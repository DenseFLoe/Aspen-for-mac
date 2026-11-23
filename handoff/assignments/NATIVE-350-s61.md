# zedstwu.dll 第六十一号续领

NATIVE-350，owner upstream，assigned_seq=61，自 #13 ACK 起 24 小时。Aspen Plus V15.0 Engine/Xeq/zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。

恢复 RVA `[0x18620,0x18679)`，89 字节，SHA-256 `aa193870871de50eecab3943d321eb78b712e74c8633011bf2028630305274f2`，unwind RVA 0x1c3f4。核对 0x1863F 的选项来源、选项低位置一、0x1865E 的 CRT 导入及传参、0x1866A 的负返回归一。

按[上游原生覆盖 v1](../standards/native-coverage-upstream.v1.md)逐字节核对回编、异常记录与引用。运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL --submission CANDIDATE` 及局部回编，沿用 [s57 裁定](../outbox/NATIVE-350/s57-decision.md)。
