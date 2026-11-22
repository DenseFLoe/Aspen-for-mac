# NATIVE-342 s13 覆盖检查器记录

固定覆盖检查 v1 为主干 6dc117d44415c89b2d5919be0788120604bc4858 的 `handoff/assignments/check-native-coverage.py`，Git blob `e0b5e9c4617c9fdff9ba8d3179b60f7abad52979`，SHA-256 `27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8`。原件、正常候选及改动行的指纹见[对照实测](s13-operand-control.json)。

用同一份固定原件，复制 [s13 候选](../../inbox/NATIVE-342/s13-submission.md)。在副本 calls.csv 的 0x397ea 行只把 callee 栏的 `[rax+0x38]` 改成 `[rax+0x30]`，重出该文件的清单指纹。对两个目录分别运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE`。两次都退出 2，均为 1,005 个原生入口、7,433 条引用和 301 个缺口，未报告槽错误。

[原件清单](../../inbox/NATIVE-342/s13/instructions.lst) 的 `ff5038` 对应 0x38。按[原生覆盖标准](../../standards/native-coverage-evidence.v1.md)，有证据的操作数必须与原件一致。当前检查会验证引用行出现 call/jmp，槽位语义还需人工核对。

建议由候选提供结构化站点 RVA 和间接操作数，从相应原件指令比较寄存器、位移和大小。回归重放上面的单字段对照。原件与候选均为 0x38 时保留整体待修的退出 2，只改候选位移为 0x30 时报告 0x397ea 的字段差异并退出 1。
