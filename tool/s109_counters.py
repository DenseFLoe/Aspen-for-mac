# -*- coding: utf-8 -*-
"""s109 counterexamples: isolated copies, one field each, all must be located."""
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
    d = Path(tempfile.mkdtemp(prefix='s109-%s-' % tag)) / 'cand'
    shutil.copytree(BASE, d, ignore=shutil.ignore_patterns('*.prev.csv', 'work', 's*-fingerprints.json'))
    return d


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def verify(d):
    r = subprocess.run([sys.executable, '-B', 'tool/s109_verify.py', '--folder', str(d),
                        '--binary', BIN, '--signature'], capture_output=True, text=True)
    return r.returncode, (r.stdout + r.stderr).strip()


def main():
    base = fresh('base')
    base_hash = tree_hash(base)
    print('baseline input_manifest_hash:', base_hash)
    hashes = []
    ok = True

    def case(title, mutate, expect, forbid=None):
        nonlocal ok
        safe = ''.join(c if c.isalnum() or c in '-_' else '_' for c in title)
        d = fresh(safe)
        hashes.append((title, tree_hash(d)))
        target = mutate(d)
        b = sha(target) if target else '-'
        rc, txt = verify(d)
        a = sha(target) if target else '-'
        hit = (expect in txt) and rc != 0
        stale = bool(forbid and forbid in txt)
        good = hit and not stale
        print('%-22s rc=%d located=%s%s status=%s' % (title, rc, hit,
                                                       ' STALE(%s)' % forbid if stale else '',
                                                       'PASS' if good else 'FAIL'))
        if target:
            print('   mutated=%s before=%s after=%s unchanged=%s'
                  % (Path(target).relative_to(d).as_posix(), b[:16], a[:16], b == a))
        for line in txt.splitlines():
            if line.startswith('CONFLICT'):
                print('   ', line)
        ok &= good and (target is None or b == a)

    def drop_edge(d):
        reg = d / 's97-registration.json'
        doc = json.loads(reg.read_text(encoding='utf-8'))
        doc['FindComponentDriver']['interfaces'] = []
        reg.write_text(json.dumps(doc, ensure_ascii=False, indent=2), encoding='utf-8')
        return reg

    def iface_rva(d):
        reg = d / 's97-registration.json'
        doc = json.loads(reg.read_text(encoding='utf-8'))
        doc['IFindComponentDriver']['methods'][0]['rva'] = '1'
        reg.write_text(json.dumps(doc, ensure_ascii=False, indent=2), encoding='utf-8')
        return reg

    def pe_sha(d):
        reg = d / 's97-registration.json'
        doc = json.loads(reg.read_text(encoding='utf-8'))
        doc['PE']['sha256'] = '00' * 32
        reg.write_text(json.dumps(doc, ensure_ascii=False, indent=2), encoding='utf-8')
        return reg

    def table_rva(d):
        tbl = d / 'code' / 's81-showdialog.csv'
        t = tbl.read_text(encoding='utf-8').replace('rva 0xA848', 'rva 0xA8480')
        tbl.write_text(t, encoding='utf-8')
        return tbl

    case('drop InterfaceImpl', drop_edge, 'field=InterfaceImpl')
    case('iface rva 0->1', iface_rva, 'field=rva')
    case('attachment PE sha', pe_sha, 'field=deployment.sha256')
    case('table rva A8480', table_rva, 'field=rva', forbid='found=0xA848 ')

    same = len({h for _, h in hashes}) == 1
    print('input_manifest_hash identical:', same)
    for t_, h in hashes:
        print('  %-22s %s' % (t_, h))
    ok &= same
    print('SUITE :', 'ALL PASS' if ok else 'FAILURES PRESENT')
    return 0 if ok else 1


if __name__ == '__main__':
    sys.exit(main())
