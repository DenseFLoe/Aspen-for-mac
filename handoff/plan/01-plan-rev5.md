---
task_id: 20261121-0145-PLAN-rev5
type: result
sender: aspen-batch (ds4.1f)
reply_to: handoff/incoming/
source_sha256: d90bf5d7b2ff1089b0e841d92e7c4b9dd66716166c6e6f2afefa98c3db3d9464
redaction: local workspace paths -> <workspace>, usernames -> <user>
---

# 01-plan — wf-20261120-aspen-batch（阶段 2 方案，rev5 / 判据 R1–R4 + D1–D5）

channel: subagent(provider=opencode-go, model=deepseek-v4.1-flash, reasoning_effort=max)
model=deepseek-v4.1-flash effort=max（Planner 本人；执行角色见 §3 = 同模型 / low）
- 被评审物：本文件 + `taskbooks/*.md`（阶段 4 产出）+ `skills-dispatch.md`（阶段 4 产出）；判据本体 `00-req.md` §7（R1–R4）+ §9（D1–D5）。
- 档位：L2 ⇒ 全八阶段；计划双审（critic_a 找茬 / critic_b 审查）。
- rev3 响应阶段 3 双 REPAIR（§11）；rev4 响应 Router 目标升级（一条命令/增量 + 完全反编译正文，§12）；**rev5 响应 r2 双 REPAIR（计划评审封顶轮，§13）**。
- **本轮范围 = R1（CLR 链 + 非 PE 处置）/ R1N（native 链）/ R2 / R3 / R4**；B3 的 58 件原件已到位（`_work/wf-20261120-aspen-batch/dl/`）。旧 scope（A1–A6）已作废，见 §10。

## 0. 一句话方案

在 `_work/wf-20261120-aspen-batch/` 下建**一条 Python 流水线**：`tool/batch_reverse.py`（CLR+非 PE 链：清单 → 逐件 IL 全清单 + ILSpy 全量 C# + `.md` + ledger）与 `tool/native_reverse.py`（native 链：Ghidra headless 全函数反汇编 + 反编译伪 C + `.md` + ledger）；`tool/run_batch.py --auto` 把**装配 → 门禁 → 逐件 commit 推送 → 读回**串成一条无需人工干预的命令，并**默认复用**两条链已产出的本地产物（缺产物才提示，或显式 `--force-analyze` 才重跑），用 `out/state.json` 做 sha256 增量；本机 git 不可用 ⇒ 全链路只走 `https://api.github.com`，token 只在 `publish.py` 进程内经 `_cred.py` 读入内存。

## 1. 目录与产物布局

### 1.1 工作树与写者（文件级不重叠）

```
_work/wf-20261120-aspen-batch/
  tool/batch_reverse.py          # T1   CLR+非PE 链入口（清单→产物→ledger-clr.csv）
  tool/il_dump.py                # T1   全程序集 IL 清单（每 MethodDef：令牌/RVA/偏移/操作码/解析操作数）
  tool/render_report.py          # T1   逐件 .md 渲染（唯一渲染点，§2 D6 脱敏 + D15 固定句）
  tool/lib/dnlib.py              # T1   从 _work/20261120-log4net-ghidra/scripts/dnlib.py 原样复制（只读源）
  tool/lib/iltab.py              # T1   同上（iltab.py）
  tool/config/profiles.json      # T1   产品映射（含 read-test 的 Plus→Aspen-Plus、Properties→Aspen-Properties）
  tool/config/tools.json         # T1   工具版本常量（dnfile/pefile/ILSpy/Ghidra/dotnet）
  tool/native_reverse.py         # T1N  native 链入口（Ghidra 调用 + 产物落位 + ledger-native.csv）
  tool/ghidra_scripts/ExportAll.java  # T1N 从零写：全函数反汇编 + 全函数反编译（契约见 §3.3）
  tool/check_repo.py             # T2   R2 仓库自检
  tool/check_upload.py           # T3   R4 上传门禁（产物齐全 + 大小 + 脱敏 + 原件哈希 + allowlist）
  tool/run_batch.py              # T4   总入口（--auto / --list-only / --plan-only / --since / --force-analyze）
  tool/assemble.py               # T4   合并两份 ledger + INDEX.md/index.csv + 暂存树 + upload-map.tsv + state 种子
  tool/publish.py                # T4   Git Data API（唯一持 token 的进程；blobs→trees→commits→refs）
  out/R1/**   out/R1N/**         # T1 / T1N
  out/R2/**   out/R4/**          # T2 / T3
  out/R3/**   out/state.json     # T4
  home/AppData/**                # T1N（Ghidra 的 APPDATA/LOCALAPPDATA 重定向，绕宿主沙箱）
```

- **入口自加 lib 路径（r2-a I2 / r2-b I7）**：`batch_reverse.py`、`render_report.py`、`il_dump.py` 顶部写死 `sys.path.insert(0, str(Path(__file__).resolve().parent / "lib"))`。本地 `tool/lib/{dnlib,iltab}.py` 能 import；上传到 `tools/aspen_batch/` 后该目录不存在也不影响（平铺同名文件在 `sys.path[0]`）。
- **单写者**：T1 只写 `out/R1`，T1N 只写 `out/R1N`，T2 只写 `out/R2`，T3 只写 `out/R4`，T4 只写 `out/R3` 与 `out/state.json`。
- **`--force-analyze` 的写入归属**：`run_batch.py` 默认**只读** `out/R1`/`out/R1N`；仅当显式传 `--force-analyze` 时，它才以 subprocess 调 T1/T1N 的 CLI 重跑，**写入仍落在 T1/T1N 的白名单**（串行、非并发），T4 自身不直接写这两个目录。该模式不在本轮验收判据里（T4 timebox 不含它）。
- **写 T3 门禁产物时的路径**：真实门禁在 T4 内跑，必须传 `--allowlist-out out/R3/upload-allowlist.json`（走 T4 自己的范围）；T3 自己的 self-test 才写 `out/R4/**`。⇒ 五份白名单保持静态两两不交（r2-b I4）。

### 1.2 产物布局

**T1（CLR + 非 PE）**——**规范运行根 `out/R1`（唯一交付根）**，另外两条判据用隔离子根：

```
out/R1/01-completed/<Product>/<DIR>/<NAME>.md                 # 逐件说明（§3.2 S0–S8）
out/R1/01-completed/<Product>/<DIR>/il/<NAME>.il.txt          # 全程序集 IL 清单
out/R1/01-completed/<Product>/<DIR>/decompiled/<NAME>.cs.txt  # ILSpy 9.1.0 全程序集 C#（stdout 落盘）
out/R1/02-incomplete/<Product>/<DIR>/<NAME>.md                # missing/hash_mismatch/failed_analyze/unsupported_non_pe
out/R1/__raw/<safe_key>/{inventory.json,il.json,resources.json,pinvoke.csv}
out/R1/ledger-clr.csv   out/R1/_run.json   out/R1/_tmp/
out/R1/runs/regression/**                                     # 判据①的隔离根（--out 指这里）
out/R1/runs/counts/**                                         # 判据③的隔离根（--out 指这里）
```

**T1N（native）**——规范根 `out/R1N`，冒烟用隔离子根：

```
out/R1N/01-completed/<Product>/<DIR>/disasm/<NAME>.asm.txt    # Ghidra listing，逐函数块
out/R1N/01-completed/<Product>/<DIR>/decompiled/<NAME>.c.txt  # Ghidra Decompiler 伪 C，逐函数
out/R1N/01-completed/<Product>/<DIR>/<NAME>.md
out/R1N/02-incomplete/<Product>/<DIR>/<NAME>.md
out/R1N/__raw/<safe_key>/{import.log,disasm.txt,pseudo.c.txt}
out/R1N/ledger-native.csv   out/R1N/_run.json   out/R1N/stage/   out/R1N/ghidra-proj/
out/R1N/runs/smoke/**                                         # 判据①的隔离根
```

**T4 暂存树（`out/R3/upload/` = 仓库目标路径镜像；M1 的「上传暂存」归属）**

```
out/R3/upload/tools/aspen_batch/{run_batch,assemble,publish,check_upload,batch_reverse,il_dump,render_report,native_reverse,dnlib,iltab}.py
out/R3/upload/tools/aspen_batch/{profiles.json,tools.json}
out/R3/upload/tools/aspen_batch/ghidra_scripts/ExportAll.java
out/R3/upload/analysis/20261120-batch-driver/README.md
out/R3/upload/analysis/20261120-batch-driver/INDEX.md
out/R3/upload/analysis/20261120-batch-driver/index.csv
out/R3/upload/analysis/20261120-batch-driver/archive-ledger.csv
out/R3/upload/analysis/20261120-batch-driver/<Product>/<DIR>/<NAME>.md
out/R3/upload/analysis/20261120-batch-driver/<Product>/<DIR>/{il,disasm,decompiled}/<NAME>.{il.txt,asm.txt,cs.txt,c.txt}
out/R3/upload-map.tsv          # repo_path 制表符 local_path 制表符 sha256 制表符 bytes（175 行）
out/R3/upload-allowlist.json   # T3 产出（--allowlist-out 指这里），T4 publish 当白名单
out/R3/receipt.json            # 推送回执
out/R3/fixtures/**             # T4 的 PLAN/替换夹具（不推送）
```

