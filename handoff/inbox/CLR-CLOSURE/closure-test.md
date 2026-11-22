# CLR 引用闭包配对构建

2026-11-22 在 Windows Server 2022 x64 对三个不同 SHA-256 的原件做了配对实验。仅使用框架引用时通过 0/3；向同一份源码添加依赖图中已解析的产品与第三方引用后通过 1/3。HybridModelUtilities 的 Release DLL 已实际生成。三件合计编译错误由 834 条降至 5 条。三个样本按大小和依赖特征选取，不能据此估算全库通过率。

| 原始 DLL（均省略 AspenTech.AspenPlus. 前缀） | 字节 | 源文件 / 其他导出文件 | 直接引用边 | 加入的闭包 DLL 数 | 加入前：退出码 / 错误 | 加入后：退出码 / 错误 |
|---|---:|---:|---:|---:|---:|---:|
| Engine.Structures.dll | 1,385,512 | 381 / 0 | 4 | 12 | 1 / 539 | 1 / 2 |
| HybridModelUtilities.dll | 55,336 | 4 / 2 | 4 | 7 | 1 / 10 | 0 / 0 |
| CustomModels.dll | 634,408 | 129 / 96 | 31 | 62 | 1 / 285 | 1 / 3 |

原路径、产品归属、版本及原件 SHA-256 见 `closure.json` 节点 73、437、435。`build-results.csv` 给出原件、C# 文件集和其余资源文件集的指纹。文件集指纹为按相对路径排序的 UTF-8 清单的 SHA-256，每行采用 `路径<TAB>小写文件SHA-256<LF>`。六个 `*.before.txt` 和 `*.after.txt` 文件保留全部错误和警告，按文本排序并将随机工作路径替换为 `<sample>`。`build-diagnostics.json` 按代码汇总。计数取 MSBuild 单次 NoSummary 输出的 error 行，不含 warning，也不重复计算末尾摘要。

## 错误及缺失输入

- Engine.Structures 的直接产品引用是 `AspenTech.NGP.Infrastructure`。加入 12 件可达依赖后，原先涉及 `AspenTech.NGP.Infrastructure`、`ILazyFactory<,>` 等的报错消失。剩余两条 CS0234 在同一个 `Properties/AssemblyInfo.cs` 特性处，分别指向 `RefSafetyRulesAttribute` 和 `RefSafetyRules`。下一步要从原件的 CustomAttribute / TypeDef 核对 ILSpy 导出的模块级特性及定义。
- HybridModelUtilities 的直接产品引用是 `ModelEquations`。加入七件可达依赖后通过编译，有三条局部变量未使用警告。试配环境时，遗漏 net48 包自带的 `Facades/netstandard.dll` 曾导致 159 条 CS0012，要求 `netstandard, Version=2.0.0.0, PublicKeyToken=cc7b13ffcd2ddd51`。表内两组均已固定这个框架输入。
- CustomModels 的直接引用共有 31 条，产品库内 13 条可唯一解析，另有 5 条同身份多内容、13 条无库内候选。补引用后只余三条 CS0596，分别出现在 `_DACMDocomentWrapperEvents_Event`、`ApplicationEvents4_Event`、`DocumentEvents2_Event` 的 `ComImport` 声明。需要按原元数据或匹配的 COM 类型库核对 Guid，再处理源级声明。此次未手改声明或生成占位 GUID。
- 每件全部未解析边号均在 `closure.json` 对应根的 `unresolved` 中。三根分别有 31、21、523 条传递未解析边，含重复使用同一身份的不同引用者。CustomModels 的传递链中，库内缺少 `ASCClassLib380 38.0.0.0` 和 `Microsoft.IdentityModel.Tokens 6.7.1.0` 的同名候选；`Xceed.FileSystem` 与 `Xceed.Zip` 的 3.6.7614.12380 版本存在同身份多内容。部分直接歧义所涉及的名称也可由其他引用者沿唯一边到达。编译器看到了这些可达 DLL，不能据此裁定原调用者会装载哪一份。独立的框架包提供 MSBuild 所需的框架程序集，图中保留各边在产品库内的原始状态。

## 配对设置

每件先按清单 SHA-256 定位原件和闭包，将原件隔离到独立目录，在同一组已解析 DLL 的辅助下用 ILSpy `-p -r` 导出一次。然后把这个导出目录复制到两个全新的工程目录，校验两份 C# 文件集指纹。两边均使用 Windows x64 SDK 8.0.100、net48、ILSpy 生成的 C# 12.0、Release、原工程平台目标及原嵌入资源设置。未修改 C# 源码；显式关闭签名以及 SDK 自动生成 TargetFrameworkAttribute。ILSpy 已关闭自动生成 AssemblyInfo。两边均清理导出工程指向安装目录的 HintPath，仅允许 HintPath 和目标框架目录解析，使用相同的直接框架引用和 netstandard facade，禁用共享编译器并清空 NuGet 源。唯一分组差异是 after 工程增加由 `reachable` 所列、排除本件的显式 Reference/HintPath。两侧使用相同的 SDK 和 NuGet 配置做独立 restore/build。

