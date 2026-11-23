# s101 单改复验

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

将主干候选完整复制一份。只将第一条 `.rva .Lexception_target` 改成 `.rva .Lexception_target + 1`。该条决定 SEH 保护的排他上界，续执行目标未变。对照 control.json 重算相应源码的输入指纹，分别运行下列两条命令。

    python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE
    python -B CANDIDATE/s101/replay.py ORIGINAL ZIG

覆盖检查两组均返回 2，输出 `checked 1005 coverage rows, 1005 tool-native entries, 7433 call records, 271 declared gaps`。独立回编基线返回 0，单改返回 1。首次差异 `Replay comparison failed: .xdata first difference at 0x490f8: 0xc2 instead of 0xc1`。

增加可选的局部 COFF 回编核对，解析对应重定位后比较函数体、异常目录项与展开数据。原组保留已声明缺口的退出 2，变体定位到首差地址并返回 1。现行覆盖结论仍需结合局部复验。
