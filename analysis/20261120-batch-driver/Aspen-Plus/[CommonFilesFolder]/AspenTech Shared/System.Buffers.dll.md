# 011_System.Buffers.dll 静态复核报告（Aspen-Plus / 全程序集 IL + C# 反编译）

## 必填字段（T0 口径，逐项可按名检索）

- tool=ILSpy 9.1.0.7988 + dnfile 0.18.0
- functions=N/A（CLR 托管程序集，无 native 函数概念；methods=32）
- decomp_ok=N/A（CLR：无函数级反编译统计）
- decomp_fail=N/A（CLR：无函数级反编译统计）


样本别名：`011_System.Buffers.dll`（清单 read-test-waiting.csv（schema B），原件目录只读、未上传）
来源：分支 codex/waiting-for-tietoumao｜git_blob f2d83c51416e｜自算 sha256 accccfbe45d9f08ffeed9916e37b33e98c65be012cfff6e7fa7b67210ce1fefb｜台账 20261119-61 缺失〔待验证〕
落点：`01-completed/Aspen-Plus/[CommonFilesFolder]/AspenTech Shared/`（相对 `out/R1`）｜定位规则：`local-rel`

标签约定：〔实测〕= 本轮独立实测（有命令与原始输出）；〔待验证〕= 尚未取得证据或需 Windows 环境。

## 0. 摘要

| 项目 | 结果 | 依据 |
| --- | --- | --- |
| 实际样本 | 20,856 字节（20,856），SHA-256 `accccfbe45d9f08ffeed9916e37b33e98c65be012cfff6e7fa7b67210ce1fefb` | 〔实测〕自算 |
| 程序集身份 | CLR 元数据 `v4.0.30319`；流 5 个；强名 RVA `0x4138` / 128 字节 | 〔实测〕 |
| 方法统计 | 34 = 32（有 IL 体）+ 2（抽象）+ 0（运行时实现/委托）+ 0（P/Invoke） | 〔实测〕 |
| IL 清单 | `il/011_System.Buffers.dll.il.txt`，823 行，MethodDef 34 条（全量，逐条指令） | 〔实测〕 |
| 反编译 | `decompiled/011_System.Buffers.dll.cs.txt`，467 行（ILSpy 9.1.0.7988 全量 stdout） | 〔实测〕 |
| 原生调用 | ImplMap 0 条；PE 导入表 1 个 DLL | 〔实测〕 |
| 缺口 | 见 §7（签名有效性、运行期行为未验证） | 〔待验证〕 |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

## 1. 样本与哈希

| 项 | 值 | 标签 |
| --- | --- | --- |
| 文件名 | `011_System.Buffers.dll` | 〔实测〕 |
| 字节数 | 20,856 | 〔实测〕 |
| SHA-256（本轮自算） | `accccfbe45d9f08ffeed9916e37b33e98c65be012cfff6e7fa7b67210ce1fefb` | 〔实测〕 |
| 清单声明 SHA-256 | `accccfbe45d9f08ffeed9916e37b33e98c65be012cfff6e7fa7b67210ce1fefb` | 〔实测〕一致 |
| 产品映射 | `Plus` → `Aspen-Plus` | 〔实测〕 |
| 清单 | `read-test-waiting.csv` | 〔实测〕 |
| 归并首见 | `B` | 〔实测〕 |
| 台账（20261119-61） | 缺失 | 〔待验证〕缺台账文件才能判归档口径 |

哈希校验口径：读入原件后整文件 SHA-256，与清单 `sha256` 列逐字比对；不一致则记 `status=hash_mismatch` 且不产出 IL/反编译。

## 2. 元数据摘要

| 项 | 值 | 标签 |
| --- | --- | --- |
| PE | Machine `0x14c`（i386）、3 个节、Subsystem 3 | 〔实测〕 |
| 映像基址 / 校验和 | `0x10000000` / `0xd7d4` | 〔实测〕 |
| CLR 头 | 运行时 2.5、Flags `0x9`、EntryPointToken `0x0` | 〔实测〕 |
| 元数据 | RVA `0x27c8`，6168 字节，版本串 `v4.0.30319` | 〔实测〕 |
| 强名 | RVA `0x4138` / 128 字节；Flags `0x9` | 〔实测〕 |

