/* NATIVE-340 reconstructed pseudo-C (editable; native view with CLI COM directory cleared, RVA unchanged) */

/* ---- FUNC 00001DD8 FUN_180001dd8 (43 bytes) ---- */

undefined8 * FUN_180001dd8(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = type_info::vftable;
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}

/* ---- FUNC 00001E1C FUN_180001e1c (60 bytes) ---- */

undefined8 * FUN_180001e1c(undefined8 *param_1,longlong param_2)

{
  *param_1 = std::exception::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  __std_exception_copy(param_2 + 8);
  *param_1 = std::bad_alloc::vftable;
  return param_1;
}

/* ---- FUNC 00001E58 FUN_180001e58 (30 bytes) ---- */

undefined8 * FUN_180001e58(undefined8 *param_1)

{
  param_1[2] = 0;
  param_1[1] = "bad allocation";
  *param_1 = std::bad_alloc::vftable;
  return param_1;
}

/* ---- FUNC 00001E78 FUN_180001e78 (60 bytes) ---- */

undefined8 * FUN_180001e78(undefined8 *param_1,longlong param_2)

{
  *param_1 = std::exception::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  __std_exception_copy(param_2 + 8);
  *param_1 = std::bad_array_new_length::vftable;
  return param_1;
}

/* ---- FUNC 00001EB4 FUN_180001eb4 (30 bytes) ---- */

undefined8 * FUN_180001eb4(undefined8 *param_1)

{
  param_1[2] = 0;
  param_1[1] = "bad array new length";
  *param_1 = std::bad_array_new_length::vftable;
  return param_1;
}

/* ---- FUNC 00001ED4 exception (50 bytes) ---- */

/* Library Function - Single Match
    public: __cdecl std::exception::exception(class std::exception const & __ptr64) __ptr64
   
   Library: Visual Studio 2019 Release */

exception * __thiscall std::exception::exception(exception *this,exception *param_1)

{
  *(undefined ***)this = vftable;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  __std_exception_copy(param_1 + 8);
  return this;
}

/* ---- FUNC 00001F5C FUN_180001f5c (66 bytes) ---- */

undefined8 * FUN_180001f5c(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = std::exception::vftable;
  __std_exception_destroy(param_1 + 1);
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}

/* ---- FUNC 00001FA0 FUN_180001fa0 (66 bytes) ---- */

undefined8 * FUN_180001fa0(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = std::exception::vftable;
  __std_exception_destroy(param_1 + 1);
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}

/* ---- FUNC 00001FE4 FUN_180001fe4 (66 bytes) ---- */

undefined8 * FUN_180001fe4(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = std::exception::vftable;
  __std_exception_destroy(param_1 + 1);
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}

/* ---- FUNC 00002028 FUN_180002028 (31 bytes) ---- */

void FUN_180002028(void)

{
  undefined8 local_28 [5];
  
  FUN_180001e58(local_28);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_28,(ThrowInfo *)&DAT_180017858);
}

/* ---- FUNC 00002048 FUN_180002048 (31 bytes) ---- */

void FUN_180002048(void)

{
  undefined8 local_28 [5];
  
  FUN_180001eb4(local_28);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_28,(ThrowInfo *)&DAT_1800178e0);
}

/* ---- FUNC 00002068 FUN_180002068 (18 bytes) ---- */

char * FUN_180002068(longlong param_1)

{
  char *pcVar1;
  
  pcVar1 = "Unknown exception";
  if (*(longlong *)(param_1 + 8) != 0) {
    pcVar1 = *(char **)(param_1 + 8);
  }
  return pcVar1;
}

/* ---- FUNC 0000207C FUN_18000207c (80 bytes) ---- */

ulonglong FUN_18000207c(undefined8 param_1,int param_2,longlong param_3)

{
  byte bVar1;
  ulonglong uVar2;
  undefined7 extraout_var;
  
  if (param_2 == 0) {
    bVar1 = FUN_1800021e4(CONCAT71((int7)((ulonglong)param_1 >> 8),param_3 != 0));
    return CONCAT71(extraout_var,bVar1);
  }
  if (param_2 != 1) {
    if (param_2 == 2) {
      bVar1 = FUN_1800026b8();
    }
    else {
      if (param_2 != 3) {
        return 1;
      }
      bVar1 = FUN_1800026e0();
    }
    return (ulonglong)bVar1;
  }
  uVar2 = FUN_1800020cc(param_1,param_3);
  return uVar2;
}

/* ---- FUNC 000020CC FUN_1800020cc (276 bytes) ---- */

undefined8 FUN_1800020cc(undefined8 param_1,undefined8 param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  longlong *plVar6;
  ulonglong uVar7;
  
  uVar4 = __scrt_initialize_crt(0);
  if ((char)uVar4 != '\0') {
    uVar4 = __scrt_acquire_startup_lock();
    bVar1 = true;
    if (DAT_180019990 != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_1800029e0(7);
    }
    DAT_180019990 = 1;
    bVar2 = FUN_1800026a0();
    if (bVar2) {
      FUN_180002c38();
      FUN_180002544();
      FUN_180002570();
      iVar3 = _initterm_e(&DAT_1800061f0,&DAT_1800061f8);
      if ((iVar3 == 0) && (uVar5 = __scrt_dllmain_after_initialize_c(), (char)uVar5 != '\0')) {
        _initterm(&DAT_1800061e0,&DAT_1800061e8);
        DAT_180019990 = 2;
        bVar1 = false;
      }
    }
    __scrt_release_startup_lock((char)uVar4);
    if (!bVar1) {
      plVar6 = (longlong *)FUN_1800029d0();
      if ((*plVar6 != 0) && (uVar7 = FUN_180002874((longlong)plVar6), (char)uVar7 != '\0')) {
        (*(code *)PTR__guard_dispatch_icall_1800061b8)(param_1,2,param_2);
      }
      DAT_180019964 = DAT_180019964 + 1;
      return 1;
    }
  }
  return 0;
}

/* ---- FUNC 000021E4 FUN_1800021e4 (129 bytes) ---- */

byte FUN_1800021e4(undefined8 param_1)

