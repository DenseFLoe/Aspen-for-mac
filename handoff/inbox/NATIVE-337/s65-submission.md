# NATIVE-337 s65 提交（三类反例逐站明细）

- 固定候选：#445 @ 6a611c74；同一分支，head 前移。
- 分类器：`tool/s65_counterexamples.py`（按站点逐址重建 首跳/IAT/符号，再与 calls.csv 的(完整相对路径,行号)关联）。

## 三类计数（实际数据）
| 类别 | 命中站点 | 明细 |
| --- | ---: | --- |
| 无匹配行 | **0** | 0 站；161 站的 (路径,行号) 均能命中主表 |
| 多个等价匹配行 | **0** | 0 站；同键多行且都能用同一导入符号解释的情况未出现 |
| 声明目标与原件矛盾 | **0** | 0 站；主表 callee 与原件推导符号一致 |

逐站明细（161 行，含 category/ok）见 `code/s65-counterexamples.csv`；三类为空是因为实际无异常，不是没跑。

## 分类器自检（证明能检出，而非恒为 0）
注入三类异常后重跑分类器：
~~~
SELFTEST missing-row          hits=1 PASS
SELFTEST multiple-equivalent  hits=1 PASS
SELFTEST contradiction        hits=1 PASS
SELFTEST overall PASS
~~~
（注入方式：删掉 code/native.asm#L28 行 / 复制该行 / 把该行 callee 改成 KERNEL32.dll!GetLastError）

## 三布局回归
- 单文件 / 同目录拆分 / 子目录拆分：均 161 站，0x106C→525，0x12DA→528（s45_tests.py 场景 E/F）。

## 判定（原始 stdout）
~~~
checked 307 coverage rows, 307 tool-native entries, 684 call records, 0 declared gaps
~~~
exit code: 2（112 条 unresolved 已申报）

## 指纹
- tool/s37_two_hop.py 7b68263b476267db9c19c5dd2fd055b901b011a748545ef27bbe41fa9068d927
- tool/s45_tests.py 4e5a3401d1048b525016aaa13283d3db416e43746fbcd7d4108aaec8f22c0371
- tool/pe_reader.py c0efbbffc93a0331b86dab66f93564a846890c479edad58e1ac59247053c8037
