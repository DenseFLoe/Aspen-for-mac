/* RVA 0x1a400 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001a400(undefined8 param_1,longlong *param_2)

{
  code *pcVar1;
  int iVar2;
  LPWSTR pWVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 auStackY_88 [24];
  undefined8 uStackY_70;
  WCHAR local_58 [8];
  WCHAR local_38 [16];
  longlong *local_18;
  ulonglong local_10;
  
  local_10 = DAT_180052888 ^ (ulonglong)&local_18;
  local_18 = (longlong *)0x0;
  pWVar3 = local_38;
  if (pWVar3 == (LPWSTR)0x0) {
    pWVar3 = (LPWSTR)0x0;
  }
  else {
    local_38[0] = L'\0';
    uStackY_70 = 0x18001a466;
    iVar2 = MultiByteToWideChar(0,0,"ApwnACESettings",-1,pWVar3,0x10);
    if (iVar2 == 0) {
      pWVar3 = (LPWSTR)0x0;
    }
  }
  uStackY_70 = 0x18001a494;
  iVar2 = (**(code **)(*param_2 + 0x20))(param_2,pWVar3,0,0x12);
  puVar4 = auStackY_88 + 0x20;
  if (iVar2 < 0) {
    pWVar3 = local_58;
    if (pWVar3 == (LPWSTR)0x0) {
      pWVar3 = (LPWSTR)0x0;
    }
    else {
      local_58[0] = L'\0';
      iVar2 = MultiByteToWideChar(0,0,"ApwnACESettings",-1,pWVar3,0x10);
      if (iVar2 == 0) {
        pWVar3 = (LPWSTR)0x0;
      }
    }
    iVar2 = (**(code **)(*param_2 + 0x18))(param_2,pWVar3,0x1012,0);
    puVar4 = auStackY_88;
    puVar5 = auStackY_88;
    if (iVar2 < 0) goto LAB_18001a516;
  }
  *(undefined8 *)(puVar4 + -8) = 0x18001a50c;
  WriteACEStringToIStream(local_18);
  pcVar1 = *(code **)(*local_18 + 0x10);
  *(undefined8 *)(puVar4 + -8) = 0x18001a516;
  (*pcVar1)();
  puVar5 = puVar4;
LAB_18001a516:
  *(undefined8 *)(puVar5 + -8) = 0x18001a522;
  return;
}

/* RVA 0x1a540 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001a540(undefined8 param_1,longlong *param_2,char *param_3)

{
  int iVar1;
  FILE *pFVar2;
  undefined1 auStackY_498 [32];
  char local_468 [8];
  char *local_460;
  undefined1 local_458 [20];
  int local_444;
  char local_428 [256];
  char local_328 [256];
  char local_228 [272];
  char local_118 [256];
  ulonglong local_18;
  
  local_18 = DAT_180052888 ^ (ulonglong)auStackY_498;
  iVar1 = FUN_180033bd0();
  if (iVar1 == 1) {
    _splitpath(param_3,local_468,local_328,local_428,local_118);
    _makepath(local_228,local_468,local_328,local_428,"ads");
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_460,local_228
              );
    iVar1 = _stat64i32(local_460,local_458);
    if ((iVar1 != -1) && (local_444 != 0)) {
      pFVar2 = fopen(local_460,"rb");
      if (pFVar2 != (FILE *)0x0) {
        FUN_18001a980(param_1,param_2,pFVar2,"ADS");
      }
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_460);
  }
  return;
}

/* RVA 0x1a660 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001a660(undefined8 param_1,longlong *param_2)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  WCHAR *pWVar4;
  WCHAR *pWVar5;
  undefined1 *puVar6;
  undefined1 uStack0000000000000000;
  undefined1 auStackY_a8 [32];
  WCHAR local_78 [16];
  WCHAR local_48 [24];
  longlong *local_18;
  ulonglong local_10;
  
  pWVar4 = local_48;
  local_10 = DAT_180052888 ^ (ulonglong)&local_18;
  local_18 = (longlong *)0x0;
  if (&uStack0000000000000000 == (undefined1 *)0x48) {
    pWVar4 = (WCHAR *)0x0;
  }
  else {
    local_48[0] = L'\0';
    iVar2 = MultiByteToWideChar(0,0,"ApwnShellSettings",-1,local_48,0x12);
    if (iVar2 == 0) {
      pWVar4 = (WCHAR *)0x0;
    }
  }
  iVar2 = (**(code **)(*param_2 + 0x20))(param_2,pWVar4,0,0x12);
  pWVar5 = local_78;
  pWVar4 = local_78;
  if (iVar2 < 0) {
    if (&uStack0000000000000000 == (undefined1 *)0x78) {
      pWVar4 = (WCHAR *)0x0;
    }
    else {
      local_78[0] = L'\0';
      iVar2 = MultiByteToWideChar(0,0,"ApwnShellSettings",-1,local_78,0x12);
      if (iVar2 == 0) {
        pWVar4 = (WCHAR *)0x0;
      }
    }
    iVar2 = (**(code **)(*param_2 + 0x18))(param_2,pWVar4,0x1012,0);
    pWVar5 = (WCHAR *)auStackY_a8;
    puVar6 = auStackY_a8;
    if (iVar2 < 0) goto LAB_18001a77e;
  }
  *(undefined8 *)((longlong)pWVar5 + -8) = 0x18001a768;
  uVar3 = GRGetShellSettingsFile();
  *(undefined8 *)((longlong)pWVar5 + -8) = 0x18001a774;
  WriteApwnShellSettingsFromFileToStream(local_18,uVar3);
  pcVar1 = *(code **)(*local_18 + 0x10);
  *(undefined8 *)((longlong)pWVar5 + -8) = 0x18001a77e;
  (*pcVar1)();
  puVar6 = (undefined1 *)pWVar5;
LAB_18001a77e:
  *(undefined8 *)(puVar6 + -8) = 0x18001a78a;
  return;
}

/* RVA 0x1a7a0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001a7a0(undefined8 param_1,longlong *param_2)

{
  code *pcVar1;
  undefined1 *puVar2;
  int iVar3;
  LPWSTR pWVar4;
  undefined1 *puVar5;
  undefined1 auStackY_a8 [8];
  undefined8 uStackY_a0;
  undefined1 local_98 [8];
  undefined8 uStackY_90;
  WCHAR local_68 [8];
  WCHAR local_58 [8];
  int local_48 [2];
  longlong *local_40;
  int local_38 [2];
  undefined8 local_30;
  code *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = DAT_180052888 ^ (ulonglong)local_48;
  uStackY_90 = 0x18001a7d0;
  iVar3 = FUN_180033bd0();
  puVar5 = local_98 + 0x10;
  if (iVar3 == 1) {
    local_40 = (longlong *)0x0;
    local_30 = 0;
    pWVar4 = local_58;
    if (pWVar4 == (LPWSTR)0x0) {
      pWVar4 = (LPWSTR)0x0;
    }
    else {
      local_58[0] = L'\0';
      uStackY_a0 = 0x18001a81b;
      iVar3 = MultiByteToWideChar(0,0,"EOUtil",-1,pWVar4,7);
      if (iVar3 == 0) {
        pWVar4 = (LPWSTR)0x0;
      }
    }
    uStackY_a0 = 0x18001a849;
    iVar3 = (**(code **)(*param_2 + 0x20))(param_2,pWVar4,0,0x12);
    puVar2 = local_98;
    if (iVar3 < 0) {
      pWVar4 = local_68;
      if (pWVar4 == (LPWSTR)0x0) {
        pWVar4 = (LPWSTR)0x0;
      }
      else {
        local_68[0] = L'\0';
        iVar3 = MultiByteToWideChar(0,0,"EOUtil",-1,pWVar4,7);
        if (iVar3 == 0) {
          pWVar4 = (LPWSTR)0x0;
        }
      }
      iVar3 = (**(code **)(*param_2 + 0x18))(param_2,pWVar4,0x1012,0);
      puVar5 = auStackY_a8;
      puVar2 = auStackY_a8;
      if (iVar3 < 0) goto LAB_18001a95d;
    }
    puVar5 = puVar2;
    local_48[0] = 0;
    *(code ***)(puVar5 + 0x30) = &local_28;
    local_28 = (code *)0x0;
    *(int **)(puVar5 + 0x28) = local_48;
    *(undefined8 **)(puVar5 + 0x20) = &local_20;
    *(undefined8 *)(puVar5 + -8) = 0x18001a8ee;
    EOsavblk(1,0,0,0);
    local_38[0] = local_48[0];
    pcVar1 = *(code **)(*local_40 + 0x28);
    *(undefined8 *)(puVar5 + -8) = 0x18001a908;
    (*pcVar1)(local_40,local_30,0,0);
    pcVar1 = *(code **)(*local_40 + 0x20);
    *(undefined8 *)(puVar5 + -8) = 0x18001a91d;
    (*pcVar1)(local_40,local_38,4);
    if (0 < local_38[0]) {
      pcVar1 = *(code **)(*local_40 + 0x20);
      *(undefined8 *)(puVar5 + -8) = 0x18001a937;
      (*pcVar1)(local_40,local_20,local_48[0],0);
    }
    if (local_28 != (code *)0x0) {
      *(undefined8 *)(puVar5 + -8) = 0x18001a946;
      (*local_28)(local_20);
    }
    pcVar1 = *(code **)(*local_40 + 0x10);
    *(undefined8 *)(puVar5 + -8) = 0x18001a950;
    (*pcVar1)();
    *(undefined8 *)(puVar5 + -8) = 0x18001a95d;
    Ordinal_131(param_2,1);
  }
LAB_18001a95d:
  *(undefined8 *)(puVar5 + -8) = 0x18001a969;
  return;
}

/* RVA 0x1a980 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001a980(undefined8 param_1,longlong *param_2,FILE *param_3,LPCSTR param_4)

{
  code *pcVar1;
  longlong *plVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong lVar5;
  size_t sVar6;
  ulonglong uVar7;
  int iVar8;
  undefined2 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined8 uStack_4a0;
  undefined1 auStack_498 [32];
  undefined8 uStack_478;
  int aiStack_470 [2];
  longlong *local_468;
  longlong local_460;
  undefined8 local_458;
  undefined1 local_448 [1024];
  ulonglong local_48;
  
  local_48 = DAT_180052888 ^ (ulonglong)&local_468;
  local_468 = (longlong *)0x0;
  local_458 = 0;
  puVar12 = auStack_498;
  if (param_4 == (LPCSTR)0x0) {
LAB_18001aa3d:
    puVar9 = (undefined2 *)0x0;
  }
  else {
    lVar4 = -1;
    do {
      lVar5 = lVar4;
      lVar4 = lVar5 + 1;
    } while (param_4[lVar4] != '\0');
    iVar8 = (int)lVar5 + 2;
    puVar12 = auStack_498;
    if (0x3fffffff < iVar8) goto LAB_18001aa3d;
    lVar4 = (longlong)(int)lVar4 * 2;
    uVar7 = lVar4 + 0x11;
    if (uVar7 <= lVar4 + 2U) {
      uVar7 = 0xffffffffffffff0;
    }
    uStack_4a0 = 0x18001aa08;
    lVar4 = -(uVar7 & 0xfffffffffffffff0);
    puVar12 = auStack_498 + lVar4;
    puVar9 = (undefined2 *)((longlong)aiStack_470 + lVar4 + 8);
    if (puVar9 == (undefined2 *)0x0) goto LAB_18001aa3d;
    *(int *)((longlong)aiStack_470 + lVar4) = iVar8;
    *puVar9 = 0;
    *(undefined2 **)(auStack_498 + lVar4 + 0x20) = puVar9;
    *(undefined8 *)(auStack_498 + lVar4 + -8) = 0x18001aa35;
    iVar8 = MultiByteToWideChar(0,0,param_4,-1,*(LPWSTR *)(auStack_498 + lVar4 + 0x20),
                                *(int *)((longlong)aiStack_470 + lVar4));
    puVar12 = auStack_498 + lVar4;
    if (iVar8 == 0) {
      puVar9 = (undefined2 *)0x0;
      puVar12 = auStack_498 + lVar4;
    }
  }
  lVar4 = *param_2;
  *(longlong ***)(puVar12 + 0x28) = &local_468;
  *(undefined4 *)(puVar12 + 0x20) = 0;
  pcVar1 = *(code **)(lVar4 + 0x20);
  *(undefined8 *)(puVar12 + -8) = 0x18001aa63;
  iVar8 = (*pcVar1)(param_2,puVar9,0,0x12);
  if (iVar8 < 0) {
    puVar11 = puVar12;
    if (param_4 == (LPCSTR)0x0) {
LAB_18001aae2:
      puVar9 = (undefined2 *)0x0;
      puVar12 = puVar11;
    }
    else {
      lVar4 = -1;
      do {
        lVar5 = lVar4;
        lVar4 = lVar5 + 1;
      } while (param_4[lVar4] != '\0');
      iVar8 = (int)lVar5 + 2;
      if (0x3fffffff < iVar8) goto LAB_18001aae2;
      lVar4 = (longlong)(int)lVar4 * 2;
      uVar7 = lVar4 + 0x11;
      if (uVar7 <= lVar4 + 2U) {
        uVar7 = 0xffffffffffffff0;
      }
      *(undefined8 *)(puVar12 + -8) = 0x18001aaad;
      lVar4 = -(uVar7 & 0xfffffffffffffff0);
      puVar11 = puVar12 + lVar4;
      puVar10 = puVar12 + lVar4;
      puVar9 = (undefined2 *)(puVar12 + lVar4 + 0x30);
      if (puVar9 == (undefined2 *)0x0) goto LAB_18001aae2;
      *(int *)(puVar12 + lVar4 + 0x28) = iVar8;
      *puVar9 = 0;
      *(undefined2 **)(puVar12 + lVar4 + 0x20) = puVar9;
      *(undefined8 *)(puVar12 + lVar4 + -8) = 0x18001aada;
      iVar8 = MultiByteToWideChar(0,0,param_4,-1,*(LPWSTR *)(puVar12 + lVar4 + 0x20),
                                  *(int *)(puVar12 + lVar4 + 0x28));
      puVar12 = puVar12 + lVar4;
      if (iVar8 == 0) {
        puVar9 = (undefined2 *)0x0;
        puVar12 = puVar10;
      }
    }
    lVar4 = *param_2;
    *(longlong ***)(puVar12 + 0x28) = &local_468;
    *(undefined4 *)(puVar12 + 0x20) = 0;
    pcVar1 = *(code **)(lVar4 + 0x18);
    *(undefined8 *)(puVar12 + -8) = 0x18001ab08;
    iVar8 = (*pcVar1)(param_2,puVar9,0x1012,0);
    if (iVar8 < 0) goto LAB_18001abd1;
  }
  uVar3 = local_458;
  plVar2 = local_468;
  pcVar1 = *(code **)(*local_468 + 0x28);
  *(undefined8 *)(puVar12 + -8) = 0x18001ab27;
  (*pcVar1)(plVar2,uVar3,0,0);
  plVar2 = local_468;
  local_460 = 0;
  pcVar1 = *(code **)(*local_468 + 0x20);
  *(undefined8 *)(puVar12 + -8) = 0x18001ab40;
  (*pcVar1)(plVar2,&local_460,4);
  *(undefined8 *)(puVar12 + -8) = 0x18001ab49;
  iVar8 = feof(param_3);
  while (iVar8 == 0) {
    *(undefined8 *)(puVar12 + -8) = 0x18001ab68;
    sVar6 = fread(local_448,1,0x400,param_3);
    plVar2 = local_468;
    if (sVar6 == 0) break;
    pcVar1 = *(code **)(*local_468 + 0x20);
    *(undefined8 *)(puVar12 + -8) = 0x18001ab85;
    (*pcVar1)(plVar2,local_448,sVar6 & 0xffffffff,0);
    local_460 = local_460 + sVar6;
    *(undefined8 *)(puVar12 + -8) = 0x18001ab92;
    iVar8 = feof(param_3);
  }
  *(undefined8 *)(puVar12 + -8) = 0x18001ab9f;
  fclose(param_3);
  plVar2 = local_468;
  pcVar1 = *(code **)(*local_468 + 0x28);
  *(undefined8 *)(puVar12 + -8) = 0x18001abb2;
  (*pcVar1)(plVar2,uVar3,0,0);
  plVar2 = local_468;
  pcVar1 = *(code **)(*local_468 + 0x20);
  *(undefined8 *)(puVar12 + -8) = 0x18001abc7;
  (*pcVar1)(plVar2,&local_460,4);
  pcVar1 = *(code **)(*local_468 + 0x10);
  *(undefined8 *)(puVar12 + -8) = 0x18001abd1;
  (*pcVar1)();
LAB_18001abd1:
  *(undefined8 *)(puVar12 + -8) = 0x18001abe0;
  return;
}

/* RVA 0x1ac00 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001ac00(undefined8 param_1,char param_2,wchar_t *param_3)

{
  longlong lVar1;
  IcarusInfoHelper *pIVar2;
  undefined1 auStackY_178 [32];
  int local_138 [2];
  wchar_t *local_130;
  wchar_t *local_128 [2];
  CHAR local_118 [256];
  ulonglong local_18;
  
  local_18 = DAT_180052888 ^ (ulonglong)auStackY_178;
  lVar1 = GetpIcarusInfoHelper();
  if (lVar1 == 0) {
    return;
  }
  local_130 = (LPCWSTR)0x0;
  pIVar2 = (IcarusInfoHelper *)GetpIcarusInfoHelper();
  if (param_2 == '\0') {
    IcarusInfoHelper::SaveScenario(pIVar2,local_138,&local_130);
  }
  else {
    IcarusInfoHelper::SaveScenarioAs(pIVar2,param_3,local_138,&local_130);
  }
  if (local_138[0] == 0) {
    if (local_130 == (LPCWSTR)0x0) goto LAB_18001acd9;
    WideCharToMultiByte(0,0,local_130,-1,local_118,0x100,(LPCSTR)0x0,(LPBOOL)0x0);
    MMAfxMessageBox(local_118,0x30,-1,0);
  }
  if (local_130 != (BSTR)0x0) {
    SysFreeString(local_130);
    local_130 = (LPCWSTR)0x0;
  }
LAB_18001acd9:
  local_128[0] = (BSTR)0x0;
  pIVar2 = (IcarusInfoHelper *)GetpIcarusInfoHelper();
  IcarusInfoHelper::GetStatus(pIVar2,&DAT_180053548,local_128);
  GRinitializeicarus(DAT_180053548);
  if (local_128[0] != (BSTR)0x0) {
    SysFreeString(local_128[0]);
  }
  return;
}

/* RVA 0x1ad40 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001ad40(undefined8 param_1,longlong *param_2)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  FILE *_File;
  FILE *pFVar4;
  char *pcVar5;
  longlong lVar6;
  int _Value;
  char *_Filename;
  undefined1 auStackY_9e8 [32];
  int local_9b8 [2];
  longlong local_9b0;
  char local_9a8 [8];
  char *local_9a0;
  longlong *local_998;
  undefined8 local_990;
  char local_988 [31];
  char cStack_969;
  char local_968 [272];
  char local_858 [272];
  char local_748 [256];
  CHAR local_648 [272];
  char local_538 [256];
  char local_438 [256];
  char local_338 [256];
  char local_238 [256];
  char local_138 [256];
  ulonglong local_38;
  
  local_38 = DAT_180052888 ^ (ulonglong)auStackY_9e8;
  _Value = 0;
  local_9b8[0] = 0;
  local_998 = param_2;
  local_990 = param_1;
  iVar3 = FUN_180033bd0();
  if (iVar3 == 1) {
    local_9b0 = 0;
    local_9b8[0] = 0;
    MDgetFNNNames(&local_9b0,local_9b8);
    if (0 < local_9b8[0]) {
      _File = fopen(PTR_s_FNN_TXT_1800527e8,"wt");
      bVar2 = false;
      while (_Value < local_9b8[0]) {
        lVar6 = (longlong)_Value * 8;
        pFVar4 = fopen(*(char **)(lVar6 + local_9b0),"rb");
        if (pFVar4 == (FILE *)0x0) {
          iVar3 = SHGetFolderPathA(0,0x1c,0);
          if (-1 < iVar3) {
            PathAppendA(local_648,"\\AspenTech\\AIModeling\\MergeNNFiles\\");
            pcVar5 = *(char **)(lVar6 + local_9b0);
            _splitpath(local_648,local_9a8,local_338,(char *)0x0,(char *)0x0);
            _splitpath(pcVar5,(char *)0x0,(char *)0x0,local_438,local_538);
            _makepath(local_858,local_9a8,local_338,local_438,local_538);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_9a0,
                       local_858);
            iVar3 = _access(local_9a0,0);
            if (iVar3 == 0) {
              pFVar4 = fopen(local_9a0,"rb");
            }
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_9a0);
            param_1 = local_990;
            if (pFVar4 != (FILE *)0x0) goto LAB_18001af17;
          }
          _Value = _Value + 1;
          param_2 = local_998;
        }
        else {
LAB_18001af17:
          _splitpath(*(char **)(lVar6 + local_9b0),local_988,local_138,local_238,local_748);
          _Filename = local_238;
          _makepath(local_858,(char *)0x0,(char *)0x0,_Filename,local_748);
          _itoa(_Value,local_968,10);
          pcVar5 = &cStack_969;
          do {
            pcVar5 = pcVar5 + 1;
          } while (*pcVar5 != '\0');
          lVar6 = 0;
          do {
            cVar1 = local_748[lVar6];
            pcVar5[lVar6] = cVar1;
            lVar6 = lVar6 + 1;
          } while (cVar1 != '\0');
          FUN_18001f210(_File,&DAT_1800417a4,local_968,_Filename);
          FUN_18001f210(_File,&DAT_1800417a4,local_858,_Filename);
          param_2 = local_998;
          bVar2 = true;
          FUN_18001a980(param_1,local_998,pFVar4,local_968);
          _Value = _Value + 1;
        }
      }
      if (bVar2) {
        fclose(_File);
        _File = fopen(PTR_s_FNN_TXT_1800527e8,"rt");
        FUN_18001a980(param_1,param_2,_File,PTR_s_FNN_TXT_1800527e8);
      }
      fclose(_File);
      remove(PTR_s_FNN_TXT_1800527e8);
    }
    MDfreearray(local_9b0,local_9b8[0]);
  }
  return;
}

/* RVA 0x1b0b0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

undefined8 FUN_18001b0b0(longlong param_1,longlong *param_2,void *param_3)

{
  char cVar1;
  longlong lVar2;
  longlong *plVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined8 *******pppppppuVar6;
  void *pvVar7;
  ulonglong uVar8;
  int iVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  undefined8 *******pppppppuVar12;
  undefined8 *puVar13;
  longlong *plVar14;
  size_t sVar15;
  void *pvVar16;
  void *pvVar17;
  undefined8 *puVar18;
  undefined1 auStack_a8 [32];
  longlong *local_88;
  longlong local_78;
  void *local_70;
  longlong *local_68;
  undefined8 *******local_60;
  undefined8 uStack_58;
  void *local_50;
  ulonglong local_48;
  ulonglong local_40;
  
  local_40 = DAT_180052888 ^ (ulonglong)auStack_a8;
  local_50 = (void *)0x0;
  local_48 = 0;
  local_60 = (undefined8 *******)0x0;
  uStack_58 = 0;
  sVar15 = 0xffffffffffffffff;
  do {
    sVar15 = sVar15 + 1;
  } while (*(char *)((longlong)param_3 + sVar15) != '\0');
  local_78 = param_1;
  local_70 = param_3;
  local_68 = param_2;
  FUN_180006e90(&local_60,param_3,sVar15);
  uVar4 = local_48;
  pvVar7 = local_50;
  pppppppuVar6 = local_60;
  puVar18 = *(undefined8 **)(param_1 + 0xe0);
  puVar13 = (undefined8 *)puVar18[1];
  puVar10 = puVar18;
  if (*(char *)((longlong)puVar13 + 0x19) == '\0') {
    do {
      puVar11 = puVar13 + 4;
      pppppppuVar12 = &local_60;
      if (0xf < uVar4) {
        pppppppuVar12 = pppppppuVar6;
      }
      if (0xf < (ulonglong)puVar13[7]) {
        puVar11 = (undefined8 *)puVar13[4];
      }
      pvVar16 = (void *)puVar13[6];
      pvVar17 = pvVar16;
      if (pvVar7 < pvVar16) {
        pvVar17 = pvVar7;
      }
      iVar9 = memcmp(puVar11,pppppppuVar12,(size_t)pvVar17);
      if (iVar9 == 0) {
        if (pvVar7 <= pvVar16) goto LAB_18001b174;
LAB_18001b1d9:
        puVar11 = (undefined8 *)puVar13[2];
      }
      else {
        if (iVar9 < 0) goto LAB_18001b1d9;
LAB_18001b174:
        puVar11 = (undefined8 *)*puVar13;
        puVar10 = puVar13;
      }
      puVar13 = puVar11;
    } while (*(char *)((longlong)puVar11 + 0x19) == '\0');
    param_3 = local_70;
  }
  uVar4 = local_48;
  pppppppuVar6 = local_60;
  if (*(char *)((longlong)puVar10 + 0x19) == '\0') {
    puVar13 = puVar10 + 4;
    if (0xf < (ulonglong)puVar10[7]) {
      puVar13 = (undefined8 *)puVar10[4];
    }
    local_70 = (void *)puVar10[6];
    pppppppuVar12 = &local_60;
    if (0xf < local_48) {
      pppppppuVar12 = local_60;
    }
    pvVar16 = pvVar7;
    if (local_70 < pvVar7) {
      pvVar16 = local_70;
    }
    iVar9 = memcmp(pppppppuVar12,puVar13,(size_t)pvVar16);
    if (iVar9 == 0) {
      if (pvVar7 < local_70) goto LAB_18001b1eb;
    }
    else if (iVar9 < 0) goto LAB_18001b1eb;
  }
  else {
LAB_18001b1eb:
    puVar10 = puVar18;
  }
  if (0xf < uVar4) {
    pppppppuVar12 = pppppppuVar6;
    if ((0xfff < uVar4 + 1) &&
       (pppppppuVar12 = (undefined8 *******)pppppppuVar6[-1],
       0x1f < (ulonglong)((longlong)pppppppuVar6 + (-8 - (longlong)pppppppuVar12))))
    goto LAB_18001b493;
    FUN_180035134(pppppppuVar12);
  }
  if (puVar10 == puVar18) {
    return 0;
  }
  local_60 = (undefined8 *******)0x0;
  uStack_58 = 0;
  local_50 = (void *)0x0;
  sVar15 = 0xffffffffffffffff;
  local_48 = 0;
  do {
    sVar15 = sVar15 + 1;
  } while (*(char *)((longlong)param_3 + sVar15) != '\0');
  FUN_180006e90(&local_60,param_3,sVar15);
  uVar8 = local_48;
  pvVar7 = local_50;
  pppppppuVar6 = local_60;
  puVar18 = *(undefined8 **)(local_78 + 0xe0);
  cVar1 = *(char *)((longlong)puVar18[1] + 0x19);
  puVar13 = (undefined8 *)puVar18[1];
  uVar4 = local_48;
  while (local_48 = uVar4, cVar1 == '\0') {
    puVar10 = puVar13 + 4;
    pppppppuVar12 = &local_60;
    if (0xf < uVar8) {
      pppppppuVar12 = pppppppuVar6;
    }
    if (0xf < (ulonglong)puVar13[7]) {
      puVar10 = (undefined8 *)puVar13[4];
    }
    pvVar16 = (void *)puVar13[6];
    pvVar17 = pvVar16;
    if (pvVar7 < pvVar16) {
      pvVar17 = pvVar7;
    }
    iVar9 = memcmp(puVar10,pppppppuVar12,(size_t)pvVar17);
    if (iVar9 == 0) {
      if (pvVar7 <= pvVar16) goto LAB_18001b2b4;
LAB_18001b311:
      puVar10 = (undefined8 *)puVar13[2];
    }
    else {
      if (iVar9 < 0) goto LAB_18001b311;
LAB_18001b2b4:
      puVar10 = (undefined8 *)*puVar13;
      puVar18 = puVar13;
    }
    puVar13 = puVar10;
    uVar4 = local_48;
    cVar1 = *(char *)((longlong)puVar10 + 0x19);
  }
  sVar15 = 0xffffffffffffffff;
  if (*(char *)((longlong)puVar18 + 0x19) == '\0') {
    puVar13 = puVar18 + 4;
    if (0xf < (ulonglong)puVar18[7]) {
      puVar13 = (undefined8 *)puVar18[4];
    }
    pvVar16 = (void *)puVar18[6];
    pppppppuVar12 = &local_60;
    if (0xf < uVar4) {
      pppppppuVar12 = pppppppuVar6;
    }
    pvVar17 = pvVar7;
    if (pvVar16 < pvVar7) {
      pvVar17 = pvVar16;
    }
    iVar9 = memcmp(pppppppuVar12,puVar13,(size_t)pvVar17);
    if (iVar9 == 0) {
      if (pvVar7 < pvVar16) goto LAB_18001b326;
    }
    else if (iVar9 < 0) goto LAB_18001b326;
  }
  else {
LAB_18001b326:
    puVar18 = *(undefined8 **)(local_78 + 0xe0);
  }
  lVar5 = local_78;
  lVar2 = puVar18[9];
  if (0xf < uVar4) {
    pppppppuVar12 = pppppppuVar6;
    if ((0xfff < uVar4 + 1) &&
       (pppppppuVar12 = (undefined8 *******)pppppppuVar6[-1],
       0x1f < (ulonglong)((longlong)pppppppuVar6 + (-8 - (longlong)pppppppuVar12))))
    goto LAB_18001b493;
    FUN_180035134(pppppppuVar12);
  }
  plVar14 = local_68;
  if (lVar2 == 0) {
    return 0;
  }
  if (local_68 == (longlong *)0x0) {
    return 1;
  }
  local_60 = (undefined8 *******)0x0;
  uStack_58 = 0;
  local_50 = (void *)0x0;
  local_48 = 0;
  do {
    sVar15 = sVar15 + 1;
  } while (*(char *)((longlong)param_3 + sVar15) != '\0');
  FUN_180006e90(&local_60,param_3,sVar15);
  uVar4 = local_48;
  pvVar7 = local_50;
  pppppppuVar6 = local_60;
  puVar18 = *(undefined8 **)(lVar5 + 0xe0);
  puVar13 = (undefined8 *)puVar18[1];
  puVar10 = puVar18;
  if (*(char *)((longlong)puVar18[1] + 0x19) == '\0') {
    do {
      puVar11 = puVar13 + 4;
      pppppppuVar12 = &local_60;
      if (0xf < uVar4) {
        pppppppuVar12 = pppppppuVar6;
      }
      if (0xf < (ulonglong)puVar13[7]) {
        puVar11 = (undefined8 *)puVar13[4];
      }
      pvVar16 = (void *)puVar13[6];
      pvVar17 = pvVar16;
      if (pvVar7 < pvVar16) {
        pvVar17 = pvVar7;
      }
      iVar9 = memcmp(puVar11,pppppppuVar12,(size_t)pvVar17);
      if (iVar9 == 0) {
        if (pvVar7 <= pvVar16) goto LAB_18001b404;
LAB_18001b456:
        puVar11 = (undefined8 *)puVar13[2];
      }
      else {
        if (iVar9 < 0) goto LAB_18001b456;
LAB_18001b404:
        puVar11 = (undefined8 *)*puVar13;
        puVar10 = puVar13;
      }
      puVar13 = puVar11;
    } while (*(char *)((longlong)puVar11 + 0x19) == '\0');
    plVar14 = local_68;
  }
  if (*(char *)((longlong)puVar10 + 0x19) == '\0') {
    puVar13 = puVar10 + 4;
    if (0xf < (ulonglong)puVar10[7]) {
      puVar13 = (undefined8 *)puVar10[4];
    }
    pvVar16 = (void *)puVar10[6];
    pppppppuVar12 = &local_60;
    if (0xf < uVar4) {
      pppppppuVar12 = pppppppuVar6;
    }
    pvVar17 = pvVar7;
    if (pvVar16 < pvVar7) {
      pvVar17 = pvVar16;
    }
    iVar9 = memcmp(pppppppuVar12,puVar13,(size_t)pvVar17);
    if (iVar9 == 0) {
      if (pvVar7 < pvVar16) goto LAB_18001b461;
    }
    else if (iVar9 < 0) goto LAB_18001b461;
  }
  else {
LAB_18001b461:
    puVar10 = puVar18;
  }
  plVar3 = (longlong *)puVar10[9];
  if (0xf < uVar4) {
    pppppppuVar12 = pppppppuVar6;
    if ((0xfff < uVar4 + 1) &&
       (pppppppuVar12 = (undefined8 *******)pppppppuVar6[-1],
       0x1f < (ulonglong)((longlong)pppppppuVar6 + (-8 - (longlong)pppppppuVar12)))) {
LAB_18001b493:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(pppppppuVar12);
  }
  local_88 = plVar14;
  (**(code **)(*plVar3 + 0x38))(plVar3,0,0,0);
  (**(code **)(*plVar14 + 0x48))(plVar14,0);
  return 1;
}

/* RVA 0x1b4f0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001b4f0(longlong param_1,BSTR param_2)

{
  __uint64 _Var1;
  IStorage *pIVar2;
  UINT UVar3;
  uint uVar4;
  int iVar5;
  HRESULT HVar6;
  undefined8 ***pppuVar7;
  longlong *plVar8;
  longlong *plVar9;
  ulonglong uVar10;
  longlong *plVar11;
  undefined8 ****ppppuVar12;
  longlong lVar13;
  longlong lVar14;
  longlong *plVar15;
  ulonglong uVar16;
  size_t sVar17;
  ulonglong uVar18;
  undefined8 ****ppppuVar19;
  char cVar20;
  ulonglong uVar21;
  undefined1 auStack_1a8 [32];
  longlong *local_188;
  IStorage *local_180;
  longlong *local_178;
  LPLOCKBYTES local_170;
  longlong *local_168;
  longlong *local_160 [2];
  longlong *local_150 [2];
  undefined8 ****local_140;
  undefined8 uStack_138;
  ulonglong local_130;
  ulonglong local_128;
  longlong *local_118;
  uchar auStack_110 [8];
  undefined8 ***local_108;
  undefined8 ***pppuStack_100;
  ulonglong local_f8;
  ulonglong uStack_f0;
  longlong *local_e8;
  LPSTORAGE local_e0;
  undefined1 *local_d8;
  undefined1 local_d0 [136];
  ulonglong local_48;
  
  local_48 = DAT_180052888 ^ (ulonglong)auStack_1a8;
  uStack_138 = 0;
  local_130 = 0;
  local_128 = 0xf;
  local_140 = (undefined8 ****)0x0;
  if ((param_2 == (BSTR)0x0) || (UVar3 = SysStringLen(param_2), UVar3 == 0)) {
    uVar16 = local_128;
    if (3 < local_128) {
      ppppuVar19 = &local_140;
      if (0xf < local_128) {
        ppppuVar19 = local_140;
      }
      local_130 = 4;
      *(undefined4 *)ppppuVar19 = 0x746f6f52;
      *(undefined1 *)((longlong)ppppuVar19 + 4) = 0;
      goto LAB_18001b5de;
    }
    if (0x7fffffffffffffff - (local_128 >> 1) < local_128) {
      uVar10 = 0x7fffffffffffffff;
      uVar21 = 0x8000000000000027;
LAB_18001b60a:
      pppuVar7 = operator_new(uVar21);
      if (pppuVar7 == (undefined8 ***)0x0) goto LAB_18001b6b3;
      ppppuVar19 = (undefined8 ****)((longlong)pppuVar7 + 0x27U & 0xffffffffffffffe0);
      ppppuVar19[-1] = pppuVar7;
    }
    else {
      uVar21 = local_128 + (local_128 >> 1);
      uVar10 = 0xf;
      if (0xf < uVar21) {
        uVar10 = uVar21;
      }
      _Var1 = uVar10 + 1;
      if (0xfff < _Var1) {
        uVar21 = uVar10 + 0x28;
        if (uVar21 <= _Var1) {
                    /* WARNING: Subroutine does not return */
          FUN_18001d0c0();
        }
        goto LAB_18001b60a;
      }
      if (_Var1 == 0) {
        ppppuVar19 = (undefined8 ****)0x0;
      }
      else {
        ppppuVar19 = operator_new(_Var1);
      }
    }
    local_130 = 4;
    *(undefined4 *)ppppuVar19 = 0x746f6f52;
    *(undefined1 *)((longlong)ppppuVar19 + 4) = 0;
    local_128 = uVar10;
    if (0xf < uVar16) {
      ppppuVar12 = local_140;
      if ((0xfff < uVar16 + 1) &&
         (ppppuVar12 = (undefined8 ****)local_140[-1],
         0x1f < (ulonglong)((longlong)local_140 + (-8 - (longlong)ppppuVar12)))) {
LAB_18001b6b3:
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      FUN_180035134(ppppuVar12);
    }
    local_140 = ppppuVar19;
  }
  else {
    local_d8 = local_d0;
    FUN_18000d880(&local_d8,param_2,0);
    sVar17 = 0xffffffffffffffff;
    do {
      sVar17 = sVar17 + 1;
    } while (local_d8[sVar17] != '\0');
    FUN_18001d350((longlong *)&local_140,local_d8,sVar17);
    if (local_d8 == local_d0) {
LAB_18001b5de:
    }
    else {
      free(local_d8);
    }
  }
  uVar21 = local_128;
  uVar16 = local_130;
  ppppuVar19 = local_140;
  local_188 = (longlong *)(param_1 + 0xd0);
  plVar15 = (longlong *)*local_188;
  plVar8 = (longlong *)plVar15[1];
  local_160[0] = plVar15;
  if (*(char *)((longlong)plVar8 + 0x19) == '\0') {
    plVar9 = plVar8;
    do {
      ppppuVar12 = &local_140;
      if (0xf < uVar21) {
        ppppuVar12 = ppppuVar19;
      }
      plVar11 = plVar9 + 4;
      if (0xf < (ulonglong)plVar9[7]) {
        plVar11 = (longlong *)plVar9[4];
      }
      uVar10 = plVar9[6];
      uVar18 = uVar10;
      if (uVar16 < uVar10) {
        uVar18 = uVar16;
      }
      uVar4 = memcmp(plVar11,ppppuVar12,uVar18);
      if (uVar4 == 0) {
        if (uVar10 < uVar16) {
          uVar4 = 0xffffffff;
        }
        else {
          uVar4 = (uint)(uVar16 < uVar10);
        }
      }
      if ((int)uVar4 < 0) {
        plVar11 = (longlong *)plVar9[2];
      }
      else {
        plVar11 = (longlong *)*plVar9;
        plVar15 = plVar9;
      }
      plVar9 = plVar11;
    } while (*(char *)((longlong)plVar11 + 0x19) == '\0');
  }
  uVar21 = local_128;
  plVar9 = local_160[0];
  if (*(char *)((longlong)plVar15 + 0x19) == '\0') {
    plVar11 = plVar15 + 4;
    if (0xf < (ulonglong)plVar15[7]) {
      plVar11 = (longlong *)plVar15[4];
    }
    ppppuVar12 = &local_140;
    if (0xf < local_128) {
      ppppuVar12 = ppppuVar19;
    }
    uVar10 = plVar15[6];
    uVar18 = uVar16;
    if (uVar10 < uVar16) {
      uVar18 = uVar10;
    }
    uVar4 = memcmp(ppppuVar12,plVar11,uVar18);
    uVar18 = local_128;
    if (uVar4 == 0) {
      if (uVar16 < uVar10) {
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = (uint)(uVar10 < uVar16);
      }
    }
    if (((int)uVar4 < 0) || (plVar15 == plVar9)) goto LAB_18001bb73;
    plVar15 = plVar9;
    if (*(char *)((longlong)plVar8 + 0x19) == (char)-(char)((int)uVar4 >> 0x1f)) {
      do {
        ppppuVar12 = &local_140;
        if (0xf < uVar18) {
          ppppuVar12 = ppppuVar19;
        }
        plVar11 = plVar8 + 4;
        if (0xf < (ulonglong)plVar8[7]) {
          plVar11 = (longlong *)plVar8[4];
        }
        uVar21 = plVar8[6];
        uVar10 = uVar21;
        if (uVar16 < uVar21) {
          uVar10 = uVar16;
        }
        uVar4 = memcmp(plVar11,ppppuVar12,uVar10);
        if (uVar4 == 0) {
          if (uVar21 < uVar16) {
            uVar4 = 0xffffffff;
          }
          else {
            uVar4 = (uint)(uVar16 < uVar21);
          }
        }
        if ((int)uVar4 < 0) {
          plVar11 = (longlong *)plVar8[2];
        }
        else {
          plVar11 = (longlong *)*plVar8;
          plVar15 = plVar8;
        }
        plVar8 = plVar11;
      } while (*(char *)((longlong)plVar11 + 0x19) == '\0');
      plVar8 = (longlong *)plVar9[1];
      uVar21 = local_128;
    }
    if (*(char *)((longlong)plVar15 + 0x19) == '\0') {
      plVar11 = plVar15 + 4;
      if (0xf < (ulonglong)plVar15[7]) {
        plVar11 = (longlong *)plVar15[4];
      }
      ppppuVar12 = &local_140;
      if (0xf < uVar21) {
        ppppuVar12 = ppppuVar19;
      }
      uVar21 = plVar15[6];
      uVar10 = uVar16;
      if (uVar21 < uVar16) {
        uVar10 = uVar21;
      }
      uVar4 = memcmp(ppppuVar12,plVar11,uVar10);
      if (uVar4 == 0) {
        if (uVar16 < uVar21) {
          uVar4 = 0xffffffff;
        }
        else {
          uVar4 = (uint)(uVar21 < uVar16);
        }
      }
      if ((int)uVar4 < 0) goto LAB_18001b88e;
    }
    else {
LAB_18001b88e:
      plVar15 = plVar9;
    }
    uVar21 = local_128;
    if (plVar15[9] != 0) {
      cVar20 = *(char *)((longlong)plVar8 + 0x19);
      plVar15 = plVar9;
      while (plVar11 = plVar8, cVar20 == '\0') {
        ppppuVar12 = &local_140;
        if (0xf < uVar21) {
          ppppuVar12 = ppppuVar19;
        }
        plVar8 = plVar11 + 4;
        if (0xf < (ulonglong)plVar11[7]) {
          plVar8 = (longlong *)plVar11[4];
        }
        uVar10 = plVar11[6];
        uVar18 = uVar10;
        if (uVar16 < uVar10) {
          uVar18 = uVar16;
        }
        uVar4 = memcmp(plVar8,ppppuVar12,uVar18);
        if (uVar4 == 0) {
          if (uVar10 < uVar16) {
            uVar4 = 0xffffffff;
          }
          else {
            uVar4 = (uint)(uVar16 < uVar10);
          }
        }
        if ((int)uVar4 < 0) {
          plVar8 = (longlong *)plVar11[2];
          plVar11 = plVar15;
        }
        else {
          plVar8 = (longlong *)*plVar11;
        }
        cVar20 = *(char *)((longlong)plVar8 + 0x19);
        plVar15 = plVar11;
      }
      if (*(char *)((longlong)plVar15 + 0x19) == '\0') {
        plVar8 = plVar15 + 4;
        if (0xf < (ulonglong)plVar15[7]) {
          plVar8 = (longlong *)plVar15[4];
        }
        ppppuVar12 = &local_140;
        if (0xf < uVar21) {
          ppppuVar12 = ppppuVar19;
        }
        uVar21 = plVar15[6];
        uVar10 = uVar16;
        if (uVar21 < uVar16) {
          uVar10 = uVar21;
        }
        uVar4 = memcmp(ppppuVar12,plVar8,uVar10);
        if (uVar4 == 0) {
          if (uVar16 < uVar21) {
            uVar4 = 0xffffffff;
          }
          else {
            uVar4 = (uint)(uVar21 < uVar16);
          }
        }
        if ((int)uVar4 < 0) goto LAB_18001b966;
      }
      else {
LAB_18001b966:
        plVar15 = plVar9;
      }
      (**(code **)(*(longlong *)plVar15[9] + 0x10))();
      uVar16 = local_130;
      ppppuVar19 = local_140;
    }
    uVar21 = local_128;
    plVar15 = (longlong *)*local_188;
    plVar8 = (longlong *)plVar15[1];
    cVar20 = *(char *)((longlong)plVar8 + 0x19);
    local_160[0] = plVar15;
    if (cVar20 == '\0') {
      plVar9 = plVar8;
      do {
        ppppuVar12 = &local_140;
        if (0xf < uVar21) {
          ppppuVar12 = ppppuVar19;
        }
        plVar11 = plVar9 + 4;
        if (0xf < (ulonglong)plVar9[7]) {
          plVar11 = (longlong *)plVar9[4];
        }
        uVar10 = plVar9[6];
        uVar18 = uVar10;
        if (uVar16 < uVar10) {
          uVar18 = uVar16;
        }
        uVar4 = memcmp(plVar11,ppppuVar12,uVar18);
        if (uVar4 == 0) {
          if (uVar10 < uVar16) {
            uVar4 = 0xffffffff;
          }
          else {
            uVar4 = (uint)(uVar16 < uVar10);
          }
        }
        if ((int)uVar4 < 0) {
          plVar11 = (longlong *)plVar9[2];
        }
        else {
          plVar11 = (longlong *)*plVar9;
          plVar15 = plVar9;
        }
        plVar9 = plVar11;
      } while (*(char *)((longlong)plVar11 + 0x19) == '\0');
      cVar20 = *(char *)((longlong)plVar8 + 0x19);
    }
    plVar9 = local_160[0];
    if (*(char *)((longlong)plVar15 + 0x19) == '\0') {
      plVar11 = plVar15 + 4;
      if (0xf < (ulonglong)plVar15[7]) {
        plVar11 = (longlong *)plVar15[4];
      }
      ppppuVar12 = &local_140;
      if (0xf < local_128) {
        ppppuVar12 = ppppuVar19;
      }
      uVar21 = plVar15[6];
      uVar10 = uVar16;
      if (uVar21 < uVar16) {
        uVar10 = uVar21;
      }
      uVar4 = memcmp(ppppuVar12,plVar11,uVar10);
      if (uVar4 == 0) {
        if (uVar16 < uVar21) {
          uVar4 = 0xffffffff;
        }
        else {
          uVar4 = (uint)(uVar21 < uVar16);
        }
      }
      if ((int)uVar4 < 0) goto LAB_18001ba62;
    }
    else {
LAB_18001ba62:
      plVar15 = plVar9;
    }
    uVar21 = local_128;
    if (plVar15[8] != 0) {
      while (plVar15 = plVar8, cVar20 == '\0') {
        ppppuVar12 = &local_140;
        if (0xf < uVar21) {
          ppppuVar12 = ppppuVar19;
        }
        plVar8 = plVar15 + 4;
        if (0xf < (ulonglong)plVar15[7]) {
          plVar8 = (longlong *)plVar15[4];
        }
        uVar10 = plVar15[6];
        uVar18 = uVar10;
        if (uVar16 < uVar10) {
          uVar18 = uVar16;
        }
        uVar4 = memcmp(plVar8,ppppuVar12,uVar18);
        if (uVar4 == 0) {
          if (uVar10 < uVar16) {
            uVar4 = 0xffffffff;
          }
          else {
            uVar4 = (uint)(uVar16 < uVar10);
          }
        }
        if ((int)uVar4 < 0) {
          plVar8 = (longlong *)plVar15[2];
          plVar15 = plVar9;
        }
        else {
          plVar8 = (longlong *)*plVar15;
        }
        cVar20 = *(char *)((longlong)plVar8 + 0x19);
        plVar9 = plVar15;
      }
      if (*(char *)((longlong)plVar9 + 0x19) == '\0') {
        plVar15 = plVar9 + 4;
        if (0xf < (ulonglong)plVar9[7]) {
          plVar15 = (longlong *)plVar9[4];
        }
        ppppuVar12 = &local_140;
        if (0xf < uVar21) {
          ppppuVar12 = ppppuVar19;
        }
        uVar21 = plVar9[6];
        uVar10 = uVar16;
        if (uVar21 < uVar16) {
          uVar10 = uVar21;
        }
        uVar4 = memcmp(ppppuVar12,plVar15,uVar10);
        if (uVar4 == 0) {
          if (uVar16 < uVar21) {
            uVar4 = 0xffffffff;
          }
          else {
            uVar4 = (uint)(uVar21 < uVar16);
          }
        }
        if ((int)uVar4 < 0) goto LAB_18001bb35;
      }
      else {
LAB_18001bb35:
        plVar9 = (longlong *)*local_188;
      }
      (**(code **)(*(longlong *)plVar9[8] + 0x10))();
    }
    plVar15 = local_188;
    plVar8 = FUN_1800078e0(local_188,(longlong *)local_160,&local_140);
    local_118 = (longlong *)*plVar8;
    auStack_110 = *(uchar (*) [8])(plVar8 + 1);
    FUN_18001c760(plVar15,(longlong *)&local_118);
  }
  else {
LAB_18001bb73:
    plVar15 = local_188;
  }
  local_170 = (ILockBytes *)0x0;
  local_180 = (LPSTORAGE)0x0;
  CreateILockBytesOnHGlobal((HGLOBAL)0x0,1,&local_170);
  if ((local_170 == (ILockBytes *)0x0) ||
     (StgCreateDocfileOnILockBytes(local_170,0x1012,0,&local_180), local_180 == (LPSTORAGE)0x0))
  goto LAB_18001bf0a;
  plVar8 = (longlong *)0x0;
  local_160[0] = (longlong *)0x0;
  ppppuVar19 = &local_140;
  if (0xf < local_128) {
    ppppuVar19 = local_140;
  }
  lVar13 = 0;
  do {
    lVar14 = lVar13 + 1;
    if (*(char *)((longlong)ppppuVar19 + lVar13) != (&DAT_180041bf8)[lVar13]) {
      ppppuVar19 = &local_140;
      if (0xf < local_128) {
        ppppuVar19 = local_140;
      }
      goto LAB_18001bc15;
    }
    lVar13 = lVar14;
  } while (lVar14 != 5);
  ppppuVar19 = (undefined8 ****)0x0;
