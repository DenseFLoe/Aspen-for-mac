# zedstwu.dll s37 交付

NATIVE-350，owner upstream，assigned_seq=37。原件版本 41.0.0.609，SHA-256 09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b，基线 main b04042ca387010579df70bbfccbf882460435824。

恢复 0x148d0–0x14902 的 50 字节，16 条指令和 3 处文本 REL32 逐字节吻合。由源码生成的 .pdata 经 3 处 ADDR32NB 重定位匹配，0x1c388 的 8 字节 unwind 信息也匹配。0x148df 的无符号判定允许键 1、2、3，其余直接返回 0。读取 0x235fc 的 32 位就绪字段，值为 0 时调用 0x14910。0x148f9 以 16 字节步长读取 0x23600、0x23610、0x23620 的 32 位首字段。就绪字段与三处首字段位于 .data 的零填充尾部。原件 0x14c80 将就绪字段置 1，初始化器其余实现仍待恢复。

255 个入口中覆盖 150 个，105 个仍有缺口，3,567 条引用中 26 条待解。整件未通过静态验收。

从仓库根运行 `python -B handoff/inbox/NATIVE-350/s37/check-query.py ORIGINAL ZIG --evidence-dir OUTPUT`。本轮使用 Zig 0.13.0、Capstone 5.0.6、pefile 2024.8.26、iced-x86 1.21.0。[覆盖检查记录](s37/coverage-check.txt)。[成果清单](s37/manifest.sha256) SHA-256 为 96cef36095072491926f2d20bea161e7af1ffa69c43d9fe4443404190d9a468d。
