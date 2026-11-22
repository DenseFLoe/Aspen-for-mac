/* RVA 0x31650 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180031650(IUnknown *param_1,undefined8 param_2,void **param_3)

{
  int *piVar1;
  uchar (*pauVar2) [8];
  _func_5156 *p_Var3;
  _func_5157 *p_Var4;
  _func_5158 *p_Var5;
  uchar auVar6 [8];
  IUnknown *pIVar7;
  undefined8 uVar8;
  SAFEARRAY *psa;
  ULONG UVar9;
  HRESULT HVar10;
  undefined8 *puVar11;
  longlong lVar12;
  uchar (*pauVar13) [8];
  longlong lVar14;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  ulonglong uVar15;
  int iVar16;
  char *pcVar17;
  undefined1 *puVar18;
  undefined1 *puVar19;
  undefined1 *puVar20;
  void **ppvObject;
  undefined8 uStack_f0;
  undefined1 auStack_e8 [32];
  undefined8 uStack_c8;
  int aiStack_c0 [2];
  undefined8 local_b8 [2];
  LONG local_a8;
  short sStack_a4;
  undefined2 local_a0;
  LONG LStack_9c;
  IUnknown *local_98;
  uchar (*local_90) [8];
  uchar (*local_88) [8];
  undefined8 local_80;
  SAFEARRAY *local_78;
  uchar local_70 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_68 [8];
  SAFEARRAY *local_60;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_58 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_50 [8];
  uchar (*local_48) [8];
  uchar (**local_40) [8];
  ulonglong local_38;
  
  local_38 = DAT_180052888 ^ (ulonglong)&local_a8;
  local_80 = 0;
  uStack_f0 = 0x180031698;
  UVar9 = (*param_1->lpVtbl[4].AddRef)(param_1);
  if ((int)UVar9 < 0) {
    param_3 = (void **)&DAT_1800424d8;
    uStack_f0 = 0x1800316ad;
    _com_issue_errorex(UVar9,param_1,(_GUID *)&DAT_1800424d8);
  }
  uVar8 = local_80;
  uStack_f0 = 0x1800316bb;
  puVar11 = operator_new(0x18);
  local_60 = (SAFEARRAY *)puVar11;
  if (puVar11 == (undefined8 *)0x0) {
    puVar11 = (undefined8 *)0x0;
  }
  else {
    puVar11[1] = 0;
    *(undefined4 *)(puVar11 + 2) = 1;
    *puVar11 = uVar8;
  }
  if (puVar11 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
    uStack_f0 = 0x180031ae6;
    FUN_180034a60(0x8007000e);
  }
  ppvObject = (void **)*puVar11;
  LOCK();
  piVar1 = (int *)(puVar11 + 2);
  iVar16 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar16 == 1) {
    if ((BSTR)*puVar11 != (BSTR)0x0) {
      uStack_f0 = 0x180031703;
      SysFreeString((BSTR)*puVar11);
      *puVar11 = 0;
    }
    if ((void *)puVar11[1] != (void *)0x0) {
      uStack_f0 = 0x180031714;
      operator_delete__((void *)puVar11[1]);
      puVar11[1] = 0;
    }
    uStack_f0 = 0x180031725;
    FUN_180035134(puVar11);
  }
  puVar20 = auStack_e8;
  if (ppvObject != (void **)0x0) {
    lVar12 = -1;
    do {
      lVar14 = lVar12;
      lVar12 = lVar14 + 1;
    } while (*(LPCWSTR)((longlong)ppvObject + lVar12 * 2) != L'\0');
    iVar16 = (int)lVar14 + 2;
    puVar20 = auStack_e8;
    if (iVar16 < 0x40000000) {
      lVar12 = (longlong)(int)lVar12 * 2;
      uVar15 = lVar12 + 0x11;
      if (uVar15 <= lVar12 + 2U) {
        uVar15 = 0xffffffffffffff0;
      }
      uStack_f0 = 0x180031776;
      lVar12 = -(uVar15 & 0xfffffffffffffff0);
      pcVar17 = (char *)((longlong)local_b8 + lVar12 + 0x10);
      puVar20 = auStack_e8 + lVar12;
      if (pcVar17 != (char *)0x0) {
        *pcVar17 = '\0';
        *(undefined8 *)((longlong)local_b8 + lVar12 + 8) = 0;
        *(undefined8 *)((longlong)local_b8 + lVar12) = 0;
        *(int *)((longlong)aiStack_c0 + lVar12) = iVar16 * 2;
        *(char **)(auStack_e8 + lVar12 + 0x20) = pcVar17;
        *(undefined8 *)(auStack_e8 + lVar12 + -8) = 0x1800317af;
        iVar16 = WideCharToMultiByte(0,0,(LPCWSTR)ppvObject,-1,
                                     *(LPSTR *)(auStack_e8 + lVar12 + 0x20),
                                     *(int *)((longlong)aiStack_c0 + lVar12),
                                     *(LPCSTR *)((longlong)local_b8 + lVar12),
                                     *(LPBOOL *)((longlong)local_b8 + lVar12 + 8));
        puVar20 = auStack_e8 + lVar12;
        if (iVar16 == 0) {
          pcVar17 = (char *)0x0;
          puVar20 = auStack_e8 + lVar12;
        }
        goto LAB_1800317c4;
      }
    }
  }
  pcVar17 = (char *)0x0;
  ppvObject = param_3;
LAB_1800317c4:
  *(undefined8 *)(puVar20 + -8) = 0x1800317d1;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_50,pcVar17);
  local_78 = (SAFEARRAY *)0x0;
  p_Var3 = param_1->lpVtbl[10].QueryInterface;
  *(undefined8 *)(puVar20 + -8) = 0x1800317e6;
  HVar10 = (*p_Var3)(param_1,(IID *)&local_78,ppvObject);
  if (HVar10 < 0) {
    *(undefined8 *)(puVar20 + -8) = 0x1800317fb;
    _com_issue_errorex(HVar10,param_1,(_GUID *)&DAT_1800424d8);
  }
  psa = local_78;
  local_60 = local_78;
  LStack_9c = 0;
  *(undefined8 *)(puVar20 + -8) = 0x180031818;
  SafeArrayGetUBound(psa,1,&LStack_9c);
  *(undefined8 *)(puVar20 + -8) = 0x180031821;
  SafeArrayLock(psa);
  local_a8 = 0;
  do {
    if (LStack_9c < local_a8) {
      *(undefined8 *)(puVar20 + -8) = 0x180031a9e;
      SafeArrayUnlock(psa);
      *(undefined8 *)(puVar20 + -8) = 0x180031aa7;
      SafeArrayDestroy(psa);
      *(undefined8 *)(puVar20 + -8) = 0x180031ab2;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_50);
      *(undefined8 *)(puVar20 + -8) = 0x180031abe;
      return;
    }
    local_98 = (IUnknown *)0x0;
    *(undefined8 *)(puVar20 + -8) = 0x180031844;
    SafeArrayGetElement(psa,&local_a8,&local_98);
    pIVar7 = local_98;
    if (local_98 != (IUnknown *)0x0) {
      local_70[0] = '\0';
      local_70[1] = '\0';
      local_70[2] = '\0';
      local_70[3] = '\0';
      local_70[4] = '\0';
      local_70[5] = '\0';
      local_70[6] = '\0';
      local_70[7] = '\0';
      p_Var4 = local_98->lpVtbl[4].AddRef;
      *(undefined8 *)(puVar20 + -8) = 0x180031862;
      UVar9 = (*p_Var4)(pIVar7);
      if ((int)UVar9 < 0) {
        *(undefined8 *)(puVar20 + -8) = 0x180031877;
        _com_issue_errorex(UVar9,pIVar7,(_GUID *)&DAT_1800424c8);
      }
      auVar6 = local_70;
      *(undefined8 *)(puVar20 + -8) = 0x180031885;
      pauVar13 = operator_new(0x18);
      pIVar7 = local_98;
      if (pauVar13 == (uchar (*) [8])0x0) {
        pauVar13 = (uchar (*) [8])0x0;
      }
      else {
        pauVar13[1] = (uchar  [8])0x0;
        *(uchar *)((longlong)(pauVar13 + 2) + 0) = '\x01';
        *(uchar *)((longlong)(pauVar13 + 2) + 1) = '\0';
        *(uchar *)((longlong)(pauVar13 + 2) + 2) = '\0';
        *(uchar *)((longlong)(pauVar13 + 2) + 3) = '\0';
        *pauVar13 = auVar6;
      }
      local_88 = pauVar13;
      local_48 = pauVar13;
      if (pauVar13 == (uchar (*) [8])0x0) {
                    /* WARNING: Subroutine does not return */
        *(undefined **)(puVar20 + -8) = &UNK_180031af1;
        FUN_180034a60(0x8007000e);
      }
      sStack_a4 = 0;
      p_Var5 = local_98->lpVtbl[4].Release;
      *(undefined8 *)(puVar20 + -8) = 0x1800318ca;
      UVar9 = (*p_Var5)(pIVar7);
      if ((int)UVar9 < 0) {
        *(undefined8 *)(puVar20 + -8) = 0x1800318df;
        _com_issue_errorex(UVar9,pIVar7,(_GUID *)&DAT_1800424c8);
      }
      if (sStack_a4 != 0) {
        auVar6 = *pauVar13;
        puVar19 = puVar20;
        if (auVar6 == (uchar  [8])0x0) {
LAB_180031974:
          pcVar17 = (char *)0x0;
          puVar20 = puVar19;
        }
        else {
          lVar12 = -1;
          do {
            lVar14 = lVar12;
            lVar12 = lVar14 + 1;
          } while (*(LPCWSTR)((longlong)auVar6 + lVar12 * 2) != L'\0');
          iVar16 = (int)lVar14 + 2;
          if (0x3fffffff < iVar16) goto LAB_180031974;
          lVar12 = (longlong)(int)lVar12 * 2;
          uVar15 = lVar12 + 0x11;
          if (uVar15 <= lVar12 + 2U) {
            uVar15 = 0xffffffffffffff0;
          }
          *(undefined8 *)(puVar20 + -8) = 0x180031938;
          lVar12 = -(uVar15 & 0xfffffffffffffff0);
          puVar19 = puVar20 + lVar12;
          puVar18 = puVar20 + lVar12;
          pcVar17 = puVar20 + lVar12 + 0x40;
          if (pcVar17 == (char *)0x0) goto LAB_180031974;
          *pcVar17 = '\0';
          *(undefined8 *)(puVar20 + lVar12 + 0x38) = 0;
          *(undefined8 *)(puVar20 + lVar12 + 0x30) = 0;
          *(int *)(puVar20 + lVar12 + 0x28) = iVar16 * 2;
          *(char **)(puVar20 + lVar12 + 0x20) = pcVar17;
          *(undefined8 *)(puVar20 + lVar12 + -8) = 0x18003196c;
          iVar16 = WideCharToMultiByte(0,0,(LPCWSTR)auVar6,-1,*(LPSTR *)(puVar20 + lVar12 + 0x20),
                                       *(int *)(puVar20 + lVar12 + 0x28),
                                       *(LPCSTR *)(puVar20 + lVar12 + 0x30),
                                       *(LPBOOL *)(puVar20 + lVar12 + 0x38));
          puVar20 = puVar20 + lVar12;
          if (iVar16 == 0) {
            pcVar17 = (char *)0x0;
            puVar20 = puVar18;
          }
        }
        *(undefined8 *)(puVar20 + -8) = 0x180031984;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_68,pcVar17);
        *(undefined8 *)(puVar20 + -8) = 0x180031999;
        this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Right
                         (local_68,(int)local_58);
        *(undefined8 *)(puVar20 + -8) = 0x1800319aa;
        iVar16 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                           (this,".ads");
        *(undefined8 *)(puVar20 + -8) = 0x1800319b6;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_58);
        if (iVar16 == 0) {
          LOCK();
          *(int *)pauVar13[2] = *(int *)pauVar13[2] + 1;
          UNLOCK();
          local_40 = &local_90;
          local_a0 = 0;
          p_Var4 = param_1->lpVtbl[9].AddRef;
          local_90 = pauVar13;
          *(undefined8 *)(puVar20 + -8) = 0x1800319ef;
          UVar9 = (*p_Var4)(param_1);
          if ((int)UVar9 < 0) {
            *(undefined8 *)(puVar20 + -8) = 0x180031a04;
            _com_issue_errorex(UVar9,param_1,(_GUID *)&DAT_1800424d8);
          }
          *(undefined8 *)(puVar20 + -8) = 0x180031a0e;
          FUN_18001ccd0(&local_90);
        }
        *(undefined8 *)(puVar20 + -8) = 0x180031a36;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_68);
      }
      LOCK();
      pauVar2 = pauVar13 + 2;
      iVar16 = *(int *)*pauVar2;
      *(int *)*pauVar2 = *(int *)*pauVar2 + -1;
      UNLOCK();
      if (iVar16 == 1) {
        auVar6 = *pauVar13;
        if (auVar6 != (uchar  [8])0x0) {
          *(undefined8 *)(puVar20 + -8) = 0x180031a54;
          SysFreeString((BSTR)auVar6);
          *pauVar13 = (uchar  [8])0x0;
        }
        auVar6 = pauVar13[1];
        if (auVar6 != (uchar  [8])0x0) {
          *(undefined8 *)(puVar20 + -8) = 0x180031a65;
          operator_delete__((void *)auVar6);
          pauVar13[1] = (uchar  [8])0x0;
        }
        *(undefined8 *)(puVar20 + -8) = 0x180031a76;
        FUN_180035134(pauVar13);
      }
    }
    pIVar7 = local_98;
    if (local_98 != (IUnknown *)0x0) {
      p_Var5 = local_98->lpVtbl->Release;
      *(undefined8 *)(puVar20 + -8) = 0x180031a88;
      (*p_Var5)(pIVar7);
    }
    local_a8 = local_a8 + 1;
  } while( true );
}

