# 056_Aspentech.Exchange.EquipmentSelection.dll 静态复核报告（Aspen-Plus / 全程序集 IL + C# 反编译）

样本别名：`056_Aspentech.Exchange.EquipmentSelection.dll`（清单 read-test-waiting.csv（schema B），原件目录只读、未上传）
来源：分支 codex/waiting-for-tietoumao｜git_blob 0a34de7798f0｜自算 sha256 7be4816ebce1c87861db7de9b711b2ea503ead8504adcc262ec2ba416de9cb81｜台账 20261119-61 缺失〔待验证〕
落点：`01-completed/Aspen-Plus/[TARGETDIR]/`（相对 `out/R1`）｜定位规则：`local-rel`

标签约定：〔实测〕= 本轮独立实测（有命令与原始输出）；〔待验证〕= 尚未取得证据或需 Windows 环境。

## 0. 摘要

| 项目 | 结果 | 依据 |
| --- | --- | --- |
| 实际样本 | 17,024 字节（17,024），SHA-256 `7be4816ebce1c87861db7de9b711b2ea503ead8504adcc262ec2ba416de9cb81` | 〔实测〕自算 |
| 程序集身份 | CLR 元数据 `v4.0.30319`；流 5 个；强名 RVA `0x2050` / 128 字节 | 〔实测〕 |
| 方法统计 | 27 = 24（有 IL 体）+ 3（抽象）+ 0（运行时实现/委托）+ 0（P/Invoke） | 〔实测〕 |
| IL 清单 | `il/056_Aspentech.Exchange.EquipmentSelection.dll.il.txt`，670 行，MethodDef 27 条（全量，逐条指令） | 〔实测〕 |
| 反编译 | `decompiled/056_Aspentech.Exchange.EquipmentSelection.dll.cs.txt`，381 行（ILSpy 9.1.0.7988 全量 stdout） | 〔实测〕 |
| 原生调用 | ImplMap 0 条；PE 导入表 1 个 DLL | 〔实测〕 |
| 缺口 | 见 §7（签名有效性、运行期行为未验证） | 〔待验证〕 |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

## 1. 样本与哈希

| 项 | 值 | 标签 |
| --- | --- | --- |
| 文件名 | `056_Aspentech.Exchange.EquipmentSelection.dll` | 〔实测〕 |
| 字节数 | 17,024 | 〔实测〕 |
| SHA-256（本轮自算） | `7be4816ebce1c87861db7de9b711b2ea503ead8504adcc262ec2ba416de9cb81` | 〔实测〕 |
| 清单声明 SHA-256 | `7be4816ebce1c87861db7de9b711b2ea503ead8504adcc262ec2ba416de9cb81` | 〔实测〕一致 |
| 产品映射 | `Plus` → `Aspen-Plus` | 〔实测〕 |
| 清单 | `read-test-waiting.csv` | 〔实测〕 |
| 归并首见 | `B` | 〔实测〕 |
| 台账（20261119-61） | 缺失 | 〔待验证〕缺台账文件才能判归档口径 |

哈希校验口径：读入原件后整文件 SHA-256，与清单 `sha256` 列逐字比对；不一致则记 `status=hash_mismatch` 且不产出 IL/反编译。

## 2. 元数据摘要

| 项 | 值 | 标签 |
| --- | --- | --- |
| PE | Machine `0x14c`（i386）、3 个节、Subsystem 3 | 〔实测〕 |
| 映像基址 / 校验和 | `0x10000000` / `0x10892` | 〔实测〕 |
| CLR 头 | 运行时 2.5、Flags `0x9`、EntryPointToken `0x0` | 〔实测〕 |
| 元数据 | RVA `0x28b4`，6924 字节，版本串 `v4.0.30319` | 〔实测〕 |
| 强名 | RVA `0x2050` / 128 字节；Flags `0x9` | 〔实测〕 |

元数据流（相对元数据根）：

| 流 | 相对根偏移 | 大小 |
| --- | ---: | ---: |
| `#~` | 108 (0x6c) | 2116 |
| `#Strings` | 2224 (0x8b0) | 2680 |
| `#US` | 4904 (0x1328) | 916 |
| `#GUID` | 5820 (0x16bc) | 16 |
| `#Blob` | 5836 (0x16cc) | 1088 |

