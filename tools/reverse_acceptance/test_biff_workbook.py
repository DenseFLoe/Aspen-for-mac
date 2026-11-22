"""Proof controls for the supported BIFF8 record listing."""
import struct
import unittest

if __package__:
    from . import biff_workbook as biff
else:
    import biff_workbook as biff


def make_fixture(wide):
    source = "Étage" if not wide else "算式"
    name = source.encode("utf-16le" if wide else "latin-1")
    bof = bytes.fromhex("00060500") + bytes(12)
    formula = b"\x1e\x01\x00"
    label = struct.pack("<HBBHHH", 1, 0, len(source), len(formula), 0, 1)
    label += b"\0" * 4 + bytes([wide]) + name + formula
    records = [(0x809, bof), (0x18, label), (0x0A, b"")]
    original = b"".join(struct.pack("<HH", code, len(payload)) + payload for code, payload in records)
    listing = [
        {"id": "0809", "data": bof.hex()},
        {"id": "0018", "defined_name": {
            "flags": 1, "key": 0, "ixals": 0, "scope": 1,
            "wide": wide, "text": source, "reserved": "00000000", "formula_tokens": formula.hex(),
        }},
        {"id": "000a", "data": ""},
    ]
    return original, listing


class BiffWorkbookTests(unittest.TestCase):
    def test_two_name_encodings_and_changed_formula(self):
        for wide in (0, 1):
            with self.subTest(wide=wide):
                original, rows = make_fixture(wide)
                passed = biff.compare(original, rows)
                self.assertEqual(passed["status"], "pass")
                self.assertEqual(passed["metrics"]["exact_defined_name_records"], 1)
                rows[1]["defined_name"]["formula_tokens"] = "1e0200"
                altered = biff.compare(original, rows)
                self.assertEqual(altered["status"], "fail")
                self.assertEqual(altered["findings"][0]["row"], 2)
                self.assertEqual(altered["metrics"]["exact_records"], 2)

    def test_record_missing_or_out_of_order(self):
        original, rows = make_fixture(0)
        swap = biff.compare(original, [rows[0], rows[2], rows[1]])
        self.assertEqual([item["row"] for item in swap["findings"]], [2, 3])
        missing = biff.compare(original, rows[:-1])
        self.assertEqual(missing["findings"][0]["code"], "biff_record_count")

    def test_bad_original_or_claimed_structure(self):
        original, rows = make_fixture(0)
        for invalid in (original[:2] + b"\x04\0" + original[4:],
                        original[:6] + b"\x10\0" + original[8:]):
            with self.assertRaisesRegex(ValueError, "BIFF8 Globals BOF"):
                biff.compare(invalid, rows)
        with self.assertRaisesRegex(ValueError, "incomplete or oversized"):
            biff.compare(original[:-1], rows)
        rows[1]["defined_name"]["wide"] = True
        with self.assertRaisesRegex(ValueError, "numeric"):
            biff.compare(original, rows)
