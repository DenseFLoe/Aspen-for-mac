/* NATIVE-340 reconstructed C (Hex-Rays) */

/* ---- FUNC 00001DD8 sub_180001DD8 ---- */
_QWORD *__fastcall sub_180001DD8(_QWORD *a1, char a2)
{
  *a1 = &type_info::`vftable';
  if ( (a2 & 1) != 0 )
    j_j_free(a1);
  return a1;
}

/* ---- FUNC 00001E04 sub_180001E04 ---- */
_QWORD *__fastcall sub_180001E04(_QWORD *a1, __int64 a2)
{
  a1[2] = 0;
  *a1 = &std::bad_alloc::`vftable';
  a1[1] = a2;
  return a1;
}

/* ---- FUNC 00001E1C sub_180001E1C ---- */
__int64 __fastcall sub_180001E1C(__int64 a1, __int64 a2)
{
  *(_QWORD *)a1 = &std::exception::`vftable';
  *(_OWORD *)(a1 + 8) = 0;
  _std_exception_copy(a2 + 8);
  *(_QWORD *)a1 = &std::bad_alloc::`vftable';
  return a1;
}

/* ---- FUNC 00001E58 sub_180001E58 ---- */
_QWORD *__fastcall sub_180001E58(_QWORD *a1)
{
  a1[2] = 0;
  a1[1] = "bad allocation";
  *a1 = &std::bad_alloc::`vftable';
  return a1;
}

/* ---- FUNC 00001E78 sub_180001E78 ---- */
__int64 __fastcall sub_180001E78(__int64 a1, __int64 a2)
{
  *(_QWORD *)a1 = &std::exception::`vftable';
  *(_OWORD *)(a1 + 8) = 0;
  _std_exception_copy(a2 + 8);
  *(_QWORD *)a1 = &std::bad_array_new_length::`vftable';
  return a1;
}

/* ---- FUNC 00001EB4 sub_180001EB4 ---- */
_QWORD *__fastcall sub_180001EB4(_QWORD *a1)
{
  a1[2] = 0;
  a1[1] = "bad array new length";
  *a1 = &std::bad_array_new_length::`vftable';
  return a1;
}

/* ---- FUNC 00001ED4 sub_180001ED4 ---- */
__int64 __fastcall sub_180001ED4(__int64 a1, __int64 a2)
{
  *(_QWORD *)a1 = &std::exception::`vftable';
  *(_OWORD *)(a1 + 8) = 0;
  _std_exception_copy(a2 + 8);
  return a1;
}

/* ---- FUNC 00001F08 sub_180001F08 ---- */
_QWORD *__fastcall sub_180001F08(_QWORD *a1, __int64 a2)
{
  *a1 = &std::exception::`vftable';
  a1[2] = 0;
  a1[1] = a2;
  return a1;
}

/* ---- FUNC 00001F20 sub_180001F20 ---- */
__int64 __fastcall sub_180001F20(_QWORD *a1)
{
  *a1 = &std::exception::`vftable';
  return _std_exception_destroy(a1 + 1);
}

/* ---- FUNC 00001F34 sub_180001F34 ---- */
__int64 __fastcall sub_180001F34(_QWORD *a1)
{
  *a1 = &std::exception::`vftable';
  return _std_exception_destroy(a1 + 1);
}

/* ---- FUNC 00001F48 sub_180001F48 ---- */
__int64 __fastcall sub_180001F48(_QWORD *a1)
{
  *a1 = &std::exception::`vftable';
  return _std_exception_destroy(a1 + 1);
}

/* ---- FUNC 00001F5C sub_180001F5C ---- */
char *__fastcall sub_180001F5C(char *Block, char a2)
{
  *(_QWORD *)Block = &std::exception::`vftable';
  _std_exception_destroy(Block + 8);
  if ( (a2 & 1) != 0 )
    j_j_free(Block);
  return Block;
}

/* ---- FUNC 00001FA0 sub_180001FA0 ---- */
char *__fastcall sub_180001FA0(char *Block, char a2)
{
  *(_QWORD *)Block = &std::exception::`vftable';
  _std_exception_destroy(Block + 8);
  if ( (a2 & 1) != 0 )
    j_j_free(Block);
  return Block;
}

/* ---- FUNC 00001FE4 sub_180001FE4 ---- */
char *__fastcall sub_180001FE4(char *Block, char a2)
{
  *(_QWORD *)Block = &std::exception::`vftable';
  _std_exception_destroy(Block + 8);
  if ( (a2 & 1) != 0 )
    j_j_free(Block);
  return Block;
}

/* ---- FUNC 00002028 sub_180002028 ---- */
void __noreturn sub_180002028()
{
  _QWORD pExceptionObject[5]; // [rsp+20h] [rbp-28h] BYREF

  sub_180001E58(pExceptionObject);
  throw (std::bad_alloc *)pExceptionObject;
}

/* ---- FUNC 00002048 sub_180002048 ---- */
void __noreturn sub_180002048()
{
  _QWORD pExceptionObject[5]; // [rsp+20h] [rbp-28h] BYREF

  sub_180001EB4(pExceptionObject);
  throw (std::bad_array_new_length *)pExceptionObject;
}

/* ---- FUNC 00002068 sub_180002068 ---- */
const char *__fastcall sub_180002068(__int64 a1)
{
  const char *result; // rax

  result = "Unknown exception";
  if ( *(_QWORD *)(a1 + 8) != 0 )
    return *(const char **)(a1 + 8);
  return result;
}

/* ---- FUNC 0000207C sub_18000207C ---- */
__int64 __fastcall sub_18000207C(__int64 a1, int a2, __int64 a3)
{
  __int64 result; // rax

  switch ( a2 )
  {
    case 0:
      return sub_1800021E4(a3 != 0);
    case 1:
      return sub_1800020CC(a1, a3);
    case 2:
      LOBYTE(result) = sub_1800026B8();
      break;
    case 3:
      LOBYTE(result) = sub_1800026E0();
      break;
    default:
      return 1;
  }
  return (unsigned __int8)result;
}

/* ---- FUNC 000020CC sub_1800020CC ---- */
__int64 __fastcall sub_1800020CC()
{
  char v0; // bl
  char v1; // di
  _QWORD *v2; // rax

  if ( sub_18000279C(0) == 0 )
    return 0;
  v0 = sub_180002630();
  v1 = 1;
  if ( dword_180019990 != 0 )
  {
    sub_1800029E0(7u);
    __debugbreak();
  }
  dword_180019990 = 1;
  if ( sub_1800026A0() )
  {
    sub_180002C38();
    sub_180002544();
    sub_180002570();
    if ( initterm_e((_PIFV *)&First, (_PIFV *)&Last) == 0 && sub_18000266C() != 0 )
    {
      initterm((_PVFV *)&qword_1800061E0, (_PVFV *)&qword_1800061E8);
      dword_180019990 = 2;
      v1 = 0;
    }
  }
  sub_18000290C(v0);
  if ( v1 != 0 )
    return 0;
  v2 = sub_1800029D0();
  if ( *v2 != 0 && sub_180002874((__int64)v2) )
    guard_dispatch_icall_nop();
  ++dword_180019964;
  return 1;
}

/* ---- FUNC 000021E4 sub_1800021E4 ---- */
_BOOL8 __fastcall sub_1800021E4(char a1)
{
  char v3; // bl
  __int64 v4; // rcx
  BOOL v5; // ebx

  if ( dword_180019964 <= 0 )
    return false;
  --dword_180019964;
  v3 = sub_180002630();
  if ( dword_180019990 != 2 )
  {
    sub_1800029E0(7u);
    __debugbreak();
  }
  sub_180002758();
  sub_180002554();
  sub_180002C74();
  dword_180019990 = 0;
  sub_18000290C(v3);
  LOBYTE(v4) = a1;
  v5 = sub_180002930(v4, 0) != 0;
  sub_180002788();
  return v5;
}

