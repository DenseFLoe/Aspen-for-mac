# -*- coding: utf-8 -*-
"""s73 A: derive the 161 two-hop stations from the original binary alone.

Independent of any candidate listing or previous table:
  * decode every executable section linearly (capstone, x86-64)
  * keep E8/E9 rel32 whose target body is FF25 [rip+disp] pointing into the IAT
  * de-duplicate by site RVA
"""
import argparse, json, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / 'tool'))
from pe_reader import PE  # noqa: E402

try:
    import capstone
except ImportError:  # allow running with PYTHONPATH=D:/Lib/site-packages
    for p in ('D:/Lib/site-packages',):
        sys.path.append(p)
    import capstone


def thunk_slot(data, pe, rva):
    try:
        p = pe.filepos(rva)
    except ValueError:
        return None
    b = data[p:p + 8]
    o = 1 if b and 0x40 <= b[0] <= 0x4F else 0
    if len(b) >= o + 6 and b[o] == 0xFF and (b[o + 1] & 0xC7) == 0x05:
        return rva + o + 6 + struct.unpack_from('<i', b, o + 2)[0]
    return None


def derive(data, pe):
    iat = pe.iat()
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    md.detail = False
    sites = {}
    for sec in pe.secs:
        if not sec['exec']:
            continue
        try:
            p = pe.filepos(sec['rva'])
        except ValueError:
            continue
        blob = data[p:p + sec['size']]
        for ins in md.disasm(blob, sec['rva']):
            if ins.mnemonic not in ('call', 'jmp') or len(ins.bytes) != 5:
                continue
            if ins.bytes[0] not in (0xE8, 0xE9):
                continue
            disp = struct.unpack_from('<i', ins.bytes, 1)[0]
            hop = ins.address + 5 + disp
            slot = thunk_slot(data, pe, hop)
            if slot in iat:
                sites[ins.address] = (hop, slot, iat[slot][0], iat[slot][1])
    rows = []
    for site in sorted(sites):
        hop, slot, lib, nm = sites[site]
        rows.append(dict(site='0x%X' % site, first_hop='0x%X' % hop, iat_slot='0x%X' % slot,
                         import_symbol='%s!%s' % (lib, nm),
                         site_bytes=data[pe.filepos(site):pe.filepos(site) + 5].hex()))
    return rows


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--binary', default='_t13/orig/FindComponent.dll')
    ap.add_argument('--json', default='work/s73-stations.json')
    ap.add_argument('--csv', default='handoff/inbox/NATIVE-337/code/s73-stations.csv')
    a = ap.parse_args()
    data = Path(a.binary).read_bytes()
    pe = PE(data)
    rows = derive(data, pe)
    out = Path(a.csv)
    out.parent.mkdir(parents=True, exist_ok=True)
    import csv as _csv
    with open(out, 'w', newline='', encoding='utf-8') as fh:
        w = _csv.DictWriter(fh, fieldnames=['site', 'first_hop', 'iat_slot', 'import_symbol', 'site_bytes'])
        w.writeheader(); w.writerows(rows)
    Path(a.json).write_text(json.dumps(rows, ensure_ascii=False, indent=1), encoding='utf-8')
    print('stations', len(rows), '->', out)


if __name__ == '__main__':
    main()
