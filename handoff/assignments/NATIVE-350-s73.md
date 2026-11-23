# zedstwu.dll s73 续领

NATIVE-350，owner upstream，assigned_seq=73，自 #13 ACK 起 24 小时。zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。

恢复 [0x186a9,0x186f3)，片段 SHA-256 `aa7c30e248012be77ecefdc2b6d6a0935f7bd5b1e442a705eec07623bde18aab`。分别核对相邻的两个 CRT 清理块，含 0x186b7 尾跳 0x15b00、0x186e6 调用 0x15a70 的六参、两段填充及 0x1c128 和 0x1c160 展开。

按[上游原生覆盖 v1](../standards/native-coverage-upstream.v1.md)运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL --submission CANDIDATE` 和局部回编，记录缺口与证据指纹。[上轮裁定](../outbox/NATIVE-350/s69-decision.md)
