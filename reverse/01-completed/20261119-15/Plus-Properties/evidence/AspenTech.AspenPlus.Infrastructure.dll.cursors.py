"""Recover the six 32x32, 24-bit animated cursors in AspenPlus Infrastructure 41.0.0.614.

Run this script with an original DLL and a new local directory. It writes editable
JSON and verifies that each decoded animation rebuilds byte-for-byte. The JSON
contains the original imagery and belongs in the local resource archive.
"""
import argparse
from hashlib import sha256
import itertools
import json
from pathlib import Path
import struct

EXPECTED = '052e0a0e54d287397457200d4bdb87a0051ecff751f42d941114fa5e3c02908f'
BASENAME = 'AspenTech.AspenPlus.Infrastructure.dll'
CURSOR_ENTRY = struct.Struct('<4B2H2I')
DIB = struct.Struct('<IiiHHIIiiII')


def digest(data):
    return sha256(data).hexdigest()


def chunks(data):
    offset = 0
    while offset < len(data):
        name, size = struct.unpack_from('<4sI', data, offset)
        start = offset + 8
        end = start + size
        assert end <= len(data)
        assert data[end:end + size % 2] == b'\x00' * (size % 2)
        yield name, data[start:end]
        offset = end + size % 2
    assert offset == len(data)


def chunk(name, data):
    return struct.pack('<4sI', name, len(data)) + data + bytes(len(data) % 2)


