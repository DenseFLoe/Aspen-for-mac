/* RVA 0x1000 */
void FUN_180001000(void)

{
  BOOL BVar1;
  DWORD DVar2;
  
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&DAT_1800527c0,0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if (0 < (int)DVar2) {
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
    if ((int)DVar2 < 0) {
      DAT_1800534b0 = 1;
      atexit(FUN_180039630);
      return;
    }
  }
  DAT_1800527a0 = 0x48;
  atexit(FUN_180039630);
  return;
}

/* RVA 0x1060 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180001060(void)

{
  if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4) <
      DAT_180053528) {
    FUN_180035090(&DAT_180053528);
    if (DAT_180053528 == -1) {
      _DAT_180053518 = 8;
      _DAT_180053520 = 0xffffffffffffffff;
      _Init_thread_footer(&DAT_180053528);
    }
  }
  _DAT_180053540 = &DAT_180053518;
  return;
}

/* RVA 0x10e0 */
void FUN_1800010e0(void)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_1800540c0);
  atexit((_func_5014 *)&LAB_1800396d0);
  return;
}

/* RVA 0x1110 */
void FUN_180001110(void)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_1800540b0);
  atexit((_func_5014 *)&LAB_1800396e0);
  return;
}

/* RVA 0x1140 */
void FUN_180001140(void)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_180054088);
  atexit((_func_5014 *)&LAB_1800396f0);
  return;
}

/* RVA 0x1170 */
void FUN_180001170(void)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_1800540b8);
  atexit((_func_5014 *)&LAB_180039700);
  return;
}

/* RVA 0x11a0 */
void FUN_1800011a0(void)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_1800540a8,"V15.0"
            );
  atexit((_func_5014 *)&LAB_180039710);
  return;
}

/* RVA 0x11f0 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1800011f0(void)

{
  BOOL BVar1;
  DWORD DVar2;
  longlong *plVar3;
  longlong *plVar4;
  
  DAT_1800534d0 = &DAT_1800540e0;
  BVar1 = InitializeCriticalSectionEx((LPCRITICAL_SECTION)&DAT_1800540f8,0,0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if (0 < (int)DVar2) {
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
    if ((int)DVar2 < 0) {
      DAT_1800534b0 = 1;
      goto LAB_180001243;
    }
  }
  _DAT_1800540e8 = 0x38;
LAB_180001243:
  _DAT_1800540d0 = _DAT_1800429c8;
  uRam00000001800540d4 = _UNK_1800429cc;
  uRam00000001800540d8 = _UNK_1800429d0;
  uRam00000001800540dc = _UNK_1800429d4;
  plVar3 = (longlong *)PTR_DAT_1800527b8;
  plVar4 = (longlong *)PTR_PTR_1800527b0;
  if (PTR_PTR_1800527b0 < PTR_DAT_1800527b8) {
    do {
      if (*plVar4 != 0) {
        (**(code **)(*plVar4 + 0x38))(1);
        plVar3 = (longlong *)PTR_DAT_1800527b8;
      }
      plVar4 = plVar4 + 1;
    } while (plVar4 < plVar3);
  }
  DAT_1800540e0 = CApwnIPModule::vftable;
  atexit(FUN_1800397c0);
  return;
}

/* RVA 0x12ac */
void FUN_1800012ac(void)

{
  ATL::CAtlBaseModule::CAtlBaseModule((CAtlBaseModule *)&DAT_1800547c0);
  atexit((_func_5014 *)&LAB_180039820);
  return;
}

/* RVA 0x12e0 */
void _guard_check_icall(void)

{
  return;
}

/* RVA 0x12f0 */
void FUN_1800012f0(undefined8 *param_1)

{
  if ((HKEY)*param_1 == (HKEY)0x0) {
    *(undefined4 *)(param_1 + 1) = 0;
    return;
  }
  RegCloseKey((HKEY)*param_1);
  *param_1 = 0;
  *(undefined4 *)(param_1 + 1) = 0;
  return;
}

/* RVA 0x1320 */
CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_180001320(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2,
             undefined8 *param_3)

{
  IAtlStringMgr *pIVar1;
  
  pIVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager(param_2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1,pIVar1);
  ATL::CSimpleStringT<char,1>::Concatenate
            ((CSimpleStringT<char,1> *)param_1,*(char **)param_2,*(int *)(*(char **)param_2 + -0x10)
             ,(char *)*param_3,*(int *)((char *)*param_3 + -0x10));
  return param_1;
}

/* RVA 0x13a0 */
CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_1800013a0(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2,char *param_3)

{
  IAtlStringMgr *pIVar1;
  longlong lVar2;
  
  lVar2 = 0;
  pIVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager(param_2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1,pIVar1);
  if (param_3 != (char *)0x0) {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_3[lVar2] != '\0');
  }
  ATL::CSimpleStringT<char,1>::Concatenate
            ((CSimpleStringT<char,1> *)param_1,*(char **)param_2,*(int *)(*(char **)param_2 + -0x10)
             ,param_3,(int)lVar2);
  return param_1;
}

/* RVA 0x1430 */
CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_180001430(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,char *param_2,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_3)

{
  IAtlStringMgr *pIVar1;
  longlong lVar2;
  
  lVar2 = 0;
  pIVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager(param_3);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1,pIVar1);
  if (param_2 != (char *)0x0) {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_2[lVar2] != '\0');
  }
  ATL::CSimpleStringT<char,1>::Concatenate
            ((CSimpleStringT<char,1> *)param_1,param_2,(int)lVar2,*(char **)param_3,
             *(int *)(*(char **)param_3 + -0x10));
  return param_1;
}

/* RVA 0x14d0 */
undefined8 FUN_1800014d0(int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  ulonglong uVar2;
  
  iVar1 = *param_1;
  uVar2 = (ulonglong)iVar1;
  if ((-1 < iVar1) && (uVar2 < 0x33)) {
    *param_1 = iVar1 + 1;
    if ((&DAT_18003f054)[uVar2 * 6] != 0) {
      *param_2 = (&DAT_18003f050)[uVar2 * 6];
      *param_3 = (&DAT_18003f054)[uVar2 * 6];
      *param_4 = (&DAT_18003f058)[uVar2 * 6];
      return 1;
    }
  }
  return 0;
}

/* RVA 0x1520 */
undefined4 FUN_180001520(void)

{
  return DAT_18005279c;
}

/* RVA 0x1530 */
undefined4 FUN_180001530(void)

{
  return DAT_1800534f4;
}

/* RVA 0x1540 */
undefined4 FUN_180001540(void)

{
  return DAT_180052798;
}

/* RVA 0x1550 */
void FUN_180001550(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  DAT_1800534f0 = 1;
  DAT_180052798 = param_1;
  DAT_18005279c = param_2;
  DAT_1800534f4 = param_3;
  return;
}

/* RVA 0x1570 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180001570(void)

{
  HMODULE hModule;
  FARPROC pFVar1;
  FARPROC pFVar2;
  FARPROC pFVar3;
  INT_PTR IVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 auStack_428 [32];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_180052888 ^ (ulonglong)auStack_428;
  hModule = GetModuleHandleA("MMVersion");
  if (hModule == (HMODULE)0x0) {
    FUN_180001ce0(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Common\\ApwnRegFuncs.cpp",0x70b);
    LogMessage(local_408,2,1);
    uVar6 = 0;
    DAT_180052798 = 1;
    uVar5 = 0x29;
  }
  else {
    pFVar1 = GetProcAddress(hModule,"MVGetProductCode");
    pFVar2 = GetProcAddress(hModule,"MVGetMajorI");
    pFVar3 = GetProcAddress(hModule,"MVGetPointI");
    IVar4 = (*pFVar3)();
    uVar6 = (undefined4)IVar4;
    IVar4 = (*pFVar2)();
    uVar5 = (undefined4)IVar4;
    IVar4 = (*pFVar1)();
    DAT_180052798 = (undefined4)IVar4;
  }
  DAT_1800534f0 = 1;
  DAT_18005279c = uVar5;
  DAT_1800534f4 = uVar6;
  return;
}

/* RVA 0x1680 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined * FUN_180001680(LPCSTR param_1)

{
  undefined **ppuVar1;
  undefined8 *puVar2;
  undefined *puVar3;
  LPCSTR pCVar4;
  int *piVar5;
  int iVar6;
  undefined **ppuVar7;
  undefined8 *puVar8;
  undefined1 auStack_428 [32];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_180052888 ^ (ulonglong)auStack_428;
  if ((DAT_1800534f0 == 0) && (FUN_180001570(), DAT_1800534f0 == 0)) {
    FUN_180001570();
  }
  puVar8 = (undefined8 *)0x0;
  piVar5 = &DAT_18003f050;
  puVar3 = PTR_PTR_18003f060;
  while (puVar3 != (undefined *)0x0) {
    if (((*piVar5 == DAT_180052798) && (piVar5[1] == DAT_18005279c)) && (piVar5[2] == DAT_1800534f4)
       ) {
      ppuVar7 = *(undefined ***)(piVar5 + 4);
      goto LAB_180001740;
    }
    puVar3 = *(undefined **)(piVar5 + 10);
    piVar5 = piVar5 + 6;
  }
  FUN_180001ce0(local_408,"Assert failed in file %s line %d",
                "G:\\Agent\\work\\2\\s\\src\\mm\\Common\\ApwnRegFuncs.cpp",0x71e);
  LogMessage(local_408,2,1);
  ppuVar7 = (undefined **)0x0;
LAB_180001740:
  pCVar4 = *ppuVar7;
  while (pCVar4 != (LPCSTR)0x0) {
    iVar6 = lstrcmpiA(pCVar4,param_1);
    if (iVar6 == 0) goto LAB_1800018a8;
    ppuVar1 = ppuVar7 + 2;
    ppuVar7 = ppuVar7 + 2;
    pCVar4 = *ppuVar1;
  }
  if (DAT_1800534f0 == 0) {
    FUN_180001570();
  }
  piVar5 = &DAT_18003f520;
  puVar3 = PTR_PTR_18003f530;
  do {
    if (puVar3 == (undefined *)0x0) {
      FUN_180001ce0(local_408,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\Common\\ApwnRegFuncs.cpp",0x72b);
      LogMessage(local_408,2,1);
LAB_1800017e4:
      pCVar4 = (LPCSTR)*puVar8;
      while (pCVar4 != (LPCSTR)0x0) {
        iVar6 = lstrcmpiA(pCVar4,param_1);
        if (iVar6 == 0) {
          return (undefined *)puVar8[1];
        }
        puVar2 = puVar8 + 2;
        puVar8 = puVar8 + 2;
        pCVar4 = (LPCSTR)*puVar2;
      }
      ppuVar7 = &PTR_s_IID_IHapp_18004e000;
      pCVar4 = PTR_s_IID_IHapp_18004e000;
      while( true ) {
        if (pCVar4 == (LPCSTR)0x0) {
          FUN_180001ce0(local_408,"Assert failed in file %s line %d",
                        "G:\\Agent\\work\\2\\s\\src\\mm\\Common\\ApwnRegFuncs.cpp",0x743);
          LogMessage(local_408,2,1);
          return &DAT_18003ad3b;
        }
        iVar6 = lstrcmpiA(pCVar4,param_1);
        if (iVar6 == 0) break;
        pCVar4 = ppuVar7[2];
        ppuVar7 = ppuVar7 + 2;
      }
LAB_1800018a8:
      return ppuVar7[1];
    }
    if (*piVar5 == DAT_180052798) {
      puVar8 = *(undefined8 **)(piVar5 + 4);
      goto LAB_1800017e4;
    }
    puVar3 = *(undefined **)(piVar5 + 10);
    piVar5 = piVar5 + 6;
  } while( true );
}

/* RVA 0x18c0 */
void FUN_1800018c0(void)

{
  DAT_1800534f0 = 0;
  return;
}

/* RVA 0x18d0 */
void FUN_1800018d0(long param_1)

{
  code *pcVar1;
  
  if (param_1 == -0x7ff8fff2) {
                    /* WARNING: Subroutine does not return */
    AfxThrowMemoryException();
  }
  AfxThrowOleException(param_1);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

/* RVA 0x18f0 */
ulonglong FUN_1800018f0(undefined8 *param_1,LPCSTR param_2)

{
  longlong *plVar1;
  LSTATUS LVar2;
  HMODULE pHVar3;
  FARPROC pFVar4;
  ulonglong uVar5;
  undefined4 extraout_var;
  HKEY hKey;
  
  plVar1 = (longlong *)param_1[2];
  if (plVar1 != (longlong *)0x0) {
    hKey = (HKEY)*param_1;
    if (*plVar1 == 0) {
      if ((int)plVar1[1] != 0) goto LAB_18000197a;
    }
    else {
      pHVar3 = GetModuleHandleA("Advapi32.dll");
      if ((pHVar3 != (HMODULE)0x0) &&
         (pFVar4 = GetProcAddress(pHVar3,"RegDeleteKeyTransactedA"), pFVar4 != (FARPROC)0x0)) {
        uVar5 = (*pFVar4)(hKey,param_2,0,0,*plVar1,0);
        return uVar5;
      }
    }
    return 1;
  }
  if (DAT_1800534e8 == '\0') {
    pHVar3 = GetModuleHandleA("Advapi32.dll");
    if (pHVar3 == (HMODULE)0x0) {
      DAT_1800534e8 = '\x01';
    }
    else {
      DAT_1800534e0 = GetProcAddress(pHVar3,"RegDeleteKeyExA");
      DAT_1800534e8 = '\x01';
    }
  }
  hKey = (HKEY)*param_1;
  if (DAT_1800534e0 != (FARPROC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000180001a1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar5 = (*DAT_1800534e0)(hKey,param_2,(ulonglong)*(uint *)(param_1 + 1),0);
    return uVar5;
  }
LAB_18000197a:
                    /* WARNING: Could not recover jumptable at 0x000180001989. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LVar2 = RegDeleteKeyA(hKey,param_2);
  return CONCAT44(extraout_var,LVar2);
}

/* RVA 0x1a20 */
void FUN_180001a20(void)

{
  FUN_180001680("CLSID_HappLS");
  return;
}

/* RVA 0x1a30 */
ulonglong FUN_180001a30(undefined8 *param_1,HKEY param_2,LPCSTR param_3,REGSAM param_4)

{
  longlong *plVar1;
  LSTATUS LVar2;
  uint uVar3;
  HMODULE hModule;
  FARPROC pFVar4;
  ulonglong uVar5;
  undefined4 extraout_var;
  HKEY local_res8;
  
  plVar1 = (longlong *)param_1[2];
  uVar3 = 0;
  local_res8 = (HKEY)0x0;
  if (plVar1 == (longlong *)0x0) {
LAB_180001acf:
    LVar2 = RegOpenKeyExA(param_2,param_3,0,param_4,&local_res8);
    uVar5 = CONCAT44(extraout_var,LVar2);
  }
  else {
    if (*plVar1 == 0) {
      if ((int)plVar1[1] != 0) goto LAB_180001acf;
    }
    else {
      hModule = GetModuleHandleA("Advapi32.dll");
      if (hModule == (HMODULE)0x0) {
        return 1;
      }
      pFVar4 = GetProcAddress(hModule,"RegOpenKeyTransactedA");
      if (pFVar4 != (FARPROC)0x0) {
        uVar5 = (*pFVar4)(param_2,param_3,0,param_4,&local_res8,*plVar1,0);
        goto LAB_180001ae8;
      }
    }
    uVar5 = 1;
  }
LAB_180001ae8:
  if ((int)uVar5 == 0) {
    if ((HKEY)*param_1 != (HKEY)0x0) {
      uVar3 = RegCloseKey((HKEY)*param_1);
    }
    *param_1 = local_res8;
    uVar5 = (ulonglong)uVar3;
    *(REGSAM *)(param_1 + 1) = param_4 & 0x300;
  }
  return uVar5;
}

/* RVA 0x1b30 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180001b30(undefined8 *param_1,LPCSTR param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined1 auStackY_1a8 [32];
  DWORD local_168 [2];
  HKEY local_160;
  uint local_158;
  undefined8 local_150;
  HKEY local_148;
  _FILETIME local_140;
  CHAR local_138 [256];
  ulonglong local_38;
  
  local_38 = DAT_180052888 ^ (ulonglong)auStackY_1a8;
  uVar1 = *(uint *)(param_1 + 1);
  local_160 = (HKEY)0x0;
  local_158 = 0;
  local_150 = 0;
  local_148 = (HKEY)0x0;
  uVar2 = RegOpenKeyExA((HKEY)*param_1,param_2,0,uVar1 | 0x2001f,&local_148);
  uVar5 = (ulonglong)uVar2;
  if (uVar2 == 0) {
    uVar5 = 0;
    if (local_160 != (HKEY)0x0) {
      uVar2 = RegCloseKey(local_160);
      uVar5 = (ulonglong)uVar2;
    }
    local_158 = uVar1 & 0x300;
    local_160 = local_148;
  }
  if ((int)uVar5 == 0) {
    local_168[0] = 0x100;
    iVar3 = RegEnumKeyExA(local_160,0,local_138,local_168,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,
                          &local_140);
    while (iVar3 == 0) {
      uVar4 = FUN_180001b30(&local_160,local_138);
      uVar5 = uVar4 & 0xffffffff;
      if ((int)uVar4 != 0) goto LAB_180001c8d;
      local_168[0] = 0x100;
      iVar3 = RegEnumKeyExA(local_160,0,local_138,local_168,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,
                            &local_140);
    }
    if (local_160 != (HKEY)0x0) {
      RegCloseKey(local_160);
      local_160 = (HKEY)0x0;
    }
    local_158 = 0;
    uVar5 = FUN_1800018f0(param_1,param_2);
    uVar5 = uVar5 & 0xffffffff;
  }
LAB_180001c8d:
  if (local_160 != (HKEY)0x0) {
    RegCloseKey(local_160);
  }
  return uVar5;
}

/* RVA 0x1cc0 */
BOOL __stdcall
InitializeCriticalSectionAndSpinCount(LPCRITICAL_SECTION lpCriticalSection,DWORD dwSpinCount)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180001cc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = InitializeCriticalSectionAndSpinCount(lpCriticalSection,dwSpinCount);
  return BVar1;
}

/* RVA 0x1cd0 */
undefined * FUN_180001cd0(void)

{
  return &DAT_1800534d8;
}

/* RVA 0x1ce0 */
int FUN_180001ce0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong *puVar2;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  puVar2 = (ulonglong *)FUN_180001cd0();
  iVar1 = __stdio_common_vsprintf(*puVar2 | 1,param_1,0xffffffffffffffff,param_2,0,&local_res18);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  return iVar1;
}

/* RVA 0x1d40 */
undefined8 FUN_180001d40(void)

{
  return 0;
}

/* RVA 0x1d50 */
void FUN_180001d50(int param_1)

{
  FUN_180005e20(DAT_1800534d0,0x66,param_1,(undefined8 *)0x0);
  return;
}

/* RVA 0x1d70 */
void FUN_180001d70(undefined8 *param_1)

{
  undefined8 *_Memory;
  
  _Memory = (undefined8 *)*param_1;
  while (_Memory != (undefined8 *)0x0) {
    *param_1 = *_Memory;
    free(_Memory);
    _Memory = (undefined8 *)*param_1;
  }
  return;
}

/* RVA 0x1da0 */
void FUN_180001da0(undefined8 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}

/* RVA 0x1dd0 */
void FUN_180001dd0(longlong param_1)

{
  operator_delete__(*(void **)(param_1 + 0xc0));
  if (*(longlong **)(param_1 + 0xd8) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0xd8) + 0x10))();
  }
  if (*(longlong **)(param_1 + 0xd0) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0xd0) + 0x10))();
  }
  return;
}

/* RVA 0x1e20 */
undefined8 * FUN_180001e20(undefined8 *param_1,uint param_2)

{
  *param_1 = ATL::CComObject<CApwnLWHost>::vftable;
  param_1[1] = ATL::CComObject<CApwnLWHost>::vftable;
  param_1[2] = ATL::CComObject<CApwnLWHost>::vftable;
  *(undefined4 *)(param_1 + 3) = 0xc0000001;
  FUN_18001fb30((longlong)param_1);
  (**(code **)(*DAT_1800534d0 + 0x10))();
  operator_delete__((void *)param_1[0x18]);
  if ((longlong *)param_1[0x1b] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x1b] + 0x10))();
  }
  if ((longlong *)param_1[0x1a] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x1a] + 0x10))();
  }
  if ((param_2 & 1) != 0) {
    FUN_180035134(param_1);
  }
  return param_1;
}

/* RVA 0x1ec0 */
undefined8 * FUN_180001ec0(undefined8 *param_1,uint param_2)

{
  *param_1 = ATL::CRegObject::vftable;
  FUN_180003b40(param_1 + 1);
  FUN_180003b40(param_1 + 1);
  if ((void *)param_1[1] != (void *)0x0) {
    free((void *)param_1[1]);
    param_1[1] = 0;
  }
  if ((void *)param_1[2] != (void *)0x0) {
    free((void *)param_1[2]);
    param_1[2] = 0;
  }
  *(undefined4 *)(param_1 + 3) = 0;
  if ((param_2 & 1) != 0) {
    FUN_180035134(param_1);
  }
  return param_1;
}

/* RVA 0x1f50 */
void FUN_180001f50(longlong param_1)

{
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  return;
}

/* RVA 0x1f5c */
void FUN_180001f5c(longlong param_1)

{
  FUN_180001f50(param_1 + -8);
  return;
}

/* RVA 0x1f68 */
void FUN_180001f68(longlong param_1)

{
  FUN_180001f50(param_1 + -0x10);
  return;
}

/* RVA 0x1f80 */
undefined8 FUN_180001f80(void)

{
  return 1;
}

