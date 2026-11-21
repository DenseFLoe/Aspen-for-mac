# 020_AspenTech.HtmlHelp.StrongNameInvoke.dll 静态复核报告（Aspen-Plus / 全程序集 IL + C# 反编译）

样本别名：`020_AspenTech.HtmlHelp.StrongNameInvoke.dll`（清单 read-test-waiting.csv（schema B），原件目录只读、未上传）
来源：分支 codex/waiting-for-tietoumao｜git_blob de470716c72c｜自算 sha256 02826aae6dfd55ee302126d19925cd9cc9660dd701a8679ec301a1dbc6aa5c8a｜台账 20261119-61 缺失〔待验证〕
落点：`01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/`（相对 `out/R1`）｜定位规则：`local-rel`

标签约定：〔实测〕= 本轮独立实测（有命令与原始输出）；〔待验证〕= 尚未取得证据或需 Windows 环境。

## 0. 摘要

| 项目 | 结果 | 依据 |
| --- | --- | --- |
| 实际样本 | 20,632 字节（20,632），SHA-256 `02826aae6dfd55ee302126d19925cd9cc9660dd701a8679ec301a1dbc6aa5c8a` | 〔实测〕自算 |
| 程序集身份 | CLR 元数据 `v4.0.30319`；流 5 个；强名 RVA `0x3850` / 128 字节 | 〔实测〕 |
| 方法统计 | 19 = 18（有 IL 体）+ 1（抽象）+ 0（运行时实现/委托）+ 0（P/Invoke） | 〔实测〕 |
| IL 清单 | `il/020_AspenTech.HtmlHelp.StrongNameInvoke.dll.il.txt`，468 行，MethodDef 19 条（全量，逐条指令） | 〔实测〕 |
| 反编译 | `decompiled/020_AspenTech.HtmlHelp.StrongNameInvoke.dll.cs.txt`，284 行（ILSpy 9.1.0.7988 全量 stdout） | 〔实测〕 |
| 原生调用 | ImplMap 0 条；PE 导入表 0 个 DLL | 〔实测〕 |
| 缺口 | 见 §7（签名有效性、运行期行为未验证） | 〔待验证〕 |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

## 1. 样本与哈希

| 项 | 值 | 标签 |
| --- | --- | --- |
| 文件名 | `020_AspenTech.HtmlHelp.StrongNameInvoke.dll` | 〔实测〕 |
| 字节数 | 20,632 | 〔实测〕 |
| SHA-256（本轮自算） | `02826aae6dfd55ee302126d19925cd9cc9660dd701a8679ec301a1dbc6aa5c8a` | 〔实测〕 |
| 清单声明 SHA-256 | `02826aae6dfd55ee302126d19925cd9cc9660dd701a8679ec301a1dbc6aa5c8a` | 〔实测〕一致 |
| 产品映射 | `Plus` → `Aspen-Plus` | 〔实测〕 |
| 清单 | `read-test-waiting.csv` | 〔实测〕 |
| 归并首见 | `B` | 〔实测〕 |
| 台账（20261119-61） | 缺失 | 〔待验证〕缺台账文件才能判归档口径 |

哈希校验口径：读入原件后整文件 SHA-256，与清单 `sha256` 列逐字比对；不一致则记 `status=hash_mismatch` 且不产出 IL/反编译。

## 2. 元数据摘要

| 项 | 值 | 标签 |
| --- | --- | --- |
| PE | Machine `0x8664`（amd64）、2 个节、Subsystem 3 | 〔实测〕 |
| 映像基址 / 校验和 | `0x180000000` / `0xf27e` | 〔实测〕 |
| CLR 头 | 运行时 2.5、Flags `0x9`、EntryPointToken `0x0` | 〔实测〕 |
| 元数据 | RVA `0x26bc`，4500 字节，版本串 `v4.0.30319` | 〔实测〕 |
| 强名 | RVA `0x3850` / 128 字节；Flags `0x9` | 〔实测〕 |

元数据流（相对元数据根）：

| 流 | 相对根偏移 | 大小 |
| --- | ---: | ---: |
| `#~` | 108 (0x6c) | 1324 |
| `#Strings` | 1432 (0x598) | 1816 |
| `#US` | 3248 (0xcb0) | 556 |
| `#GUID` | 3804 (0xedc) | 16 |
| `#Blob` | 3820 (0xeec) | 680 |

