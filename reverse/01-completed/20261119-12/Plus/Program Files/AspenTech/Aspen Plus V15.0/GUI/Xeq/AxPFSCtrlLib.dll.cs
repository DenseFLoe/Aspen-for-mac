using System;
using System.ComponentModel;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Windows.Forms;
using PFSCtrlLib;

[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: CompilationRelaxations(8)]
[assembly: AxHost.TypeLibraryTimeStamp("04/14/2025 09:07:39")]
[assembly: AssemblyKeyFile("..\\packages\\AspenTech.StrongName.SNK.1.0.0\\content\\Aspentech.snk")]
[assembly: AssemblyVersion("1.0.0.0")]
namespace AxPFSCtrlLib;

[DefaultEvent("DoOleVerb")]
[Clsid("{20c9d4cd-6c3e-4100-8ee1-b3056237349e}")]
[DesignTimeVisible(true)]
public class AxPfsctrl : AxHost
{
	private _DPfsctrl ocx;

	private AxPfsctrlEventMulticaster eventMulticaster;

	private ConnectionPointCookie cookie;

	[DispId(2)]
	[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
	public virtual short ClientType
	{
		get
		{
			if (ocx == null)
			{
				throw new InvalidActiveXStateException("ClientType", ActiveXInvokeKind.PropertyGet);
			}
			return ocx.ClientType;
		}
		set
		{
			if (ocx == null)
			{
				throw new InvalidActiveXStateException("ClientType", ActiveXInvokeKind.PropertySet);
			}
			ocx.ClientType = value;
		}
	}

	[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
	[DispId(1)]
	public virtual string SourceFile
	{
		get
		{
			if (ocx == null)
			{
				throw new InvalidActiveXStateException("SourceFile", ActiveXInvokeKind.PropertyGet);
			}
			return ocx.SourceFile;
		}
		set
		{
			if (ocx == null)
			{
				throw new InvalidActiveXStateException("SourceFile", ActiveXInvokeKind.PropertySet);
			}
			ocx.SourceFile = value;
		}
	}

	public event _DPfsctrlEvents_DoOleVerbEventHandler DoOleVerb;

	public event _DPfsctrlEvents_InvokeMenuItemEventHandler InvokeMenuItemEvent;

	public event _DPfsctrlEvents_SelectPrinterEventHandler SelectPrinter;

	public event EventHandler OnFIlePrint;

	public event _DPfsctrlEvents_SetMessageTextEventHandler SetMessageText;

	public event _DPfsctrlEvents_DrawToolbarEventHandler DrawToolbarEvent;

	public event EventHandler Modified;

	public event _DPfsctrlEvents_OnSelectEventHandler OnSelect;

	public new event _DPfsctrlEvents_OnDoubleClickEventHandler OnDoubleClick;

	public event _DPfsctrlEvents_UpdateSettingsEventHandler UpdateSettings;

	public event _DPfsctrlEvents_PfsToolbarEventHandler PfsToolbarEvent;

	public event _DPfsctrlEvents_OnDoubleClick2EventHandler OnDoubleClick2;

	public event EventHandler OnCancelInsertMode;

	public event _DPfsctrlEvents_ModelUpdateEventHandler ModelUpdate;

	public event _DPfsctrlEvents_BeforeRenameModelEventHandler BeforeRenameModel;

	public event EventHandler OnCancelLibBarHalfStreamInsertMode;

	public event _DPfsctrlEvents_OnZoomChangedEventHandler OnZoomChanged;

	public event EventHandler ManageViewChanged;

	public event EventHandler UndoRedoChanged;

	public event _DPfsctrlEvents_LoadingWPFFormEventHandler LoadingWPFForm;

	public event _DPfsctrlEvents_DeleteWPFFormEventHandler DeleteWPFForm;

	public event _DPfsctrlEvents_GetObjectDescriptionTextEventHandler GetObjectDescriptionText;

	public event _DPfsctrlEvents_BlockVisibleChangingEventHandler BlockVisibleChanging;

	public event _DPfsctrlEvents_OnDropFilesEventHandler OnDropFiles;

	public event EventHandler UpdateFlipRotateStatus;

	public event _DPfsctrlEvents_DeleteBlockObjectEventHandler DeleteBlockObject;

	public event _DPfsctrlEvents_RenameBlockObjectEventHandler RenameBlockObject;

	public event _DPfsctrlEvents_PSVAttachedPSVToStreamEventHandler PSVAttachedPSVToStream;

	public event EventHandler BeginInsertPSVBlock;

	public event EventHandler FinishInsertPSVBlock;

	public event _DPfsctrlEvents_GetStreamPSVNameEventHandler GetStreamPSVName;

	public event _DPfsctrlEvents_OnDeletePSVBlockEventHandler OnDeletePSVBlock;

	public event _DPfsctrlEvents_OnAddPSVBlockEventHandler OnAddPSVBlock;

	public event _DPfsctrlEvents_OnGetPSVBlockDescriptionEventHandler OnGetPSVBlockDescription;

	public event _DPfsctrlEvents_OnRequestPSVBlockTypeEventHandler OnRequestPSVBlockType;

	public event _DPfsctrlEvents_OnPSVBlockExchangeTypeEventHandler OnPSVBlockExchangeType;

	public event _DPfsctrlEvents_OnGetPSVBlockErrorLevelEventHandler OnGetPSVBlockErrorLevel;

	public event _DPfsctrlEvents_CreateBlockEventHandler CreateBlock;

	public event _DPfsctrlEvents_OnEditStreamSummaryFormEventHandler OnEditStreamSummaryForm;

	public event _DPfsctrlEvents_CreateStreamEventHandler CreateStream;

	public event _DPfsctrlEvents_ScanConnectEventHandler ScanConnect;

	public AxPfsctrl()
		: base("20c9d4cd-6c3e-4100-8ee1-b3056237349e")
	{
		SetAboutBoxDelegate(AboutBox);
	}

	public virtual void ClearStopCursor()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("ClearStopCursor", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.ClearStopCursor();
	}

	public virtual void SetDocumentPtr(ulong lpDocument)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetDocumentPtr", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetDocumentPtr(lpDocument);
	}

	public virtual bool DoActiveSelectedModel()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("DoActiveSelectedModel", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.DoActiveSelectedModel();
	}

	public virtual void PfsLButtonDown(int x, int y, int iMouseType)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("PfsLButtonDown", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.PfsLButtonDown(x, y, iMouseType);
	}

	public virtual void CancelInsertMode()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("CancelInsertMode", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.CancelInsertMode();
	}

	public virtual bool GetMultipleObjectSelected()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetMultipleObjectSelected", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetMultipleObjectSelected();
	}

