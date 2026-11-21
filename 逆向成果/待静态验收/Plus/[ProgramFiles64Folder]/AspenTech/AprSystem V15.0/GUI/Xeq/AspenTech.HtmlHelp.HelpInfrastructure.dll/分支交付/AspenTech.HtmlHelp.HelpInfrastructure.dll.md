# 018_AspenTech.HtmlHelp.HelpInfrastructure.dll 静态复核报告（Aspen-Plus / 全程序集 IL + C# 反编译）

样本别名：`018_AspenTech.HtmlHelp.HelpInfrastructure.dll`（清单 read-test-waiting.csv（schema B），原件目录只读、未上传）
来源：分支 codex/waiting-for-tietoumao｜git_blob 78de4a44cfaa｜自算 sha256 353d4748e2b529f4cbe3008b9da48cd93529d0f4acf798274a77bba07d7e9115｜台账 20261119-61 缺失〔待验证〕
落点：`01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/`（相对 `out/R1`）｜定位规则：`local-rel`

标签约定：〔实测〕= 本轮独立实测（有命令与原始输出）；〔待验证〕= 尚未取得证据或需 Windows 环境。

## 0. 摘要

| 项目 | 结果 | 依据 |
| --- | --- | --- |
| 实际样本 | 18,584 字节（18,584），SHA-256 `353d4748e2b529f4cbe3008b9da48cd93529d0f4acf798274a77bba07d7e9115` | 〔实测〕自算 |
| 程序集身份 | CLR 元数据 `v4.0.30319`；流 5 个；强名 RVA `0x3230` / 128 字节 | 〔实测〕 |
| 方法统计 | 16 = 16（有 IL 体）+ 0（抽象）+ 0（运行时实现/委托）+ 0（P/Invoke） | 〔实测〕 |
| IL 清单 | `il/018_AspenTech.HtmlHelp.HelpInfrastructure.dll.il.txt`，161 行，MethodDef 16 条（全量，逐条指令） | 〔实测〕 |
| 反编译 | `decompiled/018_AspenTech.HtmlHelp.HelpInfrastructure.dll.cs.txt`，144 行（ILSpy 9.1.0.7988 全量 stdout） | 〔实测〕 |
| 原生调用 | ImplMap 0 条；PE 导入表 0 个 DLL | 〔实测〕 |
| 缺口 | 见 §7（签名有效性、运行期行为未验证） | 〔待验证〕 |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

## 1. 样本与哈希

| 项 | 值 | 标签 |
| --- | --- | --- |
| 文件名 | `018_AspenTech.HtmlHelp.HelpInfrastructure.dll` | 〔实测〕 |
| 字节数 | 18,584 | 〔实测〕 |
| SHA-256（本轮自算） | `353d4748e2b529f4cbe3008b9da48cd93529d0f4acf798274a77bba07d7e9115` | 〔实测〕 |
| 清单声明 SHA-256 | `353d4748e2b529f4cbe3008b9da48cd93529d0f4acf798274a77bba07d7e9115` | 〔实测〕一致 |
| 产品映射 | `Plus` → `Aspen-Plus` | 〔实测〕 |
| 清单 | `read-test-waiting.csv` | 〔实测〕 |
| 归并首见 | `B` | 〔实测〕 |
| 台账（20261119-61） | 缺失 | 〔待验证〕缺台账文件才能判归档口径 |

哈希校验口径：读入原件后整文件 SHA-256，与清单 `sha256` 列逐字比对；不一致则记 `status=hash_mismatch` 且不产出 IL/反编译。

## 2. 元数据摘要

| 项 | 值 | 标签 |
| --- | --- | --- |
| PE | Machine `0x8664`（amd64）、2 个节、Subsystem 3 | 〔实测〕 |
| 映像基址 / 校验和 | `0x180000000` / `0x121b9` | 〔实测〕 |
| CLR 头 | 运行时 2.5、Flags `0x9`、EntryPointToken `0x0` | 〔实测〕 |
| 元数据 | RVA `0x21f8`，4152 字节，版本串 `v4.0.30319` | 〔实测〕 |
| 强名 | RVA `0x3230` / 128 字节；Flags `0x9` | 〔实测〕 |

元数据流（相对元数据根）：

