"""Controls for export range ownership, isolated source rebuilding and COFF fixups."""
from contextlib import ExitStack
import hashlib
import importlib.util
import json
from pathlib import Path
import struct
import tempfile
import unittest
from unittest import mock

if __package__:
    from . import native_exports as exports
    from .test_native_sites import tiny_pe
else:
    import native_exports as exports
    from test_native_sites import tiny_pe


def source(instruction):
    return ('#include "register-forms.h"\nNAKED void F(void) {\n    __asm__(START\n'
            f'        "{instruction}\\n"\n        "ret\\n"\n        END);\n}}\n').encode()


def object_file(symbol=b"rva_2050", pos=2, kind=4, name=b"F", body=None):
    code = bytes.fromhex("ff 15 00 00 00 00 c3") if body is None else body
    rel = 60 + len(code)
    header = struct.pack("<HHIIIHH", 0x8664, 1, 0, rel + 10, 2, 0, 0)
    section = struct.pack("<8sIIIIIIHHI", b".text", 0, 0, len(code), 60, rel, 0, 1, 0, 0x60500020)
    symbols = struct.pack("<8sIhHBB", name, 0, 1, 0x20, 2, 0)
    symbols += struct.pack("<8sIhHBB", symbol, 0, 0, 0, 2, 0)
    return header + section + code + struct.pack("<IIH", pos, 1, kind) + symbols + struct.pack("<I", 4)


def export_pe():
    data = bytearray(tiny_pe()[0])
    dirs = 0x98 + 112
    struct.pack_into("<II", data, dirs, 0x20a0, 64)
    struct.pack_into("<IIHHIIIIIII", data, 0x4a0, 0, 0, 0, 0, 0x2070, 1, 1, 1, 0x20d0, 0x20d4, 0x20d8)
    struct.pack_into("<IIH", data, 0x4d0, 0x1000, 0x20dc, 0)
    data[0x4dc:0x4de] = b"F\0"
    struct.pack_into("<II", data, dirs + 24, 0x2100, 12)
    struct.pack_into("<III", data, 0x500, 0x1000, 0x1007, 0x2110)
    data[0x510] = 1
    return bytes(data)


@unittest.skipUnless(importlib.util.find_spec("iced_x86") and importlib.util.find_spec("pefile"),
                     "requires iced-x86 and pefile")
