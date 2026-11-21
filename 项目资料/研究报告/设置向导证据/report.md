# 电解质与 SFE 向导执行逻辑

后续实现：[向导项目写入](../../docs/wizard-business-logic.md)已接入已核实子集；本报告的组分表右键、标题双击及统一多选排序漏接已由[落实续轮](../../docs/research-report-implementation.md)补齐。下文移植差异保留为研究时基准，未解析规则和动态边界仍适用。

本轮已把两个入口追到项目写入函数，确认它们有不同的提交时点：**电解质常规分支在模拟法页“下一步”时写项目；SFE 在末页“完成”时写项目。** 当前移植版两者都只在最后保存 `unverifiedInputs.assistants`。这既是业务能力缺口，也影响返回、取消、错误检查与后续页面。

完整操作链指入口到处理函数、校验、状态修改和后续页面的静态闭环；不表示原生反应生成算法或所有运行场景已验证。盐/离子生成的底层虚调用、全局继承权限、窗口 X 与 Esc 的完整运行效果仍有边界，见末尾。未修改移植版功能代码。

## 证据口径与文件

| 标识 | 文件，均相对 `C:/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/` | 证据用途 |
| --- | --- | --- |
| C | `WPFForms/AspenTech.AspenPlus.MMForms.Components.dll` | 组分页面、命令绑定及 ViewModel |
| F | `AspenTech.AspenPlus.WpfFindComponent.dll` | 电解质、SFE、查找、排序实际 C# 方法和 IL |
| W | `AspenTech.AspenPlus.ModelLibrary.Controls.dll` | 通用向导状态机、按钮命令和全部页面完成钩子 |
| M | `AspenTech.AspenPlus.MMControls.dll` | Custom Actions 包装、动态表格右键菜单 |
| U | `AspenTech.AspenPlus.UnmanagedWrapper.dll` | SmgeHelper → C++/CLI native stub → smge 导入 |
| N | `smge.dll` | 反应候选、组件和 Chemistry/Henry/全局字段写入 |
| B | `FindComponent.dll` | gx 命令到托管 COM Driver 的桥接 |
| D | `fimmtop.dll` | 命令字符串映射和原生分派 |
| R | 仓库 `ui/recovered/Components.json`、`WpfFindComponent.json` | 已有 BAML 布局、只读属性、事件和命令目标 |
| O | `docs/ui-operation-parity.md` | 上轮 WATER 案例观察，仅作已有动态佐证 |

上述8个安装文件的 SHA-256、方法完整名称、Token/RVA 和 native 区间见 [evidence-index.json](evidence-index.json)。表内 `F:类型.方法` 可在该索引按名称查到固定函数位置。本地阅读版位于 `.local/wizard-logic-analysis-20261115/decompiled/`；以下表述不是原始源码。

**确认-IL**：从托管方法体、布局/事件绑定确认；**确认-N**：原生指令、导入、导出及字段引用确认；**既有观察**：沿用明确标注的旧记录；**推测/未解析**：证据不足，禁止据此实现成“原版已确认”。没有把本轮自动化失败记为通过。

## 两条入口闭环

```text
组分 > 规定 > 选择
  cmdElecWizard → cmdElecWizard_CommandExecute
    → MmgExtensions.GxElectrolyteWizard
    → InvokeAction(Top.appModelV8.Custom Actions, gxElectrolyteWizard, true)
    → fimmtop 字符串映射 0x1e → FINDCOMPONENT.gxElectrolyteWizard
    → IDispatch 按名称调用 ShowElecWizard(localUseAped)
    → FindComponentDriver.ShowElecWizard → ElecWizardMain.ShowDialog
    → Form7 → Form11 → Form12 → Form10 → Form6

  cmdSFEAssistant → cmdSFEAssistant_CommandExecute
    → MmgExtensions.GxSFEAssistantMain
    → InvokeAction(..., gxSFEAssistantMain, true)
    → fimmtop 字符串映射 0x20 → FINDCOMPONENT.gxSFEAssistantMain
    → IDispatch 按名称调用 ShowSFEAssistantMain(localUseAped)
    → FindComponentDriver.ShowSFEAssistantMain → SFEAssistantMain.ShowDialog
    → Step1 → Step2 → Finish
```

