/* Windows AMD64 entry point at RVA 0x44a0. The parameters' locations and
   the signed return checks are pinned in Ikc2Bkp.dll.md and the instruction listing. */
#include <stdint.h>

extern void *ikc_state_slot(int32_t key);                       /* 0x21a60 */
extern int32_t ikc_read_input(const char *path);                /* 0x22da0 */
extern int32_t ikc_write_output(const char *path, int32_t mode);/* 0x8a30 */

int32_t Ikc2Bkp(const char *input_path, const char *output_path, int32_t mode)
{
    ikc_state_slot(-1);
    int32_t status = ikc_read_input(input_path);
    if (status < 0)
        return status;
    status = ikc_write_output(output_path, mode);
    if (status < 0)
        return status;
    ikc_state_slot(-1);
    return 0;
}
