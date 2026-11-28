# InfragisticsWPF.Persistence.dll 独立静态复核

本页保留独立复核的结论及可公开的证据链接。本机明细以文字路径标明。原始报告 SHA-256 为 `05fe2f7cd120e4bd7f4aa93189944b692a19c4197b6fa4b6afb0111f4859938a`。

复核员 `/root/reviewer`，制作方 `/root/producer`。复核本任务冻结 ZIP，SHA-256 `daf1136f30311946f905d4932c01e66bd36358d1211066010478f7198403e41c`。独立复核通过。预注册见 [PLAN.md](PLAN.md) 和 [补充计划](PLAN-supplement.md)。满覆盖结论基于本机原件与空目录直接回编输出。

## 来源与归档范围

- 实装文件位于 `C:\Program Files\AspenTech\AprSystem V15.0\GUI\Xeq\InfragisticsWPF.Persistence.dll`，Aspen Plus V15.0，文件和程序集版本 21.2.20212.9，57,384 字节，SHA-256 `dd19c93a74c439a27e214e36e2532b63b7dc5053925b02b80065ff477f84283e`。独立回读仓库固定提交 `adbe73b517acac25da87598cce46de033f630ccb` 的 [静态验收要求](https://github.com/DenseFLoe/Aspen-for-mac/blob/adbe73b517acac25da87598cce46de033f630ccb/docs/static-acceptance.md) 与对象说明。对象的待静态验收状态、原路径和 SHA-256 与任务一致。
- ZIP 118,885 字节，19 成员。CRC 全过，路径安全，无重名，清单 18 项逐文件重算一致。仅见可编辑源码、两项编译资源、程序集公开密钥、构建与证据源码、说明及清单。无原件 PE、已编译目标、回放块、安装包、缓存、凭据或受保护独立资产。[成员指纹](archive-verification.json)
- 核实登记 v9 SHA-256 `bdd0b71b9f5ab031b1a94fd993ab8b4e6441c681ebfbbe155d3aa9bab73f22d8`。源码、两项编译资源和公钥与其对应成员逐字节一致。证据工具中的 `clr_meta.py` 也与 v9 对应文件一致。新包构建入口只读取四项编译输入和显式指定的工具与引用。历史回放数据和结论没有参与本次原件比较。[来源成员](historical-provenance.json)

## 从空目录复跑

在项目根执行。评审实测的解包目录名为 `review/clean`，先检查冻结 ZIP 路径和清单。命令示例使用新目录名，便于再次复跑。构建无需 SDK 或实装 Persistence 原件，后两条比较命令只读原件。

~~~powershell
$task = (Resolve-Path -LiteralPath '.local/codex-router/work/dd19c93a74c439a27e214e36e2532b63b7dc5053925b02b80065ff477f84283e/20261128-b05').Path
$r = Join-Path $task 'review'
$zip = Join-Path $task 'producer/InfragisticsWPF.Persistence.dll.source.zip'
$fx = (Resolve-Path -LiteralPath '.local/batch-roundtrip-20261125/tooling/csharp-reference-packs/references/framework-4.0').Path
$x = 'C:/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq'
$csc = 'C:/lane_dd19c93a/ros-3.4.0/tools/csc.exe'
$clean = Join-Path $r 'repeat-clean'
python -B -m zipfile -e $zip $clean
Push-Location -LiteralPath $clean
python -B .\build.py --csc $csc --framework $fx --infragistics "$x/InfragisticsWPF.dll" --out "$r/repeat-build"
python -B .\build.py --csc $csc --framework $fx --infragistics "$x/InfragisticsWPF.dll" --out "$r/repeat-build-alternate"
python -B .\evidence\compare.py "$x/InfragisticsWPF.Persistence.dll" "$r/repeat-build/InfragisticsWPF.Persistence.dll" "$r/repeat-packaged.json"
Pop-Location
& "$r/inspect.ps1" -Original "$x/InfragisticsWPF.Persistence.dll" -Candidate "$r/repeat-build/InfragisticsWPF.Persistence.dll" -Report "$r/repeat-independent.json"
~~~

Python 3.12.10，PowerShell 7.2.2，Roslyn 3.4.0-beta4-19568-04 (82f2e254)，C# 5，编译器配置要求 .NET Framework 4.7.2 运行时。独立重算 24 个已声明工具文件及外部引用的指纹全一致。引用含 .NET Framework 4.0 的 8 个程序集与版本 21.2.20212.9 的 InfragisticsWPF.dll。编译产生 CS0436，对 `SR` 和 `InternalDynamicResourceString` 选用源码内定义。完整元数据和调用目标实测均与原件一致。两个空输出目录的直接产物完全相同，均为 47,104 字节和 SHA-256 `d6f03f543ce438fb993ae9e2a3837e9a3163bed886df588cf94761252f3979c0`。[工具和依赖指纹](compiler-inputs.json) · 包内比较（本机记录 `package-positive.json`） · 独立输出 A（本机记录 `independent-positive.json`） · 独立输出 B（本机记录 `independent-alternate.json`）

## 独立核验

- 复核代码基于 .NET `PEReader` 与 `MetadataReader`，独立于包内的 Python 解析和输出。直接通过 MethodDef 逐 token 比较调用方签名、形参所有者及标志、完整方法体、指令字节、栈上限、初始化、局部签名和异常区。36 个 TypeDef（含模块）、100 个字段、56 个属性、262 个 Param、232 个 MethodDef、231 个体、29 个异常子句无差异。唯一无体项 `0x06000097` 是 `PropertyPersistenceInfoBase.DoesPropertyMeetCriteria`，抽象声明、RVA 0，两个形参为 `pi` 与 `propertyPath`。
- 逐项解析了 1,086 处 `InlineMethod` 操作数（覆盖调用、构造、函数指针等），令牌和绑定目标一致。独立读取的完整元数据区仅屏蔽 MethodDef 的物理 RVA 和 Module 占用的 MVID 槽，两方 SHA-256 均为 `4f6da76cf478130810c55f7a532c94e4fcb1ede08dd1309f572ebf98f797a181`。签名、属性、程序集引用、声明、方法规范及原始数据堆均受此比较覆盖。
- 两方均为 IL-only PE32/I386，CLI 托管入口令牌 0。 `ImplMap` 行和方法 `PInvokeImpl` 标志各 0。PE 的唯一加载导入是 `mscoree.dll!_CorDllMain`，启动桩指令都为 `FF2500200010`。
- 唯一托管资源 `Infragistics.Persistence.strings.resources` 为 316 字节，解析到一条字符串 `InvalidPersistenceGroupException`，载荷 SHA-256 `569fdd801ba790320bf18a9d9f448928cf043e01ff3b57b6036d4fd0a350870d`。独立递归读取的唯一 Win32 资源叶 type/name/language `16/1/0` 为 1,138 字节，代码页 0，载荷 SHA-256 `c1dedd06890406ea85b79c6a6177b784580b02816e0e779ce4cfe5961f69ced7`。
- WPF 适用项为持久化库的交互。`PersistenceManager::.cctor`（`0x06000050`）在 IL 偏移 310、362、403 三次绑定到 `System.Windows.DependencyProperty::RegisterAttached`（`0x0a000047`），对应 `Settings`、`PersistenceGroup`、`Identifier`。偏移 346 绑定 `PersistenceGroupChanged` 回调（`0x06000055`）。相应方法 `0x06000051`、`0x06000052`、`0x06000053`、`0x06000054`、`0x06000056`、`0x06000057` 的 `GetValue`/`SetValue` 目标一致。四个持久化事件的 add/remove 方法和触发链一致，包括 `SavePropertyPersistence`、`LoadPropertyPersistence`、`PersistenceLoaded`、`PersistenceSaved`。类型及资源目录中没有本件主控件或布局交付的 XAML/BAML；程序集提供 `XmlnsPrefix`、`XmlnsDefinition` 并保留属性树与 `FrameworkElement`、`DataContext` 处理。不存在单独界面布局内容待复建。[独立解析代码](IndependentPersistence.cs) · 逐 token 证据（本机记录 `independent-positive.json`）
- 原件强名区 128 字节且为非零，候选以相同公钥作 public-sign，强名载荷全零。原件有 10,280 字节 Authenticode 目录，候选长 0。两边 CorFlags 均 9。MVID、方法物理布局、COFF 戳、校验和、调试记录随编译而变。静态复核核对的是签名区和构建数据，未执行 Windows 签名或加载行为测试。

## 覆盖控制及差异边界

在初次评审输出目录中运行 `python -B control_inputs.py` 和 `pwsh -NoProfile -File run_controls.ps1`，保持原件固定。控制输入和报告由评审脚本在 `controls/` 下生成。四项各变更直接回编文件中的一个字节，完整变更位置和新指纹见 [控制输入](controls/inputs.json)。包内工具和独立工具均返回预期退出码 1，且始终保留各自报告。

| 反控 | 独立工具实测 | 包内工具实测 |
| --- | --- | --- |
| `0x06000090` 的 `ldc.i4.0` 改为 `ldc.i4.1` | 仅该方法失败 | 仅该方法体失败 |
| 改 `RegisterAttached` 的 MemberRef 名称末字母 | 仅元数据与 `0x06000050` 的调用解析失败 | 仅声明与绑定失败，方法体无差异 |
| 修改托管 `InvalidPersistenceGroupException` 字符串首字母 | 仅托管资源失败 | 仅托管资源失败 |
| 修改 Win32 VERSIONINFO 版本字符串尾数 | 仅 Win32 资源失败 | 仅 Win32 资源失败 |

独立检查确认包内比较针对本件的五个 CLR 流逐字节核对，规范化限于 RVA 和独立 MVID；方法体按各自 RVA 比较头、指令及 EH 区。P/Invoke 计数加完整元数据覆盖该声明类；PE 资源逐叶覆盖身份、代码页及载荷；PE 签名、物理布局差异作为证据列出。该脚本适用于本件的表、流、启动与资源格式，遇到相关不支持结构会退出。用例不推论所有 PE/CLI 变体。主智能体的兼容层保留已固定的 `managed.py` 与验收逻辑，只在临时副本以等价逐段读填和 `ComputeHash(Stream)` 补 PowerShell 7.2.2 的两个 API，静态阅读未见覆盖缩窄。独立结果来自上述不同的解析代码。[控制实测](controls/results.json)

结论为独立静态通过，静态缺口为空。发行商签名策略、Windows 宿主加载及运行行为仍属 Windows 重建对照事项。