`gxSFEAssistant`（映射 0x1f）是另一个旧入口，调用 `ShowSFEAssistant`/单窗 `SFEAssistant`；**不能把它的逻辑误套到当前页面的两步助手**。

确认-N 位置：D `0x143e0` 解析命令，`0x145ae/0x145c6` 对应电解质，`0x14602/0x1461a` 对应 SFE Main；D `0x167f0` 分派器在 `0x1a29a/0x1a2be` 调用上述导入。B 导出 `0x31d0/0x3d90`，分别到 `0x1490/0x18e0`；后者引用 `ShowElecWizard`/`ShowSFEAssistantMain`，通过 IDispatch 的 GetIDsOfNames/Invoke 调用。Driver 类及双接口暴露对应方法。B 两个导出最终返回 0，故不能简单把托管 DialogResult 当作最上层业务成功值。

## 操作入口—触发条件—执行逻辑—数据变化—后续页面

### 电解质

| ID / 操作入口 | 触发条件与禁用/拒绝 | 执行逻辑 | 数据变化 | 后续页面 / 分支 | 来源与结论 |
| --- | --- | --- | --- | --- | --- |
| E01 组分页电解质按钮 | 页面命令仅提供执行委托，局部未指定 CanExecute；不能由此证明所有运行模式均可用 | 经上述 Custom Action/COM 链进入 Driver；首次检查配置中是否存在别名匹配 `^APV[0-9]+$` 的库，区分 postgres 与另一 APED 路径，结果缓存于静态 nullable bool | 初始化向导静态状态；没有本行的项目记录写入 | 无合格 APV 库则提示并返回 0；否则模态欢迎页 | C:Selection_ViewModel.get_cmdElecWizard_Command / cmdElecWizard_CommandExecute；F:FindComponentDriver.ShowElecWizard；确认-IL/N |
| E02 欢迎页库选择与参考态 | `localUseAped != 0` 且反应库数非零才显示可选数据库，否则隐藏库选择；允许前进 | GetTotalNumberOfReacDatabanks/GetReacDatabanksList，库名排序后反转并取第一个；改下拉调用 GetReacDatabankM；参考态 index 0/1 → flag 0/1 | 反应库上下文、`g_refStateFlag`；不是写项目物性方法 | Form11 基准组分 | F:ElectrolyteForm7.Loaded / 两个 SelectionChanged；确认-IL；不会永远固定 APV150 |
| E03 进入基准组分 | GetBaseCompsM 返回 0 则结束初始化；非对称态还检查 CheckWaterM，失败提示 WaterRequired | SetGenNewCompsM(1)，收集原生可用基准组分；初次列表为空选择，非对称态 MoveWaterComponent 自动移入 H2O；返回重进重设选中标志 | 原生 species 的选中位、UI 集合；默认 hydronium 与成盐选中 | 同页；无水不等同仅禁用一个按钮 | F:ElectrolyteForm11.Loaded / MoveWaterComponent；U:GetBaseCompsM；N:get_base_comps@0x1d1320；确认-IL/N |
| E04 移入/移除/全部/双击 | 按钮启用主要按列表是否非空；单移还检查 `_setbasecomps` 和 SelectedItems。移除单选 H2O 且非对称态时拒绝；多选情形不能扩写成“永远不可移除水” | SetSpecsSelected(基准类型1)，更新列表；清空会在非对称态重新移入 H2O；双击必须命中 ListBoxItem，直接调用同一 click 方法 | 候选选择位；随后重新生成候选反应 | 同页 | F:Form11.btnMove/btnRemove/btnMoveAll/btnClearAll / 两个 MouseDoubleClick；确认-IL |
| E05 氢离子、成盐、水离解、成冰选项 | radio/checkbox 事件调用 Update；有效基准集合前置如 E03 | ClearAllocatedRxnSpace → SetHydroniumIsH/SetIncludeSalt/SetWaterDissoc/SetIceFormation → RxnInit → GenRxnsAfresh → GetNumRxnsPossible | 原生候选反应缓冲与 `g_reactions`；尚非最终项目记录 | 同页，Next 再检候选是否存在 | F:Form11.Update；U:同名 M 包装；N:rxninit@0x1d23a0、gen_rxns_afresh@0x1d10c0 → genrxns@0x1d10f0；确认-IL/N，生成算法内部有未解析虚调用 |
| E06 基准页下一步 | `g_reactions == 0` 弹“无可用反应”并返回 false；不是单纯 selected.count > 0 | 有候选才允许状态机前进 | 不在此写最终 Chemistry | Form12；失败留 Form11 | F:Form11.OnForward；既有观察 O：仅 WATER 默认无反应，勾水离解产生 H3O+/OH- |
| E07 生成列表加载/删除 | 三个列表全空：删除、前进、两种生成选项均禁用；否则启用。删除还检实际焦点列表及选中项 | CollectAqueousSpecies/CollectSalts/CollectReactions；删除按焦点分别调用 ExcludeAq、ExcludeSalt、RemRxns 后重新收集 | 过滤原生候选，可能连带改变相关反应；不应只从界面删一行 | 同页；全空只能回退 | F:Form12.CollectAll / btnRemove_Click / GotFocus；N:exclude_aq@0x1d09f0、exclude_salt@0x1d0a10、rem_rxns@0x1d2340；确认-IL/N |
| E08 设置全局方法 | 非对称给 ELECNRTL、ENRTL-RK；对称只给 ENRTL-SR | 每次 Loaded 重设为“设置方法”，恢复仍有效的方法索引；g_optSet 随选择变化 | 先只存向导状态；真正全局写入在 E12 | 下一步走默认 GLOBAL ID 分支 | F:Form12.Loaded / radioGenSpecRxns_Checked；确认-IL |
| E09 不设置方法 + 生成 Chemistry/Henry | 选“不设置”会勾选生成；前进有效、完成无效 | `g_eform12nextcheck=1`，分别要求输入 Chemistry ID 与（有 Henry 候选时）Henry ID；已有 ID 弹 Yes/No/Cancel | 本步骤选择目标 ID，无最终写入 | 成功 → Form10；取消子对话框 → 留 Form12 | F:Form12.radioGenChemHenry_Checked / OnForward；ElecWizardMain.GenerateChemHenrySpecs；确认-IL |
| E10 不设置方法 + 取消勾选生成 | `IsGenHenryChemChecked=false` → CanForward=false、CanFinish=true；可在 Form12 提前结束 | W.Finish 遍历所有页 OnFinished；Form12 在分支1且未勾选时调用 WriteNewBaseCompsM(ref msgs,0) | 仅写新组分/数据库顺序等；不经过 Form10.OnForward，因而本链不写 Chemistry/Henry/全局方法 | 直接关闭，不必经过最后两页 | F:Form12.set_IsGenHenryChemChecked / OnFinished；W:Finish；N:write_new_base_comps@0x1d4110；确认-IL/N；移植版漏接 |
| E11 设置方法分支的下一步/重名 | 从 GLOBAL 开始。已有 Chemistry：Yes 使用该名，No 进入 OneIdDialog 并循环检查新名，Cancel 返回 false；Henry 仅有候选且同名已存在才进入同样分支 | GenerateSpeciesReactions 的名字容易误导：这里主要决定 ID 和重名处置，反应早在 E05 生成 | 目标 ID、消息标志；实际写入下一页才发生 | Form10；子窗口取消留 Form12 | F:ElecWizardMain.GenerateSpeciesReactions / Form12.OnForward；确认-IL |
| E12 模拟法页下一步 | 设置方法分支可选真实/表观，默认真；不设置分支两项禁用。两个 ID 字段原布局 IsReadOnly=true | 设置方法：WriteElecWizardFlagM(1) → WriteChemRecordM(name,ref msgs,approach,1,refState) → 有 Henry 则 WriteHcompRecordM(name,1) → SetGlobalOpsetM(所选或 ELECNRTL)。不设置：WriteChemRecordM(...,0,0,refState)，Henry 使用 global=0 | **此处已写入项目**：新组分、Chemistry、可选 Henry；设置方法分支还改全局方法与引用 | Form6 完成页；不是等 Finish 才提交 | F:Form10.Loaded / OnForward；R:Form10；U:WriteChemRecordM；N:0x1d2ac0、0x1d3bf0、0x1d25b0；确认-IL/N，O 有进入完成页前已更新的观察 |
| E13 完成页查看 Henry / 修改反应 | 页面 `CanFinish=true, CanBackward=false, CanCancel=false`；后者是否禁用外层取消按钮不能仅由属性确认 | DriveDialogEvent 以实际记录为 main；Henry 类型 MMHenryComps.MMHenryComps_Input_RewHen；反应类型 MMChemistry.MMChemistry_InputC | 查看/编辑的是已创建项目节点。子表单内部确认/取消事务未在本轮穷尽 | 打开二级编辑窗口；回到完成页 | F:Form6.Loaded / btnReviewHenryList_Click / btnModifyAddRxns_Click；确认-IL；主路径见下一表 |
| E14 返回 | Form12 返回会 ResetAll（species类型2/3及反应选中位清零）+ ClearAllocatedRxnSpace；Form10 没有专属 OnBackward，走基类 | W.GoBackward 先调用当前页 OnBackward，成功才弹导航栈；若重进触发 Loaded，则执行该页重建逻辑 | 改候选缓冲/向导状态；不能当成已提交项目的撤销 | 完成页没有正常 Back；较早页回上页 | W:GoBackward；F:Form12.OnBackward；确认-IL/N |
| E15 取消、完成、X、Esc | 外层 Cancel 有 IsCancel=true；自身 Click 执行清理。完成页 CanCancel=false 未见直接绑定至此按钮 | Cancel=ResetAll+ClearAllocatedRxnSpace+Close；Finished=相同清理+DialogResult=true+Close。X 无本类 Closing/Closed 清理事件；Esc 有 WPF IsCancel 声明 | Cancel 清理函数的 native 证据为释放候选缓冲，未找到项目逆写/快照恢复；**不能承诺取消会撤销 E12**。X 清理及最终按钮状态需动态确认 | Driver 对非 true DialogResult 返回0；先前写入与返回码分开 | F:ElecWizardMain.buttonCancel_Click/theWizard_Finished/Connect；N:clear_alloced_rxn_space@0x1d0880；确认-IL/N；X/Esc实际路由未解析 |

