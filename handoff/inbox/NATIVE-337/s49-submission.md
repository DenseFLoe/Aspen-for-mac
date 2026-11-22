# NATIVE-337 s49 提交

- 沿用 #445 分支（不新开 PR），本轮回执与产物随 head 前移。
- 生成器：tool/s37_two_hop.py a2ed8736…；依赖 tool/pe_reader.py c0efbbff…；测试 tool/s45_tests.py。
- 依赖：Python 3.13.5，仅标准库；check-s33.py 需 capstone/pefile（PYTHONPATH=D:/Lib/site-packages）。

## 推导顺序（按卡）
1. 原件字节 → 首跳（E8/E9 rel32）、IAT 槽、导入符号；
2. 原件 .pdata 异常目录 → 原件宿主；
3. 候选清单 FUNC 片段（多条命中取最内层）→ 候选宿主；
4. 清单引用位置 → calls.csv 行号。
旧附表不再参与推导，仅作回归基准（code/s37-two-hop.prev.csv）。

## 四场景测试（一条命令，tool/s45_tests.py，exit 0 = ALL PASS）
~~~
A no-prev      : rc=0 rows=161 status=PASS
B drop-row     : rc=0 rows=161 recovered_0x106C=True status=PASS
C boundary     : rc=0 candidate_owner=0x12B6 original_host=0x11E0 status=PASS
D replay       : rc=0 rows=161 sha256=2ef4b467155284f011c9fecd7c457c80cbfb9bff148b0acee7c4a60c5e8a20bf status=PASS
  baselines    : historical(72918f68) match=False ; s45-uppercase(2ef4b467) match=True
TOOLS          : generator=a2ed873660620bf468db10f6716c812c9ef207c6972e21622411b7ff00a6c271 pe_reader=5383333399175b94f3624d5ef95db2fbffdc1d8c0f23b6983ef3cc01e4e87367 tests=30e9c6cd3fc881eac7a31d64a2903b3c9ea5ceb2fc4fecd2a1be622d08c0c58e
SUITE          : ALL PASS
~~~

## 两个基准
- 历史回归：72918f68564e24dcb5e6f376bc04deacd0cc3ceece560198cfcba0a519d906bf（旧表，含已删除的地址特判 → 0x12bd 小写）
- 本轮固定布局：2ef4b467155284f011c9fecd7c457c80cbfb9bff148b0acee7c4a60c5e8a20bf（candidate_owner 统一 0x 前缀大写，现行输出）

## 判定
~~~
$ python -B handoff/outbox/NATIVE-337/check-s33.py <原件> handoff/inbox/NATIVE-337
exit 0（two_hop 161 全栏 / COM 64 / dispatch 16 / metrics 全对）
$ python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original <原件> --submission handoff/inbox/NATIVE-337
checked 307 coverage rows, 307 tool-native entries, 684 call records, 0 declared gaps
exit 2
~~~

## 保留
363 直接 IAT、13 GuardCF、16 对象槽、64 COM、161 二跳 RVA 集合均未改动；calls 684 = external 524 / data 48 / unresolved 112。
