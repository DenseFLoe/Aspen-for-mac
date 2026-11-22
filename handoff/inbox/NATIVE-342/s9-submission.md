# ApwnIPShell.dll 第九号分配交付

NATIVE-342，owner upstream，assigned_seq=9。固定原件 SHA-256 为 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`，基线为主干 `414617eaf303764aaae2904151e2e018a2af364d`。本轮 2 个宿主 94 条指令、433 字节、34 项 COFF REL32 回编相符。0x15ab 与 0x15f6 按原件 unwind 链证实共用 0x1570 栈帧，四个条目均更新覆盖。补录三个具名外部调用；0x126e 的运行期回调位置仍未决。可信覆盖检查输出 1,005 / 1,005 / 7,433 / 302，退出 2；当前 636 处间接转移未决，整件静态验收未通过。

[逐件报告](ApwnIPShell.dll.md) · [回编记录](s9/reassembly.json) · [覆盖复跑](s9/coverage-check.txt) · [材料指纹](s9/manifest.sha256)。清单 SHA-256 为 `057790e8ed1476111175753da16ec01a8e905092006920f97dfb1bfdaceb3341`。