### SFE（当前两步助手）

| ID / 操作入口 | 触发条件与禁用/拒绝 | 执行逻辑 | 数据变化 | 后续页面 / 分支 | 来源与结论 |
| --- | --- | --- | --- | --- | --- |
| S01 SFE 按钮 | 局部执行委托未设 CanExecute；Driver 同 E01 检查 APV 数据库并缓存 | ShowSFEAssistantMain，不是旧 ShowSFEAssistant；模态两步窗口 | 初始化原生库上下文与临时集合 | Step1 | C:cmdSFEAssistant_CommandExecute；M:GxSFEAssistantMain；F:Driver.ShowSFEAssistantMain；确认-IL/N |
| S02 可用组分 | 从项目 TYPE 的 child_ids 取对象；仅 CONV、PSEUDO、OLIGOMER；不把全部项目对象/离子/固体都列进来 | 同时读取 DBNAME1 与 ANAME1，保留 ComponentID、Name、Alias 三种身份 | 仅临时 SFEComponentData 集合和原生选中位 | 双击/按钮移入或移出 | F:Step1.Loaded / btnMove / btnRemove；确认-IL |
| S03 下一步 | 原版可点击，选中数为0时弹 MissingComponent 并 return false；移植版是预先禁用 | 将选中集合传到 Step2，切换 Back/Next/Finish 可见性；双击命中 ListBoxItem 才复用移动函数 | 页面共享选中集合 | Step2 | F:Step1.OnForward / MouseDoubleClick；确认-IL |
| S04 第二页初始/重入 | 首次读 Chemistry 子ID、default_name、GCHEMISTRY；无已有集合时禁用“已有”；无全局 Chemistry 时默认勾全局 | 新 ID 不应固定 C-1。**每次 Loaded 都 Clear solidComponentList 并重建固体默认名**：组件ID长度≤5用ID+(S)，否则取数据库名前5字符；数据库名空则取ID前5字符大写 | 临时名称映射；返回重进可能覆盖手工固体名，化学集的首次初始化则受 `_hasLoaded` 保护 | Step2 | F:Step2.Loaded；确认-IL。极短数据库名/空集合的异常边界未动态核实 |
| S05 编辑固体 ID | PreviewTextInput 限8字符、首字符 LetterOrDigit；允许后续 `$ & * ( ) + { } - = ] [ : > <` 与字母数字；禁止空格；并非移植版电解质的 ASCII 正则 | TextChanged 去空格/首字符处理，CellEditEnding 查其他固体名；重复则提示并清空编辑内容。粘贴命令还有专属 HandleCanExecute | 仅临时固体名；最终还有非空检查 | 仍在 Step2 | F:Step2.ValidName / TextBox_PreviewTextInput / CellEditEnding / HandleCanExecute；确认-IL；不能据此保证所有输入法/粘贴路径等价 |
| S06 新建/已有 Chemistry 与全局框 | 已有无列表不可选；已有被选且等于当前 GCHEMISTRY 时全局框禁用 | 切已有：禁用并清空新名称、启用下拉；切新建：启用名称、禁用下拉；检查已有名与当前全局名 | 先只改 UI/IsGlobalChecked | 同页；Finish 决定实际写入 | F:Step2.radioNewChemistry_Click / radioExistChemistry_Click / globalChemistryStatus；确认-IL |
| S07 最后完成校验 | 固体名非空；新化学集名非空或已有列表非空；目标名 Trim/Upper；新建同名现有 Chemistry 时拒绝；可用既有则追加 | 校验通过后分新建与已有两路。最终双重循环的 j 上界是 Count-1，遗漏最后一项比较；编辑结束有另一重复检查，不能把此实现缺陷当成合理规范 | 校验失败前不进入生成写入；不能保证底层永不拒绝已有固体 ID | 失败留 Step2；成功执行 S08/S09 | F:Step2.OnFinished 原始 IL 复核；确认-IL；重复冲突最终表现待动态核实 |
| S08 新 Chemistry 完成 | HasChemRecordM(name)==0 | **GenerateComponent → GenerateChemisty → GenerateReaction**。GenerateComponent 临时改两个询问/更新开关，顺序写固体组件后恢复；新化学集清空 GAMMA_BASIS | 写 TYPE=SOLID、DBNAME1、ANAME1；写 Chemistry。勾全局时 WriteChemRecord 参数 global=1，另写 GTRUE_COMPS=YES；填 SALT_COEF 与 SALT_OPTION | 所有 OnFinished 返回 true 才触发主窗 Finished，清理缓冲并关闭 | F:Step2.OnFinished / GenerateComponent / GenerateChemisty / GenerateReaction；确认-IL/N |
| S09 已有 Chemistry 完成 | HasChemRecordM!=0 且“已有”选中 | **GenerateComponent → GenerateReaction**；勾全局则直接设 GCHEMISTRY；不走 GenerateChemisty | 追加固体和盐式系数；已有相同 SALT_COEF solid key 跳过；本分支没有 S08 那条显式 GTRUE_COMPS=YES 写入 | 成功关闭 | F:Step2.OnFinished / GenerateReaction；确认-IL。读取的现有键数组并非每插入后重取，多组分特殊情形待核实 |
| S10 返回/取消/关闭 | Back 只切换按钮可见性并回 Step1；Cancel 始终由外层按钮处理 | 返回不提交；重进若触发 Loaded 则按 S04 重建。取消 ResetAll+ClearAllocatedRxnSpace+Close。X 无此类 Closing 钩子 | 正常未完成时没有 S08/S09 写入；生成中异常是否部分写入、底层批处理是否回滚未解析，代码未见包住全序列的显式事务/finally | 返回Step1或关闭 | F:Step2.OnBackward、SFEAssistantMain.buttonCancel_Click/theWizard_Finished；W:Finish；确认-IL/N；异常原子性未知 |

