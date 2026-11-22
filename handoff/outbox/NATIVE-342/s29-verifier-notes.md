# ApwnIPShell.dll s29 验收器复核

覆盖证据 v1 使用固定主干 `e3b3049622bbefa9241099561a8fadd35a9b25c1`，SHA-256 `27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8`。原件与输入指纹见[对照记录](../../inbox/NATIVE-342/s29/coverage-control.json)。

复跑 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE`。从同一交付复制一份控制候选，只在 `s29/appid-tail.c` 将 `[rax + 0x18]` 改为 `[rax + 0x20]`，刷新指纹清单及回执摘要，并分别用两份目录执行该命令。依据覆盖标准，声明覆盖的源码须和原 RVA 的实际操作数相符，修改后应被判为证据不一致。两份覆盖检查却均输出 `checked 1005 coverage rows, 1005 tool-native entries, 7433 call records, 290 declared gaps`，退出 2。局部回编在固定原件上正确交付退出 0，修改交付退出 1。该现象延续 [s21 的操作数核对缺口](s21-verifier-notes.md)。新对照验证了间接尾跳的虚表位移，需补跑回编才可采信覆盖声明。

建议对声称已回编的条目校验机器码及重定位目标，把覆盖缺口和源码不一致分别报告。回归用例沿用本轮这两份源码。预期正确源码保留 715 个已覆盖入口，修改源码报出 0x33a34 的间接操作数不一致。
