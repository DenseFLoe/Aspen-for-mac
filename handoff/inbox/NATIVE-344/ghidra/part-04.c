/* RVA 0xe6f0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SimExportReport(uchar *param_1,int param_2,char *param_3)

{
  bool bVar1;
  int iVar2;
  undefined7 extraout_var;
  undefined1 *puVar3;
  undefined8 uVar4;
  char *pcVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  char *pcVar8;
  undefined1 auStack_1a8 [32];
  int local_188 [2];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_180 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_178 [8];
  uint local_170 [14];
  char local_138 [272];
  ulonglong local_28;
  
                    /* 0xe6f0  112  SimExportReport */
  local_28 = DAT_1800516d8 ^ (ulonglong)auStack_1a8;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_178);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_180);
  uVar4 = 1;
  pcVar8 = (char *)0x0;
  uVar7 = 1;
  iVar2 = FUN_180022a50(0x13,1,(char *)0x1,(uchar *)0x0);
  if (iVar2 == 0) {
    bVar1 = FUN_18002bdf0();
    uVar6 = 0;
    if ((int)CONCAT71(extraout_var,bVar1) == 0) {
      iVar2 = FUN_180022a50(0x13,1,(char *)0x2,param_1);
    }
    else {
      if (DAT_180052ec4 == 0) {
LAB_18000e76b:
        DAT_180051c00 = 4;
        FUN_180031540((undefined *)0x0,uVar4,uVar7,pcVar8);
        pcVar8 = (char *)0x0;
        iVar2 = FUN_180022a50(1,1,(char *)0x0,(uchar *)0x0);
        if (iVar2 != 0) goto LAB_18000e894;
        local_170[2] = 1;
        local_170[3] = 0;
        local_170[0xb] = 0;
        local_170[7] = 0;
        local_170[8] = 0;
        local_170[9] = 0;
        local_170[10] = 0;
        local_170[0] = 4;
        local_170[4] = 0;
        local_170[5] = 0;
        local_170[1] = 1;
        local_170[6] = 0;
        FUN_180015c10(local_170);
      }
      else {
        iVar2 = GRinqcnn();
        if (iVar2 != 2) goto LAB_18000e76b;
      }
      FUN_180008f80(local_138,"%s.ia1",APtmpfil_exref,pcVar8);
      local_188[0] = param_2;
      iVar2 = FUN_180017fe0(local_188,param_3,(FILE *)0x0,pcVar8);
      if (iVar2 == 0) goto LAB_18000e899;
      if (local_188[0] == 0xd) {
        pcVar5 = "%s.rp2";
LAB_18000e823:
        FUN_180008f80(local_138,pcVar5,APtmpfil_exref,pcVar8);
      }
      else if (local_188[0] == 0xe) {
        pcVar5 = "%s.rp1";
        goto LAB_18000e823;
      }
      if (iVar2 < 1) goto LAB_18000e899;
      iVar2 = FUN_180026510((char *)0x0,local_138);
      if (iVar2 == -1) goto LAB_18000e899;
      iVar2 = SBlocalhost();
      if (iVar2 != 0) {
        CopyFileA(local_138,(LPCSTR)param_1,0);
        goto LAB_18000e899;
      }
      puVar3 = (undefined1 *)FUN_18001a130();
      iVar2 = FUN_18002b2c0((char *)param_1,local_138,puVar3);
    }
    if (iVar2 == 0) goto LAB_18000e899;
  }
LAB_18000e894:
  uVar6 = 0x80004005;
LAB_18000e899:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_180);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_178);
  return uVar6;
}

/* RVA 0xe8e0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_18000e8e0(char *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined7 extraout_var;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar5;
  uchar *puVar6;
  undefined7 extraout_var_00;
  undefined7 uVar8;
  char *pcVar7;
  char *pcVar9;
  undefined1 auStack_168 [32];
  longlong local_148;
  longlong local_140;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_138 [16];
  CHAR local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_168;
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    return -0x7fffbffb;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_148,param_1);
  uVar8 = (undefined7)((ulonglong)param_1 >> 8);
  iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_148,'.'
                    );
  uVar4 = CONCAT71(uVar8,0x5c);
  iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_148,
                     '\\');
  if (iVar2 < iVar3) {
    iVar2 = -1;
  }
  iVar3 = GRinqgpd();
  if ((iVar3 == 0) || (iVar3 = GRinqQRs(), iVar3 == 0)) {
    DAT_180051c00 = 0xb;
    FUN_180031540((undefined *)0x0,uVar4,param_3,param_4);
    iVar3 = FUN_180022a50(1,1,(char *)0x0,(uchar *)0x0);
    if (iVar3 == 0) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_140);
      if (iVar2 != -1) {
        pCVar5 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                           ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_148,(int)local_138);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_140,
                   pCVar5);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_138);
      }
      puVar6 = (uchar *)ATL::CSimpleStringT<char,1>::GetBuffer
                                  ((CSimpleStringT<char,1> *)&local_140,*(int *)(local_140 + -0x10))
      ;
      iVar3 = FUN_180022a50(2,1,(char *)0x1,puVar6);
      if (iVar3 == 0) {
        if (iVar2 == -1) {
          iVar2 = MVGetProductCode();
          pcVar7 = ".aprpdf";
          if (iVar2 != 2) {
            pcVar7 = ".appdf";
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_148,
                     pcVar7);
        }
        pcVar7 = ATL::CSimpleStringT<char,1>::GetBuffer
                           ((CSimpleStringT<char,1> *)&local_148,*(int *)(local_148 + -0x10));
        iVar2 = MVGetProductCode();
        pcVar9 = "%s.aprpdf";
        if (iVar2 != 2) {
          pcVar9 = "%s.appdf";
        }
        FUN_180008f80(local_128,pcVar9,APtmpfil_exref,puVar6);
        iVar2 = SBlocalhost();
        if (iVar2 == 0) {
          iVar2 = FUN_180010b70(pcVar7,local_128);
        }
        else {
          bVar1 = FUN_180025b70((char *)open_path_exref,local_128,pcVar7,(char *)0x0);
          iVar2 = -0x7fffbffb;
          if ((int)CONCAT71(extraout_var_00,bVar1) != 0) {
            iVar2 = 0;
          }
        }
        ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_148,-1);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_140);
        goto LAB_18000eb86;
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_140);
    }
    iVar2 = -0x7fffbffb;
  }
  else {
    if (iVar2 == -1) {
      iVar2 = MVGetProductCode();
      pcVar7 = ".aprpdf";
      if (iVar2 != 2) {
        pcVar7 = ".appdf";
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_148,pcVar7)
      ;
    }
    pcVar7 = ATL::CSimpleStringT<char,1>::GetBuffer
                       ((CSimpleStringT<char,1> *)&local_148,*(int *)(local_148 + -0x10));
    iVar2 = MVGetProductCode();
    pcVar9 = "%s.aprpdf";
    if (iVar2 != 2) {
      pcVar9 = "%s.appdf";
    }
    uVar4 = GRinqfnm();
    FUN_180008f80(local_128,pcVar9,uVar4,param_4);
    iVar2 = SBlocalhost();
    if (iVar2 == 0) {
      iVar2 = FUN_180010b70(pcVar7,local_128);
      ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_148,-1);
    }
    else {
      bVar1 = FUN_180025b70((char *)open_path_exref,local_128,pcVar7,(char *)0x0);
      iVar2 = -0x7fffbffb;
      if ((int)CONCAT71(extraout_var,bVar1) != 0) {
        iVar2 = 0;
      }
      ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_148,-1);
    }
  }
LAB_18000eb86:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_148);
  return iVar2;
}

/* RVA 0xebd0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18000ebd0(char *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  DWORD DVar2;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar3;
  undefined1 *puVar4;
  undefined8 uVar5;
  char *pcVar6;
  LPCSTR pCVar7;
  code *pcVar8;
  undefined1 auStack_198 [32];
  char *local_178;
  LPCSTR local_170;
  LPCSTR local_168;
  uint local_160 [14];
  char local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_198;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_170,param_1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_170,'.');
  pCVar3 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                     ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_170,
                      (int)&local_178);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_170,pCVar3);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_178);
  iVar1 = MVGetProductCode();
  pcVar6 = ".aprinp";
  if (iVar1 == 1) {
    pcVar6 = ".inp";
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_170,pcVar6);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_168);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_168,"%s.inm");
  uVar5 = 0;
  pCVar7 = local_168;
  CopyFileA(local_170,local_168,0);
  DVar2 = GetFileAttributesA(local_168);
  if ((DVar2 & 1) != 0) {
    pCVar7 = (LPCSTR)(ulonglong)(DVar2 ^ 1);
    SetFileAttributesA(local_168,DVar2 ^ 1);
  }
  DAT_180051c00 = 10;
  FUN_180031540((undefined *)0x0,pCVar7,uVar5,param_4);
  uVar5 = 0;
  local_160[2] = 1;
  local_160[3] = 0;
  local_160[0xb] = 0;
  local_160[0] = 0x1a;
  local_160[7] = 0;
  local_160[8] = 0;
  local_160[9] = 0;
  local_160[10] = 0;
  local_160[4] = 0;
  local_160[5] = 0;
  local_160[1] = 1;
  local_160[6] = 0;
  FUN_180015c10(local_160);
  FUN_180008f30("");
  iVar1 = MVGetProductCode();
  pcVar6 = ".aprbkp";
  if (iVar1 == 1) {
    pcVar6 = ".bkp";
  }
  pcVar8 = APtmpfil_exref;
  FUN_180008f80(local_128,&DAT_18003f9b0,APtmpfil_exref,pcVar6);
  iVar1 = GRinqerr();
  if (iVar1 == 0) {
    iVar1 = GRinqsme();
    if (iVar1 != 0) goto LAB_18000edf9;
    iVar1 = FUN_180026510((char *)0x0,local_128);
    if (iVar1 != -1) {
      FUN_18002c760(0,1,(char *)pcVar8,pcVar6);
      iVar1 = SBlocalhost();
      if (iVar1 != 0) {
        FUN_180025b70((char *)0x0,local_128,param_1,(char *)0x0);
LAB_18000ed9e:
        FUN_180025fb0((char *)0x0,local_128);
        goto LAB_18000ee6d;
      }
      puVar4 = (undefined1 *)FUN_18001a130();
      iVar1 = FUN_18002b2c0(param_1,local_128,puVar4);
      if (iVar1 == 0) goto LAB_18000ed9e;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_178);
      uVar5 = MVGetI18nProductName();
      pcVar6 = (char *)GetSorResStringEx(0xfa6);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_178,pcVar6,
                 uVar5);
      goto LAB_18000ee30;
    }
  }
  else {
LAB_18000edf9:
    SimSendMainWndMessage(0x539,0,0);
    SimSendMainWndMessage(0x539,0,0);
    pcVar6 = (char *)GetSorResStringEx(0xfa9);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_178,pcVar6);
LAB_18000ee30:
    pcVar6 = (char *)0x0;
    uVar5 = 0xffffffff;
    MMAfxMessageBox(local_178,0,-1,0);
    FUN_180025fb0((char *)0x0,local_128);
    FUN_180025e00((char *)APtmpfil_exref,0,uVar5,pcVar6);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_178);
  }
  uVar5 = 0x80004005;
LAB_18000ee6d:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_168);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_170);
  return uVar5;
}

/* RVA 0xeeb0 */
void FUN_18000eeb0(void)

{
  SimSendMainWndMessage(0x541,0,0);
  return;
}

/* RVA 0xeec0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18000eec0(char *param_1)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar5;
  int *piVar6;
  char *pcVar7;
  undefined1 *puVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  longlong lVar11;
  char *pcVar12;
  code *pcVar13;
  undefined1 auStack_318 [32];
  CHAR *local_2f8;
  char *local_2d8;
  char *local_2d0;
  char *local_2c8;
  char *local_2c0;
  char *local_2b8;
  char *local_2b0;
  undefined8 local_2a8;
  char *local_2a0;
  undefined8 local_298;
  LPCSTR local_290;
  LPSTR local_288;
  uint local_280 [4];
  undefined8 local_270;
  undefined4 local_268;
  undefined8 local_264;
  undefined8 uStack_25c;
  undefined4 local_254;
  char local_248 [272];
  CHAR local_138 [272];
  ulonglong local_28;
  
  local_28 = DAT_1800516d8 ^ (ulonglong)auStack_318;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_290);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2b0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_298);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2a8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2c8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2a0);
  iVar2 = SBlocalhost();
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_290,param_1);
  if (*param_1 != '\0') {
    lVar1 = -1;
    do {
      lVar11 = lVar1;
      lVar1 = lVar11 + 1;
    } while (param_1[lVar11 + 1] != '\0');
    if (param_1[lVar11 + 2] != '\0') {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2b0,
                 param_1 + lVar11 + 2);
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2c0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2b8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2d8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2c0,"%s.inm",
             APtmpfil_exref);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2b8,"%s.pro",
             APtmpfil_exref);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2d8,"%s.err",
             APtmpfil_exref);
  GetFullPathNameA(local_290,0x104,local_138,&local_288);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2c8,local_138);
  iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2c8,'.'
                    );
  iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2c8,
                     '\\');
  if ((iVar4 <= iVar3) && (iVar3 != -1)) {
    pCVar5 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                       ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2c8,
                        (int)&local_2d0);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2c8,pCVar5);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2d0);
  }
  iVar3 = MVGetProductCode();
  pcVar12 = ".aprbkp";
  if (iVar3 == 1) {
    pcVar12 = ".bkp";
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2c8,pcVar12);
  pcVar12 = ATL::CSimpleStringT<char,1>::GetBufferSetLength
                      ((CSimpleStringT<char,1> *)&local_2a8,0x104);
  iVar3 = FUN_1800269c0("atp3.exe",pcVar12);
  ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_2a8,-1);
  piVar6 = (int *)SEGetSettingValue("pro2blockdata",0);
  if ((piVar6 == (int *)0x0) || (*piVar6 == 0)) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2a0,"-noall "
              );
  }
  pcVar12 = local_2b8;
  if (iVar2 == 0) {
    pcVar7 = (char *)FUN_18001a130();
    FUN_18002b360(local_138,pcVar12,pcVar7);
    local_2f8 = local_2b8;
  }
  else {
    local_2f8 = local_138;
  }
  pcVar12 = "%s %s\"%s\" \"%s\" \"%s\"";
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_298,
             "%s %s\"%s\" \"%s\" \"%s\"");
  DAT_180051c00 = 0x28;
  FUN_180031540((undefined *)0x0,pcVar12,local_2a8,local_2a0);
  local_270 = local_298;
  uVar9 = 0;
  local_280[2] = 1;
  local_280[3] = 0;
  local_264 = 0;
  uStack_25c = 0;
  local_254 = 0;
  local_280[0] = 0x28;
  local_280[1] = 1;
  local_268 = 0;
  FUN_180015c10(local_280);
  FUN_180008f30("");
  pcVar13 = APtmpfil_exref;
  FUN_180008f80(local_248,"%s.bkp",APtmpfil_exref,local_2a0);
  iVar4 = FUN_180026510((char *)0x0,local_248);
  if (iVar4 == -1) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2d0);
    uVar9 = MVGetI18nProductName();
    uVar10 = 0xfa7;
    if (iVar3 == 0) {
      uVar10 = 0xfa6;
    }
    pcVar12 = (char *)GetSorResStringEx(uVar10);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2d0,pcVar12,
               uVar9);
    MMAfxMessageBox(local_2d0,0,-1,0);
    if (iVar2 == 0) {
      FUN_180025fb0((char *)0x0,local_2b8);
      FUN_180025fb0((char *)0x0,local_2c0);
      FUN_180025fb0((char *)0x0,local_2d8);
    }
    else {
      remove(local_2c0);
      remove(local_2d8);
    }
LAB_18000f3d1:
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2d0);
    uVar9 = 0x80004005;
  }
  else {
    FUN_18002c760(0,1,(char *)pcVar13,local_2a0);
    if (iVar2 == 0) {
      FUN_180025fb0((char *)0x0,local_2b8);
      FUN_180025fb0((char *)0x0,local_2c0);
      puVar8 = (undefined1 *)FUN_18001a130();
      iVar2 = FUN_18002b2c0(local_2c8,local_248,puVar8);
      if (iVar2 != 0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2d0);
        uVar9 = MVGetI18nProductName();
        pcVar12 = (char *)GetSorResStringEx(0xfa6);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2d0,
                   pcVar12,uVar9);
        pcVar12 = (char *)0x0;
        uVar9 = 0xffffffff;
        MMAfxMessageBox(local_2d0,0,-1,0);
        FUN_180025fb0((char *)0x0,local_248);
        FUN_180025fb0((char *)0x0,local_2d8);
        FUN_180025e00((char *)APtmpfil_exref,0,uVar9,pcVar12);
        goto LAB_18000f3d1;
      }
      iVar2 = FUN_180026510((char *)0x0,local_2d8);
      pcVar7 = local_2b0;
      pcVar12 = local_2d8;
      if (iVar2 != -1) {
        puVar8 = (undefined1 *)FUN_18001a130();
        FUN_18002b2c0(pcVar7,pcVar12,puVar8);
      }
      FUN_180025fb0((char *)0x0,local_2d8);
    }
    else {
      FUN_180025b70((char *)0x0,local_248,local_2c8,(char *)0x0);
      FUN_180025b70((char *)0x0,local_2d8,local_2b0,(char *)0x0);
      remove(local_2c0);
      remove(local_2d8);
    }
    uVar10 = GetSorResStringEx(0xfa8);
    gxDriveDialog2("ShowFileDialog",2,local_2b0,uVar10);
    FUN_180025fb0((char *)0x0,local_2b0);
    FUN_180025fb0((char *)0x0,local_248);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2d8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2b8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2c0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2a0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2c8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2a8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_298);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2b0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_290);
  return uVar9;
}

/* RVA 0xf470 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_18000f470(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStack_98 [32];
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined4 local_60;
  undefined4 local_58;
  uint local_48 [4];
  undefined8 local_38;
  undefined4 local_30;
  undefined8 local_2c;
  undefined8 uStack_24;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_98;
  lVar2 = GetGlobalPointer();
  if (lVar2 == 0) {
    DAT_180051c00 = 7;
    FUN_180031540((undefined *)0x0,param_2,param_3,param_4);
    iVar1 = FUN_180022a50(1,1,(char *)0x0,(uchar *)0x0);
    if (iVar1 == 0) {
      local_48[2] = 1;
      local_48[3] = 0;
      local_1c = 0;
      local_30 = 0;
      local_2c = 0;
      uStack_24 = 0;
      local_48[0] = 7;
      local_48[1] = 1;
      local_38 = param_1;
      FUN_180015c10(local_48);
      uVar3 = 1;
    }
    else {
      uVar3 = 0x80004005;
    }
  }
  else {
    uVar3 = GetSorResStringEx(0x1c7);
    uVar4 = MVGetI18nProductName();
    local_58 = 0;
    local_60 = 1;
    local_68 = 0;
    local_70 = 0;
    local_78 = 0;
    open_message_box(uVar4,uVar3,&DAT_1800408b0,0);
    uVar3 = 0;
  }
  return uVar3;
}

/* RVA 0xf570 */
undefined4 SimGetConnectFailed(void)

