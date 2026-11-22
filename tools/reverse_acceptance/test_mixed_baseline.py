import importlib.util
import os
from pathlib import Path
import shutil
import struct
import tempfile
import unittest

import mixed_baseline as mixed
from test_clr_fixups import fixture


def report():
    return {"metrics": dict(verified_baseline_thunks=0, baseline_thunks_missing_both=0,
                            baseline_thunks_with_listing_and_call=0, verified_newobj=0, newobj_missing_calls=0,
                            nep_thunks_with_listing_and_call=0, verified_extra_predecessors=0, newobj_registered_calls=0,
                            source_missing_segment_base=0, verified_segment_load_source=0), "findings": []}


class ConstructorTests(unittest.TestCase):
    def test_operand_data_and_switch_targets_are_not_instructions(self):
        ops = {0x20: "InlineI", 0x45: "InlineSwitch", 0x73: "InlineMethod", 0x2a: "InlineNone"}
        il = bytes.fromhex("20 73 01 02 03 45 01 00 00 00 73 00 00 00 73 11 00 00 0a 2a")
        self.assertEqual(list(mixed.decode_newobj(il, ops)), [(14, 0x0a000011)])
        with self.assertRaises(ValueError):
            list(mixed.decode_newobj(il[:16], ops))

    def test_one_call_repairs_only_the_matching_site(self):
        original = {(0x06000001, n): (0x1010, 0x0a000005) for n in (0, 5)}
        listing = ["// MethodDef 0x06000001 First", "IL_0000: newobj 0x0a000005", "IL_0005: newobj 0x0a000005"]
        table = [(i, dict(caller_token="0x06000001", il_offset=f"IL_{n:04X}", caller_rva="0x1010",
                          opcode="0x73", token="0x0a000005")) for i, n in enumerate((0, 5), 2)]
        row = dict(kind="method", caller="0x06000001", callee="token 0x0a000005", listing="code/methods.il#L2-L2")
        r = report()
        mixed.check_newobj(original, listing, table, [row], r)
        self.assertEqual((r["metrics"]["verified_newobj"], r["metrics"]["newobj_missing_calls"]), (2, 1))
        self.assertEqual([f["il_offset"] for f in r["findings"]], ["0x5"])
        for change in (dict(callee="token 0x0a000006"), dict(caller="0x06000002"), dict(listing="code/methods.il#L2-L3")):
            with self.subTest(change=change):
                r = report()
                mixed.check_newobj(original, listing, table, [row | change], r)
                self.assertEqual(len(r["findings"]), 2)

    def test_deleted_or_counterfeit_constructor_still_compared_with_original(self):
        original = {(0x06000001, 0): (0x1010, 0x0a000005)}
        listing = ["// MethodDef 0x06000001 A", "IL_0005: newobj 0x0a000005"]
        r = report()
        mixed.check_newobj(original, listing, [], [], r)
        self.assertEqual(r["metrics"]["verified_newobj"], 0)
        self.assertEqual({f["code"] for f in r["findings"]},
                         {"newobj_listing_or_inventory_mismatch", "newobj_call_missing_or_incorrect", "newobj_unexpected_site"})

    def test_constructor_annex_requires_exact_original_site_and_call_reference(self):
        original = {(0x06000001, 5): (0x1010, 0x0a000005)}
        listing = ["// MethodDef 0x06000001 First", "IL_0005: newobj 0x0a000005"]
        table = [(2, dict(caller_token="0x06000001", il_offset="IL_0005", caller_rva="0x1010",
                          opcode="0x73", token="0x0a000005"))]
        annex = ["; caller MethodDef 0x06000001 First RVA 0x1010", listing[1]]
        row = dict(kind="method", caller="0x06000001", callee="System.Object::.ctor (MemberRef 0x0A000005, external)",
                   listing="proof/arbitrary-constructor-listing.il" + "#L2-L2")
        for fragment, call, count in (
            (annex, row, 1), (annex, row | {"listing": "proof/arbitrary-constructor-listing.il" + "#L1"}, 0),
            (annex, row | {"callee": row["callee"].replace("000005", "000006")}, 0),
            (annex, row | {"caller": "0x06000002"}, 0),
            ([annex[0].replace("0x1010", "0x1020"), annex[1]], row, 0),
            ([annex[0], annex[1].replace("IL_0005", "IL_0006")], row, 0),
            ([annex[0], annex[1].replace("000005", "000006")], row, 0),
        ):
            with self.subTest(fragment=fragment, call=call):
                r = report()
                mixed.check_newobj(original, listing, table, [call], r, annexes={"proof/arbitrary-constructor-listing.il": fragment})
                self.assertEqual(r["metrics"]["newobj_registered_calls"], count)
                self.assertEqual(bool(r["findings"]), not count)
        r = report()
        mixed.check_newobj(original, [], table, [row], r, annexes={
            "disassembly/renamed-primary.il": listing, "proof/arbitrary-constructor-listing.il": annex})
        self.assertEqual((r["metrics"]["verified_newobj"], r["findings"]), (1, []))

    def test_explicit_baseline_csv_must_have_schema_and_at_least_one_row(self):
        with self.assertRaisesRegex(ValueError, "header"):
            mixed.baseline(b"site_rva,method_name\n0x1010,Profile\n")
        fields = ",".join(sorted(mixed.BASELINE_FIELDS))
        with self.assertRaisesRegex(ValueError, "empty"):
            mixed.baseline(fields.encode())

    def test_additional_jump_needs_original_direct_predecessor_and_slot(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp).resolve()
            (root / "code").mkdir()
            name = "code/independently-named-evidence.csv"
            path = root / name
            header = "site_rva,slot_rva,instruction,flags,method_token,method_name,method_rva,predecessor_rva,predecessor_bytes,predecessor_target\n"
            row = "0x100a,0x2290,ff2580120000,0xa,0x06000001,First,0x1010,0x1000,eb08,0x100a\n"
            dst = dict(type=10, token=0x06000001, method="First", method_rva=0x1010)
            for text, correct in ((row, True), (row.replace("0x1000", "0x1001"), False),
                                  (row.replace("eb08", "eb09"), False),
                                  (row.replace("0x2290", "0x2298"), False), (row + row, False), ("", True)):
                with self.subTest(text=text):
                    path.write_text(header + text)
                    r = report()
                    mixed.check_extra_sites(root, {0x100a: (0x2290, bytes.fromhex("ff2580120000"))},
                                            {0x100a: [(0x1000, b"\xeb\x08")]}, {0x2290: dst}, r, [name])
                    self.assertEqual(r["metrics"]["verified_extra_predecessors"], int(correct and bool(text)))
                    self.assertEqual(bool(r["findings"]), not correct)


