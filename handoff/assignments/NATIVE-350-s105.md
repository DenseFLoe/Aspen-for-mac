# zedstwu.dll s105 续领

NATIVE-350，owner upstream，assigned_seq=105，自 #13 ACK 起 24 小时。zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。

恢复 `[0x15e90,0x15eca)`，片段 SHA-256 `06e4fb35ab14c9fe4c5e1bd9b106ce05a66e5b36f27cd04c8441446ffdb831b8`。核对相邻启动信息读取及标志驱动的返回值、外调和展开。

运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL --submission CANDIDATE` 和局部回编。[上轮裁定](../outbox/NATIVE-350/s101-decision.md)
