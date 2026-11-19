// IL code: Interop.Aosapfs
.class private auto ansi '<Module>'
{
} // end of class <Module>

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IEnumAModelType
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 42 31 39 45 34 32 42 31 2d 37 38 38 39
		2d 31 31 44 30 2d 41 39 31 42 2d 30 30 30 30 43
		30 41 31 31 38 44 42 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void Next (
			uint32 nCount,
			class AspenTech.AspenPlus.Aosapfs.IAModelType& marshal(interface) ppModelType,
			uint32& pnumFetched
		) runtime managed internalcall 
	{
	} // end of method IEnumAModelType::Next

	.method public hidebysig newslot abstract virtual 
		instance void Skip (
			uint32 nCount
		) runtime managed internalcall 
	{
	} // end of method IEnumAModelType::Skip

	.method public hidebysig newslot abstract virtual 
		instance void Reset () runtime managed internalcall 
	{
	} // end of method IEnumAModelType::Reset

	.method public hidebysig newslot abstract virtual 
		instance void Clone (
			class AspenTech.AspenPlus.Aosapfs.IEnumAModelType& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IEnumAModelType::Clone

} // end of class AspenTech.AspenPlus.Aosapfs.IEnumAModelType

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IAModelType
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 42 31 39 45 34 32 42 32 2d 37 38 38 39
		2d 31 31 44 30 2d 41 39 31 42 2d 30 30 30 30 43
		30 41 31 31 38 44 42 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void GetName (
			uint8& pName,
			int32 nSize
		) runtime managed internalcall 
	{
	} // end of method IAModelType::GetName

	.method public hidebysig newslot abstract virtual 
		instance void SetName (
			uint8& pName
		) runtime managed internalcall 
	{
	} // end of method IAModelType::SetName

	.method public hidebysig newslot abstract virtual 
		instance void GetModelCategory (
			int32& pCategory
		) runtime managed internalcall 
	{
	} // end of method IAModelType::GetModelCategory

	.method public hidebysig newslot abstract virtual 
		instance void IsStreamType () runtime managed internalcall 
	{
	} // end of method IAModelType::IsStreamType

	.method public hidebysig newslot abstract virtual 
		instance void CreateInstance (
			class AspenTech.AspenPlus.Aosapfs.IAModel& marshal(interface) ppModel
		) runtime managed internalcall 
	{
	} // end of method IAModelType::CreateInstance

	.method public hidebysig newslot abstract virtual 
		instance void GetDescription (
			uint8& pDescription,
			int32 nSize
		) runtime managed internalcall 
	{
	} // end of method IAModelType::GetDescription

	.method public hidebysig newslot abstract virtual 
		instance void SetDescription (
			uint8& pDescription
		) runtime managed internalcall 
	{
	} // end of method IAModelType::SetDescription

	.method public hidebysig newslot abstract virtual 
		instance void GetProcessType (
			valuetype AspenTech.AspenPlus.Aosapfs.ProcessTypeRestriction& pProcType
		) runtime managed internalcall 
	{
	} // end of method IAModelType::GetProcessType

	.method public hidebysig newslot abstract virtual 
		instance void IsControllerType () runtime managed internalcall 
	{
	} // end of method IAModelType::IsControllerType

} // end of class AspenTech.AspenPlus.Aosapfs.IAModelType

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IAModel
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 42 31 39 45 34 32 42 46 2d 37 38 38 39
		2d 31 31 44 30 2d 41 39 31 42 2d 30 30 30 30 43
		30 41 31 31 38 44 42 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void GetName (
			uint8& pName,
			int32 size
		) runtime managed internalcall 
	{
	} // end of method IAModel::GetName

	.method public hidebysig newslot abstract virtual 
		instance void SetName (
			uint8& pName
		) runtime managed internalcall 
	{
	} // end of method IAModel::SetName

	.method public hidebysig newslot abstract virtual 
		instance void GetParentModel (
			class AspenTech.AspenPlus.Aosapfs.IAModel& marshal(interface) ppModel
		) runtime managed internalcall 
	{
	} // end of method IAModel::GetParentModel

	.method public hidebysig newslot abstract virtual 
		instance void SetParentModel (
			class AspenTech.AspenPlus.Aosapfs.IAModel marshal(interface) pModel
		) runtime managed internalcall 
	{
	} // end of method IAModel::SetParentModel

	.method public hidebysig newslot abstract virtual 
		instance void GetModelType (
			class AspenTech.AspenPlus.Aosapfs.IAModelType& marshal(interface) ppModelType
		) runtime managed internalcall 
	{
	} // end of method IAModel::GetModelType

	.method public hidebysig newslot abstract virtual 
		instance void GetAnnotation (
			uint8& pText,
			int32 nSize
		) runtime managed internalcall 
	{
	} // end of method IAModel::GetAnnotation

	.method public hidebysig newslot abstract virtual 
		instance void GetDescription (
			uint8& pDescription,
			int32 nSize
		) runtime managed internalcall 
	{
	} // end of method IAModel::GetDescription

	.method public hidebysig newslot abstract virtual 
		instance void CanChange (
			uint32 dwChangeCode
		) runtime managed internalcall 
	{
	} // end of method IAModel::CanChange

	.method public hidebysig newslot abstract virtual 
		instance void CustomMethod (
			int32 nMethodId,
			int32 nMethodArg,
			int32 nDataType,
			native int pData
		) runtime managed internalcall 
	{
	} // end of method IAModel::CustomMethod

} // end of class AspenTech.AspenPlus.Aosapfs.IAModel