元数据流（相对元数据根）：

| 流 | 相对根偏移 | 大小 |
| --- | ---: | ---: |
| `#~` | 108 (0x6c) | 2128 |
| `#Strings` | 2236 (0x8bc) | 2004 |
| `#US` | 4240 (0x1090) | 188 |
| `#GUID` | 4428 (0x114c) | 16 |
| `#Blob` | 4444 (0x115c) | 1724 |

- 方法统计：**34 = 32 + 2 + 0 + 0**（有 IL 体 + 抽象 + 运行时实现/委托 + P/Invoke）〔实测〕
- 方法体头分布（按方法体首字/标志字统计，每种恰好一行）：〔实测〕

| 头 | 方法数 |
| --- | ---: |
| fat 0x3013 | 7 |
| tiny 0x1E | 4 |
| fat 0x301B | 3 |
| tiny 0x1A | 2 |
| tiny 0x2E | 2 |
| tiny 0x6A | 1 |
| tiny 0x0A | 1 |
| tiny 0x9A | 1 |
| tiny 0xA2 | 1 |
| tiny 0xB6 | 1 |
| tiny 0xCA | 1 |
| tiny 0x32 | 1 |
| tiny 0x42 | 1 |
| tiny 0x52 | 1 |
| tiny 0x5E | 1 |
| tiny 0x22 | 1 |
| tiny 0x06 | 1 |
| tiny 0x3A | 1 |
| tiny 0xC6 | 1 |

- 版本资源：1252 字节，SHA-256 61f6d23111770cda0518872ef7e2c505c9b4b62b3e8533ee94f5d7af34ff961e（RT_VERSION，语言 0）〔实测〕
- 托管资源（ManifestResource）：1 条〔实测〕
- 解码失败方法体：1 条〔实测〕

## 3. IL 清单（全量）

全程序集 IL 逐条清单落盘为 `il/011_System.Buffers.dll.il.txt`（823 行）；每个 MethodDef 一行（`MD ` 开头），其下为该方法体全部指令（`IL_XXXX` + 原始字节 + 反汇编文本 + 令牌解析）。〔实测〕

| 项 | 值 |
| --- | ---: |
| MethodDef 总数 | 34 |
| 有 IL 体方法 | 32 |
| IL 字节合计 | 1,711 |
| 清单文件行数 | 823 |

## 4. 反编译伪代码（ILSpy）

全量 C# 反编译落盘为 `decompiled/011_System.Buffers.dll.cs.txt`（467 行，含 7 处 `class ` 声明）。命令为 `dotnet <ilspycmd.dll> <样本> > decompiled/011_System.Buffers.dll.cs.txt`：stdout 单文件，未用 `-o`/`-p`（目录/工程形态会产多文件）。〔实测〕

| 项 | 值 |
| --- | ---: |
| 反编译行数 | 467 |
| `class ` 声明数 | 7 |

## 5. P/Invoke 与原生调用

ImplMap 表 0 条：本件无 P/Invoke 声明〔实测〕。

PE 导入表：1 个 DLL。

| DLL | 符号数 | 前若干符号 |
| --- | ---: | --- |
| `mscoree.dll` | 1 | `_CorDllMain` |

托管调用目标全量分布（`call`/`callvirt`/`newobj`/`ldftn`/`ldvirtftn`/`jmp` 操作数解析；调用点为目标在 IL 中的出现偏移，最多列 8 处）：〔实测〕

