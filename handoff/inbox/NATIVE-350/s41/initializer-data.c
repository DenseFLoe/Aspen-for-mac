/* Read-only CPUID inputs and loader-zeroed capability records. */
#include <stdint.h>

const unsigned char intel_vendor_signature[16] __attribute__((aligned(16))) =
    "GenuineIntel";

struct cache_descriptor {
    uint32_t encoding;
    uint32_t capacity_kib;
};

const struct cache_descriptor cache_descriptors[255] __attribute__((aligned(16))) = {
    [0x0a] = { 0x00808101, 8 },
    [0x0c] = { 0x01008101, 16 },
    [0x0d] = { 0x01008201, 16 },
    [0x0e] = { 0x01808201, 24 },
    [0x10] = { 0x01008101, 16 },
    [0x1a] = { 0x01808202, 96 },
    [0x1d] = { 0x00808202, 128 },
    [0x21] = { 0x02008202, 256 },
    [0x22] = { 0x01010203, 512 },
    [0x23] = { 0x02010203, 1024 },
    [0x24] = { 0x04008202, 1024 },
    [0x25] = { 0x02010203, 2048 },
    [0x29] = { 0x02010203, 4096 },
    [0x2c] = { 0x02008201, 32 },
    [0x39] = { 0x01008202, 128 },
    [0x3a] = { 0x01808202, 192 },
    [0x3b] = { 0x00808202, 128 },
    [0x3c] = { 0x01008202, 256 },
    [0x3d] = { 0x01808202, 384 },
    [0x3e] = { 0x01008202, 512 },
    [0x3f] = { 0x01008202, 256 },
    [0x41] = { 0x01008102, 128 },
    [0x42] = { 0x01008102, 256 },
    [0x43] = { 0x01008102, 512 },
    [0x44] = { 0x01008102, 1024 },
    [0x45] = { 0x01008102, 2048 },
    [0x46] = { 0x01008203, 4096 },
    [0x47] = { 0x02008203, 8192 },
    [0x48] = { 0x03008202, 3072 },
    [0x49] = { 0x04008202, 4096 },
    [0x4a] = { 0x03008203, 6144 },
    [0x4b] = { 0x04008203, 8192 },
    [0x4c] = { 0x03008203, 12228 },
    [0x4d] = { 0x04008203, 16384 },
    [0x4e] = { 0x06008202, 6144 },
    [0x60] = { 0x02008201, 16 },
    [0x62] = { 0x02008201, 32 },
    [0x66] = { 0x01010201, 8 },
    [0x67] = { 0x01010201, 16 },
    [0x68] = { 0x01010201, 32 },
    [0x69] = { 0x01010201, 64 },
    [0x78] = { 0x01008202, 1024 },
    [0x79] = { 0x02010202, 128 },
    [0x7a] = { 0x02010202, 256 },
    [0x7b] = { 0x02010202, 512 },
    [0x7c] = { 0x02010202, 1024 },
    [0x7d] = { 0x02010202, 2048 },
    [0x7e] = { 0x03008402, 256 },
    [0x7f] = { 0x00808202, 512 },
    [0x80] = { 0x02008202, 512 },
    [0x81] = { 0x02008102, 128 },
    [0x82] = { 0x02008102, 256 },
    [0x83] = { 0x02008102, 512 },
    [0x84] = { 0x02008102, 1024 },
    [0x85] = { 0x02008102, 2048 },
    [0x86] = { 0x01008202, 512 },
    [0x87] = { 0x02008202, 1024 },
    [0x88] = { 0x01008203, 2048 },
    [0x89] = { 0x01008203, 4096 },
    [0x8a] = { 0x01008203, 8192 },
    [0x8d] = { 0x03008403, 3072 },
    [0xd0] = { 0x01008203, 512 },
    [0xd1] = { 0x01008203, 1024 },
    [0xd2] = { 0x01008203, 2048 },
    [0xd6] = { 0x02008203, 1024 },
    [0xd7] = { 0x02008203, 2048 },
    [0xd8] = { 0x02008203, 4096 },
    [0xdc] = { 0x03008203, 2048 },
    [0xdd] = { 0x03008203, 4096 },
    [0xde] = { 0x03008203, 8192 },
    [0xe2] = { 0x04008203, 2048 },
    [0xe3] = { 0x04008203, 4096 },
    [0xe4] = { 0x04008203, 8192 },
    [0xea] = { 0x06008203, 12288 },
    [0xeb] = { 0x06008203, 18432 },
    [0xec] = { 0x06008203, 24576 },
};

struct capability_record {
    uint32_t capacity_kib;
    uint32_t line_size;
    uint32_t partitions;
    uint32_t ways;
};

struct capability_state {
    uint32_t intel_vendor;
    uint32_t max_basic_leaf;
    uint32_t reserved_dword;
    uint32_t ready;
    struct capability_record level[3];
};

struct capability_state capability_records __attribute__((aligned(16)));

_Static_assert(sizeof(struct cache_descriptor) == 8, "descriptor stride");
_Static_assert(sizeof(struct capability_record) == 16, "record stride");
_Static_assert(sizeof(struct capability_state) == 64, "metadata plus three records");
