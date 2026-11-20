# 053_AspenHelper.dll 静态复核报告（Aspen-Plus / 全程序集 IL + C# 反编译）

样本别名：`053_AspenHelper.dll`（清单 read-test-waiting.csv（schema B），原件目录只读、未上传）
来源：分支 codex/waiting-for-tietoumao｜git_blob 741f7904db25｜自算 sha256 5b6e34442388e8a193fd1d2a44f345e3310690c76ea7e83192fa97455728ff4f｜台账 20261119-61 缺失〔待验证〕
落点：`01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/Converter V15.0/`（相对 `out/R1`）｜定位规则：`local-rel`

标签约定：〔实测〕= 本轮独立实测（有命令与原始输出）；〔待验证〕= 尚未取得证据或需 Windows 环境。

## 0. 摘要

| 项目 | 结果 | 依据 |
| --- | --- | --- |
| 实际样本 | 19,400 字节（19,400），SHA-256 `5b6e34442388e8a193fd1d2a44f345e3310690c76ea7e83192fa97455728ff4f` | 〔实测〕自算 |
| 程序集身份 | CLR 元数据 `v4.0.30319`；流 5 个；强名 RVA `0x0` / 0 字节 | 〔实测〕 |
| 方法统计 | 17 = 17（有 IL 体）+ 0（抽象）+ 0（运行时实现/委托）+ 0（P/Invoke） | 〔实测〕 |
| IL 清单 | `il/053_AspenHelper.dll.il.txt`，458 行，MethodDef 17 条（全量，逐条指令） | 〔实测〕 |
| 反编译 | `decompiled/053_AspenHelper.dll.cs.txt`，252 行（ILSpy 9.1.0.7988 全量 stdout） | 〔实测〕 |
| 原生调用 | ImplMap 0 条；PE 导入表 0 个 DLL | 〔实测〕 |
| 缺口 | 见 §7（签名有效性、运行期行为未验证） | 〔待验证〕 |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

## 1. 样本与哈希

| 项 | 值 | 标签 |
| --- | --- | --- |
| 文件名 | `053_AspenHelper.dll` | 〔实测〕 |
| 字节数 | 19,400 | 〔实测〕 |
| SHA-256（本轮自算） | `5b6e34442388e8a193fd1d2a44f345e3310690c76ea7e83192fa97455728ff4f` | 〔实测〕 |
| 清单声明 SHA-256 | `5b6e34442388e8a193fd1d2a44f345e3310690c76ea7e83192fa97455728ff4f` | 〔实测〕一致 |
| 产品映射 | `Plus` → `Aspen-Plus` | 〔实测〕 |
| 清单 | `read-test-waiting.csv` | 〔实测〕 |
| 归并首见 | `B` | 〔实测〕 |
| 台账（20261119-61） | 缺失 | 〔待验证〕缺台账文件才能判归档口径 |

哈希校验口径：读入原件后整文件 SHA-256，与清单 `sha256` 列逐字比对；不一致则记 `status=hash_mismatch` 且不产出 IL/反编译。

## 2. 元数据摘要

| 项 | 值 | 标签 |
| --- | --- | --- |
| PE | Machine `0x8664`（amd64）、2 个节、Subsystem 3 | 〔实测〕 |
| 映像基址 / 校验和 | `0x180000000` / `0xbdc9` | 〔实测〕 |
| CLR 头 | 运行时 2.5、Flags `0x1`、EntryPointToken `0x0` | 〔实测〕 |
| 元数据 | RVA `0x24d0`，4248 字节，版本串 `v4.0.30319` | 〔实测〕 |
| 强名 | RVA `0x0` / 0 字节；Flags `0x1` | 〔实测〕 |

元数据流（相对元数据根）：

| 流 | 相对根偏移 | 大小 |
| --- | ---: | ---: |
| `#~` | 108 (0x6c) | 1400 |
| `#Strings` | 1508 (0x5e4) | 1656 |
| `#US` | 3164 (0xc5c) | 332 |
| `#GUID` | 3496 (0xda8) | 16 |
| `#Blob` | 3512 (0xdb8) | 736 |

- 方法统计：**17 = 17 + 0 + 0 + 0**（有 IL 体 + 抽象 + 运行时实现/委托 + P/Invoke）〔实测〕
- 方法体头分布（按方法体首字/标志字统计，每种恰好一行）：〔实测〕

| 头 | 方法数 |
| --- | ---: |
| fat 0x3013 | 6 |
| fat 0x301B | 2 |
| tiny 0x1E | 2 |
| tiny 0x22 | 2 |
| tiny 0xDE | 1 |
| tiny 0x72 | 1 |
| tiny 0xE2 | 1 |
| tiny 0x76 | 1 |
| tiny 0x5E | 1 |

