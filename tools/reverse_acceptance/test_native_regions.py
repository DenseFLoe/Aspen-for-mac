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

    def test_host_data_reference_identity_must_match_at_original_site(self):
        self.claim.update(external_import_call_sites=0, import_calls_by_dll={}, rip_relative_data_sites=1,
                          rip_relative_target_regions={"X.dll (IAT)": 1})
        for identity, status in (("X.dll!#5", "pass"), ("Y.dll!#5", "fail")):
            with self.subTest(identity=identity):
                (self.delivery / "calls.csv").write_text(
                    f"caller,class,callee,note\n0x1000,data,{identity},RVA 0x1000; import slot\n", encoding="utf-8")
                _, _, result = self.audit(object_file())
                self.assertEqual(status, result["status"], result["findings"])
                row, = result["metrics"]["regions"]
                if status == "pass":
                    self.assertEqual(1, row["rip_relative_data_sites"])
                else:
                    self.assertNotIn("rip_relative_data_sites", row)
                    self.assertIn("region_host_reference", [item["code"] for item in result["findings"]])

    def test_chunk_encoded_instruction_language(self):
        import iced_x86 as x86
        for statement in (r".byte 0x40 # original redundant REX prefix\n        push rbp",
                          ".byte 0x66,0x90 # alignment NOP"):
            self.assertTrue(regions._block(f'"{statement}\\n"', x86, chunk=True))
        for statement in (r".byte 0x40 # original redundant REX prefix\n        .include hidden",
                          ".byte 0xc3 # alignment NOP", ".byte 0x90,0x90 # alignment NOP"):
            with self.assertRaises(ValueError):
                regions._block(f'"{statement}\\n"', x86, chunk=True)

    def test_cumulative_rebuild_compares_source_bytes_before_counting(self):
        import iced_x86 as x86
        import pefile
        data = bytearray(self.original.read_bytes())
        data[0x208:0x20c] = b"\x90" * 4
        pe = pefile.PE(data=bytes(data))
        digest = build._digest(data)
        paths = ("reassembly.json", "s5/reassembly-delta.json", "s9/reassembly-delta.json", regions.DELTA_MANIFEST)
        for i, path in enumerate(paths):
            doc = dict(original_sha256=digest, bodies=1, bytes=1, relocations=0,
                       matches=[dict(rva=hex(0x1008+i), bytes=1, sha256=build._digest(b"\x90"), relocations=[])])
            out = self.delivery / path
            out.parent.mkdir(exist_ok=True)
            out.write_text(json.dumps(doc), encoding="utf-8")
        for first_byte, status, count in ((0x90, "pass", 4), (0xcc, "fail", 3)):
            metrics = {"original_sha256": digest}
            current = [dict(entry="0x100b", status="pass", relocations=0, source="current",
                            compiled_input_sha256="current-input")]
            with (mock.patch.object(regions, "_chunk_source", return_value=("shard", b"", b"body", None)),
                  mock.patch.object(build, "_build", side_effect=[(bytes([first_byte]), []), (b"\x90", []),
                                                                  (b"\x90", [])]) as compiler):
                regions._cumulative(self.delivery.resolve(), pe, x86, (), self.compiler, metrics, (), doc, current)
            result = metrics["cumulative_rebuild"]
            self.assertEqual((status, count, 3), (result["status"], result["matching_ranges"], compiler.call_count))

    def test_chunk_index_rejects_uncompiled_wrapper(self):
        folder = self.delivery / "code"
        folder.mkdir()
        unit = folder / "verified.c"
        unit.write_text('#include "verified-01.h"\n', encoding="ascii")
        source = ('/* body 0x1000 until 0x1001 */\nBODY void ikc_1000(void) {\n'
                  '    __asm__(INTEL\n        "ret\\n"\n        END);\n}\n')
        with mock.patch.object(regions, "CHUNK_PRELUDE", build._digest(b"")):
            for prefix, suffix in (("", ""), ("#if 0\n", "#endif\n"), ("", "#include \"hidden.h\"\n")):
                (folder / "verified-01.h").write_text(prefix + source + suffix, encoding="ascii")
                if prefix or suffix:
                    with self.assertRaises(ValueError):
                        regions._chunk_sources(self.delivery.resolve())
                else:
                    _, bodies = regions._chunk_sources(self.delivery.resolve())
                    self.assertEqual(["ikc_1000"], list(bodies))