| 流 | 相对根偏移 | 大小 |
| --- | ---: | ---: |
| `#~` | 108 (0x6c) | 1388 |
| `#Strings` | 1496 (0x5d8) | 1812 |
| `#US` | 3308 (0xcec) | 116 |
| `#GUID` | 3424 (0xd60) | 16 |
| `#Blob` | 3440 (0xd70) | 712 |

- 方法统计：**16 = 16 + 0 + 0 + 0**（有 IL 体 + 抽象 + 运行时实现/委托 + P/Invoke）〔实测〕
- 方法体头分布（按方法体首字/标志字统计，每种恰好一行）：〔实测〕

| 头 | 方法数 |
| --- | ---: |
| tiny 0x1E | 7 |
| tiny 0x3A | 3 |
| tiny 0x22 | 3 |
| fat 0x3013 | 1 |
| fat 0x301B | 1 |
| tiny 0x1A | 1 |

- 版本资源：1132 字节，SHA-256 5a158e8a8292277d5944a013796a13b3250a929d327a30438fc560aaa09023b4（RT_VERSION，语言 0）〔实测〕
- 托管资源（ManifestResource）：0 条〔实测〕
- 解码失败方法体：1 条〔实测〕

## 3. IL 清单（全量）

全程序集 IL 逐条清单落盘为 `il/018_AspenTech.HtmlHelp.HelpInfrastructure.dll.il.txt`（161 行）；每个 MethodDef 一行（`MD ` 开头），其下为该方法体全部指令（`IL_XXXX` + 原始字节 + 反汇编文本 + 令牌解析）。〔实测〕

| 项 | 值 |
| --- | ---: |
| MethodDef 总数 | 16 |
| 有 IL 体方法 | 16 |
| IL 字节合计 | 365 |
| 清单文件行数 | 161 |

## 4. 反编译伪代码（ILSpy）

全量 C# 反编译落盘为 `decompiled/018_AspenTech.HtmlHelp.HelpInfrastructure.dll.cs.txt`（144 行，含 8 处 `class ` 声明）。命令为 `dotnet <ilspycmd.dll> <样本> > decompiled/018_AspenTech.HtmlHelp.HelpInfrastructure.dll.cs.txt`：stdout 单文件，未用 `-o`/`-p`（目录/工程形态会产多文件）。〔实测〕

| 项 | 值 |
| --- | ---: |
| 反编译行数 | 144 |
| `class ` 声明数 | 8 |

## 5. P/Invoke 与原生调用

ImplMap 表 0 条：本件无 P/Invoke 声明〔实测〕。

PE 导入表：0 个 DLL。

PE 导入目录为空或不可读〔实测〕。

托管调用目标全量分布（`call`/`callvirt`/`newobj`/`ldftn`/`ldvirtftn`/`jmp` 操作数解析；调用点为目标在 IL 中的出现偏移，最多列 8 处）：〔实测〕

