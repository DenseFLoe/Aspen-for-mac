using System;
using System.Collections;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.ComTypes;
using System.Threading;

[assembly: ImportedFromTypeLib("PFSCTRL360Lib")]
[assembly: TypeLibVersion(1, 0)]
[assembly: Guid("D3BD248B-50AD-4100-BFE6-FC7E6C4AEB01")]
[assembly: AssemblyVersion("1.0.0.0")]
namespace PFSCtrlLib;

[ComImport]
[Guid("B41CD126-42E6-4100-B959-77E2EAC8CDA0")]
[TypeLibType(TypeLibTypeFlags.FHidden | TypeLibTypeFlags.FDispatchable)]
[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
public interface _DPfsctrl
{
	[DispId(2)]
	short ClientType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		set;
	}

	[DispId(1)]
	string SourceFile
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	bool LoadFromFile([MarshalAs(UnmanagedType.BStr)] string filename);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void SetRootModel([MarshalAs(UnmanagedType.IUnknown)] object RootModel);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void DeleteBuddy([MarshalAs(UnmanagedType.IDispatch)] object dispatch);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	[return: MarshalAs(UnmanagedType.IDispatch)]
	object GetIDispatch();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	void AddBuddy([MarshalAs(UnmanagedType.IDispatch)] object dispatch);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	void InvokeMenuItem(int Command);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(9)]
	bool CheckMenuItem(int Command, ref short Check);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(10)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetCurrentModel(ref int ObjectType, [MarshalAs(UnmanagedType.IUnknown)] ref object pModel, [MarshalAs(UnmanagedType.Error)] ref int Result);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(11)]
	void MessagePort([MarshalAs(UnmanagedType.BStr)] string sMessage);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(12)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetMessageLog();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	void OnViewUpdate(int lHint, [MarshalAs(UnmanagedType.IUnknown)] object pObject);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	void OnFilePageSetup();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	void OnPrinting(int code, [MarshalAs(UnmanagedType.IUnknown)] object pDC, [MarshalAs(UnmanagedType.IUnknown)] object pInfo, bool bPreview);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	void ClosePlaceWindow();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	void AutoPlacement(bool bON);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(18)]
	bool SaveEmbedded([MarshalAs(UnmanagedType.IUnknown)] object pStorage);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	void AnimateBlock([MarshalAs(UnmanagedType.BStr)] string Name);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(20)]
	void InsertBirdcage([MarshalAs(UnmanagedType.IUnknown)] object pCage);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(21)]
	void DeleteAllBirdcages();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(22)]
	void SetStopPoint([MarshalAs(UnmanagedType.BStr)] string blockid, short after);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(23)]
	void RemoveStopPoint([MarshalAs(UnmanagedType.BStr)] string blockid, short after);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(24)]
	void RemoveAllStopPoints();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(25)]
	void OpenUnplaceDialog(short AutoPlacement);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(26)]
	bool DrawToolbar(bool bToggle);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(27)]
	bool BkpReader([MarshalAs(UnmanagedType.IUnknown)] object lpStream);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	void SetDocument([MarshalAs(UnmanagedType.IUnknown)] object lpDocument);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	void AddText([MarshalAs(UnmanagedType.BStr)] string szText);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	void KeyDown(int nChar, int nRepCnt, int nFlags);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(31)]
	void GenerateDXF([MarshalAs(UnmanagedType.IUnknown)] object pStream);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(32)]
	void AddMenuItem(short type, [MarshalAs(UnmanagedType.BStr)] string label, int Command);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(33)]
	void EnableMenuItem(short type, int Command, int flags);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(34)]
	void DeleteMenuItem(short type, int Command);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	short AddMenu(short type, [MarshalAs(UnmanagedType.BStr)] string label);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(36)]
	short GetMenuSize(short type);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(37)]
	void SetSymbol([MarshalAs(UnmanagedType.BStr)] string SymbolName, [MarshalAs(UnmanagedType.BStr)] string Value);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(38)]
	void SetName([MarshalAs(UnmanagedType.BStr)] string Name);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(39)]
	bool CenterView([MarshalAs(UnmanagedType.BStr)] string ID, short type);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(40)]
	void Zoom(float scalefactor, short type);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(41)]
	[return: MarshalAs(UnmanagedType.IUnknown)]
	object GetEmbeddedItem([MarshalAs(UnmanagedType.BStr)] string szItemName);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(42)]
	void SetApplication([MarshalAs(UnmanagedType.IUnknown)] object lpApp);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(43)]
	void CloseEmbeddedItems();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(44)]
	bool PfsToolbar(bool bToggle);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(45)]
	void Configure(int flags);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(46)]
	[return: MarshalAs(UnmanagedType.IUnknown)]
	object TransferCopyDataObject();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(47)]
	void GetViewport(ref float left, ref float right, ref float top, ref float bottom);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(48)]
	void SetViewport(float left, float right, float top, float bottom);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(49)]
	void LockFlowsheet(bool Lock);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(50)]
	void EnableBlock([MarshalAs(UnmanagedType.BStr)] string Name, bool bEnable);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(51)]
	bool FlowsheetLocked();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(52)]
	void GenerateDump([MarshalAs(UnmanagedType.IUnknown)] object pStream);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(53)]
	void AutoPositionBlock([MarshalAs(UnmanagedType.BStr)] string Name);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(54)]
	bool CheckEmbededObject();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(55)]
	void SetLibBarDropDownState();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(56)]
	void CancelLibBarDropDownState();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(57)]
	void ChangeBlockIcon([MarshalAs(UnmanagedType.LPWStr)] string pszBlockName, [MarshalAs(UnmanagedType.LPStr)] string pszIconName);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(58)]
	void DrawText();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(59)]
	bool GetFontBold();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(60)]
	void SetFontBold();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(61)]
	void DrawLine();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(62)]
	void DrawBox();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(63)]
	void DrawPolygon();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(64)]
	void DrawPolyline();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(65)]
	void DrawEllipse();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(66)]
	void DrawHellipsens();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(67)]
	void DrawArrow();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(68)]
	void DrawDoubleArrow();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(69)]
	void ZoomToScale(float newScale);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(70)]
	bool GetFontItalic();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(71)]
	void SetFontItalic();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(72)]
	bool GetFontUnderScore();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(73)]
	void SetFontUnderScore();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(74)]
	bool GetAlignLeft();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(75)]
	void SetAlignLeft();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(76)]
	bool GetAlignCenter();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(77)]
	void SetAlignCenter();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(78)]
	bool GetAlignRight();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(79)]
	void SetAlignRight();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(80)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetFontSizeList();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(81)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetFontNameList();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(82)]
	short GetFontSizeCurIndex();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(83)]
	void SetFontSizeCurIndex(short curIndex);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(84)]
	short GetColorCurIndex();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(85)]
	short GetLineTypeCurIndex();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(86)]
	void SetRotateRight();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(87)]
	void SetFLIPX();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(88)]
	void SetFLIPY();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(89)]
	void PlaceAllBlocks();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(90)]
	void PlaceNextBlock();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(91)]
	void PlaceBlock([MarshalAs(UnmanagedType.BStr)] string Name);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(92)]
	bool GetSelectMode();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(93)]
	void SetSelectMode();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(94)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetUndoList();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(95)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetRedoList();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(96)]
	void SetOneStepUndo();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(97)]
	void SetStepsUndo(short curIndex);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(98)]
	void SetOneStepRedo();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(99)]
	void SetStepsRedo(short curIndex);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(100)]
	bool IsItemSelected();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(101)]
	void SelectObject([MarshalAs(UnmanagedType.BStr)] string sRootModelName, [MarshalAs(UnmanagedType.BStr)] string sName, int oclass, int bCenterView, int bZoomView);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(102)]
	void SaveFindObjectSettings(int bCenterView, int bZoomView, [MarshalAs(UnmanagedType.BStr)] string sBlockFilterList, [MarshalAs(UnmanagedType.BStr)] string sStreamFilterList);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(103)]
	void FindObjectClosed();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(104)]
	void WPFInsertBirdcage(long pCage);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(105)]
	[return: MarshalAs(UnmanagedType.IUnknown)]
	object GetRootModel();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(106)]
	void LoadAsText([MarshalAs(UnmanagedType.BStr)] string sVData);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(107)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string SaveAsText();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(108)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetBookmarkList();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(109)]
	void GotoBookmark([MarshalAs(UnmanagedType.BStr)] string sName);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(110)]
	void AddBookmark([MarshalAs(UnmanagedType.LPStr)] string strName);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(111)]
	void DeleteBookmark([MarshalAs(UnmanagedType.LPStr)] string strName);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(112)]
	short GetTextColorIndex();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(113)]
	void SetTextColorIndex(short curIndex);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(114)]
	short GetColorFillCurIndex();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(115)]
	short GetLineWeightCurIndex();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(116)]
	void SetLineWeightCurIndex(short curIndex);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(117)]
	void SelectObject2([MarshalAs(UnmanagedType.BStr)] string sName, int oclass, int bCenterView, int bZoomView);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(118)]
	bool GetSelectedDrawAttributes(ref int lineColor, ref int fillColor, ref int outline, ref int filled, ref int lineStyle, ref int lineWidth);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(119)]
	void SetSelectedDrawAttributes(int lineColor, int fillColor, int outline, int filled, int lineStyle, int lineWidth);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(120)]
	bool GetSelectedStreamAttributes(ref int useDefault, ref int lineColor, ref int lineStyle, ref int lineWidth);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(121)]
	void SetSelectedStreamAttributes(int useDefault, int lineColor, int lineStyle, int lineWidth);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(122)]
	bool GetObjectTypeSelected(int type);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(123)]
	void ScrollBigStep(int bHorizontal, short zDelta);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(124)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetFontName();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(125)]
	void SetFontName([MarshalAs(UnmanagedType.LPWStr)] string pszFontName);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(126)]
	void SetStopCursor();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(127)]
	void ClearStopCursor();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(128)]
	void SetDocumentPtr(ulong lpDocument);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(129)]
	bool DoActiveSelectedModel();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(130)]
	void PfsLButtonDown(int x, int y, int iMouseType);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(131)]
	void CancelInsertMode();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(132)]
	bool GetMultipleObjectSelected();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(133)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetSettings();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(134)]
	void SetSettings([MarshalAs(UnmanagedType.BStr)] string sSettings);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(135)]
	void UpdateTooltipText([MarshalAs(UnmanagedType.LPStr)] string strObjectsID, [MarshalAs(UnmanagedType.LPStr)] string strDescriptions);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(136)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetSelectedObjectsPath();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(137)]
	void InsertWPFForm([MarshalAs(UnmanagedType.IUnknown)] object lpCtrl, [MarshalAs(UnmanagedType.IUnknown)] object lpImg, bool bShowAsIcon, [MarshalAs(UnmanagedType.LPWStr)] string pszPath, [MarshalAs(UnmanagedType.LPWStr)] string pszFormType, int iTarget, int nWidth, int nHeight);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(138)]
	void LoadWPFForm([MarshalAs(UnmanagedType.IUnknown)] object lpCtrl, [MarshalAs(UnmanagedType.IUnknown)] object lpImg, int nWidth, int nHeight);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(139)]
	void ZoomWPFForm(double dFactor);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(140)]
	void UpdateAXObjPath([MarshalAs(UnmanagedType.LPWStr)] string pszOldPath, [MarshalAs(UnmanagedType.LPWStr)] string pszNewPath, int iType);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(141)]
	void DeleteAXObj([MarshalAs(UnmanagedType.LPWStr)] string pszPath, int iType);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(142)]
	void FitWPFFormToContent([MarshalAs(UnmanagedType.LPWStr)] string pszPath, int iType);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(143)]
	void EmbeddedWPFFormUpdateData();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(144)]
	void SetObjectDescriptionText([MarshalAs(UnmanagedType.LPStr)] string strID, [MarshalAs(UnmanagedType.LPStr)] string strDescriptionText);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(145)]
	void ResetFocus();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(146)]
	void VerifyGrid(float fGridResolution, bool bViewGrid);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(147)]
	void ClearHistory();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(148)]
	bool GetMultipleBlockObjectSelected();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(149)]
	float GetZoomLevel();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(150)]
	bool GetBlockPosition([MarshalAs(UnmanagedType.LPStr)] string sName, ref float x, ref float y);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(151)]
	bool GetBlockSize([MarshalAs(UnmanagedType.LPStr)] string sName, ref float left, ref float right, ref float top, ref float bottom);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(152)]
	bool FocusInTextEdit();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(153)]
	void SetPSVMode(bool bFlag);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(154)]
	void SetInsertPSVBlockFlag();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(155)]
	void SetPSVModelType([MarshalAs(UnmanagedType.IUnknown)] object pPSVBlockModelType, [MarshalAs(UnmanagedType.IUnknown)] object pPSVStreamModelType);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(156)]
	void RestorePSVStreamRoute();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(157)]
	void SetStreamPSVName([MarshalAs(UnmanagedType.LPWStr)] string pszStreamFullPath, [MarshalAs(UnmanagedType.LPWStr)] string pszPSVName);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(158)]
	void SynchronizePSVConnectivity([MarshalAs(UnmanagedType.LPWStr)] string pszStreamID, [MarshalAs(UnmanagedType.LPWStr)] string pszPSVName);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(159)]
	void DeletePSVBlock([MarshalAs(UnmanagedType.LPWStr)] string pszStreamID, [MarshalAs(UnmanagedType.LPWStr)] string pszPSVName);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(160)]
	void RenamePSVBlock([MarshalAs(UnmanagedType.LPWStr)] string pszStreamID, [MarshalAs(UnmanagedType.LPWStr)] string pszPSVOldName, [MarshalAs(UnmanagedType.LPWStr)] string pszPSVNewName);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(161)]
	void SetPSVObjectType(int iPSVObjectType);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(162)]
	void SetPSVBlockDescription(int iBlockType, [MarshalAs(UnmanagedType.LPWStr)] string pszBlockName, [MarshalAs(UnmanagedType.LPWStr)] string pszDescription);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(163)]
	void SetPSVBlockType([MarshalAs(UnmanagedType.LPWStr)] string pszBlocksIDtoType);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(164)]
	void SetPSVBlockErrorLevelAndMessage([MarshalAs(UnmanagedType.LPStr)] string pszPSVBlockID, int iErrorLevel, [MarshalAs(UnmanagedType.LPStr)] string pszMsg);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(165)]
	void ResetDOFIndicators();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(166)]
	void RedrawStreams([MarshalAs(UnmanagedType.LPStr)] string pszStreamNames, int iQueryLineStyle);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(167)]
	void ClearEmbeddedWPFForms();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(168)]
	void ClearAndResetEmbeddedWPFForms();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(169)]
	void SaveEmbeddedWPFForms();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(170)]
	int FocusWPFFormIfExists([MarshalAs(UnmanagedType.LPStr)] string pszID, int iType);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(171)]
	bool GetPSVMode();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(172)]
	void SetBatchMode(bool bFlag);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(173)]
	void RefreshBlock([MarshalAs(UnmanagedType.LPStr)] string pszBlockID);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(174)]
	void SetSimulationRunState(bool bIsRunning);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(175)]
	void RefreshStreamGroups(bool bAllFlowsheets, [MarshalAs(UnmanagedType.LPStr)] string pszStreamIDList);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(176)]
	void UpdateAnnotationsOnFlowSheet();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-552)]
	void AboutBox();
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDispatchable)]
[Guid("FED12056-170C-4100-9C3E-A6C33062FBB0")]
[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
public interface _DPfsctrlEvents
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void DoOleVerb([MarshalAs(UnmanagedType.IUnknown)] object pOleObj, int nID);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void InvokeMenuItem(int nCommand);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void SelectPrinter([ComAliasName("stdole.OLE_HANDLE")] int DevNames, [ComAliasName("stdole.OLE_HANDLE")] int DevMode);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void OnFIlePrint();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void SetMessageText([MarshalAs(UnmanagedType.BStr)] string text);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	void DrawToolbar(bool bON);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	void Modified();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	void OnSelect(short type, [MarshalAs(UnmanagedType.BStr)] string ID);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(9)]
	void OnDoubleClick(short type, [MarshalAs(UnmanagedType.BStr)] string ID);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(10)]
	void UpdateSettings(int lHint);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(11)]
	void PfsToolbar(bool bON);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(12)]
	void OnDoubleClick2(short type, [MarshalAs(UnmanagedType.BStr)] string ID, [MarshalAs(UnmanagedType.BStr)] string ModelType);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	void OnCancelInsertMode();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	void ModelUpdate([MarshalAs(UnmanagedType.BStr)] string ID, [MarshalAs(UnmanagedType.BStr)] string ModelType);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	void BeforeRenameModel([MarshalAs(UnmanagedType.BStr)] string ID);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	void OnCancelLibBarHalfStreamInsertMode();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	void OnZoomChanged(float oldScale, float newScale);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(18)]
	void ManageViewChanged();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	void UndoRedoChanged();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(20)]
	void LoadingWPFForm([MarshalAs(UnmanagedType.BStr)] string bstrPath, int iFormType, int iTargetClass);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(21)]
	void DeleteWPFForm([MarshalAs(UnmanagedType.BStr)] string bstrPath, [MarshalAs(UnmanagedType.BStr)] string bstrFormType);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(22)]
	void GetObjectDescriptionText([MarshalAs(UnmanagedType.BStr)] string bstrPath, int nObjectType);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(23)]
	void BlockVisibleChanging([MarshalAs(UnmanagedType.BStr)] string bstrType);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(24)]
	void OnDropFiles([MarshalAs(UnmanagedType.BStr)] string varFiles);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(25)]
	void UpdateFlipRotateStatus();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(26)]
	void DeleteBlockObject([MarshalAs(UnmanagedType.BStr)] string bstrID, [MarshalAs(UnmanagedType.BStr)] string bstrObjectType);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(27)]
	void RenameBlockObject([MarshalAs(UnmanagedType.BStr)] string bstrOldName, [MarshalAs(UnmanagedType.BStr)] string bstrNewName, [MarshalAs(UnmanagedType.BStr)] string bstrObjectType);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	void PSVAttachedPSVToStream([MarshalAs(UnmanagedType.BStr)] string bstrStreamFullPath, [MarshalAs(UnmanagedType.BStr)] string bstrPSVName);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	void BeginInsertPSVBlock();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	void FinishInsertPSVBlock();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(31)]
	void GetStreamPSVName([MarshalAs(UnmanagedType.BStr)] string bstrStreamFullPath, int iObjectType);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(32)]
	void OnDeletePSVBlock([MarshalAs(UnmanagedType.BStr)] string bstrStreamID, [MarshalAs(UnmanagedType.BStr)] string bstrPSVName);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(33)]
	void OnAddPSVBlock([MarshalAs(UnmanagedType.BStr)] string bstrStreamFullPath, int iPSVObjectType);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(34)]
	void OnGetPSVBlockDescription(int iBlockType, [MarshalAs(UnmanagedType.BStr)] string bstrBlockName);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	void OnRequestPSVBlockType([MarshalAs(UnmanagedType.BStr)] string bstrPSVBlockIDs);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(36)]
	void OnPSVBlockExchangeType([MarshalAs(UnmanagedType.BStr)] string bstrPSVBlockID, int iOldType, int iNewType);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(37)]
	void OnGetPSVBlockErrorLevel([MarshalAs(UnmanagedType.BStr)] string bstrPSVBlockID);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(38)]
	void CreateBlock([MarshalAs(UnmanagedType.BStr)] string bstrBlockID, [MarshalAs(UnmanagedType.BStr)] string bstrBlockType);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(39)]
	void OnEditStreamSummaryForm([MarshalAs(UnmanagedType.BStr)] string bstrObjectName, int iTargetObjectClass);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(40)]
	void CreateStream([MarshalAs(UnmanagedType.BStr)] string strStreamID, [MarshalAs(UnmanagedType.BStr)] string strStreamType, [MarshalAs(UnmanagedType.BStr)] string conectBlock1, [MarshalAs(UnmanagedType.BStr)] string conectBlock2);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(41)]
	void ScanConnect([MarshalAs(UnmanagedType.BStr)] string streamName, [MarshalAs(UnmanagedType.BStr)] string blockName, [MarshalAs(UnmanagedType.BStr)] string connectType, int direction);
}
[ComVisible(false)]
[TypeLibType(TypeLibTypeFlags.FHidden)]
[ComEventInterface(typeof(_DPfsctrlEvents), typeof(_DPfsctrlEvents_EventProvider))]
public interface _DPfsctrlEvents_Event
{
	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_DoOleVerbEventHandler DoOleVerb;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_InvokeMenuItemEventHandler InvokeMenuItem;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_SelectPrinterEventHandler SelectPrinter;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_OnFIlePrintEventHandler OnFIlePrint;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_SetMessageTextEventHandler SetMessageText;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_DrawToolbarEventHandler DrawToolbar;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_ModifiedEventHandler Modified;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_OnSelectEventHandler OnSelect;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_OnDoubleClickEventHandler OnDoubleClick;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_UpdateSettingsEventHandler UpdateSettings;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_PfsToolbarEventHandler PfsToolbar;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_OnDoubleClick2EventHandler OnDoubleClick2;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_OnCancelInsertModeEventHandler OnCancelInsertMode;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_ModelUpdateEventHandler ModelUpdate;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_BeforeRenameModelEventHandler BeforeRenameModel;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_OnCancelLibBarHalfStreamInsertModeEventHandler OnCancelLibBarHalfStreamInsertMode;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_OnZoomChangedEventHandler OnZoomChanged;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_ManageViewChangedEventHandler ManageViewChanged;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_UndoRedoChangedEventHandler UndoRedoChanged;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_LoadingWPFFormEventHandler LoadingWPFForm;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_DeleteWPFFormEventHandler DeleteWPFForm;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_GetObjectDescriptionTextEventHandler GetObjectDescriptionText;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_BlockVisibleChangingEventHandler BlockVisibleChanging;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_OnDropFilesEventHandler OnDropFiles;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_UpdateFlipRotateStatusEventHandler UpdateFlipRotateStatus;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_DeleteBlockObjectEventHandler DeleteBlockObject;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_RenameBlockObjectEventHandler RenameBlockObject;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_PSVAttachedPSVToStreamEventHandler PSVAttachedPSVToStream;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_BeginInsertPSVBlockEventHandler BeginInsertPSVBlock;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_FinishInsertPSVBlockEventHandler FinishInsertPSVBlock;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_GetStreamPSVNameEventHandler GetStreamPSVName;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_OnDeletePSVBlockEventHandler OnDeletePSVBlock;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_OnAddPSVBlockEventHandler OnAddPSVBlock;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_OnGetPSVBlockDescriptionEventHandler OnGetPSVBlockDescription;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_OnRequestPSVBlockTypeEventHandler OnRequestPSVBlockType;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_OnPSVBlockExchangeTypeEventHandler OnPSVBlockExchangeType;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_OnGetPSVBlockErrorLevelEventHandler OnGetPSVBlockErrorLevel;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_CreateBlockEventHandler CreateBlock;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_OnEditStreamSummaryFormEventHandler OnEditStreamSummaryForm;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_CreateStreamEventHandler CreateStream;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	event _DPfsctrlEvents_ScanConnectEventHandler ScanConnect;
}
[ComImport]
[CoClass(typeof(PfsctrlClass))]
[Guid("B41CD126-42E6-4100-B959-77E2EAC8CDA0")]
public interface Pfsctrl : _DPfsctrl, _DPfsctrlEvents_Event
{
}
[ComImport]
[ComSourceInterfaces("PFSCtrlLib._DPfsctrlEvents\0\0")]
[Guid("20C9D4CD-6C3E-4100-8EE1-B3056237349E")]
[ClassInterface(ClassInterfaceType.None)]
[TypeLibType(TypeLibTypeFlags.FCanCreate | TypeLibTypeFlags.FControl)]
// COM supplies the original public .ctor() as runtime/internalcall. C# synthesizes the COM constructor.
public class PfsctrlClass : _DPfsctrl, Pfsctrl, _DPfsctrlEvents_Event
{
	[DispId(2)]
	public virtual extern short ClientType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		set;
	}

	[DispId(1)]
	public virtual extern string SourceFile
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_DoOleVerbEventHandler DoOleVerb;

	// Original public Event is _DPfsctrlEvents_Event_InvokeMenuItem; its accessors are add_InvokeMenuItem / remove_InvokeMenuItem.
	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_InvokeMenuItemEventHandler InvokeMenuItem;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_SelectPrinterEventHandler SelectPrinter;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_OnFIlePrintEventHandler OnFIlePrint;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_SetMessageTextEventHandler SetMessageText;

	// Original public Event is _DPfsctrlEvents_Event_DrawToolbar; its accessors are add_DrawToolbar / remove_DrawToolbar.
	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_DrawToolbarEventHandler DrawToolbar;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_ModifiedEventHandler Modified;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_OnSelectEventHandler OnSelect;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_OnDoubleClickEventHandler OnDoubleClick;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_UpdateSettingsEventHandler UpdateSettings;

	// Original public Event is _DPfsctrlEvents_Event_PfsToolbar; its accessors are add_PfsToolbar / remove_PfsToolbar.
	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_PfsToolbarEventHandler PfsToolbar;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_OnDoubleClick2EventHandler OnDoubleClick2;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_OnCancelInsertModeEventHandler OnCancelInsertMode;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_ModelUpdateEventHandler ModelUpdate;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_BeforeRenameModelEventHandler BeforeRenameModel;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_OnCancelLibBarHalfStreamInsertModeEventHandler OnCancelLibBarHalfStreamInsertMode;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_OnZoomChangedEventHandler OnZoomChanged;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_ManageViewChangedEventHandler ManageViewChanged;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_UndoRedoChangedEventHandler UndoRedoChanged;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_LoadingWPFFormEventHandler LoadingWPFForm;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_DeleteWPFFormEventHandler DeleteWPFForm;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_GetObjectDescriptionTextEventHandler GetObjectDescriptionText;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_BlockVisibleChangingEventHandler BlockVisibleChanging;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_OnDropFilesEventHandler OnDropFiles;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_UpdateFlipRotateStatusEventHandler UpdateFlipRotateStatus;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_DeleteBlockObjectEventHandler DeleteBlockObject;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_RenameBlockObjectEventHandler RenameBlockObject;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_PSVAttachedPSVToStreamEventHandler PSVAttachedPSVToStream;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_BeginInsertPSVBlockEventHandler BeginInsertPSVBlock;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_FinishInsertPSVBlockEventHandler FinishInsertPSVBlock;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_GetStreamPSVNameEventHandler GetStreamPSVName;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_OnDeletePSVBlockEventHandler OnDeletePSVBlock;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_OnAddPSVBlockEventHandler OnAddPSVBlock;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_OnGetPSVBlockDescriptionEventHandler OnGetPSVBlockDescription;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_OnRequestPSVBlockTypeEventHandler OnRequestPSVBlockType;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_OnPSVBlockExchangeTypeEventHandler OnPSVBlockExchangeType;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_OnGetPSVBlockErrorLevelEventHandler OnGetPSVBlockErrorLevel;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_CreateBlockEventHandler CreateBlock;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_OnEditStreamSummaryFormEventHandler OnEditStreamSummaryForm;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_CreateStreamEventHandler CreateStream;

	[method: MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern event _DPfsctrlEvents_ScanConnectEventHandler ScanConnect;

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	public virtual extern bool LoadFromFile([MarshalAs(UnmanagedType.BStr)] string filename);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	public virtual extern void SetRootModel([MarshalAs(UnmanagedType.IUnknown)] object RootModel);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	public virtual extern void DeleteBuddy([MarshalAs(UnmanagedType.IDispatch)] object dispatch);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	[return: MarshalAs(UnmanagedType.IDispatch)]
	public virtual extern object GetIDispatch();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	public virtual extern void AddBuddy([MarshalAs(UnmanagedType.IDispatch)] object dispatch);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	// Project the colliding imported command through its original _DPfsctrl interface slot.
	extern void _DPfsctrl.InvokeMenuItem(int Command);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(9)]
	public virtual extern bool CheckMenuItem(int Command, ref short Check);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(10)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string GetCurrentModel(ref int ObjectType, [MarshalAs(UnmanagedType.IUnknown)] ref object pModel, [MarshalAs(UnmanagedType.Error)] ref int Result);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(11)]
	public virtual extern void MessagePort([MarshalAs(UnmanagedType.BStr)] string sMessage);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(12)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string GetMessageLog();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	public virtual extern void OnViewUpdate(int lHint, [MarshalAs(UnmanagedType.IUnknown)] object pObject);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	public virtual extern void OnFilePageSetup();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	public virtual extern void OnPrinting(int code, [MarshalAs(UnmanagedType.IUnknown)] object pDC, [MarshalAs(UnmanagedType.IUnknown)] object pInfo, bool bPreview);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	public virtual extern void ClosePlaceWindow();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	public virtual extern void AutoPlacement(bool bON);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(18)]
	public virtual extern bool SaveEmbedded([MarshalAs(UnmanagedType.IUnknown)] object pStorage);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	public virtual extern void AnimateBlock([MarshalAs(UnmanagedType.BStr)] string Name);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(20)]
	public virtual extern void InsertBirdcage([MarshalAs(UnmanagedType.IUnknown)] object pCage);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(21)]
	public virtual extern void DeleteAllBirdcages();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(22)]
	public virtual extern void SetStopPoint([MarshalAs(UnmanagedType.BStr)] string blockid, short after);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(23)]
	public virtual extern void RemoveStopPoint([MarshalAs(UnmanagedType.BStr)] string blockid, short after);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(24)]
	public virtual extern void RemoveAllStopPoints();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(25)]
	public virtual extern void OpenUnplaceDialog(short AutoPlacement);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(26)]
	// Project the colliding imported command through its original _DPfsctrl interface slot.
	extern bool _DPfsctrl.DrawToolbar(bool bToggle);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(27)]
	public virtual extern bool BkpReader([MarshalAs(UnmanagedType.IUnknown)] object lpStream);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	public virtual extern void SetDocument([MarshalAs(UnmanagedType.IUnknown)] object lpDocument);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	public virtual extern void AddText([MarshalAs(UnmanagedType.BStr)] string szText);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	public virtual extern void KeyDown(int nChar, int nRepCnt, int nFlags);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(31)]
	public virtual extern void GenerateDXF([MarshalAs(UnmanagedType.IUnknown)] object pStream);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(32)]
	public virtual extern void AddMenuItem(short type, [MarshalAs(UnmanagedType.BStr)] string label, int Command);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(33)]
	public virtual extern void EnableMenuItem(short type, int Command, int flags);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(34)]
	public virtual extern void DeleteMenuItem(short type, int Command);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	public virtual extern short AddMenu(short type, [MarshalAs(UnmanagedType.BStr)] string label);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(36)]
	public virtual extern short GetMenuSize(short type);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(37)]
	public virtual extern void SetSymbol([MarshalAs(UnmanagedType.BStr)] string SymbolName, [MarshalAs(UnmanagedType.BStr)] string Value);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(38)]
	public virtual extern void SetName([MarshalAs(UnmanagedType.BStr)] string Name);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(39)]
	public virtual extern bool CenterView([MarshalAs(UnmanagedType.BStr)] string ID, short type);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(40)]
	public virtual extern void Zoom(float scalefactor, short type);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(41)]
	[return: MarshalAs(UnmanagedType.IUnknown)]
	public virtual extern object GetEmbeddedItem([MarshalAs(UnmanagedType.BStr)] string szItemName);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(42)]
	public virtual extern void SetApplication([MarshalAs(UnmanagedType.IUnknown)] object lpApp);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(43)]
	public virtual extern void CloseEmbeddedItems();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(44)]
	// Project the colliding imported command through its original _DPfsctrl interface slot.
	extern bool _DPfsctrl.PfsToolbar(bool bToggle);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(45)]
	public virtual extern void Configure(int flags);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(46)]
	[return: MarshalAs(UnmanagedType.IUnknown)]
	public virtual extern object TransferCopyDataObject();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(47)]
	public virtual extern void GetViewport(ref float left, ref float right, ref float top, ref float bottom);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(48)]
	public virtual extern void SetViewport(float left, float right, float top, float bottom);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(49)]
	public virtual extern void LockFlowsheet(bool Lock);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(50)]
	public virtual extern void EnableBlock([MarshalAs(UnmanagedType.BStr)] string Name, bool bEnable);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(51)]
	public virtual extern bool FlowsheetLocked();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(52)]
	public virtual extern void GenerateDump([MarshalAs(UnmanagedType.IUnknown)] object pStream);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(53)]
	public virtual extern void AutoPositionBlock([MarshalAs(UnmanagedType.BStr)] string Name);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(54)]
	public virtual extern bool CheckEmbededObject();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(55)]
	public virtual extern void SetLibBarDropDownState();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(56)]
	public virtual extern void CancelLibBarDropDownState();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(57)]
	public virtual extern void ChangeBlockIcon([MarshalAs(UnmanagedType.LPWStr)] string pszBlockName, [MarshalAs(UnmanagedType.LPStr)] string pszIconName);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(58)]
	public virtual extern void DrawText();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(59)]
	public virtual extern bool GetFontBold();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(60)]
	public virtual extern void SetFontBold();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(61)]
	public virtual extern void DrawLine();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(62)]
	public virtual extern void DrawBox();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(63)]
	public virtual extern void DrawPolygon();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(64)]
	public virtual extern void DrawPolyline();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(65)]
	public virtual extern void DrawEllipse();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(66)]
	public virtual extern void DrawHellipsens();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(67)]
	public virtual extern void DrawArrow();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(68)]
	public virtual extern void DrawDoubleArrow();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(69)]
	public virtual extern void ZoomToScale(float newScale);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(70)]
	public virtual extern bool GetFontItalic();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(71)]
	public virtual extern void SetFontItalic();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(72)]
	public virtual extern bool GetFontUnderScore();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(73)]
	public virtual extern void SetFontUnderScore();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(74)]
	public virtual extern bool GetAlignLeft();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(75)]
	public virtual extern void SetAlignLeft();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(76)]
	public virtual extern bool GetAlignCenter();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(77)]
	public virtual extern void SetAlignCenter();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(78)]
	public virtual extern bool GetAlignRight();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(79)]
	public virtual extern void SetAlignRight();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(80)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string GetFontSizeList();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(81)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string GetFontNameList();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(82)]
	public virtual extern short GetFontSizeCurIndex();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(83)]
	public virtual extern void SetFontSizeCurIndex(short curIndex);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(84)]
	public virtual extern short GetColorCurIndex();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(85)]
	public virtual extern short GetLineTypeCurIndex();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(86)]
	public virtual extern void SetRotateRight();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(87)]
	public virtual extern void SetFLIPX();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(88)]
	public virtual extern void SetFLIPY();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(89)]
	public virtual extern void PlaceAllBlocks();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(90)]
	public virtual extern void PlaceNextBlock();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(91)]
	public virtual extern void PlaceBlock([MarshalAs(UnmanagedType.BStr)] string Name);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(92)]
	public virtual extern bool GetSelectMode();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(93)]
	public virtual extern void SetSelectMode();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(94)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string GetUndoList();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(95)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string GetRedoList();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(96)]
	public virtual extern void SetOneStepUndo();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(97)]
	public virtual extern void SetStepsUndo(short curIndex);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(98)]
	public virtual extern void SetOneStepRedo();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(99)]
	public virtual extern void SetStepsRedo(short curIndex);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(100)]
	public virtual extern bool IsItemSelected();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(101)]
	public virtual extern void SelectObject([MarshalAs(UnmanagedType.BStr)] string sRootModelName, [MarshalAs(UnmanagedType.BStr)] string sName, int oclass, int bCenterView, int bZoomView);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(102)]
	public virtual extern void SaveFindObjectSettings(int bCenterView, int bZoomView, [MarshalAs(UnmanagedType.BStr)] string sBlockFilterList, [MarshalAs(UnmanagedType.BStr)] string sStreamFilterList);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(103)]
	public virtual extern void FindObjectClosed();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(104)]
	public virtual extern void WPFInsertBirdcage(long pCage);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(105)]
	[return: MarshalAs(UnmanagedType.IUnknown)]
	public virtual extern object GetRootModel();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(106)]
	public virtual extern void LoadAsText([MarshalAs(UnmanagedType.BStr)] string sVData);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(107)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string SaveAsText();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(108)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string GetBookmarkList();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(109)]
	public virtual extern void GotoBookmark([MarshalAs(UnmanagedType.BStr)] string sName);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(110)]
	public virtual extern void AddBookmark([MarshalAs(UnmanagedType.LPStr)] string strName);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(111)]
	public virtual extern void DeleteBookmark([MarshalAs(UnmanagedType.LPStr)] string strName);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(112)]
	public virtual extern short GetTextColorIndex();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(113)]
	public virtual extern void SetTextColorIndex(short curIndex);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(114)]
	public virtual extern short GetColorFillCurIndex();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(115)]
	public virtual extern short GetLineWeightCurIndex();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(116)]
	public virtual extern void SetLineWeightCurIndex(short curIndex);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(117)]
	public virtual extern void SelectObject2([MarshalAs(UnmanagedType.BStr)] string sName, int oclass, int bCenterView, int bZoomView);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(118)]
	public virtual extern bool GetSelectedDrawAttributes(ref int lineColor, ref int fillColor, ref int outline, ref int filled, ref int lineStyle, ref int lineWidth);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(119)]
	public virtual extern void SetSelectedDrawAttributes(int lineColor, int fillColor, int outline, int filled, int lineStyle, int lineWidth);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(120)]
	public virtual extern bool GetSelectedStreamAttributes(ref int useDefault, ref int lineColor, ref int lineStyle, ref int lineWidth);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(121)]
	public virtual extern void SetSelectedStreamAttributes(int useDefault, int lineColor, int lineStyle, int lineWidth);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(122)]
	public virtual extern bool GetObjectTypeSelected(int type);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(123)]
	public virtual extern void ScrollBigStep(int bHorizontal, short zDelta);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(124)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string GetFontName();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(125)]
	public virtual extern void SetFontName([MarshalAs(UnmanagedType.LPWStr)] string pszFontName);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(126)]
	public virtual extern void SetStopCursor();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(127)]
	public virtual extern void ClearStopCursor();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(128)]
	public virtual extern void SetDocumentPtr(ulong lpDocument);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(129)]
	public virtual extern bool DoActiveSelectedModel();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(130)]
	public virtual extern void PfsLButtonDown(int x, int y, int iMouseType);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(131)]
	public virtual extern void CancelInsertMode();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(132)]
	public virtual extern bool GetMultipleObjectSelected();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(133)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string GetSettings();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(134)]
	public virtual extern void SetSettings([MarshalAs(UnmanagedType.BStr)] string sSettings);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(135)]
	public virtual extern void UpdateTooltipText([MarshalAs(UnmanagedType.LPStr)] string strObjectsID, [MarshalAs(UnmanagedType.LPStr)] string strDescriptions);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(136)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string GetSelectedObjectsPath();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(137)]
	public virtual extern void InsertWPFForm([MarshalAs(UnmanagedType.IUnknown)] object lpCtrl, [MarshalAs(UnmanagedType.IUnknown)] object lpImg, bool bShowAsIcon, [MarshalAs(UnmanagedType.LPWStr)] string pszPath, [MarshalAs(UnmanagedType.LPWStr)] string pszFormType, int iTarget, int nWidth, int nHeight);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(138)]
	public virtual extern void LoadWPFForm([MarshalAs(UnmanagedType.IUnknown)] object lpCtrl, [MarshalAs(UnmanagedType.IUnknown)] object lpImg, int nWidth, int nHeight);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(139)]
	public virtual extern void ZoomWPFForm(double dFactor);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(140)]
	public virtual extern void UpdateAXObjPath([MarshalAs(UnmanagedType.LPWStr)] string pszOldPath, [MarshalAs(UnmanagedType.LPWStr)] string pszNewPath, int iType);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(141)]
	public virtual extern void DeleteAXObj([MarshalAs(UnmanagedType.LPWStr)] string pszPath, int iType);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(142)]
	public virtual extern void FitWPFFormToContent([MarshalAs(UnmanagedType.LPWStr)] string pszPath, int iType);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(143)]
	public virtual extern void EmbeddedWPFFormUpdateData();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(144)]
	public virtual extern void SetObjectDescriptionText([MarshalAs(UnmanagedType.LPStr)] string strID, [MarshalAs(UnmanagedType.LPStr)] string strDescriptionText);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(145)]
	public virtual extern void ResetFocus();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(146)]
	public virtual extern void VerifyGrid(float fGridResolution, bool bViewGrid);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(147)]
	public virtual extern void ClearHistory();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(148)]
	public virtual extern bool GetMultipleBlockObjectSelected();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(149)]
	public virtual extern float GetZoomLevel();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(150)]
	public virtual extern bool GetBlockPosition([MarshalAs(UnmanagedType.LPStr)] string sName, ref float x, ref float y);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(151)]
	public virtual extern bool GetBlockSize([MarshalAs(UnmanagedType.LPStr)] string sName, ref float left, ref float right, ref float top, ref float bottom);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(152)]
	public virtual extern bool FocusInTextEdit();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(153)]
	public virtual extern void SetPSVMode(bool bFlag);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(154)]
	public virtual extern void SetInsertPSVBlockFlag();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(155)]
	public virtual extern void SetPSVModelType([MarshalAs(UnmanagedType.IUnknown)] object pPSVBlockModelType, [MarshalAs(UnmanagedType.IUnknown)] object pPSVStreamModelType);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(156)]
	public virtual extern void RestorePSVStreamRoute();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(157)]
	public virtual extern void SetStreamPSVName([MarshalAs(UnmanagedType.LPWStr)] string pszStreamFullPath, [MarshalAs(UnmanagedType.LPWStr)] string pszPSVName);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(158)]
	public virtual extern void SynchronizePSVConnectivity([MarshalAs(UnmanagedType.LPWStr)] string pszStreamID, [MarshalAs(UnmanagedType.LPWStr)] string pszPSVName);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(159)]
	public virtual extern void DeletePSVBlock([MarshalAs(UnmanagedType.LPWStr)] string pszStreamID, [MarshalAs(UnmanagedType.LPWStr)] string pszPSVName);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(160)]
	public virtual extern void RenamePSVBlock([MarshalAs(UnmanagedType.LPWStr)] string pszStreamID, [MarshalAs(UnmanagedType.LPWStr)] string pszPSVOldName, [MarshalAs(UnmanagedType.LPWStr)] string pszPSVNewName);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(161)]
	public virtual extern void SetPSVObjectType(int iPSVObjectType);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(162)]
	public virtual extern void SetPSVBlockDescription(int iBlockType, [MarshalAs(UnmanagedType.LPWStr)] string pszBlockName, [MarshalAs(UnmanagedType.LPWStr)] string pszDescription);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(163)]
	public virtual extern void SetPSVBlockType([MarshalAs(UnmanagedType.LPWStr)] string pszBlocksIDtoType);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(164)]
	public virtual extern void SetPSVBlockErrorLevelAndMessage([MarshalAs(UnmanagedType.LPStr)] string pszPSVBlockID, int iErrorLevel, [MarshalAs(UnmanagedType.LPStr)] string pszMsg);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(165)]
	public virtual extern void ResetDOFIndicators();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(166)]
	public virtual extern void RedrawStreams([MarshalAs(UnmanagedType.LPStr)] string pszStreamNames, int iQueryLineStyle);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(167)]
	public virtual extern void ClearEmbeddedWPFForms();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(168)]
	public virtual extern void ClearAndResetEmbeddedWPFForms();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(169)]
	public virtual extern void SaveEmbeddedWPFForms();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(170)]
	public virtual extern int FocusWPFFormIfExists([MarshalAs(UnmanagedType.LPStr)] string pszID, int iType);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(171)]
	public virtual extern bool GetPSVMode();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(172)]
	public virtual extern void SetBatchMode(bool bFlag);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(173)]
	public virtual extern void RefreshBlock([MarshalAs(UnmanagedType.LPStr)] string pszBlockID);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(174)]
	public virtual extern void SetSimulationRunState(bool bIsRunning);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(175)]
	public virtual extern void RefreshStreamGroups(bool bAllFlowsheets, [MarshalAs(UnmanagedType.LPStr)] string pszStreamIDList);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(176)]
	public virtual extern void UpdateAnnotationsOnFlowSheet();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-552)]
	public virtual extern void AboutBox();
}
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
// All 41 TlbImp delegates define only .ctor(object, native unsigned int) and a PreserveSig Invoke.
// Their original ABI is in the accompanying metadata; normal C# delegate emission has a different CLR shape.
[ComVisible(false)]
public delegate void _DPfsctrlEvents_DoOleVerbEventHandler([MarshalAs(UnmanagedType.IUnknown)] object pOleObj, int nID);
[ComVisible(false)]
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
public delegate void _DPfsctrlEvents_InvokeMenuItemEventHandler(int nCommand);
[ComVisible(false)]
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
public delegate void _DPfsctrlEvents_SelectPrinterEventHandler([ComAliasName("stdole.OLE_HANDLE")] int DevNames, [ComAliasName("stdole.OLE_HANDLE")] int DevMode);
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
[ComVisible(false)]
public delegate void _DPfsctrlEvents_OnFIlePrintEventHandler();
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
[ComVisible(false)]
public delegate void _DPfsctrlEvents_SetMessageTextEventHandler([MarshalAs(UnmanagedType.BStr)] string text);
[ComVisible(false)]
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
public delegate void _DPfsctrlEvents_DrawToolbarEventHandler(bool bON);
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
[ComVisible(false)]
public delegate void _DPfsctrlEvents_ModifiedEventHandler();
[ComVisible(false)]
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
public delegate void _DPfsctrlEvents_OnSelectEventHandler(short type, [MarshalAs(UnmanagedType.BStr)] string ID);
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
[ComVisible(false)]
public delegate void _DPfsctrlEvents_OnDoubleClickEventHandler(short type, [MarshalAs(UnmanagedType.BStr)] string ID);
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
[ComVisible(false)]
public delegate void _DPfsctrlEvents_UpdateSettingsEventHandler(int lHint);
[ComVisible(false)]
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
public delegate void _DPfsctrlEvents_PfsToolbarEventHandler(bool bON);
[ComVisible(false)]
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
public delegate void _DPfsctrlEvents_OnDoubleClick2EventHandler(short type, [MarshalAs(UnmanagedType.BStr)] string ID, [MarshalAs(UnmanagedType.BStr)] string ModelType);
[ComVisible(false)]
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
public delegate void _DPfsctrlEvents_OnCancelInsertModeEventHandler();
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
[ComVisible(false)]
public delegate void _DPfsctrlEvents_ModelUpdateEventHandler([MarshalAs(UnmanagedType.BStr)] string ID, [MarshalAs(UnmanagedType.BStr)] string ModelType);
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
[ComVisible(false)]
public delegate void _DPfsctrlEvents_BeforeRenameModelEventHandler([MarshalAs(UnmanagedType.BStr)] string ID);
[ComVisible(false)]
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
public delegate void _DPfsctrlEvents_OnCancelLibBarHalfStreamInsertModeEventHandler();
[ComVisible(false)]
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
public delegate void _DPfsctrlEvents_OnZoomChangedEventHandler(float oldScale, float newScale);
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
[ComVisible(false)]
public delegate void _DPfsctrlEvents_ManageViewChangedEventHandler();
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
[ComVisible(false)]
public delegate void _DPfsctrlEvents_UndoRedoChangedEventHandler();
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
[ComVisible(false)]
public delegate void _DPfsctrlEvents_LoadingWPFFormEventHandler([MarshalAs(UnmanagedType.BStr)] string bstrPath, int iFormType, int iTargetClass);
[ComVisible(false)]
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
public delegate void _DPfsctrlEvents_DeleteWPFFormEventHandler([MarshalAs(UnmanagedType.BStr)] string bstrPath, [MarshalAs(UnmanagedType.BStr)] string bstrFormType);
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
[ComVisible(false)]
public delegate void _DPfsctrlEvents_GetObjectDescriptionTextEventHandler([MarshalAs(UnmanagedType.BStr)] string bstrPath, int nObjectType);
[ComVisible(false)]
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
public delegate void _DPfsctrlEvents_BlockVisibleChangingEventHandler([MarshalAs(UnmanagedType.BStr)] string bstrType);
[ComVisible(false)]
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
public delegate void _DPfsctrlEvents_OnDropFilesEventHandler([MarshalAs(UnmanagedType.BStr)] string varFiles);
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
[ComVisible(false)]
public delegate void _DPfsctrlEvents_UpdateFlipRotateStatusEventHandler();
[ComVisible(false)]
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
public delegate void _DPfsctrlEvents_DeleteBlockObjectEventHandler([MarshalAs(UnmanagedType.BStr)] string bstrID, [MarshalAs(UnmanagedType.BStr)] string bstrObjectType);
[ComVisible(false)]
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
public delegate void _DPfsctrlEvents_RenameBlockObjectEventHandler([MarshalAs(UnmanagedType.BStr)] string bstrOldName, [MarshalAs(UnmanagedType.BStr)] string bstrNewName, [MarshalAs(UnmanagedType.BStr)] string bstrObjectType);
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
[ComVisible(false)]
public delegate void _DPfsctrlEvents_PSVAttachedPSVToStreamEventHandler([MarshalAs(UnmanagedType.BStr)] string bstrStreamFullPath, [MarshalAs(UnmanagedType.BStr)] string bstrPSVName);
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
[ComVisible(false)]
public delegate void _DPfsctrlEvents_BeginInsertPSVBlockEventHandler();
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
[ComVisible(false)]
public delegate void _DPfsctrlEvents_FinishInsertPSVBlockEventHandler();
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
[ComVisible(false)]
public delegate void _DPfsctrlEvents_GetStreamPSVNameEventHandler([MarshalAs(UnmanagedType.BStr)] string bstrStreamFullPath, int iObjectType);
[ComVisible(false)]
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
public delegate void _DPfsctrlEvents_OnDeletePSVBlockEventHandler([MarshalAs(UnmanagedType.BStr)] string bstrStreamID, [MarshalAs(UnmanagedType.BStr)] string bstrPSVName);
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
[ComVisible(false)]
public delegate void _DPfsctrlEvents_OnAddPSVBlockEventHandler([MarshalAs(UnmanagedType.BStr)] string bstrStreamFullPath, int iPSVObjectType);
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
[ComVisible(false)]
public delegate void _DPfsctrlEvents_OnGetPSVBlockDescriptionEventHandler(int iBlockType, [MarshalAs(UnmanagedType.BStr)] string bstrBlockName);
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
[ComVisible(false)]
public delegate void _DPfsctrlEvents_OnRequestPSVBlockTypeEventHandler([MarshalAs(UnmanagedType.BStr)] string bstrPSVBlockIDs);
[ComVisible(false)]
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
public delegate void _DPfsctrlEvents_OnPSVBlockExchangeTypeEventHandler([MarshalAs(UnmanagedType.BStr)] string bstrPSVBlockID, int iOldType, int iNewType);
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
[ComVisible(false)]
public delegate void _DPfsctrlEvents_OnGetPSVBlockErrorLevelEventHandler([MarshalAs(UnmanagedType.BStr)] string bstrPSVBlockID);
[ComVisible(false)]
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
public delegate void _DPfsctrlEvents_CreateBlockEventHandler([MarshalAs(UnmanagedType.BStr)] string bstrBlockID, [MarshalAs(UnmanagedType.BStr)] string bstrBlockType);
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
[ComVisible(false)]
public delegate void _DPfsctrlEvents_OnEditStreamSummaryFormEventHandler([MarshalAs(UnmanagedType.BStr)] string bstrObjectName, int iTargetObjectClass);
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
[ComVisible(false)]
public delegate void _DPfsctrlEvents_CreateStreamEventHandler([MarshalAs(UnmanagedType.BStr)] string strStreamID, [MarshalAs(UnmanagedType.BStr)] string strStreamType, [MarshalAs(UnmanagedType.BStr)] string conectBlock1, [MarshalAs(UnmanagedType.BStr)] string conectBlock2);
[ComVisible(false)]
// Original delegate TypeDef carries [TypeLibType(TypeLibTypeFlags.FHidden)]; C# disallows that attribute target.
public delegate void _DPfsctrlEvents_ScanConnectEventHandler([MarshalAs(UnmanagedType.BStr)] string streamName, [MarshalAs(UnmanagedType.BStr)] string blockName, [MarshalAs(UnmanagedType.BStr)] string connectType, int direction);
[TypeLibType(TypeLibTypeFlags.FHidden)]
[ClassInterface(ClassInterfaceType.None)]
public sealed class _DPfsctrlEvents_SinkHelper : _DPfsctrlEvents
{
	public _DPfsctrlEvents_DoOleVerbEventHandler m_DoOleVerbDelegate;

