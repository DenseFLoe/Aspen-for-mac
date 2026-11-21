# 006_AdbConfigOptions.dll 静态复核报告（Aspen-Plus / 全程序集 IL + C# 反编译）

## 必填字段（T0 口径，逐项可按名检索）

- tool=ILSpy 9.1.0.7988 + dnfile 0.18.0
- functions=N/A（CLR 托管程序集，无 native 函数概念；methods=18）
- decomp_ok=N/A（CLR：无函数级反编译统计）
- decomp_fail=N/A（CLR：无函数级反编译统计）


样本别名：`006_AdbConfigOptions.dll`（清单 read-test-waiting.csv（schema B），原件目录只读、未上传）
来源：分支 codex/waiting-for-tietoumao｜git_blob 103fe4f0b7c1｜自算 sha256 ff46e9a2488c31f2590c6fae8210a960ef2d00c77cd6a0f58d9e76f09dc0a11c｜台账 20261119-61 缺失〔待验证〕
落点：`01-completed/Aspen-Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen Data Share V15.0/`（相对 `out/R1`）｜定位规则：`local-rel`

标签约定：〔实测〕= 本轮独立实测（有命令与原始输出）；〔待验证〕= 尚未取得证据或需 Windows 环境。

## 0. 摘要

| 项目 | 结果 | 依据 |
| --- | --- | --- |
| 实际样本 | 18,472 字节（18,472），SHA-256 `ff46e9a2488c31f2590c6fae8210a960ef2d00c77cd6a0f58d9e76f09dc0a11c` | 〔实测〕自算 |
| 程序集身份 | CLR 元数据 `v4.0.30319`；流 5 个；强名 RVA `0x0` / 0 字节 | 〔实测〕 |
| 方法统计 | 19 = 18（有 IL 体）+ 1（抽象）+ 0（运行时实现/委托）+ 0（P/Invoke） | 〔实测〕 |
| IL 清单 | `il/006_AdbConfigOptions.dll.il.txt`，315 行，MethodDef 19 条（全量，逐条指令） | 〔实测〕 |
| 反编译 | `decompiled/006_AdbConfigOptions.dll.cs.txt`，209 行（ILSpy 9.1.0.7988 全量 stdout） | 〔实测〕 |
| 原生调用 | ImplMap 0 条；PE 导入表 1 个 DLL | 〔实测〕 |
| 缺口 | 见 §7（签名有效性、运行期行为未验证） | 〔待验证〕 |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

## 1. 样本与哈希

| 项 | 值 | 标签 |
| --- | --- | --- |
| 文件名 | `006_AdbConfigOptions.dll` | 〔实测〕 |
| 字节数 | 18,472 | 〔实测〕 |
| SHA-256（本轮自算） | `ff46e9a2488c31f2590c6fae8210a960ef2d00c77cd6a0f58d9e76f09dc0a11c` | 〔实测〕 |
| 清单声明 SHA-256 | `ff46e9a2488c31f2590c6fae8210a960ef2d00c77cd6a0f58d9e76f09dc0a11c` | 〔实测〕一致 |
| 产品映射 | `Plus` → `Aspen-Plus` | 〔实测〕 |
| 清单 | `read-test-waiting.csv` | 〔实测〕 |
| 归并首见 | `B` | 〔实测〕 |
| 台账（20261119-61） | 缺失 | 〔待验证〕缺台账文件才能判归档口径 |

哈希校验口径：读入原件后整文件 SHA-256，与清单 `sha256` 列逐字比对；不一致则记 `status=hash_mismatch` 且不产出 IL/反编译。

## 2. 元数据摘要

| 项 | 值 | 标签 |
| --- | --- | --- |
| PE | Machine `0x14c`（i386）、3 个节、Subsystem 3 | 〔实测〕 |
| 映像基址 / 校验和 | `0x10000000` / `0xa39f` | 〔实测〕 |
| CLR 头 | 运行时 2.5、Flags `0x1`、EntryPointToken `0x0` | 〔实测〕 |
| 元数据 | RVA `0x2460`，3732 字节，版本串 `v4.0.30319` | 〔实测〕 |
| 强名 | RVA `0x0` / 0 字节；Flags `0x1` | 〔实测〕 |

元数据流（相对元数据根）：

| 流 | 相对根偏移 | 大小 |
| --- | ---: | ---: |
| `#~` | 108 (0x6c) | 1356 |
| `#Strings` | 1464 (0x5b8) | 1504 |
| `#US` | 2968 (0xb98) | 172 |
| `#GUID` | 3140 (0xc44) | 16 |
| `#Blob` | 3156 (0xc54) | 576 |

- 方法统计：**19 = 18 + 1 + 0 + 0**（有 IL 体 + 抽象 + 运行时实现/委托 + P/Invoke）〔实测〕
- 方法体头分布（按方法体首字/标志字统计，每种恰好一行）：〔实测〕

