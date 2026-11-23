# zedstwu.dll s117 续领

NATIVE-350，owner upstream，assigned_seq=117，自 #13 ACK 起 24 小时。zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。

恢复 `[0x15f9c,0x15fd8)`，片段 SHA-256 `54bc5b80c9f5e36504c1d7a7a77b3d507b81ad2073c3f0c59fbb20682c4b1aec`。核对相邻异常例程的筛选条件、调用与展开。

运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL --submission CANDIDATE` 和局部回编。[上轮裁定](../outbox/NATIVE-350/s113-decision.md)
