import csv
import importlib.util
import struct
import tempfile
import unittest
from pathlib import Path

if __package__:
    from .native_sites import check
else:
    from native_sites import check


def tiny_pe(bits=64, tail=b"\xc3"):
    """A PE with two sections, an entry-point call and one by-ordinal import."""
    data = bytearray(0x600)
    data[:2] = b"MZ"
    struct.pack_into("<I", data, 0x3c, 0x80)
    data[0x80:0x84] = b"PE\0\0"
    opt_size, machine = (240, 0x8664) if bits == 64 else (224, 0x14c)
    struct.pack_into("<HHIIIHH", data, 0x84, machine, 2, 0, 0, 0, opt_size, 0x2022)
    opt = 0x98
    struct.pack_into("<H", data, opt, 0x20b if bits == 64 else 0x10b)
    struct.pack_into("<II", data, opt + 16, 0x1000, 0x1000)
    base = 0x140000000 if bits == 64 else 0x400000
    if bits == 64:
        struct.pack_into("<Q", data, opt + 24, base)
    else:
        struct.pack_into("<I", data, opt + 28, base)
    struct.pack_into("<II", data, opt + 32, 0x1000, 0x200)
    struct.pack_into("<II", data, opt + 56, 0x3000, 0x200)
    directories = 112 if bits == 64 else 96
    struct.pack_into("<I", data, opt + directories - 4, 16)
    struct.pack_into("<II", data, opt + directories + 8, 0x2000, 40)
    for i, (label, rva, raw, flags) in enumerate(((b".text", 0x1000, 0x200, 0x60000020),
                                                    (b".idata", 0x2000, 0x400, 0x40000040))):
        pos = opt + opt_size + i * 40
        data[pos:pos + len(label)] = label
        struct.pack_into("<IIII", data, pos + 8, 0x200, rva, 0x200, raw)
        struct.pack_into("<I", data, pos + 36, flags)
    struct.pack_into("<IIIII", data, 0x400, 0x2040, 0, 0, 0x2070, 0x2050)
    for slot in (0x440, 0x450):
        struct.pack_into("<Q" if bits == 64 else "<I", data, slot, (1 << (bits - 1)) + 5)
    data[0x470:0x476] = b"X.dll\0"
    address = 0x2050 - 0x1006 if bits == 64 else base + 0x2050
    call = b"\xff\x15" + struct.pack("<I", address)
    data[0x200:0x206] = call
    data[0x206:0x206 + len(tail)] = tail
    return bytes(data), call


@unittest.skipUnless(importlib.util.find_spec("iced_x86") and importlib.util.find_spec("pefile"),
                     "requires iced-x86 and pefile")
class NativeSitesTest(unittest.TestCase):
    def audit(self, extras=(), *, bits=64, tail=b"\xc3", tail_asm=None, callee="x.DLL!#5",
              call_override=None):
        original, call = tiny_pe(bits, tail)
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "code").mkdir()
            listing = [f"00001000  {(call_override or call).hex(' ')}  call [slot]"]
            if tail_asm is None:
                tail_asm = [f"00001006  {tail.hex(' ')}  instruction"]
            (root / "code/native.asm").write_text("\n".join(listing + tail_asm), encoding="utf-8")
            with (root / "calls.csv").open("w", newline="", encoding="utf-8") as f:
                writer = csv.writer(f)
                writer.writerow(("kind", "caller", "callee", "class", "listing", "note"))
                for line, cls, name in [(1, "external", callee), *extras]:
                    writer.writerow(("native", "0x1000", name, cls, f"code/native.asm#L{line}", ""))
            return check(original, root)

    def test_import_by_ordinal_and_pointer_width(self):
        for bits in (32, 64):
            with self.subTest(bits=bits):
                report = self.audit(bits=bits)
                self.assertEqual(report["status"], "pass", report)
                self.assertEqual(report["metrics"]["direct_iat_sites"], 1)

    def test_equal_counts_cannot_hide_missing_register_jump(self):
        report = self.audit([(1, "external", "X.dll!#5")], tail=b"\xff\xe0")
        codes = {r["code"] for r in report["findings"]}
        self.assertEqual(codes, {"duplicate_transfer", "missing_transfer"})
        self.assertEqual(report["metrics"]["missing_register_jumps"], 1)
        self.assertEqual(report["status"], "fail")

    def test_registered_unresolved_target_stays_open(self):
        report = self.audit([(2, "unresolved", "register")], tail=b"\xff\xe0")
        self.assertEqual(report["status"], "inconclusive")
        self.assertEqual(report["metrics"]["missing_sites"], 0)

    def test_displayed_control_instructions_match_original(self):
        for tail, display in ((b"\xc3", "CALL RAX"), (b"\xff\xe0", "JMP RCX"),
                              (b"\xeb\xfe", "JMP 0x1100")):
            with self.subTest(display=display):
                result = self.audit(tail=tail, tail_asm=[f"00001006  {tail.hex(' ')}  {display}"])
                self.assertIn("listing_flow_text", [r["code"] for r in result["findings"]])
                self.assertEqual(result["status"], "fail")

    def test_bytes_boundary_and_control_claims(self):
        for code, report in [
            ("iat_target", self.audit(callee="other.dll!#5")),
            ("listing_bytes", self.audit(call_override=b"\x90")),
            ("instruction_length", self.audit(call_override=b"\xff\x15")),
            ("non_transfer_claim", self.audit([(2, "external", "x.DLL!#5")], tail=b"\x90")),
            ("boundary_coverage", self.audit(tail_asm=[])),
        ]:
            with self.subTest(code=code):
                self.assertIn(code, [r["code"] for r in report["findings"]])
                self.assertNotEqual(report["status"], "pass")


if __name__ == "__main__":
    unittest.main()
