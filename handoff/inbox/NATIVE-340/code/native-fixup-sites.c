/* NATIVE-340: editable implementations of the 122 .nep dispatch stubs.
   Each function is a naked indirect tail jump through its CLR VTableFixups slot:
   jmp qword ptr [rip+slot]. The slot is filled by the loader, so the landing
   address is a runtime value; the static slot value is the MethodDef below. */
/* FUNC 00005004  native -> managed via CLR VTableFixups slot 0x19018
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19018, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000001 (std.exception.{ctor}, RVA 0x10a0)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019018[];

__attribute__((naked, used, noinline)) void fixup_stub_00005004(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019018(%rip)");
}

/* FUNC 00005014  native -> managed via CLR VTableFixups slot 0x19028
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19028, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600000A (std.exception_ptr.{ctor}, RVA 0x1120)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019028[];

__attribute__((naked, used, noinline)) void fixup_stub_00005014(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019028(%rip)");
}

/* FUNC 00005024  native -> managed via CLR VTableFixups slot 0x19050
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19050, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600000C (std.bad_alloc.{ctor}, RVA 0x1138)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019050[];

__attribute__((naked, used, noinline)) void fixup_stub_00005024(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019050(%rip)");
}

/* FUNC 00005034  native -> managed via CLR VTableFixups slot 0x19078
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19078, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600000B (std.bad_array_new_length.{ctor}, RVA 0x1198)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019078[];

__attribute__((naked, used, noinline)) void fixup_stub_00005034(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019078(%rip)");
}

/* FUNC 00005044  native -> managed via CLR VTableFixups slot 0x19088
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19088, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x060000A3 (<MarshalCopy>, RVA 0x1224)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019088[];

__attribute__((naked, used, noinline)) void fixup_stub_00005044(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019088(%rip)");
}

/* FUNC 00005054  native -> managed via CLR VTableFixups slot 0x19098
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19098, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x060000A4 (<MarshalDestroy>, RVA 0x123c)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019098[];

__attribute__((naked, used, noinline)) void fixup_stub_00005054(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019098(%rip)");
}

/* FUNC 00005064  native -> managed via CLR VTableFixups slot 0x190c0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x190c0, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600000F (std.bad_variant_access.{ctor}, RVA 0x1250)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000190C0[];

__attribute__((naked, used, noinline)) void fixup_stub_00005064(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000190C0(%rip)");
}

/* FUNC 00005074  native -> managed via CLR VTableFixups slot 0x190e8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x190e8, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000013 (std.bad_cast.{ctor}, RVA 0x12b0)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000190E8[];

__attribute__((naked, used, noinline)) void fixup_stub_00005074(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000190E8(%rip)");
}

/* FUNC 00005084  native -> managed via CLR VTableFixups slot 0x19110
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19110, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000019 (std.bad_weak_ptr.{ctor}, RVA 0x1324)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019110[];

__attribute__((naked, used, noinline)) void fixup_stub_00005084(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019110(%rip)");
}

/* FUNC 00005094  native -> managed via CLR VTableFixups slot 0x19120
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19120, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000014 (std._Iterator_base12.{ctor}, RVA 0x1700)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019120[];

__attribute__((naked, used, noinline)) void fixup_stub_00005094(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019120(%rip)");
}

/* FUNC 000050A4  native -> managed via CLR VTableFixups slot 0x19130
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19130, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000020 (SaveMergennFiles, RVA 0x1a80)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019130[];

__attribute__((naked, used, noinline)) void fixup_stub_000050A4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019130(%rip)");
}

/* FUNC 000050B4  native -> managed via CLR VTableFixups slot 0x19140
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19140, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600002A (new, RVA 0x1090)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019140[];

__attribute__((naked, used, noinline)) void fixup_stub_000050B4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019140(%rip)");
}

/* FUNC 000050C4  native -> managed via CLR VTableFixups slot 0x19150
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19150, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000004 (std.exception.__vecDelDtor, RVA 0x1a9c)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019150[];

__attribute__((naked, used, noinline)) void fixup_stub_000050C4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019150(%rip)");
}

/* FUNC 000050D4  native -> managed via CLR VTableFixups slot 0x19160
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19160, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000003 (std.exception.what, RVA 0x1afc)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019160[];

__attribute__((naked, used, noinline)) void fixup_stub_000050D4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019160(%rip)");
}

/* FUNC 000050E4  native -> managed via CLR VTableFixups slot 0x19170
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19170, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000002 (std.exception.{dtor}, RVA 0x10cc)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019170[];

__attribute__((naked, used, noinline)) void fixup_stub_000050E4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019170(%rip)");
}

/* FUNC 000050F4  native -> managed via CLR VTableFixups slot 0x19180
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19180, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000006 (std.bad_alloc.{dtor}, RVA 0x10ec)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019180[];

__attribute__((naked, used, noinline)) void fixup_stub_000050F4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019180(%rip)");
}

/* FUNC 00005104  native -> managed via CLR VTableFixups slot 0x19190
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19190, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000009 (std.exception_ptr.{dtor}, RVA 0x110c)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019190[];

__attribute__((naked, used, noinline)) void fixup_stub_00005104(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019190(%rip)");
}

/* FUNC 00005114  native -> managed via CLR VTableFixups slot 0x191a0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x191a0, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000005 (std.bad_alloc.__vecDelDtor, RVA 0x1b1c)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000191A0[];

__attribute__((naked, used, noinline)) void fixup_stub_00005114(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000191A0(%rip)");
}

/* FUNC 00005124  native -> managed via CLR VTableFixups slot 0x191b0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x191b0, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000007 (std.bad_array_new_length.__vecDelDtor, RVA 0x1b7c)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000191B0[];

__attribute__((naked, used, noinline)) void fixup_stub_00005124(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000191B0(%rip)");
}

/* FUNC 00005134  native -> managed via CLR VTableFixups slot 0x191c0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x191c0, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000010 (std.bad_variant_access.__vecDelDtor, RVA 0x1bfc)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000191C0[];

__attribute__((naked, used, noinline)) void fixup_stub_00005134(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000191C0(%rip)");
}

/* FUNC 00005144  native -> managed via CLR VTableFixups slot 0x191d0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x191d0, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600000D (std.bad_variant_access.what, RVA 0x1c7c)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000191D0[];

__attribute__((naked, used, noinline)) void fixup_stub_00005144(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000191D0(%rip)");
}

/* FUNC 00005154  native -> managed via CLR VTableFixups slot 0x191e0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x191e0, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000011 (std.bad_cast.__vecDelDtor, RVA 0x1c90)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000191E0[];

__attribute__((naked, used, noinline)) void fixup_stub_00005154(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000191E0(%rip)");
}

/* FUNC 00005164  native -> managed via CLR VTableFixups slot 0x191f0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x191f0, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000015 (std._Iterator_base12.=, RVA 0x1310)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000191F0[];

__attribute__((naked, used, noinline)) void fixup_stub_00005164(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000191F0(%rip)");
}

/* FUNC 00005174  native -> managed via CLR VTableFixups slot 0x19200
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19200, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000017 (std.bad_weak_ptr.__vecDelDtor, RVA 0x1d10)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019200[];

__attribute__((naked, used, noinline)) void fixup_stub_00005174(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019200(%rip)");
}

/* FUNC 00005184  native -> managed via CLR VTableFixups slot 0x19210
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19210, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000016 (std.bad_weak_ptr.what, RVA 0x1d90)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019210[];

__attribute__((naked, used, noinline)) void fixup_stub_00005184(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019210(%rip)");
}

/* FUNC 00005194  native -> managed via CLR VTableFixups slot 0x19220
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19220, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600001A (PtrToStringChars, RVA 0x1384)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019220[];

__attribute__((naked, used, noinline)) void fixup_stub_00005194(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019220(%rip)");
}

/* FUNC 000051A4  native -> managed via CLR VTableFixups slot 0x19230
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19230, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600001B (msclr.interop.details.GetAnsiStringSize, RVA 0x13a0)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019230[];

__attribute__((naked, used, noinline)) void fixup_stub_000051A4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019230(%rip)");
}

/* FUNC 000051B4  native -> managed via CLR VTableFixups slot 0x19240
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19240, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600001C (msclr.interop.details.WriteAnsiString, RVA 0x13f4)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019240[];

__attribute__((naked, used, noinline)) void fixup_stub_000051B4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019240(%rip)");
}

/* FUNC 000051C4  native -> managed via CLR VTableFixups slot 0x19250
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19250, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600001D (msclr.interop.details.GetUnicodeStringSize, RVA 0x1460)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019250[];

__attribute__((naked, used, noinline)) void fixup_stub_000051C4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019250(%rip)");
}

/* FUNC 000051D4  native -> managed via CLR VTableFixups slot 0x19260
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19260, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600001E (msclr.interop.details.WriteUnicodeString, RVA 0x14a8)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019260[];

__attribute__((naked, used, noinline)) void fixup_stub_000051D4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019260(%rip)");
}

/* FUNC 000051E4  native -> managed via CLR VTableFixups slot 0x19270
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19270, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000021 (msclr.interop.details.char_buffer<char>.release, RVA 0x1658)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019270[];

__attribute__((naked, used, noinline)) void fixup_stub_000051E4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019270(%rip)");
}

/* FUNC 000051F4  native -> managed via CLR VTableFixups slot 0x19280
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19280, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000022 (msclr.interop.details.char_buffer<char>.get, RVA 0x166c)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019280[];

__attribute__((naked, used, noinline)) void fixup_stub_000051F4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019280(%rip)");
}

/* FUNC 00005204  native -> managed via CLR VTableFixups slot 0x19290
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19290, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000023 (msclr.interop.details.char_buffer<char>.{dtor}, RVA 0x167c)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019290[];

__attribute__((naked, used, noinline)) void fixup_stub_00005204(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019290(%rip)");
}

/* FUNC 00005214  native -> managed via CLR VTableFixups slot 0x192a0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x192a0, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000024 (msclr.interop.details.char_buffer<char>.{ctor}, RVA 0x1690)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000192A0[];

__attribute__((naked, used, noinline)) void fixup_stub_00005214(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000192A0(%rip)");
}

/* FUNC 00005224  native -> managed via CLR VTableFixups slot 0x192b0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x192b0, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000025 (msclr.interop.details.char_buffer<wchar_t>.get, RVA 0x16a8)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000192B0[];

__attribute__((naked, used, noinline)) void fixup_stub_00005224(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000192B0(%rip)");
}

/* FUNC 00005234  native -> managed via CLR VTableFixups slot 0x192c0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x192c0, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000026 (msclr.interop.details.char_buffer<wchar_t>.{dtor}, RVA 0x16b8)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000192C0[];

__attribute__((naked, used, noinline)) void fixup_stub_00005234(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000192C0(%rip)");
}

/* FUNC 00005244  native -> managed via CLR VTableFixups slot 0x192d0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x192d0, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000027 (msclr.interop.details.char_buffer<wchar_t>.{ctor}, RVA 0x16cc)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000192D0[];

__attribute__((naked, used, noinline)) void fixup_stub_00005244(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000192D0(%rip)");
}

/* FUNC 00005254  native -> managed via CLR VTableFixups slot 0x192e0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x192e0, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600001F (msclr.interop.details.InternalAnsiToStringHelper, RVA 0x171c)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000192E0[];

__attribute__((naked, used, noinline)) void fixup_stub_00005254(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000192E0(%rip)");
}

/* FUNC 00005264  native -> managed via CLR VTableFixups slot 0x192f0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x192f0, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000029 (msclr.interop._Marshal_as_impl<class System::String ^>, RVA 0x19bc)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000192F0[];

__attribute__((naked, used, noinline)) void fixup_stub_00005264(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000192F0(%rip)");
}

/* FUNC 00005274  native -> managed via CLR VTableFixups slot 0x19300
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19300, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000028 (msclr.interop.marshal_as<class System::String ^,char *>, RVA 0x1a28)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019300[];

__attribute__((naked, used, noinline)) void fixup_stub_00005274(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019300(%rip)");
}

/* FUNC 00005284  native -> managed via CLR VTableFixups slot 0x19310
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19310, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000008 (std.bad_array_new_length.{dtor}, RVA 0x1bdc)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019310[];

__attribute__((naked, used, noinline)) void fixup_stub_00005284(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019310(%rip)");
}

/* FUNC 00005294  native -> managed via CLR VTableFixups slot 0x19320
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19320, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600000E (std.bad_variant_access.{dtor}, RVA 0x1c5c)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019320[];

__attribute__((naked, used, noinline)) void fixup_stub_00005294(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019320(%rip)");
}

/* FUNC 000052A4  native -> managed via CLR VTableFixups slot 0x19330
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19330, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000012 (std.bad_cast.{dtor}, RVA 0x1cf0)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019330[];

__attribute__((naked, used, noinline)) void fixup_stub_000052A4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019330(%rip)");
}

/* FUNC 000052B4  native -> managed via CLR VTableFixups slot 0x19340
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19340, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000018 (std.bad_weak_ptr.{dtor}, RVA 0x1d70)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019340[];

__attribute__((naked, used, noinline)) void fixup_stub_000052B4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019340(%rip)");
}

/* FUNC 000052C4  native -> managed via CLR VTableFixups slot 0x19388
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19388, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000051 (.cctor, RVA 0x3d80)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019388[];

__attribute__((naked, used, noinline)) void fixup_stub_000052C4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019388(%rip)");
}

/* FUNC 000052D4  native -> managed via CLR VTableFixups slot 0x19398
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19398, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600002C (<CrtImplementationDetails>.ThrowModuleLoadException, RVA 0x32f0)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019398[];

__attribute__((naked, used, noinline)) void fixup_stub_000052D4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019398(%rip)");
}

/* FUNC 000052E4  native -> managed via CLR VTableFixups slot 0x193a8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x193a8, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600002D (<CrtImplementationDetails>.ThrowModuleLoadException, RVA 0x3304)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000193A8[];

__attribute__((naked, used, noinline)) void fixup_stub_000052E4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000193A8(%rip)");
}

/* FUNC 000052F4  native -> managed via CLR VTableFixups slot 0x193b8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x193b8, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600002E (<CrtImplementationDetails>.RegisterModuleUninitializer, RVA 0x3420)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000193B8[];

__attribute__((naked, used, noinline)) void fixup_stub_000052F4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000193B8(%rip)");
}

/* FUNC 00005304  native -> managed via CLR VTableFixups slot 0x193c8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x193c8, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600002F (<CrtImplementationDetails>.FromGUID, RVA 0x3438)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000193C8[];

__attribute__((naked, used, noinline)) void fixup_stub_00005304(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000193C8(%rip)");
}

/* FUNC 00005314  native -> managed via CLR VTableFixups slot 0x193d8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x193d8, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000030 (__get_default_appdomain, RVA 0x3488)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000193D8[];

__attribute__((naked, used, noinline)) void fixup_stub_00005314(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000193D8(%rip)");
}

/* FUNC 00005324  native -> managed via CLR VTableFixups slot 0x193e8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x193e8, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000031 (__release_appdomain, RVA 0x3508)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000193E8[];

__attribute__((naked, used, noinline)) void fixup_stub_00005324(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000193E8(%rip)");
}

/* FUNC 00005334  native -> managed via CLR VTableFixups slot 0x193f8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x193f8, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000032 (<CrtImplementationDetails>.GetDefaultDomain, RVA 0x3524)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000193F8[];

__attribute__((naked, used, noinline)) void fixup_stub_00005334(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000193F8(%rip)");
}

/* FUNC 00005344  native -> managed via CLR VTableFixups slot 0x19408
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19408, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000033 (<CrtImplementationDetails>.DoCallBackInDefaultDomain, RVA 0x3584)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019408[];

__attribute__((naked, used, noinline)) void fixup_stub_00005344(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019408(%rip)");
}

/* FUNC 00005354  native -> managed via CLR VTableFixups slot 0x19418
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19418, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000034 (__scrt_is_safe_for_managed_code, RVA 0x363c)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019418[];

__attribute__((naked, used, noinline)) void fixup_stub_00005354(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019418(%rip)");
}

/* FUNC 00005364  native -> managed via CLR VTableFixups slot 0x19428
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19428, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000035 (<CrtImplementationDetails>.DefaultDomain.DoNothing, RVA 0x3670)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019428[];

__attribute__((naked, used, noinline)) void fixup_stub_00005364(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019428(%rip)");
}

/* FUNC 00005374  native -> managed via CLR VTableFixups slot 0x19438
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19438, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000036 (<CrtImplementationDetails>.DefaultDomain.HasPerProcess, RVA 0x3690)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019438[];

__attribute__((naked, used, noinline)) void fixup_stub_00005374(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019438(%rip)");
}

/* FUNC 00005384  native -> managed via CLR VTableFixups slot 0x19448
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19448, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000037 (<CrtImplementationDetails>.DefaultDomain.HasNative, RVA 0x36e4)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019448[];

__attribute__((naked, used, noinline)) void fixup_stub_00005384(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019448(%rip)");
}

/* FUNC 00005394  native -> managed via CLR VTableFixups slot 0x19458
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19458, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000038 (<CrtImplementationDetails>.DefaultDomain.NeedsInitialization, RVA 0x3764)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019458[];

__attribute__((naked, used, noinline)) void fixup_stub_00005394(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019458(%rip)");
}

/* FUNC 000053A4  native -> managed via CLR VTableFixups slot 0x19468
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19468, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000039 (<CrtImplementationDetails>.DefaultDomain.NeedsUninitialization, RVA 0x379c)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019468[];

__attribute__((naked, used, noinline)) void fixup_stub_000053A4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019468(%rip)");
}

/* FUNC 000053B4  native -> managed via CLR VTableFixups slot 0x19478
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19478, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600003A (<CrtImplementationDetails>.DefaultDomain.Initialize, RVA 0x37b0)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019478[];

__attribute__((naked, used, noinline)) void fixup_stub_000053B4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019478(%rip)");
}

/* FUNC 000053C4  native -> managed via CLR VTableFixups slot 0x19488
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19488, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000049 (<CrtImplementationDetails>.LanguageSupport.UninitializeAppDomain, RVA 0x37cc)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019488[];

__attribute__((naked, used, noinline)) void fixup_stub_000053C4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019488(%rip)");
}

/* FUNC 000053D4  native -> managed via CLR VTableFixups slot 0x19498
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19498, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600004A (<CrtImplementationDetails>.LanguageSupport._UninitializeDefaultDomain, RVA 0x37e0)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019498[];

__attribute__((naked, used, noinline)) void fixup_stub_000053D4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019498(%rip)");
}

/* FUNC 000053E4  native -> managed via CLR VTableFixups slot 0x194a8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x194a8, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600004B (<CrtImplementationDetails>.LanguageSupport.UninitializeDefaultDomain, RVA 0x3818)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000194A8[];

__attribute__((naked, used, noinline)) void fixup_stub_000053E4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000194A8(%rip)");
}

/* FUNC 000053F4  native -> managed via CLR VTableFixups slot 0x194b8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x194b8, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600004C (<CrtImplementationDetails>.LanguageSupport.DomainUnload, RVA 0x3850)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000194B8[];

__attribute__((naked, used, noinline)) void fixup_stub_000053F4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000194B8(%rip)");
}

/* FUNC 00005404  native -> managed via CLR VTableFixups slot 0x194c8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x194c8, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000052 (gcroot<System::String ^>..PE$AAVString@System@@, RVA 0x388c)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000194C8[];

__attribute__((naked, used, noinline)) void fixup_stub_00005404(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000194C8(%rip)");
}

/* FUNC 00005414  native -> managed via CLR VTableFixups slot 0x194d8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x194d8, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000053 (gcroot<System::String ^>.=, RVA 0x38b0)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000194D8[];

__attribute__((naked, used, noinline)) void fixup_stub_00005414(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000194D8(%rip)");
}

/* FUNC 00005424  native -> managed via CLR VTableFixups slot 0x194e8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x194e8, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000054 (gcroot<System::String ^>.{dtor}, RVA 0x38d8)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000194E8[];

__attribute__((naked, used, noinline)) void fixup_stub_00005424(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000194E8(%rip)");
}

/* FUNC 00005434  native -> managed via CLR VTableFixups slot 0x194f8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x194f8, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000055 (gcroot<System::String ^>.{ctor}, RVA 0x3900)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000194F8[];

__attribute__((naked, used, noinline)) void fixup_stub_00005434(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000194F8(%rip)");
}

/* FUNC 00005444  native -> managed via CLR VTableFixups slot 0x19508
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19508, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600002B (<CrtImplementationDetails>.ThrowNestedModuleLoadException, RVA 0x3940)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019508[];

__attribute__((naked, used, noinline)) void fixup_stub_00005444(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019508(%rip)");
}

/* FUNC 00005454  native -> managed via CLR VTableFixups slot 0x19518
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19518, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000042 (<CrtImplementationDetails>.LanguageSupport.InitializeVtables, RVA 0x3994)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019518[];

__attribute__((naked, used, noinline)) void fixup_stub_00005454(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019518(%rip)");
}

/* FUNC 00005464  native -> managed via CLR VTableFixups slot 0x19528
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19528, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000043 (<CrtImplementationDetails>.LanguageSupport.InitializeDefaultAppDomain, RVA 0x39c8)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019528[];

__attribute__((naked, used, noinline)) void fixup_stub_00005464(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019528(%rip)");
}

/* FUNC 00005474  native -> managed via CLR VTableFixups slot 0x19538
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19538, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000044 (<CrtImplementationDetails>.LanguageSupport.InitializeNative, RVA 0x39e8)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019538[];

__attribute__((naked, used, noinline)) void fixup_stub_00005474(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019538(%rip)");
}

/* FUNC 00005484  native -> managed via CLR VTableFixups slot 0x19548
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19548, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000045 (<CrtImplementationDetails>.LanguageSupport.InitializePerProcess, RVA 0x3a78)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019548[];

__attribute__((naked, used, noinline)) void fixup_stub_00005484(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019548(%rip)");
}

/* FUNC 00005494  native -> managed via CLR VTableFixups slot 0x19558
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19558, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000046 (<CrtImplementationDetails>.LanguageSupport.InitializePerAppDomain, RVA 0x3ab8)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019558[];

__attribute__((naked, used, noinline)) void fixup_stub_00005494(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019558(%rip)");
}

/* FUNC 000054A4  native -> managed via CLR VTableFixups slot 0x19568
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19568, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000047 (<CrtImplementationDetails>.LanguageSupport.InitializeUninitializer, RVA 0x3af4)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019568[];

__attribute__((naked, used, noinline)) void fixup_stub_000054A4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019568(%rip)");
}

/* FUNC 000054B4  native -> managed via CLR VTableFixups slot 0x19578
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19578, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000048 (<CrtImplementationDetails>.LanguageSupport._Initialize, RVA 0x3b20)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019578[];

__attribute__((naked, used, noinline)) void fixup_stub_000054B4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019578(%rip)");
}

/* FUNC 000054C4  native -> managed via CLR VTableFixups slot 0x19588
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19588, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600004D (<CrtImplementationDetails>.LanguageSupport.Cleanup, RVA 0x3c24)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019588[];

__attribute__((naked, used, noinline)) void fixup_stub_000054C4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019588(%rip)");
}

/* FUNC 000054D4  native -> managed via CLR VTableFixups slot 0x19598
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19598, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600004E (<CrtImplementationDetails>.LanguageSupport.{ctor}, RVA 0x3c98)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019598[];

__attribute__((naked, used, noinline)) void fixup_stub_000054D4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019598(%rip)");
}

/* FUNC 000054E4  native -> managed via CLR VTableFixups slot 0x195a8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x195a8, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600004F (<CrtImplementationDetails>.LanguageSupport.{dtor}, RVA 0x3cb0)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000195A8[];

__attribute__((naked, used, noinline)) void fixup_stub_000054E4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000195A8(%rip)");
}

/* FUNC 000054F4  native -> managed via CLR VTableFixups slot 0x195b8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x195b8, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000050 (<CrtImplementationDetails>.LanguageSupport.Initialize, RVA 0x3cc4)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000195B8[];

__attribute__((naked, used, noinline)) void fixup_stub_000054F4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000195B8(%rip)");
}

/* FUNC 00005500  native -> managed via CLR VTableFixups slot 0x195c8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x195c8, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600003B (?A0xeb4f7d22.??__E?Initialized@CurrentDomain@<CrtImplementationDetails>@@$$Q2HA@@YMXXZ, RVA 0x1000)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000195C8[];

__attribute__((naked, used, noinline)) void fixup_stub_00005500(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000195C8(%rip)");
}

/* FUNC 00005510  native -> managed via CLR VTableFixups slot 0x195d0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x195d0, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600003C (?A0xeb4f7d22.??__E?Uninitialized@CurrentDomain@<CrtImplementationDetails>@@$$Q2HA@@YMXXZ, RVA 0x1014)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000195D0[];

__attribute__((naked, used, noinline)) void fixup_stub_00005510(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000195D0(%rip)");
}

/* FUNC 00005520  native -> managed via CLR VTableFixups slot 0x195d8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x195d8, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600003D (?A0xeb4f7d22.??__E?IsDefaultDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2_NA@@YMXXZ, RVA 0x1028)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000195D8[];

__attribute__((naked, used, noinline)) void fixup_stub_00005520(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000195D8(%rip)");
}

/* FUNC 00005530  native -> managed via CLR VTableFixups slot 0x195e0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x195e0, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600003E (?A0xeb4f7d22.??__E?InitializedVtables@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A@@YMXXZ, RVA 0x103c)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000195E0[];

__attribute__((naked, used, noinline)) void fixup_stub_00005530(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000195E0(%rip)");
}

/* FUNC 00005540  native -> managed via CLR VTableFixups slot 0x195e8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x195e8, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600003F (?A0xeb4f7d22.??__E?InitializedNative@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A@@YMXXZ, RVA 0x1050)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000195E8[];

__attribute__((naked, used, noinline)) void fixup_stub_00005540(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000195E8(%rip)");
}

/* FUNC 00005550  native -> managed via CLR VTableFixups slot 0x195f0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x195f0, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000040 (?A0xeb4f7d22.??__E?InitializedPerProcess@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A@@YMXXZ, RVA 0x1064)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000195F0[];

__attribute__((naked, used, noinline)) void fixup_stub_00005550(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000195F0(%rip)");
}

/* FUNC 00005560  native -> managed via CLR VTableFixups slot 0x195f8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x195f8, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000041 (?A0xeb4f7d22.??__E?InitializedPerAppDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A@@YMXXZ, RVA 0x1078)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000195F8[];

__attribute__((naked, used, noinline)) void fixup_stub_00005560(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000195F8(%rip)");
}

/* FUNC 00005574  native -> managed via CLR VTableFixups slot 0x19600
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19600, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000056 (___CxxCallUnwindDtor, RVA 0x3e08)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019600[];

__attribute__((naked, used, noinline)) void fixup_stub_00005574(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019600(%rip)");
}

/* FUNC 00005584  native -> managed via CLR VTableFixups slot 0x19610
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19610, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000057 (___CxxCallUnwindDelDtor, RVA 0x3e4c)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019610[];

__attribute__((naked, used, noinline)) void fixup_stub_00005584(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019610(%rip)");
}

/* FUNC 00005594  native -> managed via CLR VTableFixups slot 0x19620
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19620, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000058 (___CxxCallUnwindVecDtor, RVA 0x3e90)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019620[];

__attribute__((naked, used, noinline)) void fixup_stub_00005594(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019620(%rip)");
}

/* FUNC 000055A4  native -> managed via CLR VTableFixups slot 0x19630
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19630, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600005B (__ArrayUnwind, RVA 0x3f24)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019630[];

__attribute__((naked, used, noinline)) void fixup_stub_000055A4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019630(%rip)");
}

/* FUNC 000055B4  native -> managed via CLR VTableFixups slot 0x19640
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19640, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000059 (__ehvec_dtor, RVA 0x3f7c)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019640[];

__attribute__((naked, used, noinline)) void fixup_stub_000055B4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019640(%rip)");
}

/* FUNC 000055C4  native -> managed via CLR VTableFixups slot 0x19650
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19650, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600005C (__ehvec_dtor, RVA 0x3fdc)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019650[];

__attribute__((naked, used, noinline)) void fixup_stub_000055C4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019650(%rip)");
}

/* FUNC 000055D4  native -> managed via CLR VTableFixups slot 0x19660
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19660, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600005A (?A0x9c83a709.ArrayUnwindFilter, RVA 0x3eec)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019660[];

__attribute__((naked, used, noinline)) void fixup_stub_000055D4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019660(%rip)");
}

/* FUNC 000055E4  native -> managed via CLR VTableFixups slot 0x19670
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19670, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600006B (_atexit_helper, RVA 0x419c)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019670[];

__attribute__((naked, used, noinline)) void fixup_stub_000055E4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019670(%rip)");
}

/* FUNC 000055F4  native -> managed via CLR VTableFixups slot 0x19680
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19680, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600006C (_exit_callback, RVA 0x4314)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019680[];

__attribute__((naked, used, noinline)) void fixup_stub_000055F4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019680(%rip)");
}

/* FUNC 00005604  native -> managed via CLR VTableFixups slot 0x19690
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19690, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600006F (_atexit_m, RVA 0x43c4)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019690[];

__attribute__((naked, used, noinline)) void fixup_stub_00005604(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019690(%rip)");
}

/* FUNC 00005614  native -> managed via CLR VTableFixups slot 0x196a0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x196a0, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000071 (_app_exit_callback, RVA 0x43ec)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000196A0[];

__attribute__((naked, used, noinline)) void fixup_stub_00005614(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000196A0(%rip)");
}

/* FUNC 00005624  native -> managed via CLR VTableFixups slot 0x196b0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x196b0, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000073 (_atexit_m_appdomain, RVA 0x44d8)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000196B0[];

__attribute__((naked, used, noinline)) void fixup_stub_00005624(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000196B0(%rip)");
}

/* FUNC 00005634  native -> managed via CLR VTableFixups slot 0x196c0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x196c0, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600006D (_initatexit_m, RVA 0x4564)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000196C0[];

__attribute__((naked, used, noinline)) void fixup_stub_00005634(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000196C0(%rip)");
}

/* FUNC 00005644  native -> managed via CLR VTableFixups slot 0x196d0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x196d0, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600006E (_onexit_m, RVA 0x45ac)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000196D0[];

__attribute__((naked, used, noinline)) void fixup_stub_00005644(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000196D0(%rip)");
}

/* FUNC 00005654  native -> managed via CLR VTableFixups slot 0x196e0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x196e0, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000070 (_initatexit_app_domain, RVA 0x45c8)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000196E0[];

__attribute__((naked, used, noinline)) void fixup_stub_00005654(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000196E0(%rip)");
}

/* FUNC 00005664  native -> managed via CLR VTableFixups slot 0x196f0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x196f0, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000072 (_onexit_m_appdomain, RVA 0x460c)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000196F0[];

__attribute__((naked, used, noinline)) void fixup_stub_00005664(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000196F0(%rip)");
}

/* FUNC 00005674  native -> managed via CLR VTableFixups slot 0x19700
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19700, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600005D (<CrtImplementationDetails>.AtExitLock._handle, RVA 0x4008)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019700[];

__attribute__((naked, used, noinline)) void fixup_stub_00005674(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019700(%rip)");
}

/* FUNC 00005684  native -> managed via CLR VTableFixups slot 0x19710
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19710, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600005F (<CrtImplementationDetails>.AtExitLock._lock_Set, RVA 0x4038)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019710[];

__attribute__((naked, used, noinline)) void fixup_stub_00005684(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019710(%rip)");
}

/* FUNC 00005694  native -> managed via CLR VTableFixups slot 0x19720
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19720, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000060 (<CrtImplementationDetails>.AtExitLock._lock_Get, RVA 0x4088)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019720[];

__attribute__((naked, used, noinline)) void fixup_stub_00005694(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019720(%rip)");
}

/* FUNC 000056A4  native -> managed via CLR VTableFixups slot 0x19730
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19730, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000061 (<CrtImplementationDetails>.AtExitLock._lock_Destruct, RVA 0x40ac)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019730[];

__attribute__((naked, used, noinline)) void fixup_stub_000056A4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019730(%rip)");
}

/* FUNC 000056B4  native -> managed via CLR VTableFixups slot 0x19740
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19740, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000062 (<CrtImplementationDetails>.AtExitLock.IsInitialized, RVA 0x40d4)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019740[];

__attribute__((naked, used, noinline)) void fixup_stub_000056B4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019740(%rip)");
}

/* FUNC 000056C4  native -> managed via CLR VTableFixups slot 0x19750
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19750, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000064 (<CrtImplementationDetails>.AtExitLock.RemoveRef, RVA 0x40f0)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019750[];

__attribute__((naked, used, noinline)) void fixup_stub_000056C4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019750(%rip)");
}

/* FUNC 000056D4  native -> managed via CLR VTableFixups slot 0x19760
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19760, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000065 (<CrtImplementationDetails>.AtExitLock.Enter, RVA 0x4118)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019760[];

__attribute__((naked, used, noinline)) void fixup_stub_000056D4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019760(%rip)");
}

/* FUNC 000056E4  native -> managed via CLR VTableFixups slot 0x19770
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19770, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000066 (<CrtImplementationDetails>.AtExitLock.Exit, RVA 0x4130)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019770[];

__attribute__((naked, used, noinline)) void fixup_stub_000056E4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019770(%rip)");
}

/* FUNC 000056F4  native -> managed via CLR VTableFixups slot 0x19780
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19780, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000067 (?A0xdf32f105.__global_lock, RVA 0x4148)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019780[];

__attribute__((naked, used, noinline)) void fixup_stub_000056F4(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019780(%rip)");
}

/* FUNC 00005704  native -> managed via CLR VTableFixups slot 0x19790
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19790, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000068 (?A0xdf32f105.__global_unlock, RVA 0x4168)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019790[];

__attribute__((naked, used, noinline)) void fixup_stub_00005704(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019790(%rip)");
}

/* FUNC 00005714  native -> managed via CLR VTableFixups slot 0x197a0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x197a0, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600006A (?A0xdf32f105.__dealloc_global_lock, RVA 0x4188)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000197A0[];

__attribute__((naked, used, noinline)) void fixup_stub_00005714(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000197A0(%rip)");
}

/* FUNC 00005724  native -> managed via CLR VTableFixups slot 0x197b0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x197b0, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600005E (<CrtImplementationDetails>.AtExitLock._lock_Construct, RVA 0x4500)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000197B0[];

__attribute__((naked, used, noinline)) void fixup_stub_00005724(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000197B0(%rip)");
}

/* FUNC 00005734  native -> managed via CLR VTableFixups slot 0x197c0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x197c0, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000063 (<CrtImplementationDetails>.AtExitLock.AddRef, RVA 0x451c)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000197C0[];

__attribute__((naked, used, noinline)) void fixup_stub_00005734(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000197C0(%rip)");
}

/* FUNC 00005744  native -> managed via CLR VTableFixups slot 0x197d0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x197d0, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000069 (?A0xdf32f105.__alloc_global_lock, RVA 0x454c)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000197D0[];

__attribute__((naked, used, noinline)) void fixup_stub_00005744(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000197D0(%rip)");
}

/* FUNC 00005754  native -> managed via CLR VTableFixups slot 0x197e0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x197e0, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000076 (_initterm_e, RVA 0x463c)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000197E0[];

__attribute__((naked, used, noinline)) void fixup_stub_00005754(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000197E0(%rip)");
}

/* FUNC 00005764  native -> managed via CLR VTableFixups slot 0x197f0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x197f0, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000077 (_initterm, RVA 0x466c)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_000197F0[];

__attribute__((naked, used, noinline)) void fixup_stub_00005764(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000197F0(%rip)");
}

/* FUNC 00005774  native -> managed via CLR VTableFixups slot 0x19800
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19800, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000079 (_initterm_m, RVA 0x46e4)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019800[];

__attribute__((naked, used, noinline)) void fixup_stub_00005774(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019800(%rip)");
}

/* FUNC 00005784  native -> managed via CLR VTableFixups slot 0x19810
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19810, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x06000078 (<CrtImplementationDetails>.ThisModule.Handle, RVA 0x4694)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019810[];

__attribute__((naked, used, noinline)) void fixup_stub_00005784(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019810(%rip)");
}

/* FUNC 00005794  native -> managed via CLR VTableFixups slot 0x19820
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19820, Type 0x2, filled by the CLR loader
   static   : slot value = MethodDef 0x0600007A (<CrtImplementationDetails>.ThisModule.ResolveMethod<void const * __clrcall(void)>, RVA 0x46b8)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
*/
extern unsigned char fixup_slot_00019820[];

__attribute__((naked, used, noinline)) void fixup_stub_00005794(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019820(%rip)");
}

