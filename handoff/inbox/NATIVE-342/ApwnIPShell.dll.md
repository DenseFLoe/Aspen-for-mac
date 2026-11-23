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
