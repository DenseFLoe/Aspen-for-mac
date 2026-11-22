# ApwnIPShell.dll 第五号事件开工

owner upstream，assigned_seq=5。2026-11-22T09:37Z 已用固定提交 `64670801de54e990f975aaeda06e89340c0e4e08` 的 `issue-materials/342/ApwnIPShell.dll` 建立独立的 Ghidra 12.2 AMD64 静态分析项目。实件 369,192 字节，SHA-256 为 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5d5d4f09422e051502b`。[本轮任务卡](../../assignments/NATIVE-342-s5.md)

首批范围为 0xdad0、0x12bc0、0x1fe50、0x21b90、0x22ad0。逐个复查 0xdd54、0x13367、0x1fedd、0x21c5a、0x21ca4、0x21d30、0x22bac 处分派指令、其 DWORD 地址表、四张字节选择表及实际分支。输入恢复表的 SHA-256 为 `d09896f9e748b357a6ec14f378de7f3667b3dfb839322f6d75cc6ecf066e1b2c`。[地址表与默认分支](../../outbox/NATIVE-342/s5-recovery.json)

保留首轮 12 个短函数与 SetHelpFile 导入槽核对。全件反编译按实际 Ghidra 函数边界输出，后续须将每个旧缺口与可编辑代码、区间归属、具体控制流或恢复条件关联，再交付本轮覆盖表。
