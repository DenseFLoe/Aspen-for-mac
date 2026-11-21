---
name: supervision-gates
description: 交付前要跑门禁、或要判一次命令/子 agent 的回执到底算不算成功时用它：跑哪五个门禁（含单写者认领注册表门禁）、门禁为什么会空绿、"门禁绿灯不等于没人写"、run-bounded 回执按什么判成功、哪些键一定存在、stdout 为空时怎么办。当用户问"这个算验证通过了吗""门禁跑了没有""绿灯能不能信""回执里这行是什么意思""为什么说没通过"时也要用它——这些话里不会出现"门禁"或"回执"这些词。也用于有人拿"我这边跑过了、没问题"当作证据的场合。
license: 跟随工作区
compatibility: PowerShell 5.1；只讲判据与消费规则，不引入包装进程；不联网、不监听端口、不动硬件
metadata:
  author: workspace
  version: "1.0"
---

# supervision-gates —— 交付门禁 + 有界执行器回执消费规则

> **需求不清先问（≤2 轮，仅 Router 可用）**：目标 / 范围 / 判据缺失或矛盾时，先按 `skills\README.md` §4 第 10 条要一次回填清单（一轮问完，最多两轮），不许猜着做；**子 agent 不向人提问**，把缺项与回填清单回给 Router。

权威来源：本工作区原 `AGENTS.md` §6（交付物与门禁）、§8（回执消费者规则）（2026-10-15 下沉；
下沉前全文快照 `worklogs\AGENTS.pre-sink-20261015.md`，SHA256 6DFBB907…）。

## 1. 交付前必跑五个门禁（**直接跑**，不要再套看门狗包装）

```
supervision\verify-interface-contract.ps1
supervision\compare-default-behavior.ps1
supervision\verify-json-contract.ps1
supervision\verify-no-stub.ps1          <- 第四个，必须有
supervision\verify-single-writer.ps1    <- 第五个，必须有（单写者认领注册表门禁，2026-10-15 新增）
```

- 出口：看到"全 PASS"才算；**`PASS=0` 不是通过**（解析到 0 个用例却打印"全部正常"是**缺陷**，不是绿灯）。
- 交付物位置（哪类东西放哪）：见 `references\gates-and-shapes.md` §1。
- 第四条为什么存在、它怎么杀空壳：同文件 §2（实测数据）。
- 第五条的退出码与判定集合：同文件 §7（`0`=违规集合为空 / `1`=有违规 / `2`=用法·环境错误）。
  **口径降级（2026-10-17）**：第五条**只验"认领注册表的卫生"** —— 必需字段齐、字段非空、`created` 可解析、
  未过期、同一 `target` 无双认领；**`ttl` 过期 / `fence` 单调 / 逻辑路径聚合属"门禁待扩展项"，当前脚本未实现**
  （口径见 `skills\execution-discipline\SKILL.md` §3 G）。它**不构成**"没人写 / 没越界写"的证据：
  存在一个合法未过期认领 ⇒ 也是 `exit=0`（有人正在写是正常状态）⇒ **不得**把它的绿灯读成"此刻没人写"
  或"我可以写"；写的许可只由 `skills\execution-discipline\SKILL.md` §3 的**认领是否成功、`fence` 是否被拒**决定。
- **交付前除门禁外，必须另跑"合并期逐路径哈希对账"**（每个副本 vs 主检出），把结果写进回执；
  可粘贴命令（在**主检出根目录**跑，只打印不一致 ⇒ **空输出即零差异**）：
  ```powershell
  $main = (Resolve-Path -LiteralPath '.').Path
  $replicas = @('.dsh-worktrees\<task-id>')
  $exclude = '\\(\.git|\.dsh-worktrees)\\'
  $mainHash = @{}
  Get-ChildItem -LiteralPath $main -Recurse -File -Force |
    Where-Object { $_.FullName -notmatch $exclude } | ForEach-Object {
      $mainHash[$_.FullName.Substring($main.Length).TrimStart('\')] =
        (Get-FileHash -LiteralPath $_.FullName -Algorithm SHA256).Hash }
  $diffs = 0
  foreach ($r in $replicas) {
    if (-not (Test-Path -LiteralPath $r)) { "NO-REPLICA $r"; $diffs++; continue }
    $rp = (Resolve-Path -LiteralPath $r).Path
    foreach ($rel in $mainHash.Keys) {
      $o = Join-Path $rp $rel
      if (-not (Test-Path -LiteralPath $o)) { "MISSING-IN-REPLICA $r $rel"; $diffs++; continue }
      if ((Get-FileHash -LiteralPath $o -Algorithm SHA256).Hash -ne $mainHash[$rel]) { "DIFF $r $rel"; $diffs++ }
    }
  }
  "RECONCILE diffs=$diffs replicas=$($replicas.Count) files=$($mainHash.Count)"
  ```
  对账**不绿就停下上报**；**不许**用"门禁绿"顶替（口径见
  `skills\execution-discipline\references\concurrency-external-patterns.md` M7）。

## 2. 判断一次 `run-bounded` 运行为"成功"的唯一判据（实测 0/24 误判）

**只认这一条**：`outcome == 'EXITED'` **且** `childExit == 0` **且** `<workDir>\receipt.json` 的 `nonce`
等于**本次 stdout** 的 `nonce`。**其余一律判失败。**

两个补充：

- **stdout 为空**（如 CLI 参数绑定失败：0 字节、exit 1）⇒ 没有本轮 nonce ⇒ **直接判失败**；
- **`outcome != 'EXITED'`** ⇒ **直接判失败**（哪怕磁盘上那份回执的 nonce 恰好与本次一致 —— 实测存在这种形状）。

**不要**用"文件里有 EXITED 就算成功"（陈旧回执会骗你），**不要**用"退出码是 0"（拒绝形状也可能透传 0），
也**不要**只看 `outcome`。

## 3. 什么时候读 `references\gates-and-shapes.md`

- 要判**回执形状/键集合**（"这个键该不该在""键数不对是不是坏了""缺键还是 null"）⇒ 读它 §3。
- 要处理 **stdout 为空 + 非 0**、或怀疑收到了**上一次运行留下的** `receipt.json` ⇒ 读它 §4。
- 要解析回执文本（行数、"第一行是不是 JSON"、编码怎么读）⇒ 读它 §5。
- 要理解 `exitCode` 与 `outcome` 为什么会互相冲突、`wrapperExit` 为什么会超出 0..5 ⇒ 读它 §3。

## 4. Gotchas

- **`exitCode` 不总是脚本自己的语义码**：`keil build/rebuild/clean` 会填 UV4 的原始码（2/3/11/…），
  与脚本自身的 1/2/3/4 **空间重叠**；只有 `outcome` 能区分"被杀"与"子进程自己的码"。
- **`outcome=EXITED` 不是成功的证明**：Windows 上第三方用非负退出码杀掉子进程与正常退出无法区分
  （`TerminateProcess` 不可观测）⇒ 它只意味"退出码 ≥ 0、来源未知"。识别"这是本次运行"只能靠 `nonce`。
- **`maxSec` 是判定阈值，不是墙钟保证**（实测 `maxSec=5` → `elapsedSec≈5.6`，另有 ~400 ms 结算等待）。
- **门禁自己也会说谎**：历史上有过"零用例 PASS=0 却 exit=0"（空绿），所以"跑过了"必须连同**原始输出行**一起给。
- **子 agent 自报不算证据**：必须由 Planner 独立复核，关键结论要有**第二条同向证据**（判据见
  `skills\handoff-self-check\SKILL.md`）。