/* RVA 0x1f90 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_180001f90(longlong param_1,LPCWSTR param_2,void *param_3)

{
  undefined1 auVar1 [16];
  undefined1 *puVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined8 *_Memory;
  void *_Dst;
  __uint64 _Var7;
  void *_Dst_00;
  void *pvVar8;
  undefined8 *puVar9;
  undefined1 *puVar10;
  ulonglong uVar11;
  undefined8 *_Src;
  uint uVar12;
  longlong lVar13;
  __uint64 _Size;
  int iVar14;
  undefined1 auStack_a8 [64];
  undefined8 *local_68;
  ulonglong local_60;
  void *local_58;
  longlong local_50;
  void *local_48;
  ulonglong local_38;
  
  puVar10 = auStack_a8;
  local_38 = DAT_180052888 ^ (ulonglong)&local_68;
  local_58 = param_3;
  local_50 = param_1;
  if ((param_2 == (LPCWSTR)0x0) || (param_3 == (void *)0x0)) {
    uVar12 = 0x80070057;
    goto LAB_18000224b;
  }
  iVar14 = 0;
  puVar9 = (undefined8 *)0x0;
  local_68 = (undefined8 *)0x0;
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (param_2[lVar4] != L'\0');
  lVar4 = (longlong)((int)lVar4 + 1) * 2;
  puVar2 = auStack_a8;
  if (lVar4 + 0x80000000U < 0x100000000) {
    iVar3 = (int)lVar4;
    uVar11 = (ulonglong)iVar3;
    if ((iVar3 < 0x401) && (uVar5 = FUN_180006b40(uVar11), (char)uVar5 != '\0')) {
      uVar6 = uVar11 + 0xf;
      if (uVar6 <= uVar11) {
        uVar6 = 0xffffffffffffff0;
      }
      puVar10 = auStack_a8 + -(uVar6 & 0xfffffffffffffff0);
      _Src = (undefined8 *)(auStack_a8 + -(uVar6 & 0xfffffffffffffff0) + 0x40);
      _Memory = puVar9;
    }
    else {
      if (~uVar11 < 0x10) {
                    /* WARNING: Subroutine does not return */
        FUN_1800018d0(-0x7ff8fdea);
      }
      _Memory = malloc(uVar11 + 0x10);
      puVar10 = auStack_a8;
      puVar2 = auStack_a8;
      if (_Memory == (undefined8 *)0x0) goto LAB_1800020db;
      *_Memory = 0;
      local_68 = _Memory;
      _Src = _Memory + 2;
    }
    puVar9 = _Memory;
    puVar2 = puVar10;
    if (_Src == (undefined8 *)0x0) goto LAB_1800020db;
    *(undefined1 *)_Src = 0;
    *(undefined8 *)(puVar10 + 0x38) = 0;
    *(undefined8 *)(puVar10 + 0x30) = 0;
    *(int *)(puVar10 + 0x28) = iVar3;
    *(undefined8 **)(puVar10 + 0x20) = _Src;
    *(undefined8 *)(puVar10 + -8) = 0x1800020c5;
    iVar3 = WideCharToMultiByte(0,0,param_2,-1,*(LPSTR *)(puVar10 + 0x20),*(int *)(puVar10 + 0x28),
                                *(LPCSTR *)(puVar10 + 0x30),*(LPBOOL *)(puVar10 + 0x38));
    if (iVar3 == 0) {
      _Src = (undefined8 *)0x0;
    }
  }
  else {
LAB_1800020db:
    puVar10 = puVar2;
    _Memory = puVar9;
    _Src = (undefined8 *)0x0;
  }
  if (_Src == (undefined8 *)0x0) {
    uVar12 = 0x8007000e;
  }
  else {
    lVar4 = -1;
    do {
      lVar13 = lVar4;
      lVar4 = lVar13 + 1;
    } while (*(char *)((longlong)_Src + lVar4) != '\0');
    _Size = lVar13 + 2;
    *(undefined8 *)(puVar10 + -8) = 0x180002106;
    _Dst = operator_new__(_Size);
    lVar4 = -1;
    do {
      lVar4 = lVar4 + 1;
    } while (*(short *)((longlong)param_3 + lVar4 * 2) != 0);
    local_60 = (longlong)((int)lVar4 + 1) * 2;
    auVar1._8_8_ = 0;
    auVar1._0_8_ = local_60;
    _Var7 = SUB168(ZEXT816(2) * auVar1,0);
    if (SUB168(ZEXT816(2) * auVar1,8) != 0) {
      _Var7 = 0xffffffffffffffff;
    }
    local_48 = _Dst;
    *(undefined8 *)(puVar10 + -8) = 0x18000214c;
    _Dst_00 = operator_new__(_Var7);
    if ((_Dst == (void *)0x0) || (_Dst_00 == (void *)0x0)) {
LAB_180002207:
      iVar14 = -0x7ff8fff2;
    }
    else {
      if (_Size != 0) {
        *(undefined8 *)(puVar10 + -8) = 0x18000217a;
        memcpy(_Dst,_Src,_Size);
      }
      pvVar8 = local_58;
      uVar11 = local_60;
      if (local_60 != 0) {
        *(undefined8 *)(puVar10 + -8) = 0x18000218f;
        memcpy(_Dst_00,pvVar8,uVar11);
      }
      lVar4 = local_50;
      iVar3 = *(int *)(local_50 + 0x18);
      pvVar8 = *(void **)(local_50 + 8);
      *(undefined8 *)(puVar10 + -8) = 0x1800021ac;
      pvVar8 = _recalloc(pvVar8,(longlong)(iVar3 + 1),8);
      if (pvVar8 == (void *)0x0) goto LAB_180002207;
      *(void **)(lVar4 + 8) = pvVar8;
      iVar3 = *(int *)(lVar4 + 0x18);
      pvVar8 = *(void **)(lVar4 + 0x10);
      *(undefined8 *)(puVar10 + -8) = 0x1800021ce;
      pvVar8 = _recalloc(pvVar8,(longlong)(iVar3 + 1),8);
      if (pvVar8 == (void *)0x0) goto LAB_180002207;
      *(void **)(lVar4 + 0x10) = pvVar8;
      lVar13 = (longlong)*(int *)(lVar4 + 0x18) * 8;
      puVar9 = (undefined8 *)(*(longlong *)(lVar4 + 8) + lVar13);
      if (puVar9 != (undefined8 *)0x0) {
        *puVar9 = _Dst;
      }
      puVar9 = (undefined8 *)(*(longlong *)(lVar4 + 0x10) + lVar13);
      if (puVar9 != (undefined8 *)0x0) {
        *puVar9 = _Dst_00;
      }
      *(int *)(lVar4 + 0x18) = *(int *)(lVar4 + 0x18) + 1;
      _Dst = (void *)0x0;
      _Dst_00 = (void *)0x0;
    }
    *(undefined8 *)(puVar10 + -8) = 0x180002212;
    operator_delete__(_Dst_00);
    *(undefined8 *)(puVar10 + -8) = 0x18000221b;
    operator_delete__(_Dst);
    uVar12 = iVar14 >> 0x1f & 0x8007000e;
  }
  while (_Memory != (undefined8 *)0x0) {
    puVar9 = (undefined8 *)*_Memory;
    *(undefined8 *)(puVar10 + -8) = 0x18000223c;
    free(_Memory);
    _Memory = puVar9;
  }
LAB_18000224b:
  *(undefined8 *)(puVar10 + -8) = 0x180002257;
  return uVar12;
}

/* RVA 0x2280 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

ulonglong FUN_180002280(int *param_1,LPCWSTR param_2)

{
  undefined1 *puVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined8 *_Memory;
  ulonglong uVar6;
  undefined8 *puVar7;
  undefined1 *puVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  longlong lVar11;
  undefined1 auStack_78 [64];
  undefined8 *local_38;
  ulonglong local_30;
  
  puVar8 = auStack_78;
  local_30 = DAT_180052888 ^ (ulonglong)&local_38;
  if (param_2 == (LPCWSTR)0x0) {
    uVar6 = 0;
    goto LAB_1800023d5;
  }
  uVar6 = 0;
  puVar7 = (undefined8 *)0x0;
  local_38 = (undefined8 *)0x0;
  lVar11 = -1;
  lVar3 = -1;
  do {
    lVar3 = lVar3 + 1;
  } while (param_2[lVar3] != L'\0');
  lVar3 = (longlong)((int)lVar3 + 1) * 2;
  puVar1 = auStack_78;
  if (lVar3 + 0x80000000U < 0x100000000) {
    iVar2 = (int)lVar3;
    uVar9 = (ulonglong)iVar2;
    if ((iVar2 < 0x401) && (uVar4 = FUN_180006b40(uVar9), (char)uVar4 != '\0')) {
      uVar5 = uVar9 + 0xf;
      if (uVar5 <= uVar9) {
        uVar5 = 0xffffffffffffff0;
      }
      puVar8 = auStack_78 + -(uVar5 & 0xfffffffffffffff0);
      puVar10 = (undefined8 *)(auStack_78 + -(uVar5 & 0xfffffffffffffff0) + 0x40);
      _Memory = puVar7;
    }
    else {
      if (~uVar9 < 0x10) {
                    /* WARNING: Subroutine does not return */
        FUN_1800018d0(-0x7ff8fdea);
      }
      _Memory = malloc(uVar9 + 0x10);
      puVar8 = auStack_78;
      puVar1 = auStack_78;
      if (_Memory == (undefined8 *)0x0) goto LAB_18000239a;
      *_Memory = 0;
      local_38 = _Memory;
      puVar10 = _Memory + 2;
    }
    puVar7 = _Memory;
    puVar1 = puVar8;
    if (puVar10 == (undefined8 *)0x0) goto LAB_18000239a;
    *(undefined1 *)puVar10 = 0;
    *(undefined8 *)(puVar8 + 0x38) = 0;
    *(undefined8 *)(puVar8 + 0x30) = 0;
    *(int *)(puVar8 + 0x28) = iVar2;
    *(undefined8 **)(puVar8 + 0x20) = puVar10;
    *(undefined8 *)(puVar8 + -8) = 0x180002392;
    iVar2 = WideCharToMultiByte(0,0,param_2,-1,*(LPSTR *)(puVar8 + 0x20),*(int *)(puVar8 + 0x28),
                                *(LPCSTR *)(puVar8 + 0x30),*(LPBOOL *)(puVar8 + 0x38));
    if (iVar2 == 0) {
      puVar10 = (undefined8 *)0x0;
    }
  }
  else {
LAB_18000239a:
    puVar8 = puVar1;
    puVar10 = (undefined8 *)0x0;
    _Memory = puVar7;
  }
  if (puVar10 != (undefined8 *)0x0) {
    do {
      lVar11 = lVar11 + 1;
    } while (*(char *)((longlong)puVar10 + lVar11) != '\0');
    *(undefined8 *)(puVar8 + -8) = 0x1800023b9;
    uVar6 = FUN_180002b50(param_1,puVar10,(int)lVar11);
    uVar6 = uVar6 & 0xffffffff;
  }
  while (_Memory != (undefined8 *)0x0) {
    puVar7 = (undefined8 *)*_Memory;
    *(undefined8 *)(puVar8 + -8) = 0x1800023cd;
    free(_Memory);
    _Memory = puVar7;
  }
LAB_1800023d5:
  *(undefined8 *)(puVar8 + -8) = 0x1800023e1;
  return uVar6;
}

/* RVA 0x2410 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180002410(undefined8 *param_1,undefined8 *param_2,LPCSTR param_3,undefined1 *param_4)

{
  BYTE BVar1;
  HKEY hKey;
  longlong lVar2;
  LPCSTR lpValueName;
  int iVar3;
  BOOL BVar4;
  DWORD cbData;
  ulonglong uVar5;
  longlong lVar6;
  LPSTR pCVar7;
  BYTE *pBVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  undefined8 *_Memory;
  undefined4 extraout_var;
  longlong lVar11;
  char cVar12;
  BYTE *pBVar13;
  undefined8 *puVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  uint uVar19;
  DWORD DVar20;
  LPCOLESTR strIn;
  undefined1 auStackY_12f8 [32];
  DWORD local_12c8 [2];
  DWORD local_12c0 [2];
  LPCSTR local_12b8;
  undefined8 *local_12b0;
  undefined8 *local_12a8;
  LPCSTR local_12a0;
  ulonglong local_1298;
  undefined1 *local_1290;
  BYTE *local_1278;
  BYTE local_1270 [264];
  BYTE *local_1168;
  BYTE local_1160 [264];
  BYTE local_1058 [4096];
  ulonglong local_58;
  undefined8 uStack_48;
  
  uStack_48 = 0x180002427;
  local_58 = DAT_180052888 ^ (ulonglong)local_12c8;
  local_12b8 = param_3;
  local_12b0 = param_1;
  local_12a8 = param_2;
  local_12a0 = param_3;
  local_1290 = param_4;
  uVar5 = FUN_180003db0(param_1,local_1058);
  puVar18 = auStackY_12f8;
  if ((int)uVar5 < 0) goto LAB_180002a8d;
  iVar3 = lstrcmpiA((LPCSTR)local_1058,"S");
  if (iVar3 == 0) {
    iVar3 = 8;
  }
  else {
    iVar3 = lstrcmpiA((LPCSTR)local_1058,"M");
    if (iVar3 == 0) {
      iVar3 = 0x4008;
    }
    else {
      iVar3 = lstrcmpiA((LPCSTR)local_1058,"D");
      if (iVar3 == 0) {
        iVar3 = 0x13;
      }
      else {
        iVar3 = lstrcmpiA((LPCSTR)local_1058,"B");
        puVar18 = auStackY_12f8;
        if (iVar3 != 0) {
          uVar5 = 0x80020009;
          goto LAB_180002a8d;
        }
        iVar3 = 0x11;
      }
    }
  }
  while( true ) {
    puVar15 = auStackY_12f8;
    puVar16 = auStackY_12f8;
    puVar17 = auStackY_12f8;
    cVar12 = *(LPCSTR)*param_1;
    if ((((cVar12 != '\t') && (cVar12 != '\n')) && (cVar12 != '\r')) && (cVar12 != ' ')) break;
    pCVar7 = CharNextA((LPCSTR)*param_1);
    *param_1 = pCVar7;
  }
  uVar5 = FUN_180003db0(param_1,local_1058);
  puVar18 = auStackY_12f8;
  if ((int)uVar5 < 0) goto LAB_180002a8d;
  if (iVar3 == 8) {
    lVar11 = -1;
    do {
      lVar6 = lVar11 + 1;
      lVar2 = lVar11 + 1;
      lVar11 = lVar6;
    } while (local_1058[lVar2] != '\0');
    uVar19 = RegSetValueExA((HKEY)*param_2,param_3,0,1,local_1058,(int)lVar6 + 1);
LAB_180002a65:
    puVar15 = puVar17;
    if (uVar19 != 0) {
      *(undefined8 *)(puVar17 + -8) = 0x180002a74;
      uVar19 = FUN_180002cb0(uVar19);
      uVar5 = CONCAT44(extraout_var,uVar19);
      puVar18 = puVar17;
      goto LAB_180002a8d;
    }
  }
  else {
    if (iVar3 == 0x11) {
      uVar5 = 0xffffffffffffffff;
      do {
        uVar9 = uVar5 + 1;
        lVar11 = uVar5 + 1;
        uVar5 = uVar9;
      } while (local_1058[lVar11] != '\0');
      DVar20 = (DWORD)uVar9;
      if ((uVar9 & 1) == 0) {
        cbData = (int)DVar20 / 2;
        uVar5 = (ulonglong)(int)cbData;
        local_1278 = (BYTE *)0x0;
        local_12c8[0] = cbData;
        local_12c0[0] = DVar20;
        local_1298 = uVar5;
        if (cbData == 0) {
LAB_180002918:
          local_1278 = local_1270;
        }
        else {
          if (0xffffffffffffffff / uVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_1800018d0(-0x7ff8fdea);
          }
          if (uVar5 < 0x101) goto LAB_180002918;
          FUN_180002b20(&local_1278,uVar5);
        }
        lpValueName = local_12b8;
        if (local_1278 != (BYTE *)0x0) {
          memset(local_1278,0,uVar5);
          iVar3 = 0;
          if (0 < (int)DVar20) {
            lVar11 = 0;
            do {
              BVar1 = local_1058[lVar11];
              switch(BVar1) {
              case '0':
              case '1':
              case '2':
              case '3':
              case '4':
              case '5':
              case '6':
              case '7':
              case '8':
              case '9':
                cVar12 = BVar1 + 0xd0;
                break;
              default:
                cVar12 = '\0';
                break;
              case 'A':
              case 'B':
              case 'C':
              case 'D':
              case 'E':
              case 'F':
                cVar12 = BVar1 + 0xc9;
                break;
              case 'a':
              case 'b':
              case 'c':
              case 'd':
              case 'e':
              case 'f':
                cVar12 = BVar1 + 0xa9;
              }
              local_1278[iVar3 / 2] =
                   local_1278[iVar3 / 2] | cVar12 << (((byte)iVar3 & 1) * -4 + 4 & 0x1f);
              iVar3 = iVar3 + 1;
              lVar11 = lVar11 + 1;
            } while (lVar11 < (int)DVar20);
          }
          uVar19 = RegSetValueExA((HKEY)*param_2,lpValueName,0,3,local_1278,cbData);
          puVar17 = auStackY_12f8;
          if (local_1278 != local_1270) {
            FUN_180003da0(&local_1278);
            puVar17 = auStackY_12f8;
          }
          goto LAB_180002a65;
        }
        FUN_180003da0(&local_1278);
      }
      uVar5 = 0x80004005;
      puVar18 = auStackY_12f8;
      goto LAB_180002a8d;
    }
    if (iVar3 == 0x13) {
      puVar14 = (undefined8 *)0x0;
      local_1298 = 0;
      lVar11 = -1;
      do {
        lVar6 = lVar11 + 1;
        lVar2 = lVar11 + 1;
        lVar11 = lVar6;
      } while (local_1058[lVar2] != '\0');
      lVar11 = (longlong)((int)lVar6 + 1) * 2;
      _Memory = puVar14;
      puVar18 = auStackY_12f8;
      if (lVar11 + 0x80000000U < 0x100000000) {
        iVar3 = (int)lVar11;
        uVar5 = (ulonglong)iVar3;
        if ((iVar3 < 0x401) && (uVar10 = FUN_180006b40(uVar5), (char)uVar10 != '\0')) {
          uVar9 = uVar5 + 0xf;
          if (uVar9 <= uVar5) {
            uVar9 = 0xffffffffffffff0;
          }
          strIn = (LPCOLESTR)((longlong)local_12c8 + -(uVar9 & 0xfffffffffffffff0));
          puVar16 = auStackY_12f8 + -(uVar9 & 0xfffffffffffffff0);
        }
        else {
          if (~uVar5 < 0x10) {
                    /* WARNING: Subroutine does not return */
            FUN_1800018d0(-0x7ff8fdea);
          }
          _Memory = malloc(uVar5 + 0x10);
          if (_Memory == (undefined8 *)0x0) {
            strIn = (LPCOLESTR)0x0;
            _Memory = puVar14;
            puVar16 = auStackY_12f8;
          }
          else {
            *_Memory = 0;
            strIn = (LPCOLESTR)(_Memory + 2);
          }
        }
        if (strIn == (LPCOLESTR)0x0) {
          puVar18 = puVar16;
          param_3 = local_12b8;
          goto LAB_1800027ec;
        }
        *strIn = L'\0';
        *(int *)(puVar16 + 0x28) = (int)(uVar5 >> 1);
        *(LPCOLESTR *)(puVar16 + 0x20) = strIn;
        *(undefined8 *)(puVar16 + -8) = 0x1800027dc;
        iVar3 = MultiByteToWideChar(0,0,(LPCSTR)local_1058,-1,*(LPWSTR *)(puVar16 + 0x20),
                                    *(int *)(puVar16 + 0x28));
        if (iVar3 == 0) {
          strIn = (LPCOLESTR)0x0;
        }
        param_3 = local_12b8;
      }
      else {
LAB_1800027ec:
        puVar16 = puVar18;
        strIn = (LPCOLESTR)0x0;
      }
      puVar18 = puVar16;
      if (strIn == (LPCOLESTR)0x0) {
        while (_Memory != (undefined8 *)0x0) {
          puVar14 = (undefined8 *)*_Memory;
          *(undefined8 *)(puVar16 + -8) = 0x18000280c;
          free(_Memory);
          _Memory = puVar14;
        }
        uVar5 = 0x8007000e;
        goto LAB_180002a8d;
      }
      *(undefined8 *)(puVar16 + -8) = 0x18000282d;
      uVar19 = VarUI4FromStr(strIn,0,0,local_12c8);
      uVar5 = (ulonglong)uVar19;
      if ((int)uVar19 < 0) {
        while (_Memory != (undefined8 *)0x0) {
          puVar14 = (undefined8 *)*_Memory;
          *(undefined8 *)(puVar16 + -8) = 0x18000284c;
          free(_Memory);
          _Memory = puVar14;
        }
        goto LAB_180002a8d;
      }
      local_12c0[0] = local_12c8[0];
      *(undefined4 *)(puVar16 + 0x28) = 4;
      *(DWORD **)(puVar16 + 0x20) = local_12c0;
      hKey = (HKEY)*param_2;
      *(undefined8 *)(puVar16 + -8) = 0x180002885;
      uVar19 = RegSetValueExA(hKey,param_3,0,4,*(BYTE **)(puVar16 + 0x20),*(DWORD *)(puVar16 + 0x28)
                             );
      while (puVar17 = puVar16, _Memory != (undefined8 *)0x0) {
        puVar14 = (undefined8 *)*_Memory;
        *(undefined8 *)(puVar16 + -8) = 0x18000289c;
        free(_Memory);
        _Memory = puVar14;
      }
      goto LAB_180002a65;
    }
    if (iVar3 == 0x4008) {
      lVar11 = -1;
      do {
        lVar6 = lVar11 + 1;
        lVar2 = lVar11 + 1;
        lVar11 = lVar6;
      } while (local_1058[lVar2] != '\0');
      iVar3 = (int)lVar6 + 2;
      local_1168 = (BYTE *)0x0;
      uVar5 = (ulonglong)iVar3;
      if (iVar3 == 0) {
LAB_1800025bf:
        local_1168 = local_1160;
      }
      else {
        if (0xffffffffffffffff / uVar5 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_1800018d0(-0x7ff8fdea);
        }
        if (uVar5 < 0x101) goto LAB_1800025bf;
        FUN_180002b20(&local_1168,uVar5);
      }
      if (local_1168 == (BYTE *)0x0) {
        uVar19 = 0xe;
      }
      else {
        pBVar8 = local_1058;
        pBVar13 = local_1168;
        while (local_1058[0] != '\0') {
          pCVar7 = CharNextA((LPCSTR)pBVar8);
          if ((*pBVar8 == '\\') && (*pCVar7 == '0')) {
            *pBVar13 = '\0';
            pBVar8 = (BYTE *)CharNextA(pCVar7);
          }
          else {
            *pBVar13 = *pBVar8;
            BVar4 = IsDBCSLeadByte(*pBVar8);
            if (BVar4 != 0) {
              pBVar13 = pBVar13 + 1;
              pBVar8 = pBVar8 + 1;
              if (*pBVar8 == '\0') break;
              *pBVar13 = *pBVar8;
            }
            pBVar8 = pBVar8 + 1;
          }
          pBVar13 = pBVar13 + 1;
          local_1058[0] = *pBVar8;
        }
        pBVar13[0] = '\0';
        pBVar13[1] = '\0';
        if (local_1168 == (BYTE *)0x0) {
          uVar19 = 0xd;
        }
        else {
          DVar20 = 0;
          pBVar8 = local_1168;
          do {
            lVar11 = -1;
            do {
              lVar11 = lVar11 + 1;
            } while (pBVar8[lVar11] != '\0');
            uVar19 = (int)lVar11 + 1;
            pBVar8 = pBVar8 + uVar19;
            DVar20 = DVar20 + uVar19;
          } while (uVar19 != 1);
          uVar19 = RegSetValueExA((HKEY)*param_2,param_3,0,(int)lVar11 + 7,local_1168,DVar20);
        }
      }
      puVar17 = auStackY_12f8;
      if (local_1168 != local_1160) {
        FUN_180003da0(&local_1168);
        puVar17 = auStackY_12f8;
      }
      goto LAB_180002a65;
    }
  }
  puVar18 = local_1290;
  uVar5 = 0;
  *(undefined8 *)(puVar15 + -8) = 0x1800026f9;
  uVar9 = FUN_180003db0(param_1,puVar18);
  if ((int)uVar9 < 0) {
    uVar5 = uVar9 & 0xffffffff;
  }
  puVar18 = puVar15;
