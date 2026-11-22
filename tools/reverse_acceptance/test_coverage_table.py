import csv
import importlib.util
import json
from pathlib import Path
import struct
import tempfile
import unittest

import coverage_table
import verify
from test_native_sites import tiny_pe


class CoverageEvidenceTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        root = Path(self.temp.name)
        self.unit = root / "delivery"
        self.unit.mkdir()
        original, call = tiny_pe()
        data = bytearray(original)
        # A valid AMD64 exception-directory entry for the normal coverage profile.
        struct.pack_into("<II", data, 0x98 + 112 + 3 * 8, 0x20a0, 12)
        struct.pack_into("<III", data, 0x4a0, 0x1000, 0x1006, 0)
        self.original = root / "unit.dll"
        self.original.write_bytes(data)
        self.data = bytes(data)
        self.instruction = call
        self.listing = self.unit / "entry.lst"
        self.write_listing(call)
        (self.unit / "source.c").write_text("/* owner documentation\nreturn 4;\n*/\n"
                                            'int f(void) { /* explanation */ return 4; }\n', encoding="utf-8")
        (self.unit / "calls.csv").write_text("kind,caller,callee,class,listing,note\n", encoding="utf-8")
        (self.unit / "native-functions.csv").write_text("rva,name,origin\n0x1000,entry,PE\n"
                                                       "0x1006,next,tool\n", encoding="utf-8-sig")
        (self.unit / "run.json").write_text(json.dumps({"native_reported_count": 2}), encoding="utf-8")
        self.rows = [["native", "0x1000", "covered", data[0x200:0x208].hex(), "entry.lst#L1", "source.c#L4", ""],
                     ["native", "0x1006", "covered", data[0x206:0x20e].hex(), "entry.lst#L2", "source.c#L4", ""]]
        self.write_rows()

    def write_listing(self, instruction):
        self.listing.write_text(f"0000000140001000: {instruction.hex(' ')}  call [rip+0x104a]\n"
                                "00001006  c3  ret\n", encoding="utf-8")

    def write_rows(self):
        with (self.unit / "coverage.csv").open("w", encoding="utf-8-sig", newline="") as out:
            writer = csv.writer(out)
            writer.writerow(["kind", "key", "state", "first_bytes", "listing", "source", "note"])
            writer.writerows(self.rows)

    def check(self):
        return coverage_table.check(self.data, verify.tree_files(self.unit))

    def add_section_tail(self, rva, prefix, display_length):
        offset = 0x200 + rva - 0x1000
        data = bytearray(self.data)
        data[offset:offset + len(prefix)] = prefix
        self.data = bytes(data)
        self.original.write_bytes(data)
        with (self.unit / "native-functions.csv").open("a", encoding="utf-8") as out:
            out.write(f"{rva:#x},tail,tool\n")
        (self.unit / "run.json").write_text('{"native_reported_count": 3}', encoding="utf-8")
        with self.listing.open("a", encoding="utf-8") as out:
            out.write(f"{rva:08x}  {data[offset:offset + display_length].hex(' ')}  tail\n")
        self.rows.append(["native", hex(rva), "covered", data[offset:offset + 8].hex(), "entry.lst#L3",
                          "source.c#L4", ""])
        self.write_rows()

    def test_section_tail_cannot_borrow_next_raw_section_for_first_eight_bytes(self):
        self.add_section_tail(0x11ff, b"\x90", 1)
        result = self.check()
        short = next(f for f in result["findings"] if f["code"] == "original_anchor_window_short")
        self.assertEqual((result["status"], short["key"], short["mapped_bytes"], short["required_bytes"]),
                         ("inconclusive", "0x11ff", 1, 8))
        self.rows[-1][3] = "90"
        self.write_rows()
        self.assertEqual(self.check()["status"], "fail")

    def test_full_anchor_window_does_not_validate_an_instruction_crossing_sections(self):
        # MOV rax, imm64 would need two more bytes from .idata.
        self.add_section_tail(0x11f8, b"\x48\xb8" + bytes(6), 10)
        result = self.check()
        diff = next(f for f in result["findings"] if f["code"] == "coverage_reference_invalid")
        self.assertEqual((result["status"], diff["key"], diff["ref"]), ("fail", "0x11f8", "entry.lst#L3"))
        self.assertIn("exceeds original instruction bytes", diff["message"])
        self.assertNotIn("original_anchor_window_short", {f["code"] for f in result["findings"]})

    def test_raw_alignment_padding_is_outside_executable_virtual_range(self):
        self.add_section_tail(0x11f8, b"\x90", 1)
        self.assertNotIn("original_anchor_window_short", {f["code"] for f in self.check()["findings"]})
        data = bytearray(self.data)
        struct.pack_into("<I", data, 0x98 + 240 + 8, 0x1f9)
        self.data = bytes(data)
        result = self.check()
        short = next(f for f in result["findings"] if f["code"] == "original_anchor_window_short")
        self.assertEqual((result["status"], short["mapped_bytes"]), ("inconclusive", 1))

    def test_old_handoff_lists_reconcile_tool_only_discoveries(self):
        result = self.check()
        if importlib.util.find_spec("iced_x86"):
            self.assertEqual(result["status"], "pass", result["findings"])
        else:
            self.assertEqual(result["status"], "inconclusive")
        self.assertEqual(result["metrics"]["original_anchors"], 1)
        self.assertEqual(result["metrics"]["additional_discovered_native_entries"], 1)
        self.rows.pop()
        self.write_rows()
        result = self.check()
        self.assertEqual(result["status"], "fail")
        self.assertIn(("discovered_native_entry_missing", "0x1006"),
                      {(x["code"], x.get("key")) for x in result["findings"]})

    def test_wrong_noninitial_byte_in_text_listing_reaches_item_failure(self):
        self.listing.rename(self.unit / "entry.txt")
        self.listing = self.unit / "entry.txt"
        for row in self.rows:
            row[4] = row[4].replace(".lst", ".txt")
        self.write_rows()
        self.assertNotEqual(self.check()["status"], "fail")
        changed = bytearray(self.instruction)
        changed[2] ^= 1
        self.write_listing(changed)
        result = verify.item(self.original, verify.digest_file(self.original), self.unit)
        component = next(c for c in result["checks"] if c["scope"].startswith("handoff_coverage"))
        diff = next(f for f in component["findings"] if f["code"] == "coverage_reference_invalid")
        self.assertEqual((diff["key"], diff["ref"], diff["column"]), ("0x1000", "entry.txt#L1", "listing"))
        self.assertIn("RVA 0x1002", diff["message"])
        self.assertEqual((component["status"], result["status"], verify.EXIT[result["status"]]), ("fail", "fail", 1))

    @unittest.skipUnless(importlib.util.find_spec("iced_x86"), "iced-x86 required for instruction length")
    def test_truncated_listing_instruction(self):
        self.write_listing(self.instruction[:1])
        result = self.check()
        diff = next(f for f in result["findings"] if f["code"] == "coverage_reference_invalid")
        self.assertEqual((result["status"], diff["ref"]), ("fail", "entry.lst#L1"))
        self.assertIn("exactly one original instruction", diff["message"])

    def test_reference_beginning_inside_multiline_comment(self):
        self.assertNotEqual(self.check()["status"], "fail")
        self.rows[0][5] = "source.c#L2"
        self.write_rows()
        result = self.check()
        diff = next(f for f in result["findings"] if f["code"] == "coverage_reference_invalid")
        self.assertEqual((result["status"], diff["column"], diff["key"]), ("fail", "source", "0x1000"))

    def test_extra_coverage_key_and_manifest_count_cannot_mask_missing_discovery(self):
        self.rows[1][1] = "0x1007"
        self.write_rows()
        findings = self.check()["findings"]
        self.assertIn(("discovered_native_entry_missing", "0x1006"), {(r["code"], r.get("key")) for r in findings})
        self.assertIn(("unregistered_native_coverage_key", "0x1007"), {(r["code"], r.get("key")) for r in findings})
        self.rows[1][1] = "0x1006"
        self.write_rows()
        (self.unit / "run.json").write_text('{"native_reported_count": 1}', encoding="utf-8")
        self.assertIn("native_discovery_count_mismatch", {r["code"] for r in self.check()["findings"]})
