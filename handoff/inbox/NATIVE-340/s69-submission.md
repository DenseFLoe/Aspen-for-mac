# NATIVE-340 s69 提交

- 分支：tietoumiao/native-340-s33（前移 #450，不新开 PR）
- 上轮固定 head：#450 @ ba2c5d5f23eddb10ae0c9d78af2a4dc5d038fa1e
- 本轮 head：见 #13

## 1. 0x06000056 全站点（8 方法 / 11 站点）

上一版审计在加入同方法第一条引用后 `break`，漏了同方法的其余站点。现按**调用地址**逐条枚举
（`code/s69-calli-sites.csv`，11 行）：

| # | 方法 | 站点 | ldftn | 实参 |
| ---: | --- | --- | --- | --- |
| 1 | 0x0600000B | IL_002D | 0x06000002 | ldarg.0 |
| 2 | 0x0600000B | **IL_0044** | **0x06000006** | ldarg.0 |
| 3 | 0x0600000C | IL_002D | 0x06000002 | ldarg.0 |
| 4 | 0x0600000F | IL_002D | 0x06000002 | ldarg.0 |
| 5 | 0x06000013 | IL_002D | 0x06000002 | ldarg.0 |
| 6 | 0x06000019 | IL_002D | 0x06000002 | ldarg.0 |
| 7 | 0x0600001F | IL_0061 | 0x06000026 | ldloca.s 0x4 |
| 8 | 0x0600001F | **IL_0087** | **0x06000026** | ldloca.s 0x4 |
| 9 | 0x06000051 | IL_0019 | 0x0600004F | ldloca.s 0x0 |
| 10 | 0x06000091 | IL_005F | 0x06000023 | ldloca.s 0x2 |
| 11 | 0x06000091 | **IL_0077** | **0x06000023** | ldloca.s 0x2 |

去重方法 **8**，站点 **11**；0x06000057 仍为 0 站点。

## 2. 访问级别与别名

| token | 名称 | flags | 访问 | ImplFlags | RVA | MemberRef | MethodImpl | 重复 RVA | 孪生体 |
| --- | --- | --- | --- | --- | --- | ---: | ---: | --- | --- |
| 0x06000056 | `___CxxCallUnwindDtor` | 0x0 | **privatescope** | 0x0 (IL) | 0x3E08 | 0 | 0 | no | 0x06000057 |
| 0x06000057 | `___CxxCallUnwindDelDtor` | 0x0 | **privatescope** | 0x0 (IL) | 0x3E4C | 0 | 0 | no | 0x06000056 |

- **无元数据别名**：无 MemberRef、无 MethodImpl、无重复 RVA；两方法 IL 体逐字节相同（同 sha256）但 token 不同 → 孪生体，不是别名。
- **指针入口**：只有 `ldftn` 产生的托管函数指针，经 IL_0004 `calli 0x11000075` 的 arg0→loc0 传入。

## 3. 配对复验

`code/s69-evidence.json`：完整 11 行 vs 删去 0x0600000B IL_0044 的 11 行，

- 完整：差异 **无**
- 删一行：差异 **恰好 `[("0x0600000B","IL_0044")]`**（定位到具体方法与偏移）

## 4. 保留

EH（25 节 / 35 子句、synthetic_tests 全 PASS）、AL 三态 0/1/0 与跳过 真/假/真、tiny 头两变体均 size 2、双审计、两套指纹。

## 5. 判定（真实退出码）

```
check-native-coverage.py  exit 2   1105 / 354 / 559 / 0
pwsh check-s29-446.ps1    exit 0   fingerprint 70 / mismatches []
s45-eh-chain.py           exit 0   9/9、10/10
s57-review.py             exit 0   sections 25 / clauses 35 / contradicted []
audit_340_s69.py ×2       exit 0   连跑两次逐字节一致
```
