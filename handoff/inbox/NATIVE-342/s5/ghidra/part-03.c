/* RVA 0xbc20 */
void FUN_18000bc20(longlong param_1,longlong *param_2)

{
  int iVar1;
  longlong *plVar2;
  longlong *plVar3;
  
  if (param_1 != 0) {
    if (param_2 != (longlong *)0x0) {
      *(longlong **)(param_1 + 0x10) = param_2;
    }
    plVar3 = (longlong *)(param_1 + 0x80);
    plVar2 = plVar3;
    if (0xf < *(ulonglong *)(param_1 + 0x98)) {
      plVar2 = (longlong *)*plVar3;
    }
    SaveHapp(param_2,*(char *)(param_1 + 0xb8) == '\0',plVar2,0);
    iVar1 = FUN_180033bd0();
    if (iVar1 == 1) {
      FUN_18001bf90(param_1,param_2);
    }
    iVar1 = FUN_180033bd0();
    if (iVar1 == 1) {
      FUN_18001a7a0(param_1,param_2);
      if (0xf < *(ulonglong *)(param_1 + 0x98)) {
        plVar3 = (longlong *)*plVar3;
      }
      FUN_18001a540(param_1,param_2,(char *)plVar3);
      FUN_18001ad40(param_1,param_2);
      FUN_18001c460(param_1,param_2);
    }
    FUN_18001a660(param_1,param_2);
    FUN_18001a400(param_1,param_2);
    (**(code **)(*param_2 + 0x48))(param_2,0);
  }
  return;
}

/* RVA 0xbd10 */
void FUN_18000bd10(undefined8 *param_1,
                  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2)

{
  int iVar1;
  CWinThread *pCVar2;
  longlong lVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar4;
  undefined8 uVar5;
  char *pcVar6;
  ulonglong uVar7;
  void **local_res8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_res10;
  LPCSTR local_res18;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res20 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_28 [16];
  
  local_res10 = param_2;
  pCVar2 = AfxGetThread();
  if (pCVar2 == (CWinThread *)0x0) {
LAB_18000bd44:
    uVar7 = 0;
  }
  else {
    lVar3 = (**(code **)(*(longlong *)pCVar2 + 0xf8))(pCVar2);
    if (lVar3 == 0) goto LAB_18000bd44;
    uVar7 = *(ulonglong *)(lVar3 + 0x40);
  }
  FUN_18000d4d0(param_1,(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8
               );
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind(param_2,'.');
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid(param_2,(int)local_res20);
  pcVar6 = (char *)(param_1 + 0xc);
  if (0xf < (ulonglong)param_1[0xf]) {
    pcVar6 = *(char **)pcVar6;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18,pcVar6);
  iVar1 = FUN_180033bd0();
  pcVar6 = ".apropz";
  if (iVar1 == 1) {
    pcVar6 = ".apwz";
  }
  iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                    (local_res20,pcVar6);
  if (iVar1 == 0) {
    pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                       (local_28,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                  *)param_2);
    uVar5 = FUN_18000b660(param_1,*(char **)param_2,
                          (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          &local_res18,
                          (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          &local_res8,pCVar4);
    if ((int)uVar5 == 0) goto LAB_18000be1c;
    pcVar6 = *(char **)param_2;
  }
  else {
    pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                       (local_28,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                  *)param_2);
    uVar5 = FUN_18000b660(param_1,(char *)0x0,
                          (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          &local_res18,
                          (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          &local_res8,pCVar4);
    if ((int)uVar5 == 0) goto LAB_18000be1c;
    pcVar6 = (char *)0x0;
  }
  FUN_180026600(pcVar6,local_res18,local_res8,uVar7);
LAB_18000be1c:
  pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
           CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                     (local_28,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                *)&local_res8);
  FUN_1800099b0(param_1,pCVar4);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_2);
  return;
}

/* RVA 0xbe70 */
uint FUN_18000be70(longlong param_1,char *param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  char *local_res20;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_18 [16];
  
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_18,param_2);
  uVar1 = FUN_18000dad0(param_1,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                 *)local_18,param_3,
                        (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                        &local_res20);
  if (*(int *)(local_res20 + -0x10) != 0) {
    iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20
                       ,"No message available");
    if (iVar2 != 0) {
      MMAfxMessageBox(local_res20,0x30,-1,0);
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_18);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
  return uVar1;
}

/* RVA 0xbf20 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_18000bf20(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,char *param_2,
             char *param_3)

{
  undefined1 auStackY_468 [32];
  char local_438 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_430;
  char local_428 [256];
  char local_328 [256];
  char local_228 [272];
  char local_118 [256];
  ulonglong local_18;
  
  local_18 = DAT_180052888 ^ (ulonglong)auStackY_468;
  local_430 = param_1;
  _splitpath(param_2,local_438,local_328,local_428,local_118);
  _makepath(local_228,local_438,local_328,local_428,param_3);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1,local_228);
  return param_1;
}

/* RVA 0xbfd0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18000bfd0(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  LPCSTR lpNewFileName;
  char *_OldFilename;
  char *pcVar3;
  undefined8 *puVar4;
  undefined1 auStack_158 [32];
  undefined8 local_138;
  undefined8 local_130;
  CHAR local_128 [259];
  undefined1 local_25;
  ulonglong local_18;
  
  local_18 = DAT_180052888 ^ (ulonglong)auStack_158;
  GetCurrentDirectoryA(0x104,local_128);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_130,local_128);
  iVar1 = FUN_180033bd0();
  pcVar3 = "\\$backup.bkp";
  if (iVar1 != 1) {
    pcVar3 = "\\$backup.aprbkp";
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_130,pcVar3);
  pcVar3 = (char *)HappName();
  if (pcVar3 == (char *)0x0) {
    local_128[0] = '\0';
  }
  else {
    strncpy(local_128,pcVar3,0x104);
    local_25 = 0;
  }
  HappUpdateMoniker(local_130);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_138);
  if (local_128[0] == '\0') {
    pcVar3 = (char *)(param_1 + 0x40);
    if (*(longlong *)(param_1 + 0x70) != 0) {
      pcVar3 = (char *)(param_1 + 0x60);
    }
    if (0xf < *(ulonglong *)(pcVar3 + 0x18)) {
      pcVar3 = *(char **)pcVar3;
    }
  }
  else {
    pcVar3 = local_128;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_138,pcVar3);
  HappUpdateMoniker(local_138);
  iVar1 = FUN_180033bd0();
  pcVar3 = "$backup.bkp";
  if (iVar1 != 1) {
    pcVar3 = "$backup.aprbkp";
  }
  iVar1 = HappWriteExport(0xb,pcVar3);
  if (iVar1 != -1) {
    puVar4 = (undefined8 *)(param_1 + 0x60);
    iVar1 = FUN_180033bd0();
    if (iVar1 == 1) {
      pcVar3 = (char *)GRemrbkp();
      _OldFilename = "$backup.bkp";
    }
    else {
      pcVar3 = (char *)GRemrprp();
      _OldFilename = "$backup.aprbkp";
    }
    rename(_OldFilename,pcVar3);
    if (0xf < *(ulonglong *)(param_1 + 0x78)) {
      puVar4 = (undefined8 *)*puVar4;
    }
    uVar2 = GRemrbkpfull();
    GRCreateEmergencyFiles(puVar4,uVar2);
    lpNewFileName = (LPCSTR)GRemrbka();
    MoveFileA("$backup.apmbd",lpNewFileName);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_138);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_130);
  return;
}

/* RVA 0xc180 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined4 FUN_18000c180(char *param_1)

{
  code *pcVar1;
  int iVar2;
  HRESULT HVar3;
  char *pcVar4;
  longlong lVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined4 uVar11;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pwcsName;
  LPCOLESTR szFilename;
  undefined8 uStackY_480;
  undefined1 auStackY_478 [32];
  int aiStack_450 [2];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_448 [8];
  CLSID local_440;
  longlong local_430;
  uchar local_428 [8];
  undefined1 local_418 [1008];
  ulonglong local_28;
  
  local_28 = DAT_180052888 ^ (ulonglong)local_448;
  uVar11 = 0xffffffff;
  uStackY_480 = 0x18000c1cc;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_448);
  uStackY_480 = 0x18000c1dc;
  pcVar4 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)local_448,0x100);
  uStackY_480 = 0x18000c1f2;
  _splitpath(param_1,(char *)0x0,(char *)0x0,(char *)0x0,pcVar4);
  uStackY_480 = 0x18000c1fe;
  ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)local_448,-1);
  uStackY_480 = 0x18000c203;
  iVar2 = FUN_180033bd0();
  pcVar4 = ".aprop";
  if (iVar2 == 1) {
    pcVar4 = ".apw";
  }
  uStackY_480 = 0x18000c222;
  iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                    (local_448,pcVar4);
  puVar10 = auStackY_478;
  if (iVar2 == 0) {
LAB_18000c228:
    uVar11 = 0;
  }
  else {
    uStackY_480 = 0x18000c240;
    iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                      (local_448,".bkp");
    if (iVar2 != 0) {
      uStackY_480 = 0x18000c259;
      iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                        (local_448,".aprbkp");
      if (iVar2 != 0) {
        uStackY_480 = 0x18000c272;
        iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                          (local_448,".apt");
        if (iVar2 != 0) {
          uStackY_480 = 0x18000c28b;
          iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                            (local_448,".aprt");
          if (iVar2 != 0) {
            uStackY_480 = 0x18000c2a4;
            iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                    CompareNoCase(local_448,".inp");
            if (iVar2 != 0) {
              uStackY_480 = 0x18000c2bd;
              iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                      CompareNoCase(local_448,".aprinp");
              if (iVar2 != 0) {
                uStackY_480 = 0x18000c2d6;
                iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                        CompareNoCase(local_448,".sum");
                if (iVar2 != 0) {
                  uStackY_480 = 0x18000c2ef;
                  iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                          CompareNoCase(local_448,".aprsum");
                  if (iVar2 != 0) {
                    uStackY_480 = 0x18000c308;
                    iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                            CompareNoCase(local_448,".apwz");
                    if (iVar2 != 0) {
                      uStackY_480 = 0x18000c321;
                      iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                              CompareNoCase(local_448,".apropz");
                      if (iVar2 != 0) {
                        uStackY_480 = 0x18000c33a;
                        iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                                CompareNoCase(local_448,".ikc");
                        puVar10 = auStackY_478;
                        if (iVar2 == 0) {
                          uVar11 = 6;
                          goto LAB_18000c710;
                        }
                        puVar10 = auStackY_478;
                        if (param_1 == (char *)0x0) {
LAB_18000c3ca:
                          pwcsName = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                      *)0x0;
                        }
                        else {
                          lVar5 = -1;
                          do {
                            lVar6 = lVar5;
                            lVar5 = lVar6 + 1;
                          } while (param_1[lVar5] != '\0');
                          iVar2 = (int)lVar6 + 2;
                          puVar10 = auStackY_478;
                          if (0x3fffffff < iVar2) goto LAB_18000c3ca;
                          lVar5 = (longlong)(int)lVar5 * 2;
                          uVar7 = lVar5 + 0x11;
                          if (uVar7 <= lVar5 + 2U) {
                            uVar7 = 0xffffffffffffff0;
                          }
                          uStackY_480 = 0x18000c396;
                          lVar5 = -(uVar7 & 0xfffffffffffffff0);
                          puVar10 = auStackY_478 + lVar5;
                          pwcsName = local_448 + lVar5;
                          if (pwcsName ==
                              (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0)
                          goto LAB_18000c3ca;
                          *(undefined2 *)pwcsName = 0;
                          *(int *)((longlong)aiStack_450 + lVar5) = iVar2;
                          *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                           (auStackY_478 + lVar5 + 0x20) = pwcsName;
                          *(undefined8 *)(auStackY_478 + lVar5 + -8) = 0x18000c3c2;
                          iVar2 = MultiByteToWideChar(0,0,param_1,-1,
                                                      *(LPWSTR *)(auStackY_478 + lVar5 + 0x20),
                                                      *(int *)((longlong)aiStack_450 + lVar5));
                          puVar10 = auStackY_478 + lVar5;
                          if (iVar2 == 0) {
                            pwcsName = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                        *)0x0;
                            puVar10 = auStackY_478 + lVar5;
                          }
                        }
                        *(undefined8 *)(puVar10 + -8) = 0x18000c3d8;
                        HVar3 = StgIsStorageFile((WCHAR *)pwcsName);
                        if (HVar3 != 0) goto LAB_18000c710;
                        pcVar1 = *(code **)(*DAT_180054050 + 0x138);
                        *(undefined8 *)(puVar10 + -8) = 0x18000c3f4;
                        iVar2 = (*pcVar1)(DAT_180054050,&local_430);
                        if (iVar2 != 0) {
                          *(undefined8 *)(puVar10 + -8) = 0x18000c415;
                          FUN_180001ce0(local_418,"Assert failed in file %s line %d",
                                        "G:\\Agent\\work\\2\\s\\src\\mm\\ApwnShellIP\\ApwnLWDocument.cpp"
                                        ,0x1ea);
                          *(undefined8 *)(puVar10 + -8) = 0x18000c428;
                          LogMessage(local_418,2,1);
                        }
                        puVar9 = puVar10;
                        if (param_1 == (char *)0x0) {
LAB_18000c498:
                          szFilename = (LPCOLESTR)0x0;
                          puVar10 = puVar9;
                        }
                        else {
                          lVar5 = -1;
                          do {
                            lVar6 = lVar5;
                            lVar5 = lVar6 + 1;
                          } while (param_1[lVar5] != '\0');
                          iVar2 = (int)lVar6 + 2;
                          if (0x3fffffff < iVar2) goto LAB_18000c498;
                          lVar5 = (longlong)(int)lVar5 * 2;
                          uVar7 = lVar5 + 0x11;
                          if (uVar7 <= lVar5 + 2U) {
                            uVar7 = 0xffffffffffffff0;
                          }
                          *(undefined8 *)(puVar10 + -8) = 0x18000c466;
                          lVar5 = -(uVar7 & 0xfffffffffffffff0);
                          puVar9 = puVar10 + lVar5;
                          puVar8 = puVar10 + lVar5;
                          szFilename = (LPCOLESTR)(puVar10 + lVar5 + 0x30);
                          if (szFilename == (LPCOLESTR)0x0) goto LAB_18000c498;
                          *szFilename = L'\0';
                          *(int *)(puVar10 + lVar5 + 0x28) = iVar2;
                          *(LPCOLESTR *)(puVar10 + lVar5 + 0x20) = szFilename;
                          *(undefined8 *)(puVar10 + lVar5 + -8) = 0x18000c490;
                          iVar2 = MultiByteToWideChar(0,0,param_1,-1,
                                                      *(LPWSTR *)(puVar10 + lVar5 + 0x20),
                                                      *(int *)(puVar10 + lVar5 + 0x28));
                          puVar10 = puVar10 + lVar5;
                          if (iVar2 == 0) {
                            szFilename = (LPCOLESTR)0x0;
                            puVar10 = puVar8;
                          }
                        }
                        *(undefined8 *)(puVar10 + -8) = 0x18000c4a8;
                        HVar3 = GetClassFile(szFilename,&local_440);
                        if (HVar3 != 0) goto LAB_18000c710;
                        if ((local_440._0_8_ != local_430) || (local_440.Data4 != local_428)) {
                          if (((((local_440._0_8_ == DAT_180041180) &&
                                (local_440.Data4 == DAT_180041188)) ||
                               ((local_440._0_8_ == DAT_1800411a0 &&
                                (local_440.Data4 == DAT_1800411a8)))) ||
                              (((local_440._0_8_ == DAT_1800411b0 &&
                                (local_440.Data4 == DAT_1800411b8)) ||
                               ((((local_440._0_8_ == DAT_1800411c0 &&
                                  (local_440.Data4 == DAT_1800411c8)) ||
                                 ((local_440._0_8_ == DAT_1800411d0 &&
                                  (local_440.Data4 == DAT_1800411d8)))) ||
                                ((local_440._0_8_ == DAT_1800411e0 &&
                                 (local_440.Data4 == DAT_1800411e8)))))))) ||
                             (((((local_440._0_8_ == DAT_1800411f0 &&
                                 (local_440.Data4 == DAT_1800411f8)) ||
                                (((local_440._0_8_ == DAT_180041200 &&
                                  (local_440.Data4 == DAT_180041208)) ||
                                 ((local_440._0_8_ == DAT_180041210 &&
                                  (local_440.Data4 == DAT_180041218)))))) ||
                               ((((local_440._0_8_ == DAT_180041220 &&
                                  (local_440.Data4 == DAT_180041228)) ||
                                 ((local_440._0_8_ == DAT_180041230 &&
                                  (local_440.Data4 == DAT_180041238)))) ||
                                ((((local_440._0_8_ == DAT_180041240 &&
                                   (local_440.Data4 == DAT_180041248)) ||
                                  ((local_440._0_8_ == DAT_180041250 &&
                                   (local_440.Data4 == DAT_180041258)))) ||
                                 ((local_440._0_8_ == DAT_180041260 &&
                                  (local_440.Data4 == DAT_180041268)))))))) ||
                              ((((local_440._0_8_ == DAT_180041270 &&
                                 (local_440.Data4 == DAT_180041278)) ||
                                (((((local_440._0_8_ == DAT_180041280 &&
                                    (local_440.Data4 == DAT_180041288)) ||
                                   ((local_440._0_8_ == DAT_180041290 &&
                                    (local_440.Data4 == DAT_180041298)))) ||
                                  (((local_440._0_8_ == DAT_1800412a0 &&
                                    (local_440.Data4 == DAT_1800412a8)) ||
                                   ((local_440._0_8_ == DAT_1800412b0 &&
                                    (local_440.Data4 == DAT_1800412b8)))))) ||
                                 (((((local_440._0_8_ == DAT_1800412c0 &&
                                     (local_440.Data4 == DAT_1800412c8)) ||
                                    ((local_440._0_8_ == DAT_1800412d0 &&
                                     (local_440.Data4 == DAT_1800412d8)))) ||
                                   ((local_440._0_8_ == DAT_1800412e0 &&
                                    (local_440.Data4 == DAT_1800412e8)))) ||
                                  ((local_440._0_8_ == DAT_1800412f0 &&
                                   (local_440.Data4 == DAT_1800412f8)))))))) ||
                               ((((local_440._0_8_ == DAT_180041300 &&
                                  (local_440.Data4 == DAT_180041308)) ||
                                 ((local_440._0_8_ == DAT_180041310 &&
                                  (local_440.Data4 == DAT_180041318)))) ||
                                ((local_440._0_8_ == DAT_180041320 &&
                                 (local_440.Data4 == DAT_180041328)))))))))) {
                            uVar11 = 5;
                          }
                          goto LAB_18000c710;
                        }
                        goto LAB_18000c228;
                      }
                    }
                    puVar10 = auStackY_478;
                    uVar11 = 8;
                    goto LAB_18000c710;
                  }
                }
                puVar10 = auStackY_478;
                uVar11 = 7;
                goto LAB_18000c710;
              }
            }
            puVar10 = auStackY_478;
            uVar11 = 3;
            goto LAB_18000c710;
          }
        }
        puVar10 = auStackY_478;
        uVar11 = 2;
        goto LAB_18000c710;
      }
    }
    puVar10 = auStackY_478;
    uVar11 = 1;
  }
LAB_18000c710:
  *(undefined8 *)(puVar10 + -8) = 0x18000c71a;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_448);
  *(undefined8 *)(puVar10 + -8) = 0x18000c72b;
  return uVar11;
}

/* RVA 0xc750 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_18000c750(void)

{
  int iVar1;
  HRESULT HVar2;
  char *pcVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  wchar_t *lpsz;
  undefined1 auStack_438 [32];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_418 [16];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_180052888 ^ (ulonglong)auStack_438;
  if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4)
       < DAT_180053590) && (FUN_180035090(&DAT_180053590), DAT_180053590 == -1)) {
    _DAT_180053580 = _DAT_180041fe0;
    uRam0000000180053588 = _UNK_180041fe8;
    _Init_thread_footer(&DAT_180053590);
  }
  iVar1 = FUN_180033bd0();
  if (iVar1 == 2) {
    pcVar3 = (char *)FUN_180001a20();
    this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
           CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_418,pcVar3);
    lpsz = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::AllocSysString(this);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_418);
    HVar2 = CLSIDFromString(lpsz,(LPCLSID)&DAT_180053580);
    SysFreeString(lpsz);
    if (HVar2 != 0) {
      FUN_180001ce0(local_408,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\ApwnShellIP\\ApwnLWDocument.cpp",0x171);
      LogMessage(local_408,2,1);
    }
  }
  return &DAT_180053580;
}

/* RVA 0xc8a0 */
int FUN_18000c8a0(longlong param_1,undefined8 *param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  longlong *local_res20;
  longlong *local_58;
  longlong *local_50;
  longlong *local_48;
  longlong *local_40;
  undefined8 local_38;
  undefined8 *local_30 [3];
  
  iVar4 = -0x7fffbffb;
  iVar3 = FUN_180033bd0();
  if (iVar3 != 1) {
    return -0x7fffbffb;
  }
  local_38 = 0;
  local_res20 = (longlong *)0x0;
  if (param_2 == (undefined8 *)0x0) {
    plVar1 = *(longlong **)(param_1 + 0x38);
    if (plVar1 == (longlong *)0x0) {
      return -0x7fffbffb;
    }
    (**(code **)(*plVar1 + 8))(plVar1);
    if (local_res20 == (longlong *)0x0) goto LAB_18000c931;
    lVar2 = *local_res20;
    local_res20 = plVar1;
    (**(code **)(lVar2 + 0x10))();
  }
  else {
    iVar3 = (**(code **)*param_2)(param_2,&DAT_1800413f0,&local_res20);
    if (iVar3 < 0) {
      return -0x7fffbffb;
    }
  }
  plVar1 = local_res20;
LAB_18000c931:
  local_res20 = plVar1;
  if (local_res20 != (longlong *)0x0) {
    local_58 = (longlong *)0x0;
    iVar4 = (**(code **)*local_res20)(local_res20,&DAT_180041340,&local_58);
    if (iVar4 < 0) {
      local_58 = (longlong *)0x0;
    }
    iVar4 = -0x7fffbffb;
    if (local_58 != (longlong *)0x0) {
      local_40 = (longlong *)0x0;
      iVar4 = (**(code **)(*local_58 + 0x20))(local_58,&DAT_180041938,&local_40);
      if (-1 < iVar4) {
        local_48 = (longlong *)0x0;
        iVar4 = (**(code **)(*local_40 + 0x38))(local_40,&local_48);
        if (-1 < iVar4) {
          iVar4 = (**(code **)(*local_48 + 0x18))(local_48,1,local_30);
          while (-1 < iVar4) {
            local_50 = (longlong *)0x0;
            if ((local_30[0] != (undefined8 *)0x0) &&
               (iVar3 = (**(code **)*local_30[0])(local_30[0],&DAT_180041938,&local_50), iVar3 < 0))
            {
              local_50 = (longlong *)0x0;
            }
            if (local_50 != (longlong *)0x0) {
              *param_3 = local_50;
              break;
            }
            iVar4 = (**(code **)(*local_48 + 0x18))(local_48,1,local_30);
            if (local_50 != (longlong *)0x0) {
              (**(code **)(*local_50 + 0x10))();
            }
          }
        }
        if (local_48 != (longlong *)0x0) {
          (**(code **)(*local_48 + 0x10))();
        }
      }
      if (local_40 != (longlong *)0x0) {
        (**(code **)(*local_40 + 0x10))();
      }
    }
    if (local_58 != (longlong *)0x0) {
      (**(code **)(*local_58 + 0x10))();
    }
    if (local_res20 != (longlong *)0x0) {
      (**(code **)(*local_res20 + 0x10))();
    }
  }
  return iVar4;
}