LAB_180002a8d:
  *(undefined8 *)(puVar18 + -8) = 0x180002a9c;
  return uVar5;
}

/* RVA 0x2b20 */
void FUN_180002b20(undefined8 *param_1,size_t param_2)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_2);
  if (pvVar1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_1800018d0(-0x7ff8fff2);
  }
  *param_1 = pvVar1;
  return;
}

/* RVA 0x2b50 */
undefined8 FUN_180002b50(int *param_1,void *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  LPVOID pvVar3;
  int *piVar4;
  int iVar5;
  void *_Dst;
  ulonglong _Size;
  ulonglong _Size_00;
  
  _Size = (ulonglong)param_3;
  iVar5 = param_3 + 1 + *param_1;
  if ((iVar5 <= *param_1) || (iVar5 <= param_3)) {
    return 0;
  }
  uVar1 = param_1[1];
  if ((int)uVar1 <= iVar5) {
    do {
      if (0x3fffffff < (int)uVar1) {
        return 0;
      }
      uVar1 = uVar1 * 2;
      param_1[1] = uVar1;
    } while ((int)uVar1 <= iVar5);
    pvVar3 = CoTaskMemRealloc(*(LPVOID *)(param_1 + 2),(ulonglong)uVar1);
    if (pvVar3 == (LPVOID)0x0) {
      return 0;
    }
    *(LPVOID *)(param_1 + 2) = pvVar3;
  }
  iVar5 = *param_1;
  if (iVar5 < 0) {
    return 0;
  }
  iVar2 = param_1[1];
  if (iVar2 <= iVar5) {
    return 0;
  }
  if (iVar2 < iVar2 - iVar5) {
    return 0;
  }
  _Size_00 = (ulonglong)(iVar2 - iVar5);
  _Dst = (void *)((longlong)iVar5 + *(longlong *)(param_1 + 2));
  if (param_3 == 0) {
LAB_180002c0b:
    *param_1 = *param_1 + param_3;
    *(undefined1 *)((longlong)*param_1 + *(longlong *)(param_1 + 2)) = 0;
    return 1;
  }
  if (_Dst == (void *)0x0) {
    piVar4 = _errno();
    *piVar4 = 0x16;
  }
  else {
    if ((param_2 != (void *)0x0) && (_Size <= _Size_00)) {
      memcpy(_Dst,param_2,_Size);
      goto LAB_180002c0b;
    }
    memset(_Dst,0,_Size_00);
    if (param_2 == (void *)0x0) {
      piVar4 = _errno();
      *piVar4 = 0x16;
    }
    else {
      if (_Size <= _Size_00) goto LAB_180002c7f;
      piVar4 = _errno();
      *piVar4 = 0x22;
    }
  }
  _invalid_parameter_noinfo();
LAB_180002c7f:
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* RVA 0x2c90 */
DWORD FUN_180002c90(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  return DVar1;
}

/* RVA 0x2cb0 */
uint FUN_180002cb0(uint param_1)

{
  if ((int)param_1 < 1) {
    return param_1;
  }
  return param_1 & 0xffff | 0x80070000;
}

/* RVA 0x2cc0 */
undefined8 FUN_180002cc0(longlong param_1,longlong param_2,int *param_3,undefined8 *param_4)

{
  longlong lVar1;
  int *piVar2;
  undefined8 uVar3;
  longlong *plVar4;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    return 0x80070057;
  }
  if (param_4 == (undefined8 *)0x0) {
    return 0x80004003;
  }
  if ((((*param_3 == 0) && (param_3[1] == 0)) && (param_3[2] == 0xc0)) && (param_3[3] == 0x46000000)
     ) {
    plVar4 = (longlong *)(*(longlong *)(param_2 + 8) + param_1);
    (**(code **)(*plVar4 + 8))(plVar4);
    uVar3 = 0;
    *param_4 = plVar4;
  }
  else {
    plVar4 = (longlong *)(param_2 + 0x10);
    lVar1 = *(longlong *)(param_2 + 0x10);
    while (lVar1 != 0) {
      piVar2 = (int *)plVar4[-2];
      if ((piVar2 == (int *)0x0) ||
         (((*piVar2 == *param_3 && (piVar2[1] == param_3[1])) &&
          ((piVar2[2] == param_3[2] && (piVar2[3] == param_3[3])))))) {
        if ((code *)*plVar4 == (code *)0x1) {
          plVar4 = (longlong *)(plVar4[-1] + param_1);
          (**(code **)(*plVar4 + 8))(plVar4);
          *param_4 = plVar4;
          return 0;
        }
        uVar3 = (*(code *)*plVar4)(param_1,param_3,param_4,plVar4[-1]);
        if ((int)uVar3 == 0) {
          return 0;
        }
        if ((piVar2 != (int *)0x0) && ((int)uVar3 < 0)) goto LAB_180002dae;
      }
      plVar4 = plVar4 + 3;
      lVar1 = *plVar4;
    }
    uVar3 = 0x80004002;
LAB_180002dae:
    *param_4 = 0;
  }
  return uVar3;
}

/* RVA 0x2e00 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

DWORD FUN_180002e00(HMODULE param_1,LPCWSTR param_2,undefined8 *param_3,ITypeLib **param_4)

{
  ITypeLib *This;
  _func_6693 *p_Var1;
  longlong lVar2;
  DWORD DVar3;
  int iVar4;
  errno_t eVar5;
  LPCSTR lpsz;
  longlong lVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined8 *puVar10;
  BSTR pOVar11;
  uint uVar12;
  undefined8 *_Memory;
  undefined1 *puVar13;
  LPCOLESTR szFile;
  ulonglong uVar14;
  char *_Src;
  LPCSTR _Dst;
  undefined1 auStack_1c8 [64];
  undefined8 *local_188 [2];
  undefined4 local_178;
  undefined1 uStack_174;
  char local_168 [270];
  undefined1 local_5a [2];
  ulonglong local_58;
  
  puVar13 = auStack_1c8;
  local_58 = DAT_180052888 ^ (ulonglong)local_188;
  if ((param_3 == (undefined8 *)0x0) || (param_4 == (ITypeLib **)0x0)) {
    DVar3 = 0x80004003;
    goto LAB_18000327d;
  }
  *param_3 = 0;
  _Memory = (undefined8 *)0x0;
  *param_4 = (ITypeLib *)0x0;
  local_188[0] = param_3;
  DVar3 = GetModuleFileNameA(param_1,local_168,0x104);
  puVar13 = auStack_1c8;
  if (DVar3 == 0) {
    DVar3 = FUN_180002c90();
    puVar13 = auStack_1c8;
  }
  else if (DVar3 == 0x104) {
    DVar3 = 0x8007007a;
    puVar13 = auStack_1c8;
  }
  else {
    lpsz = local_168;
    _Dst = (LPCSTR)0x0;
    while (local_168[0] != '\0') {
      if (local_168[0] == '.') {
        _Dst = lpsz;
      }
      else if (local_168[0] == '\\') {
        _Dst = (LPCSTR)0x0;
      }
      lpsz = CharNextA(lpsz);
      local_168[0] = *lpsz;
    }
    if (_Dst == (LPCSTR)0x0) {
      _Dst = lpsz;
    }
    if (param_2 == (LPCWSTR)0x0) {
LAB_180003019:
      lVar6 = -1;
      do {
        lVar9 = lVar6 + 1;
        lVar2 = lVar6 + 1;
        lVar6 = lVar9;
      } while (local_168[lVar2] != '\0');
      lVar6 = (longlong)((int)lVar9 + 1) * 2;
      if (0xffffffff < lVar6 + 0x80000000U) goto LAB_1800031e5;
      iVar4 = (int)lVar6;
      uVar14 = (ulonglong)iVar4;
      if (iVar4 < 0x401) {
        *(undefined8 *)(puVar13 + -8) = 0x180003055;
        uVar7 = FUN_180006b40(uVar14);
        if ((char)uVar7 == '\0') goto LAB_180003078;
        uVar8 = uVar14 + 0xf;
        if (uVar8 <= uVar14) {
          uVar8 = 0xffffffffffffff0;
        }
        *(undefined8 *)(puVar13 + -8) = 0x18000306e;
        szFile = (LPCOLESTR)(puVar13 + -(uVar8 & 0xfffffffffffffff0) + 0x40);
        puVar13 = puVar13 + -(uVar8 & 0xfffffffffffffff0);
      }
      else {
LAB_180003078:
        if (~uVar14 < 0x10) {
                    /* WARNING: Subroutine does not return */
          *(undefined **)(puVar13 + -8) = &UNK_1800032cc;
          FUN_1800018d0(-0x7ff8fdea);
        }
        *(undefined8 *)(puVar13 + -8) = 0x180003092;
        puVar10 = malloc(uVar14 + 0x10);
        if (puVar10 == (undefined8 *)0x0) goto LAB_1800031e5;
        *puVar10 = _Memory;
        szFile = (LPCOLESTR)(puVar10 + 2);
        _Memory = puVar10;
      }
      if (szFile != (LPCOLESTR)0x0) {
        *(int *)(puVar13 + 0x28) = (int)(uVar14 >> 1);
        *szFile = L'\0';
        *(LPCOLESTR *)(puVar13 + 0x20) = szFile;
        *(undefined8 *)(puVar13 + -8) = 0x1800030d7;
        iVar4 = MultiByteToWideChar(0,0,local_168,-1,*(LPWSTR *)(puVar13 + 0x20),
                                    *(int *)(puVar13 + 0x28));
        if (iVar4 != 0) {
          *(undefined8 *)(puVar13 + -8) = 0x1800030eb;
          DVar3 = LoadTypeLib(szFile,param_4);
          if (-1 < (int)DVar3) {
LAB_18000324b:
            *(undefined8 *)(puVar13 + -8) = 0x180003254;
            pOVar11 = SysAllocString(szFile);
            *local_188[0] = pOVar11;
            if (pOVar11 == (BSTR)0x0) {
              This = *param_4;
              DVar3 = 0x8007000e;
              p_Var1 = This->lpVtbl->Release;
              *(undefined8 *)(puVar13 + -8) = 0x18000326f;
              (*p_Var1)(This);
              *param_4 = (ITypeLib *)0x0;
            }
            goto joined_r0x0001800031ed;
          }
          local_178 = DAT_180040d74;
          uStack_174 = DAT_180040d78;
          if ((char *)0x104 < _Dst + (5 - (longlong)local_168)) goto LAB_18000311e;
          *(undefined8 *)(puVar13 + -8) = 0x18000313f;
          eVar5 = strcpy_s(_Dst,(rsize_t)(local_5a + -(longlong)_Dst),(char *)&local_178);
          if (eVar5 != 0) {
            if (eVar5 == 0xc) {
                    /* WARNING: Subroutine does not return */
              *(undefined **)(puVar13 + -8) = &UNK_1800032d8;
              AfxThrowMemoryException();
            }
            if (eVar5 != 0x50) {
                    /* WARNING: Subroutine does not return */
              *(undefined **)(puVar13 + -8) = &UNK_1800032d2;
              AfxThrowInvalidArgException();
            }
          }
          lVar6 = -1;
          do {
            lVar9 = lVar6 + 1;
            lVar2 = lVar6 + 1;
            lVar6 = lVar9;
          } while (local_168[lVar2] != '\0');
          lVar6 = (longlong)((int)lVar9 + 1) * 2;
          if (0xffffffff < lVar6 + 0x80000000U) goto LAB_1800031e5;
          iVar4 = (int)lVar6;
          uVar14 = (ulonglong)iVar4;
          if (iVar4 < 0x401) {
            *(undefined8 *)(puVar13 + -8) = 0x180003196;
            uVar7 = FUN_180006b40(uVar14);
            if ((char)uVar7 == '\0') goto LAB_1800031c0;
            uVar8 = uVar14 + 0xf;
            if (uVar8 <= uVar14) {
              uVar8 = 0xffffffffffffff0;
            }
            *(undefined8 *)(puVar13 + -8) = 0x1800031b6;
            szFile = (LPCOLESTR)(puVar13 + -(uVar8 & 0xfffffffffffffff0) + 0x40);
            puVar13 = puVar13 + -(uVar8 & 0xfffffffffffffff0);
          }
          else {
LAB_1800031c0:
            if (~uVar14 < 0x10) {
                    /* WARNING: Subroutine does not return */
              *(undefined **)(puVar13 + -8) = &UNK_1800032aa;
              FUN_1800018d0(-0x7ff8fdea);
            }
            *(undefined8 *)(puVar13 + -8) = 0x1800031da;
            puVar10 = malloc(uVar14 + 0x10);
            if (puVar10 == (undefined8 *)0x0) {
              goto LAB_1800031e5;
            }
            *puVar10 = _Memory;
            szFile = (LPCOLESTR)(puVar10 + 2);
            _Memory = puVar10;
          }
          if (szFile != (LPCOLESTR)0x0) {
            *(int *)(puVar13 + 0x28) = (int)(uVar14 >> 1);
            *(LPCOLESTR *)(puVar13 + 0x20) = szFile;
            *szFile = L'\0';
            *(undefined8 *)(puVar13 + -8) = 0x180003235;
            iVar4 = MultiByteToWideChar(0,0,local_168,-1,*(LPWSTR *)(puVar13 + 0x20),
                                        *(int *)(puVar13 + 0x28));
            if (iVar4 != 0) {
              *(undefined8 *)(puVar13 + -8) = 0x180003245;
              DVar3 = LoadTypeLib(szFile,param_4);
              if ((int)DVar3 < 0) goto joined_r0x0001800031ed;
              goto LAB_18000324b;
            }
          }
        }
      }
    }
    else {
      lVar6 = -1;
      do {
        lVar6 = lVar6 + 1;
      } while (param_2[lVar6] != L'\0');
      lVar6 = (longlong)((int)lVar6 + 1) * 2;
      puVar13 = auStack_1c8;
      if (lVar6 + 0x80000000U < 0x100000000) {
        iVar4 = (int)lVar6;
        uVar14 = (ulonglong)iVar4;
        if ((iVar4 < 0x401) && (uVar7 = FUN_180006b40(uVar14), (char)uVar7 != '\0')) {
          uVar8 = uVar14 + 0xf;
          if (uVar8 <= uVar14) {
            uVar8 = 0xffffffffffffff0;
          }
          _Src = (char *)((longlong)local_188 + -(uVar8 & 0xfffffffffffffff0));
          puVar13 = auStack_1c8 + -(uVar8 & 0xfffffffffffffff0);
        }
        else {
          if (~uVar14 < 0x10) {
                    /* WARNING: Subroutine does not return */
            FUN_1800018d0(-0x7ff8fdea);
          }
          puVar10 = malloc(uVar14 + 0x10);
          puVar13 = auStack_1c8;
          if (puVar10 == (undefined8 *)0x0) goto LAB_1800031e5;
          _Src = (char *)(puVar10 + 2);
          *puVar10 = 0;
          _Memory = puVar10;
          puVar13 = auStack_1c8;
        }
        if (_Src != (char *)0x0) {
          *(undefined8 *)(puVar13 + 0x38) = 0;
          *(undefined8 *)(puVar13 + 0x30) = 0;
          *(int *)(puVar13 + 0x28) = iVar4;
          *(char **)(puVar13 + 0x20) = _Src;
          *_Src = '\0';
          *(undefined8 *)(puVar13 + -8) = 0x180002fa0;
          iVar4 = WideCharToMultiByte(0,0,param_2,-1,*(LPSTR *)(puVar13 + 0x20),
                                      *(int *)(puVar13 + 0x28),*(LPCSTR *)(puVar13 + 0x30),
                                      *(LPBOOL *)(puVar13 + 0x38));
          if (iVar4 != 0) {
            lVar6 = -1;
            do {
              lVar6 = lVar6 + 1;
            } while (_Src[lVar6] != '\0');
            uVar12 = (uint)lVar6 + DVar3;
            if (((DVar3 <= uVar12) && ((uint)lVar6 <= uVar12)) && (uVar12 < 0x10e)) {
              *(undefined8 *)(puVar13 + -8) = 0x180002fee;
              eVar5 = strcpy_s(local_168 + DVar3,0x10e - (ulonglong)DVar3,_Src);
              if (eVar5 != 0) {
                if (eVar5 == 0xc) {
                    /* WARNING: Subroutine does not return */
                  *(undefined **)(puVar13 + -8) = &UNK_1800032c1;
                  AfxThrowMemoryException();
                }
                if (eVar5 != 0x50) {
                    /* WARNING: Subroutine does not return */
                  *(undefined **)(puVar13 + -8) = &UNK_1800032bb;
                  AfxThrowInvalidArgException();
                }
              }
              goto LAB_180003019;
            }
LAB_18000311e:
            DVar3 = 0x80004005;
            goto joined_r0x0001800031ed;
          }
        }
      }
    }
LAB_1800031e5:
    DVar3 = 0x8007000e;
  }
joined_r0x0001800031ed:
  while (_Memory != (undefined8 *)0x0) {
    puVar10 = (undefined8 *)*_Memory;
    *(undefined8 *)(puVar13 + -8) = 0x1800031fc;
    free(_Memory);
    _Memory = puVar10;
  }
LAB_18000327d:
  *(undefined8 *)(puVar13 + -8) = 0x18000328c;
  return DVar3;
}

