# NATIVE-340 s73 逐项核对（脚本生成）

基线：#450 head `5ca17f4987251f32be4772955c8b9be3185b9c62`；原件 SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。

## 1. 更正后的方法属性

| token | 名称 | Flags | ImplFlags | 访问 | Static | HasSecurity | IL SHA-256 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 0x06000056 | ___CxxCallUnwindDtor | 0x4013 | 0x0000 | assembly | True | True | `cf6b47445b3281297d160b230f3d5a4c08006679b0b937098c432073b5ee0b0d` |
| 0x06000057 | ___CxxCallUnwindDelDtor | 0x4013 | 0x0000 | assembly | True | True | `cf6b47445b3281297d160b230f3d5a4c08006679b0b937098c432073b5ee0b0d` |

## 2. 编码索引解码（MemberRefParent / MethodDefOrRef）

| 空间 | 原始值 | 预期 | 实测 | 输入 SHA-256 |
| --- | ---: | --- | --- | --- |
| MemberRefParent | 17 | TypeRef[2] | TypeRef[2] | `84fc05949dc1e486652a4ed316afb6434e9437eb30b714594a1d0b4205776602` |
| MemberRefParent | 11 | MethodDef[1] | MethodDef[1] | `cb30e91817239109ffd0a5870046e128f04619da80c7624d921162fdfe514f76` |
| MemberRefParent | 27 | MethodDef[3] | MethodDef[3] | `bb549140670e7cab3f174160e750d9ed261491b7feb8fb75ec32f0d788f0abce` |
| MemberRefParent | 33 | TypeRef[4] | TypeRef[4] | `9a090610d0aa9445db0890179a9dea330334e3b9086987e93af97dbc978fe311` |
| MethodDefOrRef | 3 | MemberRef[1] | MemberRef[1] | `9d9f290527a6be626a8f5985b26e19b237b44872b03631811df4416fc1713178` |
| MethodDefOrRef | 2 | MethodDef[1] | MethodDef[1] | `26b25d457597a7b0463f9620f666dd10aa2c4373a505967c7c8d70922a2d6ece` |
| MethodDefOrRef | 28 | MethodDef[14] | MethodDef[14] | `b01099398ce27bbcb7ed256854acc338ba75af739e9d73d741dcb13dc4cbfb56` |

MemberRefParent 实况分布：{'TypeRef': 105, 'TypeSpec': 4}；MethodImpl 行数：0。

## 3. 入口来路

| stub | jmp 目标 | 预期槽 | 命中 | 槽初值 | 是 MethodDef token |
| --- | --- | --- | --- | --- | --- |
| 0x5574 | 0x19600 | 0x19600 | True | 0x6000056 | True |
| 0x557A | 0x19608 | 0x19608 | True | 0x6000056 | True |
| 0x5584 | 0x19610 | 0x19610 | True | 0x6000057 | True |
| 0x558A | 0x19618 | 0x19618 | True | 0x6000057 | True |
| 0x5570 | 0x557A | - | True | - | False |
| 0x5580 | 0x558A | - | True | - | False |

## 4. 复核

- 8 方法 / 11 站点；35 EH 子句；AL 三态 0/1；删一站后证据指纹变化并定位。
- 完整证据 SHA-256 `480927f4252f25c7269a84e6857d7e4d39825d883fb8ab4384c75e240ccf485d`；删 0x0600000B IL_0044 后 `e94ba6e3be1d912ebd9353c300c95b7c21c74cd8b9608f7f89b86804131ff97c`。

## 5. 控制项（17）

- PASS：both methods flags 0x4013, ImplFlags 0x0
- PASS：0x4013 & 7 == 3 -> Assembly (not privatescope)
- PASS：IL sha256 is the full 64 hex chars
- PASS：0x06000056 and 0x06000057 have identical IL bodies
- PASS：coded-index decoder unit pairs all match
- PASS：MemberRef parents decode to {'TypeRef': 105, 'TypeSpec': 4} (no MethodDef parent)
- PASS：MethodImpl has 0 rows; declaration/implementation columns decoded
- PASS：visibility pair (assembly vs public) both report no binding
- PASS：0x5584 -> 0x19610 and 0x558A -> 0x19618
- PASS：0x5574 -> 0x19600 and 0x557A -> 0x19608 (0x06000056 entries)
- PASS：all four slots initially hold a MethodDef token (CLR fixup before patch)
- PASS：8 methods / 11 sites still enumerate
- PASS：35 EH clauses still read
- PASS：EH synthetic tests pass
- PASS：AL three states 0/1 with skip true/false
- PASS：paired evidence: removing one site is located
- PASS：complete vs one-site-removed evidence fingerprints differ

