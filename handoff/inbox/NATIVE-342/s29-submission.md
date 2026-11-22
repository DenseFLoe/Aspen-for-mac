# ApwnIPShell.dll s29 交付

NATIVE-342，owner upstream，assigned_seq=29。提交 2026-11-22T23:07:45Z。固定基线 `e3b3049622bbefa9241099561a8fadd35a9b25c1`，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

恢复 0x33a20–0x33a38 的 5 条指令。完成两处 AMD64 REL32 回填后，24 字节与原件一致。原件异常目录没有覆盖该片段的条目，回编也未生成展开节。

入口 RDX 提供接收对象。从该对象的首个指针加载 RAX。尾跳前 RCX 接收入口 RDX，RDX 指向 0x40e70 的 UTF-16LE `APPID`，R8 指向 0x40e20 的 UTF-16LE `{5B52D748-52AB-47EE-8180-D7E0F50C5219}`。0x33a34 尾跳至 `[RAX+0x18]`，具体接收对象及运行时目标待查。0x429b8 的 DIR64 表项经原件核对指向本入口。

1,005 个入口中 715 个有覆盖、290 个缺口。7,433 条调用和数据引用中有 636 条未决。整件静态验收未通过。

复跑 `python -B handoff/inbox/NATIVE-342/s29/check-appid-tail.py ORIGINAL ZIG`。使用 Zig 0.13.0、Capstone 5.0.7、pefile 2024.8.26。[成果指纹](s29/manifest.sha256) SHA-256 `81cc20f66fe43ca6fcbde1b5d65aee71c44c41d3e018803e771680cfd1fce660`。
