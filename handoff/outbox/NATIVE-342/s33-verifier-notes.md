# ApwnIPShell.dll s33 验收器复核

覆盖证据 v1 固定在主干 `2d13d4e28bffd770252e8e0c4bb491bdf256a4f6`，脚本 SHA-256 `27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8`。以[配对记录](../../inbox/NATIVE-342/s33/coverage-control.json)中的同一原件与正确交付运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE` 和 `python -B handoff/inbox/NATIVE-342/s33/check-delay-wrapper.py ORIGINAL ZIG`。

将候选 `s33/delay-load-wrapper.c` 中的重定位符号 `rva_49320` 改为 `rva_49340`，更新清单中的源码指纹及交付回执中的清单指纹。按上游原生覆盖 v1，源码应使用原件中实测的描述符地址，改动后应报证据不一致。覆盖检查对两种输入均输出 `checked 1005 coverage rows, 1005 tool-native entries, 7433 call records, 289 declared gaps` 并退出 2。局部回编对正确输入退出 0，对改动后的输入退出 1。新增证据定位到 0x33c66 的描述符 REL32 目标，延续 [s21 操作数核对缺口](s21-verifier-notes.md)。

建议在标明已回编的行校验源码机器码与重定位指向的一致性，分别报交付证据不一致和已声明缺口。以上配对输入作为回归，期望正确交付保留局部覆盖，改动交付定位 0x33c66 的描述符目标差异。