## 实际数据路径与写入边界

| 功能 | 已定位目标 | 写入依据与边界 |
| --- | --- | --- |
| SFE 固体身份 | `Top.appModelV8.Components.Specifications.Input.TYPE.#n` 的 id；`TYPE.<solid>=SOLID`；`DBNAME1.<solid>`；`ANAME1.<solid>` | F:GenerateComponent 四次显式 Set。这是**项目中的固体组分记录**，没有证据表明向 APED 安装数据库插入记录；纠正“生成固体数据库记录”的含混说法 |
| SFE 盐式反应 | `<chemistryRoot>.<id>.Input.SALT_COEF.<solid>.<fluid>=1`；`SALT_OPTION.<solid>=NO` | F:GenerateReaction 通过 AddChild、Set id/value；原有 solid key 则跳过 |
| Chemistry 根路径 | Aspen Plus：`Top.appModelV8.Reactions.Chemistry`；产品码2：`Top.appModelV8.Chemistry` | F:Step2.Loaded；Form6.btnModifyAddRxns_Click 也按产品分支 |
| 全局 Chemistry / 真组分 | `Top.appModelV8.Properties.Specifications.Input.GCHEMISTRY`、`GTRUE_COMPS` | SFE C# 明确；原生电解质写记录中也定位到字段 `GCHEMISTRY`、`GTRUE-COMPS` 与 MDsetvar，不能把 native 旧字段连字符原样当成所有 Cxs 路径 |
| Henry 查看节点 | `Top.appModelV8.Components.Henry-Comps.<id>` | F:Form6.btnReviewHenryList_Click 直接传 main；N:write_hcomp_record 引用 COMPONENTS/HENRY-COMPS/CID/ASKED，global 分支写 PROPERTIES/MAIN 的 GHEN |
| 电解质组分写入 | N:write_chem_record@0x1d2ac0 → `0x1d2c7b` 调 write_new_base_comps@0x1d4110 → 内部 `0x1d42f0` | 后者存在 ANAME/CID/TYPE、SOLID、名称冲突处理及 MDsetvar/MDrlcval，主过程还调整 databank、LSfixsmg/LSsort_to_attr/LSsavcid。详细所有类别与错误回滚未全部解码 |
| 电解质 Chemistry | N:write_chem_record 的两个 CHAININFO 分段覆盖 `0x1d2ac0–0x1d3bec` | MDcrerec/已有记录清理 helper@0x1d08d0 → 写新组分 → 逐候选写反应 → 参考态及可选全局引用。不能仅分析首段到0x1d2c6c，否则会错误得出“没有写组分/全局参数” |
| 全局物性方法 | N:set_global_opset@0x1d25b0；字符串 PPSTOPTN、PROPERTIES/MAIN、GOPSETNAME | 实际项目记录写入；没有据此声称跨平台已经可计算 |
| 候选清理 | N:clear_alloced_rxn_space@0x1d0880 两个 MDfree | 候选缓冲清理，不是项目撤销；项目文件何时保存由外层保存机制决定，本轮不等同磁盘落盘 |