- 版本资源：910 字节，SHA-256 401550ba69657f3cd0a4e7856fb9e034eeb9a8c414185afe57c2d50023132f1e（RT_VERSION，语言 0）〔实测〕
- 托管资源（ManifestResource）：0 条〔实测〕
- 解码失败方法体：1 条〔实测〕

## 3. IL 清单（全量）

全程序集 IL 逐条清单落盘为 `il/053_AspenHelper.dll.il.txt`（458 行）；每个 MethodDef 一行（`MD ` 开头），其下为该方法体全部指令（`IL_XXXX` + 原始字节 + 反汇编文本 + 令牌解析）。〔实测〕

| 项 | 值 |
| --- | ---: |
| MethodDef 总数 | 17 |
| 有 IL 体方法 | 17 |
| IL 字节合计 | 1,003 |
| 清单文件行数 | 458 |

## 4. 反编译伪代码（ILSpy）

全量 C# 反编译落盘为 `decompiled/053_AspenHelper.dll.cs.txt`（252 行，含 2 处 `class ` 声明）。命令为 `dotnet <ilspycmd.dll> <样本> > decompiled/053_AspenHelper.dll.cs.txt`：stdout 单文件，未用 `-o`/`-p`（目录/工程形态会产多文件）。〔实测〕

| 项 | 值 |
| --- | ---: |
| 反编译行数 | 252 |
| `class ` 声明数 | 2 |

## 5. P/Invoke 与原生调用

ImplMap 表 0 条：本件无 P/Invoke 声明〔实测〕。

PE 导入表：0 个 DLL。

PE 导入目录为空或不可读〔实测〕。

托管调用目标全量分布（`call`/`callvirt`/`newobj`/`ldftn`/`ldvirtftn`/`jmp` 操作数解析；调用点为目标在 IL 中的出现偏移，最多列 8 处）：〔实测〕

| 调用目标 | 次数 | 调用点（IL 偏移） |
| --- | ---: | --- |
| `System.String::IndexOf(char, int32)` | 6 | IL_004F, IL_0060, IL_0071, IL_002D, IL_003E, IL_004F |
| `TypeSpec[1]::get_Item()` | 4 | IL_0088, IL_0091, IL_00A1, IL_00AA |
| `System.IO.Stream::Close()` | 3 | IL_001A, IL_001F, IL_00DE |
| `System.Int32::ToString()` | 3 | IL_0001, IL_0013, IL_0029 |
| `System.String::IndexOf(string, int32)` | 3 | IL_002A, IL_0008, IL_001C |
| `System.String::Substring(int32, int32)` | 3 | IL_0085, IL_0023, IL_0063 |
| `AspenHelper.AspenHelper::GetCurrentVersion()` | 2 | IL_000C, IL_000A |
| `Microsoft.Win32.RegistryKey::GetValue(string)` | 2 | IL_0019, IL_0023 |
| `Microsoft.Win32.RegistryKey::OpenSubKey(string)` | 2 | IL_000A, IL_0019 |
| `System.IO.FileStream::.ctor(string, System.IO.FileMode, System.IO.FileAccess)` | 2 | IL_0003, IL_0003 |
| `System.IO.TextReader::Close()` | 2 | IL_0015, IL_001A |
| `System.IO.TextReader::ReadToEnd()` | 2 | IL_000F, IL_0014 |
| `System.Object::.ctor()` | 2 | IL_0001, IL_0017 |
| `System.Object::ToString()` | 2 | IL_001E, IL_0028 |
| `System.String::Concat(string, string)` | 2 | IL_0011, IL_0032 |
| `System.String::IndexOf(string)` | 2 | IL_0025, IL_000C |
| `System.String::Trim()` | 2 | IL_008D, IL_006C |
| `TypeSpec[1]::.ctor()` | 2 | IL_0026, IL_003D |
| `TypeSpec[1]::Add()` | 2 | IL_0062, IL_0071 |
| `AspenHelper.AspenHelper::ConvertBlockName(string, int32&)` | 1 | IL_005D |
| `AspenHelper.AspenHelper::FindBlockName(string&, int32, elem_0x15&)` | 1 | IL_0031 |
| `AspenHelper.AspenHelper::GetStreamName(string&, int32&)` | 1 | IL_0035 |
| `AspenHelper.SingleAspenPlusDataInstance::.ctor()` | 1 | IL_0007 |
| `AspenTech.AspenPlus.Happ.IHapp::Close(object)` | 1 | IL_0014 |
| `AspenTech.AspenPlus.Happ.IHapp::InitFromFile(string&, object)` | 1 | IL_0038 |
| `AspenTech.AspenPlus.Happ.IHapp::SaveAs(string&, object)` | 1 | IL_0016 |
| `AspenTech.AspenPlus.Happ.IHapp::set_Visible(bool)` | 1 | IL_0044 |
| `Microsoft.VisualBasic.Interaction::CreateObject(string, string)` | 1 | IL_001B |
| `System.IDisposable::Dispose()` | 1 | IL_007A |
| `System.IO.FileStream::.ctor(string, System.IO.FileMode)` | 1 | IL_00C7 |
| `System.IO.StreamReader::.ctor(System.IO.Stream)` | 1 | IL_0009 |
| `System.IO.StreamReader::.ctor(System.IO.Stream, System.Text.Encoding)` | 1 | IL_000E |
| `System.IO.StreamWriter::.ctor(System.IO.Stream)` | 1 | IL_00CD |
| `System.IO.TextWriter::Close()` | 1 | IL_00D9 |
| `System.IO.TextWriter::Write(string)` | 1 | IL_00D4 |
| `System.Object::Finalize()` | 1 | IL_0003 |
| `System.Runtime.InteropServices.Marshal::FinalReleaseComObject(object)` | 1 | IL_001F |
| `System.String::Concat(string, string, string)` | 1 | IL_0014 |
| `System.String::Format(string, object, object)` | 1 | IL_002E |
| `System.String::IndexOf(char)` | 1 | IL_004A |
| `System.String::IsNullOrEmpty(string)` | 1 | IL_003C |
| `System.String::Replace(string, string)` | 1 | IL_00AF |
| `System.String::get_Chars(int32)` | 1 | IL_0039 |
| `System.String::get_Length()` | 1 | IL_0006 |
| `System.String::op_Inequality(string, string)` | 1 | IL_0096 |
| `System.Text.Encoding::get_Default()` | 1 | IL_0009 |
| `System.Threading.Thread::Sleep(int32)` | 1 | IL_0031 |
| `TypeSpec[1]::GetEnumerator()` | 1 | IL_0045 |
| `TypeSpec[1]::get_Count()` | 1 | IL_00BE |
| `TypeSpec[2]::MoveNext()` | 1 | IL_0069 |
| `TypeSpec[2]::get_Current()` | 1 | IL_0050 |
| `TypeSpec[3]::.ctor()` | 1 | IL_0001 |
| `TypeSpec[4]::.ctor()` | 1 | IL_000C |

