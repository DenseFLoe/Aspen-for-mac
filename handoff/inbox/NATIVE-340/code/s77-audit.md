# NATIVE-340 s77 逐项核对（脚本生成）

基线：#450 head `3b440bf0a4bf207d479eccc148232062a7f1a6a0`（主干 581aa65b）；原件 SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。

## 1. 列宽边界（编码标记位）

规则：简单索引 count < 2**16 取 2 字节，否则 4 字节；编码索引带 tag_bits 位 tag，
整合行空间为 count << tag_bits，2 字节形式在 count < 2**(16-tag_bits) 时成立。

| 空间 | count | tag_bits | 边界 | 宽度 |
| --- | ---: | ---: | --- | ---: |
| MemberRefParent | 8191 | 3 | 0x2000 | 2 |
| MemberRefParent | 8192 | 3 | 0x2000 | 4 |
| TypeDefOrRef | 16383 | 2 | 0x4000 | 2 |
| TypeDefOrRef | 16384 | 2 | 0x4000 | 4 |
| MethodDefOrRef | 32767 | 1 | 0x8000 | 2 |
| MethodDefOrRef | 32768 | 1 | 0x8000 | 4 |
| plain-index | 65535 | 0 | 0x10000 | 2 |
| plain-index | 65536 | 0 | 0x10000 | 4 |

真件各空间取 2 字节：MemberRefParent(max 563, tag 3 -> 2), TypeDefOrRef(max 563, tag 2 -> 2), MethodDefOrRef(max 188, tag 1 -> 2)。

访问级别推导（原始整数）：0x06000056 flags=0x4013 & 0x7 = 3 -> Assembly；0x06000057 flags=0x4013 & 0x7 = 3 -> Assembly（ImplFlags=0x0）。

## 2. MethodImpl 正负绑定（同型两方法）

| 方法 | 形状 | 绑定 |
| --- | --- | --- |
| 0x00000100 | same-shape | 无 |
| 0x00000101 | same-shape | 有 |
| 0x00000102 | same-shape | 无 |

声明/实现列解码：MethodDef[256] / MethodDef[257]；真件 MethodImpl 行数 0。

## 3. 每 token 完整 IL 指纹（167 条）

| token | 访问 | flags | IL 长度 | IL SHA-256 |
| --- | --- | --- | ---: | --- |
| 0x06000001 | Assembly | 0x0813 | 31 | `c9ba162154efe7085c62fbaa707d1b181e0510c16334332d11751c1c6c7221c2` |
| 0x06000002 | Assembly | 0x0013 | 17 | `f410721af38809bb4f94bbb58a5ba651d0ede1dd96948f21b253ea70e86c5af0` |
| 0x06000003 | Assembly | 0x0013 | 20 | `07c0186459cbff3d345696ce11e88879c5154cb72a85d88bc9f98a4482c35176` |
| 0x06000004 | Assembly | 0x0013 | 81 | `5a67c37ad90ac23faac3f57e7962e0d6c284eafb02e3cc0b2fe47c481e4fe9a6` |
| 0x06000005 | Assembly | 0x0013 | 81 | `2aee9f7e60a49258d73650d8ff776704ac439ec5d837a72cbc05fa5c8c804419` |
| 0x06000006 | Assembly | 0x0013 | 17 | `f410721af38809bb4f94bbb58a5ba651d0ede1dd96948f21b253ea70e86c5af0` |
| … | … | … | 全表见 code/s77-il-fingerprints.csv |

## 4. VTableFixups 与四个修补槽

目录 0x16600 / 0x768，共 237 条；四条槽位：

| 槽 | 条目 | 块 RVA | Count | dwFlags | 位含义 | 初值 |
| --- | ---: | --- | ---: | --- | --- | --- |
| 0x19600 | 168 | 0x19600 | 1 | 0x2 | COR_VTABLE_64BIT | 0x6000056 |
| 0x19608 | 167 | 0x19608 | 1 | 0xA | COR_VTABLE_64BIT,COR_VTABLE_CALL_MOST_DERIVED | 0x6000056 |
| 0x19610 | 170 | 0x19610 | 1 | 0x2 | COR_VTABLE_64BIT | 0x6000057 |
| 0x19618 | 169 | 0x19618 | 1 | 0xA | COR_VTABLE_64BIT,COR_VTABLE_CALL_MOST_DERIVED | 0x6000057 |

0x2 = COR_VTABLE_64BIT，0xA = COR_VTABLE_64BIT|COR_VTABLE_CALL_MOST_DERIVED；
本模块可追踪的生产者：VTableFixups 目录本身（CLR 在加载/首次调用时把槽改写为方法入口），
未见模块内 IL 写入者；恢复条件＝运行期槽读写断点或 CLR fixup 跟踪（行为测试留 Windows 阶段）。

## 5. 控制项（17）

- PASS：8191 -> 2 bytes / 8192 -> 4 bytes (13-bit boundary 0x1FFF/0x2000)
- PASS：16383 -> 2 / 16384 -> 4 (14-bit boundary)
- PASS：32767 -> 2 / 32768 -> 4 (15-bit boundary)
- PASS：65535 -> 2 / 65536 -> 4 (plain 16-bit boundary)
- PASS：real image widths match the rule (2 bytes everywhere)
- PASS：MethodImpl declaration/implementation decode to MethodDef rows
- PASS：positive binding: 0x101 bound; negative: 0x102 unbound
- PASS：real image MethodImpl rows (0) decode cleanly
- PASS：every IL token has a 64-char fingerprint (167 tokens)
- PASS：0x06000056 and 0x06000057 share the same IL fingerprint
- PASS：twin bodies: the fingerprint equals the delivered body file
- PASS：VTableFixups directory 0x16600/0x768 parses 237 entries
- PASS：four slots land in 32-bit/64-bit fixup blocks (0x2 / 0xA)
- PASS：slot initial values are the two MethodDef tokens (CLR fixup target, not a code address)
- PASS：11 sites preserved
- PASS：35 EH clauses preserved
- PASS：EH synthetic tests pass

