# ApwnIPShell.dll s77 裁定

基线 `2cb8a177a47da004ddd4b305f8fe31107c2d2afc`，候选清单 `025783aac547863ea17540e7f5de33542e051dd859f27c04b56bda7b2ed5be2c`。

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x360d4,0x36110)`，片段 SHA-256 `80de413be0bad692d40a7cfff93d994ee3740475be5a1b5887c0f4e0f2715c42`。

回编 60 字节、17 条解码指令、3 处 REL32、12 字节 .pdata、12 字节 .xdata 均匹配。起止两条 LEA 均指向 0x445a0，原件的无符号严格小于分支在相等时跳过循环。循环每次增加 8，空指针跳过调用，非空指针在 RAX 中经 0x3ac20 分派；磁盘槽有 DIR64，指向 0x36ae0 的 jmp rax。其他间接站点的运行时目标仍待核。

1005 个入口中 728 个覆盖、277 个缺口，7433 条引用中 636 条未决。整件静态验收未通过。 覆盖 v1 返回 2，裁定 returned。

[回执](../../inbox/NATIVE-342/s77-submission.md) · [回编](../../inbox/NATIVE-342/s77/reassembly.json) · [成对复跑](../../inbox/NATIVE-342/s77/operand-control.json) · [续领](../../assignments/NATIVE-342-s81.md)
