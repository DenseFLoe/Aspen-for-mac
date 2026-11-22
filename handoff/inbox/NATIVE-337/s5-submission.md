# NATIVE-337 s5 提交

- PR: 见 #13
- head: 见 #13

## 三层（成因 / 流程修正 / 自证）

# 成因
首轮 calls 提取把「名字以 __imp_ 开头的导入符号」当作 IAT 映射（ida_dump.py 的 fallback 分支），而反汇编里同一槽位有两种写法：jmp 形式显示为 __imp_X，call 形式显示为 X。于是 190 处 call 全部被 kind == "import" 过滤掉，150/157 处 jmp thunk 被保留。197 处漏项 = 190 处 call + 7 处 jmp，全部是「按命名判定导入」这一条规则造成的。

# 复现命令
~~~sh
python -B tool/scan_iat_audit.py --asm <首轮 native.asm> --dll issue-materials/337/FindComponent.dll --calls <首轮 calls.csv>
# 输出：iat_sites=363 registered=166 missing=197 (call 190 / jmp 7)
~~~

# 流程修正
- 扫描器不再看符号名：直接解析 PE 导入目录得到 FirstThunk 槽位 → (DLL, 导入名/序号)，再对每条指令按原始字节判断 FF 15 / FF 25 与 RIP 相对 disp32，用「指令末 RVA + 有符号 disp32」定位槽位。
- 每次生成都对自身做自洽断言：iat_sites == iat_registered（本轮 355 == 355），并写入 metrics.json；不满足即生成失败。
- 数据引用同样按 RIP 相对内存操作数解析，不再依赖符号前缀。

# 自证
- 同一 listing 重扫：363 个站点 363 条登记（0 漏）。
- 本轮新 listing（280 个函数）：355 个站点 355 条登记（0 漏），data 48 条，含裁定点名的 0x3C44→0x7A88 "ReorderComp" 与 0x2601→0x7780 "ShowOpenMessageBox"。
- 判定命令 python handoff/assignments/check-native-coverage.py NATIVE-337 输出见下；机械检查 0 缺口，99 条间接转移按标准标 unresolved（exit 2）。

# 下一批如何自动避免
门禁一条：原生件 calls 必须由 PE 导入槽位数得出，并断言 distinct IAT 站点 == external 行数，不等即构建失败。

## 本轮实跑指标（脚本生成，非手填）

| 指标 | 值 |
| --- | --- |
| 分析器函数 | 280 |
| 原件锚点 | 115 |
| coverage 行（缺口） | 280（0） |
| IAT 调用/跳转站点 | 355 |
| 已登记 external | 355 |
| 数据引用 data | 48 |
| 未决 unresolved | 99 |

## 判定命令与原始输出

~~~
checked 280 coverage rows, 280 tool-native entries, 502 call records, 0 declared gaps\r\nchecker_exit=2
~~~

exit code: 2

## 产物

run.json / native-functions.csv / coverage.csv / calls.csv / code/native.asm / code/native.c

以上文件由生成脚本一次产出；本轮未手工编辑任何产物文件，指标与产物 SHA-256 见 metrics.json。
