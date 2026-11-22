# WrapSaveMergeNNFiles.dll 第二十五号续领

NATIVE-340，owner tietoumiao，assigned_seq=25，自本轮 #13 ACK 起 24 小时。原件 SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`，来源见[首轮卡](NATIVE-340.md)。以 [#438 固定交付](https://github.com/DenseFLoe/Aspen-for-mac/tree/24fdc60ded7fc4c37184124a25657a6d09dda8ba/handoff/inbox/NATIVE-340) 和[第二十一号裁定](../outbox/NATIVE-340/s21-decision.md)为输入。沿用已核证的全部 237 条槽跳转及 228 个回编桩。

按主表盘点 15 托管、15 原生未决。先处理 MethodDef `0x06000030` 的 `IL_0041` 和 `IL_004f`。前者包含槽位 `+0x68` 与签名令牌 `0x11000044`，后者包含槽位 `+0x10` 与签名令牌 `0x11000043`。逐条核对原件 IL、对象生产路径、槽和签名。原生部分先沿宿主 `0x20cc` 的 `0x21ae` 查 R9 来源。对已证路径更新主表，保留运行期依赖和其余位置清单。将 `fixup_edges_ok` 与全量验证、历史子集的指标对齐。

按[原生覆盖标准](../standards/native-coverage-evidence.v1.md)运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original ORIGINAL`，再运行上游 [s21 原件核对脚本](../outbox/NATIVE-340/check-s21-438.py) 保证旧证据保持。发布本轮开工、提交、逐址核验与文件指纹，在 #13 报固定 head。