/* ---- FUNC 00002268 sub_180002268 ---- */
__int64 __fastcall sub_180002268(HMODULE a1, int a2, __int64 a3)
{
  unsigned int v7; // ebx
  unsigned int v8; // eax

  if ( a2 == 0 && dword_180019964 <= 0 )
    return 0;
  if ( (unsigned int)(a2 - 1) > 1 || (v7 = sub_18000207C((__int64)a1, a2, a3)) != 0 )
  {
    v8 = sub_180002520(a1, a2);
    v7 = v8;
    if ( a2 == 1 && v8 == 0 )
    {
      sub_180002520(a1, 0);
      sub_1800021E4(a3 != 0);
    }
    if ( a2 == 0 || a2 == 3 )
      return (unsigned int)sub_18000207C((__int64)a1, a2, a3) != 0;
  }
  return v7;
}

/* ---- FUNC 000023B8 sub_1800023B8 ---- */
// attributes: thunk
__int64 __fastcall sub_1800023B8(__int64 a1, int a2, __int64 a3)
{
  return sub_18000207C(a1, a2, a3);
}

/* ---- FUNC 000023C0 sub_1800023C0 ---- */
__int64 __fastcall sub_1800023C0(HMODULE a1, int a2, __int64 a3)
{
  if ( a2 == 1 )
    _security_init_cookie();
  return sub_180002268(a1, a2, a3);
}

/* ---- FUNC 00002400 j_j_free ---- */
// attributes: thunk
void __cdecl j_j_free(void *Block)
{
  j_free(Block);
}

/* ---- FUNC 00002408 sub_180002408 ---- */
unsigned __int64 sub_180002408()
{
  struct _FILETIME v1; // [rsp+30h] [rbp+10h] BYREF
  struct _FILETIME SystemTimeAsFileTime; // [rsp+38h] [rbp+18h] BYREF
  LARGE_INTEGER PerformanceCount; // [rsp+40h] [rbp+20h] BYREF

  SystemTimeAsFileTime = 0;
  GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
  v1 = SystemTimeAsFileTime;
  v1 = (struct _FILETIME)(GetCurrentThreadId() ^ *(unsigned __int64 *)&v1);
  v1 = (struct _FILETIME)(GetCurrentProcessId() ^ *(unsigned __int64 *)&v1);
  QueryPerformanceCounter(&PerformanceCount);
  return ((unsigned __int64)&v1
        ^ *(_QWORD *)&v1
        ^ PerformanceCount.QuadPart
        ^ ((unsigned __int64)PerformanceCount.LowPart << 32))
       & 0xFFFFFFFFFFFFLL;
}

/* ---- FUNC 00002474 __security_init_cookie ---- */
void __cdecl _security_init_cookie()
{
  uintptr_t v0; // rax
  struct _FILETIME v1; // [rsp+20h] [rbp-10h] BYREF
  struct _FILETIME SystemTimeAsFileTime; // [rsp+40h] [rbp+10h] BYREF
  LARGE_INTEGER PerformanceCount; // [rsp+48h] [rbp+18h] BYREF

  v0 = _security_cookie;
  if ( _security_cookie == 0x2B992DDFA232LL )
  {
    SystemTimeAsFileTime = 0;
    GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
    v1 = SystemTimeAsFileTime;
    v1 = (struct _FILETIME)(GetCurrentThreadId() ^ *(unsigned __int64 *)&v1);
    v1 = (struct _FILETIME)(GetCurrentProcessId() ^ *(unsigned __int64 *)&v1);
    QueryPerformanceCounter(&PerformanceCount);
    v0 = ((unsigned __int64)&v1
        ^ *(_QWORD *)&v1
        ^ PerformanceCount.QuadPart
        ^ ((unsigned __int64)PerformanceCount.LowPart << 32))
       & 0xFFFFFFFFFFFFLL;
    if ( v0 == 0x2B992DDFA232LL )
      v0 = 0x2B992DDFA233LL;
    _security_cookie = v0;
  }
  _security_cookie_complement = ~v0;
}

/* ---- FUNC 00002520 sub_180002520 ---- */
__int64 __fastcall sub_180002520(HMODULE a1, int a2)
{
  if ( a2 == 1 )
    DisableThreadLibraryCalls(a1);
  return 1;
}

/* ---- FUNC 00002544 sub_180002544 ---- */
void sub_180002544()
{
  InitializeSListHead(&stru_180019970);
}

/* ---- FUNC 00002554 sub_180002554 ---- */
__int64 sub_180002554()
{
  return _std_type_info_destroy_list(&stru_180019970);
}

/* ---- FUNC 00002560 sub_180002560 ---- */
void *sub_180002560()
{
  return &unk_180019980;
}

/* ---- FUNC 00002568 sub_180002568 ---- */
void *sub_180002568()
{
  return &unk_180019988;
}

/* ---- FUNC 00002570 sub_180002570 ---- */
_QWORD *sub_180002570()
{
  _QWORD *v0; // rax
  _QWORD *result; // rax

  v0 = sub_180002560();
  *v0 |= 0x24uLL;
  result = sub_180002568();
  *result |= 2uLL;
  return result;
}

/* ---- FUNC 0000258C sub_18000258C ---- */
errno_t sub_18000258C()
{
  _crt_argv_mode v0; // eax

  v0 = (unsigned int)sub_1800030E0();
  return configure_narrow_argv(v0);
}

/* ---- FUNC 000025A0 sub_1800025A0 ---- */
__int64 __fastcall sub_1800025A0(__int64 a1, unsigned __int64 a2)
{
  __int64 v2; // r8
  __int64 v3; // r9
  __int64 v4; // r8
  unsigned __int64 v5; // rcx

  v2 = *(int *)(a1 + 60);
  v3 = *(unsigned __int16 *)(v2 + a1 + 20) + 24LL + v2 + a1;
  v4 = v3 + 40LL * *(unsigned __int16 *)(v2 + a1 + 6);
  while ( v3 != v4 )
  {
    v5 = *(unsigned int *)(v3 + 12);
    if ( a2 >= v5 && a2 < (unsigned int)(v5 + *(_DWORD *)(v3 + 8)) )
      return v3;
    v3 += 40;
  }
  return 0;
}

/* ---- FUNC 000025EC j__initialize_narrow_environment ---- */
// attributes: thunk
int __cdecl j__initialize_narrow_environment()
{
  return initialize_narrow_environment();
}

/* ---- FUNC 00002628 sub_180002628 ---- */
__int64 __fastcall sub_180002628()
{
  char v0; // al

  return v0 & 0x30;
}

/* ---- FUNC 00002630 sub_180002630 ---- */
char sub_180002630()
{
  PVOID StackBase; // rcx
  signed __int64 v1; // rax

  if ( sub_1800030E8() )
  {
    StackBase = NtCurrentTeb()->NtTib.StackBase;
    while ( 1 )
    {
      v1 = _InterlockedCompareExchange64(&qword_180019998, (signed __int64)StackBase, 0);
      if ( v1 == 0 )
        break;
      if ( StackBase == (PVOID)v1 )
        return 1;
    }
  }
  return 0;
}

/* ---- FUNC 0000266C sub_18000266C ---- */
char sub_18000266C()
{
  _crt_argv_mode v0; // eax

  if ( sub_1800030E8() )
  {
    sub_180002F34();
  }
  else
  {
    v0 = (unsigned int)sub_1800030E0();
    if ( configure_narrow_argv(v0) != 0 )
      return 0;
    initialize_narrow_environment();
  }
  return 1;
}

/* ---- FUNC 000026A0 sub_1800026A0 ---- */
bool sub_1800026A0()
{
  return sub_1800027E8(0) != 0;
}

/* ---- FUNC 000026B8 sub_1800026B8 ---- */
char sub_1800026B8()
{
  if ( sub_1800047F0() == 0 )
    return 0;
  if ( sub_1800047F0() == 0 )
  {
    sub_1800047F4();
    return 0;
  }
  return 1;
}

/* ---- FUNC 000026E0 sub_1800026E0 ---- */
char sub_1800026E0()
{
  sub_1800047F4();
  sub_1800047F4();
  return 1;
}

