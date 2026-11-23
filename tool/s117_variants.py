# -*- coding: utf-8 -*-
"""s113 variants: duplicate keys, interface edge, namespace, CLSID - each from a fresh copy."""
import hashlib, json, shutil, subprocess, sys, tempfile
from pathlib import Path

BASE = Path('handoff/inbox/NATIVE-337')
BIN = '_t13/orig/FindComponent.dll'


def tree_hash(root):
    h = hashlib.sha256()
    for p in sorted(Path(root).rglob('*')):
        if p.is_file():
            h.update(p.relative_to(root).as_posix().encode()); h.update(b'\0')
            h.update(hashlib.sha256(p.read_bytes()).digest())
    return h.hexdigest()


def fresh(tag):
    d = Path(tempfile.mkdtemp(prefix='s113-%s-' % tag)) / 'cand'
    shutil.copytree(BASE, d, ignore=shutil.ignore_patterns('*.prev.csv', 'work', 's*-fingerprints.json'))
    return d


def verify(d):
    r = subprocess.run([sys.executable, '-B', 'tool/s117_verify.py', '--folder', str(d),
                        '--binary', BIN, '--signature'], capture_output=True, text=True)
    return r.returncode, (r.stdout + r.stderr).strip()


def main():
    ok = True
    hashes = []
    base = fresh('base')
    bh = tree_hash(base)
    print('baseline input_manifest_hash:', bh)

    def case(title, tag, mutate, expect):
        nonlocal ok
        d = fresh(tag)
        hashes.append((title, tree_hash(d)))
        mutate(d)
        rc, txt = verify(d)
        hit = expect in txt and rc == 3
        print('%-28s rc=%d located=%s status=%s' % (title, rc, hit, 'PASS' if hit else 'FAIL'))
        for line in txt.splitlines():
            if line.startswith('CONFLICT'):
                print('   ', line)
        ok &= hit

    def edit(d, fn):
        reg = d / 's97-registration.json'
        doc = json.loads(reg.read_text(encoding='utf-8'))
        fn(doc)
        reg.write_text(json.dumps(doc, ensure_ascii=False, indent=2), encoding='utf-8')

    def edit(d, fn):
        reg = d / 's97-registration.json'
        doc = json.loads(reg.read_text(encoding='utf-8'))
        fn(doc)
        reg.write_text(json.dumps(doc, ensure_ascii=False, indent=2), encoding='utf-8')

    # A: contradictory duplicate CSV rows in the delivery table
    def csv_dupe(d):
        tbl = d / 'code' / 's81-showdialog.csv'
        lines = tbl.read_text(encoding='utf-8').splitlines()
        idx = next(i for i, l in enumerate(lines) if l.startswith('id-sig-impl,'))
        lines.insert(idx + 1, lines[idx].replace('2001080E', '20010E0E'))
        tbl.write_text(chr(10).join(lines) + chr(10), encoding='utf-8')

    case('A duplicate CSV row', 'csvdupe', csv_dupe, 'field=duplicate_row')

    # B: wrong registered class
    case('B wrong registry class', 'class',
         lambda d: edit(d, lambda doc: doc['Registry64'].__setitem__('class', 'AspenTech.AspenPlus.WpfFindComponent.OtherDriver')),
         'field=class')

    # C: bare lowercase interface name (different .NET type)
    case('C bare iface lowercase', 'case',
         lambda d: edit(d, lambda doc: doc['FindComponentDriver'].__setitem__('interfaces', ['ifindcomponentdriver'])),
         'field=InterfaceImpl')

    # D: independent signature input missing -> must be marked pending, never guessed
    case('D missing signature input', 'nosig',
         lambda d: edit(d, lambda doc: doc['IFindComponentDriver']['methods'][0].pop('signature', None)),
         'field=signature')

    same = len({h for _, h in hashes}) == 1
    print('input_manifest_hash identical:', same)
    ok &= same
    print('SUITE :', 'ALL PASS' if ok else 'FAILURES PRESENT')
    return 0 if ok else 1


if __name__ == '__main__':
    sys.exit(main())