.class public auto ansi sealed AspenTech.AspenPlus.Aosapfs.ProcessTypeRestriction
	extends [mscorlib]System.Enum
{
	// Fields
	.field public specialname rtspecialname int32 value__
	.field public static literal valuetype AspenTech.AspenPlus.Aosapfs.ProcessTypeRestriction ProcessTypeNone = int32(-1)
	.field public static literal valuetype AspenTech.AspenPlus.Aosapfs.ProcessTypeRestriction ProcessTypeAny = int32(0)
	.field public static literal valuetype AspenTech.AspenPlus.Aosapfs.ProcessTypeRestriction ProcessTypeBatch = int32(1)
	.field public static literal valuetype AspenTech.AspenPlus.Aosapfs.ProcessTypeRestriction ProcessTypeContinuous = int32(2)

} // end of class AspenTech.AspenPlus.Aosapfs.ProcessTypeRestriction

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IAEditModelIcons
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 42 31 39 45 34 32 42 33 2d 37 38 38 39
		2d 31 31 44 30 2d 41 39 31 42 2d 30 30 30 30 43
		30 41 31 31 38 44 42 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void GetCurrentIcon (
			class AspenTech.AspenPlus.Aosapfs.IAModelIcon& marshal(interface) ppModelIcon
		) runtime managed internalcall 
	{
	} // end of method IAEditModelIcons::GetCurrentIcon

	.method public hidebysig newslot abstract virtual 
		instance void SetCurrentIcon (
			class AspenTech.AspenPlus.Aosapfs.IAModelIcon marshal(interface) pModelIcon
		) runtime managed internalcall 
	{
	} // end of method IAEditModelIcons::SetCurrentIcon

	.method public hidebysig newslot abstract virtual 
		instance void CreateIcon (
			class AspenTech.AspenPlus.Aosapfs.IAModelIcon& marshal(interface) ppModelIcon,
			uint8& pName
		) runtime managed internalcall 
	{
	} // end of method IAEditModelIcons::CreateIcon

	.method public hidebysig newslot abstract virtual 
		instance void AddIcon (
			class AspenTech.AspenPlus.Aosapfs.IAModelIcon marshal(interface) pModelIcon
		) runtime managed internalcall 
	{
	} // end of method IAEditModelIcons::AddIcon

	.method public hidebysig newslot abstract virtual 
		instance void RemoveIcon (
			class AspenTech.AspenPlus.Aosapfs.IAModelIcon marshal(interface) pModelIcon
		) runtime managed internalcall 
	{
	} // end of method IAEditModelIcons::RemoveIcon

	.method public hidebysig newslot abstract virtual 
		instance void FindIcon (
			uint8& pName,
			class AspenTech.AspenPlus.Aosapfs.IAModelIcon& marshal(interface) ppModelIcon
		) runtime managed internalcall 
	{
	} // end of method IAEditModelIcons::FindIcon

	.method public hidebysig newslot abstract virtual 
		instance void EnumIcons (
			class AspenTech.AspenPlus.Aosapfs.IEnumAModelIcon& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IAEditModelIcons::EnumIcons

	.method public hidebysig newslot abstract virtual 
		instance void GetLineStyle (
			valuetype AspenTech.AspenPlus.Aosapfs.AOSALINESTYLE& pLineStyle
		) runtime managed internalcall 
	{
	} // end of method IAEditModelIcons::GetLineStyle

	.method public hidebysig newslot abstract virtual 
		instance void SetLineStyle (
			valuetype AspenTech.AspenPlus.Aosapfs.AOSALINESTYLE& pLineStyle
		) runtime managed internalcall 
	{
	} // end of method IAEditModelIcons::SetLineStyle

} // end of class AspenTech.AspenPlus.Aosapfs.IAEditModelIcons

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IAModelIcon
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 42 31 39 45 34 32 42 37 2d 37 38 38 39
		2d 31 31 44 30 2d 41 39 31 42 2d 30 30 30 30 43
		30 41 31 31 38 44 42 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void GetName (
			uint8& pName,
			int32 size
		) runtime managed internalcall 
	{
	} // end of method IAModelIcon::GetName

	.method public hidebysig newslot abstract virtual 
		instance void SetName (
			uint8& pName
		) runtime managed internalcall 
	{
	} // end of method IAModelIcon::SetName

	.method public hidebysig newslot abstract virtual 
		instance void GetModel (
			class AspenTech.AspenPlus.Aosapfs.IAModel& marshal(interface) ppModel
		) runtime managed internalcall 
	{
	} // end of method IAModelIcon::GetModel

	.method public hidebysig newslot abstract virtual 
		instance void SetModel (
			class AspenTech.AspenPlus.Aosapfs.IAModel marshal(interface) pModel
		) runtime managed internalcall 
	{
	} // end of method IAModelIcon::SetModel

	.method public hidebysig newslot abstract virtual 
		instance void GetIcon (
			class AspenTech.AspenPlus.Aosapfs.IAIcon& marshal(interface) ppIcon
		) runtime managed internalcall 
	{
	} // end of method IAModelIcon::GetIcon

	.method public hidebysig newslot abstract virtual 
		instance void SetIcon (
			class AspenTech.AspenPlus.Aosapfs.IAIcon marshal(interface) pIcon
		) runtime managed internalcall 
	{
	} // end of method IAModelIcon::SetIcon

	.method public hidebysig newslot abstract virtual 
		instance void Connect (
			class AspenTech.AspenPlus.Aosapfs.IAIconPort marshal(interface) pIconPort,
			native int location
		) runtime managed internalcall 
	{
	} // end of method IAModelIcon::Connect

	.method public hidebysig newslot abstract virtual 
		instance void Draw (
			valuetype AspenTech.AspenPlus.Aosapfs.RemotableHandle& hDC,
			valuetype AspenTech.AspenPlus.Aosapfs.RECT& pRect,
			int32 mode
		) runtime managed internalcall 
	{
		.param [1]
			.custom instance void [mscorlib]System.Runtime.InteropServices.ComAliasNameAttribute::.ctor(string) = (
				01 00 23 41 73 70 65 6e 54 65 63 68 2e 41 73 70
				65 6e 50 6c 75 73 2e 41 6f 73 61 70 66 73 2e 77
				69 72 65 48 44 43 00 00
			)
	} // end of method IAModelIcon::Draw

	.method public hidebysig newslot abstract virtual 
		instance void HasContents (
			int32& bNonEmpty
		) runtime managed internalcall 
	{
	} // end of method IAModelIcon::HasContents

	.method public hidebysig newslot abstract virtual 
		instance void GetSize (
			float64& pleft,
			float64& ptop,
			float64& pright,
			float64& pbottom
		) runtime managed internalcall 
	{
	} // end of method IAModelIcon::GetSize

	.method public hidebysig newslot abstract virtual 
		instance void GetLabelPosition (
			float64& px,
			float64& py
		) runtime managed internalcall 
	{
	} // end of method IAModelIcon::GetLabelPosition

	.method public hidebysig newslot abstract virtual 
		instance void GetClipRegion (
			valuetype AspenTech.AspenPlus.Aosapfs.RemotableHandle& hDC,
			valuetype AspenTech.AspenPlus.Aosapfs.RECT& pRect,
			native int pClipRegion,
			int32 modifier
		) runtime managed internalcall 
	{
		.param [1]
			.custom instance void [mscorlib]System.Runtime.InteropServices.ComAliasNameAttribute::.ctor(string) = (
				01 00 23 41 73 70 65 6e 54 65 63 68 2e 41 73 70
				65 6e 50 6c 75 73 2e 41 6f 73 61 70 66 73 2e 77
				69 72 65 48 44 43 00 00
			)
		.param [3]
			.custom instance void [mscorlib]System.Runtime.InteropServices.ComAliasNameAttribute::.ctor(string) = (
				01 00 24 41 73 70 65 6e 54 65 63 68 2e 41 73 70
				65 6e 50 6c 75 73 2e 41 6f 73 61 70 66 73 2e 77
				69 72 65 48 52 47 4e 00 00
			)
	} // end of method IAModelIcon::GetClipRegion

	.method public hidebysig newslot abstract virtual 
		instance void GetUniversalPorts (
			class AspenTech.AspenPlus.Aosapfs.IAIconPort& marshal(interface) ppInPort,
			class AspenTech.AspenPlus.Aosapfs.IAIconPort& marshal(interface) ppOutPort
		) runtime managed internalcall 
	{
	} // end of method IAModelIcon::GetUniversalPorts

	.method public hidebysig newslot abstract virtual 
		instance void SetPortMap (
			class AspenTech.AspenPlus.Aosapfs.IAPort marshal(interface) pPort,
			class AspenTech.AspenPlus.Aosapfs.IAIconPort marshal(interface) pIconPort
		) runtime managed internalcall 
	{
	} // end of method IAModelIcon::SetPortMap

	.method public hidebysig newslot abstract virtual 
		instance void SetPortMapByIndex (
			int32 modelIndex,
			int32 iconIndex
		) runtime managed internalcall 
	{
	} // end of method IAModelIcon::SetPortMapByIndex

	.method public hidebysig newslot abstract virtual 
		instance void RemovePortMap (
			class AspenTech.AspenPlus.Aosapfs.IAPort marshal(interface) pPort
		) runtime managed internalcall 
	{
	} // end of method IAModelIcon::RemovePortMap

	.method public hidebysig newslot abstract virtual 
		instance void GetPortFromMap (
			class AspenTech.AspenPlus.Aosapfs.IAIconPort marshal(interface) pIconPort,
			class AspenTech.AspenPlus.Aosapfs.IAPort& marshal(interface) ppModelPort
		) runtime managed internalcall 
	{
	} // end of method IAModelIcon::GetPortFromMap

	.method public hidebysig newslot abstract virtual 
		instance void GetIconPortFromMap (
			class AspenTech.AspenPlus.Aosapfs.IAPort marshal(interface) pModelPort,
			class AspenTech.AspenPlus.Aosapfs.IAIconPort& marshal(interface) ppIconPort
		) runtime managed internalcall 
	{
	} // end of method IAModelIcon::GetIconPortFromMap

	.method public hidebysig newslot abstract virtual 
		instance void SetVariable (
			class AspenTech.AspenPlus.Aosapfs.IAModel marshal(interface) pModel,
			uint8& pVarName,
			uint8& pValue
		) runtime managed internalcall 
	{
	} // end of method IAModelIcon::SetVariable

	.method public hidebysig newslot abstract virtual 
		instance void IsDerivedIcon (
			int32& bDerived
		) runtime managed internalcall 
	{
	} // end of method IAModelIcon::IsDerivedIcon

	.method public hidebysig newslot abstract virtual 
		instance void MapR9Ports () runtime managed internalcall 
	{
	} // end of method IAModelIcon::MapR9Ports

} // end of class AspenTech.AspenPlus.Aosapfs.IAModelIcon

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IEnumAModelIcon
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 42 31 39 45 34 32 42 34 2d 37 38 38 39
		2d 31 31 44 30 2d 41 39 31 42 2d 30 30 30 30 43
		30 41 31 31 38 44 42 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void Next (
			uint32 nCount,
			class AspenTech.AspenPlus.Aosapfs.IAModelIcon& marshal(interface) ppModelIcon,
			uint32& pnumFetched
		) runtime managed internalcall 
	{
	} // end of method IEnumAModelIcon::Next

	.method public hidebysig newslot abstract virtual 
		instance void Skip (
			uint32 nCount
		) runtime managed internalcall 
	{
	} // end of method IEnumAModelIcon::Skip

	.method public hidebysig newslot abstract virtual 
		instance void Reset () runtime managed internalcall 
	{
	} // end of method IEnumAModelIcon::Reset

	.method public hidebysig newslot abstract virtual 
		instance void Clone (
			class AspenTech.AspenPlus.Aosapfs.IEnumAModelIcon& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IEnumAModelIcon::Clone

} // end of class AspenTech.AspenPlus.Aosapfs.IEnumAModelIcon

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.AOSALINESTYLE
	extends [mscorlib]System.ValueType
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.pack 8
	.size 0

	// Fields
	.field public uint32 dwPenStyle
	.field public uint32 dwWidth
	.field public valuetype AspenTech.AspenPlus.Aosapfs.LOGBRUSH LOGBRUSH
	.field public uint32 dwStyleCount
	.field public native int lpStyle
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.field public valuetype AspenTech.AspenPlus.Aosapfs.AOSA_ARROWTYPE nArrowType
	.field public int32 bHideLabels
	.field public marshal(fixed array[10]) uint8[] szTerminatorID

} // end of class AspenTech.AspenPlus.Aosapfs.AOSALINESTYLE

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IAIcon
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 42 31 39 45 34 32 42 39 2d 37 38 38 39
		2d 31 31 44 30 2d 41 39 31 42 2d 30 30 30 30 43
		30 41 31 31 38 44 42 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void GetName (
			uint8& pName,
			int32 size
		) runtime managed internalcall 
	{
	} // end of method IAIcon::GetName

	.method public hidebysig newslot abstract virtual 
		instance void SetName (
			uint8& pName
		) runtime managed internalcall 
	{
	} // end of method IAIcon::SetName

	.method public hidebysig newslot abstract virtual 
		instance void SetupIcon (
			uint8& pName
		) runtime managed internalcall 
	{
	} // end of method IAIcon::SetupIcon

	.method public hidebysig newslot abstract virtual 
		instance void MapPorts (
			class AspenTech.AspenPlus.Aosapfs.IAModelIcon marshal(interface) pModelIcon
		) runtime managed internalcall 
	{
	} // end of method IAIcon::MapPorts

	.method public hidebysig newslot abstract virtual 
		instance void GetSize (
			float64& pleft,
			float64& ptop,
			float64& pright,
			float64& pbottom
		) runtime managed internalcall 
	{
	} // end of method IAIcon::GetSize

	.method public hidebysig newslot abstract virtual 
		instance void GetLabelPosition (
			float64& px,
			float64& py
		) runtime managed internalcall 
	{
	} // end of method IAIcon::GetLabelPosition

	.method public hidebysig newslot abstract virtual 
		instance void GetClipRegion (
			valuetype AspenTech.AspenPlus.Aosapfs.RemotableHandle& hDC,
			valuetype AspenTech.AspenPlus.Aosapfs.RECT& pRect,
			native int pClipRegion,
			int32 modifier
		) runtime managed internalcall 
	{
		.param [1]
			.custom instance void [mscorlib]System.Runtime.InteropServices.ComAliasNameAttribute::.ctor(string) = (
				01 00 23 41 73 70 65 6e 54 65 63 68 2e 41 73 70
				65 6e 50 6c 75 73 2e 41 6f 73 61 70 66 73 2e 77
				69 72 65 48 44 43 00 00
			)
		.param [3]
			.custom instance void [mscorlib]System.Runtime.InteropServices.ComAliasNameAttribute::.ctor(string) = (
				01 00 24 41 73 70 65 6e 54 65 63 68 2e 41 73 70
				65 6e 50 6c 75 73 2e 41 6f 73 61 70 66 73 2e 77
				69 72 65 48 52 47 4e 00 00
			)
	} // end of method IAIcon::GetClipRegion

	.method public hidebysig newslot abstract virtual 
		instance void AttachPort (
			class AspenTech.AspenPlus.Aosapfs.IAIconPort marshal(interface) pPort
		) runtime managed internalcall 
	{
	} // end of method IAIcon::AttachPort

	.method public hidebysig newslot abstract virtual 
		instance void GetUniversalPorts (
			class AspenTech.AspenPlus.Aosapfs.IAIconPort& marshal(interface) pInPort,
			class AspenTech.AspenPlus.Aosapfs.IAIconPort& marshal(interface) pOutPort
		) runtime managed internalcall 
	{
	} // end of method IAIcon::GetUniversalPorts

	.method public hidebysig newslot abstract virtual 
		instance void Draw (
			valuetype AspenTech.AspenPlus.Aosapfs.RemotableHandle& hDC,
			valuetype AspenTech.AspenPlus.Aosapfs.RECT& pRect,
			int32 mode
		) runtime managed internalcall 
	{
		.param [1]
			.custom instance void [mscorlib]System.Runtime.InteropServices.ComAliasNameAttribute::.ctor(string) = (
				01 00 23 41 73 70 65 6e 54 65 63 68 2e 41 73 70
				65 6e 50 6c 75 73 2e 41 6f 73 61 70 66 73 2e 77
				69 72 65 48 44 43 00 00
			)
	} // end of method IAIcon::Draw

	.method public hidebysig newslot abstract virtual 
		instance void Connect (
			class AspenTech.AspenPlus.Aosapfs.IAIconPort marshal(interface) pIconPort,
			native int location,
			class AspenTech.AspenPlus.Aosapfs.IAModelIcon marshal(interface) pModelIcon
		) runtime managed internalcall 
	{
	} // end of method IAIcon::Connect

	.method public hidebysig newslot abstract virtual 
		instance void HasContents (
			int32& bNonEmpty
		) runtime managed internalcall 
	{
	} // end of method IAIcon::HasContents

	.method public hidebysig newslot abstract virtual 
		instance void SetVariable (
			class AspenTech.AspenPlus.Aosapfs.IAModel marshal(interface) pModel,
			uint8& pVarName,
			uint8& pValue,
			class AspenTech.AspenPlus.Aosapfs.IAModelIcon marshal(interface) pModelIcon
		) runtime managed internalcall 
	{
	} // end of method IAIcon::SetVariable

	.method public hidebysig newslot abstract virtual 
		instance void IsDerivedIcon (
			int32& bDerived
		) runtime managed internalcall 
	{
	} // end of method IAIcon::IsDerivedIcon

	.method public hidebysig newslot abstract virtual 
		instance void AddIconPort (
			uint8& name,
			class AspenTech.AspenPlus.Aosapfs.IAIconPort& marshal(interface) ppPort
		) runtime managed internalcall 
	{
	} // end of method IAIcon::AddIconPort

	.method public hidebysig newslot abstract virtual 
		instance void RemoveIconPort (
			class AspenTech.AspenPlus.Aosapfs.IAIconPort marshal(interface) pPort
		) runtime managed internalcall 
	{
	} // end of method IAIcon::RemoveIconPort

	.method public hidebysig newslot abstract virtual 
		instance void FindIconPort (
			uint8& name,
			class AspenTech.AspenPlus.Aosapfs.IAIconPort& marshal(interface) ppPort
		) runtime managed internalcall 
	{
	} // end of method IAIcon::FindIconPort

	.method public hidebysig newslot abstract virtual 
		instance void EnumIconPorts (
			class AspenTech.AspenPlus.Aosapfs.IEnumAIconPort& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IAIcon::EnumIconPorts

} // end of class AspenTech.AspenPlus.Aosapfs.IAIcon

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IAIconPort
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 42 31 39 45 34 32 42 43 2d 37 38 38 39
		2d 31 31 44 30 2d 41 39 31 42 2d 30 30 30 30 43
		30 41 31 31 38 44 42 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void GetName (
			uint8& pName,
			int32 nSize
		) runtime managed internalcall 
	{
	} // end of method IAIconPort::GetName

	.method public hidebysig newslot abstract virtual 
		instance void SetPos (
			uint8& x,
			uint8& y
		) runtime managed internalcall 
	{
	} // end of method IAIconPort::SetPos

	.method public hidebysig newslot abstract virtual 
		instance void SetAttrib (
			int32 Attrib
		) runtime managed internalcall 
	{
	} // end of method IAIconPort::SetAttrib

	.method public hidebysig newslot abstract virtual 
		instance void GetAttrib (
			int32& pAttrib
		) runtime managed internalcall 
	{
	} // end of method IAIconPort::GetAttrib

	.method public hidebysig newslot abstract virtual 
		instance void SetLocation (
			float64 x,
			float64 y
		) runtime managed internalcall 
	{
	} // end of method IAIconPort::SetLocation

	.method public hidebysig newslot abstract virtual 
		instance void GetLocation (
			float64& px,
			float64& py
		) runtime managed internalcall 
	{
	} // end of method IAIconPort::GetLocation

	.method public hidebysig newslot abstract virtual 
		instance void GetDirection (
			valuetype AspenTech.AspenPlus.Aosapfs.POINT& pdirection,
			int32 modifier
		) runtime managed internalcall 
	{
	} // end of method IAIconPort::GetDirection

	.method public hidebysig newslot abstract virtual 
		instance void GetSensitiveRegion (
			valuetype AspenTech.AspenPlus.Aosapfs.POINT& pPoint,
			valuetype AspenTech.AspenPlus.Aosapfs.RECT& pregion,
			int32 modifier
		) runtime managed internalcall 
	{
	} // end of method IAIconPort::GetSensitiveRegion

	.method public hidebysig newslot abstract virtual 
		instance void Draw (
			valuetype AspenTech.AspenPlus.Aosapfs.RemotableHandle& hDC,
			valuetype AspenTech.AspenPlus.Aosapfs.POINT& pPoint,
			int32 mode
		) runtime managed internalcall 
	{
		.param [1]
			.custom instance void [mscorlib]System.Runtime.InteropServices.ComAliasNameAttribute::.ctor(string) = (
				01 00 23 41 73 70 65 6e 54 65 63 68 2e 41 73 70
				65 6e 50 6c 75 73 2e 41 6f 73 61 70 66 73 2e 77
				69 72 65 48 44 43 00 00
			)
	} // end of method IAIconPort::Draw

	.method public hidebysig newslot abstract virtual 
		instance void Highlight (
			valuetype AspenTech.AspenPlus.Aosapfs.RemotableHandle& hWnd,
			valuetype AspenTech.AspenPlus.Aosapfs.RemotableHandle& hDC,
			valuetype AspenTech.AspenPlus.Aosapfs.POINT& pPoint,
			int32 mode
		) runtime managed internalcall 
	{
		.param [1]
			.custom instance void [mscorlib]System.Runtime.InteropServices.ComAliasNameAttribute::.ctor(string) = (
				01 00 24 41 73 70 65 6e 54 65 63 68 2e 41 73 70
				65 6e 50 6c 75 73 2e 41 6f 73 61 70 66 73 2e 77
				69 72 65 48 57 4e 44 00 00
			)
		.param [2]
			.custom instance void [mscorlib]System.Runtime.InteropServices.ComAliasNameAttribute::.ctor(string) = (
				01 00 23 41 73 70 65 6e 54 65 63 68 2e 41 73 70
				65 6e 50 6c 75 73 2e 41 6f 73 61 70 66 73 2e 77
				69 72 65 48 44 43 00 00
			)
	} // end of method IAIconPort::Highlight

	.method public hidebysig newslot abstract virtual 
		instance void CompareInstance (
			object marshal(iunknown) pUnk
		) runtime managed internalcall 
	{
	} // end of method IAIconPort::CompareInstance

	.method public hidebysig newslot abstract virtual 
		instance void SetName (
			uint8& pName
		) runtime managed internalcall 
	{
	} // end of method IAIconPort::SetName

} // end of class AspenTech.AspenPlus.Aosapfs.IAIconPort

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.RemotableHandle
	extends [mscorlib]System.ValueType
{
	.pack 4
	.size 0

	// Fields
	.field public int32 fContext
	.field public valuetype AspenTech.AspenPlus.Aosapfs.__MIDL_IWinTypes_0009 u

} // end of class AspenTech.AspenPlus.Aosapfs.RemotableHandle

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.RECT
	extends [mscorlib]System.ValueType
{
	.pack 4
	.size 0

	// Fields
	.field public int32 left
	.field public int32 top
	.field public int32 right
	.field public int32 bottom

} // end of class AspenTech.AspenPlus.Aosapfs.RECT

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IAPort
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 42 31 39 45 34 32 42 38 2d 37 38 38 39
		2d 31 31 44 30 2d 41 39 31 42 2d 30 30 30 30 43
		30 41 31 31 38 44 42 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void GetModel (
			class AspenTech.AspenPlus.Aosapfs.IAModel& marshal(interface) ppModel
		) runtime managed internalcall 
	{
	} // end of method IAPort::GetModel

	.method public hidebysig newslot abstract virtual 
		instance void SetModel (
			class AspenTech.AspenPlus.Aosapfs.IAModel marshal(interface) pModel
		) runtime managed internalcall 
	{
	} // end of method IAPort::SetModel

	.method public hidebysig newslot abstract virtual 
		instance void GetName (
			uint8& pName,
			int32 nSize
		) runtime managed internalcall 
	{
	} // end of method IAPort::GetName

	.method public hidebysig newslot abstract virtual 
		instance void SetName (
			uint8& pName
		) runtime managed internalcall 
	{
	} // end of method IAPort::SetName

	.method public hidebysig newslot abstract virtual 
		instance void GetSexAndDirection (
			int32& pFlags
		) runtime managed internalcall 
	{
	} // end of method IAPort::GetSexAndDirection

	.method public hidebysig newslot abstract virtual 
		instance void CanConnect (
			class AspenTech.AspenPlus.Aosapfs.IAPort marshal(interface) pPort
		) runtime managed internalcall 
	{
	} // end of method IAPort::CanConnect

	.method public hidebysig newslot abstract virtual 
		instance void Connect (
			class AspenTech.AspenPlus.Aosapfs.IAPort marshal(interface) pPort,
			int32& pInstance
		) runtime managed internalcall 
	{
	} // end of method IAPort::Connect

	.method public hidebysig newslot abstract virtual 
		instance void Disconnect (
			int32 Instance
		) runtime managed internalcall 
	{
	} // end of method IAPort::Disconnect

	.method public hidebysig newslot abstract virtual 
		instance void IsSame (
			class AspenTech.AspenPlus.Aosapfs.IAPort marshal(interface) pPort
		) runtime managed internalcall 
	{
	} // end of method IAPort::IsSame

	.method public hidebysig newslot abstract virtual 
		instance void IsRequired () runtime managed internalcall 
	{
	} // end of method IAPort::IsRequired

	.method public hidebysig newslot abstract virtual 
		instance void GetDescription (
			uint8& pDescription,
			int32 nSize
		) runtime managed internalcall 
	{
	} // end of method IAPort::GetDescription

	.method public hidebysig newslot abstract virtual 
		instance void IsCharge () runtime managed internalcall 
	{
	} // end of method IAPort::IsCharge

} // end of class AspenTech.AspenPlus.Aosapfs.IAPort

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IEnumAIconPort
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 42 31 39 45 34 32 42 42 2d 37 38 38 39
		2d 31 31 44 30 2d 41 39 31 42 2d 30 30 30 30 43
		30 41 31 31 38 44 42 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void Next (
			uint32 nCount,
			class AspenTech.AspenPlus.Aosapfs.IAIconPort& marshal(interface) ppIconPort,
			uint32& pnumFetched
		) runtime managed internalcall 
	{
	} // end of method IEnumAIconPort::Next

	.method public hidebysig newslot abstract virtual 
		instance void Skip (
			uint32 nCount
		) runtime managed internalcall 
	{
	} // end of method IEnumAIconPort::Skip

	.method public hidebysig newslot abstract virtual 
		instance void Reset () runtime managed internalcall 
	{
	} // end of method IEnumAIconPort::Reset

	.method public hidebysig newslot abstract virtual 
		instance void Clone (
			class AspenTech.AspenPlus.Aosapfs.IEnumAIconPort& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IEnumAIconPort::Clone

} // end of class AspenTech.AspenPlus.Aosapfs.IEnumAIconPort

