# NATIVE-337 s73 独立复验

按 [#445 @ d4076c4](https://github.com/DenseFLoe/Aspen-for-mac/tree/d4076c4823da715184d4f3210b0feb6d33c0031d)、[s73 卡](../../assignments/NATIVE-337-s73.md)与[覆盖证据 v1](../../standards/native-coverage-evidence.v1.md)复验。复用经 SHA-256 核对的 FindComponent.dll，指纹为 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`。本轮核对 11 个增改文件和 82 个复用文件的 Git blob、SHA-256 和字节数。7 份工具指纹与固定候选回执一致。开工材料只写了 10:1x，台账采用固定候选提交的首个精确时间 01:50:15 UTC。[候选指纹](s73-fixed-manifest.json) · [交付通知](https://github.com/DenseFLoe/Aspen-for-mac/issues/13#issuecomment-7089460229)

在固定候选副本内运行覆盖命令。复验脚本从任意目录执行，参数依次为固定副本路径、原件路径、报告输出路径。Python 加载 Capstone 5.0.7 和 pefile 2024.8.26。覆盖脚本使用基线主干 `85a00df048174880027d84a5cb4a2d006f78f82c` 的字节，SHA-256 `27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8`。

```text
python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original ORIGINAL --submission handoff/inbox/NATIVE-337
python -B tool/s69_tests.py
python -B tool/s45_tests.py
python -B s73-review.py FIXED ORIGINAL s73-recheck.json
```

覆盖 v1 退出 2，307 行、307 原生入口、684 调用、0 申报 gap，112 个 unresolved。五项候选反例和六个历史场景退出 0。三种清单布局各 161 站，关联行 525 与 528 一致。原件重新导出 161 站，与候选站表字节相同，SHA-256 `23046e75dcfa68c4179cc6521c456dcec947e8ff0ec50fe3f6da2854ed0c699c`。[复跑脚本](s73-review.py) · [实测输出](s73-recheck.json)

## 四条初始化路径退修

原件在 0x2388 经过 IAT 0x7050 调 KERNEL32.dll!MultiByteToWideChar，原始 ProgID 字符串位于 0x78A8。0x23A0 经 IAT 0x7648 调 ole32.dll!CLSIDFromProgID，将 CLSID 写入栈局部变量。0x23C8 经 IAT 0x7650 调 ole32.dll!CoCreateInstance，R9 取 0x8308 的 IID `00020400-0000-0000-c000-000000000046`，第五参数指向接口输出槽。成功时 0x23D2 取该槽到 RAX，失败时 0x23D8 清零，调用方 0x133D 把 RAX 存入 RDI。

0x1389、0x1396、0x1444、0x1457 的指令字节、虚表取值和槽 0x28、0x10、0x30、0x10 均匹配。候选 4 条初始化记录和生成器都将 CoCreateInstance 归到 0x2388。按固定原件中导入目录和操作数解析调用位置，输出应为上面三项。运行期实现地址仍待实际对象的虚表确认。[候选生成器](https://github.com/DenseFLoe/Aspen-for-mac/blob/d4076c4823da715184d4f3210b0feb6d33c0031d/tool/s73_four_calls.py)

## 验收器实测对照

- 覆盖 v1 的操作数核对沿用 [s69 已知问题](s69-verifier-notes.md)。同一原件只改交付清单第 28 行的一个字节，`E8 32 3A 00 00` → `E8 33 3A 00 00`，重算交付指纹。覆盖仍退出 2，s73 分类器定位 0x106C 和两个完整字节串。建议把完整指令比对加入覆盖检查，回归期望正常材料退出 2、改动版退出 1 并定位该站。
- 候选分类器 `tool/s65_counterexamples.py` 固定 SHA-256 `704e429699c54296ba553cfbcb1b2637bc3c5bb64df8fd708cb95c3c5ae0acee`。将缺少 0x106C 的同一个候选清单配对原件重建的站表和只删 0x106C 一行的站表，重算站表指纹。完整表得到 160 ok 和 1 missing-listing，删行表仅有 160 ok，两者退出 0。无站表时程序退出 1，覆盖 v1 也正确拦住缺指令。建议把原件站集生成接入分类，或先逐站核对缓存表的原件身份和全集。回归期望缩减表被拒绝或仍报告缺站。复跑命令与指纹见上面的脚本和输出。
