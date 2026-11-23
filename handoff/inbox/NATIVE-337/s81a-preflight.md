# s27 流程修正：preflight 检测器（NATIVE-337）

按 §27 五步，把已发生的打回类别各落一条检测器。`tool/preflight.py` 是 t13/t14 共用文件，本轮以**追加方式**合并（未覆盖对方代码）；自本轮起 preflight.py 归 **t16** 单一 owner，t13/t14 只提交 `tool/det_<name>.py` 片段 + 注册表。

## 类别 / L1 覆盖 / 检测器
| 类别 | 表现 | L1 覆盖 | 检测器 |
| --- | --- | --- | --- |
| symbol-substring | `#2344` vs `#23440` | partial | `det_symbol_substring`：同站绑定前缀关系符号、note 与 callee 前缀变体 → defect |
| wrong-symbol | `0x2388` 认成 CoCreateInstance（实为 MultiByteToWideChar） | no | `det_wrong_symbol`：声明符号必须精确存在于原件导入表 |
| receipt-misstatement | 回执路径与实际不符 | no | `det_receipt_paths`：最新回执中 `code/...` 路径必须存在，64 位 SHA 必须能在交付或 `tool/` 找到 |
| access-flags | 报 privatescope，实际 `0x4013` = Assembly | no | `det_access_flags`：出现访问级别必须给 `flags=0x…`，且 `flags & 7` 映射须与文字一致 |
| access-prose-map | **散文里的映射表写错**（曾把 Private/Public 两级写反，本轮已改） | no | **本轮新增 `tool/det_access_prose.py`**：把散文里出现的 `值→级别` 逐项与 ACCESS 常量比对 |
| byte-mismatch | 第 28 行改一字节仍报 ok | partial | `det_byte_mismatch`：逐条清单字节与原件同址比较 |

## MemberAccessMask（唯一口径，ECMA-335 II.23.1.10）
| 值 | 级别 |
| --- | --- |
| 0 | CompilerControlled（privatescope） |
| 1 | Private |
| 2 | FamANDAssem |
| 3 | Assembly |
| 4 | Family |
| 5 | FamORAssem |
| 6 | Public |

因此 `0x4013 & 0x7 = 3` = **Assembly**（不是 privatescope，也不是 Private）。

## 自检结果（映射表 vs ACCESS）
~~~
python -B tool/det_access_prose.py handoff/inbox/NATIVE-337
stats {'documents_checked': 22, 'mask': '0..6 MemberAccessMask'} defects 0
~~~
本文件此前把 Private/Public 两级写反（真实错例，不再复述具体取值），正是该检测器的第一个真实命中，已按上表改正。

## 注入反例（tool/preflight_backtest.py）
~~~
BT symbol-substring : PASS   （同站注入 #23440）
BT wrong-symbol     : PASS   （BOGUS.dll!NoSuchImport）
BT access-flags     : PASS   （private + flags=0x4013 → Assembly 不符）
BT byte-mismatch    : PASS   （E8 32→33）
BT receipt-misstate : PASS   （code/no-such-file.csv）
PROBE rva-shuffle / rename / unseen-head : 不崩、不假通过
SUITE : ALL PASS
~~~

## 流程修正（写规则，不是"已修正该处"）
- 规则 1：符号判等一律整串精确身份（`DLL!名/#序号`），禁止子串；同站前缀符号即 defect。
- 规则 2：凡报访问级别，必须回读 Flags 原始值并断言 `flags & 7` 映射；映射以 ECMA-335 II.23.1.10 为准（0..6 如上表），文字不符即 defect。
- 规则 2b：**散文中的映射表本身**也要过 `det_access_prose`，避免「代码对、散文错」再次传到上游。
- 规则 3：回执里的路径与 SHA 由脚本从产物生成，preflight 再回读校验一次。
- 规则 4：提交前必须跑 preflight；新类别按「抽类别 → 判 L1 → 加 detector 片段 → 注入反例 → 回执写流程修正」。
