#!/usr/bin/env bash
# Emit the mandatory verifier-script receipt section. Everything is measured live.
set -u
ORIG="_t13/orig/WrapSaveMergeNNFiles.dll"
UNIT="handoff/inbox/NATIVE-340"
GATE="_t14/qa/27007e5a"
echo "## 检验器脚本"
echo
echo "| 脚本 | 字节 | sha256 | 用途 |"
echo "| --- | ---: | --- | --- |"
for pair in "tool/verify_il_digests.py|交付校验入口（167 条 IL 摘要逐行复验）" "tool/audit_340_s89.py|回归脚本（列宽/阈值/配对/摘要/EH/站点）" "tool/cli_tables.py|表流解析（CODED_COLUMNS 按表+列解码）" "tool/gen_fingerprints_340.py|两套指纹生成"; do
  f=$(echo "$pair" | cut -d'|' -f1)
  use=$(echo "$pair" | cut -d'|' -f2-)
  size=$(stat -c%s "$f")
  digest=$(sha256sum "$f" | cut -d' ' -f1)
  echo "| $f | $size B | $digest | $use |"
done
echo
echo '执行（逐条可复制；REPO 为仓库根）：'
echo '```'
echo "python -B tool/verify_il_digests.py --binary $ORIG --table $UNIT/code/s89-il-digests.csv"
echo "python -B tool/audit_340_s89.py --binary $ORIG --folder $UNIT"
echo "PYTHONPATH=.local/pylibs python -B -m qa.gate --task NATIVE-340 --item-dir $UNIT --original $ORIG"
echo '```'
echo
echo '原始输出（stdout 原文 + 真实 exit）：'
echo '```'
echo "\$ python -B tool/verify_il_digests.py --binary $ORIG --table $UNIT/code/s89-il-digests.csv"
python -B tool/verify_il_digests.py --binary "$ORIG" --table "$UNIT/code/s89-il-digests.csv" 2>&1
echo "exit $?"
echo
echo "\$ python -B tool/audit_340_s89.py --binary $ORIG --folder $UNIT"
python -B tool/audit_340_s89.py --binary "$ORIG" --folder "$UNIT" 2>&1
echo "exit $?"
echo
REPO=$(pwd)
echo "\$ cd $GATE && PYTHONPATH=$REPO/.local/pylibs python -B -m qa.gate --task NATIVE-340 --item-dir $REPO/$UNIT --original $REPO/$ORIG"
( cd "$GATE" && PYTHONPATH="$REPO/.local/pylibs" python -B -m qa.gate --task NATIVE-340 --item-dir "$REPO/$UNIT" --original "$REPO/$ORIG" 2>&1 )
echo "exit $?"
echo '```'
