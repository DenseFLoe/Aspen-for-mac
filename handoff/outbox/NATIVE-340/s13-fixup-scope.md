# NATIVE-340 第十三号原生跳转计数

对应 #13 回执 7080464912，候选分支已读到完整提交 `b16fc9edf36dd9355e6ff083b3566ea8cbb57fdf`。原件 SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。已在 #13 回执 7080557763 澄清并请执行方开产物 PR。

PE 目录第 15 项为零。CLI 头偏移 0x30 的 VTableFixups 指向 0x16600，长度 0x768。整张表含 237 项、237 槽和 122 个不同 MethodDef token，Type 0xA 有 122 项，Type 0x2 有 115 项。

任务卡的 126 指 [#393 候选中漏列的原生跳转位置](s5-native-fixup-targets.csv)。对表中 126 行重新解原件指令，均为 RIP 相对 JMP。每一站点重算出的内存槽、槽中 MethodDef token 和 flags 都相符。所访问的 126 个不同槽对应 122 个不同 token。示例为 0x5004 → 0x19018 → 0x06000001。按原生指令 RVA 在 calls.csv 登记该边及证据，运行期目标不明确的位置保留各自恢复条件。

复跑 `python -B handoff/outbox/NATIVE-340/check-s13-fixup-sites.py <固定原件> handoff/outbox/NATIVE-340/s5-native-fixup-targets.csv`。来源与回执见[任务卡](../../assignments/NATIVE-340-s13.md)。
