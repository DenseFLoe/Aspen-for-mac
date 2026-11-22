# zedstwu.dll 第二十五号续领

NATIVE-350，owner upstream，assigned_seq=25，自 #13 ACK 起 24 小时。原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`，以[第二十一号交付](../inbox/NATIVE-350/s21-submission.md)接续。

从 `0xcbf0` 绑定的复制目标 `[0xe5c0,0x100c2)` 开始，固定范围 SHA-256 `86177c7f8c319b6bfcfd11f4a4499c414db8fd18d7df16401ed7ff2ab844cfea`。从原件核对 `0xe5e4、0xe611、0xe951、0xe9c1` 的间接跳转与表基址 `0xfcc0、0xeac0、0xecc0`。恢复可编辑实现、符号表项和共享阈值 `0x22238` 的引用，独立回编核对代码和重定位。逐地址更新调用、数据引用、覆盖与恢复条件。按[上游覆盖标准](../standards/native-coverage-upstream.v1.md)执行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL` 及本轮原件回编检查。
