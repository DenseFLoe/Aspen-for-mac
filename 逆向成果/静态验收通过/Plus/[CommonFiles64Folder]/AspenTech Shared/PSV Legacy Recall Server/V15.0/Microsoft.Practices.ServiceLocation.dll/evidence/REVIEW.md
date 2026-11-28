# Microsoft.Practices.ServiceLocation.dll 独立静态复核

本页保留独立复核的结论及可公开的证据链接。本机明细以文字路径标明。原始报告 SHA-256 为 `0ce933b64e550829cfa12e7728e2c2fb14dbab4e8adc57b561636f5ec7e33d44`。

**裁定为静态验收通过。** 本报告仅适用于 SHA-256 为 `6b81cf93e25c7cbdd5e7ab221320359a9b35ca73df251f1176a9c65da35949ea` 的冻结包。合格入口为 Profile136 的直接 C# 编译。Aspen Plus V15.0 的 PSV 安装原件为 18,120 B，文件及程序集版本 1.2.0.0，SHA-256 为 `78ac70411c71b7a0c68fe8746edd3f3a8cd3f72044b329a40ab53c57891be37d`。

## 范围及预注册

复核员为 `/root/reviewer`，与制作员分开。固定主干为 `adbe73b517acac25da87598cce46de033f630ccb`，对象路径为 `逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/Microsoft.Practices.ServiceLocation.dll`。按该提交 `docs/static-acceptance.md` 和 `docs/reverse-execution-reference.md` 第 3.1 节评定。主控检取的对象及标准身份列在任务根 `BASELINE.json`。

1. 检查前先落盘 [PLAN.md](PLAN.md)，SHA-256 为 `ebffc8549579abaca22072f0ad1df70d3fa0084d593bec585fb9339c81019cba`。
2. 在复核目录将制作 ZIP 解到新的 `source/`。实测 32,022 B、10 个成员，完整 SHA-256 及每个成员的大小和指纹均与制作清单一致。核对了 PSV 与 GUI/Xeq 两处安装文件的实际内容，两者同指纹。解包成员为 C#、公钥、托管资源及版本资源、构建及比较脚本、逐件说明及 3 份 JSON 证据。原件公钥等于包内 160 字节公开密钥。源码可编辑、无待补实现，各声明的依据见独立方法清单。[输入、路径和成员指纹](inputs.json)
3. 检查 `build.py` 的实际执行路径，输入为 C#、三个包内资源、由参数指定的 native csc 和两个参考程序集。脚本以 `/noconfig /nostdlib+ /optimize+ /langversion:5 /delaysign+` 调用 csc，响应文件在当前输出生成。构建期间没有原件、预制 DLL 或历史回放输入。比较期间显式读取 PSV 原件。工具依赖指纹用于锁定输入版本。包内 `evidence/compare.py` 对命令行指定的两份 PE 分别调用 ILDASM 并读取 PE 表，仅以实际解析的行、符号和资源作比较，未发现按历史样本标识、计数、指纹或历史报告赋判的路径。
4. 复核另用 Microsoft ILDASM x64 9.0.23 的 `/QUOTEALLNAMES /RAWEH /TYPELIST`、`/NOIL /METADATA=RAW`、`/NOIL /METADATA=VALIDATE`，以及 pefile 2024.8.26 的 PE 读取路径。查看两侧导出的可读定义和指令、表行、资源及底层 PE 字段。全程未启动或加载目标程序集执行。[逐命令记录](commands.jsonl)

## 空目录重建及实测

Windows x64 本机使用 Python 3.12.10、native csc 4.8.4161.0、Mono 分发的 2014-04-14 Profile136 参考集，桌面使用 Microsoft.NETFramework.ReferenceAssemblies.net40 1.0.3 的参考集。每组仅显式引用 mscorlib.dll 与 System.dll。以下所有 DLL 名均为 `Microsoft.Practices.ServiceLocation.dll`。

| 独立空输出 | 实际 DLL SHA-256 | 预期及实测 |
| --- | --- | --- |
| `pcl/` | `0eb0e20d56dd7be510ac9c287f5f6265ad7b9f63c2a87c11e14cef59932659fc` | 构建成功，比较退出 0。44 项方法及全部静态验收项吻合 |
| `pcl2/` | `8b8b723085e8151bda2c5464234edf9b90c2b0eff4963d3a10d85bbcb956e90c` | 第二个空目录构建成功，比较退出 0。44 项方法及全部静态验收项吻合 |
| `net/` | `bb3f89f11151e35d4b899b0017d86764d2adb5fa0e956086d85b411829041952` | 构建成功，比较退出 1。44 项方法吻合，独立表比较仅有两行 AssemblyRef 差异 |