- 方法统计：**27 = 24 + 3 + 0 + 0**（有 IL 体 + 抽象 + 运行时实现/委托 + P/Invoke）〔实测〕
- 方法体头分布（按方法体首字/标志字统计，每种恰好一行）：〔实测〕

| 头 | 方法数 |
| --- | ---: |
| tiny 0x1E | 6 |
| fat 0x301B | 4 |
| tiny 0x22 | 3 |
| fat 0x3013 | 2 |
| tiny 0x66 | 1 |
| tiny 0x0A | 1 |
| tiny 0x7E | 1 |
| tiny 0x72 | 1 |
| tiny 0x56 | 1 |
| tiny 0x6A | 1 |
| tiny 0x6E | 1 |
| tiny 0xBE | 1 |
| tiny 0xF6 | 1 |

- 版本资源：988 字节，SHA-256 60cf0641ebf60342fc4571782951e0f5b29f5ba18f07aea1223c4e215204fb42（RT_VERSION，语言 0）〔实测〕
- 托管资源（ManifestResource）：0 条〔实测〕
- 解码失败方法体：1 条〔实测〕

## 3. IL 清单（全量）

全程序集 IL 逐条清单落盘为 `il/056_Aspentech.Exchange.EquipmentSelection.dll.il.txt`（670 行）；每个 MethodDef 一行（`MD ` 开头），其下为该方法体全部指令（`IL_XXXX` + 原始字节 + 反汇编文本 + 令牌解析）。〔实测〕

| 项 | 值 |
| --- | ---: |
| MethodDef 总数 | 27 |
| 有 IL 体方法 | 24 |
| IL 字节合计 | 1,840 |
| 清单文件行数 | 670 |

## 4. 反编译伪代码（ILSpy）

全量 C# 反编译落盘为 `decompiled/056_Aspentech.Exchange.EquipmentSelection.dll.cs.txt`（381 行，含 5 处 `class ` 声明）。命令为 `dotnet <ilspycmd.dll> <样本> > decompiled/056_Aspentech.Exchange.EquipmentSelection.dll.cs.txt`：stdout 单文件，未用 `-o`/`-p`（目录/工程形态会产多文件）。〔实测〕

| 项 | 值 |
| --- | ---: |
| 反编译行数 | 381 |
| `class ` 声明数 | 5 |

## 5. P/Invoke 与原生调用

ImplMap 表 0 条：本件无 P/Invoke 声明〔实测〕。

PE 导入表：1 个 DLL。

| DLL | 符号数 | 前若干符号 |
| --- | ---: | --- |
| `mscoree.dll` | 1 | `_CorDllMain` |

托管调用目标全量分布（`call`/`callvirt`/`newobj`/`ldftn`/`ldvirtftn`/`jmp` 操作数解析；调用点为目标在 IL 中的出现偏移，最多列 8 处）：〔实测〕

