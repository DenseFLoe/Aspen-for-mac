import csv
import importlib.util
from pathlib import Path
import shutil
import struct
import tempfile
import unittest
from unittest.mock import patch

import clr_fixups
from test_native_sites import tiny_pe


def metadata():
    """A compressed metadata root with one module, one TypeDef and two MethodDefs."""
    strings = b"\0sample\0<Module>\0First\0Second\0"
    tables = bytearray(struct.pack("<IBBBBQQIII", 0, 2, 0, 0, 1, 0x45, 0, 1, 1, 2))
    tables.extend(struct.pack("<5H", 0, 1, 1, 0, 0))
    tables.extend(struct.pack("<I5H", 0, strings.index(b"<Module>"), 0, 0, 1, 1))
    for name, rva in ((b"First", 0x1010), (b"Second", 0x1020)):
        tables.extend(struct.pack("<I5H", rva, 0, 0x16, strings.index(name), 1, 1))
    streams = [(b"#~", tables), (b"#Strings", strings), (b"#GUID", bytes(16)), (b"#Blob", b"\0\x03\0\0\x01")]
    root = bytearray(struct.pack("<4sHHII12sHH", b"BSJB", 1, 1, 0, 12, b"v4.0.30319", 0, len(streams)))
    headers = [(name + bytes(4 - len(name) % 4), block) for name, block in streams]
    base = len(root) + sum(8 + len(name) for name, _ in headers)
    payload = bytearray()
    for name, block in headers:
        root.extend(struct.pack("<II", base + len(payload), len(block)) + name)
        payload.extend(block)
        payload.extend(bytes(-len(payload) % 4))
    return bytes(root + payload)


def fixture():
    original = bytearray(tiny_pe()[0])
    # Extend the second file-backed section to hold metadata, header and fixups.
    original.extend(bytes(0x400))
    sec = 0x98 + 240 + 40
    for off in (8, 16):
        struct.pack_into("<I", original, sec + off, 0x600)
    struct.pack_into("<II", original, 0x98 + 112 + 14 * 8, 0x2200, 72)
    meta = metadata()
    struct.pack_into("<IHHII", original, 0x600, 72, 2, 5, 0x2300, len(meta))
    struct.pack_into("<II", original, 0x630, 0x2250, 16)
    # Two adjacent four-byte original slots and one eight-byte slot.
    struct.pack_into("<IHHIHH", original, 0x650, 0x2280, 2, 1, 0x2290, 1, 0xa)
    struct.pack_into("<II", original, 0x680, 0x06000001, 0x06000002)
    struct.pack_into("<Q", original, 0x690, 0x06000001)
    original[0x700:0x700 + len(meta)] = meta
    original[0x200:0x206] = b"\xff\x25" + struct.pack("<i", 0x2290 - 0x1006)
    return original


@unittest.skipUnless(importlib.util.find_spec("pefile") and shutil.which("pwsh"), "requires pefile and PowerShell 7")
class ClrFixupTests(unittest.TestCase):
    def setUp(self):
        tmp = tempfile.TemporaryDirectory()
        self.addCleanup(tmp.cleanup)
        self.root = Path(tmp.name)
        (self.root / "code").mkdir()
        self.pe = fixture()
        self.header = "entry,rva,count,type,width,slot,token,method,method_rva,state".split(",")
        self.rows = [
            [0, "0x2280", 2, "0x1", 4, 0, "0x06000001", "First", "0x1010", "resolved"],
            [0, "0x2280", 2, "0x1", 4, 1, "0x06000002", "Second", "0x1020", "resolved"],
            [1, "0x2290", 1, "0xa", 8, 0, "0x06000001", "First", "0x1010", "resolved"],
        ]

    def check(self):
        with (self.root / clr_fixups.TABLE).open("w", newline="", encoding="utf-8-sig") as f:
            writer = csv.writer(f)
            writer.writerow(self.header)
            writer.writerows(self.rows)
        return clr_fixups.check(bytes(self.pe), self.root)

    def test_real_metadata_multiple_slots_mixed_widths(self):
        self.rows.reverse()
        result = self.check()
        self.assertEqual(result["status"], "pass", result)
        self.assertEqual([result["metrics"][f"verified_{kind}"] for kind in ("entries", "slots", "methoddefs")],
                         [2, 3, 2])

    def test_other_real_method_still_wrong_at_this_slot(self):
        self.rows[1][6:9] = self.rows[0][6:9]
        result = self.check()
        finding, = result["findings"]
        self.assertEqual((result["status"], finding["line"], finding["slot_rva"]), ("fail", 3, "0x2284"))
        self.assertEqual(set(finding["differences"]), {"method", "token", "method_rva"})

    def test_omission_and_duplicate_despite_unchanged_row_count(self):
        self.rows[1] = self.rows[0]
        result = self.check()
        self.assertEqual(result["status"], "fail")
        self.assertEqual({i["code"] for i in result["findings"]},
                         {"clr_fixup_duplicate_slot", "clr_fixup_missing_slot"})
        self.assertEqual(result["metrics"]["verified_slots"], 1)

    def test_descriptor_identity_and_state_are_checked(self):
        self.rows[1][1:5] = ["0x2284", 1, "0x2", 8]
        self.rows[1][-1] = "pending"
        self.assertEqual(set(self.check()["findings"][0]["differences"]), {"rva", "count", "type", "width", "state"})

    def test_invalid_original_full_width_token_does_not_pass(self):
        struct.pack_into("<Q", self.pe, 0x690, 0x106000001)
        r = self.check()
        self.assertEqual((r["status"], r["findings"][0]["code"]), ("inconclusive", "clr_fixup_original_unreadable"))

    def test_truncated_original_and_overlapping_slots(self):
        for address in (0x2280, 0x25fc):
            with self.subTest(address=address):
                struct.pack_into("<I", self.pe, 0x658, address)
                self.assertEqual(self.check()["status"], "inconclusive")

    def test_reader_failure_is_inconclusive(self):
        with patch("clr_fixups.shutil.which", return_value=None):
            result = self.check()
        self.assertEqual(result["status"], "inconclusive")
        self.assertEqual(result["metrics"]["verified_slots"], 0)

    @unittest.skipUnless(importlib.util.find_spec("iced_x86"), "requires iced-x86")
    def test_submitted_edge_requires_original_instruction_and_static_method(self):
        site = bytes(self.pe[0x200:0x206]).hex(" ")
        (self.root / "code/native.asm").write_text(f"00001000  {site}  jmp [rip+disp]\n")
        path = self.root / clr_fixups.EDGES
        header = "line,addr,caller,kind,slot,slot_value,target,instruction,in_calls\n"
        row = "1,0x1000,0x1000,vtable-slot,0x140002290,0x6000001,MethodDef 0x06000001 First RVA 0x1010,jmp,yes\n"
        path.write_text(header + row)
        result = self.check()
        self.assertEqual((result["status"], result["metrics"]["verified_transfer_rows"]), ("pass", 1), result)
        path.write_text(header + row.replace("0x140002290", "0x140002280"))
        self.assertEqual(self.check()["findings"][0]["code"], "clr_fixup_edge_mismatch")


if __name__ == "__main__":
    unittest.main()
