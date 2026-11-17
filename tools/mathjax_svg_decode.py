#!/usr/bin/env python3
"""Decode MathJax v2 SVG equations (as shipped in Aspen V15 HtmlHelp) to plain text.

Aspen's help renders every equation as an SVG built from MathJax glyph paths:
  <defs><path id="MJMATHI-63" .../></defs>
  <g transform="matrix(1 0 0 -1 0 0)">
    <use x=".." y=".." xlink:href="#MJMATHI-63"/>
    <g transform="translate(x y)"> ... fractions / scripts / groups ... </g>
  </g>

The glyph id suffix is the Unicode code point in hex; layout is expressed with
translate/scale transforms and <rect> fraction bars. This module reconstructs a
linear plain-text form, e.g.  P = (R*T)/(V_m - b) - a/(V_m*(V_m + b))

Conventions of the output text:
  fraction        (num)/(den)
  subscript       x_i  / x_{ij}
  superscript     x^2  / x^{ci}
  sqrt            sqrt(x)
  n-th root       root(n, x)
  sum/prod/int    sum_{i=1}^{N} / prod / int  (Unicode big operators kept)
  accents         hat(x) bar(x) vec(x) dot(x) tilde(x)
  Greek letters   kept as Unicode characters
  minus U+2212    '-'   middle dot U+22C5 / U+00B7 -> '*'

Only the Python standard library is used.
"""
from __future__ import annotations

import math
import re
import xml.etree.ElementTree as ET

SVG_NS = "http://www.w3.org/2000/svg"
XLINK_NS = "http://www.w3.org/1999/xlink"

# ---------------------------------------------------------------- glyph map

