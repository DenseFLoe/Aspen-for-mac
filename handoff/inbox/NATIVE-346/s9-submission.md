# ppexec.dll 第九号提交

NATIVE-346，assigned_seq=9，owner upstream。原件 SHA-256 `d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a`。基础源码及资源沿用第五号固定候选 `fa54788674fb9deebde754613d9e30ae3c306463`。本次回执按[任务卡](../../assignments/NATIVE-346-s9.md)、[上游原生标准](../../standards/native-coverage-upstream.v1.md)和[逐件说明](ppexec.dll.md)提交。

20 处上轮待查索引中，14 处已核实正常入口下的表内范围，1 处从已知入口未见可达路径，5 处需补调用方的长度声明。14 处回调中有 4 处受原始只读零槽限制，另 10 处在主表保留未决标记，其中一处已确认直接调用者所传的内部函数。3,334 条主表引用、3,500 条内部边和 15 个剩余位置均可从逐址证据重建。

三个入口共 39 次八字节写入经逐指令符号核对，覆盖 IWNC、WNC1 到 WNC10 以及末端输出。扫描 12,498 条指令得到 26 个数据导出的直接基址访问情况。另以第 350 号原件确认 PPEXEC_PPROY 首字段按 binary64 读取并参与乘法，生产方连续写入 72 字节。整体声明、变量长度与未决转移待补证；正常运行留待 Windows 对照阶段。

## 复跑

以本件目录为 U、原件为 P、任务 350 原件为 Z，第五轮候选同件目录为 S。使用 Python、Capstone 5.0.6、pefile 2024.8.26。

```text
python -B U/s9/check-selector-bounds.py P U/s5
python -B U/s9/callbacks.py P
python -B U/s9/inspect-data.py P U
python -B U/s9/cross-check.py P Z
python -B U/s9/update-tables.py S <已有的独立输出目录>
python -B handoff/assignments/check-native-coverage.py NATIVE-346 --original P
```

当前主干判定器退出 2，记录 532 个覆盖行、532 个工具入口、3,334 条引用、0 个入口缺口。完整清单指纹及裁定绑定本次候选提交。[本轮文件清单](s9-manifest.sha256)
