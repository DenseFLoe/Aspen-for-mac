"""Tests for module-level procedure binding and incomplete cache evidence."""
from collections import Counter
import unittest

if __package__:
    from . import office_pcode as cache
else:
    import office_pcode as cache


class CacheTests(unittest.TestCase):
    def test_same_number_of_different_procedures_is_not_a_match(self):
        source = {"vba/first": Counter({("function", "ready"): 1}),
                  "vba/second": Counter({("sub", "reset"): 1})}
        clean = ("VBA/First - 90 bytes\n\tFuncDefn (Public Function Ready())\n"
                 "VBA/Second - 11 bytes\n\tFuncDefn (Sub Reset())\n")
        self.assertEqual(cache.compare_dump(source, clean)["matched_name_and_kind"], 2)
        changed = clean.replace("Function Ready", "Function Reset")
        result = cache.compare_dump(source, changed)
        self.assertEqual(result["matched_name_and_kind"], 1)
        self.assertEqual(result["modules"][0]["decoded_declarations"], 1)

    def test_opaque_and_unbound_declarations_do_not_count(self):
        dump = ("\tFuncDefn (Function Detached())\n"
                "VBA/Control - 12 bytes\n\tFuncDefn (Function id_FFFE())\n"
                "\tFuncDefn (Property Let Example(ByVal id_FFFF As Long))\n")
        result = cache.compare_dump({"vba/control": Counter({("property let", "example"): 1})}, dump)
        self.assertEqual(result["matched_name_and_kind"], 1)
        self.assertEqual(result["unclassified_cache_declarations"], 2)
        self.assertEqual(result["opaque_cache_markers"], {"id_FFFE": 1, "id_FFFF": 1})

    def test_original_without_cache_proof_stays_pending(self):
        result = cache.check(b"PK\x00", ".")
        self.assertEqual(result["status"], "inconclusive")
        self.assertIn({"code": "vba_cache_semantics_unverified"}, result["findings"])