/* RVA 0x31b00 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180031b00(char *param_1,char *param_2,char *param_3)

{
  int *piVar1;
  void *pvVar2;
  longlong *plVar3;
  IUnknown *pIVar4;
  short sVar5;
  short sVar6;
  BOOL BVar7;
  HRESULT HVar8;
  int iVar9;
  char *pcVar10;
  undefined8 *puVar11;
  BSTR pOVar12;
  undefined8 uVar13;
  void *pvVar14;
  undefined8 **ppuVar15;
  IID *pIVar16;
  IID *pIVar17;
  longlong *plVar18;
  void **ppvVar19;
  undefined8 uVar20;
  undefined1 auStackY_4c8 [32];
  LPCSTR local_498;
  IUnknown *local_490;
  char *local_488;
  undefined8 *local_480;
  char local_478 [8];
  char *local_470;
  undefined8 local_468;
  undefined8 *local_460;
  IID local_458 [17];
  char local_348 [256];
  char local_248 [256];
  void *local_148 [32];
  ulonglong local_48;
  
  local_48 = DAT_180052888 ^ (ulonglong)auStackY_4c8;
  local_490 = (IUnknown *)0x0;
  local_468 = 0;
  local_470 = param_3;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_488);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_498);
  _splitpath(param_1,(char *)0x0,(char *)0x0,local_248,(char *)0x0);
  _splitpath(param_2,local_478,(char *)local_148,(char *)0x0,local_348);
  ppvVar19 = local_148;
  _makepath((char *)local_458,local_478,(char *)ppvVar19,local_248,local_348);
  BVar7 = PathFileExistsA(param_1);
  sVar5 = (short)BVar7;
  if (sVar5 != 0) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_498,param_1);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_498,".backup"
              );
    ppvVar19 = (void **)0x0;
    CopyFileA(param_1,local_498,0);
  }
  pIVar17 = local_458;
  HVar8 = FUN_18002c9d0(&local_490,(LPCSTR)pIVar17);
  if (HVar8 < 0) {
    pcVar10 = (char *)GetSorResStringEx(0x58d);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_488,pcVar10);
    MMAfxMessageBox(local_488,0,-1,0);
  }
  else {
    uVar20 = FUN_1800260d0(param_1);
    pIVar4 = local_490;
    if ((short)uVar20 != 0) {
      puVar11 = operator_new(0x18);
      uVar20 = 1;
      local_480 = puVar11;
      if (puVar11 == (undefined8 *)0x0) {
        puVar11 = (undefined8 *)0x0;
      }
      else {
        puVar11[1] = 0;
        *(undefined4 *)(puVar11 + 2) = 1;
        pOVar12 = FUN_180034c50(param_1);
        *puVar11 = pOVar12;
      }
      local_460 = puVar11;
      if (puVar11 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_180034a60(0x8007000e);
      }
      LOCK();
      *(int *)(puVar11 + 2) = *(int *)(puVar11 + 2) + 1;
      UNLOCK();
      ppvVar19 = (void **)0x3;
      ppuVar15 = &local_480;
      local_480 = puVar11;
      sVar6 = FUN_180030cf0(local_490,ppuVar15);
      if (sVar6 == 0) {
        uVar13 = 0x58e;
LAB_180031e8d:
        pcVar10 = (char *)GetSorResStringEx(uVar13);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_488,
                   pcVar10);
        ppvVar19 = (void **)0xffffffff;
        pIVar17 = (IID *)0x0;
        MMAfxMessageBox(local_488,0,-1,0);
        FUN_180026150(local_490,pIVar17,ppvVar19);
        if ((sVar5 != 0) && (BVar7 = PathFileExistsA(local_498), BVar7 != 0)) {
          DeleteFileA(param_1);
          rename(local_498,param_1);
        }
      }
      else {
        FUN_180031650(local_490,ppuVar15,ppvVar19);
        uVar13 = FUN_18002fa70(local_490,(char *)local_458,param_3);
        plVar3 = DAT_180054098;
        if ((short)uVar13 == 0) {
          uVar13 = 0x587;
          goto LAB_180031e8d;
        }
        plVar18 = DAT_180054090;
        if (DAT_180054090 != DAT_180054098) {
          do {
            if (0xf < (ulonglong)plVar18[3]) {
              pvVar2 = (void *)*plVar18;
              pvVar14 = pvVar2;
              if ((0xfff < plVar18[3] + 1U) &&
                 (pvVar14 = *(void **)((longlong)pvVar2 + -8),
                 0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar14)))) {
                    /* WARNING: Subroutine does not return */
                _invalid_parameter_noinfo_noreturn();
              }
              FUN_180035134(pvVar14);
            }
            plVar18[2] = 0;
            plVar18[3] = 0xf;
            *(undefined1 *)plVar18 = 0;
            plVar18 = plVar18 + 4;
          } while (plVar18 != plVar3);
          DAT_180054098 = DAT_180054090;
        }
        CFutilit(FUN_180026c60,0);
        CfNonRegistrySettings(FUN_180026c60);
        iVar9 = FUN_180033bd0();
        if (iVar9 == 1) {
          FUN_180032010(local_490);
        }
        uVar13 = FUN_1800301e0(local_490);
        if ((short)uVar13 == 0) {
          uVar13 = 0x588;
          goto LAB_180031e8d;
        }
        uVar13 = FUN_18002e010(local_490,(char *)local_458,local_470);
        if ((short)uVar13 == 0) {
          uVar13 = 0x589;
          goto LAB_180031e8d;
        }
        pIVar17 = local_458;
        uVar13 = FUN_18002e6b0(local_490,param_1,(IUnknown *)pIVar17);
        if ((short)uVar13 == 0) {
          uVar13 = 0x58a;
          goto LAB_180031e8d;
        }
        uVar13 = FUN_18002ccc0(local_490,(char *)local_458,(void **)pIVar17);
        if ((short)uVar13 == 0) {
          uVar13 = 0x822;
          goto LAB_180031e8d;
        }
        pIVar16 = local_458;
        uVar13 = FUN_180032d80(local_490,(longlong *)pIVar16,(void **)pIVar17);
        if ((short)uVar13 == 0) {
          uVar13 = 0x830;
          goto LAB_180031e8d;
        }
        FUN_180026150(local_490,pIVar16,(void **)pIVar17);
        if ((sVar5 != 0) && (BVar7 = PathFileExistsA(local_498), BVar7 != 0)) {
          DeleteFileA(local_498);
        }
        uVar20 = 0;
      }
      LOCK();
      piVar1 = (int *)(puVar11 + 2);
      iVar9 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar9 == 1) {
        if ((BSTR)*puVar11 != (BSTR)0x0) {
          SysFreeString((BSTR)*puVar11);
          *puVar11 = 0;
        }
        if ((void *)puVar11[1] != (void *)0x0) {
          operator_delete__((void *)puVar11[1]);
          puVar11[1] = 0;
        }
        FUN_180035134(puVar11);
      }
      goto LAB_180031f5d;
    }
    HVar8 = (*local_490->lpVtbl[6].QueryInterface)(local_490,pIVar17,ppvVar19);
    if (HVar8 < 0) {
      _com_issue_errorex(HVar8,pIVar4,(_GUID *)&DAT_1800424d8);
    }
  }
  if ((sVar5 != 0) && (BVar7 = PathFileExistsA(local_498), BVar7 != 0)) {
    DeleteFileA(param_1);
    rename(local_498,param_1);
  }
  uVar20 = 1;
LAB_180031f5d:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_498);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_488);
  if (local_490 != (IUnknown *)0x0) {
    (*local_490->lpVtbl->Release)(local_490);
  }
  return uVar20;
}

/* RVA 0x31fc0 */
/* Library Function - Multiple Matches With Same Base Name
    public: void __cdecl std::_Parallelism_allocator<unsigned __int64>::deallocate(unsigned __int64
   * __ptr64 const,unsigned __int64) __ptr64
    public: void __cdecl std::allocator<struct CHN * __ptr64>::deallocate(struct CHN * __ptr64 *
   __ptr64 const,unsigned __int64) __ptr64
    public: void __cdecl std::allocator<struct `void __cdecl
   phmap::container_internal::Deallocate<8,class std::allocator<struct std::pair<unsigned long const
   ,struct TPI1::PRECEX * __ptr64> > >(class std::allocator<struct std::pair<unsigned long const
   ,struct TPI1::PRECEX * __ptr64> > * __ptr64,void * __ptr64,unsigned
   __int64)'::`2'::M>::deallocate(struct `void __cdecl phmap::container_internal::Deallocate<8,class
   std::allocator<struct std::pair<unsigned long const ,struct TPI1::PRECEX * __ptr64> > >(class
   std::allocator<struct std::pair<unsigned long const ,struct TPI1::PRECEX * __ptr64> > *
   __ptr64,void * __ptr64,unsigned __int64)'::`2'::M * __ptr64 const,unsigned __int64) __ptr64
    public: void __cdecl std::allocator<struct `void __cdecl
   phmap::container_internal::Deallocate<8,class std::allocator<struct std::pair<unsigned long const
   ,struct TYPTYPE * __ptr64> > >(class std::allocator<struct std::pair<unsigned long const ,struct
   TYPTYPE * __ptr64> > * __ptr64,void * __ptr64,unsigned __int64)'::`2'::M>::deallocate(struct
   `void __cdecl phmap::container_internal::Deallocate<8,class std::allocator<struct
   std::pair<unsigned long const ,struct TYPTYPE * __ptr64> > >(class std::allocator<struct
   std::pair<unsigned long const ,struct TYPTYPE * __ptr64> > * __ptr64,void * __ptr64,unsigned
   __int64)'::`2'::M * __ptr64 const,unsigned __int64) __ptr64
     16 names - too many to list
   
   Library: Visual Studio 2019 Release */

void deallocate(undefined8 param_1,void *param_2,longlong param_3)

