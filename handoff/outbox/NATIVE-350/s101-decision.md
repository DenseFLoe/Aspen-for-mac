# zedstwu.dll s101 裁定

基线 `1545d5c6a8082855c5d577c1017ea7d717e47fa8`，候选清单 `2c96ea06e1f5ca9671bf8ee938cc847c47e55381cff5064eab21113bb3af4660`。

zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 范围 `[0x15d48,0x15e90)`，片段 SHA-256 `6cf4d365502a8f011c563b22a8b2188a9e00ca7861d0305c8ea100750a554939`。

回编 328 字节、71 条解码指令、11 处 REL32、12 字节 .pdata、16 字节 .xdata 均匹配。以 0x17 查询 IsProcessorFeaturePresent，非零路径以原入参触发 int 0x29；其余路径捕获 CONTEXT，按查得的函数表项选择是否展开，并构造状态 0x40000015、标志 1 的异常记录。清除异常筛选器后，仅当 UnhandledExceptionFilter 返回 0 且 IsDebuggerPresent 的返回值不等于 1 时再调用 0x15d40。0x1807e 经 IAT 0x190d0 绑定 memset；0x5c0 栈帧以及 RBX、RBP 恢复与展开记录吻合。

255 个入口中 167 个覆盖、88 个缺口，3572 条引用中 26 条未决。整件静态验收未通过。 覆盖 v1 返回 2，裁定 returned。

[回执](../../inbox/NATIVE-350/s101-submission.md) · [回编](../../inbox/NATIVE-350/s101/reassembly.json) · [成对复跑](../../inbox/NATIVE-350/s101/operand-control.json) · [续领](../../assignments/NATIVE-350-s105.md)