LAB_18001bc15:
  plVar9 = (longlong *)HYGetModelByName(ppppuVar19);
  if (plVar9 == (longlong *)0x0) {
LAB_18001bef7:
    plVar9 = plVar8;
    if (plVar8 == (longlong *)0x0) goto LAB_18001bf0a;
  }
  else {
    (**(code **)(*plVar9 + 8))(plVar9);
    local_178 = (longlong *)0x0;
    local_188 = (longlong *)0x0;
    local_160[0] = plVar9;
    iVar5 = (**(code **)*plVar9)(plVar9,&DAT_180041340,&local_188);
    if (iVar5 < 0) {
      local_188 = (longlong *)0x0;
    }
    if (local_188 != (longlong *)0x0) {
      local_150[0] = (longlong *)0x0;
      (**(code **)(*local_188 + 0x20))(local_188,&DAT_180042b18,local_150);
      if (local_150[0] != (longlong *)0x0) {
        local_168 = (longlong *)0x0;
        (**(code **)(*local_150[0] + 0x38))(local_150[0],&local_168);
        if (local_168 != (longlong *)0x0) {
          iVar5 = (**(code **)(*local_168 + 0x18))(local_168,1,(IID *)&local_118);
          while (-1 < iVar5) {
            iVar5 = (**(code **)*local_118)(local_118,&DAT_180042b18,&local_178);
            (**(code **)(*local_118 + 0x10))();
            if (-1 < iVar5) break;
            iVar5 = (**(code **)(*local_168 + 0x18))(local_168,1,(IID *)&local_118);
          }
        }
        if (local_168 != (longlong *)0x0) {
          (**(code **)(*local_168 + 0x10))();
        }
      }
      if (local_150[0] != (longlong *)0x0) {
        (**(code **)(*local_150[0] + 0x10))();
      }
    }
    plVar8 = plVar9;
    if (local_178 == (longlong *)0x0) {
LAB_18001bed8:
      if (local_188 != (longlong *)0x0) {
        (**(code **)(*local_188 + 0x10))();
      }
      if (local_178 != (longlong *)0x0) {
        (**(code **)(*local_178 + 0x10))(local_178);
      }
      goto LAB_18001bef7;
    }
    iVar5 = (**(code **)(*local_178 + 0x18))(local_178,(IID *)&local_118);
    if ((-1 < iVar5) && (HVar6 = WriteClassStg(local_180,(IID *)&local_118), -1 < HVar6)) {
      (**(code **)(*local_178 + 0x28))(local_178,local_180);
      iVar5 = (**(code **)(*local_178 + 0x38))(local_178,local_180,0);
      if (-1 < iVar5) {
        (**(code **)(*local_178 + 0x40))(local_178,local_180);
        uVar16 = local_130;
        pIVar2 = local_180;
        plVar8 = (longlong *)0x0;
        local_160[0] = (longlong *)0x0;
        local_108 = (undefined8 ***)0x0;
        pppuStack_100 = (undefined8 ***)0x0;
        local_f8 = 0;
        uStack_f0 = 0;
        ppppuVar19 = &local_140;
        if (0xf < local_128) {
          ppppuVar19 = local_140;
        }
        if (0x7fffffffffffffff < local_130) {
                    /* WARNING: Subroutine does not return */
          FUN_18001d1b0();
        }
        if (local_130 < 0x10) {
          local_f8 = local_130;
          uStack_f0 = 0xf;
          local_108 = *ppppuVar19;
          pppuStack_100 = ppppuVar19[1];
        }
        else {
          uVar10 = local_130 | 0xf;
          uVar21 = 0x7fffffffffffffff;
          if ((uVar10 < 0x8000000000000000) && (uVar21 = uVar10, uVar10 < 0x16)) {
            uVar21 = 0x16;
          }
          local_108 = FUN_18001d210(&local_108,uVar21 + 1);
          local_f8 = uVar16;
          uStack_f0 = uVar21;
          memcpy(local_108,ppppuVar19,uVar16 + 1);
        }
        local_e0 = pIVar2;
        local_e8 = plVar9;
        FUN_180008240(plVar15,(longlong *)local_150,&local_108);
        if (0xf < uStack_f0) {
          pppuVar7 = local_108;
          if ((0xfff < uStack_f0 + 1) &&
             (pppuVar7 = (undefined8 ***)local_108[-1],
             0x1f < (ulonglong)((longlong)local_108 + (-8 - (longlong)pppuVar7)))) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
          FUN_180035134(pppuVar7);
        }
        goto LAB_18001bed8;
      }
    }
    (*local_180->lpVtbl->Release)(local_180);
    if (local_188 != (longlong *)0x0) {
      (**(code **)(*local_188 + 0x10))();
    }
    if (local_178 != (longlong *)0x0) {
      (**(code **)(*local_178 + 0x10))();
    }
  }
  (**(code **)(*plVar9 + 0x10))(plVar9);
