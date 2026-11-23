# NATIVE-337 s73 提交（字节级核对 + 四个未决调用真解）

- 固定候选：#445 @ 12bca3ef；同一分支 head 前移。

## A. 字节级核对
### 站集导出来源（只用原件）
~~~sh
PYTHONPATH=D:/Lib/site-packages python -B tool/s73_stations.py
# stations 161 -> handoff/inbox/NATIVE-337/code/s73-stations.csv
~~~
做法：capstone 线性解码原件各可执行段，取 E8/E9 rel32 且目标处为 `FF 25 [rip+disp]` → IAT 槽，按站点 RVA 去重。输出 161 站（与候选 161 站一致），每站含 site/first_hop/iat_slot/import_symbol/site_bytes。

### 逐站字节核对
分类器对每站读取**候选清单该行的真实指令字节**，与原件同址字节整串比较；不一致即 `byte-mismatch` 并报出两个十六进制串。

| 反例 | 实测 |
| --- | --- |
| 第 28 行单改一字节 `E8 32 3A 00 00` → `E8 33 3A 00 00` | `byte-mismatch = 1，site=0x106C，candidate e8333a0000 != original e8323a0000` |
| 删该站清单指令（且旧站表缺失） | 仍报 `missing-listing = 1，site=0x106C`；若连基准站集输入都没有，分类器直接报 `missing verifiable baseline input` 并退出非 0 |

### 三布局
单文件 / 同目录拆分 / 子目录拆分：161 站、0x106C→525、0x12DA→528（s45_tests.py E/F）。

## B. 四个未决调用（0x1320 内）
| 站 | 指令 | 接收者 | vtable 来源 | 槽 | 成员 | 初始化路径 |
| --- | --- | --- | --- | --- | --- | --- |
| 0x1389 | CALL qword ptr [RBX+0x28] | RBX | 0x1354 MOV RBX,[RDI] | 0x28 | GetIDsOfNames | 0x1338 CALL 0x180002330 → RDI |
| 0x1396 | CALL qword ptr [RAX+0x10] | RAX | 0x1390 MOV RAX,[RDI] | 0x10 | Release | 同上 |
| 0x1444 | CALL qword ptr [RBX+0x30] | RBX | 0x1400 MOV RBX,[RDI] | 0x30 | Invoke | 同上 |
| 0x1457 | CALL qword ptr [RDX+0x10] | RDX | 0x1451 MOV RDX,[RDI] | 0x10 | Release | 同上 |

- 对象来源：0x1338 调工厂 0x180002330，返回接口指针存 RDI；工厂体内 0x2388 调 `[0x180007050]`（CoCreateInstance 导入）。
- 能绑定到：槽位 + 成员 + 数据来源（RDI 指向的接口对象）。
- 绑不到实现地址：对象运行期创建，需在 0x1354/0x1390/0x1400/0x1451 断点取 vtable 或加载 CLSID 类型库；这是已证边界，已写进 code/s73-four-calls.csv 的 recovery 列。

## 判定（原始 stdout）
~~~
checked 307 coverage rows, 307 tool-native entries, 684 call records, 0 declared gaps
~~~
exit code: 2（112 条 unresolved 已申报）

## 工具指纹（按固定 head 实际值更正）
- tool/s73_stations.py、tool/s65_counterexamples.py、tool/s69_tests.py：见 work/s73-tools.txt
- tool/pe_reader.py **5383333399175b94f3624d5ef95db2fbffdc1d8c0f23b6983ef3cc01e4e87367**（此前回执误写 c0efbbff）
