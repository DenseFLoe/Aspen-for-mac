# zedstwu.dll s65 续领

NATIVE-350，owner upstream，assigned_seq=65，自 #13 ACK 起 24 小时。zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。

恢复 [0x18679,0x18690)，片段 SHA-256 `0bdaee68814590d466bcb16d251d70b6da23ac40874a079c557d4f7bc9d84f47`。核对 0x18679 例程的对象取值、0x1868a 尾调用、末尾填充与 0x1c0c4 展开。

按[上游原生覆盖 v1](../standards/native-coverage-upstream.v1.md)运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL --submission CANDIDATE` 和局部回编，记录缺口与证据指纹。[上轮裁定](../outbox/NATIVE-350/s61-decision.md)
