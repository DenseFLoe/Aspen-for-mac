# 按钮逻辑确认续轮（2026-11-16 第二轮）

同分支 `codex/button-logic-exploration`。本轮对 [report.md](report.md) 第 8 节未确认清单逐条做证据级确认，新增索引 [evidence-index-confirm.json](evidence-index-confirm.json) 与 [checks-confirm.json](checks-confirm.json)（**24/24 通过**）。证据仍为 IL/N/L/D 口径，**无动态点击**。大体积提取续存 `.local/button-logic-exploration-20261116/`。

## 0. 对前轮的更正

选择页那个“无命令名”按钮**不是亨利入口**：布局 `VariablePath=BioLookupVar`，处理函数 `BioLookupCommandExecute` 收集组分网格中生物质类型行（按 `MMComboBox1_MultiMap` 类型映射过滤）——是**生物质查找**入口。亨利页（MMHenryComps）经导航树打开，选择页没有其入口按钮。前轮 UC05 的猜测据此更正。

## 1. 状态机制闭环（原未确认 1）

- 数据路径：`CxsSolver.GetActionStatus(action)`→`CxsCase.GetActionStatus("Top.Solver", action)`；动作集 **Run/RunFor/Step/Pause/Stop/Restart/Initialize**（D＋IL）。即控制面板的 Pause/Restart 等按钮与 Run 同机制。
- **managed 边界真值表确认**：`ValueToActionStatusDetails` 把原生返回的**字符串**首字符 '0'/'1'/'2' 映射为 Status 0/1/2，其余字符为消息；空串/未知首字符→Status 2。`CanInvoke=(Status!=2)`。故 0/1 均可 invoking，2＝禁用并带消息。
- 仍未确认：原生字符串的生成端（status_code→该字符串的引擎映射）、Status 0 与 1 的语义差异。

## 2. run-anyway 与输入完整性（原未确认 2）

- `GetRunAnyWayValue` 直接读**原生导入全局变量** `runanyway`（mmg.dll 数据导出 @0xa03704）——是原生配置全局，不是托管设置；写入方（选项对话框?）未追。
- `IsInputNotComplete`→mmg `IsNotComplete`@0x3683e0：含 17 处资源串读取、`GRinqautorun`（自动运行设置查询）、HYPshFinfo/HYPopFinfo 文件信息栈；完整判定式未解码。

## 3. 停止/回卷原生语义（原未确认 3，部分确认）

- `HappRunM(code)`＝`HappRun(code)==0`；Happ.dll `HappRun`@0x24010 仅 15 条指令，**经 vtable 槽 [rax+0x270] 间接分派**。分派机制确认；对象类型与 10/8 的具体语义仍待解析（间接调用边界）。

## 4. SMreorder 记录语义（原未确认 8，确认）

smge `SMreorder`@0x16cd00：`MDfnddir/MDfndkey` 定位 **COMPONENTS/MAIN**；`DRstovbg/MDcycsnt/MDgetvar` 读向量；`SYiwpdir`＋`MDsetvar/MDsetvax`＋内部 `SMInsertlocation` 写回；`HANotify` 广播；`DRstovnd` 收尾。即**记录级移动＋UI 通知**，非视图排序。managed 侧两个 ID 以引用 marshaling，原生可回写规范化 ID。失败/冲突分支未全解码。

## 5. 用户定义向导提交模型（原未确认 7，确认）

F 内 `UserDefinedComp0/1/2`＋`UserDefinedCompWizardMain`；入口 `ShowUserDefinedWizard` 模态，DialogResult true→1 否则 0。

| 动作 | 行为 | 证据 |
| --- | --- | --- |
| 页0 前进 | `ProcessNext`→`WriteUserDefComp`（`SetUserDefCompM`）**立即写项目** | IL |
| 页1 前进 | `WriteNodeParameters`（逐参数 `Get/SetParameterM`） | IL |
| 页1 返回 | **`DeleteUserDefComp`（删除已建组分）** | IL |
| 取消 | **`DeleteUserDefComp`＋InitStaticMembers＋Close＝补偿删除，不是零写入** | IL |
| 完成 | 非 ASCII 守卫（PopupNoneAsciiCharMsg）；组分类型变更保护（g_storecompflag −1/−2、CannotChangeCompType）；按当前页补写；DialogResult=true | IL |
| 页0 校验 | `CheckifCIDisUsedM`/`CheckFormulaInDBM` | IL |
| 结构页 | molfile 压缩/解压缩、`SetMolFilePathM`、`DelStructM` | IL |
| 估算 | radio→`SMestiUserDefM`；辅助按钮→`ChkDataRecordM/CreateDataRecordM/CreateRecordM` | IL |

**与查找/重排的提交模型都不同**：向导＝分页立即写＋回退/取消补偿删除。移植时不能套用“取消零写入”。

## 6. 撤销/重做来源闭环（原未确认 6，流程图部分确认）

