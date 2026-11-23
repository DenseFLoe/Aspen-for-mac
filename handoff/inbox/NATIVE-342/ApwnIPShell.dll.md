# ApwnIPShell.dll 第九轮静态补证

本件为 Aspen Plus 与 Aspen Properties 共用的 `[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/ApwnIPShell.dll`，版本 41.0.0.614，369,192 字节。原件固定提交 64670801de54e990f975aaeda06e89340c0e4e08，路径 `issue-materials/342/ApwnIPShell.dll`，SHA-256 为 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。第五轮材料仍可按 [s5 固定候选](https://github.com/DenseFLoe/Aspen-for-mac/tree/20488adec7e3bfbe702ce1e6a275a1039547962e/handoff/inbox/NATIVE-342) 的指纹和目录回读。

本轮逐条解码两个宿主中的 94 条指令，以 Zig 0.13.0 面向 Windows AMD64 重新汇编。34 项 COFF REL32 回填后，0x11f0–0x12a0 的 176 字节和 0x1570–0x1671 的 257 字节全部一致。0x15ab 由 0x15a4 顺序进入，0x15f6 由 0x15a2 的空模块分支进入。两处 unwind 都链到 0x1570，成功路径在 0x15f4 跳至共享末段 0x1634。保留共同栈帧，覆盖记录分别指向实件清单和同一宿主源码。[可编辑实现](s9/verified.c) · [逐段回编结果](s9/reassembly.json)

0x15e2、0x15e6、0x15ea 分别使用对 MMVersion 的 MVGetPointI、MVGetMajorI、MVGetProductCode 查询返回指针，按三个外部符号入表。确认具体安装环境选中的模块版本、指纹与导出或转发链，才能固定实现。0x126e 的磁盘初值链落到已有回编证据的 0x12e0；上下界指针所在节可写，仍需查写入者和运行期描述符。0x129b 的 0x354a4、0x160f 的 0x1ce0 和 0x165b 的 0x35630 均已有 s5 回编。0x1288 传入退出回调地址 0x397c0，该回调的实现仍待恢复。

当前 1,005 个入口中 703 个有覆盖、302 个为缺口，7,433 条引用中仍有 636 处未决。其余五个宿主间接调用的接收者和数据类型、相关资源及导出依赖仍需核实。整件静态验收未通过。[覆盖运行记录](s9/coverage-check.txt)

从仓库根目录运行 `python -B handoff/inbox/NATIVE-342/s9/check.py ORIGINAL ZIG`，输出应匹配 `s9/reassembly.json`。再运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE`，预期退出 2。发布指纹见 [s9/manifest.sha256](s9/manifest.sha256)。

## s13 补充归档

恢复 0x397c0–0x3980e 的 20 条指令，5 个 AMD64 REL32 回填后 78 字节一致。原件 unwind 位于 0x44660。0x1288 传入回调地址，0x129b 尾转移至 atexit。0x397ea 以 ECX=0 调用 [RAX+0x38]。两处可写边界的磁盘初值范围只有一个 8 字节条目，初值链指向 0x12e0。每次非空调用后重新读取上界，运行期目标仍待证明。0x39809 恢复栈帧后带 0x540e0 地址尾转移至 0x33ac0，已登记独立直跳证据。

1,005 个入口仍有 301 个缺口，7,433 条调用及引用中有 636 项未决。下一件核对 0x33ac0 宿主和相邻的 unwind 片段。

[本轮源码](s13/exit-callback.c) · [回编结果](s13/reassembly.json) · [回执](s13-submission.md)

## s17 补充归档

共享退出清理体 0x33ac0–0x33b80 共 53 条指令，三个 AMD64 COFF REL32 回填后 192 字节全部一致。异常目录共八项，0x33ac0 建立栈帧，另外七段按原件的 CHAININFO 复用该帧。0x33b70 是使用已保存 R15、RBP 的错误路径，向 0x33b80 传递 0xc0000005 与 1。0x39809 和 0x33a87 分别以尾跳和直调进入清理体。

0x33b14 从当前链表节点的偏移 0 取回调，RCX 为节点的 +0x08 字段，+0x10 指向下一节点。0x33b4d 从外层对象 +0x40 取接收者，非空时从其表的 +0x10 调用。两处继续保留未决，分别需要实际节点注册来源和接收者赋值与具体表证据。0x33b22 的原件跳板到 mfc140.dll!#1487，0x33b54 以对象 +0x18 为参数调用 DeleteCriticalSection。

原件共 1,005 个入口，712 个有覆盖，293 个为缺口。7,433 条调用和数据引用仍有 636 条未决。整件静态验收未通过。

[可编辑实现](s17/teardown.c) · [逐段异常目录](s17/unwind.csv) · [回编结果](s17/reassembly.json) · [交付回执](s17-submission.md)

## s21 补充归档

恢复 0x33a40–0x33ab2 的 32 条指令。五条 AMD64 REL32 回填后，114 字节与原件一致。三条 ADDR32NB 回填后 `.pdata` 的 12 字节一致，两条 ADDR32NB 回填后 `.xdata` 的 24 字节一致。异常记录中的回调指针从 0x36298 跳到导入槽 0x3a688，对应 VCRUNTIME140_1.dll!__CxxFrameHandler4。原件 C++ 异常处理数据位于 0x48e50，本轮核对其引用和原始前缀。

`0x33a71` 先跳过空条目，再以 RCX=0 调用 `[RAX+0x38]`。上下界槽位 0x527b0、0x527b8 可写，初值区间只有一个指针，候选初值链 `0x527b0→0x49310→0x40a90` 的 +0x38 处指向 0x12e0。每次非空调用后重读上界，运行期绑定仍待核。0x33a87 以原 RCX 调用已恢复的 0x33ac0。0x33a8c 检测原 EDX 位 0，0x33a90 在位清零时跳过释放。位设定时 0x33a9a 以原 RCX、EDX=0x48 调用 `0x35134→0x34f80→IAT 0x3a9e0`，绑定 mfc140.dll!#1487。返回 RAX 为原 RCX。

原件共 1,005 个入口，713 个有覆盖，292 个为缺口。7,433 条调用和数据引用仍有 636 条未决。整件静态验收未通过。

[可编辑实现](s21/release-shell.c) · [回编结果](s21/reassembly.json) · [交付回执](s21-submission.md)

## s25 补充归档

恢复 0x339a0–0x33a14 的 35 条指令。三处 AMD64 REL32 回填后，116 字节与原件一致。三处 ADDR32NB 回填后 .pdata 的 12 字节一致，.xdata 的 16 字节一致。

输出参数为空时返回 0x80004003。缓存槽是原 RCX+0x40。空缓存时在 0x339e7 调用 ole32.dll!CoCreateInstance，CLSID 在 0x42af8，IID 在 0x42978，外部聚合指针为零，CLSCTX=1，第五参数指向缓存槽。负 HRESULT 直接退出。成功路径或缓存命中时在 0x339f6 写入调用方输出槽，0x339ff 从该接口虚表 +8 调用，符合 IUnknown 的 AddRef 槽位。具体运行时目标保持未决。

1,005 个入口中 714 个有覆盖、291 个缺口。7,433 条调用和数据引用中有 636 条未决。整件静态验收未通过。

[可编辑实现](s25/create-interface.c) · [回编结果](s25/reassembly.json) · [交付回执](s25-submission.md)

## s29 补充归档

恢复 0x33a20–0x33a38 的 5 条指令。完成两处 AMD64 REL32 回填后，24 字节与原件一致。原件异常目录没有覆盖该片段的条目，回编也未生成展开节。

入口 RDX 提供接收对象。从该对象的首个指针加载 RAX。尾跳前 RCX 接收入口 RDX，RDX 指向 0x40e70 的 UTF-16LE `APPID`，R8 指向 0x40e20 的 UTF-16LE `{5B52D748-52AB-47EE-8180-D7E0F50C5219}`。0x33a34 尾跳至 `[RAX+0x18]`，具体接收对象及运行时目标待查。0x429b8 的 DIR64 表项经原件核对指向本入口。

1,005 个入口中 715 个有覆盖、290 个缺口。7,433 条调用和数据引用中有 636 条未决。整件静态验收未通过。

[可编辑实现](s29/appid-tail.c) · [回编结果](s29/reassembly.json) · [交付回执](s29-submission.md)

## s33 补充归档

0x33c33–0x33cac 的 23 条指令完整回编。两处 REL32 回填后与原件 121 字节逐字节一致。另回编 .pdata 12 字节及 .xdata 8 字节，覆盖范围在 0x33caa 结束，随后两字节为独立尾跳。

包装函数保存并恢复 RCX、RDX、R8、R9 及 XMM0–3。0x33c6d 以 RCX=0x49320 描述符地址、RDX=入口 RAX 的延迟导入槽地址调用 0x366e0。描述符绑定 HAPP.dll，31 个初始 IAT 槽的 DIR64、INT 序号及同一包装入口逐项相符。首项是 0x52f80 → 0x33cac → 本包装函数，对应序号 58。0x36965 写回选定的指针，0x36995 将 RBX 搬入 RAX；包装函数恢复参数后在 0x33caa 跳至该返回值。外部函数实现、运行期指针和解析器中的回调路径待核。

1,005 个入口中 716 个有覆盖、289 个缺口。7,433 条调用和数据引用中有 636 条未决。整件静态验收未通过。

[可编辑实现](s33/delay-load-wrapper.c) · [回编及绑定证据](s33/reassembly.json) · [交付回执](s33-submission.md)

## s37 补充归档

0x34df0–0x34e34 的 19 条指令、68 字节和两处 REL32 重定位逐字节复验一致。.pdata 12 字节和 .xdata 8 字节回编一致，含 RBX 保存与 0x20 字节栈分配。

0x34df9 将 0x42a90 写入目标对象头，其首项 DIR64 指向 0x34ee0。源对象 +0x08 的 4 字节和 +0x10 的 8 字节复制到目标，目标 +0x18 的 8 字节清零。源 +0x10 为空则在 0x34e1c 跳至返回；否则 0x34e21 从该对象虚表的 +0x08 读取 RAX。0x34e25 通过装载配置 GuardCFDispatchFunctionPointer 指明的 0x3ac20 槽调用。磁盘中槽的 DIR64 指向 0x36ae0 的 jmp rax，虚调用目标仍需接收对象运行证据。

1,005 个入口中 717 个有覆盖、288 个缺口。7,433 条调用和数据引用中有 636 条未决。整件静态验收未通过。

[可编辑实现](s37/com-error-copy.c) · [回编及引用证据](s37/reassembly.json) · [交付回执](s37-submission.md)

## s41 局部回编

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x34e40,0x34e85)`，片段 SHA-256 `dfeaea0ef12e23a31c55b931d22c4df503a8cbdc067c31c4d5f1434aff37af51`。

69 字节、20 条指令、2 处 REL32、.pdata 12 字节和 .xdata 8 字节吻合。 0x34e49 取目标对象表 0x42a90，写入 EDX、R8 并清零 +0x18。0x34e65 检查 R8 非空，0x34e6a 检查 R9B 非零。两者通过才读取 [R8] 的表内 +8，将 R8 作为 RCX 经 0x3ac20 调度槽调用。槽的磁盘初值指向 0x36ae0，实机接收对象与虚函数目标待核。

1,005 个入口中 718 个有覆盖、287 个缺口，7,433 条引用中 636 条未决。整件静态验收未通过。 [回执](s41-submission.md) · [复验](s41/reassembly.json)

## s45 局部回编

ApwnIPShell.dll 41.0.0.614，来源 `issue-materials/342/ApwnIPShell.dll`，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x34e90,0x34ed4)`，片段 SHA-256 `83775a03ae2ae71bffd68eec65a47da50fe4e46b9805833aa6062f1a1c73d913`。

68 字节、20 条指令、3 处 REL32、.pdata 12 字节和 .xdata 8 字节逐字节吻合。 0x34e96 取虚表 0x42a90 并写回对象头。对象 +0x10 非空时取其虚表的 +0x10 槽，经 0x3ac20 调度。对象 +0x18 非空时恢复栈及 RBX，并在 0x34ec7 尾跳至 KERNEL32.dll!LocalFree 的 IAT 槽 0x3a2f0。按这些指令将本函数记为对象清理。

1,005 个入口中 719 个有覆盖、286 个缺口，7,433 条引用中 636 条未决。0x34eb3 的实时接收对象和虚调用目标待核。整件静态验收未通过。 [回执](s45-submission.md) · [复验](s45/reassembly.json)

## s49 局部回编

ApwnIPShell.dll 41.0.0.614，来源 `issue-materials/342/ApwnIPShell.dll`，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x34ee0,0x34f3f)`，片段 SHA-256 `5605be7ff7427d7b14a0069c4176e9090765233cb7fbffbdee14555282bd0bcc`。