	public virtual string GetSettings()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetSettings", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetSettings();
	}

	public virtual void SetSettings(string sSettings)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetSettings", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetSettings(sSettings);
	}

	public virtual void UpdateTooltipText(string strObjectsID, string strDescriptions)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("UpdateTooltipText", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.UpdateTooltipText(strObjectsID, strDescriptions);
	}

	public virtual string GetSelectedObjectsPath()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetSelectedObjectsPath", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetSelectedObjectsPath();
	}

	public virtual void InsertWPFForm(object lpCtrl, object lpImg, bool bShowAsIcon, string pszPath, string pszFormType, int iTarget, int nWidth, int nHeight)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("InsertWPFForm", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.InsertWPFForm(lpCtrl, lpImg, bShowAsIcon, pszPath, pszFormType, iTarget, nWidth, nHeight);
	}

	public virtual void LoadWPFForm(object lpCtrl, object lpImg, int nWidth, int nHeight)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("LoadWPFForm", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.LoadWPFForm(lpCtrl, lpImg, nWidth, nHeight);
	}

	public virtual void ZoomWPFForm(double dFactor)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("ZoomWPFForm", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.ZoomWPFForm(dFactor);
	}

	public virtual void UpdateAXObjPath(string pszOldPath, string pszNewPath, int iType)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("UpdateAXObjPath", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.UpdateAXObjPath(pszOldPath, pszNewPath, iType);
	}

	public virtual void DeleteAXObj(string pszPath, int iType)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("DeleteAXObj", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.DeleteAXObj(pszPath, iType);
	}

	public virtual void FitWPFFormToContent(string pszPath, int iType)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("FitWPFFormToContent", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.FitWPFFormToContent(pszPath, iType);
	}

	public virtual void EmbeddedWPFFormUpdateData()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("EmbeddedWPFFormUpdateData", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.EmbeddedWPFFormUpdateData();
	}

	public virtual void SetObjectDescriptionText(string strID, string strDescriptionText)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetObjectDescriptionText", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetObjectDescriptionText(strID, strDescriptionText);
	}

	public virtual void ResetFocus()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("ResetFocus", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.ResetFocus();
	}

	public virtual void VerifyGrid(float fGridResolution, bool bViewGrid)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("VerifyGrid", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.VerifyGrid(fGridResolution, bViewGrid);
	}

	public virtual void ClearHistory()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("ClearHistory", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.ClearHistory();
	}

	public virtual bool GetMultipleBlockObjectSelected()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetMultipleBlockObjectSelected", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetMultipleBlockObjectSelected();
	}

	public virtual float GetZoomLevel()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetZoomLevel", ActiveXInvokeKind.MethodInvoke);
		}
		return (float)ocx.GetZoomLevel(); // The original applies conv.r4 before returning.
	}

	public virtual bool GetBlockPosition(string sName, ref float x, ref float y)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetBlockPosition", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetBlockPosition(sName, ref x, ref y);
	}

	public virtual bool GetBlockSize(string sName, ref float left, ref float right, ref float top, ref float bottom)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetBlockSize", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetBlockSize(sName, ref left, ref right, ref top, ref bottom);
	}

	public virtual bool FocusInTextEdit()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("FocusInTextEdit", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.FocusInTextEdit();
	}

	public virtual void SetPSVMode(bool bFlag)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetPSVMode", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetPSVMode(bFlag);
	}

	public virtual void SetInsertPSVBlockFlag()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetInsertPSVBlockFlag", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetInsertPSVBlockFlag();
	}

	public virtual void SetPSVModelType(object pPSVBlockModelType, object pPSVStreamModelType)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetPSVModelType", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetPSVModelType(pPSVBlockModelType, pPSVStreamModelType);
	}

	public virtual void RestorePSVStreamRoute()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("RestorePSVStreamRoute", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.RestorePSVStreamRoute();
	}

	public virtual void SetStreamPSVName(string pszStreamFullPath, string pszPSVName)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetStreamPSVName", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetStreamPSVName(pszStreamFullPath, pszPSVName);
	}

	public virtual void SynchronizePSVConnectivity(string pszStreamID, string pszPSVName)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SynchronizePSVConnectivity", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SynchronizePSVConnectivity(pszStreamID, pszPSVName);
	}

	public virtual void DeletePSVBlock(string pszStreamID, string pszPSVName)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("DeletePSVBlock", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.DeletePSVBlock(pszStreamID, pszPSVName);
	}

	public virtual void RenamePSVBlock(string pszStreamID, string pszPSVOldName, string pszPSVNewName)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("RenamePSVBlock", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.RenamePSVBlock(pszStreamID, pszPSVOldName, pszPSVNewName);
	}

	public virtual void SetPSVObjectType(int iPSVObjectType)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetPSVObjectType", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetPSVObjectType(iPSVObjectType);
	}

	public virtual void SetPSVBlockDescription(int iBlockType, string pszBlockName, string pszDescription)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetPSVBlockDescription", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetPSVBlockDescription(iBlockType, pszBlockName, pszDescription);
	}

	public virtual void SetPSVBlockType(string pszBlocksIDtoType)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetPSVBlockType", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetPSVBlockType(pszBlocksIDtoType);
	}

	public virtual void SetPSVBlockErrorLevelAndMessage(string pszPSVBlockID, int iErrorLevel, string pszMsg)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetPSVBlockErrorLevelAndMessage", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetPSVBlockErrorLevelAndMessage(pszPSVBlockID, iErrorLevel, pszMsg);
	}

	public virtual void ResetDOFIndicators()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("ResetDOFIndicators", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.ResetDOFIndicators();
	}

	public virtual void RedrawStreams(string pszStreamNames, int iQueryLineStyle)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("RedrawStreams", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.RedrawStreams(pszStreamNames, iQueryLineStyle);
	}

	public virtual void ClearEmbeddedWPFForms()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("ClearEmbeddedWPFForms", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.ClearEmbeddedWPFForms();
	}

	public virtual void ClearAndResetEmbeddedWPFForms()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("ClearAndResetEmbeddedWPFForms", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.ClearAndResetEmbeddedWPFForms();
	}

	public virtual void SaveEmbeddedWPFForms()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SaveEmbeddedWPFForms", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SaveEmbeddedWPFForms();
	}

	public virtual int FocusWPFFormIfExists(string pszID, int iType)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("FocusWPFFormIfExists", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.FocusWPFFormIfExists(pszID, iType);
	}

	public virtual bool GetPSVMode()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetPSVMode", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetPSVMode();
	}

	public virtual void SetBatchMode(bool bFlag)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetBatchMode", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetBatchMode(bFlag);
	}

	public virtual void RefreshBlock(string pszBlockID)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("RefreshBlock", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.RefreshBlock(pszBlockID);
	}

	public virtual void SetSimulationRunState(bool bIsRunning)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetSimulationRunState", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetSimulationRunState(bIsRunning);
	}

	public virtual void RefreshStreamGroups(bool bAllFlowsheets, string pszStreamIDList)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("RefreshStreamGroups", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.RefreshStreamGroups(bAllFlowsheets, pszStreamIDList);
	}

	public virtual void UpdateAnnotationsOnFlowSheet()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("UpdateAnnotationsOnFlowSheet", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.UpdateAnnotationsOnFlowSheet();
	}

	public virtual void AboutBox()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("AboutBox", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.AboutBox();
	}

	public virtual bool LoadFromFile(string filename)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("LoadFromFile", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.LoadFromFile(filename);
	}

	public virtual void SetRootModel(object rootModel)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetRootModel", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetRootModel(rootModel);
	}

	public virtual void DeleteBuddy(object dispatch)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("DeleteBuddy", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.DeleteBuddy(dispatch);
	}

	public virtual object GetIDispatch()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetIDispatch", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetIDispatch();
	}

	public virtual void AddBuddy(object dispatch)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("AddBuddy", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.AddBuddy(dispatch);
	}

	public virtual void InvokeMenuItem(int command)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("InvokeMenuItem", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.InvokeMenuItem(command);
	}

	public virtual bool CheckMenuItem(int command, ref short check)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("CheckMenuItem", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.CheckMenuItem(command, ref check);
	}

	public virtual string GetCurrentModel(ref int objectType, ref object pModel, ref int result)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetCurrentModel", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetCurrentModel(ref objectType, ref pModel, ref result);
	}

	public virtual void MessagePort(string sMessage)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("MessagePort", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.MessagePort(sMessage);
	}

	public virtual string GetMessageLog()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetMessageLog", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetMessageLog();
	}

	public virtual void OnViewUpdate(int lHint, object pObject)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("OnViewUpdate", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.OnViewUpdate(lHint, pObject);
	}

	public virtual void OnFilePageSetup()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("OnFilePageSetup", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.OnFilePageSetup();
	}

	public virtual void OnPrinting(int code, object pDC, object pInfo, bool bPreview)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("OnPrinting", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.OnPrinting(code, pDC, pInfo, bPreview);
	}

	public virtual void ClosePlaceWindow()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("ClosePlaceWindow", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.ClosePlaceWindow();
	}

	public virtual void AutoPlacement(bool bON)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("AutoPlacement", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.AutoPlacement(bON);
	}

	public virtual bool SaveEmbedded(object pStorage)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SaveEmbedded", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.SaveEmbedded(pStorage);
	}

	public virtual void AnimateBlock(string name)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("AnimateBlock", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.AnimateBlock(name);
	}

	public virtual void InsertBirdcage(object pCage)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("InsertBirdcage", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.InsertBirdcage(pCage);
	}

	public virtual void DeleteAllBirdcages()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("DeleteAllBirdcages", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.DeleteAllBirdcages();
	}

	public virtual void SetStopPoint(string blockid, short after)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetStopPoint", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetStopPoint(blockid, after);
	}

	public virtual void RemoveStopPoint(string blockid, short after)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("RemoveStopPoint", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.RemoveStopPoint(blockid, after);
	}

	public virtual void RemoveAllStopPoints()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("RemoveAllStopPoints", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.RemoveAllStopPoints();
	}

	public virtual void OpenUnplaceDialog(short autoPlacement)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("OpenUnplaceDialog", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.OpenUnplaceDialog(autoPlacement);
	}

	public virtual bool DrawToolbar(bool bToggle)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("DrawToolbar", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.DrawToolbar(bToggle);
	}

	public virtual bool BkpReader(object lpStream)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("BkpReader", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.BkpReader(lpStream);
	}

	public virtual void SetDocument(object lpDocument)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetDocument", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetDocument(lpDocument);
	}

	public virtual void AddText(string szText)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("AddText", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.AddText(szText);
	}

	public new virtual void KeyDown(int nChar, int nRepCnt, int nFlags)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("KeyDown", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.KeyDown(nChar, nRepCnt, nFlags);
	}

	public virtual void GenerateDXF(object pStream)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GenerateDXF", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.GenerateDXF(pStream);
	}

	public virtual void AddMenuItem(short type, string label, int command)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("AddMenuItem", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.AddMenuItem(type, label, command);
	}

	public virtual void EnableMenuItem(short type, int command, int flags)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("EnableMenuItem", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.EnableMenuItem(type, command, flags);
	}

	public virtual void DeleteMenuItem(short type, int command)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("DeleteMenuItem", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.DeleteMenuItem(type, command);
	}

	public virtual short AddMenu(short type, string label)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("AddMenu", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.AddMenu(type, label);
	}

	public virtual short GetMenuSize(short type)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetMenuSize", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetMenuSize(type);
	}

	public virtual void SetSymbol(string symbolName, string value)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetSymbol", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetSymbol(symbolName, value);
	}

	public virtual void SetName(string name)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetName", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetName(name);
	}

	public virtual bool CenterView(string iD, short type)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("CenterView", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.CenterView(iD, type);
	}

	public virtual void Zoom(float scalefactor, short type)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("Zoom", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.Zoom(scalefactor, type);
	}

	public virtual object GetEmbeddedItem(string szItemName)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetEmbeddedItem", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetEmbeddedItem(szItemName);
	}

	public virtual void SetApplication(object lpApp)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetApplication", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetApplication(lpApp);
	}

	public virtual void CloseEmbeddedItems()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("CloseEmbeddedItems", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.CloseEmbeddedItems();
	}

	public virtual bool PfsToolbar(bool bToggle)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("PfsToolbar", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.PfsToolbar(bToggle);
	}

	public virtual void Configure(int flags)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("Configure", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.Configure(flags);
	}

	public virtual object TransferCopyDataObject()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("TransferCopyDataObject", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.TransferCopyDataObject();
	}

	public virtual void GetViewport(ref float left, ref float right, ref float top, ref float bottom)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetViewport", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.GetViewport(ref left, ref right, ref top, ref bottom);
	}

	public virtual void SetViewport(float left, float right, float top, float bottom)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetViewport", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetViewport(left, right, top, bottom);
	}

	public virtual void LockFlowsheet(bool @lock)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("LockFlowsheet", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.LockFlowsheet(@lock);
	}

	public virtual void EnableBlock(string name, bool bEnable)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("EnableBlock", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.EnableBlock(name, bEnable);
	}

	public virtual bool FlowsheetLocked()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("FlowsheetLocked", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.FlowsheetLocked();
	}

	public virtual void GenerateDump(object pStream)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GenerateDump", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.GenerateDump(pStream);
	}

	public virtual void AutoPositionBlock(string name)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("AutoPositionBlock", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.AutoPositionBlock(name);
	}

	public virtual bool CheckEmbededObject()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("CheckEmbededObject", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.CheckEmbededObject();
	}

	public virtual void SetLibBarDropDownState()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetLibBarDropDownState", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetLibBarDropDownState();
	}

	public virtual void CancelLibBarDropDownState()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("CancelLibBarDropDownState", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.CancelLibBarDropDownState();
	}

	public virtual void ChangeBlockIcon(string pszBlockName, string pszIconName)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("ChangeBlockIcon", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.ChangeBlockIcon(pszBlockName, pszIconName);
	}

	public virtual void DrawText()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("DrawText", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.DrawText();
	}

	public virtual bool GetFontBold()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetFontBold", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetFontBold();
	}

	public virtual void SetFontBold()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetFontBold", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetFontBold();
	}

	public virtual void DrawLine()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("DrawLine", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.DrawLine();
	}

	public virtual void DrawBox()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("DrawBox", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.DrawBox();
	}

	public virtual void DrawPolygon()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("DrawPolygon", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.DrawPolygon();
	}

	public virtual void DrawPolyline()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("DrawPolyline", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.DrawPolyline();
	}

	public virtual void DrawEllipse()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("DrawEllipse", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.DrawEllipse();
	}

	public virtual void DrawHellipsens()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("DrawHellipsens", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.DrawHellipsens();
	}

	public virtual void DrawArrow()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("DrawArrow", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.DrawArrow();
	}

	public virtual void DrawDoubleArrow()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("DrawDoubleArrow", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.DrawDoubleArrow();
	}

	public virtual void ZoomToScale(float newScale)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("ZoomToScale", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.ZoomToScale(newScale);
	}

	public virtual bool GetFontItalic()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetFontItalic", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetFontItalic();
	}

	public virtual void SetFontItalic()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetFontItalic", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetFontItalic();
	}

	public virtual bool GetFontUnderScore()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetFontUnderScore", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetFontUnderScore();
	}

	public virtual void SetFontUnderScore()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetFontUnderScore", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetFontUnderScore();
	}

	public virtual bool GetAlignLeft()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetAlignLeft", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetAlignLeft();
	}

	public virtual void SetAlignLeft()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetAlignLeft", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetAlignLeft();
	}

	public virtual bool GetAlignCenter()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetAlignCenter", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetAlignCenter();
	}

	public virtual void SetAlignCenter()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetAlignCenter", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetAlignCenter();
	}

	public virtual bool GetAlignRight()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetAlignRight", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetAlignRight();
	}

	public virtual void SetAlignRight()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetAlignRight", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetAlignRight();
	}

	public virtual string GetFontSizeList()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetFontSizeList", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetFontSizeList();
	}

	public virtual string GetFontNameList()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetFontNameList", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetFontNameList();
	}

	public virtual short GetFontSizeCurIndex()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetFontSizeCurIndex", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetFontSizeCurIndex();
	}

	public virtual void SetFontSizeCurIndex(short curIndex)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetFontSizeCurIndex", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetFontSizeCurIndex(curIndex);
	}

	public virtual short GetColorCurIndex()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetColorCurIndex", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetColorCurIndex();
	}

	public virtual short GetLineTypeCurIndex()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetLineTypeCurIndex", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetLineTypeCurIndex();
	}

	public virtual void SetRotateRight()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetRotateRight", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetRotateRight();
	}

	public virtual void SetFLIPX()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetFLIPX", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetFLIPX();
	}

	public virtual void SetFLIPY()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetFLIPY", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetFLIPY();
	}

	public virtual void PlaceAllBlocks()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("PlaceAllBlocks", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.PlaceAllBlocks();
	}

	public virtual void PlaceNextBlock()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("PlaceNextBlock", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.PlaceNextBlock();
	}

	public virtual void PlaceBlock(string name)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("PlaceBlock", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.PlaceBlock(name);
	}

	public virtual bool GetSelectMode()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetSelectMode", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetSelectMode();
	}

	public virtual void SetSelectMode()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetSelectMode", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetSelectMode();
	}

	public virtual string GetUndoList()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetUndoList", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetUndoList();
	}

	public virtual string GetRedoList()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetRedoList", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetRedoList();
	}

	public virtual void SetOneStepUndo()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetOneStepUndo", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetOneStepUndo();
	}

	public virtual void SetStepsUndo(short curIndex)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetStepsUndo", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetStepsUndo(curIndex);
	}

	public virtual void SetOneStepRedo()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetOneStepRedo", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetOneStepRedo();
	}

	public virtual void SetStepsRedo(short curIndex)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetStepsRedo", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetStepsRedo(curIndex);
	}

	public virtual bool IsItemSelected()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("IsItemSelected", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.IsItemSelected();
	}

	public virtual void SelectObject(string sRootModelName, string sName, int oclass, int bCenterView, int bZoomView)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SelectObject", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SelectObject(sRootModelName, sName, oclass, bCenterView, bZoomView);
	}

	public virtual void SaveFindObjectSettings(int bCenterView, int bZoomView, string sBlockFilterList, string sStreamFilterList)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SaveFindObjectSettings", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SaveFindObjectSettings(bCenterView, bZoomView, sBlockFilterList, sStreamFilterList);
	}

	public virtual void FindObjectClosed()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("FindObjectClosed", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.FindObjectClosed();
	}

	public virtual void WPFInsertBirdcage(long pCage)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("WPFInsertBirdcage", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.WPFInsertBirdcage(pCage);
	}

	public virtual object GetRootModel()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetRootModel", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetRootModel();
	}

	public virtual void LoadAsText(string sVData)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("LoadAsText", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.LoadAsText(sVData);
	}

	public virtual string SaveAsText()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SaveAsText", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.SaveAsText();
	}

	public virtual string GetBookmarkList()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetBookmarkList", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetBookmarkList();
	}

	public virtual void GotoBookmark(string sName)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GotoBookmark", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.GotoBookmark(sName);
	}

	public virtual void AddBookmark(string strName)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("AddBookmark", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.AddBookmark(strName);
	}

	public virtual void DeleteBookmark(string strName)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("DeleteBookmark", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.DeleteBookmark(strName);
	}

	public virtual short GetTextColorIndex()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetTextColorIndex", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetTextColorIndex();
	}

	public virtual void SetTextColorIndex(short curIndex)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetTextColorIndex", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetTextColorIndex(curIndex);
	}

	public virtual short GetColorFillCurIndex()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetColorFillCurIndex", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetColorFillCurIndex();
	}

	public virtual short GetLineWeightCurIndex()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetLineWeightCurIndex", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetLineWeightCurIndex();
	}

	public virtual void SetLineWeightCurIndex(short curIndex)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetLineWeightCurIndex", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetLineWeightCurIndex(curIndex);
	}

	public virtual void SelectObject2(string sName, int oclass, int bCenterView, int bZoomView)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SelectObject2", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SelectObject2(sName, oclass, bCenterView, bZoomView);
	}

	public virtual bool GetSelectedDrawAttributes(ref int lineColor, ref int fillColor, ref int outline, ref int filled, ref int lineStyle, ref int lineWidth)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetSelectedDrawAttributes", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetSelectedDrawAttributes(ref lineColor, ref fillColor, ref outline, ref filled, ref lineStyle, ref lineWidth);
	}

	public virtual void SetSelectedDrawAttributes(int lineColor, int fillColor, int outline, int filled, int lineStyle, int lineWidth)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetSelectedDrawAttributes", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetSelectedDrawAttributes(lineColor, fillColor, outline, filled, lineStyle, lineWidth);
	}

	public virtual bool GetSelectedStreamAttributes(ref int useDefault, ref int lineColor, ref int lineStyle, ref int lineWidth)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetSelectedStreamAttributes", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetSelectedStreamAttributes(ref useDefault, ref lineColor, ref lineStyle, ref lineWidth);
	}

	public virtual void SetSelectedStreamAttributes(int useDefault, int lineColor, int lineStyle, int lineWidth)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetSelectedStreamAttributes", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetSelectedStreamAttributes(useDefault, lineColor, lineStyle, lineWidth);
	}

	public virtual bool GetObjectTypeSelected(int type)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetObjectTypeSelected", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetObjectTypeSelected(type);
	}

	public virtual void ScrollBigStep(int bHorizontal, short zDelta)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("ScrollBigStep", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.ScrollBigStep(bHorizontal, zDelta);
	}

	public virtual string GetFontName()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("GetFontName", ActiveXInvokeKind.MethodInvoke);
		}
		return ocx.GetFontName();
	}

	public virtual void SetFontName(string pszFontName)
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetFontName", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetFontName(pszFontName);
	}

	public virtual void SetStopCursor()
	{
		if (ocx == null)
		{
			throw new InvalidActiveXStateException("SetStopCursor", ActiveXInvokeKind.MethodInvoke);
		}
		ocx.SetStopCursor();
	}

	protected override void CreateSink()
	{
		try
		{
			eventMulticaster = new AxPfsctrlEventMulticaster(this);
			cookie = new ConnectionPointCookie(ocx, eventMulticaster, typeof(_DPfsctrlEvents));
		}
		catch (Exception)
		{
		}
	}

	protected override void DetachSink()
	{
		try
		{
			cookie.Disconnect();
		}
		catch (Exception)
		{
		}
	}

	protected override void AttachInterfaces()
	{
		try
		{
			ocx = (_DPfsctrl)GetOcx();
		}
		catch (Exception)
		{
		}
	}

	internal void RaiseOnDoOleVerb(object sender, _DPfsctrlEvents_DoOleVerbEvent e)
	{
		if (this.DoOleVerb != null)
		{
			this.DoOleVerb(sender, e);
		}
	}

	internal void RaiseOnInvokeMenuItemEvent(object sender, _DPfsctrlEvents_InvokeMenuItemEvent e)
	{
		if (this.InvokeMenuItemEvent != null)
		{
			this.InvokeMenuItemEvent(sender, e);
		}
	}

	internal void RaiseOnSelectPrinter(object sender, _DPfsctrlEvents_SelectPrinterEvent e)
	{
		if (this.SelectPrinter != null)
		{
			this.SelectPrinter(sender, e);
		}
	}

	internal void RaiseOnOnFIlePrint(object sender, EventArgs e)
	{
		if (this.OnFIlePrint != null)
		{
			this.OnFIlePrint(sender, e);
		}
	}

	internal void RaiseOnSetMessageText(object sender, _DPfsctrlEvents_SetMessageTextEvent e)
	{
		if (this.SetMessageText != null)
		{
			this.SetMessageText(sender, e);
		}
	}

	internal void RaiseOnDrawToolbarEvent(object sender, _DPfsctrlEvents_DrawToolbarEvent e)
	{
		if (this.DrawToolbarEvent != null)
		{
			this.DrawToolbarEvent(sender, e);
		}
	}

	internal void RaiseOnModified(object sender, EventArgs e)
	{
		if (this.Modified != null)
		{
			this.Modified(sender, e);
		}
	}

	internal void RaiseOnOnSelect(object sender, _DPfsctrlEvents_OnSelectEvent e)
	{
		if (this.OnSelect != null)
		{
			this.OnSelect(sender, e);
		}
	}

	internal void RaiseOnOnDoubleClick(object sender, _DPfsctrlEvents_OnDoubleClickEvent e)
	{
		if (this.OnDoubleClick != null)
		{
			this.OnDoubleClick(sender, e);
		}
	}

	internal void RaiseOnUpdateSettings(object sender, _DPfsctrlEvents_UpdateSettingsEvent e)
	{
		if (this.UpdateSettings != null)
		{
			this.UpdateSettings(sender, e);
		}
	}

	internal void RaiseOnPfsToolbarEvent(object sender, _DPfsctrlEvents_PfsToolbarEvent e)
	{
		if (this.PfsToolbarEvent != null)
		{
			this.PfsToolbarEvent(sender, e);
		}
	}

	internal void RaiseOnOnDoubleClick2(object sender, _DPfsctrlEvents_OnDoubleClick2Event e)
	{
		if (this.OnDoubleClick2 != null)
		{
			this.OnDoubleClick2(sender, e);
		}
	}

	internal void RaiseOnOnCancelInsertMode(object sender, EventArgs e)
	{
		if (this.OnCancelInsertMode != null)
		{
			this.OnCancelInsertMode(sender, e);
		}
	}

	internal void RaiseOnModelUpdate(object sender, _DPfsctrlEvents_ModelUpdateEvent e)
	{
		if (this.ModelUpdate != null)
		{
			this.ModelUpdate(sender, e);
		}
	}

	internal void RaiseOnBeforeRenameModel(object sender, _DPfsctrlEvents_BeforeRenameModelEvent e)
	{
		if (this.BeforeRenameModel != null)
		{
			this.BeforeRenameModel(sender, e);
		}
	}

	internal void RaiseOnOnCancelLibBarHalfStreamInsertMode(object sender, EventArgs e)
	{
		if (this.OnCancelLibBarHalfStreamInsertMode != null)
		{
			this.OnCancelLibBarHalfStreamInsertMode(sender, e);
		}
	}

	internal void RaiseOnOnZoomChanged(object sender, _DPfsctrlEvents_OnZoomChangedEvent e)
	{
		if (this.OnZoomChanged != null)
		{
			this.OnZoomChanged(sender, e);
		}
	}

	internal void RaiseOnManageViewChanged(object sender, EventArgs e)
	{
		if (this.ManageViewChanged != null)
		{
			this.ManageViewChanged(sender, e);
		}
	}

	internal void RaiseOnUndoRedoChanged(object sender, EventArgs e)
	{
		if (this.UndoRedoChanged != null)
		{
			this.UndoRedoChanged(sender, e);
		}
	}

	internal void RaiseOnLoadingWPFForm(object sender, _DPfsctrlEvents_LoadingWPFFormEvent e)
	{
		if (this.LoadingWPFForm != null)
		{
			this.LoadingWPFForm(sender, e);
		}
	}

	internal void RaiseOnDeleteWPFForm(object sender, _DPfsctrlEvents_DeleteWPFFormEvent e)
	{
		if (this.DeleteWPFForm != null)
		{
			this.DeleteWPFForm(sender, e);
		}
	}

	internal void RaiseOnGetObjectDescriptionText(object sender, _DPfsctrlEvents_GetObjectDescriptionTextEvent e)
	{
		if (this.GetObjectDescriptionText != null)
		{
			this.GetObjectDescriptionText(sender, e);
		}
	}

	internal void RaiseOnBlockVisibleChanging(object sender, _DPfsctrlEvents_BlockVisibleChangingEvent e)
	{
		if (this.BlockVisibleChanging != null)
		{
			this.BlockVisibleChanging(sender, e);
		}
	}

	internal void RaiseOnOnDropFiles(object sender, _DPfsctrlEvents_OnDropFilesEvent e)
	{
		if (this.OnDropFiles != null)
		{
			this.OnDropFiles(sender, e);
		}
	}

	internal void RaiseOnUpdateFlipRotateStatus(object sender, EventArgs e)
	{
		if (this.UpdateFlipRotateStatus != null)
		{
			this.UpdateFlipRotateStatus(sender, e);
		}
	}

	internal void RaiseOnDeleteBlockObject(object sender, _DPfsctrlEvents_DeleteBlockObjectEvent e)
	{
		if (this.DeleteBlockObject != null)
		{
			this.DeleteBlockObject(sender, e);
		}
	}

	internal void RaiseOnRenameBlockObject(object sender, _DPfsctrlEvents_RenameBlockObjectEvent e)
	{
		if (this.RenameBlockObject != null)
		{
			this.RenameBlockObject(sender, e);
		}
	}

	internal void RaiseOnPSVAttachedPSVToStream(object sender, _DPfsctrlEvents_PSVAttachedPSVToStreamEvent e)
	{
		if (this.PSVAttachedPSVToStream != null)
		{
			this.PSVAttachedPSVToStream(sender, e);
		}
	}

	internal void RaiseOnBeginInsertPSVBlock(object sender, EventArgs e)
	{
		if (this.BeginInsertPSVBlock != null)
		{
			this.BeginInsertPSVBlock(sender, e);
		}
	}

	internal void RaiseOnFinishInsertPSVBlock(object sender, EventArgs e)
	{
		if (this.FinishInsertPSVBlock != null)
		{
			this.FinishInsertPSVBlock(sender, e);
		}
	}

	internal void RaiseOnGetStreamPSVName(object sender, _DPfsctrlEvents_GetStreamPSVNameEvent e)
	{
		if (this.GetStreamPSVName != null)
		{
			this.GetStreamPSVName(sender, e);
		}
	}

	internal void RaiseOnOnDeletePSVBlock(object sender, _DPfsctrlEvents_OnDeletePSVBlockEvent e)
	{
		if (this.OnDeletePSVBlock != null)
		{
			this.OnDeletePSVBlock(sender, e);
		}
	}

	internal void RaiseOnOnAddPSVBlock(object sender, _DPfsctrlEvents_OnAddPSVBlockEvent e)
	{
		if (this.OnAddPSVBlock != null)
		{
			this.OnAddPSVBlock(sender, e);
		}
	}

	internal void RaiseOnOnGetPSVBlockDescription(object sender, _DPfsctrlEvents_OnGetPSVBlockDescriptionEvent e)
	{
		if (this.OnGetPSVBlockDescription != null)
		{
			this.OnGetPSVBlockDescription(sender, e);
		}
	}

	internal void RaiseOnOnRequestPSVBlockType(object sender, _DPfsctrlEvents_OnRequestPSVBlockTypeEvent e)
	{
		if (this.OnRequestPSVBlockType != null)
		{
			this.OnRequestPSVBlockType(sender, e);
		}
	}

	internal void RaiseOnOnPSVBlockExchangeType(object sender, _DPfsctrlEvents_OnPSVBlockExchangeTypeEvent e)
	{
		if (this.OnPSVBlockExchangeType != null)
		{
			this.OnPSVBlockExchangeType(sender, e);
		}
	}

	internal void RaiseOnOnGetPSVBlockErrorLevel(object sender, _DPfsctrlEvents_OnGetPSVBlockErrorLevelEvent e)
	{
		if (this.OnGetPSVBlockErrorLevel != null)
		{
			this.OnGetPSVBlockErrorLevel(sender, e);
		}
	}

	internal void RaiseOnCreateBlock(object sender, _DPfsctrlEvents_CreateBlockEvent e)
	{
		if (this.CreateBlock != null)
		{
			this.CreateBlock(sender, e);
		}
	}

	internal void RaiseOnOnEditStreamSummaryForm(object sender, _DPfsctrlEvents_OnEditStreamSummaryFormEvent e)
	{
		if (this.OnEditStreamSummaryForm != null)
		{
			this.OnEditStreamSummaryForm(sender, e);
		}
	}

	internal void RaiseOnCreateStream(object sender, _DPfsctrlEvents_CreateStreamEvent e)
	{
		if (this.CreateStream != null)
		{
			this.CreateStream(sender, e);
		}
	}

	internal void RaiseOnScanConnect(object sender, _DPfsctrlEvents_ScanConnectEvent e)
	{
		if (this.ScanConnect != null)
		{
			this.ScanConnect(sender, e);
		}
	}
}
public delegate void _DPfsctrlEvents_DoOleVerbEventHandler(object sender, _DPfsctrlEvents_DoOleVerbEvent e);
public class _DPfsctrlEvents_DoOleVerbEvent
{
	public object pOleObj;

