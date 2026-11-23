# zedstwu.dll s85 续领

NATIVE-350，owner upstream，assigned_seq=85，自 #13 ACK 起 24 小时。zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。

恢复 [0x15c74,0x15c98)，片段 SHA-256 `601c3b9783b84859e5612bf54a500539f69f2005c8e71d70ba2fdb20992f42cc`。恢复 0x15c74 的完整宿主，核对 0x15c7c 至 0x1654c 的实参和返回、0x15c85 与 0x15c89 的条件、0x15c8b 对 .data 槽 0x22cb8 的原子交换及 0x1c1dc 的展开。记录该槽的初始化证据与写入边界。

按[上游原生覆盖 v1](../standards/native-coverage-upstream.v1.md)运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL --submission CANDIDATE` 和局部回编，记录缺口与证据指纹。[上轮裁定](../outbox/NATIVE-350/s81-decision.md)
