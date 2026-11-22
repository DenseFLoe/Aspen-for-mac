# verified.c 静态证据说明

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 为 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。成果 SHA-256 为 `3b99f80b1b03557d98a80121541663105b9a494470ab91fec112d7b46fa21711`。

两处 Windows AMD64 ABI 入口的具名指令实现。0x15ab 与 0x15f6 仅为 0x1570 的局部标签，共用栈帧。用 Zig 0.13.0 重新汇编，34 个 COFF REL32 回填后 433 字节逐字节一致；未恢复的运行期回调与数据类型见逐件说明。
