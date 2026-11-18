# Properties 重复项与 Plus 共用关联

Properties 本轮按处理路线总共附加两份重复清单。它们的当前入口为 `.local/properties-classification-20261118-reorganized/README.md`；Plus 原分类继续只读沿用。

| 重复清单 | Properties 来源行 | 其中与 Plus 重复 | 其中 Properties 不同来源重复 |
| --- | ---: | ---: | ---: |
| `01-needs-reverse/duplicates.csv` | 1,826 | 1,760 | 1,817 |
| `02-no-reverse/duplicates.csv` | 9,149 | 5,724 | 9,146 |

以上路径相对于当前入口目录。两种重复范围可能重叠，不能相加。重复清单是对应主分类清单的子集，不从主清单移走。只比较实际可读的完整内容 SHA-256，文件名相同或符号目标相同不作为重复依据。

CSV 的 `duplicate_type` 说明重复范围；`plus_example_path`、`properties_other_example_path` 给出对应来源示例，`duplicate_evidence` 指向 `duplicate-groups.json` 中同内容的全部双方来源。Properties 主分类列出该来源，Plus 原清单列出其对应来源，本页及重复清单提供交叉关联。

尚未确定项中另有 1,588 条来源带重复标记；它们保留在 `03-undetermined/files.csv`，不混入这两份已分类重复清单。运行中不可读的数据库不参与哈希重复匹配。

原三份混合索引及历次共享比对记录继续本地保留为历史证据，不覆盖。当前 Properties 阅读方式见 [五份清单说明](aspen-properties-classification.md)。同内容只证明来源之间的字节交集，不单独证明运行调用关系。
