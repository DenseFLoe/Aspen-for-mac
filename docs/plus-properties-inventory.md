# Properties 盘点来源与当前分类（2026-11-18）

Aspen Properties 已作为独立产品正式纳入开发，与 Aspen Plus 使用相同的开发顺序、归档和验收要求。Properties Enterprise Database Server 作为 Properties 配套安装组件单列。HYSYS、EDR 等其他产品自身文件继续范围外保留。本轮执行新增产品的第 1 步及“需要逆向 / 不需要逆向”分类，不启动 Windows / Mac 重建。

## 原版安装来源与第 1 步结果

安装介质根为 `C:/Users/Administrator/Desktop/AspenONE V15.0(1)/3-ENG/Aspen-V15-ENG (2)/aspenONEMedia/aspenonesuite/`。各目录中同名 MSI 是归属证据；三个 MSI 的 ProductVersion 均为 `41.0.0`。Plus 沿用已有逐成员盘点和后缀复核快照，Properties 两包为本轮新扫描，没有把旧快照称为重新扫描。

| 安装产品目录 | CAB | File 表 / 实际载荷 | 载荷需逆向 | 载荷不需逆向 | MSI 内嵌流 | 载荷 ZIP 内成员 |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `Process Modeling (Aspen Plus) V15 (64bit)` | 2,097 | 5,243 / 5,243 | 1,310 | 3,933 | 91 | 1,561 |
| `Aspen Properties V15 (64bit)` | 1,116 | 2,867 / 2,867 | 767 | 2,100 | 96 | 1,295 |
| `Aspen Properties Enterprise Database Server V15 (64bit)` | 379 | 1,553 / 1,553 | 319 | 1,234 | 69 | 0 |

Properties 两包共 1,495 个 CAB 均读取成功。载荷与 MSI File / Component / Directory / Media 逐项对应，缺失、重复、未映射、大小不符、所属 CAB 不符均为零。逐行记录原路径、原文件名、包内成员、所属组件、大小、内容类型、可读取的版本和 SHA-256；MSI 版本可能是伴随文件引用，不能等同于独立 PE 版本资源。安装器、资源、数据库、文本源码与编译程序分别标明处理路线。

此前为共享比对读取了 **44,561 个已安装物理文件**（此为历史来源记录，当前不重新分类 Plus）：Plus 归属 33,935 个、Properties 归属 8,292 个、双方安装表共同指向 2,334 个。覆盖两个产品各自的 Program Files、ProgramData 目录及 Properties 的 APED 目录；其他共享目录只纳入 MSI 明确指向的文件。共享目录中没有安装归属证据的其他文件不自动纳入。此前 Properties 98 条 `[TARGETDIR]` 载荷目标已在 2026-11-19 通过 MSI 程序集表确认均属 GAC：97 条找到本机实际路径（93 条哈希相同、4 条内容不同），1 条本机组件禁用，无物理安装路径，见[安装目标落实](properties-install-paths.md)。原来源路径保留，当前五份清单增加定位证据；Plus 路径记录仅作既有对照。

## 分类复核与当前五份清单

当前五份清单及安装定位入口为 `.local/properties-install-paths-20261119-verified/README.md`，分类沿用 `.local/properties-deep-20261118-verified/` 的完整证据基线。原 3,441 条未确定来源全部明确处理路线，其中可读的 2,481 个内容哈希逐一核验；8 个受限 MDF/LDF 仅用当前 SQL 系统目录确认数据身份，内容/哈希仍不可读。新确认 3 个旧版 Excel VBA 项目、4 条来源，31 个内部模块单列未完成源文本。方法及边界见[深入分类核验](properties-deep-confirmation.md)。

**本轮仅新增 Properties 分类与复核，Plus 沿用既有分类。** Properties 与 Plus 同内容哈希的文件直接继承原分类及分析记录；Plus 清单只补共用交叉索引。上轮擅自扩展到 Plus 的重分类和新增待核实统计已撤出当前交付，历史记录保留。

深入核验前，Properties 初始有 377 条显式疑点，373 条复用同哈希的既有证据，4 条新检查。通用资源/数据规则仍有初分待复核项。排除可继承 Plus 分类的同哈希内容后，首选来源曾有 **613 条**新内容待核实，现已覆盖。当时已纠正的 **3 个 `.xlsm` VBA 项目、6 条来源记录**继续保留；本轮新确认的旧版 `.xls` 项目另计。详见[Properties 不确定项](classification-uncertainties.md)。

两类分别为 `01-needs-reverse/`、`02-no-reverse/`，类内按末级后缀转小写排序。它们表示后续处理路线，不表示已完成反编译；成果仍按 `01-completed/`、`02-incomplete/` 及一文件一说明验收。

