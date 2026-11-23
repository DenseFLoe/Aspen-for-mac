# NATIVE-337 s109 独立复验

原件 FindComponent.dll SHA-256 3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02。主干 19f94421ea3b724df2b27f65f71832db0259f34d，[#445 固定候选](https://github.com/DenseFLoe/Aspen-for-mac/tree/4012387e21fdcb6d4867d5757f6fc64776a51030)。两提交共改 8 路。独立核对 191 个候选文件的 Git blob、大小和 SHA-256。[固定文件指纹](s109-fixed-manifest.json)

    python -B s109-replay.py ORIGINAL LIVE_REGISTRATION_JSON NEW_OUTPUT_DIR CANDIDATE_ROOT MAIN_CHECKER
    python -B tool/s109_verify.py --binary ORIGINAL --folder UNIT --listing --signature
    python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original ORIGINAL --submission UNIT

候选检查器 SHA-256 623181d5e34ea84bec5ca19ddea2989cf09779a4c519dfe73a768f79c8032e52。主干覆盖 v1 SHA-256 27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8，输出 307 条覆盖、307 个原生入口、684 条引用、0 个已声明覆盖缺口，exit 2。再生的绑定表 28 行逐字节相同，其中 variant-vt 一行。112 条间接目标仍未决。

本机重新读取 64 位注册项、部署 PE 与元数据，字节与交付附件相同。确证完整类型名、InterfaceImpl、双方 ShowDialog 签名 2001080E、接口 RVA 0、实现 RVA 0xA848 及 PE SHA-256 04e68b8eca60b732e661bf322d74b6f042abeba9ea801e2e2e410c1be007b5d5。候选实际只读附件、交付表及两条原件列表指令，部署程序集与注册项不在其调用路径。缺原件而单运行 --signature 仍 exit 0。

基线和等价 JSON 布局 exit 0，前轮十一项反例均点名并 exit 3。每个新增反例复制同一固定候选，仅改单项交付证据并更新副本活动指纹。预期定位冲突，实测如下。

| 单项改动 | 预期定位 | 实测 |
| --- | --- | --- |
| InterfaceImpl 改为 IFindComponentDriver2 | 接口身份 | exit 0，零冲突 |
| 单改实现命名空间 | 完整类型身份 | exit 0，零冲突 |
| 单改 Registry64.CLSID | 注册身份 | exit 0，零冲突 |
| 在正确行前加同键相反签名行 | 冲突重复键 | exit 0，零冲突 |

InterfaceImpl 仍用子串。字典构造用后一行覆盖前一行。建议从独立固定部署 PE 和注册证据取实际类型身份，按类型句柄或完整标识比较，在字典构造前拒绝冲突重复行。以上四组输入和等价 JSON 组可直接回归。先查输入存在并绑定证据，缺失时明确待核。稳定读取 DLL 只作为本件绑定证据，生产门禁的变更需独立评审。[逐例证据](s109-recheck.json) · [复验脚本](s109-replay.py) · [采集脚本](s109-read-registration.ps1)

活动清单 109/110 匹配。work/s109-exclusions.txt 声明 ea5c63bc…，实际 e77fc139…。#13 声明排除 work/*-exclusions.txt，固定排除说明仅列三个模式，活动清单却包含两份 exclusions。复验保留固定树，成对副本先重算已声明指纹。提交说明首页及检测回执仍引用旧固定头和旧检查入口。协作者套件的实际退出与输入哈希另附。[原始输出](s109-counters-readback.json)

固定树重跑 s109、s101、s105 三个套件均 exit 0。s109 基线树指纹实测 2c6fe796213052a9217d2db78f47621de91ae537b5ec2dc31283a9044d990b25，协作者回执为 7f586dfd…。s101、s105 套件的实际调用仍是旧 tool/s101_verify.py。输入指纹与入口以固定树回读为准。