/* RVA 0xcaa0 */
ulonglong FUN_18000caa0(undefined8 param_1,int *param_2,
                       CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_3)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar4;
  undefined8 uVar5;
  ulonglong extraout_RAX;
  undefined8 extraout_RAX_00;
  char *local_res10;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_res18;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res20 [8];
  
  *param_2 = -1;
  iVar2 = *(int *)(*(longlong *)param_3 + -0x10);
  local_res18 = param_3;
  iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                    (param_3,'|');
  if (iVar1 == iVar2 + -2) {
    puVar3 = (undefined8 *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Right
                       (param_3,(int)local_res20);
    iVar2 = atoi((char *)*puVar3);
    *param_2 = iVar2;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20);
    pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                       (param_3,(int)local_res20);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_3,pCVar4);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20);
  }
  iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                    (param_3,'>');
  if (0 < iVar2) {
    pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                       (param_3,(int)local_res20);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_3,pCVar4);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20);
  }
  if (*param_2 == -1) {
    iVar2 = FUN_18000c180(*(char **)param_3);
    *param_2 = iVar2;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10);
  uVar5 = FUN_18000eab0(*(char **)param_3,*param_2,
                        (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                        &local_res10);
  if ((int)uVar5 != 0) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_3);
    return CONCAT71((int7)((ulonglong)extraout_RAX_00 >> 8),1);
  }
  if (*(int *)(local_res10 + -0x10) == 0) {
    local_res10 = (char *)GetSorResStringEx(0x572);
  }
  MMAfxMessageBox(local_res10,0x40,-1,0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_3);
  return extraout_RAX & 0xffffffffffffff00;
}

