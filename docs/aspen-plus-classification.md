# Aspen Plus 文件分类清单

**本清单包含 7,943 条规则初分待复核来源记录，分类验收尚未完成。** 逐项见本地同目录 `remaining-review.csv`；[纠正说明](classification-uncertainties.md)记录遗漏原因与 VBA 误分类修复。

本页是可提交的 Plus 分类入口；详细逐文件文档仅在本地保存。当前范围包括 Plus、Properties，以及有证据属于两者的共享部分。完整盘点、统计口径与限制见[双产品盘点](plus-properties-inventory.md)。

| 处理路线 | 来源记录 | 本地 CSV |
| --- | ---: | --- |
| 需要逆向 | 3,795 | `.local/plus-properties-20261118-corrected-delivery/plus/01-needs-reverse/files.csv` |
| 不需要逆向 | 48,183 | `.local/plus-properties-20261118-corrected-delivery/plus/02-no-reverse/files.csv` |

完整逐来源 Markdown：`.local/plus-properties-20261118-corrected-delivery/plus/classification.md`。每类另有 `primary-files.csv`、`backup-files.csv` 和后缀统计；类内按末级后缀排序。主 Plus CAB 载荷仍为 5,243 份，其中暂列需要逆向 1,310 份、不需要逆向 3,933 份；这些路线包含待复核初分项，不能将整份清单视为已通过分类验收。

共用文件在本清单、[Properties 清单](aspen-properties-classification.md)和[共用清单](plus-properties-shared-files.md)同时列出。`owner` 保留原交付归属，`memberships` 记录清单归属，`analysis_key` 使用内容 SHA-256；各安装包、路径和组件证据均保留。相同内容不会因列入共用清单而从 Plus 清单消失。

来源记录包含重复来源、容器及其内部成员，不是独立内容数量，也不是已完成反编译数量。之前的 Plus 快照和全来源历史清单继续保留。
