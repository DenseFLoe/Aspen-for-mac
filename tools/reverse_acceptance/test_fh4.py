"""Controls for interpreting C++ exception continuation metadata."""
import struct
import unittest

if __package__:
    from . import fh4
else:
    import fh4


def encoded(number):
    for size in range(1, 5):
        if number < 128 ** size:
            return ((number << size) | (2 ** (size - 1) - 1)).to_bytes(size, "little")
    return b"\x0f" + struct.pack("<I", number)


def metadata(begin, catch, *, first=None, try_states=(0, 1, 2), handler_flags=0x15, malformed_tail=False,
             ip_map=0, type_rva=None):
    first = first if first is not None else begin + 0x180
    info_address, try_address, handler_address = 0x8030, 0x8090, 0x8230
    handlers = encoded(2) + bytes((handler_flags,)) + encoded(0)
    if type_rva is not None:
        handlers += struct.pack("<i", type_rva)
    handlers += encoded(96)
    handlers += struct.pack("<i", catch) + encoded(first - begin)
    handlers += bytes((0x28,)) + struct.pack("<iii", catch, begin + 0x74, begin + 0x90)
    if malformed_tail:
        handlers = handlers[:-1]
    blocks = {
        info_address: bytes((0x14,)) + encoded(300) + struct.pack("<ii", try_address, ip_map),
        try_address: encoded(1) + b"".join(map(encoded, try_states)) + struct.pack("<i", handler_address),
        handler_address: handlers,
    }

    def read(address, size):
        for start, data in blocks.items():
            offset = address - start
            if 0 <= offset and offset + size <= len(data):
                return data[offset:offset + size]
        raise ValueError("not mapped as original metadata")

    return read, info_address


class Fh4Tests(unittest.TestCase):
    def test_function_relative_and_image_relative_continuations(self):
        for begin, catch in ((0x2500, 0x7110), (0x4100, 0x5B30)):
            read, info = metadata(begin, catch)
            targets = fh4.continuations(read, info, begin, begin + 0x200, {begin, catch},
                                        type_descriptor_size=lambda _: None)
            self.assertEqual(targets, {begin + offset: {catch} for offset in (0x180, 0x74, 0x90)})

    def test_invalid_metadata_establishes_no_continuations(self):
        begin, catch = 0x3100, 0x4050
        for defect in ({"first": begin + 0x200}, {"try_states": (1, 0, 2)}, {"handler_flags": 0x35},
                       {"malformed_tail": True}):
            with self.subTest(defect=defect):
                read, info = metadata(begin, catch, **defect)
                with self.assertRaises(ValueError):
                    fh4.continuations(read, info, begin, begin + 0x200, {begin, catch},
                                      type_descriptor_size=lambda _: None)
        read, info = metadata(begin, catch)
        with self.assertRaisesRegex(ValueError, "runtime-function"):
            fh4.continuations(read, info, begin, begin + 0x200, {begin}, type_descriptor_size=lambda _: None)

    def test_pointer_into_parsed_record_does_not_create_a_path(self):
        begin, catch = 0x3100, 0x4050
        typed, unknown, aliased = 0x9020, 0x9A60, 0x8231
        valid_type = lambda address: 23 if address in (typed, aliased) else None
        read, info = metadata(begin, catch, handler_flags=0x17, type_rva=typed)
        self.assertIn(begin + 0x180, fh4.continuations(read, info, begin, begin + 0x200, {begin, catch},
                                                      type_descriptor_size=valid_type))
        for config in ({"ip_map": aliased}, {"handler_flags": 0x17, "type_rva": aliased},
                       {"handler_flags": 0x17, "type_rva": unknown}):
            with self.subTest(config=config):
                read, info = metadata(begin, catch, **config)
                with self.assertRaises(ValueError):
                    fh4.continuations(read, info, begin, begin + 0x200, {begin, catch},
                                      type_descriptor_size=valid_type)

    def test_noncanonical_integer_is_not_evidence(self):
        data = bytes.fromhex("01 00")
        with self.assertRaisesRegex(ValueError, "noncanonical"):
            fh4.Reader(lambda address, size: data[address:address + size], 0).unsigned()

    def test_optional_maps_require_every_declared_record(self):
        address = 0x8120
        full = b"".join(map(encoded, (2, 0, 0, 75, 2)))
        def read(data):
            return lambda start, size: data[start - address:start - address + size]

        self.assertEqual(fh4._map_extent(read(full), address, function_size=100),
                         (address, address + len(full)))
        for invalid in (b"\x0f", b"\0", full[:-1]):
            with self.subTest(invalid=invalid), self.assertRaises(ValueError):
                fh4._map_extent(read(invalid), address, function_size=100)
