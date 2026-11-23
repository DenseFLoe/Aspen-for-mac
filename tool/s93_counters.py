# -*- coding: utf-8 -*-
"""s93 counterexamples: change one byte of the input, the conclusion must change.

A: 0x13DD vt immediate 8 -> 9   => binding table 'variant-vt' must report 9
B: 0x137F riid rip disp        => calls-riid RVA / GUID must change (no longer IID_NULL)
"""
import csv, shutil, struct, subprocess, sys, tempfile
from pathlib import Path

BASE = Path('handoff/inbox/NATIVE-337')
BIN = Path('_t13/orig/FindComponent.dll')


def copy(name):
    d = Path(tempfile.mkdtemp(prefix='s93-')) / name
    shutil.copytree(BASE, d, ignore=shutil.ignore_patterns('*.prev.csv', 'work', 's8*-fingerprints.json'))
    return d


def gen(d, out):
    r = subprocess.run([sys.executable, '-B', 'tool/s81_showdialog.py', '--folder', str(d),
                        '--binary', str(BIN), '--out', str(out)], capture_output=True, text=True)
    return r.returncode, r.stdout + r.stderr


def rows(out):
    return {r['item']: r for r in csv.DictReader(open(out, encoding='utf-8'))}


def main():
    ok = True
    base = copy('base')
    rc, txt = gen(base, base / 'base.csv')
    b = rows(base / 'base.csv')
    print('base vt=%s riid=%s' % (b['variant-vt']['instruction'], b['calls-riid']['rva']))

    # A: vt immediate 8 -> 9 in the binary the generator reads
    d = copy('vt')
    import struct as _s
    sys.path.insert(0, 'tool')
    from pe_reader import PE as _PE
    data = bytearray(BIN.read_bytes())
    _pe = _PE(bytes(data))
    data[_pe.filepos(0x13DD) + 1] = 9
    (d / 'vt.dll').write_bytes(bytes(data))
    r = subprocess.run([sys.executable, '-B', 'tool/s81_showdialog.py', '--folder', str(d),
                        '--binary', str(d / 'vt.dll'), '--out', str(d / 'vt.csv')],
                       capture_output=True, text=True)
    rc = r.returncode
    a = rows(d / 'vt.csv')
    changed = a['variant-vt']['instruction'] != b['variant-vt']['instruction'] and '9' in a['variant-vt']['instruction']
    print('A vt-change : rc=%d %s -> %s status=%s' % (rc, b['variant-vt']['instruction'],
                                                      a['variant-vt']['instruction'], 'PASS' if changed else 'FAIL'))
    ok &= changed

    # B: riid rip displacement 0x6F72 -> 0x6F62
    d2 = copy('riid')
    p2 = d2 / 'code' / 'native.asm'
    ls2 = p2.read_text(encoding='utf-8').splitlines()
    j = next(k for k, l in enumerate(ls2) if l.startswith('0000137F'))
    ls2[j] = ls2[j].replace('72 6F 00 00', '62 6F 00 00')
    p2.write_text(chr(10).join(ls2) + chr(10), encoding='utf-8')
    # the generator reads the ORIGINAL for the rip target, so patch a binary copy too
    orig = bytearray(BIN.read_bytes())
    sys.path.insert(0, 'tool')
    from pe_reader import PE
    pe = PE(bytes(orig))
    off = pe.filepos(0x137F) + 3
    orig[off:off + 4] = struct.pack('<i', 0x6F62)
    patched = d2 / 'patched.dll'
    patched.write_bytes(bytes(orig))
    r = subprocess.run([sys.executable, '-B', 'tool/s81_showdialog.py', '--folder', str(d2),
                        '--binary', str(patched), '--out', str(d2 / 'riid.csv')], capture_output=True, text=True)
    c = rows(d2 / 'riid.csv')
    moved = c['calls-riid']['rva'] != b['calls-riid']['rva'] or c['calls-riid']['instruction'] != b['calls-riid']['instruction']
    print('B riid-change: rc=%d %s -> %s status=%s' % (r.returncode, b['calls-riid']['rva'],
                                                      c['calls-riid']['rva'], 'PASS' if moved else 'FAIL'))
    ok &= moved
    print('SUITE :', 'ALL PASS' if ok else 'FAILURES PRESENT')
    return 0 if ok else 1


if __name__ == '__main__':
    sys.exit(main())