/* RVA 0x32e0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

int FUN_1800032e0(GUID *param_1,int *param_2,int param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  code *pcVar3;
  HRESULT HVar4;
  int iVar5;
  errno_t eVar6;
  LSTATUS LVar7;
  longlong lVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  undefined8 *_Memory;
  HMODULE pHVar11;
  undefined8 *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  int iVar15;
  ulonglong uVar16;
  char *_Src;
  HKEY pHVar17;
  undefined1 auStackY_1d8 [32];
  int local_178 [2];
  longlong *local_170;
  HKEY local_168;
  HKEY local_160;
  undefined4 local_158;
  undefined8 local_150;
  undefined4 local_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  char local_138 [128];
  OLECHAR local_b8 [64];
  ulonglong local_38;
  
  local_38 = DAT_180052888 ^ (ulonglong)local_178;
  iVar15 = 0;
  local_170 = (longlong *)0x0;
  if ((param_2 == (int *)0x0) ||
     ((((param_1->Data1 == DAT_180042ae8 &&
        (iVar5._0_2_ = param_1->Data2, iVar5._2_2_ = param_1->Data3, iVar5 == DAT_180042aec)) &&
       (*(int *)param_1->Data4 == DAT_180042af0)) && (*(int *)(param_1->Data4 + 4) == DAT_180042af4)
      ))) {
LAB_180003833:
    iVar5 = 0;
  }
  else {
    HVar4 = CoCreateInstance((IID *)&DAT_180042b08,(LPUNKNOWN)0x0,1,(IID *)&DAT_180040d80,&local_170
                            );
    puVar14 = auStackY_1d8;
    puVar13 = auStackY_1d8;
    if (HVar4 < 0) goto LAB_180003833;
    iVar5 = *param_2;
    while (iVar5 != 0) {
      puVar2 = *(undefined4 **)(param_2 + 2);
      local_148 = *puVar2;
      uStack_144 = puVar2[1];
      uStack_140 = puVar2[2];
      uStack_13c = puVar2[3];
      if (param_3 == 0) {
        if (iVar5 == 1) {
          (**(code **)(*local_170 + 0x30))();
        }
        else {
          (**(code **)(*local_170 + 0x40))(local_170,param_1,1,&local_148);
        }
      }
      else {
        if (iVar5 == 1) {
          iVar5 = (**(code **)(*local_170 + 0x28))();
        }
        else {
          iVar5 = (**(code **)(*local_170 + 0x38))();
        }
        if (iVar5 < 0) goto LAB_180003835;
      }
      piVar1 = param_2 + 4;
      param_2 = param_2 + 4;
      iVar5 = *piVar1;
    }
    if (param_3 != 0) goto LAB_180003837;
    iVar5 = StringFromGUID2(param_1,local_b8,0x40);
    if (iVar5 != 0) {
      puVar12 = (undefined8 *)0x0;
      lVar8 = -1;
      do {
        lVar8 = lVar8 + 1;
      } while (local_b8[lVar8] != L'\0');
      lVar8 = (longlong)((int)lVar8 + 1) * 2;
      puVar14 = auStackY_1d8;
      if (lVar8 + 0x80000000U < 0x100000000) {
        iVar5 = (int)lVar8;
        uVar16 = (ulonglong)iVar5;
        if ((iVar5 < 0x401) && (uVar9 = FUN_180006b40(uVar16), (char)uVar9 != '\0')) {
          uVar10 = uVar16 + 0xf;
          if (uVar10 <= uVar16) {
            uVar10 = 0xffffffffffffff0;
          }
          puVar13 = auStackY_1d8 + -(uVar10 & 0xfffffffffffffff0);
          _Src = (char *)((longlong)local_178 + -(uVar10 & 0xfffffffffffffff0));
          _Memory = puVar12;
        }
        else {
          if (~uVar16 < 0x10) {
                    /* WARNING: Subroutine does not return */
            FUN_1800018d0(-0x7ff8fdea);
          }
          _Memory = malloc(uVar16 + 0x10);
          puVar14 = auStackY_1d8;
          if (_Memory == (undefined8 *)0x0) goto LAB_1800034ee;
          *_Memory = 0;
          _Src = (char *)(_Memory + 2);
        }
        puVar12 = _Memory;
        puVar14 = puVar13;
        if (_Src == (char *)0x0) goto LAB_1800034ee;
        *(undefined8 *)(puVar13 + 0x38) = 0;
        *(undefined8 *)(puVar13 + 0x30) = 0;
        *(int *)(puVar13 + 0x28) = iVar5;
        *(char **)(puVar13 + 0x20) = _Src;
        *_Src = '\0';
        *(undefined8 *)(puVar13 + -8) = 0x1800034e6;
        iVar5 = WideCharToMultiByte(0,0,local_b8,-1,*(LPSTR *)(puVar13 + 0x20),
                                    *(int *)(puVar13 + 0x28),*(LPCSTR *)(puVar13 + 0x30),
                                    *(LPBOOL *)(puVar13 + 0x38));
        if (iVar5 == 0) {
          _Src = (char *)0x0;
        }
      }
      else {
LAB_1800034ee:
        _Src = (char *)0x0;
        _Memory = puVar12;
      }
      if (_Src != (char *)0x0) {
        *(undefined8 *)(puVar14 + -8) = 0x180003510;
        eVar6 = strcpy_s(local_138,0x80,"CLSID\\");
        if (eVar6 != 0) {
          if (eVar6 == 0xc) goto LAB_18000386d;
          if (eVar6 != 0x50) goto LAB_18000387e;
        }
        *(undefined8 *)(puVar14 + -8) = 0x180003538;
        eVar6 = strcat_s(local_138,0x80,_Src);
        if (eVar6 != 0) {
          if (eVar6 == 0xc) goto LAB_18000386d;
          if (eVar6 != 0x50) goto LAB_18000387e;
        }
        *(undefined8 *)(puVar14 + -8) = 0x180003564;
        eVar6 = strcat_s(local_138,0x80,"\\Required Categories");
        if (eVar6 != 0) {
          if (eVar6 == 0xc) goto LAB_18000386d;
          if (eVar6 != 0x50) goto LAB_18000387e;
        }
        local_160 = (HKEY)0x0;
        *(HKEY **)(puVar14 + 0x20) = &local_168;
        local_158 = 0;
        local_150 = 0;
        local_178[0] = 0;
        local_168 = (HKEY)0x0;
        *(undefined8 *)(puVar14 + -8) = 0x1800035af;
        LVar7 = RegOpenKeyExA((HKEY)0xffffffff80000000,local_138,0,0x20019,
                              *(PHKEY *)(puVar14 + 0x20));
        pHVar17 = local_168;
        if (LVar7 == 0) {
          *(undefined8 *)(puVar14 + 0x58) = 0;
          *(undefined8 *)(puVar14 + 0x50) = 0;
          *(undefined8 *)(puVar14 + 0x48) = 0;
          *(undefined8 *)(puVar14 + 0x40) = 0;
          *(undefined8 *)(puVar14 + 0x38) = 0;
          *(undefined8 *)(puVar14 + 0x30) = 0;
          *(undefined8 *)(puVar14 + 0x28) = 0;
          *(int **)(puVar14 + 0x20) = local_178;
          local_160 = pHVar17;
          *(undefined8 *)(puVar14 + -8) = 0x1800035fc;
          LVar7 = RegQueryInfoKeyA(pHVar17,(LPSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                   *(LPDWORD *)(puVar14 + 0x20),*(LPDWORD *)(puVar14 + 0x28),
                                   *(LPDWORD *)(puVar14 + 0x30),*(LPDWORD *)(puVar14 + 0x38),
                                   *(LPDWORD *)(puVar14 + 0x40),*(LPDWORD *)(puVar14 + 0x48),
                                   *(LPDWORD *)(puVar14 + 0x50),*(PFILETIME *)(puVar14 + 0x58));
          if (pHVar17 != (HKEY)0x0) {
            *(undefined8 *)(puVar14 + -8) = 0x18000360d;
            RegCloseKey(pHVar17);
            local_160 = (HKEY)0x0;
          }
          if ((LVar7 == 0) && (local_178[0] == 0)) {
            if (DAT_1800534e8 == '\0') {
              *(undefined8 *)(puVar14 + -8) = 0x180003631;
              pHVar11 = GetModuleHandleA("Advapi32.dll");
              if (pHVar11 == (HMODULE)0x0) {
                DAT_1800534e8 = '\x01';
              }
              else {
                *(undefined8 *)(puVar14 + -8) = 0x180003646;
                DAT_1800534e0 = GetProcAddress(pHVar11,"RegDeleteKeyExA");
                DAT_1800534e8 = '\x01';
              }
            }
            if (DAT_1800534e0 == (FARPROC)0x0) {
              *(undefined8 *)(puVar14 + -8) = 0x18000368d;
              RegDeleteKeyA((HKEY)0xffffffff80000000,local_138);
            }
            else {
              *(undefined8 *)(puVar14 + -8) = 0x180003685;
              (*DAT_1800534e0)(0xffffffff80000000,local_138,0,0);
            }
          }
        }
        *(undefined8 *)(puVar14 + -8) = 0x1800036a3;
        eVar6 = strcpy_s(local_138,0x80,"CLSID\\");
        if (eVar6 != 0) {
          if (eVar6 == 0xc) goto LAB_18000386d;
          if (eVar6 != 0x50) goto LAB_18000387e;
        }
        *(undefined8 *)(puVar14 + -8) = 0x1800036cb;
        eVar6 = strcat_s(local_138,0x80,_Src);
        if (eVar6 != 0) {
          if (eVar6 == 0xc) goto LAB_18000386d;
          if (eVar6 != 0x50) goto LAB_18000387e;
        }
        *(undefined8 *)(puVar14 + -8) = 0x1800036f7;
        eVar6 = strcat_s(local_138,0x80,"\\Implemented Categories");
        if (eVar6 != 0) {
          if (eVar6 == 0xc) {
LAB_18000386d:
                    /* WARNING: Subroutine does not return */
            *(undefined **)(puVar14 + -8) = &UNK_180003872;
            AfxThrowMemoryException();
          }
          if (eVar6 != 0x50) {
LAB_18000387e:
                    /* WARNING: Subroutine does not return */
            *(undefined **)(puVar14 + -8) = &UNK_180003883;
            AfxThrowInvalidArgException();
          }
        }
        *(undefined8 *)(puVar14 + -8) = 0x180003727;
        uVar16 = FUN_180001a30(&local_160,(HKEY)0xffffffff80000000,local_138,0x20019);
        pHVar17 = local_160;
        if ((int)uVar16 == 0) {
          *(undefined8 *)(puVar14 + 0x58) = 0;
          *(undefined8 *)(puVar14 + 0x50) = 0;
          *(undefined8 *)(puVar14 + 0x48) = 0;
          *(undefined8 *)(puVar14 + 0x40) = 0;
          *(undefined8 *)(puVar14 + 0x38) = 0;
          *(undefined8 *)(puVar14 + 0x30) = 0;
          *(undefined8 *)(puVar14 + 0x28) = 0;
          *(int **)(puVar14 + 0x20) = local_178;
          *(undefined8 *)(puVar14 + -8) = 0x180003770;
          LVar7 = RegQueryInfoKeyA(pHVar17,(LPSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                   *(LPDWORD *)(puVar14 + 0x20),*(LPDWORD *)(puVar14 + 0x28),
                                   *(LPDWORD *)(puVar14 + 0x30),*(LPDWORD *)(puVar14 + 0x38),
                                   *(LPDWORD *)(puVar14 + 0x40),*(LPDWORD *)(puVar14 + 0x48),
                                   *(LPDWORD *)(puVar14 + 0x50),*(PFILETIME *)(puVar14 + 0x58));
          if (pHVar17 != (HKEY)0x0) {
            *(undefined8 *)(puVar14 + -8) = 0x180003781;
            RegCloseKey(pHVar17);
            pHVar17 = (HKEY)0x0;
          }
          if ((LVar7 == 0) && (local_178[0] == 0)) {
            if (DAT_1800534e8 == '\0') {
              *(undefined8 *)(puVar14 + -8) = 0x1800037a4;
              pHVar11 = GetModuleHandleA("Advapi32.dll");
              if (pHVar11 == (HMODULE)0x0) {
                DAT_1800534e8 = '\x01';
              }
              else {
                *(undefined8 *)(puVar14 + -8) = 0x1800037b9;
                DAT_1800534e0 = GetProcAddress(pHVar11,"RegDeleteKeyExA");
                DAT_1800534e8 = '\x01';
              }
            }
            if (DAT_1800534e0 == (FARPROC)0x0) {
              *(undefined8 *)(puVar14 + -8) = 0x180003800;
              RegDeleteKeyA((HKEY)0xffffffff80000000,local_138);
            }
            else {
              *(undefined8 *)(puVar14 + -8) = 0x1800037f8;
              (*DAT_1800534e0)(0xffffffff80000000,local_138,0,0);
            }
          }
        }
        if (pHVar17 != (HKEY)0x0) {
          *(undefined8 *)(puVar14 + -8) = 0x18000380e;
          RegCloseKey(pHVar17);
        }
        *(undefined8 *)(puVar14 + -8) = 0x18000381b;
        RegCloseKey((HKEY)0xffffffff80000000);
      }
      while (_Memory != (undefined8 *)0x0) {
        puVar12 = (undefined8 *)*_Memory;
        *(undefined8 *)(puVar14 + -8) = 0x18000382c;
        free(_Memory);
        _Memory = puVar12;
      }
      goto LAB_180003837;
    }
    iVar5 = 0xd;
  }
LAB_180003835:
  puVar14 = auStackY_1d8;
  iVar15 = iVar5;
LAB_180003837:
  if (local_170 != (longlong *)0x0) {
    pcVar3 = *(code **)(*local_170 + 0x10);
    *(undefined8 *)(puVar14 + -8) = 0x180003846;
    (*pcVar3)();
  }
  *(undefined8 *)(puVar14 + -8) = 0x180003857;
  return iVar15;
}

/* RVA 0x3890 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180003890(HMODULE param_1,LPCWSTR param_2)

{
  code *pcVar1;
  LPCWSTR lpsz;
  DWORD DVar2;
  HRESULT HVar3;
  UINT UVar4;
  errno_t eVar5;
  LPWSTR pWVar6;
  HMODULE hModule;
  FARPROC pFVar7;
  INT_PTR IVar8;
  ulonglong uVar9;
  WCHAR *pWVar10;
  LPWSTR pWVar11;
  undefined1 auStackY_288 [32];
  BSTR local_258;
  ITypeLib *local_250;
  BSTR local_248 [2];
  WCHAR local_238 [259];
  undefined2 local_32;
  ulonglong local_28;
  
  local_28 = DAT_180052888 ^ (ulonglong)auStackY_288;
  pWVar10 = (WCHAR *)0x0;
  local_248[0] = (BSTR)0x0;
  local_250 = (ITypeLib *)0x0;
  DVar2 = FUN_180002e00(param_1,param_2,local_248,&local_250);
  if (-1 < (int)DVar2) {
    local_258 = (BSTR)0x0;
    HVar3 = (*local_250->lpVtbl->GetDocumentation)
                      (local_250,-1,(BSTR *)0x0,(BSTR *)0x0,(DWORD *)0x0,&local_258);
    if ((-1 < HVar3) && (local_258 != (BSTR)0x0)) {
      UVar4 = SysStringLen(local_258);
      eVar5 = wcsncpy_s(local_238,0x104,local_258,(ulonglong)UVar4);
      if (eVar5 != 0) {
        if (eVar5 == 0xc) {
                    /* WARNING: Subroutine does not return */
          AfxThrowMemoryException();
        }
        if (eVar5 != 0x50) {
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
      }
      pWVar11 = local_238;
      local_32 = 0;
      lpsz = local_238;
      while (local_238[0] != L'\0') {
        pWVar6 = CharNextW(lpsz);
        if (((ushort)(*lpsz + L'￑') < 0x2e) &&
           ((0x200000000801U >> ((ulonglong)(ushort)(*lpsz + L'￑') & 0x3f) & 1) != 0)) {
          pWVar11 = pWVar6;
        }
        lpsz = pWVar6;
        local_238[0] = *pWVar6;
      }
      uVar9 = (longlong)pWVar11 - (longlong)local_238 >> 1 & 0xffffffff;
      if (0x207 < uVar9 * 2) {
        FUN_180035758();
        pcVar1 = (code *)swi(3);
        uVar9 = (*pcVar1)();
        return uVar9;
      }
      local_238[uVar9] = L'\0';
      pWVar10 = local_238;
    }
    if (((DAT_1800534c8 != '\x01') ||
        (hModule = GetModuleHandleW(L"OLEAUT32.DLL"), hModule == (HMODULE)0x0)) ||
       (pFVar7 = GetProcAddress(hModule,"RegisterTypeLibForUser"), pFVar7 == (FARPROC)0x0)) {
      pFVar7 = RegisterTypeLib_exref;
    }
    IVar8 = (*pFVar7)(local_250,local_248[0],pWVar10);
    DVar2 = (DWORD)IVar8;
    SysFreeString(local_258);
  }
  if (local_250 != (ITypeLib *)0x0) {
    (*local_250->lpVtbl->Release)(local_250);
  }
  SysFreeString(local_248[0]);
  return (ulonglong)DVar2;
}

/* RVA 0x3a70 */
DWORD FUN_180003a70(HMODULE param_1,LPCWSTR param_2)

{
  DWORD DVar1;
  HMODULE hModule;
  FARPROC pFVar2;
  INT_PTR IVar3;
  ITypeLib *local_res18;
  TLIBATTR *local_res20;
  BSTR local_18 [2];
  
  local_18[0] = (BSTR)0x0;
  local_res18 = (ITypeLib *)0x0;
  DVar1 = FUN_180002e00(param_1,param_2,local_18,&local_res18);
  if ((int)DVar1 < 0) goto LAB_180003b15;
  DVar1 = (*local_res18->lpVtbl->GetLibAttr)(local_res18,&local_res20);
  if ((int)DVar1 < 0) goto LAB_180003b15;
  if (DAT_1800534c8 == '\x01') {
    hModule = GetModuleHandleW(L"OLEAUT32.DLL");
    if (hModule == (HMODULE)0x0) goto LAB_180003ae0;
    pFVar2 = GetProcAddress(hModule,"UnRegisterTypeLibForUser");
    if (pFVar2 == (FARPROC)0x0) goto LAB_180003ae0;
  }
  else {
LAB_180003ae0:
    pFVar2 = UnRegisterTypeLib_exref;
  }
  IVar3 = (*pFVar2)(local_res20,(ulonglong)local_res20->wMajorVerNum,
                    (ulonglong)local_res20->wMinorVerNum,(ulonglong)local_res20->lcid,
                    local_res20->syskind);
  DVar1 = (DWORD)IVar3;
  (*local_res18->lpVtbl->ReleaseTLibAttr)(local_res18,local_res20);
LAB_180003b15:
  if (local_res18 != (ITypeLib *)0x0) {
    (*local_res18->lpVtbl->Release)(local_res18);
  }
  SysFreeString(local_18[0]);
  return DVar1;
}

/* RVA 0x3b40 */
undefined8 FUN_180003b40(longlong *param_1)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  
  iVar1 = (int)param_1[2];
  iVar2 = 0;
  if (0 < iVar1) {
    lVar3 = 0;
    do {
      if ((lVar3 < 0) || (iVar1 <= iVar2)) {
LAB_180003bd9:
                    /* WARNING: Subroutine does not return */
        FUN_1800018d0(-0x7ffffff5);
      }
      operator_delete__(*(void **)(lVar3 + *param_1));
      if ((int)param_1[2] <= iVar2) goto LAB_180003bd9;
      operator_delete__(*(void **)(lVar3 + param_1[1]));
      iVar1 = (int)param_1[2];
      iVar2 = iVar2 + 1;
      lVar3 = lVar3 + 8;
    } while (iVar2 < iVar1);
  }
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  if ((void *)param_1[1] != (void *)0x0) {
    free((void *)param_1[1]);
    param_1[1] = 0;
  }
  *(undefined4 *)(param_1 + 2) = 0;
  return 0;
}

/* RVA 0x3bf0 */
void FUN_180003bf0(longlong param_1)

{
  FUN_180003b40((longlong *)(param_1 + 8));
  return;
}

/* RVA 0x3c00 */
int FUN_180003c00(undefined8 param_1,int *param_2,undefined8 *param_3)

{
  code *pcVar1;
  int iVar2;
  longlong *plVar3;
  undefined8 uVar4;
  longlong *plVar5;
  longlong *plVar6;
  
  if (param_3 == (undefined8 *)0x0) {
    return -0x7fffbffd;
  }
  *param_3 = 0;
  iVar2 = -0x7ff8fff2;
  plVar3 = operator_new(0x380);
  if (plVar3 == (longlong *)0x0) {
    plVar5 = (longlong *)0x0;
  }
  else {
    *(undefined4 *)(plVar3 + 3) = 0;
    plVar3[0x18] = 0;
    plVar3[0x19] = 0;
    plVar3[0x1a] = 0;
    plVar3[0x1b] = 0;
    *(undefined2 *)(plVar3 + 0x1c) = 0;
    *(undefined4 *)((longlong)plVar3 + 0xe4) = 1;
    *(undefined2 *)(plVar3 + 0x1d) = 0;
    *(undefined4 *)(plVar3 + 0x6f) = 0;
    *(undefined1 *)((longlong)plVar3 + 0x37d) = 0;
    plVar3[0x5f] = 0x6e776f6e6b6e75;
    *(undefined4 *)((longlong)plVar3 + 0x2f4) = 0xffffffff;
    *plVar3 = (longlong)ATL::CComObject<CApwnLWHost>::vftable;
    plVar3[1] = (longlong)ATL::CComObject<CApwnLWHost>::vftable;
    plVar3[2] = (longlong)ATL::CComObject<CApwnLWHost>::vftable;
    plVar6 = plVar3;
    (**(code **)(*DAT_1800534d0 + 8))();
    plVar5 = plVar3;
    plVar3 = plVar6;
  }
  if (plVar5 != (longlong *)0x0) {
    *(int *)(plVar5 + 3) = (int)plVar5[3] + 1;
    plVar6 = plVar5;
    uVar4 = FUN_18001fad0((longlong)plVar5);
    iVar2 = 0;
    if ((int)uVar4 < 0) {
      iVar2 = (int)uVar4;
    }
    *(int *)(plVar5 + 3) = (int)plVar5[3] + -1;
    if (iVar2 == 0) {
      pcVar1 = *(code **)*plVar5;
      if (pcVar1 == FUN_180004540) {
        uVar4 = FUN_180002cc0((longlong)plVar5,0x180040e80,param_2,param_3);
        iVar2 = (int)uVar4;
      }
      else {
        iVar2 = (*pcVar1)(plVar5,param_2,param_3,pcVar1,plVar6,plVar3);
      }
      if (iVar2 == 0) {
        return 0;
      }
    }
    (**(code **)(*plVar5 + 0x160))(plVar5,1);
  }
  return iVar2;
}

/* RVA 0x3da0 */
void FUN_180003da0(undefined8 *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180003da3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  free((void *)*param_1);
  return;
}

/* RVA 0x3db0 */
undefined8 FUN_180003db0(undefined8 *param_1,undefined1 *param_2)

{
  byte bVar1;
  LPSTR pCVar2;
  char *lpsz;
  LPCSTR lpsz_00;
  ulonglong uVar3;
  char cVar4;
  uint uVar5;
  undefined1 *puVar6;
  longlong lVar7;
  byte *lpsz_01;
  
  while( true ) {
    lpsz_01 = (byte *)*param_1;
    bVar1 = *lpsz_01;
    uVar5 = (uint)(char)bVar1;
    if ((((uVar5 != 9) && (uVar5 != 10)) && (uVar5 != 0xd)) && (uVar5 != 0x20)) break;
    pCVar2 = CharNextA((LPCSTR)lpsz_01);
    *param_1 = pCVar2;
  }
  if (bVar1 != 0) {
    puVar6 = param_2;
    if (bVar1 != 0x27) {
      do {
        cVar4 = (char)uVar5;
        if (((cVar4 == '\t') || (cVar4 == '\n')) || ((cVar4 == '\r' || (cVar4 == ' ')))) break;
        pCVar2 = CharNextA((LPCSTR)lpsz_01);
        *param_1 = pCVar2;
        uVar3 = (longlong)pCVar2 - (longlong)lpsz_01;
        if (param_2 + 0x1000 <= puVar6 + uVar3 + 1) {
          return 0x80020009;
        }
        if (0 < (int)uVar3) {
          lVar7 = (longlong)lpsz_01 - (longlong)puVar6;
          uVar3 = uVar3 & 0xffffffff;
          do {
            *puVar6 = puVar6[lVar7];
            puVar6 = puVar6 + 1;
            uVar3 = uVar3 - 1;
          } while (uVar3 != 0);
        }
        lpsz_01 = (byte *)*param_1;
        uVar5 = (uint)*lpsz_01;
      } while (*lpsz_01 != 0);
      *puVar6 = 0;
      return 0;
    }
    lpsz = CharNextA((LPCSTR)lpsz_01);
    *param_1 = lpsz;
    if (*lpsz == '\0') {
LAB_180003eb2:
      if (*(char *)*param_1 != '\0') {
        *puVar6 = 0;
        pCVar2 = CharNextA((LPCSTR)*param_1);
        *param_1 = pCVar2;
        return 0;
      }
    }
    else {
      do {
        if ((*lpsz == '\'') && (pCVar2 = CharNextA(lpsz), *pCVar2 != '\'')) goto LAB_180003eb2;
        lpsz_00 = (LPCSTR)*param_1;
        if (*lpsz_00 == '\'') {
          lpsz_00 = CharNextA(lpsz_00);
          *param_1 = lpsz_00;
        }
        pCVar2 = CharNextA(lpsz_00);
        *param_1 = pCVar2;
        uVar3 = (longlong)pCVar2 - (longlong)lpsz_00;
        if (param_2 + 0x1000 <= puVar6 + uVar3 + 1) {
          return 0x80020009;
        }
        if (0 < (int)uVar3) {
          lVar7 = (longlong)lpsz_00 - (longlong)puVar6;
          uVar3 = uVar3 & 0xffffffff;
          do {
            *puVar6 = puVar6[lVar7];
            puVar6 = puVar6 + 1;
            uVar3 = uVar3 - 1;
          } while (uVar3 != 0);
        }
        lpsz = (char *)*param_1;
      } while (*lpsz != '\0');
    }
  }
  return 0x80020009;
}