95 字节、27 条指令、4 处 REL32、.pdata 12 字节和 .xdata 12 字节逐字节吻合。 例程写入对象首槽 0x42a90。0x34f09 经 0x3ac20 GuardCF 槽调度 [对象+0x10] 的虚表 +0x10，0x34f18 在缓冲指针非零时用 LocalFree 释放 [对象+0x18]。0x34f22 检查 DIL 位 0，位为 1 时用 RCX 传对象、EDX 传 0x20，经 0x35134 和 0x34f80 到 IAT 0x3a9e0 对应的 mfc140.dll!#1487。

1,005 个入口中 720 个有覆盖、285 个缺口，7,433 条引用中 636 条未决。0x34f09 的实机接收者和最终虚调用目标仍待 Windows 对照。整件静态验收未通过。 [回执](s49-submission.md) · [复验](s49/reassembly.json)

## s53 局部回编

ApwnIPShell.dll 41.0.0.614，来源 `issue-materials/342/ApwnIPShell.dll`，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x34f40,0x34f68)`，片段 SHA-256 `bc67b3c5c586198379f3f21e843c88a1850124f1e5d5b9eeabe133f2e1ae75b0`。

40 字节、9 条调用路径指令与 1 条 INT3、3 处 REL32、.pdata 12 字节和 .xdata 8 字节吻合。 0x34f51 用 RSP+0x20 上的对象地址、入口 ECX 与 RDX 以及零值 R9D 调用 0x34e40。构造函数在此参数下跳过引用计数增加。0x34f62 以同一对象地址和 0x492b0 ThrowInfo 经 0x362c2 与 IAT 0x3a640 调用 VCRUNTIME140.dll!_CxxThrowException。异常元数据给出 _com_error、32 字节、复制 0x34df0 和析构 0x34e90。

1,005 个入口中 721 个有覆盖、284 个缺口，7,433 条引用中 636 条未决。整件静态验收未通过。 [回执](s53-submission.md) · [复验](s53/reassembly.json)

## s57 局部回编

ApwnIPShell.dll 41.0.0.614，来源 `issue-materials/342/ApwnIPShell.dll`，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x35204,0x35264)`，片段 SHA-256 `aac1533de9bf8cdb8662108ffcce0dd34d55507db2a5364cfc5e02b6d53f7762`。

