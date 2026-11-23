# zedstwu.dll s69 续领

NATIVE-350，owner upstream，assigned_seq=69，自 #13 ACK 起 24 小时。zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。

恢复 [0x18690,0x186a9)，片段 SHA-256 `a54e4ac5b75e2d5ec0f89911437c11b2337c7e57f480b9eff0b262da1f5c3a7f`。核对 0x18699 从帧基址偏移 0x20 读取的字节、0x1869c 调到 0x15c74、返回与填充，以及 0x1c120 的展开记录。

按[上游原生覆盖 v1](../standards/native-coverage-upstream.v1.md)运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL --submission CANDIDATE` 和局部回编，记录缺口与证据指纹。[上轮裁定](../outbox/NATIVE-350/s65-decision.md)