- **`<Product>`（统一口径，r2-a I12）**：一律 `Aspen-Properties` / `Aspen-Plus` / `shared`。schema A 按 `owner` 映射；schema B 取 `path` 第 2 段再映射（`Plus`→`Aspen-Plus`、`Properties`→`Aspen-Properties`）。ledger 另存 `product_raw` 保留原值。
- **`<DIR>/<NAME>`** = `relative_path` 的 dirname/basename，**原样保留方括号与空格**（如 `[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/...`）；只断言不含 `:`（D11）。
- **暂存树把 status 目录摊平**：`01-completed` 与 `02-incomplete` 的 `.md` 统一落到 `analysis/20261120-batch-driver/<Product>/<DIR>/<NAME>.md`，状态只记在 `INDEX.md`/`index.csv`/`archive-ledger.csv`。
- **`safe_key`** = `analysis_key` 的安全投影（D11：`sha256_<64hex>`，无冒号）。
- **>5 MB 自动 gzip（r2-b I10）**：T1/T1N 写盘前判断明文大小，>5 MB 则 `gzip -9` 存 `<NAME>.<ext>.txt.gz`（不写明文），并在该件 `.md` 写 `解压：gzip -d <偏文件名>`；T3 allowlist 接受 `*.txt.gz`；本轮 58 件最大 0.02 MB ⇒ 期望 `gz=0`。

### 1.3 `archive-ledger.csv` 字段（T4 合并后交付）

| 列 | 含义 | 判据 |
| --- | --- | --- |
| `analysis_key` | 原始去重键（`sha256:<64hex>`） | 全表唯一；允许含冒号（只作数据） |
| `analysis_key_safe` | 投影键 `sha256_<64hex>`（D11） | 唯一；`^sha256_[0-9a-f]{64}$`；不含 `:` |
| `sha256` / `size_bytes` | 清单声明值 | 与清单一致 |
| `kind` / `chain` | `CLR`/`native`/`not-PE`；`T1`/`T1N` | 与 D3 路由表一致 |
| `relative_path` / `member` / `product` / `product_raw` | 原相对路径 / 原全名 / 统一产品目录 / 原始产品名 | 无盘符、无绝对路径 |
| `first_seen_manifest` | `properties`/`shared`/`plus`/`read-test` | 属于四值之一 |
| `owner` / `product_source` | 选行行的 `owner` / 产品来源（`owner` 或 `path-seg2`） | 非空 |
| `status` | `processed`/`unsupported_non_pe`/`missing`/`hash_mismatch`/`failed_analyze` | 每候选恰好一行 |
| `reason` | 非 processed 的原因（`source file not found`/`sha mismatch: actual <64hex>`/`zero_bytes`/`PEFormatError: …`） | 非空 |
| `archive_dir` / `report_md` | 归档目录 / 报告落点（相对 `out`） | **`report_md` 去重数 == 数据行数** |
| `product_sha256` | 该件全部产物的 `name=sha256;` 升序拼接后的 sha256 | 重算一致（PLAN 的 stale 判定依据） |
| `methoddef_total` / `pinvoke_count` / `func_count` | CLR 元数据计数 / native 函数数；未分析留空 | 与 `_raw/` 一致 |

- 编码 UTF-8 无 BOM、`lineterminator='\n'`、按 `analysis_key` 升序。
- 行数判据拆两条：**properties 单清单 `rows=754`**；**三清单并集 `rows=1397`**。

### 1.4 `status` → 目录映射

| status | 目录 | 说明 |
| --- | --- | --- |
| `processed` | `01-completed/<Product>/<DIR>/` | 产物齐全（CLR：md+il+cs；native：md+asm+c） |
| `unsupported_non_pe` | `02-incomplete/<Product>/<DIR>/` | 非 PE（.obj/.lib）：md 内写已试工具 + 原始报错，**不伪造产物** |
| `missing` / `hash_mismatch` / `failed_analyze` | `02-incomplete/<Product>/<DIR>/` | 缺件/哈希不符/分析异常 |

### 1.5 README / INDEX.md / index.csv 结构（r2-b I8）

- **`README.md` 固定 7 个二级标题**：`## 0. 这是什么`、`## 1. 一条命令怎么跑`、`## 2. 产物与边界（只推 codex 分支、不传原件）`、`## 3. B3 缺口与台账`、`## 4. native 链状态`、`## 5. AGENTS 偏离授权`、`## 6. 复现环境`。`grep -c '^## '` = 7。
- **`INDEX.md`**：首行 `# 20261120 批次索引`，随后表头 `| 类型 | 产品 | 名称 | 状态 | 产物 | 字节 |`，再 58 行数据，每行首格为 `CLR`/`native`/`nonPE`。断言：CLR 行 31、native 行 19、nonPE 行 8。
- **`index.csv`** 表头（9 列）：`name,product,relative_path,sha256,kind,status,products,bytes,report_md`；58 行数据 + 1 行表头 ⇒ `wc -l` = 59。


## 2. 关键设计决策（每条都是执行者容易猜错的地方，所以写死）

- **D1 凭据纪律（CRITICAL）**：token **只**由 `tool/publish.py` 在进程内读：`p = subprocess.run([sys.executable, str(CRED)], capture_output=True, text=False, timeout=20)` → `token = p.stdout.decode("utf-8").strip()`（`CRED` = `_work/wf-20261120-aspen-batch/_cred.py`；该脚本把 token 写到 stdout）。**禁止**：argv/env/文件/日志/stdout 传 token；`print(token)`；把 headers 打进异常。所有 HTTP 异常只带 `status`+`url`；顶层 `except` 只打 `ERROR <ExcClass> token_len=<n>`。推送前后各跑一次日志扫描（正则 `gho_[A-Za-z0-9]{20,}|github_pat_[A-Za-z0-9_]{20,}|Bearer [A-Za-z0-9]{10,}`），命中 ⇒ 立即停手、不推送、exit 1。
- **D2 只走 API，禁用 git**：本机 git 的 schannel TLS 不可用（`SEC_E_NO_CREDENTIALS`）。读 `GET https://api.github.com/repos/DenseFLoe/Aspen-for-mac/...`，写 Git Data API；**不得**调用 `git` 子命令、不得写 `~/.git-credentials`、不得改全局 git 配置。
- **D3 输入抽象 + kind 路由 + 校验表（fail-closed）**：CLI = `--manifest <csv>`（可重复）、`--source-root <dir>`、`--path-map "<清单前缀>=<本机根>"`（可重复）、`--out <dir>`、`--only <sha256|analysis_key>`（可重复）、`--product <映射文件>`。
  - **两种 schema（按表头识别）**：A `needs-reverse` 必需列 `analysis_key,relative_path,original_path,member,size_bytes,sha256,owner,format`（`utf-8-sig`，首列带 BOM）；B `read-test` 必需列 `path,size,sha256,git_blob,kind,machine,sections,entry,com_rva,local`（`utf-8` 无 BOM、CRLF）。
  - **kind → 链路由表（r2-a I5 / r2-b I13）**：`kind=CLR` → T1；`kind=not-PE` → T1（`unsupported_non_pe`）；`kind=native` → T1N。schema A 无 `kind` 列 ⇒ 由 `format`/探针判定（PE 且 CLR 表非空 ⇒ CLR；PE 无 CLR 表 ⇒ native；非 PE ⇒ not-PE）。**每条链只处理自己路由的件**：T1 ledger 39 行（31 CLR + 8 not-PE）、T1N ledger 19 行，**两者之和 = 58**。`_run.json` 记 `filtered=19`（T1）/ `filtered=39`（T1N）。
  - **定位（r2-b I15 修正）**：schema B 先试 **`<清单所在目录>/<local>`**（`local` 已含 `dl/` 前缀）；再试 `<source-root>/<basename(local)>`；schema A 先试 `<source-root>/<relative_path>`；都失败 ⇒ 在 `--source-root` 下按 `sha256` 扫（限 5,000 文件 / 深度 8）；仍失败 ⇒ `missing`。命中规则写进 `_run.json` 的 `locate=<rule>`。
  - **输入校验表**：

    | 情形 | 行为 | 退出码 |
    | --- | --- | --- |
    | 清单不存在/空文件/0 数据行 | `INPUT FAIL reason=empty_manifest rows=0` | 2 |
    | 缺必需列 | `INPUT FAIL reason=missing_columns cols=<...>` | 2 |
    | 表头不被 A/B 识别 | `INPUT FAIL reason=unsupported_schema missing=<...>` | 2 |
    | 同 sha256 重复行（跨或同清单） | 去重为 1 行，`duplicates_collapsed+=1` | 0 |
    | 0 字节文件 | `status=failed_analyze reason=zero_bytes`，继续 | 0 |
    | 扩展名大小写（`.DLL`） | `lower()` 判定，档案名保留原名 | 0 |
    | `--source-root` 不存在 | `INPUT FAIL reason=source_root_missing` | 2 |
    | `--path-map` 前缀未命中 | `INPUT FAIL reason=pathmap_unmatched arg=<...>` | 2 |

