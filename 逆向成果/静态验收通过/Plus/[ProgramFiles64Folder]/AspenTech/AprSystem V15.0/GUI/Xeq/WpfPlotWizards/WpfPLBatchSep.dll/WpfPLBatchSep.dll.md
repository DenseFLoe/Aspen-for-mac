# WpfPLBatchSep.dll

## 原件与成果

- 产品为 Aspen Plus / Aspen Properties V15.0。文件、产品及程序集版本均为 41.0.0.614。现场相对路径为 `[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLBatchSep.dll`。
- 主件原版 284,712 字节，SHA-256 `d6ba3b3848dcdb37912554bbfb078568db6f44d8bdfb288914fbc42a2a1d8106`。静态验收基线为 GitHub `ba0c945804c33338edfb24d193b20f10d35186f5`。固定主干对象中可定位的 IL 文本 blob 为 `2c02557f5ad8b7caf8950f8f435c64f3f1e3b710`。对象说明另列 C#，该固定对象目录无对应 blob。
- 可编辑 IL 和主件资源源自历史 `WpfPLBatchSep.dll.v4.zip`，SHA-256 `46a19410760c3cd0cf84e20f429f0209a02aeb8692c02c31facb4e24261ea43b`。v4 曾回填原件令牌并回放原 CLR 元数据、PE 头、节和证书以得到整件原指纹。本包构建从 IL、声明意图和提取的资源生成两个 PE，无原件 DLL 构建输入。
- 主件通过 `NeutralResourcesLanguageAttribute("en-US", Satellite)` 和 14 条 `Application.LoadComponent` URI 引用同目录 `en-US/WpfPLBatchSep.resources.dll`。现场卫星为 56,360 字节，版本 41.0.0.614，SHA-256 `d4781f877377155c326bb5b54c59cf0c639544767476637e471626416f422604`。检查它在主件的布局资源依赖范围内，卫星 DLL 无 MethodDef，单独原件裁定不在本件范围。

## 可编辑源码和资源

- `source/main/WpfPLBatchSep.dll.il` 包含完整 CIL 汇编和托管声明。18 个托管资源为 17 个 ICO 和 1 个 TXT，单独作为文件传给 ILAsm。两个 COM setter 的第 4 参数在 IL 中省略名称，以配合源声明意图恢复真正的空名称。
- `source/method-intent.json` 以类型和方法名记录 43 处 InitLocals、18 处 COM 虚表空位和 2 个空参数名。构建工具定位自己的输出 PE，验证行与字段后只更新这些字段。 .NET Framework ILAsm 将 43 个无局部变量的 fat 方法 InitLocals 清位，将 18 个 COM runtime 空位自动标为 virtual abstract，也给两处空名生成 A_3。另通过 /DEBUG=OPT 生成 DebuggableAttribute，再按 IL 声明把模式从 3 调回 2。
- ILAsm 自行分配元数据令牌、RVA、节表和各个 CLR 流。令牌按程序集作用域、完整符号及签名核对，直接构建路线的操作数回填数为 0。修正工具不拷贝原件的方法体字节、CLR 元数据流、PE 头、节表、重定位节或证书。两个 Win32 `.res` 和 18 个托管资源使用原件提取的资源 payload，容器与资源目录由 ILAsm 生成。
- `source/en-US` 含卫星 IL 外壳、Win32 `.res`，及 42,667 字节原 `WpfPLBatchSep.g.en-US.resources`，其 SHA-256 为 `0dc541836cbc1a5e32f860c45109fff5243600d9badeb13e7e350a7fd726a4a6`。卫星构建原样嵌入这个资源容器以保留 14 个 BAML payload。 `layout/` 提供这 14 个页面的可编辑 XAML 导出，供查读界面、事件和绑定。XAML 导出没有进入卫星构建。
- 生成文件使用由规范化自有映像导出的 MVID，COFF 时间戳和 checksum 清零。编译期生成的调试记录和 PDB 引用从交付产物剔除。原版两文件的 Authenticode 在现场验证均为 `Valid`。本包输出均为 `NotSigned`。

## 空目录复跑

