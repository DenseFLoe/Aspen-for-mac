# zedstwu.dll 的 CPUID 初始化器

原件版本 41.0.0.609，SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。源码对应 RVA `[0x14910,0x14cab)`，范围 SHA-256 `0e4c94c415e043053d0da33538058bc9cf4b5bb51638726ffc32969dfa7d9e38`。分支保留原指令宽度，引入符号标记内部跳转和外部引用。

- `0x14939–0x14962` 测试 EFLAGS 的 ID 位。原件相等边 `0x14951→0x1495b` 跨过 `0x1495a push rcx`。源码保留这一原始保存栈路径，未运行差异状态试验。
- `0x14987–0x149ba` 用 CPUID leaf 0 的 EBX、EDX、ECX 比较 `GenuineIntel`。匹配时保存最高基本 leaf，输出厂商和 leaf 两个元数据字段。
- `0x149c0–0x14aad` 在 leaf 至少为 4 时至多读取八组 CPUID leaf 4 结果。筛选类型 1 或 3，以 EAX 中的级别定位 16 字节记录。由 EBX 的三个字段和 ECX 计算容量，并写入记录的容量、行大小、分区数和路数。
- `0x14ab0–0x14c66` 在第一个缓存容量仍为零且 leaf 至少为 2 时读取 CPUID leaf 2。对有效寄存器里的字节使用 `0x1a170` 的八字节描述符表，标记 `0xff` 跳至整块清零。描述符 `0x49` 单独按 CPUID leaf 1 的型号字段选择记录。
- `0x14c6b–0x14c79` 清空三个 16 字节记录。`0x14c80` 写 `[0x235fc] = 1` 后，`0x14c91` 直调 `0x18110` 检查栈 cookie。`0x148ea` 与 `0x14cd3` 直调初始化器。

本范围的代码、原生展开记录和相关静态数据已经独立回编。调用者内尚未恢复的代码按 [交付回执](../s41-submission.md) 追踪。重放见 [检查命令](check-initializer.py.md) 和 [核验结果](reassembly.json)。
