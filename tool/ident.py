# -*- coding: utf-8 -*-
"""Identity comparison helpers: identifiers are compared as whole values, never as substrings.

RVA / token / ordinal / symbol identity must never use `in`, `startswith` or `endswith`:
  A848  vs A8480       (RVA)
  #2344 vs #23440      (import ordinal)
  2001080E vs 2001080E0 (metadata token / signature)
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
