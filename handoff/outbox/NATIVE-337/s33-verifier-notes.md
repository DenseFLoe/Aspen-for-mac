# 验收器 1.5 的二跳附表补充证据

沿用 s29 关于二跳附表漏检的记录。验收器源树 SHA-256 为 `4ec54c4d7a7b1b8fdc9b7462a6a0e982956be15d978d680d9a0bc03d1277e853`。 [s29 原记录](s29-verifier-notes.md) · [#441 合入版](https://github.com/DenseFLoe/Aspen-for-mac/tree/ff585268ac8983097b8a229e3d8e49abee61d7e1/tools/reverse_acceptance)

```text
python -B tools/reverse_acceptance/verify.py item --original ORIGINAL --sha256 3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02 --delivery CANDIDATE_ITEM_DIR
python -B handoff/outbox/NATIVE-337/check-s33.py ORIGINAL CANDIDATE_ITEM_DIR
```

原生覆盖 v1 要求可定位的转移逐址关联到实际目标和证据。验收器 1.5 对 #445 固定 head 仍给出 inconclusive，退出 2。与 #442 相比，各检查结果、指标、条目内容相同，只有交付路径清单与交付指纹不同。独立检查定位 #445 新附表的 17 个缺首跳、18 个缺 IAT 和最终符号，以及 `0x12da` 候选宿主错列。主表 161 个最终符号仍正确，因此仅比对主表无法发现这些证据缺口。 [#445 固定交付](https://github.com/DenseFLoe/Aspen-for-mac/tree/bd362e3f3493abdda0d5aa3171a25fae5f6f14c7/handoff/inbox/NATIVE-337) · [逐址复查](s33-recheck.json)

沿原建议逐行核对结构化二跳附表。用 #445 固定候选回归，预期 `0x44b3` 报首跳、IAT、符号三项缺失，`0x5c78` 仅报 IAT 和符号缺失，`0x12da` 根据候选清单报宿主错误。填回这些原件值后，相关三行应通过本项。保持门禁按站点核验，`0x4ac7` 被 39 个不同站点合法引用。

已在固定候选的独立副本复跑正控。`python -B handoff/outbox/NATIVE-337/make-s33-positive.py CANDIDATE CLEAN_OUTPUT` 生成对照，再对 `CLEAN_OUTPUT` 运行 `check-s33.py`，八项各为 161/161，退出 0。验收器 1.5 对该正控及固定 #445 均给出同一组检查结果并退出 2。原件的 112 条未决仍保留。

## 主干 1.6 复跑

主干 `49cd8ea339df68b5b08dfa49589a653d41d4e25e` 的验收器 Git 子树 `8152d65a20db6e9410ae66ce2ee8a58e894515c3`，入口 `verify.py` blob `b2168f535d2e337beb4b332720b58c436509e1d6`。沿同一条命令核对当前 #445 和正控，退出 2 且各项发现相同，旧附表漏检仍可复现。新 COM 检查的 64 条指向运行期模块，现场尚无目标模块证据，已核对的位移和成员继续成立。