	public int nID;

	public _DPfsctrlEvents_DoOleVerbEvent(object pOleObj, int nID)
	{
		this.pOleObj = pOleObj;
		this.nID = nID;
	}
}
public delegate void _DPfsctrlEvents_InvokeMenuItemEventHandler(object sender, _DPfsctrlEvents_InvokeMenuItemEvent e);
public class _DPfsctrlEvents_InvokeMenuItemEvent
{
	public int nCommand;

	public _DPfsctrlEvents_InvokeMenuItemEvent(int nCommand)
	{
		this.nCommand = nCommand;
	}
}
public delegate void _DPfsctrlEvents_SelectPrinterEventHandler(object sender, _DPfsctrlEvents_SelectPrinterEvent e);
public class _DPfsctrlEvents_SelectPrinterEvent
{
	public int devNames;

	public int devMode;

	public _DPfsctrlEvents_SelectPrinterEvent(int devNames, int devMode)
	{
		this.devNames = devNames;
		this.devMode = devMode;
	}
}
public delegate void _DPfsctrlEvents_SetMessageTextEventHandler(object sender, _DPfsctrlEvents_SetMessageTextEvent e);
public class _DPfsctrlEvents_SetMessageTextEvent
{
	public string text;

	public _DPfsctrlEvents_SetMessageTextEvent(string text)
	{
		this.text = text;
	}
}
public delegate void _DPfsctrlEvents_DrawToolbarEventHandler(object sender, _DPfsctrlEvents_DrawToolbarEvent e);
public class _DPfsctrlEvents_DrawToolbarEvent
{
	public bool bON;