96 字节、27 条指令、3 处 REL32、.pdata 12 字节和 .xdata 20 字节吻合。 0x35223 调用 0x35e80 读取 CRT 标志。标志为零且原始 EDX 为 1 才执行 0x3523c 的 GuardCF 回调。R9 经 RDI 传到 RAX，回调实参为入口 RCX、零值 EDX 和入口 R8。固定原件的调用点 0x39623 由 0x39611 的 LEA 将 R9 绑定至 0x35974。其他入口与装载后的调度状态待核。0x3525f 经 0x362fe 与 IAT 0x3a778 将第 5、6 个入参传给 _seh_filter_dll。

1,005 个入口中 722 个有覆盖、283 个缺口，7,433 条引用中 636 条未决。整件静态验收未通过。 [回执](s57-submission.md) · [复验](s57/reassembly.json)

## s61 局部回编

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x352f4,0x35418)`，片段 SHA-256 `4a6776f7c5a98e67967fae31a7dc3b68f427afebe72913f0f191aa4022a7f443`。

两段共 291 字节和 84 条解码指令，另有 0x3537f 的对齐 INT3。两段的 16 处 REL32、24 字节 .pdata 和 40 字节 .xdata 均逐字节吻合。 0x352f4 按 0x541e1 的初始化标志短路；未初始化时模式大于 1 走失败辅助例程。当 UCRT 在用且模式为 0 时，经 0x36310→0x3a770 分别初始化 0x541e8、0x54200 的退出表。另一分支按原件将各表的三个 64 位字段填为 -1。0x35380 验证 DOS、NT 和 PE32+ 头，按 VirtualAddress 与 VirtualSize 查找节，由 Characteristics 的最高位判断可写性。0x48f28 的范围记录绑定 0x362e0→0x3a630 的 __C_specific_handler、0x3959e 过滤器和 0x35411 恢复分支。

1,005 个入口中 724 个有覆盖、281 个缺口，7,433 条引用中 636 条未决。整件静态验收未通过。 [回执](s61-submission.md) · [复验](s61/reassembly.json)

## s65 局部回编

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x359c4,0x35ada)`，片段 SHA-256 `b800253ad5cbaf49cc76bae0c845822204ad369d8d006ab2e2f10f386153102a`。

