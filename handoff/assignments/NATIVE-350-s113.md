# zedstwu.dll s113 续领

NATIVE-350，owner upstream，assigned_seq=113，自 #13 ACK 起 24 小时。zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。

恢复 `[0x15f40,0x15f9b)`，片段 SHA-256 `8585200104557f7b6cb9f862521c227b0d4f37278a44eecde7e5ad32bc5dd2e9`。核对相邻有异常展开记录的未覆盖例程、调用和完整展开。

运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL --submission CANDIDATE` 和局部回编。[上轮裁定](../outbox/NATIVE-350/s109-decision.md)