	public _DPfsctrlEvents_InvokeMenuItemEventHandler m_InvokeMenuItemDelegate;

	public _DPfsctrlEvents_SelectPrinterEventHandler m_SelectPrinterDelegate;

	public _DPfsctrlEvents_OnFIlePrintEventHandler m_OnFIlePrintDelegate;

	public _DPfsctrlEvents_SetMessageTextEventHandler m_SetMessageTextDelegate;

	public _DPfsctrlEvents_DrawToolbarEventHandler m_DrawToolbarDelegate;

	public _DPfsctrlEvents_ModifiedEventHandler m_ModifiedDelegate;

	public _DPfsctrlEvents_OnSelectEventHandler m_OnSelectDelegate;

	public _DPfsctrlEvents_OnDoubleClickEventHandler m_OnDoubleClickDelegate;

	public _DPfsctrlEvents_UpdateSettingsEventHandler m_UpdateSettingsDelegate;

	public _DPfsctrlEvents_PfsToolbarEventHandler m_PfsToolbarDelegate;

	public _DPfsctrlEvents_OnDoubleClick2EventHandler m_OnDoubleClick2Delegate;

	public _DPfsctrlEvents_OnCancelInsertModeEventHandler m_OnCancelInsertModeDelegate;

	public _DPfsctrlEvents_ModelUpdateEventHandler m_ModelUpdateDelegate;

