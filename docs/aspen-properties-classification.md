# Aspen Properties 当前分类入口

当前使用 `.local/properties-install-paths-20261119-verified/README.md` 作为 Properties 分类及安装定位入口。它保留原分类，补充 98 条安装目标证据，见[安装目标落实](properties-install-paths.md)。原未确定内容已深入核验，见[逐内容核验记录](properties-deep-confirmation.md)。Plus 继续使用原分类，本轮只读对照。旧轮次清单及源码证据保留。

按用户确认，共五份清单：

| 清单 | 来源记录 | 首选安装来源记录 | 本地文件 |
| --- | ---: | ---: | --- |
| 需要逆向 | 1,866 | 1,172 | `.local/properties-install-paths-20261119-verified/01-needs-reverse/files.csv` |
| 不需要逆向 | 17,432 | 6,205 | `.local/properties-install-paths-20261119-verified/02-no-reverse/files.csv` |
| 需要逆向中的重复项 | 1,828 | 1,139 | `.local/properties-install-paths-20261119-verified/01-needs-reverse/duplicates.csv` |
| 不需要逆向中的重复项 | 10,735 | 5,439 | `.local/properties-install-paths-20261119-verified/02-no-reverse/duplicates.csv` |
| 尚未确定 | 0 | 0 | `.local/properties-install-paths-20261119-verified/03-undetermined/files.csv` |

需要逆向、不需要逆向、尚未确定三组互不重叠，合计覆盖 19,298 条有 Properties 归属的来源记录。旧混合索引中仅属 Plus 的对照来源不计入 Properties 数量。两份重复清单是已分类两组的附加子集，不能再次相加。

`priority=1` 表示 Properties 主包、配套数据库服务器及其载荷、安装流和内层成员；`priority=2` 表示已安装补充。每份 CSV 按末级后缀排序，保留原路径、包内成员、安装组件、版本、SHA-256、分析键、分类理由与证据。数量按来源记录计，包含容器、成员及副本，不是去重后的文件内容数。

`duplicate_type` 区分与 Plus 同哈希重复、Properties 自身不同来源重复，允许同时成立。原名相同但内容哈希不同不算重复；内容不可读时不伪造哈希。对应来源示例在 CSV 中，全部对应关系位于同目录根下的 `duplicate-groups.json`。分类未定但存在重复的内容仍留在“尚未确定”，带重复标记。

原 3,441 条未确定来源覆盖 2,481 个可读内容哈希和 8 个读取受限来源。本轮逐内容核验全部哈希，并以当前只读 SQL 系统目录确认后者的数据/日志身份。新确认的 3 个旧版 `.xls` VBA 项目共 4 条来源进入“需要逆向”；31 个内部模块另列，源文本归档全部标记未完成。

分类未确定已为零，但 8 个运行中 MDF/LDF 的原内容及 SHA-256 仍不可读，`access_limitation` 保留原读取限制，不参与重复匹配。98 条旧符号目标现已确认均属 GAC：93 条本机内容与载荷相同、4 条路径已定但内容不同、1 条本机组件禁用且无物理路径；定位状态与分类分开记录。HMS/SDF 内部完整解码、VBA 完整恢复、编译及行为验收均未因此完成。

原始 Properties 主包 CAB 载荷 2,867 份，配套包 1,553 份的来源记录均保留。此处是处理路线分类，不是反编译已完成 / 未完成验收。完整清单及原资料仅本地保存；仓库仅保存工具和汇总说明。