.class public explicit ansi sealed AspenTech.AspenPlus.Aosapfs.__MIDL_IWinTypes_0009
	extends [mscorlib]System.ValueType
{
	.pack 4
	.size 4

	// Fields
	.field [0] public int32 hInproc
	.field [0] public int32 hRemote

} // end of class AspenTech.AspenPlus.Aosapfs.__MIDL_IWinTypes_0009

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.POINT
	extends [mscorlib]System.ValueType
{
	.pack 4
	.size 0

	// Fields
	.field public int32 x
	.field public int32 y

} // end of class AspenTech.AspenPlus.Aosapfs.POINT

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.LOGBRUSH
	extends [mscorlib]System.ValueType
{
	.pack 4
	.size 0

	// Fields
	.field public uint32 lbStyle
	.field public uint32 lbColor
	.field public int32 lbHatch

} // end of class AspenTech.AspenPlus.Aosapfs.LOGBRUSH

.class public auto ansi sealed AspenTech.AspenPlus.Aosapfs.AOSA_ARROWTYPE
	extends [mscorlib]System.Enum
{
	// Fields
	.field public specialname rtspecialname int32 value__
	.field public static literal valuetype AspenTech.AspenPlus.Aosapfs.AOSA_ARROWTYPE AOSA_ARROW_NONE = int32(1)
	.field public static literal valuetype AspenTech.AspenPlus.Aosapfs.AOSA_ARROWTYPE AOSA_ARROW_SOLID = int32(2)

} // end of class AspenTech.AspenPlus.Aosapfs.AOSA_ARROWTYPE

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IAEditPorts
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 42 31 39 45 34 32 42 35 2d 37 38 38 39
		2d 31 31 44 30 2d 41 39 31 42 2d 30 30 30 30 43
		30 41 31 31 38 44 42 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void AddPort (
			class AspenTech.AspenPlus.Aosapfs.IAPort& marshal(interface) ppPort,
			uint8& name,
			class AspenTech.AspenPlus.Aosapfs.IAPortType marshal(interface) pPortType
		) runtime managed internalcall 
	{
	} // end of method IAEditPorts::AddPort

	.method public hidebysig newslot abstract virtual 
		instance void InsertPort (
			class AspenTech.AspenPlus.Aosapfs.IAPort marshal(interface) pPort
		) runtime managed internalcall 
	{
	} // end of method IAEditPorts::InsertPort

	.method public hidebysig newslot abstract virtual 
		instance void RemovePort (
			class AspenTech.AspenPlus.Aosapfs.IAPort marshal(interface) pPort
		) runtime managed internalcall 
	{
	} // end of method IAEditPorts::RemovePort

	.method public hidebysig newslot abstract virtual 
		instance void FindPort (
			uint8& name,
			class AspenTech.AspenPlus.Aosapfs.IAPort& marshal(interface) ppPort
		) runtime managed internalcall 
	{
	} // end of method IAEditPorts::FindPort

	.method public hidebysig newslot abstract virtual 
		instance void EnumPorts (
			int32 sexdir,
			class AspenTech.AspenPlus.Aosapfs.IEnumAPort& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IAEditPorts::EnumPorts

} // end of class AspenTech.AspenPlus.Aosapfs.IAEditPorts

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IAPortType
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 30 45 46 42 37 33 34 30 2d 35 38 34 37
		2d 31 31 44 30 2d 41 39 31 34 2d 30 30 30 30 43
		30 41 31 31 38 44 42 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
} // end of class AspenTech.AspenPlus.Aosapfs.IAPortType

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IEnumAPort
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 42 31 39 45 34 32 42 36 2d 37 38 38 39
		2d 31 31 44 30 2d 41 39 31 42 2d 30 30 30 30 43
		30 41 31 31 38 44 42 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void Next (
			uint32 nCount,
			class AspenTech.AspenPlus.Aosapfs.IAPort& marshal(interface) ppPort,
			uint32& pnumFetched
		) runtime managed internalcall 
	{
	} // end of method IEnumAPort::Next

	.method public hidebysig newslot abstract virtual 
		instance void Skip (
			uint32 nCount
		) runtime managed internalcall 
	{
	} // end of method IEnumAPort::Skip

	.method public hidebysig newslot abstract virtual 
		instance void Reset () runtime managed internalcall 
	{
	} // end of method IEnumAPort::Reset

	.method public hidebysig newslot abstract virtual 
		instance void Clone (
			class AspenTech.AspenPlus.Aosapfs.IEnumAPort& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IEnumAPort::Clone

} // end of class AspenTech.AspenPlus.Aosapfs.IEnumAPort

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IAIcon2
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 35 33 43 34 34 37 33 30 2d 45 35 31 34
		2d 31 31 44 31 2d 41 34 44 45 2d 30 30 31 30 34
		42 32 31 34 32 34 32 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void GetRangeCount (
			int32& count
		) runtime managed internalcall 
	{
	} // end of method IAIcon2::GetRangeCount

	.method public hidebysig newslot abstract virtual 
		instance void GetRange (
			int32 index,
			float64& pleft,
			float64& ptop,
			float64& pright,
			float64& pbottom
		) runtime managed internalcall 
	{
	} // end of method IAIcon2::GetRange

	.method public hidebysig newslot abstract virtual 
		instance void DXFOut (
			class AspenTech.AspenPlus.Aosapfs.IStream marshal(interface) pStream
		) runtime managed internalcall 
	{
	} // end of method IAIcon2::DXFOut

	.method public hidebysig newslot abstract virtual 
		instance void SetModified (
			int32 bModified
		) runtime managed internalcall 
	{
	} // end of method IAIcon2::SetModified

} // end of class AspenTech.AspenPlus.Aosapfs.IAIcon2

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.ISequentialStream
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 30 43 37 33 33 41 33 30 2d 32 41 31 43
		2d 31 31 43 45 2d 41 44 45 35 2d 30 30 41 41 30
		30 34 34 37 37 33 44 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void RemoteRead (
			[out] uint8& pv,
			[in] uint32 cb,
			[out] uint32& pcbRead
		) runtime managed internalcall 
	{
	} // end of method ISequentialStream::RemoteRead

	.method public hidebysig newslot abstract virtual 
		instance void RemoteWrite (
			[in] uint8& pv,
			[in] uint32 cb,
			[out] uint32& pcbWritten
		) runtime managed internalcall 
	{
	} // end of method ISequentialStream::RemoteWrite

} // end of class AspenTech.AspenPlus.Aosapfs.ISequentialStream

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IStream
	implements AspenTech.AspenPlus.Aosapfs.ISequentialStream
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 30 30 30 30 30 30 30 43 2d 30 30 30 30
		2d 30 30 30 30 2d 43 30 30 30 2d 30 30 30 30 30
		30 30 30 30 30 34 36 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void RemoteRead (
			[out] uint8& pv,
			[in] uint32 cb,
			[out] uint32& pcbRead
		) runtime managed internalcall 
	{
	} // end of method IStream::RemoteRead

	.method public hidebysig newslot abstract virtual 
		instance void RemoteWrite (
			[in] uint8& pv,
			[in] uint32 cb,
			[out] uint32& pcbWritten
		) runtime managed internalcall 
	{
	} // end of method IStream::RemoteWrite

	.method public hidebysig newslot abstract virtual 
		instance void RemoteSeek (
			[in] valuetype AspenTech.AspenPlus.Aosapfs.LARGE_INTEGER dlibMove,
			[in] uint32 dwOrigin,
			[out] valuetype AspenTech.AspenPlus.Aosapfs.ULARGE_INTEGER& plibNewPosition
		) runtime managed internalcall 
	{
	} // end of method IStream::RemoteSeek

	.method public hidebysig newslot abstract virtual 
		instance void SetSize (
			[in] valuetype AspenTech.AspenPlus.Aosapfs.ULARGE_INTEGER libNewSize
		) runtime managed internalcall 
	{
	} // end of method IStream::SetSize

	.method public hidebysig newslot abstract virtual 
		instance void RemoteCopyTo (
			[in] class AspenTech.AspenPlus.Aosapfs.IStream marshal(interface) pstm,
			[in] valuetype AspenTech.AspenPlus.Aosapfs.ULARGE_INTEGER cb,
			[out] valuetype AspenTech.AspenPlus.Aosapfs.ULARGE_INTEGER& pcbRead,
			[out] valuetype AspenTech.AspenPlus.Aosapfs.ULARGE_INTEGER& pcbWritten
		) runtime managed internalcall 
	{
	} // end of method IStream::RemoteCopyTo

	.method public hidebysig newslot abstract virtual 
		instance void Commit (
			[in] uint32 grfCommitFlags
		) runtime managed internalcall 
	{
	} // end of method IStream::Commit

	.method public hidebysig newslot abstract virtual 
		instance void Revert () runtime managed internalcall 
	{
	} // end of method IStream::Revert

	.method public hidebysig newslot abstract virtual 
		instance void LockRegion (
			[in] valuetype AspenTech.AspenPlus.Aosapfs.ULARGE_INTEGER libOffset,
			[in] valuetype AspenTech.AspenPlus.Aosapfs.ULARGE_INTEGER cb,
			[in] uint32 dwLockType
		) runtime managed internalcall 
	{
	} // end of method IStream::LockRegion

	.method public hidebysig newslot abstract virtual 
		instance void UnlockRegion (
			[in] valuetype AspenTech.AspenPlus.Aosapfs.ULARGE_INTEGER libOffset,
			[in] valuetype AspenTech.AspenPlus.Aosapfs.ULARGE_INTEGER cb,
			[in] uint32 dwLockType
		) runtime managed internalcall 
	{
	} // end of method IStream::UnlockRegion

	.method public hidebysig newslot abstract virtual 
		instance void Stat (
			[out] valuetype AspenTech.AspenPlus.Aosapfs.STATSTG& pstatstg,
			[in] uint32 grfStatFlag
		) runtime managed internalcall 
	{
	} // end of method IStream::Stat

	.method public hidebysig newslot abstract virtual 
		instance void Clone (
			[out] class AspenTech.AspenPlus.Aosapfs.IStream& marshal(interface) ppstm
		) runtime managed internalcall 
	{
	} // end of method IStream::Clone

} // end of class AspenTech.AspenPlus.Aosapfs.IStream

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.LARGE_INTEGER
	extends [mscorlib]System.ValueType
{
	.pack 8
	.size 0

	// Fields
	.field public int64 QuadPart

} // end of class AspenTech.AspenPlus.Aosapfs.LARGE_INTEGER

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.ULARGE_INTEGER
	extends [mscorlib]System.ValueType
{
	.pack 8
	.size 0

	// Fields
	.field public uint64 QuadPart

} // end of class AspenTech.AspenPlus.Aosapfs.ULARGE_INTEGER

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.STATSTG
	extends [mscorlib]System.ValueType
{
	.pack 8
	.size 0

	// Fields
	.field public marshal(lpwstr) string pwcsName
	.field public uint32 'type'
	.field public valuetype AspenTech.AspenPlus.Aosapfs.ULARGE_INTEGER cbSize
	.field public valuetype AspenTech.AspenPlus.Aosapfs.FILETIME mtime
	.field public valuetype AspenTech.AspenPlus.Aosapfs.FILETIME ctime
	.field public valuetype AspenTech.AspenPlus.Aosapfs.FILETIME atime
	.field public uint32 grfMode
	.field public uint32 grfLocksSupported
	.field public valuetype [mscorlib]System.Guid 'clsid'
	.field public uint32 grfStateBits
	.field public uint32 reserved

} // end of class AspenTech.AspenPlus.Aosapfs.STATSTG

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.FILETIME
	extends [mscorlib]System.ValueType
{
	.pack 4
	.size 0

	// Fields
	.field public uint32 dwLowDateTime
	.field public uint32 dwHighDateTime

} // end of class AspenTech.AspenPlus.Aosapfs.FILETIME

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IASblIcon
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 42 31 39 45 34 32 42 41 2d 37 38 38 39
		2d 31 31 44 30 2d 41 39 31 42 2d 30 30 30 30 43
		30 41 31 31 38 44 42 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void GetScriptSize (
			int32& pSize
		) runtime managed internalcall 
	{
	} // end of method IASblIcon::GetScriptSize

	.method public hidebysig newslot abstract virtual 
		instance void GetScript (
			uint8& pScript,
			int32 size
		) runtime managed internalcall 
	{
	} // end of method IASblIcon::GetScript

	.method public hidebysig newslot abstract virtual 
		instance void SetScript (
			uint8& pScript
		) runtime managed internalcall 
	{
	} // end of method IASblIcon::SetScript

} // end of class AspenTech.AspenPlus.Aosapfs.IASblIcon

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IAIconLibrary
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 42 31 39 45 34 32 42 44 2d 37 38 38 39
		2d 31 31 44 30 2d 41 39 31 42 2d 30 30 30 30 43
		30 41 31 31 38 44 42 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void LoadR9Icon (
			uint8& pFileName
		) runtime managed internalcall 
	{
	} // end of method IAIconLibrary::LoadR9Icon

	.method public hidebysig newslot abstract virtual 
		instance void Edit () runtime managed internalcall 
	{
	} // end of method IAIconLibrary::Edit

	.method public hidebysig newslot abstract virtual 
		instance void FindIcon (
			uint8& pName,
			class AspenTech.AspenPlus.Aosapfs.IAIcon& marshal(interface) ppIcon
		) runtime managed internalcall 
	{
	} // end of method IAIconLibrary::FindIcon

	.method public hidebysig newslot abstract virtual 
		instance void EnumIcons (
			class AspenTech.AspenPlus.Aosapfs.IEnumAIcon& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IAIconLibrary::EnumIcons

	.method public hidebysig newslot abstract virtual 
		instance void GetComment (
			uint8& pName,
			uint8& pComment,
			int32 size
		) runtime managed internalcall 
	{
	} // end of method IAIconLibrary::GetComment

} // end of class AspenTech.AspenPlus.Aosapfs.IAIconLibrary

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IEnumAIcon
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 42 31 39 45 34 32 42 45 2d 37 38 38 39
		2d 31 31 44 30 2d 41 39 31 42 2d 30 30 30 30 43
		30 41 31 31 38 44 42 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void Next (
			uint32 nCount,
			class AspenTech.AspenPlus.Aosapfs.IAIcon& marshal(interface) ppIcon,
			uint32& pnumFetched
		) runtime managed internalcall 
	{
	} // end of method IEnumAIcon::Next

	.method public hidebysig newslot abstract virtual 
		instance void Skip (
			uint32 nCount
		) runtime managed internalcall 
	{
	} // end of method IEnumAIcon::Skip

	.method public hidebysig newslot abstract virtual 
		instance void Reset () runtime managed internalcall 
	{
	} // end of method IEnumAIcon::Reset

	.method public hidebysig newslot abstract virtual 
		instance void Clone (
			class AspenTech.AspenPlus.Aosapfs.IEnumAIcon& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IEnumAIcon::Clone

} // end of class AspenTech.AspenPlus.Aosapfs.IEnumAIcon

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IAModel2
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 41 41 44 45 32 38 38 30 2d 30 35 41 43
		2d 31 31 44 34 2d 38 45 34 46 2d 30 30 43 30 34
		46 32 39 38 37 35 36 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void GetDisplayName (
			uint8& pName,
			int32 size
		) runtime managed internalcall 
	{
	} // end of method IAModel2::GetDisplayName

	.method public hidebysig newslot abstract virtual 
		instance void SetDisplayName (
			uint8& pName
		) runtime managed internalcall 
	{
	} // end of method IAModel2::SetDisplayName

	.method public hidebysig newslot abstract virtual 
		instance void IsVisible () runtime managed internalcall 
	{
	} // end of method IAModel2::IsVisible

	.method public hidebysig newslot abstract virtual 
		instance void EnumMultiSelectVerbs (
			int32 'flags',
			class AspenTech.AspenPlus.Aosapfs.IEnumOLEVERB& marshal(interface) ppEnumOleVerb
		) runtime managed internalcall 
	{
	} // end of method IAModel2::EnumMultiSelectVerbs

	.method public hidebysig newslot abstract virtual 
		instance void DoMultiSelectVerb (
			int32 iVerb,
			valuetype AspenTech.AspenPlus.Aosapfs.MSG& lpmsg
		) runtime managed internalcall 
	{
	} // end of method IAModel2::DoMultiSelectVerb

	.method public hidebysig newslot abstract virtual 
		instance void QuerySetData (
			valuetype AspenTech.AspenPlus.Aosapfs.FORMATETC& pformatetc
		) runtime managed internalcall 
	{
	} // end of method IAModel2::QuerySetData

	.method public hidebysig newslot abstract virtual 
		instance void SetData (
			valuetype AspenTech.AspenPlus.Aosapfs.FORMATETC& pformatetc,
			native int pmedium,
			int32 fRelease
		) runtime managed internalcall 
	{
		.param [2]
			.custom instance void [mscorlib]System.Runtime.InteropServices.ComAliasNameAttribute::.ctor(string) = (
				01 00 29 41 73 70 65 6e 54 65 63 68 2e 41 73 70
				65 6e 50 6c 75 73 2e 41 6f 73 61 70 66 73 2e 77
				69 72 65 53 54 47 4d 45 44 49 55 4d 00 00
			)
	} // end of method IAModel2::SetData

	.method public hidebysig newslot abstract virtual 
		instance void TransferDataObject (
			class AspenTech.AspenPlus.Aosapfs.IDataObject marshal(interface) pDataObject
		) runtime managed internalcall 
	{
	} // end of method IAModel2::TransferDataObject

	.method public hidebysig newslot abstract virtual 
		instance void ImportModelType (
			class AspenTech.AspenPlus.Aosapfs.IAModelType marshal(interface) pModelType
		) runtime managed internalcall 
	{
	} // end of method IAModel2::ImportModelType

} // end of class AspenTech.AspenPlus.Aosapfs.IAModel2

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IEnumOLEVERB
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 30 30 30 30 30 31 30 34 2d 30 30 30 30
		2d 30 30 30 30 2d 43 30 30 30 2d 30 30 30 30 30
		30 30 30 30 30 34 36 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void RemoteNext (
			[in] uint32 celt,
			[out] valuetype AspenTech.AspenPlus.Aosapfs.OLEVERB& rgelt,
			[out] uint32& pceltFetched
		) runtime managed internalcall 
	{
	} // end of method IEnumOLEVERB::RemoteNext

	.method public hidebysig newslot abstract virtual 
		instance void Skip (
			[in] uint32 celt
		) runtime managed internalcall 
	{
	} // end of method IEnumOLEVERB::Skip

	.method public hidebysig newslot abstract virtual 
		instance void Reset () runtime managed internalcall 
	{
	} // end of method IEnumOLEVERB::Reset

	.method public hidebysig newslot abstract virtual 
		instance void Clone (
			[out] class AspenTech.AspenPlus.Aosapfs.IEnumOLEVERB& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IEnumOLEVERB::Clone

} // end of class AspenTech.AspenPlus.Aosapfs.IEnumOLEVERB

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.MSG
	extends [mscorlib]System.ValueType
{
	.pack 8
	.size 0

	// Fields
	.field public native int hWnd
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComAliasNameAttribute::.ctor(string) = (
		01 00 24 41 73 70 65 6e 54 65 63 68 2e 41 73 70
		65 6e 50 6c 75 73 2e 41 6f 73 61 70 66 73 2e 77
		69 72 65 48 57 4e 44 00 00
	)
	.field public uint32 message
	.field public uint64 wParam
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComAliasNameAttribute::.ctor(string) = (
		01 00 24 41 73 70 65 6e 54 65 63 68 2e 41 73 70
		65 6e 50 6c 75 73 2e 41 6f 73 61 70 66 73 2e 55
		49 4e 54 5f 50 54 52 00 00
	)
	.field public int64 lParam
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComAliasNameAttribute::.ctor(string) = (
		01 00 24 41 73 70 65 6e 54 65 63 68 2e 41 73 70
		65 6e 50 6c 75 73 2e 41 6f 73 61 70 66 73 2e 4c
		4f 4e 47 5f 50 54 52 00 00
	)
	.field public uint32 time
	.field public valuetype AspenTech.AspenPlus.Aosapfs.POINT pt

} // end of class AspenTech.AspenPlus.Aosapfs.MSG

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.FORMATETC
	extends [mscorlib]System.ValueType
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.pack 8
	.size 0

	// Fields
	.field public native int cfFormat
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComAliasNameAttribute::.ctor(string) = (
		01 00 2a 41 73 70 65 6e 54 65 63 68 2e 41 73 70
		65 6e 50 6c 75 73 2e 41 6f 73 61 70 66 73 2e 77
		69 72 65 43 4c 49 50 46 4f 52 4d 41 54 00 00
	)
	.field public native int ptd
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.field public uint32 dwAspect
	.field public int32 lindex
	.field public uint32 tymed

} // end of class AspenTech.AspenPlus.Aosapfs.FORMATETC

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.userSTGMEDIUM
	extends [mscorlib]System.ValueType
{
	.pack 8
	.size 0

	// Fields
	.field public valuetype AspenTech.AspenPlus.Aosapfs._STGMEDIUM_UNION DUMMYUNIONNAME
	.field public marshal(iunknown) object pUnkForRelease

} // end of class AspenTech.AspenPlus.Aosapfs.userSTGMEDIUM

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IDataObject
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 30 30 30 30 30 31 30 45 2d 30 30 30 30
		2d 30 30 30 30 2d 43 30 30 30 2d 30 30 30 30 30
		30 30 30 30 30 34 36 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void RemoteGetData (
			[in] valuetype AspenTech.AspenPlus.Aosapfs.FORMATETC& pformatetcIn,
			[out] native int pRemoteMedium
		) runtime managed internalcall 
	{
		.param [2]
			.custom instance void [mscorlib]System.Runtime.InteropServices.ComAliasNameAttribute::.ctor(string) = (
				01 00 29 41 73 70 65 6e 54 65 63 68 2e 41 73 70
				65 6e 50 6c 75 73 2e 41 6f 73 61 70 66 73 2e 77
				69 72 65 53 54 47 4d 45 44 49 55 4d 00 00
			)
	} // end of method IDataObject::RemoteGetData

	.method public hidebysig newslot abstract virtual 
		instance void RemoteGetDataHere (
			[in] valuetype AspenTech.AspenPlus.Aosapfs.FORMATETC& pformatetc,
			[in] [out] native int pRemoteMedium
		) runtime managed internalcall 
	{
		.param [2]
			.custom instance void [mscorlib]System.Runtime.InteropServices.ComAliasNameAttribute::.ctor(string) = (
				01 00 29 41 73 70 65 6e 54 65 63 68 2e 41 73 70
				65 6e 50 6c 75 73 2e 41 6f 73 61 70 66 73 2e 77
				69 72 65 53 54 47 4d 45 44 49 55 4d 00 00
			)
	} // end of method IDataObject::RemoteGetDataHere

	.method public hidebysig newslot abstract virtual 
		instance void QueryGetData (
			[in] valuetype AspenTech.AspenPlus.Aosapfs.FORMATETC& pformatetc
		) runtime managed internalcall 
	{
	} // end of method IDataObject::QueryGetData

	.method public hidebysig newslot abstract virtual 
		instance void GetCanonicalFormatEtc (
			[in] valuetype AspenTech.AspenPlus.Aosapfs.FORMATETC& pformatectIn,
			[out] valuetype AspenTech.AspenPlus.Aosapfs.FORMATETC& pformatetcOut
		) runtime managed internalcall 
	{
	} // end of method IDataObject::GetCanonicalFormatEtc

	.method public hidebysig newslot abstract virtual 
		instance void RemoteSetData (
			[in] valuetype AspenTech.AspenPlus.Aosapfs.FORMATETC& pformatetc,
			[in] native int pmedium,
			[in] int32 fRelease
		) runtime managed internalcall 
	{
		.param [2]
			.custom instance void [mscorlib]System.Runtime.InteropServices.ComAliasNameAttribute::.ctor(string) = (
				01 00 2e 41 73 70 65 6e 54 65 63 68 2e 41 73 70
				65 6e 50 6c 75 73 2e 41 6f 73 61 70 66 73 2e 77
				69 72 65 46 4c 41 47 5f 53 54 47 4d 45 44 49 55
				4d 00 00
			)
	} // end of method IDataObject::RemoteSetData

	.method public hidebysig newslot abstract virtual 
		instance void EnumFormatEtc (
			[in] uint32 dwDirection,
			[out] class AspenTech.AspenPlus.Aosapfs.IEnumFORMATETC& marshal(interface) ppenumFormatEtc
		) runtime managed internalcall 
	{
	} // end of method IDataObject::EnumFormatEtc

	.method public hidebysig newslot abstract virtual 
		instance void DAdvise (
			[in] valuetype AspenTech.AspenPlus.Aosapfs.FORMATETC& pformatetc,
			[in] uint32 advf,
			[in] class AspenTech.AspenPlus.Aosapfs.IAdviseSink marshal(interface) pAdvSink,
			[out] uint32& pdwConnection
		) runtime managed internalcall 
	{
	} // end of method IDataObject::DAdvise

	.method public hidebysig newslot abstract virtual 
		instance void DUnadvise (
			[in] uint32 dwConnection
		) runtime managed internalcall 
	{
	} // end of method IDataObject::DUnadvise

	.method public hidebysig newslot abstract virtual 
		instance void EnumDAdvise (
			[out] class AspenTech.AspenPlus.Aosapfs.IEnumSTATDATA& marshal(interface) ppenumAdvise
		) runtime managed internalcall 
	{
	} // end of method IDataObject::EnumDAdvise

} // end of class AspenTech.AspenPlus.Aosapfs.IDataObject

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.OLEVERB
	extends [mscorlib]System.ValueType
{
	.pack 8
	.size 0

	// Fields
	.field public int32 lVerb
	.field public marshal(lpwstr) string lpszVerbName
	.field public uint32 fuFlags
	.field public uint32 grfAttribs

} // end of class AspenTech.AspenPlus.Aosapfs.OLEVERB

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.userCLIPFORMAT
	extends [mscorlib]System.ValueType
{
	.pack 8
	.size 0

	// Fields
	.field public int32 fContext
	.field public valuetype AspenTech.AspenPlus.Aosapfs.__MIDL_IWinTypes_0001 u

} // end of class AspenTech.AspenPlus.Aosapfs.userCLIPFORMAT

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.DVTARGETDEVICE
	extends [mscorlib]System.ValueType
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.pack 4
	.size 0

	// Fields
	.field public uint32 tdSize
	.field public uint16 tdDriverNameOffset
	.field public uint16 tdDeviceNameOffset
	.field public uint16 tdPortNameOffset
	.field public uint16 tdExtDevmodeOffset
	.field public native int tdData
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)

} // end of class AspenTech.AspenPlus.Aosapfs.DVTARGETDEVICE

