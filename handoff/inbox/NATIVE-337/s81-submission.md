# NATIVE-337 s81 提交（ShowDialog 调用语义 + JMP/INC 配对）

- 固定候选：#445 @ 44fcb193；同一分支 head 前移。

## A. ShowDialog 参数与结果（0x1320–0x1483）
| 项 | 位置 | 证据 |
| --- | --- | --- |
| UTF-16LE 字符串 | 0x1345 → 0x7820 | `LEA RAX,[rip+0x64D4]`，目标字节 `53 00 68 00 6F 00 77 00 44 00 69 00 61 00 6C 00 6F 00 67 00` = **"ShowDialog"** |
| 区域设置 | 0x1357 | `CALL [0x180007060]` = KERNEL32.dll!GetUserDefaultLCID → lcid |
| DISPID 请求 | 0x1389 | `CALL [RBX+0x28]` = GetIDsOfNames(this=RCX, rgszNames=RDX, cNames=[RSP+0x20], lcid=R9D, rgDispId=[RSP+0x28]) |
| DISPID 输出缓冲 | 0x1365 | `MOV [RSP+0x28],RCX`，RCX=&[RSP+0xC8] |
| 分支 | 0x138E | `JNS 0x13A0`：HRESULT≥0 走 Invoke；<0 走 Release + 返回 0 |
| Invoke | 0x1444 | `CALL [RBX+0x30]`：dispIdMember=RDX([RSP+0xC8])、riid=R8=0x82F8(IID_NULL，16 字节全零)、lcid=R9D、wFlags=[RSP+0x20]=1(DISPATCH_METHOD)、pDispParams=[RSP+0x28]、pVarResult=[RSP+0x30]、pExcepInfo=[RSP+0x38]、puArgErr=[RSP+0x40] |
| DISPPARAMS | 0x13A2–0x13B1 | `[RSP+0x50]=&[RSP+0x68]`(rgvarg)、`[RSP+0x58]=0`(rgdispidNamedArgs)、`[RSP+0x60]=R14(1)`(cArgs/cNamedArgs 区) |
| 结果 | 0x1449 `CMOVNS ESI,[RSP+0x88]` → 0x1469 `MOV EAX,ESI` | 返回值是 **int/bool**（1=成功、0=失败） |
| 两次 Release | 0x1396（GetIDsOfNames 失败路径）、0x1457（Invoke 之后） | `CALL [reg+0x10]` = Release |

### 失败路径（书面）
- 工厂返回 0：0x133D `MOV RDI,RAX` → `TEST RAX` → 0x1343 `JZ 0x1399` → `XOR EAX,EAX` → 0x139B 跳 0x146B 收尾，返回 0。
- GetIDsOfNames 失败：0x138E `JNS` 不跳 → 0x1390 `MOV RAX,[RDI]` → 0x1396 Release → 0x1399 返回 0。
- 进一步绑定条件：需要实际对象或其注册证据（CLSID/ProgID + 类型库），才能把 Invoke 的 dispIdMember 绑定到具体成员并给出实现地址；当前已证边界止于此。

## B. 工具侧
1. **真正的 RIP 相对间接 JMP**：新增 `tool/s81_jmp_pair.py`，按 modrm 判型——`FF /4 mod=00 rm=101` 才是 10 字节 `jmp [rip+disp32]`；`FF /2` 为 call；`FF /0-/1 mod=11` 为 inc/dec。用例含“相同 disp32 字节但 modrm 不同”的混淆对，全部 PASS。
2. **配对脚本继承依赖环境**：`tool/s69_tests.py` 的 subprocess 现继承 os.environ 并兜底 `PYTHONPATH=D:/Lib/site-packages`；在 `env -u PYTHONPATH` 下重跑仍全 PASS。

## C. 保持 + 新增配对
- 161 站、三布局（单文件/同目录/子目录）保持 161/0x106C→525/0x12DA→528。
- 新增 JMP/INC 配对（见 B1），`PAIR jmp-vs-inc : jmp=jmp inc=inc PASS`。

## 判定（原始 stdout）
~~~
checked 307 coverage rows, 307 tool-native entries, 684 call records, 0 declared gaps
~~~
exit code: 2（112 条未决已申报）

## 指纹
- 见 work/s81-tools.txt（本轮从实际文件生成）
