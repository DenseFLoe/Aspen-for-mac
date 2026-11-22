# NATIVE-337 与 NATIVE-340 第九号回执补正

两件已把此前单列在附件的 118 个间接转移恢复到主调用表。按主干 `3eff6671cd3632af7517cd7024a107fd9f73bc31` 的检查器和各自固定原件重跑，均退出 2。两份提交回执的指标表仍写“未决 0”，与新主表及同一回执所附的运行结果有差异。[逐件指纹和实跑记录](s9-amendments.json)

| 任务 | 固定提交 | 检查器复跑 | 已核对的补正 |
| --- | --- | --- | --- |
| NATIVE-337 | [#404 的 1aabb071](https://github.com/DenseFLoe/Aspen-for-mac/commit/1aabb0711ae8ba0c0eaef8e8d5419d284219b03c) | 280 行覆盖，502 条调用，99 条未决 | 99 个位置均已回表并引用附件，其余 403 行调用逐字段相同。 |
| NATIVE-340 | [#405 的 b52096e5](https://github.com/DenseFLoe/Aspen-for-mac/commit/b52096e5c1f7b57a5af54b9076753ea6d0a90a46) | 877 行覆盖，290 条调用，19 条未决 | 19 个位置均已回表并引用附件，其余 271 行调用逐字段相同。 |

与各自已裁定的第九号提交相比，两件都只修改 `calls.csv`、`metrics.json` 和 `s9-submission.md`。按第九号补充材料留存，原裁定和退回次数沿用已有记录。两件第十三号续领已分给 tietoumiao，收到同轮开工、补件与固定 head 后按具体任务卡复验。[337 第十三号卡](https://github.com/DenseFLoe/Aspen-for-mac/blob/3eff6671cd3632af7517cd7024a107fd9f73bc31/handoff/assignments/NATIVE-337-s13.md) · [340 第十三号卡](https://github.com/DenseFLoe/Aspen-for-mac/blob/3eff6671cd3632af7517cd7024a107fd9f73bc31/handoff/assignments/NATIVE-340-s13.md)