	public _DPfsctrlEvents_DrawToolbarEvent(bool bON)
	{
		this.bON = bON;
	}
}
public delegate void _DPfsctrlEvents_OnSelectEventHandler(object sender, _DPfsctrlEvents_OnSelectEvent e);
public class _DPfsctrlEvents_OnSelectEvent
{
	public short type;

	public string iD;

	public _DPfsctrlEvents_OnSelectEvent(short type, string iD)
	{
		this.type = type;
		this.iD = iD;
	}
}
public delegate void _DPfsctrlEvents_OnDoubleClickEventHandler(object sender, _DPfsctrlEvents_OnDoubleClickEvent e);
public class _DPfsctrlEvents_OnDoubleClickEvent
{
	public short type;

	public string iD;

	public _DPfsctrlEvents_OnDoubleClickEvent(short type, string iD)
	{
		this.type = type;
		this.iD = iD;
	}
}
public delegate void _DPfsctrlEvents_UpdateSettingsEventHandler(object sender, _DPfsctrlEvents_UpdateSettingsEvent e);
public class _DPfsctrlEvents_UpdateSettingsEvent
{
	public int lHint;

	public _DPfsctrlEvents_UpdateSettingsEvent(int lHint)
	{
		this.lHint = lHint;
	}
}
public delegate void _DPfsctrlEvents_PfsToolbarEventHandler(object sender, _DPfsctrlEvents_PfsToolbarEvent e);
public class _DPfsctrlEvents_PfsToolbarEvent
{
	public bool bON;

