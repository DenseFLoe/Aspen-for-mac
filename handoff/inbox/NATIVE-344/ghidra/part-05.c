/* RVA 0x13790 */
undefined8 SimStop(void)

{
  longlong lVar1;
  
                    /* 0x13790  56  SimStop */
  lVar1 = GetGlobalPointer("AnalysisForm");
  if (lVar1 == 0) {
    GRsetust(1);
  }
  return 0;
}

/* RVA 0x137c0 */
void SimStopPoint(undefined8 param_1,IMAGE_DOS_HEADER *param_2,int *param_3,char *param_4)

{
                    /* 0x137c0  54  SimStopPoint */
  SimMain((char *)0x8,param_2,param_3,param_4);
  return;
}

/* RVA 0x137d0 */
int SimStopPointCount(void)

{
  longlong lVar1;
  int iVar2;
  
                    /* 0x137d0  78  SimStopPointCount */
  iVar2 = 0;
  if ((*(longlong *)(*(longlong *)topfinfo_exref + 0x560) != 0) &&
     (lVar1 = deref_ptr(), *(longlong *)(lVar1 + 8) != 0)) {
    lVar1 = deref_ptr();
    while ((lVar1 != 0 && (iVar2 = iVar2 + 1, *(longlong *)(lVar1 + 0x60) != 0))) {
      lVar1 = deref_ptr();
    }
  }
  return iVar2;
}

/* RVA 0x137e0 */
void SimStopPointInfo(int param_1,undefined4 *param_2,longlong param_3,undefined4 *param_4)

{
                    /* 0x137e0  79  SimStopPointInfo */
  FUN_180021db0(param_1,param_4,param_2,param_3);
  return;
}

/* RVA 0x13800 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180013800(void)

{
  int iVar1;
  DWORD DVar2;
  DWORD DVar3;
  undefined4 uVar4;
  AFX_MODULE_STATE *pAVar5;
  HANDLE hHandle;
  HGLOBAL pvVar6;
  undefined1 *puVar7;
  char *pcVar8;
  longlong lVar10;
  longlong lVar9;
  undefined8 uVar11;
  undefined8 in_R9;
  undefined *puVar12;
  undefined1 auStack_278 [32];
  char *local_258;
  AFX_MAINTAIN_STATE2 local_250 [24];
  char local_238 [272];
  char local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_278;
  pAVar5 = AfxGetModuleState();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_250,pAVar5);
  FUN_180008f80(local_238,"%s.msh",APtmpfil_exref,in_R9);
  FUN_180008f80(local_128,"%s.msh",APtmpfil_exref,in_R9);
  iVar1 = SBlocalhost();
  if (iVar1 == 0) {
    puVar7 = (undefined1 *)FUN_18001a130();
    iVar1 = FUN_18002b2c0(local_128,local_238,puVar7);
    if (iVar1 == 0) goto LAB_180013884;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_258);
    uVar11 = MVGetI18nProductName();
    pcVar8 = (char *)GetSorResStringEx(0xfa3);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_258,pcVar8,
               uVar11);
    MMAfxMessageBox(local_258,0,-1,0);
    FUN_180025fb0((char *)0x0,local_238);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_258);
  }
  else {
    FUN_180025b70((char *)0x0,local_128,local_238,(char *)0x0);
LAB_180013884:
    FUN_18000f830();
    DVar2 = GetGlobalPointer("APWN_TID");
    DVar3 = GetCurrentThreadId();
    hHandle = (HANDLE)GetGlobalPointer("DCOM_MSHL_EVENT");
    WaitForSingleObject(hHandle,0xffffffff);
    ResetEvent(hHandle);
    EnterCriticalSection(*(LPCRITICAL_SECTION *)HACriticalSection_exref);
    uVar4 = MDclrcrt(*(undefined8 *)HACriticalSection_exref);
    lVar9 = -1;
    do {
      lVar10 = lVar9;
      lVar9 = lVar10 + 1;
    } while (APtmpfil_exref[lVar9] != (code)0x0);
    pvVar6 = GlobalAlloc(0,lVar10 + 0x12);
    iVar1 = SBlocalhost();
    puVar12 = &DAT_18003f9b8;
    if (iVar1 != 0) {
      puVar12 = &DAT_180040c10;
    }
    FUN_180008f80(pvVar6,"UNMARSHAL %s.msh %s",APtmpfil_exref,puVar12);
    if (DVar2 == DVar3) {
      SimSendMainWndMessage(0x544,pvVar6,1);
    }
    else {
      FUN_1800074b0(0x544,pvVar6,1);
    }
    WaitForSingleObject(hHandle,0xffffffff);
    MDsetcrt(*(undefined8 *)HACriticalSection_exref,uVar4);
    LeaveCriticalSection(*(LPCRITICAL_SECTION *)HACriticalSection_exref);
    lVar9 = SimSendMainWndMessage(0x544,"GETRETCODE",0);
    if (lVar9 == 0) {
      FUN_18000c7b0();
    }
    iVar1 = SBlocalhost();
    if (iVar1 == 0) {
      _unlink(local_128);
    }
    FUN_180025fb0((char *)0x0,local_238);
    if (lVar9 == 0) {
      uVar11 = 0;
      goto LAB_180013a0e;
    }
  }
  uVar11 = 0x80004005;
LAB_180013a0e:
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_250);
  return uVar11;
}

/* RVA 0x13ad0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SimWriteCPanelMessage(char *param_1)

{
  undefined8 uVar1;
  HRESULT HVar2;
  undefined8 uVar3;
  HGLOBAL hGlobal;
  char *pcVar4;
  FILE *_File;
  LPVOID _Str;
  undefined1 auStack_488 [32];
  uint *local_468;
  undefined8 local_458;
  longlong *local_450;
  LPSTREAM local_448;
  HGLOBAL local_440;
  undefined8 local_438;
  uint local_430 [2];
  uint local_428 [4];
  undefined1 local_418 [1008];
  ulonglong local_28;
  
                    /* 0x13ad0  94  SimWriteCPanelMessage */
  local_28 = DAT_1800516d8 ^ (ulonglong)auStack_488;
  if (param_1 == (char *)0x0) {
    uVar3 = 0x80004005;
  }
  else {
    local_450 = (longlong *)0x0;
    local_448 = (LPSTREAM)0x0;
    local_438 = 0;
    local_458 = 0;
    if (DAT_180051ba0 == (longlong *)0x0) {
      FUN_180008f80(local_418,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\Simdll\\SimMain.cpp",0x5b2);
      LogMessage(local_418,2,1);
    }
    uVar3 = (**(code **)(*DAT_180051ba0 + 0x68))(DAT_180051ba0,&local_450);
    uVar1 = local_438;
    if (-1 < (int)uVar3) {
      (**(code **)(*local_450 + 0x28))(local_450,local_438,2);
      if (local_458._4_4_ != 0) {
        FUN_180008f80(local_418,"Assert failed in file %s line %d",
                      "G:\\Agent\\work\\2\\s\\src\\mm\\Simdll\\SimMain.cpp",0x5b9);
        LogMessage(local_418,2,1);
      }
      (**(code **)(*local_450 + 0x28))(local_450,uVar1,0);
      hGlobal = GlobalAlloc(2,(ulonglong)((uint)local_458 + 10));
      if (hGlobal == (HGLOBAL)0x0) {
        FUN_180008f80(local_418,"Assert failed in file %s line %d",
                      "G:\\Agent\\work\\2\\s\\src\\mm\\Simdll\\SimMain.cpp",0x5bd);
        LogMessage(local_418,2,1);
      }
      HVar2 = CreateStreamOnHGlobal(hGlobal,1,&local_448);
      if (HVar2 == 0) {
        local_468 = local_430;
        (**(code **)(*local_450 + 0x38))(local_450,local_448,local_458,local_428);
        if (local_428[0] != (uint)local_458) {
          FUN_180008f80(local_418,"Assert failed in file %s line %d",
                        "G:\\Agent\\work\\2\\s\\src\\mm\\Simdll\\SimMain.cpp",0x5c9);
          LogMessage(local_418,2,1);
        }
        if (local_430[0] != (uint)local_458) {
          FUN_180008f80(local_418,"Assert failed in file %s line %d",
                        "G:\\Agent\\work\\2\\s\\src\\mm\\Simdll\\SimMain.cpp",0x5ca);
          LogMessage(local_418,2,1);
        }
        local_440 = (HGLOBAL)0x0;
        HVar2 = GetHGlobalFromStream(local_448,&local_440);
        if (HVar2 == 0) {
          _File = fopen(param_1,"w");
          if (_File != (FILE *)0x0) {
            _Str = GlobalLock(local_440);
            fwrite(_Str,1,(ulonglong)local_430[0],_File);
            fclose(_File);
          }
          GlobalUnlock(local_440);
        }
        (*local_448->lpVtbl->Release)(local_448);
        GlobalFree(hGlobal);
        (**(code **)(*local_450 + 0x10))();
        uVar3 = 0;
      }
      else {
        pcVar4 = (char *)GetSorResStringEx(0x1ce);
        MMAfxMessageBox(pcVar4,0,-1,0);
        (**(code **)(*local_450 + 0x10))();
        uVar3 = 0x80004005;
      }
    }
  }
  return uVar3;
}

/* RVA 0x13de0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180013de0(char *param_1)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  undefined7 extraout_var;
  undefined1 *puVar4;
  undefined8 uVar5;
  code *pcVar6;
  char *pcVar7;
  char *pcVar8;
  undefined1 auStack_178 [32];
  char *local_158 [2];
  char local_148 [272];
  ulonglong local_38;
  
  local_38 = DAT_1800516d8 ^ (ulonglong)auStack_178;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_158);
  uVar5 = 0;
  pcVar6 = (code *)0x0;
  bVar1 = false;
  if (DAT_180052ec4 == 0) {
LAB_180013f1b:
    iVar2 = MVGetProductCode();
    pcVar8 = ".aprhis";
    pcVar7 = ".aprhis";
    if (iVar2 == 1) {
      pcVar7 = ".his";
    }
    uVar3 = GRinqfnm();
    FUN_180008f80(local_148,&DAT_18003f9b0,uVar3,pcVar7);
    _strlwr(local_148);
    iVar2 = FUN_180026510((char *)open_path_exref,local_148);
    if (iVar2 == -1) {
      iVar2 = MVGetProductCode();
      if (iVar2 == 1) {
        pcVar8 = ".his";
      }
      FUN_180008f80(local_148,&DAT_18003f9b0,APtmpfil_exref,pcVar8);
    }
    else {
      bVar1 = true;
      pcVar6 = open_path_exref;
    }
    if (!bVar1) goto LAB_180013fc0;
LAB_18001402b:
    iVar2 = SBlocalhost();
    if (iVar2 != 0) {
      CopyFileA(local_148,param_1,0);
      goto LAB_18001408c;
    }
    puVar4 = (undefined1 *)FUN_18001a130();
    iVar2 = FUN_18002b2c0(param_1,local_148,puVar4);
    if (iVar2 == 0) goto LAB_18001408c;
    pcVar7 = "Could not receive history file from host. Aborting command";
LAB_180014054:
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_158,pcVar7);
  }
  else {
    iVar2 = GRinqiap();
    if (iVar2 == 0) {
      if (DAT_180052ec4 == 0) goto LAB_180013f1b;
      iVar2 = GRinqiap();
      if (iVar2 == 0) {
        iVar2 = MVGetProductCode();
        pcVar7 = ".aprhis";
        pcVar8 = ".aprhis";
        if (iVar2 == 1) {
          pcVar8 = ".his";
        }
        FUN_180008f80(local_148,&DAT_18003f9b0,APtmpfil_exref,pcVar8);
        iVar2 = FUN_180026510((char *)0x0,local_148);
        if (iVar2 != -1) goto LAB_18001402b;
        iVar2 = MVGetProductCode();
        if (iVar2 == 1) {
          pcVar7 = ".his";
        }
        uVar3 = GRinqfnm();
        FUN_180008f80(local_148,&DAT_18003f9b0,uVar3,pcVar7);
        _strlwr(local_148);
        pcVar6 = open_path_exref;
      }
    }
    else {
      iVar2 = MVGetProductCode();
      pcVar7 = ".aprhis";
      if (iVar2 == 1) {
        pcVar7 = ".his";
      }
      FUN_180008f80(local_148,&DAT_18003f9b0,APtmpfil_exref,pcVar7);
      iVar2 = FUN_180017f80();
      if (iVar2 < 1) {
        uVar5 = 0x80004005;
        goto LAB_18001408c;
      }
    }
LAB_180013fc0:
    iVar2 = FUN_180026510((char *)pcVar6,local_148);
    if (iVar2 != -1) goto LAB_18001402b;
    bVar1 = FUN_1800297f0();
    if ((int)CONCAT71(extraout_var,bVar1) == 0) {
      iVar2 = MVGetProductCode();
      uVar5 = 0x1c8;
      if (iVar2 != 2) {
        uVar5 = 0x1c9;
      }
      pcVar7 = (char *)GetSorResStringEx(uVar5);
      goto LAB_180014054;
    }
    iVar2 = MVGetProductCode();
    uVar5 = 0x1ca;
    if (iVar2 != 2) {
      uVar5 = 0x1cb;
    }
    uVar5 = GetSorResStringEx(uVar5);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_158,"%s",uVar5
              );
  }
  MMAfxMessageBox(local_158[0],0x30,-1,0);
  uVar5 = 0x80004005;
LAB_18001408c:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_158);
  return uVar5;
}

/* RVA 0x140d0 */
uint SimWriteReport(uchar *param_1)

{
  int iVar1;
  char *pcVar2;
  
                    /* 0x140d0  67  SimWriteReport */
  if ((param_1 == (uchar *)0x0) || (*param_1 == '\0')) {
    pcVar2 = (char *)GetSorResStringEx(0x1cd);
    MMAfxMessageBox(pcVar2,0x30,-1,0);
    return 0x80004005;
  }
  iVar1 = FUN_180022a50(0x13,1,(char *)0x0,param_1);
  return -(uint)(iVar1 != 0) & 0x80004005;
}

/* RVA 0x14130 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SimWriteSummary(char *param_1)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  char *pcVar5;
  longlong lVar6;
  undefined8 uVar7;
  undefined1 auStackY_178 [32];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_148 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_140 [8];
  char local_138 [42];
  char local_10e [246];
  ulonglong local_18;
  
                    /* 0x14130  66  SimWriteSummary */
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_178;
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    pcVar4 = (char *)GetSorResStringEx(0x1d0);
    MMAfxMessageBox(pcVar4,0x30,-1,0);
    return 0x80004005;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_140,param_1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Right
            (local_140,(int)local_148);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::MakeLower(local_148);
  iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                    (local_148,"bkp");
  if ((iVar2 == 0) ||
     (iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        (local_148,"apt"), iVar2 == 0)) {
    iVar2 = 1;
LAB_1800141ed:
    uVar7 = 0;
    local_138[0x20] = '\0';
    local_138[0x21] = '\0';
    memset(local_138 + 0x22,0,0xfe);
    local_138[0] = '\0';
    local_138[1] = '\0';
    local_138[0x12] = '\0';
    local_138[0x13] = '\0';
    local_138[0x14] = '\0';
    local_138[0x15] = '\0';
    local_138[0x16] = '\0';
    local_138[0x17] = '\0';
    local_138[0x18] = '\0';
    local_138[0x19] = '\0';
    local_138[0x1a] = '\0';
    local_138[0x1b] = '\0';
    local_138[0x1c] = '\0';
    local_138[0x1d] = '\0';
    local_138[0x1e] = '\0';
    local_138[0x1f] = '\0';
    local_138[2] = '\0';
    local_138[3] = '\0';
    local_138[4] = '\0';
    local_138[5] = '\0';
    local_138[6] = '\0';
    local_138[7] = '\0';
    local_138[8] = '\0';
    local_138[9] = '\0';
    local_138[10] = '\0';
    local_138[0xb] = '\0';
    local_138[0xc] = '\0';
    local_138[0xd] = '\0';
    local_138[0xe] = '\0';
    local_138[0xf] = '\0';
    local_138[0x10] = '\0';
    local_138[0x11] = '\0';
    _splitpath(param_1,(char *)0x0,(char *)0x0,local_138 + 0x20,local_138);
    pcVar4 = local_138 + 0x1f;
    do {
      pcVar5 = pcVar4 + 1;
      pcVar4 = pcVar4 + 1;
    } while (*pcVar5 != '\0');
    lVar6 = 0;
    do {
      cVar1 = local_138[lVar6];
      pcVar4[lVar6] = cVar1;
      lVar6 = lVar6 + 1;
    } while (cVar1 != '\0');
    if (iVar2 == 1) {
      if ((*(int *)(*(longlong *)topfinfo_exref + 0x14c) == 0) ||
         (*(int *)(*(longlong *)topfinfo_exref + 0x150) == 0)) {
        SimReflect(2,0x1003,0);
        SimSendMainWndMessage(0x540,0x1003,0);
        goto LAB_180014376;
      }
LAB_1800142e2:
      SimReflect(2,0x1003,0);
      uVar3 = FUN_180020230(iVar2,param_1);
      SimSendMainWndMessage(0x540,0x1003,0);
      if ((int)uVar3 == 1) {
        pcVar4 = local_138 + 0x1f;
        do {
          pcVar5 = pcVar4;
          pcVar4 = pcVar5 + 1;
        } while (pcVar5[1] != '\0');
        *(undefined8 *)(pcVar5 + 1) = s_Generated_180040ab8._0_8_;
        *(undefined2 *)(pcVar5 + 9) = s_Generated_180040ab8._8_2_;
        pcVar5[0xb] = s_Generated_180040ab8[10];
        pcVar4 = _strdup(local_138 + 0x20);
        SimSendMainWndMessage(0x536,0,pcVar4);
        goto LAB_18001437b;
      }
      if (iVar2 != 2) goto LAB_18001437b;
    }
    else if ((iVar2 != 2) || (*(int *)(*(longlong *)topfinfo_exref + 0x14c) != 0))
    goto LAB_1800142e2;
    FUN_18000bdb0(local_138 + 0x20);
  }
  else {
    iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                      (local_148,"sum");
    if (iVar2 == 0) {
      iVar2 = 2;
      goto LAB_1800141ed;
    }
  }