/* ---- FUNC 000026F8 sub_1800026F8 ---- */
int __fastcall sub_1800026F8(
        __int64 a1,
        int a2,
        __int64 a3,
        void (__fastcall *a4)(__int64, _QWORD, __int64),
        unsigned int ExceptionNum,
        struct _EXCEPTION_POINTERS *ExceptionPtr)
{
  if ( !sub_1800030E8() && a2 == 1 )
    a4(a1, 0, a3);
  return seh_filter_dll(ExceptionNum, ExceptionPtr);
}

/* ---- FUNC 00002758 sub_180002758 ---- */
void sub_180002758()
{
  if ( sub_1800030E8() )
  {
    execute_onexit_table(&Table);
  }
  else if ( (unsigned int)sub_180004800() == 0 )
  {
    cexit();
  }
}

/* ---- FUNC 00002788 sub_180002788 ---- */
char sub_180002788()
{
  sub_1800047FC();
  return sub_1800047FC();
}

/* ---- FUNC 0000279C sub_18000279C ---- */
char __fastcall sub_18000279C(int a1)
{
  char v1; // al

  v1 = byte_1800199A0;
  if ( a1 == 0 )
    v1 = 1;
  byte_1800199A0 = v1;
  sub_180002F34();
  if ( sub_1800047EC() == 0 )
    return 0;
  if ( sub_1800047EC() == 0 )
  {
    sub_1800047F8();
    return 0;
  }
  return 1;
}

/* ---- FUNC 000027E8 sub_1800027E8 ---- */
char __fastcall sub_1800027E8(unsigned int a1)
{
  if ( byte_1800199A1 == 0 )
  {
    if ( a1 > 1 )
    {
      sub_1800029E0(5u);
      JUMPOUT(0x180002872LL);
    }
    if ( !sub_1800030E8() || a1 != 0 )
    {
      *(__int128 *)&Table._first = xmmword_180006310;
      Table._end = (_PVFV *)-1LL;
      *(__int128 *)&stru_1800199C0._first = xmmword_180006310;
      stru_1800199C0._end = (_PVFV *)-1LL;
    }
    else if ( initialize_onexit_table(&Table) != 0 || initialize_onexit_table(&stru_1800199C0) != 0 )
    {
      return 0;
    }
    byte_1800199A1 = 1;
  }
  return 1;
}

/* ---- FUNC 00002874 sub_180002874 ---- */
bool __fastcall sub_180002874(__int64 a1)
{
  _DWORD *v2; // rcx
  unsigned __int64 v3; // r8
  _DWORD *v4; // rdx
  _DWORD *v5; // r9
  unsigned __int64 v6; // rcx

  if ( MEMORY[0x180000000] != 23117 )
    return false;
  v2 = (_DWORD *)(0x180000000LL + MEMORY[0x18000003C]);
  if ( *v2 != 17744 || *(_WORD *)(0x180000018LL + MEMORY[0x18000003C]) != 523 )
    return false;
  v3 = a1 - 0x180000000LL;
  v4 = (_DWORD *)((char *)v2 + *(unsigned __int16 *)(0x180000014LL + MEMORY[0x18000003C]) + 24);
  v5 = &v4[10 * *(unsigned __int16 *)(0x180000006LL + MEMORY[0x18000003C])];
  while ( v4 != v5 )
  {
    v6 = (unsigned int)v4[3];
    if ( v3 >= v6 && v3 < (unsigned int)(v6 + v4[2]) )
      return v4 != nullptr && v4[9] >= 0;
    v4 += 10;
  }
  v4 = nullptr;
  return v4 != nullptr && v4[9] >= 0;
}

/* ---- FUNC 0000290C sub_18000290C ---- */
_BOOL8 __fastcall sub_18000290C(char a1)
{
  _BOOL8 result; // rax

  result = sub_1800030E8();
  if ( result && a1 == 0 )
    _InterlockedExchange64(&qword_180019998, 0);
  return result;
}

/* ---- FUNC 00002930 sub_180002930 ---- */
char __fastcall sub_180002930(__int64 a1, char a2)
{
  if ( byte_1800199A0 == 0 || a2 == 0 )
  {
    sub_1800047F8();
    sub_1800047F8();
  }
  return 1;
}

/* ---- FUNC 0000295C sub_18000295C ---- */
void (__cdecl *__fastcall sub_18000295C(void (__cdecl *Function)()))()
{
  int v2; // eax
  __int64 v3; // rdx

  if ( Table._first == (_PVFV *)-1LL )
    v2 = crt_atexit(Function);
  else
    v2 = register_onexit_function(&Table, (_onexit_t)Function);
  v3 = 0;
  if ( v2 == 0 )
    return Function;
  return (void (__cdecl *)())v3;
}

/* ---- FUNC 000029B8 sub_1800029B8 ---- */
__int64 __fastcall sub_1800029B8(void (__cdecl *a1)())
{
  return (unsigned int)(sub_18000295C(a1) != nullptr) - 1;
}

/* ---- FUNC 000029D0 sub_1800029D0 ---- */
void *sub_1800029D0()
{
  return &unk_180019B78;
}

/* ---- FUNC 000029D8 sub_1800029D8 ---- */
void sub_1800029D8()
{
  dword_1800199D8 = 0;
}

/* ---- FUNC 000029E0 sub_1800029E0 ---- */
void __fastcall sub_1800029E0(unsigned int a1)
{
  ULONG64 Rip; // rbx
  struct _IMAGE_RUNTIME_FUNCTION_ENTRY *v3; // rax
  bool v4; // bl
  struct _EXCEPTION_POINTERS ExceptionInfo; // [rsp+40h] [rbp-C0h] BYREF
  _QWORD v6[20]; // [rsp+50h] [rbp-B0h] BYREF
  struct _CONTEXT ContextRecord; // [rsp+F0h] [rbp-10h] BYREF
  DWORD64 retaddr; // [rsp+5C8h] [rbp+4C8h]
  __int64 v9; // [rsp+5D0h] [rbp+4D0h] BYREF
  unsigned __int64 ImageBase; // [rsp+5D8h] [rbp+4D8h] BYREF
  unsigned __int64 EstablisherFrame; // [rsp+5E0h] [rbp+4E0h] BYREF
  PVOID HandlerData; // [rsp+5E8h] [rbp+4E8h] BYREF

  if ( IsProcessorFeaturePresent(0x17u) )
    __fastfail(a1);
  sub_1800029D8();
  memset(&ContextRecord, 0, sizeof(ContextRecord));
  RtlCaptureContext(&ContextRecord);
  Rip = ContextRecord.Rip;
  v3 = RtlLookupFunctionEntry(ContextRecord.Rip, &ImageBase, nullptr);
  if ( v3 != nullptr )
    RtlVirtualUnwind(0, ImageBase, Rip, v3, &ContextRecord, &HandlerData, &EstablisherFrame, nullptr);
  ContextRecord.Rip = retaddr;
  ContextRecord.Rsp = (DWORD64)&v9;
  memset(v6, 0, 0x98u);
  v6[2] = retaddr;
  v6[0] = 0x140000015LL;
  ExceptionInfo.ExceptionRecord = (PEXCEPTION_RECORD)v6;
  v4 = IsDebuggerPresent();
  ExceptionInfo.ContextRecord = &ContextRecord;
  SetUnhandledExceptionFilter(nullptr);
  if ( UnhandledExceptionFilter(&ExceptionInfo) == 0 && !v4 )
    sub_1800029D8();
}

/* ---- FUNC 00002B2C sub_180002B2C ---- */
WORD sub_180002B2C()
{
  WORD result; // ax
  struct _STARTUPINFOW StartupInfo; // [rsp+20h] [rbp-78h] BYREF

  memset(&StartupInfo, 0, sizeof(StartupInfo));
  GetStartupInfoW(&StartupInfo);
  result = 10;
  if ( (StartupInfo.dwFlags & 1) != 0 )
    return StartupInfo.wShowWindow;
  return result;
}

/* ---- FUNC 00002B70 sub_180002B70 ---- */
__int64 sub_180002B70()
{
  return 0;
}

