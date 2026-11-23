# NATIVE-340 s57 提交

- 分支：tietoumiao/native-340-s33（前移 #450，不新开 PR）
- 上轮固定 head：#450 @ 53bdbfa4685c80e41ed90a0f08e3528608ea0265
- 本轮 head：见 #13

## 1. EH 逐节三元核对（节头 / raw RVA / 文件字节）

`code/s57-eh-sections.csv`：每节给出 `header_kind`、`header_size`、**单子句宽度** `clause_width`（fat 24 / small 12）、
`payload`（= size-4）、子句数、子句类型、`more`，以及三条独立边界 `raw_end` / `virt_end` / `file_len` 与
`in_raw` / `in_virtual` / `in_file`。真件 25 节全部三项 in-* 为真，且 `payload == clause_width × clauses`
（上一版把负载总长写进 `entry` 列，已拆成两列）。

## 2. 五条夹具（原始错误文本）

| 夹具 | 结果 |
| --- | --- |
| full（raw/virtual/file 完整） | OK：10 data sections |
| raw 截短 4 字节 | `ValueError: data section at 0x1134 (size 28) overruns the RAW range of .text (raw end 0x114c): first invalid RVA 0x114c` |
| virtual 截短 4 字节 | `ValueError: ... overruns the VIRTUAL range of .text (virtual end 0x114c): first invalid RVA 0x114c` |
| 物理文件截短 4 字节 | `ValueError: ... overruns the FILE bytes (file length 0x114c): first invalid offset 0x114c` |
| 后继越界 | `ValueError: section at 0x1134 declares a successor but RVA 0x1150 is outside every section` |

## 3. 混排断言（只测 MoreSects 后继边界）

`method_body.synthetic_tests()` 现用同一构造器给出两种混排：`fat|0x80 + small` 与 `small|0x80 + fat`，
断言 **2 节 / 单子句宽度 24,12 / 子句 2 条（try 偏移 0,4）/ more True,False**；后继用例单独一条，
只断言错误文本含 `successor` 且给出未映射 RVA，不再与越界混在一起。

## 4. 分支三态（原件 + 两项单变量注入）

`code/s57-branch-facts.csv` 逐字段；主表 note 由 `branch_note()` 从三态解码结果拼装，措辞更正为
“取跳路径 al=1（写于 0x28FD）/ 落空路径 al=0（写于 0x28F9）”（值在前、地址在后），并把“固定跳过”改为
“原件解码为节门禁跳过”，三态结论同时写入 note。

## 5. 35 条子句回读

`code/s57-clauses.csv`：35 条，类型分布 **finally 13 / fault 11 / catch 7 / filter 4**，逐条带 try/handler 偏移长度与 ClassToken。

## 6. 保留与判定

9/10 节链、连续两次审计哈希一致、两套指纹（receipt 与 round）最后生成并从新 head 逐项验证。
判定命令与退出码见文末（head 副本复跑）。

```
check-native-coverage.py  exit 2
pwsh check-s29-446.ps1    exit 0
```
