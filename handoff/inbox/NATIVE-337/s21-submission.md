# NATIVE-337 s21 提交

- 基线：#422 候选 cc6f30c82bcc107e769672705cfe4bd8fea025c2（363 直接导入 / 13 GuardCF / 2 寄存器来源 / 303 覆盖键全部保留）
- 原件 SHA-256：3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02
- 本轮回执计数全部由 code/ 下的实际表生成（tool/s21_receipt.py）

## 判定

~~~sh
python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original <固定原件>
checked 307 coverage rows, 307 tool-native entries, 684 call records, 0 declared gaps
~~~

exit code: 2（结构齐备 + 112 条 unresolved 已申报）

## 1. 64 处 COM

- 定位：64 / 64（code/dispatch-sites.csv，操作数位移与 s17 附表一致）
- 可绑定到成员：**64 / 64**（IUnknown::QueryInterface/AddRef/Release、IDispatch::GetTypeInfoCount/GetTypeInfo/GetIDsOfNames/Invoke，按 vtable 槽 0x00/0x08/0x10/0x18/0x20/0x28/0x30）
- 实现地址：0 处可静态确定 → 全部 unresolved，恢复条件写在各行 detail（需要类型库/CoCreateInstance 运行期断点取 interface pointer）

## 2. 161 条二跳

- 归属到调用方：161 / 161（8 处未归属已按调用后继解决：0x60C7/0x60D7/0x60E7/0x60F7/0x6107/0x6117/0x6147 → 0x60C0/0x60D0/0x60E0/0x60F0/0x6100/0x6110/0x6140，经 thunk 0x11D0 → IAT 0x70D0 → OLEAUT32.dll!#9；0x616E → 0x6160，经 thunk 0x4D73 → IAT 0x7280 → mfc140.dll!#1438）
- 已进入主调用表：+161 行 external（caller→跳板→IAT 逐行可回读）

## 3. 指令差异（36 条）

- 非填充指令 **9 处**：9 处已恢复为候选汇编中的独立指令起址（0x1292/0x1297/0x129a/0x129c/0x12b6/0x12b8/0x5089/0x55c7/0x55c9），归属 0x11E0 与 0x4FF8/0x54AC
- 填充差异 **27 处**（INT3/NOP）：按原件字节确认，属函数间对齐/热补丁填充，不影响控制流
- 表：code/s21-instruction-status.csv（逐行 in_candidate / owner / status）

## 4. 保留基线

- 363 直接 IAT 站点（site-diff：missing 0 / extra 0）
- 13 处 GuardCF 分派（code/guardcf-sites.csv 13 行，字节吻合逐条）
- 2 处寄存器来源沿用
- 覆盖键 307（s17 的 303 + 4 处非填充指令宿主）

## 限制

- COM 实现地址无法静态确定（需类型库或运行期取 interface pointer）。
- 申报入口缺口 0，但去重后仍有 112 条 unresolved 待核。
