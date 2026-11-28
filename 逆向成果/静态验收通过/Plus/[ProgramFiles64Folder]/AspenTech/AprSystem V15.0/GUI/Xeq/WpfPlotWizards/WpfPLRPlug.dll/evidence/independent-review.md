# WpfPLRPlug.dll 独立静态复核报告

**裁定：pass。** 基线为 GitHub main `ba0c945804c33338edfb24d193b20f10d35186f5`。本报告绑定的 ZIP SHA-256 为 `98266c9bf32a2316b05596f098303880eaf70c66155728dd6cdd332747b0f65a`。复核员未参与制作，在新建的 review 目录先写入 PLAN.md，再读取送审包。结论适用于 Plus / Properties 共用的 Aspen V15.0 主 DLL。总控复跑、正式分类与 Windows 行为对照依各自流程办理。

## 实物与构建

原件 `C:/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLRPlug.dll`，文件、产品和程序集版本均为 41.0.0.614，SHA-256 为 `f706516819aa7da442d9080aa6eb8a49da9f92ed0d132fd67278b60dd0ce4c3c`。同目录 en-US/WpfPLRPlug.resources.dll 的文件版本 41.0.0.614，SHA-256 为 `1719dbc432d68cfe08037fe43440f8d68a7f0b6e442a5df66d3002d994b3fc3c`。

ZIP 通过 CRC、成员路径和重复项检查；32 个成员，其中 31 个成员与包内 SHA256SUMS.txt 精确互验，清单自身由 ZIP 指纹绑定。核对了源码、构建计划、脚本、资源和同名说明。唯一产品源码 WpfPLRPlug.dll.cs 的 SHA-256 为 `e5baee78c03fb5b5d84f17532974b8b90ca91171576b0b32ca172d72a3d33dee`。build.py 校验工具、引用和资源后写 csc 响应文件。它从包内源码构建，用 9 个框架引用和 8 个产品引用（其中 Interop.Happ.dll 用 /link 嵌入 COM 声明）、9 个原版托管资源和一份 Win32 .res。实际命令的所有输入见 fresh/compile.rsp，工具及目标指纹见 review-fingerprints.json，引用指纹见 expanded/build-inputs.json。独立构建不读取原件、卫星、旧编译产物、回放配方、固定元数据、调试记录或证书；新包未带预编译的目标 DLL。外部引用只用于编译与约定类型嵌入。

在 fresh 新目录用 Roslyn 3.8.0、Python 3.12.10 编译，退出 0。fresh/WpfPLRPlug.dll 118784 字节，SHA-256 为 `2a37eb5fde969850b2262d0cf15055a65d95ea66b5442822e63bd4cc09d6d8ad`。查读夜班 n-f706-b 的 REPORT.md 及 REPRO-EVIDENCE.json，其逐字节重现的编译中间件指纹 120251cf…，最终等于原件依赖重绑和回放。n-f706-c/pkg3 的原始元数据、证书、调试输入和构建读取点仍在原路径，当前核验直接使用 fresh 中 csc 输出。

## 两条 CIL 核证路径

1. 现场重新编译包内元数据读取器并运行 audit.py。覆盖 458/458 MethodDef、387 个 CIL 方法、71 个无体 COM 声明（39 个访问器、7 个普通声明、25 个 vtable gap）。5766 个令牌操作数中有 4588 个编号改变；比较解析后的符号、方法及参数元数据、体结构、局部变量签名与初始化、分支、最大栈、19 个异常区及捕获身份。核查 23 个 TypeDef（含 Module）、288 字段、130 属性、180 条显式方法覆盖、15 AssemblyRef。446 个定义直接满足严格符号比较；检查生成符号后 458 个定义均满足验收。重跑的 CIL-PE-COMPARISON.json、WPF-LAYOUT.json 分别与包内对应文件字节相同。对照脚本从现场两端 PE 取证；生成名称的约束和匹配来自相同方法相同位置的引用，原件和工具的固定指纹只作身份核对。
2. 用独立 ILDasm 9.0.23 对原件与 fresh DLL 分别生成带原始 EH 范围表示的汇编文本；独立脚本 independent.py 只读取这两份 IL、包内资源/页面和成员清单，无制作方映射或比较结果输入。从 ILDasm 的操作数文本（含 owner 和完整签名）及原始 IL 偏移推导跨两端成对的生成成员名，逐项约束逆映射的唯一性；限定生成符号格式，对普通成员名称、参数、常量或字符串不予泛化。以生成方法名称中编译器序号以外的签名和 owner 定位定义，再用其完整原文和全部引用核对实际改名。得到 141 个变名引用点、3 个生成类型改名、36 个字段和 5 个方法改名。逐行核查完整方法声明、签名、方法体（13844 条指令）、分支、局部变量、19 个 EH 条款和所有命名绑定；归一化后 458 份方法文本均完全相同。独立恢复的 22 个命名类型的全部 288 个字段及声明顺序也一致。5 个含无体声明的 COM 接口，声明、gap 与原件顺序一致。证据 independent.json 记录双射、引用方法及指令偏移、资源和逐页 WPF 明细，SHA-256 `c57573d12b11abf516e0f5db7c34fd31edae5dc14f2df7adeec560e6ff08ffeb`。