## 右键、双击、快捷键及方法扩展

| 操作组合 | 是否同一路径 | 条件、数据与后续页 | 证据 / 移植差异 |
| --- | --- | --- | --- |
| 两个向导可用/所选列表双击 ↔ 移入/移除按钮 | **确认同一 click 处理函数** | 先沿 OriginalSource 祖先找到 ListBoxItem；空白处双击不移动；复用原生选择位与刷新逻辑 | F:Form11 与 Step1 的两个 MouseDoubleClick。移植版 `UiShellAssistants.cpp:44` 共享 moveItems，但没有原生刷新 |
| 组分表右键“重新排序记录” ↔ 页面“重新排序” | **确认同一个 ViewModel 命令** | 行头或网格单元且未选择列时添加右键项；CanExecute 转发绑定的 ReorderRecordCommand；该属性在 R 绑定 cmdReorder_Command | M:MMScrollAreaMS.AddContextMenu / OnRoutedReorderRecordCommand / CanRoutedReorderRecordCommand；C:cmdReorder_CommandExecute。移植版 ComponentWorkspace 无此命令的表格右键接线 |
| 排序窗口上/下、确定、取消 | 已扩展成完整子链 | 页面入口：网格无效返回、Count<2提示、遍历非末空行若CID空则拒绝；传首个选中ID。窗口读组件、仅临时保存交换历史；可多选上/下移；确定逐次 SMreorderM；取消只关闭 | F:ReorderComp.LoadComponents/MoveUp/MoveDown/OKCommand_Executed/CancelCommand_Executed。移植版 `reorderComponents` 只操作 components 数组，默认单选；用户定义对象未纳入统一顺序 |
| 组分页“选择组分”标题双击 ↔ 查找按钮 | **确认同一个 Find()** | 事件在 fra_DefineComponents 标签；不是任意空白或任意数据行。后续由 Find 根据选择/数据库走查找 | C:MMComp_Spec_Input_Selection.fra_DefineComponents_PreviewMouseDoubleClick；Selection_ViewModel.cmdFind_CommandExecute/Find。移植版普通 QLabel 未接此事件 |
| 查找结果双击 ↔ 添加按钮 | **确认调用 btnAdd.Command.CanExecute 再 Execute** | 业务前提由添加命令持有；不是直接绕过校验添加 | F:CompoundsTab.ListViewItem_MouseDoubleClick。移植版已有按命中行添加；真实库来源与原版多选行为需另核 |
| 向导 Back/Next/Finish 按钮 ↔ 同名 RoutedUICommand | **确认同一状态机** | Forward/Backward 先调用当前页钩子、成功才换页；Finish 遍历 Items 的全部 OnFinished，任意 false 终止；无自动回滚先前页副作用 | W:GoForward/GoBackward/Finish/RefreshEnableStatus；R:命令目标 theWizard；移植版只是 index±1 和单一完成 lambda |
| Esc ↔ 外层取消；X ↔ 取消 | Esc 有 IsCancel 声明，但**实际效果未验证**；X **未证明同路** | ElecWizardMain/SFEAssistantMain 没有专属 Closing/Closed 钩子；不能将 Close 自动等同 ResetAll。完成页属性与外层按钮状态也须区分 | R:两主窗 buttonCancel；F:Connect/构造函数。运行核对受0x80070005阻塞 |
| 电解质/SFE 快捷键、右键入口 | **未发现已确认等价入口** | 扫描现有117份菜单与所选类声明；不能排除 shell 动态命令/键盘路由。快捷键名称推测不能当证据 | 本轮未把未找到写成“不存在”；后续需从全局命令注册继续追 |

