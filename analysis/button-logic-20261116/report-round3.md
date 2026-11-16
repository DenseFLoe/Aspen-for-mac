# 按钮逻辑确认第三轮（2026-11-16）

同分支 `codex/button-logic-exploration`。索引 [evidence-index-round3.json](evidence-index-round3.json)、检查 [checks-round3.json](checks-round3.json)（**16/16 通过**）。仍无动态点击。

## 1. 分析工具按钮簇闭环

- **Pure/Binary/Mixture/Solubility 四个分析按钮共用 `ExecuteShowAnalysisFormCommand`**（IL 直接委托）。
- 共享执行器顺序：发 **StoreValueEvent**（先提交当前表单）→ `SetPartialResultsOnAnalysis`（与“检索参数”R03 同款前置状态修改，取消不回滚）→ 许可证门（`CheckSplitLicense`，无许可证提示）→ 残渣曲线/三元图先经 `DistillationSynthesis` 选择对话框（含“不再显示”写回）→ `MmgSor.SetCanned/MMsetpgc/MMsetnec/MMsetcpt` 保存-设置-恢复罐装搜索参数 → InvokeAction 分析 → `ShowFormEventArgs`＋`ShowScreenEventArgs` 打开 **Analysis 面板**＋`CreateAnalysisSumbuf`。
- **关系闭环**：分析按钮打开的正是 RC08–RC11 中阻挡 Run/Step/Reinit 的 AnalysisScreenFactory 面板；分析簇与运行簇经“面板打开”边互锁。
- Azeotrope 单独走许可证门＋`SplitAzeotropeSearch`。

## 2. StoreValueEvent＝通用“提交待决编辑”钩子

IL 引用扫描（scan_refs.py）给出 ApwnShell 内完整发布/订阅边：

- **发布方**：Save/SaveAs、关闭文档/窗口关闭、**屏幕切换 OnActiveDocumentScreenChanged**、NextInputFn/NextInput_Executed、分析入口、DumpViewModel。即“保存前、关前、切屏前、下一步前、分析前”都先提交。
- **订阅方**：`ApwnFlowsheetControl.OnStoreValueEvent`→`AxPfsctrl.SaveEmbeddedWPFForms`（提交流程图内嵌 WPF 表单）；`ApwnFormContentHost.OnContainerStoreValueEvent`→**焦点法提交**（从焦点元素上溯 MMViewModelContainer 重新聚焦/清焦点，逼 WPF 绑定推值）；`ApwnModalForm` 同订阅；CustomForms 嵌入表格提交编辑单元格（续轮）。
- 移植含义：任何“离开当前编辑上下文”的操作都隐含一次提交；取消类操作若发生在提交后则不可回滚待决编辑。

## 3. ModelLibrary 撤销与列表项点击

- shell `OnModelLibraryUndoRedoEvent`：从事件取 UndoRedoScreenType 与 **UndoItems/RedoItems** 建列表——图标编辑器的撤销栈由编辑器经事件推送，shell 不持有。
- `ListBoxUndoItem_PreviewMouseDown`：解析项 Tag 索引→按屏幕类型发 ModelLibrary/Flowsheet 多步执行事件（对应 `SetStepsUndo/Redo(CurIndex)`）。**点击列表项＝跳转到该步的多步撤销**。
- 边界：事件发布方在 Xeq 根/WPFForms/Modules/WpfPlotWizards/共享目录的托管程序集中均未定位（IconCtrl/SmartIconContainer 无该类型引用），可能在原生 interop 层；未确认。

## 4. 运行状态常量部分解码

- `HAQueryRunStatus`（mmg @0x2ad690）＝**GRinq\* 引擎查询合成的位标志**：GRinqsme(求解模式)/GRinqerr/GRinqust/GRinqrdy/GRinqrsl(结果)/GRinqcpt(输入完整)/GRinqrst/GRinqpgc/GRinqrcl/GRinqgpd。
- 常量对应：10240=0x2800、74752=0x12400 为该函数分支输出；16842768=0x1010010=**0x1000000(有结果基位，sub_2ad5d0)｜0x10010(输入不完整族)**；NextStatus 检查的 0x10000 为另一族位。基位函数 sub_2ad5d0 输出 0x1000000/0x2000000/0x4000 三态。
- 即“控制面板状态”不是单一枚举而是结果×完整性×模式的位组合；完整 UI 标签映射仍未确认。

## 5. 本轮触及但未闭合的边界

- **Next Incomplete**：字符串仅存于 fimmtop 排序名字池（0x1455d8），无 strcmp/LEA/指针表引用可闭合 handler；分派表结构未知，原生实现仍未确认。
- **runanyway 写入方**：mmg 数据导出；smge/Simdll 有 IAT 导入但 .text 无直接引用（间接访问）；写入方未定位。
- **HappRun 10/8 语义**：vtable 槽 0x270 间接分派（续轮），对象类型未闭合。
- ModelLibrary 撤销事件发布方（§3）。
- 继承清单不变（反应生成、SFE 固体、PubChem、助手定义文件、M05 fallthrough、清理编码全表、查找冲突、搜索竞态、118 shell 命令/4,054 布局候选等）。

## 6. 校验

16/16 检查通过；三索引 verify 均 0 失败；保护资产 3,226 未动；扫描产物（storevalue-refs-shell.json 等）留 .local 并在索引登记。