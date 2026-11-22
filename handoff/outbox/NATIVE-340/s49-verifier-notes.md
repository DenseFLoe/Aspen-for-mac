# NATIVE-340 s49 复验

候选 `ac9d6b69cdcfe99f9b2147e0c8c12f01787bae93`。方法体读取器 SHA-256 `0e17e2ef6d9359061fbca97b2788abbb02ba41c63c9e3bb459ea8d2cee6436df`，审计 SHA-256 `a77bdc927b6693c90fa8cd7cde141523c3c0990b5595d83b7437aa74fe40efdc`。完整指纹、正反对照与两次重跑见 [s49-recheck.json](s49-recheck.json)。

- [s45 长链缺口](s45-verifier-notes.md) 的 9／10 节用例已通过。以 `python -B handoff/outbox/NATIVE-340/s49-eh-bounds.py CANDIDATE_ROOT` 复验交替 small/fat 布局。全映射的 276 字节夹具应通过。范围缩到 272 字节时应报末条子句超出可读取范围，实测仍返回 10 条子句。依据 [ECMA-335 II.25.4.5](https://www.ecma-international.org/wp-content/uploads/ECMA-335_6th_edition_june_2012.pdf) 的段大小及条款布局。读取前验证完整映射、文件范围和已声明的长度。两个旧布局断言须更新为核对两节、两条子句及其实际字段。
- 单独复制固定交付，保留原件及所有其他字节，只将调用表 0x20CC 行中的 `jge 落空 → al=0` 改为 `jge 取跳 → al=1`。运行 `python -B tool/audit_340_s49.py --binary ORIGINAL --folder CANDIDATE_COPY`。预期根据原件重新生成主表中的分支事实，实测 exit 0 且错误句仍在，输入和输出调用表 SHA-256 完全相同。用原件解析结果生成主表及引用该行的附表，并在回归中验证错误说明被更正、完整重跑保持幂等。