.class public explicit ansi sealed AspenTech.AspenPlus.Aosapfs.__MIDL_IWinTypes_0001
	extends [mscorlib]System.ValueType
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.pack 8
	.size 8

	// Fields
	.field [0] public uint32 dwValue

} // end of class AspenTech.AspenPlus.Aosapfs.__MIDL_IWinTypes_0001

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs._STGMEDIUM_UNION
	extends [mscorlib]System.ValueType
{
	.pack 8
	.size 0

	// Fields
	.field public uint32 tymed
	.field public valuetype AspenTech.AspenPlus.Aosapfs.__MIDL_IAdviseSink_0003 u

} // end of class AspenTech.AspenPlus.Aosapfs._STGMEDIUM_UNION

.class public explicit ansi sealed AspenTech.AspenPlus.Aosapfs.__MIDL_IAdviseSink_0003
	extends [mscorlib]System.ValueType
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.pack 8
	.size 8

} // end of class AspenTech.AspenPlus.Aosapfs.__MIDL_IAdviseSink_0003

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.userHMETAFILEPICT
	extends [mscorlib]System.ValueType
{
	.pack 8
	.size 0

	// Fields
	.field public int32 fContext
	.field public valuetype AspenTech.AspenPlus.Aosapfs.__MIDL_IWinTypes_0005 u

} // end of class AspenTech.AspenPlus.Aosapfs.userHMETAFILEPICT

.class public explicit ansi sealed AspenTech.AspenPlus.Aosapfs.__MIDL_IWinTypes_0005
	extends [mscorlib]System.ValueType
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.pack 8
	.size 8

	// Fields
	.field [0] public int32 hInproc
	.field [0] public int64 hInproc64

} // end of class AspenTech.AspenPlus.Aosapfs.__MIDL_IWinTypes_0005

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.remoteMETAFILEPICT
	extends [mscorlib]System.ValueType
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.pack 8
	.size 0

	// Fields
	.field public int32 mm
	.field public int32 xExt
	.field public int32 yExt
	.field public native int hMF
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)

} // end of class AspenTech.AspenPlus.Aosapfs.remoteMETAFILEPICT

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.userHMETAFILE
	extends [mscorlib]System.ValueType
{
	.pack 8
	.size 0

	// Fields
	.field public int32 fContext
	.field public valuetype AspenTech.AspenPlus.Aosapfs.__MIDL_IWinTypes_0004 u

} // end of class AspenTech.AspenPlus.Aosapfs.userHMETAFILE

.class public explicit ansi sealed AspenTech.AspenPlus.Aosapfs.__MIDL_IWinTypes_0004
	extends [mscorlib]System.ValueType
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.pack 8
	.size 8

	// Fields
	.field [0] public int32 hInproc
	.field [0] public int64 hInproc64

} // end of class AspenTech.AspenPlus.Aosapfs.__MIDL_IWinTypes_0004

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.BYTE_BLOB
	extends [mscorlib]System.ValueType
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.pack 4
	.size 0

	// Fields
	.field public uint32 clSize
	.field public native int abData
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)

} // end of class AspenTech.AspenPlus.Aosapfs.BYTE_BLOB

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.userHENHMETAFILE
	extends [mscorlib]System.ValueType
{
	.pack 8
	.size 0

	// Fields
	.field public int32 fContext
	.field public valuetype AspenTech.AspenPlus.Aosapfs.__MIDL_IWinTypes_0006 u

} // end of class AspenTech.AspenPlus.Aosapfs.userHENHMETAFILE

.class public explicit ansi sealed AspenTech.AspenPlus.Aosapfs.__MIDL_IWinTypes_0006
	extends [mscorlib]System.ValueType
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.pack 8
	.size 8

	// Fields
	.field [0] public int32 hInproc
	.field [0] public int64 hInproc64

} // end of class AspenTech.AspenPlus.Aosapfs.__MIDL_IWinTypes_0006

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.GDI_OBJECT
	extends [mscorlib]System.ValueType
{
	.pack 8
	.size 0

	// Fields
	.field public uint32 ObjectType
	.field public valuetype AspenTech.AspenPlus.Aosapfs.__MIDL_IAdviseSink_0002 u

} // end of class AspenTech.AspenPlus.Aosapfs.GDI_OBJECT

.class public explicit ansi sealed AspenTech.AspenPlus.Aosapfs.__MIDL_IAdviseSink_0002
	extends [mscorlib]System.ValueType
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.pack 8
	.size 8

} // end of class AspenTech.AspenPlus.Aosapfs.__MIDL_IAdviseSink_0002

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.userHBITMAP
	extends [mscorlib]System.ValueType
{
	.pack 8
	.size 0

	// Fields
	.field public int32 fContext
	.field public valuetype AspenTech.AspenPlus.Aosapfs.__MIDL_IWinTypes_0007 u

} // end of class AspenTech.AspenPlus.Aosapfs.userHBITMAP

.class public explicit ansi sealed AspenTech.AspenPlus.Aosapfs.__MIDL_IWinTypes_0007
	extends [mscorlib]System.ValueType
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.pack 8
	.size 8

	// Fields
	.field [0] public int32 hInproc
	.field [0] public int64 hInproc64

} // end of class AspenTech.AspenPlus.Aosapfs.__MIDL_IWinTypes_0007

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.userBITMAP
	extends [mscorlib]System.ValueType
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.pack 4
	.size 0

	// Fields
	.field public int32 bmType
	.field public int32 bmWidth
	.field public int32 bmHeight
	.field public int32 bmWidthBytes
	.field public uint16 bmPlanes
	.field public uint16 bmBitsPixel
	.field public uint32 cbSize
	.field public native int pBuffer
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)

} // end of class AspenTech.AspenPlus.Aosapfs.userBITMAP

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.userHPALETTE
	extends [mscorlib]System.ValueType
{
	.pack 8
	.size 0

	// Fields
	.field public int32 fContext
	.field public valuetype AspenTech.AspenPlus.Aosapfs.__MIDL_IWinTypes_0008 u

} // end of class AspenTech.AspenPlus.Aosapfs.userHPALETTE