/* RVA 0xcc10 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18000cc10(void)

{
  int iVar1;
  HRESULT HVar2;
  LPWSTR lpWideCharStr;
  WCHAR local_88 [48];
  LPVOID local_28;
  CLSID local_20;
  ulonglong local_10;
  
  local_10 = DAT_180052888 ^ (ulonglong)&local_28;
  lpWideCharStr = local_88;
  if (lpWideCharStr == (LPWSTR)0x0) {
    lpWideCharStr = (LPCOLESTR)0x0;
  }
  else {
    local_88[0] = L'\0';
    iVar1 = MultiByteToWideChar(0,0,"AspenTech.AspenPlus.WpfMMDialog.MessageBox.410",-1,
                                lpWideCharStr,0x2f);
    if (iVar1 == 0) {
      lpWideCharStr = (LPCOLESTR)0x0;
    }
  }
  HVar2 = CLSIDFromProgID(lpWideCharStr,&local_20);
  if (-1 < HVar2) {
    local_28 = (LPVOID)0x0;
    HVar2 = CoCreateInstance(&local_20,(LPUNKNOWN)0x0,1,(IID *)&DAT_180042b28,&local_28);
    if (-1 < HVar2) {
      return local_28;
    }
  }
  return 0;
}

/* RVA 0xcce0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18000cce0(void)

{
  int iVar1;
  HRESULT HVar2;
  LPWSTR lpWideCharStr;
  WCHAR local_98 [56];
  LPVOID local_28;
  CLSID local_20;
  ulonglong local_10;
  
  local_10 = DAT_180052888 ^ (ulonglong)&local_28;
  lpWideCharStr = local_98;
  if (lpWideCharStr == (LPWSTR)0x0) {
    lpWideCharStr = (LPCOLESTR)0x0;
  }
  else {
    local_98[0] = L'\0';
    iVar1 = MultiByteToWideChar(0,0,"AspenTech.AspenPlus.WpfMMDialog.DialogDriver.410",-1,
                                lpWideCharStr,0x31);
    if (iVar1 == 0) {
      lpWideCharStr = (LPCOLESTR)0x0;
    }
  }
  HVar2 = CLSIDFromProgID(lpWideCharStr,&local_20);
  if (-1 < HVar2) {
    local_28 = (LPVOID)0x0;
    HVar2 = CoCreateInstance(&local_20,(LPUNKNOWN)0x0,1,(IID *)&DAT_180042b28,&local_28);
    if (-1 < HVar2) {
      return local_28;
    }
  }
  return 0;
}

/* RVA 0xcdb0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ILockBytesVtbl * FUN_18000cdb0(longlong param_1,BSTR param_2,char param_3)

{
  __uint64 _Var1;
  _func_5443 *p_Var2;
  UINT UVar3;
  uint uVar4;
  undefined8 ***pppuVar5;
  longlong *plVar6;
  ulonglong uVar7;
  longlong lVar8;
  longlong lVar9;
  _func_5441 **pp_Var10;
  undefined8 ****ppppuVar11;
  ILockBytesVtbl *pIVar12;
  ulonglong uVar13;
  ILockBytesVtbl *pIVar14;
  ulonglong uVar15;
  size_t sVar16;
  _func_5443 *p_Var17;
  _func_5443 *p_Var18;
  ILockBytesVtbl *pIVar19;
  ILockBytesVtbl *pIVar20;
  undefined8 ****ppppuVar21;
  undefined1 auStack_178 [32];
  char local_158;
  ILockBytesVtbl *local_150;
  ILockBytesVtbl *local_148;
  _func_5443 *local_140;
  longlong local_138 [2];
  undefined8 ****local_128;
  undefined8 uStack_120;
  _func_5443 *local_118;
  ulonglong local_110;
  undefined8 ***local_108;
  undefined8 ***pppuStack_100;
  _func_5443 *local_f8;
  ulonglong uStack_f0;
  longlong *local_e8;
  ILockBytesVtbl *local_e0;
  undefined1 *local_d8;
  undefined1 local_d0 [136];
  ulonglong local_48;
  
  local_48 = DAT_180052888 ^ (ulonglong)auStack_178;
  uStack_120 = 0;
  pIVar19 = (ILockBytesVtbl *)0x0;
  local_118 = (_func_5443 *)0x0;
  local_110 = 0xf;
  local_128 = (undefined8 ****)0x0;
  local_158 = param_3;
  if ((param_2 == (BSTR)0x0) || (UVar3 = SysStringLen(param_2), UVar3 == 0)) {
    uVar13 = local_110;
    if (3 < local_110) {
      ppppuVar21 = &local_128;
      if (0xf < local_110) {
        ppppuVar21 = local_128;
      }
      local_118 = (_func_5443 *)0x4;
      *(undefined4 *)ppppuVar21 = 0x746f6f52;
      *(undefined1 *)((longlong)ppppuVar21 + 4) = 0;
      goto LAB_18000cea2;
    }
    if (0x7fffffffffffffff - (local_110 >> 1) < local_110) {
      uVar15 = 0x7fffffffffffffff;
      uVar7 = 0x8000000000000027;
LAB_18000cece:
      pppuVar5 = operator_new(uVar7);
      if (pppuVar5 == (undefined8 ***)0x0) goto LAB_18000cf75;
      ppppuVar21 = (undefined8 ****)((longlong)pppuVar5 + 0x27U & 0xffffffffffffffe0);
      ppppuVar21[-1] = pppuVar5;
    }
    else {
      uVar7 = local_110 + (local_110 >> 1);
      uVar15 = 0xf;
      if (0xf < uVar7) {
        uVar15 = uVar7;
      }
      _Var1 = uVar15 + 1;
      if (0xfff < _Var1) {
        uVar7 = uVar15 + 0x28;
        if (uVar7 <= _Var1) {
                    /* WARNING: Subroutine does not return */
          FUN_18001d0c0();
        }
        goto LAB_18000cece;
      }
      if (_Var1 == 0) {
        ppppuVar21 = (undefined8 ****)0x0;
      }
      else {
        ppppuVar21 = operator_new(_Var1);
      }
    }
    local_118 = (_func_5443 *)0x4;
    *(undefined4 *)ppppuVar21 = 0x746f6f52;
    *(undefined1 *)((longlong)ppppuVar21 + 4) = 0;
    local_110 = uVar15;
    if (0xf < uVar13) {
      ppppuVar11 = local_128;
      if ((0xfff < uVar13 + 1) &&
         (ppppuVar11 = (undefined8 ****)local_128[-1],
         0x1f < (ulonglong)((longlong)local_128 + (-8 - (longlong)ppppuVar11)))) {
LAB_18000cf75:
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      FUN_180035134(ppppuVar11);
    }
    local_128 = ppppuVar21;
  }
  else {
    local_d8 = local_d0;
    FUN_18000d880(&local_d8,param_2,0);
    sVar16 = 0xffffffffffffffff;
    do {
      sVar16 = sVar16 + 1;
    } while (local_d8[sVar16] != '\0');
    FUN_18001d350((longlong *)&local_128,local_d8,sVar16);
    if (local_d8 == local_d0) {
LAB_18000cea2:
    }
    else {
      free(local_d8);
    }
  }
  uVar13 = local_110;
  p_Var2 = local_118;
  ppppuVar21 = local_128;
  if (local_158 != '\0') {
    FUN_1800093c0(param_1,param_2);
    local_150 = (ILockBytesVtbl *)0x0;
    local_148 = (ILockBytesVtbl *)0x0;
    CreateILockBytesOnHGlobal((HGLOBAL)0x0,1,(LPLOCKBYTES *)&local_150);
    if ((local_150 != (ILockBytesVtbl *)0x0) &&
       (StgCreateDocfileOnILockBytes((ILockBytes *)local_150,0x1012,0,(IStorage **)&local_148),
       local_148 != (ILockBytesVtbl *)0x0)) {
      local_140 = (_func_5443 *)0x0;
      ppppuVar21 = &local_128;
      if (0xf < local_110) {
        ppppuVar21 = local_128;
      }
      lVar8 = 0;
      do {
        lVar9 = lVar8 + 1;
        if (*(char *)((longlong)ppppuVar21 + lVar8) != (&DAT_180041bf8)[lVar8]) {
          ppppuVar21 = &local_128;
          if (0xf < local_110) {
            ppppuVar21 = local_128;
          }
          goto LAB_18000d035;
        }
        lVar8 = lVar9;
      } while (lVar9 != 5);
      ppppuVar21 = (undefined8 ****)0x0;
LAB_18000d035:
      plVar6 = (longlong *)HYGetModelByName(ppppuVar21);
      if (plVar6 != (longlong *)0x0) {
        (**(code **)(*plVar6 + 8))(plVar6);
        p_Var2 = local_118;
        pIVar19 = local_148;
        local_140 = (_func_5443 *)0x0;
        local_108 = (undefined8 ***)0x0;
        pppuStack_100 = (undefined8 ***)0x0;
        local_f8 = (_func_5443 *)0x0;
        uStack_f0 = 0;
        ppppuVar21 = &local_128;
        if (0xf < local_110) {
          ppppuVar21 = local_128;
        }
        if ((_func_5443 *)0x7fffffffffffffff < local_118) {
                    /* WARNING: Subroutine does not return */
          FUN_18001d1b0();
        }
        if (local_118 < (_func_5443 *)0x10) {
          local_f8 = local_118;
          uStack_f0 = 0xf;
          local_108 = *ppppuVar21;
          pppuStack_100 = ppppuVar21[1];
        }
        else {
          uVar7 = (ulonglong)local_118 | 0xf;
          uVar13 = 0x7fffffffffffffff;
          if ((uVar7 < 0x8000000000000000) && (uVar13 = uVar7, uVar7 < 0x16)) {
            uVar13 = 0x16;
          }
          local_108 = FUN_18001d210(&local_108,uVar13 + 1);
          local_f8 = p_Var2;
          uStack_f0 = uVar13;
          memcpy(local_108,ppppuVar21,(size_t)(p_Var2 + 1));
        }
        local_e0 = pIVar19;
        local_e8 = plVar6;
        FUN_180008240((longlong *)(param_1 + 0xe0),local_138,&local_108);
        if (0xf < uStack_f0) {
          pppuVar5 = local_108;
          if ((0xfff < uStack_f0 + 1) &&
             (pppuVar5 = (undefined8 ***)local_108[-1],
             0x1f < (ulonglong)((longlong)local_108 + (-8 - (longlong)pppuVar5)))) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
          FUN_180035134(pppuVar5);
        }
        pIVar19 = local_148;
      }
    }
    if (local_150 != (ILockBytesVtbl *)0x0) {
      (**(code **)(local_150->QueryInterface + 0x10))();
    }
    ppppuVar21 = local_128;
    goto LAB_18000d456;
  }
  local_150 = *(ILockBytesVtbl **)(param_1 + 0xe0);
  pIVar20 = (ILockBytesVtbl *)local_150->AddRef;
  local_148 = local_150;
  if (*(char *)((longlong)&pIVar20->ReadAt + 1) == '\0') {
    pIVar14 = pIVar20;
    do {
      ppppuVar11 = &local_128;
      if (0xf < uVar13) {
        ppppuVar11 = ppppuVar21;
      }
      pp_Var10 = &pIVar14->WriteAt;
      if ((_func_5444 *)0xf < pIVar14->LockRegion) {
        pp_Var10 = (_func_5441 **)pIVar14->WriteAt;
      }
      p_Var17 = pIVar14->SetSize;
      p_Var18 = p_Var17;
      if (p_Var2 < p_Var17) {
        p_Var18 = p_Var2;
      }
      uVar4 = memcmp(pp_Var10,ppppuVar11,(size_t)p_Var18);
      if (uVar4 == 0) {
        if (p_Var17 < p_Var2) {
          uVar4 = 0xffffffff;
        }
        else {
          uVar4 = (uint)(p_Var2 < p_Var17);
        }
      }
      if ((int)uVar4 < 0) {
        pIVar12 = (ILockBytesVtbl *)pIVar14->Release;
      }
      else {
        pIVar12 = (ILockBytesVtbl *)pIVar14->QueryInterface;
        local_150 = pIVar14;
      }
      pIVar14 = pIVar12;
    } while (*(code *)((longlong)&pIVar12->ReadAt + 1) == (code)0x0);
  }
  uVar13 = local_110;
  pIVar12 = local_148;
  pIVar14 = local_150;
  if (*(char *)((longlong)&local_150->ReadAt + 1) != '\0') goto LAB_18000d456;
  pp_Var10 = &local_150->WriteAt;
  if ((_func_5444 *)0xf < local_150->LockRegion) {
    pp_Var10 = (_func_5441 **)local_150->WriteAt;
  }
  ppppuVar11 = &local_128;
  if (0xf < local_110) {
    ppppuVar11 = ppppuVar21;
  }
  local_140 = local_150->SetSize;
  p_Var17 = p_Var2;
  if (local_140 < p_Var2) {
    p_Var17 = local_140;
  }
  uVar4 = memcmp(ppppuVar11,pp_Var10,(size_t)p_Var17);
  uVar7 = local_110;
  if (uVar4 == 0) {
    if (p_Var2 < local_140) {
      uVar4 = 0xffffffff;
    }
    else {
      uVar4 = (uint)(local_140 < p_Var2);
    }
  }
  if (((int)uVar4 < 0) || (pIVar14 == pIVar12)) goto LAB_18000d456;
  local_150 = pIVar12;
  if (*(char *)((longlong)&pIVar20->ReadAt + 1) == (char)-(char)((int)uVar4 >> 0x1f)) {
    pIVar14 = pIVar20;
    do {
      ppppuVar11 = &local_128;
      if (0xf < uVar7) {
        ppppuVar11 = ppppuVar21;
      }
      pp_Var10 = &pIVar14->WriteAt;
      if ((_func_5444 *)0xf < pIVar14->LockRegion) {
        pp_Var10 = (_func_5441 **)pIVar14->WriteAt;
      }
      p_Var17 = pIVar14->SetSize;
      p_Var18 = p_Var17;
      if (p_Var2 < p_Var17) {
        p_Var18 = p_Var2;
      }
      uVar4 = memcmp(pp_Var10,ppppuVar11,(size_t)p_Var18);
      if (uVar4 == 0) {
        if (p_Var17 < p_Var2) {
          uVar4 = 0xffffffff;
        }
        else {
          uVar4 = (uint)(p_Var2 < p_Var17);
        }
      }
      if ((int)uVar4 < 0) {
        pIVar12 = (ILockBytesVtbl *)pIVar14->Release;
      }
      else {
        pIVar12 = (ILockBytesVtbl *)pIVar14->QueryInterface;
        local_150 = pIVar14;
      }
      pIVar14 = pIVar12;
    } while (*(code *)((longlong)&pIVar12->ReadAt + 1) == (code)0x0);
    pIVar12 = local_148;
    uVar13 = local_110;
  }
  pIVar14 = local_150;
  if (*(char *)((longlong)&local_150->ReadAt + 1) == '\0') {
    pp_Var10 = &local_150->WriteAt;
    if ((_func_5444 *)0xf < local_150->LockRegion) {
      pp_Var10 = (_func_5441 **)local_150->WriteAt;
    }
    ppppuVar11 = &local_128;
    if (0xf < uVar13) {
      ppppuVar11 = ppppuVar21;
    }
    p_Var17 = local_150->SetSize;
    p_Var18 = p_Var2;
    if (p_Var17 < p_Var2) {
      p_Var18 = p_Var17;
    }
    uVar4 = memcmp(ppppuVar11,pp_Var10,(size_t)p_Var18);
    if (uVar4 == 0) {
      if (p_Var2 < p_Var17) {
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = (uint)(p_Var17 < p_Var2);
      }
    }
    if ((int)uVar4 < 0) goto LAB_18000d36a;
  }
  else {
LAB_18000d36a:
    pIVar14 = pIVar12;
  }
  uVar13 = local_110;
  if (pIVar14->Stat == (_func_5446 *)0x0) goto LAB_18000d456;
  pIVar19 = pIVar12;
  if (*(char *)((longlong)&pIVar20->ReadAt + 1) == '\0') {
    do {
      pIVar19 = pIVar20;
      ppppuVar11 = &local_128;
      if (0xf < uVar13) {
        ppppuVar11 = ppppuVar21;
      }
      pp_Var10 = &pIVar19->WriteAt;
      if ((_func_5444 *)0xf < pIVar19->LockRegion) {
        pp_Var10 = (_func_5441 **)pIVar19->WriteAt;
      }
      p_Var17 = pIVar19->SetSize;
      p_Var18 = p_Var17;
      if (p_Var2 < p_Var17) {
        p_Var18 = p_Var2;
      }
      uVar4 = memcmp(pp_Var10,ppppuVar11,(size_t)p_Var18);
      if (uVar4 == 0) {
        if (p_Var17 < p_Var2) {
          uVar4 = 0xffffffff;
        }
        else {
          uVar4 = (uint)(p_Var2 < p_Var17);
        }
      }
      if ((int)uVar4 < 0) {
        pIVar20 = (ILockBytesVtbl *)pIVar19->Release;
        pIVar19 = pIVar12;
      }
      else {
        pIVar20 = (ILockBytesVtbl *)pIVar19->QueryInterface;
      }
      pIVar12 = pIVar19;
    } while (*(code *)((longlong)&pIVar20->ReadAt + 1) == (code)0x0);
    pIVar12 = local_148;
  }
  if (*(char *)((longlong)&pIVar19->ReadAt + 1) == '\0') {
    pp_Var10 = &pIVar19->WriteAt;
    if ((_func_5444 *)0xf < pIVar19->LockRegion) {
      pp_Var10 = (_func_5441 **)pIVar19->WriteAt;
    }
    ppppuVar11 = &local_128;
    if (0xf < local_110) {
      ppppuVar11 = ppppuVar21;
    }
    p_Var17 = pIVar19->SetSize;
    p_Var18 = p_Var2;
    if (p_Var17 < p_Var2) {
      p_Var18 = p_Var17;
    }
    uVar4 = memcmp(ppppuVar11,pp_Var10,(size_t)p_Var18);
    if (uVar4 == 0) {
      if (p_Var2 < p_Var17) {
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = (uint)(p_Var17 < p_Var2);
      }
    }
    if ((int)uVar4 < 0) goto LAB_18000d44e;
  }
  else {
LAB_18000d44e:
    pIVar19 = pIVar12;
  }
  pIVar19 = (ILockBytesVtbl *)pIVar19->Stat;
