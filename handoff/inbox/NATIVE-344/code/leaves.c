#include <stdint.h>
extern unsigned char *const sim_image;

uint32_t sim_01360(void)
{
    return 0x1u;
}

uint32_t sim_019e0(void)
{
    return 0;
}

uintptr_t sim_01b20(void)
{
    return (uintptr_t)(sim_image + 0x51b18);
}

uintptr_t sim_01b30(void)
{
    return (uintptr_t)(sim_image + 0x51b20);
}

uint32_t sim_063a0(uint8_t value)
{
    *(uint32_t *)(sim_image + 0x50de0) = value;
    return value;
}

uint32_t sim_08b40(uint32_t value)
{
    uint32_t *slot = (uint32_t *)(sim_image + 0x51bc0);
    uint32_t before = *slot;
    *slot = value;
    return before;
}

uintptr_t sim_09fe0(void)
{
    return (uintptr_t)(sim_image + 0x401f8);
}

uintptr_t sim_09ff0(void)
{
    return (uintptr_t)(sim_image + 0x403d0);
}

uintptr_t sim_0c510(void)
{
    return *(const uintptr_t *)(sim_image + 0x51c20);
}

void sim_0c730(uint8_t value)
{
    sim_image[0x51c1d] = value;
}

void sim_0c740(uint8_t value)
{
    sim_image[0x51c1c] = value;
}

uint32_t sim_0f570(void)
{
    return *(const uint32_t *)(sim_image + 0x51dd0);
}

uint32_t sim_0fd20(void)
{
    return *(const uint32_t *)(sim_image + 0x51c18);
}

uint32_t sim_0fd60(void)
{
    return *(const uint32_t *)(sim_image + 0x4f720);
}

uintptr_t sim_14f90(const unsigned char *self)
{
    return *(const uintptr_t *)(self + 0x18);
}

uintptr_t sim_14fa0(void)
{
    return (uintptr_t)(sim_image + 0x50978);
}

uintptr_t sim_14fb0(void)
{
    return (uintptr_t)(sim_image + 0x509a8);
}

uintptr_t sim_19fd0(void)
{
    return *(const uintptr_t *)(sim_image + 0x3eb10);
}

uintptr_t sim_3c674(void)
{
    return (uintptr_t)(sim_image + 0x538b8);
}