	public _DPfsctrlEvents_PfsToolbarEvent(bool bON)
	{
		this.bON = bON;
	}
}
public delegate void _DPfsctrlEvents_OnDoubleClick2EventHandler(object sender, _DPfsctrlEvents_OnDoubleClick2Event e);
public class _DPfsctrlEvents_OnDoubleClick2Event
{
	public short type;

	public string iD;

	public string modelType;

	public _DPfsctrlEvents_OnDoubleClick2Event(short type, string iD, string modelType)
	{
		this.type = type;
		this.iD = iD;
		this.modelType = modelType;
	}
}
public delegate void _DPfsctrlEvents_ModelUpdateEventHandler(object sender, _DPfsctrlEvents_ModelUpdateEvent e);
public class _DPfsctrlEvents_ModelUpdateEvent
{
	public string iD;

	public string modelType;

	public _DPfsctrlEvents_ModelUpdateEvent(string iD, string modelType)
	{
		this.iD = iD;
		this.modelType = modelType;
	}
}
public delegate void _DPfsctrlEvents_BeforeRenameModelEventHandler(object sender, _DPfsctrlEvents_BeforeRenameModelEvent e);
public class _DPfsctrlEvents_BeforeRenameModelEvent
{
	public string iD;

	public _DPfsctrlEvents_BeforeRenameModelEvent(string iD)
	{
		this.iD = iD;
	}
}
public delegate void _DPfsctrlEvents_OnZoomChangedEventHandler(object sender, _DPfsctrlEvents_OnZoomChangedEvent e);
public class _DPfsctrlEvents_OnZoomChangedEvent
{
	public float oldScale;

