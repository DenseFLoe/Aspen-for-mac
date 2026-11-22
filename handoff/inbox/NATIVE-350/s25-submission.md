# zedstwu.dll 第二十五号交付

NATIVE-350，owner upstream，assigned_seq=25。固定主干 `c260f73c2d5043aaa8731e688b0662d4f6ab3bd0`。Aspen Plus V15.0，`Engine/Xeq/zedstwu.dll`，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。[任务卡](../../assignments/NATIVE-350-s25.md) · [上一轮](s21-submission.md)

异常目录给出的 `[0xe5c0,0x100c2)` 有 6,914 字节。244 条指令（含 2 条对齐 NOP）占 1,282 字节，704 个符号差值槽占 5,632 字节。编译为 COFF 后唯一的 REL32 为 `0xe62a → 0x22238`。补齐重定位后每字节相同，范围 SHA-256 `86177c7f8c319b6bfcfd11f4a4499c414db8fd18d7df16401ed7ff2ab844cfea`。[可编辑源码](s25/copy-high.c) · [逐址回编](s25/rebuild.json) · [指令](s25/instructions.lst) · [引用](s25/references.csv)

四处跳转均把索引选出的 64 位差值从 R9 表基址减去，共核实 56 对分派位置与可达目标。

| JMP RVA | 槽读取 RVA | 表基址 | 实际索引 | 不同目标 |
| --- | --- | --- | --- | ---: |
| `0xe5e4` | `0xe5e0` | `0xfcc0` | R8，0–127 | 14 |
| `0xe611` | `0xe60d` | `0xeac0` | RSI，1–63；对齐前缀为零则跳过 | 11 |
| `0xe951` | `0xe94d` | `0xecc0` | R8，0–511 | 19 |
| `0xe9c1` | `0xe9bd` | `0xecc0` | RSI，0–63；目的末址低六位 | 12 |

索引判断适用于 Windows 用户态可用的非负复制长度。函数保留原目标地址作为返回值；短复制直接入表，大复制先对齐目的到 64 字节边界。每次循环复制 512 字节。原件 `0xe627` 从可写 .data 读取 8 字节的 `0x22238`，映像初值为 65,536，按该比较在普通向量存储与非临时存储间选择。后者使用 SFENCE 再进入尾段。当前证据覆盖该函数的阈值读取，运行期写入者需从其他相关代码的初始化或传入指针追溯。[全部表槽](s25/table-slots.csv)

从仓库根运行 `python -B handoff/inbox/NATIVE-350/s25/verify-copy-high.py ORIGINAL ZIG`。验证器用 Capstone 与 iced-x86 分别读原件指令边界，用 Zig 0.13.0 编译可编辑源并核对 COFF 绑定。主干 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL` 返回 2，255 个入口中 146 个已覆盖，109 个尚缺源码或原件级回编，对照 3,567 条引用仍有 34 处未决。调用数据表中的四处未决更新为表项读取，分派的目标和 33 条直接分支归入 [internal-transfers.csv](internal-transfers.csv)。整件仍待修复。[本轮指纹](s25-manifest.sha256)

下一件可沿填充分派的 AVX 目标 `0x11f40` 接续。原件异常目录确定 `[0x11f40,0x12ff8)`，范围 SHA-256 `49645f46662948f2a0070f7264f5409d006755c2340866023174e70a88ce98fc`，分派特性掩码 `0x9d9fee`。优先核对该范围的表、共享量和回编；其他填充目标独立建证。
