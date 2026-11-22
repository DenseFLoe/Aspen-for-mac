import csv
import hashlib
import importlib.util
import struct
import sys
import tempfile
import types
import unittest
from unittest.mock import Mock, patch
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


def ordinal_provider(target=0x21c0):
    data = bytearray(tiny_pe()[0])
    struct.pack_into("<II", data, 0x98 + 112, 0x2080, 40)
    struct.pack_into("<IIHHIIIIIII", data, 0x480, 0, 0, 0, 0, 0x2070, 5, 1, 0, 0x20c0, 0, 0)
    struct.pack_into("<I", data, 0x4c0, target)
    return bytes(data)


@unittest.skipUnless(importlib.util.find_spec("iced_x86") and importlib.util.find_spec("pefile"),
                     "requires iced-x86 and pefile")
class NativeSitesTest(unittest.TestCase):
    def audit(self, extras=(), *, bits=64, tail=b"\xc3", tail_asm=None, callee="x.DLL!#5",
              call_override=None, first_class="external", head=None, tables=None, provider=None, pe_edit=None):
        original, call = tiny_pe(bits, tail)
        if pe_edit:
            original = pe_edit(original)
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "code").mkdir()
            if head:
                original = original[:0x200] + head + original[0x200 + len(head):]
            listing = [f"00001000  {(head or call_override or call).hex(' ')}  " + ("nop" if head else "call [slot]")]
            if tail_asm is None:
                tail_asm = [f"00001006  {tail.hex(' ')}  instruction"]
            (root / "code/native.asm").write_text("\n".join(listing + tail_asm), encoding="utf-8")
            with (root / "calls.csv").open("w", newline="", encoding="utf-8") as f:
                writer = csv.writer(f)
                writer.writerow(("kind", "caller", "callee", "class", "listing", "note"))
                initial = [(1, first_class, callee)] if first_class else []
                for line, cls, name in [*initial, *extras]:
                    writer.writerow(("native", "0x1000", name, cls, f"code/native.asm#L{line}", ""))
            for name, records in (tables or {}).items():
                with (root / name).open("w", newline="", encoding="utf-8") as f:
                    csv.writer(f).writerows(records)
            trusted = None
            if provider:
                blob, digest = provider
                path = root / "provider.dll"
                path.write_bytes(blob)
                trusted = (path, digest or hashlib.sha256(blob).hexdigest())
            return check(original, root, trusted)

    def test_target_audit_receives_proven_indirect_transfers_and_original_main_rows(self):
        module_name = check.__module__.removesuffix("native_sites") + "native_targets"
        module = types.ModuleType(module_name)
        module.audit = Mock()
        with patch.dict(sys.modules, {module_name: module}):
            rows = [(2, "unresolved", "rax"), (2, "boundary", "callback"), (2, "external", "Y.dll!run"),
                    (2, "data", "auxiliary operand"), (3, "unresolved", "jump"),
                    (1, "data", "IAT 0x2050 (X.dll!#5)")]
            result = self.audit(rows, tail=b"\xff\xd0\xff\xe0",
                                tail_asm=["00001006  ff d0  call rax", "00001008  ff e0  jmp rax"])
            args = module.audit.call_args.args
            main, proven, by_file = args[7], args[-2], args[-1]
            self.assertEqual(set(main), {0x1000, 0x1006, 0x1008})
            self.assertEqual(proven, {0x1000, 0x1006, 0x1008})
            self.assertEqual(by_file["code/native.asm"], ([1, 2, 3], [0x1000, 0x1006, 0x1008], 3))
            self.assertTrue(main[0x1000][0]["known_iat"])
            self.assertEqual([row["classification"] for row in main[0x1006]], ["unresolved", "boundary", "external"])
            self.assertFalse(any(row["known_iat"] for row in main[0x1006]))
            self.assertEqual(main[0x1006][2], {"owner": 0x1000, "source": "calls.csv#L5", "listing": "code/native.asm#L2",
                                              "callee": "Y.dll!run", "classification": "external", "known_iat": False})
            self.assertEqual(main[0x1008][0]["callee"], "jump")
            self.assertEqual(result["metrics"]["explicitly_unresolved_sites"], 2)
            self.audit(tail=b"\xff\xd0\xc3", tail_asm=[])
            args = module.audit.call_args.args
            self.assertNotIn(0x1006, args[7])
            self.assertIn(0x1006, args[-2])
            self.assertNotIn(0x1006, args[-1]["code/native.asm"][1])
            module.audit.side_effect = ValueError("invalid target record")
            invalid = self.audit()
            self.assertEqual(invalid["status"], "fail")
            self.assertIn("invalid_target_evidence", [f["code"] for f in invalid["findings"]])
            self.assertEqual(invalid["metrics"]["registered_expected_sites"], 1)

    def test_deleting_only_a_listing_line_moves_a_gap_to_original_coverage(self):
        # Jump over bytes that look like an indirect call. The actual indirect jump is farther
        # along the direct target's fallthrough; neither that target nor the jump needs to be listed.
        tail = b"\xeb\x02\xff\xd0\x90\xff\xe0"
        listing = ["00001006  eb 02  jmp 0x100a", "0000100b  ff e0  jmp rax"]
        for bits in (32, 64):
            with self.subTest(bits=bits):
                full = self.audit(bits=bits, tail=tail, tail_asm=listing)
                self.assertEqual(full["metrics"]["missing_sites"], 1)
                self.assertEqual(full["metrics"]["original_reachable_unlisted_sites"], 0)
                shortened = self.audit(bits=bits, tail=tail, tail_asm=listing[:1])
                self.assertEqual(shortened["status"], "fail")
                self.assertEqual(shortened["metrics"]["missing_sites"], 0)
                self.assertEqual(shortened["metrics"]["original_reachable_indirect_sites"], 2)
                self.assertEqual(shortened["original_reachability"]["unlisted_transfers"], [
                    {"site_rva": "0x100b", "transfer": "indirect_jump", "root_rva": "0x1000", "root_kind": "entry_point",
                     "predecessor_rva": "0x100a", "edge": "fallthrough", "basis": "unambiguous_code_root_path",
                     "status": "fail"}])

    def test_overlap_or_exhausted_budget_does_not_certify_hidden_sites(self):
        # The conditional branch targets the second byte of the fallthrough instruction.
        overlap = self.audit(tail=b"\x74\x01\xff\xe0\xc3\xc3", tail_asm=[])
        self.assertEqual(overlap["status"], "inconclusive", overlap)
        self.assertEqual(overlap["metrics"]["original_reachable_unlisted_sites"], 0)
        self.assertEqual(overlap["metrics"]["original_candidate_unlisted_sites"], 1)
        walk = overlap["original_reachability"]
        self.assertIn("overlapping_original_boundaries", walk["diagnostics"])
        self.assertEqual(walk["unlisted_transfers"][0]["basis"], "overlapping_instruction_boundary")
        # A direct branch from the middle of that ambiguous instruction also makes a downstream
        # indirect jump provisional, even when no bytes overlap at the jump itself.
        downstream = self.audit(tail=b"\x74\x01\xb8\xeb\x02\x00\x00\xff\xe0", tail_asm=[])
        self.assertEqual(downstream["metrics"]["original_candidate_unlisted_sites"], 1, downstream)
        self.assertEqual(downstream["metrics"]["original_reachable_unlisted_sites"], 0)
        with patch(check.__module__ + ".ORIGINAL_WALK_LIMIT", 1):
            limited = self.audit(tail=b"\xff\xe0", tail_asm=[])
        self.assertEqual(limited["status"], "inconclusive")
        self.assertTrue(limited["original_reachability"]["budget_exhausted"])
        self.assertIn("instruction_budget_exhausted", limited["original_reachability"]["diagnostics"])

    def test_exception_root_can_certify_an_executable_export(self):
        def edited(data, unwind):
            image = bytearray(data)
            exported = ordinal_provider(0x1007)
            image[0x98 + 112:0x98 + 120] = exported[0x98 + 112:0x98 + 120]
            image[0x480:0x4c4] = exported[0x480:0x4c4]
            if unwind:
                struct.pack_into("<II", image, 0x98 + 112 + 3 * 8, 0x20d0, 12)
                struct.pack_into("<III", image, 0x4d0, 0x1007, 0x1009, 0x20e0)
                image[0x4e0] = 1
            return bytes(image)
        for unwind, status, root_kind in [(False, "inconclusive", "executable_section_export"),
                                          (True, "fail", "exception_function")]:
            with self.subTest(unwind=unwind):
                result = self.audit(tail=b"\xc3\xff\xe0", tail_asm=["00001006  c3  ret"],
                                    pe_edit=lambda data: edited(data, unwind))
                item, = result["original_reachability"]["unlisted_transfers"]
                self.assertEqual((item["site_rva"], item["root_kind"], item["status"]), ("0x1007", root_kind, status))

    def test_old_and_current_direct_edges_bind_to_the_original_operand(self):
        old = ["owner", "site", "target", "target_owner", "instruction"]
        modern = ["owner_rva", "site_rva", "target_rva", "basis"]
        def audit(header, record):
            return self.audit(tail=b"\xeb\xfe", tables={"internal-transfers.csv": [header, record]})
        for header, row in [(old, ["0x1000", "0x1006", "0x1006", "0x1000", "jmp 00001006h"]),
                            (modern, ["0x1000", "0x1006", "0x1006", "direct"])]:
            with self.subTest(header=header):
                self.assertEqual(audit(header, row)["status"], "pass")
                wrong = list(row)
                wrong[2] = "0x1007"
                result = audit(header, wrong)
                self.assertIn("internal_direct_target", [f["code"] for f in result["findings"]])
                self.assertEqual(result["status"], "fail")
        for text in ("call 00001006h", "jmp 00001007h", "unknown"):
            result = audit(old, ["0x1000", "0x1006", "0x1006", "0x1000", text])
            self.assertIn("internal_direct_instruction", [f["code"] for f in result["findings"]])

    def test_sidecar_gap_requires_main_row_at_same_owner_and_site(self):
        header = ["owner_rva", "site_rva", "observation"]
        tables = {"control-gaps.csv": [header, ["0x1000", "0x1006", "candidate target only"]],
                  "internal-transfers.csv": [["site_rva", "target_rva", "basis"],
                                             ["0x1006", "0x1000", "candidate table entry"]]}
        kwargs = {"tail": b"\xff\xe0", "tables": tables}
        result = self.audit([(2, "unresolved", "register")], **kwargs)
        self.assertEqual(result["status"], "inconclusive")
        self.assertEqual(result["control_gap_records"][0]["unresolved_main_rows"][0]["source"], "calls.csv#L3")
        result = self.audit(**kwargs)
        self.assertEqual(result["status"], "fail")
        self.assertEqual(result["metrics"]["unresolved_site_rvas"], ["0x1006"])
        self.assertEqual(result["metrics"]["missing_sites"], 1)
        self.assertEqual(result["control_gap_records"][0]["unresolved_main_rows"], [])
        tables["control-gaps.csv"][1][0] = "0x1001"
        result = self.audit([(2, "unresolved", "register")], **kwargs)
        self.assertIn("control_gap_main_row", [f["code"] for f in result["findings"]])

    def test_data_iat_read_stub_calls_and_provider_are_independent(self):
        read = b"\x48\x8b\x05" + struct.pack("<I", 0x2050 - 0x100d)
        scalar = b"\xf2\x0f\x10\x00"
        stub = b"\xff\x25" + struct.pack("<I", 0x2050 - 0x1018)
        body = [(0x1006, read), (0x100d, scalar), (0x1011, b"\xc3"), (0x1012, stub)]
        kwargs = {"extras": [(2, "data", "X.dll!#5"), (5, "data", "X.dll!#5")],
                  "tail": b"".join(ins for _, ins in body),
                  "tail_asm": [f"{rva:08x}  {ins.hex(' ')}  instruction" for rva, ins in body],
                  "head": b"\x66\x0f\x1f\x44\x00\x00", "first_class": None}
        good = self.audit(**kwargs, provider=(ordinal_provider(), None))
        item = good["data_import_evidence"][0]
        self.assertFalse(item["provider_export"]["executable"])
        self.assertEqual(item["slot_reads"][0]["scalar_double_read_rva"], "0x100d")
        self.assertEqual(item["data_registered_jump_thunks"][0]["observed_direct_incoming_rvas"], [])
        self.assertEqual(item["observed_call_rvas"], [])
        self.assertEqual(good["metrics"]["missing_sites"], 0)
        self.assertNotEqual(good["status"], "fail", good)
        missing = self.audit(**kwargs, provider=(ordinal_provider(), "0" * 64))
        self.assertIsNone(missing["data_import_evidence"][0]["provider_export"])
        self.assertIn("data_thunk_provider", [f["code"] for f in missing["findings"]])
        wrong = self.audit(**kwargs, provider=(ordinal_provider(0x1000), None))
        self.assertIn("data_thunk_control", [f["code"] for f in wrong["findings"]])
        kwargs.update(head=None, first_class="external")
        called = self.audit(**kwargs, provider=(ordinal_provider(), None))
        self.assertEqual(called["data_import_evidence"][0]["observed_call_rvas"], ["0x1000"])
        self.assertIn("call_to_data_export", [f["code"] for f in called["findings"]])
        kwargs["extras"] = []
        dropped = self.audit(**kwargs, provider=(ordinal_provider(), None))
        evidence = dropped["data_import_evidence"][0]
        self.assertEqual(evidence["observed_call_rvas"], ["0x1000"])
        self.assertEqual(evidence["observed_iat_jump_rvas"], ["0x1012"])
        self.assertEqual(evidence["data_registered_jump_thunks"], [])
        self.assertEqual(evidence["slot_reads"][0]["site_rva"], "0x1006")
        self.assertEqual(dropped["metrics"]["missing_sites"], 1)
        hidden = self.audit(first_class="data")
        self.assertIn("data_hides_call", [f["code"] for f in hidden["findings"]])
        self.assertEqual(hidden["metrics"]["missing_sites"], 1)
        ancillary = self.audit([(1, "data", "IAT 0x2050 (X.dll!#5)")])
        self.assertEqual(ancillary["status"], "pass")
        forged = self.audit([(1, "data", "IAT 0x2058 (X.dll!#5)")])
        self.assertIn("data_iat_target", [f["code"] for f in forged["findings"]])

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
