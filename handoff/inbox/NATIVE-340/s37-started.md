---
task_id: NATIVE-340
type: started
state: implementing
seq: 37
at: 2026-11-23T04:45:00+08:00
head_base: e8fb4cbcbcbbd5a5020a7ac7a3209a42d80f364d
---
已开始 s37：修生成器的 MethodDef RVA / EH 数据节读法（fat header Size 半字节 + EH 节 kind/data-size），
用 0x06000032（0x3524 / EH 0x3568 / 1 个 finally / handler IL_0025–IL_002C）验证；
还原 0x218D / 0x2874 / 0x2197 三处语义，保留 0x21A4 正分支单次读取。