# Code points that should be rendered as words / ASCII operators.
_SPECIAL = {
    0x2212: "-",      # minus
    0x22C5: "*",      # dot operator
    0x00B7: "*",      # middle dot
    0x2219: "*",      # bullet operator
    0x00D7: "*",      # multiplication sign
    0x2061: "",       # function application
    0x2062: "*",      # invisible times -> explicit multiplication
    0x2063: "",       # invisible separator
    0x2064: "",       # invisible plus
    0x00A0: " ",
    0x2002: " ", 0x2003: " ", 0x2004: " ", 0x2005: " ",
    0x2009: " ", 0x200A: " ", 0x200B: "",
    0x2260: "!=", 0x2264: "<=", 0x2265: ">=",
    0x2248: "~=", 0x2261: "==", 0x221D: "proportional_to",
    0x2192: "->", 0x2190: "<-", 0x2194: "<->",
    0x21D2: "=>", 0x21D4: "<=>",
    0x221E: "inf",
    0x2202: "d",      # partial differential -> d (context kept in text)
    0x2206: "Delta",  # increment
    0x2207: "nabla",
    0x2211: "sum",    # n-ary summation
    0x220F: "prod",   # n-ary product
    0x222B: "int",    # integral
    0x222C: "double_int", 0x222D: "triple_int",
    0x222E: "oint",
    0x22C3: "union", 0x22C2: "intersect",
    0x2208: "in", 0x2209: "not_in",
    0x2282: "subset", 0x2286: "subset_eq",
    0x22A5: "perp", 0x2225: "parallel",
    0x2220: "angle",
    0x2032: "'", 0x2033: "''", 0x2034: "'''",
    0x2026: "...", 0x22EF: "...", 0x22EE: ":", 0x22F1: "...",
    0x27E8: "<", 0x27E9: ">",   # angle brackets
    0x2016: "||",
    0x221A: "sqrt",   # radical (handled structurally too)
    0x221B: "cbrt", 0x221C: "fourthroot",
    0x2103: "degC", 0x2109: "degF",
    0x212B: "Angstrom",
    0x2205: "empty_set",
    0x2234: "therefore", 0x2235: "because",
    0x2243: "~=", 0x2245: "~=",
    0x226A: "<<", 0x226B: ">>",
    0x2295: "(+)", 0x2297: "(x)",
    0x2218: "o",     # ring operator (composition)
    0x22C0: "AND", 0x22C1: "OR",
    0x2227: "and", 0x2228: "or", 0x00AC: "not",
    0x2200: "for_all", 0x2203: "exists",
    0x2237: "::", 0x2236: ":",
    0x2213: "-/+",
    0x2214: "+.",
    0x22C4: "*",     # diamond operator
    0x22A0: "boxtimes", 0x22A1: "boxplus",
    0x2223: "|", 0x2224: "not_divides",
    0x2241: "!~=", 0x2249: "!~=",
    0x2262: "!=",
    0x2284: "not_subset",
    0x2191: "^", 0x2193: "v",
    0x27F6: "->", 0x27F5: "<-",
    0x2250: "~=", 0x2252: "~=", 0x2253: "~=",
    0x225D: "=def",
    0x22B2: "tri_left", 0x22B3: "tri_right",
    0x2228: "or",
    0x2020: "dagger", 0x2021: "ddagger",
    0x2113: "ell",
    0x210F: "hbar",
    0x2111: "Im", 0x211C: "Re",
    0x2118: "wp",
    0x2135: "aleph",
    0x220E: "QED",
    0x25B3: "triangle",
    0x2299: "(.)",
    0x2217: "*",
    0x229B: "(o)",
    0x2298: "(/)",
    0x2296: "(-)",
    0x229D: "(-)",
    0x22A2: "turnstile", 0x22A3: "dashv",
    0x22A8: "models",
    0x22C6: "*",
    0x22D2: "double_union", 0x22D3: "double_intersect",
    0x22D0: "subset_double", 0x22D1: "supset_double",
    0x227A: "prec", 0x227B: "succ",
    0x227C: "preceq", 0x227D: "succeq",
    0x2283: "supset", 0x2287: "supset_eq",
    0x228F: "sqsubset", 0x2290: "sqsupset",
    0x2291: "sqsubset_eq", 0x2292: "sqsupset_eq",
    0x2293: "sqcap", 0x2294: "sqcup",
    0x229A: "(o)", 0x229C: "(=)",
    0x229E: "[+]", 0x229F: "[-]", 0x22A0: "[x]", 0x22A1: "[.]",
    0x2226: "not_parallel",
    0x223C: "~", 0x223D: "~",
    0x2242: "-~", 0x2243: "~-",
    0x224A: "~=",
    0x224E: "~=", 0x224F: "~=",
    0x2251: "~=", 0x2254: ":=", 0x2255: "=:",
    0x2257: "(=)", 0x2259: "(^=)",
    0x2263: "==",
    0x2266: "<=", 0x2267: ">=",
    0x2268: "<!=", 0x2269: ">!=",
    0x226C: "between",
    0x226E: "!<", 0x226F: "!>",
    0x2270: "!<=", 0x2271: "!>=",
    0x2272: "<~", 0x2273: ">~",
    0x2276: "<~", 0x2277: ">~",
    0x2278: "!<~", 0x2279: "!>~",
    0x227E: "<~", 0x227F: ">~",
    0x2280: "!prec", 0x2281: "!succ",
    0x2285: "not_supset",
    0x2288: "!sqsubset_eq", 0x2289: "!sqsupset_eq",
    0x228A: "subset_neq", 0x228B: "supset_neq",
    0x228E: "multiset_union",
    0x228F: "sqsubset", 0x2290: "sqsupset",
    0x22B4: "tri_left_eq", 0x22B5: "tri_right_eq",
    0x22B6: "orig_of", 0x22B7: "image_of",
    0x22B8: "multimap",
    0x22BA: "intercal",
    0x22BB: "xor", 0x22BC: "nand", 0x22BD: "nor",
    0x22C7: "division_times",
    0x22C8: "bowtie",
    0x22C9: "left_times", 0x22CA: "right_times",
    0x22CB: "left_semidirect", 0x22CC: "right_semidirect",
    0x22CD: "~=:",
    0x22CE: "curly_or", 0x22CF: "curly_and",
    0x22D4: "pitchfork",
    0x22D5: "equal_parallel",
    0x22D6: "less_than_dot", 0x22D7: "greater_than_dot",
    0x22D8: "very_less", 0x22D9: "very_greater",
    0x22DA: "less_equal_greater", 0x22DB: "greater_equal_less",
    0x22DC: "equal_less", 0x22DD: "equal_greater",
    0x22DE: "equal_precedes", 0x22DF: "equal_succeeds",
    0x22E0: "!preceq", 0x22E1: "!succeq",
    0x22E2: "!sqsubset_eq", 0x22E3: "!sqsupset_eq",
    0x22E4: "sqsubset_neq", 0x22E5: "sqsupset_neq",
    0x22E6: "less_not_sim", 0x22E7: "greater_not_sim",
    0x22E8: "less_not_approx", 0x22E9: "greater_not_approx",
    0x22EA: "!tri_left", 0x22EB: "!tri_right",
    0x22EC: "!tri_left_eq", 0x22ED: "!tri_right_eq",
    0x22EE: "vdots", 0x22EF: "cdots", 0x22F0: "adots", 0x22F1: "ddots",
    0x2308: "ceil_left", 0x2309: "ceil_right",
    0x230A: "floor_left", 0x230B: "floor_right",
    0x2322: "frown", 0x2323: "smile",
    0x23DE: "overbrace", 0x23DF: "underbrace",
    0x23B4: "overbracket", 0x23B5: "underbracket",
    0x23DC: "overparen", 0x23DD: "underparen",
    0x23E0: "overbracket", 0x23E1: "underbracket",
    0x27F7: "<->", 0x27F8: "<=", 0x27F9: "=>",
    0x27FA: "<=>",
    0x27FC: "|->",
    0x2906: "|=>", 0x2907: "=>|",
    0x21A6: "|->",
    0x21A9: "hook_left", 0x21AA: "hook_right",
    0x21BC: "harpoon_left", 0x21BD: "harpoon_down_left",
    0x21C0: "harpoon_right", 0x21C1: "harpoon_down_right",
    0x21C4: "right_left_arrows", 0x21C6: "left_right_arrows",
    0x21CB: "left_right_harpoons", 0x21CC: "right_left_harpoons",
    0x2195: "up_down_arrow",
    0x2196: "nw_arrow", 0x2197: "ne_arrow", 0x2198: "se_arrow", 0x2199: "sw_arrow",
    0x219A: "!->", 0x219B: "!<-",
    0x219E: "twohead_left", 0x21A0: "twohead_right",
    0x21A2: "leftarrow_tail", 0x21A3: "rightarrow_tail",
    0x21A4: "|<-", 0x21A5: "|->",
    0x21A7: "down_arrow_bar",
    0x21AB: "loop_left", 0x21AC: "loop_right",
    0x21AD: "left_right_wave",
    0x21AE: "!<->",
    0x21AF: "down_zigzag",
    0x21B0: "up_arrow_tip_left", 0x21B1: "up_arrow_tip_right",
    0x21B2: "down_arrow_tip_left", 0x21B3: "down_arrow_tip_right",
    0x21B4: "right_arrow_corner", 0x21B5: "down_arrow_corner",
    0x21B6: "curve_arrow_left", 0x21B7: "curve_arrow_right",
    0x21B8: "bar_left_arrow", 0x21B9: "left_right_bar_arrows",
    0x21BA: "circle_arrow_left", 0x21BB: "circle_arrow_right",
    0x21BE: "up_harpoon_right", 0x21BF: "up_harpoon_left",
    0x21C2: "down_harpoon_right", 0x21C3: "down_harpoon_left",
    0x21C5: "up_down_arrows",
    0x21C7: "left_pair_arrows", 0x21C8: "up_pair_arrows",
    0x21C9: "right_pair_arrows", 0x21CA: "down_pair_arrows",
    0x21CD: "!<=", 0x21CE: "!<=>", 0x21CF: "!=>",
    0x21D0: "<=", 0x21D1: "up_double_arrow", 0x21D3: "down_double_arrow",
    0x21D5: "up_down_double_arrow",
    0x21D6: "nw_double_arrow", 0x21D7: "ne_double_arrow",
    0x21D8: "se_double_arrow", 0x21D9: "sw_double_arrow",
    0x21DA: "left_triple_arrow", 0x21DB: "right_triple_arrow",
    0x21DC: "left_squiggle", 0x21DD: "right_squiggle",
    0x21DE: "up_dash_arrow", 0x21DF: "down_dash_arrow",
    0x21E0: "left_dash_arrow", 0x21E1: "right_dash_arrow",
    0x21E2: "right_dash_arrow", 0x21E3: "down_dash_arrow",
    0x21E4: "left_bar_arrow", 0x21E5: "right_bar_arrow",
    0x21E6: "left_white_arrow", 0x21E7: "up_white_arrow",
    0x21E8: "right_white_arrow", 0x21E9: "down_white_arrow",
    0x21EA: "up_white_arrow_bar",
    0x21F0: "right_white_arrow_wall",
    0x21F1: "nw_corner_arrow", 0x21F2: "se_corner_arrow",
    0x21F3: "up_down_white_arrow",
    0x21F4: "right_arrow_small_circle",
    0x21F5: "down_up_arrows",
    0x21F6: "three_right_arrows",
    0x21F7: "left_arrow_stroke", 0x21F8: "right_arrow_stroke",
    0x21F9: "left_right_arrow_stroke",
    0x21FA: "left_arrow_double_stroke", 0x21FB: "right_arrow_double_stroke",
    0x21FC: "left_right_arrow_double_stroke",
    0x21FD: "left_open_arrow", 0x21FE: "right_open_arrow",
    0x21FF: "left_right_open_arrow",
    # tall-delimiter pieces (MathJax MJSZ4 builds big brackets from these)
    0x239B: "(", 0x239C: "(", 0x239D: "(",
    0x239E: ")", 0x239F: ")", 0x23A0: ")",
    0x23A1: "[", 0x23A2: "[", 0x23A3: "[",
    0x23A4: "]", 0x23A5: "]", 0x23A6: "]",
    0x23A7: "{", 0x23A8: "{", 0x23A9: "{",
    0x23AB: "}", 0x23AC: "}", 0x23AD: "}",
    0x23AA: "",      # curly-bracket vertical extension (redundant)
    0x23B7: "sqrt",  # radical bottom hook
    0xE000: "", 0xE001: "",  # MathJax private-use radical/brace extensions
}