{
  undefined1 uVar1;
  char cVar2;
  undefined8 uVar3;
  undefined7 uVar4;
  byte bVar5;
  
  uVar1 = (undefined1)param_1;
  if (DAT_180019964 < 1) {
    bVar5 = 0;
  }
  else {
    DAT_180019964 = DAT_180019964 + -1;
    uVar3 = __scrt_acquire_startup_lock();
    if (DAT_180019990 != 2) {
                    /* WARNING: Subroutine does not return */
      FUN_1800029e0(7);
    }
    __scrt_dllmain_uninitialize_c();
    FUN_180002554();
    FUN_180002c74();
    DAT_180019990 = 0;
    uVar4 = (undefined7)((ulonglong)param_1 >> 8);
    __scrt_release_startup_lock((char)uVar3);
    cVar2 = __scrt_uninitialize_crt(CONCAT71(uVar4,uVar1),'\0');
    bVar5 = -(cVar2 != '\0') & 1;
    FUN_180002788();
  }
  return bVar5;
}

/* ---- FUNC 00002268 dllmain_dispatch (305 bytes) ---- */

/* Library Function - Single Match
    int __cdecl dllmain_dispatch(struct HINSTANCE__ * __ptr64 const,unsigned long,void * __ptr64
   const)
   
   Library: Visual Studio 2019 Release */

int __cdecl dllmain_dispatch(HINSTANCE__ *param_1,ulong param_2,void *param_3)

{
  ulonglong uVar1;
  undefined8 uVar2;
  HINSTANCE__ *pHVar3;
  int iVar4;
  
  if ((param_2 == 0) && (DAT_180019964 < 1)) {
    iVar4 = 0;
  }
  else {
    if (param_2 - 1 < 2) {
      if ((DAT_180006308 != 0) &&
         (iVar4 = (*(code *)PTR__guard_dispatch_icall_1800061b8)(), iVar4 == 0)) {
        return 0;
      }
      uVar1 = FUN_18000207c(param_1,param_2,(longlong)param_3);
      if ((int)uVar1 == 0) {
        return 0;
      }
    }
    uVar2 = DllMain(param_1,param_2);
    iVar4 = (int)uVar2;
    if ((param_2 == 1) && (iVar4 == 0)) {
      pHVar3 = param_1;
      DllMain(param_1,0);
      FUN_1800021e4(CONCAT71((int7)((ulonglong)pHVar3 >> 8),param_3 != (void *)0x0));
      if (DAT_180006308 != 0) {
        (*(code *)PTR__guard_dispatch_icall_1800061b8)(param_1,0,param_3);
      }
    }
    if ((param_2 == 0) || (param_2 == 3)) {
      uVar1 = FUN_18000207c(param_1,param_2,(longlong)param_3);
      iVar4 = 0;
      if ((int)uVar1 != 0) {
        if (DAT_180006308 == 0) {
          iVar4 = 1;
        }
        else {
          iVar4 = (*(code *)PTR__guard_dispatch_icall_1800061b8)(param_1,param_2,param_3);
        }
      }
    }
  }
  return iVar4;
}

/* ---- FUNC 000023C0 _DllMainCRTStartup (61 bytes) ---- */

/* Library Function - Single Match
    _DllMainCRTStartup
   
   Library: Visual Studio 2019 Release */

void _DllMainCRTStartup(HINSTANCE__ *param_1,ulong param_2,void *param_3)

{
  if (param_2 == 1) {
    __security_init_cookie();
  }
  dllmain_dispatch(param_1,param_2,param_3);
  return;
}

/* ---- FUNC 00002400 free (5 bytes) ---- */

void __cdecl free(void *_Memory)

{
                    /* WARNING: Could not recover jumptable at 0x0001800047e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  free(_Memory);
  return;
}

/* ---- FUNC 00002408 FUN_180002408 (107 bytes) ---- */

ulonglong FUN_180002408(void)

{
  DWORD DVar1;
  _FILETIME local_res8;
  _FILETIME local_res10;
  LARGE_INTEGER local_res18 [2];
  
  local_res10.dwLowDateTime = 0;
  local_res10.dwHighDateTime = 0;
  GetSystemTimeAsFileTime(&local_res10);
  local_res8 = local_res10;
  DVar1 = GetCurrentThreadId();
  local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1);
  DVar1 = GetCurrentProcessId();
  local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1);
  QueryPerformanceCounter(local_res18);
  return ((ulonglong)(uint)local_res18[0]._0_4_ << 0x20 ^
          CONCAT44(local_res18[0].s.HighPart,local_res18[0].s.LowPart) ^ (ulonglong)local_res8 ^
         (ulonglong)&local_res8) & 0xffffffffffff;
}

/* ---- FUNC 00002474 __security_init_cookie (172 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __security_init_cookie
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl __security_init_cookie(void)

{
  DWORD DVar1;
  _FILETIME local_res8;
  LARGE_INTEGER local_res10;
  _FILETIME local_18 [2];
  
  if (DAT_180019360 == 0x2b992ddfa232) {
    local_res8.dwLowDateTime = 0;
    local_res8.dwHighDateTime = 0;
    GetSystemTimeAsFileTime(&local_res8);
    local_18[0] = local_res8;
    DVar1 = GetCurrentThreadId();
    local_18[0] = (_FILETIME)((ulonglong)local_18[0] ^ (ulonglong)DVar1);
    DVar1 = GetCurrentProcessId();
    local_18[0] = (_FILETIME)((ulonglong)local_18[0] ^ (ulonglong)DVar1);
    QueryPerformanceCounter(&local_res10);
    DAT_180019360 =
         ((ulonglong)local_res10.s.LowPart << 0x20 ^
          CONCAT44(local_res10.s.HighPart,local_res10.s.LowPart) ^ (ulonglong)local_18[0] ^
         (ulonglong)local_18) & 0xffffffffffff;
    if (DAT_180019360 == 0x2b992ddfa232) {
      DAT_180019360 = 0x2b992ddfa233;
    }
  }
  _DAT_180019358 = ~DAT_180019360;
  return;
}

/* ---- FUNC 00002520 DllMain (35 bytes) ---- */

/* Library Function - Single Match
    DllMain
   
   Library: Visual Studio 2019 Release */

