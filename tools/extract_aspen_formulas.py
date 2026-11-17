#!/usr/bin/env python3
"""Extract formula-bearing help topics and plain-text fluid files from Aspen V15.

Sources (all read-only, from the local Aspen Plus V15 installation):
  1. HtmlHelp subsystems: help topics whose equations are MathJax SVG images.
     Each topic becomes one UTF-8 .txt file with its prose, tables and the
     decoded equations in document order (see mathjax_svg_decode.py).
  2. Engine/Dat/fluids/*.FLD: NIST REFPROP-style plain-text fluid files that
     contain equation forms plus coefficient values; copied verbatim.
  3. Safety_Datasheets topics: equations stored as PNG images; the topics are
     extracted with [EQ-IMAGE: ...] markers and the images are copied for
     transcription.

Output goes to a NEW directory (default .local/formula-extraction-20261116).
Protected database assets under .local/property-database are never touched.

Usage:
  python tools/extract_aspen_formulas.py [--help-root PATH] [--output DIR]
                                         [--subsystems a,b] [--limit N]
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
import re
import shutil
import sys
from pathlib import Path

from bs4 import BeautifulSoup, NavigableString, Tag

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import mathjax_svg_decode as mj

DEFAULT_HELP = r"C:\ProgramData\AspenTech\Aspen Plus V15.0\HtmlHelp\Subsystems"
DEFAULT_ENGINE = r"C:\Program Files\AspenTech\AprSystem V15.0\Engine"
DEFAULT_OUT = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))),
                           ".local", "formula-extraction-20261116")

EQ_IMG_RE = re.compile(r"\.svg$", re.I)
# Inkscape-drawn single symbols that are not MathJax glyph SVGs.
DRAWN_SVG = {"gamma.svg": "γ"}


def output_path(path: str | Path) -> Path:
    destination = Path(path).resolve()
    protected = (Path(__file__).resolve().parents[1] / '.local' / 'property-database').resolve()
    if destination == protected or protected in destination.parents:
        raise ValueError('Output must be outside protected property-database assets')
    return destination


def copy_new_file(source: str, destination: str):
    destination = output_path(destination)
    with open(source, 'rb') as incoming, destination.open('xb') as outgoing:
        shutil.copyfileobj(incoming, outgoing)


class Extractor:
    def __init__(self, help_root: str, out_dir: str):
        self.help_root = help_root
        self.out_dir = out_dir
        self.svg_cache: dict[str, str] = {}
        self.svg_missing: list[str] = []
        self.stats = {"topics": 0, "equations": 0, "eq_images_png": 0,
                      "other_images": 0, "tables": 0}

    # ------------------------------------------------------------ equations
    def decode_svg(self, abs_path: str) -> str:
        if abs_path in self.svg_cache:
            return self.svg_cache[abs_path]
        base = os.path.basename(abs_path).lower()
        if base in DRAWN_SVG:
            txt = DRAWN_SVG[base]
        else:
            try:
                txt = mj.decode_svg_file(abs_path)
            except Exception as e:
                txt = f"[SVG-DECODE-ERROR: {e}]"
        if not txt.strip():
            txt = "[EMPTY-SVG]"
        self.svg_cache[abs_path] = txt
        return txt

    def img_text(self, img: Tag, base_dir: str) -> tuple[str, bool]:
        """Return (replacement_text, is_equation)."""
        src = img.get("src", "")
        if not src:
            return "", False
        abs_path = os.path.normpath(os.path.join(base_dir, src))
        if EQ_IMG_RE.search(src):
            self.stats["equations"] += 1
            return self.decode_svg(abs_path), True
        if re.search(r"\.(png|gif|jpg|jpeg|bmp)$", src, re.I):
            name = os.path.basename(src)
            if re.match(r"Equation\d+\.(png|gif)$", name, re.I):
                self.stats["eq_images_png"] += 1
                return f"[EQ-IMAGE: {src}]", True
            self.stats["other_images"] += 1
            return f"[IMAGE: {src}]", False
        return f"[IMAGE: {src}]", False

    # -------------------------------------------------------------- inline
    def inline(self, node, base_dir: str) -> str:
        if isinstance(node, NavigableString):
            return str(node)
        if not isinstance(node, Tag):
            return ""
        name = node.name
        if name == "img":
            txt, _ = self.img_text(node, base_dir)
            return txt
        if name == "br":
            return "\n"
        if name in ("script", "style"):
            return ""
        if name == "sup":
            inner = self.inline_children(node, base_dir).strip()
            return "^" + (f"{{{inner}}}" if len(inner) > 1 else inner)
        if name == "sub":
            inner = self.inline_children(node, base_dir).strip()
            return "_" + (f"{{{inner}}}" if len(inner) > 1 else inner)
        if name == "span":
            cls = node.get("class") or []
            style = (node.get("style") or "").replace(" ", "").lower()
            inner = self.inline_children(node, base_dir)
            s = inner.strip()
            if "super" in cls or "vertical-align:super" in style:
                return "^" + (f"{{{s}}}" if len(s) > 1 else s)
            if "sub" in cls or "vertical-align:sub" in style:
                return "_" + (f"{{{s}}}" if len(s) > 1 else s)
            return inner
        return self.inline_children(node, base_dir)

    def inline_children(self, node: Tag, base_dir: str) -> str:
        return "".join(self.inline(c, base_dir) for c in node.children)

    def cell_text(self, td: Tag, base_dir: str) -> str:
        txt = self.inline_children(td, base_dir)
        txt = re.sub(r"\s+", " ", txt).strip()
        return txt

    # -------------------------------------------------------------- tables
    def render_table(self, table: Tag, base_dir: str) -> str:
        classes = table.get("class") or []
        rows = []
        for tr in table.find_all("tr"):
            cells = tr.find_all(["td", "th"], recursive=False)
            if not cells:
                continue
            rows.append([self.cell_text(c, base_dir) for c in cells])
        if not rows:
            return ""
        if "invisible" in classes:
            # equation block: equation cell + equation-number cell
            lines = []
            for r in rows:
                if len(r) >= 2 and re.fullmatch(r"\(\d+[a-z]?\)", r[-1]):
                    eq = " ".join(x for x in r[:-1] if x)
                    lines.append(f"    {r[-1]}  {eq}")
                else:
                    lines.append("    " + " ".join(x for x in r if x))
            return "\n".join(lines)
        self.stats["tables"] += 1
        if "notebox" in classes or "warning" in classes:
            body = " ".join(" ".join(r) for r in rows)
            return "> " + body
        # plain data table
        ncols = max(len(r) for r in rows)
        rows = [r + [""] * (ncols - len(r)) for r in rows]
        widths = [max(len(r[i]) for r in rows) for i in range(ncols)]
        widths = [min(w, 60) for w in widths]
        lines = []
        for k, r in enumerate(rows):
            lines.append("| " + " | ".join(c.ljust(w) for c, w in zip(r, widths)) + " |")
            if k == 0:
                lines.append("|" + "|".join("-" * (w + 2) for w in widths) + "|")
        return "\n".join(lines)

    # -------------------------------------------------------------- blocks
    def blocks(self, node, base_dir: str, out: list):
        if isinstance(node, NavigableString):
            txt = str(node).strip()
            if txt:
                out.append(txt)
            return
        if not isinstance(node, Tag):
            return
        name = node.name
        if name in ("script", "style", "head"):
            return
        if name in ("h1", "h2", "h3", "h4", "h5", "h6"):
            level = int(name[1])
            out.append("#" * level + " " + self.inline_children(node, base_dir).strip())
            return
        if name == "p":
            classes = node.get("class") or []
            txt = self.inline_children(node, base_dir)
            txt = re.sub(r"[ \t]+", " ", txt).strip()
            if not txt:
                return
            if "subheading" in classes:
                out.append("## " + txt)
                return
            # display equation: paragraph consists solely of equation image(s)
            if node.find("img") is not None and self._eq_only(node):
                for line in txt.split("\n"):
                    if line.strip():
                        out.append("    " + line.strip())
                return
            out.append(txt)
            return
        if name == "table":
            t = self.render_table(node, base_dir)
            if t:
                out.append(t)
            return
        if name in ("ul", "ol"):
            for i, li in enumerate(node.find_all("li", recursive=False), 1):
                marker = f"{i}." if name == "ol" else "-"
                sub: list[str] = []
                self.blocks_children(li, base_dir, sub)
                text = " ".join(x.strip() for x in sub if x.strip())
                out.append(f"{marker} {text}")
            return
        if name == "pre":
            out.append("```\n" + node.get_text() + "\n```")
            return
        if name in ("div", "section", "article", "body", "html", "blockquote",
                    "span", "center", "main"):
            self.blocks_children(node, base_dir, out)
            return
        # fallback: treat as paragraph
        txt = self.inline_children(node, base_dir).strip()
        if txt:
            out.append(txt)

    def blocks_children(self, node: Tag, base_dir: str, out: list):
        for c in node.children:
            self.blocks(c, base_dir, out)

    def _eq_only(self, node: Tag) -> bool:
        for c in node.children:
            if isinstance(c, NavigableString):
                if str(c).strip():
                    return False
            elif isinstance(c, Tag):
                if c.name == "img":
                    continue
                if c.name in ("span", "b", "i", "em", "strong", "a"):
                    if not self._eq_only(c):
                        return False
                else:
                    return False
        return True

    # --------------------------------------------------------------- topic
    def extract_topic(self, htm_path: str, subsystem: str) -> dict:
        base_dir = os.path.dirname(htm_path)
        html = Path(htm_path).read_text(encoding="utf-8", errors="replace")
        soup = BeautifulSoup(html, "html.parser")
        title = soup.title.get_text(strip=True) if soup.title else os.path.basename(htm_path)
        body = soup.body or soup
        out: list[str] = []
        self.blocks_children(body, base_dir, out)
        text = "\n\n".join(out)
        text = re.sub(r"\n{3,}", "\n\n", text).strip() + "\n"
        n_eq = len(re.findall(r"Equation\d+\.svg|/eqns/|gamma\.svg", html))
        header = (f"# {title}\n\n"
                  f"Source: {htm_path}\n"
                  f"Subsystem: {subsystem}\n"
                  f"Equation images in source: {n_eq}\n\n"
                  f"{'=' * 72}\n\n")
        rel = os.path.join("topics", subsystem,
                           os.path.splitext(os.path.basename(htm_path))[0] + ".txt")
        dest = output_path(os.path.join(self.out_dir, rel))
        os.makedirs(os.path.dirname(dest), exist_ok=True)
        with open(dest, "x", encoding="utf-8") as f:
            f.write(header + text)
        self.stats["topics"] += 1
        return {"subsystem": subsystem, "title": title, "source": htm_path,
                "output": rel.replace("\\", "/"), "equation_images": n_eq}

    # ----------------------------------------------------------------- run
    def run(self, subsystems: list[str] | None, limit: int | None):
        # Exported assets are permanent. A repeat invocation must use a new path.
        output = output_path(self.out_dir)
        if not Path(self.help_root).is_dir():
            raise FileNotFoundError('Help root not found: ' + self.help_root)
        output.mkdir(parents=True, exist_ok=False)
        index = []
        subs = sorted(os.listdir(self.help_root))
        if subsystems:
            subs = [s for s in subs if s in subsystems]
        for sub in subs:
            html_dir = os.path.join(self.help_root, sub, "Content", "html")
            if not os.path.isdir(html_dir):
                continue
            topics = []
            for fn in sorted(os.listdir(html_dir)):
                if not fn.lower().endswith((".htm", ".html")):
                    continue
                p = os.path.join(html_dir, fn)
                txt = Path(p).read_text(encoding="utf-8", errors="replace")
                if re.search(r'src="[^"]*\.svg"', txt) or re.search(r'src="[^"]*Equation\d+\.png"', txt):
                    topics.append(p)
            if limit:
                topics = topics[:limit]
            for p in topics:
                index.append(self.extract_topic(p, sub))
            if topics:
                print(f"{sub}: {len(topics)} topics")
        # index
        with open(os.path.join(self.out_dir, "index.json"), "x", encoding="utf-8") as f:
            json.dump({"stats": self.stats, "topics": index}, f, ensure_ascii=False, indent=1)
        print("STATS:", json.dumps(self.stats))
        return index


def copy_fluids(engine_root: str, out_dir: str):
    src_dir = os.path.join(engine_root, "Dat", "fluids")
    if not os.path.isdir(src_dir):
        print("fluids dir not found:", src_dir)
        return
    dest_dir = output_path(os.path.join(out_dir, "engine-fluids"))
    dest_dir.mkdir(parents=True, exist_ok=False)
    manifest = []
    for fn in sorted(os.listdir(src_dir)):
        sp = os.path.join(src_dir, fn)
        if not os.path.isfile(sp):
            continue
        dp = os.path.join(dest_dir, fn)
        copy_new_file(sp, dp)
        h = hashlib.sha256(Path(sp).read_bytes()).hexdigest()
        manifest.append({"file": fn, "bytes": os.path.getsize(sp), "sha256": h,
                         "source": sp})
    with open(os.path.join(dest_dir, "manifest.json"), "x", encoding="utf-8") as f:
        json.dump(manifest, f, ensure_ascii=False, indent=1)
    print(f"engine-fluids: {len(manifest)} files copied")


def copy_safety_images(help_root: str, out_dir: str):
    src_dir = os.path.join(help_root, "Safety_Datasheets", "Content", "GeneratedImages")
    if not os.path.isdir(src_dir):
        print("Safety_Datasheets images dir not found")
        return
    dest_dir = output_path(os.path.join(out_dir, "safety-datasheets-equation-images"))
    dest_dir.mkdir(parents=True, exist_ok=False)
    n = 0
    for root, _dirs, files in os.walk(src_dir):
        for fn in sorted(files):
            if re.match(r"Equation\d+\.(png|gif)$", fn, re.I):
                copy_new_file(os.path.join(root, fn), os.path.join(dest_dir, fn))
                n += 1
    print(f"safety-datasheets equation images: {n} copied")


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--help-root", default=DEFAULT_HELP)
    ap.add_argument("--engine-root", default=DEFAULT_ENGINE)
    ap.add_argument("--output", default=DEFAULT_OUT)
    ap.add_argument("--subsystems", default="", help="comma-separated filter")
    ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--skip-fluids", action="store_true")
    ap.add_argument("--skip-safety-images", action="store_true")
    args = ap.parse_args()
    subs = [s.strip() for s in args.subsystems.split(",") if s.strip()] or None
    ex = Extractor(args.help_root, args.output)
    ex.run(subs, args.limit or None)
    if not args.skip_fluids:
        copy_fluids(args.engine_root, args.output)
    if not args.skip_safety_images:
        copy_safety_images(args.help_root, args.output)


if __name__ == "__main__":
    main()