# Accent code points -> wrapper name.
_ACCENTS = {
    0x0302: "hat", 0x0303: "tilde", 0x0304: "bar", 0x0305: "bar",
    0x0307: "dot", 0x0308: "ddot", 0x030A: "ring", 0x030C: "check",
    0x0306: "breve", 0x030B: "double_acute",
    0x20D7: "vec", 0x20D6: "vec", 0x20D1: "vec", 0x20D0: "vec",
    0x20DB: "dddot", 0x20DC: "ddddot",
    0x02C6: "hat", 0x02DC: "tilde", 0x00AF: "bar", 0x02D9: "dot",
    0x00A8: "ddot", 0x02DA: "ring", 0x02C7: "check", 0x02D8: "breve",
    0x2192: "vec",
    0x23DE: "overbrace", 0x23DF: "underbrace",
    0x23B4: "overbracket", 0x23B5: "underbracket",
    0x23DC: "overparen", 0x23DD: "underparen",
}

_GLYPH_CACHE: dict[str, tuple[str, str]] = {}


def glyph_char(glyph_id: str) -> str:
    """Map a MathJax glyph id such as MJMATHI-3B1 to its character."""
    return glyph_info(glyph_id)[0]


def glyph_info(glyph_id: str) -> tuple[str, str]:
    """Return (character, font_class) for a MathJax glyph id.

    font_class: 'it' italic variable, 'rm' roman text/digits, 'op' other.
    """
    if glyph_id in _GLYPH_CACHE:
        return _GLYPH_CACHE[glyph_id]
    m = re.match(r"^([A-Z0-9]+)-([0-9A-Fa-f]+)$", glyph_id)
    if not m:
        _GLYPH_CACHE[glyph_id] = ("?", "op")
        return ("?", "op")
    prefix, cp_hex = m.group(1), m.group(2)
    cp = int(cp_hex, 16)
    ch = _SPECIAL.get(cp)
    if ch is None:
        try:
            ch = chr(cp)
        except ValueError:
            ch = "?"
    if prefix in ("MJMATHI", "MJMATHBF", "MJMATHBIT"):
        font = "it"
    elif prefix in ("MJMAIN", "MJSS", "MJTT", "MJSANS", "MJTYPE"):
        font = "rm"
    else:
        font = "op"
    # digits and punctuation are roman regardless of font variant
    if ch.isdigit() or ch in ".,;:()[]|/+-*=<>!'\"":
        font = "rm"
    _GLYPH_CACHE[glyph_id] = (ch, font)
    return (ch, font)