需要 Windows PowerShell 7、.NET SDK 9（编译并运行局部修正工具）和 Windows .NET Framework x64 ILAsm（实测命令版本 4.8.4161.0，文件 SHA-256 `486be223bcf745332cb86a2b0bb3399e5bc89fc2c31c4b3ac6a9ea13cf82fb3f`）。实测 .NET SDK 9.0.321。构建使用同名外部程序集引用声明，既不加载这些引用，也不需要原件或 Aspen 安装作为构建输入。有多个 dotnet 时通过 `-Dotnet` 传 SDK 的启动器路径。另有兼容 ILAsm 时可通过 `-Ilasm` 指定，本记录的预期哈希适用于实测汇编器。

在新解包目录中执行以下命令。输出目录须为空或尚未存在。

```powershell
pwsh -NoProfile -File .\build.ps1 -OutputDirectory .\out -Dotnet '<path to .NET SDK 9 dotnet.exe>'
```

| 预期输出 | 字节 | SHA-256 |
| --- | ---: | --- |
| `out/WpfPLBatchSep.dll` | 278,016 | `3d4e3149b1ba4d1130e721fd981a411c26f5d9ec2815aeaf10c0a115a1a68e4f` |
| `out/en-US/WpfPLBatchSep.resources.dll` | 46,080 | `a24cd097cd70a62c8af401247794367fd75ef7500bc6819734378f0fdf810f95` |

18 条 ILAsm COM 提示是原始中间输出的已知提示。修正工具报告主件 `initLocals=43`、`comGapFlags=18`、`debuggableMode=1`、`emptyParameterNames=2`。工具目录 `out/build/` 保留用来审计的原始汇编中间件，部署产物为上表两个文件。

## 制作方静态核对

- `evidence/cil-managed.json` 中 841 个 MethodDef 全部匹配，其中 789 个 CIL 方法体、52 个原本无体的声明。39,583 条指令核对了操作码、分支、调用/字段/类型/字面量解析、局部变量、MaxStack、InitLocals 和 121 条异常区。没有缺失体或差异。
- 同表核对 58 个 TypeDef（含 `<Module>`）、703 个字段、210 个属性、1 个事件、18 个 AssemblyRef 及 18 个托管资源。声明检查包含方法作用域及原型、参数、访问/实现标志、特性、覆盖、封送与属性/事件关联，COM 接口还按声明顺序比较。原版和候选的两个 Win32 VERSIONINFO 资源名称、语种和负载哈希见 `evidence/main-pe.json` 和 `evidence/satellite-pe.json`。
- 原版、候选分别使用 ILSpy BAML 解码器导出，14 份 BAML 键和 SHA-256 相同，14 份 XAML 逐字节相同。`evidence/wpf-layout.json` 逐页关联 pack URI、BAML、XAML 根类型、88 个命名控件字段的 Connect stfld 指令偏移、22 项 XAML 事件、15 项命令和 10 项 XAML 绑定。CustomStripPlot 还实现 IStyleConnector，详见对应 connector 的 CIL。
- CustomStripPlot.Custom 构造方法 IL_02d5 将 DataContext 设为自身。相关布尔属性和 SelectedVariables 行类型 getter 可在主件定位。BAML 保留 `CustomStripPlot_ID`、`Variables_CSP` 的动态属性路径、3 个直接上下文绑定及 `Content.Text` 的 RelativeSource Self 表达式；此处静态核对原始路径和上下文代码，Windows 对照阶段验证实际赋值和求值。布局的外部 Aspen 控件、本地化和样式资源由运行环境提供。
- 签名、MVID、调试信息和 PE 构建布局差异独立列在 PE 证据。Windows 加载、呈现、交互、事件触发与绑定求值留待 Windows 重建对照。制作方记录覆盖的静态范围已闭合，整件裁定由任务负责人结合独立复核后登记。

`SHA256SUMS` 按区分大小写的序数路径排序，逐文件记录包内材料 SHA-256，清单自身的完整性由外部 ZIP SHA-256 覆盖。核对脚本和依赖细节见 `evidence/README.md`。

## 本批验收结论

从可编辑 IL 重建主 DLL 和 en-US 卫星，核对 841 项方法定义、789 个方法体、121 个异常区及 14 个 WPF 页面。卫星嵌入原 BAML，两个回编产物的资源和指纹已在总控空目录复核。

[独立复核](evidence/independent-review.json) · [总控复跑](evidence/controller-receipt.json)