class ExportControls(unittest.TestCase):
    def setUp(self):
        import iced_x86
        self.x86 = iced_x86
        self.stack = ExitStack()
        self.addCleanup(self.stack.close)
        tmp = Path(self.stack.enter_context(tempfile.TemporaryDirectory()))
        self.root = tmp / "delivery"
        self.s5 = self.root / "s5"
        self.s5.mkdir(parents=True)
        self.original = export_pe()
        self.raw = self.original[0x200:0x207]
        self.src = source("call qword ptr [rip + rva_2050]")
        self.zig = tmp / "zig.exe"
        self.zig.write_bytes(b"test executable fingerprint")
        (self.s5 / "register-forms.h").write_bytes(b"test header")
        (self.s5 / "F.c").write_bytes(self.src)
        self.stack.enter_context(mock.patch.object(exports, "HEADER_SHA256", exports._digest(b"test header")))
        zig_hash = hashlib.sha256(self.zig.read_bytes()).hexdigest()
        self.stack.enter_context(mock.patch.object(exports, "ZIG_SHA256", zig_hash))
        # Substitute only the compiler process. The actual reader, object parser,
        # original export directory, unwind range, decoder and relocation logic run.
        self.obj = object_file()

        def compile_double(args, cwd, **kwargs):
            self.assertEqual("export.c", args[-3])
            self.assertNotEqual(self.root, cwd)
            self.assertEqual(self.src, (cwd / "export.c").read_bytes())
            self.assertEqual({"export.c", "register-forms.h"}, {p.name for p in cwd.iterdir()})
            (cwd / "export.obj").write_bytes(self.obj)
            return mock.Mock(returncode=0)

        self.compiler = self.stack.enter_context(mock.patch.object(exports.subprocess, "run",
                                                                  side_effect=compile_double))
        self.manifest = {"original_sha256": exports._digest(self.original), "matching_bytes": 7, "exports": {
            "F": {"entry": "0x1000", "exclusive_end": "0x1007", "matching_bytes": 7, "rel32": 1,
                  "original_text_sha256": exports._digest(self.raw), "source_sha256": exports._digest(self.src)}}}

    def audit(self):
        (self.s5 / "business-evidence.json").write_text(json.dumps(self.manifest), encoding="utf-8")
        return exports.check(self.original, self.root, self.zig)

    def test_export_matches_after_symbolic_fixup(self):
        r = self.audit()
        self.assertEqual("pass", r["status"], r["findings"])
        self.assertEqual(7, r["metrics"]["matching_bytes"])
        self.assertEqual(1, r["metrics"]["exports"]["F"]["relocations"])
        self.compiler.assert_called_once()

    def test_same_count_wrong_target_and_exact_site(self):
        self.obj = object_file(symbol=b"rva_2051")
        r = self.audit()
        self.assertEqual("fail", r["status"])
        f, = r["findings"]
        self.assertEqual(("export_relocation_target", "F", "0x1002", "0x2050", "0x2051"),
                         (f["code"], f["export"], f["rva"], f["original"], f["rebuilt"]))
        self.assertEqual(0, r["metrics"]["matching_bytes"])

    def test_compensating_symbol_and_addend_errors(self):
        self.obj = object_file(symbol=b"rva_2051", body=bytes.fromhex("ff 15 ff ff ff ff c3"))
        r = self.audit()
        self.assertEqual("fail", r["status"])
        f, = r["findings"]
        self.assertEqual(("export_relocation_symbol", 0, -1), (f["code"], f["expected_addend"], f["addend"]))

    def test_same_size_wrong_code(self):
        self.obj = object_file(body=bytes.fromhex("ff 15 00 00 00 00 90"))
        r = self.audit()
        f, = r["findings"]
        self.assertEqual(("export_code_byte", "0x1006", "c3", "90"),
                         (f["code"], f["rva"], f["original"], f["rebuilt"]))

    def test_same_count_wrong_site(self):
        self.obj = object_file(pos=1)
        r = self.audit()
        f, = r["findings"]
        self.assertEqual(("export_relocation_field", "0x1001"), (f["code"], f["rva"]))

    def test_prelinked_literal_cannot_replace_external_relocation(self):
        f = exports._compare(self.raw, self.raw, [], 0x1000, self.x86)
        self.assertEqual(("export_missing_relocation", "0x1002"), (f["code"], f["rva"]))

    def test_wrong_range_cannot_truncate_comparison(self):
        self.manifest["exports"]["F"]["exclusive_end"] = "0x1006"
        r = self.audit()
        f, = r["findings"]
        self.assertEqual(("fail", "0x1007", "0x1006"), (r["status"], f["original"], f["rebuilt"]))

    def test_syntactically_unsafe_input_cannot_launch_compiler(self):
        for unsafe in ['.include "bad"', '.incbin "bad"', "db 0xc3", ".byte 0xc3 # alignment nop",
                       "ret; .include bad", 'ret\\n" MACRO "\\n', "call ../bad"]:
            with self.subTest(unsafe=unsafe):
                (self.s5 / "F.c").write_bytes(source(unsafe))
                self.assertEqual("inconclusive", self.audit()["status"])
        (self.s5 / "F.c").write_bytes(self.src)
        (self.s5 / "register-forms.h").write_bytes(b'#include "outside.h"')
        self.assertEqual("inconclusive", self.audit()["status"])
        self.compiler.assert_not_called()

    def test_untrusted_or_missing_tool_and_missing_source(self):
        self.audit()
        self.compiler.reset_mock()
        self.assertEqual("inconclusive", exports.check(self.original, self.root, None)["status"])
        self.zig.write_bytes(b"different executable")
        self.assertEqual("inconclusive", self.audit()["status"])
        self.zig.write_bytes(b"test executable fingerprint")
        (self.s5 / "F.c").unlink()
        self.assertEqual("fail", self.audit()["status"])
        self.compiler.assert_not_called()

    def test_forged_and_duplicate_manifest(self):
        self.manifest["exports"]["fake"] = self.manifest["exports"]["F"]
        r = self.audit()
        self.assertEqual(("fail", "export_absent"), (r["status"], r["findings"][0]["code"]))
        self.compiler.reset_mock()
        (self.s5 / "business-evidence.json").write_text('{"exports": {}, "exports":{}}', encoding="utf-8")
        self.assertEqual("inconclusive", exports.check(self.original, self.root, self.zig)["status"])
        self.compiler.assert_not_called()

    def test_no_unwind_leaf_requires_straight_line(self):
        import pefile
        pe = pefile.PE(data=self.original, fast_load=True)
        with self.assertRaisesRegex(ValueError, "Leaf end"):
            exports._extent(pe, 0x1000, [0x1000], [], self.x86)
        self.assertEqual(0x1007, exports._extent(pe, 0x1006, [0x1000], [], self.x86)[0])

    def test_coff_function_symbol_and_relocation_validation(self):
        for obj in [object_file(name=b"G"), object_file(pos=4), object_file(kind=3),
                    object_file(symbol=b"bad")]:
            with self.assertRaises(ValueError):
                exports._coff(obj, "F")


if __name__ == "__main__":
    unittest.main()
