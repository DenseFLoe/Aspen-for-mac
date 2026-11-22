/* NATIVE-340 s21: editable stubs for the 106 slot jumps that were missing.
   Every stub is a naked tail jump through its CLR VTableFixups slot; the slot is
   filled by the loader, so the landing address is a runtime value. */
/* FUNC 0000500A  native -> managed via CLR VTableFixups slot 0x19020
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19020, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000001 (std.exception.{ctor}, RVA 0x10A0)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5000 (eb08 bytes) jumps here; site instruction ff2510400100
*/
extern unsigned char fixup_slot_00019020[];

__attribute__((naked, used, noinline)) void fixup_stub_0000500A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019020(%rip)");
}

/* FUNC 0000501A  native -> managed via CLR VTableFixups slot 0x19030
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19030, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600000A (std.exception_ptr.{ctor}, RVA 0x1120)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5010 (eb08 bytes) jumps here; site instruction ff2510400100
*/
extern unsigned char fixup_slot_00019030[];

__attribute__((naked, used, noinline)) void fixup_stub_0000501A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019030(%rip)");
}

/* FUNC 0000502A  native -> managed via CLR VTableFixups slot 0x19058
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19058, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600000C (std.bad_alloc.{ctor}, RVA 0x1138)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5020 (eb08 bytes) jumps here; site instruction ff2528400100
*/
extern unsigned char fixup_slot_00019058[];

__attribute__((naked, used, noinline)) void fixup_stub_0000502A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019058(%rip)");
}

/* FUNC 0000503A  native -> managed via CLR VTableFixups slot 0x19080
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19080, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600000B (std.bad_array_new_length.{ctor}, RVA 0x1198)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5030 (eb08 bytes) jumps here; site instruction ff2540400100
*/
extern unsigned char fixup_slot_00019080[];

__attribute__((naked, used, noinline)) void fixup_stub_0000503A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019080(%rip)");
}

/* FUNC 0000504A  native -> managed via CLR VTableFixups slot 0x19090
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19090, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x060000A3 (<MarshalCopy>, RVA 0x1224)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5040 (eb08 bytes) jumps here; site instruction ff2540400100
*/
extern unsigned char fixup_slot_00019090[];

__attribute__((naked, used, noinline)) void fixup_stub_0000504A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019090(%rip)");
}

/* FUNC 0000505A  native -> managed via CLR VTableFixups slot 0x190a0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x190a0, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x060000A4 (<MarshalDestroy>, RVA 0x123C)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5050 (eb08 bytes) jumps here; site instruction ff2540400100
*/
extern unsigned char fixup_slot_000190A0[];

__attribute__((naked, used, noinline)) void fixup_stub_0000505A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000190A0(%rip)");
}

/* FUNC 0000506A  native -> managed via CLR VTableFixups slot 0x190c8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x190c8, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600000F (std.bad_variant_access.{ctor}, RVA 0x1250)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5060 (eb08 bytes) jumps here; site instruction ff2558400100
*/
extern unsigned char fixup_slot_000190C8[];

__attribute__((naked, used, noinline)) void fixup_stub_0000506A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000190C8(%rip)");
}

/* FUNC 0000507A  native -> managed via CLR VTableFixups slot 0x190f0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x190f0, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000013 (std.bad_cast.{ctor}, RVA 0x12B0)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5070 (eb08 bytes) jumps here; site instruction ff2570400100
*/
extern unsigned char fixup_slot_000190F0[];

__attribute__((naked, used, noinline)) void fixup_stub_0000507A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000190F0(%rip)");
}