每份编译产物 11,264 B。两份 Profile136 构建仅清零编译器产生的 COFF 时间戳和 MVID 后，其 SHA-256 均为 `18f1110b23879b935639a46f8842dd32f2e17c4c9c38670f1046e16f299fbee2`，与制作方一致。以上每次比较的基线均为实际安装原件。[三次结果](positive.json)

## 原件覆盖及差异归因

- 沿原件 MethodDef 的 RVA、ImplFlags 与 Flags 区分出 44 项方法，32 个含 CIL，8 个 abstract，4 个 runtime 委托成员。8 项 TypeDef 含模块伪类型。独立 IL 清单按声明类型、方法名和完整签名配对，逐行保留方法主体、局部变量、已解析操作数、声明属性、覆写和异常区。286 条有操作码的指令均吻合，其中含 57 条 call/callvirt/newobj。另有 4 个 EH 结束标签。这 4 个标签不计入指令数。独立按 tiny/fat 方法头求和，两侧均为 764 个 CIL 字节。两个 catch 的捕获类型和范围、迭代器的一条 fault 与一条 finally 的范围均相同。清单、逐项命令和方法语义（本机记录 `independent-evidence.json`） · [按方法令牌统计的 CIL 字节与 PE 头](pe-details.json)
- 独立核对所有 20 张非空表。方法表顺序变化时按类型所有权、实际签名及参数范围配对。读取 String 和 Blob 堆的真实值，比较行的多重集和相关绑定。读取 59 项 MemberRef、27 项 CustomAttribute、7 项 MethodImpl、9 项 Property、10 项 MethodSemantics 等。DebuggableAttribute 构造器参数的 TypeRef 编码原件为 0x69，候选为 0x3d，按 ECMA-335 的 TypeDefOrRefEncoded 解出同一嵌套枚举 DebuggingModes。同一构造器的属性载荷保留。Profile136 两个 AssemblyRef 均为 retargetable，mscorlib 与 System 均为 `2.0.5.0/7cec85d7bea7798e`。net40 两行均变为 `4.0.0.0/b77a5c561934e089`，标志清零。程序集身份及公钥、字段、参数和托管资源声明对应。实际 `#US` 整段指纹也相同。原件元数据及 IL（本机记录 `ind-original/`） · Profile136 元数据及 IL（本机记录 `ind-pcl/`） · 桌面 .NET 4.0 元数据及 IL（本机记录 `ind-net/`）
- 托管资源目录 591 B 的 SHA-256 为 `49146e432cc8cec259fb349a88a75fe8298251becc05958b28129b5525322ac8`。四字节长度后为 587 B 命名资源，源码包成员、独立 ILDASM 的导出物与 PE 中的载荷一致。Win32 资源目录 1,224 B 的 SHA-256 为 `d6f7bde3886de0d1c126b2c7037ed14f4bf1b8f3be40fa423f84fa1121176dac`，仅含 RT_VERSION/1/0，codepage 0，载荷 1,136 B 的 SHA-256 为 `857b007f55274d5887bd757d4f0045cefc9747da3d86728401f12ae54f69f686`。三次独立导出的 1,200 B .res 均与包内构建资源逐字节相等。
- 三者均为 PE32、IL-only 的托管 DLL，本机入口间接跳转至唯一导入 `mscoree.dll!_CorDllMain`，HIGHLOW 重定位位于跳转操作数。原件到 Profile136 的可选头标量差异只有入口 RVA（16862 到 16558）与 CheckSum（52143 到 0）。目录布局另有变化。原件 CLI flags 9、128 B 非零强名签名、6,856 B 证书表与 284 B RSDS CodeView 记录，直接构建 CLI flags 1、同公钥、128 B 全零延迟签名槽、无证书和 CodeView。未复制原签名、证书或调试布局。源恢复与可静态验证的逻辑及资源已闭合。原厂签名信任、宿主加载及运行行为留到 Windows 对照阶段。

## 单项扰动

每项从同一 `pcl/` 编译物只改一个字节，在各自新目录使用原安装 DLL 作比较。四项均预期并实测退出 1。编译物、四个负例、原件、字节前后值与偏移均在 [negative.json](negative.json)。

