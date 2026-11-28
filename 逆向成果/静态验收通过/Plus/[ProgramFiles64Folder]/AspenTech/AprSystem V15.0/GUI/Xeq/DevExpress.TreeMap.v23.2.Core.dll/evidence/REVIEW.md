# DevExpress.TreeMap.v23.2.Core.dll 独立静态复核

**结论为通过。** 独立复核员为 `/root/reviewer`，制作方为 `/root/producer`。适用 GitHub 固定主干 `adbe73b517acac25da87598cce46de033f630ccb` 的逐件静态验收标准。此结论绑定下列 ZIP 和本机原件。Windows 装载、行为对照及发布签名留待后续阶段。

| 项目 | 路径和 SHA-256 |
| --- | --- |
| 审核的冻结 ZIP | `../producer/DevExpress.TreeMap.v23.2.Core.dll.source-v3.zip`，`67c6146f79f59cb337076b6e54f557703249ba59363611359e8c753075672a0e` |
| Plus V15.0 安装原件，文件与程序集版本 23.2.4.0 | `C:/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.TreeMap.v23.2.Core.dll`，41,576 B，`6b2379f21a1c6f408893b9a94e52ca44fa2546024fc35c6cb6e6d56a8dea46c5` |
| 独立回编 DLL | `build/DevExpress.TreeMap.v23.2.Core.dll`，31,232 B，`77087b847b6964e530136ca1b47090dadc7bb509f9f93790a933ba68eae08ccf` |
| 预先记录 | `REVIEW-PLAN.md`，`02d20077b7ec0fa409eda573877ed63e59353bae488042071c40218ab79e0706` |
| 独立实测 | `INDEPENDENT-COMPARISON.json`，`165e44e388fc7b7272d8385ddf75989ea46c233c9f784e1d7e1e191dc4f31494` |
| 独立 CLR 结构清单 | `METADATA-TABLES.json`，`6f353b471274bc719b7f6cf2e3c69a514d92b512109dc98deaa50205f7651f8f` |

## 实测

- 从空目录展开，13 个成员逐一计算 SHA-256，见 `ZIP-CONTENTS.json`。内容为可编辑 C#、常规编译 RES、公钥、入口和复核记录。程序集、PDB、证书及原件布局回放均未进入 ZIP。160 B 公钥与两端 Assembly 公钥逐字节一致。冻结包与记录的核对以实际 SHA-256 为准。
- 正向构建用 Roslyn `3.11.0-4.21403.6 (ae1fff34)`，目标 .NET Framework 4.5.2，外置引用为该引用包的 `mscorlib.dll`、`System.Core.dll`、`System.dll` 和安装目录的 `DevExpress.Data.v23.2.dll` 23.2.4.0（公钥令牌 `b88d1754d700e49a`，SHA-256 `9f7d7c47cc11685e59b76b18a75a5da0ada9bcd8bc2e4a5bc105f5eded1b6493`）。编译器、引用及旁路文件指纹在 ZIP 的 `build-plan.json`。退出 0。省略 `--original` 和 `--pefile-dir` 再用另一空输出目录 `compile-only` 构建，所得 DLL 指纹相同。纯构建需要 Windows 上可运行的 Roslyn 和 .NET Framework 参考程序集。现代 .NET SDK 以及原件均无需参与编译。
- ILDasm 9.0.23 同时输出原件和实测产物的指令字节、令牌及 RAW EH。比较仅去掉行首尾空白以及 MVID、映射地址、方法 RVA 和资源导出路径四类注释，保留 `.imagebase`、指令、令牌绑定、属性、声明和异常表。全部静态 IL 文本投影相等，规范化文本指纹为 `ef7e8765d3e4ef2ceb0235a46759fdcc765afd5405a41acde14b92c54c545b17`。185 个 MethodDef 包含 146 个真实方法体和 39 个抽象声明，核对 7,908 字节、3,146 条 CIL 指令行及 16 个异常区域。独立 `PEReader` 输出 45 个 TypeDef（含 Module）、59 个 FieldDef、40 个属性、0 个 EventDef、4 个 AssemblyRef 和 0 个 ManifestResource，程序集名称、版本、公钥和所有引用绑定一致。
- 两边 PE 均只有一个 `RT_VERSION`，类型、名称、语言为 `16/1/0`，代码页 0，内容 1,074 B，SHA-256 `54fb76efd5949b46d326811842ee1901ef7dca7f0058babb2b8c57e21fc4b079`。两端独立导出 RES 也逐字节相等，1,140 B，SHA-256 `ad288b3171589acfd6bfcd5711a362a234489fb331ab46805c284854771f3b77`，与包内 RES 相同。
- PE 机器类型、子系统、对齐、首选基址、DLL 标志和 CLR 头一致，唯一原生导入和跳板目的地均是 `mscoree.dll!_CorDllMain`，非填充重定位均为入口后 2 B 的 HIGHLOW。原件和复编 DLL 的 PE 入口 RVA 为 36,706 和 36,578，跳板均为 `ff2500200010`。候选 `.text` 虚拟尺寸减少 128 B，和原件相比少了类型 19 的 PDB 校验记录，另有 MVID 与 PE 时间戳差异。双方的 128 B 强名槽一边有原件签名，一边全零。原件 Authenticode 表在 31,232 偏移处，占 10,344 B，复编产物无该表。候选 `/publicsign` 保留公钥身份，无可验证的厂商签名。
- 历史 v2 部件及结论仅作来源线索。此次实现证据来自独立源码编译的 DLL 和安装原件两份输入的直接对照。

