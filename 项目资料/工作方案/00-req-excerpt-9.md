---
task_id: 20261121-0145-REQ-excerpt9
type: result
sender: aspen-batch (ds4.1f)
reply_to: handoff/incoming/
source: 00-req.md §9 (verbatim excerpt, redacted)
---

## 9. 目标升级（2026-11-20 23:4x，用户明确指令，覆盖 §8 的「native 只出骨架」）

**交付物从「逐件报告骨架」升级为「完全反编译 + 反汇编正文」，全部上传仓库。**

- **托管件（CLR，当前 31 件）**
  - 反汇编：全程序集 IL 清单（每 MethodDef：令牌、RVA、IL 偏移、操作码、解析后的操作数目标）+ 元数据摘要（TypeDef/MethodDef/Field/MemberRef/ImplMap 计数与定位）
  - 反编译：ILSpy 9.1.0 全程序集 C#（含 P/Invoke 声明）
- **原生件（native PE，当前 19 件）**
  - 反汇编：Ghidra 12.1.4 全函数反汇编清单 + 导入日志（语言/基址/块）
  - 反编译：Ghidra Decompiler 全函数伪 C（逐函数，带地址与函数名）
- **非 PE（.obj/.lib，当前 8 件）**：`unsupported_non_pe` + 已尝试工具与原始报错，不伪造产物。

### 9.1 与仓库 AGENTS 的冲突（用户已授权，必须记录）

仓库 `AGENTS.md` 写「禁止上传…完整逆向正文」；用户 2026-11-20 明确要求上传汇编与伪代码 ⇒ 按用户指令执行，但：
1. 只推 `codex/20261120-batch-review`，**不合并 main、不改默认分支**；
2. 每份产物同名 `.md` 写明「含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条」；
3. 推送回执单列该偏离项供人复核。

### 9.2 体积与提交规范

| 项 | 约束 |
| --- | --- |
| 单文件 | ≤5 MB 明文；超出 `gzip -9` 存 `.txt.gz`，`.md` 写解压命令 |
| commit | 逐件提交，message 带 `round=20261120`、件名、产物类型 |
| 目录 | `analysis/20261120-batch-driver/<product>/<原相对路径>/` 下 `disasm|il/`、`decompiled/`、`<原全名>.md` |
| 索引 | `INDEX.md` + `index.csv`（件名、产品、哈希、类型、产物清单、字节数、状态） |
| 隐私 | 产物内不得出现本机绝对路径/用户名/凭据；Ghidra/ILSpy 输出的路径字段必须脱敏 |

### 9.3 追加验收判据

| id | 判据 | 核法 |
| --- | --- | --- |
| D1 | 31 个 CLR 件各有 IL 清单 + 全量 C#（行数>0、含 class） | 脚本断言 + 抽 2 件看 |
| D2 | 19 个 native 件各有 Ghidra 反汇编 + 伪 C（函数数>0） | 脚本断言 + 抽 2 件看 |
| D3 | 8 个非 PE 有 `unsupported_non_pe`（工具+原始报错），无伪造产物 | grep 断言 |
| D4 | 远端读回：每件目录两类产物齐全，`INDEX.md` 行数 = 参与件数 | API 读回计数 |
| D5 | 不碰 main、只推 codex 分支、原件不上传 | before/after main sha + 清单审阅 |