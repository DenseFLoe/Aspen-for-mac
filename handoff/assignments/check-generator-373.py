"""Check reported bytes from PR 373. Never import or run candidate programs."""
import argparse
import base64
import binascii
import hashlib
import json
import sys
from pathlib import Path


HEAD = "8f5034f02722916e442881a6bd112baef419d1a7"
SOURCES = {
    "tool/b2_wave.py": "627fc3becb7cd89f2bf90027b68047f28fa5f20e06514c0a1f274b3fbb4956b3",
    "tool/batch_reverse.py": "2a33353dbb07e24f15b2a4f30c8d69883ef29688f849ad327d723f1102c6534e",
    "tool/check_cs_clean.py": "f6989df348c2d3052337f9483b40489dd7512eb20afeb98a83b15eb15c291b85",
}
PRODUCERS = ("tool/b2_wave.py", "tool/batch_reverse.py")
FIRST = b"You are not using the latest version of the tool, please update."
VERSION = b"Latest version is '11.2.0.10050' (yours is '9.1.0.7988')"
LF = FIRST + b"\n" + VERSION + b"\n"
CRLF = LF.replace(b"\n", b"\r\n")
BODY = b"class C {}\n"
WINDOWS = b"\xef\xbb\xbf// UTF-8\r\nclass C {}\r\n\r\n"
LITERAL = b'const string msg = """\n' + LF + b'""";\n'
# input, expected on first and repeated write, raw gate exit, cleaned gate exit
CASES = {
    "clean-no-final-newline": (BODY.rstrip(b"\n"), BODY.rstrip(b"\n"), 0, 0),
    "clean-trailing-empty-lines": (BODY + b"\n\n", BODY + b"\n\n", 0, 0),
    "empty-source": (b"", b"", 0, 0),
    "known-lf": (BODY + LF, BODY, 1, 0),
    "known-crlf-bom": (WINDOWS + CRLF, WINDOWS, 1, 0),
    "known-no-final-newline": (BODY + LF.rstrip(b"\n"), BODY, 1, 0),
    "notice-only": (LF, b"", 1, 0),
    "source-string": (LITERAL, LITERAL, 0, 0),
    "source-string-and-notice": (LITERAL + LF, LITERAL, 1, 0),
    "incomplete-notice": (BODY + FIRST + b"\n", BODY + FIRST + b"\n", 1, 1),
}


def encode(data):
    return base64.b64encode(data).decode("ascii")


def fixtures():
    payload = {"pr_head": HEAD, "inputs": {name: encode(row[0]) for name, row in CASES.items()}}
    return (json.dumps(payload, indent=2) + "\n").encode("ascii")


def sha(data):
    return hashlib.sha256(data).hexdigest()


def unique_fields(pairs):
    fields = dict(pairs)
    if len(fields) != len(pairs):
        raise ValueError("duplicate field in reported evidence")
    return fields


def check(folder):
    fixture = (folder / "fixtures.json").read_bytes()
    if fixture != fixtures():
        raise ValueError("fixtures.json differs from the fixed input bytes")
    result = json.loads((folder / "results.json").read_text(encoding="utf-8"), object_pairs_hook=unique_fields)
    if result["pr_head"] != HEAD or result["sources_sha256"] != SOURCES:
        raise ValueError("wrong PR head or source identities")
    log = (folder / "run.log").read_bytes()
    if not log.strip() or result["run_log_sha256"] != sha(log) or result["fixtures_sha256"] != sha(fixture):
        raise ValueError("fixture/log evidence mismatch")
    if set(result["producers"]) != set(PRODUCERS):
        raise ValueError("expected both producer entry points")
    failures = []
    for producer in PRODUCERS:
        rows = result["producers"][producer]
        if set(rows) != set(CASES):
            raise ValueError(f"{producer}: missing or unexpected fixture IDs")
        for case_id, (_, expected, raw_exit, after_exit) in CASES.items():
            actual = rows[case_id]
            for phase in ("once_b64", "twice_b64"):
                value = base64.b64decode(actual[phase], validate=True)
                if value != expected:
                    failures.append(f"{producer}/{case_id}/{phase}: expected {sha(expected)}, got {sha(value)}")
            for phase, expected_exit in (("raw_gate_exit", raw_exit), ("after_gate_exit", after_exit)):
                value = actual[phase]
                if type(value) is not int or value != expected_exit:
                    failures.append(f"{producer}/{case_id}/{phase}: expected {expected_exit}, got {value!r}")
    return failures


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--emit-fixtures", type=Path, help="write canonical fixture inputs to a new file")
    parser.add_argument("--inbox", type=Path, default=Path(__file__).resolve().parents[1] / "inbox/NAG-GENERATOR-373")
    args = parser.parse_args()
    if args.emit_fixtures:
        with args.emit_fixtures.open("xb") as out:
            out.write(fixtures())
        return 0
    try:
        failures = check(args.inbox)
    except (OSError, ValueError, KeyError, TypeError, binascii.Error) as exc:
        print(f"missing or invalid evidence: {exc}", file=sys.stderr)
        return 2
    if failures:
        print("\n".join(failures), file=sys.stderr)
        return 1
    print(f"{len(PRODUCERS)} producer entries x {len(CASES)} fixtures matched; upstream source/log review required")
    return 0


if __name__ == "__main__":
    sys.exit(main())