LAB_180014376:
  uVar7 = 0x80004005;
LAB_18001437b:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_148);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_140);
  return uVar7;
}

/* RVA 0x143f0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1800143f0(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4)

{
  int iVar1;
  char *pcVar2;
  undefined1 auStack_b8 [32];
  char local_98 [128];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_b8;
  pcVar2 = local_98;
  iVar1 = MDwrtacc("mmsys.err");
  if (iVar1 == 0) {
    FUN_180028310("mmsys.err",pcVar2,param_3,param_4);
  }
  else {
    MMAfxMessageBox(local_98,0,-1,0);
  }
  return 0;
}

/* RVA 0x14460 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180014460(char *param_1,char param_2)

{
  char cVar1;
  int iVar2;
  BOOL BVar3;
  undefined8 uVar4;
  char *pcVar5;
  HANDLE hFindFile;
  longlong lVar6;
  char *pcVar7;
  undefined1 auStack_288 [32];
  char *local_268;
  LPCSTR local_260;
  _WIN32_FIND_DATAA local_258;
  undefined2 local_118;
  char acStack_116 [8];
  char local_10e [246];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_288;
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    if (param_2 != '\0') {
      pcVar5 = (char *)GetSorResStringEx(0x1d0);
      MMAfxMessageBox(pcVar5,0x30,-1,0);
    }
    return 0x80004005;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_268);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_268,"%s.xml",
             APtmpfil_exref);
  uVar4 = FUN_180020230(5,local_268);
  if ((int)uVar4 == 1) {
    iVar2 = FUN_180026510((char *)0x0,local_268);
    if (iVar2 != -1) {
      iVar2 = SBlocalhost();
      if (iVar2 == 0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_260,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   &local_268);
        iVar2 = FUN_180010b70(param_1,local_260);
        if (iVar2 != 0) {
          if (param_2 != '\0') {
            pcVar5 = (char *)GetSorResStringEx(0x1d3);
            MMAfxMessageBox(pcVar5,0x30,-1,0);
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_260);
          goto LAB_1800146f7;
        }
        FUN_180025fb0((char *)0x0,local_268);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_260);
      }
      else {
        BVar3 = MoveFileExA(local_268,param_1,0xb);
        if (BVar3 == 0) {
          Sleep(1000);
          hFindFile = FindFirstFileA(param_1,&local_258);
          if (hFindFile != (HANDLE)0xffffffffffffffff) {
            FindClose(hFindFile);
            BVar3 = DeleteFileA(param_1);
            if ((BVar3 == 0) && (param_2 != '\0')) {
              FUN_18000c660();
            }
            Sleep(1000);
          }
          BVar3 = MoveFileExA(local_268,param_1,0xb);
          if ((BVar3 == 0) && (param_2 != '\0')) {
            FUN_18000c660();
            goto LAB_1800146f7;
          }
        }
      }
      pcVar5 = strtok(param_1,"\\");
      local_118 = 0;
      memset(acStack_116,0,0xfe);
      while (pcVar5 != (char *)0x0) {
        lVar6 = (longlong)&local_118 - (longlong)pcVar5;
        do {
          cVar1 = *pcVar5;
          pcVar5[lVar6] = cVar1;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        pcVar5 = strtok((char *)0x0,"\\");
      }
      pcVar5 = &local_258.field_0x13f;
      do {
        pcVar7 = pcVar5;
        pcVar5 = pcVar7 + 1;
      } while (pcVar7[1] != '\0');
      *(undefined8 *)(pcVar7 + 1) = s_Generated_180040ab8._0_8_;
      *(undefined2 *)(pcVar7 + 9) = s_Generated_180040ab8._8_2_;
      pcVar7[0xb] = s_Generated_180040ab8[10];
      pcVar5 = _strdup((char *)&local_118);
      SimSendMainWndMessage(0x536,0,pcVar5);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_268);
      return 0;
    }
    if (param_2 == '\0') goto LAB_1800146f7;
    uVar4 = 0x1d4;
  }
  else {
    if (param_2 == '\0') goto LAB_1800146f7;
    uVar4 = 0x1d5;
  }
  pcVar5 = (char *)GetSorResStringEx(uVar4);
  MMAfxMessageBox(pcVar5,0x30,-1,0);
LAB_1800146f7:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_268);
  return 0x80004005;
}

/* RVA 0x14760 */
undefined4 FUN_180014760(char *param_1,int param_2,int param_3)

{
  undefined *puVar1;
  undefined **ppuVar2;
  
  if (param_3 != 0) {
    if (param_2 == 0) {
      GRsetsms(1);
      param_2 = FUN_180006e20(param_1);
      if (param_2 == 0) {
        return 0;
      }
    }
    ppuVar2 = &PTR_s_Block_1800504c0;
    puVar1 = PTR_s_Block_1800504c0;
    while (puVar1 != (undefined *)0x0) {
      if (*(int *)(ppuVar2 + 4) == param_2) {
        return *(undefined4 *)((longlong)ppuVar2 + 0x24);
      }
      ppuVar2 = ppuVar2 + 5;
      puVar1 = *ppuVar2;
    }
  }
  return 0;
}

/* RVA 0x147c0 */
int FUN_1800147c0(char *param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined **ppuVar3;
  
  if (param_2 == 0) {
    iVar2 = FUN_180006e20(param_1);
    ppuVar3 = &PTR_s_Block_1800504c0;
    if (PTR_s_Block_1800504c0 != (undefined *)0x0) {
      do {
        if (*(int *)(ppuVar3 + 4) == iVar2) {
          return *(int *)(ppuVar3 + 4);
        }
        ppuVar3 = ppuVar3 + 5;
      } while (*ppuVar3 != (undefined *)0x0);
      return 0;
    }
  }
  else {
    ppuVar3 = &PTR_s_Block_1800504c0;
    puVar1 = PTR_s_Block_1800504c0;
    while (puVar1 != (undefined *)0x0) {
      if (*(int *)((longlong)ppuVar3 + 0x24) == param_2) {
        return *(int *)(ppuVar3 + 4);
      }
      ppuVar3 = ppuVar3 + 5;
      puVar1 = *ppuVar3;
    }
  }
  return 0;
}

/* RVA 0x14840 */
uchar * __cdecl name_lwr(uchar *_String)

{
  uchar *puVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180014840. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x14840  261  name_lwr */
  puVar1 = _mbslwr(_String);
  return puVar1;
}

/* RVA 0x14850 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_180014850(longlong param_1,int param_2)

{
  char cVar1;
  BSTR lpWideCharStr;
  int iVar2;
  int iVar3;
  LPCSTR lpMultiByteStr;
  longlong lVar5;
  longlong lVar4;
  ulonglong uVar6;
  char *pcVar7;
  undefined1 *puVar8;
  char *pcVar9;
  size_t _Size;
  undefined *puStackY_70;
  undefined1 auStackY_68 [32];
  int local_38 [2];
  undefined8 local_30;
  BSTR local_28;
  ulonglong local_20;
  
  local_20 = DAT_1800516d8 ^ (ulonglong)&local_28;
  _Size = (size_t)param_2;
  if (param_1 != 0) {
    puStackY_70 = (undefined *)0x180014895;
    lpMultiByteStr = operator_new__(_Size + 1);
    puStackY_70 = (undefined *)0x1800148a8;
    memset(lpMultiByteStr,0x30,_Size);
    pcVar9 = (char *)0x0;
    lpMultiByteStr[_Size] = '\0';
    if (lpMultiByteStr == (LPCSTR)0x0) {
      local_28 = (BSTR)0x0;
    }
    else {
      puStackY_70 = (undefined *)0x1800148ce;
      iVar2 = MultiByteToWideChar(0,0,lpMultiByteStr,-1,(LPWSTR)0x0,0);
      puStackY_70 = (undefined *)0x1800148dc;
      local_28 = SysAllocStringLen((OLECHAR *)0x0,iVar2 - 1);
      if (local_28 != (BSTR)0x0) {
        puStackY_70 = (undefined *)0x1800148ff;
        iVar3 = MultiByteToWideChar(0,0,lpMultiByteStr,-1,local_28,iVar2);
        if (iVar3 != iVar2) {
          puStackY_70 = (undefined *)0x180014a24;
          SysFreeString(local_28);
          goto LAB_180014a24;
        }
      }
      if (local_28 == (BSTR)0x0) {
LAB_180014a24:
                    /* WARNING: Subroutine does not return */
        puStackY_70 = &UNK_180014a2e;
        FUN_180001380(-0x7ff8fff2);
      }
    }
    puStackY_70 = (undefined *)0x180014923;
    SysFreeString(local_28);
    puStackY_70 = (undefined *)0x18001492f;
    iVar2 = FUN_1800095c0(&local_28,param_2);
    puStackY_70 = (undefined *)0x18001493a;
    operator_delete__(lpMultiByteStr);
    lpWideCharStr = local_28;
    puVar8 = auStackY_68;
    if (-1 < iVar2) {
      if (iVar2 == 1) {
        puVar8 = auStackY_68;
        if (local_28 != (LPCWSTR)0x0) {
          lVar4 = -1;
          do {
            lVar5 = lVar4;
            lVar4 = lVar5 + 1;
          } while (local_28[lVar4] != L'\0');
          iVar3 = (int)lVar5 + 2;
          puVar8 = auStackY_68;
          if (iVar3 < 0x40000000) {
            lVar4 = (longlong)(int)lVar4 * 2;
            uVar6 = lVar4 + 0x11;
            if (uVar6 <= lVar4 + 2U) {
              uVar6 = 0xffffffffffffff0;
            }
            puStackY_70 = (undefined *)0x1800149a0;
            lVar4 = -(uVar6 & 0xfffffffffffffff0);
            puVar8 = auStackY_68 + lVar4;
            pcVar7 = (char *)((longlong)&local_28 + lVar4);
            if (pcVar7 != (char *)0x0) {
              *(undefined8 *)((longlong)local_38 + lVar4 + 8) = 0;
              *(undefined8 *)((longlong)local_38 + lVar4) = 0;
              *(int *)((longlong)local_38 + lVar4 + -8) = iVar3 * 2;
              *pcVar7 = '\0';
              *(char **)(auStackY_68 + lVar4 + 0x20) = pcVar7;
              *(undefined8 *)(auStackY_68 + lVar4 + -8) = 0x1800149d4;
              iVar3 = WideCharToMultiByte(0,0,lpWideCharStr,-1,
                                          *(LPSTR *)(auStackY_68 + lVar4 + 0x20),
                                          *(int *)((longlong)local_38 + lVar4 + -8),
                                          *(LPCSTR *)((longlong)local_38 + lVar4),
                                          *(LPBOOL *)((longlong)local_38 + lVar4 + 8));
              puVar8 = auStackY_68 + lVar4;
              if (iVar3 == 0) {
                pcVar7 = (char *)0x0;
              }
              pcVar9 = pcVar7;
            }
          }
        }
        lVar4 = param_1 - (longlong)pcVar9;
        do {
          cVar1 = *pcVar9;
          pcVar9[lVar4] = cVar1;
          pcVar9 = pcVar9 + 1;
        } while (cVar1 != '\0');
      }
      goto LAB_1800149f5;
    }
  }
  puVar8 = auStackY_68;
  iVar2 = 0;
LAB_1800149f5:
  *(undefined8 *)(puVar8 + -8) = 0x180014a01;
  return iVar2;
}

/* RVA 0x14a30 */
/* protected: static struct CRuntimeClass * __ptr64 __cdecl CSimSeqObj::_GetBaseClass(void) */

CRuntimeClass * __cdecl CSimSeqObj::_GetBaseClass(void)

{
  CRuntimeClass *pCVar1;
  
                    /* 0x14a30  55  ?_GetBaseClass@CSimSeqObj@@KAPEAUCRuntimeClass@@XZ */
                    /* WARNING: Could not recover jumptable at 0x00018003b4fa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = CObject::GetThisClass();
  return pCVar1;
}

/* RVA 0x14a40 */
/* public: static class CObject * __ptr64 __cdecl CSimSeqObj::CreateObject(void) */

CObject * __cdecl CSimSeqObj::CreateObject(void)

{
  CSimSeqObj *this;
  CObject *pCVar1;
  
                    /* 0x14a40  23  ?CreateObject@CSimSeqObj@@SAPEAVCObject@@XZ */
  this = operator_new(0x20);
  if (this == (CSimSeqObj *)0x0) {
    return (CObject *)0x0;
  }
  pCVar1 = (CObject *)CSimSeqObj(this);
  return pCVar1;
}

/* RVA 0x14a70 */
void FUN_180014a70(void *param_1,longlong param_2)

{
  FUN_180014a80(param_1,(longlong)((longlong)param_1 + param_2 * 8));
  return;
}

/* RVA 0x14a80 */
longlong FUN_180014a80(void *param_1,longlong param_2)

{
  memset(param_1,0,param_2 - (longlong)param_1);
  return param_2;
}

/* RVA 0x14aa0 */
longlong thunk_FUN_18000a8d0(void *param_1,longlong param_2,void *param_3)

{
  memmove(param_3,param_1,param_2 - (longlong)param_1);
  return (param_2 - (longlong)param_1) + (longlong)param_3;
}

/* RVA 0x14ab0 */
/* public: __cdecl CSimSeqObj::CSimSeqObj(class CSimSeqObj const & __ptr64) __ptr64 */

CSimSeqObj * __thiscall CSimSeqObj::CSimSeqObj(CSimSeqObj *this,CSimSeqObj *param_1)

{
  undefined8 *puVar1;
  
                    /* 0x14ab0  12  ??0CSimSeqObj@@QEAA@AEBV0@@Z */
  *(undefined ***)this = _vftable_;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(this + 8));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(this + 8),
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_1 + 8));
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  puVar1 = operator_new(0x20);
  if (puVar1 == (undefined8 *)0x0) {
    puVar1 = (undefined8 *)0x0;
  }
  else {
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    *puVar1 = CSimSeqTree::vftable;
  }
  *(undefined8 **)(this + 0x18) = puVar1;
  FUN_180014ec0((longlong)puVar1,*(longlong *)(param_1 + 0x18));
  return this;
}

/* RVA 0x14b50 */
/* public: __cdecl CSimSeqObj::CSimSeqObj(void) __ptr64 */

CSimSeqObj * __thiscall CSimSeqObj::CSimSeqObj(CSimSeqObj *this)

{
  undefined8 *puVar1;
  
                    /* 0x14b50  13  ??0CSimSeqObj@@QEAA@XZ */
  *(undefined ***)this = _vftable_;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(this + 8));
  *(undefined8 *)(this + 0x10) = 0;
  puVar1 = operator_new(0x20);
  if (puVar1 == (undefined8 *)0x0) {
    puVar1 = (undefined8 *)0x0;
  }
  else {
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    *puVar1 = CSimSeqTree::vftable;
  }
  *(undefined8 **)(this + 0x18) = puVar1;
  return this;
}

/* RVA 0x14bd0 */
void FUN_180014bd0(undefined8 *param_1)

