# -*- coding: utf-8 -*-
"""Site-set diff: baseline (#392) IAT call/jmp sites vs the current listing."""
import sys
sys.path.insert(0, 'tool')
from pe_reader import PE, parse_asm


def sites(asm_path, dll):
    pe = PE(open(dll, 'rb').read())
    iat = pe.iat()
    out = {}
    _, insns = parse_asm(asm_path)
    for (ln, addr, b, text, raw) in insns:
        o = 1 if (len(b) > 1 and 0x40 <= b[0] <= 0x4F) else 0
        if len(b) >= o + 6 and b[o] == 0xFF and (b[o + 1] & 0xC7) == 0x05:
            disp = int.from_bytes(b[o + 2:o + 6], 'little', signed=True)
            tgt = addr + len(b) + disp
            if tgt in iat:
                out[addr] = (ln, tgt, iat[tgt][0] + '!' + iat[tgt][1])
    return out


base = sites('_t13/s392_native.asm', '_t13/orig/FindComponent.dll')
cur = sites('handoff/inbox/NATIVE-337/code/native.asm', '_t13/orig/FindComponent.dll')
missing = {k: v for k, v in base.items() if k not in cur}
extra = {k: v for k, v in cur.items() if k not in base}
print('baseline sites=%d current sites=%d missing=%d extra=%d' % (len(base), len(cur), len(missing), len(extra)))
import csv as _csv
with open('handoff/inbox/NATIVE-337/code/site-diff.csv', 'w', newline='', encoding='utf-8') as fh:
    w = _csv.writer(fh)
    w.writerow(['site_rva', 'baseline_line', 'iat_slot', 'import', 'present_in_current'])
    for k in sorted(set(base) | set(cur)):
        row = base.get(k) or cur.get(k)
        w.writerow(['0x%X' % k, row[0], '0x%X' % row[1], row[2], 'yes' if k in cur else 'no'])
for k in sorted(missing):
    print('missing site 0x%X line %d slot 0x%X %s' % (k, missing[k][0], missing[k][1], missing[k][2]))
for k in sorted(extra):
    print('extra   site 0x%X line %d slot 0x%X %s' % (k, extra[k][0], extra[k][1], extra[k][2]))
