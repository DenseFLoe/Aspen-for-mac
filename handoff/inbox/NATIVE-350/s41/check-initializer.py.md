# zedstwu.dll 初始化器回编检查

从仓库根运行 `python -B handoff/inbox/NATIVE-350/s41/check-initializer.py ORIGINAL ZIG --evidence-dir OUTPUT`，其中 `ORIGINAL` 是固定原件，`ZIG` 是 Zig 0.13.0 可执行文件。Python 依赖 pefile 2024.8.26、Capstone 5.0.7 和 iced-x86 1.21.0。

检查入口验证原件和范围指纹。两个反汇编器独立确认指令边界。脚本编译两份源码，应用 COFF 重定位并比对原件指令、引用目标、异常目录、字面量和零填充。运行只生成临时 COFF 文件和可选文本证据。原件、适用范围和剩余缺口见 [交付回执](../s41-submission.md)。
