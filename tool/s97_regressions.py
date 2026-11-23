# -*- coding: utf-8 -*-
"""s97 regressions: mutate ONLY the listing, the original stays byte-identical.

A: listing 0x13DD vt immediate 8 -> 9   (original untouched) -> variant-vt listing_matches flips to no
B: listing 0x137F riid disp 0x6F72 -> 0x6F62 (original untouched) -> calls-riid listing_matches flips to no
"""
import csv, shutil, subprocess, sys, tempfile
from pathlib import Path

BASE = Path('handoff/inbox/NATIVE-337')
BIN = Path('_t13/orig/FindComponent.dll')


def copy(name):
    d = Path(tempfile.mkdtemp(prefix='s97-')) / name
    shutil.copytree(BASE, d, ignore=shutil.ignore_patterns('*.prev.csv', 'work', 's9*-fingerprints.json'))
    return d


def gen(d, out):
    r = subprocess.run([sys.executable, '-B', 'tool/s81_showdialog.py', '--folder', str(d),
                        '--binary', str(BIN), '--out', str(out)], capture_output=True, text=True)
    return r.returncode, r.stdout + r.stderr


def field(out, item):
    for r in csv.DictReader(open(out, encoding='utf-8')):
        if r['item'] == item:
            return r['meaning']
    return ''


def flag(meaning):
    i = meaning.find('listing_matches=')
    return meaning[i:i + 22] if i >= 0 else ''


def main():
    ok = True
    base = copy('base')
    rc, _ = gen(base, base / 'base.csv')
    b_vt = flag(field(base / 'base.csv', 'variant-vt'))
    b_ri = flag(field(base / 'base.csv', 'calls-riid'))
    print('base  : variant-vt %s | calls-riid %s' % (b_vt, b_ri))

    d = copy('vt')
    p = d / 'code' / 'native.asm'
    ls = p.read_text(encoding='utf-8').splitlines()
    i = next(k for k, l in enumerate(ls) if l.startswith('000013DD'))
    ls[i] = ls[i].replace('B8 08 00 00 00', 'B8 09 00 00 00')
    p.write_text(chr(10).join(ls) + chr(10), encoding='utf-8')
    rc, _ = gen(d, d / 'vt.csv')
    a_vt = flag(field(d / 'vt.csv', 'variant-vt'))
    a_ok = rc == 0 and 'no' in a_vt and a_vt != b_vt
    print('A listing-only vt 8->9   : %s -> %s status=%s' % (b_vt, a_vt, 'PASS' if a_ok else 'FAIL'))
    ok &= a_ok

    d2 = copy('riid')
    p2 = d2 / 'code' / 'native.asm'
    ls2 = p2.read_text(encoding='utf-8').splitlines()
    j = next(k for k, l in enumerate(ls2) if l.startswith('0000137F'))
    ls2[j] = ls2[j].replace('72 6F 00 00', '62 6F 00 00')
    p2.write_text(chr(10).join(ls2) + chr(10), encoding='utf-8')
    rc, _ = gen(d2, d2 / 'riid.csv')
    b2 = flag(field(d2 / 'riid.csv', 'calls-riid'))
    b_ok = rc == 0 and 'no' in b2 and b2 != b_ri
    print('B listing-only riid disp : %s -> %s status=%s' % (b_ri, b2, 'PASS' if b_ok else 'FAIL'))
    ok &= b_ok

    print('SUITE :', 'ALL PASS' if ok else 'FAILURES PRESENT')
    return 0 if ok else 1


if __name__ == '__main__':
    sys.exit(main())