	public float newScale;

	public _DPfsctrlEvents_OnZoomChangedEvent(float oldScale, float newScale)
	{
		this.oldScale = oldScale;
		this.newScale = newScale;
	}
}
public delegate void _DPfsctrlEvents_LoadingWPFFormEventHandler(object sender, _DPfsctrlEvents_LoadingWPFFormEvent e);
public class _DPfsctrlEvents_LoadingWPFFormEvent
{
	public string bstrPath;

	public int iFormType;

	public int iTargetClass;

	public _DPfsctrlEvents_LoadingWPFFormEvent(string bstrPath, int iFormType, int iTargetClass)
	{
		this.bstrPath = bstrPath;
		this.iFormType = iFormType;
		this.iTargetClass = iTargetClass;
	}
}
public delegate void _DPfsctrlEvents_DeleteWPFFormEventHandler(object sender, _DPfsctrlEvents_DeleteWPFFormEvent e);
public class _DPfsctrlEvents_DeleteWPFFormEvent
{
	public string bstrPath;

	public string bstrFormType;

	public _DPfsctrlEvents_DeleteWPFFormEvent(string bstrPath, string bstrFormType)
	{
		this.bstrPath = bstrPath;
		this.bstrFormType = bstrFormType;
	}
}
public delegate void _DPfsctrlEvents_GetObjectDescriptionTextEventHandler(object sender, _DPfsctrlEvents_GetObjectDescriptionTextEvent e);
public class _DPfsctrlEvents_GetObjectDescriptionTextEvent
{
	public string bstrPath;

	public int nObjectType;

	public _DPfsctrlEvents_GetObjectDescriptionTextEvent(string bstrPath, int nObjectType)
	{
		this.bstrPath = bstrPath;
		this.nObjectType = nObjectType;
	}
}
public delegate void _DPfsctrlEvents_BlockVisibleChangingEventHandler(object sender, _DPfsctrlEvents_BlockVisibleChangingEvent e);
public class _DPfsctrlEvents_BlockVisibleChangingEvent
{
	public string bstrType;

	public _DPfsctrlEvents_BlockVisibleChangingEvent(string bstrType)
	{
		this.bstrType = bstrType;
	}
}
public delegate void _DPfsctrlEvents_OnDropFilesEventHandler(object sender, _DPfsctrlEvents_OnDropFilesEvent e);
public class _DPfsctrlEvents_OnDropFilesEvent
{
	public string varFiles;

	public _DPfsctrlEvents_OnDropFilesEvent(string varFiles)
	{
		this.varFiles = varFiles;
	}
}
public delegate void _DPfsctrlEvents_DeleteBlockObjectEventHandler(object sender, _DPfsctrlEvents_DeleteBlockObjectEvent e);
public class _DPfsctrlEvents_DeleteBlockObjectEvent
{
	public string bstrID;

	public string bstrObjectType;

	public _DPfsctrlEvents_DeleteBlockObjectEvent(string bstrID, string bstrObjectType)
	{
		this.bstrID = bstrID;
		this.bstrObjectType = bstrObjectType;
	}
}
public delegate void _DPfsctrlEvents_RenameBlockObjectEventHandler(object sender, _DPfsctrlEvents_RenameBlockObjectEvent e);
public class _DPfsctrlEvents_RenameBlockObjectEvent
{
	public string bstrOldName;

	public string bstrNewName;

	public string bstrObjectType;

	public _DPfsctrlEvents_RenameBlockObjectEvent(string bstrOldName, string bstrNewName, string bstrObjectType)
	{
		this.bstrOldName = bstrOldName;
		this.bstrNewName = bstrNewName;
		this.bstrObjectType = bstrObjectType;
	}
}
public delegate void _DPfsctrlEvents_PSVAttachedPSVToStreamEventHandler(object sender, _DPfsctrlEvents_PSVAttachedPSVToStreamEvent e);
public class _DPfsctrlEvents_PSVAttachedPSVToStreamEvent
{
	public string bstrStreamFullPath;

	public string bstrPSVName;

	public _DPfsctrlEvents_PSVAttachedPSVToStreamEvent(string bstrStreamFullPath, string bstrPSVName)
	{
		this.bstrStreamFullPath = bstrStreamFullPath;
		this.bstrPSVName = bstrPSVName;
	}
}
public delegate void _DPfsctrlEvents_GetStreamPSVNameEventHandler(object sender, _DPfsctrlEvents_GetStreamPSVNameEvent e);
public class _DPfsctrlEvents_GetStreamPSVNameEvent
{
	public string bstrStreamFullPath;

	public int iObjectType;

	public _DPfsctrlEvents_GetStreamPSVNameEvent(string bstrStreamFullPath, int iObjectType)
	{
		this.bstrStreamFullPath = bstrStreamFullPath;
		this.iObjectType = iObjectType;
	}
}
public delegate void _DPfsctrlEvents_OnDeletePSVBlockEventHandler(object sender, _DPfsctrlEvents_OnDeletePSVBlockEvent e);
public class _DPfsctrlEvents_OnDeletePSVBlockEvent
{
	public string bstrStreamID;

	public string bstrPSVName;

	public _DPfsctrlEvents_OnDeletePSVBlockEvent(string bstrStreamID, string bstrPSVName)
	{
		this.bstrStreamID = bstrStreamID;
		this.bstrPSVName = bstrPSVName;
	}
}
public delegate void _DPfsctrlEvents_OnAddPSVBlockEventHandler(object sender, _DPfsctrlEvents_OnAddPSVBlockEvent e);
public class _DPfsctrlEvents_OnAddPSVBlockEvent
{
	public string bstrStreamFullPath;

	public int iPSVObjectType;

