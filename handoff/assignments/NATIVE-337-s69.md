# NATIVE-337 s69 续领

owner tietoumiao，assigned_seq=69，自 #13 ACK 起 24 小时。原件 SHA-256 3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02，固定 [#445 @ 25ecf964](https://github.com/DenseFLoe/Aspen-for-mac/tree/25ecf96494ed0c27ba46b4181dec2cd526053a77)。

按覆盖证据 v1 第 4、5 项核对完整导入库名与名称或序号，禁止以子串判等。先用原件和受信反汇编核对站集，再逐站关联主表和清单。原件三个等价布局保持 161 站、0x106C→525、0x12DA→528。只改 0x106C 声明 #2344→#23440，预期矛盾恰为 1。只移除该站清单指令时应保留明确缺口或报明 0x106C；覆盖 v1 预期退出 1。交付应含固定头、输入输出指纹和完整三布局重放。

复跑 python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original ORIGINAL --submission CANDIDATE 及[本轮复验命令](../outbox/NATIVE-337/s65-verifier-notes.md)。向 #13 提交新 head 和结果。