/* RVA 0x3f50 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180003f50(undefined8 *param_1,uchar *param_2,undefined8 *param_3)

{
  int iVar1;
  char cVar2;
  LPCWSTR pWVar3;
  int iVar4;
  errno_t eVar5;
  int iVar6;
  longlong lVar7;
  undefined1 *pv;
  uchar *puVar8;
  LPSTR pCVar9;
  ulonglong uVar10;
  LPSTR pCVar11;
  LPCSTR pCVar12;
  undefined1 *puVar13;
  int *piVar14;
  undefined1 *puVar15;
  uint uVar16;
  LPCSTR pCVar17;
  int iVar18;
  ulonglong uVar19;
  LPCSTR pCVar20;
  undefined8 uVar21;
  ulonglong uVar22;
  bool bVar23;
  undefined1 auStack_b8 [32];
  char local_98;
  char local_97;
  char local_96;
  int local_90;
  uint local_8c;
  undefined1 *local_88;
  int local_80;
  undefined8 *local_78;
  undefined8 *local_70;
  uchar local_68 [32];
  ulonglong local_48;
  
  local_48 = DAT_180052888 ^ (ulonglong)auStack_b8;
  if ((param_2 == (uchar *)0x0) || (param_3 == (undefined8 *)0x0)) {
    uVar21 = 0x80004003;
  }
  else {
    *param_3 = 0;
    lVar7 = -1;
    do {
      lVar7 = lVar7 + 1;
    } while (param_2[lVar7] != '\0');
    local_8c = (int)lVar7 * 2;
    iVar6 = 0;
    local_90 = 0;
    if ((int)local_8c < 100) {
      local_8c = 1000;
    }
    uVar10 = (ulonglong)local_8c;
    local_78 = param_1;
    local_70 = param_3;
    pv = CoTaskMemAlloc((ulonglong)local_8c);
    local_88 = pv;
    if (pv == (undefined1 *)0x0) {
LAB_180003fed:
      uVar21 = 0x8007000e;
    }
    else {
      *pv = 0;
      *param_1 = param_2;
      local_96 = DAT_1800534c8;
      local_80 = 0;
      local_97 = '\0';
      local_98 = '\0';
      if (*param_2 != '\0') {
        do {
          iVar1 = local_80;
          local_80 = iVar1;
          if (local_96 == '\x01') {
            if (((local_80 == 0) && (puVar8 = _mbsstr(param_2,"HKCR"), puVar8 != (uchar *)0x0)) &&
               (puVar8 == (uchar *)*param_1)) {
              pCVar9 = CharNextA((LPCSTR)*param_1);
              *param_1 = pCVar9;
              pCVar9 = CharNextA(pCVar9);
              *param_1 = pCVar9;
              pCVar9 = CharNextA(pCVar9);
              *param_1 = pCVar9;
              pCVar9 = CharNextA(pCVar9);
              *param_1 = pCVar9;
              uVar10 = FUN_180002280(&local_90,L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses");
              pv = local_88;
              if ((int)uVar10 == 0) goto LAB_180003fed;
              local_97 = '\x01';
              uVar10 = (ulonglong)local_8c;
              iVar6 = local_90;
            }
            cVar2 = local_97;
            if (*(LPCSTR)*param_1 == '\'') {
              if (local_98 == '\0') {
                local_98 = '\x01';
                goto LAB_180004221;
              }
              pCVar9 = CharNextA((LPCSTR)*param_1);
              if (*pCVar9 != '\'') {
                local_98 = '\0';
                goto LAB_1800041cf;
              }
              pCVar9 = CharNextA((LPCSTR)*param_1);
              *param_1 = pCVar9;
              pCVar11 = CharNextA(pCVar9);
              iVar18 = (int)pCVar11 - (int)pCVar9;
              iVar1 = iVar6 + iVar18;
              iVar4 = iVar1 + 1;
              if ((iVar4 <= iVar6) || (iVar4 <= iVar18)) goto LAB_180003fed;
              puVar13 = pv;
              if ((int)uVar10 <= iVar4) {
                do {
                  if (0x3fffffff < (int)uVar10) goto LAB_180003fed;
                  local_8c = (int)uVar10 * 2;
                  uVar10 = (ulonglong)local_8c;
                } while ((int)local_8c <= iVar4);
                puVar13 = CoTaskMemRealloc(pv,uVar10);
                if (puVar13 == (undefined1 *)0x0) goto LAB_180003fed;
                local_88 = puVar13;
              }
              pv = puVar13;
              if (((-1 < iVar6) && (iVar4 = (int)uVar10, iVar6 < iVar4)) && (iVar4 - iVar6 <= iVar4)
                 ) {
                uVar19 = (ulonglong)iVar18;
                uVar22 = (ulonglong)(iVar4 - iVar6);
                puVar15 = puVar13 + iVar6;
                if (uVar19 == 0) {
LAB_1800041b3:
                  puVar13[iVar1] = 0;
                  param_1 = local_78;
                  iVar6 = iVar1;
                  local_90 = iVar1;
                  goto LAB_180004221;
                }
                if (puVar15 == (undefined1 *)0x0) goto LAB_180004519;
                if ((pCVar9 != (LPSTR)0x0) && (uVar19 <= uVar22)) {
                  memcpy(puVar15,pCVar9,uVar19);
                  goto LAB_1800041b3;
                }
                memset(puVar15,0,uVar22);
                if (pCVar9 == (LPSTR)0x0) goto LAB_180004519;
                bVar23 = uVar22 < uVar19;
LAB_180004488:
                if (!bVar23) goto LAB_18000452b;
                piVar14 = _errno();
                *piVar14 = 0x22;
LAB_180004525:
                _invalid_parameter_noinfo();
LAB_18000452b:
                    /* WARNING: Subroutine does not return */
                AfxThrowInvalidArgException();
              }
              goto LAB_180003fed;
            }
            if (local_98 != '\0') goto LAB_180004221;
LAB_1800041cf:
            if (*(char *)*param_1 == '{') {
              local_80 = local_80 + 1;
            }
            else {
              local_80 = iVar1;
              if (*(char *)*param_1 == '}') {
                local_80 = iVar1 + -1;
                if (local_80 == 0) {
                  if (cVar2 == '\x01') {
                    uVar10 = FUN_180002280(&local_90,L"\r\n\t}\r\n}\r\n");
                    pv = local_88;
                    if ((int)uVar10 == 0) goto LAB_180003fed;
                    local_97 = '\0';
                    uVar10 = (ulonglong)local_8c;
                    iVar6 = local_90;
                  }
                }
              }
            }
          }
LAB_180004221:
          pCVar17 = (LPCSTR)0x0;
          pCVar12 = (LPCSTR)*param_1;
          if (*pCVar12 == '%') {
            pCVar12 = CharNextA(pCVar12);
            *param_1 = pCVar12;
            cVar2 = *pCVar12;
            if (cVar2 != '%') {
              if (pCVar12 != (LPSTR)0x0) {
                while (pCVar20 = pCVar17, cVar2 != '\0') {
                  if (cVar2 == '%') {
                    pCVar20 = pCVar12;
                    break;
                  }
                  pCVar12 = CharNextA(pCVar12);
                  cVar2 = *pCVar12;
                }
                if (pCVar20 != (LPCSTR)0x0) {
                  puVar8 = (uchar *)*param_1;
                  if (0x1f < (longlong)pCVar20 - (longlong)puVar8) {
                    uVar21 = 0x80004005;
                    goto LAB_1800044d4;
                  }
                  eVar5 = _mbsnbcpy_s(local_68,0x20,puVar8,(longlong)((int)pCVar20 - (int)puVar8));
                  if (eVar5 != 0) {
                    if (eVar5 == 0xc) {
                    /* WARNING: Subroutine does not return */
                      AfxThrowMemoryException();
                    }
                    if (eVar5 != 0x50) {
                    /* WARNING: Subroutine does not return */
                      AfxThrowInvalidArgException();
                    }
                  }
                  lVar7 = param_1[1];
                  pCVar12 = pCVar17;
                  if (0 < *(int *)(lVar7 + 0x18)) {
                    while( true ) {
                      iVar6 = lstrcmpiA(*(LPCSTR *)
                                         (*(longlong *)(lVar7 + 8) + (longlong)pCVar12 * 8),
                                        (LPCSTR)local_68);
                      if (iVar6 == 0) break;
                      uVar16 = (int)pCVar17 + 1;
                      pCVar17 = (LPCSTR)(ulonglong)uVar16;
                      pCVar12 = pCVar12 + 1;
                      if (*(int *)(lVar7 + 0x18) <= (int)uVar16) goto LAB_1800043c3;
                    }
                    if (pCVar12 != (LPCSTR)0xffffffffffffffff) {
                      if (((longlong)pCVar12 < 0) || (*(int *)(lVar7 + 0x18) <= (int)pCVar17)) {
                    /* WARNING: Subroutine does not return */
                        FUN_1800018d0(-0x7ffffff5);
                      }
                      pWVar3 = *(LPCWSTR *)(*(longlong *)(lVar7 + 0x10) + (longlong)pCVar12 * 8);
                      if (pWVar3 != (LPCWSTR)0x0) {
                        uVar10 = FUN_180002280(&local_90,pWVar3);
                        if ((int)uVar10 == 0) goto LAB_1800044b3;
                        pCVar12 = (LPCSTR)*param_1;
                        while (pCVar12 != pCVar20) {
                          pCVar12 = CharNextA(pCVar12);
                          *param_1 = pCVar12;
                        }
                        goto LAB_18000443f;
                      }
                    }
                  }
                }
              }
LAB_1800043c3:
              uVar21 = 0x80020009;
              goto LAB_1800044d4;
            }
            pCVar9 = CharNextA(pCVar12);
            iVar18 = (int)pCVar9 - (int)pCVar12;
            iVar1 = iVar6 + iVar18;
            iVar4 = iVar1 + 1;
            if ((iVar4 <= iVar6) || (iVar4 <= iVar18)) goto LAB_180003fed;
            puVar13 = pv;
            if ((int)uVar10 <= iVar4) {
              do {
                if (0x3fffffff < (int)uVar10) goto LAB_180003fed;
                local_8c = (int)uVar10 * 2;
                uVar10 = (ulonglong)local_8c;
              } while ((int)local_8c <= iVar4);
              puVar13 = CoTaskMemRealloc(pv,uVar10);
              if (puVar13 == (undefined1 *)0x0) goto LAB_180003fed;
              local_88 = puVar13;
            }
            pv = puVar13;
            if (((iVar6 < 0) || (iVar4 = (int)uVar10, iVar4 <= iVar6)) || (iVar4 < iVar4 - iVar6))
            goto LAB_180003fed;
            uVar19 = (ulonglong)iVar18;
            uVar22 = (ulonglong)(iVar4 - iVar6);
            puVar15 = puVar13 + iVar6;
            if (uVar19 != 0) {
              if (puVar15 != (undefined1 *)0x0) {
                if ((pCVar12 != (LPSTR)0x0) && (uVar19 <= uVar22)) {
                  memcpy(puVar15,pCVar12,uVar19);
                  goto LAB_180004303;
                }
                memset(puVar15,0,uVar22);
                if (pCVar12 != (LPSTR)0x0) {
                  bVar23 = uVar22 < uVar19;
                  goto LAB_180004488;
                }
              }
LAB_180004519:
              piVar14 = _errno();
              *piVar14 = 0x16;
              goto LAB_180004525;
            }
LAB_180004303:
            puVar13[iVar1] = 0;
            param_1 = local_78;
            local_90 = iVar1;
          }
          else {
            pCVar9 = CharNextA(pCVar12);
            uVar21 = FUN_180002b50(&local_90,pCVar12,(int)pCVar9 - (int)pCVar12);
            if ((int)uVar21 == 0) {
LAB_1800044b3:
              uVar21 = 0x8007000e;
              pv = local_88;
              goto LAB_1800044d4;
            }
LAB_18000443f:
            uVar10 = (ulonglong)local_8c;
            pv = local_88;
          }
          iVar6 = local_90;
          param_2 = (uchar *)CharNextA((LPCSTR)*param_1);
          *param_1 = param_2;
        } while (*param_2 != '\0');
      }
      uVar21 = 0;
      *local_70 = pv;
      pv = (undefined1 *)0x0;
    }
LAB_1800044d4:
    CoTaskMemFree(pv);
  }
  return uVar21;
}

/* RVA 0x4540 */
undefined8 FUN_180004540(longlong *param_1,int *param_2,undefined8 *param_3)

{
  int *piVar1;
  undefined8 uVar2;
  longlong *plVar3;
  
  if (param_1 == (longlong *)0x0) {
    return 0x80070057;
  }
  if (param_3 == (undefined8 *)0x0) {
    return 0x80004003;
  }
  if ((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) && (param_2[3] == 0x46000000)
     ) {
    (**(code **)(*param_1 + 8))();
    *param_3 = param_1;
    return 0;
  }
  plVar3 = &DAT_180040e90;
  do {
    piVar1 = (int *)plVar3[-2];
    if ((piVar1 == (int *)0x0) ||
       (((*piVar1 == *param_2 && (piVar1[1] == param_2[1])) &&
        ((piVar1[2] == param_2[2] && (piVar1[3] == param_2[3])))))) {
      if ((code *)*plVar3 == (code *)0x1) {
        plVar3 = (longlong *)(plVar3[-1] + (longlong)param_1);
        (**(code **)(*plVar3 + 8))(plVar3);
        *param_3 = plVar3;
        return 0;
      }
      uVar2 = (*(code *)*plVar3)(param_1,param_2,param_3,plVar3[-1]);
      if ((int)uVar2 == 0) {
        return 0;
      }
      if ((piVar1 != (int *)0x0) && ((int)uVar2 < 0)) goto LAB_180004622;
    }
    plVar3 = plVar3 + 3;
  } while (*plVar3 != 0);
  uVar2 = 0x80004002;
LAB_180004622:
  *param_3 = 0;
  return uVar2;
}

/* RVA 0x4674 */
void FUN_180004674(longlong param_1,int *param_2,undefined8 *param_3)

{
  FUN_180004540((longlong *)(param_1 + -8),param_2,param_3);
  return;
}

/* RVA 0x4680 */
void FUN_180004680(longlong param_1,int *param_2,undefined8 *param_3)

{
  FUN_180004540((longlong *)(param_1 + -0x10),param_2,param_3);
  return;
}

/* RVA 0x4690 */
undefined8 FUN_180004690(void)

{
  return 0x80004001;
}

/* RVA 0x46a0 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_1800046a0(undefined8 *param_1,uchar *param_2,int param_3)

{
  byte bVar1;
  HKEY pHVar2;
  undefined8 uVar3;
  byte *pv;
  int iVar4;
  ulonglong uVar5;
  byte *pbVar6;
  LPSTR pCVar7;
  LPCSTR pCVar8;
  byte *pbVar9;
  ulonglong uVar10;
  char cVar11;
  uint uVar12;
  uchar *puVar13;
  longlong lVar14;
  undefined **ppuVar15;
  undefined1 auStackY_1088 [32];
  byte *local_1058 [2];
  uchar local_1048 [4096];
  ulonglong local_48 [2];
  
  local_48[0] = DAT_180052888 ^ (ulonglong)auStackY_1088;
  local_1058[0] = (byte *)0x0;
  uVar5 = FUN_180003f50(param_1,param_2,local_1058);
  pv = local_1058[0];
  if (-1 < (int)uVar5) {
    *param_1 = local_1058[0];
    uVar5 = uVar5 & 0xffffffff;
    if (*local_1058[0] != 0) {
      pbVar6 = local_1058[0];
      do {
        puVar13 = local_1048;
        while( true ) {
          bVar1 = *pbVar6;
          uVar12 = (uint)(char)bVar1;
          if ((((uVar12 != 9) && (uVar12 != 10)) && (uVar12 != 0xd)) && (uVar12 != 0x20)) break;
          pbVar6 = (byte *)CharNextA((LPCSTR)pbVar6);
          *param_1 = pbVar6;
        }
        if (bVar1 == 0) {
LAB_1800048b0:
          uVar5 = 0x80020009;
          break;
        }
        if (bVar1 == 0x27) {
          pCVar7 = CharNextA((LPCSTR)pbVar6);
          *param_1 = pCVar7;
          cVar11 = *pCVar7;
          while ((cVar11 != '\0' &&
                 ((*(LPCSTR)*param_1 != '\'' ||
                  (pCVar7 = CharNextA((LPCSTR)*param_1), *pCVar7 == '\''))))) {
            pCVar8 = (LPCSTR)*param_1;
            if (*pCVar8 == '\'') {
              pCVar8 = CharNextA(pCVar8);
              *param_1 = pCVar8;
            }
            pCVar7 = CharNextA(pCVar8);
            *param_1 = pCVar7;
            uVar5 = (longlong)pCVar7 - (longlong)pCVar8;
            if (local_48 <= puVar13 + uVar5 + 1) goto LAB_1800048b0;
            if (0 < (int)uVar5) {
              lVar14 = (longlong)pCVar8 - (longlong)puVar13;
              uVar5 = uVar5 & 0xffffffff;
              do {
                *puVar13 = puVar13[lVar14];
                puVar13 = puVar13 + 1;
                uVar5 = uVar5 - 1;
              } while (uVar5 != 0);
            }
            cVar11 = *pCVar7;
          }
          pCVar8 = (LPCSTR)*param_1;
          if (*pCVar8 == '\0') goto LAB_1800048b0;
          *puVar13 = '\0';
          pCVar7 = CharNextA(pCVar8);
          *param_1 = pCVar7;
        }
        else {
          do {
            cVar11 = (char)uVar12;
            if (((cVar11 == '\t') || (cVar11 == '\n')) || ((cVar11 == '\r' || (cVar11 == ' '))))
            break;
            pbVar9 = (byte *)CharNextA((LPCSTR)pbVar6);
            *param_1 = pbVar9;
            uVar5 = (longlong)pbVar9 - (longlong)pbVar6;
            if (local_48 <= puVar13 + uVar5 + 1) goto LAB_1800048b0;
            if (0 < (int)uVar5) {
              lVar14 = (longlong)pbVar6 - (longlong)puVar13;
              uVar5 = uVar5 & 0xffffffff;
              do {
                *puVar13 = puVar13[lVar14];
                puVar13 = puVar13 + 1;
                uVar5 = uVar5 - 1;
              } while (uVar5 != 0);
            }
            uVar12 = (uint)*pbVar9;
            pbVar6 = pbVar9;
          } while (*pbVar9 != 0);
          *puVar13 = '\0';
        }
        uVar12 = 0;
        lVar14 = 0;
        ppuVar15 = &PTR_DAT_180040c00;
        while (iVar4 = lstrcmpiA((LPCSTR)local_1048,*ppuVar15), iVar4 != 0) {
          uVar12 = uVar12 + 1;
          lVar14 = lVar14 + 1;
          ppuVar15 = ppuVar15 + 2;
          if (0xd < uVar12) goto LAB_1800048b0;
        }
        pHVar2 = (HKEY)(&DAT_180040c08)[lVar14 * 2];
        if (pHVar2 == (HKEY)0x0) goto LAB_1800048b0;
        puVar13 = local_1048;
        while( true ) {
          pbVar6 = (byte *)*param_1;
          bVar1 = *pbVar6;
          uVar12 = (uint)(char)bVar1;
          if ((((uVar12 != 9) && (uVar12 != 10)) && (uVar12 != 0xd)) && (uVar12 != 0x20)) break;
          pCVar7 = CharNextA((LPCSTR)pbVar6);
          *param_1 = pCVar7;
        }
        if (bVar1 == 0) goto LAB_1800048b0;
        if (bVar1 == 0x27) {
          pCVar7 = CharNextA((LPCSTR)pbVar6);
          *param_1 = pCVar7;
          cVar11 = *pCVar7;
          while ((cVar11 != '\0' &&
                 ((*(LPCSTR)*param_1 != '\'' ||
                  (pCVar7 = CharNextA((LPCSTR)*param_1), *pCVar7 == '\''))))) {
            pCVar8 = (LPCSTR)*param_1;
            if (*pCVar8 == '\'') {
              pCVar8 = CharNextA(pCVar8);
              *param_1 = pCVar8;
            }
            pCVar7 = CharNextA(pCVar8);
            *param_1 = pCVar7;
            uVar5 = (longlong)pCVar7 - (longlong)pCVar8;
            if (local_48 <= puVar13 + uVar5 + 1) goto LAB_1800048b0;
            if (0 < (int)uVar5) {
              lVar14 = (longlong)pCVar8 - (longlong)puVar13;
              uVar5 = uVar5 & 0xffffffff;
              do {
                *puVar13 = puVar13[lVar14];
                puVar13 = puVar13 + 1;
                uVar5 = uVar5 - 1;
              } while (uVar5 != 0);
            }
            cVar11 = *pCVar7;
          }
          pCVar8 = (LPCSTR)*param_1;
          if (*pCVar8 == '\0') goto LAB_1800048b0;
          *puVar13 = '\0';
          pCVar7 = CharNextA(pCVar8);
          *param_1 = pCVar7;
        }
        else {
          do {
            cVar11 = (char)uVar12;
            if (((cVar11 == '\t') || (cVar11 == '\n')) || ((cVar11 == '\r' || (cVar11 == ' '))))
            break;
            pbVar9 = (byte *)CharNextA((LPCSTR)pbVar6);
            *param_1 = pbVar9;
            uVar5 = (longlong)pbVar9 - (longlong)pbVar6;
            if (local_48 <= puVar13 + uVar5 + 1) goto LAB_1800048b0;
            if (0 < (int)uVar5) {
              lVar14 = (longlong)pbVar6 - (longlong)puVar13;
              uVar5 = uVar5 & 0xffffffff;
              do {
                *puVar13 = puVar13[lVar14];
                puVar13 = puVar13 + 1;
                uVar5 = uVar5 - 1;
              } while (uVar5 != 0);
            }
            uVar12 = (uint)*pbVar9;
            pbVar6 = pbVar9;
          } while (*pbVar9 != 0);
          *puVar13 = '\0';
        }
        if (local_1048[0] != '{') goto LAB_1800048b0;
        if (param_3 == 0) {
          uVar10 = FUN_180004e20(param_1,local_1048,pHVar2,0,0);
          uVar5 = uVar10 & 0xffffffff;
          if ((int)uVar10 < 0) break;
        }
        else {
          uVar3 = *param_1;
          uVar10 = FUN_180004e20(param_1,local_1048,pHVar2,param_3,0);
          uVar5 = uVar10 & 0xffffffff;
          if ((int)uVar10 < 0) {
            *param_1 = uVar3;
            FUN_180004e20(param_1,local_1048,pHVar2,0,0);
            break;
          }
        }
        while( true ) {
          pbVar6 = (byte *)*param_1;
          bVar1 = *pbVar6;
          if ((((bVar1 != 9) && (bVar1 != 10)) && (bVar1 != 0xd)) && (bVar1 != 0x20)) break;
          pCVar7 = CharNextA((LPCSTR)pbVar6);
          *param_1 = pCVar7;
        }
      } while (bVar1 != 0);
    }
    CoTaskMemFree(pv);
  }
  return uVar5;
}

/* RVA 0x4b00 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

DWORD FUN_180004b00(undefined8 param_1,LPCWSTR param_2,LPCSTR param_3,LPCSTR param_4,int param_5)

{
  HMODULE hModule;
  uchar *puVar1;
  undefined1 *puVar2;
  int iVar3;
  DWORD DVar4;
  uint uVar5;
  longlong lVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined8 *_Memory;
  HRSRC hResInfo;
  HGLOBAL _Src;
  undefined8 *puVar9;
  undefined1 *puVar10;
  ulonglong uVar11;
  LPCSTR lpLibFileName;
  undefined1 auStack_4d8 [64];
  DWORD local_498 [2];
  undefined8 *local_490;
  HMODULE local_488;
  HGLOBAL local_480;
  undefined8 local_478;
  undefined8 local_470;
  uchar *local_458;
  uchar local_450 [1032];
  ulonglong local_48;
  
  puVar10 = auStack_4d8;
  local_48 = DAT_180052888 ^ (ulonglong)local_498;
  puVar9 = (undefined8 *)0x0;
  local_490 = (undefined8 *)0x0;
  local_478 = 0;
  local_458 = (uchar *)0x0;
  _Memory = puVar9;
  local_470 = param_1;
  if (param_2 != (LPCWSTR)0x0) {
    lVar6 = -1;
    do {
      lVar6 = lVar6 + 1;
    } while (param_2[lVar6] != L'\0');
    lVar6 = (longlong)((int)lVar6 + 1) * 2;
    puVar2 = auStack_4d8;
    if (lVar6 + 0x80000000U < 0x100000000) {
      iVar3 = (int)lVar6;
      uVar11 = (ulonglong)iVar3;
      if ((iVar3 < 0x401) && (uVar7 = FUN_180006b40(uVar11), (char)uVar7 != '\0')) {
        uVar8 = uVar11 + 0xf;
        if (uVar8 <= uVar11) {
          uVar8 = 0xffffffffffffff0;
        }
        puVar10 = auStack_4d8 + -(uVar8 & 0xfffffffffffffff0);
        lpLibFileName = (LPCSTR)((longlong)local_498 + -(uVar8 & 0xfffffffffffffff0));
      }
      else {
        if (~uVar11 < 0x10) {
                    /* WARNING: Subroutine does not return */
          FUN_1800018d0(-0x7ff8fdea);
        }
        _Memory = malloc(uVar11 + 0x10);
        puVar10 = auStack_4d8;
        puVar2 = auStack_4d8;
        if (_Memory == (undefined8 *)0x0) goto LAB_180004c2a;
        *_Memory = 0;
        local_490 = _Memory;
        lpLibFileName = (LPCSTR)(_Memory + 2);
      }
      puVar9 = _Memory;
      puVar2 = puVar10;
      if (lpLibFileName == (LPCSTR)0x0) goto LAB_180004c2a;
      *lpLibFileName = '\0';
      *(undefined8 *)(puVar10 + 0x38) = 0;
      *(undefined8 *)(puVar10 + 0x30) = 0;
      *(int *)(puVar10 + 0x28) = iVar3;
      *(LPCSTR *)(puVar10 + 0x20) = lpLibFileName;
      *(undefined8 *)(puVar10 + -8) = 0x180004c22;
      iVar3 = WideCharToMultiByte(0,0,param_2,-1,*(LPSTR *)(puVar10 + 0x20),*(int *)(puVar10 + 0x28)
                                  ,*(LPCSTR *)(puVar10 + 0x30),*(LPBOOL *)(puVar10 + 0x38));
      if (iVar3 == 0) {
        lpLibFileName = (LPCSTR)0x0;
      }
    }
    else {
LAB_180004c2a:
      puVar10 = puVar2;
      lpLibFileName = (LPCSTR)0x0;
      _Memory = puVar9;
    }
    if (lpLibFileName != (LPCSTR)0x0) {
      *(undefined8 *)(puVar10 + -8) = 0x180004c45;
      local_488 = LoadLibraryExA(lpLibFileName,(HANDLE)0x0,0x60);
      if (local_488 == (HMODULE)0x0) {
        *(undefined8 *)(puVar10 + -8) = 0x180004c60;
        local_488 = LoadLibraryExA(lpLibFileName,(HANDLE)0x0,2);
        if (local_488 != (HMODULE)0x0) goto LAB_180004c78;
        *(undefined8 *)(puVar10 + -8) = 0x180004c71;
        DVar4 = FUN_180002c90();
      }
      else {
LAB_180004c78:
        hModule = local_488;
        *(undefined8 *)(puVar10 + -8) = 0x180004c87;
        hResInfo = FindResourceA(hModule,param_3,param_4);
        if (hResInfo == (HRSRC)0x0) {
          *(undefined8 *)(puVar10 + -8) = 0x180004c94;
          DVar4 = FUN_180002c90();
        }
        else {
          *(undefined8 *)(puVar10 + -8) = 0x180004ca5;
          _Src = LoadResource(hModule,hResInfo);
          local_480 = _Src;
          if (_Src == (HGLOBAL)0x0) {
            *(undefined8 *)(puVar10 + -8) = 0x180004cb6;
            DVar4 = FUN_180002c90();
          }
          else {
            *(undefined8 *)(puVar10 + -8) = 0x180004cc7;
            local_498[0] = SizeofResource(hModule,hResInfo);
            uVar11 = (ulonglong)local_498[0];
            uVar5 = local_498[0] + 1;
            if (uVar5 < local_498[0]) {
              DVar4 = 0x8007000e;
            }
            else {
              if (uVar5 == 0) {
LAB_180004d0f:
                local_458 = local_450;
              }
              else {
                if (0xffffffffffffffff / (ulonglong)uVar5 == 0) {
                    /* WARNING: Subroutine does not return */
                  *(undefined **)(puVar10 + -8) = &UNK_180004e14;
                  FUN_1800018d0(-0x7ff8fdea);
                }
                if ((ulonglong)uVar5 < 0x401) goto LAB_180004d0f;
                *(undefined8 *)(puVar10 + -8) = 0x180004d0d;
                FUN_180002b20(&local_458,(ulonglong)uVar5);
              }
              puVar1 = local_458;
              if (local_458 == (uchar *)0x0) {
                DVar4 = 0x8007000e;
              }
              else {
                if (uVar11 != 0) {
                  *(undefined8 *)(puVar10 + -8) = 0x180004d4a;
                  memcpy(puVar1,_Src,uVar11);
                }
                puVar1 = local_458;
                local_458[uVar11] = '\0';
                *(undefined8 *)(puVar10 + -8) = 0x180004d66;
                uVar11 = FUN_1800046a0(&local_478,puVar1,param_5);
                DVar4 = (DWORD)uVar11;
              }
            }
          }
        }
        if (hModule != (HMODULE)0x0) {
          *(undefined8 *)(puVar10 + -8) = 0x180004d76;
          FreeLibrary(hModule);
        }
      }
      if (local_458 != local_450) {
        *(undefined8 *)(puVar10 + -8) = 0x180004d8a;
        FUN_180003da0(&local_458);
      }
      while (_Memory != (undefined8 *)0x0) {
        puVar9 = (undefined8 *)*_Memory;
        *(undefined8 *)(puVar10 + -8) = 0x180004d9c;
        free(_Memory);
        _Memory = puVar9;
      }
      goto LAB_180004dd6;
    }
  }
  if (local_458 != local_450) {
    *(undefined8 *)(puVar10 + -8) = 0x180004db8;
    FUN_180003da0(&local_458);
  }
  while (_Memory != (undefined8 *)0x0) {
    puVar9 = (undefined8 *)*_Memory;
    *(undefined8 *)(puVar10 + -8) = 0x180004dcc;
    free(_Memory);
    _Memory = puVar9;
  }
  DVar4 = 0x8007000e;
