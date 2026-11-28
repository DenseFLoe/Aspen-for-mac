# WpfPLData.dll

Aspen Plus / Aspen Properties V15.0 共用主组件。安装相对路径为 `[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLData.dll`。文件及程序集版本均为 41.0.0.614，程序集文化声明为 neutral，无强名称公钥。现场原件 111,144 B，SHA-256 为 `bf01baee83399cfdd4c3e67e965c4fced8bbb17ae83b892abcf14648a64996f7`。固定 main 基线 `ba0c945804c33338edfb24d193b20f10d35186f5` 中，本件位于 `逆向成果/待静态验收/Plus/` 下的同一原件目录。

本包是送独立复核的 IL 源码候选 v5，沿用 v4 的目标 IL、资源与静态证据。辅助工具 OperandDump 改用归档 C# 源码现场构建，Mono.Cecil 由显式外部路径输入，pefile 与 ordlookup 采用上游版本源码。可编辑来源为 `editable/WpfPLData.dll.il`，由历史 v2 原样复用（历史 ZIP SHA-256 `305217b5055a3d7fbdc983e49fed3a34148393356e6ca6b73947011a63dd0b17`，IL 由 ildasm 9.0.23 导出）。单件源码采用 CIL。包内包含十项中性程序集的托管资源、Win32 `.res`，以及单列的 en-US 界面资源。包内逐成员指纹见 `SHA256SUMS.json`。

## 静态比较覆盖

- 现场原件和未进行令牌或方法头修补的 ILAsm 产物均有 211 个 MethodDef，其中 145 个有体、66 个无体。以 Mono.Cecil 比较全部指令、控制流目标及指令操作数解析（包括其引用的作用域和签名），145/145 方法相等。4014 个可解析令牌操作数的 kind、指令宽度和符号键逐位置一致。7 项异常区的种类、catch 类型及处理范围相等。23 TypeDef、175 Field、65 Property、13 AssemblyRef 和 0 EventDef 的比较记录见 `evidence/coverage.json`。
- 66 个无体声明中，20 个 COM `_VtblGap*` 的 ILAsm 标志增加 `Virtual | Abstract`，`MethodDef.Flags` 从 `0x1806` 变成 `0x1C46`。另有两个无体 COM 属性 setter `IHPlotVal::set_XData`（`0x060000B7`）和 `set_YData`（`0x060000B9`），第 4 个参数名从空变成 `A_4`，参数标志、类型和 MarshalInfo 均匹配。证据记录列明 22 个令牌和所属签名。最终件的这些声明直接采用原件 CLR 元数据。原件另有程序集级 `DebuggableAttribute(DebuggingModes.IgnoreSymbolStoreSequencePoints)`（属性 blob 为 `0100020000000000`）。该属性在归档 IL 第 101 行为注释，原始 ILAsm 产物缺失此属性，最终由原件 CLR 元数据回放恢复。
- 未修改 ILAsm 产物的 `InitLocals` 在 `0x06000037`、`0x06000063`、`0x06000085`、`0x06000086` 四处未置位。构建入口读取现场原件逐项恢复该位，并按原件同位置校验四字节令牌槽。实测变动 1,710 个值，其中 1,704 个是 CIL 操作数、6 个是异常捕获类型令牌。局部变量签名令牌也逐项核对，本件无须改值。之后逐 MethodDef 验证 145/145 个完整方法体的字节。物理正文是 123 个不同 RVA，其中 5 组共享 RVA，22 个冗余行别名对应 82 B；按实际方法范围重放各别名。
- 10 项中性程序集 ManifestResource 均为嵌入资源（9 个图标、1 个文本），按名称、可见标志、长度和内容逐项比较；本次生成的资源内容及长度字共 41,922 B。ILAsm 从 `original.res` 导入 Win32 `RT_VERSION` 唯一叶 `(16,1,0)`，894 B、CodePage 0，原件和 ILAsm 产物的 SHA-256 都是 `f06244d518b260b8bab7d8b85b6cef5f0442ae14c7d4508d3f903501375eea1b`。最终件的 Win32 `.rsrc` 仍取原节。
- `evidence/compare-cil.ps1` 可用 PowerShell 7 静态重算 ILAsm 产物和最终件对照。原始两件在其各自元数据下比较，避免将令牌修补后的过渡文件误作独立、可加载程序集。

## DataCurve 界面

程序集使用 `NeutralResourcesLanguage("en-US", Satellite)`，在 `DataCurve.InitializeComponent` 加载 `/WpfPLData;component/datacurve.xaml`。对应布局位于安装目录的 `en-US/WpfPLData.resources.dll`（程序集 41.0.0.614，SHA-256 `c5ba599e2cd845db870d7494a86f68f66b7a5071f06ecab636ec3e0a5a8284a5`）中的 `WpfPLData.g.en-US.resources/datacurve.baml`。本包保留 3,701 B 的原 BAML 和逐节点抽取的 XAML 投影。BAML SHA-256 为 `9229871289aba90b98c5623e882f2be6768e3f8019275cc93ce368183c822b3f`，投影 SHA-256 为 `bbf24dba059dbec5d791a6b2c92b828fe0615f6e8935f1913677d6a52af44854`。实际运行仍需原 en-US 卫星及安装依赖。XAML 投影保留编译连接号供审阅，卫星重建另行验收。