已有分类证据只复用于相同内容哈希。本轮新增主来源疑点涉及四份不同内容：`Microsoft.VisualStudio.Interop.dll` 确认 16,767 个方法；`util.lib` 全成员为短导入记录或导入描述符，归入不需逆向；`vba_caller.xlsm`、`Regression.xlsm` 含 VBA，归入需要逆向。最终抽取 14 个不同内容或受限样本，其中 8 个完整读取，6 个为不可读数据库样本；首选来源四条显式分类疑点已核实，但这并未覆盖未被脚本标记的通用规则初分条目。

当前 Properties 分类入口为 `.local/properties-install-paths-20261119-verified/README.md`，具体五份清单及数量见 [Properties 当前分类](aspen-properties-classification.md)。两类已确认路线与尚未确定三组互不重叠；每个已确认分类各有一份附加重复清单，总共两份。

只纳入有 Properties 安装归属的 19,298 条来源记录，Plus 对照来源通过重复关系引用，不另算 Properties 文件。需要逆向 1,866 条，不需要逆向 17,432 条，尚未确定 0 条。重复清单分别为 1,828 条和 10,735 条，是对应主清单的子集，不能再次相加。此前混合索引的来源行数量不作为当前 Properties 数量。

## 验证、限制与本地证据

- 两个新 MSI 的全部载荷对应和 CAB 读取检查通过；另用 7-Zip 26.06 独立读取每包 DLL、LIB、EXE、DAT 各一份，共 8 份，长度与 SHA-256 均与 Cabinet FDI 结果一致。
- 从最终 CSV 独立复算三份清单的成员关系、后缀排序、分析键和分类一致性；共用来源行在两份产品清单完整出现，原来源及哈希无丢失。同哈希不存在跨分类冲突。
- APED 运行目录的 8 个 MDF/LDF 内容不可读。保留原路径、大小和读取错误，SHA-256 留空，不参与同内容匹配；没有停止服务、恢复数据库或修改源文件。读取受限与处理路线分类分别登记。
- ZIP 按既有规则展开一层；更深嵌套内容与完整数据库格式、业务语义、反编译和行为验证仍分别验收。共享内容只证明双包交付同一字节内容，不据此声称已验证运行调用关系。
- 原数据库提取包、公式目录与所有历史归档继续保留。新增输出均使用新路径；原安装介质、二进制、样本、详细清单和完整研究证据只在本地，仓库仅提交自编工具和汇总文档。

本地来源链：

| 路径 | 内容 |
| --- | --- |
| `.local/properties-inventory-20261118-primary/` | Properties 主包完整初始盘点、MSI 表、CAB 和哈希记录 |
| `.local/properties-inventory-20261118-server/` | 配套数据库服务器的独立初始盘点 |
| `.local/plus-properties-20261118-baseline-full/` | 本轮已安装现场读取、原清单指纹、归属对应及缺失安装目标 |
| `.local/plus-properties-20261118-classified/` | 上轮显式疑点复核快照；其零待核实统计已被本轮纠正，不作为完整分类验收 |
| `.local/properties-only-20261118-review-final/` | 仅 Properties 的新内容复核；Plus 分类冻结并按哈希继承 |
| `.local/properties-only-20261118-delivery-final/` | 重整理前的混合索引历史快照 |
| `.local/properties-classification-20261118-reorganized/` | 深入核验前五份清单的历史基线，保留原未确定项及重复关系 |
| `.local/properties-deep-20261118-verified/` | 深入分类核验基线、2,489 份逐内容/来源证据、31 份未完成 VBA 源文本及独立验证，继续保留 |
| `.local/properties-install-paths-20261119-verified/` | 当前五份清单及 98 对安装定位证据；97 条物理路径、1 条禁用组件，附独立验证 |
| `.local/plus-properties-20261118-checks/` | 独立 CAB 样本核验及最终清单复核 |

工具另含 `tools/audit_classification_confidence.py`，必须指定 `--plus-baseline`，仅复核 Properties 新内容，冻结 Plus 原分类并继承相同哈希内容的已有结果；不宣称已对全部数据格式重新验收。原有工具为 `tools/inventory_aspen_sources.py`、`tools/audit_aspen_suffixes.py`、`tools/inventory_plus_properties.py`。后者分 `prepare` 与 `report` 两阶段；两者均拒绝覆盖已有输出路径。初始 Properties 快照中沿用旧工具的个别 Plus 范围标签在双产品基线中按实际 MSI 归属规范为 Properties，原来源、路径和内容哈希保持不变，原快照保留。

本轮重整理工具为 `tools/organize_properties_classification.py`。只读已有分类与证据，不重新扫描或分类 Plus，不运行安装器或修改源文件。输出必须是新路径；对 Properties 输入和 Plus 原清单在前后核对 SHA-256。

深入核验使用 `tools/confirm_properties_pending.py`，原版读取链和 SQL 元数据分别由 `tools/inspect_properties_readers.py`、`tools/Get-PropertiesSqlCatalogEvidence.ps1` 取得，独立验收工具为 `tools/validate_properties_confirmation.py`。读取受限与已确认的分类分别记录；旧重整理工具的“不可读即未定”规则不用于覆盖当前基于 SQL 身份证据的分类。
