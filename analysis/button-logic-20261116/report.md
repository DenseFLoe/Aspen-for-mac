# 按钮关系图谱与未确认清单

后续实现：参考案例的字段/单位/“下一步”与端口规则见[Flash2 输入与引导](../../docs/flash2-input-guidance.md)、[连接规则](../../docs/flash2-topology.md)；组分排序、通用编辑提交及撤销历史的落实见[研究报告落实核对](../../docs/research-report-implementation.md)。本文描述的研究时移植缺口不代表这些后续实现尚未完成，求解相关边界仍保留。

日期：2026-11-16（北京时间）。分支 `codex/button-logic-exploration`，基于 `codex/wizard-business-logic@a6074aa`。本轮在 [wizard-logic-20261115](../wizard-logic-20261115/report.md) 与 `.local/other-button-logic/report.md` 已确认链条之上，把覆盖扩大到**运行控制、导航、撤销/重做、报告、组分页其余入口（用户定义／重新排序／亨利）**，并以全量清单差集标出尚未确认的按钮。本轮仅分析与证据整理：新增大体积证据在 `.local/button-logic-exploration-20261116/`，报告与索引发布于本目录；未编辑项目源码，未进行动态点击。

最值得注意的结论：

1. **求解器按钮群共用两层门**：局部 CanExecute 之外，Run/Step/Stop/Reinit 等统一委托 `CxsSolver.*ActionStatus.CanInvoke`，而 `CanInvoke = (Status != 2)`；无运行案例时 `CxsCase.GetActionStatus` 直接返回 Status=2，即整群禁用。按钮之间的启用关系不是各自独立，而是共享同一状态机制。
2. **`RefreshRunCommands` 是运行簇的共享刷新枢纽**，且按 `MmgSor.SolverThreadIsActive` 把按钮分成两组：求解线程活跃时第二组（MoveTo/StopPoint/EnergyAnalyzer/FlareSystem/EDRHeatExchanger）不刷新。
3. **Run/Step/Reinit 都被“分析对话框打开”阻挡并提示，Stop 不被阻挡**；Reinit 还会清空 RadFrac 柱分析结果、把报告门重置为不可报告。
4. **Next 按钮＝功能区 Next Input＝脚本路径**，三者共用 `NextInputFn`：先提交当前表单（StoreValueEvent），再表单内 NextHit，再 “Next Incomplete” 导航；返回值可以是 `RUN`（触发控制面板＋Run）、`GOTOSIM`（切换模式）、`CANCEL`、流程图路径或普通节点路径，跨组导航需 OK/Cancel 确认。**Next 与 Run 之间存在直接触发边**。
5. **撤销/重做不是全局项目事务**：启用取决于当前屏幕的 undo/redo 列表计数，执行按 `UndoRedoScreenType` 分派到 Flowsheet Control 或 ModelLibraryIconEditor 事件，其他屏幕类型在此不处理。
6. **重新排序入口有双重门**（组分数≥2；所有行必须有 CID），对话框内移动只改内存并记历史，**确定时按历史逐对 `SMreorderM` 写项目，取消零写入**。
7. **主功能区按钮是代码生成的**，静态 BAML 不含 Run/Stop/Undo 等工具：静态目录低估 shell 按钮，IL 命令图才是权威来源（139 个代码命令，本轮累计追踪 21 个）。

## 证据口径

沿用前两轮：**IL**＝安装程序集方法体调用/分支；**N**＝原生导出与指令；**L**＝已恢复 BAML 布局；**D**＝ILSpy 反编译阅读辅助（不是原始源码，关键结论均有 IL  backing）；**O**＝原版可访问性观察。**本轮 O 为空**：没有成功的动态点击或界面读取，所有动态表现列入待验。

完整 SHA-256、MethodDef token、RVA 见 [evidence-index.json](evidence-index.json)；18 项地址/调用一致性检查见 [checks.json](checks.json)，全部通过。地址只适用于索引所列哈希的安装文件。

