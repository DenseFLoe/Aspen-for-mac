"""Replay controls against fixed #445 and #450 candidate trees."""
import csv
from hashlib import sha256
import json
from pathlib import Path
import shutil
import subprocess
import sys
from tempfile import TemporaryDirectory


def digest(data):
    return sha256(data).hexdigest()


def file_hash(path):
    return digest(path.read_bytes())


def rows(path):
    with path.open(encoding="utf-8-sig", newline="") as stream:
        return list(csv.DictReader(stream))


def invoke(cwd, script, *args):
    result = subprocess.run([sys.executable, "-B", str(script), *map(str, args)],
                            cwd=cwd, capture_output=True, text=True, encoding="utf-8",
                            errors="replace")
    return {"exit": result.returncode, "stdout": result.stdout.strip(), "stderr": result.stderr.strip()}


def check_manifests(unit, *names):
    result = {}
    for name in names:
        file = unit / name
        value = json.loads(file.read_bytes())
        entries = value.get("files", value)
        errors = []
        for relative, expected in entries.items():
            path = (unit / relative).resolve()
            assert path.is_relative_to(unit.resolve())
            actual = file_hash(path) if path.is_file() else None
            if actual != expected:
                errors.append({"path": relative, "expected": expected, "observed": actual})
        result[name] = {"checked": len(entries), "manifest_sha256": file_hash(file), "mismatches": errors}
    return result


def named(entries, key, value):
    return [r for r in entries if r[key] == value]


def showdialog(fixed, unit, original, temp):
    tools = fixed / "tool"
    listing = unit / "code/native.asm"
    call_bytes = (unit / "calls.csv").read_bytes()
    asm_bytes = listing.read_bytes()
    out = {}
    for key, site, old, new in (
        ("first-real-ordinal", "0x106C", "#2344", "#2348"),
        ("second-real-ordinal", "0x1072", "#2348", "#2207"),
    ):
        observed = []
        for bad in (False, True):
            fixture = temp / key / str(bad)
            (fixture / "code").mkdir(parents=True)
            shutil.copy2(listing, fixture / "code/native.asm")
            before = next(row for row in rows(unit / "code/s37-two-hop.csv") if row["site"] == site)
            marker = f"mfc140.dll!{old},external,{before['asm']}-".encode()
            assert call_bytes.count(marker) == 1
            altered = call_bytes.replace(marker, marker.replace(old.encode(), new.encode()))
            (fixture / "calls.csv").write_bytes(altered if bad else call_bytes)
            args = ["--binary", original, "--folder", fixture]
            result = invoke(fixed, tools / "s37_two_hop.py", *args, "--out", fixture / "links.csv")
            assert result["exit"] == 0, result
            original_link, = named(rows(fixture / "links.csv"), "site", site)
            observed.append({"calls_sha256": file_hash(fixture / "calls.csv"), "site": original_link,
                             "exit": result["exit"]})
        out[key] = observed
    for name, before, after in (
        ("variant-listing", b"000013DD  B8 08 00 00 00", b"000013DD  B8 03 00 00 00"),
        ("riid-listing", b"72 6F 00 00", b"82 6F 00 00"),
    ):
        cases = []
        for bad in (False, True):
            fixture = temp / name / str(bad)
            (fixture / "code").mkdir(parents=True)
            if name == "riid-listing":
                patched, count = 0, 0
                changed = []
                for line in asm_bytes.splitlines(keepends=True):
                    if line.startswith(b"0000137F") and before in line:
                        count += 1
                        line = line.replace(before, after)
                    changed.append(line)
                assert count == 1
                altered = b"".join(changed)
            else:
                assert asm_bytes.count(before) == 1
                altered = asm_bytes.replace(before, after)
            asm = fixture / "code/native.asm"
            asm.write_bytes(altered if bad else asm_bytes)
            table = fixture / "generated.csv"
            result = invoke(fixed, tools / "s81_showdialog.py", "--folder", fixture, "--binary", original, "--out", table)
            assert result["exit"] == 0, result
            entries = rows(table)
            cases.append({"listing_sha256": file_hash(asm), "output_sha256": file_hash(table), "exit": result["exit"],
                          "variant_rows": named(entries, "item", "variant-vt"),
                          "variant_init": named(entries, "item", "variant-init"),
                          "riid_rows": named(entries, "item", "calls-riid")})
        out[name] = cases
    return out