LAB_180004dd6:
  *(undefined8 *)(puVar10 + -8) = 0x180004de5;
  return DVar4;
}

/* RVA 0x4e20 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180004e20(undefined8 *param_1,uchar *param_2,HKEY param_3,int param_4,int param_5)

{
  byte bVar1;
  uchar uVar2;
  bool bVar3;
  bool bVar4;
  longlong *plVar5;
  HKEY hKey;
  int iVar6;
  int iVar7;
  int iVar8;
  errno_t eVar9;
  LSTATUS LVar10;
  ulonglong uVar11;
  LPSTR pCVar12;
  char *pcVar13;
  LPCSTR pCVar14;
  ulonglong uVar15;
  byte *pbVar16;
  HMODULE pHVar17;
  FARPROC pFVar18;
  INT_PTR IVar19;
  char cVar20;
  uint uVar21;
  uint uVar22;
  uchar *puVar23;
  undefined **ppuVar24;
  CHAR *pCVar25;
  longlong lVar26;
  byte *pbVar27;
  HKEY hKey_00;
  undefined1 auStackY_1218 [32];
  HKEY local_11b8;
  HKEY local_11b0;
  int local_11a8;
  HKEY local_11a0;
  undefined4 local_1198;
  longlong *local_1190;
  DWORD local_1188 [2];
  HKEY local_1180;
  undefined4 local_1178;
  undefined8 local_1170;
  uchar local_1168 [272];
  CHAR local_1058 [4096];
  ulonglong local_58 [2];
  undefined8 uStack_48;
  
  uStack_48 = 0x180004e3f;
  local_58[0] = DAT_180052888 ^ (ulonglong)auStackY_1218;
  hKey_00 = (HKEY)0x0;
  local_11a0 = (HKEY)0x0;
  local_1198 = 0;
  local_1190 = (longlong *)0x0;
  local_11b0 = param_3;
  local_11a8 = param_4;
LAB_180004e74:
  uVar11 = FUN_180003db0(param_1,param_2);
  do {
    uVar15 = uVar11 & 0xffffffff;
    if ((int)uVar11 < 0) {
LAB_180005cb1:
      if (hKey_00 != (HKEY)0x0) {
        RegCloseKey(hKey_00);
      }
      return uVar15;
    }
LAB_180004e83:
    if (*param_2 == '}') goto LAB_180005cb1;
    iVar6 = lstrcmpiA((LPCSTR)param_2,"Delete");
    iVar7 = lstrcmpiA((LPCSTR)param_2,"ForceRemove");
    if ((iVar7 != 0) && (iVar6 != 0)) goto LAB_1800050e3;
    while( true ) {
      pbVar27 = (byte *)*param_1;
      bVar1 = *pbVar27;
      uVar21 = (uint)(char)bVar1;
      if ((uVar21 != 9) && (((uVar21 != 10 && (uVar21 != 0xd)) && (uVar21 != 0x20)))) break;
      pCVar12 = CharNextA((LPCSTR)pbVar27);
      *param_1 = pCVar12;
    }
    if (bVar1 == 0) goto LAB_180005cac;
    puVar23 = param_2;
    if (bVar1 == 0x27) {
      pcVar13 = CharNextA((LPCSTR)pbVar27);
      *param_1 = pcVar13;
      cVar20 = *pcVar13;
      while ((cVar20 != '\0' &&
             ((*pcVar13 != '\'' || (pCVar12 = CharNextA(pcVar13), *pCVar12 == '\''))))) {
        pCVar14 = (LPCSTR)*param_1;
        if (*pCVar14 == '\'') {
          pCVar14 = CharNextA(pCVar14);
          *param_1 = pCVar14;
        }
        pCVar12 = CharNextA(pCVar14);
        *param_1 = pCVar12;
        uVar11 = (longlong)pCVar12 - (longlong)pCVar14;
        if (param_2 + 0x1000 <= puVar23 + uVar11 + 1) goto LAB_180005cac;
        if (0 < (int)uVar11) {
          lVar26 = (longlong)pCVar14 - (longlong)puVar23;
          uVar11 = uVar11 & 0xffffffff;
          do {
            *puVar23 = puVar23[lVar26];
            puVar23 = puVar23 + 1;
            uVar11 = uVar11 - 1;
          } while (uVar11 != 0);
        }
        pcVar13 = (char *)*param_1;
        cVar20 = *pcVar13;
      }
      if (*(char *)*param_1 == '\0') goto LAB_180005cac;
      *puVar23 = '\0';
      pCVar12 = CharNextA((LPCSTR)*param_1);
      *param_1 = pCVar12;
    }
    else {
      do {
        cVar20 = (char)uVar21;
        if (((cVar20 == '\t') || (cVar20 == '\n')) || ((cVar20 == '\r' || (cVar20 == ' ')))) break;
        pCVar12 = CharNextA((LPCSTR)pbVar27);
        *param_1 = pCVar12;
        uVar11 = (longlong)pCVar12 - (longlong)pbVar27;
        if (param_2 + 0x1000 <= puVar23 + uVar11 + 1) goto LAB_180005cac;
        if (0 < (int)uVar11) {
          lVar26 = (longlong)pbVar27 - (longlong)puVar23;
          uVar11 = uVar11 & 0xffffffff;
          do {
            *puVar23 = puVar23[lVar26];
            puVar23 = puVar23 + 1;
            uVar11 = uVar11 - 1;
          } while (uVar11 != 0);
        }
        pbVar27 = (byte *)*param_1;
        uVar21 = (uint)*pbVar27;
      } while (*pbVar27 != 0);
      *puVar23 = '\0';
    }
    iVar7 = local_11a8;
    if (local_11a8 != 0) {
      local_1180 = (HKEY)0x0;
      local_1178 = 0;
      local_1170 = 0;
      uVar2 = *param_2;
      puVar23 = param_2;
      while (uVar2 != '\0') {
        if (uVar2 == '\\') {
          if (puVar23 != (uchar *)0x0) goto LAB_180005cac;
          break;
        }
        puVar23 = (uchar *)CharNextA((LPCSTR)puVar23);
        uVar2 = *puVar23;
      }
      ppuVar24 = &PTR_s_AppID_180040ae0;
      do {
        iVar8 = lstrcmpiA((LPCSTR)param_2,*ppuVar24);
        if (iVar8 == 0) goto LAB_1800050ae;
        ppuVar24 = ppuVar24 + 1;
      } while ((longlong)ppuVar24 < 0x180040b40);
      local_1180 = local_11b0;
      local_1178 = 0;
      local_1170 = 0;
      FUN_180001b30(&local_1180,(LPCSTR)param_2);
LAB_1800050ae:
      if (iVar6 != 0) goto LAB_1800050e3;
      uVar11 = FUN_180003db0(param_1,param_2);
      uVar15 = uVar11 & 0xffffffff;
      if ((int)uVar11 < 0) goto LAB_180005cb1;
      uVar15 = FUN_180005d60(param_1,(char *)param_2);
      iVar6 = (int)uVar15;
joined_r0x0001800050d6:
      uVar15 = uVar15 & 0xffffffff;
      if (iVar6 < 0) goto LAB_180005cb1;
LAB_1800058b8:
      if (*param_2 == '{') {
        lVar26 = -1;
        do {
          lVar26 = lVar26 + 1;
        } while (param_2[lVar26] != '\0');
        if (lVar26 == 1) {
          uVar11 = FUN_180004e20(param_1,param_2,hKey_00,iVar7,0);
          uVar15 = uVar11 & 0xffffffff;
          if (-1 < (int)uVar11) goto LAB_180004e74;
          goto LAB_180005cb1;
        }
      }
      goto LAB_180004e83;
    }
LAB_1800050e3:
    iVar6 = lstrcmpiA((LPCSTR)param_2,"NoRemove");
    uVar21 = 0;
    bVar4 = true;
    if (iVar6 == 0) {
      while( true ) {
        pbVar27 = (byte *)*param_1;
        bVar1 = *pbVar27;
        uVar22 = (uint)(char)bVar1;
        if ((((uVar22 != 9) && (uVar22 != 10)) && (uVar22 != 0xd)) && (uVar22 != 0x20)) break;
        pCVar12 = CharNextA((LPCSTR)pbVar27);
        *param_1 = pCVar12;
      }
      if (bVar1 != 0) {
        puVar23 = param_2;
        bVar4 = false;
        if (bVar1 == 0x27) {
          pcVar13 = CharNextA((LPCSTR)pbVar27);
          *param_1 = pcVar13;
          cVar20 = *pcVar13;
          while ((cVar20 != '\0' &&
                 ((*pcVar13 != '\'' || (pCVar12 = CharNextA(pcVar13), *pCVar12 == '\''))))) {
            pCVar14 = (LPCSTR)*param_1;
            if (*pCVar14 == '\'') {
              pCVar14 = CharNextA(pCVar14);
              *param_1 = pCVar14;
            }
            pCVar12 = CharNextA(pCVar14);
            *param_1 = pCVar12;
            uVar11 = (longlong)pCVar12 - (longlong)pCVar14;
            if (param_2 + 0x1000 <= puVar23 + uVar11 + 1) goto LAB_180005cac;
            if (0 < (int)uVar11) {
              lVar26 = (longlong)pCVar14 - (longlong)puVar23;
              uVar11 = uVar11 & 0xffffffff;
              do {
                *puVar23 = puVar23[lVar26];
                puVar23 = puVar23 + 1;
                uVar11 = uVar11 - 1;
              } while (uVar11 != 0);
            }
            pcVar13 = (char *)*param_1;
            cVar20 = *pcVar13;
          }
          if (*(char *)*param_1 == '\0') goto LAB_180005cac;
          *puVar23 = '\0';
          pCVar12 = CharNextA((LPCSTR)*param_1);
          *param_1 = pCVar12;
        }
        else {
          do {
            cVar20 = (char)uVar22;
            if (((cVar20 == '\t') || (cVar20 == '\n')) || ((cVar20 == '\r' || (cVar20 == ' '))))
            break;
            pCVar12 = CharNextA((LPCSTR)pbVar27);
            *param_1 = pCVar12;
            uVar11 = (longlong)pCVar12 - (longlong)pbVar27;
            if (param_2 + 0x1000 <= puVar23 + uVar11 + 1) goto LAB_180005cac;
            if (0 < (int)uVar11) {
              lVar26 = (longlong)pbVar27 - (longlong)puVar23;
              uVar11 = uVar11 & 0xffffffff;
              do {
                *puVar23 = puVar23[lVar26];
                puVar23 = puVar23 + 1;
                uVar11 = uVar11 - 1;
              } while (uVar11 != 0);
            }
            pbVar27 = (byte *)*param_1;
            uVar22 = (uint)*pbVar27;
          } while (*pbVar27 != 0);
          *puVar23 = '\0';
        }
        goto LAB_18000524c;
      }
LAB_180005cac:
      uVar15 = 0x80020009;
      goto LAB_180005cb1;
    }
LAB_18000524c:
    iVar6 = lstrcmpiA((LPCSTR)param_2,"Val");
    if (iVar6 != 0) {
      uVar2 = *param_2;
      puVar23 = param_2;
      iVar7 = local_11a8;
      plVar5 = local_1190;
      while( true ) {
        local_11a8 = iVar7;
        local_1190 = plVar5;
        if (uVar2 == '\0') break;
        if (uVar2 == '\\') {
          if (puVar23 != (uchar *)0x0) goto LAB_180005cac;
          break;
        }
        puVar23 = (uchar *)CharNextA((LPCSTR)puVar23);
        uVar2 = *puVar23;
        iVar7 = local_11a8;
        plVar5 = local_1190;
      }
      if (iVar7 != 0) {
        local_11b8 = (HKEY)0x0;
        if (plVar5 == (longlong *)0x0) {
LAB_180005677:
          iVar6 = RegOpenKeyExA(local_11b0,(LPCSTR)param_2,0,0x2001f,&local_11b8);
LAB_180005698:
          if (iVar6 != 0) goto LAB_1800056c1;
          uVar22 = uVar21;
          if (hKey_00 != (HKEY)0x0) {
            uVar22 = RegCloseKey(hKey_00);
          }
          local_11a0 = local_11b8;
          local_1198 = 0;
          hKey_00 = local_11b8;
          if (uVar22 != 0) goto LAB_1800056c1;
        }
        else {
          if (*plVar5 == 0) {
            if ((int)plVar5[1] != 0) goto LAB_180005677;
LAB_180005670:
            iVar6 = 1;
            goto LAB_180005698;
          }
          pHVar17 = GetModuleHandleA("Advapi32.dll");
          if (pHVar17 != (HMODULE)0x0) {
            pFVar18 = GetProcAddress(pHVar17,"RegOpenKeyTransactedA");
            if (pFVar18 == (FARPROC)0x0) goto LAB_180005670;
            IVar19 = (*pFVar18)(local_11b0,param_2);
            iVar6 = (int)IVar19;
            goto LAB_180005698;
          }
LAB_1800056c1:
          local_11b8 = (HKEY)0x0;
          if (plVar5 == (longlong *)0x0) {
LAB_180005739:
            iVar6 = RegOpenKeyExA(local_11b0,(LPCSTR)param_2,0,0x20019,&local_11b8);
LAB_18000575a:
            if (iVar6 == 0) {
              if (hKey_00 != (HKEY)0x0) {
                uVar21 = RegCloseKey(hKey_00);
              }
              local_11a0 = local_11b8;
              local_1198 = 0;
              hKey_00 = local_11b8;
              if (uVar21 == 0) goto LAB_18000587b;
            }
          }
          else {
            if (*plVar5 == 0) {
              if ((int)plVar5[1] != 0) goto LAB_180005739;
LAB_180005732:
              iVar6 = 1;
              goto LAB_18000575a;
            }
            pHVar17 = GetModuleHandleA("Advapi32.dll");
            if (pHVar17 != (HMODULE)0x0) {
              pFVar18 = GetProcAddress(pHVar17,"RegOpenKeyTransactedA");
              if (pFVar18 == (FARPROC)0x0) goto LAB_180005732;
              IVar19 = (*pFVar18)(local_11b0,param_2);
              iVar6 = (int)IVar19;
              goto LAB_18000575a;
            }
          }
          local_11b8 = (HKEY)0x0;
          if (plVar5 == (longlong *)0x0) {
LAB_180005816:
            uVar21 = RegCreateKeyExA(local_11b0,(LPCSTR)param_2,0,(LPSTR)0x0,0,0x2001f,
                                     (LPSECURITY_ATTRIBUTES)0x0,&local_11b8,local_1188);
          }
          else if (*plVar5 == 0) {
            if ((int)plVar5[1] != 0) goto LAB_180005816;
LAB_18000580f:
            uVar21 = 1;
          }
          else {
            pHVar17 = GetModuleHandleA("Advapi32.dll");
            if (pHVar17 == (HMODULE)0x0) {
              uVar21 = 1;
              goto LAB_180005ca1;
            }
            pFVar18 = GetProcAddress(pHVar17,"RegCreateKeyTransactedA");
            if (pFVar18 == (FARPROC)0x0) goto LAB_18000580f;
            IVar19 = (*pFVar18)(local_11b0,param_2);
            uVar21 = (uint)IVar19;
          }
          if (uVar21 != 0) goto LAB_180005ca1;
          uVar21 = 0;
          if (hKey_00 != (HKEY)0x0) {
            uVar21 = RegCloseKey(hKey_00);
          }
          local_11a0 = local_11b8;
          local_1198 = 0;
          hKey_00 = local_11b8;
          if (uVar21 != 0) goto LAB_180005ca1;
        }
LAB_18000587b:
        hKey_00 = local_11a0;
        local_1198 = 0;
        local_11b8 = local_11a0;
        uVar11 = FUN_180003db0(param_1,param_2);
        uVar15 = uVar11 & 0xffffffff;
        if (-1 < (int)uVar11) {
          if (*param_2 == '=') {
            uVar15 = FUN_180002410(param_1,&local_11a0,(LPCSTR)0x0,param_2);
            iVar6 = (int)uVar15;
            hKey_00 = local_11a0;
            goto joined_r0x0001800050d6;
          }
          goto LAB_1800058b8;
        }
        goto LAB_180005cb1;
      }
      if (param_5 == 0) {
        local_11b8 = (HKEY)0x0;
        if (plVar5 == (longlong *)0x0) {
LAB_1800059a2:
          uVar22 = RegOpenKeyExA(local_11b0,(LPCSTR)param_2,0,0x20019,&local_11b8);
        }
        else if (*plVar5 == 0) {
          if ((int)plVar5[1] != 0) goto LAB_1800059a2;
LAB_18000599b:
          uVar22 = 1;
        }
        else {
          pHVar17 = GetModuleHandleA("Advapi32.dll");
          if (pHVar17 == (HMODULE)0x0) {
            uVar22 = 1;
            goto LAB_1800059f5;
          }
          pFVar18 = GetProcAddress(pHVar17,"RegOpenKeyTransactedA");
          if (pFVar18 == (FARPROC)0x0) goto LAB_18000599b;
          IVar19 = (*pFVar18)(local_11b0,param_2,0,0x20019);
          uVar22 = (uint)IVar19;
        }
        if (uVar22 == 0) {
          uVar22 = uVar21;
          if (hKey_00 != (HKEY)0x0) {
            uVar22 = RegCloseKey(hKey_00);
          }
          local_11a0 = local_11b8;
          local_1198 = 0;
          hKey_00 = local_11b8;
        }
      }
      else {
        uVar22 = 2;
      }
LAB_1800059f5:
      iVar6 = 1;
      if (uVar22 == 0) {
        iVar6 = param_5;
      }
      eVar9 = _mbsnbcpy_s(local_1168,0x104,param_2,0xffffffffffffffff);
      if (eVar9 != 0) {
        if (eVar9 == 0xc) {
                    /* WARNING: Subroutine does not return */
          AfxThrowMemoryException();
        }
        if (eVar9 != 0x50) {
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
      }
      uVar11 = FUN_180003db0(param_1,param_2);
      uVar15 = uVar11 & 0xffffffff;
      if ((int)uVar11 < 0) goto LAB_180005cb1;
      uVar11 = FUN_180005d60(param_1,(char *)param_2);
      uVar15 = uVar11 & 0xffffffff;
      if ((int)uVar11 < 0) goto LAB_180005cb1;
      if (*param_2 == '{') {
        lVar26 = -1;
        do {
          lVar26 = lVar26 + 1;
        } while (param_2[lVar26] != '\0');
        if (lVar26 == 1) {
          uVar11 = FUN_180004e20(param_1,param_2,hKey_00,0,iVar6);
          uVar15 = uVar11 & 0xffffffff;
          if (((int)uVar11 < 0) && (iVar6 == 0)) goto LAB_180005cb1;
          uVar11 = FUN_180003db0(param_1,param_2);
          uVar15 = uVar11 & 0xffffffff;
          if ((int)uVar11 < 0) goto LAB_180005cb1;
        }
      }
      if (uVar22 != 2) {
        if (uVar22 != 0) {
          if (param_5 == 0) {
            uVar21 = FUN_180002cb0(uVar22);
            uVar15 = (ulonglong)uVar21;
            goto LAB_180005cb1;
          }
          goto LAB_180004e83;
        }
        if (param_5 != 0) {
          local_11b8 = (HKEY)((ulonglong)local_11b8 & 0xffffffff00000000);
          LVar10 = RegQueryInfoKeyW(hKey_00,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                    (LPDWORD)&local_11b8,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                    (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(PFILETIME)0x0);
          if ((LVar10 == 0) && ((int)local_11b8 != 0)) {
            ppuVar24 = &PTR_s_AppID_180040ae0;
            do {
              iVar6 = lstrcmpiA((LPCSTR)local_1168,*ppuVar24);
              if (iVar6 == 0) goto LAB_180004e83;
              ppuVar24 = ppuVar24 + 1;
            } while ((longlong)ppuVar24 < 0x180040b40);
            if (bVar4) {
              FUN_180001b30(&local_11a0,(LPCSTR)local_1168);
              hKey_00 = local_11a0;
            }
            goto LAB_180004e83;
          }
        }
        local_11b8 = (HKEY)((ulonglong)local_11b8 & 0xffffffff00000000);
        LVar10 = RegQueryInfoKeyW(hKey_00,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)&local_11b8
                                  ,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                  (LPDWORD)0x0,(PFILETIME)0x0);
        bVar3 = false;
        if (LVar10 == 0) {
          bVar3 = (int)local_11b8 != 0;
        }
        uVar21 = 0;
        if (hKey_00 != (HKEY)0x0) {
          uVar21 = RegCloseKey(hKey_00);
          local_11a0 = (HKEY)0x0;
          hKey_00 = (HKEY)0x0;
        }
        local_1198 = 0;
        if (uVar21 != 0) goto LAB_180005ca1;
        if ((bVar4) && (!bVar3)) {
          if (DAT_1800534e8 == '\0') {
            pHVar17 = GetModuleHandleA("Advapi32.dll");
            if (pHVar17 == (HMODULE)0x0) {
              DAT_1800534e8 = '\x01';
            }
            else {
              DAT_1800534e0 = GetProcAddress(pHVar17,"RegDeleteKeyExA");
              DAT_1800534e8 = '\x01';
            }
          }
          if (DAT_1800534e0 == (FARPROC)0x0) {
            uVar21 = RegDeleteKeyA(local_11b0,(LPCSTR)local_1168);
          }
          else {
            IVar19 = (*DAT_1800534e0)();
            uVar21 = (uint)IVar19;
          }
          if (uVar21 != 0) goto LAB_180005ca1;
        }
      }
      goto LAB_180004e83;
    }
    pCVar25 = local_1058;
    while( true ) {
      pbVar27 = (byte *)*param_1;
      bVar1 = *pbVar27;
      uVar21 = (uint)(char)bVar1;
      if ((((uVar21 != 9) && (uVar21 != 10)) && (uVar21 != 0xd)) && (uVar21 != 0x20)) break;
      pCVar12 = CharNextA((LPCSTR)pbVar27);
      *param_1 = pCVar12;
    }
    if (bVar1 == 0) goto LAB_180005cac;
    if (bVar1 == 0x27) {
      pCVar12 = CharNextA((LPCSTR)pbVar27);
      *param_1 = pCVar12;
      cVar20 = *pCVar12;
      while ((cVar20 != '\0' &&
             ((*(LPCSTR)*param_1 != '\'' ||
              (pCVar12 = CharNextA((LPCSTR)*param_1), *pCVar12 == '\''))))) {
        pCVar14 = (LPCSTR)*param_1;
        if (*pCVar14 == '\'') {
          pCVar14 = CharNextA(pCVar14);
          *param_1 = pCVar14;
        }
        pCVar12 = CharNextA(pCVar14);
        *param_1 = pCVar12;
        uVar11 = (longlong)pCVar12 - (longlong)pCVar14;
        if (local_58 <= pCVar25 + uVar11 + 1) goto LAB_180005cac;
        if (0 < (int)uVar11) {
          lVar26 = (longlong)pCVar14 - (longlong)pCVar25;
          uVar11 = uVar11 & 0xffffffff;
          do {
            *pCVar25 = pCVar25[lVar26];
            pCVar25 = pCVar25 + 1;
            uVar11 = uVar11 - 1;
          } while (uVar11 != 0);
        }
        cVar20 = *pCVar12;
      }
      pCVar14 = (LPCSTR)*param_1;
      if (*pCVar14 == '\0') goto LAB_180005cac;
      *pCVar25 = '\0';
      pCVar12 = CharNextA(pCVar14);
      *param_1 = pCVar12;
    }
    else {
      do {
        cVar20 = (char)uVar21;
        if (((cVar20 == '\t') || (cVar20 == '\n')) || ((cVar20 == '\r' || (cVar20 == ' ')))) break;
        pbVar16 = (byte *)CharNextA((LPCSTR)pbVar27);
        *param_1 = pbVar16;
        uVar11 = (longlong)pbVar16 - (longlong)pbVar27;
        if (local_58 <= pCVar25 + uVar11 + 1) goto LAB_180005cac;
        if (0 < (int)uVar11) {
          lVar26 = (longlong)pbVar27 - (longlong)pCVar25;
          uVar11 = uVar11 & 0xffffffff;
          do {
            *pCVar25 = pCVar25[lVar26];
            pCVar25 = pCVar25 + 1;
            uVar11 = uVar11 - 1;
          } while (uVar11 != 0);
        }
        uVar21 = (uint)*pbVar16;
        pbVar27 = pbVar16;
      } while (*pbVar16 != 0);
      *pCVar25 = '\0';
    }
    while( true ) {
      pbVar27 = (byte *)*param_1;
      bVar1 = *pbVar27;
      uVar21 = (uint)(char)bVar1;
      if ((((uVar21 != 9) && (uVar21 != 10)) && (uVar21 != 0xd)) && (uVar21 != 0x20)) break;
      pCVar12 = CharNextA((LPCSTR)pbVar27);
      *param_1 = pCVar12;
    }
    if (bVar1 == 0) goto LAB_180005cac;
    puVar23 = param_2;
    if (bVar1 == 0x27) {
      pcVar13 = CharNextA((LPCSTR)pbVar27);
      *param_1 = pcVar13;
      cVar20 = *pcVar13;
      while ((cVar20 != '\0' &&
             ((*pcVar13 != '\'' || (pCVar12 = CharNextA(pcVar13), *pCVar12 == '\''))))) {
        pCVar14 = (LPCSTR)*param_1;
        if (*pCVar14 == '\'') {
          pCVar14 = CharNextA(pCVar14);
          *param_1 = pCVar14;
        }
        pCVar12 = CharNextA(pCVar14);
        *param_1 = pCVar12;
        uVar11 = (longlong)pCVar12 - (longlong)pCVar14;
        if (param_2 + 0x1000 <= puVar23 + uVar11 + 1) goto LAB_180005cac;
        if (0 < (int)uVar11) {
          lVar26 = (longlong)pCVar14 - (longlong)puVar23;
          uVar11 = uVar11 & 0xffffffff;
          do {
            *puVar23 = puVar23[lVar26];
            puVar23 = puVar23 + 1;
            uVar11 = uVar11 - 1;
          } while (uVar11 != 0);
        }
        pcVar13 = (char *)*param_1;
        cVar20 = *pcVar13;
      }
      if (*(char *)*param_1 == '\0') goto LAB_180005cac;
      *puVar23 = '\0';
      pCVar12 = CharNextA((LPCSTR)*param_1);
      *param_1 = pCVar12;
    }
    else {
      do {
        cVar20 = (char)uVar21;
        if (((cVar20 == '\t') || (cVar20 == '\n')) || ((cVar20 == '\r' || (cVar20 == ' ')))) break;
        pCVar12 = CharNextA((LPCSTR)pbVar27);
        *param_1 = pCVar12;
        uVar11 = (longlong)pCVar12 - (longlong)pbVar27;
        if (param_2 + 0x1000 <= puVar23 + uVar11 + 1) goto LAB_180005cac;
        if (0 < (int)uVar11) {
          lVar26 = (longlong)pbVar27 - (longlong)puVar23;
          uVar11 = uVar11 & 0xffffffff;
          do {
            *puVar23 = puVar23[lVar26];
            puVar23 = puVar23 + 1;
            uVar11 = uVar11 - 1;
          } while (uVar11 != 0);
        }
        pbVar27 = (byte *)*param_1;
        uVar21 = (uint)*pbVar27;
      } while (*pbVar27 != 0);
      *puVar23 = '\0';
    }
    iVar7 = local_11a8;
    if (*param_2 != '=') goto LAB_180005cac;
    if (local_11a8 != 0) {
      local_1180 = local_11b0;
      local_1178 = 0;
      local_1170 = 0;
      uVar15 = FUN_180002410(param_1,&local_1180,local_1058,param_2);
      iVar6 = (int)uVar15;
      goto joined_r0x0001800050d6;
    }
    if ((param_5 == 0) && (bVar4)) {
      local_11b8 = (HKEY)0x0;
      uVar21 = RegOpenKeyExA(local_11b0,(LPCSTR)0x0,0,0x20006,&local_11b8);
      hKey = local_11b8;
      if (uVar21 != 0) {
LAB_180005ca1:
        uVar21 = FUN_180002cb0(uVar21);
        uVar15 = (ulonglong)uVar21;
        goto LAB_180005cb1;
      }
      uVar21 = RegDeleteValueA(local_11b8,local_1058);
      if ((uVar21 & 0xfffffffd) != 0) {
        uVar21 = FUN_180002cb0(uVar21);
        uVar15 = (ulonglong)uVar21;
        if (hKey != (HKEY)0x0) {
          RegCloseKey(hKey);
        }
        goto LAB_180005cb1;
      }
      if (hKey != (HKEY)0x0) {
        RegCloseKey(hKey);
      }
    }
    uVar11 = FUN_180005d60(param_1,(char *)param_2);
  } while( true );
}