	public _DPfsctrlEvents_BeforeRenameModelEventHandler m_BeforeRenameModelDelegate;

	public _DPfsctrlEvents_OnCancelLibBarHalfStreamInsertModeEventHandler m_OnCancelLibBarHalfStreamInsertModeDelegate;

	public _DPfsctrlEvents_OnZoomChangedEventHandler m_OnZoomChangedDelegate;

	public _DPfsctrlEvents_ManageViewChangedEventHandler m_ManageViewChangedDelegate;

	public _DPfsctrlEvents_UndoRedoChangedEventHandler m_UndoRedoChangedDelegate;

	public _DPfsctrlEvents_LoadingWPFFormEventHandler m_LoadingWPFFormDelegate;

	public _DPfsctrlEvents_DeleteWPFFormEventHandler m_DeleteWPFFormDelegate;

	public _DPfsctrlEvents_GetObjectDescriptionTextEventHandler m_GetObjectDescriptionTextDelegate;

	public _DPfsctrlEvents_BlockVisibleChangingEventHandler m_BlockVisibleChangingDelegate;

	public _DPfsctrlEvents_OnDropFilesEventHandler m_OnDropFilesDelegate;

	public _DPfsctrlEvents_UpdateFlipRotateStatusEventHandler m_UpdateFlipRotateStatusDelegate;

