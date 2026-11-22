"""Submitted-site controls for IAT, immutable pointer and scoped register witnesses."""
import importlib.util
import struct
import unittest

if __package__:
    from .target_witness import _loader_slots, verify
    from .test_native_sites import tiny_pe
else:
    from target_witness import _loader_slots, verify
    from test_native_sites import tiny_pe


BASE = 0x140000000
DIRS = 0x98 + 112
SLOT = 0x2118


def rip(opcode, start, target):
    return opcode + struct.pack("<i", target - start - len(opcode) - 4)


def fixture(body, *, writable=False, reloc=True, target_entry=True, guard=False, named=False):
    """Plain PE, two unwind records and one relocated pointer to an internal function."""
    raw = bytearray(tiny_pe()[0])
    raw[0x200:0x200 + len(body)] = body
    raw[0x240] = 0xc3
    if writable:
        struct.pack_into("<I", raw, 0x98 + 240 + 40 + 36, 0xc0000040)
    struct.pack_into("<II", raw, DIRS + 3 * 8, 0x2080, 24 if target_entry else 12)
    struct.pack_into("<IIIIII", raw, 0x480, 0x1000, 0x1000 + len(body), 0x20a0, 0x1040, 0x1041, 0x20a4)
    raw[0x4a0:0x4a8] = bytes.fromhex("01 00 00 00 01 00 00 00")
    if reloc:
        struct.pack_into("<II", raw, DIRS + 5 * 8, 0x20b0, 12)
        struct.pack_into("<IIHH", raw, 0x4b0, 0x2000, 12, 0xa118, 0)
    struct.pack_into("<Q", raw, 0x518, BASE + 0x1040)
    if guard:
        struct.pack_into("<II", raw, DIRS + 10 * 8, 0x2128, 0x94)
        struct.pack_into("<I", raw, 0x528, 0x94)
        struct.pack_into("<Q", raw, 0x528 + 120, BASE + SLOT)
        struct.pack_into("<I", raw, 0x528 + 144, 0x100)
    if named:
        for offset in (0x440, 0x450):
            struct.pack_into("<Q", raw, offset, 0x21d0)
        raw[0x5d0:0x5d7] = b"\x00\x00Work\x00"
    return bytes(raw)


@unittest.skipUnless(importlib.util.find_spec("pefile") and importlib.util.find_spec("iced_x86"),
                     "requires pefile and iced-x86")
