# zedstwu.dll 第三十三号续领

NATIVE-350，owner upstream，assigned_seq=33，#13 ACK 起 24 小时。继续使用原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b` 与[s29 裁定](../outbox/NATIVE-350/s29-decision.md)。

恢复紧邻的叶函数 `[0x13000,0x148c1)`，范围 6,337 字节，SHA-256 `b2867ed240cf8150fc69c936aaf2a674ef890589b727b40df23dcf04afd3d33b`。核对 `0x7189d9fee` 分派值、`0x13035/0x1305b/0x131aa/0x131ef` 与三张表 `0x144c0/0x132c0/0x134c0`，保留共享 `0x148c0` 的返回单指令与 `0x1306d` 对 `0x22250` 的引用。验收可编辑实现、逐字节回编和逐址引用。按[原生覆盖 v1](../standards/native-coverage-upstream.v1.md)运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL` 及本轮新增回编命令。
