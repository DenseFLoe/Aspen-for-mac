# zedstwu.dll 诊断输出例程

Aspen Plus V15.0 Engine/Xeq，原件版本 41.0.0.609，SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。可编辑 AMD64 汇编覆盖原件 RVA `[0x15180,0x15220)`，160 字节，范围 SHA-256 `3a7e60ad7c37883a4c047ccd60a1c35881af319f8d2c4bba9154a5d1fb1a92ef`。

入口保存 RSI、RDI 和第 4 个寄存器参数 R9，分配 0x48 字节栈。保存的 R9 在调整后的 `[rsp+0x78]`，对应入口 RSP 加 0x20。全局 `[0x221c0]` 的 64 位 cookie 与调整后的 RSP 做 XOR 后保存在 `[rsp+0x40]`。三条分路在 0x1520b 汇合，从该槽取回 cookie 并 XOR 同一 RSP，经 RCX 传给 0x18110 校验，然后收回 0x48、弹出 RDI 和 RSI。

| 条件 | 原件分支 | 调用及参数 |
| --- | --- | --- |
| EDX 为零 | 0x1519a 的 TEST 后，0x1519c 跳到 0x151ff | 将 RCX 设为 0x1a985 的 `"\n"`，0x15206 调 0x185b0 |
| EDX 非零，原始 R8D 有符号小于等于零 | 0x1519e 把 R8D 保存在 EDI；0x151ab 的 TEST 后，0x151ad 跳到 0x151ee | 0x151a3 先以 ECX=EDX 调 0x15000，把 RAX 暂存在 RSI。输出用 RCX=0x1a987 的 `"%s\n"`、RDX=RSI，0x151f8 调 0x185b0 |
| EDX 非零，原始 R8D 有符号大于零 | 0x151ad 不取跳 | 根据下列实参执行 CRT 格式化，随后将缓冲区地址写入 RSI，再进入同一条 `"%s\n"` 输出路径 |

0x151b9 调 0x158d8。该目标用 LEA 返回 0x22ca0，来方从返回地址解引用 64 位选项并 OR 2，传到 `__stdio_common_vsprintf` 的 RCX。RDX 为 0x23850 的缓冲区地址，R8D 为 0x200 字节，R9 为 0x15000 返回的格式字符串地址。第 5 个参数 `[rsp+0x20]` 为零，第 6 个参数 `[rsp+0x28]` 指向保存 R9 的 `[rsp+0x78]`。0x151e6 直调 0x180de；后者经 IAT 0x19188 指向 `api-ms-win-crt-stdio-l1-1-0.dll!__stdio_common_vsprintf`。0x151eb 选用缓冲区地址，未根据 CRT 返回值分支。

s45 调用点 0x14f3c、0x14f4e、0x14f5d 分别传入前三个寄存器参数 `(1,0,0)`、`(1,0x3d,0)`、`(1,0,0)`。本函数入口的原始 RCX 在构造新调用参数前未被读取。0x15000 在返回前以 RDI 写入 RAX，调用者按字符串地址使用；其完整索引、资源及回退处理仍待 s53 复核。0x185b0 的完整输出实现及 0x158d8 的函数归档也仍待核。这里确认上述参数传递、调用边与数据范围。整件仍有 102 个入口和 26 条引用待核。

[原指令](instructions.lst) · [回编结果](reassembly.json) · [复验步骤](check-diagnostic.py.md)