/* ---- FUNC 00002B74 sub_180002B74 ---- */
bool sub_180002B74()
{
  HMODULE ModuleHandleW; // rax
  char *v1; // rcx

  ModuleHandleW = GetModuleHandleW(nullptr);
  return ModuleHandleW != nullptr
      && *(_WORD *)ModuleHandleW == 23117
      && *(_DWORD *)(v1 = (char *)ModuleHandleW + *((int *)ModuleHandleW + 15)) == 17744
      && *((_WORD *)v1 + 12) == 523
      && *((_DWORD *)v1 + 33) > 0xEu
      && *((_DWORD *)v1 + 62) != 0;
}

/* ---- FUNC 00002BC8 sub_180002BC8 ---- */
LPTOP_LEVEL_EXCEPTION_FILTER sub_180002BC8()
{
  return SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)sub_180002BDC);
}

/* ---- FUNC 00002BDC sub_180002BDC ---- */
__int64 __fastcall sub_180002BDC(_QWORD *a1)
{
  _DWORD *v1; // rbx
  int v3; // edx
  __int64 v5; // rbx

  v1 = (_DWORD *)*a1;
  if ( *(_DWORD *)*a1 == -529697949 && v1[6] == 4 )
  {
    v3 = v1[8];
    if ( (unsigned int)(v3 - 429065504) <= 2 || v3 == 26820608 )
    {
      *(_QWORD *)_current_exception() = v1;
      v5 = a1[1];
      *(_QWORD *)_current_exception_context() = v5;
      terminate();
    }
  }
  return 0;
}

/* ---- FUNC 00002C38 sub_180002C38 ---- */
void sub_180002C38()
{
  void (**i)(void); // rbx

  for ( i = &qword_180017590; i < &qword_180017590; ++i )
  {
    if ( *i != nullptr )
      (*i)();
  }
}

/* ---- FUNC 00002C74 sub_180002C74 ---- */
void sub_180002C74()
{
  void (**i)(void); // rbx

  for ( i = &qword_1800175A0; i < &qword_1800175A0; ++i )
  {
    if ( *i != nullptr )
      (*i)();
  }
}

/* ---- FUNC 00002CB0 _guard_check_icall_nop ---- */
void guard_check_icall_nop()
{
  ;
}

/* ---- FUNC 00002CB4 sub_180002CB4 ---- */
__int64 __fastcall sub_180002CB4(__int64 a1)
{
  return *(_QWORD *)a1;
}

/* ---- FUNC 00002CB8 sub_180002CB8 ---- */
__int64 __fastcall sub_180002CB8(__int64 a1)
{
  return *(_QWORD *)a1;
}

/* ---- FUNC 00002CFC nullsub_1 ---- */
void nullsub_1()
{
  ;
}

/* ---- FUNC 00002D00 sub_180002D00 ---- */
signed __int64 __fastcall sub_180002D00(_BYTE *a1)
{
  signed __int64 result; // rax

  result = a1 - (_BYTE *)&unk_180016580;
  if ( a1 == (_BYTE *)&unk_180016580 )
    return 0;
  return result;
}

/* ---- FUNC 00002D3C sub_180002D3C ---- */
__int64 sub_180002D3C()
{
  return 0;
}

/* ---- FUNC 00002D5C sub_180002D5C ---- */
__int64 (*__fastcall sub_180002D5C(_BYTE *a1))(void)
{
  __int64 (*result)(void); // rax

  result = (__int64 (*)(void))(a1 - (_BYTE *)&unk_180016580);
  if ( a1 == (_BYTE *)&unk_180016580 )
  {
    result = (__int64 (*)(void))qword_1800199E0;
    if ( qword_1800199E0 != nullptr )
      return qword_1800199E0();
  }
  return result;
}

/* ---- FUNC 00002D94 sub_180002D94 ---- */
__int64 (*sub_180002D94())(void)
{
  __int64 (*result)(void); // rax

  result = (__int64 (*)(void))qword_1800199E0;
  if ( qword_1800199E0 != nullptr )
    return qword_1800199E0();
  return result;
}

/* ---- FUNC 00002DD0 sub_180002DD0 ---- */
__int64 __fastcall sub_180002DD0(__int64 a1)
{
  return _InterlockedExchange64((volatile __int64 *)&qword_1800199E0, a1);
}

/* ---- FUNC 00002E4C nullsub_2 ---- */
void nullsub_2()
{
  ;
}

/* ---- FUNC 00002E50 sub_180002E50 ---- */
unsigned __int64 __fastcall sub_180002E50(char *a1, __int64 a2, unsigned __int64 a3)
{
  unsigned __int64 result; // rax

  result = &a1[-a2] - (char *)&unk_180016500 - 128;
  if ( result > a3 )
  {
    result = 0;
    if ( a1 == (char *)&unk_180016580 )
      return 0;
  }
  return result;
}

/* ---- FUNC 00002EA4 sub_180002EA4 ---- */
__int64 (*__fastcall sub_180002EA4(char *a1, __int64 a2, unsigned __int64 a3))(void)
{
  __int64 (*result)(void); // rax

  result = (__int64 (*)(void))(&a1[-a2] - (char *)&unk_180016500 - 128);
  if ( (unsigned __int64)result > a3 )
  {
    result = nullptr;
    if ( a1 == (char *)&unk_180016580 )
    {
      result = (__int64 (*)(void))qword_1800199E0;
      if ( qword_1800199E0 != nullptr )
        return qword_1800199E0();
    }
  }
  return result;
}

/* ---- FUNC 00002EF4 sub_180002EF4 ---- */
_BOOL8 __fastcall sub_180002EF4(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  return a1 - a2 - (__int64)&unk_180016500 - 128 > a3;
}

/* ---- FUNC 00002F28 sub_180002F28 ---- */
__int64 sub_180002F28()
{
  return 0;
}

/* ---- FUNC 00002F2C j_free ---- */
// attributes: thunk
void __cdecl j_free(void *Block)
{
  free(Block);
}

/* ---- FUNC 00002F34 sub_180002F34 ---- */
__int64 sub_180002F34()
{
  int v5; // r11d
  int v6; // r9d
  int v7; // esi
  int v9; // r10d
  int v14; // edi
  int v15; // eax
  int v16; // eax
  __int64 v17; // rcx
  int v18; // r8d
  int v23; // eax
  char v25; // [rsp+20h] [rbp+8h]

  _RAX = 0;
  __asm { cpuid }
  v5 = 0;
  v6 = _RBX;
  v7 = _RAX;
  _RAX = 1;
  v9 = _RCX ^ 0x6C65746E | _RDX ^ 0x49656E69;
  __asm { cpuid }
  v14 = _RCX;
  if ( (v6 ^ 0x756E6547 | v9) == 0
    && ((qword_180019378 = -1, v15 = _RAX & 0xFFF3FF0, qword_180019370 = 0x8000, v15 == 67264)
     || v15 == 132704
     || v15 == 132720
     || (unsigned int)(v16 = v15 - 198224) <= 0x20 && (v17 = 0x100010001LL, _bittest64(&v17, (unsigned __int8)v16))) )
  {
    v18 = dword_1800199E8 | 1;
    dword_1800199E8 |= 1u;
  }
  else
  {
    v18 = dword_1800199E8;
  }
  _RAX = 7;
  if ( v7 >= 7 )
  {
    __asm { cpuid }
    v5 = _RBX;
    if ( (_RBX & 0x200) != 0 )
      dword_1800199E8 = v18 | 2;
  }
  dword_180019368 = 1;
  dword_18001936C = 2;
  if ( (v14 & 0x100000) != 0 )
  {
    dword_180019368 = 2;
    dword_18001936C = 6;
    if ( (v14 & 0x8000000) != 0 && (v14 & 0x10000000) != 0 )
    {
      __asm { xgetbv }
      v25 = _RAX;
      if ( (_RAX & 6) == 6 )
      {
        v23 = dword_18001936C | 8;
        dword_180019368 = 3;
        dword_18001936C |= 8u;
        if ( (v5 & 0x20) != 0 )
        {
          dword_180019368 = 5;
          dword_18001936C = v23 | 0x20;
          if ( (v5 & 0xD0030000) == 0xD0030000 && (v25 & 0xE0) == 0xE0 )
          {
            dword_18001936C |= 0x40u;
            dword_180019368 = 6;
          }
        }
      }
    }
  }
  return 0;
}

