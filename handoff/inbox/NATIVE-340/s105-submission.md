# NATIVE-340 s105 提交

- 分支：tietoumiao/native-340-s33
- 本轮 head：待推送后回读（见文末 §检验器脚本 的两提交写法）
- 脚本指纹来源树：34963f5d2e07142f9edd1b4c75aebaecea169d09
- 固定候选：#450 @ 9c949d3f；主干基线 19f94421

## ① 半开区间 vs census 归类冲突（待核，不统一）

    asm  ; FUNC 00004777-000047D   → 半开区间 [0x4777,0x477D)，0x477D 在区间外
    census native-functions.csv    → 按下一起点归类，0x477D 计入 FUN_0x4777
    两者不一致，本轮不作统一；0x477D/0x47D1/0x4894 三条按「census 归类 + asm 区间外」双标注，待核。

| 站点 | asm 区间 | census 归属 | 导入符号 |
| --- | --- | --- | --- |
| 0x477D | [0x4777,0x477D) 区间外 | FUN_0x4777 | VCRUNTIME140.dll!__C_specific_handler |
| 0x47D1 | [0x47CB,0x47D1) 区间外 | FUN_0x47CB | api-ms-win-crt-runtime-l1-1-0.dll!_crt_at_quick_exit |
| 0x4894 | [0x488E,0x4894) 区间外 | FUN_0x488E | VCRUNTIME140.dll!memcpy |

## ② 两个单改变体的原文输出

变体 A（只改 L1509 一个字节 FF 25 → FF 24）：

    MISMATCH listing=code/native.asm#L1509 byte mismatch at 0x4711: listing=ff24e9180000 original=ff25e9180000
    site-evidence: checked=67 mismatches=1            exit 1

变体 B（只改一行目标 #L1509 → #L1510）：

    MISMATCH listing=code/native.asm#L1510-L1510 symbol mismatch at 0x4717: IAT 0x6008 is KERNEL32.dll!GetCurrentProcessId, row says KERNEL32.dll!QueryPerformanceCounter
    site-evidence: checked=67 mismatches=1            exit 1

基线：site-evidence: checked=67 mismatches=0，exit 0。

## ③ calls_sha256 更替

    e991b6cc5b388e25… → c92c66950f4a2f7c…

旧值成因：s101 push 之后未再更新；本轮按当前 calls.csv 重算并写回 metrics.json。

## ④ QA 命令引号化

含空格路径一律加引号，并在从指定 head 取得、指纹核对过的输入上复跑：

    cd _t14/qa/93bf962c && set "PYTHONPATH=%CD%\..\..\.local\pylibs" && python -B -m qa.gate --task NATIVE-340 --item-dir "%CD%\..\..\handoff\inbox\NATIVE-340" --original "%CD%\..\..\_t13\orig\WrapSaveMergeNNFiles.dll"

## 保留

六组 ImplMap、八组阈值、两项清单定位、七份脚本指纹、0x06000057 arg0 外部指针恢复条件、28 条未决。

## 检验器脚本

见下节（由 tool/s101_receipt_section.py 从 head 树生成）。