def frame_fields(raw):
    assert struct.unpack_from('<HHH', raw) == (0, 2, 1)
    width, height, colors, reserved, x, y, nbytes, offset = CURSOR_ENTRY.unpack_from(raw, 6)
    assert (width, height, colors, reserved, offset, nbytes) == (32, 32, 0, 0, 22, 3240)
    assert DIB.unpack_from(raw, offset) == (40, 32, 64, 1, 24, 0, 3200, 0, 0, 0, 0)
    assert len(raw) == offset + nbytes
    rgb = raw[offset + DIB.size:-128]
    mask = raw[-128:]
    rows = []
    for y_source in reversed(range(height)):
        row = []
        for x_source in range(width):
            pos = 3 * (y_source * width + x_source)
            color = '#' + rgb[pos:pos + 3][::-1].hex()
            bit = (mask[y_source * 4 + x_source // 8] >> (7 - x_source % 8)) & 1
            row.append((color, bit))
        rows.append([[sum(1 for _ in run), *pixel] for pixel, run in itertools.groupby(row)])
    return dict(hotspot=[x, y], rows=rows)


def encode_frame(frame):
    xor = bytearray()
    mask = bytearray()
    assert len(frame['rows']) == 32
    for runs in reversed(frame['rows']):
        assert all(count > 0 and bit in (0, 1) for count, color, bit in runs)
        assert sum(count for count, color, bit in runs) == 32
        mask_bits = 0
        for count, color, bit in runs:
            assert len(color) == 7 and color.startswith('#')
            xor.extend(bytes.fromhex(color[1:])[::-1] * count)
            mask_bits = (mask_bits << count) | (((1 << count) - 1) * bit)
        mask.extend(mask_bits.to_bytes(4, 'big'))
    dib = DIB.pack(40, 32, 64, 1, 24, 0, 3200, 0, 0, 0, 0) + xor + mask
    return struct.pack('<HHH', 0, 2, 1) + CURSOR_ENTRY.pack(32, 32, 0, 0, *frame['hotspot'], len(dib), 22) + dib


def uints(data):
    return list(struct.unpack('<' + 'I' * (len(data) // 4), data))


def integers(items):
    return struct.pack('<' + 'I' * len(items), *items)


def decode(data):
    (tag, raw), = chunks(data)
    assert tag == b'RIFF' and raw[:4] == b'ACON'
    members = list(chunks(raw[4:]))
    keys = [key for key, _ in members]
    assert keys in ([b'anih', b'rate', b'seq ', b'LIST'], [b'anih', b'rate', b'LIST'], [b'anih', b'LIST'])
    items = dict(members)
    header_bytes, frame_count, steps, width, height, depth, planes, rate, flags = uints(items[b'anih'])
    assert (header_bytes, width, height, depth, planes) == (36, 0, 0, 4, 1)
    animation = items[b'LIST']
    assert animation[:4] == b'fram'
    frames = []
    for tag, icon in chunks(animation[4:]):
        assert tag == b'icon'
        frames.append(frame_fields(icon))
    assert len(frames) == frame_count and flags == (3 if b'seq ' in items else 1)
    duration = uints(items[b'rate']) if b'rate' in items else None
    sequence = uints(items[b'seq ']) if b'seq ' in items else None
    assert duration is None or len(duration) == steps
    assert steps == (len(sequence) if sequence else len(frames))
    assert all(index < frame_count for index in sequence or [])
    return dict(default_jiffies=rate, per_step_jiffies=duration, explicit_frame_sequence=sequence, frames=frames)


def encode(animation):
    frames = animation['frames']
    sequence = animation['explicit_frame_sequence']
    rates = animation['per_step_jiffies']
    steps = len(sequence) if sequence else len(frames)
    header = [36, len(frames), steps, 0, 0, 4, 1, animation['default_jiffies'], 3 if sequence is not None else 1]
    data = chunk(b'anih', integers(header))
    if rates is not None:
        assert len(rates) == steps
        data += chunk(b'rate', integers(rates))
    if sequence is not None:
        data += chunk(b'seq ', integers(sequence))
    data += chunk(b'LIST', b'fram' + b''.join(chunk(b'icon', encode_frame(f)) for f in frames))
    return chunk(b'RIFF', b'ACON' + data)


def export(original, target):
    import dnfile
    raw = original.read_bytes()
    assert digest(raw) == EXPECTED
    mod = dnfile.dnPE(data=raw)
    manifest = mod.net.mdtables.ManifestResource.rows
    assert len(manifest) == len(mod.net.resources) == 6
    rows, animations = [], {}
    for index, (row, resource) in enumerate(zip(manifest, mod.net.resources), start=1):
        name = str(row.Name)
        assert name == str(resource.name) and name.endswith('.ani') and row.Implementation is None and name not in animations
        animation = decode(resource.data)
        rebuilt = encode(animation)
        assert rebuilt == resource.data and len(rebuilt) == resource.size
        sequence = animation['explicit_frame_sequence'] or list(range(len(animation['frames'])))
        rates = animation['per_step_jiffies'] or [animation['default_jiffies']] * len(sequence)
        rows.append(dict(name=name, token=f'0x280000{index:02X}', manifest_offset=row.Offset, bytes=resource.size,
                         sha256=digest(resource.data), rebuilt_sha256=digest(rebuilt), frames=len(animation['frames']),
                         steps=len(sequence), frame_sequence=sequence, jiffies=rates, size=[32, 32], depth=24,
                         hotspots=sorted(set(tuple(f['hotspot']) for f in animation['frames'])), byte_equal=True))
        animations[name] = animation
    target.mkdir(exist_ok=False, parents=True)
    output = target / (BASENAME + '.cursors.json')
    document = dict(source_sha256=EXPECTED, model='top-down rows of pixel runs [width, XOR #rrggbb, AND mask bit], 60 jiffies per second', animations=animations)
    output.write_text(json.dumps(document, separators=(',', ':')) + '\n', encoding='utf-8')
    saved = json.loads(output.read_text(encoding='utf-8'))['animations']
    assert all(encode(saved[str(r.name)]) == r.data for r in mod.net.resources)
    evidence = dict(assembly=original.name, original_sha256=EXPECTED, dnfile=dnfile.__version__, resource_rows=rows,
                    recovered_json=output.name, recovered_json_sha256=digest(output.read_bytes()),
                    script_sha256=digest(Path(__file__).read_bytes()), file_readback_all_equal=True)
    (target / 'cursor-checks.json').write_text(json.dumps(evidence, indent=2) + '\n', encoding='utf-8')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('assembly', type=Path)
    parser.add_argument('new_local_directory', type=Path)
    args = parser.parse_args()
    export(args.assembly, args.new_local_directory)


if __name__ == '__main__':
    main()