/* ---- FUNC 000030E0 sub_1800030E0 ---- */
__int64 sub_1800030E0()
{
  return 1;
}

/* ---- FUNC 000030E8 sub_1800030E8 ---- */
_BOOL8 sub_1800030E8()
{
  return dword_180019830 != 0;
}

/* ---- FUNC 00003660 sub_180003660_manual ---- */
/* sub_180003660_manual: IDA failed to decompile; raw disassembly in native.asm */

/* ---- FUNC 0000476B __std_exception_copy ---- */
// attributes: thunk
__int64 __fastcall _std_exception_copy(__int64 a1)
{
  return __std_exception_copy(a1);
}

/* ---- FUNC 00004771 __std_exception_destroy ---- */
// attributes: thunk
__int64 __fastcall _std_exception_destroy(__int64 a1)
{
  return __std_exception_destroy(a1);
}

/* ---- FUNC 00004777 _CxxThrowException ---- */
// attributes: thunk
void __stdcall __noreturn CxxThrowException(void *pExceptionObject, _ThrowInfo *pThrowInfo)
{
  _CxxThrowException(pExceptionObject, pThrowInfo);
}

/* ---- FUNC 0000477D __C_specific_handler ---- */
// attributes: thunk
EXCEPTION_DISPOSITION __cdecl _C_specific_handler(
        struct _EXCEPTION_RECORD *ExceptionRecord,
        void *EstablisherFrame,
        struct _CONTEXT *ContextRecord,
        struct _DISPATCHER_CONTEXT *DispatcherContext)
{
  return __C_specific_handler(ExceptionRecord, EstablisherFrame, ContextRecord, DispatcherContext);
}

/* ---- FUNC 00004783 __std_type_info_destroy_list ---- */
// attributes: thunk
__int64 __fastcall _std_type_info_destroy_list(__int64 a1)
{
  return __std_type_info_destroy_list(a1);
}

/* ---- FUNC 00004789 __current_exception ---- */
// attributes: thunk
__int64 _current_exception(void)
{
  return __current_exception();
}

/* ---- FUNC 0000478F __current_exception_context ---- */
// attributes: thunk
__int64 _current_exception_context(void)
{
  return __current_exception_context();
}

/* ---- FUNC 00004795 memset ---- */
// attributes: thunk
void *__cdecl memset(void *a1, int Val, size_t Size)
{
  return __imp_memset(a1, Val, Size);
}

/* ---- FUNC 0000479B _initterm ---- */
// attributes: thunk
void __cdecl initterm(_PVFV *First, _PVFV *Last)
{
  _initterm(First, Last);
}

/* ---- FUNC 000047A1 _initterm_e ---- */
// attributes: thunk
int __cdecl initterm_e(_PIFV *First, _PIFV *Last)
{
  return _initterm_e(First, Last);
}

/* ---- FUNC 000047A7 _seh_filter_dll ---- */
// attributes: thunk
int __cdecl seh_filter_dll(unsigned int ExceptionNum, struct _EXCEPTION_POINTERS *ExceptionPtr)
{
  return _seh_filter_dll(ExceptionNum, ExceptionPtr);
}

/* ---- FUNC 000047AD _configure_narrow_argv ---- */
// attributes: thunk
errno_t __cdecl configure_narrow_argv(_crt_argv_mode mode)
{
  return _configure_narrow_argv(mode);
}

/* ---- FUNC 000047B3 _initialize_narrow_environment ---- */
// attributes: thunk
int __cdecl initialize_narrow_environment()
{
  return _initialize_narrow_environment();
}

/* ---- FUNC 000047B9 _initialize_onexit_table ---- */
// attributes: thunk
int __cdecl initialize_onexit_table(_onexit_table_t *Table)
{
  return _initialize_onexit_table(Table);
}

/* ---- FUNC 000047BF _register_onexit_function ---- */
// attributes: thunk
int __cdecl register_onexit_function(_onexit_table_t *Table, _onexit_t Function)
{
  return _register_onexit_function(Table, Function);
}

/* ---- FUNC 000047C5 _execute_onexit_table ---- */
// attributes: thunk
int __cdecl execute_onexit_table(_onexit_table_t *Table)
{
  return _execute_onexit_table(Table);
}

/* ---- FUNC 000047CB _crt_atexit ---- */
// attributes: thunk
int __cdecl crt_atexit(_PVFV Function)
{
  return _crt_atexit(Function);
}

/* ---- FUNC 000047D7 _cexit ---- */
// attributes: thunk
void __cdecl cexit()
{
  _cexit();
}

/* ---- FUNC 000047DD terminate ---- */
// attributes: thunk
void __noreturn terminate(void)
{
  __imp_terminate();
}

/* ---- FUNC 000047E3 free ---- */
// attributes: thunk
void __cdecl free(void *Block)
{
  __imp_free(Block);
}

/* ---- FUNC 000047EC sub_1800047EC ---- */
char sub_1800047EC()
{
  return 1;
}

/* ---- FUNC 000047F0 sub_1800047F0 ---- */
char sub_1800047F0()
{
  return 1;
}

/* ---- FUNC 000047F4 sub_1800047F4 ---- */
char sub_1800047F4()
{
  return 1;
}

/* ---- FUNC 000047F8 sub_1800047F8 ---- */
char sub_1800047F8()
{
  return 1;
}

/* ---- FUNC 000047FC sub_1800047FC ---- */
char sub_1800047FC()
{
  return 1;
}

/* ---- FUNC 00004800 sub_180004800 ---- */
__int64 sub_180004800()
{
  return 0;
}

/* ---- FUNC 00004804 j_j_free_0 ---- */
// attributes: thunk
void __cdecl j_j_free_0(void *Block)
{
  j_free(Block);
}

/* ---- FUNC 0000480C sub_18000480C ---- */
// attributes: thunk
void *__fastcall sub_18000480C(size_t Size)
{
  return sub_18000481C(Size);
}

/* ---- FUNC 00004814 j_j_j_free_0 ---- */
// attributes: thunk
void __cdecl j_j_j_free_0(void *Block)
{
  j_j_free_0(Block);
}

/* ---- FUNC 0000481C sub_18000481C ---- */
void *__fastcall sub_18000481C(size_t Size)
{
  size_t i; // rbx
  void *result; // rax

  for ( i = Size; ; Size = i )
  {
    result = malloc(Size);
    if ( result != nullptr )
      break;
    if ( callnewh(i) == 0 )
    {
      if ( i != -1 )
        sub_180002028();
      sub_180002048();
    }
  }
  return result;
}

/* ---- FUNC 00004858 ?__ExceptionPtrDestroy@@YAXPEAX@Z ---- */
// attributes: thunk
void __fastcall __ExceptionPtrDestroy(void *a1)
{
  __imp_?__ExceptionPtrDestroy@@YAXPEAX@Z(a1);
}

/* ---- FUNC 0000485E ?__ExceptionPtrCopy@@YAXPEAXPEBX@Z ---- */
// attributes: thunk
void __fastcall __ExceptionPtrCopy(void *a1, const void *a2)
{
  __imp_?__ExceptionPtrCopy@@YAXPEAXPEBX@Z(a1, a2);
}

/* ---- FUNC 00004864 WideCharToMultiByte ---- */
// attributes: thunk
int __stdcall WideCharToMultiByte(
        UINT CodePage,
        DWORD dwFlags,
        LPCWCH lpWideCharStr,
        int cchWideChar,
        LPSTR lpMultiByteStr,
        int cbMultiByte,
        LPCCH lpDefaultChar,
        LPBOOL lpUsedDefaultChar)
{
  return __imp_WideCharToMultiByte(
           CodePage,
           dwFlags,
           lpWideCharStr,
           cchWideChar,
           lpMultiByteStr,
           cbMultiByte,
           lpDefaultChar,
           lpUsedDefaultChar);
}