## 对照移植版的具体漏接/不同点

基准为本轮开始的 `3f17bdb`，所有位置都是本轮未改动的代码。

| 移植版位置 | 已确认差异 | 影响与未来接入边界 |
| --- | --- | --- |
| `src/UiShellAssistants.cpp:108` | 电解质将所有当前组分预先选中；SFE 未按 CONV/PSEUDO/OLIGOMER 过滤；身份被压为去重名称列表 | 不能照此假定原版预选、水条件、同名身份与候选集合 |
| 同文件 `:111` | APV150、ELECNRTL/ENRTL-RK 写死 | 缺库枚举及对称态 ENRTL-SR |
| 同文件 `:117`、`:156` | 允许空生成结果继续；前进只检选择数；Finish 只在最后页 | 缺“无反应”拒绝、删除联动、只加组分的提前完成分支 |
| 同文件 `:114`、`:176` | 将 Form10 两个原版只读ID变成可编辑并使用自定ASCII正则 | 漏掉前一页 Yes/No/Cancel 与 OneIdDialog 重名循环；验证位置与规则不同 |
| 同文件 `:169`、`:189` | 返回只 index-1，取消总 reject；最后保存配置，不写业务模型 | 缺候选缓冲重建、E12提前提交以及完成页禁止Back；不得把原版取消也描述为统一无副作用 |
| 同文件 `:130` | Henry/反应按钮仅弹“当前没有自动生成数据”说明 | 未打开绑定真实 Chemistry/Henry 节点的二级页面 |
| 同文件 `:142`、`:171` | SFE C-1 固定；solid ID来自显示名加(S)，返回保留人工名称 | 缺 default_name、5字符截取/8字符限制、按ComponentID构名与原版重进重建 |
| 同文件 `:164`、`:189` | 仅控新建/已有字段启用；无 SFE 完整冲突校验、当前全局名禁用规则和生成写入 | 缺固体组件、盐式系数、新/已有 Chemistry 不同全局写入路径 |
| `src/ComponentWorkspace.cpp`；`src/RecoveredWorkspace.cpp:465` | 组件主页无原版排序右键与标题双击；恢复表格提供通用编辑菜单 | 静态菜单目录存在不代表对应业务命令已接上 |
| `src/UiShellAssistants.cpp:59` | 排序直接重排项目 components；原版可以多选并提交交换历史 | 用户定义对象与数据库组件的统一顺序仍缺；该差异不要求机械复制原版内部实现 |