- **D4 上传集 = 产物集（绝不传原件）**：175 个文件 = 58 份 `<NAME>.md` + 31 `il/*.il.txt` + 31 `decompiled/*.cs.txt` + 19 `disasm/*.asm.txt` + 19 `decompiled/*.c.txt` + 4 索引/台账/README + 13 工具文件。**不上传**：任何原版二进制、`_raw/`、`repo.tar.gz`、`_cred.py`、`gh.py`、`git-auth.sh`、`err.tmp`、`tok.tmp`、`*.pyc`、`out/state.json`（本地状态；异地增量用 `--since`）。
- **D5 R3 前置门禁（双闸 + allowlist 绑定）**：`run_batch.py --auto` 内**先**跑 `check_upload.py --allowlist-out out/R3/upload-allowlist.json`（`UPLOAD_OK` 才继续），再跑 `publish.py`；`publish` 以该 JSON 为**白名单**，逐文件比对本地 sha256 与暂存树，`pushed_blobs == audited_blobs`，暂存树多一个文件 ⇒ exit 3。`--list-only` 不读 token、不发任何写请求。
- **D6 脱敏在生成阶段**：`render_report.py` 只接受相对路径与常量；写盘前过 `assert_no_leak()`：`[A-Za-z]:\\`、`Users\\\\`、`<workspace>`、`<user>`、`gho_`、`github_pat_`、`Authorization`。命中即抛错不写。`check_upload.py` 的 grep 是第二道防线。
- **D7 三档标注**：〔实测〕只给本 run 真跑的数字；〔引用第58轮〕只在显式 `--baseline` 时出现；其余〔待验证〕+ 一行"缺什么才能判"。
- **D8 仓库自检必须在副本里跑**：`tests/test_formula_extraction.py` 会以 cwd 为临时根建受 ACL 保护的 `tmp*` 目录且删不掉（`WinError 5`）。⇒ T2 必须 `cp -r Aspen-for-mac-main out/R2/worktree` 后在副本里跑，`TMPDIR/TEMP/TMP` 指到 `out/R2/_tmp`；克隆本体零改动。**快照排除 `out/R2/worktree`、`out/R2/_tmp`**。
- **D9 幂等降级为"可 diff"**：不要求字节幂等；报告不得含 wall-clock 时间/耗时/绝对路径，`--now` 可固定时间字段。
- **D10 一条命令 / 复用 / 状态 / 增量 / 无人值守（CRITICAL 修复点，r2 双 I1）**：
  - 入口：`python tool/run_batch.py --auto --manifest read-test-waiting.csv --source-root dl`（可选 `--since <40hex>`、`--list-only`、`--plan-only`、`--only <sha256>`、`--state out/state.json`、`--force-analyze`）。
  - **复用语义（默认）**：`PLAN` 对每件先查 ① state 里是否已推送且 sha 未变 ② 本地产物是否齐全且 `product_sha256` 重算一致。②成立 ⇒ **不重跑分析**，只用既有产物做 assemble/gate/push（`reused` 计数）。②不成立且 ①不成立 ⇒ 记 `stale`/缺产物，打印 `ANALYZE-MISSING n=<k> items=<name…>`：`--plan-only`/`--list-only` 照常出计划；真 `--auto` 在缺 `--force-analyze` 时 **exit 2**（提示先跑 T1/T1N），**绝不静默空跑**。⇒ T4 的 45 min 只覆盖装配+门禁+推送。
  - 顺序（固定）：`PLAN` → [仅在 `--force-analyze` 时：调 `batch_reverse.py` → `native_reverse.py`] → `assemble` → `check_upload` → `publish` → 写 `state` → 打印 `BATCH …`。
  - `out/state.json`：`{"round":"20261120","branch":"codex/20261120-batch-review","last_commit":"<40hex>|null","items":{"<analysis_key>":{"sha256":…,"kind":…,"status":…,"product_sha256":…,"pushed":{"commit":"…"},"superseded_by":"<key>|null"}}}`。
  - **增量规则**：① 新键 ⇒ 分析（或复用）+ 推送；② 键在 state 且 `pushed.commit` 非空且 sha 未变 ⇒ 跳过（不重分析、不重推）；③ 键在 state 但产物缺失/摘要变 ⇒ `stale`，重做并再推；④ 同 `relative_path` 换 sha ⇒ 新键当新件，旧键标 `superseded_by=<新键>` 并保留历史；⑤ `--since <sha>`（无状态模式）：读 `GET /git/trees/<sha>?recursive=1`（只收 `type=="blob"`），树里已有报告路径视为已处理。
  - **无人值守**：任一件异常只把该件记 `status=failed_analyze reason=<异常类名: 消息前 200 字符>`，继续下一件。
  - **末行（固定字段 + 恒等式）**：`BATCH done=<n> analyzed=<n> unsupported=<n> skipped=<n> failed=<n> reused=<n> analyzed_now=<n> pushed=<件数> blobs=<文件数> commits=<n> tree_paths=<n> base_blob=<n> branch=<…> head=<40hex|none> main_before=<…> main_after=<…> main_unchanged=OK|FAIL`。恒等式：`analyzed + unsupported + skipped + failed == done == 参与件数`；`reused + analyzed_now == done - skipped`；`blobs == 本轮推送的文件数`、`pushed == 本轮有产物被推的件数`、`tree_paths == base_blob + 树内累计产品文件数`。退出码：0 全成功；1 有失败/门禁失败/断言失败/未分类异常；2 输入不可执行/环境缺失/缺产物且未给 `--force-analyze`；3 推送集 ≠ 审计集。
- **D11 分析键安全投影（CRITICAL，r2-b I2 修正范围）**：`analysis_key = "sha256:<64hex>"` **不得**直接拼路径。⇒ 投影 `analysis_key_safe = "sha256_" + <64hex>`；**只有键派生路径**（`__raw/<safe_key>/`、以及需要由键派生的文件 stem）过 `[^A-Za-z0-9._-] → "_"` 并断言不含 `:`。**`<Product>/<DIR>/<NAME>` 原样保留**（含 `[ ]`、空格、`!`，如 `.../Lignocellulosic biomass to ethanol.apwz!/BFDYLD.dll`），只断言整条路径不含 `:`。对本轮 58 件，DIR 含方括号/空格的件数 56/58；清洗它们会直接违反 AGENTS"保留原相对路径"与 §3.1 的期望落点。
- **D12 同键多行选行 + 落点消歧**：优先级 `properties > shared > plus`，同清单取文件内首行；`owner`/`relative_path`/`member`/`product` 取该行；`first_seen_manifest` 记来源。实测：1397 键中 1303 键多 `relative_path`、684 键 `owner` 冲突；`first_seen properties=754 / shared=0 / plus=643`，产品 `Aspen-Properties=750 / Aspen-Plus=643 / shared=4`。**落点** `<Product>/<dirname(relative_path)>/<basename(relative_path)>.md`；先全量建 plan 统计同落点桶，桶内 >1 ⇒ 桶内所有键改用 `<NAME>__<key8>.md`（key8=sha256 前 8 hex，仍冲突则 12/16；顺序无关）。实测 `targets=1394 / 冲突桶=3 / 消歧键=6`；断言 `report_md 去重数 == 数据行数`。
- **D13 Git Data API 精确算法（CRITICAL）**——**逐步照抄**：
  1. `GET /git/ref/heads/main` → `main_before = .object.sha`。
  2. `GET /git/commits/<main_before>` → `main_tree = .tree.sha`。
  3. `GET /git/ref/heads/codex/20261120-batch-review`：**404** ⇒ `parent=main_before`、`cur_tree=main_tree`；**200** ⇒ `parent=.object.sha`、`cur_tree=GET /git/commits/<parent> 的 .tree.sha`。
  4. `GET /git/trees/<cur_tree>?recursive=1` → 只收 `".type" == "blob"` 的条目为 `pre_paths`（**丢弃 `type=="tree"` 的目录条目**，r2-b I11）；断言 `truncated == false`；打印 `base_blob=<len(pre_paths)>`（克隆侧实测 685；≠685 记差异，不中止）。
  5. 每个待推文件：`POST /git/blobs {"content": <base64>, "encoding": "base64"}` → `blob_sha`；若 `pre_paths` 已有同路径且 blob 相同 ⇒ 跳过（`skipped_existing+=1`）。
  6. 按**件**分组（58 件 + `INDEX` + `tools` = 60 组）：`POST /git/trees {"base_tree": cur_tree, "tree": [{"path":…,"mode":"100644","type":"blob","sha":…} × k]}` → `cur_tree`；`POST /git/commits {"message": "round=20261120 item=<NAME> kind=<CLR|native|nonPE|meta|tool> files=<k>", "tree": cur_tree, "parents": [cur_commit]}` → `cur_commit`（首组 `parents=[parent]`）。
  7. refs 只两种：首建 `POST /git/refs {"ref":"refs/heads/codex/20261120-batch-review","sha":cur_commit}`；已存在 `PATCH /git/refs/heads/codex/20261120-batch-review {"sha":cur_commit,"force":false}`；**422 不可 fast-forward ⇒ exit 1，绝不 force**。
  8. 读回：`GET /git/ref/heads/<branch>` 的 `object.sha == cur_commit`；`GET /git/trees/<cur_tree>?recursive=1`（只收 blob，`truncated==false`）⇒ `pre_paths ⊆ new_paths` 且 `len(new_paths) == len(pre_paths) + 新增文件数`；`GET /git/ref/heads/main` 的 `object.sha == main_before`；抽 5 个文件 `GET /contents/<path>?ref=<branch>` 解 base64 后本地 sha256 一致。
  9. **硬禁止**：任何写 `refs/heads/main` 的请求、任何 `force: true`、任何 `DELETE /git/refs/**`；`publish.py` 运行时断言（URL 含 `/git/refs/heads/main` 且 method 属于 {POST,PATCH,DELETE} ⇒ 抛错）。
