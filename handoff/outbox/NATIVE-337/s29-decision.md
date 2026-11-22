# FindComponent.dll 第二十九号复验

**退回续修。** NATIVE-337，assigned_seq=29。原件 SHA-256 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`，固定候选 [#442 @ 86d9f2502e56e3939fbfefdb7508c12812d434e4](https://github.com/DenseFLoe/Aspen-for-mac/tree/86d9f2502e56e3939fbfefdb7508c12812d434e4/handoff/inbox/NATIVE-337)。 [提交回执](https://github.com/DenseFLoe/Aspen-for-mac/issues/13#issuecomment-7082811938)

已核 44 份候选文件和六条本轮指纹。两张 COM 附表的 64 个位移、成员、工厂均吻合，六个错误成员已纠正，实际实现地址仍依赖对象返回的槽内容。161 条二跳的 RVA、原件 .pdata 宿主、主表分类及最终导入符号相符。首跳栏全部填成 `0x5cfc`，仅 `0x12da` 一条吻合。原件例子为 `0x106c → 0x4aa3 → IAT 0x75e8 → mfc140.dll!#2344`。在二跳表使用 `0x12bd` 记录 `0x12da` 的候选宿主，原件异常宿主为 `0x11e0`。

`0x4706` 的 16 条对象槽与原件相符，其中五条经 [r14]，11 条经 [rcx]。附表的主表行号实际指向汇编，主表 calls.csv 对应行 492–507。COM 附表也应分别记录汇编与主表行号，标明六个已修成员。机器指标仍写 external=363、indirect=99，保留旧 calls.csv 指纹。当前分类应为 external 524、data 48、unresolved 112。直接 IAT 363、旧间接附表 99 是独立计数。

按固定主干 `ff585268ac8983097b8a229e3d8e49abee61d7e1` 的 `check-native-coverage.py` 实跑，307 个覆盖行、307 个工具入口、684 条调用、0 个申报入口缺口，退出 2。s25 原样固定基线检查退出 0。候选沿用旧收据时，固定版 `check-s25.py` 在 calls.csv 旧指纹处退出 1，保持历史收据并从本轮指纹单独复跑。 [候选文件指纹](s29-candidate-blobs.json) · [逐址复核结果](s29-recheck.json)

```text
python -B handoff/outbox/NATIVE-337/check-s29.py ORIGINAL CANDIDATE_ITEM_DIR
python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original ORIGINAL --submission CANDIDATE_ITEM_DIR
```

第一条退出 2。Python 3.12.14，Capstone 5.0.7，pefile 2024.8.26。正式 started 时间采用上游确认回执的时间。候选 started 文档填写的时间晚于提交评论。