{
  void *pvVar1;
  longlong lVar2;
  void *pvVar3;
  
  lVar2 = param_1[4];
  if (lVar2 != 0) {
    do {
      lVar2 = lVar2 + -1;
      param_1[4] = lVar2;
    } while (lVar2 != 0);
    param_1[3] = 0;
  }
  if (param_1[1] != 0) {
    lVar2 = param_1[2];
    while (lVar2 != 0) {
      lVar2 = lVar2 + -1;
      pvVar1 = *(void **)(param_1[1] + lVar2 * 8);
      if (pvVar1 != (void *)0x0) {
        FUN_180001300(pvVar1);
      }
    }
    pvVar1 = (void *)param_1[1];
    pvVar3 = pvVar1;
    if ((0xfff < (ulonglong)(param_1[2] << 3)) &&
       (pvVar3 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar3)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180001300(pvVar3);
  }
  pvVar1 = (void *)*param_1;
  *param_1 = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  FUN_180001300(pvVar1);
  return;
}

/* RVA 0x14cb0 */
/* public: virtual __cdecl CSimSeqObj::~CSimSeqObj(void) __ptr64 */

void __thiscall CSimSeqObj::~CSimSeqObj(CSimSeqObj *this)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  
                    /* 0x14cb0  15  ??1CSimSeqObj@@UEAA@XZ */
  lVar1 = *(longlong *)(this + 0x18);
  *(undefined ***)this = _vftable_;
  plVar3 = *(longlong **)(lVar1 + 8);
  plVar2 = *(longlong **)(lVar1 + 0x10);
  if (plVar3 != plVar2) {
    do {
      (**(code **)(*plVar3 + 8))(plVar3,0);
      plVar3 = plVar3 + 4;
    } while (plVar3 != plVar2);
    *(undefined8 *)(lVar1 + 0x10) = *(undefined8 *)(lVar1 + 8);
  }
  plVar3 = *(longlong **)(this + 0x18);
  if (plVar3 != (longlong *)0x0) {
    (**(code **)(*plVar3 + 8))(plVar3,1);
  }
                    /* WARNING: Could not recover jumptable at 0x000180014d2a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(this + 8));
  return;
}

/* RVA 0x14d40 */
/* public: class CSimSeqObj __cdecl CSimSeqObj::operator=(class CSimSeqObj const & __ptr64) __ptr64
    */

CSimSeqObj * __thiscall CSimSeqObj::operator=(CSimSeqObj *this,CSimSeqObj *param_1)

{
  CSimSeqObj *in_R8;
  
                    /* 0x14d40  16  ??4CSimSeqObj@@QEAA?AV0@AEBV0@@Z */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(this + 8),
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (in_R8 + 8));
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(in_R8 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(in_R8 + 0x14);
  FUN_180014ec0(*(longlong *)(this + 0x18),*(longlong *)(in_R8 + 0x18));
  CSimSeqObj(param_1,in_R8);
  return param_1;
}

/* RVA 0x14da0 */
CArchive * FUN_180014da0(CArchive *param_1,undefined4 *param_2)

{
  char *pcVar1;
  
  if (((byte)param_1[0x20] & 1) == 0) {
    pcVar1 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                       ((CSimpleStringT<char,1> *)(param_1 + 0x18));
                    /* WARNING: Subroutine does not return */
    AfxThrowArchiveException(4,pcVar1);
  }
  if (*(ulonglong *)(param_1 + 0x40) < *(longlong *)(param_1 + 0x38) + 4U) {
    CArchive::FillBuffer
              (param_1,((int)*(longlong *)(param_1 + 0x38) - (int)*(ulonglong *)(param_1 + 0x40)) +
                       4);
  }
  *param_2 = **(undefined4 **)(param_1 + 0x38);
  *(longlong *)(param_1 + 0x38) = *(longlong *)(param_1 + 0x38) + 4;
  return param_1;
}

/* RVA 0x14e10 */
CSimSeqObj * FUN_180014e10(CSimSeqObj *param_1,uint param_2)

{
  if ((param_2 & 2) != 0) {
    _eh_vector_destructor_iterator_
              (param_1,0x20,*(__uint64 *)(param_1 + -8),CSimSeqObj::~CSimSeqObj);
    if ((param_2 & 1) != 0) {
      operator_delete__(param_1 + -8);
    }
    return param_1 + -8;
  }
  CSimSeqObj::~CSimSeqObj(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    FUN_180001300(param_1);
  }
  return param_1;
}

/* RVA 0x14ec0 */
void FUN_180014ec0(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  
  plVar2 = *(longlong **)(param_1 + 8);
  plVar1 = *(longlong **)(param_1 + 0x10);
  if (plVar2 != plVar1) {
    do {
      (**(code **)(*plVar2 + 8))(plVar2,0);
      plVar2 = plVar2 + 4;
    } while (plVar2 != plVar1);
    *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(param_1 + 8);
  }
  FUN_180004820((longlong *)(param_1 + 8),*(CSimSeqObj **)(param_1 + 0x10),
                *(CSimSeqObj **)(param_2 + 8),
                *(longlong *)(param_2 + 0x10) - (longlong)*(CSimSeqObj **)(param_2 + 8) >> 5);
  return;
}

/* RVA 0x14f50 */
undefined8 * FUN_180014f50(void)

{
  undefined8 *puVar1;
  
  puVar1 = operator_new(0x20);
  if (puVar1 == (undefined8 *)0x0) {
    return (undefined8 *)0x0;
  }
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  *puVar1 = CSimSeqTree::vftable;
  return puVar1;
}

/* RVA 0x14f90 */
/* public: class CSimSeqTree & __ptr64 __cdecl CSimSeqObj::GetChildren(void) __ptr64 */

CSimSeqTree * __thiscall CSimSeqObj::GetChildren(CSimSeqObj *this)

{
                    /* 0x14f90  33  ?GetChildren@CSimSeqObj@@QEAAAEAVCSimSeqTree@@XZ
                       0x14f90  34  ?GetChildren@CSimSeqObj@@QEBAAEBVCSimSeqTree@@XZ */
  return *(CSimSeqTree **)(this + 0x18);
}

/* RVA 0x14fa0 */
/* public: virtual struct CRuntimeClass * __ptr64 __cdecl CSimSeqObj::GetRuntimeClass(void)const
   __ptr64 */

CRuntimeClass * __cdecl CSimSeqObj::GetRuntimeClass(void)

{
                    /* 0x14fa0  37  ?GetRuntimeClass@CSimSeqObj@@UEBAPEAUCRuntimeClass@@XZ
                       0x14fa0  39  ?GetThisClass@CSimSeqObj@@SAPEAUCRuntimeClass@@XZ */
  return (CRuntimeClass *)&classCSimSeqObj;
}

/* RVA 0x14fb0 */
undefined ** FUN_180014fb0(void)

{
  return &PTR_s_CSimSeqTree_1800509a8;
}

/* RVA 0x14fc0 */
/* public: int __cdecl CSimSeqObj::HasChildren(void)const __ptr64 */

int __thiscall CSimSeqObj::HasChildren(CSimSeqObj *this)

{
                    /* 0x14fc0  44  ?HasChildren@CSimSeqObj@@QEBAHXZ */
  return (int)(*(longlong *)(*(longlong *)(this + 0x18) + 0x10) -
               *(longlong *)(*(longlong *)(this + 0x18) + 8) >> 5 != 0);
}

/* RVA 0x14fe0 */
/* public: virtual void __cdecl CSimSeqObj::Serialize(class CArchive & __ptr64) __ptr64 */

void __thiscall CSimSeqObj::Serialize(CSimSeqObj *this,CArchive *param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  char *pcVar3;
  
                    /* 0x14fe0  47  ?Serialize@CSimSeqObj@@UEAAXAEAVCArchive@@@Z */
  if ((~*(uint *)(param_1 + 0x20) & 1) == 0) {
    FUN_1800036e0(param_1,(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          (this + 8));
    FUN_180014da0(param_1,(undefined4 *)(this + 0x10));
    FUN_180014da0(param_1,(undefined4 *)(this + 0x14));
  }
  else {
    CArchive::operator<<<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>_>_>
              (param_1,(CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>_>_> *)(this + 8));
    uVar1 = *(undefined4 *)(this + 0x10);
    if ((~*(uint *)(param_1 + 0x20) & 1) == 0) {
      pcVar3 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                         ((CSimpleStringT<char,1> *)(param_1 + 0x18));
                    /* WARNING: Subroutine does not return */
      AfxThrowArchiveException(2,pcVar3);
    }
    if (*(ulonglong *)(param_1 + 0x40) < *(longlong *)(param_1 + 0x38) + 4U) {
      CArchive::Flush(param_1);
    }
    **(undefined4 **)(param_1 + 0x38) = uVar1;
    lVar2 = *(longlong *)(param_1 + 0x38);
    *(longlong *)(param_1 + 0x38) = lVar2 + 4;
    uVar1 = *(undefined4 *)(this + 0x14);
    if ((~*(uint *)(param_1 + 0x20) & 1) == 0) {
      pcVar3 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                         ((CSimpleStringT<char,1> *)(param_1 + 0x18));
                    /* WARNING: Subroutine does not return */
      AfxThrowArchiveException(2,pcVar3);
    }
    if (*(ulonglong *)(param_1 + 0x40) < lVar2 + 8U) {
      CArchive::Flush(param_1);
    }
    **(undefined4 **)(param_1 + 0x38) = uVar1;
    *(longlong *)(param_1 + 0x38) = *(longlong *)(param_1 + 0x38) + 4;
  }
                    /* WARNING: Could not recover jumptable at 0x0001800150a3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(longlong **)(this + 0x18) + 0x10))(*(longlong **)(this + 0x18),param_1);
  return;
}

/* RVA 0x150e0 */
void FUN_1800150e0(longlong param_1,CArchive *param_2)

{
  uint uVar1;
  longlong lVar2;
  CSimSeqObj *this;
  char *pcVar3;
  ulonglong uVar4;
  CSimSeqObj *this_00;
  longlong *plVar5;
  ulonglong uVar6;
  longlong lVar7;
  CSimSeqObj local_88 [32];
  CSimSeqObj local_68 [32];
  longlong *local_48;
  longlong local_40 [5];
  
  if ((~*(uint *)(param_2 + 0x20) & 1) == 0) {
    if ((*(uint *)(param_2 + 0x20) & 1) == 0) {
      pcVar3 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                         ((CSimpleStringT<char,1> *)(param_2 + 0x18));
                    /* WARNING: Subroutine does not return */
      AfxThrowArchiveException(4,pcVar3);
    }
    if (*(ulonglong *)(param_2 + 0x40) < *(longlong *)(param_2 + 0x38) + 4U) {
      CArchive::FillBuffer
                (param_2,((int)*(longlong *)(param_2 + 0x38) - (int)*(ulonglong *)(param_2 + 0x40))
                         + 4);
    }
    uVar1 = **(uint **)(param_2 + 0x38);
    uVar6 = (ulonglong)uVar1;
    *(uint **)(param_2 + 0x38) = *(uint **)(param_2 + 0x38) + 1;
    if (uVar1 != 0) {
      uVar4 = (ulonglong)(int)uVar1;
      plVar5 = (longlong *)(param_1 + 8);
      if ((ulonglong)(*(longlong *)(param_1 + 0x18) - *plVar5 >> 5) < uVar4) {
        if (0x7ffffffffffffff < uVar4) {
                    /* WARNING: Subroutine does not return */
          FUN_180005f30();
        }
        FUN_180005df0(plVar5,uVar4);
      }
      if (0 < (int)uVar1) {
        lVar7 = 0;
        do {
          CSimSeqObj::CSimSeqObj(local_88);
          CSimSeqObj::Serialize(local_88,param_2);
          this_00 = (CSimSeqObj *)(*plVar5 + lVar7);
          this = *(CSimSeqObj **)(param_1 + 0x10);
          if (this == *(CSimSeqObj **)(param_1 + 0x18)) {
            FUN_180004620(plVar5,this_00,local_88);
          }
          else if (this_00 == this) {
            CSimSeqObj::CSimSeqObj(this,local_88);
            *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x20;
          }
          else {
            local_48 = plVar5;
            CSimSeqObj::CSimSeqObj((CSimSeqObj *)local_40,local_88);
            CSimSeqObj::CSimSeqObj(this,this + -0x20);
            *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x20;
            FUN_180004d30((longlong)this_00,(longlong)(this + -0x20),this);
            CSimSeqObj::operator=(this_00,local_68);
            CSimSeqObj::~CSimSeqObj(local_68);
            (**(code **)(local_40[0] + 8))(local_40,0);
          }
          CSimSeqObj::~CSimSeqObj(local_88);
          lVar7 = lVar7 + 0x20;
          uVar6 = uVar6 - 1;
        } while (uVar6 != 0);
      }
    }
  }
  else {
    lVar7 = *(longlong *)(param_1 + 0x10);
    lVar2 = *(longlong *)(param_1 + 8);
    if (*(ulonglong *)(param_2 + 0x40) < *(longlong *)(param_2 + 0x38) + 4U) {
      CArchive::Flush(param_2);
    }
    **(undefined4 **)(param_2 + 0x38) = (int)(lVar7 - lVar2 >> 5);
    *(longlong *)(param_2 + 0x38) = *(longlong *)(param_2 + 0x38) + 4;
    plVar5 = *(longlong **)(param_1 + 8);
    if (plVar5 != *(longlong **)(param_1 + 0x10)) {
      do {
        (**(code **)(*plVar5 + 0x10))(plVar5,param_2);
        plVar5 = plVar5 + 4;
      } while (plVar5 != *(longlong **)(param_1 + 0x10));
    }
  }
  return;
}

/* RVA 0x15300 */
bool FUN_180015300(uint param_1)

{
  if ((param_1 < 0x10) && ((0xa024U >> (param_1 & 0x1f) & 1) != 0)) {
    return true;
  }
  return param_1 == 0x10;
}

/* RVA 0x15320 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180015320(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  bool bVar3;
  int iVar4;
  undefined7 extraout_var;
  void *pvVar5;
  CSimSeqTree *pCVar6;
  CSimSeqObj *pCVar7;
  longlong lVar8;
  CSimSeqObj *this;
  ulonglong uVar9;
  CSimSeqObj *pCVar10;
  longlong lVar11;
  undefined1 auStack_498 [32];
  longlong *local_478;
  longlong lStack_470;
  ulonglong local_468;
  ulonglong local_460;
  longlong local_458;
  CSimSeqObj local_450 [40];
  undefined1 local_428 [1008];
  ulonglong local_38;
  
  local_38 = DAT_1800516d8 ^ (ulonglong)auStack_498;
  local_478 = (longlong *)0x0;
  lStack_470 = 0;
  local_468 = 0;
  local_460 = 0;
  local_458 = 0;
  local_478 = operator_new(0x10);
  local_478[1] = 0;
  *local_478 = (longlong)&local_478;
  lVar8 = *(longlong *)(param_1 + 8);
  if (lVar8 != *(longlong *)(param_1 + 0x10)) {
    lVar11 = local_458;
    do {
      uVar1 = *(uint *)(lVar8 + 0x10);
      bVar3 = FUN_180015300(uVar1);
      if ((int)CONCAT71(extraout_var,bVar3) == 0) {
        if ((int)uVar1 < 0) {
          if (lVar11 == 0) {
            FUN_180008f80(local_428,"Assert failed in file %s line %d",
                          "G:\\Agent\\work\\2\\s\\src\\mm\\Simdll\\SimSeqObj.cpp",0xc0);
            LogMessage(local_428,2,1);
            lVar11 = local_458;
            if (local_458 == 0) goto LAB_180015627;
          }
          uVar9 = (local_460 - 1) + lVar11;
          lVar11 = (longlong)
                   *(int *)(*(longlong *)(lStack_470 + (local_468 - 1 & uVar9 >> 2) * 8) +
                           (ulonglong)((uint)uVar9 & 3) * 4) * 0x20;
          pCVar10 = (CSimSeqObj *)(*(longlong *)(param_1 + 8) + lVar11);
          iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             (pCVar10 + 8),*(char **)(lVar8 + 8));
          if (iVar4 != 0) {
            FUN_180008f80(local_428,"Assert failed in file %s line %d",
                          "G:\\Agent\\work\\2\\s\\src\\mm\\Simdll\\SimSeqObj.cpp",199);
            LogMessage(local_428,2,1);
          }
          iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             (pCVar10 + 8),*(char **)(lVar8 + 8));
          if (iVar4 == 0) {
            if (*(int *)(pCVar10 + 0x10) != -*(int *)(lVar8 + 0x10)) {
              FUN_180008f80(local_428,"Assert failed in file %s line %d",
                            "G:\\Agent\\work\\2\\s\\src\\mm\\Simdll\\SimSeqObj.cpp",0xca);
              LogMessage(local_428,2,1);
            }
            this = pCVar10 + 0x20;
            pCVar6 = CSimSeqObj::GetChildren(pCVar10);
            FUN_180004820((longlong *)(pCVar6 + 8),*(CSimSeqObj **)(pCVar6 + 8),this,
                          lVar8 - (longlong)this >> 5);
            pCVar10 = (CSimSeqObj *)(lVar8 + 0x20);
            if (this != pCVar10) {
              pCVar7 = *(CSimSeqObj **)(param_1 + 0x10);
              for (; pCVar10 != pCVar7; pCVar10 = pCVar10 + 0x20) {
                CSimSeqObj::operator=(this,local_450);
                CSimSeqObj::~CSimSeqObj(local_450);
                this = this + 0x20;
              }
              pCVar10 = *(CSimSeqObj **)(param_1 + 0x10);
              for (pCVar7 = this; pCVar7 != pCVar10; pCVar7 = pCVar7 + 0x20) {
                (**(code **)(*(longlong *)pCVar7 + 8))(pCVar7,0);
              }
              *(CSimSeqObj **)(param_1 + 0x10) = this;
            }
            lVar8 = *(longlong *)(param_1 + 8) + lVar11;
          }
          lVar11 = local_458 + -1;
          local_458 = lVar11;
          if (lVar11 == 0) {
            local_460 = 0;
          }
        }
      }
      else {
        lVar2 = *(longlong *)(param_1 + 8);
        if ((((char)local_460 + (char)lVar11 & 3U) == 0) && (local_468 <= lVar11 + 4U >> 2)) {
          FUN_180015860((longlong)&local_478,1);
          lVar11 = local_458;
        }
        local_460 = local_460 & local_468 * 4 - 1;
        uVar9 = lVar11 + local_460;
        lVar11 = (local_468 - 1 & uVar9 >> 2) * 8;
        if (*(longlong *)(lStack_470 + lVar11) == 0) {
          pvVar5 = operator_new(0x10);
          *(void **)(lVar11 + lStack_470) = pvVar5;
        }
        *(int *)(*(longlong *)(lVar11 + lStack_470) + (ulonglong)((uint)uVar9 & 3) * 4) =
             (int)(lVar8 - lVar2 >> 5);
        lVar11 = local_458 + 1;
        local_458 = local_458 + 1;
      }
LAB_180015627:
      lVar8 = lVar8 + 0x20;
    } while (lVar8 != *(longlong *)(param_1 + 0x10));
  }
  FUN_180014bd0(&local_478);
  return 0;
}

/* RVA 0x15670 */
/* public: char * __ptr64 __cdecl CSimSeqObj::Xml(void) __ptr64 */

char * __thiscall CSimSeqObj::Xml(CSimSeqObj *this)

{
  longlong lVar1;
  bool bVar2;
  int iVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this_00;
  char *pcVar4;
  char *local_res10;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res18 [16];
  
                    /* 0x15670  49  ?Xml@CSimSeqObj@@QEAAPEADXZ */
  pcVar4 = (char *)0x0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10);
  this_00 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(this + 8),
                       (int)local_res18);
  iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                    (this_00,"STOP");
  if ((iVar3 == 0) && (*(uint *)(this + 0x10) == 99)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
  if (!bVar2) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10,
               "<Object id=\"%s\" type=\"%d\" acquired=\"%d\">\n",*(undefined8 *)(this + 8),
               (ulonglong)*(uint *)(this + 0x10),*(undefined4 *)(this + 0x14));
    lVar1 = *(longlong *)(this + 0x18);
    if (*(longlong *)(lVar1 + 0x10) - *(longlong *)(lVar1 + 8) >> 5 != 0) {
      pcVar4 = FUN_180015790(lVar1);
      if (pcVar4 != (char *)0x0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10,
                   pcVar4);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10,
                   "\n");
        free(pcVar4);
      }
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10,
               "</Object>");
    pcVar4 = _strdup(local_res10);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10);
  return pcVar4;
}

