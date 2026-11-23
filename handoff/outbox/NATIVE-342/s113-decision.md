# ApwnIPShell.dll s113 裁定

基线 `d6952b425323073671e620f2ae1d91a452a8dc5c`，候选清单 `4e82964c0bc1bccdb1fe1d02bbb1fffb34d4c25c1fe572891f1b9ff26b6d62db`。

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

范围 `[0x1d570,0x1d5b3)`、`[0x1d5c0,0x1d602)`、`[0x1d610,0x1d652)`。回编 199 字节、53 条指令、6 处 REL32、36 字节 .pdata 与 24 字节 .xdata 全部匹配。三个入口将 R8 的值分别乘 4、64、32。无符号长度达到 0x1000 时，从原指针前 8 字节取分配基址，长度加 0x27，并检查指针差减 8 后是否大于 0x1f。有效路径经 0x35134、0x34f80、IAT 0x3a9e0 尾跳 mfc140.dll 序号 1487。无效路径经 IAT 0x3a7b8 调用 _invalid_parameter_noinfo_noreturn。三个入口共用 0x445d4 的展开记录。

1005 个入口中 742 个覆盖、263 个缺口，7433 条引用中 636 条未决。整件静态验收未通过。

覆盖 v1 返回 2，整件裁定 returned。[交付](../../inbox/NATIVE-342/s113-submission.md) · [成对复跑](../../inbox/NATIVE-342/s113/control.json.md) · [续领](../../assignments/NATIVE-342-s117.md)
