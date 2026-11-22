/* RVA 0x1f210 */
void FUN_18001f210(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  puVar1 = (undefined8 *)FUN_180001cd0();
  __stdio_common_vfprintf(*puVar1,param_1,param_2,0,&local_res18);
  return;
}

/* RVA 0x1f260 */
void FUN_18001f260(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  uVar1 = __acrt_iob_func(1);
  puVar2 = (undefined8 *)FUN_180001cd0();
  __stdio_common_vfprintf(*puVar2,uVar1,param_1,0,&local_res10);
  return;
}

/* RVA 0x1f2c0 */
longlong * FUN_18001f2c0(longlong *param_1,longlong *param_2,void *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  ulonglong uVar3;
  
  uVar3 = 0xffffffffffffffff;
  do {
    uVar3 = uVar3 + 1;
  } while (*(char *)((longlong)param_3 + uVar3) != '\0');
  plVar2 = FUN_180024e40(param_2,param_3,uVar3);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  lVar1 = plVar2[1];
  *param_1 = *plVar2;
  param_1[1] = lVar1;
  lVar1 = plVar2[3];
  param_1[2] = plVar2[2];
  param_1[3] = lVar1;
  plVar2[2] = 0;
  plVar2[3] = 0xf;
  *(undefined1 *)plVar2 = 0;
  return param_1;
}

/* RVA 0x1f330 */
undefined8 * FUN_18001f330(undefined8 *param_1)

{
  void *pvVar1;
  
  *param_1 = CApwnLWDocument::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0xf;
  *(undefined1 *)(param_1 + 8) = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0xf;
  *(undefined1 *)(param_1 + 0xc) = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0xf;
  *(undefined1 *)(param_1 + 0x10) = 0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x14));
  *(undefined4 *)(param_1 + 0x15) = 0;
  *(undefined1 *)((longlong)param_1 + 0xac) = 0;
  param_1[0x16] = 0;
  *(undefined4 *)((longlong)param_1 + 0xbc) = 0;
  *(undefined4 *)((longlong)param_1 + 0xc4) = 0;
  *(undefined1 *)(param_1 + 0x19) = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  pvVar1 = operator_new(0x50);
  *(void **)pvVar1 = pvVar1;
  *(void **)((longlong)pvVar1 + 8) = pvVar1;
  *(void **)((longlong)pvVar1 + 0x10) = pvVar1;
  *(undefined2 *)((longlong)pvVar1 + 0x18) = 0x101;
  param_1[0x1a] = pvVar1;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  pvVar1 = operator_new(0x50);
  *(void **)pvVar1 = pvVar1;
  *(void **)((longlong)pvVar1 + 8) = pvVar1;
  *(void **)((longlong)pvVar1 + 0x10) = pvVar1;
  *(undefined2 *)((longlong)pvVar1 + 0x18) = 0x101;
  param_1[0x1c] = pvVar1;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x1e));
  return param_1;
}

/* RVA 0x1f470 */
void FUN_18001f470(longlong *param_1)

{
  FUN_180007ae0(param_1,param_1,*(longlong **)(*param_1 + 8));
  FUN_180035134((void *)*param_1);
  return;
}

/* RVA 0x1f4a0 */
longlong * FUN_18001f4a0(longlong *param_1,longlong *param_2)

{
  void *pvVar1;
  longlong lVar2;
  void *pvVar3;
  
  if (param_1 != param_2) {
    if (0xf < (ulonglong)param_1[3]) {
      pvVar1 = (void *)*param_1;
      pvVar3 = pvVar1;
      if ((0xfff < param_1[3] + 1U) &&
         (pvVar3 = *(void **)((longlong)pvVar1 + -8),
         0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar3)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      FUN_180035134(pvVar3);
    }
    param_1[3] = 0xf;
    param_1[2] = 0;
    *(undefined1 *)param_1 = 0;
    lVar2 = param_2[1];
    *param_1 = *param_2;
    param_1[1] = lVar2;
    lVar2 = param_2[3];
    param_1[2] = param_2[2];
    param_1[3] = lVar2;
    param_2[2] = 0;
    param_2[3] = 0xf;
    *(undefined1 *)param_2 = 0;
  }
  return param_1;
}

/* RVA 0x1f530 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HMODULE FUN_18001f530(longlong *param_1)

{
  char *pcVar1;
  void *pvVar2;
  ulonglong uVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  longlong *plVar7;
  HMODULE pHVar8;
  LPCSTR ***ppppCVar9;
  void *pvVar10;
  longlong lVar11;
  int iVar12;
  undefined1 auStack_58 [32];
  longlong *local_38;
  LPCSTR ***local_30;
  undefined8 uStack_28;
  ulonglong local_20;
  ulonglong local_18;
  ulonglong local_10;
  
  local_10 = DAT_180052888 ^ (ulonglong)auStack_58;
  uStack_28 = 0;
  local_20 = 0;
  local_18 = 0xf;
  local_30 = (LPCSTR ***)0x0;
  local_38 = param_1;
  srand(0x37e07b3d);
  iVar12 = 0;
  if (param_1[2] != 0) {
    lVar11 = 0;
    do {
      plVar7 = param_1;
      if (0xf < (ulonglong)param_1[3]) {
        plVar7 = (longlong *)*param_1;
      }
      iVar5 = toupper((int)*(char *)(lVar11 + (longlong)plVar7));
      uVar6 = rand();
      uVar3 = local_20;
      uVar6 = uVar6 & 0x8000003f;
      if ((int)uVar6 < 0) {
        uVar6 = (uVar6 - 1 | 0xffffffc0) + 1;
      }
      cVar4 = ((byte)uVar6 ^ (char)iVar5 - 0x20U) + 0x20;
      if (local_20 < local_18) {
        ppppCVar9 = (LPCSTR ***)&local_30;
        if (0xf < local_18) {
          ppppCVar9 = local_30;
        }
        pcVar1 = (char *)((longlong)ppppCVar9 + local_20);
        local_20 = local_20 + 1;
        *pcVar1 = cVar4;
        *(CHAR *)((longlong)ppppCVar9 + uVar3 + 1) = '\0';
      }
      else {
        FUN_180007cd0(&local_30,1,0,cVar4);
      }
      iVar12 = iVar12 + 1;
      lVar11 = lVar11 + 1;
    } while ((ulonglong)(longlong)iVar12 < (ulonglong)param_1[2]);
  }
  ppppCVar9 = (LPCSTR ***)&local_30;
  if (0xf < local_18) {
    ppppCVar9 = local_30;
  }
  pHVar8 = LoadLibraryA((LPCSTR)ppppCVar9);
  if (pHVar8 == (HMODULE)0x0) {
    GetLastError();
  }
  if (0xf < local_18) {
    ppppCVar9 = local_30;
    if ((0xfff < local_18 + 1) &&
       (ppppCVar9 = (LPCSTR ***)local_30[-1],
       (LPCSTR)0x1f < (LPCSTR)((longlong)local_30 + (-8 - (longlong)ppppCVar9)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(ppppCVar9);
  }
  local_20 = 0;
  local_18 = 0xf;
  local_30 = (LPCSTR ***)((ulonglong)local_30 & 0xffffffffffffff00);
  if (0xf < (ulonglong)param_1[3]) {
    pvVar2 = (void *)*param_1;
    pvVar10 = pvVar2;
    if ((0xfff < param_1[3] + 1U) &&
       (pvVar10 = *(void **)((longlong)pvVar2 + -8),
       0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar10)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(pvVar10);
  }
  param_1[2] = 0;
  param_1[3] = 0xf;
  *(undefined1 *)param_1 = 0;
  return pHVar8;
}

/* RVA 0x1f710 */
undefined8 FUN_18001f710(longlong *param_1)

{
  if (*(int *)((longlong)param_1 + 0xe4) == 0) {
    (**(code **)(*param_1 + 0x20))();
  }
  if ((ICXSDocumentV22 *)param_1[0x1a] == (ICXSDocumentV22 *)0x0) {
    return 0x80004005;
  }
  CxsRaiseCustomEvent((ICXSDocumentV22 *)param_1[0x1a],(char *)0x0,0x3f8,"Main Window",0);
  return 0;
}

/* RVA 0x1f770 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_18001f770(undefined8 param_1,char *param_2,int param_3)

{
  int iVar1;
  BOOL BVar2;
  undefined4 extraout_var;
  HANDLE hObject;
  undefined4 extraout_var_00;
  undefined8 uVar3;
  undefined4 extraout_var_01;
  undefined1 auStackY_168 [32];
  CHAR local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_180052888 ^ (ulonglong)auStackY_168;
  iVar1 = _access(param_2,param_3);
  uVar3 = CONCAT44(extraout_var,iVar1);
  if ((iVar1 == 0) && (param_3 == 2)) {
    GetTempFileNameA(param_2,"_",0,local_128);
    hObject = CreateFileA(local_128,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,0x100,(HANDLE)0x0);
    if (hObject != (HANDLE)0xffffffffffffffff) {
      CloseHandle(hObject);
      BVar2 = DeleteFileA(local_128);
      return CONCAT44(extraout_var_01,BVar2) & 0xffffffffffffff00;
    }
    CloseHandle((HANDLE)0xffffffffffffffff);
    BVar2 = DeleteFileA(local_128);
    uVar3 = CONCAT44(extraout_var_00,BVar2);
  }
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}

/* RVA 0x1f850 */
undefined8 FUN_18001f850(longlong param_1)

{
  if (*(longlong *)(param_1 + 200) == 0) {
    return 0x80004005;
  }
  FUN_180009360(*(longlong *)(param_1 + 200));
  return 0;
}

/* RVA 0x1f880 */
void FUN_18001f880(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1)

{
  int iVar1;
  DWORD DVar2;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar3;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar4;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res10 [8];
  
  pCVar3 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Right
                     (param_1,(int)local_res10);
  iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare(pCVar3,"\\");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10);
  if (iVar1 == 0) {
    pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                       (param_1,(int)local_res10);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_1,pCVar4);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10);
  }
  DVar2 = GetFileAttributesA(*(LPCSTR *)param_1);
  if (DVar2 == 0xffffffff) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind(param_1,'\\');
    pCVar3 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                       (param_1,(int)local_res10);
    FUN_18001f880(pCVar3);
    CreateDirectoryA(*(LPCSTR *)param_1,(LPSECURITY_ATTRIBUTES)0x0);
  }
                    /* WARNING: Could not recover jumptable at 0x00018001f941. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1);
  return;
}

/* RVA 0x1f950 */
undefined8 FUN_18001f950(longlong param_1)

{
  int iVar1;
  BOOL BVar2;
  int iVar3;
  
  if ((*(char *)(param_1 + 0xe0) != '\0') && (*(char *)(param_1 + 0xe9) != '\0')) {
    iVar3 = 0;
    while (((iVar1 = _access((char *)(param_1 + 0x1ef),0), iVar1 == 0 && (iVar3 < 10)) &&
           (BVar2 = FUN_180026330((LPCSTR)(param_1 + 0x1ef)), BVar2 == 0))) {
      GetLastError();
      iVar3 = iVar3 + 1;
      Sleep(0xfa);
    }
  }
  return 0x80004005;
}

/* RVA 0x1f9f0 */
undefined8 FUN_18001f9f0(longlong param_1)

{
  *(undefined1 *)(param_1 + 0x374) = 1;
  return 0;
}