	public _DPfsctrlEvents_OnAddPSVBlockEvent(string bstrStreamFullPath, int iPSVObjectType)
	{
		this.bstrStreamFullPath = bstrStreamFullPath;
		this.iPSVObjectType = iPSVObjectType;
	}
}
public delegate void _DPfsctrlEvents_OnGetPSVBlockDescriptionEventHandler(object sender, _DPfsctrlEvents_OnGetPSVBlockDescriptionEvent e);
public class _DPfsctrlEvents_OnGetPSVBlockDescriptionEvent
{
	public int iBlockType;

	public string bstrBlockName;

	public _DPfsctrlEvents_OnGetPSVBlockDescriptionEvent(int iBlockType, string bstrBlockName)
	{
		this.iBlockType = iBlockType;
		this.bstrBlockName = bstrBlockName;
	}
}
public delegate void _DPfsctrlEvents_OnRequestPSVBlockTypeEventHandler(object sender, _DPfsctrlEvents_OnRequestPSVBlockTypeEvent e);
public class _DPfsctrlEvents_OnRequestPSVBlockTypeEvent
{
	public string bstrPSVBlockIDs;

	public _DPfsctrlEvents_OnRequestPSVBlockTypeEvent(string bstrPSVBlockIDs)
	{
		this.bstrPSVBlockIDs = bstrPSVBlockIDs;
	}
}
public delegate void _DPfsctrlEvents_OnPSVBlockExchangeTypeEventHandler(object sender, _DPfsctrlEvents_OnPSVBlockExchangeTypeEvent e);
public class _DPfsctrlEvents_OnPSVBlockExchangeTypeEvent
{
	public string bstrPSVBlockID;

	public int iOldType;

	public int iNewType;

	public _DPfsctrlEvents_OnPSVBlockExchangeTypeEvent(string bstrPSVBlockID, int iOldType, int iNewType)
	{
		this.bstrPSVBlockID = bstrPSVBlockID;
		this.iOldType = iOldType;
		this.iNewType = iNewType;
	}
}
public delegate void _DPfsctrlEvents_OnGetPSVBlockErrorLevelEventHandler(object sender, _DPfsctrlEvents_OnGetPSVBlockErrorLevelEvent e);
public class _DPfsctrlEvents_OnGetPSVBlockErrorLevelEvent
{
	public string bstrPSVBlockID;

	public _DPfsctrlEvents_OnGetPSVBlockErrorLevelEvent(string bstrPSVBlockID)
	{
		this.bstrPSVBlockID = bstrPSVBlockID;
	}
}
public delegate void _DPfsctrlEvents_CreateBlockEventHandler(object sender, _DPfsctrlEvents_CreateBlockEvent e);
public class _DPfsctrlEvents_CreateBlockEvent
{
	public string bstrBlockID;

	public string bstrBlockType;

	public _DPfsctrlEvents_CreateBlockEvent(string bstrBlockID, string bstrBlockType)
	{
		this.bstrBlockID = bstrBlockID;
		this.bstrBlockType = bstrBlockType;
	}
}
public delegate void _DPfsctrlEvents_OnEditStreamSummaryFormEventHandler(object sender, _DPfsctrlEvents_OnEditStreamSummaryFormEvent e);
public class _DPfsctrlEvents_OnEditStreamSummaryFormEvent
{
	public string bstrObjectName;

	public int iTargetObjectClass;

	public _DPfsctrlEvents_OnEditStreamSummaryFormEvent(string bstrObjectName, int iTargetObjectClass)
	{
		this.bstrObjectName = bstrObjectName;
		this.iTargetObjectClass = iTargetObjectClass;
	}
}
public delegate void _DPfsctrlEvents_CreateStreamEventHandler(object sender, _DPfsctrlEvents_CreateStreamEvent e);
public class _DPfsctrlEvents_CreateStreamEvent
{
	public string strStreamID;

	public string strStreamType;

	public string conectBlock1;

	public string conectBlock2;

	public _DPfsctrlEvents_CreateStreamEvent(string strStreamID, string strStreamType, string conectBlock1, string conectBlock2)
	{
		this.strStreamID = strStreamID;
		this.strStreamType = strStreamType;
		this.conectBlock1 = conectBlock1;
		this.conectBlock2 = conectBlock2;
	}
}
public delegate void _DPfsctrlEvents_ScanConnectEventHandler(object sender, _DPfsctrlEvents_ScanConnectEvent e);
public class _DPfsctrlEvents_ScanConnectEvent
{
	public string streamName;

	public string blockName;

	public string connectType;

	public int direction;

	public _DPfsctrlEvents_ScanConnectEvent(string streamName, string blockName, string connectType, int direction)
	{
		this.streamName = streamName;
		this.blockName = blockName;
		this.connectType = connectType;
		this.direction = direction;
	}
}
[ClassInterface(ClassInterfaceType.None)]
public class AxPfsctrlEventMulticaster : _DPfsctrlEvents
{
	private AxPfsctrl parent;

	public AxPfsctrlEventMulticaster(AxPfsctrl parent)
	{
		this.parent = parent;
	}

	public virtual void DoOleVerb(object pOleObj, int nID)
	{
		_DPfsctrlEvents_DoOleVerbEvent e = new _DPfsctrlEvents_DoOleVerbEvent(pOleObj, nID);
		parent.RaiseOnDoOleVerb(parent, e);
	}

	public virtual void InvokeMenuItem(int nCommand)
	{
		_DPfsctrlEvents_InvokeMenuItemEvent e = new _DPfsctrlEvents_InvokeMenuItemEvent(nCommand);
		parent.RaiseOnInvokeMenuItemEvent(parent, e);
	}

	public virtual void SelectPrinter(int devNames, int devMode)
	{
		_DPfsctrlEvents_SelectPrinterEvent e = new _DPfsctrlEvents_SelectPrinterEvent(devNames, devMode);
		parent.RaiseOnSelectPrinter(parent, e);
	}

	public virtual void OnFIlePrint()
	{
		EventArgs e = new EventArgs();
		parent.RaiseOnOnFIlePrint(parent, e);
	}

	public virtual void SetMessageText(string text)
	{
		_DPfsctrlEvents_SetMessageTextEvent e = new _DPfsctrlEvents_SetMessageTextEvent(text);
		parent.RaiseOnSetMessageText(parent, e);
	}

	public virtual void DrawToolbar(bool bON)
	{
		_DPfsctrlEvents_DrawToolbarEvent e = new _DPfsctrlEvents_DrawToolbarEvent(bON);
		parent.RaiseOnDrawToolbarEvent(parent, e);
	}

	public virtual void Modified()
	{
		EventArgs e = new EventArgs();
		parent.RaiseOnModified(parent, e);
	}

	public virtual void OnSelect(short type, string iD)
	{
		_DPfsctrlEvents_OnSelectEvent e = new _DPfsctrlEvents_OnSelectEvent(type, iD);
		parent.RaiseOnOnSelect(parent, e);
	}

	public virtual void OnDoubleClick(short type, string iD)
	{
		_DPfsctrlEvents_OnDoubleClickEvent e = new _DPfsctrlEvents_OnDoubleClickEvent(type, iD);
		parent.RaiseOnOnDoubleClick(parent, e);
	}

	public virtual void UpdateSettings(int lHint)
	{
		_DPfsctrlEvents_UpdateSettingsEvent e = new _DPfsctrlEvents_UpdateSettingsEvent(lHint);
		parent.RaiseOnUpdateSettings(parent, e);
	}

	public virtual void PfsToolbar(bool bON)
	{
		_DPfsctrlEvents_PfsToolbarEvent e = new _DPfsctrlEvents_PfsToolbarEvent(bON);
		parent.RaiseOnPfsToolbarEvent(parent, e);
	}

	public virtual void OnDoubleClick2(short type, string iD, string modelType)
	{
		_DPfsctrlEvents_OnDoubleClick2Event e = new _DPfsctrlEvents_OnDoubleClick2Event(type, iD, modelType);
		parent.RaiseOnOnDoubleClick2(parent, e);
	}

	public virtual void OnCancelInsertMode()
	{
		EventArgs e = new EventArgs();
		parent.RaiseOnOnCancelInsertMode(parent, e);
	}

	public virtual void ModelUpdate(string iD, string modelType)
	{
		_DPfsctrlEvents_ModelUpdateEvent e = new _DPfsctrlEvents_ModelUpdateEvent(iD, modelType);
		parent.RaiseOnModelUpdate(parent, e);
	}