LAB_18001bf0a:
  if (local_170 != (ILockBytes *)0x0) {
    (*local_170->lpVtbl->Release)(local_170);
  }
  if (0xf < local_128) {
    ppppuVar19 = local_140;
    if ((0xfff < local_128 + 1) &&
       (ppppuVar19 = (undefined8 ****)local_140[-1],
       0x1f < (ulonglong)((longlong)local_140 + (-8 - (longlong)ppppuVar19)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(ppppuVar19);
  }
  return;
}

/* RVA 0x1bf90 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001bf90(longlong param_1,longlong *param_2)

{
  char cVar1;
  longlong *plVar2;
  int iVar3;
  undefined8 ****ppppuVar4;
  LPWSTR lpWideCharStr;
  longlong *plVar5;
  longlong *plVar6;
  undefined1 *puVar7;
  longlong *plVar8;
  bool bVar9;
  undefined1 auStackY_108 [24];
  undefined8 uStackY_f0;
  WCHAR local_d8 [16];
  undefined4 local_b8 [2];
  longlong *local_b0;
  undefined1 local_a8 [8];
  longlong *local_a0;
  longlong *local_98;
  longlong *local_90;
  longlong local_88;
  longlong *local_80;
  undefined4 local_78;
  undefined8 ****local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  ulonglong local_58;
  undefined4 local_50 [2];
  undefined8 ****local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  ulonglong local_28;
  
  local_28 = DAT_180052888 ^ (ulonglong)local_b8;
  uStackY_f0 = 0x18001bfcb;
  iVar3 = FUN_180033bd0();
  puVar7 = auStackY_108 + 0x20;
  if ((iVar3 != 1) || (puVar7 = auStackY_108 + 0x20, param_2 == (longlong *)0x0))
  goto LAB_18001c428;
  local_a0 = (longlong *)0x0;
  lpWideCharStr = local_d8;
  if (lpWideCharStr == (LPWSTR)0x0) {
    lpWideCharStr = (LPWSTR)0x0;
  }
  else {
    local_d8[0] = L'\0';
    iVar3 = MultiByteToWideChar(0,0,"PFSVData",-1,lpWideCharStr,9);
    if (iVar3 == 0) {
      lpWideCharStr = (LPWSTR)0x0;
    }
  }
  iVar3 = (**(code **)(*param_2 + 0x28))(param_2,lpWideCharStr,0x1012,0);
  puVar7 = auStackY_108;
  if (iVar3 < 0) goto LAB_18001c428;
  local_90 = (longlong *)0x0;
  local_88 = 0;
  local_90 = operator_new(0x68);
  *local_90 = (longlong)local_90;
  local_90[1] = (longlong)local_90;
  local_90[2] = (longlong)local_90;
  *(undefined2 *)(local_90 + 3) = 0x101;
  local_78 = 0;
  local_98 = local_a0;
  plVar8 = (longlong *)(param_1 + 0xd0);
  local_80 = plVar8;
  HYloohie2(&local_98,FUN_18001e2c0);
  if (local_88 != 0) {
    local_b0 = (longlong *)0x0;
    iVar3 = (**(code **)(*local_a0 + 0x20))(local_a0,L"_Contents",0,0x12);
    if (iVar3 < 0) {
      iVar3 = (**(code **)(*local_a0 + 0x18))(local_a0,L"_Contents",0x1012,0);
    }
    if (iVar3 == 0) {
      if (local_b0 == (longlong *)0x0) goto LAB_18001c351;
      plVar5 = (longlong *)*local_90;
      bVar9 = plVar5 == local_90;
      while (!bVar9) {
        uStack_40 = 0;
        local_38 = 0;
        local_30 = 0xf;
        local_48 = (undefined8 ****)0x0;
        ppppuVar4 = (undefined8 ****)(plVar5 + 4);
        if (&local_48 != (undefined8 *****)ppppuVar4) {
          if (0xf < (ulonglong)plVar5[7]) {
            ppppuVar4 = (undefined8 ****)*ppppuVar4;
          }
          FUN_18001d350((longlong *)&local_48,ppppuVar4,plVar5[6]);
        }
        ppppuVar4 = (undefined8 ****)(plVar5 + 8);
        uStack_68 = 0;
        local_60 = 0;
        local_58 = 0xf;
        local_70 = (undefined8 ****)0x0;
        if (&local_70 != (undefined8 *****)ppppuVar4) {
          if (0xf < (ulonglong)plVar5[0xb]) {
            ppppuVar4 = (undefined8 ****)*ppppuVar4;
          }
          FUN_18001d350((longlong *)&local_70,ppppuVar4,plVar5[10]);
        }
        local_50[0] = (undefined4)plVar5[0xc];
        local_b8[0] = (undefined4)local_38;
        (**(code **)(*local_b0 + 0x20))(local_b0,local_b8,4,local_a8);
        ppppuVar4 = &local_48;
        if (0xf < local_30) {
          ppppuVar4 = local_48;
        }
        (**(code **)(*local_b0 + 0x20))(local_b0,ppppuVar4,local_b8[0],local_a8);
        local_b8[0] = (undefined4)local_60;
        (**(code **)(*local_b0 + 0x20))(local_b0,local_b8,4,local_a8);
        ppppuVar4 = &local_70;
        if (0xf < local_58) {
          ppppuVar4 = local_70;
        }
        (**(code **)(*local_b0 + 0x20))(local_b0,ppppuVar4,local_b8[0],local_a8);
        (**(code **)(*local_b0 + 0x20))(local_b0,local_50,4,local_a8);
        if (0xf < local_58) {
          ppppuVar4 = local_70;
          if ((0xfff < local_58 + 1) &&
             (ppppuVar4 = (undefined8 ****)local_70[-1],
             0x1f < (ulonglong)((longlong)local_70 + (-8 - (longlong)ppppuVar4)))) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
          FUN_180035134(ppppuVar4);
        }
        local_60 = 0;
        local_58 = 0xf;
        local_70 = (undefined8 ****)((ulonglong)local_70 & 0xffffffffffffff00);
        if (0xf < local_30) {
          ppppuVar4 = local_48;
          if ((0xfff < local_30 + 1) &&
             (ppppuVar4 = (undefined8 ****)local_48[-1],
             0x1f < (ulonglong)((longlong)local_48 + (-8 - (longlong)ppppuVar4)))) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
          FUN_180035134(ppppuVar4);
        }
        plVar6 = (longlong *)plVar5[2];
        if (*(char *)((longlong)plVar6 + 0x19) == '\0') {
          cVar1 = *(char *)(*plVar6 + 0x19);
          plVar5 = plVar6;
          plVar6 = (longlong *)*plVar6;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*plVar6 + 0x19);
            plVar5 = plVar6;
            plVar6 = (longlong *)*plVar6;
          }
          bVar9 = plVar5 == local_90;
        }
        else {
          cVar1 = *(char *)(plVar5[1] + 0x19);
          plVar2 = (longlong *)plVar5[1];
          plVar6 = plVar5;
          while ((plVar5 = plVar2, cVar1 == '\0' && (plVar6 == (longlong *)plVar5[2]))) {
            cVar1 = *(char *)(plVar5[1] + 0x19);
            plVar2 = (longlong *)plVar5[1];
            plVar6 = plVar5;
          }
          bVar9 = plVar5 == local_90;
        }
      }
      (**(code **)(*local_b0 + 0x40))(local_b0,0);
    }
    if (local_b0 != (longlong *)0x0) {
      (**(code **)(*local_b0 + 0x10))();
    }
  }
LAB_18001c351:
  puVar7 = auStackY_108;
  if (local_a0 != (longlong *)0x0) {
    (**(code **)(*local_a0 + 0x10))();
  }
  plVar5 = (longlong *)*plVar8;
  plVar6 = (longlong *)*plVar5;
  if (plVar6 != plVar5) {
    do {
      if ((longlong *)plVar6[9] != (longlong *)0x0) {
        (**(code **)(*(longlong *)plVar6[9] + 0x10))();
      }
      if ((longlong *)plVar6[8] != (longlong *)0x0) {
        (**(code **)(*(longlong *)plVar6[8] + 0x10))();
      }
      plVar5 = (longlong *)plVar6[2];
      if (*(char *)((longlong)plVar5 + 0x19) == '\0') {
        cVar1 = *(char *)(*plVar5 + 0x19);
        plVar6 = plVar5;
        plVar5 = (longlong *)*plVar5;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*plVar5 + 0x19);
          plVar6 = plVar5;
          plVar5 = (longlong *)*plVar5;
        }
      }
      else {
        cVar1 = *(char *)(plVar6[1] + 0x19);
        plVar2 = (longlong *)plVar6[1];
        plVar5 = plVar6;
        while ((plVar6 = plVar2, cVar1 == '\0' && (plVar5 == (longlong *)plVar6[2]))) {
          cVar1 = *(char *)(plVar6[1] + 0x19);
          plVar2 = (longlong *)plVar6[1];
          plVar5 = plVar6;
        }
      }
      plVar5 = (longlong *)*plVar8;
    } while (plVar6 != plVar5);
  }
  FUN_180007ae0(plVar8,plVar8,(longlong *)plVar5[1]);
  plVar5[1] = (longlong)plVar5;
  *plVar5 = (longlong)plVar5;
  plVar5[2] = (longlong)plVar5;
  *(undefined8 *)(param_1 + 0xd8) = 0;
  FUN_180007a60(&local_90,&local_90,(longlong *)local_90[1]);
  FUN_180035134(local_90);
LAB_18001c428:
  *(undefined8 *)(puVar7 + -8) = 0x18001c437;
  return;
}

/* RVA 0x1c460 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001c460(undefined8 param_1,longlong *param_2)

{
  code *pcVar1;
  int iVar2;
  WCHAR *pWVar3;
  WCHAR *pWVar4;
  undefined1 *puVar5;
  undefined1 uStack0000000000000000;
  undefined1 auStackY_a8 [32];
  WCHAR local_78 [16];
  WCHAR local_48 [24];
  longlong *local_18;
  ulonglong local_10;
  
  pWVar3 = local_48;
  local_10 = DAT_180052888 ^ (ulonglong)&local_18;
  local_18 = (longlong *)0x0;
  if (&uStack0000000000000000 == (undefined1 *)0x48) {
    pWVar3 = (WCHAR *)0x0;
  }
  else {
    local_48[0] = L'\0';
    iVar2 = MultiByteToWideChar(0,0,"SpreadsheetCalculators",-1,local_48,0x17);
    if (iVar2 == 0) {
      pWVar3 = (WCHAR *)0x0;
    }
  }
  iVar2 = (**(code **)(*param_2 + 0x20))(param_2,pWVar3,0,0x12);
  pWVar4 = local_78;
  pWVar3 = local_78;
  if (iVar2 < 0) {
    if (&uStack0000000000000000 == (undefined1 *)0x78) {
      pWVar3 = (WCHAR *)0x0;
    }
    else {
      local_78[0] = L'\0';
      iVar2 = MultiByteToWideChar(0,0,"SpreadsheetCalculators",-1,local_78,0x17);
      if (iVar2 == 0) {
        pWVar3 = (WCHAR *)0x0;
      }
    }
    iVar2 = (**(code **)(*param_2 + 0x18))(param_2,pWVar3,0x1012,0);
    pWVar4 = (WCHAR *)auStackY_a8;
    puVar5 = auStackY_a8;
    if (iVar2 < 0) goto LAB_18001c576;
  }
  *(undefined8 *)((longlong)pWVar4 + -8) = 0x18001c56c;
  WriteSpreadsheetInfoToStream(local_18);
  pcVar1 = *(code **)(*local_18 + 0x10);
  *(undefined8 *)((longlong)pWVar4 + -8) = 0x18001c576;
  (*pcVar1)();
  puVar5 = (undefined1 *)pWVar4;
LAB_18001c576:
  *(undefined8 *)(puVar5 + -8) = 0x18001c582;
  return;
}

/* RVA 0x1c5a0 */
void FUN_18001c5a0(longlong param_1,void *param_2)

{
  size_t sVar1;
  
  sVar1 = 0xffffffffffffffff;
  do {
    sVar1 = sVar1 + 1;
  } while (*(char *)((longlong)param_2 + sVar1) != '\0');
  FUN_18001d350((longlong *)(param_1 + 0x40),param_2,sVar1);
  return;
}

/* RVA 0x1c5d0 */
void FUN_18001c5d0(longlong *param_1,longlong param_2,longlong param_3,longlong param_4)

{
  void *pvVar1;
  void *pvVar2;
  
  if ((longlong *)*param_1 != (longlong *)0x0) {
    FUN_180007060((longlong *)*param_1,(longlong *)param_1[1]);
    pvVar1 = (void *)*param_1;
    pvVar2 = pvVar1;
    if ((0xfff < (param_1[2] - (longlong)pvVar1 & 0xffffffffffffffe0U)) &&
       (pvVar2 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(pvVar2);
  }
  *param_1 = param_2;
  param_1[1] = param_3 * 0x20 + param_2;
  param_1[2] = param_4 * 0x20 + param_2;
  return;
}

/* RVA 0x1c670 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FUN_18001c670(longlong *param_1)

{
  int iVar1;
  size_t sVar2;
  size_t _Count;
  undefined1 auStackY_68 [32];
  char *local_38;
  char local_30 [32];
  ulonglong local_10;
  
  local_10 = DAT_180052888 ^ (ulonglong)auStackY_68;
  if ((param_1[0xd] == 0) || (*(char *)((longlong)param_1 + 0x71) == '\0')) {
    return true;
  }
  iVar1 = (**(code **)(*param_1 + 0x18))(param_1,0xffffffff);
  if (iVar1 != -1) {
    iVar1 = std::codecvt<char,char,_Mbstatet>::unshift
                      ((codecvt<char,char,_Mbstatet> *)param_1[0xd],
                       (_Mbstatet *)((longlong)param_1 + 0x74),local_30,(char *)&local_10,&local_38)
    ;
    if (iVar1 == 0) {
      *(undefined1 *)((longlong)param_1 + 0x71) = 0;
    }
    else if (iVar1 != 1) {
      if (iVar1 == 3) {
        *(undefined1 *)((longlong)param_1 + 0x71) = 0;
        return true;
      }
      return false;
    }
    _Count = (longlong)local_38 - (longlong)local_30;
    if ((_Count == 0) || (sVar2 = fwrite(local_30,1,_Count,(FILE *)param_1[0x10]), _Count == sVar2))
    {
      return *(char *)((longlong)param_1 + 0x71) == '\0';
    }
  }
  return false;
}

/* RVA 0x1c760 */
longlong FUN_18001c760(longlong *param_1,longlong *param_2)

{
  longlong *plVar1;
  char cVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong lVar9;
  
  plVar6 = (longlong *)*param_2;
  lVar9 = 0;
  plVar3 = (longlong *)param_2[1];
  plVar5 = plVar6;
  while (plVar5 != plVar3) {
    plVar8 = (longlong *)plVar5[2];
    lVar9 = lVar9 + 1;
    if (*(char *)((longlong)plVar8 + 0x19) == '\0') {
      cVar2 = *(char *)(*plVar8 + 0x19);
      plVar5 = plVar8;
      plVar8 = (longlong *)*plVar8;
      while (cVar2 == '\0') {
        cVar2 = *(char *)(*plVar8 + 0x19);
        plVar5 = plVar8;
        plVar8 = (longlong *)*plVar8;
      }
    }
    else {
      cVar2 = *(char *)(plVar5[1] + 0x19);
      plVar7 = (longlong *)plVar5[1];
      plVar8 = plVar5;
      while ((plVar5 = plVar7, cVar2 == '\0' && (plVar8 == (longlong *)plVar5[2]))) {
        cVar2 = *(char *)(plVar5[1] + 0x19);
        plVar7 = (longlong *)plVar5[1];
        plVar8 = plVar5;
      }
    }
  }
  puVar4 = (undefined8 *)*param_1;
  if ((plVar6 == (longlong *)*puVar4) && (*(char *)((longlong)plVar3 + 0x19) != '\0')) {
    FUN_180007ae0(param_1,param_1,(longlong *)puVar4[1]);
    puVar4[1] = puVar4;
    *puVar4 = puVar4;
    puVar4[2] = puVar4;
    param_1[1] = 0;
  }
  else {
    while (plVar6 != plVar3) {
      plVar5 = (longlong *)plVar6[2];
      if (*(char *)((longlong)plVar5 + 0x19) == '\0') {
        cVar2 = *(char *)(*plVar5 + 0x19);
        plVar8 = plVar5;
        plVar7 = (longlong *)*plVar5;
        while (cVar2 == '\0') {
          cVar2 = *(char *)(*plVar7 + 0x19);
          plVar8 = plVar7;
          plVar7 = (longlong *)*plVar7;
        }
        plVar5 = (longlong *)*plVar5;
        cVar2 = *(char *)((longlong)plVar5 + 0x19);
        while (cVar2 == '\0') {
          plVar5 = (longlong *)*plVar5;
          cVar2 = *(char *)((longlong)plVar5 + 0x19);
        }
      }
      else {
        cVar2 = *(char *)(plVar6[1] + 0x19);
        plVar7 = (longlong *)plVar6[1];
        plVar5 = plVar6;
        while ((plVar8 = plVar7, cVar2 == '\0' && (plVar5 == (longlong *)plVar8[2]))) {
          cVar2 = *(char *)(plVar8[1] + 0x19);
          plVar7 = (longlong *)plVar8[1];
          plVar5 = plVar8;
        }
        if (*(char *)(plVar6[1] + 0x19) == '\0') {
          plVar5 = plVar6;
          plVar7 = (longlong *)plVar6[1];
          do {
            if (plVar5 != (longlong *)plVar7[2]) break;
            plVar1 = plVar7 + 1;
            plVar5 = plVar7;
            plVar7 = (longlong *)*plVar1;
          } while (*(char *)(*plVar1 + 0x19) == '\0');
        }
      }
      plVar6 = FUN_18001c900(param_1,plVar6);
      FUN_180007c60(param_1,plVar6);
      plVar6 = plVar8;
    }
  }
  return lVar9;
}

/* RVA 0x1c900 */
longlong * FUN_18001c900(longlong *param_1,longlong *param_2)

{
  char cVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong *plVar7;
  
  plVar3 = (longlong *)param_2[2];
  plVar5 = param_2 + 2;
  if (*(char *)((longlong)plVar3 + 0x19) == '\0') {
    cVar1 = *(char *)(*plVar3 + 0x19);
    plVar4 = (longlong *)*plVar3;
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*plVar4 + 0x19);
      plVar3 = plVar4;
      plVar4 = (longlong *)*plVar4;
    }
  }
  else {
    cVar1 = *(char *)(param_2[1] + 0x19);
    plVar6 = (longlong *)param_2[1];
    plVar4 = param_2;
    while ((plVar3 = plVar6, cVar1 == '\0' && (plVar4 == (longlong *)plVar3[2]))) {
      cVar1 = *(char *)(plVar3[1] + 0x19);
      plVar6 = (longlong *)plVar3[1];
      plVar4 = plVar3;
    }
  }
  plVar7 = param_2 + 1;
  plVar4 = (longlong *)*param_2;
  plVar6 = (longlong *)*plVar5;
  if (*(char *)((longlong)plVar4 + 0x19) == '\0') {
    if (*(char *)(*plVar5 + 0x19) == '\0') {
      plVar6 = (longlong *)plVar3[2];
      if (plVar3 != param_2) {
        plVar4[1] = (longlong)plVar3;
        *plVar3 = *param_2;
        if (plVar3 == (longlong *)*plVar5) {
          plVar4 = plVar3;
        }
        else {
          plVar4 = (longlong *)plVar3[1];
          if (*(char *)((longlong)plVar6 + 0x19) == '\0') {
            plVar6[1] = (longlong)plVar4;
          }
          *plVar4 = (longlong)plVar6;
          plVar3[2] = *plVar5;
          *(longlong **)(*plVar5 + 8) = plVar3;
        }
        if (*(longlong **)(*param_1 + 8) == param_2) {
          *(longlong **)(*param_1 + 8) = plVar3;
        }
        else {
          plVar5 = (longlong *)*plVar7;
          if ((longlong *)*plVar5 == param_2) {
            *plVar5 = (longlong)plVar3;
          }
          else {
            plVar5[2] = (longlong)plVar3;
          }
        }
        lVar2 = plVar3[3];
        plVar3[1] = *plVar7;
        *(char *)(plVar3 + 3) = (char)param_2[3];
        *(char *)(param_2 + 3) = (char)lVar2;
        goto LAB_18001ca9d;
      }
    }
    else {
      plVar6 = plVar4;
    }
  }
  plVar4 = (longlong *)*plVar7;
  if (*(char *)((longlong)plVar6 + 0x19) == '\0') {
    plVar6[1] = (longlong)plVar4;
  }
  if (*(longlong **)(*param_1 + 8) == param_2) {
    *(longlong **)(*param_1 + 8) = plVar6;
  }
  else if ((longlong *)*plVar4 == param_2) {
    *plVar4 = (longlong)plVar6;
  }
  else {
    plVar4[2] = (longlong)plVar6;
  }
  if (*(longlong **)*param_1 == param_2) {
    if (*(char *)((longlong)plVar6 + 0x19) == '\0') {
      cVar1 = *(char *)(*plVar6 + 0x19);
      plVar5 = (longlong *)*plVar6;
      plVar3 = plVar6;
      while (plVar7 = plVar5, cVar1 == '\0') {
        plVar5 = (longlong *)*plVar7;
        cVar1 = *(char *)((longlong)plVar5 + 0x19);
        plVar3 = plVar7;
      }
    }
    else {
      plVar3 = plVar4;
    }
    *(longlong **)*param_1 = plVar3;
  }
  lVar2 = *param_1;
  if (*(longlong **)(lVar2 + 0x10) == param_2) {
    if (*(char *)((longlong)plVar6 + 0x19) == '\0') {
      cVar1 = *(char *)(plVar6[2] + 0x19);
      plVar5 = (longlong *)plVar6[2];
      plVar3 = plVar6;
      while (plVar7 = plVar5, cVar1 == '\0') {
        plVar5 = (longlong *)plVar7[2];
        cVar1 = *(char *)((longlong)plVar5 + 0x19);
        plVar3 = plVar7;
      }
      *(longlong **)(lVar2 + 0x10) = plVar3;
    }
    else {
      *(longlong **)(lVar2 + 0x10) = plVar4;
    }
  }
LAB_18001ca9d:
  if ((char)param_2[3] == '\x01') {
    if (plVar6 != *(longlong **)(*param_1 + 8)) {
      do {
        plVar5 = plVar4;
        if ((char)plVar6[3] != '\x01') break;
        plVar3 = (longlong *)*plVar5;
        if (plVar6 == plVar3) {
          plVar3 = (longlong *)plVar5[2];
          if ((char)plVar3[3] == '\0') {
            *(undefined1 *)(plVar3 + 3) = 1;
            plVar3 = (longlong *)plVar5[2];
            *(undefined1 *)(plVar5 + 3) = 0;
            plVar5[2] = *plVar3;
            if (*(char *)(*plVar3 + 0x19) == '\0') {
              *(longlong **)(*plVar3 + 8) = plVar5;
            }
            plVar4 = plVar5 + 1;
            plVar3[1] = plVar5[1];
            if (plVar5 == *(longlong **)(*param_1 + 8)) {
              *(longlong **)(*param_1 + 8) = plVar3;
              *plVar3 = (longlong)plVar5;
              *plVar4 = (longlong)plVar3;
              plVar3 = (longlong *)plVar5[2];
            }
            else {
              plVar7 = (longlong *)*plVar4;
              if (plVar5 == (longlong *)*plVar7) {
                *plVar7 = (longlong)plVar3;
                *plVar3 = (longlong)plVar5;
                *plVar4 = (longlong)plVar3;
                plVar3 = (longlong *)plVar5[2];
              }
              else {
                plVar7[2] = (longlong)plVar3;
                *plVar3 = (longlong)plVar5;
                *plVar4 = (longlong)plVar3;
                plVar3 = (longlong *)plVar5[2];
              }
            }
          }
          if (*(char *)((longlong)plVar3 + 0x19) == '\0') {
            if ((*(char *)(*plVar3 + 0x18) == '\x01') && (*(char *)(plVar3[2] + 0x18) == '\x01'))
            goto LAB_18001cc4b;
            if (*(char *)(plVar3[2] + 0x18) == '\x01') {
              *(undefined1 *)(*plVar3 + 0x18) = 1;
              *(undefined1 *)(plVar3 + 3) = 0;
              FUN_18001d060(param_1,plVar3);
              plVar3 = (longlong *)plVar5[2];
            }
            *(char *)(plVar3 + 3) = (char)plVar5[3];
            *(undefined1 *)(plVar5 + 3) = 1;
            *(undefined1 *)(plVar3[2] + 0x18) = 1;
            FUN_18001cfc0(param_1,(longlong)plVar5);
            break;
          }
        }
        else {
          if ((char)plVar3[3] == '\0') {
            *(undefined1 *)(plVar3 + 3) = 1;
            lVar2 = *plVar5;
            *(undefined1 *)(plVar5 + 3) = 0;
            *plVar5 = *(longlong *)(lVar2 + 0x10);
            if (*(char *)(*(longlong *)(lVar2 + 0x10) + 0x19) == '\0') {
              *(longlong **)(*(longlong *)(lVar2 + 0x10) + 8) = plVar5;
            }
            plVar3 = plVar5 + 1;
            *(longlong *)(lVar2 + 8) = plVar5[1];
            if (plVar5 == *(longlong **)(*param_1 + 8)) {
              *(longlong *)(*param_1 + 8) = lVar2;
              *(longlong **)(lVar2 + 0x10) = plVar5;
              *plVar3 = lVar2;
              plVar3 = (longlong *)*plVar5;
            }
            else {
              plVar4 = (longlong *)*plVar3;
              if (plVar5 == (longlong *)plVar4[2]) {
                plVar4[2] = lVar2;
                *(longlong **)(lVar2 + 0x10) = plVar5;
                *plVar3 = lVar2;
                plVar3 = (longlong *)*plVar5;
              }
              else {
                *plVar4 = lVar2;
                *(longlong **)(lVar2 + 0x10) = plVar5;
                *plVar3 = lVar2;
                plVar3 = (longlong *)*plVar5;
              }
            }
          }
          if (*(char *)((longlong)plVar3 + 0x19) == '\0') {
            if ((*(char *)(plVar3[2] + 0x18) != '\x01') || (*(char *)(*plVar3 + 0x18) != '\x01')) {
              if (*(char *)(*plVar3 + 0x18) == '\x01') {
                *(undefined1 *)(plVar3[2] + 0x18) = 1;
                *(undefined1 *)(plVar3 + 3) = 0;
                FUN_18001cfc0(param_1,(longlong)plVar3);
                plVar3 = (longlong *)*plVar5;
              }
              *(char *)(plVar3 + 3) = (char)plVar5[3];
              *(undefined1 *)(plVar5 + 3) = 1;
              *(undefined1 *)(*plVar3 + 0x18) = 1;
              FUN_18001d060(param_1,plVar5);
              break;
            }
LAB_18001cc4b:
            *(undefined1 *)(plVar3 + 3) = 0;
          }
        }
        plVar4 = (longlong *)plVar5[1];
        plVar6 = plVar5;
      } while (plVar5 != *(longlong **)(*param_1 + 8));
    }
    *(undefined1 *)(plVar6 + 3) = 1;
  }
  if (param_1[1] != 0) {
    param_1[1] = param_1[1] + -1;
  }
  return param_2;
}

/* RVA 0x1ccd0 */
void FUN_18001ccd0(undefined8 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  
  puVar3 = (undefined8 *)*param_1;
  if (puVar3 != (undefined8 *)0x0) {
    LOCK();
    piVar1 = (int *)(puVar3 + 2);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      if ((BSTR)*puVar3 != (BSTR)0x0) {
        SysFreeString((BSTR)*puVar3);
        *puVar3 = 0;
      }
      if ((void *)puVar3[1] != (void *)0x0) {
        operator_delete__((void *)puVar3[1]);
        puVar3[1] = 0;
      }
      FUN_180035134(puVar3);
    }
    *param_1 = 0;
  }
  return;
}

/* RVA 0x1cd40 */
longlong * FUN_18001cd40(longlong *param_1,longlong *param_2,longlong *param_3)

{
  char cVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong *plVar8;
  
  param_1[1] = param_1[1] + 1;
  plVar2 = (longlong *)*param_1;
  plVar6 = (longlong *)*param_2;
  param_3[1] = (longlong)plVar6;
  if (plVar6 == plVar2) {
    *plVar2 = (longlong)param_3;
    plVar2[1] = (longlong)param_3;
    plVar2[2] = (longlong)param_3;
    *(undefined1 *)(param_3 + 3) = 1;
    return param_3;
  }
  if ((int)param_2[1] == 0) {
    plVar6[2] = (longlong)param_3;
    if (plVar6 == (longlong *)plVar2[2]) {
      plVar2[2] = (longlong)param_3;
    }
  }
  else {
    *plVar6 = (longlong)param_3;
    if (plVar6 == (longlong *)*plVar2) {
      *plVar2 = (longlong)param_3;
    }
  }
  cVar1 = *(char *)(param_3[1] + 0x18);
  plVar6 = param_3;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(plVar2[1] + 0x18) = 1;
      return param_3;
    }
    plVar7 = (longlong *)plVar6[1];
    lVar3 = *(longlong *)plVar7[1];
    if (plVar7 == (longlong *)lVar3) {
      lVar3 = ((longlong *)plVar7[1])[2];
      if (*(char *)(lVar3 + 0x18) == '\0') {
        *(undefined1 *)(plVar7 + 3) = 1;
        *(undefined1 *)(lVar3 + 0x18) = 1;
        *(undefined1 *)(*(longlong *)(plVar6[1] + 8) + 0x18) = 0;
        plVar6 = *(longlong **)(plVar6[1] + 8);
      }
      else {
        plVar8 = (longlong *)plVar7[2];
        if (plVar6 == plVar8) {
          plVar7[2] = *plVar8;
          if (*(char *)(*plVar8 + 0x19) == '\0') {
            *(longlong **)(*plVar8 + 8) = plVar7;
          }
          plVar8[1] = plVar7[1];
          if (plVar7 == (longlong *)*(longlong *)(*param_1 + 8)) {
            *(longlong **)(*param_1 + 8) = plVar8;
          }
          else {
            plVar6 = (longlong *)plVar7[1];
            if (plVar7 == (longlong *)*plVar6) {
              *plVar6 = (longlong)plVar8;
            }
            else {
              plVar6[2] = (longlong)plVar8;
            }
          }
          *plVar8 = (longlong)plVar7;
          plVar7[1] = (longlong)plVar8;
          plVar6 = plVar7;
        }
        *(undefined1 *)(plVar6[1] + 0x18) = 1;
        *(undefined1 *)(*(longlong *)(plVar6[1] + 8) + 0x18) = 0;
        plVar7 = *(longlong **)(plVar6[1] + 8);
        plVar8 = (longlong *)*plVar7;
        *plVar7 = plVar8[2];
        if (*(char *)(plVar8[2] + 0x19) == '\0') {
          *(longlong **)(plVar8[2] + 8) = plVar7;
        }
        plVar8[1] = plVar7[1];
        if (plVar7 == *(longlong **)(*param_1 + 8)) {
          *(longlong **)(*param_1 + 8) = plVar8;
          plVar8[2] = (longlong)plVar7;
        }
        else {
          plVar4 = (longlong *)plVar7[1];
          if (plVar7 == (longlong *)plVar4[2]) {
            plVar4[2] = (longlong)plVar8;
            plVar8[2] = (longlong)plVar7;
          }
          else {
            *plVar4 = (longlong)plVar8;
            plVar8[2] = (longlong)plVar7;
          }
        }
LAB_18001cf7d:
        plVar7[1] = (longlong)plVar8;
      }
    }
    else {
      if (*(char *)(lVar3 + 0x18) != '\0') {
        plVar8 = (longlong *)*plVar7;
        if (plVar6 == plVar8) {
          *plVar7 = plVar8[2];
          if (*(char *)(plVar8[2] + 0x19) == '\0') {
            *(longlong **)(plVar8[2] + 8) = plVar7;
          }
          plVar8[1] = plVar7[1];
          if (plVar7 == *(longlong **)(*param_1 + 8)) {
            *(longlong **)(*param_1 + 8) = plVar8;
          }
          else {
            puVar5 = (undefined8 *)plVar7[1];
            if (plVar7 == (longlong *)puVar5[2]) {
              puVar5[2] = plVar8;
            }
            else {
              *puVar5 = plVar8;
            }
          }
          plVar8[2] = (longlong)plVar7;
          plVar7[1] = (longlong)plVar8;
          plVar6 = plVar7;
        }
        *(undefined1 *)(plVar6[1] + 0x18) = 1;
        *(undefined1 *)(*(longlong *)(plVar6[1] + 8) + 0x18) = 0;
        plVar7 = *(longlong **)(plVar6[1] + 8);
        plVar8 = (longlong *)plVar7[2];
        plVar7[2] = *plVar8;
        if (*(char *)(*plVar8 + 0x19) == '\0') {
          *(longlong **)(*plVar8 + 8) = plVar7;
        }
        plVar8[1] = plVar7[1];
        if (plVar7 == *(longlong **)(*param_1 + 8)) {
          *(longlong **)(*param_1 + 8) = plVar8;
        }
        else {
          puVar5 = (undefined8 *)plVar7[1];
          if (plVar7 == (longlong *)*puVar5) {
            *puVar5 = plVar8;
          }
          else {
            puVar5[2] = plVar8;
          }
        }
        *plVar8 = (longlong)plVar7;
        goto LAB_18001cf7d;
      }
      *(undefined1 *)(plVar7 + 3) = 1;
      *(undefined1 *)(lVar3 + 0x18) = 1;
      *(undefined1 *)(*(longlong *)(plVar6[1] + 8) + 0x18) = 0;
      plVar6 = *(longlong **)(plVar6[1] + 8);
    }
    cVar1 = *(char *)(plVar6[1] + 0x18);
  } while( true );
}

