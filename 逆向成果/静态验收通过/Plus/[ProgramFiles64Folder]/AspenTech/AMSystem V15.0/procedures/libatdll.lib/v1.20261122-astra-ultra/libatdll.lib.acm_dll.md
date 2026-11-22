# libatdll.lib.acm_dll.s

恢复 ACM 动态库包装、装卸、取地址及后备回调。第 18 节为 FindSymbol 清理函数，第 23、25 节从栈上读取两个不同位置的 iflag 指针，第 41、43 节分别引用相应回调。

原库成员为 `.\Release\acm_dll.obj`，大小 108,418 字节，SHA-256 为 `47aba5b29d0fef410ccce3e2eccd76d464735c9910d2f7200108821e15eb2b6d`。逐字节回编匹配，包括 144 个节、29 个函数符号和 594 条重定位。

原件为 Aspen Plus 的 `Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/procedures/libatdll.lib`，组件版本 AMSystem V15.0。原件 SHA-256 为 `aa423ce85b3c9a4bb16ae0c42ea8b939d4fe8f4c78ab98c9086ae4db9fea518f`。本文件 SHA-256 为 `77cf8de8293215cfc8b666cc5fc59bfc67386317e7afb3ede13c3181646a1f4f`。

本件通过静态验收。Windows 调用行为待重建阶段对照。[整件说明](libatdll.lib.md) · [逐件比对](libatdll.lib.audit.json)
