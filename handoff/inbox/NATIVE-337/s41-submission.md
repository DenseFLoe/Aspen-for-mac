# NATIVE-337 s41 提交

## 生成器清单与指纹

| 文件 | SHA-256 | 作用 |
| --- | --- | --- |
| tool/s37_two_hop.py | 54d8477d9926ce4acf83f69eb10d9389aea688501daf44e049ec8e297c6a09dd | 从原件重算 161 条二跳（首跳/IAT/符号/calls_row） |
| tool/pe_reader.py | c0efbbffc93a0331b86dab66f93564a846890c479edad58e1ac59247053c8037 | PE 段表、导入目录（IAT 槽→DLL!符号）、汇编清单解析 |

依赖：Python 3.13.5，仅标准库（argparse/csv/struct/sys/pathlib/re/json）——无 capstone/pefile。

## 复跑命令与输出路径

~~~sh
mkdir -p repro/code && cp <原件>/FindComponent.dll repro/ \
  && cp <候选>/calls.csv repro/ \
  && cp <候选>/code/native.asm repro/code/ \
  && cp <候选>/code/s33-two-hop.csv repro/code/
python -B tool/s37_two_hop.py --folder repro \
  --binary repro/FindComponent.dll \
  --prev repro/code/s33-two-hop.csv \
  --out repro/out/s37-two-hop.csv
~~~

输出：repro/out/s37-two-hop.csv（161 行）。

## 空目录复跑结果

~~~
repro sha 72918f68564e24dcb5e6f376bc04deacd0cc3ceece560198cfcba0a519d906bf
expect   72918f68564e24dcb5e6f376bc04deacd0cc3ceece560198cfcba0a519d906bf
MATCH (161 rows, 0 empty first_hop/iat/calls_row)
~~~

## 判定（原始输出）

check-s33.py exit 0：
~~~
{
  "original_sha256": "3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02",
  "listing_instructions": 5055,
  "two_hop": {
    "first_hop": 161,
    "iat_slot": 161,
    "import_symbol": 161,
    "main_class": 161,
    "original_host": 161,
    "candidate_owner": 161,
    "asm": 161,
    "calls_row": 161,
    "main_symbol_matches": 161,
    "rows": 161
  },
  "examples": [
    {
      "site": "0x106c",
      "first_hop": "0x4aa3",
      "iat_slot": "0x75e8",
      "symbol": "mfc140.dll!#2344",
      "expected_original_host": "0x1060",
      "expected_listing_owner": "0x1060",
      "claimed_listing_owner": "0x1060",
      "asm_line": 28,
      "expected_calls_rows": [
        525
      ],
      "claimed_calls_row": "525"
    },
    {
      "site": "0x1072",
      "first_hop": "0x4aa9",
      "iat_slot": "0x75e0",
      "symbol": "mfc140.dll!#2348",
      "expected_original_host": "0x1060",
      "expected_listing_owner": "0x1060",
      "claimed_listing_owner": "0x1060",
      "asm_line": 30,
      "expected_calls_rows": [
        526
      ],
      "claimed_calls_row": "526"
    },
    {
      "site": "0x12da",
      "first_hop": "0x5cfc",
      "iat_slot": "0x70c8",
      "symbol": "OLEAUT32.dll!#313",
      "expected_original_host": "0x11e0",
      "expected_listing_owner": "0x12bd",
      "claimed_listing_owner": "0x12bd",
      "asm_line": 208,
      "expected_calls_rows": [
        528
      ],
      "claimed_calls_row": "528"
    }
  ],
  "mismatches": [
~~~

check-native-coverage.py exit 2：
~~~
checked 307 coverage rows, 307 tool-native entries, 684 call records, 0 declared gaps
~~~

## 机器指标（calls.csv 现算）

- calls 684 = external 524 + data 48 + unresolved 112
- direct_iat 363、indirect_annex 99 单列
- two_hop 161、com 64、dispatch 16
- 指纹 calls d6f82133e5187d15 / coverage 3afe1c2a87c9e70c / two-hop 72918f68564e24dc
