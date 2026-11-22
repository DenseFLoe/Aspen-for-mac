#include <stdint.h>

/* module_base is the loaded image base, supplied by the caller.
   Functions below model only the documented x64 register result. */
extern const unsigned char *module_base;

uint32_t result_01520(void)
{
    return *(const uint32_t *)(module_base + 0x5279c);
}

uint32_t result_01530(void)
{
    return *(const uint32_t *)(module_base + 0x534f4);
}

uint32_t result_01540(void)
{
    return *(const uint32_t *)(module_base + 0x52798);
}

uintptr_t result_01cd0(void)
{
    return (uintptr_t)(module_base + 0x534d8);
}

uint32_t result_01d40(void)
{
    return 0;
}

uint32_t result_01f80(void)
{
    return 1;
}

uintptr_t result_33bb0(void)
{
    return (uintptr_t)(module_base + 0x429c0);
}

uintptr_t result_33bc0(void)
{
    return (uintptr_t)(module_base + 0x42464);
}

uint32_t result_33bd0(void)
{
    return *(const uint32_t *)(module_base + 0x52850);
}

uintptr_t result_33c00(void)
{
    return (uintptr_t)(module_base + 0x3ad3c);
}

uintptr_t result_360a8(void)
{
    return (uintptr_t)(module_base + 0x547b0);
}

uintptr_t result_360cc(void)
{
    return (uintptr_t)(module_base + 0x54870);
}