class TargetWitnessTests(unittest.TestCase):
    def check(self, body, site, claim, **options):
        import pefile
        import iced_x86
        pe = pefile.PE(data=fixture(body, **options), fast_load=True)
        return verify(pe, 0x1000, 0x1000 + len(body), site, {"site": hex(site), **claim}, iced_x86)

    def table(self, before=b"", between=b"", tail=b"\xc3", **options):
        definition = 0x1000 + len(before)
        head = before + rip(b"\x48\x8d\x05", definition, SLOT - 24) + between
        site = 0x1000 + len(head)
        witness = {"kind": "readonly_table", "register": "rax", "definition_rva": hex(definition),
                   "slot_rva": hex(SLOT)}
        witness.update(options.pop("witness", {}))
        return self.check(head + b"\xff\x50\x18" + tail, site,
                          {"witness": witness, "target": options.pop("target", "0x1040")}, **options)

    def test_direct_iat_name_and_ordinal(self):
        for named, name in [(False, "#5"), (True, "Work")]:
            with self.subTest(name=name):
                claim = {"external": {"iat_rva": "0x2050", "import": "x.DLL!" + name},
                         "witness": {"kind": "iat", "slot_rva": "0x2050"}}
                body = rip(b"\xff\x15", 0x1000, 0x2050) + b"\xc3"
                result = self.check(body, 0x1000, claim, named=named)
                self.assertEqual(("pass", "instruction_operand", "X.dll!" + name),
                                 (result["status"], result["binding_scope"], result["external"]["import"]))
                claim["external"]["import"] = "X.dll!Other"
                self.assertEqual("witness_import", self.check(body, 0x1000, claim, named=named)["code"])

    def test_rip_readonly_pointer_needs_typed_original_target(self):
        body = rip(b"\xff\x15", 0x1000, SLOT) + b"\xc3"
        claim = {"target": "0x1040", "witness": {"kind": "readonly_slot", "slot_rva": hex(SLOT)}}
        result = self.check(body, 0x1000, claim)
        self.assertEqual(("pass", "0x1040", "IMAGE_REL_BASED_DIR64"),
                         (result["status"], result["target"], result["original"]["pointer_type"]))
        for condition in [{"writable": True}, {"reloc": False}, {"target_entry": False}]:
            with self.subTest(condition=condition):
                self.assertEqual("inconclusive", self.check(body, 0x1000, claim, **condition)["status"])

    def test_table_base_definition_and_fixed_displacement(self):
        result = self.table(b"\x90", b"\x90")
        self.assertEqual(("pass", "from_owner_entry", False, "0x1040"), (result["status"], result["binding_scope"],
                         result["whole_program_unique"], result["target"]))
        evidence = result["original"]
        self.assertEqual(("0x1001", "rax", "0x2100", 24, "0x2118", "0x140001040"),
                         tuple(evidence[k] for k in ("definition_rva", "register", "table_rva", "displacement",
                                                     "slot_rva", "pointer_va")))

    def test_target_register_slot_and_definition_each_disagree(self):
        for options, code in [({"target": "0x1041"}, "witness_target"),
                              ({"witness": {"register": "rcx"}}, "witness_register"),
                              ({"witness": {"slot_rva": "0x2120"}}, "witness_slot"),
                              ({"witness": {"definition_rva": "0x1001"}}, "witness_definition")]:
            with self.subTest(options=options):
                result = self.table(**options)
                self.assertEqual(("fail", code), (result["status"], result["code"]))

    def test_bypassed_definition_and_partial_register_writes(self):
        # Conditional branch can enter the exact claimed call without executing LEA.
        self.assertEqual("inconclusive", self.table(before=b"\x75\x07")["status"])
        clobbered = self.table(between=b"\x30\xe4")  # XOR AH, AH changes RAX.
        self.assertEqual(("inconclusive", "0x1007"), (clobbered["status"], clobbered["original"]["clobber_rva"]))
        self.assertEqual("inconclusive", self.table(tail=b"\xeb\xfb\xc3")["status"])

    def test_guard_route_keeps_final_target_unresolved(self):
        body = rip(b"\x4c\x8b\x0d", 0x1000, SLOT) + b"\x41\xff\xd1\xc3"
        claim = {"target": "0x1040", "witness": {"kind": "guard_dispatch", "definition_rva": "0x1000",
                                                "register": "r9", "slot_rva": hex(SLOT)}}
        result = self.check(body, 0x1007, claim, guard=True)
        self.assertEqual(("inconclusive", "witness_guard_route", None), (result["status"], result["code"], result["target"]))
        self.assertEqual(["GuardCFDispatchFunctionPointer"], result["original"]["dispatch_route"]["load_config_fields"])
        self.assertEqual("pass", result["original"]["dispatch_route"]["status"])
        self.assertNotIn("dispatch_route", self.check(body, 0x1007, claim)["original"])
        guarded = self.table(guard=True)
        self.assertEqual(("inconclusive", None, "GuardCFDispatchFunctionPointer"), (guarded["status"], guarded["target"],
                         guarded["original"]["loader_slot"]))

    def test_guard_requires_independent_owner_and_supports_typed_unwind_handler(self):
        import pefile
        import iced_x86
        body = b"\x90" + rip(b"\x4c\x8b\x0d", 0x1001, SLOT) + b"\x41\xff\xd1\xc3"
        data = bytearray(fixture(body, guard=True))
        # Original owner has an unwind handler, as in the real guard-dispatch candidate.
        struct.pack_into("<I", data, 0x488, 0x20c0)
        data[0x4c0:0x4c8] = bytes.fromhex("11 00 00 00 40 10 00 00")
        pe = pefile.PE(data=bytes(data), fast_load=True)
        claim = {"site": "0x1008", "target": "0x1040", "witness": {"kind": "guard_dispatch", "register": "r9",
                                                                    "definition_rva": "0x1001", "slot_rva": hex(SLOT)}}
        good = verify(pe, 0x1000, 0x1000 + len(body), 0x1008, claim, iced_x86)
        self.assertEqual(("witness_guard_route", None), (good["code"], good["target"]))
        bad = verify(pe, 0x1001, 0x1000 + len(body), 0x1008, claim, iced_x86)
        self.assertEqual(("inconclusive", "witness_insufficient"), (bad["status"], bad["code"]))
        self.assertNotIn("dispatch_route", bad["original"])
        slots = _loader_slots(pe, {"Reserved": b"\x00\x00", "Note": "padding", "SecurityCookie": BASE + SLOT}, {})
        self.assertEqual("SecurityCookie", slots[SLOT])

    def test_unsupported_index_and_interior_instruction_offset(self):
        claim = {"target": "0x1040", "witness": {"kind": "readonly_slot", "slot_rva": hex(SLOT)}}
        self.assertEqual("inconclusive", self.check(b"\xff\x14\xc8\xc3", 0x1000, claim)["status"])
        body = rip(b"\xff\x15", 0x1000, SLOT) + b"\xc3"
        self.assertEqual("inconclusive", self.check(body, 0x1001, claim)["status"])


if __name__ == "__main__":
    unittest.main()