{
  void *pvVar1;
  
  pvVar1 = param_2;
  if ((0xfff < (ulonglong)(param_3 * 8)) &&
     (pvVar1 = *(void **)((longlong)param_2 + -8),
     0x1f < (ulonglong)((longlong)param_2 + (-8 - (longlong)pvVar1)))) {
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
  FUN_180035134(pvVar1);
  return;
}

/* RVA 0x32010 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180032010(IUnknown *param_1)

{
  int *piVar1;
  int iVar2;
  ULONG UVar3;
  longlong *plVar4;
  HANDLE hFindFile;
  undefined8 *puVar5;
  BSTR pOVar6;
  undefined8 *puVar7;
  longlong *plVar8;
  int iVar9;
  undefined1 auStack_448 [32];
  longlong **local_428;
  undefined4 local_418;
  int local_414;
  undefined8 *local_410;
  undefined8 *local_408;
  longlong *local_400;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_3f8 [8];
  undefined4 local_3f0;
  undefined4 local_3ec;
  int local_3e8;
  undefined8 **local_3d8;
  longlong *local_3d0;
  IUnknown *local_3c8;
  HANDLE local_3c0;
  IUnknown *local_3b8;
  undefined8 *local_3b0;
  undefined8 **local_3a8;
  _WIN32_FIND_DATAA local_398;
  CHAR local_258 [272];
  char local_148 [272];
  ulonglong local_38;
  
  local_38 = DAT_180052888 ^ (ulonglong)auStack_448;
  local_418 = 0;
  plVar8 = (longlong *)0x0;
  local_400 = (longlong *)0x0;
  local_3ec = 0;
  local_3f0 = 0;
  local_3c8 = param_1;
  local_3b8 = param_1;
  local_3e8 = ApwnLibraryCount();
  iVar9 = 0;
  do {
    local_414 = iVar9;
    if (local_3e8 <= iVar9) {
      if (plVar8 != (longlong *)0x0) {
        (**(code **)(*plVar8 + 0x10))(plVar8);
      }
      return;
    }
    plVar4 = (longlong *)ApwnLibraryGetAt(iVar9);
    if (plVar4 != (longlong *)0x0) {
      (**(code **)(*plVar4 + 0x38))(plVar4,local_148,0x104);
      (**(code **)(*plVar4 + 0x10))(plVar4);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_3f8,local_148);
      iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                        (local_3f8,"Conceptual Design");
      if (iVar2 != 0) {
        local_428 = (longlong **)&local_3f0;
        iVar2 = APModLibGetValues(local_148,local_258,0x104,&local_3ec);
        if (iVar2 != 0) {
          hFindFile = FindFirstFileA(local_258,&local_398);
          local_3c0 = hFindFile;
          if (hFindFile != (HANDLE)0xffffffffffffffff) {
            puVar5 = operator_new(0x18);
            if (puVar5 == (undefined8 *)0x0) {
              puVar5 = (undefined8 *)0x0;
            }
            else {
              puVar5[1] = 0;
              *(undefined4 *)(puVar5 + 2) = 1;
              local_3b0 = puVar5;
              pOVar6 = FUN_180034c50(local_258);
              *puVar5 = pOVar6;
            }
            local_3b0 = puVar5;
            if (puVar5 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
              FUN_180034a60(0x8007000e);
            }
            puVar7 = operator_new(0x18);
            local_3d8 = (undefined8 **)puVar7;
            if (puVar7 == (undefined8 *)0x0) {
              local_408 = (undefined8 *)0x0;
            }
            else {
              puVar7[1] = 0;
              *(undefined4 *)(puVar7 + 2) = 1;
              pOVar6 = FUN_180034c50("");
              *puVar7 = pOVar6;
              local_408 = puVar7;
            }
            if (local_408 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
              FUN_180034a60(0x8007000e);
            }
            local_3d8 = &local_408;
            LOCK();
            *(int *)(puVar5 + 2) = *(int *)(puVar5 + 2) + 1;
            UNLOCK();
            local_3a8 = &local_410;
            local_3d0 = (longlong *)0x0;
            local_428 = &local_3d0;
            local_410 = puVar5;
            UVar3 = (*param_1->lpVtbl[7].AddRef)(param_1);
            if ((int)UVar3 < 0) {
              _com_issue_errorex(UVar3,param_1,(_GUID *)&DAT_1800424d8);
            }
            plVar4 = local_3d0;
            local_418 = 1;
            FUN_18001ccd0(&local_410);
            FUN_18001ccd0(&local_408);
            plVar8 = local_400;
            if (local_400 != plVar4) {
              if (plVar4 != (longlong *)0x0) {
                (**(code **)(*plVar4 + 8))(plVar4);
              }
              local_400 = plVar4;
              if (plVar8 != (longlong *)0x0) {
                (**(code **)(*plVar8 + 0x10))(plVar8);
              }
            }
            if (plVar4 != (longlong *)0x0) {
              (**(code **)(*plVar4 + 0x10))(plVar4);
            }
            plVar8 = local_400;
            LOCK();
            piVar1 = (int *)(puVar5 + 2);
            iVar2 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (local_400 == (longlong *)0x0) {
              if (iVar2 == 1) {
                if ((BSTR)*puVar5 != (BSTR)0x0) {
                  SysFreeString((BSTR)*puVar5);
                  *puVar5 = 0;
                }
                if ((void *)puVar5[1] != (void *)0x0) {
                  operator_delete__((void *)puVar5[1]);
                  puVar5[1] = 0;
                }
                FUN_180035134(puVar5);
              }
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_3f8);
              goto LAB_18003237b;
            }
            if (iVar2 == 1) {
              if ((BSTR)*puVar5 != (BSTR)0x0) {
                SysFreeString((BSTR)*puVar5);
                *puVar5 = 0;
              }
              if ((void *)puVar5[1] != (void *)0x0) {
                operator_delete__((void *)puVar5[1]);
                puVar5[1] = 0;
              }
              FUN_180035134(puVar5);
            }
          }
          FindClose(hFindFile);
        }
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_3f8);
    }
LAB_18003237b:
    iVar9 = iVar9 + 1;
    param_1 = local_3c8;
  } while( true );
}

/* RVA 0x323f0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1800323f0(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1)

{
  int iVar1;
  undefined1 auStack_68 [32];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_48;
  undefined1 local_40 [20];
  int local_2c;
  ulonglong local_10;
  
  local_10 = DAT_180052888 ^ (ulonglong)auStack_68;
  local_48 = param_1;
  iVar1 = _stat64i32(*(undefined8 *)param_1,local_40);
  if ((iVar1 == 0) && (local_2c != 0)) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1);
    return 0;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1);
  return 1;
}

/* RVA 0x32470 */
void FUN_180032470(longlong *param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  
  plVar1 = (longlong *)param_1[1];
  if (plVar1 == (longlong *)param_1[2]) {
    FUN_1800077a0(param_1,plVar1,param_2);
    return;
  }
  *plVar1 = 0;
  plVar1[1] = 0;
  plVar1[2] = 0;
  plVar1[3] = 0;
  lVar2 = param_2[1];
  *plVar1 = *param_2;
  plVar1[1] = lVar2;
  lVar2 = param_2[3];
  plVar1[2] = param_2[2];
  plVar1[3] = lVar2;
  param_2[2] = 0;
  param_2[3] = 0xf;
  *(undefined1 *)param_2 = 0;
  param_1[1] = param_1[1] + 0x20;
  return;
}

/* RVA 0x324c0 */
void FUN_1800324c0(undefined8 *param_1)

{
  if ((BSTR)*param_1 != (BSTR)0x0) {
    SysFreeString((BSTR)*param_1);
    *param_1 = 0;
  }
  if ((void *)param_1[1] != (void *)0x0) {
    operator_delete__((void *)param_1[1]);
    param_1[1] = 0;
  }
  return;
}

/* RVA 0x32500 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined8 FUN_180032500(undefined8 param_1,char *param_2)

{
  longlong *plVar1;
  LPCWSTR lpWideCharStr;
  IUnknownVtbl *pIVar2;
  _func_5158 *p_Var3;
  void *pvVar4;
  IUnknown *pIVar5;
  LPCSTR *ppCVar6;
  LPCSTR lpNewFileName;
  OLECHAR *psz;
  HRESULT HVar7;
  ULONG UVar8;
  int iVar9;
  BOOL BVar10;
  HANDLE hFindFile;
  longlong *plVar11;
  longlong lVar13;
  longlong lVar12;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar14;
  BSTR pOVar15;
  LPCSTR pCVar16;
  BSTR pOVar17;
  ulonglong uVar18;
  int iVar19;
  char *pcVar20;
  undefined1 *puVar21;
  undefined8 uVar22;
  undefined *puVar23;
  undefined8 uVar24;
  undefined *puStackY_780;
  undefined1 auStackY_778 [32];
  int aiStack_750 [2];
  undefined8 local_748 [2];
  char local_738 [4];
  int iStack_734;
  LPCSTR local_730;
  LPCSTR *local_728;
  longlong local_720;
  LPCSTR local_718;
  LPCSTR local_710;
  longlong *local_708;
  BSTR local_700;
  LPCSTR local_6f8;
  LPCSTR local_6f0;
  BSTR local_6e8;
  undefined8 local_6e0;
  LPCSTR local_6d8;
  LPCSTR local_6d0;
  longlong *local_6c8;
  longlong local_6c0;
  OLECHAR *local_6b8;
  LPCSTR *local_6b0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_6a8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_6a0 [8];
  longlong *local_698;
  undefined8 local_690;
  undefined8 local_688;
  undefined8 local_680;
  longlong local_678 [24];
  _WIN32_FIND_DATAA local_5b8;
  _WIN32_FIND_DATAA local_478;
  char local_338 [256];
  char local_238 [256];
  char local_138 [256];
  ulonglong local_38;
  
  local_38 = DAT_180052888 ^ (ulonglong)local_738;
  puStackY_780 = (undefined *)0x180032568;
  _splitpath(param_2,local_738,local_338,local_138,local_238);
  puStackY_780 = (undefined *)0x180032572;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6d0);
  puStackY_780 = (undefined *)0x18003258f;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6d0,
             "%s%sHybridModels\\*.athm",local_738,local_338);
  puStackY_780 = (undefined *)0x1800325a0;
  hFindFile = FindFirstFileA(local_6d0,&local_5b8);
  puStackY_780 = (undefined *)0x1800325ad;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6d8);
  puStackY_780 = (undefined *)0x1800325ca;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6d8,
             "%s%sHybridModels\\*.xlp",local_738,local_338);
  puStackY_780 = (undefined *)0x1800325db;
  local_700 = FindFirstFileA(local_6d8,&local_478);
  puVar21 = auStackY_778;
  if ((hFindFile == (HANDLE)0xffffffffffffffff) && (local_700 == (BSTR)0xffffffffffffffff)) {
    uVar24 = 1;
    goto LAB_180032cbf;
  }
  if (DAT_1800540c8 == (IUnknown *)0x0) {
    puVar23 = &DAT_180042880;
    uVar22 = 1;
    uVar24 = 0;
    puStackY_780 = (undefined *)0x18003262a;
    HVar7 = CoCreateInstance((IID *)&DAT_180042890,(LPUNKNOWN)0x0,1,(IID *)&DAT_180042880,
                             &DAT_1800540c8);
    if (HVar7 < 0) {
      DAT_1800540c8 = (IUnknown *)0x0;
    }
    if (HVar7 != 0) {
      if (DAT_1800540c8 != (IUnknown *)0x0) {
        puStackY_780 = (undefined *)0x180032653;
        (*DAT_1800540c8->lpVtbl->Release)(DAT_1800540c8);
      }
      DAT_1800540c8 = (IUnknown *)0x0;
      puStackY_780 = (undefined *)0x180032667;
      FUN_18001f260("!!!Compound File - Failed to get IModelLibraryManagerPtr\n",uVar24,uVar22,
                    puVar23);
      puVar21 = auStackY_778;
      uVar24 = 0x80004005;
      goto LAB_180032cbf;
    }
    if (DAT_1800540c8 == (IUnknown *)0x0) {
                    /* WARNING: Subroutine does not return */
      puStackY_780 = &UNK_180032d48;
      FUN_180034a60(0x80004003);
    }
  }
  pIVar5 = DAT_1800540c8;
  local_6c0 = 0;
  puStackY_780 = (undefined *)0x18003268c;
  UVar8 = (*DAT_1800540c8->lpVtbl[3].Release)(DAT_1800540c8);
  if ((int)UVar8 < 0) {
    puStackY_780 = (undefined *)0x1800326a1;
    _com_issue_errorex(UVar8,pIVar5,(_GUID *)&DAT_180042880);
  }
  lVar12 = local_6c0;
  puStackY_780 = (undefined *)0x1800326af;
  plVar11 = operator_new(0x18);
  local_6c8 = plVar11;
  if (plVar11 == (longlong *)0x0) {
    plVar11 = (longlong *)0x0;
  }
  else {
    plVar11[1] = 0;
    *(undefined4 *)(plVar11 + 2) = 1;
    *plVar11 = lVar12;
  }
  local_698 = plVar11;
  if (plVar11 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
    puStackY_780 = (undefined *)0x180032d53;
    FUN_180034a60(0x8007000e);
  }
  lpWideCharStr = (LPCWSTR)*plVar11;
  puVar21 = auStackY_778;
  if (lpWideCharStr == (LPCWSTR)0x0) {
LAB_18003276b:
    pcVar20 = (char *)0x0;
  }
  else {
    lVar12 = -1;
    do {
      lVar13 = lVar12;
      lVar12 = lVar13 + 1;
    } while (lpWideCharStr[lVar12] != L'\0');
    iVar19 = (int)lVar13 + 2;
    puVar21 = auStackY_778;
    if (0x3fffffff < iVar19) goto LAB_18003276b;
    lVar12 = (longlong)(int)lVar12 * 2;
    uVar18 = lVar12 + 0x11;
    if (uVar18 <= lVar12 + 2U) {
      uVar18 = 0xffffffffffffff0;
    }
    puStackY_780 = (undefined *)0x180032730;
    lVar12 = -(uVar18 & 0xfffffffffffffff0);
    puVar21 = auStackY_778 + lVar12;
    pcVar20 = local_738 + lVar12;
    if (pcVar20 == (char *)0x0) goto LAB_18003276b;
    *pcVar20 = '\0';
    *(undefined8 *)((longlong)local_748 + lVar12 + 8) = 0;
    *(undefined8 *)((longlong)local_748 + lVar12) = 0;
    *(int *)((longlong)aiStack_750 + lVar12) = iVar19 * 2;
    *(char **)(auStackY_778 + lVar12 + 0x20) = pcVar20;
    *(undefined8 *)(auStackY_778 + lVar12 + -8) = 0x180032763;
    iVar19 = WideCharToMultiByte(0,0,lpWideCharStr,-1,*(LPSTR *)(auStackY_778 + lVar12 + 0x20),
                                 *(int *)((longlong)aiStack_750 + lVar12),
                                 *(LPCSTR *)((longlong)local_748 + lVar12),
                                 *(LPBOOL *)((longlong)local_748 + lVar12 + 8));
    puVar21 = auStackY_778 + lVar12;
    if (iVar19 == 0) {
      pcVar20 = (char *)0x0;
      puVar21 = auStackY_778 + lVar12;
    }
  }
  *(undefined8 *)(puVar21 + -8) = 0x18003277b;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e0,pcVar20);
  if (hFindFile != (HANDLE)0xffffffffffffffff) {
    *(undefined8 *)(puVar21 + -8) = 0x180032793;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_6a0);
    local_678[6] = 0;
    local_678[7] = 0;
    local_678[8] = 0;
    local_678[3] = 0;
    local_678[4] = 0;
    local_678[5] = 0;
    local_678[0] = 0;
    local_678[1] = 0;
    local_678[2] = 0;
    local_678[9] = 0;
    local_678[10] = 0;
    local_678[0xb] = 0;
    do {
      *(undefined8 *)(puVar21 + -8) = 0x1800327dd;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_718);
      *(CHAR **)(puVar21 + 0x20) = local_5b8.cFileName;
      *(undefined8 *)(puVar21 + -8) = 0x180032806;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_718,
                 "%s%sHybridModels\\%s",local_738,local_338);
      *(undefined8 *)(puVar21 + -8) = 0x180032817;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_730,
                 local_5b8.cFileName);
      *(undefined8 *)(puVar21 + -8) = 0x180032824;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_730,'.');
      *(undefined8 *)(puVar21 + -8) = 0x180032838;
      pCVar14 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_730,(int)local_6a8);
      *(undefined8 *)(puVar21 + -8) = 0x180032846;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_730,pCVar14
                );
      *(undefined8 *)(puVar21 + -8) = 0x180032854;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_6a8);
      pCVar16 = local_730;
      if (local_730 == (LPCSTR)0x0) {
        local_6b8 = (OLECHAR *)0x0;
      }
      else {
        *(undefined4 *)(puVar21 + 0x28) = 0;
        *(undefined8 *)(puVar21 + 0x20) = 0;
        *(undefined8 *)(puVar21 + -8) = 0x180032876;
        iVar19 = MultiByteToWideChar(0,0,pCVar16,-1,*(LPWSTR *)(puVar21 + 0x20),
                                     *(int *)(puVar21 + 0x28));
        *(undefined8 *)(puVar21 + -8) = 0x180032883;
        pOVar15 = SysAllocStringLen((OLECHAR *)0x0,iVar19 - 1);
        if (pOVar15 != (BSTR)0x0) {
          *(int *)(puVar21 + 0x28) = iVar19;
          *(BSTR *)(puVar21 + 0x20) = pOVar15;
          *(undefined8 *)(puVar21 + -8) = 0x1800328a4;
          iVar9 = MultiByteToWideChar(0,0,pCVar16,-1,*(LPWSTR *)(puVar21 + 0x20),
                                      *(int *)(puVar21 + 0x28));
          if (iVar9 != iVar19) {
            *(undefined8 *)(puVar21 + -8) = 0x180032d5d;
            SysFreeString(pOVar15);
            local_6b8 = (BSTR)0x0;
            goto LAB_180032d68;
          }
        }
        local_6b8 = pOVar15;
        if (pOVar15 == (BSTR)0x0) {
LAB_180032d68:
                    /* WARNING: Subroutine does not return */
          *(undefined8 *)(puVar21 + -8) = 0x180032d72;
          FUN_1800018d0(-0x7ff8fff2);
        }
      }
      psz = local_6b8;
      local_6e8 = (BSTR)0x0;
      local_690 = 0;
      local_6c8 = &local_720;
      local_6b0 = &local_6f8;
      local_720 = 0;
      local_708 = &local_720;
      *(undefined8 *)(puVar21 + -8) = 0x1800328fe;
      pCVar16 = operator_new(0x18);
      local_710 = pCVar16;
      if (pCVar16 == (LPCSTR)0x0) {
        pCVar16 = (LPCSTR)0x0;
      }
      else {
        pCVar16[8] = '\0';
        pCVar16[9] = '\0';
        pCVar16[10] = '\0';
        pCVar16[0xb] = '\0';
        pCVar16[0xc] = '\0';
        pCVar16[0xd] = '\0';
        pCVar16[0xe] = '\0';
        pCVar16[0xf] = '\0';
        pCVar16[0x10] = '\x01';
        pCVar16[0x11] = '\0';
        pCVar16[0x12] = '\0';
        pCVar16[0x13] = '\0';
        *(undefined8 *)(puVar21 + -8) = 0x18003291f;
        pOVar15 = SysAllocString(psz);
        *(BSTR *)pCVar16 = pOVar15;
        if ((pOVar15 == (BSTR)0x0) && (psz != (OLECHAR *)0x0)) {
                    /* WARNING: Subroutine does not return */
          *(undefined8 *)(puVar21 + -8) = 0x180032d21;
          FUN_180034a60(0x8007000e);
        }
      }
      pIVar5 = DAT_1800540c8;
      local_6f8 = pCVar16;
      if (pCVar16 == (LPCSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        *(undefined8 *)(puVar21 + -8) = 0x180032d16;
        FUN_180034a60(0x8007000e);
      }
      local_728 = &local_6f8;
      if (DAT_1800540c8 == (IUnknown *)0x0) {
                    /* WARNING: Subroutine does not return */
        *(undefined **)(puVar21 + -8) = &UNK_180032d7d;
        FUN_180034a60(0x80004003);
      }
      iStack_734 = 0;
      pIVar2 = DAT_1800540c8->lpVtbl;
      *(int **)(puVar21 + 0x20) = &iStack_734;
      p_Var3 = pIVar2[0xc].Release;
      *(undefined8 *)(puVar21 + -8) = 0x18003298d;
      UVar8 = (*p_Var3)(DAT_1800540c8);
      if ((int)UVar8 < 0) {
        *(undefined8 *)(puVar21 + -8) = 0x1800329a2;
        _com_issue_errorex(UVar8,pIVar5,(_GUID *)&DAT_180042880);
      }
      iVar19 = iStack_734;
      *(undefined8 *)(puVar21 + -8) = 0x1800329ae;
      FUN_18001ccd0(&local_6f8);
      *(undefined8 *)(puVar21 + -8) = 0x1800329b8;
      FUN_18001ccd0(&local_720);
      if (iVar19 < 0) {
        *(undefined8 *)(puVar21 + -8) = 0x1800329c6;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6f0);
        uVar24 = local_6e0;
        pCVar16 = local_730;
        *(undefined8 *)(puVar21 + -8) = 0x1800329e0;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6f0,
                   "%s\\%s.athm",uVar24,pCVar16);
        lpNewFileName = local_6f0;
        pCVar16 = local_718;
        *(undefined8 *)(puVar21 + -8) = 0x1800329f1;
        CopyFileA(pCVar16,lpNewFileName,1);
        *(undefined8 *)(puVar21 + -8) = 0x1800329fc;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6f0);
      }
      pOVar15 = local_6e8;
      *(undefined8 *)(puVar21 + -8) = 0x180032a07;
      SysFreeString(pOVar15);
      *(undefined8 *)(puVar21 + -8) = 0x180032a11;
      SysFreeString(psz);
      *(undefined8 *)(puVar21 + -8) = 0x180032a1c;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_730);
      *(undefined8 *)(puVar21 + -8) = 0x180032a27;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_718);
      *(undefined8 *)(puVar21 + -8) = 0x180032a37;
      BVar10 = FindNextFileA(hFindFile,&local_5b8);
    } while (BVar10 != 0);
    *(undefined8 *)(puVar21 + -8) = 0x180032a4b;
    FindClose(hFindFile);
    *(undefined8 *)(puVar21 + -8) = 0x180032a58;
    FUN_1800259b0(local_678);
    *(undefined8 *)(puVar21 + -8) = 0x180032a65;
    FUN_1800259b0(local_678 + 3);
    *(undefined8 *)(puVar21 + -8) = 0x180032a72;
    FUN_1800259b0(local_678 + 6);
    *(undefined8 *)(puVar21 + -8) = 0x180032a80;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_6a0);
  }
  pOVar15 = local_700;
  if (local_700 != (BSTR)0xffffffffffffffff) {
    *(undefined8 *)(puVar21 + -8) = 0x180032a9a;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6c8);
    local_678[0xc] = 0;
    local_678[0xd] = 0;
    local_678[0xe] = 0;
    local_678[0xf] = 0;
    local_678[0x10] = 0;
    local_678[0x11] = 0;
    local_678[0x12] = 0;
    local_678[0x13] = 0;
    local_678[0x14] = 0;
    local_678[0x15] = 0;
    local_678[0x16] = 0;
    local_678[0x17] = 0;
    do {
      *(undefined8 *)(puVar21 + -8) = 0x180032aea;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_708);
      *(CHAR **)(puVar21 + 0x20) = local_478.cFileName;
      *(undefined8 *)(puVar21 + -8) = 0x180032b13;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_708,
                 "%s%sHybridModels\\%s",local_738,local_338);
      *(undefined8 *)(puVar21 + -8) = 0x180032b24;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_728,
                 local_478.cFileName);
      *(undefined8 *)(puVar21 + -8) = 0x180032b31;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_728,'.');
      *(undefined8 *)(puVar21 + -8) = 0x180032b45;
      pCVar14 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_728,(int)&local_6b0);
      *(undefined8 *)(puVar21 + -8) = 0x180032b53;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_728,pCVar14
                );
      *(undefined8 *)(puVar21 + -8) = 0x180032b61;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6b0);
      ppCVar6 = local_728;
      if (local_728 == (LPCSTR *)0x0) {
        local_700 = (BSTR)0x0;
      }
      else {
        *(undefined4 *)(puVar21 + 0x28) = 0;
        *(undefined8 *)(puVar21 + 0x20) = 0;
        *(undefined8 *)(puVar21 + -8) = 0x180032b83;
        iVar19 = MultiByteToWideChar(0,0,(LPCSTR)ppCVar6,-1,*(LPWSTR *)(puVar21 + 0x20),
                                     *(int *)(puVar21 + 0x28));
        *(undefined8 *)(puVar21 + -8) = 0x180032b90;
        pOVar17 = SysAllocStringLen((OLECHAR *)0x0,iVar19 - 1);
        if (pOVar17 != (BSTR)0x0) {
          *(int *)(puVar21 + 0x28) = iVar19;
          *(BSTR *)(puVar21 + 0x20) = pOVar17;
          *(undefined8 *)(puVar21 + -8) = 0x180032bb1;
          iVar9 = MultiByteToWideChar(0,0,(LPCSTR)ppCVar6,-1,*(LPWSTR *)(puVar21 + 0x20),
                                      *(int *)(puVar21 + 0x28));
          if (iVar9 != iVar19) {
            *(undefined8 *)(puVar21 + -8) = 0x180032d2b;
            SysFreeString(pOVar17);
            local_700 = (BSTR)0x0;
            goto LAB_180032d33;
          }
        }
        local_700 = pOVar17;
        if (pOVar17 == (BSTR)0x0) {
LAB_180032d33:
                    /* WARNING: Subroutine does not return */
          *(undefined8 *)(puVar21 + -8) = 0x180032d3d;
          FUN_1800018d0(-0x7ff8fff2);
        }
      }
      pOVar17 = local_700;
      local_688 = 0;
      local_680 = 0;
      *(undefined8 *)(puVar21 + -8) = 0x180032be9;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_710);
      uVar24 = local_6e0;
      ppCVar6 = local_728;
      *(undefined8 *)(puVar21 + -8) = 0x180032c03;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_710,
                 "%s\\%s.xlp",uVar24,ppCVar6);
      plVar1 = local_708;
      pCVar16 = local_710;
      *(undefined8 *)(puVar21 + -8) = 0x180032c14;
      CopyFileA((LPCSTR)plVar1,pCVar16,1);
      *(undefined8 *)(puVar21 + -8) = 0x180032c1f;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_710);
      *(undefined8 *)(puVar21 + -8) = 0x180032c28;
      SysFreeString((BSTR)0x0);
      *(undefined8 *)(puVar21 + -8) = 0x180032c32;
      SysFreeString(pOVar17);
      *(undefined8 *)(puVar21 + -8) = 0x180032c3d;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_728);
      *(undefined8 *)(puVar21 + -8) = 0x180032c48;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_708);
      *(undefined8 *)(puVar21 + -8) = 0x180032c58;
      BVar10 = FindNextFileA(pOVar15,&local_478);
    } while (BVar10 != 0);
    *(undefined8 *)(puVar21 + -8) = 0x180032c69;
    FindClose(pOVar15);
    *(undefined8 *)(puVar21 + -8) = 0x180032c74;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6c8);
  }
  uVar24 = 0;
  *(undefined8 *)(puVar21 + -8) = 0x180032c81;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e0);
  LOCK();
  plVar1 = plVar11 + 2;
  lVar12 = *plVar1;
  *(int *)plVar1 = (int)*plVar1 + -1;
  UNLOCK();
  if ((int)lVar12 == 1) {
    pOVar15 = (BSTR)*plVar11;
    if (pOVar15 != (BSTR)0x0) {
      *(undefined8 *)(puVar21 + -8) = 0x180032c9c;
      SysFreeString(pOVar15);
      *plVar11 = 0;
    }
    pvVar4 = (void *)plVar11[1];
    if (pvVar4 != (void *)0x0) {
      *(undefined8 *)(puVar21 + -8) = 0x180032cad;
      operator_delete__(pvVar4);
      plVar11[1] = 0;
    }
    *(undefined8 *)(puVar21 + -8) = 0x180032cbe;
    FUN_180035134(plVar11);
  }
