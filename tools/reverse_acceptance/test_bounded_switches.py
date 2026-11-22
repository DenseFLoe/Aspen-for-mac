"""Guarded RVA tables through the normal PE delivery audit."""
import importlib.util
from pathlib import Path
import struct
import tempfile
import unittest
from unittest.mock import patch

if __package__:
    from . import bounded_switches
    from .native_sites import check
    from .test_native_sites import tiny_pe
else:
    import bounded_switches
    from native_sites import check
    from test_native_sites import tiny_pe


def switch_image(layout, variant="valid"):
    data = bytearray(tiny_pe()[0])
    start = 0x1000 if layout == 1 else 0x1038
    default = start + 0x51
    targets = [start + 0x50, default, default] if layout == 1 else [default, start + 0x50, start + 0x82, default, start + 0x88]
    table = 0x2180 if layout == 1 else 0x2174
    if variant == "truncated":
        table = 0x21fc
    if variant == "noncode":
        targets[0] = 0x2140
    if variant == "interior":
        targets[0] = start + 1
    if variant == "overlapping_cases":
        targets[:2] = [start + 0x70, start + 0x71]
        data[0x270 + start - 0x1000:0x276 + start - 0x1000] = bytes.fromhex("b8 33 c0 00 00 c3")
    struct.pack_into("<I", data, 0x98 + 16, start)
    # Layouts vary selector, base, destination, table address, guarded extent and case count.
    cmp = bytes.fromhex("83 f8" if layout == 1 else "83 f9") + bytes([len(targets) - 1])
    ja = bytes.fromhex("0f 85" if variant == "wrong_guard" else "0f 87") + struct.pack("<i", default - start - 9)
    lea = bytes.fromhex("48 8d 15" if layout == 1 else "4c 8d 05")
    lea += struct.pack("<i", -start - 16 + (4 if variant == "wrong_base" else 0))
    extend = bytes.fromhex("48 98" if layout == 1 else "48 63 c1")
    sib = 0x82 if layout == 1 else 0x80
    if variant == "wrong_scale":
        sib ^= 0xc0
    load = bytes.fromhex("8b 8c" if layout == 1 else "45 8b 8c") + bytes([sib]) + struct.pack("<I", table)
    suffix = bytes.fromhex("48 03 ca ff e1" if layout == 1 else "4d 03 c8 41 ff e1")
    block = cmp + ja + lea + extend + load + suffix
    offset = 0x200 + start - 0x1000
    data[offset:offset + len(block)] = block
    for address in (start + 0x50, default, start + 0x82, start + 0x88):
        data[0x200 + address - 0x1000] = 0xc3
    raw = struct.pack("<" + "I" * len(targets), *targets)
    offset = 0x400 + table - 0x2000
    available = min(len(raw), len(data) - offset)
    data[offset:offset + available] = raw[:available]
    if variant == "writable":
        struct.pack_into("<I", data, 0x98 + 240 + 40 + 36, 0xc0000040)
    if variant == "split_function":
        # The JA and preceding CMP are separately rooted; no fallthrough crosses their metadata boundary.
        struct.pack_into("<II", data, 0x98 + 112 + 3 * 8, 0x20d0, 24)
        struct.pack_into("<IIIIII", data, 0x4d0, start, start + len(cmp), 0x2100,
                         start + len(cmp), start + len(block), 0x2104)
        struct.pack_into("<II", data, 0x500, 1, 1)
    return bytes(data), start, targets


