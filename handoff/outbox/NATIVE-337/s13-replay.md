# FindComponent.dll 第十三号复跑

从 #411 固定 head `43017ac0901a450784de1678b55d2f501641b75c` 取候选 `handoff/inbox/NATIVE-337`，从 `a180dcfd1b6bd39072a4a03b94b908408e6da426` 取同路径基线。固定原件及路径见[任务卡](../../assignments/NATIVE-337-s13.md)。保留主干 `63f12578ef185f22e72b01076e81420b595a9499` 的已确认检查器及 [上一轮的地址输入](pr394-addresses.csv)。候选快照的 `handoff/assignments/` 下放已确认的检查器，然后运行：

```text
python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original <FindComponent.dll>
```

实际返回 2，标准输出 `checked 290 coverage rows, 290 tool-native entries, 510 call records, 0 declared gaps`。独立对照使用 Python 3、pefile 2024.8.26 和 Capstone 5.0.7：

```text
python -B check-s13.py <FindComponent.dll> <候选本件目录> <基线本件目录> <pr394-addresses.csv> <check-native-coverage.py>
```

对照输出 [s13-recheck.json](s13-recheck.json)。[逐址附件](s13-sites.csv)中的 candidate_class 表示候选记录，旁列另给出原件结论。