/* RVA 0x15790 */
char * FUN_180015790(longlong param_1)

{
  char *pcVar1;
  CSimSeqObj *this;
  char *local_res8;
  
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8,
             "<Sequence count=\"%d\">\n<Children>\n",
             *(longlong *)(param_1 + 0x10) - *(longlong *)(param_1 + 8) >> 5);
  this = *(CSimSeqObj **)(param_1 + 8);
  if (this != *(CSimSeqObj **)(param_1 + 0x10)) {
    do {
      pcVar1 = CSimSeqObj::Xml(this);
      if (pcVar1 != (char *)0x0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8,
                   pcVar1);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8,"\n"
                  );
        free(pcVar1);
      }
      this = this + 0x20;
    } while (this != *(CSimSeqObj **)(param_1 + 0x10));
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8,
             "</Children>\n</Sequence>");
  pcVar1 = _strdup(local_res8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
  return pcVar1;
}

/* RVA 0x15860 */
void FUN_180015860(longlong param_1,ulonglong param_2)

{
  __uint64 _Var1;
  longlong lVar2;
  code *pcVar3;
  ulonglong uVar4;
  void *pvVar5;
  void *pvVar6;
  void *pvVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  
  uVar9 = *(ulonglong *)(param_1 + 0x10);
  uVar4 = 1;
  if (uVar9 != 0) {
    uVar4 = uVar9;
  }
  for (; (uVar8 = uVar4 - uVar9, uVar8 < param_2 || (uVar4 < 8)); uVar4 = uVar4 * 2) {
    if (0xfffffffffffffff - uVar4 < uVar4) {
      FUN_1800159f0();
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
  }
  uVar9 = *(ulonglong *)(param_1 + 0x18) >> 2;
  if (0x1fffffffffffffff < uVar4) {
                    /* WARNING: Subroutine does not return */
    FUN_180005ed0();
  }
  _Var1 = uVar4 * 8;
  if (_Var1 < 0x1000) {
    if (_Var1 == 0) {
      pvVar5 = (void *)0x0;
    }
    else {
      pvVar5 = operator_new(_Var1);
    }
  }
  else {
    pvVar5 = (void *)FUN_1800044b0(_Var1);
  }
  lVar2 = uVar9 * 8;
  pvVar6 = (void *)thunk_FUN_18000a8d0((void *)(*(longlong *)(param_1 + 8) + lVar2),
                                       *(longlong *)(param_1 + 8) +
                                       *(longlong *)(param_1 + 0x10) * 8,
                                       (void *)(lVar2 + (longlong)pvVar5));
  pvVar7 = *(void **)(param_1 + 8);
  if (uVar8 < uVar9) {
    thunk_FUN_18000a8d0(pvVar7,(longlong)((longlong)pvVar7 + uVar8 * 8),pvVar6);
    pvVar7 = (void *)thunk_FUN_18000a8d0((void *)(*(longlong *)(param_1 + 8) + uVar8 * 8),
                                         *(longlong *)(param_1 + 8) + lVar2,pvVar5);
    uVar9 = uVar8;
  }
  else {
    pvVar7 = (void *)thunk_FUN_18000a8d0(pvVar7,(longlong)(lVar2 + (longlong)pvVar7),pvVar6);
    FUN_180014a70(pvVar7,uVar8 - uVar9);
    pvVar7 = pvVar5;
  }
  FUN_180014a70(pvVar7,uVar9);
  pvVar7 = *(void **)(param_1 + 8);
  if (pvVar7 != (void *)0x0) {
    pvVar6 = pvVar7;
    if ((0xfff < (ulonglong)(*(longlong *)(param_1 + 0x10) << 3)) &&
       (pvVar6 = *(void **)((longlong)pvVar7 + -8),
       0x1f < (ulonglong)((longlong)pvVar7 + (-8 - (longlong)pvVar6)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180001300(pvVar6);
  }
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + uVar8;
  *(void **)(param_1 + 8) = pvVar5;
  return;
}

/* RVA 0x159f0 */
void FUN_1800159f0(void)

{
                    /* WARNING: Subroutine does not return */
  std::_Xlength_error("deque<T> too long");
}

/* RVA 0x15a10 */
ulonglong FUN_180015a10(uint param_1,uchar *param_2)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  uint *puVar6;
  char *pcVar7;
  ulonglong uVar8;
  uint uVar9;
  
  if ((param_1 == 0x1f) && (param_2 != (uchar *)0x0)) {
    iVar4 = strncmp((char *)param_2,"PARSE ",6);
    if (iVar4 != 0) goto LAB_180015a47;
  }
  else {
LAB_180015a47:
    iVar4 = MMGetVisibleSuppress();
    if (iVar4 != 0) {
      SetFocus((HWND)0x0);
    }
  }
  GRsetinmt(0);
  DAT_180051c18 = 0;
  uVar5 = FUN_180015fb0();
  if (((int)uVar5 != 0) &&
     ((0x26 < param_1 || ((0x4040000290U >> ((longlong)(int)param_1 & 0x3fU) & 1) == 0)))) {
    if (((param_1 < 0x23) && ((0x7b0000022U >> ((longlong)(int)param_1 & 0x3fU) & 1) != 0)) ||
       (DAT_180052ec4 == 0)) {
LAB_180015ab3:
      puVar6 = operator_new(0x30);
      puVar6[0] = 0;
      puVar6[1] = 0;
      puVar6[2] = 0;
      puVar6[3] = 0;
      puVar6[4] = 0;
      puVar6[5] = 0;
      puVar6[6] = 0;
      puVar6[7] = 0;
      puVar6[8] = 0;
      puVar6[9] = 0;
      puVar6[10] = 0;
      puVar6[0xb] = 0;
      *puVar6 = param_1;
      if (param_2 == (uchar *)0x0) {
        pcVar7 = (char *)0x0;
      }
      else {
        pcVar7 = _strdup((char *)param_2);
      }
      *(char **)(puVar6 + 4) = pcVar7;
      puVar6[1] = 1;
      puVar6[2] = 0;
      puVar6[6] = 1;
      *(undefined8 *)(puVar6 + 9) = *(undefined8 *)Sactions_exref;
      uVar8 = FUN_180015c10(puVar6);
      return uVar8;
    }
    iVar4 = GRinqiap();
    if (iVar4 == 0) goto LAB_180015ab3;
  }
  cVar3 = MMCheckWaitStruct();
  if (cVar3 == '\0') {
    return 0x80004005;
  }
  if (param_2 != (uchar *)0x0) {
    iVar4 = strcmp("<DO_NOT_NOTIFY>",(char *)param_2);
    if (iVar4 == 0) {
      param_2 = (uchar *)0x0;
      goto LAB_180015b7b;
    }
  }
  SimReflect(2,param_1 + 0x1000,0);
LAB_180015b7b:
  iVar4 = FUN_180022a50(2,1,(char *)0x1,param_2);
  uVar9 = 0;
  if (iVar4 == -1) {
    uVar9 = 0x80004005;
  }
  uVar1 = *(uint *)(Sactions_exref + 4);
  uVar2 = *(uint *)Sactions_exref;
  SimSendMainWndMessage
            (0x540,(longlong)(int)(param_1 + 0x1000),
             (ulonglong)
             ((((((uVar1 >> 0xe & 1) * 2 | uVar1 >> 0xd & 1) * 2 | uVar1 >> 0xc & 1) * 2 |
               uVar2 >> 0x12 & 1) * 2 | uVar2 >> 0xe & 1) * 2 | uVar2 >> 10 & 1));
  return (ulonglong)uVar9;
}

/* RVA 0x15c10 */
undefined8 FUN_180015c10(uint *param_1)

{
  char cVar1;
  BOOL BVar2;
  DWORD DVar3;
  CWinThread *pCVar4;
  undefined8 uVar5;
  tagMSG local_38;
  
  cVar1 = MMCheckWaitStruct();
  if (cVar1 == '\0') {
    return 0x80004005;
  }
  if (((*param_1 - 0x1c & 0xfffffffa) != 0) || (uVar5 = 1, *param_1 == 0x21)) {
    uVar5 = 0;
  }
  if (param_1[1] != 0) {
    SimSendMainWndMessage(0x533,0,uVar5);
  }
  if (*(char **)(param_1 + 4) != (char *)0x0) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_180051f60,
               *(char **)(param_1 + 4));
  }
  if (param_1[2] == 0) {
    GRsetinmt(1);
    DAT_180051c18 = 1;
    AfxBeginThread(FUN_180015d70,param_1,0,0,0,(_SECURITY_ATTRIBUTES *)0x0);
    return 0;
  }
  SimReflect(2,*param_1,0);
  pCVar4 = AfxBeginThread(FUN_180015d70,param_1,0,0,0,(_SECURITY_ATTRIBUTES *)0x0);
  *(undefined4 *)(pCVar4 + 0x50) = 0;
  do {
    BVar2 = PeekMessageA(&local_38,(HWND)0x0,0,0,1);
    if (BVar2 != 0) {
      DispatchMessageA(&local_38);
    }
  } while ((char)param_1[7] == '\0');
  FUN_1800074b0(0x540,(ulonglong)*param_1,0);
  DVar3 = WaitForSingleObject(*(HANDLE *)(pCVar4 + 0x58),100);
  if (DVar3 != 0x102) {
    (**(code **)(*(longlong *)pCVar4 + 8))(pCVar4,1);
  }
  return 0;
}

/* RVA 0x15d70 */
undefined8 FUN_180015d70(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uchar *puVar4;
  undefined8 uVar5;
  
  EnterCriticalSection(DAT_180051f68);
  DCOM_INIT_THREAD();
  GRsetinmt(1);
  DAT_180051c18 = 1;
  if (param_1[8] == 0x7a0) {
    param_1[8] = 0;
  }
  puVar4 = *(uchar **)(param_1 + 4);
  if ((puVar4 != (uchar *)0x0) && ((*param_1 == 2 || (*param_1 == 0x20)))) {
    puVar4 = (uchar *)ATL::CSimpleStringT<char,1>::GetBuffer
                                ((CSimpleStringT<char,1> *)&DAT_180051f60,
                                 *(int *)(DAT_180051f60 + -0x10));
  }
  SimReflect(2,*param_1,0);
  if (*param_1 == 0xc) {
    DAT_180051ff0 = 1;
    _guard_check_icall();
    uVar2 = FUN_180022a50(0xc,1,(char *)0x1,puVar4);
    param_1[8] = uVar2;
    _guard_check_icall();
    DAT_180051ff0 = 0;
  }
  else if (*param_1 == 0x20) {
    uVar5 = FUN_18000c190((char *)puVar4);
    param_1[8] = (uint)uVar5;
  }
  else {
    uVar2 = FUN_180022a50(2,1,(char *)0x1,puVar4);
    param_1[8] = uVar2;
  }
  if ((*param_1 == 2) && (puVar4 != (uchar *)0x0)) {
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&DAT_180051f60,-1);
  }
  if (param_1[1] != 0) {
    iVar3 = GRinqust();
    FUN_180007640(0x534,(ulonglong)*param_1,(ulonglong)(-(uint)(iVar3 != 0) & 10));
  }
  DAT_18004f720 = 0;
  GRsetinmt(0);
  DAT_180051c18 = 0;
  uVar2 = param_1[10];
  uVar1 = param_1[9];
  FUN_1800074b0(0x540,(ulonglong)*param_1,
                (ulonglong)
                ((((((uVar2 >> 0xe & 1) * 2 | uVar2 >> 0xd & 1) * 2 | uVar2 >> 0xc & 1) * 2 |
                  uVar1 >> 0x12 & 1) * 2 | uVar1 >> 0xe & 1) * 2 | uVar1 >> 10 & 1));
  DAT_18004f720 = 1;
  if (param_1[6] == 0) {
    *(undefined1 *)(param_1 + 7) = 1;
  }
  else {
    if (*(void **)(param_1 + 4) != (void *)0x0) {
      free(*(void **)(param_1 + 4));
    }
    FUN_180001300(param_1);
  }
  DCOM_TERMINATE_THREAD();
  LeaveCriticalSection(DAT_180051f68);
  return 0;
}

/* RVA 0x15f60 */
LPCRITICAL_SECTION FUN_180015f60(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = operator_new(0x28);
  if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
    InitializeCriticalSection((LPCRITICAL_SECTION)0x0);
    return (LPCRITICAL_SECTION)0x0;
  }
  lpCriticalSection->DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
  lpCriticalSection->LockCount = 0;
  lpCriticalSection->RecursionCount = 0;
  lpCriticalSection->OwningThread = (HANDLE)0x0;
  lpCriticalSection->LockSemaphore = (HANDLE)0x0;
  lpCriticalSection->SpinCount = 0;
  InitializeCriticalSection(lpCriticalSection);
  return lpCriticalSection;
}

/* RVA 0x15fb0 */
undefined8 FUN_180015fb0(void)

{
  longlong *plVar1;
  int iVar2;
  AFX_MODULE_STATE *pAVar3;
  
  pAVar3 = AfxGetModuleState();
  plVar1 = *(longlong **)(pAVar3 + 8);
  if ((plVar1 != (longlong *)0x0) &&
     (iVar2 = (**(code **)(*plVar1 + 0x108))(plVar1,"debug","MultiThreading",1), iVar2 == 0)) {
    return 0;
  }
  if ((DAT_1800509d8 == 0) || (iVar2 = GRinqmt(), iVar2 == 0)) {
    return 0;
  }
  return 1;
}

/* RVA 0x16010 */
void FUN_180016010(undefined8 param_1,int param_2)

{
  if ((DAT_180051c18 == 0) && (param_2 == 0)) {
    return;
  }
  SimSendMainWndMessage(0x537,0,0);
  return;
}

/* RVA 0x16030 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SimStartRun(int param_1,char *param_2,int *param_3,char *param_4,char *param_5)

{
  BOOL BVar1;
  DWORD DVar2;
  int iVar3;
  CWinThread *pCVar4;
  char *pcVar5;
  undefined8 uVar6;
  int iVar7;
  undefined1 auStackY_e8 [32];
  longlong local_b8;
  undefined8 local_b0;
  tagMSG local_a8;
  undefined4 local_78;
  undefined4 local_74;
  undefined8 local_70;
  char *local_68;
  undefined4 local_60;
  char local_5c;
  undefined2 local_5b;
  undefined1 local_59;
  int local_58;
  undefined8 local_54;
  undefined4 local_4c;
  ulonglong local_48;
  
                    /* 0x16030  176  SimStartRun */
  local_48 = DAT_1800516d8 ^ (ulonglong)auStackY_e8;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,"");
  if (param_1 == 0) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,'A');
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,'\0');
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,"");
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,'\0');
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,"");
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,'\0');
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,"");
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,'\0');
    pcVar5 = "";
  }
  else {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,"XXX");
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,'\0');
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,param_2);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,'\0');
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,
               (char *)param_3);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,'\0');
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,param_4);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,'\0');
    pcVar5 = param_5;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,pcVar5);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,'\0');
  local_78 = 0xc;
  local_70 = 0;
  local_5b = 0;
  local_59 = 0;
  local_54 = 0;
  local_4c = 0;
  local_68 = ATL::CSimpleStringT<char,1>::GetBuffer
                       ((CSimpleStringT<char,1> *)&local_b8,*(int *)(local_b8 + -0x10));
  local_74 = 0;
  local_60 = 0;
  local_5c = '\0';
  local_58 = 0x7a0;
  pCVar4 = AfxBeginThread(FUN_180015d70,&local_78,0,0,0,(_SECURITY_ATTRIBUTES *)0x0);
  *(undefined4 *)(pCVar4 + 0x50) = 0;
  pcVar5 = (char *)GetSorResStringEx(0x159);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b0,pcVar5);
  iVar7 = 1;
  FUN_1800074b0(0x559,local_b0,1);
  do {
    BVar1 = PeekMessageA(&local_a8,(HWND)0x0,0,0,1);
    if (BVar1 != 0) {
      DispatchMessageA(&local_a8);
    }
  } while (local_5c == '\0');
  FUN_1800074b0(0x559,0,0);
  DVar2 = WaitForSingleObject(*(HANDLE *)(pCVar4 + 0x58),1000);
  if (DVar2 != 0x102) {
    (**(code **)(*(longlong *)pCVar4 + 8))();
  }
  if (local_58 == 0) {
    SimSetConnectInfo(0,param_2,(char *)param_3,param_4,param_5,0);
    DAT_180051c2c = 0;
    SimResume(0,param_2,param_3,param_4);
    COprocom(1);
  }
  else {
    iVar3 = GRinqsme();
    if (iVar3 == 0) {
      pcVar5 = (char *)GetSorResStringEx(0x15a);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b0,pcVar5);
      uVar6 = MVGetProductName();
      MMMessageBox(0,local_b0,uVar6,0x30);
      goto LAB_1800162fa;
    }
    SimSendMainWndMessage(0x539,0,0);
  }
  iVar7 = local_58;
