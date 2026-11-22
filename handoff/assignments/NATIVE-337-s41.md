# FindComponent.dll 第四十一号续领

NATIVE-337，owner tietoumiao，assigned_seq=41，#13 ACK 起 24 小时。原件 SHA-256 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`，输入 [#445@5d0b4f3](https://github.com/DenseFLoe/Aspen-for-mac/tree/5d0b4f3aae5886f7d441a7dfc5a6c64e160e7952/handoff/inbox/NATIVE-337)及[s37 裁定](../outbox/NATIVE-337/s37-decision.md)。

交付原件到 161 条二跳附表及当前回执的生成器，记录依赖版本、命令、输出路径及脚本指纹。以固定原件和当前主表在新目录复跑，预期附表摘要 `72918f68564e24dcb5e6f376bc04deacd0cc3ceece560198cfcba0a519d906bf`，当前三项证据摘要全吻合。保留已核事实和历史回执。

运行 `python -B handoff/outbox/NATIVE-337/check-s33.py ORIGINAL CANDIDATE`，并按[原生覆盖证据 v1](../standards/native-coverage-evidence.v1.md)运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original ORIGINAL --submission CANDIDATE`。交付开工、提交回执及固定 PR head。
