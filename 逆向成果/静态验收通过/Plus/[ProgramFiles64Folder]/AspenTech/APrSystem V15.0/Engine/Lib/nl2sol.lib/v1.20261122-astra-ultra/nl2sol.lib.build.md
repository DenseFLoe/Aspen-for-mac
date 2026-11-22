# 库构建脚本

Aspen Plus，APrSystem V15.0。原路径为 `Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Lib/nl2sol.lib`，原件 203,986 字节，SHA-256 为 `7738ce952d97d2f27c6fce67e735f5e710598a8ce1b77746cbe443f611fe4dee`。归档中没有独立库版本字段。

Python 3 标准库驱动 GNU as，分别汇编 68 个成员。脚本读取同目录的汇编源码和 COFF 声明，按汇编所得标签、节数据和真实重定位重建原件的节号、节辅助记录、COMDAT 选择、符号、CRC 和两个归档索引。构建输入只有这三份文本文件。实际验证使用 Python 3.12.14 和面向 Windows x64 的 GNU as 2.39。

成果 `nl2sol.lib.build.py` 的 SHA-256 为 `e13998840be9e4f2ccce033f0954d988a7ff65ec1760c2eb46917e0ecaaa8a75`。本件已通过整库静态验收。独立复查命令、原件来源和后续 Windows 行为对照范围见 [逐件说明](nl2sol.lib.md)。