.class public explicit ansi sealed AspenTech.AspenPlus.Aosapfs.__MIDL_IWinTypes_0008
	extends [mscorlib]System.ValueType
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.pack 8
	.size 8

	// Fields
	.field [0] public int32 hInproc
	.field [0] public int64 hInproc64

} // end of class AspenTech.AspenPlus.Aosapfs.__MIDL_IWinTypes_0008

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.LOGPALETTE
	extends [mscorlib]System.ValueType
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.pack 2
	.size 0

	// Fields
	.field public uint16 palVersion
	.field public uint16 palNumEntries
	.field public native int palPalEntry
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)

} // end of class AspenTech.AspenPlus.Aosapfs.LOGPALETTE

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.PALETTEENTRY
	extends [mscorlib]System.ValueType
{
	.pack 1
	.size 0

	// Fields
	.field public uint8 peRed
	.field public uint8 peGreen
	.field public uint8 peBlue
	.field public uint8 peFlags

} // end of class AspenTech.AspenPlus.Aosapfs.PALETTEENTRY

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.userHGLOBAL
	extends [mscorlib]System.ValueType
{
	.pack 8
	.size 0

	// Fields
	.field public int32 fContext
	.field public valuetype AspenTech.AspenPlus.Aosapfs.__MIDL_IWinTypes_0003 u

} // end of class AspenTech.AspenPlus.Aosapfs.userHGLOBAL

