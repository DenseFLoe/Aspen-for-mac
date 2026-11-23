"""Check the s89 generator on single-field and single-row controls."""
import argparse
import csv
from hashlib import sha256
import io
import json
from pathlib import Path
import subprocess
import sys
from tempfile import TemporaryDirectory


def digest(data):
    return sha256(data).hexdigest()


def rows(data):
    return list(csv.DictReader(io.StringIO(data.decode("utf-8-sig"), newline="")))


def csv_bytes(records):
    output = io.StringIO(newline="")
    writer = csv.DictWriter(output, records[0].keys(), lineterminator="\r\n")
    writer.writeheader()
    writer.writerows(records)
    return output.getvalue().encode()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("fixed", type=Path)
    parser.add_argument("original", type=Path)
    options = parser.parse_args()
    fixed, original = options.fixed.resolve(), options.original.resolve()
    original_sha = digest(original.read_bytes())
    assert original_sha == "869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec"
    tool = fixed / "tool/audit_340_s89.py"
    code = fixed / "handoff/inbox/NATIVE-340/code"
    delivered = (code / "s89-il-digests.csv").read_bytes()
    old = (code / "s77-il-fingerprints.csv").read_bytes()
    old_rows = rows(old)
    target = old_rows[0]["token"]
    delivered_rows = rows(delivered)
    assert delivered_rows[0]["token"] == target
    bad_delivered = [dict(r) for r in delivered_rows]
    bad_delivered[0]["sha256"] = "0" * 64
    bad_old = [dict(r) for r in old_rows]
    bad_old[0]["il_sha256"] = "0" * 64
    cases = [
        ("fixed", delivered, old),
        ("change_delivered_digest", csv_bytes(bad_delivered), old),
        ("change_compared_s77_digest", delivered, csv_bytes(bad_old)),
        ("duplicate_compared_s77_token", delivered, csv_bytes(old_rows + [old_rows[0]])),
        ("remove_compared_s77_token", delivered, csv_bytes(old_rows[1:])),
    ]
    outcomes = []
    with TemporaryDirectory() as temporary:
        for name, actual, reference in cases:
            candidate = Path(temporary) / name
            prepared = candidate / "code"
            prepared.mkdir(parents=True)
            (prepared / "s89-il-digests.csv").write_bytes(actual)
            (prepared / "s77-il-fingerprints.csv").write_bytes(reference)
            report = subprocess.run([sys.executable, "-B", str(tool), "--binary", str(original),
                                     "--folder", str(candidate)], capture_output=True, text=True, check=False)
            assert not report.stderr, report.stderr
            outcomes.append({
                "control": name,
                "s89_input_sha256": digest(actual),
                "s77_input_sha256": digest(reference),
                "s89_after_sha256": digest((prepared / "s89-il-digests.csv").read_bytes()),
                "exit": report.returncode,
                "differences": {r["category"]: int(r["count"])
                                for r in rows((prepared / "s89-digest-diffs.csv").read_bytes())},
                "stdout": report.stdout.strip(),
            })
    print(json.dumps({"original_sha256": original_sha, "audit_sha256": digest(tool.read_bytes()),
                      "modified_token": target, "controls": outcomes}, indent=2))


if __name__ == "__main__":
    main()
