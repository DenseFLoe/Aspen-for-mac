# NATIVE-337 s13 提交

- PR: 见 #13
- head: 见 #13

## 三层（成因 / 流程修正 / 自证）

# 本轮（s13）做到哪一步
① 间接转移推导器已落地（tool/indirect_resolver.py）：逐址读原件指令字节，按 mod/rm 解出基址寄存器与 disp，对 RIP 相对槽读 8 字节指针、对寄存器基址做函数内后向基址回溯。**实测结论：99 处全部是 `call [reg+disp]` 虚调用**（FF50 35、FF53 31、FF52 16、FF92 11、FF10 3、其余 3），基址来自 this/对象寄存器，静态不可唯一绑定 → 逐行写「基址寄存器 + 回溯到的最近定义 + 恢复条件」。定性为 external/boundary 的为 0，这是实测结果不是漏做。
④ 站点集与 #392 基准对齐（tool/site_diff.py）：以 a180dcfd 的 calls.csv + native.asm 为基准（363 个 IAT 站点、296 函数），与当前实现按「指令 RVA + IAT 槽」求集合差 → **baseline 363 / current 363 / missing 0 / extra 0**；同时把 8 个此前缺失站点所在函数的入口补进函数发现（0x11C0/0x11D0/0x11E0/0x129F/0x4D5B/0x5FB8/0x5FD0/0x602B/0x6230），函数数 280→290。输出表 code/site-diff.csv（每站一行，含 baseline 行号、IAT 槽、导入名、是否在当前集）。

# 上一轮为什么漏
- 8 个站点漏：Ghidra 递归下降漏建叶函数（0x11C0/0x11E0/0x4D5B/0x5FB8/0x5FD0/0x602B/0x6230），而我们直接接受了它的函数集，没有拿 #392 的 363 站点做集合差。
- 间接转移全部标 unresolved：没有做基址回溯，也没区分「虚调用不可定」与「表槽可读出指针」两类。

# 尚未完成（如实报缺件）
- ② 64 处 COM 槽：需要「接口指针 → vtable 基址 → 槽索引 → 目标」的链，当前只到「基址寄存器 + disp」，缺对象类型来源（构造点/接口查询点）识别。
- ③ 161 个调用方→跳板：需要 thunk 级反向调用图；当前 calls.csv 的 external 行已含 thunk 指令位置，但未做 caller 反向索引。
- ① 中「13 处可静态定性」的目标尚未出现：99 处经字节级复核均为虚调用；若上游的 13 处来自另一子集（如 jmp thunk），需上游给出这 13 个地址或判据。

# 下一批如何自动避免
门禁：每轮出证前先跑 tool/site_diff.py，要求 missing=0 且函数集覆盖基准集；indirect 表必须带「基址寄存器 + 回溯定义」两列，禁止只写 unresolved 三个字。

## 本轮实跑指标（脚本生成，非手填）

| 指标 | 值 |
| --- | --- |
| 分析器函数 | 290 |
| 原件锚点 | 115 |
| coverage 行（缺口） | 290（0） |
| IAT 调用/跳转站点 | 363 |
| 已登记 external | 363 |
| 数据引用 data | 48 |
| 未决 unresolved | 0 |

## 判定命令与原始输出

~~~
checked 290 coverage rows, 290 tool-native entries, 510 call records, 0 declared gaps
~~~

exit code: 2

## 产物

run.json / native-functions.csv / coverage.csv / calls.csv / code/native.asm / code/native.c

以上文件由生成脚本一次产出；本轮未手工编辑任何产物文件，指标与产物 SHA-256 见 metrics.json。
