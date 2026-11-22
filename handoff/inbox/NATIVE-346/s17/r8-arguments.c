#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

enum ppexec_count_path {
    PPEXEC_SKIP,
    PPEXEC_INLINE_QWORDS,
    PPEXEC_COPY_BYTES,
    PPEXEC_FILL_BYTES,
};

struct ppexec_r8_arguments {
    enum ppexec_count_path path;
    uint64_t element_count;
    uint64_t r8_byte_count;
    uint8_t fill_byte;
};

/* Models count predicates and the bulk-call R8 value at the listed RVAs.
 * Addresses, caller-provided counts and buffer layout are supplied separately.
 */
bool ppexec_dynamic_r8_arguments(uint32_t site, int64_t count,
                                 struct ppexec_r8_arguments *arguments)
{
    enum ppexec_count_path bulk_path;
    uint8_t fill = 0;

    switch (site) {
    case 0x7135:
    case 0x71cc:
    case 0x7e5a:
    case 0x7e70:
    case 0x7e86:
    case 0x8013:
        bulk_path = PPEXEC_COPY_BYTES;
        break;
    case 0x565e:
        bulk_path = PPEXEC_FILL_BYTES;
        break;
    case 0x79fa:
        bulk_path = PPEXEC_FILL_BYTES;
        fill = 0x20;
        break;
    default:
        return false;
    }

    *arguments = (struct ppexec_r8_arguments){.path = PPEXEC_SKIP, .fill_byte = fill};
    if (count <= 0) {
        return true;
    }

    arguments->element_count = (uint64_t)count;
    if (count < 13) {
        arguments->path = PPEXEC_INLINE_QWORDS;
        return true;
    }

    arguments->path = bulk_path;
    /* Unsigned shift preserves the original AMD64 64-bit R8 bit pattern. */
    arguments->r8_byte_count = (uint64_t)count << 3;
    return true;
}
