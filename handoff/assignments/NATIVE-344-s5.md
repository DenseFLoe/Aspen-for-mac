# Simdll.dll 第五号任务

upstream 领取 NATIVE-344，assigned_seq=5，时限为本轮 #13 ACK 后 24 小时。固定输入为提交 `64670801de54e990f975aaeda06e89340c0e4e08` 的 `issue-materials/344/Simdll.dll`，SHA-256 为 `9b762caf68ad02f296eb3d98d9995af91adbd572f7c00acb88f4afc5fe88d601`。原路径、版本与首轮范围见[原任务卡](NATIVE-344.md)和[首轮裁定](../outbox/NATIVE-344/s1-decision.md)。

首轮 1,360 个缺口中，401 个六字节函数从入口直接跳往可确定的 PE 导入槽。原件及 COFF 重组已逐字节确认这些入口，包括首轮引用表遗漏的 45 处。[逐址清单](../outbox/NATIVE-344/s5-import-thunks.csv) · [重组和资源复核](../outbox/NATIVE-344/s5-recovery.json) · [复查脚本](../outbox/NATIVE-344/check-import-thunks.py)

给这 401 个入口提供可编辑实现和原始指令，逐件关联 DLL、导入名或序号、IAT 槽和函数入口。补齐引用表并保留已验证的旧证据，为其余入口保留逐址缺口。9 类 50 个资源已复核身份与字节指纹，按整件要求继续核对必要资源和使用关系。按[上游原生覆盖标准](../standards/native-coverage-upstream.v1.md)运行 `python handoff/assignments/check-native-coverage.py NATIVE-344`，在固定原件上独立复跑重组。将开工、交付分别记入 `handoff/inbox/NATIVE-344/s5-started.md` 和 `s5-submission.md`，#13 回报 head。
