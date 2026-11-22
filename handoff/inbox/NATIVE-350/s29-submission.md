# zedstwu.dll 第二十九号交付

NATIVE-350，owner upstream，assigned_seq=29。固定主干 `414617eaf303764aaae2904151e2e018a2af364d`。Aspen Plus V15.0，`Engine/Xeq/zedstwu.dll`，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。[任务卡](../../assignments/NATIVE-350-s29.md) · [上一轮](s25-submission.md)

异常目录给出 `[0x11f40,0x12ff8)`，非易失寄存器恢复对应的原件 unwind RVA 为 `0x1c380`。可编辑 C 内联汇编恢复 4,280 字节。Capstone 与 iced-x86 的 189 条指令边界一致，含 34 条对齐 NOP。嵌入表存有 418 个 64 位差值，占 3,344 字节。用 Zig 0.13.0 编译，重定位字段 `0x11fc3` 绑定 `0x22240` 后逐字节匹配，范围 SHA-256 `49645f46662948f2a0070f7264f5409d006755c2340866023174e70a88ce98fc`。[源码](s29/avx-fill.c) · [逐址回编](s29/rebuild.json) · [原件清单](s29/instructions.lst)

`0xcd34` 的 `0x9d9fee` 能力分支在更高掩码不满足后选择 `0xcd45 → 0xccb0 → 0x11f40`，初始化器在 `0xcd78` 跳转。下表以可用的非负缓冲区长度为输入范围，记录从 RDX 表基址减去被选差值后得到的可达目标。

| JMP RVA | 槽读取 RVA | 表 | 实际索引 | 不同目标 |
| --- | --- | --- | --- | ---: |
| `0x11f78` | `0x11f74` | `0x12be0` | R8，0–128 | 15 |
| `0x11fa4` | `0x11fa0` | `0x122e0` | RCX，1–31；已对齐直接跳过 | 9 |
| `0x12115` | `0x12111` | `0x123e0` | R8，0–255 | 17 |
| `0x1216a` | `0x12166` | `0x123e0` | R8，0–31 | 10 |

三表原件存储分别有 130、32、256 槽。`0x12be0` 第 129 号和 `0x122e0` 第 0 号槽保留原有值，该分派路径按原件条件不会读它们。51 对位置和可达目标及 33 个直接分支已登记到[控制流索引](internal-transfers.csv)。[全部表槽](s29/table-slots.csv)

`0x11fc0` 读取可写 .data 的 8 字节阈值 `0x22240`，其映像初值为 16,384。原件以阈值减去其右移四位的值比较剩余尺寸，按映像初值为 15,360，大于等于该边界走 `CLD; REP STOSB`。较小的大块长度走每轮八次 32 字节向量写。运行期阈值的写入者仍需另查。

```text
python -B handoff/inbox/NATIVE-350/s29/verify-avx-fill.py ORIGINAL ZIG
python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL
```

第一条退出 0。第二条主干检查器实测 255 条覆盖行、255 个分析器入口、3,567 条调用与引用，申报 108 个入口缺口，退出 2。主表未决由 34 降到 30。该范围的任务卡条件已获得证据，整件静态验收仍有缺口。[本轮指纹](s29-manifest.sha256)
