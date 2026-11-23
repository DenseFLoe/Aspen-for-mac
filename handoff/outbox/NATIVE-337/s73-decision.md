# NATIVE-337 s73 静态复验

`returned`（seq 76）。候选 [#445 @ d4076c4](https://github.com/DenseFLoe/Aspen-for-mac/tree/d4076c4823da715184d4f3210b0feb6d33c0031d)，原件 SHA-256 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`。按覆盖证据 v1 和静态验收 v2 核对完整性。

重建的 161 站与交付表字节相同，五项回归与三布局复验通过。四处虚表槽和成员可静态定位。附表中的 4 条初始化链都把 0x2388 误写为 CoCreateInstance。该处指向 KERNEL32.dll!MultiByteToWideChar，原件在 0x23C8 调 ole32.dll!CoCreateInstance。覆盖 v1 退出 2，112 条转移仍未决，维持整件退回。详见[复验与命令](s73-verifier-notes.md)和[下一件任务卡](../../assignments/NATIVE-337-s77.md)。
