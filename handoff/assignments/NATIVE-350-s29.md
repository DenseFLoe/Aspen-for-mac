# zedstwu.dll 第二十九号续领

NATIVE-350，owner upstream，assigned_seq=29，#13 ACK 起 24 小时。固定原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`，沿用 [s25 裁定](../outbox/NATIVE-350/s25-decision.md)。

以异常目录确定的 AVX 填充范围 `[0x11f40,0x12ff8)` 为单件本轮恢复目标，范围 SHA-256 `49645f46662948f2a0070f7264f5409d006755c2340866023174e70a88ce98fc`。核对 `0x9d9fee` 对应分派、三个表基址 `0x12be0/0x122e0/0x123e0`、四个跳转 `0x11f78/0x11fa4/0x12115/0x1216a` 与 `0x11fc0` 的共享读取。恢复可编辑实现并逐字节比对，更新本轮相关覆盖和引用。按[上游原生覆盖 v1](../standards/native-coverage-upstream.v1.md)运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL` 及本轮回编命令。
