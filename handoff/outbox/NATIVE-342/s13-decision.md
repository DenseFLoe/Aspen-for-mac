# ApwnIPShell.dll s13 复验

**本轮恢复范围通过，整件退回。下一件是 0x33ac0 的尾转移目标。** 原件 SHA-256 为 ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b。

恢复 0x397c0–0x3980e 的 20 条指令，5 个 AMD64 REL32 回填后 78 字节一致。原件 unwind 位于 0x44660。0x1288 传入回调地址，0x129b 尾转移至 atexit。0x397ea 以 ECX=0 调用 [RAX+0x38]。两处可写边界的磁盘初值范围只有一个 8 字节条目，初值链指向 0x12e0。每次非空调用后重新读取上界，运行期目标仍待证明。0x39809 恢复栈帧后带 0x540e0 地址尾转移至 0x33ac0，已登记独立直跳证据。

1,005 个入口仍有 301 个缺口，7,433 条调用及引用中有 636 项未决。下一件核对 0x33ac0 宿主和相邻的 unwind 片段。覆盖检查退出 2。[交付与命令](../../inbox/NATIVE-342/s13-submission.md) · [回编对照](../../inbox/NATIVE-342/s13/reassembly.json) · [指纹](../../inbox/NATIVE-342/s13/manifest.sha256) · [覆盖工具复验](s13-verifier-notes.md)。
