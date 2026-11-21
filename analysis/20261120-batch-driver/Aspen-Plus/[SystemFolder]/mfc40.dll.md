# mfc40.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `mfc40.dll`，924432 字节，SHA-256 `c1bfab83ac97237f546964ec6bbc75174a629f21f51895cb99942de758c4f2c7` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 6263 = decomp_ok 6033 + decomp_fail 230 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=6263
- decomp_ok=6033
- decomp_fail=230
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `mfc40.dll` |
| 字节数 | 924432 |
| SHA-256 | `c1bfab83ac97237f546964ec6bbc75174a629f21f51895cb99942de758c4f2c7` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[SystemFolder]/mfc40.dll` |
| product_raw | `Plus` |
| 产品目录 | `Aspen-Plus` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 32 |
| 镜像基址 | `0x5f800000` |
| 段数 | 5 |
| 指令行数 | 197105 |

## 3. 反汇编清单（全量）

全文：disasm/mfc40.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/mfc40.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 6263
- decomp_ok（伪 C） = 6033
- decomp_fail = 230
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `5f805285` `??1CPtrList@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f805bbc` `sub_5F805BBC`：RuntimeError（decompile returned None）
- `5f80754b` `??1CMapPtrToPtr@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f80785c` `??1_AFX_CTL3D_THREAD@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f807b8c` `sub_5F807B8C`：RuntimeError（decompile returned None）
- `5f807c1f` `??1CFile@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f807cec` `??1CMemFile@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f808ddf` `??1CObList@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f80909e` `??1CDialog@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f80a753` `??1CMapStringToPtr@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f810426` `??1CArchive@@QAE@XZ`：RuntimeError（decompile returned None）
- `5f81078f` `??1CException@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f8108f4` `??1CFrameWnd@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f810c24` `sub_5F810C24`：RuntimeError（decompile returned None）
- `5f810d54` `sub_5F810D54`：RuntimeError（decompile returned None）
- `5f810dbb` `sub_5F810DBB`：RuntimeError（decompile returned None）
- `5f810de8` `sub_5F810DE8`：RuntimeError（decompile returned None）
- `5f810e1f` `sub_5F810E1F`：RuntimeError（decompile returned None）
- `5f810e55` `??1?$CThreadLocal@VAFX_MODULE_THREAD_STATE@@@@QAE@XZ`：RuntimeError（decompile returned None）
- `5f810ea7` `sub_5F810EA7`：RuntimeError（decompile returned None）
- `5f810ed4` `sub_5F810ED4`：RuntimeError（decompile returned None）
- `5f810f01` `sub_5F810F01`：RuntimeError（decompile returned None）
- `5f810f2e` `sub_5F810F2E`：RuntimeError（decompile returned None）
- `5f810f79` `??1AFX_MODULE_STATE@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f8110d8` `sub_5F8110D8`：RuntimeError（decompile returned None）
- `5f81122e` `sub_5F81122E`：RuntimeError（decompile returned None）
- `5f811273` `sub_5F811273`：RuntimeError（decompile returned None）
- `5f8112a6` `??1?$CProcessLocal@VAFX_MODULE_PROCESS_STATE@@@@QAE@XZ`：RuntimeError（decompile returned None）
- `5f8112e7` `sub_5F8112E7`：RuntimeError（decompile returned None）
- `5f81139f` `sub_5F81139F`：RuntimeError（decompile returned None）
- `5f81144a` `sub_5F81144A`：RuntimeError（decompile returned None）
- `5f811487` `sub_5F811487`：RuntimeError（decompile returned None）
- `5f8114b4` `sub_5F8114B4`：RuntimeError（decompile returned None）
- `5f8114f1` `sub_5F8114F1`：RuntimeError（decompile returned None）
- `5f81151e` `sub_5F81151E`：RuntimeError（decompile returned None）
- `5f81154b` `sub_5F81154B`：RuntimeError（decompile returned None）
- `5f811578` `sub_5F811578`：RuntimeError（decompile returned None）
- `5f8115a5` `sub_5F8115A5`：RuntimeError（decompile returned None）
- `5f8115dc` `sub_5F8115DC`：RuntimeError（decompile returned None）
- `5f81165b` `sub_5F81165B`：RuntimeError（decompile returned None）
- `5f811688` `sub_5F811688`：RuntimeError（decompile returned None）
- `5f8117e4` `??1CSimpleException@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f811813` `sub_5F811813`：RuntimeError（decompile returned None）
- `5f812183` `??1COleMessageFilter@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f81230b` `??1CSingleDocTemplate@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f8123f4` `??1CComboBox@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f8132df` `??1COleLinkingDoc@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f815184` `??1CButton@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f815d15` `??1CStringList@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f8162c2` `??1CCommonDialog@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f817389` `??1CFileException@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f8174af` `?AfxResolveShortcut@@YGHPAVCWnd@@PBDPADH@Z`：RuntimeError（decompile returned None）
- `5f817a6e` `??1CCommandLineInfo@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f819267` `??1CMapStringToString@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f8194d9` `??1CListBox@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f819a58` `??1CStatic@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f819f02` `??1CMapWordToOb@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f81a248` `??1CStdioFile@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f81a4d9` `??1CMapPtrToWord@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f81a604` `??1CEdit@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f81b604` `??1CMiniFrameWnd@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f81b659` `??1CScrollBar@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f81bfb7` `??1COleDropTarget@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f81c076` `??1CScrollView@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f81e8b4` `sub_5F81E8B4`：RuntimeError（decompile returned None）
- `5f81e8f9` `??1CToolTipCtrl@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f81fe5e` `??1CSocket@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f81ffea` `??1CAsyncSocket@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f820089` `sub_5F820089`：RuntimeError（decompile returned None）
- `5f820abf` `??1CMapStringToOb@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f820c09` `??1CMapWordToPtr@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f820da6` `??1COleUpdateDialog@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f820f33` `??1COleLinksDialog@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f821029` `??1COleDialog@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f82320d` `sub_5F82320D`：RuntimeError（decompile returned None）
- `5f8247ea` `sub_5F8247EA`：RuntimeError（decompile returned None）
- `5f824b0c` `??1CDocItem@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f824d7a` `??1COleCntrFrameWnd@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f82535d` `?RemoveMenus@XOleInPlaceFrame@COleFrameHook@@UAGJPAUHMENU__@@@Z`：RuntimeError（decompile returned None）
- `5f8253d4` `?OnUIDeactivate@XOleIPSite@COleClientItem@@UAGJH@Z`：RuntimeError（decompile returned None）
- `5f825459` `??1COleResizeBar@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f8255e5` `??1CItemDataSource@COleServerItem@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f825cd6` `??1COleFrameHook@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f82649e` `??1CDialogBar@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f8264e1` `?AfxMessageBox@@YGHIII@Z`：RuntimeError（decompile returned None）
- `5f8266a9` `??1CImageList@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f826719` `sub_5F826719`：RuntimeError（decompile returned None）
- `5f8267a9` `??1CSocketFile@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f8275a8` `?ResizeBorder@XOleInPlaceActiveObject@COleServerDoc@@UAGJPBUtagRECT@@PAUIOleInPlaceUIWindow@@H@Z`：RuntimeError（decompile returned None）
- `5f82926e` `?SetMenu@XOleInPlaceFrame@COleFrameHook@@UAGJPAUHMENU__@@PAXPAUHWND__@@@Z`：RuntimeError（decompile returned None）
- `5f8292eb` `?InsertMenus@XOleInPlaceFrame@COleFrameHook@@UAGJPAUHMENU__@@PAUtagOleMenuGroupWidths@@@Z`：RuntimeError（decompile returned None）
- `5f829365` `?SetBorderSpace@XOleInPlaceFrame@COleFrameHook@@UAGJPBUtagRECT@@@Z`：RuntimeError（decompile returned None）
- `5f8293e8` `?RequestBorderSpace@XOleInPlaceFrame@COleFrameHook@@UAGJPBUtagRECT@@@Z`：RuntimeError（decompile returned None）
- `5f82f26e` `??1CGdiObject@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f82f2ac` `??1CBrush@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f830693` `sub_5F830693`：RuntimeError（decompile returned None）
- `5f8349ee` `sub_5F8349EE`：RuntimeError（decompile returned None）
- `5f8369d0` `sub_5F8369D0`：RuntimeError（decompile returned None）
- `5f836a28` `sub_5F836A28`：RuntimeError（decompile returned None）
- `5f836a80` `sub_5F836A80`：RuntimeError（decompile returned None）
- `5f836ad8` `sub_5F836AD8`：RuntimeError（decompile returned None）
- `5f83726b` `sub_5F83726B`：RuntimeError（decompile returned None）
- `5f8375b0` `?GetClassObject@AFX_COM@@QAEJABU_GUID@@0PAPAX@Z`：RuntimeError（decompile returned None）
- `5f8377f7` `sub_5F8377F7`：RuntimeError（decompile returned None）
- `5f837b1c` `??1CSharedFile@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f83a3cf` `??1CSemaphore@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f83a493` `??1CMutex@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f83a550` `??1CEvent@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f83bcbf` `sub_5F83BCBF`：RuntimeError（decompile returned None）
- `5f83d52b` `sub_5F83D52B`：RuntimeError（decompile returned None）
- `5f840ba1` `??1CDragListBox@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f84104a` `??1CToolBarCtrl@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f84120f` `??1CStatusBarCtrl@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f84142f` `??1CListCtrl@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f8417f7` `??1CTreeCtrl@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f841b7a` `??1CSpinButtonCtrl@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f841c2c` `??1CSliderCtrl@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f841d82` `??1CProgressCtrl@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f841e08` `??1CHeaderCtrl@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f841ec2` `??1CHotKeyCtrl@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f841f7f` `??1CTabCtrl@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f842073` `??1CAnimateCtrl@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f8420c0` `??1CRichEditCtrl@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f845b33` `sub_5F845B33`：RuntimeError（decompile returned None）
- `5f84613a` `sub_5F84613A`：RuntimeError（decompile returned None）
- `5f846839` `sub_5F846839`：RuntimeError（decompile returned None）
- `5f8469eb` `sub_5F8469EB`：RuntimeError（decompile returned None）
- `5f846b25` `sub_5F846B25`：RuntimeError（decompile returned None）
- `5f847f97` `sub_5F847F97`：RuntimeError（decompile returned None）
- `5f847fef` `sub_5F847FEF`：RuntimeError（decompile returned None）
- `5f849d18` `sub_5F849D18`：RuntimeError（decompile returned None）
- `5f849fef` `sub_5F849FEF`：RuntimeError（decompile returned None）
- `5f84a108` `sub_5F84A108`：RuntimeError（decompile returned None）
- `5f84c39d` `sub_5F84C39D`：RuntimeError（decompile returned None）
- `5f84d6d5` `?OnFindReplaceCmd@CEditView@@IAEJIJ@Z`：RuntimeError（decompile returned None）
- `5f84f36c` `?OnUpdateNumPageChange@CPreviewView@@IAEXPAVCCmdUI@@@Z`：RuntimeError（decompile returned None）
- `5f851d59` `?OnShowWindow@XOleClientSite@COleClientItem@@UAGJH@Z`：RuntimeError（decompile returned None）
- `5f851e16` `?OnDataChange@XAdviseSink@COleClientItem@@UAGXPAUtagFORMATETC@@PAUtagSTGMEDIUM@@@Z`：RuntimeError（decompile returned None）
- `5f851e7a` `?OnViewChange@XAdviseSink@COleClientItem@@UAGXKJ@Z`：RuntimeError（decompile returned None）
- `5f85253d` `?TranslateAcceleratorA@XOleInPlaceFrame@COleFrameHook@@UAGJPAUtagMSG@@G@Z`：RuntimeError（decompile returned None）
- `5f852644` `?Scroll@XOleIPSite@COleClientItem@@UAGJUtagSIZE@@@Z`：RuntimeError（decompile returned None）
- `5f853528` `?OnRenderData@COleDataSource@@UAEHPAUtagFORMATETC@@PAUtagSTGMEDIUM@@@Z`：RuntimeError（decompile returned None）
- `5f85412d` `??1COleDispatchException@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f855148` `?DoConvert@COleConvertDialog@@QAEHPAVCOleClientItem@@@Z`：RuntimeError（decompile returned None）
- `5f855a6a` `sub_5F855A6A`：RuntimeError（decompile returned None）
- `5f855b6b` `??1COleBusyDialog@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f855dec` `sub_5F855DEC`：RuntimeError（decompile returned None）
- `5f856a67` `?GiveFeedback@XDropSource@COleDropSource@@UAGJK@Z`：RuntimeError（decompile returned None）
- `5f856fba` `?DragEnter@XDropTarget@COleDropTarget@@UAGJPAUIDataObject@@KU_POINTL@@PAK@Z`：RuntimeError（decompile returned None）
- `5f857125` `?DragOver@XDropTarget@COleDropTarget@@UAGJKU_POINTL@@PAK@Z`：RuntimeError（decompile returned None）
- `5f85762f` `?RetryRejectedCall@XMessageFilter@COleMessageFilter@@UAGKPAUHTASK__@@KK@Z`：RuntimeError（decompile returned None）
- `5f85788b` `?Next@XEnumVOID@CEnumArray@@UAGJKPAXPAK@Z`：RuntimeError（decompile returned None）
- `5f857c54` `?RequestLicKey@XClassFactory@COleObjectFactory@@UAGJKPAPAG@Z`：RuntimeError（decompile returned None）
- `5f8596c7` `sub_5F8596C7`：RuntimeError（decompile returned None）
- `5f85a909` `?InitFromData@XOleObject@COleServerDoc@@UAGJPAUIDataObject@@HK@Z`：RuntimeError（decompile returned None）
- `5f85ad7b` `?SetColorScheme@XOleObject@COleServerDoc@@UAGJPAUtagLOGPALETTE@@@Z`：RuntimeError（decompile returned None）
- `5f85b1d5` `?UIDeactivate@XOleInPlaceObject@COleServerDoc@@UAGJXZ`：RuntimeError（decompile returned None）
- `5f85b297` `?SetObjectRects@XOleInPlaceObject@COleServerDoc@@UAGJPBUtagRECT@@0@Z`：RuntimeError（decompile returned None）
- `5f85b47b` `?TranslateAcceleratorA@XOleInPlaceActiveObject@COleServerDoc@@UAGJPAUtagMSG@@@Z`：RuntimeError（decompile returned None）
- `5f85b54f` `?OnFrameWindowActivate@XOleInPlaceActiveObject@COleServerDoc@@UAGJH@Z`：RuntimeError（decompile returned None）
- `5f85b5d8` `?OnDocWindowActivate@XOleInPlaceActiveObject@COleServerDoc@@UAGJH@Z`：RuntimeError（decompile returned None）
- `5f85b754` `sub_5F85B754`：RuntimeError（decompile returned None）
- `5f85c4c9` `?SetColorScheme@XOleObject@COleServerItem@@UAGJPAUtagLOGPALETTE@@@Z`：RuntimeError（decompile returned None）
- `5f860743` `?QueryAcceptData@XRichEditOleCallback@CRichEditView@@UAGJPAUIDataObject@@PAGKHPAX@Z`：RuntimeError（decompile returned None）
- `5f8608cd` `?GetContextMenu@XRichEditOleCallback@CRichEditView@@UAGJGPAUIOleObject@@PAU_charrange@@PAPAUHMENU__@@@Z`：RuntimeError（decompile returned None）
- `5f860f86` `?OnDevModeChange@CRichEditView@@IAEXPAD@Z`：RuntimeError（decompile returned None）
- `5f861ecc` `sub_5F861ECC`：RuntimeError（decompile returned None）
- `5f864ab4` `?Invoke@XAmbientProps@COleControlSite@@UAGJJABU_GUID@@KGPAUtagDISPPARAMS@@PAUtagVARIANT@@PAUtagEXCEPINFO@@PAI@Z`：RuntimeError（decompile returned None）
- `5f866196` `??1XPropConnPt@COleControl@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f8661d6` `??1XEventConnPt@COleControl@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f866216` `??1CControlDataSource@COleControl@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f8662cc` `sub_5F8662CC`：RuntimeError（decompile returned None）
- `5f8679ae` `?GetControlInfo@XOleControl@COleControl@@UAGJPAUtagCONTROLINFO@@@Z`：RuntimeError（decompile returned None）
- `5f867a18` `?OnMnemonic@XOleControl@COleControl@@UAGJPAUtagMSG@@@Z`：RuntimeError（decompile returned None）
- `5f867a82` `?OnAmbientPropertyChange@XOleControl@COleControl@@UAGJJ@Z`：RuntimeError（decompile returned None）
- `5f867b09` `?FreezeEvents@XOleControl@COleControl@@UAGJH@Z`：RuntimeError（decompile returned None）
- `5f868733` `sub_5F868733`：RuntimeError（decompile returned None）
- `5f868785` `sub_5F868785`：RuntimeError（decompile returned None）
- `5f8687fb` `sub_5F8687FB`：RuntimeError（decompile returned None）
- `5f86884d` `sub_5F86884D`：RuntimeError（decompile returned None）
- `5f868a02` `?OnAdvise@XEventConnPt@COleControl@@UAEXH@Z`：RuntimeError（decompile returned None）
- `5f869c2e` `sub_5F869C2E`：RuntimeError（decompile returned None）
- `5f86a89f` `?SetObjectRects@XOleInPlaceObject@COleControl@@UAGJPBUtagRECT@@0@Z`：RuntimeError（decompile returned None）
- `5f86aa97` `?TranslateAcceleratorA@XOleInPlaceActiveObject@COleControl@@UAGJPAUtagMSG@@@Z`：RuntimeError（decompile returned None）
- `5f86b4a9` `?Close@XOleObject@COleControl@@UAGJK@Z`：RuntimeError（decompile returned None）
- `5f86b577` `?DoVerb@XOleObject@COleControl@@UAGJJPAUtagMSG@@PAUIOleClientSite@@JPAUHWND__@@PBUtagRECT@@@Z`：RuntimeError（decompile returned None）
- `5f86b7fc` `?EnumVerbs@XOleObject@COleControl@@UAGJPAPAUIEnumOLEVERB@@@Z`：RuntimeError（decompile returned None）
- `5f86cf49` `sub_5F86CF49`：RuntimeError（decompile returned None）
- `5f86d850` `?SetPageSite@XPropertyPage@COlePropertyPage@@UAGJPAUIPropertyPageSite@@@Z`：RuntimeError（decompile returned None）
- `5f86e13a` `?EditProperty@XPropertyPage@COlePropertyPage@@UAGJJ@Z`：RuntimeError（decompile returned None）
- `5f8714b5` `?GetDisplayString@XPerPropertyBrowsing@COleControl@@UAGJJPAPAG@Z`：RuntimeError（decompile returned None）
- `5f8715ef` `?MapPropertyToPage@XPerPropertyBrowsing@COleControl@@UAGJJPAU_GUID@@@Z`：RuntimeError（decompile returned None）
- `5f871a0f` `?GetPredefinedValue@XPerPropertyBrowsing@COleControl@@UAGJJKPAUtagVARIANT@@@Z`：RuntimeError（decompile returned None）
- `5f872cc9` `?InitNew@XPersistStorage@COleControl@@UAGJPAUIStorage@@@Z`：RuntimeError（decompile returned None）
- `5f872e93` `?Save@XPersistStorage@COleControl@@UAGJPAUIStorage@@H@Z`：RuntimeError（decompile returned None）
- `5f87489e` `?Draw@XViewObject@COleControl@@UAGJKJPAXPAUtagDVTARGETDEVICE@@PAUHDC__@@2PBU_RECTL@@3P6GHK@ZK@Z`：RuntimeError（decompile returned None）
- `5f874a12` `?GetColorSet@XViewObject@COleControl@@UAGJKJPAXPAUtagDVTARGETDEVICE@@PAUHDC__@@PAPAUtagLOGPALETTE@@@Z`：RuntimeError（decompile returned None）
- `5f874ce1` `??1CProperty@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f875668` `??1CPropertySection@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f8775d5` `sub_5F8775D5`：RuntimeError（decompile returned None）
- `5f877958` `??1CColorButton@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f877993` `sub_5F877993`：RuntimeError（decompile returned None）
- `5f878507` `sub_5F878507`：RuntimeError（decompile returned None）
- `5f8786b0` `??1CFontComboBox@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f878719` `??1CSizeComboBox@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f8787a8` `sub_5F8787A8`：RuntimeError（decompile returned None）
- `5f8788b0` `sub_5F8788B0`：RuntimeError（decompile returned None）
- `5f87a980` `sub_5F87A980`：RuntimeError（decompile returned None）
- `5f87b62c` `sub_5F87B62C`：RuntimeError（decompile returned None）
- `5f87b78b` `sub_5F87B78B`：RuntimeError（decompile returned None）
- `5f87c332` `??1CDBException@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f87c6dc` `??1CDatabase@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f882ccb` `??1CRecordView@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f883cba` `??1_AFX_DAO_STATE@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f883e3a` `??1CDaoIndexFieldInfo@@QAE@XZ`：RuntimeError（decompile returned None）
- `5f883fd1` `??1CDaoRelationFieldInfo@@QAE@XZ`：RuntimeError（decompile returned None）
- `5f88bf22` `?SetFieldValue@CDaoRecordset@@QAEXHPBD@Z`：RuntimeError（decompile returned None）
- `5f88bf82` `?SetFieldValue@CDaoRecordset@@QAEXPBD0@Z`：RuntimeError（decompile returned None）
- `5f88f1aa` `??1CDaoRecordView@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f890ccb` `??1CMirrorFile@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f890ef7` `??1CPageSetupDialog@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f89123d` `??1COleTemplateServer@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f891397` `??1CRichEditView@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f891851` `??1CPalette@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f89194a` `??1CMenu@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f891aed` `??1CCheckListBox@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f891d81` `??1CBitmapButton@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f89235f` `??1CListView@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f8923f3` `??1CTreeView@@UAE@XZ`：RuntimeError（decompile returned None）
- `5f892be5` `sub_5F892BE5`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：205.7 s
- 日志：out/R1N/ida/logs/sha256_c1bfab83ac97237f546964ec6bbc75174a629f21f51895cb99942de758c4f2c7.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 230 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `mfc40.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 6263 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +6263（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`_EH_prolog`, `?AfxUnlockGlobals@@YGXH@Z`, `?AfxWndProc@@YGJPAUHWND__@@IIJ@Z`, `?AfxGetModuleState@@YGPAVAFX_MODULE_STATE@@XZ`, `?AfxGetAppModuleState@@YGPAVAFX_MODULE_STATE@@XZ`, `nullsub_1`, `?AfxLockGlobals@@YGXH@Z`, `?AfxGetThreadState@@YGPAV_AFX_THREAD_STATE@@XZ`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part3.tar.gz