.class public explicit ansi sealed AspenTech.AspenPlus.Aosapfs.__MIDL_IWinTypes_0003
	extends [mscorlib]System.ValueType
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.pack 8
	.size 8

	// Fields
	.field [0] public int32 hInproc
	.field [0] public int64 hInproc64

} // end of class AspenTech.AspenPlus.Aosapfs.__MIDL_IWinTypes_0003

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.FLAGGED_BYTE_BLOB
	extends [mscorlib]System.ValueType
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.pack 4
	.size 0

	// Fields
	.field public uint32 fFlags
	.field public uint32 clSize
	.field public native int abData
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)

} // end of class AspenTech.AspenPlus.Aosapfs.FLAGGED_BYTE_BLOB

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.userFLAG_STGMEDIUM
	extends [mscorlib]System.ValueType
{
	.pack 8
	.size 0

	// Fields
	.field public int32 ContextFlags
	.field public int32 fPassOwnership
	.field public valuetype AspenTech.AspenPlus.Aosapfs.userSTGMEDIUM Stgmed

} // end of class AspenTech.AspenPlus.Aosapfs.userFLAG_STGMEDIUM

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IEnumFORMATETC
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 30 30 30 30 30 31 30 33 2d 30 30 30 30
		2d 30 30 30 30 2d 43 30 30 30 2d 30 30 30 30 30
		30 30 30 30 30 34 36 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void RemoteNext (
			[in] uint32 celt,
			[out] valuetype AspenTech.AspenPlus.Aosapfs.FORMATETC& rgelt,
			[out] uint32& pceltFetched
		) runtime managed internalcall 
	{
	} // end of method IEnumFORMATETC::RemoteNext

	.method public hidebysig newslot abstract virtual 
		instance void Skip (
			[in] uint32 celt
		) runtime managed internalcall 
	{
	} // end of method IEnumFORMATETC::Skip

	.method public hidebysig newslot abstract virtual 
		instance void Reset () runtime managed internalcall 
	{
	} // end of method IEnumFORMATETC::Reset

	.method public hidebysig newslot abstract virtual 
		instance void Clone (
			[out] class AspenTech.AspenPlus.Aosapfs.IEnumFORMATETC& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IEnumFORMATETC::Clone

} // end of class AspenTech.AspenPlus.Aosapfs.IEnumFORMATETC

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IAdviseSink
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 30 30 30 30 30 31 30 46 2d 30 30 30 30
		2d 30 30 30 30 2d 43 30 30 30 2d 30 30 30 30 30
		30 30 30 30 30 34 36 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void RemoteOnDataChange (
			[in] valuetype AspenTech.AspenPlus.Aosapfs.FORMATETC& pformatetc,
			[in] native int pStgmed
		) runtime managed internalcall 
	{
		.param [2]
			.custom instance void [mscorlib]System.Runtime.InteropServices.ComAliasNameAttribute::.ctor(string) = (
				01 00 2f 41 73 70 65 6e 54 65 63 68 2e 41 73 70
				65 6e 50 6c 75 73 2e 41 6f 73 61 70 66 73 2e 77
				69 72 65 41 53 59 4e 43 5f 53 54 47 4d 45 44 49
				55 4d 00 00
			)
	} // end of method IAdviseSink::RemoteOnDataChange

	.method public hidebysig newslot abstract virtual 
		instance void RemoteOnViewChange (
			[in] uint32 dwAspect,
			[in] int32 lindex
		) runtime managed internalcall 
	{
	} // end of method IAdviseSink::RemoteOnViewChange

	.method public hidebysig newslot abstract virtual 
		instance void RemoteOnRename (
			[in] class AspenTech.AspenPlus.Aosapfs.IMoniker marshal(interface) pmk
		) runtime managed internalcall 
	{
	} // end of method IAdviseSink::RemoteOnRename

	.method public hidebysig newslot abstract virtual 
		instance void RemoteOnSave () runtime managed internalcall 
	{
	} // end of method IAdviseSink::RemoteOnSave

	.method public hidebysig newslot abstract virtual 
		instance void RemoteOnClose () runtime managed internalcall 
	{
	} // end of method IAdviseSink::RemoteOnClose

} // end of class AspenTech.AspenPlus.Aosapfs.IAdviseSink

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IEnumSTATDATA
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 30 30 30 30 30 31 30 35 2d 30 30 30 30
		2d 30 30 30 30 2d 43 30 30 30 2d 30 30 30 30 30
		30 30 30 30 30 34 36 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void RemoteNext (
			[in] uint32 celt,
			[out] valuetype AspenTech.AspenPlus.Aosapfs.STATDATA& rgelt,
			[out] uint32& pceltFetched
		) runtime managed internalcall 
	{
	} // end of method IEnumSTATDATA::RemoteNext

	.method public hidebysig newslot abstract virtual 
		instance void Skip (
			[in] uint32 celt
		) runtime managed internalcall 
	{
	} // end of method IEnumSTATDATA::Skip

	.method public hidebysig newslot abstract virtual 
		instance void Reset () runtime managed internalcall 
	{
	} // end of method IEnumSTATDATA::Reset

	.method public hidebysig newslot abstract virtual 
		instance void Clone (
			[out] class AspenTech.AspenPlus.Aosapfs.IEnumSTATDATA& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IEnumSTATDATA::Clone

} // end of class AspenTech.AspenPlus.Aosapfs.IEnumSTATDATA

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IPersist
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 30 30 30 30 30 31 30 43 2d 30 30 30 30
		2d 30 30 30 30 2d 43 30 30 30 2d 30 30 30 30 30
		30 30 30 30 30 34 36 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void GetClassID (
			[out] valuetype [mscorlib]System.Guid& pClassID
		) runtime managed internalcall 
	{
	} // end of method IPersist::GetClassID

} // end of class AspenTech.AspenPlus.Aosapfs.IPersist

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IPersistStream
	implements AspenTech.AspenPlus.Aosapfs.IPersist
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 30 30 30 30 30 31 30 39 2d 30 30 30 30
		2d 30 30 30 30 2d 43 30 30 30 2d 30 30 30 30 30
		30 30 30 30 30 34 36 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void GetClassID (
			[out] valuetype [mscorlib]System.Guid& pClassID
		) runtime managed internalcall 
	{
	} // end of method IPersistStream::GetClassID

	.method public hidebysig newslot abstract virtual 
		instance void IsDirty () runtime managed internalcall 
	{
	} // end of method IPersistStream::IsDirty

	.method public hidebysig newslot abstract virtual 
		instance void Load (
			[in] class AspenTech.AspenPlus.Aosapfs.IStream marshal(interface) pstm
		) runtime managed internalcall 
	{
	} // end of method IPersistStream::Load

	.method public hidebysig newslot abstract virtual 
		instance void Save (
			[in] class AspenTech.AspenPlus.Aosapfs.IStream marshal(interface) pstm,
			[in] int32 fClearDirty
		) runtime managed internalcall 
	{
	} // end of method IPersistStream::Save

	.method public hidebysig newslot abstract virtual 
		instance void GetSizeMax (
			[out] valuetype AspenTech.AspenPlus.Aosapfs.ULARGE_INTEGER& pcbSize
		) runtime managed internalcall 
	{
	} // end of method IPersistStream::GetSizeMax

} // end of class AspenTech.AspenPlus.Aosapfs.IPersistStream

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IMoniker
	implements AspenTech.AspenPlus.Aosapfs.IPersistStream
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 30 30 30 30 30 30 30 46 2d 30 30 30 30
		2d 30 30 30 30 2d 43 30 30 30 2d 30 30 30 30 30
		30 30 30 30 30 34 36 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void GetClassID (
			[out] valuetype [mscorlib]System.Guid& pClassID
		) runtime managed internalcall 
	{
	} // end of method IMoniker::GetClassID

	.method public hidebysig newslot abstract virtual 
		instance void IsDirty () runtime managed internalcall 
	{
	} // end of method IMoniker::IsDirty

	.method public hidebysig newslot abstract virtual 
		instance void Load (
			[in] class AspenTech.AspenPlus.Aosapfs.IStream marshal(interface) pstm
		) runtime managed internalcall 
	{
	} // end of method IMoniker::Load

	.method public hidebysig newslot abstract virtual 
		instance void Save (
			[in] class AspenTech.AspenPlus.Aosapfs.IStream marshal(interface) pstm,
			[in] int32 fClearDirty
		) runtime managed internalcall 
	{
	} // end of method IMoniker::Save

	.method public hidebysig newslot abstract virtual 
		instance void GetSizeMax (
			[out] valuetype AspenTech.AspenPlus.Aosapfs.ULARGE_INTEGER& pcbSize
		) runtime managed internalcall 
	{
	} // end of method IMoniker::GetSizeMax

	.method public hidebysig newslot abstract virtual 
		instance void RemoteBindToObject (
			[in] class AspenTech.AspenPlus.Aosapfs.IBindCtx marshal(interface) pbc,
			[in] class AspenTech.AspenPlus.Aosapfs.IMoniker marshal(interface) pmkToLeft,
			[in] valuetype [mscorlib]System.Guid& riidResult,
			[out] object& marshal(iunknown) ppvResult
		) runtime managed internalcall 
	{
	} // end of method IMoniker::RemoteBindToObject

	.method public hidebysig newslot abstract virtual 
		instance void RemoteBindToStorage (
			[in] class AspenTech.AspenPlus.Aosapfs.IBindCtx marshal(interface) pbc,
			[in] class AspenTech.AspenPlus.Aosapfs.IMoniker marshal(interface) pmkToLeft,
			[in] valuetype [mscorlib]System.Guid& riid,
			[out] object& marshal(iunknown) ppvObj
		) runtime managed internalcall 
	{
	} // end of method IMoniker::RemoteBindToStorage

	.method public hidebysig newslot abstract virtual 
		instance void Reduce (
			[in] class AspenTech.AspenPlus.Aosapfs.IBindCtx marshal(interface) pbc,
			[in] uint32 dwReduceHowFar,
			[in] [out] class AspenTech.AspenPlus.Aosapfs.IMoniker& marshal(interface) ppmkToLeft,
			[out] class AspenTech.AspenPlus.Aosapfs.IMoniker& marshal(interface) ppmkReduced
		) runtime managed internalcall 
	{
	} // end of method IMoniker::Reduce

	.method public hidebysig newslot abstract virtual 
		instance void ComposeWith (
			[in] class AspenTech.AspenPlus.Aosapfs.IMoniker marshal(interface) pmkRight,
			[in] int32 fOnlyIfNotGeneric,
			[out] class AspenTech.AspenPlus.Aosapfs.IMoniker& marshal(interface) ppmkComposite
		) runtime managed internalcall 
	{
	} // end of method IMoniker::ComposeWith

	.method public hidebysig newslot abstract virtual 
		instance void Enum (
			[in] int32 fForward,
			[out] class AspenTech.AspenPlus.Aosapfs.IEnumMoniker& marshal(interface) ppenumMoniker
		) runtime managed internalcall 
	{
	} // end of method IMoniker::Enum

	.method public hidebysig newslot abstract virtual 
		instance void IsEqual (
			[in] class AspenTech.AspenPlus.Aosapfs.IMoniker marshal(interface) pmkOtherMoniker
		) runtime managed internalcall 
	{
	} // end of method IMoniker::IsEqual

	.method public hidebysig newslot abstract virtual 
		instance void Hash (
			[out] uint32& pdwHash
		) runtime managed internalcall 
	{
	} // end of method IMoniker::Hash

	.method public hidebysig newslot abstract virtual 
		instance void IsRunning (
			[in] class AspenTech.AspenPlus.Aosapfs.IBindCtx marshal(interface) pbc,
			[in] class AspenTech.AspenPlus.Aosapfs.IMoniker marshal(interface) pmkToLeft,
			[in] class AspenTech.AspenPlus.Aosapfs.IMoniker marshal(interface) pmkNewlyRunning
		) runtime managed internalcall 
	{
	} // end of method IMoniker::IsRunning

	.method public hidebysig newslot abstract virtual 
		instance void GetTimeOfLastChange (
			[in] class AspenTech.AspenPlus.Aosapfs.IBindCtx marshal(interface) pbc,
			[in] class AspenTech.AspenPlus.Aosapfs.IMoniker marshal(interface) pmkToLeft,
			[out] valuetype AspenTech.AspenPlus.Aosapfs.FILETIME& pfiletime
		) runtime managed internalcall 
	{
	} // end of method IMoniker::GetTimeOfLastChange

	.method public hidebysig newslot abstract virtual 
		instance void Inverse (
			[out] class AspenTech.AspenPlus.Aosapfs.IMoniker& marshal(interface) ppmk
		) runtime managed internalcall 
	{
	} // end of method IMoniker::Inverse

	.method public hidebysig newslot abstract virtual 
		instance void CommonPrefixWith (
			[in] class AspenTech.AspenPlus.Aosapfs.IMoniker marshal(interface) pmkOther,
			[out] class AspenTech.AspenPlus.Aosapfs.IMoniker& marshal(interface) ppmkPrefix
		) runtime managed internalcall 
	{
	} // end of method IMoniker::CommonPrefixWith

	.method public hidebysig newslot abstract virtual 
		instance void RelativePathTo (
			[in] class AspenTech.AspenPlus.Aosapfs.IMoniker marshal(interface) pmkOther,
			[out] class AspenTech.AspenPlus.Aosapfs.IMoniker& marshal(interface) ppmkRelPath
		) runtime managed internalcall 
	{
	} // end of method IMoniker::RelativePathTo

	.method public hidebysig newslot abstract virtual 
		instance void GetDisplayName (
			[in] class AspenTech.AspenPlus.Aosapfs.IBindCtx marshal(interface) pbc,
			[in] class AspenTech.AspenPlus.Aosapfs.IMoniker marshal(interface) pmkToLeft,
			[out] string& marshal(lpwstr) ppszDisplayName
		) runtime managed internalcall 
	{
	} // end of method IMoniker::GetDisplayName

	.method public hidebysig newslot abstract virtual 
		instance void ParseDisplayName (
			[in] class AspenTech.AspenPlus.Aosapfs.IBindCtx marshal(interface) pbc,
			[in] class AspenTech.AspenPlus.Aosapfs.IMoniker marshal(interface) pmkToLeft,
			[in] string marshal(lpwstr) pszDisplayName,
			[out] uint32& pchEaten,
			[out] class AspenTech.AspenPlus.Aosapfs.IMoniker& marshal(interface) ppmkOut
		) runtime managed internalcall 
	{
	} // end of method IMoniker::ParseDisplayName

	.method public hidebysig newslot abstract virtual 
		instance void IsSystemMoniker (
			[out] uint32& pdwMksys
		) runtime managed internalcall 
	{
	} // end of method IMoniker::IsSystemMoniker

} // end of class AspenTech.AspenPlus.Aosapfs.IMoniker

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IBindCtx
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 30 30 30 30 30 30 30 45 2d 30 30 30 30
		2d 30 30 30 30 2d 43 30 30 30 2d 30 30 30 30 30
		30 30 30 30 30 34 36 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void RegisterObjectBound (
			[in] object marshal(iunknown) pUnk
		) runtime managed internalcall 
	{
	} // end of method IBindCtx::RegisterObjectBound

	.method public hidebysig newslot abstract virtual 
		instance void RevokeObjectBound (
			[in] object marshal(iunknown) pUnk
		) runtime managed internalcall 
	{
	} // end of method IBindCtx::RevokeObjectBound

	.method public hidebysig newslot abstract virtual 
		instance void ReleaseBoundObjects () runtime managed internalcall 
	{
	} // end of method IBindCtx::ReleaseBoundObjects

	.method public hidebysig newslot abstract virtual 
		instance void RemoteSetBindOptions (
			[in] valuetype AspenTech.AspenPlus.Aosapfs.BIND_OPTS2& pbindopts
		) runtime managed internalcall 
	{
	} // end of method IBindCtx::RemoteSetBindOptions

	.method public hidebysig newslot abstract virtual 
		instance void RemoteGetBindOptions (
			[in] [out] valuetype AspenTech.AspenPlus.Aosapfs.BIND_OPTS2& pbindopts
		) runtime managed internalcall 
	{
	} // end of method IBindCtx::RemoteGetBindOptions

	.method public hidebysig newslot abstract virtual 
		instance void GetRunningObjectTable (
			[out] class AspenTech.AspenPlus.Aosapfs.IRunningObjectTable& marshal(interface) pprot
		) runtime managed internalcall 
	{
	} // end of method IBindCtx::GetRunningObjectTable

	.method public hidebysig newslot abstract virtual 
		instance void RegisterObjectParam (
			[in] string marshal(lpwstr) pszKey,
			[in] object marshal(iunknown) pUnk
		) runtime managed internalcall 
	{
	} // end of method IBindCtx::RegisterObjectParam

	.method public hidebysig newslot abstract virtual 
		instance void GetObjectParam (
			[in] string marshal(lpwstr) pszKey,
			[out] object& marshal(iunknown) ppunk
		) runtime managed internalcall 
	{
	} // end of method IBindCtx::GetObjectParam

	.method public hidebysig newslot abstract virtual 
		instance void EnumObjectParam (
			[out] class AspenTech.AspenPlus.Aosapfs.IEnumString& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IBindCtx::EnumObjectParam

	.method public hidebysig newslot abstract virtual 
		instance void RevokeObjectParam (
			[in] string marshal(lpwstr) pszKey
		) runtime managed internalcall 
	{
	} // end of method IBindCtx::RevokeObjectParam

} // end of class AspenTech.AspenPlus.Aosapfs.IBindCtx

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IEnumMoniker
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 30 30 30 30 30 31 30 32 2d 30 30 30 30
		2d 30 30 30 30 2d 43 30 30 30 2d 30 30 30 30 30
		30 30 30 30 30 34 36 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void RemoteNext (
			[in] uint32 celt,
			[out] class AspenTech.AspenPlus.Aosapfs.IMoniker& marshal(interface) rgelt,
			[out] uint32& pceltFetched
		) runtime managed internalcall 
	{
	} // end of method IEnumMoniker::RemoteNext

	.method public hidebysig newslot abstract virtual 
		instance void Skip (
			[in] uint32 celt
		) runtime managed internalcall 
	{
	} // end of method IEnumMoniker::Skip

	.method public hidebysig newslot abstract virtual 
		instance void Reset () runtime managed internalcall 
	{
	} // end of method IEnumMoniker::Reset

	.method public hidebysig newslot abstract virtual 
		instance void Clone (
			[out] class AspenTech.AspenPlus.Aosapfs.IEnumMoniker& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IEnumMoniker::Clone

} // end of class AspenTech.AspenPlus.Aosapfs.IEnumMoniker

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.BIND_OPTS2
	extends [mscorlib]System.ValueType
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.pack 8
	.size 0

	// Fields
	.field public uint32 cbStruct
	.field public uint32 grfFlags
	.field public uint32 grfMode
	.field public uint32 dwTickCountDeadline
	.field public uint32 dwTrackFlags
	.field public uint32 dwClassContext
	.field public uint32 locale
	.field public native int pServerInfo
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)

} // end of class AspenTech.AspenPlus.Aosapfs.BIND_OPTS2

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IRunningObjectTable
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 30 30 30 30 30 30 31 30 2d 30 30 30 30
		2d 30 30 30 30 2d 43 30 30 30 2d 30 30 30 30 30
		30 30 30 30 30 34 36 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void Register (
			[in] uint32 grfFlags,
			[in] object marshal(iunknown) punkObject,
			[in] class AspenTech.AspenPlus.Aosapfs.IMoniker marshal(interface) pmkObjectName,
			[out] uint32& pdwRegister
		) runtime managed internalcall 
	{
	} // end of method IRunningObjectTable::Register

	.method public hidebysig newslot abstract virtual 
		instance void Revoke (
			[in] uint32 dwRegister
		) runtime managed internalcall 
	{
	} // end of method IRunningObjectTable::Revoke

	.method public hidebysig newslot abstract virtual 
		instance void IsRunning (
			[in] class AspenTech.AspenPlus.Aosapfs.IMoniker marshal(interface) pmkObjectName
		) runtime managed internalcall 
	{
	} // end of method IRunningObjectTable::IsRunning

	.method public hidebysig newslot abstract virtual 
		instance void GetObject (
			[in] class AspenTech.AspenPlus.Aosapfs.IMoniker marshal(interface) pmkObjectName,
			[out] object& marshal(iunknown) ppunkObject
		) runtime managed internalcall 
	{
	} // end of method IRunningObjectTable::GetObject

	.method public hidebysig newslot abstract virtual 
		instance void NoteChangeTime (
			[in] uint32 dwRegister,
			[in] valuetype AspenTech.AspenPlus.Aosapfs.FILETIME& pfiletime
		) runtime managed internalcall 
	{
	} // end of method IRunningObjectTable::NoteChangeTime

	.method public hidebysig newslot abstract virtual 
		instance void GetTimeOfLastChange (
			[in] class AspenTech.AspenPlus.Aosapfs.IMoniker marshal(interface) pmkObjectName,
			[out] valuetype AspenTech.AspenPlus.Aosapfs.FILETIME& pfiletime
		) runtime managed internalcall 
	{
	} // end of method IRunningObjectTable::GetTimeOfLastChange

	.method public hidebysig newslot abstract virtual 
		instance void EnumRunning (
			[out] class AspenTech.AspenPlus.Aosapfs.IEnumMoniker& marshal(interface) ppenumMoniker
		) runtime managed internalcall 
	{
	} // end of method IRunningObjectTable::EnumRunning

} // end of class AspenTech.AspenPlus.Aosapfs.IRunningObjectTable

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IEnumString
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 30 30 30 30 30 31 30 31 2d 30 30 30 30
		2d 30 30 30 30 2d 43 30 30 30 2d 30 30 30 30 30
		30 30 30 30 30 34 36 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void RemoteNext (
			[in] uint32 celt,
			[out] string& marshal(lpwstr) rgelt,
			[out] uint32& pceltFetched
		) runtime managed internalcall 
	{
	} // end of method IEnumString::RemoteNext

	.method public hidebysig newslot abstract virtual 
		instance void Skip (
			[in] uint32 celt
		) runtime managed internalcall 
	{
	} // end of method IEnumString::Skip

	.method public hidebysig newslot abstract virtual 
		instance void Reset () runtime managed internalcall 
	{
	} // end of method IEnumString::Reset

	.method public hidebysig newslot abstract virtual 
		instance void Clone (
			[out] class AspenTech.AspenPlus.Aosapfs.IEnumString& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IEnumString::Clone

} // end of class AspenTech.AspenPlus.Aosapfs.IEnumString

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.COSERVERINFO
	extends [mscorlib]System.ValueType
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.pack 8
	.size 0

	// Fields
	.field public uint32 dwReserved1
	.field public marshal(lpwstr) string pwszName
	.field public native int pAuthInfo
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.field public uint32 dwReserved2

} // end of class AspenTech.AspenPlus.Aosapfs.COSERVERINFO

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.COAUTHINFO
	extends [mscorlib]System.ValueType
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.pack 8
	.size 0

	// Fields
	.field public uint32 dwAuthnSvc
	.field public uint32 dwAuthzSvc
	.field public marshal(lpwstr) string pwszServerPrincName
	.field public uint32 dwAuthnLevel
	.field public uint32 dwImpersonationLevel
	.field public native int pAuthIdentityData
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.field public uint32 dwCapabilities

} // end of class AspenTech.AspenPlus.Aosapfs.COAUTHINFO

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.COAUTHIDENTITY
	extends [mscorlib]System.ValueType
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.pack 8
	.size 0

	// Fields
	.field public native int User
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.field public uint32 UserLength
	.field public native int Domain
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.field public uint32 DomainLength
	.field public native int Password
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.field public uint32 PasswordLength
	.field public uint32 'flags'

} // end of class AspenTech.AspenPlus.Aosapfs.COAUTHIDENTITY

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.STATDATA
	extends [mscorlib]System.ValueType
{
	.pack 8
	.size 0

	// Fields
	.field public valuetype AspenTech.AspenPlus.Aosapfs.FORMATETC FORMATETC
	.field public uint32 advf
	.field public marshal(interface) class AspenTech.AspenPlus.Aosapfs.IAdviseSink pAdvSink
	.field public uint32 dwConnection

} // end of class AspenTech.AspenPlus.Aosapfs.STATDATA

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IEnumAModel
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 42 31 39 45 34 32 43 30 2d 37 38 38 39
		2d 31 31 44 30 2d 41 39 31 42 2d 30 30 30 30 43
		30 41 31 31 38 44 42 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void Next (
			uint32 nCount,
			class AspenTech.AspenPlus.Aosapfs.IAModel& marshal(interface) ppModel,
			uint32& pnumFetched
		) runtime managed internalcall 
	{
	} // end of method IEnumAModel::Next

	.method public hidebysig newslot abstract virtual 
		instance void Skip (
			uint32 nCount
		) runtime managed internalcall 
	{
	} // end of method IEnumAModel::Skip

	.method public hidebysig newslot abstract virtual 
		instance void Reset () runtime managed internalcall 
	{
	} // end of method IEnumAModel::Reset

	.method public hidebysig newslot abstract virtual 
		instance void Clone (
			class AspenTech.AspenPlus.Aosapfs.IEnumAModel& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IEnumAModel::Clone

} // end of class AspenTech.AspenPlus.Aosapfs.IEnumAModel

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IAEditModels
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 42 31 39 45 34 32 43 36 2d 37 38 38 39
		2d 31 31 44 30 2d 41 39 31 42 2d 30 30 30 30 43
		30 41 31 31 38 44 42 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void GetModelLibrary (
			class AspenTech.AspenPlus.Aosapfs.IAModelLibrary2& marshal(interface) ppModelLibrary
		) runtime managed internalcall 
	{
	} // end of method IAEditModels::GetModelLibrary

	.method public hidebysig newslot abstract virtual 
		instance void SetModelLibrary (
			class AspenTech.AspenPlus.Aosapfs.IAModelLibrary2 marshal(interface) pModelLibrary
		) runtime managed internalcall 
	{
	} // end of method IAEditModels::SetModelLibrary

	.method public hidebysig newslot abstract virtual 
		instance void AddModel (
			class AspenTech.AspenPlus.Aosapfs.IAModel& marshal(interface) ppModel,
			uint8& pName,
			class AspenTech.AspenPlus.Aosapfs.IAModelType marshal(interface) pModelType
		) runtime managed internalcall 
	{
	} // end of method IAEditModels::AddModel

	.method public hidebysig newslot abstract virtual 
		instance void RemoveModel (
			class AspenTech.AspenPlus.Aosapfs.IAModel marshal(interface) pModel
		) runtime managed internalcall 
	{
	} // end of method IAEditModels::RemoveModel

	.method public hidebysig newslot abstract virtual 
		instance void FindModel (
			uint8& pName,
			class AspenTech.AspenPlus.Aosapfs.IAModel& marshal(interface) ppModel
		) runtime managed internalcall 
	{
	} // end of method IAEditModels::FindModel

	.method public hidebysig newslot abstract virtual 
		instance void EnumModels (
			class AspenTech.AspenPlus.Aosapfs.IEnumAModel& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IAEditModels::EnumModels

} // end of class AspenTech.AspenPlus.Aosapfs.IAEditModels

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IACategory
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 41 38 39 42 42 31 44 30 2d 31 30 35 37
		2d 31 31 44 32 2d 38 30 45 34 2d 30 30 30 30 43
		30 39 45 46 43 46 33 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void GetName (
			uint8& pName,
			int32 nSize
		) runtime managed internalcall 
	{
	} // end of method IACategory::GetName

	.method public hidebysig newslot abstract virtual 
		instance void SetName (
			uint8& pName
		) runtime managed internalcall 
	{
	} // end of method IACategory::SetName

	.method public hidebysig newslot abstract virtual 
		instance void AddModelType (
			class AspenTech.AspenPlus.Aosapfs.IAModelType marshal(interface) pModelType
		) runtime managed internalcall 
	{
	} // end of method IACategory::AddModelType

	.method public hidebysig newslot abstract virtual 
		instance void RemoveModelType (
			class AspenTech.AspenPlus.Aosapfs.IAModelType marshal(interface) pModelType
		) runtime managed internalcall 
	{
	} // end of method IACategory::RemoveModelType

	.method public hidebysig newslot abstract virtual 
		instance void FindModelType (
			uint8& pName,
			class AspenTech.AspenPlus.Aosapfs.IAModelType& marshal(interface) ppModelType
		) runtime managed internalcall 
	{
	} // end of method IACategory::FindModelType

	.method public hidebysig newslot abstract virtual 
		instance void EnumModelType (
			class AspenTech.AspenPlus.Aosapfs.IEnumAModelType& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IACategory::EnumModelType

} // end of class AspenTech.AspenPlus.Aosapfs.IACategory

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IAModelLibrary2
	implements AspenTech.AspenPlus.Aosapfs.IACategory
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 42 31 39 45 34 32 42 30 2d 37 38 38 39
		2d 31 31 44 30 2d 41 39 31 42 2d 30 30 30 30 43
		30 41 31 31 38 44 42 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void GetName (
			uint8& pName,
			int32 nSize
		) runtime managed internalcall 
	{
	} // end of method IAModelLibrary2::GetName

	.method public hidebysig newslot abstract virtual 
		instance void SetName (
			uint8& pName
		) runtime managed internalcall 
	{
	} // end of method IAModelLibrary2::SetName

	.method public hidebysig newslot abstract virtual 
		instance void AddModelType (
			class AspenTech.AspenPlus.Aosapfs.IAModelType marshal(interface) pModelType
		) runtime managed internalcall 
	{
	} // end of method IAModelLibrary2::AddModelType

	.method public hidebysig newslot abstract virtual 
		instance void RemoveModelType (
			class AspenTech.AspenPlus.Aosapfs.IAModelType marshal(interface) pModelType
		) runtime managed internalcall 
	{
	} // end of method IAModelLibrary2::RemoveModelType

	.method public hidebysig newslot abstract virtual 
		instance void FindModelType (
			uint8& pName,
			class AspenTech.AspenPlus.Aosapfs.IAModelType& marshal(interface) ppModelType
		) runtime managed internalcall 
	{
	} // end of method IAModelLibrary2::FindModelType

	.method public hidebysig newslot abstract virtual 
		instance void EnumModelType (
			class AspenTech.AspenPlus.Aosapfs.IEnumAModelType& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IAModelLibrary2::EnumModelType

	.method public hidebysig newslot abstract virtual 
		instance void GetIconLibrary (
			class AspenTech.AspenPlus.Aosapfs.IAIconLibrary& marshal(interface) ppIconLib
		) runtime managed internalcall 
	{
	} // end of method IAModelLibrary2::GetIconLibrary

	.method public hidebysig newslot abstract virtual 
		instance void SetIconLibrary (
			class AspenTech.AspenPlus.Aosapfs.IAIconLibrary marshal(interface) pIconLib
		) runtime managed internalcall 
	{
	} // end of method IAModelLibrary2::SetIconLibrary

} // end of class AspenTech.AspenPlus.Aosapfs.IAModelLibrary2

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IAEditBlocks
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 42 31 39 45 34 32 43 31 2d 37 38 38 39
		2d 31 31 44 30 2d 41 39 31 42 2d 30 30 30 30 43
		30 41 31 31 38 44 42 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void AddBlock (
			class AspenTech.AspenPlus.Aosapfs.IAModel& marshal(interface) ppModel,
			uint8& pName,
			class AspenTech.AspenPlus.Aosapfs.IAModelType marshal(interface) pModelType
		) runtime managed internalcall 
	{
	} // end of method IAEditBlocks::AddBlock

	.method public hidebysig newslot abstract virtual 
		instance void RemoveBlock (
			class AspenTech.AspenPlus.Aosapfs.IAModel marshal(interface) pModel
		) runtime managed internalcall 
	{
	} // end of method IAEditBlocks::RemoveBlock

	.method public hidebysig newslot abstract virtual 
		instance void FindBlock (
			uint8& pName,
			class AspenTech.AspenPlus.Aosapfs.IAModel& marshal(interface) ppModel
		) runtime managed internalcall 
	{
	} // end of method IAEditBlocks::FindBlock

	.method public hidebysig newslot abstract virtual 
		instance void EnumBlocks (
			class AspenTech.AspenPlus.Aosapfs.IEnumAModel& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IAEditBlocks::EnumBlocks

} // end of class AspenTech.AspenPlus.Aosapfs.IAEditBlocks

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IAEditStreams
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 42 31 39 45 34 32 43 32 2d 37 38 38 39
		2d 31 31 44 30 2d 41 39 31 42 2d 30 30 30 30 43
		30 41 31 31 38 44 42 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void AddStream (
			class AspenTech.AspenPlus.Aosapfs.IAModel& marshal(interface) ppModel,
			uint8& pName,
			class AspenTech.AspenPlus.Aosapfs.IAModelType marshal(interface) pModelType
		) runtime managed internalcall 
	{
	} // end of method IAEditStreams::AddStream

	.method public hidebysig newslot abstract virtual 
		instance void RemoveStream (
			class AspenTech.AspenPlus.Aosapfs.IAModel marshal(interface) pModel
		) runtime managed internalcall 
	{
	} // end of method IAEditStreams::RemoveStream

	.method public hidebysig newslot abstract virtual 
		instance void FindStream (
			uint8& pName,
			class AspenTech.AspenPlus.Aosapfs.IAModel& marshal(interface) ppModel
		) runtime managed internalcall 
	{
	} // end of method IAEditStreams::FindStream

	.method public hidebysig newslot abstract virtual 
		instance void EnumStreams (
			class AspenTech.AspenPlus.Aosapfs.IEnumAModel& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IAEditStreams::EnumStreams

} // end of class AspenTech.AspenPlus.Aosapfs.IAEditStreams

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IAConnection
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 42 31 39 45 34 32 43 33 2d 37 38 38 39
		2d 31 31 44 30 2d 41 39 31 42 2d 30 30 30 30 43
		30 41 31 31 38 44 42 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void GetPort1 (
			class AspenTech.AspenPlus.Aosapfs.IAPort& marshal(interface) ppPort,
			int32& pInstanceNumber
		) runtime managed internalcall 
	{
	} // end of method IAConnection::GetPort1

	.method public hidebysig newslot abstract virtual 
		instance void GetPort2 (
			class AspenTech.AspenPlus.Aosapfs.IAPort& marshal(interface) ppPort,
			int32& pInstanceNumber
		) runtime managed internalcall 
	{
	} // end of method IAConnection::GetPort2

	.method public hidebysig newslot abstract virtual 
		instance void Disconnect () runtime managed internalcall 
	{
	} // end of method IAConnection::Disconnect

} // end of class AspenTech.AspenPlus.Aosapfs.IAConnection

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IEnumAConnection
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 42 31 39 45 34 32 43 34 2d 37 38 38 39
		2d 31 31 44 30 2d 41 39 31 42 2d 30 30 30 30 43
		30 41 31 31 38 44 42 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void Next (
			uint32 nCount,
			class AspenTech.AspenPlus.Aosapfs.IAConnection& marshal(interface) ppConn,
			uint32& pnumFetched
		) runtime managed internalcall 
	{
	} // end of method IEnumAConnection::Next

	.method public hidebysig newslot abstract virtual 
		instance void Skip (
			uint32 nCount
		) runtime managed internalcall 
	{
	} // end of method IEnumAConnection::Skip

	.method public hidebysig newslot abstract virtual 
		instance void Reset () runtime managed internalcall 
	{
	} // end of method IEnumAConnection::Reset

	.method public hidebysig newslot abstract virtual 
		instance void Clone (
			class AspenTech.AspenPlus.Aosapfs.IEnumAConnection& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IEnumAConnection::Clone

} // end of class AspenTech.AspenPlus.Aosapfs.IEnumAConnection

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IAEditConnections
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 42 31 39 45 34 32 43 35 2d 37 38 38 39
		2d 31 31 44 30 2d 41 39 31 42 2d 30 30 30 30 43
		30 41 31 31 38 44 42 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void Connect (
			class AspenTech.AspenPlus.Aosapfs.IAConnection& marshal(interface) ppConn,
			class AspenTech.AspenPlus.Aosapfs.IAPort marshal(interface) pPort1,
			class AspenTech.AspenPlus.Aosapfs.IAPort marshal(interface) pPort2
		) runtime managed internalcall 
	{
	} // end of method IAEditConnections::Connect

	.method public hidebysig newslot abstract virtual 
		instance void Disconnect (
			class AspenTech.AspenPlus.Aosapfs.IAConnection marshal(interface) pConn
		) runtime managed internalcall 
	{
	} // end of method IAEditConnections::Disconnect

	.method public hidebysig newslot abstract virtual 
		instance void EnumConnections (
			class AspenTech.AspenPlus.Aosapfs.IAModel marshal(interface) pModel,
			class AspenTech.AspenPlus.Aosapfs.IEnumAConnection& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IAEditConnections::EnumConnections

	.method public hidebysig newslot abstract virtual 
		instance void FindConnection (
			class AspenTech.AspenPlus.Aosapfs.IAConnection& marshal(interface) ppConn,
			class AspenTech.AspenPlus.Aosapfs.IAPort marshal(interface) pPort1,
			class AspenTech.AspenPlus.Aosapfs.IAPort marshal(interface) pPort2
		) runtime managed internalcall 
	{
	} // end of method IAEditConnections::FindConnection

} // end of class AspenTech.AspenPlus.Aosapfs.IAEditConnections

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IAEditIconSink
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 42 31 39 45 34 32 43 38 2d 37 38 38 39
		2d 31 31 44 30 2d 41 39 31 42 2d 30 30 30 30 43
		30 41 31 31 38 44 42 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void OnAddIcon () runtime managed internalcall 
	{
	} // end of method IAEditIconSink::OnAddIcon

	.method public hidebysig newslot abstract virtual 
		instance void OnRemoveIcon () runtime managed internalcall 
	{
	} // end of method IAEditIconSink::OnRemoveIcon

	.method public hidebysig newslot abstract virtual 
		instance void OnSetCurrentIcon () runtime managed internalcall 
	{
	} // end of method IAEditIconSink::OnSetCurrentIcon

} // end of class AspenTech.AspenPlus.Aosapfs.IAEditIconSink

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IASection
	implements AspenTech.AspenPlus.Aosapfs.IEnumAModel
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 43 30 37 42 33 42 45 30 2d 32 45 44 33
		2d 31 31 44 31 2d 38 39 30 30 2d 30 30 30 30 43
		30 45 37 34 39 46 38 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void Next (
			uint32 nCount,
			class AspenTech.AspenPlus.Aosapfs.IAModel& marshal(interface) ppModel,
			uint32& pnumFetched
		) runtime managed internalcall 
	{
	} // end of method IASection::Next

	.method public hidebysig newslot abstract virtual 
		instance void Skip (
			uint32 nCount
		) runtime managed internalcall 
	{
	} // end of method IASection::Skip

	.method public hidebysig newslot abstract virtual 
		instance void Reset () runtime managed internalcall 
	{
	} // end of method IASection::Reset

	.method public hidebysig newslot abstract virtual 
		instance void Clone (
			class AspenTech.AspenPlus.Aosapfs.IEnumAModel& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IASection::Clone

	.method public hidebysig newslot abstract virtual 
		instance void GetName (
			uint8& pName,
			int32 nSize
		) runtime managed internalcall 
	{
	} // end of method IASection::GetName

	.method public hidebysig newslot abstract virtual 
		instance void SetName (
			uint8& pName
		) runtime managed internalcall 
	{
	} // end of method IASection::SetName

} // end of class AspenTech.AspenPlus.Aosapfs.IASection

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IEnumASection
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 43 30 37 42 33 42 45 31 2d 32 45 44 33
		2d 31 31 44 31 2d 38 39 30 30 2d 30 30 30 30 43
		30 45 37 34 39 46 38 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void Next (
			uint32 nCount,
			class AspenTech.AspenPlus.Aosapfs.IASection& marshal(interface) ppSection,
			uint32& pnumFetched
		) runtime managed internalcall 
	{
	} // end of method IEnumASection::Next

	.method public hidebysig newslot abstract virtual 
		instance void Skip (
			uint32 nCount
		) runtime managed internalcall 
	{
	} // end of method IEnumASection::Skip

	.method public hidebysig newslot abstract virtual 
		instance void Reset () runtime managed internalcall 
	{
	} // end of method IEnumASection::Reset

	.method public hidebysig newslot abstract virtual 
		instance void Clone (
			class AspenTech.AspenPlus.Aosapfs.IEnumASection& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IEnumASection::Clone

} // end of class AspenTech.AspenPlus.Aosapfs.IEnumASection

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IAEditSections
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 43 30 37 42 33 42 45 32 2d 32 45 44 33
		2d 31 31 44 31 2d 38 39 30 30 2d 30 30 30 30 43
		30 45 37 34 39 46 38 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void AddSection (
			class AspenTech.AspenPlus.Aosapfs.IASection& marshal(interface) ppIASection,
			uint8& name
		) runtime managed internalcall 
	{
	} // end of method IAEditSections::AddSection

	.method public hidebysig newslot abstract virtual 
		instance void RemoveSection (
			class AspenTech.AspenPlus.Aosapfs.IASection marshal(interface) pSection
		) runtime managed internalcall 
	{
	} // end of method IAEditSections::RemoveSection

	.method public hidebysig newslot abstract virtual 
		instance void FindSection (
			uint8& name,
			class AspenTech.AspenPlus.Aosapfs.IASection& marshal(interface) ppSection
		) runtime managed internalcall 
	{
	} // end of method IAEditSections::FindSection

	.method public hidebysig newslot abstract virtual 
		instance void EnumSections (
			class AspenTech.AspenPlus.Aosapfs.IEnumASection& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IAEditSections::EnumSections

	.method public hidebysig newslot abstract virtual 
		instance void SetCurrentSection (
			class AspenTech.AspenPlus.Aosapfs.IASection marshal(interface) pIASection
		) runtime managed internalcall 
	{
	} // end of method IAEditSections::SetCurrentSection

	.method public hidebysig newslot abstract virtual 
		instance void GetCurrentSection (
			class AspenTech.AspenPlus.Aosapfs.IASection& marshal(interface) ppIASection
		) runtime managed internalcall 
	{
	} // end of method IAEditSections::GetCurrentSection

} // end of class AspenTech.AspenPlus.Aosapfs.IAEditSections

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IEnumACategory
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 41 38 39 42 42 31 44 31 2d 31 30 35 37
		2d 31 31 44 32 2d 38 30 45 34 2d 30 30 30 30 43
		30 39 45 46 43 46 33 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void Next (
			uint32 nCount,
			class AspenTech.AspenPlus.Aosapfs.IACategory& marshal(interface) ppCategory,
			uint32& pnumFetched
		) runtime managed internalcall 
	{
	} // end of method IEnumACategory::Next

	.method public hidebysig newslot abstract virtual 
		instance void Skip (
			uint32 nCount
		) runtime managed internalcall 
	{
	} // end of method IEnumACategory::Skip

	.method public hidebysig newslot abstract virtual 
		instance void Reset () runtime managed internalcall 
	{
	} // end of method IEnumACategory::Reset

	.method public hidebysig newslot abstract virtual 
		instance void Clone (
			class AspenTech.AspenPlus.Aosapfs.IEnumACategory& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IEnumACategory::Clone

} // end of class AspenTech.AspenPlus.Aosapfs.IEnumACategory

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IAEditCategories
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 41 38 39 42 42 31 44 32 2d 31 30 35 37
		2d 31 31 44 32 2d 38 30 45 34 2d 30 30 30 30 43
		30 39 45 46 43 46 33 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void AddCategory (
			uint8& name,
			class AspenTech.AspenPlus.Aosapfs.IACategory& marshal(interface) ppCategory
		) runtime managed internalcall 
	{
	} // end of method IAEditCategories::AddCategory

	.method public hidebysig newslot abstract virtual 
		instance void RemoveCategory (
			class AspenTech.AspenPlus.Aosapfs.IACategory marshal(interface) pCategory
		) runtime managed internalcall 
	{
	} // end of method IAEditCategories::RemoveCategory

	.method public hidebysig newslot abstract virtual 
		instance void FindCategory (
			uint8& name,
			class AspenTech.AspenPlus.Aosapfs.IACategory& marshal(interface) ppCategory
		) runtime managed internalcall 
	{
	} // end of method IAEditCategories::FindCategory

	.method public hidebysig newslot abstract virtual 
		instance void EnumCategories (
			class AspenTech.AspenPlus.Aosapfs.IEnumACategory& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IAEditCategories::EnumCategories

} // end of class AspenTech.AspenPlus.Aosapfs.IAEditCategories

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IAModel3
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 39 37 30 31 31 46 43 45 2d 36 42 38 32
		2d 34 30 34 45 2d 39 36 35 37 2d 44 31 30 39 36
		43 34 33 37 35 30 41 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void DoCopy () runtime managed internalcall 
	{
	} // end of method IAModel3::DoCopy

	.method public hidebysig newslot abstract virtual 
		instance void DoPaste () runtime managed internalcall 
	{
	} // end of method IAModel3::DoPaste

	.method public hidebysig newslot abstract virtual 
		instance int32 OnUpdatePaste () runtime managed preservesig internalcall 
	{
	} // end of method IAModel3::OnUpdatePaste

} // end of class AspenTech.AspenPlus.Aosapfs.IAModel3

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.AOSASTREAM_MODEL_MSG
	extends [mscorlib]System.ValueType
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.pack 8
	.size 0

	// Fields
	.field public uint32 dwEventCode
	.field public native int pName
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)

} // end of class AspenTech.AspenPlus.Aosapfs.AOSASTREAM_MODEL_MSG

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IABlockType
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 42 30 44 46 46 46 45 45 2d 39 30 38 43
		2d 31 31 43 45 2d 41 39 36 34 2d 30 30 30 30 43
		30 38 43 36 36 38 45 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
} // end of class AspenTech.AspenPlus.Aosapfs.IABlockType

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IAStreamType
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 42 30 44 46 46 46 45 38 2d 39 30 38 43
		2d 31 31 43 45 2d 41 39 36 34 2d 30 30 30 30 43
		30 38 43 36 36 38 45 00 00
	)
} // end of class AspenTech.AspenPlus.Aosapfs.IAStreamType

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IARootModel
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 42 37 34 38 31 41 32 30 2d 39 45 39 30
		2d 34 41 32 37 2d 42 46 38 43 2d 42 37 41 37 39
		36 37 30 46 45 45 35 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void GetRootPathName (
			uint8& pName,
			int32 size
		) runtime managed internalcall 
	{
	} // end of method IARootModel::GetRootPathName

	.method public hidebysig newslot abstract virtual 
		instance void ActivatePFSView (
			uint8& pName
		) runtime managed internalcall 
	{
	} // end of method IARootModel::ActivatePFSView

	.method public hidebysig newslot abstract virtual 
		instance void GetDynamicsExportMode (
			int32& mode
		) runtime managed internalcall 
	{
	} // end of method IARootModel::GetDynamicsExportMode

	.method public hidebysig newslot abstract virtual 
		instance void SetDynamicsExportMode (
			int32 mode
		) runtime managed internalcall 
	{
	} // end of method IARootModel::SetDynamicsExportMode

	.method public hidebysig newslot abstract virtual 
		instance void FindHierarchy (
			uint8& pName,
			class AspenTech.AspenPlus.Aosapfs.IAModel& marshal(interface) ppModel
		) runtime managed internalcall 
	{
	} // end of method IARootModel::FindHierarchy

	.method public hidebysig newslot abstract virtual 
		instance void EnumHierarchies (
			class AspenTech.AspenPlus.Aosapfs.IEnumAModel& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IARootModel::EnumHierarchies

} // end of class AspenTech.AspenPlus.Aosapfs.IARootModel

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IALoadBkpIcon
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 45 31 38 44 46 35 30 30 2d 36 37 46 39
		2d 31 31 44 30 2d 41 39 31 38 2d 30 30 30 30 43
		30 41 31 31 38 44 42 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void LoadBkpIcon (
			int32 nIconId,
			uint8& pModelName,
			class AspenTech.AspenPlus.Aosapfs.IAIcon& marshal(interface) ppIcon
		) runtime managed internalcall 
	{
	} // end of method IALoadBkpIcon::LoadBkpIcon

} // end of class AspenTech.AspenPlus.Aosapfs.IALoadBkpIcon

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IAEditControlSignal
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 34 43 42 33 36 35 39 30 2d 33 42 45 44
		2d 31 31 44 31 2d 42 31 44 37 2d 30 30 41 30 32
		34 45 35 44 46 34 31 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void Edit (
			uint32 nEnd
		) runtime managed internalcall 
	{
	} // end of method IAEditControlSignal::Edit

} // end of class AspenTech.AspenPlus.Aosapfs.IAEditControlSignal

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IAConnectorPort
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 32 36 39 31 34 41 31 42 2d 34 43 31 41
		2d 31 31 44 34 2d 39 30 37 44 2d 30 30 41 30 32
		34 35 31 42 42 39 34 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void GetConnectedStreamName (
			uint8& pName,
			int32 nSize
		) runtime managed internalcall 
	{
	} // end of method IAConnectorPort::GetConnectedStreamName

} // end of class AspenTech.AspenPlus.Aosapfs.IAConnectorPort

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IAStreamTable
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 44 31 43 45 39 35 44 46 2d 42 33 44 35
		2d 34 31 43 36 2d 41 32 45 36 2d 35 39 46 38 30
		41 38 38 43 41 42 32 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void GetData (
			native int& pData
		) runtime managed internalcall 
	{
	} // end of method IAStreamTable::GetData

	.method public hidebysig newslot abstract virtual 
		instance void SetData (
			native int pData
		) runtime managed internalcall 
	{
	} // end of method IAStreamTable::SetData

	.method public hidebysig newslot abstract virtual 
		instance void GetUpdate (
			int16& flag
		) runtime managed internalcall 
	{
	} // end of method IAStreamTable::GetUpdate

	.method public hidebysig newslot abstract virtual 
		instance void SetUpdate (
			int16 flag
		) runtime managed internalcall 
	{
	} // end of method IAStreamTable::SetUpdate

} // end of class AspenTech.AspenPlus.Aosapfs.IAStreamTable

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IEnumAStreamTable
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 44 31 43 45 39 35 45 30 2d 42 33 44 35
		2d 34 31 43 36 2d 41 32 45 36 2d 35 39 46 38 30
		41 38 38 43 41 42 32 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void Next (
			uint32 nCount,
			class AspenTech.AspenPlus.Aosapfs.IAStreamTable& marshal(interface) ppStreamTable,
			uint32& pnumFetched
		) runtime managed internalcall 
	{
	} // end of method IEnumAStreamTable::Next

	.method public hidebysig newslot abstract virtual 
		instance void Skip (
			uint32 nCount
		) runtime managed internalcall 
	{
	} // end of method IEnumAStreamTable::Skip

	.method public hidebysig newslot abstract virtual 
		instance void Reset () runtime managed internalcall 
	{
	} // end of method IEnumAStreamTable::Reset

	.method public hidebysig newslot abstract virtual 
		instance void Clone (
			class AspenTech.AspenPlus.Aosapfs.IEnumAStreamTable& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IEnumAStreamTable::Clone

} // end of class AspenTech.AspenPlus.Aosapfs.IEnumAStreamTable

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IAEditStreamTables
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 44 31 43 45 39 35 45 31 2d 42 33 44 35
		2d 34 31 43 36 2d 41 32 45 36 2d 35 39 46 38 30
		41 38 38 43 41 42 32 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void InsertStreamTable (
			class AspenTech.AspenPlus.Aosapfs.IAStreamTable& marshal(interface) ppTable,
			native int pData
		) runtime managed internalcall 
	{
	} // end of method IAEditStreamTables::InsertStreamTable

	.method public hidebysig newslot abstract virtual 
		instance void RemoveStreamTable (
			class AspenTech.AspenPlus.Aosapfs.IAStreamTable marshal(interface) pTable
		) runtime managed internalcall 
	{
	} // end of method IAEditStreamTables::RemoveStreamTable

	.method public hidebysig newslot abstract virtual 
		instance void RemoveAllStreamTables () runtime managed internalcall 
	{
	} // end of method IAEditStreamTables::RemoveAllStreamTables

	.method public hidebysig newslot abstract virtual 
		instance void EnumStreamTables (
			class AspenTech.AspenPlus.Aosapfs.IEnumAStreamTable& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IAEditStreamTables::EnumStreamTables

	.method public hidebysig newslot abstract virtual 
		instance void GetCount (
			int32& nCount
		) runtime managed internalcall 
	{
	} // end of method IAEditStreamTables::GetCount

} // end of class AspenTech.AspenPlus.Aosapfs.IAEditStreamTables

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IAPFSControl
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 45 46 42 39 36 39 35 46 2d 33 39 33 35
		2d 34 35 31 34 2d 38 41 43 44 2d 37 45 44 45 35
		43 45 32 35 30 44 45 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void BeginImport (
			[in] int32 bUseCenterPt,
			[in] valuetype AspenTech.AspenPlus.Aosapfs.POINT pt
		) runtime managed internalcall 
	{
	} // end of method IAPFSControl::BeginImport

	.method public hidebysig newslot abstract virtual 
		instance void EndImport () runtime managed internalcall 
	{
	} // end of method IAPFSControl::EndImport

	.method public hidebysig specialname newslot abstract virtual 
		instance valuetype AspenTech.AspenPlus.Aosapfs.RECT get_Viewport () runtime managed internalcall 
	{
	} // end of method IAPFSControl::get_Viewport

	.method public hidebysig specialname newslot abstract virtual 
		instance void set_Viewport (
			[in] valuetype AspenTech.AspenPlus.Aosapfs.RECT pRect
		) runtime managed internalcall 
	{
	} // end of method IAPFSControl::set_Viewport

	.method public hidebysig specialname newslot abstract virtual 
		instance valuetype AspenTech.AspenPlus.Aosapfs.RECT get_BlockPosition (
			[in] uint8& name
		) runtime managed internalcall 
	{
	} // end of method IAPFSControl::get_BlockPosition

	.method public hidebysig specialname newslot abstract virtual 
		instance void set_BlockPosition (
			[in] uint8& name,
			[in] valuetype AspenTech.AspenPlus.Aosapfs.RECT pRect
		) runtime managed internalcall 
	{
	} // end of method IAPFSControl::set_BlockPosition

	.method public hidebysig newslot abstract virtual 
		instance void ResizeBlockIcon (
			[in] uint8& name,
			[in] float32 ratio
		) runtime managed internalcall 
	{
	} // end of method IAPFSControl::ResizeBlockIcon

	.method public hidebysig newslot abstract virtual 
		instance void ExchangeBlockIcon (
			[in] uint8& name
		) runtime managed internalcall 
	{
	} // end of method IAPFSControl::ExchangeBlockIcon

	.method public hidebysig newslot abstract virtual 
		instance void RerouteStream (
			[in] uint8& name
		) runtime managed internalcall 
	{
	} // end of method IAPFSControl::RerouteStream

	.method public hidebysig newslot abstract virtual 
		instance void GetBlockPosition (
			[in] uint8& name,
			[out] float32& x,
			[out] float32& y,
			[out] float32& scale,
			[out] int32& orient
		) runtime managed internalcall 
	{
	} // end of method IAPFSControl::GetBlockPosition

	.method public hidebysig newslot abstract virtual 
		instance void SetBlockPosition (
			[in] uint8& name,
			[in] float32 x,
			[in] float32 y,
			[in] float32 scale,
			[in] int32 orient
		) runtime managed internalcall 
	{
	} // end of method IAPFSControl::SetBlockPosition

	// Properties
	.property valuetype AspenTech.AspenPlus.Aosapfs.RECT Viewport()
	{
		.custom instance void [mscorlib]System.Runtime.InteropServices.DispIdAttribute::.ctor(int32) = (
			01 00 02 00 01 60 00 00
		)
		.get instance valuetype AspenTech.AspenPlus.Aosapfs.RECT AspenTech.AspenPlus.Aosapfs.IAPFSControl::get_Viewport()
		.set instance void AspenTech.AspenPlus.Aosapfs.IAPFSControl::set_Viewport(valuetype AspenTech.AspenPlus.Aosapfs.RECT)
	}
	.property valuetype AspenTech.AspenPlus.Aosapfs.RECT BlockPosition(
		[in] uint8& name
	)
	{
		.custom instance void [mscorlib]System.Runtime.InteropServices.DispIdAttribute::.ctor(int32) = (
			01 00 04 00 01 60 00 00
		)
		.get instance valuetype AspenTech.AspenPlus.Aosapfs.RECT AspenTech.AspenPlus.Aosapfs.IAPFSControl::get_BlockPosition(uint8&)
		.set instance void AspenTech.AspenPlus.Aosapfs.IAPFSControl::set_BlockPosition(uint8&, valuetype AspenTech.AspenPlus.Aosapfs.RECT)
	}

} // end of class AspenTech.AspenPlus.Aosapfs.IAPFSControl