{
                    /* 0xf570  105  SimGetConnectFailed */
  return DAT_180051dd0;
}

/* RVA 0xf580 */
void SimGetConnectInfo(undefined4 *param_1,char *param_2,char *param_3,char *param_4,char *param_5,
                      undefined4 *param_6,int param_7)

{
  int iVar1;
  
                    /* 0xf580  106  SimGetConnectInfo */
  iVar1 = param_7 + -1;
  *param_1 = DAT_18004f780;
  if (0x4f < iVar1) {
    iVar1 = 0x4f;
  }
  strncpy(param_2,&DAT_18004f784,0x4f);
  param_2[iVar1] = '\0';
  strncpy(param_3,&DAT_18004f7d4,0x4f);
  param_3[iVar1] = '\0';
  strncpy(param_4,&DAT_18004f824,0x4f);
  param_4[iVar1] = '\0';
  strncpy(param_5,&DAT_18004f874,0x4f);
  param_5[iVar1] = '\0';
  *param_6 = DAT_18004f8c4;
  return;
}

/* RVA 0xf670 */
int SimGetHostTypeName(uint param_1,undefined8 *param_2,longlong *param_3,uint *param_4,
                      uint *param_5)

{
  int iVar1;
  char *_Str1;
  
                    /* 0xf670  83  SimGetHostTypeName
                       0xf670  174  SimSBgetcsect */
  if (param_1 == 0xffffffff) {
    DAT_180051fe0 = SBcntcsect();
    if (DAT_180051fe0 == 0) {
      return -1;
    }
    if (DAT_180051fe8 != (void *)0x0) {
      free(DAT_180051fe8);
      DAT_180051fe8 = (void *)0x0;
    }
    DAT_180051fe8 = malloc((longlong)DAT_180051fe0 * 0x32);
    if (DAT_180051fe8 == (void *)0x0) {
      return -1;
    }
    iVar1 = SBreacsect(DAT_180051fe8);
    if (iVar1 != 0) {
      free(DAT_180051fe8);
      return -1;
    }
    param_1 = 0;
  }
  else if (param_1 == 0xfffffffe) {
    if (DAT_180051fe8 == (void *)0x0) {
      return -1;
    }
    free(DAT_180051fe8);
    DAT_180051fe8 = (void *)0x0;
    return -1;
  }
  if (DAT_180051fe0 <= (int)param_1) {
    return -1;
  }
  _Str1 = (char *)((longlong)(int)param_1 * 0x32 + (longlong)DAT_180051fe8);
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = _Str1;
  }
  if (param_3 != (longlong *)0x0) {
    *param_3 = (longlong)(_Str1 + 9);
  }
  if (param_4 != (uint *)0x0) {
    iVar1 = _stricmp(_Str1,(char *)commsect_exref);
    *param_4 = (uint)(iVar1 == 0);
  }
  if (param_5 != (uint *)0x0) {
    *param_5 = (uint)((*(uint *)(submitdata_exref + 0x1470) >> (param_1 & 0x1f) & 1) != 0);
  }
  return param_1 + 1;
}

/* RVA 0xf680 */
void FUN_18000f680(char *param_1,char *param_2,int param_3)

{
  size_t _Count;
  
  _Count = (size_t)(param_3 + -1);
  strncpy(param_1,&DAT_180051d30,_Count);
  strncpy(param_2,&DAT_180051d80,_Count);
  if (*param_1 == '\0') {
    strncpy(param_1,"None",_Count);
    strncpy(param_2,"None",_Count);
  }
  return;
}

/* RVA 0xf700 */
undefined4 SimGetReportSummary(void)

{
  undefined8 uVar1;
  undefined4 uVar2;
  
                    /* 0xf700  68  SimGetReportSummary */
  uVar1 = FUN_180020230(3,0);
  uVar2 = 0x80004005;
  if ((int)uVar1 == 1) {
    uVar2 = 0;
  }
  return uVar2;
}

/* RVA 0xf730 */
bool SimGetRunOption(undefined4 param_1)

{
  bool bVar1;
  undefined7 extraout_var;
  
                    /* 0xf730  75  SimGetRunOption */
  switch(param_1) {
  case 0:
    return *(int *)pseudobatch_exref != 0;
  case 1:
    bVar1 = FUN_18002bdf0();
    if ((int)CONCAT71(extraout_var,bVar1) != 0) {
      return *(int *)partial_results_exref != 0;
    }
    break;
  case 2:
    return *(int *)runanyway_exref == 0;
  case 3:
  case 4:
    return *(int *)load_reg_result_exref != 0;
  case 5:
    return *(int *)load_estimation_result_exref != 0;
  case 6:
    return *(int *)load_retrieved_result_exref != 0;
  }
  return false;
}

/* RVA 0xf800 */
undefined4 SimGetSummaryHeader(void)

{
  undefined8 uVar1;
  undefined4 uVar2;
  
                    /* 0xf800  69  SimGetSummaryHeader */
  uVar1 = FUN_180020230(4,0);
  uVar2 = 0x80004005;
  if ((int)uVar1 == 1) {
    uVar2 = 0;
  }
  return uVar2;
}

/* RVA 0xf830 */
void FUN_18000f830(void)

{
  if (DAT_180051dd4 != 0) {
    Ordinal_116();
    DAT_180051dd4 = 0;
  }
  CSimEventsThread::SimEventHangup();
  return;
}

/* RVA 0xf860 */
int SimHostTypeCount(void)

{
  uint uVar1;
  int iVar2;
  uint local_res8 [2];
  uint local_res10 [2];
  longlong local_res18;
  undefined8 local_res20;
  
                    /* 0xf860  82  SimHostTypeCount */
  iVar2 = 0;
  for (uVar1 = FUN_180019fe0(0xffffffff,&local_res20,&local_res18,local_res10,local_res8);
      uVar1 != 0xffffffff;
      uVar1 = FUN_180019fe0(uVar1,&local_res20,&local_res18,local_res10,local_res8)) {
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}

/* RVA 0xf8c0 */
ulonglong SimInEOMode(void)

{
  int iVar1;
  ulonglong uVar2;
  
                    /* 0xf8c0  121  SimInEOMode */
  uVar2 = GRinqiwp();
  if ((int)uVar2 == 0) {
    return uVar2;
  }
  iVar1 = GRinqrcl();
  if (iVar1 == 1) {
    iVar1 = GRinqeop();
    return (ulonglong)(iVar1 == 2);
  }
  return 0;
}

/* RVA 0xf910 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SimInitialize(IID *param_1,IUnknown *param_2)

{
  UINT ui;
  IUnknown *pUnk;
  int iVar1;
  HRESULT HVar2;
  char *pcVar3;
  undefined8 uVar4;
  LPWSTR lpWideCharStr;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 auStackY_118 [24];
  undefined8 uStackY_100;
  WCHAR local_e8 [8];
  IStream *local_c8 [2];
  CArchive local_b8 [24];
  CSimpleStringT<char,1> local_a0 [8];
  byte local_98;
  UINT *local_80;
  UINT *local_78;
  COleStreamFile local_48 [56];
  ulonglong local_10;
  
                    /* 0xf910  41  SimInitialize */
  local_10 = DAT_1800516d8 ^ (ulonglong)local_c8;
  uStackY_100 = 0x18000f956;
  iVar1 = FUN_18002e060();
  uStackY_100 = 0x18000f964;
  DAT_18004f724 = GetGlobalPointer("APWN_TID");
  if (param_2 != (IUnknown *)0x0) {
    uStackY_100 = 0x18000f982;
    DAT_180051bb0 = param_2;
    (*param_2->lpVtbl->AddRef)(param_2);
    pUnk = DAT_180051bb0;
    uStackY_100 = 0x18000f99c;
    HVar2 = CreateStreamOnHGlobal((HGLOBAL)0x0,1,&DAT_180051bb8);
    if (-1 < HVar2) {
      uStackY_100 = 0x18000f9c8;
      HVar2 = CoMarshalInterface(DAT_180051bb8,(IID *)&DAT_1800410e8,pUnk,3,(LPVOID)0x0,1);
      if (HVar2 < 0) {
        uStackY_100 = 0x18000f9d9;
        (*DAT_180051bb8->lpVtbl->Release)(DAT_180051bb8);
        DAT_180051bb8 = (LPSTREAM)0x0;
      }
    }
  }
  if (iVar1 < 0) {
    uStackY_100 = 0x18000f9ef;
    pcVar3 = (char *)GetSorResStringEx(0x1b6);
    uStackY_100 = 0x18000fa00;
    MMAfxMessageBox(pcVar3,0,-1,0);
  }
  uStackY_100 = 0x18000fa0d;
  uVar4 = FUN_18000d050(1,(longlong *)param_1);
  puVar5 = auStackY_118 + 0x20;
  puVar6 = auStackY_118 + 0x20;
  if ((int)uVar4 == 0) {
    if (param_1 != (IID *)0x0) {
      if (DAT_180051bb0 != (IUnknown *)0x0) {
        uStackY_100 = 0x18000fa39;
        (*DAT_180051bb0->lpVtbl[1].QueryInterface)(DAT_180051bb0,param_1,(void **)0x1);
      }
      local_c8[0] = (IStream *)0x0;
      lpWideCharStr = local_e8;
      if (lpWideCharStr == (LPWSTR)0x0) {
        lpWideCharStr = (LPWSTR)0x0;
      }
      else {
        local_e8[0] = L'\0';
        iVar1 = MultiByteToWideChar(0,0,"ControlPanel",-1,lpWideCharStr,0xd);
        if (iVar1 == 0) {
          lpWideCharStr = (LPWSTR)0x0;
        }
      }
      (**(code **)(*(longlong *)param_1 + 0x20))(param_1,lpWideCharStr,0,0x10);
      puVar5 = auStackY_118;
      if (local_c8[0] != (IStream *)0x0) {
        COleStreamFile::COleStreamFile(local_48,local_c8[0]);
        CArchive::CArchive(local_b8,(CFile *)local_48,1,0x1000,(void *)0x0);
        if ((local_98 & 1) == 0) {
          pcVar3 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64(local_a0);
                    /* WARNING: Subroutine does not return */
          AfxThrowArchiveException(4,pcVar3);
        }
        if (local_78 < local_80 + 1) {
          CArchive::FillBuffer(local_b8,((int)local_80 - (int)local_78) + 4);
        }
        ui = *local_80;
        local_80 = local_80 + 1;
        if (ui != 0) {
          DAT_180051c20 = SysAllocStringLen((OLECHAR *)0x0,ui);
          CArchive::Read(local_b8,DAT_180051c20,ui * 2);
        }
        CArchive::Close(local_b8);
        (*local_c8[0]->lpVtbl->Release)(local_c8[0]);
        CArchive::~CArchive(local_b8);
        COleStreamFile::~COleStreamFile(local_48);
        puVar5 = auStackY_118;
      }
    }
    uVar4 = 0;
    puVar6 = puVar5;
  }
  *(undefined8 *)(puVar6 + -8) = 0x18000fb75;
  return uVar4;
}

/* RVA 0xfbc0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SimInputSummary(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_168 [32];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_148 [8];
  undefined8 local_140;
  undefined1 local_138;
  CHAR local_128 [272];
  ulonglong local_18;
  
                    /* 0xfbc0  144  SimInputSummary */
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_168;
  local_140 = DAT_180040988;
  local_138 = DAT_180040990;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_148,(char *)&local_140);
  GetEditorTempTxtFileName(local_128);
  iVar1 = export_MM_file_MAX(2);
  if (iVar1 == 0) {
    FUN_180009bc0(local_128,0,0,(LPCSTR)0x0);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x80004005;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_148);
  return uVar2;
}

/* RVA 0xfc70 */
ulonglong SimInstantiateBlock(undefined8 param_1,undefined8 param_2,int *param_3,char *param_4)

{
  undefined4 *puVar1;
  ulonglong uVar2;
  int *piVar3;
  char *pcVar4;
  undefined4 local_res10 [2];
  undefined4 local_res18;
  
                    /* 0xfc70  109  SimInstantiateBlock */
  local_res10[0] = 0xffffffff;
  local_res18 = 0;
  puVar1 = (undefined4 *)SEGetSettingValue("editinput");
  if (puVar1 == (undefined4 *)0x0) {
    GRsetigb(param_1);
    uVar2 = SimMain((char *)0x1d,(IMAGE_DOS_HEADER *)0x0,param_3,param_4);
    return uVar2;
  }
  local_res10[0] = *puVar1;
  pcVar4 = (char *)0x0;
  piVar3 = (int *)0x0;
  SESetSettingValue("editinput");
  GRsetigb(param_1);
  uVar2 = SimMain((char *)0x1d,(IMAGE_DOS_HEADER *)0x0,piVar3,pcVar4);
  SESetSettingValue("editinput",local_res10,0,0,0);
  return uVar2 & 0xffffffff;
}

/* RVA 0xfd20 */
undefined4 SimIsMultiThread(void)

{
                    /* 0xfd20  151  SimIsMultiThread */
  return DAT_180051c18;
}

/* RVA 0xfd30 */
void SimLoadResults(undefined8 param_1,undefined8 param_2,int *param_3,char *param_4)

