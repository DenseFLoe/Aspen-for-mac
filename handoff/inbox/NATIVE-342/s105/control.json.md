# s105 单改复验

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

只把 0x36b00 的 RIP 目标从 0x3ac20 改到本 PE 相邻的 0x3ac28。对照 [control.json](control.json) 重算源码和输入清单指纹。分别对基线与变体运行下列命令。

    python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE
    python -B CANDIDATE/s105/replay.py ORIGINAL ZIG

两组覆盖检查均返回 2，输出 `checked 1005 coverage rows, 1005 tool-native entries, 7433 call records, 269 declared gaps`。独立回编依次返回 0、1，变体首差为 `Replay comparison failed: .text first difference at 0x36b02: 0x22 instead of 0x1a`。

建议在覆盖判定入口接入局部回编及相对引用核对。基线须保留原有申报缺口，变体须报地址并判为交付证据错误。
