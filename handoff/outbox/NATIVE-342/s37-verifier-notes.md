# ApwnIPShell.dll s37 验收器复核

覆盖证据 v1 固定主干 d29e63566fa3969bc38837b38fddcb1f9ff5c044，脚本 SHA-256 27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8。对[配对记录](../../inbox/NATIVE-342/s37/coverage-control.json)的同一原件与正确交付运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE` 与 `python -B handoff/inbox/NATIVE-342/s37/check-com-error-copy.py ORIGINAL ZIG`。

将候选 s37/com-error-copy.c 的虚表操作数从 [rax + 8] 改为 [rax + 0x10]，更新清单和交付回执指纹。原件 0x34e21 读取 +8，改动使声明的函数实现与原件不符。覆盖检查在两份交付上均输出 `checked 1005 coverage rows, 1005 tool-native entries, 7433 call records, 288 declared gaps` 并退出 2。局部回编在正确交付退出 0，错误交付退出 1。该对照补充 [s21 已知操作数核对缺口](s21-verifier-notes.md) 的虚调用证据。

建议对声明已回编的函数核对重建指令和原件，分别报告证据不一致和已声明缺口。以上单变量回归应保留正确交付的局部覆盖，在错误交付报告 0x34e21 的虚表槽位偏差。