def is_accent_char(ch: str) -> str | None:
    if len(ch) != 1:
        return None
    return _ACCENTS.get(ord(ch))


# ------------------------------------------------------------- transforms

def parse_transform(s: str | None):
    """Return affine (a,b,c,d,e,f) for an SVG transform list."""
    a, b, c, d, e, f = 1.0, 0.0, 0.0, 1.0, 0.0, 0.0
    if not s:
        return (a, b, c, d, e, f)
    for name, args in re.findall(r"(matrix|translate|scale|rotate|skewX|skewY)\s*\(([^)]*)\)", s):
        v = [float(x) for x in re.split(r"[\s,]+", args.strip()) if x]
        if name == "translate":
            tx = v[0] if v else 0.0
            ty = v[1] if len(v) > 1 else 0.0
            m = (1, 0, 0, 1, tx, ty)
        elif name == "scale":
            sx = v[0] if v else 1.0
            sy = v[1] if len(v) > 1 else sx
            m = (sx, 0, 0, sy, 0, 0)
        elif name == "matrix":
            m = tuple(v)
        elif name == "rotate":
            ang = math.radians(v[0])
            co, si = math.cos(ang), math.sin(ang)
            if len(v) == 3:
                cx, cy = v[1], v[2]
                m = (co, si, -si, co, cx - co * cx + si * cy, cy - si * cx - co * cy)
            else:
                m = (co, si, -si, co, 0, 0)
        else:
            m = (1, 0, 0, 1, 0, 0)
        a, b, c, d, e, f = mul(m, (a, b, c, d, e, f))
    return (a, b, c, d, e, f)


def mul(m1, m2):
    a1, b1, c1, d1, e1, f1 = m1
    a2, b2, c2, d2, e2, f2 = m2
    return (
        a1 * a2 + c1 * b2,
        b1 * a2 + d1 * b2,
        a1 * c2 + c1 * d2,
        b1 * c2 + d1 * d2,
        a1 * e2 + c1 * f2 + e1,
        b1 * e2 + d1 * f2 + f1,
    )


def apply(m, x, y):
    a, b, c, d, e, f = m
    return (a * x + c * y + e, b * x + d * y + f)


def scale_of(m) -> float:
    a, b, c, d, _, _ = m
    return math.sqrt(abs(a * d - b * c))


IDENT = (1, 0, 0, 1, 0, 0)
FLIP = (1, 0, 0, -1, 0, 0)


# ----------------------------------------------------------------- items

class Item:
    """A positioned piece of an equation: glyph, group, or rule.

    x/y are relative to the containing group's origin, in math coordinates
    (+y up) after normalization.
    """

    __slots__ = ("kind", "x", "y", "scale", "text", "font", "children", "elem", "w")

    def __init__(self, kind, x, y, scale, text="", font="op", children=None, elem=None, w=0.0):
        self.kind = kind        # 'char' | 'group' | 'rect'
        self.x = x
        self.y = y
        self.scale = scale
        self.text = text        # for char
        self.font = font        # 'it' | 'rm' | 'op' | 'grp'
        self.children = children or []
        self.elem = elem
        self.w = w

    def __repr__(self):
        return f"Item({self.kind},{self.x:.0f},{self.y:.0f},{self.text!r})"


def collect(elem, parent_m, out: list):
    """Flatten one level of <g> children into positioned items.

    Children of a nested <g> get coordinates relative to that group's origin,
    so recursive rendering sees a local baseline at y=0.
    """
    for child in elem:
        tag = child.tag.split("}")[-1]
        m = mul(parent_m, parse_transform(child.get("transform")))
        if tag == "use":
            href = child.get(f"{{{XLINK_NS}}}href") or child.get("href") or ""
            ch, font = glyph_info(href.lstrip("#"))
            x = float(child.get("x", 0))
            y = float(child.get("y", 0))
            px, py = apply(m, x, y)
            out.append(Item("char", px, py, scale_of(m), text=ch, font=font, elem=child))
        elif tag == "g":
            px, py = apply(m, 0, 0)
            kids: list[Item] = []
            collect(child, m, kids)
            for k in kids:
                k.x -= px
                k.y -= py
            out.append(Item("group", px, py, scale_of(m), font="grp", children=kids, elem=child))
        elif tag == "rect":
            x = float(child.get("x", 0))
            y = float(child.get("y", 0))
            w = float(child.get("width", 0))
            h = float(child.get("height", 0))
            px, py = apply(m, x + w / 2.0, y + h / 2.0)
            out.append(Item("rect", px, py, scale_of(m), elem=child, w=w))
        elif tag == "text":
            px, py = apply(m, float(child.get("x", 0)), float(child.get("y", 0)))
            txt = "".join(child.itertext())
            out.append(Item("char", px, py, scale_of(m), text=txt, font="rm", elem=child))
        # ignore defs, path, etc.