- 方法统计：**19 = 18 + 1 + 0 + 0**（有 IL 体 + 抽象 + 运行时实现/委托 + P/Invoke）〔实测〕
- 方法体头分布（按方法体首字/标志字统计，每种恰好一行）：〔实测〕

| 头 | 方法数 |
| --- | ---: |
| fat 0x301B | 9 |
| fat 0x3013 | 4 |
| tiny 0x1E | 2 |
| tiny 0x2E | 1 |
| tiny 0x22 | 1 |
| tiny 0x4A | 1 |

- 版本资源：1116 字节，SHA-256 870291a75c17ae8d1077107cb2f03f5d6359c1f79e77b913146a5cdb96257805（RT_VERSION，语言 0）〔实测〕
- 托管资源（ManifestResource）：0 条〔实测〕
- 解码失败方法体：1 条〔实测〕

## 3. IL 清单（全量）

全程序集 IL 逐条清单落盘为 `il/020_AspenTech.HtmlHelp.StrongNameInvoke.dll.il.txt`（468 行）；每个 MethodDef 一行（`MD ` 开头），其下为该方法体全部指令（`IL_XXXX` + 原始字节 + 反汇编文本 + 令牌解析）。〔实测〕

| 项 | 值 |
| --- | ---: |
| MethodDef 总数 | 19 |
| 有 IL 体方法 | 18 |
| IL 字节合计 | 1,314 |
| 清单文件行数 | 468 |

## 4. 反编译伪代码（ILSpy）

全量 C# 反编译落盘为 `decompiled/020_AspenTech.HtmlHelp.StrongNameInvoke.dll.cs.txt`（284 行，含 4 处 `class ` 声明）。命令为 `dotnet <ilspycmd.dll> <样本> > decompiled/020_AspenTech.HtmlHelp.StrongNameInvoke.dll.cs.txt`：stdout 单文件，未用 `-o`/`-p`（目录/工程形态会产多文件）。〔实测〕

| 项 | 值 |
| --- | ---: |
| 反编译行数 | 284 |
| `class ` 声明数 | 4 |

## 5. P/Invoke 与原生调用

ImplMap 表 0 条：本件无 P/Invoke 声明〔实测〕。

PE 导入表：0 个 DLL。

PE 导入目录为空或不可读〔实测〕。

托管调用目标全量分布（`call`/`callvirt`/`newobj`/`ldftn`/`ldvirtftn`/`jmp` 操作数解析；调用点为目标在 IL 中的出现偏移，最多列 8 处）：〔实测〕

| 调用目标 | 次数 | 调用点（IL 偏移） |
| --- | ---: | --- |
| `System.Reflection.MemberInfo::get_Name()` | 19 | IL_00A1, IL_00AB, IL_00CF, IL_00D9, IL_0005, IL_0014, IL_001E, IL_0040 |
| `System.Reflection.MethodBase::GetCurrentMethod()` | 10 | IL_00A6, IL_00D4, IL_0000, IL_0019, IL_0045, IL_003B, IL_004A, IL_004A |
| `AspenTech.HtmlHelp.StrongNameInvoke.Util.UtilError::WriteToEventLog(string, string, string)` | 9 | IL_00B0, IL_00DE, IL_0023, IL_004F, IL_0045, IL_0054, IL_0054, IL_0054 |
| `System.Exception::get_Message()` | 9 | IL_0092, IL_00B6, IL_00C0, IL_0031, IL_0027, IL_0036, IL_0036, IL_0036 |
| `System.Type::GetTypeFromHandle(System.RuntimeTypeHandle)` | 9 | IL_009C, IL_00CA, IL_000F, IL_003B, IL_0031, IL_0040, IL_0040, IL_0040 |
| `System.Type::InvokeMember(string, System.Reflection.BindingFlags, System.Reflection.Binder, object, object[])` | 9 | IL_0063, IL_004A, IL_0054, IL_0029, IL_001F, IL_002E, IL_002E, IL_002E |
| `System.DateTime::get_Now()` | 4 | IL_000A, IL_0000, IL_002B, IL_003D |
| `System.IO.TextWriter::WriteLine(string)` | 4 | IL_004F, IL_0066, IL_0077, IL_0082 |
| `System.DateTime::ToString(string)` | 2 | IL_0017, IL_000D |
| `System.Object::.ctor()` | 2 | IL_0001, IL_000C |
| `System.String::Concat(string, string, string)` | 2 | IL_0021, IL_004A |
| `AspenTech.HtmlHelp.StrongNameInvoke.Classes.LogWriter::.ctor()` | 1 | IL_0007 |
| `AspenTech.HtmlHelp.StrongNameInvoke.Classes.LogWriter::WriteToLog(string, string, string)` | 1 | IL_0019 |
| `AspenTech.HtmlHelp.StrongNameInvoke.Util.Global::GetLogFilename()` | 1 | IL_0001 |
| `System.Activator::CreateInstance(System.Type)` | 1 | IL_0085 |
| `System.Console::WriteLine(string)` | 1 | IL_00BB |
| `System.DateTime::ToLongDateString()` | 1 | IL_0045 |
| `System.DateTime::ToLongTimeString()` | 1 | IL_0033 |
| `System.IDisposable::Dispose()` | 1 | IL_008D |
| `System.IO.File::AppendText(string)` | 1 | IL_0019 |
| `System.IO.Path::Combine(string, string)` | 1 | IL_0026 |
| `System.IO.Path::GetTempPath()` | 1 | IL_0000 |
| `System.IO.TextWriter::Write(string)` | 1 | IL_0025 |
| `System.Object::ToString()` | 1 | IL_0095 |
| `System.String::Concat(string, string)` | 1 | IL_0072 |
| `System.String::Concat(string, string, string, string)` | 1 | IL_0061 |
| `System.Type::GetTypeFromProgID(string)` | 1 | IL_0069 |
| `System.Type::op_Inequality(System.Type, System.Type)` | 1 | IL_0079 |