## 阴性对照与包装方法复查

| 控制样本 | 唯一改动 | 实测 |
| --- | --- | --- |
| 方法 | 在独立副本 `CalcHorizontalLabelBoundsCore` 中把首个角度平均值常量 2.0 改为 3.0 | 退出 2。交付比较器在 MethodDef `0600005d` 定位 1 个方法差异，另 145 个方法体及 39 个声明相等。独立 ILDasm 在 `IL_0003` 只报告一条 `ldc.r8` 值的变化，资源和 ABI 相同。候选 SHA-256 为 `f2f67145dd2db655278e160a2a69092de1451dea6c75bb3c748365343ddd1d74`。 |
| 资源 | 独立 RES 副本的 `VS_FIXEDFILEINFO.dwFileVersionLS` 仅最低位改变，固定版本由 23.2.4.0 变为 23.2.4.1 | 退出 2。交付比较器标记资源差异，方法和 ABI 均通过。ILDasm 的全量 IL 相等，独立 RES 与 PE 资源内容均有差。候选 SHA-256 为 `0529285f278852a55d3221e14fa66a26c38869bdaab95de8187513e724b9cfdf`。 |

`reproduce.py` 从收到的编译输入调用 Roslyn。比较主判断来自 `managed.check` 读取实时 CLR 元数据、方法及异常区域，逐资源对比同身份的大小、代码页和内容，另核对 PE 装载 ABI。`managed.py`、`ManagedEvidence.cs`、`pe_resources.py`、`version_resource.py` 与本机共享文件 SHA-256 一致。为 PowerShell 7.2 / .NET 6 产生的临时适配只替换流 SHA-256 调用，并通过同文件编译的读满循环补充 `ReadExactly`。适配在本次证据路径执行，未修改共享工具。入口不读取旧版结论或包内预先生成的比较报告来赋予实时判定。源版本、编译器、引用、输出等指纹用于标识与追溯。原件 SHA-256 由复跑包装在调用比较器前核对，比较器自身会记录实际收到的原件 SHA-256。

## 独立命令和证据

下列命令从 Aspen 项目根运行。`$r` 指本报告所在绝对路径。再次运行时应使用一个全新复核目录，带入各复核脚本和预先记录。构建外置参数的现役绝对路径由 `rebuild.ps1` 解析；比较需要安装原件、Python 3.12、PowerShell 7.2.2 和 pefile 2024.8.26。ILDasm 9.0.23 SHA-256 为 `79509cec19209578a6b8a7e6aff3e5ae5e75d3a21c59107021f7e99ad4888541`。

```powershell
& (Join-Path $r 'rebuild.ps1')
# 入口内部以绝对路径设置 $csc $framework $data $output $original $pefile
# 在空目录展开并进入 ZIP 根，执行：
python -B .\reproduce.py --csc $csc --framework-refs $framework --devexpress-data $data --out $output --original $original --pefile-dir $pefile
# 以下以盘上 ILDasm 读原件和实测 DLL，输出位置设在 $r\il
& $ildasm /BYTES /TOKENS /RAWEH /UTF8 "/OUT=$r/il/original.il" $original
& $ildasm /BYTES /TOKENS /RAWEH /UTF8 "/OUT=$r/il/candidate.il" $candidate
& (Join-Path $r 'run-control.ps1') -Case method
& (Join-Path $r 'run-control.ps1') -Case resource
python -B (Join-Path $r 'inspect_independently.py') --original $original --review $r --pefile-dir $pefile --ildasm $ildasm
& (Join-Path $r 'inspect-metadata.ps1')
```

`build/comparison.json` 与 `method-build/comparison.json`、`resource-build/comparison.json` 分别是正向和两个阴性控制的交付比较器实测。逐件命令、输入和输出指纹、成员覆盖、PE 差异及独立定向差异均可从 `INDEPENDENT-COMPARISON.json`、`METADATA-TABLES.json`、`ZIP-CONTENTS.json` 与 `EVIDENCE-SHA256.json` 回读。双方均为静态文件读取。

