"""Reverify s105 using the fixed candidate, original, and published checkers."""
import csv
import hashlib
import importlib.util
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

ORIGINAL_SHA = "869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec"
CHECKER_SHA = "27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8"
SITE_SHA = "600975699de15c7ff150a336ac792726c40383e5229f835acdb727dd0e68c1ed"
WIDTH_SHA = "85145a458b4c4f1c9ff8dc3d0eeadadca2d81b5b2254e27af90027958b095a95"
UNIT = Path("handoff/inbox/NATIVE-340")
MANIFESTS = tuple(f"code/s{n}-fingerprints.json" for n in (29, 101, 105))
FIELDS = ("calls.csv", "code/native.asm", "metrics.json")
RECEIPT = "s105-submission.md"


def digest(data):
    return hashlib.sha256(data).hexdigest()


def hash_file(path):
    return digest(path.read_bytes())


def run(*args):
    result = subprocess.run([sys.executable, "-B", *map(str, args)], capture_output=True, encoding="utf8", errors="replace")
    return {"exit": result.returncode, "stdout": result.stdout.strip(), "stderr": result.stderr.strip()}


def replace_one(data, old, new):
    assert data.count(old) == 1, (old, data.count(old))
    return data.replace(old, new)


def load_module(path, name):
    spec = importlib.util.spec_from_file_location(name, path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def manifest(unit, filename):
    doc = json.loads((unit / filename).read_bytes())
    hashes = doc.get("files", doc)
    diffs = [p for p, h in hashes.items() if not (unit / p).is_file() or hash_file(unit / p) != h]
    return {"entries": len(hashes), "stale": diffs, "sha256": hash_file(unit / filename)}


def refresh(unit, filename):
    path = unit / filename
    data = json.loads(path.read_bytes())
    hashes = data.get("files", data)
    for item in sorted(hashes):
        hashes[item] = hash_file(unit / item)
    path.write_text(json.dumps(data, ensure_ascii=False, indent=1) + "\n", encoding="utf8", newline="\n")


def native_evidence(unit, original):
    asm = (unit / "code/native.asm").read_text(encoding="utf8").splitlines()
    bounds = {int(m[1], 16): int(m[2], 16) for line in asm if (m := re.match(r"; FUNC ([0-9A-F]+)-([0-9A-F]+)", line))}
    imp = {}
    for entry in original.DIRECTORY_ENTRY_IMPORT:
        for value in entry.imports:
            name = value.name.decode("ascii") if value.name else f"#{value.ordinal}"
            imp[value.address - original.OPTIONAL_HEADER.ImageBase] = entry.dll.decode("ascii") + "!" + name
    rows = list(csv.DictReader(io.StringIO((unit / "calls.csv").read_text(encoding="utf-8-sig"))))
    result = []
    for row in rows[-19:]:
        line = int(row["listing"].split("#L")[1])
        match = re.fullmatch(r"([0-9A-F]+)  ([0-9A-F ]+?)  JMP qword ptr \[RIP\+(0x[0-9A-Fa-f]+|[0-9]+)\]", asm[line - 1])
        site = int(match[1], 16)
        base = original.get_data(site, 3)
        prefix = 1 if base[:1] == b"\x48" else 0
        source = original.get_data(site, prefix + 6)
        assert source[prefix:prefix + 2] == b"\xff\x25"
        disp = struct.unpack_from("<i", source, prefix + 2)[0]
        slot = site + len(source) + disp
        caller = int(row["caller"], 0)
        end = bounds[caller]
        result.append(dict(line=line, site=hex(site), caller=hex(caller), end=hex(end),
            inside=caller <= site < end, at_end=site == end, pending_in_calls="待核" in row["note"],
            actual_bytes=source.hex(), bytes_match=bytes.fromhex(match[2]) == source, displacement=hex(disp),
            disp_matches=int(match[3], 0) == disp, slot=hex(slot), symbol=imp[slot],
            symbol_matches=imp[slot] == row["callee"],
            note_site_matches=int(re.search(r"@0x([0-9A-Fa-f]+)", row["note"])[1], 16) == site))
    return result


def main():
    fixed, original, checker, width_control = map(lambda p: Path(p).resolve(), sys.argv[1:])
    here = Path.cwd()
    unit = fixed / UNIT
    raw = original.read_bytes()
    pe = pefile.PE(data=raw)
    site = fixed / "tool/s105-site-evidence.py"
    width = fixed / "tool/s101_width_fixtures.py"
    assert hash_file(original) == ORIGINAL_SHA
    assert hash_file(checker) == CHECKER_SHA
    assert hash_file(site) == SITE_SHA
    assert hash_file(width) == WIDTH_SHA
    r = dict(original=ORIGINAL_SHA, checker=CHECKER_SHA, site_verifier=SITE_SHA,
             width_verifier=WIDTH_SHA, independent_width=hash_file(width_control))
    r["fingerprints"] = {p: manifest(unit, p) for p in MANIFESTS}
    receipt = (unit / RECEIPT).read_text(encoding="utf8")
    scripts = re.findall(r"^\| (tool/[^ |]+) \| ([0-9,]+) B \| ([0-9a-f]{64}) \|", receipt, re.M)
    assert len(scripts) == 8
    r["receipt_scripts"] = [dict(path=p, size=int(size.replace(",", "")), digest=h,
        match=(fixed / p).stat().st_size == int(size.replace(",", "")) and hash_file(fixed / p) == h) for p, size, h in scripts]
    r["coverage"] = run(checker, "NATIVE-340", "--original", original, "--submission", unit)
    r["il"] = run(fixed / "tool/verify_il_digests.py", "--binary", original, "--table", unit / "code/s89-il-digests.csv")
    metric = json.loads((unit / "metrics.json").read_bytes())
    r["metrics"] = {p: [metric[key], hash_file(unit / p)] for p, key in (
        ("calls.csv", "calls_sha256"), ("coverage.csv", "coverage_sha256"),
        ("native-functions.csv", "native_functions_sha256"))}
    r["iat_crosscheck"] = native_evidence(unit, pe)
    r["site_controls"] = [dict(case="fixed", **run(site, fixed, "--original", original))]
    r["width_controls"] = []
    lib = load_module(width_control, "independent_fixture")
    cli = load_module(fixed / "tool/cli_tables.py", "fixed_parser")
    r["implmap"] = []
    for table, count in ((4, 1), (6, 1), (4, 16383), (4, 16384), (6, 32767), (6, 32768)):
        raw_id = (count << 1) + (table == 6)
        row = struct.pack("<H", 0) + struct.pack("<H" if count < 32768 else "<I", raw_id) + struct.pack("<HH", 17, 1)
        value = lib.metadata_fixture({table: count, 26: 1, 28: 1},
                    {table: bytes((6 if table == 4 else 14)*count), 26: bytes(2), 28: row})
        actual = cli.read(value, 0)["rows"][28][0]
        match = ((actual["MemberForwarded"], actual["ImportName"], actual["ImportScope"]) == (raw_id, "MethodName", 1)
                 and actual["_decoded"]["MemberForwarded"] == (table, count))
        r["implmap"].append(dict(table=table, count=count, fixture_sha256=digest(value), match=match, observed=actual))
    site_path = b"0x3660,KERNEL32.dll!QueryPerformanceCounter,external,code/native.asm#L1509"
    controls = (
        ("relocated", None, None, None, "exit 0, same 67 sites"),
        ("one_listing_byte", "code/native.asm", b"00004711  FF 25 E9", b"00004711  FF 24 E9", "exit 1, L1509 byte mismatch"),
        ("one_display_displacement", "code/native.asm", b"00004711  FF 25 E9 18 00 00  JMP qword ptr [RIP+0x18E9]",
         b"00004711  FF 25 E9 18 00 00  JMP qword ptr [RIP+0x18E8]", "exit 1, L1509 disp mismatch"),
        ("one_import_name", "calls.csv", site_path, site_path.replace(b"QueryPerformanceCounter", b"GetStartupInfoW"),
         "exit 1, L1509 symbol mismatch"),
        ("one_import_suffix", "calls.csv", site_path, site_path.replace(b"QueryPerformanceCounter", b"QueryPerformanceCounter_WRONG"),
         "exit 1, L1509 symbol mismatch"),
        ("one_listing_reference", "calls.csv", site_path, site_path.replace(b"#L1509", b"#L1510"),
         "exit 1, L1510 symbol mismatch"),
        ("one_missing_listing", "calls.csv", site_path, site_path.replace(b"code/native.asm#L1509", b""),
         "exit 1, missing site evidence"),
        ("one_func_end", "code/native.asm", b"; FUNC 00004777-0000477D _CxxThrowException (6 bytes)",
         b"; FUNC 00004777-00004783 _CxxThrowException (6 bytes)", "record changed relation at L1524"),
    )
    with TemporaryDirectory(dir=here) as scratch:
        t = Path(scratch)
        sam = t / UNIT
        shutil.copytree(unit, sam)
        (t / "tool").mkdir()
        for filename in ("s101_width_fixtures.py", "cli_tables.py"):
            shutil.copyfile(fixed / "tool" / filename, t / "tool" / filename)
        for case, file, old, new, expectation in controls:
            for filename in (*FIELDS, *MANIFESTS):
                shutil.copyfile(unit / filename, sam / filename)
            if file:
                (sam / file).write_bytes(replace_one((sam / file).read_bytes(), old, new))
                if file == "calls.csv":
                    doc = json.loads((sam / "metrics.json").read_bytes())
                    doc["calls_sha256"] = hash_file(sam / "calls.csv")
                    (sam / "metrics.json").write_text(json.dumps(doc, ensure_ascii=False, indent=1) + "\n", encoding="utf8", newline="\n")
                for f in MANIFESTS:
                    refresh(sam, f)
            r["site_controls"].append(dict(case=case, expectation=expectation,
                input_sha256={f: hash_file(sam / f) for f in (*FIELDS, *MANIFESTS)}, **run(site, t, "--original", original)))
        parser = t / "tool/cli_tables.py"
        for mutation in (False, True):
            if mutation:
                old = b'raw = int.from_bytes(data[off:off + width], "little")'
                patch = b'width = 2 if isinstance(column_spec(i,name),tuple) and column_spec(i,name)[0]=="coded" else width\n                '
                parser.write_bytes(replace_one(parser.read_bytes(), old, patch + old))
            independent = run(width_control, t)
            r["width_controls"].append(dict(change_actual_read=mutation, parser_sha256=hash_file(parser),
                delivery=run(t / "tool/s101_width_fixtures.py"), independent_exit=independent["exit"],
                independent=json.loads(independent["stdout"])))
    print(json.dumps(r, ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
