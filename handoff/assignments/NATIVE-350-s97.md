# zedstwu.dll s97 续领

NATIVE-350，owner upstream，assigned_seq=97，自 #13 ACK 起 24 小时。zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。

恢复 `[0x15d20,0x15d37)`，片段 SHA-256 `466a3aba93bfca3396f9f06a0f569bb63706ec4dd0de519a65abb600b8700147`。恢复 atexit 包装入口，核对 _onexit 返回指针到 0/-1 的映射、调用与异常展开。

运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL --submission CANDIDATE` 和局部回编。[上轮裁定](../outbox/NATIVE-350/s93-decision.md)
