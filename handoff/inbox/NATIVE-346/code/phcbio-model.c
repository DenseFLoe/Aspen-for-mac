/* Source-level interpretation of PPEXEC_PHCBIO at RVA 0x2cc0.
   State names below use the identities from the PE import table or RVAs.
   The byte-verified Windows AMD64 implementation is in ppexec.c. */
#include <stdint.h>
#include <string.h>

typedef uint64_t (*dms_locati_fn)(const void *cell);

struct ppexec_phcbio_state {
    dms_locati_fn dms_locati;             /* thunk 0x11354, IAT 0x15508 */
    const unsigned char *dms_plex;        /* IAT 0x154f8 */
    uint64_t *dms_ipoff6;                 /* IAT 0x15460 */
    const void *cell_16c10;
    uint64_t *cell_1ebf0;
    uint64_t *cell_1ebe8;
};

static uint64_t plex_entry(const unsigned char *plex, uint64_t index, uint64_t displacement)
{
    uint64_t value;
    const uintptr_t address = (uintptr_t)plex + index * UINT64_C(8) + displacement;
    memcpy(&value, (const void *)address, sizeof value);
    return value;
}

/* The return models RAX on exit. The original PE does not specify the
   language-level return type. On Windows x64 the table is little-endian. */
uint64_t ppexec_phcbio_result(struct ppexec_phcbio_state *state)
{
    uint64_t index = state->dms_locati(state->cell_16c10);
    const unsigned char *plex = state->dms_plex;
    *state->cell_1ebf0 = plex_entry(plex, index, 0x630);

    index = state->dms_locati(state->cell_1ebf0);
    uint64_t result = plex_entry(plex, index, 0x50);
    *state->cell_1ebe8 = result;
    if (result != 0 && (result >> 63) == 0) {
        result = state->dms_locati(state->cell_1ebe8) - UINT64_C(1);
        *state->dms_ipoff6 = result;
    }
    return result;
}