对历史源码与交付源码的两处申报修订做了定位：PropSet.PropertyList 的声明位置恢复字段顺序，编译的后备字段在上述顺序检查中相符。PropSet.CancelCommand 的 delegate(object dr) 在原、候选均保留同名形参和相同代码；原方法 060000C8 对应候选 060000EB，getter 的 IL_000a 绑定到本类生成的相应方法，二者名称从 b__67_0 变为 b__50_0。

## 资源、WPF 与反证

ILDasm 从两端实物独立导出 8 个 ICO、1 个文本和 Win32 .res；逐文件与包中对应输入形成三方字节一致。两端托管资源的名称、Public 标志及整体 36336 字节一致，Win32 VERSIONINFO 叶 /16/1/0 的 938 字节一致。这些资源字节来自原件。BAML 从已安装 en-US 卫星单独读取；主 DLL 的语种回退、8 个实际 pack URI、BAML 和包内可编辑 XAML 经核对相符。以相同卫星、不同两端主 DLL 的连接代码分别反解，8 个 XAML 均与交付字节一致。另用 XML 与 ILDasm 的各页 Connect 方法核实 51 个命名控件实际写入字段，18 个事件连接有对应处理器函数指针和 add_Click/add_DropDownClosed。8 页共有 10 个数据绑定表达式、16 个命令属性；详见 independent.json 及 audit/WPF-LAYOUT.json。卫星是另件，此 ZIP 提供核对主 DLL 的页面源码，不重编该卫星。Windows 交互未执行。

反证在 CONTROL-PLAN.txt 先定预期。在副本里将 CompAttr 的 comboBoxComponent.DropDownClosed 仅从 comboBoxComponent_SelectionChanged 改接到同签名 comboBoxSubstream_SelectionChanged，更新副本源码指纹清单。编译仍成功，变体输出 SHA-256 `9b45015d71c3ca4975d7b4b1c697f80bcf8c465f5ab7ff864b53d2c8854ef3dc`。audit.py 退出 1，准确报 CompAttr.IComponentConnector.Connect 的 resolved_operands 差异和 compattr.xaml 字节不同，剩余 457 个方法匹配。见 control-summary.txt、control-build/build.json。正本全程只读。

## 签名、范围与后续

原件与回编均 I386、ILOnly、无 CLR 强名称。原件 129064 字节，Authenticode 证书表 10280 字节；回编 118784 字节，证书表为空。原件 CodeView 284 字节、回编 Reproducible 0 字节。MVID 从 `33f5594c-b36a-491d-b33a-c30a4d275e57` 变为 `5a32bdf0-5f46-4765-b696-5c1de94ab289`。时间戳、校验和、元数据与 PE 排布差异见 audit/CIL-PE-COMPARISON.json。现阶段主 DLL 无未解决的静态缺口。后续由总控从锁定 ZIP 在新空目录复跑并登记；运行时 WPF 交互和卫星装载留到 Windows 阶段。

## 命令与证据

工作目录为项目根，复核根为本报告所在 review/。命令的绝对输入和输出变量保留在 rebuild.ps1、disassemble.ps1、control.ps1 中。可在对应空目录按相同命令与本机路径复跑，输出请用新的审查目录，已有结果不覆盖。

- 解压与成员指纹：`py -3 -B "$r/unpack.py" $z $r`，结果 zip-members.json。
- 新编与交叉核验：`py -3 -B "$e/build.py" --csc $csc --framework $fw --xeq $xeq --out "$r/fresh"`。随后 `py -3 -B "$e/audit.py" --original $o --candidate "$r/fresh/WpfPLRPlug.dll" --satellite $sat --dotnet-root $net --ilspy $spy --framework $fw --xeq $xeq --out "$r/audit"`。
- 独立对照：在各自空目录对原件与 fresh DLL 分别执行 `& $il /utf8 /raweh /out=image.il $inputFile`，再执行 `py -3 -B "$r/independent.py"`。早先 ILDasm 尝试使用 /text，9.0.23 工具不识别；正式取证命令如上，成功导出两端实物。
- 反证复现：审查用 control.ps1 从解压正本复制、改单处、重编并审查，脚本核对内层验收退出码为 1。review-fingerprints.json 给出主要输入输出的全指纹。REVIEW.sha256 单独保存报告指纹。