	public _DPfsctrlEvents_DeleteBlockObjectEventHandler m_DeleteBlockObjectDelegate;

	public _DPfsctrlEvents_RenameBlockObjectEventHandler m_RenameBlockObjectDelegate;

	public _DPfsctrlEvents_PSVAttachedPSVToStreamEventHandler m_PSVAttachedPSVToStreamDelegate;

	public _DPfsctrlEvents_BeginInsertPSVBlockEventHandler m_BeginInsertPSVBlockDelegate;

	public _DPfsctrlEvents_FinishInsertPSVBlockEventHandler m_FinishInsertPSVBlockDelegate;

	public _DPfsctrlEvents_GetStreamPSVNameEventHandler m_GetStreamPSVNameDelegate;

	public _DPfsctrlEvents_OnDeletePSVBlockEventHandler m_OnDeletePSVBlockDelegate;

	public _DPfsctrlEvents_OnAddPSVBlockEventHandler m_OnAddPSVBlockDelegate;

	public _DPfsctrlEvents_OnGetPSVBlockDescriptionEventHandler m_OnGetPSVBlockDescriptionDelegate;

	public _DPfsctrlEvents_OnRequestPSVBlockTypeEventHandler m_OnRequestPSVBlockTypeDelegate;

	public _DPfsctrlEvents_OnPSVBlockExchangeTypeEventHandler m_OnPSVBlockExchangeTypeDelegate;

