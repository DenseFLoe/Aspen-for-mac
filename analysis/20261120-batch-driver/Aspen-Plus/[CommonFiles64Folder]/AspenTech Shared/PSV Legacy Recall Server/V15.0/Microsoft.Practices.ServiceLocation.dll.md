# 008_Microsoft.Practices.ServiceLocation.dll 静态复核报告（Aspen-Plus / 全程序集 IL + C# 反编译）

样本别名：`008_Microsoft.Practices.ServiceLocation.dll`（清单 read-test-waiting.csv（schema B），原件目录只读、未上传）
来源：分支 codex/waiting-for-tietoumao｜git_blob 0d600ecca85e｜自算 sha256 78ac70411c71b7a0c68fe8746edd3f3a8cd3f72044b329a40ab53c57891be37d｜台账 20261119-61 缺失〔待验证〕
落点：`01-completed/Aspen-Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/`（相对 `out/R1`）｜定位规则：`local-rel`

标签约定：〔实测〕= 本轮独立实测（有命令与原始输出）；〔待验证〕= 尚未取得证据或需 Windows 环境。

## 0. 摘要

| 项目 | 结果 | 依据 |
| --- | --- | --- |
| 实际样本 | 18,120 字节（18,120），SHA-256 `78ac70411c71b7a0c68fe8746edd3f3a8cd3f72044b329a40ab53c57891be37d` | 〔实测〕自算 |
| 程序集身份 | CLR 元数据 `v4.0.30319`；流 5 个；强名 RVA `0x2050` / 128 字节 | 〔实测〕 |
| 方法统计 | 44 = 32（有 IL 体）+ 8（抽象）+ 4（运行时实现/委托）+ 0（P/Invoke） | 〔实测〕 |
| IL 清单 | `il/008_Microsoft.Practices.ServiceLocation.dll.il.txt`，338 行，MethodDef 44 条（全量，逐条指令） | 〔实测〕 |
| 反编译 | `decompiled/008_Microsoft.Practices.ServiceLocation.dll.cs.txt`，205 行（ILSpy 9.1.0.7988 全量 stdout） | 〔实测〕 |
| 原生调用 | ImplMap 0 条；PE 导入表 1 个 DLL | 〔实测〕 |
| 缺口 | 见 §7（签名有效性、运行期行为未验证） | 〔待验证〕 |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

## 1. 样本与哈希

| 项 | 值 | 标签 |
| --- | --- | --- |
| 文件名 | `008_Microsoft.Practices.ServiceLocation.dll` | 〔实测〕 |
| 字节数 | 18,120 | 〔实测〕 |
| SHA-256（本轮自算） | `78ac70411c71b7a0c68fe8746edd3f3a8cd3f72044b329a40ab53c57891be37d` | 〔实测〕 |
| 清单声明 SHA-256 | `78ac70411c71b7a0c68fe8746edd3f3a8cd3f72044b329a40ab53c57891be37d` | 〔实测〕一致 |
| 产品映射 | `Plus` → `Aspen-Plus` | 〔实测〕 |
| 清单 | `read-test-waiting.csv` | 〔实测〕 |
| 归并首见 | `B` | 〔实测〕 |
| 台账（20261119-61） | 缺失 | 〔待验证〕缺台账文件才能判归档口径 |

哈希校验口径：读入原件后整文件 SHA-256，与清单 `sha256` 列逐字比对；不一致则记 `status=hash_mismatch` 且不产出 IL/反编译。

## 2. 元数据摘要

| 项 | 值 | 标签 |
| --- | --- | --- |
| PE | Machine `0x14c`（i386）、3 个节、Subsystem 3 | 〔实测〕 |
| 映像基址 / 校验和 | `0x10000000` / `0xcbaf` | 〔实测〕 |
| CLR 头 | 运行时 2.5、Flags `0x9`、EntryPointToken `0x0` | 〔实测〕 |
| 元数据 | RVA `0x26f0`，6500 字节，版本串 `v4.0.30319` | 〔实测〕 |
| 强名 | RVA `0x2050` / 128 字节；Flags `0x9` | 〔实测〕 |

元数据流（相对元数据根）：

| 流 | 相对根偏移 | 大小 |
| --- | ---: | ---: |
| `#~` | 108 (0x6c) | 2236 |
| `#Strings` | 2344 (0x928) | 2816 |
| `#US` | 5160 (0x1428) | 300 |
| `#GUID` | 5460 (0x1554) | 16 |
| `#Blob` | 5476 (0x1564) | 1024 |