LAB_1800162fa:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8);
  return iVar7;
}

/* RVA 0x16340 */
void FUN_180016340(undefined8 param_1,int param_2)

{
  if ((DAT_180051c18 == 0) && (param_2 == 0)) {
    return;
  }
  SimSendMainWndMessage(0x538,0,0);
  return;
}

/* RVA 0x16360 */
undefined4 SimThreadNoMT(int param_1)

{
  undefined4 uVar1;
  
                    /* 0x16360  99  SimThreadNoMT */
  uVar1 = DAT_1800509d8;
  DAT_1800509d8 = (uint)(param_1 == 0);
  return uVar1;
}

/* RVA 0x16380 */
/* public: void __cdecl CSimSeqObj::Copy(class CSimSeqObj const & __ptr64) __ptr64 */

void __thiscall CSimSeqObj::Copy(CSimSeqObj *this,CSimSeqObj *param_1)

{
                    /* 0x16380  20  ?Copy@CSimSeqObj@@QEAAXAEBV1@@Z */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(this + 8),
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_1 + 8));
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  return;
}

/* RVA 0x163b0 */
BOOL __stdcall
InitializeCriticalSectionEx(LPCRITICAL_SECTION lpCriticalSection,DWORD dwSpinCount,DWORD Flags)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800163b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = InitializeCriticalSectionEx(lpCriticalSection,dwSpinCount,Flags);
  return BVar1;
}

/* RVA 0x163c0 */
int FUN_1800163c0(char *param_1)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  
  iVar3 = 0;
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    return 0;
  }
  pcVar1 = _strdup(param_1);
  if (pcVar1 != (char *)0x0) {
    do {
      iVar3 = iVar3 + 1;
      pcVar2 = FUN_180019f50(pcVar1,0x20);
    } while (pcVar2 != (char *)0x0);
    MDfree(pcVar1);
  }
  return iVar3;
}

/* RVA 0x16430 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180016430(int param_1,char *param_2,FILE *param_3,char *param_4)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  FILE *_File;
  char *pcVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined1 *puVar7;
  FILE *_File_00;
  undefined *puVar8;
  char *pcVar9;
  int iVar10;
  char *pcVar11;
  undefined1 auStack_5c8 [32];
  char *local_5a8;
  FILE *local_5a0;
  char local_598 [8];
  undefined1 local_590;
  char local_588 [272];
  char local_478 [272];
  char local_368 [272];
  char local_258 [256];
  char local_158 [272];
  ulonglong local_48;
  
  local_48 = DAT_1800516d8 ^ (ulonglong)auStack_5c8;
  _File_00 = (FILE *)0x0;
  iVar10 = 0;
  pcVar11 = param_4;
  local_5a0 = param_3;
  pcVar2 = _strdup(param_2);
  if (pcVar2 != (char *)0x0) {
    do {
      iVar10 = iVar10 + 1;
      pcVar3 = FUN_180019f50(pcVar2,0x20);
    } while (pcVar3 != (char *)0x0);
    MDfree(pcVar2);
    if (0 < iVar10) {
      GetEditorTempFileName(local_368);
      _File = fopen(local_368,"at");
      if (_File == (FILE *)0x0) {
        puVar8 = &DAT_180041290;
        _File = fopen(local_368,"wt");
        if (_File == (FILE *)0x0) {
          FUN_180019f70("can not open for writing.\n",puVar8,param_3,pcVar11);
        }
      }
      GetEditorTempFileName(local_478);
      pcVar2 = _strdup(param_2);
      if (pcVar2 != (char *)0x0) {
        pcVar3 = pcVar2;
        do {
          pcVar4 = FUN_180019f50(pcVar3,0x20);
          FUN_180018800(pcVar3,&local_5a8);
          pcVar9 = local_598 + -(longlong)local_5a8;
          pcVar3 = local_5a8;
          do {
            cVar1 = *pcVar3;
            pcVar3[(longlong)pcVar9] = cVar1;
            pcVar3 = pcVar3 + 1;
          } while (cVar1 != '\0');
          iVar10 = 0;
          lVar5 = 0;
          do {
            if (local_598[lVar5] == '\0') {
              if (iVar10 < 8) {
                pcVar9 = (char *)CONCAT71((int7)((ulonglong)pcVar9 >> 8),0x20);
                param_3 = (FILE *)(longlong)(8 - iVar10);
                memset(local_598 + iVar10,(int)pcVar9,(size_t)param_3);
              }
              break;
            }
            iVar10 = iVar10 + 1;
            lVar5 = lVar5 + 1;
          } while (lVar5 < 8);
          local_590 = 0;
          if ((int)param_4 == 0) {
            GRsetmtf();
            FUN_180018e70(0,pcVar9,param_3,pcVar11);
          }
          uVar6 = FUN_180017610(param_1,local_598,(char *)local_5a0,pcVar11);
          if ((int)uVar6 < 0) {
            if (_File_00 != (FILE *)0x0) {
              fclose(_File_00);
            }
            DeleteTempFile(local_478);
            MDfree(pcVar2);
            show_mouse();
            return uVar6 & 0xffffffff;
          }
          param_3 = (FILE *)APtmpfil_exref;
          FUN_180008f80(local_588,"%s.ia1",APtmpfil_exref,pcVar11);
          if (param_1 == 0xd) {
            pcVar3 = "%s.rp2";
LAB_180016611:
            param_3 = (FILE *)APtmpfil_exref;
            FUN_180008f80(local_588,pcVar3,APtmpfil_exref,pcVar11);
          }
          else if (param_1 == 0xe) {
            pcVar3 = "%s.rp1";
            goto LAB_180016611;
          }
          iVar10 = FUN_180026510((char *)0x0,local_588);
          if (iVar10 != -1) {
            iVar10 = SBlocalhost();
            if (iVar10 == 0) {
              GetEditorTempFileName(local_158);
              puVar7 = (undefined1 *)FUN_18001a130();
              iVar10 = FUN_18002b2c0(local_158,local_588,puVar7);
              if (iVar10 != 0) {
                return 0;
              }
              param_3 = (FILE *)0x103;
              strncpy(local_478,local_158,0x103);
            }
            else {
              FUN_180006b60(local_588,local_478);
            }
            _File_00 = fopen(local_478,"rt");
            if (_File_00 != (FILE *)0x0) {
              param_3 = _File_00;
              pcVar3 = fgets(local_258,0xfa,_File_00);
              while (pcVar3 != (char *)0x0) {
                fputs(local_258,_File);
                param_3 = _File_00;
                pcVar3 = fgets(local_258,0xfa,_File_00);
              }
              fclose(_File_00);
              DeleteTempFile(local_478);
            }
          }
          pcVar3 = pcVar4;
        } while (pcVar4 != (char *)0x0);
        if (_File != (FILE *)0x0) {
          fclose(_File);
          FUN_180009bc0(local_368,0,0,(LPCSTR)0x0);
          show_mouse();
          MDfree(pcVar2);
          return 0;
        }
      }
      show_mouse();
      if (pcVar2 != (char *)0x0) {
        MDfree(pcVar2);
      }
      return 0;
    }
  }
  return 0xffffffff;
}

/* RVA 0x167c0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1800167c0(int param_1,char *param_2,undefined8 param_3,char *param_4)

{
  char cVar1;
  char *pcVar2;
  undefined8 uVar3;
  longlong lVar4;
  char *pcVar5;
  undefined1 auStack_d28 [32];
  int local_d08 [2];
  char *local_d00;
  char *local_cf8;
  char *local_cf0;
  char *local_ce8;
  char local_c70 [96];
  undefined8 local_c10;
  undefined1 local_c08 [3056];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_d28;
  local_cf0 = param_2;
  if (param_1 == 1) {
    memset(local_d08,0,0xf8);
    memset(local_c08,0,0xbf0);
    local_c10 = *(undefined8 *)(*(longlong *)finfo_exref + 0x1b8);
    pcVar2 = strchr(param_2,0x20);
    if (pcVar2 != (char *)0x0) {
      *pcVar2 = '\0';
    }
    FUN_180019eb0((longlong)local_d08,param_2);
    pcVar2 = param_2;
    do {
      cVar1 = *pcVar2;
      pcVar2[(longlong)(local_c70 + -(longlong)param_2)] = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    local_d00 = "RECDEF";
    local_cf8 = "BLOCK";
    thunk_FUN_18001b720(local_d08,0,0,param_4);
    return;
  }
  if (param_1 == 2) {
    memset(local_d08,0,0xf8);
    memset(local_c08,0,0xbf0);
    local_c10 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref);
    pcVar2 = strchr(param_2,0x20);
    if (pcVar2 != (char *)0x0) {
      *pcVar2 = '\0';
    }
    FUN_180019eb0((longlong)local_d08,param_2);
    pcVar2 = param_2;
    do {
      cVar1 = *pcVar2;
      pcVar2[(longlong)(local_c70 + -(longlong)param_2)] = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    local_cf8 = "CONVERGENCE";
    local_d00 = "RECDEF";
    thunk_FUN_18001b720(local_d08,0,0,param_4);
    return;
  }
  if (param_1 == 3) {
    memset(local_d08,0,0xf8);
    memset(local_c08,0,0xbf0);
    pcVar5 = "COSTING";
    uVar3 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"COSTING");
    local_c10 = MDfnddir(*(undefined8 *)iwpfile_exref,uVar3);
    pcVar2 = strchr(param_2,0x20);
    if (pcVar2 != (char *)0x0) {
      *pcVar2 = '\0';
    }
    FUN_180019eb0((longlong)local_d08,param_2);
    pcVar2 = param_2;
    do {
      cVar1 = *pcVar2;
      pcVar2[(longlong)(local_c70 + -(longlong)param_2)] = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    local_cf0 = "EQUIPMENT";
    local_ce8 = param_2;
  }
  else {
    if (param_1 == 4) {
      return;
    }
    if (param_1 == 5) {
      memset(local_d08,0,0xf8);
      memset(local_c08,0,0xbf0);
      pcVar5 = "SENSITIVITY";
      local_c10 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref);
      pcVar2 = strchr(param_2,0x20);
      if (pcVar2 != (char *)0x0) {
        *pcVar2 = '\0';
      }
      FUN_180019eb0((longlong)local_d08,param_2);
      pcVar2 = param_2;
      do {
        cVar1 = *pcVar2;
        pcVar2[(longlong)(local_c70 + -(longlong)param_2)] = cVar1;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
    }
    else if (param_1 == 6) {
      memset(local_d08,0,0xf8);
      memset(local_c08,0,0xbf0);
      pcVar5 = "TRANSFER";
      local_c10 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref);
      pcVar2 = strchr(param_2,0x20);
      if (pcVar2 != (char *)0x0) {
        *pcVar2 = '\0';
      }
      FUN_180019eb0((longlong)local_d08,param_2);
      pcVar2 = param_2;
      do {
        cVar1 = *pcVar2;
        pcVar2[(longlong)(local_c70 + -(longlong)param_2)] = cVar1;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
    }
    else if (param_1 == 7) {
      memset(local_d08,0,0xf8);
      memset(local_c08,0,0xbf0);
      pcVar5 = "CALCULATOR";
      local_c10 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref);
      pcVar2 = strchr(param_2,0x20);
      if (pcVar2 != (char *)0x0) {
        *pcVar2 = '\0';
      }
      FUN_180019eb0((longlong)local_d08,param_2);
      pcVar2 = param_2;
      do {
        cVar1 = *pcVar2;
        pcVar2[(longlong)(local_c70 + -(longlong)param_2)] = cVar1;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
    }
    else if (param_1 == 8) {
      pcVar2 = strchr(param_2,0x20);
      if (pcVar2 != (char *)0x0) {
        *pcVar2 = '\0';
      }
      memset(local_d08,0,0xcf0);
      uVar3 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"UTILITY");
      param_4 = param_2;
      lVar4 = MDfndkey(*(undefined8 *)iwpfile_exref,uVar3,1);
      if (lVar4 != -1) {
        local_c10 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref);
        FUN_180019eb0((longlong)local_d08,param_2);
        pcVar2 = param_2;
        do {
          cVar1 = *pcVar2;
          pcVar2[(longlong)(local_c70 + -(longlong)param_2)] = cVar1;
          pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        local_cf8 = "UTILITY";
        goto LAB_180017248;
      }
      ERclear(0);
      pcVar5 = "COSTING";
      uVar3 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"COSTING");
      local_c10 = MDfnddir(*(undefined8 *)iwpfile_exref,uVar3);
      FUN_180019eb0((longlong)local_d08,param_2);
      pcVar2 = param_2;
      do {
        cVar1 = *pcVar2;
        pcVar2[(longlong)(local_c70 + -(longlong)param_2)] = cVar1;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      local_cf0 = "UTILITY";
      local_ce8 = param_2;
    }
    else {
      if (param_1 == 9) {
        return;
      }
      if (param_1 == 10) {
        memset(local_d08,0,0xf8);
        memset(local_c08,0,0xbf0);
        pcVar5 = "BALANCE";
        local_c10 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref);
        pcVar2 = strchr(param_2,0x20);
        if (pcVar2 != (char *)0x0) {
          *pcVar2 = '\0';
        }
        FUN_180019eb0((longlong)local_d08,param_2);
        pcVar2 = param_2;
        do {
          cVar1 = *pcVar2;
          pcVar2[(longlong)(local_c70 + -(longlong)param_2)] = cVar1;
          pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
      }
      else if (param_1 == 0xb) {
        memset(local_d08,0,0xf8);
        memset(local_c08,0,0xbf0);
        pcVar5 = "PRES-RELIEF";
        local_c10 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref);
        pcVar2 = strchr(param_2,0x20);
        if (pcVar2 != (char *)0x0) {
          *pcVar2 = '\0';
        }
        FUN_180019eb0((longlong)local_d08,param_2);
        pcVar2 = param_2;
        do {
          cVar1 = *pcVar2;
          pcVar2[(longlong)(local_c70 + -(longlong)param_2)] = cVar1;
          pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
      }
      else if (param_1 == 0xc) {
        memset(local_d08,0,0xf8);
        memset(local_c08,0,0xbf0);
        pcVar5 = "DATA-FIT";
        uVar3 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"DATA-FIT");
        local_c10 = MDfnddir(*(undefined8 *)iwpfile_exref,uVar3);
        pcVar2 = strchr(param_2,0x20);
        if (pcVar2 != (char *)0x0) {
          *pcVar2 = '\0';
        }
        FUN_180019eb0((longlong)local_d08,param_2);
        pcVar2 = param_2;
        do {
          cVar1 = *pcVar2;
          pcVar2[(longlong)(local_c70 + -(longlong)param_2)] = cVar1;
          pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        local_cf0 = "REGRESSION";
        local_ce8 = param_2;
      }
      else if (param_1 == 0x10) {
        memset(local_d08,0,0xf8);
        memset(local_c08,0,0xbf0);
        pcVar5 = "PROP-TABLE";
        local_c10 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref);
        pcVar2 = strchr(param_2,0x20);
        if (pcVar2 != (char *)0x0) {
          *pcVar2 = '\0';
        }
        FUN_180019eb0((longlong)local_d08,param_2);
        pcVar2 = param_2;
        do {
          cVar1 = *pcVar2;
          pcVar2[(longlong)(local_c70 + -(longlong)param_2)] = cVar1;
          pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
      }
      else if (param_1 == 0x11) {
        memset(local_d08,0,0xf8);
        memset(local_c08,0,0xbf0);
        pcVar5 = "DESIGN-SPEC";
        local_c10 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref);
        pcVar2 = strchr(param_2,0x20);
        if (pcVar2 != (char *)0x0) {
          *pcVar2 = '\0';
        }
        FUN_180019eb0((longlong)local_d08,param_2);
        pcVar2 = param_2;
        do {
          cVar1 = *pcVar2;
          pcVar2[(longlong)(local_c70 + -(longlong)param_2)] = cVar1;
          pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
      }
      else {
        if (param_1 == 0x12) {
          FUN_18001a420(0);
          return;
        }
        if (param_1 == 0x13) {
          memset(local_d08,0,0xf8);
          memset(local_c08,0,0xbf0);
          pcVar5 = "CONSTRAINT";
          local_c10 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref);
          pcVar2 = strchr(param_2,0x20);
          if (pcVar2 != (char *)0x0) {
            *pcVar2 = '\0';
          }
          FUN_180019eb0((longlong)local_d08,param_2);
          pcVar2 = param_2;
          do {
            cVar1 = *pcVar2;
            pcVar2[(longlong)(local_c70 + -(longlong)param_2)] = cVar1;
            pcVar2 = pcVar2 + 1;
          } while (cVar1 != '\0');
        }
        else if (param_1 == 0x14) {
          memset(local_d08,0,0xf8);
          memset(local_c08,0,0xbf0);
          pcVar5 = "OPTIMIZATION";
          local_c10 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref);
          pcVar2 = strchr(param_2,0x20);
          if (pcVar2 != (char *)0x0) {
            *pcVar2 = '\0';
          }
          FUN_180019eb0((longlong)local_d08,param_2);
          pcVar2 = param_2;
          do {
            cVar1 = *pcVar2;
            pcVar2[(longlong)(local_c70 + -(longlong)param_2)] = cVar1;
            pcVar2 = pcVar2 + 1;
          } while (cVar1 != '\0');
        }
        else {
          if (param_1 != 0x15) {
            return;
          }
          memset(local_d08,0,0xf8);
          memset(local_c08,0,0xbf0);
          pcVar5 = "MEASUREMENT";
          local_c10 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref);
          pcVar2 = strchr(param_2,0x20);
          if (pcVar2 != (char *)0x0) {
            *pcVar2 = '\0';
          }
          FUN_180019eb0((longlong)local_d08,param_2);
          pcVar2 = param_2;
          do {
            cVar1 = *pcVar2;
            pcVar2[(longlong)(local_c70 + -(longlong)param_2)] = cVar1;
            pcVar2 = pcVar2 + 1;
          } while (cVar1 != '\0');
        }
      }
    }
  }
  local_cf8 = pcVar5;
LAB_180017248:
  local_d00 = "RECDEF";
  thunk_FUN_18001b720(local_d08,0,0,param_4);
  return;
}

/* RVA 0x172a0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_1800172a0(int param_1,char *param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  int iVar8;
  longlong lVar9;
  longlong lVar10;
  char *pcVar11;
  int iVar12;
  undefined1 auStackY_1b8 [32];
  undefined8 local_188;
  undefined8 local_180;
  char local_178 [304];
  ulonglong local_48;
  
  local_48 = DAT_1800516d8 ^ (ulonglong)auStackY_1b8;
  iVar12 = 0;
  iVar3 = 0;
  uVar6 = 1;
  iVar2 = GRinqcnn();
  lVar4 = GRinqscp();
  if (lVar4 != 0) {
    uVar5 = HYrslhie(lVar4,&DAT_18003fa80,&local_180,&local_188);
    if ((int)uVar5 == 0) {
      return uVar5;
    }
    uVar6 = HYGetFinfoCls(local_180,local_188);
  }
  uVar6 = HYPshFinfo(uVar6);
  lVar10 = 0;
  do {
    lVar9 = lVar10 + 1;
    if (param_2[lVar10] != (&DAT_18004049c)[lVar10]) {
      iVar8 = 0;
      lVar10 = 0;
      goto LAB_180017360;
    }
    lVar10 = lVar9;
  } while (lVar9 != 4);
  goto LAB_18001739a;
  while( true ) {
    iVar12 = iVar12 + 1;
    lVar4 = lVar4 + 1;
    if (7 < lVar4) break;
LAB_180017427:
    if (param_2[lVar4] == ' ') {
      param_2[iVar12] = '\0';
      goto LAB_180017451;
    }
  }
  FUN_18001d3c0(param_2,1);
  goto LAB_18001756d;
  while( true ) {
    iVar8 = iVar8 + 1;
    lVar10 = lVar10 + 1;
    if (7 < lVar10) break;
LAB_180017360:
    if (param_2[lVar10] == '\0') {
      if (iVar8 < 8) {
        memset(param_2 + iVar8,-0x7ffbfbe0,(longlong)(8 - iVar8));
      }
      break;
    }
  }
  param_2[8] = '\0';
LAB_18001739a:
  if (param_1 == 1) {
    if (iVar2 == 2) {
      pcVar11 = param_2;
      do {
        cVar1 = *pcVar11;
        pcVar11[(longlong)(local_178 + -(longlong)param_2)] = cVar1;
        pcVar11 = pcVar11 + 1;
      } while (cVar1 != '\0');
      if (lVar4 != 0) {
        FUN_180008f80(local_178,"%s.%s",lVar4,param_2);
      }
      uVar7 = SimIsBlockInBatchHierarchy(local_178);
      if ((int)uVar7 == 1) {
        uVar5 = 0x30030000;
        pcVar11 = (char *)0x0;
      }
      else {
        lVar4 = 0;
        do {
          lVar10 = lVar4 + 1;
          if (param_2[lVar4] != (&DAT_18004049c)[lVar4]) {
            uVar5 = 0x120101ff;
            pcVar11 = param_2;
            goto LAB_18001754b;
          }
          lVar4 = lVar10;
        } while (lVar10 != 4);
        uVar5 = 0x12010200;
        pcVar11 = (char *)0x0;
      }
LAB_18001754b:
      iVar3 = FUN_180030240((char *)0x0,param_3,0,uVar5,pcVar11);
    }
    iVar2 = 1;
  }
  else {
    if (param_1 != 2) {
      if (param_1 == 3) {
        lVar4 = 0;
        do {
          lVar10 = lVar4 + 1;
          if (param_2[lVar4] != (&DAT_18004049c)[lVar4]) {
            if (iVar2 == 2) {
              iVar3 = FUN_180030240((char *)0x0,param_3,0,0x120301ff,param_2);
            }
            lVar4 = 0;
            goto LAB_180017427;
          }
          lVar4 = lVar10;
        } while (lVar10 != 4);
        if (iVar2 == 2) {
          iVar3 = FUN_180030240((char *)0x0,param_3,0,0x12030200,(char *)0x0);
          FUN_18001d3c0(param_2,1);
        }
        else {
LAB_180017451:
          FUN_18001d3c0(param_2,1);
        }
      }
      goto LAB_18001756d;
    }
    if (iVar2 == 2) {
      lVar4 = 0;
      do {
        lVar10 = lVar4 + 1;
        if (param_2[lVar4] != (&DAT_18004049c)[lVar4]) {
          uVar5 = 0x120201ff;
          pcVar11 = param_2;
          goto LAB_18001749b;
        }
        lVar4 = lVar10;
      } while (lVar10 != 4);
      uVar5 = 0x12020200;
      pcVar11 = (char *)0x0;
LAB_18001749b:
      iVar3 = FUN_180030240((char *)0x0,param_3,0,uVar5,pcVar11);
    }
    iVar2 = 2;
  }
  FUN_18001cc30(iVar2,0,param_2,1);
LAB_18001756d:
  HYPopFinfo(uVar6);
  if (iVar3 != 0) {
    switch(*(uint *)(param_3 + 8)) {
    case 4:
    case 6:
    case 7:
    case 8:
    case 10:
    case 0xb:
    case 0xd:
    case 0xe:
    case 0xf:
    case 0x10:
      GRsetust(0);
      break;
    default:
      return (ulonglong)*(uint *)(param_3 + 8);
    }
  }
  return 0xffffffff;
}

/* RVA 0x17610 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180017610(int param_1,char *param_2,char *param_3,char *param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  char *pcVar5;
  undefined1 auStackY_68 [32];
  int local_38;
  undefined8 local_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = DAT_1800516d8 ^ (ulonglong)auStackY_68;
  uVar4 = 1;
  pcVar5 = param_3;
  GRinqcnn();
  lVar1 = GRinqscp();
  if (lVar1 != 0) {
    param_4 = (char *)&local_30;
    pcVar5 = (char *)&local_28;
    uVar2 = HYrslhie(lVar1,&DAT_18003fa80);
    if ((int)uVar2 == 0) {
      return uVar2;
    }
    uVar4 = HYGetFinfoCls(local_28,local_30);
  }
  uVar4 = HYPshFinfo(uVar4);
  FUN_1800167c0(param_1,param_2,pcVar5,param_4);
  if (param_1 == 1) {
    uVar2 = 0x201ff00;
  }
  else if (param_1 == 2) {
    uVar2 = 0x202ff00;
  }
  else if (param_1 == 3) {
    uVar2 = 0x203ff00;
  }
  else if (param_1 == 4) {
    uVar2 = 0x204ff00;
  }
  else if (param_1 == 5) {
    uVar2 = 0x205ff00;
  }
  else if (param_1 == 6) {
    uVar2 = 0x207ff00;
  }
  else if (param_1 == 7) {
    uVar2 = 0x208ff00;
  }
  else if (param_1 == 8) {
    uVar2 = 0x209ff00;
  }
  else if (param_1 == 9) {
    uVar2 = 0x20aff00;
  }
  else if (param_1 == 10) {
    uVar2 = 0x20bff00;
  }
  else if (param_1 == 0xb) {
    uVar2 = 0x20cff00;
  }
  else if (param_1 == 0xc) {
    uVar2 = 0x20dff00;
  }
  else {
    if (param_1 - 0xdU < 2) {
      uVar3 = FUN_180023a50();
      if ((int)uVar3 == -1) {
        return 0xffffffff;
      }
      uVar2 = 0x2810000;
      if (param_1 != 0xd) {
        uVar2 = 0x2830000;
      }
    }
    else {
      if (param_1 != 0xf) {
        if (param_1 == 0x10) {
          uVar2 = 0x285ff00;
        }
        else if (param_1 == 0x11) {
          uVar2 = 0x287ff00;
        }
        else if (param_1 == 0x12) {
          uVar2 = 0x288ff00;
        }
        else if (param_1 == 0x13) {
          uVar2 = 0x2b3ff00;
        }
        else if (param_1 == 0x14) {
          uVar2 = 0x2b4ff00;
        }
        else if (param_1 == 0x15) {
          uVar2 = 0x20eff00;
        }
        else {
          if (param_1 == 0x16) {
            uVar2 = 0x2940000;
            goto LAB_18001786e;
          }
          if (param_1 == 0x17) {
            uVar2 = 0x211ff00;
          }
          else {
            if (param_1 != 0x18) goto LAB_180017886;
            uVar2 = 0x212ff00;
          }
        }
        goto LAB_180017877;
      }
      uVar2 = 0x2840000;
    }
LAB_18001786e:
    param_2 = (char *)0x0;
  }
LAB_180017877:
  local_38 = FUN_180030240((char *)0x0,param_3,0,uVar2,param_2);
LAB_180017886:
  HYPopFinfo(uVar4);
  if (local_38 != 0) {
    switch(*(undefined4 *)(param_3 + 8)) {
    case 4:
    case 6:
    case 7:
    case 8:
    case 10:
    case 0xb:
    case 0xd:
    case 0xe:
    case 0xf:
    case 0x10:
      GRsetust(0);
      break;
    default:
      show_mouse();
      return (ulonglong)*(uint *)(param_3 + 8);
    }
  }
  return 0xffffffff;
}

/* RVA 0x17920 */
undefined4 FUN_180017920(void)