- **D14 工具与环境常量（实测；任务书原样带）**：`WS=<workspace>`；`GHIDRA=$WS/tools/ghidra/ghidra_12.1.4_PUBLIC`；`JAVA_HOME=$WS/tools/jdk/jdk-21.0.12.1+1`（无 `java_home.save`，必须显式 export）；`APPDATA=$WS/_work/wf-20261120-aspen-batch/home/AppData/Roaming`、`LOCALAPPDATA=$WS/_work/wf-20261120-aspen-batch/home/AppData/Local`；`DOTNET=<program-files>/dotnet/dotnet.exe`；`ILSPY=$WS/_work/20261120-log4net-ghidra/tools/ilspy/tools/net8.0/any/ilspycmd.dll`（9.1.0.7988）；`PYTHONPATH=$WS/_work/20261120-log4net-ghidra/.pylib`（dnfile 0.18.0 / pefile 2024.8.26）。
  - **ILSpy 跑法（r2-a I3 / r2-b I6 修正）**：`“$DOTNET” “$ILSPY” <dll> > decompiled/<NAME>.cs.txt`（**stdout 捕获落单文件**）；**禁用 `-o`/`-p`**（`-o` 是目录/工程形态，会产多文件）。判据：每件恰好 1 个 `.cs.txt`、`wc -l`>0、`grep -c 'class '`≥1。
  - **Ghidra 跑法（a-I14）**：统一用 `bash "$GHIDRA/support/analyzeHeadless"`（本机 log4net 链实测可用，`ghidra_import.log` 有 `Headless startup complete`）；若宿主 cmd 下失败，退化 `cmd //c "$GHIDRA\\support\\analyzeHeadless.bat"`。加 `-analysisTimeoutPerFile 600`。
