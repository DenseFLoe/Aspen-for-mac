# s125 单改复验

zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。

只把 0x16082 的 JA 改为 JAE。两界相等且 RCX 等于边界时，原件仍可进入读取槽的路径。对照 [control.json](control.json) 重算源码和输入清单指纹。分别对基线与变体运行下列命令。

    python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL --submission CANDIDATE
    python -B CANDIDATE/s125/replay.py ORIGINAL ZIG

两组覆盖检查均返回 2，输出 `checked 255 coverage rows, 255 tool-native entries, 3572 call records, 78 declared gaps`。独立回编依次返回 0、1，变体首差为 `Replay comparison failed: .text first difference at 0x16082: 0x73 instead of 0x77`。

建议在覆盖判定入口接入局部回编及相对引用核对。基线须保留原有申报缺口，变体须报地址并判为交付证据错误。