undefined8 DllMain(HMODULE param_1,int param_2)

{
  if ((param_2 == 1) && (DAT_180006308 == 0)) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}

/* ---- FUNC 00002544 FUN_180002544 (14 bytes) ---- */

void FUN_180002544(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000254b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InitializeSListHead(&DAT_180019970);
  return;
}

/* ---- FUNC 00002554 FUN_180002554 (12 bytes) ---- */

void FUN_180002554(void)

{
  __std_type_info_destroy_list(&DAT_180019970);
  return;
}

/* ---- FUNC 00002560 FUN_180002560 (8 bytes) ---- */

undefined * FUN_180002560(void)

{
  return &DAT_180019980;
}

/* ---- FUNC 00002568 FUN_180002568 (8 bytes) ---- */

undefined * FUN_180002568(void)

{
  return &DAT_180019988;
}

/* ---- FUNC 00002570 FUN_180002570 (27 bytes) ---- */

void FUN_180002570(void)

{
  ulonglong *puVar1;
  
  puVar1 = (ulonglong *)FUN_180002560();
  *puVar1 = *puVar1 | 0x24;
  puVar1 = (ulonglong *)FUN_180002568();
  *puVar1 = *puVar1 | 2;
  return;
}

/* ---- FUNC 0000258C FUN_18000258c (20 bytes) ---- */

void FUN_18000258c(void)

{
  ulonglong uVar1;
  
  uVar1 = FUN_1800030e0();
  _configure_narrow_argv(uVar1 & 0xffffffff);
  return;
}

/* ---- FUNC 00002630 __scrt_acquire_startup_lock (57 bytes) ---- */

/* Library Function - Single Match
    __scrt_acquire_startup_lock
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

ulonglong __scrt_acquire_startup_lock(void)

{
  ulonglong uVar1;
  bool bVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  
  bVar2 = __scrt_is_ucrt_dll_in_use();
  uVar3 = CONCAT71(extraout_var,bVar2);
  if ((int)uVar3 == 0) {
LAB_18000265e:
    uVar3 = uVar3 & 0xffffffffffffff00;
  }
  else {
    do {
      uVar3 = 0;
      LOCK();
      bVar2 = DAT_180019998 == 0;
      uVar1 = *(ulonglong *)((longlong)Self + 8);
      if (!bVar2) {
        uVar3 = DAT_180019998;
        uVar1 = DAT_180019998;
      }
      DAT_180019998 = uVar1;
      UNLOCK();
      if (bVar2) goto LAB_18000265e;
    } while (*(ulonglong *)((longlong)Self + 8) != uVar3);
    uVar3 = CONCAT71((int7)(uVar3 >> 8),1);
  }
  return uVar3;
}

/* ---- FUNC 0000266C __scrt_dllmain_after_initialize_c (52 bytes) ---- */

/* Library Function - Single Match
    __scrt_dllmain_after_initialize_c
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined8 __scrt_dllmain_after_initialize_c(void)

{
  bool bVar1;
  undefined7 extraout_var;
  undefined8 uVar2;
  ulonglong uVar3;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if ((int)CONCAT71(extraout_var,bVar1) == 0) {
    uVar3 = FUN_1800030e0();
    uVar3 = _configure_narrow_argv(uVar3 & 0xffffffff);
    if ((int)uVar3 != 0) {
      return uVar3 & 0xffffffffffffff00;
    }
    uVar2 = _initialize_narrow_environment();
  }
  else {
    uVar2 = FUN_180002f34();
  }
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}

/* ---- FUNC 000026A0 FUN_1800026a0 (21 bytes) ---- */

bool FUN_1800026a0(void)

{
  undefined8 uVar1;
  
  uVar1 = FUN_1800027e8(0);
  return (char)uVar1 != '\0';
}

/* ---- FUNC 000026B8 FUN_1800026b8 (40 bytes) ---- */

undefined1 FUN_1800026b8(void)

{
  char cVar1;
  
  cVar1 = FUN_1800047f0();
  if (cVar1 != '\0') {
    cVar1 = FUN_1800047f0();
    if (cVar1 != '\0') {
      return 1;
    }
    FUN_1800047f4();
  }
  return 0;
}

/* ---- FUNC 000026E0 FUN_1800026e0 (21 bytes) ---- */

undefined1 FUN_1800026e0(void)

{
  FUN_1800047f4();
  FUN_1800047f4();
  return 1;
}

/* ---- FUNC 000026F8 __scrt_dllmain_exception_filter (96 bytes) ---- */

/* Library Function - Single Match
    __scrt_dllmain_exception_filter
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __scrt_dllmain_exception_filter
               (undefined8 param_1,int param_2,undefined8 param_3,undefined *param_4,
               undefined4 param_5,undefined8 param_6)

{
  bool bVar1;
  undefined7 extraout_var;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if (((int)CONCAT71(extraout_var,bVar1) == 0) && (param_2 == 1)) {
    (*(code *)PTR__guard_dispatch_icall_1800061b8)(param_1,0,param_3);
  }
  _seh_filter_dll(param_5,param_6);
  return;
}

/* ---- FUNC 00002758 __scrt_dllmain_uninitialize_c (48 bytes) ---- */

/* Library Function - Single Match
    __scrt_dllmain_uninitialize_c
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __scrt_dllmain_uninitialize_c(void)

{
  bool bVar1;
  undefined7 extraout_var;
  undefined8 uVar2;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if ((int)CONCAT71(extraout_var,bVar1) != 0) {
    _execute_onexit_table(&DAT_1800199a8);
    return;
  }
  uVar2 = FUN_180004800();
  if ((int)uVar2 == 0) {
    _cexit();
  }
  return;
}

/* ---- FUNC 00002788 FUN_180002788 (20 bytes) ---- */

void FUN_180002788(void)

{
  FUN_1800047fc();
  FUN_1800047fc();
  return;
}

/* ---- FUNC 0000279C __scrt_initialize_crt (73 bytes) ---- */