/* ---- FUNC 0000486A MultiByteToWideChar ---- */
// attributes: thunk
int __stdcall MultiByteToWideChar(
        UINT CodePage,
        DWORD dwFlags,
        LPCCH lpMultiByteStr,
        int cbMultiByte,
        LPWSTR lpWideCharStr,
        int cchWideChar)
{
  return __imp_MultiByteToWideChar(CodePage, dwFlags, lpMultiByteStr, cbMultiByte, lpWideCharStr, cchWideChar);
}

/* ---- FUNC 00004870 Sleep ---- */
// attributes: thunk
void __stdcall Sleep(DWORD dwMilliseconds)
{
  __imp_Sleep(dwMilliseconds);
}

/* ---- FUNC 00004876 __FrameUnwindFilter ---- */
// attributes: thunk
__int64 _FrameUnwindFilter()
{
  return __FrameUnwindFilter();
}

/* ---- FUNC 0000487C abort ---- */
// attributes: thunk
void __cdecl __noreturn abort()
{
  __imp_abort();
}

/* ---- FUNC 00004882 _callnewh ---- */
// attributes: thunk
int __cdecl callnewh(size_t Size)
{
  return _callnewh(Size);
}

/* ---- FUNC 00004888 malloc ---- */
// attributes: thunk
void *__cdecl malloc(size_t Size)
{
  return __imp_malloc(Size);
}

/* ---- FUNC 0000488E DllEntryPoint ---- */
// attributes: thunk
BOOL __stdcall DllEntryPoint(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
  return CorDllMain(hinstDLL, fdwReason, lpReserved);
}

/* ---- FUNC 00004894 memcpy ---- */
// attributes: thunk
void *__cdecl memcpy(void *a1, const void *Src, size_t Size)
{
  return __imp_memcpy(a1, Src, Size);
}

/* ---- FUNC 000048B0 _guard_dispatch_icall_nop ---- */
__int64 __fastcall guard_dispatch_icall_nop()
{
  __int64 (*v0)(void); // rax

  return v0();
}

/* ---- FUNC 000048D0 _guard_xfg_dispatch_icall_nop ---- */
// attributes: thunk
__int64 __fastcall guard_xfg_dispatch_icall_nop()
{
  __int64 (*v0)(void); // rax

  return v0();
}

/* ---- FUNC 000048D6 sub_1800048D6 ---- */
_BOOL8 __fastcall sub_1800048D6(__int64 a1, __int64 a2)
{
  return sub_18000290C(*(_BYTE *)(a2 + 64));
}

/* ---- FUNC 000048ED sub_1800048ED ---- */
_BOOL8 __fastcall sub_1800048ED(__int64 a1, __int64 a2)
{
  return sub_18000290C(*(_BYTE *)(a2 + 32));
}

/* ---- FUNC 00004906 sub_180004906 ---- */
char sub_180004906()
{
  return sub_180002788();
}

/* ---- FUNC 0000491A sub_18000491A ---- */
int __fastcall sub_18000491A(struct _EXCEPTION_POINTERS *ExceptionPtr, __int64 a2)
{
  return sub_1800026F8(
           *(_QWORD *)(a2 + 96),
           *(_DWORD *)(a2 + 104),
           *(_QWORD *)(a2 + 112),
           (void (__fastcall *)(__int64, _QWORD, __int64))sub_18000207C,
           ExceptionPtr->ExceptionRecord->ExceptionCode,
           ExceptionPtr);
}

/* ---- FUNC 00004950 sub_180004950 ---- */
_BOOL8 __fastcall sub_180004950(_DWORD **a1)
{
  return **a1 == -1073741819;
}

/* ---- FUNC 00005004 sub_180005004 ---- */
// attributes: thunk
__int64 sub_180005004()
{
  return qword_180019018();
}

/* ---- FUNC 00005014 sub_180005014 ---- */
// attributes: thunk
__int64 sub_180005014()
{
  return qword_180019028();
}

/* ---- FUNC 00005024 sub_180005024 ---- */
// attributes: thunk
__int64 sub_180005024()
{
  return qword_180019050();
}

/* ---- FUNC 00005034 sub_180005034 ---- */
// attributes: thunk
__int64 sub_180005034()
{
  return qword_180019078();
}

/* ---- FUNC 00005044 sub_180005044 ---- */
// attributes: thunk
__int64 sub_180005044()
{
  return qword_180019088();
}

/* ---- FUNC 00005054 sub_180005054 ---- */
// attributes: thunk
__int64 sub_180005054()
{
  return qword_180019098();
}

/* ---- FUNC 00005064 sub_180005064 ---- */
// attributes: thunk
__int64 sub_180005064()
{
  return qword_1800190C0();
}

/* ---- FUNC 00005074 sub_180005074 ---- */
// attributes: thunk
__int64 sub_180005074()
{
  return qword_1800190E8();
}

/* ---- FUNC 00005084 sub_180005084 ---- */
// attributes: thunk
__int64 sub_180005084()
{
  return qword_180019110();
}

/* ---- FUNC 00005094 sub_180005094 ---- */
// attributes: thunk
__int64 sub_180005094()
{
  return qword_180019120();
}

/* ---- FUNC 000050A0 ?SaveMergennFiles@@YAXPEAD0@Z ---- */
void __fastcall SaveMergennFiles(char *a1, char *a2)
{
  qword_180019138(a1, a2);
}

/* ---- FUNC 000050B4 sub_1800050B4 ---- */
// attributes: thunk
__int64 sub_1800050B4()
{
  return qword_180019140();
}

/* ---- FUNC 000050C0 sub_1800050C0 ---- */
// attributes: thunk
__int64 sub_1800050C0()
{
  return sub_1800050CA();
}

/* ---- FUNC 000050C4 sub_1800050C4 ---- */
// attributes: thunk
__int64 sub_1800050C4()
{
  return qword_180019150();
}

/* ---- FUNC 000050CA sub_1800050CA ---- */
// attributes: thunk
__int64 sub_1800050CA(void)
{
  return qword_180019158();
}

/* ---- FUNC 000050D4 sub_1800050D4 ---- */
// attributes: thunk
__int64 sub_1800050D4()
{
  return qword_180019160();
}

/* ---- FUNC 000050E4 sub_1800050E4 ---- */
// attributes: thunk
__int64 sub_1800050E4()
{
  return qword_180019170();
}

/* ---- FUNC 000050F4 sub_1800050F4 ---- */
// attributes: thunk
__int64 sub_1800050F4()
{
  return qword_180019180();
}

/* ---- FUNC 00005104 sub_180005104 ---- */
// attributes: thunk
__int64 sub_180005104()
{
  return qword_180019190();
}

/* ---- FUNC 00005110 sub_180005110 ---- */
// attributes: thunk
__int64 sub_180005110()
{
  return sub_18000511A();
}

/* ---- FUNC 00005114 sub_180005114 ---- */
// attributes: thunk
__int64 sub_180005114()
{
  return qword_1800191A0();
}

/* ---- FUNC 0000511A sub_18000511A ---- */
// attributes: thunk
__int64 sub_18000511A(void)
{
  return qword_1800191A8();
}

/* ---- FUNC 00005120 sub_180005120 ---- */
// attributes: thunk
__int64 sub_180005120()
{
  return sub_18000512A();
}

/* ---- FUNC 00005124 sub_180005124 ---- */
// attributes: thunk
__int64 sub_180005124()
{
  return qword_1800191B0();
}

/* ---- FUNC 0000512A sub_18000512A ---- */
// attributes: thunk
__int64 sub_18000512A(void)
{
  return qword_1800191B8();
}

/* ---- FUNC 00005134 sub_180005134 ---- */
// attributes: thunk
__int64 sub_180005134()
{
  return qword_1800191C0();
}

