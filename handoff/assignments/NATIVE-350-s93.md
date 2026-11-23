# zedstwu.dll s93 续领

NATIVE-350，owner upstream，assigned_seq=93，自 #13 ACK 起 24 小时。zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。

恢复 `[0x15cc4,0x15cfe)`，片段 SHA-256 `22f4dfa6d1add55d959e2ab6d2e7f0b7192c75d500d2b3ae08b0e971e5d042f9`。恢复退出注册包装函数，逐址核对 0x22cc8 的 -1 哨兵、两个 UCRT 导入和返回值映射。

运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL --submission CANDIDATE` 和局部回编。[上轮裁定](../outbox/NATIVE-350/s89-decision.md)
