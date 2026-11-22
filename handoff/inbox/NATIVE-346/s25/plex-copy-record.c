#include <stddef.h>
#include <stdint.h>

struct ppexec_plex_copy_record_fields {
    uint8_t unknown_00[0x20];
    uint64_t first_one_based_word;
    uint8_t unknown_28[0x10];
    uint64_t second_one_based_word;
    uint8_t unknown_40[0x20];
    uint64_t third_one_based_word;
};

_Static_assert(offsetof(struct ppexec_plex_copy_record_fields, first_one_based_word) == 0x20,
               "ppexec 0x7df5");
_Static_assert(offsetof(struct ppexec_plex_copy_record_fields, second_one_based_word) == 0x38,
               "ppexec 0x7dfa");
_Static_assert(offsetof(struct ppexec_plex_copy_record_fields, third_one_based_word) == 0x60,
               "ppexec 0x7df0");

/* This reproduces the two 64-bit index additions in the original copy path. */
uint64_t ppexec_plex_source_word(uint64_t record_index, uint64_t one_based_word)
{
    return record_index + (one_based_word - 1);
}
