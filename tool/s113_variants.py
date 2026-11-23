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
    r = subprocess.run([sys.executable, '-B', 'tool/s113_verify.py', '--folder', str(d),
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

    case('InterfaceImpl -> ...2', 'edge',
         lambda d: edit(d, lambda doc: doc['FindComponentDriver'].__setitem__('interfaces', ['IFindComponentDriver2'])),
         'field=InterfaceImpl')
    case('impl namespace', 'ns',
         lambda d: edit(d, lambda doc: doc['FindComponentDriver'].__setitem__('namespace', 'Other.Namespace')),
         'field=namespace')
    case('Registry64.CLSID', 'clsid',
         lambda d: edit(d, lambda doc: doc['Registry64'].__setitem__('CLSID', '{00000000-0000-0000-0000-000000000000}')),
         'field=CLSID')

    def dupe(d):
        reg = d / 's97-registration.json'
        raw = reg.read_text(encoding='utf-8')
        bad = raw.replace('"signature": "2001080E"',
                          '"signature": "2001080E", "signature": "20010E0E"', 1)
        reg.write_text(bad, encoding='utf-8')

    case('duplicate signature key', 'dupe', dupe, 'field=duplicate_key')

    same = len({h for _, h in hashes}) == 1
    print('input_manifest_hash identical:', same)
    ok &= same
    print('SUITE :', 'ALL PASS' if ok else 'FAILURES PRESENT')
    return 0 if ok else 1


if __name__ == '__main__':
    sys.exit(main())
