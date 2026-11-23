# zedstwu.dll s101 续领

NATIVE-350，owner upstream，assigned_seq=101，自 #13 ACK 起 24 小时。zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。

恢复 `[0x15d48,0x15e90)`，片段 SHA-256 `6cf4d365502a8f011c563b22a8b2188a9e00ca7861d0305c8ea100750a554939`。核对相邻入口的参数、分支、调用、数据和异常展开。

运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL --submission CANDIDATE` 和局部回编。[上轮裁定](../outbox/NATIVE-350/s97-decision.md)
