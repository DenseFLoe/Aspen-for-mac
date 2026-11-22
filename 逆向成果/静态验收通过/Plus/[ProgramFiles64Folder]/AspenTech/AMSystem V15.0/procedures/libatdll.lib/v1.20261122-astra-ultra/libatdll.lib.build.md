# libatdll.lib.build.py

用 Python 标准库和 Windows x64 GNU as 汇编五份源码，从汇编结果重建 MS COFF 节、符号和重定位。根据生成的节重新计算 .chks64，再按外部定义构造库的两个符号索引和完整归档。

原件为 Aspen Plus 的 `Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/procedures/libatdll.lib`，组件版本 AMSystem V15.0。原件 SHA-256 为 `aa423ce85b3c9a4bb16ae0c42ea8b939d4fe8f4c78ab98c9086ae4db9fea518f`。本文件 SHA-256 为 `481053a5a05e0a1e7be6770df8969728a8784a1f600361759869a52aebce6952`。

本件通过静态验收。Windows 调用行为待重建阶段对照。[整件说明](libatdll.lib.md) · [逐件比对](libatdll.lib.audit.json)
