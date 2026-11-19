# Flowsheet 托管代码交接｜20261119-05

**结论：117/117 个 MethodDef 已逐 token 核对；未发现无解释的托管方法体缺失。** 115 项有 IL，另 2 项是原版 COM 接口中的无体声明。本结论是该 DLL 的托管代码证据，不是整文件、Windows 重建、原版宿主交互或 Mac 验收；不修改上级归档或台账。

## 从哪里查

- **主表 `methods.tsv`**：按原始 MethodDef 行号排序；类型、签名 blob、实现类别、RVA、代码字节数/指令数、分支、异常区、SHA-256、两个 IL 位置及三个 C# 位置/映射类别。行号从 1 开始、首尾都计入。直接看某一方法优先打开 `token-source.cs` 对应段；看全类上下文用 `readable.cs`；追编译器生成逻辑用 `expanded.cs`。
- `raw.il` 为逐 token 带原始指令字节的 IL；`structured.il` 为结构化 IL。 `coverage.json` 含原始 flags、实现 flags、方法体/代码指纹、CLR locals、maxstack、逐分支及 EH 区间（起点含、终点不含）。`branch-targets.tsv` 列全部跳转和条件顺落，`operand-tokens.tsv` 从方法和 IL 偏移定位元数据/字符串操作数。
- `types.json` 保留基类、嵌套、接口、字段及方法归属；`contracts.json` 是 .NET Framework 只反射读取结果；`references.json` 汇合原始引用与 CLR 解析身份；`boundaries.json` 定位 COM、三个 XAML 引用、卫星候选与被折叠的方法。`summary.json` 是机械核对统计，`method-tokens.tsv` 是补充普通 C# 折叠上下文前的中间表；以 `methods.tsv` 交接。
- `02-incomplete/` 只存**待整体验收的本地交接副本**（普通 C#、原始 IL、展开 C#、逐令牌 C#、主表及各自同名说明）。不代替主智能体签收。辅助证据和可复查脚本同在本目录；`manifest.json` 含除清单自身外全部交接文件的字节数、SHA-256。

## 身份和计数

Plus 原包成员、Properties 原包成员和指定安装件逐字节相等，均为 42,024 字节；文件及程序集版本 `41.0.0.614`，SHA-256 `aba9d5c58c1cbe4d0ee5584ea7c36ee8dd8be4196816c919151895adfe8b2bac`，MVID `b4439948-8ea6-4b80-b59f-afbd9ee68c09`。输入采用 Plus 成员。冻结清单指纹、CAB 路径/成员名、7-Zip 命令见 `identity.json`。上轮的“42”是按名称去重的选择，不作为覆盖率分母。

| 核对项 | 结果 |
|---|---|
| 定义 | 15 TypeDef（14 个类型，另 1 个为无方法的模块占位）、57 字段、37 属性、43 个方法语义关联、8 个接口实现行、10 个 MethodImpl 行 |
| 物理实现 | 115 个有体 token，109 个不同 RVA；4 组共享 RVA。按方法逐行合计 2,245 条指令、6,798 字节；按 RVA 去重 2,229 条、6,762 字节。不以地址或名称替代 token |
| 控制流 | 49 个方法共 149 条显式跳转指令，其中 3 条 switch；157 个显式目标、116 条条件顺落。全部对照原始操作数字节及指令边界。6 个 finally，0 个 catch/filter/fault；原始 EH、IL 区间、CLR 三方一致 |
| 可读源 | 独立按 EntityHandle 输出 117 段（115 个有体函数的序列点记录，2 个无体声明）；普通、展开和逐 token 导出均 0 条方法级反编译警告。独立片段和展开 C# 用于核查，不是可编译工程或厂家原稿 |
| 外部静态引用 | 14/14 个 AssemblyRef 的本机完整身份匹配（含版本、文化和公钥标记）；154/154 TypeRef、19/19 TypeSpec、238/238 MemberRef 通过 CLR 解析，无替换泛型槽；209 个不同 MemberRef 在指令操作数中实际出现。类型引用无未解；这不是调用成功的证据 |

## 容易误判的地方

