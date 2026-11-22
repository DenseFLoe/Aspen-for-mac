# zedstwu.dll 第二十一号交付

NATIVE-350，owner upstream，assigned_seq=21。固定主干 `ff585268ac8983097b8a229e3d8e49abee61d7e1`，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。产品为 Aspen Plus V15.0，原路径 `Engine/Xeq/zedstwu.dll`。沿用第十七号已核对的分派与缓存证据。[任务卡](../../assignments/NATIVE-350-s21.md) · [前轮证据](s17/dispatch-evidence.json)

| 原件起止 RVA（右端不含） | 回编字节 | 指令数（含对齐） | COFF REL32 操作数字段 → 目标 RVA | 范围 SHA-256 |
| --- | ---: | ---: | --- | --- |
| 0xcbe0–0xcbe8 | 8 | 2 | 0xcbe3 → 0xcd80 | `d740376f069513192c97c0dbdda6e5c39eedd1360a62c58fe60ce92d91d43fb8` |
| 0xcbf0–0xcbf8 | 8 | 2 | 0xcbf3 → 0xe5c0 | `8e76d8faea7a668fed332a38927d8ebcb47e2f8484cdebe053e9e3cf10e846ea` |
| 0xcd80–0xe589 | 6,153 | 325 | 0xcdf6 → 0x22248，0xceb3 → 0x22238 | `72586b05df77ea74f39bcc554d92941fe99e1e417afeb70728e4a4dec746d58b` |

0xcc20 初始化器在 0xcc58 调用 0xcbf0、在 0xcc77 调用 0xcbe0。两个叶函数都只将实现地址装入 RAX 后返回。0xcd80 保存目的指针，返回前执行 VZEROUPPER 并恢复非易失寄存器。函数内部无 CALL。尺寸 ≤256 时直接进小复制表；更大尺寸先复制使目标按 32 字节对齐的前缀。一个循环每轮复制 256 字节。0xcdf3 读取 0x22248 并计算其值减去四分之一，0xceb0 读取 0x22238，按当前值选择缓存写、REP MOVSB 或带 SFENCE 的非临时写。两个 64 位共享字的映像初值分别是 8,192、65,536；运行时写入来源仍待核实。[指令逐址对照](s21/instructions.lst) · [调用、分支和数据引用](s21/references.csv)

1,793 字节是 0xcd80 内的指令及对齐。其余 4,360 字节按 `表基址 − 目标标签` 恢复成 545 个 64 位表项。四处分派均先从 R9 中减去表项，再跳入本函数的指令边界。下表的索引范围适用于 Windows 用户态有效复制长度。[全部表槽](s21/table-slots.csv) · [各分派的可达目标](s21/rebuild.json)

| 跳转 RVA | 表地址 | 表项总数 | 实际索引 |
| --- | --- | ---: | --- |
| 0xcd9f | 0xdd70 | 257 | R8，0–256 |
| 0xcdda | 0xd470 | 32 | R14，1–31，零对齐跳过前缀 |
| 0xd084 | 0xd570 | 256 | R8，0–255，最后一个不足 256 字节的块 |
| 0xd0fd | 0xd570 | 256 | R14，0–31，最终目的地址的低五位 |

复验从仓库根运行 `python -B handoff/inbox/NATIVE-350/s21/verify-copy.py <zedstwu.dll> <zig>`，使用 Zig 0.13.0、Capstone 5.0.7、iced-x86 1.21.0、pefile 2024.8.26。三段源码单独编译成 COFF，核对原件四个 RIP 相对操作数、两种解码器的指令边界及全部表项，最后逐字节比较。运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original <zedstwu.dll>`，检查器返回 2。255 个入口中已覆盖 145 个、申报缺口 110 个，3,567 条调用或数据记录中仍有 38 处未决。[本轮文件指纹](s21-manifest.sha256)

**下一张卡建议。** 从 0xcbf0 已绑定的高能力复制目标 0xe5c0 接续。原件异常目录给出 `[0xe5c0,0x100c2)`，范围 SHA-256 `86177c7f8c319b6bfcfd11f4a4499c414db8fd18d7df16401ed7ff2ab844cfea`。核对 0xe5e4、0xe611、0xe951、0xe9c1 的四处间接跳转与表基址 0xfcc0、0xeac0、0xecc0，逐项建立尺寸边界以及共享阈值 0x22238 的引用，再按原件回编。低能力复制目标 0x16560 已有上轮回编，回退为 VCRUNTIME140.dll!memcpy。填充一侧的 0x13000、0x11f40、0x17610 仍需各自的函数边界、数据及完整回编；回退为 VCRUNTIME140.dll!memset。0xcc10、0xcce0 的缓存命中路径仍需核对全部可能写入来源。
