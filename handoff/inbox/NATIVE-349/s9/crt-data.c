/* AMD64 PE field widths in the CRT lifecycle routines.
   Original RVAs in symbol names preserve identity across the COFF comparison. */
typedef unsigned long long word64;
typedef struct { word64 slots[3]; } onexit_storage;
_Static_assert(sizeof(onexit_storage) == 24, "three AMD64 words per table");

int rva_34900;                /* active attach count, signed comparison */
unsigned int rva_34930;       /* lifecycle state */
unsigned char rva_34941;      /* onexit tables initialized */
onexit_storage rva_34948;
onexit_storage rva_34960;
const word64 rva_29e90[2] = {~0ULL, ~0ULL};