def cli_review(fixed, unit, original, oracle_path, sample_record_path, temp):
    import struct
    import pefile

    reference = json.loads(oracle_path.read_bytes())["original"]
    sample = json.loads(sample_record_path.read_bytes())
    raw = original.read_bytes()
    pe = pefile.PE(data=raw)
    cor = pe.get_offset_from_rva(pe.OPTIONAL_HEADER.DATA_DIRECTORY[14].VirtualAddress)
    root = pe.get_offset_from_rva(struct.unpack_from("<I", raw, cor + 8)[0])
    cursor = root + 16 + struct.unpack_from("<I", raw, root + 12)[0]
    stream_count = struct.unpack_from("<H", raw, cursor + 2)[0]
    cursor += 4
    streams = {}
    for _ in range(stream_count):
        offset, size = struct.unpack_from("<II", raw, cursor)
        end = raw.index(b"\0", cursor + 8)
        streams[raw[cursor + 8:end].decode()] = (root + offset, size)
        cursor = (end + 4) & ~3
    stream = streams["#~"][0]
    il = {f"0x{x['token']:08X}": x["il_sha256"] for x in reference["methods"]
          if x["rva"] and x["implementation"] & 3 == 0}
    delivered = rows(unit / "code/s81-il-fingerprints.csv")
    assert len(il) == len(delivered) == 167
    assert {r["token"]: r["il_sha256"] for r in delivered} == il
    new_slots = rows(unit / "code/s85-vtable-flags.csv")
    for row in new_slots:
        descriptor = reference["fixup_descriptors"][int(row["entry"])]
        assert descriptor["rva"] == int(row["slot"], 16)
        assert descriptor["flags"] == int(row["raw"], 16) and descriptor["slots"] == [int(row["token"], 16)]
        expected = "COR_VTABLE_64BIT"
        if descriptor["flags"] & 8:
            expected += " | COR_VTABLE_FROM_UNMANAGED_RETAIN_APPDOMAIN"
        assert row["bit_names"] == expected
    methodimpl, = rows(unit / "code/s85-methodimpl-pereader.csv")
    binding, = sample["bindings"]
    assert methodimpl["sha256"] == sample["sha256"]
    assert (int(methodimpl["body_rid"]), int(methodimpl["decl_rid"])) == (
        binding["body"] & 0xffffff, binding["declaration"] & 0xffffff)
    script = fixed / "tool/audit_340_s85.py"
    normal = [("original", ("MethodDef", 4))]
    duplicate = normal * 2
    probe = ("import importlib.util,json,sys;"
             "s=importlib.util.spec_from_file_location('audit',sys.argv[1]);"
             "m=importlib.util.module_from_spec(s);s.loader.exec_module(m);"
             "pairs=json.loads(sys.argv[2]);"
             "print(json.dumps(m.diff_categories(dict(pairs),dict(pairs[:1]),'MethodImpl')))")
    checks = {}
    for name, args in (("baseline", normal), ("duplicate_evidence", duplicate)):
        input_data = json.dumps(args)
        run = subprocess.run([sys.executable, "-B", "-c", probe, str(script), input_data],
                             capture_output=True, text=True, encoding="utf-8")
        assert run.returncode == 0, run.stderr
        checks[name] = {"input_rows_sha256": digest(input_data.encode()), "rows": len(args),
                        "result": json.loads(run.stdout)}
    return {"metadata_root": hex(root), "tables_stream": hex(stream),
            "metadata_root_plus_6": raw[root + 6], "tables_stream_plus_6": raw[stream + 6],
            "oracle_sha256": file_hash(oracle_path), "sample_record_sha256": file_hash(sample_record_path),
            "reported_heaps": rows(unit / "code/s85-heap-sizes.csv"), "il_verified": len(il),
            "slots": new_slots, "methodimpl": methodimpl, "sample": sample,
            "duplicate_control": checks}


def main():
    checker, fixed, original, task, *extra = sys.argv[1:]
    checker, fixed, original = (Path(x).resolve() for x in (checker, fixed, original))
    unit = fixed / "handoff/inbox" / task
    manifest = json.loads((fixed.parent / "fixed-manifest.json").read_bytes())
    coverage = invoke(fixed, checker, task, "--original", original, "--submission", unit)
    assert coverage["exit"] == 2, coverage
    with TemporaryDirectory() as temporary:
        temp = Path(temporary)
        if task == "NATIVE-337":
            report = showdialog(fixed, unit, original, temp)
            files = ("s93-fingerprints.json",)
            names = ("s81_showdialog.py", "s37_two_hop.py", "s65_counterexamples.py", "s93_counters.py")
        else:
            report = cli_review(fixed, unit, original, *map(Path, extra), temp)
            files = ("code/s29-fingerprints.json", "code/s85-fingerprints.json")
            names = ("cli_tables.py", "audit_340_s85.py", "audit_340_s81.py")
    print(json.dumps({"head": manifest["head"], "changed": manifest["changed"],
                      "paths_checked": len(manifest["files"]), "original_sha256": file_hash(original),
                      "coverage_checker_sha256": file_hash(checker), "coverage": coverage,
                      "manifest_recheck": check_manifests(unit, *files),
                      "tools": {name: file_hash(fixed / "tool" / name) for name in names},
                      "observed": report}, ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