{
  longlong lVar1;
  
                    /* 0xfd30  100  SimLoadResults */
  lVar1 = GRchkitm(0x40);
  if (lVar1 == 0) {
    return;
  }
  SimMain((char *)0x3,(IMAGE_DOS_HEADER *)0x0,param_3,param_4);
  return;
}

/* RVA 0xfd60 */
undefined4 SimMTRefreshed(void)

{
                    /* 0xfd60  178  SimMTRefreshed */
  return DAT_18004f720;
}

/* RVA 0xfd70 */
ulonglong SimMain(char *param_1,IMAGE_DOS_HEADER *param_2,int *param_3,char *param_4)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined4 extraout_var_08;
  longlong lVar16;
  undefined8 *puVar17;
  BSTR pOVar18;
  char *_Str1;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  undefined7 extraout_var_01;
  undefined7 extraout_var_02;
  undefined7 extraout_var_03;
  undefined7 extraout_var_04;
  undefined7 extraout_var_05;
  undefined7 extraout_var_06;
  undefined7 extraout_var_07;
  IMAGE_DOS_HEADER *pIVar19;
  char *pcVar20;
  int *piVar21;
  ulonglong uVar22;
  int local_res8 [2];
  char *local_res18;
  char *local_res20;
  undefined8 in_stack_ffffffffffffffb0;
  
                    /* 0xfd70  40  SimMain */
  uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffffb0 >> 0x20);
  iVar5 = 0;
  uVar7 = (uint)param_1;
  uVar22 = (ulonglong)(int)uVar7;
  pIVar19 = param_2;
  if ((uVar7 - 1 & 0xfffffffb) == 0) {
    local_res8[0] = 0;
    param_3 = local_res8;
    param_1 = (char *)0x552;
    pIVar19 = (IMAGE_DOS_HEADER *)(ulonglong)(uVar7 == 5);
    SimSendMainWndMessage(0x552,pIVar19,param_3);
    if (local_res8[0] != 0) {
      return 0x80004005;
    }
    if (uVar7 != 1) goto LAB_18000fdd2;
LAB_18000fde2:
    uVar9 = SimInEOMode();
    if ((int)uVar9 != 0) {
      if (uVar7 == 1) {
        iVar4 = GRinqsms();
        if (((iVar4 == 0) || (iVar4 = GRinqsmf(), iVar4 != 0)) && (iVar4 = GRinqmtf(), iVar4 == 0))
        {
          iVar5 = GRinqautorun();
          if (((iVar5 == 1) && (iVar5 = GRinqpgc(), iVar5 == 0)) &&
             (iVar5 = GRinqeorsl(), iVar5 != 0)) {
            return 0x80004005;
          }
LAB_18000ffa7:
          uVar6 = SimEORun(param_2->e_magic);
          return CONCAT44(extraout_var_08,uVar6);
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
        iVar4 = GRinqsmstrat();
        if (iVar4 == 1) {
          uVar10 = GetSorResStringEx(0x1bc);
          uVar11 = GetSorResStringEx(0x1bb);
          uVar12 = GetSorResStringEx(0x1ba);
          uVar13 = GetSorResStringEx(0x1b9);
          uVar14 = GetSorResStringEx(0x1b8);
          uVar15 = GetSorResStringEx(0x1b7);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
                     "%s\n%s\n%s\n\n%s\n%s\n%s",uVar15,uVar14,uVar13,uVar12,uVar11,uVar10);
          uVar6 = (undefined4)((ulonglong)uVar10 >> 0x20);
        }
        else {
          uVar10 = GetSorResStringEx(0x1bc);
          uVar11 = GetSorResStringEx(0x1bb);
          uVar12 = GetSorResStringEx(0x1ba);
          uVar13 = GetSorResStringEx(0x1bd);
          uVar14 = GetSorResStringEx(0x1be);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
                     "%s\n%s\n\n%s\n%s\n%s",uVar14,uVar13,uVar12,uVar11,uVar10);
        }
        param_4 = (char *)0x0;
        param_3 = (int *)0xffffffff;
        pIVar19 = (IMAGE_DOS_HEADER *)0x33;
        iVar4 = MMAfxMessageBox(local_res20,0x33,-1,0);
        param_1 = (char *)&local_res20;
        if (iVar4 == 2) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_1);
          return 0x80004005;
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_1);
        if (iVar4 == 7) goto LAB_18000ffa7;
      }
      else {
        if (uVar7 == 5) {
          uVar22 = FUN_18000e0d0();
          return uVar22;
        }
        if (uVar7 == 0x33) {
          uVar22 = FUN_18000d8f0();
          return uVar22;
        }
      }
    }
  }
  else {
LAB_18000fdd2:
    if ((uVar7 == 5) || (uVar7 == 0x33)) goto LAB_18000fde2;
  }
  bVar3 = false;
  bVar2 = false;
  bVar1 = false;
  if (DAT_180051c18 == 0) {
    pcVar20 = pIVar19->e_magic;
    if (uVar7 != 9) goto LAB_18000ffd5;
  }
  else {
    if (uVar7 != 10) {
      return 0x80004005;
    }
LAB_18000ffd5:
    param_1 = "AnalysisForm";
    lVar16 = GetGlobalPointer();
    if (lVar16 != 0) {
      if (0xc < uVar7 - 10) {
switchD_180010002_caseD_d:
        uVar10 = 0x1c0;
LAB_180010009:
        uVar10 = GetSorResStringEx(uVar10);
        uVar11 = MVGetI18nProductName();
        open_message_box(uVar11,uVar10,&DAT_1800408b0,0,0,0,0,CONCAT44(uVar6,1),0);
        return 0;
      }
      pIVar19 = &IMAGE_DOS_HEADER_180000000;
      param_1 = (char *)((ulonglong)(&switchD_180010002::switchdataD_18001082c)[(int)(uVar7 - 10)] +
                        0x180000000);
      switch(uVar7) {
      default:
        break;
      case 0xb:
        uVar10 = 0x1bf;
        goto LAB_180010009;
      case 0xd:
      case 0xe:
      case 0xf:
      case 0x10:
      case 0x11:
        goto switchD_180010002_caseD_d;
      }
    }
    if (uVar7 == 0xc) {
      uVar10 = FUN_18000d050(0,(longlong *)0x0);
      if ((int)uVar10 == 0) {
        FUN_180019330(0);
        return 0;
      }
      return 0;
    }
    if (uVar7 == 10) {
      GRsetust(1);
      return 0;
    }
    pcVar20 = pIVar19->e_magic;
    if (uVar7 == 0xb) {
      uVar22 = SimInEOMode();
      if ((int)uVar22 != 0) {
        PostMainWndMessage(0x545,"EOReinit",0);
        return 0;
      }
      FUN_180019330(1);
      uVar7 = 0;
      if (DAT_180052ce4 == 1) {
        uVar7 = 0x80004005;
      }
      return (ulonglong)uVar7;
    }
  }
  if (uVar7 - 0xf < 3) {
    PostMainWndMessage(0x545,"Batch Submit",0);
    return 0;
  }
  if (uVar7 == 0x12) {
    SimInputSummary();
    return 0;
  }
  if (uVar7 == 0x13) {
    FUN_18000cb60();
    return 0;
  }
  if (uVar7 == 0x14) {
    PostMainWndMessage(0x545,"Run Settings",0);
    return 0;
  }
  if (uVar7 == 0x15) {
    FUN_1800143f0(param_1,pcVar20,param_3,param_4);
    return 0;
  }
  if (uVar7 == 0x16) {
    SimDisplayReport(0,(char *)0x0,0);
    return 0;
  }
  if (uVar7 == 0x17) {
    puVar17 = operator_new(0x18);
    if (puVar17 != (undefined8 *)0x0) {
      puVar17[1] = 0;
      *(undefined4 *)(puVar17 + 2) = 1;
      pOVar18 = SysAllocString(L"PDBActivateDlg");
      *puVar17 = pOVar18;
      if (pOVar18 != (BSTR)0x0) {
        uVar7 = FUN_1800090b0(pOVar18);
        LOCK();
        piVar21 = (int *)(puVar17 + 2);
        iVar5 = *piVar21;
        *piVar21 = *piVar21 + -1;
        UNLOCK();
        if (iVar5 == 1) {
          if ((BSTR)*puVar17 != (BSTR)0x0) {
            SysFreeString((BSTR)*puVar17);
            *puVar17 = 0;
          }
          if ((void *)puVar17[1] != (void *)0x0) {
            operator_delete__((void *)puVar17[1]);
            puVar17[1] = 0;
          }
          FUN_180001300(puVar17);
        }
        return (ulonglong)uVar7;
      }
    }
                    /* WARNING: Subroutine does not return */
    FUN_18003c7f0(0x8007000e);
  }
  if (uVar7 == 0x18) {
    PostMainWndMessage(0x545,"PDBGet",0);
    return 0;
  }
  if (uVar7 == 0x19) {
    PostMainWndMessage(0x545,"PDBPut",0);
    return 0;
  }
  if (uVar7 == 0x1a) {
    uVar22 = FUN_18000ebd0(param_2->e_magic,pcVar20,param_3,param_4);
    return uVar22;
  }
  if (uVar7 == 0x28) {
    uVar22 = FUN_18000eec0(param_2->e_magic);
    return uVar22;
  }
  if (uVar7 == 0x1b) {
    uVar11 = 0;
    uVar10 = 0x101b;
    SimReflect(2,0x101b,0);
    uVar7 = FUN_18000e8e0(param_2->e_magic,uVar10,uVar11,param_4);
    SimSendMainWndMessage(0x540,0x101b,0);
    return (ulonglong)uVar7;
  }
  if (uVar7 == 0x1c) {
    iVar4 = GRinqlcp();
    if (iVar4 == 0) {
      return 0;
    }
    iVar4 = GRinqcnn();
    if (iVar4 == 0) {
      return 0;
    }
    GRsetpri();
    GRsetigb();
  }
  else if (uVar7 == 0x1d) {
    GRsetpri();
    _Str1 = (char *)GRinqigb();
    if (_Str1 == (char *)0x0) {
LAB_180010308:
      iVar4 = GRinqgcp();
      if (iVar4 != 0) goto LAB_18001060b;
    }
    else {
      pcVar20 = "########";
      iVar4 = strcmp(_Str1,"########");
      if (iVar4 != 0) goto LAB_180010308;
    }
    GRsetedt();
  }
  else {
    GRsetpri();
    GRsetigb();
    if ((uVar7 < 0x28) && ((0x8680000000U >> (uVar22 & 0x3f) & 1) != 0)) {
      DAT_180051c10 = 0;
      if ((param_2 != (IMAGE_DOS_HEADER *)0x0) && (param_2->e_magic[0] != '\0')) {
        pcVar20 = param_2->e_magic;
        iVar4 = _stricmp("solve",param_2->e_magic);
        if (iVar4 != 0) {
          param_3 = (int *)0x6;
          pcVar20 = param_2->e_magic;
          iVar4 = _strnicmp("solve ",param_2->e_magic,6);
          if (iVar4 != 0) {
            pcVar20 = param_2->e_magic;
            iVar4 = _stricmp("parse solve",param_2->e_magic);
            if (iVar4 != 0) {
              param_3 = (int *)0xc;
              pcVar20 = param_2->e_magic;
              iVar4 = _strnicmp("parse solve ",param_2->e_magic,0xc);
              if (iVar4 != 0) goto LAB_1800103bb;
            }
          }
        }
        DAT_180051c10 = 1;
      }
LAB_1800103bb:
      DAT_180051c04 = 0;
      DAT_180051c08 = 1;
      if (((*(int *)bestinput_exref == 0) && (*(int *)runanyway_exref == 0)) &&
         (iVar4 = GRinqcmp(), iVar4 == 0)) {
        DAT_180051c04 = 1;
        DAT_180051c08 = 0;
      }
      else {
        if (uVar7 == 0x1f) {
          DAT_180051c08 = 0;
          goto LAB_18001060b;
        }
        iVar4 = GRinqpgc();
        if (iVar4 != 0) {
          iVar4 = GRinqnec();
          if (iVar4 != 0) {
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18
                      );
            iVar4 = GRinqautorun();
            if (iVar4 != 1) {
              lVar16 = GetGlobalPointer("RunFromPlantData");
              if (lVar16 != 0) {
                param_4 = "False";
                piVar21 = (int *)0x0;
                do {
                  pcVar20 = (char *)(ulonglong)*(byte *)(lVar16 + (longlong)piVar21);
                  param_3 = (int *)((longlong)piVar21 + 1);
                  if (*(byte *)(lVar16 + (longlong)piVar21) != *(byte *)(piVar21 + 0x60010257))
                  goto LAB_180010538;
                  piVar21 = param_3;
                } while (param_3 != (int *)0x6);
              }
              uVar10 = GetSorResStringEx(0x1bc);
              uVar11 = GetSorResStringEx(0x1c6);
              uVar12 = GetSorResStringEx(0x1c5);
              uVar13 = GetSorResStringEx(0x1c4);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         &local_res18,"%s\n%s\n\n%s\n%s ",uVar13,uVar12,uVar11,uVar10);
              param_4 = (char *)0x0;
              param_3 = (int *)0xffffffff;
              pcVar20 = (char *)0x31;
              iVar4 = MMAfxMessageBox(local_res18,0x31,-1,0);
              if (iVar4 == 2) {
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_res18);
                return 0;
              }
              if (iVar4 == 7) {
                DAT_180051c04 = 1;
                bVar3 = true;
                DAT_180051c08 = 0;
              }
            }
LAB_180010538:
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18
                      );
            bVar2 = bVar3;
          }
        }
      }
    }
    bVar1 = bVar2;
    if (uVar7 == 0x23) {
      FUN_18000be50(1);
      return 0;
    }
    if (uVar7 == 0x24) {
      FUN_18000be50(2);
      return 0;
    }
    if (uVar7 == 0x25) {
      FUN_18000be50(3);
      return 0;
    }
    if (uVar7 == 0x29) {
      uVar22 = FUN_180014460(param_2->e_magic,'\x01');
      return uVar22;
    }
    if (uVar7 == 0x2a) {
      uVar22 = FUN_180013de0(param_2->e_magic);
      return uVar22;
    }
    if (uVar7 == 0x2b) {
      uVar22 = FUN_180014460(param_2->e_magic,'\0');
      return uVar22;
    }
    if (((uVar7 == 1) && (iVar4 = GRinqdrs(), iVar4 != 0)) && (iVar4 = MMGetSuppress(), iVar4 == 0))
    {
      if ((param_2 != (IMAGE_DOS_HEADER *)0x0) && (param_2->e_magic[0] != '\0')) {
        pcVar20 = "NoShowDialog";
        iVar4 = _stricmp(param_2->e_magic,"NoShowDialog");
        if (iVar4 == 0) goto LAB_18001060b;
      }
      iVar4 = FUN_1800094a0();
      if (iVar4 < 1) {
        return 0;
      }
    }
  }
