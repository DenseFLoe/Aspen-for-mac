# WpfPLRPlug.dll

| 项目 | 值 |
| --- | --- |
| 产品 | Plus / Properties，Aspen V15.0 共用 AprSystem |
| 原相对路径 | `[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLRPlug.dll` |
| 原件文件和程序集版本 | `41.0.0.614` |
| 原件 SHA-256 | `f706516819aa7da442d9080aa6eb8a49da9f92ed0d132fd67278b60dd0ce4c3c` |
| 锁定标准 | GitHub `main` 提交 `ba0c945804c33338edfb24d193b20f10d35186f5` 的《静态验收要求》和《逐文件逆向详细规则》 |
| 本包状态 | 制作阶段静态对照通过，待独立复核和总控复跑 |
| 独立 C# 构建产物 SHA-256 | `2a37eb5fde969850b2262d0cf15055a65d95ea66b5442822e63bd4cc09d6d8ad` |
| 成果源码 SHA-256 | `e5baee78c03fb5b5d84f17532974b8b90ca91171576b0b32ca172d72a3d33dee` |

本 ZIP 的解压根对应原件对象目录。整件通过登记后的归档相对目录为 `01-completed/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLRPlug.dll/`。`SHA256SUMS.txt` 逐件记录包内成员指纹，清单自身由外部 ZIP 指纹覆盖。

## 来源与源码修订

`WpfPLRPlug.dll.cs` 由夜班已移交的 `n-f706-c/pkg3` 中 12 个源码单元合并。已逐文件核对 `n-f706-b/WpfPLRPlug.dll.exact.zip` 的源码成员，12 个成员的字节均相同。合并沿用每个命名空间块的 using 范围和源码的类型顺序。此前本机记录中 Roslyn 新版本的项目有 COM 互操作类型和符号差异。现使用 Roslyn 3.8.0、C# 9、优化、17 个经指纹校验的引用，使用 `/link` 嵌入 `Interop.Happ.dll` 所需的 COM 声明。

原样合并后直接编译的 SHA-256 为 `cf376a0980225736fa3aa54c65ab09040b154a809d743c682a311fb2abe92376`，与夜班 `pkg3` 直接输出相符。逐项对照发现 `PropSet.PropertyList` 的自动属性后备字段的位置变化，以及 `PropSet.CancelCommand` 生成的委托形参由原件的 `dr` 变为编译器合成的 `<p0>`。本包通过移动自动属性声明和使用显式 `delegate(object dr)` 恢复两处结构。

夜班另一个报告 `n-f706-b/REPORT.md` 和 `REPRO-EVIDENCE.json` 记录中间产物 SHA-256 `120251cfb7efd578f4990203d693940087d92e7f0c93f9e5b0011d7eb9365ee5`。夜班的两份布局配方将独立编译的 387 个方法体迁移至原 RVA，并重绑定 CIL、局部签名和异常捕获类型令牌，随后回放原件 CLR 元数据流、调试记录、PE 布局及证书。该历史路线得到整件原件指纹。当前 `build.py` 直接调用编译器生成 PE。它使用下文记录的原件提取资源数据；所有 CIL、CLR 元数据及 PE 布局均由编译器生成。归档包含源码、资源和核验脚本，布局配方及原件二进制位于历史输入路径。

## 代码与元数据覆盖

- 458/458 MethodDef 定义、387/387 有体方法、71 条原件无 CIL 体的声明。后者均在 5 个带 Import 标志的 COM 接口中，包含 39 条 abstract/runtime 访问器、7 条 abstract/runtime 普通声明及 25 条 Runtime `_VtblGap` 槽位占位。逐接口核对 MethodDef 和 gap 的顺序。
- 387 个方法体的操作码、非令牌操作数、分支、栈上限、局部签名和初始化标志全部匹配，19 条异常子句的范围、种类和绑定全部匹配。5766 个 CIL 令牌操作数按调用或引用的实际符号解析，其中 4588 个原始数值重编号。
- 直接以生成名称对齐时严格匹配 446 个定义。7 个具名方法的符号体包含重编号的生成成员，另外 5 个 lambda 的生成名称改变。以相同方法内相同指令位置支持的 141 次引用核对创建双射，覆盖 3 个生成类型、36 个生成字段和 5 个生成方法。逐个核对生成声明的标志、完整签名、所有被引用位置、方法体和单向反查，证据包含原件令牌与候选令牌。业务名称和字符串按实际值核对。
- 另核对 23 个类型、288 个字段、130 个属性、180 个显式覆盖和 15 项 AssemblyRef。AssemblyDef 全属性、类型结构、接口列表、构造和参数元数据均对得上。`evidence/CIL-PE-COMPARISON.json` 保存逐方法记录、原始与重编号的绑定及元数据范围。

## 资源和 WPF 覆盖

