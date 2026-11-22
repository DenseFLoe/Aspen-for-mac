# Ikc2Bkp.dll 第二十五号续领

NATIVE-349，owner upstream，assigned_seq=25，本轮 #13 ACK 后 24 小时。原件 SHA-256 `bba17051eb1071e5f48702f685f1d8d5d3b9f5cfd222f357e30fd0545bf00011`，来源见[第二十一号卡](NATIVE-349-s21.md)。沿用[已验证范围和四处分支](../inbox/NATIVE-349/s21-submission.md)及[复验](../outbox/NATIVE-349/s21-decision.md)。

从异常过滤器 `0x255ca` 的 `0x255f3` 直接调用 `0x249c0` 开始，复核 `0x255e1` 的 LEA 是否将 R9 指到 `0x2435c`，以及 `0x249d4`、`0x249f5` 到 `0x249f8` 的寄存器传递。查清另有无取址和间接调用，标记这条已证调用方与动态目标的证据范围。另核对可写零填充槽 `0x34980` 的读取者、取址及可能写入来源，保留剩余状态的恢复条件。

运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-349 --original <固定原件>`。附按地址的原件证据，回编新增实现并核对已恢复范围，继续记录独立的开工、提交和逐件结果。
