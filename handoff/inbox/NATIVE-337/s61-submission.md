# NATIVE-337 s61 提交（完整相对路径 + 行号关联；三布局）

- 基线：#445 @ fdad14b1；同一分支，head 前移。

## 关联修复
- 键从「文件名+行号」改为 **calls.csv 里的完整相对路径 + 行号**（如 `code/native.asm#L28`、`code/sub/native-part.asm#L28`），并从仓库根可解析。
- 清单扫描改为 `code/**/native*.asm`（rglob），子目录布局也能发现站点。
- 同键多行时用导入符号（callee/note）消歧；仍歧义则置空并计数，不静默挑一个。本轮 `ambiguous_calls_row=0`、`missing_listing_ref=0`、blank calls_row=0。

## 三布局实测
| 布局 | rows | 0x106C | 0x12DA | 输入 SHA-256 | 输出 SHA-256 |
| --- | ---: | --- | --- | --- | --- |
| 单文件 | 161 | code/native.asm#L28 → 525 | code/native.asm#L208 → 528 | cb99ee3a… | 2ef4b467… |
| 同目录拆分 | 161 | code/native.asm#L28 → 525 | code/native-part.asm#L28 → 528 | 8df61195… | 8cf6698d… |
| 子目录拆分 | 161 | code/native.asm#L28 → 525 | code/sub/native-part.asm#L28 → 528 | 41ee1434… | e2bd418c… |

子目录布局的相对路径 `code/sub/native-part.asm` 从仓库根可解析（测试 F 断言 ref_resolvable=True，且实际文件存在）。

## 判定（原始 stdout）
~~~
checked 307 coverage rows, 307 tool-native entries, 684 call records, 0 declared gaps
~~~
exit code: 2（112 条 unresolved 已申报）

## 工具指纹
- tool/s37_two_hop.py  7b68263b476267db9c19c5dd2fd055b901b011a748545ef27bbe41fa9068d927
- tool/pe_reader.py    c0efbbffc93a0331b86dab66f93564a846890c479edad58e1ac59247053c8037
- tool/s45_tests.py    4e5a3401d1048b525016aaa13283d3db416e43746fbcd7d4108aaec8f22c0371
