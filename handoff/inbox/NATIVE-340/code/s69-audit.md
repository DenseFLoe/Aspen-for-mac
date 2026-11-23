# NATIVE-340 s69 逐项核对（脚本生成）

基线：#450 head `ba2c5d5f23eddb10ae0c9d78af2a4dc5d038fa1e`；原件 SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。

## 1. 0x06000056 全站点（11 站 / 8 方法）

| # | 方法 | 名称 | 站点 | ldftn | 实参 |
| ---: | --- | --- | --- | --- | --- |
| 1 | 0x0600000B | std.bad_array_new_length.{ctor} | IL_002D | 0x06000002 | ldarg.0  |
| 2 | 0x0600000B | std.bad_array_new_length.{ctor} | IL_0044 | 0x06000006 | ldarg.0  |
| 3 | 0x0600000C | std.bad_alloc.{ctor} | IL_002D | 0x06000002 | ldarg.0  |
| 4 | 0x0600000F | std.bad_variant_access.{ctor} | IL_002D | 0x06000002 | ldarg.0  |
| 5 | 0x06000013 | std.bad_cast.{ctor} | IL_002D | 0x06000002 | ldarg.0  |
| 6 | 0x06000019 | std.bad_weak_ptr.{ctor} | IL_002D | 0x06000002 | ldarg.0  |
| 7 | 0x0600001F | msclr.interop.details.InternalAnsiToStringHelper | IL_0061 | 0x06000026 | ldloca.s 0x4 |
| 8 | 0x0600001F | msclr.interop.details.InternalAnsiToStringHelper | IL_0087 | 0x06000026 | ldloca.s 0x4 |
| 9 | 0x06000051 | .cctor | IL_0019 | 0x0600004F | ldloca.s 0x0 |
| 10 | 0x06000091 | .ctor | IL_005F | 0x06000023 | ldloca.s 0x2 |
| 11 | 0x06000091 | .ctor | IL_0077 | 0x06000023 | ldloca.s 0x2 |

## 2. 两方法访问级别与别名

| token | 名称 | flags | 访问 | ImplFlags | RVA | MemberRef | MethodImpl | 重复 RVA | 孪生体 |
| --- | --- | --- | --- | --- | --- | ---: | ---: | --- | --- |
| 0x06000056 | ___CxxCallUnwindDtor | 0x0 | privatescope | 0x0 | 0x3E08 | 0 | 0 | no | 0x06000057 |
| 0x06000057 | ___CxxCallUnwindDelDtor | 0x0 | privatescope | 0x0 | 0x3E4C | 0 | 0 | no | 0x06000056 |

## 3. 配对复验（完整 vs 缺一站点）

- 完整 11 行：差异 无
- 删去 0x0600000B IL_0044：差异 [('0x0600000B', 'IL_0044')]

## 4. 控制项（15）

- PASS：0x06000056: 8 distinct methods
- PASS：0x06000056: 11 sites
- PASS：0x06000057: 0 sites
- PASS：0x0600000B IL_0044 -> ldftn 0x06000006
- PASS：0x0600001F IL_0087 -> ldftn 0x06000026
- PASS：0x06000091 IL_0077 -> ldftn 0x06000023
- PASS：both methods are privatescope, IL, no duplicate RVA
- PASS：no MemberRef/MethodImpl alias path
- PASS：0x06000056 and 0x06000057 have identical IL bodies (twin bodies, distinct tokens)
- PASS：paired: complete evidence has zero差异
- PASS：paired: removing 0x0600000B IL_0044 is located exactly
- PASS：EH: 35 clauses still read
- PASS：EH synthetic tests all pass
- PASS：AL three states 0/1 with skip true/false
- PASS：tiny header 0A 00 2A and 0A 01 2A both size 2