回编的 278 字节、22 处 REL32、12 字节 .pdata 和 60 字节 .xdata 均与原版一致。 0x359fc 要求状态槽 0x541d0 为 0，其他值走 0x35ace。0x35a09 写入 1，0x35a39 调用 _initterm_e(0x3acc0,0x3acc8)，其失败路径释放启动锁并返回 0。0x35a59 调用 _initterm(0x3ac48,0x3acb8)，0x35a5e 写入 2。展开记录将两段终结范围绑定到 0x395b6，从父帧 +0x40 读取锁标志并转入 0x35418。0x35aa6 的 R9 来源是 CFG 调度槽 0x3ac20，磁盘初值 0x36ae0 再跳转 RAX。RAX 来自 0x54870；该槽初值为零，原件节属性为可写，不能据此给出动态回调目标。成功后递增 0x54790 并返回 1。

1,005 个入口中 725 个有覆盖、280 个缺口，7,433 条引用中 636 条未决。整件静态验收未通过。 [回执](s65-submission.md) · [复验](s65/reassembly.json)

## s69 局部回编

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x35adc,0x35b60)`，片段 SHA-256 `98baaba43113b7361a8183aac6de0ad606107760f29d5d1527ac2abd98adce10`。

回编 132 字节、39 条解码指令、12 处 REL32、12 字节 .pdata、84 字节 .xdata 均匹配。附加计数 0x54790 非正数时直接返回 0，否则递减。初始化状态 0x541d0 须为 2，三处清理调用后将它清零。核对锁标志保存于父帧 +0x20，0x395cd 读取并调用 0x35418，0x395e6 尾跳 0x35294。0x48fe0 的四个终结范围及处理器 RVA 全匹配。

1005 个入口中 726 个覆盖、279 个缺口，7433 条引用中 636 条未决。整件静态验收未通过。

[回执](s69-submission.md) · [复验](s69/reassembly.json)

## s73 局部回编

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x35b60,0x35c91)`，片段 SHA-256 `0285fdb7ca2cf80f7f3e90e73077a87cbc4fe350e4c47466e8855ac6abe290df`。

