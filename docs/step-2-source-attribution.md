# 第 2 步｜现有源码与 Aspen Plus V15 原版文件对照

下方项目文件与功能对应表为旧 Qt 工程的历史研究记录。当前反编译归档按完成状态组织，见[当前源码归档](#当前源码归档)。

盘点日期 2026-11-18。源码基准为 `4ffcad5d7ea2aa168410a417dba87bab01c6c860`。本表覆盖 `src/` 的 45 个文件和研究工具，共 45 条功能记录，其中 40 条有证据的部分计入第 2 步。同一源码可以有多条记录。第 2 步对应[逐文件分析与归档](development-requirements.md#2-逐个反编译并按原名归档)。

- **计入 · 调用**：已定位原版方法、导出或调用链，只计入表中明确的入口、操作和数据变化。
- **计入 · 资源／数据／案例**：已定位 BAML、原生资源、数据库记录、安装示例或文档文件，只计入对应的布局、字段、数据或案例。引用实走时保留可回查的原装示例或运行快照。
- **待核实**：现有证据还定位不到原版文件和具体实现，或只找到相关候选文件。原版截图和实走用于核对现象，单凭观察不做文件归属。
- **项目自有**：可直接从现有源码确认是 Qt、项目格式、数据适配或测试实现。原版相应能力若仍有缺口，另列待核实。

表中 `Apr/` 指 `C:/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/`，`Plus/` 指 `C:/Program Files/AspenTech/Aspen Plus V15.0/GUI/Xeq/`。在 `Apr/` 下，`MMForms.<模块>.dll` 展开为 `WPFForms/AspenTech.AspenPlus.MMForms.<模块>.dll`。表中的资源卫星文件一律以 `ui/recovered/index.json` 的实际路径为准。原版文件身份和本地证据位置见[复核记录](#复核记录)。本表计入的是已证实的第 2 步条目。Windows 对照验收和 Mac 实机验收使用各自的记录。

## A. 外壳、导航、文件与状态

| 编号 | 当前源码及功能段 | Aspen 原版文件与定位 | 结论及边界 |
| --- | --- | --- | --- |
| A01 | `UiShell.cpp/.h` 的 `makeMenu`、`makeRibbon`、`makeNavigator`，`UiShellActions.cpp` 的命令路由 | `Apr/ApwnShell.dll` 及 `Apr/WPFForms/en-US/ApwnShell.resources.dll`。`ui/recovered/menus.json` 有资源和命令 ID，`ui/aspen-plus.json` 的手工项可参见[原版菜单观察](ui-research.md)。 | **计入 · 资源**，限静态目录可追溯的菜单、导航和命令绑定。只见过截图的项、手工别名及未接通的命令逐项待核实。 |
| A02 | `UiShellObjects.cpp` 的物性/模拟工作区切换与对象树路由，`UiShellSimulation.cpp` 的模拟导航和主流程图入口 | `Apr/ApwnShell.dll` 的 `CanExecuteNavigateToCommand`、`ExecuteShowFlowsheetCommand`、`TryShowNewFlowsheetScreen`。`Apr/MMForms.Flowsheet.dll` 及其布局来源见 `ui/recovered/Flowsheet.json`。[按钮 NV07](../analysis/button-logic-20261116/report.md) | **计入 · 调用／资源**，限工作区、导航、打开流程图及可定位布局。Qt 树重建、筛选组合和新增路由未逐项核对。 |
| A03 | `UiShell.cpp` 的 `makeFilePanel`、`makeFilePage`，`UiShellProject.cpp` 的新建、打开、保存、另存、关闭确认 | `Apr/AspenTech.Engineering.Controls.FileMenu.dll` 和 `Apr/ApwnShell.dll`。`PlusFileMenu.CreateNewMenuItemControl`、`ApwnApplication.ExecuteFileOpenCommand`、`ApwnDocument.ExecuteSaveCommand`、`ExecuteSaveAsCommand`、`ApwnShellWindow.OnCloseDocument`。新建还可定位原装 `Aspen Plus V15.0/GUI/Templates/BlankSimulation.apt`。本地 `.local/full-ui-logic-20261116/shell-file/report.md` FIL01、07–11。 | **计入 · 调用／资源**，限入口与保存前的确认、提交编辑。模板预览、MRU、网络盘、恢复和原生格式仍需各自验证。 |
| A04 | `ProjectDocument.cpp/.h` 的 `emptyState`、`validate`、`save`、`load`，`UiShellProject.cpp` 的 `captureProject`、`restoreProject`，`ObjectWorkspace.cpp` 的对象快照 | `Apr/ApwnShell.dll` 可追至 `ApwnDocument.NewDocument/OpenDocument` 等原版文档动作。本地文件报告将原生序列化列为未闭合，`Apr/mmg.dll` 的动作名称只提供调查入口。[项目保存实现](project-persistence.md) | **项目自有**，`.afmp` JSON、结构校验、`QSaveFile` 原子替换、项目数据快照。**待核实**原版 `.bkp/.apw` 序列化、图形数据、读写兼容和失败恢复。 |
| A05 | `UiShellProject.cpp` 的 `initializeProject`、`updateUndoActions`、文本撤销及历史菜单 | `Apr/ApwnShell.dll` 的 `GetUndoRedoObservableList`、`OnFlowsheetControlUndoRedoExecuteEvent` 对接 `Plus/pfsctrl.ocx`。同一 Shell 内 `OnModelLibraryUndoRedoEvent` 消费模型库历史事件。原版有单步、多步与文本焦点豁免。[按钮 UD01–03](../analysis/button-logic-20261116/report.md)、[第三轮](../analysis/button-logic-20261116/report-round3.md) | **计入 · 调用**，限可见历史、操作派发及文本编辑优先。模型库事件发布方待核实。Qt 历史描述、撤销域和事务粒度按本项目实现。 |
| A06 | `ProjectDocument.cpp` 的 `edit/undo/redo/undoHistory/redoHistory` 及历史版本 | 原版流程图历史落在 `Plus/pfsctrl.ocx`，现有证据定位到了历史 API，历史条目内部格式仍未解析。 | **项目自有**，全项目快照、100 步上限和历史修订保护。**待核实**原版各对象/属性事务何时入栈、能否跨页撤销及其失败语义。 |
| A07 | `WidgetState.cpp/.h` 的 `commit`，`UiShellProject.cpp` 的 `commitPendingInputs`，`ObjectWorkspace.cpp` 的 `commitProcessEditors` | `Apr/ApwnShell.dll` 发布 `StoreValueEvent`，`Apr/AspenTech.AspenPlus.MMControls.dll` 的 `MMTabPage` 等订阅者提交待决编辑。原版文件保存及 Next 路径均有调用证据。[StoreValue 链](../analysis/button-logic-20261116/report-round3.md)、[下一步静态复核](next-guided-workflow.md) | **计入 · 调用**，限提交待决编辑的时序。Qt 清焦点、信号和恢复时的保护按本项目实现。 |
| A08 | `WidgetState.cpp` 的 `capture/restore/observe`，`RecoveredWorkspace.cpp` 的 `saveState/restoreState/sessionState`，`ComponentWorkspace.cpp` 的会话保存 | 原版 `MMControls` 有变量绑定，现有材料未定位到与 Qt 控件快照对应的原版持久化行为。 | **项目自有**，未验证输入的保存与还原。**待核实**这些控件各自对应的业务变量、单位及默认取值。 |
| A09 | `UiShellActions.cpp` 的 `remember`、窗口后退/前进、快速工具栏定制、功能区折叠、选项及帮助 | `Apr/ApwnShell.dll!ApwnShellWindow.ExecuteShowOptionsCommand` 打开 `OptionsDialog`，命令以 `HasActiveDocument` 为门。`QuickAccessToolbar_ItemsCollectionChanged` 处理工具栏项新增。可回查本地 `.local/other-button-logic/decompiled/ApwnShell.ApwnShellWindow.cs`。 | **计入 · 调用**，限原版选项入口与工具栏项新增处理。窗口历史、工具栏保存与位置、功能区折叠、帮助和各设置写入待核实。 |
| A10 | `UiShellActions.cpp` 的控制面板、消息、运行、报告及未接通动作入口 | `ui/recovered/native-menus.json` 有 `Apr/Simdll.dll` 控制面板菜单资源 13832；`Apr/ApwnShell.dll` 有 `ExecuteRunCommand`、`ExecuteStepCommand`、`MakeCanReport` 等，`Apr/AspenTech.AspenCxs.dll` 有 `CxsCase.GetActionStatus`。[运行与报告 RC、RP](../analysis/button-logic-20261116/report.md) | **计入 · 资源／调用**，限已定位的原版菜单、运行门控和报告入口。现有 Qt 提示和预览不形成可运行的求解或报告链。原生状态全集、结果和分析执行仍待核实。 |
| A11 | `main.cpp`、`LightTheme.h`、`CocoaAccessibilityCheck.mm/.h`、`ui/shell.qss` 的 Qt 启动、样式、自检和可访问性 | 原版安装入口已识别为 `Plus/AspenPlus.exe`，原版启动参数的托管入口见 `Apr/ApwnShell.dll!ApwnApplication.ProcessCommandLine`。本地文件报告 FIL28。 | **计入 · 调用**，限原版入口与托管参数处理。**项目自有**，QApplication、Cocoa、离屏自检、QSS。两处原版入口之间的完整启动链待核实。 |

## B. 界面资源、组分与物性

| 编号 | 当前源码及功能段 | Aspen 原版文件与定位 | 结论及边界 |
| --- | --- | --- | --- |
| B01 | `RecoveredWorkspace.cpp/.h` 的 `pageSpec`、`showPage`、`renderPage/renderNodes` | `ui/recovered/index.json` 每页 `source.file/resource/sha256`，逐节点记录在 59 个模块 JSON。比如 `Setup` 对应 `AspenTech.AspenPlus.MMForms.Setup.resources.dll`，`PhysicalProperties` 对应同名模块资源卫星；完整安装相对路径见 `sources.json`。[静态资源记录](ui-resource-recovery.md) | **计入 · 资源**，逐页可追溯的 3,086 份布局。Qt 渲染、额外标签、静态占位为项目实现；变量绑定、启用门控和 11 个缺失 ContentType 待核实。 |
| B02 | `RecoveredWorkspace.cpp` 的 `renderDialog/renderMenu`，`UiShell.cpp` 的全部资源浏览 | `ui/recovered/native-dialogs.json`、`native-menus.json`、`menus.json` 逐项有 `file/resource/language/sha256` 或相应来源对象。比如 `Apr/Simdll.dll` 菜单 13832。 | **计入 · 资源**，限可定位的 289 个原生对话框模板、69 个原生菜单模板与目录中的 WPF 菜单。资源浏览器及回退预览为项目实现。 |
| B03 | `IconCatalog.cpp/.h` 的 `aspenIcon` 和恢复页面图片 | `Apr/AspenTech.Visualisation.CommonImages.Wpf.dll` 的 `.g.resources`，如 `images/save_16.png`。`ui/icons/manifest.json` 区分内嵌 PNG 与截图裁片；`ui/icons/recovered.json` 给出恢复图来源及资源键。[图片来源](ui-assets.md) | **计入 · 资源**，限有程序集及资源键的位图。截图裁片的原始内嵌资源和动态绘图待核实。 |
| B04 | `ComponentWorkspace.cpp/.h` 的组分页、页签、表格、下拉、默认布局 | `Apr/MMForms.Components.dll` 及 `ui/recovered/Components.json`，分子绘图另有 `Apr/AspenTech.AspenPlus.MolecularDrawing.dll`。`ui/components.json` 是截图核对页的项目配置。[组分页采集](components-research.md) | **计入 · 资源**，限已能定位的选择、油品、非常规、Henry、UNIFAC、聚合物等布局。石油组分生成、结构编辑、参数校验和未绑定的控件行为待核实。 |
| B05 | `ComponentWorkspace.cpp` 的查找按钮、标题双击、`showFindDialog/eventFilter`，`UiShellProject.cpp` 的 `showDatabaseSearch` | `Apr/MMForms.Components.dll` 的 `Find` 入口，经 `Apr/AspenTech.AspenPlus.MMControls.dll!GxSearchComponents`、`Apr/fimmtop.dll`、`Apr/FindComponent.dll` 到 `Apr/AspenTech.AspenPlus.WpfFindComponent.dll!Driver.ShowSearchComponent`。[向导交互扩展](../analysis/wizard-logic-20261115/report.md)、本地其他按钮报告 F01。 | **计入 · 调用**，限查找入口复用。当前 Qt 窗口路由、PubChem 分支和原版选中行上下文需分别核实。 |
| B06 | `DatabaseDialog.cpp/.h` 的名称匹配、立即查找、范围/分类、沸点单位、结果上限、新搜索及排序 | `Apr/AspenTech.AspenPlus.WpfFindComponent.dll` 的 `ExecuteFindCommand`、`FetchComponent/APED/APEDPG`、`ConvertBPUnits`、`ExecuteNewSearchCommand`、`ListView_ColumnHeaderClicked`。本地其他按钮报告 F02–F06、F09。 | **计入 · 调用**，限原版操作和已解析的单位/排序入口。SQLite 排序优先级、非法数值处理、空查找条件和原版异步线程协议未证明等价。 |
| B07 | `DatabaseDialog.cpp` 的 `addSelection`、双击和关闭，`UiShellProject.cpp` 的加入项目回调 | `Apr/AspenTech.AspenPlus.WpfFindComponent.dll!ExecuteAddCommand/InsertComponent` 经 `Apr/AspenTech.AspenPlus.UnmanagedWrapper.dll!SMinsertcompM` 到 `Apr/smge.dll!SMinsertcomp`；双击复用 Add，关闭读 `AddedSuccessfully`。本地其他按钮报告 F07–F12。 | **计入 · 调用**，限添加立即进入项目、双击、多选和关闭边界。原版重复组分、部分失败及 PubChem 估算还需对照。 |
| B08 | `DatabaseDialog.cpp` 的 `refreshDatabanks/saveDatabankSelection/syncDatabankSelection`，`PropertyDatabase.cpp` 的 `databanks` | `Apr/AspenTech.AspenPlus.WpfFindComponent.dll!DatabanksTabViewModel` 绑定 `Top.appModelV8.Pure Databanks.Input.FILE_SYM_NAM`。`DatabanksTab` 布局 ID `eacfcb10862c29b4`；关联 `Apr/MMForms.Pure_Databanks.dll`。[查找筛选实施](research-report-implementation.md) | **计入 · 调用／资源**，限原版库选择和顺序影响查询。清空恢复默认的通用选择器语义待核实；本项目 `compoundSearch` JSON 与数据集校验为自有。 |
| B09 | `PropertyDatabase.cpp/.h` 的 `search/compoundClasses/parameters/provenance`，`DatabaseDialog.cpp` 的详情、参数和来源查询 | APED 的 `APV150/NISTV150/APESV150/FACTV150.mdf`，入口目录 `C:/ProgramData/AspenTech/APED V15.0/`；原装 `AprSystem V15.0/PropertiesDatabase/Bin/ApedGateway.dll` 与 `ApedDataProvider.dll`。`active_Compounds` 等关系、MW/TB、COMPCLASS、出处记录见[数据库调查](property-database-investigation.md)和[运行库记录](runtime-property-database.md)。 | **计入 · 数据**，限来源及参数身份。SQLite 的归并、多子库选值、详情页渲染、只读打开及 QSettings 按本项目实现。原版功能区的检索参数→复制→清理链有研究线索，当前详情展示未接入该链。 |
| B10 | `UiShellAssistants.cpp` 的 `reorderComponents`，`ComponentWorkspace.cpp` 的表格右键、选中项定位和组分排序回显 | `Apr/MMForms.Components.dll!cmdReorder_CommandExecute`，`Apr/AspenTech.AspenPlus.MMControls.dll!MMScrollAreaMS.OnRoutedReorderRecordCommand`，`Apr/AspenTech.AspenPlus.WpfFindComponent.dll!ReorderComp` 调 `SmgeHelper.SMreorderM`，并在 `Apr/smge.dll` 找到 `SMreorder`。[按钮 UC02–04](../analysis/button-logic-20261116/report.md)、[续轮第 4 节](../analysis/button-logic-20261116/report-continued.md) | **计入 · 调用**，限入口、多选上下移、取消及确认写入。原版逐对重放与项目统一 `componentOrder` 属各自实现，跨类型与重复 ID 的边界待核实。 |
| B11 | `UiShellActions.cpp` 的 `openWizard` 用户定义分支，`ObjectWorkspace.cpp` 的用户组分对象 | `Apr/MMForms.Components.dll!cmdUserDefWizard_CommandExecute` → `MMControls.dll` 包装 → `Apr/fimmtop.dll` → `Apr/FindComponent.dll!gxUserDefWizard` → `Apr/AspenTech.AspenPlus.WpfFindComponent.dll!ShowUserDefinedWizard`。[按钮 UC01 及续轮](../analysis/button-logic-20261116/report-continued.md) | **计入 · 调用**，限打开入口和已解析的分页写入/取消补偿调用。当前只创建项目对象并保留草稿，参数、结构、估算和完整补偿失败路径待核实。 |
| B12 | `UiShellProject.cpp` 的 `installMethodEditor`，`UiShellActions.cpp` 的方法页及助手入口 | `Apr/MMForms.PhysicalProperties.dll` 的方法规定页及 `GBASEOPSET/GOPSETNAME/GMODIFY` 绑定，`Apr/AspenTech.AspenCxs.CxsViewModel.dll!CxvVariableData.RefreshValueOptions`。方法助手进程和通用导航定义加载器位于 `C:/Program Files/Common Files/AspenTech Shared/` 下的 `AspenTech.Visualisation.Assistant.Run.exe`、`AspenTech.Visualisation.Controls.Assistant.W1.dll`。本地 `properties-env/report.md` 及其他按钮报告 M01–M07、A01–A05。 | **计入 · 调用／资源**，限原版方法规定字段和通用助手入口。Qt 仅提供 NRTL/IDEAL 及已提交的电解质方法值。原版候选生成、助手推荐定义、覆盖/修改的完整状态和计算参数门控待核实。 |
| B13 | `PropertyAssistant.cpp/.h` 的 `enterPage/forward/backward/finish`，`UiShellAssistants.cpp` 的 `openPropertyAssistant` | `Apr/MMForms.Components.dll` → `Apr/AspenTech.AspenPlus.MMControls.dll` → `Apr/fimmtop.dll` → `Apr/FindComponent.dll` → `Apr/AspenTech.AspenPlus.WpfFindComponent.dll!ShowElecWizard/ShowSFEAssistantMain`，`Apr/AspenTech.AspenPlus.ModelLibrary.Controls.dll!WizardControl.Finish`。[电解质与 SFE 原版报告](../analysis/wizard-logic-20261115/report.md) | **计入 · 调用**，限 E01–E15、S01–S10 内有证据的入口、分页、确认和取消语义。Qt 页序和错误行按当前支持案例实现。 |
| B14 | `ChemicalSystem.cpp/.h` 的 `electrolyteCandidates/applyElectrolyte`、`PropertyAssistant.cpp` 的候选及写入 | `Apr/AspenTech.AspenPlus.WpfFindComponent.dll!ElectrolyteForm10.OnForward`、`ElectrolyteForm12.OnFinished` → `Apr/AspenTech.AspenPlus.UnmanagedWrapper.dll` → `Apr/smge.dll` 的 Chemistry、Henry、全局方法写入。纯水水合氢离子案例另有实走。[落地记录](wizard-business-logic.md) | **计入 · 调用／案例**，限已核实 WATER 水离解、提前完成/正常提交和已定位全局写入。通用反应候选、H+、冰、Henry、平衡常数待核实。 |
| B15 | `ChemicalSystem.cpp` 的 `sfeComponents/applySfe`，`PropertyAssistant.cpp` 的 `chooseChemistry` | `Apr/AspenTech.AspenPlus.WpfFindComponent.dll!SFEAssistantStep2.OnFinished` → `GenerateComponent/GenerateChemisty/GenerateReaction`，通过 `Apr/AspenTech.AspenPlus.UnmanagedWrapper.dll` 到 `Apr/smge.dll`。[向导 S01–S09](../analysis/wizard-logic-20261115/report.md) | **计入 · 调用**，限两步助手、追加或新建固体与盐式、全局引用写入。旧版单窗助手和原版异常补偿的语义待核实。 |
| B16 | `ChemicalSystemView.cpp/.h` 的 `makeChemicalSystemView`，`ChemicalSystem.cpp` 的引用保护、ID、统一组分身份与 JSON 校验 | `Apr/MMForms.Reactions.dll` 的资源卫星中有 `chemistry/mmchemistry_input.baml`，记录写入对应 B14–B15。 | **计入 · 资源**，限原版 Chemistry 输入布局。**项目自有**，只读表、生成组分 key、跨对象引用保护、事务校验。原版二级反应编辑、ID 合法性和撤销粒度待核实。 |

## C. 流程图、输入、单位和下一步

| 编号 | 当前源码及功能段 | Aspen 原版文件与定位 | 结论及边界 |
| --- | --- | --- | --- |
| C01 | `ObjectWorkspace.cpp/.h` 的对象集合、`createObject/renameObject/removeObject/openObject`、父子关系和表单 | 对象页的 `ui/object-types.json` `page/name` 指向 `ui/recovered/index.json` 的页面与原文件。物性组有 `Apr/MMForms.PhysicalProperties.dll`，反应有 `Apr/MMForms.Reactions.dll`，流股有 `Apr/MMForms.Streams.dll`，Mixer 有 `Apr/MMForms.Blocks.Mix_Split.dll`。[原版对象观察](ui-object-interactions.md) | **计入 · 资源**，限已映射的模块、对象页和 ID 对话框。95 个类型逐项的原生 CRUD、父子级联、编号与命名策略待核实。 |
| C02 | `ModelPalette.cpp` 的 `makeModelPalette`，`ObjectWorkspace.cpp` 的 `beginPlacement/placeAt`，`UiShellSimulation.cpp` 的入口 | `Apr/ApwnShell.dll!ApwnFlowsheetControl.OpenModelLibraryCommand_Execute` → `Plus/Modules/AspenTech.AspenPlus.ModelLibrary.dll` 及 `Plus/pfsctrl.ocx` 的放置接口。`Apr/mmg.dll!GRcreblk/GRcrestm2` 建立块/流股记录。本地流程图报告 PFD01–PFD02。 | **计入 · 调用**，限选项板、放置接口与原版建模入口。每种设备放置限制、OCX 鼠标状态和原生模型提交序列仍待核实。 |
| C03 | `ObjectWorkspace.cpp` 的点击/框选、双击、`showFlowsheetMenu`、删除、复制粘贴与重命名 | `Apr/ApwnShell.dll!pfs_OnSelect/OnCOEditModel`，`Plus/pfsctrl.ocx`，`Apr/AspenTech.AspenPlus.PfsDialogs.dll!PFSContextMenu.OnClickMenuItem`，`Apr/AspenTech.AspenPlus.UnmanagedWrapper.dll!MMPFSHelper.CopyObject`，`Apr/mmg.dll!GRrenblk/GRrenstm/GRdelblk/GRdelstm`。本地流程图报告 PFD03、11–15。 | **计入 · 调用**，限已定位的选择、菜单、模型编辑、复用剪贴板入口。Qt 剪贴板内容、对象复制粒度、锁和删除通知的全路径待核实。 |
| C04 | `ObjectWorkspace.cpp` 的 `moveBlock/moveBlocks`、旋转翻转、缩放、适应窗口、锁定、流股样式与画布刷新 | `Plus/pfsctrl.ocx`、`Apr/Interop.Aosapfs.dll!IAPFSControl` 的位置、图标和视口接口；`Apr/ApwnShell.dll` 的 `ExecutePFSRotateCommand`、`pfs_OnZoomChanged`。本地流程图报告 PFD15–16、22–23；流股属性见[操作链核查](ui-operation-parity.md)。 | **计入 · 调用**，限位置、方向和视口入口。图形样式字段、VData 保存、路线几何、锁的所有写入门控仍待核实。 |
| C05 | `ObjectWorkspace.cpp` 的 `chooseFlash2Port/connectStreamEndpoint/beginReconnection`、删除后的掉线处理 | `Plus/pfsctrl.ocx` → `Apr/AspenTech.AspenPlus.PfsDialogs.dll!PFSUniversalPortDialog` → `Apr/AspenTech.AspenPlus.UnmanagedWrapper.dll!AddConnection/DeleteConnection`，`Apr/mmg.dll!GRconstm/GRdscstm`；原版端口接口在 `Apr/Interop.Aosapfs.dll!IAPort`。本地流程图报告 PFD02、08、13。 | **计入 · 调用**，限原版重连入口、端口选择和连接/断开函数。原版拒绝和替换行为、端口占用真值表和内部路由待核实。 |
| C06 | `ProcessTopology.cpp/.h` 的 `ports/endpointError/issues/validateStructure`，`ObjectWorkspace.cpp` 的 Flash2 点位 | `Aspen Plus V15.0/GUI/Examples/Getting Started/Process/flash.bkp`；[原版案例快照索引](../analysis/next-guidance-20261117/case.json)确证单进料、汽相和液相出口，方向接口见 C05。 | **计入 · 案例／调用**，仅代表参考拓扑和端口接口证据。`FEED/VAPOR/LIQUID`、端口占用/自连限制、旧项目缺失角色处理是当前项目规则，原生端口编码和边界待核实。 |
| C07 | `ModelPalette.cpp` 的 `flowsheetModelIcon/makeMetrics`，`ObjectWorkspace.cpp` 的局部图形状态 | [模拟界面观察](simulation-ui-parity.md)记录了模型符号、经济/公用工程、换热器和 CO₂e 指标区域。逐指标原版文件未与当前占位逐项对应。 | **项目自有**，QPainter 设备近似图标、指标占位与 Qt 几何。原版符号源文件及四组指标依赖待核实。 |
| C08 | `ProcessInput.cpp/.h`、`ProcessInputWidget.cpp/.h` 的物料进料规定、TP/TV/PV、总摩尔流量及组成 | `Apr/MMForms.Streams.dll!MMMaterial_Input_MixedPha_ViewModel.OnSubPropertyDataChanged`，`MIXED_SPEC`、`TOTFLOW/FLOWBASE`、`FLOW/BASIS`；布局 `0c0854b8dd276b69`。本地流股表单报告 FRM01–06，案例见 C06。 | **计入 · 调用／资源／案例**，限物料进料子集与已定位字段，质量基准、子流股、组分属性、PSD 和完整 CC Nodes 待核实。 |
| C09 | `ProcessInput.cpp`、`ProcessInputWidget.cpp` 的 Flash2 双规定、TP/TV/PV/TD/PD、汽相分率与热负荷 | `Apr/MMForms.Blocks.Flash_HX.dll!MMFlash2_Input_Specif_ViewModel.OnSubPropertyDataChanged`，`SPEC_OPT` 与 `CC Nodes.EXIST*`；布局 `5b05ea65d054f920`。本地流股表单报告 FRM11–13。 | **计入 · 调用／资源**，限已定位的五种规定和字段联动。TQ/PQ 使用入口热流，热流端口规则、完整相态联动及其他单元配置待核实。 |
| C10 | `ProcessInput.cpp` 的 `number/issues/validateStructure`，`ProcessInputWidget.cpp` 的输入提交、必填提示 | 原版表单字段和 `CC Nodes` 见 C08–C09，参考案例记录了部分缺项提示。 | **计入 · 案例**，限已实走的必填现象。**项目自有**，数值语法、正值边界、组成求和 `1e-8`、版本与草稿结构。原版阈值、容差及数值异常矩阵待核实。 |
| C11 | `ProcessUnits.cpp/.h`，`UiShellActions.cpp` 的 `setUnits`，`ProcessInputWidget.cpp` 与 `ObjectWorkspace.cpp` 的换算 | `Apr/MMForms.Setup.dll` 的单位集资源布局 `a7fa9aee81e4e62f`，`Apr/AspenTech.AspenCxs.CxsViewModel.dll!CxvVariableData.Units/UnitsOptions`，`Apr/AspenTech.AspenPlus.UnmanagedWrapper.dll!SMgetglobalunitM` → `Apr/smge.dll!SMgetglobalunit`；本地表单报告 FRM22。原版 Flash2 参考案例核到 ENG 字段与运行量纲。 | **计入 · 调用／资源／案例**，限单位展示、单位集入口和已核对案例。C++ 线性系数和事务性换算为项目实现；原版存储量纲、精度与单位候选全集待核实。 |
| C12 | `UiShellGuidance.cpp` 的 `nextProcessInput/updateProcessStatus`，`ProcessGuidance.cpp/.h` 的 `next/issues` | `Apr/AspenTech.AspenPlus.MMControls.dll!MMNextButton.OnClick/MMTabPage.OnNextButtonClicked` → `Apr/ApwnShell.dll!NextInputFn`，含 `StoreValueEvent`、`ApwnFormContentHost.NextHit`、跨组导航令牌。原版案例 C06 覆盖缺项定位及最后运行。[静态与实走记录](next-guided-workflow.md) | **计入 · 调用／案例**，限入口合流、先交编辑、字段定位及原版案例观察。Qt 的对象优先级、NRTL/IDEAL 和一进两出限制只服务当前案例。原生 `Next Incomplete` 的全分支和项目的自动运行仍待核实。 |

## D. 研究工具、测试与构建

| 编号 | 当前源码及功能段 | Aspen 原版文件与定位 | 结论及边界 |
| --- | --- | --- | --- |
| D01 | `tools/scan_aspen_ui.py`、`build_ui_catalog.py`、`recover_ui_images.py`、`verify_ui_catalog.py`、`compare_ui_shell.py`、`audit_ui_operations.py` | 源身份见 `ui/recovered/scan-files.json`、`sources.json`、原生模板索引及 `ui/icons/recovered.json`。`tools/baml_known.json` 属 Microsoft WPF 格式辅助数据。[恢复与复核](ui-resource-recovery.md) | **计入 · 资源**，限已定位的 Aspen PE/资源片段。工具本身为研究代码。 |
| D02 | `tools/inspect_aspen_properties.py`、`AspenDatabaseExporter.cs`、`Export-AspenDatabase.ps1`、`Export-AspenPropertySample.ps1`、`audit_aspen_vectors.py` | B09 的 APED 数据文件和原版 provider，已核对的 API 入口 `AspenTech.APED.SqlServerDatabase`、`PropertyValueManager.GetUnaryPropertyValue`，来源清单保存在本地导出包。[明文导出](plaintext-database-export.md) | **计入 · 数据／调用**，限公开读取接口和可追溯数据。原数据库的存储表示→API 数组差异仍待按参数解释。 |
| D03 | `tools/export_aspen_catalogs.py`、`export_aspen_support.py`、`export_aspen_tde.py`、`import_aspen_plaintext.py`、`verify_aspen_plaintext.py`、`build_runtime_database.py` | 原版 `TDE9i.sqlite`、`TIIS.sqlite`、`TDE9m.sqlite`、`TDE9r.sqlite` 及原装 `TDE.dll`。逐文件实际路径与哈希见本地 `plaintext-export/support/inventory.json` 和子库清单；APED 主输入见 B09。 | **计入 · 数据**，限格式已验证的导出、恢复和查询数据。旧二进制的十六进制保存只登记来源，内部语义待核实。SQLite 索引构建为项目自有。 |
| D04 | `tools/extract_aspen_formulas.py`、`mathjax_svg_decode.py` | 原装 `HtmlHelp` 的主题 HTML、MathJax SVG 与 Safety_Datasheets PNG；`Engine/Dat/fluids/*.{FLD,PPF,BNC}`。逐个主题、图片与流体文件见本地公式 `index.json`、`engine-fluids/manifest.json`。[公式提取说明](formula-extraction.md) | **计入 · 资源／数据**，限文档公式及明文系数来源。编译引擎公式、参数映射与实际求解待核实。 |
| D05 | `analysis/wizard-logic-20261115/`、`analysis/button-logic-20261116/`、`analysis/next-guidance-20261117/` 的提取、验证脚本与案例 | 向导和按钮的 `evidence-index*.json` 带原版路径、哈希、方法 token/RVA 或导出位置。案例 `case.json` 带原装 `flash.bkp` 来源和本地运行快照入口。 | **计入 · 调用／案例**，已核实条目通过 A、B、C 引用。研究工具自身为项目代码。 |
| D06 | `CMakeLists.txt`、`.github/workflows/ui-build.yml`、`tools/package_macos.sh`、`tests/` | Qt 构建、平台打包、合成测试数据和回归断言由本项目维护；`Flash2Fixture.h` 使用 C06 参考案例，资源和数据库测试分别回查 B01–B03、B09。 | **项目自有**。现有测试用例可用于第 3 步复跑，测试通过的证据与本表的原版文件归属分别记录。 |

## 待核实清单

| 功能 | 已知调查入口 | 缺少的证据 |
| --- | --- | --- |
| 原版文件兼容和恢复 | A03–A04 的 `ApwnDocument` 与 `mmg.dll` | `.bkp/.apw` 的读写字段、工程图形数据格式、保存事务、失败与恢复。 |
| 全模型端口和流程图操作 | C01–C07 的 `pfsctrl.ocx`、`mmg.dll`、`Interop.Aosapfs.dll` | 原版模型端口身份、占用/多连规则、错误回退、热/功连接、嵌套流程和剪贴板状态。 |
| 表单完整业务 | B01、B04、B12、C08–C11 的 `MMForms.*` 和 `MMControls.dll` | 11 个缺失 ContentType、动态表单条件、原版单位/字段范围、方法候选和参数写回。 |
| 化学、数据库和查找例外 | B06–B16 的 `WpfFindComponent.dll`、`smge.dll`、APED 接口 | 反应库、Henry、查找冲突和部分失败、参数复制/清理、单位和真实值来源。 |
| 完整 Next、计算及结果 | A10、C12 的 `ApwnShell.dll`、`AspenTech.AspenCxs.dll`、`Simdll.dll` | 原生 `Next Incomplete` 和状态真值表、引擎入口到物性与单元操作求解的调用链、参数/公式映射和数值对照。 |
| 安装介质与逐文件归档 | 本地 `.local/full-ui-logic-20261116/installer-inventory/report.md`，介质 `aspenonesuite/Process Modeling (Aspen Plus) V15 (64bit)/Process Modeling (Aspen Plus) V15 (64bit).msi` | 当前 MSI 已确认存在并记录 SHA-256。CAB 解包后的逐文件、版本及哈希配对仍待验证，所以本表以本机安装文件为归属基准。全套程序集逐文件完整反编译也仍在第 2 步待办。 |

## 复核记录

- 原版安装路径、SHA-256 和证据出处按原名登记在本地 `.local/source-attribution-20261118/original-files.json`。112 个原版路径与既有哈希一致，其中包括静态目录的 59 个布局来源。另现场登记 `AspenPlus.exe`、两个空白模板和产品 MSI 的哈希。数据库和公式使用原有清单，本轮不对运行中的 MDF 做快照。原有反编译、IL、原生证据和数据包继续在各自的本地路径保留。
- 本轮复核通过向导静态 37 项、其他按钮静态 77 项、按钮三轮索引，以及 Flash2 快照、源身份与 Next 调用链 9 项。资源检查通过 3,086 份布局、59 个模块、289 个原生对话框、117 份菜单。Flash2 检查使用保存的原版运行快照。
- 主要本地定位入口为 `.local/full-ui-logic-20261116/{shell-file,flowsheet,stream-block-forms,properties-env}/report.md` 和 `.local/other-button-logic/report.md`。前四份按报告中的 FIL、PFD、FRM 与物性字段回查各目录的托管/原生证据。后一份按 F、M、A 编号及同目录证据索引回查。快照入口和原版调用研究在[下一步研究](next-guided-workflow.md)、[向导报告](../analysis/wizard-logic-20261115/report.md)、[按钮报告](../analysis/button-logic-20261116/report.md)与[三轮补充](../analysis/button-logic-20261116/report-round3.md)。

## 原名归档与报告命名

本地入口为 `.local/step-2-naming-20261118/V15-final/README.md`。`sources/` 和 `reports/` 下镜像保存安装产品、相对目录和完整文件名（含原扩展名）。例如，`AprSystem V15.0/GUI/Xeq/ApwnShell.dll` 对应 `ApwnShell.dll.sources.json` 和 `ApwnShell.dll.md`。已确认来源的 C#、IL 和原生分析材料分别追加 `.01.cs`、`.il-01.json`、`.native-01.json` 等后缀。记录内保留原版路径、可取得的文件版本、SHA-256、原始证据出处和对照表编号。同一相对路径有不同哈希的版本时，为每个版本使用含版本号和哈希的独立归档目录。

本轮建立 **1,298 对**原名源码记录和报告，归入 **251 份**可追溯的局部分析材料（139 份 C# 阅读版、77 份 IL、35 份原生分析）。C# 归属通过 IL 或原版托管类型定义核对。资源条目保留原资源键，数据库、公式和流体数据指向已有本地资料。20 个仅登记身份的条目标为源码归档待核实。未能归属的材料记录在 `index.json` 的 `unassignedEvidence`。原名归档和原版证据均保存在本地。

`project-reports/src/` 按当前项目文件的完整文件名保存 **45 份**同名报告，例如 `UiShell.cpp.md`。现在的 Qt 构建从 `src/` 读取源码。一个 Qt 文件涉及多个原版文件时，可通过 `project-index.json` 和对照表编号查阅各自的原版报告。

## 20 个原版条目与 7 份 C# 阅读版复核

最新本地归档入口为 `.local/step-2-naming-20261118/V15-check/README.md`。同目录 `followup.md` 逐项列出本轮 20 个原版文件的已证实范围和待核实项。各文件按原相对路径补入 `<原名>.verification.json` 及可取得的 C#、原始 BAML 或 APT，原版文件 SHA-256 均与上一版登记一致。

- 托管程序集通过 TypeDef、方法与 ILSpy 阅读版定位。例如 `ApedGateway.dll` 定义 `IPropertyValueManager` 接口，`ApedDataProvider.dll` 持有 `SqlServerDatabase` 和 `GetUnaryPropertyValue` 的实现。另核实了 Chemistry 编辑入口、流程图覆盖层、模型选项板和启动入口。
- 原生文件核到导入、导出或注册证据。`ADMethods.dll` 对应 Aspen Dynamics 与 EDR 接口，更正旧报告的“油品化验方法”标注。`AOSA.dll` 有本机 64 位 COM 注册记录，`mmhost.dll` 已确认回调接口，实际加载者与运行调用链仍待核实。
- Windows Installer 只读查询核实产品 MSI 版本 `41.0.0`，`File` 表命中本批其余 19 个文件名，共 23 条记录。两个 `ApwnShell.resources.dll` 安装副本的 SHA-256 不同，分别按相对路径保存。MSI 中同名文件与安装文件的逐字节匹配仍需解包比对。
- 7 份旧 C# 阅读版中，6 份重新提取后正文匹配，归入 `AspenTech.Visualisation.Assistant.Run.exe`、`Interop.Aosapfs.dll` 和新增归档的 `AspenTech.AspenPlus.MMHNodeTree.dll`。旧 `MMResults_PureSca_Converter.cs` 只有 ILSpy 更新提示，索引继续保留该异常。实际转换器已通过 `NestedClass` 定位到 `AspenTech.AspenPlus.MMForms.PhysicalProperties.dll` 中的父 ViewModel，并单独归档重新提取的正文。

## 当前源码归档

归档入口为本机的 `.local/source-classification-20261118/README.md`。`index.json` 记录原版绝对路径、版本、SHA-256、归档文件指纹和选取范围。完整反编译资料仅在本机保存。

以下为既有归档快照。后续每轮反编译或编译均按[第 1.1 项：每轮成果分类与逐文件说明](development-requirements.md#11-每轮成果分类与逐文件说明)执行：已完成与未完成两类中的每个成果文件，都须在同目录配套独立的同名 `.md` 说明，目录级 `README.md` 仅作汇总。新增归档使用新路径，保留既有快照与说明。

| 本地目录 | 数量 | 命名和说明 |
| --- | --- | --- |
| `01-completed/` | 4 个原版文件，4 份 C# | 保留原相对路径，使用 `<原文件全名>.cs`。目录中的 `README.md` 列出完成依据与验证范围。 |
| `02-incomplete/` | 35 个原版文件，161 份 C# | 使用 `<原文件全名>.<序号>.cs` 保存局部导出，带未解决提示的整份导出保留 `<原文件全名>.cs`。每份 C# 的同名 `.md` 存在同一目录，记录该份输出的范围、缺口与证据。例如 `A.dll.01.cs` 对应 `A.dll.01.md`。 |

第一类的四份整程序集 C# 均由原版重新导出复核。`AspenTech.AspenPlus.WpfFindComponent.dll` 的整份导出仍有两处类型未能推断，归第二类。重新编译、资源与行为对照按后续步骤验收。

上述 45 个第三类 Qt 工程文件已从当前整理分支移除，之前分类目录中的 45 个工程副本和 19 段 Qt 摘录一并移除。功能对照表仍可用来定位原版文件和调用链。数据库保护范围见[数据库永久保留原则](database-preservation.md)。
