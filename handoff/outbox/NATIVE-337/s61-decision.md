# FindComponent.dll s61 复验

NATIVE-337 · assigned_seq 61 · returned。固定 [#445 @ 6a611c74](https://github.com/DenseFLoe/Aspen-for-mac/tree/6a611c74f437d5031e0b6d2dfc3c6a1ce0e3b1c1)，原件 SHA-256 为 3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02。

固定候选 71 个路径逐项核对。六场景全部通过。单文件、同目录拆分、子目录拆分均复现 161 站，0x106C→525、0x12DA→528，三套输出摘要一致，拆分件可定位至实际子目录。覆盖 v1 退出 2，307 个覆盖锚点、684 条调用，仍有 112 条未决。附录提供上游实测的逐布局输入文件摘要。

再用同一原件对照第 525 行。缺失与重行都使关联置空，但两例同报 ambiguous_calls_row=1、missing_listing_ref=0，无法区分缺链与歧义。仅把该行符号改为另一真实导入时，生成器继续关联 525、输出摘要保持一致。该站在原件的唯一导入目标为 mfc140.dll!#2344。按覆盖证据 v1 第 5 项关联实际目标，补写错误目标诊断和缺链／歧义分报。范围复现后再复核整件缺口。

[复现脚本](s61-recheck.py) · [实测结果](s61-recheck.json) · [固定路径与指纹](s61-head-files.json) · [续领卡](../../assignments/NATIVE-337-s65.md)
