"""Controls for checking historical listing coverage against original bytes."""
import importlib.util
import unittest
from unittest.mock import Mock

if __package__:
    from . import historical_listing as history
else:
    import historical_listing as history


@unittest.skipUnless(importlib.util.find_spec("iced_x86"), "requires iced-x86")
class HistoricCoverageTest(unittest.TestCase):
    def audit(self, rows, current):
        import iced_x86 as x86

        original = bytes.fromhex("48 89 c1 90 cc c3")
        pe = Mock(get_data=lambda address, size: original[address:address + size])

        def decode(site):
            return x86.Decoder(64, original[site:], ip=site).decode()

        notes = Mock()
        return history.compare(rows, pe, x86, decode, set(current), notes), notes

    def test_original_instruction_missing_while_nop_and_int3_stay_separate(self):
        rows = b"rva,bytes\n0,4889c1\n3,90\n4,cc\n5,c3\n"
        initial, notes = self.audit(rows, [5])
        self.assertEqual(initial["status"], "fail")
        self.assertEqual([r["rva"] for r in initial["missing_nonpadding"]], ["0x0"])
        self.assertEqual([r["rva"] for r in initial["missing_nop_or_int3"]], ["0x3", "0x4"])
        self.assertEqual(notes.call_args.args[1], "historical_instruction_missing")
        repaired, notes = self.audit(rows, [0, 5])
        self.assertEqual(repaired["status"], "pass")
        notes.assert_not_called()

    def test_undecodable_reference_does_not_create_a_proof(self):
        for rows, code in [
            (b"rva,bytes\n0,4889c0\n", "historical_instruction_identity"),
            (b"rva,bytes\n0,4889c1\n2,c1\n", "historical_instruction_baseline"),
        ]:
            with self.subTest(code=code):
                result, notes = self.audit(rows, [])
                self.assertEqual(result["status"], "inconclusive")
                self.assertEqual(result["verified_baseline_instructions"], 0)
                self.assertEqual(notes.call_args.args[1], code)
