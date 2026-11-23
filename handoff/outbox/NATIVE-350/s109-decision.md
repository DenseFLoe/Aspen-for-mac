# zedstwu.dll s109 裁定

基线 `44c22e3daac712802e8a7e865a42c301f70b714b`，候选清单 `402863a2f3c33d928733555168488ca1b7bbd3af1eb73c5ef61fff054484a7de`。

zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 范围 `[0x15ed8,0x15f29)`，片段 SHA-256 `a770ffd4b25132856e7686d08700a557db24cefb90fa4304ff455f11e1b8c714`。

回编 81 字节、23 条解码指令、1 处 REL32、12 字节 .pdata、8 字节 .xdata 均匹配。原件经 IAT 0x19088 调用 GetModuleHandleW(NULL)，取进程主模块。返回空、DOS 或 PE 签名不匹配、可选头非 PE32+，或 NumberOfRvaAndSizes 不大于 14 时返回 false。其他路径以索引 14 的 CLR 目录 RVA 是否非零决定 AL。保持 e_lfanew 的有符号扩展、目录数的无符号比较和 0x28 字节栈帧。[Microsoft PE 格式](https://learn.microsoft.com/en-us/windows/win32/debug/pe-format#optional-header-data-directories-image-only)

255 个入口中 169 个覆盖、86 个缺口，3572 条引用中 26 条未决。整件静态验收未通过。 覆盖 v1 返回 2，裁定 returned。

[回执](../../inbox/NATIVE-350/s109-submission.md) · [回编](../../inbox/NATIVE-350/s109/reassembly.json) · [成对复跑](../../inbox/NATIVE-350/s109/operand-control.json) · [续领](../../assignments/NATIVE-350-s113.md)