- `0x06000041` 是导入接口 `IHNode._VtblGap1_51` 的虚表占位，RVA=0，runtime managed。CLR ResolveMember 不将其作为可调用方法返回（本次唯一 MethodDef 查询错误）；原始元数据、token IL 和 C# 声明都在。`0x06000042` 是 `IHNode.Export` 的 runtime managed internalcall，RVA=0，参数为可选 BSTR、默认空串，DispId 1610743859。二者均非反编译失败。`0x06000036` 先 InvokeAction("Top.appModelV8.Custom Actions","HappNode",...)，仅在成功且返回 IHNode 时将空串传入 Export；实际 COM 服务、导出对话框、文件效果不在本 DLL 的 IL 内，也未运行。
- `0x06000039`（选择变化回调）和 `0x0600006f`（迭代器 Dispose）的原体都是单条 ret，共用 RVA；不是丢失的空实现。`0x06000072` 的 Reset 原本就是 newobj NotSupportedException 后 throw。展开视图的 IEnumerator.MoveNext 转发是 ILSpy 根据 override 合成，不能计为第 118 个 MethodDef。
- 7 个静态构造在整类视图折入 19 个字段初始化，逐个按 stsfld 的 token 和顺序核对；7 个隐式默认构造只调基类；另有 `0x0600006c` 先把 string.Empty 写入 _recType 再调基类，不能当空构造。单方法 C# 的 base..ctor() 一类写法反映展开形式，以 IL 为准。
- 普通 C# 将 `0x0600005d`、`0x06000063` 内联为两个 Dispatcher 委托；父方法各自在 IL_0058 用 ldftn 指到各自 token。8 个迭代器成员在普通 C# 中折叠为 GetSelectedIds 的 yield，普通视图的工厂序列点可达 157 字节，而实际工厂仅 15 字节；157 字节属于 `0x06000070 MoveNext`，不能拿工厂偏移验证它。逐 token 和展开视图分别保留八个方法的实际体。
- 业务分支示例：`0x06000016/17` 检查块 ID 和流股 ID 时分别查询对方集合；输入或返回集合为空时放行。`0x06000018` 对 null 放行、对非字符串及末尾为 `$(IN)` 或 `$(OUT)` 的字符串返回 false。两个延期回调检查的是带美元符的结尾，写入却拼接 `(IN)` / `(OUT)`，不要自行“纠正”。`0x06000013/2d/2e/2f/30/36` 的 finally 用于枚举清理，并非捕获业务异常。

## 缺口与恢复条件

1. 三个 InitializeComponent 携带不同资源 URI；主 DLL 的 CLR 资源目录 RVA/size 均为 0、无 ManifestResource 行。同目录 en-US 卫星 `AspenTech.AspenPlus.MMForms.Flowsheet.resources.dll` 已定位并记录指纹；本代码分工未据此认定三个 BAML、资源回退和连接 ID 已验收。整文件签收前需对接独立资源证据。
2. 只确认了 CxsViewModel/provider、MMControls、Infragistics、定位/消息框、WPF Dispatcher 与 COM 等静态签名和调用点。真实模型数据、UI 生命周期、资源加载顺序、宿主动作和 COM 服务返回值/副作用均未在本分工观察。需要这些结论时应对接相应资源、探针或宿主证据；不将外部实现误记成本 DLL 缺失方法。
3. 所有推断只限于原 IL 能支持的范围。没有重建，没有运行产品代码，没有提交、上传或写入指定目录以外的位置。此包不发布任何整文件完成状态。

## 复查方式

计划先于解包，身份先于导出。使用仓库根当前目录，脚本绝不覆盖已有输出。原证据应只读；若需重导，由获授权的操作者另建同层全新工作目录，复制 plan 与脚本、在新计划声明新目录，保留计划所指的历轮工具。依次运行：

1. 用 `.local-tools/research/venv/Scripts/python.exe -B` 运行 `acquire.py`。7-Zip 26.06 只用 e -so 从两个 CAB 取指定成员。
2. 用 PowerShell 7.6.9 运行 `export.ps1`、`token-source.ps1`。ILSpy 9.1.0.7988；搜索路径和库指纹见 `export.json`。
3. 用 Windows PowerShell 5.1（-NoProfile -NonInteractive -File）运行 `contracts.ps1`。只用 ReflectionOnly 上下文，精确身份，未调用目标方法。
4. 用上述 Python（-B）依次运行 `audit.py`、`handoff.py`、`seal-code.py`。dnfile 0.18.0 / dncil 1.0.2 独立解析原始 PE，CLR 再对照 IL 字节指纹、局部变量初始化标志、栈深及 EH。`verify.py` 为纯只读复核入口，可直接在现有证据上运行。
