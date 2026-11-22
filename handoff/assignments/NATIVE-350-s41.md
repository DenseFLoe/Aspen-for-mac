# zedstwu.dll 第四十一号续领

NATIVE-350，owner upstream，assigned_seq=41，自 #13 ACK 起 24 小时。固定原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。复用 [s37](../inbox/NATIVE-350/s37-submission.md) 的覆盖及查询证据。

恢复 `[0x14910,0x14cab)` 的 923 字节初始化器，范围 SHA-256 `0e4c94c415e043053d0da33538058bc9cf4b5bb51638726ffc32969dfa7d9e38`，unwind RVA `0x1c390`。核对 CPUID 可用性和厂商分支、16 字节记录的写入、能力就绪字段在 0x14c80 的写入，以及分派边的静态来源。

按[上游原生覆盖 v1](../standards/native-coverage-upstream.v1.md)交付可编辑实现、逐字节回编和原件数据引用，执行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL --submission CANDIDATE` 及候选回编命令。
