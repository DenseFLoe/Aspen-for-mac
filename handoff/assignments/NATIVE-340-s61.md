# NATIVE-340 s61 续领

owner tietoumiao，assigned_seq=61，自 #13 ACK 起 24 小时。原件 SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec，固定 [#450 @ 81718358](https://github.com/DenseFLoe/Aspen-for-mac/tree/817183580e8e59b82c3389a2cdf0a01c6ecb1e96)。

EH 读取器先独立核对四字节节头的 raw、virtual、file，再按申报长度核对整节。276 字节完整样本读取 10 节，物理文件减到 250 字节时报 FILE 位置 0xFA，单减 raw 或 virtual 时诊断首个失效 RVA 0x24FA。原件 0x0600000B 应报 raw_end 0x4A00、virt_end 0x4968，子句宽度 24、数量 2。原件、只翻转 jge、只改未取跳立即数三态在主表与五份附表写入实际 AL 0/1/0、跳过真/假/真。保留九／十节链、混排、两次审计和两套完整指纹。

复跑 python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original ORIGINAL --submission CANDIDATE 及[本轮复验命令](../outbox/NATIVE-340/s57-verifier-notes.md)。向 #13 提交新 head 和结果。
