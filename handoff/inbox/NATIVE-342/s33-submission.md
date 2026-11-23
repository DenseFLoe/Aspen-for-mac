# ApwnIPShell.dll s33 交付

NATIVE-342，owner upstream，assigned_seq=33。提交 2026-11-23T00:04:32Z。固定基线 `2d13d4e28bffd770252e8e0c4bb491bdf256a4f6`，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

0x33c33–0x33cac 的 23 条指令完整回编。两处 REL32 回填后与原件 121 字节逐字节一致。另回编 .pdata 12 字节及 .xdata 8 字节，覆盖范围在 0x33caa 结束，随后两字节为独立尾跳。

包装函数保存并恢复 RCX、RDX、R8、R9 及 XMM0–3。0x33c6d 以 RCX=0x49320 描述符地址、RDX=入口 RAX 的延迟导入槽地址调用 0x366e0。描述符绑定 HAPP.dll，31 个初始 IAT 槽的 DIR64、INT 序号及同一包装入口逐项相符。首项是 0x52f80 → 0x33cac → 本包装函数，对应序号 58。0x36965 写回选定的指针，0x36995 将 RBX 搬入 RAX；包装函数恢复参数后在 0x33caa 跳至该返回值。外部函数实现、运行期指针和解析器中的回调路径待核。

1,005 个入口中 716 个有覆盖、289 个缺口。7,433 条调用和数据引用中有 636 条未决。整件静态验收未通过。

复跑 `python -B handoff/inbox/NATIVE-342/s33/check-delay-wrapper.py ORIGINAL ZIG`。使用 Zig 0.13.0、Capstone 5.0.6、pefile 2024.8.26。[成果指纹](s33/manifest.sha256) SHA-256 `d1e6beab98f5fcbfd5636936d7a52a66e6dc8086cb820bd509f3c82fef976b79`。