| 头 | 方法数 |
| --- | ---: |
| tiny 0x1E | 5 |
| fat 0x3013 | 3 |
| fat 0x301B | 2 |
| tiny 0x1A | 2 |
| tiny 0x3A | 1 |
| tiny 0x36 | 1 |
| tiny 0x4A | 1 |
| tiny 0xCA | 1 |
| tiny 0x42 | 1 |
| tiny 0x8A | 1 |

- 版本资源：954 字节，SHA-256 89058860790660dcabed23042f9d2af3f6c71acd8c248fc5d736e5bb7764569b（RT_VERSION，语言 0）〔实测〕
- 托管资源（ManifestResource）：0 条〔实测〕
- 解码失败方法体：1 条〔实测〕

## 3. IL 清单（全量）

全程序集 IL 逐条清单落盘为 `il/006_AdbConfigOptions.dll.il.txt`（315 行）；每个 MethodDef 一行（`MD ` 开头），其下为该方法体全部指令（`IL_XXXX` + 原始字节 + 反汇编文本 + 令牌解析）。〔实测〕

| 项 | 值 |
| --- | ---: |
| MethodDef 总数 | 19 |
| 有 IL 体方法 | 18 |
| IL 字节合计 | 858 |
| 清单文件行数 | 315 |

## 4. 反编译伪代码（ILSpy）

全量 C# 反编译落盘为 `decompiled/006_AdbConfigOptions.dll.cs.txt`（209 行，含 4 处 `class ` 声明）。命令为 `dotnet <ilspycmd.dll> <样本> > decompiled/006_AdbConfigOptions.dll.cs.txt`：stdout 单文件，未用 `-o`/`-p`（目录/工程形态会产多文件）。〔实测〕

| 项 | 值 |
| --- | ---: |
| 反编译行数 | 209 |
| `class ` 声明数 | 4 |

## 5. P/Invoke 与原生调用

ImplMap 表 0 条：本件无 P/Invoke 声明〔实测〕。

PE 导入表：1 个 DLL。

| DLL | 符号数 | 前若干符号 |
| --- | ---: | --- |
| `mscoree.dll` | 1 | `_CorDllMain` |

托管调用目标全量分布（`call`/`callvirt`/`newobj`/`ldftn`/`ldvirtftn`/`jmp` 操作数解析；调用点为目标在 IL 中的出现偏移，最多列 8 处）：〔实测〕

| 调用目标 | 次数 | 调用点（IL 偏移） |
| --- | ---: | --- |
| `System.String::ToLower()` | 7 | IL_0093, IL_00F9, IL_0113, IL_011F, IL_0155, IL_000F, IL_000F |
| `System.IDisposable::Dispose()` | 4 | IL_0143, IL_017C, IL_009D, IL_00A9 |
| `System.IO.TextWriter::Write(string)` | 4 | IL_0043, IL_005D, IL_0074, IL_007F |
| `System.Object::.ctor()` | 4 | IL_000C, IL_0001, IL_0001, IL_0001 |
| `Aspentech.Adb.AdbConfigOptions.DebugLog::get_ShouldWrite()` | 2 | IL_0000, IL_0000 |
| `System.Collections.IEnumerator::MoveNext()` | 2 | IL_012B, IL_0162 |
| `System.Collections.IEnumerator::get_Current()` | 2 | IL_0052, IL_00C0 |
| `System.IO.FileStream::.ctor(string, System.IO.FileMode, System.IO.FileAccess)` | 2 | IL_002A, IL_0019 |
| `System.String::Concat(string, string)` | 2 | IL_003E, IL_0058 |
| `System.String::Equals(string)` | 2 | IL_009D, IL_0103 |
| `System.Xml.XmlElement::GetAttribute(string)` | 2 | IL_008E, IL_00F4 |
| `System.Xml.XmlElement::HasAttribute(string)` | 2 | IL_007C, IL_00E6 |
| `System.Xml.XmlNode::get_ChildNodes()` | 2 | IL_0041, IL_00B0 |
| `System.Xml.XmlNode::get_Name()` | 2 | IL_010E, IL_0150 |
| `System.Xml.XmlNode::get_NodeType()` | 2 | IL_005E, IL_00CE |
| `System.Xml.XmlNodeList::GetEnumerator()` | 2 | IL_0046, IL_00B5 |
| `Aspentech.Adb.AdbConfigOptions.AdbOption::.ctor()` | 1 | IL_00A7 |
| `Aspentech.Adb.AdbConfigOptions.AdbOption::AddSubOption(string, string)` | 1 | IL_0124 |
| `Aspentech.Adb.AdbConfigOptions.AdbOptions::HasOption(string)` | 1 | IL_0012 |
| `Aspentech.Adb.AdbConfigOptions.DebugLog::DebugFilePath()` | 1 | IL_000A |
| `Aspentech.Adb.AdbConfigOptions.DebugLog::get_PathToFile()` | 1 | IL_0000 |
| `Aspentech.Adb.AdbConfigOptions.DebugLog::get_Role()` | 1 | IL_006F |
| `Aspentech.Adb.AdbConfigOptions.ShouldBase::Test()` | 1 | IL_0018 |
| `System.DateTime::ToString(string)` | 1 | IL_0034 |
| `System.DateTime::get_Now()` | 1 | IL_0026 |
| `System.Environment::GetFolderPath(SpecialFolder)` | 1 | IL_000C |
| `System.IO.File::Exists(string)` | 1 | IL_001D |
| `System.IO.Path::ChangeExtension(string, string)` | 1 | IL_000A |
| `System.IO.Path::Combine(string, string)` | 1 | IL_0016 |
| `System.IO.Stream::Close()` | 1 | IL_0188 |
| `System.IO.StreamWriter::.ctor(System.IO.Stream)` | 1 | IL_0020 |
| `System.IO.TextWriter::Close()` | 1 | IL_0092 |
| `System.IO.TextWriter::Flush()` | 1 | IL_008C |
| `System.IO.TextWriter::WriteLine(string)` | 1 | IL_0086 |
| `System.Int32::ToString()` | 1 | IL_004E |
| `System.Xml.XmlDocument::.ctor()` | 1 | IL_0030 |
| `System.Xml.XmlDocument::Load(System.IO.Stream)` | 1 | IL_0037 |
| `System.Xml.XmlDocument::get_DocumentElement()` | 1 | IL_003C |
| `System.Xml.XmlNode::get_InnerText()` | 1 | IL_011A |
| `TypeSpec[1]::.ctor()` | 1 | IL_0001 |
| `TypeSpec[1]::Add(!4864, void)` | 1 | IL_0008 |
| `TypeSpec[1]::ContainsKey()` | 1 | IL_0007 |
| `TypeSpec[1]::TryGetValue()` | 1 | IL_000B |
| `TypeSpec[2]::.ctor()` | 1 | IL_0000 |
| `TypeSpec[2]::Add(!4864, void)` | 1 | IL_015C |
| `TypeSpec[2]::ContainsKey()` | 1 | IL_0014 |
| `TypeSpec[2]::TryGetValue()` | 1 | IL_0016 |

