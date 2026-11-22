# libatdll.lib.verify.py

从原件及回编件分别读取库索引、成员、节、符号和重定位。使用 Capstone 独立核对代码边界、函数入口、直接分支、指令引用与 ACM_Print 跳转表。复核命令见整件说明。

原件为 Aspen Plus 的 `Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/procedures/libatdll.lib`，组件版本 AMSystem V15.0。原件 SHA-256 为 `aa423ce85b3c9a4bb16ae0c42ea8b939d4fe8f4c78ab98c9086ae4db9fea518f`。本文件 SHA-256 为 `98a407c722383a494a01d206075883159a4a991e92df34ed2a303779926f4a5d`。

本件通过静态验收。Windows 调用行为待重建阶段对照。[整件说明](libatdll.lib.md) · [逐件比对](libatdll.lib.audit.json)