.class interface public auto ansi abstract import AspenTech.AspenPlus.Aosapfs.IAPFSAdviseSink
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 36 37 41 39 43 45 32 30 2d 42 30 32 34
		2d 31 31 44 30 2d 41 30 44 38 2d 30 30 30 30 43
		30 33 33 33 33 45 46 00 00
	)
	.custom instance void [mscorlib]System.Runtime.InteropServices.InterfaceTypeAttribute::.ctor(valuetype [mscorlib]System.Runtime.InteropServices.ComInterfaceType) = (
		01 00 01 00 00 00 00 00
	)
	// Methods
	.method public hidebysig newslot abstract virtual 
		instance void OnNotify (
			uint32 EventCode,
			int32 BeforeOrAfterEvent,
			native int pEventStruct,
			int32 nStructSize
		) runtime managed internalcall 
	{
	} // end of method IAPFSAdviseSink::OnNotify

	.method public hidebysig newslot abstract virtual 
		instance void GetSettings (
			uint8& pSettings,
			int32 nSize
		) runtime managed internalcall 
	{
	} // end of method IAPFSAdviseSink::GetSettings

	.method public hidebysig newslot abstract virtual 
		instance void SetSettings (
			uint8& pSettings
		) runtime managed internalcall 
	{
	} // end of method IAPFSAdviseSink::SetSettings

	.method public hidebysig newslot abstract virtual 
		instance void EnumSelectedModels (
			class AspenTech.AspenPlus.Aosapfs.IEnumAModel& marshal(interface) ppEnum
		) runtime managed internalcall 
	{
	} // end of method IAPFSAdviseSink::EnumSelectedModels

} // end of class AspenTech.AspenPlus.Aosapfs.IAPFSAdviseSink

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.AOSAEC_MODEL_MSG
	extends [mscorlib]System.ValueType
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.pack 8
	.size 0

	// Fields
	.field public marshal(interface) class AspenTech.AspenPlus.Aosapfs.IAModel pModel
	.field public native int oldName
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.field public native int newName
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)

} // end of class AspenTech.AspenPlus.Aosapfs.AOSAEC_MODEL_MSG

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.AOSAEC_CONN_MSG
	extends [mscorlib]System.ValueType
{
	.pack 8
	.size 0

	// Fields
	.field public marshal(interface) class AspenTech.AspenPlus.Aosapfs.IAConnection pConnection
	.field public marshal(interface) class AspenTech.AspenPlus.Aosapfs.IAPort pPort1
	.field public int32 nInstNumber1
	.field public marshal(interface) class AspenTech.AspenPlus.Aosapfs.IAPort pPort2
	.field public int32 nInstNumber2
	.field public marshal(interface) class AspenTech.AspenPlus.Aosapfs.IAPort pReplacedPort
	.field public int32 nReplacedInstNumber
	.field public int32 bPortReplacedWas1

} // end of class AspenTech.AspenPlus.Aosapfs.AOSAEC_CONN_MSG

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.AOSAEC_SECTION_MSG
	extends [mscorlib]System.ValueType
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.pack 8
	.size 0

	// Fields
	.field public marshal(interface) class AspenTech.AspenPlus.Aosapfs.IASection pSection
	.field public native int oldName
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.field public native int newName
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)

} // end of class AspenTech.AspenPlus.Aosapfs.AOSAEC_SECTION_MSG

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.AOSAEC_DISCONNECT_MSG
	extends [mscorlib]System.ValueType
{
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)
	.pack 8
	.size 0

	// Fields
	.field public int16 iDirection
	.field public native int StreamName
	.custom instance void [mscorlib]System.Runtime.InteropServices.ComConversionLossAttribute::.ctor() = (
		01 00 00 00
	)

} // end of class AspenTech.AspenPlus.Aosapfs.AOSAEC_DISCONNECT_MSG

