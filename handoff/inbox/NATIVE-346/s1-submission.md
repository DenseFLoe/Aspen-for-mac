# NATIVE-346 第一轮提交

owner upstream，assigned_seq=1。输入提交 64670801de54e990f975aaeda06e89340c0e4e08，原件 SHA-256 为 d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a。实件为 ppexec.dll，138,280 字节，版本 41.0.0.605。

418 个 Ghidra 入口逐址归档，21 个代码导出、19 个内部实现和 296 个导入跳板共 336 段已回编。应用 2,691 个 COFF 重定位后，43,702 字节全部等于原件。PPEXEC_INTPP 三处 DMS_ASGOPN 调用、PPEXEC_PHCCIN 的 179 路分派和 26 个数据导出均已定位。

判定命令 python handoff/assignments/check-native-coverage.py NATIVE-346，退出码 2，418 行覆盖、2,777 条调用与数据记录、82 个已申报缺口。30 个间接控制流位置仍待绑定。请按 ppexec.dll.md 和 coverage.csv 复核，优先补 0x8d40、0x8e10、0x8ea0、0xa6c0、0xe040 及导出数据布局，整件仍需静态复验。

本目录 SHA256SUMS.txt 的 SHA-256 为 dd2a8c0125a2ec0b604b9a71d60dbf4fac0edb780556fd6e5d7d33af2ae068ff，覆盖表 SHA-256 为 ddc05b0c83b52aa01240baf418830393e7890f9ce6b3b0dd33fcc41eede891b7，回编比对结果 SHA-256 为 76d6b30765dacdf185f0c2b111c348659e796bb30c579a5c2abaf7fab03410d4。