/* RVA 0x5cf0 */
undefined4 FUN_180005cf0(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  
  plVar1 = param_1 + 3;
  *(int *)plVar1 = (int)*plVar1 + -1;
  lVar2 = param_1[3];
  if ((int)*plVar1 == 0) {
    (**(code **)(*DAT_1800534d0 + 8))();
    if (param_1 != (longlong *)0x0) {
      (**(code **)(*param_1 + 0x160))(param_1,1);
    }
    (**(code **)(*DAT_1800534d0 + 0x10))();
  }
  return (int)lVar2;
}

/* RVA 0x5d48 */
void FUN_180005d48(longlong param_1)

{
  FUN_180005cf0((longlong *)(param_1 + -8));
  return;
}

/* RVA 0x5d54 */
void FUN_180005d54(longlong param_1)

{
  FUN_180005cf0((longlong *)(param_1 + -0x10));
  return;
}

/* RVA 0x5d60 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180005d60(undefined8 *param_1,char *param_2)

{
  char cVar1;
  ulonglong uVar2;
  LPSTR pCVar3;
  undefined8 uVar4;
  uint uVar5;
  undefined1 auStack_1038 [32];
  undefined1 local_1018 [4096];
  ulonglong local_18;
  undefined8 uStack_10;
  
  uStack_10 = 0x180005d70;
  local_18 = DAT_180052888 ^ (ulonglong)auStack_1038;
  if (*param_2 == '=') {
    uVar2 = FUN_180003db0(param_1,param_2);
    if (-1 < (int)uVar2) {
      while( true ) {
        cVar1 = *(LPCSTR)*param_1;
        if ((((cVar1 != '\t') && (cVar1 != '\n')) && (cVar1 != '\r')) && (cVar1 != ' ')) break;
        pCVar3 = CharNextA((LPCSTR)*param_1);
        *param_1 = pCVar3;
      }
      uVar2 = FUN_180003db0(param_1,local_1018);
      if (-1 < (int)uVar2) {
        uVar4 = FUN_180003db0(param_1,param_2);
        uVar5 = 0;
        if ((int)(uint)uVar4 < 0) {
          uVar5 = (uint)uVar4;
        }
        uVar2 = (ulonglong)uVar5;
      }
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* RVA 0x5e20 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

DWORD FUN_180005e20(longlong *param_1,undefined4 param_2,int param_3,undefined8 *param_4)

{
  char *pcVar1;
  WCHAR WVar2;
  void *pvVar3;
  undefined8 *puVar4;
  size_t _Size;
  HMODULE pHVar5;
  DWORD DVar6;
  uint uVar7;
  longlong lVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  HMODULE pHVar11;
  int *piVar12;
  undefined8 *puVar13;
  WCHAR *pWVar14;
  WCHAR *pWVar15;
  longlong lVar16;
  undefined8 *_Memory;
  undefined1 *puVar17;
  ulonglong uVar18;
  LPCSTR pCVar19;
  int iVar20;
  LPCWSTR pWVar21;
  LPCWSTR pWVar22;
  LPCSTR pCVar23;
  undefined1 auStack_9f8 [64];
  undefined **local_9b8;
  void *local_9b0;
  void *pvStack_9a8;
  int local_9a0;
  undefined4 local_990;
  CHAR local_988;
  char acStack_987 [271];
  WCHAR local_878;
  short local_876 [527];
  WCHAR local_458 [520];
  ulonglong local_48;
  
  puVar17 = auStack_9f8;
  local_48 = DAT_180052888 ^ (ulonglong)&local_9b8;
  local_9b8 = ATL::CRegObject::vftable;
  local_9b0 = (void *)0x0;
  pvStack_9a8 = (void *)0x0;
  local_9a0 = 0;
  local_990 = param_2;
  if (param_4 != (undefined8 *)0x0) {
    pWVar21 = (LPCWSTR)*param_4;
    while (pWVar21 != (LPCWSTR)0x0) {
      FUN_180001f90((longlong)&local_9b8,pWVar21,(void *)param_4[1]);
      param_4 = param_4 + 2;
      pWVar21 = (LPCWSTR)*param_4;
    }
  }
  DVar6 = (**(code **)(*param_1 + 0x28))(param_1,&local_9b8);
  pHVar5 = DAT_1800547c8;
  if ((int)DVar6 < 0) {
    local_9b8 = ATL::CRegObject::vftable;
    iVar20 = 0;
    if (0 < local_9a0) {
      lVar16 = 0;
      do {
        if (((lVar16 < 0) || (local_9a0 <= iVar20)) ||
           (operator_delete__(*(void **)((longlong)local_9b0 + lVar16)), local_9a0 <= iVar20)) {
                    /* WARNING: Subroutine does not return */
          FUN_1800018d0(-0x7ffffff5);
        }
        operator_delete__(*(void **)((longlong)pvStack_9a8 + lVar16));
        iVar20 = iVar20 + 1;
        lVar16 = lVar16 + 8;
      } while (iVar20 < local_9a0);
    }
    if (local_9b0 != (void *)0x0) {
      free(local_9b0);
      local_9b0 = (void *)0x0;
    }
    if (pvStack_9a8 != (void *)0x0) {
      free(pvStack_9a8);
      pvStack_9a8 = (void *)0x0;
    }
    local_9a0 = 0;
    if (local_9b0 != (void *)0x0) {
      free(local_9b0);
      local_9b0 = (void *)0x0;
    }
    if (pvStack_9a8 != (void *)0x0) {
      free(pvStack_9a8);
      pvStack_9a8 = (void *)0x0;
    }
    local_9a0 = 0;
    if (local_9b0 != (void *)0x0) {
      free(local_9b0);
      local_9b0 = (void *)0x0;
    }
    if (pvStack_9a8 != (void *)0x0) {
      free(pvStack_9a8);
    }
    puVar17 = auStack_9f8;
    goto LAB_180006aa4;
  }
  _Memory = (undefined8 *)0x0;
  DVar6 = GetModuleFileNameA(DAT_1800547c8,&local_988,0x104);
  if (DVar6 == 0) {
    DVar6 = FUN_180002c90();
    local_9b8 = ATL::CRegObject::vftable;
    iVar20 = 0;
    if (0 < local_9a0) {
      do {
        if ((((longlong)_Memory < 0) || (local_9a0 <= iVar20)) ||
           (operator_delete__(*(void **)((longlong)local_9b0 + (longlong)_Memory)),
           local_9a0 <= iVar20)) {
                    /* WARNING: Subroutine does not return */
          FUN_1800018d0(-0x7ffffff5);
        }
        operator_delete__(*(void **)((longlong)pvStack_9a8 + (longlong)_Memory));
        iVar20 = iVar20 + 1;
        _Memory = _Memory + 1;
      } while (iVar20 < local_9a0);
    }
    if (local_9b0 != (void *)0x0) {
      free(local_9b0);
      local_9b0 = (void *)0x0;
    }
    if (pvStack_9a8 != (void *)0x0) {
      free(pvStack_9a8);
      pvStack_9a8 = (void *)0x0;
    }
    local_9a0 = 0;
    if (local_9b0 != (void *)0x0) {
      free(local_9b0);
      local_9b0 = (void *)0x0;
    }
    if (pvStack_9a8 != (void *)0x0) {
      free(pvStack_9a8);
      pvStack_9a8 = (void *)0x0;
    }
    local_9a0 = 0;
    if (local_9b0 != (void *)0x0) {
      free(local_9b0);
      local_9b0 = (void *)0x0;
    }
    if (pvStack_9a8 != (void *)0x0) {
      free(pvStack_9a8);
    }
    puVar17 = auStack_9f8;
    goto LAB_180006aa4;
  }
  if (DVar6 == 0x104) {
    local_9b8 = ATL::CRegObject::vftable;
    iVar20 = 0;
    if (0 < local_9a0) {
      lVar16 = 0;
      do {
        if (((lVar16 < 0) || (local_9a0 <= iVar20)) ||
           (operator_delete__(*(void **)((longlong)local_9b0 + lVar16)), local_9a0 <= iVar20)) {
                    /* WARNING: Subroutine does not return */
          FUN_1800018d0(-0x7ffffff5);
        }
        operator_delete__(*(void **)((longlong)pvStack_9a8 + lVar16));
        iVar20 = iVar20 + 1;
        lVar16 = lVar16 + 8;
      } while (iVar20 < local_9a0);
    }
    if (local_9b0 != (void *)0x0) {
      free(local_9b0);
      local_9b0 = (void *)0x0;
    }
    if (pvStack_9a8 != (void *)0x0) {
      free(pvStack_9a8);
      pvStack_9a8 = (void *)0x0;
    }
    local_9a0 = 0;
    if (local_9b0 != (void *)0x0) {
      free(local_9b0);
      local_9b0 = (void *)0x0;
    }
    if (pvStack_9a8 != (void *)0x0) {
      free(pvStack_9a8);
      pvStack_9a8 = (void *)0x0;
    }
    local_9a0 = 0;
    if (local_9b0 != (void *)0x0) {
      free(local_9b0);
      local_9b0 = (void *)0x0;
    }
    if (pvStack_9a8 != (void *)0x0) {
      free(pvStack_9a8);
    }
    DVar6 = 0x8007007a;
    goto LAB_180006aa4;
  }
  lVar16 = -1;
  do {
    lVar8 = lVar16 + 1;
    pcVar1 = acStack_987 + lVar16;
    lVar16 = lVar8;
  } while (*pcVar1 != '\0');
  lVar16 = (longlong)((int)lVar8 + 1) * 2;
  puVar17 = auStack_9f8;
  if (lVar16 + 0x80000000U < 0x100000000) {
    iVar20 = (int)lVar16;
    uVar18 = (ulonglong)iVar20;
    if ((iVar20 < 0x401) && (uVar9 = FUN_180006b40(uVar18), (char)uVar9 != '\0')) {
      uVar10 = uVar18 + 0xf;
      if (uVar10 <= uVar18) {
        uVar10 = 0xffffffffffffff0;
      }
      pWVar21 = (LPCWSTR)(auStack_9f8 + -(uVar10 & 0xfffffffffffffff0) + 0x40);
      puVar17 = auStack_9f8 + -(uVar10 & 0xfffffffffffffff0);
    }
    else {
      if (~uVar18 < 0x10) {
                    /* WARNING: Subroutine does not return */
        FUN_1800018d0(-0x7ff8fdea);
      }
      _Memory = malloc(uVar18 + 0x10);
      puVar17 = auStack_9f8;
      if (_Memory == (undefined8 *)0x0) goto LAB_1800069c1;
      *_Memory = 0;
      pWVar21 = (LPCWSTR)(_Memory + 2);
      puVar17 = auStack_9f8;
    }
    if (pWVar21 != (LPCWSTR)0x0) {
      *pWVar21 = L'\0';
      *(int *)(puVar17 + 0x28) = (int)(uVar18 >> 1);
      *(LPCWSTR *)(puVar17 + 0x20) = pWVar21;
      *(undefined8 *)(puVar17 + -8) = 0x180006271;
      iVar20 = MultiByteToWideChar(0,0,&local_988,-1,*(LPWSTR *)(puVar17 + 0x20),
                                   *(int *)(puVar17 + 0x28));
      if (iVar20 != 0) {
        uVar7 = 0;
        pWVar14 = local_458;
        pWVar22 = pWVar21;
        do {
          WVar2 = *pWVar22;
          pWVar15 = pWVar14;
          if (WVar2 == L'\0') break;
          *pWVar14 = WVar2;
          pWVar15 = pWVar14 + 1;
          if ((WVar2 == L'\'') && (uVar7 = uVar7 + 1, uVar7 < 0x207)) {
            *pWVar15 = L'\'';
            pWVar15 = pWVar14 + 2;
          }
          pWVar22 = pWVar22 + 1;
          uVar7 = uVar7 + 1;
          pWVar14 = pWVar15;
        } while (uVar7 < 0x207);
        *pWVar15 = L'\0';
        if (pHVar5 == (HMODULE)0x0) {
LAB_1800062df:
          local_878 = L'\"';
          lVar16 = -1;
          do {
            lVar16 = lVar16 + 1;
          } while (local_458[lVar16] != L'\0');
          _Size = (longlong)((int)lVar16 + 1) * 2;
          if (_Size != 0) {
            if (0x416 < _Size) {
              *(undefined8 *)(puVar17 + -8) = 0x1800064a1;
              memset(local_876,0,0x416);
              *(undefined8 *)(puVar17 + -8) = 0x1800064a7;
              piVar12 = _errno();
              *piVar12 = 0x22;
              *(undefined8 *)(puVar17 + -8) = 0x1800064af;
              _invalid_parameter_noinfo();
              while (_Memory != (undefined8 *)0x0) {
                puVar13 = (undefined8 *)*_Memory;
                *(undefined8 *)(puVar17 + -8) = 0x1800064c0;
                free(_Memory);
                _Memory = puVar13;
              }
              local_9b8 = ATL::CRegObject::vftable;
              iVar20 = 0;
              if (0 < local_9a0) {
                lVar16 = 0;
                do {
                  if ((lVar16 < 0) || (local_9a0 <= iVar20)) {
LAB_180006b0a:
                    /* WARNING: Subroutine does not return */
                    *(undefined8 *)(puVar17 + -8) = 0x180006b14;
                    FUN_1800018d0(-0x7ffffff5);
                  }
                  pvVar3 = *(void **)((longlong)local_9b0 + lVar16);
                  *(undefined8 *)(puVar17 + -8) = 0x1800064fe;
                  operator_delete__(pvVar3);
                  if (local_9a0 <= iVar20) goto LAB_180006b0a;
                  pvVar3 = *(void **)((longlong)pvStack_9a8 + lVar16);
                  *(undefined8 *)(puVar17 + -8) = 0x180006514;
                  operator_delete__(pvVar3);
                  iVar20 = iVar20 + 1;
                  lVar16 = lVar16 + 8;
                } while (iVar20 < local_9a0);
              }
              pvVar3 = local_9b0;
              if (local_9b0 != (void *)0x0) {
                *(undefined8 *)(puVar17 + -8) = 0x180006530;
                free(pvVar3);
                local_9b0 = (void *)0x0;
              }
              pvVar3 = pvStack_9a8;
              if (pvStack_9a8 != (void *)0x0) {
                *(undefined8 *)(puVar17 + -8) = 0x180006549;
                free(pvVar3);
                pvStack_9a8 = (void *)0x0;
              }
              pvVar3 = local_9b0;
              local_9a0 = 0;
              if (local_9b0 != (void *)0x0) {
                *(undefined8 *)(puVar17 + -8) = 0x180006563;
                free(pvVar3);
                local_9b0 = (void *)0x0;
              }
              pvVar3 = pvStack_9a8;
              if (pvStack_9a8 != (void *)0x0) {
                *(undefined8 *)(puVar17 + -8) = 0x18000657c;
                free(pvVar3);
                pvStack_9a8 = (void *)0x0;
              }
              pvVar3 = local_9b0;
              local_9a0 = 0;
              if (local_9b0 != (void *)0x0) {
                *(undefined8 *)(puVar17 + -8) = 0x180006596;
                free(pvVar3);
                local_9b0 = (void *)0x0;
              }
              pvVar3 = pvStack_9a8;
              if (pvStack_9a8 != (void *)0x0) {
                *(undefined8 *)(puVar17 + -8) = 0x1800065ac;
                free(pvVar3);
              }
              DVar6 = 0x80004005;
              goto LAB_180006aa4;
            }
            *(undefined8 *)(puVar17 + -8) = 0x180006328;
            memcpy(local_876,local_458,_Size);
          }
          lVar16 = -1;
          do {
            lVar16 = lVar16 + 1;
          } while ((&local_878)[lVar16] != L'\0');
          lVar16 = (longlong)(int)lVar16;
          (&local_878)[lVar16] = L'\"';
          if (0x417 < lVar16 * 2 + 2U) {
            *(undefined8 *)(puVar17 + -8) = 0x180006ad2;
            FUN_180035758();
LAB_180006ad3:
                    /* WARNING: Subroutine does not return */
            *(undefined8 *)(puVar17 + -8) = 0x180006add;
            FUN_1800018d0(-0x7ffffff5);
          }
          local_876[lVar16] = 0;
          pWVar14 = &local_878;
        }
        else {
          *(undefined8 *)(puVar17 + -8) = 0x1800062ce;
          pHVar11 = GetModuleHandleA((LPCSTR)0x0);
          if (pHVar5 == pHVar11) goto LAB_1800062df;
          pWVar14 = local_458;
        }
        *(undefined8 *)(puVar17 + -8) = 0x18000637e;
        DVar6 = FUN_180001f90((longlong)&local_9b8,L"Module",pWVar14);
        if ((int)DVar6 < 0) {
          while (_Memory != (undefined8 *)0x0) {
            puVar13 = (undefined8 *)*_Memory;
            *(undefined8 *)(puVar17 + -8) = 0x18000639c;
            free(_Memory);
            _Memory = puVar13;
          }
          local_9b8 = ATL::CRegObject::vftable;
          iVar20 = 0;
          if (0 < local_9a0) {
            lVar16 = 0;
            do {
              if ((lVar16 < 0) || (local_9a0 <= iVar20)) {
LAB_180006b15:
                    /* WARNING: Subroutine does not return */
                *(undefined8 *)(puVar17 + -8) = 0x180006b1f;
                FUN_1800018d0(-0x7ffffff5);
              }
              pvVar3 = *(void **)((longlong)local_9b0 + lVar16);
              *(undefined8 *)(puVar17 + -8) = 0x1800063de;
              operator_delete__(pvVar3);
              if (local_9a0 <= iVar20) goto LAB_180006b15;
              pvVar3 = *(void **)((longlong)pvStack_9a8 + lVar16);
              *(undefined8 *)(puVar17 + -8) = 0x1800063f4;
              operator_delete__(pvVar3);
              iVar20 = iVar20 + 1;
              lVar16 = lVar16 + 8;
            } while (iVar20 < local_9a0);
          }
          pvVar3 = local_9b0;
          if (local_9b0 != (void *)0x0) {
            *(undefined8 *)(puVar17 + -8) = 0x180006410;
            free(pvVar3);
            local_9b0 = (void *)0x0;
          }
          pvVar3 = pvStack_9a8;
          if (pvStack_9a8 != (void *)0x0) {
            *(undefined8 *)(puVar17 + -8) = 0x180006429;
            free(pvVar3);
            pvStack_9a8 = (void *)0x0;
          }
          pvVar3 = local_9b0;
          local_9a0 = 0;
          if (local_9b0 != (void *)0x0) {
            *(undefined8 *)(puVar17 + -8) = 0x180006443;
            free(pvVar3);
            local_9b0 = (void *)0x0;
          }
          pvVar3 = pvStack_9a8;
          if (pvStack_9a8 != (void *)0x0) {
            *(undefined8 *)(puVar17 + -8) = 0x18000645c;
            free(pvVar3);
            pvStack_9a8 = (void *)0x0;
          }
          pvVar3 = local_9b0;
          local_9a0 = 0;
          if (local_9b0 != (void *)0x0) {
            *(undefined8 *)(puVar17 + -8) = 0x180006476;
            free(pvVar3);
            local_9b0 = (void *)0x0;
          }
          pvVar3 = pvStack_9a8;
          if (pvStack_9a8 != (void *)0x0) {
            *(undefined8 *)(puVar17 + -8) = 0x18000648c;
            free(pvVar3);
          }
          goto LAB_180006aa4;
        }
        *(undefined8 *)(puVar17 + -8) = 0x1800065ce;
        DVar6 = FUN_180001f90((longlong)&local_9b8,L"Module_Raw",local_458);
        if ((int)DVar6 < 0) {
          while (_Memory != (undefined8 *)0x0) {
            puVar13 = (undefined8 *)*_Memory;
            *(undefined8 *)(puVar17 + -8) = 0x1800065ec;
            free(_Memory);
            _Memory = puVar13;
          }
          local_9b8 = ATL::CRegObject::vftable;
          iVar20 = 0;
          if (0 < local_9a0) {
            lVar16 = 0;
            do {
              if ((lVar16 < 0) || (local_9a0 <= iVar20)) {
LAB_180006b20:
                    /* WARNING: Subroutine does not return */
                *(undefined8 *)(puVar17 + -8) = 0x180006b2a;
                FUN_1800018d0(-0x7ffffff5);
              }
              pvVar3 = *(void **)((longlong)local_9b0 + lVar16);
              *(undefined8 *)(puVar17 + -8) = 0x18000662e;
              operator_delete__(pvVar3);
              if (local_9a0 <= iVar20) goto LAB_180006b20;
              pvVar3 = *(void **)((longlong)pvStack_9a8 + lVar16);
              *(undefined8 *)(puVar17 + -8) = 0x180006644;
              operator_delete__(pvVar3);
              iVar20 = iVar20 + 1;
              lVar16 = lVar16 + 8;
            } while (iVar20 < local_9a0);
          }
          pvVar3 = local_9b0;
          if (local_9b0 != (void *)0x0) {
            *(undefined8 *)(puVar17 + -8) = 0x180006660;
            free(pvVar3);
            local_9b0 = (void *)0x0;
          }
          pvVar3 = pvStack_9a8;
          if (pvStack_9a8 != (void *)0x0) {
            *(undefined8 *)(puVar17 + -8) = 0x180006679;
            free(pvVar3);
            pvStack_9a8 = (void *)0x0;
          }
          pvVar3 = local_9b0;
          local_9a0 = 0;
          if (local_9b0 != (void *)0x0) {
            *(undefined8 *)(puVar17 + -8) = 0x180006693;
            free(pvVar3);
            local_9b0 = (void *)0x0;
          }
          pvVar3 = pvStack_9a8;
          if (pvStack_9a8 != (void *)0x0) {
            *(undefined8 *)(puVar17 + -8) = 0x1800066ac;
            free(pvVar3);
            pvStack_9a8 = (void *)0x0;
          }
          pvVar3 = local_9b0;
          local_9a0 = 0;
          if (local_9b0 != (void *)0x0) {
            *(undefined8 *)(puVar17 + -8) = 0x1800066c6;
            free(pvVar3);
            local_9b0 = (void *)0x0;
          }
          pvVar3 = pvStack_9a8;
          if (pvStack_9a8 != (void *)0x0) {
            *(undefined8 *)(puVar17 + -8) = 0x1800066dc;
            free(pvVar3);
          }
          goto LAB_180006aa4;
        }
        if (param_3 == 0) {
          puVar13 = (undefined8 *)0x0;
          *(undefined8 *)(puVar17 + -8) = 0x1800067d1;
          uVar9 = FUN_180006b40(0x12);
          if ((char)uVar9 == '\0') {
            *(undefined8 *)(puVar17 + -8) = 0x1800067f0;
            puVar13 = malloc(0x22);
            if (puVar13 == (undefined8 *)0x0) goto LAB_180006891;
            *puVar13 = 0;
            pCVar19 = (LPCSTR)(puVar13 + 2);
          }
          else {
            pCVar19 = puVar17 + 0x20;
            puVar17 = puVar17 + -0x20;
          }
          if (pCVar19 == (LPCSTR)0x0) {
joined_r0x000180006876:
            while (puVar13 != (undefined8 *)0x0) {
              puVar4 = (undefined8 *)*puVar13;
              *(undefined8 *)(puVar17 + -8) = 0x18000688c;
              free(puVar13);
              puVar13 = puVar4;
            }
            goto LAB_180006891;
          }
          *pCVar19 = '\0';
          *(undefined8 *)(puVar17 + 0x38) = 0;
          *(undefined8 *)(puVar17 + 0x30) = 0;
          *(undefined4 *)(puVar17 + 0x28) = 0x12;
          *(LPCSTR *)(puVar17 + 0x20) = pCVar19;
          *(undefined8 *)(puVar17 + -8) = 0x180006839;
          iVar20 = WideCharToMultiByte(0,0,L"REGISTRY",-1,*(LPSTR *)(puVar17 + 0x20),
                                       *(int *)(puVar17 + 0x28),*(LPCSTR *)(puVar17 + 0x30),
                                       *(LPBOOL *)(puVar17 + 0x38));
          if (iVar20 == 0) goto joined_r0x000180006876;
          pCVar23 = (LPCSTR)(ulonglong)(ushort)local_990;
          *(undefined4 *)(puVar17 + 0x20) = 0;
          *(undefined8 *)(puVar17 + -8) = 0x180006856;
          DVar6 = FUN_180004b00(&local_9b8,pWVar21,pCVar23,pCVar19,*(int *)(puVar17 + 0x20));
          while (puVar13 != (undefined8 *)0x0) {
            puVar4 = (undefined8 *)*puVar13;
            *(undefined8 *)(puVar17 + -8) = 0x18000686c;
            free(puVar13);
            puVar13 = puVar4;
          }
        }
        else {
          puVar13 = (undefined8 *)0x0;
          *(undefined8 *)(puVar17 + -8) = 0x1800066fd;
          uVar9 = FUN_180006b40(0x12);
          if ((char)uVar9 == '\0') {
            *(undefined8 *)(puVar17 + -8) = 0x18000671c;
            puVar13 = malloc(0x22);
            if (puVar13 == (undefined8 *)0x0) goto LAB_180006891;
            *puVar13 = 0;
            pCVar19 = (LPCSTR)(puVar13 + 2);
          }
          else {
            pCVar19 = puVar17 + 0x20;
            puVar17 = puVar17 + -0x20;
          }
          if (pCVar19 != (LPCSTR)0x0) {
            *pCVar19 = '\0';
            *(undefined8 *)(puVar17 + 0x38) = 0;
            *(undefined8 *)(puVar17 + 0x30) = 0;
            *(undefined4 *)(puVar17 + 0x28) = 0x12;
            *(LPCSTR *)(puVar17 + 0x20) = pCVar19;
            *(undefined8 *)(puVar17 + -8) = 0x180006765;
            iVar20 = WideCharToMultiByte(0,0,L"REGISTRY",-1,*(LPSTR *)(puVar17 + 0x20),
                                         *(int *)(puVar17 + 0x28),*(LPCSTR *)(puVar17 + 0x30),
                                         *(LPBOOL *)(puVar17 + 0x38));
            if (iVar20 != 0) {
              pCVar23 = (LPCSTR)(ulonglong)(ushort)local_990;
              *(undefined4 *)(puVar17 + 0x20) = 1;
              *(undefined8 *)(puVar17 + -8) = 0x180006785;
              DVar6 = FUN_180004b00(&local_9b8,pWVar21,pCVar23,pCVar19,*(int *)(puVar17 + 0x20));
              while (puVar13 != (undefined8 *)0x0) {
                puVar4 = (undefined8 *)*puVar13;
                *(undefined8 *)(puVar17 + -8) = 0x18000679c;
                free(puVar13);
                puVar13 = puVar4;
              }
              goto LAB_180006896;
            }
          }
          while (puVar13 != (undefined8 *)0x0) {
            puVar4 = (undefined8 *)*puVar13;
            *(undefined8 *)(puVar17 + -8) = 0x1800067bc;
            free(puVar13);
            puVar13 = puVar4;
          }
LAB_180006891:
          DVar6 = 0x8007000e;
        }
LAB_180006896:
        uVar18 = 0;
        while (_Memory != (undefined8 *)0x0) {
          puVar13 = (undefined8 *)*_Memory;
          *(undefined8 *)(puVar17 + -8) = 0x1800068ac;
          free(_Memory);
          _Memory = puVar13;
        }
        local_9b8 = ATL::CRegObject::vftable;
        if (0 < local_9a0) {
          uVar10 = uVar18;
          do {
            if (((longlong)uVar18 < 0) || (iVar20 = (int)uVar10, local_9a0 <= iVar20)) {
LAB_180006b2b:
                    /* WARNING: Subroutine does not return */
              *(undefined **)(puVar17 + -8) = &UNK_180006b35;
              FUN_1800018d0(-0x7ffffff5);
            }
            pvVar3 = *(void **)((longlong)local_9b0 + uVar18);
            *(undefined8 *)(puVar17 + -8) = 0x1800068ee;
            operator_delete__(pvVar3);
            if (local_9a0 <= iVar20) goto LAB_180006b2b;
            pvVar3 = *(void **)((longlong)pvStack_9a8 + uVar18);
            *(undefined8 *)(puVar17 + -8) = 0x180006904;
            operator_delete__(pvVar3);
            uVar10 = (ulonglong)(iVar20 + 1U);
            uVar18 = uVar18 + 8;
          } while ((int)(iVar20 + 1U) < local_9a0);
        }
        pvVar3 = local_9b0;
        if (local_9b0 != (void *)0x0) {
          *(undefined8 *)(puVar17 + -8) = 0x180006920;
          free(pvVar3);
          local_9b0 = (void *)0x0;
        }
        pvVar3 = pvStack_9a8;
        if (pvStack_9a8 != (void *)0x0) {
          *(undefined8 *)(puVar17 + -8) = 0x180006939;
          free(pvVar3);
          pvStack_9a8 = (void *)0x0;
        }
        pvVar3 = local_9b0;
        local_9a0 = 0;
        if (local_9b0 != (void *)0x0) {
          *(undefined8 *)(puVar17 + -8) = 0x180006953;
          free(pvVar3);
          local_9b0 = (void *)0x0;
        }
        pvVar3 = pvStack_9a8;
        if (pvStack_9a8 != (void *)0x0) {
          *(undefined8 *)(puVar17 + -8) = 0x18000696c;
          free(pvVar3);
          pvStack_9a8 = (void *)0x0;
        }
        pvVar3 = local_9b0;
        local_9a0 = 0;
        if (local_9b0 != (void *)0x0) {
          *(undefined8 *)(puVar17 + -8) = 0x180006986;
          free(pvVar3);
          local_9b0 = (void *)0x0;
        }
        pvVar3 = pvStack_9a8;
        if (pvStack_9a8 != (void *)0x0) {
          *(undefined8 *)(puVar17 + -8) = 0x18000699c;
          free(pvVar3);
        }
        goto LAB_180006aa4;
      }
    }
    while (_Memory != (undefined8 *)0x0) {
      puVar13 = (undefined8 *)*_Memory;
      *(undefined8 *)(puVar17 + -8) = 0x1800069bc;
      free(_Memory);
      _Memory = puVar13;
    }
  }