- 列表来源＝**原生 PFS ActiveX**：`AxPfsctrl.GetUndoList/GetRedoList`；`pfs_UndoRedoChanged`→SetDirtyFlag＋发 FlowsheetControlUndoRedoEventArgs→shell 填充列表。可撤销操作＝PFS 控件记录的操作（放置/删除/连接等），托管不 push。
- 执行：`FocusInTextEdit`→忽略（文本编辑自己消费撤销）；单步 `SetOneStepUndo/SetOneStepRedo`；多步 `SetStepsUndo/SetStepsRedo(CurIndex)`；第三分支仅刷新。
- 仍未确认：ModelLibraryIconEditor 的列表来源；PFS 内部记录粒度。

## 7. NextHit 与 StoreValue（原未确认 5，大部分确认）

- `MMTabStrip.NextHit` 两遍扫描：选中 tab 若 Accessible≠false 且 Complete==false→**留在本 tab** 并输出其 CompletionMessages；否则选中其后第一个 accessible 且 incomplete 的 tab；无→−1。
- `MMViewModel.NextHit`：遍历属性声明，值实现 `ICxvCompletableObject` 且 IsComplete==false→`ShowNextIncomplete()`（聚焦字段）；否则用 CxsWatch 监视 `@main.CC Nodes.<path>` 完成状态与消息串，拼接输出。
- `StoreValueEvent` 订阅者确认其一：`CustomFormControl.OnStoreValueEvent`（与 PFS 嵌入变体**同 RVA**）→提交嵌入自定义表格的当前编辑单元格。完整订阅者集合未穷尽。
- `bRunAfterInputIsComplete` 消费方＝`NextStatus`（`MMGetSuppressM()==1 || flag`），并在导航后把 “Results Only” 重置为 “All Items”、调 OnNext；`disableITOnly` 在运行判定前后成对保存/恢复。
- `RefreshNavigatorViewFilter`：`MMinqrsl()>0`（有结果）才提供 Results Only 过滤项，否则移除并重置；`UpdateDynamicsButtons` 刷新 6 个动态命令（activateDynamics/sendToFlowDriven/updateFlowDriven/sendToPressureDriven/updatePressureDriven/pressureChecker）启用。**运行枢纽的边扩展到动态按钮组与导航过滤器**。
- 仍未确认：“Next Incomplete” 原生实现、状态常量 16842768/10240/74752 含义。

## 8. 重初始化对话框闭环（原未确认 4，确认）

- `ReinitDlg`＝类别选择（Simulation/Block/Convergence/Streams，另有 Batch_Restart）＋逐块复选框。OK：按类别选动作串；Simulation 且选了块→`Reinit.GetPrompt` 二次确认；`InvokeAction("Top.Solver",…)`；Block 类按 `Top.appModelV8.Blocks.<name>` BatchGet 收集 RadFrac 块→**发 ReInitEventArgs(块列表)**→`ApwnSimulationCommands.OnReInitEvent` 存 radfracBlkList→Reinit 后 `RemoveALLCAResults`。Cancel 零写入。CanExecuteOK 依赖类别/块选择非空。
- `EOReinitDlg` OK：CloseForm(true)＋`InvokeAction("Top.Solver", action,[Choice,gScope])`；**Choice==4→发 EOVariableImportedEvent**；Cancel 仅 CloseForm(false)。
- `ShowSimReinitDlg` 仅 DialogResult==true 返回 true。

## 9. 关系图谱新增边

| 边 | 类型 | 证据 |
| --- | --- | --- |
| 向导页0前进→写组分；页1前进→写参数；页1返回/取消→补偿删除 | 提交/补偿 | §5 |
| PFS ActiveX undo 栈 ↔ shell 撤销 UI；FocusInTextEdit 豁免 | 来源/分派 | §6 |
| ReinitDlg OK→ReInitEvent→radfracBlkList→CA 结果清除 | 数据链 | §8 |
| 运行枢纽→动态六命令启用；→Results Only 过滤器可用性 | 刷新枢纽 | §7 |
| NextStatus 消费 bRunAfterInputIsComplete；Next→Run 链补全 | 触发 | §7 |
| Pause/Restart/RunFor 与 Run 同状态机制 | 共享门 | §1 |

## 10. 更新后的未确认清单

1. 原生状态字符串生成端与 status_code 全真值表；Status 0/1 语义差异。
2. runanyway 全局的写入方；IsNotComplete 完整判定式。
3. HappRun vtable 对象类型与 10/8 语义。
4. SMreorder 失败/冲突分支。
5. ModelLibrary 撤销列表来源；PFS 记录粒度；StoreValue 完整订阅者集合。
6. “Next Incomplete” 原生实现；状态常量含义；SMestiUserDefM 估算数值逻辑。
7. 118 个 shell 代码命令、4,054 个布局按钮候选（差集见 inventory-summary.json）。
8. 继承：反应生成、SFE 固体、PubChem、方法助手定义文件、M05 fallthrough、清理来源编码全表、查找冲突策略、关闭中搜索竞态、运行时绑定与动态菜单。

## 11. 校验

- checks-confirm 24/24；`verify_evidence.py --index evidence-index-confirm.json --checks checks-confirm.json` 复算哈希/定位一致。
- 受保护资产仍 3,226 文件；本轮无写入；无动态点击；未上传。