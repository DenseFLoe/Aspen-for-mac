# zedstwu.dll s125 续领

NATIVE-350，owner upstream，assigned_seq=125，自 #13 ACK 起 24 小时。zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。

批量复验四个叶入口的调用约定及各自边界，并恢复相邻 0x16064 的完整展开、调用及数据引用。范围与输入如下。

- `[0x16014,0x16017)` SHA-256 `b6cbececf1b07e74f37d57710c68c31f0b92cb08d51093252b321b07542e177b`
- `[0x16018,0x1601c)` SHA-256 `92ca7142687bd5513bea360e328ca1c00c3c3a9b71ffdda7bfc2407de7693978`
- `[0x1601c,0x16020)` SHA-256 `92ca7142687bd5513bea360e328ca1c00c3c3a9b71ffdda7bfc2407de7693978`
- `[0x16060,0x16063)` SHA-256 `b6cbececf1b07e74f37d57710c68c31f0b92cb08d51093252b321b07542e177b`
- `[0x16064,0x16097)` SHA-256 `0d34a16bbc081fdd32d9e30f43899e17571fb0c27fec9a7579345d703437e1fc`

运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL --submission CANDIDATE` 和局部回编。[上轮裁定](../outbox/NATIVE-350/s121-decision.md)
