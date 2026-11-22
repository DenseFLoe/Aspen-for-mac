# reassemble.py 静态证据说明

对应 ApwnIPShell.dll 41.0.0.614，原件 SHA-256 为 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`，成果 SHA-256 为 `b22716e57837d62df6850ee8edae651d81e9ac0345fa578fb8f3140c9dfdcdbe`。

用 Zig 0.13.0 cc 或目标兼容的 clang 将同目录 code/verified.c 编译为临时的 Windows AMD64 COFF。从符号表还原各函数 RVA，按重定位类型回填 PC 相对目标，再按函数逐字节对照原件。接受原件路径和编译器路径两个参数，输出可与 reassembly.json 比较。