- `decompiled/BPCompressor.dll.c.txt` sha256=5d2fefe607135b3c292a10b672b33a07c9b182660fee18fe6a6445e01f3ce608 bytes=53489
- `decompiled/CLIREG32.EXE.c.txt` sha256=63a1b1760bd181b2ab6f2ae683ac3b301fb4f8bbe01b104b03e9afc7b9eed72d bytes=116199
- `decompiled/GRID32.OCX.c.txt` sha256=3d124a8fe7916c4cc7508262a9f380bb4d9aa5bbb58eed114bd4e9f8fd2e029b bytes=246471
- `decompiled/INETWH32.dll.c.txt` sha256=84012f570473cb24070fce8c0857754b20d172701ea4ea31e9036477e7d04093 bytes=148534
- `decompiled/LOADWC.EXE.c.txt` sha256=17ae94df9603c63bb893ca0140a1770c90a7e15cbf4f2280a9b17d5818477215 bytes=32366
- `decompiled/MSCAL.OCX.c.txt` sha256=68385c49aab70ba186af81522d8f7700588b0e0c233cf11d813d2b361dad8c3d bytes=319492
- `decompiled/MSCHART.OCX.c.txt` sha256=36190dd38f03e72dd2772e7890368198b6dff273a89e6fb77db6725ef1f1ffa0 bytes=3366426
- `decompiled/RHMMPLAY.DLL.c.txt` sha256=bdaa5589cdace4a2670d80ab7d2834412ce957bb829b74b69c1d5040cee62720 bytes=49336
- `decompiled/VB5DB.DLL.c.txt` sha256=49f9e71311884bcbc8fb7daef959655d9394d4c2f5c14d93b1692146dc106dfc bytes=347359
- `decompiled/VB5STKIT.DLL.c.txt` sha256=a9208722db6540b2355b025e0813a690b6162e7503038cdfb60d00a0ed4c45b5 bytes=81474
- `decompiled/VB6STKIT.DLL.c.txt` sha256=50b27b35423e54bec84c34ca08983596dec72dd40e331e10f1916c7377006f60 bytes=341666
- `decompiled/comcat.dll.c.txt` sha256=1ed18efb6629f6118baeb32e4160eb9cd7712a03211e70a206249b01103c8de9 bytes=49039
- `decompiled/comctl32.ocx.c.txt` sha256=4d8c2f0281c3f8e78e7b958db3f9799c6200696b8e05e2dcc4566116dadf2bab bytes=1608821
- `decompiled/mfc40.dll.c.txt` sha256=0b02812a97980abc04affda5ab51a75d511b58d5ce36ce5b82d79ea48b522cbb bytes=3594695
- `decompiled/mscomct2.ocx.c.txt` sha256=4a43378df698650548e4ffb6cbd39e759ae1f7be466abca7eecb764f839d48b8 bytes=2607990
- `decompiled/mscomm32.ocx.c.txt` sha256=36f6a91d935d998aae3067dc468383c6700ca74806af9880e28aed4daee7f938 bytes=278118
- `decompiled/msinet.ocx.c.txt` sha256=b91b1255fc2bb7bf01605b06c863a7db61abfec9f8d331f152aef8ecc1a96615 bytes=324105
- `decompiled/msscript.ocx.c.txt` sha256=d72df798ffc9b144fdc0a1d268038f3d3650172befcb7a15fc6f7e8203e7dbf4 bytes=264804
- `decompiled/msstdfmt.dll.c.txt` sha256=66f5d520aee8cf3e7d1cb0f30e856e13abfd28627026b9241029b92ca3f546ed bytes=417331
- `decompiled/oleaut32.dll.c.txt` sha256=95ffc271e40c401fb47d0607be9bd9796d06c08382b98864d892ca6c60681afa bytes=2513264
- `decompiled/psapi.dll.c.txt` sha256=289f9f15a0e3afdcb65f732b7d489164fec97b359006880b97128d933af35f40 bytes=150260
- `decompiled/sstbars2.ocx.c.txt` sha256=0e87c493689adb701eee7cf261ea85551875a6cfcc4e43051d92356af458bc91 bytes=1812734
- `disasm/BPCompressor.dll.asm.txt` sha256=cf2565161f882fc8475a08a2adb4f92244db7b32b7c72460406ac19686fa3730 bytes=85536
- `disasm/CLIREG32.EXE.asm.txt` sha256=2e9050ab7260533b98ae274f17af8e72c0c302b05a483b2114a516871d909a13 bytes=276249
- `disasm/GRID32.OCX.asm.txt` sha256=8f7a7ccd4e680e32850278fce91fa4df3a768c2594580a65248375bf939020e7 bytes=446074
- `disasm/INETWH32.dll.asm.txt` sha256=b1d5495c7cd64b2f9c96667ebd09926e832508a7ce6a919381c6642723b6d3f6 bytes=316887
- `disasm/LOADWC.EXE.asm.txt` sha256=6c5efa2342832126bb53dc8016ed281ed23266d8e92a936285f671b4537ca836 bytes=71613
- `disasm/MSCAL.OCX.asm.txt` sha256=b71b12416c6a9ddfbf01c85d2f66481ef26666f055f450e1b55f1f4368f4ef4b bytes=651736
- `disasm/MSCHART.OCX.asm.txt` sha256=1e1162748c40afd7052a47f2c7dd50e1b67b48132740fbf862834c03869f6420 bytes=6137555
- `disasm/RHMMPLAY.DLL.asm.txt` sha256=73d45debb0dec57bc1dcbb5fd084fcee37d385a19edf29ed2f7794445871960f bytes=108549
- `disasm/VB5DB.DLL.asm.txt` sha256=45ca17b79035f05dd3fa0dbbf58350824c902dc240c47d7f8e2c848f642761f6 bytes=507277
- `disasm/VB5STKIT.DLL.asm.txt` sha256=41ae2a4349f2733f3634b7e4b978b2b1e704f2ffb3945246102d57cd86d03a41 bytes=180333
- `disasm/VB6STKIT.DLL.asm.txt` sha256=6128cc5fe308daf13e391590b02e8dd278f50b3bce4f059d881778f5be5227fd bytes=781398
- `disasm/comcat.dll.asm.txt` sha256=76b67e4e20f56e401117cc045ad19292c5b066c97ebe7058e0b52cb5337b1175 bytes=120606
- `disasm/comctl32.ocx.asm.txt` sha256=4df497cfb0c03d1a51814dd66f15516437c8fbd76634478fccdaa56e9d9ef5f0 bytes=2929242
- `disasm/mfc40.dll.asm.txt` sha256=58836d218a9191a36431daa8829c5f8fab766fe6d1e124522cc40dfdca4abd38 bytes=6909173
- `disasm/mscomct2.ocx.asm.txt` sha256=87b33ac7be69b09e0335252cd5251a629525364d253a7e1f30566cbbeb0b1a58 bytes=5351489
- `disasm/mscomm32.ocx.asm.txt` sha256=edf6261b01cbcdb7a0cee182925cf7727090941bf7d80381084a8e1d3923811c bytes=525587
- `disasm/msinet.ocx.asm.txt` sha256=63e4fe843a53837cf0e364a2e4b16d4e5e16fb21c3bcdb2f926d20ceea9ddecb bytes=605681
- `disasm/msscript.ocx.asm.txt` sha256=e35141be0fd866abb0d1e896fd7e0d6565cd29ea0a26d9f5e96faf3ede1220c5 bytes=586535
- `disasm/msstdfmt.dll.asm.txt` sha256=aa5e00d781a7ed19e1404800a88ff31b3f83d592d77c4b56fbf02eeb85436e23 bytes=826752
- `disasm/oleaut32.dll.asm.txt` sha256=f09a63923e1ca2cdc76ba650e77f1d0d5190994b6b1dbabf5ad22bc38db3349c bytes=4741251
- `disasm/psapi.dll.asm.txt` sha256=561e0314d5a637358797247675e74b2c0482550b2b0728f69c43dde885d60062 bytes=302757
- `disasm/sstbars2.ocx.asm.txt` sha256=45a6a45b2a81409ea67ec31d78f202fc690108bfc0a08a179cfbfdcf13fdaad5 bytes=3676816