/* RVA 0x1cfa0 */
void FUN_18001cfa0(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x80) == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00018001cfac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _lock_file();
  return;
}

/* RVA 0x1cfc0 */
void FUN_18001cfc0(longlong *param_1,longlong param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  
  plVar1 = *(longlong **)(param_2 + 0x10);
  *(longlong *)(param_2 + 0x10) = *plVar1;
  if (*(char *)(*plVar1 + 0x19) == '\0') {
    *(longlong *)(*plVar1 + 8) = param_2;
  }
  plVar1[1] = *(longlong *)(param_2 + 8);
  if (param_2 == *(longlong *)(*param_1 + 8)) {
    *(longlong **)(*param_1 + 8) = plVar1;
    *plVar1 = param_2;
    *(longlong **)(param_2 + 8) = plVar1;
    return;
  }
  plVar2 = *(longlong **)(param_2 + 8);
  if (param_2 == *plVar2) {
    *plVar2 = (longlong)plVar1;
    *plVar1 = param_2;
    *(longlong **)(param_2 + 8) = plVar1;
    return;
  }
  plVar2[2] = (longlong)plVar1;
  *plVar1 = param_2;
  *(longlong **)(param_2 + 8) = plVar1;
  return;
}

/* RVA 0x1d020 */
void FUN_18001d020(basic_streambuf<char,std::char_traits<char>_> *param_1)

