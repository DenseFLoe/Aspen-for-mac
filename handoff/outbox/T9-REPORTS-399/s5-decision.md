# T9-REPORTS-399 第五号交叉核对

**验收通过。** 按第五号任务卡复核 [#429 固定交付](https://github.com/DenseFLoe/Aspen-for-mac/tree/982a967dc8b79d88b54398041ee1e5e5ede3aca5/handoff/inbox/T9-REPORTS-399)，交付方在 [#13](https://github.com/DenseFLoe/Aspen-for-mac/issues/13#issuecomment-7081371664) 确认该 head。按同一 head 合入 ec3478a21d2a7e72ec07ca54be8cf22a288f6d56，从主干逐项回读开工、提交、指纹、生成器和四份报告。变更限于本任务目录。

使用上一主干 `44a6c57647e523d1176450ed7523629ad0af32bb` 的两个判定器和 `db544a6fdfb04ec60d182c311aa47d13a61d744b` 的六份固定输入。原始交叉核对重新计算并与归档 JSON 完全一致，新报告判定退出 0。两张 CSV 的 1,000 个身份逐行吻合，530 项 pass、470 项 fail、492 次原因占用，B4 的 455 项由 448 个原 pass 和 7 个原 partial 组成。

分别用完整输入目录、只含台账的独立目录重生成四份报告，两次均逐字节匹配。Tier A 的 1,000 条执行结果含 985 pass、15 fail，未覆盖 0。核对器、生成器及归档 JSON 的路径均已写入报告。回执正文有个别 Markdown 行内引号显示异常，命令块和指纹可直接读取。[复跑输入及候选指纹](s5-recheck.json)

本裁定覆盖千件预审报告。每个对象的静态验收状态仍由对应逐件证据决定。