{
  int iVar1;
  undefined4 uVar2;
  longlong lVar3;
  LPCSTR pCVar4;
  char *pcVar5;
  
  uVar2 = 0;
  lVar3 = GRinqexc();
  if (lVar3 == 0) {
    return 0;
  }
  pCVar4 = (LPCSTR)GRinqexc();
  iVar1 = SBaskreexc(pCVar4);
  if (iVar1 == 1) {
    pcVar5 = (char *)GRinqexc();
    uVar2 = SBmoveto(1,pcVar5);
  }
  else {
    if (iVar1 == 0) {
      return 0xfffffffe;
    }
    if (iVar1 == 2) {
      GRsetexc(0);
      return 0;
    }
  }
  return uVar2;
}

/* RVA 0x17990 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_180017990(void)

{
  int iVar1;
  undefined1 auStackY_158 [32];
  char local_128 [8];
  undefined4 local_120;
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_158;
  GRinqcnn();
  iVar1 = FUN_180030240((char *)0x0,local_128,0,0x30030000,(char *)0x0);
  if (iVar1 == 0) {
    local_120 = 0xffffffff;
  }
  return local_120;
}

/* RVA 0x17a00 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180017a00(int param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  longlong lVar2;
  int iVar3;
  ulonglong uVar4;
  char *pcVar5;
  undefined8 uVar6;
  longlong lVar8;
  longlong lVar7;
  undefined1 auStackY_348 [32];
  char *local_318;
  char *local_310;
  undefined8 local_308;
  undefined8 local_300;
  char local_2f8 [8];
  uint local_2f0;
  char local_1e8 [16];
  char local_1d8 [16];
  char local_1c8 [400];
  ulonglong local_38;
  
  local_38 = DAT_1800516d8 ^ (ulonglong)auStackY_348;
  local_310 = (char *)0x0;
  local_1e8[0] = '\0';
  uVar6 = 1;
  iVar3 = HYparnam(param_2,&local_310,&local_318);
  if (iVar3 != 0) {
    lVar8 = -(longlong)local_318;
    do {
      cVar1 = *local_318;
      local_318[(longlong)(local_1d8 + lVar8)] = cVar1;
      local_318 = local_318 + 1;
    } while (cVar1 != '\0');
    pcVar5 = local_310;
    do {
      cVar1 = *pcVar5;
      pcVar5[(longlong)(local_1e8 + -(longlong)local_310)] = cVar1;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    local_318 = local_1d8;
    uVar4 = HYrslhie(local_310,&DAT_18003fa80,&local_300,&local_308);
    if ((int)uVar4 == 0) {
      return uVar4;
    }
    uVar6 = HYGetFinfoCls(local_300,local_308);
  }
  uVar6 = HYPshFinfo(uVar6);
  pcVar5 = local_1e8;
  if (local_1e8[0] == '\0') {
    pcVar5 = "";
  }
  SBsetscp(pcVar5);
  if (param_1 == 1) {
    FUN_180008f80(local_1c8,"%s, %s %s RAMP %s",local_318,param_3);
  }
  else if (param_1 == 2) {
    FUN_180008f80(local_1c8,"%s, %s %s SRAMP %s",local_318,param_3);
  }
  else {
    FUN_180008f80(local_1c8,"%s, %s %s",local_318,param_3);
  }
  lVar8 = -1;
  do {
    lVar7 = lVar8 + 1;
    lVar2 = lVar8 + 1;
    lVar8 = lVar7;
  } while (local_1c8[lVar2] != '\0');
  iVar3 = FUN_180030240((char *)0x0,local_2f8,0,lVar7 * 0x100 | 0x300500ff,local_1c8);
  HYPopFinfo(uVar6);
  uVar4 = (ulonglong)local_2f0;
  if (iVar3 == 0) {
    uVar4 = 0xffffffff;
  }
  return uVar4;
}

/* RVA 0x17bf0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_180017bf0(int param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  int iVar2;
  longlong lVar4;
  longlong lVar3;
  undefined1 auStackY_2e8 [32];
  char local_2b8 [8];
  undefined4 local_2b0;
  char local_1a8 [400];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_2e8;
  if (param_1 == 1) {
    FUN_180008f80(local_1a8,"%s %s %s RAMP %s",param_2,param_3);
  }
  else if (param_1 == 2) {
    FUN_180008f80(local_1a8,"%s %s %s SRAMP %s",param_2,param_3);
  }
  else {
    FUN_180008f80(local_1a8,"%s %s %s",param_2,param_3);
  }
  lVar4 = -1;
  do {
    lVar3 = lVar4 + 1;
    lVar1 = lVar4 + 1;
    lVar4 = lVar3;
  } while (local_1a8[lVar1] != '\0');
  iVar2 = FUN_180030240((char *)0x0,local_2b8,0,lVar3 * 0x100 | 0x300400ff,local_1a8);
  if (iVar2 == 0) {
    local_2b0 = 0xffffffff;
  }
  return local_2b0;
}

/* RVA 0x17cf0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_180017cf0(undefined8 param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  int iVar2;
  char *pcVar3;
  longlong lVar5;
  longlong lVar4;
  undefined1 auStackY_2e8 [32];
  char local_2b8 [8];
  undefined4 local_2b0;
  char local_1a8 [400];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_2e8;
  pcVar3 = "SAVE %s";
  if (param_2 != 1) {
    pcVar3 = "RESTORE %s";
  }
  FUN_180008f80(local_1a8,pcVar3,param_1,param_4);
  lVar5 = -1;
  do {
    lVar4 = lVar5 + 1;
    lVar1 = lVar5 + 1;
    lVar5 = lVar4;
  } while (local_1a8[lVar1] != '\0');
  iVar2 = FUN_180030240((char *)0x0,local_2b8,0,lVar4 * 0x100 | 0x300200ff,local_1a8);
  if (iVar2 == 0) {
    local_2b0 = 0xffffffff;
  }
  return local_2b0;
}

/* RVA 0x17da0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_180017da0(uint param_1)

{
  int iVar1;
  ulonglong uVar2;
  undefined1 auStackY_178 [32];
  char local_148 [8];
  undefined4 local_140;
  ulonglong local_38;
  
  local_38 = DAT_1800516d8 ^ (ulonglong)auStackY_178;
  if ((DAT_180052ec4 != 0) && (iVar1 = GRinqiap(), iVar1 != 0)) {
    if (param_1 == 0xffffffff) {
      uVar2 = 0x1018100;
    }
    else {
      if (param_1 == 0) {
        param_1 = 0xffffff80;
      }
      uVar2 = ((ulonglong)(param_1 & 0xff) | 0x10100) << 8;
    }
    iVar1 = FUN_180030240((char *)0x0,local_148,0,uVar2,(char *)0x0);
    if (iVar1 != 0) {
      _guard_check_icall();
      switch(local_140) {
      case 4:
      case 6:
      case 7:
      case 8:
      case 10:
      case 0xb:
      case 0xd:
      case 0xe:
      case 0xf:
      case 0x10:
        GRsetust(0);
        break;
      default:
        show_mouse();
        return local_140;
      }
    }
  }
  return 0xffffffff;
}

/* RVA 0x17ee0 */
undefined8 FUN_180017ee0(void)