| 调用目标 | 次数 | 调用点（IL 偏移） |
| --- | ---: | --- |
| `System.EventArgs::.ctor()` | 3 | IL_0001, IL_0001, IL_0001 |
| `System.Object::.ctor()` | 2 | IL_0001, IL_0001 |
| `AspenTech.HtmlHelp.HelpInfrastructure.HtmlHelpCefLibMgr::.ctor()` | 1 | IL_0007 |
| `AspenTech.HtmlHelp.HelpInfrastructure.HtmlHelpNavigateToEventArgs::set_HelpTopicUrl(string)` | 1 | IL_0008 |
| `AspenTech.HtmlHelp.HelpInfrastructure.HtmlHelpShowHelpViewerEventArgs::set_HelpFileRelativeURL(string)` | 1 | IL_0008 |
| `AspenTech.HtmlHelp.HelpInfrastructure.HtmlHelpViewerNavigatingEventArgs::set_HelpFileRelativeURL(string)` | 1 | IL_0008 |
| `CefSharp.Cef::Initialize(CefSharp.CefSettingsBase, bool, CefSharp.IBrowserProcessHandler)` | 1 | IL_009C |
| `CefSharp.Cef::Shutdown()` | 1 | IL_0000 |
| `CefSharp.Cef::get_IsInitialized()` | 1 | IL_0092 |
| `CefSharp.CefSettingsBase::get_CefCommandLineArgs()` | 1 | IL_007E |
| `CefSharp.CefSettingsBase::set_BrowserSubprocessPath(string)` | 1 | IL_0060 |
| `CefSharp.CefSettingsBase::set_CachePath(string)` | 1 | IL_0077 |
| `CefSharp.CefSettingsBase::set_IgnoreCertificateErrors(bool)` | 1 | IL_0067 |
| `CefSharp.CefSettingsBase::set_LogSeverity(CefSharp.LogSeverity)` | 1 | IL_0055 |
| `CefSharp.Wpf.CefSettings::.ctor()` | 1 | IL_004D |
| `System.Console::WriteLine(object)` | 1 | IL_0045 |
| `System.Environment::GetFolderPath(SpecialFolder, SpecialFolderOption)` | 1 | IL_0018 |
| `System.IO.Directory::CreateDirectory(string)` | 1 | IL_0038 |
| `System.IO.FileInfo::.ctor(string)` | 1 | IL_0018 |
| `System.IO.FileInfo::get_DirectoryName()` | 1 | IL_0022 |
| `System.IO.FileSystemInfo::get_FullName()` | 1 | IL_003D |
| `System.IO.Path::Combine(string, string)` | 1 | IL_0036 |
| `System.Object::GetType()` | 1 | IL_0007 |
| `System.Reflection.Assembly::get_Location()` | 1 | IL_0011 |
| `System.String::Concat(string, string)` | 1 | IL_0033 |
| `System.String::IsNullOrWhiteSpace(string)` | 1 | IL_0029 |
| `System.Type::get_Assembly()` | 1 | IL_000C |
| `TypeSpec[1]::.ctor()` | 1 | IL_0001 |
| `TypeSpec[2]::.ctor()` | 1 | IL_0001 |
| `TypeSpec[3]::.ctor()` | 1 | IL_0001 |
| `TypeSpec[4]::Add(!4864, void)` | 1 | IL_008D |

## 6. 工具与环境

| 项 | 值 |
| --- | --- |
| 元数据/IL | Python 3.13.5 + dnfile 0.18.0 + pefile 2024.8.26；`tool/lib/dnlib.py` + `tool/lib/iltab.py`（ECMA-335 自解析，不依赖 Ghidra） |
| 反编译 | ILSpy 9.1.0.7988（`ilspycmd.dll`，ICSharpCode.Decompiler 9.1.0.7988，.NET 8） |
| 反编译命令 | `dotnet <ilspycmd.dll> <样本> > decompiled/018_AspenTech.HtmlHelp.HelpInfrastructure.dll.cs.txt`（ASCII 引号，stdout 单文件） |
| IL 命令 | `python tool/il_dump.py --dll <样本> --out il/018_AspenTech.HtmlHelp.HelpInfrastructure.dll.il.txt` |
| 未使用 | Ghidra：本链为托管件，其 C 反编译器不处理 CIL（原生件走 T1N 链） |
| 时间戳 | 固定值 `2026-11-20T00:00:00Z`（报告可 diff，不含 wall-clock / 耗时） |

## 7. 缺口与待验证

1. Authenticode 签名有效性与签发者：本轮只做静态摘要，未做信任链校验〔待验证〕——缺 signtool verify 或 Windows 信任链才能判。
2. 运行期行为（依赖解析、P/Invoke 实际落点、COM 注册）：未执行样本〔待验证〕——缺 Windows 运行环境与依赖目录才能判。
3. 与上游公开包的逐字节关系：本轮未取回同名 NuGet/厂商件〔待验证〕——缺对应公开包才能判。
4. 类型/成员语义与源码对照：本件未提供源码或 PDB〔待验证〕——缺 PDB/源码才能判标识符原名。
5. 台账 20261119-61：未提供〔待验证〕——缺台账文件才能判归档口径与行号对照。

## 8. 结论

- 本件为可读 CLR 程序集：元数据、MethodDef 16 条、IL 字节 365 全部落盘，逐条指令可复核〔实测〕。
- 反编译（ILSpy 9.1.0.7988）产出 144 行 C#，与 IL 清单可逐条对齐〔实测〕。
- P/Invoke 声明 0 条、PE 导入 DLL 0 个，均已列出〔实测〕。
- 未验证项集中在签名/运行期/上游对照（§7），不影响本轮静态定位结论〔待验证〕。