| 调用目标 | 次数 | 调用点（IL 偏移） |
| --- | ---: | --- |
| `EventData::set_DataPointer(native int)` | 9 | IL_0027, IL_0054, IL_0084, IL_00B4, IL_0027, IL_0054, IL_0084, IL_00B4 |
| `EventData::set_Size(int32)` | 9 | IL_0018, IL_0045, IL_0075, IL_00A5, IL_0018, IL_0045, IL_0075, IL_00A5 |
| `System.IntPtr::op_Explicit(void*)` | 9 | IL_0022, IL_004F, IL_007F, IL_00AF, IL_0022, IL_004F, IL_007F, IL_00AF |
| `System.Object::GetHashCode()` | 6 | IL_0001, IL_005F, IL_00BB, IL_0052, IL_0001, IL_007E |
| `TypeSpec[2]::get_Id()` | 5 | IL_003F, IL_0068, IL_00CC, IL_00DF, IL_005B |
| `System.Diagnostics.Tracing.EventSource::IsEnabled()` | 4 | IL_0056, IL_00B3, IL_0049, IL_0074 |
| `System.SR::UsingResourceKeys()` | 4 | IL_0003, IL_0000, IL_0000, IL_0000 |
| `System.String::Join(string, object[])` | 4 | IL_0011, IL_001A, IL_001E, IL_0022 |
| `System.ArgumentOutOfRangeException::.ctor(string)` | 3 | IL_000F, IL_001E, IL_0009 |
| `System.Buffers.Utilities::SelectBucketIndex(int32)` | 3 | IL_0046, IL_0031, IL_0016 |
| `System.Buffers.ArrayPoolEventSource::BufferAllocated(int32, int32, int32, int32, BufferAllocatedReason)` | 2 | IL_00F5, IL_0096 |
| `System.Buffers.ArrayPoolEventSource::BufferRented(int32, int32, int32, int32)` | 2 | IL_007A, IL_00D3 |
| `System.Diagnostics.Tracing.EventSource::WriteEventCore(int32, int32, EventData*)` | 2 | IL_00C3, IL_00F3 |
| `System.Object::.ctor()` | 2 | IL_0001, IL_0001 |
| `System.Threading.SpinLock::Enter(bool&)` | 2 | IL_0015, IL_0025 |
| `System.Threading.SpinLock::Exit(bool)` | 2 | IL_0056, IL_0057 |
| `TypeSpec[2]::.ctor(int32, int32)` | 2 | IL_0002, IL_0008 |
| `TypeSpec[3]::get_Id()` | 2 | IL_0075, IL_0090 |
| `System.ArgumentException::.ctor(string, string)` | 1 | IL_0015 |
| `System.ArgumentNullException::.ctor(string)` | 1 | IL_0008 |
| `System.Array::Clear(System.Array, int32, int32)` | 1 | IL_002F |
| `System.Buffers.ArrayPoolEventSource::.ctor()` | 1 | IL_0000 |
| `System.Buffers.ArrayPoolEventSource::BufferReturned(int32, int32, int32)` | 1 | IL_0060 |
| `System.Buffers.Utilities::GetMaxSizeForBucket(int32)` | 1 | IL_005C |
| `System.Diagnostics.Debugger::get_IsAttached()` | 1 | IL_0007 |
| `System.Diagnostics.Tracing.EventSource::.ctor()` | 1 | IL_0001 |
| `System.Diagnostics.Tracing.EventSource::WriteEvent(int32, int32, int32, int32)` | 1 | IL_0005 |
| `System.Resources.ResourceManager::.ctor(System.Type)` | 1 | IL_000E |
| `System.Resources.ResourceManager::GetString(string)` | 1 | IL_0008 |
| `System.SR::GetResourceString(string, string)` | 1 | IL_0006 |
| `System.SR::get_ArgumentException_BufferNotFromPool()` | 1 | IL_000B |
| `System.SR::get_ResourceManager()` | 1 | IL_0002 |
| `System.SR::get_ResourceType()` | 1 | IL_0009 |
| `System.String::Concat(string, string)` | 1 | IL_0016 |
| `System.String::Equals(string, System.StringComparison)` | 1 | IL_0019 |
| `System.String::Format(string, object)` | 1 | IL_0022 |
| `System.String::Format(string, object, object)` | 1 | IL_0027 |
| `System.String::Format(string, object, object, object)` | 1 | IL_002C |
| `System.String::Format(string, object[])` | 1 | IL_001E |
| `System.Threading.Interlocked::CompareExchange()` | 1 | IL_000B |
| `System.Threading.SpinLock::.ctor(bool)` | 1 | IL_000C |
| `System.Threading.Volatile::Read()` | 1 | IL_0005 |
| `System.Type::GetTypeFromHandle(System.RuntimeTypeHandle)` | 1 | IL_0005 |
| `TypeSpec[1]::.ctor()` | 1 | IL_0001 |
| `TypeSpec[1]::Create()` | 1 | IL_0005 |
| `TypeSpec[1]::EnsureSharedCreated()` | 1 | IL_000E |
| `TypeSpec[2]::.ctor()` | 1 | IL_0000 |
| `TypeSpec[3]::.ctor(int32, int32, int32)` | 1 | IL_0063 |
| `TypeSpec[3]::Rent()` | 1 | IL_004C |
| `TypeSpec[3]::Return()` | 1 | IL_003D |