| 调用目标 | 次数 | 调用点（IL 偏移） |
| --- | ---: | --- |
| `TypeSpec[2]::Add(!4864, void)` | 20 | IL_001F, IL_002F, IL_003F, IL_004F, IL_005F, IL_0070, IL_0080, IL_0090 |
| `System.String::IsNullOrEmpty(string)` | 7 | IL_0032, IL_00B3, IL_00CC, IL_0177, IL_0190, IL_0006, IL_000C |
| `System.Reflection.Assembly::get_FullName()` | 5 | IL_005F, IL_004B, IL_005F, IL_010F, IL_0123 |
| `System.IO.FileSystemInfo::get_FullName()` | 4 | IL_0033, IL_0095, IL_00F7, IL_0159 |
| `System.Object::.ctor()` | 4 | IL_0001, IL_0001, IL_0022, IL_0022 |
| `System.Type::GetTypeFromHandle(System.RuntimeTypeHandle)` | 4 | IL_0055, IL_0085, IL_0119, IL_0149 |
| `System.AppDomain::get_CurrentDomain()` | 3 | IL_002D, IL_0047, IL_0059 |
| `System.Reflection.Assembly::op_Inequality(System.Reflection.Assembly, System.Reflection.Assembly)` | 3 | IL_0014, IL_0042, IL_0106 |
| `System.Xml.XmlAttributeCollection::get_ItemOf(string)` | 3 | IL_00B4, IL_00DA, IL_0100 |
| `System.Xml.XmlElement::HasAttribute(string)` | 3 | IL_00A1, IL_00C7, IL_00ED |
| `System.Xml.XmlNode::get_Attributes()` | 3 | IL_00AA, IL_00D0, IL_00F6 |
| `System.Xml.XmlNode::get_Value()` | 3 | IL_00B9, IL_00DF, IL_0105 |
| `AspenTech.Exchange.EquipmentSelection.BusinessParameter::get_CodeName()` | 2 | IL_000E, IL_0012 |
| `System.IDisposable::Dispose()` | 2 | IL_01A2, IL_0151 |
| `System.IO.DirectoryInfo::GetFiles(string, System.IO.SearchOption)` | 2 | IL_0019, IL_00DD |
| `System.Reflection.Assembly::GetTypes()` | 2 | IL_006D, IL_0131 |
| `System.Reflection.Assembly::LoadFile(string)` | 2 | IL_0038, IL_00FC |
| `System.String::Concat(object, object)` | 2 | IL_0021, IL_003D |
| `System.String::op_Inequality(string, string)` | 2 | IL_0064, IL_0128 |
| `System.Type::IsAssignableFrom(System.Type)` | 2 | IL_008C, IL_0150 |
| `System.Type::get_Assembly()` | 2 | IL_005A, IL_011E |
| `TypeSpec[2]::get_Item(elem_0x00)` | 2 | IL_0184, IL_0013 |
| `AspenTech.Exchange.EquipmentSelection.AdditionalParameters::.ctor()` | 1 | IL_0000 |
| `AspenTech.Exchange.EquipmentSelection.BusinessParameter::.ctor(string, string)` | 1 | IL_0110 |
| `AspenTech.Exchange.EquipmentSelection.BusinessParameter::get_DisplayName()` | 1 | IL_0023 |
| `AspenTech.Exchange.EquipmentSelection.BusinessParameter::get_Value()` | 1 | IL_0034 |
| `AspenTech.Exchange.EquipmentSelection.BusinessParameter::set_Value(string)` | 1 | IL_011B |
| `AspenTech.Exchange.EquipmentSelection.EquipmentSelectionLoader::GetToolAssembly(string, System.Type&)` | 1 | IL_000C |
| `AspenTech.Exchange.EquipmentSelection.IEquipmentSelection::GetResult()` | 1 | IL_003F |
| `AspenTech.Exchange.EquipmentSelection.IEquipmentSelection::SetContext(AspenTech.Exchange.EquipmentSelection.StartContext)` | 1 | IL_0015 |
| `AspenTech.Exchange.EquipmentSelection.IEquipmentSelection::ShowDialog(native int)` | 1 | IL_0022 |
| `AspenTech.Exchange.EquipmentSelection.ParameterUtils::GetKnownNameString(ParameterKnownKeys)` | 1 | IL_000F |
| `System.AppDomain::CreateInstanceAndUnwrap(string, string)` | 1 | IL_006A |
| `System.AppDomain::Load(System.Reflection.AssemblyName)` | 1 | IL_0052 |
| `System.AppDomain::get_SetupInformation()` | 1 | IL_0032 |
| `System.AppDomainSetup::set_ConfigurationFile(string)` | 1 | IL_0042 |
| `System.ApplicationException::.ctor(string)` | 1 | IL_01B6 |
| `System.Collections.IEnumerator::MoveNext()` | 1 | IL_0136 |
| `System.Collections.IEnumerator::get_Current()` | 1 | IL_0070 |
| `System.Exception::get_Message()` | 1 | IL_01AC |
| `System.IO.DirectoryInfo::.ctor(string)` | 1 | IL_000C |
| `System.IO.File::Exists(string)` | 1 | IL_0026 |
| `System.MarshalByRefObject::.ctor()` | 1 | IL_000C |
| `System.Object::ToString()` | 1 | IL_0039 |
| `System.Reflection.Assembly::GetName()` | 1 | IL_004D |
| `System.String::Concat(string, string)` | 1 | IL_01B1 |
| `System.String::Concat(string[])` | 1 | IL_0048 |
| `System.Type::get_FullName()` | 1 | IL_0065 |
| `System.Xml.XmlDocument::.ctor()` | 1 | IL_0016 |
| `System.Xml.XmlDocument::GetElementsByTagName(string)` | 1 | IL_002E |
| `System.Xml.XmlDocument::LoadXml(string)` | 1 | IL_0023 |
| `System.Xml.XmlElement::GetElementsByTagName(string)` | 1 | IL_0059 |
| `System.Xml.XmlNodeList::GetEnumerator()` | 1 | IL_0062 |
| `System.Xml.XmlNodeList::get_Count()` | 1 | IL_003B |
| `System.Xml.XmlNodeList::get_ItemOf(int32)` | 1 | IL_0048 |
| `TypeSpec[1]::.ctor()` | 1 | IL_0001 |
| `TypeSpec[1]::Add(!4864, void)` | 1 | IL_012F |
| `TypeSpec[1]::ContainsKey()` | 1 | IL_0123 |
| `TypeSpec[2]::.ctor()` | 1 | IL_0000 |
| `TypeSpec[2]::ContainsKey()` | 1 | IL_0006 |
| `TypeSpec[2]::get_Keys()` | 1 | IL_0164 |
| `TypeSpec[3]::.ctor()` | 1 | IL_000A |
| `TypeSpec[3]::Add(!4864, void)` | 1 | IL_018A |
| `TypeSpec[3]::ContainsKey()` | 1 | IL_0006 |
| `TypeSpec[3]::get_Item(elem_0x00)` | 1 | IL_0013 |
| `TypeSpec[4]::GetEnumerator()` | 1 | IL_0169 |
| `TypeSpec[5]::MoveNext()` | 1 | IL_0191 |
| `TypeSpec[5]::get_Current()` | 1 | IL_0173 |

