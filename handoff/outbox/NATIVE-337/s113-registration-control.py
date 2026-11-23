"""Compare the fixed candidate verifier on one changed registration binding."""
from hashlib import sha256
import json
from pathlib import Path
import subprocess
import sys
from tempfile import TemporaryDirectory

FIXED = Path(sys.argv[1]).resolve()
UNIT = FIXED / "handoff/inbox/NATIVE-337"
ENTRY = FIXED / "tool/s113_verify.py"
NAMES = ("s97-registration.json", "code/s81-showdialog.csv")
REG = NAMES[0]
before = b'"class": "AspenTech.AspenPlus.WpfFindComponent.FindComponentDriver"'
after = b'"class": "AspenTech.AspenPlus.WpfFindComponent.FindComponentDriver2"'


def digest(data):
    return sha256(data).hexdigest()


summary = []
with TemporaryDirectory() as scratch:
    for case in ("fixed", "registry-class"):
        unit = Path(scratch) / case
        hashes = {}
        for name in NAMES:
            data = (UNIT / name).read_bytes()
            if case == "registry-class" and name == REG:
                assert data.count(before) == 1
                data = data.replace(before, after)
            target = unit / name
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_bytes(data)
            hashes[name] = digest(data)
        result = subprocess.run([sys.executable, "-B", str(ENTRY), "--folder", str(unit),
                                 "--signature"], cwd=FIXED, capture_output=True, text=True)
        summary.append({"case": case, "files": hashes, "stdout": result.stdout,
                        "stderr": result.stderr, "exit": result.returncode})
report = {"entry": digest(ENTRY.read_bytes()),
          "before": before.decode(), "after": after.decode(), "cases": summary}
print(json.dumps(report, indent=2))
