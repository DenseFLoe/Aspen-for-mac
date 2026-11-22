import sys, json, hashlib
sys.stdout.reconfigure(encoding='utf-8')
from pathlib import Path
root=Path('handoff/inbox/NATIVE-340')
out={}
for p in sorted(root.rglob('*')):
    if not p.is_file(): continue
    rel=p.relative_to(root).as_posix()
    if rel=='code/s29-fingerprints.json': continue
    out[rel]=hashlib.sha256(p.read_bytes()).hexdigest()
Path('handoff/inbox/NATIVE-340/code/s29-fingerprints.json').write_text(json.dumps(out,ensure_ascii=False,indent=1)+"\n",encoding='utf-8')
print('fingerprints',len(out))