{
  basic_streambuf<char,std::char_traits<char>_> *pbVar1;
  
  pbVar1 = (basic_streambuf<char,std::char_traits<char>_> *)
           std::basic_streambuf<char,std::char_traits<char>_>::eback(param_1);
  if (pbVar1 == param_1 + 0x70) {
                    /* WARNING: Could not recover jumptable at 0x00018001d051. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_streambuf<char,std::char_traits<char>_>::setg
              (param_1,*(char **)(param_1 + 0x88),*(char **)(param_1 + 0x88),
               *(char **)(param_1 + 0x90));
    return;
  }
  return;
}

/* RVA 0x1d060 */
void FUN_18001d060(longlong *param_1,longlong *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  
  lVar1 = *param_2;
  *param_2 = *(longlong *)(lVar1 + 0x10);
  if (*(char *)(*(longlong *)(lVar1 + 0x10) + 0x19) == '\0') {
    *(longlong **)(*(longlong *)(lVar1 + 0x10) + 8) = param_2;
  }
  *(longlong *)(lVar1 + 8) = param_2[1];
  if (param_2 == *(longlong **)(*param_1 + 8)) {
    *(longlong *)(*param_1 + 8) = lVar1;
    *(longlong **)(lVar1 + 0x10) = param_2;
    param_2[1] = lVar1;
    return;
  }
  plVar2 = (longlong *)param_2[1];
  if (param_2 == (longlong *)plVar2[2]) {
    plVar2[2] = lVar1;
    *(longlong **)(lVar1 + 0x10) = param_2;
    param_2[1] = lVar1;
    return;
  }
  *plVar2 = lVar1;
  *(longlong **)(lVar1 + 0x10) = param_2;
  param_2[1] = lVar1;
  return;
}

/* RVA 0x1d0c0 */
void FUN_18001d0c0(void)

{
  undefined8 local_28 [5];
  
  FUN_1800088c0(local_28);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_28,(ThrowInfo *)&DAT_180049108);
}

/* RVA 0x1d0e0 */
void FUN_18001d0e0(void)

{
  undefined8 local_28 [5];
  
  FUN_180008930(local_28);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_28,(ThrowInfo *)&DAT_1800491c0);
}

/* RVA 0x1d100 */
void FUN_18001d100(void)

{
                    /* WARNING: Subroutine does not return */
  std::_Xlength_error("map/set too long");
}

/* RVA 0x1d120 */
void FUN_18001d120(longlong *param_1)

