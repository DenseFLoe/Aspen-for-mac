# Aspen V15 操作逻辑分析（仅分析）

本轮基于 `codex/ui-operation-parity@3f17bdb`，工作分支 `codex/wizard-logic-analysis`。2026-11-15 通过 GitHub 连接器读取默认分支 `main@9745ff58f995e60e2d351ec745ba8fe8e4311352` 与 AGENTS.md；本地包含 main 及上一轮向导 UI 改动。CLI fetch 在关闭凭据交互后明确报未配置用户名，远端核对使用连接器完成。没有更改默认分支。

本轮范围：电解质、SFE 两条主操作链；复用方法扩展到组分查找双击与组分右键排序。只新增本目录的分析工具和报告，不修改 `src/`、`ui/`、项目格式或计算实现。当前阶段 0–2 的实现状态不变，不将分析成果记为业务验收。

- [操作对应表与移植差异](report.md)
- [文件 SHA-256、方法 Token/RVA 与原生函数区间](evidence-index.json)
- [复现与证据检查结果](validation.md)
- [只读分析器](inspect_logic.py)：提取 CLR 方法位置、IL 调用/分支、x64 导出与内部函数的反汇编、导入跳板与字符串引用；处理 `.pdata` 的 CHAININFO，避免漏掉函数后半段。
- [证据检查器](verify_evidence.py)：检查实际扫描结果、关键调用顺序、原生函数链与输入文件哈希。
- [完整复现入口](reproduce.py)：核对索引中安装文件的哈希，重新提取全部选定方法和原生函数，再执行证据检查。

## 本地证据

`.local/wizard-logic-analysis-20261115/` 保存完整反编译、IL、原生反汇编和原版只读观察。它与受保护的 `.local/property-database/` 完全分开。二进制输入仍在原安装位置；数据库导出、归档、原安装文件和既有分析结果均不覆盖。完整厂商代码、输入二进制、工具和数据库不加入 Git。

最终脚本复跑的 IL/原生证据在 `.local/wizard-logic-analysis-20261115-final/`；索引指向该目录。IL 指令及跳转目标都已归一为方法代码起点的偏移；初次扫描保留供追溯。

本轮复用 `ui/recovered/` 和 `.local/ui-scan/results/`；不重新解包安装介质。程序集从安装目录只读解析，没有通过反射执行原版程序集，也没有修改原版进程内存。

## 可复用分析方法

1. 从布局 `Name/VariablePath/Command` 和生成的 `IComponentConnector.Connect` 找实际绑定；不要用按钮文字猜函数。
2. 解析 ViewModel 的命令 getter、执行委托、状态属性初始化，分别记录“禁用”与“可点击但检查失败”。记录继承状态尚未追踪的边界。
3. 追踪 `InvokeAction` 字符串到原生字符串分派、导入函数、COM 调用名，再追到托管窗口/页面。记录被动返回值是否真的上传到调用者。
4. 对每页检查 Loaded、OnEnter、OnForward、OnBackward、OnFinished，随后读向导框架本身。不能假定 Finish 只调用当前页。
5. 将 UI 临时集合、原生候选缓冲、项目记录、持久化文件分开。追到 Set/AddChild/写记录函数，列出真实路径或原生字段名。
6. 托管包装器不是分析终点：确认混合模式 native stub 的 IAT 目标，分析原生导出；读 `.pdata` 链式 unwind 分段和跳板，保留未解析虚调用。
7. 以相同命令对象/同一处理函数证明按钮、右键、双击等价。未找到快捷键声明不等于证明快捷键不存在。
8. 只为静态仍不能确定的行为构造临时原版案例，记录前后项目差异。本轮输入自动化被系统拒绝，未取得新的动态通过证据。

## 复现

Python 3.12；`dnfile 0.18.0`、`dncil 1.0.2`、`pefile 2024.8.26`、`capstone 5.0.9`。阅读 C# 使用 [ILSpy 官方项目](https://github.com/icsharpcode/ILSpy) 的 ilspycmd 9.1.0.7988（匹配本机 .NET 8）；下载包 SHA-256 为 `2b5058f5ccc164c33b7aabf1a5eb0cf3d3a6af6c145aaf58efd3ed891443af7c`。工具仅存 `.local-tools/research/`。

每次复现选一个**不存在**的新输出目录；工具拒绝覆盖，并只接受本仓库 `.local/wizard-logic-analysis-*` 下的目录。以下示例可独立运行：

完整复现本报告的选定范围：

```powershell
& .local-tools/research/venv/Scripts/python.exe analysis/wizard-logic-20261115/reproduce.py --out .local/wizard-logic-analysis-repeat-all
```

新增模块时使用底层分析器指定新的类、方法或原生入口：

```powershell
$py = '.local-tools/research/venv/Scripts/python.exe'
$gui = 'C:/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq'
& $py analysis/wizard-logic-20261115/inspect_logic.py managed "$gui/AspenTech.AspenPlus.WpfFindComponent.dll" --match 'ElectrolyteForm|ElecWizardMain|SFEAssistant|SFEComponentData|FindComponentDriver::Show(Elec|SFE)|ReorderComp::|CompoundsTab::ListViewItem_MouseDoubleClick' --out .local/wizard-logic-analysis-repeat/managed-findcomponent
& $py analysis/wizard-logic-20261115/inspect_logic.py native "$gui/smge.dll" --match '^(write_chem_record|write_hcomp_record|write_new_base_comps|set_global_opset|gen_rxns_afresh|genrxns|rxninit|clear_alloced_rxn_space|get_base_comps|has_chem_record|has_hcomp_record|exclude_aq|exclude_salt|rem_rxns|sub_)' --entry 0x1d42f0 --entry 0x1d08d0 --out .local/wizard-logic-analysis-repeat/native-smge-v2
```

地址只适用于 `evidence-index.json` 中相同哈希的 V15 文件，不能套用其他补丁版。反汇编字符串是候选证据，需要结合参数和调用点阅读；线性扫描、间接虚调用、未展开的子函数不能当成完整算法证明。原始第一次 native 扫描没有合并 CHAININFO，已被 `native-smge-v2` 取代，报告只采用修正后的结果。

可选 C# 阅读（输出也使用新目录）：

```powershell
dotnet .local-tools/research/ilspycmd-9.1/tools/net8.0/any/ilspycmd.dll "$gui/AspenTech.AspenPlus.WpfFindComponent.dll" -o .local/wizard-logic-analysis-repeat/decompiled
```

反编译文本有部分引用未解析警告，因此关键调用及分支另外用 dncil 读取原始 IL 交叉核对；C# 行号只用于阅读，稳定定位使用程序集哈希 + MethodDef Token + RVA + IL offset。
