# Ikc2Bkp.dll 第二十五号提交

NATIVE-349，owner upstream，assigned_seq=25。固定原件 Ikc2Bkp.dll 41.0.0.614，SHA-256 `bba17051eb1071e5f48702f685f1d8d5d3b9f5cfd222f357e30fd0545bf00011`。沿用 [第二十一号交付](s21-submission.md) 已重组的函数，不需要新增实现。

- 原件异常作用域表 `0x2b2e0` 把 `[0x2457d,0x24663)` 交给筛选器 `0x255ca`。它在 `0x255e1` 把 `0x2435c` 装入 R9，经 `0x255f3` 调用 `0x249c0`。后者保存至 RDI，`0x249f5` 转入 RAX。原件 `0x26268` 的 DIR64 指向 `0x25560: jmp rax`。在该调用路径满足门条件时，Guard CF 接收的目标为 `0x2435c`。
- `0x253a8` 读取可写且有文件字节的 `0x321a0`。磁盘初值为 1，`0x249e6` 因此绕过 `0x249f8`。动态进入该指令要求此标志为 0 且入参 EDX 为 1。核查登记范围的 31,382 条指令及 `.text` 整段 E8/E9 位移，只发现上述直接调用，无指向 `0x249c0` 的 DIR64 指针。
- `0x34980` 在 `.data` 零填充区，原初值 0，无重叠基址重定位。逐址发现 `0x25044`、`0x25060`、`0x251a5` 读入 RAX，随后分别在三个零值检查处绕过分派。本轮登记范围没有直接 RIP 相对写入和取址，没有 DIR64 指针直接指向该槽。基址加偏移的别名写入及外部初始化仍待核实。

两次运行 `python -B s25/check-callbacks.py ORIGINAL` 给出同一 [逐址报告](s25/callbacks.json)。用 Zig 0.13.0 重编 `reassemble.py ORIGINAL ZIG`，202 个既有范围共 146,662 字节和 5,419 次 COFF 重定位仍全部匹配。[调用补表](s25/calls.csv)记录四处条件和来源，15 条整件未决保持申报。判定命令为 `python -B handoff/assignments/check-native-coverage.py NATIVE-349 --original ORIGINAL`。[指纹清单](s25-manifest.sha256)