回编 305 字节、97 条解码指令、12 处 REL32、12 字节 .pdata、40 字节 .xdata 均匹配。reason 0 且附加计数不大于零时直接返回 0；reason 1/2 先过可选回调与 CRT 分派，失败即返回。入口回调失败的 reason 1 走 reason 0 回滚。reason 0/3 在 CRT 分派返回非零后再调回调，有回调时返回其结果，无回调时返回 1。三处间接调用的磁盘初值均走 0x42c48→0x369b8 与 0x3ac20→0x36ae0，两个槽均有 DIR64，调度体跳转 RAX；运行时替换后目标仍未决。范围 [0x35b95,0x35c7b) 的异常过滤器为 0x395fa，接续点 0x35c7b 将结果清零。

1005 个入口中 727 个覆盖、278 个缺口，7433 条引用中 636 条未决。整件静态验收未通过。

[回执](s73-submission.md) · [复验](s73/reassembly.json)

## s77 局部回编

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x360d4,0x36110)`，片段 SHA-256 `80de413be0bad692d40a7cfff93d994ee3740475be5a1b5887c0f4e0f2715c42`。

回编 60 字节、17 条解码指令、3 处 REL32、12 字节 .pdata、12 字节 .xdata 均匹配。起止两条 LEA 均指向 0x445a0，原件的无符号严格小于分支在相等时跳过循环。循环每次增加 8，空指针跳过调用，非空指针在 RAX 中经 0x3ac20 分派；磁盘槽有 DIR64，指向 0x36ae0 的 jmp rax。其他间接站点的运行时目标仍待核。

1005 个入口中 728 个覆盖、277 个缺口，7433 条引用中 636 条未决。整件静态验收未通过。

[回执](s77-submission.md) · [复验](s77/reassembly.json)

## s81 局部回编

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x36110,0x3614c)`，片段 SHA-256 `e36318e0d5411b79b2dc3b873af30708f04dab919c8c35fc17c898251a70e10a`。