这些构建只检查固定输入下 C# 工程能否生成程序集。运行行为、签名、公钥、逐方法 IL、BAML 可编辑性、Windows 实机及静态验收需各自核验。

## 后续路径及代价

1. 用真实原件作编译期引用。该路径已实测，每件临时准备 7 至 62 份校验过的引用即可直接比较错误。三个样本的引用副本分别为 2,971,840、1,461,184、87,577,912 字节。它依赖同版本二进制和框架包；同身份异内容仍需逐调用方消歧，无法由一次成功构建决定发布或装载版本。
2. 在相同闭包上按依赖顺序修复、回编并逐件换成 ProjectReference。可以从已过编译的 HybridModelUtilities 着手，但先要核对其 7 个可达依赖及构建签名。对 CustomModels，仅本次已解析范围便有 62 个依赖，此外还要恢复 COM 声明、核查未解析边并验证每个替换件。此方案有更高的人力与复验成本，本轮未实施。
3. 仅为定位类型错误，可从同版本元数据或类型库生成引用程序集。需要保留成员签名、泛型约束、转发与互操作特性，对每个替代件记录来源。这条路径适合缺少可用目标框架或编译引用的诊断；可执行实现、原件级验证仍需单独取得。表内未使用桩。

## 复跑

在本目录运行 `paired-build.py`；需要 Windows、Python 3.11+（实测 3.12.14）、`pwsh` 7 和同版本安装或原版介质。先按 `scan.md` 的固定提交下载 `plus.csv`、`properties.csv`、`shared.csv` 至同一目录。脚本会检查三张清单的指纹，读取本目录的 `closure.json` 和 `assemblyrefs.csv`，并对每个实际使用的原件做哈希校验。

将下列固定版本下载并分别解压至专用工作目录。括号为本轮实测下载文件的 SHA-256。

- [.NET SDK 8.0.100 win-x64 ZIP](https://dotnetcli.blob.core.windows.net/dotnet/Sdk/8.0.100/dotnet-sdk-8.0.100-win-x64.zip)（`fc225bcce6b54385580a16216e484b6119452ff6febac7da4e2a7e1fdee09921`）
- [ilspycmd 9.1.0.7988 NuGet](https://api.nuget.org/v3-flatcontainer/ilspycmd/9.1.0.7988/ilspycmd.9.1.0.7988.nupkg)（`2b5058f5ccc164c33b7aabf1a5eb0cf3d3a6af6c145aaf58efd3ed891443af7c`）
- [Microsoft.NETFramework.ReferenceAssemblies.net48 1.0.3 NuGet](https://api.nuget.org/v3-flatcontainer/microsoft.netframework.referenceassemblies.net48/1.0.3/microsoft.netframework.referenceassemblies.net48.1.0.3.nupkg)（`8a7e348538e7eb91351696911689f49e3d4f63f8bab517432bbe159b8b1104a2`）

以下示例在 PowerShell 中执行，`$kit` 指向上述 SDK、ILSpy、参考包和三张清单的本地父目录。SDK 解压目录命名为 `sdk`、ILSpy 为 `il`、参考包为 `ref48`。输出目录可另选。若原版介质已迁移，可另传 `--media-dir`（用法同扫描器）。

```powershell
$kit = 'C:\work\clr-tools'
$run = Join-Path $env:TEMP ("aspen-clr-" + [guid]::NewGuid())
python -B .\paired-build.py --dotnet "$kit\sdk\dotnet.exe" --ilspy "$kit\il\tools\net8.0\any\ilspycmd.dll" --refroot "$kit\ref48\build" --inventory-dir "$kit\inventories" --out "$run\results" --work-dir "$run\projects"
```

`--work-dir` 必须是新路径。指定它可保留每件的 `before/` 和 `after/` 源码工程、`refs/`、原始构建日志及成功生成的 DLL，供本机复核。省略时，仅保留 `--out` 中的数据表和诊断，临时原件、源码与产物在实验结束时清理。

已另用全新工作路径复跑。两次最终实验的 `build-results.csv` 均为 SHA-256 `64c29fdaf0b29b4d69c0d15e891f06ddcf99f12191645e6d9f68ae94bcafa2c5`，包括原件、源码与资源指纹、六次退出码和错误数。保留工程的复跑也核对了六份原始日志及 HybridModelUtilities 的目标 DLL；再次指定已有的工作目录退出 1。
