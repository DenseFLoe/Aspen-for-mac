# preflight — 本地验收工装（内部 QA，不进交付分支）

两段结构：**L1 = 上游检查器原样调用（pin sha256，退出码权威）**；**L2 = 我们自己的检测器**
（`qa/det_*.py`，每个在 docstring 里声明 `l1_covers: yes|partial|no`）。

工装放在独立分支 `tietoumiao/preflight`，不进 `native-337-s33` / `native-340-s33` 交付分支。

## 取用

    python qa/sync.py                 # 取该分支最新 head
    python qa/sync.py --head <sha>    # 钉住某个 head

落到 `_tools/preflight/<head8>/`，并在同目录写 `MANIFEST.json`（每文件
`path/sha256/bytes` + `branch` + `head` + `generated_at`）。

版本引用写成：

    preflight <head8> (sha256 of MANIFEST = <manifest_sha256>)

## 运行

    # 判本地目录
    python -B qa/gate.py --task NATIVE-340 --item-dir handoff/inbox/NATIVE-340

    # 判某个 head（先把该 head 的 inbox 拉到缓存，再判）
    python -B qa/gate.py --task NATIVE-337 --head <sha>

    # 只核对「本地目录与该 head 的 git blob 是否逐件一致」
    python -B qa/gate.py --task NATIVE-337 --item-dir ... --against-head <sha>

    # 机器可读输出
    python -B qa/gate.py --task NATIVE-337 --item-dir ... --json /tmp/rep.json

退出码：`l1.exit != 0` 时取 L1；否则 `2` 表示 L2 有 defect；`0` 表示双方都无 defect。
结果里 `l1_authoritative: true` 恒为真。

## L1 pin

| 项 | 值 |
| --- | --- |
| 路径 | `out/localrepo3/handoff/assignments/check-native-coverage.py` |
| sha256 | `27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8` |

该 sha256 被上游 9 份复验文档引用（337 s61/s65/s69/s73/s77、340 s13/s37/s65/s69）。
逐轮 pin 历史见 `out/backtest/l1_pin.json`。**L1 不改、不绕过、不解释**。

## 检测器

| 模块 | 类别 | l1_covers |
| --- | --- | --- |
| det_omitted_sites | omitted-sites（原件 IAT 站点普查差集） | no |
| det_stale_metrics | stale-metrics | no |
| det_row_linkage | row-linkage | partial |
| det_fingerprint_pathset | fingerprint-pathset | no |
| det_unresolved_no_recovery | unresolved-no-recovery | no |
| det_symbol_substring | symbol-substring | partial |
| det_wrong_symbol | wrong-symbol | no |
| det_byte_mismatch | byte-mismatch | partial |
| det_access_flags | access-flags（ECMA-335 全表自检） | no |
| det_receipt_paths | receipt-misstatement | no |
| det_eh_clause | clause-semantics | no |
| det_eh_boundary | eh-boundary | no |
| det_truncated_hash | truncated-hash | no |
| det_access_prose（t13 碎片） | access-flags（散文映射） | no |

新增检测器 = 加一个 `tool/det_<name>.py` + 在 `qa/registry.py` 加一行；
只导出 `REGISTRY = {name: fn}` 的碎片模块也会被加载。

## 判据来源

检测器只读「pin 住的原件 + 候选目录」。不读上游裁定文本、不读 issue 评论、
不按样本 sha256 或轮次号分支。

## 回测

    python -B qa/backtest.py --blind <未参与调参的 item 目录>
    python -B qa/report.py

数据：`out/backtest/{dataset.csv,backtest.json,report.md,l1_pin.json}`。

## 扫描基线（必须整段引用，否则计数不可复算）

`det_semantic_rebuild` 的普查口径写死如下，并逐条落在 `stats` 里：

1. **节**：`Characteristics & 0x20000000`（`IMAGE_SCN_MEM_EXECUTE`）的所有节，不按名单挑。
2. **跨度**：`SizeOfRawData`（raw），**不用** `VirtualSize` 截断。例：`.nep` raw=0x800 / vsize=0x7A0，尾部仍可解码。
3. **解码器**：固定用本仓库 `.local/pylibs` 下 vendored 的 capstone（`stats.libs` 记录版本与路径）。
   两个同为 5.0.7 但不同来源的 capstone 会在个别 skipdata 边界相差 2 条记录（实测 .text：5,926 vs 5,928），
   所以构建来源必须入产物。
4. **skipdata**：开启；被跳过字节按 capstone 的每字节一条 data 记录计数，记入 `stats.sections[].data_bytes`，
   **不进** `inputs_checked`。
5. **容量**：`inputs_checked = total_instructions` = 实指令数（data 记录在 total 之外单独计）；`compared = ok + whitelisted` 是真正完成语义比对的部分；`entries_total = total_instructions + data_bytes`；`bytes_scanned` 是字节级覆盖。**不要用 total 减 data 这类减法推导任何口径**，那会把 data 重复扣一次。

参考读数（FindComponent / WrapSaveMergeNNFiles）：

| 节 | 337 instructions | 337 data | 340 instructions | 340 data |
| --- | ---: | ---: | ---: | ---: |
| .text | 6,083 | 0 | 5,450 | 478 |
| .nep | — | — | 585 | 0 |
| 合计 entries | 6,083 | | **6,513** | |
