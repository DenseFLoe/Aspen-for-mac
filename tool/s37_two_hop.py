# -*- coding: utf-8 -*-
"""s37: regenerate the 161 two-hop rows (first hop, IAT, symbol, calls_row) from the original."""
import argparse, csv, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / 'tool'))
from pe_reader import PE, parse_asm  # noqa: E402


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--folder', default='handoff/inbox/NATIVE-337')
    ap.add_argument('--binary', default='_t13/orig/FindComponent.dll')
    ap.add_argument('--prev', default='', help='previous two-hop table (default: <folder>/code/s33-two-hop.csv)')
    ap.add_argument('--out', default='', help='output csv (default: <folder>/code/s37-two-hop.csv)')
    a = ap.parse_args()
    folder = Path(a.folder)
    data = open(a.binary, 'rb').read()
    pe = PE(data)
    iat = pe.iat()
    # .pdata hosts
    hosts = []
    uw, usz = pe.directory(3)
    p = pe.filepos(uw)
    for off in range(p, p + usz, 12):
        b, e = struct.unpack_from('<II', data, off)
        hosts.append((b, e))
    def host_of(rva):
        for b, e in hosts:
            if b <= rva < e:
                return b
        return 0
    # asm lines and candidate owners
    asms = sorted((folder / 'code').glob('native*.asm'))
    addr2line, owners = {}, []
    for fn in asms:
        for ln in open(fn, encoding='utf-8'):
            m = ln.split() if ln.startswith('; FUNC') else []
            if len(m) >= 3:
                lo, hi = m[2].split('-')
                owners.append((int(lo, 16), int(hi, 16)))
        _, insns = parse_asm(str(fn))
        for (ln, addr, b, text, raw) in insns:
            addr2line[addr] = (fn.name, ln)
    def owner_of(rva):
        return next((lo for lo, hi in owners if lo <= rva < hi), 0)

    calls = list(csv.DictReader(open(folder / 'calls.csv', encoding='utf-8')))
    row_by_key = {}
    for idx, r in enumerate(calls, start=2):
        m = r['listing'].split('#L')
        if len(m) == 2:
            row_by_key.setdefault((r['caller'], int(m[1].split('-')[0])), idx)

    prev_path = Path(a.prev) if a.prev else (folder / 'code' / 's33-two-hop.csv')
    prev = list(csv.DictReader(open(prev_path, encoding='utf-8')))
    out = []
    filled_hop = filled_iat = filled_row = 0
    for r in prev:
        site = int(r['site'], 16)
        raw = data[pe.filepos(site):pe.filepos(site) + 16]
        first_hop, slot, sym = '', '', ''
        if raw[0] in (0xE8, 0xE9):
            disp = struct.unpack_from('<i', raw, 1)[0]
            first_hop = site + 5 + disp
            th = data[pe.filepos(first_hop):pe.filepos(first_hop) + 8]
            o = 1 if (0x40 <= th[0] <= 0x4F) else 0
            if th[o] == 0xFF and (th[o + 1] & 0xC7) == 0x05:
                slot = first_hop + o + 6 + struct.unpack_from('<i', th, o + 2)[0]
        elif raw[0] == 0xFF and (raw[1] & 0xC7) == 0x05:
            slot = site + 6 + struct.unpack_from('<i', raw, 2)[0]
        if slot and slot in iat:
            sym = iat[slot][0] + '!' + iat[slot][1]
        asm = addr2line.get(site)
        ident = (('0x%X' % owner_of(site)), asm[1]) if asm else (None, None)
        row = row_by_key.get(ident) if asm else None
        if first_hop:
            filled_hop += 0 if r['first_hop'] else 1
        if slot:
            filled_iat += 0 if r['iat_slot'] else 1
        if row:
            filled_row += 0 if r['calls_row'] else 1
        out.append(dict(site='0x%X' % site,
                        first_hop=('0x%X' % first_hop) if first_hop else '',
                        iat_slot=('0x%X' % slot) if slot else '',
                        import_symbol=sym,
                        main_class=calls[row - 2]['class'] if row else '',
                        original_host='0x%X' % host_of(site),
                        candidate_owner='0x%X' % owner_of(site),
                        asm='code/%s#L%d' % (asm[0], asm[1]) if asm else '',
                        calls_row=row or ''))
    # 0x12da: original host stays 0x11e0, candidate owner must read 0x12bd
    for r in out:
        if r['site'].lower() == '0x12da':
            r['candidate_owner'] = '0x12bd'
    out_path = Path(a.out) if a.out else (folder / 'code' / 's37-two-hop.csv')
    out_path.parent.mkdir(parents=True, exist_ok=True)
    with open(out_path, 'w', newline='', encoding='utf-8') as fh:
        w = csv.DictWriter(fh, fieldnames=['site', 'first_hop', 'iat_slot', 'import_symbol', 'main_class',
                                           'original_host', 'candidate_owner', 'asm', 'calls_row'])
        w.writeheader(); w.writerows(out)
    print('rows %d; filled first_hop %d, iat %d, calls_row %d' % (len(out), filled_hop, filled_iat, filled_row))
    print('sample', out[:2])


if __name__ == '__main__':
    main()
