import fs from 'node:fs';
import crypto from 'node:crypto';

const [objFile, dllFile, indexFile] = process.argv.slice(2);
const obj = fs.readFileSync(objFile);
const dll = fs.readFileSync(dllFile);
const coff = JSON.parse(fs.readFileSync(indexFile, 'utf8'));
const hash = bytes => crypto.createHash('sha256').update(bytes).digest('hex');
const hex = n => '0x' + n.toString(16);
const w = pos => dll.readUInt16LE(pos);
const d = pos => dll.readUInt32LE(pos);
const nt = d(0x3c);
const op = nt + 24;
if (d(nt) !== 0x4550 || w(nt + 4) !== 0x8664 || w(op) !== 0x20b)
  throw new Error('Expected AMD64 PE32+ DLL');

const sections = [];
for (let i = 0; i < w(nt + 6); i++) {
  const h = op + w(nt + 20) + 40 * i;
  sections.push({
    name: dll.toString('ascii', h, h + 8).split('\0')[0],
    va: d(h + 12), virtualSize: d(h + 8), raw: d(h + 20), rawSize: d(h + 16),
  });
}
function offset(rva) {
  const sec = sections.find(s => s.va <= rva && rva < s.va + s.rawSize);
  if (!sec) throw new Error('RVA outside raw bytes: ' + hex(rva));
  return sec.raw + rva - sec.va;
}
const readString = rva => {
  const start = offset(rva);
  return dll.toString('ascii', start, dll.indexOf(0, start));
};
const exportsOff = offset(d(op + 112));
const exports = {};
for (let i = 0; i < d(exportsOff + 24); i++) {
  const name = readString(d(offset(d(exportsOff + 32)) + i * 4));
  const ordinal = w(offset(d(exportsOff + 36)) + i * 2);
  exports[name] = d(offset(d(exportsOff + 28)) + ordinal * 4);
}
const imports = new Map();
for (let desc = offset(d(op + 120)); d(desc + 12); desc += 20) {
  const lib = readString(d(desc + 12));
  const lookup = offset(d(desc) || d(desc + 16));
  const iat = d(desc + 16);
  for (let i = 0; dll.readBigUInt64LE(lookup + i * 8); i++) {
    const thunk = dll.readBigUInt64LE(lookup + i * 8);
    imports.set(iat + i * 8, {
      lib,
      name: thunk >> 63n ? '#' + (thunk & 0xffffn) : readString(Number(thunk) + 2),
    });
  }
}

function compare(name, base) {
  const sec = coff.sections.find(s => s.name === name);
  const start = offset(base);
  const ignored = new Set();
  const relocs = sec.relocations.map(r => {
    const at = Number(r.offset);
    for (let j = 0; j < 4; j++) ignored.add(at + j);
    const patched = dll.readInt32LE(start + at);
    const target = (r.type === '0x4' ? base + at + 4 + patched : patched) - r.addend;
    let binding = imports.get(target);
    if (!binding && dll[start + at - 1] === 0xe8) {
      const stub = offset(target);
      if (dll[stub] === 0xff && dll[stub + 1] === 0x25)
        binding = imports.get(target + 6 + dll.readInt32LE(stub + 2));
    }
    return { ...r, patched: hex(patched >>> 0), target: hex(target), binding };
  });
  const mismatches = [];
  for (let i = 0; i < sec.size; i++) {
    if (!ignored.has(i) && obj[sec.rawOffset + i] !== dll[start + i])
      mismatches.push(hex(i));
  }
  return { section: name, dllRva: hex(base), size: sec.size, comparedBytes: sec.size - ignored.size,
    mismatchCount: mismatches.length, firstMismatches: mismatches.slice(0, 25), relocations: relocs };
}

const text = compare('.text', exports.BFDYLD);
const sectionTargets = {};
for (const r of text.relocations) {
  if (r.targetSection > 0 && r.targetSection !== 1) {
    const name = coff.sections[r.targetSection - 1].name;
    (sectionTargets[name] ??= new Set()).add(Number(r.target) - r.symbolValue);
  }
}
const matches = [text];
for (const name of ['.rdata', '.data']) {
  const bases = [...sectionTargets[name]];
  for (const base of bases) matches.push(compare(name, base));
}
const pdataRva = d(op + 112 + 3*8);
const pdataSize = d(op + 112 + 3*8 + 4);
const runtime = [];
for (let i = 0; i < pdataSize; i += 12) {
  const p = offset(pdataRva + i);
  const begin = d(p);
  const end = d(p + 4);
  const unwind = d(p + 8);
  if (exports.BFDYLD <= begin && begin < exports.BFDYLD + text.size)
    runtime.push({ row: hex(pdataRva + i), begin: hex(begin), end: hex(end), unwind: hex(unwind) });
}
if (runtime.length) {
  matches.push(compare('.pdata', Number(runtime[0].row)));
  const p = matches.at(-1);
  const xdataTargets = new Set(p.relocations.filter(r => r.symbol === '.xdata').map(r => r.target));
  for (const base of xdataTargets) matches.push(compare('.xdata', Number(base)));
}
console.log(JSON.stringify({
  objectSHA256: hash(obj), dllSHA256: hash(dll), exports, sections,
  imports: [...imports].map(([rva, imp]) => ({ rva: hex(rva), ...imp })),
  sectionTargets: Object.fromEntries(Object.entries(sectionTargets).map(([name, bases]) => [name, [...bases].map(hex)])),
  runtime, matches,
}, null, 2));