# --------------------------------------------------------------- rendering

def _content_scaled(it: Item) -> bool:
    """Whether an item's content is set at script size (recursively)."""
    if it.kind == "char":
        return it.scale < 0.92 or it.text == "/"
    if it.kind == "group":
        kids = [c for c in it.children if c.kind != "rect"]
        return bool(kids) and all(_content_scaled(c) for c in kids)
    return True


def _is_script(it: Item) -> bool:
    # Scripts sit above/below the baseline. MathJax marks them either with a
    # scale on the <use> or with scaled children inside a translated <g>.
    if abs(it.y) <= 60 or it.scale > 1.01:
        return False
    if it.scale < 0.92:
        return True
    if it.kind == "group" and it.children:
        return _content_scaled(it)
    return False


# Multi-letter function names that Aspen help sets in math italic.
ITALIC_FUNCS = {
    "fcn", "ln", "log", "exp", "sin", "cos", "tan", "cot", "sec", "csc",
    "sinh", "cosh", "tanh", "coth", "arcsin", "arccos", "arctan",
    "max", "min", "lim", "sup", "inf", "det", "dim", "ker", "deg",
    "gcd", "hom", "arg", "mod", "erf", "erfc", "sign", "sgn",
}


def _paren(s: str) -> str:
    if not s:
        return "()"
    if _needs_parens(s):
        return "(" + s + ")"
    return s


def _fmt_script(base: str, scripts: list[Item], kind: str) -> str:
    parts = []
    for s in scripts:
        if s.kind == "group":
            t = render_items(s.children, wrap=False, script_mode=True)
        else:
            t = s.text
        if t:
            parts.append(t)
    body = "".join(parts)
    if len(body) > 1 or any(c in body for c in " +-*/=,"):
        body = "{" + body + "}"
    return base + kind + body


def _join(chars: list[str]) -> str:
    """Join glyph chars, merging digits/roman words, spacing operators."""
    out = []
    for ch in chars:
        out.append(ch)
    s = "".join(out)
    # normalize spaces around operators
    s = re.sub(r"\s+", " ", s).strip()
    return s


BIG_OPS = {"sum", "prod", "int", "double_int", "triple_int", "oint",
           "union", "intersect", "AND", "OR", "lim", "max", "min",
           "sup", "inf", "limsup", "liminf"}


def _solidus_fractions(items: list[Item]) -> list[Item]:
    """Detect skewed inline fractions: raised numerator, slash, lowered
    denominator (MathJax renders small fractions without a horizontal bar)."""
    ordered = sorted(items, key=lambda i: i.x)
    taken: set[int] = set()
    synth: dict[int, Item] = {}   # slash id -> replacement item
    for idx, it in enumerate(ordered):
        if id(it) in taken:
            continue
        if it.kind == "char" and it.text == "/" and it.scale > 0.9:
            left, j = [], idx - 1
            while j >= 0 and ordered[j].y > 60 and id(ordered[j]) not in taken:
                left.append(ordered[j])
                j -= 1
            right, j = [], idx + 1
            while j < len(ordered) and ordered[j].y < -60 and id(ordered[j]) not in taken:
                right.append(ordered[j])
                j += 1
            if left and right:
                num = render_items(sorted(left, key=lambda a: a.x), wrap=False,
                                   allow_scripts=False)
                den = render_items(sorted(right, key=lambda a: a.x), wrap=False,
                                   allow_scripts=False)
                txt = f"{_paren(num)}/{_paren(den)}"
                synth[id(it)] = Item("char", it.x, 0.0, it.scale, text=txt, font="grp")
                taken.add(id(it))
                for x in left + right:
                    taken.add(id(x))
    out: list[Item] = []
    for it in ordered:
        if id(it) in synth:
            out.append(synth[id(it)])
        elif id(it) not in taken:
            out.append(it)
    return out


