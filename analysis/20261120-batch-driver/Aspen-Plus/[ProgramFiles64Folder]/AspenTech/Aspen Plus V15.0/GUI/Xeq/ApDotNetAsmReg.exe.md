# 052_ApDotNetAsmReg.exe 静态复核报告（Aspen-Plus / 全程序集 IL + C# 反编译）

## 必填字段（T0 口径，逐项可按名检索）

- tool=ILSpy 9.1.0.7988 + dnfile 0.18.0
- functions=N/A（CLR 托管程序集，无 native 函数概念；methods=5）
- decomp_ok=N/A（CLR：无函数级反编译统计）
- decomp_fail=N/A（CLR：无函数级反编译统计）


样本别名：`052_ApDotNetAsmReg.exe`（清单 read-test-waiting.csv（schema B），原件目录只读、未上传）
来源：分支 codex/waiting-for-tietoumao｜git_blob acd0201ad2d1｜自算 sha256 a015bb5b50b2bac2f0c3a53e0923c2c4fab255e8db232efab324d28ad333fa9e｜台账 20261119-61 缺失〔待验证〕
落点：`01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/`（相对 `out/R1`）｜定位规则：`local-rel`

标签约定：〔实测〕= 本轮独立实测（有命令与原始输出）；〔待验证〕= 尚未取得证据或需 Windows 环境。

## 0. 摘要

| 项目 | 结果 | 依据 |
| --- | --- | --- |
| 实际样本 | 17,448 字节（17,448），SHA-256 `a015bb5b50b2bac2f0c3a53e0923c2c4fab255e8db232efab324d28ad333fa9e` | 〔实测〕自算 |
| 程序集身份 | CLR 元数据 `v4.0.30319`；流 5 个；强名 RVA `0x0` / 0 字节 | 〔实测〕 |
| 方法统计 | 5 = 5（有 IL 体）+ 0（抽象）+ 0（运行时实现/委托）+ 0（P/Invoke） | 〔实测〕 |
| IL 清单 | `il/052_ApDotNetAsmReg.exe.il.txt`，221 行，MethodDef 5 条（全量，逐条指令） | 〔实测〕 |
| 反编译 | `decompiled/052_ApDotNetAsmReg.exe.cs.txt`，115 行（ILSpy 9.1.0.7988 全量 stdout） | 〔实测〕 |
| 原生调用 | ImplMap 0 条；PE 导入表 1 个 DLL | 〔实测〕 |
| 缺口 | 见 §7（签名有效性、运行期行为未验证） | 〔待验证〕 |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

## 1. 样本与哈希

| 项 | 值 | 标签 |
| --- | --- | --- |
| 文件名 | `052_ApDotNetAsmReg.exe` | 〔实测〕 |
| 字节数 | 17,448 | 〔实测〕 |
| SHA-256（本轮自算） | `a015bb5b50b2bac2f0c3a53e0923c2c4fab255e8db232efab324d28ad333fa9e` | 〔实测〕 |
| 清单声明 SHA-256 | `a015bb5b50b2bac2f0c3a53e0923c2c4fab255e8db232efab324d28ad333fa9e` | 〔实测〕一致 |
| 产品映射 | `Plus` → `Aspen-Plus` | 〔实测〕 |
| 清单 | `read-test-waiting.csv` | 〔实测〕 |
| 归并首见 | `B` | 〔实测〕 |
| 台账（20261119-61） | 缺失 | 〔待验证〕缺台账文件才能判归档口径 |

哈希校验口径：读入原件后整文件 SHA-256，与清单 `sha256` 列逐字比对；不一致则记 `status=hash_mismatch` 且不产出 IL/反编译。

## 2. 元数据摘要

| 项 | 值 | 标签 |
| --- | --- | --- |
| PE | Machine `0x14c`（i386）、3 个节、Subsystem 3 | 〔实测〕 |
| 映像基址 / 校验和 | `0x400000` / `0x8963` | 〔实测〕 |
| CLR 头 | 运行时 2.5、Flags `0x1`、EntryPointToken `0x6000001` | 〔实测〕 |
| 元数据 | RVA `0x22e4`，2776 字节，版本串 `v4.0.30319` | 〔实测〕 |
| 强名 | RVA `0x0` / 0 字节；Flags `0x1` | 〔实测〕 |

元数据流（相对元数据根）：

