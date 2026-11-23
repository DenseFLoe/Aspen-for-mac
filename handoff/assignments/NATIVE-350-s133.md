# zedstwu.dll s133 续领

NATIVE-350，owner upstream，assigned_seq=133，自 #13 ACK 起 24 小时。zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。

恢复相邻三个非叶入口，检查回调槽、原件参数和 Guard CF 引用及异常展开。范围与输入如下。

- `[0x160e8,0x16103)` SHA-256 `d23477ddf95c2c4dd278da00609177ac0da5bb1a9d9796d8b3ae0491ea76089d`
- `[0x161a4,0x161f0)` SHA-256 `a0f188f4d177450b49578b9dbec9ef67c3b5605868eb554c44583c77c5a69e9d`
- `[0x161f0,0x16240)` SHA-256 `7b0118b0a7ef800619bea4aa59fe285bc8937133b1f3472b327b98b01d00bf64`

运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL --submission CANDIDATE` 和局部回编。[上轮裁定](../outbox/NATIVE-350/s129-decision.md)