def _absorb_bigop_limits(items: list[Item]):
    """Attach above/below limits to n-ary operators even when the limit's x
    precedes the operator glyph (limits are centered under the operator)."""
    ordered = sorted(items, key=lambda i: i.x)
    ops: list[tuple[Item, float]] = []   # (operator item, right x extent)
    for it in items:
        if it.kind == "char" and it.text in BIG_OPS and abs(it.y) <= 60:
            ops.append((it, it.x + 1500 * it.scale))
    # roman runs spelling lim / max / min / sup / inf
    i = 0
    while i < len(ordered):
        it = ordered[i]
        if (it.kind == "char" and it.font == "rm" and len(it.text) == 1
                and it.text.isalpha() and abs(it.y) <= 60):
            j = i + 1
            while (j < len(ordered) and ordered[j].kind == "char"
                   and ordered[j].font == "rm" and len(ordered[j].text) == 1
                   and ordered[j].text.isalpha() and abs(ordered[j].y) <= 60):
                j += 1
            run = "".join(o.text for o in ordered[i:j])
            if run in BIG_OPS:
                ops.append((ordered[j - 1], ordered[j - 1].x + 1500))
            i = j
        else:
            i += 1
    limits: dict[int, tuple[list, list]] = {}
    taken: set[int] = set()
    for op, xmax in ops:
        subs, sups = [], []
        for it in items:
            if it is op or id(it) in taken:
                continue
            if (abs(it.y) > 450 and _is_script(it)
                    and op.x - 450 <= it.x <= xmax):
                (subs if it.y < 0 else sups).append(it)
        if subs or sups:
            limits[id(op)] = (subs, sups)
            for s in subs + sups:
                taken.add(id(s))
    remaining = [it for it in items if id(it) not in taken]
    return remaining, limits


def _is_delimiter_item(it: Item) -> bool:
    if it.kind == "char":
        return len(it.text) == 1 and it.text in "()[]{}"
    if it.kind == "group":
        kids = [c for c in it.children if c.kind != "rect"]
        return bool(kids) and all(_is_delimiter_item(c) for c in kids)
    return False


def _split_lines(items: list[Item]) -> list[list[Item]]:
    """Split multi-line displays (piecewise definitions, aligned equations)
    into separate baselines. Returns one list per line, top to bottom."""
    import copy
    bases = [it for it in items
             if not _is_script(it) and not _is_delimiter_item(it)]
    if len(bases) < 2:
        return [items]
    ys = sorted({round(it.y) for it in bases})
    clusters: list[list[int]] = [[ys[0]]]
    for y in ys[1:]:
        if y - clusters[-1][-1] > 1000:
            clusters.append([y])
        else:
            clusters[-1].append(y)
    if len(clusters) < 2:
        return [items]
    # baseline of each cluster = most common rounded y among its base items
    lines: list[tuple[float, list[Item]]] = []
    for cl in clusters:
        members = [it for it in bases if any(abs(it.y - y) <= 300 for y in cl)]
        counts: dict[int, int] = {}
        for it in members:
            k = round(it.y / 100) * 100
            counts[k] = counts.get(k, 0) + 1
        baseline = max(counts, key=counts.get)
        lines.append((baseline, []))
    # assign every item to the nearest baseline
    for it in items:
        best = min(lines, key=lambda ln: abs(ln[0] - it.y))
        cp = copy.copy(it)
        cp.y = it.y - best[0]
        best[1].append(cp)
    lines.sort(key=lambda ln: -ln[0])
    return [ln[1] for ln in lines if ln[1]]