| ConnectionId | BAML 元素 / IL 连接目标 |
| --- | --- |
| 1 | GroupBox / groupBoxOption |
| 2 | AesLabel / lblXAxis |
| 3 | ComboBox / ComboBoxXAxis |
| 4 | CheckBox / chkParaVar |
| 5 | AesLabel / lblParaVar |
| 6 | ComboBox / ComboBoxParaVar |
| 7 | CurvesSelectorControl / CurveList |
| 8 | AesCmdButton / btnClear |

`IComponentConnector.Connect` 的八个 switch 分支逐项与布局相符，ID 4 的 Click 接到 `chkParaVar_Click`。XAML 将 `ComboBoxParaVar.IsEnabled` 绑定到 `chkParaVar.IsChecked`。OK、Cancel、Clear 三项布局命令依次连到构造函数注册的 `ExecuteOKCommand`（另有 `CanExecuteOKCommand`）、`ExecuteCancelCommand`、`ExecuteClearCommand`。布局中的资源引用保留在原 BAML 和 XAML 投影中。外部控件和本地化程序集保留为加载依赖。本件比较代码与布局的可见边界，界面交互留待 Windows 对照。

## 构建与回放边界

`reproduce.py` 先用归档 IL 与资源新汇编，保留当次 ILAsm 产物。然后将版本构建字段 COFF 时间戳、PE 校验和及 MVID 归零，稳定的 `source-normalized.dll` SHA-256 为 `873da6aaa7fd6d7dd2fe37d2bf536b12dce2188b1c83edfe4b13dadb30dd084e`。运行时记录的三项原始字段可能随复编改变。方法头和令牌补齐后的中间件 SHA-256 为 `8f9417fd7256f8fdded1fe8e83ce35245c157a613f82976c24c2e0ac4659a205`。

最终映像以当次生成的 29,652 B 物理方法范围和 41,922 B 托管资源范围拼入原相对位置。其余 39,570 B 直接读取现场原件，包括 PE 头/节表、CLR 头和 26,404 B 的全量 CLR 元数据（`#~`、`#Strings`、`#US`、`#GUID`、`#Blob`）、调试和版本构建记录、启动导入布局、资源填充、原 `.rsrc` / `.reloc` 与 10,280 B Authenticode 证书表。最终 SHA-256 与原件一致，来自重组后比对。该签名沿用原件证书及签名数据，重编中间件无该签名，原件不含强名称。包内没有原件二进制或预制重编产物。入口在当前产物校验完成后尝试比较 v2 的中间件指纹（`db3c3fca0ef8a530ddbf94b97858c3980c626dcbf47d81f7cf99d4470044fa36`），在构建报告 `historical` 单列实际值、比较状态或计算失败原因。历史诊断只供追溯。当前输出直接消费本次生成的 CIL 和托管资源。

## 在新空目录复现

使用 Windows、Python 3.12（实测 3.12.10）、64 位 .NET Framework ILAsm（命令版本 4.0.30319，文件版本 4.8.4161.0，SHA-256 `486be223bcf745332cb86a2b0bb3399e5bc89fc2c31c4b3ac6a9ea13cf82fb3f`）和 .NET 9 SDK（实测 9.0.321，Microsoft.NETCore.App 9.0.23）和 Mono.Cecil 0.11.6 官方 NuGet 包内的 `lib/netstandard2.0/Mono.Cecil.dll`。ILAsm 使用 `compile.rsp` 构建目标 IL。`reproduce.py` 在新输出目录逐次编译 `tools/OperandDump/OperandDump.csproj`，以清空包源的配置运行本机 SDK 还原和构建，再运行新工具读取 IL 操作数。编译暂存、NuGet 缓存和工具产物均写入新输出目录。第三方来源与许可见 `THIRD-PARTY-NOTICES.md`。用于构建的原件为只读输入，其完整 SHA-256 由入口校验。

在新空目录展开 ZIP，把当前目录切换到展开根。将 `$net9Dotnet` 设为本机 .NET 9 SDK 的 `dotnet.exe`，可用 `--list-sdks` 和 `--list-runtimes` 核对。使用同一现场安装读取原件，或将 `$original` 改为具有相同指纹的文件。Mono.Cecil 依赖可在另一个新目录用 PowerShell 从 NuGet 官方源获取一次：