LAB_180032cbf:
  *(undefined8 *)(puVar21 + -8) = 0x180032cc9;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6d8);
  *(undefined8 *)(puVar21 + -8) = 0x180032cd4;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6d0);
  *(undefined8 *)(puVar21 + -8) = 0x180032ce6;
  return uVar24;
}

/* RVA 0x32d80 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180032d80(IUnknown *param_1,longlong *param_2,void **param_3)

{
  undefined8 *******pppppppuVar1;
  int *piVar2;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar3;
  _func_5157 *p_Var4;
  _func_5158 *p_Var5;
  LPCWSTR lpWideCharStr;
  IUnknownVtbl *pIVar6;
  _func_5156 *p_Var7;
  code *pcVar8;
  BSTR bstrString;
  void *pvVar9;
  longlong *plVar10;
  bool bVar11;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar12;
  IUnknown *pIVar13;
  char *pcVar14;
  LPCSTR pCVar15;
  undefined8 *puVar16;
  SAFEARRAY *psa;
  HRESULT HVar17;
  ULONG UVar18;
  int iVar19;
  longlong lVar21;
  longlong lVar20;
  undefined8 uVar22;
  undefined8 *puVar23;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar24;
  undefined8 ******ppppppuVar25;
  undefined8 *****pppppuVar26;
  undefined8 ******ppppppuVar27;
  undefined8 ******ppppppuVar28;
  ulonglong uVar29;
  int iVar30;
  IID *riid;
  undefined8 *******pppppppuVar31;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar32;
  undefined1 *puVar33;
  undefined1 *puVar34;
  undefined1 *puVar35;
  undefined1 *puVar36;
  char *pcVar37;
  undefined8 uVar38;
  undefined *puVar39;
  undefined1 auStack_508 [64];
  undefined8 *******local_4c8;
  short local_4c0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_4b8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCStack_4b0;
  longlong local_4a8;
  LONG local_4a0 [2];
  char *local_498;
  undefined2 local_490;
  LONG local_48c;
  char *local_488;
  undefined8 local_480;
  IUnknown *local_478;
  IUnknown *local_470;
  LPCSTR local_468;
  undefined8 *******local_460;
  undefined8 *local_458;
  longlong *local_450;
  undefined8 ******local_448;
  undefined8 ******local_440;
  undefined8 ******local_438;
  undefined8 local_430;
  undefined8 ******local_428;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_420 [8];
  undefined8 local_418;
  longlong *local_410;
  SAFEARRAY *local_408;
  char local_400 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_3f8 [8];
  undefined8 *******local_3f0;
  undefined8 ******local_3e8;
  undefined8 ******local_3e0;
  undefined8 ******local_3d8;
  undefined8 ******local_3d0;
  undefined8 local_3c8 [3];
  CFileFind local_3b0 [56];
  undefined1 local_378 [20];
  int local_364;
  undefined1 local_348 [256];
  char local_248 [256];
  char local_148 [256];
  ulonglong local_48;
  
  local_48 = DAT_180052888 ^ (ulonglong)&local_4c8;
  local_4a0[0] = 0;
  local_478 = param_1;
  local_450 = param_2;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_488,
             "HybridModels\\");
  local_408 = (SAFEARRAY *)0x0;
  HVar17 = (*param_1->lpVtbl[10].QueryInterface)(param_1,(IID *)&local_408,param_3);
  if (HVar17 < 0) {
    _com_issue_errorex(HVar17,param_1,(_GUID *)&DAT_1800424d8);
  }
  psa = local_408;
  local_4a0[0] = 0;
  SafeArrayGetUBound(local_408,1,local_4a0);
  SafeArrayLock(psa);
  puVar35 = auStack_508;
  local_48c = 0;
  puVar34 = auStack_508;
  if (-1 < local_4a0[0]) {
    do {
      puVar35 = puVar34;
      local_470 = (IUnknown *)0x0;
      *(undefined8 *)(puVar35 + -8) = 0x180032e65;
      SafeArrayGetElement(psa,&local_48c,&local_470);
      pIVar13 = local_470;
      if (local_470 != (IUnknown *)0x0) {
        local_428 = (undefined8 ******)0x0;
        p_Var4 = local_470->lpVtbl[4].AddRef;
        *(undefined8 *)(puVar35 + -8) = 0x180032e89;
        UVar18 = (*p_Var4)(pIVar13);
        if ((int)UVar18 < 0) {
          *(undefined8 *)(puVar35 + -8) = 0x180032e9e;
          _com_issue_errorex(UVar18,pIVar13,(_GUID *)&DAT_1800424c8);
        }
        ppppppuVar25 = local_428;
        *(undefined8 *)(puVar35 + -8) = 0x180032eaf;
        local_4c8 = operator_new(0x18);
        pIVar13 = local_470;
        if (local_4c8 == (undefined8 *******)0x0) {
          pppppppuVar31 = (undefined8 *******)0x0;
        }
        else {
          local_4c8[1] = (undefined8 ******)0x0;
          *(undefined4 *)(local_4c8 + 2) = 1;
          *local_4c8 = ppppppuVar25;
          pppppppuVar31 = local_4c8;
        }
        local_3f0 = pppppppuVar31;
        if (pppppppuVar31 == (undefined8 *******)0x0) {
                    /* WARNING: Subroutine does not return */
          *(undefined8 *)(puVar35 + -8) = 0x180033903;
          FUN_180034a60(0x8007000e);
        }
        local_4c0 = 0;
        p_Var5 = local_470->lpVtbl[4].Release;
        *(undefined8 *)(puVar35 + -8) = 0x180032ef7;
        UVar18 = (*p_Var5)(pIVar13);
        if ((int)UVar18 < 0) {
          *(undefined8 *)(puVar35 + -8) = 0x180032f0c;
          _com_issue_errorex(UVar18,pIVar13,(_GUID *)&DAT_1800424c8);
        }
        if (local_4c0 != 0) {
          ppppppuVar25 = *pppppppuVar31;
          puVar34 = puVar35;
          if (ppppppuVar25 == (undefined8 ******)0x0) {
LAB_180032fa3:
            pcVar37 = (char *)0x0;
            puVar35 = puVar34;
          }
          else {
            lVar20 = -1;
            do {
              lVar21 = lVar20;
              lVar20 = lVar21 + 1;
            } while (*(LPCWSTR)((longlong)ppppppuVar25 + lVar20 * 2) != L'\0');
            iVar30 = (int)lVar21 + 2;
            if (0x3fffffff < iVar30) goto LAB_180032fa3;
            lVar20 = (longlong)(int)lVar20 * 2;
            uVar29 = lVar20 + 0x11;
            if (uVar29 <= lVar20 + 2U) {
              uVar29 = 0xffffffffffffff0;
            }
            *(undefined8 *)(puVar35 + -8) = 0x180032f68;
            lVar20 = -(uVar29 & 0xfffffffffffffff0);
            puVar34 = puVar35 + lVar20;
            puVar33 = puVar35 + lVar20;
            pcVar37 = puVar35 + lVar20 + 0x40;
            if (pcVar37 == (char *)0x0) goto LAB_180032fa3;
            *pcVar37 = '\0';
            *(undefined8 *)(puVar35 + lVar20 + 0x38) = 0;
            *(undefined8 *)(puVar35 + lVar20 + 0x30) = 0;
            *(int *)(puVar35 + lVar20 + 0x28) = iVar30 * 2;
            *(char **)(puVar35 + lVar20 + 0x20) = pcVar37;
            *(undefined8 *)(puVar35 + lVar20 + -8) = 0x180032f9b;
            iVar30 = WideCharToMultiByte(0,0,(LPCWSTR)ppppppuVar25,-1,
                                         *(LPSTR *)(puVar35 + lVar20 + 0x20),
                                         *(int *)(puVar35 + lVar20 + 0x28),
                                         *(LPCSTR *)(puVar35 + lVar20 + 0x30),
                                         *(LPBOOL *)(puVar35 + lVar20 + 0x38));
            puVar35 = puVar35 + lVar20;
            if (iVar30 == 0) {
              pcVar37 = (char *)0x0;
              puVar35 = puVar33;
            }
          }
          *(undefined8 *)(puVar35 + -8) = 0x180032fb6;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_420,pcVar37);
          pcVar37 = local_488;
          *(undefined8 *)(puVar35 + -8) = 0x180032fcb;
          iVar30 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                             (local_420,pcVar37,0);
          pIVar13 = local_478;
          if (-1 < iVar30) {
            LOCK();
            *(int *)(pppppppuVar31 + 2) = *(int *)(pppppppuVar31 + 2) + 1;
            UNLOCK();
            local_4c8 = &local_460;
            local_490 = 0;
            p_Var4 = local_478->lpVtbl[9].AddRef;
            local_460 = pppppppuVar31;
            *(undefined8 *)(puVar35 + -8) = 0x180033008;
            UVar18 = (*p_Var4)(pIVar13);
            if ((int)UVar18 < 0) {
              *(undefined8 *)(puVar35 + -8) = 0x18003301d;
              _com_issue_errorex(UVar18,pIVar13,(_GUID *)&DAT_1800424d8);
            }
            *(undefined8 *)(puVar35 + -8) = 0x180033027;
            FUN_18001ccd0(&local_460);
          }
          *(undefined8 *)(puVar35 + -8) = 0x180033035;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_420);
        }
        LOCK();
        pppppppuVar1 = pppppppuVar31 + 2;
        iVar30 = *(int *)pppppppuVar1;
        *(int *)pppppppuVar1 = *(int *)pppppppuVar1 + -1;
        UNLOCK();
        if (iVar30 == 1) {
          ppppppuVar25 = *pppppppuVar31;
          if (ppppppuVar25 != (undefined8 ******)0x0) {
            *(undefined8 *)(puVar35 + -8) = 0x180033051;
            SysFreeString((BSTR)ppppppuVar25);
            *pppppppuVar31 = (undefined8 ******)0x0;
          }
          ppppppuVar25 = pppppppuVar31[1];
          if (ppppppuVar25 != (undefined8 ******)0x0) {
            *(undefined8 *)(puVar35 + -8) = 0x180033062;
            operator_delete__(ppppppuVar25);
            pppppppuVar31[1] = (undefined8 ******)0x0;
          }
          *(undefined8 *)(puVar35 + -8) = 0x180033073;
          FUN_180035134(pppppppuVar31);
        }
      }
      pIVar13 = local_470;
      if (local_470 != (IUnknown *)0x0) {
        p_Var5 = local_470->lpVtbl->Release;
        *(undefined8 *)(puVar35 + -8) = 0x180033085;
        (*p_Var5)(pIVar13);
      }
      local_48c = local_48c + 1;
      puVar34 = puVar35;
    } while (local_48c <= local_4a0[0]);
  }
  *(undefined8 *)(puVar35 + -8) = 0x18003309f;
  SafeArrayUnlock(psa);
  *(undefined8 *)(puVar35 + -8) = 0x1800330a8;
  SafeArrayDestroy(psa);
  *(undefined1 **)(puVar35 + 0x20) = local_348;
  plVar10 = local_450;
  *(undefined8 *)(puVar35 + -8) = 0x1800330d3;
  _splitpath((char *)plVar10,local_400,local_148,local_248,*(char **)(puVar35 + 0x20));
  local_4b8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  pCStack_4b0 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  local_4a8 = 0;
  *(undefined8 *)(puVar35 + -8) = 0x1800330e9;
  GetHybridModelList(&local_4b8);
  pCVar24 = pCStack_4b0;
  if ((longlong)pCStack_4b0 - (longlong)local_4b8 >> 3 == 0) {
    pCVar12 = local_4b8;
    pCVar32 = local_4b8;
    if (local_4b8 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
      for (; local_4b8 = pCVar32, pCVar12 != pCVar24; pCVar12 = pCVar12 + 8) {
        *(undefined8 *)(puVar35 + -8) = 0x180033119;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar12);
        pCVar32 = local_4b8;
      }
      if (0xfff < (ulonglong)((local_4a8 - (longlong)pCVar32 >> 3) * 8)) {
        lVar20 = (longlong)pCVar32 -
                 (longlong)
                 *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)(pCVar32 + -8);
        pCVar32 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)(pCVar32 + -8);
        goto joined_r0x0001800338ec;
      }
      goto LAB_18003315e;
    }
  }
  else {
    if (DAT_1800540c8 == (IUnknown *)0x0) {
      *(IUnknown ***)(puVar35 + 0x20) = &DAT_1800540c8;
      puVar39 = &DAT_180042880;
      uVar22 = 0;
      uVar38 = 1;
      *(undefined8 *)(puVar35 + -8) = 0x1800331e0;
      HVar17 = CoCreateInstance((IID *)&DAT_180042890,(LPUNKNOWN)0x0,1,(IID *)&DAT_180042880,
                                *(LPVOID **)(puVar35 + 0x20));
      if (HVar17 < 0) {
        DAT_1800540c8 = (IUnknown *)0x0;
      }
      if (HVar17 != 0) {
        if (DAT_1800540c8 != (IUnknown *)0x0) {
          p_Var5 = DAT_1800540c8->lpVtbl->Release;
          *(undefined8 *)(puVar35 + -8) = 0x18003320d;
          (*p_Var5)(DAT_1800540c8);
        }
        DAT_1800540c8 = (IUnknown *)0x0;
        *(undefined8 *)(puVar35 + -8) = 0x180033221;
        FUN_18001f260("!!!Compound File - Failed to get IModelLibraryManagerPtr\n",uVar22,uVar38,
                      puVar39);
        pCVar32 = pCStack_4b0;
        pCVar24 = local_4b8;
        if (local_4b8 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
          for (; pCVar24 != pCVar32; pCVar24 = pCVar24 + 8) {
            *(undefined8 *)(puVar35 + -8) = 0x18003323d;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar24);
          }
          pCVar24 = local_4b8;
          if ((0xfff < (ulonglong)((local_4a8 - (longlong)local_4b8 >> 3) * 8)) &&
             (pCVar24 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                         (local_4b8 + -8),
             (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x1f <
             local_4b8 + (-8 - (longlong)pCVar24))) goto LAB_1800338f2;
          *(undefined8 *)(puVar35 + -8) = 0x18003328a;
          FUN_180035134(pCVar24);
          local_4b8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
          pCStack_4b0 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
          local_4a8 = 0;
        }
        *(undefined8 *)(puVar35 + -8) = 0x1800332a0;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_488);
        uVar22 = 0;
        goto LAB_180033181;
      }
      if (DAT_1800540c8 == (IUnknown *)0x0) {
                    /* WARNING: Subroutine does not return */
        *(undefined **)(puVar35 + -8) = &UNK_18003390e;
        FUN_180034a60(0x80004003);
      }
    }
    pIVar13 = DAT_1800540c8;
    local_418 = 0;
    p_Var5 = DAT_1800540c8->lpVtbl[3].Release;
    *(undefined8 *)(puVar35 + -8) = 0x1800332c7;
    UVar18 = (*p_Var5)(DAT_1800540c8);
    if ((int)UVar18 < 0) {
      *(undefined8 *)(puVar35 + -8) = 0x1800332dc;
      _com_issue_errorex(UVar18,pIVar13,(_GUID *)&DAT_180042880);
    }
    uVar22 = local_418;
    *(undefined8 *)(puVar35 + -8) = 0x1800332ed;
    puVar23 = operator_new(0x18);
    if (puVar23 == (undefined8 *)0x0) {
      puVar23 = (undefined8 *)0x0;
    }
    else {
      puVar23[1] = 0;
      *(undefined4 *)(puVar23 + 2) = 1;
      *puVar23 = uVar22;
    }
    local_458 = puVar23;
    if (puVar23 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
      *(undefined8 *)(puVar35 + -8) = 0x180033919;
      FUN_180034a60(0x8007000e);
    }
    lpWideCharStr = (LPCWSTR)*puVar23;
    puVar34 = puVar35;
    if (lpWideCharStr == (LPCWSTR)0x0) {
LAB_180033397:
      pcVar37 = (char *)0x0;
      puVar35 = puVar34;
    }
    else {
      lVar20 = -1;
      do {
        lVar21 = lVar20;
        lVar20 = lVar21 + 1;
      } while (lpWideCharStr[lVar20] != L'\0');
      iVar30 = (int)lVar21 + 2;
      if (0x3fffffff < iVar30) goto LAB_180033397;
      lVar20 = (longlong)(int)lVar20 * 2;
      uVar29 = lVar20 + 0x11;
      if (uVar29 <= lVar20 + 2U) {
        uVar29 = 0xffffffffffffff0;
      }
      *(undefined8 *)(puVar35 + -8) = 0x18003335c;
      lVar20 = -(uVar29 & 0xfffffffffffffff0);
      puVar34 = puVar35 + lVar20;
      puVar36 = puVar35 + lVar20;
      pcVar37 = puVar35 + lVar20 + 0x40;
      if (pcVar37 == (char *)0x0) goto LAB_180033397;
      *pcVar37 = '\0';
      *(undefined8 *)(puVar35 + lVar20 + 0x38) = 0;
      *(undefined8 *)(puVar35 + lVar20 + 0x30) = 0;
      *(int *)(puVar35 + lVar20 + 0x28) = iVar30 * 2;
      *(char **)(puVar35 + lVar20 + 0x20) = pcVar37;
      *(undefined8 *)(puVar35 + lVar20 + -8) = 0x18003338f;
      iVar30 = WideCharToMultiByte(0,0,lpWideCharStr,-1,*(LPSTR *)(puVar35 + lVar20 + 0x20),
                                   *(int *)(puVar35 + lVar20 + 0x28),
                                   *(LPCSTR *)(puVar35 + lVar20 + 0x30),
                                   *(LPBOOL *)(puVar35 + lVar20 + 0x38));
      puVar35 = puVar35 + lVar20;
      if (iVar30 == 0) {
        pcVar37 = (char *)0x0;
        puVar35 = puVar36;
      }
    }
    *(undefined8 *)(puVar35 + -8) = 0x1800333aa;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_430,pcVar37);
    for (iVar30 = 0;
        (ulonglong)(longlong)iVar30 < (ulonglong)((longlong)pCStack_4b0 - (longlong)local_4b8 >> 3);
        iVar30 = iVar30 + 1) {
      *(undefined8 *)(puVar35 + -8) = 0x1800333d4;
      CFileFind::CFileFind(local_3b0);
      pCVar3 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               (local_4b8 + (longlong)iVar30 * 8);
      *(undefined8 *)(puVar35 + -8) = 0x1800333e7;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_480,pCVar3)
      ;
      *(undefined8 *)(puVar35 + -8) = 0x1800333f2;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_498);
      *(undefined8 *)(puVar35 + -8) = 0x1800333fd;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_468);
      uVar38 = local_430;
      uVar22 = local_480;
      *(undefined8 *)(puVar35 + -8) = 0x18003341a;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_498,
                 "%s\\%s.athm",uVar38,uVar22);
      pcVar37 = local_498;
      *(undefined8 *)(puVar35 + -8) = 0x18003342d;
      iVar19 = CFileFind::FindFile(local_3b0,pcVar37,0);
      uVar38 = local_430;
      uVar22 = local_480;
      if (iVar19 == 1) {
        pcVar37 = "%s%s.athm";
      }
      else {
        *(undefined8 *)(puVar35 + -8) = 0x180033457;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_498,
                   "%s\\%s.xlp",uVar38,uVar22);
        pcVar37 = "%s%s.xlp";
      }
      uVar22 = local_480;
      pcVar14 = local_488;
      *(undefined8 *)(puVar35 + -8) = 0x180033470;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_468,pcVar37
                 ,pcVar14,uVar22);
      *(undefined8 *)(puVar35 + -8) = 0x180033482;
      pCVar24 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          (local_3f8,
                           (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                            *)&local_498);
      uVar22 = *(undefined8 *)pCVar24;
      *(undefined8 *)(puVar35 + -8) = 0x180033495;
      iVar19 = _stat64i32(uVar22,local_378);
      if (iVar19 == 0) {
        if (local_364 == 0) {
          *(undefined8 *)(puVar35 + -8) = 0x1800334b8;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar24);
          bVar11 = true;
        }
        else {
          *(undefined8 *)(puVar35 + -8) = 0x1800334c5;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar24);
          bVar11 = false;
        }
      }
      else {
        *(undefined8 *)(puVar35 + -8) = 0x1800334a2;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar24);
        bVar11 = true;
      }
      pCVar15 = local_468;
      if (bVar11) {
        *(undefined8 *)(puVar35 + -8) = 0x18003392d;
        FUN_180025880(local_3c8,"File Size is 0");
                    /* WARNING: Subroutine does not return */
        *(undefined8 *)(puVar35 + -8) = 0x180033940;
        _CxxThrowException(local_3c8,(ThrowInfo *)&DAT_180049220);
      }
      *(undefined8 *)(puVar35 + -8) = 0x1800334dd;
      ppppppuVar25 = operator_new(0x18);
      local_4c8 = (undefined8 *******)ppppppuVar25;
      if (ppppppuVar25 == (undefined8 ******)0x0) {
        ppppppuVar25 = (undefined8 ******)0x0;
      }
      else {
        ppppppuVar25[1] = (undefined8 *****)0x0;
        *(undefined4 *)(ppppppuVar25 + 2) = 1;
        *(undefined8 *)(puVar35 + -8) = 0x1800334fc;
        pppppuVar26 = (undefined8 *****)FUN_180034c50(pCVar15);
        *ppppppuVar25 = pppppuVar26;
      }
      pcVar37 = local_498;
      local_3e8 = ppppppuVar25;
      if (ppppppuVar25 == (undefined8 ******)0x0) {
                    /* WARNING: Subroutine does not return */
        *(undefined8 *)(puVar35 + -8) = 0x18003394a;
        FUN_180034a60(0x8007000e);
      }
      *(undefined8 *)(puVar35 + -8) = 0x180033522;
      ppppppuVar27 = operator_new(0x18);
      local_4c8 = (undefined8 *******)ppppppuVar27;
      if (ppppppuVar27 == (undefined8 ******)0x0) {
        ppppppuVar27 = (undefined8 ******)0x0;
      }
      else {
        ppppppuVar27[1] = (undefined8 *****)0x0;
        *(undefined4 *)(ppppppuVar27 + 2) = 1;
        *(undefined8 *)(puVar35 + -8) = 0x180033541;
        pppppuVar26 = (undefined8 *****)FUN_180034c50(pcVar37);
        *ppppppuVar27 = pppppuVar26;
      }
      local_3e0 = ppppppuVar27;
      if (ppppppuVar27 == (undefined8 ******)0x0) {
                    /* WARNING: Subroutine does not return */
        *(undefined8 *)(puVar35 + -8) = 0x180033955;
        FUN_180034a60(0x8007000e);
      }
      local_450 = (longlong *)0x0;
      *(undefined8 *)(puVar35 + -8) = 0x180033567;
      ppppppuVar28 = operator_new(0x18);
      local_4c8 = (undefined8 *******)ppppppuVar28;
      if (ppppppuVar28 == (undefined8 ******)0x0) {
        local_438 = (undefined8 ******)0x0;
      }
      else {
        ppppppuVar28[1] = (undefined8 *****)0x0;
        *(undefined4 *)(ppppppuVar28 + 2) = 1;
        *(undefined8 *)(puVar35 + -8) = 0x18003358a;
        pppppuVar26 = (undefined8 *****)FUN_180034c50("");
        *ppppppuVar28 = pppppuVar26;
        local_438 = ppppppuVar28;
      }
      pIVar13 = local_478;
      if (local_438 == (undefined8 ******)0x0) {
                    /* WARNING: Subroutine does not return */
        *(undefined **)(puVar35 + -8) = &UNK_180033960;
        FUN_180034a60(0x8007000e);
      }
      local_4c8 = &local_438;
      LOCK();
      *(int *)(ppppppuVar27 + 2) = *(int *)(ppppppuVar27 + 2) + 1;
      UNLOCK();
      local_3d8 = &local_440;
      LOCK();
      *(int *)(ppppppuVar25 + 2) = *(int *)(ppppppuVar25 + 2) + 1;
      UNLOCK();
      local_3d0 = &local_448;
      local_410 = (longlong *)0x0;
      if (ppppppuVar27 == (undefined8 ******)0x0) {
        pppppuVar26 = (undefined8 *****)0x0;
      }
      else {
        pppppuVar26 = *ppppppuVar27;
      }
      if (ppppppuVar25 == (undefined8 ******)0x0) {
        riid = (IID *)0x0;
      }
      else {
        riid = (IID *)*ppppppuVar25;
      }
      pIVar6 = local_478->lpVtbl;
      local_448 = ppppppuVar25;
      local_440 = ppppppuVar27;
      *(longlong ***)(puVar35 + 0x28) = &local_410;
      *(undefined2 *)(puVar35 + 0x20) = 0xffff;
      p_Var7 = pIVar6[8].QueryInterface;
      *(undefined8 *)(puVar35 + -8) = 0x180033646;
      HVar17 = (*p_Var7)(pIVar13,riid,pppppuVar26);
      if (HVar17 < 0) {
        *(undefined8 *)(puVar35 + -8) = 0x18003365b;
        _com_issue_errorex(HVar17,pIVar13,(_GUID *)&DAT_1800424d8);
      }
      plVar10 = local_410;
      *(undefined8 *)(puVar35 + -8) = 0x18003366e;
      FUN_18001ccd0(&local_448);
      *(undefined8 *)(puVar35 + -8) = 0x18003367b;
      FUN_18001ccd0(&local_440);
      *(undefined8 *)(puVar35 + -8) = 0x180033688;
      FUN_18001ccd0(&local_438);
      if (plVar10 == (longlong *)0x0) {
        plVar10 = local_450;
      }
      else {
        pcVar8 = *(code **)(*plVar10 + 8);
        *(undefined8 *)(puVar35 + -8) = 0x180033696;
        (*pcVar8)(plVar10);
        local_450 = plVar10;
        pcVar8 = *(code **)(*plVar10 + 0x10);
        *(undefined8 *)(puVar35 + -8) = 0x1800336b1;
        (*pcVar8)(plVar10);
      }
      if (plVar10 != (longlong *)0x0) {
        pcVar8 = *(code **)(*plVar10 + 0x10);
        *(undefined8 *)(puVar35 + -8) = 0x1800336c0;
        (*pcVar8)(plVar10);
      }
      LOCK();
      ppppppuVar28 = ppppppuVar27 + 2;
      iVar19 = *(int *)ppppppuVar28;
      *(int *)ppppppuVar28 = *(int *)ppppppuVar28 + -1;
      UNLOCK();
      if (iVar19 == 1) {
        pppppuVar26 = *ppppppuVar27;
        if (pppppuVar26 != (undefined8 *****)0x0) {
          *(undefined8 *)(puVar35 + -8) = 0x1800336dd;
          SysFreeString((BSTR)pppppuVar26);
          *ppppppuVar27 = (undefined8 *****)0x0;
        }
        pppppuVar26 = ppppppuVar27[1];
        if (pppppuVar26 != (undefined8 *****)0x0) {
          *(undefined8 *)(puVar35 + -8) = 0x1800336ee;
          operator_delete__(pppppuVar26);
          ppppppuVar27[1] = (undefined8 *****)0x0;
        }
        *(undefined8 *)(puVar35 + -8) = 0x1800336ff;
        FUN_180035134(ppppppuVar27);
      }
      LOCK();
      ppppppuVar27 = ppppppuVar25 + 2;
      iVar19 = *(int *)ppppppuVar27;
      *(int *)ppppppuVar27 = *(int *)ppppppuVar27 + -1;
      UNLOCK();
      if (iVar19 == 1) {
        pppppuVar26 = *ppppppuVar25;
        if (pppppuVar26 != (undefined8 *****)0x0) {
          *(undefined8 *)(puVar35 + -8) = 0x18003371c;
          SysFreeString((BSTR)pppppuVar26);
          *ppppppuVar25 = (undefined8 *****)0x0;
        }
        pppppuVar26 = ppppppuVar25[1];
        if (pppppuVar26 != (undefined8 *****)0x0) {
          *(undefined8 *)(puVar35 + -8) = 0x18003372d;
          operator_delete__(pppppuVar26);
          ppppppuVar25[1] = (undefined8 *****)0x0;
        }
        *(undefined8 *)(puVar35 + -8) = 0x18003373e;
        FUN_180035134(ppppppuVar25);
      }
      *(undefined8 *)(puVar35 + -8) = 0x180033749;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_468);
      *(undefined8 *)(puVar35 + -8) = 0x180033754;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_498);
      *(undefined8 *)(puVar35 + -8) = 0x18003375f;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_480);
      *(undefined8 *)(puVar35 + -8) = 0x18003376c;
      CFileFind::~CFileFind(local_3b0);
      puVar23 = local_458;
    }
    *(undefined8 *)(puVar35 + -8) = 0x180033841;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_430);
    puVar16 = local_458;
    if (puVar23 != (undefined8 *)0x0) {
      LOCK();
      piVar2 = (int *)(puVar23 + 2);
      iVar30 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar30 == 1) {
        bstrString = (BSTR)*local_458;
        if (bstrString != (BSTR)0x0) {
          *(undefined8 *)(puVar35 + -8) = 0x180033865;
          SysFreeString(bstrString);
          *puVar16 = 0;
        }
        pvVar9 = (void *)puVar16[1];
        if (pvVar9 != (void *)0x0) {
          *(undefined8 *)(puVar35 + -8) = 0x180033876;
          operator_delete__(pvVar9);
          puVar16[1] = 0;
        }
        *(undefined8 *)(puVar35 + -8) = 0x180033887;
        FUN_180035134(puVar16);
      }
    }
    pCVar12 = pCStack_4b0;
    pCVar24 = local_4b8;
    pCVar32 = local_4b8;
    if (local_4b8 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
      for (; local_4b8 = pCVar32, pCVar24 != pCVar12; pCVar24 = pCVar24 + 8) {
        *(undefined8 *)(puVar35 + -8) = 0x1800338a9;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar24);
        pCVar32 = local_4b8;
      }
      if (0xfff < (ulonglong)((local_4a8 - (longlong)pCVar32 >> 3) * 8)) {
        lVar20 = (longlong)pCVar32 -
                 (longlong)
                 *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)(pCVar32 + -8);
        pCVar32 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)(pCVar32 + -8);
