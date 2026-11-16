# button-logic-20261116

按钮间逻辑关系的第三轮逆向分析（运行控制／导航／撤销重做／报告／组分页其余入口），并给出全量按钮差集与未确认清单。仅分析，不含移植实现。

- [report.md](report.md)：关系图谱、RC/NV/UD/UC/RP 五簇结论、未确认清单与待动态验收案例。
- [report-continued.md](report-continued.md)：续轮逐条确认（状态真值表、向导提交模型、PFS 撤销栈、NextHit、重初始化链）与对前轮的更正。
- [evidence-index-confirm.json](evidence-index-confirm.json) / [checks-confirm.json](checks-confirm.json)：续轮索引与 24 项检查（全过）。
- [report-round3.md](report-round3.md)：第三轮（分析按钮簇互锁、StoreValue 通用提交钩子、ModelLibrary 撤销、状态位解码）。
- [evidence-index-round3.json](evidence-index-round3.json) / [checks-round3.json](checks-round3.json)：第三轮索引与 16 项检查（全过）。
- [evidence-index.json](evidence-index.json)：11 个安装源哈希、316 个方法 token/RVA、3 个原生入口、字符串归属。
- [checks.json](checks.json)：18 项一致性检查（全过）。
- [verify_evidence.py](verify_evidence.py) / [reproduce.py](reproduce.py)：复算与重提取入口。
- [inventory-summary.json](inventory-summary.json) / [shell-command-inventory.json](shell-command-inventory.json)：双轨差集摘要。
- [validation.md](validation.md)：核验结果、工具陷阱与资产边界。

大体积 IL/native 提取与反编译阅读辅助在 `.local/button-logic-exploration-20261116/`（不入库）。前两轮：[wizard-logic-20261115](../wizard-logic-20261115/report.md)、`.local/other-button-logic/report.md`。