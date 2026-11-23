# NATIVE-337 s113 独立复验

原件 FindComponent.dll，SHA-256 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`。主干 `c8ec21865e2a9afc48873757ec1da993ceaf2f26`，[#445 固定候选](https://github.com/DenseFLoe/Aspen-for-mac/tree/7c18f40da2b6ef2d74a897b0983d9d5175ca20af)。独立以 Git blob 和大小核对交付目录、tool 和 qa 三棵树共 204 个文件，再计算 SHA-256。[清单](s113-fixed-manifest.json)

    python -B s113-replay.py ORIGINAL LIVE_REGISTRATION_JSON NEW_OUTPUT_DIR CANDIDATE MAIN_CHECKER
    python -B tool/s113_verify.py --binary ORIGINAL --folder UNIT --listing --signature
    python -B s113-registration-control.py CANDIDATE
    python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original ORIGINAL --submission UNIT

候选检查器 SHA-256 `6b426eaf429b0d17babf9f82cab7e7845a63b1335c381d336f2e0bf9079f2175`。主干覆盖 v1 SHA-256 `27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8`，实测 307 条覆盖、307 个入口、684 条引用、0 个声明缺口，exit 2，112 条间接目标未决。ShowDialog 交付表重生后逐字节一致。独立重新读取本机 64 位注册项和部署 PE 元数据，所得 JSON 与固定附件逐字节一致。PE SHA-256 `04e68b8eca60b732e661bf322d74b6f042abeba9ea801e2e2e410c1be007b5d5`，接口和实现的签名均为 2001080E，接口 RVA 为 0，部署实现 RVA 为 0xA848。[采集命令](s113-read-registration.ps1)

基线与仅更换 JSON 排序和空白均 exit 0。旧十一项拒绝仍定位并 exit 3。接口加尾缀、实现错命名空间、错误 CLSID 和前置矛盾 JSON 签名键亦定位并 exit 3。下列对照取同一固定候选，每组只改一项交付证据并更新指纹，或只改变一个输入路径。

| 单项改动 | 预期 | 实测 |
| --- | --- | --- |
| 前置同键 `id-sig-impl` 行，签名写 `2001090E`，保留正确后行 | 定位 CSV 重复证据并拒绝 | exit 0，两项检查均报告零冲突 |
| 裸 InterfaceImpl 写为小写 `ifindcomponentdriver` | 无独立类型句柄佐证时拒绝错误的精确名称 | exit 0，两项检查均报告零冲突 |
| 只改 `Registry64.class` 为 `...FindComponentDriver2` | 定位 CLSID 到类的绑定矛盾 | exit 0，两项检查均报告零冲突 |
| `--signature` 原件输入路径指向不存在的文件，附件仍完整 | 缺独立输入时待核或退出非零 | `signature-check: conflicts=0`，exit 0 |

CSV 在构造字典时由后行覆盖前行，裸接口名经 `same_ident` 转为小写，签名路径读取交付附件里的 SHA-256 和注册字段，未从独立部署 PE 读取 TypeDef 或方法。建议按精确类型句柄及完整名称验证接口，检查注册 class 到部署实现的绑定，并在建立 CSV 索引前拒绝矛盾。以该表四个副本为回归，保持等价 JSON 布局 exit 0，缺独立输入标待核，矛盾证据定位并 exit 3。[成对复验与原始输出](s113-recheck.json) · [注册类反例第二次复跑](s113-registration-control.json)

活动清单 109/109 指纹吻合。固定树同版本生成器产出 110 条，唯一缺项是 `code/README.md`。回执未写活动清单 SHA-256，也未列 s113 各脚本指纹、可复制命令及最终头输出。旧审计页指纹可通过清单中的反向索引核对。审计本轮复跑报告 10 对、0 命中、exit 0，未覆盖 `same_ident` 大小写折叠导致的精确身份差异。
