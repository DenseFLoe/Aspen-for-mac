# Properties 重复项与 Plus 共用关联

Properties 本轮按处理路线总共附加两份重复清单。它们的当前入口为 `.local/properties-install-paths-20261119-verified/README.md`；Plus 原分类继续只读沿用。完整重复 CSV、全部重复关联及原共用索引见[仓库分类清单快照](../inventories/2026-11-19/README.md)。

| 重复清单 | Properties 来源行 | 其中与 Plus 重复 | 其中 Properties 不同来源重复 |
| --- | ---: | ---: | ---: |
| `01-needs-reverse/duplicates.csv` | 1,828 | 1,760 | 1,819 |
| `02-no-reverse/duplicates.csv` | 10,735 | 5,724 | 10,732 |

以上路径相对于当前入口目录。两种重复范围可能重叠，不能相加。重复清单是对应主分类清单的子集，不从主清单移走。只比较实际可读的完整内容 SHA-256，文件名相同或符号目标相同不作为重复依据。

CSV 的 `duplicate_type` 说明重复范围；`plus_example_path`、`properties_other_example_path` 给出对应来源示例，`duplicate_evidence` 指向 `duplicate-groups.json` 中同内容的全部双方来源。Properties 主分类列出该来源，Plus 原清单列出其对应来源，本页及重复清单提供交叉关联。

原未确定项中带重复标记的 1,588 条来源已随逐内容核验结果进入对应分类及其重复子清单。当前未确定清单为空。8 个运行中不可读的数据库由 SQL 系统目录确认身份，但继续不参与哈希重复匹配；读取限制单列。与 Plus 重复的来源数不变，没有据此重新分类 Plus。

原三份混合索引及历次共享比对记录继续本地保留为历史证据，不覆盖。当前 Properties 阅读方式见 [五份清单说明](aspen-properties-classification.md)。同内容只证明来源之间的字节交集，不单独证明运行调用关系。
