"""Regression controls for scoped internal rebuild evidence."""
import importlib.util
import json
from pathlib import Path
import tempfile
import unittest
from unittest import mock

if __package__:
    from . import native_exports as build, native_regions as regions, verify
    from .test_native_exports import export_pe, object_file
else:
    import native_exports as build
    import native_regions as regions
    import verify
    from test_native_exports import export_pe, object_file


@unittest.skipUnless(importlib.util.find_spec("iced_x86") and importlib.util.find_spec("pefile"),
                     "requires iced-x86 and pefile")
class RegionControls(unittest.TestCase):
    def setUp(self):
        temp = tempfile.TemporaryDirectory()
        self.addCleanup(temp.cleanup)
        path = Path(temp.name)
        self.delivery = path / "delivery"
        self.folder = self.delivery / "s13"
        self.folder.mkdir(parents=True)
        self.original = path / "original.dll"
        data = bytearray(export_pe())
        data[0x108:0x110] = bytes(8)  # This body is not a named export.
        self.original.write_bytes(data)
        self.digest = build._digest(data)
        self.raw_digest = build._digest(data[0x200:0x207])
        self.compiler = path / "zig.exe"
        self.compiler.write_bytes(b"fixed test compiler")
        self.header = b"reviewed macro body in this fixture"
        (self.folder / "host-encoding.h").write_bytes(self.header)
        self.source = (b'#include "host-encoding.h"\n\n'
                       b'__asm__(".globl rva_1000\\n.set rva_1000, F\\n");\n'
                       b'NAKED void F(void) {\n    __asm__(START\n'
                       b'        "    call qword ptr [rip + rva_2050]\\n" /* 01000 */\n'
                       b'        "    ret\\n" /* 01006 */\n        END);\n}\n')
        (self.folder / "F.c").write_bytes(self.source)
        self.claim = {"entry": "0x1000", "exclusive_end": "0x1007", "original_text_sha256": self.raw_digest,
                      "rebuilt_text_sha256": self.raw_digest, "source_sha256": build._digest(self.source),
                      "instructions": 2, "matching_bytes": 7, "rel32": 1}
        self.manifest = {"original_sha256": self.digest, "hosts": {"F": self.claim},
                         "matched_bytes": 7, "matched_instructions": 2, "checked_rel32": 1}

    def audit(self, coff=None, compiler=True):
        (self.delivery / regions.HOST_MANIFEST).write_text(json.dumps(self.manifest), encoding="utf-8")

        def run(args, cwd, **_):
            self.assertEqual({"export.c", "register-forms.h"}, {p.name for p in cwd.iterdir()})
            text = (cwd / "export.c").read_text(encoding="ascii")
            self.assertIn('call qword ptr [rip + rva_2050]', text)
            self.assertNotIn(".globl", text)
            (cwd / "export.obj").write_bytes(coff)
            return mock.Mock(returncode=0)

        with (mock.patch.object(regions, "HOST_HEADER", build._digest(self.header)),
              mock.patch.object(build, "ZIG_SHA256", build._digest(self.compiler.read_bytes())),
              mock.patch.object(build.subprocess, "run", side_effect=run) as invocation):
            report = verify.item(self.original, self.digest, self.delivery,
                                 assembler=self.compiler if compiler else None)
        return report, invocation, next(c for c in report["checks"] if "regions" in c["metrics"])

    def test_fresh_internal_body_pass_and_same_bytes_wrong_symbol(self):
        for operand, status in [(b"rva_2050", "pass"), (b"rva_2051", "fail")]:
            with self.subTest(operand=operand):
                report, call, result = self.audit(object_file(symbol=operand))
                call.assert_called_once()
                self.assertEqual(status, result["status"], result["findings"])
                row, = result["metrics"]["regions"]
                self.assertEqual(status, row["rebuild_status"])
                self.assertNotEqual("pass", report["status"])
                if status == "fail":
                    error, = result["findings"]
                    self.assertEqual(("region_relocation_target", "0x1000", "0x1002", "0x2050", "0x2051"),
                                     tuple(error[key] for key in ("code", "instruction_rva", "rva", "original", "rebuilt")))

    def test_original_fact_conflict_is_retained_without_compiler(self):
        self.claim["exclusive_end"] = "0x1006"
        _, call, result = self.audit(compiler=False)
        call.assert_not_called()
        self.assertEqual("fail", result["status"])
        self.assertIn("region_manifest_fact", [f["code"] for f in result["findings"]])
        self.assertEqual(0, result["metrics"]["matching_bytes"])

    def test_unreviewed_source_never_reaches_compiler(self):
        for directive in [b'        ".include otherfile\\n"\n', b'        "nop; ret\\n"\n']:
            with self.subTest(directive=directive):
                (self.folder / "F.c").write_bytes(self.source.replace(b"        END);", directive + b"        END);"))
                _, call, result = self.audit()
                call.assert_not_called()
                self.assertEqual("inconclusive", result["status"])
                self.assertEqual(0, result["metrics"]["matching_bytes"])
