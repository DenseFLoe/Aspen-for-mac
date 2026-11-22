# NATIVE-337 s53 提交（补交测试脚本 + 回读校验）

## cause（写进流程的教训）
s49 交付时 `tool/s45_tests.py` 只在本机运行、**未进提交**（manifest 漏列该路径），导致「可复跑测试」这条实际未交付；同时 `tool/s37_two_hop.py` 的 s45 版也因同一原因未推。修法：**任何声称交付的路径，提交后必须从远端 head 回读 blob 并核对 SHA-256**，本地跑通不等于已交付。

## 回读结果（head 见 #13）
| 路径 | blob sha | size | sha256 |
| --- | --- | ---: | --- |
| tool/s37_two_hop.py | 5866f0c97b711c9dbc54a2e5acdef8c4373276f4 | 4848 | a2ed873660620bf468db10f6716c812c9ef207c6972e21622411b7ff00a6c271 |
| tool/s45_tests.py | 0e28effc5f7aa19ed678e8914eb2486ec24d1ee0 | 5047 | 30e9c6cd3fc881eac7a31d64a2903b3c9ea5ceb2fc4fecd2a1be622d08c0c58e |
| tool/pe_reader.py | （本轮重推后回读见 #13） | 5769 | c0efbbffc93a0331b86dab66f93564a846890c479edad58e1ac59247053c8037 |

## 四场景（按分支固定文件跑，一条命令）
~~~
A no-prev      : rc=0 rows=161 status=PASS
B drop-row     : rc=0 rows=161 recovered_0x106C=True status=PASS
C boundary     : rc=0 candidate_owner=0x12B6 original_host=0x11E0 status=PASS
D replay       : rc=0 rows=161 sha256=2ef4b467155284f011c9fecd7c457c80cbfb9bff148b0acee7c4a60c5e8a20bf status=PASS
TOOLS          : generator=a2ed8736... pe_reader=c0efbbff... tests=30e9c6cd...
SUITE          : ALL PASS
~~~

## 判定
~~~
python -B handoff/outbox/NATIVE-337/check-s33.py <原件> <候选>   → exit 0
python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original <原件> --submission <候选>
checked 307 coverage rows, 307 tool-native entries, 684 call records, 0 declared gaps   → exit 2
~~~

## 附：历史附表
code/s37-two-hop.prev.csv（历史回归基准，sha 72918f68…）；code/s45-two-hop.csv（本轮固定布局，sha 2ef4b467…）。
