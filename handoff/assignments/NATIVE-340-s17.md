# WrapSaveMergeNNFiles.dll 第十七号续领

NATIVE-340，owner tietoumiao，assigned_seq=17，本轮 #13 ACK 后 24 小时。固定原件 `64670801de54e990f975aaeda06e89340c0e4e08:issue-materials/340/WrapSaveMergeNNFiles.dll`，SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。基线为 #419 的 `b16fc9edf36dd9355e6ff083b3566ea8cbb57fdf` 和 [第十三号逐址复验](../outbox/NATIVE-340/s13-decision.md)。

在原件上逐条使用 [126 个 JMP 与槽的映射](../outbox/NATIVE-340/s5-native-fixup-targets.csv)，将 122 个缺失位置补入原生汇编与调用表，对 126 处已确定的 MethodDef 边标注 native → managed、槽 RVA 和 token。保留运行期地址的待核条件。237 槽统计单列。将 16 个外部 newobj 按行号与目标补入主调用表，另在内部证据保留 5 个本模块构造调用，保持 19 个非空类型的已核定范围及 61 条旧跨界边。恢复 0x3660 的 GS 与间接加载语义并同步 metrics.json。

按 [覆盖证据 v1](../standards/native-coverage-evidence.v1.md)，从仓库根运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original <原件> --submission handoff/inbox/NATIVE-340`。提交 s17 开工与提交回执、主表及逐址证据，在 #13 报最新固定 head。
