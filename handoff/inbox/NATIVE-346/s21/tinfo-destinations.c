#include <stddef.h>
#include <stdint.h>

typedef struct {
    size_t begin;
    size_t end;
} ByteRange;

typedef struct {
    ByteRange tinfo_copy_destinations[3];
    ByteRange pgmnfo_fill_destination;
    uint8_t fill_value;
} InitializedDestinations;

/* Offsets relative to the original symbols, after the observed initialization. */
InitializedDestinations ppexec_initialized_tinfo_destinations(void)
{
    enum { initialized_count = 64, bytes_per_word = 8 };
    const size_t bytes = initialized_count * bytes_per_word;
    const InitializedDestinations destinations = {
        .tinfo_copy_destinations = {
            {0x2f0, 0x2f0 + bytes},
            {0x4f8, 0x4f8 + bytes},
            {0x0f0, 0x0f0 + bytes},
        },
        .pgmnfo_fill_destination = {0x018, 0x018 + bytes},
        .fill_value = 0x20,
    };
    return destinations;
}
