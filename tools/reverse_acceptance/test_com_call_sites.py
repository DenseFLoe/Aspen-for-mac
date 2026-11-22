"""Controls for original-backed COM receiver, member and byte-displacement checks."""
import csv
import importlib.util
from pathlib import Path
import struct
from tempfile import TemporaryDirectory
import unittest

if __package__:
    from . import com_call_sites as com
    from .test_native_sites import tiny_pe
    from .test_target_witness import rip
else:
    import com_call_sites as com
    from test_native_sites import tiny_pe
    from test_target_witness import rip


def fixture(owner, factory, *, clobber=False, bypass=False, wrong_iid=False, bad_return=False):
    raw = bytearray(tiny_pe()[0])
    base = 0x171200000
    struct.pack_into("<Q", raw, 0x98 + 24, base)
    raw[0x470:0x47a] = b"ole32.dll\0"
    for slot in (0x440, 0x450):
        struct.pack_into("<Q", raw, slot, 0x2120)
    symbol = b"\0\0CoCreateInstance\0"
    raw[0x520:0x520 + len(symbol)] = symbol
    raw[0x550:0x560] = bytes(16) if wrong_iid else com.IID

    body = bytearray.fromhex("48 83 ec 38")
    body += rip(b"\x4c\x8d\x0d", factory + len(body), 0x2150)  # IID in r9
    body += bytes.fromhex("48 8d 44 24 30 48 89 44 24 20")    # fifth arg points to [rsp+30]
    body += rip(b"\xff\x15", factory + len(body), 0x2050)
    body += bytes.fromhex("48 8b 44 24 28" if bad_return else "48 8b 44 24 30")
    body += bytes.fromhex("48 83 c4 38 c3")
    caller = bytearray.fromhex("48 83 ec 28")
    via = owner + len(caller)
    caller += rip(b"\xe8", via, factory)
    caller += bytes.fromhex("48 89 c1")
    caller += bytes.fromhex("74 03") if bypass else b""
    caller += bytes.fromhex("48 8b 11")  # RDX from [RCX]
    if clobber:
        caller += bytes.fromhex("48 89 e9")  # Same vtable register, unrelated receiver
    site = owner + len(caller)
    caller += bytes.fromhex("ff 52 18 48 83 c4 28 c3")
    for start, data in [(owner, caller), (factory, body)]:
        offset = 0x200 + start - 0x1000
        raw[offset:offset + len(data)] = data
    struct.pack_into("<II", raw, 0x98 + 112 + 3*8, 0x2080, 24)
    struct.pack_into("<IIIIII", raw, 0x480, owner, owner+len(caller), 0x20a0, factory, factory+len(body), 0x20a4)
    raw[0x4a0:0x4a8] = bytes.fromhex("01 00 00 00 01 00 00 00")
    return bytes(raw), via, site


@unittest.skipUnless(importlib.util.find_spec("pefile") and importlib.util.find_spec("iced_x86"),
                     "requires pefile and iced-x86")
class ComEvidenceTest(unittest.TestCase):
    def audit(self, *, owner=0x1010, factory=0x10a0, witness=None, **options):
        data, via, site = fixture(owner, factory, **options)
        row = dict(site=hex(site), owner=hex(owner), factory_call=hex(via), factory=hex(factory),
                   disp="0x18", member="IDispatch::GetTypeInfoCount", target_module="runtime")
        row.update(witness or {})
        with TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "code").mkdir()
            (root / com.LISTING).write_text(f"; FUNC {owner:08x}\n{site:08x}  FF 52 18  CALL [rdx+18h]\n")
            (root / "calls.csv").write_text(f"caller,callee,listing\n{owner:#x},indirect@{site:#x},code/native.asm#L2-L2\n")
            with (root / com.TABLE).open("w", newline="") as out:
                writer = csv.DictWriter(out, fieldnames=row.keys())
                writer.writeheader()
                writer.writerow(row)
            return com.check(data, root)

    def test_unseen_rvas_and_member_slot(self):
        for owner, factory in [(0x1010, 0x10a0), (0x1030, 0x1110)]:
            result = self.audit(owner=owner, factory=factory)
            self.assertEqual(result["status"], "pass", result)
            self.assertEqual(result["metrics"]["concrete_targets_verified"], 0)

    def test_independent_one_field_controls(self):
        for field, value, status, code, members, disps in [
            ("member", "IDispatch::Invoke", "fail", "com_member_mismatch", 0, 1),
            ("disp", "0x20", "fail", "com_displacement_mismatch", 1, 0),
            ("disp", "", "inconclusive", "com_displacement_missing", 1, 0),
            ("target_module", "supplier.dll", "inconclusive", "com_runtime_module_unverified", 1, 1),
            ("factory", "0x1010", "fail", "com_factory_call_mismatch", 0, 1),
        ]:
            with self.subTest(field=field, value=value):
                result = self.audit(witness={field: value})
                self.assertEqual(result["status"], status, result)
                self.assertEqual([f["code"] for f in result["findings"]], [code])
                self.assertEqual(result["metrics"]["member_matches"], members)
                self.assertEqual(result["metrics"]["displacement_matches"], disps)

    def test_displacement_without_receiver_or_factory_proof(self):
        for key in ("bypass", "clobber", "wrong_iid", "bad_return"):
            with self.subTest(key=key):
                result = self.audit(**{key: True})
                self.assertEqual(result["status"], "inconclusive", result)
                self.assertEqual(result["metrics"]["member_matches"], 0)
                self.assertEqual(result["metrics"]["displacement_matches"], 1)
