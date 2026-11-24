# 门禁加固记录（外部静态审计 17 条）

自测：python -B qa/selftest.py → 17/17 passed。每条断言都针对加固前的行为；
critical 的三条在加固前会直接给出 0 退出码（见每条说明）。

## 已修（14 条）

| # | 类别 | 位置 | 修复 | 自测 |
| ---: | --- | --- | --- | --- |
| 1 | aggregate-order (critical) | gate.run_l1/aggregate | 先验 pin 再执行；checker 缺失或 hash 不符时**不执行**，直接判失败；L1 未运行不再回退到 L2 结论（仅显式 --skip-l1 允许，且报告标注 skipped/非权威） | l1-missing-blocks / l1-pin-mismatch-blocks（含 subprocess 未被调用断言） |
| 2 | exception-swallow (critical) | gate.aggregate | 导入失败 / execute 抛异常 / 显式返回 error 三条路径统一 status=error 并阻断；同时进入 problems[] | detector-import-failure / detector-exception / detector-error-result |
| 3 | exception-swallow (critical) | det_semantic_rebuild.detect | 无法完成往返记为错误：compared==0 → error；asm_error 超过 1% → error；重解码必须整条消费；逐节字节覆盖不足 → defect | rebuild-no-comparison-error |
| 4 | vacuous-pass | gate.load_detectors | 注册项无可调用 detect / 导入失败 → 变成可见的 error 单元，不再静默消失 | registry-empty-entry-blocks |
| 5 | vacuous-pass | gate.aggregate | 全部单元 not-applicable → 判失败（什么都没查不等于通过） | all-units-na-blocks |
| 6 | vacuous-pass | gate.unit_status | 计数键缺失 / 类型错 / bool → error；不再累加其它整数糊过去 | missing-counter-is-error / bool-counter-not-int |
| 7 | aggregate-order | gate._covers | l1_covers 只接受 {yes,no,partial}（大小写统一），非法值 → error | invalid-l1-covers-blocks |
| 8 | vacuous-pass | gate.check_head | truncated 标记 → error；want 与 have 同时为空 → error | check-head-truncated-error |
| 9 | vacuous-pass | det_semantic_rebuild.detect | 每节 bytes_decoded + data_bytes 必须等于 len(chunk)，否则 defect | （随 #3 一起，见 stats.sections[].bytes_decoded） |
| 10 | vacuous-pass | det_semantic_rebuild.detect | 重解码结果必须消费 len(enc) 全部字节，否则记 asm_error | 同上 |
| 11 | definition-drift | det_semantic_rebuild.stats | compared = ok + whitelisted + mismatch（mismatch 也算完成了比较）；inputs_checked = total_instructions，不再做任何减法推导 | （README 容量段 + selftest 中的 inputs 断言） |
| 12 | vacuous-pass | common.resolve_ref / asm_line_rva | 包含性用 realpath+commonpath 判定（前缀目录不再被误接受）；单字节行尾指令可解析 | resolve-ref-containment / asm-line-rva-single-byte |
| 13 | definition-drift | common.current_round / is_current | 两者统一按相对路径取轮次 | current-round-consistent |
| 14 | definition-drift | gate.aggregate | 原件 sha256 真正比对，不符 → problems + 非零 | original-sha-mismatch-blocks |
| 15 | vacuous-pass | det_semantic_rebuild._load_whitelist | 去掉 CWD 回退；找不到白名单 → error（否则会把 defect 变 whitelisted） | rebuild-whitelist-missing-error |
| 16 | aggregate-order | gate.main / aggregate | head 比较失败或差异 → 非零；warnings 不再无条件声称 L1 accepts，改写为 L1 exited N / L1 was skipped | （337/340 head 全量运行验证） |

## 未修（1 条，附风险）

| # | 类别 | 位置 | 为什么跳过 | 风险 |
| ---: | --- | --- | --- | --- |
| 17 | definition-drift | det_semantic_rebuild.detect | 「文本相等当语义相等」：RIP 相对操作数长度变化时，同一文本可能指向不同目标。要真正消除需要重定位模型（把 rip+disp 归一为目标地址再比较），属于重写而非补丁 | 当前白名单外的 mismatch 会判 defect（偏严）；但若某条指令文本相同、位移却变，本单元看不出来。这类只有『字节回路』能发现，而字节回路 84.5% 的等价编码噪声不可用 |

## 仍存在的已知边界（不在审计项内，一并记录）

- common.ROUND_CACHE 仍按 item_dir 绝对路径缓存；验收过程中若目录被改写需重开进程。
- 顶层 key 与带前缀 key 的声明集比较只在同一轮次表之间做（跨轮次下降才发 advisory）。
- det_semantic_rebuild 的白名单是字面 pattern，不做正则推断；新增别名必须显式入库。