- 方法统计：**44 = 32 + 8 + 4 + 0**（有 IL 体 + 抽象 + 运行时实现/委托 + P/Invoke）〔实测〕
- 方法体头分布（按方法体首字/标志字统计，每种恰好一行）：〔实测〕

| 头 | 方法数 |
| --- | ---: |
| tiny 0x1E | 7 |
| fat 0x3013 | 5 |
| fat 0x301B | 4 |
| tiny 0x26 | 3 |
| tiny 0x56 | 3 |
| tiny 0x32 | 2 |
| tiny 0x5E | 2 |
| tiny 0x1A | 2 |
| tiny 0x22 | 1 |
| tiny 0x76 | 1 |
| tiny 0x7A | 1 |
| tiny 0x6E | 1 |

- 版本资源：1136 字节，SHA-256 857b007f55274d5887bd757d4f0045cefc9747da3d86728401f12ae54f69f686（RT_VERSION，语言 0）〔实测〕
- 托管资源（ManifestResource）：1 条〔实测〕
- 解码失败方法体：1 条〔实测〕

## 3. IL 清单（全量）

全程序集 IL 逐条清单落盘为 `il/008_Microsoft.Practices.ServiceLocation.dll.il.txt`（338 行）；每个 MethodDef 一行（`MD ` 开头），其下为该方法体全部指令（`IL_XXXX` + 原始字节 + 反汇编文本 + 令牌解析）。〔实测〕

| 项 | 值 |
| --- | ---: |
| MethodDef 总数 | 44 |
| 有 IL 体方法 | 32 |
| IL 字节合计 | 764 |
| 清单文件行数 | 338 |

## 4. 反编译伪代码（ILSpy）

全量 C# 反编译落盘为 `decompiled/008_Microsoft.Practices.ServiceLocation.dll.cs.txt`（205 行，含 4 处 `class ` 声明）。命令为 `dotnet <ilspycmd.dll> <样本> > decompiled/008_Microsoft.Practices.ServiceLocation.dll.cs.txt`：stdout 单文件，未用 `-o`/`-p`（目录/工程形态会产多文件）。〔实测〕

