# ApwnIPShell.dll 第九轮静态补证

本件为 Aspen Plus 与 Aspen Properties 共用的 `[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/ApwnIPShell.dll`，版本 41.0.0.614，369,192 字节。原件固定提交 64670801de54e990f975aaeda06e89340c0e4e08，路径 `issue-materials/342/ApwnIPShell.dll`，SHA-256 为 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。第五轮材料仍可按 [s5 固定候选](https://github.com/DenseFLoe/Aspen-for-mac/tree/20488adec7e3bfbe702ce1e6a275a1039547962e/handoff/inbox/NATIVE-342) 的指纹和目录回读。

本轮逐条解码两个宿主中的 94 条指令，以 Zig 0.13.0 面向 Windows AMD64 重新汇编。34 项 COFF REL32 回填后，0x11f0–0x12a0 的 176 字节和 0x1570–0x1671 的 257 字节全部一致。0x15ab 由 0x15a4 顺序进入，0x15f6 由 0x15a2 的空模块分支进入。两处 unwind 都链到 0x1570，成功路径在 0x15f4 跳至共享末段 0x1634。保留共同栈帧，覆盖记录分别指向实件清单和同一宿主源码。[可编辑实现](s9/verified.c) · [逐段回编结果](s9/reassembly.json)

0x15e2、0x15e6、0x15ea 分别使用对 MMVersion 的 MVGetPointI、MVGetMajorI、MVGetProductCode 查询返回指针，按三个外部符号入表。确认具体安装环境选中的模块版本、指纹与导出或转发链，才能固定实现。0x126e 的磁盘初值链落到已有回编证据的 0x12e0；上下界指针所在节可写，仍需查写入者和运行期描述符。0x129b 的 0x354a4、0x160f 的 0x1ce0 和 0x165b 的 0x35630 均已有 s5 回编。0x1288 传入退出回调地址 0x397c0，该回调的实现仍待恢复。

当前 1,005 个入口中 703 个有覆盖、302 个为缺口，7,433 条引用中仍有 636 处未决。其余五个宿主间接调用的接收者和数据类型、相关资源及导出依赖仍需核实。整件静态验收未通过。[覆盖运行记录](s9/coverage-check.txt)

从仓库根目录运行 `python -B handoff/inbox/NATIVE-342/s9/check.py ORIGINAL ZIG`，输出应匹配 `s9/reassembly.json`。再运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE`，预期退出 2。发布指纹见 [s9/manifest.sha256](s9/manifest.sha256)。

## s13 补充归档

恢复 0x397c0–0x3980e 的 20 条指令，5 个 AMD64 REL32 回填后 78 字节一致。原件 unwind 位于 0x44660。0x1288 传入回调地址，0x129b 尾转移至 atexit。0x397ea 以 ECX=0 调用 [RAX+0x38]。两处可写边界的磁盘初值范围只有一个 8 字节条目，初值链指向 0x12e0。每次非空调用后重新读取上界，运行期目标仍待证明。0x39809 恢复栈帧后带 0x540e0 地址尾转移至 0x33ac0，已登记独立直跳证据。

1,005 个入口仍有 301 个缺口，7,433 条调用及引用中有 636 项未决。下一件核对 0x33ac0 宿主和相邻的 unwind 片段。

[本轮源码](s13/exit-callback.c) · [回编结果](s13/reassembly.json) · [回执](s13-submission.md)