| 流 | 相对根偏移 | 大小 |
| --- | ---: | ---: |
| `#~` | 108 (0x6c) | 744 |
| `#Strings` | 852 (0x354) | 1040 |
| `#US` | 1892 (0x764) | 440 |
| `#GUID` | 2332 (0x91c) | 16 |
| `#Blob` | 2348 (0x92c) | 428 |

- 方法统计：**5 = 5 + 0 + 0 + 0**（有 IL 体 + 抽象 + 运行时实现/委托 + P/Invoke）〔实测〕
- 方法体头分布（按方法体首字/标志字统计，每种恰好一行）：〔实测〕

| 头 | 方法数 |
| --- | ---: |
| fat 0x3013 | 1 |
| fat 0x301B | 1 |
| tiny 0xAA | 1 |
| tiny 0x1E | 1 |
| tiny 0x2E | 1 |

- 版本资源：948 字节，SHA-256 b8811cb9d9b178fd91ee2d936955a2508ca11fd6bf28d0791fd9b88470b6c3b7（RT_VERSION，语言 0）〔实测〕
- 托管资源（ManifestResource）：0 条〔实测〕
- 解码失败方法体：1 条〔实测〕

## 3. IL 清单（全量）

全程序集 IL 逐条清单落盘为 `il/052_ApDotNetAsmReg.exe.il.txt`（221 行）；每个 MethodDef 一行（`MD ` 开头），其下为该方法体全部指令（`IL_XXXX` + 原始字节 + 反汇编文本 + 令牌解析）。〔实测〕

| 项 | 值 |
| --- | ---: |
| MethodDef 总数 | 5 |
| 有 IL 体方法 | 5 |
| IL 字节合计 | 615 |
| 清单文件行数 | 221 |

## 4. 反编译伪代码（ILSpy）

全量 C# 反编译落盘为 `decompiled/052_ApDotNetAsmReg.exe.cs.txt`（115 行，含 1 处 `class ` 声明）。命令为 `dotnet <ilspycmd.dll> <样本> > decompiled/052_ApDotNetAsmReg.exe.cs.txt`：stdout 单文件，未用 `-o`/`-p`（目录/工程形态会产多文件）。〔实测〕

| 项 | 值 |
| --- | ---: |
| 反编译行数 | 115 |
| `class ` 声明数 | 1 |

## 5. P/Invoke 与原生调用

ImplMap 表 0 条：本件无 P/Invoke 声明〔实测〕。

PE 导入表：1 个 DLL。

| DLL | 符号数 | 前若干符号 |
| --- | ---: | --- |
| `mscoree.dll` | 1 | `_CorExeMain` |

托管调用目标全量分布（`call`/`callvirt`/`newobj`/`ldftn`/`ldvirtftn`/`jmp` 操作数解析；调用点为目标在 IL 中的出现偏移，最多列 8 处）：〔实测〕

| 调用目标 | 次数 | 调用点（IL 偏移） |
| --- | ---: | --- |
| `System.String::CompareTo(string)` | 10 | IL_0073, IL_0088, IL_009A, IL_00AC, IL_00BE, IL_00D0, IL_00E2, IL_00F4 |
| `System.String::ToLower()` | 10 | IL_0069, IL_007E, IL_0090, IL_00A2, IL_00B4, IL_00C6, IL_00D8, IL_00EA |
| `System.Console::WriteLine(string)` | 4 | IL_0033, IL_0136, IL_00AC, IL_00CF |
| `System.String::get_Length()` | 4 | IL_0021, IL_0056, IL_006D, IL_0005 |
| `ApDotNetAsmReg.ApRegAsm::AddParameter(string)` | 3 | IL_003E, IL_0046, IL_010E |
| `System.IO.File::Exists(string)` | 3 | IL_001A, IL_000D, IL_002A |
| `System.String::Concat(string, string)` | 3 | IL_0131, IL_0064, IL_00A7 |
| `System.String::Concat(string, string, string)` | 3 | IL_002E, IL_00CA, IL_0018 |
| `ApDotNetAsmReg.ApRegAsm::RunRegAsm(string, bool)` | 2 | IL_0011, IL_014E |
| `Microsoft.Build.Utilities.ToolLocationHelper::GetPathToDotNetFrameworkFile(string, Microsoft.Build.Utilities.TargetDotNetFrameworkVersion)` | 2 | IL_0006, IL_001A |
| `System.Diagnostics.ProcessStartInfo::get_Arguments()` | 2 | IL_00A2, IL_00C5 |
| `System.Diagnostics.ProcessStartInfo::get_FileName()` | 2 | IL_009C, IL_00BF |
| `System.Array::GetLength(int32)` | 1 | IL_0004 |
| `System.Console::Write(string)` | 1 | IL_003C |
| `System.Diagnostics.Process::.ctor()` | 1 | IL_0082 |
| `System.Diagnostics.Process::Close()` | 1 | IL_00B1 |
| `System.Diagnostics.Process::Start()` | 1 | IL_008F |
| `System.Diagnostics.Process::WaitForExit()` | 1 | IL_0096 |
| `System.Diagnostics.Process::set_StartInfo(System.Diagnostics.ProcessStartInfo)` | 1 | IL_0089 |
| `System.Diagnostics.ProcessStartInfo::.ctor()` | 1 | IL_0041 |
| `System.Diagnostics.ProcessStartInfo::set_Arguments(string)` | 1 | IL_007D |
| `System.Diagnostics.ProcessStartInfo::set_CreateNoWindow(bool)` | 1 | IL_0050 |
| `System.Diagnostics.ProcessStartInfo::set_FileName(string)` | 1 | IL_0049 |
| `System.Object::.ctor()` | 1 | IL_0001 |
| `System.String::StartsWith(string)` | 1 | IL_005E |

