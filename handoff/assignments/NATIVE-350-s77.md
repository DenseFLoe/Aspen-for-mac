# zedstwu.dll s77 续领

NATIVE-350，owner upstream，assigned_seq=77，自 #13 ACK 起 24 小时。zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。

恢复 [0x186f3,0x1870b)，片段 SHA-256 `515c04e0ba3bb82e249e1f52765ba9c74cf63305116d4e5c2393eb92ba558686`。核对异常记录状态值比较、SETcc 到 EAX 的返回值、0x1870a 填充及 0x1c1cc 展开。

按[上游原生覆盖 v1](../standards/native-coverage-upstream.v1.md)运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL --submission CANDIDATE` 和局部回编，记录缺口与证据指纹。[上轮裁定](../outbox/NATIVE-350/s73-decision.md)