## 仍属推测、尚未解析和原版疑点

1. **确认的局部与未知的全局**：按钮本地委托无独立 CanExecute，不代表运行中、只读、其他文档状态或许可证下始终可用。未解析全部 MMTabPage/Cxs 全局状态传播。
2. **完成页取消**：CanCancel=false 是确认的状态；外层按钮没有直接 IsEnabled 绑定也是确认的布局事实。样式/父级是否另行限制、点击后是否能关闭须动态核对。现有清理函数不逆写项目，因此不得把 Cancel 宣称为事务撤销。
3. **窗口 X / Esc**：IsCancel=true 与无本类 Closing 钩子可确认；全局窗口样式、WPF系统关闭到 native 缓冲生命周期、再开向导是否影响旧状态仍未解析。未将框架惯例写成原版观察。
4. **反应生成深层**：追到 SmgeHelper→smge.rxninit/gen_rxns_afresh/genrxns、选择/排除与真实写记录；APED 反应遍历的间接函数、完整化学筛选规则、盐/水合物/酸体系与反应系数格式尚未完全反编译。不能宣称已经获得可移植求解器。
5. **错误原子性**：SFE依次写三个阶段，C#无统一事务/finally；底层Cxs/MD服务是否批处理、失败能否保留部分项目数据未知。相同理由不能承诺原版生成中的取消/异常全部回滚。
6. **实现疑点**：SFE最终重复ID循环忽略最后一项；GenerateReaction读取已有key后不逐次刷新；SFE的Loaded会重建固体默认名；GenerateChemHenrySpecs 的某个重名提示格式化了 Henry 名变量。这些为代码事实/疑点，未动态证明所有症状；未来移植不必复制缺陷，应单列兼容性决策。
7. **二级反应编辑器**：已确认具体类型、记录路径和打开事件；其自身所有增删、取消、平衡式校验与保存事务未在本轮展开。
8. **扩展覆盖**：已扩到排序右键、查找双击；其余物性方法、流程图、石油、聚合物、模型页未逐条解析，不以方法可复用冒充全程序已覆盖。

## 原版核对与资产边界

本轮通过 Computer Use 读取了原先打开的 `Simulation 1` 可访问性树：页面包含电解质/SFE按钮，分子结构树已有 WATER/H3O+/OH-。它是既有案例，不能证明本轮新操作效果。为隔离测试调用 launch_app 两次均返回 `GetCursorPos failed: 拒绝访问 (0x80070005)`，未创建新的可操作实例，也没有对现有案例执行成功的点击或输入；没有要求用户逐项操作。完整只读树和失败记录见本地 `runtime-observation.txt`。

既有 O 记录的 WATER 案例仅用于交叉佐证候选反应和提前写入，不替代本轮的取消/X/重名/异常案例。数据库文件清单与安装输入复核、工具检查见 [validation.md](validation.md)。