## 6. 工具与环境

| 项 | 值 |
| --- | --- |
| 元数据/IL | Python 3.13.5 + dnfile 0.18.0 + pefile 2024.8.26；`tool/lib/dnlib.py` + `tool/lib/iltab.py`（ECMA-335 自解析，不依赖 Ghidra） |
| 反编译 | ILSpy 9.1.0.7988（`ilspycmd.dll`，ICSharpCode.Decompiler 9.1.0.7988，.NET 8） |
| 反编译命令 | `dotnet <ilspycmd.dll> <样本> > decompiled/052_ApDotNetAsmReg.exe.cs.txt`（ASCII 引号，stdout 单文件） |
| IL 命令 | `python tool/il_dump.py --dll <样本> --out il/052_ApDotNetAsmReg.exe.il.txt` |
| 未使用 | Ghidra：本链为托管件，其 C 反编译器不处理 CIL（原生件走 T1N 链） |
| 时间戳 | 固定值 `2026-11-20T00:00:00Z`（报告可 diff，不含 wall-clock / 耗时） |

## 7. 缺口与待验证

1. Authenticode 签名有效性与签发者：本轮只做静态摘要，未做信任链校验〔待验证〕——缺 signtool verify 或 Windows 信任链才能判。
2. 运行期行为（依赖解析、P/Invoke 实际落点、COM 注册）：未执行样本〔待验证〕——缺 Windows 运行环境与依赖目录才能判。
3. 与上游公开包的逐字节关系：本轮未取回同名 NuGet/厂商件〔待验证〕——缺对应公开包才能判。
4. 类型/成员语义与源码对照：本件未提供源码或 PDB〔待验证〕——缺 PDB/源码才能判标识符原名。
5. 台账 20261119-61：未提供〔待验证〕——缺台账文件才能判归档口径与行号对照。

## 8. 结论

- 本件为可读 CLR 程序集：元数据、MethodDef 5 条、IL 字节 615 全部落盘，逐条指令可复核〔实测〕。
- 反编译（ILSpy 9.1.0.7988）产出 115 行 C#，与 IL 清单可逐条对齐〔实测〕。
- P/Invoke 声明 0 条、PE 导入 DLL 1 个，均已列出〔实测〕。
- 未验证项集中在签名/运行期/上游对照（§7），不影响本轮静态定位结论〔待验证〕。

## dumps

dumps: repo:analysis/20261120-batch-driver/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/（仓内产物，不在 Release 包）

- `Aspen-Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/decompiled/ApDotNetAsmReg.exe.cs.txt` sha256=0ac32f3fdd48f07ef2fbfcee3b09a91bde0d955ba05f3d13e0bf18cee995cc46 bytes=3592
- `Aspen-Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/il/ApDotNetAsmReg.exe.il.txt` sha256=c90873715c9456f2f819e49b7cebda2c2afc8490ed10b0fbc95982c4ca1bfea9 bytes=12207
