# 安装程序优先扫描（2026-11-18）

本页保留首次 Plus 扫描的统计。新增 Properties、配套数据库服务器及双产品共用分类的最新入口见[双产品盘点](plus-properties-inventory.md)。后续按后缀抽样并按文件结构修订了分类，最新清单入口和结论见[后缀抽样分类复核](suffix-sample-classification.md)。

后续逐文件工作选择 **Aspen Plus 原版安装程序为主来源**。已安装程序只用于备选补充、按哈希核对版本及原版运行观察。先读取安装包中的原始载荷，再在主来源缺失或需要解释安装后差异时查找备选文件。

本轮完成文件扫描、分类、清单统计与核验；未运行安装器、未启动新一轮反编译，也未开始 Windows 或 Mac 编译。两类清单表示处理路线，与 `01-completed/`、`02-incomplete/` 的成果验收分类分别使用。

## 扫描范围

- 首选产品：`3-ENG/Aspen-V15-ENG (2)/aspenONEMedia/aspenonesuite/Process Modeling (Aspen Plus) V15 (64bit)/Process Modeling (Aspen Plus) V15 (64bit).msi`。MSI 产品版本为 `41.0.0`。
- 对该 MSI 的全部 2,097 个外部 CAB 逐成员读取文件头、内容长度和 SHA-256；用只读 Windows Installer API 恢复 File、Component、Directory 和 Media 的来源对应，保留原始文件名、目标相对目录、组件、CAB 和包内标识。路径中的系统目录保留为 MSI 符号根，不猜测安装后的实际位置。
- 对该 MSI 的 Binary 与 Icon 表共 91 个内嵌流另建清单；表内名称是安装器标识，未虚构不存在的原始文件名。
- 已下载介质根 `C:/Users/Administrator/Desktop/AspenONE V15.0(1)` 的物理文件全部登记。其他产品的 ISO/MSI/CAB 只登记容器，不将其内部文件称为已展开或已完成扫描。
- 备选扫描覆盖 `C:/Program Files/AspenTech`、64/32 位 `Common Files/AspenTech Shared`、`C:/Program Files (x86)/AspenTech` 和 `C:/ProgramData/AspenTech`。它们全部标记为备选，不自动进入首选开发队列。
- 对主产品载荷和物理文件中识别出的 ZIP 格式容器枚举一层成员，包括示例容器内的 DLL。更深的嵌套容器未展开。

## 统计口径

物理文件共 **114,757 个**：下载介质 14,832 个、已安装备选 99,925 个。这些数字按来源路径计数，不是去重后的内容数。

| 清单层次 | 需要逆向（含待核实候选） | 不需要逆向 | 合计 |
| --- | ---: | ---: | ---: |
| Aspen Plus CAB 载荷 | 1,633 | 3,610 | 5,243 |
| MSI Binary/Icon 内嵌流 | 63 | 28 | 91 |
| 主载荷 ZIP 内层成员 | 45 | 1,516 | 1,561 |
| 全部来源与内层成员的清单行 | 11,798 | 121,422 | 133,220 |

最后一行包含物理容器及其内容，也包含其他产品备选文件，不能当作 Aspen Plus 独立原始文件数。首选清单另含 2,098 个物理 MSI/CAB 容器；它们归入不需要逆向类，内部程序单独列出。

“需要逆向”包括编译程序、可能含实现的 COFF 库、宏载体与未知二进制。仅主 CAB 载荷中就有 368 个需进一步判别的候选，其中 14 个为未知二进制；不表示每个候选均已证明含有程序实现。仅导入库与实现库仍需成员级区分。

“不需要逆向”包括图标、资源、数据、文档、已有文本源码/脚本及安装容器；它们按原格式读取或提取。IL-only PE 的 MethodDef 行数为零，或原生 PE 没有可执行区段时，归入资源/元数据类。格式解析可能仍需研究，分类不构成业务语义或恢复完整性的验收。

## 本地清单

本轮正式入口：`.local/installer-first-inventory-20261118-verified/README.md`。

| 文件 | 用途 |
| --- | --- |
| `01-needs-reverse/files.csv` | 全来源需要逆向及待核实候选 |
| `02-no-reverse/files.csv` | 全来源不需要逆向的文件 |
| 两类目录下的 `primary-files.csv` | 首选产品安装器、载荷与内层成员；后续先从这里取文件 |
| 两类目录下的 `backup-files.csv` | 已安装文件及其内层成员，只作备选 |
| 两类目录下的 `surrounding-media.csv` | 其他下载介质及周边文件，不混入首选来源 |
| `extension-statistics.csv` | 按大类、后缀和来源统计数量、大小与待核实数 |
| `physical-files.csv` | 114,757 个物理文件的扫描快照 |
| `installer-payload.csv`、`msi-tables.json` | 主 CAB 全载荷与 MSI 原表的对应证据 |
| `installer-msi-streams.csv` | 主 MSI 内嵌流 |
| `embedded-members.csv`、`zip-results.json` | ZIP 内层清单及加密状态 |
| `summary.json`、`verification.json` | 数量、异常、来源对应和独立哈希核验结果 |
| `physical-evidence.json` | 原始物理扫描快照的路径、哈希和时间 |

两大类及其子清单均按**末级后缀转小写后排序**，同后缀再按来源优先级、来源与路径排列。原始文件名与路径保持原大小写，无后缀单列。MSI 内嵌流保留表内标识，其标识后缀不一定代表磁盘文件格式；实际格式另有字段。

每行保留来源、路径、所属容器/成员、大小、可读取的版本、SHA-256、实际识别格式、分类理由与待核实项。MSI Version 可能引用伴随文件，不保证每个载荷都有独立 PE 版本资源。同哈希使用相同 `analysis_key`，保留两边来源；未读到内容的行没有伪造哈希。共有 5,333 个备选物理文件与主载荷的某个 SHA-256 一致。

物理文件于北京时间 18:02 起扫描；正式清单沿用该次物理快照，并补充核验主 CAB 与 MSI 内嵌流。原快照及中间记录分别保留在本轮其他新路径，未覆盖历史资料。整个详细清单、安装器数据与研究证据继续仅本地保存；仓库仅保存工具、选择与汇总说明。

## 验证及读取边界

- MSI File 表 5,243 条全部一一匹配主 CAB 载荷；缺失、重复、未映射、大小不符与所属 CAB 不符均为零。
- 全部 2,097 个主 CAB 读取成功，所有载荷有 SHA-256。另选托管 DLL、原生 DLL、COFF 库与数据文件四个样本，独立用 7-Zip 输出内容复核长度和 SHA-256，均一致。
- 验证了两大类的数量、后缀排序、子清单分区与异常条目不产生有效 `analysis_key`。
- 备选 APED 运行目录的 8 个 MDF/LDF 文件被占用，已登记路径和大小，内容及哈希不可读。未停止数据库服务或更改源文件。
- 备选 HYSYS 的 6 个 ZIP 内共有 6,281 个加密成员，已枚举名称与目录大小，未读取内容或生成 SHA-256。加密条目的分类仅依据名称，未知格式保留待核实标识。
- 受保护的数据库提取包、公式资料与所有原归档未作为输出目标，也未进行清理或覆盖。

工具为 `tools/inventory_aspen_sources.py`，使用 Python 标准库和 Windows 只读 MSI/Cabinet API。输出路径必须不存在；可显式复用同范围的物理快照并记录其来源哈希，不把复用说成另一次现场扫描。