joined_r0x0001800338ec:
        if (0x1f < lVar20 - 8U) {
LAB_1800338f2:
                    /* WARNING: Subroutine does not return */
          *(undefined **)(puVar35 + -8) = &UNK_1800338f8;
          _invalid_parameter_noinfo_noreturn();
        }
      }
LAB_18003315e:
      *(undefined8 *)(puVar35 + -8) = 0x180033166;
      FUN_180035134(pCVar32);
      local_4b8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
      pCStack_4b0 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
      local_4a8 = 0;
    }
  }
  *(undefined8 *)(puVar35 + -8) = 0x18003317c;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_488);
  uVar22 = 1;
LAB_180033181:
  *(undefined8 *)(puVar35 + -8) = 0x180033190;
  return uVar22;
}

/* RVA 0x33970 */
int FUN_180033970(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0xc);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  return iVar2 + 1;
}

/* RVA 0x33980 */
int FUN_180033980(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0xc);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  return iVar2 + -1;
}

/* RVA 0x33990 */
undefined4 FUN_180033990(longlong param_1)

{
  return *(undefined4 *)(param_1 + 0xc);
}

/* RVA 0x339a0 */
HRESULT FUN_1800339a0(longlong param_1,undefined8 *param_2)

{
  LPVOID *ppv;
  HRESULT HVar1;
  
  if (param_2 == (undefined8 *)0x0) {
    return -0x7fffbffd;
  }
  ppv = (LPVOID *)(param_1 + 0x40);
  HVar1 = 0;
  if ((*ppv == (LPVOID)0x0) &&
     (HVar1 = CoCreateInstance((IID *)&DAT_180042af8,(LPUNKNOWN)0x0,1,(IID *)&DAT_180042978,ppv),
     HVar1 < 0)) {
    return HVar1;
  }
  *param_2 = *ppv;
  (**(code **)(*(longlong *)*ppv + 8))();
  return HVar1;
}

