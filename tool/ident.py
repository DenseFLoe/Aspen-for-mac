# -*- coding: utf-8 -*-
"""Identity comparison helpers: identifiers are compared as whole values, never as substrings.

RVA / token / ordinal / symbol identity must never use `in`, `startswith` or `endswith`:
  A848  vs A8480       (RVA)
  #2344 vs #23440      (import ordinal)
  2001080E vs 2001080E0 (metadata token / signature)

SEMANTICS (read before comparing anything by hand):
  same_ident(a, b)
    * compares the WHOLE value; no substring, prefix or suffix logic;
    * hex-ish values ("A848", "0xA848", 0xA848) are parsed as integers and compared numerically,
      so a leading "0x" is insignificant and "A848" != "A8480";
    * non-hex strings (symbols such as "mfc140.dll!#2344") are compared case-insensitively
      after stripping surrounding whitespace: "mfc140.dll!#2344" == "MFC140.DLL!#2344";
    * an int and a string are never equal unless both normalise to an int;
    * paths are NOT handled here: compare them as-is (case-sensitive) after os.path.normpath.

  DO NOT compare identifiers with ==, in, startswith or endswith anywhere else: call this module.
  tool/s113_substring_audit.py fails when a substring comparison on an identifier reappears.
"""
import re

_NUM = re.compile(r'^(?:0x)?[0-9A-Fa-f]+$')


def norm(value):
    """Normalise an identifier: ints become lowercase hex ints, strings lose surrounding space."""
    if isinstance(value, int):
        return value
    s = str(value).strip()
    if s.lower().startswith('0x') or _NUM.match(s):
        try:
            return int(s, 16)
        except ValueError:
            return s.lower()
    return s.lower()


def same_ident(a, b):
    """True only when the two identifiers are the same whole value."""
    if a is None or b is None:
        return False
    na, nb = norm(a), norm(b)
    if isinstance(na, int) != isinstance(nb, int):
        return False
    return na == nb


def hex_equal(a, b):
    """Compare two hex-ish identifiers numerically (accepts '0x..' and bare hex)."""
    try:
        return int(str(a), 16) == int(str(b), 16)
    except (TypeError, ValueError):
        return False
