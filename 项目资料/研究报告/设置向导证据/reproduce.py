"""Re-extract exactly the indexed evidence into a new, local-only directory."""
import argparse
import hashlib
import json
import re
import subprocess
import sys
from pathlib import Path

from inspect_logic import managed, native, new_output


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--out", required=True)
    args = ap.parse_args()
    here = Path(__file__).resolve().parent
    index = json.loads((here / "evidence-index.json").read_text(encoding="utf-8"))
    # Fixed native addresses must never be applied to a different build.
    for source in index["sources"]:
        path = Path(source["file"])
        if hashlib.sha256(path.read_bytes()).hexdigest() != source["sha256"]:
            raise ValueError(f"Input differs from recorded build: {path.name}")
    run = new_output(args.out)
    for source in index["sources"]:
        out = run / Path(source["local_evidence"]).parent.name
        out.mkdir(exist_ok=False)
        symbols = source.get("methods", source.get("functions", []))
        pattern = re.compile("^(?:" + "|".join(re.escape(s["name"]) for s in symbols) + ")$")
        if "methods" in source:
            managed(Path(source["file"]), pattern, out)
        else:
            entries = [int(s["rva"], 16) for s in symbols if s["name"].startswith("sub_")]
            native(Path(source["file"]), pattern, out, entries)
    subprocess.run([sys.executable, str(here / "verify_evidence.py"), str(run)], check=True)


if __name__ == "__main__":
    main()
