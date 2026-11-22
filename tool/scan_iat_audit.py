# -*- coding: utf-8 -*-
"""Audit an IAT call/jmp scan against a calls.csv: prints sites / registered / missing by form."""
import argparse, csv, re, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / 'tool'))
from pe_reader import PE, parse_asm  # noqa: E402


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--asm', required=True)
    ap.add_argument('--dll', required=True)
    ap.add_argument('--calls', default='')
    a = ap.parse_args()
    pe = PE(Path(a.dll).read_bytes())
    iat = pe.iat()
    _, insns = parse_asm(a.asm)
    sites = {}
    for (ln, addr, b, text, raw) in insns:
        o = 1 if (len(b) > 1 and 0x40 <= b[0] <= 0x4F) else 0
        if len(b) >= o + 6 and b[o] == 0xFF and (b[o + 1] & 0xC7) == 0x05:
            disp = int.from_bytes(b[o + 2:o + 6], 'little', signed=True)
            tgt = addr + len(b) + disp
            if tgt in iat:
                sites[addr] = (ln, 'call' if (b[o + 1] >> 3) == 2 else 'jmp', iat[tgt])
    reg = set()
    if a.calls and Path(a.calls).exists():
        for r in csv.DictReader(open(a.calls, encoding='utf-8-sig')):
            m = re.search(r'#L(\d+)', r.get('listing', ''))
            if m:
                reg.add(int(m.group(1)))
    miss = {k: v for k, v in sites.items() if v[0] not in reg}
    from collections import Counter
    print('iat_sites=%d registered=%d missing=%d' % (len(sites), len(sites) - len(miss), len(miss)))
    print('missing_forms=%s' % dict(Counter(v[1] for v in miss.values())))
    print('registered_forms=%s' % dict(Counter(v[1] for k, v in sites.items() if v[0] in reg)))
    for k in sorted(miss)[:5]:
        print('  missing %#x line %d %s %s!%s' % (k, miss[k][0], miss[k][1], miss[k][2][0], miss[k][2][1]))
    return 0


if __name__ == '__main__':
    sys.exit(main())
