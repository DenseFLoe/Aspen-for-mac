#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Scan .cs.txt dumps for the ilspycmd upgrade notice that must never reach delivery.

Usage: python tool/check_cs_clean.py <dir> [<dir> ...]
Exit: 0 clean, 1 hits, 2 no files
"""
import sys
from pathlib import Path

NAG_HEAD = "You are not using the latest version of the tool"
NAG_VER = "Latest version is"


def literal_spans(text):
    """C# 字符串/字符/注释占用的区间；其中的同文提示属于合法源码。"""
    spans = []
    i, n = 0, len(text)
    while i < n:
        ch = text[i]
        if ch == "/" and text.startswith("//", i):
            j = text.find("\n", i)
            j = n if j < 0 else j
            spans.append((i, j))
            i = j
        elif ch == "/" and text.startswith("/*", i):
            j = text.find("*/", i + 2)
            j = n if j < 0 else j + 2
            spans.append((i, j))
            i = j
        elif ch == "@" and text.startswith('@"', i):
            j = i + 2
            while j < n:
                if text[j] == '"':
                    if text.startswith('""', j):
                        j += 2
                        continue
                    j += 1
                    break
                j += 1
            spans.append((i, j))
            i = j
        elif ch == '"':
            q = 0
            while i + q < n and text[i + q] == '"':
                q += 1
            if q >= 3:
                j = text.find('"' * q, i + q)
                j = n if j < 0 else j + q
            else:
                j = i + 1
                while j < n:
                    if text[j] == "\\":
                        j += 2
                        continue
                    if text[j] == '"':
                        j += 1
                        break
                    if text[j] == "\n":
                        break
                    j += 1
            spans.append((i, j))
            i = j
        elif ch == "'":
            j = i + 1
            while j < n:
                if text[j] == "\\":
                    j += 2
                    continue
                if text[j] == "'":
                    j += 1
                    break
                if text[j] == "\n":
                    break
                j += 1
            spans.append((i, j))
            i = j
        else:
            i += 1
    return spans


def has_nag(text):
    """只在字符串/注释之外命中终端提示或未配对裸诊断才算脏。"""
    spans = literal_spans(text)
    offset = 0
    for line in text.splitlines(keepends=True):
        probe = line.lstrip()
        if probe.startswith(NAG_HEAD) or probe.startswith(NAG_VER):
            if not any(a <= offset < b for a, b in spans):
                return True
        offset += len(line)
    return False


def scan(root):
    hits, total = [], 0
    for p in Path(root).rglob("*.cs.txt"):
        total += 1
        try:
            text = p.read_bytes().decode("utf-8", "replace")
        except OSError:
            continue
        if has_nag(text):
            hits.append(p)
    return total, hits


def main(argv=None):
    argv = argv if argv is not None else sys.argv[1:]
    if not argv:
        print("usage: check_cs_clean.py <dir> [...]")
        return 2
    grand = 0
    bad = 0
    for d in argv:
        total, hits = scan(d)
        grand += total
        bad += len(hits)
        print("%s files=%d nag_hits=%d" % (d, total, len(hits)))
        for h in hits[:5]:
            print("   HIT %s" % h)
    if grand == 0:
        print("CHECK_CS_CLEAN no_files")
        return 2
    print("CHECK_CS_CLEAN files=%d hits=%d %s" % (grand, bad, "OK" if bad == 0 else "FAIL"))
    return 0 if bad == 0 else 1


if __name__ == "__main__":
    sys.exit(main())