## 6. 工具与环境

| 项 | 值 |
| --- | --- |
| 元数据/IL | Python 3.13.5 + dnfile 0.18.0 + pefile 2024.8.26；`tool/lib/dnlib.py` + `tool/lib/iltab.py`（ECMA-335 自解析，不依赖 Ghidra） |
| 反编译 | ILSpy 9.1.0.7988（`ilspycmd.dll`，ICSharpCode.Decompiler 9.1.0.7988，.NET 8） |
| 反编译命令 | `dotnet <ilspycmd.dll> <样本> > decompiled/056_Aspentech.Exchange.EquipmentSelection.dll.cs.txt`（ASCII 引号，stdout 单文件） |
| IL 命令 | `python tool/il_dump.py --dll <样本> --out il/056_Aspentech.Exchange.EquipmentSelection.dll.il.txt` |
| 未使用 | Ghidra：本链为托管件，其 C 反编译器不处理 CIL（原生件走 T1N 链） |
| 时间戳 | 固定值 `2026-11-20T00:00:00Z`（报告可 diff，不含 wall-clock / 耗时） |

## 7. 缺口与待验证

1. Authenticode 签名有效性与签发者：本轮只做静态摘要，未做信任链校验〔待验证〕——缺 signtool verify 或 Windows 信任链才能判。
2. 运行期行为（依赖解析、P/Invoke 实际落点、COM 注册）：未执行样本〔待验证〕——缺 Windows 运行环境与依赖目录才能判。
3. 与上游公开包的逐字节关系：本轮未取回同名 NuGet/厂商件〔待验证〕——缺对应公开包才能判。
4. 类型/成员语义与源码对照：本件未提供源码或 PDB〔待验证〕——缺 PDB/源码才能判标识符原名。
5. 台账 20261119-61：未提供〔待验证〕——缺台账文件才能判归档口径与行号对照。

## 8. 结论

- 本件为可读 CLR 程序集：元数据、MethodDef 27 条、IL 字节 1,840 全部落盘，逐条指令可复核〔实测〕。
- 反编译（ILSpy 9.1.0.7988）产出 381 行 C#，与 IL 清单可逐条对齐〔实测〕。
- P/Invoke 声明 0 条、PE 导入 DLL 1 个，均已列出〔实测〕。
- 未验证项集中在签名/运行期/上游对照（§7），不影响本轮静态定位结论〔待验证〕。

## dumps

dumps: repo:逆向成果/待静态验收/Plus/[TARGETDIR]/Aspentech.Exchange.EquipmentSelection.dll.md/分支交付/

- tool=ILSpy 9.1.0.7988 + dnfile 0.18.0