/* Library Function - Single Match
    __scrt_initialize_crt
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

longlong __scrt_initialize_crt(int param_1)

{
  char cVar1;
  uint7 extraout_var;
  uint7 uVar2;
  undefined7 extraout_var_00;
  uint7 extraout_var_01;
  
  if (param_1 == 0) {
    DAT_1800199a0 = 1;
  }
  FUN_180002f34();
  cVar1 = FUN_1800047ec();
  uVar2 = extraout_var;
  if (cVar1 != '\0') {
    cVar1 = FUN_1800047ec();
    if (cVar1 != '\0') {
      return CONCAT71(extraout_var_00,1);
    }
    FUN_1800047f8();
    uVar2 = extraout_var_01;
  }
  return (ulonglong)uVar2 << 8;
}

/* ---- FUNC 000027E8 FUN_1800027e8 (138 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1800027e8(uint param_1)

{
  bool bVar1;
  ulonglong in_RAX;
  undefined7 extraout_var;
  
  if (DAT_1800199a1 == '\0') {
    if (1 < param_1) {
                    /* WARNING: Subroutine does not return */
      FUN_1800029e0(5);
    }
    bVar1 = __scrt_is_ucrt_dll_in_use();
    if (((int)CONCAT71(extraout_var,bVar1) == 0) || (param_1 != 0)) {
      in_RAX = 0xffffffffffffffff;
      DAT_1800199a8 = _DAT_180006310;
      uRam00000001800199b0 = _UNK_180006318;
      _DAT_1800199b8 = 0xffffffffffffffff;
      _DAT_1800199c0 = _DAT_180006310;
      uRam00000001800199c8 = _UNK_180006318;
      _DAT_1800199d0 = 0xffffffffffffffff;
    }
    else {
      in_RAX = _initialize_onexit_table(&DAT_1800199a8);
      if (((int)in_RAX != 0) ||
         (in_RAX = _initialize_onexit_table(&DAT_1800199c0), (int)in_RAX != 0)) {
        return in_RAX & 0xffffffffffffff00;
      }
    }
    DAT_1800199a1 = '\x01';
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}

/* ---- FUNC 00002874 FUN_180002874 (152 bytes) ---- */

ulonglong FUN_180002874(longlong param_1)

{
  ulonglong uVar1;
  uint7 uVar2;
  longlong lVar3;
  longlong lVar4;
  
  uVar1 = 0x5a4d;
  if (IMAGE_DOS_HEADER_180000000.e_magic == (char  [2])0x5a4d) {
    lVar3 = (longlong)(int)IMAGE_DOS_HEADER_180000000.e_lfanew;
    if ((*(int *)(lVar3 + 0x180000000) == 0x4550) &&
       (uVar1 = 0x20b,
       *(short *)((longlong)IMAGE_DOS_HEADER_180000000.e_res_4_ + lVar3 + -4) == 0x20b)) {
      lVar4 = (ulonglong)*(ushort *)((longlong)IMAGE_DOS_HEADER_180000000.e_res_4_ + lVar3 + -8) +
              0x18 + lVar3 + 0x180000000;
      uVar1 = (ulonglong)*(ushort *)(IMAGE_DOS_HEADER_180000000.e_magic + lVar3 + 6);
      lVar3 = lVar4 + uVar1 * 0x28;
      for (; lVar4 != lVar3; lVar4 = lVar4 + 0x28) {
        if (((ulonglong)*(uint *)(lVar4 + 0xc) <= param_1 - 0x180000000U) &&
           (uVar1 = (ulonglong)(*(int *)(lVar4 + 8) + *(uint *)(lVar4 + 0xc)),
           param_1 - 0x180000000U < uVar1)) goto LAB_1800028ea;
      }
      lVar4 = 0;
LAB_1800028ea:
      if (lVar4 == 0) {
        return uVar1 & 0xffffffffffffff00;
      }
      uVar2 = (uint7)(uVar1 >> 8);
      if (*(int *)(lVar4 + 0x24) < 0) {
        return (ulonglong)uVar2 << 8;
      }
      return CONCAT71(uVar2,1);
    }
  }
  return uVar1 & 0xffffffffffffff00;
}

/* ---- FUNC 0000290C __scrt_release_startup_lock (36 bytes) ---- */

/* Library Function - Single Match
    __scrt_release_startup_lock
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __scrt_release_startup_lock(char param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if ((CONCAT31(extraout_var,bVar1) != 0) && (param_1 == '\0')) {
    LOCK();
    DAT_180019998 = 0;
    UNLOCK();
  }
  return;
}

/* ---- FUNC 00002930 __scrt_uninitialize_crt (41 bytes) ---- */

/* Library Function - Single Match
    __scrt_uninitialize_crt
   
   Library: Visual Studio 2019 Release */

undefined1 __scrt_uninitialize_crt(undefined8 param_1,char param_2)

{
  if ((DAT_1800199a0 == '\0') || (param_2 == '\0')) {
    FUN_1800047f8();
    FUN_1800047f8();
  }
  return 1;
}

/* ---- FUNC 0000295C _onexit (58 bytes) ---- */

/* Library Function - Single Match
    _onexit
   
   Library: Visual Studio 2019 Release */

_onexit_t __cdecl _onexit(_onexit_t _Func)

{
  int iVar1;
  _onexit_t p_Var2;
  
  if (DAT_1800199a8 == -1) {
    iVar1 = _crt_atexit();
  }
  else {
    iVar1 = _register_onexit_function(&DAT_1800199a8);
  }
  p_Var2 = (_onexit_t)0x0;
  if (iVar1 == 0) {
    p_Var2 = _Func;
  }
  return p_Var2;
}

/* ---- FUNC 000029B8 atexit (23 bytes) ---- */

/* Library Function - Single Match
    atexit
   
   Library: Visual Studio 2019 Release */

int __cdecl atexit(_func_5014 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = _onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}

/* ---- FUNC 000029D0 FUN_1800029d0 (8 bytes) ---- */

undefined * FUN_1800029d0(void)

{
  return &DAT_180019b78;
}

/* ---- FUNC 000029D8 FUN_1800029d8 (8 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1800029d8(void)

{
  _DAT_1800199d8 = 0;
  return;
}

/* ---- FUNC 000029E0 FUN_1800029e0 (331 bytes) ---- */

void FUN_1800029e0(undefined4 param_1)

