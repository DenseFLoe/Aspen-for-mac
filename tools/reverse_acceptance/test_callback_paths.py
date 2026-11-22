"""Two-path tests using a synthetic PE with independent code, data and unwind addresses."""
import hashlib
import importlib.util
import json
from pathlib import Path
import struct
import tempfile
import unittest

if __package__:
    from . import callback_paths as callbacks
    from .test_native_sites import tiny_pe
else:
    import callback_paths as callbacks
    from test_native_sites import tiny_pe


def fixture():
    data = bytearray(tiny_pe()[0])

    def code(rva, body):
        body = bytes.fromhex(body)
        offset = 0x200 + rva - 0x1000
        data[offset:offset + len(body)] = body

    def relative(field, target):
        struct.pack_into("<i", data, 0x200 + field - 0x1000, target - (field + 4))

    # Conditional caller, slot getter, and section predicate. Their external
    # operands are linked to this fixture's own labels below.
    code(0x1000, """e8 00000000 488bd8 48833800 7424 488bc8 e8 00000000 84c0 7418
                    4c8bc6 ba02000000 498bce 488b03 4c8b0d 00000000 41ffd1 c3""")
    code(0x1040, "488d05 00000000 c3")
    code(0x1050, """4883ec18 4c8bc1 b84d5a0000 663905 00000000 7578
                    48630d 00000000 488d15 00000000 4803ca 813950450000 755f
                    b80b020000 66394118 7554 4c2bc2 0fb75114 4883c218 4803d1
                    0fb74106 488d0c80 4c8d0cca 48891424 493bd1 7418 8b4a0c
                    4c3bc1 720a 8b4208 03c1 4c3bc0 7208 4883c228 ebdf
                    33d2 4885d2 7504 32c0 eb14 837a2400 7d04 32c0 eb0a
                    b001 eb06 32c0 eb02 32c0 4883c418 c3""")
    # Second path from a caller with a known fourth argument to a helper that
    # saves it across an ABI call and uses the original dispatch slot.
    code(0x1100, """48895c2408 48896c2410 4889742418 57 4883ec20 498bf9 498bf0
                    8bda 488be9 e8 00000000 85c0 7516 83fb01 7511 4c8bc6
                    33d2 488bcd 488bc7 ff15 00000000 c3""")
    code(0x1150, """4055 4883ec30 488bea 488b01 8b10 48894c2428 89542420
                    4c8d0d 00000000 4c8b4570 8b5568 488b4d60 e8 00000000 c3""")
    code(0x1190, "c3 c3")
    for field, target in ((0x1001, 0x1040), (0x1012, 0x1050), (0x102b, 0x2150),
                          (0x1043, 0x2230), (0x105f, 0), (0x1068, 0x3c), (0x106f, 0),
                          (0x1120, 0x1191), (0x113a, 0x2150),
                          (0x116a, 0x1190), (0x117a, 0x1100)):
        relative(field, target)
    opt = 0x98
    second_section = opt + 240 + 40
    struct.pack_into("<I", data, second_section + 8, 0x300)
    struct.pack_into("<I", data, second_section + 36, 0xc0000040)
    functions = ((0x1000, 0x1033), (0x1050, 0x10e8), (0x1100, 0x113f),
                 (0x1150, 0x117f), (0x1190, 0x1191))
    struct.pack_into("<II", data, opt + 112 + 3 * 8, 0x2080, len(functions) * 12)
    for index, (start, end) in enumerate(functions):
        struct.pack_into("<III", data, 0x480 + index * 12, start, end, 0x21a0)
    data[0x5a0] = 1
    struct.pack_into("<II", data, opt + 112 + 10 * 8, 0x20c0, 0x94)
    struct.pack_into("<I", data, 0x4c0, 0x94)
    struct.pack_into("<Q", data, 0x4c0 + 120, 0x140002150)
    return data


@unittest.skipUnless(importlib.util.find_spec("iced_x86") and importlib.util.find_spec("pefile"),
                     "requires iced-x86 and pefile")
