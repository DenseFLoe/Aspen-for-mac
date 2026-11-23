# s27 流程修正：preflight 检测器（NATIVE-337）

本轮按 §27 五步，把已发生的打回类别各落一条检测器（`tool/preflight.py`），并给出 L1 覆盖判定与反背题探针。

| 类别 | 表现 | L1 是否覆盖 | 处理 |
| --- | --- | --- | --- |
| symbol-substring | `#2344` 与 `#23440` 判等 | partial（只查结构，不查符号判等） | detector：同一站绑定两个前缀关系符号 / note 与 callee 前缀变体 → 报 |
| wrong-symbol | `0x2388` 认成 CoCreateInstance（实为 MultiByteToWideChar） | partial（不解析 IAT 符号身份） | detector：声明的 `DLL!名前缀` 必须精确存在于原件导入表 |
| receipt-misstatement | 回执写 `code/s45-two-hop.csv`，实际 `code/s37-two-hop.csv` | no | detector：回执里每个路径必须存在；每个 64 位 SHA 必须能在交付或 `tool/` 中找到 |
| access-flags | 报 `privatescope`，实际 `0x4013` = Assembly | no（337 无访问级别声明） | detector：出现访问级别必须同时给 `flags=0x…`，且 `flags & 7` 映射须与文字一致 |
| byte-mismatch | 第 28 行改一字节仍报 ok | no | detector：逐条指令字节与原件同址比较 |

## 反背题（tool/preflight_backtest.py，一条命令）
~~~
BT symbol-substring : PASS   （同站注入 #23440）
BT wrong-symbol     : PASS   （BOGUS.dll!NoSuchImport）
BT access-flags     : PASS   （private + flags=0x4013）
BT byte-mismatch    : PASS   （E8 32→33）
BT receipt-misstate : PASS   （code/no-such-file.csv）
PROBE rva-shuffle   : 未崩、未假通过
PROBE rename        : 未崩（native.asm → native-part.asm）
PROBE unseen-head   : 未崩（删掉全部回执）
SUITE : ALL PASS
~~~

## 当前候选上的 preflight 结果
~~~
PREFLIGHT findings=0 PASS   （exit 0）
~~~

## 流程修正（不是"已修正该处"）
- 规则：凡「符号/路径/字段解码/字节」类断言，提交前必须先跑 `tool/preflight.py`；它不依赖上一轮缓存，逐条从原件与该轮产物重算。
- 新类别默认流程：从裁定抽类别 → 判 L1 覆盖 → 不覆盖则加 detector → 注入反例确认能检出 → 写回执。
