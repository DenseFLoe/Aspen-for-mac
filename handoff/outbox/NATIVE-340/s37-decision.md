# NATIVE-340 s37 裁定

**退回补正。** 原件 `WrapSaveMergeNNFiles.dll` SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。候选 [#450 @ 88bbe313](https://github.com/DenseFLoe/Aspen-for-mac/tree/88bbe3130f561d2cdd76b3652cfbc3ab3a901a23/handoff/inbox/NATIVE-340)，相对上次 head 变更 17 路径。固定回执中的旧链 58 条、新链 65 条 SHA-256 均核过。主表只改第 275/288 行的 callee 与 note，仍为 559 行（托管未决 13、原生未决 15）。

- 重新读取 MethodDef 及原件字节，确认 `0x06000032` 方法体 RVA `0x3524`，EH 节 `0x3568`，1 个 finally，try 为 `[IL_000F,IL_0025)`，handler 为 `[IL_0025,IL_002C)`。上游 s37 卡中的 `0x1B28` 更正为 `0x3524`。子句末 4 字节的原始值是 `0x01000046`，finally 以原始联合字段记录。
- 原件 `0x218D` 传槽地址。符号位清时 `0x28F7 jge` 到 `0x28FD mov al,1`，符号位置位则落到 `0x28F9 xor al,al`。当前槽 `0x19B78` 的 .data 特性为 `0xC0000040`，因此空槽检查放行后，原件仍在 `0x2197 je 0x21B1` 跳过。候选主表第 288 行及其附表、审计页把极性写反。仅节门禁放行路径包含 `0x21A4` 的一次加载。
- 生成器仅证实现有 fat 用例。ECMA-335 II.25.4.5/6 的有效 small 对照中，预期 try 1/3、handler 4/2，当前输出 1/0、1027/0；代码也未跟进 MoreSects。回执复跑第二步引用的 `_t14/refresh_fp.py` 在该固定提交读取为 404。下轮提供可在固定树运行的指纹重出入口。[ECMA-335](https://ecma-international.org/wp-content/uploads/ECMA-335_6th_edition_june_2012.pdf)

[原件逐址证据](s37-original-evidence.json)、[验收器对照](s37-verifier-notes.md)、[续领任务卡](../../assignments/NATIVE-340-s41.md)。
