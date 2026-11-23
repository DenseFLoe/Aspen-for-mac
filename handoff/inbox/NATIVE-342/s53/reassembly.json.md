# reassembly.json

40 字节、9 条调用路径指令与 1 条 INT3、3 处 REL32、.pdata 12 字节和 .xdata 8 字节吻合。0x34f51 用 RSP+0x20 上的对象地址、入口 ECX 与 RDX 以及零值 R9D 调用 0x34e40。构造函数在此参数下跳过引用计数增加。0x34f62 以同一对象地址和 0x492b0 ThrowInfo 经 0x362c2 与 IAT 0x3a640 调用 VCRUNTIME140.dll!_CxxThrowException。异常元数据给出 _com_error、32 字节、复制 0x34df0 和析构 0x34e90。

ApwnIPShell.dll 41.0.0.614，来源 `issue-materials/342/ApwnIPShell.dll`，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x34f40,0x34f68)`，片段 SHA-256 `bc67b3c5c586198379f3f21e843c88a1850124f1e5d5b9eeabe133f2e1ae75b0`。

1,005 个入口中 721 个有覆盖、284 个缺口，7,433 条引用中 636 条未决。整件静态验收未通过。 [交付回执](../s53-submission.md)