## 6. 工具与环境

| 项 | 值 |
| --- | --- |
| 元数据/IL | Python 3.13.5 + dnfile 0.18.0 + pefile 2024.8.26；`tool/lib/dnlib.py` + `tool/lib/iltab.py`（ECMA-335 自解析，不依赖 Ghidra） |
| 反编译 | ILSpy 9.1.0.7988（`ilspycmd.dll`，ICSharpCode.Decompiler 9.1.0.7988，.NET 8） |
| 反编译命令 | `dotnet <ilspycmd.dll> <样本> > decompiled/020_AspenTech.HtmlHelp.StrongNameInvoke.dll.cs.txt`（ASCII 引号，stdout 单文件） |
| IL 命令 | `python tool/il_dump.py --dll <样本> --out il/020_AspenTech.HtmlHelp.StrongNameInvoke.dll.il.txt` |
| 未使用 | Ghidra：本链为托管件，其 C 反编译器不处理 CIL（原生件走 T1N 链） |
| 时间戳 | 固定值 `2026-11-20T00:00:00Z`（报告可 diff，不含 wall-clock / 耗时） |

## 7. 缺口与待验证

1. Authenticode 签名有效性与签发者：本轮只做静态摘要，未做信任链校验〔待验证〕——缺 signtool verify 或 Windows 信任链才能判。
2. 运行期行为（依赖解析、P/Invoke 实际落点、COM 注册）：未执行样本〔待验证〕——缺 Windows 运行环境与依赖目录才能判。
3. 与上游公开包的逐字节关系：本轮未取回同名 NuGet/厂商件〔待验证〕——缺对应公开包才能判。
4. 类型/成员语义与源码对照：本件未提供源码或 PDB〔待验证〕——缺 PDB/源码才能判标识符原名。
5. 台账 20261119-61：未提供〔待验证〕——缺台账文件才能判归档口径与行号对照。

## 8. 结论

- 本件为可读 CLR 程序集：元数据、MethodDef 19 条、IL 字节 1,314 全部落盘，逐条指令可复核〔实测〕。
- 反编译（ILSpy 9.1.0.7988）产出 284 行 C#，与 IL 清单可逐条对齐〔实测〕。
- P/Invoke 声明 0 条、PE 导入 DLL 0 个，均已列出〔实测〕。
- 未验证项集中在签名/运行期/上游对照（§7），不影响本轮静态定位结论〔待验证〕。

## dumps

dumps: repo:逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/GUI/Xeq/AspenTech.HtmlHelp.StrongNameInvoke.dll.md/分支交付/

- tool=ILSpy 9.1.0.7988 + dnfile 0.18.0