## 6. 工具与环境

| 项 | 值 |
| --- | --- |
| 元数据/IL | Python 3.13.5 + dnfile 0.18.0 + pefile 2024.8.26；`tool/lib/dnlib.py` + `tool/lib/iltab.py`（ECMA-335 自解析，不依赖 Ghidra） |
| 反编译 | ILSpy 9.1.0.7988（`ilspycmd.dll`，ICSharpCode.Decompiler 9.1.0.7988，.NET 8） |
| 反编译命令 | `dotnet <ilspycmd.dll> <样本> > decompiled/053_AspenHelper.dll.cs.txt`（ASCII 引号，stdout 单文件） |
| IL 命令 | `python tool/il_dump.py --dll <样本> --out il/053_AspenHelper.dll.il.txt` |
| 未使用 | Ghidra：本链为托管件，其 C 反编译器不处理 CIL（原生件走 T1N 链） |
| 时间戳 | 固定值 `2026-11-20T00:00:00Z`（报告可 diff，不含 wall-clock / 耗时） |

## 7. 缺口与待验证

1. Authenticode 签名有效性与签发者：本轮只做静态摘要，未做信任链校验〔待验证〕——缺 signtool verify 或 Windows 信任链才能判。
2. 运行期行为（依赖解析、P/Invoke 实际落点、COM 注册）：未执行样本〔待验证〕——缺 Windows 运行环境与依赖目录才能判。
3. 与上游公开包的逐字节关系：本轮未取回同名 NuGet/厂商件〔待验证〕——缺对应公开包才能判。
4. 类型/成员语义与源码对照：本件未提供源码或 PDB〔待验证〕——缺 PDB/源码才能判标识符原名。
5. 台账 20261119-61：未提供〔待验证〕——缺台账文件才能判归档口径与行号对照。

## 8. 结论

- 本件为可读 CLR 程序集：元数据、MethodDef 17 条、IL 字节 1,003 全部落盘，逐条指令可复核〔实测〕。
- 反编译（ILSpy 9.1.0.7988）产出 252 行 C#，与 IL 清单可逐条对齐〔实测〕。
- P/Invoke 声明 0 条、PE 导入 DLL 0 个，均已列出〔实测〕。
- 未验证项集中在签名/运行期/上游对照（§7），不影响本轮静态定位结论〔待验证〕。
