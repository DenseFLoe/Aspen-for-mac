"""Regression controls for submitted two-hop import routes."""
import csv
import hashlib
import importlib.util
from pathlib import Path
import struct
import tempfile
import unittest

if __package__:
    from . import verify
    from .test_native_sites import tiny_pe
else:
    import verify
    from test_native_sites import tiny_pe


@unittest.skipUnless(importlib.util.find_spec("iced_x86") and importlib.util.find_spec("pefile"),
                     "requires iced-x86 and pefile")
class ImportRoutesTest(unittest.TestCase):
    def setUp(self):
        temp = tempfile.TemporaryDirectory()
        self.addCleanup(temp.cleanup)
        root = Path(temp.name)
        self.delivery = root / "delivery"
        (self.delivery / "code").mkdir(parents=True)
        self.original = root / "original.dll"
        self.base = bytearray(tiny_pe()[0])
        struct.pack_into("<II", self.base, 0x98 + 112 + 3 * 8, 0x2080, 12)
        struct.pack_into("<III", self.base, 0x480, 0x1000, 0x1006, 0x2090)
        self.base[0x490] = 1
        self.base[0x205] = 0xc3
        self.base[0x210:0x216] = b"\xff\x25" + struct.pack("<i", 0x2050 - 0x1016)
        self.base[0x220:0x225] = b"\xe8" + struct.pack("<i", 0x1010 - 0x1025)

    def run_claims(self, overrides=None, extra=(), transfer="call", register_main=False):
        bit = b"\xe8" if transfer == "call" else b"\xe9"
        original = bytearray(self.base)
        original[0x200:0x205] = bit + struct.pack("<i", 0x1010 - 0x1005)
        self.original.write_bytes(original)
        lines = [
            "; FUNC 00001000", f"00001000 {original[0x200:0x205].hex(' ')} {transfer} 0x1010",
            "00001005 c3 ret", "; FUNC 00001010",
            f"00001010 {original[0x210:0x216].hex(' ')} jmp [slot]", "; FUNC 00001020",
            f"00001020 {original[0x220:0x225].hex(' ')} call 0x1010",
        ]
        (self.delivery / "code/native.asm").write_text("\n".join(lines), encoding="utf-8")
        with (self.delivery / "calls.csv").open("w", encoding="utf-8", newline="") as f:
            w = csv.writer(f)
            w.writerow(("kind", "caller", "callee", "class", "listing", "note"))
            w.writerow(("native", "0x1010", "X.dll!#5", "external", "code/native.asm#L5", ""))
            if register_main:
                w.writerow(("native", "0x1000", "X.dll!#5", "external", "code/native.asm#L2", ""))
        row = {"group": "import-callers", "rva": "0x1000", "primary_class": "absent", "primary_callee": "",
               "in_candidate": "yes", "owner": "0x1000", "detail": "0x1010 -> IAT 0x2050 -> x.DLL!#5"}
        with (self.delivery / "code/import-callers.csv").open("w", encoding="utf-8", newline="") as f:
            w = csv.DictWriter(f, fieldnames=list(row))
            w.writeheader()
            w.writerow({**row, **(overrides or {})})
            w.writerows({**row, **change} for change in extra)
        report = verify.item(self.original, hashlib.sha256(original).hexdigest(), self.delivery)
        native = next(c for c in report["checks"] if "import_routes" in c)
        return native["import_routes"], native["findings"]

    def test_both_source_forms_and_independent_main_registration(self):
        for transfer, registered in [("call", False), ("jmp", True)]:
            with self.subTest(transfer=transfer):
                result, _ = self.run_claims(transfer=transfer, register_main=registered)
                site, = result["sites"]
                self.assertEqual(result["counts"], {"confirmed": 1, "unresolved": 0, "contradicted": 0})
                self.assertEqual([site["original"][k] for k in ("thunk_rva", "iat_rva", "import", "owner_rva")],
                                 ["0x1010", "0x2050", "x.dll!#5", "0x1000"])
                self.assertEqual(site["main_registration"], "matches_original" if registered else "absent")
                self.assertEqual(result["unregistered_sites"], 0 if registered else 1)

    def test_each_field_must_match_its_original_evidence(self):
        for opts, field, expected in [
            ({"detail": "0x1011 -> IAT 0x2050 -> x.dll!#5"}, "thunk_rva", "0x1010"),
            ({"detail": "0x1010 -> IAT 0x2058 -> x.dll!#5"}, "iat_rva", "0x2050"),
            ({"detail": "0x1010 -> IAT 0x2050 -> x.dll!#6"}, "import", "x.dll!#5"),
        ]:
            with self.subTest(field=field):
                result, findings = self.run_claims(opts)
                site, = result["sites"]
                self.assertEqual(site["decision"], "contradicted")
                diff, = site["route_differences"]
                self.assertEqual((diff["field"], diff["original"], diff["boundary_confirmed"]),
                                 (field, expected, True))
                error, = [f for f in findings if f["code"] == f"import_route_{field}_mismatch"]
                self.assertEqual((error["site_rva"], error["listing"]), ("0x1000", "code/import-callers.csv#L2"))
        result, _ = self.run_claims({"owner": "0x1010"})
        self.assertEqual(result["sites"][0]["owner_status"], "contradicted")

    def test_missing_owner_or_unanchored_caller_cannot_confirm_row(self):
        result, _ = self.run_claims({"owner": ""}, extra=[{"rva": "0x1020", "owner": "",
                                    "detail": "0x1010 -> IAT 0x2050 -> x.dll!#6"}])
        first, other = result["sites"]
        self.assertEqual((first["decision"], first["route_status"]), ("unresolved", "confirmed"))
        self.assertEqual((other["decision"], other["route_status"]), ("unresolved", "unresolved"))
        self.assertEqual(other["route_differences"][0]["boundary_confirmed"], False)

    def test_duplicate_and_invalid_rows_stay_visible(self):
        result, findings = self.run_claims(extra=[{}, {"rva": "0x1020", "detail": "incomplete"}])
        self.assertEqual(result["counts"]["contradicted"], 2)
        self.assertIn("import_route_duplicate", [f["code"] for f in findings])
        self.assertIn("import_route_invalid_claim", [f["code"] for f in findings])
