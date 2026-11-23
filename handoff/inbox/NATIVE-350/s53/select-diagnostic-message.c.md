# select-diagnostic-message.c 的复验说明

## 入口及回退

- ECX 是输入索引。0x1501d 在 ECX 为零时直接取 0x1a98b 的空串。其他索引先读 0x23a58，首次进入置 1，再取线程区域设置，并在 0x15054 调用 0x18550，用 `%lu/%s` 与 `irc_msg.dll` 构造路径。0x15061 以 HFILE=0、flags=0 调用 LoadLibraryExA。结果保存在 0x23a60，仅当结果非空才将 0x23a5c 置 1。0x18550 的完整实现待核。
- 0x1507a 把 ESI 符号扩展后左移 4，0x15088 用该偏移从 0x1a990 记录的 +8 取默认文本。62 条记录及其 DIR64 和文本逐条核对。0x23a5c 不为 1 时返回默认文本。
- 0x150d0 向 FormatMessageA 传入 flags=0x900、消息 ID=索引加 0x80000000（32 位）、语言 ID=0x409，第 5～7 参数是 `(&slot, 0x200, NULL)`。0x150d8 在返回值为 0 时沿用默认文本。成功时从 slot 读取临时字符串的指针。

## 文本复制与返回

- 0x150e7 起检查长度至少 2 且以 CR/LF 结尾。命中时把长度减 2，以该长度复制到 0x23a70，随后在该长度位置写 0。其余情况向 strncpy 传入 0x200 并在 0x23c6f 写 0。两路均调用 LocalFree，再返回复用缓冲区地址。
- 0x15159 恢复并核对 cookie。0x15169 把选中的 RDI 放入 RAX。调用者 0x151a3 以原始 EDX 提供索引；0x151a8 将 RAX 保留在 RSI，R8D 大于零时以该指针作 CRT 格式字符串，否则以该指针作 `%s\n` 的输出实参。[调用者 s49 对照](../s49/report-diagnostic.c.md)

[原件指令](instructions.lst) · [回编结果](reassembly.json) · [复验步骤](check-message-source.py.md)

Aspen Plus V15.0 Engine/Xeq/zedstwu.dll，原件版本 41.0.0.609，SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 RVA `[0x15000,0x15176)`，374 字节，范围 SHA-256 `e3a5b4ddb8c8dd30d9e7899520b6e29e574c73d09882bf8de1d72dfb7737ca58`。 本文件 SHA-256 `5609c178c989a9cdd15d055c41b325e0569f230dd81f527fad07ba3f7087039c`。

整件已覆盖 154/255 个入口，仍有 101 个入口及 26 条引用待核，静态验收未通过。 [本轮回执](../s53-submission.md)
