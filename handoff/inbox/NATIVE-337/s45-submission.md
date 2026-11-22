# NATIVE-337 s45 提交

## 1. 生成器（进交付，依赖与指纹）

| 文件 | SHA-256 |
| --- | --- |
| tool/s37_two_hop.py | a2ed873660620bf468db10f6716c812c9ef207c6972e21622411b7ff00a6c271 |
| tool/pe_reader.py | c0efbbffc93a0331b86dab66f93564a846890c479edad58e1ac59247053c8037 |

依赖：Python 3.13.5，仅标准库（argparse/csv/struct/sys/pathlib/re/json）。生成器不读旧附表，行数由清单发现。

## 2. 推导顺序（按卡）

1. 原件字节：site 的 E8/E9 rel32 → 首跳 RVA；首跳体 FF25(+REX) → IAT 槽；导入目录 → DLL!符号
2. 候选清单 FUNC 片段范围 → 候选宿主（多条命中时取**最内层**片段，统一规则，无地址特判）
3. 原件 .pdata 异常目录 → 原件宿主
4. 主表按**引用位置**（listing 行号）→ calls.csv 行号

## 3. 反例测试（tool/s45_tests.py，实际 stdout）

A 删站自愈：从旧附表删除 0x106C 后重跑 → rc=0，rows=161，recovered_0x106C=True（**独立找回**）
B 对照实验：把清单片段改为从 0x12B6 起 → rc=0，candidate_owner=0x12B6，original_host=0x11E0（**两侧各自解析**）
C 空目录重放：rc=0，rows=161，sha256=2ef4b467155284f011c9fecd7c457c80cbfb9bff148b0acee7c4a60c5e8a20bf

## 4. 与固定摘要 72918f68… 的差异（如实）

- 固定摘要 72918f68564e24dcb5e6f376bc04deacd0cc3ceece560198cfcba0a519d906bf
- 本轮摘要 2ef4b467155284f011c9fecd7c457c80cbfb9bff148b0acee7c4a60c5e8a20bf
- 逐行比对只有 **1 个单元格**不同：0x12DA 的 candidate_owner 旧值 0x12bd（小写）vs 新值 0x12BD（统一 0x%X 规则）
- 原因：旧值来自被删除的「0x12DA 固定覆盖」；按卡第 5 条（不得赋予偶然地址语义），本次统一用 0x%X 输出，未保留该单元格的历史小写。其余 160 行逐字节相同。若上游要求逐字节回到 72918f68，只能在输出层加一个全列小写规则（会让所有含 A–F 的地址一起变小写，摘要同样变化），或恢复地址特判（违反第 5 条）。

## 5. 判定

~~~sh
python -B handoff/outbox/NATIVE-337/check-s33.py <原件> <候选目录>
# exit 0（two_hop 161 全栏匹配 / COM 64 / dispatch 16 / metrics 全对）

PYTHONPATH=D:/Lib/site-packages python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original <原件> --submission <候选目录>
checked 307 coverage rows, 307 tool-native entries, 684 call records, 0 declared gaps
# exit 2
~~~

## 6. 指纹

- s37-two-hop.csv sha256 2ef4b467155284f011c9fecd7c457c80cbfb9bff148b0acee7c4a60c5e8a20bf
- coverage.csv sha256 3afe1c2a87c9e70c95a8a9216d5f68798fd14e934ff75fa8dc49d41fee00fb43
- calls.csv sha256 d6f82133e5187d15efbaf5f3d2e87944cb6d5b60088516b3fa140eabbe569c04
