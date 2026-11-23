"""Pair controls for fixed QA 93bf962c fingerprint and symbol checks."""
from hashlib import sha256
import json
from pathlib import Path
import shutil
import sys
from tempfile import TemporaryDirectory

PIN = "d0379abfd3df805081b5514ae0acf04e956018cc563b8cec4ac482aae07d3316"


def sha(path):
    return sha256(path.read_bytes()).hexdigest()


def main():
    item, original, gate = (Path(p).resolve() for p in sys.argv[1:])
    qa = gate / "qa"
    assert sha(qa / "det_fingerprint_pathset.py") == PIN
    sys.path.insert(0, str(qa))
    import det_fingerprint_pathset
    import det_symbol_substring
    import det_wrong_symbol

    result = {"qa": "93bf962ce92430fe03768f6f2808e9a8096ad47f",
        "fingerprint_detector": PIN, "symbol_detectors": {mod.__name__: sha(Path(mod.__file__)) for mod in
        (det_symbol_substring, det_wrong_symbol)}, "original_sha256": sha(original), "cases": []}
    choices = (("fixed", None, None, None), ("one_binary_byte", "code/s73-il-bodies.bin", None, None),
               ("one_csharp_byte", "code/types.cs", None, None),
               ("one_receipt_digest", "s105-submission.md", b"600975699de15c7ff150a336ac792726c40383e5229f835acdb727dd0e68c1ed", b"0" * 64),
               ("wrong_existing_import", "calls.csv", b"0x3660,KERNEL32.dll!QueryPerformanceCounter,external,code/native.asm#L1509",
                b"0x3660,KERNEL32.dll!GetStartupInfoW,external,code/native.asm#L1509"))
    with TemporaryDirectory(dir=Path.cwd()) as scratch:
        t = Path(scratch)
        shutil.copytree(item, t, dirs_exist_ok=True)
        active = Path("code/s105-fingerprints.json")
        for case, name, old, new in choices:
            if name:
                raw = (item / name).read_bytes()
                if old is None:
                    changed = bytes((raw[0] ^ 1,)) + raw[1:]
                else:
                    assert raw.count(old) == 1
                    changed = raw.replace(old, new)
                (t / name).write_bytes(changed)
                if case == "one_receipt_digest":
                    refreshed = json.loads((item / active).read_bytes())
                    refreshed["files"][name] = sha(t / name)
                    (t / active).write_text(json.dumps(refreshed, indent=1) + "\n", encoding="utf8", newline="\n")
            modules = (det_fingerprint_pathset,) if case != "wrong_existing_import" else (det_wrong_symbol, det_symbol_substring)
            r = dict(case=case, path=name, changed_sha256=sha(t / name) if name else None, results={})
            for mod in modules:
                hits, stats = mod.detect("NATIVE-340", str(t), str(original), {})
                r["results"][mod.__name__] = dict(hits=hits, stats=stats)
            result["cases"].append(r)
            if name:
                (t / name).write_bytes(raw)
            if case == "one_receipt_digest":
                shutil.copyfile(item / active, t / active)
    print(json.dumps(result, ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
