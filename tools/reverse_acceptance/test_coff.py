"""Ordinary COFF structure, bounded assembly grammar, and optional real-build controls."""
from pathlib import Path
import hashlib
import json
import os
import struct
import subprocess
import tempfile
import unittest
from unittest import mock

if __package__:
    from . import coff, verify
else:
    import coff
    import verify


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

    def test_unsupported_original_is_inconclusive(self):
        report = coff.check(b"other format", Path("."), None)
        self.assertEqual(report["status"], "inconclusive")
        self.assertEqual(report["findings"][0]["code"], "unsupported_original")

    def test_missing_and_ambiguous_source(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            self.assertEqual(coff.check(fixture(), root, None)["findings"][0]["code"], "missing_source")
            for name in ("one.s", "two.s"):
                (root / name).touch()
            result = coff.check(fixture(), root, None)
            self.assertEqual(result["findings"][0]["code"], "ambiguous_source")

    def test_unsupported_statements_do_not_reach_assembler(self):
        with tempfile.TemporaryDirectory() as temp, mock.patch.object(
                coff.subprocess, "run", side_effect=AssertionError("assembler invoked")):
            root = Path(temp)
            for line in (b'.incbin "payload"', b'.include "payload"', b'.rept 999999', b'.macro expand',
                         b'nop; .include "payload"', b'.zero 9999999', b'.p2align 31',
                         b'.section .text,"rx"; .incbin "payload"', b'# ignored\\\n.include "payload"'):
                with self.subTest(line=line):
                    (root / "different.s").write_bytes(line + b"\n")
                    result = coff.check(fixture(), root, root / "zig.exe")
                    self.assertEqual(result["findings"][0]["code"], "unsupported_assembly")

    def test_comments_are_removed_before_assembly(self):
        self.assertEqual(coff._assembly(b"# edited\n  nop  # note\r\nretq\n"), b"nop\nretq\n")

    def test_preprocessed_input_is_left_inconclusive(self):
        source = b"#if 0\n.byte 42\n#endif\n"
        with tempfile.TemporaryDirectory() as temp, mock.patch.object(
                coff.subprocess, "run", side_effect=AssertionError("assembler invoked")):
            root = Path(temp)
            for name, reason in (("choice.S", "unsupported_source_profile"), ("choice.s", "unsupported_assembly")):
                with self.subTest(name=name):
                    path = root / name
                    path.write_bytes(source)
                    result = coff.check(fixture(), root, root / "zig.exe")
                    self.assertEqual(result["status"], "inconclusive")
                    self.assertEqual(result["findings"][0]["code"], reason)
                    path.unlink()

    def test_shared_assembler_does_not_require_assembly_from_other_deliveries(self):
        with tempfile.TemporaryDirectory() as temp:
            base = Path(temp)
            original = base / "example.obj"
            original.write_bytes(fixture())
            digest = verify.digest_file(original)
            delivery = base / "delivery"
            delivery.mkdir()
            (delivery / "example.f").write_bytes(b"      END\n")
            assembler = base / "shared-tool.exe"
            single = verify.item(original, digest, delivery, assembler=assembler)
            inventory = base / "inventory.csv"
            inventory.write_text(f"产品,原路径,原件SHA256\nPlus,example.obj,{digest}\n", encoding="utf-8")
            bindings = base / "inputs.json"
            bindings.write_text(json.dumps([dict(product="Plus", path=original.name, sha256=digest,
                                                 original=original.name, delivery=delivery.name)]), encoding="utf-8")
            project = verify.project(inventory, verify.digest_file(inventory), bindings, assembler)
            for report in (single, project["rows"][0]["proof"]):
                self.assertEqual(report["status"], "inconclusive")
                self.assertFalse(any(check["scope"] == coff.SCOPE for check in report["checks"]))

    @unittest.skipUnless(os.environ.get("ASPEN_COFF_ZIG"), "set ASPEN_COFF_ZIG for real reassembly")
    def test_fresh_reassembly_and_mutations(self):
        compiler = Path(os.environ["ASPEN_COFF_ZIG"]).resolve()
        with compiler.open("rb") as stream:
            self.assertEqual(hashlib.file_digest(stream, "sha256").hexdigest(), coff.ZIG_SHA256)
        source = b".text\n.globl calculate\ncalculate:\nmovl $3,%eax\ncallq alpha\ncallq beta\nretq\n"
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            (root / "original.s").write_bytes(source)
            subprocess.run([str(compiler), "cc", "--target=x86_64-windows-gnu", "-g0", "-c",
                            "original.s", "-o", "original.obj"], cwd=root, check=True, timeout=90)
            original = (root / "original.obj").read_bytes()
            delivery = root / "delivery"
            delivery.mkdir()
            for filename, candidate, status, diagnostic in (
                    ("implementation.s", source, "pass", None),
                    ("renamed.s", b"# alternate\n" + source, "pass", None),
                    ("changed.s", source.replace(b"$3", b"$4"), "fail", "stored section bytes"),
                    ("retargeted.s", source.replace(b"callq alpha", b"callq beta"), "fail", "relocation")):
                with self.subTest(filename=filename):
                    path = delivery / filename
                    path.write_bytes(candidate)
                    report = coff.check(original, delivery, compiler)
                    self.assertEqual(report["status"], status, report)
                    if diagnostic:
                        self.assertIn(diagnostic, report["findings"][0]["message"])
                    path.unlink()

