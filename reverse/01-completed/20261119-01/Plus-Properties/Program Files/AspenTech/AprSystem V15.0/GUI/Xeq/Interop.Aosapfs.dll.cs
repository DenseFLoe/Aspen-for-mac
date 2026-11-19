using System;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: ImportedFromTypeLib("AOSAPfs")]
[assembly: Guid("8080E641-57DE-497B-B834-ABCCB50A4CA2")]
[assembly: TypeLibVersion(5, 0)]
[assembly: AssemblyVersion("5.0.0.0")]
namespace AspenTech.AspenPlus.Aosapfs;

[ComImport]
[Guid("B19E42B1-7889-11D0-A91B-0000C0A118DB")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IEnumAModelType
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Next(uint nCount, [MarshalAs(UnmanagedType.Interface)] ref IAModelType ppModelType, ref uint pnumFetched);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Skip(uint nCount);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] ref IEnumAModelType ppEnum);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("B19E42B2-7889-11D0-A91B-0000C0A118DB")]
public interface IAModelType
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetName(ref byte pName, int nSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetName(ref byte pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetModelCategory(ref int pCategory);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsStreamType();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CreateInstance([MarshalAs(UnmanagedType.Interface)] ref IAModel ppModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetDescription(ref byte pDescription, int nSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetDescription(ref byte pDescription);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetProcessType(ref ProcessTypeRestriction pProcType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsControllerType();
}
[ComImport]
[Guid("B19E42BF-7889-11D0-A91B-0000C0A118DB")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IAModel
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetName(ref byte pName, int size);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetName(ref byte pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetParentModel([MarshalAs(UnmanagedType.Interface)] ref IAModel ppModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetParentModel([MarshalAs(UnmanagedType.Interface)] IAModel pModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetModelType([MarshalAs(UnmanagedType.Interface)] ref IAModelType ppModelType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetAnnotation(ref byte pText, int nSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetDescription(ref byte pDescription, int nSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CanChange(uint dwChangeCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CustomMethod(int nMethodId, int nMethodArg, int nDataType, IntPtr pData);
}
public enum ProcessTypeRestriction
{
	ProcessTypeNone = -1,
	ProcessTypeAny,
	ProcessTypeBatch,
	ProcessTypeContinuous
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("B19E42B3-7889-11D0-A91B-0000C0A118DB")]
public interface IAEditModelIcons
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetCurrentIcon([MarshalAs(UnmanagedType.Interface)] ref IAModelIcon ppModelIcon);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetCurrentIcon([MarshalAs(UnmanagedType.Interface)] IAModelIcon pModelIcon);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CreateIcon([MarshalAs(UnmanagedType.Interface)] ref IAModelIcon ppModelIcon, ref byte pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void AddIcon([MarshalAs(UnmanagedType.Interface)] IAModelIcon pModelIcon);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoveIcon([MarshalAs(UnmanagedType.Interface)] IAModelIcon pModelIcon);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void FindIcon(ref byte pName, [MarshalAs(UnmanagedType.Interface)] ref IAModelIcon ppModelIcon);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnumIcons([MarshalAs(UnmanagedType.Interface)] ref IEnumAModelIcon ppEnum);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetLineStyle(ref AOSALINESTYLE pLineStyle);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetLineStyle(ref AOSALINESTYLE pLineStyle);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("B19E42B7-7889-11D0-A91B-0000C0A118DB")]
[ComConversionLoss]
public interface IAModelIcon
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetName(ref byte pName, int size);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetName(ref byte pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetModel([MarshalAs(UnmanagedType.Interface)] ref IAModel ppModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetModel([MarshalAs(UnmanagedType.Interface)] IAModel pModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetIcon([MarshalAs(UnmanagedType.Interface)] ref IAIcon ppIcon);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetIcon([MarshalAs(UnmanagedType.Interface)] IAIcon pIcon);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Connect([MarshalAs(UnmanagedType.Interface)] IAIconPort pIconPort, IntPtr location);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Draw([ComAliasName("AspenTech.AspenPlus.Aosapfs.wireHDC")] ref RemotableHandle hDC, ref RECT pRect, int mode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void HasContents(ref int bNonEmpty);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetSize(ref double pleft, ref double ptop, ref double pright, ref double pbottom);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetLabelPosition(ref double px, ref double py);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetClipRegion([ComAliasName("AspenTech.AspenPlus.Aosapfs.wireHDC")] ref RemotableHandle hDC, ref RECT pRect, [ComAliasName("AspenTech.AspenPlus.Aosapfs.wireHRGN")] IntPtr pClipRegion, int modifier);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetUniversalPorts([MarshalAs(UnmanagedType.Interface)] ref IAIconPort ppInPort, [MarshalAs(UnmanagedType.Interface)] ref IAIconPort ppOutPort);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetPortMap([MarshalAs(UnmanagedType.Interface)] IAPort pPort, [MarshalAs(UnmanagedType.Interface)] IAIconPort pIconPort);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetPortMapByIndex(int modelIndex, int iconIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemovePortMap([MarshalAs(UnmanagedType.Interface)] IAPort pPort);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetPortFromMap([MarshalAs(UnmanagedType.Interface)] IAIconPort pIconPort, [MarshalAs(UnmanagedType.Interface)] ref IAPort ppModelPort);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetIconPortFromMap([MarshalAs(UnmanagedType.Interface)] IAPort pModelPort, [MarshalAs(UnmanagedType.Interface)] ref IAIconPort ppIconPort);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetVariable([MarshalAs(UnmanagedType.Interface)] IAModel pModel, ref byte pVarName, ref byte pValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsDerivedIcon(ref int bDerived);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void MapR9Ports();
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("B19E42B4-7889-11D0-A91B-0000C0A118DB")]
public interface IEnumAModelIcon
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Next(uint nCount, [MarshalAs(UnmanagedType.Interface)] ref IAModelIcon ppModelIcon, ref uint pnumFetched);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Skip(uint nCount);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] ref IEnumAModelIcon ppEnum);
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
[ComConversionLoss]
public struct AOSALINESTYLE
{
	public uint dwPenStyle;

	public uint dwWidth;

	public LOGBRUSH LOGBRUSH;

	public uint dwStyleCount;

	[ComConversionLoss]
	public IntPtr lpStyle;

	public AOSA_ARROWTYPE nArrowType;

	public int bHideLabels;

	[MarshalAs(UnmanagedType.ByValArray, SizeConst = 10)]
	public byte[] szTerminatorID;
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("B19E42B9-7889-11D0-A91B-0000C0A118DB")]
[ComConversionLoss]
public interface IAIcon
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetName(ref byte pName, int size);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetName(ref byte pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetupIcon(ref byte pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void MapPorts([MarshalAs(UnmanagedType.Interface)] IAModelIcon pModelIcon);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetSize(ref double pleft, ref double ptop, ref double pright, ref double pbottom);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetLabelPosition(ref double px, ref double py);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetClipRegion([ComAliasName("AspenTech.AspenPlus.Aosapfs.wireHDC")] ref RemotableHandle hDC, ref RECT pRect, [ComAliasName("AspenTech.AspenPlus.Aosapfs.wireHRGN")] IntPtr pClipRegion, int modifier);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void AttachPort([MarshalAs(UnmanagedType.Interface)] IAIconPort pPort);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetUniversalPorts([MarshalAs(UnmanagedType.Interface)] ref IAIconPort pInPort, [MarshalAs(UnmanagedType.Interface)] ref IAIconPort pOutPort);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Draw([ComAliasName("AspenTech.AspenPlus.Aosapfs.wireHDC")] ref RemotableHandle hDC, ref RECT pRect, int mode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Connect([MarshalAs(UnmanagedType.Interface)] IAIconPort pIconPort, IntPtr location, [MarshalAs(UnmanagedType.Interface)] IAModelIcon pModelIcon);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void HasContents(ref int bNonEmpty);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetVariable([MarshalAs(UnmanagedType.Interface)] IAModel pModel, ref byte pVarName, ref byte pValue, [MarshalAs(UnmanagedType.Interface)] IAModelIcon pModelIcon);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsDerivedIcon(ref int bDerived);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void AddIconPort(ref byte name, [MarshalAs(UnmanagedType.Interface)] ref IAIconPort ppPort);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoveIconPort([MarshalAs(UnmanagedType.Interface)] IAIconPort pPort);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void FindIconPort(ref byte name, [MarshalAs(UnmanagedType.Interface)] ref IAIconPort ppPort);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnumIconPorts([MarshalAs(UnmanagedType.Interface)] ref IEnumAIconPort ppEnum);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("B19E42BC-7889-11D0-A91B-0000C0A118DB")]
public interface IAIconPort
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetName(ref byte pName, int nSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetPos(ref byte x, ref byte y);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetAttrib(int Attrib);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetAttrib(ref int pAttrib);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetLocation(double x, double y);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetLocation(ref double px, ref double py);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetDirection(ref POINT pdirection, int modifier);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetSensitiveRegion(ref POINT pPoint, ref RECT pregion, int modifier);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Draw([ComAliasName("AspenTech.AspenPlus.Aosapfs.wireHDC")] ref RemotableHandle hDC, ref POINT pPoint, int mode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Highlight([ComAliasName("AspenTech.AspenPlus.Aosapfs.wireHWND")] ref RemotableHandle hWnd, [ComAliasName("AspenTech.AspenPlus.Aosapfs.wireHDC")] ref RemotableHandle hDC, ref POINT pPoint, int mode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CompareInstance([MarshalAs(UnmanagedType.IUnknown)] object pUnk);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetName(ref byte pName);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct RemotableHandle
{
	public int fContext;

	public __MIDL_IWinTypes_0009 u;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct RECT
{
	public int left;

	public int top;

	public int right;

	public int bottom;
}
[ComImport]
[Guid("B19E42B8-7889-11D0-A91B-0000C0A118DB")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IAPort
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetModel([MarshalAs(UnmanagedType.Interface)] ref IAModel ppModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetModel([MarshalAs(UnmanagedType.Interface)] IAModel pModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetName(ref byte pName, int nSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetName(ref byte pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetSexAndDirection(ref int pFlags);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CanConnect([MarshalAs(UnmanagedType.Interface)] IAPort pPort);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Connect([MarshalAs(UnmanagedType.Interface)] IAPort pPort, ref int pInstance);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Disconnect(int Instance);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsSame([MarshalAs(UnmanagedType.Interface)] IAPort pPort);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsRequired();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetDescription(ref byte pDescription, int nSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsCharge();
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("B19E42BB-7889-11D0-A91B-0000C0A118DB")]
public interface IEnumAIconPort
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Next(uint nCount, [MarshalAs(UnmanagedType.Interface)] ref IAIconPort ppIconPort, ref uint pnumFetched);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Skip(uint nCount);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] ref IEnumAIconPort ppEnum);
}
[StructLayout(LayoutKind.Explicit, Pack = 4, Size = 4)]
public struct __MIDL_IWinTypes_0009
{
	[FieldOffset(0)]
	public int hInproc;

	[FieldOffset(0)]
	public int hRemote;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct POINT
{
	public int x;

	public int y;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct LOGBRUSH
{
	public uint lbStyle;

	public uint lbColor;

	public int lbHatch;
}
public enum AOSA_ARROWTYPE
{
	AOSA_ARROW_NONE = 1,
	AOSA_ARROW_SOLID
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("B19E42B5-7889-11D0-A91B-0000C0A118DB")]
public interface IAEditPorts
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void AddPort([MarshalAs(UnmanagedType.Interface)] ref IAPort ppPort, ref byte name, [MarshalAs(UnmanagedType.Interface)] IAPortType pPortType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void InsertPort([MarshalAs(UnmanagedType.Interface)] IAPort pPort);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemovePort([MarshalAs(UnmanagedType.Interface)] IAPort pPort);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void FindPort(ref byte name, [MarshalAs(UnmanagedType.Interface)] ref IAPort ppPort);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnumPorts(int sexdir, [MarshalAs(UnmanagedType.Interface)] ref IEnumAPort ppEnum);
}
[ComImport]
[Guid("0EFB7340-5847-11D0-A914-0000C0A118DB")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IAPortType
{
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("B19E42B6-7889-11D0-A91B-0000C0A118DB")]
public interface IEnumAPort
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Next(uint nCount, [MarshalAs(UnmanagedType.Interface)] ref IAPort ppPort, ref uint pnumFetched);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Skip(uint nCount);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] ref IEnumAPort ppEnum);
}
[ComImport]
[Guid("53C44730-E514-11D1-A4DE-00104B214242")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IAIcon2
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetRangeCount(ref int count);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetRange(int index, ref double pleft, ref double ptop, ref double pright, ref double pbottom);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void DXFOut([MarshalAs(UnmanagedType.Interface)] IStream pStream);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetModified(int bModified);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("0C733A30-2A1C-11CE-ADE5-00AA0044773D")]
public interface ISequentialStream
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoteRead(out byte pv, [In] uint cb, out uint pcbRead);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoteWrite([In] ref byte pv, [In] uint cb, out uint pcbWritten);
}
[ComImport]
[Guid("0000000C-0000-0000-C000-000000000046")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IStream : ISequentialStream
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void RemoteRead(out byte pv, [In] uint cb, out uint pcbRead);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void RemoteWrite([In] ref byte pv, [In] uint cb, out uint pcbWritten);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoteSeek([In] LARGE_INTEGER dlibMove, [In] uint dwOrigin, out ULARGE_INTEGER plibNewPosition);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetSize([In] ULARGE_INTEGER libNewSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoteCopyTo([In][MarshalAs(UnmanagedType.Interface)] IStream pstm, [In] ULARGE_INTEGER cb, out ULARGE_INTEGER pcbRead, out ULARGE_INTEGER pcbWritten);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Commit([In] uint grfCommitFlags);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Revert();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void LockRegion([In] ULARGE_INTEGER libOffset, [In] ULARGE_INTEGER cb, [In] uint dwLockType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void UnlockRegion([In] ULARGE_INTEGER libOffset, [In] ULARGE_INTEGER cb, [In] uint dwLockType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Stat(out STATSTG pstatstg, [In] uint grfStatFlag);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] out IStream ppstm);
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
public struct LARGE_INTEGER
{
	public long QuadPart;
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
public struct ULARGE_INTEGER
{
	public ulong QuadPart;
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
public struct STATSTG
{
	[MarshalAs(UnmanagedType.LPWStr)]
	public string pwcsName;

	public uint type;

	public ULARGE_INTEGER cbSize;

	public FILETIME mtime;

	public FILETIME ctime;

	public FILETIME atime;

	public uint grfMode;

	public uint grfLocksSupported;

	public Guid clsid;

	public uint grfStateBits;

	public uint reserved;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct FILETIME
{
	public uint dwLowDateTime;

	public uint dwHighDateTime;
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("B19E42BA-7889-11D0-A91B-0000C0A118DB")]
public interface IASblIcon
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetScriptSize(ref int pSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetScript(ref byte pScript, int size);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetScript(ref byte pScript);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("B19E42BD-7889-11D0-A91B-0000C0A118DB")]
public interface IAIconLibrary
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void LoadR9Icon(ref byte pFileName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Edit();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void FindIcon(ref byte pName, [MarshalAs(UnmanagedType.Interface)] ref IAIcon ppIcon);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnumIcons([MarshalAs(UnmanagedType.Interface)] ref IEnumAIcon ppEnum);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetComment(ref byte pName, ref byte pComment, int size);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("B19E42BE-7889-11D0-A91B-0000C0A118DB")]
public interface IEnumAIcon
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Next(uint nCount, [MarshalAs(UnmanagedType.Interface)] ref IAIcon ppIcon, ref uint pnumFetched);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Skip(uint nCount);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] ref IEnumAIcon ppEnum);
}
[ComImport]
[Guid("AADE2880-05AC-11D4-8E4F-00C04F298756")]
[ComConversionLoss]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IAModel2
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetDisplayName(ref byte pName, int size);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetDisplayName(ref byte pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsVisible();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnumMultiSelectVerbs(int flags, [MarshalAs(UnmanagedType.Interface)] ref IEnumOLEVERB ppEnumOleVerb);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void DoMultiSelectVerb(int iVerb, ref MSG lpmsg);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void QuerySetData(ref FORMATETC pformatetc);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetData(ref FORMATETC pformatetc, [ComAliasName("AspenTech.AspenPlus.Aosapfs.wireSTGMEDIUM")] IntPtr pmedium, int fRelease);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void TransferDataObject([MarshalAs(UnmanagedType.Interface)] IDataObject pDataObject);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ImportModelType([MarshalAs(UnmanagedType.Interface)] IAModelType pModelType);
}
[ComImport]
[Guid("00000104-0000-0000-C000-000000000046")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IEnumOLEVERB
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoteNext([In] uint celt, out OLEVERB rgelt, out uint pceltFetched);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Skip([In] uint celt);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] out IEnumOLEVERB ppEnum);
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
public struct MSG
{
	[ComAliasName("AspenTech.AspenPlus.Aosapfs.wireHWND")]
	public IntPtr hWnd;

	public uint message;

	[ComAliasName("AspenTech.AspenPlus.Aosapfs.UINT_PTR")]
	public ulong wParam;

	[ComAliasName("AspenTech.AspenPlus.Aosapfs.LONG_PTR")]
	public long lParam;

	public uint time;

	public POINT pt;
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
[ComConversionLoss]
public struct FORMATETC
{
	[ComAliasName("AspenTech.AspenPlus.Aosapfs.wireCLIPFORMAT")]
	public IntPtr cfFormat;

	[ComConversionLoss]
	public IntPtr ptd;

	public uint dwAspect;

	public int lindex;

	public uint tymed;
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
public struct userSTGMEDIUM
{
	public _STGMEDIUM_UNION DUMMYUNIONNAME;

	[MarshalAs(UnmanagedType.IUnknown)]
	public object pUnkForRelease;
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("0000010E-0000-0000-C000-000000000046")]
[ComConversionLoss]
public interface IDataObject
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoteGetData([In] ref FORMATETC pformatetcIn, [Out][ComAliasName("AspenTech.AspenPlus.Aosapfs.wireSTGMEDIUM")] IntPtr pRemoteMedium);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoteGetDataHere([In] ref FORMATETC pformatetc, [In][Out][ComAliasName("AspenTech.AspenPlus.Aosapfs.wireSTGMEDIUM")] IntPtr pRemoteMedium);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void QueryGetData([In] ref FORMATETC pformatetc);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetCanonicalFormatEtc([In] ref FORMATETC pformatectIn, out FORMATETC pformatetcOut);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoteSetData([In] ref FORMATETC pformatetc, [In][ComAliasName("AspenTech.AspenPlus.Aosapfs.wireFLAG_STGMEDIUM")] IntPtr pmedium, [In] int fRelease);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnumFormatEtc([In] uint dwDirection, [MarshalAs(UnmanagedType.Interface)] out IEnumFORMATETC ppenumFormatEtc);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void DAdvise([In] ref FORMATETC pformatetc, [In] uint advf, [In][MarshalAs(UnmanagedType.Interface)] IAdviseSink pAdvSink, out uint pdwConnection);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void DUnadvise([In] uint dwConnection);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnumDAdvise([MarshalAs(UnmanagedType.Interface)] out IEnumSTATDATA ppenumAdvise);
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
public struct OLEVERB
{
	public int lVerb;

	[MarshalAs(UnmanagedType.LPWStr)]
	public string lpszVerbName;

	public uint fuFlags;

	public uint grfAttribs;
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
public struct userCLIPFORMAT
{
	public int fContext;

	public __MIDL_IWinTypes_0001 u;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct DVTARGETDEVICE
{
	public uint tdSize;

	public ushort tdDriverNameOffset;

	public ushort tdDeviceNameOffset;

	public ushort tdPortNameOffset;

	public ushort tdExtDevmodeOffset;

	[ComConversionLoss]
	public IntPtr tdData;
}
[StructLayout(LayoutKind.Explicit, Pack = 8, Size = 8)]
[ComConversionLoss]
public struct __MIDL_IWinTypes_0001
{
	[FieldOffset(0)]
	public uint dwValue;
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
public struct _STGMEDIUM_UNION
{
	public uint tymed;

	public __MIDL_IAdviseSink_0003 u;
}
[StructLayout(LayoutKind.Explicit, Pack = 8, Size = 8)]
[ComConversionLoss]
public struct __MIDL_IAdviseSink_0003
{
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
public struct userHMETAFILEPICT
{
	public int fContext;

	public __MIDL_IWinTypes_0005 u;
}
[StructLayout(LayoutKind.Explicit, Pack = 8, Size = 8)]
[ComConversionLoss]
public struct __MIDL_IWinTypes_0005
{
	[FieldOffset(0)]
	public int hInproc;

	[FieldOffset(0)]
	public long hInproc64;
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
[ComConversionLoss]
public struct remoteMETAFILEPICT
{
	public int mm;

	public int xExt;

	public int yExt;

	[ComConversionLoss]
	public IntPtr hMF;
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
public struct userHMETAFILE
{
	public int fContext;

	public __MIDL_IWinTypes_0004 u;
}
[StructLayout(LayoutKind.Explicit, Pack = 8, Size = 8)]
[ComConversionLoss]
public struct __MIDL_IWinTypes_0004
{
	[FieldOffset(0)]
	public int hInproc;

	[FieldOffset(0)]
	public long hInproc64;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct BYTE_BLOB
{
	public uint clSize;

	[ComConversionLoss]
	public IntPtr abData;
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
public struct userHENHMETAFILE
{
	public int fContext;

	public __MIDL_IWinTypes_0006 u;
}
[StructLayout(LayoutKind.Explicit, Pack = 8, Size = 8)]
[ComConversionLoss]
public struct __MIDL_IWinTypes_0006
{
	[FieldOffset(0)]
	public int hInproc;

	[FieldOffset(0)]
	public long hInproc64;
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
public struct GDI_OBJECT
{
	public uint ObjectType;

	public __MIDL_IAdviseSink_0002 u;
}
[StructLayout(LayoutKind.Explicit, Pack = 8, Size = 8)]
[ComConversionLoss]
public struct __MIDL_IAdviseSink_0002
{
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
public struct userHBITMAP
{
	public int fContext;

	public __MIDL_IWinTypes_0007 u;
}
[StructLayout(LayoutKind.Explicit, Pack = 8, Size = 8)]
[ComConversionLoss]
public struct __MIDL_IWinTypes_0007
{
	[FieldOffset(0)]
	public int hInproc;

	[FieldOffset(0)]
	public long hInproc64;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct userBITMAP
{
	public int bmType;

	public int bmWidth;

	public int bmHeight;

	public int bmWidthBytes;

	public ushort bmPlanes;

	public ushort bmBitsPixel;

	public uint cbSize;

	[ComConversionLoss]
	public IntPtr pBuffer;
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
public struct userHPALETTE
{
	public int fContext;

	public __MIDL_IWinTypes_0008 u;
}
[StructLayout(LayoutKind.Explicit, Pack = 8, Size = 8)]
[ComConversionLoss]
public struct __MIDL_IWinTypes_0008
{
	[FieldOffset(0)]
	public int hInproc;

	[FieldOffset(0)]
	public long hInproc64;
}
[StructLayout(LayoutKind.Sequential, Pack = 2)]
[ComConversionLoss]
public struct LOGPALETTE
{
	public ushort palVersion;

	public ushort palNumEntries;

	[ComConversionLoss]
	public IntPtr palPalEntry;
}
[StructLayout(LayoutKind.Sequential, Pack = 1)]
public struct PALETTEENTRY
{
	public byte peRed;

	public byte peGreen;

	public byte peBlue;

	public byte peFlags;
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
public struct userHGLOBAL
{
	public int fContext;

	public __MIDL_IWinTypes_0003 u;
}
[StructLayout(LayoutKind.Explicit, Pack = 8, Size = 8)]
[ComConversionLoss]
public struct __MIDL_IWinTypes_0003
{
	[FieldOffset(0)]
	public int hInproc;

	[FieldOffset(0)]
	public long hInproc64;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct FLAGGED_BYTE_BLOB
{
	public uint fFlags;

	public uint clSize;

	[ComConversionLoss]
	public IntPtr abData;
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
public struct userFLAG_STGMEDIUM
{
	public int ContextFlags;

	public int fPassOwnership;

	public userSTGMEDIUM Stgmed;
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("00000103-0000-0000-C000-000000000046")]
public interface IEnumFORMATETC
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoteNext([In] uint celt, out FORMATETC rgelt, out uint pceltFetched);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Skip([In] uint celt);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] out IEnumFORMATETC ppEnum);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[ComConversionLoss]
[Guid("0000010F-0000-0000-C000-000000000046")]
public interface IAdviseSink
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoteOnDataChange([In] ref FORMATETC pformatetc, [In][ComAliasName("AspenTech.AspenPlus.Aosapfs.wireASYNC_STGMEDIUM")] IntPtr pStgmed);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoteOnViewChange([In] uint dwAspect, [In] int lindex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoteOnRename([In][MarshalAs(UnmanagedType.Interface)] IMoniker pmk);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoteOnSave();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoteOnClose();
}
[ComImport]
[Guid("00000105-0000-0000-C000-000000000046")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IEnumSTATDATA
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoteNext([In] uint celt, out STATDATA rgelt, out uint pceltFetched);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Skip([In] uint celt);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] out IEnumSTATDATA ppEnum);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("0000010C-0000-0000-C000-000000000046")]
public interface IPersist
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetClassID(out Guid pClassID);
}
[ComImport]
[Guid("00000109-0000-0000-C000-000000000046")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IPersistStream : IPersist
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetClassID(out Guid pClassID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsDirty();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Load([In][MarshalAs(UnmanagedType.Interface)] IStream pstm);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Save([In][MarshalAs(UnmanagedType.Interface)] IStream pstm, [In] int fClearDirty);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetSizeMax(out ULARGE_INTEGER pcbSize);
}
[ComImport]
[Guid("0000000F-0000-0000-C000-000000000046")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IMoniker : IPersistStream
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetClassID(out Guid pClassID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void IsDirty();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void Load([In][MarshalAs(UnmanagedType.Interface)] IStream pstm);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void Save([In][MarshalAs(UnmanagedType.Interface)] IStream pstm, [In] int fClearDirty);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetSizeMax(out ULARGE_INTEGER pcbSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoteBindToObject([In][MarshalAs(UnmanagedType.Interface)] IBindCtx pbc, [In][MarshalAs(UnmanagedType.Interface)] IMoniker pmkToLeft, [In] ref Guid riidResult, [MarshalAs(UnmanagedType.IUnknown)] out object ppvResult);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoteBindToStorage([In][MarshalAs(UnmanagedType.Interface)] IBindCtx pbc, [In][MarshalAs(UnmanagedType.Interface)] IMoniker pmkToLeft, [In] ref Guid riid, [MarshalAs(UnmanagedType.IUnknown)] out object ppvObj);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Reduce([In][MarshalAs(UnmanagedType.Interface)] IBindCtx pbc, [In] uint dwReduceHowFar, [In][Out][MarshalAs(UnmanagedType.Interface)] ref IMoniker ppmkToLeft, [MarshalAs(UnmanagedType.Interface)] out IMoniker ppmkReduced);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ComposeWith([In][MarshalAs(UnmanagedType.Interface)] IMoniker pmkRight, [In] int fOnlyIfNotGeneric, [MarshalAs(UnmanagedType.Interface)] out IMoniker ppmkComposite);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Enum([In] int fForward, [MarshalAs(UnmanagedType.Interface)] out IEnumMoniker ppenumMoniker);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsEqual([In][MarshalAs(UnmanagedType.Interface)] IMoniker pmkOtherMoniker);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Hash(out uint pdwHash);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsRunning([In][MarshalAs(UnmanagedType.Interface)] IBindCtx pbc, [In][MarshalAs(UnmanagedType.Interface)] IMoniker pmkToLeft, [In][MarshalAs(UnmanagedType.Interface)] IMoniker pmkNewlyRunning);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetTimeOfLastChange([In][MarshalAs(UnmanagedType.Interface)] IBindCtx pbc, [In][MarshalAs(UnmanagedType.Interface)] IMoniker pmkToLeft, out FILETIME pfiletime);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Inverse([MarshalAs(UnmanagedType.Interface)] out IMoniker ppmk);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CommonPrefixWith([In][MarshalAs(UnmanagedType.Interface)] IMoniker pmkOther, [MarshalAs(UnmanagedType.Interface)] out IMoniker ppmkPrefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RelativePathTo([In][MarshalAs(UnmanagedType.Interface)] IMoniker pmkOther, [MarshalAs(UnmanagedType.Interface)] out IMoniker ppmkRelPath);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetDisplayName([In][MarshalAs(UnmanagedType.Interface)] IBindCtx pbc, [In][MarshalAs(UnmanagedType.Interface)] IMoniker pmkToLeft, [MarshalAs(UnmanagedType.LPWStr)] out string ppszDisplayName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ParseDisplayName([In][MarshalAs(UnmanagedType.Interface)] IBindCtx pbc, [In][MarshalAs(UnmanagedType.Interface)] IMoniker pmkToLeft, [In][MarshalAs(UnmanagedType.LPWStr)] string pszDisplayName, out uint pchEaten, [MarshalAs(UnmanagedType.Interface)] out IMoniker ppmkOut);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsSystemMoniker(out uint pdwMksys);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("0000000E-0000-0000-C000-000000000046")]
public interface IBindCtx
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RegisterObjectBound([In][MarshalAs(UnmanagedType.IUnknown)] object pUnk);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RevokeObjectBound([In][MarshalAs(UnmanagedType.IUnknown)] object pUnk);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReleaseBoundObjects();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoteSetBindOptions([In] ref BIND_OPTS2 pbindopts);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoteGetBindOptions([In][Out] ref BIND_OPTS2 pbindopts);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetRunningObjectTable([MarshalAs(UnmanagedType.Interface)] out IRunningObjectTable pprot);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RegisterObjectParam([In][MarshalAs(UnmanagedType.LPWStr)] string pszKey, [In][MarshalAs(UnmanagedType.IUnknown)] object pUnk);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetObjectParam([In][MarshalAs(UnmanagedType.LPWStr)] string pszKey, [MarshalAs(UnmanagedType.IUnknown)] out object ppunk);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnumObjectParam([MarshalAs(UnmanagedType.Interface)] out IEnumString ppEnum);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RevokeObjectParam([In][MarshalAs(UnmanagedType.LPWStr)] string pszKey);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("00000102-0000-0000-C000-000000000046")]
public interface IEnumMoniker
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoteNext([In] uint celt, [MarshalAs(UnmanagedType.Interface)] out IMoniker rgelt, out uint pceltFetched);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Skip([In] uint celt);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] out IEnumMoniker ppEnum);
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
[ComConversionLoss]
public struct BIND_OPTS2
{
	public uint cbStruct;

	public uint grfFlags;

	public uint grfMode;

	public uint dwTickCountDeadline;

	public uint dwTrackFlags;

	public uint dwClassContext;

	public uint locale;

	[ComConversionLoss]
	public IntPtr pServerInfo;
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("00000010-0000-0000-C000-000000000046")]
public interface IRunningObjectTable
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Register([In] uint grfFlags, [In][MarshalAs(UnmanagedType.IUnknown)] object punkObject, [In][MarshalAs(UnmanagedType.Interface)] IMoniker pmkObjectName, out uint pdwRegister);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Revoke([In] uint dwRegister);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsRunning([In][MarshalAs(UnmanagedType.Interface)] IMoniker pmkObjectName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetObject([In][MarshalAs(UnmanagedType.Interface)] IMoniker pmkObjectName, [MarshalAs(UnmanagedType.IUnknown)] out object ppunkObject);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void NoteChangeTime([In] uint dwRegister, [In] ref FILETIME pfiletime);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetTimeOfLastChange([In][MarshalAs(UnmanagedType.Interface)] IMoniker pmkObjectName, out FILETIME pfiletime);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnumRunning([MarshalAs(UnmanagedType.Interface)] out IEnumMoniker ppenumMoniker);
}
[ComImport]
[Guid("00000101-0000-0000-C000-000000000046")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IEnumString
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoteNext([In] uint celt, [MarshalAs(UnmanagedType.LPWStr)] out string rgelt, out uint pceltFetched);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Skip([In] uint celt);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] out IEnumString ppEnum);
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
[ComConversionLoss]
public struct COSERVERINFO
{
	public uint dwReserved1;

	[MarshalAs(UnmanagedType.LPWStr)]
	public string pwszName;

	[ComConversionLoss]
	public IntPtr pAuthInfo;

	public uint dwReserved2;
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
[ComConversionLoss]
public struct COAUTHINFO
{
	public uint dwAuthnSvc;

	public uint dwAuthzSvc;

	[MarshalAs(UnmanagedType.LPWStr)]
	public string pwszServerPrincName;

	public uint dwAuthnLevel;

	public uint dwImpersonationLevel;

	[ComConversionLoss]
	public IntPtr pAuthIdentityData;

	public uint dwCapabilities;
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
[ComConversionLoss]
public struct COAUTHIDENTITY
{
	[ComConversionLoss]
	public IntPtr User;

	public uint UserLength;

	[ComConversionLoss]
	public IntPtr Domain;

	public uint DomainLength;

	[ComConversionLoss]
	public IntPtr Password;

	public uint PasswordLength;

	public uint flags;
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
public struct STATDATA
{
	public FORMATETC FORMATETC;

	public uint advf;

	[MarshalAs(UnmanagedType.Interface)]
	public IAdviseSink pAdvSink;

	public uint dwConnection;
}
[ComImport]
[Guid("B19E42C0-7889-11D0-A91B-0000C0A118DB")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IEnumAModel
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Next(uint nCount, [MarshalAs(UnmanagedType.Interface)] ref IAModel ppModel, ref uint pnumFetched);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Skip(uint nCount);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] ref IEnumAModel ppEnum);
}
[ComImport]
[Guid("B19E42C6-7889-11D0-A91B-0000C0A118DB")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IAEditModels
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetModelLibrary([MarshalAs(UnmanagedType.Interface)] ref IAModelLibrary2 ppModelLibrary);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetModelLibrary([MarshalAs(UnmanagedType.Interface)] IAModelLibrary2 pModelLibrary);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void AddModel([MarshalAs(UnmanagedType.Interface)] ref IAModel ppModel, ref byte pName, [MarshalAs(UnmanagedType.Interface)] IAModelType pModelType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoveModel([MarshalAs(UnmanagedType.Interface)] IAModel pModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void FindModel(ref byte pName, [MarshalAs(UnmanagedType.Interface)] ref IAModel ppModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnumModels([MarshalAs(UnmanagedType.Interface)] ref IEnumAModel ppEnum);
}
[ComImport]
[Guid("A89BB1D0-1057-11D2-80E4-0000C09EFCF3")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IACategory
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetName(ref byte pName, int nSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetName(ref byte pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void AddModelType([MarshalAs(UnmanagedType.Interface)] IAModelType pModelType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoveModelType([MarshalAs(UnmanagedType.Interface)] IAModelType pModelType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void FindModelType(ref byte pName, [MarshalAs(UnmanagedType.Interface)] ref IAModelType ppModelType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnumModelType([MarshalAs(UnmanagedType.Interface)] ref IEnumAModelType ppEnum);
}
[ComImport]
[Guid("B19E42B0-7889-11D0-A91B-0000C0A118DB")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IAModelLibrary2 : IACategory
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetName(ref byte pName, int nSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void SetName(ref byte pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void AddModelType([MarshalAs(UnmanagedType.Interface)] IAModelType pModelType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void RemoveModelType([MarshalAs(UnmanagedType.Interface)] IAModelType pModelType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void FindModelType(ref byte pName, [MarshalAs(UnmanagedType.Interface)] ref IAModelType ppModelType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void EnumModelType([MarshalAs(UnmanagedType.Interface)] ref IEnumAModelType ppEnum);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetIconLibrary([MarshalAs(UnmanagedType.Interface)] ref IAIconLibrary ppIconLib);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetIconLibrary([MarshalAs(UnmanagedType.Interface)] IAIconLibrary pIconLib);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("B19E42C1-7889-11D0-A91B-0000C0A118DB")]
public interface IAEditBlocks
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void AddBlock([MarshalAs(UnmanagedType.Interface)] ref IAModel ppModel, ref byte pName, [MarshalAs(UnmanagedType.Interface)] IAModelType pModelType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoveBlock([MarshalAs(UnmanagedType.Interface)] IAModel pModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void FindBlock(ref byte pName, [MarshalAs(UnmanagedType.Interface)] ref IAModel ppModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnumBlocks([MarshalAs(UnmanagedType.Interface)] ref IEnumAModel ppEnum);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("B19E42C2-7889-11D0-A91B-0000C0A118DB")]
public interface IAEditStreams
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void AddStream([MarshalAs(UnmanagedType.Interface)] ref IAModel ppModel, ref byte pName, [MarshalAs(UnmanagedType.Interface)] IAModelType pModelType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoveStream([MarshalAs(UnmanagedType.Interface)] IAModel pModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void FindStream(ref byte pName, [MarshalAs(UnmanagedType.Interface)] ref IAModel ppModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnumStreams([MarshalAs(UnmanagedType.Interface)] ref IEnumAModel ppEnum);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("B19E42C3-7889-11D0-A91B-0000C0A118DB")]
public interface IAConnection
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetPort1([MarshalAs(UnmanagedType.Interface)] ref IAPort ppPort, ref int pInstanceNumber);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetPort2([MarshalAs(UnmanagedType.Interface)] ref IAPort ppPort, ref int pInstanceNumber);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Disconnect();
}
[ComImport]
[Guid("B19E42C4-7889-11D0-A91B-0000C0A118DB")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IEnumAConnection
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Next(uint nCount, [MarshalAs(UnmanagedType.Interface)] ref IAConnection ppConn, ref uint pnumFetched);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Skip(uint nCount);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] ref IEnumAConnection ppEnum);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("B19E42C5-7889-11D0-A91B-0000C0A118DB")]
public interface IAEditConnections
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Connect([MarshalAs(UnmanagedType.Interface)] ref IAConnection ppConn, [MarshalAs(UnmanagedType.Interface)] IAPort pPort1, [MarshalAs(UnmanagedType.Interface)] IAPort pPort2);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Disconnect([MarshalAs(UnmanagedType.Interface)] IAConnection pConn);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnumConnections([MarshalAs(UnmanagedType.Interface)] IAModel pModel, [MarshalAs(UnmanagedType.Interface)] ref IEnumAConnection ppEnum);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void FindConnection([MarshalAs(UnmanagedType.Interface)] ref IAConnection ppConn, [MarshalAs(UnmanagedType.Interface)] IAPort pPort1, [MarshalAs(UnmanagedType.Interface)] IAPort pPort2);
}
[ComImport]
[Guid("B19E42C8-7889-11D0-A91B-0000C0A118DB")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IAEditIconSink
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnAddIcon();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnRemoveIcon();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnSetCurrentIcon();
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("C07B3BE0-2ED3-11D1-8900-0000C0E749F8")]
public interface IASection : IEnumAModel
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void Next(uint nCount, [MarshalAs(UnmanagedType.Interface)] ref IAModel ppModel, ref uint pnumFetched);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void Skip(uint nCount);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void Clone([MarshalAs(UnmanagedType.Interface)] ref IEnumAModel ppEnum);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetName(ref byte pName, int nSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetName(ref byte pName);
}
[ComImport]
[Guid("C07B3BE1-2ED3-11D1-8900-0000C0E749F8")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IEnumASection
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Next(uint nCount, [MarshalAs(UnmanagedType.Interface)] ref IASection ppSection, ref uint pnumFetched);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Skip(uint nCount);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] ref IEnumASection ppEnum);
}
[ComImport]
[Guid("C07B3BE2-2ED3-11D1-8900-0000C0E749F8")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IAEditSections
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void AddSection([MarshalAs(UnmanagedType.Interface)] ref IASection ppIASection, ref byte name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoveSection([MarshalAs(UnmanagedType.Interface)] IASection pSection);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void FindSection(ref byte name, [MarshalAs(UnmanagedType.Interface)] ref IASection ppSection);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnumSections([MarshalAs(UnmanagedType.Interface)] ref IEnumASection ppEnum);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetCurrentSection([MarshalAs(UnmanagedType.Interface)] IASection pIASection);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetCurrentSection([MarshalAs(UnmanagedType.Interface)] ref IASection ppIASection);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("A89BB1D1-1057-11D2-80E4-0000C09EFCF3")]
public interface IEnumACategory
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Next(uint nCount, [MarshalAs(UnmanagedType.Interface)] ref IACategory ppCategory, ref uint pnumFetched);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Skip(uint nCount);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] ref IEnumACategory ppEnum);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("A89BB1D2-1057-11D2-80E4-0000C09EFCF3")]
public interface IAEditCategories
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void AddCategory(ref byte name, [MarshalAs(UnmanagedType.Interface)] ref IACategory ppCategory);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoveCategory([MarshalAs(UnmanagedType.Interface)] IACategory pCategory);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void FindCategory(ref byte name, [MarshalAs(UnmanagedType.Interface)] ref IACategory ppCategory);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnumCategories([MarshalAs(UnmanagedType.Interface)] ref IEnumACategory ppEnum);
}
[ComImport]
[Guid("97011FCE-6B82-404E-9657-D1096C43750A")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IAModel3
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void DoCopy();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void DoPaste();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int OnUpdatePaste();
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
[ComConversionLoss]
public struct AOSASTREAM_MODEL_MSG
{
	public uint dwEventCode;

	[ComConversionLoss]
	public IntPtr pName;
}
[ComImport]
[Guid("B0DFFFEE-908C-11CE-A964-0000C08C668E")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IABlockType
{
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("B0DFFFE8-908C-11CE-A964-0000C08C668E")]
public interface IAStreamType
{
}
[ComImport]
[Guid("B7481A20-9E90-4A27-BF8C-B7A79670FEE5")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IARootModel
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetRootPathName(ref byte pName, int size);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ActivatePFSView(ref byte pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetDynamicsExportMode(ref int mode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetDynamicsExportMode(int mode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void FindHierarchy(ref byte pName, [MarshalAs(UnmanagedType.Interface)] ref IAModel ppModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnumHierarchies([MarshalAs(UnmanagedType.Interface)] ref IEnumAModel ppEnum);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("E18DF500-67F9-11D0-A918-0000C0A118DB")]
public interface IALoadBkpIcon
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void LoadBkpIcon(int nIconId, ref byte pModelName, [MarshalAs(UnmanagedType.Interface)] ref IAIcon ppIcon);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("4CB36590-3BED-11D1-B1D7-00A024E5DF41")]
public interface IAEditControlSignal
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Edit(uint nEnd);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("26914A1B-4C1A-11D4-907D-00A02451BB94")]
public interface IAConnectorPort
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetConnectedStreamName(ref byte pName, int nSize);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("D1CE95DF-B3D5-41C6-A2E6-59F80A88CAB2")]
public interface IAStreamTable
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetData(ref IntPtr pData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetData(IntPtr pData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetUpdate(ref short flag);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetUpdate(short flag);
}
[ComImport]
[Guid("D1CE95E0-B3D5-41C6-A2E6-59F80A88CAB2")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IEnumAStreamTable
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Next(uint nCount, [MarshalAs(UnmanagedType.Interface)] ref IAStreamTable ppStreamTable, ref uint pnumFetched);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Skip(uint nCount);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] ref IEnumAStreamTable ppEnum);
}
[ComImport]
[Guid("D1CE95E1-B3D5-41C6-A2E6-59F80A88CAB2")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IAEditStreamTables
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void InsertStreamTable([MarshalAs(UnmanagedType.Interface)] ref IAStreamTable ppTable, IntPtr pData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoveStreamTable([MarshalAs(UnmanagedType.Interface)] IAStreamTable pTable);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoveAllStreamTables();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnumStreamTables([MarshalAs(UnmanagedType.Interface)] ref IEnumAStreamTable ppEnum);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetCount(ref int nCount);
}
[ComImport]
[Guid("EFB9695F-3935-4514-8ACD-7EDE5CE250DE")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IAPFSControl
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void BeginImport([In] int bUseCenterPt, [In] POINT pt);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EndImport();

	[DispId(1610678274)]
	RECT Viewport
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	// Named indexed COM property BlockPosition, DispId 1610678276. The original
	// Property/MethodSemantics mapping is retained in the accompanying IL and metadata.
	[SpecialName]
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	RECT get_BlockPosition([In] ref byte name);

	[SpecialName]
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void set_BlockPosition([In] ref byte name, [In] RECT pRect);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ResizeBlockIcon([In] ref byte name, [In] float ratio);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ExchangeBlockIcon([In] ref byte name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RerouteStream([In] ref byte name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetBlockPosition([In] ref byte name, out float x, out float y, out float scale, out int orient);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetBlockPosition([In] ref byte name, [In] float x, [In] float y, [In] float scale, [In] int orient);
}
[ComImport]
[Guid("67A9CE20-B024-11D0-A0D8-0000C03333EF")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IAPFSAdviseSink
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnNotify(uint EventCode, int BeforeOrAfterEvent, IntPtr pEventStruct, int nStructSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetSettings(ref byte pSettings, int nSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetSettings(ref byte pSettings);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnumSelectedModels([MarshalAs(UnmanagedType.Interface)] ref IEnumAModel ppEnum);
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
[ComConversionLoss]
public struct AOSAEC_MODEL_MSG
{
	[MarshalAs(UnmanagedType.Interface)]
	public IAModel pModel;

	[ComConversionLoss]
	public IntPtr oldName;

	[ComConversionLoss]
	public IntPtr newName;
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
public struct AOSAEC_CONN_MSG
{
	[MarshalAs(UnmanagedType.Interface)]
	public IAConnection pConnection;

	[MarshalAs(UnmanagedType.Interface)]
	public IAPort pPort1;

	public int nInstNumber1;

	[MarshalAs(UnmanagedType.Interface)]
	public IAPort pPort2;

	public int nInstNumber2;

	[MarshalAs(UnmanagedType.Interface)]
	public IAPort pReplacedPort;

	public int nReplacedInstNumber;

	public int bPortReplacedWas1;
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
[ComConversionLoss]
public struct AOSAEC_SECTION_MSG
{
	[MarshalAs(UnmanagedType.Interface)]
	public IASection pSection;

	[ComConversionLoss]
	public IntPtr oldName;

	[ComConversionLoss]
	public IntPtr newName;
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
[ComConversionLoss]
public struct AOSAEC_DISCONNECT_MSG
{
	public short iDirection;

	[ComConversionLoss]
	public IntPtr StreamName;
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
public struct AOSAEC_IUNKNOWN_MSG
{
	[MarshalAs(UnmanagedType.IUnknown)]
	public object pUnk;
}
public enum PSSTATE
{
	PSSTATE_UNINIT,
	PSSTATE_SCRIBBLE,
	PSSTATE_ZOMBIE,
	PSSTATE_HANDSOFF
}
public enum IAModelCustomMethod
{
	IAModel_HAGetAttr,
	IAModel_HASetAttr,
	IAModel_GetControlVarList,
	IAModel_SetControllerVar,
	IAModel_ClearControllerVar,
	IAModel_IsControllerModel,
	IAModel_GetControllerVar
}