/* RVA 0x1fa00 */
undefined8 FUN_18001fa00(longlong param_1,wchar_t *param_2)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res8 [16];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res18 [16];
  
  if (*(longlong *)(param_1 + 200) == 0) {
    return 0x80004005;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8,param_2);
  pCVar1 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
           CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                     (local_res18,
                      (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                      local_res8);
  FUN_18000bd10(*(undefined8 **)(param_1 + 200),pCVar1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
  return 0;
}

/* RVA 0x1fa60 */
undefined8 FUN_18001fa60(longlong param_1)

{
  if (*(ICXSDocumentV22 **)(param_1 + 0xc0) == (ICXSDocumentV22 *)0x0) {
    return 0x80004005;
  }
  CxsRaiseCustomEvent(*(ICXSDocumentV22 **)(param_1 + 0xc0),(char *)0x0,0x3ff,(char *)0x0,0);
  return 0;
}

/* RVA 0x1faa0 */
bool FUN_18001faa0(longlong param_1,char *param_2,int param_3)

{
  ulonglong uVar1;
  
  if (*(longlong *)(param_1 + 200) == 0) {
    return true;
  }
  uVar1 = FUN_1800119a0(*(longlong *)(param_1 + 200),param_2,param_3);
  return (char)uVar1 == '\0';
}

/* RVA 0x1fad0 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_18001fad0(longlong param_1)

{
  AFX_MODULE_STATE *pAVar1;
  
  if (DAT_180054050 == 0) {
    FUN_180020c90(param_1);
    DAT_180054050 = param_1;
    APInitInstance(param_1);
    _DAT_180054048 = ApwnContextInitialize();
    pAVar1 = AfxSetModuleState(_DAT_180054048);
    FindComponentInitExtDLL();
    MMStructInitExtDLL();
    MMDialogDLLInitExtDLL();
    AfxSetModuleState(pAVar1);
  }
  return 0;
}

/* RVA 0x1fb30 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_18001fb30(longlong param_1)

{
  longlong *plVar1;
  undefined8 *puVar2;
  
  if (DAT_180054050 != param_1) {
    return;
  }
  _DAT_180054048 = 0;
  plVar1 = *(longlong **)(param_1 + 0xd0);
  if (plVar1 != (longlong *)0x0) {
    *(undefined8 *)(param_1 + 0xd0) = 0;
    (**(code **)(*plVar1 + 0x10))();
  }
  DAT_180054050 = 0;
  if (*(longlong *)(param_1 + 200) != 0) {
    FUN_1800118b0(*(longlong *)(param_1 + 200));
    puVar2 = *(undefined8 **)(param_1 + 200);
    if (puVar2 != (undefined8 *)0x0) {
      FUN_180008cd0(puVar2);
      FUN_180035134(puVar2);
    }
    *(undefined8 *)(param_1 + 200) = 0;
  }
  APExitInstance();
  plVar1 = *(longlong **)(param_1 + 0xd8);
  if (plVar1 != (longlong *)0x0) {
    *(undefined8 *)(param_1 + 0xd8) = 0;
    (**(code **)(*plVar1 + 0x10))();
  }
  CloseHandle(DAT_180054058);
  DAT_180054058 = (HANDLE)0x0;
  CloseHandle(DAT_180054060);
  DAT_180054060 = (HANDLE)0x0;
  CloseHandle(DAT_180054068);
  DAT_180054068 = (HANDLE)0x0;
  SEUnhookThemes();
  SEFreeSettings();
  if (*(char *)(param_1 + 0x37d) != '\0') {
    MMReleaseWaitStruct();
  }
  DCOM_TERMINATE();
  return;
}

/* RVA 0x1fc40 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18001fc40(longlong param_1)

{
  char cVar1;
  undefined8 *puVar2;
  longlong lVar3;
  BOOL BVar4;
  longlong lVar5;
  char *pcVar6;
  undefined1 auStackY_178 [32];
  tagMSG local_148;
  char local_118 [256];
  ulonglong local_18;
  
  local_18 = DAT_180052888 ^ (ulonglong)auStackY_178;
  if (*(longlong *)(param_1 + 200) != 0) {
    ApwnContextDocumentClose(*(void **)(*(longlong *)(param_1 + 200) + 0xb0));
    if (*(longlong *)(param_1 + 0xd0) != 0) {
      *(undefined1 *)(param_1 + 0x37c) = 0;
      CxsClearNodeCaches();
      CxsRaiseCustomEvent(*(ICXSDocumentV22 **)(param_1 + 0xd0),(char *)0x0,0x3f4,(char *)0x0,0);
      cVar1 = *(char *)(param_1 + 0x37c);
      while (cVar1 == '\0') {
        BVar4 = PeekMessageA(&local_148,(HWND)0x0,0,0,1);
        if (BVar4 != 0) {
          DispatchMessageA(&local_148);
        }
        cVar1 = *(char *)(param_1 + 0x37c);
      }
    }
    CxsClearNodeCaches();
    pcVar6 = (char *)(*(longlong *)(param_1 + 200) + 0x60);
    if (0xf < *(ulonglong *)(*(longlong *)(param_1 + 200) + 0x78)) {
      pcVar6 = *(char **)pcVar6;
    }
    pcVar6 = _strdup(pcVar6);
    FUN_1800118b0(*(longlong *)(param_1 + 200));
    puVar2 = *(undefined8 **)(param_1 + 200);
    if (puVar2 != (undefined8 *)0x0) {
      FUN_180008cd0(puVar2);
      FUN_180035134(puVar2);
    }
    *(undefined8 *)(param_1 + 200) = 0;
    if ((*(char *)(param_1 + 0xe0) != '\0') && (*(char *)(param_1 + 0xe9) != '\0')) {
      _splitpath(pcVar6,(char *)(param_1 + 0x1ef),local_118,(char *)0x0,(char *)0x0);
      strncat((char *)(param_1 + 0x1ef),local_118,0x100);
      lVar3 = -1;
      do {
        lVar5 = lVar3;
        lVar3 = lVar5 + 1;
      } while (*(char *)(param_1 + 0x1f0 + lVar5) != '\0');
      *(undefined1 *)(lVar5 + 0x1ef + param_1) = 0;
    }
    free(pcVar6);
  }
  return 0;
}

/* RVA 0x1fdf0 */
void FUN_18001fdf0(undefined8 param_1,long param_2,IUnknown *param_3)

{
  ApwnContextDoObjectVerb(param_2,param_3);
  return;
}

/* RVA 0x1fe00 */
undefined8 FUN_18001fe00(longlong *param_1)

{
  (**(code **)(*param_1 + 0x58))();
  SetGlobalWinApp(0);
  if ((ICXSDocumentV22 *)param_1[0x1a] != (ICXSDocumentV22 *)0x0) {
    CxsRaiseCustomEvent((ICXSDocumentV22 *)param_1[0x1a],(char *)0x0,0x3f9,(char *)0x0,0);
  }
  return 0;
}

/* RVA 0x1fe50 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18001fe50(longlong param_1,short param_2,longlong *param_3)

{
  int iVar1;
  ICXSDocumentV22 *pIVar2;
  __uint64 _Var3;
  undefined1 auStackY_5d8 [32];
  char *local_5a8;
  _union_2707 local_5a0;
  undefined4 local_588;
  ULONG UStack_584;
  undefined4 uStack_580;
  undefined4 uStack_57c;
  undefined8 local_578;
  _union_2707 local_568;
  char *local_548;
  char local_540 [136];
  char *local_4b8;
  char local_4b0 [136];
  char local_428 [1024];
  ulonglong local_28;
  
  local_28 = DAT_180052888 ^ (ulonglong)auStackY_5d8;
  if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4)
       < DAT_180054078) && (FUN_180035090(&DAT_180054078), DAT_180054078 == -1)) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_180054070);
    atexit((_func_5014 *)&LAB_1800396c0);
    _Init_thread_footer(&DAT_180054078);
  }
  if (*(longlong *)(param_1 + 200) == 0) {
    return 0x80004005;
  }
  switch(param_2) {
  case 0xf:
    HAFullBlockName(param_3,local_428,0x400);
    CxsRaiseCustomEvent(*(ICXSDocumentV22 **)(param_1 + 0xd0),local_428,0x4fc,(char *)0x0,0);
    break;
  case 0x10:
  case 0x20:
    if ((param_3 != (longlong *)0x0) && (*(longlong *)(param_1 + 0xd0) != 0)) {
      VariantInit((VARIANTARG *)&local_568.n2);
      VariantInit((VARIANTARG *)&local_5a0.n2);
      local_588 = local_568._0_4_;
      UStack_584 = local_568.decVal.Hi32;
      uStack_580 = local_568._8_4_;
      uStack_57c = local_568._12_4_;
      local_578 = local_568._16_8_;
      iVar1 = (**(code **)(*param_3 + 0x98))(param_3,0x3f,&local_588,&local_5a0);
      if ((-1 < iVar1) && ((local_5a0.n2.vt == 3 && (local_5a0._8_4_ != 0)))) {
        VariantClear((VARIANTARG *)&local_5a0.n2);
        local_588 = local_568._0_4_;
        UStack_584 = local_568.decVal.Hi32;
        uStack_580 = local_568._8_4_;
        uStack_57c = local_568._12_4_;
        local_578 = local_568._16_8_;
        iVar1 = (**(code **)(*param_3 + 0x98))(param_3,0x41);
        if (-1 < iVar1) {
          local_4b8 = local_4b0;
          FUN_18000d880(&local_4b8,(LPCWSTR)CONCAT44(local_5a0._12_4_,local_5a0._8_4_),0);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5a8,
                     local_4b8);
          if (local_4b8 != local_4b0) {
            free(local_4b8);
          }
          if (param_2 == 0x20) {
            FUN_180011b60(*(longlong *)(param_1 + 200),
                          (BSTR)CONCAT44(local_5a0._12_4_,local_5a0._8_4_));
          }
          CxsRaiseCustomEvent(*(ICXSDocumentV22 **)(param_1 + 0xd0),local_5a8,0x4f1,(char *)0x0,0);
          (**(code **)(*param_3 + 0x10))(param_3);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5a8);
        }
      }
    }
    break;
  case 0x11:
    if ((param_3 != (longlong *)0x0) && (*(longlong *)(param_1 + 0xd0) != 0)) {
      FUN_180013520(*(longlong *)(param_1 + 200),param_3);
      VariantInit((VARIANTARG *)&local_568.n2);
      VariantInit((VARIANTARG *)&local_5a0.n2);
      local_588 = local_568._0_4_;
      UStack_584 = local_568.decVal.Hi32;
      uStack_580 = local_568._8_4_;
      uStack_57c = local_568._12_4_;
      local_578 = local_568._16_8_;
      iVar1 = (**(code **)(*param_3 + 0x98))(param_3,0x3f,&local_588,&local_5a0);
      if ((-1 < iVar1) && ((local_5a0.n2.vt == 3 && (local_5a0._8_4_ != 0)))) {
        VariantClear((VARIANTARG *)&local_5a0.n2);
        local_588 = local_568._0_4_;
        UStack_584 = local_568.decVal.Hi32;
        uStack_580 = local_568._8_4_;
        uStack_57c = local_568._12_4_;
        local_578 = local_568._16_8_;
        iVar1 = (**(code **)(*param_3 + 0x98))(param_3,0x41,&local_588,&local_5a0);
        if (-1 < iVar1) {
          local_548 = local_540;
          FUN_18000d880(&local_548,(LPCWSTR)CONCAT44(local_5a0._12_4_,local_5a0._8_4_),0);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5a8,
                     local_548);
          if (local_548 != local_540) {
            free(local_548);
          }
          CxsRaiseCustomEvent(*(ICXSDocumentV22 **)(param_1 + 0xd0),DAT_180054070,0x4fb,local_5a8,0)
          ;
          (**(code **)(*param_3 + 0x10))(param_3);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5a8);
        }
      }
    }
    break;
  case 0x1f:
    if (param_3 == (longlong *)0x0) {
      return 0;
    }
    pIVar2 = *(ICXSDocumentV22 **)(param_1 + 0xd0);
    if (pIVar2 == (ICXSDocumentV22 *)0x0) {
      return 0;
    }
    _Var3 = 0x4f2;
    goto LAB_1800201f4;
  case 0x21:
    if (param_3 == (longlong *)0x0) {
      return 0;
    }
    pIVar2 = *(ICXSDocumentV22 **)(param_1 + 0xd0);
    if (pIVar2 == (ICXSDocumentV22 *)0x0) {
      return 0;
    }
    _Var3 = 0x4f6;
LAB_1800201f4:
    CxsRaiseCustomEvent(pIVar2,(char *)0x0,_Var3,(char *)0x0,0);
    (**(code **)(*param_3 + 0x10))(param_3);
    break;
  case 0x22:
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_180054070,
               (char *)param_3);
  }
  return 0;
}

/* RVA 0x202d0 */
undefined4 FUN_1800202d0(longlong param_1)

{
  char cVar1;
  undefined8 *puVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  if (*(longlong *)(param_1 + 200) == 0) {
    ApwnEnsureContext();
    puVar2 = operator_new(0xf8);
    if (puVar2 == (undefined8 *)0x0) {
      puVar2 = (undefined8 *)0x0;
    }
    else {
      puVar2 = FUN_18001f330(puVar2);
    }
    *(undefined8 **)(param_1 + 200) = puVar2;
    cVar1 = FUN_1800128b0((longlong)puVar2);
    uVar3 = 0x80004005;
    if (cVar1 == '\0') {
      FUN_1800118b0(*(longlong *)(param_1 + 200));
      puVar2 = *(undefined8 **)(param_1 + 200);
      if (puVar2 != (undefined8 *)0x0) {
        FUN_180008cd0(puVar2);
        FUN_180035134(puVar2);
      }
      *(undefined8 *)(param_1 + 200) = 0;
    }
    else {
      uVar3 = 0;
      if (((*(char *)(param_1 + 0xe0) != '\0') && (*(int *)(param_1 + 0xe4) == 0)) &&
         (*(ICXSDocumentV22 **)(param_1 + 0xd0) != (ICXSDocumentV22 *)0x0)) {
        pcVar4 = (char *)(*(longlong *)(param_1 + 200) + 0x40);
        if (0xf < *(ulonglong *)(*(longlong *)(param_1 + 200) + 0x58)) {
          pcVar4 = *(char **)pcVar4;
        }
        CxsRaiseCustomEvent(*(ICXSDocumentV22 **)(param_1 + 0xd0),(char *)0x0,0x3f6,pcVar4,0);
      }
    }
  }
  else {
    uVar3 = 0x80004005;
  }
  return uVar3;
}

/* RVA 0x203d0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1800203d0(longlong param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  char *pcVar5;
  undefined8 uVar6;
  longlong lVar7;
  char *pcVar8;
  undefined1 auStackY_278 [32];
  char local_238 [272];
  char local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_180052888 ^ (ulonglong)auStackY_278;
  if (*(longlong *)(param_1 + 200) != 0) {
    return 0x80004005;
  }
  ApwnEnsureContext();
  puVar3 = operator_new(0xf8);
  puVar4 = (undefined8 *)0x0;
  if (puVar3 != (undefined8 *)0x0) {
    puVar4 = FUN_18001f330(puVar3);
  }
  *(undefined8 **)(param_1 + 200) = puVar4;
  if (param_2 == (char *)0x0) {
    return 0x80070057;
  }
  pcVar5 = _strdup(param_2);
  *(undefined1 *)(param_1 + 0xe9) = 0;
  local_238[0] = '\0';
  if (*(char *)(param_1 + 0xe0) == '\0') goto LAB_180020543;
  iVar2 = FUN_18000c180(param_2);
  if (iVar2 == 8) {
    *(undefined1 *)(param_1 + 0xe9) = 1;
    strncpy((char *)(param_1 + 0xea),param_2,0x104);
    *(undefined1 *)(param_1 + 0x1ee) = 0;
    local_128[0] = '\0';
    uVar6 = FUN_180030d60(*(byte *)(param_1 + 0xe0),param_2,(longlong)local_128,(longlong)local_238)
    ;
    if ((int)uVar6 != 0) {
      return uVar6;
    }
    operator_delete__(pcVar5);
    pcVar5 = _strdup(local_128);
    lVar7 = GetGlobalPointer("CompoundFileName");
    if (lVar7 == 0) {
      pcVar8 = param_2;
LAB_18002050b:
      SetGlobalPointer("CompoundFileName",pcVar8,0);
    }
  }
  else {
    lVar7 = GetGlobalPointer("CompoundFileName");
    if (lVar7 != 0) {
      pcVar8 = (char *)0x0;
      goto LAB_18002050b;
    }
  }
  lVar7 = GetGlobalPointer("WorkingDirectorySet");
  if (lVar7 == 0) {
    pcVar8 = local_238;
    if (*(char *)(param_1 + 0xe9) == '\0') {
      pcVar8 = pcVar5;
    }
    FUN_1800230a0(param_1,pcVar8);
  }
LAB_180020543:
  lVar7 = GetGlobalPointer();
  if ((lVar7 != 0) && (*(char *)(param_1 + 0xe0) == '\0')) {
    FUN_180029cb0('\0',param_2);
    FUN_180032500((ulonglong)*(byte *)(param_1 + 0xe0),param_2);
  }
  cVar1 = FUN_180012bc0(*(longlong *)(param_1 + 200),pcVar5);
  if (cVar1 == '\0') {
    FUN_1800118b0(*(longlong *)(param_1 + 200));
    puVar4 = *(undefined8 **)(param_1 + 200);
    if (puVar4 != (undefined8 *)0x0) {
      FUN_180008cd0(puVar4);
      FUN_180035134(puVar4);
    }
    *(undefined8 *)(param_1 + 200) = 0;
    uVar6 = 0xffffffff;
  }
  else {
    if ((((*(char *)(param_1 + 0xe0) != '\0') && (*(int *)(param_1 + 0xe4) == 0)) &&
        (*(ICXSDocumentV22 **)(param_1 + 0xd0) != (ICXSDocumentV22 *)0x0)) &&
       (CxsRaiseCustomEvent(*(ICXSDocumentV22 **)(param_1 + 0xd0),(char *)0x0,0x3f6,param_2,1),
       *(char *)(param_1 + 0xe9) != '\0')) {
      CxsRaiseCustomEvent(*(ICXSDocumentV22 **)(param_1 + 0xd0),(char *)0x0,0x3f6,pcVar5,2);
      CxsRaiseCustomEvent(*(ICXSDocumentV22 **)(param_1 + 0xd0),(char *)0x0,0x3f6,local_238,3);
    }
    FUN_180035134(pcVar5);
    uVar6 = 0;
  }
  return uVar6;
}

/* RVA 0x20680 */
undefined8 FUN_180020680(longlong param_1,int param_2,char *param_3)

{
  ICXSDocumentV22 *pIVar1;
  long local_res8 [2];
  
  pIVar1 = *(ICXSDocumentV22 **)(param_1 + 0xd0);
  if (pIVar1 == (ICXSDocumentV22 *)0x0) {
    return 0x80004005;
  }
  if (param_2 == 0x78) {
    *(undefined1 *)(param_1 + 0xe8) = 1;
    return 0;
  }
  if (param_2 == 0x79) {
    *(undefined1 *)(param_1 + 0xe8) = 0;
    return 0;
  }
  if (param_2 == 0x67) {
    if (*(char *)(param_1 + 0xe8) == '\0') {
      CxsRaiseCustomEvent(pIVar1,(char *)0x0,0x3ed,param_3,0x67);
      return 0;
    }
  }
  else if ((param_2 - 0x66U < 0x15) && ((0x10000dU >> (param_2 - 0x66U & 0x1f) & 1) != 0)) {
    CxsClearNodeCaches();
    if (*(char *)(param_1 + 0xe8) == '\0') {
      CxsRaiseCustomEvent(*(ICXSDocumentV22 **)(param_1 + 0xd0),(char *)0x0,0x3ed,param_3,param_2);
      return 0;
    }
  }
  else if ((param_2 == 0x7b) &&
          ((*(char *)(param_1 + 0xe0) != '\0' && (*(int *)(param_1 + 0xe4) != 0)))) {
    CxsRaiseCustomEventWait(pIVar1,(char *)0x0,0x3ed,(char *)0x0,0x7b,0,local_res8);
  }
  return 0;
}

/* RVA 0x207d0 */
undefined4 FUN_1800207d0(longlong param_1,char *param_2,undefined8 param_3,DWORD param_4)

{
  char cVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined4 uVar4;
  
  if (*(longlong *)(param_1 + 200) == 0) {
    ApwnEnsureContext();
    puVar2 = operator_new(0xf8);
    if (puVar2 == (undefined8 *)0x0) {
      puVar2 = (undefined8 *)0x0;
    }
    else {
      puVar2 = FUN_18001f330(puVar2);
    }
    *(undefined8 **)(param_1 + 200) = puVar2;
    if ((*(char *)(param_1 + 0xe0) != '\0') &&
       (lVar3 = GetGlobalPointer("WorkingDirectorySet"), lVar3 == 0)) {
      FUN_1800230a0(param_1,param_2);
    }
    cVar1 = FUN_180013b10(*(longlong *)(param_1 + 200),param_2,param_4);
    uVar4 = 0x80004005;
    if ((((cVar1 != '\0') && (uVar4 = 0, *(char *)(param_1 + 0xe0) != '\0')) &&
        (*(int *)(param_1 + 0xe4) == 0)) &&
       (*(ICXSDocumentV22 **)(param_1 + 0xd0) != (ICXSDocumentV22 *)0x0)) {
      CxsRaiseCustomEvent(*(ICXSDocumentV22 **)(param_1 + 0xd0),(char *)0x0,0x3f6,param_2,1);
    }
  }
  else {
    uVar4 = 0x80004005;
  }
  return uVar4;
}

/* RVA 0x208d0 */
int FUN_1800208d0(longlong param_1,IStorage param_2)

{
  undefined4 uVar1;
  ulonglong uVar2;
  IStorage IVar3;
  int iVar4;
  long local_res8 [2];
  
  if (*(undefined8 **)(param_1 + 200) == (undefined8 *)0x0) {
    return -0x7fffbffb;
  }
  if ((*(char *)(param_1 + 0xe0) == '\0') || (*(char *)(param_1 + 0xe9) == '\0')) {
    uVar1 = MMGetVisibleSuppress();
    if ((*(char *)(param_1 + 0xe0) != '\0') && (*(int *)(param_1 + 0xe4) == 0)) {
      MMSetVisibleSuppress(0);
    }
    uVar2 = FUN_180018d40(*(IStorageVtbl **)(param_1 + 200),param_2);
    iVar4 = -0x7fffbffb;
    if ((char)uVar2 != '\0') {
      iVar4 = 0;
    }
    if ((*(char *)(param_1 + 0xe0) != '\0') && (*(int *)(param_1 + 0xe4) == 0)) {
      MMSetVisibleSuppress(uVar1);
    }
  }
  else {
    IVar3.lpVtbl = param_2.lpVtbl;
    if (param_2.lpVtbl == (IStorageVtbl *)0x0) {
      IVar3.lpVtbl = (IStorageVtbl *)(param_1 + 0xea);
    }
    uVar2 = FUN_18000b2c0(*(undefined8 **)(param_1 + 200),(char *)IVar3.lpVtbl);
    iVar4 = 0;
    if ((int)uVar2 == 0) {
      iVar4 = -0x7fffbffb;
    }
  }
  if (((iVar4 == 0) && (*(ICXSDocumentV22 **)(param_1 + 0xd0) != (ICXSDocumentV22 *)0x0)) &&
     (*(char *)(param_1 + 0xe8) == '\0')) {
    CxsRaiseCustomEventWait
              (*(ICXSDocumentV22 **)(param_1 + 0xd0),(char *)0x0,0x3f7,(char *)param_2.lpVtbl,0,0,
               local_res8);
  }
  return iVar4;
}

/* RVA 0x209e0 */
undefined8 FUN_1800209e0(longlong param_1,undefined8 *param_2)

{
  *param_2 = *(undefined8 *)(param_1 + 0xc0);
  return 0;
}

/* RVA 0x209f0 */
undefined8 FUN_1800209f0(longlong param_1,int *param_2)

{
  if (param_2 == (int *)0x0) {
    return 0x80070057;
  }
  *param_2 = -(uint)(*(int *)(param_1 + 0xe4) != 0);
  return 0;
}

/* RVA 0x20a10 */
bool FUN_180020a10(longlong param_1,uchar *param_2)

{
  undefined8 uVar1;
  
  if (*(longlong *)(param_1 + 200) == 0) {
    return true;
  }
  uVar1 = FUN_1800124b0(*(longlong *)(param_1 + 200),param_2);
  return (char)uVar1 == '\0';
}

/* RVA 0x20a40 */
void FUN_180020a40(undefined8 *param_1,LPCWSTR param_2,UINT param_3)

{
  LPSTR pCVar1;
  LPSTR pCVar2;
  int iVar3;
  DWORD DVar4;
  LPSTR pCVar5;
  int cchWideChar;
  longlong lVar6;
  bool bVar7;
  
  if (param_2 == (LPCWSTR)0x0) {
    *param_1 = 0;
    return;
  }
  lVar6 = -1;
  do {
    lVar6 = lVar6 + 1;
  } while (param_2[lVar6] != L'\0');
  cchWideChar = (int)lVar6 + 1;
  pCVar1 = (LPSTR)(param_1 + 1);
  iVar3 = cchWideChar * 4;
  if (((param_1 == (undefined8 *)0x0) || (iVar3 < 0)) || (pCVar1 == (LPSTR)0x0)) {
                    /* WARNING: Subroutine does not return */
    FUN_1800018d0(-0x7ff8ffa9);
  }
  pCVar2 = (LPSTR)*param_1;
  pCVar5 = pCVar1;
  if (pCVar2 == pCVar1) {
    if (iVar3 < 0x29) {
      *param_1 = pCVar1;
    }
    else {
      pCVar5 = calloc((longlong)iVar3,1);
      *param_1 = pCVar5;
      if (pCVar5 == (LPSTR)0x0) goto LAB_180020c4c;
    }
  }
  else {
    if (iVar3 < 0x29) {
      free(pCVar2);
    }
    else {
      pCVar5 = _recalloc(pCVar2,(longlong)iVar3,1);
      if (pCVar5 == (LPSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_1800018d0(-0x7ff8fff2);
      }
    }
    *param_1 = pCVar5;
  }
  iVar3 = WideCharToMultiByte(param_3,0,param_2,cchWideChar,pCVar5,iVar3,(LPCSTR)0x0,(LPBOOL)0x0);
  bVar7 = iVar3 == 0;
  if ((iVar3 == 0) && (DVar4 = GetLastError(), DVar4 == 0x7a)) {
    iVar3 = WideCharToMultiByte(param_3,0,param_2,cchWideChar,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    if (iVar3 < 0) {
                    /* WARNING: Subroutine does not return */
      FUN_1800018d0(-0x7ff8ffa9);
    }
    pCVar2 = (LPSTR)*param_1;
    pCVar5 = pCVar1;
    if (pCVar2 == pCVar1) {
      if (iVar3 < 0x29) {
        *param_1 = pCVar1;
      }
      else {
        pCVar5 = calloc((longlong)iVar3,1);
        *param_1 = pCVar5;
        if (pCVar5 == (LPSTR)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_1800018d0(-0x7ff8fff2);
        }
      }
    }
    else {
      if (iVar3 < 0x29) {
        free(pCVar2);
      }
      else {
        pCVar5 = _recalloc(pCVar2,(longlong)iVar3,1);
        if (pCVar5 == (LPSTR)0x0) {
LAB_180020c4c:
                    /* WARNING: Subroutine does not return */
          FUN_1800018d0(-0x7ff8fff2);
        }
      }
      *param_1 = pCVar5;
    }
    iVar3 = WideCharToMultiByte(param_3,0,param_2,cchWideChar,pCVar5,iVar3,(LPCSTR)0x0,(LPBOOL)0x0);
    bVar7 = iVar3 == 0;
  }
  if (bVar7) {
    FUN_180006e80((void *)*param_1,pCVar1);
                    /* WARNING: Subroutine does not return */
    FUN_180009340();
  }
  return;
}

/* RVA 0x20c90 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180020c90(longlong param_1)

{
  int iVar1;
  DWORD DVar2;
  UINT UVar3;
  HANDLE pvVar4;
  GUID *rguid;
  longlong lVar5;
  ulonglong uVar7;
  ulonglong uVar6;
  undefined1 auStack_1c8 [32];
  undefined1 *local_1a8;
  undefined1 local_1a0 [40];
  OLECHAR local_178 [31];
  char acStack_13a [6];
  char acStack_134 [12];
  CHAR local_128;
  char acStack_127 [271];
  ulonglong local_18;
  
  local_18 = DAT_180052888 ^ (ulonglong)auStack_1c8;
  FUN_1800235c0(param_1,'\0');
  GetModuleFileNameA((HMODULE)0x0,&local_128,0x104);
  _strlwr(&local_128);
  uVar6 = 0xffffffffffffffff;
  do {
    uVar7 = uVar6;
    uVar6 = uVar7 + 1;
  } while (acStack_127[uVar7] != '\0');
  *(undefined1 *)(param_1 + 0x37d) = 1;
  if (0xe < uVar6) {
    iVar1 = strcmp(acStack_134 + uVar7,"aspenplus.exe");
    if (iVar1 == 0) {
      *(undefined1 *)(param_1 + 0x37d) = 0;
      goto LAB_180020d52;
    }
    if (0x14 < uVar6) {
      iVar1 = strcmp(acStack_13a + uVar7,"aspenproperties.exe");
      if (iVar1 == 0) {
        *(undefined1 *)(param_1 + 0x37d) = 0;
        goto LAB_180020d52;
      }
    }
  }
  MMInitWaitStruct();
LAB_180020d52:
  DAT_180054058 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,1,(LPCSTR)0x0);
  SetGlobalPointer("DCOM_EVENT",DAT_180054058,1);
  DAT_180054060 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,1,(LPCSTR)0x0);
  SetGlobalPointer("DCOM_MSHL_EVENT",DAT_180054060,1);
  DCOM_SET_SYNC(DAT_180054060);
  DVar2 = GetCurrentThreadId();
  *(DWORD *)(param_1 + 0x378) = DVar2;
  pvVar4 = GetCurrentThread();
  SetGlobalPointer("APWN_TID",pvVar4,1);
  DAT_180054068 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,1,(LPCSTR)0x0);
  SetGlobalPointer("XLPTR_EVENT",DAT_180054068,1);
  SetGlobalPointer("APXLGetItem",FUN_180025070,0);
  SetGlobalPointer("APXLRemoveItem",FUN_180025350,0);
  SetGlobalPointer("APXLRestoreItem",&LAB_180025390,0);
  SetGlobalPointer("APXLDoCalc",FUN_1800252a0,0);
  SetGlobalPointer("APXLCloseItem",&LAB_180025230,0);
  SetGlobalPointer("APXLCommitItem",FUN_180025260,0);
  SetGlobalPointer("APXLEditDefVars",FUN_180025310,0);
  SetGlobalPointer("RefreshForms",FUN_180024db0,0);
  SetGlobalPointer("LoadForm",FUN_180001d40,0);
  SetGlobalPointer("SetupAutomation",FUN_180024de0,0);
  UVar3 = RegisterClipboardFormatA("CF_SELECTED_TEXT");
  SetGlobalPointer("CF_SELECTED_TEXT",UVar3,0);
  MMSetVisibleSuppress(1);
  GRsetAutomationMode(0);
  iVar1 = FUN_180033bd0();
  rguid = (GUID *)&DAT_180041ff0;
  if (iVar1 == 2) {
    rguid = (GUID *)&DAT_180042010;
  }
  StringFromGUID2(rguid,local_178,0x28);
  local_1a8 = local_1a0;
  FUN_180020a40(&local_1a8,local_178,0);
  DCOM_INIT(local_1a8);
  if (local_1a8 != local_1a0) {
    free(local_1a8);
  }
  lVar5 = param_1 + 8;
  if (param_1 == 0) {
    lVar5 = 0;
  }
  SetGlobalWinApp(lVar5);
  return;
}

/* RVA 0x20fc0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_180020fc0(longlong param_1)

{
  BYTE *pBVar1;
  BYTE BVar2;
  char cVar3;
  ulonglong uVar4;
  LSTATUS LVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  FILE *_File;
  undefined *puVar9;
  longlong *plVar10;
  undefined8 ****ppppuVar11;
  undefined8 uVar12;
  longlong lVar13;
  void *pvVar14;
  LPCSTR ***ppppCVar15;
  char ****ppppcVar16;
  uint uVar17;
  void *pvVar18;
  size_t sVar19;
  LPDWORD lpType;
  undefined1 auStackY_6e8 [32];
  DWORD local_6b8;
  undefined4 uStack_6b4;
  DWORD local_6b0 [2];
  HKEY local_6a8;
  HKEY local_6a0;
  HKEY local_698;
  DWORD local_690 [2];
  char ****local_688;
  undefined8 uStack_680;
  ulonglong local_678;
  ulonglong local_670;
  undefined8 ****local_668;
  longlong lStack_660;
  longlong local_658;
  ulonglong uStack_650;
  char *local_648;
  undefined8 uStack_640;
  undefined8 local_638;
  ulonglong local_630;
  LPCSTR ***local_628;
  undefined8 ***pppuStack_620;
  undefined8 ***local_618;
  undefined8 ***pppuStack_610;
  char *local_608;
  undefined8 uStack_600;
  undefined8 local_5f8;
  ulonglong local_5f0;
  BYTE local_5e8 [16];
  BYTE local_5d8 [16];
  CHAR local_5c8 [16];
  CHAR local_5b8 [128];
  CHAR local_538;
  undefined1 local_537 [511];
  BYTE local_338 [256];
  CHAR local_238;
  undefined1 local_237 [511];
  ulonglong local_38;
  
  local_38 = DAT_180052888 ^ (ulonglong)auStackY_6e8;
  pcVar7 = GetProfileStringA("mm","mmtop",(char *)0x0);
  if ((pcVar7 == (char *)0x0) || (*pcVar7 == '\0')) {
    pcVar7 = GetLMProfileString("mm","mmtop",(char *)0x0);
  }
  strncpy((char *)&szmmtop,pcVar7,0x103);
  SetGlobalPointer("MMTOP",&szmmtop,1);
  pcVar7 = GetLMSystemProfileString("mm","mmcommontop");
  strncpy((char *)&szmmcommontop,pcVar7,0x103);
  SetGlobalPointer("MMCOMMONTOP",&szmmcommontop);
  pcVar7 = GetProfileStringA("mm","mmxeq",(char *)0x0);
  if ((pcVar7 == (char *)0x0) || (*pcVar7 == '\0')) {
    pcVar7 = GetLMProfileString("mm","mmxeq",(char *)0x0);
  }
  strncpy((char *)&szmmxeq,pcVar7,0x103);
  SetGlobalPointer("MMXEQ",&szmmxeq,1);
  pcVar7 = GetLMSystemProfileString("mm","mmcommonxeq");
  strncpy((char *)&szmmcommonxeq,pcVar7,0x103);
  SetGlobalPointer("MMCOMMONXEQ",&szmmcommonxeq,1);
  GetEnvironmentVariableA("TEMP",local_5b8,0x78);
  pcVar7 = GetProfileStringA("mmgini","startupdir",(char *)0x0);
  if ((pcVar7 == (char *)0x0) || (*pcVar7 == '\0')) {
    pcVar7 = GetLMProfileString("mm","mmdefault",local_5b8);
  }
  pcVar8 = MMReplaceEnvironmentVariables(pcVar7);
  *(char **)(param_1 + 0xc0) = pcVar8;
  if ((pcVar7 != (char *)0x0) && (*pcVar7 != '\0')) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6b8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6b8,
               "%s\\Aplus_Tmp00000001.tmp");
    _File = fopen((char *)CONCAT44(uStack_6b4,local_6b8),"w");
    if (_File != (FILE *)0x0) {
      fclose(_File);
      remove((char *)CONCAT44(uStack_6b4,local_6b8));
      goto LAB_18002126f;
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6b8);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6b8);
  SHGetSpecialFolderPathA((HWND)0x0,&local_538,5,0);
  pcVar7 = FUN_180033bc0();
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6b8,
             "%s\\Aspentech\\Aspen Plus %s",&local_538,pcVar7);
  pcVar7 = MMReplaceEnvironmentVariables((char *)CONCAT44(uStack_6b4,local_6b8));
  *(char **)(param_1 + 0xc0) = pcVar7;
LAB_18002126f:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6b8);
  pcVar7 = GetProfileStringA("mm","mmdat",(char *)0x0);
  if ((pcVar7 == (char *)0x0) || (*pcVar7 == '\0')) {
    pcVar7 = GetLMProfileString("mm","mmdat",(char *)0x0);
  }
  strncpy((char *)&szmmdat,pcVar7,0x103);
  SetGlobalPointer("MMDAT",&szmmdat,1);
  pcVar7 = GetLMSystemProfileString("mm","mmcommondat");
  strncpy((char *)&szmmcommondat,pcVar7,0x103);
  SetGlobalPointer("MMCOMMONDAT",&szmmcommondat);
  pcVar7 = GetProfileStringA("aplus","asptop",(char *)0x0);
  if ((pcVar7 == (char *)0x0) || (*pcVar7 == '\0')) {
    pcVar7 = GetLMProfileString("aplus","asptop",(char *)0x0);
  }
  strncpy((char *)&szasptop,pcVar7,0x103);
  SetGlobalPointer("ASPTOP",&szasptop,1);
  local_6b0[0] = 0xff;
  local_6a8 = (HKEY)0x0;
  puVar9 = FUN_180033c00();
  local_688 = (char ****)0x0;
  uStack_680 = 0;
  local_678 = 0;
  local_670 = 0;
  sVar19 = 0xffffffffffffffff;
  do {
    sVar19 = sVar19 + 1;
  } while (puVar9[sVar19] != '\0');
  FUN_180006e90(&local_688,puVar9,sVar19);
  local_648 = (char *)0x0;
  uStack_640 = 0;
  local_638 = 0;
  local_630 = 0xf;
  local_648 = FUN_18001d210(&local_648,0x20);
  uVar12 = s_SOFTWARE_AspenTech_APrSystem__180040a00._8_8_;
  local_638 = 0x1d;
  local_630 = 0x1f;
  *(undefined8 *)local_648 = s_SOFTWARE_AspenTech_APrSystem__180040a00._0_8_;
  *(undefined8 *)(local_648 + 8) = uVar12;
  *(undefined8 *)(local_648 + 0x10) = s_SOFTWARE_AspenTech_APrSystem__180040a00._16_8_;
  *(undefined4 *)(local_648 + 0x18) = s_SOFTWARE_AspenTech_APrSystem__180040a00._24_4_;
  local_648[0x1c] = s_SOFTWARE_AspenTech_APrSystem__180040a00[0x1c];
  local_648[0x1d] = '\0';
  ppppcVar16 = (char ****)&local_688;
  if (0xf < local_670) {
    ppppcVar16 = local_688;
  }
  plVar10 = FUN_180024e40((longlong *)&local_648,ppppcVar16,local_678);
  local_668 = (undefined8 ****)*plVar10;
  lStack_660 = plVar10[1];
  local_658 = plVar10[2];
  uStack_650 = plVar10[3];
  plVar10[2] = 0;
  plVar10[3] = 0xf;
  *(undefined1 *)plVar10 = 0;
  if (uStack_650 - local_658 < 6) {
    ppppuVar11 = (undefined8 ****)FUN_180007e40(&local_668,6,0,"\\aplus",6);
  }
  else {
    ppppuVar11 = &local_668;
    if (0xf < uStack_650) {
      ppppuVar11 = local_668;
    }
    pvVar18 = (void *)((longlong)ppppuVar11 + local_658);
    local_658 = local_658 + 6;
    memmove(pvVar18,"\\aplus",6);
    *(undefined1 *)((longlong)pvVar18 + 6) = 0;
    ppppuVar11 = &local_668;
  }
  local_628 = (LPCSTR ***)0x0;
  pppuStack_620 = (undefined8 ***)0x0;
  local_618 = (undefined8 ***)0x0;
  pppuStack_610 = (undefined8 ***)0x0;
  local_628 = (LPCSTR ***)*ppppuVar11;
  pppuStack_620 = ppppuVar11[1];
  local_618 = ppppuVar11[2];
  pppuStack_610 = ppppuVar11[3];
  ppppuVar11[2] = (undefined8 ***)0x0;
  ppppuVar11[3] = (undefined8 ***)0xf;
  *(undefined1 *)ppppuVar11 = 0;
  if (0xf < uStack_650) {
    ppppuVar11 = local_668;
    if ((0xfff < uStack_650 + 1) &&
       (ppppuVar11 = (undefined8 ****)local_668[-1],
       0x1f < (ulonglong)((longlong)local_668 + (-8 - (longlong)ppppuVar11)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(ppppuVar11);
  }
  local_658 = _DAT_180041f70;
  uStack_650 = _UNK_180041f78;
  local_668 = (undefined8 ****)((ulonglong)local_668 & 0xffffffffffffff00);
  if (0xf < local_630) {
    pcVar7 = local_648;
    if ((0xfff < local_630 + 1) &&
       (pcVar7 = *(char **)(local_648 + -8), (char *)0x1f < local_648 + (-8 - (longlong)pcVar7))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(pcVar7);
  }
  local_638 = 0;
  local_630 = 0xf;
  local_648 = (char *)((ulonglong)local_648 & 0xffffffffffffff00);
  ppppCVar15 = (LPCSTR ***)&local_628;
  if ((undefined8 ***)0xf < pppuStack_610) {
    ppppCVar15 = local_628;
  }
  lpType = (LPDWORD)0x20019;
  LVar5 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000002,(LPCSTR)ppppCVar15,0,0x20019,&local_6a8);
  if (LVar5 == 0) {
    lpType = local_690;
    LVar5 = RegQueryValueExA(local_6a8,"asptop",(LPDWORD)0x0,lpType,local_338,local_6b0);
    if (LVar5 == 0) {
      lVar13 = 0;
      do {
        BVar2 = local_338[lVar13];
        *(BYTE *)((longlong)&szaprsys + lVar13) = BVar2;
        lVar13 = lVar13 + 1;
      } while (BVar2 != '\0');
      SetGlobalPointer("APRSYS");
    }
    RegCloseKey(local_6a8);
  }
  pcVar7 = GetProfileStringA("mm","mmFavorites",(char *)0x0);
  if ((pcVar7 == (char *)0x0) || (*pcVar7 == '\0')) {
    pcVar7 = GetLMProfileString("mm","mmFavorites",(char *)0x0);
  }
  strncpy((char *)&szmmFavorites,pcVar7,0x103);
  SetGlobalPointer("MMFAVORITES",&szmmFavorites,1);
  iVar6 = FUN_180033bd0();
  if (iVar6 == 1) {
    local_698 = (HKEY)0x0;
    local_5e8[0] = '\0';
    local_5e8[1] = '\0';
    local_5e8[2] = '\0';
    local_5e8[3] = '\0';
    local_5e8[4] = '\0';
    local_5e8[5] = '\0';
    local_5e8[6] = '\0';
    local_5e8[7] = '\0';
    local_5e8[8] = '\0';
    local_5e8[9] = 0;
    local_5d8[0] = '\0';
    local_5d8[1] = '\0';
    local_5d8[2] = '\0';
    local_5d8[3] = '\0';
    local_5d8[4] = '\0';
    local_5d8[5] = '\0';
    local_5d8[6] = '\0';
    local_5d8[7] = '\0';
    local_5d8[8] = '\0';
    local_5d8[9] = 0;
    local_538 = '\0';
    memset(local_537,0,0x1ff);
    ppppcVar16 = (char ****)&local_688;
    if (0xf < local_670) {
      ppppcVar16 = local_688;
    }
    FUN_180001ce0(&local_538,"SOFTWARE\\AspenTech\\Aspen Plus\\%s\\Compatibility\\Aspen Dynamics",
                  ppppcVar16,lpType);
    local_238 = '\0';
    memset(local_237,0,0x1ff);
    pcVar7 = getenv("AD_VSN");
    if (pcVar7 == (char *)0x0) {
      uVar12 = 0x20019;
      LVar5 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000002,&local_538,0,0x20019,&local_6a0);
      if (LVar5 == 0) {
        uVar17 = 1;
LAB_1800217c0:
        FUN_180001ce0(local_5c8,&DAT_180042040,(ulonglong)uVar17,uVar12);
        local_6b8 = 10;
        uVar12 = 0;
        LVar5 = RegQueryValueExA(local_6a0,local_5c8,(LPDWORD)0x0,(LPDWORD)0x0,local_5d8,&local_6b8)
        ;
        if (LVar5 != 0) goto code_r0x00018002180b;
        lVar13 = 0;
        do {
          pBVar1 = local_5d8 + lVar13;
          local_5e8[lVar13] = *pBVar1;
          lVar13 = lVar13 + 1;
        } while (*pBVar1 != '\0');
        RegCloseKey(local_6a0);
        goto LAB_18002183f;
      }
LAB_180021812:
      ppppcVar16 = (char ****)&local_688;
      if (0xf < local_670) {
        ppppcVar16 = local_688;
      }
      lVar13 = -(longlong)ppppcVar16;
      do {
        BVar2 = *(BYTE *)ppppcVar16;
        *(BYTE *)((longlong)ppppcVar16 + (longlong)(local_5e8 + lVar13)) = BVar2;
        ppppcVar16 = (char ****)((longlong)ppppcVar16 + 1);
      } while (BVar2 != '\0');
    }
    else {
      lVar13 = -(longlong)pcVar7;
      do {
        cVar3 = *pcVar7;
        pcVar7[(longlong)(local_5e8 + lVar13)] = cVar3;
        pcVar7 = pcVar7 + 1;
      } while (cVar3 != '\0');
    }
LAB_18002183f:
    wsprintfA(&local_238,"SOFTWARE\\AspenTech\\Aspen Dynamics\\%s\\Dir");
    LVar5 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000002,&local_238,0,0x20019,&local_698);
    if (LVar5 == 0) {
      g_DynamicsInstalled = 1;
      RegCloseKey(local_698);
    }
    SetGlobalPointer("DynamicsInstalled",&g_DynamicsInstalled,1);
    local_608 = (char *)0x0;
    uStack_600 = 0;
    local_5f8 = 0;
    local_5f0 = 0xf;
    local_608 = FUN_18001d210(&local_608,0x20);
    uVar12 = s_SOFTWARE_AspenTech_Aspen_Split__180042398._8_8_;
    local_5f8 = 0x1f;
    local_5f0 = 0x1f;
    *(undefined8 *)local_608 = s_SOFTWARE_AspenTech_Aspen_Split__180042398._0_8_;
    *(undefined8 *)(local_608 + 8) = uVar12;
    *(undefined8 *)(local_608 + 0x10) = s_SOFTWARE_AspenTech_Aspen_Split__180042398._16_8_;
    *(undefined4 *)(local_608 + 0x18) = s_SOFTWARE_AspenTech_Aspen_Split__180042398._24_4_;
    *(undefined2 *)(local_608 + 0x1c) = s_SOFTWARE_AspenTech_Aspen_Split__180042398._28_2_;
    local_608[0x1e] = s_SOFTWARE_AspenTech_Aspen_Split__180042398[0x1e];
    local_608[0x1f] = '\0';
    ppppcVar16 = (char ****)&local_688;
    if (0xf < local_670) {
      ppppcVar16 = local_688;
    }
    plVar10 = FUN_180024e40((longlong *)&local_608,ppppcVar16,local_678);
    pvVar18 = (void *)*plVar10;
    uVar4 = plVar10[3];
    plVar10[2] = 0;
    plVar10[3] = 0xf;
    *(undefined1 *)plVar10 = 0;
    if (0xf < local_5f0) {
      pcVar7 = local_608;
      if ((0xfff < local_5f0 + 1) &&
         (pcVar7 = *(char **)(local_608 + -8), (char *)0x1f < local_608 + (-8 - (longlong)pcVar7)))
      {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      FUN_180035134(pcVar7);
    }
    szAzeoGUI._0_1_ = 0;
    g_SplitInstalled = 0;
    SetGlobalPointer("SplitInstalled",&g_SplitInstalled,1);
    if (0xf < uVar4) {
      pvVar14 = pvVar18;
      if ((0xfff < uVar4 + 1) &&
         (pvVar14 = *(void **)((longlong)pvVar18 + -8),
         0x1f < (ulonglong)((longlong)pvVar18 + (-8 - (longlong)pvVar14)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      FUN_180035134(pvVar14);
    }
  }
  else {
    SetGlobalPointer("DynamicsInstalled",&g_DynamicsInstalled,1);
    SetGlobalPointer("SplitInstalled",&g_SplitInstalled,1);
  }
  uVar12 = SEInitialize(0);
  if ((undefined8 ***)0xf < pppuStack_610) {
    ppppCVar15 = local_628;
    if ((0xfff < (longlong)pppuStack_610 + 1U) &&
       (ppppCVar15 = (LPCSTR ***)local_628[-1],
       (LPCSTR)0x1f < (LPCSTR)((longlong)local_628 + (-8 - (longlong)ppppCVar15)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    uVar12 = FUN_180035134(ppppCVar15);
  }
  local_618 = (undefined8 ***)_DAT_180041f70;
  pppuStack_610 = (undefined8 ***)_UNK_180041f78;
  local_628 = (LPCSTR ***)((ulonglong)local_628 & 0xffffffffffffff00);
  if (0xf < local_670) {
    ppppcVar16 = local_688;
    if ((0xfff < local_670 + 1) &&
       (ppppcVar16 = (char ****)local_688[-1],
       (char *)0x1f < (char *)((longlong)local_688 + (-8 - (longlong)ppppcVar16)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    uVar12 = FUN_180035134(ppppcVar16);
  }
  return CONCAT71((int7)((ulonglong)uVar12 >> 8),1);
code_r0x00018002180b:
  uVar17 = uVar17 + 1;
  if (4 < (int)uVar17) goto LAB_180021812;
  goto LAB_1800217c0;
}

/* RVA 0x21b30 */
undefined8
FUN_180021b30(longlong *param_1,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2)

{
  wchar_t *bstrString;
  undefined8 local_res8;
  
  local_res8 = 0;
  if (*param_1 == 0) {
    return 0;
  }
  bstrString = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::AllocSysString
                         (param_2);
  (**(code **)(*(longlong *)*param_1 + 0x110))((longlong *)*param_1,bstrString,&local_res8);
  SysFreeString(bstrString);
  return local_res8;
}

/* RVA 0x21b90 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_180021b90(longlong param_1,uint param_2,IStream *param_3,IStream *param_4,ulonglong *param_5)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  longlong *plVar5;
  wchar_t *bstrString;
  LPCSTR lpCaption;
  HWND__ *hWnd;
  HMODULE hModule;
  FARPROC pFVar6;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar7;
  undefined8 *puVar8;
  BSTR pOVar9;
  char *pcVar10;
  undefined8 uVar11;
  ICXSDocumentV22 *pIVar12;
  longlong lVar13;
  uint uVar14;
  ulonglong uVar15;
  undefined4 uVar16;
  IStream *pIVar17;
  undefined1 auStackY_238 [32];
  int iVar18;
  uint local_1e8 [2];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_1e0 [8];
  ulonglong local_1d8;
  undefined8 *local_1d0;
  _union_2707 local_1c8;
  undefined8 local_1b0;
  _union_2707 local_1a8;
  _union_2707 local_190;
  _union_2707 local_178;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_160 [8];
  char local_158 [272];
  ulonglong local_48;
  
  local_48 = DAT_180052888 ^ (ulonglong)auStackY_238;
  uVar15 = 0;
  local_1e8[0] = 0;
  *param_5 = 0;
  iVar18 = (int)param_3;
  pcVar10 = (char *)param_4;
  if (param_2 < 0x4cf) {
    if (param_2 == 0x4ce) {
      pIVar12 = *(ICXSDocumentV22 **)(param_1 + 200);
      if (pIVar12 == (ICXSDocumentV22 *)0x0) {
        return 0;
      }
      pIVar17 = (IStream *)0x3ed;
      goto LAB_18002288b;
    }
    if (param_2 != 0x111) {
      return 0;
    }
    if (param_3 < (IStream *)0x9095) {
      if ((param_3 != (IStream *)0x9094) && (param_3 != (IStream *)0x80d2)) {
        return 0;
      }
      pIVar12 = *(ICXSDocumentV22 **)(param_1 + 200);
      if (pIVar12 == (ICXSDocumentV22 *)0x0) {
        return 0;
      }
      iVar18 = 0;
      goto LAB_180022888;
    }
    if (param_3 < (IStream *)0xdae4) {
      if (param_3 != (IStream *)0xdae3) {
        switch(param_3) {
        case (IStream *)0x9095:
        case (IStream *)0x9096:
        case (IStream *)0x9097:
        case (IStream *)0x9098:
        case (IStream *)0x9099:
        case (IStream *)0x909d:
        case (IStream *)0x90be:
        case (IStream *)0x90bf:
        case (IStream *)0x90c1:
          goto switchD_180021c5a_caseD_9095;
        default:
          return 0;
        case (IStream *)0x90ac:
        case (IStream *)0x90ad:
        case (IStream *)0x90ae:
          break;
        }
      }
switchD_180021c5a_caseD_90ac:
      pIVar12 = *(ICXSDocumentV22 **)(param_1 + 200);
      if (pIVar12 == (ICXSDocumentV22 *)0x0) {
        return 0;
      }
      param_3 = (IStream *)0x3ea;
    }
    else {
      switch(param_3) {
      case (IStream *)0xdae4:
      case (IStream *)0xdae5:
      case (IStream *)0xdae6:
      case (IStream *)0xdb57:
      case (IStream *)0xdb58:
        goto switchD_180021c5a_caseD_90ac;
      default:
        goto switchD_180021c5a_caseD_909a;
      case (IStream *)0xdaea:
        pIVar12 = *(ICXSDocumentV22 **)(param_1 + 200);
        if (pIVar12 == (ICXSDocumentV22 *)0x0) {
          return 0;
        }
        param_3 = (IStream *)0x3fe;
        break;
      case (IStream *)0xdaf5:
      case (IStream *)0xdb0a:
switchD_180021c5a_caseD_9095:
        pIVar12 = *(ICXSDocumentV22 **)(param_1 + 200);
        if (pIVar12 == (ICXSDocumentV22 *)0x0) {
          return 0;
        }
        iVar18 = 0;
      }
    }
    goto LAB_180022888;
  }
  iVar3 = (int)param_4;
  switch(param_2) {
  case 0x4d4:
    if (*(ICXSDocumentV22 **)(param_1 + 200) != (ICXSDocumentV22 *)0x0) {
      CxsRaiseCustomEvent(*(ICXSDocumentV22 **)(param_1 + 200),(char *)0x0,0x3ed,(char *)0x0,iVar18)
      ;
    }
    pIVar12 = *(ICXSDocumentV22 **)(param_1 + 200);
    if (pIVar12 == (ICXSDocumentV22 *)0x0) {
      return 0;
    }
    if (param_3 != (IStream *)0x13) {
      return 0;
    }
    iVar18 = 0x75;
    param_3 = (IStream *)0x3ed;
    goto LAB_180022888;
  case 0x4de:
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1e0,(char *)param_3);
    plVar5 = (longlong *)HappGetTree();
    if (plVar5 != (longlong *)0x0) {
      local_1d8 = 0;
      bstrString = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                   AllocSysString(local_1e0);
      (**(code **)(*plVar5 + 0x110))(plVar5,bstrString,&local_1d8);
      SysFreeString(bstrString);
      uVar15 = local_1d8;
      (**(code **)(*plVar5 + 0x10))(plVar5);
    }
    *param_5 = uVar15;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1e0);
    break;
  case 0x4e1:
    if (*(longlong *)(param_1 + 0xc0) != 0) {
      uVar11 = FUN_18001b0b0(*(longlong *)(param_1 + 0xc0),(longlong *)param_3,param_4);
      *param_5 = (longlong)(int)uVar11;
    }
    break;
  case 0x4e2:
    if (param_3 == (IStream *)0x0) {
      return 0;
    }
    lpCaption = (LPCSTR)MVGetI18nProductName();
    hWnd = ApwnContextHWND();
    iVar3 = MessageBoxA(hWnd,(LPCSTR)param_3->lpVtbl,lpCaption,*(UINT *)&param_3[1].lpVtbl);
    param_3[2].lpVtbl = (IStreamVtbl *)(longlong)iVar3;
  case 0x532:
    CxsRaiseCustomEvent(*(ICXSDocumentV22 **)(param_1 + 200),(char *)0x0,1000,(char *)param_4,iVar18
                       );
    if (param_4 != (IStream *)0x0) {
      GlobalFree(param_4);
    }
    break;
  case 0x4ed:
    pIVar12 = *(ICXSDocumentV22 **)(param_1 + 200);
    if (pIVar12 == (ICXSDocumentV22 *)0x0) {
      return 0;
    }
    pIVar17 = (IStream *)0x4ed;
    goto LAB_18002288b;
  case 0x4f0:
    pIVar12 = *(ICXSDocumentV22 **)(param_1 + 200);
    if (pIVar12 == (ICXSDocumentV22 *)0x0) {
      return 0;
    }
    param_3 = (IStream *)0x3ef;
    goto LAB_180022888;
  case 0x4f3:
    pIVar12 = *(ICXSDocumentV22 **)(param_1 + 200);
    if (pIVar12 == (ICXSDocumentV22 *)0x0) {
      return 0;
    }
    iVar18 = 0;
    pIVar17 = (IStream *)0x4f3;
    goto LAB_18002288b;
  case 0x4f4:
    pIVar12 = *(ICXSDocumentV22 **)(param_1 + 200);
    if (pIVar12 == (ICXSDocumentV22 *)0x0) {
      return 0;
    }
    if (*(longlong *)(param_1 + 0xc0) == 0) {
      return 0;
    }
    if (*(char *)(*(longlong *)(param_1 + 0xc0) + 200) != '\0') {
      return 0;
    }
    iVar18 = 0;
    pIVar17 = (IStream *)0x4f4;
    goto LAB_18002288b;
  case 0x4f5:
    pIVar12 = *(ICXSDocumentV22 **)(param_1 + 200);
    if (pIVar12 == (ICXSDocumentV22 *)0x0) {
      return 0;
    }
    iVar18 = 0;
    pIVar17 = (IStream *)0x4f5;
    goto LAB_18002288b;
  case 0x4f7:
    pIVar12 = *(ICXSDocumentV22 **)(param_1 + 200);
    if (pIVar12 == (ICXSDocumentV22 *)0x0) {
      return 0;
    }
    iVar18 = 0;
    pcVar10 = (char *)0x0;
    pIVar17 = (IStream *)0x3fa;
    goto LAB_18002288d;
  case 0x4f8:
    pIVar12 = *(ICXSDocumentV22 **)(param_1 + 200);
    if (pIVar12 == (ICXSDocumentV22 *)0x0) {
      return 0;
    }
    param_3 = (IStream *)0x3fc;
    goto LAB_180022888;
  case 0x4f9:
    pIVar12 = *(ICXSDocumentV22 **)(param_1 + 200);
    if (pIVar12 == (ICXSDocumentV22 *)0x0) {
      return 0;
    }
    param_3 = (IStream *)0x4f9;
    goto LAB_180022888;
  case 0x4fa:
    pIVar12 = *(ICXSDocumentV22 **)(param_1 + 200);
    if (pIVar12 == (ICXSDocumentV22 *)0x0) {
      return 0;
    }
    iVar18 = 0;
    pcVar10 = (char *)0x0;
    pIVar17 = (IStream *)0x4fa;
    param_3 = param_4;
    goto LAB_18002288d;
  case 0x4fd:
    pIVar12 = *(ICXSDocumentV22 **)(param_1 + 200);
    if (pIVar12 == (ICXSDocumentV22 *)0x0) {
      return 0;
    }
    iVar18 = 0;
    pcVar10 = (char *)0x0;
    pIVar17 = (IStream *)0x4fd;
    goto LAB_18002288d;
  case 0x4fe:
    pIVar12 = *(ICXSDocumentV22 **)(param_1 + 200);
    if (pIVar12 == (ICXSDocumentV22 *)0x0) {
      return 0;
    }
    iVar18 = 0;
    pcVar10 = (char *)0x0;
    pIVar17 = (IStream *)0x4fe;
    goto LAB_18002288d;
  case 0x52d:
    if (*(ICXSDocumentV22 **)(param_1 + 200) == (ICXSDocumentV22 *)0x0) {
      return 0;
    }
    if (param_4 == (IStream *)0x4) {
      CxsRaiseCustomEvent(*(ICXSDocumentV22 **)(param_1 + 200),(char *)0x0,0x3ed,(char *)0x0,0x6d);
    }
    SimReflect(3);
    iVar18 = 0x75;
    param_3 = (IStream *)0x3ed;
    pIVar12 = *(ICXSDocumentV22 **)(param_1 + 200);
    goto LAB_180022888;
  case 0x533:
    HappFireUpdateMessage(0xeb,&DAT_18003ad3b,0);
    break;
  case 0x534:
    if ((((((param_3 == (IStream *)0x1) || (param_3 == (IStream *)0x5)) ||
          (param_3 == (IStream *)0x22)) ||
         ((((ulonglong)((longlong)&param_3[-4].lpVtbl + 1U) & 0xfffffffffffffff5) == 0 &&
          (param_3 != (IStream *)0x29)))) &&
        ((param_3 == (IStream *)0x1f || (param_3 == (IStream *)0x22)))) &&
       (*(int *)(param_1 + 0x2ec) != -1)) {
      SimSetEOSolveStatus(param_1 + 0x2f0);
    }
    HappFireUpdateMessage(0xec,&DAT_18003ad3b,0);
    break;
  case 0x536:
    if ((*(ICXSDocumentV22 **)(param_1 + 200) != (ICXSDocumentV22 *)0x0) &&
       (CxsRaiseCustomEvent(*(ICXSDocumentV22 **)(param_1 + 200),(char *)0x0,0x3ec,(char *)param_4,
                            -1), param_4 != (IStream *)0x0)) {
      free(param_4);
    }
    break;
  case 0x53a:
    pIVar12 = *(ICXSDocumentV22 **)(param_1 + 200);
    if (pIVar12 == (ICXSDocumentV22 *)0x0) {
      return 0;
    }
    pIVar17 = (IStream *)0x3f1;
    goto LAB_18002288b;
  case 0x53b:
    pIVar12 = *(ICXSDocumentV22 **)(param_1 + 200);
    if (pIVar12 == (ICXSDocumentV22 *)0x0) {
      return 0;
    }
    pIVar17 = (IStream *)0x3f2;
    goto LAB_18002288b;
  case 0x53c:
    pIVar12 = *(ICXSDocumentV22 **)(param_1 + 200);
    if (pIVar12 == (ICXSDocumentV22 *)0x0) {
      return 0;
    }
    pIVar17 = (IStream *)0x3f3;
    goto LAB_18002288b;
  case 0x540:
    DAT_1800536bc = DAT_1800536bc + 1;
    if (iVar18 == 1) {
      pcVar10 = getenv("SAVESUM");
      if (pcVar10 == (char *)0x0) {
        local_1c8.decVal.u2 = (_union_1719)(_struct_1720)0x0;
        local_1c8._16_8_ = 7;
        local_1b0 = 0xf;
        local_1c8.n2.wReserved2 = DAT_1800423d0._4_2_;
        local_1c8._0_4_ = (undefined4)DAT_1800423d0;
        local_1c8.n2.wReserved3._0_1_ = DAT_1800423d0._6_1_;
        local_1c8.n2.wReserved3._1_1_ = 0;
        hModule = FUN_18001f530((longlong *)&local_1c8);
        pFVar6 = GetProcAddress(hModule,"APtmpfil");
        FreeLibrary(hModule);
        iVar3 = FUN_180033bd0();
        pcVar10 = ".aprsum";
        if (iVar3 == 1) {
          pcVar10 = ".sum";
        }
        FUN_180001ce0(local_158,&DAT_1800423e4,pFVar6,pcVar10);
        remove(local_158);
      }
    }
    else if (((iVar18 == 0x101f) || (iVar18 == 0x1022)) && (*(int *)(param_1 + 0x2ec) != -1)) {
      SimSetEOSolveStatus(param_1 + 0x2f0);
    }
    if (DAT_1800536bc < 2) {
      SimReflect(0,(ulonglong)param_4 & 0xffffffff,param_3);
    }
    if (*(ICXSDocumentV22 **)(param_1 + 200) != (ICXSDocumentV22 *)0x0) {
      CxsRaiseCustomEvent(*(ICXSDocumentV22 **)(param_1 + 200),(char *)0x0,0x3ed,(char *)0x0,0x6f);
      CxsRaiseCustomEvent(*(ICXSDocumentV22 **)(param_1 + 200),(char *)0x0,0x3ed,(char *)0x0,0x75);
      if (((*(char *)(param_1 + 0xd8) != '\0') && (*(int *)(param_1 + 0xdc) != 0)) &&
         ((*(ICXSDocumentV22 **)(param_1 + 200) != (ICXSDocumentV22 *)0x0 && (iVar18 < 0xc)))) {
        CxsRaiseCustomEventWait
                  (*(ICXSDocumentV22 **)(param_1 + 200),(char *)0x0,0x3ed,(char *)0x0,0x7b,0,
                   (long *)local_1e8);
      }
    }
    iVar18 = GRinqsmf();
    if (iVar18 == 0) {
      HappFireCalculationStopped();
      HappFireEngineCommandCompleted();
      DAT_1800536bc = DAT_1800536bc + -1;
    }
    else {
      HappFireCalculationCompleted();
      HappFireEngineCommandCompleted();
      DAT_1800536bc = DAT_1800536bc + -1;
    }
    break;
  case 0x541:
    if (*(longlong *)(param_1 + 0xc0) != 0) {
      FUN_18000bfd0(*(longlong *)(param_1 + 0xc0));
    }
    break;
  case 0x543:
    ApwnContextSyncCPMessage((__uint64)param_3,(__int64)param_4);
    break;
  case 0x544:
    if (param_3 != (IStream *)0x0) {
      strncmp((char *)param_3,"solve",5);
    }
    iVar18 = Ordinal_73(param_3,(ulonglong)param_4 & 0xffffffff,0);
    *param_5 = (longlong)iVar18;
    break;
  case 0x545:
    pIVar12 = *(ICXSDocumentV22 **)(param_1 + 200);
    if (pIVar12 == (ICXSDocumentV22 *)0x0) {
      return 0;
    }
    pIVar17 = (IStream *)0x3f8;
    goto LAB_18002288b;
  case 0x548:
    pIVar12 = *(ICXSDocumentV22 **)(param_1 + 200);
    if (pIVar12 == (ICXSDocumentV22 *)0x0) {
      return 0;
    }
    iVar18 = 0;
    pcVar10 = "Kernel Debugger";
    pIVar17 = (IStream *)0x3f8;
    goto LAB_18002288d;
  case 0x54b:
    local_190._0_8_ = 0;
    local_190.decVal.u2 = (_union_1719)(_struct_1720)0x0;
    local_190._16_8_ = 0;
    VariantInit((VARIANTARG *)&local_190.n2);
    local_1a8._0_8_ = 0;
    local_1a8.decVal.u2 = (_union_1719)(_struct_1720)0x0;
    local_1a8._16_8_ = 0;
    VariantInit((VARIANTARG *)&local_1a8.n2);
    local_1c8._0_8_ = 0;
    local_1c8.decVal.u2 = (_union_1719)(_struct_1720)0x0;
    local_1c8._16_8_ = 0;
    VariantInit((VARIANTARG *)&local_1c8.n2);
    local_178._0_8_ = 0;
    local_178.decVal.u2 = (_union_1719)(_struct_1720)0x0;
    local_178._16_8_ = 0;
    VariantInit((VARIANTARG *)&local_178.n2);
    if (param_3 != (IStream *)0x0) {
      FUN_180022ad0((VARIANTARG *)&local_190.n2,param_3,0,(undefined *)0x0,0);
      FUN_180022ad0((VARIANTARG *)&local_1a8.n2,param_3,0,(undefined *)0x0,0);
      (*param_3->lpVtbl->Release)(param_3);
    }
    VariantChangeType((VARIANTARG *)&local_1c8.n2,(VARIANTARG *)&local_190.n2,0,8);
    VariantChangeType((VARIANTARG *)&local_178.n2,(VARIANTARG *)&local_1a8.n2,0,8);
    SysStringLen((BSTR)local_178.decVal.u2);
    SysStringLen((BSTR)local_1c8.decVal.u2);
    FUN_180001ce0(local_158,"%I64d %d %d %S %d %d %S",param_4,local_190._0_8_ & 0xffff);
    if (*(ICXSDocumentV22 **)(param_1 + 200) != (ICXSDocumentV22 *)0x0) {
      CxsRaiseCustomEvent(*(ICXSDocumentV22 **)(param_1 + 200),local_158,0x12f,(char *)0x0,iVar3);
    }
    uVar11 = local_190._8_8_;
    if (param_4 == (IStream *)0x6) {
      *(undefined4 *)(param_1 + 0x2ec) = 7;
      *(undefined8 *)(param_1 + 0x2f0) = 0x6e776f6e6b6e75;
    }
    else if (param_4 == (IStream *)0x7) {
      if (local_190.n2.vt == 8) {
        puVar8 = operator_new(0x18);
        if (puVar8 == (undefined8 *)0x0) {
          puVar8 = (undefined8 *)0x0;
        }
        else {
          puVar8[1] = 0;
          *(undefined4 *)(puVar8 + 2) = 1;
          local_1d0 = puVar8;
          pOVar9 = SysAllocString((OLECHAR *)uVar11);
          *puVar8 = pOVar9;
          if ((pOVar9 == (BSTR)0x0) && (uVar11 != 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_180034a60(0x8007000e);
          }
        }
        local_1d0 = puVar8;
        if (puVar8 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_180034a60(0x8007000e);
        }
        pcVar10 = (char *)puVar8[1];
        if (pcVar10 == (char *)0x0) {
          pcVar10 = FUN_180034b30((LPCWSTR)*puVar8);
          puVar8[1] = pcVar10;
        }
        lVar13 = (param_1 + 0x2f0) - (longlong)pcVar10;
        do {
          cVar2 = *pcVar10;
          pcVar10[lVar13] = cVar2;
          pcVar10 = pcVar10 + 1;
        } while (cVar2 != '\0');
        LOCK();
        piVar1 = (int *)(puVar8 + 2);
        iVar18 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar18 == 1) {
          if ((BSTR)*puVar8 != (BSTR)0x0) {
            SysFreeString((BSTR)*puVar8);
            *puVar8 = 0;
          }
          if ((void *)puVar8[1] != (void *)0x0) {
            operator_delete__((void *)puVar8[1]);
            puVar8[1] = 0;
          }
          FUN_180035134(puVar8);
        }
      }
      else {
        *(undefined1 *)(param_1 + 0x2f0) = 0;
      }
      iVar18 = strcmp((char *)(param_1 + 0x2f0),"root container");
      if (iVar18 == 0) {
        *(undefined4 *)(param_1 + 0x2f0) = s_Plant_180042430._0_4_;
        *(undefined2 *)(param_1 + 0x2f4) = s_Plant_180042430._4_2_;
      }
      uVar16 = 0xffffffff;
      if (local_1a8.n2.vt == 3) {
        uVar16 = local_1a8._8_4_;
      }
      *(undefined4 *)(param_1 + 0x2ec) = uVar16;
    }
    VariantClear((VARIANTARG *)&local_178.n2);
    VariantClear((VARIANTARG *)&local_1c8.n2);
    VariantClear((VARIANTARG *)&local_1a8.n2);
    VariantClear((VARIANTARG *)&local_190.n2);
    break;
  case 0x54e:
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1e0,(char *)param_4);
    iVar3 = 0;
    while( true ) {
      iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                        (local_1e0,',',iVar3);
      if (iVar4 < 1) {
        pCVar7 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                           (local_1e0,(int)local_160);
        uVar14 = (uint)uVar15 | 2;
      }
      else {
        pCVar7 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                           (local_1e0,(int)&local_1d0,iVar3);
        uVar14 = (uint)uVar15 | 1;
      }
      local_1e8[0] = uVar14;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1d8,pCVar7)
      ;
      if ((uVar14 & 2) != 0) {
        uVar14 = uVar14 & 0xfffffffd;
        local_1e8[0] = uVar14;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_160);
      }
      if ((uVar14 & 1) != 0) {
        uVar14 = uVar14 & 0xfffffffe;
        local_1e8[0] = uVar14;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1d0);
      }
      uVar15 = (ulonglong)uVar14;
      pCVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Trim
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          &local_1d8);
      SetBlockEOStatus(*(undefined8 *)pCVar7);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1d8);
      if (iVar4 < 0) break;
      iVar3 = iVar4 + 1;
    }
    if (*(ICXSDocumentV22 **)(param_1 + 200) != (ICXSDocumentV22 *)0x0) {
      CxsRaiseCustomEvent(*(ICXSDocumentV22 **)(param_1 + 200),(char *)0x0,0x54e,(char *)param_4,
                          iVar18);
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1e0);
    break;
  case 0x552:
    *(undefined4 *)&param_4->lpVtbl = 0;
    HappFireBeforeCalculate((ulonglong)param_3 & 0xffffffff,param_4);
    break;
  case 0x559:
    if (iVar3 == 1) {
      if (*(ICXSDocumentV22 **)(param_1 + 200) != (ICXSDocumentV22 *)0x0) {
        CxsRaiseCustomEvent(*(ICXSDocumentV22 **)(param_1 + 200),(char *)0x0,0x3f0,(char *)param_3,1
                           );
      }
      HappFireUpdateMessage(0x133,param_3,0);
      return 0;
    }
    HappFireUpdateMessage(0x134,0,0);
    pIVar12 = *(ICXSDocumentV22 **)(param_1 + 200);
    if (pIVar12 == (ICXSDocumentV22 *)0x0) {
      return 0;
    }
    iVar18 = 0;
    param_3 = (IStream *)0x3f0;
    goto LAB_180022888;
  case 0x55a:
    if (*(ICXSDocumentV22 **)(param_1 + 200) != (ICXSDocumentV22 *)0x0) {
      CxsRaiseCustomEvent(*(ICXSDocumentV22 **)(param_1 + 200),(char *)0x0,0x3ee,(char *)param_4,-1)
      ;
      free(param_4);
    }
    break;
  case 0x55b:
    pIVar12 = *(ICXSDocumentV22 **)(param_1 + 200);
    if (pIVar12 == (ICXSDocumentV22 *)0x0) {
      return 0;
    }
    iVar18 = 0x76;
    param_3 = (IStream *)0x3ed;
    goto LAB_180022888;
  case 0x55c:
    pIVar17 = (IStream *)0x55c;
    pIVar12 = *(ICXSDocumentV22 **)(param_1 + 200);
    goto LAB_18002288b;
  case 0x55d:
    pIVar12 = *(ICXSDocumentV22 **)(param_1 + 200);
    if (pIVar12 == (ICXSDocumentV22 *)0x0) {
      return 0;
    }
    param_3 = (IStream *)0x55d;
    iVar18 = iVar3;
LAB_180022888:
    pcVar10 = (char *)0x0;
    pIVar17 = param_3;
    goto LAB_18002288b;
  case 0x565:
    pIVar12 = *(ICXSDocumentV22 **)(param_1 + 200);
    if (pIVar12 == (ICXSDocumentV22 *)0x0) {
      return 0;
    }
    iVar18 = 0;
    pIVar17 = (IStream *)0x565;
LAB_18002288b:
    param_3 = (IStream *)0x0;
LAB_18002288d:
    CxsRaiseCustomEvent(pIVar12,(char *)param_3,(__uint64)pIVar17,pcVar10,iVar18);
  }
switchD_180021c5a_caseD_909a:
  return 0;
}

/* RVA 0x22ad0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HRESULT FUN_180022ad0(VARIANTARG *param_1,IStream *param_2,VARTYPE param_3,undefined *param_4,
                     uint param_5)

{
  longlong *plVar1;
  HRESULT HVar2;
  HRESULT HVar3;
  uint uVar4;
  UINT len;
  ulonglong uVar5;
  BSTR bstrString;
  BSTR bstrString_00;
  IID *riid;
  undefined1 auStackY_b8 [32];
  ULONG local_88 [2];
  undefined8 local_80;
  VARTYPE local_78 [4];
  undefined8 local_70;
  short local_68 [4];
  BSTR local_60;
  ULARGE_INTEGER local_58;
  longlong local_50;
  ulonglong local_48;
  
  local_48 = DAT_180052888 ^ (ulonglong)auStackY_b8;
  if (param_2 == (IStream *)0x0) {
    return -0x7ff8ffa9;
  }
  HVar2 = VariantClear(param_1);
  if (HVar2 < 0) {
    return HVar2;
  }
  local_78[0] = 0;
  local_88[0] = 0;
  HVar2 = (*param_2->lpVtbl->Read)(param_2,local_78,2,local_88);
  if ((HVar2 == 1) || ((local_88[0] != 2 && (HVar2 == 0)))) {
    return -0x7fffbffb;
  }
  if (HVar2 < 0) {
    return HVar2;
  }
  if ((param_3 != 0) && (local_78[0] != param_3)) {
    return -0x7fffbffb;
  }
  (param_1->n1).n2.vt = local_78[0];
  local_88[0] = 0;
  switch(local_78[0]) {
  case 2:
  case 0xb:
  case 0x12:
    local_88[0] = 2;
    break;
  case 3:
  case 4:
  case 10:
  case 0x13:
  case 0x16:
  case 0x17:
    local_88[0] = 4;
    break;
  case 5:
  case 6:
  case 7:
  case 0x14:
  case 0x15:
    local_88[0] = 8;
    break;
  default:
    SysFreeString((BSTR)0x0);
    bstrString = (BSTR)0x0;
    local_60 = (BSTR)0x0;
    HVar2 = (*param_2->lpVtbl->Seek)(param_2,(LARGE_INTEGER)0x0,1,&local_58);
    local_70 = (longlong *)((ulonglong)local_70._4_4_ << 0x20);
    local_80 = (longlong *)((ulonglong)local_80._4_4_ << 0x20);
    HVar3 = (*param_2->lpVtbl->Read)(param_2,&local_80,4,(ULONG *)&local_70);
    if (HVar3 < 0) {
LAB_180022e3e:
      if (-1 < HVar2) {
        (*param_2->lpVtbl->Seek)(param_2,(LARGE_INTEGER)local_58,0,(ULARGE_INTEGER *)0x0);
      }
LAB_180022e56:
      if (HVar3 < 0) {
        (*param_2->lpVtbl->Seek)(param_2,(LARGE_INTEGER)0xfffffffffffffffe,1,(ULARGE_INTEGER *)0x0);
        (param_1->n1).n2.vt = 0;
        bstrString_00 = bstrString;
        goto LAB_180022ea3;
      }
    }
    else {
      if ((ULONG)local_70 != 4) {
        HVar3 = -0x7fffbffb;
        goto LAB_180022e3e;
      }
      if ((uint)local_80 != 0) {
        if ((uint)local_80 < 2) {
          HVar3 = -0x7fffbffb;
          goto LAB_180022e3e;
        }
        if (0x100000 < (uint)local_80) {
          HVar3 = -0x7ff8fffb;
          goto LAB_180022e3e;
        }
        len = (uint)local_80 - 2;
        local_80 = (longlong *)CONCAT44(local_80._4_4_,len);
        bstrString = SysAllocStringByteLen((LPCSTR)0x0,len);
        local_60 = bstrString;
        if (bstrString == (BSTR)0x0) {
          HVar3 = -0x7ff8fff2;
          goto LAB_180022e3e;
        }
        HVar3 = (*param_2->lpVtbl->Read)(param_2,bstrString,(uint)local_80,(ULONG *)&local_70);
        if (HVar3 < 0) {
LAB_180022e2a:
          SysFreeString(bstrString);
          local_60 = (BSTR)0x0;
          goto LAB_180022e3a;
        }
        if ((ULONG)local_70 != (uint)local_80) {
LAB_180022e25:
          HVar3 = -0x7fffbffb;
          goto LAB_180022e2a;
        }
        HVar3 = (*param_2->lpVtbl->Read)(param_2,local_68,2,(ULONG *)&local_70);
        if (HVar3 < 0) goto LAB_180022e2a;
        if (((ULONG)local_70 != 2) || (local_68[0] != 0)) goto LAB_180022e25;
        goto LAB_180022e56;
      }
LAB_180022e3a:
      bstrString = (BSTR)0x0;
      if (HVar3 < 0) goto LAB_180022e3e;
    }
    (param_1->n1).n2.vt = 8;
    bstrString_00 = (BSTR)0x0;
    (param_1->n1).decVal.u2.Lo64 = (ULONGLONG)bstrString;
    if (local_78[0] != 8) {
      HVar3 = VariantChangeType(param_1,param_1,0,local_78[0]);
    }
LAB_180022ea3:
    SysFreeString(bstrString_00);
    return HVar3;
  case 9:
  case 0xd:
    riid = (IID *)&DAT_180042020;
    if (local_78[0] == 0xd) {
      riid = (IID *)&DAT_180041330;
    }
    (param_1->n1).decVal.u2.Lo64 = 0;
    HVar2 = ReadClassStm(param_2,(CLSID *)&local_58.s);
    if (HVar2 < 0) goto LAB_180022cd5;
    local_80 = (longlong *)0x0;
    if (param_5 == 0) {
      if ((param_4 == (undefined *)0x0) ||
         (HVar2 = (*(code *)param_4)(&local_58,riid,&local_80), -1 < HVar2)) {
        if (local_80 == (longlong *)0x0) {
LAB_180022c43:
          HVar2 = CoCreateInstance((IID *)&local_58.s,(LPUNKNOWN)0x0,0x415,riid,(LPVOID *)&local_80)
          ;
          if (HVar2 < 0) goto LAB_180022cca;
        }
        local_70 = (longlong *)0x0;
        HVar2 = (**(code **)*local_80)(local_80,&DAT_180042030,&local_70);
        if (-1 < HVar2) {
          HVar2 = (**(code **)(*local_70 + 0x28))(local_70,param_2);
          plVar1 = local_80;
          if (-1 < HVar2) {
            local_80 = (longlong *)0x0;
            (param_1->n1).n2.n3.llVal = (LONGLONG)plVar1;
          }
        }
        if (local_70 != (longlong *)0x0) {
          (**(code **)(*local_70 + 0x10))(local_70);
        }
      }
    }
    else {
      HVar2 = -0x7ff8fffb;
      uVar5 = 0;
      do {
        if ((local_58.QuadPart == *(ULONGLONG *)(param_4 + uVar5 * 0x10)) &&
           (local_50 == *(longlong *)(param_4 + uVar5 * 0x10 + 8))) goto LAB_180022c43;
        uVar4 = (int)uVar5 + 1;
        uVar5 = (ulonglong)uVar4;
      } while (uVar4 < param_5);
    }
LAB_180022cca:
    if (local_80 != (longlong *)0x0) {
      (**(code **)(*local_80 + 0x10))();
    }
LAB_180022cd5:
    HVar3 = 0;
    if (HVar2 != -0x7ffbfeac) {
      HVar3 = HVar2;
    }
    return HVar3;
  case 0x10:
  case 0x11:
    local_88[0] = 1;
  }
  HVar2 = (*param_2->lpVtbl->Read)(param_2,&(param_1->n1).n2.n3,local_88[0],(ULONG *)0x0);
  if (HVar2 == 1) {
    return -0x7fffbffb;
  }
  return HVar2;
}

/* RVA 0x22f10 */
undefined8 FUN_180022f10(longlong param_1)

{
  if (*(ICXSDocumentV22 **)(param_1 + 0xc0) == (ICXSDocumentV22 *)0x0) {
    return 0x80004005;
  }
  CxsRaiseCustomEvent(*(ICXSDocumentV22 **)(param_1 + 0xc0),"<RunLineSizing />",0x3fa,(char *)0x0,0)
  ;
  return 0;
}

/* RVA 0x22f50 */
undefined8 FUN_180022f50(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  int iVar3;
  
  plVar1 = (longlong *)(param_1 + 200);
  plVar2 = (longlong *)*plVar1;
  if (plVar2 != (longlong *)0x0) {
    *plVar1 = 0;
    (**(code **)(*plVar2 + 0x10))();
  }
  if (param_2 == (longlong *)0x0) {
    if (*(longlong *)(param_1 + 0xc0) != 0) {
      ApwnContextDocumentClose(*(void **)(*(longlong *)(param_1 + 0xc0) + 0xb0));
    }
  }
  else {
    plVar2 = (longlong *)*plVar1;
    if (plVar2 != param_2) {
      iVar3 = (**(code **)*param_2)(param_2,&DAT_180042048,plVar1);
      if (iVar3 < 0) {
        *plVar1 = 0;
      }
      if (plVar2 != (longlong *)0x0) {
        (**(code **)(*plVar2 + 0x10))(plVar2);
        return 0;
      }
    }
  }
  return 0;
}

/* RVA 0x23000 */
undefined8 FUN_180023000(longlong param_1,int param_2)

{
  if (param_2 == 0) {
    return 0x80004001;
  }
  if (*(ICXSDocumentV22 **)(param_1 + 0xd0) != (ICXSDocumentV22 *)0x0) {
    CxsRaiseCustomEvent(*(ICXSDocumentV22 **)(param_1 + 0xd0),(char *)0x0,0x3f8,"Home Tab",0);
  }
  return 0;
}

/* RVA 0x23050 */
undefined8 FUN_180023050(longlong param_1,int param_2)

{
  if (param_2 == 0) {
    return 0x80004001;
  }
  if (*(ICXSDocumentV22 **)(param_1 + 0xd0) == (ICXSDocumentV22 *)0x0) {
    return 0x80004005;
  }
  CxsRaiseCustomEvent(*(ICXSDocumentV22 **)(param_1 + 0xd0),(char *)0x0,0x3f8,"Control Panel",0);
  return 0;
}

/* RVA 0x230a0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FUN_1800230a0(undefined8 param_1,char *param_2)

{
  char cVar1;
  DWORD DVar2;
  int iVar3;
  BOOL BVar4;
  ulonglong uVar5;
  char *pcVar6;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar7;
  longlong lVar8;
  bool bVar9;
  undefined1 auStack_4b8 [32];
  undefined1 *local_498;
  char *local_488;
  char *local_480;
  LPSTR local_478;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_470 [8];
  LPSTR local_468 [2];
  char local_458 [272];
  undefined1 local_348 [272];
  CHAR local_238 [272];
  CHAR local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_180052888 ^ (ulonglong)auStack_4b8;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_480);
  DVar2 = GetFullPathNameA(param_2,0x104,local_458,&local_478);
  if (DVar2 == 0) {
    lVar8 = -(longlong)param_2;
    do {
      cVar1 = *param_2;
      param_2[(longlong)(local_458 + lVar8)] = cVar1;
      param_2 = param_2 + 1;
    } while (cVar1 != '\0');
  }
  if (local_458[0] == '\0') {
LAB_18002332e:
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_488);
    pcVar6 = GetProfileStringA("mmgini","startupdir","");
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_488,pcVar6);
    if (*(int *)(local_488 + -0x10) == 0) {
LAB_18002339a:
      local_498 = local_348;
      iVar3 = SHGetFolderPathA(0,0x8005,0,0);
      if (-1 < iVar3) {
        pcVar6 = FUN_180033bc0();
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_488,
                   "%s\\Aspentech\\Aspen Plus %s",local_348,pcVar6);
        pCVar7 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                 ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                 CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                           (local_470,
                            (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                             *)&local_488);
        FUN_18001f880(pCVar7);
      }
      if (*(int *)(local_488 + -0x10) != 0) goto LAB_1800233ff;
    }
    else {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::TrimLeft
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_488);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::TrimRight
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_488);
      MMReplaceEnvironmentVariables(local_488);
      if (*(int *)(local_488 + -0x10) == 0) goto LAB_18002339a;
LAB_1800233ff:
      DVar2 = GetFullPathNameA(local_488,0x104,local_128,local_468);
      if (DVar2 != 0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_488,
                   local_128);
      }
      DVar2 = GetFileAttributesA(local_488);
      if ((DVar2 & 0x10) != 0) {
        uVar5 = FUN_18001f770(param_1,local_488,2);
        if ((char)uVar5 == '\0') {
          iVar3 = GRchkmmdir(local_488,0);
          if (iVar3 == 0) {
            BVar4 = SetCurrentDirectoryA(local_488);
            if (BVar4 != 0) {
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_488
                        );
              bVar9 = true;
              goto LAB_18002348e;
            }
          }
        }
      }
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_488);
  }
  else {
    DVar2 = GetFileAttributesA(local_458);
    if ((DVar2 & 0x10) == 0) {
      lVar8 = 0;
      do {
        pcVar6 = local_458 + lVar8;
        local_238[lVar8] = *pcVar6;
        lVar8 = lVar8 + 1;
      } while (*pcVar6 != '\0');
      DVar2 = GetFullPathNameA(local_238,0x104,local_458,&local_478);
      if ((DVar2 != 0) && (local_478 != (LPSTR)0x0)) {
        *local_478 = '\0';
      }
      DVar2 = GetFileAttributesA(local_458);
      if ((DVar2 & 0x10) != 0) goto LAB_180023184;
LAB_180023204:
      pcVar6 = GetProfileStringA("mmgini","startupdir","");
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_480,pcVar6)
      ;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::TrimLeft
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_480);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::TrimRight
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_480);
      MMReplaceEnvironmentVariables(local_480);
      if (*(int *)(local_480 + -0x10) == 0) {
        local_498 = local_348;
        iVar3 = SHGetFolderPathA(0,5,0);
        if (-1 < iVar3) {
          pcVar6 = FUN_180033bc0();
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_480,
                     "%s\\Aspentech\\Aspen Plus %s",local_348,pcVar6);
          pCVar7 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                   ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                   CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                             ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                              &local_488,
                              (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                               *)&local_480);
          FUN_18001f880(pCVar7);
        }
        if (*(int *)(local_480 + -0x10) == 0) goto LAB_18002332e;
      }
      DVar2 = GetFullPathNameA(local_480,0x104,local_458,&local_478);
      if (DVar2 != 0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_480,
                   local_458);
      }
      DVar2 = GetFileAttributesA(local_480);
      if ((DVar2 & 0x10) != 0) {
        uVar5 = FUN_18001f770(param_1,local_480,2);
        if ((char)uVar5 == '\0') {
          iVar3 = GRchkmmdir(local_480,0);
          if (iVar3 == 0) {
            BVar4 = SetCurrentDirectoryA(local_480);
            bVar9 = BVar4 != 0;
            goto LAB_18002348e;
          }
        }
      }
      goto LAB_18002332e;
    }
LAB_180023184:
    uVar5 = FUN_18001f770(param_1,local_458,2);
    if ((char)uVar5 != '\0') goto LAB_180023204;
    iVar3 = GRchkmmdir(local_458,0);
    if (iVar3 != 0) goto LAB_180023204;
    iVar3 = _strnicmp(local_458,"a:",2);
    if (iVar3 != 0) {
      iVar3 = _strnicmp(local_458,"b:",2);
      if (iVar3 != 0) {
        BVar4 = SetCurrentDirectoryA(local_458);
        if (BVar4 != 0) {
          bVar9 = true;
          goto LAB_18002348e;
        }
        goto LAB_18002332e;
      }
    }
  }
  bVar9 = false;
LAB_18002348e:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_480);
  return bVar9;
}

/* RVA 0x234c0 */
undefined8 FUN_1800234c0(longlong param_1,int param_2)

{
  ICXSDocumentV22 *pIVar1;
  BOOL BVar2;
  long local_res8 [2];
  tagMSG local_38;
  
  pIVar1 = *(ICXSDocumentV22 **)(param_1 + 0xd0);
  if (pIVar1 == (ICXSDocumentV22 *)0x0) {
    return 0x80004005;
  }
  if (param_2 == 0) {
    if (*(int *)(param_1 + 0xe4) != 0) {
      *(undefined1 *)(param_1 + 0xe1) = 1;
      CxsRaiseCustomEvent(pIVar1,(char *)0x0,0x3f5,(char *)0x0,0);
    }
  }
  else if (*(int *)(param_1 + 0xe4) == 0) {
    CxsRaiseCustomEvent(pIVar1,(char *)0x0,0x3f5,(char *)0x0,1);
    CxsRaiseCustomEventWait
              (*(ICXSDocumentV22 **)(param_1 + 0xd0),(char *)0x0,0x3ed,(char *)0x0,0x7b,0,local_res8
              );
  }
  do {
    BVar2 = PeekMessageA(&local_38,(HWND)0x0,0,0,1);
    if (BVar2 != 0) {
      DispatchMessageA(&local_38);
    }
  } while (*(int *)(param_1 + 0xe4) != param_2);
  return 0;
}

/* RVA 0x235c0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_1800235c0(longlong param_1,char param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  LSTATUS LVar3;
  DWORD DVar4;
  int iVar5;
  BOOL BVar6;
  char *pcVar7;
  undefined *puVar8;
  longlong *plVar9;
  undefined8 *****pppppuVar10;
  LPSTR pCVar11;
  ulonglong uVar12;
  LPCSTR ****pppppCVar13;
  LPCSTR ***ppppCVar14;
  undefined8 *puVar15;
  ulonglong uVar16;
  undefined8 uVar17;
  void *pvVar18;
  LPCSTR ****pppppCVar19;
  char *****pppppcVar20;
  void *pvVar21;
  LPCSTR ***ppppCVar22;
  size_t sVar23;
  size_t sVar24;
  LPCSTR ***ppppCVar25;
  undefined1 auStackY_418 [32];
  DWORD local_3e8 [2];
  HKEY local_3e0;
  DWORD local_3d8 [2];
  undefined8 local_3d0;
  longlong lStack_3c8;
  LPCSTR ***local_3c0;
  LPCSTR ***ppppCStack_3b8;
  char *****local_3b0;
  longlong lStack_3a8;
  LPCSTR ***local_3a0;
  LPCSTR ***ppppCStack_398;
  LPCSTR ****local_390;
  undefined8 ****ppppuStack_388;
  LPCSTR ***local_380;
  LPCSTR ***ppppCStack_378;
  void *local_370;
  longlong lStack_368;
  LPCSTR ***local_360;
  LPCSTR ***ppppCStack_358;
  void *local_350;
  longlong lStack_348;
  longlong local_340;
  ulonglong uStack_338;
  undefined8 *****local_330;
  undefined8 uStack_328;
  ulonglong local_320;
  ulonglong local_318;
  undefined8 *****local_310;
  longlong lStack_308;
  LPCSTR ***local_300;
  LPCSTR ***ppppCStack_2f8;
  LPCSTR ****local_2f0;
  LPCSTR ***ppppCStack_2e8;
  LPCSTR ***local_2e0;
  LPCSTR ***ppppCStack_2d8;
  LPCSTR ****local_2d0;
  LPCSTR ***ppppCStack_2c8;
  LPCSTR ***local_2c0;
  LPCSTR ***ppppCStack_2b8;
  char *local_2b0;
  undefined8 uStack_2a8;
  undefined8 local_2a0;
  ulonglong local_298;
  char *****local_290;
  undefined8 uStack_288;
  undefined8 local_280;
  ulonglong local_278;
  BYTE local_268 [256];
  CHAR local_168 [272];
  ulonglong local_58;
  
  local_58 = DAT_180052888 ^ (ulonglong)auStackY_418;
  GetModuleFileNameA((HMODULE)0x0,local_168,0x104);
  pcVar7 = _strlwr(local_168);
  pcVar7 = strstr(pcVar7,"aspenproperties.exe");
  if (pcVar7 != (char *)0x0) {
    FUN_180033c10(2);
  }
  if (param_2 != '\0') {
    FUN_180033c10(2);
  }
  local_3e8[0] = 0xff;
  local_3e0 = (HKEY)0x0;
  puVar8 = FUN_180033c00();
  local_330 = (undefined8 *****)0x0;
  uStack_328 = 0;
  local_320 = 0;
  local_318 = 0;
  sVar23 = 0xffffffffffffffff;
  do {
    sVar23 = sVar23 + 1;
  } while (puVar8[sVar23] != '\0');
  FUN_180006e90(&local_330,puVar8,sVar23);
  local_2b0 = (char *)0x0;
  uStack_2a8 = 0;
  local_2a0 = 0;
  local_298 = 0xf;
  local_2b0 = FUN_18001d210(&local_2b0,0x20);
  uVar17 = s_SOFTWARE_AspenTech_APrSystem__180040a00._8_8_;
  local_2a0 = 0x1d;
  local_298 = 0x1f;
  *(undefined8 *)local_2b0 = s_SOFTWARE_AspenTech_APrSystem__180040a00._0_8_;
  *(undefined8 *)(local_2b0 + 8) = uVar17;
  *(undefined8 *)(local_2b0 + 0x10) = s_SOFTWARE_AspenTech_APrSystem__180040a00._16_8_;
  *(undefined4 *)(local_2b0 + 0x18) = s_SOFTWARE_AspenTech_APrSystem__180040a00._24_4_;
  local_2b0[0x1c] = s_SOFTWARE_AspenTech_APrSystem__180040a00[0x1c];
  local_2b0[0x1d] = '\0';
  pppppuVar10 = &local_330;
  if (0xf < local_318) {
    pppppuVar10 = local_330;
  }
  plVar9 = FUN_180024e40((longlong *)&local_2b0,pppppuVar10,local_320);
  local_310 = (undefined8 *****)*plVar9;
  lStack_308 = plVar9[1];
  local_300 = (LPCSTR ***)plVar9[2];
  ppppCStack_2f8 = (LPCSTR ***)plVar9[3];
  plVar9[2] = 0;
  plVar9[3] = 0xf;
  *(undefined1 *)plVar9 = 0;
  if ((ulonglong)((longlong)ppppCStack_2f8 - (longlong)local_300) < 6) {
    pppppuVar10 = (undefined8 *****)FUN_180007e40(&local_310,6,0,"\\aplus",6);
  }
  else {
    pppppuVar10 = &local_310;
    if (0xf < ppppCStack_2f8) {
      pppppuVar10 = local_310;
    }
    pvVar21 = (void *)((longlong)pppppuVar10 + (longlong)local_300);
    local_300 = (LPCSTR ***)((longlong)local_300 + 6);
    memmove(pvVar21,"\\aplus",6);
    *(undefined1 *)((longlong)pvVar21 + 6) = 0;
    pppppuVar10 = &local_310;
  }
  local_390 = (LPCSTR ****)0x0;
  ppppuStack_388 = (undefined8 ****)0x0;
  local_380 = (LPCSTR ***)0x0;
  ppppCStack_378 = (LPCSTR ***)0x0;
  local_390 = (LPCSTR ****)*pppppuVar10;
  ppppuStack_388 = pppppuVar10[1];
  local_380 = (LPCSTR ***)pppppuVar10[2];
  ppppCStack_378 = (LPCSTR ***)pppppuVar10[3];
  pppppuVar10[2] = (undefined8 ****)0x0;
  pppppuVar10[3] = (undefined8 ****)0xf;
  *(undefined1 *)pppppuVar10 = 0;
  if (0xf < ppppCStack_2f8) {
    pppppuVar10 = local_310;
    if ((0xfff < (longlong)ppppCStack_2f8 + 1U) &&
       (pppppuVar10 = (undefined8 *****)local_310[-1],
       0x1f < (ulonglong)((longlong)local_310 + (-8 - (longlong)pppppuVar10)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(pppppuVar10);
  }
  local_300 = _DAT_180041f70;
  ppppCStack_2f8 = _UNK_180041f78;
  local_310 = (undefined8 *****)((ulonglong)local_310 & 0xffffffffffffff00);
  if (0xf < local_298) {
    pcVar7 = local_2b0;
    if ((0xfff < local_298 + 1) &&
       (pcVar7 = *(char **)(local_2b0 + -8), (char *)0x1f < local_2b0 + (-8 - (longlong)pcVar7))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(pcVar7);
  }
  local_2a0 = 0;
  local_298 = 0xf;
  local_2b0 = (char *)((ulonglong)local_2b0 & 0xffffffffffffff00);
  pppppCVar13 = (LPCSTR ****)&local_390;
  if ((undefined8 ****)0xf < ppppCStack_378) {
    pppppCVar13 = local_390;
  }
  LVar3 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000002,(LPCSTR)pppppCVar13,0,0x20019,&local_3e0);
  if (LVar3 == 0) {
    LVar3 = RegQueryValueExA(local_3e0,"asptop",(LPDWORD)0x0,local_3d8,local_268,local_3e8);
    if (LVar3 == 0) {
      ppppCStack_2e8 = (LPCSTR ***)0x0;
      local_2e0 = _DAT_180041f70;
      ppppCStack_2d8 = _UNK_180041f78;
      local_2f0 = (LPCSTR ****)0x0;
      DVar4 = GetEnvironmentVariableA("path",(LPSTR)0x0,0);
      pCVar11 = operator_new__((longlong)(int)DVar4 + 1);
      pCVar11[(int)DVar4] = '\0';
      GetEnvironmentVariableA("path",pCVar11,DVar4);
      local_370 = (void *)0x0;
      lStack_368 = 0;
      local_360 = (LPCSTR ***)0x0;
      ppppCStack_358 = (LPCSTR ***)0x0;
      sVar23 = 0xffffffffffffffff;
      do {
        sVar23 = sVar23 + 1;
      } while (pCVar11[sVar23] != '\0');
      FUN_180006e90(&local_370,pCVar11,sVar23);
      local_3b0 = (char *****)0x0;
      lStack_3a8 = 0;
      local_3a0 = (LPCSTR ***)0x0;
      ppppCStack_398 = (LPCSTR ***)0x0;
      sVar23 = 0xffffffffffffffff;
      do {
        sVar24 = sVar23 + 1;
        lVar2 = sVar23 + 1;
        sVar23 = sVar24;
      } while (local_268[lVar2] != '\0');
      FUN_180006e90(&local_3b0,local_268,sVar24);
      plVar9 = FUN_180024e40((longlong *)&local_3b0,"\\xeq;",5);
      pvVar21 = (void *)*plVar9;
      lStack_348 = plVar9[1];
      local_340 = plVar9[2];
      uVar16 = plVar9[3];
      plVar9[2] = 0;
      plVar9[3] = 0xf;
      *(undefined1 *)plVar9 = 0;
      local_350 = pvVar21;
      uStack_338 = uVar16;
      uVar12 = FUN_180024f10(&local_370,(char *)&local_350,0);
      if (0xf < uVar16) {
        pvVar18 = pvVar21;
        if ((0xfff < uVar16 + 1) &&
           (pvVar18 = *(void **)((longlong)pvVar21 + -8),
           0x1f < (ulonglong)((longlong)pvVar21 + (-8 - (longlong)pvVar18)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        FUN_180035134(pvVar18);
      }
      if (0xf < ppppCStack_398) {
        pppppcVar20 = local_3b0;
        if ((0xfff < (longlong)ppppCStack_398 + 1U) &&
           (pppppcVar20 = (char *****)local_3b0[-1],
           0x1f < (ulonglong)((longlong)local_3b0 + (-8 - (longlong)pppppcVar20)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        FUN_180035134(pppppcVar20);
      }
      if (uVar12 == 0xffffffffffffffff) {
        local_350 = (void *)0x0;
        lStack_348 = 0;
        local_340 = 0;
        uStack_338 = 0;
        sVar23 = 0xffffffffffffffff;
        do {
          sVar24 = sVar23 + 1;
          lVar2 = sVar23 + 1;
          sVar23 = sVar24;
        } while (local_268[lVar2] != '\0');
        FUN_180006e90(&local_350,local_268,sVar24);
        plVar9 = FUN_180024e40((longlong *)&local_350,"\\xeq;",5);
        local_3b0 = (char *****)*plVar9;
        lStack_3a8 = plVar9[1];
        local_3a0 = (LPCSTR ***)plVar9[2];
        ppppCStack_398 = (LPCSTR ***)plVar9[3];
        plVar9[2] = 0;
        plVar9[3] = 0xf;
        *(undefined1 *)plVar9 = 0;
        pppppCVar13 = (LPCSTR ****)FUN_18001f2c0(&local_3d0,(longlong *)&local_3b0,pCVar11);
        if (&local_2f0 != (LPCSTR *****)pppppCVar13) {
          if ((LPCSTR ***)0xf < ppppCStack_2d8) {
            pppppCVar19 = local_2f0;
            if ((0xfff < (longlong)ppppCStack_2d8 + 1U) &&
               (pppppCVar19 = (LPCSTR ****)local_2f0[-1],
               (LPCSTR)0x1f < (LPCSTR)((longlong)local_2f0 + (-8 - (longlong)pppppCVar19)))) {
                    /* WARNING: Subroutine does not return */
              _invalid_parameter_noinfo_noreturn();
            }
            FUN_180035134(pppppCVar19);
          }
          local_2f0 = (LPCSTR ****)*pppppCVar13;
          ppppCStack_2e8 = pppppCVar13[1];
          local_2e0 = pppppCVar13[2];
          ppppCStack_2d8 = pppppCVar13[3];
          pppppCVar13[2] = (LPCSTR ***)0x0;
          pppppCVar13[3] = (LPCSTR ***)0xf;
          *(undefined1 *)pppppCVar13 = 0;
        }
        FUN_180008a90(&local_3d0);
        FUN_180008a90((longlong *)&local_3b0);
        FUN_180008a90((longlong *)&local_350);
        pppppCVar13 = (LPCSTR ****)&local_2f0;
        if ((LPCSTR ***)0xf < ppppCStack_2d8) {
          pppppCVar13 = local_2f0;
        }
        SetEnvironmentVariableA("path",(LPCSTR)pppppCVar13);
      }
      operator_delete__(pCVar11);
      if (0xf < ppppCStack_358) {
        pvVar21 = local_370;
        if ((0xfff < (longlong)ppppCStack_358 + 1U) &&
           (pvVar21 = *(void **)((longlong)local_370 + -8),
           0x1f < (ulonglong)((longlong)local_370 + (-8 - (longlong)pvVar21)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        FUN_180035134(pvVar21);
      }
      local_360 = _DAT_180041f70;
      ppppCStack_358 = _UNK_180041f78;
      local_370 = (void *)((ulonglong)local_370 & 0xffffffffffffff00);
      if ((LPCSTR ***)0xf < ppppCStack_2d8) {
        pppppCVar13 = local_2f0;
        if ((0xfff < (longlong)ppppCStack_2d8 + 1U) &&
           (pppppCVar13 = (LPCSTR ****)local_2f0[-1],
           (LPCSTR)0x1f < (LPCSTR)((longlong)local_2f0 + (-8 - (longlong)pppppCVar13)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        FUN_180035134(pppppCVar13);
      }
    }
    RegCloseKey(local_3e0);
  }
  local_3b0 = (char *****)0x0;
  lStack_3a8 = 0;
  local_3a0 = (LPCSTR ***)0x0;
  ppppCStack_398 = (LPCSTR ***)0xf;
  local_3b0 = FUN_18001d210(&local_3b0,0x20);
  uVar17 = s_SOFTWARE_AspenTech_APrSystem__180040a00._8_8_;
  local_3a0 = (LPCSTR ***)0x1d;
  ppppCStack_398 = (LPCSTR ***)0x1f;
  *local_3b0 = (char ****)s_SOFTWARE_AspenTech_APrSystem__180040a00._0_8_;
  local_3b0[1] = (char ****)uVar17;
  local_3b0[2] = (char ****)s_SOFTWARE_AspenTech_APrSystem__180040a00._16_8_;
  *(undefined4 *)(local_3b0 + 3) = s_SOFTWARE_AspenTech_APrSystem__180040a00._24_4_;
  *(char *)((longlong)local_3b0 + 0x1c) = s_SOFTWARE_AspenTech_APrSystem__180040a00[0x1c];
  *(char *)((longlong)local_3b0 + 0x1d) = '\0';
  pppppuVar10 = &local_330;
  if (0xf < local_318) {
    pppppuVar10 = local_330;
  }
  plVar9 = FUN_180024e40((longlong *)&local_3b0,pppppuVar10,local_320);
  local_3d0 = (undefined8 *)*plVar9;
  lStack_3c8 = plVar9[1];
  local_3c0 = (LPCSTR ***)plVar9[2];
  ppppCStack_3b8 = (LPCSTR ***)plVar9[3];
  plVar9[2] = 0;
  plVar9[3] = 0xf;
  *(undefined1 *)plVar9 = 0;
  if ((ulonglong)((longlong)ppppCStack_3b8 - (longlong)local_3c0) < 3) {
    puVar15 = FUN_180007e40(&local_3d0,3,0,&DAT_1800409fc,3);
  }
  else {
    puVar15 = &local_3d0;
    if (0xf < ppppCStack_3b8) {
      puVar15 = local_3d0;
    }
    pvVar21 = (void *)((longlong)puVar15 + (longlong)local_3c0);
    local_3c0 = (LPCSTR ***)((longlong)local_3c0 + 3);
    memmove(pvVar21,&DAT_1800409fc,3);
    *(undefined1 *)((longlong)pvVar21 + 3) = 0;
    puVar15 = &local_3d0;
  }
  pppppCVar13 = (LPCSTR ****)*puVar15;
  uVar17 = puVar15[1];
  uVar1 = puVar15[2];
  uVar16 = puVar15[3];
  puVar15[2] = 0;
  puVar15[3] = 0xf;
  *(undefined1 *)puVar15 = 0;
  if ((undefined8 ****)0xf < ppppCStack_378) {
    pppppCVar19 = local_390;
    if ((0xfff < (longlong)ppppCStack_378 + 1U) &&
       (pppppCVar19 = (LPCSTR ****)local_390[-1],
       (LPCSTR)0x1f < (LPCSTR)((longlong)local_390 + (-8 - (longlong)pppppCVar19)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(pppppCVar19);
  }
  local_390 = pppppCVar13;
  ppppuStack_388 = (undefined8 ****)uVar17;
  local_380 = (LPCSTR ***)uVar1;
  ppppCStack_378 = (LPCSTR ***)uVar16;
  if (0xf < ppppCStack_3b8) {
    puVar15 = local_3d0;
    if ((0xfff < (longlong)ppppCStack_3b8 + 1U) &&
       (puVar15 = (undefined8 *)local_3d0[-1],
       0x1f < (ulonglong)((longlong)local_3d0 + (-8 - (longlong)puVar15)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(puVar15);
  }
  local_3c0 = _DAT_180041f70;
  ppppCStack_3b8 = _UNK_180041f78;
  local_3d0 = (undefined8 *)((ulonglong)local_3d0 & 0xffffffffffffff00);
  if ((LPCSTR ***)0xf < ppppCStack_398) {
    pppppcVar20 = local_3b0;
    if ((0xfff < (longlong)ppppCStack_398 + 1U) &&
       (pppppcVar20 = (char *****)local_3b0[-1],
       (char *)0x1f < (char *)((longlong)local_3b0 + (-8 - (longlong)pppppcVar20)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(pppppcVar20);
  }
  pppppCVar13 = (LPCSTR ****)&local_390;
  if (0xf < ppppCStack_378) {
    pppppCVar13 = local_390;
  }
  LVar3 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000002,(LPCSTR)pppppCVar13,0,0x20019,&local_3e0);
  if (LVar3 == 0) {
    local_3e8[0] = 0xff;
    LVar3 = RegQueryValueExA(local_3e0,"mmcommonxeq",(LPDWORD)0x0,local_3d8,local_268,local_3e8);
    if (LVar3 == 0) {
      lStack_3a8 = 0;
      local_3a0 = _DAT_180041f70;
      ppppCStack_398 = _UNK_180041f78;
      local_3b0 = (char *****)0x0;
      DVar4 = GetEnvironmentVariableA("path",(LPSTR)0x0,0);
      pCVar11 = operator_new__((longlong)(int)DVar4 + 1);
      pCVar11[(int)DVar4] = '\0';
      GetEnvironmentVariableA("path",pCVar11,DVar4);
      local_370 = (void *)0x0;
      lStack_368 = 0;
      local_360 = (LPCSTR ***)0x0;
      ppppCStack_358 = (LPCSTR ***)0x0;
      sVar23 = 0xffffffffffffffff;
      do {
        sVar23 = sVar23 + 1;
      } while (pCVar11[sVar23] != '\0');
      FUN_180006e90(&local_370,pCVar11,sVar23);
      local_3d0 = (void *)0x0;
      lStack_3c8 = 0;
      local_3c0 = (LPCSTR ***)0x0;
      ppppCStack_3b8 = (LPCSTR ***)0x0;
      ppppCVar22 = (LPCSTR ***)0xffffffffffffffff;
      do {
        ppppCVar25 = ppppCVar22;
        ppppCVar22 = (LPCSTR ***)((longlong)ppppCVar25 + 1);
      } while (local_268[(longlong)ppppCVar25 + 1] != '\0');
      if ((LPCSTR ***)0x7fffffffffffffff < ppppCVar22) {
                    /* WARNING: Subroutine does not return */
        FUN_18001d1b0();
      }
      ppppCStack_3b8 = (LPCSTR ***)0xf;
      if (ppppCVar22 < (LPCSTR ***)0x10) {
        local_3c0 = ppppCVar22;
        memcpy(&local_3d0,local_268,(size_t)ppppCVar22);
        *(undefined1 *)((longlong)local_3d8 + (longlong)ppppCVar25 + 9) = 0;
      }
      else {
        ppppCVar14 = (LPCSTR ***)((ulonglong)ppppCVar22 | 0xf);
        ppppCVar25 = (LPCSTR ***)0x7fffffffffffffff;
        if ((ppppCVar14 < (LPCSTR ***)0x8000000000000000) &&
           (ppppCVar25 = ppppCVar14, ppppCVar14 < (LPCSTR ***)0x16)) {
          ppppCVar25 = (LPCSTR ***)0x16;
        }
        pvVar21 = FUN_18001d210(&local_3d0,(longlong)ppppCVar25 + 1);
        local_3d0 = pvVar21;
        local_3c0 = ppppCVar22;
        ppppCStack_3b8 = ppppCVar25;
        memcpy(pvVar21,local_268,(size_t)ppppCVar22);
        *(undefined1 *)((longlong)pvVar21 + (longlong)ppppCVar22) = 0;
      }
      plVar9 = FUN_180024e40(&local_3d0,&DAT_180040a54,1);
      pvVar21 = (void *)*plVar9;
      lStack_348 = plVar9[1];
      local_340 = plVar9[2];
      uVar16 = plVar9[3];
      plVar9[2] = 0;
      plVar9[3] = 0xf;
      *(undefined1 *)plVar9 = 0;
      local_350 = pvVar21;
      uStack_338 = uVar16;
      uVar12 = FUN_180024f10(&local_370,(char *)&local_350,0);
      if (0xf < uVar16) {
        pvVar18 = pvVar21;
        if ((0xfff < uVar16 + 1) &&
           (pvVar18 = *(void **)((longlong)pvVar21 + -8),
           0x1f < (ulonglong)((longlong)pvVar21 + (-8 - (longlong)pvVar18)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        FUN_180035134(pvVar18);
      }
      if ((LPCSTR ***)0xf < ppppCStack_3b8) {
        pvVar21 = local_3d0;
        if ((0xfff < (longlong)ppppCStack_3b8 + 1U) &&
           (pvVar21 = *(void **)((longlong)local_3d0 + -8),
           0x1f < (ulonglong)((longlong)local_3d0 + (-8 - (longlong)pvVar21)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        FUN_180035134(pvVar21);
      }
      if (uVar12 == 0xffffffffffffffff) {
        local_350 = (void *)0x0;
        lStack_348 = 0;
        local_340 = 0;
        uStack_338 = 0;
        sVar23 = 0xffffffffffffffff;
        do {
          sVar24 = sVar23 + 1;
          lVar2 = sVar23 + 1;
          sVar23 = sVar24;
        } while (local_268[lVar2] != '\0');
        FUN_180006e90(&local_350,local_268,sVar24);
        plVar9 = FUN_180024e40((longlong *)&local_350,&DAT_180040a54,1);
        local_3d0 = (undefined8 *)*plVar9;
        lStack_3c8 = plVar9[1];
        local_3c0 = (LPCSTR ***)plVar9[2];
        ppppCStack_3b8 = (LPCSTR ***)plVar9[3];
        plVar9[2] = 0;
        plVar9[3] = 0xf;
        *(undefined1 *)plVar9 = 0;
        plVar9 = FUN_18001f2c0((longlong *)&local_290,&local_3d0,pCVar11);
        FUN_18001f4a0((longlong *)&local_3b0,plVar9);
        FUN_180008a90((longlong *)&local_290);
        FUN_180008a90(&local_3d0);
        if (0xf < uStack_338) {
          pvVar21 = local_350;
          if ((0xfff < uStack_338 + 1) &&
             (pvVar21 = *(void **)((longlong)local_350 + -8),
             0x1f < (ulonglong)((longlong)local_350 + (-8 - (longlong)pvVar21)))) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
          FUN_180035134(pvVar21);
        }
        pppppcVar20 = (char *****)&local_3b0;
        if ((LPCSTR ***)0xf < ppppCStack_398) {
          pppppcVar20 = local_3b0;
        }
        SetEnvironmentVariableA("path",(LPCSTR)pppppcVar20);
      }
      operator_delete__(pCVar11);
      if (0xf < ppppCStack_358) {
        FUN_180024ed0(&local_370,local_370,(longlong)ppppCStack_358 + 1);
      }
      local_360 = _DAT_180041f70;
      ppppCStack_358 = _UNK_180041f78;
      local_370 = (void *)((ulonglong)local_370 & 0xffffffffffffff00);
      if ((LPCSTR ***)0xf < ppppCStack_398) {
        FUN_180024ed0(&local_3b0,local_3b0,(longlong)ppppCStack_398 + 1);
      }
    }
    RegCloseKey(local_3e0);
  }
  iVar5 = FUN_180033bd0();
  if (iVar5 == 2) {
    local_290 = (char *****)0x0;
    uStack_288 = 0;
    local_280 = 0;
    local_278 = 0xf;
    local_290 = FUN_18001d210(&local_290,0x30);
    uVar17 = s_SOFTWARE_AspenTech_Aspen_Propert_1800421d0._8_8_;
    local_280 = 0x24;
    local_278 = 0x2f;
    *local_290 = (char ****)s_SOFTWARE_AspenTech_Aspen_Propert_1800421d0._0_8_;
    local_290[1] = (char ****)uVar17;
    uVar17 = s_SOFTWARE_AspenTech_Aspen_Propert_1800421d0._24_8_;
    local_290[2] = (char ****)s_SOFTWARE_AspenTech_Aspen_Propert_1800421d0._16_8_;
    local_290[3] = (char ****)uVar17;
    *(undefined4 *)(local_290 + 4) = s_SOFTWARE_AspenTech_Aspen_Propert_1800421d0._32_4_;
    *(char *)((longlong)local_290 + 0x24) = '\0';
    pppppuVar10 = &local_330;
    if (0xf < local_318) {
      pppppuVar10 = local_330;
    }
    plVar9 = FUN_180024e40((longlong *)&local_290,pppppuVar10,local_320);
    local_3d0 = (undefined8 *)*plVar9;
    lStack_3c8 = plVar9[1];
    local_3c0 = (LPCSTR ***)plVar9[2];
    ppppCStack_3b8 = (LPCSTR ***)plVar9[3];
    plVar9[2] = 0;
    plVar9[3] = 0xf;
    *(undefined1 *)plVar9 = 0;
    if ((ulonglong)((longlong)ppppCStack_3b8 - (longlong)local_3c0) < 3) {
      puVar15 = FUN_180007e40(&local_3d0,3,0,&DAT_1800409fc,3);
    }
    else {
      puVar15 = &local_3d0;
      if (0xf < ppppCStack_3b8) {
        puVar15 = local_3d0;
      }
      pvVar21 = (void *)((longlong)puVar15 + (longlong)local_3c0);
      local_3c0 = (LPCSTR ***)((longlong)local_3c0 + 3);
      memmove(pvVar21,&DAT_1800409fc,3);
      *(undefined1 *)((longlong)pvVar21 + 3) = 0;
      puVar15 = &local_3d0;
    }
    pppppCVar13 = (LPCSTR ****)*puVar15;
    uVar17 = puVar15[1];
    uVar1 = puVar15[2];
    uVar16 = puVar15[3];
    puVar15[2] = 0;
    puVar15[3] = 0xf;
    *(undefined1 *)puVar15 = 0;
    if (0xf < ppppCStack_378) {
      pppppCVar19 = local_390;
      if ((0xfff < (longlong)ppppCStack_378 + 1U) &&
         (pppppCVar19 = (LPCSTR ****)local_390[-1],
         (LPCSTR)0x1f < (LPCSTR)((longlong)local_390 + (-8 - (longlong)pppppCVar19)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      FUN_180035134(pppppCVar19);
    }
    local_390 = pppppCVar13;
    ppppuStack_388 = (undefined8 ****)uVar17;
    local_380 = (LPCSTR ***)uVar1;
    ppppCStack_378 = (LPCSTR ***)uVar16;
    if (0xf < ppppCStack_3b8) {
      puVar15 = local_3d0;
      if ((0xfff < (longlong)ppppCStack_3b8 + 1U) &&
         (puVar15 = (undefined8 *)local_3d0[-1],
         0x1f < (ulonglong)((longlong)local_3d0 + (-8 - (longlong)puVar15)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      FUN_180035134(puVar15);
    }
    local_3c0 = _DAT_180041f70;
    ppppCStack_3b8 = _UNK_180041f78;
    local_3d0 = (undefined8 *)((ulonglong)local_3d0 & 0xffffffffffffff00);
    if (local_278 < 0x10) goto LAB_1800246ba;
    pppppcVar20 = local_290;
    if ((0xfff < local_278 + 1) &&
       (pppppcVar20 = (char *****)local_290[-1],
       (char *)0x1f < (char *)((longlong)local_290 + (-8 - (longlong)pppppcVar20)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
  }
  else {
    local_3b0 = (char *****)0x0;
    lStack_3a8 = 0;
    local_3a0 = (LPCSTR ***)0x0;
    ppppCStack_398 = (LPCSTR ***)0xf;
    local_3b0 = FUN_18001d210(&local_3b0,0x20);
    uVar17 = s_SOFTWARE_AspenTech_Aspen_Plus__1800421f8._8_8_;
    local_3a0 = (LPCSTR ***)0x1e;
    ppppCStack_398 = (LPCSTR ***)0x1f;
    *local_3b0 = (char ****)s_SOFTWARE_AspenTech_Aspen_Plus__1800421f8._0_8_;
    local_3b0[1] = (char ****)uVar17;
    local_3b0[2] = (char ****)s_SOFTWARE_AspenTech_Aspen_Plus__1800421f8._16_8_;
    *(undefined4 *)(local_3b0 + 3) = s_SOFTWARE_AspenTech_Aspen_Plus__1800421f8._24_4_;
    *(undefined2 *)((longlong)local_3b0 + 0x1c) = s_SOFTWARE_AspenTech_Aspen_Plus__1800421f8._28_2_;
    *(char *)((longlong)local_3b0 + 0x1e) = '\0';
    pppppuVar10 = &local_330;
    if (0xf < local_318) {
      pppppuVar10 = local_330;
    }
    plVar9 = FUN_180024e40((longlong *)&local_3b0,pppppuVar10,local_320);
    local_3d0 = (undefined8 *)*plVar9;
    lStack_3c8 = plVar9[1];
    local_3c0 = (LPCSTR ***)plVar9[2];
    ppppCStack_3b8 = (LPCSTR ***)plVar9[3];
    plVar9[2] = 0;
    plVar9[3] = 0xf;
    *(undefined1 *)plVar9 = 0;
    if ((ulonglong)((longlong)ppppCStack_3b8 - (longlong)local_3c0) < 3) {
      puVar15 = FUN_180007e40(&local_3d0,3,0,&DAT_1800409fc,3);
    }
    else {
      puVar15 = &local_3d0;
      if (0xf < ppppCStack_3b8) {
        puVar15 = local_3d0;
      }
      pvVar21 = (void *)((longlong)puVar15 + (longlong)local_3c0);
      local_3c0 = (LPCSTR ***)((longlong)local_3c0 + 3);
      memmove(pvVar21,&DAT_1800409fc,3);
      *(undefined1 *)((longlong)pvVar21 + 3) = 0;
      puVar15 = &local_3d0;
    }
    pppppCVar13 = (LPCSTR ****)*puVar15;
    uVar17 = puVar15[1];
    uVar1 = puVar15[2];
    uVar16 = puVar15[3];
    puVar15[2] = 0;
    puVar15[3] = 0xf;
    *(undefined1 *)puVar15 = 0;
    if (0xf < ppppCStack_378) {
      pppppCVar19 = local_390;
      if ((0xfff < (longlong)ppppCStack_378 + 1U) &&
         (pppppCVar19 = (LPCSTR ****)local_390[-1],
         (LPCSTR)0x1f < (LPCSTR)((longlong)local_390 + (-8 - (longlong)pppppCVar19)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      FUN_180035134(pppppCVar19);
    }
    local_390 = pppppCVar13;
    ppppuStack_388 = (undefined8 ****)uVar17;
    local_380 = (LPCSTR ***)uVar1;
    ppppCStack_378 = (LPCSTR ***)uVar16;
    if (0xf < ppppCStack_3b8) {
      puVar15 = local_3d0;
      if ((0xfff < (longlong)ppppCStack_3b8 + 1U) &&
         (puVar15 = (undefined8 *)local_3d0[-1],
         0x1f < (ulonglong)((longlong)local_3d0 + (-8 - (longlong)puVar15)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      FUN_180035134(puVar15);
    }
    local_3c0 = _DAT_180041f70;
    ppppCStack_3b8 = _UNK_180041f78;
    local_3d0 = (undefined8 *)((ulonglong)local_3d0 & 0xffffffffffffff00);
    if (ppppCStack_398 < (LPCSTR ***)0x10) goto LAB_1800246ba;
    pppppcVar20 = local_3b0;
    if ((0xfff < (longlong)ppppCStack_398 + 1U) &&
       (pppppcVar20 = (char *****)local_3b0[-1],
       (char *)0x1f < (char *)((longlong)local_3b0 + (-8 - (longlong)pppppcVar20)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
  }
  _DAT_180041f70 = local_3c0;
  _UNK_180041f78 = ppppCStack_3b8;
  FUN_180035134(pppppcVar20);
LAB_1800246ba:
  pppppCVar13 = (LPCSTR ****)&local_390;
  if (0xf < ppppCStack_378) {
    pppppCVar13 = local_390;
  }
  LVar3 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000002,(LPCSTR)pppppCVar13,0,0x20019,&local_3e0);
  if (LVar3 == 0) {
    local_3e8[0] = 0xff;
    LVar3 = RegQueryValueExA(local_3e0,"mmxeq",(LPDWORD)0x0,local_3d8,local_268,local_3e8);
    if (LVar3 == 0) {
      ppppCStack_2c8 = (LPCSTR ***)0x0;
      local_2c0 = _DAT_180041f70;
      ppppCStack_2b8 = _UNK_180041f78;
      local_2d0 = (LPCSTR ****)0x0;
      DVar4 = GetEnvironmentVariableA("path",(LPSTR)0x0,0);
      pCVar11 = operator_new__((longlong)(int)DVar4 + 1);
      pCVar11[(int)DVar4] = '\0';
      GetEnvironmentVariableA("path",pCVar11,DVar4);
      local_3b0 = (char *****)0x0;
      lStack_3a8 = 0;
      local_3a0 = (LPCSTR ***)0x0;
      ppppCStack_398 = (LPCSTR ***)0x0;
      sVar23 = 0xffffffffffffffff;
      do {
        sVar23 = sVar23 + 1;
      } while (pCVar11[sVar23] != '\0');
      FUN_180006e90(&local_3b0,pCVar11,sVar23);
      local_350 = (void *)0x0;
      lStack_348 = 0;
      local_340 = 0;
      uStack_338 = 0;
      sVar23 = 0xffffffffffffffff;
      do {
        sVar24 = sVar23 + 1;
        lVar2 = sVar23 + 1;
        sVar23 = sVar24;
      } while (local_268[lVar2] != '\0');
      FUN_180006e90(&local_350,local_268,sVar24);
      plVar9 = FUN_180024e40((longlong *)&local_350,&DAT_180040a54,1);
      pvVar21 = (void *)*plVar9;
      lStack_368 = plVar9[1];
      local_360 = (LPCSTR ***)plVar9[2];
      ppppCVar22 = (LPCSTR ***)plVar9[3];
      plVar9[2] = 0;
      plVar9[3] = 0xf;
      *(undefined1 *)plVar9 = 0;
      local_370 = pvVar21;
      ppppCStack_358 = ppppCVar22;
      uVar16 = FUN_180024f10(&local_3b0,(char *)&local_370,0);
      if ((LPCSTR ***)0xf < ppppCVar22) {
        pvVar18 = pvVar21;
        if ((0xfff < (longlong)ppppCVar22 + 1U) &&
           (pvVar18 = *(void **)((longlong)pvVar21 + -8),
           0x1f < (ulonglong)((longlong)pvVar21 + (-8 - (longlong)pvVar18)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        FUN_180035134(pvVar18);
      }
      if (0xf < uStack_338) {
        pvVar21 = local_350;
        if ((0xfff < uStack_338 + 1) &&
           (pvVar21 = *(void **)((longlong)local_350 + -8),
           0x1f < (ulonglong)((longlong)local_350 + (-8 - (longlong)pvVar21)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        FUN_180035134(pvVar21);
      }
      if (uVar16 == 0xffffffffffffffff) {
        local_350 = (void *)0x0;
        lStack_348 = 0;
        local_340 = 0;
        uStack_338 = 0;
        sVar23 = 0xffffffffffffffff;
        do {
          sVar24 = sVar23 + 1;
          lVar2 = sVar23 + 1;
          sVar23 = sVar24;
        } while (local_268[lVar2] != '\0');
        FUN_180006e90(&local_350,local_268,sVar24);
        plVar9 = FUN_180024e40((longlong *)&local_350,&DAT_180040a54,1);
        local_370 = (void *)*plVar9;
        lStack_368 = plVar9[1];
        local_360 = (LPCSTR ***)plVar9[2];
        ppppCStack_358 = (LPCSTR ***)plVar9[3];
        plVar9[2] = 0;
        plVar9[3] = 0xf;
        *(undefined1 *)plVar9 = 0;
        pppppCVar13 = (LPCSTR ****)
                      FUN_18001f2c0((longlong *)&local_290,(longlong *)&local_370,pCVar11);
        if (&local_2d0 != (LPCSTR *****)pppppCVar13) {
          if ((LPCSTR ***)0xf < ppppCStack_2b8) {
            pppppCVar19 = local_2d0;
            if ((0xfff < (longlong)ppppCStack_2b8 + 1U) &&
               (pppppCVar19 = (LPCSTR ****)local_2d0[-1],
               (LPCSTR)0x1f < (LPCSTR)((longlong)local_2d0 + (-8 - (longlong)pppppCVar19)))) {
                    /* WARNING: Subroutine does not return */
              _invalid_parameter_noinfo_noreturn();
            }
            FUN_180035134(pppppCVar19);
          }
          local_2d0 = (LPCSTR ****)*pppppCVar13;
          ppppCStack_2c8 = pppppCVar13[1];
          local_2c0 = pppppCVar13[2];
          ppppCStack_2b8 = pppppCVar13[3];
          pppppCVar13[2] = (LPCSTR ***)0x0;
          pppppCVar13[3] = (LPCSTR ***)0xf;
          *(undefined1 *)pppppCVar13 = 0;
        }
        FUN_180008a90((longlong *)&local_290);
        if (0xf < ppppCStack_358) {
          pvVar21 = local_370;
          if ((0xfff < (longlong)ppppCStack_358 + 1U) &&
             (pvVar21 = *(void **)((longlong)local_370 + -8),
             0x1f < (ulonglong)((longlong)local_370 + (-8 - (longlong)pvVar21)))) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
          FUN_180035134(pvVar21);
        }
        local_360 = _DAT_180041f70;
        ppppCStack_358 = _UNK_180041f78;
        local_370 = (void *)((ulonglong)local_370 & 0xffffffffffffff00);
        if (0xf < uStack_338) {
          pvVar21 = local_350;
          if ((0xfff < uStack_338 + 1) &&
             (pvVar21 = *(void **)((longlong)local_350 + -8),
             0x1f < (ulonglong)((longlong)local_350 + (-8 - (longlong)pvVar21)))) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
          FUN_180035134(pvVar21);
        }
        pppppCVar13 = (LPCSTR ****)&local_2d0;
        if ((LPCSTR ***)0xf < ppppCStack_2b8) {
          pppppCVar13 = local_2d0;
        }
        SetEnvironmentVariableA("path",(LPCSTR)pppppCVar13);
      }
      operator_delete__(pCVar11);
      if (0xf < ppppCStack_398) {
        pppppcVar20 = local_3b0;
        if ((0xfff < (longlong)ppppCStack_398 + 1U) &&
           (pppppcVar20 = (char *****)local_3b0[-1],
           0x1f < (ulonglong)((longlong)local_3b0 + (-8 - (longlong)pppppcVar20)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        FUN_180035134(pppppcVar20);
      }
      local_3a0 = _DAT_180041f70;
      ppppCStack_398 = _UNK_180041f78;
      local_3b0 = (char *****)((ulonglong)local_3b0 & 0xffffffffffffff00);
      if ((LPCSTR ***)0xf < ppppCStack_2b8) {
        pppppCVar13 = local_2d0;
        if ((0xfff < (longlong)ppppCStack_2b8 + 1U) &&
           (pppppCVar13 = (LPCSTR ****)local_2d0[-1],
           (LPCSTR)0x1f < (LPCSTR)((longlong)local_2d0 + (-8 - (longlong)pppppCVar13)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        FUN_180035134(pppppCVar13);
      }
    }
    RegCloseKey(local_3e0);
  }
  if (0xf < ppppCStack_378) {
    pppppCVar13 = local_390;
    if ((0xfff < (longlong)ppppCStack_378 + 1U) &&
       (pppppCVar13 = (LPCSTR ****)local_390[-1],
       (LPCSTR)0x1f < (LPCSTR)((longlong)local_390 + (-8 - (longlong)pppppCVar13)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(pppppCVar13);
  }
  local_380 = _DAT_180041f70;
  ppppCStack_378 = _UNK_180041f78;
  local_390 = (LPCSTR ****)((ulonglong)local_390 & 0xffffffffffffff00);
  if (0xf < local_318) {
    pppppuVar10 = local_330;
    if ((0xfff < local_318 + 1) &&
       (pppppuVar10 = (undefined8 *****)local_330[-1],
       0x1f < (ulonglong)((longlong)local_330 + (-8 - (longlong)pppppuVar10)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(pppppuVar10);
  }
  iVar5 = FUN_180033bd0();
  pcVar7 = "propmmg.hms";
  if (iVar5 != 2) {
    pcVar7 = "mmg.hms";
  }
  SetHelpFile(pcVar7);
  *(undefined8 *)(param_1 + 0x24) = 0;
  *(undefined8 *)(param_1 + 0x2c) = 0;
  *(undefined8 *)(param_1 + 0x34) = 0;
  *(undefined8 *)(param_1 + 0x3c) = 0;
  *(undefined8 *)(param_1 + 0x44) = 0;
  *(undefined8 *)(param_1 + 0x4c) = 0;
  *(undefined8 *)(param_1 + 0x54) = 0;
  *(undefined8 *)(param_1 + 0x5c) = 0;
  *(undefined8 *)(param_1 + 100) = 0;
  *(undefined8 *)(param_1 + 0x6c) = 0;
  *(undefined8 *)(param_1 + 0x74) = 0;
  *(undefined8 *)(param_1 + 0x7c) = 0;
  *(undefined8 *)(param_1 + 0x84) = 0;
  *(undefined8 *)(param_1 + 0x8c) = 0;
  *(undefined8 *)(param_1 + 0x94) = 0;
  *(undefined8 *)(param_1 + 0x9c) = 0;
  *(undefined8 *)(param_1 + 0xa4) = 0;
  *(undefined8 *)(param_1 + 0xac) = 0;
  *(undefined8 *)(param_1 + 0xb4) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0x9c;
  BVar6 = GetVersionExA((LPOSVERSIONINFOA)(param_1 + 0x20));
  if (BVar6 == 0) {
    *(undefined4 *)(param_1 + 0x20) = 0x94;
    GetVersionExA((LPOSVERSIONINFOA)(param_1 + 0x20));
  }
  SetGlobalPointer("OSVersion",param_1 + 0x20,1);
  uVar17 = FUN_180020fc0(param_1);
  return (char)uVar17 != '\0';
}

/* RVA 0x24c90 */
undefined8 FUN_180024c90(longlong param_1,int param_2)

{
  int iVar1;
  longlong *plVar2;
  int local_res10 [6];
  
  if (param_2 != 0) {
    if (*(int *)(param_1 + 0xdc) == 0) {
      *(undefined4 *)(param_1 + 0xdc) = 1;
      MMSetVisibleSuppress(1);
      LockGlobalObject(1);
      ApwnContextResetContext(true);
    }
    return 0;
  }
  if (*(int *)(param_1 + 0xdc) == 0) {
    return 0;
  }
  *(undefined4 *)(param_1 + 0xdc) = 0;
  iVar1 = FUN_180033bd0();
  if (iVar1 != 2) {
    MMSetVisibleSuppress(0);
  }
  if (*(longlong *)(param_1 + 0xc0) != 0) {
    ApwnContextDocumentClose(*(void **)(*(longlong *)(param_1 + 0xc0) + 0xb0));
  }
  plVar2 = (longlong *)HappGetHapp();
  local_res10[0] = 0;
  if (plVar2 != (longlong *)0x0) {
    (**(code **)(*plVar2 + 0x210))(plVar2,local_res10);
    (**(code **)(*plVar2 + 0x10))(plVar2);
    if (1 < local_res10[0]) {
      LockGlobalObject(0,0);
      HappFireGuiClosed();
      if (*(char *)(param_1 + 0xd9) == '\0') {
        HappFireInClosing(0,0);
        *(undefined1 *)(param_1 + 0xd9) = 0;
        return 0;
      }
      goto LAB_180024d5d;
    }
  }
  HappFireGuiClosed();
  LockGlobalObject(0,1);
LAB_180024d5d:
  *(undefined1 *)(param_1 + 0xd9) = 0;
  return 0;
}

/* RVA 0x24db0 */
undefined8 FUN_180024db0(undefined4 param_1,undefined8 param_2)

{
  if (DAT_180054050 == (longlong *)0x0) {
    return 0;
  }
  (**(code **)(*DAT_180054050 + 0x68))(DAT_180054050,param_1,param_2);
  return 1;
}

