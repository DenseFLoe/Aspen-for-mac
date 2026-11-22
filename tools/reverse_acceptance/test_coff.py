"""Regression checks for comparison by bytes, symbolic targets and source identity."""
from pathlib import Path
import hashlib
import struct
import tempfile
import unittest
from unittest import mock

if __package__:
    from . import coff
else:
    import coff


def fixture(target=0, value=0, reverse_symbols=False, attr=0x60500020):
    body = bytes((value, 0, 0, 0))
    names = [b"one", b"two"]
    if reverse_symbols:
        names.reverse()
        target = 1 - target
    header = struct.pack("<HHIIIHH", 0x8664, 1, 0, 74, 2, 0, 0)
    section = struct.pack("<8sIIIIIIHHI", b".text", 0, 0, 4, 60, 64, 0, 1, 0, attr)
    reloc = struct.pack("<IIH", 0, target, 4)
    syms = b"".join(struct.pack("<8sIhHBB", name, 0, 0, 0, 2, 0) for name in names)
    return header + section + body + reloc + syms + struct.pack("<I", 4)


class CoffControls(unittest.TestCase):
    def test_symbol_renumbering_is_allowed(self):
        self.assertIsNone(coff._compare(fixture(), fixture(reverse_symbols=True)))

    def test_same_count_different_target(self):
        self.assertIn("relocation", coff._compare(fixture(), fixture(target=1)))

    def test_same_size_different_code(self):
        self.assertIn(".text+0x0", coff._compare(fixture(), fixture(value=1)))

    def test_changed_alignment(self):
        self.assertIn("characteristics", coff._compare(fixture(), fixture(attr=0x60400020)))

    def test_unknown_original_is_inconclusive(self):
        self.assertEqual(coff.check(fixture(), Path("."), None)["status"], "inconclusive")

    def test_unreviewed_source_is_never_assembled(self):
        original = fixture()
        with tempfile.TemporaryDirectory() as temp, mock.patch.object(
                coff, "ORIGINALS", {hashlib.sha256(original).hexdigest()}), mock.patch.object(
                coff.subprocess, "run", side_effect=AssertionError("assembler invoked")):
            root = Path(temp)
            (root / "BFDYLD.s").write_bytes(b'.incbin "replacement.obj"\n')
            result = coff.check(original, root, root / "zig.exe")
            self.assertEqual(result["findings"][0]["code"], "unreviewed_source")
            self.assertEqual(result["status"], "fail")

