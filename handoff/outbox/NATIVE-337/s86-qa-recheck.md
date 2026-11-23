# NATIVE-337 s86 QA 补证复核

本补证对应 [#445 固定候选](https://github.com/DenseFLoe/Aspen-for-mac/tree/a93daa5523ab7865228ce73c279bc69f2d3e020c/handoff/inbox/NATIVE-337) 和 [QA 13fe04a5](https://github.com/DenseFLoe/Aspen-for-mac/tree/13fe04a534dfaad3c896e2230d0139f6c1533a0a/qa)。s86 清单重新读取 111 个声明路径，逐一匹配 Git blob 和 SHA-256。交付文件里的 stdout 报 109 个声明路径，这两个计数的口径对应关系待核。本轮裁定仍沿用 s85，s89 续领继续有效。

运行 `python -B handoff/outbox/NATIVE-337/s86-qa-sync-replay.py`。输入是固定 QA 树的 28 个文件与 s86 清单指向的文件。两次均在新目录重放固定的 `qa/sync.py`，只替换网络读入为固定树的核验字节。同步器 SHA-256 为 `f52f21c29c3d4d2c1f98d926e7dbe72fea9b3e86e33e28ce704d260d145ac4ea`。

- 同版本、同文件集合的版本指纹应一致。13fe04a5 把 `generated_at` 写入被哈希的清单，两次清单 SHA-256 不同，排序后的文件记录 SHA-256 相同。实测两次路径均完整，未复现截断文件名。
- 复验后继版见 NATIVE-340 s77 记录。786fec74 的两个独立输出目录各有 27 个文件，版本 SHA-256 一致。回归用例是固定 27 文件，在两次不同时间同步，核对全部路径和文件指纹，并要求版本 SHA-256 相同。

[复核原始结果](s86-qa-recheck.json) · [前轮裁定](s85-decision.md)
