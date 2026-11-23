# record-control.json 的复验说明

固定原件和其余交付，只在隔离副本中改 `s53/message-data.c` 的 `.long 1, 4` 为 `.long 1, 5`，并更新 `s53/manifest.sha256`。两次覆盖检查均为 2，局部回编由 0 变为 1，指出默认表字节差异。依次复跑[覆盖命令](coverage-check.txt)与[局部命令](check-message-source.py.md)。

Aspen Plus V15.0 Engine/Xeq/zedstwu.dll，原件版本 41.0.0.609，SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 RVA `[0x15000,0x15176)`，374 字节，范围 SHA-256 `e3a5b4ddb8c8dd30d9e7899520b6e29e574c73d09882bf8de1d72dfb7737ca58`。 本文件 SHA-256 `b0379f3b36ce38e1cb3537d558f42de83460f420e5e5a6b77552bcdfe5b026af`。

整件已覆盖 154/255 个入口，仍有 101 个入口及 26 条引用待核，静态验收未通过。 [本轮回执](../s53-submission.md)
