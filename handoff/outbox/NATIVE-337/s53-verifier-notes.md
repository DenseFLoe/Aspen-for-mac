# #445 的多文件清单关联

固定 `tool/s37_two_hop.py` SHA-256 `a2ed873660620bf468db10f6716c812c9ef207c6972e21622411b7ff00a6c271`，`tool/pe_reader.py` SHA-256 `c0efbbffc93a0331b86dab66f93564a846890c479edad58e1ac59247053c8037`。使用 [#445 固定提交](https://github.com/DenseFLoe/Aspen-for-mac/tree/32ce7e38ca2ec72a31007b09c66ec847285e3071) 和 [输入指纹](s53-layout.json)。

1. 按固定文件运行 `python -B tool/s45_tests.py`，得到四项通过。
2. 在固定输入的新副本里，把 `code/native.asm` 第 199–226 行移到 `code/native-part.asm` 的第 19–46 行。原位置每行换成注释，第二文件前置 18 行注释。保持其余清单指令、行位及原件内容。
3. 将 `calls.csv` 中指向被移区间的引用改为新文件名，并减去 180 行。保留 CSV 数据行顺序。
4. 对原和拆分副本分别执行 `python -B tool/s37_two_hop.py --folder CANDIDATE --binary ORIGINAL --out RESULT.csv`。核对 0x106C 和 0x12DA 的路径、行号及 `calls_row`。

原布局 0x106C 指向第 525 行，0x12DA 指向第 528 行。拆分后两个地址的清单行号均为 28，文件路径不同。实测退出 0，两个地址皆指向第 525 行，且总数仍为 161。调用表按适用标准须能定位到对应清单和真实引用。当前生成器的索引只保留行号，造成按文件拆分时串行，需人工重对调用行。

建议以相对路径和行号组合定位，同一定位仍有多行时再比对候选宿主和导入符号，无法消歧时明确报告。回归用例复跑上述两版，均应为 161 站，0x12DA 固定指向第 528 行，0x106C 固定指向第 525 行。单文件历史摘要按原用例继续核对。
