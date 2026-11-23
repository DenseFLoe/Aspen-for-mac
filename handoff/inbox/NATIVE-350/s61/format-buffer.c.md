# format-buffer.c

可编辑 Windows AMD64 实现和展开指令。0x1863f 调用 0x158d8，取加载器零填充的选项槽 0x22ca0。0x18647 对读出的选项置位 0，经 0x180de 和 IAT 0x19188 调用 __stdio_common_vsprintf。寄存器传选项、缓冲、容量和格式，栈传 locale 与 va_list。0x1866a 将负值统一为 -1。

zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 范围 `[0x18620,0x18679)`，片段 SHA-256 `aa193870871de50eecab3943d321eb78b712e74c8633011bf2028630305274f2`。

255 个入口中 156 个有覆盖、99 个缺口，3,567 条引用中 26 条未决。整件静态验收未通过。 [交付回执](../s61-submission.md)
