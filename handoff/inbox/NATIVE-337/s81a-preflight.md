# s27 流程修正：preflight 检测器（NATIVE-337）

按 §27 五步，把已发生的打回类别各落一条检测器。**注意：`tool/preflight.py` 是 t13/t14 共用文件**（t14 的 L1+L2 框架已在其中），本轮以追加方式合并，未覆盖对方代码。

| 类别 | 表现 | L1 覆盖 | 检测器 |
| --- | --- | --- | --- |
| symbol-substring | `#2344` vs `#23440` | partial | `det_symbol_identity`/`det_symbol_substring`：同站绑定前缀关系符号、note 与 callee 前缀变体 → defect |
| wrong-symbol | `0x2388` 认成 CoCreateInstance | no | `det_wrong_symbol`：声明符号必须精确存在于原件导入表 |
| receipt-misstatement | 回执路径与实际不符 | no | `det_receipt_paths`（本轮新增）：最新回执中 `code/...` 路径必须存在，64 位 SHA 必须能在交付或 `tool/` 找到 |
| access-flags | 报 privatescope 实为 `0x4013`=Assembly | no | `det_access_flags`：出现访问级别必须给 `flags=0x…`，`flags&7` 映射须与文字一致 |
| byte-mismatch | 单字节改仍 ok | partial | `det_byte_mismatch`/`det_instruction_bytes`：逐条清单字节与原件同址比对 |

合并后实测（真实候选）：
~~~
l1 pin_ok=True exit=2 :: checked 307 coverage rows, 307 tool-native entries, 684 call records, 0 declared gaps
l2 receipt_paths / omitted_sites / stale_metrics / row_linkage / fingerprint_pathset / unresolved_no_recovery /
   symbol_substring / wrong_symbol / byte_mismatch / access_flags  defects=0
exit: 2
~~~

注入反例（tool/preflight_backtest.py）：symbol-substring / wrong-symbol / access-flags（private + flags=0x4013）/ byte-mismatch / receipt-misstate 五类各命中 1；RVA 打乱、rename、删光回执三探针不崩、不假通过。

## 流程修正（不是"已修正该处"）
- 规则 1：凡符号判等一律整串精确身份（`DLL!名/#序号`），禁止子串；检测器对同站前缀符号报 defect。
- 规则 2：凡报访问级别，必须回读 Flags 原始值并断言 `flags & 7` 映射（0x0 CompilerControlled / 0x1 Public / 0x2 Private / 0x3 Assembly / 0x4 Family），文字与映射不一致即 defect。
- 规则 3：回执里的路径与 SHA 由脚本从产物生成，preflight 再回读校验一次。
- 规则 4：提交前必须跑 `tool/preflight.py`；新类别按「抽类别→判 L1→加 detector→注入反例→回执写流程修正」执行。
