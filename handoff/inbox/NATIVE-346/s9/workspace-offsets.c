#include <stdint.h>

/* Arithmetic shared by the three recovered workspace-offset initializers.
 * destination[] supplies pointers to separate labels or output arguments in
 * machine-store order. It does not describe the DLL's physical data layout.
 * The caller supplies the three values at their documented load sites.
 */
void ppexec_workspace_offsets(uint64_t integer_base, uint64_t stride,
                              uint64_t workspace_base, uint64_t *destination[13])
{
    *destination[0] = integer_base - 1;
    *destination[1] = integer_base - 1 + stride;
    uint64_t offset = workspace_base - 1;
    for (unsigned slot = 2; slot < 13; ++slot) {
        *destination[slot] = offset;
        offset += stride;
    }
}
