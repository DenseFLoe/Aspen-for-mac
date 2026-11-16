"""Re-extract exactly the indexed evidence into a new, local-only directory.

Usage: python reproduce.py --out .local/button-logic-repro-<name>
Refuses to run against installed binaries whose SHA-256 differs from the index.
"""
import argparse, hashlib, importlib.util, json, re, subprocess, sys, types
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
SPEC = importlib.util.spec_from_file_location('prior_analysis', ROOT/'analysis/wizard-logic-20261115/inspect_logic.py')
CORE = importlib.util.module_from_spec(SPEC)
sys.dont_write_bytecode = True
SPEC.loader.exec_module(CORE)
_original_pe = CORE.pefile.PE
def full_export_pe(*a, **k):
    k.setdefault('max_symbol_exports', 65536)
    k.setdefault('max_repeated_symbol', 65536)
    return _original_pe(*a, **k)
CORE.pefile = types.SimpleNamespace(PE=full_export_pe, PEFormatError=CORE.pefile.PEFormatError)

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--out', required=True)
    ap.add_argument('--index', type=Path, default=HERE/'evidence-index.json')
    args = ap.parse_args()
    out = Path(args.out).resolve()
    rel = out.relative_to(ROOT/'.local')
    if not rel.parts or not rel.parts[0].startswith('button-logic-repro-'):
        raise ValueError('Output must be under .local/button-logic-repro-*')
    out.mkdir(parents=True, exist_ok=False)
    index = json.loads(args.index.read_text(encoding='utf-8'))
    for src in index['sources']:
        p = Path(src['file'])
        if hashlib.sha256(p.read_bytes()).hexdigest() != src['sha256']:
            raise ValueError(f'Input differs from recorded build: {p.name}')
    for src in index['sources']:
        if not src['methods'] and not src['functions']:
            continue
        target = out/src['alias']
        target.mkdir(exist_ok=False)
        if src['methods']:
            pattern = re.compile('^(?:'+'|'.join(re.escape(m['name']) for m in src['methods'])+')$')
            CORE.managed(Path(src['file']), pattern, target)
        else:
            pattern = re.compile('^(?:'+'|'.join(re.escape(f['name']) for f in src['functions'])+')$')
            entries = [int(f['rva'], 16) for f in src['functions'] if f['name'].startswith('sub_')]
            CORE.native(Path(src['file']), pattern, target, entries)
    subprocess.run([sys.executable, str(HERE/'verify_evidence.py'), '--run', str(out),
                    '--index', str(args.index),
                    '--checks', str(args.index.with_name(args.index.name.replace('evidence-index', 'checks')))],
                   check=True)

if __name__ == '__main__':
    main()