LAB_18000d456:
  if (0xf < local_110) {
    ppppuVar11 = ppppuVar21;
    if ((0xfff < local_110 + 1) &&
       (ppppuVar11 = (undefined8 ****)ppppuVar21[-1],
       0x1f < (ulonglong)((longlong)ppppuVar21 + (-8 - (longlong)ppppuVar11)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(ppppuVar11);
  }
  return pIVar19;
}

/* RVA 0xd4d0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_18000d4d0(undefined8 param_1,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2)

{
  int iVar1;
  char *lpTempFileName;
  undefined1 auStack_158 [32];
  undefined4 local_138;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_130;
  CHAR local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_180052888 ^ (ulonglong)auStack_158;
  local_138 = 1;
  local_130 = param_2;
  GetCurrentDirectoryA(0x104,local_128);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_2);
  local_138 = 1;
  iVar1 = _access(local_128,2);
  if (iVar1 == 0) {
    lpTempFileName =
         ATL::CSimpleStringT<char,1>::GetBufferSetLength((CSimpleStringT<char,1> *)param_2,0x104);
    GetTempFileNameA(local_128,"_",0,lpTempFileName);
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)param_2,-1);
  }
  if (*(int *)(*(longlong *)param_2 + -0x10) == 0) {
    MMAfxMessageBox("Unable to create new file in this directory\n",0x40,-1,0);
  }
  return param_2;
}

/* RVA 0xd660 */
void FUN_18000d660(undefined8 *param_1,LPCSTR param_2,UINT param_3)

{
  LPWSTR pWVar1;
  LPWSTR pWVar2;
  int iVar3;
  DWORD DVar4;
  LPWSTR pWVar5;
  int iVar6;
  longlong lVar7;
  bool bVar8;
  
  if (param_2 == (LPCSTR)0x0) {
    *param_1 = 0;
    return;
  }
  lVar7 = -1;
  do {
    lVar7 = lVar7 + 1;
  } while (param_2[lVar7] != '\0');
  iVar6 = (int)lVar7 + 1;
  pWVar1 = (LPWSTR)(param_1 + 1);
  if (((param_1 == (undefined8 *)0x0) || (iVar6 < 0)) || (pWVar1 == (LPWSTR)0x0)) {
                    /* WARNING: Subroutine does not return */
    FUN_1800018d0(-0x7ff8ffa9);
  }
  pWVar2 = (LPWSTR)*param_1;
  pWVar5 = pWVar1;
  if (pWVar2 == pWVar1) {
    if (iVar6 < 0x81) {
      *param_1 = pWVar1;
    }
    else {
      pWVar5 = calloc((longlong)iVar6,2);
      *param_1 = pWVar5;
      if (pWVar5 == (LPWSTR)0x0) goto LAB_18000d842;
    }
  }
  else {
    if (iVar6 < 0x81) {
      free(pWVar2);
    }
    else {
      pWVar5 = _recalloc(pWVar2,(longlong)iVar6,2);
      if (pWVar5 == (LPWSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_1800018d0(-0x7ff8fff2);
      }
    }
    *param_1 = pWVar5;
  }
  iVar3 = MultiByteToWideChar(param_3,0,param_2,iVar6,pWVar5,iVar6);
  bVar8 = iVar3 == 0;
  if ((iVar3 == 0) && (DVar4 = GetLastError(), DVar4 == 0x7a)) {
    iVar3 = MultiByteToWideChar(param_3,0,param_2,iVar6,(LPWSTR)0x0,0);
    if (iVar3 < 0) {
                    /* WARNING: Subroutine does not return */
      FUN_1800018d0(-0x7ff8ffa9);
    }
    pWVar2 = (LPWSTR)*param_1;
    pWVar5 = pWVar1;
    if (pWVar2 == pWVar1) {
      if (iVar3 < 0x81) {
        *param_1 = pWVar1;
      }
      else {
        pWVar5 = calloc((longlong)iVar3,2);
        *param_1 = pWVar5;
        if (pWVar5 == (LPWSTR)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_1800018d0(-0x7ff8fff2);
        }
      }
    }
    else {
      if (iVar3 < 0x81) {
        free(pWVar2);
      }
      else {
        pWVar5 = _recalloc(pWVar2,(longlong)iVar3,2);
        if (pWVar5 == (LPWSTR)0x0) {
LAB_18000d842:
                    /* WARNING: Subroutine does not return */
          FUN_1800018d0(-0x7ff8fff2);
        }
      }
      *param_1 = pWVar5;
    }
    iVar6 = MultiByteToWideChar(param_3,0,param_2,iVar6,pWVar5,iVar3);
    bVar8 = iVar6 == 0;
  }
  if (bVar8) {
    FUN_180006e80((void *)*param_1,pWVar1);
                    /* WARNING: Subroutine does not return */
    FUN_180009340();
  }
  return;
}

/* RVA 0xd880 */
void FUN_18000d880(undefined8 *param_1,LPCWSTR param_2,UINT param_3)

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
    if (iVar3 < 0x81) {
      *param_1 = pCVar1;
    }
    else {
      pCVar5 = calloc((longlong)iVar3,1);
      *param_1 = pCVar5;
      if (pCVar5 == (LPSTR)0x0) goto LAB_18000da98;
    }
  }
  else {
    if (iVar3 < 0x81) {
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
      if (iVar3 < 0x81) {
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
      if (iVar3 < 0x81) {
        free(pCVar2);
      }
      else {
        pCVar5 = _recalloc(pCVar2,(longlong)iVar3,1);
        if (pCVar5 == (LPSTR)0x0) {
LAB_18000da98:
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

/* RVA 0xdad0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_18000dad0(longlong param_1,
                  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *param_2
                  ,undefined4 param_3,
                  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_4)

{
  int iVar1;
  int iVar2;
  HRESULT HVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar9;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar10;
  undefined4 *puVar11;
  undefined8 *puVar12;
  AFX_MODULE_STATE *pAVar13;
  longlong *plVar14;
  undefined8 uVar15;
  uint uVar16;
  char *pcVar17;
  char *pcVar18;
  undefined1 auStackY_5f8 [32];
  BSTR local_5c8;
  char *local_5c0;
  longlong *local_5b8;
  IErrorInfo *local_5b0;
  char *local_5a8 [2];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_598 [8];
  longlong local_590;
  longlong *local_588;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_580 [8];
  tagVARIANT local_578;
  VARIANTARG local_560;
  VARIANTARG local_548;
  _union_2707 local_530;
  undefined8 local_518;
  _union_1719 _Stack_510;
  undefined8 local_508;
  char *local_4f8;
  char local_4f0 [136];
  char local_468 [256];
  char local_368 [256];
  char local_268 [272];
  char local_158 [256];
  ulonglong local_58;
  
  local_58 = DAT_180052888 ^ (ulonglong)auStackY_5f8;
  local_5b8 = (longlong *)CONCAT44(local_5b8._4_4_,param_3);
  uVar4 = 0;
  uVar6 = 1;
  uVar7 = 1;
  pcVar8 = (char *)GetGlobalPointer("ExportHierarchyPath");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0xf0),
             pcVar8);
  pcVar8 = "";
  iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                     (param_1 + 0xf0),"TOPHIERARCHY");
  if (iVar1 != 0) {
    pcVar8 = *(char **)(param_1 + 0xf0);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c0,param_2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_590,"");
  iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,'.');
  if (iVar1 == *(int *)(*(longlong *)param_2 + -0x10) + -1) {
    pCVar9 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                       ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
                        (int)&local_5c8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,pCVar9);
LAB_18000dbe4:
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
  }
  else {
    iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,'\\'
                      );
    if (iVar2 < iVar1) {
      pCVar9 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Right
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
                          (int)&local_5c8);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_590,pCVar9)
      ;
      goto LAB_18000dbe4;
    }
  }
  if ((*(int *)(*(longlong *)param_2 + -0x10) != 0) &&
     (iVar1 = GRchkmmdir(*(longlong *)param_2,2), iVar1 != 0)) goto LAB_18000ea09;
  iVar2 = MMGetSuppress();
  iVar1 = (int)local_5b8;
  iVar2 = GRchkhie((ulonglong)local_5b8 & 0xffffffff,iVar2 == 0);
  if (iVar2 != 0) goto LAB_18000ea09;
  local_588 = (longlong *)HappGetTree();
  pCVar10 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8,
                       "Data\\Setup\\Main\\Input\\RUN_CLASS");
  local_5b0 = (IErrorInfo *)FUN_180021b30((longlong *)&local_588,pCVar10);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
  (**(code **)(*local_588 + 0x10))();
  AfxVariantInit(&local_578);
  VariantClear(&local_578);
  if (local_5b0 != (IErrorInfo *)0x0) {
    VariantInit((VARIANTARG *)&local_530.n2);
    VariantInit(&local_560);
    local_518 = local_530._0_8_;
    _Stack_510.s2 = (_struct_1720)local_530.decVal.u2;
    local_508 = local_530._16_8_;
    HVar3 = (*local_5b0->lpVtbl[2].GetGUID)(local_5b0,(GUID *)0x0);
    if (-1 < HVar3) {
      COleVariant::operator=((COleVariant *)&local_578,&local_560);
      VariantClear(&local_560);
    }
  }
  COleVariant::COleVariant((COleVariant *)&local_548,"PROP",8);
  local_4f8 = local_4f0;
  FUN_18000d880(&local_4f8,(LPCWSTR)local_578.n1.decVal.u2,0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_580,local_4f8);
  if (local_4f8 != local_4f0) {
    free(local_4f8);
  }
  pcVar17 = local_5c0;
  uVar4 = 0;
  switch(iVar1) {
  case 0:
    uVar4 = GRinqusrexp();
    if (uVar4 != 0) {
      pAVar13 = AfxGetModuleState();
      CCmdTarget::BeginWaitCursor(*(CCmdTarget **)(pAVar13 + 8));
      uVar5 = MMGetVisibleSuppress();
      MMSetVisibleSuppress(0);
      uVar16 = 0;
      uVar7 = uVar6;
      do {
        if ((uVar4 >> (uVar16 & 0x1f) & 1) != 0) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_5a8);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_5a8,
                     (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     &local_5c0);
          uVar6 = FUN_18000dad0(param_1,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                         *)local_5a8,uVar16,
                                (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                &local_5c8);
          uVar7 = uVar7 & uVar6;
          if (uVar6 == 0) {
            if (*(int *)(*(longlong *)param_4 + -0x10) == 0) {
              pcVar8 = (char *)GetSorResStringEx(0x579);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                        (param_4,pcVar8);
            }
            _splitpath(local_5a8[0],(char *)&local_5b8,local_158,local_368,local_468);
            _makepath(local_268,(char *)0x0,(char *)0x0,local_368,local_468);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_598,local_268);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                      (param_4,(CSimpleStringT<char,1> *)local_598);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                      (param_4,"\n");
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_598);
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_5a8);
        }
        uVar16 = uVar16 + 1;
      } while (uVar16 < 0x1f);
      MMSetVisibleSuppress(uVar5);
      FUN_180008ee0();
    }
    goto LAB_18000e951;
  case 1:
    iVar1 = FUN_180033bd0();
    pcVar17 = ".aprbkp";
    if (iVar1 == 1) {
      pcVar17 = ".bkp";
    }
    pCVar10 = FUN_18000bf20((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_5c8,local_5c0,pcVar17);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar10)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
    HappUpdateMoniker(*(undefined8 *)param_2);
    if (*(longlong *)(param_1 + 0x70) == 0) {
      plVar14 = (longlong *)(param_1 + 0x40);
      if (0xf < *(ulonglong *)(param_1 + 0x58)) {
        plVar14 = (longlong *)*plVar14;
      }
    }
    else {
      plVar14 = (longlong *)(param_1 + 0x60);
      if (0xf < *(ulonglong *)(param_1 + 0x78)) {
        plVar14 = (longlong *)*plVar14;
      }
    }
    puVar12 = (undefined8 *)(param_1 + 0x60);
    HappUpdateMoniker(plVar14);
    uVar7 = HappWriteExportHier(1,*(undefined8 *)param_2,pcVar8);
    if (*pcVar8 == '\0') {
      if (0xf < *(ulonglong *)(param_1 + 0x78)) {
        puVar12 = (undefined8 *)*puVar12;
      }
      GRAuxFileOnSaveAs(puVar12,*(undefined8 *)param_2);
    }
    goto LAB_18000e951;
  case 2:
    iVar1 = FUN_180033bd0();
    pcVar17 = ".aprrep";
    if (iVar1 == 1) {
      pcVar17 = ".rep";
    }
    pCVar10 = FUN_18000bf20((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_5c8,local_5c0,pcVar17);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar10)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
    uVar15 = 3;
    break;
  case 3:
    iVar1 = FUN_180033bd0();
    pcVar17 = ".aprsum";
    if (iVar1 == 1) {
      pcVar17 = ".sum";
    }
    pCVar10 = FUN_18000bf20((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_5c8,local_5c0,pcVar17);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar10)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
    uVar15 = 7;
    break;
  case 4:
    iVar1 = FUN_180033bd0();
    pcVar17 = ".aprinp";
    if (iVar1 == 1) {
      pcVar17 = ".inp";
    }
    pCVar10 = FUN_18000bf20((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_5c8,local_5c0,pcVar17);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar10)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
    uVar15 = 2;
    break;
  case 5:
    iVar1 = FUN_180033bd0();
    pcVar18 = ".aprinp";
    if (iVar1 == 1) {
      pcVar18 = ".inp";
    }
    pCVar10 = FUN_18000bf20((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_5c8,pcVar17,pcVar18);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar10)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
    HappWriteExportHier(2,*(undefined8 *)param_2,pcVar8);
    pCVar10 = FUN_18000bf20((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_5c8,local_5c0,".apmbd");
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar10)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
    uVar15 = 0xe;
    break;
  case 6:
    pCVar10 = FUN_18000bf20((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_5c8,local_5c0,".cpm");
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar10)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
    uVar15 = 5;
    break;
  case 7:
    iVar1 = FUN_180033bd0();
    pcVar18 = ".aprinp";
    if (iVar1 == 1) {
      pcVar18 = ".inp";
    }
    pCVar10 = FUN_18000bf20((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_5c8,pcVar17,pcVar18);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar10)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
    uVar7 = HappWriteExportHier(2,*(undefined8 *)param_2,pcVar8);
    iVar1 = FUN_180033bd0();
    pcVar17 = ".aprrep";
    if (iVar1 == 1) {
      pcVar17 = ".rep";
    }
    pCVar10 = FUN_18000bf20((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_5c8,local_5c0,pcVar17);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar10)
    ;
    goto LAB_18000e27f;
  case 8:
    iVar1 = FUN_180033bd0();
    pcVar18 = ".aprsum";
    if (iVar1 == 1) {
      pcVar18 = ".sum";
    }
    pCVar10 = FUN_18000bf20((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_5c8,pcVar17,pcVar18);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar10)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
    uVar7 = HappWriteExportHier(7,*(undefined8 *)param_2,pcVar8);
    iVar1 = FUN_180033bd0();
    pcVar17 = ".aprrep";
    if (iVar1 == 1) {
      pcVar17 = ".rep";
    }
    pCVar10 = FUN_18000bf20((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_5c8,local_5c0,pcVar17);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar10)
    ;
LAB_18000e27f:
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
    uVar4 = HappWriteExportHier(3,*(undefined8 *)param_2,pcVar8);
    uVar7 = uVar7 & uVar4;
    goto LAB_18000e951;
  case 9:
  case 10:
    puVar11 = (undefined4 *)GetGlobalPointer("DynamicsExportMode");
    if (puVar11 == (undefined4 *)0x0) {
      puVar11 = operator_new__(4);
    }
    *puVar11 = 1;
    SetGlobalPointer("DynamicsExportMode",puVar11,0);
    if (*(int *)(local_590 + -0x10) == 0) {
      uVar7 = HappWriteExportHier((iVar1 != 9) + '\t',*(undefined8 *)param_2,pcVar8);
    }
    else {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,'.');
      puVar12 = (undefined8 *)
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
                           (int)&local_5c8);
      uVar7 = HappWriteExportHier((iVar1 != 9) + '\t',*puVar12,pcVar8);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
    }
    pCVar10 = FUN_18000bf20((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_5c8,local_5c0,".dynf");
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar10)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
    *puVar11 = 0;
    SetGlobalPointer("DynamicsExportMode",puVar11,0);
    goto LAB_18000e951;
  case 0xb:
    pCVar10 = FUN_18000bf20((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_5c8,local_5c0,".dxf");
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar10)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
    FUN_180033bd0();
    goto LAB_18000e951;
  case 0xc:
    pCVar10 = FUN_18000bf20((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_5c8,local_5c0,".xml");
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar10)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
    uVar15 = 0xc;
    break;
  case 0xd:
    iVar1 = FUN_180033bd0();
    if (iVar1 == 1) {
      pCVar10 = FUN_18000bf20((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                              &local_5c8,local_5c0,".his");
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 pCVar10);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
      uVar15 = 0xd;
    }
    else {
      pCVar10 = FUN_18000bf20((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                              &local_5c8,local_5c0,".aprhis");
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 pCVar10);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
      uVar15 = 0xd;
    }
    break;
  case 0xe:
    uVar7 = 0;
    pCVar10 = FUN_18000bf20((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_5c8,local_5c0,".pfs");
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar10)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
    FUN_180033bd0();
    goto LAB_18000e951;
  case 0xf:
    iVar1 = FUN_180033bd0();
    pcVar8 = ".aprpdf";
    if (iVar1 == 1) {
      pcVar8 = ".appdf";
    }
    pCVar10 = FUN_18000bf20((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_5c8,local_5c0,pcVar8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar10)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
    puVar12 = (undefined8 *)HappGetHapp();
    local_5b8 = (longlong *)0x0;
    if ((puVar12 != (undefined8 *)0x0) &&
       (iVar1 = (**(code **)*puVar12)(puVar12,&DAT_180041998,&local_5b8), iVar1 < 0)) {
      local_5b8 = (longlong *)0x0;
    }
    plVar14 = local_5b8;
    uVar7 = uVar6;
    if (local_5b8 != (longlong *)0x0) {
      puVar12 = FUN_180008700(&local_5c8,*(LPCSTR *)param_2);
      iVar1 = (**(code **)(*plVar14 + 0x38))(plVar14,*puVar12,0);
      SysFreeString(local_5c8);
      uVar7 = (uint)(iVar1 == 0);
    }
    if (local_5b8 != (longlong *)0x0) {
      (**(code **)(*local_5b8 + 0x10))(local_5b8);
    }
    goto LAB_18000e951;
  case 0x10:
    pCVar10 = FUN_18000bf20((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_5c8,local_5c0,".atslv");
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar10)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
    uVar7 = SimExportEOReport(*(undefined8 *)param_2,1);
    goto LAB_18000e951;
  case 0x11:
    pCVar10 = FUN_18000bf20((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_5c8,local_5c0,".atact");
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar10)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
    uVar7 = SimExportEOReport(*(undefined8 *)param_2,3);
    goto LAB_18000e951;
  case 0x12:
    iVar1 = FUN_180033bd0();
    pcVar18 = ".aprinp";
    if (iVar1 == 1) {
      pcVar18 = ".inp";
    }
    pCVar10 = FUN_18000bf20((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_5c8,pcVar17,pcVar18);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar10)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
    HappWriteExportHier(4,*(undefined8 *)param_2,pcVar8);
    pCVar10 = FUN_18000bf20((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_5c8,local_5c0,".apmbd");
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar10)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
    uVar15 = 0xe;
    break;
  case 0x13:
    iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                      (local_580,"Flowsheet");
    if (iVar1 == 0) {
      FUN_1800117d0((longlong *)&local_5b0,(COleVariant *)&local_548);
    }
    SetExportToApropFlag(1);
    pCVar10 = FUN_18000bf20((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_5c8,local_5c0,".aprbkp");
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar10)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
    HappUpdateMoniker(*(undefined8 *)param_2);
    puVar12 = (undefined8 *)(param_1 + 0x40);
    if (*(longlong *)(param_1 + 0x70) != 0) {
      puVar12 = (undefined8 *)(param_1 + 0x60);
    }
    if (0xf < (ulonglong)puVar12[3]) {
      puVar12 = (undefined8 *)*puVar12;
    }
    HappUpdateMoniker(puVar12);
    uVar7 = HappWriteExportHier(1,*(undefined8 *)param_2,pcVar8);
    FUN_1800117d0((longlong *)&local_5b0,(COleVariant *)&local_578);
    goto LAB_18000e951;
  case 0x14:
    FUN_1800117d0((longlong *)&local_5b0,(COleVariant *)&local_548);
    SetExportToApropFlag(1);
    pCVar10 = FUN_18000bf20((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_5c8,local_5c0,".aprpdf");
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar10)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
    puVar12 = (undefined8 *)HappGetHapp();
    local_5b8 = (longlong *)0x0;
    if ((puVar12 != (undefined8 *)0x0) &&
       (iVar1 = (**(code **)*puVar12)(puVar12,&DAT_180041998,&local_5b8), iVar1 < 0)) {
      local_5b8 = (longlong *)0x0;
    }
    plVar14 = local_5b8;
    uVar7 = uVar6;
    if (local_5b8 != (longlong *)0x0) {
      puVar12 = FUN_180008700(&local_5c8,*(LPCSTR *)param_2);
      iVar1 = (**(code **)(*plVar14 + 0x38))(plVar14,*puVar12,0);
      SysFreeString(local_5c8);
      uVar7 = (uint)(iVar1 == 0);
    }
    if (local_5b8 != (longlong *)0x0) {
      (**(code **)(*local_5b8 + 0x10))(local_5b8);
    }
    FUN_1800117d0((longlong *)&local_5b0,(COleVariant *)&local_578);
    goto LAB_18000e951;
  case 0x15:
    SetExportToApropFlag(1);
    pCVar10 = FUN_18000bf20((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_5c8,local_5c0,".aprrep");
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar10)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
    uVar15 = 3;
    break;
  case 0x16:
    pCVar10 = FUN_18000bf20((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_5c8,local_5c0,".odi");
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar10)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
    uVar15 = 0x10;
    break;
  case 0x17:
    iVar1 = FUN_180033bd0();
    pcVar17 = ".aprinp";
    if (iVar1 == 1) {
      pcVar17 = ".inp";
    }
    pCVar10 = FUN_18000bf20((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_5c8,local_5c0,pcVar17);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar10)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
    uVar15 = 0x11;
    break;
  case 0x18:
    iVar1 = FUN_180033bd0();
    pcVar18 = ".aprsum";
    if (iVar1 == 1) {
      pcVar18 = ".sum";
    }
    pCVar10 = FUN_18000bf20((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_5c8,pcVar17,pcVar18);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar10)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
    HappWriteExportHier(7,*(undefined8 *)param_2,pcVar8);
    pCVar10 = FUN_18000bf20(local_598,local_5c0,".ads");
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar10)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_598);
    uVar15 = 0x12;
    break;
  case 0x19:
    pCVar10 = FUN_18000bf20((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_5c8,local_5c0,".aprinp");
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar10)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c8);
    uVar15 = 2;
    break;
  default:
    goto switchD_18000dd54_default;
  }
  uVar7 = HappWriteExportHier(uVar15,*(undefined8 *)param_2,pcVar8);
LAB_18000e951:
  if (local_5b0 != (IErrorInfo *)0x0) {
    (*local_5b0->lpVtbl->Release)(local_5b0);
  }
  if (uVar7 == 0) {
    local_5b0 = (IErrorInfo *)0x0;
    HVar3 = GetErrorInfo(0,&local_5b0);
    if ((HVar3 == 0) && (local_5b0 != (IErrorInfo *)0x0)) {
      HVar3 = (*local_5b0->lpVtbl->GetDescription)(local_5b0,&local_5c8);
      if (-1 < HVar3) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_5a8,
                   local_5c8);
        iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           local_5a8,"No message available");
        if (iVar1 != 0) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    (param_4,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                              *)local_5a8);
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_5a8);
      }
      (*local_5b0->lpVtbl->Release)(local_5b0);
    }
  }
  uVar4 = uVar7;
switchD_18000dd54_default:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_580);
  VariantClear(&local_548);
  VariantClear(&local_578);
LAB_18000ea09:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_590);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5c0);
  return uVar4;
}

/* RVA 0xeab0 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_18000eab0(char *param_1,int param_2,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_3)

{
  code *pcVar1;
  int iVar2;
  HRESULT HVar3;
  longlong lVar4;
  char *pcVar5;
  char *pcVar6;
  longlong lVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  LPCOLESTR pOVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  WCHAR *pWVar15;
  LPCOLESTR pOVar16;
  undefined8 uStack_500;
  undefined1 auStack_4f8 [32];
  undefined8 uStack_4d8;
  int aiStack_4d0 [6];
  uint local_4b8;
  uint uStack_4b4;
  char *local_4b0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_4a8 [8];
  int local_4a0 [2];
  LPCWSTR local_498;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_490 [8];
  CLSID local_488;
  CLSID local_478;
  longlong local_468;
  uchar local_460 [8];
  undefined1 local_458 [48];
  undefined1 local_428 [1008];
  ulonglong local_38;
  
  local_38 = DAT_180052888 ^ (ulonglong)&local_4b8;
  if (param_2 == -1) {
    uStack_500 = 0x18000eaee;
    param_2 = FUN_18000c180(param_1);
    puVar13 = auStack_4f8;
    if (param_2 != -1) goto LAB_18000eaf9;
LAB_18000ef6d:
    uVar10 = 0;
    puVar14 = puVar13;
  }
  else {
LAB_18000eaf9:
    uStack_500 = 0x18000eb06;
    iVar2 = _stat64i32(param_1,local_458);
    puVar13 = auStack_4f8;
    if (iVar2 != -1) {
      if (param_2 != 0) {
        puVar13 = auStack_4f8;
        if (param_2 != 5) goto LAB_18000f281;
        puVar13 = auStack_4f8;
        if (param_1 == (char *)0x0) {
LAB_18000eba0:
          puVar14 = puVar13;
          pWVar15 = (WCHAR *)0x0;
        }
        else {
          lVar4 = -1;
          do {
            lVar7 = lVar4;
            lVar4 = lVar7 + 1;
          } while (param_1[lVar4] != '\0');
          iVar2 = (int)lVar7 + 2;
          puVar13 = auStack_4f8;
          if (0x3fffffff < iVar2) goto LAB_18000eba0;
          lVar4 = (longlong)(int)lVar4 * 2;
          uVar9 = lVar4 + 0x11;
          if (uVar9 <= lVar4 + 2U) {
            uVar9 = 0xffffffffffffff0;
          }
          uStack_500 = 0x18000eb6c;
          lVar4 = -(uVar9 & 0xfffffffffffffff0);
          puVar13 = auStack_4f8 + lVar4;
          pWVar15 = (WCHAR *)((longlong)aiStack_4d0 + lVar4 + 0x18);
          if (pWVar15 == (WCHAR *)0x0) goto LAB_18000eba0;
          *pWVar15 = L'\0';
          *(int *)((longlong)aiStack_4d0 + lVar4) = iVar2;
          *(WCHAR **)(auStack_4f8 + lVar4 + 0x20) = pWVar15;
          *(undefined8 *)(auStack_4f8 + lVar4 + -8) = 0x18000eb98;
          iVar2 = MultiByteToWideChar(0,0,param_1,-1,*(LPWSTR *)(auStack_4f8 + lVar4 + 0x20),
                                      *(int *)((longlong)aiStack_4d0 + lVar4));
          puVar14 = auStack_4f8 + lVar4;
          if (iVar2 == 0) {
            puVar14 = auStack_4f8 + lVar4;
            pWVar15 = (WCHAR *)0x0;
          }
        }
        pOVar11 = (LPCOLESTR)0x0;
        *(undefined8 *)(puVar14 + -8) = 0x18000ebad;
        HVar3 = StgIsStorageFile(pWVar15);
        puVar13 = puVar14;
        if (HVar3 == 0) {
          if (param_1 != (char *)0x0) {
            lVar4 = -1;
            do {
              lVar7 = lVar4;
              lVar4 = lVar7 + 1;
            } while (param_1[lVar4] != '\0');
            iVar2 = (int)lVar7 + 2;
            if (iVar2 < 0x40000000) {
              lVar4 = (longlong)(int)lVar4 * 2;
              uVar9 = lVar4 + 0x11;
              if (uVar9 <= lVar4 + 2U) {
                uVar9 = 0xffffffffffffff0;
              }
              *(undefined8 *)(puVar14 + -8) = 0x18000ec16;
              lVar4 = -(uVar9 & 0xfffffffffffffff0);
              pOVar16 = (LPCOLESTR)(puVar14 + lVar4 + 0x40);
              puVar13 = puVar14 + lVar4;
              if (pOVar16 != (LPCOLESTR)0x0) {
                *pOVar16 = L'\0';
                *(int *)(puVar14 + lVar4 + 0x28) = iVar2;
                *(LPCOLESTR *)(puVar14 + lVar4 + 0x20) = pOVar16;
                *(undefined8 *)(puVar14 + lVar4 + -8) = 0x18000ec42;
                iVar2 = MultiByteToWideChar(0,0,param_1,-1,*(LPWSTR *)(puVar14 + lVar4 + 0x20),
                                            *(int *)(puVar14 + lVar4 + 0x28));
                if (iVar2 == 0) {
                  pOVar16 = pOVar11;
                }
                pOVar11 = pOVar16;
                puVar13 = puVar14 + lVar4;
              }
            }
          }
          *(undefined8 *)(puVar13 + -8) = 0x18000ec58;
          HVar3 = GetClassFile(pOVar11,&local_478);
          if (HVar3 == 0) {
            if (((((((local_478._0_8_ == DAT_180041180) && (local_478.Data4 == DAT_180041188)) ||
                   ((local_478._0_8_ == DAT_1800411a0 && (local_478.Data4 == DAT_1800411a8)))) ||
                  ((local_478._0_8_ == DAT_1800411b0 && (local_478.Data4 == DAT_1800411b8)))) ||
                 (((local_478._0_8_ == DAT_1800411c0 && (local_478.Data4 == DAT_1800411c8)) ||
                  ((((local_478._0_8_ == DAT_1800411d0 && (local_478.Data4 == DAT_1800411d8)) ||
                    ((local_478._0_8_ == DAT_1800411e0 && (local_478.Data4 == DAT_1800411e8)))) ||
                   ((local_478._0_8_ == DAT_1800411f0 && (local_478.Data4 == DAT_1800411f8))))))))
                || (((local_478._0_8_ == DAT_180041200 && (local_478.Data4 == DAT_180041208)) ||
                    ((((local_478._0_8_ == DAT_180041210 && (local_478.Data4 == DAT_180041218)) ||
                      ((local_478._0_8_ == DAT_180041220 && (local_478.Data4 == DAT_180041228)))) ||
                     ((((local_478._0_8_ == DAT_180041230 && (local_478.Data4 == DAT_180041238)) ||
                       ((local_478._0_8_ == DAT_180041240 && (local_478.Data4 == DAT_180041248))))
                      || ((((local_478._0_8_ == DAT_180041250 && (local_478.Data4 == DAT_180041258))
                           || ((local_478._0_8_ == DAT_180041260 &&
                               (local_478.Data4 == DAT_180041268)))) ||
                          ((local_478._0_8_ == DAT_180041270 && (local_478.Data4 == DAT_180041278)))
                          ))))))))) ||
               (((local_478._0_8_ == DAT_180041280 && (local_478.Data4 == DAT_180041288)) ||
                (((((local_478._0_8_ == DAT_180041290 && (local_478.Data4 == DAT_180041298)) ||
                   ((local_478._0_8_ == DAT_1800412a0 && (local_478.Data4 == DAT_1800412a8)))) ||
                  (((((local_478._0_8_ == DAT_1800412b0 && (local_478.Data4 == DAT_1800412b8)) ||
                     ((local_478._0_8_ == DAT_1800412c0 && (local_478.Data4 == DAT_1800412c8)))) ||
                    ((((local_478._0_8_ == DAT_1800412d0 && (local_478.Data4 == DAT_1800412d8)) ||
                      ((local_478._0_8_ == DAT_1800412e0 && (local_478.Data4 == DAT_1800412e8)))) ||
                     ((local_478._0_8_ == DAT_1800412f0 && (local_478.Data4 == DAT_1800412f8))))))
                   || ((local_478._0_8_ == DAT_180041300 && (local_478.Data4 == DAT_180041308))))))
                 || (((local_478._0_8_ == DAT_180041310 && (local_478.Data4 == DAT_180041318)) ||
                     ((local_478._0_8_ == DAT_180041320 && (local_478.Data4 == DAT_180041328))))))))
               )) goto LAB_18000f281;
            uVar10 = 0x571;
          }
          else {
            uVar10 = 0x570;
          }
        }
        else {
          uVar10 = 0x56f;
        }
        *(undefined8 *)(puVar13 + -8) = 0x18000ebbc;
        pcVar5 = (char *)GetSorResStringEx(uVar10);
        *(undefined8 *)(puVar13 + -8) = 0x18000ebc8;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format(param_3,pcVar5);
        uVar10 = 0;
        puVar14 = puVar13;
        goto LAB_18000f286;
      }
      puVar13 = auStack_4f8;
      if (param_1 == (char *)0x0) {
LAB_18000ef3a:
        pWVar15 = (WCHAR *)0x0;
      }
      else {
        lVar4 = -1;
        do {
          lVar7 = lVar4;
          lVar4 = lVar7 + 1;
        } while (param_1[lVar4] != '\0');
        iVar2 = (int)lVar7 + 2;
        puVar13 = auStack_4f8;
        if (0x3fffffff < iVar2) goto LAB_18000ef3a;
        lVar4 = (longlong)(int)lVar4 * 2;
        uVar9 = lVar4 + 0x11;
        if (uVar9 <= lVar4 + 2U) {
          uVar9 = 0xffffffffffffff0;
        }
        uStack_500 = 0x18000ef06;
        lVar4 = -(uVar9 & 0xfffffffffffffff0);
        puVar13 = auStack_4f8 + lVar4;
        pWVar15 = (WCHAR *)((longlong)aiStack_4d0 + lVar4 + 0x18);
        if (pWVar15 == (WCHAR *)0x0) goto LAB_18000ef3a;
        *pWVar15 = L'\0';
        *(int *)((longlong)aiStack_4d0 + lVar4) = iVar2;
        *(WCHAR **)(auStack_4f8 + lVar4 + 0x20) = pWVar15;
        *(undefined8 *)(auStack_4f8 + lVar4 + -8) = 0x18000ef32;
        iVar2 = MultiByteToWideChar(0,0,param_1,-1,*(LPWSTR *)(auStack_4f8 + lVar4 + 0x20),
                                    *(int *)((longlong)aiStack_4d0 + lVar4));
        puVar13 = auStack_4f8 + lVar4;
        if (iVar2 == 0) {
          puVar13 = auStack_4f8 + lVar4;
          pWVar15 = (WCHAR *)0x0;
        }
      }
      pOVar11 = (LPCOLESTR)0x0;
      *(undefined8 *)(puVar13 + -8) = 0x18000ef47;
      HVar3 = StgIsStorageFile(pWVar15);
      if (HVar3 != 0) {
        *(undefined8 *)(puVar13 + -8) = 0x18000ef50;
        pcVar5 = FUN_180033be0();
        uVar10 = 0x56a;
LAB_18000ef55:
        *(undefined8 *)(puVar13 + -8) = 0x18000ef5e;
        pcVar6 = (char *)GetSorResStringEx(uVar10);
        *(undefined8 *)(puVar13 + -8) = 0x18000ef6d;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                  (param_3,pcVar6,pcVar5);
        goto LAB_18000ef6d;
      }
      pcVar1 = *(code **)(*DAT_180054050 + 0x138);
      *(undefined8 *)(puVar13 + -8) = 0x18000ef88;
      iVar2 = (*pcVar1)(DAT_180054050,&local_468);
      if (iVar2 != 0) {
        *(undefined8 *)(puVar13 + -8) = 0x18000efac;
        FUN_180001ce0(local_428,"Assert failed in file %s line %d",
                      "G:\\Agent\\work\\2\\s\\src\\mm\\ApwnShellIP\\ApwnLWDocument.cpp",0x24f);
        *(undefined8 *)(puVar13 + -8) = 0x18000efc2;
        LogMessage(local_428,2,1);
      }
      puVar14 = puVar13;
      if (param_1 == (char *)0x0) {
LAB_18000f03a:
        puVar13 = puVar14;
        pOVar16 = pOVar11;
      }
      else {
        lVar4 = -1;
        do {
          lVar7 = lVar4;
          lVar4 = lVar7 + 1;
        } while (param_1[lVar4] != '\0');
        iVar2 = (int)lVar7 + 2;
        if (0x3fffffff < iVar2) goto LAB_18000f03a;
        lVar4 = (longlong)(int)lVar4 * 2;
        uVar9 = lVar4 + 0x11;
        if (uVar9 <= lVar4 + 2U) {
          uVar9 = 0xffffffffffffff0;
        }
        *(undefined8 *)(puVar13 + -8) = 0x18000f006;
        lVar4 = -(uVar9 & 0xfffffffffffffff0);
        puVar14 = puVar13 + lVar4;
        puVar12 = puVar13 + lVar4;
        pOVar16 = (LPCOLESTR)(puVar13 + lVar4 + 0x40);
        if (pOVar16 == (LPCOLESTR)0x0) goto LAB_18000f03a;
        *pOVar16 = L'\0';
        *(int *)(puVar13 + lVar4 + 0x28) = iVar2;
        *(LPCOLESTR *)(puVar13 + lVar4 + 0x20) = pOVar16;
        *(undefined8 *)(puVar13 + lVar4 + -8) = 0x18000f032;
        iVar2 = MultiByteToWideChar(0,0,param_1,-1,*(LPWSTR *)(puVar13 + lVar4 + 0x20),
                                    *(int *)(puVar13 + lVar4 + 0x28));
        puVar13 = puVar13 + lVar4;
        if (iVar2 == 0) {
          puVar13 = puVar12;
          pOVar16 = pOVar11;
        }
      }
      *(undefined8 *)(puVar13 + -8) = 0x18000f04a;
      HVar3 = GetClassFile(pOVar16,&local_488);
      puVar14 = puVar13;
      if (HVar3 != 0) {
        *(undefined8 *)(puVar13 + -8) = 0x18000f059;
        pcVar5 = (char *)GetSorResStringEx(0x56b);
        *(undefined8 *)(puVar13 + -8) = 0x18000f065;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format(param_3,pcVar5);
        uVar10 = 0;
        goto LAB_18000f286;
      }
      if ((local_488._0_8_ != local_468) || (local_488.Data4 != local_460)) {
        *(undefined8 *)(puVar13 + -8) = 0x18000f099;
        uVar10 = FUN_180010820(&local_488,local_4a0,&uStack_4b4,&local_4b8);
        if ((int)uVar10 == 0) {
          *(undefined8 *)(puVar13 + -8) = 0x18000f10d;
          ProgIDFromCLSID(&local_488,&local_498);
          if (local_498 != (LPCWSTR)0x0) {
            lVar4 = -1;
            do {
              lVar7 = lVar4;
              lVar4 = lVar7 + 1;
            } while (local_498[lVar4] != L'\0');
            iVar2 = (int)lVar7 + 2;
            if (iVar2 < 0x40000000) {
              lVar4 = (longlong)(int)lVar4 * 2;
              uVar9 = lVar4 + 0x11;
              if (uVar9 <= lVar4 + 2U) {
                uVar9 = 0xffffffffffffff0;
              }
              *(undefined8 *)(puVar13 + -8) = 0x18000f159;
              lVar4 = -(uVar9 & 0xfffffffffffffff0);
              pOVar16 = (LPCOLESTR)(puVar13 + lVar4 + 0x40);
              puVar14 = puVar13 + lVar4;
              if (pOVar16 != (LPCOLESTR)0x0) {
                *(char *)pOVar16 = '\0';
                *(undefined8 *)(puVar13 + lVar4 + 0x38) = 0;
                *(undefined8 *)(puVar13 + lVar4 + 0x30) = 0;
                *(int *)(puVar13 + lVar4 + 0x28) = iVar2 * 2;
                *(LPCOLESTR *)(puVar13 + lVar4 + 0x20) = pOVar16;
                *(undefined8 *)(puVar13 + lVar4 + -8) = 0x18000f18d;
                iVar2 = WideCharToMultiByte(0,0,local_498,-1,*(LPSTR *)(puVar13 + lVar4 + 0x20),
                                            *(int *)(puVar13 + lVar4 + 0x28),
                                            *(LPCSTR *)(puVar13 + lVar4 + 0x30),
                                            *(LPBOOL *)(puVar13 + lVar4 + 0x38));
                if (iVar2 == 0) {
                  pOVar16 = pOVar11;
                }
                pOVar11 = pOVar16;
                puVar14 = puVar13 + lVar4;
              }
            }
          }
          *(undefined8 *)(puVar14 + -8) = 0x18000f1a3;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_4a8,(char *)pOVar11);
          *(undefined8 *)(puVar14 + -8) = 0x18000f1b5;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4b0,
                     "Apwn.Document.");
          pcVar5 = local_4b0;
          *(undefined8 *)(puVar14 + -8) = 0x18000f1c7;
          iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                            (local_4a8,pcVar5,0);
          if (iVar2 == -1) {
            *(undefined8 *)(puVar14 + -8) = 0x18000f1df;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4b0,
                       "AspenProperties.Document.");
            *(undefined8 *)(puVar14 + -8) = 0x18000f1f0;
            iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                              (local_4a8,local_4b0,0);
          }
          if (iVar2 < 0) {
            *(undefined8 *)(puVar14 + -8) = 0x18000f24a;
            pcVar5 = FUN_180033be0();
            *(undefined8 *)(puVar14 + -8) = 0x18000f258;
            pcVar6 = (char *)GetSorResStringEx(0x56e);
            *(undefined8 *)(puVar14 + -8) = 0x18000f267;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                      (param_3,pcVar6,pcVar5);
          }
          else {
            *(undefined8 *)(puVar14 + -8) = 0x18000f210;
            puVar8 = (undefined8 *)
                     ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                               (local_4a8,(int)local_490);
            *(undefined8 *)(puVar14 + -8) = 0x18000f218;
            pcVar5 = FUN_180033be0();
            *(undefined8 *)(puVar14 + -8) = 0x18000f226;
            pcVar6 = (char *)GetSorResStringEx(0x821);
            uVar10 = *puVar8;
            *(undefined8 *)(puVar14 + -8) = 0x18000f238;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                      (param_3,pcVar6,pcVar5,uVar10);
            *(undefined8 *)(puVar14 + -8) = 0x18000f243;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_490);
          }
          *(undefined8 *)(puVar14 + -8) = 0x18000f272;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4b0);
          *(undefined8 *)(puVar14 + -8) = 0x18000f27d;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_4a8);
          uVar10 = 0;
          goto LAB_18000f286;
        }
        *(undefined8 *)(puVar13 + -8) = 0x18000f0a2;
        iVar2 = FUN_180001540();
        if (local_4a0[0] != iVar2) {
          *(undefined8 *)(puVar13 + -8) = 0x18000f0ac;
          pcVar5 = FUN_180033be0();
          uVar10 = 0x56c;
          goto LAB_18000ef55;
        }
        if (((int)uStack_4b4 < 0xc) || ((uStack_4b4 == 0xc && ((int)local_4b8 < 2)))) {
          *(undefined8 *)(puVar13 + -8) = 0x18000f0d1;
          pcVar5 = FUN_180033be0();
          *(undefined8 *)(puVar13 + -8) = 0x18000f0df;
          pcVar6 = (char *)GetSorResStringEx(0x56d);
          *(char **)(puVar13 + 0x20) = pcVar5;
          *(undefined8 *)(puVar13 + -8) = 0x18000f0f8;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                    (param_3,pcVar6,(ulonglong)uStack_4b4,(ulonglong)local_4b8);
          uVar10 = 0;
          goto LAB_18000f286;
        }
      }
    }
LAB_18000f281:
    uVar10 = 1;
    puVar14 = puVar13;
  }
LAB_18000f286:
  *(undefined8 *)(puVar14 + -8) = 0x18000f295;
  return uVar10;
}

/* RVA 0xf2b0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18000f2b0(undefined8 param_1,longlong *param_2)

{
  int iVar1;
  LPWSTR lpWideCharStr;
  LPWSTR in_stack_ffffffffffffffb8;
  WCHAR local_38 [16];
  longlong *local_18;
  ulonglong local_10;
  
  local_10 = DAT_180052888 ^ (ulonglong)&local_18;
  local_18 = (longlong *)0x0;
  lpWideCharStr = local_38;
  if (lpWideCharStr == (LPWSTR)0x0) {
    lpWideCharStr = (LPWSTR)0x0;
  }
  else {
    local_38[0] = L'\0';
    in_stack_ffffffffffffffb8 = lpWideCharStr;
    iVar1 = MultiByteToWideChar(0,0,"ApwnACESettings",-1,lpWideCharStr,0x10);
    if (iVar1 == 0) {
      lpWideCharStr = (LPWSTR)0x0;
    }
  }
  iVar1 = (**(code **)(*param_2 + 0x20))
                    (param_2,lpWideCharStr,0,0x12,
                     (ulonglong)in_stack_ffffffffffffffb8 & 0xffffffff00000000,&local_18);
  if (-1 < iVar1) {
    ReadACEStringFromIStream(local_18);
    (**(code **)(*local_18 + 0x10))();
  }
  return;
}

/* RVA 0xf380 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18000f380(undefined8 param_1,longlong *param_2)

{
  int iVar1;
  undefined8 uVar2;
  WCHAR *pWVar3;
  undefined1 uStack0000000000000000;
  undefined1 *in_stack_ffffffffffffffa8;
  WCHAR *pWVar4;
  WCHAR local_48 [24];
  longlong *local_18;
  ulonglong local_10;
  
  pWVar3 = local_48;
  pWVar4 = local_48;
  local_10 = DAT_180052888 ^ (ulonglong)&local_18;
  local_18 = (longlong *)0x0;
  if (&uStack0000000000000000 == (undefined1 *)0x48) {
    pWVar3 = (WCHAR *)0x0;
    pWVar4 = (WCHAR *)in_stack_ffffffffffffffa8;
  }
  else {
    local_48[0] = L'\0';
    iVar1 = MultiByteToWideChar(0,0,"ApwnShellSettings",-1,local_48,0x12);
    if (iVar1 == 0) {
      pWVar3 = (WCHAR *)0x0;
    }
  }
  iVar1 = (**(code **)(*param_2 + 0x20))
                    (param_2,pWVar3,0,0x12,(ulonglong)pWVar4 & 0xffffffff00000000,&local_18);
  if (-1 < iVar1) {
    uVar2 = GRGetShellSettingsFile();
    ReadApwnShellSettingsFromStreamToFile(local_18,uVar2);
    (**(code **)(*local_18 + 0x10))();
  }
  return;
}

/* RVA 0xf450 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18000f450(undefined8 param_1,longlong *param_2)

{
  int iVar1;
  void *pvVar2;
  LPWSTR lpWideCharStr;
  undefined1 *puVar3;
  undefined1 auStackY_68 [8];
  undefined8 uStackY_60;
  undefined1 local_58 [16];
  WCHAR local_38 [8];
  int local_28 [2];
  longlong *local_20;
  ulonglong local_18;
  
  local_18 = DAT_180052888 ^ (ulonglong)local_28;
  uStackY_60 = 0x18000f47d;
  iVar1 = FUN_180033bd0();
  puVar3 = local_58;
  if (iVar1 == 1) {
    local_20 = (longlong *)0x0;
    lpWideCharStr = local_38;
    if (lpWideCharStr == (LPWSTR)0x0) {
      lpWideCharStr = (LPWSTR)0x0;
    }
    else {
      local_38[0] = L'\0';
      iVar1 = MultiByteToWideChar(0,0,"EOUtil",-1,lpWideCharStr,7);
      if (iVar1 == 0) {
        lpWideCharStr = (LPWSTR)0x0;
      }
    }
    iVar1 = (**(code **)(*param_2 + 0x20))(param_2,lpWideCharStr,0,0x12);
    puVar3 = auStackY_68;
    if (-1 < iVar1) {
      local_28[0] = 0;
      (**(code **)(*local_20 + 0x18))(local_20,local_28,4);
      if (0 < local_28[0]) {
        pvVar2 = operator_new__((longlong)(local_28[0] + 1));
        (**(code **)(*local_20 + 0x18))(local_20,pvVar2,local_28[0],0);
        EOreablk(1,pvVar2,local_28[0]);
        operator_delete__(pvVar2);
      }
      (**(code **)(*local_20 + 0x10))();
      Ordinal_131(param_2,0);
      puVar3 = auStackY_68;
    }
  }
  *(undefined8 *)(puVar3 + -8) = 0x18000f56f;
  return;
}

/* RVA 0xf590 */
void FUN_18000f590(longlong param_1)

{
  LPVOID *ppv;
  LPVOID *ppv_00;
  longlong *plVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  int iVar4;
  HRESULT HVar5;
  HMODULE hModule;
  FARPROC pFVar6;
  BSTR bstrString;
  bool bVar7;
  longlong *local_res10;
  longlong *local_res18;
  
  iVar4 = FUN_180033bd0();
  if (iVar4 != 1) {
    return;
  }
  ppv = (LPVOID *)(param_1 + 0x20);
  ppv_00 = (LPVOID *)(param_1 + 0x18);
  if ((*ppv != (LPVOID)0x0) && (*ppv_00 != (LPVOID)0x0)) {
    return;
  }
  hModule = LoadLibraryA("mmg.dll");
  pFVar6 = GetProcAddress(hModule,"g_RootStg");
  plVar1 = *(longlong **)pFVar6;
  FreeLibrary(hModule);
  if (*ppv == (LPVOID)0x0) {
    HVar5 = CoCreateInstance((IID *)&DAT_180041170,(LPUNKNOWN)0x0,1,(IID *)&DAT_180042b18,ppv);
    if (HVar5 < 0) {
      return;
    }
    local_res10 = (longlong *)0x0;
    bstrString = SysAllocString(L"ICONLIB");
    iVar4 = (**(code **)(*plVar1 + 0x30))(plVar1,bstrString,0,0x10,0,0,&local_res10);
    SysFreeString(bstrString);
    if (iVar4 < 0) {
      MMAfxMessageBox("Bad recdef.apr! icondef.exe probably failed to run!",0x30,-1,0);
      plVar1 = *ppv;
      if (plVar1 != (longlong *)0x0) {
        *ppv = (LPVOID)0x0;
        (**(code **)(*plVar1 + 0x10))();
      }
      goto LAB_18000f877;
    }
    (**(code **)(*(longlong *)*ppv + 0x30))(*ppv,local_res10);
    if (local_res10 != (longlong *)0x0) {
      (**(code **)(*local_res10 + 0x10))();
    }
  }
  if (*ppv_00 == (LPVOID)0x0) {
    HVar5 = CoCreateInstance((IID *)&DAT_180041160,(LPUNKNOWN)0x0,1,(IID *)&DAT_180042b18,ppv_00);
    if (HVar5 < 0) {
      return;
    }
    local_res10 = (longlong *)0x0;
    iVar4 = (**(code **)(*plVar1 + 0x30))(plVar1,L"MODELLIB",0,0x10,0,0,&local_res10);
    plVar1 = *ppv_00;
    if (iVar4 < 0) {
      if (plVar1 != (longlong *)0x0) {
        *ppv_00 = (LPVOID)0x0;
        (**(code **)(*plVar1 + 0x10))();
      }
      goto LAB_18000f877;
    }
    (**(code **)(*plVar1 + 0x30))(plVar1,local_res10);
    if (local_res10 != (longlong *)0x0) {
      (**(code **)(*local_res10 + 0x10))();
    }
  }
  if (*(longlong *)(param_1 + 0x28) == 0) {
    InitializeApwnLibraries(*ppv_00,0);
  }
  puVar2 = *ppv_00;
  puVar3 = *(undefined8 **)(param_1 + 0x30);
  if (puVar3 == (undefined8 *)0x0) {
    if (puVar2 != (undefined8 *)0x0) goto LAB_18000f7fa;
  }
  else {
    if (puVar2 != (undefined8 *)0x0) {
      local_res10 = (longlong *)0x0;
      local_res18 = (longlong *)0x0;
      (**(code **)*puVar3)(puVar3,&DAT_180041330,&local_res10);
      (**(code **)*puVar2)(puVar2,&DAT_180041330,&local_res18);
      bVar7 = local_res10 == local_res18;
      if (local_res18 != (longlong *)0x0) {
        (**(code **)(*local_res18 + 0x10))(local_res18);
      }
      if (local_res10 != (longlong *)0x0) {
        (**(code **)(*local_res10 + 0x10))();
      }
      if (bVar7) goto LAB_18000f82c;
    }
LAB_18000f7fa:
    puVar2 = *ppv_00;
    plVar1 = *(longlong **)(param_1 + 0x30);
    if ((puVar2 == (undefined8 *)0x0) ||
       (iVar4 = (**(code **)*puVar2)(puVar2,&DAT_180041f50,param_1 + 0x30), iVar4 < 0)) {
      *(undefined8 *)(param_1 + 0x30) = 0;
    }
    if (plVar1 != (longlong *)0x0) {
      (**(code **)(*plVar1 + 0x10))(plVar1);
    }
  }
LAB_18000f82c:
  if (*(longlong *)(param_1 + 0x30) == 0) {
    return;
  }
  SetModelLibraryPtr();
  puVar2 = *ppv;
  local_res10 = (longlong *)0x0;
  if ((puVar2 != (undefined8 *)0x0) &&
     (iVar4 = (**(code **)*puVar2)(puVar2,&DAT_1800418b0,&local_res10), iVar4 < 0)) {
    local_res10 = (longlong *)0x0;
  }
  (**(code **)(**(longlong **)(param_1 + 0x30) + 0x50))(*(longlong **)(param_1 + 0x30),local_res10);
LAB_18000f877:
  if (local_res10 != (longlong *)0x0) {
    (**(code **)(*local_res10 + 0x10))();
  }
  return;
}

/* RVA 0xf8b0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 FUN_18000f8b0(longlong *param_1,BSTR param_2)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  _func_5400 *p_Var5;
  _func_5396 *p_Var6;
  code *pcVar7;
  _func_5400 *p_Var8;
  UINT UVar9;
  uint uVar10;
  undefined4 uVar11;
  int iVar12;
  HRESULT HVar13;
  longlong *plVar14;
  void *pvVar15;
  char *pcVar16;
  char *pcVar17;
  byte ****ppppbVar18;
  _func_5398 **pp_Var19;
  undefined8 ****ppppuVar20;
  IStorage IVar21;
  undefined8 ****ppppuVar22;
  LPWSTR lpWideCharStr;
  undefined1 *puVar23;
  undefined1 *puVar24;
  IStorage IVar25;
  byte ****ppppbVar26;
  size_t sVar27;
  _func_5400 *p_Var28;
  size_t sVar29;
  IStorage IVar30;
  ulonglong uVar31;
  undefined1 uVar32;
  longlong lVar33;
  undefined1 auStackY_2c8 [24];
  undefined8 uStackY_2b0;
  WCHAR local_288 [16];
  bool local_268 [4];
  uint local_264;
  uint local_260 [2];
  IStorage local_258;
  IStorage local_250;
  IStorage local_248;
  longlong *local_240;
  longlong *local_238;
  longlong *local_230;
  longlong *local_228;
  longlong *local_220 [3];
  LPCWSTR local_208 [10];
  undefined8 ****local_1b8;
  undefined8 uStack_1b0;
  _func_5400 *local_1a8;
  ulonglong local_1a0;
  byte ****local_198;
  undefined8 uStack_190;
  longlong local_188;
  ulonglong local_180;
  CLSID local_178;
  undefined1 *local_168;
  undefined1 local_160 [136];
  undefined1 *local_d8;
  undefined1 local_d0 [136];
  ulonglong local_48;
  
  local_48 = DAT_180052888 ^ (ulonglong)local_268;
  local_268[0] = false;
  uStackY_2b0 = 0x18000f8f6;
  local_240 = param_1;
  plVar14 = (longlong *)HappGetHapp();
  puVar24 = auStackY_2c8 + 0x20;
  uVar32 = 0;
  if (plVar14 == (longlong *)0x0) goto LAB_180010253;
  local_228 = (longlong *)0x0;
  uStack_1b0 = 0;
  local_1a8 = (_func_5400 *)0x0;
  local_1a0 = 0xf;
  local_1b8 = (undefined8 ****)0x0;
  sVar29 = 0xffffffffffffffff;
  if (param_2 == (BSTR)0x0) {
LAB_18000f9a9:
    local_1a8 = (_func_5400 *)0x4;
    local_1b8 = (undefined8 ****)CONCAT35(local_1b8._5_3_,0x746f6f52);
  }
  else {
    uStackY_2b0 = 0x18000f93e;
    UVar9 = SysStringLen(param_2);
    if (UVar9 == 0) goto LAB_18000f9a9;
    local_168 = local_160;
    uStackY_2b0 = 0x18000f962;
    FUN_18000d880(&local_168,param_2,0);
    sVar27 = 0xffffffffffffffff;
    do {
      sVar27 = sVar27 + 1;
    } while (local_168[sVar27] != '\0');
    uStackY_2b0 = 0x18000f986;
    FUN_18001d350((longlong *)&local_1b8,local_168,sVar27);
    if (local_168 != local_160) {
      uStackY_2b0 = 0x18000f9a0;
      free(local_168);
    }
  }
  p_Var8 = local_1a8;
  uStackY_2b0 = 0x18000f9d9;
  (**(code **)(*plVar14 + 0x1f8))(plVar14,param_2,&local_228);
  uVar31 = local_1a0;
  ppppuVar20 = local_1b8;
  puVar24 = auStackY_2c8 + 0x20;
  puVar23 = auStackY_2c8 + 0x20;
  uVar32 = 0;
  if (local_228 != (longlong *)0x0) {
    local_248.lpVtbl = (IStorageVtbl *)0x0;
    local_230 = (longlong *)0x0;
    IVar21.lpVtbl = (IStorageVtbl *)param_1[0x1a];
    local_258.lpVtbl = (IStorageVtbl *)(IVar21.lpVtbl)->AddRef;
    local_250.lpVtbl = IVar21.lpVtbl;
    if (*(char *)((longlong)&(local_258.lpVtbl)->CreateStream + 1) == '\0') {
      IVar30.lpVtbl = IVar21.lpVtbl;
      IVar25.lpVtbl = local_258.lpVtbl;
      do {
        IVar21.lpVtbl = IVar25.lpVtbl;
        ppppuVar22 = &local_1b8;
        if (0xf < uVar31) {
          ppppuVar22 = ppppuVar20;
        }
        pp_Var19 = &(IVar21.lpVtbl)->OpenStream;
        if ((_func_5401 *)0xf < (IVar21.lpVtbl)->CopyTo) {
          pp_Var19 = (_func_5398 **)(IVar21.lpVtbl)->OpenStream;
        }
        p_Var5 = (IVar21.lpVtbl)->OpenStorage;
        p_Var28 = p_Var5;
        if (p_Var8 < p_Var5) {
          p_Var28 = p_Var8;
        }
        uStackY_2b0 = 0x18000fa51;
        uVar10 = memcmp(pp_Var19,ppppuVar22,(size_t)p_Var28);
        if (uVar10 == 0) {
          if (p_Var5 < p_Var8) {
            uVar10 = 0xffffffff;
          }
          else {
            uVar10 = (uint)(p_Var8 < p_Var5);
          }
        }
        if ((int)uVar10 < 0) {
          IVar25.lpVtbl = (IStorageVtbl *)(IVar21.lpVtbl)->Release;
          IVar21.lpVtbl = IVar30.lpVtbl;
        }
        else {
          IVar25.lpVtbl = (IStorageVtbl *)(IVar21.lpVtbl)->QueryInterface;
        }
        IVar30.lpVtbl = IVar21.lpVtbl;
      } while (*(code *)((longlong)&(IVar25.lpVtbl)->CreateStream + 1) == (code)0x0);
      param_1 = local_240;
    }
    IVar30.lpVtbl = local_250.lpVtbl;
    IVar25.lpVtbl = local_258.lpVtbl;
    if (*(char *)((longlong)&(IVar21.lpVtbl)->CreateStream + 1) == '\0') {
      pp_Var19 = &(IVar21.lpVtbl)->OpenStream;
      if ((_func_5401 *)0xf < (IVar21.lpVtbl)->CopyTo) {
        pp_Var19 = (_func_5398 **)(IVar21.lpVtbl)->OpenStream;
      }
      ppppuVar20 = &local_1b8;
      if (0xf < local_1a0) {
        ppppuVar20 = local_1b8;
      }
      p_Var5 = (IVar21.lpVtbl)->OpenStorage;
      p_Var28 = p_Var8;
      if (p_Var5 < p_Var8) {
        p_Var28 = p_Var5;
      }
      uStackY_2b0 = 0x18000fad4;
      uVar10 = memcmp(ppppuVar20,pp_Var19,(size_t)p_Var28);
      uVar31 = local_1a0;
      ppppuVar20 = local_1b8;
      if (uVar10 == 0) {
        if (p_Var8 < p_Var5) {
          uVar10 = 0xffffffff;
        }
        else {
          uVar10 = (uint)(p_Var5 < p_Var8);
        }
      }
      if (((int)uVar10 < 0) || (IVar21.lpVtbl == IVar30.lpVtbl)) goto LAB_18000fc03;
      IVar21.lpVtbl = IVar30.lpVtbl;
      if (*(char *)((longlong)&(IVar25.lpVtbl)->CreateStream + 1) ==
          (char)-(char)((int)uVar10 >> 0x1f)) {
        do {
          ppppuVar22 = &local_1b8;
          if (0xf < uVar31) {
            ppppuVar22 = ppppuVar20;
          }
          pp_Var19 = &(IVar25.lpVtbl)->OpenStream;
          if ((_func_5401 *)0xf < (IVar25.lpVtbl)->CopyTo) {
            pp_Var19 = (_func_5398 **)(IVar25.lpVtbl)->OpenStream;
          }
          p_Var5 = (IVar25.lpVtbl)->OpenStorage;
          p_Var28 = p_Var5;
          if (p_Var8 < p_Var5) {
            p_Var28 = p_Var8;
          }
          uStackY_2b0 = 0x18000fb51;
          uVar10 = memcmp(pp_Var19,ppppuVar22,(size_t)p_Var28);
          if (uVar10 == 0) {
            if (p_Var5 < p_Var8) {
              uVar10 = 0xffffffff;
            }
            else {
              uVar10 = (uint)(p_Var8 < p_Var5);
            }
          }
          if ((int)uVar10 < 0) {
            IVar21.lpVtbl = (IStorageVtbl *)(IVar25.lpVtbl)->Release;
          }
          else {
            IVar21.lpVtbl = (IStorageVtbl *)(IVar25.lpVtbl)->QueryInterface;
            IVar30.lpVtbl = IVar25.lpVtbl;
          }
          IVar25.lpVtbl = IVar21.lpVtbl;
        } while (*(char *)((longlong)&(IVar21.lpVtbl)->CreateStream + 1) == '\0');
        IVar21.lpVtbl = local_250.lpVtbl;
      }
      if (*(char *)((longlong)&(IVar30.lpVtbl)->CreateStream + 1) == '\0') {
        pp_Var19 = &(IVar30.lpVtbl)->OpenStream;
        if ((_func_5401 *)0xf < (IVar30.lpVtbl)->CopyTo) {
          pp_Var19 = (_func_5398 **)(IVar30.lpVtbl)->OpenStream;
        }
        ppppuVar20 = &local_1b8;
        if (0xf < uVar31) {
          ppppuVar20 = local_1b8;
        }
        p_Var5 = (IVar30.lpVtbl)->OpenStorage;
        p_Var28 = p_Var8;
        if (p_Var5 < p_Var8) {
          p_Var28 = p_Var5;
        }
        uStackY_2b0 = 0x18000fbc0;
        uVar10 = memcmp(ppppuVar20,pp_Var19,(size_t)p_Var28);
        if (uVar10 == 0) {
          if (p_Var8 < p_Var5) {
            uVar10 = 0xffffffff;
          }
          else {
            uVar10 = (uint)(p_Var5 < p_Var8);
          }
        }
        if ((int)uVar10 < 0) goto LAB_18000fbdd;
      }
      else {
LAB_18000fbdd:
        IVar30.lpVtbl = IVar21.lpVtbl;
      }
      IVar25.lpVtbl = (IStorageVtbl *)(IVar30.lpVtbl)->Commit;
      puVar24 = auStackY_2c8 + 0x20;
      if (IVar25.lpVtbl != (IStorageVtbl *)0x0) {
        uStackY_2b0 = 0x18000fbf6;
        (*((IStorageVtbl *)(IVar25.lpVtbl)->QueryInterface)->AddRef)((IStorage *)IVar25.lpVtbl);
        IVar21.lpVtbl = local_248.lpVtbl;
        local_248.lpVtbl = IVar25.lpVtbl;
        goto LAB_180010066;
      }
    }
    else {
LAB_18000fc03:
      puVar24 = auStackY_2c8 + 0x20;
      if ((*(char *)((longlong)param_1 + 0xac) == '\0') &&
         (puVar24 = auStackY_2c8 + 0x20, param_1[1] != 0)) {
        lpWideCharStr = local_288;
        if (lpWideCharStr == (LPWSTR)0x0) {
          lpWideCharStr = (LPWSTR)0x0;
        }
        else {
          local_288[0] = L'\0';
          iVar12 = MultiByteToWideChar(0,0,"PFSVData",-1,lpWideCharStr,9);
          if (iVar12 == 0) {
            lpWideCharStr = (LPWSTR)0x0;
          }
        }
        (**(code **)(*(longlong *)param_1[1] + 0x30))((longlong *)param_1[1],lpWideCharStr,0,0x12);
        puVar23 = auStackY_2c8;
        if (local_230 != (longlong *)0x0) {
          local_250.lpVtbl = (IStorageVtbl *)0x0;
          (**(code **)(*local_230 + 0x58))(local_230,0,0,0);
          puVar23 = auStackY_2c8;
          IVar21.lpVtbl = local_250.lpVtbl;
          if (local_250.lpVtbl != (IStorageVtbl *)0x0) {
            local_258.lpVtbl = (IStorageVtbl *)0x0;
            (**(code **)(*local_230 + 0x20))(local_230,L"_Contents",0,0x12);
            if (local_258.lpVtbl != (IStorageVtbl *)0x0) {
              local_238 = (longlong *)((ulonglong)local_238 & 0xffffffff00000000);
              uStack_190 = 0;
              lVar33 = 0;
              local_188 = 0;
              uVar31 = 0xf;
              local_180 = 0xf;
              local_198 = (byte ****)0x0;
              iVar12 = (**(code **)((local_258.lpVtbl)->QueryInterface + 0x18))
                                 (local_258.lpVtbl,local_260,4,&local_264);
joined_r0x00018000fd3b:
              if ((iVar12 != 0) || (local_264 != 4)) goto LAB_18000fe69;
              pvVar15 = operator_new__((ulonglong)(local_260[0] + 1));
              uVar10 = local_260[0];
              *(undefined1 *)((ulonglong)local_260[0] + (longlong)pvVar15) = 0;
              (**(code **)((local_258.lpVtbl)->QueryInterface + 0x18))
                        (local_258.lpVtbl,pvVar15,local_260[0],&local_264);
              pcVar16 = (char *)0x0;
              if (uVar10 != local_264) goto LAB_18000fede;
              (**(code **)((local_258.lpVtbl)->QueryInterface + 0x18))
                        (local_258.lpVtbl,local_260,4,&local_264);
              if (local_264 != 4) goto LAB_18000fede;
              pcVar16 = operator_new__((ulonglong)(local_260[0] + 1));
              uVar10 = local_260[0];
              pcVar16[local_260[0]] = '\0';
              (**(code **)((local_258.lpVtbl)->QueryInterface + 0x18))
                        (local_258.lpVtbl,pcVar16,local_260[0],&local_264);
              if (uVar10 != local_264) goto LAB_18000fede;
              (**(code **)((local_258.lpVtbl)->QueryInterface + 0x18))
                        (local_258.lpVtbl,&local_238,4,&local_264);
              if (local_264 != 4) goto LAB_18000fede;
              ppppuVar20 = &local_1b8;
              if (0xf < local_1a0) {
                ppppuVar20 = local_1b8;
              }
              pcVar17 = pcVar16;
              do {
                cVar1 = *pcVar17;
                cVar2 = pcVar17[(longlong)ppppuVar20 - (longlong)pcVar16];
                if (cVar1 != cVar2) break;
                pcVar17 = pcVar17 + 1;
              } while (cVar2 != '\0');
              if (cVar1 != cVar2) {
                operator_delete__(pvVar15);
                operator_delete__(pcVar16);
                iVar12 = (**(code **)((local_258.lpVtbl)->QueryInterface + 0x18))
                                   (local_258.lpVtbl,local_260,4,&local_264);
                goto joined_r0x00018000fd3b;
              }
              if ((int)local_238 == 1) {
                do {
                  sVar29 = sVar29 + 1;
                } while (*(char *)((longlong)pvVar15 + sVar29) != '\0');
                FUN_18001d350((longlong *)&local_198,pvVar15,sVar29);
                uVar31 = local_180;
                lVar33 = local_188;
              }
LAB_18000fede:
              if (pvVar15 != (void *)0x0) {
                operator_delete__(pvVar15);
              }
              if (pcVar16 != (char *)0x0) {
                operator_delete__(pcVar16);
              }
              ppppbVar26 = local_198;
              if (lVar33 == 0) {
LAB_18000fe69:
                ppppbVar26 = local_198;
              }
              else {
LAB_18000ff10:
                do {
                  while( true ) {
                    iVar12 = (**(code **)((local_250.lpVtbl)->QueryInterface + 0x18))
                                       (local_250.lpVtbl,1,local_208,&local_240);
                    IVar21.lpVtbl = local_248.lpVtbl;
                    if ((iVar12 < 0) || ((int)local_240 == 0)) goto LAB_18000fe70;
                    if (local_208[0] == (LPCWSTR)0x0) break;
                    lVar33 = 0;
                    do {
                      if ((local_208[0][lVar33] != L"_Contents"[lVar33]) ||
                         (local_208[0][lVar33 + 1] != L"_Contents"[lVar33 + 1])) goto LAB_18000ff74;
                      lVar33 = lVar33 + 2;
                    } while (lVar33 != 10);
                  }
LAB_18000ff74:
                  if (local_248.lpVtbl != (IStorageVtbl *)0x0) {
                    local_248.lpVtbl = (IStorageVtbl *)0x0;
                    (*((IStorageVtbl *)(IVar21.lpVtbl)->QueryInterface)->Release)
                              ((IStorage *)IVar21.lpVtbl);
                  }
                  iVar12 = (**(code **)(*local_230 + 0x30))(local_230,local_208[0],0,0x12);
                  if (iVar12 < 0) {
                    if (local_208[0] != (LPCWSTR)0x0) {
                      CoTaskMemFree(local_208[0]);
                    }
                    goto LAB_18000ff10;
                  }
                  local_d8 = local_d0;
                  FUN_18000d880(&local_d8,local_208[0],0);
                  ppppbVar18 = (byte ****)&local_198;
                  if (0xf < uVar31) {
                    ppppbVar18 = ppppbVar26;
                  }
                  lVar33 = (longlong)local_d8 - (longlong)ppppbVar18;
                  do {
                    bVar3 = *(byte *)ppppbVar18;
                    bVar4 = *(byte *)((longlong)ppppbVar18 + lVar33);
                    if (bVar3 != bVar4) {
                      uVar10 = -(uint)(bVar3 < bVar4) | 1;
                      goto LAB_180010029;
                    }
                    ppppbVar18 = (byte ****)((longlong)ppppbVar18 + 1);
                  } while (bVar3 != 0);
                  uVar10 = 0;
LAB_180010029:
                  if (local_d8 != local_d0) {
                    free(local_d8);
                  }
                } while (uVar10 != 0);
              }
LAB_18000fe70:
              if (0xf < uVar31) {
                ppppbVar18 = ppppbVar26;
                if ((0xfff < uVar31 + 1) &&
                   (ppppbVar18 = (byte ****)ppppbVar26[-1],
                   (byte *)0x1f < (byte *)((longlong)ppppbVar26 + (-8 - (longlong)ppppbVar18)))) {
                    /* WARNING: Subroutine does not return */
                  _invalid_parameter_noinfo_noreturn();
                }
                FUN_180035134(ppppbVar18);
              }
            }
            puVar23 = auStackY_2c8;
            if (local_258.lpVtbl != (IStorageVtbl *)0x0) {
              (**(code **)((local_258.lpVtbl)->QueryInterface + 0x10))();
            }
            IVar21.lpVtbl = local_250.lpVtbl;
          }
LAB_180010066:
          if (IVar21.lpVtbl != (IStorageVtbl *)0x0) {
            p_Var6 = ((IStorageVtbl *)(IVar21.lpVtbl)->QueryInterface)->Release;
            *(undefined8 *)(puVar23 + -8) = 0x180010071;
            (*p_Var6)((IStorage *)IVar21.lpVtbl);
          }
        }
        puVar24 = puVar23;
        if (local_248.lpVtbl != (IStorageVtbl *)0x0) {
          *(undefined8 *)(puVar23 + -8) = 0x180010082;
          uVar11 = GRinqres();
          *(undefined8 *)(puVar23 + -8) = 0x18001008c;
          GRsetres(0);
          local_238 = (longlong *)0x0;
          local_240 = (longlong *)0x0;
          if (local_228 != (longlong *)0x0) {
            pcVar7 = *(code **)*local_228;
            *(undefined8 *)(puVar23 + -8) = 0x1800100b4;
            iVar12 = (*pcVar7)(local_228,&DAT_180041340,&local_240);
            if (iVar12 < 0) {
              local_240 = (longlong *)0x0;
            }
          }
          if (local_240 != (longlong *)0x0) {
            local_258.lpVtbl = (IStorageVtbl *)0x0;
            pcVar7 = *(code **)(*local_240 + 0x20);
            *(undefined8 *)(puVar23 + -8) = 0x1800100e2;
            (*pcVar7)(local_240,&DAT_180042b18,&local_258);
            if (local_258.lpVtbl != (IStorageVtbl *)0x0) {
              local_250.lpVtbl = (IStorageVtbl *)0x0;
              pcVar7 = *(code **)((local_258.lpVtbl)->QueryInterface + 0x38);
              *(undefined8 *)(puVar23 + -8) = 0x1800100fd;
              iVar12 = (*pcVar7)(local_258.lpVtbl,&local_250);
              if ((-1 < iVar12) && (local_250.lpVtbl != (IStorageVtbl *)0x0)) {
                pcVar7 = *(code **)((local_250.lpVtbl)->QueryInterface + 0x18);
                *(undefined8 *)(puVar23 + -8) = 0x18001011b;
                iVar12 = (*pcVar7)(local_250.lpVtbl,1,local_220);
                while (-1 < iVar12) {
                  pcVar7 = *(code **)*local_220[0];
                  *(undefined8 *)(puVar23 + -8) = 0x180010134;
                  iVar12 = (*pcVar7)(local_220[0],&DAT_180042b18,&local_238);
                  pcVar7 = *(code **)(*local_220[0] + 0x10);
                  *(undefined8 *)(puVar23 + -8) = 0x180010140;
                  (*pcVar7)();
                  if (-1 < iVar12) break;
                  pcVar7 = *(code **)((local_250.lpVtbl)->QueryInterface + 0x18);
                  *(undefined8 *)(puVar23 + -8) = 0x180010159;
                  iVar12 = (*pcVar7)(local_250.lpVtbl,1,local_220);
                }
              }
              if (local_250.lpVtbl != (IStorageVtbl *)0x0) {
                pcVar7 = *(code **)((local_250.lpVtbl)->QueryInterface + 0x10);
                *(undefined8 *)(puVar23 + -8) = 0x18001016c;
                (*pcVar7)();
              }
            }
            if (local_258.lpVtbl != (IStorageVtbl *)0x0) {
              pcVar7 = *(code **)((local_258.lpVtbl)->QueryInterface + 0x10);
              *(undefined8 *)(puVar23 + -8) = 0x18001017b;
              (*pcVar7)();
            }
          }
          *(undefined8 *)(puVar23 + -8) = 0x18001018c;
          HVar13 = ReadClassStg((LPSTORAGE)local_248.lpVtbl,&local_178);
          local_268[0] = false;
          if ((HVar13 == 0) && (local_268[0] = false, local_238 != (longlong *)0x0)) {
            pcVar7 = *(code **)(*local_238 + 0x30);
            *(undefined8 *)(puVar23 + -8) = 0x1800101aa;
            iVar12 = (*pcVar7)(local_238,local_248.lpVtbl);
            local_268[0] = iVar12 == 0;
          }
          *(undefined8 *)(puVar23 + -8) = 0x1800101b8;
          GRsetres(uVar11);
          if (local_240 != (longlong *)0x0) {
            pcVar7 = *(code **)(*local_240 + 0x10);
            *(undefined8 *)(puVar23 + -8) = 0x1800101c8;
            (*pcVar7)();
          }
          if (local_238 != (longlong *)0x0) {
            pcVar7 = *(code **)(*local_238 + 0x10);
            *(undefined8 *)(puVar23 + -8) = 0x1800101d8;
            (*pcVar7)();
          }
        }
      }
    }
    pcVar7 = *(code **)(*local_228 + 0x10);
    *(undefined8 *)(puVar24 + -8) = 0x1800101e2;
    (*pcVar7)();
    if (local_230 != (longlong *)0x0) {
      pcVar7 = *(code **)(*local_230 + 0x10);
      *(undefined8 *)(puVar24 + -8) = 0x1800101f2;
      (*pcVar7)();
    }
    if (local_248.lpVtbl != (IStorageVtbl *)0x0) {
      p_Var6 = ((IStorageVtbl *)(local_248.lpVtbl)->QueryInterface)->Release;
      *(undefined8 *)(puVar24 + -8) = 0x180010202;
      (*p_Var6)((IStorage *)local_248.lpVtbl);
    }
    uVar32 = local_268[0];
  }
  if (0xf < local_1a0) {
    ppppuVar20 = local_1b8;
    if ((0xfff < local_1a0 + 1) &&
       (ppppuVar20 = (undefined8 ****)local_1b8[-1],
       0x1f < (ulonglong)((longlong)local_1b8 + (-8 - (longlong)ppppuVar20)))) {
                    /* WARNING: Subroutine does not return */
      *(undefined **)(puVar24 + -8) = &UNK_180010246;
      _invalid_parameter_noinfo_noreturn();
    }
    *(undefined8 *)(puVar24 + -8) = 0x18001024f;
    FUN_180035134(ppppuVar20);
  }
LAB_180010253:
  *(undefined8 *)(puVar24 + -8) = 0x180010262;
  return uVar32;
}

