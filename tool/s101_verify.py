# -*- coding: utf-8 -*-
"""s101 product-path verifier: refuse a contradictory listing / signature.

--listing : for 0x13DD and 0x137F the listing bytes must equal the original; a single-byte edit is
             refused and the site is named.
--signature: interface signature, implementation signature and the declared sig must all agree;
             a mutated implementation signature is reported as a conflict (not silently accepted).
"""
import argparse, json, sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from pe_reader import PE, parse_asm

SITES = {0x13DD: 5, 0x137F: 7}


def read_listing(asm):
    _, ins = parse_asm(str(asm))
    return {addr: b.hex() for (ln, addr, b, t, r) in ins}


def verify_listing(folder, binary):
    data = Path(binary).read_bytes()
    pe = PE(data)
    listing = read_listing(Path(folder) / 'code' / 'native.asm')
    bad = []
    for site, n in SITES.items():
        orig = data[pe.filepos(site):pe.filepos(site) + n].hex()
        got = listing.get(site)
        if got is None:
            bad.append((site, 'missing-from-listing', orig, ''))
        elif not got.startswith(orig):
            bad.append((site, 'listing-mismatch', orig, got))
    return bad


def verify_signature(folder):
    reg = Path(folder) / 's97-registration.json'
    if not reg.exists():
        return []
    d = json.loads(reg.read_text(encoding='utf-8'))
    def sig(key):
        ms = (d.get(key, {}) or {}).get('methods') or [{}]
        return ms[0].get('signature', '')
    iface, impl = sig('IFindComponentDriver'), sig('FindComponentDriver')
    out = []
    if iface != '2001080E':
        out.append(('interface', 'IFindComponentDriver.ShowDialog', '2001080E', iface))
    if impl != '2001080E':
        out.append(('implementation', 'FindComponentDriver.ShowDialog', '2001080E', impl))
    if iface and impl and iface != impl:
        out.append(('iface-vs-impl', 'signature disagreement', iface, impl))
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--folder', default='handoff/inbox/NATIVE-337')
    ap.add_argument('--binary', default='_t13/orig/FindComponent.dll')
    ap.add_argument('--listing', action='store_true', help='refuse a listing that contradicts the original')
    ap.add_argument('--signature', action='store_true', help='refuse a signature conflict')
    a = ap.parse_args()
    rc = 0
    if a.listing:
        bad = verify_listing(a.folder, a.binary)
        for site, kind, orig, got in bad:
            print('CONFLICT site=0x%X kind=%s original=%s listing=%s' % (site, kind, orig, got))
        print('listing-check: sites=%d conflicts=%d' % (len(SITES), len(bad)))
        if bad:
            rc = 3
    if a.signature:
        bad = verify_signature(a.folder)
        for kind, where, want, got in bad:
            print('CONFLICT site=%s kind=%s expected=%s found=%s' % (where, kind, want, got))
        print('signature-check: conflicts=%d' % len(bad))
        if bad:
            rc = 3
    return rc


if __name__ == '__main__':
    sys.exit(main())