	public virtual void BeforeRenameModel(string iD)
	{
		_DPfsctrlEvents_BeforeRenameModelEvent e = new _DPfsctrlEvents_BeforeRenameModelEvent(iD);
		parent.RaiseOnBeforeRenameModel(parent, e);
	}

	public virtual void OnCancelLibBarHalfStreamInsertMode()
	{
		EventArgs e = new EventArgs();
		parent.RaiseOnOnCancelLibBarHalfStreamInsertMode(parent, e);
	}

	public virtual void OnZoomChanged(float oldScale, float newScale)
	{
		_DPfsctrlEvents_OnZoomChangedEvent e = new _DPfsctrlEvents_OnZoomChangedEvent(oldScale, newScale);
		parent.RaiseOnOnZoomChanged(parent, e);
	}

	public virtual void ManageViewChanged()
	{
		EventArgs e = new EventArgs();
		parent.RaiseOnManageViewChanged(parent, e);
	}

	public virtual void UndoRedoChanged()
	{
		EventArgs e = new EventArgs();
		parent.RaiseOnUndoRedoChanged(parent, e);
	}

	public virtual void LoadingWPFForm(string bstrPath, int iFormType, int iTargetClass)
	{
		_DPfsctrlEvents_LoadingWPFFormEvent e = new _DPfsctrlEvents_LoadingWPFFormEvent(bstrPath, iFormType, iTargetClass);
		parent.RaiseOnLoadingWPFForm(parent, e);
	}

	public virtual void DeleteWPFForm(string bstrPath, string bstrFormType)
	{
		_DPfsctrlEvents_DeleteWPFFormEvent e = new _DPfsctrlEvents_DeleteWPFFormEvent(bstrPath, bstrFormType);
		parent.RaiseOnDeleteWPFForm(parent, e);
	}

	public virtual void GetObjectDescriptionText(string bstrPath, int nObjectType)
	{
		_DPfsctrlEvents_GetObjectDescriptionTextEvent e = new _DPfsctrlEvents_GetObjectDescriptionTextEvent(bstrPath, nObjectType);
		parent.RaiseOnGetObjectDescriptionText(parent, e);
	}

	public virtual void BlockVisibleChanging(string bstrType)
	{
		_DPfsctrlEvents_BlockVisibleChangingEvent e = new _DPfsctrlEvents_BlockVisibleChangingEvent(bstrType);
		parent.RaiseOnBlockVisibleChanging(parent, e);
	}

	public virtual void OnDropFiles(string varFiles)
	{
		_DPfsctrlEvents_OnDropFilesEvent e = new _DPfsctrlEvents_OnDropFilesEvent(varFiles);
		parent.RaiseOnOnDropFiles(parent, e);
	}

	public virtual void UpdateFlipRotateStatus()
	{
		EventArgs e = new EventArgs();
		parent.RaiseOnUpdateFlipRotateStatus(parent, e);
	}

	public virtual void DeleteBlockObject(string bstrID, string bstrObjectType)
	{
		_DPfsctrlEvents_DeleteBlockObjectEvent e = new _DPfsctrlEvents_DeleteBlockObjectEvent(bstrID, bstrObjectType);
		parent.RaiseOnDeleteBlockObject(parent, e);
	}

	public virtual void RenameBlockObject(string bstrOldName, string bstrNewName, string bstrObjectType)
	{
		_DPfsctrlEvents_RenameBlockObjectEvent e = new _DPfsctrlEvents_RenameBlockObjectEvent(bstrOldName, bstrNewName, bstrObjectType);
		parent.RaiseOnRenameBlockObject(parent, e);
	}

	public virtual void PSVAttachedPSVToStream(string bstrStreamFullPath, string bstrPSVName)
	{
		_DPfsctrlEvents_PSVAttachedPSVToStreamEvent e = new _DPfsctrlEvents_PSVAttachedPSVToStreamEvent(bstrStreamFullPath, bstrPSVName);
		parent.RaiseOnPSVAttachedPSVToStream(parent, e);
	}

	public virtual void BeginInsertPSVBlock()
	{
		EventArgs e = new EventArgs();
		parent.RaiseOnBeginInsertPSVBlock(parent, e);
	}

	public virtual void FinishInsertPSVBlock()
	{
		EventArgs e = new EventArgs();
		parent.RaiseOnFinishInsertPSVBlock(parent, e);
	}

	public virtual void GetStreamPSVName(string bstrStreamFullPath, int iObjectType)
	{
		_DPfsctrlEvents_GetStreamPSVNameEvent e = new _DPfsctrlEvents_GetStreamPSVNameEvent(bstrStreamFullPath, iObjectType);
		parent.RaiseOnGetStreamPSVName(parent, e);
	}

	public virtual void OnDeletePSVBlock(string bstrStreamID, string bstrPSVName)
	{
		_DPfsctrlEvents_OnDeletePSVBlockEvent e = new _DPfsctrlEvents_OnDeletePSVBlockEvent(bstrStreamID, bstrPSVName);
		parent.RaiseOnOnDeletePSVBlock(parent, e);
	}

	public virtual void OnAddPSVBlock(string bstrStreamFullPath, int iPSVObjectType)
	{
		_DPfsctrlEvents_OnAddPSVBlockEvent e = new _DPfsctrlEvents_OnAddPSVBlockEvent(bstrStreamFullPath, iPSVObjectType);
		parent.RaiseOnOnAddPSVBlock(parent, e);
	}

	public virtual void OnGetPSVBlockDescription(int iBlockType, string bstrBlockName)
	{
		_DPfsctrlEvents_OnGetPSVBlockDescriptionEvent e = new _DPfsctrlEvents_OnGetPSVBlockDescriptionEvent(iBlockType, bstrBlockName);
		parent.RaiseOnOnGetPSVBlockDescription(parent, e);
	}

	public virtual void OnRequestPSVBlockType(string bstrPSVBlockIDs)
	{
		_DPfsctrlEvents_OnRequestPSVBlockTypeEvent e = new _DPfsctrlEvents_OnRequestPSVBlockTypeEvent(bstrPSVBlockIDs);
		parent.RaiseOnOnRequestPSVBlockType(parent, e);
	}

	public virtual void OnPSVBlockExchangeType(string bstrPSVBlockID, int iOldType, int iNewType)
	{
		_DPfsctrlEvents_OnPSVBlockExchangeTypeEvent e = new _DPfsctrlEvents_OnPSVBlockExchangeTypeEvent(bstrPSVBlockID, iOldType, iNewType);
		parent.RaiseOnOnPSVBlockExchangeType(parent, e);
	}

	public virtual void OnGetPSVBlockErrorLevel(string bstrPSVBlockID)
	{
		_DPfsctrlEvents_OnGetPSVBlockErrorLevelEvent e = new _DPfsctrlEvents_OnGetPSVBlockErrorLevelEvent(bstrPSVBlockID);
		parent.RaiseOnOnGetPSVBlockErrorLevel(parent, e);
	}

	public virtual void CreateBlock(string bstrBlockID, string bstrBlockType)
	{
		_DPfsctrlEvents_CreateBlockEvent e = new _DPfsctrlEvents_CreateBlockEvent(bstrBlockID, bstrBlockType);
		parent.RaiseOnCreateBlock(parent, e);
	}

	public virtual void OnEditStreamSummaryForm(string bstrObjectName, int iTargetObjectClass)
	{
		_DPfsctrlEvents_OnEditStreamSummaryFormEvent e = new _DPfsctrlEvents_OnEditStreamSummaryFormEvent(bstrObjectName, iTargetObjectClass);
		parent.RaiseOnOnEditStreamSummaryForm(parent, e);
	}

	public virtual void CreateStream(string strStreamID, string strStreamType, string conectBlock1, string conectBlock2)
	{
		_DPfsctrlEvents_CreateStreamEvent e = new _DPfsctrlEvents_CreateStreamEvent(strStreamID, strStreamType, conectBlock1, conectBlock2);
		parent.RaiseOnCreateStream(parent, e);
	}

	public virtual void ScanConnect(string streamName, string blockName, string connectType, int direction)
	{
		_DPfsctrlEvents_ScanConnectEvent e = new _DPfsctrlEvents_ScanConnectEvent(streamName, blockName, connectType, direction);
		parent.RaiseOnScanConnect(parent, e);
	}
}