/* FUNC 0000508A  native -> managed via CLR VTableFixups slot 0x19118
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19118, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000019 (std.bad_weak_ptr.{ctor}, RVA 0x1324)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5080 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019118[];

__attribute__((naked, used, noinline)) void fixup_stub_0000508A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019118(%rip)");
}

/* FUNC 0000509A  native -> managed via CLR VTableFixups slot 0x19128
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19128, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000014 (std._Iterator_base12.{ctor}, RVA 0x1700)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5090 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019128[];

__attribute__((naked, used, noinline)) void fixup_stub_0000509A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019128(%rip)");
}

/* FUNC 000050BA  native -> managed via CLR VTableFixups slot 0x19148
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19148, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600002A (new, RVA 0x1090)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x50B0 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019148[];

__attribute__((naked, used, noinline)) void fixup_stub_000050BA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019148(%rip)");
}

/* FUNC 000050DA  native -> managed via CLR VTableFixups slot 0x19168
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19168, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000003 (std.exception.what, RVA 0x1AFC)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x50D0 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019168[];

__attribute__((naked, used, noinline)) void fixup_stub_000050DA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019168(%rip)");
}

/* FUNC 000050EA  native -> managed via CLR VTableFixups slot 0x19178
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19178, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000002 (std.exception.{dtor}, RVA 0x10CC)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x50E0 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019178[];

__attribute__((naked, used, noinline)) void fixup_stub_000050EA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019178(%rip)");
}

/* FUNC 000050FA  native -> managed via CLR VTableFixups slot 0x19188
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19188, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000006 (std.bad_alloc.{dtor}, RVA 0x10EC)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x50F0 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019188[];

__attribute__((naked, used, noinline)) void fixup_stub_000050FA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019188(%rip)");
}

/* FUNC 0000510A  native -> managed via CLR VTableFixups slot 0x19198
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19198, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000009 (std.exception_ptr.{dtor}, RVA 0x110C)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5100 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019198[];

__attribute__((naked, used, noinline)) void fixup_stub_0000510A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019198(%rip)");
}

/* FUNC 0000516A  native -> managed via CLR VTableFixups slot 0x191f8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x191f8, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000015 (std._Iterator_base12.=, RVA 0x1310)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5160 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_000191F8[];

__attribute__((naked, used, noinline)) void fixup_stub_0000516A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000191F8(%rip)");
}

/* FUNC 0000519A  native -> managed via CLR VTableFixups slot 0x19228
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19228, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600001A (PtrToStringChars, RVA 0x1384)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5190 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019228[];

__attribute__((naked, used, noinline)) void fixup_stub_0000519A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019228(%rip)");
}

/* FUNC 000051AA  native -> managed via CLR VTableFixups slot 0x19238
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19238, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600001B (msclr.interop.details.GetAnsiStringSize, RVA 0x13A0)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x51A0 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019238[];

__attribute__((naked, used, noinline)) void fixup_stub_000051AA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019238(%rip)");
}

/* FUNC 000051BA  native -> managed via CLR VTableFixups slot 0x19248
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19248, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600001C (msclr.interop.details.WriteAnsiString, RVA 0x13F4)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x51B0 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019248[];

__attribute__((naked, used, noinline)) void fixup_stub_000051BA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019248(%rip)");
}

/* FUNC 000051CA  native -> managed via CLR VTableFixups slot 0x19258
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19258, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600001D (msclr.interop.details.GetUnicodeStringSize, RVA 0x1460)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x51C0 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019258[];

__attribute__((naked, used, noinline)) void fixup_stub_000051CA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019258(%rip)");
}

/* FUNC 000051DA  native -> managed via CLR VTableFixups slot 0x19268
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19268, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600001E (msclr.interop.details.WriteUnicodeString, RVA 0x14A8)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x51D0 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019268[];

__attribute__((naked, used, noinline)) void fixup_stub_000051DA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019268(%rip)");
}

/* FUNC 000051EA  native -> managed via CLR VTableFixups slot 0x19278
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19278, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000021 (msclr.interop.details.char_buffer<char>.release, RVA 0x1658)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x51E0 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019278[];

__attribute__((naked, used, noinline)) void fixup_stub_000051EA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019278(%rip)");
}

/* FUNC 000051FA  native -> managed via CLR VTableFixups slot 0x19288
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19288, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000022 (msclr.interop.details.char_buffer<char>.get, RVA 0x166C)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x51F0 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019288[];

__attribute__((naked, used, noinline)) void fixup_stub_000051FA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019288(%rip)");
}

/* FUNC 0000520A  native -> managed via CLR VTableFixups slot 0x19298
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19298, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000023 (msclr.interop.details.char_buffer<char>.{dtor}, RVA 0x167C)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5200 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019298[];

__attribute__((naked, used, noinline)) void fixup_stub_0000520A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019298(%rip)");
}

/* FUNC 0000521A  native -> managed via CLR VTableFixups slot 0x192a8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x192a8, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000024 (msclr.interop.details.char_buffer<char>.{ctor}, RVA 0x1690)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5210 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_000192A8[];

__attribute__((naked, used, noinline)) void fixup_stub_0000521A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000192A8(%rip)");
}

/* FUNC 0000522A  native -> managed via CLR VTableFixups slot 0x192b8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x192b8, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000025 (msclr.interop.details.char_buffer<wchar_t>.get, RVA 0x16A8)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5220 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_000192B8[];

__attribute__((naked, used, noinline)) void fixup_stub_0000522A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000192B8(%rip)");
}

/* FUNC 0000523A  native -> managed via CLR VTableFixups slot 0x192c8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x192c8, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000026 (msclr.interop.details.char_buffer<wchar_t>.{dtor}, RVA 0x16B8)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5230 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_000192C8[];

__attribute__((naked, used, noinline)) void fixup_stub_0000523A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000192C8(%rip)");
}

/* FUNC 0000524A  native -> managed via CLR VTableFixups slot 0x192d8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x192d8, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000027 (msclr.interop.details.char_buffer<wchar_t>.{ctor}, RVA 0x16CC)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5240 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_000192D8[];

__attribute__((naked, used, noinline)) void fixup_stub_0000524A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000192D8(%rip)");
}

/* FUNC 0000525A  native -> managed via CLR VTableFixups slot 0x192e8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x192e8, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600001F (msclr.interop.details.InternalAnsiToStringHelper, RVA 0x171C)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5250 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_000192E8[];

__attribute__((naked, used, noinline)) void fixup_stub_0000525A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000192E8(%rip)");
}

/* FUNC 0000526A  native -> managed via CLR VTableFixups slot 0x192f8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x192f8, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000029 (msclr.interop._Marshal_as_impl<class System::String ^>, RVA 0x19BC)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5260 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_000192F8[];

__attribute__((naked, used, noinline)) void fixup_stub_0000526A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000192F8(%rip)");
}

/* FUNC 0000527A  native -> managed via CLR VTableFixups slot 0x19308
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19308, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000028 (msclr.interop.marshal_as<class System::String ^,char *>, RVA 0x1A28)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5270 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019308[];

__attribute__((naked, used, noinline)) void fixup_stub_0000527A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019308(%rip)");
}

/* FUNC 0000528A  native -> managed via CLR VTableFixups slot 0x19318
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19318, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000008 (std.bad_array_new_length.{dtor}, RVA 0x1BDC)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5280 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019318[];

__attribute__((naked, used, noinline)) void fixup_stub_0000528A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019318(%rip)");
}

/* FUNC 0000529A  native -> managed via CLR VTableFixups slot 0x19328
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19328, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600000E (std.bad_variant_access.{dtor}, RVA 0x1C5C)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5290 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019328[];

__attribute__((naked, used, noinline)) void fixup_stub_0000529A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019328(%rip)");
}

/* FUNC 000052AA  native -> managed via CLR VTableFixups slot 0x19338
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19338, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000012 (std.bad_cast.{dtor}, RVA 0x1CF0)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x52A0 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019338[];

__attribute__((naked, used, noinline)) void fixup_stub_000052AA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019338(%rip)");
}

/* FUNC 000052BA  native -> managed via CLR VTableFixups slot 0x19348
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19348, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000018 (std.bad_weak_ptr.{dtor}, RVA 0x1D70)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x52B0 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019348[];

__attribute__((naked, used, noinline)) void fixup_stub_000052BA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019348(%rip)");
}

/* FUNC 000052CA  native -> managed via CLR VTableFixups slot 0x19390
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19390, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000051 (.cctor, RVA 0x3D80)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x52C0 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_00019390[];

__attribute__((naked, used, noinline)) void fixup_stub_000052CA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019390(%rip)");
}

/* FUNC 000052DA  native -> managed via CLR VTableFixups slot 0x193a0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x193a0, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600002C (<CrtImplementationDetails>.ThrowModuleLoadException, RVA 0x32F0)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x52D0 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_000193A0[];

__attribute__((naked, used, noinline)) void fixup_stub_000052DA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000193A0(%rip)");
}

/* FUNC 000052EA  native -> managed via CLR VTableFixups slot 0x193b0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x193b0, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600002D (<CrtImplementationDetails>.ThrowModuleLoadException, RVA 0x3304)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x52E0 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_000193B0[];

__attribute__((naked, used, noinline)) void fixup_stub_000052EA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000193B0(%rip)");
}

/* FUNC 000052FA  native -> managed via CLR VTableFixups slot 0x193c0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x193c0, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600002E (<CrtImplementationDetails>.RegisterModuleUninitializer, RVA 0x3420)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x52F0 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_000193C0[];

__attribute__((naked, used, noinline)) void fixup_stub_000052FA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000193C0(%rip)");
}

/* FUNC 0000530A  native -> managed via CLR VTableFixups slot 0x193d0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x193d0, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600002F (<CrtImplementationDetails>.FromGUID, RVA 0x3438)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5300 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_000193D0[];

__attribute__((naked, used, noinline)) void fixup_stub_0000530A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000193D0(%rip)");
}

/* FUNC 0000531A  native -> managed via CLR VTableFixups slot 0x193e0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x193e0, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000030 (__get_default_appdomain, RVA 0x3488)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5310 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_000193E0[];

__attribute__((naked, used, noinline)) void fixup_stub_0000531A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000193E0(%rip)");
}

/* FUNC 0000532A  native -> managed via CLR VTableFixups slot 0x193f0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x193f0, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000031 (__release_appdomain, RVA 0x3508)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5320 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_000193F0[];

__attribute__((naked, used, noinline)) void fixup_stub_0000532A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000193F0(%rip)");
}

/* FUNC 0000533A  native -> managed via CLR VTableFixups slot 0x19400
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19400, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000032 (<CrtImplementationDetails>.GetDefaultDomain, RVA 0x3524)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5330 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_00019400[];

__attribute__((naked, used, noinline)) void fixup_stub_0000533A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019400(%rip)");
}

/* FUNC 0000534A  native -> managed via CLR VTableFixups slot 0x19410
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19410, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000033 (<CrtImplementationDetails>.DoCallBackInDefaultDomain, RVA 0x3584)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5340 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_00019410[];

__attribute__((naked, used, noinline)) void fixup_stub_0000534A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019410(%rip)");
}

/* FUNC 0000535A  native -> managed via CLR VTableFixups slot 0x19420
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19420, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000034 (__scrt_is_safe_for_managed_code, RVA 0x363C)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5350 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_00019420[];

__attribute__((naked, used, noinline)) void fixup_stub_0000535A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019420(%rip)");
}

/* FUNC 0000536A  native -> managed via CLR VTableFixups slot 0x19430
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19430, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000035 (<CrtImplementationDetails>.DefaultDomain.DoNothing, RVA 0x3670)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5360 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_00019430[];

__attribute__((naked, used, noinline)) void fixup_stub_0000536A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019430(%rip)");
}

/* FUNC 0000537A  native -> managed via CLR VTableFixups slot 0x19440
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19440, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000036 (<CrtImplementationDetails>.DefaultDomain.HasPerProcess, RVA 0x3690)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5370 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_00019440[];

__attribute__((naked, used, noinline)) void fixup_stub_0000537A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019440(%rip)");
}

/* FUNC 0000538A  native -> managed via CLR VTableFixups slot 0x19450
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19450, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000037 (<CrtImplementationDetails>.DefaultDomain.HasNative, RVA 0x36E4)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5380 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_00019450[];

__attribute__((naked, used, noinline)) void fixup_stub_0000538A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019450(%rip)");
}

/* FUNC 0000539A  native -> managed via CLR VTableFixups slot 0x19460
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19460, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000038 (<CrtImplementationDetails>.DefaultDomain.NeedsInitialization, RVA 0x3764)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5390 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_00019460[];

__attribute__((naked, used, noinline)) void fixup_stub_0000539A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019460(%rip)");
}

/* FUNC 000053AA  native -> managed via CLR VTableFixups slot 0x19470
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19470, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000039 (<CrtImplementationDetails>.DefaultDomain.NeedsUninitialization, RVA 0x379C)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x53A0 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_00019470[];

__attribute__((naked, used, noinline)) void fixup_stub_000053AA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019470(%rip)");
}

/* FUNC 000053BA  native -> managed via CLR VTableFixups slot 0x19480
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19480, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600003A (<CrtImplementationDetails>.DefaultDomain.Initialize, RVA 0x37B0)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x53B0 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_00019480[];

__attribute__((naked, used, noinline)) void fixup_stub_000053BA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019480(%rip)");
}

/* FUNC 000053CA  native -> managed via CLR VTableFixups slot 0x19490
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19490, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000049 (<CrtImplementationDetails>.LanguageSupport.UninitializeAppDomain, RVA 0x37CC)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x53C0 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_00019490[];

__attribute__((naked, used, noinline)) void fixup_stub_000053CA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019490(%rip)");
}

/* FUNC 000053DA  native -> managed via CLR VTableFixups slot 0x194a0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x194a0, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600004A (<CrtImplementationDetails>.LanguageSupport._UninitializeDefaultDomain, RVA 0x37E0)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x53D0 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_000194A0[];

__attribute__((naked, used, noinline)) void fixup_stub_000053DA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000194A0(%rip)");
}

/* FUNC 000053EA  native -> managed via CLR VTableFixups slot 0x194b0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x194b0, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600004B (<CrtImplementationDetails>.LanguageSupport.UninitializeDefaultDomain, RVA 0x3818)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x53E0 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_000194B0[];

__attribute__((naked, used, noinline)) void fixup_stub_000053EA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000194B0(%rip)");
}

/* FUNC 000053FA  native -> managed via CLR VTableFixups slot 0x194c0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x194c0, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600004C (<CrtImplementationDetails>.LanguageSupport.DomainUnload, RVA 0x3850)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x53F0 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_000194C0[];

__attribute__((naked, used, noinline)) void fixup_stub_000053FA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000194C0(%rip)");
}

/* FUNC 0000540A  native -> managed via CLR VTableFixups slot 0x194d0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x194d0, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000052 (gcroot<System::String ^>..PE$AAVString@System@@, RVA 0x388C)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5400 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_000194D0[];

__attribute__((naked, used, noinline)) void fixup_stub_0000540A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000194D0(%rip)");
}

/* FUNC 0000541A  native -> managed via CLR VTableFixups slot 0x194e0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x194e0, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000053 (gcroot<System::String ^>.=, RVA 0x38B0)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5410 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_000194E0[];

__attribute__((naked, used, noinline)) void fixup_stub_0000541A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000194E0(%rip)");
}

/* FUNC 0000542A  native -> managed via CLR VTableFixups slot 0x194f0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x194f0, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000054 (gcroot<System::String ^>.{dtor}, RVA 0x38D8)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5420 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_000194F0[];

__attribute__((naked, used, noinline)) void fixup_stub_0000542A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000194F0(%rip)");
}

/* FUNC 0000543A  native -> managed via CLR VTableFixups slot 0x19500
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19500, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000055 (gcroot<System::String ^>.{ctor}, RVA 0x3900)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5430 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_00019500[];

__attribute__((naked, used, noinline)) void fixup_stub_0000543A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019500(%rip)");
}

/* FUNC 0000544A  native -> managed via CLR VTableFixups slot 0x19510
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19510, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600002B (<CrtImplementationDetails>.ThrowNestedModuleLoadException, RVA 0x3940)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5440 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_00019510[];

__attribute__((naked, used, noinline)) void fixup_stub_0000544A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019510(%rip)");
}

/* FUNC 0000545A  native -> managed via CLR VTableFixups slot 0x19520
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19520, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000042 (<CrtImplementationDetails>.LanguageSupport.InitializeVtables, RVA 0x3994)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5450 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_00019520[];

__attribute__((naked, used, noinline)) void fixup_stub_0000545A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019520(%rip)");
}

/* FUNC 0000546A  native -> managed via CLR VTableFixups slot 0x19530
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19530, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000043 (<CrtImplementationDetails>.LanguageSupport.InitializeDefaultAppDomain, RVA 0x39C8)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5460 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_00019530[];

__attribute__((naked, used, noinline)) void fixup_stub_0000546A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019530(%rip)");
}

/* FUNC 0000547A  native -> managed via CLR VTableFixups slot 0x19540
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19540, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000044 (<CrtImplementationDetails>.LanguageSupport.InitializeNative, RVA 0x39E8)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5470 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_00019540[];

__attribute__((naked, used, noinline)) void fixup_stub_0000547A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019540(%rip)");
}

/* FUNC 0000548A  native -> managed via CLR VTableFixups slot 0x19550
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19550, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000045 (<CrtImplementationDetails>.LanguageSupport.InitializePerProcess, RVA 0x3A78)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5480 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_00019550[];

__attribute__((naked, used, noinline)) void fixup_stub_0000548A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019550(%rip)");
}

/* FUNC 0000549A  native -> managed via CLR VTableFixups slot 0x19560
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19560, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000046 (<CrtImplementationDetails>.LanguageSupport.InitializePerAppDomain, RVA 0x3AB8)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5490 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_00019560[];

__attribute__((naked, used, noinline)) void fixup_stub_0000549A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019560(%rip)");
}

/* FUNC 000054AA  native -> managed via CLR VTableFixups slot 0x19570
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19570, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000047 (<CrtImplementationDetails>.LanguageSupport.InitializeUninitializer, RVA 0x3AF4)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x54A0 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_00019570[];

__attribute__((naked, used, noinline)) void fixup_stub_000054AA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019570(%rip)");
}

/* FUNC 000054BA  native -> managed via CLR VTableFixups slot 0x19580
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19580, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000048 (<CrtImplementationDetails>.LanguageSupport._Initialize, RVA 0x3B20)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x54B0 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_00019580[];

__attribute__((naked, used, noinline)) void fixup_stub_000054BA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019580(%rip)");
}

/* FUNC 000054CA  native -> managed via CLR VTableFixups slot 0x19590
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19590, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600004D (<CrtImplementationDetails>.LanguageSupport.Cleanup, RVA 0x3C24)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x54C0 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_00019590[];

__attribute__((naked, used, noinline)) void fixup_stub_000054CA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019590(%rip)");
}

/* FUNC 000054DA  native -> managed via CLR VTableFixups slot 0x195a0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x195a0, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600004E (<CrtImplementationDetails>.LanguageSupport.{ctor}, RVA 0x3C98)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x54D0 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_000195A0[];

__attribute__((naked, used, noinline)) void fixup_stub_000054DA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000195A0(%rip)");
}

/* FUNC 000054EA  native -> managed via CLR VTableFixups slot 0x195b0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x195b0, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600004F (<CrtImplementationDetails>.LanguageSupport.{dtor}, RVA 0x3CB0)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x54E0 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_000195B0[];

__attribute__((naked, used, noinline)) void fixup_stub_000054EA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000195B0(%rip)");
}

/* FUNC 000054FA  native -> managed via CLR VTableFixups slot 0x195c0
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x195c0, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000050 (<CrtImplementationDetails>.LanguageSupport.Initialize, RVA 0x3CC4)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x54F0 (eb08 bytes) jumps here; site instruction ff25c0400100
*/
extern unsigned char fixup_slot_000195C0[];