{
  code *pcVar1;
  BOOL BVar2;
  LONG LVar3;
  PRUNTIME_FUNCTION FunctionEntry;
  undefined1 *puVar4;
  undefined8 unaff_retaddr;
  DWORD64 local_res10;
  undefined1 local_res18 [8];
  undefined1 local_res20 [8];
  undefined1 auStack_5c8 [8];
  undefined1 auStack_5c0 [232];
  undefined1 local_4d8 [152];
  undefined1 *local_440;
  DWORD64 local_3e0;
  
  puVar4 = auStack_5c8;
  BVar2 = IsProcessorFeaturePresent(0x17);
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(param_1);
    puVar4 = auStack_5c0;
  }
  *(undefined8 *)(puVar4 + -8) = 0x180002a14;
  FUN_1800029d8();
  *(undefined8 *)(puVar4 + -8) = 0x180002a25;
  memset(local_4d8,0,0x4d0);
  *(undefined8 *)(puVar4 + -8) = 0x180002a2f;
  RtlCaptureContext(local_4d8);
  *(undefined8 *)(puVar4 + -8) = 0x180002a49;
  FunctionEntry = RtlLookupFunctionEntry(local_3e0,&local_res10,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry != (PRUNTIME_FUNCTION)0x0) {
    *(undefined8 *)(puVar4 + 0x38) = 0;
    *(undefined1 **)(puVar4 + 0x30) = local_res18;
    *(undefined1 **)(puVar4 + 0x28) = local_res20;
    *(undefined1 **)(puVar4 + 0x20) = local_4d8;
    *(undefined8 *)(puVar4 + -8) = 0x180002a8a;
    RtlVirtualUnwind(0,local_res10,local_3e0,FunctionEntry,*(PCONTEXT *)(puVar4 + 0x20),
                     *(PVOID **)(puVar4 + 0x28),*(PDWORD64 *)(puVar4 + 0x30),
                     *(PKNONVOLATILE_CONTEXT_POINTERS *)(puVar4 + 0x38));
  }
  local_440 = &stack0x00000008;
  *(undefined8 *)(puVar4 + -8) = 0x180002abc;
  memset(puVar4 + 0x50,0,0x98);
  *(undefined8 *)(puVar4 + 0x60) = unaff_retaddr;
  *(undefined4 *)(puVar4 + 0x50) = 0x40000015;
  *(undefined4 *)(puVar4 + 0x54) = 1;
  *(undefined8 *)(puVar4 + -8) = 0x180002ade;
  BVar2 = IsDebuggerPresent();
  *(undefined1 **)(puVar4 + 0x40) = puVar4 + 0x50;
  *(undefined1 **)(puVar4 + 0x48) = local_4d8;
  *(undefined8 *)(puVar4 + -8) = 0x180002aff;
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  *(undefined8 *)(puVar4 + -8) = 0x180002b0a;
  LVar3 = UnhandledExceptionFilter((_EXCEPTION_POINTERS *)(puVar4 + 0x40));
  if ((LVar3 == 0) && (BVar2 != 1)) {
    *(undefined8 *)(puVar4 + -8) = 0x180002b1a;
    FUN_1800029d8();
  }
  return;
}

/* ---- FUNC 00002B2C __scrt_get_show_window_mode (58 bytes) ---- */

/* Library Function - Single Match
    __scrt_get_show_window_mode
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

WORD __scrt_get_show_window_mode(void)

{
  WORD WVar1;
  _STARTUPINFOW local_78;
  
  memset(&local_78,0,0x68);
  GetStartupInfoW(&local_78);
  WVar1 = 10;
  if (((byte)local_78.dwFlags & 1) != 0) {
    WVar1 = local_78.wShowWindow;
  }
  return WVar1;
}

/* ---- FUNC 00002B74 FUN_180002b74 (81 bytes) ---- */

ulonglong FUN_180002b74(void)

{
  HMODULE pHVar1;
  ulonglong uVar2;
  int *piVar3;
  
  pHVar1 = GetModuleHandleW((LPCWSTR)0x0);
  if ((((pHVar1 == (HMODULE)0x0) || ((short)pHVar1->unused != 0x5a4d)) ||
      (piVar3 = (int *)((longlong)&pHVar1->unused + (longlong)pHVar1[0xf].unused), *piVar3 != 0x4550
      )) || ((pHVar1 = (HMODULE)0x20b, (short)piVar3[6] != 0x20b || ((uint)piVar3[0x21] < 0xf)))) {
    uVar2 = (ulonglong)pHVar1 & 0xffffffffffffff00;
  }
  else {
    uVar2 = CONCAT71(2,piVar3[0x3e] != 0);
  }
  return uVar2;
}

/* ---- FUNC 00002BDC FUN_180002bdc (90 bytes) ---- */

undefined8 FUN_180002bdc(undefined8 *param_1)

{
  int *piVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  piVar1 = (int *)*param_1;
  if ((*piVar1 == -0x1f928c9d) && (piVar1[6] == 4)) {
    if ((piVar1[8] + 0xe66cfae0U < 3) || (piVar1[8] == 0x1994000)) {
      puVar3 = (undefined8 *)__current_exception();
      *puVar3 = piVar1;
      uVar2 = param_1[1];
      puVar3 = (undefined8 *)__current_exception_context();
      *puVar3 = uVar2;
                    /* WARNING: Subroutine does not return */
      terminate();
    }
  }
  return 0;
}

/* ---- FUNC 00002C38 FUN_180002c38 (60 bytes) ---- */

void FUN_180002c38(void)

{
  longlong *plVar1;
  
  for (plVar1 = &DAT_180017590; plVar1 < &DAT_180017590; plVar1 = plVar1 + 1) {
    if (*plVar1 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800061b8)();
    }
  }
  return;
}

/* ---- FUNC 00002C74 FUN_180002c74 (60 bytes) ---- */

void FUN_180002c74(void)

{
  longlong *plVar1;
  
  for (plVar1 = &DAT_1800175a0; plVar1 < &DAT_1800175a0; plVar1 = plVar1 + 1) {
    if (*plVar1 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800061b8)();
    }
  }
  return;
}

/* ---- FUNC 00002CB0 _guard_check_icall (3 bytes) ---- */

void _guard_check_icall(void)

