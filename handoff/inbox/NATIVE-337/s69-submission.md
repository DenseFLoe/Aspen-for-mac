# NATIVE-337 s69 提交（精确符号身份 + 三个可证伪测试）

- 固定候选：#445 @ 25ecf964；同一分支 head 前移。

## 1. 符号判等改为精确身份
- `same_symbol()`：`callee` 与原件推导的 `DLL!name|#ordinal` **整串等值**（去空白、大小写无关），不再用子串。`#2344` 与 `#23440` 因此不再互认。
- 生成器消歧同样改为整串等值。

## 2. 三个可证伪测试（tool/s69_tests.py，一次跑完）
| 注入 | 预期 | 实测 |
| --- | --- | --- |
| 仅把 0x106C 声明改成 mfc140.dll!#23440 | 矛盾恰为 1 | contradiction=1，site=0x106C，PASS |
| 仅移除该站清单指令 | 保留明确缺口或报明 0x106C | missing-listing=1，site=0x106C，PASS |
| 同上情况下的覆盖 v1 | exit 1（拒绝） | exit=1，`call site reference lacks instruction`，PASS |

exit 1 是**预期结果**：单站失去清单证据时，检查器应当拒绝，而不是当作通过。

## 3. 三布局重放
- 单文件 / 同目录拆分 / 子目录拆分：161 站、0x106C→525、0x12DA→528（s45_tests.py E/F）。
- 正常候选覆盖 v1：exit 2，307 rows / 307 entries / 684 calls / 0 declared gaps。

## 判定（原始 stdout）
~~~
checked 307 coverage rows, 307 tool-native entries, 684 call records, 0 declared gaps
~~~
exit code: 2

## 指纹
- tool/s37_two_hop.py 604bb62d2b47a2c87e1b16ad14b820cd31a1d019e65cd5a668b4ce573e853bce
- tool/s45_tests.py 4e5a3401d1048b525016aaa13283d3db416e43746fbcd7d4108aaec8f22c0371
- tool/s65_counterexamples.py 89ceca2e4d32a812875f6ef4901551c2d79530021172192ce26dda7a97fffb0d
- tool/s69_tests.py 0f8e1c939ad14e201ba9807727e27062336c364671d1431ed4aa35e9b85b5e99
- tool/pe_reader.py c0efbbffc93a0331b86dab66f93564a846890c479edad58e1ac59247053c8037