LAB_18001060b:
  bVar3 = FUN_18002f5f0(0);
  iVar4 = local_res8[0];
  if ((int)CONCAT71(extraout_var,bVar3) == 0) {
    if (*(int *)debug_flag_exref == 0) {
      if (bVar1) {
        iVar4 = *(int *)simulate_flag_exref;
        *(undefined4 *)simulate_flag_exref = 0;
      }
    }
    else {
      bVar1 = false;
    }
    DAT_180051c00 = uVar7;
    uVar10 = FUN_180031540((undefined *)0x0,pcVar20,param_3,param_4);
    if ((int)uVar10 == 0) {
      return 0x80004005;
    }
    if ((uVar7 - 1 & 0xfffffffb) != 0) {
      bVar3 = FUN_180031510(0);
      if (((int)CONCAT71(extraout_var_00,bVar3) != 0) ||
         (bVar3 = FUN_180031510(0xe), (int)CONCAT71(extraout_var_01,bVar3) != 0)) {
        local_res8[0] = 0;
        SimSendMainWndMessage(0x552,0,local_res8);
        if (local_res8[0] != 0) {
          return 0x80004005;
        }
      }
      if (uVar7 == 0x20) goto LAB_1800107fd;
    }
    GRbkpinp();
    if ((uVar7 < 0x28) && ((0x8010000222U >> (uVar22 & 0x3f) & 1) != 0)) {
LAB_180010744:
      FUN_18000eeb0();
    }
    else if ((uVar7 == 0x1f) || (uVar7 == 0x22)) {
      if (((param_2 != (IMAGE_DOS_HEADER *)0x0) && (param_2->e_magic[0] != '\0')) &&
         ((iVar8 = _stricmp(param_2->e_magic,"parse solve"), iVar8 == 0 ||
          (iVar8 = _strnicmp(param_2->e_magic,"parse solve ",0xc), iVar8 == 0))))
      goto LAB_180010744;
    }
    else if ((uVar7 == 0x21) &&
            ((bVar3 = FUN_180031510(0), (int)CONCAT71(extraout_var_02,bVar3) != 0 ||
             (bVar3 = FUN_180031510(0xe), (int)CONCAT71(extraout_var_03,bVar3) != 0))))
    goto LAB_180010744;
    uVar10 = EXmsgbox();
    if ((int)uVar10 == 1) {
      iVar5 = -1;
    }
    else {
      if (uVar7 == 7) goto LAB_1800107fd;
      bVar3 = FUN_180031510(0);
      if (((((int)CONCAT71(extraout_var_04,bVar3) != 0) ||
           (bVar3 = FUN_180031510(0x19), (int)CONCAT71(extraout_var_05,bVar3) != 0)) ||
          (bVar3 = FUN_180031510(1), (int)CONCAT71(extraout_var_06,bVar3) != 0)) ||
         (bVar3 = FUN_180031510(0x2b), (int)CONCAT71(extraout_var_07,bVar3) != 0)) {
        iVar8 = FUN_180022a50(1,1,(char *)0x0,(uchar *)param_2);
        if (iVar8 == 0) {
          if ((uVar7 < 0x23) && ((0x6a0000000U >> (uVar22 & 0x3f) & 1) != 0)) goto LAB_1800107fd;
          GRsetgfl();
        }
        else {
          iVar5 = -1;
        }
      }
    }
  }
  else {
    iVar5 = -1;
  }
  if (uVar7 == 1) {
    GRinqdrs(0);
  }
  if ((iVar5 == -1) && ((0x27 < uVar7 || ((0x8680000000U >> (uVar22 & 0x3f) & 1) == 0)))) {
    if (bVar1) {
      *(int *)simulate_flag_exref = iVar4;
    }
    return 0x80004005;
  }
LAB_1800107fd:
  uVar22 = FUN_180015a10(uVar7,(uchar *)param_2);
  if (!bVar1) {
    return uVar22;
  }
  *(int *)simulate_flag_exref = iVar4;
  return uVar22;
}

/* RVA 0x10860 */
void SimMoveTo(IMAGE_DOS_HEADER *param_1,undefined8 param_2,int *param_3,char *param_4)

{
                    /* 0x10860  52  SimMoveTo */
  SimMain((char *)0x2,param_1,param_3,param_4);
  return;
}

/* RVA 0x10870 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SimMoveTo2(int param_1,int *param_2)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined8 auStack_40 [5];
  ulonglong local_18 [2];
  
                    /* 0x10870  108  SimMoveTo2 */
  local_18[0] = DAT_1800516d8 ^ (ulonglong)local_18;
  if (param_2 == (int *)0x0) {
    uVar3 = 0x23;
  }
  else {
    uVar3 = 0xffffffffffffffff;
    do {
      uVar3 = uVar3 + 1;
    } while (*(char *)((longlong)param_2 + uVar3) != '\0');
  }
  uVar4 = uVar3 + 0xf;
  if (uVar4 <= uVar3) {
    uVar4 = 0xffffffffffffff0;
  }
  auStack_40[0] = 0x1800108d1;
  lVar1 = -(uVar4 & 0xfffffffffffffff0);
  *(undefined8 *)((longlong)auStack_40 + lVar1) = 0x1800108e7;
  uVar2 = FUN_180014760((char *)param_2,param_1,1);
  pcVar6 = (char *)(ulonglong)uVar2;
  pcVar5 = "%s #%d";
  *(undefined8 *)((longlong)auStack_40 + lVar1) = 0x1800108fc;
  FUN_180008f80((IMAGE_DOS_HEADER *)((longlong)local_18 + lVar1),"%s #%d",param_2,pcVar6);
  *(undefined8 *)((longlong)auStack_40 + lVar1) = 0x180010904;
  SimMoveTo((IMAGE_DOS_HEADER *)((longlong)local_18 + lVar1),pcVar5,param_2,pcVar6);
  *(undefined8 *)((longlong)auStack_40 + lVar1) = 0x180010910;
  return;
}

/* RVA 0x10920 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SimMoveTo3(uint param_1,int *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  char *pcVar4;
  char *pcVar5;
  undefined8 auStack_40 [5];
  ulonglong local_18 [2];
  
                    /* 0x10920  128  SimMoveTo3 */
  local_18[0] = DAT_1800516d8 ^ (ulonglong)local_18;
  pcVar5 = (char *)(ulonglong)param_1;
  if (param_2 == (int *)0x0) {
    uVar2 = 0x23;
  }
  else {
    uVar2 = 0xffffffffffffffff;
    do {
      uVar2 = uVar2 + 1;
    } while (*(char *)((longlong)param_2 + uVar2) != '\0');
  }
  uVar3 = uVar2 + 0xf;
  if (uVar3 <= uVar2) {
    uVar3 = 0xffffffffffffff0;
  }
  auStack_40[0] = 0x18001097f;
  lVar1 = -(uVar3 & 0xfffffffffffffff0);
  pcVar4 = "%s #%d";
  *(undefined8 *)((longlong)auStack_40 + lVar1) = 0x180010999;
  FUN_180008f80((IMAGE_DOS_HEADER *)((longlong)local_18 + lVar1),"%s #%d",param_2,pcVar5);
  *(undefined8 *)((longlong)auStack_40 + lVar1) = 0x1800109a1;
  SimMoveTo((IMAGE_DOS_HEADER *)((longlong)local_18 + lVar1),pcVar4,param_2,pcVar5);
  *(undefined8 *)((longlong)auStack_40 + lVar1) = 0x1800109ad;
  return;
}

/* RVA 0x109c0 */
bool FUN_1800109c0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong uVar2;
  
  DAT_180051c00 = 1;
  FUN_180031540((undefined *)0x0,param_2,param_3,param_4);
  iVar1 = FUN_180022a50(1,1,(char *)0x0,(uchar *)0x0);
  if (iVar1 == 0) {
    GRsetgfl();
    uVar2 = FUN_180015a10(9,(uchar *)0x0);
    return (int)uVar2 == 0;
  }
  return false;
}

/* RVA 0x10a10 */
int SimQueryNonStream(int *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
                    /* 0x10a10  70  SimQueryNonStream */
  iVar1 = GRinqAutomationMode();
  iVar2 = GRinqinmt();
  if ((iVar2 == 0) || (iVar1 != 0)) {
    uVar3 = thunk_FUN_18001b720(param_1,param_2,param_3,param_4);
    if ((int)uVar3 < 1) {
      iVar1 = ((int)uVar3 >> 0x1f & 0x80004004U) + 1;
    }
    else {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = -0x7fffbffb;
  }
  return iVar1;
}

/* RVA 0x10a80 */
int SimQueryStream(longlong param_1)

{
  int iVar1;
  int iVar2;
  
                    /* 0x10a80  71  SimQueryStream */
  iVar1 = GRinqAutomationMode();
  iVar2 = GRinqinmt();
  if ((iVar2 == 0) || (iVar1 != 0)) {
    iVar1 = FUN_18001a420(param_1);
    if (iVar1 < 1) {
      iVar1 = (iVar1 >> 0x1f & 0x80004004U) + 1;
    }
    else {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = -0x7fffbffb;
  }
  return iVar1;
}

/* RVA 0x10af0 */
void SimReSetStopErrorLevel(int param_1)

{
                    /* 0x10af0  163  SimReSetStopErrorLevel */
  FUN_1800209a0(*(longlong *)(*(longlong *)topfinfo_exref + 0x560),-1);
  if (1 < param_1) {
    FUN_180020520(*(longlong *)(*(longlong *)topfinfo_exref + 0x560),1,2,-param_1,"ERROR");
  }
  FUN_180020ec0(*(longlong *)(*(longlong *)topfinfo_exref + 0x560),1);
  _guard_check_icall();
  return;
}

/* RVA 0x10b70 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000180010d30) */
/* WARNING: Removing unreachable block (ram,0x000180010cc9) */
/* WARNING: Removing unreachable block (ram,0x000180010ce5) */
/* WARNING: Removing unreachable block (ram,0x000180010cff) */
/* WARNING: Removing unreachable block (ram,0x000180010d0c) */
/* WARNING: Removing unreachable block (ram,0x000180010d26) */
/* WARNING: Removing unreachable block (ram,0x000180010d40) */

int FUN_180010b70(undefined8 param_1,LPCSTR param_2)

{
  longlong *plVar1;
  int iVar2;
  int iVar3;
  BSTR lpWideCharStr;
  undefined1 auStackY_f8 [32];
  longlong *local_a8;
  longlong *local_a0 [13];
  ulonglong local_38;
  
  local_38 = DAT_1800516d8 ^ (ulonglong)auStackY_f8;
  local_a0[0] = (longlong *)0x0;
  iVar2 = DCGetEngineServer(local_a0);
  if (-1 < iVar2) {
    local_a8 = (longlong *)0x0;
    iVar2 = (**(code **)*local_a0[0])(local_a0[0],&DAT_180040f70,&local_a8);
    plVar1 = local_a8;
    if (-1 < iVar2) {
      if (param_2 == (LPCSTR)0x0) {
        lpWideCharStr = (BSTR)0x0;
      }
      else {
        iVar2 = MultiByteToWideChar(0,0,param_2,-1,(LPWSTR)0x0,0);
        lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,iVar2 - 1);
        if ((lpWideCharStr != (BSTR)0x0) &&
           (iVar3 = MultiByteToWideChar(0,0,param_2,-1,lpWideCharStr,iVar2), iVar3 != iVar2)) {
          SysFreeString(lpWideCharStr);
LAB_180010d98:
                    /* WARNING: Subroutine does not return */
          FUN_180001380(-0x7ff8fff2);
        }
        if (lpWideCharStr == (BSTR)0x0) goto LAB_180010d98;
      }
      iVar2 = (**(code **)(*plVar1 + 0x60))(plVar1,lpWideCharStr,0x80000000,1);
      SysFreeString(lpWideCharStr);
      if (-1 < iVar2) {
        MMCreateStreamOnFileEx(param_1,0xc0000000,0,0);
      }
    }
    if (local_a8 != (longlong *)0x0) {
      (**(code **)(*local_a8 + 0x10))();
    }
  }
  if (local_a0[0] != (longlong *)0x0) {
    (**(code **)(*local_a0[0] + 0x10))();
  }
  return iVar2;
}

/* RVA 0x10db0 */
undefined8 SimReconcile(void)

{
  longlong *plVar1;
  int iVar2;
  int iVar3;
  HRESULT HVar4;
  longlong *plVar5;
  BSTR lpWideCharStr;
  undefined8 uVar6;
  undefined4 uVar7;
  longlong *local_res8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res10 [8];
  longlong *local_res18;
  _union_2707 local_78;
  _union_2707 local_60;
  undefined4 local_48;
  ULONG UStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  
                    /* 0x10db0  140  SimReconcile */
  uVar6 = 0;
  local_res18 = (longlong *)0x0;
  local_res8 = (longlong *)0x0;
  plVar5 = (longlong *)GetGlobalPointer("HappNode");
  if (plVar5 == (longlong *)0x0) goto LAB_180010fed;
  (**(code **)(*plVar5 + 8))(plVar5);
  (**(code **)(*plVar5 + 0x90))();
  plVar1 = local_res18;
  if (local_res18 != (longlong *)0x0) {
    iVar2 = MultiByteToWideChar(0,0,"Data",-1,(LPWSTR)0x0,0);
    lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,iVar2 - 1);
    if (lpWideCharStr != (BSTR)0x0) {
      iVar3 = MultiByteToWideChar(0,0,"Data",-1,lpWideCharStr,iVar2);
      if (iVar3 != iVar2) {
        SysFreeString(lpWideCharStr);
        goto LAB_180011039;
      }
    }
    if (lpWideCharStr == (BSTR)0x0) {
LAB_180011039:
                    /* WARNING: Subroutine does not return */
      FUN_180001380(-0x7ff8fff2);
    }
    (**(code **)(*plVar1 + 0x110))(plVar1,lpWideCharStr,&local_res8);
    SysFreeString(lpWideCharStr);
    if (local_res8 != (longlong *)0x0) {
      local_60._0_8_ = 0;
      local_60.decVal.u2 = (_union_1719)(_struct_1720)0x0;
      local_60._16_8_ = 0;
      VariantInit((VARIANTARG *)&local_60.n2);
      local_78._0_8_ = 0;
      local_78.decVal.u2 = (_union_1719)(_struct_1720)0x0;
      local_78._16_8_ = 0;
      VariantInit((VARIANTARG *)&local_78.n2);
      local_48 = local_60._0_4_;
      UStack_44 = local_60.decVal.Hi32;
      uStack_40 = local_60._8_4_;
      uStack_3c = local_60._12_4_;
      local_38 = local_60._16_8_;
      iVar2 = (**(code **)(*local_res8 + 0x98))(local_res8,0x4e,&local_48,&local_78);
      uVar7 = 0x144a5;
      if (-1 < iVar2) {
        HVar4 = VariantChangeType((VARIANTARG *)&local_78.n2,(VARIANTARG *)&local_78.n2,0,3);
        uVar7 = 0x144a5;
        if (-1 < HVar4) {
          uVar7 = local_78._8_4_;
        }
      }
      if (((uint)uVar7 >> 0x19 & 1) == 0) {
        local_48 = local_60._0_4_;
        UStack_44 = local_60.decVal.Hi32;
        uStack_40 = local_60._8_4_;
        uStack_3c = local_60._12_4_;
        local_38 = local_60._16_8_;
        iVar2 = (**(code **)(*local_res8 + 0x98))(local_res8,6,&local_48,&local_78);
        if ((iVar2 < 0) || (local_78.n2.vt != 8)) {
LAB_180010fb8:
          (**(code **)(*local_res8 + 0x1c0))(local_res8,uVar7 | 0x10000000);
          uVar6 = 1;
        }
        else {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    (local_res10,(wchar_t *)local_78.decVal.u2);
          iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                            (local_res10,"HEAT");
          if (iVar2 != 0) {
            iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                              (local_res10,"WORK");
            if (iVar2 != 0) {
              iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                                (local_res10,"POWER");
              if (iVar2 != 0) {
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10);
                goto LAB_180010fb8;
              }
            }
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10);
        }
      }
      VariantClear((VARIANTARG *)&local_78.n2);
      VariantClear((VARIANTARG *)&local_60.n2);
    }
  }
  (**(code **)(*plVar5 + 0x10))(plVar5);
LAB_180010fed:
  if (local_res8 != (longlong *)0x0) {
    (**(code **)(*local_res8 + 0x10))();
  }
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x10))();
  }
  return uVar6;
}

