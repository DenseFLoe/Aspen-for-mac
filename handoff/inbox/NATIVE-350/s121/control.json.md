# s121 单改复验

zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。

将主干候选完整复制一份。只将 `lea rdi, [rip + rva_1bf88]` 改成 `lea rdi, [rip + rva_1bf90]`。开始地址不变，区间不再为空。对照 control.json 重算相应源码的输入指纹，分别运行下列两条命令。

    python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL --submission CANDIDATE
    python -B CANDIDATE/s121/replay.py ORIGINAL ZIG

覆盖检查两组均返回 2，输出 `checked 255 coverage rows, 255 tool-native entries, 3572 call records, 83 declared gaps`。独立回编基线返回 0，单改返回 1。首次差异 `Replay comparison failed: .text first difference at 0x15fec: 0xa0 instead of 0x98`。

增加可选的局部 COFF 回编核对，解析对应重定位后比较函数体、异常目录项与展开数据。原组保留已声明缺口的退出 2，变体定位到首差地址并返回 1。现行覆盖结论仍需结合局部复验。