```powershell
$deps = (New-Item -ItemType Directory -Path ../dependencies).FullName
$nuget = Join-Path $deps 'mono.cecil.0.11.6.zip'
Invoke-WebRequest -Uri 'https://api.nuget.org/v3-flatcontainer/mono.cecil/0.11.6/mono.cecil.0.11.6.nupkg' -OutFile $nuget
Expand-Archive -LiteralPath $nuget -DestinationPath (Join-Path $deps 'mono.cecil')
$cecil = Join-Path $deps 'mono.cecil/lib/netstandard2.0/Mono.Cecil.dll'
Get-FileHash -LiteralPath $cecil -Algorithm SHA256
```

DLL 的 SHA-256 应为 `831dca77470d85cb6ffbea3072daa7a3df5b7c9fcfd9c3f43674a9be99d4bfcf`。已有同指纹 DLL 时，直接设置 `$cecil` 为该文件的绝对路径即可离线复跑。

```powershell
$original = 'C:\Program Files\AspenTech\AprSystem V15.0\GUI\Xeq\WpfPlotWizards\WpfPLData.dll'
$ilasm = Join-Path $env:windir 'Microsoft.NET\Framework64\v4.0.30319\ilasm.exe'
python .\reproduce.py --original $original --ilasm $ilasm --dotnet $net9Dotnet --cecil $cecil --out-dir ../new-run
Get-FileHash -LiteralPath '../new-run/WpfPLData.dll' -Algorithm SHA256
pwsh -NoProfile -File ./evidence/compare-cil.ps1 -Original $original -Assembled ../new-run/source-normalized.dll -Final ../new-run/WpfPLData.dll -Cecil $cecil -Report ../new-run/cecil-audit.json
```

预期 `../new-run/WpfPLData.dll` 的完整 SHA-256 为 `bf01baee83399cfdd4c3e67e965c4fced8bbb17ae83b892abcf14648a64996f7`，同级 `build-report.json`、`operand-audit.json`、`position-report.json` 留存本次构建证据。编译器新生成的时间戳与随机 MVID 仅影响未归一化的中间件。入口校验 ZIP 解包成员，源码目录始终只读。旧版预制版 OperandDump 和此次源码版在同一个原件以及同一个 ILAsm 原始产物上各输出 4,014 个位置，按 MethodDef 和 IL 偏移比较操作码宽度、种类、解析键及原始值。两个输入各自的新旧 JSON 逐字节相同，记录见 `evidence/operand-dump-equivalence.json`。历史诊断探针的准确命令和预期见 `evidence/historical-check.md`。

如需单独汇编可编辑 IL，可在展开根用下列命令将 IL、`.res` 和十个以清单名命名的资源载荷放到另一个新目录，再按 `compile.rsp` 汇编。源码编辑在临时目录进行，修改后的构建保留为 ILAsm 中间件。发布经过修改的逻辑需要重新生成匹配的元数据与签名，本包的原件回放用于固定内容等价复现。

```powershell
$scratch = (New-Item -ItemType Directory -Path ../raw-ilasm-run).FullName
$ilasmArgs = Get-Content -LiteralPath ./compile.rsp
Copy-Item -LiteralPath ./editable/WpfPLData.dll.il,./resources/original.res -Destination $scratch
Get-ChildItem -LiteralPath ./resources/managed -File | Copy-Item -Destination $scratch
Push-Location -LiteralPath $scratch
try { & $ilasm @ilasmArgs } finally { Pop-Location }
```

使用 PowerShell 7 可从指定现场卫星静态提取同一 BAML：

```powershell
$satellite = Join-Path (Split-Path -Parent $original) 'en-US/WpfPLData.resources.dll'
pwsh -NoProfile -File ./evidence/extract-satellite-baml.ps1 -Satellite $satellite -OutBaml ../new-run/datacurve.baml -Cecil $cecil
```

可在 Windows PowerShell 5.1 静态重取 XAML 节点。下列命令中当前目录仍为展开根，`$original` 为该 shell 中的现场原件路径。解码需要安装目录中用于解析引用类型的 WPF 控件程序集：

```powershell
$wizard = Split-Path -Parent $original
.\evidence\decode-baml.ps1 -Baml ../new-run/datacurve.baml -Xaml ../new-run/datacurve.layout.xaml -SearchDirectories @($wizard,(Split-Path -Parent $wizard))
```

后续检查为独立静态复核、总控复跑和正式登记。Windows 行为对照包括 DataCurve 视图、命令、数据绑定和宿主交互。

## 本批验收结论

从可编辑 IL 回编 145 个 CIL 方法体，校正令牌和方法头后使用原 PE 布局与 CLR 元数据生成逐字节一致的 DLL。已核对 211 项方法定义、10 项托管资源和 DataCurve 界面绑定。核验工具由源码即时构建。

[独立复核](evidence/independent-review.json) · [总控复跑](evidence/controller-receipt.json)