.class public sequential ansi sealed beforefieldinit AspenTech.AspenPlus.Aosapfs.AOSAEC_IUNKNOWN_MSG
	extends [mscorlib]System.ValueType
{
	.pack 8
	.size 0

	// Fields
	.field public marshal(iunknown) object pUnk

} // end of class AspenTech.AspenPlus.Aosapfs.AOSAEC_IUNKNOWN_MSG

.class public auto ansi sealed AspenTech.AspenPlus.Aosapfs.PSSTATE
	extends [mscorlib]System.Enum
{
	// Fields
	.field public specialname rtspecialname int32 value__
	.field public static literal valuetype AspenTech.AspenPlus.Aosapfs.PSSTATE PSSTATE_UNINIT = int32(0)
	.field public static literal valuetype AspenTech.AspenPlus.Aosapfs.PSSTATE PSSTATE_SCRIBBLE = int32(1)
	.field public static literal valuetype AspenTech.AspenPlus.Aosapfs.PSSTATE PSSTATE_ZOMBIE = int32(2)
	.field public static literal valuetype AspenTech.AspenPlus.Aosapfs.PSSTATE PSSTATE_HANDSOFF = int32(3)

} // end of class AspenTech.AspenPlus.Aosapfs.PSSTATE

.class public auto ansi sealed AspenTech.AspenPlus.Aosapfs.IAModelCustomMethod
	extends [mscorlib]System.Enum
{
	// Fields
	.field public specialname rtspecialname int32 value__
	.field public static literal valuetype AspenTech.AspenPlus.Aosapfs.IAModelCustomMethod IAModel_HAGetAttr = int32(0)
	.field public static literal valuetype AspenTech.AspenPlus.Aosapfs.IAModelCustomMethod IAModel_HASetAttr = int32(1)
	.field public static literal valuetype AspenTech.AspenPlus.Aosapfs.IAModelCustomMethod IAModel_GetControlVarList = int32(2)
	.field public static literal valuetype AspenTech.AspenPlus.Aosapfs.IAModelCustomMethod IAModel_SetControllerVar = int32(3)
	.field public static literal valuetype AspenTech.AspenPlus.Aosapfs.IAModelCustomMethod IAModel_ClearControllerVar = int32(4)
	.field public static literal valuetype AspenTech.AspenPlus.Aosapfs.IAModelCustomMethod IAModel_IsControllerModel = int32(5)
	.field public static literal valuetype AspenTech.AspenPlus.Aosapfs.IAModelCustomMethod IAModel_GetControllerVar = int32(6)

} // end of class AspenTech.AspenPlus.Aosapfs.IAModelCustomMethod

