# NATIVE-337 s49 验收器复验

沿用 [s45 已知问题](s45-verifier-notes.md)。固定版本为主干 `183ec4aeb38f5463a99aadc2fbdbbc3326ce243a` 中的 `check-s33.py`，SHA-256 `467c949dd92d04db4d92dc248c8d3690d282ec9e54eb7929ec97cee21f30e58f`。

    python -B handoff/outbox/NATIVE-337/check-s33.py ORIGINAL CANDIDATE

本次 [#445 固定输入](https://github.com/DenseFLoe/Aspen-for-mac/tree/2c9db5656867da19de3c6b53ee4400220b407fd5) 的 `check-s33.py` 退出 0。s49 卡同时要求当前生成器、依赖和测试在该 head 可重放。新证据是该 head 的新版生成器指纹不符和测试路径 404。欠缺的文件须由人工逐项回读，历史附表检查只覆盖原有输入。[各指纹和输出](s49-review.json)

建议给当前轮次增加一个独立的交付清单核验小步，从固定提交读取路径并比较 SHA-256。回归用例沿用 s49 三个工具的回执摘要和原件。全部实件与声明一致时通过清单核验。其余项固定，删除测试脚本时应指名缺件。换回旧生成器时应指名摘要不符。随后仍须单独复验生成器推导结果。
