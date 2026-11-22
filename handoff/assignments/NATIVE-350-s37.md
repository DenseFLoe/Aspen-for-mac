# zedstwu.dll 第三十七号续领

NATIVE-350，owner upstream，assigned_seq=37，自 #13 ACK 起 24 小时。固定原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。复用 [s33 材料](../inbox/NATIVE-350/s33-submission.md) 的原件和覆盖快照。

恢复 `[0x148d0,0x14902)`，50 字节，范围 SHA-256 `53ab68e5de47e6beb36cf37ba805cf09edc3eaa8a738b5670451109abd5b5dc2`，unwind RVA 为 0x1c388。核对 0x148d7–0x148df 对参数的门禁、0x148e1 的就绪字段、0x148ea 到 0x14910 的调用、0x148f2–0x148f9 的索引和原件数据引用。

按[上游原生覆盖 v1](../standards/native-coverage-upstream.v1.md)交付可编辑实现、逐字节回编以及各引用地址，执行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL --submission CANDIDATE` 和候选回编命令。
