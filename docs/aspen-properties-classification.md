# Aspen Properties 当前分类入口

当前只使用 `.local/properties-classification-20261118-reorganized/README.md` 作为 Properties 分类入口。Plus 继续使用原分类，本轮只读对照。旧轮次清单保留为历史记录。

按用户确认，共五份清单：

| 清单 | 来源记录 | 首选安装来源记录 | 本地文件 |
| --- | ---: | ---: | --- |
| 需要逆向 | 1,862 | 1,169 | `.local/properties-classification-20261118-reorganized/01-needs-reverse/files.csv` |
| 不需要逆向 | 13,995 | 5,595 | `.local/properties-classification-20261118-reorganized/02-no-reverse/files.csv` |
| 需要逆向中的重复项 | 1,826 | 1,138 | `.local/properties-classification-20261118-reorganized/01-needs-reverse/duplicates.csv` |
| 不需要逆向中的重复项 | 9,149 | 4,831 | `.local/properties-classification-20261118-reorganized/02-no-reverse/duplicates.csv` |
| 尚未确定 | 3,441 | 613 | `.local/properties-classification-20261118-reorganized/03-undetermined/files.csv` |

需要逆向、不需要逆向、尚未确定三组互不重叠，合计覆盖 19,298 条有 Properties 归属的来源记录。旧混合索引中仅属 Plus 的对照来源不计入 Properties 数量。两份重复清单是已分类两组的附加子集，不能再次相加。

`priority=1` 表示 Properties 主包、配套数据库服务器及其载荷、安装流和内层成员；`priority=2` 表示已安装补充。每份 CSV 按末级后缀排序，保留原路径、包内成员、安装组件、版本、SHA-256、分析键、分类理由与证据。数量按来源记录计，包含容器、成员及副本，不是去重后的文件内容数。

`duplicate_type` 区分与 Plus 同哈希重复、Properties 自身不同来源重复，允许同时成立。原名相同但内容哈希不同不算重复；内容不可读时不伪造哈希。对应来源示例在 CSV 中，全部对应关系位于同目录根下的 `duplicate-groups.json`。分类未定但存在重复的内容仍留在“尚未确定”，带重复标记。

未确定项保留暂定路线 `proposed_category` 与原因 `uncertainty_reason`，不再混入“不需要逆向”。其中 8 个运行中 MDF/LDF 内容不可读。98 条符号安装路径的定位状态另有字段，与处理路线是否确定分别记录。

原始 Properties 主包 CAB 载荷 2,867 份，配套包 1,553 份的来源记录均保留。此处是处理路线分类，不是反编译已完成 / 未完成验收。完整清单及原资料仅本地保存；仓库仅保存工具和汇总说明。