{
  uint uVar1;
  int iVar2;
  
  if ((*(int *)runanyway_exref == 0) &&
     (*(int *)(hunks_exref + **(longlong **)iwpfile_exref * 0x108 + 0xf4) == 0)) {
    GRinqerr();
    return 0;
  }
  uVar1 = GRinqerr();
  iVar2 = GRinqcat();
  if (((((iVar2 == 0) && (*(int *)(*(longlong *)topfinfo_exref + 0x660) == 0)) &&
       (DAT_180052ec4 != 0)) &&
      ((*(int *)(*(longlong *)topfinfo_exref + 0x380) == 1 && (iVar2 = GRinqiap(), iVar2 == 1)))) &&
     ((iVar2 = GRinqgpd(), iVar2 != 0 && (((uVar1 & 0xfffffffa) == 0 && (uVar1 != 4)))))) {
    return 1;
  }
  return 0;
}

/* RVA 0x17f80 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180017f80(void)

{
  undefined1 auStackY_158 [32];
  char local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_158;
  DAT_180050de4 = 0;
  FUN_180030240((char *)0x0,local_128,0,0x2820000,(char *)0x0);
  DAT_180050de4 = 1;
  return;
}

/* RVA 0x17fe0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_180017fe0(int *param_1,char *param_2,FILE *param_3,char *param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined8 uVar6;
  char *pcVar7;
  char *pcVar8;
  FILE *_Size;
  undefined8 uVar9;
  undefined1 auStackY_968 [32];
  char *local_938;
  undefined8 local_930;
  undefined1 local_928 [24];
  int local_910;
  char local_808 [8];
  undefined1 local_800;
  ulonglong local_38;
  
  local_38 = DAT_1800516d8 ^ (ulonglong)auStackY_968;
  iVar3 = *param_1;
  pcVar7 = (char *)((ulonglong)param_3 & 0xffffffff);
  uVar9 = 1;
  pcVar8 = param_2;
  _Size = param_3;
  iVar2 = GRinqust();
  if (iVar2 == 2) {
    GRsetust();
  }
  if (iVar3 == 0) {
    if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
      local_808[0] = '\0';
      uVar9 = EXmsgbox();
      if ((int)uVar9 == -1) {
        return 0xffffffff;
      }
      uVar9 = EXmsgbox();
      if ((int)uVar9 == -1) {
        return 0xffffffff;
      }
      show_mouse();
      FUN_180018e70(0,pcVar8,_Size,param_4);
      return 0;
    }
    iVar3 = FUN_1800163c0(param_2);
    if (1 < iVar3) {
      _Size = (FILE *)(local_928 + 0x10);
      uVar4 = FUN_180016430(0,param_2,_Size,pcVar7);
      param_4 = pcVar7;
      if ((int)uVar4 == 0) {
        return 0;
      }
    }
    FUN_180018800(param_2,&local_938);
    pcVar8 = local_808 + -(longlong)local_938;
    pcVar7 = local_938;
    do {
      cVar1 = *pcVar7;
      pcVar7[(longlong)pcVar8] = cVar1;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    iVar3 = 0;
    lVar5 = 0;
    do {
      if (local_808[lVar5] == '\0') {
        if (iVar3 < 8) {
          pcVar8 = (char *)CONCAT71((int7)((ulonglong)pcVar8 >> 8),0x20);
          _Size = (FILE *)(longlong)(8 - iVar3);
          memset(local_808 + iVar3,(int)pcVar8,(size_t)_Size);
        }
        local_800 = 0;
        iVar3 = (int)local_938;
        goto LAB_1800181c4;
      }
      iVar3 = iVar3 + 1;
      lVar5 = lVar5 + 1;
    } while (lVar5 < 8);
    local_800 = 0;
    iVar3 = (int)local_938;
  }
  else if (param_2 == (char *)0x0) {
    local_808[0] = '\0';
  }
  else {
    iVar2 = FUN_1800163c0(param_2);
    if (1 < iVar2) {
      _Size = (FILE *)(local_928 + 0x10);
      uVar4 = FUN_180016430(iVar3,param_2,_Size,pcVar7);
      param_4 = pcVar7;
      if ((int)uVar4 == 0) {
        return 0;
      }
    }
    FUN_180018800(param_2,&local_938);
    pcVar8 = local_808 + -(longlong)local_938;
    do {
      cVar1 = *local_938;
      local_938[(longlong)pcVar8] = cVar1;
      local_938 = local_938 + 1;
    } while (cVar1 != '\0');
    iVar2 = 0;
    lVar5 = 0;
    do {
      if (local_808[lVar5] == '\0') {
        if (iVar2 < 8) {
          pcVar8 = (char *)CONCAT71((int7)((ulonglong)pcVar8 >> 8),0x20);
          _Size = (FILE *)(longlong)(8 - iVar2);
          memset(local_808 + iVar2,(int)pcVar8,(size_t)_Size);
        }
        local_800 = 0;
        goto LAB_1800181c4;
      }
      iVar2 = iVar2 + 1;
      lVar5 = lVar5 + 1;
    } while (lVar5 < 8);
    local_800 = 0;
  }
LAB_1800181c4:
  if ((int)param_3 == 0) {
    GRsetmtf();
    FUN_180018e70(0,pcVar8,_Size,param_4);
  }
  local_938 = (char *)GRinqscp();
  if (local_938 != (char *)0x0) {
    param_4 = (char *)&local_930;
    _Size = (FILE *)local_928;
    iVar2 = HYrslhie(local_938,&DAT_18003fa80);
    if (iVar2 == 0) {
      return 0;
    }
    uVar9 = HYGetFinfoCls(local_928._0_8_,local_930);
  }
  uVar9 = HYPshFinfo(uVar9);
  FUN_1800167c0(iVar3,local_808,_Size,param_4);
  if (iVar3 == 1) {
    iVar3 = FUN_180030240((char *)0x0,local_928 + 0x10,0,0x201ff00,local_808);
  }
  else if (iVar3 == 2) {
    iVar3 = FUN_180030240((char *)0x0,local_928 + 0x10,0,0x202ff00,local_808);
  }
  else if (iVar3 == 3) {
    iVar3 = FUN_180030240((char *)0x0,local_928 + 0x10,0,0x203ff00,local_808);
  }
  else if (iVar3 == 4) {
    iVar3 = FUN_180030240((char *)0x0,local_928 + 0x10,0,0x204ff00,local_808);
  }
  else if (iVar3 == 5) {
    iVar3 = FUN_180030240((char *)0x0,local_928 + 0x10,0,0x205ff00,local_808);
  }
  else if (iVar3 == 6) {
    iVar3 = FUN_180030240((char *)0x0,local_928 + 0x10,0,0x207ff00,local_808);
  }
  else if (iVar3 == 7) {
    iVar3 = FUN_180030240((char *)0x0,local_928 + 0x10,0,0x208ff00,local_808);
  }
  else if (iVar3 == 8) {
    iVar3 = FUN_180030240((char *)0x0,local_928 + 0x10,0,0x209ff00,local_808);
  }
  else if (iVar3 == 9) {
    iVar3 = FUN_180030240((char *)0x0,local_928 + 0x10,0,0x20aff00,local_808);
  }
  else if (iVar3 == 10) {
    iVar3 = FUN_180030240((char *)0x0,local_928 + 0x10,0,0x20bff00,local_808);
  }
  else if (iVar3 == 0xb) {
    iVar3 = FUN_180030240((char *)0x0,local_928 + 0x10,0,0x20cff00,local_808);
  }
  else if (iVar3 == 0xc) {
    iVar3 = FUN_180030240((char *)0x0,local_928 + 0x10,0,0x20dff00,local_808);
  }
  else if (iVar3 - 0xdU < 2) {
    uVar6 = FUN_180023a50();
    if ((int)uVar6 == -1) {
      return 0xffffffff;
    }
    if (iVar3 == 0xd) {
      iVar3 = FUN_180030240((char *)0x0,local_928 + 0x10,0,0x2810000,(char *)0x0);
      *param_1 = 0xd;
    }
    else {
      iVar3 = FUN_180030240((char *)0x0,local_928 + 0x10,0,0x2830000,(char *)0x0);
      *param_1 = 0xe;
    }
  }
  else if (iVar3 == 0xf) {
    iVar3 = FUN_180030240((char *)0x0,local_928 + 0x10,0,0x2840000,(char *)0x0);
  }
  else if (iVar3 == 0x10) {
    iVar3 = FUN_180030240((char *)0x0,local_928 + 0x10,0,0x285ff00,local_808);
  }
  else if (iVar3 == 0x11) {
    iVar3 = FUN_180030240((char *)0x0,local_928 + 0x10,0,0x287ff00,local_808);
  }
  else if (iVar3 == 0x12) {
    iVar3 = FUN_180030240((char *)0x0,local_928 + 0x10,0,0x288ff00,local_808);
  }
  else if (iVar3 == 0x13) {
    iVar3 = FUN_180030240((char *)0x0,local_928 + 0x10,0,0x2b3ff00,local_808);
  }
  else if (iVar3 == 0x14) {
    iVar3 = FUN_180030240((char *)0x0,local_928 + 0x10,0,0x2b4ff00,local_808);
  }
  else if (iVar3 == 0x15) {
    iVar3 = FUN_180030240((char *)0x0,local_928 + 0x10,0,0x20eff00,local_808);
  }
  else if (iVar3 == 0x16) {
    iVar3 = FUN_180030240((char *)0x0,local_928 + 0x10,0,0x2940000,(char *)0x0);
  }
  else if (iVar3 == 0x17) {
    iVar3 = FUN_180030240((char *)0x0,local_928 + 0x10,0,0x211ff00,local_808);
  }
  else {
    if (iVar3 != 0x18) {
      iVar3 = (int)local_938;
      goto LAB_1800185f4;
    }
    iVar3 = FUN_180030240((char *)0x0,local_928 + 0x10,0,0x212ff00,local_808);
  }
LAB_1800185f4:
  HYPopFinfo(uVar9);
  if (iVar3 != 0) {
    switch(local_910) {
    case 4:
    case 6:
    case 7:
    case 8:
    case 10:
    case 0xb:
    case 0xd:
    case 0xe:
    case 0xf:
    case 0x10:
      GRsetust(0);
      break;
    default:
      show_mouse();
      return local_910;
    }
  }
  return 0xffffffff;
}

/* RVA 0x186a0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_1800186a0(void)

{
  undefined1 auStack_278 [32];
  int *local_258;
  int local_248 [4];
  undefined1 local_238 [8];
  uint local_230;
  undefined1 local_128 [4];
  undefined4 local_124;
  undefined4 local_120;
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_278;
  local_248[1] = 1;
  if (DAT_180052ec4 == 0) {
    return 0;
  }
  FUN_1800194c0(0);
  local_248[0] = -1;
  local_120 = 0xd;
  local_124 = 1;
  SyncDataShareOut();
  local_258 = local_248;
  SEND_MESSAGE_WAIT(&DAT_1800521b4,local_248 + 1,local_128,local_238);
  SyncDataShareIn();
  local_230 = (local_230 ^ (int)local_230 >> 0x1f) - ((int)local_230 >> 0x1f);
  GRsetiap(0);
  if (((local_248[0] == 0) && (*(longlong *)iwpfile_exref != 0)) &&
     (*(longlong *)topfinfo_exref != 0)) {
    GRsetsme();
    FUN_180021b60(0);
    GRsetgpd(0);
    *(undefined4 *)(*(longlong *)topfinfo_exref + 0x438) = 0xffffffff;
  }
  else {
    if (local_230 == 9) {
      return 9;
    }
    if (local_230 == 0) {
      return 0;
    }
  }
  return 0xffffffff;
}

/* RVA 0x187d0 */
undefined8 FUN_1800187d0(void)

{
  int iVar1;
  
  iVar1 = DCHasEngineServer();
  if (iVar1 != 0) {
    FUN_1800071b0(0x132,(LPCSTR)0x0,(longlong *)0x0);
  }
  return 0;
}

/* RVA 0x18800 */
void FUN_180018800(char *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  char *local_res18 [2];
  
  uVar1 = FUN_1800272e0(param_1,local_res18,param_2);
  if ((int)uVar1 == 0) {
    local_res18[0] = "";
  }
  SBsetscp(local_res18[0]);
  return;
}

/* RVA 0x18830 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 SBmoveto(int param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  char *pcVar6;
  ulonglong _Count;
  undefined1 auStackY_1c8 [32];
  char *local_198 [2];
  char local_188 [8];
  undefined4 local_180;
  char local_78 [8];
  undefined1 local_70;
  undefined1 local_6f;
  char local_68 [80];
  ulonglong local_18;
  
                    /* 0x18830  214  SBmoveto */
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_1c8;
  SetGlobalPointer("GRlstmov",EXmsgbox);
  iVar2 = GRinqust();
  if (iVar2 == 2) {
    GRsetust(1);
  }
  if ((param_2 == (char *)0x0) || (local_198[0] = strstr(param_2," #"), local_198[0] == (char *)0x0)
     ) {
    if (DAT_1800509dc == -1) {
      if (param_1 == 0) {
        if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
          local_78[0] = '\0';
          local_68[0] = '\0';
          uVar4 = EXmsgbox();
          if ((int)uVar4 == -1) {
            return 0xffffffff;
          }
          iVar2 = FUN_180014760(local_68,1,0);
          if ((iVar2 == 0) || ((iVar2 != 0xc && (local_68[0] == '\0')))) {
            show_mouse();
            return 0;
          }
          FUN_180018800(local_68,local_198);
          pcVar6 = local_198[0];
          strncpy(local_78,local_198[0],9);
          iVar3 = 0;
          local_6f = 0;
          lVar5 = 0;
          do {
            if (local_78[lVar5] == '\0') {
              if (iVar3 < 8) {
                memset(local_78 + iVar3,(int)CONCAT71((int7)((ulonglong)pcVar6 >> 8),0x20),
                       (longlong)(8 - iVar3));
              }
              local_70 = 0;
              goto LAB_180018b6b;
            }
            iVar3 = iVar3 + 1;
            lVar5 = lVar5 + 1;
          } while (lVar5 < 8);
          local_70 = 0;
          goto LAB_180018b6b;
        }
        FUN_180018800(param_2,local_198);
        pcVar6 = local_198[0];
        do {
          cVar1 = *pcVar6;
          pcVar6[(longlong)(local_78 + -(longlong)local_198[0])] = cVar1;
          pcVar6 = pcVar6 + 1;
        } while (cVar1 != '\0');
        lVar5 = -(longlong)param_2;
        do {
          cVar1 = *param_2;
          param_2[(longlong)(local_68 + lVar5)] = cVar1;
          param_2 = param_2 + 1;
        } while (cVar1 != '\0');
        iVar2 = 0;
        lVar5 = 0;
        do {
          if (local_78[lVar5] == '\0') {
            if (iVar2 < 8) {
              memset(local_78 + iVar2,
                     (int)CONCAT71((int7)((ulonglong)(local_78 + -(longlong)local_198[0]) >> 8),0x20
                                  ),(longlong)(8 - iVar2));
            }
            local_70 = 0;
            pcVar6 = local_68;
            iVar2 = 0;
            goto LAB_180018b5e;
          }
          iVar2 = iVar2 + 1;
          lVar5 = lVar5 + 1;
        } while (lVar5 < 8);
        local_70 = 0;
        pcVar6 = local_68;
        iVar2 = 0;
      }
      else {
        if (param_2 == (char *)0x0) {
          local_78[0] = '\0';
          local_68[0] = '\0';
        }
        else {
          FUN_180018800(param_2,local_198);
          pcVar6 = local_198[0];
          do {
            cVar1 = *pcVar6;
            pcVar6[(longlong)(local_78 + -(longlong)local_198[0])] = cVar1;
            pcVar6 = pcVar6 + 1;
          } while (cVar1 != '\0');
          lVar5 = -(longlong)param_2;
          do {
            cVar1 = *param_2;
            param_2[(longlong)(local_68 + lVar5)] = cVar1;
            param_2 = param_2 + 1;
          } while (cVar1 != '\0');
        }
        pcVar6 = local_78;
        iVar2 = param_1;
      }
LAB_180018b5e:
      iVar2 = FUN_180014760(pcVar6,iVar2,1);
    }
    else {
      if (DAT_180051fd8 == 0) {
        local_78[0] = '\0';
        local_68[0] = '\0';
      }
      else {
        pcVar6 = param_2;
        do {
          cVar1 = *pcVar6;
          pcVar6[(longlong)(local_68 + -(longlong)param_2)] = cVar1;
          pcVar6 = pcVar6 + 1;
        } while (cVar1 != '\0');
        FUN_180018800(param_2,local_198);
        strncpy(local_78,local_198[0],9);
        local_6f = 0;
      }
      iVar2 = FUN_180014760(local_78,DAT_1800509dc,1);
      param_1 = DAT_1800509dc;
    }
  }
  else {
    _Count = (ulonglong)((int)local_198[0] - (int)param_2);
    strncpy(local_68,param_2,_Count);
    if (0x4f < _Count) {
                    /* WARNING: Subroutine does not return */
      FUN_18003b6e4();
    }
    local_68[_Count] = '\0';
    iVar2 = atoi(local_198[0] + 2);
    FUN_180018800(local_68,local_198);
    strncpy(local_78,local_198[0],9);
    local_6f = 0;
    param_1 = FUN_1800147c0(local_68,iVar2);
  }
