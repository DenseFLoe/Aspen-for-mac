"""Read compiler-declared catch continuations from non-separated MSVC x64 EH4 tables."""


MAX_TRY_BLOCKS = 1024
MAX_HANDLERS = 4096
MAX_MAP_ENTRIES = 16384


class Reader:
    def __init__(self, read_metadata, address):
        self.read_metadata = read_metadata
        self.address = address

    def take(self, size):
        raw = self.read_metadata(self.address, size)
        if len(raw) != size:
            raise ValueError("incomplete FH4 metadata")
        self.address += size
        return raw

    def byte(self):
        return self.take(1)[0]

    def rva(self):
        return int.from_bytes(self.take(4), "little", signed=True)

    def unsigned(self):
        first = self.byte()
        if first & 15 == 15:
            if first != 15:
                raise ValueError("invalid FH4 integer prefix")
            size = 5
            value = int.from_bytes(self.take(4), "little")
        else:
            # Each trailing one in the first byte adds a byte and a tag bit.
            size = 1
            while first & (1 << (size - 1)):
                size += 1
            tail = self.take(size - 1) if size > 1 else b""
            value = int.from_bytes(bytes([first]) + tail, "little") >> size
        if size > 1 and value < 1 << (7 * (size - 1)):
            raise ValueError("noncanonical FH4 integer")
        return value


def _map_extent(read_metadata, address, *, function_size=None):
    entries = Reader(read_metadata, address)
    count = entries.unsigned()
    if not 0 < count <= MAX_MAP_ENTRIES:
        raise ValueError("empty or oversized FH4 map")
    ip = 0
    for _ in range(count):
        value = entries.unsigned()
        if function_size is not None:
            # IP-to-state records use function-relative deltas and state + 1.
            ip += value
            if ip > function_size or entries.unsigned() > 0x80000000:
                raise ValueError("FH4 IP-to-state entry is outside its range")
        else:
            # The low two bits select an unwind action and its operand layout.
            kind = value & 3
            if kind and entries.rva() <= 0:
                raise ValueError("invalid FH4 unwind action pointer")
            if kind in (1, 2):
                entries.unsigned()
    return address, entries.address


def _add_handler_targets(table, count, begin, end, runtime_starts, type_descriptor_size, type_ranges, targets):
    for _ in range(count):
        flags = table.byte()
        address_count = (flags >> 4) & 3
        if flags & 0xC0 or address_count == 3:
            raise ValueError("unknown FH4 catch handler flags")
        if flags & 1:
            table.unsigned()  # Catch adjectives affect matching, not the destination.
        if flags & 2:
            type_rva = table.rva()
            size = type_descriptor_size(type_rva)
            if type_rva <= 0 or not size or size <= 16:
                raise ValueError("unverified FH4 catch type descriptor")
            type_ranges.add((type_rva, type_rva + size))
        if flags & 4:
            table.unsigned()  # Displacement of the caught object in the frame.
        handler = table.rva()
        if handler == begin or handler not in runtime_starts:
            raise ValueError("FH4 catch funclet has no independent runtime-function entry")
        for _ in range(address_count):
            target = table.rva() if flags & 8 else begin + table.unsigned()
            if not begin < target < end:
                raise ValueError("FH4 continuation is outside its runtime function")
            targets.setdefault(target, set()).add(handler)


def continuations(read_metadata, info_rva, begin, end, runtime_starts, *, type_descriptor_size):
    """Map each possible continuation to its metadata-backed catch funclets."""
    info = Reader(read_metadata, info_rva)
    flags = info.byte()
    if flags & 0x80:
        raise ValueError("unknown FH4 function flags")
    if flags & 3 or not flags & 0x10:  # Catch funclets, split functions, and functions without a try map.
        return {}
    if flags & 4:
        info.unsigned()
    unwind_map = None
    if flags & 8:
        unwind_map = info.rva()
    try_rva = info.rva()
    ip_map = info.rva()
    map_ranges = []
    if unwind_map is not None:
        map_ranges.append(_map_extent(read_metadata, unwind_map))
    if ip_map:
        map_ranges.append(_map_extent(read_metadata, ip_map, function_size=end - begin))

    tries = Reader(read_metadata, try_rva)
    count = tries.unsigned()
    if count > MAX_TRY_BLOCKS:
        raise ValueError("FH4 try table exceeds the supported count")
    tables = set()
    for _ in range(count):
        low, high, catch_high = (tries.unsigned() for _ in range(3))
        if not low <= high < catch_high:
            raise ValueError("invalid FH4 try state range")
        tables.add(tries.rva())

    ranges = [(info_rva, info.address), (try_rva, tries.address)]
    targets = {}
    type_ranges = set()
    remaining = MAX_HANDLERS
    for address in sorted(tables):
        table = Reader(read_metadata, address)
        count = table.unsigned()
        if count > remaining:
            raise ValueError("FH4 handler tables exceed the supported count")
        remaining -= count
        _add_handler_targets(table, count, begin, end, runtime_starts, type_descriptor_size, type_ranges, targets)
        ranges.append((address, table.address))
    ranges.extend(map_ranges)
    for start, stop in ranges:
        if len(read_metadata(start, stop - start)) != stop - start:
            raise ValueError("incomplete FH4 record")
    ordered = sorted(ranges + list(type_ranges))
    if any(before[1] > after[0] for before, after in zip(ordered, ordered[1:])):
        raise ValueError("overlapping FH4 records")
    return targets