- 本 DLL 的 9 条公开托管资源分别为 8 个 ICO 和 1 个原始 `RPlugpwr.txt`。包内资源为原件提取字节，普通 C# 编译将其嵌入；每个资源的清单名、可见性、长度及 SHA-256 均与原件一致，36336 B CLR 资源区也逐字相同。
- `resources/WpfPLRPlug.win32.res` 为从原件导出的 Win32 资源输入，以 `/win32res` 嵌入；双方 PE 唯一 Win32 叶项均为 `VERSIONINFO`，键 `16/1/0`，938 B，SHA-256 `1078636ee31cb4748560578d88d52379ce1fc7290d66481c89acd332bc0fae7b`。
- 中性语言是 `en-US`，回落目标是卫星程序集。同目录下 `en-US/WpfPLRPlug.resources.dll` 是独立的运行依赖，也是本包静态 XAML 核验的只读输入。实测版本 `41.0.0.614`，大小 45096 B，SHA-256 `1719dbc432d68cfe08037fe43440f8d68a7f0b6e442a5df66d3002d994b3fc3c`。
- 卫星的 `WpfPLRPlug.g.en-US.resources` 包含 8 个 BAML 页面。静态读取各 BAML，同时分别用原件和独立编译产物的元数据及连接代码生成 XAML，三方页面与 `wpf/` 中可编辑的 8 个 XAML 全部逐字一致。每页核对 `x:Class`、pack URI、初始化连接及处理器，记录 51 个命名控件、18 个事件连接、10 个数据绑定表达式和 16 个命令属性。`evidence/WPF-LAYOUT.json` 记录各页 BAML 和 XAML 指纹及清单。
- XAML 是从卫星 BAML 展开的布局证据。归档只保留 XAML，既有卫星和其 BAML 由外部路径读取。当前主 DLL 构建重建自身界面代码和绑定，不编译 XAML 或重新生成卫星。更改 XAML 后需在后续重建阶段另行构建卫星，并用相同界面场景核对。

## 签名和构建信息

| 项目 | 原件 | 独立编译 |
| --- | --- | --- |
| PE 文件大小 | 129064 B | 118784 B |
| CLR / 处理器字段 | I386，ILOnly | I386，ILOnly |
| CLR 强名称 | 0 B | 0 B |
| Authenticode 证书表 | 10280 B | 0 B |
| 调试目录 | CodeView，284 B | Reproducible，0 B |
| MVID | `33f5594c-b36a-491d-b33a-c30a4d275e57` | `5a32bdf0-5f46-4765-b696-5c1de94ab289` |
| PE 校验和 | 133501 | 0 |

其余构建差异包括 COFF 时间戳和令牌或数据的排布。原件签名表的 SHA-256 为 `abda226ea7aff00a46cdb905bc2a8861ce80d3a13aa98f4f22089c7644cf41f6`。`build.py` 产出的 DLL 是独立无 Authenticode 构建。实际启动、卫星装载和界面交互留到 Windows 重建及对照阶段。

## 在新目录复跑

解压 ZIP 到空目录，并在该解压根运行。编译需要 Windows、Python 3.12、Roslyn 3.8.0 `csc.exe` 及其同目录运行依赖、.NET Framework 4.8 引用程序集、Aspen V15.0 `AprSystem V15.0/GUI/Xeq` 安装目录。Roslyn 使用 Microsoft.Net.Compilers 3.8.0 包的 `tools/csc.exe`，版本 `3.8.0-5.20562.2`。.NET Framework 引用来自 `Microsoft.NETFramework.ReferenceAssemblies.net48` 1.0.3 的 `build/.NETFramework/v4.8`。所有编译依赖的路径和指纹列在 `build-inputs.json`。核对引用文件存在且指纹匹配后执行。

```powershell
py -3 -B .\build.py --csc $csc --framework $framework --xeq $xeq --out .\out\source
```

预期输出为 `out/source/WpfPLRPlug.dll`，指纹见首页。编译步骤只依赖源码包及所列编译工具和引用。静态复核另需现场原件、卫星和工具，以 `-B` 运行。

```powershell
$original = Join-Path $xeq 'WpfPlotWizards\WpfPLRPlug.dll'
$satellite = Join-Path $xeq 'WpfPlotWizards\en-US\WpfPLRPlug.resources.dll'
py -3 -B .\audit.py --original $original --candidate .\out\source\WpfPLRPlug.dll --satellite $satellite --dotnet-root $dotnet9 --ilspy $ilspy9 --framework $framework --xeq $xeq --out .\out\audit
```

`$dotnet9` 指向具有 SDK 9.0.321 和 `Microsoft.NETCore.App.Ref` 9.0.23 的私有或系统 .NET 根目录。`$ilspy9` 指向 ILSpy 9.1.0.7988 x64 二进制 ZIP 的解压目录，脚本固定检查 `ICSharpCode.Decompiler.dll` 和 `ICSharpCode.BamlDecompiler.dll` 指纹。项目现有的 CIL 元数据读取代码只在本包证据工具内复制并增补结构比较与 PE 资源描述。[ILSpy 9.1 官方发行版](https://github.com/icsharpcode/ILSpy/releases/tag/v9.1)

成功时退出 0，在 `out/audit/` 生成 `CIL-PE-COMPARISON.json`、`WPF-LAYOUT.json` 和每端 BAML 枚举与 XAML。对照控制记录见 `evidence/NEGATIVE-CONTROL.json`。

## 本批验收结论

从可编辑 C# 和提取的资源直接回编，核对 458 项方法定义、387 个 CIL 方法体、71 个 COM 声明、19 个异常子句及 8 个 WPF 页面。现有英语卫星程序集用于界面对照，独立编译产物未签名。

[独立复核](evidence/independent-review.md) · [总控复跑](evidence/controller-receipt.json)
