# s1-submission · NAG-GENERATOR-373-FIX

## 判定命令与原始输出

```
cd _work/wf-20261120-aspen-batch
python -B handoff/assignments/check-generator-revision.py
```

- exit code: **2**
- stdout: （空，无任何输出）
- stderr: `missing or invalid evidence: full lower-case commit SHA required`

该 2 是任务卡允许的唯一原因：`results.json` 的 `pr_head` 为 `PENDING_MAIN_AGENT`（本机无远端提交可填，判定器第一步 `commit_id()` 要求 40 位小写 SHA）。未出现其它输入、来源、日志或指纹错误——判定器在读取 `results.json` 后立即停在 `pr_head` 校验，其后的夹具字节比对与三源摘要校验均未执行，因此另跑下面这条等价校验。

## 等价校验（同一 check() + 本地摘要 + 占位 40 位 head）

```
python -B handoff/inbox/NAG-GENERATOR-373-FIX/verify-local.py
```

- exit code: **0**
- stdout:
```
refs: ['0123456789abcdef0123456789abcdef01234567']
failures: []
PASS
```

即：2 个生产写入口 × 10 个固定用例 × (首次/二次字节 + 存在性 + 写前/写后门禁退出码) 共 20 组断言零差异；`fixtures.json` 与旧夹具逐字节相同（判定器 `fixture == baseline["fixtures"]()` 通过），`run.log`/`results.json` 摘要自洽。

## 真实双次写入（重放器）

```
python -I -B handoff/inbox/NAG-GENERATOR-373-FIX/replay.py
```

- exit code: **0**，无 stdout；真实写出 `run.log`（14395 字节，`94bc917cf60a161ae4f82a25915e2fe72bb2330c7834d66598ae9f9ed1ac9b11`）与 `results.json`（7146 字节，`021cc4f9e932b23f7118e3c43bf2d1d494d4a0d4a9db66b4e97019da74ad5c30`）。
- 每组：新目标目录首次写入 → 把首次输出原始字节送回同一入口 → 二次写入；两个目标均实际存在（含 0 字节用例）；门禁以独立进程跑完整 `tool/check_cs_clean.py`。

## 三份新源文件实际 SHA-256

| 文件 | 新 SHA-256 |
| --- | --- |
| tool/b2_wave.py | `615e67f0b8766da9571b8810f81daf84556426b8e5d8f4685b300b6585d43969` |
| tool/batch_reverse.py | `5d8df77940b57d8231bccbce93bfa1ce28ab02145972eed8337d53ba4f1a853a` |
| tool/check_cs_clean.py | `c6751f1a3b6ac426b998f4cfa8e41fd000be05ae06288fba79fdab96c2b6fb8c` |

未引入共享助手，故无 `additional_sources_sha256`。

## 文件清单（handoff/inbox/NAG-GENERATOR-373-FIX/）

| 文件 | 字节 | SHA-256 |
| --- | --- | --- |
| fixtures.json | 1795 | `bdfc2ae821e1d202e227ecace50656c34b879e055c35124a33d7b1a04e3aeb11` |
| results.json | 7146 | `021cc4f9e932b23f7118e3c43bf2d1d494d4a0d4a9db66b4e97019da74ad5c30` |
| run.log | 14395 | `94bc917cf60a161ae4f82a25915e2fe72bb2330c7834d66598ae9f9ed1ac9b11` |
| review.md | 7699 | `96c7e14122f2c7c63c5ca79e0a5a9df4d708684ae06bb012675d2deb2400efca`（预期 vs 实得指纹表） |
| s1-started.md | 见文件 | — |
| s1-submission.md | 本文件 | — |
| replay.py | 8217 | `b8c77a43645ae38a9b6db28b365ec6be2e38a6bffada158eabdb6465d662595f` |
| verify-local.py | 1561 | `a2de37884a82b649c642879d5a9a522cfa8d60c71e7fe4d20d910fd78ef1d716`（本地等价校验器） |
| sample.cs.txt | 1439 | `2ceba82a4d3bb35449fb475d8946274afa91dd04f5914f2fd245f09d75336886` |
| _original/{b2_wave.py,batch_reverse.py,check_cs_clean.py} | — | 原版三件备份（= 任务卡原始 SHA-256） |

受验代码树（本机工作副本）：`_work/wf-20261120-aspen-batch/tool/{b2_wave.py,batch_reverse.py,check_cs_clean.py}`。

## 限制

1. **pr_head 未定**：不能 push/commit 到远端，`pr_head=PENDING_MAIN_AGENT`。主 agent 推送后须把该字段改成真实 40 位 SHA，并用 `--expected-head` 复跑判定器；若推送字节与上表不同，须重跑 replay.py（会重写 run.log 与 results.json，含 `run_log_sha256`）。
2. **未调用真实 ILSpy/.NET**：`dotnet` 由真实子进程按固定字节回放 stdout（与旧审核 replay 同方法），未执行原始 DLL；因此 20 组的"ILSpy 输出"是固定的已审工件字节。
3. 本机 Windows 10.0.26200 + Python 3.13.5（旧审核为 10.0.20348 + 3.12.14），字节与退出码结果一致。
4. 存量 455 份单文件交付不在本次范围（任务卡明确另案）。
