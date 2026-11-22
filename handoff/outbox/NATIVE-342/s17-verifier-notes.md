# NATIVE-342 s17 验收器对照

任务卡覆盖 v1 与 [NATIVE-350 的同轮记录](../NATIVE-350/s37-verifier-notes.md)为同一固定版本。命令 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission UNIT`。

同一原件和候选，只在对照副本把 `s17/unwind.csv` 中 `0x33b34` 的 parent_begin 从 `0x33af8` 改为 `0x33ad5`，更新清单与回执指纹。原件 `0x48de0` 对应的 CHAININFO 起点为 `0x33af8`。两份候选的覆盖工具均为 1005/1005/7433/293、退出 2，错误父帧需要人工对照。以后读取原件异常目录时比较 parent 起点、终点和 unwind RVA；同一配对中，原候选应保留整件缺口结果，控制副本应定位错误父帧。[复跑记录](s17-chain-control.json)
