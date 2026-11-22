# zedstwu.dll 第四十九号续领

NATIVE-350，owner upstream，assigned_seq=49，自 #13 ACK 起 24 小时。Aspen Plus V15 Engine/Xeq/zedstwu.dll，版本 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。上轮 s45 在 0x14f3c、0x14f4e 和 0x14f5d 三次直调本入口。

恢复 `[0x15180,0x15220)`，160 字节，SHA-256 `3a7e60ad7c37883a4c047ccd60a1c35881af319f8d2c4bba9154a5d1fb1a92ef`，unwind RVA 0x1c3dc。核对 0x1519a 和 0x151ab 的分流条件、0x15000 的返回值和参数转发、0x151e6 经 0x180de/IAT 0x19188 的格式化调用、0x1a985 和 0x1a987 两个输出格式地址以及两处通向 0x185b0 的调用。保留静态观察边界，特别是格式缓冲区容量、调用寄存器与栈参数、栈 cookie 的传递和回收。

逐字节核对代码及 .pdata/.xdata，补齐覆盖表、引用表和控制转移；沿用固定覆盖器和新增范围复验脚本。s45 后仍有 103 个入口缺口及 26 条未决引用。

按[上游原生覆盖 v1](../standards/native-coverage-upstream.v1.md)交付。运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL --submission CANDIDATE` 和局部回编命令。复用 [s45 裁定](../outbox/NATIVE-350/s45-decision.md)。
