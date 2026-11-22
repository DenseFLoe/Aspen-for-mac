# zedstwu.dll 第五十三号续领

NATIVE-350，owner upstream，assigned_seq=53，自 #13 ACK 起 24 小时。Aspen Plus V15.0 Engine/Xeq/zedstwu.dll，原件版本 41.0.0.609，SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。

恢复 RVA `[0x15000,0x15176)`，374 字节，SHA-256 `e3a5b4ddb8c8dd30d9e7899520b6e29e574c73d09882bf8de1d72dfb7737ca58`，unwind RVA 0x1c3d0。核对 0x1501d 的零索引路径、0x15025 的一次性初始化、0x1507a 起索引和记录布局、0x150d0 的资源消息调用及回退，还有 0x150e7 起的 CR/LF 裁剪。在 0x15169 跟踪 RAX 的指针来源与 0x15180 的消费方式。

逐字节检查新增实现和异常记录，核对必要数据与导入链。运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL --submission CANDIDATE` 及新增局部回编，按[原生覆盖 v1](../standards/native-coverage-upstream.v1.md)交付。沿用 [s49 裁定](../outbox/NATIVE-350/s49-decision.md)。
