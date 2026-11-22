"""Coverage controls through the native acceptance entry point."""
import importlib.util
from pathlib import Path
import struct
import tempfile
import unittest
from unittest.mock import patch

if __package__:
    from .native_sites import check
    from .test_native_sites import tiny_pe
else:
    from native_sites import check
    from test_native_sites import tiny_pe


@unittest.skipUnless(importlib.util.find_spec("iced_x86") and importlib.util.find_spec("pefile"),
                     "requires iced-x86 and pefile")
class HistoricalCoverageTest(unittest.TestCase):
    def audit(self, original, rows, current=()):
        with tempfile.TemporaryDirectory() as directory:
            delivery = Path(directory)
            (delivery / "code").mkdir()
            listing = [f"{site:08x}  {raw.hex(' ')}  original" for site, raw in current]
            (delivery / "code/native.asm").write_text("\n".join(listing), encoding="ascii")
            (delivery / "calls.csv").write_text("kind,caller,callee,class,listing,note\n", encoding="ascii")
            return check(original, delivery, historical_listing=b"rva,bytes\n" + rows)["historical_listing"]

    @staticmethod
    def image(code, bits=64):
        image = bytearray(tiny_pe(bits)[0])
        image[0x200:0x200 + len(code)] = code
        return bytes(image)

    def test_proven_omission_repair_and_padding(self):
        for bits in (32, 64):
            with self.subTest(bits=bits):
                image = self.image(bytes.fromhex("31 c0 90 cc"), bits)
                rows = b"1000,31c0\n1002,90\n1003,cc\n"
                missing = self.audit(image, rows)
                self.assertEqual(missing["status"], "fail")
                self.assertEqual([r["rva"] for r in missing["missing_nonpadding"]], ["0x1000"])
                self.assertEqual([r["rva"] for r in missing["missing_nop_or_int3"]], ["0x1002", "0x1003"])
                repaired = self.audit(image, rows, [(0x1000, bytes.fromhex("31 c0"))])
                self.assertEqual((repaired["status"], repaired["verified_baseline_instructions"]), ("pass", 3))

    def test_interior_and_unreachable_decode_remain_unproven_even_if_listed(self):
        image = self.image(bytes.fromhex("b8 33 c0 00 00 c3 90 31 db c3"))
        for rows, site, raw, reason in [
                (b"1001,33c0\n", 0x1001, b"\x33\xc0", "overlaps_verified_instruction"),
                (b"1006,90\n", 0x1006, b"\x90", "no_independent_original_path"),
                (b"1007,31db\n", 0x1007, b"\x31\xdb", "no_independent_original_path")]:
            for listed in (False, True):
                with self.subTest(site=site, listed=listed):
                    result = self.audit(image, rows, [(site, raw)] if listed else [])
                    self.assertEqual((result["status"], result["verified_baseline_instructions"]), ("inconclusive", 0))
                    self.assertFalse(result["missing_nonpadding"] or result["missing_nop_or_int3"])
                    row, = result["unproven_boundaries"]
                    self.assertEqual((row["reason"], row["listed"]), (reason, listed))

    def test_overlapping_paths_and_exhausted_walk_remain_unproven(self):
        image = self.image(bytes.fromhex("74 01 b8 eb 02 00 00 31 c0 c3"))
        # Both candidate paths to XOR depend on conflicting interpretations.
        ambiguous = self.audit(image, b"1007,31c0\n")
        self.assertEqual(ambiguous["status"], "inconclusive")
        with patch(check.__module__ + ".ORIGINAL_WALK_LIMIT", 1):
            capped = self.audit(image, b"1000,7401\n")
        self.assertEqual(capped["status"], "inconclusive")

    def test_invalid_csv_structure_is_atomic(self):
        image = self.image(bytes.fromhex("48 89 c1 c3"))
        for rows in (b"1000,4889c1\n1003,9\n", b"1000,4889c1\n1003,c3,extra\n", b""):
            result = self.audit(image, rows)
            self.assertEqual((result["status"], result["verified_baseline_instructions"]), ("inconclusive", 0))
            self.assertFalse(result["missing_nonpadding"])

    def test_individual_reference_rows_cannot_hide_other_proven_omissions(self):
        image = self.image(bytes.fromhex("b8 33 c0 00 00 31 db c3"))
        ordinary = b"1005,31db\n1007,c3\n"
        for extra, interior, mismatch, duplicate in (
                (b"1000,b833c00000\n1001,33c0\n", 1, 0, 0),
                (b"1001,33db\n", 0, 1, 0),
                (b"1007,c3\n1005,31db\n", 0, 0, 2)):
            with self.subTest(extra=extra):
                result = self.audit(image, ordinary + extra, [(0x1000, bytes.fromhex("b8 33 c0 00 00"))])
                self.assertEqual([r["rva"] for r in result["missing_nonpadding"]], ["0x1005", "0x1007"])
                self.assertEqual(result["status"], "fail")
                self.assertEqual(len(result["unproven_boundaries"]), interior)
                self.assertEqual(len(result["unverified_identity_rows"]), mismatch)
                self.assertEqual(result["duplicate_rows"], duplicate)
        mismatch = self.audit(image, b"1005,31de\n")
        self.assertEqual((mismatch["status"], len(mismatch["unverified_identity_rows"])), ("inconclusive", 1))

    @staticmethod
    def c_handler(target, *, symbol=b"__C_specific_handler", module=b"VCRUNTIME140.dll",
                  count=1, extra_record=None):
        # The only ordinary rooted path returns before this separate handler continuation.
        image = bytearray(HistoricalCoverageTest.image(bytes.fromhex("b8 33 c0 00 00 c3")))
        island = 0x200 + target - 0x1000
        image[island:island + 4] = bytes.fromhex("31 db 90 c3")
        struct.pack_into("<II", image, 0x98 + 112 + 3 * 8, 0x2100, 12)
        struct.pack_into("<III", image, 0x500, 0x1000, 0x1060, 0x2120)
        thunk, slot = 0x1070, 0x2050
        image[0x270:0x276] = b"\xff\x25" + struct.pack("<i", slot - (thunk + 6))
        for offset in (0x440, 0x450):
            struct.pack_into("<Q", image, offset, 0x2090)
        image[0x470:0x471 + len(module)] = module + b"\0"
        image[0x492:0x493 + len(symbol)] = symbol + b"\0"
        struct.pack_into("<IIIIIII", image, 0x520, 9, thunk, count, 0x1000, 0x1005, 1, target)
        if extra_record:
            struct.pack_into("<IIII", image, 0x53c, *extra_record)
        return bytes(image)

    def test_c_scope_continuation_proves_local_fallthrough_at_two_layouts(self):
        for target in (0x1014, 0x1033):
            with self.subTest(target=target):
                rows = f"{target:x},31db\n{target+2:x},90\n".encode()
                image = self.c_handler(target)
                missing = self.audit(image, rows)
                self.assertEqual(missing["status"], "fail")
                self.assertEqual(missing["verified_baseline_instructions"], 2)
                entry, = missing["exception_continuations"]
                self.assertEqual(entry["target_rva"], hex(target))
                self.assertEqual(entry["scope_record_rva"], "0x212c")
                repaired = self.audit(image, rows, [(target, b"\x31\xdb")])
                self.assertEqual(repaired["status"], "pass")
                gap = self.audit(image, f"{target+4:x},0000\n".encode())
                self.assertEqual(gap["status"], "inconclusive")

    def test_c_scope_requires_handler_identity_and_entire_bounded_table(self):
        for changes in ({"symbol": b"other_handler"}, {"module": b"other.dll"}, {"count": 0x100},
                        {"count": 2, "extra_record": (0x1000, 0x1005, 1, 0x1075)}):
            with self.subTest(changes=changes):
                result = self.audit(self.c_handler(0x1014, **changes), b"1014,31db\n")
                self.assertEqual(result["status"], "inconclusive")
                self.assertFalse(result["exception_continuations"])

    def test_exception_metadata_cannot_certify_a_conflicting_decode_or_crossing(self):
        image = bytearray(self.c_handler(0x1014))
        struct.pack_into("<I", image, 0x538, 0x1001)
        self.assertEqual(self.audit(bytes(image), b"1001,33c0\n")["status"], "inconclusive")
        # Exception end splits the entry MOV. A historical row with matching bytes still cannot certify it.
        struct.pack_into("<I", image, 0x504, 0x1002)
        result = self.audit(bytes(image), b"1000,b833c00000\n")
        self.assertEqual(result["status"], "inconclusive")

    def test_conflicting_handler_thunk_cannot_promote_its_continuations(self):
        image = bytearray(self.c_handler(0x1014))
        image[0x200:0x205] = b"\xe9" + struct.pack("<i", 0x106f - 0x1005)
        image[0x26f] = 0xb8  # MOV now overlaps the independently named exception handler thunk.
        result = self.audit(bytes(image), b"1014,31db\n")
        self.assertEqual(result["status"], "inconclusive")
        self.assertFalse(result["missing_nonpadding"])

    def test_c_scope_table_in_writable_data_is_unconfirmed(self):
        image = bytearray(self.c_handler(0x1014))
        struct.pack_into("<I", image, 0x98 + 240 + 40 + 36, 0xc0000040)
        result = self.audit(bytes(image), b"1014,31db\n")
        self.assertEqual(result["status"], "inconclusive")

    def test_filter_requires_an_independently_proven_instruction_boundary(self):
        for filter_rva, status in ((0x1000, "fail"), (0x1001, "inconclusive"), (0x1014, "inconclusive")):
            with self.subTest(filter_rva=filter_rva):
                image = bytearray(self.c_handler(0x1014))
                struct.pack_into("<I", image, 0x534, filter_rva)
                self.assertEqual(self.audit(bytes(image), b"1014,31db\n")["status"], status)

    def test_joint_walk_rechecks_filters_and_allows_an_independent_alternative(self):
        for independent, status in ((False, "inconclusive"), (True, "fail")):
            with self.subTest(independent=independent):
                image = bytearray(self.c_handler(0x1033, count=3 if independent else 2,
                                                 extra_record=(0x1000, 0x1002, 1, 0x1014)))
                image[0x200:0x202] = bytes.fromhex("eb 13")
                image[0x214:0x21a] = bytes.fromhex("b8 33 c0 00 00 c3")
                struct.pack_into("<I", image, 0x534, 0x1015)
                if independent:
                    struct.pack_into("<IIII", image, 0x54c, 0x1000, 0x1002, 1, 0x1033)
                result = self.audit(bytes(image), b"1015,33c0\n1033,31db\n")
                self.assertEqual(result["status"], status)
                self.assertTrue(any(not row["boundaries_confirmed"] for row in result["exception_continuations"]))

    def test_partial_exception_directory_is_not_a_root_or_range_boundary(self):
        image = bytearray(self.c_handler(0x1014))
        struct.pack_into("<II", image, 0x500, 0x1014, 0x1060)
        rows = b"1000,b833c00000\n1014,31db\n"
        self.assertEqual(len(self.audit(bytes(image), rows)["missing_nonpadding"]), 2)
        struct.pack_into("<I", image, 0x98 + 112 + 3 * 8 + 4, 13)
        partial = self.audit(bytes(image), rows)
        self.assertEqual([r["rva"] for r in partial["missing_nonpadding"]], ["0x1000"])
        self.assertEqual([r["rva"] for r in partial["unproven_boundaries"]], ["0x1014"])

    @classmethod
    def typed_catch(cls):
        target, catch = 0x1014, 0x1060
        image = bytearray(cls.c_handler(target, symbol=b"__CxxFrameHandler4", module=b"VCRUNTIME140_1.dll"))
        struct.pack_into("<I", image, 0x98 + 112 + 3 * 8 + 4, 24)
        struct.pack_into("<III", image, 0x50c, catch, catch + 1, 0x2140)
        image[0x260] = 0xc3
        struct.pack_into("<I", image, 0x540, 1)
        struct.pack_into("<I", image, 0x528, 0x2150)
        struct.pack_into("<BII", image, 0x550, 0x10, 0x2160, 0)
        image[0x560:0x568] = bytes.fromhex("02 00 00 02") + struct.pack("<I", 0x2170)
        image[0x570:0x57b] = bytes([2, 0x12]) + struct.pack("<II", 0x3000, catch) + bytes([2 * (target - 0x1000)])
        # RTTI commonly lives in writable non-executable data.
        struct.pack_into("<H", image, 0x86, 3)
        struct.pack_into("<I", image, 0x98 + 56, 0x4000)
        struct.pack_into("<8sIIIIIIHHI", image, 0x98 + 240 + 80, b".data", 0x200, 0x3000, 0x200, 0x600,
                         0, 0, 0, 0, 0xc0000040)
        image.extend(bytes(0x200))
        struct.pack_into("<QQ", image, 0x600, 0x140002040, 0)
        image[0x610:0x618] = b"Example\0"
        return image

    def test_type_descriptor_requires_backed_pointers_and_a_complete_printable_name(self):
        good = self.typed_catch()
        self.assertEqual(self.audit(bytes(good), b"1014,31db\n")["status"], "fail")
        for offset, raw in ((0x600, bytes(8)), (0x600, struct.pack("<Q", 0x140004000)), (0x608, b"\x01"),
                            (0x610, b"\0"), (0x612, b"\x01"), (0x610, b"x" * 0x1f0)):
            with self.subTest(offset=offset, size=len(raw)):
                image = good.copy()
                image[offset:offset + len(raw)] = raw
                self.assertEqual(self.audit(bytes(image), b"1014,31db\n")["status"], "inconclusive")

    def test_catch_funclet_must_survive_joint_boundary_confirmation(self):
        image = self.typed_catch()
        image[0x200:0x205] = b"\xe9" + struct.pack("<i", 0x1061 - 0x1005)
        image[0x260:0x266] = bytes.fromhex("b8 33 c0 00 00 c3")
        struct.pack_into("<I", image, 0x510, 0x1066)
        result = self.audit(bytes(image), b"1014,31db\n")
        self.assertEqual(result["status"], "inconclusive")
        row, = result["exception_continuations"]
        self.assertEqual(row["funclet_rva"], "0x1060")
        self.assertFalse(row["boundaries_confirmed"])
