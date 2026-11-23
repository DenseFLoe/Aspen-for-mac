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

| 脚本 | 字节 | sha256 | 用途 |
| --- | ---: | --- | --- |
| tool/cli_tables.py | 15,890 B | 64dfbcd80bf771871a8c1e423b3feb5bdc6d44d11ddf950283890b8e65b37035 | 解析（read 调 layout_for，ImplMap 1 位） |
| tool/s101_width_fixtures.py | 3,215 B | 85145a458b4c4f1c9ff8dc3d0eeadadca2d81b5b2254e27af90027958b095a95 | 夹具 A/B/C/D + 双负向 |
| tool/s101_layout_check.py | 1,949 B | 35835a05362b4ba5b851970bb0ef6f95e86dcba35b83ddec7238a4054353b523 | 1c/1d 逐键比对 |
| tool/s101_layout_baseline.py | 2,777 B | 5492909e8428993e051ede50e97ccab968420aebc8aeb281e3f80bc445560e72 | 基线重生成 |
| tool/s93-width-controls.py | 3,134 B | 8374898c760cce153ca2b5ab541a6a261c3a9d848ae230544dfb79aa4635e551 | 列宽 + 紧邻列控制 |
| tool/s97-site-owners.py | 2,475 B | 3dc305a25b38bde1689d6803476c45a73d44c9dff1d1b199a70b3e74a926ffce | 站点归属 + 正反例 |
| tool/s105-site-evidence.py | 3,610 B | 600975699de15c7ff150a336ac792726c40383e5229f835acdb727dd0e68c1ed | 站点四样比对（字节/位移/符号/半开区间） |
| tool/verify_il_digests.py | 1,958 B | 3693094d52e76e40ba43aee56cbb6d379defde219a43ce10d3a27c654a25aec6 | 167 条 IL 摘要只读复验 |

运行命令（Windows 可直接复制，仓库根执行）：

```
python -B tool/s101_width_fixtures.py
python -B tool/s101_layout_check.py
python -B tool/s97-site-owners.py .
python -B tool/verify_il_digests.py --binary _t13/orig/WrapSaveMergeNNFiles.dll --table handoff/inbox/NATIVE-340/code/s89-il-digests.csv
cd _t14/qa/93bf962c && set PYTHONPATH=%CD%/../../.local/pylibs && python -B -m qa.gate --task NATIVE-340 --item-dir %CD%/../../handoff/inbox/NATIVE-340 --original %CD%/../../_t13/orig/WrapSaveMergeNNFiles.dll
```

原始输出与真实 exit：

```
> python -B tool/s101_width_fixtures.py
fixture A: MemberRefParent=2 MethodDefOrRef=2
fixture B: MemberRefParent=4 MethodDefOrRef=4
fixture C: MemberRefParent=4 MethodDefOrRef=2
fixture D: MemberRefParent=4 MethodDefOrRef=2
NEGATIVE detected: MemberRefParent expected 4 got 2
NEGATIVE(D) detected: MemberRefParent expected 4 got 2
width-fixtures: cases=4 failures=0
exit 0

> python -B tool/s101_layout_check.py
1d MISMATCH ImplMap.MemberForwarded baseline={'table': 'ImplMap', 'column': 'MemberForwarded', 'width': 2, 'rule': 'coded tag 2 bits, max rows 698 < 2**14 -> 2', 'row_size': 8, 'rows': 15} new={'table': 'ImplMap', 'column': 'MemberForwarded', 'width': 2, 'rule': 'coded tag 1 bits, max rows 698 < 2**15 -> 2', 'row_size': 8, 'rows': 15}
layout-check: columns=85 1c_diffs=0 1d_diffs=1
exit 1

> python -B tool/s97-site-owners.py .
attribution: checked=67 mismatches=0
exit 0

> python -B tool/verify_il_digests.py --binary _t13/orig/WrapSaveMergeNNFiles.dll --table handoff/inbox/NATIVE-340/code/s89-il-digests.csv
checked 167 rows, mismatches 0
exit 0

usage: gate.py [-h] [--task {NATIVE-337,NATIVE-340}] [--item-dir ITEM_DIR]
               [--folder FOLDER] [--head HEAD] [--repo REPO] [--cache CACHE]
               [--original ORIGINAL] [--binary BINARY] [--l1-path L1_PATH]
               [--against-head AGAINST_HEAD] [--skip-l1] [--json JSON]
               [--quiet]
gate.py: error: unrecognized arguments: workspace\_work\wf-20261120-aspen-batch/../../handoff/inbox/NATIVE-340 workspace\_work\wf-20261120-aspen-batch/../../_t13/orig/WrapSaveMergeNNFiles.dll
exit 2
```

判据映射：

| 判据 | 脚本位置 |
| --- | --- |
| 夹具 A/B/C/D 两列逐格 | tool/s101_width_fixtures.py main() 的 cases |
| 破坏取宽必非零 | 同文件 ct.coded_width = lambda *a: 2 段 |
| read == layout_for | tool/s101_layout_check.py 的 keyed() 1c 段 |
| 新版 == 基线 | 同文件 1d 段（按键名比对） |
| 站点/owner/listing | tool/s97-site-owners.py 的 site 比较 |
| 167 条摘要 | tool/verify_il_digests.py 的 truth/bad |

版本 pin：qa gate 93bf962c (MANIFEST files sha256 0f8be7a96e6dfa528116f28663d182b83ae60481896e1796975d27a398394c81)。