## 6. 工具与环境

| 项 | 值 |
| --- | --- |
| 元数据/IL | Python 3.13.5 + dnfile 0.18.0 + pefile 2024.8.26；`tool/lib/dnlib.py` + `tool/lib/iltab.py`（ECMA-335 自解析，不依赖 Ghidra） |
| 反编译 | ILSpy 9.1.0.7988（`ilspycmd.dll`，ICSharpCode.Decompiler 9.1.0.7988，.NET 8） |
| 反编译命令 | `dotnet <ilspycmd.dll> <样本> > decompiled/011_System.Buffers.dll.cs.txt`（ASCII 引号，stdout 单文件） |
| IL 命令 | `python tool/il_dump.py --dll <样本> --out il/011_System.Buffers.dll.il.txt` |
| 未使用 | Ghidra：本链为托管件，其 C 反编译器不处理 CIL（原生件走 T1N 链） |
| 时间戳 | 固定值 `2026-11-20T00:00:00Z`（报告可 diff，不含 wall-clock / 耗时） |

## 7. 缺口与待验证

1. Authenticode 签名有效性与签发者：本轮只做静态摘要，未做信任链校验〔待验证〕——缺 signtool verify 或 Windows 信任链才能判。
2. 运行期行为（依赖解析、P/Invoke 实际落点、COM 注册）：未执行样本〔待验证〕——缺 Windows 运行环境与依赖目录才能判。
3. 与上游公开包的逐字节关系：本轮未取回同名 NuGet/厂商件〔待验证〕——缺对应公开包才能判。
4. 类型/成员语义与源码对照：本件未提供源码或 PDB〔待验证〕——缺 PDB/源码才能判标识符原名。
5. 台账 20261119-61：未提供〔待验证〕——缺台账文件才能判归档口径与行号对照。

## 8. 结论

- 本件为可读 CLR 程序集：元数据、MethodDef 34 条、IL 字节 1,711 全部落盘，逐条指令可复核〔实测〕。
- 反编译（ILSpy 9.1.0.7988）产出 467 行 C#，与 IL 清单可逐条对齐〔实测〕。
- P/Invoke 声明 0 条、PE 导入 DLL 1 个，均已列出〔实测〕。
- 未验证项集中在签名/运行期/上游对照（§7），不影响本轮静态定位结论〔待验证〕。

## dumps

dumps: repo:analysis/20261120-batch-driver/Aspen-Plus/[CommonFilesFolder]/AspenTech Shared/（仓内产物，不在 Release 包）

- `Aspen-Plus/[CommonFilesFolder]/AspenTech Shared/decompiled/System.Buffers.dll.cs.txt` sha256=acffa707a068c2c639fe5dbd20a5a08fccaf92b137393cce2292f12e57aeecd1 bytes=11295
- `Aspen-Plus/[CommonFilesFolder]/AspenTech Shared/il/System.Buffers.dll.il.txt` sha256=06f0d4ba32c71a33d8a41d57814104ac8e840f7f5e80adf3883f110117658bf4 bytes=39595
