---
task_id: 20261121-0145-SKILLS-dispatch
type: result
sender: aspen-batch (ds4.1f)
reply_to: handoff/incoming/
redaction: local workspace paths -> <workspace>
---

# skills-dispatch — wf-20261120-aspen-batch（阶段 4 技能分发清单）

channel: subagent provider=opencode-go model=deepseek-v4.1-flash reasoning_effort=low
model=deepseek-v4.1-flash effort=low
plan_ref: `01-plan.md` rev5 §7（技能分发摘要）+ `skills/flowntier-pipeline/references/planner-dispatch.md` §2（分发四条）
机制来源: `skills/POINTERS.md` §2（子档现值 = 9 条 grant + `diagnose-windows-sandbox-acl`）
apply_skill_grants: false
产出者: planner（阶段 4）；执行者是各 worker / critic 自己，本文件只定“派谁、给哪几条、取哪几节、何时收回”。

## 0. 一句话

7 个角色（5 个 worker + 2 个 critic）各挂 2–3 条技能，**技能只按“这条活真会用到的节”给**，不整本塞。本轮 `apply_skill_grants=false`：只出清单、**不真跑** `grant`；阶段 4 派工**前**必须按 §3 真跑 `grant` → `verify`（`STATUS=OK` 才派），阶段 5/6 收账后 `revoke`。未真跑的记 `gaps`：`skills_declared_not_dispatched`。

## 1. 角色 × 技能（7 行，逐行有 `skills[]` / 库内路径 / 取哪几节 / 不取哪几节）

| 角色 | skills[]（名字 + 库内路径） | 取哪几节 | 不取哪几节（原因） |
| --- | --- | --- | --- |
| `T1`（R1-CLR 链，`taskbooks/T1-R1-clr-chain.md`） | ① `reverse-engineering` = `skills/reverse-engineering/SKILL.md`；② `execution-discipline` = `skills/execution-discipline/SKILL.md` | ① §1（工具现实）/§3（先分流）/§4（观测·推断·未知三档）；② §1（输出规模）/§3（单写者与写入范围） | ① 不取 Ghidra-GUI 流程细节（属 T1N）；② 不取并发认领 fenced 的扩展项（本轮无多写者竞争） |
| `T1N`（R1-NATIVE 链，`taskbooks/T1N-R1-native-chain.md`） | ① `reverse-engineering`；② `execution-discipline` | ① §1/§2（开工前定死三样）/§4（函数级证据口径：`FUNC` / `//FUNC` / `//DECOMP-FAIL`）；② §1（headless 长跑纪律）/§3 | ① 不取“发布成果署名/分发”相关段；② 不取提交规范（属 T4） |
| `T2`（R2 仓库自检，`taskbooks/T2-R2-repo-check.md`） | ① `supervision-gates` = `skills/supervision-gates/SKILL.md`；② `execution-discipline` | ① §1（`PASS=0` 不是通过 = 空绿陷阱）/§2（回执只认命令 + 原始输出行）；② §1/§3 | ① 不取 §3 的 run-bounded `nonce` 细则（本题不用 run-bounded）；② 不取发布章节 |
| `T3`（R4 上传门禁，`taskbooks/T3-R4-upload-gate.md`） | ① `supervision-gates`；② `code-review` = `skills/code-review/SKILL.md` | ① §1/§2/§4；② 两轴框架（仓库标准 + 原始判据）用于自审门禁实现 | ① 不取发布章节；② **不做风格挑刺**，只拦“会推错集/漏拦原件”的错 |
| `T4`（R3 装配 + 推送，`taskbooks/T4-R3-push.md`） | ① `github-publish-without-git` = `skills/github-publish-without-git/SKILL.md`；② `pr` = `skills/pr/SKILL.md`；③ `network-firewall-policy` = `skills/network-firewall-policy/SKILL.md` | ① §3（Git Data API：blobs→trees→commits→refs、base_tree、空仓库 409）/§4（读回核对）；② §Sections（Summary / Evidence / Merge Danger）写分支说明；③ §1（只出站一条禁令一条判据）/§3（被拒怎么记账） | ① **禁用** §2 的 `GH_TOKEN` 环境变量法（违 D1）、§3 的 pwsh 包装脚本、第 4 步 `refs/heads/main` 的 PATCH（违 D13）；③ 不取账号级操作（§6） |
| `critic_a`（阶段 6 双评审之“找茬”） | ① `code-review`；② `supervision-gates` | ① 两轴（仓库标准 + 原始 `00-req.md` §7/§9）；② §1/§2（判“算不算验证通过”） | ② 不取发布/账号章节；不做纯风格挑刺（`must_fix` 只收 CRITICAL） |
| `critic_b`（阶段 6 双评审之“审查”） | ① `code-review`；② `writing-for-agents` = `skills/writing-for-agents/SKILL.md` | ① 两轴；② 命名/接口/判据一致性（任务书能否被 `ds4.1f` 这类执行模型照着做对） | ② 不取“人话报告”改写手法（那是 reporter 的 `de-ai-flavor`） |

非本轮（**不在本清单**）：`reporter` 属阶段 8，由 Router 出 `07-report.md` 并跑 `supervision-gates` ⇒ 其技能（`de-ai-flavor`、`writing-for-agents`）由 Router 侧安排，不由 Planner 分发。

