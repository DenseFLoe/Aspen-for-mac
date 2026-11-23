# NATIVE-340 s65 提交

- 分支：tietoumiao/native-340-s33（前移 #450，不新开 PR）
- 上轮固定 head：#450 @ 42dc0c03af69288288b70589a6f3064b7887494c
- 本轮 head：见 #13

## A. EH 子句末字段（按种类，保留原始整数）

`code/s65-eh-clauses.csv` 每行给 `last_field_raw`（原始整数）与 `last_field_role` / `last_field_value`：

| 种类 | 末字段语义 | 本件取值 |
| --- | --- | --- |
| catch | **类型 token** | 0x01000030 ×3、0x0100001D ×2、0x0100004B ×2 |
| filter | **filter IL 偏移** | 0x0B、0x0B、0x0F、0x1E |
| finally / fault | 原始值 + 标注“字段未使用” | 0（保留） |

四个 filter 方法（独立 reader 从节字节解析）：

| 方法 | filter 起点 | 起点字节 | handler 起点 | handler 前两字节 |
| --- | ---: | --- | ---: | --- |
| 0x06000056 | IL_000B | 0x26 pop | IL_0018 | `fe 11` endfilter |
| 0x06000057 | IL_000B | 0x26 pop | IL_0018 | `fe 11` endfilter |
| 0x06000058 | IL_000F | 0x26 pop | IL_001C | `fe 11` endfilter |
| 0x0600005B | IL_001E | 0x26 pop | IL_002B | `fe 11` endfilter |

7 个 catch 的类型 token 见 `code/s65-catch-types.csv`（独立 `struct` 读取，不经 `method_body` 的子句函数）。
变异测试：把交付表里 0x06000056 的 `last_field_value` 由 `IL_000B` 改成 `IL_000C` → 表指纹改变，且语义比对**定位到该行**
（`located == [("0x06000056","0")]`）。

## B. 两处 calli（静态）

`code/s65-calli.csv`。签名 `0x11000075` blob `00 01 01 0F 01` = 默认调用约定、1 个参数、返回 void、参数 `ptr<void>`。

- **0x06000056 IL_0004**：`ldarg.0 → stloc.0` 把 **arg0 作为函数指针**，`ldarg.1` 作为唯一实参，`ldloc.0; calli`。
  原件可见 **8 个调用者**（11 个 call 站点），每个都以 `ldftn <MethodDef>` 提供 arg0 → 目标可枚举：
  0x06000002 ×5、0x06000006、0x06000026 ×2、0x0600004F、0x06000023 ×2。
  缺失生产者＝本方法之外的调用者/委托表；恢复条件＝枚举导出与委托注册，或在入口断点读 arg0。
- **0x06000057 IL_0004**：同构造，但原件 IL 中 **0 个** call/callvirt/ldftn 引用本方法 → 无生产者，保留 unresolved，
  恢复条件＝外部调用者清单或运行期断点。

## 保留

s61 的 EH 范围检查、六张表（主表 + 5 份原生附表）里的三态 AL 0/1/0 与跳过真/假/真、双审计、两套指纹。

## 判定（真实退出码）

```
check-native-coverage.py  exit 2   1105 / 354 / 559 / 0
pwsh check-s29-446.ps1    exit 0   fingerprint 67 / mismatches []
s45-eh-chain.py           exit 0   9/9、10/10
s57-review.py             exit 0   sections 25 / clauses 35 / virtual_end_diff [] / contradicted []
audit_340_s65.py ×2       exit 0   连跑两次逐字节一致
```