{
  return;
}

/* ---- FUNC 00002D00 FUN_180002d00 (58 bytes) ---- */

void FUN_180002d00(undefined *param_1)

{
  if ((param_1 == &DAT_180016580) && (DAT_1800061d0 != (code *)0x0)) {
    (*DAT_1800061d0)();
  }
  return;
}

/* ---- FUNC 00002D3C FUN_180002d3c (30 bytes) ---- */

void FUN_180002d3c(void)

{
  if (DAT_1800061d0 != (code *)0x0) {
    (*DAT_1800061d0)();
  }
  return;
}

/* ---- FUNC 00002D5C FUN_180002d5c (55 bytes) ---- */

void FUN_180002d5c(undefined *param_1)

{
  if ((param_1 == &DAT_180016580) && (DAT_1800199e0 != 0)) {
    (*(code *)PTR__guard_dispatch_icall_1800061b8)();
  }
  return;
}

/* ---- FUNC 00002D94 FUN_180002d94 (27 bytes) ---- */

void FUN_180002d94(void)

{
  if (DAT_1800199e0 != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800061b8)();
  }
  return;
}

/* ---- FUNC 00002E50 FUN_180002e50 (83 bytes) ---- */

void FUN_180002e50(undefined *param_1,longlong param_2,undefined *param_3)

{
  if (((param_3 < param_1 + (-0x180016580 - param_2)) && (param_1 == &DAT_180016580)) &&
     (DAT_1800061d0 != (code *)0x0)) {
    (*DAT_1800061d0)();
  }
  return;
}

/* ---- FUNC 00002EA4 FUN_180002ea4 (80 bytes) ---- */

void FUN_180002ea4(undefined *param_1,longlong param_2,undefined *param_3)

{
  if (((param_3 < param_1 + (-0x180016580 - param_2)) && (param_1 == &DAT_180016580)) &&
     (DAT_1800199e0 != 0)) {
    (*(code *)PTR__guard_dispatch_icall_1800061b8)();
  }
  return;
}

/* ---- FUNC 00002F2C free (5 bytes) ---- */

void __cdecl free(void *_Memory)

{
                    /* WARNING: Could not recover jumptable at 0x0001800047e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  free(_Memory);
  return;
}

/* ---- FUNC 00002F34 FUN_180002f34 (428 bytes) ---- */

/* WARNING: Removing unreachable block (ram,0x000180002ffe) */
/* WARNING: Removing unreachable block (ram,0x000180002f6e) */
/* WARNING: Removing unreachable block (ram,0x000180002f47) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_180002f34(void)

{
  int *piVar1;
  uint *puVar2;
  longlong lVar3;
  uint uVar4;
  undefined8 uVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  byte in_XCR0;
  
  piVar1 = (int *)cpuid_basic_info(0);
  uVar8 = 0;
  puVar2 = (uint *)cpuid_Version_info(1);
  uVar4 = puVar2[3];
  if ((piVar1[2] == 0x49656e69 && piVar1[3] == 0x6c65746e) && piVar1[1] == 0x756e6547) {
    _DAT_180019378 = 0xffffffffffffffff;
    uVar7 = *puVar2 & 0xfff3ff0;
    _DAT_180019370 = 0x8000;
    if ((((uVar7 == 0x106c0) || (uVar7 == 0x20660)) || (uVar7 == 0x20670)) ||
       ((uVar7 - 0x30650 < 0x21 &&
        ((0x100010001U >> ((ulonglong)(uVar7 - 0x30650) & 0x3f) & 1) != 0)))) {
      DAT_1800199e8 = DAT_1800199e8 | 1;
    }
  }
  if (6 < *piVar1) {
    lVar3 = cpuid_Extended_Feature_Enumeration_info(7);
    uVar8 = *(uint *)(lVar3 + 4);
    if ((uVar8 >> 9 & 1) != 0) {
      DAT_1800199e8 = DAT_1800199e8 | 2;
    }
  }
  _DAT_180019368 = 1;
  DAT_18001936c = 2;
  if ((uVar4 >> 0x14 & 1) != 0) {
    _DAT_180019368 = 2;
    DAT_18001936c = 6;
    if (((uVar4 >> 0x1b & 1) != 0) && ((uVar4 >> 0x1c & 1) != 0)) {
      uVar5 = xinuse(0);
      bVar6 = in_XCR0 & (byte)uVar5;
      if ((bVar6 & 6) == 6) {
        DAT_18001936c = 0xe;
        _DAT_180019368 = 3;
        if ((uVar8 & 0x20) != 0) {
          _DAT_180019368 = 5;
          DAT_18001936c = 0x2e;
          if (((uVar8 & 0xd0030000) == 0xd0030000) && ((bVar6 & 0xe0) == 0xe0)) {
            DAT_18001936c = 0x6e;
            _DAT_180019368 = 6;
          }
        }
      }
    }
  }
  return 0;
}

/* ---- FUNC 000030E0 FUN_1800030e0 (6 bytes) ---- */

undefined8 FUN_1800030e0(void)

{
  return 1;
}

/* ---- FUNC 000030E8 __scrt_is_ucrt_dll_in_use (12 bytes) ---- */

/* Library Function - Single Match
    __scrt_is_ucrt_dll_in_use
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

bool __scrt_is_ucrt_dll_in_use(void)

{
  return DAT_180019830 != 0;
}

/* ---- FUNC 00003660 FUN_180003660 (14 bytes) ---- */

undefined8 FUN_180003660(void)
{ unsigned char *p = (unsigned char *)__readgsqword(0x30);  /* 65 48 8B 04 25 30 00 00 00: mov rax, gs:[0x30] */
  return *(undefined8 *)(p + 8);                              /* 48 8B 40 08: mov rax, [rax+8] (one indirect load) */
}
/* 0000366D C3: ret. 14 bytes: GS:[0x30] gives a pointer, +0x8 is dereferenced once;

/* ---- FUNC 0000476B __std_exception_copy (6 bytes) ---- */

void __std_exception_copy(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000476b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __std_exception_copy();
  return;
}

/* ---- FUNC 00004771 __std_exception_destroy (6 bytes) ---- */

void __std_exception_destroy(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180004771. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __std_exception_destroy();
  return;
}

/* ---- FUNC 00004777 _CxxThrowException (6 bytes) ---- */

void __stdcall _CxxThrowException(void *pExceptionObject,ThrowInfo *pThrowInfo)

{
                    /* WARNING: Could not recover jumptable at 0x000180004777. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  _CxxThrowException(pExceptionObject,pThrowInfo);
  return;
}

/* ---- FUNC 00004783 __std_type_info_destroy_list (6 bytes) ---- */

void __std_type_info_destroy_list(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180004783. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __std_type_info_destroy_list();
  return;
}

/* ---- FUNC 00004789 __current_exception (6 bytes) ---- */

void __current_exception(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180004789. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __current_exception();
  return;
}

/* ---- FUNC 0000478F __current_exception_context (6 bytes) ---- */

void __current_exception_context(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000478f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __current_exception_context();
  return;
}

/* ---- FUNC 00004795 memset (6 bytes) ---- */

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004795. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}

/* ---- FUNC 0000479B _initterm (6 bytes) ---- */

void _initterm(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000479b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm();
  return;
}

/* ---- FUNC 000047A1 _initterm_e (6 bytes) ---- */

void _initterm_e(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800047a1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm_e();
  return;
}

/* ---- FUNC 000047A7 _seh_filter_dll (6 bytes) ---- */

void _seh_filter_dll(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800047a7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _seh_filter_dll();
  return;
}

/* ---- FUNC 000047AD _configure_narrow_argv (6 bytes) ---- */

void _configure_narrow_argv(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800047ad. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _configure_narrow_argv();
  return;
}

/* ---- FUNC 000047B3 _initialize_narrow_environment (6 bytes) ---- */

void _initialize_narrow_environment(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800047b3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initialize_narrow_environment();
  return;
}

/* ---- FUNC 000047B9 _initialize_onexit_table (6 bytes) ---- */

void _initialize_onexit_table(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800047b9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initialize_onexit_table();
  return;
}

/* ---- FUNC 000047BF _register_onexit_function (6 bytes) ---- */

void _register_onexit_function(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800047bf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _register_onexit_function();
  return;
}

/* ---- FUNC 000047C5 _execute_onexit_table (6 bytes) ---- */

void _execute_onexit_table(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800047c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _execute_onexit_table();
  return;
}

/* ---- FUNC 000047CB _crt_atexit (6 bytes) ---- */

void _crt_atexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800047cb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _crt_atexit();
  return;
}

