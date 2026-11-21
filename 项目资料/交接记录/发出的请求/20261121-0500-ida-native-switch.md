---
task_id: 20261121-0500-T5N-ida-native.reply
type: result
sender: aspen-batch (ds4.1f, T5N worker)
reply_to: handoff/incoming/
in_reply_to: 20261121-0505-T5N-ida-native.plan.md
---

# native 链已换成 IDA 9.5 + Hex-Rays（19/19 重做并推送，22 commits）

用户指令「本机已安装 IDA9.5 headless，可以调用」之后，native 链（19 件 PE）不再是 Ghidra 产物：`.asm.txt` 与 `.c.txt` 已用 **IDA Professional 9.5 + Hex-Rays** 在同一路径覆盖重做，`.md` 补齐 `tool=IDA 9.5` / `hexrays=yes` / `functions=N` / `decomp_ok=N` / `decomp_fail=N` / `prevtool=Ghidra 12.1.4` 六个可检索字段，并新增 §9 与 Ghidra 的函数数对账。

## 1. 为什么换

| 项 | Ghidra 12.1.4（旧） | IDA 9.5 + Hex-Rays（新） |
| --- | --- | --- |
| 调用式 | `analyzeHeadless` + JVM + `ExportAll.java`，单件 40–47 s | `idat.exe -A -c -S<script> -L<log> <dll>`，单件 1.6–6.8 s |
| 依赖 | 需 JDK 21 + `JAVA_HOME`/`APPDATA` 三个 export | 只依赖本机安装与 `idapro.hexlic`（Hex-Rays 内置） |
| 伪 C | Ghidra decompiler | Hex-Rays（IDA 旗舰反编译器，本任务实测 `init_hexrays_plugin()` → True） |
| 函数命名 | 未命名一律 `FUN_<addr>` | 应用 FLIRT 库签名（`__CRT_INIT@12`、`@__security_check_cookie@4` 等） |

结论：同一批样本上 IDA 更快、伪 C 更可读、库函数识别更好，产物格式保持与旧版一致（`FUNC` / `// FUNC` / `// DECOMP-FAIL` 三段恒等式不变），因此**下游不需要改任何解析**。

## 2. G1–G6 逐条（命令 + 原始输出行）

- **G1 全部 IDA 产物**：`python tool/ida_export.py --manifest read-test-waiting.csv --source-root dl --out out/R1N` → `IDA-NATIVE files=19 funcs=1079 decomp_fail=0 asm_lines=24073`；`find out/R1N/01-completed -name '*.asm.txt'|wc -l` = 19、`*.c.txt` = 19；远端读回 `REMOTE-NATIVE-IDA ok=19/19`（首行 `# TOOL IDA 9.5` + asm/c 函数数一致 + c 首行 `// FUNC`）。
- **G2 md 字段**：19/19 含 `tool=IDA 9.5`、`hexrays=yes`、`functions=`、`decomp_ok=`、`decomp_fail=`、`prevtool=Ghidra 12.1.4`（脚本校验 `MD problems=0`）；本批 `decomp_fail` 全 0，故无需失败清单。
- **G3 与 Ghidra 对账**：`IDA-G3 over10pct=0`，最大偏差 7.7%（comcat.dll 26→24）；合计 **1067 → 1079（+12，+1.1%）**，逐件表见 §3。
- **G4 远端目录与索引**：`REMOTE-INDEX INDEX.md/index.csv/archive-ledger.csv` 表头分别含 `tool`/`prevtool` 列，native 行 19/19 = `IDA 9.5` / `Ghidra 12.1.4`。
- **G5 文件数不暴涨**：推送集仍 **175** 文件（58 件 ×(md+companion) + 4 索引台账 + 12 工具 + …）；`find out/R1N/01-completed -type f|wc -l` = 57；Ghidra 旧文本被同路径覆盖，只在历史 commit 里（`b5944f12` 及更早）。
- **G6 不碰 main、不传原件、不传库文件**：`main 865e2524…` push 前后一致；`find out/R3/upload -name '*.i64' -o -name '*.log' -o -name '*.dll'|wc -l` = 0；21 个 `.i64` 与全部 IDA 日志只落本机 `out/R1N/ida/{stage,logs,scripts}`；`dl/` 61 个原件零新增。

## 3. 推送

| 项 | 实测 |
| --- | --- |
| 分支 | `codex/20261120-batch-review`（**未碰 main**，未 force） |
| head | `57333265` → **`87fddcbf`**，22 commits，全部 message 含 `round=20261121 redo native with IDA 9.5` |
| 变化文件 | 63（19×3 native + INDEX.md/index.csv/archive-ledger.csv + tools/aspen_batch/assemble.py） |
| 字节审计 | `BYTES-MATCH checked=175 mismatch=0`；`tree_paths=883 base_blob=883`（无删除、无重排） |
| 门禁 | `GATE UPLOAD_OK files=175 findings=0` |
| 抽查读回 | comcat.dll 24 / userfort.dll 57 / userfort.dll 60，首行均 `# TOOL IDA 9.5` |

## 4. 需要你方知道的三个口径

1. **函数数不是逐位相等**：IDA 与 Ghidra 的函数粒度不同（导入跳板/thunk 合并、FLIRT 命名），合计 +1.1%、最大 7.7%，均 <10% 判据；每件 md §9 有逐件差值表与命名口径说明。
2. **`.md` §6 的日志路径是本仓库相对路径**（`out/R1N/ida/logs/…`），指向不进推送集的本机文件，读者按该路径取不到远端文件——这是有意为之（G6 要求日志不外发）。
3. **`tools/aspen_batch/assemble.py` 本次只加 `tool`/`prevtool` 两列**；`publish.py` 与 `tools.json` 曾因本机版本较新被一并推了一版，已在 `87fddcbf` 的最后一个 commit 里恢复为父提交内容（`files=2`），远端工具口径与 `57333265` 一致。

## 5. 未做 / 待验证

- 语义层（函数用途、调用约定、结构体）未做人工复核，只证明「全函数已反汇编/反编译落盘」。
- Hex-Rays 失败率 0/1079，未覆盖「反编译失败清单」路径的真实样本（脚本已实现 `DECOMP-FAIL` 逐条落 md §5.1，但本轮没有触发）。
- 未做动态验证（不运行样本）。
