# NATIVE-337 s105 独立复验

固定 #445 候选 8a261635459e2e862b034ed3fd3a6d02dcc10dd9，主干 44c22e3daac712802e8a7e865a42c301f70b714b。上轮固定头 fa42db6 至本轮共 8 次提交、13 条增改路径。巡检中间头 18edf44 至最终交付头仅改提交说明、独立反例脚本并新增 s105c 门禁日志。原件 FindComponent.dll SHA-256 为 3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02。185 个范围内文件逐一比对 Git blob 和 SHA-256。交付目录 160 文件，活跃清单 109/109 匹配。声明的三个排除模式之外仍未列 code/README.md、work/s49-inputs.json、work/s61-layouts.json、work/s105b-gate.json。s101 清单现有 139 项，未列 work/s101-gate.txt，表中 code/s81-showdialog.csv 一项为旧指纹。[固定文件与差异](s105-fixed-manifest.json)

## 重放

在装有同版本 Aspen 的 PowerShell 7 执行 `./s105-read-registration.ps1`，脚本在同目录生成 `registration.json`。使用固定主干的 check-native-coverage.py、固定候选根目录、原生原件、上述独立部署 PEReader 回读以及新输出目录。复验脚本以 SHA-256 约束原件、入口和依赖。下列命令中的大写参数须替换为相应路径。

```text
python -B s105-replay.py MAIN_CHECKER CANDIDATE_ROOT ORIGINAL LIVE_REGISTRATION_JSON NEW_OUTPUT_DIR
python -B tool/s101_verify.py --binary ORIGINAL --folder UNIT --listing --signature
python -B tool/s81_showdialog.py --binary ORIGINAL --folder UNIT --out REGENERATED_CSV
python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original ORIGINAL --submission UNIT
```

同安装独立采集的元数据 JSON 与固定附件逐字节一致，SHA-256 72abab6b73c616bc454ede59d9698510cee968a26100dbaaf07627ffa86b363e。部署 PE 的独立 SHA-256 为 04e68b8eca60b732e661bf322d74b6f042abeba9ea801e2e2e410c1be007b5d5。IFindComponentDriver.ShowDialog 的签名 2001080E、RVA 0，与实现同签名、RVA A848；FindComponentDriver 的 InterfaceImpl 指向 IFindComponentDriver。每个用例从相同固定树重新复制，只改一项交付证据并更新活跃指纹，运行后重核全部声明文件。[复验脚本](s105-replay.py) · [退出码、输出与指纹](s105-recheck.json)

| 用例 | 预期 | 实测 |
| --- | --- | --- |
| 基线、等价 JSON 键序 | 通过 | 两项 exit 0 |
| 分别改两处列表（0x13DD / 0x137F） | 定位对应站点 | 两项 exit 3 |
| 分别改实现方法名、RVA、签名；改单元格签名或移除附件 | 定位改动 | 五项均 exit 3，输出字段与文件 |
| 仅删除类的接口实现关系 | 定位缺少 InterfaceImpl | exit 0，零冲突 |
| 仅改接口 RVA 0→1 | 定位接口 RVA | exit 0，零冲突 |
| 仅改附件内的部署 PE SHA-256 | 定位附件与固定部署 PE、交付表的身份冲突 | exit 0，零冲突 |
| 仅改交付表内实现地址 0xA848→0xA8480 | 定位完整 RVA 不一致 | exit 0，零冲突 |

交付入口 s101_verify.py 的 verify_signature 仅读 s97-registration.json 及交付表，用第 19–23 行常量校验，未独立读取部署 PE 或固定回读，未核 InterfaceImpl 和接口 RVA。第 107 行用子串查表内地址，使 0xA8480 通过。协作回执列入口为旧版 3,091 B、SHA e75b4bc0…，固定头实为 5,151 B、SHA 57d8cdeec3d3369a32d2c86279df8b0a6c7edea7910081efc273b4bdd7a0215a。同样，生成器固定头为 9,917 B、SHA efc2a76909c2b8950c4eb1213cc460e1afa4c04227c1799c8c75648f75d8ef55，脚本表填了 9,431 B 的旧版。完整指纹见复验 JSON。

固定树内执行 `python -B tool/s105_counters.py` 得到四例一致的输入摘要 89289f14f78446fe7f177984297a3ac49ce6beefc81872bfe95138cbd8d4785d，四例定位、总 exit 0。回执写 07869974…，在最终固定树无法复现。fresh() 排除了工作目录和活动清单，测试没有重算活动清单。第 61 行打印被测输入运行前后是否相等，第 65 行未将它计入成败。运行 `python -B tool/s101_counters.py`，两站通过，签名被正确拒绝，但旧测试仍查找旧格式 `CONFLICT site=`，总 exit 1。完整原始输出见复验 JSON。

28 行表重新生成后与交付逐字节相同，唯一 variant-vt 行。原件 0x13C2 及 0x13CB 计算 i×3×8，0x13CF 调 VariantInit，0x13DD、0x13E2 写入标签 8，0x13E7 存入 BSTR 指针。表及本轮说明已分别说明 vt=VT_EMPTY、24 字节数组步幅与调用方写 VT_BSTR。[Microsoft VariantInit](https://learn.microsoft.com/en-us/windows/win32/api/oleauto/nf-oleauto-variantinit)

正式主干覆盖入口 SHA-256 27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8。全件复跑 307 行覆盖、307 原生条目、684 条调用、0 个声明缺口，exit 2。调用分为 524 external、48 data、112 unresolved。交付所附 QA 93bf962c 日志为 11 pass、3 not-applicable、0 fail、0 error。该数字为协作者记录。本次独立运行的入口和实际退出见复验 JSON。