## 2. 每条技能的“为什么是它”（查库结论，不是拍脑袋）

- `reverse-engineering`：库内**唯一**讲“已发布成果的逆向与行为还原”的条目，§4 的观测/推断/未知三档正是 T1/T1N 报告 `〔实测〕/〔待验证〕` 标注的本体。
- `execution-discipline`：长跑与输出规模的调用侧纪律（T1 要跑 31 次 ILSpy、T1N 要跑 19 件 headless、T2 要跑 54 例 tests）——不给这条，worker 会把全量 listing 刷进回执。
- `supervision-gates`：`PASS=0` 不是通过的判据本体；T2 的 `ran==0 ⇒ exit 2`、T3 的 `空暂存树 ⇒ exit 2`、T4 的 `门禁不绿不推送` 全部引用它 §1。
- `code-review`：T3 自审与两份 critic 的“两轴”框架（对仓库标准 + 对原始需求）；只拦两类（会写错 / 方向错），其余记 `issues[]` 不阻断。
- `github-publish-without-git`：本机 `git` 不可用，库内唯一给 Git Data API 形态的条目——但它的凭据法与 main 上的 PATCH 与本轮 D1/D13 冲突，所以**只取 §3/§4、显式禁用其余**（见上表）。
- `pr`：分支说明正文规范（三节），T4 的 `branch_note` 用它，保证“只推 codex 分支”这件事在正文里说清。
- `network-firewall-policy`：60 commit / 175 blob 会被限流；它给“被拒不许绕路、怎么记账”的纪律，避免 worker 用 curl 或重试风暴。
- `writing-for-agents`：critic_b 判“任务书能不能被次级模型照着执行”的对齐手法（命名、字段、判据一致性）。

**库内无覆盖的项**：本轮没有“需要但库里没有”的技能（0 条）；T3 的“上传门禁”具体规则来自 `00-req.md` §7 R4 + 仓库 `AGENTS.md`，已写进任务书正文，不靠技能补。

## 3. 真跑序列（阶段 4 派工前；本轮 `apply_skill_grants=false` 未执行）

```bash
# 1) 逐条放指针（每条一次；名字就是上表的 skill 名）
pwsh -NoProfile -File skills/_bin/skill-pointer.ps1 grant reverse-engineering
pwsh -NoProfile -File skills/_bin/skill-pointer.ps1 grant execution-discipline
pwsh -NoProfile -File skills/_bin/skill-pointer.ps1 grant supervision-gates
pwsh -NoProfile -File skills/_bin/skill-pointer.ps1 grant code-review
pwsh -NoProfile -File skills/_bin/skill-pointer.ps1 grant github-publish-without-git
pwsh -NoProfile -File skills/_bin/skill-pointer.ps1 grant pr
pwsh -NoProfile -File skills/_bin/skill-pointer.ps1 grant network-firewall-policy
pwsh -NoProfile -File skills/_bin/skill-pointer.ps1 grant writing-for-agents
# 2) verify 必须 STATUS=OK 才派（子根 == child_grants）
pwsh -NoProfile -File skills/_bin/skill-pointer.ps1 verify
```

- 判据：`verify` 输出 `STATUS=OK` 一行；不 OK 就别派（“子 agent 太笨”多半是没给它那份技能）。
- **收回时点**：每个 worker 的 `TASK_RESULT` 被 Planner 复核后 `revoke` 该角色**独有**的条目（8 条里 5 条被多角色共用 ⇒ 同一波全收后再统一 `revoke`，别在半波中间抽走）。
- 派 `ops-ptc` 档时记住：只有 `run_code` 能直呼，`ops_*` 经 SDK 绑定 ⇒ 任务书写“在 `run_code` 里调 `tools.read` / `tools.write` / `tools.ops_bash`”，不写“用 `read` 工具”。
- **catalog 是会话建立时的快照**：`grant` 之后再新开会话/重派才生效；给已启动的子会话补 grant = 白干。
- 指针只封 catalog，不封文件系统读权：要真隔离，在任务书里写“禁用范围外读取”或给更窄 `cwd`。

## 4. 与 `TASK_RESULT.skills_used[]` 的对账口径（阶段 6 用）

Planner 只认两件事对得上：① 回执 `skills_used[]` 里的名字 ⊆ 上表该角色的 `skills[]`；② 写了**节号**（如 `reverse-engineering §4`），不是只写名字。
对不上 ⇒ 按 `未验证` 收：要么没给对技能（`grant` 后重派），要么 worker 走了别域（要它补证据或重做）。

## 5. gaps（本清单自身的未验证项）

- `skills_declared_not_dispatched`：本轮 `apply_skill_grants=false`，8 条 `grant` 与 1 次 `verify` **都没真跑** ⇒ 各角色实际 catalog 是否含这些条目属**无法判定**；阶段 4 派工前补跑 §3 并把 `STATUS=OK` 行贴进派工记录。
- 子档现值以 `skills/POINTERS.md` §2 为准（当前口径 9 条 grant + 1 条内置）；若有人改过指针，上表的“取哪几节”不受影响，但 `verify` 行会变，按实测记。
- 7 个角色行只覆盖阶段 4/6；阶段 8 的 reporter 与阶段 7 的 `ops-ptc` 修复不在本清单（见 §1 末段）。