	public _DPfsctrlEvents_OnGetPSVBlockErrorLevelEventHandler m_OnGetPSVBlockErrorLevelDelegate;

	public _DPfsctrlEvents_CreateBlockEventHandler m_CreateBlockDelegate;

	public _DPfsctrlEvents_OnEditStreamSummaryFormEventHandler m_OnEditStreamSummaryFormDelegate;

	public _DPfsctrlEvents_CreateStreamEventHandler m_CreateStreamDelegate;

	public _DPfsctrlEvents_ScanConnectEventHandler m_ScanConnectDelegate;

	public int m_dwCookie;

	public void DoOleVerb(object P_0, int P_1)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_DoOleVerbDelegate != null)
		{
			m_DoOleVerbDelegate(P_0, P_1);
		}
	}

	public void InvokeMenuItem(int P_0)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_InvokeMenuItemDelegate != null)
		{
			m_InvokeMenuItemDelegate(P_0);
		}
	}

	public void SelectPrinter(int P_0, int P_1)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_SelectPrinterDelegate != null)
		{
			m_SelectPrinterDelegate(P_0, P_1);
		}
	}

	public void OnFIlePrint()
	{
		// The original local signature encodes zero slots (07 00).
		if (m_OnFIlePrintDelegate != null)
		{
			m_OnFIlePrintDelegate();
		}
	}

	public void SetMessageText(string P_0)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_SetMessageTextDelegate != null)
		{
			m_SetMessageTextDelegate(P_0);
		}
	}

	public void DrawToolbar(bool P_0)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_DrawToolbarDelegate != null)
		{
			m_DrawToolbarDelegate(P_0);
		}
	}

	public void Modified()
	{
		// The original local signature encodes zero slots (07 00).
		if (m_ModifiedDelegate != null)
		{
			m_ModifiedDelegate();
		}
	}

	public void OnSelect(short P_0, string P_1)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_OnSelectDelegate != null)
		{
			m_OnSelectDelegate(P_0, P_1);
		}
	}

	public void OnDoubleClick(short P_0, string P_1)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_OnDoubleClickDelegate != null)
		{
			m_OnDoubleClickDelegate(P_0, P_1);
		}
	}

	public void UpdateSettings(int P_0)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_UpdateSettingsDelegate != null)
		{
			m_UpdateSettingsDelegate(P_0);
		}
	}

	public void PfsToolbar(bool P_0)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_PfsToolbarDelegate != null)
		{
			m_PfsToolbarDelegate(P_0);
		}
	}

	public void OnDoubleClick2(short P_0, string P_1, string P_2)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_OnDoubleClick2Delegate != null)
		{
			m_OnDoubleClick2Delegate(P_0, P_1, P_2);
		}
	}

	public void OnCancelInsertMode()
	{
		// The original local signature encodes zero slots (07 00).
		if (m_OnCancelInsertModeDelegate != null)
		{
			m_OnCancelInsertModeDelegate();
		}
	}

	public void ModelUpdate(string P_0, string P_1)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_ModelUpdateDelegate != null)
		{
			m_ModelUpdateDelegate(P_0, P_1);
		}
	}

	public void BeforeRenameModel(string P_0)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_BeforeRenameModelDelegate != null)
		{
			m_BeforeRenameModelDelegate(P_0);
		}
	}

	public void OnCancelLibBarHalfStreamInsertMode()
	{
		// The original local signature encodes zero slots (07 00).
		if (m_OnCancelLibBarHalfStreamInsertModeDelegate != null)
		{
			m_OnCancelLibBarHalfStreamInsertModeDelegate();
		}
	}

	public void OnZoomChanged(float P_0, float P_1)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_OnZoomChangedDelegate != null)
		{
			m_OnZoomChangedDelegate(P_0, P_1);
		}
	}

	public void ManageViewChanged()
	{
		// The original local signature encodes zero slots (07 00).
		if (m_ManageViewChangedDelegate != null)
		{
			m_ManageViewChangedDelegate();
		}
	}

	public void UndoRedoChanged()
	{
		// The original local signature encodes zero slots (07 00).
		if (m_UndoRedoChangedDelegate != null)
		{
			m_UndoRedoChangedDelegate();
		}
	}

	public void LoadingWPFForm(string P_0, int P_1, int P_2)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_LoadingWPFFormDelegate != null)
		{
			m_LoadingWPFFormDelegate(P_0, P_1, P_2);
		}
	}

	public void DeleteWPFForm(string P_0, string P_1)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_DeleteWPFFormDelegate != null)
		{
			m_DeleteWPFFormDelegate(P_0, P_1);
		}
	}

	public void GetObjectDescriptionText(string P_0, int P_1)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_GetObjectDescriptionTextDelegate != null)
		{
			m_GetObjectDescriptionTextDelegate(P_0, P_1);
		}
	}

	public void BlockVisibleChanging(string P_0)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_BlockVisibleChangingDelegate != null)
		{
			m_BlockVisibleChangingDelegate(P_0);
		}
	}

	public void OnDropFiles(string P_0)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_OnDropFilesDelegate != null)
		{
			m_OnDropFilesDelegate(P_0);
		}
	}

	public void UpdateFlipRotateStatus()
	{
		// The original local signature encodes zero slots (07 00).
		if (m_UpdateFlipRotateStatusDelegate != null)
		{
			m_UpdateFlipRotateStatusDelegate();
		}
	}

	public void DeleteBlockObject(string P_0, string P_1)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_DeleteBlockObjectDelegate != null)
		{
			m_DeleteBlockObjectDelegate(P_0, P_1);
		}
	}

	public void RenameBlockObject(string P_0, string P_1, string P_2)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_RenameBlockObjectDelegate != null)
		{
			m_RenameBlockObjectDelegate(P_0, P_1, P_2);
		}
	}

	public void PSVAttachedPSVToStream(string P_0, string P_1)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_PSVAttachedPSVToStreamDelegate != null)
		{
			m_PSVAttachedPSVToStreamDelegate(P_0, P_1);
		}
	}

	public void BeginInsertPSVBlock()
	{
		// The original local signature encodes zero slots (07 00).
		if (m_BeginInsertPSVBlockDelegate != null)
		{
			m_BeginInsertPSVBlockDelegate();
		}
	}

	public void FinishInsertPSVBlock()
	{
		// The original local signature encodes zero slots (07 00).
		if (m_FinishInsertPSVBlockDelegate != null)
		{
			m_FinishInsertPSVBlockDelegate();
		}
	}

	public void GetStreamPSVName(string P_0, int P_1)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_GetStreamPSVNameDelegate != null)
		{
			m_GetStreamPSVNameDelegate(P_0, P_1);
		}
	}

	public void OnDeletePSVBlock(string P_0, string P_1)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_OnDeletePSVBlockDelegate != null)
		{
			m_OnDeletePSVBlockDelegate(P_0, P_1);
		}
	}

	public void OnAddPSVBlock(string P_0, int P_1)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_OnAddPSVBlockDelegate != null)
		{
			m_OnAddPSVBlockDelegate(P_0, P_1);
		}
	}

	public void OnGetPSVBlockDescription(int P_0, string P_1)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_OnGetPSVBlockDescriptionDelegate != null)
		{
			m_OnGetPSVBlockDescriptionDelegate(P_0, P_1);
		}
	}

	public void OnRequestPSVBlockType(string P_0)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_OnRequestPSVBlockTypeDelegate != null)
		{
			m_OnRequestPSVBlockTypeDelegate(P_0);
		}
	}

	public void OnPSVBlockExchangeType(string P_0, int P_1, int P_2)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_OnPSVBlockExchangeTypeDelegate != null)
		{
			m_OnPSVBlockExchangeTypeDelegate(P_0, P_1, P_2);
		}
	}

	public void OnGetPSVBlockErrorLevel(string P_0)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_OnGetPSVBlockErrorLevelDelegate != null)
		{
			m_OnGetPSVBlockErrorLevelDelegate(P_0);
		}
	}

	public void CreateBlock(string P_0, string P_1)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_CreateBlockDelegate != null)
		{
			m_CreateBlockDelegate(P_0, P_1);
		}
	}

	public void OnEditStreamSummaryForm(string P_0, int P_1)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_OnEditStreamSummaryFormDelegate != null)
		{
			m_OnEditStreamSummaryFormDelegate(P_0, P_1);
		}
	}

	public void CreateStream(string P_0, string P_1, string P_2, string P_3)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_CreateStreamDelegate != null)
		{
			m_CreateStreamDelegate(P_0, P_1, P_2, P_3);
		}
	}

	public void ScanConnect(string P_0, string P_1, string P_2, int P_3)
	{
		// The original local signature encodes zero slots (07 00).
		if (m_ScanConnectDelegate != null)
		{
			m_ScanConnectDelegate(P_0, P_1, P_2, P_3);
		}
	}

	internal _DPfsctrlEvents_SinkHelper()
	{
		// The original local signature encodes zero slots (07 00).
		m_dwCookie = 0;
		m_DoOleVerbDelegate = null;
		m_InvokeMenuItemDelegate = null;
		m_SelectPrinterDelegate = null;
		m_OnFIlePrintDelegate = null;
		m_SetMessageTextDelegate = null;
		m_DrawToolbarDelegate = null;
		m_ModifiedDelegate = null;
		m_OnSelectDelegate = null;
		m_OnDoubleClickDelegate = null;
		m_UpdateSettingsDelegate = null;
		m_PfsToolbarDelegate = null;
		m_OnDoubleClick2Delegate = null;
		m_OnCancelInsertModeDelegate = null;
		m_ModelUpdateDelegate = null;
		m_BeforeRenameModelDelegate = null;
		m_OnCancelLibBarHalfStreamInsertModeDelegate = null;
		m_OnZoomChangedDelegate = null;
		m_ManageViewChangedDelegate = null;
		m_UndoRedoChangedDelegate = null;
		m_LoadingWPFFormDelegate = null;
		m_DeleteWPFFormDelegate = null;
		m_GetObjectDescriptionTextDelegate = null;
		m_BlockVisibleChangingDelegate = null;
		m_OnDropFilesDelegate = null;
		m_UpdateFlipRotateStatusDelegate = null;
		m_DeleteBlockObjectDelegate = null;
		m_RenameBlockObjectDelegate = null;
		m_PSVAttachedPSVToStreamDelegate = null;
		m_BeginInsertPSVBlockDelegate = null;
		m_FinishInsertPSVBlockDelegate = null;
		m_GetStreamPSVNameDelegate = null;
		m_OnDeletePSVBlockDelegate = null;
		m_OnAddPSVBlockDelegate = null;
		m_OnGetPSVBlockDescriptionDelegate = null;
		m_OnRequestPSVBlockTypeDelegate = null;
		m_OnPSVBlockExchangeTypeDelegate = null;
		m_OnGetPSVBlockErrorLevelDelegate = null;
		m_CreateBlockDelegate = null;
		m_OnEditStreamSummaryFormDelegate = null;
		m_CreateStreamDelegate = null;
		m_ScanConnectDelegate = null;
	}
}
internal sealed class _DPfsctrlEvents_EventProvider : _DPfsctrlEvents_Event, IDisposable
{
	private WeakReference m_wkConnectionPointContainer;

