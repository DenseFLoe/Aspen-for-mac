# libatdll.lib.audit.json

逐项记录成员指纹、节表、函数入口、指令引用和跳转目标。sections 数组的每行依次为节号、节名、长度、标志、重定位数、原始数据 SHA-256。BSS 的原始数据指纹为空值。executable 中的 offset 为节内字节偏移，entries 三元组为 COFF 符号索引、全名及偏移。

原件为 Aspen Plus 的 `Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/procedures/libatdll.lib`，组件版本 AMSystem V15.0。原件 SHA-256 为 `aa423ce85b3c9a4bb16ae0c42ea8b939d4fe8f4c78ab98c9086ae4db9fea518f`。本文件 SHA-256 为 `d914f0c21d9e780dee4611138e830f6d06d9a74a31ef17cc8a18e75d40aa9b8b`。

本件通过静态验收。Windows 调用行为待重建阶段对照。[整件说明](libatdll.lib.md) · [逐件比对](libatdll.lib.audit.json)
