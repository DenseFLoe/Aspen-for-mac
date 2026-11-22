/* Static x64 models. External declarations show observed uses at these call sites.
   The original prototypes of imported and unresolved functions remain to be verified. */
#include <stdint.h>
#include <stddef.h>

extern uint32_t prop_retrieve_results;
extern unsigned char *topfinfo;
extern uint32_t image_dword_51c00;
extern void GRbumpsumcount(void);
extern int GRinqgpd(const void *observed_rcx);
extern void GRsetpgc(uint32_t), GRsetnec(uint32_t), GRsetcpt(uint32_t);
extern void GRsetgfl(void);
extern void sub_31540(void *);
extern int sub_15a10(int, void *);
extern int sub_210b0(int), sub_20e10(int,int), sub_21e70(int,int,int);
extern int sub_20ae0(int,int), sub_20c70(int), sub_21b80(int,int,void *);
extern int sub_218f0(int,int), sub_21600(int,int), sub_21fa0(int,int);
extern int sub_20b10(int,int), sub_22060(int,void *);
extern const uint32_t *SEGetSettingValue(const char *, int);
extern void CreateApwnLibrariesTest(void);

/* RVA 0x22a50. The table contains 19 unsigned image-relative addresses. */
int sim_dispatch(uint32_t operation, int arg2, int arg3, void *arg4)
{
    switch (operation) {
    case 1: return sub_210b0(arg2);
    case 2: return sub_21e70(arg2, arg3, 1);
    case 5: return sub_20c70(arg2);
    case 7:
    case 17: return sub_20e10(arg2, arg3);
    case 8:
    case 18: return sub_20ae0(arg2, arg3);
    case 12: {
        const uint32_t *setting = SEGetSettingValue("SkipEngineLoadOnDocumentLoad", 0);
        if (setting && *setting) {
            CreateApwnLibrariesTest();
            return 0;
        }
        return sub_21b80(arg2, arg3, arg4);
    }
    case 13: return sub_218f0(arg2, arg3);
    case 14: return sub_21600(arg2, arg3);
    case 15: return sub_21fa0(arg2, arg3);
    case 16: return sub_20b10(arg2, arg3);
    case 19: return sub_22060(arg3, arg4);
    default: return 0;
    }
}

/* RVA 0x109c0. The first helper's result does not participate in the branch. */
int submit_helper(void)
{
    image_dword_51c00 = 1;
    sub_31540(NULL);
    if (sim_dispatch(1, 1, 0, NULL) != 0)
        return 0;
    GRsetgfl();
    return sub_15a10(9, NULL) == 0;
}

#define FIELD32(record, offset) (*(uint32_t *)((record) + (offset)))

/* RVA 0x39c00, ordinal 93. Reload the imported record pointer after each call
   at the same sites as the binary. Offset names are intentionally numeric. */
int submit_proprun(void)
{
    GRbumpsumcount();
    prop_retrieve_results = 1;
    unsigned char *initial = topfinfo;
    uint32_t saved_380 = FIELD32(initial, 0x380);
    uint32_t flag = 1;
    if (FIELD32(initial, 0x15c) == 0 && GRinqgpd(initial) != 0)
        flag = 0;
    unsigned char *record = topfinfo;
    uint32_t saved_15c = FIELD32(record, 0x15c);
    uint32_t saved_708 = FIELD32(record, 0x708);
    uint32_t saved_150 = FIELD32(record, 0x150);
    FIELD32(record, 0x380) = 0x2d9;
    int result = submit_helper();
    FIELD32(topfinfo, 0x380) = saved_380;
    GRsetpgc(flag);
    FIELD32(topfinfo, 0x15c) = saved_15c;
    GRsetnec(saved_708);
    GRsetcpt(saved_150);
    return result;
}
