import importlib.util
from pathlib import Path
import shutil
import struct
import tempfile
import unittest
from unittest.mock import patch

import mixed_baseline as mixed
from test_clr_fixups import fixture


def report():
    return {"metrics": dict(verified_baseline_thunks=0, baseline_thunks_missing_both=0,
                            baseline_thunks_with_listing_and_call=0, verified_newobj=0, newobj_missing_calls=0,
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

    def test_reviewed_profile_fingerprint_is_enforced(self):
        digest, = mixed.BASELINES
        self.assertTrue(mixed.baseline(digest))
        with patch.object(mixed, "BASELINES", {digest: "0" * 64}):
            with self.assertRaisesRegex(ValueError, "digest mismatch"):
                mixed.baseline(digest)


@unittest.skipUnless(importlib.util.find_spec("pefile") and importlib.util.find_spec("iced_x86") and shutil.which("pwsh"),
                     "requires pefile, iced-x86, PowerShell 7")
class MixedEvidenceTests(unittest.TestCase):
    def setUp(self):
        import pefile
        self.original = fixture()
        self.pe = pefile.PE(data=bytes(self.original), fast_load=True)
        self.addCleanup(self.pe.close)

    def test_site_is_resolved_again_against_original_slot(self):
        historical = dict(site_rva="0x1000", fixup_slot_rva="0x2290", method_token="0x06000001",
                          method_rva="0x1010", flags="0xa", method_name="First")
        line = "00001000  " + self.original[0x200:0x206].hex(" ") + "  JMP qword ptr [rip+disp]"
        row = dict(kind="native", caller="0x1000", listing="code/native.asm#L1-L1",
                   callee="vtable slot 0x140002290 -> MethodDef 0x06000001 First RVA 0x1010")
        def compare(original, listing, calls):
            r = report()
            mixed.check_thunks(original, self.pe, [historical], listing, calls, r)
            return r
        self.assertEqual(compare(self.original, [], [])["metrics"]["baseline_thunks_missing_both"], 1)
        self.assertEqual(compare(self.original, [line], [row])["findings"], [])
        r = compare(self.original, [line], [row | {"callee": row["callee"].replace("0x06000001", "0x06000002")}])
        self.assertEqual(r["findings"][0]["code"], "baseline_thunk_missing_or_incorrect_evidence")
        struct.pack_into("<i", self.original, 0x202, 0x2280 - 0x1006)
        r = compare(self.original, [line], [row])
        self.assertEqual(r["findings"][0]["code"], "baseline_original_target_disagrees")
        self.assertEqual(r["metrics"]["verified_baseline_thunks"], 0)

    def test_source_expression_is_bound_to_original_bytes_and_function(self):
        code = bytes.fromhex("65 48 8b 04 25 30 00 00 00 48 8b 40 08 c3")
        self.original[0x220:0x22e] = code
        base = "/* ---- FUNC 00001020 F (14 bytes) ---- */\nundefined8 F(void) { return *(undefined8 *)((longlong)Self + 8); }"
        for source, expected in (
            (base, "source_missing_segment_base"),
            (base.replace("Self", "Self /* __readgsqword(0x30) */"), "source_missing_segment_base"),
            (base.replace("Self", "__readgsqword(0x31)"), "segment_load_offset_mismatch"),
            (base.replace("Self", "other()"), "segment_load_source_requires_review"),
            (base.replace("00001020", "00001021"), "segment_load_source_missing_or_ambiguous"),
            (base.replace("Self", "__readgsqword(0x30)"), None)):
            with self.subTest(expected=expected):
                r = report()
                mixed.check_source(self.original, self.pe, {0x6000002: 0x1020}, source, r)
                self.assertEqual([f["code"] for f in r["findings"]], [expected] if expected else [])
                self.assertEqual(r["metrics"]["verified_segment_load_source"], int(expected is None))

    def test_load_witness_removal_or_wrong_method_is_reported(self):
        t = tempfile.TemporaryDirectory()
        self.addCleanup(t.cleanup)
        root = Path(t.name).resolve()
        (root / "code").mkdir()
        path = root / "code/loads-1020.csv"
        result = report()
        code = bytes.fromhex("65488b042530000000488b4008c3")
        asm = ["00001020  65 48 8b 04 25 30 00 00 00  MOV", "00001029  48 8b 40 08  MOV", "0000102d  c3  RET"]
        mixed.check_load_witness(root, self.pe, 0x6000002, 0x1020, code, asm, result)
        self.assertEqual(result["findings"][0]["code"], "mixed_mode_missing_artifact")
        raw = "view,data_dir14,rva,bytes,method,evidence\nCLI,0x2200/0x48,0x1020," + code.hex() + ",0x06000002,code/native.asm#L1-L3\n"
        for data, expected in [(raw, []), (raw.replace("0x06000002", "0x06000001"), ["segment_load_witness_mismatch"])]:
            path.write_text(data)
            result = report()
            mixed.check_load_witness(root, self.pe, 0x6000002, 0x1020, code, asm, result)
            self.assertEqual([f["code"] for f in result["findings"]], expected)


if __name__ == "__main__":
    unittest.main()
