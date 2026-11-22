# NATIVE-342 第五号事件续领

owner 为 upstream，assigned_seq 为 5，时限为本轮 #13 ACK 后 24 小时。原件为 `issue-materials/342/ApwnIPShell.dll`，固定提交 `64670801de54e990f975aaeda06e89340c0e4e08`，SHA-256 为 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。[原件与路径](NATIVE-342.md) · [首轮裁定](../outbox/NATIVE-342/s1-decision.md)

复查已从原件的比较指令、间接跳转和表字节中定位 7 张跳转表。首轮 5 个顺序解码停止位置均落在这些表的数据内。[各表的边界、指令字节、默认分支和目标 RVA](../outbox/NATIVE-342/s5-recovery.json)

在完整原生分析中标出表区，重建各分支及后续控制流，先核对 0xdad0、0x12bc0、0x1fe50、0x21b90 和 0x22ad0 五个入口。逐址核对其余原件锚点、分析器新增入口、可编辑实现以及外部调用和重要数据。首轮 801 个缺口须按地址说明解决情况，沿用已核实的 12 个短函数及 SetHelpFile 调用证据。

开工与提交写入 `handoff/inbox/NATIVE-342/s5-started.md` 和 `s5-submission.md`；修订材料以新提交保存。[原生覆盖标准](../standards/native-coverage-upstream.v1.md)及仓库根目录的判定命令 `python handoff/assignments/check-native-coverage.py NATIVE-342` 适用。复查来源及版本、核对实际代码后另行裁定整件静态验收。