class CallbackPathsTests(unittest.TestCase):
    def setUp(self):
        import iced_x86
        import pefile
        work = tempfile.TemporaryDirectory()
        self.addCleanup(work.cleanup)
        self.root = Path(work.name)
        (self.root / "s13").mkdir()
        self.data = fixture()
        with pefile.PE(data=bytes(self.data)) as pe:
            image = callbacks.Image(self.data, pe, iced_x86)
            rows = []
            for addr in (0x1000, 0x1040, 0x100e, 0x1011, 0x10af, 0x10bc,
                         0x10cf, 0x10d3, 0x10d5, 0x1016, 0x1018, 0x102f):
                ins, raw = image.instruction(addr)
                rows.append({"rva": hex(addr), "bytes": raw.hex(), "instruction": image.fmt.format(ins)})
        self.optional = {"site": "0x102f", "slot": "0x2230", "normal_original_gate": "inactive", "evidence": rows,
            "section": {"section": ".idata", "start": "0x2000", "end_exclusive": "0x2300",
                        "characteristics": "0xc0000040", "raw_backed": False, "accepted_by_122f4": False},
            "readonly_control": {"section": ".text", "start": "0x1000", "end_exclusive": "0x1200",
                                 "characteristics": "0x60000020", "raw_backed": True, "accepted_by_122f4": True}}
        self.local = {"caller": "0x1179", "helper": "0x1100", "site": "0x1138",
                      "target": "0x1190", "dispatch_slot": "0x2150"}
        self.proof = {"original_sha256": hashlib.sha256(self.data).hexdigest(), "optional_callback": self.optional,
                      "local_callback": self.local, "matching_rel32_sites": {"0x1179": "0x1100"}}
        (self.root / callbacks.DISPOSITIONS).write_text(
            "owner_rva,site_rva,state\n0x1000,0x102f,resolved\n0x1100,0x1138,resolved\n", encoding="utf-8")
        (self.root / callbacks.EDGES).write_text(
            "owner_rva,site_rva,target_rva,basis\n0x1150,0x1179,0x1100,direct\n"
            "0x1100,0x1138,0x1190,named caller\n", encoding="utf-8")

    def check(self):
        (self.root / callbacks.EVIDENCE).write_text(json.dumps(self.proof), encoding="utf-8")
        return callbacks.check(bytes(self.data), self.root)

    def test_both_named_paths(self):
        check = self.check()
        self.assertEqual(check["status"], "pass", check["findings"])
        self.assertEqual(check["metrics"], {"section_gate": "0x2230", "one_callback": ["0x1179", "0x1190"]})
        self.assertIs(check["paths"]["one_callback"]["all_callers_exhausted"], False)

    def test_permission_bit_only_in_newly_bound_synthetic_original(self):
        baseline = bytes(self.data)
        self.data[0x98 + 240 + 40 + 39] ^= 0x80
        self.assertEqual(sum(a != b for a, b in zip(baseline, self.data)), 1)
        self.proof["original_sha256"] = hashlib.sha256(self.data).hexdigest()
        self.optional["section"].update(characteristics="0x40000040", accepted_by_122f4=True)
        result = self.check()
        self.assertEqual(set(result["metrics"]), {"one_callback"})
        self.assertIn("does not establish", result["findings"][0]["detail"])

    def test_declared_target_differs(self):
        self.local["target"] = "0x1000"
        check = self.check()
        self.assertEqual(set(check["metrics"]), {"section_gate"})
        self.assertIn("instruction differs", check["findings"][0]["detail"])

    def test_claimed_instruction_bytes_differ(self):
        self.optional["evidence"][8]["bytes"] = "00"
        check = self.check()
        self.assertEqual(set(check["metrics"]), {"one_callback"})
        self.assertEqual(check["findings"][0]["site_rva"], "0x102f")

    def test_undeclared_instruction_in_original_changes(self):
        self.data[0x200 + 0x115d - 0x1000] = 0x90
        self.proof["original_sha256"] = hashlib.sha256(self.data).hexdigest()
        self.assertEqual(set(self.check()["metrics"]), {"section_gate"})

    def test_missing_edge_refuses_local_claim(self):
        edges = self.root / callbacks.EDGES
        edges.write_text(edges.read_text(encoding="utf-8").replace("0x1190", "0x1191"), encoding="utf-8")
        self.assertEqual(set(self.check()["metrics"]), {"section_gate"})

    def test_wrong_original_hash(self):
        self.proof["original_sha256"] = "0" * 64
        check = self.check()
        self.assertEqual((check["status"], check["metrics"]), ("fail", {}))


if __name__ == "__main__":
    unittest.main()
