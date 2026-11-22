# 编译四个导出所用的寄存器指令形式

此头文件保存原件采用的 AMD64 双寄存器指令编码方向，供四个导出的可编辑 C 汇编实现共同引用。源码沿用 NATIVE-346 第五轮已检查的同一组 LLVM 汇编宏。原件出现另一种等价编码时，助记符和寄存器操作数仍可分别编辑。

使用 Zig 0.13.0、Capstone 5.0.6、pefile 2024.8.26 和 iced-x86 1.21.0。从仓库根运行以下命令。脚本读取上一轮已归档的 COFF 解析器，构建结果只在临时目录使用。第二条命令同时验证消费方、提供方和旧 IDA 汇编全文的 SHA-256，并记录对导入桩的已知静态引用。

```text
python -B handoff/inbox/NATIVE-350/s5/check-business.py <zedstwu.dll> <zig> --output business-evidence.json
python -B handoff/inbox/NATIVE-350/s5/check-import-data.py <zedstwu.dll> <ppexec.dll> <zedstwu旧IDA汇编> --output import-data-evidence.json
```

独立输出与同目录两份 JSON 逐字节核对，接着运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original <zedstwu.dll>` 验证全件覆盖表。四个导出的实现与整件当前状态见[逐件说明](../zedstwu.dll.md)。
