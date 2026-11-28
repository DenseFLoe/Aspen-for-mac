# AdvancedFileDialogLib.dll

## 原件与证据来源

- 产品为 Aspen Plus / Aspen Properties V15.0，两条注册产品证据共享同一已安装文件。MSI 组件为 APRSYS410.GUI.Xeq.AdvFlDlgLi.dll.01AE6323_4069_4985_B882_1C2F459EE258，File 表成员为 advancedfiledialogli.01AE6323_4069_4985_B882_1C2F459EE258。
- 原相对路径为 [ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AdvancedFileDialogLib.dll。安装原件文件和程序集版本均为 10.0.0.0，文件大小 17,960 字节，SHA-256 为 dc459f335bfda3a3053046a4b18eff669f624673188e1bb274b45fe655a7e8e5。
- 静态标准和主干材料固定于 ba0c945804c33338edfb24d193b20f10d35186f5。原对象 tree 为 5e688274e5b1eb877b1f77a92a9b502de7c30d2b，归档说明、旧逐件报告和 IL 列表 blob 分别为 d3b5b2e450b49a16514aa53c6c18964e7011d1ec、85d18961de2aec7681ec5efbe07859bfcf36e8e4 和 0d81949fcdcf0759fa73d73bc9ff183a84a67875。旧报告有 1 条解码失败。本轮比较实测覆盖 5/5 有体方法的全部 506 字节 CIL 指令。
- 候选复用本地历史 AdvancedFileDialogLib.dll.v3.zip 的完整 IL，历史 ZIP SHA-256 为 42cbecaccde808ac61d7cfb129cd1a0a6dd0a9f4888e4a8fd1a8314745aca277。v4 删除反汇编生成的本地路径注释，并用数字参数槽表达原件无名构造参数。当前包为本轮静态候选，待独立复核和总控复跑登记。

## 从空目录复跑

使用 Windows x64、Python 3.12 和 .NET Framework 4.x ILASM。已实测 Python 3.12.10，ILASM 文件版本 4.8.4161.0、入口默认来自 Windows 的 Microsoft.NET/Framework64/v4.0.30319/ilasm.exe，可用 --ilasm 指定。已测 ILASM SHA-256 为 486be223bcf745332cb86a2b0bb3399e5bc89fc2c31c4b3ac6a9ea13cf82fb3f，字节回放要求该指纹。pefile 2024.8.26 与依赖 ordlookup 随包提供并附 MIT 许可。复跑无需网络、pip、.NET 9 或 Aspen 运行环境。核验命令另用 PowerShell 7 与随包的 Mono.Cecil 0.11.6。

在 PowerShell 中将 ZIP 解到新空目录，然后在解包目录运行。fresh-source 和 fresh-replay 应为新输出目录。

~~~
python -B reproduce.py --mode source --out fresh-source
$original = 'C:\Program Files\AspenTech\AprSystem V15.0\GUI\Xeq\AdvancedFileDialogLib.dll'
python -B reproduce.py --mode replay --out fresh-replay --original $original
~~~

| 模式 | 输出 | SHA-256 |
| --- | --- | --- |
| 独立源码装配 | fresh-source/AdvancedFileDialogLib.dll | a6cda579bceec10f3d126ca023c37a4f2504b0cce013064b899af6e10b75c2c9 |
| 原件布局回放 | fresh-replay/replayed/AdvancedFileDialogLib.dll | dc459f335bfda3a3053046a4b18eff669f624673188e1bb274b45fe655a7e8e5 |

独立入口只向 ILASM 提供可编辑 IL 和 RES。assembly-input/cand-asm.dll 保留原始 ILASM 产物，其 MVID 和 COFF 时间戳会变化。正式独立产物将 MVID 由 IL 和 RES 稳定派生，COFF 时间戳及 PE 校验和清零。ILASM 为事件提供器构造参数自动生成 A_0。原件该方法没有物理 Param 行，源码标记触发的后处理只为指定 .ctor(object) 把编译器生成的 Name 索引写为 0。只有参数名为 A_0、序号为 1、flags 为 0，且没有自定义特性、默认值和封送记录时才写入。修改源码后可移除标记，保留编译器生成的参数元数据。

回放需要显式给出现场原件并校验其完整 SHA-256。它另一次调用 ILASM，临时移除公钥指令，随后根据原件将 25 个四字节字段按位置重定位，含指令令牌、局部签名令牌、catch 类型令牌和 finally 保留字段。tokens-translated-for-original-metadata.dll 的方法体与其自己的元数据不配套，仅用于构建回放结果。回放程序直接读本次生成的中间件，将其 5 个方法的 596 字节全跨度写入文本区。text-prefix.bin 中这些跨度预先置零。CLR 元数据五个流、CLR 头所用字段、PE 头和节布局、原版 .rsrc 和 .reloc、强名和证书表按归档记录恢复。引导尾部也使用编译器生成的载荷及原件布局信息。包内没有预先编译的目标 DLL 或完整原件镜像。

## 静态覆盖

- 逐条核对 42 个 MethodDef，包括 18 条抽象声明、19 条其他运行时无体声明和 5 条 CIL 实现。比较声明类型、签名、方法与实现标志、参数及返回值、默认值、封送、自定义特性以及 MethodImpl 绑定。7 个实际类型另加 <Module>，4 个字段、8 个接口关系、18 个 MethodImpl、56 条自定义特性、22 条 FieldMarshal、1 个 mscorlib AssemblyRef。独立产物的这些定义和方法级语义均吻合。
- 两侧重解码五个方法体，核对每条操作码、操作数、分支/常量、31 个 CIL 元数据操作数绑定及作用域、局部变量、栈限制和 InitLocals。共 506 字节 CIL。包含方法头、对齐与 EH 的跨度按令牌为 36、283、46、200、31 字节，共 596 字节。回放结果五跨度逐字节一致。
- Finalize 的 small EH section 位于方法内偏移 172，DataSize 28 含 4 字节节头及两个 12 字节子句。catch System.Exception 的保护区 [0,133)，处理区 [133,139)。finally 的保护区 [0,144)，处理区 [144,157)。独立装配的 catch 解析到相同类型。原件 finally 保留值 0x01000000，ILASM 输出 0，字节回放恢复原值。历史独立报告将小型节的 DataSize 读取到保留字段，误记 572 字节，本轮以 596 字节为准。
- 唯一原件资源是 Win32 RT_VERSION 路径 16/1/0，代码页 0，载荷 716 字节，SHA-256 为 060c617bcd34faf32e856d402cb262f89b56e2da24513c4334ae49601e6eeebc。归档的 RES 和独立装配输出均含相同载荷。原件的 CLR 资源目录大小为 0，程序集无 ManifestResource、WPF 程序集引用、BAML/XAML、控件树、WPF 事件或数据绑定。本件公开对话框调用和 COM 事件接口由导入类型声明与连接点代码表达，实际对话框控件资源在本 DLL 之外。
- 独立装配的物理元数据行数差异为 TypeRef 29→27、MemberRef 25→24、StandAloneSig 3→2、Param 38→33。前两项对应无引用的 MarshalAsAttribute、UnmanagedType 和该特性构造器，22 个实际封送描述符均一致。独立装配省略 3 个无局部变量方法所共用的空局部签名 0700，读取到的局部变量语义一致。ILASM 省略六个无名、无标志、无附加元数据的返回值 Param 行（0x06000002、03、08、15、16、1b），并在 0x06000028 留一个无名、无标志、无附加元数据的参数行。数值令牌、元数据表与堆布局在独立装配时生成，物理原样保留由回放入口提供。

## 签名及后续

独立装配保留原 Assembly 公钥，程序集身份及公钥令牌 b05689b39deefbcd 一致，强名签名槽未签署且无 Authenticode。原 COFF 时间戳、MVID、PE 检查和及证书签名属于原构建信息。回放保留原件强名签名和 Authenticode 字节，本轮制作核验未检查证书链或时间戳的有效性。Windows 运行、COM 激活及对话框行为对照留到 Windows 重建阶段。

## 复查命令与文件

~~~
pwsh -NoProfile -File tools/compare-managed.ps1 -Original $original -Candidate fresh-source/AdvancedFileDialogLib.dll -Report fresh-source/managed-comparison.json
python -B tools/inspect-image.py --original $original --source-candidate fresh-source/AdvancedFileDialogLib.dll --replay-candidate fresh-replay/replayed/AdvancedFileDialogLib.dll --resource resources/original.res --output fresh-source/raw-comparison.json
~~~

制作记录见 evidence/independent-source-managed.json 与 evidence/raw-pe-and-resource.json。前者逐条列出方法声明、解析绑定与异常区，后者提供 MethodDef 参数物理行、原始 EH 节字节和足迹、资源内容及签名槽。PACKAGE-SHA256.json 登记包内文件完整指纹。reproduce.py 在 fresh-source、fresh-replay 各生成 build-report.json。证据生成工具版本见 build-plan.json。


## 本批验收结论

独立 IL 装配覆盖 42 项方法定义、5 个方法体、2 条异常子句和 Win32 版本资源。总控从定版 ZIP 分别复跑了独立装配和布局回放。独立产物未签名，使用原件数据回放的产物逐字节一致。

[独立复核](evidence/independent-review.json) · [总控复跑](evidence/controller-receipt.json)