def render_items(items: list[Item], wrap: bool = True,
                 allow_scripts: bool = True, script_mode: bool = False) -> str:
    """Render a flat, positioned item list into linear text.

    allow_scripts=False: items are fraction parts positioned relative to a
    fraction bar, not to a baseline; do not reinterpret their y as scripts.
    script_mode: rendering the content of a sub/superscript; join letters
    without spaces (ci, ij are labels, not products).
    """
    if not items:
        return ""
    items = [it for it in items if not (it.kind == "char" and it.text == "")]
    if not items:
        return ""

    # ---- accents: combining marks positioned above a base glyph
    accents = [it for it in items
               if it.kind == "char" and is_accent_char(it.text) and it.y > 150]
    if accents:
        for acc in accents:
            cands = [it for it in items
                     if it is not acc and it.kind != "rect" and -60 <= it.y <= 150]
            if not cands:
                continue
            base = min(cands, key=lambda b: abs(b.x - acc.x))
            name = is_accent_char(acc.text)
            if base.kind == "char":
                base.text = f"{name}({base.text})"
            else:
                inner = render_items(base.children, wrap=False)
                idx = items.index(base)
                items[idx] = Item("char", base.x, base.y, base.scale,
                                  text=f"{name}({inner})", font="grp")
        items = [it for it in items if it not in accents]
        if not items:
            return ""

    # ---- radical: sqrt glyph; radicand is everything to its right under the
    # overline rule. The overline itself is dropped.
    for i, it in enumerate(items):
        if it.kind == "char" and it.text in ("sqrt", "cbrt", "fourthroot"):
            prefix = items[:i]
            rest = [r for r in items[i + 1:]
                    if not (r.kind == "rect" and r.y > 400)]
            if len(rest) == 1 and rest[0].kind == "group":
                body = render_items(rest[0].children, wrap=False)
            else:
                body = render_items(rest, wrap=False)
            head = render_items(prefix, wrap=False) if prefix else ""
            fn = it.text
            out = f"{head} {fn}({body})" if head else f"{fn}({body})"
            return _tidy(out)

    # ---- fraction / rule detection
    rects = [it for it in items if it.kind == "rect" and it.w > 0]
    if rects:
        bar = max(rects, key=lambda r: r.w)
        above = [it for it in items if it.kind != "rect" and it.y > bar.y + 40]
        below = [it for it in items if it.kind != "rect" and it.y < bar.y - 40]
        if above and below:
            num = render_items(sorted(above, key=lambda i: i.x), wrap=False,
                               allow_scripts=False)
            den = render_items(sorted(below, key=lambda i: i.x), wrap=False,
                               allow_scripts=False)
            return f"{_paren(num)}/{_paren(den)}"
        if above and not below:
            body = render_items(sorted(above, key=lambda i: i.x), wrap=False,
                                allow_scripts=False)
            return f"bar({body})"
        if below and not above:
            body = render_items(sorted(below, key=lambda i: i.x), wrap=False,
                                allow_scripts=False)
            return f"underline({body})"

    # ---- skewed solidus fractions (raised num / lowered den, no bar)
    items = _solidus_fractions(items)

    # ---- multi-line displays (piecewise / aligned equations)
    lines = _split_lines(items)
    if len(lines) > 1:
        return " ; ".join(render_items(ln, wrap=False) for ln in lines)

    # ---- n-ary operator limits (centered above/below the operator)
    items, limits = _absorb_bigop_limits(items)

    # ---- sort by x, attach scripts to preceding base
    ordered = sorted(items, key=lambda i: (i.x, -i.y))
    pieces: list[tuple[str, str]] = []   # (text, font)
    pending_sub: list[Item] = []
    pending_sup: list[Item] = []
    last_base_idx = -1

    def flush_scripts():
        nonlocal pending_sub, pending_sup, last_base_idx
        if last_base_idx >= 0 and (pending_sub or pending_sup):
            base, font = pieces[last_base_idx]
            if pending_sub:
                base = _fmt_script(base, sorted(pending_sub, key=lambda s: s.x), "_")
            if pending_sup:
                base = _fmt_script(base, sorted(pending_sup, key=lambda s: s.x), "^")
            pieces[last_base_idx] = (base, font)
        pending_sub = []
        pending_sup = []

    for it in ordered:
        if allow_scripts and _is_script(it):
            if it.y < 0:
                pending_sub.append(it)
            else:
                pending_sup.append(it)
            continue
        flush_scripts()
        if it.kind == "char":
            txt = it.text
            if id(it) in limits:
                subs, sups = limits[id(it)]
                if subs:
                    txt = _fmt_script(txt, sorted(subs, key=lambda s: s.x), "_")
                if sups:
                    txt = _fmt_script(txt, sorted(sups, key=lambda s: s.x), "^")
            pieces.append((txt, it.font))
            last_base_idx = len(pieces) - 1
        else:
            txt = render_items(it.children, wrap=True)
            if txt:
                # distinguish genuine delimiter groups from synthetic wrapping
                first = next((c for c in it.children
                              if c.kind != "rect" and c.text != ""), None)
                genuine = (first is not None and first.kind == "char"
                           and len(first.text) == 1 and first.text in "()[]{}")
                pieces.append((txt, "grp" if genuine else "wrap"))
                last_base_idx = len(pieces) - 1
    flush_scripts()

    # ---- merge italic runs that spell known function names (fcn, ln, ...)
    i = 0
    while i < len(pieces):
        t, f = pieces[i]
        if f == "it" and len(t) == 1 and t.isalpha():
            j = i + 1
            while (j < len(pieces) and pieces[j][1] == "it"
                   and len(pieces[j][0]) == 1 and pieces[j][0].isalpha()):
                j += 1
            run = "".join(p[0] for p in pieces[i:j])
            if run.lower() in ITALIC_FUNCS:
                pieces[i:j] = [(run, "it")]
                i += 1
            else:
                i = j
        else:
            i += 1

    # ---- merge adjacent characters into tokens (font-aware)
    merged: list[tuple[str, str]] = []
    for text, font in pieces:
        if not text:
            continue
        if merged and _mergeable(merged[-1], (text, font)):
            merged[-1] = (merged[-1][0] + text, merged[-1][1])
        else:
            merged.append((text, font))
    merged = _absorb_bigop_bodies(merged)
    s = ("" if script_mode else " ").join(t for t, _ in merged)
    s = _tidy(s)
    if wrap and _needs_parens(s):
        s = "(" + s + ")"
    return s


_BODY_STOP = {"+", "-", "=", "<=", ">=", "!=", "~=", "==", "->", "<->",
              "=>", "<=>", ",", ";", "<", ">", "for", "where", "and", "or"}


def _balanced_inner(t: str) -> str | None:
    """Return the content of a fully parenthesized token, else None."""
    if not (t.startswith("(") and t.endswith(")")):
        return None
    depth = 0
    for k, ch in enumerate(t):
        if ch == "(":
            depth += 1
        elif ch == ")":
            depth -= 1
        if depth == 0 and k < len(t) - 1:
            return None
    return t[1:-1] if depth == 0 else None