/* ---- FUNC 00005144 sub_180005144 ---- */
// attributes: thunk
__int64 sub_180005144()
{
  return qword_1800191D0();
}

/* ---- FUNC 00005154 sub_180005154 ---- */
// attributes: thunk
__int64 sub_180005154()
{
  return qword_1800191E0();
}

/* ---- FUNC 00005164 sub_180005164 ---- */
// attributes: thunk
__int64 sub_180005164()
{
  return qword_1800191F0();
}

/* ---- FUNC 00005174 sub_180005174 ---- */
// attributes: thunk
__int64 sub_180005174()
{
  return qword_180019200();
}

/* ---- FUNC 00005184 sub_180005184 ---- */
// attributes: thunk
__int64 sub_180005184()
{
  return qword_180019210();
}

/* ---- FUNC 00005194 sub_180005194 ---- */
// attributes: thunk
__int64 sub_180005194()
{
  return qword_180019220();
}

/* ---- FUNC 000051A4 sub_1800051A4 ---- */
// attributes: thunk
__int64 sub_1800051A4()
{
  return qword_180019230();
}

/* ---- FUNC 000051B4 sub_1800051B4 ---- */
// attributes: thunk
__int64 sub_1800051B4()
{
  return qword_180019240();
}

/* ---- FUNC 000051C4 sub_1800051C4 ---- */
// attributes: thunk
__int64 sub_1800051C4()
{
  return qword_180019250();
}

/* ---- FUNC 000051D4 sub_1800051D4 ---- */
// attributes: thunk
__int64 sub_1800051D4()
{
  return qword_180019260();
}

/* ---- FUNC 000051E4 sub_1800051E4 ---- */
// attributes: thunk
__int64 sub_1800051E4()
{
  return qword_180019270();
}

/* ---- FUNC 000051F4 sub_1800051F4 ---- */
// attributes: thunk
__int64 sub_1800051F4()
{
  return qword_180019280();
}

/* ---- FUNC 00005204 sub_180005204 ---- */
// attributes: thunk
__int64 sub_180005204()
{
  return qword_180019290();
}

/* ---- FUNC 00005214 sub_180005214 ---- */
// attributes: thunk
__int64 sub_180005214()
{
  return qword_1800192A0();
}

/* ---- FUNC 00005224 sub_180005224 ---- */
// attributes: thunk
__int64 sub_180005224()
{
  return qword_1800192B0();
}

/* ---- FUNC 00005234 sub_180005234 ---- */
// attributes: thunk
__int64 sub_180005234()
{
  return qword_1800192C0();
}

/* ---- FUNC 00005244 sub_180005244 ---- */
// attributes: thunk
__int64 sub_180005244()
{
  return qword_1800192D0();
}

/* ---- FUNC 00005254 sub_180005254 ---- */
// attributes: thunk
__int64 sub_180005254()
{
  return qword_1800192E0();
}

/* ---- FUNC 00005264 sub_180005264 ---- */
// attributes: thunk
__int64 sub_180005264()
{
  return qword_1800192F0();
}

/* ---- FUNC 00005274 sub_180005274 ---- */
// attributes: thunk
__int64 sub_180005274()
{
  return qword_180019300();
}

/* ---- FUNC 00005284 sub_180005284 ---- */
// attributes: thunk
__int64 sub_180005284()
{
  return qword_180019310();
}

/* ---- FUNC 00005294 sub_180005294 ---- */
// attributes: thunk
__int64 sub_180005294()
{
  return qword_180019320();
}

/* ---- FUNC 000052A4 sub_1800052A4 ---- */
// attributes: thunk
__int64 sub_1800052A4()
{
  return qword_180019330();
}

/* ---- FUNC 000052B4 sub_1800052B4 ---- */
// attributes: thunk
__int64 sub_1800052B4()
{
  return qword_180019340();
}

/* ---- FUNC 000052C4 sub_1800052C4 ---- */
// attributes: thunk
__int64 sub_1800052C4()
{
  return qword_180019388();
}

/* ---- FUNC 000052D4 sub_1800052D4 ---- */
// attributes: thunk
__int64 sub_1800052D4()
{
  return qword_180019398();
}

/* ---- FUNC 000052E4 sub_1800052E4 ---- */
// attributes: thunk
__int64 sub_1800052E4()
{
  return qword_1800193A8();
}

/* ---- FUNC 000052F4 sub_1800052F4 ---- */
// attributes: thunk
__int64 sub_1800052F4()
{
  return qword_1800193B8();
}

/* ---- FUNC 00005304 sub_180005304 ---- */
// attributes: thunk
__int64 sub_180005304()
{
  return qword_1800193C8();
}

/* ---- FUNC 00005314 sub_180005314 ---- */
// attributes: thunk
__int64 sub_180005314()
{
  return qword_1800193D8();
}

/* ---- FUNC 00005324 sub_180005324 ---- */
// attributes: thunk
__int64 sub_180005324()
{
  return qword_1800193E8();
}

/* ---- FUNC 00005334 sub_180005334 ---- */
// attributes: thunk
__int64 sub_180005334()
{
  return qword_1800193F8();
}

/* ---- FUNC 00005344 sub_180005344 ---- */
// attributes: thunk
__int64 sub_180005344()
{
  return qword_180019408();
}

/* ---- FUNC 00005354 sub_180005354 ---- */
// attributes: thunk
__int64 sub_180005354()
{
  return qword_180019418();
}

/* ---- FUNC 00005364 sub_180005364 ---- */
// attributes: thunk
__int64 sub_180005364()
{
  return qword_180019428();
}

/* ---- FUNC 00005374 sub_180005374 ---- */
// attributes: thunk
__int64 sub_180005374()
{
  return qword_180019438();
}

/* ---- FUNC 00005384 sub_180005384 ---- */
// attributes: thunk
__int64 sub_180005384()
{
  return qword_180019448();
}

/* ---- FUNC 00005394 sub_180005394 ---- */
// attributes: thunk
__int64 sub_180005394()
{
  return qword_180019458();
}

/* ---- FUNC 000053A4 sub_1800053A4 ---- */
// attributes: thunk
__int64 sub_1800053A4()
{
  return qword_180019468();
}

/* ---- FUNC 000053B4 sub_1800053B4 ---- */
// attributes: thunk
__int64 sub_1800053B4()
{
  return qword_180019478();
}

/* ---- FUNC 000053C4 sub_1800053C4 ---- */
// attributes: thunk
__int64 sub_1800053C4()
{
  return qword_180019488();
}

/* ---- FUNC 000053D4 sub_1800053D4 ---- */
// attributes: thunk
__int64 sub_1800053D4()
{
  return qword_180019498();
}

/* ---- FUNC 000053E4 sub_1800053E4 ---- */
// attributes: thunk
__int64 sub_1800053E4()
{
  return qword_1800194A8();
}

/* ---- FUNC 000053F4 sub_1800053F4 ---- */
// attributes: thunk
__int64 sub_1800053F4()
{
  return qword_1800194B8();
}

/* ---- FUNC 00005404 sub_180005404 ---- */
// attributes: thunk
__int64 sub_180005404()
{
  return qword_1800194C8();
}

/* ---- FUNC 00005414 sub_180005414 ---- */
// attributes: thunk
__int64 sub_180005414()
{
  return qword_1800194D8();
}

/* ---- FUNC 00005424 sub_180005424 ---- */
// attributes: thunk
__int64 sub_180005424()
{
  return qword_1800194E8();
}

/* ---- FUNC 00005434 sub_180005434 ---- */
// attributes: thunk
__int64 sub_180005434()
{
  return qword_1800194F8();
}

/* ---- FUNC 00005444 sub_180005444 ---- */
// attributes: thunk
__int64 sub_180005444()
{
  return qword_180019508();
}

/* ---- FUNC 00005454 sub_180005454 ---- */
// attributes: thunk
__int64 sub_180005454()
{
  return qword_180019518();
}

/* ---- FUNC 00005464 sub_180005464 ---- */
// attributes: thunk
__int64 sub_180005464()
{
  return qword_180019528();
}