LAB_180018b6b:
  if (0 < iVar2) {
    if (param_1 == 0) {
      FUN_1800147c0(local_68,iVar2);
    }
    GRsetmtf();
    if (iVar2 == 1) {
      iVar2 = FUN_180030240((char *)0x0,local_188,0,0x601ff00,local_78);
    }
    else if (iVar2 == 2) {
      iVar2 = FUN_180030240((char *)0x0,local_188,0,0x602ff00,local_78);
    }
    else if (iVar2 == 6) {
      iVar2 = FUN_180030240((char *)0x0,local_188,0,0x603ff00,local_78);
    }
    else if (iVar2 == 7) {
      iVar2 = FUN_180030240((char *)0x0,local_188,0,0x604ff00,local_78);
    }
    else if (iVar2 == 3) {
      iVar2 = FUN_180030240((char *)0x0,local_188,0,0x605ff00,local_78);
    }
    else if (iVar2 == 0xc) {
      iVar2 = FUN_180030240((char *)0x0,local_188,0,0x681ff00,local_78);
      local_78[0] = '\0';
      local_68[0] = '\0';
    }
    else if (iVar2 == 5) {
      iVar2 = FUN_180030240((char *)0x0,local_188,0,0x607ff00,local_78);
    }
    else if (iVar2 == 4) {
      iVar2 = FUN_180030240((char *)0x0,local_188,0,0x608ff00,local_78);
    }
    else if (iVar2 == 8) {
      iVar2 = FUN_180030240((char *)0x0,local_188,0,0x609ff00,local_78);
    }
    else if (iVar2 == 0xb) {
      iVar2 = FUN_180030240((char *)0x0,local_188,0,0x60bff00,local_78);
    }
    else if (iVar2 == 9) {
      iVar2 = FUN_180030240((char *)0x0,local_188,0,0x60cff00,local_78);
    }
    else if (iVar2 == 10) {
      iVar2 = FUN_180030240((char *)0x0,local_188,0,0x60dff00,local_78);
    }
    else if (iVar2 == 0x15) {
      iVar2 = FUN_180030240((char *)0x0,local_188,0,0x60eff00,local_78);
    }
    else if (iVar2 == 0xf) {
      iVar2 = FUN_180030240((char *)0x0,local_188,0,0x60fff00,local_78);
    }
    else {
      iVar2 = (int)local_198[0];
    }
    if (iVar2 != 0) {
      _guard_check_icall();
      switch(local_180) {
      case 4:
      case 6:
      case 7:
      case 8:
      case 10:
      case 0xb:
      case 0xd:
      case 0xe:
      case 0xf:
      case 0x10:
        GRsetust(0);
        break;
      default:
        show_mouse();
        return local_180;
      }
    }
  }
  return 0xffffffff;
}

/* RVA 0x18e70 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180018e70(int param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 auStack_148 [32];
  char local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_148;
  FUN_180008f80(local_128,"%s.mtz",*(undefined8 *)topfinfo_exref,param_4);
  if (param_1 == 1) {
    _DAT_1800538a8 = fopen(local_128,"w");
  }
  else {
    remove(local_128);
  }
  return;
}

/* RVA 0x18ef0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_180018ef0(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4)

{
  int iVar1;
  undefined1 *puVar2;
  char *pcVar3;
  undefined1 auStack_278 [32];
  undefined4 *local_258;
  undefined4 local_248;
  undefined4 local_244;
  undefined1 local_238 [4];
  undefined4 local_234;
  undefined4 local_230;
  char local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_278;
  local_248 = 1;
  local_244 = 1;
  FUN_1800194c0(1);
  if ((DAT_180052ec4 == 0) && (iVar1 = GRinqcnn(), iVar1 != 1)) {
    FUN_180025e00((char *)APtmpfil_exref,0,param_3,param_4);
    return local_248;
  }
  _guard_check_icall();
  if ((DAT_180052ec4 != 0) && (iVar1 = GRinqiap(), iVar1 != 0)) {
    FUN_1800186a0();
  }
  _guard_check_icall();
  local_230 = 8;
  local_234 = 1;
  _guard_check_icall();
  local_258 = &local_248;
  pcVar3 = local_128;
  puVar2 = local_238;
  SEND_MESSAGE_WAIT(&DAT_1800521b4);
  _guard_check_icall();
  if ((*(longlong *)iwpfile_exref != 0) && (*(longlong *)topfinfo_exref != 0)) {
    _guard_check_icall();
    GRsetgpd(0);
    _guard_check_icall();
    *(undefined4 *)(*(longlong *)topfinfo_exref + 0x438) = 0xffffffff;
    _guard_check_icall();
    GRsetari(*(undefined8 *)topfinfo_exref);
    _guard_check_icall();
    GRsetsms(0);
    _guard_check_icall();
    GRsetsmf(0);
    _guard_check_icall();
    GRsetsbm(0);
    _guard_check_icall();
    GRsetpgc();
    _guard_check_icall();
    GRsetedt();
    _guard_check_icall();
    GRsetexc();
    _guard_check_icall();
    SBsetnxt((char *)0x0,0);
  }
  _guard_check_icall();
  FUN_180025e00((char *)APtmpfil_exref,0,puVar2,pcVar3);
  _guard_check_icall();
  GRsetiap();
  _guard_check_icall();
  GRsetust();
  _guard_check_icall();
  FUN_180021b60(0);
  return local_248;
}

/* RVA 0x190c0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_1800190c0(void)

{
  int iVar1;
  undefined1 auStackY_158 [32];
  char local_128 [8];
  undefined4 local_120;
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_158;
  iVar1 = GRinqcnn();
  if (iVar1 == 2) {
    FUN_180030240((char *)0x0,local_128,0,0x12050200,(char *)0x0);
    return local_120;
  }
  return 1;
}

/* RVA 0x19140 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180019140(char *param_1,char ****param_2,char *param_3,char *param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  char ******ppppppcVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_938 [32];
  char ******local_918 [2];
  char local_908 [8];
  undefined4 local_900;
  char *****local_7f8 [250];
  ulonglong local_28;
  
  iVar8 = (int)param_4;
  local_28 = DAT_1800516d8 ^ (ulonglong)auStack_938;
  local_900 = 0;
  iVar3 = (int)param_3;
  ppppppcVar6 = (char ******)param_2;
  iVar2 = GRinqust();
  iVar7 = 1;
  if (iVar2 == 2) {
    GRsetust();
  }
  if ((int)param_2 == 0) {
    if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
      local_7f8[0]._0_1_ = '\0';
      uVar4 = EXmsgbox();
      if (((int)uVar4 != -1) && (uVar4 = EXmsgbox(), (int)uVar4 != -1)) {
        if (iVar3 == 0) goto LAB_180019282;
        ppppppcVar6 = (char ******)local_918;
        FUN_180018800((char *)local_7f8,ppppppcVar6);
        if (local_918[0] != local_7f8) {
          ppppppcVar6 = (char ******)((longlong)local_7f8 - (longlong)local_918[0]);
          do {
            cVar1 = *(char *)local_918[0];
            *(char *)((longlong)ppppppcVar6 + (longlong)local_918[0]) = cVar1;
            local_918[0] = (char ******)((longlong)local_918[0] + 1);
          } while (cVar1 != '\0');
        }
        goto LAB_18001926e;
      }
    }
    else {
      FUN_180018800(param_1,local_918);
      ppppppcVar6 = (char ******)((longlong)local_7f8 - (longlong)local_918[0]);
      do {
        cVar1 = *(char *)local_918[0];
        *(char *)((longlong)ppppppcVar6 + (longlong)local_918[0]) = cVar1;
        local_918[0] = (char ******)((longlong)local_918[0] + 1);
      } while (cVar1 != '\0');
LAB_18001926e:
      if (((char)local_7f8[0] == '\0') && (iVar3 < 4)) {
        show_mouse();
        goto LAB_180019282;
      }
      FUN_180018e70(0,ppppppcVar6,param_3,param_4);
      if (iVar3 == 4) {
        iVar3 = GRinqcnn();
        iVar2 = GRinqiap();
        if ((iVar3 != 2) || (iVar2 != 1)) {
          iVar7 = 0;
        }
        uVar4 = FUN_18002c760(iVar7,iVar8,param_3,param_4);
        if ((int)uVar4 != 0) {
          thunk_FUN_180008f30("");
        }
      }
      else {
        if (iVar3 != 5) {
          uVar5 = FUN_1800172a0(iVar3,(char *)local_7f8,local_908);
          GRsetmtf(1);
          show_mouse();
          return uVar5 & 0xffffffff;
        }
        show_mouse();
      }
    }
    uVar5 = 0xffffffff;
  }
  else {
    local_7f8[0]._0_1_ = '\0';
    iVar2 = 4;
    if (iVar3 != 0) {
      iVar2 = iVar3;
    }
    if (iVar2 != 0) {
      if (iVar2 == 4) {
        FUN_18002c760(0,iVar8,param_3,param_4);
      }
      return 0;
    }
LAB_180019282:
    FUN_180018e70(0,ppppppcVar6,param_3,param_4);
    uVar5 = 0;
  }
  return uVar5;
}

/* RVA 0x19330 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180019330(uint param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  uint uVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined1 auStackY_188 [32];
  char local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_188;
  SetGlobalPointer();
  DAT_180052ce4 = 0;
  uVar9 = FUN_180017ee0();
  if ((int)uVar9 == 0) {
    uVar11 = FUN_180019140((char *)0x0,(char ****)0x1,(char *)0x0,(ulonglong)param_1);
    uVar11 = uVar11 & 0xffffffff;
    thunk_FUN_180008f30("");
  }
  else {
    uVar10 = FUN_180019140((char *)0x0,(char ****)0x0,(char *)0x0,(ulonglong)param_1);
    uVar11 = uVar10 & 0xffffffff;
    if ((int)uVar10 == -1) {
      return uVar10;
    }
    if (*(int *)partial_results_exref != 0) {
      uVar8 = FUN_180030240((char *)0x0,local_128,0,0x1c000000,(char *)0x0);
      uVar11 = (ulonglong)uVar8;
      lVar2 = *(longlong *)topfinfo_exref;
      uVar4 = *(undefined8 *)(lVar2 + 0x5a0);
      uVar5 = *(undefined8 *)(lVar2 + 0x5a8);
      uVar3 = *(undefined8 *)(lVar2 + 0x5d0);
      uVar9 = *(undefined8 *)(lVar2 + 0x5b0);
      uVar6 = *(undefined8 *)(lVar2 + 0x5b8);
      uVar7 = *(undefined8 *)(lVar2 + 0x5c0);
      uVar1 = *(undefined8 *)(lVar2 + 0x5c8);
      hide_mouse();
      HYloohie(&DAT_18003ae52);
      lVar2 = *(longlong *)topfinfo_exref;
      *(undefined8 *)(lVar2 + 0x5a0) = uVar4;
      *(undefined8 *)(lVar2 + 0x5a8) = uVar5;
      *(undefined8 *)(lVar2 + 0x5b0) = uVar9;
      lVar2 = *(longlong *)topfinfo_exref;
      *(undefined8 *)(lVar2 + 0x5b8) = uVar6;
      *(undefined8 *)(lVar2 + 0x5c0) = uVar7;
      *(undefined8 *)(lVar2 + 0x5c8) = uVar1;
      *(undefined8 *)(*(longlong *)topfinfo_exref + 0x5d0) = uVar3;
      show_mouse();
    }
  }
  return uVar11;
}

/* RVA 0x194c0 */
undefined8 FUN_1800194c0(int param_1)

{
  if (param_1 == 0) {
    Ordinal_80();
  }
  else {
    DCReleaseServer();
  }
  FUN_1800071b0(0x130,(LPCSTR)0x0,(longlong *)0x0);
  FUN_18000f830();
  FUN_1800085e0(0);
  CoFreeUnusedLibraries();
  return 0;
}

/* RVA 0x19500 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_180019500(char *param_1)

{
  char cVar1;
  longlong lVar2;
  int iVar3;
  char *pcVar4;
  longlong lVar6;
  longlong lVar5;
  undefined1 auStackY_268 [32];
  char local_238 [8];
  undefined4 local_230;
  char local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_268;
  pcVar4 = param_1;
  do {
    cVar1 = *pcVar4;
    pcVar4[(longlong)(local_128 + -(longlong)param_1)] = cVar1;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  lVar6 = -1;
  do {
    lVar5 = lVar6 + 1;
    lVar2 = lVar6 + 1;
    lVar6 = lVar5;
  } while (local_128[lVar2] != '\0');
  DAT_180050de4 = 0;
  iVar3 = FUN_180030240((char *)0x0,local_238,0,lVar5 * 0x10000 | 0x1300ff00,local_128);
  DAT_180050de4 = 1;
  if (iVar3 == 0) {
LAB_1800195cd:
    DAT_180050de4 = 1;
    return -1;
  }
  switch(local_230) {
  case 4:
  case 6:
  case 7:
  case 8:
  case 10:
  case 0xb:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
    goto LAB_1800195cd;
  default:
    GRsetari(param_1);
    return iVar3;
  }
}

/* RVA 0x19630 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_180019630(char *param_1)

{
  char cVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined8 *puVar9;
  FILE *_File;
  undefined8 *puVar10;
  char *pcVar11;
  undefined8 uVar12;
  undefined1 auStackY_448 [32];
  undefined8 local_418;
  char local_408 [272];
  char local_2f8 [208];
  char local_228 [255];
  undefined8 uStack_129;
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_448;
  iVar7 = _stricmp((char *)APtmpfil_exref,*(char **)topfinfo_exref);
  if ((iVar7 == 0) || (iVar7 = FUN_180019500(param_1), iVar7 != -1)) {
    uVar6 = _UNK_1800412dc;
    uVar5 = _UNK_1800412d8;
    uVar4 = _UNK_1800412d4;
    uVar3 = _DAT_1800412d0;
    lVar2 = *(longlong *)topfinfo_exref;
    *(undefined4 *)(lVar2 + 0x438) = _DAT_1800412d0;
    *(undefined4 *)(lVar2 + 0x43c) = uVar4;
    *(undefined4 *)(lVar2 + 0x440) = uVar5;
    *(undefined4 *)(lVar2 + 0x444) = uVar6;
    *(undefined4 *)(lVar2 + 0x448) = uVar3;
    DAT_180050de4 = 0;
    FUN_180030240((char *)0x0,local_408,0,0x17010000,(char *)0x0);
    DAT_180050de4 = 1;
    iVar7 = FUN_180019500((char *)APtmpfil_exref);
    if (iVar7 != -1) {
      uVar12 = 0x17000000;
      DAT_180050de4 = 0;
      iVar7 = FUN_180030240((char *)0x0,local_408,0,0x17000000,(char *)0x0);
      DAT_180050de4 = 1;
      if (iVar7 == 1) {
        lVar2 = 0x100 - (longlong)param_1;
        do {
          cVar1 = *param_1;
          param_1[(longlong)(local_228 + lVar2)] = cVar1;
          param_1 = param_1 + 1;
        } while (cVar1 != '\0');
        _mbslwr((uchar *)((longlong)&uStack_129 + 1));
        iVar8 = MVGetProductCode();
        if (iVar8 == 2) {
          puVar9 = &uStack_129;
          do {
            pcVar11 = (char *)((longlong)puVar9 + 1);
            puVar9 = (undefined8 *)((longlong)puVar9 + 1);
          } while (*pcVar11 != '\0');
          *puVar9 = _DAT_180040b78;
        }
        else {
          puVar9 = &uStack_129;
          do {
            puVar10 = puVar9;
            puVar9 = (undefined8 *)((longlong)puVar10 + 1);
          } while (*(char *)((longlong)puVar10 + 1) != '\0');
          *(undefined4 *)((longlong)puVar10 + 1) = DAT_180040b80;
          *(undefined2 *)((longlong)puVar10 + 5) = DAT_180040b84;
          *(undefined1 *)((longlong)puVar10 + 7) = DAT_180040b86;
        }
        iVar8 = FUN_180026510((char *)0x0,(char *)((longlong)&uStack_129 + 1));
        if (iVar8 == 0) {
          *(undefined8 *)(*(longlong *)topfinfo_exref + 0x438) = local_418;
          iVar8 = SBlocalhost();
          pcVar11 = "%s.dan";
          if (iVar8 != 0) {
            pcVar11 = "%s.nin";
          }
          FUN_180008f80(local_228,pcVar11,APtmpfil_exref,uVar12);
          iVar8 = _access(local_228,0);
          if (iVar8 == 0) {
            _File = fopen(local_228,"r");
            if (_File != (FILE *)0x0) {
              clean_buffer(*(undefined8 *)(*(longlong *)topfinfo_exref + 0x548));
              pcVar11 = fgets(local_2f8,200,_File);
              while (pcVar11 != (char *)0x0) {
                SFfiltra(local_2f8,&DAT_18004100c);
                append_buffer_line(*(undefined8 *)(*(longlong *)topfinfo_exref + 0x548),local_2f8);
                pcVar11 = fgets(local_2f8,200,_File);
              }
              fclose(_File);
            }
            iVar8 = SBlocalhost();
            if (iVar8 == 0) {
              remove(local_228);
            }
          }
        }
      }
      return iVar7;
    }
  }
  return -1;
}

