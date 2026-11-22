# NATIVE-350 s37 裁定

**退回续办。** 原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`，基线 `b04042ca387010579df70bbfccbf882460435824`。候选见 [s37 交付](../../inbox/NATIVE-350/s37-submission.md)，[指纹清单](../../inbox/NATIVE-350/s37/manifest.sha256) SHA-256 `96cef36095072491926f2d20bea161e7af1ffa69c43d9fe4443404190d9a468d`。

上游独立重编 `[0x148d0,0x14902)`，50 字节、16 条指令和 3 处文本 REL32 一致。三处 ADDR32NB 调整后，原件 .pdata 记录和 8 字节 .xdata 一致。原件只接受键 1–3，就绪位为零时调用 0x14910。覆盖 v1 输出 255/255/3567/105，退出 2，26 条引用未决。整件维持未通过，s41 续查初始化器。[复跑结果](../../inbox/NATIVE-350/s37/reassembly.json) [任务卡](../../assignments/NATIVE-350-s41.md)
