"""Test method identity in the pinned omitted-sites detector."""
import argparse
import csv
from hashlib import sha256
import io
import json
from pathlib import Path
import sys
from tempfile import TemporaryDirectory


def digest(data):
    return sha256(data).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("qa", type=Path)
    parser.add_argument("original", type=Path)
    parser.add_argument("candidate", type=Path)
    args = parser.parse_args()
    detector = args.qa / "det_omitted_sites.py"
    assert digest(detector.read_bytes()) == "2424b60278d5ed26226f1a2432a14c78f096e7085a021437370235a566333d1c"
    original = args.original.read_bytes()
    original_sha = digest(original)
    assert original_sha == "869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec"
    sys.path.insert(0, str(args.qa.resolve()))
    import common
    import det_omitted_sites

    methods = (0x06000056, 0x06000057)
    offset = 4
    missing_site = f"method {methods[1]:#010x} IL_{offset:04X}"
    pe = common.prepared_pe(original)
    expected = det_omitted_sites._calli_expected(original, pe, common.cli_methoddefs(original))
    assert all({"token": m, "offset": offset} in expected for m in methods)
    listing = (args.candidate / "code/methods.il").read_bytes()
    source_lines = listing.decode("utf-8-sig").splitlines()
    lines = []
    for token in methods:
        start, = (i for i, line in enumerate(source_lines) if line.startswith(f"// MethodDef 0x{token:08X} "))
        stop = next(i for i in range(start + 1, len(source_lines)) if source_lines[i].startswith("// MethodDef "))
        line, = (x for x in source_lines[start:stop] if x.strip().startswith("IL_0004: calli"))
        lines.extend((source_lines[start], line))
    listing_data = ("\n".join(lines) + "\n").encode()
    cases = []
    with TemporaryDirectory() as temp:
        for keep in (2, 1):
            folder = Path(temp) / str(keep)
            folder.mkdir()
            (folder / "methods.il").write_bytes(listing_data)
            register = io.StringIO(newline="")
            table = csv.writer(register, lineterminator="\n")
            table.writerow(("token", "offset", "listing"))
            for i, token in enumerate(methods[:keep], 1):
                table.writerow((f"0x{token:08X}", f"0x{offset:04X}", f"methods.il#L{2*i}"))
            record = register.getvalue().encode()
            (folder / "calli.csv").write_bytes(record)
            hits, stats = det_omitted_sites.detect("NATIVE-340", str(folder), str(args.original), {})
            locators = [row["locator"] for row in hits if row["locator"].startswith("method ")]
            cases.append({
                "registered": keep,
                "calli_csv_sha256": digest(record),
                "expected_missing_at_0x06000057": keep == 1,
                "actual_missing_at_0x06000057": missing_site in locators,
                "all_calli_missing_reported": stats["calli_missing"],
            })
    print(json.dumps({
        "original_sha256": original_sha,
        "candidate_listing_sha256": digest(listing),
        "detector_sha256": digest(detector.read_bytes()),
        "paired_listing_sha256": digest(listing_data),
        "cases": cases,
    }, indent=2))


if __name__ == "__main__":
    main()
