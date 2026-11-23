# NATIVE-337 s117 续领

owner tietoumiao，assigned_seq=117，自 #13 ACK 起 24 小时。原件 FindComponent.dll SHA-256 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`。[固定候选 #445](https://github.com/DenseFLoe/Aspen-for-mac/tree/7c18f40da2b6ef2d74a897b0983d9d5175ca20af)。

按独立部署 PE 和注册项核对完整的 CLSID→class→TypeDef/InterfaceImpl→ShowDialog 绑定，拒绝矛盾重复 CSV 行，重算活动清单并固定最终头回执。用独立部署 PE + 注册信息验证 TypeDef、接口实现、方法签名和 RVA，缺输入时明确待核。保留 s113 十五项拒绝与两个正组，增加矛盾重复 CSV、错误注册 class、裸接口大小写、缺独立签名输入四组。每组只改单项证据并重算其指纹。修复当前 109→110 清单差异，回执写活动清单 SHA-256 及最终头每条脚本指纹、命令、原始输出和真实退出。

    python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original ORIGINAL --submission UNIT

动态 DISPID 和 112 条间接目标沿各自恢复条件保留。[上游复验](../outbox/NATIVE-337/s113-verifier-notes.md)
