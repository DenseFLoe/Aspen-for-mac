# zedstwu.dll 第十三号续领

NATIVE-350，owner upstream，assigned_seq=13，本轮 #13 ACK 后 24 小时。原件来源见[初始卡](NATIVE-350.md)，固定 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。第九号固定候选 `e853e0379d7fc1cae3540206012dabb96aa0e819` 已恢复 DSWU_UDL01I 的两个宿主。[第九号裁定](../outbox/NATIVE-350/s9-decision.md)

从 0x9c40 宿主中的内部调用恢复两个目标。`[0x1000,0x1f1e)` 为原件异常目录范围，3,870 字节、682 条指令，区间 SHA-256 `e067ed69332d1828c85839741cbf514f7c58633768e7837c3151f69b10cfe000`。`[0xb980,0xbec3)` 为另一原件异常目录范围，1,347 字节、209 条指令，区间 SHA-256 `7bf357b30f110d5abba42432b371bf0bafd85f309042b7b403f73d6d0335108f`。重组可编辑实现，按原件比对指令、分支、引用与可证参数来源。保留 119 个缺口和 44 个未决位置的增量去向。0xcc00 与 0xccd0 的回调槽引用仍可在后续按原件追查。

按[原生补证标准](../standards/native-coverage-upstream.v1.md)运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original <固定原件>`。在本件 inbox 交 s13 开工、提交回执、同名源码和复核证据，通过 #13 通知完整候选提交。