/* RVA 0x33a20 */
void FUN_180033a20(undefined8 param_1,longlong *param_2)

{
                    /* WARNING: Could not recover jumptable at 0x000180033a34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_2 + 0x18))(param_2,L"APPID",L"{5B52D748-52AB-47EE-8180-D7E0F50C5219}");
  return;
}

/* RVA 0x33a40 */
void * FUN_180033a40(void *param_1,uint param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  
  plVar1 = (longlong *)PTR_PTR_1800527b0;
  plVar2 = (longlong *)PTR_DAT_1800527b8;
  if (PTR_PTR_1800527b0 < PTR_DAT_1800527b8) {
    do {
      if (*plVar1 != 0) {
        (**(code **)(*plVar1 + 0x38))(0);
        plVar2 = (longlong *)PTR_DAT_1800527b8;
      }
      plVar1 = plVar1 + 1;
    } while (plVar1 < plVar2);
  }
  FUN_180033ac0((longlong)param_1);
  if ((param_2 & 1) != 0) {
    FUN_180035134(param_1);
  }
  return param_1;
}

/* RVA 0x33ac0 */
void FUN_180033ac0(longlong param_1)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined8 *puVar3;
  longlong lVar4;
  
  if (*(int *)(param_1 + 8) != 0) {
    if (*(longlong *)(param_1 + 0x10) != 0) {
      lVar4 = param_1 + 8;
      if (param_1 == 0) {
        lVar4 = 0;
      }
      if (lVar4 == 0) {
        FUN_180033b80(0xc0000005,1);
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      puVar3 = *(undefined8 **)(lVar4 + 8);
      while (puVar3 != (undefined8 *)0x0) {
        (*(code *)*puVar3)(puVar3[1]);
        puVar1 = (undefined8 *)puVar3[2];
        FUN_180035134(puVar3);
        puVar3 = puVar1;
      }
      *(undefined8 *)(lVar4 + 8) = 0;
      *(undefined8 *)(param_1 + 0x10) = 0;
    }
    if (*(longlong **)(param_1 + 0x40) != (longlong *)0x0) {
      (**(code **)(**(longlong **)(param_1 + 0x40) + 0x10))();
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}

/* RVA 0x33b80 */
void FUN_180033b80(DWORD param_1,DWORD param_2)

{
                    /* WARNING: Could not recover jumptable at 0x000180033b86. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RaiseException(param_1,param_2,0,(ULONG_PTR *)0x0);
  return;
}

/* RVA 0x33b90 */
undefined8 FUN_180033b90(undefined8 param_1,int param_2)

{
  if ((param_2 == 1) && (DAT_1800534b0 != '\0')) {
    return 0;
  }
  return 1;
}

/* RVA 0x33bb0 */
undefined * FUN_180033bb0(void)

{
  return &DAT_1800429c0;
}

/* RVA 0x33bc0 */
char * FUN_180033bc0(void)

{
  return "V15.0";
}

/* RVA 0x33bd0 */
undefined4 FUN_180033bd0(void)

{
  return DAT_180052850;
}

/* RVA 0x33be0 */
char * FUN_180033be0(void)

{
  char *pcVar1;
  
  pcVar1 = "Aspen Plus";
  if (DAT_180052850 == 2) {
    pcVar1 = "Aspen Properties";
  }
  return pcVar1;
}

/* RVA 0x33c00 */
undefined * FUN_180033c00(void)

{
  return &DAT_18003ad3c;
}

/* RVA 0x33c10 */
void FUN_180033c10(int param_1)

{
  DAT_180052850 = (param_1 == 2) + 1;
  return;
}

/* RVA 0x33c21 */
void DelayLoad_Ordinal_50
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33c2d */
void HappGetClassObject(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033c2d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HappGetClassObject();
  return;
}

/* RVA 0x33c33 */
void FUN_180033c33(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *in_RAX;
  FARPROC UNRECOVERED_JUMPTABLE;
  undefined8 in_RDX;
  undefined8 in_R9;
  
  UNRECOVERED_JUMPTABLE = FUN_1800366e0(&ImgDelayDescr_180049320.grAttrs,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x000180033caa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,in_RDX,param_3,in_R9);
  return;
}

/* RVA 0x33cac */
void DelayLoad_Ordinal_58
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33cb8 */
void HappFireBeforeSave(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033cb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HappFireBeforeSave();
  return;
}

/* RVA 0x33cbe */
void DelayLoad_Ordinal_21
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33cca */
void HappGetHapp(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033cca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HappGetHapp();
  return;
}

/* RVA 0x33cd0 */
void DelayLoad_Ordinal_22
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33cdc */
void HappGetTree(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033cdc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HappGetTree();
  return;
}

/* RVA 0x33ce2 */
void DelayLoad_Ordinal_10
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33cee */
void HappInitted(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033cee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HappInitted();
  return;
}

/* RVA 0x33cf4 */
void DelayLoad_Ordinal_12
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33d00 */
void HappName(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033d00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HappName();
  return;
}

/* RVA 0x33d06 */
void DelayLoad_Ordinal_9(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33d12 */
void NewHapp(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033d12. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  NewHapp();
  return;
}

/* RVA 0x33d18 */
void DelayLoad_Ordinal_6(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33d24 */
void OpenHappArchive(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033d24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OpenHappArchive();
  return;
}

/* RVA 0x33d2a */
void DelayLoad_Ordinal_4(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33d36 */
void RestoreHappArchive(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033d36. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RestoreHappArchive();
  return;
}

/* RVA 0x33d3c */
void DelayLoad_Ordinal_17
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33d48 */
void WriteHappArchive(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033d48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WriteHappArchive();
  return;
}

/* RVA 0x33d4e */
void DelayLoad_Ordinal_32
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33d5a */
void HappIsDirty(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033d5a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HappIsDirty();
  return;
}

/* RVA 0x33d60 */
void DelayLoad_Ordinal_47
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33d6c */
void HappSetDirty(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033d6c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HappSetDirty();
  return;
}

/* RVA 0x33d72 */
void DelayLoad_Ordinal_5(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33d7e */
void OpenHapp(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033d7e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OpenHapp();
  return;
}

/* RVA 0x33d84 */
void DelayLoad_Ordinal_34
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33d90 */
void InitializeHapp(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033d90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InitializeHapp();
  return;
}

/* RVA 0x33d96 */
void DelayLoad_Ordinal_68
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33da2 */
void OpenHappArchiveStg(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033da2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OpenHappArchiveStg();
  return;
}

/* RVA 0x33da8 */
void DelayLoad_Ordinal_46
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33db4 */
void OpenHappInput(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033db4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OpenHappInput();
  return;
}

/* RVA 0x33dba */
void DelayLoad_Ordinal_7(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33dc6 */
void SaveHapp(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033dc6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SaveHapp();
  return;
}

/* RVA 0x33dcc */
void DelayLoad_Ordinal_23
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33dd8 */
void HappWriteExport(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033dd8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HappWriteExport();
  return;
}

/* RVA 0x33dde */
void DelayLoad_Ordinal_61
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33dea */
void HappWriteExportHier(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033dea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HappWriteExportHier();
  return;
}

/* RVA 0x33df0 */
void DelayLoad_Ordinal_54
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33dfc */
void HappUpdateMoniker(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033dfc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HappUpdateMoniker();
  return;
}

/* RVA 0x33e02 */
void DelayLoad_Ordinal_57
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33e0e */
void HappFireBeforeCalculate(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033e0e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HappFireBeforeCalculate();
  return;
}

/* RVA 0x33e14 */
void DelayLoad_Ordinal_59
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33e20 */
void HappFireCalculationCompleted(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033e20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HappFireCalculationCompleted();
  return;
}

/* RVA 0x33e26 */
void DelayLoad_Ordinal_63
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33e32 */
void HappFireCalculationStopped(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033e32. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HappFireCalculationStopped();
  return;
}

/* RVA 0x33e38 */
void DelayLoad_Ordinal_64
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33e44 */
void HappFireUpdateMessage(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033e44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HappFireUpdateMessage();
  return;
}

/* RVA 0x33e4a */
void DelayLoad_Ordinal_65
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33e56 */
void HappFireInClosing(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033e56. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HappFireInClosing();
  return;
}

/* RVA 0x33e5c */
void DelayLoad_Ordinal_69
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33e68 */
void HappFireGuiClosed(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033e68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HappFireGuiClosed();
  return;
}

/* RVA 0x33e6e */
void DelayLoad_Ordinal_67
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33e7a */
void HappFireEngineCommandCompleted(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033e7a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HappFireEngineCommandCompleted();
  return;
}

/* RVA 0x33e80 */
void DelayLoad_Ordinal_15
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33e8c */
void RegisterClassFactory(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033e8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RegisterClassFactory();
  return;
}

/* RVA 0x33e92 */
void DelayLoad_Ordinal_16
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33e9e */
void LockGlobalObject(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033e9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LockGlobalObject();
  return;
}

/* RVA 0x33ea4 */
void DelayLoad_Ordinal_20
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33eb0 */
void APInitInstance(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033eb0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  APInitInstance();
  return;
}

/* RVA 0x33eb6 */
void DelayLoad_Ordinal_35
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033c33(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33ec2 */
void APExitInstance(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033ec2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  APExitInstance();
  return;
}

/* RVA 0x33ec8 */
void DelayLoad_MMSetVisibleSuppress
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33ed4 */
void MMSetVisibleSuppress(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033ed4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MMSetVisibleSuppress();
  return;
}

/* RVA 0x33eda */
void FUN_180033eda(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *in_RAX;
  FARPROC UNRECOVERED_JUMPTABLE;
  undefined8 in_RDX;
  undefined8 in_R9;
  
  UNRECOVERED_JUMPTABLE = FUN_1800366e0(&ImgDelayDescr_180049340.grAttrs,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x000180033f51. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,in_RDX,param_3,in_R9);
  return;
}

/* RVA 0x33f53 */
void DelayLoad_MMGetSuppress
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33f5f */
void MMGetSuppress(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033f5f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MMGetSuppress();
  return;
}

/* RVA 0x33f65 */
void DelayLoad_MMGetVisibleSuppress
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33f71 */
void MMGetVisibleSuppress(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033f71. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MMGetVisibleSuppress();
  return;
}

/* RVA 0x33f77 */
void DelayLoad__MMAfxMessageBox__YAHPEBDIHI_Z
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33f83 */
int __cdecl MMAfxMessageBox(char *param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180033f83. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = MMAfxMessageBox(param_1,param_2,param_3,param_4);
  return iVar1;
}

/* RVA 0x33f89 */
void DelayLoad__GetProfileStringA__YAPEBDPEBD00_Z
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33f95 */
void DelayLoad__MMGetProfileInt__YAHPEBD0H_Z
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33fa1 */
int __cdecl MMGetProfileInt(char *param_1,char *param_2,int param_3)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180033fa1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = MMGetProfileInt(param_1,param_2,param_3);
  return iVar1;
}

/* RVA 0x33fa7 */
void DelayLoad_ApwnLibInitFromRegistry
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33fb3 */
void ApwnLibInitFromRegistry(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033fb3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ApwnLibInitFromRegistry();
  return;
}

/* RVA 0x33fb9 */
void DelayLoad_InitializeApwnLibraries
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33fc5 */
void InitializeApwnLibraries(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033fc5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InitializeApwnLibraries();
  return;
}

/* RVA 0x33fcb */
void DelayLoad_FreeGlobalBlockUsage
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33fd7 */
void FreeGlobalBlockUsage(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033fd7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FreeGlobalBlockUsage();
  return;
}

/* RVA 0x33fdd */
void DelayLoad_FreeGlobalApwnLib
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33fe9 */
void FreeGlobalApwnLib(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033fe9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FreeGlobalApwnLib();
  return;
}

/* RVA 0x33fef */
void DelayLoad_InitGlobalBlockUsage
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x33ffb */
void InitGlobalBlockUsage(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180033ffb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InitGlobalBlockUsage();
  return;
}

/* RVA 0x34001 */
void DelayLoad_SEInitializeVData
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x3400d */
void SEInitializeVData(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003400d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SEInitializeVData();
  return;
}

/* RVA 0x34013 */
void DelayLoad_SetGlobalPointer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x3401f */
void SetGlobalPointer(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003401f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetGlobalPointer();
  return;
}

/* RVA 0x34025 */
void DelayLoad_SetGlobalCharPointer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x34031 */
void SetGlobalCharPointer(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180034031. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetGlobalCharPointer();
  return;
}

/* RVA 0x34037 */
void DelayLoad_GetGlobalPointer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x34043 */
void GetGlobalPointer(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180034043. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetGlobalPointer();
  return;
}

/* RVA 0x34049 */
void DelayLoad_RestoreEmbeddedObjects
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x34055 */
void RestoreEmbeddedObjects(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180034055. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RestoreEmbeddedObjects();
  return;
}

/* RVA 0x3405b */
void DelayLoad_ReadACEStringFromIStream
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x34067 */
void ReadACEStringFromIStream(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180034067. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ReadACEStringFromIStream();
  return;
}

/* RVA 0x3406d */
void DelayLoad_WriteACEStringToIStream
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x34079 */
void WriteACEStringToIStream(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180034079. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WriteACEStringToIStream();
  return;
}

/* RVA 0x3407f */
void DelayLoad_SThasstr(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x3408b */
void SThasstr(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003408b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SThasstr();
  return;
}

/* RVA 0x34091 */
void DelayLoad_STremstr(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x3409d */
void STremstr(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003409d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  STremstr();
  return;
}

/* RVA 0x340a3 */
void DelayLoad_STclsstg(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x340af */
void STclsstg(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800340af. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  STclsstg();
  return;
}

/* RVA 0x340b5 */
void DelayLoad_SEGetSettingValue
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x340c1 */
void SEGetSettingValue(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800340c1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SEGetSettingValue();
  return;
}

/* RVA 0x340c7 */
void DelayLoad_SESetSettingValue
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x340d3 */
void SESetSettingValue(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800340d3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SESetSettingValue();
  return;
}

/* RVA 0x340d9 */
void DelayLoad_WriteApwnShellSettingsFromFileToStream
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x340e5 */
void WriteApwnShellSettingsFromFileToStream(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800340e5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WriteApwnShellSettingsFromFileToStream();
  return;
}

/* RVA 0x340eb */
void DelayLoad_ReadApwnShellSettingsFromStreamToFile
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x340f7 */
void ReadApwnShellSettingsFromStreamToFile(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800340f7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ReadApwnShellSettingsFromStreamToFile();
  return;
}

/* RVA 0x340fd */
void DelayLoad_SetGlobalWinApp
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x34109 */
void SetGlobalWinApp(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180034109. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetGlobalWinApp();
  return;
}

/* RVA 0x3410f */
void DelayLoad__GetLMSystemProfileString__YAPEBDPEBD0_Z
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x3411b */
void DelayLoad__GetLMProfileString__YAPEBDPEBD00_Z
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x34127 */
void DelayLoad__MMReplaceEnvironmentVariables__YAPEBDPEBD_Z
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x34133 */
void DelayLoad_SEInitialize
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x3413f */
void SEInitialize(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003413f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SEInitialize();
  return;
}

/* RVA 0x34145 */
void DelayLoad_SEFreeSettings
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x34151 */
void SEFreeSettings(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180034151. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SEFreeSettings();
  return;
}

/* RVA 0x34157 */
void DelayLoad_SetBlockEOStatus
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x34163 */
void SetBlockEOStatus(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180034163. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetBlockEOStatus();
  return;
}

/* RVA 0x34169 */
void DelayLoad_MMInitWaitStruct
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x34175 */
void DelayLoad_MMReleaseWaitStruct
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x34181 */
void DelayLoad_MMStructInitExtDLL
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x3418d */
void MMStructInitExtDLL(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003418d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MMStructInitExtDLL();
  return;
}

/* RVA 0x34193 */
void DelayLoad_APModLibGetValues
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x3419f */
void APModLibGetValues(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003419f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  APModLibGetValues();
  return;
}

/* RVA 0x341a5 */
void DelayLoad_ApwnLibraryCount
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x341b1 */
void ApwnLibraryCount(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800341b1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ApwnLibraryCount();
  return;
}

/* RVA 0x341b7 */
void DelayLoad_ApwnLibraryGetAt
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180033eda(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x341c3 */
void ApwnLibraryGetAt(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800341c3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ApwnLibraryGetAt();
  return;
}

/* RVA 0x341c9 */
void DelayLoad_Ordinal_131
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_1800341db(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x341d5 */
void Ordinal_131(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800341d5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_131();
  return;
}

/* RVA 0x341db */
void FUN_1800341db(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *in_RAX;
  FARPROC UNRECOVERED_JUMPTABLE;
  undefined8 in_RDX;
  undefined8 in_R9;
  
  UNRECOVERED_JUMPTABLE = FUN_1800366e0(&ImgDelayDescr_180049360.grAttrs,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x000180034252. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,in_RDX,param_3,in_R9);
  return;
}

/* RVA 0x34254 */
void DelayLoad_DCOM_SET_SYNC
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_1800341db(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x34260 */
void DCOM_SET_SYNC(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180034260. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DCOM_SET_SYNC();
  return;
}

/* RVA 0x34266 */
void DelayLoad_DCOM_INIT(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  FUN_1800341db(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x34272 */
void DCOM_INIT(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180034272. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DCOM_INIT();
  return;
}

/* RVA 0x34278 */
void DelayLoad_DCOM_TERMINATE
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_1800341db(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x34284 */
void DCOM_TERMINATE(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180034284. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DCOM_TERMINATE();
  return;
}

/* RVA 0x3428a */
void DelayLoad_Ordinal_73
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_1800341db(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x34296 */
void DelayLoad__DCGetACMModelLibraryManagerPtr__YAPEAUIModelLibraryManager__XZ
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_1800341db(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x342a2 */
IModelLibraryManager * __cdecl DCGetACMModelLibraryManagerPtr(void)

{
  IModelLibraryManager *pIVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800342a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pIVar1 = DCGetACMModelLibraryManagerPtr();
  return pIVar1;
}

/* RVA 0x342a8 */
void DelayLoad_MVGetI18nProductName
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_1800342ba(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x342b4 */
void MVGetI18nProductName(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800342b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MVGetI18nProductName();
  return;
}

/* RVA 0x342ba */
void FUN_1800342ba(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *in_RAX;
  FARPROC UNRECOVERED_JUMPTABLE;
  undefined8 in_RDX;
  undefined8 in_R9;
  
  UNRECOVERED_JUMPTABLE = FUN_1800366e0(&ImgDelayDescr_180049380.grAttrs,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x000180034331. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,in_RDX,param_3,in_R9);
  return;
}

/* RVA 0x34333 */
void DelayLoad__CxsRaiseCustomEvent__YAXPEAUICXSDocumentV22__PEBD_KPEADH_Z
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180034345(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x3433f */
void __cdecl
CxsRaiseCustomEvent(ICXSDocumentV22 *param_1,char *param_2,__uint64 param_3,char *param_4,
                   int param_5)

{
                    /* WARNING: Could not recover jumptable at 0x00018003433f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CxsRaiseCustomEvent(param_1,param_2,param_3,param_4,param_5);
  return;
}

/* RVA 0x34345 */
void FUN_180034345(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *in_RAX;
  FARPROC UNRECOVERED_JUMPTABLE;
  undefined8 in_RDX;
  undefined8 in_R9;
  
  UNRECOVERED_JUMPTABLE = FUN_1800366e0(&ImgDelayDescr_1800493a0.grAttrs,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x0001800343bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,in_RDX,param_3,in_R9);
  return;
}

/* RVA 0x343be */
void DelayLoad__CxsRaiseCustomEventWait__YA_NPEAUICXSDocumentV22__PEBD_KPEADHHAEAJ_Z
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180034345(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x343ca */
bool __cdecl
CxsRaiseCustomEventWait
          (ICXSDocumentV22 *param_1,char *param_2,__uint64 param_3,char *param_4,int param_5,
          int param_6,long *param_7)

{
  bool bVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800343ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  bVar1 = CxsRaiseCustomEventWait(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return bVar1;
}

/* RVA 0x343d0 */
void DelayLoad__CxsClearNodeCaches__YAXXZ
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_180034345(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x343dc */
void __cdecl CxsClearNodeCaches(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800343dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CxsClearNodeCaches();
  return;
}

/* RVA 0x343e2 */
void FUN_1800343e2(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *in_RAX;
  FARPROC UNRECOVERED_JUMPTABLE;
  undefined8 in_RDX;
  undefined8 in_R9;
  
  UNRECOVERED_JUMPTABLE = FUN_1800366e0(&ImgDelayDescr_1800493c0.grAttrs,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x000180034459. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,in_RDX,param_3,in_R9);
  return;
}

/* RVA 0x3445b */
void DelayLoad_MDgetlibptr
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_1800343e2(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x34467 */
void DelayLoad_MDintlib(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_1800343e2(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x34473 */
void DelayLoad_MDintbku(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_1800343e2(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x3447f */
void DelayLoad_MDintecn(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_1800343e2(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x3448b */
void DelayLoad_SetModelLibraryPtr
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_1800343e2(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x34497 */
void DelayLoad_GRchkmmdir
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_1800343e2(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x344a3 */
void DelayLoad_GRchkhie(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_1800343e2(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x344af */
void DelayLoad_GRbldemrbkp
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_1800343e2(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x344bb */
void DelayLoad_GRbldbkprun
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_1800343e2(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x344c7 */
void DelayLoad_GRsetmod(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_1800343e2(param_1,param_2,param_3,param_4);
  return;
}

