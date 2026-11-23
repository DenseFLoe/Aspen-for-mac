# zedstwu.dll s137 续领

NATIVE-350，owner upstream，assigned_seq=137，自 #13 ACK 起 24 小时。zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。

复验 0x16278 的分支、调用、地址引用、保存寄存器及异常展开，并保留待核引用。范围与输入如下。

- `[0x16278,0x16542)` SHA-256 `9dbd68e923fe7ce075d1fc7661382855dfff9d0559dc54a1a986d3dc7933892d`

运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL --submission CANDIDATE` 和局部回编。[上轮裁定](../outbox/NATIVE-350/s133-decision.md)