/* ---- FUNC 000047D7 _cexit (6 bytes) ---- */

void __cdecl _cexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800047d7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _cexit();
  return;
}

/* ---- FUNC 000047DD terminate (6 bytes) ---- */

void terminate(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800047dd. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  terminate();
  return;
}

/* ---- FUNC 000047E3 free (6 bytes) ---- */

void __cdecl free(void *_Memory)

{
                    /* WARNING: Could not recover jumptable at 0x0001800047e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  free(_Memory);
  return;
}

/* ---- FUNC 000047EC FUN_1800047ec (3 bytes) ---- */

undefined1 FUN_1800047ec(void)

{
  return 1;
}

/* ---- FUNC 000047F0 FUN_1800047f0 (3 bytes) ---- */

undefined1 FUN_1800047f0(void)

{
  return 1;
}

/* ---- FUNC 000047F4 FUN_1800047f4 (3 bytes) ---- */

undefined1 FUN_1800047f4(void)

{
  return 1;
}

/* ---- FUNC 000047F8 FUN_1800047f8 (3 bytes) ---- */

undefined1 FUN_1800047f8(void)

{
  return 1;
}

/* ---- FUNC 000047FC FUN_1800047fc (3 bytes) ---- */

undefined1 FUN_1800047fc(void)

{
  return 1;
}

/* ---- FUNC 00004800 FUN_180004800 (3 bytes) ---- */

undefined8 FUN_180004800(void)

{
  return 0;
}

/* ---- FUNC 00004804 free (5 bytes) ---- */

void __cdecl free(void *_Memory)

{
                    /* WARNING: Could not recover jumptable at 0x0001800047e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  free(_Memory);
  return;
}

/* ---- FUNC 0000480C thunk_FUN_18000481c (5 bytes) ---- */

void thunk_FUN_18000481c(size_t param_1)

{
  int iVar1;
  void *pvVar2;
  
  do {
    pvVar2 = malloc(param_1);
    if (pvVar2 != (void *)0x0) {
      return;
    }
    iVar1 = _callnewh(param_1);
  } while (iVar1 != 0);
  if (param_1 == 0xffffffffffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_180002048();
  }
                    /* WARNING: Subroutine does not return */
  FUN_180002028();
}

/* ---- FUNC 00004814 free (5 bytes) ---- */

void __cdecl free(void *_Memory)

{
                    /* WARNING: Could not recover jumptable at 0x0001800047e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  free(_Memory);
  return;
}

/* ---- FUNC 0000481C FUN_18000481c (59 bytes) ---- */

void FUN_18000481c(size_t param_1)

{
  int iVar1;
  void *pvVar2;
  
  do {
    pvVar2 = malloc(param_1);
    if (pvVar2 != (void *)0x0) {
      return;
    }
    iVar1 = _callnewh(param_1);
  } while (iVar1 != 0);
  if (param_1 == 0xffffffffffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_180002048();
  }
                    /* WARNING: Subroutine does not return */
  FUN_180002028();
}

/* ---- FUNC 00004858 __ExceptionPtrDestroy (6 bytes) ---- */

void __cdecl __ExceptionPtrDestroy(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180004858. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __ExceptionPtrDestroy(param_1);
  return;
}

/* ---- FUNC 0000485E __ExceptionPtrCopy (6 bytes) ---- */

void __cdecl __ExceptionPtrCopy(void *param_1,void *param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00018000485e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __ExceptionPtrCopy(param_1,param_2);
  return;
}

/* ---- FUNC 00004864 WideCharToMultiByte (6 bytes) ---- */

int __stdcall
WideCharToMultiByte(UINT CodePage,DWORD dwFlags,LPCWSTR lpWideCharStr,int cchWideChar,
                   LPSTR lpMultiByteStr,int cbMultiByte,LPCSTR lpDefaultChar,
                   LPBOOL lpUsedDefaultChar)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004864. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = WideCharToMultiByte(CodePage,dwFlags,lpWideCharStr,cchWideChar,lpMultiByteStr,cbMultiByte,
                              lpDefaultChar,lpUsedDefaultChar);
  return iVar1;
}

/* ---- FUNC 0000486A MultiByteToWideChar (6 bytes) ---- */

int __stdcall
MultiByteToWideChar(UINT CodePage,DWORD dwFlags,LPCSTR lpMultiByteStr,int cbMultiByte,
                   LPWSTR lpWideCharStr,int cchWideChar)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000486a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = MultiByteToWideChar(CodePage,dwFlags,lpMultiByteStr,cbMultiByte,lpWideCharStr,cchWideChar)
  ;
  return iVar1;
}

/* ---- FUNC 00004870 Sleep (6 bytes) ---- */

void __stdcall Sleep(DWORD dwMilliseconds)

{
                    /* WARNING: Could not recover jumptable at 0x000180004870. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Sleep(dwMilliseconds);
  return;
}

/* ---- FUNC 00004876 __FrameUnwindFilter (6 bytes) ---- */

void __FrameUnwindFilter(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180004876. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __FrameUnwindFilter();
  return;
}

/* ---- FUNC 0000487C abort (6 bytes) ---- */

void __cdecl abort(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000487c. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  abort();
  return;
}

/* ---- FUNC 00004882 _callnewh (6 bytes) ---- */

int __cdecl _callnewh(size_t _Size)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004882. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _callnewh(_Size);
  return iVar1;
}

/* ---- FUNC 00004888 malloc (6 bytes) ---- */

void * __cdecl malloc(size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004888. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = malloc(_Size);
  return pvVar1;
}

/* ---- FUNC 0000488E entry (6 bytes) ---- */

void entry(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000488e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _CorDllMain();
  return;
}

/* ---- FUNC 000048B0 _guard_dispatch_icall (2 bytes) ---- */

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001800048b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

/* ---- FUNC 000048D0 _guard_dispatch_icall (6 bytes) ---- */

/* WARNING: This is an inlined function */
/* WARNING: Switch with 1 destination removed at 0x0001800048d0 */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001800048b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

/* ---- FUNC 000048D6 FUN_1800048d6 (22 bytes) ---- */

void FUN_1800048d6(undefined8 param_1,longlong param_2)

{
  __scrt_release_startup_lock(*(char *)(param_2 + 0x40));
  return;
}

/* ---- FUNC 000048ED FUN_1800048ed (24 bytes) ---- */

void FUN_1800048ed(undefined8 param_1,longlong param_2)

{
  __scrt_release_startup_lock(*(char *)(param_2 + 0x20));
  return;
}

/* ---- FUNC 00004906 FUN_180004906 (19 bytes) ---- */

void FUN_180004906(void)

{
  FUN_180002788();
  return;
}

/* ---- FUNC 0000491A FUN_18000491a (53 bytes) ---- */

void FUN_18000491a(undefined8 *param_1,longlong param_2)

{
  __scrt_dllmain_exception_filter
            (*(undefined8 *)(param_2 + 0x60),*(int *)(param_2 + 0x68),
             *(undefined8 *)(param_2 + 0x70),FUN_18000207c,*(undefined4 *)*param_1,param_1);
  return;
}

/* ---- FUNC 00004950 FUN_180004950 (23 bytes) ---- */

bool FUN_180004950(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}

/* ---- FUNC 000050A0 SaveMergennFiles (2 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl SaveMergennFiles(char * __ptr64,char * __ptr64) */

void __cdecl SaveMergennFiles(char *param_1,char *param_2)

{
                    /* 0x50a0  1  ?SaveMergennFiles@@YAXPEAD0@Z */
                    /* WARNING: Could not recover jumptable at 0x0001800050aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_180019138)();
  return;
}

/* ---- FUNC 000050AA FUN_1800050aa (6 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1800050aa(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800050aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_180019138)();
  return;
}

/* ---- FUNC 000050C0 thunk_FUN_1800050ca (2 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_1800050ca(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800050ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_180019158)();
  return;
}

/* ---- FUNC 000050CA FUN_1800050ca (6 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1800050ca(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800050ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_180019158)();
  return;
}

/* ---- FUNC 00005110 thunk_FUN_18000511a (2 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_18000511a(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000511a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_1800191a8)();
  return;
}

/* ---- FUNC 0000511A FUN_18000511a (6 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_18000511a(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000511a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_1800191a8)();
  return;
}

/* ---- FUNC 00005120 thunk_FUN_18000512a (2 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_18000512a(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000512a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_1800191b8)();
  return;
}

/* ---- FUNC 0000512A FUN_18000512a (6 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_18000512a(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000512a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_1800191b8)();
  return;
}

/* ---- FUNC 00005130 thunk_FUN_18000513a (2 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_18000513a(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000513a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_1800191c8)();
  return;
}

/* ---- FUNC 0000513A FUN_18000513a (6 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_18000513a(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000513a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_1800191c8)();
  return;
}

/* ---- FUNC 00005140 thunk_FUN_18000514a (2 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_18000514a(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000514a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_1800191d8)();
  return;
}

/* ---- FUNC 0000514A FUN_18000514a (6 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_18000514a(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000514a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_1800191d8)();
  return;
}

/* ---- FUNC 00005150 thunk_FUN_18000515a (2 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_18000515a(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000515a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_1800191e8)();
  return;
}

/* ---- FUNC 0000515A FUN_18000515a (6 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_18000515a(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000515a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_1800191e8)();
  return;
}

/* ---- FUNC 00005170 thunk_FUN_18000517a (2 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_18000517a(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000517a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_180019208)();
  return;
}

/* ---- FUNC 0000517A FUN_18000517a (6 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_18000517a(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000517a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_180019208)();
  return;
}

/* ---- FUNC 00005180 thunk_FUN_18000518a (2 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_18000518a(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000518a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_180019218)();
  return;
}

/* ---- FUNC 0000518A FUN_18000518a (6 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_18000518a(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000518a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_180019218)();
  return;
}
