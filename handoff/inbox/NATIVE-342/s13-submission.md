# ApwnIPShell.dll s13 交付

NATIVE-342，owner upstream，assigned_seq=13。原件版本 41.0.0.614，SHA-256 为 ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b，基线 main 96b1f2452703fe53cdcfff16d26ed4bc11c20d68。

恢复 0x397c0–0x3980e 的 20 条指令，5 个 AMD64 REL32 回填后 78 字节一致。原件 unwind 位于 0x44660。0x1288 传入回调地址，0x129b 尾转移至 atexit。0x397ea 以 ECX=0 调用 [RAX+0x38]。两处可写边界的磁盘初值范围只有一个 8 字节条目，初值链指向 0x12e0。每次非空调用后重新读取上界，运行期目标仍待证明。0x39809 恢复栈帧后带 0x540e0 地址尾转移至 0x33ac0，已登记独立直跳证据。

1,005 个入口仍有 301 个缺口，7,433 条调用及引用中有 636 项未决。下一件核对 0x33ac0 宿主和相邻的 unwind 片段。

从仓库根运行 `python -B handoff/inbox/NATIVE-342/s13/check-callback.py ORIGINAL ZIG --evidence-dir OUTPUT`。复用 Zig 0.13.0、Capstone 5.0.6、pefile 2024.8.26，以及 zedstwu.dll 所用 iced-x86 1.21.0。复跑 JSON 与原件清单应吻合。结构覆盖命令见[覆盖检查记录](s13/coverage-check.txt)。[成果清单](s13/manifest.sha256) SHA-256 为 26599de48b6867a5c5107dd6537b555051c7c28d50e6a4da0733f968381120a2。