| 简称 | 安装文件（未注明时位于 `C:/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/`） |
| --- | --- |
| S | `ApwnShell.dll` |
| X | `AspenTech.AspenCxs.dll`（CxsSolver/CxsCase 定义处；V 中只有 TypeRef） |
| V | `AspenTech.AspenCxs.CxsViewModel.dll` |
| C | `WPFForms/AspenTech.AspenPlus.MMForms.Components.dll` |
| M | `AspenTech.AspenPlus.MMControls.dll` |
| F | `AspenTech.AspenPlus.WpfFindComponent.dll`（查找窗口与 ReorderComp 同程序集） |
| B / D | `FindComponent.dll` / `fimmtop.dll` |
| G / N | `mmg.dll` / `smge.dll`（本轮仅字符串归属扫描） |
| I | `AspenTech.AspenPlus.Infrastructure.dll`（ProblemModes 枚举） |

模式枚举交叉确认：`MakeCanReport` 的 IL 分支（1→CanReport，0→CanReportInPropertiesMode）与 D 中 `ProblemModes.Simulation/Properties` 用法一致；`NextInput_Executed` 的 IL `ldc.i4.4` 对应 D 中 `ProblemModes.PSVPlus`。故 **0=Properties、1=Simulation、4=PSVPlus**（2/3 按枚举顺序推断为 Dynamics/EnergyAnalysis，未单独交叉验证）。

## 1. 运行控制簇（RC）

| ID | 条件与校验 | 执行与数据变化 | 后续 / 证据 |
| --- | --- | --- | --- |
| RC01 Run 启用 | 文档非空；ActiveMode≠4（PSVPlus）；非 AI 训练；非 AspenProperties 且 `GetRunAnyWayValue()==1` 且 `IsInputNotComplete()==1` 时直接 true（run-anyway 覆盖）；否则 `Case.Solver.CanRun` | 只读门 | S.CanExecuteRunCommand，IL |
| RC02 Step 启用 | 文档；模式≠4；Case 非空；`IsNormalRun`→`Solver.CanStep`；`IsSimInEOMode`→false；否则 `!bRunComplete` | 只读门 | S.CanExecuteStepCommand，IL |
| RC03 Stop 启用 | 文档；`!IsSimNotRunning`→true（运行中即可停）；否则 `Solver.CanStop` | 与 Run 互补 | S.CanExecuteStopCommand，IL |
| RC04 Reinit/TimePlot/MoveTo 启用 | 三者**同一方法体**（RVA 0x470c）：Case 非空且 `Solver.CanInitialize` | 共享门 | S，IL＋checks |
| RC05 Rewind/TakeSnapshot/ManageSnapshots 启用 | 三者**同一方法体**（RVA 0x4797）：`IsCurrentFlowsheetBatch` | 仅批处理流程图可用 | S，IL＋checks |
| RC06 StopPoint 启用 | Case 非空 | 只读门 | S，IL |
| RC07 刷新枢纽 | `RefreshRunCommands` 先Raise Run/Step/Reinit/Stop；`SolverThreadIsActive`→返回，不刷新第二组 | 否则刷新 MoveTo/StopPoint/EnergyAnalyzer/FlareSystem/EDRHeatExchanger；发 UpdateShowDashboardCommand 事件；`UpdateDynamicsButtons`；运行中 `GlobalScriptEnable=false`，否则按 `EoGlobalScriptsPopListHelp.IsEnabled/BuildList`；`IsSimOverForEo`（EO 模式按 `CanEoVariableIO`）；`RefreshNavigatorViewFilter` | 一个枢纽决定整簇可见启用状态 | S.RefreshRunCommands，IL |
| RC08 Run 执行 | 分析面板（AnalysisScreenFactory）打开→`CloseAnaDlgBeforeRun` 提示并**返回** | AspenProperties→内部；否则 `EnergyAnalysisAgent.IsAutoRun`→`StartRunningSimulation`＋Dispatcher 延迟内部；内部：EO 且 Scope≠plant 警告（No→返回）；发 PrepareForCheckpoint、BeforeRunSimulation 事件；`Case.InvokeAction("Top.Solver","Run")`；SyncContext.Post 续体；`MakeCanReport(true)` | 运行事件链与报告门 | S.ExecuteRunCommand/Internal，IL＋D |
| RC09 Step 执行 | 同 RC08 的分析面板阻挡 | 发 PrepareForCheckpoint（**不发 BeforeRunSimulation**）；`Solver.InvokeAction("Step")`；Refresh；`MakeCanReport(true)` | S，IL＋D |
| RC10 Stop 执行 | **无**分析面板阻挡 | `HappFuncs.HappRunM(10)`；`IApwnSimulationViewModel.OnStopPending`；Refresh；不改报告门 | S，IL＋D |
| RC11 Reinit 执行 | 发 BeforeRunSimulation；分析面板阻挡（CloseAnaDlgBeforeInit） | EO＋模式1→EOReinitDlg（DriveDialog 事件）；AspenProperties→`Reinit.GetPrompt` 确认（No→返回）→`InvokeAction("Top.Solver","Initialize")`；否则 `DialogDriver.ShowSimReinitDlg` 确认；成功后 Refresh＋`MakeCanReport(false)`＋`UpdateStreamsStyleAfterRunEvent`；`radfracBlkList` 非空→`RemoveALLCAResults` | 重新初始化会清柱分析结果、重置报告门 | S，IL＋D |
| RC12 状态机制 | `CanRun/CanStep/CanStop/CanInitialize`＝各自 `*ActionStatus.CanInvoke`；`CanInvoke=(Status!=2)` | `CxsCase.GetActionStatus`：无 `_RunningCase`→new StatusDetails(**2**)；否则 `BatchGet` 读案例数据→`ValueToActionStatusDetails`；`InvokeAction` 无运行案例抛 `CxsCaseNotRunningException` | 状态数值来自原生案例数据，**status_code 全真值表未确认** | X，IL＋checks |
| RC13 与报告簇的边 | Run/Step→MakeCanReport(true)；Reinit→false | 见 RP | S，IL |