def _absorb_bigop_bodies(merged: list[tuple[str, str]]) -> list[tuple[str, str]]:
    """Extend n-ary operator scope over the following term: MathJax sometimes
    groups only part of a sum/integrand body; visually the operator applies to
    the whole term up to the next additive operator or relation. Only synthetic
    wrapping parens are transparent; genuine source delimiters close scope."""
    out: list[tuple[str, str]] = []
    i = 0
    while i < len(merged):
        t, f = merged[i]
        head = re.split(r"[_^]", t)[0]
        inner = _balanced_inner(t) if f == "wrap" else None
        wrapped_op = (inner is not None
                      and re.split(r"[_^]", inner)[0] in BIG_OPS)
        if (head in BIG_OPS or wrapped_op) and i + 1 < len(merged):
            body: list[str] = []
            j = i + 1
            while j < len(merged) and merged[j][0] not in _BODY_STOP:
                body.append(merged[j][0])
                j += 1
            if wrapped_op:
                if body:
                    out.append(("(" + inner + " " + " ".join(body) + ")", "wrap"))
                    i = j
                    continue
            elif body:
                if len(body) == 1 and body[0].startswith("(") and body[0].endswith(")"):
                    out.append((t, f))
                    out.append((body[0], "grp"))
                    i = j
                    continue
                if len(body) > 1:
                    bi = _balanced_inner(body[0])
                    if bi is not None:
                        body[0] = bi
                out.append((t + " (" + " ".join(body) + ")", f))
                i = j
                continue
        out.append((t, f))
        i += 1
    return out


def _mergeable(a: tuple[str, str], b: tuple[str, str]) -> bool:
    """Whether two adjacent pieces should be concatenated without space."""
    at, af = a
    bt, bf = b
    if not at or not bt:
        return False
    # digits with digits / decimal point
    if (at[-1].isdigit() or at[-1] == ".") and (bt[0].isdigit() or bt[0] == "."):
        return True
    # roman letters form words (function names like ln, exp, fcn);
    # italic variables stay separate (each letter is its own variable)
    if af == "rm" and bf == "rm":
        if at[-1].isascii() and at[-1].isalpha() and bt[0].isascii() and bt[0].isalpha():
            return True
    # stacked tall-delimiter pieces collapse into one delimiter
    if at == bt and at in "()[]{}":
        return True
    return False


_NEEDS_PAREN_RE = re.compile(r"[ +\-*/=,]|^$")


def _needs_parens(s: str) -> bool:
    if not s:
        return False
    if s.startswith("(") and s.endswith(")"):
        return False
    return bool(_NEEDS_PAREN_RE.search(s))


_MULTI_OPS = ["<=>", "<->", "->", "<-", "=>", "<=", ">=", "!=", "~=", "==",
              "-/+", "...", "||"]


def _tidy(s: str) -> str:
    s = re.sub(r"\s+", " ", s).strip()
    # protect multi-character operators from single-char spacing
    holders: dict[str, str] = {}
    for i, op in enumerate(_MULTI_OPS):
        h = f"\x00{i}\x00"
        if op in s:
            s = s.replace(op, h)
            holders[h] = op
    s = re.sub(r"\s*(=|\+|\-|\*|/)\s*", r" \1 ", s)
    # keep unary minus attached: "x = - 5" -> "x = -5"
    s = re.sub(r"(=|\+|\*|/|\(|\{|,|^)\s+-\s+", r"\1 -", s)
    for h, op in holders.items():
        s = s.replace(h, f" {op} ")
    s = re.sub(r"\{\s*-\s+", "{-", s)
    s = re.sub(r"\(\s+", "(", s)
    s = re.sub(r"\s+\)", ")", s)
    s = re.sub(r"\s+_", "_", s)
    s = re.sub(r"\s+\^", "^", s)
    s = re.sub(r"_\s+", "_", s)
    s = re.sub(r"\^\s+", "^", s)
    s = re.sub(r"\s+,", ",", s)
    s = re.sub(r"\s+\.", ".", s)
    s = re.sub(r"\s+'", "'", s)
    s = re.sub(r"\s+", " ", s)
    s = _collapse_parens(s.strip())
    return s


def _collapse_parens(s: str) -> str:
    """Remove redundant parenthesis pairs that directly wrap another pair."""
    while True:
        stack: list[int] = []
        match: dict[int, int] = {}
        for k, ch in enumerate(s):
            if ch == "(":
                stack.append(k)
            elif ch == ")" and stack:
                match[stack.pop()] = k
        removed = False
        for i, j in match.items():
            if i + 1 < j and s[i + 1] == "(" and match.get(i + 1) == j - 1:
                s = s[:i] + s[i + 1:j] + s[j + 1:]
                removed = True
                break
        if not removed:
            return s


# ------------------------------------------------------------------ entry

def decode_svg_text(svg_text: str) -> str:
    root = ET.fromstring(svg_text)
    defs = root.find(f"{{{SVG_NS}}}defs")
    body_g = None
    for child in root:
        tag = child.tag.split("}")[-1]
        if tag == "g":
            body_g = child
            break
    if body_g is None:
        return ""
    m = parse_transform(body_g.get("transform"))
    items: list[Item] = []
    collect(body_g, m, items)
    # The outer matrix(1 0 0 -1 0 0) flips y; normalize so +y is up.
    if m[3] < 0:
        for it in items:
            it.y = -it.y
            if it.kind == "group":
                _flip_group(it)
    return render_items(items, wrap=False)


def _flip_group(it: Item):
    for c in it.children:
        c.y = -c.y
        if c.kind == "group":
            _flip_group(c)


def decode_svg_file(path: str) -> str:
    with open(path, encoding="utf-8") as f:
        return decode_svg_text(f.read())


if __name__ == "__main__":
    import sys
    for p in sys.argv[1:]:
        print(p)
        print("  ", decode_svg_file(p))