@unittest.skipUnless(importlib.util.find_spec("pefile") and importlib.util.find_spec("iced_x86") and shutil.which("pwsh"),
                     "requires pefile, iced-x86, PowerShell 7")
class MixedEvidenceTests(unittest.TestCase):
    def setUp(self):
        import pefile
        self.original = fixture()
        self.pe = pefile.PE(data=bytes(self.original), fast_load=True)
        self.addCleanup(self.pe.close)

    def test_site_is_resolved_again_against_original_slot(self):
        # Keep one six-byte .nep jump and its sole eight-byte descriptor.
        self.pe.sections[0].Name = b".other\0\0"
        self.pe.sections[0].Misc_VirtualSize = 6
        struct.pack_into("<II", self.original, 0x630, 0x2258, 8)
        tmp = tempfile.TemporaryDirectory()
        self.addCleanup(tmp.cleanup)
        root = Path(tmp.name).resolve()
        (root / "code").mkdir()
        historical = dict(site_rva="0x1000", fixup_slot_rva="0x2290", method_token="0x06000001",
                          method_rva="0x1010", flags="0xa", method_name="First")
        line = "00001000  " + self.original[0x200:0x206].hex(" ") + "  JMP qword ptr [0x140002290]"
        row = dict(kind="native", caller="0x1000", listing="code/native.asm#L1-L1",
                   callee="vtable slot 0x140002290 -> MethodDef 0x06000001 First RVA 0x1010")
        def compare(original, listing, calls):
            r = report()
            mixed.check_thunks(original, self.pe, [historical], listing, calls, r, root=root)
            return r
        self.assertEqual(compare(self.original, [], [])["metrics"]["baseline_thunks_missing_both"], 1)
        self.assertEqual(compare(self.original, [line], [row])["findings"], [])
        r = compare(self.original, [line], [row | {"callee": row["callee"].replace("0x06000001", "0x06000002")}])
        self.assertEqual(r["findings"][0]["code"], "baseline_thunk_missing_or_incorrect_evidence")
        annex = "code/renamed-dispatch.asm"
        (root / annex).write_text("; thunk\n" + line)
        edge = dict(kind="native", caller="0x1000", listing=annex + "#L2",
                    callee="MethodDef 0x06000001 First (managed, RVA 0x1010) via fixup slot 0x2290")
        self.assertEqual(compare(self.original, [], [edge])["findings"], [])
        for changed in [edge | {"listing": annex + "#L1"}, edge | {"listing": "code/native.asm#L2"},
                        edge | {"callee": edge["callee"].replace("0x2290", "0x2280")}]:
            self.assertEqual(compare(self.original, [], [changed])["metrics"]["baseline_thunks_with_listing_and_call"], 0)
        struct.pack_into("<Q", self.original, 0x690, 0x06000002)
        r = compare(self.original, [line], [row])
        self.assertEqual(r["findings"][0]["code"], "baseline_original_target_disagrees")
        self.assertEqual(r["metrics"]["verified_baseline_thunks"], 0)

    def test_new_original_uses_original_slots_and_source_with_history_opt_in(self):
        data = self.original
        # Add a dedicated dispatch section with a new name and link its jump to the original slot.
        struct.pack_into("<H", data, 0x86, 3)
        struct.pack_into("<I", data, 0x98 + 56, 0x4000)
        struct.pack_into("<8sIIII12xI", data, 0x98 + 240 + 80, b".stubs", 6, 0x3000, 0x200, len(data), 0x60000020)
        jump = b"\xff\x25" + struct.pack("<i", 0x2290 - 0x3006)
        data.extend(jump + bytes(0x200 - len(jump)))
        struct.pack_into("<II", data, 0x630, 0x2258, 8)
        # Two native MethodDefs, one of which implements a GS load at independent offsets.
        for rva in (0x1010, 0x1020):
            method = data.index(struct.pack("<IHH", rva, 0, 0x16), 0x700)
            struct.pack_into("<H", data, method + 4, 1)
        data[0x220:0x22e] = bytes.fromhex("65 48 8b 04 25 48 00 00 00 48 8b 40 10 c3")
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp).resolve()
            (root / "user-listing.asm").write_text("00003000  " + jump.hex(" ") + "  JMP qword ptr [0x140002290]")
            (root / "calls.csv").write_text("kind,caller,callee,listing\nnative,0x3000,"
                "vtable slot 0x140002290 -> MethodDef 0x06000001 First RVA 0x1010,user-listing.asm#L1\n")
            (root / "another-source.c").write_text("/* ---- FUNC 00001020 F (14 bytes) ---- */\n"
                "uint64_t F(void) { return *(uint64_t *)(__readgsqword(0x48) + 16); }")
            history = (b"site_rva,fixup_slot_rva,flags,method_token,method_name,method_rva\n"
                       b"0x3000,0x2290,0xa,0x06000001,First,0x1010\n")
            for reference, count in ((None, 0), (history, 1)):
                result = mixed.check(bytes(data), root, reference)
                self.assertEqual(result["status"], "pass", result)
                m = result["metrics"]
                self.assertEqual((m["original_thunk_section"], m["original_nep_thunks"]), (".stubs", 1))
                self.assertEqual((m["nep_thunks_with_listing_and_call"], m["verified_segment_load_source"]), (1, 1))
                self.assertEqual(m["verified_baseline_thunks"], count)
                self.assertEqual("baseline_sha256" in m, reference is not None)

    def test_source_expression_is_bound_to_original_bytes_and_function(self):
        code = bytes.fromhex("65 48 8b 04 25 30 00 00 00 48 8b 40 08 c3")
        self.original[0x220:0x22e] = code
        base = "/* ---- FUNC 00001020 F (14 bytes) ---- */\nundefined8 F(void) { return *(undefined8 *)((longlong)Self + 8); }"
        local = base[:base.index("{")] + "{ unsigned char *p = (unsigned char *)__readgsqword(0x30); return *(undefined8 *)(p + 8); }"
        for source, expected in (
            (base, "source_missing_segment_base"),
            (local, None),
            (local.replace("0x30", "0x31"), "segment_load_offset_mismatch"),
            (local.replace("+ 8", "+ 7"), "segment_load_offset_mismatch"),
            (local.replace("(p + 8)", "(q + 8)"), "segment_load_source_requires_review"),
            (local.replace("; return", "; p++; return"), "segment_load_source_requires_review"),
            (local.replace("unsigned char *p", "uint64_t *p"), "segment_load_source_requires_review"),
            (base.replace("Self", "Self /* __readgsqword(0x30) */"), "source_missing_segment_base"),
            (base.replace("Self", "__readgsqword(0x31)"), "segment_load_offset_mismatch"),
            (base.replace("Self", "other()"), "segment_load_source_requires_review"),
            (base.replace("00001020", "00001021"), "segment_load_source_missing_or_ambiguous"),
            (base.replace("Self", "__readgsqword(0x30)"), None)):
            with self.subTest(expected=expected):
                r = report()
                mixed.check_source(self.original, self.pe, {0x6000002: 0x1020}, {"arbitrary/source.c": source}, r)
                self.assertEqual([f["code"] for f in r["findings"]], [expected] if expected else [])
                self.assertEqual(r["metrics"]["verified_segment_load_source"], int(expected is None))

    @unittest.skipUnless(all(os.getenv(key) for key in ("WRAP_ORIGINAL", "WRAP_S13", "WRAP_S21", "WRAP_THUNK_BASELINE")),
                         "set WRAP_ORIGINAL, WRAP_S13, WRAP_S21 and WRAP_THUNK_BASELINE to replay pinned deliveries")
    def test_pinned_wrap_s13_and_s21(self):
        original = Path(os.environ["WRAP_ORIGINAL"]).read_bytes()
        for profile, historical, absent, total, predecessors, calls, source in (
            ("WRAP_S13", 4, 122, 9, 0, 0, 0), ("WRAP_S21", 126, 0, 237, 111, 16, 1)
        ):
            with self.subTest(profile=profile):
                r = mixed.check(original, Path(os.environ[profile]), Path(os.environ["WRAP_THUNK_BASELINE"]).read_bytes())
                m = r["metrics"]
                self.assertEqual(r["status"], "fail")
                self.assertEqual((m["verified_baseline_thunks"], m["original_nep_thunks"]), (126, 237))
                self.assertEqual((m["baseline_thunks_with_listing_and_call"], m["baseline_thunks_missing_both"]),
                                 (historical, absent))
                self.assertEqual((m["nep_thunks_with_listing_and_call"], m["verified_extra_predecessors"]),
                                 (total, predecessors))
                self.assertEqual((m["original_newobj"], m["verified_newobj"], m["newobj_registered_calls"],
                                  m["newobj_missing_calls"]), (21, 21, calls, 21 - calls))
                self.assertEqual((m["verified_segment_load_source"], m["source_missing_segment_base"]), (source, 1 - source))
                if profile == "WRAP_S21":
                    self.assertEqual(len(r["findings"]), 5)
                    self.assertTrue(all(f["code"] == "newobj_call_missing_or_incorrect" and
                                        f["target"].startswith("0x06") for f in r["findings"]))

    def test_load_witness_removal_or_wrong_method_is_reported(self):
        t = tempfile.TemporaryDirectory()
        self.addCleanup(t.cleanup)
        root = Path(t.name).resolve()
        (root / "code").mkdir()
        path = root / "code/loads-1020.csv"
        result = report()
        code = bytes.fromhex("65488b042530000000488b4008c3")
        asm = ["00001020  65 48 8b 04 25 30 00 00 00  MOV", "00001029  48 8b 40 08  MOV", "0000102d  c3  RET"]
        mixed.check_load_witness(root, self.pe, 0x6000002, 0x1020, code, asm, result, path.relative_to(root).as_posix())
        self.assertEqual(result["findings"][0]["code"], "mixed_mode_missing_artifact")
        raw = "view,data_dir14,rva,bytes,method,evidence\nCLI,0x2200/0x48,0x1020," + code.hex() + ",0x06000002,code/native.asm#L1-L3\n"
        for data, expected in [(raw, []), (raw.replace("0x06000002", "0x06000001"), ["segment_load_witness_mismatch"])]:
            path.write_text(data)
            result = report()
            mixed.check_load_witness(root, self.pe, 0x6000002, 0x1020, code, asm, result, path.relative_to(root).as_posix())
            self.assertEqual([f["code"] for f in result["findings"]], expected)


if __name__ == "__main__":
    unittest.main()
