# -*- coding: utf-8 -*-
"""s17 step 2: fill the two register-operand derivations (0x4A7C CALL RAX, 0x53F2 CALL R9)."""
import csv, struct, sys
from pathlib import Path
ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / 'tool'))
from pe_reader import PE, parse_asm

CASES = [
    dict(call=0x4A7C, src=0x4A64, reg='RAX',
         note='寄存器操作数来源：0x4A64 MOV RAX,[0xB6F8]（.data 全局，文件无初始化值=0，运行期写入）；0x4A7C CALL RAX 目标取决于该全局'),
    dict(call=0x53F2, src=0x53EB, reg='R9',
         note='寄存器操作数来源：0x53EB MOV R9,[0x7670]（GuardCFDispatchFunctionPointer 槽，磁盘值 0x180006050 → 0x6050 JMP RAX）；0x53F2 CALL R9 走已证的 GuardCF 分派路径，运行期目标未知'),
]


def main():
    folder = Path('handoff/inbox/NATIVE-337')
    data = open('_t13/orig/FindComponent.dll', 'rb').read()
    pe = PE(data)
    _, insns = parse_asm(str(folder / 'code' / 'native.asm'))
    by = {a: (ln, b, t) for (ln, a, b, t, _) in insns}
    calls = list(csv.DictReader(open(folder / 'calls.csv', encoding='utf-8')))
    out = []
    for c in CASES:
        ln, b, t = by[c['call']]
        row = next((r for r in calls if r['listing'].endswith('#L%d-L%d' % (ln, ln))), None)
        assert row is not None, hex(c['call'])
        row['class'] = 'unresolved'
        row['callee'] = 'dynamic via %s' % c['note'].split('：')[1][:60]
        row['note'] = c['note']
        out.append(dict(call_rva='0x%X' % c['call'], bytes=b.hex(), instr=t,
                        source_rva='0x%X' % c['src'], source_bytes=by[c['src']][1].hex(),
                        source_instr=by[c['src']][2], derived=c['note']))
    with open(folder / 'calls.csv', 'w', newline='', encoding='utf-8') as fh:
        w = csv.DictWriter(fh, fieldnames=['kind', 'caller', 'callee', 'class', 'listing', 'note'])
        w.writeheader(); w.writerows(calls)
    with open(folder / 'code' / 'register-operands.csv', 'w', newline='', encoding='utf-8') as fh:
        w = csv.DictWriter(fh, fieldnames=['call_rva', 'bytes', 'instr', 'source_rva', 'source_bytes', 'source_instr', 'derived'])
        w.writeheader(); w.writerows(out)
    print('filled', len(out), 'register derivations; calls', len(calls))


if __name__ == '__main__':
    main()
