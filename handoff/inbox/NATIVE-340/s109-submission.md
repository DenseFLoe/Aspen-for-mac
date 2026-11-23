# NATIVE-340 s109 提交

- 分支：tietoumiao/native-340-s33
- 上轮固定候选：#450 @ 6d93c598；主干基线 c8ec2186
- 脚本指纹来源树：本轮 head 推送前为 6d93c598…（§33 节按推送后 head 重新生成）

## ① L1509 位移 / 槽 / 完整导入符号

固定原件核对：`L1509 site=0x4711 disp=0x18E9 slot=0x6000 symbol=KERNEL32.dll!QueryPerformanceCounter`，基线 `problems=0`（exit 0）。

两个单改变体（各自 exit 1，点名原因）：

    A 只改显示位移 [RIP+0x18E9] → [RIP+0x18EA]
      MISMATCH disp: asm 0x18EA != original 0x18E9
      l1509-check: problems=1

    B 只改符号后缀 QueryPerformanceCounter → QueryPerformanceCounterX
      MISMATCH symbol: row callee 'KERNEL32.dll!QueryPerformanceCounterX' != KERNEL32.dll!QueryPerformanceCounter
      l1509-check: problems=1

缺引用时报缺：跳板块 15 条 note 原先没有 IAT 槽与符号，本轮补为 `；IAT 槽 0x60xx = DLL!symbol` 后基线才为 0。


## ①b read() 行取值路径变体

`read(data, offset, _mutate_row_size=True)` 把行步长改成常量 2（只动取值路径，不动宽度函数）。

    LOCATED MemberRef[3].Name: normal='.ctor' mutated='bute'
    LOCATED MethodDef[5].Flags: normal=19 mutated=4300
    read-mutate: fields=5 changed=5                     exit 0

测试通过 = 5 个字段全部被观测到变化；若取值路径未被覆盖（changed=0）则 exit 1。

## ② 三站点区间冲突（双标注，待核）

    asm  ; FUNC 00004777-000047D   → 半开区间 [0x4777,0x477D)，0x477D 在区间外
    census native-functions.csv    → 只有 rva,name 两列，没有结束地址；按下一起点推算归类，0x477D 计入 FUN_0x4777
    两者不一致，本轮不作统一；0x477D/0x47D1/0x4894 三条按「census 归类 + asm 区间外」双标注，待核。

| 站点 | asm 区间（实际结束地址） | census 归类 | 导入符号 |
| --- | --- | --- | --- |
| 0x477D | [0x4777,0x477D)，结束 0x477D | FUN_0x4777（推算） | VCRUNTIME140.dll!__C_specific_handler |
| 0x47D1 | [0x47CB,0x47D1)，结束 0x47D1 | FUN_0x47CB（推算） | api-ms-win-crt-runtime-l1-1-0.dll!_crt_at_quick_exit |
| 0x4894 | [0x488E,0x4894)，结束 0x4894 | FUN_0x488E（推算） | VCRUNTIME140.dll!memcpy |

根因：`native-functions.csv` 只有 `rva,name` 两列，没有结束地址，所以「以下一起点当终点」是推算而非实测；这正是与 asm 半开区间冲突的来源。

## ③ metrics / 清单

- `calls.csv` 三条站点 note 已加区间双标注；15 条跳板 note 已补 IAT 槽与符号。
- `calls_sha256` 重算为 `0356c8a3dc5fa3b5…`（成因：note 补槽/补标注后 calls.csv 变化）。
- 保留：167 条 IL 摘要、六组 ImplMap、metrics 三摘要、两份活动清单、八份脚本指纹、0x06000057 arg0 外部指针恢复条件、28 条未决。

## ④ QA 命令（引号化）

    cd _t14/qa/93bf962c && set "PYTHONPATH=%CD%\..\..\.local\pylibs" && python -B -m qa.gate --task NATIVE-340 --item-dir "%CD%\..\..\handoff\inbox\NATIVE-340" --original "%CD%\..\..\_t13\orig\WrapSaveMergeNNFiles.dll"

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
| tool/s109-l1509-check.py | 3,647 B | 9c9f5927e14d8949ce297830ef88931a5c5f28398745bee0531fc602fce1e41e | L1509 位移/槽/符号 + 单改变体 |
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
