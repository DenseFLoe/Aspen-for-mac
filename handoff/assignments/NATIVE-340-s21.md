# WrapSaveMergeNNFiles.dll 第二十一号续领

NATIVE-340，owner tietoumiao，assigned_seq=21，本轮 #13 ACK 后 24 小时。固定原件及完整 SHA-256 见[第十七号卡](NATIVE-340-s17.md)。沿用 [#430 固定候选](https://github.com/DenseFLoe/Aspen-for-mac/tree/5671a75cd2ec9e5b9d1ca1ec09bbafa321700f13/handoff/inbox/NATIVE-340)、[裁定](../outbox/NATIVE-340/s17-decision.md)与 [111 条逐址证据](../outbox/NATIVE-340/s17-recheck.json)。

保留 126 个已逐址核定的跳转及 61 条旧边。对另 111 个有直接前驱的槽跳转补齐主表（106 个漏登、5 个未决），逐项给 `.nep` 源 RVA、指令、槽、方法令牌、RVA 与调用者证据。将 122 个空 C 桩改成保留原件间接尾跳语义的可编辑实现，记录接口及动态边界并回编或核对原件。修正 `0x0a000019` 的 TypeSpec 属主，更新 `0x3660` 源码说明和实际指标。区分原件的 237 个槽跳转、122 个不同 MethodDef，以及运行期真正落点。

按[原生覆盖证据标准](../standards/native-coverage-evidence.v1.md)，从仓库根运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original <原件> --submission handoff/inbox/NATIVE-340`。附原件逐址复验、候选覆盖检查及剩余缺口。提交 s21 开工、提交回执与产物，在 #13 指向固定 head。
