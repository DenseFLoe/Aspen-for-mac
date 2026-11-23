# zedstwu.dll 第五十七号续领

NATIVE-350，owner upstream，assigned_seq=57，自 #13 ACK 起 24 小时。Aspen Plus V15.0 Engine/Xeq/zedstwu.dll，原件版本 41.0.0.609，SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。

恢复 RVA `[0x18550,0x185a6)`，86 字节，范围 SHA-256 `48838f1e44a19a9df9b6312e94bc9c7a4fc6acaaac53037e3a59289946d53351`，unwind RVA 0x1c3bc。核对 0x15054 的格式串及两个可变实参，0x18558 至 0x18578 的参数存放，0x1858a 至 0x18620 的格式化调用及返回，以及 0x18599 的 cookie 检查。记录当前原件可核实的调用边和剩余缺口。

逐字节检查回编、异常记录与引用。运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL --submission CANDIDATE` 及新增局部回编，按[上游原生覆盖 v1](../standards/native-coverage-upstream.v1.md)交付。沿用 [s53 裁定](../outbox/NATIVE-350/s53-decision.md)。