| 项 | 值 |
| --- | ---: |
| 反编译行数 | 205 |
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
| `Microsoft.Practices.ServiceLocation.ServiceLocatorImplBase::GetInstance(System.Type, string)` | 4 | IL_0003, IL_0003, IL_000C, IL_000C |
| `System.Type::GetTypeFromHandle(System.RuntimeTypeHandle)` | 4 | IL_0006, IL_0006, IL_0017, IL_002E |
| `Microsoft.Practices.ServiceLocation.Properties.Resources::get_ResourceManager()` | 3 | IL_0000, IL_0000, IL_0000 |
| `System.Object::.ctor()` | 3 | IL_0001, IL_0001, IL_0001 |
| `System.Resources.ResourceManager::GetString(string, System.Globalization.CultureInfo)` | 3 | IL_000F, IL_000F, IL_000F |
| `Microsoft.Practices.ServiceLocation.ActivationException::.ctor(string, System.Exception)` | 2 | IL_0016, IL_0014 |
| `System.Globalization.CultureInfo::get_CurrentUICulture()` | 2 | IL_0000, IL_0000 |
| `System.Reflection.MemberInfo::get_Name()` | 2 | IL_0014, IL_0014 |
| `System.String::Format(System.IFormatProvider, string, object[])` | 2 | IL_001F, IL_001B |
| `System.Threading.Thread::get_CurrentThread()` | 2 | IL_0000, IL_000E |
| `System.Threading.Thread::get_ManagedThreadId()` | 2 | IL_0005, IL_0013 |
| `TypeSpec[4]::<>m__Finally3()` | 2 | IL_008D, IL_001B |
| `Microsoft.Practices.ServiceLocation.Properties.Resources::get_ActivateAllExceptionMessage()` | 1 | IL_0005 |
| `Microsoft.Practices.ServiceLocation.Properties.Resources::get_ActivationExceptionMessage()` | 1 | IL_0005 |
| `Microsoft.Practices.ServiceLocation.Properties.Resources::get_ServiceLocationProviderNotSetMessage()` | 1 | IL_0007 |
| `Microsoft.Practices.ServiceLocation.ServiceLocator::get_IsLocationProviderSet()` | 1 | IL_0000 |
| `Microsoft.Practices.ServiceLocation.ServiceLocatorImplBase::DoGetAllInstances(System.Collections.Generic.IEnumerable`1)` | 1 | IL_0002 |
| `Microsoft.Practices.ServiceLocation.ServiceLocatorImplBase::DoGetInstance(System.Type, string)` | 1 | IL_0003 |
| `Microsoft.Practices.ServiceLocation.ServiceLocatorImplBase::FormatActivateAllExceptionMessage(System.Exception, System.Type)` | 1 | IL_000E |
| `Microsoft.Practices.ServiceLocation.ServiceLocatorImplBase::FormatActivationExceptionMessage(System.Exception, System.Type, string)` | 1 | IL_0010 |
| `Microsoft.Practices.ServiceLocation.ServiceLocatorImplBase::GetAllInstances(System.Collections.Generic.IEnumerable`1)` | 1 | IL_0033 |
| `Microsoft.Practices.ServiceLocation.ServiceLocatorProvider::Invoke()` | 1 | IL_0017 |
| `System.Collections.IEnumerator::MoveNext()` | 1 | IL_0085 |
| `System.Exception::.ctor()` | 1 | IL_0001 |
| `System.Exception::.ctor(string)` | 1 | IL_0002 |
| `System.Exception::.ctor(string, System.Exception)` | 1 | IL_0003 |
| `System.IDisposable::Dispose()` | 1 | IL_0015 |
| `System.InvalidOperationException::.ctor(string)` | 1 | IL_000C |
| `System.NotSupportedException::.ctor()` | 1 | IL_0000 |
| `System.Object::ReferenceEquals(object, object)` | 1 | IL_0006 |
| `System.Resources.ResourceManager::.ctor(string, System.Reflection.Assembly)` | 1 | IL_0021 |
| `System.Type::get_Assembly()` | 1 | IL_001C |
| `TypeSpec[4]::.ctor(int32)` | 1 | IL_0028 |
| `TypeSpec[4]::System.Collections.Generic.IEnumerable<TService>.GetEnumerator()` | 1 | IL_0001 |
| `TypeSpec[4]::System.IDisposable.Dispose()` | 1 | IL_0097 |
| `TypeSpec[6]::GetEnumerator()` | 1 | IL_0038 |
| `TypeSpec[7]::get_Current()` | 1 | IL_0052 |
| `TypeSpec[8]::.ctor(int32)` | 1 | IL_0002 |

## 6. 工具与环境

| 项 | 值 |
| --- | --- |
| 元数据/IL | Python 3.13.5 + dnfile 0.18.0 + pefile 2024.8.26；`tool/lib/dnlib.py` + `tool/lib/iltab.py`（ECMA-335 自解析，不依赖 Ghidra） |
| 反编译 | ILSpy 9.1.0.7988（`ilspycmd.dll`，ICSharpCode.Decompiler 9.1.0.7988，.NET 8） |
| 反编译命令 | `dotnet <ilspycmd.dll> <样本> > decompiled/008_Microsoft.Practices.ServiceLocation.dll.cs.txt`（ASCII 引号，stdout 单文件） |
| IL 命令 | `python tool/il_dump.py --dll <样本> --out il/008_Microsoft.Practices.ServiceLocation.dll.il.txt` |
| 未使用 | Ghidra：本链为托管件，其 C 反编译器不处理 CIL（原生件走 T1N 链） |
| 时间戳 | 固定值 `2026-11-20T00:00:00Z`（报告可 diff，不含 wall-clock / 耗时） |

## 7. 缺口与待验证

1. Authenticode 签名有效性与签发者：本轮只做静态摘要，未做信任链校验〔待验证〕——缺 signtool verify 或 Windows 信任链才能判。
2. 运行期行为（依赖解析、P/Invoke 实际落点、COM 注册）：未执行样本〔待验证〕——缺 Windows 运行环境与依赖目录才能判。
3. 与上游公开包的逐字节关系：本轮未取回同名 NuGet/厂商件〔待验证〕——缺对应公开包才能判。
4. 类型/成员语义与源码对照：本件未提供源码或 PDB〔待验证〕——缺 PDB/源码才能判标识符原名。
5. 台账 20261119-61：未提供〔待验证〕——缺台账文件才能判归档口径与行号对照。

## 8. 结论

- 本件为可读 CLR 程序集：元数据、MethodDef 44 条、IL 字节 764 全部落盘，逐条指令可复核〔实测〕。
- 反编译（ILSpy 9.1.0.7988）产出 205 行 C#，与 IL 清单可逐条对齐〔实测〕。
- P/Invoke 声明 0 条、PE 导入 DLL 1 个，均已列出〔实测〕。
- 未验证项集中在签名/运行期/上游对照（§7），不影响本轮静态定位结论〔待验证〕。

## dumps

dumps: repo:逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/Microsoft.Practices.ServiceLocation.dll.md/分支交付/

- tool=ILSpy 9.1.0.7988 + dnfile 0.18.0
