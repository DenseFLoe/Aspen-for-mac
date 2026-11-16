"""Verify published evidence index against installed binaries and local extracts.

Read-only. Usage:
  python verify_evidence.py            # verify against .local/button-logic-exploration-20261116
  python verify_evidence.py --run DIR  # verify a reproduce.py output (DIR/<alias>/managed.json)
Never executes Aspen code; never writes protected assets.
"""
import argparse, hashlib, json, re
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
DEFAULT_RUN = ROOT/'.local/button-logic-exploration-20261116'

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--run', type=Path, default=None)
    ap.add_argument('--index', type=Path, default=HERE/'evidence-index.json')
    ap.add_argument('--checks', type=Path, default=HERE/'checks.json')
    args = ap.parse_args()
    index = json.loads(args.index.read_text(encoding='utf-8'))
    checks = json.loads(args.checks.read_text(encoding='utf-8'))['checks']
    failures = []

    def fail(msg):
        failures.append(msg)

    # 1. installed file identity
    for src in index['sources']:
        p = Path(src['file'])
        if not p.exists():
            fail(f'missing installed file {p}')
            continue
        if hashlib.sha256(p.read_bytes()).hexdigest() != src['sha256']:
            fail(f'hash mismatch {p.name}')

    # 2. indexed tokens/RVAs present in extracts
    for src in index['sources']:
        alias = src['alias']
        if args.run:
            paths = [args.run/alias/'managed.json', args.run/alias/'native.json']
        else:
            paths = [ROOT/e for e in src['evidence']]
        method_triples, functions = set(), {}
        for p in paths:
            if not p.exists():
                continue
            obj = json.loads(p.read_text(encoding='utf-8'))
            if not isinstance(obj, dict):
                continue
            for m in obj.get('methods', []):
                method_triples.add((m['name'], m['token'], m['rva']))
            for f in obj.get('functions', []):
                functions[f['name']] = f
        for m in src['methods']:
            if (m['name'], m['token'], m['rva']) not in method_triples:
                fail(f"method location mismatch {alias} {m['name']}")
        for f in src['functions']:
            got = functions.get(f['name'])
            if got is None or got['rva'] != f['rva']:
                fail(f"function location mismatch {alias} {f['name']}")

    # 3. recompute key structural checks from extracts
    def load_methods(label):
        p = (args.run/label/'managed.json') if args.run else (DEFAULT_RUN/label/'managed.json')
        if not p.exists():
            return {}
        return {m['name']: m for m in json.loads(p.read_text(encoding='utf-8'))['methods']}

    rc = load_methods('managed-run-control')
    def rva(d, suffix):
        return next((m['rva'] for m in d.values() if m['name'].endswith('::'+suffix)), None)
    if rc:
        if not (rva(rc,'CanExecuteReinitCommand')==rva(rc,'CanExecuteTimePlotCommand')==rva(rc,'CanExecuteMoveToCommand')):
            fail('shared RVA Reinit/TimePlot/MoveTo broken')
        if not (rva(rc,'CanExecuteRewindCommand')==rva(rc,'CanExecuteTakeSnapshotCommand')==rva(rc,'CanExecuteManageSnapshotsCommand')):
            fail('shared RVA Rewind/TakeSnapshot/ManageSnapshots broken')
    ast = load_methods('managed-action-status')
    ci = next((m for m in ast.values() if m['name'].endswith('::get_CanInvoke')), None)
    if ci is not None:
        ops = [i['op'] for i in ci['il']]
        if ops != ['ldarg.0','call','ldc.i4.2','ceq','ldc.i4.0','ceq','ret']:
            fail('CanInvoke body changed')

    # 4. recorded checks must all be ok
    for c in checks:
        if not c['ok']:
            fail(f"recorded check not ok: {c['check']}")

    # 5. protected asset count baseline
    prot = ROOT/'.local/property-database'
    n = sum(1 for x in prot.rglob('*') if x.is_file())
    if n != 3226:
        fail(f'protected asset count {n} != baseline 3226')

    print(json.dumps({'failures': failures, 'protected_files': n,
                      'indexed_methods': sum(len(s['methods']) for s in index['sources']),
                      'indexed_functions': sum(len(s['functions']) for s in index['sources'])},
                     ensure_ascii=False))
    return 1 if failures else 0

if __name__ == '__main__':
    raise SystemExit(main())
