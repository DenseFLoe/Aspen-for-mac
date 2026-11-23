# -*- coding: utf-8 -*-
"""s73 B: recover receiver / slot / init path for the four indirect calls in 0x1320."""
import csv, sys
from pathlib import Path

sys.path.insert(0, 'tool')
from pe_reader import parse_asm

OUT = Path('handoff/inbox/NATIVE-337/code/s73-four-calls.csv')
ASM = Path('handoff/inbox/NATIVE-337/code/native.asm')

SLOT_MEMBER = {0x00: 'QueryInterface', 0x08: 'AddRef', 0x10: 'Release',
               0x18: 'GetTypeInfoCount', 0x20: 'GetTypeInfo',
               0x28: 'GetIDsOfNames', 0x30: 'Invoke'}

# (site, receiver_reg, vtable_load_site, slot, init_evidence)
CASES = [
    ('0x1389', 'RBX', '0x1354', 0x28, '0x1338 CALL 0x180002330 -> RDI;0x1354 MOV RBX,[RDI]'),
    ('0x1396', 'RAX', '0x1390', 0x10, '0x1338 CALL 0x180002330 -> RDI;0x1390 MOV RAX,[RDI]'),
    ('0x1444', 'RBX', '0x1400', 0x30, '0x1400 MOV RBX,[RDI];0x1441 MOV RCX,RDI'),
    ('0x1457', 'RDX', '0x1451', 0x10, '0x1451 MOV RDX,[RDI];0x1454 MOV RCX,RDI'),
]


def main():
    _, ins = parse_asm(str(ASM))
    by = {a: (l, b, t) for (l, a, b, t, r) in ins}
    rows = []
    for site, reg, load, slot, init in CASES:
        s = int(site, 16)
        ln, b, t = by[s]
        rows.append(dict(site=site, instruction=t, bytes=b.hex(), asm='code/native.asm#L%d' % ln,
                         receiver_reg=reg, vtable_load='%s (%s)' % (load, by[int(load, 16)][2]),
                         slot='0x%02X' % slot, member=SLOT_MEMBER[slot],
                         init_path='factory 0x180002330 (CoCreateInstance import at 0x2388) -> RDI',
                         init_evidence=init,
                         target_status='unresolved: object created at runtime; slot/member proven, implementation address needs a breakpoint or type library',
                         recovery='breakpoint at 0x1354/0x1390/0x1400/0x1451 to read the vtable pointer, or load the type library for the CLSID used at 0x2330'))
    OUT.parent.mkdir(parents=True, exist_ok=True)
    with open(OUT, 'w', newline='', encoding='utf-8') as fh:
        w = csv.DictWriter(fh, fieldnames=list(rows[0].keys()))
        w.writeheader(); w.writerows(rows)
    for r in rows:
        print(r['site'], r['slot'], r['member'], '|', r['instruction'])


if __name__ == '__main__':
    main()