/* RVA 0x11050 */
undefined8 SimReflect(int param_1,undefined4 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  
                    /* 0x11050  135  SimReflect */
  uVar5 = 0;
  if (param_1 == 0) {
    iVar3 = 0;
    if (0 < DAT_180051e3c) {
      uVar5 = 1;
      lVar4 = 0;
      iVar2 = DAT_180051e3c;
      do {
        puVar1 = *(undefined8 **)(lVar4 + DAT_180051df0);
        if ((puVar1 != (undefined8 *)0x0) && ((code *)puVar1[1] != (code *)0x0)) {
          (*(code *)puVar1[1])(iVar3,*puVar1,0,param_2,param_3);
          iVar2 = DAT_180051e3c;
        }
        iVar3 = iVar3 + 1;
        lVar4 = lVar4 + 8;
      } while (iVar3 < iVar2);
    }
  }
  else if (param_1 == 1) {
    iVar3 = 0;
    if (0 < DAT_180051e38) {
      uVar5 = 1;
      lVar4 = 0;
      iVar2 = DAT_180051e38;
      do {
        puVar1 = *(undefined8 **)(lVar4 + DAT_180051dd8);
        if ((puVar1 != (undefined8 *)0x0) && ((code *)puVar1[1] != (code *)0x0)) {
          (*(code *)puVar1[1])(iVar3,*puVar1,1,param_2,param_3);
          iVar2 = DAT_180051e38;
        }
        iVar3 = iVar3 + 1;
        lVar4 = lVar4 + 8;
      } while (iVar3 < iVar2);
    }
  }
  else if (param_1 == 2) {
    iVar3 = 0;
    if (0 < DAT_180051e40) {
      uVar5 = 1;
      lVar4 = 0;
      iVar2 = DAT_180051e40;
      do {
        puVar1 = *(undefined8 **)(lVar4 + DAT_180051e08);
        if ((puVar1 != (undefined8 *)0x0) && ((code *)puVar1[1] != (code *)0x0)) {
          (*(code *)puVar1[1])(iVar3,*puVar1,2,param_2,param_3);
          iVar2 = DAT_180051e40;
        }
        iVar3 = iVar3 + 1;
        lVar4 = lVar4 + 8;
      } while (iVar3 < iVar2);
    }
  }
  else if ((param_1 == 3) && (iVar3 = 0, 0 < DAT_180051e44)) {
    uVar5 = 1;
    lVar4 = 0;
    iVar2 = DAT_180051e44;
    do {
      puVar1 = *(undefined8 **)(lVar4 + DAT_180051e20);
      if ((puVar1 != (undefined8 *)0x0) && ((code *)puVar1[1] != (code *)0x0)) {
        (*(code *)puVar1[1])(iVar3,*puVar1,3,param_2,param_3);
        iVar2 = DAT_180051e44;
      }
      iVar3 = iVar3 + 1;
      lVar4 = lVar4 + 8;
    } while (iVar3 < iVar2);
  }
  return uVar5;
}

/* RVA 0x11210 */
undefined8 SimReinit(void)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
                    /* 0x11210  57  SimReinit */
  lVar1 = GetGlobalPointer("AnalysisForm");
  if (lVar1 == 0) {
    FUN_180019330(1);
    return 0;
  }
  uVar2 = GetSorResStringEx(0x1bf);
  uVar3 = MVGetI18nProductName();
  open_message_box(uVar3,uVar2,&DAT_1800408b0,0,0,0,0,1,0);
  return 0;
}

/* RVA 0x11290 */
ulonglong SimReinitBlock(uint param_1,char ****param_2,char *param_3)

{
  int iVar1;
  ulonglong uVar2;
  
                    /* 0x11290  85  SimReinitBlock */
  uVar2 = FUN_180019140(param_3,param_2,(char *)(ulonglong)param_1,1);
  if (*(int *)partial_results_exref != 0) {
    iVar1 = (*(code *)PTR_FUN_180044150)();
    if (iVar1 != 0) {
      FUN_18002fb80();
    }
  }
  FUN_1800074b0(0x52d,0,(longlong)(int)param_1);
  return uVar2 & 0xffffffff;
}

/* RVA 0x112f0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 SimReinitStreamReportFlags(void)

{
  int iVar1;
  undefined1 auStackY_158 [32];
  char acStack_128 [8];
  undefined4 uStack_120;
  ulonglong uStack_18;
  
                    /* 0x112f0  141  SimReinitStreamReportFlags */
  uStack_18 = DAT_1800516d8 ^ (ulonglong)auStackY_158;
  iVar1 = GRinqcnn();
  if (iVar1 == 2) {
    FUN_180030240((char *)0x0,acStack_128,0,0x12050200,(char *)0x0);
    return uStack_120;
  }
  return 1;
}

/* RVA 0x11300 */
ulonglong SimResume(int param_1,undefined8 param_2,int *param_3,char *param_4)

{
  int iVar1;
  ulonglong uVar2;
  char *pcVar3;
  
                    /* 0x11300  110  SimResume */
  iVar1 = GRinqQRs();
  if ((iVar1 == 0) || (iVar1 = GRinqgpd(), iVar1 == 0)) {
    return 1;
  }
  iVar1 = GRinqnco();
  if ((iVar1 == 0) && (iVar1 = GRinqpgc(), iVar1 != 0)) {
    return 1;
  }
  pcVar3 = (char *)0x26;
  if (param_1 != 0) {
    pcVar3 = (char *)0x1e;
  }
  uVar2 = SimMain(pcVar3,(IMAGE_DOS_HEADER *)0x0,param_3,param_4);
  return uVar2;
}

/* RVA 0x11360 */
void SimRun(undefined8 param_1,undefined8 param_2,int *param_3,char *param_4)

{
                    /* 0x11360  51  SimRun */
  SimMain((char *)0x1,(IMAGE_DOS_HEADER *)0x0,param_3,param_4);
  return;
}

/* RVA 0x11370 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SimSBgetblkpth(undefined4 param_1,int param_2,char *param_3,undefined1 param_4,
                        undefined8 param_5)

{
  char cVar1;
  longlong lVar2;
  bool bVar3;
  int iVar4;
  char *pcVar5;
  ulonglong uVar6;
  undefined7 extraout_var;
  undefined8 uVar7;
  undefined1 auStackY_f8 [32];
  int aiStack_b8 [2];
  char *pcStack_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 auStack_88 [6];
  char acStack_58 [16];
  ulonglong uStack_48;
  
                    /* 0x11370  170  SimSBgetblkpth */
  uStack_48 = DAT_1800516d8 ^ (ulonglong)auStackY_f8;
  uVar7 = 1;
  pcVar5 = strchr(param_3,0x20);
  if (pcVar5 != (char *)0x0) {
    *pcVar5 = '\0';
  }
  iVar4 = HYparnam(param_3,&uStack_a8,&pcStack_b0);
  if (iVar4 != 0) {
    lVar2 = -(longlong)pcStack_b0;
    do {
      cVar1 = *pcStack_b0;
      pcStack_b0[(longlong)(acStack_58 + lVar2)] = cVar1;
      pcStack_b0 = pcStack_b0 + 1;
    } while (cVar1 != '\0');
    pcStack_b0 = acStack_58;
    uVar6 = HYrslhie(uStack_a8,&DAT_18003fa80,&uStack_90,&uStack_98);
    if ((int)uVar6 == 0) {
      return uVar6;
    }
    uVar7 = HYGetFinfoCls(uStack_90,uStack_98);
  }
  uVar7 = HYPshFinfo(uVar7);
  bVar3 = FUN_18001e1a0(param_1,param_2,pcStack_b0,auStack_88,aiStack_b8,&uStack_98,&uStack_a0);
  if ((int)CONCAT71(extraout_var,bVar3) != 0) {
    uStack_98 = uStack_a0;
    uStack_90 = auStack_88[aiStack_b8[0]];
    HYnavpth(&uStack_98,param_4,0,param_5);
  }
  HYPopFinfo(uVar7);
  return CONCAT71(extraout_var,bVar3) & 0xffffffff;
}

/* RVA 0x11380 */
longlong SimSBgetinterdir(void)

{
                    /* 0x11380  175  SimSBgetinterdir */
  return *(longlong *)SBdataptr_exref + 0x10;
}

/* RVA 0x11390 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SimSave(longlong *param_1,char *param_2,undefined *param_3,undefined *param_4)

{
  char cVar1;
  longlong lVar2;
  code *pcVar3;
  _func_5369 *p_Var4;
  int iVar5;
  UINT UVar6;
  UINT UVar7;
  undefined4 uVar8;
  char *pcVar9;
  char *pcVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  LPWSTR lpWideCharStr;
  undefined8 *puVar13;
  undefined8 *puVar14;
  undefined8 *puVar15;
  undefined8 auStackY_5f0 [5];
  undefined1 local_5c8 [24];
  undefined8 uStackY_5b0;
  WCHAR local_598 [16];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_578 [8];
  IStream *local_570;
  CArchive local_568 [24];
  CSimpleStringT<char,1> local_550 [8];
  uint local_548;
  undefined4 *local_530;
  undefined4 *local_528;
  CArchive local_4f8 [24];
  CSimpleStringT<char,1> local_4e0 [8];
  uint local_4d8;
  UINT *local_4c0;
  UINT *local_4b8;
  COleStreamFile local_488 [56];
  COleStreamFile local_450 [55];
  undefined4 uStack_419;
  undefined1 local_414 [1004];
  ulonglong local_28;
  
                    /* 0x11390  60  SimSave */
  puVar14 = (undefined8 *)(local_5c8 + 0x20);
  local_28 = DAT_1800516d8 ^ (ulonglong)local_578;
  if (param_1 == (longlong *)0x0) {
    uStackY_5b0 = 0x1800113d7;
    pcVar9 = param_2;
    FUN_180027cb0(param_2);
    uStackY_5b0 = 0x1800113df;
    FUN_1800325b0(param_2,pcVar9,param_3,param_4);
    uStackY_5b0 = 0x1800113e4;
    iVar5 = SBlocalhost();
    puVar15 = (undefined8 *)(local_5c8 + 0x20);
    if (iVar5 == 0) {
      lVar2 = 0x38 - (longlong)param_2;
      do {
        cVar1 = *param_2;
        param_2[(longlong)(local_450 + lVar2)] = cVar1;
        param_2 = param_2 + 1;
      } while (cVar1 != '\0');
      puVar12 = &uStack_419;
      do {
        puVar11 = puVar12;
        puVar12 = (undefined4 *)((longlong)puVar11 + 1);
      } while (*(char *)((longlong)puVar11 + 1) != '\0');
      *(undefined4 *)((longlong)puVar11 + 1) = DAT_180040a80;
      *(undefined1 *)((longlong)puVar11 + 5) = DAT_180040a84;
      uStackY_5b0 = 0x18001144d;
      pcVar9 = strrchr((char *)((longlong)&uStack_419 + 1),0x5c);
      if (pcVar9 == (char *)0x0) {
        pcVar9 = (char *)((longlong)&uStack_419 + 1);
      }
      else {
        pcVar9 = pcVar9 + 1;
      }
      uStackY_5b0 = 0x18001146b;
      FUN_180025fb0((char *)0x0,pcVar9);
      uStackY_5b0 = 0x180011470;
      pcVar10 = (char *)FUN_18001a130();
      uStackY_5b0 = 0x180011482;
      FUN_18002b360((char *)((longlong)&uStack_419 + 1),pcVar9,pcVar10);
      puVar15 = (undefined8 *)(local_5c8 + 0x20);
    }
  }
  else {
    local_570 = (IStream *)0x0;
    if (DAT_180051c20 != (BSTR)0x0) {
      lpWideCharStr = local_598;
      if (lpWideCharStr == (LPWSTR)0x0) {
        lpWideCharStr = (LPWSTR)0x0;
      }
      else {
        local_598[0] = L'\0';
        iVar5 = MultiByteToWideChar(0,0,"ControlPanel",-1,lpWideCharStr,0xd);
        if (iVar5 == 0) {
          lpWideCharStr = (LPWSTR)0x0;
        }
      }
      iVar5 = (**(code **)(*param_1 + 0x18))(param_1,lpWideCharStr,0x1012,0);
      if (iVar5 != 0) {
        FUN_180008f80((longlong)&uStack_419 + 1,"Assert failed in file %s line %d",
                      "G:\\Agent\\work\\2\\s\\src\\mm\\Simdll\\SimMain.cpp",0x602);
        LogMessage((longlong)&uStack_419 + 1);
      }
      puVar14 = (undefined8 *)local_5c8;
      if (local_570 != (IStream *)0x0) {
        COleStreamFile::COleStreamFile(local_488,local_570);
        CArchive::CArchive(local_4f8,(CFile *)local_488,0,0x1000,(void *)0x0);
        UVar6 = SysStringLen(DAT_180051c20);
        UVar7 = SysStringLen(DAT_180051c20);
        if ((~local_4d8 & 1) == 0) {
          pcVar9 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64(local_4e0);
                    /* WARNING: Subroutine does not return */
          AfxThrowArchiveException(2,pcVar9);
        }
        if (local_4b8 < local_4c0 + 1) {
          CArchive::Flush(local_4f8);
        }
        *local_4c0 = UVar7;
        local_4c0 = local_4c0 + 1;
        CArchive::Write(local_4f8,DAT_180051c20,UVar6 * 2);
        CArchive::Close(local_4f8);
        if (local_570 != (IStream *)0x0) {
          (*local_570->lpVtbl->Release)(local_570);
        }
        local_570 = (IStream *)0x0;
        SimClearControlPanelMessage();
        CArchive::~CArchive(local_4f8);
        COleStreamFile::~COleStreamFile(local_488);
        puVar14 = (undefined8 *)local_5c8;
      }
    }
    puVar13 = puVar14 + 2;
    if (puVar13 == (undefined8 *)0x0) {
      puVar13 = (undefined8 *)0x0;
    }
    else {
      *(undefined4 *)(puVar14 + 1) = 9;
      *puVar14 = puVar13;
      *(undefined2 *)puVar13 = 0;
      puVar14[-5] = 0x180011665;
      iVar5 = MultiByteToWideChar(0,0,"ACCTINFO",-1,(LPWSTR)*puVar14,*(int *)(puVar14 + 1));
      if (iVar5 == 0) {
        puVar13 = (undefined8 *)0x0;
      }
    }
    lVar2 = *param_1;
    puVar14[1] = &local_570;
    *(undefined4 *)puVar14 = 0;
    pcVar3 = *(code **)(lVar2 + 0x18);
    puVar14[-5] = 0x180011693;
    iVar5 = (*pcVar3)(param_1,puVar13,0x1012,0);
    if (iVar5 != 0) {
      puVar14[-5] = 0x1800116b7;
      FUN_180008f80((longlong)&uStack_419 + 1,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\Simdll\\SimMain.cpp",0x615);
      puVar14[-5] = 0x1800116cd;
      LogMessage((longlong)&uStack_419 + 1);
    }
    puVar14[-5] = 0x1800116dd;
    COleStreamFile::COleStreamFile(local_450,local_570);
    *puVar14 = 0;
    puVar14[-5] = 0x1800116fb;
    CArchive::CArchive(local_568,(CFile *)local_450,0,0x1000,(void *)*puVar14);
    puVar14[-5] = 0x180011700;
    uVar8 = GRinqcnn();
    puVar14[-5] = 0x180011707;
    iVar5 = SBlocalhost();
    if (iVar5 == 0) {
      if ((~local_548 & 1) == 0) {
        puVar14[-5] = 0x18001191b;
        pcVar9 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64(local_550);
                    /* WARNING: Subroutine does not return */
        puVar14[-5] = &UNK_180011928;
        AfxThrowArchiveException(2,pcVar9);
      }
      if (local_528 < local_530 + 1) {
        puVar14[-5] = 0x180011734;
        CArchive::Flush(local_568);
      }
      *local_530 = 1;
      puVar12 = local_530 + 1;
      if ((~local_548 & 1) == 0) {
        puVar14[-5] = 0x180011933;
        local_530 = puVar12;
        pcVar9 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64(local_550);
                    /* WARNING: Subroutine does not return */
        puVar14[-5] = &UNK_180011940;
        AfxThrowArchiveException(2,pcVar9);
      }
      puVar11 = local_530 + 2;
      local_530 = puVar12;
      if (local_528 < puVar11) {
        puVar14[-5] = 0x18001176a;
        CArchive::Flush(local_568);
      }
      *local_530 = uVar8;
      local_530 = local_530 + 1;
      puVar14[-5] = 0x18001177f;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_578);
      puVar14[-5] = 0x180011784;
      pcVar9 = FUN_180019fd0();
      puVar14[-5] = 0x180011791;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                (local_578,pcVar9);
      puVar14[-5] = 0x18001179e;
      CArchive::operator<<<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>_>_>
                (local_568,(CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>_>_> *)local_578);
      puVar14[-5] = 0x1800117aa;
      pcVar9 = (char *)SBgethvr("NODENAME");
      puVar14[-5] = 0x1800117b7;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                (local_578,pcVar9);
      puVar14[-5] = 0x1800117c4;
      CArchive::operator<<<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>_>_>
                (local_568,(CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>_>_> *)local_578);
      puVar14[-5] = 0x1800117d0;
      pcVar9 = (char *)SBgethvr("LOGONNAME");
      puVar14[-5] = 0x1800117dd;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                (local_578,pcVar9);
      puVar14[-5] = 0x1800117ea;
      CArchive::operator<<<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>_>_>
                (local_568,(CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>_>_> *)local_578);
      puVar14[-5] = 0x1800117ef;
      pcVar9 = (char *)FUN_18001a130();
    }
    else {
      if ((~local_548 & 1) == 0) {
        puVar14[-5] = 0x18001194b;
        pcVar9 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64(local_550);
                    /* WARNING: Subroutine does not return */
        puVar14[-5] = &UNK_180011958;
        AfxThrowArchiveException(2,pcVar9);
      }
      if (local_528 < local_530 + 1) {
        puVar14[-5] = 0x180011815;
        CArchive::Flush(local_568);
      }
      *local_530 = 0;
      puVar12 = local_530 + 1;
      if ((~local_548 & 1) == 0) {
        puVar14[-5] = 0x1800118e8;
        local_530 = puVar12;
        pcVar9 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64(local_550);
                    /* WARNING: Subroutine does not return */
        puVar14[-5] = &UNK_1800118f5;
        AfxThrowArchiveException(2,pcVar9);
      }
      puVar11 = local_530 + 2;
      local_530 = puVar12;
      if (local_528 < puVar11) {
        puVar14[-5] = 0x180011848;
        CArchive::Flush(local_568);
      }
      *local_530 = uVar8;
      local_530 = local_530 + 1;
      puVar14[-5] = 0x18001185d;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_578);
      puVar14[-5] = 0x180011862;
      pcVar9 = FUN_180019fd0();
    }
    puVar14[-5] = 0x18001186f;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(local_578,pcVar9);
    puVar14[-5] = 0x18001187c;
    CArchive::operator<<<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>_>_>
              (local_568,(CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>_>_> *)local_578);
    puVar14[-5] = 0x180011886;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_578);
    puVar14[-5] = 0x18001188f;
    CArchive::Close(local_568);
    if (local_570 != (IStream *)0x0) {
      p_Var4 = local_570->lpVtbl->Release;
      puVar14[-5] = 0x18001189e;
      (*p_Var4)(local_570);
    }
    puVar14[-5] = 0x1800118a7;
    CArchive::~CArchive(local_568);
    puVar14[-5] = 0x1800118b3;
    COleStreamFile::~COleStreamFile(local_450);
    puVar15 = puVar14 + -4;
  }
  *(undefined8 *)((longlong)puVar15 + -8) = 0x1800118c4;
  return 0;
}

