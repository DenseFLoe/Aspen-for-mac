# Aspen Plus / Aspen Properties 双产品盘点（2026-11-18）

Aspen Properties 已作为独立产品正式纳入开发，与 Aspen Plus 使用相同的开发顺序、归档和验收要求。Properties Enterprise Database Server 作为 Properties 配套安装组件单列。HYSYS、EDR 等其他产品自身文件继续范围外保留。本轮执行新增产品的第 1 步及“需要逆向 / 不需要逆向”分类，不启动 Windows / Mac 重建。

## 原版安装来源与第 1 步结果

安装介质根为 `C:/Users/Administrator/Desktop/AspenONE V15.0(1)/3-ENG/Aspen-V15-ENG (2)/aspenONEMedia/aspenonesuite/`。各目录中同名 MSI 是归属证据；三个 MSI 的 ProductVersion 均为 `41.0.0`。Plus 沿用已有逐成员盘点和后缀复核快照，Properties 两包为本轮新扫描，没有把旧快照称为重新扫描。

| 安装产品目录 | CAB | File 表 / 实际载荷 | 载荷需逆向 | 载荷不需逆向 | MSI 内嵌流 | 载荷 ZIP 内成员 |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `Process Modeling (Aspen Plus) V15 (64bit)` | 2,097 | 5,243 / 5,243 | 1,310 | 3,933 | 91 | 1,561 |
| `Aspen Properties V15 (64bit)` | 1,116 | 2,867 / 2,867 | 767 | 2,100 | 96 | 1,295 |
| `Aspen Properties Enterprise Database Server V15 (64bit)` | 379 | 1,553 / 1,553 | 319 | 1,234 | 69 | 0 |

Properties 两包共 1,495 个 CAB 均读取成功。载荷与 MSI File / Component / Directory / Media 逐项对应，缺失、重复、未映射、大小不符、所属 CAB 不符均为零。逐行记录原路径、原文件名、包内成员、所属组件、大小、内容类型、可读取的版本和 SHA-256；MSI 版本可能是伴随文件引用，不能等同于独立 PE 版本资源。安装器、资源、数据库、文本源码与编译程序分别标明处理路线。

此前为共享比对读取了 **44,561 个已安装物理文件**（此为历史来源记录，当前不重新分类 Plus）：Plus 归属 33,935 个、Properties 归属 8,292 个、双方安装表共同指向 2,334 个。覆盖两个产品各自的 Program Files、ProgramData 目录及 Properties 的 APED 目录；其他共享目录只纳入 MSI 明确指向的文件。共享目录中没有安装归属证据的其他文件不自动纳入。符号根 `[TARGETDIR]` 未强行转换为实际目录；Properties 有 98 条载荷记录保留此类未解析目标，Plus 路径记录仅作既有对照，不列入本轮待办。

## 分类复核与三份清单

**本轮仅新增 Properties 分类与复核，Plus 沿用既有分类。** Properties 与 Plus 同内容哈希的文件直接继承原分类及分析记录；Plus 清单只补共用交叉索引。上轮擅自扩展到 Plus 的重分类和新增待核实统计已撤出当前交付，历史记录保留。

Properties 初始有 377 条显式疑点，373 条复用同哈希的既有证据，4 条新检查。通用资源/数据规则还存在初分待复核项。排除可继承 Plus 分类的同哈希内容后，Properties 首选来源有 **613 条**新内容待核实。已核验并纠正 Properties 的 **3 个 VBA 项目、6 条来源记录**。详见[Properties 不确定项](classification-uncertainties.md)。

两类分别为 `01-needs-reverse/`、`02-no-reverse/`，类内按末级后缀转小写排序。它们表示后续处理路线，不表示已完成反编译；成果仍按 `01-completed/`、`02-incomplete/` 及一文件一说明验收。

已有分类证据只复用于相同内容哈希。本轮新增主来源疑点涉及四份不同内容：`Microsoft.VisualStudio.Interop.dll` 确认 16,767 个方法；`util.lib` 全成员为短导入记录或导入描述符，归入不需逆向；`vba_caller.xlsm`、`Regression.xlsm` 含 VBA，归入需要逆向。最终抽取 14 个不同内容或受限样本，其中 8 个完整读取，6 个为不可读数据库样本；首选来源四条显式分类疑点已核实，但这并未覆盖未被脚本标记的通用规则初分条目。

| 文档 | 需要逆向的来源行 | 不需要逆向的来源行 | 完整本地分类文档 |
| --- | ---: | ---: | --- |
| [Plus](aspen-plus-classification.md) | 3,791 | 48,187 | `.local/properties-only-20261118-delivery-final/plus/classification.md` |
| [Properties](aspen-properties-classification.md) | 2,632 | 19,900 | `.local/properties-only-20261118-delivery-final/properties/classification.md` |
| [两者共用](plus-properties-shared-files.md) | 2,534 | 8,189 | `.local/properties-only-20261118-delivery-final/shared/classification.md` |

三份清单均有逐来源 CSV，保留产品、安装包、原路径、组件、版本、哈希、统一分析键和分类证据。共用来源行同时出现在两份产品清单中，不从产品清单移走。统计包括容器、载荷、内嵌流、ZIP 成员及重复来源，三份有交集，不能相加当作独立文件数。总输入为 63,787 条来源记录。

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
| `.local/properties-only-20261118-delivery-final/` | 正式三份分类文档、两类 CSV、后缀统计和验证 |
| `.local/plus-properties-20261118-checks/` | 独立 CAB 样本核验及最终清单复核 |

工具另含 `tools/audit_classification_confidence.py`，必须指定 `--plus-baseline`，仅复核 Properties 新内容，冻结 Plus 原分类并继承相同哈希内容的已有结果；不宣称已对全部数据格式重新验收。原有工具为 `tools/inventory_aspen_sources.py`、`tools/audit_aspen_suffixes.py`、`tools/inventory_plus_properties.py`。后者分 `prepare` 与 `report` 两阶段；两者均拒绝覆盖已有输出路径。初始 Properties 快照中沿用旧工具的个别 Plus 范围标签在双产品基线中按实际 MSI 归属规范为 Properties，原来源、路径和内容哈希保持不变，原快照保留。