- **D15 AGENTS 偏离授权（00-req §9.1）**：仓库 `AGENTS.md` 禁止上传「完整逆向正文」；用户 2026-11-20 明确要求上传汇编与伪代码 ⇒ 按用户指令执行，但：① 只推 `codex/20261120-batch-review`，不合并 main、不改默认分支；② **每份 `.md` 的 `## 0. 摘要` 末行写固定句** `含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条`（模板见 §3.2）；③ `receipt.json` 单列 `agents_deviation` 供人复核。断言：`find <staging>/analysis -name '*.md' -exec grep -L '偏离仓库 AGENTS' {} +` 无输出（58/58 命中）。
- **D16 体积与提交（00-req §9.2）**：单文件 ≤5 MB 明文（超出 gzip，见 §1.2 写者规则）；**逐件 commit**，message 带 `round=20261120`、件名、产物类型、`files=<k>`；索引 `INDEX.md`+`index.csv`；产物内不得出现本机绝对路径/用户名/凭据。
- **D17 Windows 路径长度（r2-b I14）**：实测相对路径最长 220（native `BFDYLD.dll` 的 `.apwz!` 目录），加上工作区前缀后绝对路径最长 285 > 260 ⇒ T1N 冒烟**必须挑这件**（`--only 0ea4a856…`）先跑；若 JVM 侧写失败，统一给输出路径加 `\\?\` 前缀，或把 `out/` 根改到短路径（如 `<short-root>/`）并在回执记 `LONGPATH fallback=<方式>`。


## 3. 任务表（每行 = 一份任务书；编号 = 判据号；执行顺序见 §4）

| task_id | 目标（判据） | 写入白名单 | 判据（命令 + 期望输出行） | 依赖 | skills[] | 为什么是这几条 | model/effort | channel |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| **T1 / R1-CLR** | CLR 链：31 件全程序集 IL 清单 + ILSpy 全量 C# + 逐件 `.md`；非 PE 8 件 `unsupported_non_pe`；出 `ledger-clr.csv`（39 行） | `tool/batch_reverse.py`、`tool/il_dump.py`、`tool/render_report.py`、`tool/lib/dnlib.py`、`tool/lib/iltab.py`、`tool/config/profiles.json`、`tool/config/tools.json`、`out/R1/**` | ①**log4net 回归**（§3.1，`--out out/R1/runs/regression`）；②**全量**（`--out out/R1`）：`python tool/batch_reverse.py --manifest read-test-waiting.csv --source-root dl --out out/R1` ⇒ `LEDGER rows=39 processed=31 unsupported_non_pe=8 missing=0 failed_analyze=0 filtered=19`；`find out/R1/01-completed -path '*/il/*.il.txt'` 计 31、`*/decompiled/*.cs.txt` 计 31 且逐个 `wc -l` 大于 0；`find out/R1/01-completed -path '*/il/*.il.txt' -exec grep -L '^MD ' {} +` 无输出、对 `*/decompiled/*.cs.txt` 跑 `grep -L 'class '` 无输出；`find out/R1/02-incomplete -name '*.md'` 计 8 且 `-exec grep -L 'unsupported_non_pe' {} +` 无输出；`find out/R1 -name '*:*'` 计 0；每份 `.md` 命中固定句 `偏离仓库 AGENTS`；③**清单口径**（`--out out/R1/runs/counts`，`--source-root out/R1/fixtures/empty`）：properties 单清单 `--manifest .../properties/01-needs-reverse/files.csv` ⇒ `LEDGER rows=754 processed=0 missing=754`；三清单并集（properties+shared+plus）⇒ `LEDGER rows=1397 processed=0 missing=1397` + `FIRST_SEEN properties=754 shared=0 plus=643` + `TARGETS rows=1397 unique=1394 collisions=3 disambiguated=6`；④**fixture 六例**（missing / hash_mismatch / zero_bytes / 重复键 / 空清单 exit 2 / `--path-map` 未命中 exit 2） | — | `reverse-engineering`、`execution-discipline` | 前者给观测/推断/未知分层与 PE-CLR 取证口径；后者 §1/§3 给长命令与输出规模纪律 | deepseek-v4.1-flash / low | subagent provider=opencode-go model=deepseek-v4.1-flash reasoning_effort=low |
| **T1N / R1-NATIVE** | native 链：19 件 Ghidra 全函数反汇编 + 全函数伪 C + 逐件 `.md`；出 `ledger-native.csv`（19 行） | `tool/native_reverse.py`、`tool/ghidra_scripts/ExportAll.java`、`out/R1N/**`、`home/AppData/**` | ①**单件冒烟（同时是长路径件）**：`python tool/native_reverse.py --manifest read-test-waiting.csv --source-root dl --out out/R1N/runs/smoke --only 0ea4a856d763ae6201c5848cfed812583041ef1d711c271d8fb1c22a679ab6c2` ⇒ `NATIVE files=1 funcs=<n> decomp_fail=<m> asm_lines=<k>`（n≥1），`grep -c '^FUNC '`大于 0；②**全量**（`--out out/R1N`）：同命令去掉 `--only` ⇒ `LEDGER rows=19 processed=19 failed_analyze=0 filtered=39` + `FUNC-MATCH files=19 ok=19 fails=<m>`；`find out/R1N/01-completed -path '*/disasm/*.asm.txt' -exec grep -L '^FUNC ' {} +` 无输出、对 `*/decompiled/*.c.txt` 跑 `grep -L '^// FUNC '` 与 `'^// DECOMP-FAIL '` 的组合无输出（每件 `FUNC == //FUNC + //DECOMP-FAIL`）；③原件哈希/大小与清单一致、产物无绝对路径；④**契约见 §3.3** | —（与 T1 同波，仅共用 §1.2 目录约定，不 import 其代码） | `reverse-engineering`、`execution-discipline` | 前者 §2/§4 给原生反汇编取证口径；后者给 headless 长跑纪律 | deepseek-v4.1-flash / low | 同上 |
| **T2 / R2** | 仓库自检：verifier + 离线 tests + 清单计数对账，产差异清单 | `tool/check_repo.py`、`out/R2/**` | `python tool/check_repo.py --repo Aspen-for-mac-main --out out/R2` ⇒ `REPO_CHECK verifier=PASS files_verified=18`、`TESTS ran=54 errors=<n>`、`COUNTS props=1866 plus=3791 shared=2534 union_keys=1397`；`ran==0` ⇒ exit 2 + `TESTS cannot-judge`；**`errors=<n>` 必须等于 `grep -c '^ERR ' out/R2/05-repo-check.md`**；每条差异带 `CMD:` 原文 + `CLASS: env/real`；`WORKTREE residue=<n>` | — | `supervision-gates`、`execution-discipline` | 前者 §1「PASS=0/空绿不是通过」；后者输出规模纪律 | deepseek-v4.1-flash / low | 同上 |
| **T3 / R4** | 门禁工具本体：产物齐全（D1–D3）+ 路径/扩展名/大小 + 脱敏 + 原件哈希 + 固定句 + allowlist（**只验自建夹具**，不依赖 T4） | `tool/check_upload.py`、`out/R4/**` | ①`python tool/check_upload.py --build-fixtures out/R4/fixtures/staging --out out/R4` ⇒ `FIXTURE files=13`；②`python tool/check_upload.py --staging out/R4/fixtures/staging --ledger out/R4/fixtures/staging/analysis/20261120-batch-driver/archive-ledger.csv --origins out/R4/fixtures/origins.csv --allowlist-out out/R4/fixtures/allowlist.json --out out/R4` ⇒ `GATE UPLOAD_OK files=13 findings=0 products clr=1 native=1 nonpe=1`；③`--self-test` ⇒ `SELFTEST cases=8 passed=8`（.dll/.exe/.db/6 MB 超限/`_cred.py`/`*.cs`/绝对路径内容/原件哈希 各 ⇒ findings=1 且 exit 1）；④夹具含 1 个 `*.txt.gz` 且被接受；**真实 175 件门禁断言在 T4 判据①**（r2-b I3） | — | `supervision-gates`、`code-review` | 前者给门禁判据；后者两轴审阅 | deepseek-v4.1-flash / low | 同上 |
| **T4 / R3** | 装配 + 一条命令（复用）+ 增量/替换 + 逐件 commit 推送 + 读回；不碰 main | `tool/run_batch.py`、`tool/assemble.py`、`tool/publish.py`、`out/R3/**`、`out/state.json` | ①`--list-only`：`GATE UPLOAD_OK files=175 bytes=<n> findings=0 products clr=31 native=19 nonpe=8` + stdout 里 `grep -c '^MAP '`=175 + `DRYRUN files=175 bytes=<n> lines=175 bundle=OK no_write=OK`（`bundle=OK` = 从 staging 目录跑 `run_batch.py --plan-only` exit 0，r2-a I2）；②`--auto` ⇒ `BATCH done=58 analyzed=50 unsupported=8 skipped=0 failed=0 reused=58 analyzed_now=0 pushed=58 blobs=175 commits=60 tree_paths=860 base_blob=685 … main_unchanged=OK`；③重跑 ⇒ `BATCH done=58 analyzed=0 unsupported=0 skipped=58 failed=0 reused=0 analyzed_now=0 pushed=0 blobs=0 commits=0 tree_paths=860 base_blob=685 … head=<同>`；④`--since <上次 head>` ⇒ 同 ③；⑤fixtures（§3.4）⇒ `PLAN new=0 skip=58 replaced=0 stale=0` / `PLAN new=58 skip=0 replaced=0` / `PLAN new=1 skip=57 replaced=1` + `SUPERSEDE old=<key> new=<key>`；⑥`receipt.json`：60 条 commit message 全含 `round=20261120` 与 `files=`，`agents_deviation` 非空，`readback.index_rows=58 readback.clr=31 readback.native=19 readback.nonpe=8 readback.csv_rows=59 readback.readme_sections=7` | T1、T1N、T3（`UPLOAD_OK` 硬门禁） | `github-publish-without-git`、`pr`、`network-firewall-policy` | 前者只取 §3 的 blobs/tree/commit/refs 与 `base_tree`（禁其 pwsh 包装与 main 上的 PATCH）；`pr` 给分支说明正文；`network-firewall-policy` §1 给联网/重试纪律 | deepseek-v4.1-flash / low | 同上 |

### 3.1 T1 判据①：log4net 回归（先在基线上自测，再判产物）

```
cd _work/wf-20261120-aspen-batch
mkdir -p out/R1/fixtures
python -c "import csv;rows=[r for r in csv.DictReader(open('Aspen-for-mac-main/inventories/2026-11-19/properties/01-needs-reverse/files.csv',encoding='utf-8-sig')) if r['relative_path'].lower().endswith('/log4net.dll')];w=csv.DictWriter(open('out/R1/fixtures/log4net-one.csv','w',encoding='utf-8',newline=''),fieldnames=rows[0].keys());w.writeheader();w.writerows(rows)"
python tool/batch_reverse.py --manifest out/R1/fixtures/log4net-one.csv --source-root ../20261120-log4net-ghidra/samples --out out/R1/runs/regression --only 2af48761d784d3c3b44eb0cf592e96aa2fee7dbc570c62e05db147198ff8f86c
```

期望：`LOCATE rule=hash-scan`、`LEDGER rows=1 processed=1 missing=0`；报告 `out/R1/runs/regression/01-completed/Aspen-Properties/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/PropertiesDatabase/DatabaseSetup/log4net.dll.md` 逐条断言（同一组先在基线 `_work/20261120-log4net-ghidra/log4net.dll.md` 上跑，必须同样通过）：

| # | 命令 | 期望 |
| --- | --- | --- |
| 1 | `grep -c -F '2152 = 1956 + 154 + 32 + 10'` | ≥1（基线实测 2） |
| 2 | `grep -c -F '79fb102269a09a949d76ab39897a226a6a7c66f04d7de0330dc41873d1433bc6'` | =1（完整 64 hex；模板规定只出现于 §2） |
| 3 | `grep -c -E '1134.*79fb102269a09a949d76ab39897a226a6a7c66f04d7de0330dc41873d1433bc6'` | =1（1134 与哈希同行） |
| 4 | `grep -c -F 'Debug::Flush'` | ≥1（基线 5） |
| 5 | `grep -c -F 'Debug::Write(string, string)'` | ≥1（基线 2） |
| 6 | `grep -c -F 'IL_000A'` | ≥1（基线 6） |
| 7 | `grep -c -F '反编译伪代码'` | ≥1（基线实测 2） |
| 8 | `grep -c -F 'tiny 0x46'` | =1（只在 §2 方法表出现一次） |
| 9 | `grep -c -F 'fat 0x3013'` | =1（同上） |
| 10 | `grep -c -F '〔实测〕'` | ≥1 |
| 11 | `grep -c -E '[A-Za-z]:\\'` | =0（无本机绝对路径；基线 0） |

### 3.2 报告模板（S0–S8，取代未定义的 F01–F12）

CLR `.md` 九节，标题逐字可 grep：`## 0. 摘要`（**末行固定句** `含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条`）/ `## 1. 样本与哈希` / `## 2. 元数据摘要` / `## 3. IL 清单（全量）` / `## 4. 反编译伪代码（ILSpy）` / `## 5. P/Invoke 与原生调用` / `## 6. 工具与环境` / `## 7. 缺口与待验证` / `## 8. 结论`。
- **唯一性规则（r2-a I10）**：`1134` 与版本资源哈希只写在 `## 2` 的一行（`- 版本资源：1134 字节，SHA-256 <64hex>`）；`tiny 0x46`/`fat 0x3013` 只在 `## 2` 的方法表各出现一次；`## 3`/`## 4` 只引用文件名，不重复这些字面量。
- **来源行按 schema 条件化（r2-a I13）**：B 清单 = `来源：分支 codex/waiting-for-tietoumao｜git blob <前12>｜自算 sha256 <64hex>｜台账 20261119-61 缺失〔待验证〕`；A 清单 = `来源：inventories/2026-11-19（properties|plus|shared）｜台账〔待验证〕`。
- native `.md` 同构九节：`## 2. PE 导入摘要（语言/基址/块）`、`## 3. 反汇编清单（全量）`、`## 4. 反编译伪 C（Ghidra）`、`## 5. 函数统计（FUNC 数 = //FUNC 数 + //DECOMP-FAIL 数）`。
- 非 PE `.md`：`## 0. 摘要` + `status=unsupported_non_pe` + `已试工具` 列表 + `原始报错：<工具> <异常类名: 消息>` + `〔待验证〕` + 同一固定句。

### 3.3 `tool/ghidra_scripts/ExportAll.java` 最小接口（T1N 从零写，r2 双 I5 契约）

- **调用**（由 `native_reverse.py` 拼）：
  `bash "$GHIDRA/support/analyzeHeadless" out/R1N/ghidra-proj aspen_native -deleteProject -import "out/R1N/stage/<safe_key>__<NAME>" [再重复 -import …] -scriptPath tool/ghidra_scripts -postScript ExportAll.java "<abs outdir>" -analysisTimeoutPerFile 600`
  staging 文件名 = `<safe_key>__<NAME>`（唯一化，避免 4 份 `userfort.dll` 同名冲突；程序名即此名）。
- **ExportAll 入参**：`args[0]` = 输出目录；取 `currentProgram`，输出两个文件：
  - `<outdir>/<programName>.asm.txt`：首三行 `# LANG <language id>` / `# BASE <image base hex>` / `# BLOCKS <n>`；随后每函数 `FUNC <addr> <name>` + 指令行 `  <addr>: <mnemonic> <operands>` + `ENDFUNC`。
  - `<outdir>/<programName>.c.txt`：每函数 `// FUNC <addr> <name>` + C 正文 + `// ENDFUNC`；反编译抛异常时写 `// DECOMP-FAIL <addr> <name> <ExceptionClass>`（**不写空函数体、不凑数**）。
- **恒等式**：`^FUNC ` 数 `==` `^// FUNC ` 数 `+` `^// DECOMP-FAIL ` 数（逐 PE）；`decomp_fail` 可大于 0 但必须打印并在 `.md`/`receipt` 报数；单 PE 超 600 s ⇒ 该件 `failed_analyze`（不写伪造产物）。
- **产物落位**：`native_reverse.py` 把 `<programName>.asm.txt` 重命名为 `01-completed/<Product>/<DIR>/disasm/<NAME>.asm.txt`，`.c.txt` → `decompiled/<NAME>.c.txt`；`import.log` 存 analyzeHeadless stdout。

### 3.4 T4 的 PLAN 夹具（r2-b I17，全部离线、不推送）

```
python tool/assemble.py --seed-state read-test-waiting.csv --out out/R3/fixtures/plan-fx/state-seeded.json   ⇒ STATE-SEEDED items=58
python tool/run_batch.py --auto --manifest read-test-waiting.csv --source-root dl --state out/R3/fixtures/plan-fx/state-seeded.json --plan-only   ⇒ PLAN new=0 skip=58 replaced=0 stale=0
python - <<'EOF'
import csv, shutil, pathlib
rows = list(csv.DictReader(open('read-test-waiting.csv', encoding='utf-8')))
fx = pathlib.Path('out/R3/fixtures/plan-fx'); (fx/'dl2').mkdir(parents=True, exist_ok=True)
shutil.copy('../20261120-log4net-ghidra/samples/log4net.dll', fx/'dl2'/'000_comcat.dll')
rows[0].update(sha256='2af48761d784d3c3b44eb0cf592e96aa2fee7dbc570c62e05db147198ff8f86c', size='272424', local='dl2/000_comcat.dll')
with (fx/'manifest-replaced.csv').open('w', encoding='utf-8', newline='') as fh:
    w = csv.DictWriter(fh, fieldnames=rows[0].keys()); w.writeheader(); w.writerows(rows)
EOF
python tool/run_batch.py --auto --manifest out/R3/fixtures/plan-fx/manifest-replaced.csv --source-root out/R3/fixtures/plan-fx --state out/R3/fixtures/plan-fx/state-seeded.json --plan-only
⇒ PLAN new=1 skip=57 replaced=1 stale=0
⇒ SUPERSEDE old=sha256:42abffb7bfa1da5188a85dcc448365c4ca5cb07d8749d32e0dae636ecb23d696 new=sha256:2af48761d784d3c3b44eb0cf592e96aa2fee7dbc570c62e05db147198ff8f86c
```

## 4. 阶段划分与就绪关系

```
[阶段 4 前] starter 快照（§6）
   T1  (CLR 链)   ─┐
   T1N (native 链) ─┼─→ T4（装配 → 调 T3 门禁 → 逐件 commit 推送 → 读回）→ 阶段 6 双评审
   T3  (门禁工具)  ─┘        ↑ T4 内部先跑 UPLOAD_OK，非 0 不推送；默认复用 T1/T1N 产物，不重跑分析
   T2  (仓库自检) ──→ 独立产物 out/R2/05-repo-check.md（不进 T4 依赖）
[阶段 6] critic_a + critic_b（L2 双份，并行互不知情）→ 非 PASS ⇒ 阶段 7：dispatch_subagent preset="ops-ptc" 只修 must_fix ⇒ 回 6
[阶段 8] reporter 出 07-report.md → Router 跑 supervision-gates
```

- **可同波并行**：T1、T1N、T2、T3（四个写者目录互不重叠；T1/T1N 只读 `dl/` 与清单，T3 只读自建夹具）。
- **真依赖**：T4 ← T1 `.and.` T1N `.and.` T3。T4 的 `--auto` **内部**先调 `check_upload.py`，非 0 不推送。
- **T4 不重跑分析**：默认复用 `out/R1`/`out/R1N` 的产物（D10 复用语义），因此其 45 min 只覆盖装配+门禁+推送；`--force-analyze` 是显式逃生门，不在验收判据路径上。
- **不可并行**：`out/R1` 与 `out/R1N` 不共享文件；`out/state.json` 只 T4 写。
- 波次上限 100/波（本轮 4+1）；token/墙钟一律「无法判定」。

## 5. 阻塞与缺口（B3 已部分解除）

- **B3 已到位 58 件**：`read-test-waiting.csv`（58 行、UTF-8 无 BOM、CRLF；CLR 31 / native 19 / not-PE 8；58 个 sha256 与 `dl/` 文件逐一对上）。**`dl/` 有 61 个文件**：58 个 `NNN_<原名>` + 3 个 Router 抽检副本（`Interop.appinitLib.dll` c8cbc427…、`comcat.dll` 42abffb7…、`userfort.dll` cbcecb9c…，哈希都在 CSV 里）⇒ 必须按 `local` 列定位，不得按目录扫描计数。
- **台账缺失**：`20261119-61` 台账在 9 个分支都不存在 ⇒ 无法按台账哈希对账；报告"来源"只写分支名 + `git_blob` + 自算 sha256，对账项标〔待验证〕。
- **范围 1,315 vs 当前 58**：上游 README 说仍在传 ⇒ 本轮以 58 件为验收面；新件靠 `--auto` 重跑自动纳入。
- **平台事实**：properties 清单 1,866 = 920 `PE-native` + 872 `PE-CLR-IL-only` + 36 `PE-CLR-mixed` + **38 非 PE**（COFF-archive 20 / ZIP 6 / OLE-VBA-project 6 / OLE-Office-with-code 4 / OLE-compound 2）；plus 另有 COFF-object 14 / ACM-model-library 8 / NE-Win16 2。本轮 native 链覆盖 `PE-native`；`.obj/.lib` 走 `unsupported_non_pe`。
- **Ghidra 原生链首次落地**：`ExportAll.java` 是从零写的交付物（磁盘上不存在），契约见 §3.3；首个判据是长路径 native 件冒烟；失败如实回执，不伪造产物。
- **gaps 记 `skills_declared_not_dispatched`**：本轮只出清单不真跑 grant（`apply_skill_grants=false`），阶段 4 派工前须真跑 `skills-dispatch.md` §3 的 grant+verify。

## 6. 快照与回滚（阶段 4 派工前，starter 必须做）

- **对象**：① `worklogs/flowntier/wf-20261120-aspen-batch/{01-plan.md,taskbooks/**,skills-dispatch.md}`；② `_work/wf-20261120-aspen-batch/{tool/**,out/**}`（当前 `tool/`、`out/` 不存在 ⇒ manifest 记 `MISSING(预期)`）。
- **落点**：`worklogs/flowntier/wf-20261120-aspen-batch/snapshots/phase4/` + `manifest.sha256`（`<相对路径>|<sha256>|<字节数>`）。
- **排除**：`__pycache__/`、`*.pyc`、`_logs/`、`repo.tar.gz`、`out/R2/worktree`、`out/R2/_tmp`、`out/R1/_tmp`、`out/R1N/stage`、`out/R1N/ghidra-proj`、`out/R3/upload/**`（可重生成）、`home/**`、阶段 1 残留 `_cred.py`/`gh.py`/`git-auth.sh`/`err.tmp`/`tok.tmp`。
- **必须快照**（r2-a I15）：`out/R3/upload-map.tsv` 与 `out/R3/receipt.json`（推送来源与回执，排除 `upload/**` 时**不能**把它们一起排除）。
- 仓库克隆 `Aspen-for-mac-main/` 不纳入快照（本轮零改动；T2 在副本里跑）。单文件 >200 MB ⇒ 报错停手。
- `taskbooks/**`、`skills-dispatch.md` 当前不存在 ⇒ 记 `MISSING(预期)`，产出后再快照。
- **回滚两步**：① 先列 `DIFF/MISSING/EXTRA` 交 Router；② 确认后才按清单回拷；无 git ⇒ 禁用 `git restore/checkout`。


## 7. 技能分发清单（摘要；可执行版见 `skills-dispatch.md`）

| 角色/任务 | skills[] | 取哪几节 / 不取哪几节 |
| --- | --- | --- |
| T1 / R1-CLR | `reverse-engineering`、`execution-discipline` | 取观测/推断/未知分层与 PE-CLR 取证口径；取长命令与输出规模纪律。不取 Ghidra-GUI 流程细节 |
| T1N / R1-NATIVE | `reverse-engineering`、`execution-discipline` | 同上 + 函数级证据口径；不取提交规范 |
| T2 / R2 | `supervision-gates`、`execution-discipline` | 取 §1（`PASS=0` 空绿陷阱）与回执判据；不取发布章节 |
| T3 / R4 | `supervision-gates`、`code-review` | 取门禁判据 + 两轴审阅框架；不做代码风格挑刺 |
| T4 / R3 | `github-publish-without-git`、`pr`、`network-firewall-policy` | 只取 §3 的 blobs/tree/commit/refs 与 `base_tree`；**禁用**其 `GH_TOKEN`、pwsh/node 包装与 main 上的 PATCH（违 D1/D2/D5） |
| critic_a（阶段 3/6） | `code-review`、`supervision-gates` | 找茬两轴 + 回执判据 |
| critic_b（阶段 3/6） | `code-review`、`writing-for-agents` | 命名/接口/判据一致性 |
| reporter | `de-ai-flavor`、`writing-for-agents` | 人话报告 |

- `apply_skill_grants=false`：只出清单不真跑；无"库内无覆盖"项。

## 8. 风险与预算

| 风险 | 影响 | 处置 |
| --- | --- | --- |
| token 泄漏 | CRITICAL | D1：只进内存 + `token_len` + 推送前后日志扫描 + R4 grep 第二道 |
| 误写 main / 整树覆盖新分支 | 丢数据面 | D13：`base_tree`/`parents`/`force:false` + `pre_paths ⊆ new_paths` + `main_before==main_after` + 三条硬禁止 |
| `--auto` 重跑全链 ⇒ BATCH 行出不来 | CRITICAL | D10 复用语义（默认不重跑）+ `ANALYZE-MISSING`/`--force-analyze`；T4 45 min 只覆盖装配/门禁/推送 |
| Windows 路径含冒号 | `WinError 123`/ADS | D11 只清洗键派生路径；`<DIR>` 原样 |
| 长路径 >260 | Ghidra/JVM 写失败 | D17 冒烟挑最长件 + `\\?\` 兜底 |
| 同键多行 / 落点撞名 | 报告静默覆盖 | D12 + `report_md 去重数 == 行数` |
| 仓库 tests 污染克隆 | `tmp*` 残留 | D8 副本 + 快照排除 |
| Ghidra headless 环境 | native 链跑不出 | D14 常量 + §3.3 契约 + 单件冒烟 + 失败如实回执 |
| 上传完整逆向正文 | 违反仓库 AGENTS | D15 固定句 + D16 体积/commit + 门禁断言 |
| API 限流 | 推送中断 | 60 commit/175 blob 分步可续；`network-firewall-policy` §1 重试退避 |
| 预算 | — | timebox：T1 100 / T1N 60 / T2 20 / T3 20 / T4 45 min ⇒ **关键路径 ≈145 min**（T1‖T1N‖T2‖T3 → T4）。用 `--force-analyze` 时额外 +160 min 且不计入验收。超时停手上报，不抽样 |

## 9. 交付前自检（结果写进 `TASK_RESULT.evidence`）

1. 任务表五行都在，每行 `skills[]` 非空、有 `model/effort` 与 `channel`；
2. 5 份任务书都有 `channel:` 行，三项与 §3 一致（`opencode-go` / `deepseek-v4.1-flash` / `low`）；
3. **每份任务书五要素齐全**（`planner-dispatch` §1）：① 目标与判据 ② 写入范围 ③ 时限（T1 100 / T1N 60 / T2 20 / T3 20 / T4 45 min + "超时停手上报"）④ 技能指针 ⑤ 回传格式（三档验证表 + 未验证缺口 + 失败点原文 + `TASK_RESULT`）；
4. **白名单两两交集为空 + 运行时写入 ⊆ 白名单**（静态交集附命令输出；运行时核对：T4 调 gate 必须带 `--allowlist-out out/R3/upload-allowlist.json`，不写 `out/R4`）；
5. **每份任务书带工具口径三行**：只有 `run_code` 能直呼；其余在 `run_code` 里调 `tools.read`/`tools.write`/`tools.ops_bash`；不得直呼未声明工具；
6. 任务书零 `git` 命令、零 token 字面量（附 `grep -c`）；
7. 每条判据都是「命令 + 期望输出行」；无弹性措辞（自查恒真切词的 `grep -c` 见 `TASK_RESULT.evidence`，期望 0）；
8. 判据能在本机只读数据上先跑出基线（§3.1 的 11 条已在基线 `log4net.dll.md` 上通过）；
9. 未写白名单外路径（写入清单 = 本文件 + 5 份任务书 + `skills-dispatch.md`）。

## 10. 作废说明与 taskbooks 产出计划

- 旧 scope（A1–A6）按"仓库内含托管 PE"写成，实测仓库 **0 个托管 PE** ⇒ A1–A6 全部作废。
- **`taskbooks/01-pipeline-core.md` 仍在（123 行，旧 A1 scope）⇒ 阶段 4 开始前必须删除或整篇覆盖**。
- 阶段 4 产出 5 份任务书：`taskbooks/02-r1-clr-chain.md`、`taskbooks/03-r1n-native-chain.md`、`taskbooks/04-r2-repo-check.md`、`taskbooks/05-r4-upload-gate.md`、`taskbooks/06-r3-push.md`；以及 `skills-dispatch.md`。**本轮不写这些文件。**

## 11. rev3 变更（响应阶段 3 双 REPAIR）

| must_fix | 来源 | 改在哪节 | 具体做法 |
| --- | --- | --- | --- |
| M1 上传集无人拥有 / 无本地→远端映射 | critic_b I1（CRITICAL） | §1.2 暂存树、§2 D4、§3 T4、§3 T3 | 定 `out/R3/upload/` 为**上传暂存归属**（T4 装配），`upload-map.tsv` 逐行 `repo_path↔local_path↔sha256↔bytes`；T4 `--list-only` 逐行打印 `MAP …` 且 `lines==files`（缺一行 exit 1）；README 内容口径写死：怎么跑（D10 命令）、边界（只推 codex 分支、不传原件）、B3 缺口（台账缺失/1315 vs 58）、native 已实现（§9 后不再是骨架） |
| M2 `analysis_key` 含冒号 ⇒ 路径不可用 | critic_a I1（CRITICAL） | §1.2 `safe_key`、§1.3 列、§2 D11、§3 T1 | `analysis_key_safe = sha256_<64hex>`；ledger 单列；路径组件 `[^A-Za-z0-9._-]→_` + 断言不含 `:` |
| M3 Git Data API 四步名不可执行 | critic_a I2（CRITICAL） | §2 D13、§3 T4 判据 | 写死 `base_tree/commit.parents`、首建 `POST`/已存在 `PATCH force=false`、`422` 不 force、`pre_paths ⊆ new_paths`、`len(new)==len(pre)+N`、`main_before==main_after`、三条硬禁止 |

| HIGH/其余 issue | 来源 | 改在哪节 | 具体做法 |
| --- | --- | --- | --- |
| 判据不可执行（U+2026 省略号 / `=1` 与基线冲突） | critic_a I3、I4；critic_b I4 | §3.1 表 | 完整 64 hex + `2152…` 改 ≥1；`Flush`/`Write(string, string)`/IL_000A/伪代码节/tiny/fat/1134 同行，共 11 条并在基线上自测 |
| 行数判据自相矛盾（754 vs 1397） | critic_a I5；critic_b I3 | §1.3、§3 T1 判据③ | 拆两条：properties 754 / 三清单并集 1397；带来源命令 |
| 同键多行 / owner 冲突 | critic_a I6；critic_b I2 | §2 D12、§1.3 | 优先级 `properties>shared>plus`、同清单首行；`first_seen_manifest`/`product_source` 列；实测 1303/684、分布 750/643/4 |
| 落点撞名 | critic_a I7 | §2 D12 | 消歧后缀 `__<key8>` + 断言 `report_md 去重数==行数`；实测 1394/3 桶/6 键（口径见 D12） |
| T2 空绿（判据写成弹性值） | critic_a I8；critic_b I8 | §3 T2 | `files_verified=18`、`ran=54` 写死；`errors` 只记实测；`ran==0` ⇒ exit 2；`05-repo-check.md` 每条差异带命令原文 + env/real |
| T3→T4 allowlist 未绑定 | critic_a I9 | §2 D5、§3 T3/T4 | T3 出 `upload-allowlist.json`（每文件 sha256）；T4 当白名单，`pushed_blobs==audited_blobs`，多一个 exit 3 |
| T3 缺大小断言 | critic_a I15；critic_b I5 | §3 T3 | 单文件 ≤5 MB（超限须 gzip）、总量 ≤64 MB；负例补 `.dll/.exe/.db` 与 6 MB 超限 |
| D1 传递路径未写死 | critic_a I10 | §2 D1 | `capture_output=True`+`stdout.strip()`；禁 argv/env/文件；顶层 except 只打类名+`token_len` |
| 输入校验/空清单未定义 | critic_a I12 | §2 D3 校验表 | 8 种情形 + fail-closed（`rows=0` ⇒ exit 2） |
| 编号 T3/T4 与 §3 反 | critic_a I17；critic_b I6 | §1.1 注释、§3 | 全篇统一 **T1=CLR 链、T1N=native 链、T2=R2、T3=R4 门禁、T4=R3 推送** |
| §10 不实陈述 | critic_a I13；critic_b I12 | §10 | 改成"阶段 4 前删除/覆盖"；点名 5 份任务书与 `skills-dispatch.md` 待产出 |
| §9 自检缺工具口径三条 | critic_a I16 | §9 #4 | 新增硬规则（`run_code` + `tools.*`） |
| 快照排除 worktree/tmp | critic_a I18 | §6 | `out/R2/worktree`、`out/R2/_tmp`（另加 R1/R1N 临时目录） |
| skills 只声明不 grant | critic_a I19 | §5、§7 | gaps 记 `skills_declared_not_dispatched`；阶段 4 前真跑 grant+verify |
| status 枚举缺非 PE | critic_a I11；critic_b I7 | §1.4、§5 | 增 `unsupported_non_pe`（rev3 曾写 `skipped_non_pe`；rev4 按 00-req §9.3 D3 统一）并给 `status→目录` 映射表；§5 补 1866=920+872+36+38 |
| F01–F12 无定义 | critic_b I9 | §3.2 | 删除该记号，改为可 grep 的 S0–S8 节名 |
| 上传脚本依赖 lib/config 不可跑 | critic_a I14 | §1.1、§2 D4 | 平铺 import + 上传 `tools/aspen_batch/` 全量 13 件 |
| `--since` 等自动化口径 | Router 补充 #1 | §2 D10、§3 T4 | 见 §12 |

## 12. rev4 变更（响应 Router 2026-11-20 23:5x 两条指令）

| Router 要求 / 00-req §9 | 落点 |
| --- | --- |
| 一条命令跑全流程 `tool/run_batch.py --auto`（发现→分析→出报告→门禁→推送→回执） | §2 D10、§3 T4 判据② |
| 增量/幂等：`out/state.json`（sha256 键）；已处理且已在远端不重推；新件自动纳入；原件被替换（哈希变）重做并留历史 | §2 D10 增量规则③④、§3 T4 判据③⑤ |
| 上传只传产物（逐件报告 + ledger + README），落 `analysis/20261120-batch-driver/`；**绝不传原件** | §2 D4、§1.2 暂存树、§3 T3 |
| 单件失败不中断；末行 `BATCH done=… skipped=… failed=…` | §2 D10、§3 T4 判据② |
| 可定时 `--auto --since <sha>`（本轮不真挂 cron） | §2 D10、§3 T4 判据④ |
| 推送前仍过 R4 门禁 + main-sha 不变断言 | §2 D5、D13、§3 T4 |
| **D4 冲突**：旧 D4「只传 4 个文件」vs 新口径「传逐件产物」 | §2 D4 改为**产物集**（175 件），§3 T3 按 `files=175` 校验、T4 用 T3 allowlist（取舍见回执 gaps） |
| §9 目标升级：CLR 全程序集 IL + 全量 C#；native Ghidra 全函数反汇编 + 伪 C；非 PE `unsupported_non_pe` + 原始报错 | §1.1 T1/T1N 分工、§2 D14、§3 T1/T1N、§3.2 模板 |
| §9.1 AGENTS 偏离授权（每份 md 写明依据；回执单列） | §2 D15、§3 T4 判据⑥ |
| §9.2 体积/提交规范（≤5 MB、gzip、逐件 commit、INDEX.md+index.csv、隐私） | §2 D16、§1.2、§3 T3/T4 |
| §9.3 D1–D5 判据 | D1/D2 → §3 T1/T1N 判据 + T3 产物齐全断言（`products clr=31 native=19 nonpe=8`）；D3 → T1 判据②（每份 `unsupported_non_pe` + 原始报错）；D4 → T4 判据⑥（`readback.index_rows=58 items_complete=50`）；D5 → D13 硬禁止 + `main_before==main_after` |
| T1 拆两链（CLR / native），互不依赖、同波、白名单不撞 | §1.1、§4 DAG、§8 timebox（T1 100 / T1N 60） |
| T4 改逐件 commit 的批推（60 次 commit / 175 blobs；只推 codex；main 前后 sha；T3 allowlist；`tree_paths==base+n`） | §2 D13 步 6–8、§3 T4 判据② |
| 「§8 的 native 骨架口径已被 §9 覆盖」 | §5 平台事实改写为"native 链覆盖；非 PE 走 `unsupported_non_pe`"，rev3 的 `skipped_native` 不再是有效 status（仅在本节与 §11 对照表里作为历史名保留） |
| timebox 重算（rev2 的 45 min 装不下） | §8：T1 100 min（31 件 ×3 min 保守）、T1N 60 min（19 件小 PE + 单次 JVM）、关键路径 ≈145 min；超时停手上报、不抽样 |

## 13. rev5 变更（响应 r2 双 REPAIR）

| issue（r2） | 改在哪节 / 哪个判据 |
| --- | --- |
| **a-I1 = b-I1（CRITICAL）`--auto` 重跑全链、BATCH 行出不来** | §2 **D10** 新增**复用语义**（默认查 `product_sha256` 与 state，存在即跳过分析；缺产物才 `ANALYZE-MISSING`/`--force-analyze`）+ 末行字段重定义（`done/analyzed/unsupported/skipped/failed/reused/analyzed_now` 恒等式）；§0 / §4 / §8 同步（T4 45 min 只覆盖装配+门禁+推送；`--force-analyze` 不计入验收） |
| a-I2 `import dnlib` 在 `tool/lib/` ⇒ ModuleNotFound | §1.1 入口 `sys.path.insert(0, Path(__file__).parent/"lib")`；T4 判据①加 `bundle=OK`（从 staging 目录跑 `--plan-only`） |
| a-I3 = b-I6 ILSpy `-o` 产出多文件 | §2 D14 写死 `“$DOTNET” “$ILSPY” <dll> > decompiled/<NAME>.cs.txt`、**禁 `-o`/`-p`**；T1 判据②加"每件 1 个 `.cs.txt`、行数>0、`class `≥1" |
| a-I4 T1 ①②③ 共用 `--out out/R1` 互相污染、③ 缺参数 | §1.2 三个隔离根（`out/R1` / `out/R1/runs/regression` / `out/R1/runs/counts`）；§3.1 命令改 `--out out/R1/runs/regression`；T1 判据③补全 `--manifest` 与 `--out` |
| a-I5 = b-I13 缺 kind→链 路由 | §2 **D3** 路由表（CLR/not-PE→T1、native→T1N）+ `_run.json filtered`；T1 `rows=39 filtered=19`、T1N `rows=19 filtered=39`、"两者之和 = 58" |
| a-I6 = b-I5 `ExportAll.java` 无契约 | 新增 **§3.3**（analyzeHeadless 调用、`<safe_key>__<NAME>` staging、两输出文件行格式、`// DECOMP-FAIL`、`FUNC == //FUNC + //DECOMP-FAIL` 恒等式、600 s 超时 ⇒ `failed_analyze`）；T1N 目标/判据引用 §3.3 |
| a-I7 = b-I3 T3 判据依赖 T4 的 staging（环形） | §3 T3 判据改为**只验自建夹具**（`--build-fixtures` 13 件 + `GATE UPLOAD_OK files=13` + `SELFTEST cases=8 passed=8`）；真实 175 件断言移到 T4 判据①；§4 依赖说明同步 |
| a-I8 = b-I12 末行计数器不自洽 | §2 D10 末行重定义：`analyzed+unsupported+skipped+failed == done`、`reused+analyzed_now == done-skipped`；T4 判据②③给出两套具体期望值（58/50/8/0/0 与 58/0/0/58/0） |
| a-I9 = b-I11 `tree_paths=860` 写死且未过滤目录 | §2 D13 步 4 只收 `type=="blob"`；步 8 与 T4 判据② 改 `tree_paths=<base_blob+175>` 并打印 `base_blob=685`（期望值，不等则记差异） |
| a-I10 模板重复 `1134`/`tiny` 与判据 `=1` 冲突 | §3.2 增**唯一性规则**（这两处只在 §2 出现一次）；§3.1 #8/#9 保持 `=1`，#7 注释订正为 2 |
| a-I11 = b-I9 固定句无断言 | §3.2 S0 末行写死固定句；T1 判据② 与 T3/T4 加 `find … -name '*.md' -exec grep -L '偏离仓库 AGENTS' {} +` 无输出 |
| a-I12 产品目录两套名 | §1.2 统一 `Aspen-Properties/Aspen-Plus/shared`；§1.3 ledger 增 `product_raw` 保留原值 |
| a-I13 模板来源行对 schema A 填不出 | §3.2 来源行按 schema 条件化（B：分支+blob；A：`inventories/2026-11-19` + 台账〔待验证〕） |
| a-I14 analyzeHeadless 用 bash 还是 .bat | §2 D14 写死 `bash "$GHIDRA/support/analyzeHeadless"`（实测可用）+ `.bat` 退化 + `-analysisTimeoutPerFile 600` |
| a-I15 快照排除 staging 导致无法复算 | §6 增"必须快照 `out/R3/upload-map.tsv` 与 `receipt.json`"（只排除 `out/R3/upload/**`） |
| a-I16 `errors=<实测>` 与自查口径冲突 | §3 T2 改 `errors=<n>` + 断言 `errors == grep -c '^ERR ' out/R2/05-repo-check.md` |
| b-I2 D11 清洗 `<DIR>` 与 §3.1/D12 冲突 | §2 **D11** 收窄：只清洗 `analysis_key_safe` 与键派生 stem；`<Product>/<DIR>/<NAME>` 原样（含 `[ ]`/空格/`!`），只断言不含 `:`；§1.2 同步 |
| b-I4 T4 运行时写 `out/R4` | §2 D5 加 `--allowlist-out out/R3/upload-allowlist.json`；§9 #4 改为"静态不交 + 运行时写入 ⊆ 白名单" |
| b-I7 `sys.path` | 同 a-I2（§1.1） |
| b-I8 README/INDEX/index.csv 无结构 | 新增 **§1.5**（README 7 个二级节、INDEX 三类行计数 31/19/8、index.csv 9 列 × 59 行）；T4 判据⑥加 `readback.readme_sections=7`/`csv_rows=59` |
| b-I10 >5 MB gzip 无写者 | §1.2 增"T1/T1N 写盘前自动 gzip + `.md` 写解压命令"；T3 allowlist 接受 `*.txt.gz`（夹具含 1 个） |
| b-I14 长路径 >260 | §2 新增 **D17**（实测绝对最长 285；T1N 冒烟挑 `BFDYLD.dll`，`\\?\` 兜底 + 记 `LONGPATH fallback`） |
| b-I15 `local` 相对基含糊 | §2 D3 定位规则改为"先 `<清单所在目录>/<local>`，再 `<source-root>/<basename(local)>`" |
| b-I16 §3.1 #7 注释"基线 10" | §3.1 表 #7 订正为"基线实测 2" |
| b-I17 PLAN 替换夹具缺构造命令 | 新增 **§3.4**（`--seed-state` + 替换夹具脚本 + 两条期望 `PLAN` 行 + `SUPERSEDE` 行） |
| a-I1 残留：D11 无判据 grep | T1 判据② 加 `find out/R1 -name '*:*'` 计 0 |
