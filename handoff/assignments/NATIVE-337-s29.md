# FindComponent.dll 第二十九号续领

NATIVE-337，owner tietoumiao，assigned_seq=29，本轮 #13 ACK 后 24 小时。原件 SHA-256 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`，见[原任务](NATIVE-337.md)。以 [#436 固定交付](https://github.com/DenseFLoe/Aspen-for-mac/tree/fb049d7760ecdc038a6a468f5afa6d5c391a612c/handoff/inbox/NATIVE-337) 与[第二十五号裁定](../outbox/NATIVE-337/s25-decision.md)接续。沿用已对齐的 99 条清单引用、16 个槽证据和此前通过的原件比对。

1. 用原件解出的指令操作数填满 64 个 `disp`，以三个已核实的 IDispatch 槽位校正六个错误成员。各站点保留原件 RVA、工厂或对象来源及目标模块的恢复条件。
2. 从主表按 RVA 重生成 161 条二跳附表分类，并生成真实 external/data/unresolved 指标。直接 IAT 数和间接附表行数单列。记录变化的逐件指纹。
3. 补记 `0x12da` 的原件异常宿主与候选子清单。对 `0x4706` 保留原件展开片段及链到 `0x4690` 的关系、原件槽位、主表行号和对象来源；按证据绑定目标。

按[标准](../standards/native-coverage-evidence.v1.md)运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original ORIGINAL` 及 `python -B handoff/outbox/NATIVE-337/check-s25.py ORIGINAL CANDIDATE_ITEM_DIR`。交付本轮开工、提交、按地址可复跑证据与完整指纹，在 #13 给出固定 head。
