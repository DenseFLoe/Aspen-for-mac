# NATIVE-337 s25 提交

## 从实际表生成的计数

| 项 | 值 | 表 |
| --- | ---: | --- |
| indirect 附件行 | 99 | code/indirect.csv |
| 重算后的推导行 | 99 | code/indirect-resolved.csv |
| 宿主/候选归属分列行（不一致） | 99（16） | code/s25-host-vs-candidate.csv |
| 0x4706 内存分派 | 16 | code/s25-0x4706-dispatches.csv |
| 其中可证 vtable 槽 | 16 | 同上 |
| 其中实现地址静态可定 | 0 | 同上 |
| IDispatch 槽记录（可绑成员） | 64（64） | code/s25-idispatch-slots.csv |
| calls.csv 行 | 684 | calls.csv |
| unresolved | 112 | calls.csv |
| coverage 行 | 307 | coverage.csv |

## 产物指纹

- calls.csv 7bd46572102cd73fd5ceaa58fc0e783ec30bf0c6fee54e078b4be186871da7d5
- coverage.csv 3afe1c2a87c9e70c95a8a9216d5f68798fd14e934ff75fa8dc49d41fee00fb43
- code/indirect-resolved.csv 4e5a96285567d441d3d2fd89313e28a26f7fa231ebaaacf1968b11a2bcf60278
- code/s25-0x4706-dispatches.csv 6fefbb8583693c80ef3a4ff1454aa0c43465b87ab5a86a699c7d0e91e3133b8e

## 未决

申报入口缺口 0，但去重后仍有 112 条 unresolved（寄存器/接口指针动态目标），以及 64 条 IDispatch 实现地址需运行期对象。
