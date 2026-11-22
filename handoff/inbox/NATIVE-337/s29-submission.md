# NATIVE-337 s29 提交

- task_id: NATIVE-337　assigned_seq: 29　owner: tietoumiao
- 基线：#436 fb049d7760ecdc038a6a468f5afa6d5c391a612c
- 原件：issue-materials/337/FindComponent.dll，SHA-256 3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02

## 判定一：上游 check-s25.py（基线 #436 上的真实输出，exit 0）

~~~
{
  "original_sha256": "3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02",
  "prior_controls": {
    "original_sha256": "3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02",
    "candidate_hashes": {
      "s21-started.md": "d66d8bdd7787d8e673aeda8b15b6060624e4c13ebcf0c7dffea5a73fd57db93f",
      "s21-submission.md": "5bf6e168231958e15fc000fbb5f9eed75857621a33f85be8498cf956e9254ca2",
      "coverage.csv": "3afe1c2a87c9e70c95a8a9216d5f68798fd14e934ff75fa8dc49d41fee00fb43",
      "native-functions.csv": "9fbb8a1a53f28fdb2194c08f675937321e4c4ff2cb852d1fa2c104f42db02413",
      "calls.csv": "7bd46572102cd73fd5ceaa58fc0e783ec30bf0c6fee54e078b4be186871da7d5"
    },
    "listing_rows_checked": 5055,
    "call_classes": {
      "external": 524,
      "data": 48,
      "unresolved": 112
    },
    "direct_iat": {
      "sites": 363,
      "match_main": 363
    },
    "two_hop": {
      "verified_original_and_main": 161,
      "rows": 161,
      "annex_primary_class": {
        "absent": 161
      },
      "owner_region_differences": [
        {
          "site": "0x12da",
          "owner": "0x11e0",
          "listing_region": "0x12bd"
        }
      ]
    },
    "com": {
      "unique_sites": 64,
      "members": {
        "IDispatch::GetIDsOfNames": 16,
        "IUnknown::Release": 32,
        "IDispatch::Invoke": 16
      },
      "blank_impl": 64,
      "factory_iid": "00020400-0000-0000-c000-000000000046",
      "factories": {
        "0x2330": {
          "sites": 44,
          "iid_load": "0x23b4",
          "create": "0x23c8"
        },
        "0x2410": {
          "sites": 12,
          "iid_load": "0x2491",
          "create": "0x24a5"
        },
        "0x24e0": {
          "sites": 8,
          "iid_load": "0x2561",
          "create
~~~

基线关键差异：idispatch rows 64 / member_matches 58 / member_mismatches 6 / missing_displacements 64 / original_slot_offsets {0x10:32, 0x28:16, 0x30:16}；owner_columns 99 行、16 行 different、incorrect_candidate_owners []；direct_example 0x12da→0x5cfc，原件宿主 0x11e0–0x1319，候选宿主 0x12bd。

## 1. 64 个 disp + 6 个错误成员

| 站点 | 旧成员（错） | 原件槽 | 更正后 |
| --- | --- | --- | --- |
| 0x18A1 | IDispatch::GetTypeInfoCount | +0x30 | IDispatch::Invoke |
| 0x1948 | IDispatch::GetTypeInfoCount | +0x28 | IDispatch::GetIDsOfNames |
| 0x1A01 | IDispatch::GetTypeInfoCount | +0x30 | IDispatch::Invoke |
| 0x2021 | IDispatch::GetTypeInfo | +0x30 | IDispatch::Invoke |
| 0x20C9 | IDispatch::GetTypeInfo | +0x28 | IDispatch::GetIDsOfNames |
| 0x2195 | IDispatch::GetTypeInfo | +0x30 | IDispatch::Invoke |

disp 由原件指令操作数解析，写入 code/s25-idispatch-slots.csv（同内容另存 code/s29-idispatch.csv）：64/64 已填。校正后重跑 check-s25：member_matches 64、member_mismatches []、missing_displacements 0。

## 2. 161 条二跳按 RVA 从主表重生成

- code/s29-two-hop.csv：161 行，带 site RVA / listing / main_class / original_host / candidate_owner。
- 主表真实指标（不混算）：external 524 / data 48 / unresolved 112，合计 684。
- 直接 IAT 站点 363 条单列，不进 161 条二跳计数。
- 变化指纹（实际文件重算）：
- calls.csv d6f82133e5187d15efbaf5f3d2e87944cb6d5b60088516b3fa140eabbe569c04
- coverage.csv 3afe1c2a87c9e70c95a8a9216d5f68798fd14e934ff75fa8dc49d41fee00fb43
- code/s29-two-hop.csv 1f1ab3be707bf85ffff0a74d8a87d72ecc1adb71949b020e3e3f2c7efdd56801
- code/s29-idispatch.csv 177f42f976382eec85c592b5ef4c8b5705de09980916c4a7023beb58fb5d4fe2
- code/s25-idispatch-slots.csv 8057dce74efcfc43a8d617f9ecf0cda945556b65abfccf317c42066009e7b572
- code/s29-owner-notes.csv e8eedc956384072ca40c7c89d4c685c8a7edfb89cbdc33fe4a9f4ec984acf48e

## 3. 0x12da 与 0x4706

- 0x12da：E8 1D 4A 00 00 = CALL 0x5cfc（跳板→IAT 0x70c8→OLEAUT32.dll!#313）；原件 .pdata 宿主 0x11e0（0x11e0–0x1319），候选子清单宿主 0x12bd，两侧分列在 code/s29-owner-notes.csv。
- 0x4706：原件展开片段 0x4706–0x4988，unwind 0x93e8，链 0x4690→0x4706→0x93c8；16 条内存分派逐条给原件位置、源指令、槽位 0x00–0x40、主表行号与对象来源（code/s29-owner-notes.csv）。

## 判定二：覆盖检查器

~~~
checked 307 coverage rows, 307 tool-native entries, 684 call records, 0 declared gaps
exit 2
~~~

## 残余（如实）

- 112 条 unresolved（64 COM 实现地址 + 16 处 0x4706 内存分派 + 32 条其他间接），每行有 note 与恢复条件；申报入口缺口 0，去重后仍有 112 条待核。
- check-s25 的 direct_example.submitted_annex_has_row 对 0x12da 仍为 false：该脚本只接受 99 条间接站点的 s25-host 表（集合相等硬断言），0x12da 是直呼，落在 s29 附表；s29 附表已含该行。
