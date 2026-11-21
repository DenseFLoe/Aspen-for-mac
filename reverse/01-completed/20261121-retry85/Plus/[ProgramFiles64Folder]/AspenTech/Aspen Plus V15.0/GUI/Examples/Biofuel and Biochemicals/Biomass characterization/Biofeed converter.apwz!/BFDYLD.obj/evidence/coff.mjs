import fs from 'node:fs';
import crypto from 'node:crypto';
const bytes = fs.readFileSync(process.argv[2]);
const u16 = offset => bytes.readUInt16LE(offset);
const u32 = offset => bytes.readUInt32LE(offset);
const hex = n => '0x' + n.toString(16);
const ascii = (offset, length) => bytes.toString('ascii', offset, offset + length).split('\0')[0];
const symbolBase = u32(8);
const symbolCount = u32(12);
const strings = symbolBase + 18 * symbolCount;
const stringEnd = strings + u32(strings);
const getString = offset => ascii(strings + offset, stringEnd - (strings + offset));
const file = {
  sha256: crypto.createHash('sha256').update(bytes).digest('hex'),
  size: bytes.length, machine: hex(u16(0)), optionalHeaderSize: u16(16),
  timestamp: new Date(u32(4) * 1000).toISOString(),
  symbolBase, symbolCount, sections: [], symbols: [],
};
const byIndex = new Map();
for (let index = 0; index < symbolCount;) {
  const offset = symbolBase + index * 18;
  const auxCount = bytes[offset + 17];
  const symbol = {
    index, name: u32(offset) ? ascii(offset, 8) : getString(u32(offset + 4)),
    value: u32(offset + 8), section: bytes.readInt16LE(offset + 12),
    type: hex(u16(offset + 14)), storage: bytes[offset + 16], aux: [],
  };
  for (let aux = 0; aux < auxCount; aux++) {
    const start = offset + (aux + 1) * 18;
    symbol.aux.push(bytes.subarray(start, start + 18).toString('hex'));
  }
  byIndex.set(index, symbol);
  file.symbols.push(symbol);
  index += 1 + auxCount;
}
for (let i = 0; i < u16(2); i++) {
  const offset = 20 + u16(16) + 40*i;
  const shortName = ascii(offset, 8);
  const name = shortName.startsWith('/') ? getString(Number(shortName.slice(1))) : shortName;
  const rawOffset = u32(offset + 20);
  const size = u32(offset + 16);
  const raw = bytes.subarray(rawOffset, rawOffset + size);
  const section = { index: i + 1, name, size, rawOffset, flags: hex(u32(offset + 36)), relocations: [] };
  if (rawOffset) section.sha256 = crypto.createHash('sha256').update(raw).digest('hex');
  if (rawOffset && name !== '.text') section.rawHex = raw.toString('hex');
  if (name === '.drectve') section.directives = raw.toString('ascii').trim();
  for (let r = 0; r < u16(offset + 32); r++) {
    const entry = u32(offset + 24) + r * 10;
    const position = u32(entry);
    const symbolIndex = u32(entry + 4);
    const type = u16(entry + 8);
    const target = byIndex.get(symbolIndex);
    if (!target || position + 4 > size) throw Error('Invalid relocation');
    const addend = raw.readInt32LE(position);
    section.relocations.push({
      offset: hex(position), type: hex(type), symbolIndex, symbol: target.name,
      targetSection: target.section, symbolValue: target.value, addend,
    });
  }
  file.sections.push(section);
}
console.log(JSON.stringify(file, null, 2));