LAB_1800069c1:
  local_9b8 = ATL::CRegObject::vftable;
  iVar20 = 0;
  if (0 < local_9a0) {
    lVar16 = 0;
    do {
      if ((lVar16 < 0) || (local_9a0 <= iVar20)) goto LAB_180006ad3;
      pvVar3 = *(void **)((longlong)local_9b0 + lVar16);
      *(undefined8 *)(puVar17 + -8) = 0x1800069f0;
      operator_delete__(pvVar3);
      if (local_9a0 <= iVar20) goto LAB_180006ad3;
      pvVar3 = *(void **)((longlong)pvStack_9a8 + lVar16);
      *(undefined8 *)(puVar17 + -8) = 0x180006a06;
      operator_delete__(pvVar3);
      iVar20 = iVar20 + 1;
      lVar16 = lVar16 + 8;
    } while (iVar20 < local_9a0);
  }
  pvVar3 = local_9b0;
  if (local_9b0 != (void *)0x0) {
    *(undefined8 *)(puVar17 + -8) = 0x180006a22;
    free(pvVar3);
    local_9b0 = (void *)0x0;
  }
  pvVar3 = pvStack_9a8;
  if (pvStack_9a8 != (void *)0x0) {
    *(undefined8 *)(puVar17 + -8) = 0x180006a3b;
    free(pvVar3);
    pvStack_9a8 = (void *)0x0;
  }
  pvVar3 = local_9b0;
  local_9a0 = 0;
  if (local_9b0 != (void *)0x0) {
    *(undefined8 *)(puVar17 + -8) = 0x180006a55;
    free(pvVar3);
    local_9b0 = (void *)0x0;
  }
  pvVar3 = pvStack_9a8;
  if (pvStack_9a8 != (void *)0x0) {
    *(undefined8 *)(puVar17 + -8) = 0x180006a6e;
    free(pvVar3);
    pvStack_9a8 = (void *)0x0;
  }
  pvVar3 = local_9b0;
  local_9a0 = 0;
  if (local_9b0 != (void *)0x0) {
    *(undefined8 *)(puVar17 + -8) = 0x180006a88;
    free(pvVar3);
    local_9b0 = (void *)0x0;
  }
  pvVar3 = pvStack_9a8;
  if (pvStack_9a8 != (void *)0x0) {
    *(undefined8 *)(puVar17 + -8) = 0x180006a9e;
    free(pvVar3);
  }
  DVar6 = 0x8007000e;
LAB_180006aa4:
  *(undefined8 *)(puVar17 + -8) = 0x180006ab3;
  return DVar6;
}

