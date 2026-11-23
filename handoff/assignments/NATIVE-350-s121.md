# zedstwu.dll s121 续领

NATIVE-350，owner upstream，assigned_seq=121，自 #13 ACK 起 24 小时。zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。

恢复 `[0x15fd8,0x16014)`，片段 SHA-256 `094a457256f9a9eeae0d6eb948a0ff7c2216b3d9828deea475aac9d6a440ef1f`。复核相邻 CRT 回调遍历的实际半开边界、间接调度对应关系和完整展开。

运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL --submission CANDIDATE` 和局部回编。[上轮裁定](../outbox/NATIVE-350/s117-decision.md)
