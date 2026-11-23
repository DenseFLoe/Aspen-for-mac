# NATIVE-340 s97 提交

- 分支：tietoumiao/native-340-s33（前移 #450，不新开 PR）
- 上轮固定候选：#450 @ 22135b6596af10a318fc80483b9c20d3680115bb；主干 263497c5
- 本轮 head：见 #13

## ① cli_tables 单一来源

TABLES 现在是唯一的逐列定义（("coded", tag_bits, 有序目标表, tag_offset)）：行宽累加 fsize()、字段读取、
decode_column() 三者都从这份定义派生（并行查表 CODED_COLUMNS 已删除）。顺带修正 tag 位宽：
MemberRef.Class 2→3、MethodImpl.MethodBody/MethodDeclaration 2→1，CustomAttribute.Type 标为
("coded", 3, [6,10], 2)（tag 2/3）。

## ② 阈值 + 紧邻列

tool/s93-width-controls.py 除校验编码定义，还检查下一列字节偏移随宽度同步移动：

| 配对 | 行数 | 本列宽 | 下一列偏移 |
| --- | --- | ---: | --- |
| MemberRefParent | 8191 / 8192 | 2 / 4 | 0 / +2 |
| CustomAttributeType | 8191 / 8192 | 2 / 4 | 0 / +2 |
| MethodDefOrRef | 16383 / 16384 / 32767 / 32768 | 2 / 2 / 2 / 4 | 0 / 0 / 0 / +2 |

## ③ 控制脚本

    $ python -B tool/s93-width-controls.py .
    width-controls: pairs=3 mismatches=0        exit 0

    $ python -B tool/s93-width-controls.py . --lib _t14/old_cli_tables.py
    MISMATCH table=CustomAttribute column=Type spec (2, [6, 10], 0) != (3, [6, 10], 2)
    width-controls: pairs=3 mismatches=1        exit 1

## ④ 最后 19 行关联

tool/s97-site-owners.py 按原件函数边界校验：FUNC 内站点写该 FUNC 起点；跳板块 0x4711-0x476A 写块起点并在
note 标「待核依据」；0x2BCF 不在任何 FUNC 内，写站点自身并给编码依据。

- 0x2BCF：48 FF 25 82 34 00 00（REX.W 前缀 0x48，disp 0x3482，目标 0x2BCF+7+0x3482 = IAT 0x6058）。
- 最后三跳板：0x477D→0x4777、0x47D1→0x47CB、0x4894→0x488E（均在对应 FUNC 内）。
- 正反例：0x2B7A 记 0x2B74 → exit 0；只改 0x3660 → exit 1，输出
  MISMATCH listing=code/native.asm#L1508 owner=0x3660 site=0x2B7A must name FUN_0x2B74。

## ⑤ 更正与补件

- CustomAttribute[1].Type 原值 19（此前 18 有误），解码 MemberRef[2]。
- PEReader 工程固定路径：tool/pereader_340/pereader_340.csproj + Program.cs（dotnet run -c Release -- ORIGINAL）。
- QA 依赖：python -m pip install --target .local/pylibs keystone-engine==0.9.2 capstone==5.0.7 pefile==2024.8.26；
  gate 用 PYTHONPATH=.local/pylibs；keystone 缺失会让 rebuild 单元 error/fail（不会假绿）。

## 保留

167 条只读摘要（tool/verify_il_digests.py）、四组对照、0x06000057 arg0 静态恢复条件。

## 判定

qa gate 93bf962c 的 14 单元结果与 §33 检验器脚本节见下。

## 检验器脚本

| 脚本 | 字节 | sha256 | 用途 |
| --- | ---: | --- | --- |
| tool/verify_il_digests.py | 1958 B | 3693094d52e76e40ba43aee56cbb6d379defde219a43ce10d3a27c654a25aec6 | 只读摘要复验（167 条，保留行身份） |
| tool/s93-width-controls.py | 3134 B | 8374898c760cce153ca2b5ab541a6a261c3a9d848ae230544dfb79aa4635e551 | 列宽+紧邻列控制（正确/错列两版） |
| tool/s97-site-owners.py | 2258 B | ac0bed8004f0c23e38d6338ce40931cc4538661bed1af82ca6337715cebdc976 | 19 站点归属校验（正反例） |
| tool/audit_340_s89.py | 9087 B | e5ce33401c14f4acf01b7340bc4678b18c2814ea6d2dd077846ba9c3b6792f82 | 回归脚本 |
| tool/cli_tables.py | 15217 B | 3ca027e7ce2187e5537d2540efbbf7fb9e32450b2849eb95ed9779f4a864fed1 | 表流解析（单一来源列定义） |

运行命令（逐条可复制；REPO 为仓库根）：

    python -B tool/verify_il_digests.py --binary _t13/orig/WrapSaveMergeNNFiles.dll --table handoff/inbox/NATIVE-340/code/s89-il-digests.csv
    python -B tool/s93-width-controls.py .
    python -B tool/s97-site-owners.py .
    cd _t14/qa/93bf962c && PYTHONPATH=<REPO>/.local/pylibs python -B -m qa.gate --task NATIVE-340 --item-dir <REPO>/handoff/inbox/NATIVE-340 --original <REPO>/_t13/orig/WrapSaveMergeNNFiles.dll

原始输出 + 真实 exit：

    checked 167 rows, mismatches 0                                  exit 0
    width-controls: pairs=3 mismatches=0                            exit 0
    site-owners: checked=19 mismatches=0                            exit 0

版本 pin：qa gate 93bf962c (MANIFEST files sha256 0f8be7a96e6dfa528116f28663d182b83ae60481896e1796975d27a398394c81)；上游 checker pin 27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8。