**边界**：`GetRunAnyWayValue/IsInputNotComplete`、`HappRunM(10)` 与另一处 `HappRunM(8)`（Rewind 链）的原生语义未解析；EO 重初始化对话框与 `ShowSimReinitDlg` 的选项内部未展开；`radfracBlkList` 的填充时机未追；分析面板阻挡只确认了“打开即挡”，关闭后的恢复路径未追。

## 2. 导航簇（NV）

| ID | 条件与校验 | 执行与数据变化 | 后续 / 证据 |
| --- | --- | --- | --- |
| NV01 入口共体 | `MMNextButton.OnClick` 先 Raise NextEvent 再走基类命令；`MMTabPage.MMNextButton_Next` 与 `DoNextButtonFromScript` **同一 RVA**→`OnNextButtonClicked`→发 NextButtonClickedEvent | 点击与脚本同路径 | M，IL＋checks |
| NV02 shell 订阅 | `!args.Handled` 才处理；保存 `bRunAfterInputIsComplete`，`args.Source!=null` 时置 true，调用后恢复 | 调 `NextInputFn` | S.OnNextButtonClickedEvent，IL |
| NV03 功能区 Next Input | `NextInput_Executed`：PSVPlus 模式跳过；否则同 `NextInputFn` | 与 NV01 共执行器 | S，IL＋D |
| NV04 提交与表单内 Next | ControlPanelView 且 `HAQueryRunStatusM()==16842768`→跳过；否则**发 StoreValueEvent（提交当前表单）**；`ApwnFormContentHost.NextHit(true)` 命中表单内下一个必填→返回 | 导航前先写当前表单 | S.NextInputFn，IL＋D |
| NV05 流程图分支 | 流程图导航组＋流程图屏幕→Custom Actions “Next Incomplete”(“Top.appModelV8.Flowsheet”)；结果以 `\Flowsheet\` 开头→`ExecuteFlowsheetCommand3`；状态 10240/74752→提示，否则 `MMHappDialog("Flowsheet Incomplete")` | 原生 “Next Incomplete” 实现未解析 | S，D |
| NV06 树遍历与令牌 | 选中节点→DefaultFormRelativePath→上溯容器；逐路径 “Next Incomplete”，COMException 上溯父路径；兜底 “Top.appModelV8”。令牌：`\Flowsheet\Section\GLOBAL`→流程图提示；`CANCEL`→停；`GOTOSIM`→估算/回归切分析模式，否则切 Simulation；**`RUN`→CanRun 时 disableITOnly=true，`ExecuteShowControlPanelCommand`＋`OnRunRun`**；普通路径→跨组时 SimIncomplete OK/Cancel→`NavigateTo` | **Next→Run 触发边**；跨组需确认 | S.NextInputFn，D（IL 提取 backing 关键调用） |
| NV07 导航/流程图门 | `CanExecuteNavigateToCommand`＝HasActiveDocument（与 RP02 属性报告门**同 RVA**）；流程图显示门＝模式∈{1,4}，ShowFlowsheet 与 ShowDemoFlowsheet 共用；Execute→OnShowHierarchyScreen＋TryShowNewFlowsheetScreen；NewFlowsheet→OnShowNewHierarchyScreen | 共享门 | S，IL＋checks |

**边界**：`NextHit` 表单内算法、“Next Incomplete” 原生实现、`bRunAfterInputIsComplete` 与 `disableITOnly` 的消费方、StoreValueEvent 的订阅者集合均未展开；16842768/10240/74752 等状态常量含义未解码。

## 3. 撤销/重做簇（UD）

| ID | 条件与校验 | 执行 | 证据 |
| --- | --- | --- | --- |
| UD01 启用 | `m_olListBoxUndoItems.Count>0` / `m_olListBoxRedoItems.Count>0` | 每屏幕列表驱动，非全局事务 | S，IL |
| UD02 分派 | `UndoRedoScreenType=="Flowsheet Control"`→FlowsheetControlUndoRedoExecuteEventArgs；`=="ModelLibraryIconEditor"`→ModelLibraryUndoRedoExecuteEventArgs；其他类型不处理 | 事件参数含 ActiveDocumentScreen | S，IL＋D |
| UD03 类型来源 | 屏幕事件写入 UndoRedoScreenType（D 17079/17085） | 哪些操作向列表 push 项**未追** | S，D |

## 4. 组分页其余入口（UC）

| ID | 条件与校验 | 执行与数据变化 | 后续 / 证据 |
| --- | --- | --- | --- |
| UC01 用户定义 | `cmdUserDefWizard_CommandExecute`→`GxUserDefWizard(FirstRowIndex)`→InvokeAction(“Top.appModelV8.Custom Actions”,“gxUserDefWizard”,1,[row]) | D 分派字符串 @0x144fd0（与 gxSearchComponents @0x144fa0 相邻）→B.gxUserDefWizard@0x42d0→COM 桥 sub_21d0→`ShowUserDefinedWizard` | 与查找同构的 COM 桥；向导本体未确认 | C/M/B/D，IL＋N＋checks |
| UC02 重新排序入口 | 网格 count<2→Message1 提示返回；任一行 `txtCompID_cid` 空→Message2 返回 | 否则取首个选中行 CID，发 OpenReorderComponentsDialogEventArgs；UpdateDisplay | **无 CID 的行（如未命名用户定义组分）阻挡排序** | C.cmdReorder_CommandExecute，IL |
| UC03 排序对话框 | shell 订阅→`new ReorderComp()`（F）＋Owner＋InitialSelectedComponent＋ShowDialog 模态 | MoveUp/Down 只改内存 Components 并记 MovingHistory；CanExecute 用索引和边界（支持多选、有序处理防碰撞） | 移动不写项目 | S 订阅＋F.ReorderComp，IL |
| UC04 确定/取消 | OK/Cancel CanExecute 恒 true（同 RVA） | OK：`SequenceEqual(OriginalComponents)`→只 Close；否则**按 MovingHistory 逐对 `SmgeHelper.SMreorderM`** 后 Close；Cancel：只 Close | 提交＝历史重放，非单次批量；SMreorderM 原生记录语义未解析 | F，IL＋checks |
| UC05 亨利页 | 选择页亨利按钮在静态布局**无命令名**（绑定未确认） | 页＝tab 条（HenryC/Info/RewHen）；两 ListPicker 绑 `@main.Input.CID`（AllowSort=false）；RewHen.cmdClose→CloseForm | 列表选择事务语义未确认 | C，IL＋L |
| UC06 遗留原生路径 | B.gxReorderComp@0x3bf0，COM 名 “ReorderComp” | 与 WPF ReorderComp 并存的遗留桥；调用方未确认 | N |

## 5. 报告簇（RP）

| ID | 条件与校验 | 执行 | 证据 |
| --- | --- | --- | --- |
| RP01 模拟报告门 | `CanExecuteReportCommand`＝HasActiveDocument 且 **!IsSimRunning** | Execute：!CanReport→CannotReport 提示；否则 `DialogDriver.ShowSimReportsDlg` | S，IL |
| RP02 属性报告门 | CanExecute 与 NavigateTo 同 RVA（HasActiveDocument） | Execute：!CanReportInPropertiesMode→按模式（Analysis/Estimation/Regression）提示；否则 ShowSimReportsDlgInPropertiesMode | S，IL＋checks |
| RP03 互斥写入 | `MakeCanReport`：模式1→CanReport=b，且 b 时清属性门；模式0→属性门=b，且 b 时清 CanReport；末尾 `UpdateIsEnabledStreamAnalysis` | Run/Step 置 true、Reinit 置 false → **运行簇与报告簇的启用边** | S，IL |

## 6. 按钮关系图谱（本轮新增边）

| 边 | 类型 | 证据 |
| --- | --- | --- |
| Run/Step/Stop/Reinit/TimePlot/MoveTo → 同一 CanInvoke(Status≠2) 机制 | 共享门 | RC12 |
| Reinit≡TimePlot≡MoveTo；Rewind≡TakeSnapshot≡ManageSnapshots | 同体门 | checks |
| RefreshRunCommands → 全簇；SolverThreadIsActive 分裂两组 | 刷新枢纽 | RC07 |
| 分析面板打开 ⊣ Run/Step/Reinit（Stop 豁免） | 阻挡 | RC08–RC11 |
| Run/Step → MakeCanReport(true)；Reinit → false；两报告门互斥 | 启用边 | RP03 |
| Reinit → RemoveALLCAResults / UpdateStreamsStyleAfterRunEvent | 数据副作用 | RC11 |
| Next 按钮 ≡ Next Input ≡ 脚本 → NextInputFn | 共享执行器 | NV01–NV03 |
| Next → StoreValueEvent（先提交表单） | 提交边 | NV04 |
| Next → RUN 令牌 → 控制面板＋OnRunRun | 触发边 | NV06 |
| Next → GOTOSIM/跨组确认 → NavigateTo | 导航边 | NV06 |
| Undo/Redo → 屏幕类型事件分派 | 分派 | UD02 |
| cmdReorder → 双门 → ReorderComp → OK 历史重放 SMreorderM | 提交链 | UC02–UC04 |
| cmdUserDefWizard → gxUserDefWizard → ShowUserDefinedWizard | 桥链 | UC01 |
| 组分查找 Add → 立即写项目（前轮）；检索/检查共执行器（前轮） | 继承 | other-button-logic F/R |

## 7. 全量清单与差集

`inventory_diff.py`（.local）对 `ui-operation-audit/operations.json` 与 shell 代码命令做双轨差集，输出 inventory-summary.json / uncovered-controls.json / shell-command-inventory.json（摘要两份随本报告发布；1.2MB 的 uncovered-controls.json 仅留 .local）：

- 布局按钮候选 **4,190**（含 RadioButton/选项按钮等；不含列定义），已被证据追踪 **136**，未覆盖 **4,054**。
- 菜单节点 **1,365**（静态；动态追加未计）。
- shell 代码命令 **139**，已追踪 **21**，未覆盖 **118**（经济分析、动态、EO、绘图格式功能区、分析工具、帮助/关于等）。
- 未覆盖布局按钮集中在：各模块块页面（RadFrac/Reactor/Petrofrac/Solids 等）、石油/聚合物表征、结果与绘图（PlotFormatRibbon 等）、Setup/Convergence/Controllers。**主功能区 Run/Stop/Undo 不在静态 BAML 中**，只能以 IL 命令图为准。

差集是“执行链未被证据追踪”的清单，不等于“原版不存在该逻辑”；候选数也不等于可操作控件数。

## 8. 尚未确认清单

本轮新增待验（均需动态或更深原生分析）：

1. status_code→ActionStatus 的完整真值表与写入路径（原生 BatchGet 数据路径）。
2. run-anyway 覆盖（GetRunAnyWayValue/IsInputNotComplete）的原生判定。
3. HappRunM(10)/(8) 的停止/回卷语义；OnStopPending 订阅者。
4. EOReinitDlg / ShowSimReinitDlg 选项与返回；radfracBlkList 填充时机。
5. NextHit 算法；“Next Incomplete” 原生实现；bRunAfterInputIsComplete/disableITOnly 消费方；StoreValueEvent 订阅者；状态常量 16842768/10240/74752。
6. undo/redo 列表的 push 来源（哪些操作可撤销）；非 Flowsheet/ModelLibrary 屏幕的撤销路径。
7. ShowUserDefinedWizard COM 服务器内部（向导页、校验、写项目时机）。
8. SMreorderM 原生记录语义（逐对交换/移动、通知、失败分支）。
9. 亨利入口按钮绑定；亨利 ListPicker 事务；ReorderComp 遗留原生桥调用方。
10. EnergyAnalysisAgent.IsAutoRun 链；UpdateDynamicsButtons；GlobalScriptEnable 消费方；RefreshNavigatorViewFilter。
11. 118 个 shell 代码命令与 4,054 个布局按钮候选的执行链（第 7 节清单）。

继承前轮仍未确认：反应生成与盐/离子/Henry 数据、SFE 固体记录、PubChem 网络、方法助手定义文件与应用建议、M05 名称对话框 fallthrough 疑点、清理参数来源编码全表、查找添加冲突策略全分支、关闭中搜索线程竞态、15,535 个运行时绑定与 11 个缺失 ContentType、动态追加菜单。

## 9. 待运行动态验收案例

桌面输入接口前轮失败于 `GetCursorPos 拒绝访问`，本轮未尝试点击。以下为整理出的待运行案例（不是已测试）：

1. 无案例/有案例未运行/运行中/运行完成四态下，Run/Step/Stop/Reinit/Rewind/报告/Next 的启用矩阵，对照 RC/RP 门。
2. 打开分析对话框后点 Run/Step/Reinit/Stop：前三者提示且不运行，Stop 行为观察。
3. 含 RadFrac 结果时 Reinit：柱分析结果是否清空、流股样式是否刷新、报告门是否关闭。
4. 表单未填完点 Next：StoreValue 提交、NextHit 命中、跨组确认、RUN 令牌自动运行各分支。
5. 组分<2、含空 CID 行、正常三种情况点重新排序；对话框多选移动→确定→保存重开验证顺序；取消验证零写入。
6. 用户定义向导入口→观察 COM 向导页与写项目时机。
7. 流程图屏幕与模型库图标编辑器中 Ctrl+Z/Y 的分派差异；其他屏幕的撤销行为。

## 10. 校验与资产边界

- [checks.json](checks.json) 18 项一致性检查全部通过（共享 RVA、CanInvoke 体、默认 Status=2、SMreorderM 重放、Cancel 零写入、桥字符串、导出 RVA、与前轮安装文件哈希连续）。
- [verify_evidence.py](verify_evidence.py) 可复算哈希与 token/RVA 一致性；[reproduce.py](reproduce.py) 可在新目录重跑全部提取。
- 受保护 `.local/property-database/` 未写入：本轮所有输出均为新目录；验证见 [validation.md](validation.md)。
- 未解包安装介质；未上传安装文件、数据库或反编译产物；发布内容仅 authored 报告、索引与脚本。