__attribute__((naked, used, noinline)) void fixup_stub_000054FA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000195C0(%rip)");
}

/* FUNC 0000557A  native -> managed via CLR VTableFixups slot 0x19608
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19608, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000056 (___CxxCallUnwindDtor, RVA 0x3E08)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5570 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019608[];

__attribute__((naked, used, noinline)) void fixup_stub_0000557A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019608(%rip)");
}

/* FUNC 0000558A  native -> managed via CLR VTableFixups slot 0x19618
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19618, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000057 (___CxxCallUnwindDelDtor, RVA 0x3E4C)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5580 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019618[];

__attribute__((naked, used, noinline)) void fixup_stub_0000558A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019618(%rip)");
}

/* FUNC 0000559A  native -> managed via CLR VTableFixups slot 0x19628
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19628, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000058 (___CxxCallUnwindVecDtor, RVA 0x3E90)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5590 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019628[];

__attribute__((naked, used, noinline)) void fixup_stub_0000559A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019628(%rip)");
}

/* FUNC 000055AA  native -> managed via CLR VTableFixups slot 0x19638
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19638, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600005B (__ArrayUnwind, RVA 0x3F24)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x55A0 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019638[];

__attribute__((naked, used, noinline)) void fixup_stub_000055AA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019638(%rip)");
}

/* FUNC 000055BA  native -> managed via CLR VTableFixups slot 0x19648
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19648, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000059 (__ehvec_dtor, RVA 0x3F7C)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x55B0 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019648[];

__attribute__((naked, used, noinline)) void fixup_stub_000055BA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019648(%rip)");
}

/* FUNC 000055CA  native -> managed via CLR VTableFixups slot 0x19658
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19658, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600005C (__ehvec_dtor, RVA 0x3FDC)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x55C0 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019658[];

__attribute__((naked, used, noinline)) void fixup_stub_000055CA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019658(%rip)");
}

/* FUNC 000055DA  native -> managed via CLR VTableFixups slot 0x19668
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19668, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600005A (?A0x9c83a709.ArrayUnwindFilter, RVA 0x3EEC)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x55D0 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019668[];

__attribute__((naked, used, noinline)) void fixup_stub_000055DA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019668(%rip)");
}

/* FUNC 000055EA  native -> managed via CLR VTableFixups slot 0x19678
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19678, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600006B (_atexit_helper, RVA 0x419C)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x55E0 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019678[];

__attribute__((naked, used, noinline)) void fixup_stub_000055EA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019678(%rip)");
}

/* FUNC 000055FA  native -> managed via CLR VTableFixups slot 0x19688
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19688, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600006C (_exit_callback, RVA 0x4314)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x55F0 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019688[];

__attribute__((naked, used, noinline)) void fixup_stub_000055FA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019688(%rip)");
}

/* FUNC 0000560A  native -> managed via CLR VTableFixups slot 0x19698
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19698, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600006F (_atexit_m, RVA 0x43C4)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5600 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019698[];

__attribute__((naked, used, noinline)) void fixup_stub_0000560A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019698(%rip)");
}

/* FUNC 0000561A  native -> managed via CLR VTableFixups slot 0x196a8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x196a8, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000071 (_app_exit_callback, RVA 0x43EC)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5610 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_000196A8[];

__attribute__((naked, used, noinline)) void fixup_stub_0000561A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000196A8(%rip)");
}

/* FUNC 0000562A  native -> managed via CLR VTableFixups slot 0x196b8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x196b8, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000073 (_atexit_m_appdomain, RVA 0x44D8)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5620 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_000196B8[];

__attribute__((naked, used, noinline)) void fixup_stub_0000562A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000196B8(%rip)");
}

/* FUNC 0000563A  native -> managed via CLR VTableFixups slot 0x196c8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x196c8, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600006D (_initatexit_m, RVA 0x4564)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5630 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_000196C8[];

__attribute__((naked, used, noinline)) void fixup_stub_0000563A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000196C8(%rip)");
}

/* FUNC 0000564A  native -> managed via CLR VTableFixups slot 0x196d8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x196d8, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600006E (_onexit_m, RVA 0x45AC)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5640 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_000196D8[];

__attribute__((naked, used, noinline)) void fixup_stub_0000564A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000196D8(%rip)");
}

/* FUNC 0000565A  native -> managed via CLR VTableFixups slot 0x196e8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x196e8, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000070 (_initatexit_app_domain, RVA 0x45C8)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5650 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_000196E8[];

__attribute__((naked, used, noinline)) void fixup_stub_0000565A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000196E8(%rip)");
}

/* FUNC 0000566A  native -> managed via CLR VTableFixups slot 0x196f8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x196f8, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000072 (_onexit_m_appdomain, RVA 0x460C)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5660 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_000196F8[];

__attribute__((naked, used, noinline)) void fixup_stub_0000566A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000196F8(%rip)");
}

/* FUNC 0000567A  native -> managed via CLR VTableFixups slot 0x19708
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19708, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600005D (<CrtImplementationDetails>.AtExitLock._handle, RVA 0x4008)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5670 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019708[];

__attribute__((naked, used, noinline)) void fixup_stub_0000567A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019708(%rip)");
}

/* FUNC 0000568A  native -> managed via CLR VTableFixups slot 0x19718
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19718, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600005F (<CrtImplementationDetails>.AtExitLock._lock_Set, RVA 0x4038)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5680 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019718[];

__attribute__((naked, used, noinline)) void fixup_stub_0000568A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019718(%rip)");
}

/* FUNC 0000569A  native -> managed via CLR VTableFixups slot 0x19728
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19728, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000060 (<CrtImplementationDetails>.AtExitLock._lock_Get, RVA 0x4088)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5690 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019728[];

__attribute__((naked, used, noinline)) void fixup_stub_0000569A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019728(%rip)");
}

/* FUNC 000056AA  native -> managed via CLR VTableFixups slot 0x19738
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19738, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000061 (<CrtImplementationDetails>.AtExitLock._lock_Destruct, RVA 0x40AC)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x56A0 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019738[];

__attribute__((naked, used, noinline)) void fixup_stub_000056AA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019738(%rip)");
}

/* FUNC 000056BA  native -> managed via CLR VTableFixups slot 0x19748
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19748, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000062 (<CrtImplementationDetails>.AtExitLock.IsInitialized, RVA 0x40D4)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x56B0 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019748[];

__attribute__((naked, used, noinline)) void fixup_stub_000056BA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019748(%rip)");
}

/* FUNC 000056CA  native -> managed via CLR VTableFixups slot 0x19758
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19758, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000064 (<CrtImplementationDetails>.AtExitLock.RemoveRef, RVA 0x40F0)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x56C0 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019758[];

__attribute__((naked, used, noinline)) void fixup_stub_000056CA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019758(%rip)");
}

/* FUNC 000056DA  native -> managed via CLR VTableFixups slot 0x19768
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19768, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000065 (<CrtImplementationDetails>.AtExitLock.Enter, RVA 0x4118)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x56D0 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019768[];

__attribute__((naked, used, noinline)) void fixup_stub_000056DA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019768(%rip)");
}

/* FUNC 000056EA  native -> managed via CLR VTableFixups slot 0x19778
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19778, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000066 (<CrtImplementationDetails>.AtExitLock.Exit, RVA 0x4130)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x56E0 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019778[];

__attribute__((naked, used, noinline)) void fixup_stub_000056EA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019778(%rip)");
}

/* FUNC 000056FA  native -> managed via CLR VTableFixups slot 0x19788
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19788, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000067 (?A0xdf32f105.__global_lock, RVA 0x4148)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x56F0 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019788[];

__attribute__((naked, used, noinline)) void fixup_stub_000056FA(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019788(%rip)");
}

/* FUNC 0000570A  native -> managed via CLR VTableFixups slot 0x19798
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19798, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000068 (?A0xdf32f105.__global_unlock, RVA 0x4168)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5700 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019798[];

__attribute__((naked, used, noinline)) void fixup_stub_0000570A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019798(%rip)");
}

/* FUNC 0000571A  native -> managed via CLR VTableFixups slot 0x197a8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x197a8, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600006A (?A0xdf32f105.__dealloc_global_lock, RVA 0x4188)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5710 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_000197A8[];

__attribute__((naked, used, noinline)) void fixup_stub_0000571A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000197A8(%rip)");
}

/* FUNC 0000572A  native -> managed via CLR VTableFixups slot 0x197b8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x197b8, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600005E (<CrtImplementationDetails>.AtExitLock._lock_Construct, RVA 0x4500)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5720 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_000197B8[];

__attribute__((naked, used, noinline)) void fixup_stub_0000572A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000197B8(%rip)");
}

/* FUNC 0000573A  native -> managed via CLR VTableFixups slot 0x197c8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x197c8, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000063 (<CrtImplementationDetails>.AtExitLock.AddRef, RVA 0x451C)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5730 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_000197C8[];

__attribute__((naked, used, noinline)) void fixup_stub_0000573A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000197C8(%rip)");
}

/* FUNC 0000574A  native -> managed via CLR VTableFixups slot 0x197d8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x197d8, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000069 (?A0xdf32f105.__alloc_global_lock, RVA 0x454C)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5740 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_000197D8[];

__attribute__((naked, used, noinline)) void fixup_stub_0000574A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000197D8(%rip)");
}

/* FUNC 0000575A  native -> managed via CLR VTableFixups slot 0x197e8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x197e8, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000076 (_initterm_e, RVA 0x463C)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5750 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_000197E8[];

__attribute__((naked, used, noinline)) void fixup_stub_0000575A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000197E8(%rip)");
}

/* FUNC 0000576A  native -> managed via CLR VTableFixups slot 0x197f8
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x197f8, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000077 (_initterm, RVA 0x466C)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5760 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_000197F8[];

__attribute__((naked, used, noinline)) void fixup_stub_0000576A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_000197F8(%rip)");
}

/* FUNC 0000577A  native -> managed via CLR VTableFixups slot 0x19808
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19808, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000079 (_initterm_m, RVA 0x46E4)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5770 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019808[];

__attribute__((naked, used, noinline)) void fixup_stub_0000577A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019808(%rip)");
}

/* FUNC 0000578A  native -> managed via CLR VTableFixups slot 0x19818
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19818, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x06000078 (<CrtImplementationDetails>.ThisModule.Handle, RVA 0x4694)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5780 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019818[];

__attribute__((naked, used, noinline)) void fixup_stub_0000578A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019818(%rip)");
}

/* FUNC 0000579A  native -> managed via CLR VTableFixups slot 0x19828
   interface: no parameters and no return handling in this stub; it is a tail
              jump, so the caller frame and the callee signature are inherited
   slot     : image base + 0x19828, Type 0xa, filled by the CLR loader
   static   : slot value = MethodDef 0x0600007A (<CrtImplementationDetails>.ThisModule.ResolveMethod<void const * __clrcall(void)>, RVA 0x46B8)
   dynamic  : the loader rewrites the slot with the runtime entry point, so the
              landing address stays a runtime value (statically unknown).
   evidence : predecessor 0x5790 (eb08 bytes) jumps here; site instruction ff2588400100
*/
extern unsigned char fixup_slot_00019828[];

__attribute__((naked, used, noinline)) void fixup_stub_0000579A(void)
{
    __asm__ __volatile__("jmp *fixup_slot_00019828(%rip)");
}

