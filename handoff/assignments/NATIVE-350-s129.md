# zedstwu.dll s129 续领

NATIVE-350，owner upstream，assigned_seq=129，自 #13 ACK 起 24 小时。zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。

恢复共享 0x194d0 槽的下一入口及带地址范围和 Guard CF 调度的相邻入口，核对两项展开。范围与输入如下。

- `[0x16098,0x160af)` SHA-256 `182c5cc9a742a13668e05ed2bbdfe198701be702c67ce265a6175cc7d4153a40`
- `[0x160b0,0x160e7)` SHA-256 `718a2c8cda1ec5bf3c57562ef1f1f31d1a5fe6eff108bf95f1bbccef0571a792`

运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL --submission CANDIDATE` 和局部回编。[上轮裁定](../outbox/NATIVE-350/s125-decision.md)
