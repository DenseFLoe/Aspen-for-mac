import assert from 'node:assert/strict';
import fs from 'node:fs';
import crypto from 'node:crypto';

const [objectFile, dllFile, sourceFile, coffFile, peFile, ghidraLog] = process.argv.slice(2);
const buffer = file => fs.readFileSync(file);
const json = file => JSON.parse(buffer(file));
const hash = bytes => crypto.createHash('sha256').update(bytes).digest('hex');
const orig = buffer(objectFile);
const dll = buffer(dllFile);
const source = buffer(sourceFile);
const coff = json(coffFile);
const pe = json(peFile);

assert.equal(hash(orig), '194e88b44801eb787ccd0964ef43f869a7d355a2ea905a0f679d173f91703ec0');
assert.equal(hash(orig), coff.sha256);
assert.equal(hash(orig), pe.objectSHA256);
assert.equal(hash(dll), 'f80d424238afde109cb1257446f1c0e11914a806f625bad1523cfeb778440216');
assert.equal(hash(dll), pe.dllSHA256);
assert.equal(hash(source), '9c4b6d277af6643d2f199656e6aece7e478290368613b0bd9b5002f799b10fb1');
assert.deepEqual(coff.symbols.filter(s => s.section > 0 && s.type === '0x20').map(s => s.name), ['BFDYLD']);
assert.equal(coff.optionalHeaderSize, 0);
assert.equal(coff.machine, '0x8664');
assert.equal(coff.symbolCount, 51);
assert.equal(coff.sections.length, 7);

const [text, rdata, data, pdata, xdata] = pe.matches;
assert.deepEqual(pe.matches.map(m => m.section), ['.text', '.rdata', '.data', '.pdata', '.xdata']);
assert.deepEqual(pe.matches.map(m => m.relocations.length), [59, 0, 0, 30, 27]);
assert.ok(pe.matches.every(m => m.mismatchCount === 0));
assert.equal(pe.exports.BFDYLD, Number(text.dllRva));
assert.equal(pe.runtime.length, 10);

const bss = pe.sectionTargets['.bss'].map(Number);
assert.equal(bss.length, 1);
const dataInPe = pe.sections.find(s => s.name === '.data');
const bssSize = coff.sections.find(s => s.name === '.bss').size;
assert.equal(coff.sections.find(s => s.name === '.bss').rawOffset, 0);
assert.ok(Number(data.dllRva) + data.size <= bss[0]);
assert.ok(bss[0] + bssSize <= dataInPe.va + dataInPe.virtualSize);
const rawBssStart = dataInPe.raw + bss[0] - dataInPe.va;
const rawDataEnd = dataInPe.raw + dataInPe.rawSize;
assert.ok(dll.subarray(rawBssStart, rawDataEnd).every(byte => byte === 0));

const originalBase = { '.text': 0x2700, '.xdata': 0x2f00, '.pdata': 0x2500 };
const peBases = new Map(pe.matches.map(m => [m.section, Number(m.dllRva)]));
peBases.set('.bss', bss[0]);
const verifiedAddresses = new Map();
for (const sec of pe.matches) {
  for (const r of sec.relocations) {
    const target = Number(r.target);
    if (r.targetSection > 0) {
      const targetSection = coff.sections[r.targetSection - 1].name;
      assert.equal(target, peBases.get(targetSection) + r.symbolValue);
    } else if (r.symbol === '__ImageBase') {
      assert.equal(target, 0);
    } else if (r.symbol === '__chkstk') {
      assert.equal(target, 0x1730);
    } else {
      const expected = r.symbol.replace(/^__imp_/, '');
      const dll = expected === 'for_write_int_fmt' ? 'libifcoremd.dll' : 'atdms.dll';
      assert.equal(r.binding?.name, expected);
      assert.equal(r.binding?.lib.toLowerCase(), dll);
    }
    verifiedAddresses.set(originalBase[sec.section] + Number(r.offset), Number(r.type));
  }
}
const failures = [...buffer(ghidraLog).toString().matchAll(/Failed to apply COFF Relocation type (0x[0-9a-f]+) at ([0-9a-f]+)/gi)];
assert.equal(failures.length, 41);
assert.equal(new Set(failures.map(m => m[2])).size, 41);
assert.ok(failures.every(m => verifiedAddresses.get(parseInt(m[2], 16)) === Number(m[1])));

const originalText = coff.sections[0];
const nopTail = orig.subarray(originalText.rawOffset + 1780, originalText.rawOffset + originalText.size);
assert.equal(nopTail.toString('hex'), '0f1f4400000f1f8000000000');
const constants = Buffer.from(coff.sections.find(s => s.name === '.rdata').rawHex, 'hex');
assert.deepEqual([64, 72, 80].map(i => constants.readDoubleLE(i)), [Math.fround(.99), Math.fround(1.01), 1]);
console.log(JSON.stringify({
  outcome: 'matched',
  checkedBytesOutsideRelocations: pe.matches.reduce((n, s) => n + s.comparedBytes, 0),
  checkedRelocations: verifiedAddresses.size,
  ghidraCoffFailuresMatchedViaLinkedPe: failures.length,
  procedureBytes: 1780,
  paddingBytes: nopTail.length,
  bssZeroFillBytes: bssSize,
  runtimeFunctionRows: pe.runtime.length,
  sourceSHA256: hash(source),
}, null, 2));