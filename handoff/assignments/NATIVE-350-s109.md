# zedstwu.dll s109 续领

NATIVE-350，owner upstream，assigned_seq=109，自 #13 ACK 起 24 小时。zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。

恢复 `[0x15ed8,0x15f29)`，片段 SHA-256 `a770ffd4b25132856e7686d08700a557db24cefb90fa4304ff455f11e1b8c714`。核对相邻未覆盖例程的寄存器、调用与展开。

运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL --submission CANDIDATE` 和局部回编。[上轮裁定](../outbox/NATIVE-350/s105-decision.md)
