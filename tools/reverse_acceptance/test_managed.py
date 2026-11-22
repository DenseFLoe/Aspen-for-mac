"""Focused controls for MethodDef identity, CIL, EH, #US and declaration-only files."""
import os
import shutil
import struct
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

try:
    from .managed import check
except ImportError:
    sys.path.insert(0, str(Path(__file__).resolve().parent))
    from managed import check


CS = """
public static class Fixture {
    public static int Read(int x) { return x + 185753183; }
    public static int Read(long x) { return (int)x + 3; }
    public static string Label() { return "CLR coverage fixture"; }
    public static int Guard(int x) {
        try { return 1 / x; } catch (System.DivideByZeroException) { return -1; }
    }
}
"""
BUILD = """
$ErrorActionPreference='Stop'
Add-Type -TypeDefinition $env:A_TEST_CS -OutputAssembly $env:A_TEST_OUT -CompilerOptions '/optimize+'
"""
# Obtain the Guard method address with the platform reader. Locate its
# exception clause from the public fat-header and section layout in ECMA-335.
GUARD = """
$ErrorActionPreference='Stop'
$f=[IO.File]::OpenRead($env:A_TEST_OUT)
$pe=[System.Reflection.PortableExecutable.PEReader]::new($f)
$r=[System.Reflection.Metadata.PEReaderExtensions]::GetMetadataReader($pe)
foreach($h in $r.MethodDefinitions){
  $m=$r.GetMethodDefinition($h)
  if ($r.GetString($m.Name) -eq 'Guard') {
    $v=$m.RelativeVirtualAddress
    $s=$pe.PEHeaders.SectionHeaders | Where-Object { $v -ge $_.VirtualAddress -and $v -lt $_.VirtualAddress+$_.SizeOfRawData }
    $s.PointerToRawData+$v-$s.VirtualAddress
  }
}
$pe.Dispose()
$f.Dispose()
"""


@unittest.skipUnless(shutil.which("pwsh"), "requires PowerShell 7")
class ManagedComparisonTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.tmp = tempfile.TemporaryDirectory()
        cls.root = Path(cls.tmp.name)
        cls.binary = cls.compile("full", CS)
        cls.data = cls.binary.read_bytes()

    @classmethod
    def tearDownClass(cls):
        cls.tmp.cleanup()

    @classmethod
    def compile(cls, name, source):
        path = cls.root / (name + ".dll")
        subprocess.run(["pwsh", "-NoProfile", "-NonInteractive", "-Command", BUILD],
                       check=True, capture_output=True,
                       env={**os.environ, "A_TEST_CS": source, "A_TEST_OUT": str(path)})
        return path

    def mutated(self, name, data):
        path = self.root / (name + ".dll")
        path.write_bytes(data)
        return check(self.data, path)

    def test_positive(self):
        result = check(self.data, self.binary)
        self.assertEqual(result["status"], "pass", result["findings"])
        self.assertEqual(result["metrics"]["original_methods"], 4)
        self.assertEqual(result["metrics"]["original_eh_clauses"], 1)

    def test_deleted_overload(self):
        other = self.compile("gone", CS.replace("public static int Read(long x)", "public static int Other(long x)"))
        result = check(self.data, other)
        self.assertEqual(result["status"], "fail", result["findings"])
        self.assertIn("named_method_count_changed", [f["code"] for f in result["findings"]])

    def test_changed_il_same_metadata(self):
        marker = struct.pack("<I",185753183)
        self.assertEqual(self.data.count(marker), 1)
        result = self.mutated("il-change", self.data.replace(marker,struct.pack("<I",185753184)))
        self.assertTrue(result["metrics"]["normalized_metadata_equal"])
        self.assertNotEqual(result["status"], "pass")
        self.assertTrue(any("il_sha256" in f.get("changed",{}) for f in result["findings"]))

    def test_user_string_changed_with_identical_il(self):
        a = "CLR coverage fixture".encode("utf-16le")
        b = "CLR coverage fixturX".encode("utf-16le")
        self.assertEqual(self.data.count(a), 1)
        result = self.mutated("string-change", self.data.replace(a,b))
        self.assertFalse(result["metrics"]["normalized_metadata_equal"])
        self.assertNotEqual(result["status"], "pass")
        self.assertFalse(any("il_sha256" in f.get("changed",{}) for f in result["findings"]))

    def test_exception_clause_changed_only(self):
        out = subprocess.check_output(["pwsh", "-NoProfile", "-NonInteractive", "-Command", GUARD],
                                      env={**os.environ, "A_TEST_OUT": str(self.binary)})
        header = int(out.strip())
        code_start = header + 4 * (self.data[header+1] >> 4)
        length = struct.unpack_from("<I", self.data, header+4)[0]
        eh = (code_start + length + 3) & ~3
        self.assertEqual(self.data[eh] & 0x3f, 1)
        # First clause's flags follow its section header, in either EH format.
        mod = bytearray(self.data)
        self.assertEqual(mod[eh+4], 0)  # Catch
        mod[eh+4] = 2  # Finally
        result = self.mutated("eh-change",mod)
        self.assertTrue(result["metrics"]["normalized_metadata_equal"])
        self.assertTrue(any("eh_sha256" in f.get("changed",{}) for f in result["findings"]))
        self.assertFalse(any("il_sha256" in f.get("changed",{}) for f in result["findings"]))
        self.assertNotEqual(result["status"], "pass")

    def test_only_declaration(self):
        path = self.compile("empty", "public interface IProbe { int Read(); }")
        result = check(path.read_bytes(),path)
        self.assertEqual(result["status"], "inconclusive")
        self.assertIn("no_verifiable_cil_bodies", [f["code"] for f in result["findings"]])


if __name__ == "__main__":
    unittest.main()

