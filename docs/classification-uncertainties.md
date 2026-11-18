# Properties 分类不确定项与纠正（2026-11-18）

本轮只复核新增的 Aspen Properties。Aspen Plus 沿用已固定的分类结果，作为只读对照基线。上轮把复核扩大到 Plus 并新增其待核实统计，超出了本轮任务范围；这些重分类和统计已撤出当前交付，相关本地快照仅作历史保留。

Properties 主包初始有 207 条显式疑点，配套包 170 条，合计 377 条来源记录。其中 373 条复用此前相同内容哈希的结构证据，4 条重新检查。后续检查发现通用资源/数据规则漏标初分项，不能用显式待核实为零代表 Properties 分类全部验收。

## 本轮处理方式

先按内容 SHA-256 对照既有 Plus 分类。相同内容直接复用原分类及分析记录，不重新检查或重标 Plus；剩余 Properties 新内容再单独核验。本轮有 5,155 条 Properties 来源记录继承既有 Plus 分类。

Properties 的 `vba_caller.xlsm`、`Calculation.xlsm`、`Regression.xlsm` 内部 `xl/vbaProject.bin` 曾被当成普通数据。本轮核对完整内容哈希及 OLE/VBA 存储，纠正 3 个不同 VBA 项目、6 条安装包 / 已安装来源记录，改为“需要逆向”。VBA 代码恢复尚未验收。

## Properties 尚缺的证据

| 项目 | 数量与口径 | 后续工作 |
| --- | --- | --- |
| 首选来源的新内容规则初分项 | 613 条 | 核验具体格式、内部成员和原版读取用途；尚未通过分类验收 |
| 全部 Properties 新内容待复核项 | 3,441 条，含备选和重复来源 | 逐内容核验，保留原暂定路线；不代表这些条目全部含程序 |
| APED 内容不可读 | 8 条，已包含在上述全来源待复核项中 | 原始内容及 SHA-256 尚未取得；保留读取失败记录 |
| Properties 安装目标未解析 | 98 条载荷记录 | 确定 `[TARGETDIR]` 的真实位置；与内容分类分别统计 |

此前的 1,041 条 Properties 首选初分项中，428 条与既有 Plus 分类同哈希，直接继承已有结果；剩余 613 条才是本轮新增待复核项。此前列出的 Plus 1,129 条等统计不作为本轮欠项。

最新入口为 `.local/properties-classification-20261118-reorganized/README.md`；未确定项只列在 `03-undetermined/files.csv`，已从“需要逆向 / 不需要逆向”两组移出。证据为 `.local/properties-only-20261118-review-final/`，含 `confidence-audit.json`、`category-corrections.csv`、`remaining-review.csv` 和 3 份 VBA 结构核验记录。Plus 分类逐字段保持基线一致、三份共用索引完整性与分类纠正另有验证记录。所有原快照继续保留，数据库和公式资产未改动。

本轮重整理保留全部 Properties 来源：两类已确认路线加尚未确定三组互不重叠。尚未确定项保留暂定分类和具体原因；其中有重复的内容附重复标记，待分类确认后再进入相应重复清单。原 19,298 条 Properties 归属来源全部保留，Plus 原分类文件的哈希核对不变。
