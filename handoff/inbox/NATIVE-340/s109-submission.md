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

见下节（由 tool/s101_receipt_section.py 从 head 树生成）。