| 独立用例 | 修改偏移（十进制） | 实际定位 |
| --- | ---: | --- |
| 将同签名资源 getter 调用重定向到另一个 getter | 1454 | 仅 FormatActivationExceptionMessage 方法变化，43/44 相同 |
| 改动一位命名资源字符串 | 2285 | 44/44，managed_resources 差异 |
| 改动 Win32 版本字符串一位 | 9724 | 44/44，win32_directory 与 win32_leaves 差异 |
| 清除首条 AssemblyRef 的 retargetable 标志 | 4527 | 44/44，il_metadata 差异 |

包内比较器适用于本件的 PE32、标准 CLI 元数据流、引导桩与资源布局；部分 PE 标量、未被 IL 文本显示的表行内容以及签名、证书与调试材料的字节不参与其布尔结论。独立复核在本件上补查了表行与 PE 标量和独立资源导出。该比较器与复核脚本均未作其它二进制的通用验收器评审。

## 复现入口

下面的 PowerShell 从项目根运行。选择尚不存在的临时复核子目录，运行后会得到 `src`、`pcl`、`net`、`check-pcl` 和 `check-net`。Python 和 native csc、两组参考程序集是编译输入；安装原件与 ILDASM 只参与比较。无需完整 dotnet SDK。同一组参数及绝对路径的原始实测命令在本目录 `commands.jsonl`。

```powershell
$w = (Get-Location).Path
$t = Join-Path $w '.local/codex-router/work/78ac70411c71b7a0c68fe8746edd3f3a8cd3f72044b329a40ab53c57891be37d/20261128-b01'
$f = Join-Path $t ('review/repeat-' + [guid]::NewGuid())
New-Item -ItemType Directory $f | Out-Null
$env:TEMP = $f
$env:TMP = $f
Expand-Archive -LiteralPath "$t/producer/Microsoft.Practices.ServiceLocation.dll.source.zip" -DestinationPath "$f/src"
Set-Location $f
$csc = "$env:windir/Microsoft.NET/Framework64/v4.0.30319/csc.exe"
$tool = "$w/.local/batch-roundtrip-20261125/tooling"
$ildasm = "$tool/il/ildasm/ildasm.exe"
$dll = 'Microsoft.Practices.ServiceLocation.dll'
$orig = "C:/Program Files/Common Files/AspenTech Shared/PSV Legacy Recall Server/V15.0/$dll"
python -B src/build.py --csc $csc --profile profile136 --references "$t/producer/portable-refs/mono" --out pcl
python -B src/evidence/compare.py --ildasm $ildasm --original $orig --candidate "pcl/$dll" --out check-pcl
python -B src/build.py --csc $csc --profile net40 --references "$tool/csharp-reference-packs/references/net40" --out net
python -B src/evidence/compare.py --ildasm $ildasm --original $orig --candidate "net/$dll" --out check-net
```

独立导出命令在新目录内运行，`/OUT` 使用该目录的相对文件名，输入路径也可从当前目录相对定位。实测中 Windows ILDASM 的元数据子命令对带非 ASCII 字符的候选绝对路径返回 0x80070003；改用相对路径后原始表及验证视图均成功输出。`run.py` 保留了工作命令，`independent.py` 解析原件和两个候选的独立清单、原始表与 PE 资源，`pe_checks.py` 直接核对方法体长度、公开密钥和资源的完整字节，`negative.py` 构造四个单字节扰动。原始证据的 SHA-256 如下。

| 材料 | SHA-256 |
| --- | --- |
| inputs.json | `2bee27bee921616ef60e107040f5f37350c6a88809e0f23859179a9e673629af` |
| positive.json | `742ecc9ef322f496bbb727c1d41b4d1a2a0c858ce4a51ae8d61871ca2ea46fa1` |
| negative.json | `38eab0dbc5228926a12f6a9f8016095a3500d037a9cb594295ea05c167ec3b7b` |
| independent-evidence.json | `662fbb50348376e7373b764e48f47bf979dda208de6e81c314fdebc7a0bf0ce9` |
| pe-details.json | `40bfc9c4f179169e7d23a6d2df7ac94900ebdc2626a81d593726aa5e151b97f9` |
| commands.jsonl | `788c104e28ce03f56ae02c3ac5adda9cc35b9541450193f8fa62bafeb06c03ad` |