@unittest.skipUnless(importlib.util.find_spec("iced_x86") and importlib.util.find_spec("pefile"), "requires PE decoder")
class BoundedSwitchTest(unittest.TestCase):
    def audit(self, image, listing=""):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "code").mkdir()
            (root / "code/native.asm").write_text(listing, encoding="ascii")
            (root / "calls.csv").write_text("kind,caller,callee,class,listing,note\n", encoding="ascii")
            return check(image, root)

    def test_two_layouts_and_seven_independent_mutations(self):
        for layout in (1, 2):
            for variant in ("valid", "wrong_guard", "wrong_base", "wrong_scale", "writable", "truncated", "noncode", "interior"):
                with self.subTest(layout=layout, variant=variant):
                    image, start, targets = switch_image(layout, variant)
                    result = self.audit(image)
                    audit = result["bounded_switch_paths"]
                    self.assertEqual(audit["examined_register_jumps"], 1)
                    if variant in ("wrong_guard", "wrong_base", "wrong_scale"):
                        self.assertEqual(audit["paths"], [])
                        self.assertEqual(audit["unmatched_register_jumps"], 1)
                        continue
                    record, = audit["paths"]
                    self.assertEqual(record["guard_rva"], hex(start))
                    self.assertTrue(record["original_boundary_confirmed"])
                    self.assertFalse(record["listed_site"])
                    self.assertEqual(result["metrics"]["original_reachable_unlisted_sites"], 1)
                    if variant == "valid":
                        self.assertEqual(record["status"], "verified_table_mapping")
                        self.assertEqual(record["unsigned_selector_max"], len(targets) - 1)
                        self.assertEqual(record["table_bytes"], 4 * len(targets))
                        self.assertEqual(record["entry_bytes"], 4)
                        self.assertEqual(record["ordered_target_rvas"], list(map(hex, targets)))
                        by_rva = {x["rva"]: x["boundary"] for x in record["destinations"]}
                        self.assertEqual(by_rva[record["default_target_rva"]], "original_root_path")
                        self.assertIn("selector_derived_candidate", by_rva.values())
                    else:
                        self.assertEqual(record["status"], "inconclusive")
                        if variant in ("writable", "truncated"):
                            self.assertEqual(record["ordered_target_rvas"], [])
                        else:
                            self.assertEqual(record["reason"], "destination_boundary_unverified")

    def test_matching_address_still_needs_its_main_registration(self):
        image, _, _ = switch_image(1)
        site = self.audit(image)["bounded_switch_paths"]["paths"][0]["site_rva"]
        result = self.audit(image, f"{int(site, 16):08x}  ff e1  jmp rcx")
        record, = result["bounded_switch_paths"]["paths"]
        self.assertTrue(record["listed_site"])
        self.assertEqual(record["status"], "verified_table_mapping")
        self.assertEqual(result["metrics"]["missing_sites"], 1)
        self.assertEqual(result["metrics"]["original_reachable_unlisted_sites"], 0)
        self.assertEqual(result["status"], "fail")

    def test_conflicting_case_decodings_and_budget_remain_open(self):
        image, _, _ = switch_image(1, "overlapping_cases")
        record, = self.audit(image)["bounded_switch_paths"]["paths"]
        self.assertEqual(record["status"], "inconclusive")
        self.assertEqual(sum(d["boundary"] == "overlapping_selector_destinations" for d in record["destinations"]), 2)
        image, _, _ = switch_image(1)
        with patch.object(bounded_switches, "MAX_TOTAL_ENTRIES", 1):
            record, = self.audit(image)["bounded_switch_paths"]["paths"]
        self.assertEqual(record["reason"], "entry_budget_exceeded")
        self.assertEqual(record["ordered_target_rvas"], [])

    def test_competing_destinations_across_tables_and_unchanged_aliases(self):
        same_start = [{"boundary": "selector_derived_candidate"} for _ in range(2)]
        interior = {"boundary": "selector_derived_candidate"}
        unrelated = {"boundary": "selector_derived_candidate"}
        bounded_switches.mark_overlapping_entries({
            0x1940: (5, same_start),
            0x1941: (1, [interior]),
            0x1945: (1, [unrelated]),
        })
        for entry in [*same_start, interior]:
            self.assertEqual(entry["boundary"], "overlapping_selector_destinations")
        self.assertEqual(unrelated["boundary"], "selector_derived_candidate")

    def test_contiguous_independent_roots_do_not_prove_a_connected_guard(self):
        image, _, _ = switch_image(1, "split_function")
        summary = self.audit(image)["bounded_switch_paths"]
        self.assertEqual((summary["examined_register_jumps"], summary["unmatched_register_jumps"]), (1, 1))

    def test_ordinary_return_and_x86_keep_existing_scope(self):
        for bits in (32, 64):
            image, _ = tiny_pe(bits)
            result = self.audit(image)
            self.assertEqual(result["metrics"]["original_reachable_unlisted_sites"], 1)
            if bits == 64:
                self.assertEqual(result["bounded_switch_paths"]["paths"], [])
            else:
                self.assertNotIn("bounded_switch_paths", result)