/* ---- FUNC 00005474 sub_180005474 ---- */
// attributes: thunk
__int64 sub_180005474()
{
  return qword_180019538();
}

/* ---- FUNC 00005484 sub_180005484 ---- */
// attributes: thunk
__int64 sub_180005484()
{
  return qword_180019548();
}

/* ---- FUNC 00005494 sub_180005494 ---- */
// attributes: thunk
__int64 sub_180005494()
{
  return qword_180019558();
}

/* ---- FUNC 000054A4 sub_1800054A4 ---- */
// attributes: thunk
__int64 sub_1800054A4()
{
  return qword_180019568();
}

/* ---- FUNC 000054B4 sub_1800054B4 ---- */
// attributes: thunk
__int64 sub_1800054B4()
{
  return qword_180019578();
}

/* ---- FUNC 000054C4 sub_1800054C4 ---- */
// attributes: thunk
__int64 sub_1800054C4()
{
  return qword_180019588();
}

/* ---- FUNC 000054D4 sub_1800054D4 ---- */
// attributes: thunk
__int64 sub_1800054D4()
{
  return qword_180019598();
}

/* ---- FUNC 000054E4 sub_1800054E4 ---- */
// attributes: thunk
__int64 sub_1800054E4()
{
  return qword_1800195A8();
}

/* ---- FUNC 000054F4 sub_1800054F4 ---- */
// attributes: thunk
__int64 sub_1800054F4()
{
  return qword_1800195B8();
}

/* ---- FUNC 00005500 sub_180005500 ---- */
// attributes: thunk
__int64 sub_180005500()
{
  return qword_1800195C8();
}

/* ---- FUNC 00005510 sub_180005510 ---- */
// attributes: thunk
__int64 sub_180005510()
{
  return qword_1800195D0();
}

/* ---- FUNC 00005520 sub_180005520 ---- */
// attributes: thunk
__int64 sub_180005520()
{
  return qword_1800195D8();
}

/* ---- FUNC 00005530 sub_180005530 ---- */
// attributes: thunk
__int64 sub_180005530()
{
  return qword_1800195E0();
}

/* ---- FUNC 00005540 sub_180005540 ---- */
// attributes: thunk
__int64 sub_180005540()
{
  return qword_1800195E8();
}

/* ---- FUNC 00005550 sub_180005550 ---- */
// attributes: thunk
__int64 sub_180005550()
{
  return qword_1800195F0();
}

/* ---- FUNC 00005560 sub_180005560 ---- */
// attributes: thunk
__int64 sub_180005560()
{
  return qword_1800195F8();
}

/* ---- FUNC 00005574 sub_180005574 ---- */
// attributes: thunk
__int64 sub_180005574()
{
  return qword_180019600();
}

/* ---- FUNC 00005584 sub_180005584 ---- */
// attributes: thunk
__int64 sub_180005584()
{
  return qword_180019610();
}

/* ---- FUNC 00005594 sub_180005594 ---- */
// attributes: thunk
__int64 sub_180005594()
{
  return qword_180019620();
}

/* ---- FUNC 000055A4 sub_1800055A4 ---- */
// attributes: thunk
__int64 sub_1800055A4()
{
  return qword_180019630();
}

/* ---- FUNC 000055B4 sub_1800055B4 ---- */
// attributes: thunk
__int64 sub_1800055B4()
{
  return qword_180019640();
}

/* ---- FUNC 000055C4 sub_1800055C4 ---- */
// attributes: thunk
__int64 sub_1800055C4()
{
  return qword_180019650();
}

/* ---- FUNC 000055D4 sub_1800055D4 ---- */
// attributes: thunk
__int64 sub_1800055D4()
{
  return qword_180019660();
}

/* ---- FUNC 000055E4 sub_1800055E4 ---- */
// attributes: thunk
__int64 sub_1800055E4()
{
  return qword_180019670();
}

/* ---- FUNC 000055F4 sub_1800055F4 ---- */
// attributes: thunk
__int64 sub_1800055F4()
{
  return qword_180019680();
}

/* ---- FUNC 00005604 sub_180005604 ---- */
// attributes: thunk
__int64 sub_180005604()
{
  return qword_180019690();
}

/* ---- FUNC 00005614 sub_180005614 ---- */
// attributes: thunk
__int64 sub_180005614()
{
  return qword_1800196A0();
}

/* ---- FUNC 00005624 sub_180005624 ---- */
// attributes: thunk
__int64 sub_180005624()
{
  return qword_1800196B0();
}

/* ---- FUNC 00005634 sub_180005634 ---- */
// attributes: thunk
__int64 sub_180005634()
{
  return qword_1800196C0();
}

/* ---- FUNC 00005644 sub_180005644 ---- */
// attributes: thunk
__int64 sub_180005644()
{
  return qword_1800196D0();
}

/* ---- FUNC 00005654 sub_180005654 ---- */
// attributes: thunk
__int64 sub_180005654()
{
  return qword_1800196E0();
}

/* ---- FUNC 00005664 sub_180005664 ---- */
// attributes: thunk
__int64 sub_180005664()
{
  return qword_1800196F0();
}

/* ---- FUNC 00005674 sub_180005674 ---- */
// attributes: thunk
__int64 sub_180005674()
{
  return qword_180019700();
}

/* ---- FUNC 00005684 sub_180005684 ---- */
// attributes: thunk
__int64 sub_180005684()
{
  return qword_180019710();
}

/* ---- FUNC 00005694 sub_180005694 ---- */
// attributes: thunk
__int64 sub_180005694()
{
  return qword_180019720();
}

/* ---- FUNC 000056A4 sub_1800056A4 ---- */
// attributes: thunk
__int64 sub_1800056A4()
{
  return qword_180019730();
}

/* ---- FUNC 000056B4 sub_1800056B4 ---- */
// attributes: thunk
__int64 sub_1800056B4()
{
  return qword_180019740();
}

/* ---- FUNC 000056C4 sub_1800056C4 ---- */
// attributes: thunk
__int64 sub_1800056C4()
{
  return qword_180019750();
}

/* ---- FUNC 000056D4 sub_1800056D4 ---- */
// attributes: thunk
__int64 sub_1800056D4()
{
  return qword_180019760();
}

/* ---- FUNC 000056E4 sub_1800056E4 ---- */
// attributes: thunk
__int64 sub_1800056E4()
{
  return qword_180019770();
}

/* ---- FUNC 000056F4 sub_1800056F4 ---- */
// attributes: thunk
__int64 sub_1800056F4()
{
  return qword_180019780();
}

/* ---- FUNC 00005704 sub_180005704 ---- */
// attributes: thunk
__int64 sub_180005704()
{
  return qword_180019790();
}

/* ---- FUNC 00005714 sub_180005714 ---- */
// attributes: thunk
__int64 sub_180005714()
{
  return qword_1800197A0();
}

/* ---- FUNC 00005724 sub_180005724 ---- */
// attributes: thunk
__int64 sub_180005724()
{
  return qword_1800197B0();
}

/* ---- FUNC 00005734 sub_180005734 ---- */
// attributes: thunk
__int64 sub_180005734()
{
  return qword_1800197C0();
}

/* ---- FUNC 00005744 sub_180005744 ---- */
// attributes: thunk
__int64 sub_180005744()
{
  return qword_1800197D0();
}

/* ---- FUNC 00005754 sub_180005754 ---- */
// attributes: thunk
__int64 sub_180005754()
{
  return qword_1800197E0();
}

/* ---- FUNC 00005764 sub_180005764 ---- */
// attributes: thunk
__int64 sub_180005764()
{
  return qword_1800197F0();
}

/* ---- FUNC 00005774 sub_180005774 ---- */
// attributes: thunk
__int64 sub_180005774()
{
  return qword_180019800();
}

/* ---- FUNC 00005784 sub_180005784 ---- */
// attributes: thunk
__int64 sub_180005784()
{
  return qword_180019810();
}

/* ---- FUNC 00005794 sub_180005794 ---- */
// attributes: thunk
__int64 sub_180005794()
{
  return qword_180019820();
}
