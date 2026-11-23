# -*- coding: utf-8 -*-
"""s101 counterexamples through the PRODUCT verifier (tool/s101_verify.py).

L1: listing-only single edit at 0x13DD and at 0x137F (original untouched) -> must be refused and named.
L2: only the implementation signature changes (original and deployed assembly untouched), affected
    fingerprints updated -> must be located or marked pending, never silently pass.
"""
import json, shutil, subprocess, sys, tempfile
from pathlib import Path

BASE = Path('handoff/inbox/NATIVE-337')
BIN = Path('_t13/orig/FindComponent.dll')


def copy(name):
    d = Path(tempfile.mkdtemp(prefix='s101-')) / name
    shutil.copytree(BASE, d, ignore=shutil.ignore_patterns('*.prev.csv', 'work', 's9*-fingerprints.json'))
    return d


def verify(d, *flags):
    r = subprocess.run([sys.executable, '-B', 'tool/s101_verify.py', '--folder', str(d),
                        '--binary', str(BIN)] + list(flags), capture_output=True, text=True)
    return r.returncode, (r.stdout + r.stderr).strip()


def main():
    ok = True
    for site, old, new in (('000013DD', 'B8 08 00 00 00', 'B8 09 00 00 00'),
                           ('0000137F', '72 6F 00 00', '62 6F 00 00')):
        d = copy('lst-' + site)
        p = d / 'code' / 'native.asm'
        ls = p.read_text(encoding='utf-8').splitlines()
        i = next(k for k, l in enumerate(ls) if l.startswith(site))
        ls[i] = ls[i].replace(old, new)
        p.write_text(chr(10).join(ls) + chr(10), encoding='utf-8')
        rc, txt = verify(d, '--listing')
        hit = 'CONFLICT site=0x%s' % site[4:].lstrip('0') in txt
        good = rc == 3 and hit
        print('L1 %s listing-only : rc=%d named=%s status=%s' % (site, rc, hit, 'PASS' if good else 'FAIL'))
        print('   ', [l for l in txt.splitlines() if l.startswith('CONFLICT')][:1])
        ok &= good

    d = copy('sig')
    reg = d / 's97-registration.json'
    doc = json.loads(reg.read_text(encoding='utf-8'))
    doc['FindComponentDriver']['methods'][0]['signature'] = '20010E0E'
    reg.write_text(json.dumps(doc, ensure_ascii=False, indent=2), encoding='utf-8')
    rc, txt = verify(d, '--signature')
    hit = 'CONFLICT site=FindComponentDriver.ShowDialog' in txt
    good = rc == 3 and hit
    print('L2 signature-only  : rc=%d named=%s status=%s' % (rc, hit, 'PASS' if good else 'FAIL'))
    print('   ', [l for l in txt.splitlines() if l.startswith('CONFLICT')][:2])
    ok &= good
    print('SUITE :', 'ALL PASS' if ok else 'FAILURES PRESENT')
    return 0 if ok else 1


if __name__ == '__main__':
    sys.exit(main())
