"""Replay static controls. Requires pefile. Paths name pinned local copies."""
import argparse
import csv
from hashlib import sha256
import io
import json
from pathlib import Path
import re
import shutil
import struct
import subprocess
import sys
from tempfile import TemporaryDirectory

import pefile


def digest(data):
    return sha256(data).hexdigest()


def run(argv):
    r = subprocess.run([sys.executable, "-B", *map(str, argv)], capture_output=True, encoding="utf-8", errors="replace")
    return {"exit": r.returncode, "stdout": r.stdout.strip(), "stderr": r.stderr.strip()}


def table(rows):
    buf = io.StringIO(newline="")
    writer = csv.DictWriter(buf, rows[0].keys(), lineterminator="\r\n")
    writer.writeheader()
    writer.writerows(rows)
    return buf.getvalue().encode()


def main():
    a = argparse.ArgumentParser()
    for key in ("candidate", "original", "checker"):
        a.add_argument(key, type=Path)
    a.add_argument("--require-iat", action="store_true", help="exit 1 if site, symbol, bytes, operand or declared owner disagrees")
    args = a.parse_args()
    candidate, original, checker = (p.resolve() for p in (args.candidate, args.original, args.checker))
    unit = candidate / "handoff/inbox/NATIVE-340"
    code = unit / "code"
    tool = candidate / "tool/verify_il_digests.py"
    data = original.read_bytes()
    assert digest(data) == "869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec"
    signed = {}
    for name in ("s29-fingerprints", "s97-fingerprints"):
        m = code / (name + ".json")
        mapping = json.loads(m.read_bytes())
        mapping = mapping.get("files", mapping)
        signed[name] = {"manifest_sha256": digest(m.read_bytes()), "entries": len(mapping),
                        "mismatch": [path for path, h in mapping.items() if digest((unit / path).read_bytes()) != h]}
    tbl = (code / "s89-il-digests.csv").read_bytes()
    rows = list(csv.DictReader(io.StringIO(tbl.decode("utf-8-sig"), newline="")))
    k = 66
    sha_bad = [dict(r) for r in rows]
    sha_bad[k]["sha256"] = "0" * 64
    digest_cases = []
    with TemporaryDirectory(dir=Path.cwd()) as temp:
        t = Path(temp)
        for label, content, expected_exit in (("intact", tbl, 0), ("wrong_digest", table(sha_bad), 1),
                ("missing", table(rows[:k] + rows[k+1:]), 1), ("duplicate", table(rows + [rows[k]]), 1)):
            dest = t / "digest.csv"
            dest.write_bytes(content)
            out = run([tool, "--binary", original, "--table", dest])
            digest_cases.append(dict(case=label, target=rows[k]["token"], input_sha256=digest(content),
                                     output_sha256=digest(dest.read_bytes()), expected_exit=expected_exit, **out))
        calls_bytes = (unit / "calls.csv").read_bytes()
        calls = list(csv.DictReader(io.StringIO(calls_bytes.decode("utf-8-sig"), newline="")))
        asm = (code / "native.asm").read_text(encoding="utf-8-sig").splitlines()
        fn_bounds = {}
        for line in asm:
            m = re.match(r"; FUNC ([0-9A-F]+)-([0-9A-F]+)", line)
            if m:
                start, end = (int(v, 16) for v in m.groups())
                fn_bounds[start] = end
        pe = pefile.PE(data=data)
        sys.path.insert(0, str(candidate / "tool"))
        import cli_tables
        clr = pe.OPTIONAL_HEADER.DATA_DIRECTORY[14].VirtualAddress
        metadata_rva, = struct.unpack("<I", pe.get_data(clr + 8, 4))
        tables = cli_tables.read(data, pe.get_offset_from_rva(metadata_rva))
        real_layout = {"heap_sizes": tables["heap_sizes"], "stream": tables["stream"],
                       "MemberRef1": tables["rows"][10][0], "CustomAttribute1": tables["rows"][12][0]}
        imports = {i.address - pe.OPTIONAL_HEADER.ImageBase:
                   d.dll.decode() + "!" + (i.name.decode() if i.name else "#" + str(i.ordinal))
                   for d in pe.DIRECTORY_ENTRY_IMPORT for i in d.imports}
        iat = []
        for row in calls[-19:]:
            n = int(row["listing"].split("#L")[1])
            m = re.fullmatch(r"([0-9A-F]+)  ([0-9A-F ]+?)  JMP qword ptr \[RIP\+(\d+)\]", asm[n-1])
            site = int(m[1], 16)
            bs = bytes.fromhex(m[2])
            raw = pe.get_data(site, len(bs))
            prefix = 1 if 0x40 <= raw[0] <= 0x4F else 0
            assert raw[prefix:prefix+2] == bytes.fromhex("ff25") and len(raw) == prefix + 6
            disp = int.from_bytes(raw[prefix+2:prefix+6], "little", signed=True)
            slot = site + len(raw) + disp
            caller = int(row["caller"], 0)
            end = fn_bounds[caller]
            note_site = int(re.search(r"@0x([0-9A-Fa-f]+)", row["note"])[1], 16)
            iat.append(dict(line=n, site=hex(site), note_site=hex(note_site), note_site_match=note_site==site,
                            actual_bytes=raw.hex(), bytes_match=raw==bs, signed_displacement=disp,
                            listing_displacement=int(m[3]), displacement_match=disp==int(m[3]), slot=hex(slot),
                            slot_symbol=imports[slot], symbol_match=imports[slot]==row["callee"],
                            declared_caller=hex(caller), declared_end_exclusive=hex(end),
                            inside_declared_caller=caller<=site<end))
        # Mechanical v1 cannot decide every source/caller relation. Preserve every other byte.
        checks = []
        clean = run([checker, "NATIVE-340", "--original", original, "--submission", unit])
        old = b"native,0x2B74,KERNEL32.dll!GetModuleHandleW,"
        assert calls_bytes.count(old)==1
        fb = calls_bytes.replace(old, b"native,0x3660,KERNEL32.dll!GetModuleHandleW,")
        sample = t / "sample"
        shutil.copytree(unit, sample)
        (sample / "calls.csv").write_bytes(fb)
        for label, content, out, exp in (("as_delivered", calls_bytes, clean, True), ("change_only_owner_at_0x2B7A", fb,
                run([checker, "NATIVE-340", "--original", original, "--submission", sample]), False)):
            checks.append(dict(case=label, calls_sha256=digest(content), expected_owner_matches=exp, **out))
    print(json.dumps({"head":"38b6814d15332a90258f2caa42169b6f52e5bad4", "original_sha256":digest(data),
          "signed":signed, "digest_verifier_sha256":digest(tool.read_bytes()),
          "parser_sha256":digest((candidate/"tool/cli_tables.py").read_bytes()),
          "coverage_verifier_sha256":digest(checker.read_bytes()), "pefile_version":pefile.__version__,
          "original_cli_layout":real_layout,
          "pefile_sha256":digest(Path(pefile.__file__).read_bytes()), "digest_controls":digest_cases,
          "iat_sites":iat, "coverage_controls":checks}, indent=2))
    if args.require_iat:
        fields = ("note_site_match", "bytes_match", "symbol_match", "displacement_match", "inside_declared_caller")
        sys.exit(int(any(not all(row[f] for f in fields) for row in iat)))


if __name__ == "__main__":
    main()