回编 60 字节、17 条解码指令、3 处 REL32、12 字节 .pdata、12 字节 .xdata 均匹配。两条 LEA 均指向 0x445b0，严格无符号比较在边界相等时直接退出；循环按 8 字节推进，空值跳过，非空值通过 0x3ac20 分派。原件磁盘槽 DIR64 指向 0x36ae0 的 jmp rax；实际运行时目标保留未决。该段与前一段共享 0x44e68 展开记录。

1005 个入口中 729 个覆盖、276 个缺口，7433 条引用中 636 条未决。整件静态验收未通过。

[回执](s81-submission.md) · [复验](s81/reassembly.json)

## s85 局部回编

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x3633c,0x363e6)`，片段 SHA-256 `f88b5d0135afbb312cfb4a14adb121169f8dfda75fa95cdeb3ff57c48f07c09f`。

回编 170 字节、38 条解码指令、16 处 REL32、12 字节 .pdata、8 字节 .xdata 均匹配。原件先测试 0x42ce0 的 0x1000 位。置位时根据 0x363e8 的 AL 选择调度槽调用或 PAUSE/CMPXCHG 锁路径，随后递增 0x54858，结果为 1 时以类别 4 和 0x5485c 调用 0x365bc。再次调用 0x363e8 后，在恢复栈帧后经调度槽跳转或将 0x54850 清零。0x3ac20 的磁盘 DIR64 初值为 0x36ae0，沿用两处运行时接收目标待核。

1005 个入口中 730 个覆盖、275 个缺口，7433 条引用中 636 条未决。整件静态验收未通过。

[回执](s85-submission.md) · [复验](s85/reassembly.json)

## s89 局部回编

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x3664c,0x366df)`，片段 SHA-256 `86e2bd47334735f5ba5edb3f83e44a8de321ce45b480a48a36b370b30fff1246`。

回编 147 字节、32 条解码指令、15 处 REL32、12 字节 .pdata、8 字节 .xdata 均匹配。原件以 0x42ce0 的 0x1000 位决定是否进入。0x363e8 的 AL 选择 RAX 加载及经 0x3ac20 调用，或 PAUSE/CMPXCHG 锁路径。0x36697 将 0x54858 减一，仅结果为零时将 0x5485c 的值与栈参数地址传给 0x365bc。再次判定后经 0x3ac20 调用释放路径，或直接清零 0x54850。0x3ac20 的磁盘 DIR64 初值指向 0x36ae0，0x36673 与 0x366c7 的运行时接收者继续记为未决。

1005 个入口中 731 个覆盖、274 个缺口，7433 条引用中 636 条未决。整件静态验收未通过。

[回执](s89-submission.md) · [复验](s89/reassembly.json)

## s93 局部回编

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x366e0,0x369b6)`，片段 SHA-256 `a37241803bea0d69bc7e8d8cce04d9ac893f4c311b0a1d62d17e1a7e50c0a766`。

回编 726 字节、195 条解码指令、28 处 REL32、12 字节 .pdata、28 字节 .xdata 均匹配。0x36705 和 0x36990 进出受保护路径。描述符位 0 控制 RVA 模式，失败路径以 0xc06d0057 调用 RaiseException。原件由导入地址槽索引定位名称或序数，依次检查通知回调、缓存模块、加载结果、绑定时间戳和首选映像基址，再回退到 GetProcAddress。0x3688c 原子发布模块；0x36965 写最终地址。通知、失败回调和 API 解析后的运行时地址保留待核。

1005 个入口中 732 个覆盖、273 个缺口，7433 条引用中 636 条未决。整件静态验收未通过。

[回执](s93-submission.md) · [复验](s93/reassembly.json)

## s97 局部回编

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x369b8,0x36a15)`，片段 SHA-256 `a734bfdc8815088d4621896161f2496e4eb73b6f3e08e987dfbf29ee61e67d32`。

