# NATIVE-340 s65 逐项核对（脚本生成）

基线：#450 head `42dc0c03af69288288b70589a6f3064b7887494c`；原件 SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。

## 1. EH 子句末字段（按种类）

| 方法 | 节 | # | flags | 种类 | try | handler | 末字段原值 | 语义 | 值 |
| --- | --- | ---: | --- | --- | --- | --- | --- | --- | --- |
| 0x06000030 | 0x34EC | 0 | 0x0 | catch | 3/39 | 42/8 | 0x1000030 | type_token | 0x01000030 |
| 0x0600004D | 0x3C64 | 0 | 0x0 | catch | 0/30 | 30/10 | 0x1000030 | type_token | 0x01000030 |
| 0x0600004D | 0x3C64 | 1 | 0x0 | catch | 0/30 | 40/10 | 0x100001D | type_token | 0x0100001D |
| 0x06000050 | 0x3D34 | 1 | 0x0 | catch | 7/41 | 48/25 | 0x1000030 | type_token | 0x01000030 |
| 0x06000050 | 0x3D34 | 2 | 0x0 | catch | 7/41 | 73/25 | 0x100001D | type_token | 0x0100001D |
| 0x06000056 | 0x3E30 | 0 | 0x1 | filter | 0/11 | 24/3 | 0xB | filter_offset | IL_000B |
| 0x06000057 | 0x3E74 | 0 | 0x1 | filter | 0/11 | 24/3 | 0xB | filter_offset | IL_000B |
| 0x06000058 | 0x3EBC | 0 | 0x1 | filter | 0/15 | 28/3 | 0xF | filter_offset | IL_000F |
| 0x0600005B | 0x3F60 | 0 | 0x1 | filter | 0/30 | 43/3 | 0x1E | filter_offset | IL_001E |
| 0x0600006B | 0x42C8 | 0 | 0x0 | catch | 55/107 | 162/66 | 0x100004B | type_token | 0x0100004B |
| 0x0600006B | 0x42C8 | 1 | 0x0 | catch | 20/237 | 257/3 | 0x100004B | type_token | 0x0100004B |

## 2. 四个 filter 方法

| 方法 | filter 起点 | 起点字节 | handler 起点 | handler 前两字节 | 预期 |
| --- | ---: | --- | ---: | --- | --- |
| 0x06000056 | IL_000B | 0x26 | IL_0018 | fe11 | 命中 |
| 0x06000057 | IL_000B | 0x26 | IL_0018 | fe11 | 命中 |
| 0x06000058 | IL_000F | 0x26 | IL_001C | fe11 | 命中 |
| 0x0600005B | IL_001E | 0x26 | IL_002B | fe11 | 命中 |

## 3. 7 个 catch 类型 token

| 方法 | # | type token | handler |
| --- | ---: | --- | --- |
| 0x06000030 | 0 | 0x01000030 | IL_002A |
| 0x0600004D | 0 | 0x01000030 | IL_001E |
| 0x0600004D | 1 | 0x0100001D | IL_0028 |
| 0x06000050 | 1 | 0x01000030 | IL_0030 |
| 0x06000050 | 2 | 0x0100001D | IL_0049 |
| 0x0600006B | 0 | 0x0100004B | IL_00A2 |
| 0x0600006B | 1 | 0x0100004B | IL_0101 |

## 4. 变异测试

- 表格指纹 before/after：927930a35c0b27ca / 2d434295ffe0aa7c（不同=True）
- 语义比对定位：[('0x06000056', '0')]（期望 ('0x06000056', '0')）

## 5. 两处 calli

签名 0x11000075 blob `0001010f01` = callconv=0 param_count=1 ret=void param0=ptr<void>。
- 0x06000056 IL_0004：可见调用者 8 个 → 0x0600000B@IL_002D:0x06000002, 0x0600000C@IL_002D:0x06000002, 0x0600000F@IL_002D:0x06000002, 0x06000013@IL_002D:0x06000002, 0x06000019@IL_002D:0x06000002, 0x0600001F@IL_0061:0x06000026, 0x06000051@IL_0019:0x0600004F, 0x06000091@IL_005F:0x06000023
- 0x06000057 IL_0004：可见调用者 0 个 → 无（缺外部生产者）

## 6. 控制项（12）

- PASS：25 EH sections / 35 clauses
- PASS：7 catch clauses read independently
- PASS：4 filter clauses
- PASS：0x06000056 filter 0x0B / handler 0x18, pop + endfilter(FE 11)
- PASS：0x06000057 filter 0x0B / handler 0x18, pop + endfilter(FE 11)
- PASS：0x06000058 filter 0x0F / handler 0x1C, pop + endfilter(FE 11)
- PASS：0x0600005B filter 0x1E / handler 0x2B, pop + endfilter(FE 11)
- PASS：mutation changes the table fingerprint
- PASS：semantic diff locates the mutated row
- PASS：signature 0x11000075 = void(ptr<void>) with one parameter
- PASS：0x06000056 calli: 8 visible callers with ldftn targets
- PASS：0x06000057 calli: zero visible callers