/* RVA 0x11960 */
int SimSetAnimation(int param_1)

{
  char *pcVar1;
  char *local_res10 [3];
  
                    /* 0x11960  98  SimSetAnimation */
  if (*(int *)pseudobatch_exref != 0) {
    return param_1;
  }
  if (param_1 == 0) {
    FUN_1800068d0((char *)0x0,1);
    return 0;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res10);
  pcVar1 = (char *)GRinqexc();
  if ((pcVar1 != (char *)0x0) || (pcVar1 = (char *)GRinqnxt(), pcVar1 != (char *)0x0)) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res10,pcVar1);
    FUN_1800068d0(local_res10[0],1);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res10);
  return param_1;
}

/* RVA 0x119e0 */
undefined8
SimSetConnectInfo(undefined4 param_1,char *param_2,char *param_3,char *param_4,char *param_5,
                 undefined4 param_6)

{
                    /* 0x119e0  104  SimSetConnectInfo */
  DAT_180051c2c = 1;
  DAT_18004f780 = param_1;
  strncpy(&DAT_18004f784,param_2,0x4f);
  DAT_18004f7d3 = 0;
  strncpy(&DAT_18004f7d4,param_3,0x4f);
  DAT_18004f823 = 0;
  strncpy(&DAT_18004f824,param_4,0x4f);
  DAT_18004f873 = 0;
  strncpy(&DAT_18004f874,param_5,0x4f);
  DAT_18004f8c4 = param_6;
  DAT_18004f8c3 = 0;
  return 1;
}

/* RVA 0x11a90 */
undefined4 SimSetEngineFile(int param_1,char *param_2)

{
  undefined4 uVar1;
  char *pcVar2;
  longlong local_res18 [2];
  
                    /* 0x11a90  74  SimSetEngineFile */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res18,
             (&PTR_s_usrpp1a_18004f730)[param_1]);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res18," ");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res18,param_2);
  pcVar2 = ATL::CSimpleStringT<char,1>::GetBuffer
                     ((CSimpleStringT<char,1> *)local_res18,*(int *)(local_res18[0] + -0x10));
  uVar1 = SBmmgini(pcVar2,4,0xffffffff);
  ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)local_res18,-1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res18);
  return uVar1;
}

/* RVA 0x11b20 */
int SimSetExpressRun(int param_1)

{
                    /* 0x11b20  97  SimSetExpressRun */
  GRdiagno();
  if (param_1 != 0) {
    FUN_1800068d0((char *)0x0,1);
  }
  return param_1;
}

/* RVA 0x11b50 */
undefined4 SimSetHost(undefined4 param_1,char *param_2,char *param_3,char *param_4,char *param_5)

{
  bool bVar1;
  AFX_MODULE_STATE *pAVar2;
  undefined7 extraout_var;
  undefined4 uVar3;
  undefined1 local_28 [8];
  AFX_MAINTAIN_STATE2 local_20 [24];
  
                    /* 0x11b50  84  SimSetHost */
  pAVar2 = AfxGetModuleState();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_20,pAVar2);
  SimSetConnectInfo(param_1,param_2,param_3,param_4,param_5,1);
  DAT_180051c2c = 0;
  bVar1 = FUN_180003d80(local_28,(char *)0x0);
  uVar3 = 0x80004005;
  if ((int)CONCAT71(extraout_var,bVar1) != 0) {
    uVar3 = 0;
  }
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_20);
  return uVar3;
}

/* RVA 0x11bf0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
SimSetInteractiveLoadResult(int param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  bool bVar1;
  undefined7 extraout_var;
  char *pcVar2;
  undefined8 uVar3;
  undefined1 auStack_168 [32];
  char local_148 [304];
  ulonglong local_18;
  
                    /* 0x11bf0  95  SimSetInteractiveLoadResult */
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_168;
  bVar1 = FUN_18002bdf0();
  if (((int)CONCAT71(extraout_var,bVar1) != 0) && (param_1 != *(int *)partial_results_exref)) {
    *(int *)partial_results_exref = param_1;
    if (param_1 == 0) {
      *(undefined4 *)partial_results_exref = 1;
      FUN_180020230(3,0);
    }
    else {
      if (*(int *)denied_exref == 0) {
        uVar3 = FUN_180020230(4,0);
        if ((int)uVar3 != 0) goto LAB_180011ca0;
        uVar3 = 0xfa4;
      }
      else {
        uVar3 = 0xfa5;
      }
      uVar3 = GetSorResStringEx(uVar3);
      FUN_180008f80(local_148,uVar3,param_3,param_4);
      FUN_180006fc0('e',local_148,"OKONLY",0);
    }
    *(undefined4 *)partial_results_exref = 0;
  }
LAB_180011ca0:
  pcVar2 = (char *)GetSorResStringEx(0x1d7);
  FUN_180008f30(pcVar2);
  return *(undefined4 *)partial_results_exref;
}

/* RVA 0x11ce0 */
undefined8 SimSetLicenseInfo(char *param_1,char *param_2)

{
                    /* 0x11ce0  129  SimSetLicenseInfo */
  strncpy(&DAT_180051d30,param_1,0x4f);
  DAT_180051d7f = 0;
  strncpy(&DAT_180051d80,param_2,0x4f);
  DAT_180051dcf = 0;
  MMHasDupInfo();
  return 1;
}

/* RVA 0x11d40 */
undefined8 SimSetRunOption(uint param_1,int param_2)

{
  undefined7 extraout_var;
  undefined8 uVar1;
  uint uVar3;
  uint uVar2;
  bool bVar4;
  
                    /* 0x11d40  76  SimSetRunOption */
  bVar4 = param_2 != 0;
  if (6 < param_1) {
    return 0;
  }
  uVar2 = (uint)bVar4;
  uVar3 = (uint)bVar4;
  switch(param_1) {
  case 0:
    if (*(uint *)pseudobatch_exref != uVar2) {
      *(uint *)pseudobatch_exref = uVar3;
      GRdiagno(bVar4);
      return 1;
    }
    break;
  case 1:
    bVar4 = FUN_18002bdf0();
    if (((int)CONCAT71(extraout_var,bVar4) != 0) && (uVar2 != *(uint *)partial_results_exref)) {
      *(uint *)partial_results_exref = uVar2;
      if (param_2 != 0) {
        if ((*(int *)denied_exref == 0) && (uVar1 = FUN_180020230(4,0), (int)uVar1 != 0)) {
          return 1;
        }
        *(undefined4 *)partial_results_exref = 0;
        return 0;
      }
      *(undefined4 *)partial_results_exref = 1;
      FUN_180020230(3,0);
      *(undefined4 *)partial_results_exref = 0;
    }
    break;
  case 2:
    GRsetrun(param_2 == 0);
    return 1;
  case 3:
    *(uint *)load_reg_result_exref = uVar3;
    *(uint *)load_estimation_result_exref = uVar3;
  case 6:
    *(uint *)load_retrieved_result_exref = uVar2;
    return 1;
  case 4:
    *(uint *)load_reg_result_exref = uVar2;
    return 1;
  case 5:
    *(uint *)load_estimation_result_exref = uVar2;
    return 1;
  }
  return 1;
}