回编 93 字节、25 条解码指令、5 处 REL32、12 字节 .pdata、16 字节 .xdata 均匹配。0x54868 位于可写 .data 的加载器零填充区。槽为空时返回 1。槽非空时将槽的地址交给 0x36a18，返回 0 时跳过分派，否则重新取槽值到 RAX，恢复 RCX、EDX、R8 并经 0x3ac20 间接调用。该分派槽的原件 DIR64 初值指向 0x36ae0（JMP RAX）。动态回调值和实际分派目标仍待核。同模块直接调用 0x369e0→0x36a18 单列于回编报告，外部调用、重要数据与待决引用的表内计数不变。

1005 个入口中 733 个覆盖、272 个缺口，7433 条引用中 636 条未决。整件静态验收未通过。

[回执](s97-submission.md) · [复验](s97/reassembly.json)

## s101 局部回编

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x36a18,0x36ac8)`，片段 SHA-256 `10f027a5d2a931866854b85dee9e83f9fa8488615fc60cd3c6ee3a8e757ff201`。

回编 176 字节、53 条指令、4 处 REL32、12 字节 .pdata 和 32 字节 .xdata 全部匹配。原件按 MZ、PE 签名、PE32+ 魔数及 e_lfanew 解析当前映像，按节表的 RVA 和 VirtualSize 做半开区间判断。仅落在节内且 Characteristics 位 31 为零时返回 1。SEH 保护范围 [0x36a1f,0x36ac1)，筛选函数 0x3959e 仅匹配 0xC0000005，再转入 0x36ac1 返回 0。0x362e0 经 IAT 0x3a630 绑定 VCRUNTIME140.dll!__C_specific_handler。

1005 个入口中 734 个覆盖、271 个缺口，7433 条引用中 636 条未决。整件静态验收未通过。

[回执](s101-submission.md) · [复验](s101/reassembly.json)

## s105 局部回编

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

范围 `[0x36ae0,0x36ae2)`、`[0x36b00,0x36b06)`。回编 8 字节、2 条指令、1 处 REL32、24 字节 .pdata 与 8 字节 .xdata 全部匹配。0x36ae0 直接跳 RAX，0x36b00 尾跳经 0x3ac20。Load Config 指明该槽为 GuardCFDispatchFunctionPointer，原件 DIR64 与磁盘初值均指向 0x36ae0。两个入口分别具有零展开码的独立 UNWIND_INFO。实际加载后分派目标及调用者赋给 RAX 的值仍待核。

1005 个入口中 736 个覆盖、269 个缺口，7433 条引用中 636 条未决。整件静态验收未通过。

[回执](s105-submission.md) · [复验](s105/reassembly.json)

## s109 局部回编

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

范围 `[0x36d30,0x36d58)`、`[0x36d70,0x36db3)`、`[0x36dc0,0x36dfd)`。回编 168 字节、46 条指令、8 处 REL32、36 字节 .pdata 与 32 字节 .xdata 全部匹配。三个入口把传入的 RDX 保存在 RBP，并从帧槽装入 RCX、RDX、R8。0x36d30 从 +0x60、+0x78、+0x68 取参调用 0x1d570。0x36d70 依次从 +0x20、+0x30、+0x80 和 +0x80、+0x28、+0x98 取参调用 0x7020、0x1d5c0。0x36dc0 依次从 +0x78、+0x20、+0x70 和 +0x70、+0x28、+0x88 取参调用 0x7060、0x1d610。三者均清零 ECX、EDX，经 0x362c2 和 IAT 0x3a640 调用 VCRUNTIME140.dll!_CxxThrowException。后两个入口共用原件的 0x46ba8 展开布局。帧槽的源码类型待核。

1005 个入口中 739 个覆盖、266 个缺口，7433 条引用中 636 条未决。整件静态验收未通过。

[回执](s109-submission.md) · [复验](s109/reassembly.json)