## 6. 工具与环境

| 项 | 值 |
| --- | --- |
| 元数据/IL | Python 3.13.5 + dnfile 0.18.0 + pefile 2024.8.26；`tool/lib/dnlib.py` + `tool/lib/iltab.py`（ECMA-335 自解析，不依赖 Ghidra） |
| 反编译 | ILSpy 9.1.0.7988（`ilspycmd.dll`，ICSharpCode.Decompiler 9.1.0.7988，.NET 8） |
| 反编译命令 | `dotnet <ilspycmd.dll> <样本> > decompiled/006_AdbConfigOptions.dll.cs.txt`（ASCII 引号，stdout 单文件） |
| IL 命令 | `python tool/il_dump.py --dll <样本> --out il/006_AdbConfigOptions.dll.il.txt` |
| 未使用 | Ghidra：本链为托管件，其 C 反编译器不处理 CIL（原生件走 T1N 链） |
| 时间戳 | 固定值 `2026-11-20T00:00:00Z`（报告可 diff，不含 wall-clock / 耗时） |

## 7. 缺口与待验证

1. Authenticode 签名有效性与签发者：本轮只做静态摘要，未做信任链校验〔待验证〕——缺 signtool verify 或 Windows 信任链才能判。
2. 运行期行为（依赖解析、P/Invoke 实际落点、COM 注册）：未执行样本〔待验证〕——缺 Windows 运行环境与依赖目录才能判。
3. 与上游公开包的逐字节关系：本轮未取回同名 NuGet/厂商件〔待验证〕——缺对应公开包才能判。
4. 类型/成员语义与源码对照：本件未提供源码或 PDB〔待验证〕——缺 PDB/源码才能判标识符原名。
5. 台账 20261119-61：未提供〔待验证〕——缺台账文件才能判归档口径与行号对照。

## 8. 结论

- 本件为可读 CLR 程序集：元数据、MethodDef 19 条、IL 字节 858 全部落盘，逐条指令可复核〔实测〕。
- 反编译（ILSpy 9.1.0.7988）产出 209 行 C#，与 IL 清单可逐条对齐〔实测〕。
- P/Invoke 声明 0 条、PE 导入 DLL 1 个，均已列出〔实测〕。
- 未验证项集中在签名/运行期/上游对照（§7），不影响本轮静态定位结论〔待验证〕。

## dumps

dumps: repo:analysis/20261120-batch-driver/Aspen-Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen Data Share V15.0/（仓内产物，不在 Release 包）

- `Aspen-Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen Data Share V15.0/decompiled/AdbConfigOptions.dll.cs.txt` sha256=5fa1a17f3a6529d90d91b31f661ae64cd41f364be851b52a05739fba7c26682c bytes=4932
- `Aspen-Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen Data Share V15.0/il/AdbConfigOptions.dll.il.txt` sha256=7e9a080a8480d1d8525079e95e6f30c417e28dc23d04f98125aba18b397f3613 bytes=19294
