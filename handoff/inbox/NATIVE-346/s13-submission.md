# ppexec.dll 第十三号提交

NATIVE-346，owner upstream，assigned_seq=13。原件 SHA-256 d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a，版本 41.0.0.605。复用了此前 532 个原件代码范围并核对 12,498 条指令。含入口转移在内的可执行节扫描覆盖 81,451 字节。

0x11c56 的前置检查读取 PE 节 Characteristics 的写权限位。0x22148 在原件的可写 .data 虚拟尾端，故正常映像转到 0x11c59。0x121c0 经 0x15d00 分派，0x14e06 传入 0x11b24，保留在内部边表。0x20a80 的三个读取和一个交换写入已有原件证据，尚缺能到达交换例程的注册来源。0x14c60 由两个 XFG 槽转发至 0x15d00，原件回退为 0x14c40；加载器更新后的地址和各入口的 RAX 仍按调用方追踪。GuardMemcpy 原件槽经 0x1479a 到 0x150b8 的 VCRUNTIME140.dll!memcpy。

19 个调用方分别向复制和填充分派器传 R8；两套缓存的实际写入为 0x20a90、0x20a98。分派器保留 R8，固定字节数与元素数乘八的路径均有定位。五个位置的动态计数上界尚待实际生产者或声明证明。26 个数据导出已核标签及边界，剩余对象类型和分配长度继续缺依据。

从仓库根目录运行：

~~~text
python -B handoff/inbox/NATIVE-346/s13/check-callbacks.py <ppexec.dll> handoff/inbox/NATIVE-346 handoff/outbox/NATIVE-346/trace-callbacks.py
python -B handoff/assignments/check-native-coverage.py NATIVE-346 --original <ppexec.dll>
~~~

复跑环境为 Capstone 5.0.7、pefile 2024.8.26。检查器 532 个覆盖行、532 个工具入口、3,332 条引用、0 个已申报入口缺口，退出 2，剩 13 处未决。[清单](s13-manifest.sha256) · [逐址裁定](s13/disposition.csv)