	private ArrayList m_aEventSinkHelpers;

	private IConnectionPoint m_ConnectionPoint;

	private void Init()
	{
		IConnectionPoint ppCP = null;
		Guid riid = new Guid(new byte[16]
		{
			86, 32, 209, 254, 12, 23, 0, 65, 156, 62,
			166, 195, 48, 98, 251, 176
		});
		((IConnectionPointContainer)m_wkConnectionPointContainer.Target).FindConnectionPoint(ref riid, out ppCP);
		m_ConnectionPoint = ppCP;
		m_aEventSinkHelpers = new ArrayList();
	}

	public event _DPfsctrlEvents_DoOleVerbEventHandler DoOleVerb
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_DoOleVerbDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_DoOleVerbDelegate != null && ((dPfsctrlEvents_SinkHelper.m_DoOleVerbDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_InvokeMenuItemEventHandler InvokeMenuItem
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_InvokeMenuItemDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_InvokeMenuItemDelegate != null && ((dPfsctrlEvents_SinkHelper.m_InvokeMenuItemDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_SelectPrinterEventHandler SelectPrinter
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_SelectPrinterDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_SelectPrinterDelegate != null && ((dPfsctrlEvents_SinkHelper.m_SelectPrinterDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_OnFIlePrintEventHandler OnFIlePrint
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_OnFIlePrintDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_OnFIlePrintDelegate != null && ((dPfsctrlEvents_SinkHelper.m_OnFIlePrintDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_SetMessageTextEventHandler SetMessageText
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_SetMessageTextDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_SetMessageTextDelegate != null && ((dPfsctrlEvents_SinkHelper.m_SetMessageTextDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_DrawToolbarEventHandler DrawToolbar
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_DrawToolbarDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_DrawToolbarDelegate != null && ((dPfsctrlEvents_SinkHelper.m_DrawToolbarDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_ModifiedEventHandler Modified
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_ModifiedDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_ModifiedDelegate != null && ((dPfsctrlEvents_SinkHelper.m_ModifiedDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_OnSelectEventHandler OnSelect
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_OnSelectDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_OnSelectDelegate != null && ((dPfsctrlEvents_SinkHelper.m_OnSelectDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_OnDoubleClickEventHandler OnDoubleClick
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_OnDoubleClickDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_OnDoubleClickDelegate != null && ((dPfsctrlEvents_SinkHelper.m_OnDoubleClickDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_UpdateSettingsEventHandler UpdateSettings
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_UpdateSettingsDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_UpdateSettingsDelegate != null && ((dPfsctrlEvents_SinkHelper.m_UpdateSettingsDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_PfsToolbarEventHandler PfsToolbar
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_PfsToolbarDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_PfsToolbarDelegate != null && ((dPfsctrlEvents_SinkHelper.m_PfsToolbarDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_OnDoubleClick2EventHandler OnDoubleClick2
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_OnDoubleClick2Delegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_OnDoubleClick2Delegate != null && ((dPfsctrlEvents_SinkHelper.m_OnDoubleClick2Delegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_OnCancelInsertModeEventHandler OnCancelInsertMode
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_OnCancelInsertModeDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_OnCancelInsertModeDelegate != null && ((dPfsctrlEvents_SinkHelper.m_OnCancelInsertModeDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_ModelUpdateEventHandler ModelUpdate
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_ModelUpdateDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_ModelUpdateDelegate != null && ((dPfsctrlEvents_SinkHelper.m_ModelUpdateDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_BeforeRenameModelEventHandler BeforeRenameModel
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_BeforeRenameModelDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_BeforeRenameModelDelegate != null && ((dPfsctrlEvents_SinkHelper.m_BeforeRenameModelDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_OnCancelLibBarHalfStreamInsertModeEventHandler OnCancelLibBarHalfStreamInsertMode
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_OnCancelLibBarHalfStreamInsertModeDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_OnCancelLibBarHalfStreamInsertModeDelegate != null && ((dPfsctrlEvents_SinkHelper.m_OnCancelLibBarHalfStreamInsertModeDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_OnZoomChangedEventHandler OnZoomChanged
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_OnZoomChangedDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_OnZoomChangedDelegate != null && ((dPfsctrlEvents_SinkHelper.m_OnZoomChangedDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_ManageViewChangedEventHandler ManageViewChanged
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_ManageViewChangedDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_ManageViewChangedDelegate != null && ((dPfsctrlEvents_SinkHelper.m_ManageViewChangedDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_UndoRedoChangedEventHandler UndoRedoChanged
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_UndoRedoChangedDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_UndoRedoChangedDelegate != null && ((dPfsctrlEvents_SinkHelper.m_UndoRedoChangedDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_LoadingWPFFormEventHandler LoadingWPFForm
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_LoadingWPFFormDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_LoadingWPFFormDelegate != null && ((dPfsctrlEvents_SinkHelper.m_LoadingWPFFormDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_DeleteWPFFormEventHandler DeleteWPFForm
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_DeleteWPFFormDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_DeleteWPFFormDelegate != null && ((dPfsctrlEvents_SinkHelper.m_DeleteWPFFormDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_GetObjectDescriptionTextEventHandler GetObjectDescriptionText
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_GetObjectDescriptionTextDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_GetObjectDescriptionTextDelegate != null && ((dPfsctrlEvents_SinkHelper.m_GetObjectDescriptionTextDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_BlockVisibleChangingEventHandler BlockVisibleChanging
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_BlockVisibleChangingDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_BlockVisibleChangingDelegate != null && ((dPfsctrlEvents_SinkHelper.m_BlockVisibleChangingDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_OnDropFilesEventHandler OnDropFiles
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_OnDropFilesDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_OnDropFilesDelegate != null && ((dPfsctrlEvents_SinkHelper.m_OnDropFilesDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_UpdateFlipRotateStatusEventHandler UpdateFlipRotateStatus
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_UpdateFlipRotateStatusDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_UpdateFlipRotateStatusDelegate != null && ((dPfsctrlEvents_SinkHelper.m_UpdateFlipRotateStatusDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_DeleteBlockObjectEventHandler DeleteBlockObject
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_DeleteBlockObjectDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_DeleteBlockObjectDelegate != null && ((dPfsctrlEvents_SinkHelper.m_DeleteBlockObjectDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_RenameBlockObjectEventHandler RenameBlockObject
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_RenameBlockObjectDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_RenameBlockObjectDelegate != null && ((dPfsctrlEvents_SinkHelper.m_RenameBlockObjectDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_PSVAttachedPSVToStreamEventHandler PSVAttachedPSVToStream
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_PSVAttachedPSVToStreamDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_PSVAttachedPSVToStreamDelegate != null && ((dPfsctrlEvents_SinkHelper.m_PSVAttachedPSVToStreamDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_BeginInsertPSVBlockEventHandler BeginInsertPSVBlock
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_BeginInsertPSVBlockDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_BeginInsertPSVBlockDelegate != null && ((dPfsctrlEvents_SinkHelper.m_BeginInsertPSVBlockDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_FinishInsertPSVBlockEventHandler FinishInsertPSVBlock
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_FinishInsertPSVBlockDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_FinishInsertPSVBlockDelegate != null && ((dPfsctrlEvents_SinkHelper.m_FinishInsertPSVBlockDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_GetStreamPSVNameEventHandler GetStreamPSVName
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_GetStreamPSVNameDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_GetStreamPSVNameDelegate != null && ((dPfsctrlEvents_SinkHelper.m_GetStreamPSVNameDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_OnDeletePSVBlockEventHandler OnDeletePSVBlock
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_OnDeletePSVBlockDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_OnDeletePSVBlockDelegate != null && ((dPfsctrlEvents_SinkHelper.m_OnDeletePSVBlockDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_OnAddPSVBlockEventHandler OnAddPSVBlock
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_OnAddPSVBlockDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_OnAddPSVBlockDelegate != null && ((dPfsctrlEvents_SinkHelper.m_OnAddPSVBlockDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_OnGetPSVBlockDescriptionEventHandler OnGetPSVBlockDescription
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_OnGetPSVBlockDescriptionDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_OnGetPSVBlockDescriptionDelegate != null && ((dPfsctrlEvents_SinkHelper.m_OnGetPSVBlockDescriptionDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_OnRequestPSVBlockTypeEventHandler OnRequestPSVBlockType
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_OnRequestPSVBlockTypeDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_OnRequestPSVBlockTypeDelegate != null && ((dPfsctrlEvents_SinkHelper.m_OnRequestPSVBlockTypeDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_OnPSVBlockExchangeTypeEventHandler OnPSVBlockExchangeType
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_OnPSVBlockExchangeTypeDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_OnPSVBlockExchangeTypeDelegate != null && ((dPfsctrlEvents_SinkHelper.m_OnPSVBlockExchangeTypeDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_OnGetPSVBlockErrorLevelEventHandler OnGetPSVBlockErrorLevel
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_OnGetPSVBlockErrorLevelDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_OnGetPSVBlockErrorLevelDelegate != null && ((dPfsctrlEvents_SinkHelper.m_OnGetPSVBlockErrorLevelDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_CreateBlockEventHandler CreateBlock
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_CreateBlockDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_CreateBlockDelegate != null && ((dPfsctrlEvents_SinkHelper.m_CreateBlockDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_OnEditStreamSummaryFormEventHandler OnEditStreamSummaryForm
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_OnEditStreamSummaryFormDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_OnEditStreamSummaryFormDelegate != null && ((dPfsctrlEvents_SinkHelper.m_OnEditStreamSummaryFormDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_CreateStreamEventHandler CreateStream
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_CreateStreamDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_CreateStreamDelegate != null && ((dPfsctrlEvents_SinkHelper.m_CreateStreamDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public event _DPfsctrlEvents_ScanConnectEventHandler ScanConnect
	{
		add
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_ConnectionPoint == null)
				{
					Init();
				}
				_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = new _DPfsctrlEvents_SinkHelper();
				int pdwCookie = 0;
				m_ConnectionPoint.Advise(dPfsctrlEvents_SinkHelper, out pdwCookie);
				dPfsctrlEvents_SinkHelper.m_dwCookie = pdwCookie;
				dPfsctrlEvents_SinkHelper.m_ScanConnectDelegate = value;
				m_aEventSinkHelpers.Add(dPfsctrlEvents_SinkHelper);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}

		remove
		{
			bool lockTaken = default(bool);
			try
			{
				Monitor.Enter(this, ref lockTaken);
				if (m_aEventSinkHelpers == null)
				{
					return;
				}
				int count = m_aEventSinkHelpers.Count;
				int num = 0;
				if (0 >= count)
				{
					return;
				}
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					if (dPfsctrlEvents_SinkHelper.m_ScanConnectDelegate != null && ((dPfsctrlEvents_SinkHelper.m_ScanConnectDelegate.Equals(value) ? 1u : 0u) & 0xFFu) != 0)
					{
						m_aEventSinkHelpers.RemoveAt(num);
						m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
						if (count <= 1)
						{
							Marshal.ReleaseComObject(m_ConnectionPoint);
							m_ConnectionPoint = null;
							m_aEventSinkHelpers = null;
						}
						break;
					}
					num++;
				}
				while (num < count);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(this);
				}
			}
		}
	}

	public _DPfsctrlEvents_EventProvider(object P_0)
	{
		// The original local signature encodes zero slots (07 00).
		m_wkConnectionPointContainer = new WeakReference((IConnectionPointContainer)P_0, trackResurrection: false);
	}

	// Original public virtual Finalize reuses the Object slot and is also called by Dispose.
	// The original IL has no call to Object.Finalize. The C# destructor adds that implicit base call.
	~_DPfsctrlEvents_EventProvider() { ReleaseConnections(); }
	private void ReleaseConnections()
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				return;
			}
			int count = m_aEventSinkHelpers.Count;
			int num = 0;
			if (0 < count)
			{
				do
				{
					_DPfsctrlEvents_SinkHelper dPfsctrlEvents_SinkHelper = (_DPfsctrlEvents_SinkHelper)m_aEventSinkHelpers[num];
					m_ConnectionPoint.Unadvise(dPfsctrlEvents_SinkHelper.m_dwCookie);
					num++;
				}
				while (num < count);
			}
			Marshal.ReleaseComObject(m_ConnectionPoint);
		}
		catch (Exception)
		{
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void Dispose()
	{
		// The original local signature encodes zero slots (07 00).
		ReleaseConnections();
		GC.SuppressFinalize(this);
	}
}