{
  void *pvVar1;
  void *pvVar2;
  
  if (7 < (ulonglong)param_1[3]) {
    pvVar1 = (void *)*param_1;
    pvVar2 = pvVar1;
    if ((0xfff < param_1[3] * 2 + 2U) &&
       (pvVar2 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(pvVar2);
  }
  param_1[3] = 7;
  param_1[2] = 0;
  *(undefined2 *)param_1 = 0;
  return;
}

/* RVA 0x1d190 */
void FUN_18001d190(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x80) == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00018001d19c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _unlock_file();
  return;
}

/* RVA 0x1d1b0 */
void FUN_18001d1b0(void)

{
                    /* WARNING: Subroutine does not return */
  std::_Xlength_error("string too long");
}

/* RVA 0x1d1d0 */
void FUN_18001d1d0(void)

{
                    /* WARNING: Subroutine does not return */
  std::_Xlength_error("vector too long");
}

/* RVA 0x1d1f0 */
void FUN_18001d1f0(void)

{
  code *pcVar1;
  
  std::_Xout_of_range("invalid string position");
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

/* RVA 0x1d210 */
void * FUN_18001d210(undefined8 param_1,ulonglong param_2)

{
  void *pvVar1;
  void *pvVar2;
  
  if (param_2 < 0x1000) {
    if (param_2 == 0) {
      return (void *)0x0;
    }
    pvVar1 = operator_new(param_2);
    return pvVar1;
  }
  if (param_2 + 0x27 <= param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_18001d0c0();
  }
  pvVar1 = operator_new(param_2 + 0x27);
  if (pvVar1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
  pvVar2 = (void *)((longlong)pvVar1 + 0x27U & 0xffffffffffffffe0);
  *(void **)((longlong)pvVar2 + -8) = pvVar1;
  return pvVar2;
}

/* RVA 0x1d270 */
void * FUN_18001d270(undefined8 param_1,ulonglong param_2)

{
  void *pvVar1;
  void *pvVar2;
  ulonglong uVar3;
  
  if (param_2 < 0x800000000000000) {
    uVar3 = param_2 * 0x20;
    if (uVar3 < 0x1000) {
      if (uVar3 == 0) {
        return (void *)0x0;
      }
      pvVar1 = operator_new(uVar3);
      return pvVar1;
    }
    if (uVar3 < uVar3 + 0x27) {
      pvVar1 = operator_new(uVar3 + 0x27);
      if (pvVar1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      pvVar2 = (void *)((longlong)pvVar1 + 0x27U & 0xffffffffffffffe0);
      *(void **)((longlong)pvVar2 + -8) = pvVar1;
      return pvVar2;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18001d0c0();
}

/* RVA 0x1d2e0 */
void * FUN_18001d2e0(undefined8 param_1,ulonglong param_2)

{
  __uint64 _Var1;
  void *pvVar2;
  void *pvVar3;
  
  if (param_2 < 0x8000000000000000) {
    _Var1 = param_2 * 2;
    if (_Var1 < 0x1000) {
      if (_Var1 == 0) {
        return (void *)0x0;
      }
      pvVar2 = operator_new(_Var1);
      return pvVar2;
    }
    if (_Var1 < _Var1 + 0x27) {
      pvVar2 = operator_new(_Var1 + 0x27);
      if (pvVar2 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      pvVar3 = (void *)((longlong)pvVar2 + 0x27U & 0xffffffffffffffe0);
      *(void **)((longlong)pvVar3 + -8) = pvVar2;
      return pvVar3;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18001d0c0();
}

/* RVA 0x1d350 */
longlong * FUN_18001d350(longlong *param_1,void *param_2,size_t param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  void *pvVar3;
  ulonglong uVar4;
  void *pvVar5;
  longlong *_Dst;
  ulonglong uVar6;
  void *_Dst_00;
  
  uVar2 = param_1[3];
  if (param_3 <= uVar2) {
    _Dst = param_1;
    if (0xf < uVar2) {
      _Dst = (longlong *)*param_1;
    }
    param_1[2] = param_3;
    memmove(_Dst,param_2,param_3);
    *(undefined1 *)((longlong)_Dst + param_3) = 0;
    return param_1;
  }
  uVar6 = 0x7fffffffffffffff;
  if (0x7fffffffffffffff < param_3) {
                    /* WARNING: Subroutine does not return */
    FUN_18001d1b0();
  }
  uVar4 = param_3 | 0xf;
  if ((uVar4 < 0x8000000000000000) && (uVar2 <= 0x7fffffffffffffff - (uVar2 >> 1))) {
    uVar1 = (uVar2 >> 1) + uVar2;
    uVar6 = uVar4;
    if (uVar4 < uVar1) {
      uVar6 = uVar1;
    }
    uVar1 = uVar6 + 1;
    if (0xfff < uVar1) {
      uVar4 = uVar6 + 0x28;
      if (uVar4 <= uVar1) {
                    /* WARNING: Subroutine does not return */
        FUN_18001d0c0();
      }
      goto LAB_18001d401;
    }
    if (uVar1 == 0) {
      _Dst_00 = (void *)0x0;
    }
    else {
      _Dst_00 = operator_new(uVar1);
    }
  }
  else {
    uVar4 = 0x8000000000000027;
LAB_18001d401:
    pvVar3 = operator_new(uVar4);
    if (pvVar3 == (void *)0x0) goto LAB_18001d49e;
    _Dst_00 = (void *)((longlong)pvVar3 + 0x27U & 0xffffffffffffffe0);
    *(void **)((longlong)_Dst_00 - 8) = pvVar3;
  }
  param_1[2] = param_3;
  param_1[3] = uVar6;
  memcpy(_Dst_00,param_2,param_3);
  *(undefined1 *)((longlong)_Dst_00 + param_3) = 0;
  if (0xf < uVar2) {
    pvVar3 = (void *)*param_1;
    pvVar5 = pvVar3;
    if ((0xfff < uVar2 + 1) &&
       (pvVar5 = *(void **)((longlong)pvVar3 + -8),
       0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)pvVar5)))) {
LAB_18001d49e:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(pvVar5);
  }
  *param_1 = (longlong)_Dst_00;
  return param_1;
}

/* RVA 0x1d4c0 */
basic_streambuf<char,std::char_traits<char>_> *
FUN_18001d4c0(basic_streambuf<char,std::char_traits<char>_> *param_1)

{
  bool bVar1;
  int iVar2;
  basic_streambuf<char,std::char_traits<char>_> *pbVar3;
  basic_streambuf<char,std::char_traits<char>_> *pbVar4;
  
  if (*(longlong *)(param_1 + 0x80) == 0) {
    pbVar3 = (basic_streambuf<char,std::char_traits<char>_> *)0x0;
  }
  else {
    pbVar3 = (basic_streambuf<char,std::char_traits<char>_> *)
             std::basic_streambuf<char,std::char_traits<char>_>::eback(param_1);
    if (pbVar3 == param_1 + 0x70) {
      std::basic_streambuf<char,std::char_traits<char>_>::setg
                (param_1,*(char **)(param_1 + 0x88),*(char **)(param_1 + 0x88),
                 *(char **)(param_1 + 0x90));
    }
    bVar1 = FUN_18001c670((longlong *)param_1);
    pbVar4 = (basic_streambuf<char,std::char_traits<char>_> *)0x0;
    if (bVar1) {
      pbVar4 = param_1;
    }
    iVar2 = fclose(*(FILE **)(param_1 + 0x80));
    pbVar3 = (basic_streambuf<char,std::char_traits<char>_> *)0x0;
    if (iVar2 == 0) {
      pbVar3 = pbVar4;
    }
  }
  param_1[0x7c] = (basic_streambuf<char,std::char_traits<char>_>)0x0;
  param_1[0x71] = (basic_streambuf<char,std::char_traits<char>_>)0x0;
  std::basic_streambuf<char,std::char_traits<char>_>::_Init(param_1);
  *(undefined8 *)(param_1 + 0x80) = 0;
  *(undefined8 *)(param_1 + 0x74) = DAT_180053598;
  *(undefined8 *)(param_1 + 0x68) = 0;
  return pbVar3;
}

/* RVA 0x1d570 */
/* Library Function - Multiple Matches With Same Base Name
    public: void __cdecl std::allocator<struct `void __cdecl
   phmap::container_internal::Deallocate<4,class std::allocator<unsigned long> >(class
   std::allocator<unsigned long> * __ptr64,void * __ptr64,unsigned
   __int64)'::`2'::M>::deallocate(struct `void __cdecl phmap::container_internal::Deallocate<4,class
   std::allocator<unsigned long> >(class std::allocator<unsigned long> * __ptr64,void *
   __ptr64,unsigned __int64)'::`2'::M * __ptr64 const,unsigned __int64) __ptr64
    public: void __cdecl std::allocator<struct `void __cdecl
   phmap::container_internal::Deallocate<4,class std::allocator<struct std::pair<unsigned long const
   ,unsigned long> > >(class std::allocator<struct std::pair<unsigned long const ,unsigned long> > *
   __ptr64,void * __ptr64,unsigned __int64)'::`2'::M>::deallocate(struct `void __cdecl
   phmap::container_internal::Deallocate<4,class std::allocator<struct std::pair<unsigned long const
   ,unsigned long> > >(class std::allocator<struct std::pair<unsigned long const ,unsigned long> > *
   __ptr64,void * __ptr64,unsigned __int64)'::`2'::M * __ptr64 const,unsigned __int64) __ptr64
    public: static void __cdecl phmap::allocator_traits<class std::allocator<struct `void __cdecl
   phmap::container_internal::Deallocate<4,class std::allocator<unsigned long> >(class
   std::allocator<unsigned long> * __ptr64,void * __ptr64,unsigned __int64)'::`2'::M>
   >::deallocate(class std::allocator<struct `void __cdecl
   phmap::container_internal::Deallocate<4,class std::allocator<unsigned long> >(class
   std::allocator<unsigned long> * __ptr64,void * __ptr64,unsigned __int64)'::`2'::M> &
   __ptr64,struct `void __cdecl phmap::container_internal::Deallocate<4,class
   std::allocator<unsigned long> >(class std::allocator<unsigned long> * __ptr64,void *
   __ptr64,unsigned __int64)'::`2'::M * __ptr64,unsigned __int64)
   
   Library: Visual Studio 2019 Release */

void deallocate(undefined8 param_1,void *param_2,longlong param_3)

{
  void *pvVar1;
  
  pvVar1 = param_2;
  if ((0xfff < (ulonglong)(param_3 * 4)) &&
     (pvVar1 = *(void **)((longlong)param_2 + -8),
     0x1f < (ulonglong)((longlong)param_2 + (-8 - (longlong)pvVar1)))) {
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
  FUN_180035134(pvVar1);
  return;
}

/* RVA 0x1d5c0 */
void FUN_18001d5c0(undefined8 param_1,void *param_2,longlong param_3)

{
  void *pvVar1;
  
  pvVar1 = param_2;
  if ((0xfff < (ulonglong)(param_3 << 6)) &&
     (pvVar1 = *(void **)((longlong)param_2 + -8),
     0x1f < (ulonglong)((longlong)param_2 + (-8 - (longlong)pvVar1)))) {
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
  FUN_180035134(pvVar1);
  return;
}

/* RVA 0x1d610 */
void FUN_18001d610(undefined8 param_1,void *param_2,longlong param_3)

{
  void *pvVar1;
  
  pvVar1 = param_2;
  if ((0xfff < (ulonglong)(param_3 << 5)) &&
     (pvVar1 = *(void **)((longlong)param_2 + -8),
     0x1f < (ulonglong)((longlong)param_2 + (-8 - (longlong)pvVar1)))) {
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
  FUN_180035134(pvVar1);
  return;
}

/* RVA 0x1d660 */
longlong * FUN_18001d660(longlong param_1,longlong *param_2,longlong param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  void *pvVar5;
  longlong lVar6;
  void *pvVar7;
  undefined8 *puVar8;
  
  puVar4 = *(undefined8 **)(param_1 + 8);
  if ((undefined8 *)(param_3 + 0x20) != puVar4) {
    puVar8 = (undefined8 *)(param_3 + 0x38);
    do {
      plVar1 = puVar8 + -3;
      plVar2 = puVar8 + -7;
      if (plVar2 != plVar1) {
        if (0xf < (ulonglong)puVar8[-4]) {
          pvVar5 = (void *)*plVar2;
          pvVar7 = pvVar5;
          if ((0xfff < puVar8[-4] + 1) &&
             (pvVar7 = *(void **)((longlong)pvVar5 + -8),
             0x1f < (ulonglong)((longlong)pvVar5 + (-8 - (longlong)pvVar7)))) goto LAB_18001d786;
          FUN_180035134(pvVar7);
        }
        *plVar2 = *plVar1;
        puVar8[-6] = puVar8[-2];
        puVar8[-5] = puVar8[-1];
        puVar8[-4] = *puVar8;
        puVar8[-1] = 0;
        *puVar8 = 0xf;
        *(undefined1 *)plVar1 = 0;
      }
      puVar3 = puVar8 + 1;
      puVar8 = puVar8 + 4;
    } while (puVar3 != puVar4);
  }
  lVar6 = *(longlong *)(param_1 + 8);
  if (0xf < *(ulonglong *)(lVar6 + -8)) {
    pvVar5 = *(void **)(lVar6 + -0x20);
    pvVar7 = pvVar5;
    if ((0xfff < *(ulonglong *)(lVar6 + -8) + 1) &&
       (pvVar7 = *(void **)((longlong)pvVar5 + -8),
       0x1f < (ulonglong)((longlong)pvVar5 + (-8 - (longlong)pvVar7)))) {
LAB_18001d786:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(pvVar7);
  }
  *(undefined8 *)(lVar6 + -0x10) = 0;
  *(undefined8 *)(lVar6 + -8) = 0xf;
  *(undefined1 *)(lVar6 + -0x20) = 0;
  *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + -0x20;
  *param_2 = param_3;
  return param_2;
}

/* RVA 0x1d790 */
void FUN_18001d790(basic_streambuf<char,std::char_traits<char>_> *param_1,locale *param_2)

{
  bool bVar1;
  _Facet_base *this;
  
  this = FUN_180008350(param_2);
  bVar1 = std::codecvt_base::always_noconv((codecvt_base *)this);
  if (bVar1) {
    *(undefined8 *)(param_1 + 0x68) = 0;
    return;
  }
  *(_Facet_base **)(param_1 + 0x68) = this;
                    /* WARNING: Could not recover jumptable at 0x00018001d7d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<char,std::char_traits<char>_>::_Init(param_1);
  return;
}

/* RVA 0x1d7e0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_18001d7e0(basic_streambuf<char,std::char_traits<char>_> *param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  basic_streambuf<char,std::char_traits<char>_> *pbVar4;
  size_t sVar5;
  size_t _Count;
  char cVar6;
  undefined1 auStackY_88 [32];
  char local_48;
  char local_47 [7];
  char *local_40;
  char *local_38;
  char local_30 [32];
  ulonglong local_10;
  
  local_10 = DAT_180052888 ^ (ulonglong)auStackY_88;
  if (param_2 == -1) {
    iVar1 = 0;
  }
  else {
    pcVar2 = std::basic_streambuf<char,std::char_traits<char>_>::pptr(param_1);
    cVar6 = (char)param_2;
    if (pcVar2 != (char *)0x0) {
      pcVar2 = std::basic_streambuf<char,std::char_traits<char>_>::epptr(param_1);
      pcVar3 = std::basic_streambuf<char,std::char_traits<char>_>::pptr(param_1);
      if (pcVar3 < pcVar2) {
        pcVar2 = std::basic_streambuf<char,std::char_traits<char>_>::_Pninc(param_1);
        *pcVar2 = cVar6;
        return param_2;
      }
    }
    if (*(longlong *)(param_1 + 0x80) != 0) {
      pbVar4 = (basic_streambuf<char,std::char_traits<char>_> *)
               std::basic_streambuf<char,std::char_traits<char>_>::eback(param_1);
      if (pbVar4 == param_1 + 0x70) {
        std::basic_streambuf<char,std::char_traits<char>_>::setg
                  (param_1,*(char **)(param_1 + 0x88),*(char **)(param_1 + 0x88),
                   *(char **)(param_1 + 0x90));
      }
      if (*(codecvt<char,char,_Mbstatet> **)(param_1 + 0x68) == (codecvt<char,char,_Mbstatet> *)0x0)
      {
        iVar1 = fputc((int)cVar6,*(FILE **)(param_1 + 0x80));
        if (iVar1 == -1) {
          return -1;
        }
        return param_2;
      }
      local_48 = cVar6;
      iVar1 = std::codecvt<char,char,_Mbstatet>::out
                        (*(codecvt<char,char,_Mbstatet> **)(param_1 + 0x68),
                         (_Mbstatet *)(param_1 + 0x74),&local_48,local_47,&local_38,local_30,
                         (char *)&local_10,&local_40);
      if ((iVar1 == 0) || (iVar1 == 1)) {
        _Count = (longlong)local_40 - (longlong)local_30;
        if ((_Count == 0) ||
           (sVar5 = fwrite(local_30,1,_Count,*(FILE **)(param_1 + 0x80)), _Count == sVar5)) {
          param_1[0x71] = (basic_streambuf<char,std::char_traits<char>_>)0x1;
          if (local_38 == &local_48) {
            return -1;
          }
          return param_2;
        }
      }
      else if (iVar1 == 3) {
        iVar1 = fputc((int)local_48,*(FILE **)(param_1 + 0x80));
        if (iVar1 == -1) {
          return -1;
        }
        return param_2;
      }
    }
    iVar1 = -1;
  }
  return iVar1;
}

/* RVA 0x1d9a0 */
uint FUN_18001d9a0(basic_streambuf<char,std::char_traits<char>_> *param_1,uint param_2)

{
  basic_streambuf<char,std::char_traits<char>_> *pbVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  basic_streambuf<char,std::char_traits<char>_> *pbVar5;
  
  pcVar3 = std::basic_streambuf<char,std::char_traits<char>_>::gptr(param_1);
  if (pcVar3 != (char *)0x0) {
    pcVar3 = std::basic_streambuf<char,std::char_traits<char>_>::eback(param_1);
    pcVar4 = std::basic_streambuf<char,std::char_traits<char>_>::gptr(param_1);
    if ((pcVar3 < pcVar4) &&
       ((param_2 == 0xffffffff ||
        (pcVar3 = std::basic_streambuf<char,std::char_traits<char>_>::gptr(param_1),
        (byte)pcVar3[-1] == param_2)))) {
      std::basic_streambuf<char,std::char_traits<char>_>::_Gndec(param_1);
      if (param_2 == 0xffffffff) {
        return 0;
      }
      return param_2;
    }
  }
  if ((*(FILE **)(param_1 + 0x80) != (FILE *)0x0) && (param_2 != 0xffffffff)) {
    if ((*(longlong *)(param_1 + 0x68) == 0) &&
       (iVar2 = ungetc(param_2 & 0xff,*(FILE **)(param_1 + 0x80)), iVar2 != -1)) {
      return param_2;
    }
    pbVar1 = param_1 + 0x70;
    pbVar5 = (basic_streambuf<char,std::char_traits<char>_> *)
             std::basic_streambuf<char,std::char_traits<char>_>::gptr(param_1);
    if (pbVar5 != pbVar1) {
      *pbVar1 = SUB41(param_2,0);
      pbVar5 = (basic_streambuf<char,std::char_traits<char>_> *)
               std::basic_streambuf<char,std::char_traits<char>_>::eback(param_1);
      if (pbVar5 != pbVar1) {
        pcVar3 = std::basic_streambuf<char,std::char_traits<char>_>::eback(param_1);
        *(char **)(param_1 + 0x88) = pcVar3;
        pcVar3 = std::basic_streambuf<char,std::char_traits<char>_>::egptr(param_1);
        *(char **)(param_1 + 0x90) = pcVar3;
      }
      std::basic_streambuf<char,std::char_traits<char>_>::setg
                (param_1,(char *)pbVar1,(char *)pbVar1,(char *)(param_1 + 0x71));
      return param_2;
    }
  }
  return 0xffffffff;
}

/* RVA 0x1dac0 */
fpos_t * FUN_18001dac0(basic_streambuf<char,std::char_traits<char>_> *param_1,fpos_t *param_2,
                      longlong param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  basic_streambuf<char,std::char_traits<char>_> *pbVar3;
  fpos_t fVar4;
  fpos_t local_res8;
  
  pbVar3 = (basic_streambuf<char,std::char_traits<char>_> *)
           std::basic_streambuf<char,std::char_traits<char>_>::gptr(param_1);
  if (((pbVar3 == param_1 + 0x70) && (param_4 == 1)) && (*(longlong *)(param_1 + 0x68) == 0)) {
    param_3 = param_3 + -1;
  }
  if (*(longlong *)(param_1 + 0x80) != 0) {
    bVar1 = FUN_18001c670((longlong *)param_1);
    if (bVar1) {
      if ((param_3 != 0) || (param_4 != 1)) {
        iVar2 = _fseeki64(*(FILE **)(param_1 + 0x80),param_3,param_4);
        if (iVar2 != 0) goto LAB_18001db61;
      }
      iVar2 = fgetpos(*(FILE **)(param_1 + 0x80),&local_res8);
      if (iVar2 == 0) {
        FUN_18001d020(param_1);
        fVar4 = *(fpos_t *)(param_1 + 0x74);
        *param_2 = local_res8;
        goto LAB_18001db6a;
      }
    }
  }
LAB_18001db61:
  *param_2 = -1;
  fVar4 = 0;
LAB_18001db6a:
  param_2[1] = 0;
  param_2[2] = fVar4;
  return param_2;
}

/* RVA 0x1db90 */
longlong *
FUN_18001db90(basic_streambuf<char,std::char_traits<char>_> *param_1,longlong *param_2,
             longlong *param_3)

{
  bool bVar1;
  int iVar2;
  longlong lVar3;
  longlong local_res8;
  
  local_res8 = param_3[1] + *param_3;
  if (*(longlong *)(param_1 + 0x80) != 0) {
    bVar1 = FUN_18001c670((longlong *)param_1);
    if (bVar1) {
      iVar2 = fsetpos(*(FILE **)(param_1 + 0x80),&local_res8);
      if (iVar2 == 0) {
        *(longlong *)(param_1 + 0x74) = param_3[2];
        FUN_18001d020(param_1);
        lVar3 = *(longlong *)(param_1 + 0x74);
        *param_2 = local_res8;
        goto LAB_18001dc04;
      }
    }
  }
  *param_2 = -1;
  lVar3 = 0;
LAB_18001dc04:
  param_2[1] = 0;
  param_2[2] = lVar3;
  return param_2;
}

/* RVA 0x1dc30 */
basic_streambuf<char,std::char_traits<char>_> *
FUN_18001dc30(basic_streambuf<char,std::char_traits<char>_> *param_1,char *param_2,size_t param_3)

{
  longlong lVar1;
  int iVar2;
  int *local_res8;
  char **local_res10;
  char **local_res18 [2];
  
  if ((param_2 != (char *)0x0) || (iVar2 = 4, param_3 != 0)) {
    iVar2 = 0;
  }
  if (*(FILE **)(param_1 + 0x80) != (FILE *)0x0) {
    iVar2 = setvbuf(*(FILE **)(param_1 + 0x80),param_2,iVar2,param_3);
    if (iVar2 == 0) {
      lVar1 = *(longlong *)(param_1 + 0x80);
      param_1[0x7c] = (basic_streambuf<char,std::char_traits<char>_>)0x1;
      param_1[0x71] = (basic_streambuf<char,std::char_traits<char>_>)0x0;
      std::basic_streambuf<char,std::char_traits<char>_>::_Init(param_1);
      if (lVar1 != 0) {
        local_res18[0] = (char **)0x0;
        local_res10 = (char **)0x0;
        local_res8 = (int *)0x0;
        _get_stream_buffer_pointers(lVar1,local_res18,&local_res10,&local_res8);
        std::basic_streambuf<char,std::char_traits<char>_>::_Init
                  (param_1,local_res18[0],local_res10,local_res8,local_res18[0],local_res10,
                   local_res8);
      }
      *(longlong *)(param_1 + 0x80) = lVar1;
      *(undefined8 *)(param_1 + 0x74) = DAT_180053598;
      *(undefined8 *)(param_1 + 0x68) = 0;
      return param_1;
    }
  }
  return (basic_streambuf<char,std::char_traits<char>_> *)0x0;
}

/* RVA 0x1dd10 */
int FUN_18001dd10(longlong *param_1)

{
  int iVar1;
  
  if (param_1[0x10] != 0) {
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,0xffffffff);
    if (iVar1 != -1) {
      iVar1 = fflush((FILE *)param_1[0x10]);
      return (-1 < iVar1) - 1;
    }
  }
  return 0;
}

/* RVA 0x1dd60 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_18001dd60(basic_streambuf<char,std::char_traits<char>_> *param_1)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  byte *pbVar5;
  basic_streambuf<char,std::char_traits<char>_> *pbVar6;
  ulonglong uVar7;
  char *******pppppppcVar8;
  FILE *_File;
  uint uVar9;
  ulonglong uVar10;
  undefined1 auStackY_88 [32];
  byte local_48;
  char local_47 [7];
  char *local_40;
  byte *local_38;
  char *******local_30;
  undefined8 uStack_28;
  ulonglong local_20;
  ulonglong local_18;
  ulonglong local_10;
  
  local_10 = DAT_180052888 ^ (ulonglong)auStackY_88;
  pcVar3 = std::basic_streambuf<char,std::char_traits<char>_>::gptr(param_1);
  if (pcVar3 != (char *)0x0) {
    pcVar3 = std::basic_streambuf<char,std::char_traits<char>_>::egptr(param_1);
    pcVar4 = std::basic_streambuf<char,std::char_traits<char>_>::gptr(param_1);
    if (pcVar4 < pcVar3) {
      pbVar5 = (byte *)std::basic_streambuf<char,std::char_traits<char>_>::_Gninc(param_1);
      return (uint)*pbVar5;
    }
  }
  if (*(longlong *)(param_1 + 0x80) == 0) {
    uVar9 = 0xffffffff;
  }
  else {
    pbVar6 = (basic_streambuf<char,std::char_traits<char>_> *)
             std::basic_streambuf<char,std::char_traits<char>_>::eback(param_1);
    if (pbVar6 == param_1 + 0x70) {
      std::basic_streambuf<char,std::char_traits<char>_>::setg
                (param_1,*(char **)(param_1 + 0x88),*(char **)(param_1 + 0x88),
                 *(char **)(param_1 + 0x90));
    }
    _File = *(FILE **)(param_1 + 0x80);
    if (*(longlong *)(param_1 + 0x68) == 0) {
      uVar1 = fgetc(_File);
      uVar9 = 0xffffffff;
      if (uVar1 != 0xffffffff) {
        uVar9 = uVar1 & 0xff;
      }
    }
    else {
      uStack_28 = 0;
      local_20 = 0;
      local_18 = 0xf;
      local_30 = (char *******)0x0;
LAB_18001de46:
      iVar2 = fgetc(_File);
      uVar7 = local_20;
      if (iVar2 != -1) {
        if (local_20 < local_18) {
          pppppppcVar8 = (char *******)&local_30;
          if (0xf < local_18) {
            pppppppcVar8 = local_30;
          }
          pcVar3 = (char *)((longlong)pppppppcVar8 + local_20);
          local_20 = local_20 + 1;
          *pcVar3 = (char)iVar2;
          *(char *)((longlong)pppppppcVar8 + uVar7 + 1) = '\0';
        }
        else {
          FUN_180007cd0(&local_30,1,0,(char)iVar2);
        }
        pppppppcVar8 = (char *******)&local_30;
        if (0xf < local_18) {
          pppppppcVar8 = local_30;
        }
        iVar2 = std::codecvt<char,char,_Mbstatet>::in
                          (*(codecvt<char,char,_Mbstatet> **)(param_1 + 0x68),
                           (_Mbstatet *)(param_1 + 0x74),(char *)pppppppcVar8,
                           (char *)((longlong)pppppppcVar8 + local_20),&local_40,(char *)&local_48,
                           local_47,(char **)&local_38);
        if ((iVar2 == 0) || (iVar2 == 1)) {
          if (local_38 == &local_48) goto code_r0x00018001df02;
          pppppppcVar8 = (char *******)&local_30;
          if (0xf < local_18) {
            pppppppcVar8 = local_30;
          }
          pcVar3 = (char *)((longlong)pppppppcVar8 + (local_20 - (longlong)local_40));
          while (0 < (longlong)pcVar3) {
            pcVar3 = pcVar3 + -1;
            ungetc((int)pcVar3[(longlong)local_40],*(FILE **)(param_1 + 0x80));
          }
          uVar9 = (uint)local_48;
          goto LAB_18001dfba;
        }
        if (iVar2 == 3) {
          pppppppcVar8 = (char *******)&local_30;
          if (0xf < local_18) {
            pppppppcVar8 = local_30;
          }
          uVar9 = (uint)*(char *)pppppppcVar8;
          goto LAB_18001dfba;
        }
      }
      uVar9 = 0xffffffff;
LAB_18001dfba:
      if (0xf < local_18) {
        pppppppcVar8 = local_30;
        if ((0xfff < local_18 + 1) &&
           (pppppppcVar8 = (char *******)local_30[-1],
           (char *)0x1f < (char *)((longlong)local_30 + (-8 - (longlong)pppppppcVar8)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        FUN_180035134(pppppppcVar8);
      }
    }
  }
  return uVar9;
code_r0x00018001df02:
  pppppppcVar8 = (char *******)&local_30;
  if (0xf < local_18) {
    pppppppcVar8 = local_30;
  }
  uVar7 = (longlong)local_40 - (longlong)pppppppcVar8;
  if (local_20 < (ulonglong)((longlong)local_40 - (longlong)pppppppcVar8)) {
    uVar7 = local_20;
  }
  pppppppcVar8 = (char *******)&local_30;
  if (0xf < local_18) {
    pppppppcVar8 = local_30;
  }
  uVar10 = local_20 - uVar7;
  memmove(pppppppcVar8,(char *)((longlong)pppppppcVar8 + uVar7),uVar10 + 1);
  _File = *(FILE **)(param_1 + 0x80);
  local_20 = uVar10;
  goto LAB_18001de46;
}

/* RVA 0x1e020 */
ulonglong FUN_18001e020(basic_streambuf<char,std::char_traits<char>_> *param_1)

{
  char *pcVar1;
  char *pcVar2;
  byte *pbVar3;
  ulonglong uVar4;
  
  pcVar1 = std::basic_streambuf<char,std::char_traits<char>_>::gptr(param_1);
  if (pcVar1 != (char *)0x0) {
    pcVar1 = std::basic_streambuf<char,std::char_traits<char>_>::egptr(param_1);
    pcVar2 = std::basic_streambuf<char,std::char_traits<char>_>::gptr(param_1);
    if (pcVar2 < pcVar1) {
      pbVar3 = (byte *)std::basic_streambuf<char,std::char_traits<char>_>::gptr(param_1);
      return (ulonglong)*pbVar3;
    }
  }
  uVar4 = (**(code **)(*(longlong *)param_1 + 0x38))(param_1);
  if ((int)uVar4 == -1) {
    return uVar4;
  }
  (**(code **)(*(longlong *)param_1 + 0x20))(param_1,uVar4 & 0xffffffff);
  return uVar4 & 0xffffffff;
}

/* RVA 0x1e0a0 */
char * FUN_18001e0a0(longlong param_1)

{
  char *pcVar1;
  
  pcVar1 = "Unknown exception";
  if (*(char **)(param_1 + 8) != (char *)0x0) {
    pcVar1 = *(char **)(param_1 + 8);
  }
  return pcVar1;
}

/* RVA 0x1e0c0 */
longlong FUN_18001e0c0(basic_streambuf<char,std::char_traits<char>_> *param_1,char *param_2,
                      ulonglong param_3)

{
  __int64 _Var1;
  ulonglong uVar2;
  char *_Src;
  size_t sVar3;
  ulonglong _Count;
  ulonglong _Size;
  
  if ((longlong)param_3 < 1) {
    return 0;
  }
  if (*(longlong *)(param_1 + 0x68) != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018001e108. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    _Var1 = std::basic_streambuf<char,std::char_traits<char>_>::xsgetn(param_1,param_2,param_3);
    return _Var1;
  }
  uVar2 = std::basic_streambuf<char,std::char_traits<char>_>::_Gnavail(param_1);
  _Count = param_3;
  if (uVar2 != 0) {
    _Size = param_3;
    if (uVar2 < param_3) {
      _Size = uVar2;
    }
    _Src = std::basic_streambuf<char,std::char_traits<char>_>::gptr(param_1);
    memcpy(param_2,_Src,_Size);
    param_2 = param_2 + _Size;
    _Count = param_3 - _Size;
    std::basic_streambuf<char,std::char_traits<char>_>::gbump(param_1,(int)_Size);
  }
  if (*(longlong *)(param_1 + 0x80) != 0) {
    FUN_18001d020(param_1);
    do {
      if (_Count < 0x1000) {
        if (_Count != 0) {
          sVar3 = fread(param_2,1,_Count,*(FILE **)(param_1 + 0x80));
          _Count = _Count - sVar3;
        }
        break;
      }
      sVar3 = fread(param_2,1,0xfff,*(FILE **)(param_1 + 0x80));
      _Count = _Count - sVar3;
      param_2 = param_2 + sVar3;
    } while (sVar3 == 0xfff);
  }
  return param_3 - _Count;
}

/* RVA 0x1e200 */
longlong FUN_18001e200(basic_streambuf<char,std::char_traits<char>_> *param_1,char *param_2,
                      size_t param_3)

{
  __int64 _Var1;
  size_t sVar2;
  char *_Dst;
  size_t _Count;
  
  if (*(longlong *)(param_1 + 0x68) != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018001e221. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    _Var1 = std::basic_streambuf<char,std::char_traits<char>_>::xsputn(param_1,param_2,param_3);
    return _Var1;
  }
  sVar2 = std::basic_streambuf<char,std::char_traits<char>_>::_Pnavail(param_1);
  _Count = param_3;
  if (0 < (longlong)param_3) {
    if (0 < (longlong)sVar2) {
      if ((longlong)param_3 < (longlong)sVar2) {
        sVar2 = param_3;
      }
      _Dst = std::basic_streambuf<char,std::char_traits<char>_>::pptr(param_1);
      memcpy(_Dst,param_2,sVar2);
      param_2 = param_2 + sVar2;
      _Count = param_3 - sVar2;
      std::basic_streambuf<char,std::char_traits<char>_>::pbump(param_1,(int)sVar2);
      if ((longlong)_Count < 1) goto LAB_18001e29c;
    }
    if (*(FILE **)(param_1 + 0x80) != (FILE *)0x0) {
      sVar2 = fwrite(param_2,1,_Count,*(FILE **)(param_1 + 0x80));
      _Count = _Count - sVar2;
    }
  }
LAB_18001e29c:
  return param_3 - _Count;
}

/* RVA 0x1e2c0 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_18001e2c0(undefined8 *param_1)

{
  undefined8 *puVar1;
  longlong ****pppplVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong ****pppplVar5;
  longlong **pplVar6;
  _func_5397 *p_Var7;
  longlong ***ppplVar8;
  _func_5403 *p_Var9;
  _func_5396 *p_Var10;
  byte bVar11;
  IStorage *pIVar12;
  char cVar13;
  int iVar14;
  HRESULT HVar15;
  longlong *plVar16;
  longlong lVar17;
  undefined8 uVar18;
  ulonglong uVar19;
  LPCSTR ***ppppCVar20;
  longlong lVar21;
  undefined8 *puVar22;
  longlong *****ppppplVar23;
  ulonglong uVar24;
  longlong *****ppppplVar25;
  void *pvVar26;
  longlong *****ppppplVar27;
  longlong *****ppppplVar28;
  LPCSTR ****pppppCVar29;
  undefined8 *****pppppuVar30;
  undefined8 *puVar31;
  undefined8 uVar32;
  undefined2 *puVar33;
  longlong *****ppppplVar34;
  undefined1 *puVar35;
  undefined1 *puVar36;
  ulonglong uVar37;
  size_t sVar38;
  size_t sVar39;
  longlong ****pppplVar40;
  undefined1 *puVar41;
  undefined8 *puVar42;
  undefined8 uStack_380;
  undefined1 auStack_378 [32];
  undefined8 uStack_358;
  int aiStack_350 [6];
  byte local_338;
  char cStack_337;
  longlong *****local_330;
  IStorage *local_328;
  longlong *local_320;
  undefined8 *local_318;
  longlong *local_310;
  longlong *local_308;
  _union_2707 local_300;
  ulonglong uStack_2e8;
  _union_2707 local_2e0;
  longlong *local_2c8;
  _union_2707 local_2c0;
  LPCSTR ****local_2a8;
  undefined8 uStack_2a0;
  ulonglong local_298;
  ulonglong local_290;
  longlong *****local_288;
  undefined8 uStack_280;
  longlong ****local_278;
  ulonglong local_270;
  undefined8 *****local_268;
  undefined8 uStack_260;
  size_t local_258;
  ulonglong uStack_250;
  undefined8 *****local_248;
  _union_1719 _Stack_240;
  size_t local_238;
  ulonglong uStack_230;
  int local_228;
  LPCSTR ***local_218;
  LPCSTR ***ppppCStack_210;
  ulonglong local_208;
  ulonglong local_200;
  void *local_1f8;
  undefined8 uStack_1f0;
  size_t local_1e8;
  ulonglong uStack_1e0;
  int local_1d8;
  IID local_1c8;
  undefined1 *local_1b8;
  undefined1 local_1b0 [136];
  char local_128 [26];
  undefined1 auStack_10e [6];
  char local_108 [199];
  undefined1 local_41;
  ulonglong local_38;
  
  local_38 = DAT_180052888 ^ (ulonglong)&local_338;
  local_328 = (IStorage *)0x0;
  uStack_380 = 0x18001e30f;
  local_318 = param_1;
  plVar16 = (longlong *)HYGetCurrentModel();
  if (plVar16 == (longlong *)0x0) {
    uStack_380 = 0x18001e31c;
    plVar16 = (longlong *)HappGetTree();
  }
  else {
    uStack_380 = 0x18001e32a;
    (**(code **)(*plVar16 + 8))(plVar16);
  }
  local_320 = (longlong *)0x0;
  local_308 = (longlong *)0x0;
  uStack_380 = 0x18001e345;
  iVar14 = (**(code **)*plVar16)(plVar16,&DAT_180042b38,&local_308);
  if (-1 < iVar14) {
    local_310 = (longlong *)0x0;
    uStack_380 = 0x18001e366;
    iVar14 = (**(code **)(*local_308 + 0x20))(local_308,&DAT_180042b18,&local_310);
    if (-1 < iVar14) {
      local_330 = (longlong *****)0x0;
      uStack_380 = 0x18001e380;
      iVar14 = (**(code **)(*local_310 + 0x38))(local_310,&local_330);
      if (-1 < iVar14) {
        uStack_380 = 0x18001e399;
        iVar14 = (*(code *)(*local_330)[3])(local_330,1,&local_2e0);
        while (-1 < iVar14) {
          uStack_380 = 0x18001e3b4;
          iVar14 = (*(code *)**(undefined8 **)CONCAT62(local_2e0._2_6_,local_2e0.n2.vt))
                             ((undefined8 *)CONCAT62(local_2e0._2_6_,local_2e0.n2.vt),&DAT_180042b18
                              ,&local_320);
          uStack_380 = 0x18001e3c0;
          (**(code **)(*(longlong *)CONCAT62(local_2e0._2_6_,local_2e0.n2.vt) + 0x10))();
          if (-1 < iVar14) break;
          uStack_380 = 0x18001e3d9;
          iVar14 = (*(code *)(*local_330)[3])(local_330,1,&local_2e0);
        }
        uStack_380 = 0x18001e3e7;
        (*(code *)(*local_330)[2])();
      }
      uStack_380 = 0x18001e3f1;
      (**(code **)(*local_310 + 0x10))();
    }
    uStack_380 = 0x18001e3fb;
    (**(code **)(*local_308 + 0x10))();
  }
  puVar35 = auStack_378;
  local_278 = (longlong ****)0x4;
  uStack_280 = 0;
  local_288 = (longlong *****)0x746f6f52;
  local_270 = 0xf;
  uStack_380 = 0x18001e43f;
  iVar14 = (**(code **)*plVar16)(plVar16,&DAT_180041fd0,&local_2c8);
  if (iVar14 < 0) {
    local_41 = 0;
    uStack_380 = 0x18001e5b2;
    HYfullid("_dummy",local_108,199);
    uVar24 = 0xffffffffffffffff;
    do {
      uVar37 = uVar24;
      uVar24 = uVar37 + 1;
    } while (local_108[uVar37 + 1] != '\0');
    if (7 < uVar37 + 1) {
      if (199 < uVar37 - 6) {
        uStack_380 = 0x18001f200;
        FUN_180035758();
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      auStack_10e[uVar37] = 0;
      sVar38 = 0xffffffffffffffff;
      do {
        sVar39 = sVar38 + 1;
        lVar17 = sVar38 + 1;
        sVar38 = sVar39;
      } while (local_108[lVar17] != '\0');
      uStack_380 = 0x18001e61c;
      FUN_18001d350((longlong *)&local_288,local_108,sVar39);
    }
  }
  else {
    uStack_380 = 0x18001e450;
    AfxVariantInit((tagVARIANT *)&local_2e0.n2);
    uStack_380 = 0x18001e45a;
    VariantInit((VARIANTARG *)&local_2c0.n2);
    uStack_380 = 0x18001e464;
    VariantInit((VARIANTARG *)&local_300.n2);
    local_2c0.n2.vt = 0;
    local_248 = (undefined8 *****)((ulonglong)(uint6)local_2c0._2_6_ << 0x10);
    local_238 = local_2c0._16_8_;
    _Stack_240.s2 = (_struct_1720)local_2c0.decVal.u2;
    uStack_380 = 0x18001e4a0;
    (**(code **)(*local_2c8 + 0x98))(local_2c8,0x41,&local_248,&local_2e0);
    if (local_2e0.n2.vt == 8) {
      local_1b8 = local_1b0;
      uStack_380 = 0x18001e4c8;
      FUN_18000d880(&local_1b8,(LPCWSTR)local_2e0.decVal.u2,0);
      sVar38 = 0xffffffffffffffff;
      do {
        sVar38 = sVar38 + 1;
      } while (local_1b8[sVar38] != '\0');
      uStack_380 = 0x18001e4eb;
      FUN_18001d350((longlong *)&local_288,local_1b8,sVar38);
      if (local_1b8 != local_1b0) {
        uStack_380 = 0x18001e504;
        free(local_1b8);
      }
    }
    uStack_380 = 0x18001e50e;
    (**(code **)(*local_2c8 + 0x10))();
    uStack_380 = 0x18001e518;
    VariantClear((VARIANTARG *)&local_2e0.n2);
  }
  pppplVar5 = local_278;
  ppppplVar25 = local_288;
  puVar41 = &DAT_180041bf8;
  cStack_337 = '\0';
  uStack_260 = 0;
  ppppplVar23 = (longlong *****)&local_288;
  if (0xf < local_270) {
    ppppplVar23 = local_288;
  }
  local_338 = 0;
  local_258 = _DAT_180041f70;
  uStack_250 = _UNK_180041f78;
  local_268 = (undefined8 *****)0x0;
  lVar17 = 0;
  do {
    lVar21 = lVar17 + 1;
    if (*(char *)((longlong)ppppplVar23 + lVar17) != (&DAT_180041bf8)[lVar17]) {
      local_330 = (longlong *****)&local_288;
      if (0xf < local_270) {
        local_330 = local_288;
      }
      goto LAB_18001e634;
    }
    lVar17 = lVar21;
  } while (lVar21 != 5);
  local_330 = (longlong *****)0x0;
LAB_18001e634:
  if (local_320 == (longlong *)0x0) {
    puVar1 = *(undefined8 **)param_1[3];
    puVar31 = (undefined8 *)puVar1[1];
    puVar42 = puVar1;
    if (*(char *)((longlong)puVar1[1] + 0x19) == '\0') {
      do {
        puVar22 = puVar31 + 4;
        ppppplVar23 = (longlong *****)&local_288;
        if (0xf < local_270) {
          ppppplVar23 = ppppplVar25;
        }
        if (0xf < (ulonglong)puVar31[7]) {
          puVar22 = (undefined8 *)puVar31[4];
        }
        pppplVar2 = (longlong ****)puVar31[6];
        pppplVar40 = pppplVar2;
        if (pppplVar5 < pppplVar2) {
          pppplVar40 = pppplVar5;
        }
        uStack_380 = 0x18001e691;
        iVar14 = memcmp(puVar22,ppppplVar23,(size_t)pppplVar40);
        if (iVar14 == 0) {
          if (pppplVar5 <= pppplVar2) goto LAB_18001e69f;
LAB_18001e82e:
          puVar22 = (undefined8 *)puVar31[2];
        }
        else {
          if (iVar14 < 0) goto LAB_18001e82e;
LAB_18001e69f:
          puVar22 = (undefined8 *)*puVar31;
          puVar42 = puVar31;
        }
        puVar31 = puVar22;
      } while (*(char *)((longlong)puVar22 + 0x19) == '\0');
      param_1 = local_318;
    }
    if (*(char *)((longlong)puVar42 + 0x19) == '\0') {
      puVar31 = puVar42 + 4;
      if (0xf < (ulonglong)puVar42[7]) {
        puVar31 = (undefined8 *)puVar42[4];
      }
      pppplVar2 = (longlong ****)puVar42[6];
      ppppplVar23 = (longlong *****)&local_288;
      if (0xf < local_270) {
        ppppplVar23 = ppppplVar25;
      }
      pppplVar40 = pppplVar5;
      if (pppplVar2 < pppplVar5) {
        pppplVar40 = pppplVar2;
      }
      uStack_380 = 0x18001e6ee;
      iVar14 = memcmp(ppppplVar23,puVar31,(size_t)pppplVar40);
      if (iVar14 == 0) {
        if (pppplVar2 <= pppplVar5) goto LAB_18001e840;
      }
      else if (-1 < iVar14) {
LAB_18001e840:
        if (puVar42 != puVar1) {
          cStack_337 = '\x01';
          goto LAB_18001e71a;
        }
      }
    }
    uStack_380 = 0x18001e70c;
    cVar13 = HAHierPFSVData(local_330,&local_268);
    if (cVar13 != '\0') {
      local_338 = 1;
      goto LAB_18001e71a;
    }
    uStack_380 = 0x18001e85b;
    (**(code **)(*plVar16 + 0x10))(plVar16);
LAB_18001e85b:
    if (0xf < uStack_250) {
      pppppuVar30 = local_268;
      if ((0xfff < uStack_250 + 1) &&
         (pppppuVar30 = (undefined8 *****)local_268[-1],
         0x1f < (ulonglong)((longlong)local_268 + (-8 - (longlong)pppppuVar30))))
      goto LAB_18001f1f4;
      *(undefined8 *)(puVar35 + -8) = 0x18001e89c;
      FUN_180035134(pppppuVar30);
    }
LAB_18001e8a3:
    local_268 = (undefined8 *****)((ulonglong)local_268 & 0xffffffffffffff00);
    local_258 = _DAT_180041f70;
    uStack_250 = _UNK_180041f78;
    if (local_270 < 0x10) goto LAB_18001e8f4;
    ppppplVar25 = local_288;
    if (0xfff < local_270 + 1) {
      ppppplVar25 = (longlong *****)local_288[-1];
      lVar17 = (longlong)local_288 - (longlong)ppppplVar25;
joined_r0x00018001f1ee:
      local_258 = _DAT_180041f70;
      uStack_250 = _UNK_180041f78;
      if (0x1f < lVar17 - 8U) {
LAB_18001f1f4:
                    /* WARNING: Subroutine does not return */
        *(undefined **)(puVar35 + -8) = &UNK_18001f1fa;
        _invalid_parameter_noinfo_noreturn();
      }
    }
  }
  else {
LAB_18001e71a:
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
    local_298 = 0;
    uStack_2a0 = 0;
    local_2a8 = (LPCSTR ****)0x0;
    local_290 = 0xf;
    uStack_380 = 0x18001e757;
    FUN_180001ce0(local_128,&DAT_180041c08,(ulonglong)*(uint *)(param_1 + 4),puVar41);
    sVar38 = 0xffffffffffffffff;
    do {
      sVar39 = sVar38 + 1;
      lVar17 = sVar38 + 1;
      sVar38 = sVar39;
    } while (local_128[lVar17] != '\0');
    uStack_380 = 0x18001e782;
    FUN_18001d350((longlong *)&local_2a8,local_128,sVar39);
    pppppCVar29 = (LPCSTR ****)&local_2a8;
    if (local_290 < 0x10) {
LAB_18001e7ad:
      lVar17 = -1;
      do {
        lVar21 = lVar17;
        lVar17 = lVar21 + 1;
      } while (*(char *)((longlong)pppppCVar29 + lVar17) != '\0');
      iVar14 = (int)lVar21 + 2;
      puVar35 = auStack_378;
      if (0x3fffffff < iVar14) goto LAB_18001e929;
      lVar17 = (longlong)(int)lVar17 * 2;
      uVar24 = lVar17 + 0x11;
      if (uVar24 <= lVar17 + 2U) {
        uVar24 = 0xffffffffffffff0;
      }
      uStack_380 = 0x18001e7ef;
      lVar17 = -(uVar24 & 0xfffffffffffffff0);
      puVar35 = auStack_378 + lVar17;
      puVar33 = (undefined2 *)((longlong)aiStack_350 + lVar17 + 0x18);
      if (puVar33 == (undefined2 *)0x0) goto LAB_18001e929;
      *(int *)((longlong)aiStack_350 + lVar17) = iVar14;
      *puVar33 = 0;
      *(undefined2 **)(auStack_378 + lVar17 + 0x20) = puVar33;
      *(undefined8 *)(auStack_378 + lVar17 + -8) = 0x18001e81a;
      iVar14 = MultiByteToWideChar(0,0,(LPCSTR)pppppCVar29,-1,
                                   *(LPWSTR *)(auStack_378 + lVar17 + 0x20),
                                   *(int *)((longlong)aiStack_350 + lVar17));
      puVar35 = auStack_378 + lVar17;
      if (iVar14 == 0) {
        puVar33 = (undefined2 *)0x0;
        puVar35 = auStack_378 + lVar17;
      }
    }
    else {
      puVar35 = auStack_378;
      pppppCVar29 = local_2a8;
      if (local_2a8 != (LPCSTR ****)0x0) goto LAB_18001e7ad;
LAB_18001e929:
      puVar33 = (undefined2 *)0x0;
    }
    plVar3 = (longlong *)*param_1;
    *(IStorage ***)(puVar35 + 0x30) = &local_328;
    *(undefined4 *)(puVar35 + 0x28) = 0;
    *(undefined8 *)(puVar35 + 0x20) = 0;
    pcVar4 = *(code **)(*plVar3 + 0x30);
    *(undefined8 *)(puVar35 + -8) = 0x18001e953;
    iVar14 = (*pcVar4)(plVar3,puVar33,0);
    if (iVar14 < 0) {
      pppppCVar29 = (LPCSTR ****)&local_2a8;
      puVar41 = puVar35;
      if ((local_290 < 0x10) || (pppppCVar29 = local_2a8, local_2a8 != (LPCSTR ****)0x0)) {
        lVar17 = -1;
        do {
          lVar21 = lVar17;
          lVar17 = lVar21 + 1;
        } while (*(char *)((longlong)pppppCVar29 + lVar17) != '\0');
        iVar14 = (int)lVar21 + 2;
        if (0x3fffffff < iVar14) goto LAB_18001e9e8;
        lVar17 = (longlong)(int)lVar17 * 2;
        uVar24 = lVar17 + 0x11;
        if (uVar24 <= lVar17 + 2U) {
          uVar24 = 0xffffffffffffff0;
        }
        *(undefined8 *)(puVar35 + -8) = 0x18001e9b9;
        lVar17 = -(uVar24 & 0xfffffffffffffff0);
        puVar41 = puVar35 + lVar17;
        puVar36 = puVar35 + lVar17;
        puVar33 = (undefined2 *)(puVar35 + lVar17 + 0x40);
        if (puVar33 == (undefined2 *)0x0) goto LAB_18001e9e8;
        *(int *)(puVar35 + lVar17 + 0x28) = iVar14;
        *puVar33 = 0;
        *(undefined2 **)(puVar35 + lVar17 + 0x20) = puVar33;
        *(undefined8 *)(puVar35 + lVar17 + -8) = 0x18001e9e0;
        iVar14 = MultiByteToWideChar(0,0,(LPCSTR)pppppCVar29,-1,*(LPWSTR *)(puVar35 + lVar17 + 0x20)
                                     ,*(int *)(puVar35 + lVar17 + 0x28));
        puVar35 = puVar35 + lVar17;
        if (iVar14 == 0) {
          puVar33 = (undefined2 *)0x0;
          puVar35 = puVar36;
        }
      }
      else {
LAB_18001e9e8:
        puVar33 = (undefined2 *)0x0;
        puVar35 = puVar41;
      }
      plVar3 = (longlong *)*param_1;
      *(IStorage ***)(puVar35 + 0x28) = &local_328;
      *(undefined4 *)(puVar35 + 0x20) = 0;
      pcVar4 = *(code **)(*plVar3 + 0x28);
      *(undefined8 *)(puVar35 + -8) = 0x18001ea0d;
      iVar14 = (*pcVar4)(plVar3,puVar33,0x1012);
      if (iVar14 < 0) {
        if (local_320 != (longlong *)0x0) {
          pcVar4 = *(code **)(*local_320 + 0x10);
          *(undefined8 *)(puVar35 + -8) = 0x18001ea23;
          (*pcVar4)();
        }
        pcVar4 = *(code **)(*plVar16 + 0x10);
        *(undefined8 *)(puVar35 + -8) = 0x18001ea2c;
        (*pcVar4)(plVar16);
        if (0xf < local_290) {
          pppppCVar29 = local_2a8;
          if ((0xfff < local_290 + 1) &&
             (pppppCVar29 = (LPCSTR ****)local_2a8[-1],
             0x1f < (ulonglong)((longlong)local_2a8 + (-8 - (longlong)pppppCVar29))))
          goto LAB_18001f1f4;
          *(undefined8 *)(puVar35 + -8) = 0x18001ea6d;
          FUN_180035134(pppppCVar29);
        }
        local_298 = 0;
        local_290 = 0xf;
        local_2a8 = (LPCSTR ****)((ulonglong)local_2a8 & 0xffffffffffffff00);
        goto LAB_18001e85b;
      }
    }
    pppplVar5 = local_278;
    ppppplVar25 = (longlong *****)&local_288;
    if (0xf < local_270) {
      ppppplVar25 = local_288;
    }
    local_300._0_8_ = (_union_2707 *)0x0;
    local_300.decVal.u2 = (_union_1719)(_struct_1720)0x0;
    local_300._16_8_ = (longlong ****)0x0;
    uStack_2e8 = 0;
    if ((longlong ****)0x7fffffffffffffff < local_278) {
LAB_18001f201:
                    /* WARNING: Subroutine does not return */
      *(undefined **)(puVar35 + -8) = &UNK_18001f206;
      FUN_18001d1b0();
    }
    if (local_278 < (longlong ****)0x10) {
      uVar18 = *ppppplVar25;
      local_300.decVal.u2 = (_union_1719)*(_union_1719 *)&((_union_1719 *)(ppppplVar25 + 1))->s2;
      uVar24 = 0xf;
      local_300._16_8_ = local_278;
      uStack_2e8 = 0xf;
      local_300._0_8_ = uVar18;
    }
    else {
      uVar24 = (ulonglong)local_278 | 0xf;
      if (uVar24 < 0x8000000000000000) {
        if (uVar24 < 0x16) {
          uVar24 = 0x16;
        }
      }
      else {
        uVar24 = 0x7fffffffffffffff;
      }
      *(undefined8 *)(puVar35 + -8) = 0x18001eb17;
      uVar18 = FUN_18001d210(&local_300,uVar24 + 1);
      local_300._16_8_ = pppplVar5;
      local_300._0_8_ = uVar18;
      uStack_2e8 = uVar24;
      *(undefined8 *)(puVar35 + -8) = 0x18001eb35;
      memcpy((void *)uVar18,ppppplVar25,(longlong)pppplVar5 + 1);
    }
    _Stack_240.Lo64 = 0;
    local_248 = (undefined8 *****)0x0;
    uVar32 = &local_300;
    if (0xf < uVar24) {
      uVar32 = uVar18;
    }
    local_238 = _DAT_180041f70;
    uStack_230 = _UNK_180041f78;
    *(undefined8 *)(puVar35 + -8) = 0x18001eb71;
    FUN_18001d350((longlong *)&local_248,(void *)uVar32,(size_t)pppplVar5);
    bVar11 = local_338;
    local_228 = local_338 + 1;
    if (0xf < uStack_2e8) {
      uVar18 = local_300._0_8_;
      if ((0xfff < uStack_2e8 + 1) &&
         (uVar18 = *(longlong ****)(local_300._0_8_ + -8), 0x1f < (local_300._0_8_ - uVar18) - 8))
      goto LAB_18001f1f4;
      *(undefined8 *)(puVar35 + -8) = 0x18001ebbb;
      FUN_180035134((void *)uVar18);
    }
    uVar24 = local_298;
    pppppCVar29 = (LPCSTR ****)&local_2a8;
    if (0xf < local_290) {
      pppppCVar29 = local_2a8;
    }
    local_218 = (LPCSTR ***)0x0;
    ppppCStack_210 = (LPCSTR ***)0x0;
    if (0x7fffffffffffffff < local_298) goto LAB_18001f201;
    if (local_298 < 0x10) {
      local_218 = *pppppCVar29;
      ppppCStack_210 = pppppCVar29[1];
      local_208 = local_298;
      local_200 = 0xf;
    }
    else {
      uVar19 = local_298 | 0xf;
      uVar37 = 0x7fffffffffffffff;
      if ((uVar19 < 0x8000000000000000) && (uVar37 = uVar19, uVar19 < 0x16)) {
        uVar37 = 0x16;
      }
      *(undefined8 *)(puVar35 + -8) = 0x18001ec3c;
      ppppCVar20 = FUN_18001d210(&local_218,uVar37 + 1);
      local_208 = uVar24;
      local_218 = ppppCVar20;
      local_200 = uVar37;
      *(undefined8 *)(puVar35 + -8) = 0x18001ec60;
      memcpy(ppppCVar20,pppppCVar29,uVar24 + 1);
    }
    sVar38 = local_238;
    pppppuVar30 = &local_248;
    if (0xf < uStack_230) {
      pppppuVar30 = local_248;
    }
    uStack_1f0 = 0;
    local_1f8 = (void *)0x0;
    local_1e8 = _DAT_180041f70;
    uStack_1e0 = _UNK_180041f78;
    *(undefined8 *)(puVar35 + -8) = 0x18001ecab;
    FUN_18001d350((longlong *)&local_1f8,pppppuVar30,sVar38);
    puVar1 = local_318;
    local_1d8 = local_228;
    plVar3 = local_318 + 1;
    *(undefined8 *)(puVar35 + -8) = 0x18001eccf;
    FUN_1800070f0(plVar3,(undefined8 *)&local_2e0,&local_218);
    if (0xf < uStack_1e0) {
      pvVar26 = local_1f8;
      if ((0xfff < uStack_1e0 + 1) &&
         (pvVar26 = *(void **)((longlong)local_1f8 + -8),
         0x1f < (ulonglong)((longlong)local_1f8 + (-8 - (longlong)pvVar26)))) goto LAB_18001f1f4;
      *(undefined8 *)(puVar35 + -8) = 0x18001ed10;
      FUN_180035134(pvVar26);
    }
    if (0xf < local_200) {
      ppppCVar20 = local_218;
      if ((0xfff < local_200 + 1) &&
         (ppppCVar20 = (LPCSTR ***)local_218[-1],
         0x1f < (ulonglong)((longlong)local_218 + (-8 - (longlong)ppppCVar20)))) goto LAB_18001f1f4;
      *(undefined8 *)(puVar35 + -8) = 0x18001ed51;
      FUN_180035134(ppppCVar20);
    }
    if (0xf < uStack_230) {
      pppppuVar30 = local_248;
      if ((0xfff < uStack_230 + 1) &&
         (pppppuVar30 = (undefined8 *****)local_248[-1],
         0x1f < (ulonglong)((longlong)local_248 + (-8 - (longlong)pppppuVar30))))
      goto LAB_18001f1f4;
      *(undefined8 *)(puVar35 + -8) = 0x18001ed92;
      FUN_180035134(pppppuVar30);
    }
    uVar24 = local_270;
    pppplVar5 = local_278;
    ppppplVar25 = local_288;
    plVar3 = local_320;
    pIVar12 = local_328;
    if (cStack_337 == '\0') {
      if (bVar11 != 0) {
        *(longlong *******)(puVar35 + 0x28) = &local_330;
        local_330 = (longlong *****)0x0;
        *(undefined4 *)(puVar35 + 0x20) = 0;
        p_Var7 = pIVar12->lpVtbl->CreateStream;
        *(undefined8 *)(puVar35 + -8) = 0x18001eec4;
        (*p_Var7)(pIVar12,L"SEVData",0x1012,0,*(DWORD *)(puVar35 + 0x20),
                  *(IStream ***)(puVar35 + 0x28));
        ppppplVar25 = local_330;
        if (local_330 != (longlong *****)0x0) {
          local_318 = (undefined8 *)CONCAT44(local_318._4_4_,(undefined4)local_258);
          ppplVar8 = (*local_330)[4];
          *(undefined8 *)(puVar35 + -8) = 0x18001eeec;
          (*(code *)ppplVar8)(ppppplVar25,&local_318,4,&local_310);
          ppppplVar25 = local_330;
          uVar24 = (ulonglong)local_318 & 0xffffffff;
          pppppuVar30 = &local_268;
          if (0xf < uStack_250) {
            pppppuVar30 = local_268;
          }
          ppplVar8 = (*local_330)[4];
          *(undefined8 *)(puVar35 + -8) = 0x18001ef15;
          (*(code *)ppplVar8)(ppppplVar25,pppppuVar30,uVar24,&local_310);
          ppppplVar25 = local_330;
          ppplVar8 = (*local_330)[8];
          *(undefined8 *)(puVar35 + -8) = 0x18001ef21;
          (*(code *)ppplVar8)(ppppplVar25,0);
          if (local_330 != (longlong *****)0x0) {
            ppplVar8 = (*local_330)[2];
            *(undefined8 *)(puVar35 + -8) = 0x18001ef34;
            (*(code *)ppplVar8)();
          }
        }
        goto LAB_18001f07b;
      }
      pcVar4 = *(code **)(*local_320 + 0x18);
      *(undefined8 *)(puVar35 + -8) = 0x18001ef4a;
      iVar14 = (*pcVar4)(plVar3,&local_1c8);
      pIVar12 = local_328;
      if (-1 < iVar14) {
        *(undefined8 *)(puVar35 + -8) = 0x18001f023;
        HVar15 = WriteClassStg(pIVar12,&local_1c8);
        plVar3 = local_320;
        pIVar12 = local_328;
        if (-1 < HVar15) {
          pcVar4 = *(code **)(*local_320 + 0x28);
          *(undefined8 *)(puVar35 + -8) = 0x18001f03e;
          (*pcVar4)(plVar3,pIVar12);
          plVar3 = local_320;
          pIVar12 = local_328;
          pcVar4 = *(code **)(*local_320 + 0x38);
          *(undefined8 *)(puVar35 + -8) = 0x18001f04f;
          iVar14 = (*pcVar4)(plVar3,pIVar12,0);
          if (-1 < iVar14) {
            pcVar4 = *(code **)(*local_320 + 0x40);
            *(undefined8 *)(puVar35 + -8) = 0x18001f06a;
            iVar14 = (*pcVar4)();
            pIVar12 = local_328;
            p_Var9 = local_328->lpVtbl->Commit;
            *(undefined8 *)(puVar35 + -8) = 0x18001f079;
            (*p_Var9)(pIVar12,0);
            goto LAB_18001f07b;
          }
        }
      }
      pIVar12 = local_328;
      p_Var10 = local_328->lpVtbl->Release;
      *(undefined8 *)(puVar35 + -8) = 0x18001ef5c;
      (*p_Var10)(pIVar12);
      pcVar4 = *(code **)(*local_320 + 0x10);
      *(undefined8 *)(puVar35 + -8) = 0x18001ef66;
      (*pcVar4)();
      pcVar4 = *(code **)(*plVar16 + 0x10);
      *(undefined8 *)(puVar35 + -8) = 0x18001ef6f;
      (*pcVar4)(plVar16);
      if (0xf < local_290) {
        pppppCVar29 = local_2a8;
        if ((0xfff < local_290 + 1) &&
           (pppppCVar29 = (LPCSTR ****)local_2a8[-1],
           0x1f < (ulonglong)((longlong)local_2a8 + (-8 - (longlong)pppppCVar29))))
        goto LAB_18001f1f4;
        *(undefined8 *)(puVar35 + -8) = 0x18001efb0;
        FUN_180035134(pppppCVar29);
      }
      local_2a8 = (LPCSTR ****)((ulonglong)local_2a8 & 0xffffffffffffff00);
      local_290 = 0xf;
      local_298 = 0;
      if (0xf < uStack_250) {
        pppppuVar30 = local_268;
        if ((0xfff < uStack_250 + 1) &&
           (pppppuVar30 = (undefined8 *****)local_268[-1],
           0x1f < (ulonglong)((longlong)local_268 + (-8 - (longlong)pppppuVar30))))
        goto LAB_18001f1f4;
        *(undefined8 *)(puVar35 + -8) = 0x18001f00b;
        FUN_180035134(pppppuVar30);
      }
      goto LAB_18001e8a3;
    }
    ppppplVar23 = *(longlong ******)puVar1[3];
    ppppplVar34 = (longlong *****)ppppplVar23[1];
    local_330 = ppppplVar23;
    if (*(char *)((longlong)ppppplVar23[1] + 0x19) == '\0') {
      do {
        ppppplVar27 = ppppplVar34 + 4;
        ppppplVar28 = (longlong *****)&local_288;
        if (0xf < uVar24) {
          ppppplVar28 = ppppplVar25;
        }
        if ((longlong ****)0xf < ppppplVar34[7]) {
          ppppplVar27 = (longlong *****)ppppplVar34[4];
        }
        pppplVar2 = ppppplVar34[6];
        pppplVar40 = pppplVar2;
        if (pppplVar5 < pppplVar2) {
          pppplVar40 = pppplVar5;
        }
        *(undefined8 *)(puVar35 + -8) = 0x18001ee01;
        iVar14 = memcmp(ppppplVar27,ppppplVar28,(size_t)pppplVar40);
        if (iVar14 == 0) {
          if (pppplVar5 <= pppplVar2) goto LAB_18001ee07;
LAB_18001ee5c:
          ppppplVar27 = (longlong *****)ppppplVar34[2];
        }
        else {
          if (iVar14 < 0) goto LAB_18001ee5c;
LAB_18001ee07:
          ppppplVar27 = (longlong *****)*ppppplVar34;
          ppppplVar23 = ppppplVar34;
        }
        ppppplVar34 = ppppplVar27;
      } while (*(char *)((longlong)ppppplVar27 + 0x19) == '\0');
    }
    ppppplVar34 = local_330;
    if (*(char *)((longlong)ppppplVar23 + 0x19) == '\0') {
      ppppplVar27 = ppppplVar23 + 4;
      if ((longlong ****)0xf < ppppplVar23[7]) {
        ppppplVar27 = (longlong *****)ppppplVar23[4];
      }
      pppplVar2 = ppppplVar23[6];
      ppppplVar28 = (longlong *****)&local_288;
      if (0xf < uVar24) {
        ppppplVar28 = ppppplVar25;
      }
      pppplVar40 = pppplVar5;
      if (pppplVar2 < pppplVar5) {
        pppplVar40 = pppplVar2;
      }
      *(undefined8 *)(puVar35 + -8) = 0x18001ee4f;
      iVar14 = memcmp(ppppplVar28,ppppplVar27,(size_t)pppplVar40);
      if (iVar14 == 0) {
        if (pppplVar5 < pppplVar2) goto LAB_18001ee67;
      }
      else if (iVar14 < 0) goto LAB_18001ee67;
    }
    else {
LAB_18001ee67:
      ppppplVar23 = ppppplVar34;
    }
    pppplVar5 = ppppplVar23[9];
    *(IStorage **)(puVar35 + 0x20) = local_328;
    pplVar6 = (*pppplVar5)[7];
    *(undefined8 *)(puVar35 + -8) = 0x18001ee86;
    iVar14 = (*(code *)pplVar6)(pppplVar5,0,0,0);
LAB_18001f07b:
    pIVar12 = local_328;
    if (local_328 != (IStorage *)0x0) {
      p_Var10 = local_328->lpVtbl->Release;
      *(undefined8 *)(puVar35 + -8) = 0x18001f08a;
      (*p_Var10)(pIVar12);
    }
    if (local_320 != (longlong *)0x0) {
      pcVar4 = *(code **)(*local_320 + 0x10);
      *(undefined8 *)(puVar35 + -8) = 0x18001f099;
      (*pcVar4)();
    }
    pcVar4 = *(code **)(*plVar16 + 0x10);
    *(undefined8 *)(puVar35 + -8) = 0x18001f0a5;
    (*pcVar4)(plVar16);
    if (iVar14 < 0) {
      if (0xf < local_290) {
        pppppCVar29 = local_2a8;
        if ((0xfff < local_290 + 1) &&
           (pppppCVar29 = (LPCSTR ****)local_2a8[-1],
           0x1f < (ulonglong)((longlong)local_2a8 + (-8 - (longlong)pppppCVar29))))
        goto LAB_18001f1f4;
        *(undefined8 *)(puVar35 + -8) = 0x18001f0eb;
        FUN_180035134(pppppCVar29);
      }
      local_298 = 0;
      local_290 = 0xf;
      local_2a8 = (LPCSTR ****)((ulonglong)local_2a8 & 0xffffffffffffff00);
      goto LAB_18001e85b;
    }
    if (0xf < local_290) {
      pppppCVar29 = local_2a8;
      if ((0xfff < local_290 + 1) &&
         (pppppCVar29 = (LPCSTR ****)local_2a8[-1],
         0x1f < (ulonglong)((longlong)local_2a8 + (-8 - (longlong)pppppCVar29))))
      goto LAB_18001f1f4;
      *(undefined8 *)(puVar35 + -8) = 0x18001f143;
      FUN_180035134(pppppCVar29);
    }
    local_298 = 0;
    local_290 = 0xf;
    local_2a8 = (LPCSTR ****)((ulonglong)local_2a8 & 0xffffffffffffff00);
    if (0xf < uStack_250) {
      pppppuVar30 = local_268;
      if ((0xfff < uStack_250 + 1) &&
         (pppppuVar30 = (undefined8 *****)local_268[-1],
         0x1f < (ulonglong)((longlong)local_268 + (-8 - (longlong)pppppuVar30))))
      goto LAB_18001f1f4;
      *(undefined8 *)(puVar35 + -8) = 0x18001f199;
      FUN_180035134(pppppuVar30);
    }
    local_268 = (undefined8 *****)((ulonglong)local_268 & 0xffffffffffffff00);
    local_258 = _DAT_180041f70;
    uStack_250 = _UNK_180041f78;
    if (local_270 < 0x10) goto LAB_18001e8f4;
    ppppplVar25 = local_288;
    if (0xfff < local_270 + 1) {
      ppppplVar25 = (longlong *****)local_288[-1];
      lVar17 = (longlong)local_288 - (longlong)ppppplVar25;
      goto joined_r0x00018001f1ee;
    }
  }
  _UNK_180041f78 = uStack_250;
  _DAT_180041f70 = local_258;
  *(undefined8 *)(puVar35 + -8) = 0x18001e8f4;
  FUN_180035134(ppppplVar25);
LAB_18001e8f4:
  *(undefined8 *)(puVar35 + -8) = 0x18001e903;
  return;
}