/* RVA 0x11ee0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HGLOBAL SimShowExistStopPoint(void)

{
  char cVar1;
  longlong lVar2;
  uchar *puVar3;
  uchar *_Src;
  uchar *_Src_00;
  char ****ppppcVar4;
  HGLOBAL pvVar5;
  char *pcVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined1 auStackY_88 [32];
  undefined2 local_58 [4];
  char ****local_50;
  char local_48 [4];
  char local_44 [2];
  undefined2 local_42;
  longlong local_40;
  ulonglong local_38;
  ulonglong local_30;
  
                    /* 0x11ee0  161  SimShowExistStopPoint */
  local_30 = DAT_1800516d8 ^ (ulonglong)auStackY_88;
  (*(code *)PTR_FUN_180044148)(&DAT_18003f720,1);
  local_48[0] = s_<ArrayOfClass>_180040de0[8];
  local_48[1] = s_<ArrayOfClass>_180040de0[9];
  local_48[2] = s_<ArrayOfClass>_180040de0[10];
  local_48[3] = s_<ArrayOfClass>_180040de0[0xb];
  local_44[0] = s_<ArrayOfClass>_180040de0[0xc];
  local_44[1] = s_<ArrayOfClass>_180040de0[0xd];
  local_42 = 0;
  local_40 = 0xe;
  local_38 = 0xf;
  local_50 = (char ****)s_<ArrayOfClass>_180040de0._0_8_;
  lVar2 = FUN_1800213d0();
  puVar3 = FUN_180021460(lVar2);
  while (puVar3 != (uchar *)0x0) {
    local_58[0] = 0x20;
    puVar3 = _mbstok(puVar3,(uchar *)local_58);
    if (((puVar3 != (uchar *)0x0) &&
        (_Src = _mbstok((uchar *)0x0,(uchar *)local_58), _Src != (uchar *)0x0)) &&
       (_Src_00 = _mbstok((uchar *)0x0,(uchar *)local_58), _Src_00 != (uchar *)0x0)) {
      if (local_38 - local_40 < 0xf) {
        FUN_18000aa90(&local_50,0xf,0,"<Class><Action>",0xf);
      }
      else {
        ppppcVar4 = (char ****)&local_50;
        if (0xf < local_38) {
          ppppcVar4 = local_50;
        }
        pcVar6 = (char *)((longlong)ppppcVar4 + local_40);
        local_40 = local_40 + 0xf;
        memmove(pcVar6,"<Class><Action>",0xf);
        pcVar6[0xf] = '\0';
      }
      uVar7 = 0xffffffffffffffff;
      do {
        uVar7 = uVar7 + 1;
      } while (puVar3[uVar7] != '\0');
      if (local_38 - local_40 < uVar7) {
        FUN_18000aa90(&local_50,uVar7,0,puVar3,uVar7);
      }
      else {
        ppppcVar4 = (char ****)&local_50;
        if (0xf < local_38) {
          ppppcVar4 = local_50;
        }
        pcVar6 = (char *)((longlong)ppppcVar4 + local_40);
        local_40 = uVar7 + local_40;
        memmove(pcVar6,puVar3,uVar7);
        pcVar6[uVar7] = '\0';
      }
      if (local_38 - local_40 < 0xf) {
        FUN_18000aa90(&local_50,0xf,0,"</Action><Type>",0xf);
      }
      else {
        ppppcVar4 = (char ****)&local_50;
        if (0xf < local_38) {
          ppppcVar4 = local_50;
        }
        pcVar6 = (char *)((longlong)ppppcVar4 + local_40);
        local_40 = local_40 + 0xf;
        memmove(pcVar6,"</Action><Type>",0xf);
        pcVar6[0xf] = '\0';
      }
      uVar7 = 0xffffffffffffffff;
      do {
        uVar7 = uVar7 + 1;
      } while (_Src[uVar7] != '\0');
      if (local_38 - local_40 < uVar7) {
        FUN_18000aa90(&local_50,uVar7,0,_Src,uVar7);
      }
      else {
        ppppcVar4 = (char ****)&local_50;
        if (0xf < local_38) {
          ppppcVar4 = local_50;
        }
        pcVar6 = (char *)((longlong)ppppcVar4 + local_40);
        local_40 = local_40 + uVar7;
        memmove(pcVar6,_Src,uVar7);
        pcVar6[uVar7] = '\0';
      }
      if (local_38 - local_40 < 0xe) {
        FUN_18000aa90(&local_50,0xe,0,"</Type><Block>",0xe);
      }
      else {
        ppppcVar4 = (char ****)&local_50;
        if (0xf < local_38) {
          ppppcVar4 = local_50;
        }
        pcVar6 = (char *)((longlong)ppppcVar4 + local_40);
        local_40 = local_40 + 0xe;
        memmove(pcVar6,"</Type><Block>",0xe);
        pcVar6[0xe] = '\0';
      }
      uVar7 = 0xffffffffffffffff;
      do {
        uVar7 = uVar7 + 1;
      } while (_Src_00[uVar7] != '\0');
      if (local_38 - local_40 < uVar7) {
        FUN_18000aa90(&local_50,uVar7,0,_Src_00,uVar7);
      }
      else {
        ppppcVar4 = (char ****)&local_50;
        if (0xf < local_38) {
          ppppcVar4 = local_50;
        }
        pcVar6 = (char *)((longlong)ppppcVar4 + local_40);
        local_40 = local_40 + uVar7;
        memmove(pcVar6,_Src_00,uVar7);
        pcVar6[uVar7] = '\0';
      }
      if (local_38 - local_40 < 0x10) {
        FUN_18000aa90(&local_50,0x10,0,"</Block></Class>",0x10);
      }
      else {
        ppppcVar4 = (char ****)&local_50;
        if (0xf < local_38) {
          ppppcVar4 = local_50;
        }
        pcVar6 = (char *)((longlong)ppppcVar4 + local_40);
        local_40 = local_40 + 0x10;
        memmove(pcVar6,"</Block></Class>",0x10);
        pcVar6[0x10] = '\0';
      }
    }
    puVar3 = FUN_180021460(lVar2);
  }
  if (local_38 - local_40 < 0xf) {
    FUN_18000aa90(&local_50,0xf,0,"</ArrayOfClass>",0xf);
  }
  else {
    ppppcVar4 = (char ****)&local_50;
    if (0xf < local_38) {
      ppppcVar4 = local_50;
    }
    pcVar6 = (char *)((longlong)ppppcVar4 + local_40);
    local_40 = local_40 + 0xf;
    memmove(pcVar6,"</ArrayOfClass>",0xf);
    pcVar6[0xf] = '\0';
  }
  ppppcVar4 = (char ****)&local_50;
  lVar2 = -1;
  if (0xf < local_38) {
    ppppcVar4 = local_50;
  }
  do {
    lVar8 = lVar2;
    lVar2 = lVar8 + 1;
  } while (*(char *)((longlong)ppppcVar4 + lVar8 + 1) != '\0');
  pvVar5 = GlobalAlloc(0,lVar8 + 2);
  ppppcVar4 = (char ****)&local_50;
  if (0xf < local_38) {
    ppppcVar4 = local_50;
  }
  lVar2 = (longlong)pvVar5 - (longlong)ppppcVar4;
  do {
    cVar1 = *(char *)ppppcVar4;
    *(char *)((longlong)ppppcVar4 + lVar2) = cVar1;
    ppppcVar4 = (char ****)((longlong)ppppcVar4 + 1);
  } while (cVar1 != '\0');
  if (0xf < local_38) {
    ppppcVar4 = local_50;
    if ((0xfff < local_38 + 1) &&
       (ppppcVar4 = (char ****)local_50[-1],
       (char *)0x1f < (char *)((longlong)local_50 + (-8 - (longlong)ppppcVar4)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180001300(ppppcVar4);
  }
  return pvVar5;
}

/* RVA 0x12400 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HGLOBAL SimShowPointsList(int param_1)

{
  char cVar1;
  void *pvVar2;
  longlong lVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  ulonglong uVar7;
  CSimpleStringT<char,1> *pCVar8;
  HGLOBAL pvVar9;
  longlong *plVar10;
  char ****ppppcVar11;
  char *pcVar12;
  char *pcVar13;
  ulonglong uVar14;
  longlong lVar15;
  undefined **ppuVar16;
  longlong lVar17;
  longlong lVar18;
  longlong lVar19;
  CSimSeqObj *pCVar20;
  ulonglong uVar21;
  undefined1 auStackY_e8 [32];
  undefined **local_a8;
  longlong local_a0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_90 [8];
  char ****local_88;
  char local_80 [4];
  char local_7c [2];
  undefined2 local_7a;
  longlong local_78;
  ulonglong local_70;
  char local_68 [16];
  char local_58 [16];
  char local_48 [16];
  ulonglong local_38;
  
                    /* 0x12400  160  SimShowPointsList */
  local_38 = DAT_1800516d8 ^ (ulonglong)auStackY_e8;
  (*(code *)PTR_FUN_180044148)(&DAT_18003f720,1);
  local_80[0] = s_<ArrayOfClass>_180040de0[8];
  local_80[1] = s_<ArrayOfClass>_180040de0[9];
  local_80[2] = s_<ArrayOfClass>_180040de0[10];
  local_80[3] = s_<ArrayOfClass>_180040de0[0xb];
  local_7c[0] = s_<ArrayOfClass>_180040de0[0xc];
  local_7c[1] = s_<ArrayOfClass>_180040de0[0xd];
  local_7a = 0;
  local_78 = 0xe;
  local_70 = 0xf;
  local_88 = (char ****)s_<ArrayOfClass>_180040de0._0_8_;
  if (param_1 == 0) {
    ppuVar16 = &PTR_s_Block_18004fd10;
    puVar6 = PTR_s_Block_18004fd10;
  }
  else if (param_1 == 1) {
    ppuVar16 = &PTR_s_Block_18004f8d0;
    puVar6 = PTR_s_Block_18004f8d0;
  }
  else if (param_1 == 3) {
    ppuVar16 = &PTR_s_Simulation_180050720;
    puVar6 = PTR_s_Simulation_180050720;
  }
  else {
    puVar6 = PTR_s_All_Blocks_and_Streams_18004fc70;
    if (param_1 == 4) {
      ppuVar16 = &PTR_s_All_Blocks_and_Streams_18004fc70;
    }
    else if (param_1 == 5) {
      ppuVar16 = &PTR_s_All_Blocks_and_Streams_18004fc70;
    }
    else {
      ppuVar16 = &PTR_s_Block_1800504c0;
      puVar6 = PTR_s_Block_1800504c0;
    }
  }
  uVar21 = 0xffffffffffffffff;
  if (puVar6 != (undefined *)0x0) {
    local_a0 = 0;
    local_a8 = ppuVar16;
    do {
      lVar15 = 0;
      if ((-1 < *(int *)(local_a8 + 2)) &&
         (((param_1 != 3 || (*(int *)(local_a8 + 2) == 0)) ||
          (iVar4 = (*(code *)PTR_FUN_180044150)(), iVar4 != 0)))) {
        if ((*(int *)(local_a8 + 2) == 2) &&
           (uVar7 = FUN_18000ae30(0x18004f600,local_a8[3],*(int *)(local_a8 + 4)),
           (char)uVar7 == '\0')) {
          if (local_70 - local_78 < 0xd) {
            FUN_18000aa90(&local_88,0xd,0,"<Class><name>",0xd);
          }
          else {
            ppppcVar11 = (char ****)&local_88;
            if (0xf < local_70) {
              ppppcVar11 = local_88;
            }
            pcVar12 = (char *)((longlong)ppppcVar11 + local_78);
            local_78 = local_78 + 0xd;
            memmove(pcVar12,"<Class><name>",0xd);
            pcVar12[0xd] = '\0';
          }
          puVar6 = *local_a8;
          uVar7 = uVar21;
          do {
            uVar7 = uVar7 + 1;
          } while (puVar6[uVar7] != '\0');
          if (local_70 - local_78 < uVar7) {
            FUN_18000aa90(&local_88,uVar7,0,puVar6,uVar7);
          }
          else {
            ppppcVar11 = (char ****)&local_88;
            if (0xf < local_70) {
              ppppcVar11 = local_88;
            }
            pcVar12 = (char *)((longlong)ppppcVar11 + local_78);
            local_78 = uVar7 + local_78;
            memmove(pcVar12,puVar6,uVar7);
            pcVar12[uVar7] = '\0';
          }
          if (local_70 - local_78 < 0x1e) {
            FUN_18000aa90(&local_88,0x1e,0,"</name><Items></Items></Class>",0x1e);
          }
          else {
            ppppcVar11 = (char ****)&local_88;
            if (0xf < local_70) {
              ppppcVar11 = local_88;
            }
            pcVar12 = (char *)((longlong)ppppcVar11 + local_78);
            local_78 = local_78 + 0x1e;
            memmove(pcVar12,"</name><Items></Items></Class>",0x1e);
            pcVar12[0x1e] = '\0';
          }
        }
        else {
          if (local_70 - local_78 < 0xd) {
            FUN_18000aa90(&local_88,0xd,0,"<Class><name>",0xd);
          }
          else {
            ppppcVar11 = (char ****)&local_88;
            if (0xf < local_70) {
              ppppcVar11 = local_88;
            }
            pcVar12 = (char *)((longlong)ppppcVar11 + local_78);
            local_78 = local_78 + 0xd;
            memmove(pcVar12,"<Class><name>",0xd);
            pcVar12[0xd] = '\0';
          }
          puVar6 = *local_a8;
          uVar7 = uVar21;
          do {
            uVar7 = uVar7 + 1;
          } while (puVar6[uVar7] != '\0');
          if (local_70 - local_78 < uVar7) {
            FUN_18000aa90(&local_88,uVar7,0,puVar6,uVar7);
          }
          else {
            ppppcVar11 = (char ****)&local_88;
            if (0xf < local_70) {
              ppppcVar11 = local_88;
            }
            pcVar12 = (char *)((longlong)ppppcVar11 + local_78);
            local_78 = uVar7 + local_78;
            memmove(pcVar12,puVar6,uVar7);
            pcVar12[uVar7] = '\0';
          }
          if (local_70 - local_78 < 0xe) {
            FUN_18000aa90(&local_88,0xe,0,"</name><Items>",0xe);
          }
          else {
            ppppcVar11 = (char ****)&local_88;
            if (0xf < local_70) {
              ppppcVar11 = local_88;
            }
            pcVar12 = (char *)((longlong)ppppcVar11 + local_78);
            local_78 = local_78 + 0xe;
            memmove(pcVar12,"</name><Items>",0xe);
            pcVar12[0xe] = '\0';
          }
          iVar4 = *(int *)(local_a8 + 2);
          if (iVar4 == 0) {
            if (local_70 - local_78 < 0x10) {
              FUN_18000aa90(&local_88,0x10,0,"</Items></Class>",0x10);
            }
            else {
              ppppcVar11 = (char ****)&local_88;
              if (0xf < local_70) {
                ppppcVar11 = local_88;
              }
              pcVar12 = (char *)((longlong)ppppcVar11 + local_78);
              local_78 = local_78 + 0x10;
              memmove(pcVar12,"</Items></Class>",0x10);
              pcVar12[0x10] = '\0';
            }
          }
          else {
            plVar10 = &DAT_18004f608;
            if (iVar4 == 0xc) {
              plVar10 = &DAT_18004f628;
            }
            iVar5 = (int)(plVar10[1] - *plVar10 >> 5);
            lVar17 = (longlong)iVar5;
            if (0 < iVar5) {
              lVar19 = lVar17;
              do {
                lVar18 = lVar19;
                lVar19 = DAT_18004f608;
                if (iVar4 == 0xc) {
                  lVar19 = DAT_18004f628;
                }
                pCVar20 = (CSimSeqObj *)(lVar19 + lVar15);
                if ((pCVar20 != (CSimSeqObj *)0x0) && (*(int *)(pCVar20 + 0x10) == -1)) {
                  if (local_70 - local_78 < 0xc) {
                    FUN_18000aa90(&local_88,0xc,0,"<Item><Name>",0xc);
                  }
                  else {
                    ppppcVar11 = (char ****)&local_88;
                    if (0xf < local_70) {
                      ppppcVar11 = local_88;
                    }
                    pcVar12 = (char *)((longlong)ppppcVar11 + local_78);
                    local_78 = local_78 + 0xc;
                    memmove(pcVar12,"<Item><Name>",0xc);
                    pcVar12[0xc] = '\0';
                  }
                  pcVar12 = *(char **)(pCVar20 + 8);
                  uVar21 = 0xffffffffffffffff;
                  do {
                    uVar21 = uVar21 + 1;
                  } while (pcVar12[uVar21] != '\0');
                  if (local_70 - local_78 < uVar21) {
                    FUN_18000aa90(&local_88,uVar21,0,pcVar12,uVar21);
                  }
                  else {
                    ppppcVar11 = (char ****)&local_88;
                    if (0xf < local_70) {
                      ppppcVar11 = local_88;
                    }
                    pcVar13 = (char *)((longlong)ppppcVar11 + local_78);
                    local_78 = local_78 + uVar21;
                    memmove(pcVar13,pcVar12,uVar21);
                    pcVar13[uVar21] = '\0';
                  }
                  if (local_70 - local_78 < 0xe) {
                    pcVar12 = "</Name><Image>";
                    FUN_18000aa90(&local_88,0xe,0,"</Name><Image>",0xe);
                  }
                  else {
                    ppppcVar11 = (char ****)&local_88;
                    if (0xf < local_70) {
                      ppppcVar11 = local_88;
                    }
                    pcVar13 = (char *)((longlong)ppppcVar11 + local_78);
                    local_78 = local_78 + 0xe;
                    memmove(pcVar13,"</Name><Image>",0xe);
                    pcVar13[0xe] = '\0';
                  }
                  if (local_70 - local_78 < 10) {
                    pcVar12 = "Folder.ico";
                    FUN_18000aa90(&local_88,10,0,"Folder.ico",10);
                  }
                  else {
                    ppppcVar11 = (char ****)&local_88;
                    if (0xf < local_70) {
                      ppppcVar11 = local_88;
                    }
                    pcVar13 = (char *)((longlong)ppppcVar11 + local_78);
                    local_78 = local_78 + 10;
                    memmove(pcVar13,"Folder.ico",10);
                    pcVar13[10] = '\0';
                  }
                  if (local_70 - local_78 < 0xe) {
                    pcVar12 = "</Image><Type>";
                    FUN_18000aa90(&local_88,0xe,0,"</Image><Type>",0xe);
                  }
                  else {
                    ppppcVar11 = (char ****)&local_88;
                    if (0xf < local_70) {
                      ppppcVar11 = local_88;
                    }
                    pcVar13 = (char *)((longlong)ppppcVar11 + local_78);
                    local_78 = local_78 + 0xe;
                    memmove(pcVar13,"</Image><Type>",0xe);
                    pcVar13[0xe] = '\0';
                  }
                  local_68[0] = '\0';
                  local_68[1] = '\0';
                  local_68[2] = '\0';
                  local_68[3] = '\0';
                  local_68[4] = '\0';
                  local_68[5] = '\0';
                  local_68[6] = '\0';
                  local_68[7] = '\0';
                  local_68[8] = '\0';
                  local_68[9] = '\0';
                  local_68[10] = '\0';
                  local_68[0xb] = '\0';
                  FUN_180008f80(local_68,&DAT_180040814,(ulonglong)*(uint *)(pCVar20 + 0x10),pcVar12
                               );
                  lVar19 = local_78;
                  uVar21 = 0xffffffffffffffff;
                  do {
                    uVar7 = uVar21 + 1;
                    lVar3 = uVar21 + 1;
                    uVar21 = uVar7;
                  } while (local_68[lVar3] != '\0');
                  if (local_70 - local_78 < uVar7) {
                    FUN_18000aa90(&local_88,uVar7,0,local_68,uVar7);
                  }
                  else {
                    ppppcVar11 = (char ****)&local_88;
                    if (0xf < local_70) {
                      ppppcVar11 = local_88;
                    }
                    pcVar12 = (char *)((longlong)ppppcVar11 + local_78);
                    local_78 = local_78 + uVar7;
                    memmove(pcVar12,local_68,uVar7);
                    *(char *)((longlong)ppppcVar11 + lVar19 + uVar7) = '\0';
                  }
                  if (local_70 - local_78 < 0xc) {
                    FUN_18000aa90(&local_88,0xc,0,"</Type><Tag>",0xc);
                  }
                  else {
                    ppppcVar11 = (char ****)&local_88;
                    if (0xf < local_70) {
                      ppppcVar11 = local_88;
                    }
                    pcVar12 = (char *)((longlong)ppppcVar11 + local_78);
                    local_78 = local_78 + 0xc;
                    memmove(pcVar12,"</Type><Tag>",0xc);
                    pcVar12[0xc] = '\0';
                  }
                  lVar19 = local_78;
                  pvVar2 = *(void **)(pCVar20 + 8);
                  uVar21 = 0xffffffffffffffff;
                  do {
                    uVar21 = uVar21 + 1;
                  } while (*(char *)((longlong)pvVar2 + uVar21) != '\0');
                  if (local_70 - local_78 < uVar21) {
                    FUN_18000aa90(&local_88,uVar21,0,pvVar2,uVar21);
                  }
                  else {
                    ppppcVar11 = (char ****)&local_88;
                    if (0xf < local_70) {
                      ppppcVar11 = local_88;
                    }
                    pcVar12 = (char *)((longlong)ppppcVar11 + local_78);
                    local_78 = local_78 + uVar21;
                    memmove(pcVar12,pvVar2,uVar21);
                    *(char *)((longlong)ppppcVar11 + lVar19 + uVar21) = '\0';
                  }
                  if (local_70 - local_78 < 0x24) {
                    FUN_18000aa90(&local_88,0x24,0,"</Tag><IsExpanded>false</IsExpanded>",0x24);
                  }
                  else {
                    ppppcVar11 = (char ****)&local_88;
                    if (0xf < local_70) {
                      ppppcVar11 = local_88;
                    }
                    pcVar12 = (char *)((longlong)ppppcVar11 + local_78);
                    local_78 = local_78 + 0x24;
                    memmove(pcVar12,"</Tag><IsExpanded>false</IsExpanded>",0x24);
                    pcVar12[0x24] = '\0';
                  }
                  pCVar8 = (CSimpleStringT<char,1> *)
                           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                           CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                     (local_90,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                                *)(pCVar20 + 8));
                  FUN_18000af00(pCVar8,pCVar20,(longlong *)&local_88,local_a8[3],
                                *(uint *)(local_a8 + 4));
                  if (local_70 - local_78 < 7) {
                    FUN_18000aa90(&local_88,7,0,"</Item>",7);
                  }
                  else {
                    ppppcVar11 = (char ****)&local_88;
                    if (0xf < local_70) {
                      ppppcVar11 = local_88;
                    }
                    pcVar12 = (char *)((longlong)ppppcVar11 + local_78);
                    local_78 = local_78 + 7;
                    memmove(pcVar12,"</Item>",7);
                    pcVar12[7] = '\0';
                  }
                }
                lVar15 = lVar15 + 0x20;
                lVar19 = lVar18 + -1;
              } while (lVar19 != 0);
              uVar21 = lVar18 - 2;
            }
            lVar15 = 0;
            if (local_a8[3] != (undefined *)0x0) {
              if (local_70 - local_78 < 0xc) {
                FUN_18000aa90(&local_88,0xc,0,"<Item><Name>",0xc);
              }
              else {
                ppppcVar11 = (char ****)&local_88;
                if (0xf < local_70) {
                  ppppcVar11 = local_88;
                }
                pcVar12 = (char *)((longlong)ppppcVar11 + local_78);
                local_78 = local_78 + 0xc;
                memmove(pcVar12,"<Item><Name>",0xc);
                pcVar12[0xc] = '\0';
              }
              pcVar12 = local_a8[3];
              uVar7 = uVar21;
              do {
                uVar7 = uVar7 + 1;
              } while (pcVar12[uVar7] != '\0');
              if (local_70 - local_78 < uVar7) {
                FUN_18000aa90(&local_88,uVar7,0,pcVar12,uVar7);
              }
              else {
                ppppcVar11 = (char ****)&local_88;
                if (0xf < local_70) {
                  ppppcVar11 = local_88;
                }
                pcVar13 = (char *)((longlong)ppppcVar11 + local_78);
                local_78 = local_78 + uVar7;
                memmove(pcVar13,pcVar12,uVar7);
                pcVar13[uVar7] = '\0';
              }
              if (local_70 - local_78 < 0xe) {
                pcVar12 = "</Name><Image>";
                FUN_18000aa90(&local_88,0xe,0,"</Name><Image>",0xe);
              }
              else {
                ppppcVar11 = (char ****)&local_88;
                if (0xf < local_70) {
                  ppppcVar11 = local_88;
                }
                pcVar13 = (char *)((longlong)ppppcVar11 + local_78);
                local_78 = local_78 + 0xe;
                memmove(pcVar13,"</Name><Image>",0xe);
                pcVar13[0xe] = '\0';
              }
              if (local_70 - local_78 < 0xc) {
                pcVar12 = "FormNode.png";
                FUN_18000aa90(&local_88,0xc,0,"FormNode.png",0xc);
              }
              else {
                ppppcVar11 = (char ****)&local_88;
                if (0xf < local_70) {
                  ppppcVar11 = local_88;
                }
                pcVar13 = (char *)((longlong)ppppcVar11 + local_78);
                local_78 = local_78 + 0xc;
                memmove(pcVar13,"FormNode.png",0xc);
                pcVar13[0xc] = '\0';
              }
              if (local_70 - local_78 < 0xe) {
                pcVar12 = "</Image><Type>";
                FUN_18000aa90(&local_88,0xe,0,"</Image><Type>",0xe);
              }
              else {
                ppppcVar11 = (char ****)&local_88;
                if (0xf < local_70) {
                  ppppcVar11 = local_88;
                }
                pcVar13 = (char *)((longlong)ppppcVar11 + local_78);
                local_78 = local_78 + 0xe;
                memmove(pcVar13,"</Image><Type>",0xe);
                pcVar13[0xe] = '\0';
              }
              local_58[0] = '\0';
              local_58[1] = '\0';
              local_58[2] = '\0';
              local_58[3] = '\0';
              local_58[4] = '\0';
              local_58[5] = '\0';
              local_58[6] = '\0';
              local_58[7] = '\0';
              local_58[8] = '\0';
              local_58[9] = '\0';
              local_58[10] = '\0';
              local_58[0xb] = '\0';
              FUN_180008f80(local_58,&DAT_180040814,(ulonglong)*(uint *)(local_a8 + 4),pcVar12);
              uVar7 = uVar21;
              do {
                uVar14 = uVar7 + 1;
                lVar19 = uVar7 + 1;
                uVar7 = uVar14;
              } while (local_58[lVar19] != '\0');
              if (local_70 - local_78 < uVar14) {
                FUN_18000aa90(&local_88,uVar14,0,local_58,uVar14);
              }
              else {
                ppppcVar11 = (char ****)&local_88;
                if (0xf < local_70) {
                  ppppcVar11 = local_88;
                }
                pcVar12 = (char *)((longlong)ppppcVar11 + local_78);
                local_78 = uVar14 + local_78;
                memmove(pcVar12,local_58,uVar14);
                pcVar12[uVar14] = '\0';
              }
              if (local_70 - local_78 < 0xc) {
                FUN_18000aa90(&local_88,0xc,0,"</Type><Tag>",0xc);
              }
              else {
                ppppcVar11 = (char ****)&local_88;
                if (0xf < local_70) {
                  ppppcVar11 = local_88;
                }
                pcVar12 = (char *)((longlong)ppppcVar11 + local_78);
                local_78 = local_78 + 0xc;
                memmove(pcVar12,"</Type><Tag>",0xc);
                pcVar12[0xc] = '\0';
              }
              puVar6 = local_a8[3];
              uVar7 = uVar21;
              do {
                uVar7 = uVar7 + 1;
              } while (puVar6[uVar7] != '\0');
              if (local_70 - local_78 < uVar7) {
                FUN_18000aa90(&local_88,uVar7,0,puVar6,uVar7);
              }
              else {
                ppppcVar11 = (char ****)&local_88;
                if (0xf < local_70) {
                  ppppcVar11 = local_88;
                }
                pcVar12 = (char *)((longlong)ppppcVar11 + local_78);
                local_78 = local_78 + uVar7;
                memmove(pcVar12,puVar6,uVar7);
                pcVar12[uVar7] = '\0';
              }
              if (local_70 - local_78 < 0xd) {
                FUN_18000aa90(&local_88,0xd,0,"</Tag></Item>",0xd);
              }
              else {
                ppppcVar11 = (char ****)&local_88;
                if (0xf < local_70) {
                  ppppcVar11 = local_88;
                }
                pcVar12 = (char *)((longlong)ppppcVar11 + local_78);
                local_78 = local_78 + 0xd;
                memmove(pcVar12,"</Tag></Item>",0xd);
                pcVar12[0xd] = '\0';
              }
            }
            if (0 < lVar17) {
              do {
                lVar19 = DAT_18004f608;
                if (iVar4 == 0xc) {
                  lVar19 = DAT_18004f628;
                }
                lVar19 = lVar19 + lVar15;
                if ((lVar19 != 0) && (*(int *)(lVar19 + 0x10) == *(int *)(local_a8 + 4))) {
                  if (local_70 - local_78 < 0xc) {
                    FUN_18000aa90(&local_88,0xc,0,"<Item><Name>",0xc);
                  }
                  else {
                    ppppcVar11 = (char ****)&local_88;
                    if (0xf < local_70) {
                      ppppcVar11 = local_88;
                    }
                    pcVar12 = (char *)((longlong)ppppcVar11 + local_78);
                    local_78 = local_78 + 0xc;
                    memmove(pcVar12,"<Item><Name>",0xc);
                    pcVar12[0xc] = '\0';
                  }
                  pcVar12 = *(char **)(lVar19 + 8);
                  uVar7 = uVar21;
                  do {
                    uVar7 = uVar7 + 1;
                  } while (pcVar12[uVar7] != '\0');
                  if (local_70 - local_78 < uVar7) {
                    FUN_18000aa90(&local_88,uVar7,0,pcVar12,uVar7);
                  }
                  else {
                    ppppcVar11 = (char ****)&local_88;
                    if (0xf < local_70) {
                      ppppcVar11 = local_88;
                    }
                    pcVar13 = (char *)((longlong)ppppcVar11 + local_78);
                    local_78 = local_78 + uVar7;
                    memmove(pcVar13,pcVar12,uVar7);
                    pcVar13[uVar7] = '\0';
                  }
                  if (local_70 - local_78 < 0xe) {
                    pcVar12 = "</Name><Image>";
                    FUN_18000aa90(&local_88,0xe,0,"</Name><Image>",0xe);
                  }
                  else {
                    ppppcVar11 = (char ****)&local_88;
                    if (0xf < local_70) {
                      ppppcVar11 = local_88;
                    }
                    pcVar13 = (char *)((longlong)ppppcVar11 + local_78);
                    local_78 = local_78 + 0xe;
                    memmove(pcVar13,"</Name><Image>",0xe);
                    pcVar13[0xe] = '\0';
                  }
                  if (local_70 - local_78 < 0xc) {
                    pcVar12 = "FormNode.png";
                    FUN_18000aa90(&local_88,0xc,0,"FormNode.png",0xc);
                  }
                  else {
                    ppppcVar11 = (char ****)&local_88;
                    if (0xf < local_70) {
                      ppppcVar11 = local_88;
                    }
                    pcVar13 = (char *)((longlong)ppppcVar11 + local_78);
                    local_78 = local_78 + 0xc;
                    memmove(pcVar13,"FormNode.png",0xc);
                    pcVar13[0xc] = '\0';
                  }
                  if (local_70 - local_78 < 0xe) {
                    pcVar12 = "</Image><Type>";
                    FUN_18000aa90(&local_88,0xe,0,"</Image><Type>",0xe);
                  }
                  else {
                    ppppcVar11 = (char ****)&local_88;
                    if (0xf < local_70) {
                      ppppcVar11 = local_88;
                    }
                    pcVar13 = (char *)((longlong)ppppcVar11 + local_78);
                    local_78 = local_78 + 0xe;
                    memmove(pcVar13,"</Image><Type>",0xe);
                    pcVar13[0xe] = '\0';
                  }
                  local_48[0] = '\0';
                  local_48[1] = '\0';
                  local_48[2] = '\0';
                  local_48[3] = '\0';
                  local_48[4] = '\0';
                  local_48[5] = '\0';
                  local_48[6] = '\0';
                  local_48[7] = '\0';
                  local_48[8] = '\0';
                  local_48[9] = '\0';
                  local_48[10] = '\0';
                  local_48[0xb] = '\0';
                  FUN_180008f80(local_48,&DAT_180040814,(ulonglong)*(uint *)(local_a8 + 4),pcVar12);
                  uVar7 = uVar21;
                  do {
                    uVar14 = uVar7 + 1;
                    lVar18 = uVar7 + 1;
                    uVar7 = uVar14;
                  } while (local_48[lVar18] != '\0');
                  if (local_70 - local_78 < uVar14) {
                    FUN_18000aa90(&local_88,uVar14,0,local_48,uVar14);
                  }
                  else {
                    ppppcVar11 = (char ****)&local_88;
                    if (0xf < local_70) {
                      ppppcVar11 = local_88;
                    }
                    pcVar12 = (char *)((longlong)ppppcVar11 + local_78);
                    local_78 = local_78 + uVar14;
                    memmove(pcVar12,local_48,uVar14);
                    pcVar12[uVar14] = '\0';
                  }
                  if (local_70 - local_78 < 0xc) {
                    FUN_18000aa90(&local_88,0xc,0,"</Type><Tag>",0xc);
                  }
                  else {
                    ppppcVar11 = (char ****)&local_88;
                    if (0xf < local_70) {
                      ppppcVar11 = local_88;
                    }
                    pcVar12 = (char *)((longlong)ppppcVar11 + local_78);
                    local_78 = local_78 + 0xc;
                    memmove(pcVar12,"</Type><Tag>",0xc);
                    pcVar12[0xc] = '\0';
                  }
                  pvVar2 = *(void **)(lVar19 + 8);
                  uVar7 = uVar21;
                  do {
                    uVar7 = uVar7 + 1;
                  } while (*(char *)((longlong)pvVar2 + uVar7) != '\0');
                  if (local_70 - local_78 < uVar7) {
                    FUN_18000aa90(&local_88,uVar7,0,pvVar2,uVar7);
                  }
                  else {
                    ppppcVar11 = (char ****)&local_88;
                    if (0xf < local_70) {
                      ppppcVar11 = local_88;
                    }
                    pcVar12 = (char *)((longlong)ppppcVar11 + local_78);
                    local_78 = uVar7 + local_78;
                    memmove(pcVar12,pvVar2,uVar7);
                    pcVar12[uVar7] = '\0';
                  }
                  if (local_70 - local_78 < 0xd) {
                    FUN_18000aa90(&local_88,0xd,0,"</Tag></Item>",0xd);
                  }
                  else {
                    ppppcVar11 = (char ****)&local_88;
                    if (0xf < local_70) {
                      ppppcVar11 = local_88;
                    }
                    pcVar12 = (char *)((longlong)ppppcVar11 + local_78);
                    local_78 = local_78 + 0xd;
                    memmove(pcVar12,"</Tag></Item>",0xd);
                    pcVar12[0xd] = '\0';
                  }
                }
                lVar15 = lVar15 + 0x20;
                lVar17 = lVar17 + -1;
              } while (lVar17 != 0);
            }
            if (local_70 - local_78 < 0x10) {
              FUN_18000aa90(&local_88,0x10,0,"</Items></Class>",0x10);
            }
            else {
              ppppcVar11 = (char ****)&local_88;
              if (0xf < local_70) {
                ppppcVar11 = local_88;
              }
              pcVar12 = (char *)((longlong)ppppcVar11 + local_78);
              local_78 = local_78 + 0x10;
              memmove(pcVar12,"</Items></Class>",0x10);
              pcVar12[0x10] = '\0';
            }
          }
        }
      }
      local_a0 = local_a0 + 1;
      local_a8 = ppuVar16 + local_a0 * 5;
    } while (ppuVar16[local_a0 * 5] != (undefined *)0x0);
  }
  if (local_70 - local_78 < 0xf) {
    FUN_18000aa90(&local_88,0xf,0,"</ArrayOfClass>",0xf);
  }
  else {
    ppppcVar11 = (char ****)&local_88;
    if (0xf < local_70) {
      ppppcVar11 = local_88;
    }
    pcVar12 = (char *)((longlong)ppppcVar11 + local_78);
    local_78 = local_78 + 0xf;
    memmove(pcVar12,"</ArrayOfClass>",0xf);
    pcVar12[0xf] = '\0';
  }
  ppppcVar11 = (char ****)&local_88;
  if (0xf < local_70) {
    ppppcVar11 = local_88;
  }
  do {
    uVar7 = uVar21;
    uVar21 = uVar7 + 1;
  } while (*(char *)((longlong)ppppcVar11 + uVar7 + 1) != '\0');
  pvVar9 = GlobalAlloc(0,uVar7 + 2);
  ppppcVar11 = (char ****)&local_88;
  if (0xf < local_70) {
    ppppcVar11 = local_88;
  }
  lVar15 = (longlong)pvVar9 - (longlong)ppppcVar11;
  do {
    cVar1 = *(char *)ppppcVar11;
    *(char *)((longlong)ppppcVar11 + lVar15) = cVar1;
    ppppcVar11 = (char ****)((longlong)ppppcVar11 + 1);
  } while (cVar1 != '\0');
  if (0xf < local_70) {
    ppppcVar11 = local_88;
    if ((0xfff < local_70 + 1) &&
       (ppppcVar11 = (char ****)local_88[-1],
       (char *)0x1f < (char *)((longlong)local_88 + (-8 - (longlong)ppppcVar11)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180001300(ppppcVar11);
  }
  return pvVar9;
}

/* RVA 0x13720 */
void SimShowStopPointErrorLevel(void)

{
  int iVar1;
  char *pcVar2;
  undefined8 local_res8 [4];
  
                    /* 0x13720  162  SimShowStopPointErrorLevel */
  FUN_1800208a0(*(longlong *)(*(longlong *)topfinfo_exref + 0x560),local_res8);
  iVar1 = FUN_180020c20(*(longlong *)(*(longlong *)topfinfo_exref + 0x560));
  pcVar2 = GlobalAlloc(0,2);
  *pcVar2 = (char)iVar1 + '0';
  pcVar2[1] = '\0';
  return;
}

/* RVA 0x13780 */
void SimStep(undefined8 param_1,undefined8 param_2,int *param_3,char *param_4)

{
                    /* 0x13780  53  SimStep */
  SimMain((char *)0x5,(IMAGE_DOS_HEADER *)0x0,param_3,param_4);
  return;
}

