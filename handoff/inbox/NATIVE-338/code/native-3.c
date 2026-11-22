/* ---- FUNC 00039D40 FUN_180039d40 (140 bytes) ---- */

undefined8 FUN_180039d40(longlong *param_1,wchar_t *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  longlong *plVar2;
  byte *local_res20;
  
  if (DAT_1800797f8 != 0) {
    uVar1 = (**(code **)(*param_1 + 0x210))(param_1,0x7f3);
    return uVar1;
  }
  if (param_1[9] == 0) {
    uVar1 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
    return uVar1;
  }
  *param_3 = 0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,param_2);
  plVar2 = FUN_180038fc0(param_1,local_res20);
  *param_3 = plVar2;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
  return 0;
}

/* ---- FUNC 00039DD0 FUN_180039dd0 (578 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_180039dd0(IUnknownVtbl *param_1,undefined8 param_2,VARIANTARG *param_3,undefined8 param_4)

{
  longlong lVar1;
  wchar_t *pwVar2;
  _func_5158 *p_Var3;
  int iVar4;
  IUnknownVtbl *pIVar5;
  longlong lVar6;
  ulonglong uVar7;
  int iVar8;
  undefined8 uVar9;
  undefined1 *puVar10;
  wchar_t *pwVar11;
  wchar_t *pwVar12;
  VARIANTARG *pVVar13;
  CHAR *pCVar14;
  undefined8 uStackY_1b0;
  undefined1 auStackY_1a8 [32];
  undefined8 *local_178;
  ULONGLONG local_170;
  uint local_168;
  undefined8 local_164;
  undefined8 uStack_15c;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 local_130;
  CHAR local_128;
  char acStack_127 [255];
  ulonglong local_28;
  
  puVar10 = auStackY_1a8;
  local_28 = DAT_180077818 ^ (ulonglong)&local_178;
  if (DAT_1800797f8 != 0) {
    uStackY_1b0 = 0x180039e1f;
    iVar4 = (**(code **)(param_1->QueryInterface + 0x210))(param_1,0x7f3);
    puVar10 = auStackY_1a8;
    goto LAB_180039fe9;
  }
  uStackY_1b0 = 0x180039e2d;
  uVar9 = param_2;
  pVVar13 = param_3;
  VariantInit(param_3);
  local_168 = (uint)param_2;
  pwVar11 = (wchar_t *)0x0;
  local_164 = _DAT_180065b90;
  uStack_15c = _UNK_180065b98;
  local_130 = 0;
  local_178 = (undefined8 *)0x0;
  local_140 = 0;
  uStack_138 = 0;
  local_150 = 0;
  uStack_148 = 0;
  if (param_1[3].QueryInterface == (_func_5156 *)0x0) {
    uStackY_1b0 = 0x180039e6e;
    iVar4 = (**(code **)(param_1->QueryInterface + 0x210))(param_1,0x7d9);
    puVar10 = auStackY_1a8;
    goto LAB_180039fe9;
  }
  uStackY_1b0 = 0x180039e78;
  FUN_18003c040((longlong)param_1,uVar9,pVVar13,param_4);
  uStackY_1b0 = 0x180039e8e;
  pIVar5 = (IUnknownVtbl *)HAGetElement(param_1[3].QueryInterface,&local_168,&local_150);
  if (pIVar5 == (IUnknownVtbl *)0x0) {
    if (local_178 != (undefined8 *)0x0) {
      if (*(short *)(local_178 + 1) == 0) {
        uStackY_1b0 = 0x180039ec5;
        iVar4 = (**(code **)(param_1->QueryInterface + 0x208))(param_1);
        puVar10 = auStackY_1a8;
        goto LAB_180039fe9;
      }
      if ((code *)*local_178 != (code *)0x0) {
        uStackY_1b0 = 0x180039eb2;
        (*(code *)*local_178)(local_178);
      }
    }
    iVar4 = 0;
    puVar10 = auStackY_1a8;
    goto LAB_180039fe9;
  }
  uStackY_1b0 = 0x180039eeb;
  iVar4 = FUN_1800389d0(pIVar5,(IUnknownVtbl *)param_1[3].AddRef,param_1,0,
                        (IUnknownVtbl *)param_1->Release,&local_170);
  if (iVar4 < 0) goto LAB_180039fe9;
  pCVar14 = &local_128;
  (param_3->n1).decVal.u2.Lo64 = local_170;
  (param_3->n1).n2.vt = 9;
  uStackY_1b0 = 0x180039f17;
  local_178 = (undefined8 *)HAGetLabel(param_1[3].QueryInterface,0,local_168);
  if (local_178 == (undefined8 *)0x0) {
    if (local_128 == '\0') goto LAB_180039f3d;
  }
  else {
    if ((code *)*local_178 != (code *)0x0) {
      uStackY_1b0 = 0x180039f2d;
      (*(code *)*local_178)(local_178);
    }
    local_178 = (undefined8 *)0x0;
    local_128 = '\0';
LAB_180039f3d:
    uStackY_1b0 = 0x180039f51;
    FUN_180002a20(&local_128,&DAT_180065a3c,(ulonglong)local_168,pCVar14);
  }
  lVar1 = -1;
  do {
    lVar6 = lVar1;
    lVar1 = lVar6 + 1;
  } while (acStack_127[lVar6] != '\0');
  iVar8 = (int)lVar6 + 2;
  puVar10 = auStackY_1a8;
  pwVar12 = pwVar11;
  if (iVar8 < 0x40000000) {
    lVar1 = (longlong)(int)(lVar6 + 1) * 2;
    uVar7 = lVar1 + 0x11;
    if (uVar7 <= lVar1 + 2U) {
      uVar7 = 0xffffffffffffff0;
    }
    uStackY_1b0 = 0x180039f9d;
    lVar1 = -(uVar7 & 0xfffffffffffffff0);
    pwVar2 = (wchar_t *)((longlong)&local_178 + lVar1);
    puVar10 = auStackY_1a8 + lVar1;
    if (pwVar2 != (wchar_t *)0x0) {
      *(int *)(&stack0xfffffffffffffe80 + lVar1) = iVar8;
      *pwVar2 = L'\0';
      *(wchar_t **)(&stack0xfffffffffffffe78 + lVar1) = pwVar2;
      *(undefined8 *)(auStackY_1a8 + lVar1 + -8) = 0x180039fca;
      iVar8 = MultiByteToWideChar(0,0,&local_128,-1,*(LPWSTR *)(&stack0xfffffffffffffe78 + lVar1),
                                  *(int *)(&stack0xfffffffffffffe80 + lVar1));
      puVar10 = auStackY_1a8 + lVar1;
      pwVar12 = pwVar2;
      if (iVar8 == 0) {
        puVar10 = auStackY_1a8 + lVar1;
        pwVar12 = pwVar11;
      }
    }
  }
  p_Var3 = param_1[9].Release;
  *(undefined8 *)(puVar10 + -8) = 0x180039fe6;
  FUN_180038480(local_170,(longlong *)p_Var3,pwVar12);
LAB_180039fe9:
  *(undefined8 *)(puVar10 + -8) = 0x180039ff8;
  return iVar4;
}

/* ---- FUNC 0003A020 FUN_18003a020 (429 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HRESULT FUN_18003a020(longlong param_1,undefined8 param_2,OLECHAR **param_3,UINT param_4,
                     undefined8 param_5,DISPID *param_6)

{
  undefined1 *puVar1;
  LPCWSTR lpWideCharStr;
  undefined8 uVar2;
  code *pcVar3;
  HRESULT HVar4;
  int iVar5;
  longlong lVar6;
  ulonglong uVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined8 uStack_80;
  undefined1 auStack_78 [32];
  undefined8 uStack_58;
  int aiStack_50 [2];
  undefined8 local_48 [2];
  HRESULT local_38 [2];
  undefined8 *local_30;
  ulonglong local_28;
  longlong lVar7;
  
  local_28 = DAT_180077818 ^ (ulonglong)local_38;
  uStack_80 = 0x18003a070;
  HVar4 = DispGetIDsOfNames(DAT_180079880,param_3,param_4,param_6);
  puVar11 = (undefined1 *)0x0;
  local_30 = (undefined8 *)0x0;
  puVar9 = auStack_78;
  if ((((HVar4 == -0x7ffdfffa) && (puVar9 = auStack_78, param_4 == 1)) &&
      (puVar9 = auStack_78, *(longlong *)(param_1 + 0x48) != 0)) &&
     (puVar9 = auStack_78, *(int *)(param_1 + 0x160) == 1)) {
    uStack_80 = 0x18003a0b6;
    local_38[0] = HVar4;
    iVar5 = HAIsNamedDimension(*(longlong *)(param_1 + 0x48),0,&local_30);
    if (iVar5 == 0) {
      puVar9 = auStack_78;
      if ((local_30 != (undefined8 *)0x0) && (puVar9 = auStack_78, (code *)*local_30 != (code *)0x0)
         ) {
        uStack_80 = 0x18003a19f;
        (*(code *)*local_30)();
        puVar9 = auStack_78;
      }
    }
    else {
      lpWideCharStr = *param_3;
      puVar9 = auStack_78;
      puVar10 = puVar11;
      if (lpWideCharStr != (LPCWSTR)0x0) {
        lVar6 = -1;
        do {
          lVar7 = lVar6;
          lVar6 = lVar7 + 1;
        } while (lpWideCharStr[lVar6] != L'\0');
        iVar5 = (int)lVar7 + 2;
        puVar9 = auStack_78;
        if (iVar5 < 0x40000000) {
          lVar6 = (longlong)(int)lVar6 * 2;
          uVar8 = lVar6 + 0x11;
          if (uVar8 <= lVar6 + 2U) {
            uVar8 = 0xffffffffffffff0;
          }
          uStack_80 = 0x18003a110;
          lVar6 = -(uVar8 & 0xfffffffffffffff0);
          puVar1 = (undefined1 *)((longlong)local_38 + lVar6);
          puVar9 = auStack_78 + lVar6;
          if (puVar1 != (undefined1 *)0x0) {
            *puVar1 = 0;
            *(undefined8 *)((longlong)local_48 + lVar6 + 8) = 0;
            *(undefined8 *)((longlong)local_48 + lVar6) = 0;
            *(int *)((longlong)aiStack_50 + lVar6) = iVar5 * 2;
            *(undefined1 **)((longlong)&uStack_58 + lVar6) = puVar1;
            *(undefined8 *)(auStack_78 + lVar6 + -8) = 0x18003a144;
            iVar5 = WideCharToMultiByte(0,0,lpWideCharStr,-1,
                                        *(LPSTR *)((longlong)&uStack_58 + lVar6),
                                        *(int *)((longlong)aiStack_50 + lVar6),
                                        *(LPCSTR *)((longlong)local_48 + lVar6),
                                        *(LPBOOL *)((longlong)local_48 + lVar6 + 8));
            puVar9 = auStack_78 + lVar6;
            puVar10 = puVar1;
            if (iVar5 == 0) {
              puVar9 = auStack_78 + lVar6;
              puVar10 = puVar11;
            }
          }
        }
      }
      uVar2 = *(undefined8 *)(param_1 + 0x48);
      *(undefined8 *)(puVar9 + -8) = 0x18003a162;
      iVar5 = HAGetLabelLocation(uVar2,0,puVar10,&local_30);
      if (iVar5 == -1) {
        if ((local_30 != (undefined8 *)0x0) && (pcVar3 = (code *)*local_30, pcVar3 != (code *)0x0))
        {
          *(undefined8 *)(puVar9 + -8) = 0x18003a17a;
          (*pcVar3)();
        }
      }
      else {
        HVar4 = 0;
        *param_6 = iVar5 + 0x60020050;
      }
    }
  }
  *(undefined8 *)(puVar9 + -8) = 0x18003a1b3;
  return HVar4;
}

/* ---- FUNC 0003A1D0 FUN_18003a1d0 (296 bytes) ---- */

char * FUN_18003a1d0(longlong *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  longlong *local_res10;
  longlong *local_res18;
  wchar_t *local_res20;
  char *local_18;
  IBindCtx *local_10;
  
  DAT_1800798a0 = '\0';
  CreateBindCtx(0,&local_10);
  local_res10 = (longlong *)0x0;
  local_res18 = (longlong *)0x0;
  iVar2 = (**(code **)(*param_1 + 0x60))(param_1,0,&local_res18);
  if ((-1 < iVar2) && (local_res18 != (longlong *)0x0)) {
    iVar2 = (**(code **)(*local_res18 + 0x18))(local_res18,1,&local_res10);
    if (-1 < iVar2) {
      (**(code **)(*local_res10 + 0xa0))(local_res10,local_10,0,&local_res20);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_18,
                 local_res20);
      CoTaskMemFree(local_res20);
      pcVar3 = local_18 + 1;
      if (*local_18 != '!') {
        pcVar3 = local_18;
      }
      pcVar4 = &DAT_1800798a0;
      do {
        cVar1 = *pcVar3;
        *pcVar4 = cVar1;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      pcVar3 = &DAT_1800798a0;
      cVar1 = DAT_1800798a0;
      while (cVar1 != '\0') {
        if (cVar1 == '!') {
          *pcVar3 = ' ';
        }
        pcVar3 = pcVar3 + 1;
        cVar1 = *pcVar3;
      }
      (**(code **)(*local_res10 + 0x10))();
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_18);
    }
    (**(code **)(*local_res18 + 0x10))();
  }
  (*local_10->lpVtbl->Release)(local_10);
  return &DAT_1800798a0;
}

/* ---- FUNC 0003A300 FUN_18003a300 (545 bytes) ---- */

longlong * FUN_18003a300(longlong *param_1)

{
  int iVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  byte *local_res8;
  undefined1 local_28 [8];
  int *local_20;
  code *local_18;
  
  if ((param_1[9] == 0) && (iVar1 = (**(code **)(*param_1 + 0x198))(), iVar1 < 0)) {
    return (longlong *)0x0;
  }
  iVar1 = HAWillNotify(param_1[9]);
  if (iVar1 == 0) {
    puVar3 = (undefined8 *)HAGetAttr(param_1[9],0x12,0,local_28);
    if (puVar3 != (undefined8 *)0x0) {
      if ((code *)*puVar3 == (code *)0x0) {
        return (longlong *)0x0;
      }
      (*(code *)*puVar3)(puVar3);
      return (longlong *)0x0;
    }
    iVar1 = *local_20;
    if (local_18 != (code *)0x0) {
      (*local_18)();
    }
    if (iVar1 == 0) {
      return (longlong *)0x0;
    }
    do {
      if ((int)param_1[0xd] != 0) {
        return (longlong *)0x0;
      }
      param_1 = (longlong *)param_1[0xc];
      if (param_1 == (longlong *)0x0) {
        return (longlong *)0x0;
      }
      iVar1 = HAWillNotify(param_1[9]);
    } while (iVar1 == 0);
    iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       (param_1 + 0x3b),"Output");
    if (iVar1 != 0) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8,"..\\"
                );
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8,
                 (CSimpleStringT<char,1> *)(param_1 + 0x3b));
      plVar2 = FUN_180038fc0(param_1,local_res8);
      if (plVar2 != (longlong *)0x0) {
        (**(code **)(*plVar2 + 0x10))(plVar2);
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
      (**(code **)(*param_1 + 8))(param_1);
      return param_1;
    }
  }
  else {
    iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       (param_1 + 0x3b),"Output");
    if (iVar1 != 0) {
      iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         (param_1 + 0x3b),"Stream-Sum");
      if (((iVar1 != 0) &&
          (iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                             ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                              (param_1 + 0x3b),"Heat-Sum"), iVar1 != 0)) &&
         (iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             (param_1 + 0x3b),"Work-Sum"), iVar1 != 0)) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8,
                   "..\\");
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8,
                   (CSimpleStringT<char,1> *)(param_1 + 0x3b));
        plVar2 = FUN_180038fc0(param_1,local_res8);
        if (plVar2 != (longlong *)0x0) {
          (**(code **)(*plVar2 + 0x10))(plVar2);
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
      }
      goto LAB_18003a492;
    }
  }
  param_1 = (longlong *)param_1[0xc];
LAB_18003a492:
  if (param_1 == (longlong *)0x0) {
    return (longlong *)0x0;
  }
  (**(code **)(*param_1 + 8))(param_1);
  return param_1;
}

/* ---- FUNC 0003A530 FUN_18003a530 (187 bytes) ---- */

undefined4 FUN_18003a530(longlong param_1,longlong param_2,longlong param_3)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *local_res18 [2];
  
  if (param_3 == 0) {
    return 0x80070057;
  }
  lVar2 = -1;
  while( true ) {
    if (*(wchar_t *)(param_2 + 2 + lVar2 * 2) != L"HNodeSelection"[lVar2 + 1]) {
      return 0x80004002;
    }
    lVar2 = lVar2 + 2;
    if (lVar2 == 0xf) break;
    if (*(wchar_t *)(param_2 + lVar2 * 2) != L"HNodeSelection"[lVar2]) {
      return 0x80004002;
    }
  }
  plVar3 = FUN_18000f5a0(local_res18);
  if ((int)plVar3 != 0) {
    return 0x80004002;
  }
  FUN_18004faf0((longlong)local_res18[0],*(longlong **)(param_1 + 8));
  uVar1 = (**(code **)*local_res18[0])(local_res18[0],&DAT_1800635d0,param_3);
  return uVar1;
}

/* ---- FUNC 0003A5F0 FUN_18003a5f0 (62 bytes) ---- */

undefined8 FUN_18003a5f0(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  *param_4 = 0;
  if (param_2 != 0) {
    return 0x8002000b;
  }
  (**(code **)(*DAT_180079880 + 8))();
  *param_4 = DAT_180079880;
  return 0;
}

/* ---- FUNC 0003A630 FUN_18003a630 (441 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined8 FUN_18003a630(longlong *param_1,LPCWSTR param_2)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  code *pcVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong *plVar6;
  ulonglong uVar7;
  int iVar8;
  undefined1 *puVar9;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar10;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar11;
  undefined8 uStack_70;
  undefined1 auStack_68 [32];
  undefined8 uStack_48;
  int aiStack_40 [2];
  undefined8 local_38 [2];
  longlong *local_28;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_20 [8];
  ulonglong local_18;
  longlong lVar5;
  
  puVar9 = auStack_68;
  local_18 = DAT_180077818 ^ (ulonglong)&local_28;
  lVar4 = *param_1;
  if (DAT_1800797f8 == 0) {
    if (param_1[9] == 0) {
      uStack_70 = 0x18003a68d;
      uVar3 = (**(code **)(lVar4 + 0x210))(param_1,0x7d9);
    }
    else {
      pCVar10 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
      local_28 = (longlong *)0x0;
      uStack_70 = 0x18003a6a2;
      (**(code **)(lVar4 + 0x110))(param_1,param_2,&local_28);
      puVar9 = auStack_68;
      pCVar11 = pCVar10;
      if (param_2 != (LPCWSTR)0x0) {
        lVar4 = -1;
        do {
          lVar5 = lVar4;
          lVar4 = lVar5 + 1;
        } while (param_2[lVar4] != L'\0');
        iVar8 = (int)lVar5 + 2;
        puVar9 = auStack_68;
        if (iVar8 < 0x40000000) {
          lVar4 = (longlong)(int)lVar4 * 2;
          uVar7 = lVar4 + 0x11;
          if (uVar7 <= lVar4 + 2U) {
            uVar7 = 0xffffffffffffff0;
          }
          uStack_70 = 0x18003a6ef;
          lVar4 = -(uVar7 & 0xfffffffffffffff0);
          pCVar1 = local_20 + lVar4 + -8;
          puVar9 = auStack_68 + lVar4;
          if (pCVar1 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
            *(undefined8 *)((longlong)local_38 + lVar4 + 8) = 0;
            *(undefined8 *)((longlong)local_38 + lVar4) = 0;
            *(int *)((longlong)aiStack_40 + lVar4) = iVar8 * 2;
            *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
             ((longlong)&uStack_48 + lVar4) = pCVar1;
            *pCVar1 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>)0x0;
            *(undefined8 *)(auStack_68 + lVar4 + -8) = 0x18003a728;
            iVar8 = WideCharToMultiByte(0,0,param_2,-1,*(LPSTR *)((longlong)&uStack_48 + lVar4),
                                        *(int *)((longlong)aiStack_40 + lVar4),
                                        *(LPCSTR *)((longlong)local_38 + lVar4),
                                        *(LPBOOL *)((longlong)local_38 + lVar4 + 8));
            puVar9 = auStack_68 + lVar4;
            pCVar11 = pCVar1;
            if (iVar8 == 0) {
              puVar9 = auStack_68 + lVar4;
              pCVar11 = pCVar10;
            }
          }
        }
      }
      lVar4 = param_1[9];
      *(undefined8 *)(puVar9 + -8) = 0x18003a740;
      lVar4 = HAHideReveal(lVar4,0,pCVar11);
      plVar6 = local_28;
      if (lVar4 == 0) {
        if (DAT_180079800 != (longlong *)0x0) {
          pcVar2 = *(code **)(*DAT_180079800 + 0x68);
          *(undefined8 *)(puVar9 + -8) = 0x18003a772;
          (*pcVar2)(DAT_180079800,0x73,plVar6);
        }
        if (DAT_18007988c == 0) {
          *(undefined8 *)(puVar9 + -8) = 0x18003a791;
          plVar6 = (longlong *)
                   ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                   CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_20);
          *(undefined8 *)(puVar9 + -8) = 0x18003a79e;
          FUN_1800374c0(0x66,plVar6);
          *(undefined8 *)(puVar9 + -8) = 0x18003a7a8;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_20);
        }
        else {
          DAT_180079894 = 1;
        }
        if (local_28 != (longlong *)0x0) {
          pcVar2 = *(code **)(*local_28 + 0x10);
          *(undefined8 *)(puVar9 + -8) = 0x18003a7b7;
          (*pcVar2)();
        }
        *(undefined4 *)(param_1[10] + 0x100) = 1;
        uVar3 = 0;
      }
      else {
        pcVar2 = *(code **)(*param_1 + 0x208);
        *(undefined8 *)(puVar9 + -8) = 0x18003a755;
        uVar3 = (*pcVar2)(param_1,lVar4);
      }
    }
  }
  else {
    uStack_70 = 0x18003a676;
    uVar3 = (**(code **)(lVar4 + 0x210))(param_1,0x7f3);
    puVar9 = auStack_68;
  }
  *(undefined8 *)(puVar9 + -8) = 0x18003a7d3;
  return uVar3;
}

/* ---- FUNC 0003A7F0 FUN_18003a7f0 (8 bytes) ---- */

void FUN_18003a7f0(undefined8 param_1,short param_2)

{
  FUN_18003e370(param_2);
  return;
}

/* ---- FUNC 0003A800 FUN_18003a800 (328 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined8 FUN_18003a800(longlong *param_1,LPCWSTR param_2)

{
  undefined1 *puVar1;
  code *pcVar2;
  undefined8 uVar3;
  longlong lVar4;
  ulonglong uVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  int iVar10;
  undefined8 uStack_60;
  undefined1 auStack_58 [32];
  undefined8 uStack_38;
  int aiStack_30 [2];
  undefined8 local_28 [2];
  ulonglong local_18 [2];
  longlong lVar5;
  
  puVar7 = auStack_58;
  local_18[0] = DAT_180077818 ^ (ulonglong)local_18;
  puVar8 = (undefined1 *)0x0;
  if (DAT_1800797f8 == 0) {
    lVar4 = param_1[9];
    if (lVar4 == 0) {
      uStack_60 = 0x18003a85f;
      uVar3 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
      puVar7 = auStack_58;
    }
    else {
      puVar9 = puVar8;
      if (param_2 != (LPCWSTR)0x0) {
        lVar4 = -1;
        do {
          lVar5 = lVar4;
          lVar4 = lVar5 + 1;
        } while (param_2[lVar4] != L'\0');
        iVar10 = (int)lVar5 + 2;
        puVar7 = auStack_58;
        if (iVar10 < 0x40000000) {
          lVar4 = (longlong)(int)lVar4 * 2;
          uVar6 = lVar4 + 0x11;
          if (uVar6 <= lVar4 + 2U) {
            uVar6 = 0xffffffffffffff0;
          }
          uStack_60 = 0x18003a8b3;
          lVar4 = -(uVar6 & 0xfffffffffffffff0);
          puVar1 = (undefined1 *)((longlong)local_18 + lVar4);
          puVar7 = auStack_58 + lVar4;
          if (puVar1 != (undefined1 *)0x0) {
            *(undefined8 *)((longlong)local_28 + lVar4 + 8) = 0;
            *(undefined8 *)((longlong)local_28 + lVar4) = 0;
            *(int *)((longlong)aiStack_30 + lVar4) = iVar10 * 2;
            *(undefined1 **)((longlong)&uStack_38 + lVar4) = puVar1;
            *puVar1 = 0;
            *(undefined8 *)(auStack_58 + lVar4 + -8) = 0x18003a8ed;
            iVar10 = WideCharToMultiByte(0,0,param_2,-1,*(LPSTR *)((longlong)&uStack_38 + lVar4),
                                         *(int *)((longlong)aiStack_30 + lVar4),
                                         *(LPCSTR *)((longlong)local_28 + lVar4),
                                         *(LPBOOL *)((longlong)local_28 + lVar4 + 8));
            puVar7 = auStack_58 + lVar4;
            puVar9 = puVar1;
            if (iVar10 == 0) {
              puVar7 = auStack_58 + lVar4;
              puVar9 = puVar8;
            }
          }
        }
        lVar4 = param_1[9];
      }
      *(undefined8 *)(puVar7 + -8) = 0x18003a903;
      lVar4 = HAImport(lVar4,puVar9);
      if (lVar4 == 0) {
        *(undefined4 *)(param_1[10] + 0x100) = 1;
        uVar3 = 0;
      }
      else {
        pcVar2 = *(code **)(*param_1 + 0x208);
        *(undefined8 *)(puVar7 + -8) = 0x18003a918;
        uVar3 = (*pcVar2)(param_1,lVar4);
      }
    }
  }
  else {
    uStack_60 = 0x18003a840;
    uVar3 = (**(code **)(*param_1 + 0x210))(param_1,0x7f3);
    puVar7 = auStack_58;
  }
  *(undefined8 *)(puVar7 + -8) = 0x18003a936;
  return uVar3;
}

/* ---- FUNC 0003A950 FUN_18003a950 (196 bytes) ---- */

HRESULT FUN_18003a950(longlong *param_1,int param_2,longlong *param_3,undefined8 param_4,
                     ushort param_5,DISPPARAMS *param_6,VARIANT *param_7,EXCEPINFO *param_8,
                     UINT *param_9)

{
  longlong lVar1;
  BSTR pOVar2;
  PVOID pvVar3;
  HRESULT HVar4;
  
  *(undefined4 *)(param_1 + 0x1c) = 0;
  if (param_2 < 0x60020050) {
    HVar4 = DispInvoke(param_1,DAT_180079880,param_2,param_5,param_6,param_7,param_8,param_9);
    if (HVar4 == -0x7ffdfffd) {
      HVar4 = DispInvoke(param_1 + 0x3e,(ITypeInfo *)param_1[0x40],param_2,param_5,param_6,param_7,
                         param_8,param_9);
    }
  }
  else {
    if ((*param_3 != DAT_180066d68) || (param_3[1] != DAT_180066d70)) {
      return -0x7ffdffff;
    }
    if ((param_5 & 3) == 0) {
      return -0x7ffdfffd;
    }
    if (param_7 == (VARIANT *)0x0) {
      return -0x7ff8ffa9;
    }
    if (param_6->cArgs != 0) {
      return -0x7ffdfff2;
    }
    HVar4 = (**(code **)(*param_1 + 0x218))(param_1,param_2 + -0x60020050);
  }
  if ((int)param_1[0x1c] != 0) {
    if (param_8 != (EXCEPINFO *)0x0) {
      lVar1 = param_1[0x14];
      pOVar2 = (BSTR)param_1[0x15];
      param_8->wCode = (short)lVar1;
      param_8->wReserved = (short)((ulonglong)lVar1 >> 0x10);
      *(int *)&param_8->field_0x4 = (int)((ulonglong)lVar1 >> 0x20);
      param_8->bstrSource = pOVar2;
      pOVar2 = (BSTR)param_1[0x17];
      param_8->bstrDescription = (BSTR)param_1[0x16];
      param_8->bstrHelpFile = pOVar2;
      pvVar3 = (PVOID)param_1[0x19];
      *(longlong *)&param_8->dwHelpContext = param_1[0x18];
      param_8->pvReserved = pvVar3;
      lVar1 = param_1[0x1b];
      param_8->pfnDeferredFillIn = (_func_6477 *)param_1[0x1a];
      *(longlong *)&param_8->scode = lVar1;
      param_1[0x14] = 0;
      param_1[0x15] = 0;
      param_1[0x16] = 0;
      param_1[0x17] = 0;
      param_1[0x18] = 0;
      param_1[0x19] = 0;
      param_1[0x1a] = 0;
      param_1[0x1b] = 0;
    }
    HVar4 = -0x7ffdfff7;
  }
  return HVar4;
}

/* ---- FUNC 0003AA14 FUN_18003aa14 (139 bytes) ---- */

HRESULT FUN_18003aa14(void *param_1,ITypeInfo *param_2,DISPID param_3,WORD param_4)

{
  undefined8 uVar1;
  BSTR pOVar2;
  PVOID pvVar3;
  HRESULT HVar4;
  longlong unaff_RBX;
  DISPID unaff_ESI;
  EXCEPINFO *unaff_RDI;
  WORD in_stack_00000080;
  DISPPARAMS *in_stack_00000088;
  VARIANT *in_stack_00000090;
  UINT *in_stack_000000a0;
  
  HVar4 = DispInvoke(param_1,param_2,param_3,param_4,in_stack_00000088,in_stack_00000090,unaff_RDI,
                     in_stack_000000a0);
  if (HVar4 == -0x7ffdfffd) {
    HVar4 = DispInvoke((void *)(unaff_RBX + 0x1f0),*(ITypeInfo **)(unaff_RBX + 0x200),unaff_ESI,
                       in_stack_00000080,in_stack_00000088,in_stack_00000090,unaff_RDI,
                       in_stack_000000a0);
  }
  if (*(int *)(unaff_RBX + 0xe0) != 0) {
    if (unaff_RDI != (EXCEPINFO *)0x0) {
      uVar1 = *(undefined8 *)(unaff_RBX + 0xa0);
      pOVar2 = *(BSTR *)(unaff_RBX + 0xa8);
      unaff_RDI->wCode = (short)uVar1;
      unaff_RDI->wReserved = (short)((ulonglong)uVar1 >> 0x10);
      *(int *)&unaff_RDI->field_0x4 = (int)((ulonglong)uVar1 >> 0x20);
      unaff_RDI->bstrSource = pOVar2;
      pOVar2 = *(BSTR *)(unaff_RBX + 0xb8);
      unaff_RDI->bstrDescription = *(BSTR *)(unaff_RBX + 0xb0);
      unaff_RDI->bstrHelpFile = pOVar2;
      pvVar3 = *(PVOID *)(unaff_RBX + 200);
      *(undefined8 *)&unaff_RDI->dwHelpContext = *(undefined8 *)(unaff_RBX + 0xc0);
      unaff_RDI->pvReserved = pvVar3;
      uVar1 = *(undefined8 *)(unaff_RBX + 0xd8);
      unaff_RDI->pfnDeferredFillIn = *(_func_6477 **)(unaff_RBX + 0xd0);
      *(undefined8 *)&unaff_RDI->scode = uVar1;
      *(undefined8 *)(unaff_RBX + 0xa0) = 0;
      *(undefined8 *)(unaff_RBX + 0xa8) = 0;
      *(undefined8 *)(unaff_RBX + 0xb0) = 0;
      *(undefined8 *)(unaff_RBX + 0xb8) = 0;
      *(undefined8 *)(unaff_RBX + 0xc0) = 0;
      *(undefined8 *)(unaff_RBX + 200) = 0;
      *(undefined8 *)(unaff_RBX + 0xd0) = 0;
      *(undefined8 *)(unaff_RBX + 0xd8) = 0;
    }
    HVar4 = -0x7ffdfff7;
  }
  return HVar4;
}

/* ---- FUNC 0003AA9F FUN_18003aa9f (101 bytes) ---- */

void FUN_18003aa9f(void)

{
  undefined8 uVar1;
  longlong unaff_RBX;
  undefined8 *unaff_RDI;
  
  if ((*(int *)(unaff_RBX + 0xe0) != 0) && (unaff_RDI != (undefined8 *)0x0)) {
    uVar1 = *(undefined8 *)(unaff_RBX + 0xa8);
    *unaff_RDI = *(undefined8 *)(unaff_RBX + 0xa0);
    unaff_RDI[1] = uVar1;
    uVar1 = *(undefined8 *)(unaff_RBX + 0xb8);
    unaff_RDI[2] = *(undefined8 *)(unaff_RBX + 0xb0);
    unaff_RDI[3] = uVar1;
    uVar1 = *(undefined8 *)(unaff_RBX + 200);
    unaff_RDI[4] = *(undefined8 *)(unaff_RBX + 0xc0);
    unaff_RDI[5] = uVar1;
    uVar1 = *(undefined8 *)(unaff_RBX + 0xd8);
    unaff_RDI[6] = *(undefined8 *)(unaff_RBX + 0xd0);
    unaff_RDI[7] = uVar1;
    *(undefined8 *)(unaff_RBX + 0xa0) = 0;
    *(undefined8 *)(unaff_RBX + 0xa8) = 0;
    *(undefined8 *)(unaff_RBX + 0xb0) = 0;
    *(undefined8 *)(unaff_RBX + 0xb8) = 0;
    *(undefined8 *)(unaff_RBX + 0xc0) = 0;
    *(undefined8 *)(unaff_RBX + 200) = 0;
    *(undefined8 *)(unaff_RBX + 0xd0) = 0;
    *(undefined8 *)(unaff_RBX + 0xd8) = 0;
  }
  return;
}

/* ---- FUNC 0003AB10 FUN_18003ab10 (172 bytes) ---- */

HRESULT FUN_18003ab10(void *param_1,DISPID param_2,undefined8 param_3,undefined8 param_4,
                     WORD param_5,DISPPARAMS *param_6,VARIANT *param_7,EXCEPINFO *param_8,
                     UINT *param_9)

{
  longlong lVar1;
  undefined8 uVar2;
  BSTR pOVar3;
  PVOID pvVar4;
  HRESULT HVar5;
  
  *(undefined4 *)(*(longlong *)((longlong)param_1 + 8) + 0xe0) = 0;
  HVar5 = DispInvoke(param_1,*(ITypeInfo **)((longlong)param_1 + 0x10),param_2,param_5,param_6,
                     param_7,param_8,param_9);
  lVar1 = *(longlong *)((longlong)param_1 + 8);
  if (*(int *)(lVar1 + 0xe0) != 0) {
    if (param_8 != (EXCEPINFO *)0x0) {
      uVar2 = *(undefined8 *)(lVar1 + 0xa0);
      pOVar3 = *(BSTR *)(lVar1 + 0xa8);
      param_8->wCode = (short)uVar2;
      param_8->wReserved = (short)((ulonglong)uVar2 >> 0x10);
      *(int *)&param_8->field_0x4 = (int)((ulonglong)uVar2 >> 0x20);
      param_8->bstrSource = pOVar3;
      pOVar3 = *(BSTR *)(lVar1 + 0xb8);
      param_8->bstrDescription = *(BSTR *)(lVar1 + 0xb0);
      param_8->bstrHelpFile = pOVar3;
      pvVar4 = *(PVOID *)(lVar1 + 200);
      *(undefined8 *)&param_8->dwHelpContext = *(undefined8 *)(lVar1 + 0xc0);
      param_8->pvReserved = pvVar4;
      uVar2 = *(undefined8 *)(lVar1 + 0xd8);
      param_8->pfnDeferredFillIn = *(_func_6477 **)(lVar1 + 0xd0);
      *(undefined8 *)&param_8->scode = uVar2;
    }
    HVar5 = -0x7ffdfff7;
  }
  return HVar5;
}

/* ---- FUNC 0003ABC0 FUN_18003abc0 (326 bytes) ---- */

undefined8 FUN_18003abc0(longlong param_1,undefined4 param_2,ushort *param_3)

{
  int iVar1;
  longlong lVar2;
  char *pcVar3;
  ushort uVar4;
  ushort uVar5;
  
  uVar4 = 0;
  uVar5 = 0;
  *param_3 = 0;
  switch(param_2) {
  case 0:
    iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       (param_1 + 0x1d8),"Analysis");
    if (((iVar1 != 0) || (*(int *)(param_1 + 0x68) != 0)) ||
       (lVar2 = *(longlong *)(param_1 + 0x60), lVar2 == 0)) break;
    pcVar3 = "Properties";
    goto LAB_18003acdb;
  case 1:
    pcVar3 = "Pure Components";
    goto LAB_18003ac3f;
  case 2:
    pcVar3 = "UNIFAC Groups";
LAB_18003ac3f:
    iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       (param_1 + 0x1d8),pcVar3);
    if (((iVar1 == 0) && (*(int *)(param_1 + 0x68) == 0)) &&
       (lVar2 = *(longlong *)(param_1 + 0x60), lVar2 != 0)) {
      pcVar3 = "Parameters";
LAB_18003acdb:
      iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         (lVar2 + 0x1d8),pcVar3);
      uVar5 = uVar4;
      if (iVar1 == 0) {
        uVar5 = 1;
      }
    }
    break;
  case 3:
    iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       (param_1 + 0x1d8),"Subs-Attr");
    if (((iVar1 == 0) && (*(int *)(param_1 + 0x68) == 0)) &&
       (lVar2 = *(longlong *)(param_1 + 0x60), lVar2 != 0)) {
      pcVar3 = "Stream-Class";
      goto LAB_18003acdb;
    }
    break;
  case 4:
    iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       (param_1 + 0x1d8),"Subobjects");
    uVar5 = (ushort)(iVar1 == 0);
    break;
  case 5:
    uVar5 = uVar4;
    if ((*(int *)(param_1 + 0x68) == 0) && (lVar2 = *(longlong *)(param_1 + 0x60), lVar2 != 0)) {
      pcVar3 = "Streams";
      goto LAB_18003acdb;
    }
    break;
  default:
    goto switchD_18003abf8_default;
  }
  *param_3 = uVar5;
switchD_18003abf8_default:
  return 0;
}

/* ---- FUNC 0003AD20 FUN_18003ad20 (16 bytes) ---- */

undefined8 FUN_18003ad20(longlong param_1,short *param_2)

{
  *param_2 = -(ushort)(*(longlong *)(param_1 + 0x48) != 0);
  return 0;
}

/* ---- FUNC 0003AD30 FUN_18003ad30 (870 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined8 FUN_18003ad30(longlong *param_1)

{
  char *pcVar1;
  char cVar2;
  void *pvVar3;
  int iVar4;
  UINT UVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong lVar9;
  char *pcVar10;
  ulonglong uVar11;
  _union_2707 *pvarSrc;
  char *pcVar12;
  undefined1 *puVar13;
  size_t _Count;
  size_t sVar14;
  undefined8 uStack_1b0;
  undefined1 auStack_1a8 [32];
  undefined8 uStack_188;
  int aiStack_180 [2];
  undefined8 local_178 [2];
  char local_168 [8];
  _union_2707 *local_160;
  code *local_158;
  undefined8 *local_150;
  _union_2707 local_148;
  char local_128 [256];
  ulonglong local_28;
  longlong lVar8;
  
  local_28 = DAT_180077818 ^ (ulonglong)local_168;
  pcVar10 = (char *)0x0;
  local_150 = (undefined8 *)0x0;
  puVar13 = auStack_1a8;
  if ((DAT_1800797f8 == 0) && (puVar13 = auStack_1a8, param_1[9] != 0)) {
    uStack_1b0 = 0x18003ad91;
    iVar4 = HAGetAttrType(param_1[9],0,0,&local_150);
    if (iVar4 == -999) {
      lVar7 = *param_1;
      if (local_150 == (undefined8 *)0x0) {
        uStack_1b0 = 0x18003adb5;
        uVar6 = (**(code **)(lVar7 + 0x210))(param_1,0x7d1);
        puVar13 = auStack_1a8;
        goto LAB_18003ae49;
      }
    }
    else {
      uStack_1b0 = 0x18003adcd;
      local_150 = (undefined8 *)HAGetAttr(param_1[9],0,0,local_168);
      if (local_150 == (undefined8 *)0x0) {
        _Count = 0xffffffffffffffff;
        if (iVar4 == -6) {
          local_128[0] = '\0';
          local_148._0_8_ = 0;
          local_148.decVal.u2.Lo64 = (_union_1719)0x0;
          local_148._16_8_ = 0;
          uStack_1b0 = 0x18003af22;
          VariantInit((VARIANTARG *)&local_148.n2);
          pvarSrc = &local_148;
          if (local_160 != (_union_2707 *)0x0) {
            pvarSrc = local_160;
          }
          uStack_1b0 = 0x18003af44;
          VariantChangeType((VARIANTARG *)&local_148.n2,(VARIANTARG *)&pvarSrc->n2,0,8);
          puVar13 = auStack_1a8;
          if (local_148.n2.vt == 8) {
            uStack_1b0 = 0x18003af59;
            UVar5 = SysStringLen((BSTR)local_148.decVal.u2);
            uVar6 = local_148.decVal.u2;
            puVar13 = auStack_1a8;
            if (UVar5 != 0) {
              pcVar12 = pcVar10;
              puVar13 = auStack_1a8;
              if (local_148.decVal.u2.Lo64 != 0) {
                lVar7 = -1;
                do {
                  lVar8 = lVar7;
                  lVar7 = lVar8 + 1;
                } while (*(LPCWSTR)((longlong)local_148.decVal.u2 + lVar7 * 2) != L'\0');
                iVar4 = (int)lVar8 + 2;
                puVar13 = auStack_1a8;
                if (iVar4 < 0x40000000) {
                  lVar7 = (longlong)(int)lVar7 * 2;
                  uVar11 = lVar7 + 0x11;
                  if (uVar11 <= lVar7 + 2U) {
                    uVar11 = 0xffffffffffffff0;
                  }
                  uStack_1b0 = 0x18003afaf;
                  lVar7 = -(uVar11 & 0xfffffffffffffff0);
                  pcVar1 = local_168 + lVar7;
                  puVar13 = auStack_1a8 + lVar7;
                  if (pcVar1 != (char *)0x0) {
                    *(undefined8 *)((longlong)local_178 + lVar7 + 8) = 0;
                    *(undefined8 *)((longlong)local_178 + lVar7) = 0;
                    *(int *)((longlong)aiStack_180 + lVar7) = iVar4 * 2;
                    *(char **)((longlong)&uStack_188 + lVar7) = pcVar1;
                    *pcVar1 = '\0';
                    *(undefined8 *)(auStack_1a8 + lVar7 + -8) = 0x18003afe2;
                    iVar4 = WideCharToMultiByte(0,0,(LPCWSTR)uVar6,-1,
                                                *(LPSTR *)((longlong)&uStack_188 + lVar7),
                                                *(int *)((longlong)aiStack_180 + lVar7),
                                                *(LPCSTR *)((longlong)local_178 + lVar7),
                                                *(LPBOOL *)((longlong)local_178 + lVar7 + 8));
                    pcVar12 = pcVar1;
                    puVar13 = auStack_1a8 + lVar7;
                    if (iVar4 == 0) {
                      pcVar12 = pcVar10;
                      puVar13 = auStack_1a8 + lVar7;
                    }
                  }
                }
              }
              lVar7 = -(longlong)pcVar12;
              do {
                cVar2 = *pcVar12;
                pcVar12[(longlong)(local_128 + lVar7)] = cVar2;
                pcVar12 = pcVar12 + 1;
              } while (cVar2 != '\0');
            }
          }
          *(undefined8 *)(puVar13 + -8) = 0x18003b00a;
          VariantClear((VARIANTARG *)&local_148.n2);
          if (local_158 != (code *)0x0) {
            *(undefined8 *)(puVar13 + -8) = 0x18003b019;
            (*local_158)(local_160);
          }
          lVar7 = -1;
          do {
            lVar9 = lVar7 + 1;
            lVar8 = lVar7 + 1;
            lVar7 = lVar9;
          } while (local_128[lVar8] != '\0');
          if (lVar9 == 0) goto LAB_18003ae47;
        }
        else if (iVar4 == -3) {
          if (local_160 != (_union_2707 *)0x0) {
            pcVar10 = (char *)0xffffffffffffffff;
            do {
              pcVar10 = pcVar10 + 1;
            } while (pcVar10[(longlong)local_160] != '\0');
            puVar13 = auStack_1a8;
            if ((char *)0xff < pcVar10) goto LAB_18003ae47;
            uStack_1b0 = 0x18003aeeb;
            strncpy(local_128,(char *)local_160,(size_t)pcVar10);
          }
          local_128[(longlong)pcVar10] = '\0';
          puVar13 = auStack_1a8;
          if (local_158 != (code *)0x0) {
            uStack_1b0 = 0x18003af03;
            (*local_158)(local_160);
            puVar13 = auStack_1a8;
          }
        }
        else {
          if (iVar4 == -2) {
            uStack_1b0 = 0x18003aeb7;
            _gcvt(*(double *)&(local_160->n2).vt,0xd,local_128);
          }
          else {
            if (iVar4 != -1) {
              puVar13 = auStack_1a8;
              if (local_158 != (code *)0x0) {
                uStack_1b0 = 0x18003ae47;
                (*local_158)(local_160);
                puVar13 = auStack_1a8;
              }
              goto LAB_18003ae47;
            }
            uStack_1b0 = 0x18003ae88;
            _itoa(*(int *)&(local_160->n2).vt,local_128,10);
          }
          puVar13 = auStack_1a8;
          if (local_158 != (code *)0x0) {
            uStack_1b0 = 0x18003ae9b;
            (*local_158)(local_160);
            puVar13 = auStack_1a8;
          }
        }
        do {
          sVar14 = _Count;
          _Count = sVar14 + 1;
        } while (local_128[sVar14 + 1] != '\0');
        pvVar3 = (void *)param_1[0x2a];
        if (pvVar3 != (void *)0x0) {
          *(undefined8 *)(puVar13 + -8) = 0x18003b055;
          FUN_180025ad0(pvVar3);
        }
        *(undefined8 *)(puVar13 + -8) = 0x18003b05e;
        pcVar10 = operator_new__(sVar14 + 2);
        param_1[0x2a] = (longlong)pcVar10;
        *(undefined8 *)(puVar13 + -8) = 0x18003b075;
        strncpy(pcVar10,local_128,_Count);
        *(undefined1 *)(_Count + param_1[0x2a]) = 0;
        *(int *)(param_1 + 0x2b) = (int)_Count * 300;
        uVar6 = 1;
        goto LAB_18003ae49;
      }
      if (*(short *)(local_150 + 1) == 0) {
        if ((code *)*local_150 != (code *)0x0) {
          uStack_1b0 = 0x18003adec;
          (*(code *)*local_150)(local_150);
        }
        param_1[0x2a] = 0;
        uVar6 = 1;
        *(undefined4 *)(param_1 + 0x2b) = 5;
        puVar13 = auStack_1a8;
        goto LAB_18003ae49;
      }
      lVar7 = *param_1;
    }
    uStack_1b0 = 0x18003ae10;
    uVar6 = (**(code **)(lVar7 + 0x208))(param_1);
    puVar13 = auStack_1a8;
  }
  else {
LAB_18003ae47:
    uVar6 = 0;
  }
LAB_18003ae49:
  *(undefined8 *)(puVar13 + -8) = 0x18003ae58;
  return uVar6;
}

/* ---- FUNC 0003B0A0 FUN_18003b0a0 (299 bytes) ---- */

int FUN_18003b0a0(longlong *param_1,int param_2)

{
  IUnknown *pIVar1;
  undefined8 *puVar2;
  int iVar3;
  int iVar4;
  longlong *local_res20;
  
  iVar4 = *(int *)((longlong)param_1 + 0xc);
  if (param_2 == 0) {
    if (iVar4 == 0) {
      return 0;
    }
    iVar4 = iVar4 + -1;
    *(int *)((longlong)param_1 + 0xc) = iVar4;
    if ((iVar4 == 0) && (pIVar1 = (IUnknown *)param_1[0xc], pIVar1 != (IUnknown *)0x0)) {
      if ((int)param_1[0xd] != 0) {
        FUN_180018e30(pIVar1,0,1);
        (**(code **)(*param_1 + 0x10))(param_1);
        return 0;
      }
      FUN_18003b0a0((longlong *)pIVar1,0);
    }
    (**(code **)(*param_1 + 0x10))(param_1);
  }
  else {
    iVar4 = iVar4 + 1;
    *(int *)((longlong)param_1 + 0xc) = iVar4;
    (**(code **)(*param_1 + 8))();
    if ((iVar4 == 1) && (pIVar1 = (IUnknown *)param_1[0xc], pIVar1 != (IUnknown *)0x0)) {
      if ((int)param_1[0xd] == 0) {
        FUN_18003b0a0((longlong *)pIVar1,1);
      }
      else {
        FUN_180018e30(pIVar1,1,1);
      }
    }
    if (((int)param_1[0x3a] == 0) &&
       (puVar2 = (undefined8 *)param_1[0xc], puVar2 != (undefined8 *)0x0)) {
      iVar3 = (**(code **)*puVar2)(puVar2,&DAT_180066db8,&local_res20);
      if (-1 < iVar3) {
        (**(code **)(*local_res20 + 0x98))(local_res20,param_1[0x39],param_1 + 0x3a);
        (**(code **)(*local_res20 + 0x10))();
        return iVar4;
      }
    }
  }
  return iVar4;
}

/* ---- FUNC 0003B1D0 FUN_18003b1d0 (104 bytes) ---- */

bool FUN_18003b1d0(char *param_1,int param_2,undefined2 param_3,undefined2 param_4)

{
  int iVar1;
  char *pcVar2;
  char *local_18 [2];
  
  pcVar2 = (char *)MMGetLocalizedPrompt(param_3,param_4);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_18,pcVar2);
  iVar1 = *(int *)(local_18[0] + -0x10);
  if (iVar1 != 0) {
    strncpy(param_1,local_18[0],(longlong)param_2);
    param_1[(longlong)param_2 - 1] = '\0';
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_18);
  return iVar1 != 0;
}

/* ---- FUNC 0003B240 FUN_18003b240 (177 bytes) ---- */

undefined8 FUN_18003b240(longlong *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018003b25f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x210))(param_1,0x7f3);
    return uVar1;
  }
  if (param_1[9] == 0) {
                    /* WARNING: Could not recover jumptable at 0x00018003b27a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
    return uVar1;
  }
  if ((DAT_180079800 != (longlong *)0x0) && (param_1[0xc] != 0)) {
    (**(code **)(*DAT_180079800 + 0xb0))(DAT_180079800,param_1,param_2);
  }
  *(undefined4 *)(param_1[10] + 0x100) = 1;
  if (DAT_18007988c != 0) {
    DAT_180079890 = 1;
    return 0;
  }
  FUN_1800374c0(0x67,param_1 + 0x3b);
  FUN_180011410(param_1[10],param_1);
  return 0;
}

/* ---- FUNC 0003B300 FUN_18003b300 (121 bytes) ---- */

undefined8 FUN_18003b300(longlong *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018003b31f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x210))(param_1,0x7f3);
    return uVar1;
  }
  if (param_1[9] == 0) {
                    /* WARNING: Could not recover jumptable at 0x00018003b33a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
    return uVar1;
  }
  if ((DAT_180079800 != (longlong *)0x0) && (param_1[0xc] != 0)) {
    (**(code **)(*DAT_180079800 + 200))(DAT_180079800,param_1,param_2);
  }
  *(undefined4 *)(param_1[10] + 0x100) = 1;
  return 0;
}

/* ---- FUNC 0003B380 FUN_18003b380 (285 bytes) ---- */

undefined8 FUN_18003b380(longlong *param_1,VARIANTARG *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  BSTR pOVar3;
  int local_28 [2];
  LPCSTR local_20;
  code *local_18;
  
  if (DAT_1800797f8 != 0) {
    uVar1 = (**(code **)(*param_1 + 0x210))(param_1,0x7f3);
    return uVar1;
  }
  *param_3 = 0;
  if (param_1[9] == 0) {
    uVar1 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
    return uVar1;
  }
  VariantClear(param_2);
  (param_2->n1).n2.vt = 3;
  *(undefined4 *)((longlong)&param_2->n1 + 8) = 0;
  lVar2 = HANext(param_1[9],local_28);
  if (lVar2 != 0) {
    uVar1 = (**(code **)(*param_1 + 0x208))(param_1,lVar2);
    return uVar1;
  }
  if (local_20 != (LPCSTR)0x0) {
    if (local_28[0] == -1) {
      *(undefined4 *)((longlong)&param_2->n1 + 8) = *(undefined4 *)local_20;
      pOVar3 = FUN_1800019d0("");
      *param_3 = pOVar3;
      return 0;
    }
    *(undefined4 *)((longlong)&param_2->n1 + 8) = 1;
    pOVar3 = FUN_1800019d0(local_20);
    *param_3 = pOVar3;
    if (local_18 != (code *)0x0) {
      (*local_18)(local_20);
    }
  }
  return 0;
}

/* ---- FUNC 0003B4A0 FUN_18003b4a0 (84 bytes) ---- */

void FUN_18003b4a0(longlong *param_1)

{
  longlong lVar1;
  
  if (param_1[9] == 0) {
                    /* WARNING: Could not recover jumptable at 0x00018003b4c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
    return;
  }
  lVar1 = HAOnNotify(param_1[9],0xb);
  if (lVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018003b4e7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x208))(param_1,lVar1);
    return;
  }
  return;
}

/* ---- FUNC 0003B500 FUN_18003b500 (99 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18003b500(void)

{
  undefined1 auStack_428 [32];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_180077818 ^ (ulonglong)auStack_428;
  FUN_180002a20(local_408,"Assert failed in file %s line %d",
                "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnode.cpp",0x1613);
  LogMessage(local_408,2,1);
  return;
}

/* ---- FUNC 0003B570 FUN_18003b570 (56 bytes) ---- */

void FUN_18003b570(LPUNKNOWN param_1)

{
  FUN_180038690(param_1,1);
  param_1[9].lpVtbl = (IUnknownVtbl *)0x0;
  if (*(int *)&param_1[0xd].lpVtbl == 0) {
    FUN_18003e8c0((longlong)param_1[0xc].lpVtbl,(ulonglong)param_1);
    return;
  }
  return;
}

/* ---- FUNC 0003B5B0 FUN_18003b5b0 (351 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void FUN_18003b5b0(longlong param_1)

{
  wchar_t *pwVar1;
  longlong lVar2;
  longlong *plVar3;
  char *lpMultiByteStr;
  undefined8 *puVar4;
  longlong lVar5;
  ulonglong uVar7;
  int iVar8;
  undefined1 *puVar9;
  wchar_t *pwVar10;
  wchar_t *pwVar11;
  undefined8 uStack_60;
  undefined1 auStack_58 [32];
  undefined8 uStack_38;
  int aiStack_30 [2];
  wchar_t local_28 [4];
  char *local_20;
  code *local_18;
  ulonglong local_10;
  longlong lVar6;
  
  local_10 = DAT_180077818 ^ (ulonglong)local_28;
  uStack_60 = 0x18003b5f1;
  puVar4 = (undefined8 *)HAGetAttr(*(undefined8 *)(param_1 + 0x48),0x18,0,local_28);
  if (puVar4 == (undefined8 *)0x0) {
    if (*(longlong **)(param_1 + 0xe8) != (longlong *)0x0) {
      uStack_60 = 0x18003b61e;
      (**(code **)(**(longlong **)(param_1 + 0xe8) + 0x10))();
    }
    pwVar10 = (wchar_t *)0x0;
    *(undefined8 *)(param_1 + 0xe8) = 0;
    uStack_60 = 0x18003b638;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x1d8),
               local_20);
    lpMultiByteStr = local_20;
    lVar2 = *(longlong *)(param_1 + 0x60);
    puVar9 = auStack_58;
    pwVar11 = pwVar10;
    if (local_20 != (LPCSTR)0x0) {
      lVar5 = -1;
      do {
        lVar6 = lVar5;
        lVar5 = lVar6 + 1;
      } while (local_20[lVar5] != '\0');
      iVar8 = (int)lVar6 + 2;
      puVar9 = auStack_58;
      if (iVar8 < 0x40000000) {
        lVar5 = (longlong)(int)lVar5 * 2;
        uVar7 = lVar5 + 0x11;
        if (uVar7 <= lVar5 + 2U) {
          uVar7 = 0xffffffffffffff0;
        }
        uStack_60 = 0x18003b68d;
        lVar5 = -(uVar7 & 0xfffffffffffffff0);
        pwVar1 = (wchar_t *)((longlong)local_28 + lVar5);
        puVar9 = auStack_58 + lVar5;
        if (pwVar1 != (wchar_t *)0x0) {
          *(int *)((longlong)aiStack_30 + lVar5) = iVar8;
          *pwVar1 = L'\0';
          *(wchar_t **)((longlong)&uStack_38 + lVar5) = pwVar1;
          *(undefined8 *)(auStack_58 + lVar5 + -8) = 0x18003b6b4;
          iVar8 = MultiByteToWideChar(0,0,lpMultiByteStr,-1,
                                      *(LPWSTR *)((longlong)&uStack_38 + lVar5),
                                      *(int *)((longlong)aiStack_30 + lVar5));
          puVar9 = auStack_58 + lVar5;
          pwVar11 = pwVar1;
          if (iVar8 == 0) {
            puVar9 = auStack_58 + lVar5;
            pwVar11 = pwVar10;
          }
        }
      }
    }
    plVar3 = *(longlong **)(lVar2 + 0xe8);
    *(undefined8 *)(puVar9 + -8) = 0x18003b6cf;
    FUN_180038480(param_1,plVar3,pwVar11);
    if (local_18 != (code *)0x0) {
      *(undefined8 *)(puVar9 + -8) = 0x18003b6de;
      (*local_18)(local_20);
    }
    plVar3 = *(longlong **)(param_1 + 0xe8);
    *(undefined8 *)(puVar9 + -8) = 0x18003b6ed;
    FUN_18003ca80(param_1,plVar3);
  }
  else {
    puVar9 = auStack_58;
    if ((code *)*puVar4 != (code *)0x0) {
      uStack_60 = 0x18003b607;
      (*(code *)*puVar4)(puVar4);
      puVar9 = auStack_58;
    }
  }
  *(undefined8 *)(puVar9 + -8) = 0x18003b6f9;
  return;
}

/* ---- FUNC 0003B710 FUN_18003b710 (67 bytes) ---- */

void FUN_18003b710(longlong *param_1)

{
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018003b724. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x210))(param_1,0x7f3);
    return;
  }
  if (DAT_180079800 == (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00018003b742. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x210))(param_1,0x7d1);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00018003b74c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_180079800 + 0x100))();
  return;
}

/* ---- FUNC 0003B760 FUN_18003b760 (67 bytes) ---- */

void FUN_18003b760(longlong *param_1)

{
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018003b771. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x210))(param_1,0x7f3);
    return;
  }
  if (DAT_180079800 == (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00018003b78c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x210))(param_1,0x7d1);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00018003b79c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_180079800 + 0xf8))(DAT_180079800,param_1);
  return;
}

/* ---- FUNC 0003B7B0 FUN_18003b7b0 (200 bytes) ---- */

ulonglong FUN_18003b7b0(longlong *param_1,short param_2,wchar_t *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  char *pcVar3;
  longlong lVar4;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res20 [8];
  
  if (DAT_1800797f8 != 0) {
    uVar2 = (**(code **)(*param_1 + 0x210))(param_1,0x7f3);
    return uVar2;
  }
  if (param_1[9] == 0) {
    uVar2 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
    return uVar2;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20,param_3);
  pcVar3 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)local_res20,0);
  lVar4 = HACCPrintUse(param_1[9],(int)param_2,pcVar3);
  if (lVar4 == 0) {
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)local_res20,-1);
    uVar2 = 0;
  }
  else {
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)local_res20,-1);
    uVar1 = (**(code **)(*param_1 + 0x208))(param_1,lVar4);
    uVar2 = (ulonglong)uVar1;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20);
  return uVar2;
}

/* ---- FUNC 0003B880 FUN_18003b880 (940 bytes) ---- */

/* WARNING: Removing unreachable block (ram,0x00018003bc12) */
/* WARNING: Removing unreachable block (ram,0x00018003bc1a) */

undefined8 FUN_18003b880(longlong *param_1,longlong *param_2,longlong *param_3)

{
  undefined8 uVar1;
  
  *param_3 = 0;
  if (((((*param_2 == DAT_180066c58) && (param_2[1] == DAT_180066c60)) ||
       ((*param_2 == DAT_180066c78 && (param_2[1] == DAT_180066c80)))) ||
      ((*param_2 == DAT_180063400 && (param_2[1] == DAT_180063408)))) ||
     ((*param_2 == DAT_1800634f0 && (param_2[1] == DAT_1800634f8)))) {
    *param_3 = (longlong)param_1;
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((*param_2 == DAT_180066ca8) && (param_2[1] == DAT_180066cb0)) {
    *param_3 = (longlong)(param_1 + 0x10);
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((((*param_2 == DAT_180066dd8) && (param_2[1] == DAT_180066de0)) ||
      ((*param_2 == DAT_180066d98 && (param_2[1] == DAT_180066da0)))) ||
     ((*param_2 == DAT_180066da8 && (param_2[1] == DAT_180066db0)))) {
    *param_3 = (longlong)(param_1 + 0x1e);
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((*param_2 == DAT_180066d58) && (param_2[1] == DAT_180066d60)) {
    *param_3 = (longlong)(param_1 + 0x23);
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((*param_2 == DAT_180066db8) && (param_2[1] == DAT_180066dc0)) {
    *param_3 = (longlong)(param_1 + 0x32);
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((*param_2 == DAT_180066cd8) && (param_2[1] == DAT_180066ce0)) {
    *param_3 = (longlong)(param_1 + 3);
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if (((*param_2 == DAT_180066d48) && (param_2[1] == DAT_180066d50)) && (param_1[0x39] != 0)) {
    *param_3 = param_1[0x39];
    (**(code **)(*(longlong *)param_1[0x39] + 8))();
    return 0;
  }
  if ((*param_2 == DAT_1800635c0) && (param_2[1] == DAT_1800635c8)) {
    *param_3 = (longlong)(param_1 + 0x3e);
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if (((((*param_2 != DAT_180066cb8) || (param_2[1] != DAT_180066cc0)) &&
       ((*param_2 != DAT_180066cc8 || (param_2[1] != DAT_180066cd0)))) &&
      ((((*param_2 != DAT_180066d78 || (param_2[1] != DAT_180066d80)) &&
        ((*param_2 != DAT_1800638c8 || (param_2[1] != DAT_1800638d0)))) &&
       ((((*param_2 != DAT_180064158 || (param_2[1] != DAT_180064160)) &&
         ((*param_2 != DAT_180064168 || (param_2[1] != DAT_180064170)))) &&
        ((*param_2 != DAT_180066e38 || (param_2[1] != DAT_180066e40)))))))) &&
     (((*param_2 != DAT_1800659c0 || (param_2[1] != DAT_1800659c8)) &&
      ((*param_2 != DAT_180066ce8 || (param_2[1] != DAT_180066cf0)))))) {
    if ((int)param_1[0x31] != 0) {
      *(undefined4 *)(param_1 + 0x31) = 0;
      return 0x80004002;
    }
    if (param_1[9] != 0) {
      *(undefined4 *)(param_1 + 0x31) = 1;
      uVar1 = HAQueryInterface();
      *(undefined4 *)(param_1 + 0x31) = 0;
      return uVar1;
    }
  }
  return 0x80004002;
}

/* ---- FUNC 0003BC30 FUN_18003bc30 (440 bytes) ---- */

undefined8 FUN_18003bc30(longlong param_1,uint param_2)

{
  HRESULT HVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar2;
  BSTR pOVar3;
  ICreateErrorInfo *local_res8;
  LPCSTR local_res18;
  LPCSTR local_res20;
  IErrorInfo *local_18;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_10 [8];
  
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18);
  if (*(BSTR *)(param_1 + 0xb0) != (BSTR)0x0) {
    SysFreeString(*(BSTR *)(param_1 + 0xb0));
  }
  if (*(BSTR *)(param_1 + 0xa8) != (BSTR)0x0) {
    SysFreeString(*(BSTR *)(param_1 + 0xa8));
  }
  if (*(BSTR *)(param_1 + 0xb8) != (BSTR)0x0) {
    SysFreeString(*(BSTR *)(param_1 + 0xb8));
  }
  *(undefined8 *)(param_1 + 0xa0) = 0;
  *(undefined8 *)(param_1 + 0xa8) = 0;
  *(undefined8 *)(param_1 + 0xb0) = 0;
  *(undefined8 *)(param_1 + 0xb8) = 0;
  *(undefined8 *)(param_1 + 0xc0) = 0;
  *(undefined8 *)(param_1 + 200) = 0;
  *(undefined8 *)(param_1 + 0xd0) = 0;
  *(undefined8 *)(param_1 + 0xd8) = 0;
  *(short *)(param_1 + 0xa0) = (short)param_2;
  pCVar2 = FUN_180020fe0(local_10,param_2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_10);
  pCVar2 = FUN_180020fe0(local_10,1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18,
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_10);
  if (*(int *)(local_res20 + -0x10) != 0) {
    pOVar3 = FUN_1800019d0(local_res20);
    *(BSTR *)(param_1 + 0xb0) = pOVar3;
  }
  if (*(int *)(local_res18 + -0x10) != 0) {
    pOVar3 = FUN_1800019d0(local_res18);
    *(BSTR *)(param_1 + 0xa8) = pOVar3;
  }
  *(undefined4 *)(param_1 + 0xe0) = 1;
  HVar1 = CreateErrorInfo(&local_res8);
  if (-1 < HVar1) {
    (*local_res8->lpVtbl->SetGUID)(local_res8,(GUID *)&DAT_180063400);
    if (*(LPOLESTR *)(param_1 + 0xa8) != (LPOLESTR)0x0) {
      (*local_res8->lpVtbl->SetSource)(local_res8,*(LPOLESTR *)(param_1 + 0xa8));
    }
    if (*(LPOLESTR *)(param_1 + 0xb0) != (LPOLESTR)0x0) {
      (*local_res8->lpVtbl->SetDescription)(local_res8,*(LPOLESTR *)(param_1 + 0xb0));
    }
    HVar1 = (*local_res8->lpVtbl->QueryInterface)(local_res8,(IID *)&DAT_180066c98,&local_18);
    if (-1 < HVar1) {
      SetErrorInfo(0,local_18);
      (*local_18->lpVtbl->Release)(local_18);
    }
    (*local_res8->lpVtbl->Release)(local_res8);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
  return 0x80020009;
}

/* ---- FUNC 0003BDF0 FUN_18003bdf0 (46 bytes) ---- */

undefined8 FUN_18003bdf0(longlong *param_1,undefined8 *param_2)

{
  OLECHAR OVar1;
  HRESULT HVar2;
  undefined8 uVar3;
  BSTR pOVar4;
  OLECHAR *pOVar5;
  short sVar6;
  longlong lVar7;
  OLECHAR *pOVar8;
  longlong lVar9;
  OLECHAR *pOVar10;
  ICreateErrorInfo *local_res10;
  IErrorInfo *local_res18;
  
  if (param_2 == (undefined8 *)0x0) {
    uVar3 = (**(code **)(*param_1 + 0x210))(param_1,0x7d1);
    return uVar3;
  }
  if ((BSTR)param_1[0x16] != (BSTR)0x0) {
    SysFreeString((BSTR)param_1[0x16]);
  }
  if ((BSTR)param_1[0x15] != (BSTR)0x0) {
    SysFreeString((BSTR)param_1[0x15]);
  }
  if ((BSTR)param_1[0x17] != (BSTR)0x0) {
    SysFreeString((BSTR)param_1[0x17]);
  }
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  sVar6 = 0x7d1;
  if (*(short *)(param_2 + 1) != 0) {
    sVar6 = *(short *)(param_2 + 1);
  }
  *(short *)(param_1 + 0x14) = sVar6;
  pOVar5 = (OLECHAR *)param_2[2];
  if (pOVar5 == (OLECHAR *)0x0) {
    pOVar4 = SysAllocString(L"Unexpected Error");
  }
  else {
    lVar7 = -1;
    do {
      lVar7 = lVar7 + 1;
    } while (pOVar5[lVar7] != L'\0');
    pOVar4 = SysAllocStringLen(pOVar5,(UINT)lVar7);
  }
  param_1[0x16] = (longlong)pOVar4;
  pOVar5 = (OLECHAR *)param_2[3];
  lVar7 = -1;
  if (pOVar5 == (OLECHAR *)0x0) {
    pOVar4 = SysAllocString(L"Happ.Application");
  }
  else {
    do {
      lVar9 = lVar7;
      lVar7 = lVar9 + 1;
    } while (pOVar5[lVar7] != L'\0');
    if (*(short *)(param_2 + 1) == 0x13) {
      pOVar5 = (OLECHAR *)MDmalloc(lVar7 * 2 + 4);
      if (pOVar5 != (OLECHAR *)0x0) {
        *pOVar5 = L'!';
        pOVar8 = (OLECHAR *)param_2[3];
        pOVar10 = pOVar5;
        do {
          pOVar10 = pOVar10 + 1;
          OVar1 = *pOVar8;
          pOVar8 = pOVar8 + 1;
          *pOVar10 = OVar1;
        } while (OVar1 != L'\0');
        pOVar5[lVar9 + 2] = L'\0';
        pOVar4 = SysAllocStringLen(pOVar5,(int)lVar9 + 2);
        param_1[0x15] = (longlong)pOVar4;
        MDfree(pOVar5);
      }
      goto LAB_18003bf77;
    }
    pOVar4 = SysAllocStringLen(pOVar5,(UINT)lVar7);
  }
  param_1[0x15] = (longlong)pOVar4;
LAB_18003bf77:
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_1 + 0x1c) = 1;
  if ((code *)*param_2 != (code *)0x0) {
    (*(code *)*param_2)(param_2);
  }
  HVar2 = CreateErrorInfo(&local_res10);
  if (-1 < HVar2) {
    (*local_res10->lpVtbl->SetGUID)(local_res10,(GUID *)&DAT_180063460);
    if ((LPOLESTR)param_1[0x15] != (LPOLESTR)0x0) {
      (*local_res10->lpVtbl->SetSource)(local_res10,(LPOLESTR)param_1[0x15]);
    }
    if ((LPOLESTR)param_1[0x16] != (LPOLESTR)0x0) {
      (*local_res10->lpVtbl->SetDescription)(local_res10,(LPOLESTR)param_1[0x16]);
    }
    HVar2 = (*local_res10->lpVtbl->QueryInterface)(local_res10,(IID *)&DAT_180066c98,&local_res18);
    if (-1 < HVar2) {
      SetErrorInfo(0,local_res18);
      (*local_res18->lpVtbl->Release)(local_res18);
    }
    (*local_res10->lpVtbl->Release)(local_res10);
  }
  return 0x80020009;
}

/* ---- FUNC 0003BE1E FUN_18003be1e (387 bytes) ---- */

undefined8 FUN_18003be1e(BSTR param_1)

{
  OLECHAR OVar1;
  HRESULT HVar2;
  BSTR pOVar3;
  OLECHAR *pOVar4;
  short sVar5;
  longlong lVar6;
  OLECHAR *pOVar7;
  longlong unaff_RBX;
  undefined8 *unaff_RSI;
  longlong lVar8;
  OLECHAR *pOVar9;
  ICreateErrorInfo *in_stack_00000048;
  IErrorInfo *in_stack_00000050;
  
  if (param_1 != (BSTR)0x0) {
    SysFreeString(param_1);
  }
  if (*(BSTR *)(unaff_RBX + 0xa8) != (BSTR)0x0) {
    SysFreeString(*(BSTR *)(unaff_RBX + 0xa8));
  }
  if (*(BSTR *)(unaff_RBX + 0xb8) != (BSTR)0x0) {
    SysFreeString(*(BSTR *)(unaff_RBX + 0xb8));
  }
  *(undefined8 *)(unaff_RBX + 0xa0) = 0;
  *(undefined8 *)(unaff_RBX + 0xa8) = 0;
  *(undefined8 *)(unaff_RBX + 0xb0) = 0;
  *(undefined8 *)(unaff_RBX + 0xb8) = 0;
  *(undefined8 *)(unaff_RBX + 0xc0) = 0;
  *(undefined8 *)(unaff_RBX + 200) = 0;
  *(undefined8 *)(unaff_RBX + 0xd0) = 0;
  *(undefined8 *)(unaff_RBX + 0xd8) = 0;
  sVar5 = 0x7d1;
  if (*(short *)(unaff_RSI + 1) != 0) {
    sVar5 = *(short *)(unaff_RSI + 1);
  }
  *(short *)(unaff_RBX + 0xa0) = sVar5;
  pOVar4 = (OLECHAR *)unaff_RSI[2];
  if (pOVar4 == (OLECHAR *)0x0) {
    pOVar3 = SysAllocString(L"Unexpected Error");
  }
  else {
    lVar6 = -1;
    do {
      lVar6 = lVar6 + 1;
    } while (pOVar4[lVar6] != L'\0');
    pOVar3 = SysAllocStringLen(pOVar4,(UINT)lVar6);
  }
  *(BSTR *)(unaff_RBX + 0xb0) = pOVar3;
  pOVar4 = (OLECHAR *)unaff_RSI[3];
  lVar6 = -1;
  if (pOVar4 == (OLECHAR *)0x0) {
    pOVar3 = SysAllocString(L"Happ.Application");
  }
  else {
    do {
      lVar8 = lVar6;
      lVar6 = lVar8 + 1;
    } while (pOVar4[lVar6] != L'\0');
    if (*(short *)(unaff_RSI + 1) == 0x13) {
      pOVar4 = (OLECHAR *)MDmalloc(lVar6 * 2 + 4);
      if (pOVar4 != (OLECHAR *)0x0) {
        *pOVar4 = L'!';
        pOVar7 = (OLECHAR *)unaff_RSI[3];
        pOVar9 = pOVar4;
        do {
          pOVar9 = pOVar9 + 1;
          OVar1 = *pOVar7;
          pOVar7 = pOVar7 + 1;
          *pOVar9 = OVar1;
        } while (OVar1 != L'\0');
        pOVar4[lVar8 + 2] = L'\0';
        pOVar3 = SysAllocStringLen(pOVar4,(int)lVar8 + 2);
        *(BSTR *)(unaff_RBX + 0xa8) = pOVar3;
        MDfree(pOVar4);
      }
      goto LAB_18003bf77;
    }
    pOVar3 = SysAllocStringLen(pOVar4,(UINT)lVar6);
  }
  *(BSTR *)(unaff_RBX + 0xa8) = pOVar3;
LAB_18003bf77:
  *(undefined4 *)(unaff_RBX + 0xc0) = *(undefined4 *)(unaff_RSI + 4);
  *(undefined4 *)(unaff_RBX + 0xe0) = 1;
  if ((code *)*unaff_RSI != (code *)0x0) {
    (*(code *)*unaff_RSI)();
  }
  HVar2 = CreateErrorInfo(&stack0x00000048);
  if (-1 < HVar2) {
    (*in_stack_00000048->lpVtbl->SetGUID)(in_stack_00000048,(GUID *)&DAT_180063460);
    if (*(LPOLESTR *)(unaff_RBX + 0xa8) != (LPOLESTR)0x0) {
      (*in_stack_00000048->lpVtbl->SetSource)(in_stack_00000048,*(LPOLESTR *)(unaff_RBX + 0xa8));
    }
    if (*(LPOLESTR *)(unaff_RBX + 0xb0) != (LPOLESTR)0x0) {
      (*in_stack_00000048->lpVtbl->SetDescription)
                (in_stack_00000048,*(LPOLESTR *)(unaff_RBX + 0xb0));
    }
    HVar2 = (*in_stack_00000048->lpVtbl->QueryInterface)
                      (in_stack_00000048,(IID *)&DAT_180066c98,&stack0x00000050);
    if (-1 < HVar2) {
      SetErrorInfo(0,in_stack_00000050);
      (*in_stack_00000050->lpVtbl->Release)(in_stack_00000050);
    }
    (*in_stack_00000048->lpVtbl->Release)(in_stack_00000048);
  }
  return 0x80020009;
}

/* ---- FUNC 0003BFA1 FUN_18003bfa1 (157 bytes) ---- */

undefined8 FUN_18003bfa1(void)

{
  HRESULT HVar1;
  code *in_RAX;
  longlong unaff_RBX;
  ICreateErrorInfo *in_stack_00000048;
  IErrorInfo *in_stack_00000050;
  
  (*in_RAX)();
  HVar1 = CreateErrorInfo(&stack0x00000048);
  if (-1 < HVar1) {
    (*in_stack_00000048->lpVtbl->SetGUID)(in_stack_00000048,(GUID *)&DAT_180063460);
    if (*(LPOLESTR *)(unaff_RBX + 0xa8) != (LPOLESTR)0x0) {
      (*in_stack_00000048->lpVtbl->SetSource)(in_stack_00000048,*(LPOLESTR *)(unaff_RBX + 0xa8));
    }
    if (*(LPOLESTR *)(unaff_RBX + 0xb0) != (LPOLESTR)0x0) {
      (*in_stack_00000048->lpVtbl->SetDescription)
                (in_stack_00000048,*(LPOLESTR *)(unaff_RBX + 0xb0));
    }
    HVar1 = (*in_stack_00000048->lpVtbl->QueryInterface)
                      (in_stack_00000048,(IID *)&DAT_180066c98,&stack0x00000050);
    if (-1 < HVar1) {
      SetErrorInfo(0,in_stack_00000050);
      (*in_stack_00000050->lpVtbl->Release)(in_stack_00000050);
    }
    (*in_stack_00000048->lpVtbl->Release)(in_stack_00000048);
  }
  return 0x80020009;
}

/* ---- FUNC 0003C040 FUN_18003c040 (446 bytes) ---- */

void FUN_18003c040(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong *local_28;
  undefined8 uStack_20;
  longlong **local_18;
  longlong **local_10;
  
  if (*(longlong *)(param_1 + 0x1e8) != 0) {
    local_28 = (longlong *)0x0;
    uStack_20 = 0;
    local_18 = &local_28;
    local_10 = &local_28;
    local_28 = operator_new(0x28);
    *local_28 = (longlong)local_28;
    local_28[1] = (longlong)local_28;
    local_28[2] = (longlong)local_28;
    *(undefined2 *)(local_28 + 3) = 0x101;
    plVar6 = FUN_1800378f0(&local_28,*(undefined8 **)(*(longlong *)(param_1 + 0x1e0) + 8),
                           (longlong)local_28,param_4);
    local_28[1] = (longlong)plVar6;
    uStack_20 = *(undefined8 *)(param_1 + 0x1e8);
    plVar6 = (longlong *)local_28[1];
    if (*(char *)((longlong)plVar6 + 0x19) == '\0') {
      cVar1 = *(char *)(*plVar6 + 0x19);
      plVar3 = (longlong *)*plVar6;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*plVar3 + 0x19);
        plVar6 = plVar3;
        plVar3 = (longlong *)*plVar3;
      }
      *local_28 = (longlong)plVar6;
      lVar2 = *(longlong *)(local_28[1] + 0x10);
      cVar1 = *(char *)(lVar2 + 0x19);
      lVar4 = local_28[1];
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*(longlong *)(lVar2 + 0x10) + 0x19);
        lVar4 = lVar2;
        lVar2 = *(longlong *)(lVar2 + 0x10);
      }
      local_28[2] = lVar4;
    }
    else {
      *local_28 = (longlong)local_28;
      local_28[2] = (longlong)local_28;
    }
    plVar6 = (longlong *)*local_28;
    if (plVar6 != local_28) {
      do {
        (**(code **)(*(longlong *)plVar6[4] + 0x198))();
        plVar3 = (longlong *)plVar6[2];
        if (*(char *)((longlong)plVar3 + 0x19) == '\0') {
          cVar1 = *(char *)(*plVar3 + 0x19);
          plVar6 = plVar3;
          plVar3 = (longlong *)*plVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*plVar3 + 0x19);
            plVar6 = plVar3;
            plVar3 = (longlong *)*plVar3;
          }
        }
        else {
          cVar1 = *(char *)(plVar6[1] + 0x19);
          plVar5 = (longlong *)plVar6[1];
          plVar3 = plVar6;
          while ((plVar6 = plVar5, cVar1 == '\0' && (plVar3 == (longlong *)plVar6[2]))) {
            cVar1 = *(char *)(plVar6[1] + 0x19);
            plVar5 = (longlong *)plVar6[1];
            plVar3 = plVar6;
          }
        }
      } while (plVar6 != local_28);
    }
    cVar1 = *(char *)(local_28[1] + 0x19);
    plVar6 = (longlong *)local_28[1];
    while (cVar1 == '\0') {
      FUN_180037a20(&local_28,&local_28,(longlong *)plVar6[2]);
      plVar3 = (longlong *)*plVar6;
      FUN_180025ad0(plVar6);
      plVar6 = plVar3;
      cVar1 = *(char *)((longlong)plVar3 + 0x19);
    }
    FUN_180025ad0(local_28);
  }
  return;
}

/* ---- FUNC 0003C200 FUN_18003c200 (77 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_18003c200(longlong *param_1)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  longlong *plVar1;
  int iVar2;
  ulonglong uVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this_00;
  char *_Str;
  longlong lVar4;
  char *pcVar5;
  undefined8 *puVar6;
  char cVar7;
  size_t _Count;
  ulonglong uVar8;
  ulonglong uVar9;
  undefined1 auStack_b8 [32];
  undefined8 *local_98;
  longlong local_90;
  longlong *local_88;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_80;
  longlong local_78 [5];
  undefined8 local_50;
  undefined8 uStack_48;
  undefined4 local_40;
  ulonglong local_38;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStack_b8;
  if (DAT_1800797f8 != 0) {
    uVar3 = (**(code **)(*param_1 + 0x210))(param_1,0x7f3);
    return uVar3;
  }
  if (param_1[9] != 0) {
    return 1;
  }
  this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x3b);
  local_80 = this;
  this_00 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                      (this,(int)&local_90);
  iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                    (this_00,"@LABEL");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_90);
  if ((((iVar2 == 0) || ((int)param_1[0xd] != 0)) ||
      (plVar1 = (longlong *)param_1[0xc], plVar1 == (longlong *)0x0)) ||
     ((plVar1[9] == 0 && (iVar2 = (**(code **)(*plVar1 + 0x198))(plVar1), iVar2 < 0)))) {
    return 0x80004005;
  }
  _Str = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)this,0);
  uVar3 = 0;
  local_50 = _DAT_180065b90;
  uStack_48 = _UNK_180065b98;
  local_40 = 0xffffffff;
  local_78[4] = 0;
  local_98 = (undefined8 *)0x0;
  local_78[0] = 0;
  local_78[1] = 0;
  local_78[2] = 0;
  local_78[3] = 0;
  lVar4 = (longlong)(int)plVar1[0x2c];
  if ((int)plVar1[0x2c] == -1) {
LAB_18003c4b6:
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)local_80,-1);
    return 0x80004005;
  }
  uVar8 = uVar3;
  uVar9 = uVar3;
  local_90 = lVar4;
  if (0 < lVar4) {
    do {
      if (*_Str == '#') {
        _Str = _Str + 1;
        cVar7 = '#';
        iVar2 = atoi(_Str);
        if (iVar2 < 0) goto LAB_18003c4b6;
        *(int *)((longlong)&local_50 + uVar8 * 4) = iVar2;
        do {
          if (cVar7 == '\0') break;
          cVar7 = *_Str;
          _Str = _Str + 1;
        } while (cVar7 != '!');
      }
      else {
        iVar2 = HAIsNamedDimension(plVar1[9],uVar9,&local_98);
        if (iVar2 == 0) goto LAB_18003c4b6;
        pcVar5 = strchr(_Str,0x21);
        _Count = 0xffffffffffffffff;
        if (pcVar5 == (char *)0x0) {
          do {
            _Count = _Count + 1;
          } while (_Str[_Count] != '\0');
        }
        else {
          *pcVar5 = '\0';
          do {
            _Count = _Count + 1;
          } while (_Str[_Count] != '\0');
          *pcVar5 = '!';
        }
        pcVar5 = (char *)MDmalloc(_Count + 1);
        local_78[uVar8] = (longlong)pcVar5;
        if (pcVar5 == (char *)0x0) {
          ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)local_80,-1);
          return 0x8007000e;
        }
        *(undefined4 *)((longlong)&local_50 + uVar8 * 4) = 0xffffffff;
        strncpy(pcVar5,_Str,_Count);
        _Str = _Str + _Count;
        *(undefined1 *)(_Count + local_78[uVar8]) = 0;
        if (*_Str == '!') {
          _Str = _Str + 1;
        }
      }
      uVar8 = uVar8 + 1;
      uVar9 = (ulonglong)((int)uVar9 + 1);
    } while ((longlong)uVar8 < local_90);
  }
  lVar4 = HAGetElement(plVar1[9],&local_50,local_78,&local_98);
  param_1[9] = lVar4;
  if (lVar4 == 0) {
    if ((local_98 != (undefined8 *)0x0) && ((code *)*local_98 != (code *)0x0)) {
      (*(code *)*local_98)();
    }
    if (local_78[0] != 0) {
      MDfree();
    }
    if (local_78[1] != 0) {
      MDfree();
    }
    if (local_78[2] != 0) {
      MDfree();
    }
    if (local_78[3] != 0) {
      MDfree();
    }
    if (local_78[4] != 0) {
      MDfree();
    }
    goto LAB_18003c4b6;
  }
  local_88 = (longlong *)0x0;
  HAGetBptr(lVar4,&local_88);
  if (local_88 == (longlong *)0x0) {
    puVar6 = (undefined8 *)HASetBptr(param_1,param_1[9]);
    if (puVar6 == (undefined8 *)0x0) {
      if ((int)param_1[0xd] == 0) {
        FUN_18003e690(param_1[0xc],(ulonglong)param_1);
      }
      goto LAB_18003c584;
    }
    if ((code *)*puVar6 != (code *)0x0) {
      (*(code *)*puVar6)(puVar6);
    }
  }
  else if (local_88 == param_1) goto LAB_18003c584;
  param_1[9] = 0;
  uVar3 = 0x80004005;
LAB_18003c584:
  if (local_78[0] != 0) {
    MDfree();
  }
  if (local_78[1] != 0) {
    MDfree();
  }
  if (local_78[2] != 0) {
    MDfree();
  }
  if (local_78[3] != 0) {
    MDfree();
  }
  if (local_78[4] != 0) {
    MDfree();
  }
  ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)(param_1 + 0x3b),-1);
  return uVar3;
}

/* ---- FUNC 0003C24D FUN_18003c24d (141 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_18003c24d(longlong param_1)

{
  longlong *plVar1;
  code *pcVar2;
  int iVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  char *_Str;
  char *pcVar4;
  longlong lVar5;
  undefined8 *puVar6;
  longlong unaff_RBP;
  ulonglong unaff_RSI;
  char cVar7;
  size_t _Count;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this_00;
  ulonglong uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  
  this_00 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x1d8);
  *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)(unaff_RBP + -0x21) = this_00;
  this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
         ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                   (this_00,(int)unaff_RBP + -0x31);
  iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                    (this,"@LABEL");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + -0x31));
  if ((((iVar3 == 0) || (*(int *)(unaff_RSI + 0x68) != 0)) ||
      (plVar1 = *(longlong **)(unaff_RSI + 0x60), plVar1 == (longlong *)0x0)) ||
     ((plVar1[9] == 0 && (iVar3 = (**(code **)(*plVar1 + 0x198))(plVar1), iVar3 < 0)))) {
    return 0x80004005;
  }
  _Str = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)this_00,0);
  uVar11 = _UNK_180065b98;
  uVar8 = 0;
  *(undefined8 *)(unaff_RBP + 0xf) = _DAT_180065b90;
  *(undefined8 *)(unaff_RBP + 0x17) = uVar11;
  *(undefined4 *)(unaff_RBP + 0x1f) = 0xffffffff;
  *(undefined8 *)(unaff_RBP + 7) = 0;
  *(undefined8 *)(unaff_RBP + -0x39) = 0;
  *(undefined8 *)(unaff_RBP + -0x19) = 0;
  *(undefined8 *)(unaff_RBP + -0x11) = 0;
  *(undefined8 *)(unaff_RBP + -9) = 0;
  *(undefined8 *)(unaff_RBP + -1) = 0;
  iVar3 = (int)plVar1[0x2c];
  if (iVar3 == -1) {
LAB_18003c4b6:
    ATL::CSimpleStringT<char,1>::ReleaseBuffer(*(CSimpleStringT<char,1> **)(unaff_RBP + -0x21),-1);
    return 0x80004005;
  }
  *(longlong *)(unaff_RBP + -0x31) = (longlong)iVar3;
  uVar9 = uVar8;
  uVar10 = uVar8;
  if (0 < (longlong)iVar3) {
    do {
      if (*_Str == '#') {
        _Str = _Str + 1;
        cVar7 = '#';
        iVar3 = atoi(_Str);
        if (iVar3 < 0) goto LAB_18003c4b6;
        *(int *)(unaff_RBP + 0xf + uVar9 * 4) = iVar3;
        do {
          if (cVar7 == '\0') break;
          cVar7 = *_Str;
          _Str = _Str + 1;
        } while (cVar7 != '!');
      }
      else {
        iVar3 = HAIsNamedDimension(plVar1[9],uVar10,unaff_RBP + -0x39);
        if (iVar3 == 0) goto LAB_18003c4b6;
        pcVar4 = strchr(_Str,0x21);
        _Count = 0xffffffffffffffff;
        if (pcVar4 == (char *)0x0) {
          do {
            _Count = _Count + 1;
          } while (_Str[_Count] != '\0');
        }
        else {
          *pcVar4 = '\0';
          do {
            _Count = _Count + 1;
          } while (_Str[_Count] != '\0');
          *pcVar4 = '!';
        }
        pcVar4 = (char *)MDmalloc(_Count + 1);
        *(char **)(unaff_RBP + -0x19 + uVar9 * 8) = pcVar4;
        if (pcVar4 == (char *)0x0) {
          ATL::CSimpleStringT<char,1>::ReleaseBuffer
                    (*(CSimpleStringT<char,1> **)(unaff_RBP + -0x21),-1);
          return 0x8007000e;
        }
        *(undefined4 *)(unaff_RBP + 0xf + uVar9 * 4) = 0xffffffff;
        strncpy(pcVar4,_Str,_Count);
        _Str = _Str + _Count;
        *(undefined1 *)(_Count + *(longlong *)(unaff_RBP + -0x19 + uVar9 * 8)) = 0;
        if (*_Str == '!') {
          _Str = _Str + 1;
        }
      }
      uVar9 = uVar9 + 1;
      uVar10 = (ulonglong)((int)uVar10 + 1);
    } while ((longlong)uVar9 < *(longlong *)(unaff_RBP + -0x31));
    this_00 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RSI + 0x1d8);
  }
  lVar5 = HAGetElement(plVar1[9],unaff_RBP + 0xf,unaff_RBP + -0x19,unaff_RBP + -0x39);
  *(longlong *)(unaff_RSI + 0x48) = lVar5;
  if (lVar5 == 0) {
    if ((*(undefined8 **)(unaff_RBP + -0x39) != (undefined8 *)0x0) &&
       (pcVar2 = (code *)**(undefined8 **)(unaff_RBP + -0x39), pcVar2 != (code *)0x0)) {
      (*pcVar2)();
    }
    if (*(longlong *)(unaff_RBP + -0x19) != 0) {
      MDfree();
    }
    if (*(longlong *)(unaff_RBP + -0x11) != 0) {
      MDfree();
    }
    if (*(longlong *)(unaff_RBP + -9) != 0) {
      MDfree();
    }
    if (*(longlong *)(unaff_RBP + -1) != 0) {
      MDfree();
    }
    if (*(longlong *)(unaff_RBP + 7) != 0) {
      MDfree();
    }
    goto LAB_18003c4b6;
  }
  *(undefined8 *)(unaff_RBP + -0x29) = 0;
  uVar11 = HAGetBptr(lVar5,unaff_RBP + -0x29);
  if (*(ulonglong *)(unaff_RBP + -0x29) == 0) {
    puVar6 = (undefined8 *)HASetBptr(uVar11,*(undefined8 *)(unaff_RSI + 0x48));
    if (puVar6 == (undefined8 *)0x0) {
      if (*(int *)(unaff_RSI + 0x68) == 0) {
        FUN_18003e690(*(longlong *)(unaff_RSI + 0x60),unaff_RSI);
      }
      goto LAB_18003c584;
    }
    if ((code *)*puVar6 != (code *)0x0) {
      (*(code *)*puVar6)(puVar6);
    }
  }
  else if (*(ulonglong *)(unaff_RBP + -0x29) == unaff_RSI) goto LAB_18003c584;
  *(undefined8 *)(unaff_RSI + 0x48) = 0;
  uVar8 = 0x80004005;
LAB_18003c584:
  if (*(longlong *)(unaff_RBP + -0x19) != 0) {
    MDfree();
  }
  if (*(longlong *)(unaff_RBP + -0x11) != 0) {
    MDfree();
  }
  if (*(longlong *)(unaff_RBP + -9) != 0) {
    MDfree();
  }
  if (*(longlong *)(unaff_RBP + -1) != 0) {
    MDfree();
  }
  if (*(longlong *)(unaff_RBP + 7) != 0) {
    MDfree();
  }
  ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)this_00,-1);
  return uVar8;
}

/* ---- FUNC 0003C2DA FUN_18003c2da (774 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_18003c2da(void)

{
  code *pcVar1;
  int iVar2;
  char *_Str;
  char *pcVar3;
  longlong lVar4;
  undefined8 *puVar5;
  longlong unaff_RBP;
  ulonglong unaff_RSI;
  char cVar6;
  CSimpleStringT<char,1> *unaff_RDI;
  size_t _Count;
  ulonglong uVar7;
  longlong unaff_R13;
  ulonglong uVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  
  _Str = ATL::CSimpleStringT<char,1>::GetBuffer(unaff_RDI,0);
  uVar10 = _UNK_180065b98;
  uVar7 = 0;
  *(undefined8 *)(unaff_RBP + 0xf) = _DAT_180065b90;
  *(undefined8 *)(unaff_RBP + 0x17) = uVar10;
  *(undefined4 *)(unaff_RBP + 0x1f) = 0xffffffff;
  *(undefined8 *)(unaff_RBP + 7) = 0;
  *(undefined8 *)(unaff_RBP + -0x39) = 0;
  *(undefined8 *)(unaff_RBP + -0x19) = 0;
  *(undefined8 *)(unaff_RBP + -0x11) = 0;
  *(undefined8 *)(unaff_RBP + -9) = 0;
  *(undefined8 *)(unaff_RBP + -1) = 0;
  iVar2 = *(int *)(unaff_R13 + 0x160);
  if (iVar2 == -1) {
LAB_18003c4b6:
    ATL::CSimpleStringT<char,1>::ReleaseBuffer(*(CSimpleStringT<char,1> **)(unaff_RBP + -0x21),-1);
    return 0x80004005;
  }
  *(longlong *)(unaff_RBP + -0x31) = (longlong)iVar2;
  uVar8 = uVar7;
  uVar9 = uVar7;
  if (0 < (longlong)iVar2) {
    do {
      if (*_Str == '#') {
        _Str = _Str + 1;
        cVar6 = '#';
        iVar2 = atoi(_Str);
        if (iVar2 < 0) goto LAB_18003c4b6;
        *(int *)(unaff_RBP + 0xf + uVar8 * 4) = iVar2;
        do {
          if (cVar6 == '\0') break;
          cVar6 = *_Str;
          _Str = _Str + 1;
        } while (cVar6 != '!');
      }
      else {
        iVar2 = HAIsNamedDimension(*(undefined8 *)(unaff_R13 + 0x48),uVar9,unaff_RBP + -0x39);
        if (iVar2 == 0) goto LAB_18003c4b6;
        pcVar3 = strchr(_Str,0x21);
        _Count = 0xffffffffffffffff;
        if (pcVar3 == (char *)0x0) {
          do {
            _Count = _Count + 1;
          } while (_Str[_Count] != '\0');
        }
        else {
          *pcVar3 = '\0';
          do {
            _Count = _Count + 1;
          } while (_Str[_Count] != '\0');
          *pcVar3 = '!';
        }
        pcVar3 = (char *)MDmalloc(_Count + 1);
        *(char **)(unaff_RBP + -0x19 + uVar8 * 8) = pcVar3;
        if (pcVar3 == (char *)0x0) {
          ATL::CSimpleStringT<char,1>::ReleaseBuffer
                    (*(CSimpleStringT<char,1> **)(unaff_RBP + -0x21),-1);
          return 0x8007000e;
        }
        *(undefined4 *)(unaff_RBP + 0xf + uVar8 * 4) = 0xffffffff;
        strncpy(pcVar3,_Str,_Count);
        _Str = _Str + _Count;
        *(undefined1 *)(_Count + *(longlong *)(unaff_RBP + -0x19 + uVar8 * 8)) = 0;
        if (*_Str == '!') {
          _Str = _Str + 1;
        }
      }
      uVar8 = uVar8 + 1;
      uVar9 = (ulonglong)((int)uVar9 + 1);
    } while ((longlong)uVar8 < *(longlong *)(unaff_RBP + -0x31));
    unaff_RDI = (CSimpleStringT<char,1> *)(unaff_RSI + 0x1d8);
  }
  lVar4 = HAGetElement(*(undefined8 *)(unaff_R13 + 0x48),unaff_RBP + 0xf,unaff_RBP + -0x19,
                       unaff_RBP + -0x39);
  *(longlong *)(unaff_RSI + 0x48) = lVar4;
  if (lVar4 == 0) {
    if ((*(undefined8 **)(unaff_RBP + -0x39) != (undefined8 *)0x0) &&
       (pcVar1 = (code *)**(undefined8 **)(unaff_RBP + -0x39), pcVar1 != (code *)0x0)) {
      (*pcVar1)();
    }
    if (*(longlong *)(unaff_RBP + -0x19) != 0) {
      MDfree();
    }
    if (*(longlong *)(unaff_RBP + -0x11) != 0) {
      MDfree();
    }
    if (*(longlong *)(unaff_RBP + -9) != 0) {
      MDfree();
    }
    if (*(longlong *)(unaff_RBP + -1) != 0) {
      MDfree();
    }
    if (*(longlong *)(unaff_RBP + 7) != 0) {
      MDfree();
    }
    goto LAB_18003c4b6;
  }
  *(undefined8 *)(unaff_RBP + -0x29) = 0;
  uVar10 = HAGetBptr(lVar4,unaff_RBP + -0x29);
  if (*(ulonglong *)(unaff_RBP + -0x29) == 0) {
    puVar5 = (undefined8 *)HASetBptr(uVar10,*(undefined8 *)(unaff_RSI + 0x48));
    if (puVar5 == (undefined8 *)0x0) {
      if (*(int *)(unaff_RSI + 0x68) == 0) {
        FUN_18003e690(*(longlong *)(unaff_RSI + 0x60),unaff_RSI);
      }
      goto LAB_18003c584;
    }
    if ((code *)*puVar5 != (code *)0x0) {
      (*(code *)*puVar5)(puVar5);
    }
  }
  else if (*(ulonglong *)(unaff_RBP + -0x29) == unaff_RSI) goto LAB_18003c584;
  *(undefined8 *)(unaff_RSI + 0x48) = 0;
  uVar7 = 0x80004005;
LAB_18003c584:
  if (*(longlong *)(unaff_RBP + -0x19) != 0) {
    MDfree();
  }
  if (*(longlong *)(unaff_RBP + -0x11) != 0) {
    MDfree();
  }
  if (*(longlong *)(unaff_RBP + -9) != 0) {
    MDfree();
  }
  if (*(longlong *)(unaff_RBP + -1) != 0) {
    MDfree();
  }
  if (*(longlong *)(unaff_RBP + 7) != 0) {
    MDfree();
  }
  ATL::CSimpleStringT<char,1>::ReleaseBuffer(unaff_RDI,-1);
  return uVar7;
}

/* ---- FUNC 0003C4E2 FUN_18003c4e2 (24 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18003c4e2(void)

{
  return;
}

/* ---- FUNC 0003C4FA FUN_18003c4fa (22 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18003c4fa(void)

{
  return;
}

/* ---- FUNC 0003C510 FUN_18003c510 (22 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18003c510(void)

{
  longlong unaff_RBP;
  
  ATL::CSimpleStringT<char,1>::ReleaseBuffer(*(CSimpleStringT<char,1> **)(unaff_RBP + -0x21),-1);
  return 0x8007000e;
}

/* ---- FUNC 0003C5E0 FUN_18003c5e0 (10 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18003c5e0(void)

{
  return 0x80004005;
}

/* ---- FUNC 0003C5F0 FUN_18003c5f0 (181 bytes) ---- */

undefined8 FUN_18003c5f0(longlong *param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018003c60f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x210))(param_1,0x7f3);
    return uVar1;
  }
  if (param_1[9] == 0) {
                    /* WARNING: Could not recover jumptable at 0x00018003c62f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
    return uVar1;
  }
  lVar2 = HAReconcile();
  if (lVar2 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018003c64f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x208))(param_1,lVar2);
    return uVar1;
  }
  *(undefined4 *)(param_1[10] + 0x100) = 1;
  if (DAT_18007988c != 0) {
    DAT_180079890 = 1;
    return 0;
  }
  FUN_180011410(param_1[10],param_1);
  FUN_180019420(param_1[10],param_1,0x10000012);
  return 0;
}

/* ---- FUNC 0003C6B0 FUN_18003c6b0 (364 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_18003c6b0(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int *piVar1;
  DWORD DVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined1 auStack_438 [32];
  CHAR local_418 [1024];
  ulonglong local_18;
  
  local_18 = DAT_180077818 ^ (ulonglong)auStack_438;
  if (DAT_1800797e8 == (HANDLE)0x0) {
    FUN_180002a20(local_418,"Unfreed CHNode, name = \"%s\"\n",param_1[0x3b],param_4);
    OutputDebugStringA(local_418);
  }
  else {
    DVar2 = WaitForSingleObject(DAT_1800797e8,100);
    if (DVar2 == 0x102) {
      uVar4 = 0x16c;
      FUN_180002a20(local_418,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnode.cpp",0x16c);
      LogMessage(local_418,2,1);
      DVar2 = GetLastError();
      FUN_180002a20(local_418,"CHNode: Release --- LastError: %d",(ulonglong)DVar2,uVar4);
      LogMessage(local_418,0,1);
    }
    piVar1 = (int *)(param_1 + 1);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      if (param_1[9] == 0) {
        if (*(int *)(param_1 + 0xd) == 0) {
          FUN_18003e690(param_1[0xc],(ulonglong)param_1);
        }
      }
      else {
        puVar3 = (undefined8 *)HASetBptr(0);
        if ((puVar3 != (undefined8 *)0x0) && ((code *)*puVar3 != (code *)0x0)) {
          (*(code *)*puVar3)(puVar3);
        }
        param_1[9] = 0;
      }
      ReleaseSemaphore(DAT_1800797e8,1,(LPLONG)0x0);
      if ((code *)param_1[2] != (code *)0x0) {
        (*(code *)param_1[2])();
      }
      FUN_180037ee0(param_1);
      FUN_180025ad0(param_1);
      return 0;
    }
    ReleaseSemaphore(DAT_1800797e8,1,(LPLONG)0x0);
  }
  return *(undefined4 *)(param_1 + 1);
}

/* ---- FUNC 0003C820 FUN_18003c820 (74 bytes) ---- */

undefined8 FUN_18003c820(longlong *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  longlong lVar6;
  int iVar7;
  longlong local_res10;
  
  if (DAT_1800797f8 != 0) {
    uVar5 = (**(code **)(*param_1 + 0x210))(param_1,0x7f3);
    return uVar5;
  }
  local_res10 = 0;
  if (param_1[9] == 0) {
    uVar5 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
    return uVar5;
  }
  iVar1 = (int)param_1[0x2c];
  if (iVar1 == -1) {
    uVar5 = (**(code **)(*param_1 + 0x210))(param_1,0x7d1);
    return uVar5;
  }
  if (iVar1 == 0) {
    uVar5 = (**(code **)(*param_1 + 0x210))(param_1,0x7da);
    return uVar5;
  }
  iVar7 = 0;
  if (0 < iVar1) {
    do {
      iVar3 = HAGetLength(param_1[9],iVar7,&local_res10);
      iVar4 = HAGetLength(param_1[9],iVar7,&local_res10);
      iVar2 = 0;
      while (0 < iVar4) {
        local_res10 = HARemoveLocation(param_1[9],iVar7,0);
        if (local_res10 != 0) {
          lVar6 = *param_1;
          goto LAB_18003c981;
        }
        if (iVar3 * 2 < iVar2) {
          uVar5 = (**(code **)(*param_1 + 0x210))(param_1,0x7d1);
          return uVar5;
        }
        iVar4 = HAGetLength(param_1[9],iVar7);
        iVar2 = iVar2 + 1;
      }
      if (iVar4 == -1) {
        lVar6 = *param_1;
        if (local_res10 == 0) {
          uVar5 = (**(code **)(lVar6 + 0x210))(param_1,0x7d1);
          return uVar5;
        }
LAB_18003c981:
        uVar5 = (**(code **)(lVar6 + 0x208))(param_1,local_res10);
        return uVar5;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar1);
  }
  *(undefined4 *)(param_1[10] + 0x100) = 1;
  if (DAT_18007988c == 0) {
    FUN_1800374c0(0x67,param_1 + 0x3b);
    FUN_180011410(param_1[10],param_1);
  }
  else {
    DAT_180079890 = 1;
  }
  return 0;
}

/* ---- FUNC 0003C86A FUN_18003c86a (43 bytes) ---- */

undefined8 FUN_18003c86a(longlong *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  longlong lVar6;
  longlong *unaff_RBX;
  int iVar7;
  longlong in_stack_00000048;
  
  iVar1 = (int)param_1[0x2c];
  if (iVar1 == -1) {
    uVar5 = (**(code **)(*param_1 + 0x210))(param_1,0x7d1);
    return uVar5;
  }
  if (iVar1 == 0) {
    uVar5 = (**(code **)(*param_1 + 0x210))(param_1,0x7da);
    return uVar5;
  }
  iVar7 = 0;
  if (0 < iVar1) {
    do {
      iVar3 = HAGetLength(unaff_RBX[9],iVar7,&stack0x00000048);
      iVar4 = HAGetLength(unaff_RBX[9],iVar7,&stack0x00000048);
      iVar2 = 0;
      while (0 < iVar4) {
        in_stack_00000048 = HARemoveLocation(unaff_RBX[9],iVar7,0);
        if (in_stack_00000048 != 0) {
          lVar6 = *unaff_RBX;
          goto LAB_18003c981;
        }
        if (iVar3 * 2 < iVar2) {
          uVar5 = (**(code **)(*unaff_RBX + 0x210))();
          return uVar5;
        }
        iVar4 = HAGetLength(unaff_RBX[9],iVar7);
        iVar2 = iVar2 + 1;
      }
      if (iVar4 == -1) {
        lVar6 = *unaff_RBX;
        if (in_stack_00000048 == 0) {
          uVar5 = (**(code **)(lVar6 + 0x210))();
          return uVar5;
        }
LAB_18003c981:
        uVar5 = (**(code **)(lVar6 + 0x208))();
        return uVar5;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar1);
  }
  *(undefined4 *)(unaff_RBX[10] + 0x100) = 1;
  if (DAT_18007988c == 0) {
    FUN_1800374c0(0x67,unaff_RBX + 0x3b);
    FUN_180011410(unaff_RBX[10],unaff_RBX);
  }
  else {
    DAT_180079890 = 1;
  }
  return 0;
}

/* ---- FUNC 0003C895 FUN_18003c895 (30 bytes) ---- */

undefined8 FUN_18003c895(longlong *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong *unaff_RBX;
  int iVar6;
  int unaff_R14D;
  longlong in_stack_00000048;
  
  if (unaff_R14D == 0) {
    uVar4 = (**(code **)(*param_1 + 0x210))(param_1,0x7da);
    return uVar4;
  }
  iVar6 = 0;
  if (0 < unaff_R14D) {
    do {
      iVar2 = HAGetLength(unaff_RBX[9],iVar6,&stack0x00000048);
      iVar3 = HAGetLength(unaff_RBX[9],iVar6,&stack0x00000048);
      iVar1 = 0;
      while (0 < iVar3) {
        in_stack_00000048 = HARemoveLocation(unaff_RBX[9],iVar6,0);
        if (in_stack_00000048 != 0) {
          lVar5 = *unaff_RBX;
          goto LAB_18003c981;
        }
        if (iVar2 * 2 < iVar1) {
          uVar4 = (**(code **)(*unaff_RBX + 0x210))();
          return uVar4;
        }
        iVar3 = HAGetLength(unaff_RBX[9],iVar6);
        iVar1 = iVar1 + 1;
      }
      if (iVar3 == -1) {
        lVar5 = *unaff_RBX;
        if (in_stack_00000048 == 0) {
          uVar4 = (**(code **)(lVar5 + 0x210))();
          return uVar4;
        }
LAB_18003c981:
        uVar4 = (**(code **)(lVar5 + 0x208))();
        return uVar4;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < unaff_R14D);
  }
  *(undefined4 *)(unaff_RBX[10] + 0x100) = 1;
  if (DAT_18007988c == 0) {
    FUN_1800374c0(0x67,unaff_RBX + 0x3b);
    FUN_180011410(unaff_RBX[10],unaff_RBX);
  }
  else {
    DAT_180079890 = 1;
  }
  return 0;
}

/* ---- FUNC 0003C8B3 FUN_18003c8b3 (300 bytes) ---- */

undefined8 FUN_18003c8b3(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  longlong *unaff_RBX;
  int iVar6;
  int unaff_R14D;
  longlong in_stack_00000048;
  
  iVar6 = 0;
  if (0 < unaff_R14D) {
    do {
      iVar2 = HAGetLength(unaff_RBX[9],iVar6,&stack0x00000048);
      iVar3 = HAGetLength(unaff_RBX[9],iVar6,&stack0x00000048);
      iVar1 = 0;
      while (0 < iVar3) {
        in_stack_00000048 = HARemoveLocation(unaff_RBX[9],iVar6,0);
        if (in_stack_00000048 != 0) {
          lVar4 = *unaff_RBX;
          goto LAB_18003c981;
        }
        if (iVar2 * 2 < iVar1) {
          uVar5 = (**(code **)(*unaff_RBX + 0x210))();
          return uVar5;
        }
        iVar3 = HAGetLength(unaff_RBX[9],iVar6);
        iVar1 = iVar1 + 1;
      }
      if (iVar3 == -1) {
        lVar4 = *unaff_RBX;
        if (in_stack_00000048 == 0) {
          uVar5 = (**(code **)(lVar4 + 0x210))();
          return uVar5;
        }
LAB_18003c981:
        uVar5 = (**(code **)(lVar4 + 0x208))();
        return uVar5;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < unaff_R14D);
  }
  *(undefined4 *)(unaff_RBX[10] + 0x100) = 1;
  if (DAT_18007988c == 0) {
    FUN_1800374c0(0x67,unaff_RBX + 0x3b);
    FUN_180011410(unaff_RBX[10],unaff_RBX);
  }
  else {
    DAT_180079890 = 1;
  }
  return 0;
}

/* ---- FUNC 0003C9E0 FUN_18003c9e0 (146 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18003c9e0(longlong param_1)

{
  undefined1 auStack_428 [32];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_180077818 ^ (ulonglong)auStack_428;
  if ((*(int *)(param_1 + 0x164) != 0) && (DAT_180079898 == 0)) {
    FUN_18001b7f0(*(longlong *)(param_1 + 0x50),param_1);
    if (*(int *)(param_1 + 0x164) != 0) {
      FUN_180002a20(local_408,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnode.cpp",0xef5);
      LogMessage(local_408,2,1);
    }
  }
  return 0;
}

/* ---- FUNC 0003CA80 FUN_18003ca80 (143 bytes) ---- */

void FUN_18003ca80(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong *local_res8;
  
  plVar1 = *(longlong **)(param_1 + 0x70);
  if (plVar1 != (longlong *)0x0) {
    if (*(longlong **)(param_1 + 0xe8) == plVar1) {
      local_res8 = param_2;
      (**(code **)(*param_2 + 8))(param_2);
    }
    else {
      FUN_18005b660(plVar1,param_2,*(longlong **)(param_1 + 0xe8),&local_res8);
    }
    if (local_res8 != (longlong *)0x0) {
      (**(code **)(**(longlong **)(param_1 + 0xe8) + 0x10))();
      *(longlong **)(param_1 + 0xe8) = local_res8;
      (**(code **)(**(longlong **)(param_1 + 0x70) + 0x10))();
      (**(code **)(*param_2 + 8))(param_2);
      *(longlong **)(param_1 + 0x70) = param_2;
      FUN_18003d280(param_1,2);
    }
  }
  return;
}

/* ---- FUNC 0003CB10 FUN_18003cb10 (121 bytes) ---- */

undefined8 FUN_18003cb10(longlong *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018003cb2f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x210))(param_1,0x7f3);
    return uVar1;
  }
  if (param_1[9] == 0) {
                    /* WARNING: Could not recover jumptable at 0x00018003cb4a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
    return uVar1;
  }
  if ((DAT_180079800 != (longlong *)0x0) && (param_1[0xc] != 0)) {
    (**(code **)(*DAT_180079800 + 0xb8))(DAT_180079800,param_1,param_2);
  }
  *(undefined4 *)(param_1[10] + 0x100) = 1;
  return 0;
}

/* ---- FUNC 0003CB90 FUN_18003cb90 (741 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HRESULT FUN_18003cb90(longlong *param_1,UINT param_2,int *param_3)

{
  UINT UVar1;
  UINT UVar2;
  UINT UVar3;
  int iVar4;
  HRESULT HVar5;
  LPSTR lpMultiByteStr;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar6;
  char *pcVar7;
  HGLOBAL pvVar8;
  undefined1 auStackY_4b8 [32];
  longlong local_478;
  LPCWSTR local_470;
  IBindCtx *local_468;
  undefined8 local_460;
  IID local_458;
  undefined4 local_448;
  undefined4 local_444;
  undefined4 local_440;
  IID local_438;
  undefined1 local_428 [1008];
  ulonglong local_38;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStackY_4b8;
  if (param_1[0x1d] != 0) {
    UVar1 = RegisterClipboardFormatA("Link Source");
    UVar2 = RegisterClipboardFormatA("Link Source Descriptor");
    UVar3 = RegisterClipboardFormatA("Moniker");
    if (param_2 == UVar2) {
      CreateBindCtx(0,&local_468);
      (**(code **)(*(longlong *)param_1[0x1d] + 0xa0))
                ((longlong *)param_1[0x1d],local_468,0,&local_470);
      lpMultiByteStr = CoTaskMemAlloc(0x200);
      HVar5 = 0;
      WideCharToMultiByte(0,0,local_470,-1,lpMultiByteStr,0x200,(LPCSTR)0x0,(LPBOOL)0x0);
      CoTaskMemFree(local_470);
      (*local_468->lpVtbl->Release)(local_468);
      local_460 = 0;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_478);
      pCVar6 = FUN_180020fe0((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_458,2);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_478,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar6
                );
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_458);
      if (*(int *)(local_478 + -0x10) == 0) {
        HVar5 = -0x7fffbffb;
      }
      else {
        if (param_1[0x2a] == 0) {
          FUN_18003ad30(param_1);
        }
        iVar4 = (**(code **)(*DAT_180079800 + 0x138))(DAT_180079800,&local_438);
        if (iVar4 != 0) {
          FUN_180002a20(local_428,"Assert failed in file %s line %d",
                        "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnode.cpp",0x143d);
          LogMessage(local_428,2,1);
        }
        local_458.Data1 = local_438.Data1;
        local_458.Data2 = local_438.Data2;
        local_458.Data3 = local_438.Data3;
        local_458.Data4[0] = local_438.Data4[0];
        local_458.Data4[1] = local_438.Data4[1];
        local_458.Data4[2] = local_438.Data4[2];
        local_458.Data4[3] = local_438.Data4[3];
        local_458.Data4[4] = local_438.Data4[4];
        local_458.Data4[5] = local_438.Data4[5];
        local_458.Data4[6] = local_438.Data4[6];
        local_458.Data4[7] = local_438.Data4[7];
        pcVar7 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)&local_478);
        pvVar8 = FUN_1800314f0(&local_458.Data1,1,param_1[0x2b],local_460,0x10,pcVar7,lpMultiByteStr
                              );
        *(HGLOBAL *)(param_3 + 2) = pvVar8;
        ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_478,-1);
        if (*(longlong *)(param_3 + 2) == 0) {
          HVar5 = -0x7ff8fff2;
        }
        else {
          CoTaskMemFree(lpMultiByteStr);
          *param_3 = 1;
          param_3[4] = 0;
          param_3[5] = 0;
        }
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_478);
      return HVar5;
    }
    if ((param_2 == UVar1) || (param_2 == UVar3)) {
      *param_3 = 0;
      local_458.Data1._0_2_ = (short)param_2;
      local_448 = 1;
      local_458.Data4[0] = '\0';
      local_458.Data4[1] = '\0';
      local_458.Data4[2] = '\0';
      local_458.Data4[3] = '\0';
      local_458.Data4[4] = '\0';
      local_458.Data4[5] = '\0';
      local_458.Data4[6] = '\0';
      local_458.Data4[7] = '\0';
      local_440 = 4;
      local_444 = 0xffffffff;
      iVar4 = (**(code **)(*DAT_180079800 + 0x138))(DAT_180079800,&local_438);
      if (iVar4 != 0) {
        FUN_180002a20(local_428,"Assert failed in file %s line %d",
                      "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnode.cpp",0x1457);
        LogMessage(local_428,2,1);
      }
      HVar5 = FUN_180031650((LPPERSISTSTREAM)param_1[0x1d],&local_438,(longlong)&local_458,param_3);
      param_3[4] = 0;
      param_3[5] = 0;
      return HVar5;
    }
  }
  return -0x7ffbff9c;
}

/* ---- FUNC 0003CE80 FUN_18003ce80 (232 bytes) ---- */

void FUN_18003ce80(longlong *param_1)

{
  int y;
  HDC hdc;
  HGDIOBJ pvVar1;
  longlong lVar2;
  
  FUN_18003ad30(param_1);
  y = *(int *)((longlong)param_1 + 0x15c);
  lVar2 = param_1[0x2b];
  hdc = CreateMetaFileA((LPCSTR)0x0);
  if (hdc != (HDC)0x0) {
    SetMapMode(hdc,8);
    SetWindowOrgEx(hdc,0,0,(LPPOINT)0x0);
    SetWindowExtEx(hdc,(int)lVar2,y,(LPSIZE)0x0);
    pvVar1 = GetStockObject(7);
    pvVar1 = SelectObject(hdc,pvVar1);
    SetBkMode(hdc,1);
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (((LPCSTR)param_1[0x2a])[lVar2] != '\0');
    TextOutA(hdc,0,0,(LPCSTR)param_1[0x2a],(int)lVar2);
    SelectObject(hdc,pvVar1);
    CloseMetaFile(hdc);
  }
  return;
}

/* ---- FUNC 0003CF70 FUN_18003cf70 (191 bytes) ---- */

undefined8 FUN_18003cf70(longlong *param_1,undefined4 *param_2)

{
  HMETAFILE hmf;
  HGLOBAL hMem;
  undefined8 uVar1;
  undefined4 *puVar2;
  
  hmf = (HMETAFILE)FUN_18003ce80(param_1);
  if (hmf == (HMETAFILE)0x0) {
    return 0x8007000e;
  }
  hMem = GlobalAlloc(0x2002,0x18);
  if (hMem == (HGLOBAL)0x0) {
    DeleteMetaFile(hmf);
    uVar1 = 0x8007000e;
  }
  else {
    puVar2 = GlobalLock(hMem);
    *(HMETAFILE *)(puVar2 + 4) = hmf;
    *puVar2 = 8;
    puVar2[1] = (int)param_1[0x2b];
    puVar2[2] = *(undefined4 *)((longlong)param_1 + 0x15c);
    GlobalUnlock(hMem);
    uVar1 = 0;
    *(HGLOBAL *)(param_2 + 2) = hMem;
    *param_2 = 0x20;
    *(undefined8 *)(param_2 + 4) = 0;
  }
  return uVar1;
}

/* ---- FUNC 0003D030 FUN_18003d030 (90 bytes) ---- */

undefined8 FUN_18003d030(longlong *param_1,undefined4 *param_2)

{
  HGLOBAL hMem;
  undefined8 uVar1;
  char *_Dest;
  size_t _Count;
  size_t sVar2;
  
  FUN_18003ad30(param_1);
  _Count = 0xffffffffffffffff;
  do {
    sVar2 = _Count;
    _Count = sVar2 + 1;
  } while (*(char *)(param_1[0x2a] + _Count) != '\0');
  hMem = GlobalAlloc(0x2002,sVar2 + 2);
  if (hMem == (HGLOBAL)0x0) {
    uVar1 = 0x80030070;
  }
  else {
    _Dest = GlobalLock(hMem);
    strncpy(_Dest,(char *)param_1[0x2a],_Count);
    _Dest[_Count] = '\0';
    GlobalUnlock(hMem);
    uVar1 = 0;
    *(HGLOBAL *)(param_2 + 2) = hMem;
    *param_2 = 1;
    *(undefined8 *)(param_2 + 4) = 0;
  }
  return uVar1;
}

/* ---- FUNC 0003D08A FUN_18003d08a (72 bytes) ---- */

undefined8 FUN_18003d08a(HGLOBAL param_1)

{
  char *_Dest;
  size_t unaff_RBX;
  longlong unaff_RBP;
  HGLOBAL unaff_RSI;
  undefined4 *unaff_R15;
  
  _Dest = GlobalLock(param_1);
  strncpy(_Dest,*(char **)(unaff_RBP + 0x150),unaff_RBX);
  _Dest[unaff_RBX] = '\0';
  GlobalUnlock(unaff_RSI);
  *(HGLOBAL *)(unaff_R15 + 2) = unaff_RSI;
  *unaff_R15 = 1;
  *(undefined8 *)(unaff_R15 + 4) = 0;
  return 0;
}

/* ---- FUNC 0003D0D2 FUN_18003d0d2 (20 bytes) ---- */

void FUN_18003d0d2(void)

{
  return;
}

/* ---- FUNC 0003D0F0 FUN_18003d0f0 (388 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined8 FUN_18003d0f0(longlong *param_1,LPCWSTR param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong *plVar5;
  ulonglong uVar6;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar7;
  undefined1 *puVar8;
  int iVar9;
  undefined8 uStack_60;
  undefined1 auStack_58 [32];
  undefined8 uStack_38;
  int aiStack_30 [2];
  undefined8 local_28 [2];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_18 [8];
  ulonglong local_10;
  longlong lVar4;
  
  puVar8 = auStack_58;
  local_10 = DAT_180077818 ^ (ulonglong)local_18;
  if (DAT_1800797f8 != 0) {
    uStack_60 = 0x18003d12f;
    uVar2 = (**(code **)(*param_1 + 0x210))(param_1,0x7f3);
    puVar8 = auStack_58;
    goto LAB_18003d256;
  }
  if (param_1[9] == 0) {
    uStack_60 = 0x18003d149;
    uVar2 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
    goto LAB_18003d256;
  }
  puVar8 = auStack_58;
  if (param_2 == (LPCWSTR)0x0) {
LAB_18003d1e5:
    pCVar7 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_2[lVar3] != L'\0');
    iVar9 = (int)lVar4 + 2;
    puVar8 = auStack_58;
    if (0x3fffffff < iVar9) goto LAB_18003d1e5;
    lVar3 = (longlong)(int)lVar3 * 2;
    uVar6 = lVar3 + 0x11;
    if (uVar6 <= lVar3 + 2U) {
      uVar6 = 0xffffffffffffff0;
    }
    uStack_60 = 0x18003d1a0;
    lVar3 = -(uVar6 & 0xfffffffffffffff0);
    puVar8 = auStack_58 + lVar3;
    pCVar7 = local_18 + lVar3;
    if (pCVar7 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0)
    goto LAB_18003d1e5;
    *pCVar7 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>)0x0;
    *(undefined8 *)((longlong)local_28 + lVar3 + 8) = 0;
    *(undefined8 *)((longlong)local_28 + lVar3) = 0;
    *(int *)((longlong)aiStack_30 + lVar3) = iVar9 * 2;
    *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
     ((longlong)&uStack_38 + lVar3) = pCVar7;
    *(undefined8 *)(auStack_58 + lVar3 + -8) = 0x18003d1da;
    iVar9 = WideCharToMultiByte(0,0,param_2,-1,*(LPSTR *)((longlong)&uStack_38 + lVar3),
                                *(int *)((longlong)aiStack_30 + lVar3),
                                *(LPCSTR *)((longlong)local_28 + lVar3),
                                *(LPBOOL *)((longlong)local_28 + lVar3 + 8));
    puVar8 = auStack_58 + lVar3;
    if (iVar9 == 0) {
      pCVar7 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
      puVar8 = auStack_58 + lVar3;
    }
  }
  lVar3 = param_1[9];
  *(undefined8 *)(puVar8 + -8) = 0x18003d1f9;
  lVar3 = HAHideReveal(lVar3,1,pCVar7);
  if (lVar3 == 0) {
    *(undefined4 *)(param_1[10] + 0x100) = 1;
    if (DAT_18007988c == 0) {
      *(undefined8 *)(puVar8 + -8) = 0x18003d23d;
      plVar5 = (longlong *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
               CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_18);
      *(undefined8 *)(puVar8 + -8) = 0x18003d24a;
      FUN_1800374c0(0x66,plVar5);
      *(undefined8 *)(puVar8 + -8) = 0x18003d254;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_18);
    }
    else {
      DAT_180079894 = 1;
    }
    uVar2 = 0;
  }
  else {
    pcVar1 = *(code **)(*param_1 + 0x208);
    *(undefined8 *)(puVar8 + -8) = 0x18003d20e;
    uVar2 = (*pcVar1)(param_1,lVar3);
  }
LAB_18003d256:
  *(undefined8 *)(puVar8 + -8) = 0x18003d262;
  return uVar2;
}

/* ---- FUNC 0003D280 FUN_18003d280 (262 bytes) ---- */

void FUN_18003d280(longlong param_1,undefined4 param_2)

{
  longlong *plVar1;
  
  switch(param_2) {
  case 0:
    if (*(longlong **)(param_1 + 0x1c0) != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00018003d2be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(longlong **)(param_1 + 0x1c0) + 0x38))();
      return;
    }
    break;
  case 1:
    if (*(longlong **)(param_1 + 0x1c0) != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00018003d2da. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(longlong **)(param_1 + 0x1c0) + 0x40))();
      return;
    }
    break;
  case 2:
    plVar1 = *(longlong **)(param_1 + 0x1c0);
    if (plVar1 != (longlong *)0x0) {
      (**(code **)(*plVar1 + 0x30))(plVar1,*(undefined8 *)(param_1 + 0xe8));
    }
  case 4:
    plVar1 = *(longlong **)(param_1 + 0x148);
    if (plVar1 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00018003d31b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*plVar1 + 0x30))(plVar1,param_1 + 0x118,0,1);
      return;
    }
    break;
  case 3:
    if (*(longlong **)(param_1 + 0x1b8) != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00018003d333. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(longlong **)(param_1 + 0x1b8) + 0x18))();
      return;
    }
    break;
  case 5:
    plVar1 = *(longlong **)(param_1 + 0x1b8);
    if (plVar1 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00018003d350. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*plVar1 + 0x38))(plVar1,1);
      return;
    }
    break;
  case 6:
    plVar1 = *(longlong **)(param_1 + 0x1b8);
    if (plVar1 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00018003d36a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*plVar1 + 0x38))(plVar1,0);
      return;
    }
    break;
  case 7:
    if (*(longlong **)(param_1 + 0x1b8) != (longlong *)0x0) {
      (**(code **)(**(longlong **)(param_1 + 0x1b8) + 0x30))();
    }
  }
  return;
}

/* ---- FUNC 0003D3B0 FUN_18003d3b0 (1942 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */

HRESULT FUN_18003d3b0(longlong *param_1,VARIANTARG *param_2,VARTYPE param_3,VARIANTARG *param_4)

{
  VARIANTARG *pVVar1;
  ushort uVar2;
  undefined8 *puVar3;
  short *psVar4;
  longlong *plVar5;
  code *pcVar6;
  undefined1 auVar7 [8];
  HRESULT HVar8;
  int iVar9;
  UINT UVar10;
  ULONG UVar11;
  void *_Dst;
  void *pvVar12;
  longlong lVar13;
  ulonglong uVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  VARIANTARG *pVVar17;
  SAFEARRAY *psa;
  LPCWSTR lpWideCharStr;
  VARIANTARG *pVVar19;
  VARTYPE VVar20;
  size_t _Size;
  bool bVar21;
  undefined8 uStack_100;
  undefined1 auStack_f8 [32];
  longlong lStack_d8;
  int aiStack_d0 [2];
  undefined8 local_c8 [2];
  undefined1 local_b8 [16];
  undefined1 local_a8 [8];
  VARIANTARG *local_a0;
  VARIANTARG local_98;
  VARIANTARG *local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 local_58;
  _union_1719 _Stack_50;
  undefined8 local_48;
  ulonglong local_38;
  VARIANTARG *pVVar18;
  
  puVar15 = auStack_f8;
  puVar16 = auStack_f8;
  local_38 = DAT_180077818 ^ (ulonglong)local_b8;
  local_b8._0_2_ = param_3;
  if (DAT_1800797f8 != 0) {
    uStack_100 = 0x18003d415;
    HVar8 = (**(code **)(*param_1 + 0x210))(param_1,0x7f3);
    puVar16 = auStack_f8;
    goto LAB_18003db11;
  }
  pVVar18 = (VARIANTARG *)0x0;
  pVVar17 = (VARIANTARG *)0x0;
  local_a8 = (undefined1  [8])0x0;
  if (param_1[9] == 0) {
    uStack_100 = 0x18003d434;
    HVar8 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
    puVar16 = auStack_f8;
    goto LAB_18003db11;
  }
  uVar2 = (param_4->n1).n2.vt;
  if (uVar2 == 0x400c) {
    puVar3 = *(undefined8 **)((longlong)&param_4->n1 + 8);
    local_78 = *puVar3;
    uStack_70 = puVar3[1];
    local_68 = puVar3[2];
    local_58 = *(undefined8 *)&param_2->n1;
    _Stack_50 = (param_2->n1).decVal.u2;
    local_48 = *(undefined8 *)((longlong)&param_2->n1 + 0x10);
    uStack_100 = 0x18003d481;
    HVar8 = (**(code **)(*param_1 + 0x78))(*(undefined4 *)&param_2->n1,&local_58,param_3,&local_78);
    puVar16 = auStack_f8;
    goto LAB_18003db11;
  }
  if (0xb < uVar2) {
    if (uVar2 == 0x4002) {
      pVVar19 = (VARIANTARG *)(ulonglong)(uint)(int)**(short **)((longlong)&param_4->n1 + 8);
      goto LAB_18003d530;
    }
    if (uVar2 == 0x4003) {
      pVVar19 = (VARIANTARG *)(ulonglong)**(uint **)((longlong)&param_4->n1 + 8);
      goto LAB_18003d530;
    }
    if (uVar2 == 0x400b) {
      pVVar19 = (VARIANTARG *)(ulonglong)(**(short **)((longlong)&param_4->n1 + 8) != 0);
      goto LAB_18003d530;
    }
LAB_18003d4dc:
    uStack_100 = 0x18003d4ef;
    HVar8 = VariantChangeType(&local_98,param_4,0,3);
    if (HVar8 == 0) {
      pVVar19 = (VARIANTARG *)(ulonglong)(uint)local_98.n1._8_4_;
      goto LAB_18003d530;
    }
    goto LAB_18003d4f3;
  }
  if (uVar2 == 0xb) {
    pVVar19 = (VARIANTARG *)(ulonglong)(*(short *)((longlong)&param_4->n1 + 8) != 0);
  }
  else {
    pVVar19 = pVVar18;
    if (uVar2 != 0) {
      if (uVar2 == 2) {
        pVVar19 = (VARIANTARG *)(ulonglong)(uint)(int)*(short *)((longlong)&param_4->n1 + 8);
      }
      else if (uVar2 == 3) {
        pVVar19 = (VARIANTARG *)(ulonglong)*(uint *)((longlong)&param_4->n1 + 8);
      }
      else if (uVar2 != 10) goto LAB_18003d4dc;
    }
  }
LAB_18003d530:
  if ((param_2->n1).n2.vt == 0x400c) {
    puVar3 = *(undefined8 **)((longlong)&param_2->n1 + 8);
    local_58 = *(undefined8 *)&param_4->n1;
    _Stack_50 = (param_4->n1).decVal.u2;
    local_48 = *(undefined8 *)((longlong)&param_4->n1 + 0x10);
    local_78 = *puVar3;
    uStack_70 = puVar3[1];
    local_68 = puVar3[2];
    uStack_100 = 0x18003d571;
    HVar8 = (**(code **)(*param_1 + 0x78))(param_1,&local_78,param_3,&local_58);
    puVar16 = auStack_f8;
    goto LAB_18003db11;
  }
  uStack_100 = 0x18003d580;
  VariantInit(&local_98);
  if (param_1[9] == 0) {
    uStack_100 = 0x18003d59a;
    HVar8 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
    puVar16 = auStack_f8;
    goto LAB_18003db11;
  }
  uStack_100 = 0x18003d5ae;
  iVar9 = HAGetAttrType(param_1[9],0,0,
                        (undefined1 *)((longlong)&(((_union_2707 *)local_b8)->n2).n3.brecVal + 8));
  if (iVar9 == -999) {
    lVar13 = *param_1;
    if (local_a8 == (undefined1  [8])0x0) {
      uStack_100 = 0x18003d5d5;
      HVar8 = (**(code **)(lVar13 + 0x210))(param_1,0x7d1);
      puVar16 = auStack_f8;
      goto LAB_18003db11;
    }
LAB_18003d681:
    uStack_100 = 0x18003d687;
    HVar8 = (**(code **)(lVar13 + 0x208))(param_1);
    puVar16 = auStack_f8;
  }
  else {
    if (iVar9 == 0) {
      uStack_100 = 0x18003d5ef;
      HVar8 = (**(code **)(*param_1 + 0x210))(param_1,0x7e6);
      puVar16 = auStack_f8;
      goto LAB_18003db11;
    }
    uVar2 = (param_2->n1).n2.vt;
    if (uVar2 == 0) {
LAB_18003d659:
      uStack_100 = 0x18003d66b;
      local_a8 = (undefined1  [8])HASetValUnits(param_1[9],0,(int)(short)param_3,pVVar19);
      puVar15 = auStack_f8;
      if (local_a8 != (undefined1  [8])0x0) {
        lVar13 = *param_1;
        goto LAB_18003d681;
      }
    }
    else {
      if ((((uVar2 != 9) && (uVar2 != 0xd)) && (uVar2 != 0x4009)) && (uVar2 != 0x400d)) {
        if (uVar2 == 8) {
          if (((param_2->n1).decVal.u2.Lo64 != 0) &&
             (psVar4 = *(short **)((longlong)&param_2->n1 + 8), psVar4 != (short *)0x0)) {
            bVar21 = *psVar4 == 0;
LAB_18003d657:
            if (!bVar21) goto LAB_18003d692;
          }
        }
        else {
          if (uVar2 != 0x4008) goto LAB_18003d692;
          plVar5 = *(longlong **)((longlong)&param_2->n1 + 8);
          if (plVar5 != (longlong *)0x0) {
            bVar21 = *plVar5 == 0;
            goto LAB_18003d657;
          }
        }
        goto LAB_18003d659;
      }
      if ((param_2->n1).decVal.u2.Lo64 == 0) goto LAB_18003d659;
LAB_18003d692:
      if (iVar9 < 1) {
        VVar20 = local_b8._0_2_;
        if ((uVar2 & 0x4000) == 0) {
          if (iVar9 == -10) {
            VVar20 = 0xd;
          }
          else if (iVar9 == -6) {
            VVar20 = 0xc;
          }
          else if (iVar9 == -3) {
            VVar20 = 8;
          }
          else if (iVar9 == -2) {
            VVar20 = 5;
          }
          else if (iVar9 == -1) {
            VVar20 = 3;
          }
        }
        else if (iVar9 == -10) {
          VVar20 = 0x400d;
        }
        else if (iVar9 == -6) {
          VVar20 = 0x400c;
        }
        else if (iVar9 == -3) {
          VVar20 = 0x4008;
        }
        else if (iVar9 == -2) {
          VVar20 = 0x4005;
        }
        else if (iVar9 == -1) {
          VVar20 = 0x4003;
        }
        uStack_100 = 0x18003d840;
        HVar8 = VariantChangeType(&local_98,param_2,0,VVar20);
        if (HVar8 != 0) {
          uStack_100 = 0x18003d858;
          HVar8 = VariantChangeType(&local_98,param_2,0,VVar20);
          if (HVar8 != 0) goto LAB_18003d4f3;
        }
        if ((uVar2 & 0x4000) == 0) {
          if (iVar9 != -10) {
            if (iVar9 == -6) {
              puVar15 = auStack_f8;
              local_a0 = &local_98;
            }
            else if (iVar9 == -3) {
              lpWideCharStr = (LPCWSTR)CONCAT44(local_98.n1._12_4_,local_98.n1._8_4_);
              puVar15 = auStack_f8;
              local_a0 = pVVar17;
              if (lpWideCharStr != (LPCWSTR)0x0) {
                lVar13 = -1;
                do {
                  lVar13 = lVar13 + 1;
                } while (lpWideCharStr[lVar13] != L'\0');
                goto LAB_18003d8ba;
              }
            }
            else if ((iVar9 == -2) || (iVar9 == -1)) {
              puVar15 = auStack_f8;
              local_a0 = (VARIANTARG *)((longlong)&local_98.n1 + 8);
            }
            goto LAB_18003da4a;
          }
          uStack_100 = 0x18003d9ff;
          iVar9 = (**(code **)**(undefined8 **)CONCAT44(local_98.n1._12_4_,local_98.n1._8_4_))
                            (*(undefined8 **)CONCAT44(local_98.n1._12_4_,local_98.n1._8_4_),
                             &DAT_180063400,&local_a0);
          if (-1 < iVar9) {
            uStack_100 = 0x18003da18;
            (**(code **)(*(longlong *)&local_a0->n1 + 0xd0))
                      (local_a0,&(((_union_2707 *)local_b8)->n2).wReserved2);
            uStack_100 = 0x18003da1e;
            UVar11 = _getpid();
            lVar13 = *(longlong *)&local_a0->n1;
            local_80 = local_a0;
            if (local_b8._4_4_ != UVar11) {
              uStack_100 = 0x18003da2d;
              (**(code **)(lVar13 + 0x10))();
              uStack_100 = 0x18003da3e;
              HVar8 = (**(code **)(*param_1 + 0x210))(param_1,0x7e8);
              goto LAB_18003db11;
            }
            goto LAB_18003da43;
          }
        }
        else {
          if (iVar9 != -10) {
            if (iVar9 == -6) {
LAB_18003d88a:
              puVar15 = auStack_f8;
              local_a0 = (VARIANTARG *)CONCAT44(local_98.n1._12_4_,local_98.n1._8_4_);
            }
            else if (iVar9 == -3) {
              lpWideCharStr = *(LPCWSTR *)CONCAT44(local_98.n1._12_4_,local_98.n1._8_4_);
              puVar15 = auStack_f8;
              local_a0 = pVVar18;
              if (lpWideCharStr != (LPCWSTR)0x0) {
                lVar13 = -1;
                do {
                  lVar13 = lVar13 + 1;
                } while (lpWideCharStr[lVar13] != L'\0');
LAB_18003d8ba:
                iVar9 = (int)lVar13 + 1;
                puVar15 = auStack_f8;
                local_a0 = pVVar17;
                if (iVar9 < 0x40000000) {
                  lVar13 = (longlong)(int)lVar13 * 2;
                  uVar14 = lVar13 + 0x11;
                  if (uVar14 <= lVar13 + 2U) {
                    uVar14 = 0xffffffffffffff0;
                  }
                  uStack_100 = 0x18003d8f2;
                  lVar13 = -(uVar14 & 0xfffffffffffffff0);
                  pVVar1 = (VARIANTARG *)((longlong)local_b8 + lVar13);
                  puVar15 = auStack_f8 + lVar13;
                  if (pVVar1 != (VARIANTARG *)0x0) {
                    *(undefined8 *)((longlong)local_c8 + lVar13 + 8) = 0;
                    *(undefined8 *)((longlong)local_c8 + lVar13) = 0;
                    *(int *)((longlong)aiStack_d0 + lVar13) = iVar9 * 2;
                    *(undefined1 *)&pVVar1->n1 = 0;
                    *(VARIANTARG **)((longlong)&lStack_d8 + lVar13) = pVVar1;
                    *(undefined8 *)(auStack_f8 + lVar13 + -8) = 0x18003d92a;
                    iVar9 = WideCharToMultiByte(0,0,lpWideCharStr,-1,
                                                *(LPSTR *)((longlong)&lStack_d8 + lVar13),
                                                *(int *)((longlong)aiStack_d0 + lVar13),
                                                *(LPCSTR *)((longlong)local_c8 + lVar13),
                                                *(LPBOOL *)((longlong)local_c8 + lVar13 + 8));
                    puVar15 = auStack_f8 + lVar13;
                    local_a0 = pVVar1;
                    if (iVar9 == 0) {
                      puVar15 = auStack_f8 + lVar13;
                      local_a0 = pVVar18;
                    }
                  }
                }
              }
            }
            else if ((iVar9 == -2) || (puVar15 = auStack_f8, iVar9 == -1)) goto LAB_18003d88a;
LAB_18003da4a:
            iVar9 = (int)(short)local_b8._0_2_;
            lVar13 = param_1[9];
            *(undefined8 *)(puVar15 + -8) = 0x18003da5f;
            lVar13 = HASetValUnits(lVar13,local_a0,iVar9,pVVar19);
            local_a8 = (undefined1  [8])lVar13;
            if (lVar13 != 0) {
              pcVar6 = *(code **)(*param_1 + 0x208);
              *(undefined8 *)(puVar15 + -8) = 0x18003da77;
              HVar8 = (*pcVar6)(param_1,lVar13);
              puVar16 = puVar15;
              goto LAB_18003db11;
            }
            goto LAB_18003da7c;
          }
          uStack_100 = 0x18003d94c;
          iVar9 = (*(code *)**(undefined8 **)CONCAT44(local_98.n1._12_4_,local_98.n1._8_4_))
                            ((undefined8 *)CONCAT44(local_98.n1._12_4_,local_98.n1._8_4_),
                             &DAT_180063400,&local_80);
          if (-1 < iVar9) {
            uStack_100 = 0x18003d965;
            (**(code **)(*(longlong *)&local_80->n1 + 0xd0))
                      (local_80,&(((_union_2707 *)local_b8)->n2).n3);
            uStack_100 = 0x18003d96b;
            iVar9 = _getpid();
            lVar13 = *(longlong *)&local_80->n1;
            if (local_b8._8_4_ != iVar9) {
              uStack_100 = 0x18003d97e;
              (**(code **)(lVar13 + 0x10))();
              uStack_100 = 0x18003d98f;
              HVar8 = (**(code **)(*param_1 + 0x210))(param_1,0x7e8);
              puVar16 = auStack_f8;
              goto LAB_18003db11;
            }
LAB_18003da43:
            pVVar17 = *(VARIANTARG **)&local_80[3].n1;
            uStack_100 = 0x18003da4a;
            (**(code **)(lVar13 + 0x10))();
            puVar15 = auStack_f8;
            local_a0 = pVVar17;
            goto LAB_18003da4a;
          }
        }
LAB_18003d4f3:
        uStack_100 = 0x18003d504;
        HVar8 = (**(code **)(*param_1 + 0x210))(param_1,0x7d4);
        puVar16 = auStack_f8;
        goto LAB_18003db11;
      }
      psa = *(SAFEARRAY **)((longlong)&param_2->n1 + 8);
      if ((uVar2 & 0x4000) != 0) {
        psa = *(SAFEARRAY **)psa;
      }
      uStack_100 = 0x18003d6af;
      UVar10 = SafeArrayGetDim(psa);
      if (UVar10 != 1) goto LAB_18003d4f3;
      uStack_100 = 0x18003d6c7;
      SafeArrayGetLBound(psa,1,&(((_union_2707 *)local_b8)->n2).n3.lVal);
      uStack_100 = 0x18003d6d9;
      SafeArrayGetUBound(psa,1,(LONG *)&(((_union_2707 *)local_b8)->n2).wReserved2);
      uStack_100 = 0x18003d6e2;
      UVar10 = SafeArrayGetElemsize(psa);
      _Size = (longlong)(int)(local_b8._4_4_ - local_b8._8_4_) * (ulonglong)UVar10;
      uStack_100 = 0x18003d6f9;
      _Dst = (void *)MDmalloc(_Size);
      if (_Dst == (void *)0x0) {
        uStack_100 = 0x18003d712;
        HVar8 = (**(code **)(*param_1 + 0x210))(param_1,0x7e1);
        puVar16 = auStack_f8;
        goto LAB_18003db11;
      }
      uStack_100 = 0x18003d724;
      HVar8 = SafeArrayAccessData(psa,&local_a0);
      puVar16 = auStack_f8;
      if (HVar8 < 0) goto LAB_18003db11;
      uStack_100 = 0x18003d73b;
      pvVar12 = memcpy(_Dst,local_a0,_Size);
      if (pvVar12 == (void *)0x0) {
        uStack_100 = 0x18003d748;
        MDfree(_Dst);
        uStack_100 = 0x18003d751;
        SafeArrayUnaccessData(psa);
        uStack_100 = 0x18003d762;
        HVar8 = (**(code **)(*param_1 + 0x210))(param_1,0x7d1);
        puVar16 = auStack_f8;
        goto LAB_18003db11;
      }
      uStack_100 = 0x18003d770;
      SafeArrayUnaccessData(psa);
      uStack_100 = 0x18003d785;
      local_a8 = (undefined1  [8])HASetValUnits(param_1[9],_Dst,(int)(short)local_b8._0_2_,pVVar19);
      puVar15 = auStack_f8;
      if (local_a8 != (undefined1  [8])0x0) {
        uStack_100 = 0x18003d7a1;
        HVar8 = (**(code **)(*param_1 + 0x208))(param_1,local_a8);
        puVar16 = auStack_f8;
        goto LAB_18003db11;
      }
    }
LAB_18003da7c:
    auVar7 = local_a8;
    pcVar6 = *(code **)(*param_1 + 0x130);
    *(undefined8 *)(puVar15 + -8) = 0x18003da88;
    (*pcVar6)(param_1,auVar7);
    *(undefined4 *)(param_1[10] + 0x100) = 1;
    *(undefined8 *)(puVar15 + -8) = 0x18003daa3;
    FUN_18003d280((longlong)param_1,4);
    *(undefined8 *)(puVar15 + -8) = 0x18003dab7;
    iVar9 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       (param_1 + 0x3b),"FCVAR1");
    if (iVar9 != 0) {
      *(undefined8 *)(puVar15 + -8) = 0x18003dacf;
      iVar9 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         (param_1 + 0x3b),"FCVAR2");
      if (iVar9 != 0) {
        if (DAT_18007988c == 0) {
          *(undefined8 *)(puVar15 + -8) = 0x18003daf9;
          FUN_1800374c0(0x67,param_1 + 0x3b);
          lVar13 = param_1[10];
          *(undefined8 *)(puVar15 + -8) = 0x18003db05;
          FUN_180011410(lVar13,param_1);
        }
        else {
          DAT_180079890 = 1;
        }
      }
    }
    *(undefined8 *)(puVar15 + -8) = 0x18003db0f;
    VariantClear(&local_98);
    HVar8 = 0;
    puVar16 = puVar15;
  }
LAB_18003db11:
  *(undefined8 *)(puVar16 + -8) = 0x18003db20;
  return HVar8;
}

/* ---- FUNC 0003DB50 FUN_18003db50 (2068 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

ulonglong FUN_18003db50(longlong *param_1,VARIANTARG *param_2,short param_3,wchar_t *param_4,
                       VARIANTARG *param_5)

{
  ushort uVar1;
  undefined8 *puVar2;
  short *psVar3;
  longlong *plVar4;
  VARIANTARG *pVVar5;
  code *pcVar6;
  undefined8 uVar7;
  uint uVar8;
  HRESULT HVar9;
  int iVar10;
  UINT UVar11;
  ulonglong uVar12;
  void *_Dst;
  void *pvVar13;
  longlong lVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  VARTYPE vt;
  SAFEARRAY *psa;
  LPCWSTR lpWideCharStr;
  size_t _Size;
  int iVar19;
  undefined4 uVar20;
  bool bVar21;
  undefined8 uStack_100;
  undefined1 auStack_f8 [32];
  undefined8 *local_d8;
  int aiStack_d0 [2];
  undefined8 local_c8 [2];
  undefined1 local_b8 [16];
  undefined8 local_a8;
  VARIANTARG *local_a0;
  VARIANTARG local_98;
  VARIANTARG *local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 local_58;
  _union_1719 _Stack_50;
  undefined8 local_48;
  ulonglong local_38;
  
  puVar15 = auStack_f8;
  puVar17 = auStack_f8;
  puVar16 = auStack_f8;
  puVar18 = auStack_f8;
  local_38 = DAT_180077818 ^ (ulonglong)local_b8;
  iVar19 = (int)param_3;
  if (DAT_1800797f8 != 0) {
    uStack_100 = 0x18003dbb0;
    uVar12 = (**(code **)(*param_1 + 0x210))(param_1,0x7f3);
    puVar18 = auStack_f8;
    goto LAB_18003e32f;
  }
  local_b8._8_8_ = 0;
  uStack_100 = 0x18003dbc9;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_a8,param_4);
  if (param_1[9] == 0) {
LAB_18003dd2b:
    uStack_100 = 0x18003dd3c;
    uVar8 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
    uVar12 = (ulonglong)uVar8;
    puVar18 = auStack_f8;
  }
  else {
    uVar1 = (param_5->n1).n2.vt;
    if (uVar1 == 0x400c) {
      puVar2 = *(undefined8 **)((longlong)&param_5->n1 + 8);
      local_d8 = &local_78;
      local_78 = *puVar2;
      uStack_70 = puVar2[1];
      local_68 = puVar2[2];
      local_58 = *(undefined8 *)&param_2->n1;
      _Stack_50 = (param_2->n1).decVal.u2;
      local_48 = *(undefined8 *)((longlong)&param_2->n1 + 0x10);
      uStack_100 = 0x18003dc31;
      uVar8 = (**(code **)(*param_1 + 0x80))(param_1,&local_58,param_3,param_4);
      uVar12 = (ulonglong)uVar8;
      puVar18 = auStack_f8;
    }
    else {
      if (0xb < uVar1) {
        if (uVar1 == 0x4002) {
          uVar20 = (int)**(short **)((longlong)&param_5->n1 + 8);
          goto LAB_18003dcc5;
        }
        if (uVar1 == 0x4003) {
          uVar20 = **(uint **)((longlong)&param_5->n1 + 8);
          goto LAB_18003dcc5;
        }
        if (uVar1 == 0x400b) {
          uVar20 = (uint)(**(short **)((longlong)&param_5->n1 + 8) != 0);
          goto LAB_18003dcc5;
        }
LAB_18003dc85:
        uStack_100 = 0x18003dc98;
        HVar9 = VariantChangeType(&local_98,param_5,0,3);
        uVar20 = local_98.n1._8_4_;
        if (HVar9 == 0) goto LAB_18003dcc5;
        goto LAB_18003e1d1;
      }
      if (uVar1 == 0xb) {
        uVar20 = (uint)(*(short *)((longlong)&param_5->n1 + 8) != 0);
      }
      else {
        uVar20 = 0;
        if (uVar1 != 0) {
          if (uVar1 == 2) {
            uVar20 = (int)*(short *)((longlong)&param_5->n1 + 8);
          }
          else if (uVar1 == 3) {
            uVar20 = *(uint *)((longlong)&param_5->n1 + 8);
          }
          else if (uVar1 != 10) goto LAB_18003dc85;
        }
      }
LAB_18003dcc5:
      if ((param_2->n1).n2.vt == 0x400c) {
        puVar2 = *(undefined8 **)((longlong)&param_2->n1 + 8);
        local_d8 = &local_58;
        local_58 = *(undefined8 *)&param_5->n1;
        _Stack_50 = (param_5->n1).decVal.u2;
        local_48 = *(undefined8 *)((longlong)&param_5->n1 + 0x10);
        local_78 = *puVar2;
        uStack_70 = puVar2[1];
        local_68 = puVar2[2];
        uStack_100 = 0x18003dd11;
        uVar8 = (**(code **)(*param_1 + 0x80))(param_1,&local_78,param_3,param_4);
        uVar12 = (ulonglong)uVar8;
        puVar18 = auStack_f8;
      }
      else {
        uStack_100 = 0x18003dd22;
        VariantInit(&local_98);
        if (param_1[9] == 0) goto LAB_18003dd2b;
        uStack_100 = 0x18003dd52;
        iVar10 = HAGetAttrType(param_1[9],0,0,local_b8 + 8);
        if (iVar10 == -999) {
          lVar14 = *param_1;
          puVar16 = auStack_f8;
          if (local_b8._8_8_ == 0) {
            uStack_100 = 0x18003dd79;
            uVar8 = (**(code **)(lVar14 + 0x210))(param_1,0x7d1);
            uVar12 = (ulonglong)uVar8;
            puVar18 = auStack_f8;
          }
          else {
LAB_18003e25b:
            pcVar6 = *(code **)(lVar14 + 0x208);
            *(undefined8 *)(puVar16 + -8) = 0x18003e261;
            uVar8 = (*pcVar6)(param_1);
            uVar12 = (ulonglong)uVar8;
            puVar18 = puVar16;
          }
        }
        else if (iVar10 == 0) {
          uStack_100 = 0x18003dd95;
          uVar8 = (**(code **)(*param_1 + 0x210))(param_1,0x7e6);
          uVar12 = (ulonglong)uVar8;
          puVar18 = auStack_f8;
        }
        else {
          uVar1 = (param_2->n1).n2.vt;
          if (uVar1 == 0) {
LAB_18003e268:
            local_d8 = (undefined8 *)CONCAT44(local_d8._4_4_,uVar20);
            uStack_100 = 0x18003e280;
            local_b8._8_8_ = HASetValUnitsBasis(param_1[9],0,iVar19,local_a8);
            if (local_b8._8_8_ != 0) {
LAB_18003e255:
              lVar14 = *param_1;
              goto LAB_18003e25b;
            }
          }
          else {
            vt = 0x400d;
            if ((((uVar1 == 9) || (uVar1 == 0xd)) || (uVar1 == 0x4009)) || (uVar1 == 0x400d)) {
              if ((param_2->n1).decVal.u2.Lo64 == 0) goto LAB_18003e268;
LAB_18003de50:
              if (0 < iVar10) {
                psa = *(SAFEARRAY **)((longlong)&param_2->n1 + 8);
                if ((uVar1 & 0x4000) != 0) {
                  psa = *(SAFEARRAY **)psa;
                }
                uStack_100 = 0x18003de6d;
                UVar11 = SafeArrayGetDim(psa);
                if (UVar11 == 1) {
                  uStack_100 = 0x18003de85;
                  SafeArrayGetLBound(psa,1,(LONG *)(local_b8 + 4));
                  uStack_100 = 0x18003de97;
                  SafeArrayGetUBound(psa,1,(LONG *)local_b8);
                  uStack_100 = 0x18003dea0;
                  UVar11 = SafeArrayGetElemsize(psa);
                  _Size = (longlong)(int)(local_b8._0_4_ - local_b8._4_4_) * (ulonglong)UVar11;
                  uStack_100 = 0x18003deb7;
                  _Dst = (void *)MDmalloc(_Size);
                  if (_Dst == (void *)0x0) {
                    uStack_100 = 0x18003ded0;
                    uVar8 = (**(code **)(*param_1 + 0x210))(param_1,0x7e1);
                    uVar12 = (ulonglong)uVar8;
                    puVar18 = auStack_f8;
                  }
                  else {
                    uStack_100 = 0x18003dee4;
                    uVar8 = SafeArrayAccessData(psa,&local_a0);
                    uVar12 = (ulonglong)uVar8;
                    puVar18 = auStack_f8;
                    if (-1 < (int)uVar8) {
                      uStack_100 = 0x18003defd;
                      pvVar13 = memcpy(_Dst,local_a0,_Size);
                      if (pvVar13 == (void *)0x0) {
                        uStack_100 = 0x18003df0a;
                        MDfree(_Dst);
                        uStack_100 = 0x18003df13;
                        SafeArrayUnaccessData(psa);
                        uStack_100 = 0x18003df24;
                        uVar8 = (**(code **)(*param_1 + 0x210))(param_1,0x7d1);
                        uVar12 = (ulonglong)uVar8;
                        puVar18 = auStack_f8;
                      }
                      else {
                        uStack_100 = 0x18003df34;
                        SafeArrayUnaccessData(psa);
                        local_d8 = (undefined8 *)CONCAT44(local_d8._4_4_,uVar20);
                        uStack_100 = 0x18003df4d;
                        local_b8._8_8_ = HASetValUnitsBasis(param_1[9],_Dst,iVar19,local_a8);
                        puVar17 = auStack_f8;
                        if (local_b8._8_8_ == 0) goto LAB_18003e28e;
                        uStack_100 = 0x18003df69;
                        uVar8 = (**(code **)(*param_1 + 0x208))(param_1,local_b8._8_8_);
                        uVar12 = (ulonglong)uVar8;
                        puVar18 = auStack_f8;
                      }
                    }
                  }
                  goto LAB_18003e323;
                }
LAB_18003e1d1:
                uStack_100 = 0x18003e1e2;
                uVar8 = (**(code **)(*param_1 + 0x210))(param_1,0x7d4);
                uVar12 = (ulonglong)uVar8;
                puVar18 = auStack_f8;
                goto LAB_18003e323;
              }
              if ((uVar1 & 0x4000) == 0) {
                if (iVar10 == -10) {
                  vt = 0xd;
                }
                else if (iVar10 == -6) {
                  vt = 0xc;
                }
                else if (iVar10 == -3) {
                  vt = 8;
                }
                else if (iVar10 == -2) {
                  vt = 5;
                }
                else {
                  if (iVar10 != -1) goto LAB_18003dfc6;
                  vt = 3;
                }
              }
              else if (iVar10 != -10) {
                if (iVar10 == -6) {
                  vt = 0x400c;
                }
                else if (iVar10 == -3) {
                  vt = 0x4008;
                }
                else if (iVar10 == -2) {
                  vt = 0x4005;
                }
                else if (iVar10 == -1) {
                  vt = 0x4003;
                }
                else {
LAB_18003dfc6:
                  vt = (VARTYPE)local_b8._0_4_;
                }
              }
              uStack_100 = 0x18003dffa;
              HVar9 = VariantChangeType(&local_98,param_2,0,vt);
              if (HVar9 != 0) {
                uStack_100 = 0x18003e012;
                HVar9 = VariantChangeType(&local_98,param_2,0,vt);
                if (HVar9 != 0) goto LAB_18003e1d1;
              }
              if ((uVar1 & 0x4000) == 0) {
                if (iVar10 == -10) {
                  uStack_100 = 0x18003e1cd;
                  iVar10 = (**(code **)**(undefined8 **)
                                         CONCAT44(local_98.n1._12_4_,local_98.n1._8_4_))
                                     (*(undefined8 **)CONCAT44(local_98.n1._12_4_,local_98.n1._8_4_)
                                      ,&DAT_180063400,&local_a0);
                  if (-1 < iVar10) {
                    uStack_100 = 0x18003e1fa;
                    (**(code **)(*(longlong *)&local_a0->n1 + 0xd0))(local_a0,local_b8);
                    uStack_100 = 0x18003e200;
                    iVar10 = _getpid();
                    lVar14 = *(longlong *)&local_a0->n1;
                    local_80 = local_a0;
                    if (local_b8._0_4_ == iVar10) goto LAB_18003e227;
                    uStack_100 = 0x18003e20f;
                    (**(code **)(lVar14 + 0x10))();
                    uStack_100 = 0x18003e220;
                    uVar8 = (**(code **)(*param_1 + 0x210))(param_1,0x7e8);
                    uVar12 = (ulonglong)uVar8;
                    goto LAB_18003e323;
                  }
                  goto LAB_18003e1d1;
                }
                if (iVar10 == -6) {
                  puVar16 = auStack_f8;
                  local_a0 = &local_98;
                }
                else if (iVar10 == -3) {
                  lpWideCharStr = (LPCWSTR)CONCAT44(local_98.n1._12_4_,local_98.n1._8_4_);
                  if (lpWideCharStr != (LPCWSTR)0x0) {
                    lVar14 = -1;
                    do {
                      lVar14 = lVar14 + 1;
                    } while (lpWideCharStr[lVar14] != L'\0');
                    goto LAB_18003e07b;
                  }
                  puVar16 = auStack_f8;
                  local_a0 = (VARIANTARG *)0x0;
                }
                else if ((iVar10 == -2) || (puVar16 = auStack_f8, iVar10 == -1)) {
                  puVar16 = auStack_f8;
                  local_a0 = (VARIANTARG *)((longlong)&local_98.n1 + 8);
                }
              }
              else if (iVar10 == -10) {
                uStack_100 = 0x18003e10d;
                iVar10 = (*(code *)**(undefined8 **)CONCAT44(local_98.n1._12_4_,local_98.n1._8_4_))
                                   ((undefined8 *)CONCAT44(local_98.n1._12_4_,local_98.n1._8_4_),
                                    &DAT_180063400,&local_80);
                if (iVar10 < 0) goto LAB_18003e1d1;
                uStack_100 = 0x18003e126;
                (**(code **)(*(longlong *)&local_80->n1 + 0xd0))(local_80,local_b8 + 4);
                uStack_100 = 0x18003e12c;
                iVar10 = _getpid();
                lVar14 = *(longlong *)&local_80->n1;
                if (local_b8._4_4_ != iVar10) {
                  uStack_100 = 0x18003e13f;
                  (**(code **)(lVar14 + 0x10))();
                  uStack_100 = 0x18003e150;
                  uVar8 = (**(code **)(*param_1 + 0x210))(param_1,0x7e8);
                  uVar12 = (ulonglong)uVar8;
                  puVar18 = auStack_f8;
                  goto LAB_18003e323;
                }
LAB_18003e227:
                pVVar5 = *(VARIANTARG **)&local_80[3].n1;
                uStack_100 = 0x18003e22e;
                (**(code **)(lVar14 + 0x10))();
                puVar16 = auStack_f8;
                local_a0 = pVVar5;
              }
              else {
                if (iVar10 != -6) {
                  if (iVar10 == -3) {
                    lpWideCharStr = *(LPCWSTR *)CONCAT44(local_98.n1._12_4_,local_98.n1._8_4_);
                    if (lpWideCharStr == (LPCWSTR)0x0) {
LAB_18003e05b:
                      puVar16 = puVar15;
                      local_a0 = (VARIANTARG *)0x0;
                    }
                    else {
                      lVar14 = -1;
                      do {
                        lVar14 = lVar14 + 1;
                      } while (lpWideCharStr[lVar14] != L'\0');
LAB_18003e07b:
                      iVar10 = (int)lVar14 + 1;
                      if (iVar10 < 0x40000000) {
                        lVar14 = (longlong)(int)lVar14 * 2;
                        uVar12 = lVar14 + 0x11;
                        if (uVar12 <= lVar14 + 2U) {
                          uVar12 = 0xffffffffffffff0;
                        }
                        uStack_100 = 0x18003e0b8;
                        lVar14 = -(uVar12 & 0xfffffffffffffff0);
                        puVar15 = auStack_f8 + lVar14;
                        pVVar5 = (VARIANTARG *)(local_b8 + lVar14);
                        if (pVVar5 == (VARIANTARG *)0x0) goto LAB_18003e05b;
                        *(undefined8 *)((longlong)local_c8 + lVar14 + 8) = 0;
                        *(undefined8 *)((longlong)local_c8 + lVar14) = 0;
                        *(int *)((longlong)aiStack_d0 + lVar14) = iVar10 * 2;
                        *(VARIANTARG **)((longlong)aiStack_d0 + lVar14 + -8) = pVVar5;
                        *(undefined1 *)&pVVar5->n1 = 0;
                        *(undefined8 *)(auStack_f8 + lVar14 + -8) = 0x18003e0ee;
                        iVar10 = WideCharToMultiByte(0,0,lpWideCharStr,-1,
                                                     *(LPSTR *)((longlong)aiStack_d0 + lVar14 + -8),
                                                     *(int *)((longlong)aiStack_d0 + lVar14),
                                                     *(LPCSTR *)((longlong)local_c8 + lVar14),
                                                     *(LPBOOL *)((longlong)local_c8 + lVar14 + 8));
                        puVar16 = auStack_f8 + lVar14;
                        local_a0 = pVVar5;
                        if (iVar10 == 0) {
                          puVar16 = auStack_f8 + lVar14;
                          local_a0 = (VARIANTARG *)0x0;
                        }
                      }
                      else {
                        puVar16 = auStack_f8;
                        local_a0 = (VARIANTARG *)0x0;
                      }
                    }
                    goto LAB_18003e230;
                  }
                  if ((iVar10 != -2) && (puVar16 = auStack_f8, iVar10 != -1)) goto LAB_18003e230;
                }
                puVar16 = auStack_f8;
                local_a0 = (VARIANTARG *)CONCAT44(local_98.n1._12_4_,local_98.n1._8_4_);
              }
LAB_18003e230:
              lVar14 = param_1[9];
              *(undefined4 *)(puVar16 + 0x20) = uVar20;
              *(undefined8 *)(puVar16 + -8) = 0x18003e249;
              local_b8._8_8_ = HASetValUnitsBasis(lVar14,local_a0,iVar19,local_a8);
              puVar17 = puVar16;
              if (local_b8._8_8_ == 0) goto LAB_18003e28e;
              goto LAB_18003e255;
            }
            if (uVar1 == 8) {
              if (((param_2->n1).decVal.u2.Lo64 != 0) &&
                 (psVar3 = *(short **)((longlong)&param_2->n1 + 8), psVar3 != (short *)0x0)) {
                bVar21 = *psVar3 == 0;
LAB_18003de08:
                if (!bVar21) goto LAB_18003de50;
              }
            }
            else {
              if (uVar1 != 0x4008) goto LAB_18003de50;
              plVar4 = *(longlong **)((longlong)&param_2->n1 + 8);
              if (plVar4 != (longlong *)0x0) {
                bVar21 = *plVar4 == 0;
                goto LAB_18003de08;
              }
            }
            local_d8 = (undefined8 *)CONCAT44(local_d8._4_4_,uVar20);
            uStack_100 = 0x18003de22;
            local_b8._8_8_ = HASetValUnitsBasis(param_1[9],0,iVar19,local_a8);
            puVar17 = auStack_f8;
            if (local_b8._8_8_ != 0) {
              uStack_100 = 0x18003de3e;
              uVar8 = (**(code **)(*param_1 + 0x208))(param_1);
              uVar12 = (ulonglong)uVar8;
              puVar18 = auStack_f8;
              goto LAB_18003e323;
            }
          }
LAB_18003e28e:
          uVar7 = local_b8._8_8_;
          pcVar6 = *(code **)(*param_1 + 0x130);
          *(undefined8 *)(puVar17 + -8) = 0x18003e29a;
          (*pcVar6)(param_1,uVar7);
          *(undefined4 *)(param_1[10] + 0x100) = 1;
          *(undefined8 *)(puVar17 + -8) = 0x18003e2b5;
          FUN_18003d280((longlong)param_1,4);
          *(undefined8 *)(puVar17 + -8) = 0x18003e2c9;
          iVar19 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                             ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                              (param_1 + 0x3b),"FCVAR1");
          if (iVar19 != 0) {
            *(undefined8 *)(puVar17 + -8) = 0x18003e2e1;
            iVar19 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                     CompareNoCase((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                   (param_1 + 0x3b),"FCVAR2");
            if (iVar19 != 0) {
              if (DAT_18007988c == 0) {
                *(undefined8 *)(puVar17 + -8) = 0x18003e30b;
                FUN_1800374c0(0x67,param_1 + 0x3b);
                lVar14 = param_1[10];
                *(undefined8 *)(puVar17 + -8) = 0x18003e317;
                FUN_180011410(lVar14,param_1);
              }
              else {
                DAT_180079890 = 1;
              }
            }
          }
          *(undefined8 *)(puVar17 + -8) = 0x18003e321;
          VariantClear(&local_98);
          uVar12 = 0;
          puVar18 = puVar17;
        }
      }
    }
  }
LAB_18003e323:
  *(undefined8 *)(puVar18 + -8) = 0x18003e32d;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_a8);
LAB_18003e32f:
  *(undefined8 *)(puVar18 + -8) = 0x18003e33e;
  return uVar12;
}

/* ---- FUNC 0003E370 FUN_18003e370 (229 bytes) ---- */

undefined8 FUN_18003e370(short param_1)

{
  int iVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res10 [24];
  
  iVar1 = DAT_180079890;
  if (param_1 == 0) {
    if (DAT_18007988c != 0) {
      if (DAT_180079890 != 0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10);
        FUN_1800374c0(0x67,(longlong *)local_res10);
        FUN_180011410(DAT_1800797f0,0);
        DAT_180079890 = 0;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10);
      }
      if (DAT_180079894 != 0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10);
        FUN_1800374c0(0x72,(longlong *)local_res10);
        if (iVar1 == 0) {
          FUN_18001bec0(DAT_1800797f0);
        }
        DAT_180079894 = 0;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10);
      }
      DAT_18007988c = 0;
      return 0;
    }
  }
  else if (DAT_18007988c == 0) {
    DAT_18007988c = 1;
    return 0;
  }
  return 1;
}

/* ---- FUNC 0003E460 FUN_18003e460 (558 bytes) ---- */

longlong * FUN_18003e460(longlong *param_1,longlong *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  longlong lVar3;
  int iVar4;
  ulonglong uVar5;
  void *_Dst;
  longlong *plVar6;
  longlong *plVar7;
  size_t _MaxCount;
  
  _Dst = (void *)0x0;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  plVar7 = param_2;
  if (0xf < (ulonglong)param_2[3]) {
    plVar7 = (longlong *)*param_2;
  }
  uVar2 = param_2[2];
  if (0x7fffffffffffffff < uVar2) {
                    /* WARNING: Subroutine does not return */
    FUN_180002780();
  }
  param_1[3] = 0xf;
  if (uVar2 < 0x10) {
    param_1[2] = uVar2;
    lVar3 = plVar7[1];
    *param_1 = *plVar7;
    param_1[1] = lVar3;
  }
  else {
    uVar5 = uVar2 | 0xf;
    if (uVar5 < 0x8000000000000000) {
      if (uVar5 < 0x16) {
        uVar5 = 0x16;
      }
      uVar1 = uVar5 + 1;
      if (uVar1 < 0x1000) {
        if (uVar1 != 0) {
          _Dst = operator_new(uVar1);
        }
      }
      else {
        _Dst = (void *)FUN_180001160(uVar1);
      }
    }
    else {
      _Dst = (void *)FUN_180001160(0x8000000000000000);
      uVar5 = 0x7fffffffffffffff;
    }
    *param_1 = (longlong)_Dst;
    param_1[2] = uVar2;
    param_1[3] = uVar5;
    memcpy(_Dst,plVar7,uVar2 + 1);
  }
  do {
    plVar7 = param_1;
    if (0xf < (ulonglong)param_1[3]) {
      plVar7 = (longlong *)*param_1;
    }
    uVar2 = param_1[2];
    if (0xb < uVar2) {
      _MaxCount = uVar2 - 0xb;
      plVar6 = plVar7;
      while (plVar6 = memchr(plVar6,0x44,_MaxCount), plVar6 != (longlong *)0x0) {
        if ((*plVar6 == 0x6f6c422e61746144) && ((int)plVar6[1] == 0x2e736b63)) {
          iVar4 = (int)plVar6 - (int)plVar7;
          goto LAB_18003e5ad;
        }
        plVar6 = (longlong *)((longlong)plVar6 + 1);
        _MaxCount = (longlong)plVar7 + ((uVar2 - 0xb) - (longlong)plVar6);
      }
    }
    iVar4 = -1;
LAB_18003e5ad:
    if (iVar4 < 0) break;
    FUN_1800419f0(param_1,(longlong)iVar4,0xc,&DAT_18006271e,0);
  } while( true );
  plVar7 = param_1;
  if (0xf < (ulonglong)param_1[3]) {
    plVar7 = (longlong *)*param_1;
  }
  if (0xc < uVar2) {
    for (plVar6 = memchr(plVar7,0x44,uVar2 - 0xc); plVar6 != (longlong *)0x0;
        plVar6 = memchr((void *)((longlong)plVar6 + 1),0x44,
                        (longlong)plVar7 + ((uVar2 - 0xc) - ((longlong)plVar6 + 1)))) {
      if (((*plVar6 == 0x7274532e61746144) && ((int)plVar6[1] == 0x736d6165)) &&
         (*(char *)((longlong)plVar6 + 0xc) == '.')) {
        iVar4 = (int)plVar6 - (int)plVar7;
        goto LAB_18003e647;
      }
    }
  }
  iVar4 = -1;
LAB_18003e647:
  if (-1 < iVar4) {
    FUN_1800419f0(param_1,(longlong)iVar4,0xd,&DAT_18006271e,0);
  }
  return param_1;
}

/* ---- FUNC 0003E690 FUN_18003e690 (232 bytes) ---- */

undefined8 FUN_18003e690(longlong param_1,ulonglong param_2)

{
  char cVar1;
  char cVar2;
  ulonglong *puVar3;
  ulonglong *puVar4;
  longlong lVar5;
  ulonglong *puVar6;
  ulonglong *puVar7;
  ulonglong *local_18;
  ulonglong *puStack_10;
  
  puStack_10 = *(ulonglong **)(param_1 + 0x1e0);
  puVar3 = (ulonglong *)puStack_10[1];
  cVar1 = *(char *)((longlong)puVar3 + 0x19);
  puVar4 = puStack_10;
  puVar7 = puVar3;
  cVar2 = cVar1;
  while (cVar2 == '\0') {
    if (puVar7[4] < param_2) {
      puVar6 = (ulonglong *)puVar7[2];
      puVar7 = puVar4;
    }
    else {
      puVar6 = (ulonglong *)*puVar7;
    }
    puVar4 = puVar7;
    puVar7 = puVar6;
    cVar2 = *(char *)((longlong)puVar6 + 0x19);
  }
  if (((*(char *)((longlong)puVar4 + 0x19) == '\0') && (puVar4[4] <= param_2)) &&
     (local_18 = puStack_10, puVar7 = puVar3, puVar4 != puStack_10)) {
    while (cVar1 == '\0') {
      if (puVar7[4] < param_2) {
        puVar4 = (ulonglong *)puVar7[2];
        puVar7 = local_18;
      }
      else {
        if ((*(char *)((longlong)puStack_10 + 0x19) != '\0') && (param_2 < puVar7[4])) {
          puStack_10 = puVar7;
        }
        puVar4 = (ulonglong *)*puVar7;
      }
      local_18 = puVar7;
      puVar7 = puVar4;
      cVar1 = *(char *)((longlong)puVar4 + 0x19);
    }
    if (*(char *)((longlong)puStack_10 + 0x19) == '\0') {
      puVar3 = (ulonglong *)*puStack_10;
    }
    cVar2 = *(char *)((longlong)puVar3 + 0x19);
    while (cVar2 == '\0') {
      if (param_2 < puVar3[4]) {
        puVar4 = (ulonglong *)*puVar3;
        puStack_10 = puVar3;
      }
      else {
        puVar4 = (ulonglong *)puVar3[2];
      }
      puVar3 = puVar4;
      cVar2 = *(char *)((longlong)puVar4 + 0x19);
    }
    lVar5 = FUN_18003e9e0((longlong *)(param_1 + 0x1e0),(longlong *)&local_18);
    return CONCAT71((int7)((ulonglong)lVar5 >> 8),1);
  }
  return (ulonglong)puVar3 & 0xffffffffffffff00;
}

/* ---- FUNC 0003E780 FUN_18003e780 (21 bytes) ---- */

undefined * FUN_18003e780(longlong param_1,int param_2,int param_3)

{
  undefined *puVar1;
  
  if (DAT_1800797f8 != 0) {
    return (undefined *)0x0;
  }
  puVar1 = FUN_18001d4a0(*(longlong *)(param_1 + 0x50),param_2,param_3);
  return puVar1;
}

/* ---- FUNC 0003E7A0 FUN_18003e7a0 (284 bytes) ---- */

undefined8 FUN_18003e7a0(longlong param_1,IUnknown *param_2,int param_3)

{
  IUnknown *pIVar1;
  longlong lVar2;
  int iVar3;
  longlong *plVar4;
  longlong *local_res8;
  
  pIVar1 = *(IUnknown **)(param_1 + 0x60);
  if (pIVar1 != (IUnknown *)0x0) {
    if (param_3 == 0) {
      FUN_18003b0a0((longlong *)pIVar1,0);
    }
    else {
      FUN_180018e30(pIVar1,0,1);
    }
    iVar3 = (**(code **)**(undefined8 **)(param_1 + 0x60))
                      (*(undefined8 **)(param_1 + 0x60),&DAT_180066db8,&local_res8);
    if (-1 < iVar3) {
      (**(code **)(*local_res8 + 0xa0))(local_res8,*(undefined4 *)(param_1 + 0x1d0));
      (**(code **)(*local_res8 + 0x10))();
    }
  }
  *(int *)(param_1 + 0x68) = param_3;
  *(IUnknown **)(param_1 + 0x60) = param_2;
  if (param_2 != (IUnknown *)0x0) {
    if (param_3 == 0) {
      FUN_18003b0a0((longlong *)param_2,1);
    }
    else {
      FUN_180018e30(param_2,1,1);
    }
    iVar3 = (**(code **)**(undefined8 **)(param_1 + 0x60))
                      (*(undefined8 **)(param_1 + 0x60),&DAT_180066db8,&local_res8);
    if (-1 < iVar3) {
      if (*(int *)(param_1 + 0x1d0) == 0) {
        (**(code **)(*local_res8 + 0x98))(local_res8,*(undefined8 *)(param_1 + 0x1c8));
      }
      (**(code **)(*local_res8 + 0x10))();
    }
    lVar2 = *(longlong *)(param_1 + 0x60);
    if (lVar2 != 0) {
      if (*(int *)(param_1 + 0x68) == 0) {
        plVar4 = *(longlong **)(lVar2 + 0xe8);
      }
      else {
        plVar4 = *(longlong **)(lVar2 + 0x118);
      }
      FUN_18003ca80(param_1,plVar4);
    }
  }
  return 1;
}

/* ---- FUNC 0003E8C0 FUN_18003e8c0 (287 bytes) ---- */

ulonglong FUN_18003e8c0(longlong param_1,ulonglong param_2)

{
  ulonglong *puVar1;
  char cVar2;
  char cVar3;
  ulonglong *puVar4;
  code *pcVar5;
  ulonglong *puVar6;
  ulonglong *puVar7;
  undefined8 uVar8;
  ulonglong *puVar9;
  ulonglong *puVar10;
  ulonglong *local_38;
  undefined8 uStack_30;
  ulonglong *local_28;
  uint uStack_20;
  undefined4 uStack_1c;
  
  puVar1 = (ulonglong *)(param_1 + 0x1e0);
  puVar4 = (ulonglong *)*puVar1;
  puVar6 = (ulonglong *)puVar4[1];
  cVar2 = *(char *)((longlong)puVar6 + 0x19);
  puVar10 = puVar4;
  puVar7 = puVar6;
  cVar3 = cVar2;
  while (cVar3 == '\0') {
    if (puVar7[4] < param_2) {
      puVar9 = (ulonglong *)puVar7[2];
      puVar7 = puVar10;
    }
    else {
      puVar9 = (ulonglong *)*puVar7;
    }
    puVar10 = puVar7;
    puVar7 = puVar9;
    cVar3 = *(char *)((longlong)puVar9 + 0x19);
  }
  if (((*(char *)((longlong)puVar10 + 0x19) == '\0') && (puVar10[4] <= param_2)) &&
     (puVar10 != puVar4)) {
    return (ulonglong)puVar6 & 0xffffffffffffff00;
  }
  uStack_20 = 0;
  puVar10 = puVar4;
  local_28 = puVar6;
  while (puVar7 = puVar6, cVar2 == '\0') {
    if (param_2 <= puVar7[4]) {
      puVar6 = (ulonglong *)*puVar7;
      puVar10 = puVar7;
    }
    else {
      puVar6 = (ulonglong *)puVar7[2];
    }
    uStack_20 = (uint)(param_2 <= puVar7[4]);
    cVar2 = *(char *)((longlong)puVar6 + 0x19);
    local_28 = puVar7;
  }
  if ((*(char *)((longlong)puVar10 + 0x19) != '\0') || (param_2 < puVar10[4])) {
    if (*(longlong *)(param_1 + 0x1e8) == 0x666666666666666) {
      FUN_18003f2b0();
      pcVar5 = (code *)swi(3);
      uVar8 = (*pcVar5)();
      return uVar8;
    }
    uStack_30 = 0;
    local_38 = puVar1;
    puVar6 = operator_new(0x28);
    puVar6[4] = param_2;
    *puVar6 = (ulonglong)puVar4;
    puVar6[1] = (ulonglong)puVar4;
    puVar6[2] = (ulonglong)puVar4;
    *(undefined2 *)(puVar6 + 3) = 0;
    uStack_30 = CONCAT44(uStack_1c,uStack_20);
    local_38 = local_28;
    puVar7 = (ulonglong *)FUN_18003ef90((longlong *)puVar1,(longlong *)&local_38,(longlong *)puVar6)
    ;
  }
  return CONCAT71((int7)((ulonglong)puVar7 >> 8),1);
}

/* ---- FUNC 0003E9E0 FUN_18003e9e0 (456 bytes) ---- */

longlong FUN_18003e9e0(longlong *param_1,longlong *param_2)

{
  char cVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong lVar9;
  
  plVar7 = (longlong *)*param_2;
  lVar9 = 0;
  plVar2 = (longlong *)param_2[1];
  plVar4 = plVar7;
  while (plVar4 != plVar2) {
    plVar8 = (longlong *)plVar4[2];
    lVar9 = lVar9 + 1;
    if (*(char *)((longlong)plVar8 + 0x19) == '\0') {
      cVar1 = *(char *)(*plVar8 + 0x19);
      plVar4 = plVar8;
      plVar8 = (longlong *)*plVar8;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*plVar8 + 0x19);
        plVar4 = plVar8;
        plVar8 = (longlong *)*plVar8;
      }
    }
    else {
      cVar1 = *(char *)(plVar4[1] + 0x19);
      plVar6 = (longlong *)plVar4[1];
      plVar8 = plVar4;
      while ((plVar4 = plVar6, cVar1 == '\0' && (plVar8 == (longlong *)plVar4[2]))) {
        cVar1 = *(char *)(plVar4[1] + 0x19);
        plVar6 = (longlong *)plVar4[1];
        plVar8 = plVar4;
      }
    }
  }
  puVar3 = (undefined8 *)*param_1;
  if ((plVar7 == (longlong *)*puVar3) && (*(char *)((longlong)plVar2 + 0x19) != '\0')) {
    cVar1 = *(char *)((longlong)puVar3[1] + 0x19);
    plVar7 = (longlong *)puVar3[1];
    while (cVar1 == '\0') {
      FUN_180037a20(param_1,param_1,(longlong *)plVar7[2]);
      plVar2 = (longlong *)*plVar7;
      FUN_180025ad0(plVar7);
      plVar7 = plVar2;
      cVar1 = *(char *)((longlong)plVar2 + 0x19);
    }
    puVar3[1] = puVar3;
    *puVar3 = puVar3;
    puVar3[2] = puVar3;
    param_1[1] = 0;
  }
  else {
    while (plVar7 != plVar2) {
      plVar4 = (longlong *)plVar7[2];
      if (*(char *)((longlong)plVar4 + 0x19) == '\0') {
        cVar1 = *(char *)(*plVar4 + 0x19);
        plVar8 = plVar4;
        plVar6 = (longlong *)*plVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*plVar6 + 0x19);
          plVar8 = plVar6;
          plVar6 = (longlong *)*plVar6;
        }
        plVar4 = (longlong *)*plVar4;
        cVar1 = *(char *)((longlong)plVar4 + 0x19);
        while (cVar1 == '\0') {
          plVar4 = (longlong *)*plVar4;
          cVar1 = *(char *)((longlong)plVar4 + 0x19);
        }
      }
      else {
        cVar1 = *(char *)(plVar7[1] + 0x19);
        plVar6 = (longlong *)plVar7[1];
        plVar4 = plVar7;
        while ((plVar8 = plVar6, cVar1 == '\0' && (plVar4 == (longlong *)plVar8[2]))) {
          cVar1 = *(char *)(plVar8[1] + 0x19);
          plVar6 = (longlong *)plVar8[1];
          plVar4 = plVar8;
        }
        cVar1 = *(char *)(plVar7[1] + 0x19);
        plVar6 = (longlong *)plVar7[1];
        plVar4 = plVar7;
        while ((plVar5 = plVar6, cVar1 == '\0' && (plVar4 == (longlong *)plVar5[2]))) {
          cVar1 = *(char *)(plVar5[1] + 0x19);
          plVar6 = (longlong *)plVar5[1];
          plVar4 = plVar5;
        }
      }
      plVar7 = FUN_18003ebb0(param_1,plVar7);
      FUN_180025ad0(plVar7);
      plVar7 = plVar8;
    }
  }
  return lVar9;
}

/* ---- FUNC 0003EBB0 FUN_18003ebb0 (19 bytes) ---- */

longlong * FUN_18003ebb0(longlong *param_1,longlong *param_2)

{
  char cVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong *plVar7;
  
  plVar3 = (longlong *)param_2[2];
  plVar4 = param_2 + 2;
  if (*(char *)((longlong)plVar3 + 0x19) == '\0') {
    cVar1 = *(char *)(*plVar3 + 0x19);
    plVar5 = (longlong *)*plVar3;
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*plVar5 + 0x19);
      plVar3 = plVar5;
      plVar5 = (longlong *)*plVar5;
    }
  }
  else {
    cVar1 = *(char *)(param_2[1] + 0x19);
    plVar6 = (longlong *)param_2[1];
    plVar5 = param_2;
    while ((plVar3 = plVar6, cVar1 == '\0' && (plVar5 == (longlong *)plVar3[2]))) {
      cVar1 = *(char *)(plVar3[1] + 0x19);
      plVar6 = (longlong *)plVar3[1];
      plVar5 = plVar3;
    }
  }
  plVar7 = param_2 + 1;
  plVar5 = (longlong *)*param_2;
  plVar6 = (longlong *)*plVar4;
  if (((*(char *)((longlong)plVar5 + 0x19) == '\0') &&
      (plVar6 = plVar5, *(char *)(*plVar4 + 0x19) == '\0')) &&
     (plVar6 = (longlong *)plVar3[2], plVar3 != param_2)) {
    plVar5[1] = (longlong)plVar3;
    *plVar3 = *param_2;
    plVar5 = plVar3;
    if (plVar3 != (longlong *)*plVar4) {
      plVar5 = (longlong *)plVar3[1];
      if (*(char *)((longlong)plVar6 + 0x19) == '\0') {
        plVar6[1] = (longlong)plVar5;
      }
      *plVar5 = (longlong)plVar6;
      plVar3[2] = *plVar4;
      *(longlong **)(*plVar4 + 8) = plVar3;
    }
    if (*(longlong **)(*param_1 + 8) == param_2) {
      *(longlong **)(*param_1 + 8) = plVar3;
    }
    else {
      plVar4 = (longlong *)*plVar7;
      if ((longlong *)*plVar4 == param_2) {
        *plVar4 = (longlong)plVar3;
      }
      else {
        plVar4[2] = (longlong)plVar3;
      }
    }
    lVar2 = plVar3[3];
    plVar3[1] = *plVar7;
    *(char *)(plVar3 + 3) = (char)param_2[3];
    *(char *)(param_2 + 3) = (char)lVar2;
  }
  else {
    plVar5 = (longlong *)*plVar7;
    if (*(char *)((longlong)plVar6 + 0x19) == '\0') {
      plVar6[1] = (longlong)plVar5;
    }
    if (*(longlong **)(*param_1 + 8) == param_2) {
      *(longlong **)(*param_1 + 8) = plVar6;
    }
    else if ((longlong *)*plVar5 == param_2) {
      *plVar5 = (longlong)plVar6;
    }
    else {
      plVar5[2] = (longlong)plVar6;
    }
    if (*(longlong **)*param_1 == param_2) {
      plVar4 = plVar5;
      if (*(char *)((longlong)plVar6 + 0x19) == '\0') {
        cVar1 = *(char *)(*plVar6 + 0x19);
        plVar3 = (longlong *)*plVar6;
        plVar4 = plVar6;
        while (plVar7 = plVar3, cVar1 == '\0') {
          plVar3 = (longlong *)*plVar7;
          cVar1 = *(char *)((longlong)plVar3 + 0x19);
          plVar4 = plVar7;
        }
      }
      *(longlong **)*param_1 = plVar4;
    }
    lVar2 = *param_1;
    if (*(longlong **)(lVar2 + 0x10) == param_2) {
      if (*(char *)((longlong)plVar6 + 0x19) == '\0') {
        cVar1 = *(char *)(plVar6[2] + 0x19);
        plVar4 = (longlong *)plVar6[2];
        plVar3 = plVar6;
        while (plVar7 = plVar4, cVar1 == '\0') {
          plVar4 = (longlong *)plVar7[2];
          cVar1 = *(char *)((longlong)plVar4 + 0x19);
          plVar3 = plVar7;
        }
        *(longlong **)(lVar2 + 0x10) = plVar3;
      }
      else {
        *(longlong **)(lVar2 + 0x10) = plVar5;
      }
    }
  }
  if ((char)param_2[3] == '\x01') {
    if (plVar6 != *(longlong **)(*param_1 + 8)) {
      do {
        plVar4 = plVar5;
        if ((char)plVar6[3] != '\x01') break;
        plVar3 = (longlong *)*plVar4;
        if (plVar6 == plVar3) {
          plVar3 = (longlong *)plVar4[2];
          if ((char)plVar3[3] == '\0') {
            *(undefined1 *)(plVar3 + 3) = 1;
            plVar3 = (longlong *)plVar4[2];
            *(undefined1 *)(plVar4 + 3) = 0;
            plVar4[2] = *plVar3;
            if (*(char *)(*plVar3 + 0x19) == '\0') {
              *(longlong **)(*plVar3 + 8) = plVar4;
            }
            plVar5 = plVar4 + 1;
            plVar3[1] = plVar4[1];
            if (plVar4 == *(longlong **)(*param_1 + 8)) {
              *(longlong **)(*param_1 + 8) = plVar3;
              *plVar3 = (longlong)plVar4;
              *plVar5 = (longlong)plVar3;
              plVar3 = (longlong *)plVar4[2];
            }
            else {
              plVar7 = (longlong *)*plVar5;
              if (plVar4 == (longlong *)*plVar7) {
                *plVar7 = (longlong)plVar3;
                *plVar3 = (longlong)plVar4;
                *plVar5 = (longlong)plVar3;
                plVar3 = (longlong *)plVar4[2];
              }
              else {
                plVar7[2] = (longlong)plVar3;
                *plVar3 = (longlong)plVar4;
                *plVar5 = (longlong)plVar3;
                plVar3 = (longlong *)plVar4[2];
              }
            }
          }
          if (*(char *)((longlong)plVar3 + 0x19) == '\0') {
            if ((*(char *)(*plVar3 + 0x18) != '\x01') || (*(char *)(plVar3[2] + 0x18) != '\x01')) {
              if (*(char *)(plVar3[2] + 0x18) == '\x01') {
                *(undefined1 *)(*plVar3 + 0x18) = 1;
                *(undefined1 *)(plVar3 + 3) = 0;
                FUN_18003f250(param_1,plVar3);
                plVar3 = (longlong *)plVar4[2];
              }
              *(char *)(plVar3 + 3) = (char)plVar4[3];
              *(undefined1 *)(plVar4 + 3) = 1;
              *(undefined1 *)(plVar3[2] + 0x18) = 1;
              FUN_18003f1f0(param_1,(longlong)plVar4);
              break;
            }
LAB_18003eefb:
            *(undefined1 *)(plVar3 + 3) = 0;
          }
        }
        else {
          if ((char)plVar3[3] == '\0') {
            *(undefined1 *)(plVar3 + 3) = 1;
            lVar2 = *plVar4;
            *(undefined1 *)(plVar4 + 3) = 0;
            *plVar4 = *(longlong *)(lVar2 + 0x10);
            if (*(char *)(*(longlong *)(lVar2 + 0x10) + 0x19) == '\0') {
              *(longlong **)(*(longlong *)(lVar2 + 0x10) + 8) = plVar4;
            }
            plVar3 = plVar4 + 1;
            *(longlong *)(lVar2 + 8) = plVar4[1];
            if (plVar4 == *(longlong **)(*param_1 + 8)) {
              *(longlong *)(*param_1 + 8) = lVar2;
              *(longlong **)(lVar2 + 0x10) = plVar4;
              *plVar3 = lVar2;
              plVar3 = (longlong *)*plVar4;
            }
            else {
              plVar5 = (longlong *)*plVar3;
              if (plVar4 == (longlong *)plVar5[2]) {
                plVar5[2] = lVar2;
                *(longlong **)(lVar2 + 0x10) = plVar4;
                *plVar3 = lVar2;
                plVar3 = (longlong *)*plVar4;
              }
              else {
                *plVar5 = lVar2;
                *(longlong **)(lVar2 + 0x10) = plVar4;
                *plVar3 = lVar2;
                plVar3 = (longlong *)*plVar4;
              }
            }
          }
          if (*(char *)((longlong)plVar3 + 0x19) == '\0') {
            if ((*(char *)(plVar3[2] + 0x18) == '\x01') && (*(char *)(*plVar3 + 0x18) == '\x01'))
            goto LAB_18003eefb;
            if (*(char *)(*plVar3 + 0x18) == '\x01') {
              *(undefined1 *)(plVar3[2] + 0x18) = 1;
              *(undefined1 *)(plVar3 + 3) = 0;
              FUN_18003f1f0(param_1,(longlong)plVar3);
              plVar3 = (longlong *)*plVar4;
            }
            *(char *)(plVar3 + 3) = (char)plVar4[3];
            *(undefined1 *)(plVar4 + 3) = 1;
            *(undefined1 *)(*plVar3 + 0x18) = 1;
            FUN_18003f250(param_1,plVar4);
            break;
          }
        }
        plVar5 = (longlong *)plVar4[1];
        plVar6 = plVar4;
      } while (plVar4 != *(longlong **)(*param_1 + 8));
    }
    *(undefined1 *)(plVar6 + 3) = 1;
  }
  if (param_1[1] != 0) {
    param_1[1] = param_1[1] + -1;
  }
  return param_2;
}

/* ---- FUNC 0003EBC3 FUN_18003ebc3 (936 bytes) ---- */

longlong * FUN_18003ebc3(longlong *param_1,longlong *param_2,undefined8 param_3,longlong *param_4)

{
  char cVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong *in_RAX;
  longlong *plVar6;
  longlong *plVar7;
  longlong *plVar8;
  
  if (*(char *)((longlong)in_RAX + 0x19) == '\0') {
    cVar1 = *(char *)(*in_RAX + 0x19);
    plVar6 = (longlong *)*in_RAX;
    while (plVar8 = plVar6, cVar1 == '\0') {
      plVar6 = (longlong *)*plVar8;
      cVar1 = *(char *)((longlong)plVar6 + 0x19);
      in_RAX = plVar8;
    }
  }
  else {
    cVar1 = *(char *)(param_2[1] + 0x19);
    plVar8 = (longlong *)param_2[1];
    plVar6 = param_2;
    while ((in_RAX = plVar8, cVar1 == '\0' && (plVar6 == (longlong *)in_RAX[2]))) {
      cVar1 = *(char *)(in_RAX[1] + 0x19);
      plVar8 = (longlong *)in_RAX[1];
      plVar6 = in_RAX;
    }
  }
  plVar7 = param_2 + 1;
  plVar6 = (longlong *)*param_2;
  plVar8 = (longlong *)*param_4;
  if (((*(char *)((longlong)plVar6 + 0x19) == '\0') &&
      (plVar8 = plVar6, *(char *)(*param_4 + 0x19) == '\0')) &&
     (plVar8 = (longlong *)in_RAX[2], in_RAX != param_2)) {
    plVar6[1] = (longlong)in_RAX;
    *in_RAX = *param_2;
    plVar6 = in_RAX;
    if (in_RAX != (longlong *)*param_4) {
      plVar6 = (longlong *)in_RAX[1];
      if (*(char *)((longlong)plVar8 + 0x19) == '\0') {
        plVar8[1] = (longlong)plVar6;
      }
      *plVar6 = (longlong)plVar8;
      in_RAX[2] = *param_4;
      *(longlong **)(*param_4 + 8) = in_RAX;
    }
    if (*(longlong **)(*param_1 + 8) == param_2) {
      *(longlong **)(*param_1 + 8) = in_RAX;
    }
    else {
      puVar3 = (undefined8 *)*plVar7;
      if ((longlong *)*puVar3 == param_2) {
        *puVar3 = in_RAX;
      }
      else {
        puVar3[2] = in_RAX;
      }
    }
    lVar2 = in_RAX[3];
    in_RAX[1] = *plVar7;
    *(char *)(in_RAX + 3) = (char)param_2[3];
    *(char *)(param_2 + 3) = (char)lVar2;
  }
  else {
    plVar6 = (longlong *)*plVar7;
    if (*(char *)((longlong)plVar8 + 0x19) == '\0') {
      plVar8[1] = (longlong)plVar6;
    }
    if (*(longlong **)(*param_1 + 8) == param_2) {
      *(longlong **)(*param_1 + 8) = plVar8;
    }
    else if ((longlong *)*plVar6 == param_2) {
      *plVar6 = (longlong)plVar8;
    }
    else {
      plVar6[2] = (longlong)plVar8;
    }
    if (*(longlong **)*param_1 == param_2) {
      plVar7 = plVar6;
      if (*(char *)((longlong)plVar8 + 0x19) == '\0') {
        cVar1 = *(char *)(*plVar8 + 0x19);
        plVar5 = (longlong *)*plVar8;
        plVar7 = plVar8;
        while (plVar4 = plVar5, cVar1 == '\0') {
          plVar5 = (longlong *)*plVar4;
          cVar1 = *(char *)((longlong)plVar5 + 0x19);
          plVar7 = plVar4;
        }
      }
      *(longlong **)*param_1 = plVar7;
    }
    lVar2 = *param_1;
    if (*(longlong **)(lVar2 + 0x10) == param_2) {
      if (*(char *)((longlong)plVar8 + 0x19) == '\0') {
        cVar1 = *(char *)(plVar8[2] + 0x19);
        plVar7 = (longlong *)plVar8[2];
        plVar5 = plVar8;
        while (plVar4 = plVar7, cVar1 == '\0') {
          plVar7 = (longlong *)plVar4[2];
          cVar1 = *(char *)((longlong)plVar7 + 0x19);
          plVar5 = plVar4;
        }
        *(longlong **)(lVar2 + 0x10) = plVar5;
      }
      else {
        *(longlong **)(lVar2 + 0x10) = plVar6;
      }
    }
  }
  if ((char)param_2[3] == '\x01') {
    if (plVar8 != *(longlong **)(*param_1 + 8)) {
      do {
        plVar7 = plVar6;
        if ((char)plVar8[3] != '\x01') break;
        plVar6 = (longlong *)*plVar7;
        if (plVar8 == plVar6) {
          plVar6 = (longlong *)plVar7[2];
          if ((char)plVar6[3] == '\0') {
            *(undefined1 *)(plVar6 + 3) = 1;
            plVar6 = (longlong *)plVar7[2];
            *(undefined1 *)(plVar7 + 3) = 0;
            plVar7[2] = *plVar6;
            if (*(char *)(*plVar6 + 0x19) == '\0') {
              *(longlong **)(*plVar6 + 8) = plVar7;
            }
            plVar5 = plVar7 + 1;
            plVar6[1] = plVar7[1];
            if (plVar7 == *(longlong **)(*param_1 + 8)) {
              *(longlong **)(*param_1 + 8) = plVar6;
              *plVar6 = (longlong)plVar7;
              *plVar5 = (longlong)plVar6;
              plVar6 = (longlong *)plVar7[2];
            }
            else {
              plVar4 = (longlong *)*plVar5;
              if (plVar7 == (longlong *)*plVar4) {
                *plVar4 = (longlong)plVar6;
                *plVar6 = (longlong)plVar7;
                *plVar5 = (longlong)plVar6;
                plVar6 = (longlong *)plVar7[2];
              }
              else {
                plVar4[2] = (longlong)plVar6;
                *plVar6 = (longlong)plVar7;
                *plVar5 = (longlong)plVar6;
                plVar6 = (longlong *)plVar7[2];
              }
            }
          }
          if (*(char *)((longlong)plVar6 + 0x19) == '\0') {
            if ((*(char *)(*plVar6 + 0x18) != '\x01') || (*(char *)(plVar6[2] + 0x18) != '\x01')) {
              if (*(char *)(plVar6[2] + 0x18) == '\x01') {
                *(undefined1 *)(*plVar6 + 0x18) = 1;
                *(undefined1 *)(plVar6 + 3) = 0;
                FUN_18003f250(param_1,plVar6);
                plVar6 = (longlong *)plVar7[2];
              }
              *(char *)(plVar6 + 3) = (char)plVar7[3];
              *(undefined1 *)(plVar7 + 3) = 1;
              *(undefined1 *)(plVar6[2] + 0x18) = 1;
              FUN_18003f1f0(param_1,(longlong)plVar7);
              break;
            }
LAB_18003eefb:
            *(undefined1 *)(plVar6 + 3) = 0;
          }
        }
        else {
          if ((char)plVar6[3] == '\0') {
            *(undefined1 *)(plVar6 + 3) = 1;
            lVar2 = *plVar7;
            *(undefined1 *)(plVar7 + 3) = 0;
            *plVar7 = *(longlong *)(lVar2 + 0x10);
            if (*(char *)(*(longlong *)(lVar2 + 0x10) + 0x19) == '\0') {
              *(longlong **)(*(longlong *)(lVar2 + 0x10) + 8) = plVar7;
            }
            plVar6 = plVar7 + 1;
            *(longlong *)(lVar2 + 8) = plVar7[1];
            if (plVar7 == *(longlong **)(*param_1 + 8)) {
              *(longlong *)(*param_1 + 8) = lVar2;
              *(longlong **)(lVar2 + 0x10) = plVar7;
              *plVar6 = lVar2;
              plVar6 = (longlong *)*plVar7;
            }
            else {
              plVar5 = (longlong *)*plVar6;
              if (plVar7 == (longlong *)plVar5[2]) {
                plVar5[2] = lVar2;
                *(longlong **)(lVar2 + 0x10) = plVar7;
                *plVar6 = lVar2;
                plVar6 = (longlong *)*plVar7;
              }
              else {
                *plVar5 = lVar2;
                *(longlong **)(lVar2 + 0x10) = plVar7;
                *plVar6 = lVar2;
                plVar6 = (longlong *)*plVar7;
              }
            }
          }
          if (*(char *)((longlong)plVar6 + 0x19) == '\0') {
            if ((*(char *)(plVar6[2] + 0x18) == '\x01') && (*(char *)(*plVar6 + 0x18) == '\x01'))
            goto LAB_18003eefb;
            if (*(char *)(*plVar6 + 0x18) == '\x01') {
              *(undefined1 *)(plVar6[2] + 0x18) = 1;
              *(undefined1 *)(plVar6 + 3) = 0;
              FUN_18003f1f0(param_1,(longlong)plVar6);
              plVar6 = (longlong *)*plVar7;
            }
            *(char *)(plVar6 + 3) = (char)plVar7[3];
            *(undefined1 *)(plVar7 + 3) = 1;
            *(undefined1 *)(*plVar6 + 0x18) = 1;
            FUN_18003f250(param_1,plVar7);
            break;
          }
        }
        plVar6 = (longlong *)plVar7[1];
        plVar8 = plVar7;
      } while (plVar7 != *(longlong **)(*param_1 + 8));
    }
    *(undefined1 *)(plVar8 + 3) = 1;
  }
  if (param_1[1] != 0) {
    param_1[1] = param_1[1] + -1;
  }
  return param_2;
}

/* ---- FUNC 0003EF6B FUN_18003ef6b (19 bytes) ---- */

void FUN_18003ef6b(longlong param_1)

{
  longlong unaff_RSI;
  
  *(longlong *)(unaff_RSI + 8) = param_1 + -1;
  return;
}

/* ---- FUNC 0003EF80 FUN_18003ef80 (4 bytes) ---- */

undefined8 FUN_18003ef80(undefined8 param_1)

{
  return param_1;
}

/* ---- FUNC 0003EF90 FUN_18003ef90 (603 bytes) ---- */

longlong * FUN_18003ef90(longlong *param_1,longlong *param_2,longlong *param_3)

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
LAB_18003f1cd:
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
          if (plVar7 == (longlong *)*(longlong *)(*param_1 + 8)) {
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
        goto LAB_18003f1cd;
      }
      *(undefined1 *)(plVar7 + 3) = 1;
      *(undefined1 *)(lVar3 + 0x18) = 1;
      *(undefined1 *)(*(longlong *)(plVar6[1] + 8) + 0x18) = 0;
      plVar6 = *(longlong **)(plVar6[1] + 8);
    }
    cVar1 = *(char *)(plVar6[1] + 0x18);
  } while( true );
}

/* ---- FUNC 0003F1F0 FUN_18003f1f0 (85 bytes) ---- */

void FUN_18003f1f0(longlong *param_1,longlong param_2)

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

/* ---- FUNC 0003F250 FUN_18003f250 (89 bytes) ---- */

void FUN_18003f250(longlong *param_1,longlong *param_2)

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

/* ---- FUNC 0003F2B0 FUN_18003f2b0 (16 bytes) ---- */

void FUN_18003f2b0(void)

{
                    /* WARNING: Subroutine does not return */
  std::_Xlength_error("map/set too long");
}

/* ---- FUNC 0003F2D0 FUN_18003f2d0 (17 bytes) ---- */

void FUN_18003f2d0(void)

{
  code *pcVar1;
  
  std::_Xout_of_range("invalid string position");
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

/* ---- FUNC 0003F2F0 FUN_18003f2f0 (11 bytes) ---- */

void FUN_18003f2f0(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018003f2f7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(longlong **)(param_1 + 0x50) + 0x38))();
  return;
}

/* ---- FUNC 0003F300 FUN_18003f300 (54 bytes) ---- */

undefined8 FUN_18003f300(longlong *param_1,short param_2,undefined2 *param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 *local_res20;
  
  if (DAT_1800797f8 != 0) {
    uVar2 = (**(code **)(*param_1 + 0x210))(param_1,0x7f3);
    return uVar2;
  }
  local_res20 = (undefined8 *)0x0;
  if (param_1[9] == 0) {
    uVar2 = 0x7d9;
  }
  else {
    iVar1 = HAGetAttrType(param_1[9],(int)param_2,0,&local_res20);
    if (iVar1 == -999) {
      if ((local_res20 != (undefined8 *)0x0) && ((code *)*local_res20 != (code *)0x0)) {
        (*(code *)*local_res20)();
      }
      *param_3 = 0;
      return 0;
    }
    if (0 < iVar1) {
      *param_3 = 5;
      return 0;
    }
    switch(iVar1) {
    case 0:
      *param_3 = 0;
      return 0;
    case -10:
      *param_3 = 4;
      return 0;
    default:
      uVar2 = 0x7d1;
      break;
    case -6:
      *param_3 = 6;
      return 0;
    case -3:
      *param_3 = 3;
      return 0;
    case -2:
      *param_3 = 2;
      return 0;
    case -1:
      *param_3 = 1;
      return 0;
    }
  }
  uVar2 = (**(code **)(*param_1 + 0x210))(param_1,uVar2);
  return uVar2;
}

/* ---- FUNC 0003F336 FUN_18003f336 (92 bytes) ---- */

undefined8 FUN_18003f336(longlong param_1,short param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined2 *unaff_RBX;
  longlong *unaff_RDI;
  undefined8 *puStack0000000000000048;
  
  puStack0000000000000048 = (undefined8 *)0x0;
  if (param_1 != 0) {
    iVar1 = HAGetAttrType(param_1,(int)param_2,0,&stack0x00000048);
    if (iVar1 == -999) {
      if ((puStack0000000000000048 != (undefined8 *)0x0) &&
         ((code *)*puStack0000000000000048 != (code *)0x0)) {
        (*(code *)*puStack0000000000000048)();
      }
      *unaff_RBX = 0;
      return 0;
    }
    if (0 < iVar1) {
      *unaff_RBX = 5;
      return 0;
    }
    switch(iVar1) {
    case 0:
      *unaff_RBX = 0;
      return 0;
    case -10:
      *unaff_RBX = 4;
      return 0;
    default:
      break;
    case -6:
      *unaff_RBX = 6;
      return 0;
    case -3:
      *unaff_RBX = 3;
      return 0;
    case -2:
      *unaff_RBX = 2;
      return 0;
    case -1:
      *unaff_RBX = 1;
      return 0;
    }
  }
  uVar2 = (**(code **)(*unaff_RDI + 0x210))();
  return uVar2;
}

/* ---- FUNC 0003F392 FUN_18003f392 (27 bytes) ---- */

undefined8 FUN_18003f392(void)

{
  int in_EAX;
  undefined8 uVar1;
  undefined2 *unaff_RBX;
  undefined2 unaff_SI;
  longlong *unaff_RDI;
  
  if (0 < in_EAX) {
    *unaff_RBX = 5;
    return 0;
  }
  switch(in_EAX) {
  case 0:
    *unaff_RBX = unaff_SI;
    return 0;
  case -10:
    *unaff_RBX = 4;
    return 0;
  default:
    uVar1 = (**(code **)(*unaff_RDI + 0x210))();
    return uVar1;
  case -6:
    *unaff_RBX = 6;
    return 0;
  case -3:
    *unaff_RBX = 3;
    return 0;
  case -2:
    *unaff_RBX = 2;
    return 0;
  case -1:
    *unaff_RBX = 1;
    return 0;
  }
}

/* ---- FUNC 0003F3AD FUN_18003f3ad (54 bytes) ---- */

undefined8 FUN_18003f3ad(void)

{
  undefined4 in_EAX;
  undefined8 uVar1;
  undefined2 *unaff_RBX;
  undefined2 unaff_SI;
  longlong *unaff_RDI;
  
  switch(in_EAX) {
  case 0:
    *unaff_RBX = unaff_SI;
    return 0;
  case 0xfffffff6:
    *unaff_RBX = 4;
    return 0;
  default:
    uVar1 = (**(code **)(*unaff_RDI + 0x210))();
    return uVar1;
  case 0xfffffffa:
    *unaff_RBX = 6;
    return 0;
  case 0xfffffffd:
    *unaff_RBX = 3;
    return 0;
  case 0xfffffffe:
    *unaff_RBX = 2;
    return 0;
  case 0xffffffff:
    *unaff_RBX = 1;
    return 0;
  }
}

/* ---- FUNC 0003F3E3 caseD_ffffffff (23 bytes) ---- */

undefined8 switchD_18003f3cc::caseD_ffffffff(void)

{
  undefined2 *unaff_RBX;
  
  *unaff_RBX = 1;
  return 0;
}

/* ---- FUNC 0003F3FA caseD_fffffffe (23 bytes) ---- */

undefined8 switchD_18003f3cc::caseD_fffffffe(void)

{
  undefined2 *unaff_RBX;
  
  *unaff_RBX = 2;
  return 0;
}

/* ---- FUNC 0003F411 caseD_fffffffd (23 bytes) ---- */

undefined8 switchD_18003f3cc::caseD_fffffffd(void)

{
  undefined2 *unaff_RBX;
  
  *unaff_RBX = 3;
  return 0;
}

/* ---- FUNC 0003F428 caseD_fffffff6 (23 bytes) ---- */

undefined8 switchD_18003f3cc::caseD_fffffff6(void)

{
  undefined2 *unaff_RBX;
  
  *unaff_RBX = 4;
  return 0;
}

/* ---- FUNC 0003F43F caseD_fffffffa (23 bytes) ---- */

undefined8 switchD_18003f3cc::caseD_fffffffa(void)

{
  undefined2 *unaff_RBX;
  
  *unaff_RBX = 6;
  return 0;
}

/* ---- FUNC 0003F456 caseD_fffffff7 (33 bytes) ---- */

void switchD_18003f3cc::caseD_fffffff7(void)

{
  longlong *unaff_RDI;
  
  (**(code **)(*unaff_RDI + 0x210))();
  return;
}

/* ---- FUNC 0003F4B0 FUN_18003f4b0 (63 bytes) ---- */

int FUN_18003f4b0(longlong *param_1,short param_2,undefined8 param_3,VARIANTARG *param_4)

{
  short sVar1;
  short sVar2;
  bool bVar3;
  ULONG UVar4;
  HRESULT HVar5;
  longlong lVar6;
  SAFEARRAY *psa;
  void *pvVar7;
  longlong lVar8;
  undefined7 extraout_var;
  _union_1719 _Var9;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar10;
  int iVar11;
  SAFEARRAYBOUND local_58;
  undefined8 *local_50;
  void *local_48;
  _union_1719 local_40 [2];
  IUnknownVtbl *local_30;
  code *local_28;
  
  iVar11 = (int)param_2;
  if (DAT_1800797f8 != 0) {
    iVar11 = (**(code **)(*param_1 + 0x210))(param_1,0x7f3);
    return iVar11;
  }
  local_50 = (undefined8 *)0x0;
  if (param_1[9] == 0) {
    iVar11 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
    return iVar11;
  }
  VariantInit(param_4);
  UVar4 = HAGetAttrType(param_1[9],iVar11,0,&local_50);
  if (UVar4 == 0xfffffc19) {
    lVar6 = *param_1;
    if (local_50 == (undefined8 *)0x0) {
      iVar11 = (**(code **)(lVar6 + 0x210))(param_1,0x7d1);
      return iVar11;
    }
LAB_18003f5d6:
    iVar11 = (**(code **)(lVar6 + 0x208))(param_1);
    return iVar11;
  }
  if (UVar4 != 0) {
    local_50 = (undefined8 *)HAGetAttr(param_1[9],iVar11);
    if (local_50 == (undefined8 *)0x0) {
      if (local_30 != (IUnknownVtbl *)0x0) {
        if (0 < (int)UVar4) {
          local_58.lLbound = 0;
          local_58.cElements = UVar4;
          psa = SafeArrayCreate(0x11,1,&local_58);
          if (psa == (SAFEARRAY *)0x0) {
            iVar11 = (**(code **)(*param_1 + 0x210))(param_1,0x7e1);
            return iVar11;
          }
          HVar5 = SafeArrayAccessData(psa,&local_48);
          if (-1 < HVar5) {
            pvVar7 = memcpy(local_48,local_30,(longlong)(int)UVar4);
            if (pvVar7 != (void *)0x0) {
              if (local_28 != (code *)0x0) {
                (*local_28)(local_30);
              }
              SafeArrayUnaccessData(psa);
              (param_4->n1).n2.vt = 0x2000;
              *(SAFEARRAY **)((longlong)&param_4->n1 + 8) = psa;
              return 0;
            }
            if (local_28 != (code *)0x0) {
              (*local_28)(local_30);
            }
            SafeArrayUnaccessData(psa);
          }
          iVar11 = (**(code **)(*param_1 + 0x210))(param_1,0x7d1);
          return iVar11;
        }
        switch(UVar4) {
        case 0:
          (param_4->n1).n2.vt = 0;
          break;
        case 0xfffffff6:
          (param_4->n1).n2.vt = 9;
          iVar11 = FUN_1800389d0(local_30,(IUnknownVtbl *)param_1[10],(IUnknownVtbl *)0x0,0,
                                 (IUnknownVtbl *)param_1[2],local_40);
          if (-1 < iVar11) {
            (param_4->n1).decVal.u2 = local_40[0];
            return 0;
          }
          return iVar11;
        case 0xfffffffa:
          VariantCopy(param_4,(VARIANTARG *)local_30);
          break;
        case 0xfffffffc:
          (param_4->n1).n2.vt = 0x14;
          (param_4->n1).decVal.u2 = (_union_1719)local_30->QueryInterface;
          break;
        case 0xfffffffd:
          (param_4->n1).n2.vt = 8;
          if (iVar11 == 0x13) {
            lVar6 = -1;
            do {
              lVar8 = lVar6;
              lVar6 = lVar8 + 1;
            } while (*(char *)((longlong)&local_30->QueryInterface + lVar8 + 1) != '\0');
            sVar1 = *(short *)((longlong)&local_30->QueryInterface + lVar8 + 2);
            lVar6 = -1;
            do {
              lVar8 = lVar6;
              lVar6 = lVar8 + 1;
            } while (*(char *)((longlong)&local_30->QueryInterface + lVar8 + 1) != '\0');
            sVar2 = *(short *)((longlong)&local_30->QueryInterface + lVar8 + 4);
            if (sVar1 != 0) {
              if (((ushort)(sVar2 - 1U) < 999) &&
                 (bVar3 = FUN_18003b1d0(&DAT_180079aa0,399,sVar2,sVar1),
                 (int)CONCAT71(extraout_var,bVar3) != 0)) {
                _Var9 = (_union_1719)FUN_1800019d0(&DAT_180079aa0);
                (param_4->n1).decVal.u2 = _Var9;
                break;
              }
              if (-1 < sVar2) {
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_58,(char *)local_30);
                iVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                         ReverseFind((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                      *)&local_58,'.');
                if (iVar11 != -1) {
                  pCVar10 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                             *)ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                               Left((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
                                    )&local_58,(int)&local_48);
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_58,pCVar10);
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_48);
                }
                _Var9 = (_union_1719)
                        FUN_1800019d0((LPCSTR)CONCAT44(local_58.lLbound,local_58.cElements));
                (param_4->n1).decVal.u2 = _Var9;
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_58);
                break;
              }
            }
          }
          _Var9 = (_union_1719)FUN_1800019d0((LPCSTR)local_30);
          (param_4->n1).decVal.u2 = _Var9;
          break;
        case 0xfffffffe:
          (param_4->n1).n2.vt = 5;
          (param_4->n1).decVal.u2 = (_union_1719)local_30->QueryInterface;
          break;
        case 0xffffffff:
          (param_4->n1).n2.vt = 3;
          *(undefined4 *)((longlong)&param_4->n1 + 8) = *(undefined4 *)&local_30->QueryInterface;
        }
        if (local_28 == (code *)0x0) {
          return 0;
        }
        (*local_28)(local_30);
        return 0;
      }
    }
    else {
      if (*(short *)(local_50 + 1) != 0) {
        lVar6 = *param_1;
        goto LAB_18003f5d6;
      }
      if ((code *)*local_50 != (code *)0x0) {
        (*(code *)*local_50)(local_50);
      }
    }
  }
  (param_4->n1).n2.vt = 0;
  return 0;
}

/* ---- FUNC 0003F4EF FUN_18003f4ef (40 bytes) ---- */

int FUN_18003f4ef(longlong *param_1)

{
  short sVar1;
  short sVar2;
  code *pcVar3;
  bool bVar4;
  int iVar5;
  HRESULT HVar6;
  undefined8 *puVar7;
  longlong lVar8;
  SAFEARRAY *psa;
  void *pvVar9;
  longlong lVar10;
  undefined7 extraout_var;
  _union_1719 _Var11;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar12;
  VARIANTARG *unaff_RBX;
  longlong unaff_RBP;
  int unaff_ESI;
  longlong *unaff_RDI;
  IUnknownVtbl *pvargSrc;
  
  *(undefined8 *)(unaff_RBP + -0x38) = 0;
  if (param_1[9] == 0) {
    iVar5 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
    return iVar5;
  }
  VariantInit(unaff_RBX);
  iVar5 = HAGetAttrType(unaff_RDI[9],unaff_ESI,0,unaff_RBP + -0x38);
  if (iVar5 == -999) {
    lVar8 = *unaff_RDI;
    if (*(longlong *)(unaff_RBP + -0x38) == 0) {
      iVar5 = (**(code **)(lVar8 + 0x210))();
      return iVar5;
    }
LAB_18003f5d6:
    iVar5 = (**(code **)(lVar8 + 0x208))();
    return iVar5;
  }
  if (iVar5 == 0) {
LAB_18003f5a2:
    (unaff_RBX->n1).n2.vt = 0;
    return 0;
  }
  puVar7 = (undefined8 *)HAGetAttr(unaff_RDI[9],unaff_ESI);
  *(undefined8 **)(unaff_RBP + -0x38) = puVar7;
  if (puVar7 != (undefined8 *)0x0) {
    if (*(short *)(puVar7 + 1) != 0) {
      lVar8 = *unaff_RDI;
      goto LAB_18003f5d6;
    }
    if ((code *)*puVar7 != (code *)0x0) {
      (*(code *)*puVar7)(puVar7);
    }
    goto LAB_18003f5a2;
  }
  pvargSrc = *(IUnknownVtbl **)(unaff_RBP + -0x18);
  if (pvargSrc == (IUnknownVtbl *)0x0) goto LAB_18003f5a2;
  if (0 < iVar5) {
    *(undefined4 *)(unaff_RBP + -0x3c) = 0;
    *(int *)(unaff_RBP + -0x40) = iVar5;
    psa = SafeArrayCreate(0x11,1,(SAFEARRAYBOUND *)(unaff_RBP + -0x40));
    if (psa == (SAFEARRAY *)0x0) {
      iVar5 = (**(code **)(*unaff_RDI + 0x210))();
      return iVar5;
    }
    HVar6 = SafeArrayAccessData(psa,(void **)(unaff_RBP + -0x30));
    if (-1 < HVar6) {
      pvVar9 = memcpy(*(void **)(unaff_RBP + -0x30),*(void **)(unaff_RBP + -0x18),(longlong)iVar5);
      pcVar3 = *(code **)(unaff_RBP + -0x10);
      if (pvVar9 != (void *)0x0) {
        if (pcVar3 != (code *)0x0) {
          (*pcVar3)(*(undefined8 *)(unaff_RBP + -0x18));
        }
        SafeArrayUnaccessData(psa);
        (unaff_RBX->n1).n2.vt = 0x2000;
        *(SAFEARRAY **)((longlong)&unaff_RBX->n1 + 8) = psa;
        return 0;
      }
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(*(undefined8 *)(unaff_RBP + -0x18));
      }
      SafeArrayUnaccessData(psa);
    }
    iVar5 = (**(code **)(*unaff_RDI + 0x210))();
    return iVar5;
  }
  switch(iVar5) {
  case 0:
    (unaff_RBX->n1).n2.vt = 0;
    break;
  case -10:
    (unaff_RBX->n1).n2.vt = 9;
    iVar5 = FUN_1800389d0(pvargSrc,(IUnknownVtbl *)unaff_RDI[10],(IUnknownVtbl *)0x0,0,
                          (IUnknownVtbl *)unaff_RDI[2],(undefined8 *)(unaff_RBP + -0x28));
    if (-1 < iVar5) {
      (unaff_RBX->n1).decVal.u2 = *(_union_1719 *)(unaff_RBP + -0x28);
      return 0;
    }
    return iVar5;
  case -6:
    VariantCopy(unaff_RBX,(VARIANTARG *)pvargSrc);
    goto LAB_18003f83a;
  case -4:
    (unaff_RBX->n1).n2.vt = 0x14;
    (unaff_RBX->n1).decVal.u2 = (_union_1719)pvargSrc->QueryInterface;
    break;
  case -3:
    (unaff_RBX->n1).n2.vt = 8;
    if (unaff_ESI == 0x13) {
      lVar8 = -1;
      do {
        lVar10 = lVar8;
        lVar8 = lVar10 + 1;
      } while (*(char *)((longlong)&pvargSrc->QueryInterface + lVar10 + 1) != '\0');
      sVar1 = *(short *)((longlong)&pvargSrc->QueryInterface + lVar10 + 2);
      lVar8 = -1;
      do {
        lVar10 = lVar8;
        lVar8 = lVar10 + 1;
      } while (*(char *)((longlong)&pvargSrc->QueryInterface + lVar10 + 1) != '\0');
      sVar2 = *(short *)((longlong)&pvargSrc->QueryInterface + lVar10 + 4);
      if (sVar1 != 0) {
        if ((ushort)(sVar2 - 1U) < 999) {
          bVar4 = FUN_18003b1d0(&DAT_180079aa0,399,sVar2,sVar1);
          if ((int)CONCAT71(extraout_var,bVar4) != 0) {
            _Var11 = (_union_1719)FUN_1800019d0(&DAT_180079aa0);
            (unaff_RBX->n1).decVal.u2 = _Var11;
            goto LAB_18003f83a;
          }
          pvargSrc = *(IUnknownVtbl **)(unaff_RBP + -0x18);
        }
        if (-1 < sVar2) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                     (unaff_RBP + -0x40),(char *)pvargSrc);
          iVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             (unaff_RBP + -0x40),'.');
          if (iVar5 != -1) {
            pCVar12 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                 (unaff_RBP + -0x40),(int)unaff_RBP + -0x30);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       (unaff_RBP + -0x40),pCVar12);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       (unaff_RBP + -0x30));
          }
          _Var11 = (_union_1719)FUN_1800019d0(*(LPCSTR *)(unaff_RBP + -0x40));
          (unaff_RBX->n1).decVal.u2 = _Var11;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                     (unaff_RBP + -0x40));
          goto LAB_18003f83a;
        }
      }
    }
    _Var11 = (_union_1719)FUN_1800019d0((LPCSTR)pvargSrc);
    (unaff_RBX->n1).decVal.u2 = _Var11;
LAB_18003f83a:
    pvargSrc = *(IUnknownVtbl **)(unaff_RBP + -0x18);
    break;
  case -2:
    (unaff_RBX->n1).n2.vt = 5;
    (unaff_RBX->n1).decVal.u2 = (_union_1719)pvargSrc->QueryInterface;
    break;
  case -1:
    (unaff_RBX->n1).n2.vt = 3;
    *(undefined4 *)((longlong)&unaff_RBX->n1 + 8) = *(undefined4 *)&pvargSrc->QueryInterface;
  }
  if (*(code **)(unaff_RBP + -0x10) != (code *)0x0) {
    (**(code **)(unaff_RBP + -0x10))(pvargSrc);
  }
  return 0;
}

/* ---- FUNC 0003F517 FUN_18003f517 (830 bytes) ---- */

int FUN_18003f517(void)

{
  short sVar1;
  short sVar2;
  code *pcVar3;
  bool bVar4;
  int iVar5;
  HRESULT HVar6;
  undefined8 *puVar7;
  longlong lVar8;
  SAFEARRAY *psa;
  void *pvVar9;
  longlong lVar10;
  undefined7 extraout_var;
  _union_1719 _Var11;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar12;
  VARIANTARG *unaff_RBX;
  longlong unaff_RBP;
  int unaff_ESI;
  longlong *unaff_RDI;
  IUnknownVtbl *pvargSrc;
  VARTYPE VVar13;
  undefined4 unaff_R12D;
  
  VariantInit(unaff_RBX);
  iVar5 = HAGetAttrType(unaff_RDI[9],unaff_ESI,0,unaff_RBP + -0x38);
  if (iVar5 == -999) {
    lVar8 = *unaff_RDI;
    if (*(longlong *)(unaff_RBP + -0x38) == 0) {
      iVar5 = (**(code **)(lVar8 + 0x210))();
      return iVar5;
    }
LAB_18003f5d6:
    iVar5 = (**(code **)(lVar8 + 0x208))();
    return iVar5;
  }
  VVar13 = (VARTYPE)unaff_R12D;
  if (iVar5 == 0) {
LAB_18003f5a2:
    (unaff_RBX->n1).n2.vt = VVar13;
    return 0;
  }
  puVar7 = (undefined8 *)HAGetAttr(unaff_RDI[9],unaff_ESI);
  *(undefined8 **)(unaff_RBP + -0x38) = puVar7;
  if (puVar7 != (undefined8 *)0x0) {
    if (*(VARTYPE *)(puVar7 + 1) != VVar13) {
      lVar8 = *unaff_RDI;
      goto LAB_18003f5d6;
    }
    if ((code *)*puVar7 != (code *)0x0) {
      (*(code *)*puVar7)(puVar7);
    }
    goto LAB_18003f5a2;
  }
  pvargSrc = *(IUnknownVtbl **)(unaff_RBP + -0x18);
  if (pvargSrc == (IUnknownVtbl *)0x0) goto LAB_18003f5a2;
  if (0 < iVar5) {
    *(undefined4 *)(unaff_RBP + -0x3c) = unaff_R12D;
    *(int *)(unaff_RBP + -0x40) = iVar5;
    psa = SafeArrayCreate(0x11,1,(SAFEARRAYBOUND *)(unaff_RBP + -0x40));
    if (psa == (SAFEARRAY *)0x0) {
      iVar5 = (**(code **)(*unaff_RDI + 0x210))();
      return iVar5;
    }
    HVar6 = SafeArrayAccessData(psa,(void **)(unaff_RBP + -0x30));
    if (-1 < HVar6) {
      pvVar9 = memcpy(*(void **)(unaff_RBP + -0x30),*(void **)(unaff_RBP + -0x18),(longlong)iVar5);
      pcVar3 = *(code **)(unaff_RBP + -0x10);
      if (pvVar9 != (void *)0x0) {
        if (pcVar3 != (code *)0x0) {
          (*pcVar3)(*(undefined8 *)(unaff_RBP + -0x18));
        }
        SafeArrayUnaccessData(psa);
        (unaff_RBX->n1).n2.vt = 0x2000;
        *(SAFEARRAY **)((longlong)&unaff_RBX->n1 + 8) = psa;
        return 0;
      }
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(*(undefined8 *)(unaff_RBP + -0x18));
      }
      SafeArrayUnaccessData(psa);
    }
    iVar5 = (**(code **)(*unaff_RDI + 0x210))();
    return iVar5;
  }
  switch(iVar5) {
  case 0:
    (unaff_RBX->n1).n2.vt = VVar13;
    break;
  case -10:
    (unaff_RBX->n1).n2.vt = 9;
    iVar5 = FUN_1800389d0(pvargSrc,(IUnknownVtbl *)unaff_RDI[10],(IUnknownVtbl *)0x0,0,
                          (IUnknownVtbl *)unaff_RDI[2],(undefined8 *)(unaff_RBP + -0x28));
    if (-1 < iVar5) {
      (unaff_RBX->n1).decVal.u2 = *(_union_1719 *)(unaff_RBP + -0x28);
      return 0;
    }
    return iVar5;
  case -6:
    VariantCopy(unaff_RBX,(VARIANTARG *)pvargSrc);
    goto LAB_18003f83a;
  case -4:
    (unaff_RBX->n1).n2.vt = 0x14;
    (unaff_RBX->n1).decVal.u2 = (_union_1719)pvargSrc->QueryInterface;
    break;
  case -3:
    (unaff_RBX->n1).n2.vt = 8;
    if (unaff_ESI == 0x13) {
      lVar8 = -1;
      do {
        lVar10 = lVar8;
        lVar8 = lVar10 + 1;
      } while (*(char *)((longlong)&pvargSrc->QueryInterface + lVar10 + 1) != (char)unaff_R12D);
      sVar1 = *(short *)((longlong)&pvargSrc->QueryInterface + lVar10 + 2);
      lVar8 = -1;
      do {
        lVar10 = lVar8;
        lVar8 = lVar10 + 1;
      } while (*(char *)((longlong)&pvargSrc->QueryInterface + lVar10 + 1) != (char)unaff_R12D);
      sVar2 = *(short *)((longlong)&pvargSrc->QueryInterface + lVar10 + 4);
      if (sVar1 != 0) {
        if ((ushort)(sVar2 - 1U) < 999) {
          bVar4 = FUN_18003b1d0(&DAT_180079aa0,399,sVar2,sVar1);
          if ((int)CONCAT71(extraout_var,bVar4) != 0) {
            _Var11 = (_union_1719)FUN_1800019d0(&DAT_180079aa0);
            (unaff_RBX->n1).decVal.u2 = _Var11;
            goto LAB_18003f83a;
          }
          pvargSrc = *(IUnknownVtbl **)(unaff_RBP + -0x18);
        }
        if (-1 < sVar2) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                     (unaff_RBP + -0x40),(char *)pvargSrc);
          iVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             (unaff_RBP + -0x40),'.');
          if (iVar5 != -1) {
            pCVar12 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                 (unaff_RBP + -0x40),(int)unaff_RBP + -0x30);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       (unaff_RBP + -0x40),pCVar12);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       (unaff_RBP + -0x30));
          }
          _Var11 = (_union_1719)FUN_1800019d0(*(LPCSTR *)(unaff_RBP + -0x40));
          (unaff_RBX->n1).decVal.u2 = _Var11;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                     (unaff_RBP + -0x40));
          goto LAB_18003f83a;
        }
      }
    }
    _Var11 = (_union_1719)FUN_1800019d0((LPCSTR)pvargSrc);
    (unaff_RBX->n1).decVal.u2 = _Var11;
LAB_18003f83a:
    pvargSrc = *(IUnknownVtbl **)(unaff_RBP + -0x18);
    break;
  case -2:
    (unaff_RBX->n1).n2.vt = 5;
    (unaff_RBX->n1).decVal.u2 = (_union_1719)pvargSrc->QueryInterface;
    break;
  case -1:
    (unaff_RBX->n1).n2.vt = 3;
    *(undefined4 *)((longlong)&unaff_RBX->n1 + 8) = *(undefined4 *)&pvargSrc->QueryInterface;
  }
  if (*(code **)(unaff_RBP + -0x10) != (code *)0x0) {
    (**(code **)(unaff_RBP + -0x10))(pvargSrc);
  }
  return 0;
}

/* ---- FUNC 0003F5B8 FUN_18003f5b8 (24 bytes) ---- */

void FUN_18003f5b8(void)

{
  return;
}

/* ---- FUNC 0003F5D0 FUN_18003f5d0 (14 bytes) ---- */

void FUN_18003f5d0(void)

{
  longlong *unaff_RDI;
  
  (**(code **)(*unaff_RDI + 0x208))();
  return;
}

/* ---- FUNC 0003F890 FUN_18003f890 (59 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18003f890(longlong *param_1,LPCOLESTR param_2,undefined2 *param_3)

{
  HRESULT HVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined1 auStack_58 [32];
  longlong local_38;
  CLSID local_30;
  ulonglong local_20;
  
  local_20 = DAT_180077818 ^ (ulonglong)auStack_58;
  if (DAT_1800797f8 != 0) {
    uVar3 = (**(code **)(*param_1 + 0x210))(param_1,0x7f3);
    return uVar3;
  }
  local_38 = 0;
  if (param_1[9] == 0) {
    uVar3 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
    return uVar3;
  }
  HVar1 = CLSIDFromString(param_2,&local_30);
  if (HVar1 != 0) {
    uVar3 = (**(code **)(*param_1 + 0x210))(param_1,0x7d1);
    return uVar3;
  }
  iVar2 = HAGetAttrType(param_1[9],1,&local_30,&local_38);
  if (iVar2 == -999) {
    lVar4 = *param_1;
    if (local_38 != 0) {
      uVar3 = (**(code **)(lVar4 + 0x208))();
      return uVar3;
    }
LAB_18003f9b9:
    uVar3 = (**(code **)(lVar4 + 0x210))(param_1,0x7d1);
  }
  else {
    if (0 < iVar2) {
      *param_3 = 5;
      return 0;
    }
    switch(iVar2) {
    case 0:
      *param_3 = 0;
      uVar3 = 0;
      break;
    case -10:
      *param_3 = 4;
      uVar3 = 0;
      break;
    default:
      lVar4 = *param_1;
      goto LAB_18003f9b9;
    case -6:
      *param_3 = 6;
      uVar3 = 0;
      break;
    case -3:
      *param_3 = 3;
      uVar3 = 0;
      break;
    case -2:
      *param_3 = 2;
      uVar3 = 0;
      break;
    case -1:
      *param_3 = 1;
      uVar3 = 0;
    }
  }
  return uVar3;
}

/* ---- FUNC 0003F8CB FUN_18003f8cb (86 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18003f8cb(longlong *param_1)

{
  HRESULT HVar1;
  int iVar2;
  LPCOLESTR in_RAX;
  undefined8 uVar3;
  longlong lVar4;
  longlong *unaff_RBX;
  undefined2 *unaff_RDI;
  longlong lStackX_20;
  
  lStackX_20 = 0;
  if (param_1[9] == 0) {
    uVar3 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
    return uVar3;
  }
  HVar1 = CLSIDFromString(in_RAX,(LPCLSID)&stack0x00000028);
  if (HVar1 != 0) {
    uVar3 = (**(code **)(*unaff_RBX + 0x210))();
    return uVar3;
  }
  iVar2 = HAGetAttrType(unaff_RBX[9],1,&stack0x00000028,&lStackX_20);
  if (iVar2 == -999) {
    lVar4 = *unaff_RBX;
    if (lStackX_20 != 0) {
      uVar3 = (**(code **)(lVar4 + 0x208))();
      return uVar3;
    }
LAB_18003f9b9:
    uVar3 = (**(code **)(lVar4 + 0x210))();
  }
  else {
    if (0 < iVar2) {
      *unaff_RDI = 5;
      return 0;
    }
    switch(iVar2) {
    case 0:
      *unaff_RDI = 0;
      uVar3 = 0;
      break;
    case -10:
      *unaff_RDI = 4;
      uVar3 = 0;
      break;
    default:
      lVar4 = *unaff_RBX;
      goto LAB_18003f9b9;
    case -6:
      *unaff_RDI = 6;
      uVar3 = 0;
      break;
    case -3:
      *unaff_RDI = 3;
      uVar3 = 0;
      break;
    case -2:
      *unaff_RDI = 2;
      uVar3 = 0;
      break;
    case -1:
      *unaff_RDI = 1;
      uVar3 = 0;
    }
  }
  return uVar3;
}

/* ---- FUNC 0003F921 FUN_18003f921 (168 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18003f921(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong *unaff_RBX;
  undefined2 unaff_SI;
  undefined2 *unaff_RDI;
  longlong lStackX_20;
  
  iVar1 = HAGetAttrType(param_1,1,&stack0x00000028);
  if (iVar1 == -999) {
    lVar3 = *unaff_RBX;
    if (lStackX_20 != 0) {
      uVar2 = (**(code **)(lVar3 + 0x208))();
      return uVar2;
    }
LAB_18003f9b9:
    uVar2 = (**(code **)(lVar3 + 0x210))();
  }
  else {
    if (0 < iVar1) {
      *unaff_RDI = 5;
      return 0;
    }
    switch(iVar1) {
    case 0:
      *unaff_RDI = unaff_SI;
      uVar2 = 0;
      break;
    case -10:
      *unaff_RDI = 4;
      uVar2 = 0;
      break;
    default:
      lVar3 = *unaff_RBX;
      goto LAB_18003f9b9;
    case -6:
      *unaff_RDI = 6;
      uVar2 = 0;
      break;
    case -3:
      *unaff_RDI = 3;
      uVar2 = 0;
      break;
    case -2:
      *unaff_RDI = 2;
      uVar2 = 0;
      break;
    case -1:
      *unaff_RDI = 1;
      uVar2 = 0;
    }
  }
  return uVar2;
}

/* ---- FUNC 0003F9C9 FUN_18003f9c9 (5 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18003f9c9(void)

{
  return;
}

/* ---- FUNC 0003F9CE FUN_18003f9ce (20 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18003f9ce(void)

{
  return;
}

/* ---- FUNC 0003FA10 FUN_18003fa10 (67 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_18003fa10(IUnknownVtbl *param_1,LPCOLESTR param_2,undefined8 param_3,VARIANTARG *param_4)

{
  int iVar1;
  HRESULT HVar2;
  ULONG UVar3;
  _func_5156 *p_Var4;
  SAFEARRAY *pSVar5;
  void *pvVar6;
  _union_1719 _Var7;
  undefined1 auStackY_a8 [32];
  undefined8 *local_78;
  _union_1719 local_70 [2];
  IUnknownVtbl *local_60;
  code *local_58;
  SAFEARRAYBOUND local_50;
  CLSID local_48;
  ulonglong local_38;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStackY_a8;
  if (DAT_1800797f8 != 0) {
    iVar1 = (**(code **)(param_1->QueryInterface + 0x210))(param_1,0x7f3);
    return iVar1;
  }
  local_78 = (undefined8 *)0x0;
  if (param_1[3].QueryInterface == (_func_5156 *)0x0) {
    iVar1 = (**(code **)(param_1->QueryInterface + 0x210))(param_1,0x7d9);
    return iVar1;
  }
  HVar2 = CLSIDFromString(param_2,&local_48);
  if (HVar2 != 0) {
    iVar1 = (**(code **)(param_1->QueryInterface + 0x210))(param_1,0x7d1);
    return iVar1;
  }
  VariantInit(param_4);
  UVar3 = HAGetAttrType(param_1[3].QueryInterface,1,&local_48,&local_78);
  if (UVar3 != 0xfffffc19) {
    if (UVar3 != 0) {
      local_78 = (undefined8 *)HAGetAttr(param_1[3].QueryInterface,1,&local_48);
      if (local_78 == (undefined8 *)0x0) {
        if (local_60 != (IUnknownVtbl *)0x0) {
          if (0 < (int)UVar3) {
            local_50.lLbound = 0;
            local_50.cElements = UVar3;
            pSVar5 = SafeArrayCreate(0x11,1,&local_50);
            if (pSVar5 != (SAFEARRAY *)0x0) {
              iVar1 = (**(code **)(param_1->QueryInterface + 0x210))(param_1,0x7e1);
              return iVar1;
            }
            HVar2 = SafeArrayAccessData((SAFEARRAY *)0x0,(void **)local_70);
            if (-1 < HVar2) {
              pvVar6 = memcpy((void *)local_70[0],local_60,(longlong)(int)UVar3);
              if (pvVar6 != (void *)0x0) {
                if (local_58 != (code *)0x0) {
                  (*local_58)(local_60);
                }
                SafeArrayUnaccessData((SAFEARRAY *)0x0);
                (param_4->n1).n2.vt = 0x2000;
                (param_4->n1).decVal.u2.Lo64 = 0;
                return 0;
              }
              if (local_58 != (code *)0x0) {
                (*local_58)(local_60);
              }
              SafeArrayUnaccessData((SAFEARRAY *)0x0);
            }
            iVar1 = (**(code **)(param_1->QueryInterface + 0x210))(param_1,0x7d1);
            return iVar1;
          }
          switch(UVar3) {
          case 0:
            (param_4->n1).n2.vt = 0;
            break;
          case 0xfffffff6:
            (param_4->n1).n2.vt = 9;
            iVar1 = FUN_1800389d0(local_60,(IUnknownVtbl *)param_1[3].AddRef,param_1,0,
                                  (IUnknownVtbl *)param_1->Release,local_70);
            if (-1 < iVar1) {
              (param_4->n1).decVal.u2 = local_70[0];
              return 0;
            }
            return iVar1;
          case 0xfffffffa:
            VariantCopy(param_4,(VARIANTARG *)local_60);
            break;
          case 0xfffffffd:
            (param_4->n1).n2.vt = 8;
            _Var7 = (_union_1719)FUN_1800019d0((LPCSTR)local_60);
            (param_4->n1).decVal.u2 = _Var7;
            break;
          case 0xfffffffe:
            (param_4->n1).n2.vt = 5;
            (param_4->n1).decVal.u2 = (_union_1719)local_60->QueryInterface;
            break;
          case 0xffffffff:
            (param_4->n1).n2.vt = 3;
            *(undefined4 *)((longlong)&param_4->n1 + 8) = *(undefined4 *)&local_60->QueryInterface;
          }
          if (local_58 == (code *)0x0) {
            return 0;
          }
          (*local_58)(local_60);
          return 0;
        }
      }
      else {
        if (*(short *)(local_78 + 1) != 0) {
          p_Var4 = param_1->QueryInterface;
          goto LAB_18003fb5f;
        }
        if ((code *)*local_78 != (code *)0x0) {
          (*(code *)*local_78)(local_78);
        }
      }
    }
    (param_4->n1).n2.vt = 0;
    return 0;
  }
  p_Var4 = param_1->QueryInterface;
  if (local_78 == (undefined8 *)0x0) {
    iVar1 = (**(code **)(p_Var4 + 0x210))(param_1,0x7d1);
    return iVar1;
  }
LAB_18003fb5f:
  iVar1 = (**(code **)(p_Var4 + 0x208))(param_1);
  return iVar1;
}

/* ---- FUNC 0003FA53 FUN_18003fa53 (82 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_18003fa53(longlong *param_1)

{
  code *pcVar1;
  int iVar2;
  HRESULT HVar3;
  LPCOLESTR in_RAX;
  undefined8 *puVar4;
  _func_5156 *p_Var5;
  SAFEARRAY *pSVar6;
  void *pvVar7;
  _union_1719 _Var8;
  IUnknownVtbl *unaff_RBX;
  longlong unaff_RBP;
  VARIANTARG *unaff_RDI;
  IUnknownVtbl *pvargSrc;
  
  *(undefined8 *)(unaff_RBP + -0x19) = 0;
  if (param_1[9] == 0) {
    iVar2 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
    return iVar2;
  }
  HVar3 = CLSIDFromString(in_RAX,(LPCLSID)(unaff_RBP + 0x17));
  if (HVar3 != 0) {
    iVar2 = (**(code **)(unaff_RBX->QueryInterface + 0x210))();
    return iVar2;
  }
  VariantInit(unaff_RDI);
  iVar2 = HAGetAttrType(unaff_RBX[3].QueryInterface,1,unaff_RBP + 0x17,unaff_RBP + -0x19);
  if (iVar2 == -999) {
    p_Var5 = unaff_RBX->QueryInterface;
    if (*(longlong *)(unaff_RBP + -0x19) == 0) {
      iVar2 = (**(code **)(p_Var5 + 0x210))();
      return iVar2;
    }
LAB_18003fb5f:
    iVar2 = (**(code **)(p_Var5 + 0x208))();
    return iVar2;
  }
  if (iVar2 == 0) {
LAB_18003fb2c:
    (unaff_RDI->n1).n2.vt = 0;
    return 0;
  }
  puVar4 = (undefined8 *)HAGetAttr(unaff_RBX[3].QueryInterface,1,unaff_RBP + 0x17);
  *(undefined8 **)(unaff_RBP + -0x19) = puVar4;
  if (puVar4 != (undefined8 *)0x0) {
    if (*(short *)(puVar4 + 1) != 0) {
      p_Var5 = unaff_RBX->QueryInterface;
      goto LAB_18003fb5f;
    }
    if ((code *)*puVar4 != (code *)0x0) {
      (*(code *)*puVar4)(puVar4);
    }
    goto LAB_18003fb2c;
  }
  pvargSrc = *(IUnknownVtbl **)(unaff_RBP + -1);
  if (pvargSrc == (IUnknownVtbl *)0x0) goto LAB_18003fb2c;
  if (0 < iVar2) {
    *(undefined4 *)(unaff_RBP + 0x13) = 0;
    *(int *)(unaff_RBP + 0xf) = iVar2;
    pSVar6 = SafeArrayCreate(0x11,1,(SAFEARRAYBOUND *)(unaff_RBP + 0xf));
    if (pSVar6 != (SAFEARRAY *)0x0) {
      iVar2 = (**(code **)(unaff_RBX->QueryInterface + 0x210))();
      return iVar2;
    }
    HVar3 = SafeArrayAccessData((SAFEARRAY *)0x0,(void **)(unaff_RBP + -0x11));
    if (-1 < HVar3) {
      pvVar7 = memcpy(*(void **)(unaff_RBP + -0x11),*(void **)(unaff_RBP + -1),(longlong)iVar2);
      pcVar1 = *(code **)(unaff_RBP + 7);
      if (pvVar7 != (void *)0x0) {
        if (pcVar1 != (code *)0x0) {
          (*pcVar1)();
        }
        SafeArrayUnaccessData((SAFEARRAY *)0x0);
        (unaff_RDI->n1).n2.vt = 0x2000;
        (unaff_RDI->n1).decVal.u2.Lo64 = 0;
        return 0;
      }
      if (pcVar1 != (code *)0x0) {
        (*pcVar1)();
      }
      SafeArrayUnaccessData((SAFEARRAY *)0x0);
    }
    iVar2 = (**(code **)(unaff_RBX->QueryInterface + 0x210))();
    return iVar2;
  }
  switch(iVar2) {
  case 0:
    (unaff_RDI->n1).n2.vt = 0;
    break;
  case -10:
    (unaff_RDI->n1).n2.vt = 9;
    iVar2 = FUN_1800389d0(pvargSrc,(IUnknownVtbl *)unaff_RBX[3].AddRef,unaff_RBX,0,
                          (IUnknownVtbl *)unaff_RBX->Release,(undefined8 *)(unaff_RBP + -0x11));
    if (-1 < iVar2) {
      (unaff_RDI->n1).decVal.u2 = *(_union_1719 *)(unaff_RBP + -0x11);
      return 0;
    }
    return iVar2;
  case -6:
    VariantCopy(unaff_RDI,(VARIANTARG *)pvargSrc);
    goto LAB_18003fcbc;
  case -3:
    (unaff_RDI->n1).n2.vt = 8;
    _Var8 = (_union_1719)FUN_1800019d0((LPCSTR)pvargSrc);
    (unaff_RDI->n1).decVal.u2 = _Var8;
LAB_18003fcbc:
    pvargSrc = *(IUnknownVtbl **)(unaff_RBP + -1);
    break;
  case -2:
    (unaff_RDI->n1).n2.vt = 5;
    (unaff_RDI->n1).decVal.u2 = (_union_1719)pvargSrc->QueryInterface;
    break;
  case -1:
    (unaff_RDI->n1).n2.vt = 3;
    *(undefined4 *)((longlong)&unaff_RDI->n1 + 8) = *(undefined4 *)&pvargSrc->QueryInterface;
  }
  if (*(code **)(unaff_RBP + 7) != (code *)0x0) {
    (**(code **)(unaff_RBP + 7))(pvargSrc);
  }
  return 0;
}

/* ---- FUNC 0003FAA5 FUN_18003faa5 (562 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_18003faa5(VARIANTARG *param_1)

{
  code *pcVar1;
  int iVar2;
  HRESULT HVar3;
  undefined8 *puVar4;
  _func_5156 *p_Var5;
  SAFEARRAY *pSVar6;
  void *pvVar7;
  _union_1719 _Var8;
  IUnknownVtbl *unaff_RBX;
  longlong unaff_RBP;
  VARIANTARG *unaff_RDI;
  IUnknownVtbl *pvargSrc;
  VARTYPE VVar9;
  undefined8 unaff_R14;
  
  VariantInit(param_1);
  iVar2 = HAGetAttrType(unaff_RBX[3].QueryInterface,1,unaff_RBP + 0x17,unaff_RBP + -0x19);
  if (iVar2 == -999) {
    p_Var5 = unaff_RBX->QueryInterface;
    if (*(longlong *)(unaff_RBP + -0x19) == 0) {
      iVar2 = (**(code **)(p_Var5 + 0x210))();
      return iVar2;
    }
LAB_18003fb5f:
    iVar2 = (**(code **)(p_Var5 + 0x208))();
    return iVar2;
  }
  VVar9 = (VARTYPE)unaff_R14;
  if (iVar2 == 0) {
LAB_18003fb2c:
    (unaff_RDI->n1).n2.vt = VVar9;
    return 0;
  }
  puVar4 = (undefined8 *)HAGetAttr(unaff_RBX[3].QueryInterface,1,unaff_RBP + 0x17);
  *(undefined8 **)(unaff_RBP + -0x19) = puVar4;
  if (puVar4 != (undefined8 *)0x0) {
    if (*(VARTYPE *)(puVar4 + 1) != VVar9) {
      p_Var5 = unaff_RBX->QueryInterface;
      goto LAB_18003fb5f;
    }
    if ((code *)*puVar4 != (code *)0x0) {
      (*(code *)*puVar4)(puVar4);
    }
    goto LAB_18003fb2c;
  }
  pvargSrc = *(IUnknownVtbl **)(unaff_RBP + -1);
  if (pvargSrc == (IUnknownVtbl *)0x0) goto LAB_18003fb2c;
  if (0 < iVar2) {
    *(int *)(unaff_RBP + 0x13) = (int)unaff_R14;
    *(int *)(unaff_RBP + 0xf) = iVar2;
    pSVar6 = SafeArrayCreate(0x11,1,(SAFEARRAYBOUND *)(unaff_RBP + 0xf));
    if (pSVar6 != (SAFEARRAY *)0x0) {
      iVar2 = (**(code **)(unaff_RBX->QueryInterface + 0x210))();
      return iVar2;
    }
    HVar3 = SafeArrayAccessData((SAFEARRAY *)0x0,(void **)(unaff_RBP + -0x11));
    if (-1 < HVar3) {
      pvVar7 = memcpy(*(void **)(unaff_RBP + -0x11),*(void **)(unaff_RBP + -1),(longlong)iVar2);
      pcVar1 = *(code **)(unaff_RBP + 7);
      if (pvVar7 != (void *)0x0) {
        if (pcVar1 != (code *)0x0) {
          (*pcVar1)();
        }
        SafeArrayUnaccessData((SAFEARRAY *)0x0);
        (unaff_RDI->n1).n2.vt = 0x2000;
        *(undefined8 *)((longlong)&unaff_RDI->n1 + 8) = unaff_R14;
        return 0;
      }
      if (pcVar1 != (code *)0x0) {
        (*pcVar1)();
      }
      SafeArrayUnaccessData((SAFEARRAY *)0x0);
    }
    iVar2 = (**(code **)(unaff_RBX->QueryInterface + 0x210))();
    return iVar2;
  }
  switch(iVar2) {
  case 0:
    (unaff_RDI->n1).n2.vt = VVar9;
    break;
  case -10:
    (unaff_RDI->n1).n2.vt = 9;
    iVar2 = FUN_1800389d0(pvargSrc,(IUnknownVtbl *)unaff_RBX[3].AddRef,unaff_RBX,0,
                          (IUnknownVtbl *)unaff_RBX->Release,(undefined8 *)(unaff_RBP + -0x11));
    if (-1 < iVar2) {
      (unaff_RDI->n1).decVal.u2 = *(_union_1719 *)(unaff_RBP + -0x11);
      return 0;
    }
    return iVar2;
  case -6:
    VariantCopy(unaff_RDI,(VARIANTARG *)pvargSrc);
    goto LAB_18003fcbc;
  case -3:
    (unaff_RDI->n1).n2.vt = 8;
    _Var8 = (_union_1719)FUN_1800019d0((LPCSTR)pvargSrc);
    (unaff_RDI->n1).decVal.u2 = _Var8;
LAB_18003fcbc:
    pvargSrc = *(IUnknownVtbl **)(unaff_RBP + -1);
    break;
  case -2:
    (unaff_RDI->n1).n2.vt = 5;
    (unaff_RDI->n1).decVal.u2 = (_union_1719)pvargSrc->QueryInterface;
    break;
  case -1:
    (unaff_RDI->n1).n2.vt = 3;
    *(undefined4 *)((longlong)&unaff_RDI->n1 + 8) = *(undefined4 *)&pvargSrc->QueryInterface;
  }
  if (*(code **)(unaff_RBP + 7) != (code *)0x0) {
    (**(code **)(unaff_RBP + 7))(pvargSrc);
  }
  return 0;
}

/* ---- FUNC 0003FB3A FUN_18003fb3a (8 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18003fb3a(void)

{
  return;
}

/* ---- FUNC 0003FB42 FUN_18003fb42 (23 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18003fb42(void)

{
  return;
}

/* ---- FUNC 0003FB59 FUN_18003fb59 (14 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18003fb59(void)

{
  longlong *unaff_RBX;
  
  (**(code **)(*unaff_RBX + 0x208))();
  return;
}

/* ---- FUNC 0003FD10 FUN_18003fd10 (99 bytes) ---- */

undefined8 FUN_18003fd10(longlong *param_1,int *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018003fd2e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(*param_1 + 0x210))(param_1,0x7f3);
    return uVar2;
  }
  if (param_1[9] == 0) {
                    /* WARNING: Could not recover jumptable at 0x00018003fd48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
    return uVar2;
  }
  lVar1 = param_1[0x2c];
  *param_2 = (int)lVar1;
  if ((int)lVar1 == -1) {
    uVar2 = (**(code **)(*param_1 + 0x210))(param_1,0x7d1);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* ---- FUNC 0003FD80 FUN_18003fd80 (334 bytes) ---- */

ulonglong FUN_18003fd80(longlong *param_1,longlong *param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 *local_res18 [2];
  
  if (DAT_1800797f8 != 0) {
    uVar3 = (**(code **)(*param_1 + 0x210))(param_1,0x7f3);
    return uVar3;
  }
  if (param_1[9] == 0) {
    uVar3 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
    return uVar3;
  }
  if (param_1[0xf] != 0) {
    *param_2 = param_1[0xf];
    (**(code **)(*param_1 + 8))(param_1);
    return 0;
  }
  if ((int)param_1[0x2c] == -1) {
    uVar3 = (**(code **)(*param_1 + 0x210))(param_1,0x7d1);
    return uVar3;
  }
  if ((int)param_1[0x2c] == 0) {
    uVar3 = (**(code **)(*param_1 + 0x210))(param_1,0x7da);
    return uVar3;
  }
  FUN_180047ce0(param_1[9],local_res18,param_1[10],param_1);
  if (local_res18[0] == (undefined8 *)0x0) {
    DAT_1800797d4 = DAT_1800797d4 + 1;
    if ((code *)param_1[2] != (code *)0x0) {
      (*(code *)param_1[2])();
    }
  }
  uVar2 = (**(code **)*local_res18[0])(local_res18[0],&DAT_180063410,param_2);
  puVar1 = local_res18[0];
  if (((int)uVar2 < 0) && (local_res18[0] != (undefined8 *)0x0)) {
    FUN_1800473f0(local_res18[0]);
    FUN_180025ad0(puVar1);
  }
  param_1[0xf] = (longlong)local_res18[0];
  return (ulonglong)uVar2;
}

/* ---- FUNC 0003FED0 FUN_18003fed0 (54 bytes) ---- */

undefined8 FUN_18003fed0(longlong *param_1,short param_2,ushort *param_3)

{
  int iVar1;
  undefined8 uVar2;
  longlong local_res20;
  
  if (DAT_1800797f8 != 0) {
    uVar2 = (**(code **)(*param_1 + 0x210))(param_1,0x7f3);
    return uVar2;
  }
  local_res20 = 0;
  if (param_1[9] == 0) {
    uVar2 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
    return uVar2;
  }
  iVar1 = HAGetAttrType(param_1[9],(int)param_2,0,&local_res20);
  if (iVar1 != -999) {
    *param_3 = (ushort)(iVar1 != 0);
    return 0;
  }
  if (local_res20 != 0) {
    uVar2 = (**(code **)(*param_1 + 0x208))();
    return uVar2;
  }
  uVar2 = (**(code **)(*param_1 + 0x210))(param_1,0x7d1);
  return uVar2;
}

/* ---- FUNC 0003FF06 FUN_18003ff06 (50 bytes) ---- */

undefined8 FUN_18003ff06(longlong param_1,short param_2)

{
  int iVar1;
  undefined8 uVar2;
  longlong *unaff_RBX;
  ushort *unaff_RSI;
  longlong lStack0000000000000048;
  
  lStack0000000000000048 = 0;
  if (param_1 == 0) {
    uVar2 = (**(code **)(*unaff_RBX + 0x210))();
    return uVar2;
  }
  iVar1 = HAGetAttrType(param_1,(int)param_2,0,&stack0x00000048);
  if (iVar1 == -999) {
    if (lStack0000000000000048 != 0) {
      uVar2 = (**(code **)(*unaff_RBX + 0x208))();
      return uVar2;
    }
    uVar2 = (**(code **)(*unaff_RBX + 0x210))();
    return uVar2;
  }
  *unaff_RSI = (ushort)(iVar1 != 0);
  return 0;
}

/* ---- FUNC 0003FF38 FUN_18003ff38 (62 bytes) ---- */

undefined8 FUN_18003ff38(undefined8 param_1,short param_2)

{
  int iVar1;
  undefined8 uVar2;
  longlong *unaff_RBX;
  undefined2 *unaff_RSI;
  undefined8 unaff_RDI;
  longlong in_stack_00000048;
  
  iVar1 = HAGetAttrType(param_1,(int)param_2,0,&stack0x00000048);
  if (iVar1 != -999) {
    *unaff_RSI = (short)CONCAT71((int7)((ulonglong)unaff_RDI >> 8),iVar1 != 0);
    return 0;
  }
  if (in_stack_00000048 != 0) {
    uVar2 = (**(code **)(*unaff_RBX + 0x208))();
    return uVar2;
  }
  uVar2 = (**(code **)(*unaff_RBX + 0x210))();
  return uVar2;
}

/* ---- FUNC 0003FF76 FUN_18003ff76 (27 bytes) ---- */

void FUN_18003ff76(undefined8 param_1)

{
  longlong in_RAX;
  
  (**(code **)(in_RAX + 0x210))(param_1,0x7d1);
  return;
}

/* ---- FUNC 0003FF91 FUN_18003ff91 (27 bytes) ---- */

undefined8 FUN_18003ff91(void)

{
  int in_EAX;
  undefined2 *unaff_RSI;
  undefined8 unaff_RDI;
  
  *unaff_RSI = (short)CONCAT71((int7)((ulonglong)unaff_RDI >> 8),in_EAX != 0);
  return 0;
}

/* ---- FUNC 0003FFB0 FUN_18003ffb0 (59 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18003ffb0(longlong *param_1,LPCOLESTR param_2,ushort *param_3)

{
  HRESULT HVar1;
  int iVar2;
  undefined8 uVar3;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  CLSID local_30;
  ulonglong local_20;
  
  local_20 = DAT_180077818 ^ (ulonglong)auStack_58;
  if (DAT_1800797f8 == 0) {
    local_38 = 0;
    if (param_1[9] == 0) {
      uVar3 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
    }
    else {
      HVar1 = CLSIDFromString(param_2,&local_30);
      if (HVar1 == 0) {
        if (param_1[9] == 0) {
          uVar3 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
        }
        else {
          iVar2 = HAGetAttrType(param_1[9],1,&local_30,&local_38);
          uVar3 = 0;
          *param_3 = (ushort)(iVar2 != -999);
        }
      }
      else {
        uVar3 = (**(code **)(*param_1 + 0x210))(param_1,0x7d1);
      }
    }
  }
  else {
    uVar3 = (**(code **)(*param_1 + 0x210))(param_1,0x7f3);
  }
  return uVar3;
}

/* ---- FUNC 0003FFEB FUN_18003ffeb (139 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18003ffeb(longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  HRESULT HVar1;
  int iVar2;
  LPCOLESTR in_RAX;
  undefined8 uVar3;
  longlong *unaff_RBX;
  ushort *unaff_RSI;
  
  if (param_1[9] == 0) {
    uVar3 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9,param_3,param_4,0);
  }
  else {
    HVar1 = CLSIDFromString(in_RAX,(LPCLSID)&stack0x00000028);
    if (HVar1 == 0) {
      if (unaff_RBX[9] == 0) {
        uVar3 = (**(code **)(*unaff_RBX + 0x210))();
      }
      else {
        iVar2 = HAGetAttrType(unaff_RBX[9],1,&stack0x00000028,&stack0x00000020);
        uVar3 = 0;
        *unaff_RSI = (ushort)(iVar2 != -999);
      }
    }
    else {
      uVar3 = (**(code **)(*unaff_RBX + 0x210))();
    }
  }
  return uVar3;
}

/* ---- FUNC 00040076 FUN_180040076 (20 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180040076(void)

{
  return;
}

/* ---- FUNC 00040090 FUN_180040090 (56 bytes) ---- */

undefined8 FUN_180040090(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  char *pcVar1;
  BSTR pOVar2;
  
  if (*(longlong **)(param_1 + 0xe8) != (longlong *)0x0) {
    pcVar1 = FUN_18003a1d0(*(longlong **)(param_1 + 0xe8));
    pOVar2 = FUN_1800019d0(pcVar1);
    *param_3 = pOVar2;
    return 0;
  }
  return 0x80004005;
}

/* ---- FUNC 000400D0 FUN_1800400d0 (2091 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_1800400d0(longlong param_1,longlong *param_2)

{
  char cVar1;
  longlong lVar2;
  bool bVar3;
  bool bVar4;
  char ***pppcVar5;
  char *pcVar6;
  AcpBase *this;
  AcpBaseRecord *this_00;
  IAdbRecord *pIVar7;
  char *pcVar8;
  AcpFlowsheet *pAVar9;
  longlong lVar10;
  ulonglong uVar11;
  char ****ppppcVar12;
  char ****ppppcVar13;
  ulonglong uVar14;
  AString *this_01;
  int iVar15;
  char *pcVar16;
  size_t sVar17;
  undefined1 auStackY_2778 [32];
  ulonglong local_2748;
  size_t local_2740 [2];
  longlong *local_2730;
  AString local_2728 [16];
  longlong local_2718;
  longlong local_2710;
  _union_2707 local_2708;
  char ***local_26f0;
  ULONGLONG UStack_26e8;
  size_t local_26e0;
  ulonglong uStack_26d8;
  char ***local_26d0;
  ULONGLONG UStack_26c8;
  size_t local_26c0;
  ulonglong uStack_26b8;
  char ***local_26b0;
  ULONGLONG UStack_26a8;
  size_t local_26a0;
  ulonglong uStack_2698;
  char ***local_2688;
  _union_1719 _Stack_2680;
  size_t local_2678;
  ulonglong uStack_2670;
  char ***local_2668;
  undefined8 uStack_2660;
  ulonglong local_2658;
  ulonglong local_2650;
  char ***local_2648;
  undefined8 uStack_2640;
  undefined8 local_2638;
  ulonglong local_2630;
  AcpFlowsheet local_2628 [304];
  AcpArray<AString,AcpBlock> local_24f8 [144];
  AcpArray<AString,AcpStream> local_2468 [576];
  AcpFlowsheet local_2228 [1024];
  AcpFlowsheet local_1e28 [376];
  AcpArray<AString,AcpFlowsheet> local_1cb0 [7272];
  ulonglong local_48;
  undefined8 uStack_40;
  
  uStack_26b8 = _UNK_180065b88;
  local_26c0 = _DAT_180065b80;
  uStack_40 = 0x1800400f2;
  local_48 = DAT_180077818 ^ (ulonglong)auStackY_2778;
  *param_2 = 0;
  lVar2 = *(longlong *)(param_1 + 0x178);
  bVar4 = false;
  bVar3 = false;
  local_2740[0] = 0;
  local_2678 = 0;
  local_2748 = 0xf;
  uStack_2670 = 0xf;
  _Stack_2680.Lo64 = 0;
  local_2688 = (char ***)0x0;
  UStack_26c8 = 0;
  local_26d0 = (char ***)0x0;
  ppppcVar12 = (char ****)local_2688;
  local_2730 = param_2;
  local_2718 = param_1;
  if (lVar2 != 0) {
    pcVar8 = (char *)(param_1 + 0x168);
    pcVar6 = pcVar8;
    if (0xf < *(ulonglong *)(param_1 + 0x180)) {
      pcVar6 = *(char **)pcVar8;
    }
    uVar14 = *(ulonglong *)(param_1 + 0x178);
    if (uVar14 == 0) {
LAB_1800401b2:
      iVar15 = -1;
    }
    else {
      lVar10 = -1;
      if (uVar14 - 1 != -1) {
        lVar10 = uVar14 - 1;
      }
      pcVar16 = pcVar6 + lVar10;
      cVar1 = *pcVar16;
      while (cVar1 != '.') {
        if (pcVar16 == pcVar6) goto LAB_1800401b2;
        pcVar16 = pcVar16 + -1;
        cVar1 = *pcVar16;
      }
      iVar15 = (int)pcVar16 - (int)pcVar6;
    }
    if (0 < iVar15) {
      uVar11 = (ulonglong)(iVar15 + 1);
      local_26b0 = (char ***)0x0;
      UStack_26a8 = 0;
      local_26a0 = 0;
      uStack_2698 = 0;
      if (uVar14 < uVar11) {
LAB_1800408f6:
        uStack_2698 = 0;
        local_26a0 = 0;
        UStack_26a8 = 0;
        local_26b0 = (char ***)0x0;
                    /* WARNING: Subroutine does not return */
        FUN_18003f2d0();
      }
      sVar17 = 0xffffffffffffffff;
      if (uVar14 - uVar11 != 0xffffffffffffffff) {
        sVar17 = uVar14 - uVar11;
      }
      pcVar6 = pcVar8;
      if (0xf < *(ulonglong *)(param_1 + 0x180)) {
        pcVar6 = *(char **)pcVar8;
      }
      FUN_180037800(&local_26b0,pcVar6 + uVar11,sVar17);
      if (0xf < uStack_26b8) {
        ppppcVar12 = (char ****)local_26d0;
        if ((0xfff < uStack_26b8 + 1) &&
           (ppppcVar12 = (char ****)local_26d0[-1],
           (char *)0x1f < (char *)((longlong)local_26d0 + (-8 - (longlong)ppppcVar12))))
        goto LAB_1800403e5;
        FUN_180025ad0(ppppcVar12);
      }
      uVar14 = (longlong)iVar15;
      if (*(ulonglong *)(param_1 + 0x178) < (ulonglong)(longlong)iVar15) {
        uVar14 = *(size_t *)(param_1 + 0x178);
      }
      local_26d0 = local_26b0;
      UStack_26c8 = UStack_26a8;
      local_2658 = 0;
      local_2650 = 0;
      local_2668 = (char ***)0x0;
      uStack_2660 = 0;
      local_26c0 = local_26a0;
      uStack_26b8 = uStack_2698;
      if (0xf < *(ulonglong *)(param_1 + 0x180)) {
        pcVar8 = *(char **)pcVar8;
      }
      FUN_180037800(&local_2668,pcVar8,uVar14);
      ppppcVar12 = &local_2668;
      if (0xf < local_2650) {
        ppppcVar12 = (char ****)local_2668;
      }
      if (local_2658 == 0) {
LAB_1800402d2:
        iVar15 = -1;
      }
      else {
        lVar10 = -1;
        if (local_2658 - 1 != -1) {
          lVar10 = local_2658 - 1;
        }
        ppppcVar13 = (char ****)((longlong)ppppcVar12 + lVar10);
        cVar1 = *(char *)ppppcVar13;
        while (cVar1 != '.') {
          if (ppppcVar13 == ppppcVar12) goto LAB_1800402d2;
          ppppcVar13 = (char ****)((longlong)ppppcVar13 + -1);
          cVar1 = *(char *)ppppcVar13;
        }
        iVar15 = (int)ppppcVar13 - (int)ppppcVar12;
      }
      ppppcVar12 = (char ****)local_2688;
      bVar3 = bVar4;
      if (0 < iVar15) {
        uVar14 = (ulonglong)(iVar15 + 1);
        local_26b0 = (char ***)0x0;
        UStack_26a8 = 0;
        local_26a0 = 0;
        uStack_2698 = 0;
        if (local_2658 < uVar14) goto LAB_1800408f6;
        sVar17 = 0xffffffffffffffff;
        if (local_2658 - uVar14 != 0xffffffffffffffff) {
          sVar17 = local_2658 - uVar14;
        }
        ppppcVar12 = &local_2668;
        if (0xf < local_2650) {
          ppppcVar12 = (char ****)local_2668;
        }
        FUN_180037800(&local_26b0,(char *)((longlong)ppppcVar12 + uVar14),sVar17);
        uVar14 = uStack_2698;
        sVar17 = local_26a0;
        ppppcVar12 = (char ****)local_26b0;
        local_2688 = local_26b0;
        _Stack_2680.Lo64 = UStack_26a8;
        local_2740[0] = local_26a0;
        local_2748 = uStack_2698;
        local_2678 = local_26a0;
        uStack_2670 = uStack_2698;
        ppppcVar13 = &local_2688;
        if (0xf < uStack_2698) {
          ppppcVar13 = (char ****)local_26b0;
        }
        if ((local_26a0 != 6) || (iVar15 = memcmp(ppppcVar13,"Blocks",6), iVar15 != 0)) {
          ppppcVar13 = &local_2688;
          if (0xf < uVar14) {
            ppppcVar13 = ppppcVar12;
          }
          if ((sVar17 != 7) || (iVar15 = memcmp(ppppcVar13,"Streams",7), iVar15 != 0))
          goto LAB_1800403ba;
        }
        bVar3 = true;
      }
LAB_1800403ba:
      if (0xf < local_2650) {
        ppppcVar13 = (char ****)local_2668;
        if ((0xfff < local_2650 + 1) &&
           (ppppcVar13 = (char ****)local_2668[-1],
           (char *)0x1f < (char *)((longlong)local_2668 + (-8 - (longlong)ppppcVar13)))) {
LAB_1800403e5:
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        FUN_180025ad0(ppppcVar13);
      }
    }
  }
  FUN_18003e460((longlong *)&local_26f0,(longlong *)(param_1 + 0x168));
  if ((bVar3) || (lVar2 == 0)) {
    lVar10 = *(longlong *)(param_1 + 0x58);
    if (*(longlong *)(param_1 + 0x58) != 0) {
LAB_1800407e8:
      *local_2730 = lVar10;
      goto LAB_1800407f0;
    }
    this = operator_new(0xe68);
    if (this == (AcpBase *)0x0) {
      this = (AcpBase *)0x0;
    }
    else {
      this_00 = (AcpBaseRecord *)
                ConvertToAcpBaseRecord(*(undefined8 *)(*(longlong *)topfinfo_exref + 0x750));
      pIVar7 = AcpBaseRecord::Record(this_00);
      AcpTopRecord::AcpTopRecord((AcpTopRecord *)this,pIVar7,true);
      *(undefined ***)this = AcpTopRecord::vftable;
    }
    if (lVar2 != 0) {
      AcpReference<AcpFlowsheet>::operator_class_AcpFlowsheet
                ((AcpReference<AcpFlowsheet> *)(this + 0x58));
      AcpFlowsheet::AcpFlowsheet(local_2628,local_1e28);
      AcpFlowsheet::~AcpFlowsheet(local_1e28);
      do {
        uVar14 = uStack_26d8;
        sVar17 = local_26e0;
        pppcVar5 = local_26f0;
        ppppcVar13 = &local_26f0;
        if (0xf < uStack_26d8) {
          ppppcVar13 = (char ****)local_26f0;
        }
        if (local_26e0 != 0) {
          for (pcVar8 = memchr(ppppcVar13,0x2e,local_26e0); pcVar8 != (char *)0x0;
              pcVar8 = memchr(pcVar8 + 1,0x2e,
                              (size_t)((longlong)ppppcVar13 + (sVar17 - (longlong)(pcVar8 + 1))))) {
            if (*pcVar8 == '.') {
              iVar15 = (int)pcVar8 - (int)ppppcVar13;
              goto LAB_18004052e;
            }
          }
        }
        iVar15 = -1;
LAB_18004052e:
        if (iVar15 < 1) {
          ppppcVar13 = &local_2688;
          if (0xf < local_2748) {
            ppppcVar13 = ppppcVar12;
          }
          if ((local_2740[0] == 6) && (iVar15 = memcmp(ppppcVar13,"Blocks",6), iVar15 == 0)) {
            ppppcVar13 = &local_26d0;
            if (0xf < uStack_26b8) {
              ppppcVar13 = (char ****)local_26d0;
            }
            AString::AString(local_2728,(char *)ppppcVar13,true);
            this = (AcpBase *)AcpArray<AString,AcpBlock>::ValueAt(local_24f8,(AString *)local_2228);
            AcpBlock::~AcpBlock((AcpBlock *)local_2228);
            this_01 = local_2728;
          }
          else {
            ppppcVar13 = &local_26d0;
            if (0xf < uStack_26b8) {
              ppppcVar13 = (char ****)local_26d0;
            }
            AString::AString((AString *)local_2740,(char *)ppppcVar13,true);
            this = (AcpBase *)AcpArray<AString,AcpStream>::ValueAt(local_2468,(AString *)local_1e28)
            ;
            AcpStream::~AcpStream((AcpStream *)local_1e28);
            this_01 = (AString *)local_2740;
          }
          AString::~AString(this_01);
          AcpFlowsheet::~AcpFlowsheet(local_2628);
          param_1 = local_2718;
          break;
        }
        local_2638 = 0;
        local_2630 = 0;
        uVar11 = (longlong)iVar15;
        if (sVar17 < (ulonglong)(longlong)iVar15) {
          uVar11 = sVar17;
        }
        local_2648 = (char ***)0x0;
        uStack_2640 = 0;
        ppppcVar13 = &local_26f0;
        if (0xf < uVar14) {
          ppppcVar13 = (char ****)pppcVar5;
        }
        FUN_180037800(&local_2648,ppppcVar13,uVar11);
        uVar14 = (ulonglong)(iVar15 + 1);
        local_26a0 = 0;
        uStack_2698 = 0;
        local_26b0 = (char ***)0x0;
        UStack_26a8 = 0;
        if (local_26e0 < uVar14) {
                    /* WARNING: Subroutine does not return */
          FUN_18003f2d0();
        }
        sVar17 = 0xffffffffffffffff;
        if (local_26e0 - uVar14 != 0xffffffffffffffff) {
          sVar17 = local_26e0 - uVar14;
        }
        ppppcVar13 = &local_26f0;
        if (0xf < uStack_26d8) {
          ppppcVar13 = (char ****)local_26f0;
        }
        FUN_180037800(&local_26b0,(char *)((longlong)ppppcVar13 + uVar14),sVar17);
        if (0xf < uStack_26d8) {
          ppppcVar13 = (char ****)local_26f0;
          if ((0xfff < uStack_26d8 + 1) &&
             (ppppcVar13 = (char ****)local_26f0[-1],
             (char *)0x1f < (char *)((longlong)local_26f0 + (-8 - (longlong)ppppcVar13)))) {
LAB_1800406c3:
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
          FUN_180025ad0(ppppcVar13);
        }
        ppppcVar13 = &local_2648;
        if (0xf < local_2630) {
          ppppcVar13 = (char ****)local_2648;
        }
        local_26f0 = local_26b0;
        UStack_26e8 = UStack_26a8;
        local_26e0 = local_26a0;
        uStack_26d8 = uStack_2698;
        AString::AString(local_2728,(char *)ppppcVar13,true);
        AcpArray<AString,AcpBlock>::ValueAt(local_24f8,(AString *)local_1e28);
        AString::~AString(local_2728);
        pAVar9 = (AcpFlowsheet *)
                 AcpArray<AString,AcpFlowsheet>::ValueAtLocation(local_1cb0,(int)local_2228);
        AcpFlowsheet::operator=(local_2628,pAVar9);
        AcpFlowsheet::~AcpFlowsheet(local_2228);
        AcpBlock::~AcpBlock((AcpBlock *)local_1e28);
        if (0xf < local_2630) {
          ppppcVar13 = (char ****)local_2648;
          if ((0xfff < local_2630 + 1) &&
             (ppppcVar13 = (char ****)local_2648[-1],
             (char *)0x1f < (char *)((longlong)local_2648 + (-8 - (longlong)ppppcVar13))))
          goto LAB_1800406c3;
          FUN_180025ad0(ppppcVar13);
        }
      } while( true );
    }
    VariantInit((VARIANTARG *)&local_2708.n2);
    local_2688 = (char ***)local_2708._0_8_;
    _Stack_2680 = local_2708.decVal.u2;
    local_2678 = local_2708._16_8_;
    uVar14 = FUN_180001ab0(this,(longlong *)&local_2688,&local_2710,*(longlong **)(param_1 + 0x50),
                           param_1);
    uVar11 = uVar14 & 0xffffffff;
    if (-1 < (int)uVar14) {
      *(longlong *)(param_1 + 0x58) = local_2710;
      lVar10 = local_2710;
      goto LAB_1800407e8;
    }
  }
  else {
    *local_2730 = 0;
LAB_1800407f0:
    uVar11 = 0;
  }
  if (0xf < uStack_26d8) {
    ppppcVar13 = (char ****)local_26f0;
    if ((0xfff < uStack_26d8 + 1) &&
       (ppppcVar13 = (char ****)local_26f0[-1],
       (char *)0x1f < (char *)((longlong)local_26f0 + (-8 - (longlong)ppppcVar13))))
    goto LAB_1800408b5;
    FUN_180025ad0(ppppcVar13);
  }
  local_26e0 = 0;
  uStack_26d8 = 0xf;
  local_26f0 = (char ***)((ulonglong)local_26f0 & 0xffffffffffffff00);
  if (0xf < uStack_26b8) {
    ppppcVar13 = (char ****)local_26d0;
    if ((0xfff < uStack_26b8 + 1) &&
       (ppppcVar13 = (char ****)local_26d0[-1],
       (char *)0x1f < (char *)((longlong)local_26d0 + (-8 - (longlong)ppppcVar13))))
    goto LAB_1800408b5;
    FUN_180025ad0(ppppcVar13);
  }
  local_26d0 = (char ***)((ulonglong)local_26d0 & 0xffffffffffffff00);
  local_26c0 = _DAT_180065b80;
  uStack_26b8 = _UNK_180065b88;
  if (0xf < local_2748) {
    ppppcVar13 = ppppcVar12;
    if ((0xfff < local_2748 + 1) &&
       (ppppcVar13 = (char ****)ppppcVar12[-1],
       (char *)0x1f < (char *)((longlong)ppppcVar12 + (-8 - (longlong)ppppcVar13)))) {
LAB_1800408b5:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180025ad0(ppppcVar13);
  }
  return uVar11;
}

/* ---- FUNC 00040900 FUN_180040900 (279 bytes) ---- */

undefined8 FUN_180040900(longlong *param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  LPCSTR pCVar3;
  BSTR pOVar4;
  undefined4 uVar5;
  _union_2707 local_58;
  _union_2707 local_40;
  undefined4 local_28;
  ULONG UStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined8 local_18;
  
  if (DAT_1800797f8 != 0) {
    uVar2 = (**(code **)(*param_1 + 0x210))(param_1,0x7f3);
    return uVar2;
  }
  VariantInit((VARIANTARG *)&local_40.n2);
  VariantInit((VARIANTARG *)&local_58.n2);
  *param_2 = 0;
  local_28 = local_40._0_4_;
  UStack_24 = local_40.decVal.Hi32;
  uStack_20 = local_40._8_4_;
  uStack_1c = local_40._12_4_;
  local_18 = local_40._16_8_;
  (**(code **)(*param_1 + 0x98))(param_1,2,&local_28,&local_58);
  uVar1 = local_58._8_4_;
  if (((local_58.n2.vt == 3) && (local_58._8_4_ != 0)) && (local_58._8_4_ != 0x2c)) {
    local_28 = local_40._0_4_;
    UStack_24 = local_40.decVal.Hi32;
    uStack_20 = local_40._8_4_;
    uStack_1c = local_40._12_4_;
    local_18 = local_40._16_8_;
    (**(code **)(*param_1 + 0x98))(param_1,3,&local_28,&local_58);
    uVar5 = 0;
    if (local_58.n2.vt == 3) {
      uVar5 = local_58._8_4_;
    }
    pCVar3 = FUN_18001d4a0(param_1[10],uVar1,uVar5);
    pOVar4 = FUN_1800019d0(pCVar3);
    *param_2 = pOVar4;
  }
  return 0;
}

/* ---- FUNC 00040A20 FUN_180040a20 (95 bytes) ---- */

void FUN_180040a20(longlong *param_1,undefined4 *param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined8 local_18;
  
  lVar1 = *param_1;
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x000180040a39. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(lVar1 + 0x210))(param_1,0x7f3);
    return;
  }
  if (param_1[9] == 0) {
                    /* WARNING: Could not recover jumptable at 0x000180040a50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(lVar1 + 0x210))(param_1,0x7d9);
    return;
  }
  local_28 = *param_2;
  uStack_24 = param_2[1];
  uStack_20 = param_2[2];
  uStack_1c = param_2[3];
  local_18 = *(undefined8 *)(param_2 + 4);
  (**(code **)(lVar1 + 0x98))(local_28,0,&local_28,param_3);
  return;
}

/* ---- FUNC 00040A80 FUN_180040a80 (67 bytes) ---- */

undefined8 FUN_180040a80(longlong *param_1,short param_2,short param_3,VARIANTARG *param_4)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  _union_1719 _Var4;
  undefined8 *local_38;
  undefined1 local_30 [8];
  VARIANTARG *local_28;
  code *local_20;
  
  if (DAT_1800797f8 != 0) {
    uVar2 = (**(code **)(*param_1 + 0x210))(param_1,0x7f3);
    return uVar2;
  }
  local_38 = (undefined8 *)0x0;
  if (param_1[9] == 0) {
    uVar2 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
    return uVar2;
  }
  VariantInit(param_4);
  iVar1 = HAGetAttrType(param_1[9],0,0,&local_38);
  if (iVar1 != -999) {
    if (iVar1 != 0) {
      local_38 = (undefined8 *)
                 HAGetValForUnitsBasis(param_1[9],local_30,(int)param_2,(int)param_3,0);
      if (local_38 == (undefined8 *)0x0) {
        if (local_28 != (VARIANTARG *)0x0) {
          if (iVar1 == -6) {
            VariantCopy(param_4,local_28);
          }
          else if (iVar1 == -3) {
            (param_4->n1).n2.vt = 8;
            _Var4 = (_union_1719)FUN_1800019d0((LPCSTR)local_28);
            (param_4->n1).decVal.u2 = _Var4;
          }
          else if (iVar1 == -2) {
            (param_4->n1).n2.vt = 5;
            (param_4->n1).decVal.u2 = *(_union_1719 *)&local_28->n1;
          }
          else if (iVar1 == -1) {
            (param_4->n1).n2.vt = 3;
            *(undefined4 *)((longlong)&param_4->n1 + 8) = *(undefined4 *)&local_28->n1;
          }
          if (local_20 == (code *)0x0) {
            return 0;
          }
          (*local_20)(local_28);
          return 0;
        }
      }
      else {
        if (*(short *)(local_38 + 1) != 0) {
          lVar3 = *param_1;
          goto LAB_180040b97;
        }
        if ((code *)*local_38 != (code *)0x0) {
          (*(code *)*local_38)(local_38);
        }
      }
    }
    (param_4->n1).n2.vt = 0;
    return 0;
  }
  lVar3 = *param_1;
  if (local_38 == (undefined8 *)0x0) {
    uVar2 = (**(code **)(lVar3 + 0x210))(param_1,0x7d1);
    return uVar2;
  }
LAB_180040b97:
  uVar2 = (**(code **)(lVar3 + 0x208))(param_1);
  return uVar2;
}

/* ---- FUNC 00040AC3 FUN_180040ac3 (41 bytes) ---- */

undefined8 FUN_180040ac3(longlong *param_1)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  _union_1719 _Var4;
  longlong *unaff_RBX;
  undefined4 unaff_EBP;
  VARIANTARG *unaff_RDI;
  undefined4 unaff_R14D;
  undefined8 *puStack0000000000000030;
  VARIANTARG *in_stack_00000040;
  code *in_stack_00000048;
  
  puStack0000000000000030 = (undefined8 *)0x0;
  if (param_1[9] == 0) {
    uVar2 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
    return uVar2;
  }
  VariantInit(unaff_RDI);
  iVar1 = HAGetAttrType(unaff_RBX[9],0,0,&stack0x00000030);
  if (iVar1 != -999) {
    if (iVar1 != 0) {
      puStack0000000000000030 =
           (undefined8 *)HAGetValForUnitsBasis(unaff_RBX[9],&stack0x00000038,unaff_R14D,unaff_EBP,0)
      ;
      if (puStack0000000000000030 == (undefined8 *)0x0) {
        if (in_stack_00000040 != (VARIANTARG *)0x0) {
          if (iVar1 == -6) {
            VariantCopy(unaff_RDI,in_stack_00000040);
          }
          else if (iVar1 == -3) {
            (unaff_RDI->n1).n2.vt = 8;
            _Var4 = (_union_1719)FUN_1800019d0((LPCSTR)in_stack_00000040);
            (unaff_RDI->n1).decVal.u2 = _Var4;
          }
          else if (iVar1 == -2) {
            (unaff_RDI->n1).n2.vt = 5;
            (unaff_RDI->n1).decVal.u2 = *(_union_1719 *)&in_stack_00000040->n1;
          }
          else if (iVar1 == -1) {
            (unaff_RDI->n1).n2.vt = 3;
            *(undefined4 *)((longlong)&unaff_RDI->n1 + 8) = *(undefined4 *)&in_stack_00000040->n1;
          }
          if (in_stack_00000048 == (code *)0x0) {
            return 0;
          }
          (*in_stack_00000048)(in_stack_00000040);
          return 0;
        }
      }
      else {
        if (*(short *)(puStack0000000000000030 + 1) != 0) {
          lVar3 = *unaff_RBX;
          goto LAB_180040b97;
        }
        if ((code *)*puStack0000000000000030 != (code *)0x0) {
          (*(code *)*puStack0000000000000030)(puStack0000000000000030);
        }
      }
    }
    (unaff_RDI->n1).n2.vt = 0;
    return 0;
  }
  lVar3 = *unaff_RBX;
  if (puStack0000000000000030 == (undefined8 *)0x0) {
    uVar2 = (**(code **)(lVar3 + 0x210))();
    return uVar2;
  }
LAB_180040b97:
  uVar2 = (**(code **)(lVar3 + 0x208))();
  return uVar2;
}

/* ---- FUNC 00040AEC FUN_180040aec (289 bytes) ---- */

undefined8 FUN_180040aec(VARIANTARG *param_1)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  _union_1719 _Var4;
  longlong *unaff_RBX;
  undefined4 unaff_EBP;
  VARIANTARG *unaff_RDI;
  undefined4 unaff_R14D;
  VARTYPE unaff_R15W;
  undefined8 *in_stack_00000030;
  VARIANTARG *in_stack_00000040;
  code *in_stack_00000048;
  
  VariantInit(param_1);
  iVar1 = HAGetAttrType(unaff_RBX[9],0,0,&stack0x00000030);
  if (iVar1 == -999) {
    lVar3 = *unaff_RBX;
    if (in_stack_00000030 == (undefined8 *)0x0) {
      uVar2 = (**(code **)(lVar3 + 0x210))();
      return uVar2;
    }
LAB_180040b97:
    uVar2 = (**(code **)(lVar3 + 0x208))();
    return uVar2;
  }
  if (iVar1 != 0) {
    in_stack_00000030 =
         (undefined8 *)HAGetValForUnitsBasis(unaff_RBX[9],&stack0x00000038,unaff_R14D,unaff_EBP);
    if (in_stack_00000030 == (undefined8 *)0x0) {
      if (in_stack_00000040 != (VARIANTARG *)0x0) {
        if (iVar1 == -6) {
          VariantCopy(unaff_RDI,in_stack_00000040);
        }
        else if (iVar1 == -3) {
          (unaff_RDI->n1).n2.vt = 8;
          _Var4 = (_union_1719)FUN_1800019d0((LPCSTR)in_stack_00000040);
          (unaff_RDI->n1).decVal.u2 = _Var4;
        }
        else if (iVar1 == -2) {
          (unaff_RDI->n1).n2.vt = 5;
          (unaff_RDI->n1).decVal.u2 = *(_union_1719 *)&in_stack_00000040->n1;
        }
        else if (iVar1 == -1) {
          (unaff_RDI->n1).n2.vt = 3;
          *(undefined4 *)((longlong)&unaff_RDI->n1 + 8) = *(undefined4 *)&in_stack_00000040->n1;
        }
        if (in_stack_00000048 == (code *)0x0) {
          return 0;
        }
        (*in_stack_00000048)(in_stack_00000040);
        return 0;
      }
    }
    else {
      if (*(VARTYPE *)(in_stack_00000030 + 1) != unaff_R15W) {
        lVar3 = *unaff_RBX;
        goto LAB_180040b97;
      }
      if ((code *)*in_stack_00000030 != (code *)0x0) {
        (*(code *)*in_stack_00000030)(in_stack_00000030);
      }
    }
  }
  (unaff_RDI->n1).n2.vt = unaff_R15W;
  return 0;
}

/* ---- FUNC 00040B7B FUN_180040b7b (22 bytes) ---- */

void FUN_180040b7b(void)

{
  return;
}

/* ---- FUNC 00040B91 FUN_180040b91 (14 bytes) ---- */

void FUN_180040b91(void)

{
  longlong *unaff_RBX;
  
  (**(code **)(*unaff_RBX + 0x208))();
  return;
}

/* ---- FUNC 00040C10 FUN_180040c10 (55 bytes) ---- */

void FUN_180040c10(longlong *param_1,undefined8 param_2)

{
  longlong lVar1;
  
  lVar1 = *param_1;
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x000180040c24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(lVar1 + 0x210))(param_1,0x7f3);
    return;
  }
  if (param_1[9] == 0) {
                    /* WARNING: Could not recover jumptable at 0x000180040c37. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(lVar1 + 0x210))(param_1,0x7d9);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000180040c40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(lVar1 + 0x90))(param_1,0,param_2);
  return;
}

/* ---- FUNC 00040C50 FUN_180040c50 (2082 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */

HRESULT FUN_180040c50(longlong *param_1,VARTYPE param_2,VARIANTARG *param_3,VARIANTARG *param_4)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  VARIANTARG *pVVar1;
  ushort uVar2;
  undefined8 *puVar3;
  short *psVar4;
  longlong *plVar5;
  code *pcVar6;
  undefined8 uVar7;
  HRESULT HVar8;
  int iVar9;
  UINT UVar10;
  ULONG UVar11;
  void *_Dst;
  void *pvVar12;
  longlong lVar13;
  ulonglong uVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined4 uVar17;
  VARIANTARG *pVVar18;
  SAFEARRAY *psa;
  LPCWSTR lpWideCharStr;
  VARTYPE vt;
  int iVar19;
  size_t _Size;
  bool bVar20;
  undefined8 uStackY_110;
  undefined1 auStackY_108 [32];
  int aiStack_e0 [2];
  undefined8 local_d8 [2];
  undefined1 local_c8 [24];
  VARIANTARG *local_b0;
  int local_a8;
  VARIANTARG local_a0;
  VARIANTARG *local_88 [2];
  undefined8 local_78;
  _union_1719 _Stack_70;
  undefined8 local_68;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_38;
  
  puVar15 = auStackY_108;
  puVar16 = auStackY_108;
  local_38 = DAT_180077818 ^ (ulonglong)local_c8;
  iVar19 = (int)(short)param_2;
  local_c8._0_2_ = param_2;
  if (DAT_1800797f8 != 0) {
    uStackY_110 = 0x180040cb5;
    HVar8 = (**(code **)(*param_1 + 0x210))(param_1,0x7f3);
    puVar16 = auStackY_108;
    goto LAB_18004143d;
  }
  pVVar18 = (VARIANTARG *)0x0;
  local_c8._16_8_ = 0;
  if (param_1[9] == 0) {
    uStackY_110 = 0x180040cd4;
    HVar8 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
    puVar16 = auStackY_108;
    goto LAB_18004143d;
  }
  uVar2 = (param_3->n1).n2.vt;
  if (uVar2 == 0x400c) {
    puVar3 = *(undefined8 **)((longlong)&param_3->n1 + 8);
    local_78 = *(undefined8 *)&param_4->n1;
    _Stack_70 = (param_4->n1).decVal.u2;
    local_68 = *(undefined8 *)((longlong)&param_4->n1 + 0x10);
    local_58 = *puVar3;
    uStack_50 = puVar3[1];
    local_48 = puVar3[2];
    uStackY_110 = 0x180040d29;
    HVar8 = (**(code **)(*param_1 + 0xa0))(*(undefined4 *)puVar3,param_2,&local_58,&local_78);
    puVar16 = auStackY_108;
    goto LAB_18004143d;
  }
  uVar17 = 0;
  if (0xb < uVar2) {
    if (uVar2 == 0x4002) {
      uVar17 = (int)**(short **)((longlong)&param_3->n1 + 8);
      goto LAB_180040dd8;
    }
    if (uVar2 == 0x4003) {
      uVar17 = **(uint **)((longlong)&param_3->n1 + 8);
      goto LAB_180040dd8;
    }
    if (uVar2 == 0x400b) {
      uVar17 = (uint)(**(short **)((longlong)&param_3->n1 + 8) != 0);
      goto LAB_180040dd8;
    }
LAB_180040d84:
    uStackY_110 = 0x180040d97;
    HVar8 = VariantChangeType(&local_a0,param_3,0,3);
    uVar17 = local_a0.n1._8_4_;
    if (HVar8 == 0) goto LAB_180040dd8;
    goto LAB_180040d9b;
  }
  if (uVar2 == 0xb) {
    uVar17 = (uint)(*(short *)((longlong)&param_3->n1 + 8) != 0);
  }
  else if (uVar2 != 0) {
    if (uVar2 == 2) {
      uVar17 = (int)*(short *)((longlong)&param_3->n1 + 8);
    }
    else if (uVar2 == 3) {
      uVar17 = *(uint *)((longlong)&param_3->n1 + 8);
    }
    else if (uVar2 != 10) goto LAB_180040d84;
  }
LAB_180040dd8:
  if ((param_4->n1).n2.vt == 0x400c) {
    puVar3 = *(undefined8 **)((longlong)&param_4->n1 + 8);
    local_58 = *puVar3;
    uStack_50 = puVar3[1];
    local_48 = puVar3[2];
    local_78 = *(undefined8 *)&param_3->n1;
    _Stack_70 = (param_3->n1).decVal.u2;
    local_68 = *(undefined8 *)((longlong)&param_3->n1 + 0x10);
    uStackY_110 = 0x180040e1f;
    HVar8 = (**(code **)(*param_1 + 0xa0))(param_1,param_2,&local_78,&local_58);
    puVar16 = auStackY_108;
    goto LAB_18004143d;
  }
  uStackY_110 = 0x180040e2e;
  VariantInit(&local_a0);
  if (param_1[9] == 0) {
    uStackY_110 = 0x180040e48;
    HVar8 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
    puVar16 = auStackY_108;
    goto LAB_18004143d;
  }
  uStackY_110 = 0x180040e61;
  local_a8 = iVar19;
  iVar9 = HAGetAttrType(param_1[9],iVar19,0);
  if (iVar9 == -999) {
    lVar13 = *param_1;
    puVar15 = auStackY_108;
    if (local_c8._16_8_ == 0) {
      uStackY_110 = 0x180040e88;
      HVar8 = (**(code **)(lVar13 + 0x210))(param_1,0x7d1);
      puVar16 = auStackY_108;
      goto LAB_18004143d;
    }
  }
  else {
    if (iVar9 == 0) {
      uStackY_110 = 0x180040ea2;
      HVar8 = (**(code **)(*param_1 + 0x210))(param_1,0x7e6);
      puVar16 = auStackY_108;
      goto LAB_18004143d;
    }
    uVar2 = (param_4->n1).n2.vt;
    if (uVar2 == 0) {
LAB_180040f0c:
      uStackY_110 = 0x180040f24;
      local_c8._16_8_ = HASetAttr(param_1[9],iVar19,0,0);
      puVar15 = auStackY_108;
      puVar16 = auStackY_108;
      if (local_c8._16_8_ == 0) {
LAB_180041347:
        uVar7 = local_c8._16_8_;
        if (param_2 == 0) {
          pcVar6 = *(code **)(*param_1 + 0x130);
          *(undefined8 *)(puVar16 + -8) = 0x180041359;
          (*pcVar6)(param_1,uVar7);
LAB_180041366:
          *(undefined4 *)(param_1[10] + 0x100) = 1;
          if ((param_2 == 0) || (param_2 == 3)) {
            *(undefined8 *)(puVar16 + -8) = 0x180041392;
            FUN_18003d280((longlong)param_1,4);
            this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x3b)
            ;
            *(undefined8 *)(puVar16 + -8) = 0x1800413a9;
            iVar19 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                     CompareNoCase(this,"RUN_CLASS");
            if (iVar19 == 0) {
              *(undefined8 *)(puVar16 + -8) = 0x1800413b8;
              FUN_1800374c0(0x6e,(longlong *)this);
            }
            else {
              *(undefined8 *)(puVar16 + -8) = 0x1800413ca;
              iVar19 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                       CompareNoCase(this,"INPUT_MODE");
              if (iVar19 == 0) {
                *(undefined8 *)(puVar16 + -8) = 0x1800413d9;
                FUN_1800374c0(0x71,(longlong *)this);
              }
              else {
                *(undefined8 *)(puVar16 + -8) = 0x1800413eb;
                iVar19 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                         CompareNoCase(this,"FCVAR1");
                if (iVar19 != 0) {
                  *(undefined8 *)(puVar16 + -8) = 0x1800413ff;
                  iVar19 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                           CompareNoCase(this,"FCVAR2");
                  if (iVar19 != 0) {
                    if (DAT_18007988c == 0) {
                      *(undefined8 *)(puVar16 + -8) = 0x180041425;
                      FUN_1800374c0(0x67,(longlong *)this);
                      lVar13 = param_1[10];
                      *(undefined8 *)(puVar16 + -8) = 0x180041431;
                      FUN_180011410(lVar13,param_1);
                    }
                    else {
                      DAT_180079890 = 1;
                    }
                  }
                }
              }
            }
          }
        }
        else if (param_2 != 0x14) goto LAB_180041366;
        *(undefined8 *)(puVar16 + -8) = 0x18004143b;
        VariantClear(&local_a0);
        HVar8 = 0;
        goto LAB_18004143d;
      }
    }
    else {
      if ((((uVar2 != 9) && (uVar2 != 0xd)) && (uVar2 != 0x4009)) && (uVar2 != 0x400d)) {
        if (uVar2 == 8) {
          if (((param_4->n1).decVal.u2.Lo64 != 0) &&
             (psVar4 = *(short **)((longlong)&param_4->n1 + 8), psVar4 != (short *)0x0)) {
            bVar20 = *psVar4 == 0;
LAB_180040f0a:
            if (!bVar20) goto LAB_180040f4b;
          }
        }
        else {
          if (uVar2 != 0x4008) goto LAB_180040f4b;
          plVar5 = *(longlong **)((longlong)&param_4->n1 + 8);
          if (plVar5 != (longlong *)0x0) {
            bVar20 = *plVar5 == 0;
            goto LAB_180040f0a;
          }
        }
        goto LAB_180040f0c;
      }
      if ((param_4->n1).decVal.u2.Lo64 == 0) goto LAB_180040f0c;
LAB_180040f4b:
      if (0 < iVar9) {
        psa = *(SAFEARRAY **)((longlong)&param_4->n1 + 8);
        if ((uVar2 & 0x4000) != 0) {
          psa = *(SAFEARRAY **)psa;
        }
        uStackY_110 = 0x180040f68;
        UVar10 = SafeArrayGetDim(psa);
        if (UVar10 != 1) goto LAB_180040d9b;
        uStackY_110 = 0x180040f80;
        SafeArrayGetLBound(psa,1,&(((_union_2707 *)local_c8)->n2).n3.lVal);
        uStackY_110 = 0x180040f92;
        SafeArrayGetUBound(psa,1,(LONG *)&(((_union_2707 *)local_c8)->n2).wReserved2);
        uStackY_110 = 0x180040f9b;
        UVar10 = SafeArrayGetElemsize(psa);
        _Size = (longlong)(int)(local_c8._4_4_ - local_c8._8_4_) * (ulonglong)UVar10;
        uStackY_110 = 0x180040fb2;
        _Dst = (void *)MDmalloc(_Size);
        if (_Dst == (void *)0x0) {
          uStackY_110 = 0x180040fcb;
          HVar8 = (**(code **)(*param_1 + 0x210))(param_1,0x7e1);
          puVar16 = auStackY_108;
          goto LAB_18004143d;
        }
        uStackY_110 = 0x180040fdd;
        HVar8 = SafeArrayAccessData(psa,&local_b0);
        puVar16 = auStackY_108;
        if (HVar8 < 0) goto LAB_18004143d;
        uStackY_110 = 0x180040ff4;
        pvVar12 = memcpy(_Dst,local_b0,_Size);
        if (pvVar12 == (void *)0x0) {
          uStackY_110 = 0x180041001;
          MDfree(_Dst);
          uStackY_110 = 0x18004100a;
          SafeArrayUnaccessData(psa);
          uStackY_110 = 0x18004101b;
          HVar8 = (**(code **)(*param_1 + 0x210))(param_1,0x7d1);
          puVar16 = auStackY_108;
          goto LAB_18004143d;
        }
        uStackY_110 = 0x180041029;
        SafeArrayUnaccessData(psa);
        uStackY_110 = 0x180041041;
        local_c8._16_8_ = HASetAttr(param_1[9],local_a8,0,_Dst);
        puVar15 = auStackY_108;
        if (local_c8._16_8_ != 0) {
          uStackY_110 = 0x18004105d;
          HVar8 = (**(code **)(*param_1 + 0x208))(param_1,local_c8._16_8_);
          puVar16 = auStackY_108;
          goto LAB_18004143d;
        }
LAB_180041342:
        local_c8._16_8_ = 0;
        puVar16 = puVar15;
        param_2 = local_c8._0_2_;
        goto LAB_180041347;
      }
      if ((uVar2 & 0x4000) == 0) {
        if (iVar9 == -10) {
          vt = 0xd;
        }
        else {
          vt = uVar2;
          if (iVar9 != -6) {
            if (iVar9 == -3) {
              vt = 8;
            }
            else if (iVar9 == -2) {
              vt = 5;
            }
            else {
              vt = local_c8._0_2_;
              if (iVar9 == -1) {
                vt = 3;
              }
            }
          }
        }
      }
      else if (iVar9 == -10) {
        vt = 0x400d;
      }
      else if (iVar9 == -6) {
        vt = 0x400c;
      }
      else if (iVar9 == -3) {
        vt = 0x4008;
      }
      else if (iVar9 == -2) {
        vt = 0x4005;
      }
      else {
        vt = local_c8._0_2_;
        if (iVar9 == -1) {
          vt = 0x4003;
        }
      }
      if ((((byte)uVar2 & 5) == 5) && (vt == 8)) {
        uStackY_110 = 0x18004110e;
        HVar8 = VariantChangeTypeEx(&local_a0,param_4,0x7f,0,8);
        if (HVar8 != 0) goto LAB_180041112;
      }
      else {
LAB_180041112:
        uStackY_110 = 0x180041126;
        HVar8 = VariantChangeType(&local_a0,param_4,0,vt);
        if (HVar8 != 0) goto LAB_180040d9b;
      }
      if ((uVar2 & 0x4000) == 0) {
        if (iVar9 == -10) {
          uStackY_110 = 0x1800412cf;
          iVar19 = (**(code **)**(undefined8 **)CONCAT44(local_a0.n1._12_4_,local_a0.n1._8_4_))
                             (*(undefined8 **)CONCAT44(local_a0.n1._12_4_,local_a0.n1._8_4_),
                              &DAT_180063400,&local_b0);
          if (-1 < iVar19) {
            uStackY_110 = 0x1800412e8;
            (**(code **)(*(longlong *)&local_b0->n1 + 0xd0))
                      (local_b0,&(((_union_2707 *)local_c8)->n2).wReserved2);
            uStackY_110 = 0x1800412ee;
            UVar11 = _getpid();
            lVar13 = *(longlong *)&local_b0->n1;
            local_88[0] = local_b0;
            if (local_c8._4_4_ != UVar11) {
              uStackY_110 = 0x1800412fd;
              (**(code **)(lVar13 + 0x10))();
              uStackY_110 = 0x18004130e;
              HVar8 = (**(code **)(*param_1 + 0x210))(param_1,0x7e8);
              goto LAB_18004143d;
            }
            goto LAB_180041313;
          }
LAB_180040d9b:
          uStackY_110 = 0x180040dac;
          HVar8 = (**(code **)(*param_1 + 0x210))(param_1,0x7d4);
          puVar16 = auStackY_108;
          goto LAB_18004143d;
        }
        if (iVar9 == -6) {
          puVar15 = auStackY_108;
          local_b0 = &local_a0;
        }
        else if (iVar9 == -3) {
          lpWideCharStr = (LPCWSTR)CONCAT44(local_a0.n1._12_4_,local_a0.n1._8_4_);
          puVar15 = auStackY_108;
          local_b0 = pVVar18;
          if (lpWideCharStr != (LPCWSTR)0x0) {
            lVar13 = -1;
            do {
              lVar13 = lVar13 + 1;
            } while (lpWideCharStr[lVar13] != L'\0');
            goto LAB_18004118a;
          }
        }
        else if ((iVar9 == -2) || (iVar9 == -1)) {
          puVar15 = auStackY_108;
          local_b0 = (VARIANTARG *)((longlong)&local_a0.n1 + 8);
        }
      }
      else if (iVar9 == -10) {
        uStackY_110 = 0x18004121c;
        iVar19 = (*(code *)**(undefined8 **)CONCAT44(local_a0.n1._12_4_,local_a0.n1._8_4_))
                           ((undefined8 *)CONCAT44(local_a0.n1._12_4_,local_a0.n1._8_4_),
                            &DAT_180063400,local_88);
        if (iVar19 < 0) goto LAB_180040d9b;
        uStackY_110 = 0x180041235;
        (**(code **)(*(longlong *)&local_88[0]->n1 + 0xd0))
                  (local_88[0],&(((_union_2707 *)local_c8)->n2).n3);
        uStackY_110 = 0x18004123b;
        iVar19 = _getpid();
        lVar13 = *(longlong *)&local_88[0]->n1;
        if (local_c8._8_4_ != iVar19) {
          uStackY_110 = 0x18004124e;
          (**(code **)(lVar13 + 0x10))();
          uStackY_110 = 0x18004125f;
          HVar8 = (**(code **)(*param_1 + 0x210))(param_1,0x7e8);
          puVar16 = auStackY_108;
          goto LAB_18004143d;
        }
LAB_180041313:
        pVVar18 = *(VARIANTARG **)&local_88[0][3].n1;
        uStackY_110 = 0x18004131a;
        (**(code **)(lVar13 + 0x10))();
        puVar15 = auStackY_108;
        local_b0 = pVVar18;
      }
      else if (iVar9 == -6) {
LAB_180041158:
        puVar15 = auStackY_108;
        local_b0 = (VARIANTARG *)CONCAT44(local_a0.n1._12_4_,local_a0.n1._8_4_);
      }
      else if (iVar9 == -3) {
        lpWideCharStr = *(LPCWSTR *)CONCAT44(local_a0.n1._12_4_,local_a0.n1._8_4_);
        puVar15 = auStackY_108;
        local_b0 = (VARIANTARG *)0x0;
        if (lpWideCharStr != (LPCWSTR)0x0) {
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (lpWideCharStr[lVar13] != L'\0');
LAB_18004118a:
          iVar19 = (int)lVar13 + 1;
          puVar15 = auStackY_108;
          local_b0 = pVVar18;
          if (iVar19 < 0x40000000) {
            lVar13 = (longlong)(int)lVar13 * 2;
            uVar14 = lVar13 + 0x11;
            if (uVar14 <= lVar13 + 2U) {
              uVar14 = 0xffffffffffffff0;
            }
            uStackY_110 = 0x1800411c2;
            lVar13 = -(uVar14 & 0xfffffffffffffff0);
            pVVar1 = (VARIANTARG *)((longlong)local_c8 + lVar13);
            puVar15 = auStackY_108 + lVar13;
            if (pVVar1 != (VARIANTARG *)0x0) {
              *(undefined8 *)((longlong)local_d8 + lVar13 + 8) = 0;
              *(undefined8 *)((longlong)local_d8 + lVar13) = 0;
              *(int *)((longlong)aiStack_e0 + lVar13) = iVar19 * 2;
              *(undefined1 *)&pVVar1->n1 = 0;
              *(VARIANTARG **)(&stack0xffffffffffffff18 + lVar13) = pVVar1;
              *(undefined8 *)(auStackY_108 + lVar13 + -8) = 0x1800411fa;
              iVar19 = WideCharToMultiByte(0,0,lpWideCharStr,-1,
                                           *(LPSTR *)(&stack0xffffffffffffff18 + lVar13),
                                           *(int *)((longlong)aiStack_e0 + lVar13),
                                           *(LPCSTR *)((longlong)local_d8 + lVar13),
                                           *(LPBOOL *)((longlong)local_d8 + lVar13 + 8));
              puVar15 = auStackY_108 + lVar13;
              local_b0 = pVVar1;
              if (iVar19 == 0) {
                puVar15 = auStackY_108 + lVar13;
                local_b0 = (VARIANTARG *)0x0;
              }
            }
          }
        }
      }
      else if ((iVar9 == -2) || (puVar15 = auStackY_108, iVar9 == -1)) goto LAB_180041158;
      iVar19 = local_a8;
      lVar13 = param_1[9];
      *(undefined4 *)(puVar15 + 0x20) = uVar17;
      *(undefined8 *)(puVar15 + -8) = 0x180041332;
      local_c8._16_8_ = HASetAttr(lVar13,iVar19,0,local_b0);
      if (local_c8._16_8_ == 0) goto LAB_180041342;
    }
    lVar13 = *param_1;
  }
  pcVar6 = *(code **)(lVar13 + 0x208);
  *(undefined8 *)(puVar15 + -8) = 0x180040f40;
  HVar8 = (*pcVar6)(param_1);
  puVar16 = puVar15;
LAB_18004143d:
  *(undefined8 *)(puVar16 + -8) = 0x18004144c;
  return HVar8;
}

/* ---- FUNC 00041480 FUN_180041480 (1220 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

HRESULT FUN_180041480(longlong *param_1,LPCOLESTR param_2,VARIANTARG *param_3,VARIANTARG *param_4)

{
  undefined1 *puVar1;
  ushort uVar2;
  undefined4 *puVar3;
  longlong *plVar4;
  HRESULT HVar5;
  int iVar6;
  UINT UVar7;
  void *_Dst;
  void *pvVar8;
  longlong lVar9;
  ulonglong uVar10;
  undefined1 *puVar11;
  VARTYPE vt;
  SAFEARRAY *psa;
  undefined8 lpWideCharStr;
  size_t _Size;
  bool bVar12;
  undefined8 uStack_130;
  undefined1 auStack_128 [32];
  undefined8 uStack_108;
  int aiStack_100 [2];
  undefined8 local_f8 [2];
  int local_e8 [2];
  VARTYPE local_e0;
  undefined2 uStack_de;
  undefined4 uStack_dc;
  VARIANTARG local_d8;
  longlong local_c0;
  void *local_b8 [2];
  undefined8 local_a8;
  _union_1719 _Stack_a0;
  undefined8 local_98;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined8 local_78;
  CLSID local_68;
  ulonglong local_58;
  
  puVar11 = auStack_128;
  local_58 = DAT_180077818 ^ (ulonglong)local_e8;
  if (DAT_1800797f8 != 0) {
    uStack_130 = 0x1800414cd;
    HVar5 = (**(code **)(*param_1 + 0x210))(param_1,0x7f3);
    puVar11 = auStack_128;
    goto LAB_180041921;
  }
  local_c0 = 0;
  if (param_1[9] == 0) {
    uStack_130 = 0x1800414ed;
    HVar5 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
    puVar11 = auStack_128;
    goto LAB_180041921;
  }
  uVar2 = (param_3->n1).n2.vt;
  if (uVar2 == 0x400c) {
    puVar3 = *(undefined4 **)((longlong)&param_3->n1 + 8);
    local_a8 = *(undefined8 *)&param_4->n1;
    _Stack_a0 = (param_4->n1).decVal.u2;
    local_98 = *(undefined8 *)((longlong)&param_4->n1 + 0x10);
    local_88 = *puVar3;
    uStack_84 = puVar3[1];
    uStack_80 = puVar3[2];
    uStack_7c = puVar3[3];
    local_78 = *(undefined8 *)(puVar3 + 4);
    uStack_130 = 0x180041539;
    HVar5 = (**(code **)(*param_1 + 0xc0))(local_88,local_78,&local_88,&local_a8);
    puVar11 = auStack_128;
    goto LAB_180041921;
  }
  if (0xb < uVar2) {
    if ((uVar2 == 0x4002) || (uVar2 == 0x4003)) goto LAB_18004159f;
    bVar12 = uVar2 == 0x400b;
LAB_180041570:
    if (bVar12) goto LAB_18004159f;
    uStack_130 = 0x180041585;
    HVar5 = VariantChangeType(&local_d8,param_3,0,3);
    if (HVar5 == 0) goto LAB_18004159f;
    goto LAB_180041589;
  }
  if ((((uVar2 != 0xb) && (uVar2 != 0)) && (uVar2 != 2)) && (uVar2 != 3)) {
    bVar12 = uVar2 == 10;
    goto LAB_180041570;
  }
LAB_18004159f:
  uStack_130 = 0x1800415af;
  HVar5 = CLSIDFromString(param_2,&local_68);
  if (HVar5 != 0) {
LAB_1800416f2:
    uStack_130 = 0x180041703;
    HVar5 = (**(code **)(*param_1 + 0x210))(param_1,0x7d1);
    puVar11 = auStack_128;
    goto LAB_180041921;
  }
  uStack_130 = 0x1800415c1;
  VariantInit(&local_d8);
  uStack_130 = 0x1800415db;
  iVar6 = HAGetAttrType(param_1[9],1,&local_68,&local_c0);
  if (iVar6 == -999) {
    if (local_c0 == 0) {
      uStack_130 = 0x180041609;
      HVar5 = (**(code **)(*param_1 + 0x210))(param_1,0x7d1);
      puVar11 = auStack_128;
    }
    else {
      uStack_130 = 0x1800415f9;
      HVar5 = (**(code **)(*param_1 + 0x208))();
      puVar11 = auStack_128;
    }
    goto LAB_180041921;
  }
  if (iVar6 == 0) {
    uStack_130 = 0x180041623;
    HVar5 = (**(code **)(*param_1 + 0x210))(param_1,0x7e6);
    puVar11 = auStack_128;
    goto LAB_180041921;
  }
  uVar2 = (param_4->n1).n2.vt;
  if (iVar6 < 1) {
    if ((uVar2 & 0x4000) == 0) {
      if (iVar6 == -10) {
        vt = 0xd;
      }
      else if (iVar6 == -6) {
        vt = 0xc;
      }
      else if (iVar6 == -3) {
        vt = 8;
      }
      else if (iVar6 == -2) {
        vt = 5;
      }
      else {
        vt = local_e0;
        if (iVar6 == -1) {
          vt = 3;
        }
      }
    }
    else if (iVar6 == -10) {
      vt = 0x400d;
    }
    else {
      vt = 0x400c;
      if (iVar6 != -6) {
        if (iVar6 == -3) {
          vt = 0x4008;
        }
        else if (iVar6 == -2) {
          vt = 0x4005;
        }
        else {
          vt = local_e0;
          if (iVar6 == -1) {
            vt = 0x4003;
          }
        }
      }
    }
    uStack_130 = 0x1800417a3;
    HVar5 = VariantChangeType(&local_d8,param_4,0,vt);
    if (HVar5 != 0) {
      uStack_130 = 0x1800417bb;
      HVar5 = VariantChangeType(&local_d8,param_4,0,vt);
      if (HVar5 != 0) goto LAB_180041589;
    }
    if ((uVar2 & 0x4000) == 0) {
      if (iVar6 == -10) goto LAB_180041807;
      puVar11 = auStack_128;
      if ((iVar6 == -3) && (puVar11 = auStack_128, local_d8.n1.decVal.u2.Lo64 != 0)) {
        lVar9 = -1;
        do {
          lVar9 = lVar9 + 1;
          lpWideCharStr = local_d8.n1.decVal.u2;
        } while (*(LPCWSTR)((longlong)local_d8.n1.decVal.u2 + lVar9 * 2) != L'\0');
        goto LAB_18004188f;
      }
    }
    else if (iVar6 == -10) {
      local_d8.n1.decVal.u2 = (_union_1719)*(undefined8 *)local_d8.n1.decVal.u2;
LAB_180041807:
      uStack_130 = 0x180041817;
      iVar6 = (*(code *)**(undefined8 **)local_d8.n1.decVal.u2)
                        (local_d8.n1.decVal.u2.Lo64,&DAT_180063400,&local_e0);
      if (iVar6 < 0) goto LAB_180041589;
      plVar4 = (longlong *)CONCAT44(uStack_dc,CONCAT22(uStack_de,local_e0));
      uStack_130 = 0x180041830;
      (**(code **)(*plVar4 + 0xd0))(plVar4,local_e8);
      uStack_130 = 0x180041836;
      iVar6 = _getpid();
      lVar9 = *(longlong *)CONCAT44(uStack_dc,CONCAT22(uStack_de,local_e0));
      if (local_e8[0] != iVar6) {
        uStack_130 = 0x180041849;
        (**(code **)(lVar9 + 0x10))();
        uStack_130 = 0x18004185a;
        HVar5 = (**(code **)(*param_1 + 0x210))(param_1,0x7e8);
        goto LAB_180041921;
      }
      uStack_130 = 0x180041907;
      (**(code **)(lVar9 + 0x10))();
      puVar11 = auStack_128;
    }
    else {
      puVar11 = auStack_128;
      if ((iVar6 == -3) &&
         (lpWideCharStr = *(undefined8 *)local_d8.n1.decVal.u2, puVar11 = auStack_128,
         (LPCWSTR)lpWideCharStr != (LPCWSTR)0x0)) {
        lVar9 = -1;
        do {
          lVar9 = lVar9 + 1;
        } while (*(LPCWSTR)(lpWideCharStr + lVar9 * 2) != L'\0');
LAB_18004188f:
        iVar6 = (int)lVar9;
        puVar11 = auStack_128;
        if (iVar6 < 0x3fffffff) {
          uVar10 = (longlong)iVar6 * 2 + 0x11;
          if (uVar10 <= (longlong)iVar6 * 2 + 2U) {
            uVar10 = 0xffffffffffffff0;
          }
          uStack_130 = 0x1800418c1;
          lVar9 = -(uVar10 & 0xfffffffffffffff0);
          puVar1 = (undefined1 *)((longlong)local_e8 + lVar9);
          puVar11 = auStack_128 + lVar9;
          if (puVar1 != (undefined1 *)0x0) {
            *(undefined8 *)((longlong)local_f8 + lVar9 + 8) = 0;
            *(undefined8 *)((longlong)local_f8 + lVar9) = 0;
            *(int *)((longlong)aiStack_100 + lVar9) = iVar6 * 2 + 2;
            *(undefined1 **)((longlong)&uStack_108 + lVar9) = puVar1;
            *puVar1 = 0;
            *(undefined8 *)(auStack_128 + lVar9 + -8) = 0x1800418f9;
            WideCharToMultiByte(0,0,(LPCWSTR)lpWideCharStr,-1,
                                *(LPSTR *)((longlong)&uStack_108 + lVar9),
                                *(int *)((longlong)aiStack_100 + lVar9),
                                *(LPCSTR *)((longlong)local_f8 + lVar9),
                                *(LPBOOL *)((longlong)local_f8 + lVar9 + 8));
            puVar11 = auStack_128 + lVar9;
          }
        }
      }
    }
LAB_180041907:
    *(undefined4 *)(param_1[10] + 0x100) = 1;
    *(undefined8 *)(puVar11 + -8) = 0x18004191f;
    VariantClear(&local_d8);
    HVar5 = 0;
  }
  else {
    psa = *(SAFEARRAY **)((longlong)&param_4->n1 + 8);
    if ((uVar2 & 0x4000) != 0) {
      psa = *(SAFEARRAY **)psa;
    }
    uStack_130 = 0x180041650;
    UVar7 = SafeArrayGetDim(psa);
    if (UVar7 == 1) {
      uStack_130 = 0x180041668;
      SafeArrayGetLBound(psa,1,local_e8);
      uStack_130 = 0x18004167a;
      SafeArrayGetUBound(psa,1,(LONG *)&local_e0);
      uStack_130 = 0x180041683;
      UVar7 = SafeArrayGetElemsize(psa);
      _Size = (longlong)(CONCAT22(uStack_de,local_e0) - local_e8[0]) * (ulonglong)UVar7;
      uStack_130 = 0x18004169a;
      _Dst = (void *)MDmalloc(_Size);
      if (_Dst == (void *)0x0) {
        uStack_130 = 0x1800416b3;
        HVar5 = (**(code **)(*param_1 + 0x210))(param_1,0x7e1);
        puVar11 = auStack_128;
        goto LAB_180041921;
      }
      uStack_130 = 0x1800416c5;
      HVar5 = SafeArrayAccessData(psa,local_b8);
      puVar11 = auStack_128;
      if (HVar5 < 0) goto LAB_180041921;
      uStack_130 = 0x1800416dc;
      pvVar8 = memcpy(_Dst,local_b8[0],_Size);
      if (pvVar8 == (void *)0x0) {
        uStack_130 = 0x1800416e9;
        MDfree(_Dst);
        uStack_130 = 0x1800416f2;
        SafeArrayUnaccessData(psa);
        goto LAB_1800416f2;
      }
      uStack_130 = 0x180041711;
      SafeArrayUnaccessData(psa);
      puVar11 = auStack_128;
      goto LAB_180041907;
    }
LAB_180041589:
    uStack_130 = 0x18004159a;
    HVar5 = (**(code **)(*param_1 + 0x210))(param_1,0x7d4);
    puVar11 = auStack_128;
  }
LAB_180041921:
  *(undefined8 *)(puVar11 + -8) = 0x180041930;
  return HVar5;
}

/* ---- FUNC 00041950 FUN_180041950 (17 bytes) ---- */

void FUN_180041950(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018004195a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_1800797f0 + 0x228))();
  return;
}

/* ---- FUNC 00041970 FUN_180041970 (118 bytes) ---- */

void FUN_180041970(longlong *param_1,undefined4 *param_2,undefined8 *param_3)

{
  longlong lVar1;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined8 local_18;
  
  lVar1 = *param_1;
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x000180041989. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(lVar1 + 0x210))(param_1,0x7f3);
    return;
  }
  if (param_1[9] == 0) {
                    /* WARNING: Could not recover jumptable at 0x0001800419a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(lVar1 + 0x210))(param_1,0x7d9);
    return;
  }
  local_48 = *param_3;
  uStack_40 = param_3[1];
  local_38 = param_3[2];
  local_28 = *param_2;
  uStack_24 = param_2[1];
  uStack_20 = param_2[2];
  uStack_1c = param_2[3];
  local_18 = *(undefined8 *)(param_2 + 4);
  (**(code **)(lVar1 + 0xa0))(local_28,0,&local_28,&local_48);
  return;
}

/* ---- FUNC 000419F0 FUN_1800419f0 (35 bytes) ---- */

longlong *
FUN_1800419f0(longlong *param_1,ulonglong param_2,ulonglong param_3,void *param_4,size_t param_5)

{
  void *pvVar1;
  void *_Src;
  ulonglong uVar2;
  longlong *plVar3;
  size_t _Size;
  ulonglong uVar4;
  ulonglong uVar5;
  
  uVar2 = param_1[2];
  if (uVar2 < param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_18003f2d0();
  }
  uVar4 = uVar2 - param_2;
  if (uVar4 < param_3) {
    param_3 = uVar4;
  }
  if (param_3 == param_5) {
    plVar3 = param_1;
    if (0xf < (ulonglong)param_1[3]) {
      plVar3 = (longlong *)*param_1;
    }
    memmove((void *)((longlong)plVar3 + param_2),param_4,param_5);
  }
  else if (param_5 < param_3) {
    plVar3 = param_1;
    if (0xf < (ulonglong)param_1[3]) {
      plVar3 = (longlong *)*param_1;
    }
    pvVar1 = (void *)((longlong)plVar3 + param_2);
    memmove(pvVar1,param_4,param_5);
    memmove((void *)((longlong)pvVar1 + param_5),(void *)((longlong)pvVar1 + param_3),
            (uVar4 - param_3) + 1);
    param_1[2] = (uVar2 - param_3) + param_5;
  }
  else {
    uVar5 = param_5 - param_3;
    if (param_1[3] - uVar2 < uVar5) {
      param_1 = FUN_180037a80(param_1,uVar5,0,param_2,param_3,param_4,param_5);
    }
    else {
      param_1[2] = uVar2 + uVar5;
      plVar3 = param_1;
      if (0xf < (ulonglong)param_1[3]) {
        plVar3 = (longlong *)*param_1;
      }
      pvVar1 = (void *)((longlong)plVar3 + param_2);
      _Src = (void *)((longlong)pvVar1 + param_3);
      _Size = param_5;
      if ((pvVar1 < (void *)((longlong)param_4 + param_5)) &&
         (param_4 <= (void *)((longlong)plVar3 + uVar2))) {
        if (param_4 < _Src) {
          _Size = (longlong)_Src - (longlong)param_4;
        }
        else {
          _Size = 0;
        }
      }
      memmove((void *)((longlong)_Src + uVar5),_Src,(uVar4 - param_3) + 1);
      memmove(pvVar1,param_4,_Size);
      memcpy((void *)(_Size + (longlong)pvVar1),(void *)(_Size + uVar5 + (longlong)param_4),
             param_5 - _Size);
    }
  }
  return param_1;
}

/* ---- FUNC 00041A13 FUN_180041a13 (73 bytes) ---- */

void FUN_180041a13(longlong *param_1,size_t param_2,ulonglong param_3,longlong param_4)

{
  void *pvVar1;
  void *_Src;
  longlong in_RAX;
  longlong lVar2;
  size_t _Size;
  ulonglong unaff_RBP;
  undefined8 unaff_RSI;
  longlong unaff_RDI;
  undefined8 unaff_R12;
  ulonglong uVar3;
  ulonglong uVar4;
  void *unaff_R14;
  longlong unaff_R15;
  size_t in_stack_00000090;
  
  *(undefined8 *)(in_RAX + 0x18) = unaff_RSI;
  *(undefined8 *)(in_RAX + 0x20) = unaff_R12;
  uVar3 = unaff_R15 - param_2;
  if (uVar3 < param_3) {
    unaff_RBP = uVar3;
  }
  if (unaff_RBP == in_stack_00000090) {
    if (0xf < (ulonglong)param_1[3]) {
      param_1 = (longlong *)*param_1;
    }
    memmove((void *)((longlong)param_1 + param_2),unaff_R14,in_stack_00000090);
  }
  else if (in_stack_00000090 < unaff_RBP) {
    lVar2 = unaff_RDI;
    if (0xf < (ulonglong)param_1[3]) {
      lVar2 = *param_1;
    }
    pvVar1 = (void *)(lVar2 + param_2);
    memmove(pvVar1,unaff_R14,in_stack_00000090);
    memmove((void *)((longlong)pvVar1 + in_stack_00000090),(void *)((longlong)pvVar1 + unaff_RBP),
            (uVar3 - unaff_RBP) + 1);
    *(ulonglong *)(unaff_RDI + 0x10) = (unaff_R15 - unaff_RBP) + in_stack_00000090;
  }
  else {
    uVar4 = in_stack_00000090 - unaff_RBP;
    if ((ulonglong)(param_1[3] - unaff_R15) < uVar4) {
      FUN_180037a80(param_1,uVar4,0,param_2,unaff_RBP,unaff_R14,in_stack_00000090);
    }
    else {
      param_1[2] = unaff_R15 + uVar4;
      if (0xf < (ulonglong)param_1[3]) {
        param_1 = (longlong *)*param_1;
      }
      pvVar1 = (void *)((longlong)param_1 + param_2);
      _Src = (void *)((longlong)pvVar1 + unaff_RBP);
      _Size = in_stack_00000090;
      if ((pvVar1 < (void *)(param_4 + in_stack_00000090)) &&
         (unaff_R14 <= (void *)((longlong)param_1 + unaff_R15))) {
        if (unaff_R14 < _Src) {
          _Size = (longlong)_Src - (longlong)unaff_R14;
        }
        else {
          _Size = 0;
        }
      }
      memmove((void *)((longlong)_Src + uVar4),_Src,(uVar3 - unaff_RBP) + 1);
      memmove(pvVar1,unaff_R14,_Size);
      memcpy((void *)(_Size + (longlong)pvVar1),(void *)(_Size + uVar4 + (longlong)unaff_R14),
             in_stack_00000090 - _Size);
    }
  }
  return;
}

/* ---- FUNC 00041A5C FUN_180041a5c (81 bytes) ---- */

void FUN_180041a5c(longlong *param_1,size_t param_2,undefined8 param_3,longlong param_4)

{
  void *pvVar1;
  void *_Src;
  longlong lVar2;
  size_t _Size;
  ulonglong unaff_RBP;
  ulonglong unaff_RSI;
  longlong unaff_RDI;
  longlong unaff_R12;
  ulonglong uVar3;
  void *unaff_R14;
  longlong unaff_R15;
  
  if (unaff_RSI < unaff_RBP) {
    lVar2 = unaff_RDI;
    if (0xf < (ulonglong)param_1[3]) {
      lVar2 = *param_1;
    }
    pvVar1 = (void *)(lVar2 + param_2);
    memmove(pvVar1,unaff_R14,unaff_RSI);
    memmove((void *)((longlong)pvVar1 + unaff_RSI),(void *)((longlong)pvVar1 + unaff_RBP),
            unaff_R12 + 1);
    *(ulonglong *)(unaff_RDI + 0x10) = (unaff_R15 - unaff_RBP) + unaff_RSI;
  }
  else {
    uVar3 = unaff_RSI - unaff_RBP;
    if ((ulonglong)(param_1[3] - unaff_R15) < uVar3) {
      FUN_180037a80(param_1,uVar3,0,param_2,unaff_RBP,unaff_R14,unaff_RSI);
    }
    else {
      param_1[2] = unaff_R15 + uVar3;
      if (0xf < (ulonglong)param_1[3]) {
        param_1 = (longlong *)*param_1;
      }
      pvVar1 = (void *)((longlong)param_1 + param_2);
      _Src = (void *)((longlong)pvVar1 + unaff_RBP);
      _Size = unaff_RSI;
      if ((pvVar1 < (void *)(param_4 + unaff_RSI)) &&
         (unaff_R14 <= (void *)((longlong)param_1 + unaff_R15))) {
        if (unaff_R14 < _Src) {
          _Size = (longlong)_Src - (longlong)unaff_R14;
        }
        else {
          _Size = 0;
        }
      }
      memmove((void *)((longlong)_Src + uVar3),_Src,unaff_R12 + 1);
      memmove(pvVar1,unaff_R14,_Size);
      memcpy((void *)(_Size + (longlong)pvVar1),(void *)(_Size + uVar3 + (longlong)unaff_R14),
             unaff_RSI - _Size);
    }
  }
  return;
}

/* ---- FUNC 00041AAD FUN_180041aad (188 bytes) ---- */

void FUN_180041aad(undefined8 *param_1,size_t param_2,ulonglong param_3,longlong param_4)

{
  void *_Dst;
  void *_Src;
  size_t _Size;
  longlong unaff_RBP;
  size_t unaff_RSI;
  longlong unaff_R12;
  ulonglong uVar1;
  void *unaff_R14;
  longlong unaff_R15;
  
  uVar1 = unaff_RSI - unaff_RBP;
  if (param_3 - unaff_R15 < uVar1) {
    FUN_180037a80(param_1,uVar1,0,param_2,unaff_RBP,unaff_R14,unaff_RSI);
  }
  else {
    param_1[2] = unaff_R15 + uVar1;
    if (0xf < param_3) {
      param_1 = (undefined8 *)*param_1;
    }
    _Dst = (void *)((longlong)param_1 + param_2);
    _Src = (void *)((longlong)_Dst + unaff_RBP);
    _Size = unaff_RSI;
    if ((_Dst < (void *)(param_4 + unaff_RSI)) &&
       (unaff_R14 <= (void *)((longlong)param_1 + unaff_R15))) {
      if (unaff_R14 < _Src) {
        _Size = (longlong)_Src - (longlong)unaff_R14;
      }
      else {
        _Size = 0;
      }
    }
    memmove((void *)((longlong)_Src + uVar1),_Src,unaff_R12 + 1);
    memmove(_Dst,unaff_R14,_Size);
    memcpy((void *)(_Size + (longlong)_Dst),(void *)(_Size + uVar1 + (longlong)unaff_R14),
           unaff_RSI - _Size);
  }
  return;
}

/* ---- FUNC 00041B69 FUN_180041b69 (5 bytes) ---- */

void FUN_180041b69(void)

{
  return;
}

/* ---- FUNC 00041B6E FUN_180041b6e (27 bytes) ---- */

void FUN_180041b6e(void)

{
  return;
}

/* ---- FUNC 00041B89 thunk_FUN_18003f2d0 (5 bytes) ---- */

void thunk_FUN_18003f2d0(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_18003f2d0();
}

/* ---- FUNC 00041B90 FUN_180041b90 (85 bytes) ---- */

void FUN_180041b90(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  char cVar1;
  longlong *plVar2;
  
  cVar1 = *(char *)((longlong)param_3 + 0x19);
  while (cVar1 == '\0') {
    FUN_180041b90(param_1,param_2,(longlong *)param_3[2]);
    plVar2 = (longlong *)*param_3;
    FUN_180025ad0(param_3);
    param_3 = plVar2;
    cVar1 = *(char *)((longlong)plVar2 + 0x19);
  }
  return;
}

/* ---- FUNC 00041BF0 FUN_180041bf0 (58 bytes) ---- */

CEnumArray * FUN_180041bf0(CEnumArray *param_1)

{
  CEnumArray::CEnumArray(param_1,0x20,(void *)0x0,0,1);
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined ***)param_1 = CEnumFormatEtc::vftable;
  return param_1;
}

/* ---- FUNC 00041C30 FUN_180041c30 (358 bytes) ---- */

undefined8 *
FUN_180041c30(undefined8 *param_1,longlong *param_2,undefined8 param_3,undefined4 param_4,
             int param_5)

{
  UINT UVar1;
  longlong *plVar2;
  
  param_1[2] = param_1;
  *param_1 = CHNodeDataObject::vftable;
  param_1[4] = param_1;
  param_1[1] = CHNodeDataObject::CHIOleObject::vftable;
  param_1[3] = CHNodeDataObject::CHIDataObject::vftable;
  param_1[9] = CHNodeDataObject::CHIExternalConnection::vftable;
  UVar1 = RegisterClipboardFormatA("Link Source");
  *(UINT *)(param_1 + 5) = UVar1;
  UVar1 = RegisterClipboardFormatA("Link Source Descriptor");
  *(UINT *)((longlong)param_1 + 0x2c) = UVar1;
  UVar1 = RegisterClipboardFormatA("Grid Text");
  *(UINT *)(param_1 + 6) = UVar1;
  UVar1 = RegisterClipboardFormatA("Print Text");
  *(UINT *)((longlong)param_1 + 0x34) = UVar1;
  UVar1 = RegisterClipboardFormatA("Moniker");
  *(UINT *)(param_1 + 7) = UVar1;
  UVar1 = RegisterClipboardFormatA("MonikerText");
  *(UINT *)((longlong)param_1 + 0x3c) = UVar1;
  UVar1 = RegisterClipboardFormatA("ASI Format");
  *(UINT *)(param_1 + 8) = UVar1;
  UVar1 = RegisterClipboardFormatA("ASI File Format");
  param_1[10] = param_1;
  *(UINT *)((longlong)param_1 + 0x44) = UVar1;
  *(int *)((longlong)param_1 + 0x84) = param_5;
  param_1[0xb] = 0;
  *(undefined4 *)(param_1 + 0xc) = 4000;
  *(undefined8 *)((longlong)param_1 + 100) = 400;
  param_1[0xe] = param_3;
  param_1[0xf] = param_2;
  *(undefined4 *)(param_1 + 0x10) = param_4;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  *(undefined4 *)(param_1 + 0x11) = 0;
  if (param_5 == 0) {
    plVar2 = (longlong *)param_2[0x1d];
  }
  else {
    plVar2 = (longlong *)FUN_18002a120(param_2);
  }
  FUN_180042540((longlong)param_1,plVar2);
  FUN_180043b30((longlong)param_1);
  return param_1;
}

/* ---- FUNC 00041DA0 FUN_180041da0 (362 bytes) ---- */

undefined8 *
FUN_180041da0(undefined8 *param_1,longlong *param_2,undefined8 param_3,undefined4 param_4,
             int param_5,undefined4 param_6)

{
  UINT UVar1;
  longlong *plVar2;
  
  param_1[2] = param_1;
  *param_1 = CHNodeDataObject::vftable;
  param_1[4] = param_1;
  param_1[1] = CHNodeDataObject::CHIOleObject::vftable;
  param_1[3] = CHNodeDataObject::CHIDataObject::vftable;
  param_1[9] = CHNodeDataObject::CHIExternalConnection::vftable;
  UVar1 = RegisterClipboardFormatA("Link Source");
  *(UINT *)(param_1 + 5) = UVar1;
  UVar1 = RegisterClipboardFormatA("Link Source Descriptor");
  *(UINT *)((longlong)param_1 + 0x2c) = UVar1;
  UVar1 = RegisterClipboardFormatA("Grid Text");
  *(UINT *)(param_1 + 6) = UVar1;
  UVar1 = RegisterClipboardFormatA("Print Text");
  *(UINT *)((longlong)param_1 + 0x34) = UVar1;
  UVar1 = RegisterClipboardFormatA("Moniker");
  *(UINT *)(param_1 + 7) = UVar1;
  UVar1 = RegisterClipboardFormatA("MonikerText");
  *(UINT *)((longlong)param_1 + 0x3c) = UVar1;
  UVar1 = RegisterClipboardFormatA("ASI Format");
  *(UINT *)(param_1 + 8) = UVar1;
  UVar1 = RegisterClipboardFormatA("ASI File Format");
  *(UINT *)((longlong)param_1 + 0x44) = UVar1;
  param_1[0xb] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  *(undefined4 *)(param_1 + 0x11) = param_6;
  param_1[10] = param_1;
  *(int *)((longlong)param_1 + 0x84) = param_5;
  *(undefined4 *)(param_1 + 0xc) = 4000;
  *(undefined8 *)((longlong)param_1 + 100) = 400;
  param_1[0xe] = param_3;
  param_1[0xf] = param_2;
  *(undefined4 *)(param_1 + 0x10) = param_4;
  if (param_5 == 0) {
    plVar2 = (longlong *)param_2[0x1d];
  }
  else {
    plVar2 = (longlong *)FUN_18002a120(param_2);
  }
  FUN_180042540((longlong)param_1,plVar2);
  FUN_180043b30((longlong)param_1);
  return param_1;
}

/* ---- FUNC 00041F10 FUN_180041f10 (38 bytes) ---- */

undefined8 *
FUN_180041f10(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  param_1[1] = param_3;
  *param_1 = CMultiDataObjects::vftable;
  *(undefined4 *)(param_1 + 3) = 0;
  param_1[4] = 0;
  *(undefined4 *)((longlong)param_1 + 0x2c) = 0;
  param_1[2] = param_2;
  *(undefined4 *)(param_1 + 5) = param_4;
  return param_1;
}

/* ---- FUNC 00041F60 FUN_180041f60 (119 bytes) ---- */

void FUN_180041f60(longlong *param_1)

{
  IUnknown *This;
  HRESULT HVar1;
  longlong lVar2;
  
  if (((int)param_1[2] == 0) && (param_1[1] != 0)) {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (*(short *)(param_1[1] + lVar2 * 2) != 0);
  }
  This = *(IUnknown **)(*param_1 + 8);
  HVar1 = (*This->lpVtbl[3].QueryInterface)(This,(IID *)&DAT_1800648c0,(void **)0x0);
  if (HVar1 < 0) {
    _com_issue_errorex(HVar1,This,(_GUID *)&DAT_180065d78);
  }
  return;
}

/* ---- FUNC 00041FE0 FUN_180041fe0 (26 bytes) ---- */

void FUN_180041fe0(CEnumArray *param_1)

{
  longlong lVar1;
  uint uVar2;
  
  *(undefined ***)param_1 = CEnumFormatEtc::vftable;
  if (*(longlong *)(param_1 + 0x48) == 0) {
    uVar2 = 0;
    lVar1 = *(longlong *)(param_1 + 0x50);
    if (*(int *)(param_1 + 0x5c) != 0) {
      do {
        CoTaskMemFree(*(LPVOID *)((ulonglong)uVar2 * 0x20 + 8 + lVar1));
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(uint *)(param_1 + 0x5c));
    }
  }
  CEnumArray::~CEnumArray(param_1);
  return;
}

/* ---- FUNC 00041FFA FUN_180041ffa (56 bytes) ---- */

void FUN_180041ffa(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  CEnumArray *unaff_RDI;
  
  uVar2 = 0;
  lVar1 = *(longlong *)(param_1 + 0x50);
  if (*(int *)(param_1 + 0x5c) != 0) {
    do {
      CoTaskMemFree(*(LPVOID *)((ulonglong)uVar2 * 0x20 + 8 + lVar1));
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(unaff_RDI + 0x5c));
  }
  CEnumArray::~CEnumArray(unaff_RDI);
  return;
}

/* ---- FUNC 00042032 FUN_180042032 (13 bytes) ---- */

void FUN_180042032(void)

{
  CEnumArray *unaff_RDI;
  
  CEnumArray::~CEnumArray(unaff_RDI);
  return;
}

/* ---- FUNC 00042040 FUN_180042040 (117 bytes) ---- */

void FUN_180042040(undefined8 *param_1)

{
  *param_1 = CHNodeDataObject::vftable;
  if ((void *)param_1[0xb] != (void *)0x0) {
    FUN_180025ad0((void *)param_1[0xb]);
  }
  if ((longlong *)param_1[0x12] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x12] + 0x10))();
  }
  if ((longlong *)param_1[0x13] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x13] + 0x10))();
  }
  if ((longlong *)param_1[0x14] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x14] + 0x10))();
  }
  if ((longlong *)param_1[0x15] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x15] + 0x10))();
  }
  return;
}

/* ---- FUNC 000420C0 FUN_1800420c0 (26 bytes) ---- */

void FUN_1800420c0(undefined8 *param_1)

{
  undefined8 *puVar1;
  int iVar2;
  longlong lVar3;
  
  *param_1 = CMultiDataObjects::vftable;
  if (param_1[4] != 0) {
    iVar2 = 0;
    if (0 < *(int *)(param_1 + 3)) {
      lVar3 = 0;
      do {
        puVar1 = *(undefined8 **)(lVar3 + param_1[4]);
        if (puVar1 != (undefined8 *)0x0) {
          FUN_180042040(puVar1);
          FUN_180025ad0(puVar1);
        }
        iVar2 = iVar2 + 1;
        lVar3 = lVar3 + 8;
      } while (iVar2 < *(int *)(param_1 + 3));
    }
    free((void *)param_1[4]);
  }
  return;
}

/* ---- FUNC 000420DA FUN_1800420da (12 bytes) ---- */

void FUN_1800420da(longlong param_1)

{
  undefined8 *puVar1;
  int iVar2;
  longlong lVar3;
  longlong unaff_RDI;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x18)) {
    lVar3 = 0;
    do {
      puVar1 = *(undefined8 **)(lVar3 + *(longlong *)(unaff_RDI + 0x20));
      if (puVar1 != (undefined8 *)0x0) {
        FUN_180042040(puVar1);
        FUN_180025ad0(puVar1);
      }
      iVar2 = iVar2 + 1;
      lVar3 = lVar3 + 8;
    } while (iVar2 < *(int *)(unaff_RDI + 0x18));
  }
  free(*(void **)(unaff_RDI + 0x20));
  return;
}

/* ---- FUNC 000420E6 FUN_1800420e6 (67 bytes) ---- */

void FUN_1800420e6(void)

{
  undefined8 *puVar1;
  uint unaff_EBX;
  ulonglong uVar2;
  longlong unaff_RDI;
  
  uVar2 = (ulonglong)unaff_EBX;
  do {
    puVar1 = *(undefined8 **)(uVar2 + *(longlong *)(unaff_RDI + 0x20));
    if (puVar1 != (undefined8 *)0x0) {
      FUN_180042040(puVar1);
      FUN_180025ad0(puVar1);
    }
    unaff_EBX = unaff_EBX + 1;
    uVar2 = uVar2 + 8;
  } while ((int)unaff_EBX < *(int *)(unaff_RDI + 0x18));
  free(*(void **)(unaff_RDI + 0x20));
  return;
}

/* ---- FUNC 00042129 FUN_180042129 (15 bytes) ---- */

void FUN_180042129(void)

{
  longlong unaff_RDI;
  
  free(*(void **)(unaff_RDI + 0x20));
  return;
}

/* ---- FUNC 00042138 FUN_180042138 (6 bytes) ---- */

void FUN_180042138(void)

{
  return;
}

/* ---- FUNC 00042140 FUN_180042140 (78 bytes) ---- */

CEnumArray * FUN_180042140(CEnumArray *param_1,uint param_2)

{
  FUN_180041fe0(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    _guard_check_icall();
  }
  return param_1;
}

/* ---- FUNC 00042190 FUN_180042190 (42 bytes) ---- */

int FUN_180042190(longlong param_1,ulonglong param_2)

{
  longlong *plVar1;
  int iVar2;
  
  if ((param_2 & 1) == 0) {
    return 0;
  }
  plVar1 = *(longlong **)(*(longlong *)(param_1 + 8) + 0x78);
  if (*(int *)(*(longlong *)(param_1 + 8) + 0x84) == 0) {
    iVar2 = FUN_18003b0a0(plVar1,1);
    return iVar2;
  }
  iVar2 = FUN_180018e30((IUnknown *)plVar1[1],1,1);
  return iVar2;
}

/* ---- FUNC 000421C0 FUN_1800421c0 (106 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1800421c0(longlong param_1,undefined2 *param_2)

{
  undefined1 auVar1 [16];
  __uint64 _Var2;
  void *_Dst;
  undefined2 *puVar3;
  undefined1 auStack_428 [32];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_180077818 ^ (ulonglong)auStack_428;
  if (*(uint *)(param_1 + 0x70) < *(uint *)(param_1 + 0x5c)) {
    FUN_180002a20(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnode_dataobj.cpp",0x4dc);
    LogMessage(local_408,2,1);
  }
  if (*(int *)(param_1 + 0x5c) == *(int *)(param_1 + 0x70)) {
    auVar1 = ZEXT816(0x20) * ZEXT416(*(int *)(param_1 + 0x5c) + 10);
    _Var2 = auVar1._0_8_;
    if (auVar1._8_8_ != 0) {
      _Var2 = 0xffffffffffffffff;
    }
    _Dst = operator_new__(_Var2);
    *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + 10;
    memcpy(_Dst,*(void **)(param_1 + 0x50),(ulonglong)*(uint *)(param_1 + 0x5c) << 5);
    FUN_180025ad0(*(void **)(param_1 + 0x50));
    *(void **)(param_1 + 0x50) = _Dst;
  }
  if (*(uint *)(param_1 + 0x70) <= *(uint *)(param_1 + 0x5c)) {
    FUN_180002a20(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnode_dataobj.cpp",0x4e9);
    LogMessage(local_408,2,1);
  }
  puVar3 = (undefined2 *)
           ((ulonglong)*(uint *)(param_1 + 0x5c) * 0x20 + *(longlong *)(param_1 + 0x50));
  *puVar3 = *param_2;
  *(undefined8 *)(puVar3 + 4) = *(undefined8 *)(param_2 + 4);
  *(undefined4 *)(puVar3 + 8) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(puVar3 + 10) = *(undefined4 *)(param_2 + 10);
  *(undefined4 *)(puVar3 + 0xc) = *(undefined4 *)(param_2 + 0xc);
  *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + 1;
  return;
}

/* ---- FUNC 0004222A FUN_18004222a (88 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18004222a(ulonglong param_1)

{
  undefined1 auVar1 [16];
  __uint64 _Var2;
  void *_Dst;
  undefined2 *puVar3;
  undefined2 *unaff_RSI;
  longlong unaff_RDI;
  undefined1 auStackX_20 [8];
  
  auVar1._8_8_ = 0;
  auVar1._0_8_ = param_1;
  _Var2 = SUB168(ZEXT816(0x20) * auVar1,0);
  if (SUB168(ZEXT816(0x20) * auVar1,8) != 0) {
    _Var2 = 0xffffffffffffffff;
  }
  _Dst = operator_new__(_Var2);
  *(int *)(unaff_RDI + 0x70) = *(int *)(unaff_RDI + 0x70) + 10;
  memcpy(_Dst,*(void **)(unaff_RDI + 0x50),(ulonglong)*(uint *)(unaff_RDI + 0x5c) << 5);
  FUN_180025ad0(*(void **)(unaff_RDI + 0x50));
  *(void **)(unaff_RDI + 0x50) = _Dst;
  if (*(uint *)(unaff_RDI + 0x70) <= *(uint *)(unaff_RDI + 0x5c)) {
    FUN_180002a20(auStackX_20,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnode_dataobj.cpp",0x4e9);
    LogMessage(auStackX_20,2,1);
  }
  puVar3 = (undefined2 *)
           ((ulonglong)*(uint *)(unaff_RDI + 0x5c) * 0x20 + *(longlong *)(unaff_RDI + 0x50));
  *puVar3 = *unaff_RSI;
  *(undefined8 *)(puVar3 + 4) = *(undefined8 *)(unaff_RSI + 4);
  *(undefined4 *)(puVar3 + 8) = *(undefined4 *)(unaff_RSI + 8);
  *(undefined4 *)(puVar3 + 10) = *(undefined4 *)(unaff_RSI + 10);
  *(undefined4 *)(puVar3 + 0xc) = *(undefined4 *)(unaff_RSI + 0xc);
  *(int *)(unaff_RDI + 0x5c) = *(int *)(unaff_RDI + 0x5c) + 1;
  return;
}

/* ---- FUNC 00042282 FUN_180042282 (137 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180042282(void)

{
  undefined2 *puVar1;
  undefined2 *unaff_RSI;
  longlong unaff_RDI;
  undefined1 auStackX_20 [8];
  
  if (*(uint *)(unaff_RDI + 0x70) <= *(uint *)(unaff_RDI + 0x5c)) {
    FUN_180002a20(auStackX_20,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnode_dataobj.cpp",0x4e9);
    LogMessage(auStackX_20,2,1);
  }
  puVar1 = (undefined2 *)
           ((ulonglong)*(uint *)(unaff_RDI + 0x5c) * 0x20 + *(longlong *)(unaff_RDI + 0x50));
  *puVar1 = *unaff_RSI;
  *(undefined8 *)(puVar1 + 4) = *(undefined8 *)(unaff_RSI + 4);
  *(undefined4 *)(puVar1 + 8) = *(undefined4 *)(unaff_RSI + 8);
  *(undefined4 *)(puVar1 + 10) = *(undefined4 *)(unaff_RSI + 10);
  *(undefined4 *)(puVar1 + 0xc) = *(undefined4 *)(unaff_RSI + 0xc);
  *(int *)(unaff_RDI + 0x5c) = *(int *)(unaff_RDI + 0x5c) + 1;
  return;
}

/* ---- FUNC 00042310 FUN_180042310 (14 bytes) ---- */

void FUN_180042310(longlong param_1)

{
  *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 1;
                    /* WARNING: Could not recover jumptable at 0x00018004231a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(longlong **)(param_1 + 0x70) + 8))();
  return;
}

/* ---- FUNC 00042320 FUN_180042320 (238 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void * FUN_180042320(undefined8 param_1,void *param_2,int *param_3,int param_4,int param_5)

{
  void *pvVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  int iVar4;
  undefined1 auStack_448 [32];
  undefined1 local_428 [1008];
  ulonglong local_38;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStack_448;
  if (param_4 < 0) {
    FUN_180002a20(local_428,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnode_dataobj.cpp",0xb94);
    LogMessage(local_428,2,1);
  }
  iVar4 = param_4 * 2;
  if (param_5 == 0) {
    iVar4 = param_4;
  }
  if (param_2 == (void *)0x0) {
    pvVar1 = malloc((longlong)iVar4);
  }
  else {
    pvVar1 = realloc(param_2,(longlong)(*param_3 + iVar4));
  }
  uVar2 = 0;
  uVar3 = uVar2;
  if (0 < iVar4) {
    do {
      if ((param_5 == 0) || ((uVar3 & 1) != 0)) {
        *(undefined1 *)((longlong)*param_3 + uVar2 + (longlong)pvVar1) = 9;
      }
      else {
        *(undefined1 *)((longlong)*param_3 + uVar2 + (longlong)pvVar1) = 0x20;
      }
      uVar2 = uVar2 + 1;
      uVar3 = (ulonglong)((int)uVar3 + 1);
    } while ((longlong)uVar2 < (longlong)iVar4);
  }
  *param_3 = *param_3 + iVar4;
  return pvVar1;
}

/* ---- FUNC 00042410 FUN_180042410 (174 bytes) ---- */

void * FUN_180042410(undefined8 param_1,void *param_2,int *param_3,char *param_4)

{
  char cVar1;
  void *pvVar2;
  int iVar3;
  longlong lVar4;
  char *pcVar6;
  char *pcVar7;
  longlong lVar8;
  longlong lVar5;
  
  if ((param_4 == (char *)0x0) || (*param_4 == '\0')) {
    param_4 = " ";
  }
  lVar8 = -1;
  lVar4 = -1;
  do {
    lVar5 = lVar4;
    lVar4 = lVar5 + 1;
  } while (param_4[lVar4] != '\0');
  if (param_2 == (void *)0x0) {
    pvVar2 = malloc(lVar5 + 2);
  }
  else {
    pvVar2 = realloc(param_2,(longlong)*param_3 + 1 + lVar4);
  }
  pcVar6 = (char *)((longlong)*param_3 + (longlong)pvVar2);
  pcVar7 = param_4;
  do {
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    *pcVar6 = cVar1;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  do {
    lVar8 = lVar8 + 1;
  } while (param_4[lVar8] != '\0');
  iVar3 = *param_3 + (int)lVar8;
  *param_3 = iVar3 + 1;
  *(undefined1 *)((longlong)iVar3 + (longlong)pvVar2) = 9;
  return pvVar2;
}

/* ---- FUNC 000424C0 FUN_1800424c0 (112 bytes) ---- */

void FUN_1800424c0(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong *plVar1;
  HRESULT HVar2;
  LPOLEADVISEHOLDER *ppOAHolder;
  
  if (*(int *)(*(longlong *)(param_1 + 8) + 0x84) != 0) {
    FUN_18002acb0(*(longlong **)(*(longlong *)(param_1 + 8) + 0x78));
  }
  ppOAHolder = (LPOLEADVISEHOLDER *)(*(longlong *)(param_1 + 8) + 0xa0);
  if ((*ppOAHolder == (LPOLEADVISEHOLDER)0x0) &&
     (HVar2 = CreateOleAdviseHolder(ppOAHolder), HVar2 < 0)) {
    return;
  }
  plVar1 = *(longlong **)(*(longlong *)(param_1 + 8) + 0xa0);
  (**(code **)(*plVar1 + 0x18))(plVar1,param_2,param_3);
  return;
}

/* ---- FUNC 00042530 FUN_180042530 (8 bytes) ---- */

void FUN_180042530(longlong param_1)

{
  *(undefined4 *)(param_1 + 0x2c) = 1;
  return;
}

/* ---- FUNC 00042540 FUN_180042540 (227 bytes) ---- */

undefined8 FUN_180042540(longlong param_1,longlong *param_2)

{
  HRESULT HVar1;
  LPCOLESTR lpszItem;
  OLECHAR local_res10 [4];
  IMoniker *local_res18;
  LPCOLESTR local_res20;
  
  local_res10[0] = L'!';
  local_res10[1] = L'\0';
  if (param_2 == (longlong *)0x0) {
    return 0x80004005;
  }
  if (*(longlong *)(param_1 + 0xa8) == 0) {
    lpszItem = CoTaskMemAlloc(0x40);
    *lpszItem = L'&';
    local_res20 = lpszItem;
    _itow(*(int *)(param_1 + 0x80),lpszItem + 1,10);
    HVar1 = CreateItemMoniker(local_res10,lpszItem,&local_res18);
    if (-1 < HVar1) {
      (**(code **)(*param_2 + 0x58))(param_2,local_res18,0,param_1 + 0xa8);
      (*local_res18->lpVtbl->Release)(local_res18);
      CoTaskMemFree(lpszItem);
      return 0;
    }
    CoTaskMemFree(lpszItem);
  }
  return 1;
}

/* ---- FUNC 00042630 FUN_180042630 (356 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FUN_180042630(longlong param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_488 [32];
  longlong *local_468;
  longlong *local_460;
  _union_2707 local_458;
  _union_2707 local_440;
  undefined4 local_428;
  ULONG UStack_424;
  undefined4 uStack_420;
  undefined4 uStack_41c;
  undefined8 local_418;
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_180077818 ^ (ulonglong)auStack_488;
  local_460 = (longlong *)0x0;
  uVar2 = 5000;
  local_468 = (longlong *)0x0;
  iVar1 = (**(code **)(*DAT_1800797f0 + 0x90))(DAT_1800797f0,&local_460);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_460 + 0x110))(local_460,L"Settings\\linklimit",&local_468);
    uVar2 = 5000;
    if (-1 < iVar1) {
      VariantInit((VARIANTARG *)&local_440.n2);
      VariantInit((VARIANTARG *)&local_458.n2);
      local_428 = local_440._0_4_;
      UStack_424 = local_440.decVal.Hi32;
      uStack_420 = local_440._8_4_;
      uStack_41c = local_440._12_4_;
      local_418 = local_440._16_8_;
      iVar1 = (**(code **)(*local_468 + 0x68))(local_468,&local_428,&local_458);
      uVar2 = 5000;
      if (((-1 < iVar1) && (local_458.n2.vt == 3)) &&
         (uVar2 = local_458._8_4_, local_458._8_4_ == 500)) {
        uVar2 = 5000;
      }
      VariantClear((VARIANTARG *)&local_458.n2);
      (**(code **)(*local_468 + 0x10))();
    }
    (**(code **)(*local_460 + 0x10))();
  }
  if (*(int *)(param_1 + 0x84) == 0) {
    FUN_180002a20(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnode_dataobj.cpp",0x185);
    LogMessage(local_408,2,1);
  }
  return *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60) < (longlong)(int)uVar2;
}

/* ---- FUNC 000427A0 FUN_1800427a0 (66 bytes) ---- */

undefined8 FUN_1800427a0(longlong *param_1)

{
  (**(code **)(*param_1 + 8))();
  if (*(longlong **)(param_1[1] + 0xa0) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1[1] + 0xa0) + 0x40))();
  }
  CoDisconnectObject((LPUNKNOWN)param_1[1],0);
  (**(code **)(*param_1 + 0x10))(param_1);
  return 0;
}

/* ---- FUNC 000427F0 FUN_1800427f0 (20 bytes) ---- */

void FUN_1800427f0(longlong param_1)

{
  if (*(longlong **)(param_1 + 0xa0) != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001800427ff. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(longlong **)(param_1 + 0xa0) + 0x40))();
    return;
  }
  return;
}

/* ---- FUNC 00042810 FUN_180042810 (16 bytes) ---- */

void FUN_180042810(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  
  if ((*(longlong *)(param_1 + 0x20) != 0) && (iVar1 = 0, 0 < *(int *)(param_1 + 0x18))) {
    lVar2 = 0;
    do {
      FUN_1800427f0(*(longlong *)(*(longlong *)(param_1 + 0x20) + lVar2));
      iVar1 = iVar1 + 1;
      lVar2 = lVar2 + 8;
    } while (iVar1 < *(int *)(param_1 + 0x18));
  }
  return;
}

/* ---- FUNC 00042820 FUN_180042820 (12 bytes) ---- */

void FUN_180042820(longlong param_1)

{
  int iVar1;
  longlong unaff_RSI;
  longlong lVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x18)) {
    lVar2 = 0;
    do {
      FUN_1800427f0(*(longlong *)(*(longlong *)(unaff_RSI + 0x20) + lVar2));
      iVar1 = iVar1 + 1;
      lVar2 = lVar2 + 8;
    } while (iVar1 < *(int *)(unaff_RSI + 0x18));
  }
  return;
}

/* ---- FUNC 0004282C FUN_18004282c (36 bytes) ---- */

void FUN_18004282c(void)

{
  uint unaff_EBX;
  longlong unaff_RSI;
  ulonglong uVar1;
  
  uVar1 = (ulonglong)unaff_EBX;
  do {
    FUN_1800427f0(*(longlong *)(*(longlong *)(unaff_RSI + 0x20) + uVar1));
    unaff_EBX = unaff_EBX + 1;
    uVar1 = uVar1 + 8;
  } while ((int)unaff_EBX < *(int *)(unaff_RSI + 0x18));
  return;
}

/* ---- FUNC 00042850 FUN_180042850 (5 bytes) ---- */

void FUN_180042850(void)

{
  return;
}

/* ---- FUNC 00042855 FUN_180042855 (6 bytes) ---- */

void FUN_180042855(void)

{
  return;
}

/* ---- FUNC 00042860 FUN_180042860 (348 bytes) ---- */

void FUN_180042860(longlong param_1,
                  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2)

{
  char cVar1;
  int iVar2;
  IAtlStringMgr *pIVar3;
  char local_res8 [16];
  undefined4 local_res18;
  char *local_res20;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_38 [8];
  char *local_30;
  char *local_28 [2];
  
  local_res18 = 0;
  if (*(char *)(param_1 + 0xb0) != '.') {
    iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find(param_2,".",0);
    if (-1 < iVar2) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                (param_2,(int)&local_30);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Right
                (param_2,(int)local_28);
      cVar1 = *(char *)(param_1 + 0xb0);
      pIVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_30
                         );
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
                 pIVar3);
      local_res18 = 1;
      local_res8[0] = cVar1;
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)&local_res20,local_30,*(int *)(local_30 + -0x10),
                 local_res8,1);
      pIVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          &local_res20);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_38,pIVar3);
      local_res18 = 3;
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)local_38,local_res20,*(int *)(local_res20 + -0x10),
                 local_28[0],*(int *)(local_28[0] + -0x10));
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                (param_2,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                          *)local_38);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_38);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_28);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_30);
    }
  }
  return;
}

/* ---- FUNC 000429C0 FUN_1800429c0 (306 bytes) ---- */

undefined8
FUN_1800429c0(longlong param_1,ushort *param_2,undefined4 param_3,undefined8 param_4,
             undefined4 *param_5)

{
  ushort uVar1;
  longlong *plVar2;
  bool bVar3;
  HRESULT HVar4;
  undefined8 uVar5;
  LPDATAADVISEHOLDER *ppDAHolder;
  uint uVar6;
  
  bVar3 = false;
  *param_5 = 0;
  uVar1 = *param_2;
  if ((((uVar1 == 0) && (*(longlong *)(param_2 + 4) == 0)) && (*(int *)(param_2 + 8) == -1)) &&
     ((bVar3 = false, *(int *)(param_2 + 10) == -1 && (bVar3 = false, *(int *)(param_2 + 0xc) == -1)
      ))) {
    bVar3 = true;
  }
  uVar6 = (uint)uVar1;
  if ((uVar6 == *(uint *)(param_1 + 0x10)) && (*(int *)(param_2 + 0xc) == 4)) {
    bVar3 = true;
  }
  if ((uVar6 == *(uint *)(param_1 + 0x14)) && (*(int *)(param_2 + 0xc) == 1)) {
    bVar3 = true;
  }
  if ((uVar6 == 1) && (*(int *)(param_2 + 0xc) == 1)) {
    bVar3 = true;
  }
  if ((uVar6 == *(uint *)(param_1 + 0x18)) && (*(int *)(param_2 + 0xc) == 1)) {
    bVar3 = true;
  }
  uVar6 = (uint)uVar1;
  if ((uVar6 == *(uint *)(param_1 + 0x28)) && (*(int *)(param_2 + 0xc) == 1)) {
    bVar3 = true;
  }
  if ((uVar6 == *(uint *)(param_1 + 0x2c)) && (*(int *)(param_2 + 0xc) == 1)) {
    bVar3 = true;
  }
  if ((uVar6 == 3) && (*(int *)(param_2 + 0xc) == 0x20)) {
    bVar3 = true;
  }
  if ((((uVar6 == *(uint *)(param_1 + 0x20)) && (*(int *)(param_2 + 0xc) == 4)) ||
      ((uVar6 == *(uint *)(param_1 + 0x24) && (*(int *)(param_2 + 0xc) == 1)))) || (bVar3)) {
    ppDAHolder = (LPDATAADVISEHOLDER *)(*(longlong *)(param_1 + 8) + 0x98);
    if ((*ppDAHolder == (LPDATAADVISEHOLDER)0x0) &&
       (HVar4 = CreateDataAdviseHolder(ppDAHolder), HVar4 < 0)) {
      return 0x8007000e;
    }
    plVar2 = *(longlong **)(*(longlong *)(param_1 + 8) + 0x98);
    uVar5 = (**(code **)(*plVar2 + 0x18))(plVar2,param_1,param_2,param_3,param_4,param_5);
  }
  else {
    uVar5 = 0x80040064;
  }
  return uVar5;
}

/* ---- FUNC 00042B00 FUN_180042b00 (36 bytes) ---- */

undefined8 FUN_180042b00(longlong param_1,int param_2)

{
  longlong *plVar1;
  undefined8 uVar2;
  
  if (param_2 == 0) {
    return 0;
  }
  plVar1 = *(longlong **)(*(longlong *)(param_1 + 8) + 0x98);
  if (plVar1 == (longlong *)0x0) {
    return 0x80004005;
  }
                    /* WARNING: Could not recover jumptable at 0x000180042b20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(*plVar1 + 0x20))();
  return uVar2;
}

/* ---- FUNC 00042B30 FUN_180042b30 (51 bytes) ---- */

undefined8 FUN_180042b30(undefined8 param_1,int param_2)

{
  if (param_2 == -3) {
    FUN_180037570();
    return 0;
  }
  if (1 < param_2 + 1U) {
    return 0x40180;
  }
  FUN_180037380();
  return 0;
}

/* ---- FUNC 00042B70 FUN_180042b70 (29 bytes) ---- */

undefined8 FUN_180042b70(longlong param_1)

{
  longlong *plVar1;
  undefined8 uVar2;
  
  plVar1 = *(longlong **)(*(longlong *)(param_1 + 8) + 0xa0);
  if (plVar1 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000180042b83. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(*plVar1 + 0x28))();
    return uVar2;
  }
  return 0x80004005;
}

/* ---- FUNC 00042B90 FUN_180042b90 (29 bytes) ---- */

undefined8 FUN_180042b90(longlong param_1)

{
  longlong *plVar1;
  undefined8 uVar2;
  
  plVar1 = *(longlong **)(*(longlong *)(param_1 + 8) + 0x98);
  if (plVar1 == (longlong *)0x0) {
    return 0x80004005;
  }
                    /* WARNING: Could not recover jumptable at 0x000180042ba9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(*plVar1 + 0x28))();
  return uVar2;
}

/* ---- FUNC 00042BB0 FUN_180042bb0 (487 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HRESULT FUN_180042bb0(longlong param_1,DWORD param_2,LPENUMFORMATETC *param_3)

{
  bool bVar1;
  int iVar2;
  HRESULT HVar3;
  CEnumArray *pCVar4;
  undefined7 extraout_var;
  undefined1 auStack_488 [32];
  undefined2 local_468 [4];
  undefined8 local_460;
  undefined4 local_458;
  undefined4 local_454;
  undefined4 local_450;
  CEnumArray *local_448;
  IID local_440;
  undefined1 local_428 [1008];
  ulonglong local_38;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStack_488;
  iVar2 = (**(code **)(*DAT_180079800 + 0x138))(DAT_180079800,&local_440);
  if (iVar2 != 0) {
    FUN_180002a20(local_428,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnode_dataobj.cpp",0x4f9);
    LogMessage(local_428,2,1);
  }
  if (param_2 == 1) {
    local_448 = operator_new(0x78);
    if (local_448 == (CEnumArray *)0x0) {
      pCVar4 = (CEnumArray *)0x0;
    }
    else {
      pCVar4 = FUN_180041bf0(local_448);
    }
    local_468[0] = 1;
    local_458 = 1;
    local_460 = 0;
    local_450 = 1;
    local_454 = 0xffffffff;
    FUN_1800421c0((longlong)pCVar4,local_468);
    local_468[0] = *(undefined2 *)(param_1 + 0x1c);
    FUN_1800421c0((longlong)pCVar4,local_468);
    local_468[0] = *(undefined2 *)(param_1 + 0x18);
    FUN_1800421c0((longlong)pCVar4,local_468);
    local_468[0] = *(undefined2 *)(param_1 + 0x28);
    FUN_1800421c0((longlong)pCVar4,local_468);
    local_468[0] = *(undefined2 *)(param_1 + 0x2c);
    FUN_1800421c0((longlong)pCVar4,local_468);
    local_468[0] = *(undefined2 *)(param_1 + 0x20);
    local_450 = 4;
    FUN_1800421c0((longlong)pCVar4,local_468);
    local_468[0] = *(undefined2 *)(param_1 + 0x24);
    local_450 = 1;
    FUN_1800421c0((longlong)pCVar4,local_468);
    bVar1 = FUN_180042630(*(longlong *)(param_1 + 8));
    if ((int)CONCAT71(extraout_var,bVar1) != 0) {
      local_468[0] = *(undefined2 *)(param_1 + 0x10);
      local_450 = 4;
      FUN_1800421c0((longlong)pCVar4,local_468);
      local_468[0] = *(undefined2 *)(param_1 + 0x14);
      local_450 = 1;
      FUN_1800421c0((longlong)pCVar4,local_468);
    }
    *param_3 = (LPENUMFORMATETC)(pCVar4 + 0x68);
    HVar3 = 0;
  }
  else {
    HVar3 = OleRegEnumFormatEtc(&local_440,param_2,param_3);
  }
  return HVar3;
}

/* ---- FUNC 00042DA0 FUN_180042da0 (6 bytes) ---- */

undefined8 FUN_180042da0(void)

{
  return 0x40000;
}

/* ---- FUNC 00042DB0 FUN_180042db0 (6 bytes) ---- */

undefined8 FUN_180042db0(void)

{
  return 0x40130;
}

/* ---- FUNC 00042DC0 FUN_180042dc0 (42 bytes) ---- */

undefined8 FUN_180042dc0(longlong param_1,undefined8 *param_2)

{
  *param_2 = *(undefined8 *)(*(longlong *)(param_1 + 8) + 0x90);
  (**(code **)(**(longlong **)(*(longlong *)(param_1 + 8) + 0x90) + 8))();
  return 0;
}

/* ---- FUNC 00042DF0 FUN_180042df0 (45 bytes) ---- */

undefined8 FUN_180042df0(longlong param_1,undefined8 param_2,longlong *param_3)

{
  undefined8 uVar1;
  longlong *plVar2;
  
  plVar2 = (longlong *)(*(longlong *)(param_1 + 8) + 0x18);
  *param_3 = (longlong)plVar2;
  (**(code **)(*plVar2 + 8))();
  uVar1 = 0x80004005;
  if (*param_3 != 0) {
    uVar1 = 0;
  }
  return uVar1;
}

/* ---- FUNC 00042E20 FUN_180042e20 (401 bytes) ---- */

ulonglong FUN_180042e20(longlong param_1,ushort *param_2,int *param_3)

{
  uint uVar1;
  ushort uVar2;
  code *pcVar3;
  bool bVar4;
  HRESULT HVar5;
  ulonglong uVar6;
  undefined4 extraout_var_00;
  undefined7 extraout_var;
  undefined4 extraout_var_01;
  uint uVar7;
  
  uVar2 = *param_2;
  uVar7 = (uint)uVar2;
  if ((*(uint *)(param_2 + 0xc) & 1) == 0) {
    if ((*(uint *)(param_2 + 0xc) != 4) || (uVar7 == *(uint *)(param_1 + 0x20))) goto LAB_180042e7d;
    uVar1 = *(uint *)(param_1 + 0x10);
  }
  else {
    if (((((uint)uVar2 == *(uint *)(param_1 + 0x1c)) || ((uint)uVar2 == *(uint *)(param_1 + 0x18)))
        || (uVar7 == *(uint *)(param_1 + 0x28))) ||
       ((uVar7 == *(uint *)(param_1 + 0x2c) || (uVar7 == *(uint *)(param_1 + 0x24)))))
    goto LAB_180042e7d;
    uVar1 = *(uint *)(param_1 + 0x14);
  }
  if (uVar7 == uVar1) {
    FUN_180042630(*(longlong *)(param_1 + 8));
  }
LAB_180042e7d:
  if (uVar7 == 1) {
    if ((param_2[0xc] & 1) != 0) {
      uVar6 = FUN_180046bf0(*(longlong *)(param_1 + 8),param_3);
      return uVar6;
    }
  }
  else if ((uVar7 == 3) && ((param_2[0xc] & 0x20) != 0)) {
    uVar6 = FUN_1800466f0(*(longlong *)(param_1 + 8),param_3);
    return uVar6;
  }
  if ((uVar7 == *(uint *)(param_1 + 0x1c)) && ((param_2[0xc] & 1) != 0)) {
    FUN_180046bc0(*(longlong *)(param_1 + 8));
    pcVar3 = (code *)swi(3);
    uVar6 = (*pcVar3)();
    return uVar6;
  }
  if ((uVar7 == *(uint *)(param_1 + 0x18)) && ((param_2[0xc] & 1) != 0)) {
    uVar6 = FUN_180046160(*(longlong *)(param_1 + 8),param_3);
  }
  else if ((uVar7 == *(uint *)(param_1 + 0x28)) && ((param_2[0xc] & 1) != 0)) {
    uVar6 = FUN_180045890(*(longlong *)(param_1 + 8),param_3,'\x01');
  }
  else if ((uVar7 == *(uint *)(param_1 + 0x2c)) && ((param_2[0xc] & 1) != 0)) {
    uVar6 = FUN_180045890(*(longlong *)(param_1 + 8),param_3,'\0');
  }
  else if (((uVar7 == *(uint *)(param_1 + 0x20)) && (uVar1 = *(uint *)(param_2 + 0xc), uVar1 == 4))
          || ((uVar7 == *(uint *)(param_1 + 0x24) && (uVar1 = 1, *(int *)(param_2 + 0xc) == 1)))) {
    HVar5 = FUN_1800467b0(*(longlong *)(param_1 + 8),uVar7,param_3,(ulonglong)uVar1,0);
    uVar6 = CONCAT44(extraout_var_00,HVar5);
  }
  else {
    bVar4 = FUN_180042630(*(longlong *)(param_1 + 8));
    if (((int)CONCAT71(extraout_var,bVar4) == 0) ||
       (((uVar7 != *(uint *)(param_1 + 0x10) || (*(int *)(param_2 + 0xc) != 4)) &&
        ((uVar7 != *(uint *)(param_1 + 0x14) || (*(int *)(param_2 + 0xc) != 1)))))) {
      uVar6 = 0x80040064;
    }
    else {
      HVar5 = FUN_1800462d0(*(longlong *)(param_1 + 8),uVar7,param_3,0);
      uVar6 = CONCAT44(extraout_var_01,HVar5);
    }
  }
  return uVar6;
}

/* ---- FUNC 00042FC0 FUN_180042fc0 (570 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180042fc0(longlong param_1,ushort *param_2,int *param_3)

{
  UINT UVar1;
  ushort uVar2;
  uint uVar3;
  code *pcVar4;
  bool bVar5;
  UINT UVar6;
  int iVar7;
  HRESULT HVar8;
  ulonglong uVar9;
  undefined4 extraout_var_00;
  undefined7 extraout_var;
  undefined4 extraout_var_01;
  uint uVar10;
  undefined1 auStackY_468 [32];
  IID local_438;
  undefined1 local_428 [1008];
  ulonglong local_38;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStackY_468;
  UVar6 = RegisterClipboardFormatA("Link Source");
  if ((*(uint *)(param_2 + 0xc) & 1) == 0) {
    if ((*(uint *)(param_2 + 0xc) != 4) || (UVar6 == *(UINT *)(param_1 + 0x20))) goto LAB_18004303a;
    UVar1 = *(UINT *)(param_1 + 0x10);
  }
  else {
    if (((((UVar6 == 1) || (UVar6 == *(UINT *)(param_1 + 0x1c))) ||
         (UVar6 == *(UINT *)(param_1 + 0x18))) ||
        ((UVar6 == *(UINT *)(param_1 + 0x28) || (UVar6 == *(UINT *)(param_1 + 0x2c))))) ||
       (UVar6 == *(UINT *)(param_1 + 0x24))) goto LAB_18004303a;
    UVar1 = *(UINT *)(param_1 + 0x14);
  }
  if (UVar6 == UVar1) {
    FUN_180042630(*(longlong *)(param_1 + 8));
  }
LAB_18004303a:
  uVar2 = *param_2;
  uVar10 = (uint)uVar2;
  if ((UVar6 == uVar10) && ((param_2[0xc] & 8) != 0)) {
    *param_3 = 8;
    param_3[4] = 0;
    param_3[5] = 0;
    iVar7 = (**(code **)(*DAT_180079800 + 0x138))(DAT_180079800,&local_438);
    if (iVar7 != 0) {
      FUN_180002a20(local_428,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnode_dataobj.cpp",0x419);
      LogMessage(local_428,2,1);
    }
    WriteClassStg(*(LPSTORAGE *)(param_3 + 2),&local_438);
    uVar9 = 0;
  }
  else {
    if (uVar10 == 1) {
      if ((param_2[0xc] & 1) != 0) {
        uVar9 = FUN_180046bf0(*(longlong *)(param_1 + 8),param_3);
        return uVar9;
      }
    }
    else if ((uVar10 == 3) && ((param_2[0xc] & 0x20) != 0)) {
      uVar9 = FUN_1800466f0(*(longlong *)(param_1 + 8),param_3);
      return uVar9;
    }
    uVar10 = (uint)uVar2;
    if ((uVar10 == *(uint *)(param_1 + 0x1c)) && ((param_2[0xc] & 1) != 0)) {
      FUN_180046bc0(*(longlong *)(param_1 + 8));
      pcVar4 = (code *)swi(3);
      uVar9 = (*pcVar4)();
      return uVar9;
    }
    if ((uVar10 == *(uint *)(param_1 + 0x18)) && ((param_2[0xc] & 1) != 0)) {
      uVar9 = FUN_180046160(*(longlong *)(param_1 + 8),param_3);
    }
    else if ((uVar10 == *(uint *)(param_1 + 0x28)) && ((param_2[0xc] & 1) != 0)) {
      uVar9 = FUN_180045890(*(longlong *)(param_1 + 8),param_3,'\x01');
    }
    else if ((uVar10 == *(uint *)(param_1 + 0x2c)) && ((param_2[0xc] & 1) != 0)) {
      uVar9 = FUN_180045890(*(longlong *)(param_1 + 8),param_3,'\0');
    }
    else {
      uVar10 = (uint)uVar2;
      if (((uVar10 == *(uint *)(param_1 + 0x20)) && (uVar3 = *(uint *)(param_2 + 0xc), uVar3 == 4))
         || ((uVar10 == *(uint *)(param_1 + 0x24) && (uVar3 = 1, *(int *)(param_2 + 0xc) == 1)))) {
        HVar8 = FUN_1800467b0(*(longlong *)(param_1 + 8),uVar10,param_3,(ulonglong)uVar3,1);
        uVar9 = CONCAT44(extraout_var_00,HVar8);
      }
      else {
        bVar5 = FUN_180042630(*(longlong *)(param_1 + 8));
        if (((int)CONCAT71(extraout_var,bVar5) == 0) ||
           (((uVar10 != *(uint *)(param_1 + 0x10) || (*(int *)(param_2 + 0xc) != 4)) &&
            ((uVar10 != *(uint *)(param_1 + 0x14) || (*(int *)(param_2 + 0xc) != 1)))))) {
          uVar9 = 0x80040064;
        }
        else {
          HVar8 = FUN_1800462d0(*(longlong *)(param_1 + 8),uVar10,param_3,1);
          uVar9 = CONCAT44(extraout_var_01,HVar8);
        }
      }
    }
  }
  return uVar9;
}

/* ---- FUNC 00043200 FUN_180043200 (239 bytes) ---- */

longlong FUN_180043200(longlong param_1,longlong param_2,int *param_3)

{
  void *pvVar1;
  longlong lVar2;
  longlong lVar3;
  CPtrArray local_58 [8];
  longlong local_50;
  longlong local_48;
  CPtrArray local_30 [40];
  
  CPtrArray::CPtrArray(local_58);
  CPtrArray::Copy(local_58,(CPtrArray *)(*(longlong *)(param_1 + 0x78) + 0x50));
  CPtrArray::CPtrArray(local_30);
  CPtrArray::SetSize(local_30,0,-1);
  lVar2 = local_48;
  lVar3 = local_48;
  if (local_48 < 1) {
    *(undefined1 *)((longlong)*param_3 + -1 + param_2) = 10;
    CPtrArray::~CPtrArray(local_30);
    CPtrArray::~CPtrArray(local_58);
    return param_2;
  }
  while ((lVar3 = lVar3 + -1, -1 < lVar3 && (lVar3 < lVar2))) {
    pvVar1 = *(void **)(local_50 + lVar3 * 8);
    if ((pvVar1 != (void *)0x0) &&
       ((*(longlong *)((longlong)pvVar1 + 0x38) != 0 &&
        (*(int *)(*(longlong *)((longlong)pvVar1 + 0x38) + 0xc) != -1)))) {
      CPtrArray::InsertAt(local_30,0,pvVar1,1);
      CPtrArray::RemoveAt(local_58,lVar3,1);
      lVar2 = local_48;
    }
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 000432F0 FUN_1800432f0 (75 bytes) ---- */

undefined8 FUN_1800432f0(longlong param_1,int param_2,undefined8 *param_3)

{
  longlong lVar1;
  int iVar2;
  void *pvVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  uint uVar7;
  
  puVar5 = (undefined8 *)0x0;
  iVar2 = *(int *)(param_1 + 0x18);
  if (0 < iVar2) {
    plVar6 = *(longlong **)(param_1 + 0x20);
    puVar4 = puVar5;
    do {
      if (*(int *)(*plVar6 + 0x80) == param_2) {
        plVar6 = (longlong *)((*(longlong **)(param_1 + 0x20))[(int)puVar4] + 0x18);
        *param_3 = plVar6;
        (**(code **)(*plVar6 + 8))();
        return 0;
      }
      uVar7 = (int)puVar4 + 1;
      puVar4 = (undefined8 *)(ulonglong)uVar7;
      plVar6 = plVar6 + 1;
    } while ((int)uVar7 < iVar2);
  }
  if (*(void **)(param_1 + 0x20) == (void *)0x0) {
    pvVar3 = malloc(8);
  }
  else {
    pvVar3 = realloc(*(void **)(param_1 + 0x20),(longlong)(iVar2 + 1) << 3);
  }
  *(void **)(param_1 + 0x20) = pvVar3;
  iVar2 = *(int *)(param_1 + 0x18);
  if (*(int *)(param_1 + 0x2c) == 0) {
    puVar4 = operator_new(0xb8);
    if (puVar4 != (undefined8 *)0x0) {
      puVar5 = FUN_180041c30(puVar4,*(longlong **)(param_1 + 0x10),*(undefined8 *)(param_1 + 8),
                             param_2,*(int *)(param_1 + 0x28));
    }
  }
  else {
    puVar4 = operator_new(0xb8);
    if (puVar4 != (undefined8 *)0x0) {
      puVar5 = FUN_180041da0(puVar4,*(longlong **)(param_1 + 0x10),*(undefined8 *)(param_1 + 8),
                             param_2,*(int *)(param_1 + 0x28),1);
    }
  }
  lVar1 = (longlong)iVar2 * 8;
  *(undefined8 **)(lVar1 + *(longlong *)(param_1 + 0x20)) = puVar5;
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  plVar6 = (longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x20) + lVar1) + 0x18);
  *param_3 = plVar6;
  (**(code **)(*plVar6 + 8))();
  return 0;
}

/* ---- FUNC 0004333B FUN_18004333b (22 bytes) ---- */

undefined8 FUN_18004333b(int param_1,undefined8 param_2,void *param_3)

{
  longlong lVar1;
  int iVar2;
  void *pvVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  undefined4 unaff_ESI;
  longlong unaff_RDI;
  undefined8 *unaff_R14;
  undefined8 *unaff_R15;
  
  if (param_3 == (void *)0x0) {
    pvVar3 = malloc(8);
  }
  else {
    pvVar3 = realloc(param_3,(longlong)(param_1 + 1) << 3);
  }
  *(void **)(unaff_RDI + 0x20) = pvVar3;
  iVar2 = *(int *)(unaff_RDI + 0x18);
  if (*(int *)(unaff_RDI + 0x2c) == (int)unaff_R14) {
    puVar4 = operator_new(0xb8);
    if (puVar4 != (undefined8 *)0x0) {
      unaff_R14 = FUN_180041c30(puVar4,*(longlong **)(unaff_RDI + 0x10),
                                *(undefined8 *)(unaff_RDI + 8),unaff_ESI,*(int *)(unaff_RDI + 0x28))
      ;
    }
  }
  else {
    puVar4 = operator_new(0xb8);
    if (puVar4 != (undefined8 *)0x0) {
      unaff_R14 = FUN_180041da0(puVar4,*(longlong **)(unaff_RDI + 0x10),
                                *(undefined8 *)(unaff_RDI + 8),unaff_ESI,*(int *)(unaff_RDI + 0x28),
                                1);
    }
  }
  lVar1 = (longlong)iVar2 * 8;
  *(undefined8 **)(lVar1 + *(longlong *)(unaff_RDI + 0x20)) = unaff_R14;
  *(int *)(unaff_RDI + 0x18) = *(int *)(unaff_RDI + 0x18) + 1;
  plVar5 = (longlong *)(*(longlong *)(*(longlong *)(unaff_RDI + 0x20) + lVar1) + 0x18);
  *unaff_R15 = plVar5;
  (**(code **)(*plVar5 + 8))();
  return 0;
}

/* ---- FUNC 00043351 FUN_180043351 (25 bytes) ---- */

undefined8 FUN_180043351(undefined8 param_1,longlong param_2,undefined8 param_3,int param_4)

{
  longlong *plVar1;
  undefined8 *unaff_R15;
  
  plVar1 = (longlong *)(*(longlong *)(param_2 + (longlong)param_4 * 8) + 0x18);
  *unaff_R15 = plVar1;
  (**(code **)(*plVar1 + 8))();
  return 0;
}

/* ---- FUNC 0004336A FUN_18004336a (168 bytes) ---- */

undefined8 FUN_18004336a(int param_1,undefined8 param_2,void *param_3)

{
  longlong lVar1;
  int iVar2;
  void *pvVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  undefined4 unaff_ESI;
  longlong unaff_RDI;
  undefined8 *unaff_R14;
  undefined8 *unaff_R15;
  
  pvVar3 = realloc(param_3,(longlong)(param_1 + 1) << 3);
  *(void **)(unaff_RDI + 0x20) = pvVar3;
  iVar2 = *(int *)(unaff_RDI + 0x18);
  if (*(int *)(unaff_RDI + 0x2c) == (int)unaff_R14) {
    puVar4 = operator_new(0xb8);
    if (puVar4 != (undefined8 *)0x0) {
      unaff_R14 = FUN_180041c30(puVar4,*(longlong **)(unaff_RDI + 0x10),
                                *(undefined8 *)(unaff_RDI + 8),unaff_ESI,*(int *)(unaff_RDI + 0x28))
      ;
    }
  }
  else {
    puVar4 = operator_new(0xb8);
    if (puVar4 != (undefined8 *)0x0) {
      unaff_R14 = FUN_180041da0(puVar4,*(longlong **)(unaff_RDI + 0x10),
                                *(undefined8 *)(unaff_RDI + 8),unaff_ESI,*(int *)(unaff_RDI + 0x28),
                                1);
    }
  }
  lVar1 = (longlong)iVar2 * 8;
  *(undefined8 **)(lVar1 + *(longlong *)(unaff_RDI + 0x20)) = unaff_R14;
  *(int *)(unaff_RDI + 0x18) = *(int *)(unaff_RDI + 0x18) + 1;
  plVar5 = (longlong *)(*(longlong *)(*(longlong *)(unaff_RDI + 0x20) + lVar1) + 0x18);
  *unaff_R15 = plVar5;
  (**(code **)(*plVar5 + 8))();
  return 0;
}

/* ---- FUNC 00043412 FUN_180043412 (22 bytes) ---- */

undefined8 FUN_180043412(void)

{
  return 0;
}

/* ---- FUNC 00043430 FUN_180043430 (8 bytes) ---- */

undefined ** FUN_180043430(void)

{
  return &PTR_LAB_180065e38;
}

/* ---- FUNC 00043440 FUN_180043440 (1251 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char * FUN_180043440(undefined8 param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  int iVar3;
  undefined8 *puVar4;
  longlong lVar5;
  char *pcVar7;
  IAtlStringMgr *pIVar8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  int iVar9;
  undefined1 auStackY_198 [32];
  char *local_168;
  undefined4 local_160;
  char *local_158;
  int local_150 [2];
  char *local_148;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_140 [16];
  longlong *local_130;
  char local_128 [256];
  ulonglong local_28;
  longlong lVar6;
  
  local_28 = DAT_180077818 ^ (ulonglong)auStackY_198;
  iVar9 = 0;
  local_160 = 0;
  DAT_180079c40 = '\0';
  local_130 = (longlong *)0x0;
  iVar3 = (**(code **)**(undefined8 **)(param_2 + 0x60))
                    (*(undefined8 **)(param_2 + 0x60),&DAT_180063400);
  if (-1 < iVar3) {
    local_150[0] = 0;
    (**(code **)(*local_130 + 0x58))(local_130,local_150);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_168,"");
    if ((1 < local_150[0]) && (0 < local_150[0])) {
      do {
        puVar4 = (undefined8 *)HAGetElementLocation(*(undefined8 *)(param_2 + 0x48),iVar9);
        if (puVar4 == (undefined8 *)0x0) {
          if (DAT_180079c40 == '\0') {
            puVar4 = (undefined8 *)HAGetDecoratedColumn(local_130[9],iVar9);
            if (puVar4 != (undefined8 *)0x0) {
              if ((code *)*puVar4 != (code *)0x0) {
                (*(code *)*puVar4)(puVar4);
              }
              DAT_180079c40 = '\0';
              goto LAB_180043556;
            }
            if (DAT_180079c40 == '\0') goto LAB_180043556;
          }
          else {
LAB_180043556:
            local_128[0] = '\0';
            puVar4 = (undefined8 *)HAGetLabel(local_130[9],iVar9);
            if (puVar4 != (undefined8 *)0x0) goto LAB_1800434f6;
            if (local_128[0] != '\0') {
              if (*(int *)(local_168 + -0x10) == 0) {
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_168,local_128);
              }
              else {
                pIVar8 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                         GetManager((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
                                    )&local_168);
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_158,pIVar8);
                local_160 = 4;
                ATL::CSimpleStringT<char,1>::Concatenate
                          ((CSimpleStringT<char,1> *)&local_158,local_168,
                           *(int *)(local_168 + -0x10)," ",1);
                pIVar8 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                         GetManager((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
                                    )&local_158);
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_140,pIVar8);
                local_160 = 0xc;
                lVar6 = -1;
                do {
                  lVar5 = lVar6 + 1;
                  lVar2 = lVar6 + 1;
                  lVar6 = lVar5;
                } while (local_128[lVar2] != '\0');
                ATL::CSimpleStringT<char,1>::Concatenate
                          ((CSimpleStringT<char,1> *)local_140,local_158,*(int *)(local_158 + -0x10)
                           ,local_128,(int)lVar5);
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_168,
                           (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                            *)local_140);
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_140);
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_158);
              }
            }
          }
        }
        else {
LAB_1800434f6:
          if ((code *)*puVar4 != (code *)0x0) {
            (*(code *)*puVar4)(puVar4);
          }
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < local_150[0]);
    }
    (**(code **)(*local_130 + 0x10))();
    if (DAT_180079c40 != '\0') {
      if (*(int *)(local_168 + -0x10) != 0) {
        pcVar7 = (char *)((longlong)&DAT_180079c38 + 7);
        do {
          pcVar7 = pcVar7 + 1;
        } while (*pcVar7 != '\0');
        *(undefined2 *)pcVar7 = DAT_1800633a4;
        pcVar7 = (char *)((longlong)&DAT_180079c38 + 7);
        do {
          pcVar7 = pcVar7 + 1;
        } while (*pcVar7 != '\0');
        lVar6 = 0;
        do {
          cVar1 = local_168[lVar6];
          pcVar7[lVar6] = cVar1;
          lVar6 = lVar6 + 1;
        } while (cVar1 != '\0');
      }
      this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_168;
      goto LAB_1800438f6;
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_168);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_148,"");
  iVar3 = *(int *)(param_2 + 0x68);
  while (iVar3 == 0) {
    puVar4 = (undefined8 *)HAGetDecoratedName(*(undefined8 *)(param_2 + 0x48),&DAT_180079c40);
    if (puVar4 == (undefined8 *)0x0) {
      if (DAT_180079c40 != '\0') break;
    }
    else {
      if ((code *)*puVar4 != (code *)0x0) {
        (*(code *)*puVar4)(puVar4);
      }
      DAT_180079c40 = '\0';
    }
    pcVar7 = FUN_18003a1d0(*(longlong **)(param_2 + 0xe8));
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_168,pcVar7);
    iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_168,
                       "Input");
    if ((iVar3 == 0) ||
       (iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_168,"Output"), iVar3 == 0)) {
      if (*(int *)(local_148 + -0x10) != 0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_168);
        break;
      }
LAB_180043864:
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_148,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 &local_168);
    }
    else {
      if (*(int *)(local_148 + -0x10) == 0) goto LAB_180043864;
      pIVar8 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          &local_168);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_158,pIVar8)
      ;
      local_160 = 1;
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)&local_158,local_168,*(int *)(local_168 + -0x10)," ",1);
      pIVar8 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          &local_158);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_140,pIVar8);
      local_160 = 3;
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)local_140,local_158,*(int *)(local_158 + -0x10),local_148
                 ,*(int *)(local_148 + -0x10));
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_148,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 local_140);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_140);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_158);
    }
    param_2 = *(longlong *)(param_2 + 0x60);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_168);
    iVar3 = *(int *)(param_2 + 0x68);
  }
  if (*(int *)(local_148 + -0x10) != 0) {
    if (DAT_180079c40 != '\0') {
      pcVar7 = (char *)((longlong)&DAT_180079c38 + 7);
      do {
        pcVar7 = pcVar7 + 1;
      } while (*pcVar7 != '\0');
      *(undefined2 *)pcVar7 = DAT_1800633a4;
    }
    pcVar7 = (char *)((longlong)&DAT_180079c38 + 7);
    do {
      pcVar7 = pcVar7 + 1;
    } while (*pcVar7 != '\0');
    lVar6 = 0;
    do {
      cVar1 = local_148[lVar6];
      pcVar7[lVar6] = cVar1;
      lVar6 = lVar6 + 1;
    } while (cVar1 != '\0');
  }
  this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_148;
LAB_1800438f6:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this);
  return &DAT_180079c40;
}

/* ---- FUNC 00043930 FUN_180043930 (497 bytes) ---- */

void FUN_180043930(longlong param_1)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  CPtrArray local_38 [8];
  longlong *local_30;
  longlong local_28;
  
  CPtrArray::CPtrArray(local_38);
  CPtrArray::Copy(local_38,(CPtrArray *)(*(longlong *)(param_1 + 0x78) + 0x50));
  while (0 < local_28) {
    if (*local_30 != 0) {
      lVar5 = *(longlong *)(*local_30 + 0x38);
      if (lVar5 != 0) {
        iVar1 = *(int *)(lVar5 + 0x18);
        iVar2 = *(int *)(lVar5 + 8);
        CPtrArray::RemoveAt(local_38,0,1);
        lVar4 = local_28;
        lVar5 = local_28;
        while ((lVar5 = lVar5 + -1, -1 < lVar5 && (lVar5 < lVar4))) {
          if ((local_30[lVar5] != 0) &&
             (((lVar3 = *(longlong *)(local_30[lVar5] + 0x38), lVar3 != 0 &&
               (iVar2 == *(int *)(lVar3 + 8))) && (iVar1 == *(int *)(lVar3 + 0x18))))) {
            CPtrArray::RemoveAt(local_38,lVar5,1);
            lVar4 = local_28;
          }
        }
        goto LAB_180043b1c;
      }
    }
    CPtrArray::RemoveAt(local_38,0,1);
  }
  CPtrArray::SetSize(local_38,0,-1);
  CPtrArray::Copy(local_38,(CPtrArray *)(*(longlong *)(param_1 + 0x78) + 0x50));
  do {
    if (local_28 < 1) {
      CPtrArray::SetSize(local_38,0,-1);
      CPtrArray::Copy(local_38,(CPtrArray *)(*(longlong *)(param_1 + 0x78) + 0x50));
      lVar4 = local_28;
      lVar5 = local_28;
      while ((lVar5 = lVar5 + -1, -1 < lVar5 && (lVar5 < lVar4))) {
        if ((*(longlong *)(local_30[lVar5] + 0x38) != 0) &&
           (*(int *)(*(longlong *)(local_30[lVar5] + 0x38) + 8) != -1)) {
          CPtrArray::RemoveAt(local_38,lVar5,1);
          lVar4 = local_28;
        }
      }
LAB_180043b1c:
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
    if (*local_30 != 0) {
      lVar5 = *(longlong *)(*local_30 + 0x38);
      if (lVar5 != 0) {
        iVar1 = *(int *)(lVar5 + 0x14);
        iVar2 = *(int *)(lVar5 + 0xc);
        CPtrArray::RemoveAt(local_38,0,1);
        lVar4 = local_28;
        lVar5 = local_28;
        while ((lVar5 = lVar5 + -1, -1 < lVar5 && (lVar5 < lVar4))) {
          lVar3 = *(longlong *)(local_30[lVar5] + 0x38);
          if ((lVar3 != 0) &&
             ((iVar2 == *(int *)(lVar3 + 0xc) && (iVar1 == *(int *)(lVar3 + 0x14))))) {
            CPtrArray::RemoveAt(local_38,lVar5,1);
            lVar4 = local_28;
          }
        }
        goto LAB_180043b1c;
      }
    }
    CPtrArray::RemoveAt(local_38,0,1);
  } while( true );
}

/* ---- FUNC 00043B30 FUN_180043b30 (91 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180043b30(longlong param_1)

{
  int iVar1;
  undefined1 auStack_38 [32];
  CHAR local_18 [8];
  ulonglong local_10;
  
  local_10 = DAT_180077818 ^ (ulonglong)auStack_38;
  *(undefined1 *)(param_1 + 0xb0) = 0x2e;
  iVar1 = GetLocaleInfoA(0x400,0xe,local_18,5);
  if (iVar1 != 0) {
    *(CHAR *)(param_1 + 0xb0) = local_18[0];
  }
  return;
}

/* ---- FUNC 00043B90 FUN_180043b90 (2637 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char * FUN_180043b90(longlong param_1,longlong param_2,int *param_3)

{
  longlong lVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  HRESULT HVar6;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar7;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar8;
  char *pcVar9;
  undefined8 *puVar10;
  wchar_t *pwVar11;
  char *pcVar12;
  undefined4 uVar13;
  longlong *plVar14;
  char *pcVar15;
  undefined1 auStackY_558 [32];
  int local_528 [2];
  wchar_t *local_520;
  char *local_518;
  _union_2707 local_510;
  _union_2707 local_4f8;
  wchar_t *local_4d8;
  char *local_4d0;
  longlong *local_4c8 [2];
  _union_2707 local_4b8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_498 [8];
  _union_2707 local_490;
  _union_2707 local_478;
  undefined4 local_458;
  ULONG UStack_454;
  ULONG UStack_450;
  ULONG UStack_44c;
  code *local_448;
  undefined1 local_438 [1008];
  ulonglong local_48;
  
  local_48 = DAT_180077818 ^ (ulonglong)auStackY_558;
  pcVar12 = (char *)0x0;
  uVar13 = 0;
  pcVar15 = (char *)0x0;
  local_528[0] = 0;
  *param_3 = 0;
  pcVar9 = pcVar12;
  switch(*(undefined4 *)(param_2 + 0x30)) {
  case 0:
    plVar14 = *(longlong **)(param_2 + 0x28);
    if ((*(byte *)(param_1 + 0x80) & 2) != 0) {
      pcVar9 = FUN_180043440(param_1,(longlong)plVar14);
      pcVar9 = FUN_180042410(param_1,(void *)0x0,local_528,pcVar9);
      *param_3 = *param_3 + 1;
    }
    if ((*(byte *)(param_1 + 0x80) & 8) != 0) {
      pcVar12 = *(char **)(param_2 + 0x50);
      if ((pcVar12 == (char *)0x0) || ((*pcVar12 == '-' && (pcVar12[1] == '\0')))) {
        pcVar12 = (char *)0x0;
      }
      pcVar9 = FUN_180042410(param_1,pcVar9,local_528,pcVar12);
      *param_3 = *param_3 + 1;
    }
    if ((*(byte *)(param_1 + 0x80) & 1) != 0) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4d8,"");
      VariantInit((VARIANTARG *)&local_4f8.n2);
      if (plVar14[9] == 0) {
LAB_180043f64:
        HVar6 = VariantChangeTypeEx((VARIANTARG *)&local_4f8.n2,(VARIANTARG *)&local_4f8.n2,0x400,0,
                                    8);
        if (-1 < HVar6) {
          pCVar8 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                   CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                             ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                              &local_518,(wchar_t *)local_4f8.decVal.u2);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4d8,
                     pCVar8);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_518);
        }
      }
      else {
        uVar13 = *(int *)(param_2 + 0x48);
        if ((uVar13 == 0) && (*(int *)(param_2 + 0x4c) == 0)) {
          local_520 = (wchar_t *)((ulonglong)local_520 & 0xffffffff00000000);
          VariantInit((VARIANTARG *)&local_4b8.n2);
          VariantInit((VARIANTARG *)&local_490.n2);
          local_478._16_8_ = local_4f8._16_8_;
          iVar4 = (**(code **)(*plVar14 + 0x98))(plVar14,2,&local_478,&local_4b8);
          uVar13 = 0;
          if (-1 < iVar4) {
            if (local_4b8.n2.vt == 2) {
              uVar13 = SEXT24((short)local_4b8._8_2_);
            }
            else if (local_4b8.n2.vt == 3) {
              uVar13 = local_4b8._8_4_;
            }
            VariantClear((VARIANTARG *)&local_4b8.n2);
          }
          local_478._16_8_ = local_4f8._16_8_;
          iVar4 = (**(code **)(*plVar14 + 0x98))(plVar14,3,&local_478,&local_490);
          if (-1 < iVar4) {
            if (local_490.n2.vt == 2) {
              local_490._8_4_ = SEXT24((short)local_490._8_2_);
LAB_180043d6b:
              local_520 = (wchar_t *)CONCAT44(local_520._4_4_,local_490._8_4_);
            }
            else if (local_490.n2.vt == 3) goto LAB_180043d6b;
            VariantClear((VARIANTARG *)&local_490.n2);
          }
          *(undefined4 *)(param_2 + 0x48) = uVar13;
          *(undefined4 *)(param_2 + 0x4c) = local_520._0_4_;
        }
        local_510.decVal.u2.Lo64 = (_union_1719)0x0;
        local_510._16_8_ = (code *)0x0;
        local_510._0_8_ = local_510._0_8_ & 0xffffffff00000000;
        puVar10 = (undefined8 *)HAGetValForUnitsBasis(plVar14[9],&local_510,uVar13);
        if (puVar10 != (undefined8 *)0x0) {
          if ((code *)*puVar10 != (code *)0x0) {
            (*(code *)*puVar10)(puVar10);
          }
          if (*(int *)(param_2 + 0x48) == 0) {
            if ((code *)local_510._16_8_ != (code *)0x0) {
              (*(code *)local_510._16_8_)(local_510.decVal.u2.Lo64);
            }
            puVar10 = (undefined8 *)HAGetAttr(plVar14[9],0,0);
            if ((puVar10 != (undefined8 *)0x0) && ((code *)*puVar10 != (code *)0x0)) {
              (*(code *)*puVar10)(puVar10);
            }
          }
        }
        if (local_510.decVal.u2.Lo64 == 0) goto LAB_180043f64;
        if (local_510._0_4_ == -6) {
          VariantCopy((VARIANTARG *)&local_4f8.n2,(VARIANTARG *)local_510.decVal.u2);
          bVar2 = false;
        }
        else if (local_510._0_4_ == -3) {
          local_4f8.n2.vt = 8;
          pCVar7 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                   ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                   CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                             ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                              &local_518,(char *)local_510.decVal.u2);
          local_4f8.decVal.u2 =
               (_union_1719)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::AllocSysString
                         (pCVar7);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_518);
          pCVar8 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                   CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                             ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                              &local_518,(wchar_t *)local_4f8.decVal.u2);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4d8,
                     pCVar8);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_518);
          if ((code *)local_510._16_8_ != (code *)0x0) {
            (*(code *)local_510._16_8_)(local_510.decVal.u2.Lo64);
          }
          local_510.decVal.u2.Lo64 = (_union_1719)0x0;
          local_510._16_8_ = (code *)0x0;
          local_510._0_8_ = local_510._0_8_ & 0xffffffff00000000;
          puVar10 = (undefined8 *)HAGetAttr(plVar14[9],0x34);
          if ((puVar10 != (undefined8 *)0x0) && ((code *)*puVar10 != (code *)0x0)) {
            (*(code *)*puVar10)(puVar10);
          }
          if (((local_510.decVal.u2.Lo64 != 0) && (local_510._0_4_ == -1)) &&
             (*(int *)local_510.decVal.u2 != 0)) {
            FUN_180042860(param_1,(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                  &local_4d8);
          }
          bVar2 = true;
        }
        else if (local_510._0_4_ == -2) {
          local_4f8.n2.vt = 5;
          local_4f8.decVal.u2 = (_union_1719)*(undefined8 *)local_510.decVal.u2;
          FUN_180047000(param_1,(double)local_4f8.decVal.u2,10,
                        (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4d8)
          ;
          bVar2 = true;
        }
        else {
          bVar2 = false;
          if (local_510._0_4_ == -1) {
            local_4f8.n2.vt = 3;
            local_4f8._8_4_ = *(undefined4 *)local_510.decVal.u2;
          }
        }
        if ((code *)local_510._16_8_ != (code *)0x0) {
          (*(code *)local_510._16_8_)(local_510.decVal.u2.Lo64);
        }
        if (!bVar2) goto LAB_180043f64;
      }
      VariantClear((VARIANTARG *)&local_4f8.n2);
      pcVar9 = FUN_180042410(param_1,pcVar9,local_528,(char *)local_4d8);
      *param_3 = *param_3 + 1;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4d8);
    }
    if ((*(byte *)(param_1 + 0x80) & 4) == 0) goto LAB_18004456f;
    if ((0 < *(int *)(param_2 + 0x48)) && (0 < *(int *)(param_2 + 0x4c))) {
      pcVar15 = FUN_18003e780((longlong)plVar14,*(int *)(param_2 + 0x48),*(int *)(param_2 + 0x4c));
    }
    break;
  default:
    FUN_180002a20(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnode_dataobj.cpp",0xb74);
    LogMessage(local_438,2,1);
    return (char *)0x0;
  case 2:
    pcVar9 = (char *)0x0;
    pcVar15 = *(char **)(param_2 + 0x28);
    break;
  case 3:
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              (local_498,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               (param_2 + 0x18));
    local_4c8[0] = (longlong *)0x0;
    iVar4 = (**(code **)(**(longlong **)(param_2 + 0x28) + 200))
                      (*(longlong **)(param_2 + 0x28),local_4c8);
    if ((-1 < iVar4) &&
       (iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                          (local_498,'x',0), pcVar9 = (char *)0x0, iVar4 != -1)) {
      puVar10 = (undefined8 *)
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                          (local_498,(int)&local_518);
      iVar4 = atoi((char *)*puVar10);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_518);
      puVar10 = (undefined8 *)
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                          (local_498,(int)&local_518);
      iVar5 = atoi((char *)*puVar10);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_518);
      local_478._0_8_ = 0;
      local_478.decVal.u2.Lo64 = (_union_1719)0x0;
      local_478._16_8_ = (code *)0x0;
      VariantInit((VARIANTARG *)&local_478.n2);
      local_510._0_8_ = 0;
      local_510.decVal.u2.Lo64 = (_union_1719)0x0;
      local_510._16_8_ = (code *)0x0;
      VariantInit((VARIANTARG *)&local_510.n2);
      local_520 = (wchar_t *)0x0;
      local_4b8._0_8_ = local_478._0_8_;
      local_4b8.decVal.u2.Lo64 = local_478.decVal.u2;
      local_4b8._16_8_ = local_478._16_8_;
      iVar5 = (**(code **)(*local_4c8[0] + 0x80))(local_4c8[0],iVar4,iVar5,&local_4b8);
      if (-1 < iVar5) {
        cVar3 = FUN_18002f2c0();
        if (cVar3 != '\0') {
          local_4b8._0_8_ = 0;
          local_4b8.decVal.u2.Lo64 = (_union_1719)0x0;
          local_4b8._16_8_ = (code *)0x0;
          VariantInit((VARIANTARG *)&local_4b8.n2);
          local_490._0_8_ = 0;
          local_490.decVal.u2.Lo64 = (_union_1719)0x0;
          local_490._16_8_ = 0;
          VariantInit((VARIANTARG *)&local_490.n2);
          local_4f8._0_8_ = local_510._0_8_;
          local_4f8.decVal.u2.s2 = local_510.decVal.u2;
          local_4f8._16_8_ = local_510._16_8_;
          iVar5 = (**(code **)(*local_4c8[0] + 0xa0))(local_4c8[0],iVar4);
          if (((iVar5 < 0) || (local_490.n2.vt != 3)) || (local_490._8_4_ == 0)) {
            local_458 = local_510._0_4_;
            UStack_454 = local_510.decVal.Hi32;
            UStack_450 = local_510._8_4_;
            UStack_44c = local_510._12_4_;
            local_448 = (code *)local_510._16_8_;
            iVar4 = (**(code **)(*local_4c8[0] + 0xa0))(local_4c8[0],iVar4);
            if ((-1 < iVar4) && (local_4b8.n2.vt == 3)) {
              uVar13 = local_4b8._8_4_;
              goto LAB_18004449d;
            }
          }
          else {
            pwVar11 = wcschr(local_520,L' ');
            if (pwVar11 != (wchar_t *)0x0) {
              plVar14 = *(longlong **)(param_2 + 0x28);
              while ((int)plVar14[0xd] == 0) {
                plVar14 = (longlong *)plVar14[0xc];
                local_4f8._0_8_ = 0;
                local_4f8.decVal.u2.Lo64 = (_union_1719)0x0;
                local_4f8._16_8_ = (code *)0x0;
                VariantInit((VARIANTARG *)&local_4f8.n2);
                local_458 = local_510._0_4_;
                UStack_454 = local_510.decVal.Hi32;
                UStack_450 = local_510._8_4_;
                UStack_44c = local_510._12_4_;
                local_448 = (code *)local_510._16_8_;
                iVar4 = (**(code **)(*plVar14 + 0x98))(plVar14,0x3b,&local_458,&local_4f8);
                if (((-1 < iVar4) && (local_4f8.n2.vt == 8)) &&
                   (iVar4 = _wcsicmp(L"BATCHFRAC",(wchar_t *)local_4f8.decVal.u2), iVar4 == 0)) {
                  pwVar11 = wcsrchr(local_520,L' ');
                  if (pwVar11 != (wchar_t *)0x0) {
                    *pwVar11 = L'\0';
                  }
                  uVar13 = 1;
                  VariantClear((VARIANTARG *)&local_4f8.n2);
                  break;
                }
                VariantClear((VARIANTARG *)&local_4f8.n2);
              }
            }
LAB_18004449d:
            if (((uVar13 != 0) &&
                (HVar6 = VarR8FromStr(local_520,0x7f,0,(DOUBLE *)&local_4d0), -1 < HVar6)) &&
               (HVar6 = VarBstrFromR8((DOUBLE)local_4d0,0x400,0,&local_4d8), -1 < HVar6)) {
              SysFreeString(local_520);
              local_520 = local_4d8;
            }
          }
          VariantClear((VARIANTARG *)&local_490.n2);
          VariantClear((VARIANTARG *)&local_4b8.n2);
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_518,
                   local_520);
        pcVar12 = FUN_180042410(param_1,(void *)0x0,local_528,local_518);
        *param_3 = *param_3 + 1;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_518);
      }
      SysFreeString(local_520);
      VariantClear((VARIANTARG *)&local_510.n2);
      VariantClear((VARIANTARG *)&local_478.n2);
      pcVar9 = pcVar12;
    }
    if (local_4c8[0] != (longlong *)0x0) {
      (**(code **)(*local_4c8[0] + 0x10))();
    }
    pCVar7 = local_498;
    goto LAB_180044569;
  case 4:
    if ((*(byte *)(param_1 + 0x80) & 2) != 0) {
      pcVar9 = FUN_180042410(param_1,(void *)0x0,local_528,(char *)0x0);
      *param_3 = *param_3 + 1;
    }
    if ((*(byte *)(param_1 + 0x80) & 8) != 0) {
      pcVar15 = *(char **)(param_2 + 0x50);
      if ((pcVar15 == (char *)0x0) || ((*pcVar15 == '-' && (pcVar15[1] == '\0')))) {
        pcVar15 = (char *)0x0;
      }
      pcVar9 = FUN_180042410(param_1,pcVar9,local_528,pcVar15);
      *param_3 = *param_3 + 1;
    }
    if ((*(byte *)(param_1 + 0x80) & 1) != 0) {
      pcVar9 = FUN_180042410(param_1,pcVar9,local_528,(char *)0x0);
      *param_3 = *param_3 + 1;
    }
    if ((*(byte *)(param_1 + 0x80) & 4) == 0) goto LAB_18004456f;
    pcVar15 = pcVar12;
    if ((0 < *(int *)(param_2 + 0x48)) && (0 < *(int *)(param_2 + 0x4c))) {
      pcVar15 = FUN_18001d4a0(DAT_1800797f0,*(int *)(param_2 + 0x48),*(int *)(param_2 + 0x4c));
    }
    break;
  case 0x5a:
    pcVar9 = FUN_180042320(param_1,(void *)0x0,local_528,1,0);
    *param_3 = *param_3 + 1;
    goto LAB_18004456f;
  case 0x60:
    pcVar15 = pcVar12;
    if ((0 < *(int *)(param_2 + 0x48)) && (0 < *(int *)(param_2 + 0x4c))) {
      pcVar15 = FUN_18003e780(*(longlong *)(param_2 + 0x28),*(int *)(param_2 + 0x48),
                              *(int *)(param_2 + 0x4c));
    }
LAB_180044106:
    pcVar9 = (char *)0x0;
    break;
  case 0x61:
    pcVar9 = *(char **)(param_2 + 0x50);
    pcVar15 = pcVar12;
    if (((pcVar9 == (char *)0x0) || (pcVar15 = pcVar9, *pcVar9 != '-')) || (pcVar9[1] != '\0'))
    goto LAB_180044106;
    pcVar9 = (char *)0x0;
    pcVar15 = pcVar12;
    break;
  case 0x62:
    lVar1 = *(longlong *)(param_2 + 0x28);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4d0,"");
    pcVar15 = *(char **)(param_2 + 0x50);
    if ((pcVar15 != (char *)0x0) && ((*pcVar15 != '-' || (pcVar15[1] != '\0')))) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4d0,pcVar15
                );
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4d0,' ');
    if ((0 < *(int *)(param_2 + 0x48)) || (*(int *)(param_2 + 0x4c) < 1)) {
      pcVar15 = FUN_18003e780(lVar1,*(int *)(param_2 + 0x48),*(int *)(param_2 + 0x4c));
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4d0,pcVar15
                );
    }
    pcVar9 = FUN_180042410(param_1,(void *)0x0,local_528,local_4d0);
    *param_3 = *param_3 + 1;
    pCVar7 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4d0;
LAB_180044569:
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar7);
    goto LAB_18004456f;
  }
  pcVar9 = FUN_180042410(param_1,pcVar9,local_528,pcVar15);
  *param_3 = *param_3 + 1;
LAB_18004456f:
  if (0 < local_528[0]) {
    pcVar9[(longlong)local_528[0] + -1] = '\0';
  }
  return pcVar9;
}

/* ---- FUNC 00044670 FUN_180044670 (663 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void * FUN_180044670(longlong param_1,void *param_2,int *param_3,longlong param_4)

{
  ulonglong uVar1;
  longlong *plVar2;
  longlong lVar3;
  char *_Memory;
  int iVar4;
  ulonglong uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  longlong lVar9;
  undefined1 auStackY_4a8 [32];
  int local_470;
  int local_46c;
  undefined4 local_468;
  int *local_460;
  longlong local_458;
  undefined1 local_448 [1008];
  ulonglong local_58;
  
  local_58 = DAT_180077818 ^ (ulonglong)auStackY_4a8;
  local_468 = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(param_1 + 0x80) = 1;
  lVar9 = 0;
  uVar1 = *(ulonglong *)(param_4 + 0x60);
  uVar5 = 0;
  iVar6 = -1;
  iVar7 = -1;
  if (uVar1 != 0) {
    do {
      local_460 = param_3;
      local_458 = param_4;
      if (((longlong)uVar5 < 0) || ((longlong)uVar1 <= (longlong)uVar5)) goto LAB_180044902;
      plVar2 = *(longlong **)(*(longlong *)(*(longlong *)(param_4 + 0x58) + uVar5 * 8) + 0x38);
      if (plVar2 != (longlong *)0x0) {
        if (((lVar9 == 0) && (-1 < (int)plVar2[1])) && (-1 < *(int *)((longlong)plVar2 + 0xc))) {
          lVar9 = *plVar2;
          iVar7 = *(int *)((longlong)plVar2 + 0xc);
          iVar6 = (int)plVar2[1];
        }
        else if (((*plVar2 == lVar9) && (iVar4 = (int)plVar2[1], -1 < iVar4)) &&
                (iVar8 = *(int *)((longlong)plVar2 + 0xc), -1 < iVar8)) {
          if (iVar6 <= iVar4) {
            iVar4 = iVar6;
          }
          iVar6 = iVar4;
          if (iVar8 < iVar7) {
            iVar7 = iVar8;
          }
        }
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
    uVar5 = 0;
    local_46c = iVar7;
    iVar4 = iVar7;
    do {
      if (((longlong)uVar5 < 0) || (*(longlong *)(param_4 + 0x60) <= (longlong)uVar5)) {
LAB_180044902:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      lVar3 = *(longlong *)(*(longlong *)(param_4 + 0x58) + uVar5 * 8);
      plVar2 = *(longlong **)(lVar3 + 0x38);
      if ((((plVar2 != (longlong *)0x0) && (*plVar2 == lVar9)) && (-1 < (int)plVar2[1])) &&
         (iVar8 = *(int *)((longlong)plVar2 + 0xc), param_4 = local_458, -1 < iVar8)) {
        if (iVar6 < (int)plVar2[1]) {
          if (0 < *param_3) {
            *(undefined1 *)((longlong)*param_3 + -1 + (longlong)param_2) = 10;
            iVar8 = *(int *)((longlong)plVar2 + 0xc);
          }
          iVar6 = (int)plVar2[1];
          iVar7 = iVar4;
        }
        if (iVar7 < iVar8) {
          param_2 = FUN_180042320(param_1,param_2,param_3,iVar8 - iVar7,0);
          iVar7 = *(int *)((longlong)plVar2 + 0xc);
        }
        _Memory = FUN_180043b90(param_1,lVar3,&local_470);
        if (1 < local_470) {
          FUN_180002a20(local_448,"Assert failed in file %s line %d",
                        "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnode_dataobj.cpp",0xe46);
          LogMessage(local_448,2,1);
        }
        if ((*_Memory == ' ') && (_Memory[1] == '\0')) {
          free(_Memory);
        }
        else if (_Memory != (char *)0x0) {
          param_2 = FUN_180042410(param_1,param_2,local_460,_Memory);
          free(_Memory);
          iVar7 = iVar7 + 1;
          param_4 = local_458;
          param_3 = local_460;
          iVar4 = local_46c;
          goto LAB_1800448b7;
        }
        param_2 = FUN_180042320(param_1,param_2,local_460,1,0);
        iVar7 = iVar7 + 1;
        param_4 = local_458;
        param_3 = local_460;
        iVar4 = local_46c;
      }
LAB_1800448b7:
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
  }
  *(undefined4 *)(param_1 + 0x80) = local_468;
  if (0 < *param_3) {
    *(undefined1 *)((longlong)*param_3 + -1 + (longlong)param_2) = 0;
  }
  return param_2;
}

/* ---- FUNC 00044910 FUN_180044910 (2438 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void * FUN_180044910(longlong param_1,void *param_2,int *param_3)

{
  uint *puVar1;
  char cVar2;
  longlong lVar3;
  longlong lVar4;
  code *pcVar5;
  ulonglong uVar6;
  longlong *plVar7;
  longlong *plVar8;
  char *pcVar9;
  void *pvVar10;
  longlong lVar11;
  longlong lVar12;
  longlong *plVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  uint uVar16;
  ulonglong uVar17;
  int *piVar19;
  int iVar20;
  ulonglong uVar21;
  uint uVar22;
  uint uVar23;
  longlong *plVar24;
  int iVar25;
  ulonglong uVar26;
  undefined1 auStackY_558 [32];
  uint local_528 [2];
  longlong local_520;
  ulonglong local_518;
  int *local_510;
  CPtrArray local_508 [8];
  longlong local_500;
  ulonglong local_4f8;
  longlong *local_4d8;
  undefined8 uStack_4d0;
  longlong local_4c8;
  undefined8 *local_4a8;
  undefined8 local_4a0;
  CPtrArray local_498 [8];
  longlong local_490;
  longlong local_488;
  CDWordArray local_468 [8];
  longlong local_460;
  longlong local_458;
  undefined1 local_438 [1008];
  ulonglong local_48;
  ulonglong uVar18;
  
  local_48 = DAT_180077818 ^ (ulonglong)auStackY_558;
  local_520 = param_1;
  local_510 = param_3;
  CPtrArray::CPtrArray(local_508);
  CPtrArray::Copy(local_508,(CPtrArray *)(*(longlong *)(param_1 + 0x78) + 0x50));
  uVar14 = local_4f8;
  uVar6 = FUN_180045570(param_1);
  plVar24 = DAT_180079c30;
  lVar12 = local_500;
  uVar18 = local_4f8;
  if ((char)uVar6 == '\0') {
    cVar2 = *(char *)(DAT_180079c30[1] + 0x19);
    plVar7 = (longlong *)DAT_180079c30[1];
    uVar14 = local_4f8;
    while (local_518 = uVar14, cVar2 == '\0') {
      FUN_180041b90(&DAT_180079c30,&DAT_180079c30,(longlong *)plVar7[2]);
      plVar8 = (longlong *)*plVar7;
      FUN_180025ad0(plVar7);
      plVar7 = plVar8;
      param_1 = local_520;
      uVar14 = local_518;
      cVar2 = *(char *)((longlong)plVar8 + 0x19);
    }
    plVar24[1] = (longlong)plVar24;
    *plVar24 = (longlong)plVar24;
    plVar24[2] = (longlong)plVar24;
    uVar6 = 0;
    DAT_180079c38 = 0;
    uVar18 = uVar14;
    if (uVar14 != 0) {
      uVar15 = 0;
      uVar21 = uVar15;
      uVar26 = uVar6;
      do {
        plVar24 = DAT_180079c30;
        if (((longlong)uVar21 < 0) || ((longlong)local_4f8 <= (longlong)uVar21)) goto LAB_180045291;
        uVar18 = *(ulonglong *)(local_500 + uVar21 * 8);
        if ((uVar18 != 0) && (lVar12 = *(longlong *)(uVar18 + 0x38), lVar12 != 0)) {
          plVar7 = (longlong *)DAT_180079c30[1];
          uStack_4d0 = uStack_4d0 & 0xffffffff00000000;
          cVar2 = *(char *)((longlong)plVar7 + 0x19);
          local_4d8 = plVar7;
          plVar8 = DAT_180079c30;
          while (plVar13 = plVar7, cVar2 == '\0') {
            uStack_4d0._4_4_ = (uint)(uStack_4d0 >> 0x20);
            if ((ulonglong)plVar13[4] < uVar18) {
              uStack_4d0 = (ulonglong)uStack_4d0._4_4_ << 0x20;
              plVar7 = (longlong *)plVar13[2];
            }
            else {
              uStack_4d0 = CONCAT44(uStack_4d0._4_4_,1);
              plVar7 = (longlong *)*plVar13;
              plVar8 = plVar13;
            }
            cVar2 = *(char *)((longlong)plVar7 + 0x19);
            local_4d8 = plVar13;
          }
          if ((*(char *)((longlong)plVar8 + 0x19) != '\0') || (uVar18 < (ulonglong)plVar8[4])) {
            if (uVar6 == 0x555555555555555) {
              FUN_18003f2b0();
              pcVar5 = (code *)swi(3);
              pvVar10 = (void *)(*pcVar5)();
              return pvVar10;
            }
            local_4a8 = &DAT_180079c30;
            local_4a0 = 0;
            plVar7 = operator_new(0x30);
            plVar7[4] = uVar18;
            *(undefined4 *)(plVar7 + 5) = 0;
            *plVar7 = (longlong)plVar24;
            plVar7[1] = (longlong)plVar24;
            plVar7[2] = (longlong)plVar24;
            *(undefined2 *)(plVar7 + 3) = 0;
            local_4a0 = 0;
            plVar8 = FUN_18003ef90((longlong *)&DAT_180079c30,(longlong *)&local_4d8,plVar7);
            uVar14 = local_518;
          }
          *(undefined4 *)(plVar8 + 5) = *(undefined4 *)(lVar12 + 0x18);
          uVar6 = DAT_180079c38;
        }
        uVar18 = local_518;
        uVar22 = (int)uVar26 + 1;
        uVar26 = (ulonglong)uVar22;
        uVar21 = uVar21 + 1;
        uVar17 = uVar15;
      } while ((ulonglong)(longlong)(int)uVar22 < uVar14);
      do {
        uVar22 = (uint)uVar17;
        if (((longlong)uVar15 < 0) || ((longlong)local_4f8 <= (longlong)uVar15)) goto LAB_180045291;
        lVar12 = *(longlong *)(local_500 + uVar15 * 8);
        if ((lVar12 != 0) &&
           (plVar24 = *(longlong **)(lVar12 + 0x38), iVar25 = 0, plVar24 != (longlong *)0x0)) {
          while( true ) {
            uVar14 = uVar15;
            uVar16 = (uint)uVar17;
            uVar22 = uVar16 + 1;
            uVar17 = (ulonglong)uVar22;
            uVar6 = uVar14 + 1;
            uVar15 = uVar6;
            if (uVar18 <= (ulonglong)(longlong)(int)uVar22) break;
            if (((longlong)uVar6 < 0) || ((longlong)local_4f8 <= (longlong)uVar6))
            goto LAB_180045291;
            lVar12 = *(longlong *)(local_500 + uVar6 * 8);
            if (lVar12 != 0) {
              plVar7 = *(longlong **)(lVar12 + 0x38);
              uVar15 = uVar14;
              uVar22 = uVar16;
              if ((plVar7 == (longlong *)0x0) || (*plVar7 != *plVar24)) break;
              if ((int)plVar7[3] < (int)plVar24[3]) {
                FUN_180002a20(local_438,"Assert failed in file %s line %d",
                              "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnode_dataobj.cpp",0x905);
                LogMessage(local_438,2,1);
              }
              iVar20 = iVar25 + 1;
              if ((int)plVar7[3] <= (int)plVar24[3]) {
                iVar20 = iVar25;
              }
              *(int *)(plVar24 + 3) = iVar25;
              uVar15 = uVar6;
              plVar24 = plVar7;
              iVar25 = iVar20;
            }
          }
          *(int *)(plVar24 + 3) = iVar25;
        }
        uVar15 = uVar15 + 1;
        uVar17 = (ulonglong)(uVar22 + 1);
        param_1 = local_520;
      } while ((ulonglong)(longlong)(int)(uVar22 + 1) < uVar18);
    }
    uVar6 = 0;
    CPtrArray::CPtrArray(local_498);
    CDWordArray::CDWordArray(local_468);
    CPtrArray::SetSize(local_498,uVar18,-1);
    CDWordArray::SetSize(local_468,uVar18,-1);
    uVar14 = uVar6;
    if (uVar18 != 0) {
      do {
        if (((longlong)uVar6 < 0) || ((longlong)local_4f8 <= (longlong)uVar6)) goto LAB_180045285;
        lVar12 = *(longlong *)(local_500 + uVar6 * 8);
        uVar22 = *(uint *)(param_1 + 0x80);
        uVar16 = (uint)uVar14;
        if ((uVar22 & 2) == 0) {
LAB_180044de5:
          if (0x7fffffff < uVar16) goto LAB_180044dea;
        }
        else {
          if (-1 < (int)uVar16) {
            plVar24 = *(longlong **)(lVar12 + 0x38);
            uVar15 = uVar6;
            uVar23 = uVar16;
            if (plVar24 != (longlong *)0x0) {
              while ((ulonglong)(longlong)(int)uVar23 < uVar18) {
                if (((longlong)uVar15 < 0) || ((longlong)local_4f8 <= (longlong)uVar15))
                goto LAB_180045285;
                plVar7 = *(longlong **)(*(longlong *)(local_500 + uVar15 * 8) + 0x38);
                if ((plVar7 == (longlong *)0x0) || (*plVar7 != *plVar24)) break;
                uVar23 = (int)uVar14 + 1;
                uVar14 = (ulonglong)uVar23;
                uVar15 = uVar15 + 1;
              }
            }
            goto LAB_180044de5;
          }
LAB_180044dea:
          *(uint *)(param_1 + 0x80) = uVar22 & 0xfffffffd;
        }
        pcVar9 = FUN_180043b90(param_1,lVar12,(int *)local_528);
        if ((local_488 <= (longlong)uVar6) ||
           (*(char **)(local_490 + uVar6 * 8) = pcVar9, local_458 <= (longlong)uVar6))
        goto LAB_180045285;
        *(uint *)(local_460 + uVar6 * 4) = local_528[0];
        *(uint *)(param_1 + 0x80) = uVar22;
        uVar14 = (ulonglong)(uVar16 + 1);
        uVar6 = uVar6 + 1;
      } while ((ulonglong)(longlong)(int)(uVar16 + 1) < uVar18);
      uVar18 = 0;
      local_528[0] = 0;
      piVar19 = local_510;
      uVar14 = uVar18;
      do {
        uVar22 = (uint)uVar18;
        if (((longlong)uVar14 < 0) || ((longlong)local_4f8 <= (longlong)uVar14)) goto LAB_180045285;
        plVar24 = *(longlong **)(*(longlong *)(local_500 + uVar14 * 8) + 0x38);
        if (plVar24 == (longlong *)0x0) {
          if (local_488 <= (longlong)uVar14) goto LAB_180045285;
          param_2 = FUN_180042410(local_520,param_2,piVar19,*(char **)(local_490 + uVar14 * 8));
        }
        else {
          CDWordArray::CDWordArray((CDWordArray *)&local_4d8);
          lVar12 = local_4c8;
          uVar6 = uVar14;
          uVar15 = local_518;
          uVar16 = uVar22;
          if ((ulonglong)(longlong)(int)uVar22 < local_518) {
            do {
              uVar16 = (uint)uVar18;
              if (((longlong)uVar6 < 0) || ((longlong)local_4f8 <= (longlong)uVar6))
              goto LAB_18004527f;
              plVar7 = *(longlong **)(*(longlong *)(local_500 + uVar6 * 8) + 0x38);
              if ((plVar7 == (longlong *)0x0) || (*plVar7 != *plVar24)) break;
              if (lVar12 <= *(int *)((longlong)plVar7 + 0x14)) {
                CDWordArray::SetSize
                          ((CDWordArray *)&local_4d8,
                           (longlong)(*(int *)((longlong)plVar7 + 0x14) + 1),-1);
                lVar12 = local_4c8;
                uVar15 = local_518;
              }
              lVar11 = (longlong)*(int *)((longlong)plVar7 + 0x14);
              if (((lVar11 < 0) || (lVar12 <= lVar11)) ||
                 (puVar1 = (uint *)(uStack_4d0 + lVar11 * 4), local_458 <= (longlong)uVar6))
              goto LAB_18004527f;
              uVar23 = *(uint *)(local_460 + uVar6 * 4);
              if (*puVar1 < uVar23) {
                if (lVar12 <= lVar11) goto LAB_18004527f;
                *puVar1 = uVar23;
                lVar12 = local_4c8;
              }
              uVar16 = uVar16 + 1;
              uVar18 = (ulonglong)uVar16;
              uVar6 = uVar6 + 1;
            } while ((ulonglong)(longlong)(int)uVar16 < uVar15);
          }
          iVar20 = 0;
          lVar11 = 0;
          iVar25 = 0;
          local_4a8 = (undefined8 *)(longlong)(int)uVar16;
          piVar19 = local_510;
          if ((longlong)uVar14 < (longlong)local_4a8) {
            do {
              piVar19 = local_510;
              if (((longlong)uVar14 < 0) || ((longlong)local_4f8 <= (longlong)uVar14)) {
LAB_18004527f:
                    /* WARNING: Subroutine does not return */
                AfxThrowInvalidArgException();
              }
              lVar3 = *(longlong *)(local_500 + uVar14 * 8);
              lVar4 = *(longlong *)(lVar3 + 0x38);
              if (iVar25 < *(int *)(lVar4 + 0x18)) {
                if (iVar20 < lVar12) {
                  do {
                    if (*(int *)(lVar3 + 0x30) != 2) {
                      if ((lVar11 < 0) || (lVar12 <= lVar11)) goto LAB_18004527f;
                      param_2 = FUN_180042320(local_520,param_2,piVar19,
                                              *(int *)(uStack_4d0 + lVar11 * 4),1);
                      lVar12 = local_4c8;
                    }
                    iVar20 = iVar20 + 1;
                    lVar11 = lVar11 + 1;
                  } while (iVar20 < lVar12);
                }
                if (0 < *local_510) {
                  *(undefined1 *)((longlong)*local_510 + -1 + (longlong)param_2) = 10;
                  lVar12 = local_4c8;
                }
                iVar20 = 0;
                lVar11 = 0;
                iVar25 = *(int *)(lVar4 + 0x18);
              }
              piVar19 = local_510;
              if (iVar20 < *(int *)(lVar4 + 0x14)) {
                do {
                  if ((lVar11 < 0) || (lVar12 <= lVar11)) goto LAB_18004527f;
                  param_2 = FUN_180042320(local_520,param_2,piVar19,
                                          *(int *)(uStack_4d0 + lVar11 * 4),1);
                  iVar20 = iVar20 + 1;
                  lVar11 = lVar11 + 1;
                  lVar12 = local_4c8;
                } while (iVar20 < *(int *)(lVar4 + 0x14));
              }
              if (local_488 <= (longlong)uVar14) goto LAB_18004527f;
              param_2 = FUN_180042410(local_520,param_2,piVar19,*(char **)(local_490 + uVar14 * 8));
              iVar20 = iVar20 + 1;
              lVar11 = lVar11 + 1;
              lVar12 = (longlong)*(int *)(lVar4 + 0x14);
              if (((lVar12 < 0) || (local_4c8 <= lVar12)) || (local_458 <= (longlong)uVar14))
              goto LAB_18004527f;
              uVar22 = *(uint *)(local_460 + uVar14 * 4);
              uVar16 = *(uint *)(uStack_4d0 + lVar12 * 4);
              if (uVar22 < uVar16) {
                if (local_4c8 <= lVar12) goto LAB_18004527f;
                param_2 = FUN_180042320(local_520,param_2,piVar19,uVar16 - uVar22,1);
              }
              uVar22 = local_528[0] + 1;
              uVar14 = uVar14 + 1;
              lVar12 = local_4c8;
              local_528[0] = uVar22;
            } while ((longlong)uVar14 < (longlong)local_4a8);
          }
          CDWordArray::~CDWordArray((CDWordArray *)&local_4d8);
        }
        if (0 < *piVar19) {
          *(undefined1 *)((longlong)*piVar19 + -1 + (longlong)param_2) = 10;
        }
        local_528[0] = uVar22 + 1;
        uVar18 = (ulonglong)local_528[0];
        uVar14 = uVar14 + 1;
      } while ((ulonglong)(longlong)(int)local_528[0] < local_518);
      uVar6 = 0;
      uVar14 = uVar6;
      uVar18 = uVar6;
      do {
        if (((longlong)uVar14 < 0) || (local_488 <= (longlong)uVar14)) goto LAB_180045285;
        pvVar10 = *(void **)(local_490 + uVar14 * 8);
        if (pvVar10 != (void *)0x0) {
          free(pvVar10);
        }
        uVar22 = (int)uVar18 + 1;
        uVar18 = (ulonglong)uVar22;
        uVar14 = uVar14 + 1;
        uVar15 = uVar6;
        plVar24 = DAT_180079c30;
      } while ((ulonglong)(longlong)(int)uVar22 < local_518);
      do {
        if (((longlong)uVar15 < 0) || ((longlong)local_4f8 <= (longlong)uVar15)) {
LAB_180045285:
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        uVar14 = *(ulonglong *)(local_500 + uVar15 * 8);
        if ((uVar14 != 0) && (*(longlong *)(uVar14 + 0x38) != 0)) {
          cVar2 = *(char *)(plVar24[1] + 0x19);
          plVar7 = (longlong *)plVar24[1];
          plVar8 = plVar24;
          while (plVar13 = plVar7, cVar2 == '\0') {
            if ((ulonglong)plVar13[4] < uVar14) {
              plVar7 = (longlong *)plVar13[2];
              plVar13 = plVar8;
            }
            else {
              plVar7 = (longlong *)*plVar13;
            }
            cVar2 = *(char *)((longlong)plVar7 + 0x19);
            plVar8 = plVar13;
          }
          if (((*(char *)((longlong)plVar8 + 0x19) == '\0') && ((ulonglong)plVar8[4] <= uVar14)) &&
             (plVar8 != plVar24)) {
            *(int *)(*(longlong *)(uVar14 + 0x38) + 0x18) = (int)plVar8[5];
            plVar24 = DAT_180079c30;
          }
        }
        uVar22 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar22;
        uVar15 = uVar15 + 1;
      } while ((ulonglong)(longlong)(int)uVar22 < local_518);
    }
    CDWordArray::~CDWordArray(local_468);
    CPtrArray::~CPtrArray(local_498);
    CPtrArray::~CPtrArray(local_508);
    return param_2;
  }
LAB_180044991:
  do {
    uVar14 = uVar14 - 1;
    uVar6 = 0;
    if (((longlong)uVar14 < 0) || ((longlong)uVar18 <= (longlong)uVar14)) {
LAB_180045291:
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
    lVar11 = *(longlong *)(lVar12 + uVar14 * 8);
  } while ((lVar11 == 0) ||
          ((lVar3 = *(longlong *)(lVar11 + 0x38), lVar3 == 0 || (*(int *)(lVar3 + 8) != -1))));
  uVar22 = *(uint *)(lVar11 + 0x30);
  if (uVar22 != 0x5a) goto code_r0x0001800449d0;
  goto LAB_180044a3d;
code_r0x0001800449d0:
  if ((uVar22 & 0xfffffffd) == 0) {
    if (((*(int *)(lVar3 + 0xc) != -1) || (uVar22 != 2)) && (uVar15 = uVar6, uVar14 != 0)) {
      do {
        if (((longlong)uVar6 < 0) || ((longlong)uVar18 <= (longlong)uVar6)) goto LAB_180045291;
        lVar11 = *(longlong *)(lVar12 + uVar6 * 8);
        if (((lVar11 != 0) && (lVar11 = *(longlong *)(lVar11 + 0x38), lVar11 != 0)) &&
           ((*(int *)(lVar11 + 0xc) == *(int *)(lVar3 + 0xc) &&
            ((*(int *)(lVar11 + 8) == -1 && (*(int *)(lVar11 + 0x18) <= *(int *)(lVar3 + 0x18)))))))
        goto LAB_180044991;
        uVar22 = (int)uVar15 + 1;
        uVar15 = (ulonglong)uVar22;
        uVar6 = uVar6 + 1;
      } while ((ulonglong)(longlong)(int)uVar22 < uVar14);
    }
LAB_180044a3d:
    CPtrArray::RemoveAt(local_508,uVar14,1);
    lVar12 = local_500;
    uVar18 = local_4f8;
  }
  goto LAB_180044991;
}

/* ---- FUNC 000452A0 FUN_1800452a0 (34 bytes) ---- */

uint FUN_1800452a0(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_180079800 + 0x138))();
  return -(uint)(iVar1 != 0) & 0x80004005;
}

/* ---- FUNC 000452D0 FUN_1800452d0 (75 bytes) ---- */

LPVOID FUN_1800452d0(uint *param_1)

{
  LPVOID _Dst;
  
  if (param_1 != (uint *)0x0) {
    _Dst = CoTaskMemAlloc((ulonglong)*param_1);
    if (_Dst != (LPVOID)0x0) {
      memcpy(_Dst,param_1,(ulonglong)*param_1);
      return _Dst;
    }
  }
  return (LPVOID)0x0;
}

/* ---- FUNC 00045320 FUN_180045320 (132 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180045320(longlong param_1)

{
  char cVar1;
  BOOL BVar2;
  char *pcVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  void *pvVar6;
  char *pcVar7;
  HDC hdc;
  char *pcVar8;
  __uint64 _Var9;
  undefined1 auStack_438 [32];
  int local_418 [2];
  tagSIZE local_410;
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_180077818 ^ (ulonglong)auStack_438;
  pvVar6 = (void *)0x0;
  local_418[0] = 0;
  if (*(int *)(param_1 + 0x88) == 0) {
    if (*(int *)(param_1 + 0x84) == 0) {
      FUN_180002a20(local_408,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnode_dataobj.cpp",0x7ef);
      LogMessage(local_408,2,1);
    }
    if (((*(byte *)(param_1 + 0x80) & 0xe) == 0) &&
       (uVar5 = FUN_180045570(param_1), (char)uVar5 != '\0')) {
      pvVar6 = (void *)FUN_180043200(param_1,0,local_418);
    }
    pcVar3 = FUN_180044910(param_1,pvVar6,local_418);
    uVar4 = 0;
    if (pcVar3 != (char *)0x0) {
      _Var9 = (__uint64)local_418[0];
      pcVar3[_Var9 - 1] = '\0';
      if (*(void **)(param_1 + 0x58) != (void *)0x0) {
        FUN_180025ad0(*(void **)(param_1 + 0x58));
      }
      pcVar7 = operator_new__(_Var9);
      *(char **)(param_1 + 0x58) = pcVar7;
      pcVar8 = pcVar3;
      do {
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        *pcVar7 = cVar1;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      hdc = CreateDCA("DISPLAY",(LPCSTR)0x0,(LPCSTR)0x0,(DEVMODEA *)0x0);
      SetMapMode(hdc,3);
      *(undefined8 *)(param_1 + 0x60) = 0;
      cVar1 = *pcVar3;
      pcVar7 = pcVar3;
      pcVar8 = pcVar3;
      while( true ) {
        if (cVar1 == '\0') break;
        if (*pcVar7 == '\n') {
          BVar2 = GetTextExtentPoint32A(hdc,pcVar8,(int)pcVar7 - (int)pcVar8,&local_410);
          if (BVar2 != 0) {
            if (*(int *)(param_1 + 0x60) < local_410.cx) {
              *(LONG *)(param_1 + 0x60) = local_410.cx;
            }
            *(int *)(param_1 + 100) = *(int *)(param_1 + 100) + local_410.cy;
          }
          pcVar8 = pcVar7 + 1;
        }
        pcVar7 = pcVar7 + 1;
        cVar1 = *pcVar7;
      }
      BVar2 = GetTextExtentPoint32A(hdc,pcVar8,(int)pcVar7 - (int)pcVar8,&local_410);
      if (BVar2 != 0) {
        if (*(int *)(param_1 + 0x60) < local_410.cx) {
          *(LONG *)(param_1 + 0x60) = local_410.cx;
        }
        *(int *)(param_1 + 100) = *(int *)(param_1 + 100) + local_410.cy;
      }
      DeleteDC(hdc);
      free(pcVar3);
      uVar4 = 1;
    }
  }
  else {
    if (*(void **)(param_1 + 0x58) != (void *)0x0) {
      FUN_180025ad0(*(void **)(param_1 + 0x58));
    }
    pcVar3 = operator_new__(0x17);
    *(char **)(param_1 + 0x58) = pcVar3;
    uVar4 = s_Unable_to_resolve_link_180065fe0._8_8_;
    *(undefined8 *)pcVar3 = s_Unable_to_resolve_link_180065fe0._0_8_;
    *(undefined8 *)(pcVar3 + 8) = uVar4;
    *(undefined4 *)(pcVar3 + 0x10) = s_Unable_to_resolve_link_180065fe0._16_4_;
    *(undefined2 *)(pcVar3 + 0x14) = s_Unable_to_resolve_link_180065fe0._20_2_;
    pcVar3[0x16] = s_Unable_to_resolve_link_180065fe0[0x16];
    uVar4 = 1;
  }
  return uVar4;
}

/* ---- FUNC 000453A4 FUN_1800453a4 (146 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1800453a4(longlong param_1)

{
  char cVar1;
  BOOL BVar2;
  ulonglong uVar3;
  char *_Memory;
  char *pcVar4;
  HDC hdc;
  undefined8 uVar5;
  char *pcVar6;
  longlong unaff_RBX;
  void *unaff_RDI;
  int aiStackX_20 [2];
  int iStack0000000000000028;
  int iStack000000000000002c;
  
  if (*(int *)(param_1 + 0x84) == (int)unaff_RDI) {
    FUN_180002a20(&stack0x00000030,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnode_dataobj.cpp",0x7ef);
    LogMessage(&stack0x00000030,2,1);
  }
  if (((*(byte *)(unaff_RBX + 0x80) & 0xe) == 0) &&
     (uVar3 = FUN_180045570(unaff_RBX), (char)uVar3 != '\0')) {
    unaff_RDI = (void *)FUN_180043200(unaff_RBX,0,aiStackX_20);
  }
  _Memory = FUN_180044910(unaff_RBX,unaff_RDI,aiStackX_20);
  uVar5 = 0;
  if (_Memory != (char *)0x0) {
    _Memory[(longlong)aiStackX_20[0] - 1] = '\0';
    if (*(void **)(unaff_RBX + 0x58) != (void *)0x0) {
      FUN_180025ad0(*(void **)(unaff_RBX + 0x58));
    }
    pcVar4 = operator_new__((longlong)aiStackX_20[0]);
    *(char **)(unaff_RBX + 0x58) = pcVar4;
    pcVar6 = _Memory;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      *pcVar4 = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    hdc = CreateDCA("DISPLAY",(LPCSTR)0x0,(LPCSTR)0x0,(DEVMODEA *)0x0);
    SetMapMode(hdc,3);
    *(undefined8 *)(unaff_RBX + 0x60) = 0;
    cVar1 = *_Memory;
    pcVar4 = _Memory;
    pcVar6 = _Memory;
    while( true ) {
      if (cVar1 == '\0') break;
      if (*pcVar4 == '\n') {
        BVar2 = GetTextExtentPoint32A(hdc,pcVar6,(int)pcVar4 - (int)pcVar6,(LPSIZE)&stack0x00000028)
        ;
        if (BVar2 != 0) {
          if (*(int *)(unaff_RBX + 0x60) < iStack0000000000000028) {
            *(int *)(unaff_RBX + 0x60) = iStack0000000000000028;
          }
          *(int *)(unaff_RBX + 100) = *(int *)(unaff_RBX + 100) + iStack000000000000002c;
        }
        pcVar6 = pcVar4 + 1;
      }
      pcVar4 = pcVar4 + 1;
      cVar1 = *pcVar4;
    }
    BVar2 = GetTextExtentPoint32A(hdc,pcVar6,(int)pcVar4 - (int)pcVar6,(LPSIZE)&stack0x00000028);
    if (BVar2 != 0) {
      if (*(int *)(unaff_RBX + 0x60) < iStack0000000000000028) {
        *(int *)(unaff_RBX + 0x60) = iStack0000000000000028;
      }
      *(int *)(unaff_RBX + 100) = *(int *)(unaff_RBX + 100) + iStack000000000000002c;
    }
    DeleteDC(hdc);
    free(_Memory);
    uVar5 = 1;
  }
  return uVar5;
}

/* ---- FUNC 00045436 FUN_180045436 (273 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180045436(void)

{
  char cVar1;
  BOOL BVar2;
  longlong in_RAX;
  char *pcVar3;
  HDC hdc;
  char *pcVar4;
  longlong unaff_RBX;
  char *unaff_RBP;
  __uint64 unaff_RDI;
  int iStack0000000000000028;
  int iStack000000000000002c;
  
  *(undefined1 *)((unaff_RDI - 1) + in_RAX) = 0;
  if (*(void **)(unaff_RBX + 0x58) != (void *)0x0) {
    FUN_180025ad0(*(void **)(unaff_RBX + 0x58));
  }
  pcVar3 = operator_new__(unaff_RDI);
  *(char **)(unaff_RBX + 0x58) = pcVar3;
  pcVar4 = unaff_RBP;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    *pcVar3 = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  hdc = CreateDCA("DISPLAY",(LPCSTR)0x0,(LPCSTR)0x0,(DEVMODEA *)0x0);
  SetMapMode(hdc,3);
  *(undefined8 *)(unaff_RBX + 0x60) = 0;
  cVar1 = *unaff_RBP;
  pcVar3 = unaff_RBP;
  pcVar4 = unaff_RBP;
  while( true ) {
    if (cVar1 == '\0') break;
    if (*pcVar3 == '\n') {
      BVar2 = GetTextExtentPoint32A(hdc,pcVar4,(int)pcVar3 - (int)pcVar4,(LPSIZE)&stack0x00000028);
      if (BVar2 != 0) {
        if (*(int *)(unaff_RBX + 0x60) < iStack0000000000000028) {
          *(int *)(unaff_RBX + 0x60) = iStack0000000000000028;
        }
        *(int *)(unaff_RBX + 100) = *(int *)(unaff_RBX + 100) + iStack000000000000002c;
      }
      pcVar4 = pcVar3 + 1;
    }
    pcVar3 = pcVar3 + 1;
    cVar1 = *pcVar3;
  }
  BVar2 = GetTextExtentPoint32A(hdc,pcVar4,(int)pcVar3 - (int)pcVar4,(LPSIZE)&stack0x00000028);
  if (BVar2 != 0) {
    if (*(int *)(unaff_RBX + 0x60) < iStack0000000000000028) {
      *(int *)(unaff_RBX + 0x60) = iStack0000000000000028;
    }
    *(int *)(unaff_RBX + 100) = *(int *)(unaff_RBX + 100) + iStack000000000000002c;
  }
  DeleteDC(hdc);
  free(unaff_RBP);
  return 1;
}

/* ---- FUNC 00045547 FUN_180045547 (8 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180045547(void)

{
  return;
}

/* ---- FUNC 0004554F FUN_18004554f (33 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18004554f(void)

{
  return;
}

/* ---- FUNC 00045570 FUN_180045570 (211 bytes) ---- */

ulonglong FUN_180045570(longlong param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong in_RAX;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  CPtrArray local_38 [8];
  longlong local_30;
  longlong local_28;
  
  uVar1 = *(ulonglong *)(*(longlong *)(param_1 + 0x78) + 0x60);
  uVar4 = 0;
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar4 < 0) || ((longlong)uVar1 <= (longlong)uVar4)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      lVar5 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x78) + 0x58) + uVar4 * 8);
      in_RAX = 0;
      if (((lVar5 != 0) && (in_RAX = *(ulonglong *)(lVar5 + 0x38), in_RAX != 0)) &&
         (*(int *)(in_RAX + 8) == -1)) {
        CPtrArray::CPtrArray(local_38);
        CPtrArray::Copy(local_38,(CPtrArray *)(*(longlong *)(param_1 + 0x78) + 0x50));
        lVar3 = local_28;
        lVar5 = local_28;
        while ((lVar5 = lVar5 + -1, -1 < lVar5 && (lVar5 < lVar3))) {
          lVar2 = *(longlong *)(local_30 + lVar5 * 8);
          if ((lVar2 != 0) &&
             ((lVar2 = *(longlong *)(lVar2 + 0x38), lVar2 != 0 && (*(int *)(lVar2 + 8) != -1)))) {
            CPtrArray::RemoveAt(local_38,lVar5,1);
            lVar3 = local_28;
          }
        }
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  return in_RAX & 0xffffffffffffff00;
}

/* ---- FUNC 00045650 FUN_180045650 (63 bytes) ---- */

undefined4 FUN_180045650(CEnumArray *param_1,void *param_2)

{
  int iVar1;
  LPVOID pvVar2;
  
  iVar1 = CEnumArray::OnNext(param_1,param_2);
  if (iVar1 == 0) {
    return 0;
  }
  if (*(uint **)((longlong)param_2 + 8) != (uint *)0x0) {
    pvVar2 = FUN_1800452d0(*(uint **)((longlong)param_2 + 8));
    *(LPVOID *)((longlong)param_2 + 8) = pvVar2;
    if (pvVar2 == (LPVOID)0x0) {
                    /* WARNING: Subroutine does not return */
      AfxThrowMemoryException();
    }
  }
  return 1;
}

/* ---- FUNC 00045690 FUN_180045690 (211 bytes) ---- */

ulonglong FUN_180045690(longlong param_1,ushort *param_2)

{
  uint *puVar1;
  bool bVar2;
  undefined7 extraout_var;
  uint uVar3;
  uint uVar4;
  
  if ((param_2[8] & 1) != 0) {
    uVar4 = (uint)*param_2;
    puVar1 = (uint *)(param_2 + 0xc);
    uVar3 = 0;
    if (uVar4 == 1) {
      uVar3 = *puVar1 & 1;
    }
    else if (uVar4 == 3) {
      uVar3 = *puVar1 & 0x20;
    }
    if ((uint)*param_2 == *(uint *)(param_1 + 0x18)) {
      uVar3 = *puVar1 & 1;
    }
    if (uVar4 == *(uint *)(param_1 + 0x28)) {
      uVar3 = *puVar1 & 1;
    }
    if (uVar4 == *(uint *)(param_1 + 0x2c)) {
      uVar3 = *puVar1 & 1;
    }
    if (uVar4 == *(uint *)(param_1 + 0x20)) {
      uVar3 = *puVar1 & 4;
    }
    else if (uVar4 == *(uint *)(param_1 + 0x24)) {
      uVar3 = *puVar1 & 1;
    }
    bVar2 = FUN_180042630(*(longlong *)(param_1 + 8));
    if ((int)CONCAT71(extraout_var,bVar2) != 0) {
      if ((uVar4 == *(uint *)(param_1 + 0x10)) && (*puVar1 == 4)) {
        uVar3 = 1;
      }
      if ((uVar4 == *(uint *)(param_1 + 0x14)) && (*puVar1 == 1)) {
        uVar3 = 1;
      }
    }
    return (ulonglong)(uVar3 == 0);
  }
  return 0x80040064;
}

/* ---- FUNC 00045770 FUN_180045770 (219 bytes) ---- */

undefined8 FUN_180045770(longlong *param_1,longlong *param_2,longlong *param_3)

{
  undefined8 uVar1;
  
  *param_3 = 0;
  if ((*param_2 == DAT_180066c58) && (param_2[1] == DAT_180066c60)) {
    *param_3 = (longlong)param_1;
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((*param_2 == DAT_180066d58) && (param_2[1] == DAT_180066d60)) {
    *param_3 = (longlong)(param_1 + 3);
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((*param_2 == DAT_180066db8) && (param_2[1] == DAT_180066dc0)) {
    *param_3 = (longlong)(param_1 + 1);
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((*param_2 == DAT_180066cd8) && (param_2[1] == DAT_180066ce0)) {
    *param_3 = (longlong)(param_1 + 9);
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((undefined8 *)param_1[0xe] != (undefined8 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00018004583e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)**(undefined8 **)param_1[0xe])();
    return uVar1;
  }
  return 0x80004002;
}

/* ---- FUNC 00045850 FUN_180045850 (14 bytes) ---- */

void FUN_180045850(longlong param_1)

{
  *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + -1;
                    /* WARNING: Could not recover jumptable at 0x00018004585a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(longlong **)(param_1 + 0x70) + 0x10))();
  return;
}

/* ---- FUNC 00045860 FUN_180045860 (38 bytes) ---- */

int FUN_180045860(longlong param_1,ulonglong param_2,undefined8 param_3,int param_4)

{
  longlong *plVar1;
  int iVar2;
  
  if ((param_2 & 1) == 0) {
    return 0;
  }
  plVar1 = *(longlong **)(*(longlong *)(param_1 + 8) + 0x78);
  if (*(int *)(*(longlong *)(param_1 + 8) + 0x84) == 0) {
    iVar2 = FUN_18003b0a0(plVar1,0);
    return iVar2;
  }
  iVar2 = FUN_180018e30((IUnknown *)plVar1[1],0,param_4);
  return iVar2;
}

/* ---- FUNC 00045890 FUN_180045890 (2250 bytes) ---- */

ulonglong FUN_180045890(longlong param_1,undefined4 *param_2,char param_3)

{
  longlong lVar1;
  IUnknown *pIVar2;
  IUnknown *pIVar3;
  HRESULT HVar4;
  int iVar5;
  ULONG UVar6;
  wchar_t *pwVar7;
  HGLOBAL hMem;
  LPSTR lpMultiByteStr;
  IUnknown *pIVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  longlong lVar11;
  uint uVar12;
  ulonglong uVar13;
  longlong lVar14;
  wchar_t *local_res8;
  undefined4 *local_res10;
  IBindCtx *local_res20;
  longlong *local_e8;
  IUnknown *local_e0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_d8 [8];
  wchar_t *local_d0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_c8 [8];
  VARIANTARG local_c0;
  longlong **local_a8;
  wchar_t *local_a0;
  undefined4 local_98;
  CPtrArray local_90 [8];
  longlong local_88;
  longlong local_80;
  longlong **local_68;
  wchar_t *local_60;
  undefined4 local_58;
  longlong **local_50;
  wchar_t *local_48;
  undefined4 local_40;
  
  local_res10 = param_2;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_c8);
  CreateBindCtx(0,&local_res20);
  (**(code **)(**(longlong **)(param_1 + 0xa8) + 0xa0))
            (*(longlong **)(param_1 + 0xa8),local_res20,0,&local_res8);
  (*local_res20->lpVtbl->Release)(local_res20);
  pwVar7 = wcschr(local_res8,L'!');
  uVar10 = 0;
  if (pwVar7 != (wchar_t *)0x0) {
    *pwVar7 = L'\0';
  }
  lVar14 = -1;
  HVar4 = CoCreateInstance((IID *)&DAT_180065d98,(LPUNKNOWN)0x0,3,(IID *)&DAT_180065d88,&local_e8);
  if (param_3 == '\0') {
    if ((-1 < HVar4) &&
       (iVar5 = (**(code **)*local_e8)(local_e8,&DAT_180065d78,&local_e0), pIVar8 = local_e0,
       -1 < iVar5)) {
      local_a8 = &local_e8;
      local_a0 = L"SelectionFile";
      local_98 = 0xd;
      UVar6 = (*local_e0->lpVtbl[2].Release)(local_e0);
      if ((int)UVar6 < 0) {
        _com_issue_errorex(UVar6,pIVar8,(_GUID *)&DAT_180065d78);
      }
      pIVar8 = local_e0;
      UVar6 = (*local_e0->lpVtbl[2].Release)(local_e0);
      pIVar2 = local_e0;
      if ((((int)UVar6 < 0) ||
          (UVar6 = (*local_e0->lpVtbl[3].AddRef)(local_e0), pIVar3 = local_e0, pIVar8 = pIVar2,
          (int)UVar6 < 0)) ||
         (UVar6 = (*local_e0->lpVtbl[3].QueryInterface)(local_e0,(IID *)&DAT_1800648c0,(void **)0x0)
         , pIVar8 = pIVar3, (int)UVar6 < 0)) {
        _com_issue_errorex(UVar6,pIVar8,(_GUID *)&DAT_180065d78);
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_d8,(char *)recprver_exref)
      ;
      pwVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::AllocSysString
                         (local_d8);
      local_d0 = pwVar7;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_d8);
      FUN_180046e90((longlong)&local_e8,0x180065f70,(longlong)pwVar7);
      SysFreeString(pwVar7);
      FUN_180046e90((longlong)&local_e8,0x180065f80,(longlong)local_res8);
      CoTaskMemFree(local_res8);
      pIVar8 = local_e0;
      HVar4 = (*local_e0->lpVtbl[3].QueryInterface)(local_e0,(IID *)&DAT_1800648c0,(void **)0x0);
      if (HVar4 < 0) {
        _com_issue_errorex(HVar4,pIVar8,(_GUID *)&DAT_180065d78);
      }
      goto LAB_18004602c;
    }
  }
  else if ((-1 < HVar4) &&
          (iVar5 = (**(code **)*local_e8)(local_e8,&DAT_180065d78,&local_e0), pIVar8 = local_e0,
          -1 < iVar5)) {
    local_a8 = &local_e8;
    local_a0 = L"Selection";
    local_98 = 9;
    UVar6 = (*local_e0->lpVtbl[2].Release)(local_e0);
    if ((int)UVar6 < 0) {
      _com_issue_errorex(UVar6,pIVar8,(_GUID *)&DAT_180065d78);
    }
    pIVar8 = local_e0;
    UVar6 = (*local_e0->lpVtbl[2].Release)(local_e0);
    pIVar2 = local_e0;
    if ((((int)UVar6 < 0) ||
        (UVar6 = (*local_e0->lpVtbl[3].AddRef)(local_e0), pIVar3 = local_e0, pIVar8 = pIVar2,
        (int)UVar6 < 0)) ||
       (UVar6 = (*local_e0->lpVtbl[3].QueryInterface)(local_e0,(IID *)&DAT_1800648c0,(void **)0x0),
       pIVar8 = pIVar3, (int)UVar6 < 0)) {
      _com_issue_errorex(UVar6,pIVar8,(_GUID *)&DAT_180065d78);
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_d8,(char *)recprver_exref);
    pwVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::AllocSysString
                       (local_d8);
    local_d0 = pwVar7;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_d8);
    FUN_180046e90((longlong)&local_e8,0x180065f70,(longlong)pwVar7);
    SysFreeString(pwVar7);
    FUN_180046e90((longlong)&local_e8,0x180065f80,(longlong)local_res8);
    CoTaskMemFree(local_res8);
    CPtrArray::CPtrArray(local_90);
    CPtrArray::Copy(local_90,(CPtrArray *)(*(longlong *)(param_1 + 0x78) + 0x50));
    pIVar8 = local_e0;
    local_68 = &local_e8;
    local_60 = L"Items";
    local_58 = 5;
    UVar6 = (*local_e0->lpVtbl[2].Release)(local_e0);
    if ((int)UVar6 < 0) {
      _com_issue_errorex(UVar6,pIVar8,(_GUID *)&DAT_180065d78);
    }
    lVar11 = local_80;
    uVar9 = uVar10;
    uVar13 = uVar10;
    if (0 < local_80) {
      do {
        pIVar8 = local_e0;
        if (((longlong)uVar9 < 0) || (lVar11 <= (longlong)uVar9)) {
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        lVar1 = *(longlong *)(local_88 + uVar9 * 8);
        if (((lVar1 != 0) && (*(int *)(*(longlong *)(lVar1 + 0x10) + -0x10) != 0)) &&
           (*(int *)(lVar1 + 0x30) == 0)) {
          local_50 = &local_e8;
          local_48 = L"Item";
          local_40 = 4;
          UVar6 = (*local_e0->lpVtbl[2].Release)(local_e0);
          if ((int)UVar6 < 0) {
            _com_issue_errorex(UVar6,pIVar8,(_GUID *)&DAT_180065d78);
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    (local_d8,*(char **)(lVar1 + 0x10));
          pwVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                   AllocSysString(local_d8);
          local_d0 = pwVar7;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_d8);
          pIVar8 = local_e0;
          UVar6 = (*local_e0->lpVtbl[2].Release)(local_e0);
          pIVar2 = local_e0;
          if ((int)UVar6 < 0) {
LAB_180045ee6:
            _com_issue_errorex(UVar6,pIVar8,(_GUID *)&DAT_180065d78);
          }
          else if (pwVar7 == (wchar_t *)0x0) {
LAB_180045eb2:
            pIVar8 = local_e0;
            UVar6 = (*local_e0->lpVtbl[3].QueryInterface)
                              (local_e0,(IID *)&DAT_1800648c0,(void **)0x0);
            if ((int)UVar6 < 0) goto LAB_180045ee6;
          }
          else {
            lVar11 = -1;
            do {
              lVar11 = lVar11 + 1;
            } while (pwVar7[lVar11] != L'\0');
            UVar6 = (*local_e0->lpVtbl[3].AddRef)(local_e0);
            if ((int)UVar6 < 0) {
              _com_issue_errorex(UVar6,pIVar2,(_GUID *)&DAT_180065d78);
            }
            if (-1 < (int)UVar6) goto LAB_180045eb2;
          }
          SysFreeString(pwVar7);
          pIVar8 = local_e0;
          HVar4 = (*local_e0->lpVtbl[3].QueryInterface)(local_e0,(IID *)&DAT_1800648c0,(void **)0x0)
          ;
          lVar11 = local_80;
          if (HVar4 < 0) {
            _com_issue_errorex(HVar4,pIVar8,(_GUID *)&DAT_180065d78);
            lVar11 = local_80;
          }
        }
        uVar12 = (int)uVar13 + 1;
        uVar9 = uVar9 + 1;
        uVar13 = (ulonglong)uVar12;
      } while ((int)uVar12 < lVar11);
    }
    pIVar8 = local_e0;
    HVar4 = (*local_e0->lpVtbl[3].QueryInterface)(local_e0,(IID *)&DAT_1800648c0,(void **)0x0);
    if (HVar4 < 0) {
      _com_issue_errorex(HVar4,pIVar8,(_GUID *)&DAT_180065d78);
    }
    CPtrArray::~CPtrArray(local_90);
    pIVar8 = local_e0;
    HVar4 = (*local_e0->lpVtbl[3].QueryInterface)(local_e0,(IID *)&DAT_1800648c0,(void **)0x0);
    param_2 = local_res10;
    if (HVar4 < 0) {
      _com_issue_errorex(HVar4,pIVar8,(_GUID *)&DAT_180065d78);
      param_2 = local_res10;
    }
    goto LAB_18004602c;
  }
  (**(code **)(*local_e8 + 0x10))();
  (*local_e0->lpVtbl->Release)(local_e0);
LAB_18004602c:
  pIVar8 = local_e0;
  UVar6 = (*local_e0->lpVtbl[1].Release)(local_e0);
  if ((int)UVar6 < 0) {
    _com_issue_errorex(UVar6,pIVar8,(_GUID *)&DAT_180065d78);
  }
  else {
    VariantInit(&local_c0);
    (**(code **)(*local_e8 + 0x40))();
  }
  (**(code **)(*local_e8 + 0x10))();
  (*local_e0->lpVtbl->Release)(local_e0);
  do {
    lVar14 = lVar14 + 1;
  } while (*(LPCWSTR)((longlong)local_c0.n1.decVal.u2 + lVar14 * 2) != L'\0');
  if (lVar14 != 0) {
    iVar5 = WideCharToMultiByte(0xfde9,0,(LPCWSTR)local_c0.n1.decVal.u2,(int)lVar14,(LPSTR)0x0,0,
                                (LPCSTR)0x0,(LPBOOL)0x0);
    hMem = GlobalAlloc(0x2002,(longlong)iVar5 + 1);
    if (hMem == (HGLOBAL)0x0) {
      uVar10 = 0x80030070;
    }
    else {
      lpMultiByteStr = GlobalLock(hMem);
      WideCharToMultiByte(0xfde9,0,(LPCWSTR)local_c0.n1.decVal.u2,(int)lVar14,lpMultiByteStr,iVar5,
                          (LPCSTR)0x0,(LPBOOL)0x0);
      lpMultiByteStr[iVar5] = '\0';
      GlobalUnlock(hMem);
      *(HGLOBAL *)(param_2 + 2) = hMem;
      *param_2 = 1;
      *(undefined8 *)(param_2 + 4) = 0;
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_c8);
  return uVar10;
}

/* ---- FUNC 00046160 FUN_180046160 (143 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180046160(longlong param_1,undefined4 *param_2)

{
  char *_Source;
  HGLOBAL hMem;
  undefined8 uVar1;
  char *_Dest;
  size_t _Count;
  undefined1 auStack_458 [32];
  int local_438 [4];
  undefined1 local_428 [1008];
  ulonglong local_38;
  size_t sVar2;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStack_458;
  local_438[0] = 0;
  if (*(int *)(param_1 + 0x84) == 0) {
    FUN_180002a20(local_428,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnode_dataobj.cpp",0xc83);
    LogMessage(local_428,2,1);
  }
  _Source = FUN_180044670(param_1,(void *)0x0,local_438,*(longlong *)(param_1 + 0x78));
  if ((_Source == (char *)0x0) || (*_Source == '\0')) {
    uVar1 = 0x80040064;
  }
  else {
    _Count = 0xffffffffffffffff;
    do {
      sVar2 = _Count;
      _Count = sVar2 + 1;
    } while (_Source[_Count] != '\0');
    hMem = GlobalAlloc(0x2002,sVar2 + 2);
    if (hMem == (HGLOBAL)0x0) {
      free(_Source);
      uVar1 = 0x80030070;
    }
    else {
      _Dest = GlobalLock(hMem);
      strncpy(_Dest,_Source,_Count);
      _Dest[_Count] = '\0';
      GlobalUnlock(hMem);
      *(HGLOBAL *)(param_2 + 2) = hMem;
      *param_2 = 1;
      *(undefined8 *)(param_2 + 4) = 0;
      free(_Source);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* ---- FUNC 000461EF FUN_1800461ef (103 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1800461ef(void)

{
  longlong in_RAX;
  HGLOBAL hMem;
  undefined8 uVar1;
  char *_Dest;
  char *unaff_RSI;
  size_t _Count;
  undefined4 *unaff_R15;
  size_t sVar2;
  
  _Count = 0xffffffffffffffff;
  do {
    sVar2 = _Count;
    _Count = sVar2 + 1;
  } while (*(char *)(in_RAX + _Count) != '\0');
  hMem = GlobalAlloc(0x2002,sVar2 + 2);
  if (hMem == (HGLOBAL)0x0) {
    free(unaff_RSI);
    uVar1 = 0x80030070;
  }
  else {
    _Dest = GlobalLock(hMem);
    strncpy(_Dest,unaff_RSI,_Count);
    _Dest[_Count] = '\0';
    GlobalUnlock(hMem);
    *(HGLOBAL *)(unaff_R15 + 2) = hMem;
    *unaff_R15 = 1;
    *(undefined8 *)(unaff_R15 + 4) = 0;
    free(unaff_RSI);
    uVar1 = 0;
  }
  return uVar1;
}

/* ---- FUNC 00046256 FUN_180046256 (28 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180046256(void)

{
  return;
}

/* ---- FUNC 00046272 FUN_180046272 (72 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180046272(void)

{
  char *_Dest;
  HGLOBAL unaff_RBP;
  char *unaff_RSI;
  size_t unaff_RDI;
  undefined4 *unaff_R15;
  
  _Dest = GlobalLock(unaff_RBP);
  strncpy(_Dest,unaff_RSI,unaff_RDI);
  _Dest[unaff_RDI] = '\0';
  GlobalUnlock(unaff_RBP);
  *(HGLOBAL *)(unaff_R15 + 2) = unaff_RBP;
  *unaff_R15 = 1;
  *(undefined8 *)(unaff_R15 + 4) = 0;
  free(unaff_RSI);
  return 0;
}

/* ---- FUNC 000462BA FUN_1800462ba (7 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1800462ba(void)

{
  return 0x80040064;
}

/* ---- FUNC 000462D0 FUN_1800462d0 (68 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HRESULT FUN_1800462d0(longlong param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  HRESULT HVar2;
  LPSTR lpMultiByteStr;
  HGLOBAL pvVar3;
  longlong lVar4;
  undefined1 auStackY_5b8 [32];
  LPCWSTR local_578;
  IBindCtx *local_570;
  undefined8 local_568;
  undefined2 local_558 [4];
  uchar auStack_550 [8];
  undefined4 local_548;
  undefined4 local_544;
  undefined4 local_540;
  IID local_538;
  undefined4 local_528;
  undefined1 local_524;
  undefined1 local_428 [1008];
  ulonglong local_38;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStackY_5b8;
  if (*(longlong *)(param_1 + 0xa8) != 0) {
    if (param_2 == *(int *)(param_1 + 0x2c)) {
      CreateBindCtx(0,&local_570);
      (**(code **)(**(longlong **)(param_1 + 0xa8) + 0xa0))
                (*(longlong **)(param_1 + 0xa8),local_570,0,&local_578);
      lVar4 = -1;
      do {
        lVar4 = lVar4 + 1;
      } while (local_578[lVar4] != L'\0');
      lpMultiByteStr = CoTaskMemAlloc(lVar4 * 2);
      WideCharToMultiByte(0,0,local_578,-1,lpMultiByteStr,(int)(lVar4 * 2),(LPCSTR)0x0,(LPBOOL)0x0);
      CoTaskMemFree(local_578);
      (*local_570->lpVtbl->Release)(local_570);
      local_528 = DAT_180064eb4;
      local_524 = DAT_180064eb8;
      local_568 = 0;
      if (*(longlong *)(param_1 + 0x58) == 0) {
        FUN_180045320(param_1);
      }
      iVar1 = (**(code **)(*DAT_180079800 + 0x138))(DAT_180079800,local_558);
      if (iVar1 != 0) {
        FUN_180002a20(local_428,"Assert failed in file %s line %d",
                      "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnode_dataobj.cpp",0x5a3);
        LogMessage(local_428,2,1);
      }
      local_538.Data4[0] = auStack_550[0];
      local_538.Data4[1] = auStack_550[1];
      local_538.Data4[2] = auStack_550[2];
      local_538.Data4[3] = auStack_550[3];
      local_538.Data4[4] = auStack_550[4];
      local_538.Data4[5] = auStack_550[5];
      local_538.Data4[6] = auStack_550[6];
      local_538.Data4[7] = auStack_550[7];
      pvVar3 = FUN_1800314f0(&local_538.Data1,1,*(undefined8 *)(param_1 + 0x60),local_568,0x10,
                             (LPCSTR)&local_528,lpMultiByteStr);
      *(HGLOBAL *)(param_3 + 2) = pvVar3;
      if (pvVar3 == (HGLOBAL)0x0) {
        return -0x7ff8fff2;
      }
      CoTaskMemFree(lpMultiByteStr);
      *param_3 = 1;
      param_3[4] = 0;
      param_3[5] = 0;
      return 0;
    }
    if (param_2 == *(int *)(param_1 + 0x28)) {
      if (param_4 == 0) {
        *param_3 = 0;
      }
      param_3[4] = 0;
      param_3[5] = 0;
      local_558[0] = (undefined2)param_2;
      local_548 = 1;
      auStack_550[0] = '\0';
      auStack_550[1] = '\0';
      auStack_550[2] = '\0';
      auStack_550[3] = '\0';
      auStack_550[4] = '\0';
      auStack_550[5] = '\0';
      auStack_550[6] = '\0';
      auStack_550[7] = '\0';
      local_540 = 4;
      local_544 = 0xffffffff;
      iVar1 = (**(code **)(*DAT_180079800 + 0x138))(DAT_180079800,&local_538);
      if (iVar1 != 0) {
        FUN_180002a20(local_428,"Assert failed in file %s line %d",
                      "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnode_dataobj.cpp",0x5bf);
        LogMessage(local_428,2,1);
      }
      HVar2 = FUN_180031650(*(LPPERSISTSTREAM *)(param_1 + 0xa8),&local_538,(longlong)local_558,
                            param_3);
      return HVar2;
    }
  }
  return -0x7ffbff9c;
}

/* ---- FUNC 00046314 FUN_180046314 (188 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180046314(void)

{
  int iVar1;
  LPSTR lpMultiByteStr;
  HGLOBAL pvVar2;
  undefined8 uVar3;
  undefined8 unaff_RBX;
  longlong lVar4;
  longlong unaff_RBP;
  undefined4 *unaff_RSI;
  longlong unaff_RDI;
  longlong in_R11;
  undefined8 unaff_R15;
  LPCWSTR in_stack_00000040;
  IBindCtx *in_stack_00000048;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  *(undefined8 *)(in_R11 + 0x20) = unaff_RBX;
  *(undefined8 *)(in_R11 + -0x28) = unaff_R15;
  CreateBindCtx(0,&stack0x00000048);
  (**(code **)(**(longlong **)(unaff_RDI + 0xa8) + 0xa0))
            (*(longlong **)(unaff_RDI + 0xa8),in_stack_00000048,0,&stack0x00000040);
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (in_stack_00000040[lVar4] != L'\0');
  lpMultiByteStr = CoTaskMemAlloc(lVar4 * 2);
  WideCharToMultiByte(0,0,in_stack_00000040,-1,lpMultiByteStr,(int)(lVar4 * 2),(LPCSTR)0x0,
                      (LPBOOL)0x0);
  CoTaskMemFree(in_stack_00000040);
  (*in_stack_00000048->lpVtbl->Release)(in_stack_00000048);
  *(undefined4 *)(unaff_RBP + -0x70) = DAT_180064eb4;
  *(undefined1 *)(unaff_RBP + -0x6c) = DAT_180064eb8;
  in_stack_00000050 = 0;
  if (*(longlong *)(unaff_RDI + 0x58) == 0) {
    FUN_180045320(unaff_RDI);
  }
  iVar1 = (**(code **)(*DAT_180079800 + 0x138))(DAT_180079800,&stack0x00000060);
  if (iVar1 != 0) {
    FUN_180002a20(unaff_RBP + 0x90,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnode_dataobj.cpp",0x5a3);
    LogMessage(unaff_RBP + 0x90,2,1);
  }
  uVar3 = *(undefined8 *)(unaff_RDI + 0x60);
  *(undefined8 *)(unaff_RBP + -0x80) = in_stack_00000060;
  *(undefined8 *)(unaff_RBP + -0x78) = in_stack_00000068;
  pvVar2 = FUN_1800314f0((uint *)(unaff_RBP + -0x80),1,uVar3,in_stack_00000050,0x10,
                         (LPCSTR)(unaff_RBP + -0x70),lpMultiByteStr);
  *(HGLOBAL *)(unaff_RSI + 2) = pvVar2;
  if (pvVar2 == (HGLOBAL)0x0) {
    uVar3 = 0x8007000e;
  }
  else {
    CoTaskMemFree(lpMultiByteStr);
    uVar3 = 0;
    *unaff_RSI = 1;
    *(undefined8 *)(unaff_RSI + 4) = 0;
  }
  return uVar3;
}

/* ---- FUNC 000463D0 FUN_1800463d0 (164 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1800463d0(void)

{
  int iVar1;
  HGLOBAL pvVar2;
  undefined8 uVar3;
  longlong unaff_RBP;
  undefined4 *unaff_RSI;
  longlong unaff_RDI;
  undefined8 unaff_R14;
  LPCSTR unaff_R15;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  FUN_180045320(unaff_RDI);
  iVar1 = (**(code **)(*DAT_180079800 + 0x138))(DAT_180079800,&stack0x00000060);
  if (iVar1 != 0) {
    FUN_180002a20(unaff_RBP + 0x90,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnode_dataobj.cpp",0x5a3);
    LogMessage(unaff_RBP + 0x90,2,1);
  }
  uVar3 = *(undefined8 *)(unaff_RDI + 0x60);
  *(undefined8 *)(unaff_RBP + -0x80) = in_stack_00000060;
  *(undefined8 *)(unaff_RBP + -0x78) = in_stack_00000068;
  pvVar2 = FUN_1800314f0((uint *)(unaff_RBP + -0x80),1,uVar3,in_stack_00000050,0x10,
                         (LPCSTR)(unaff_RBP + -0x70),unaff_R15);
  *(HGLOBAL *)(unaff_RSI + 2) = pvVar2;
  if (pvVar2 == (HGLOBAL)0x0) {
    uVar3 = 0x8007000e;
  }
  else {
    CoTaskMemFree(unaff_R15);
    uVar3 = 0;
    *unaff_RSI = 1;
    *(undefined8 *)(unaff_RSI + 4) = unaff_R14;
  }
  return uVar3;
}

/* ---- FUNC 00046474 FUN_180046474 (28 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180046474(void)

{
  return;
}

/* ---- FUNC 00046490 FUN_180046490 (23 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180046490(void)

{
  undefined4 *unaff_RSI;
  undefined8 unaff_R14;
  LPVOID unaff_R15;
  
  CoTaskMemFree(unaff_R15);
  *unaff_RSI = 1;
  *(undefined8 *)(unaff_RSI + 4) = unaff_R14;
  return 0;
}

/* ---- FUNC 000464A7 FUN_1800464a7 (175 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HRESULT FUN_1800464a7(longlong param_1,int param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  HRESULT HVar2;
  longlong unaff_RBP;
  int *unaff_RSI;
  longlong unaff_RDI;
  undefined2 uStack0000000000000060;
  undefined8 uStack0000000000000068;
  undefined4 uStack0000000000000070;
  undefined4 uStack0000000000000074;
  undefined4 uStack0000000000000078;
  
  if (param_2 == *(int *)(param_1 + 0x28)) {
    if (param_4 == 0) {
      *param_3 = 0;
    }
    *(undefined8 *)(param_3 + 4) = 0;
    uStack0000000000000060 = (undefined2)param_2;
    uStack0000000000000070 = 1;
    uStack0000000000000068 = 0;
    uStack0000000000000078 = 4;
    uStack0000000000000074 = 0xffffffff;
    iVar1 = (**(code **)(*DAT_180079800 + 0x138))(DAT_180079800,unaff_RBP + -0x80);
    if (iVar1 != 0) {
      FUN_180002a20(unaff_RBP + 0x90,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnode_dataobj.cpp",0x5bf);
      LogMessage(unaff_RBP + 0x90,2,1);
    }
    HVar2 = FUN_180031650(*(LPPERSISTSTREAM *)(unaff_RDI + 0xa8),(IID *)(unaff_RBP + -0x80),
                          (longlong)&stack0x00000060,unaff_RSI);
  }
  else {
    HVar2 = -0x7ffbff9c;
  }
  return HVar2;
}

/* ---- FUNC 00046560 FUN_180046560 (129 bytes) ---- */

HMETAFILE FUN_180046560(longlong param_1)

{
  char cVar1;
  BOOL BVar2;
  HDC hdc;
  HDC hdc_00;
  HGDIOBJ pvVar3;
  HMETAFILE pHVar4;
  char *pcVar5;
  char *lpString;
  int iVar6;
  tagPOINT local_res8;
  tagSIZE local_res10;
  
  FUN_180045320(param_1);
  local_res8.x = *(int *)(param_1 + 0x60);
  local_res8.y = -*(int *)(param_1 + 100);
  hdc = CreateDCA("DISPLAY",(LPCSTR)0x0,(LPCSTR)0x0,(DEVMODEA *)0x0);
  SetMapMode(hdc,3);
  LPtoDP(hdc,&local_res8,1);
  SetMapMode(hdc,1);
  hdc_00 = CreateMetaFileA((LPCSTR)0x0);
  pHVar4 = (HMETAFILE)0x0;
  iVar6 = 0;
  if (hdc_00 != (HDC)0x0) {
    SetMapMode(hdc_00,8);
    SetWindowOrgEx(hdc_00,0,0,(LPPOINT)0x0);
    SetWindowExtEx(hdc_00,local_res8.x,local_res8.y,(LPSIZE)0x0);
    pvVar3 = GetStockObject(7);
    pvVar3 = SelectObject(hdc_00,pvVar3);
    SetBkMode(hdc_00,1);
    pcVar5 = *(char **)(param_1 + 0x58);
    cVar1 = *pcVar5;
    lpString = pcVar5;
    while( true ) {
      if (cVar1 == '\0') break;
      if (*pcVar5 == '\n') {
        iVar6 = (int)pcVar5 - (int)lpString;
        TextOutA(hdc_00,0,(int)pHVar4,lpString,iVar6);
        BVar2 = GetTextExtentPoint32A(hdc,lpString,iVar6,&local_res10);
        if (BVar2 != 0) {
          pHVar4 = (HMETAFILE)(ulonglong)(uint)((int)pHVar4 + local_res10.cy);
        }
        lpString = pcVar5 + 1;
      }
      iVar6 = (int)pHVar4;
      pcVar5 = pcVar5 + 1;
      cVar1 = *pcVar5;
    }
    TextOutA(hdc_00,0,iVar6,lpString,(int)pcVar5 - (int)lpString);
    SelectObject(hdc_00,pvVar3);
    pHVar4 = CloseMetaFile(hdc_00);
  }
  DeleteDC(hdc);
  return pHVar4;
}

/* ---- FUNC 000465E1 FUN_1800465e1 (109 bytes) ---- */

HMETAFILE FUN_1800465e1(void)

{
  BOOL BVar1;
  HDC in_RAX;
  HGDIOBJ pvVar2;
  HMETAFILE pHVar3;
  char *pcVar4;
  longlong unaff_RBP;
  char *lpString;
  int unaff_ESI;
  int c;
  HDC unaff_R14;
  HDC unaff_R15;
  int iStack0000000000000060;
  int iStack0000000000000064;
  tagSIZE in_stack_00000068;
  
  SetMapMode(in_RAX,unaff_ESI + 8);
  SetWindowOrgEx(unaff_R14,0,0,(LPPOINT)0x0);
  SetWindowExtEx(unaff_R14,iStack0000000000000060,iStack0000000000000064,(LPSIZE)0x0);
  pvVar2 = GetStockObject(unaff_ESI + 7);
  pvVar2 = SelectObject(unaff_R14,pvVar2);
  SetBkMode(unaff_R14,unaff_ESI + 1);
  pcVar4 = *(char **)(unaff_RBP + 0x58);
  lpString = pcVar4;
  if (*pcVar4 != (char)unaff_ESI) {
    do {
      if (*pcVar4 == '\n') {
        c = (int)pcVar4 - (int)lpString;
        TextOutA(unaff_R14,0,unaff_ESI,lpString,c);
        BVar1 = GetTextExtentPoint32A(unaff_R15,lpString,c,&stack0x00000068);
        if (BVar1 != 0) {
          unaff_ESI = unaff_ESI + in_stack_00000068.cy;
        }
        lpString = pcVar4 + 1;
      }
      pcVar4 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
  }
  TextOutA(unaff_R14,0,unaff_ESI,lpString,(int)pcVar4 - (int)lpString);
  SelectObject(unaff_R14,pvVar2);
  pHVar3 = CloseMetaFile(unaff_R14);
  DeleteDC(unaff_R15);
  return pHVar3;
}

/* ---- FUNC 0004664E FUN_18004664e (80 bytes) ---- */

HMETAFILE FUN_18004664e(void)

{
  BOOL BVar1;
  HMETAFILE pHVar2;
  char *unaff_RBX;
  char *unaff_RBP;
  int unaff_ESI;
  int c;
  HGDIOBJ unaff_R12;
  HDC unaff_R14;
  HDC unaff_R15;
  tagSIZE in_stack_00000068;
  
  do {
    if (*unaff_RBX == '\n') {
      c = (int)unaff_RBX - (int)unaff_RBP;
      TextOutA(unaff_R14,0,unaff_ESI,unaff_RBP,c);
      BVar1 = GetTextExtentPoint32A(unaff_R15,unaff_RBP,c,&stack0x00000068);
      if (BVar1 != 0) {
        unaff_ESI = unaff_ESI + in_stack_00000068.cy;
      }
      unaff_RBP = unaff_RBX + 1;
    }
    unaff_RBX = unaff_RBX + 1;
  } while (*unaff_RBX != '\0');
  TextOutA(unaff_R14,0,unaff_ESI,unaff_RBP,(int)unaff_RBX - (int)unaff_RBP);
  SelectObject(unaff_R14,unaff_R12);
  pHVar2 = CloseMetaFile(unaff_R14);
  DeleteDC(unaff_R15);
  return pHVar2;
}

/* ---- FUNC 0004669E FUN_18004669e (57 bytes) ---- */

HMETAFILE FUN_18004669e(void)

{
  HMETAFILE pHVar1;
  int unaff_EBX;
  LPCSTR unaff_RBP;
  int unaff_ESI;
  HGDIOBJ unaff_R12;
  HDC unaff_R14;
  HDC unaff_R15;
  
  TextOutA(unaff_R14,0,unaff_ESI,unaff_RBP,unaff_EBX - (int)unaff_RBP);
  SelectObject(unaff_R14,unaff_R12);
  pHVar1 = CloseMetaFile(unaff_R14);
  DeleteDC(unaff_R15);
  return pHVar1;
}

/* ---- FUNC 000466D7 FUN_1800466d7 (23 bytes) ---- */

void FUN_1800466d7(void)

{
  HDC unaff_R15;
  
  DeleteDC(unaff_R15);
  return;
}

/* ---- FUNC 000466F0 FUN_1800466f0 (185 bytes) ---- */

undefined8 FUN_1800466f0(longlong param_1,undefined4 *param_2)

{
  HMETAFILE hmf;
  HGLOBAL hMem;
  undefined8 uVar1;
  undefined4 *puVar2;
  
  hmf = FUN_180046560(param_1);
  if (hmf == (HMETAFILE)0x0) {
    return 0x8007000e;
  }
  hMem = GlobalAlloc(0x2002,0x18);
  if (hMem == (HGLOBAL)0x0) {
    DeleteMetaFile(hmf);
    uVar1 = 0x8007000e;
  }
  else {
    puVar2 = GlobalLock(hMem);
    *(HMETAFILE *)(puVar2 + 4) = hmf;
    *puVar2 = 8;
    puVar2[1] = *(undefined4 *)(param_1 + 0x60);
    puVar2[2] = *(undefined4 *)(param_1 + 100);
    GlobalUnlock(hMem);
    uVar1 = 0;
    *(HGLOBAL *)(param_2 + 2) = hMem;
    *param_2 = 0x20;
    *(undefined8 *)(param_2 + 4) = 0;
  }
  return uVar1;
}

/* ---- FUNC 000467B0 FUN_1800467b0 (1026 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HRESULT FUN_1800467b0(longlong param_1,int param_2,int *param_3,undefined8 param_4,int param_5)

{
  undefined2 *puVar1;
  uint uVar2;
  longlong *plVar3;
  code *pcVar4;
  _func_5312 *p_Var5;
  bool bVar6;
  LPPERSISTSTREAM pIVar7;
  HRESULT HVar8;
  longlong lVar9;
  longlong lVar10;
  HGLOBAL hMem;
  char *_Dest;
  ulonglong uVar11;
  size_t _Count;
  int iVar12;
  undefined2 *puVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  undefined2 *puVar16;
  undefined8 uStack_4a0;
  undefined1 auStack_498 [32];
  undefined8 uStack_478;
  int aiStack_470 [2];
  LPPERSISTSTREAM local_468;
  undefined2 local_460 [4];
  undefined8 local_458;
  undefined4 local_450;
  undefined4 local_44c;
  undefined4 local_448;
  IID local_440;
  undefined1 local_428 [1008];
  ulonglong local_38;
  
  puVar14 = auStack_498;
  local_38 = DAT_180077818 ^ (ulonglong)&local_468;
  if (param_2 == *(int *)(param_1 + 0x38)) {
    puVar15 = auStack_498;
    if (*(longlong *)(param_1 + 0xa8) != 0) {
      puVar13 = (undefined2 *)0x0;
      local_468 = (LPPERSISTSTREAM)0x0;
      bVar6 = false;
      lVar9 = *(longlong *)(param_1 + 0x78);
      if (*(int *)(param_1 + 0x84) == 0) {
        local_468 = *(LPPERSISTSTREAM *)(lVar9 + 0xe8);
      }
      else {
        puVar14 = auStack_498;
        if ((*(longlong *)(lVar9 + 0x60) == 1) &&
           (lVar9 = **(longlong **)(lVar9 + 0x58), puVar14 = auStack_498, lVar9 != 0)) {
          uVar2 = *(uint *)(lVar9 + 0x30);
          if ((uVar2 & 0xfffffffb) == 0) {
            local_468 = *(LPPERSISTSTREAM *)(*(longlong *)(lVar9 + 0x28) + 0xe8);
            puVar14 = auStack_498;
          }
          else if (uVar2 == 3) {
            plVar3 = *(longlong **)(*(longlong *)(lVar9 + 0x28) + 0xe8);
            uStack_4a0 = 0x180046858;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_440);
            uStack_4a0 = 0x18004686e;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_440,
                       "@LABEL%s",*(undefined8 *)(lVar9 + 0x18));
            puVar14 = auStack_498;
            puVar16 = puVar13;
            if ((LPCSTR)local_440._0_8_ != (LPCSTR)0x0) {
              lVar9 = -1;
              do {
                lVar10 = lVar9;
                lVar9 = lVar10 + 1;
              } while (*(char *)(local_440._0_8_ + lVar9) != '\0');
              iVar12 = (int)lVar10 + 2;
              puVar14 = auStack_498;
              if (iVar12 < 0x40000000) {
                lVar9 = (longlong)(int)lVar9 * 2;
                uVar11 = lVar9 + 0x11;
                if (uVar11 <= lVar9 + 2U) {
                  uVar11 = 0xffffffffffffff0;
                }
                uStack_4a0 = 0x1800468be;
                lVar9 = -(uVar11 & 0xfffffffffffffff0);
                puVar1 = (undefined2 *)((longlong)local_460 + lVar9 + -8);
                puVar14 = auStack_498 + lVar9;
                if (puVar1 != (undefined2 *)0x0) {
                  *puVar1 = 0;
                  *(int *)((longlong)aiStack_470 + lVar9) = iVar12;
                  *(undefined2 **)((longlong)&uStack_478 + lVar9) = puVar1;
                  *(undefined8 *)(auStack_498 + lVar9 + -8) = 0x1800468e5;
                  iVar12 = MultiByteToWideChar(0,0,(LPCSTR)local_440._0_8_,-1,
                                               *(LPWSTR *)((longlong)&uStack_478 + lVar9),
                                               *(int *)((longlong)aiStack_470 + lVar9));
                  puVar14 = auStack_498 + lVar9;
                  puVar16 = puVar1;
                  if (iVar12 == 0) {
                    puVar14 = auStack_498 + lVar9;
                    puVar16 = puVar13;
                  }
                }
              }
            }
            *(LPPERSISTSTREAM **)(puVar14 + 0x20) = &local_468;
            *(undefined8 *)(puVar14 + -8) = 0x180046909;
            FUN_1800312a0((IBindCtx *)0x0,plVar3,(longlong)puVar16,(ULONG *)0x0,
                          *(LPMONIKER **)(puVar14 + 0x20));
            bVar6 = true;
            *(undefined8 *)(puVar14 + -8) = 0x180046918;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_440);
          }
          else {
            puVar14 = auStack_498;
            if ((((uVar2 == 2) &&
                 (puVar14 = auStack_498, *(int *)(*(longlong *)(lVar9 + 0x10) + -0x10) != 0)) &&
                (puVar14 = auStack_498, *(int *)(*(longlong *)(lVar9 + 0x18) + -0x10) != 0)) &&
               (puVar14 = auStack_498, DAT_1800797f0 != 0)) {
              uStack_4a0 = 0x180046957;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_440
                        );
              uStack_4a0 = 0x180046971;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_440
                         ,"%s!@LABEL%s",*(undefined8 *)(lVar9 + 0x10));
              puVar14 = auStack_498;
              puVar16 = puVar13;
              if ((LPCSTR)local_440._0_8_ != (LPCSTR)0x0) {
                lVar9 = -1;
                do {
                  lVar10 = lVar9;
                  lVar9 = lVar10 + 1;
                } while (*(char *)(local_440._0_8_ + lVar9) != '\0');
                iVar12 = (int)lVar10 + 2;
                puVar14 = auStack_498;
                if (iVar12 < 0x40000000) {
                  lVar9 = (longlong)(int)lVar9 * 2;
                  uVar11 = lVar9 + 0x11;
                  if (uVar11 <= lVar9 + 2U) {
                    uVar11 = 0xffffffffffffff0;
                  }
                  uStack_4a0 = 0x1800469bf;
                  lVar9 = -(uVar11 & 0xfffffffffffffff0);
                  puVar1 = (undefined2 *)((longlong)local_460 + lVar9 + -8);
                  puVar14 = auStack_498 + lVar9;
                  if (puVar1 != (undefined2 *)0x0) {
                    *puVar1 = 0;
                    *(int *)((longlong)aiStack_470 + lVar9) = iVar12;
                    *(undefined2 **)((longlong)&uStack_478 + lVar9) = puVar1;
                    *(undefined8 *)(auStack_498 + lVar9 + -8) = 0x1800469e6;
                    iVar12 = MultiByteToWideChar(0,0,(LPCSTR)local_440._0_8_,-1,
                                                 *(LPWSTR *)((longlong)&uStack_478 + lVar9),
                                                 *(int *)((longlong)aiStack_470 + lVar9));
                    puVar14 = auStack_498 + lVar9;
                    puVar16 = puVar1;
                    if (iVar12 == 0) {
                      puVar14 = auStack_498 + lVar9;
                      puVar16 = puVar13;
                    }
                  }
                }
              }
              *(LPPERSISTSTREAM **)(puVar14 + 0x20) = &local_468;
              plVar3 = *(longlong **)(DAT_1800797f0 + 0x118);
              *(undefined8 *)(puVar14 + -8) = 0x180046a15;
              FUN_1800312a0((IBindCtx *)0x0,plVar3,(longlong)puVar16,(ULONG *)0x0,
                            *(LPMONIKER **)(puVar14 + 0x20));
              bVar6 = true;
              *(undefined8 *)(puVar14 + -8) = 0x180046a24;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_440
                        );
            }
          }
        }
      }
      puVar15 = puVar14;
      if (local_468 != (LPPERSISTSTREAM)0x0) {
        if (param_5 == 0) {
          *param_3 = 0;
        }
        param_3[4] = 0;
        param_3[5] = 0;
        local_460[0] = (undefined2)param_2;
        local_450 = 1;
        local_458 = 0;
        local_448 = 4;
        local_44c = 0xffffffff;
        pcVar4 = *(code **)(*DAT_180079800 + 0x138);
        *(undefined8 *)(puVar14 + -8) = 0x180046a8f;
        iVar12 = (*pcVar4)(DAT_180079800,&local_440);
        if (iVar12 != 0) {
          *(undefined8 *)(puVar14 + -8) = 0x180046ab0;
          FUN_180002a20(local_428,"Assert failed in file %s line %d",
                        "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnode_dataobj.cpp",0xd0b);
          *(undefined8 *)(puVar14 + -8) = 0x180046ac3;
          LogMessage(local_428,2,1);
        }
        pIVar7 = local_468;
        *(undefined8 *)(puVar14 + -8) = 0x180046ad7;
        HVar8 = FUN_180031650(pIVar7,&local_440,(longlong)local_460,param_3);
        pIVar7 = local_468;
        if (bVar6) {
          p_Var5 = local_468->lpVtbl->Release;
          *(undefined8 *)(puVar14 + -8) = 0x180046ae7;
          (*p_Var5)(pIVar7);
        }
        goto LAB_180046b8d;
      }
    }
  }
  else {
    puVar15 = auStack_498;
    if ((((param_2 == *(int *)(param_1 + 0x3c)) &&
         (puVar15 = auStack_498, *(int *)(param_1 + 0x84) != 0)) &&
        (puVar15 = auStack_498, *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60) == 1)) &&
       ((lVar9 = **(longlong **)(*(longlong *)(param_1 + 0x78) + 0x58), puVar15 = auStack_498,
        lVar9 != 0 &&
        (iVar12 = *(int *)(*(longlong *)(lVar9 + 0x10) + -0x10), _Count = (size_t)iVar12,
        puVar15 = auStack_498, iVar12 != 0)))) {
      uStack_4a0 = 0x180046b3a;
      hMem = GlobalAlloc(0x2002,_Count + 1);
      if (hMem == (HGLOBAL)0x0) {
        HVar8 = -0x7ffcff90;
        puVar14 = auStack_498;
      }
      else {
        uStack_4a0 = 0x180046b52;
        _Dest = GlobalLock(hMem);
        uStack_4a0 = 0x180046b65;
        strncpy(_Dest,*(char **)(lVar9 + 0x10),_Count);
        _Dest[_Count] = '\0';
        uStack_4a0 = 0x180046b73;
        GlobalUnlock(hMem);
        *(HGLOBAL *)(param_3 + 2) = hMem;
        *param_3 = 1;
        param_3[4] = 0;
        param_3[5] = 0;
        HVar8 = 0;
        puVar14 = auStack_498;
      }
      goto LAB_180046b8d;
    }
  }
  HVar8 = -0x7ffbff9c;
  puVar14 = puVar15;
LAB_180046b8d:
  *(undefined8 *)(puVar14 + -8) = 0x180046b9c;
  return HVar8;
}

/* ---- FUNC 00046BC0 FUN_180046bc0 (41 bytes) ---- */

void FUN_180046bc0(longlong param_1)

{
  code *pcVar1;
  
  *(undefined4 *)(param_1 + 0x80) = 1;
  operator_new__(0x14);
  FUN_180043930(param_1);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

/* ---- FUNC 00046BF0 FUN_180046bf0 (94 bytes) ---- */

undefined8 FUN_180046bf0(longlong param_1,undefined4 *param_2)

{
  HGLOBAL hMem;
  undefined8 uVar1;
  char *_Dest;
  size_t _Count;
  
  FUN_180045320(param_1);
  if (*(longlong *)(param_1 + 0x58) == 0) {
    _Count = 0;
  }
  else {
    _Count = 0xffffffffffffffff;
    do {
      _Count = _Count + 1;
    } while (*(char *)(*(longlong *)(param_1 + 0x58) + _Count) != '\0');
  }
  hMem = GlobalAlloc(0x2002,_Count + 1);
  if (hMem == (HGLOBAL)0x0) {
    uVar1 = 0x80030070;
  }
  else {
    _Dest = GlobalLock(hMem);
    strncpy(_Dest,*(char **)(param_1 + 0x58),_Count);
    _Dest[_Count] = '\0';
    GlobalUnlock(hMem);
    uVar1 = 0;
    *(HGLOBAL *)(param_2 + 2) = hMem;
    *param_2 = 1;
    *(undefined8 *)(param_2 + 4) = 0;
  }
  return uVar1;
}

/* ---- FUNC 00046C4E FUN_180046c4e (69 bytes) ---- */

undefined8 FUN_180046c4e(HGLOBAL param_1)

{
  char *_Dest;
  size_t unaff_RBX;
  longlong unaff_RBP;
  HGLOBAL unaff_RSI;
  undefined4 *unaff_R15;
  
  _Dest = GlobalLock(param_1);
  strncpy(_Dest,*(char **)(unaff_RBP + 0x58),unaff_RBX);
  _Dest[unaff_RBX] = '\0';
  GlobalUnlock(unaff_RSI);
  *(HGLOBAL *)(unaff_R15 + 2) = unaff_RSI;
  *unaff_R15 = 1;
  *(undefined8 *)(unaff_R15 + 4) = 0;
  return 0;
}

/* ---- FUNC 00046C93 FUN_180046c93 (20 bytes) ---- */

void FUN_180046c93(void)

{
  return;
}

/* ---- FUNC 00046CB0 FUN_180046cb0 (45 bytes) ---- */

undefined8 FUN_180046cb0(longlong param_1,undefined4 param_2,undefined4 param_3)

{
  longlong *plVar1;
  
  plVar1 = *(longlong **)(param_1 + 0x98);
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x30))(plVar1,param_1 + 0x18,param_2,param_3);
  }
  return 0;
}

/* ---- FUNC 00046CE0 FUN_180046ce0 (37 bytes) ---- */

undefined8 FUN_180046ce0(longlong param_1,undefined4 param_2,undefined4 param_3)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x18)) {
    lVar3 = 0;
    do {
      plVar1 = *(longlong **)(lVar3 + *(longlong *)(param_1 + 0x20));
      (**(code **)(*plVar1 + 0x18))(plVar1,param_2,param_3);
      iVar2 = iVar2 + 1;
      lVar3 = lVar3 + 8;
    } while (iVar2 < *(int *)(param_1 + 0x18));
  }
  return 0;
}

/* ---- FUNC 00046D05 FUN_180046d05 (47 bytes) ---- */

undefined8 FUN_180046d05(void)

{
  longlong *plVar1;
  uint unaff_EBX;
  undefined4 unaff_EBP;
  longlong unaff_RSI;
  ulonglong uVar2;
  undefined4 unaff_R14D;
  
  uVar2 = (ulonglong)unaff_EBX;
  do {
    plVar1 = *(longlong **)(uVar2 + *(longlong *)(unaff_RSI + 0x20));
    (**(code **)(*plVar1 + 0x18))(plVar1,unaff_R14D,unaff_EBP);
    unaff_EBX = unaff_EBX + 1;
    uVar2 = uVar2 + 8;
  } while ((int)unaff_EBX < *(int *)(unaff_RSI + 0x18));
  return 0;
}

/* ---- FUNC 00046D34 FUN_180046d34 (24 bytes) ---- */

undefined8 FUN_180046d34(void)

{
  return 0;
}

/* ---- FUNC 00046D50 FUN_180046d50 (98 bytes) ---- */

undefined8 FUN_180046d50(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  undefined8 uVar2;
  
  if (*(longlong **)(param_1 + 0xa8) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0xa8) + 0x10))();
    *(undefined8 *)(param_1 + 0xa8) = 0;
  }
  uVar2 = FUN_180042540(param_1,param_2);
  if ((-1 < (int)uVar2) && (plVar1 = *(longlong **)(param_1 + 0xa0), plVar1 != (longlong *)0x0)) {
    (**(code **)(*plVar1 + 0x30))(plVar1,*(undefined8 *)(param_1 + 0xa8));
  }
  return 0;
}

/* ---- FUNC 00046DC0 FUN_180046dc0 (28 bytes) ---- */

undefined8 FUN_180046dc0(longlong param_1,undefined8 param_2)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x18)) {
    lVar3 = 0;
    do {
      plVar1 = *(longlong **)(lVar3 + *(longlong *)(param_1 + 0x20));
      (**(code **)(*plVar1 + 0x20))(plVar1,param_2);
      iVar2 = iVar2 + 1;
      lVar3 = lVar3 + 8;
    } while (iVar2 < *(int *)(param_1 + 0x18));
  }
  return 0;
}

/* ---- FUNC 00046DDC FUN_180046ddc (53 bytes) ---- */

undefined8 FUN_180046ddc(void)

{
  uint unaff_EBX;
  longlong unaff_RSI;
  ulonglong uVar1;
  
  uVar1 = (ulonglong)unaff_EBX;
  do {
    (**(code **)(**(longlong **)(uVar1 + *(longlong *)(unaff_RSI + 0x20)) + 0x20))();
    unaff_EBX = unaff_EBX + 1;
    uVar1 = uVar1 + 8;
  } while ((int)unaff_EBX < *(int *)(unaff_RSI + 0x18));
  return 0;
}

/* ---- FUNC 00046E11 FUN_180046e11 (18 bytes) ---- */

undefined8 FUN_180046e11(void)

{
  return 0;
}

/* ---- FUNC 00046E30 FUN_180046e30 (84 bytes) ---- */

undefined8 FUN_180046e30(longlong param_1,undefined8 param_2)

{
  longlong *plVar1;
  
  plVar1 = *(longlong **)(*(longlong *)(param_1 + 8) + 0x90);
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x10))();
  }
  *(undefined8 *)(*(longlong *)(param_1 + 8) + 0x90) = param_2;
  plVar1 = *(longlong **)(*(longlong *)(param_1 + 8) + 0x90);
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 8))();
  }
  return 0;
}

/* ---- FUNC 00046E90 FUN_180046e90 (334 bytes) ---- */

ULONG FUN_180046e90(longlong param_1,longlong param_2,longlong param_3)

{
  IUnknown *pIVar1;
  ULONG UVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar3 = -1;
  lVar4 = lVar3;
  if (param_2 != 0) {
    do {
      lVar4 = lVar4 + 1;
    } while (*(short *)(param_2 + lVar4 * 2) != 0);
  }
  pIVar1 = *(IUnknown **)(param_1 + 8);
  UVar2 = (*pIVar1->lpVtbl[2].Release)(pIVar1);
  if ((int)UVar2 < 0) {
    _com_issue_errorex(UVar2,pIVar1,(_GUID *)&DAT_180065d78);
  }
  else {
    lVar4 = lVar3;
    if (param_3 != 0) {
      do {
        lVar4 = lVar4 + 1;
      } while (*(short *)(param_3 + lVar4 * 2) != 0);
      pIVar1 = *(IUnknown **)(param_1 + 8);
      UVar2 = (*pIVar1->lpVtbl[3].AddRef)(pIVar1);
      if ((int)UVar2 < 0) {
        _com_issue_errorex(UVar2,pIVar1,(_GUID *)&DAT_180065d78);
        return UVar2;
      }
    }
    if (param_2 != 0) {
      do {
        lVar3 = lVar3 + 1;
      } while (*(short *)(param_2 + lVar3 * 2) != 0);
    }
    pIVar1 = *(IUnknown **)(param_1 + 8);
    UVar2 = (*pIVar1->lpVtbl[3].QueryInterface)(pIVar1,(IID *)&DAT_1800648c0,(void **)0x0);
    if ((int)UVar2 < 0) {
      _com_issue_errorex(UVar2,pIVar1,(_GUID *)&DAT_180065d78);
    }
  }
  return UVar2;
}

/* ---- FUNC 00046FE0 FUN_180046fe0 (29 bytes) ---- */

undefined8 FUN_180046fe0(longlong param_1)

{
  longlong *plVar1;
  undefined8 uVar2;
  
  plVar1 = *(longlong **)(*(longlong *)(param_1 + 8) + 0xa0);
  if (plVar1 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000180046ff3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(*plVar1 + 0x20))();
    return uVar2;
  }
  return 0x80004005;
}

/* ---- FUNC 00047000 FUN_180047000 (376 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180047000(longlong param_1,double param_2,short param_3,
                  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_4)

{
  char *pcVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  ulonglong uVar5;
  double _X;
  double dVar6;
  uint uVar7;
  uint uVar8;
  undefined1 auStack_108 [32];
  char local_e8 [112];
  ulonglong local_78;
  
  local_78 = DAT_180077818 ^ (ulonglong)auStack_108;
  uVar7 = SUB84(param_2,0) & _DAT_180066040;
  uVar8 = (uint)((ulonglong)param_2 >> 0x20) & _UNK_180066044;
  uVar4 = (int)param_3 - 1;
  if (0.0 <= param_2) {
    uVar4 = (uint)param_3;
  }
  _X = log10((double)CONCAT44(uVar8,uVar7));
  dVar6 = ceil(_X);
  uVar2 = uVar4 - 1;
  if ((int)dVar6 == uVar4) {
    uVar2 = uVar4;
  }
  uVar5 = (ulonglong)uVar2;
  if (((0.0 < _X) || (_X < DAT_180066030)) ||
     (DAT_180066020 < (double)CONCAT44(uVar8,uVar7) ||
      DAT_180066020 == (double)CONCAT44(uVar8,uVar7))) {
    if (((_X < DAT_180066030) || ((double)(int)uVar2 <= _X)) &&
       (uVar5 = (ulonglong)(uVar2 - 4),
       _DAT_180066028 <=
       (double)CONCAT44((uint)((ulonglong)_X >> 0x20) & _UNK_180066044,SUB84(_X,0) & _DAT_180066040)
       )) {
      uVar5 = (ulonglong)(uVar2 - 5);
    }
  }
  else {
    uVar5 = (ulonglong)(uVar2 - 1);
  }
  FUN_180002a20(local_e8,&DAT_180065e30,uVar5,param_2);
  pcVar3 = local_e8;
  while (local_e8[0] != '\0') {
    if (local_e8[0] == 'e') {
      pcVar3 = pcVar3 + 2;
      if (*pcVar3 == '0') {
        do {
          pcVar1 = pcVar3 + 1;
          *pcVar3 = *pcVar1;
          pcVar3 = pcVar3 + 1;
        } while (*pcVar1 != '\0');
      }
    }
    else {
      pcVar3 = pcVar3 + 1;
    }
    local_e8[0] = *pcVar3;
  }
  if ((ulonglong)(longlong)param_3 < 100) {
    local_e8[param_3] = '\0';
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_4,local_e8);
    FUN_180042860(param_1,param_4);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18005c254();
}

/* ---- FUNC 00047180 FUN_180047180 (463 bytes) ---- */

undefined8 *
FUN_180047180(undefined8 *param_1,undefined8 param_2,undefined8 *param_3,undefined8 *param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  size_t _Size;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  void *pvVar7;
  
  pvVar7 = (void *)0x0;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  _Size = param_3[2];
  uVar3 = param_4[2];
  uVar2 = uVar3 + _Size;
  if ((param_3[3] - _Size < uVar3) || ((ulonglong)param_3[3] < (ulonglong)param_4[3])) {
    if (param_4[3] - uVar3 < _Size) {
      if (0x7fffffffffffffff - _Size < uVar3) {
                    /* WARNING: Subroutine does not return */
        FUN_180002780();
      }
      uVar6 = uVar2 | 0xf;
      if (uVar6 < 0x8000000000000000) {
        if (uVar6 < 0x16) {
          uVar6 = 0x16;
        }
        uVar1 = uVar6 + 1;
        if (uVar1 < 0x1000) {
          if (uVar1 != 0) {
            pvVar7 = operator_new(uVar1);
          }
        }
        else {
          pvVar7 = (void *)FUN_180001160(uVar1);
        }
      }
      else {
        pvVar7 = (void *)FUN_180001160(0x8000000000000000);
        uVar6 = 0x7fffffffffffffff;
      }
      *param_1 = pvVar7;
      param_1[2] = uVar2;
      param_1[3] = uVar6;
      if (0xf < (ulonglong)param_3[3]) {
        param_3 = (undefined8 *)*param_3;
      }
      memcpy(pvVar7,param_3,_Size);
      if (0xf < (ulonglong)param_4[3]) {
        param_4 = (undefined8 *)*param_4;
      }
      memcpy((void *)((longlong)pvVar7 + _Size),param_4,uVar3 + 1);
    }
    else {
      uVar4 = param_4[1];
      *param_1 = *param_4;
      param_1[1] = uVar4;
      uVar4 = param_4[3];
      param_1[2] = param_4[2];
      param_1[3] = uVar4;
      param_4[2] = 0;
      param_4[3] = 0xf;
      *(undefined1 *)param_4 = 0;
      pvVar7 = (void *)*param_1;
      memmove((void *)((longlong)pvVar7 + _Size),pvVar7,uVar3 + 1);
      if (0xf < (ulonglong)param_3[3]) {
        param_3 = (undefined8 *)*param_3;
      }
      memcpy(pvVar7,param_3,_Size);
      param_1[2] = uVar2;
    }
  }
  else {
    uVar4 = param_3[1];
    *param_1 = *param_3;
    param_1[1] = uVar4;
    uVar4 = param_3[3];
    param_1[2] = param_3[2];
    param_1[3] = uVar4;
    param_3[2] = 0;
    param_3[3] = 0xf;
    *(undefined1 *)param_3 = 0;
    puVar5 = param_1;
    if (0xf < (ulonglong)param_1[3]) {
      puVar5 = (undefined8 *)*param_1;
    }
    if (0xf < (ulonglong)param_4[3]) {
      param_4 = (undefined8 *)*param_4;
    }
    memcpy((void *)((longlong)puVar5 + _Size),param_4,uVar3 + 1);
    param_1[2] = uVar2;
  }
  return param_1;
}

/* ---- FUNC 00047350 FUN_180047350 (22 bytes) ---- */

undefined8 * FUN_180047350(undefined8 *param_1)

{
  param_1[3] = 0;
  *param_1 = CEnumVariant::vftable;
  return param_1;
}

/* ---- FUNC 00047370 FUN_180047370 (82 bytes) ---- */

undefined8 * FUN_180047370(undefined8 *param_1)

{
  *param_1 = CHNodeCol::vftable;
  FUN_1800212f0(param_1 + 2,param_1,&DAT_180063400);
  *(undefined4 *)(param_1 + 1) = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  return param_1;
}

/* ---- FUNC 000473D0 FUN_1800473d0 (27 bytes) ---- */

void FUN_1800473d0(undefined8 *param_1)

{
  *param_1 = CEnumVariant::vftable;
  if ((SAFEARRAY *)param_1[3] != (SAFEARRAY *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001800473e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    SafeArrayDestroy((SAFEARRAY *)param_1[3]);
    return;
  }
  return;
}

/* ---- FUNC 000473F0 FUN_1800473f0 (123 bytes) ---- */

void FUN_1800473f0(undefined8 *param_1)

{
  *param_1 = CHNodeCol::vftable;
  if ((DAT_180079d40 != (longlong *)0x0) && (DAT_180079d48 != 0)) {
    (**(code **)(*DAT_180079d40 + 0x10))();
    DAT_180079d48 = DAT_180079d48 + -1;
    if (DAT_180079d48 == 0) {
      DAT_180079d40 = (longlong *)0x0;
    }
  }
  if ((BSTR)param_1[8] != (BSTR)0x0) {
    SysFreeString((BSTR)param_1[8]);
  }
  if ((BSTR)param_1[7] != (BSTR)0x0) {
    SysFreeString((BSTR)param_1[7]);
  }
  if ((BSTR)param_1[9] != (BSTR)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00018004745e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    SysFreeString((BSTR)param_1[9]);
    return;
  }
  return;
}

/* ---- FUNC 00047470 FUN_180047470 (1729 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */

ulonglong FUN_180047470(longlong *param_1,undefined8 *param_2,undefined8 *param_3,
                       undefined8 *param_4,undefined8 *param_5,undefined4 *param_6,
                       undefined8 *param_7)

{
  undefined1 *puVar1;
  ushort uVar2;
  undefined8 uVar3;
  code *pcVar4;
  IUnknownVtbl *pIVar5;
  IUnknownVtbl *pIVar6;
  LPCWSTR lpWideCharStr;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  HRESULT HVar12;
  uint uVar13;
  ulonglong uVar14;
  longlong lVar15;
  longlong lVar16;
  int iVar17;
  undefined1 *puVar18;
  undefined1 *puVar19;
  undefined1 *puVar20;
  undefined1 *puVar21;
  _struct_1720 *p_Var22;
  int *piVar23;
  _struct_1720 _Var24;
  int iVar25;
  undefined8 *puVar26;
  undefined1 auStack_208 [64];
  longlong local_1c8;
  undefined8 *local_1c0;
  VARIANTARG local_1b8;
  IUnknownVtbl *local_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 local_178;
  _union_1719 _Stack_170;
  undefined8 local_168;
  undefined8 local_158;
  _union_1719 _Stack_150;
  undefined8 local_148;
  undefined8 local_138;
  _union_1719 _Stack_130;
  undefined8 local_128;
  undefined4 local_118;
  ULONG UStack_114;
  undefined4 uStack_110;
  ULONG UStack_10c;
  undefined8 local_108;
  undefined1 local_f8 [8];
  _union_1719 a_Stack_f0 [2];
  _union_2707 local_e0;
  _union_2707 local_c8;
  _union_2707 local_b0;
  _union_2707 local_98;
  undefined8 local_78 [5];
  int local_50 [6];
  ulonglong local_38;
  
  puVar21 = auStack_208;
  local_38 = DAT_180077818 ^ (ulonglong)&local_1c8;
  *param_7 = 0;
  if (DAT_1800797f8 == 0) {
    local_1c8 = 0;
    if (*(longlong *)(param_1[0x10] + 0x48) == 0) {
      uVar14 = (**(code **)(*param_1 + 0x108))(param_1,0x7d9);
    }
    else {
      VariantInit((VARIANTARG *)&((_union_2707 *)local_f8)->n2);
      local_78[0] = 0;
      VariantInit((VARIANTARG *)((longlong)local_f8 + 0x18));
      local_78[1] = 0;
      VariantInit((VARIANTARG *)((longlong)local_f8 + 0x30));
      local_78[2] = 0;
      VariantInit((VARIANTARG *)((longlong)local_f8 + 0x48));
      local_78[3] = 0;
      VariantInit((VARIANTARG *)&local_98.n2);
      puVar26 = local_78;
      iVar25 = 0;
      local_f8 = (undefined1  [8])*param_2;
      a_Stack_f0[0] = *(_union_1719 *)(param_2 + 1);
      p_Var22 = (_struct_1720 *)&(((_union_2707 *)local_f8)->decVal).u2;
      local_78[4] = 0;
      a_Stack_f0[1] = (_union_1719)param_2[2];
      piVar23 = local_50;
      local_e0._0_8_ = *param_3;
      local_e0.decVal.u2 = *(_union_1719 *)(param_3 + 1);
      local_e0._16_8_ = param_3[2];
      local_c8._0_8_ = *param_4;
      local_c8.decVal.u2 = *(_union_1719 *)(param_4 + 1);
      local_c8._16_8_ = param_4[2];
      local_b0._0_8_ = *param_5;
      local_b0.decVal.u2 = *(_union_1719 *)(param_5 + 1);
      local_b0._16_8_ = param_5[2];
      local_98._0_4_ = *param_6;
      local_98.decVal.Hi32 = param_6[1];
      local_98._8_4_ = param_6[2];
      local_98._12_4_ = param_6[3];
      local_98._16_8_ = *(undefined8 *)(param_6 + 4);
      puVar21 = auStack_208;
      do {
        uVar2 = *(ushort *)&p_Var22[-1].Lo32;
        if (uVar2 < 0xb) {
          if ((uVar2 == 10) || (uVar2 == 0)) {
            *piVar23 = -1;
            *puVar26 = 0;
          }
          else if (uVar2 == 2) {
            *piVar23 = (int)*(short *)&p_Var22->Lo32;
          }
          else if (uVar2 == 3) {
            *piVar23 = p_Var22->Lo32;
          }
          else {
            if (uVar2 != 8) goto LAB_180047744;
            _Var24 = *p_Var22;
            *piVar23 = -1;
            if (_Var24 == (_struct_1720)0x0) goto LAB_1800478c0;
            lVar15 = -1;
            do {
              lVar15 = lVar15 + 1;
            } while (*(short *)((longlong)_Var24 + lVar15 * 2) != 0);
LAB_18004767b:
            iVar17 = (int)lVar15 + 1;
            puVar18 = (undefined1 *)0x0;
            puVar19 = puVar21;
            if (iVar17 < 0x40000000) {
              lVar15 = (longlong)(int)lVar15 * 2;
              uVar14 = lVar15 + 0x11;
              if (uVar14 <= lVar15 + 2U) {
                uVar14 = 0xffffffffffffff0;
              }
              *(undefined8 *)(puVar21 + -8) = 0x1800476a8;
              lVar15 = -(uVar14 & 0xfffffffffffffff0);
              puVar1 = puVar21 + lVar15 + 0x40;
              puVar19 = puVar21 + lVar15;
              if (puVar1 != (undefined1 *)0x0) {
                *(undefined8 *)(puVar21 + lVar15 + 0x38) = 0;
                *(undefined8 *)(puVar21 + lVar15 + 0x30) = 0;
                *(int *)(puVar21 + lVar15 + 0x28) = iVar17 * 2;
                *puVar1 = 0;
                *(undefined1 **)(puVar21 + lVar15 + 0x20) = puVar1;
                *(undefined8 *)(puVar21 + lVar15 + -8) = 0x1800476dc;
                iVar17 = WideCharToMultiByte(0,0,(LPCWSTR)_Var24,-1,
                                             *(LPSTR *)(puVar21 + lVar15 + 0x20),
                                             *(int *)(puVar21 + lVar15 + 0x28),
                                             *(LPCSTR *)(puVar21 + lVar15 + 0x30),
                                             *(LPBOOL *)(puVar21 + lVar15 + 0x38));
                puVar18 = puVar1;
                puVar19 = puVar21 + lVar15;
                if (iVar17 == 0) {
                  puVar18 = (undefined1 *)0x0;
                  puVar19 = puVar21 + lVar15;
                }
              }
            }
            puVar21 = puVar19;
            *puVar26 = puVar18;
            if (puVar18 == (undefined1 *)0x0) goto LAB_1800478c3;
          }
        }
        else {
          if (uVar2 == 0x4002) {
            iVar17 = (int)*(short *)*p_Var22;
          }
          else {
            if (uVar2 != 0x4003) {
              if (uVar2 == 0x4008) {
                _Var24 = *p_Var22;
                *piVar23 = -1;
                _Var24 = *(_struct_1720 *)_Var24;
                if (_Var24 != (_struct_1720)0x0) {
                  lVar15 = -1;
                  do {
                    lVar15 = lVar15 + 1;
                  } while (*(short *)((longlong)_Var24 + lVar15 * 2) != 0);
                  goto LAB_18004767b;
                }
LAB_1800478c0:
                *puVar26 = 0;
                goto LAB_1800478c3;
              }
              if (uVar2 == 0x400c) {
                lVar16 = (longlong)iVar25;
                *(undefined8 **)(puVar21 + 0x30) = param_7;
                puVar26 = *(undefined8 **)((longlong)local_f8 + lVar16 * 0x18 + 8);
                uVar3 = puVar26[1];
                *(undefined8 *)((_union_2707 *)local_f8 + lVar16) = *puVar26;
                *(undefined8 *)((longlong)local_f8 + lVar16 * 0x18 + 8) = uVar3;
                lVar15 = *param_1;
                *(undefined8 *)((longlong)local_f8 + lVar16 * 0x18 + 0x10) = puVar26[2];
                uVar11 = local_98._16_8_;
                uVar10 = local_b0.decVal.u2;
                uVar9 = local_b0._0_8_;
                local_198 = CONCAT44(local_98.decVal.Hi32,local_98._0_4_);
                uStack_190 = CONCAT44(local_98._12_4_,local_98._8_4_);
                *(undefined8 **)(puVar21 + 0x28) = &local_198;
                uVar8 = local_c8._16_8_;
                uVar7 = local_e0.decVal.u2;
                uVar3 = local_e0._0_8_;
                local_188 = uVar11;
                local_178 = uVar9;
                _Stack_170 = (_union_1719)uVar10;
                local_168 = local_b0._16_8_;
                local_158 = local_c8._0_8_;
                _Stack_150 = local_c8.decVal.u2;
                *(undefined8 **)(puVar21 + 0x20) = &local_178;
                local_148 = uVar8;
                local_138 = uVar3;
                _Stack_130 = (_union_1719)uVar7;
                local_128 = local_e0._16_8_;
                local_118 = local_f8._0_4_;
                UStack_114 = local_f8._4_4_;
                uStack_110 = a_Stack_f0[0]._0_4_;
                UStack_10c = a_Stack_f0[0]._4_4_;
                local_108 = a_Stack_f0[1];
                pcVar4 = *(code **)(lVar15 + 0xc0);
                *(undefined8 *)(puVar21 + -8) = 0x1800479d0;
                uVar14 = (*pcVar4)(param_1,&local_118,&local_138,&local_158);
              }
              else {
LAB_180047744:
                *(undefined8 *)(puVar21 + -8) = 0x18004774e;
                VariantInit(&local_1b8);
                *(undefined8 *)(puVar21 + -8) = 0x180047776;
                HVar12 = VariantChangeType(&local_1b8,
                                           (VARIANTARG *)((_union_2707 *)local_f8 + iVar25),0,3);
                if (HVar12 == 0) {
                  *piVar23 = local_1b8.n1._8_4_;
                  *(undefined8 *)(puVar21 + -8) = 0x180047789;
                  VariantClear(&local_1b8);
                  goto LAB_18004789f;
                }
                *(undefined8 *)(puVar21 + -8) = 0x180047794;
                VariantClear(&local_1b8);
                *(undefined8 *)(puVar21 + -8) = 0x1800477aa;
                HVar12 = VariantChangeType(&local_1b8,
                                           (VARIANTARG *)((_union_2707 *)local_f8 + iVar25),0,8);
                if (HVar12 == 0) {
                  lpWideCharStr = (LPCWSTR)CONCAT44(local_1b8.n1._12_4_,local_1b8.n1._8_4_);
                  *piVar23 = -1;
                  if (lpWideCharStr == (LPCWSTR)0x0) {
                    *puVar26 = 0;
                  }
                  else {
                    lVar15 = -1;
                    do {
                      lVar16 = lVar15;
                      lVar15 = lVar16 + 1;
                    } while (lpWideCharStr[lVar15] != L'\0');
                    iVar17 = (int)lVar16 + 2;
                    puVar18 = puVar21;
                    if (iVar17 < 0x40000000) {
                      lVar15 = (longlong)(int)lVar15 * 2;
                      uVar14 = lVar15 + 0x11;
                      if (uVar14 <= lVar15 + 2U) {
                        uVar14 = 0xffffffffffffff0;
                      }
                      *(undefined8 *)(puVar21 + -8) = 0x18004780f;
                      lVar15 = -(uVar14 & 0xfffffffffffffff0);
                      puVar18 = puVar21 + lVar15;
                      puVar20 = puVar21 + lVar15;
                      puVar19 = puVar21 + lVar15 + 0x40;
                      if (puVar19 == (undefined1 *)0x0) goto LAB_180047850;
                      *puVar19 = 0;
                      *(undefined8 *)(puVar21 + lVar15 + 0x38) = 0;
                      *(undefined8 *)(puVar21 + lVar15 + 0x30) = 0;
                      *(int *)(puVar21 + lVar15 + 0x28) = iVar17 * 2;
                      *(undefined1 **)(puVar21 + lVar15 + 0x20) = puVar19;
                      *(undefined8 *)(puVar21 + lVar15 + -8) = 0x180047843;
                      iVar17 = WideCharToMultiByte(0,0,lpWideCharStr,-1,
                                                   *(LPSTR *)(puVar21 + lVar15 + 0x20),
                                                   *(int *)(puVar21 + lVar15 + 0x28),
                                                   *(LPCSTR *)(puVar21 + lVar15 + 0x30),
                                                   *(LPBOOL *)(puVar21 + lVar15 + 0x38));
                      puVar21 = puVar21 + lVar15;
                      if (iVar17 == 0) {
                        puVar19 = (undefined1 *)0x0;
                        puVar21 = puVar20;
                      }
                    }
                    else {
LAB_180047850:
                      puVar19 = (undefined1 *)0x0;
                      puVar21 = puVar18;
                    }
                    *puVar26 = puVar19;
                    if (puVar19 != (undefined1 *)0x0) goto LAB_18004789f;
                  }
                }
                else {
                  *(undefined8 *)(puVar21 + -8) = 0x1800478ea;
                  VariantClear(&local_1b8);
                }
LAB_1800478c3:
                pcVar4 = *(code **)(*param_1 + 0x108);
                *(undefined8 *)(puVar21 + -8) = 0x1800478d4;
                uVar14 = (*pcVar4)(param_1,0x7db);
              }
              goto LAB_180047afc;
            }
            iVar17 = *(int *)*p_Var22;
          }
          *piVar23 = iVar17;
        }
LAB_18004789f:
        iVar25 = iVar25 + 1;
        puVar26 = puVar26 + 1;
        p_Var22 = p_Var22 + 3;
        piVar23 = piVar23 + 1;
      } while (iVar25 < 5);
      lVar15 = param_1[0x10];
      *(longlong **)(puVar21 + 0x20) = &local_1c8;
      uVar3 = *(undefined8 *)(lVar15 + 0x48);
      *(undefined8 *)(puVar21 + -8) = 0x180047a01;
      iVar25 = HACreateElement(uVar3,&local_1a0,local_50,local_78);
      if (iVar25 == -1) {
        if (local_1c8 == 0) {
          pcVar4 = *(code **)(*param_1 + 0x108);
          *(undefined8 *)(puVar21 + -8) = 0x180047a2b;
          uVar14 = (*pcVar4)(param_1,0x7d1);
        }
        else {
          pcVar4 = *(code **)(*param_1 + 0x100);
          *(undefined8 *)(puVar21 + -8) = 0x180047a1b;
          uVar14 = (*pcVar4)();
        }
      }
      else {
        pIVar5 = (IUnknownVtbl *)param_1[0x10];
        pIVar6 = (IUnknownVtbl *)param_1[0xf];
        *(_func_5158 **)(puVar21 + 0x28) = pIVar5->Release;
        *(undefined4 *)(puVar21 + 0x20) = 0;
        *(undefined8 *)(puVar21 + -8) = 0x180047a57;
        FUN_1800387d0(local_1a0,(longlong *)&local_1c0,pIVar6,pIVar5,*(int *)(puVar21 + 0x20),
                      *(IUnknownVtbl **)(puVar21 + 0x28));
        puVar26 = local_1c0;
        if (local_1c0 == (undefined8 *)0x0) {
          DAT_1800797d4 = DAT_1800797d4 + 1;
          pcVar4 = *(code **)(param_1[0x10] + 0x10);
          if (pcVar4 != (code *)0x0) {
            *(undefined8 *)(puVar21 + -8) = 0x180047a78;
            (*pcVar4)();
          }
          pcVar4 = *(code **)(*param_1 + 0x108);
          *(undefined8 *)(puVar21 + -8) = 0x180047a89;
          uVar14 = (*pcVar4)(param_1,0x7d1);
        }
        else {
          pcVar4 = *(code **)*local_1c0;
          *(undefined8 *)(puVar21 + -8) = 0x180047a9a;
          uVar13 = (*pcVar4)(puVar26,&DAT_180063400,param_7);
          DAT_1800797d4 = DAT_1800797d4 + 1;
          uVar14 = (ulonglong)uVar13;
          if ((int)uVar13 < 0) {
            if (local_1c0 != (undefined8 *)0x0) {
              *(undefined8 *)(puVar21 + -8) = 0x180047ab7;
              FUN_180037ee0(local_1c0);
              *(undefined8 *)(puVar21 + -8) = 0x180047ac4;
              FUN_180025ad0(local_1c0);
            }
            pcVar4 = *(code **)(param_1[0x10] + 0x10);
            if (pcVar4 != (code *)0x0) {
              *(undefined8 *)(puVar21 + -8) = 0x180047ad6;
              (*pcVar4)();
            }
          }
          *(undefined4 *)(param_1[0xf] + 0x100) = 1;
          uVar3 = *(undefined8 *)(param_1[0x10] + 0x48);
          *(undefined8 *)(puVar21 + -8) = 0x180047afa;
          HANotify(uVar3,2);
        }
      }
    }
  }
  else {
    uVar14 = (**(code **)(*param_1 + 0x108))(param_1,0x7f3);
    puVar21 = auStack_208;
  }
LAB_180047afc:
  *(undefined8 *)(puVar21 + -8) = 0x180047b0b;
  return uVar14;
}

/* ---- FUNC 00047B40 FUN_180047b40 (14 bytes) ---- */

void FUN_180047b40(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180047b4a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(longlong **)(param_1 + 0x80) + 8))();
  return;
}

/* ---- FUNC 00047B50 FUN_180047b50 (129 bytes) ---- */

HRESULT FUN_180047b50(longlong param_1,undefined8 *param_2)

{
  longlong *plVar1;
  HRESULT HVar2;
  longlong *local_res8;
  
  *param_2 = 0;
  local_res8 = (longlong *)0x0;
  HVar2 = FUN_180047be0(*(SAFEARRAY **)(param_1 + 0x18),*(undefined4 *)(param_1 + 0xc),&local_res8);
  plVar1 = local_res8;
  if (HVar2 < 0) {
    if (local_res8 != (longlong *)0x0) {
      (**(code **)(*local_res8 + 0x10))();
    }
    return HVar2;
  }
  (**(code **)(*local_res8 + 8))(local_res8);
  *(undefined4 *)((longlong)plVar1 + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *param_2 = plVar1;
  return 0;
}

/* ---- FUNC 00047BE0 FUN_180047be0 (77 bytes) ---- */

HRESULT FUN_180047be0(SAFEARRAY *param_1,undefined4 param_2,undefined8 *param_3)

{
  SAFEARRAY *psa;
  HRESULT HVar1;
  undefined8 *puVar2;
  LONG local_res18 [2];
  undefined8 *local_res20;
  
  *param_3 = 0;
  local_res20 = operator_new(0x20);
  if ((local_res20 != (undefined8 *)0x0) &&
     (puVar2 = FUN_180047350(local_res20), puVar2 != (undefined8 *)0x0)) {
    *(undefined4 *)(puVar2 + 1) = 0;
    HVar1 = SafeArrayGetLBound(param_1,1,local_res18);
    if (-1 < HVar1) {
      *(undefined4 *)((longlong)puVar2 + 0xc) = param_2;
      *(LONG *)(puVar2 + 2) = local_res18[0];
      *(LONG *)((longlong)puVar2 + 0x14) = local_res18[0];
      HVar1 = SafeArrayCopy(param_1,(SAFEARRAY **)(puVar2 + 3));
      if (-1 < HVar1) {
        *param_3 = puVar2;
        return 0;
      }
    }
    psa = (SAFEARRAY *)puVar2[3];
    if (psa != (SAFEARRAY *)0x0) {
      SafeArrayDestroy(psa);
    }
    puVar2[3] = 0;
    FUN_1800473d0(puVar2);
    FUN_180025ad0(puVar2);
    return HVar1;
  }
  return -0x7ff8fff2;
}

/* ---- FUNC 00047C2D FUN_180047c2d (95 bytes) ---- */

HRESULT FUN_180047c2d(undefined8 param_1,undefined8 param_2,LONG *param_3)

{
  SAFEARRAY *psa;
  HRESULT HVar1;
  longlong in_RAX;
  undefined8 *unaff_RBX;
  SAFEARRAY *unaff_RBP;
  undefined4 unaff_EDI;
  undefined8 *unaff_R14;
  undefined4 in_stack_00000050;
  
  *(undefined4 *)(in_RAX + 8) = 0;
  HVar1 = SafeArrayGetLBound(unaff_RBP,1,param_3);
  if (-1 < HVar1) {
    *(undefined4 *)((longlong)unaff_RBX + 0xc) = unaff_EDI;
    *(undefined4 *)(unaff_RBX + 2) = in_stack_00000050;
    *(undefined4 *)((longlong)unaff_RBX + 0x14) = in_stack_00000050;
    HVar1 = SafeArrayCopy(unaff_RBP,(SAFEARRAY **)(unaff_RBX + 3));
    if (-1 < HVar1) {
      *unaff_R14 = unaff_RBX;
      return 0;
    }
  }
  psa = (SAFEARRAY *)unaff_RBX[3];
  if (psa != (SAFEARRAY *)0x0) {
    SafeArrayDestroy(psa);
  }
  unaff_RBX[3] = 0;
  FUN_1800473d0(unaff_RBX);
  FUN_180025ad0(unaff_RBX);
  return HVar1;
}

/* ---- FUNC 00047C8C FUN_180047c8c (50 bytes) ---- */

undefined4 FUN_180047c8c(void)

{
  SAFEARRAY *psa;
  undefined8 *unaff_RBX;
  undefined4 unaff_ESI;
  
  psa = (SAFEARRAY *)unaff_RBX[3];
  if (psa != (SAFEARRAY *)0x0) {
    SafeArrayDestroy(psa);
  }
  unaff_RBX[3] = 0;
  FUN_1800473d0(unaff_RBX);
  FUN_180025ad0(unaff_RBX);
  return unaff_ESI;
}

/* ---- FUNC 00047CBE FUN_180047cbe (19 bytes) ---- */

undefined8 FUN_180047cbe(void)

{
  return 0x8007000e;
}

/* ---- FUNC 00047CE0 FUN_180047ce0 (164 bytes) ---- */

HRESULT FUN_180047ce0(undefined8 param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
  HRESULT HVar1;
  undefined8 *puVar2;
  
  puVar2 = operator_new(0x88);
  if (puVar2 == (undefined8 *)0x0) {
    puVar2 = (undefined8 *)0x0;
  }
  else {
    puVar2 = FUN_180047370(puVar2);
  }
  if (DAT_180079d48 == 0) {
    HVar1 = FUN_180033ad0(&DAT_180079d40,(GUID *)&DAT_180063410);
    if (HVar1 < 0) {
      return HVar1;
    }
  }
  else {
    (**(code **)(*DAT_180079d40 + 8))();
  }
  DAT_180079d48 = DAT_180079d48 + 1;
  puVar2[0xf] = param_3;
  puVar2[0x10] = param_4;
  *param_2 = puVar2;
  return 0;
}

/* ---- FUNC 00047D90 FUN_180047d90 (28 bytes) ---- */

void FUN_180047d90(undefined8 param_1,undefined8 param_2,OLECHAR **param_3,UINT param_4,
                  undefined8 param_5,DISPID *param_6)

{
                    /* WARNING: Could not recover jumptable at 0x000180047da5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DispGetIDsOfNames(DAT_180079d40,param_3,param_4,param_6);
  return;
}

/* ---- FUNC 00047DB0 FUN_180047db0 (62 bytes) ---- */

undefined8 FUN_180047db0(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  *param_4 = 0;
  if (param_2 != 0) {
    return 0x8002000b;
  }
  (**(code **)(*DAT_180079d40 + 8))();
  *param_4 = DAT_180079d40;
  return 0;
}

/* ---- FUNC 00047DF0 FUN_180047df0 (1684 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */

undefined8
FUN_180047df0(longlong *param_1,longlong *param_2,ushort *param_3,undefined8 *param_4,
             undefined8 *param_5,undefined8 *param_6,undefined4 *param_7)

{
  undefined1 *puVar1;
  ushort uVar2;
  LPCWSTR pWVar3;
  BSTR *ppOVar4;
  code *pcVar5;
  undefined8 uVar6;
  longlong *plVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  HRESULT HVar12;
  undefined8 uVar13;
  longlong lVar14;
  longlong lVar15;
  ulonglong uVar16;
  int iVar17;
  undefined1 *puVar18;
  undefined1 *puVar19;
  undefined1 *puVar20;
  _union_2709 *p_Var21;
  int *piVar22;
  int iVar23;
  undefined8 *puVar24;
  undefined1 auStack_218 [64];
  int local_1d8 [2];
  longlong *local_1d0;
  longlong local_1c8;
  VARIANTARG local_1c0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 local_188;
  _union_1719 _Stack_180;
  undefined8 local_178;
  undefined8 local_168;
  _union_1719 _Stack_160;
  undefined8 local_158;
  undefined8 local_148;
  _union_1719 _Stack_140;
  undefined8 local_138;
  undefined4 local_128;
  ULONG UStack_124;
  undefined4 uStack_120;
  ULONG UStack_11c;
  undefined8 local_118;
  undefined1 local_108 [16];
  undefined8 local_f8;
  _union_2707 local_f0;
  _union_2707 local_d8;
  _union_2707 local_c0;
  _union_2707 local_a8;
  undefined8 local_88 [5];
  int local_60 [6];
  ulonglong local_48;
  
  puVar20 = auStack_218;
  local_48 = DAT_180077818 ^ (ulonglong)local_1d8;
  local_1c8 = 0;
  local_1d0 = param_2;
  if (DAT_1800797f8 == 0) {
    if (*(longlong *)(param_1[0x10] + 0x48) == 0) {
      uVar13 = (**(code **)(*param_1 + 0x108))(param_1,0x7d9);
    }
    else {
      VariantInit((VARIANTARG *)&((_union_2707 *)local_108)->n2);
      local_88[0] = 0;
      VariantInit((VARIANTARG *)((longlong)local_108 + 0x18));
      local_88[1] = 0;
      VariantInit((VARIANTARG *)((longlong)local_108 + 0x30));
      local_88[2] = 0;
      VariantInit((VARIANTARG *)((longlong)local_108 + 0x48));
      local_88[3] = 0;
      VariantInit((VARIANTARG *)&local_a8.n2);
      p_Var21 = &(((_union_2707 *)local_108)->n2).n3;
      puVar24 = local_88;
      uVar2 = *param_3;
      iVar23 = 0;
      local_108._0_8_ = *(undefined8 *)param_3;
      local_108._8_8_ = *(_union_1719 *)(param_3 + 4);
      local_88[4] = 0;
      local_f8 = *(undefined8 *)(param_3 + 8);
      piVar22 = local_60;
      local_f0._0_8_ = *param_4;
      local_f0.decVal.u2 = *(_union_1719 *)(param_4 + 1);
      local_f0._16_8_ = param_4[2];
      local_d8._0_8_ = *param_5;
      local_d8.decVal.u2 = *(_union_1719 *)(param_5 + 1);
      local_d8._16_8_ = param_5[2];
      local_c0._0_8_ = *param_6;
      local_c0.decVal.u2 = *(_union_1719 *)(param_6 + 1);
      local_c0._16_8_ = param_6[2];
      local_a8._0_4_ = *param_7;
      local_a8.decVal.Hi32 = param_7[1];
      local_a8._8_4_ = param_7[2];
      local_a8._12_4_ = param_7[3];
      local_a8._16_8_ = *(undefined8 *)(param_7 + 4);
      puVar20 = auStack_218;
      do {
        plVar7 = local_1d0;
        puVar18 = (undefined1 *)0x0;
        puVar19 = puVar20;
        if (uVar2 < 0xb) {
          if ((uVar2 == 10) || (uVar2 == 0)) {
            *puVar24 = 0;
          }
          else if (uVar2 != 2) {
            if (uVar2 != 3) {
              if (uVar2 != 8) goto LAB_1800480a2;
              pWVar3 = p_Var21->bstrVal;
              *piVar22 = -1;
              if (pWVar3 != (LPCWSTR)0x0) {
                lVar14 = -1;
                do {
                  lVar15 = lVar14;
                  lVar14 = lVar15 + 1;
                } while (pWVar3[lVar14] != L'\0');
                iVar17 = (int)lVar15 + 2;
                if (iVar17 < 0x40000000) {
                  lVar14 = (longlong)(int)lVar14 * 2;
                  uVar16 = lVar14 + 0x11;
                  if (uVar16 <= lVar14 + 2U) {
                    uVar16 = 0xffffffffffffff0;
                  }
                  *(undefined8 *)(puVar20 + -8) = 0x18004800d;
                  lVar14 = -(uVar16 & 0xfffffffffffffff0);
                  puVar1 = puVar20 + lVar14 + 0x40;
                  puVar19 = puVar20 + lVar14;
                  if (puVar1 != (undefined1 *)0x0) {
                    *(undefined8 *)(puVar20 + lVar14 + 0x38) = 0;
                    *(undefined8 *)(puVar20 + lVar14 + 0x30) = 0;
                    *(int *)(puVar20 + lVar14 + 0x28) = iVar17 * 2;
                    *puVar1 = 0;
                    *(undefined1 **)(puVar20 + lVar14 + 0x20) = puVar1;
                    *(undefined8 *)(puVar20 + lVar14 + -8) = 0x180048041;
                    iVar17 = WideCharToMultiByte(0,0,pWVar3,-1,*(LPSTR *)(puVar20 + lVar14 + 0x20),
                                                 *(int *)(puVar20 + lVar14 + 0x28),
                                                 *(LPCSTR *)(puVar20 + lVar14 + 0x30),
                                                 *(LPBOOL *)(puVar20 + lVar14 + 0x38));
                    puVar18 = puVar1;
                    puVar19 = puVar20 + lVar14;
                    if (iVar17 == 0) {
                      puVar18 = (undefined1 *)0x0;
                      puVar19 = puVar20 + lVar14;
                    }
                  }
                }
                goto LAB_180048051;
              }
LAB_180048293:
              *puVar24 = 0;
              goto LAB_180048296;
            }
            *piVar22 = p_Var21->lVal;
            goto LAB_180048272;
          }
          *piVar22 = (int)p_Var21->iVal;
        }
        else {
          if (uVar2 == 0x4002) {
            iVar17 = (int)*p_Var21->bstrVal;
          }
          else {
            if (uVar2 != 0x4003) {
              if (uVar2 == 0x4008) {
                ppOVar4 = p_Var21->pbstrVal;
                *piVar22 = -1;
                pWVar3 = *ppOVar4;
                if (pWVar3 == (LPCWSTR)0x0) goto LAB_180048293;
                lVar14 = -1;
                do {
                  lVar15 = lVar14;
                  lVar14 = lVar15 + 1;
                } while (pWVar3[lVar14] != L'\0');
                iVar17 = (int)lVar15 + 2;
                if (iVar17 < 0x40000000) {
                  lVar14 = (longlong)(int)lVar14 * 2;
                  uVar16 = lVar14 + 0x11;
                  if (uVar16 <= lVar14 + 2U) {
                    uVar16 = 0xffffffffffffff0;
                  }
                  *(undefined8 *)(puVar20 + -8) = 0x18004821b;
                  lVar14 = -(uVar16 & 0xfffffffffffffff0);
                  puVar19 = puVar20 + lVar14;
                  puVar1 = puVar20 + lVar14 + 0x40;
                  if (puVar1 != (undefined1 *)0x0) {
                    *(undefined8 *)(puVar20 + lVar14 + 0x38) = 0;
                    *(undefined8 *)(puVar20 + lVar14 + 0x30) = 0;
                    *(int *)(puVar20 + lVar14 + 0x28) = iVar17 * 2;
                    *puVar1 = 0;
                    *(undefined1 **)(puVar20 + lVar14 + 0x20) = puVar1;
                    *(undefined8 *)(puVar20 + lVar14 + -8) = 0x180048253;
                    iVar17 = WideCharToMultiByte(0,0,pWVar3,-1,*(LPSTR *)(puVar20 + lVar14 + 0x20),
                                                 *(int *)(puVar20 + lVar14 + 0x28),
                                                 *(LPCSTR *)(puVar20 + lVar14 + 0x30),
                                                 *(LPBOOL *)(puVar20 + lVar14 + 0x38));
                    puVar18 = puVar1;
                    puVar19 = puVar20 + lVar14;
                    if (iVar17 == 0) {
                      puVar18 = (undefined1 *)0x0;
                      puVar19 = puVar20 + lVar14;
                    }
                  }
                }
LAB_180048051:
                *puVar24 = puVar18;
                puVar20 = puVar19;
joined_r0x0001800481ba:
                if (puVar18 != (undefined1 *)0x0) goto LAB_180048272;
              }
              else {
                if (uVar2 == 0x400c) {
                  lVar15 = (longlong)iVar23;
                  puVar24 = *(undefined8 **)((longlong)local_108 + lVar15 * 0x18 + 8);
                  uVar13 = puVar24[1];
                  *(undefined8 *)((_union_2707 *)local_108 + lVar15) = *puVar24;
                  *(undefined8 *)((longlong)local_108 + lVar15 * 0x18 + 8) = uVar13;
                  lVar14 = *param_1;
                  *(undefined8 *)((longlong)local_108 + lVar15 * 0x18 + 0x10) = puVar24[2];
                  uVar11 = local_a8._16_8_;
                  uVar13 = CONCAT44(local_a8.decVal.Hi32,local_a8._0_4_);
                  uVar6 = CONCAT44(local_a8._12_4_,local_a8._8_4_);
                  *(undefined8 **)(puVar20 + 0x30) = &local_1a8;
                  uVar10 = local_c0.decVal.u2;
                  uVar9 = local_c0._0_8_;
                  local_1a8 = uVar13;
                  uStack_1a0 = uVar6;
                  *(undefined8 **)(puVar20 + 0x28) = &local_188;
                  uVar8 = local_d8._16_8_;
                  uVar6 = local_f0.decVal.u2;
                  uVar13 = local_f0._0_8_;
                  local_198 = uVar11;
                  local_188 = uVar9;
                  _Stack_180 = (_union_1719)uVar10;
                  local_178 = local_c0._16_8_;
                  local_168 = local_d8._0_8_;
                  _Stack_160 = local_d8.decVal.u2;
                  *(undefined8 **)(puVar20 + 0x20) = &local_168;
                  local_158 = uVar8;
                  local_148 = uVar13;
                  _Stack_140 = (_union_1719)uVar6;
                  local_138 = local_f0._16_8_;
                  local_128 = local_108._0_4_;
                  UStack_124 = local_108._4_4_;
                  uStack_120 = local_108._8_4_;
                  UStack_11c = local_108._12_4_;
                  local_118 = local_f8;
                  pcVar5 = *(code **)(lVar14 + 200);
                  *(undefined8 *)(puVar20 + -8) = 0x1800483a7;
                  uVar13 = (*pcVar5)(param_1,plVar7,&local_128,&local_148);
                  goto LAB_18004845b;
                }
LAB_1800480a2:
                *(undefined8 *)(puVar20 + -8) = 0x1800480ac;
                VariantInit(&local_1c0);
                *(undefined8 *)(puVar20 + -8) = 0x1800480d4;
                HVar12 = VariantChangeType(&local_1c0,
                                           (VARIANTARG *)((_union_2707 *)local_108 + iVar23),0,3);
                if (HVar12 == 0) {
                  *piVar22 = local_1c0.n1._8_4_;
                  *(undefined8 *)(puVar20 + -8) = 0x1800480e7;
                  VariantClear(&local_1c0);
                  goto LAB_180048272;
                }
                *(undefined8 *)(puVar20 + -8) = 0x1800480f2;
                VariantClear(&local_1c0);
                *(undefined8 *)(puVar20 + -8) = 0x180048108;
                HVar12 = VariantChangeType(&local_1c0,
                                           (VARIANTARG *)((_union_2707 *)local_108 + iVar23),0,8);
                if (HVar12 == 0) {
                  pWVar3 = (LPCWSTR)CONCAT44(local_1c0.n1._12_4_,local_1c0.n1._8_4_);
                  *piVar22 = -1;
                  if (pWVar3 != (LPCWSTR)0x0) {
                    lVar14 = -1;
                    do {
                      lVar15 = lVar14;
                      lVar14 = lVar15 + 1;
                    } while (pWVar3[lVar14] != L'\0');
                    iVar17 = (int)lVar15 + 2;
                    if (iVar17 < 0x40000000) {
                      lVar14 = (longlong)(int)lVar14 * 2;
                      uVar16 = lVar14 + 0x11;
                      if (uVar16 <= lVar14 + 2U) {
                        uVar16 = 0xffffffffffffff0;
                      }
                      *(undefined8 *)(puVar20 + -8) = 0x18004816f;
                      lVar14 = -(uVar16 & 0xfffffffffffffff0);
                      puVar19 = puVar20 + lVar14;
                      puVar18 = puVar20 + lVar14 + 0x40;
                      if (puVar18 == (undefined1 *)0x0) goto LAB_1800481b0;
                      *puVar18 = 0;
                      *(undefined8 *)(puVar20 + lVar14 + 0x38) = 0;
                      *(undefined8 *)(puVar20 + lVar14 + 0x30) = 0;
                      *(int *)(puVar20 + lVar14 + 0x28) = iVar17 * 2;
                      *(undefined1 **)(puVar20 + lVar14 + 0x20) = puVar18;
                      *(undefined8 *)(puVar20 + lVar14 + -8) = 0x1800481a3;
                      iVar17 = WideCharToMultiByte(0,0,pWVar3,-1,*(LPSTR *)(puVar20 + lVar14 + 0x20)
                                                   ,*(int *)(puVar20 + lVar14 + 0x28),
                                                   *(LPCSTR *)(puVar20 + lVar14 + 0x30),
                                                   *(LPBOOL *)(puVar20 + lVar14 + 0x38));
                      puVar19 = puVar20 + lVar14;
                      if (iVar17 == 0) {
                        puVar18 = (undefined1 *)0x0;
                        puVar19 = puVar20 + lVar14;
                      }
                    }
                    else {
LAB_1800481b0:
                      puVar18 = (undefined1 *)0x0;
                    }
                    *puVar24 = puVar18;
                    puVar20 = puVar19;
                    goto joined_r0x0001800481ba;
                  }
                  *puVar24 = 0;
                }
                else {
                  *(undefined8 *)(puVar20 + -8) = 0x1800482bd;
                  VariantClear(&local_1c0);
                }
              }
LAB_180048296:
              pcVar5 = *(code **)(*param_1 + 0x108);
              *(undefined8 *)(puVar20 + -8) = 0x1800482a7;
              uVar13 = (*pcVar5)(param_1,0x7db);
              goto LAB_18004845b;
            }
            iVar17 = *p_Var21->plVal;
          }
          *piVar22 = iVar17;
        }
LAB_180048272:
        plVar7 = local_1d0;
        iVar23 = iVar23 + 1;
        puVar24 = puVar24 + 1;
        p_Var21 = (_union_2709 *)(&p_Var21->lVal + 6);
        piVar22 = piVar22 + 1;
      } while (iVar23 < 5);
      pcVar5 = *(code **)(*local_1d0 + 8);
      *(undefined8 *)(puVar20 + -8) = 0x1800483b9;
      (*pcVar5)(plVar7);
      pcVar5 = *(code **)(*plVar7 + 0xd0);
      *(undefined8 *)(puVar20 + -8) = 0x1800483c9;
      (*pcVar5)(plVar7,local_1d8);
      *(undefined8 *)(puVar20 + -8) = 0x1800483cf;
      iVar23 = _getpid();
      if (local_1d8[0] == iVar23) {
        lVar14 = plVar7[9];
        pcVar5 = *(code **)(*plVar7 + 0x10);
        *(undefined8 *)(puVar20 + -8) = 0x1800483f7;
        (*pcVar5)(plVar7);
        lVar15 = param_1[0x10];
        *(longlong **)(puVar20 + 0x20) = &local_1c8;
        uVar13 = *(undefined8 *)(lVar15 + 0x48);
        *(undefined8 *)(puVar20 + -8) = 0x180048422;
        iVar23 = HAAddElement(uVar13,lVar14,local_60,local_88);
        if (iVar23 == -1) {
          if (local_1c8 == 0) {
            pcVar5 = *(code **)(*param_1 + 0x108);
            *(undefined8 *)(puVar20 + -8) = 0x180048449;
            uVar13 = (*pcVar5)(param_1,0x7d1);
          }
          else {
            pcVar5 = *(code **)(*param_1 + 0x100);
            *(undefined8 *)(puVar20 + -8) = 0x18004843c;
            uVar13 = (*pcVar5)();
          }
        }
        else {
          *(undefined4 *)(param_1[0xf] + 0x100) = 1;
          uVar13 = 0;
        }
      }
      else {
        pcVar5 = *(code **)(*plVar7 + 0x10);
        *(undefined8 *)(puVar20 + -8) = 0x1800483dd;
        (*pcVar5)();
        pcVar5 = *(code **)(*param_1 + 0x108);
        *(undefined8 *)(puVar20 + -8) = 0x1800483ee;
        uVar13 = (*pcVar5)(param_1,0x7e8);
      }
    }
  }
  else {
    uVar13 = (**(code **)(*param_1 + 0x108))(param_1,0x7f3);
    puVar20 = auStack_218;
  }
LAB_18004845b:
  *(undefined8 *)(puVar20 + -8) = 0x18004846a;
  return uVar13;
}

/* ---- FUNC 00048490 FUN_180048490 (201 bytes) ---- */

undefined8 FUN_180048490(longlong *param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0001800484af. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x108))(param_1,0x7f3);
    return uVar1;
  }
  if (*(longlong *)(param_1[0x10] + 0x48) == 0) {
                    /* WARNING: Could not recover jumptable at 0x0001800484d6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x108))(param_1,0x7d9);
    return uVar1;
  }
  lVar2 = HAInsertLocation();
  if (lVar2 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0001800484f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x100))(param_1,lVar2);
    return uVar1;
  }
  *(undefined4 *)(param_1[0xf] + 0x100) = 1;
  if (DAT_18007988c != 0) {
    DAT_180079890 = 1;
    return 0;
  }
  FUN_1800374c0(0x67,(longlong *)(param_1[0x10] + 0x1d8));
  FUN_180011410(*(longlong *)(param_1[0x10] + 0x50),param_1[0x10]);
  return 0;
}

/* ---- FUNC 00048560 FUN_180048560 (168 bytes) ---- */

HRESULT FUN_180048560(void *param_1,DISPID param_2,undefined8 param_3,undefined8 param_4,
                     WORD param_5,DISPPARAMS *param_6,VARIANT *param_7,EXCEPINFO *param_8,
                     UINT *param_9)

{
  undefined8 uVar1;
  BSTR pOVar2;
  PVOID pvVar3;
  HRESULT HVar4;
  
  *(undefined4 *)((longlong)param_1 + 0x70) = 0;
  HVar4 = DispInvoke(param_1,DAT_180079d40,param_2,param_5,param_6,param_7,param_8,param_9);
  if (*(int *)((longlong)param_1 + 0x70) != 0) {
    if (param_8 != (EXCEPINFO *)0x0) {
      uVar1 = *(undefined8 *)((longlong)param_1 + 0x30);
      pOVar2 = *(BSTR *)((longlong)param_1 + 0x38);
      param_8->wCode = (short)uVar1;
      param_8->wReserved = (short)((ulonglong)uVar1 >> 0x10);
      *(int *)&param_8->field_0x4 = (int)((ulonglong)uVar1 >> 0x20);
      param_8->bstrSource = pOVar2;
      pOVar2 = *(BSTR *)((longlong)param_1 + 0x48);
      param_8->bstrDescription = *(BSTR *)((longlong)param_1 + 0x40);
      param_8->bstrHelpFile = pOVar2;
      pvVar3 = *(PVOID *)((longlong)param_1 + 0x58);
      *(undefined8 *)&param_8->dwHelpContext = *(undefined8 *)((longlong)param_1 + 0x50);
      param_8->pvReserved = pvVar3;
      uVar1 = *(undefined8 *)((longlong)param_1 + 0x68);
      param_8->pfnDeferredFillIn = *(_func_6477 **)((longlong)param_1 + 0x60);
      *(undefined8 *)&param_8->scode = uVar1;
      *(undefined8 *)((longlong)param_1 + 0x30) = 0;
      *(undefined8 *)((longlong)param_1 + 0x38) = 0;
      *(undefined8 *)((longlong)param_1 + 0x40) = 0;
      *(undefined8 *)((longlong)param_1 + 0x48) = 0;
      *(undefined8 *)((longlong)param_1 + 0x50) = 0;
      *(undefined8 *)((longlong)param_1 + 0x58) = 0;
      *(undefined8 *)((longlong)param_1 + 0x60) = 0;
      *(undefined8 *)((longlong)param_1 + 0x68) = 0;
    }
    HVar4 = -0x7ffdfff7;
  }
  return HVar4;
}

/* ---- FUNC 00048610 FUN_180048610 (231 bytes) ---- */

uint FUN_180048610(longlong param_1,uint param_2,VARIANTARG *param_3,uint *param_4)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  VARIANTARG *pvarg;
  ulonglong uVar5;
  int local_res10 [2];
  ulonglong uVar4;
  
  uVar4 = 0;
  uVar5 = (ulonglong)param_2;
  uVar3 = 0;
  if (param_4 != (uint *)0x0) {
    *param_4 = 0;
  }
  uVar2 = uVar5;
  pvarg = param_3;
  if (param_2 != 0) {
    do {
      VariantInit(pvarg);
      uVar2 = uVar2 - 1;
      pvarg = pvarg + 1;
    } while (uVar2 != 0);
  }
  local_res10[0] = *(int *)(param_1 + 0x14);
  if (local_res10[0] < *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) {
    do {
      uVar3 = (uint)uVar4;
      if (param_2 <= uVar3) break;
      uVar1 = SafeArrayGetElement(*(SAFEARRAY **)(param_1 + 0x18),local_res10,param_3 + uVar4);
      if ((int)uVar1 < 0) {
        if (param_2 == 0) {
          return uVar1;
        }
        do {
          VariantClear(param_3);
          param_3 = param_3 + 1;
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
        return uVar1;
      }
      uVar3 = uVar3 + 1;
      uVar4 = (ulonglong)uVar3;
      local_res10[0] = local_res10[0] + 1;
    } while (local_res10[0] < *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc));
  }
  if (param_4 != (uint *)0x0) {
    *param_4 = uVar3;
  }
  *(int *)(param_1 + 0x14) = local_res10[0];
  return (uint)(uVar3 < param_2);
}

/* ---- FUNC 00048700 FUN_180048700 (87 bytes) ---- */

undefined8 FUN_180048700(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  *param_3 = 0;
  if (((*param_2 != DAT_180066c58) || (param_2[1] != DAT_180066c60)) &&
     ((*param_2 != DAT_180066c88 || (param_2[1] != DAT_180066c90)))) {
    return 0x80004002;
  }
  *param_3 = param_1;
  (**(code **)(*param_1 + 8))();
  return 0;
}

/* ---- FUNC 00048760 FUN_180048760 (212 bytes) ---- */

undefined8 FUN_180048760(longlong *param_1,longlong *param_2,longlong *param_3)

{
  *param_3 = 0;
  if ((((*param_2 == DAT_180066c58) && (param_2[1] == DAT_180066c60)) ||
      ((*param_2 == DAT_180066c78 && (param_2[1] == DAT_180066c80)))) ||
     ((*param_2 == DAT_180063410 && (param_2[1] == DAT_180063418)))) {
    *param_3 = (longlong)param_1;
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((*param_2 == DAT_180066ca8) && (param_2[1] == DAT_180066cb0)) {
    *param_3 = (longlong)(param_1 + 2);
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((*param_2 == DAT_180066cd8) && (param_2[1] == DAT_180066ce0)) {
    *param_3 = param_1[0x10] + 0x18;
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  return 0x80004002;
}

/* ---- FUNC 00048840 FUN_180048840 (401 bytes) ---- */

undefined8 FUN_180048840(longlong param_1,uint param_2)

{
  HRESULT HVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar2;
  BSTR pOVar3;
  ICreateErrorInfo *local_res8;
  LPCSTR local_res18;
  LPCSTR local_res20;
  IErrorInfo *local_18;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_10 [8];
  
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18);
  if (*(BSTR *)(param_1 + 0x40) != (BSTR)0x0) {
    SysFreeString(*(BSTR *)(param_1 + 0x40));
  }
  if (*(BSTR *)(param_1 + 0x38) != (BSTR)0x0) {
    SysFreeString(*(BSTR *)(param_1 + 0x38));
  }
  if (*(BSTR *)(param_1 + 0x48) != (BSTR)0x0) {
    SysFreeString(*(BSTR *)(param_1 + 0x48));
  }
  *(undefined8 *)(param_1 + 0x30) = 0;
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(undefined8 *)(param_1 + 0x40) = 0;
  *(undefined8 *)(param_1 + 0x48) = 0;
  *(undefined8 *)(param_1 + 0x50) = 0;
  *(undefined8 *)(param_1 + 0x58) = 0;
  *(undefined8 *)(param_1 + 0x60) = 0;
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(short *)(param_1 + 0x30) = (short)param_2;
  pCVar2 = FUN_180020fe0(local_10,param_2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_10);
  pCVar2 = FUN_180020fe0(local_10,1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18,
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_10);
  if (*(int *)(local_res20 + -0x10) != 0) {
    pOVar3 = FUN_1800019d0(local_res20);
    *(BSTR *)(param_1 + 0x40) = pOVar3;
  }
  if (*(int *)(local_res18 + -0x10) != 0) {
    pOVar3 = FUN_1800019d0(local_res18);
    *(BSTR *)(param_1 + 0x38) = pOVar3;
  }
  *(undefined4 *)(param_1 + 0x70) = 1;
  HVar1 = CreateErrorInfo(&local_res8);
  if (-1 < HVar1) {
    (*local_res8->lpVtbl->SetGUID)(local_res8,(GUID *)&DAT_180063410);
    if (*(LPOLESTR *)(param_1 + 0x38) != (LPOLESTR)0x0) {
      (*local_res8->lpVtbl->SetSource)(local_res8,*(LPOLESTR *)(param_1 + 0x38));
    }
    if (*(LPOLESTR *)(param_1 + 0x40) != (LPOLESTR)0x0) {
      (*local_res8->lpVtbl->SetDescription)(local_res8,*(LPOLESTR *)(param_1 + 0x40));
    }
    HVar1 = (*local_res8->lpVtbl->QueryInterface)(local_res8,(IID *)&DAT_180066c98,&local_18);
    if (-1 < HVar1) {
      SetErrorInfo(0,local_18);
      (*local_18->lpVtbl->Release)(local_18);
    }
    (*local_res8->lpVtbl->Release)(local_res8);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
  return 0x80020009;
}

/* ---- FUNC 000489E0 FUN_1800489e0 (43 bytes) ---- */

undefined8 FUN_1800489e0(longlong *param_1,undefined8 *param_2)

{
  OLECHAR OVar1;
  HRESULT HVar2;
  undefined8 uVar3;
  BSTR pOVar4;
  OLECHAR *pOVar5;
  short sVar6;
  longlong lVar7;
  OLECHAR *pOVar8;
  longlong lVar9;
  OLECHAR *pOVar10;
  ICreateErrorInfo *local_res10;
  IErrorInfo *local_res18;
  
  if (param_2 == (undefined8 *)0x0) {
    uVar3 = (**(code **)(*param_1 + 0x108))(param_1,0x7d1);
    return uVar3;
  }
  if ((BSTR)param_1[8] != (BSTR)0x0) {
    SysFreeString((BSTR)param_1[8]);
  }
  if ((BSTR)param_1[7] != (BSTR)0x0) {
    SysFreeString((BSTR)param_1[7]);
  }
  if ((BSTR)param_1[9] != (BSTR)0x0) {
    SysFreeString((BSTR)param_1[9]);
  }
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  sVar6 = 0x7d1;
  if (*(short *)(param_2 + 1) != 0) {
    sVar6 = *(short *)(param_2 + 1);
  }
  *(short *)(param_1 + 6) = sVar6;
  pOVar5 = (OLECHAR *)param_2[2];
  if (pOVar5 == (OLECHAR *)0x0) {
    pOVar4 = SysAllocString(L"Unexpected Error");
  }
  else {
    lVar7 = -1;
    do {
      lVar7 = lVar7 + 1;
    } while (pOVar5[lVar7] != L'\0');
    pOVar4 = SysAllocStringLen(pOVar5,(UINT)lVar7);
  }
  param_1[8] = (longlong)pOVar4;
  pOVar5 = (OLECHAR *)param_2[3];
  lVar7 = -1;
  if (pOVar5 == (OLECHAR *)0x0) {
    pOVar4 = SysAllocString(L"Happ.Application");
  }
  else {
    do {
      lVar9 = lVar7;
      lVar7 = lVar9 + 1;
    } while (pOVar5[lVar7] != L'\0');
    if (*(short *)(param_2 + 1) == 0x13) {
      pOVar5 = (OLECHAR *)MDmalloc(lVar7 * 2 + 4);
      if (pOVar5 != (OLECHAR *)0x0) {
        *pOVar5 = L'!';
        pOVar8 = (OLECHAR *)param_2[3];
        pOVar10 = pOVar5;
        do {
          pOVar10 = pOVar10 + 1;
          OVar1 = *pOVar8;
          pOVar8 = pOVar8 + 1;
          *pOVar10 = OVar1;
        } while (OVar1 != L'\0');
        pOVar5[lVar9 + 2] = L'\0';
        pOVar4 = SysAllocStringLen(pOVar5,(int)lVar9 + 2);
        param_1[7] = (longlong)pOVar4;
        MDfree(pOVar5);
      }
      goto LAB_180048b41;
    }
    pOVar4 = SysAllocStringLen(pOVar5,(UINT)lVar7);
  }
  param_1[7] = (longlong)pOVar4;
LAB_180048b41:
  *(undefined4 *)(param_1 + 10) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_1 + 0xe) = 1;
  if ((code *)*param_2 != (code *)0x0) {
    (*(code *)*param_2)(param_2);
  }
  HVar2 = CreateErrorInfo(&local_res10);
  if (-1 < HVar2) {
    (*local_res10->lpVtbl->SetGUID)(local_res10,(GUID *)&DAT_180063460);
    if ((LPOLESTR)param_1[7] != (LPOLESTR)0x0) {
      (*local_res10->lpVtbl->SetSource)(local_res10,(LPOLESTR)param_1[7]);
    }
    if ((LPOLESTR)param_1[8] != (LPOLESTR)0x0) {
      (*local_res10->lpVtbl->SetDescription)(local_res10,(LPOLESTR)param_1[8]);
    }
    HVar2 = (*local_res10->lpVtbl->QueryInterface)(local_res10,(IID *)&DAT_180066c98,&local_res18);
    if (-1 < HVar2) {
      SetErrorInfo(0,local_res18);
      (*local_res18->lpVtbl->Release)(local_res18);
    }
    (*local_res10->lpVtbl->Release)(local_res10);
  }
  return 0x80020009;
}

/* ---- FUNC 00048A0B FUN_180048a0b (346 bytes) ---- */

undefined8 FUN_180048a0b(BSTR param_1)

{
  OLECHAR OVar1;
  HRESULT HVar2;
  BSTR pOVar3;
  OLECHAR *pOVar4;
  short sVar5;
  longlong lVar6;
  OLECHAR *pOVar7;
  longlong unaff_RBX;
  undefined8 *unaff_RSI;
  longlong lVar8;
  OLECHAR *pOVar9;
  ICreateErrorInfo *in_stack_00000048;
  IErrorInfo *in_stack_00000050;
  
  if (param_1 != (BSTR)0x0) {
    SysFreeString(param_1);
  }
  if (*(BSTR *)(unaff_RBX + 0x38) != (BSTR)0x0) {
    SysFreeString(*(BSTR *)(unaff_RBX + 0x38));
  }
  if (*(BSTR *)(unaff_RBX + 0x48) != (BSTR)0x0) {
    SysFreeString(*(BSTR *)(unaff_RBX + 0x48));
  }
  *(undefined8 *)(unaff_RBX + 0x30) = 0;
  *(undefined8 *)(unaff_RBX + 0x38) = 0;
  *(undefined8 *)(unaff_RBX + 0x40) = 0;
  *(undefined8 *)(unaff_RBX + 0x48) = 0;
  *(undefined8 *)(unaff_RBX + 0x50) = 0;
  *(undefined8 *)(unaff_RBX + 0x58) = 0;
  *(undefined8 *)(unaff_RBX + 0x60) = 0;
  *(undefined8 *)(unaff_RBX + 0x68) = 0;
  sVar5 = 0x7d1;
  if (*(short *)(unaff_RSI + 1) != 0) {
    sVar5 = *(short *)(unaff_RSI + 1);
  }
  *(short *)(unaff_RBX + 0x30) = sVar5;
  pOVar4 = (OLECHAR *)unaff_RSI[2];
  if (pOVar4 == (OLECHAR *)0x0) {
    pOVar3 = SysAllocString(L"Unexpected Error");
  }
  else {
    lVar6 = -1;
    do {
      lVar6 = lVar6 + 1;
    } while (pOVar4[lVar6] != L'\0');
    pOVar3 = SysAllocStringLen(pOVar4,(UINT)lVar6);
  }
  *(BSTR *)(unaff_RBX + 0x40) = pOVar3;
  pOVar4 = (OLECHAR *)unaff_RSI[3];
  lVar6 = -1;
  if (pOVar4 == (OLECHAR *)0x0) {
    pOVar3 = SysAllocString(L"Happ.Application");
  }
  else {
    do {
      lVar8 = lVar6;
      lVar6 = lVar8 + 1;
    } while (pOVar4[lVar6] != L'\0');
    if (*(short *)(unaff_RSI + 1) == 0x13) {
      pOVar4 = (OLECHAR *)MDmalloc(lVar6 * 2 + 4);
      if (pOVar4 != (OLECHAR *)0x0) {
        *pOVar4 = L'!';
        pOVar7 = (OLECHAR *)unaff_RSI[3];
        pOVar9 = pOVar4;
        do {
          pOVar9 = pOVar9 + 1;
          OVar1 = *pOVar7;
          pOVar7 = pOVar7 + 1;
          *pOVar9 = OVar1;
        } while (OVar1 != L'\0');
        pOVar4[lVar8 + 2] = L'\0';
        pOVar3 = SysAllocStringLen(pOVar4,(int)lVar8 + 2);
        *(BSTR *)(unaff_RBX + 0x38) = pOVar3;
        MDfree(pOVar4);
      }
      goto LAB_180048b41;
    }
    pOVar3 = SysAllocStringLen(pOVar4,(UINT)lVar6);
  }
  *(BSTR *)(unaff_RBX + 0x38) = pOVar3;
LAB_180048b41:
  *(undefined4 *)(unaff_RBX + 0x50) = *(undefined4 *)(unaff_RSI + 4);
  *(undefined4 *)(unaff_RBX + 0x70) = 1;
  if ((code *)*unaff_RSI != (code *)0x0) {
    (*(code *)*unaff_RSI)();
  }
  HVar2 = CreateErrorInfo(&stack0x00000048);
  if (-1 < HVar2) {
    (*in_stack_00000048->lpVtbl->SetGUID)(in_stack_00000048,(GUID *)&DAT_180063460);
    if (*(LPOLESTR *)(unaff_RBX + 0x38) != (LPOLESTR)0x0) {
      (*in_stack_00000048->lpVtbl->SetSource)(in_stack_00000048,*(LPOLESTR *)(unaff_RBX + 0x38));
    }
    if (*(LPOLESTR *)(unaff_RBX + 0x40) != (LPOLESTR)0x0) {
      (*in_stack_00000048->lpVtbl->SetDescription)
                (in_stack_00000048,*(LPOLESTR *)(unaff_RBX + 0x40));
    }
    HVar2 = (*in_stack_00000048->lpVtbl->QueryInterface)
                      (in_stack_00000048,(IID *)&DAT_180066c98,&stack0x00000050);
    if (-1 < HVar2) {
      SetErrorInfo(0,in_stack_00000050);
      (*in_stack_00000050->lpVtbl->Release)(in_stack_00000050);
    }
    (*in_stack_00000048->lpVtbl->Release)(in_stack_00000048);
  }
  return 0x80020009;
}

/* ---- FUNC 00048B65 FUN_180048b65 (151 bytes) ---- */

undefined8 FUN_180048b65(void)

{
  HRESULT HVar1;
  code *in_RAX;
  longlong unaff_RBX;
  ICreateErrorInfo *in_stack_00000048;
  IErrorInfo *in_stack_00000050;
  
  (*in_RAX)();
  HVar1 = CreateErrorInfo(&stack0x00000048);
  if (-1 < HVar1) {
    (*in_stack_00000048->lpVtbl->SetGUID)(in_stack_00000048,(GUID *)&DAT_180063460);
    if (*(LPOLESTR *)(unaff_RBX + 0x38) != (LPOLESTR)0x0) {
      (*in_stack_00000048->lpVtbl->SetSource)(in_stack_00000048,*(LPOLESTR *)(unaff_RBX + 0x38));
    }
    if (*(LPOLESTR *)(unaff_RBX + 0x40) != (LPOLESTR)0x0) {
      (*in_stack_00000048->lpVtbl->SetDescription)
                (in_stack_00000048,*(LPOLESTR *)(unaff_RBX + 0x40));
    }
    HVar1 = (*in_stack_00000048->lpVtbl->QueryInterface)
                      (in_stack_00000048,(IID *)&DAT_180066c98,&stack0x00000050);
    if (-1 < HVar1) {
      SetErrorInfo(0,in_stack_00000050);
      (*in_stack_00000050->lpVtbl->Release)(in_stack_00000050);
    }
    (*in_stack_00000048->lpVtbl->Release)(in_stack_00000048);
  }
  return 0x80020009;
}

/* ---- FUNC 00048C00 FUN_180048c00 (46 bytes) ---- */

int FUN_180048c00(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 1) + -1;
  *(int *)(param_1 + 1) = iVar1;
  if (iVar1 == 0) {
    FUN_1800473d0(param_1);
    FUN_180025ad0(param_1);
    iVar1 = 0;
  }
  return iVar1;
}

/* ---- FUNC 00048C30 FUN_180048c30 (14 bytes) ---- */

void FUN_180048c30(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180048c3a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(longlong **)(param_1 + 0x80) + 0x10))();
  return;
}

/* ---- FUNC 00048C40 FUN_180048c40 (1490 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */

undefined8
FUN_180048c40(longlong *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
             undefined8 *param_5,undefined4 *param_6,undefined8 *param_7)

{
  undefined1 *puVar1;
  ushort uVar2;
  code *pcVar3;
  LPCWSTR lpWideCharStr;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  HRESULT HVar9;
  undefined8 uVar10;
  longlong lVar11;
  longlong lVar12;
  ulonglong uVar13;
  int iVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  _struct_1720 *p_Var19;
  int *piVar20;
  _struct_1720 _Var21;
  int iVar22;
  undefined8 *puVar23;
  undefined1 auStack_1f8 [64];
  VARIANTARG local_1b8;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 local_178;
  _union_1719 _Stack_170;
  undefined8 local_168;
  undefined8 local_158;
  _union_1719 _Stack_150;
  undefined8 local_148;
  undefined8 local_138;
  _union_1719 _Stack_130;
  undefined8 local_128;
  undefined4 local_118;
  ULONG UStack_114;
  undefined4 uStack_110;
  ULONG UStack_10c;
  undefined8 local_108;
  undefined1 local_f8 [8];
  _union_1719 a_Stack_f0 [2];
  _union_2707 local_e0;
  _union_2707 local_c8;
  _union_2707 local_b0;
  _union_2707 local_98;
  undefined8 local_78 [5];
  int local_50 [6];
  ulonglong local_38;
  
  puVar18 = auStack_1f8;
  local_38 = DAT_180077818 ^ (ulonglong)&local_1b8;
  *param_7 = 0;
  if (DAT_1800797f8 == 0) {
    VariantInit(&local_1b8);
    if (*(longlong *)(param_1[0x10] + 0x48) == 0) {
      uVar10 = (**(code **)(*param_1 + 0x108))(param_1,0x7d9);
    }
    else {
      VariantInit((VARIANTARG *)&((_union_2707 *)local_f8)->n2);
      local_78[0] = 0;
      VariantInit((VARIANTARG *)((longlong)local_f8 + 0x18));
      local_78[1] = 0;
      VariantInit((VARIANTARG *)((longlong)local_f8 + 0x30));
      local_78[2] = 0;
      VariantInit((VARIANTARG *)((longlong)local_f8 + 0x48));
      local_78[3] = 0;
      VariantInit((VARIANTARG *)&local_98.n2);
      puVar23 = local_78;
      iVar22 = 0;
      local_f8 = (undefined1  [8])*param_2;
      a_Stack_f0[0] = *(_union_1719 *)(param_2 + 1);
      p_Var19 = (_struct_1720 *)&(((_union_2707 *)local_f8)->decVal).u2;
      local_78[4] = 0;
      a_Stack_f0[1] = (_union_1719)param_2[2];
      piVar20 = local_50;
      local_e0._0_8_ = *param_3;
      local_e0.decVal.u2 = *(_union_1719 *)(param_3 + 1);
      local_e0._16_8_ = param_3[2];
      local_c8._0_8_ = *param_4;
      local_c8.decVal.u2 = *(_union_1719 *)(param_4 + 1);
      local_c8._16_8_ = param_4[2];
      local_b0._0_8_ = *param_5;
      local_b0.decVal.u2 = *(_union_1719 *)(param_5 + 1);
      local_b0._16_8_ = param_5[2];
      local_98._0_4_ = *param_6;
      local_98.decVal.Hi32 = param_6[1];
      local_98._8_4_ = param_6[2];
      local_98._12_4_ = param_6[3];
      local_98._16_8_ = *(undefined8 *)(param_6 + 4);
      puVar18 = auStack_1f8;
      do {
        uVar2 = *(ushort *)&p_Var19[-1].Lo32;
        if (uVar2 < 0xb) {
          if ((uVar2 == 10) || (uVar2 == 0)) {
            *puVar23 = 0;
          }
          else if (uVar2 != 2) {
            if (uVar2 == 3) {
              *piVar20 = p_Var19->Lo32;
            }
            else {
              if (uVar2 != 8) goto LAB_180048f09;
              _Var21 = *p_Var19;
              *piVar20 = -1;
              if (_Var21 == (_struct_1720)0x0) goto LAB_180049080;
              lVar11 = -1;
              do {
                lVar11 = lVar11 + 1;
              } while (*(short *)((longlong)_Var21 + lVar11 * 2) != 0);
LAB_180048e4b:
              iVar14 = (int)lVar11 + 1;
              puVar15 = (undefined1 *)0x0;
              puVar16 = puVar18;
              if (iVar14 < 0x40000000) {
                lVar11 = (longlong)(int)lVar11 * 2;
                uVar13 = lVar11 + 0x11;
                if (uVar13 <= lVar11 + 2U) {
                  uVar13 = 0xffffffffffffff0;
                }
                *(undefined8 *)(puVar18 + -8) = 0x180048e78;
                lVar11 = -(uVar13 & 0xfffffffffffffff0);
                puVar1 = puVar18 + lVar11 + 0x40;
                puVar16 = puVar18 + lVar11;
                if (puVar1 != (undefined1 *)0x0) {
                  *(undefined8 *)(puVar18 + lVar11 + 0x38) = 0;
                  *(undefined8 *)(puVar18 + lVar11 + 0x30) = 0;
                  *(int *)(puVar18 + lVar11 + 0x28) = iVar14 * 2;
                  *puVar1 = 0;
                  *(undefined1 **)(puVar18 + lVar11 + 0x20) = puVar1;
                  *(undefined8 *)(puVar18 + lVar11 + -8) = 0x180048eac;
                  iVar14 = WideCharToMultiByte(0,0,(LPCWSTR)_Var21,-1,
                                               *(LPSTR *)(puVar18 + lVar11 + 0x20),
                                               *(int *)(puVar18 + lVar11 + 0x28),
                                               *(LPCSTR *)(puVar18 + lVar11 + 0x30),
                                               *(LPBOOL *)(puVar18 + lVar11 + 0x38));
                  puVar15 = puVar1;
                  puVar16 = puVar18 + lVar11;
                  if (iVar14 == 0) {
                    puVar15 = (undefined1 *)0x0;
                    puVar16 = puVar18 + lVar11;
                  }
                }
              }
              puVar18 = puVar16;
              *puVar23 = puVar15;
              if (puVar15 == (undefined1 *)0x0) goto LAB_180049083;
            }
            goto LAB_18004905f;
          }
          *piVar20 = (int)*(short *)&p_Var19->Lo32;
        }
        else {
          if (uVar2 == 0x4002) {
            iVar14 = (int)*(short *)*p_Var19;
          }
          else {
            if (uVar2 != 0x4003) {
              if (uVar2 == 0x4008) {
                _Var21 = *p_Var19;
                *piVar20 = -1;
                _Var21 = *(_struct_1720 *)_Var21;
                if (_Var21 != (_struct_1720)0x0) {
                  lVar11 = -1;
                  do {
                    lVar11 = lVar11 + 1;
                  } while (*(short *)((longlong)_Var21 + lVar11 * 2) != 0);
                  goto LAB_180048e4b;
                }
LAB_180049080:
                *puVar23 = 0;
                goto LAB_180049083;
              }
              if (uVar2 == 0x400c) {
                lVar12 = (longlong)iVar22;
                *(undefined8 **)(puVar18 + 0x30) = param_7;
                puVar23 = *(undefined8 **)((longlong)local_f8 + lVar12 * 0x18 + 8);
                uVar10 = puVar23[1];
                *(undefined8 *)((_union_2707 *)local_f8 + lVar12) = *puVar23;
                *(undefined8 *)((longlong)local_f8 + lVar12 * 0x18 + 8) = uVar10;
                lVar11 = *param_1;
                *(undefined8 *)((longlong)local_f8 + lVar12 * 0x18 + 0x10) = puVar23[2];
                uVar8 = local_98._16_8_;
                uVar7 = local_b0.decVal.u2;
                uVar6 = local_b0._0_8_;
                local_198 = CONCAT44(local_98.decVal.Hi32,local_98._0_4_);
                uStack_190 = CONCAT44(local_98._12_4_,local_98._8_4_);
                *(undefined8 **)(puVar18 + 0x28) = &local_198;
                uVar5 = local_c8._16_8_;
                uVar4 = local_e0.decVal.u2;
                uVar10 = local_e0._0_8_;
                local_188 = uVar8;
                local_178 = uVar6;
                _Stack_170 = (_union_1719)uVar7;
                local_168 = local_b0._16_8_;
                local_158 = local_c8._0_8_;
                _Stack_150 = local_c8.decVal.u2;
                *(undefined8 **)(puVar18 + 0x20) = &local_178;
                local_148 = uVar5;
                local_138 = uVar10;
                _Stack_130 = (_union_1719)uVar4;
                local_128 = local_e0._16_8_;
                local_118 = local_f8._0_4_;
                UStack_114 = local_f8._4_4_;
                uStack_110 = a_Stack_f0[0]._0_4_;
                UStack_10c = a_Stack_f0[0]._4_4_;
                local_108 = a_Stack_f0[1];
                pcVar3 = *(code **)(lVar11 + 0xd0);
                *(undefined8 *)(puVar18 + -8) = 0x18004918d;
                uVar10 = (*pcVar3)(param_1,&local_118,&local_138,&local_158);
              }
              else {
LAB_180048f09:
                *(undefined8 *)(puVar18 + -8) = 0x180048f13;
                VariantInit(&local_1b8);
                *(undefined8 *)(puVar18 + -8) = 0x180048f3b;
                HVar9 = VariantChangeType(&local_1b8,
                                          (VARIANTARG *)((_union_2707 *)local_f8 + iVar22),0,3);
                if (HVar9 == 0) {
                  *piVar20 = local_1b8.n1._8_4_;
                  *(undefined8 *)(puVar18 + -8) = 0x180048f4e;
                  VariantClear(&local_1b8);
                  goto LAB_18004905f;
                }
                *(undefined8 *)(puVar18 + -8) = 0x180048f59;
                VariantClear(&local_1b8);
                *(undefined8 *)(puVar18 + -8) = 0x180048f6f;
                HVar9 = VariantChangeType(&local_1b8,
                                          (VARIANTARG *)((_union_2707 *)local_f8 + iVar22),0,8);
                if (HVar9 == 0) {
                  lpWideCharStr = (LPCWSTR)CONCAT44(local_1b8.n1._12_4_,local_1b8.n1._8_4_);
                  *piVar20 = -1;
                  if (lpWideCharStr == (LPCWSTR)0x0) {
                    *puVar23 = 0;
                  }
                  else {
                    lVar11 = -1;
                    do {
                      lVar12 = lVar11;
                      lVar11 = lVar12 + 1;
                    } while (lpWideCharStr[lVar11] != L'\0');
                    iVar14 = (int)lVar12 + 2;
                    puVar15 = puVar18;
                    if (iVar14 < 0x40000000) {
                      lVar11 = (longlong)(int)lVar11 * 2;
                      uVar13 = lVar11 + 0x11;
                      if (uVar13 <= lVar11 + 2U) {
                        uVar13 = 0xffffffffffffff0;
                      }
                      *(undefined8 *)(puVar18 + -8) = 0x180048fd0;
                      lVar11 = -(uVar13 & 0xfffffffffffffff0);
                      puVar15 = puVar18 + lVar11;
                      puVar17 = puVar18 + lVar11;
                      puVar16 = puVar18 + lVar11 + 0x40;
                      if (puVar16 == (undefined1 *)0x0) goto LAB_180049011;
                      *puVar16 = 0;
                      *(undefined8 *)(puVar18 + lVar11 + 0x38) = 0;
                      *(undefined8 *)(puVar18 + lVar11 + 0x30) = 0;
                      *(int *)(puVar18 + lVar11 + 0x28) = iVar14 * 2;
                      *(undefined1 **)(puVar18 + lVar11 + 0x20) = puVar16;
                      *(undefined8 *)(puVar18 + lVar11 + -8) = 0x180049004;
                      iVar14 = WideCharToMultiByte(0,0,lpWideCharStr,-1,
                                                   *(LPSTR *)(puVar18 + lVar11 + 0x20),
                                                   *(int *)(puVar18 + lVar11 + 0x28),
                                                   *(LPCSTR *)(puVar18 + lVar11 + 0x30),
                                                   *(LPBOOL *)(puVar18 + lVar11 + 0x38));
                      puVar18 = puVar18 + lVar11;
                      if (iVar14 == 0) {
                        puVar16 = (undefined1 *)0x0;
                        puVar18 = puVar17;
                      }
                    }
                    else {
LAB_180049011:
                      puVar16 = (undefined1 *)0x0;
                      puVar18 = puVar15;
                    }
                    *puVar23 = puVar16;
                    if (puVar16 != (undefined1 *)0x0) goto LAB_18004905f;
                  }
                }
                else {
                  *(undefined8 *)(puVar18 + -8) = 0x1800490aa;
                  VariantClear(&local_1b8);
                }
LAB_180049083:
                pcVar3 = *(code **)(*param_1 + 0x108);
                *(undefined8 *)(puVar18 + -8) = 0x180049094;
                uVar10 = (*pcVar3)(param_1,0x7db);
              }
              goto LAB_1800491dd;
            }
            iVar14 = *(int *)*p_Var19;
          }
          *piVar20 = iVar14;
        }
LAB_18004905f:
        iVar22 = iVar22 + 1;
        puVar23 = puVar23 + 1;
        p_Var19 = p_Var19 + 3;
        piVar20 = piVar20 + 1;
      } while (iVar22 < 5);
      uVar10 = *(undefined8 *)(param_1[0x10] + 0x48);
      *(undefined8 *)(puVar18 + -8) = 0x1800491ae;
      lVar11 = HADeleteElement(uVar10,local_50,local_78);
      if (lVar11 == 0) {
        uVar10 = *(undefined8 *)(param_1[0x10] + 0x48);
        *(undefined8 *)(puVar18 + -8) = 0x1800491db;
        HANotify(uVar10,2);
        uVar10 = 0;
      }
      else {
        pcVar3 = *(code **)(*param_1 + 0x100);
        *(undefined8 *)(puVar18 + -8) = 0x1800491c3;
        uVar10 = (*pcVar3)(param_1,lVar11);
      }
    }
  }
  else {
    uVar10 = (**(code **)(*param_1 + 0x108))(param_1,0x7f3);
    puVar18 = auStack_1f8;
  }
LAB_1800491dd:
  *(undefined8 *)(puVar18 + -8) = 0x1800491ec;
  return uVar10;
}

/* ---- FUNC 00049220 FUN_180049220 (398 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180049220(longlong *param_1,ulonglong param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined1 auStack_158 [32];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_138 [8];
  int local_130 [2];
  char local_128 [256];
  ulonglong local_28;
  
  local_28 = DAT_180077818 ^ (ulonglong)auStack_158;
  if (DAT_1800797f8 == 0) {
    if (*(longlong *)(param_1[0x10] + 0x48) == 0) {
      uVar3 = (**(code **)(*param_1 + 0x108))(param_1,0x7d9);
    }
    else {
      iVar1 = (**(code **)(*param_1 + 0x50))(param_1,param_2,local_130);
      if ((-1 < iVar1) && (local_130[0] != 0)) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_138);
        puVar4 = (undefined8 *)
                 HAGetLabel(*(undefined8 *)(param_1[0x10] + 0x48),param_2 & 0xffffffff,param_3,
                            local_128);
        if (puVar4 != (undefined8 *)0x0) {
          if ((code *)*puVar4 != (code *)0x0) {
            (*(code *)*puVar4)(puVar4);
          }
          local_128[0] = '\0';
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  (local_138,local_128);
        lVar5 = HARemoveLocation(*(undefined8 *)(param_1[0x10] + 0x48),param_2 & 0xffffffff,param_3)
        ;
        if (lVar5 != 0) {
          uVar2 = (**(code **)(*param_1 + 0x100))(param_1,lVar5);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_138);
          return (ulonglong)uVar2;
        }
        *(undefined4 *)(param_1[0xf] + 0x100) = 1;
        if (DAT_18007988c == 0) {
          FUN_1800374c0(0x67,(longlong *)(param_1[0x10] + 0x1d8));
          FUN_180011410(*(longlong *)(param_1[0x10] + 0x50),param_1[0x10]);
        }
        else {
          DAT_180079890 = 1;
        }
        FUN_1800374c0(0x74,(longlong *)local_138);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_138);
      }
      uVar3 = 0;
    }
  }
  else {
    uVar3 = (**(code **)(*param_1 + 0x108))(param_1,0x7f3);
  }
  return uVar3;
}

/* ---- FUNC 000493B0 FUN_1800493b0 (1460 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */

ulonglong FUN_1800493b0(longlong *param_1,undefined4 *param_2,short param_3)

{
  undefined1 *puVar1;
  ushort uVar2;
  undefined8 uVar3;
  code *pcVar4;
  longlong *plVar5;
  longlong *plVar6;
  LPCWSTR lpWideCharStr;
  bool bVar7;
  short sVar8;
  bool bVar9;
  HRESULT HVar10;
  ulonglong uVar11;
  longlong lVar12;
  longlong lVar13;
  int iVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  int *piVar18;
  ulonglong uVar19;
  undefined1 *puVar20;
  _struct_1720 _Var21;
  int iVar22;
  undefined8 *puVar23;
  _struct_1720 *p_Var24;
  bool bVar25;
  undefined1 auStack_198 [64];
  short local_158 [2];
  short sStack_154;
  undefined8 *local_150;
  longlong *local_148;
  VARIANTARG local_140;
  undefined4 local_128;
  ULONG UStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  code *local_118;
  int local_108 [8];
  undefined1 local_e8 [8];
  _union_1719 a_Stack_e0 [15];
  undefined8 local_68 [5];
  ulonglong local_40;
  
  puVar17 = auStack_198;
  local_40 = DAT_180077818 ^ (ulonglong)local_158;
  sStack_154 = param_3;
  VariantInit(&local_140);
  if (DAT_1800797f8 != 0) {
    uVar11 = (**(code **)(*param_1 + 0x108))(param_1,0x7f3);
    puVar17 = auStack_198;
    goto LAB_18004993b;
  }
  lVar12 = param_1[0x10];
  if (*(longlong *)(lVar12 + 0x48) == 0) {
    uVar11 = (**(code **)(*param_1 + 0x108))(param_1,0x7d9);
    goto LAB_18004993b;
  }
  if (param_3 == 0) {
    bVar25 = false;
    bVar7 = false;
    uVar19 = 0;
    puVar17 = auStack_198;
    uVar11 = 0;
    if (((lVar12 != 0) && (puVar17 = auStack_198, uVar11 = uVar19, *(int *)(lVar12 + 0x68) == 0)) &&
       (puVar17 = auStack_198, *(longlong *)(lVar12 + 0x60) != 0)) {
      local_150 = (undefined8 *)0x0;
      iVar22 = HAGetAttrType(*(longlong *)(lVar12 + 0x48),0x33,0,&local_150);
      bVar9 = false;
      if (iVar22 == -999) {
LAB_180049867:
        bVar7 = bVar9;
        if (local_150 != (undefined8 *)0x0) goto LAB_18004986c;
      }
      else {
        if (local_150 == (undefined8 *)0x0) {
          local_150 = (undefined8 *)
                      HAGetAttr(*(undefined8 *)(param_1[0x10] + 0x48),0x33,0,&local_128);
          if ((local_150 == (undefined8 *)0x0) &&
             ((int *)CONCAT44(uStack_11c,uStack_120) != (int *)0x0)) {
            bVar25 = *(int *)CONCAT44(uStack_11c,uStack_120) != 0;
          }
          bVar9 = bVar25;
          if (local_118 != (code *)0x0) {
            (*local_118)();
          }
          goto LAB_180049867;
        }
LAB_18004986c:
        if ((code *)*local_150 != (code *)0x0) {
          (*(code *)*local_150)(local_150);
        }
      }
      (**(code **)(**(longlong **)(param_1[0x10] + 0x60) + 400))
                (*(longlong **)(param_1[0x10] + 0x60),4,local_158);
      if ((local_158[0] != 0) || (bVar7)) {
        puVar17 = auStack_198;
        if (DAT_180079800 != (longlong *)0x0) {
          (**(code **)(*DAT_180079800 + 0xc0))(DAT_180079800,param_1);
          puVar17 = auStack_198;
        }
      }
      else {
        plVar5 = *(longlong **)(param_1[0x10] + 0x60);
        puVar17 = auStack_198;
        if (((((int)plVar5[0xd] == 0) &&
             (plVar6 = (longlong *)plVar5[0xc], puVar17 = auStack_198, plVar6 != (longlong *)0x0))
            && ((**(code **)(*plVar6 + 400))(plVar6,4,local_158), puVar17 = auStack_198,
               local_158[0] != 0)) &&
           (iVar22 = (**(code **)(*plVar5 + 200))(plVar5,&local_148), puVar17 = auStack_198,
           -1 < iVar22)) {
          if ((DAT_180079800 != (longlong *)0x0) && (local_148 != (longlong *)0x0)) {
            (**(code **)(*DAT_180079800 + 0xc0))(DAT_180079800,local_148);
          }
          (**(code **)(*local_148 + 0x10))();
          puVar17 = auStack_198;
        }
      }
    }
  }
  else {
    VariantInit((VARIANTARG *)&((_union_2707 *)local_e8)->n2);
    piVar18 = local_108;
    puVar20 = (undefined1 *)0x0;
    p_Var24 = (_struct_1720 *)&(((_union_2707 *)local_e8)->decVal).u2;
    local_e8._0_4_ = *param_2;
    local_e8._4_4_ = param_2[1];
    a_Stack_e0[0]._0_4_ = param_2[2];
    a_Stack_e0[0]._4_4_ = param_2[3];
    puVar23 = local_68;
    local_68[0] = 0;
    a_Stack_e0[1] = (_union_1719)*(undefined8 *)(param_2 + 4);
    puVar17 = auStack_198;
    puVar15 = puVar20;
    do {
      sVar8 = sStack_154;
      uVar2 = *(ushort *)&p_Var24[-1].Lo32;
      iVar22 = (int)puVar15;
      puVar15 = puVar20;
      puVar16 = puVar17;
      if (uVar2 < 0xb) {
        if ((uVar2 == 10) || (uVar2 == 0)) {
          *puVar23 = 0;
        }
        else if (uVar2 != 2) {
          if (uVar2 == 3) {
            *piVar18 = p_Var24->Lo32;
          }
          else {
            if (uVar2 != 8) goto LAB_18004959e;
            _Var21 = *p_Var24;
            *piVar18 = -1;
            if (_Var21 == (_struct_1720)0x0) goto LAB_18004974a;
            lVar12 = -1;
            do {
              lVar12 = lVar12 + 1;
            } while (*(short *)((longlong)_Var21 + lVar12 * 2) != 0);
LAB_1800494ea:
            iVar14 = (int)lVar12 + 1;
            if (iVar14 < 0x40000000) {
              lVar12 = (longlong)(int)lVar12 * 2;
              uVar11 = lVar12 + 0x11;
              if (uVar11 <= lVar12 + 2U) {
                uVar11 = 0xffffffffffffff0;
              }
              *(undefined8 *)(puVar17 + -8) = 0x18004951b;
              lVar12 = -(uVar11 & 0xfffffffffffffff0);
              puVar1 = puVar17 + lVar12 + 0x40;
              puVar16 = puVar17 + lVar12;
              if (puVar1 != (undefined1 *)0x0) {
                *(undefined8 *)(puVar17 + lVar12 + 0x38) = 0;
                *(undefined8 *)(puVar17 + lVar12 + 0x30) = 0;
                *(int *)(puVar17 + lVar12 + 0x28) = iVar14 * 2;
                *puVar1 = 0;
                *(undefined1 **)(puVar17 + lVar12 + 0x20) = puVar1;
                *(undefined8 *)(puVar17 + lVar12 + -8) = 0x180049553;
                iVar14 = WideCharToMultiByte(0,0,(LPCWSTR)_Var21,-1,
                                             *(LPSTR *)(puVar17 + lVar12 + 0x20),
                                             *(int *)(puVar17 + lVar12 + 0x28),
                                             *(LPCSTR *)(puVar17 + lVar12 + 0x30),
                                             *(LPBOOL *)(puVar17 + lVar12 + 0x38));
                puVar15 = puVar1;
                puVar16 = puVar17 + lVar12;
                if (iVar14 == 0) {
                  puVar15 = puVar20;
                  puVar16 = puVar17 + lVar12;
                }
              }
            }
LAB_1800496ad:
            *puVar23 = puVar15;
            puVar17 = puVar16;
            if (puVar15 == (undefined1 *)0x0) goto LAB_18004974e;
          }
          goto LAB_1800496f2;
        }
        *piVar18 = (int)*(short *)&p_Var24->Lo32;
      }
      else {
        if (uVar2 == 0x4002) {
          iVar14 = (int)*(short *)*p_Var24;
        }
        else {
          if (uVar2 != 0x4003) {
            if (uVar2 == 0x4008) {
              _Var21 = *p_Var24;
              *piVar18 = -1;
              _Var21 = *(_struct_1720 *)_Var21;
              if (_Var21 != (_struct_1720)0x0) {
                lVar12 = -1;
                do {
                  lVar12 = lVar12 + 1;
                } while (*(short *)((longlong)_Var21 + lVar12 * 2) != 0);
                goto LAB_1800494ea;
              }
            }
            else {
              if (uVar2 == 0x400c) {
                lVar13 = (longlong)iVar22;
                puVar23 = *(undefined8 **)((longlong)local_e8 + lVar13 * 0x18 + 8);
                uVar3 = puVar23[1];
                *(undefined8 *)((_union_2707 *)local_e8 + lVar13) = *puVar23;
                *(undefined8 *)((longlong)local_e8 + lVar13 * 0x18 + 8) = uVar3;
                lVar12 = *param_1;
                *(undefined8 *)((longlong)local_e8 + lVar13 * 0x18 + 0x10) = puVar23[2];
                local_128 = local_e8._0_4_;
                UStack_124 = local_e8._4_4_;
                uStack_120 = a_Stack_e0[0]._0_4_;
                uStack_11c = a_Stack_e0[0]._4_4_;
                local_118 = (code *)a_Stack_e0[1];
                pcVar4 = *(code **)(lVar12 + 0xf0);
                *(undefined8 *)(puVar17 + -8) = 0x1800497bc;
                uVar11 = (*pcVar4)(param_1,&local_128,sVar8);
                goto LAB_18004993b;
              }
LAB_18004959e:
              *(undefined8 *)(puVar17 + -8) = 0x1800495a8;
              VariantInit(&local_140);
              *(undefined8 *)(puVar17 + -8) = 0x1800495cd;
              HVar10 = VariantChangeType(&local_140,(VARIANTARG *)((_union_2707 *)local_e8 + iVar22)
                                         ,0,3);
              local_150 = (undefined8 *)CONCAT44(local_150._4_4_,HVar10);
              if (HVar10 == 0) {
                *piVar18 = local_140.n1._8_4_;
                *(undefined8 *)(puVar17 + -8) = 0x1800495e4;
                VariantClear(&local_140);
                goto LAB_1800496f2;
              }
              *(undefined8 *)(puVar17 + -8) = 0x1800495f3;
              VariantClear(&local_140);
              *(undefined8 *)(puVar17 + -8) = 0x180049609;
              HVar10 = VariantChangeType(&local_140,(VARIANTARG *)((_union_2707 *)local_e8 + iVar22)
                                         ,0,8);
              local_150 = (undefined8 *)CONCAT44(local_150._4_4_,HVar10);
              if (HVar10 != 0) {
                *(undefined8 *)(puVar17 + -8) = 0x18004976e;
                VariantClear(&local_140);
                goto LAB_18004974e;
              }
              lpWideCharStr = (LPCWSTR)CONCAT44(local_140.n1._12_4_,local_140.n1._8_4_);
              *piVar18 = -1;
              if (lpWideCharStr != (LPCWSTR)0x0) {
                lVar12 = -1;
                do {
                  lVar13 = lVar12;
                  lVar12 = lVar13 + 1;
                } while (lpWideCharStr[lVar12] != L'\0');
                iVar14 = (int)lVar13 + 2;
                if (iVar14 < 0x40000000) {
                  lVar12 = (longlong)(int)lVar12 * 2;
                  uVar11 = lVar12 + 0x11;
                  if (uVar11 <= lVar12 + 2U) {
                    uVar11 = 0xffffffffffffff0;
                  }
                  *(undefined8 *)(puVar17 + -8) = 0x18004966e;
                  lVar12 = -(uVar11 & 0xfffffffffffffff0);
                  puVar1 = puVar17 + lVar12 + 0x40;
                  puVar16 = puVar17 + lVar12;
                  if (puVar1 != (undefined1 *)0x0) {
                    *(undefined8 *)(puVar17 + lVar12 + 0x38) = 0;
                    *(undefined8 *)(puVar17 + lVar12 + 0x30) = 0;
                    *(int *)(puVar17 + lVar12 + 0x28) = iVar14 * 2;
                    *puVar1 = 0;
                    *(undefined1 **)(puVar17 + lVar12 + 0x20) = puVar1;
                    *(undefined8 *)(puVar17 + lVar12 + -8) = 0x1800496a2;
                    iVar14 = WideCharToMultiByte(0,0,lpWideCharStr,-1,
                                                 *(LPSTR *)(puVar17 + lVar12 + 0x20),
                                                 *(int *)(puVar17 + lVar12 + 0x28),
                                                 *(LPCSTR *)(puVar17 + lVar12 + 0x30),
                                                 *(LPBOOL *)(puVar17 + lVar12 + 0x38));
                    puVar15 = puVar1;
                    puVar16 = puVar17 + lVar12;
                    if (iVar14 == 0) {
                      puVar15 = puVar20;
                      puVar16 = puVar17 + lVar12;
                    }
                  }
                }
                goto LAB_1800496ad;
              }
            }
LAB_18004974a:
            *puVar23 = 0;
LAB_18004974e:
            pcVar4 = *(code **)(*param_1 + 0x108);
            *(undefined8 *)(puVar17 + -8) = 0x18004975f;
            uVar11 = (*pcVar4)(param_1,0x7db);
            goto LAB_18004993b;
          }
          iVar14 = *(int *)*p_Var24;
        }
        *piVar18 = iVar14;
      }
LAB_1800496f2:
      puVar15 = (undefined1 *)(ulonglong)(iVar22 + 1U);
      puVar23 = puVar23 + 1;
      p_Var24 = p_Var24 + 3;
      piVar18 = piVar18 + 1;
    } while ((int)(iVar22 + 1U) < 1);
    iVar22 = (int)sStack_154;
    uVar3 = *(undefined8 *)(param_1[0x10] + 0x48);
    *(undefined8 *)(puVar17 + -8) = 0x18004972c;
    lVar12 = HAReorder(uVar3,local_108,local_68,iVar22);
    if (lVar12 != 0) {
      pcVar4 = *(code **)(*param_1 + 0x100);
      *(undefined8 *)(puVar17 + -8) = 0x180049745;
      uVar11 = (*pcVar4)(param_1,lVar12);
      goto LAB_18004993b;
    }
    lVar12 = param_1[0x10];
    *(undefined8 *)(puVar17 + -8) = 0x1800497d9;
    FUN_1800374c0(0x66,(longlong *)(lVar12 + 0x1d8));
    uVar11 = (ulonglong)local_150 & 0xffffffff;
  }
  *(undefined4 *)(param_1[0xf] + 0x100) = 1;
LAB_18004993b:
  *(undefined8 *)(puVar17 + -8) = 0x18004994a;
  return uVar11;
}

/* ---- FUNC 00049970 FUN_180049970 (9 bytes) ---- */

undefined8 FUN_180049970(longlong param_1)

{
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x10);
  return 0;
}

/* ---- FUNC 00049980 FUN_180049980 (37 bytes) ---- */

undefined8 FUN_180049980(longlong param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x14) + param_2;
  iVar2 = *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc);
  *(int *)(param_1 + 0x14) = iVar1;
  if (iVar2 < iVar1) {
    *(int *)(param_1 + 0x14) = iVar2;
    return 1;
  }
  return 0;
}

/* ---- FUNC 000499B0 FUN_1800499b0 (11 bytes) ---- */

void FUN_1800499b0(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0001800499b7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(longlong **)(param_1 + 0x78) + 0x38))();
  return;
}

/* ---- FUNC 000499C0 FUN_1800499c0 (381 bytes) ---- */

undefined8 FUN_1800499c0(longlong *param_1,int *param_2)

{
  longlong *plVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  int iVar6;
  longlong local_60;
  longlong *local_58;
  int *local_50;
  longlong *local_48;
  
  local_50 = param_2;
  local_48 = param_1;
  if (DAT_1800797f8 != 0) {
    uVar5 = (**(code **)(*param_1 + 0x108))(param_1,0x7f3);
    return uVar5;
  }
  iVar6 = 0;
  local_60 = 0;
  *param_2 = 0;
  plVar1 = param_1 + 0x10;
  local_58 = plVar1;
  if (*(longlong *)(*plVar1 + 0x48) != 0) {
    iVar2 = *(int *)(*plVar1 + 0x160);
    if (iVar2 == -1) {
      uVar5 = (**(code **)(*param_1 + 0x108))(param_1,0x7d1);
      return uVar5;
    }
    while( true ) {
      if (iVar2 <= iVar6) {
        return 0;
      }
      iVar3 = HAGetLength(*(undefined8 *)(*plVar1 + 0x48),iVar6,&local_60);
      if (iVar3 == -1) break;
      iVar4 = iVar3;
      if (*param_2 != 0) {
        iVar4 = *param_2 * iVar3;
      }
      *param_2 = iVar4;
      if (iVar3 == 0) {
        return 0;
      }
      iVar6 = iVar6 + 1;
    }
    if (local_60 == 0) {
      uVar5 = (**(code **)(*param_1 + 0x108))(param_1,0x7d1);
      return uVar5;
    }
    uVar5 = (**(code **)(*param_1 + 0x100))();
    return uVar5;
  }
  uVar5 = (**(code **)(*param_1 + 0x108))(param_1,0x7d9);
  return uVar5;
}

/* ---- FUNC 00049B40 FUN_180049b40 (84 bytes) ---- */

undefined8 FUN_180049b40(longlong *param_1,int *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x000180049b51. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(*param_1 + 0x108))(param_1,0x7f3);
    return uVar2;
  }
  if (*(longlong *)(param_1[0x10] + 0x48) == 0) {
                    /* WARNING: Could not recover jumptable at 0x000180049b6e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(*param_1 + 0x108))(param_1,0x7d9);
    return uVar2;
  }
  iVar1 = *(int *)(param_1[0x10] + 0x160);
  *param_2 = iVar1;
  if (iVar1 == -1) {
                    /* WARNING: Could not recover jumptable at 0x000180049b8a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(*param_1 + 0x108))(param_1,0x7d1);
    return uVar2;
  }
  return 0;
}

/* ---- FUNC 00049BA0 FUN_180049ba0 (99 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180049ba0(longlong *param_1,undefined8 param_2,undefined8 *param_3)

{
  int cchWideChar;
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  BSTR pOVar4;
  undefined1 auStackY_78 [32];
  CHAR local_48 [32];
  ulonglong local_28;
  
  local_28 = DAT_180077818 ^ (ulonglong)auStackY_78;
  if (DAT_1800797f8 == 0) {
    if (*(longlong *)(param_1[0x10] + 0x48) == 0) {
      uVar2 = (**(code **)(*param_1 + 0x108))(param_1,0x7d9);
    }
    else {
      lVar3 = HAGetDimensionName(*(longlong *)(param_1[0x10] + 0x48),param_2,local_48);
      if (lVar3 == 0) {
        cchWideChar = MultiByteToWideChar(0,0,local_48,-1,(LPWSTR)0x0,0);
        pOVar4 = SysAllocStringLen((OLECHAR *)0x0,cchWideChar - 1);
        if ((pOVar4 != (BSTR)0x0) &&
           (iVar1 = MultiByteToWideChar(0,0,local_48,-1,pOVar4,cchWideChar), iVar1 != cchWideChar))
        {
          SysFreeString(pOVar4);
          pOVar4 = (BSTR)0x0;
        }
        uVar2 = 0;
        *param_3 = pOVar4;
      }
      else {
        pOVar4 = FUN_1800019d0("");
        *param_3 = pOVar4;
        uVar2 = (**(code **)(*param_1 + 0x100))(param_1,lVar3);
      }
    }
  }
  else {
    uVar2 = (**(code **)(*param_1 + 0x108))(param_1,0x7f3);
  }
  return uVar2;
}

/* ---- FUNC 00049C03 FUN_180049c03 (54 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180049c03(void)

{
  int cchWideChar;
  int iVar1;
  longlong lVar2;
  BSTR pOVar3;
  undefined8 uVar4;
  longlong *unaff_RBX;
  undefined8 *unaff_RSI;
  
  lVar2 = HAGetDimensionName();
  if (lVar2 == 0) {
    cchWideChar = MultiByteToWideChar(0,0,&stack0x00000030,-1,(LPWSTR)0x0,0);
    pOVar3 = SysAllocStringLen((OLECHAR *)0x0,cchWideChar - 1);
    if ((pOVar3 != (BSTR)0x0) &&
       (iVar1 = MultiByteToWideChar(0,0,&stack0x00000030,-1,pOVar3,cchWideChar),
       iVar1 != cchWideChar)) {
      SysFreeString(pOVar3);
      pOVar3 = (BSTR)0x0;
    }
    uVar4 = 0;
    *unaff_RSI = pOVar3;
  }
  else {
    pOVar3 = FUN_1800019d0("");
    *unaff_RSI = pOVar3;
    uVar4 = (**(code **)(*unaff_RBX + 0x100))();
  }
  return uVar4;
}

/* ---- FUNC 00049C39 FUN_180049c39 (116 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180049c39(void)

{
  int cchWideChar;
  int iVar1;
  LPWSTR lpWideCharStr;
  undefined8 *unaff_RSI;
  LPWSTR unaff_RDI;
  
  iVar1 = (int)unaff_RDI;
  cchWideChar = MultiByteToWideChar(0,0,&stack0x00000030,iVar1 + -1,unaff_RDI,iVar1);
  lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,cchWideChar - 1);
  if ((lpWideCharStr != (BSTR)0x0) &&
     (iVar1 = MultiByteToWideChar(0,0,&stack0x00000030,iVar1 + -1,lpWideCharStr,cchWideChar),
     iVar1 != cchWideChar)) {
    SysFreeString(lpWideCharStr);
    lpWideCharStr = unaff_RDI;
  }
  *unaff_RSI = lpWideCharStr;
  return 0;
}

/* ---- FUNC 00049CAD FUN_180049cad (5 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180049cad(void)

{
  return;
}

/* ---- FUNC 00049CB2 FUN_180049cb2 (20 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180049cb2(void)

{
  return;
}

/* ---- FUNC 00049CD0 FUN_180049cd0 (427 bytes) ---- */

undefined8 FUN_180049cd0(longlong *param_1,VARIANTARG *param_2,ushort *param_3)

{
  ushort uVar1;
  undefined4 *puVar2;
  HRESULT HVar3;
  int iVar4;
  undefined8 uVar5;
  longlong local_res20;
  VARIANTARG local_48;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined8 local_18;
  
  if (DAT_1800797f8 != 0) {
    uVar5 = (**(code **)(*param_1 + 0x108))(param_1,0x7f3);
    return uVar5;
  }
  local_res20 = 0;
  VariantInit(&local_48);
  if (*(longlong *)(param_1[0x10] + 0x48) == 0) {
    uVar5 = (**(code **)(*param_1 + 0x108))(param_1,0x7d9);
    return uVar5;
  }
  uVar1 = (param_2->n1).n2.vt;
  if (uVar1 < 0xb) {
    if ((uVar1 == 10) || (uVar1 == 0)) {
      local_48.n1._8_4_ = 0;
      goto LAB_180049e0e;
    }
    if (uVar1 == 2) {
      local_48.n1._8_4_ = SEXT24(*(short *)((longlong)&param_2->n1 + 8));
      goto LAB_180049e0e;
    }
    if (uVar1 == 3) {
      local_48.n1._8_4_ = *(int *)((longlong)&param_2->n1 + 8);
      goto LAB_180049e0e;
    }
  }
  else {
    if (uVar1 == 0x4002) {
      local_48.n1._8_4_ = SEXT24(**(short **)((longlong)&param_2->n1 + 8));
      goto LAB_180049e0e;
    }
    if (uVar1 == 0x4003) {
      local_48.n1._8_4_ = **(int **)((longlong)&param_2->n1 + 8);
      goto LAB_180049e0e;
    }
    if (uVar1 == 0x400c) {
      puVar2 = *(undefined4 **)((longlong)&param_2->n1 + 8);
      local_28 = *puVar2;
      uStack_24 = puVar2[1];
      uStack_20 = puVar2[2];
      uStack_1c = puVar2[3];
      local_18 = *(undefined8 *)(puVar2 + 4);
      uVar5 = (**(code **)(*param_1 + 0x60))(param_1,&local_28,param_3);
      return uVar5;
    }
  }
  HVar3 = VariantChangeType(&local_48,param_2,0,3);
  if (HVar3 != 0) {
    uVar5 = (**(code **)(*param_1 + 0x108))(param_1,0x7d4);
    return uVar5;
  }
  VariantClear(&local_48);
LAB_180049e0e:
  iVar4 = HAIsNamedDimension(*(undefined8 *)(param_1[0x10] + 0x48),local_48.n1._8_4_,&local_res20);
  if (iVar4 == -1) {
    if (local_res20 == 0) {
      uVar5 = (**(code **)(*param_1 + 0x108))(param_1,0x7d1);
    }
    else {
      uVar5 = (**(code **)(*param_1 + 0x100))();
    }
  }
  else {
    uVar5 = 0;
    *param_3 = (ushort)(iVar4 != 0);
  }
  return uVar5;
}

/* ---- FUNC 00049E80 FUN_180049e80 (4322 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */

ulonglong FUN_180049e80(longlong *param_1,undefined8 *param_2,LPCWSTR param_3,undefined8 *param_4,
                       undefined8 *param_5,undefined8 *param_6,undefined8 *param_7)

{
  char *pcVar1;
  undefined1 *puVar2;
  wchar_t *pwVar3;
  char cVar4;
  ushort uVar5;
  code *pcVar6;
  undefined8 uVar7;
  IUnknownVtbl *pIVar8;
  IUnknownVtbl *pIVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 ******ppppppuVar12;
  undefined8 **ppuVar13;
  undefined8 uVar14;
  undefined2 uVar15;
  HRESULT HVar16;
  uint uVar17;
  ulonglong uVar18;
  ulonglong uVar19;
  longlong lVar20;
  IUnknownVtbl *pIVar21;
  void *pvVar22;
  undefined8 *******pppppppuVar23;
  ulonglong uVar24;
  char *pcVar25;
  void *pvVar26;
  int iVar27;
  ulonglong uVar28;
  ulonglong uVar29;
  VARIANTARG *pvarg;
  undefined1 *puVar30;
  undefined1 *puVar31;
  ulonglong uVar32;
  wchar_t *pwVar33;
  undefined1 *puVar34;
  undefined1 *puVar35;
  uint *puVar36;
  wchar_t *pwVar37;
  longlong lVar38;
  uint *puVar39;
  longlong *plVar40;
  LPCWSTR lpWideCharStr;
  undefined1 *puVar41;
  char *pcVar42;
  undefined8 *puVar43;
  longlong *plVar44;
  int iVar45;
  undefined1 auStack_4d8 [64];
  uint local_498;
  uint uStack_494;
  undefined8 *local_490;
  longlong *local_488;
  byte local_480;
  int iStack_47c;
  longlong *local_478;
  undefined8 *local_470;
  longlong local_468;
  VARIANTARG local_460;
  undefined8 local_448;
  undefined8 uStack_440;
  undefined8 local_438;
  undefined8 **local_428;
  undefined8 uStack_420;
  undefined8 local_418;
  undefined8 **local_408;
  undefined8 uStack_400;
  undefined8 local_3f8;
  undefined8 local_3e8;
  _union_1719 _Stack_3e0;
  ulonglong local_3d8;
  ulonglong local_3d0;
  undefined8 *******local_3c8;
  undefined8 uStack_3c0;
  ulonglong local_3b8;
  ulonglong local_3b0;
  undefined8 local_3a8;
  longlong lStack_3a0;
  ulonglong local_398;
  ulonglong uStack_390;
  undefined1 local_388;
  undefined7 uStack_387;
  longlong lStack_380;
  longlong local_378;
  ulonglong uStack_370;
  uint local_368 [6];
  longlong local_350 [5];
  _union_2707 local_328;
  undefined8 ******local_310;
  undefined8 uStack_308;
  undefined8 local_300;
  undefined8 **local_2f8;
  undefined8 uStack_2f0;
  undefined8 local_2e8;
  undefined8 **local_2e0;
  undefined8 uStack_2d8;
  undefined8 local_2d0;
  undefined8 local_2c8;
  undefined8 uStack_2c0;
  undefined8 local_2b8;
  char local_248 [15];
  char cStack_239;
  char local_238 [256];
  char local_138 [256];
  ulonglong local_38;
  
  puVar35 = auStack_4d8;
  local_38 = DAT_180077818 ^ (ulonglong)&local_498;
  local_470 = param_7;
  *param_7 = 0;
  if (DAT_1800797f8 != 0) {
    uVar18 = (**(code **)(*param_1 + 0x108))(param_1,0x7f3);
    puVar35 = auStack_4d8;
    goto LAB_18004af22;
  }
  local_490 = (undefined8 *)0x0;
  if (*(longlong *)(param_1[0x10] + 0x48) == 0) {
    uVar18 = (**(code **)(*param_1 + 0x108))(param_1,0x7d9);
    goto LAB_18004af22;
  }
  pvarg = (VARIANTARG *)&local_328;
  lVar38 = 9;
  lpWideCharStr = param_3;
  do {
    VariantInit(pvarg);
    pvarg = pvarg + 1;
    lVar38 = lVar38 + -1;
  } while (lVar38 != 0);
  puVar39 = local_368;
  local_350[0] = 0;
  local_350[1] = 0;
  iVar45 = 0;
  uVar28 = 5;
  local_350[4] = 0;
  local_350[2] = 0;
  local_350[3] = 0;
  uVar18 = 0xffffffffffffffff;
  uStack_494 = 5;
  local_328._0_8_ = *param_2;
  local_328.decVal.u2 = *(_union_1719 *)(param_2 + 1);
  local_328._16_8_ = param_2[2];
  plVar44 = local_350;
  local_310 = *(undefined8 *******)param_3;
  uStack_308 = *(undefined8 *)(param_3 + 4);
  local_300 = *(undefined8 *)(param_3 + 8);
  puVar36 = (uint *)((longlong)&local_328.n2 + 8);
  local_2f8 = (undefined8 **)*param_4;
  uStack_2f0 = param_4[1];
  local_2e8 = param_4[2];
  local_2e0 = (undefined8 **)*param_5;
  uStack_2d8 = param_5[1];
  local_2d0 = param_5[2];
  local_2c8 = *param_6;
  uStack_2c0 = param_6[1];
  local_2b8 = param_6[2];
  puVar35 = auStack_4d8;
  do {
    puVar41 = (undefined1 *)0x0;
    uVar5 = (ushort)puVar36[-2];
    uVar19 = uVar18;
    if (uVar5 < 0xb) {
      if ((uVar5 == 10) || (uVar5 == 0)) {
        uStack_494 = (int)uVar28 - 1;
        uVar28 = (ulonglong)uStack_494;
        *puVar39 = 0xffffffff;
        *plVar44 = 0;
      }
      else if (uVar5 == 2) {
        *puVar39 = (int)(short)*puVar36;
      }
      else if (uVar5 == 3) {
        *puVar39 = *puVar36;
      }
      else {
        if (uVar5 != 8) goto LAB_18004a139;
        lpWideCharStr = *(LPCWSTR *)puVar36;
        *puVar39 = 0xffffffff;
        if (lpWideCharStr == (LPCWSTR)0x0) goto LAB_18004a2a1;
        do {
          uVar19 = uVar19 + 1;
        } while (lpWideCharStr[uVar19] != L'\0');
LAB_18004a06b:
        iVar27 = (int)uVar19 + 1;
        puVar30 = puVar41;
        puVar31 = puVar35;
        if (iVar27 < 0x40000000) {
          lVar38 = (longlong)(int)uVar19 * 2;
          uVar28 = lVar38 + 0x11;
          if (uVar28 <= lVar38 + 2U) {
            uVar28 = 0xffffffffffffff0;
          }
          *(undefined8 *)(puVar35 + -8) = 0x18004a098;
          lVar38 = -(uVar28 & 0xfffffffffffffff0);
          puVar2 = puVar35 + lVar38 + 0x40;
          puVar31 = puVar35 + lVar38;
          if (puVar2 != (undefined1 *)0x0) {
            *(undefined8 *)(puVar35 + lVar38 + 0x38) = 0;
            *(undefined8 *)(puVar35 + lVar38 + 0x30) = 0;
            *(int *)(puVar35 + lVar38 + 0x28) = iVar27 * 2;
            puVar41 = (undefined1 *)0xffffffff;
            *(undefined1 **)(puVar35 + lVar38 + 0x20) = puVar2;
            *puVar2 = 0;
            *(undefined8 *)(puVar35 + lVar38 + -8) = 0x18004a0cb;
            iVar27 = WideCharToMultiByte(0,0,lpWideCharStr,-1,*(LPSTR *)(puVar35 + lVar38 + 0x20),
                                         *(int *)(puVar35 + lVar38 + 0x28),
                                         *(LPCSTR *)(puVar35 + lVar38 + 0x30),
                                         *(LPBOOL *)(puVar35 + lVar38 + 0x38));
            puVar30 = puVar2;
            puVar31 = puVar35 + lVar38;
            if (iVar27 == 0) {
              puVar30 = (undefined1 *)0x0;
              puVar31 = puVar35 + lVar38;
            }
          }
        }
        puVar35 = puVar31;
        *plVar44 = (longlong)puVar30;
        if (puVar30 == (undefined1 *)0x0) goto LAB_18004a2a4;
        uVar28 = (ulonglong)uStack_494;
      }
    }
    else {
      if (uVar5 == 0x4002) {
        uVar17 = (uint)**(short **)puVar36;
      }
      else {
        if (uVar5 != 0x4003) {
          if (uVar5 != 0x4008) {
            if (uVar5 != 0x400c) {
LAB_18004a139:
              *(undefined8 *)(puVar35 + -8) = 0x18004a143;
              VariantInit(&local_460);
              puVar41 = (undefined1 *)0x3;
              lpWideCharStr = (LPCWSTR)0x0;
              *(undefined8 *)(puVar35 + -8) = 0x18004a16b;
              HVar16 = VariantChangeType(&local_460,
                                         (VARIANTARG *)
                                         ((longlong)&local_328 + (longlong)iVar45 * 0x18),0,3);
              if (HVar16 == 0) {
                *puVar39 = local_460.n1._8_4_;
                *(undefined8 *)(puVar35 + -8) = 0x18004a17e;
                VariantClear(&local_460);
                uVar28 = (ulonglong)uStack_494;
                goto LAB_18004a280;
              }
              *(undefined8 *)(puVar35 + -8) = 0x18004a18c;
              VariantClear(&local_460);
              puVar41 = (undefined1 *)0x8;
              *(undefined8 *)(puVar35 + -8) = 0x18004a1a2;
              HVar16 = VariantChangeType(&local_460,
                                         (VARIANTARG *)
                                         ((longlong)&local_328 + (longlong)iVar45 * 0x18),0,8);
              if (HVar16 == 0) {
                lpWideCharStr = (LPCWSTR)CONCAT44(local_460.n1._12_4_,local_460.n1._8_4_);
                *puVar39 = 0xffffffff;
                uVar28 = uVar18;
                if (lpWideCharStr == (LPCWSTR)0x0) {
                  *plVar44 = 0;
                }
                else {
                  do {
                    uVar19 = uVar28;
                    uVar28 = uVar19 + 1;
                  } while (lpWideCharStr[uVar28] != L'\0');
                  iVar27 = (int)uVar19 + 2;
                  puVar30 = puVar35;
                  if (iVar27 < 0x40000000) {
                    lVar38 = (longlong)(int)uVar28 * 2;
                    uVar28 = lVar38 + 0x11;
                    if (uVar28 <= lVar38 + 2U) {
                      uVar28 = 0xffffffffffffff0;
                    }
                    *(undefined8 *)(puVar35 + -8) = 0x18004a1ff;
                    lVar38 = -(uVar28 & 0xfffffffffffffff0);
                    puVar30 = puVar35 + lVar38;
                    puVar34 = puVar35 + lVar38;
                    puVar31 = puVar35 + lVar38 + 0x40;
                    if (puVar31 == (undefined1 *)0x0) goto LAB_18004a23f;
                    *puVar31 = 0;
                    *(undefined8 *)(puVar35 + lVar38 + 0x38) = 0;
                    *(undefined8 *)(puVar35 + lVar38 + 0x30) = 0;
                    puVar41 = (undefined1 *)0xffffffff;
                    *(int *)(puVar35 + lVar38 + 0x28) = iVar27 * 2;
                    *(undefined1 **)(puVar35 + lVar38 + 0x20) = puVar31;
                    *(undefined8 *)(puVar35 + lVar38 + -8) = 0x18004a232;
                    iVar27 = WideCharToMultiByte(0,0,lpWideCharStr,-1,
                                                 *(LPSTR *)(puVar35 + lVar38 + 0x20),
                                                 *(int *)(puVar35 + lVar38 + 0x28),
                                                 *(LPCSTR *)(puVar35 + lVar38 + 0x30),
                                                 *(LPBOOL *)(puVar35 + lVar38 + 0x38));
                    puVar35 = puVar35 + lVar38;
                    if (iVar27 == 0) {
                      puVar31 = (undefined1 *)0x0;
                      puVar35 = puVar34;
                    }
                  }
                  else {
LAB_18004a23f:
                    puVar31 = (undefined1 *)0x0;
                    puVar35 = puVar30;
                  }
                  *plVar44 = (longlong)puVar31;
                  if (puVar31 != (undefined1 *)0x0) {
                    uVar28 = (ulonglong)uStack_494;
                    goto LAB_18004a280;
                  }
                }
              }
              else {
                *(undefined8 *)(puVar35 + -8) = 0x18004a2cc;
                VariantClear(&local_460);
              }
              goto LAB_18004a2a4;
            }
            lVar20 = (longlong)iVar45;
            puVar43 = *(undefined8 **)((longlong)&local_328 + (lVar20 * 3 + -1) * 8 + 0x10);
            uVar7 = puVar43[1];
            *(undefined8 *)((longlong)&local_328 + lVar20 * 0x18) = *puVar43;
            *(undefined8 *)((longlong)&local_328 + (lVar20 * 3 + -1) * 8 + 0x10) = uVar7;
            lVar38 = *param_1;
            *(undefined8 *)((longlong)&local_328 + lVar20 * 0x18 + 0x10) = puVar43[2];
            uVar14 = local_2b8;
            uVar10 = uStack_2c0;
            uVar7 = local_2c8;
            *(undefined8 **)(puVar35 + 0x30) = local_470;
            uVar11 = uStack_2d8;
            ppuVar13 = local_2e0;
            local_448 = uVar7;
            uStack_440 = uVar10;
            *(undefined8 **)(puVar35 + 0x28) = &local_448;
            uVar10 = local_2e8;
            uVar7 = uStack_308;
            ppppppuVar12 = local_310;
            local_438 = uVar14;
            local_428 = ppuVar13;
            uStack_420 = uVar11;
            local_418 = local_2d0;
            local_408 = local_2f8;
            uStack_400 = uStack_2f0;
            *(undefined8 ****)(puVar35 + 0x20) = &local_428;
            local_3f8 = uVar10;
            local_3c8 = (undefined8 *******)ppppppuVar12;
            uStack_3c0 = uVar7;
            local_3b8 = local_300;
            local_3e8 = (void *)local_328._0_8_;
            _Stack_3e0 = local_328.decVal.u2;
            local_3d8 = local_328._16_8_;
            pcVar6 = *(code **)(lVar38 + 0x68);
            *(undefined8 *)(puVar35 + -8) = 0x18004a3bd;
            uVar18 = (*pcVar6)(param_1,&local_3e8,&local_3c8,&local_408);
            goto LAB_18004af22;
          }
          plVar40 = *(longlong **)puVar36;
          *puVar39 = 0xffffffff;
          lpWideCharStr = (LPCWSTR)*plVar40;
          if (lpWideCharStr != (LPCWSTR)0x0) {
            do {
              uVar19 = uVar19 + 1;
            } while (lpWideCharStr[uVar19] != L'\0');
            goto LAB_18004a06b;
          }
LAB_18004a2a1:
          *plVar44 = 0;
          goto LAB_18004a2a4;
        }
        uVar17 = **(uint **)puVar36;
      }
      *puVar39 = uVar17;
    }
LAB_18004a280:
    iVar45 = iVar45 + 1;
    plVar44 = plVar44 + 1;
    puVar36 = puVar36 + 6;
    puVar39 = puVar39 + 1;
  } while (iVar45 < 5);
  if ((local_368[0] == 0xffffffff) && (local_350[0] == 0)) {
LAB_18004a2a4:
    pcVar6 = *(code **)(*param_1 + 0x108);
    *(undefined8 *)(puVar35 + -8) = 0x18004a2b6;
    uVar18 = (*pcVar6)(param_1,0x7db);
    goto LAB_18004af22;
  }
  iStack_47c = *(int *)(param_1[0x10] + 0x160);
  lVar38 = (longlong)iStack_47c;
  if (iStack_47c == -1) {
    pcVar6 = *(code **)(*param_1 + 0x108);
    *(undefined8 *)(puVar35 + -8) = 0x18004a401;
    uVar18 = (*pcVar6)(param_1,0x7d1);
    goto LAB_18004af22;
  }
  uVar32 = 0;
  uVar19 = uVar32;
  uVar24 = uVar32;
  local_468 = lVar38;
  if (0 < iStack_47c) {
    do {
      uVar28 = uVar24;
      iVar27 = (int)uVar28;
      pcVar6 = *(code **)(*param_1 + 0x50);
      *(undefined8 *)(puVar35 + -8) = 0x18004a430;
      lpWideCharStr = (LPCWSTR)&local_498;
      iVar45 = (*pcVar6)(param_1);
      if ((iVar45 < 0) || ((int)local_498 <= (int)local_368[uVar19])) goto LAB_18004aaf4;
      uVar19 = uVar19 + 1;
      uVar24 = (ulonglong)(iVar27 + 1);
    } while ((longlong)uVar19 < lVar38);
  }
  lVar20 = param_1[0x10];
  if (lVar20 != 0) {
    *(undefined8 *)(puVar35 + -8) = 0x18004a463;
    FUN_18003c040(lVar20,uVar28,lpWideCharStr,puVar41);
  }
  uVar7 = *(undefined8 *)(param_1[0x10] + 0x48);
  *(undefined8 *)(puVar35 + -8) = 0x18004a486;
  pIVar21 = (IUnknownVtbl *)HAGetElement(uVar7,local_368,local_350);
  puVar43 = local_490;
  if (pIVar21 == (IUnknownVtbl *)0x0) {
    if (local_490 != (undefined8 *)0x0) {
      if (*(short *)(local_490 + 1) == 0) {
        pcVar6 = *(code **)(*param_1 + 0x100);
        *(undefined8 *)(puVar35 + -8) = 0x18004a4c6;
        uVar18 = (*pcVar6)(param_1);
        goto LAB_18004af22;
      }
      pcVar6 = (code *)*local_490;
      if (pcVar6 != (code *)0x0) {
        *(undefined8 *)(puVar35 + -8) = 0x18004a4b2;
        (*pcVar6)(puVar43);
        uVar18 = 0;
        goto LAB_18004af22;
      }
    }
LAB_18004aaf4:
    uVar18 = 0;
  }
  else {
    pIVar8 = (IUnknownVtbl *)param_1[0x10];
    pIVar9 = (IUnknownVtbl *)param_1[0xf];
    pcVar42 = (char *)0x0;
    *(longlong ***)(puVar35 + 0x28) = &local_488;
    *(_func_5158 **)(puVar35 + 0x20) = pIVar8->Release;
    *(undefined8 *)(puVar35 + -8) = 0x18004a4f0;
    local_498 = FUN_1800389d0(pIVar21,pIVar9,pIVar8,0,*(IUnknownVtbl **)(puVar35 + 0x20),
                              *(undefined8 **)(puVar35 + 0x28));
    if (-1 < (int)local_498) {
      *local_470 = local_488;
      if ((param_1[0x10] != 0) &&
         (plVar44 = *(longlong **)(param_1[0x10] + 0xe8), plVar44 != (longlong *)0x0)) {
        local_238[0] = '\0';
        if (0 < lVar38) {
          puVar41 = (undefined1 *)&local_328;
          uVar28 = uVar32;
          uVar15 = DAT_180064480;
          do {
            if ((*(short *)puVar41 != 10) && (*(short *)puVar41 != 0)) {
              if (local_368[uVar32] == 0xffffffff) {
                pcVar42 = (char *)local_350[uVar32];
                uVar19 = uVar18;
                if (pcVar42 != (char *)0x0) {
                  do {
                    uVar19 = uVar19 + 1;
                    uVar24 = uVar18;
                  } while (pcVar42[uVar19] != '\0');
                  do {
                    uVar29 = uVar24 + 1;
                    lVar20 = uVar24 + 2;
                    uVar24 = uVar29;
                  } while ((&cStack_239)[lVar20] != '\0');
                  if (0xfe < uVar19 + uVar29) goto LAB_18004af20;
                  pcVar25 = &cStack_239;
                  do {
                    pcVar1 = pcVar25 + 1;
                    pcVar25 = pcVar25 + 1;
                  } while (*pcVar1 != '\0');
                  lVar20 = 0;
                  do {
                    cVar4 = pcVar42[lVar20];
                    pcVar25[lVar20] = cVar4;
                    lVar20 = lVar20 + 1;
                  } while (cVar4 != '\0');
                }
                pcVar25 = &cStack_239;
                do {
                  pcVar1 = pcVar25 + 1;
                  pcVar25 = pcVar25 + 1;
                } while (*pcVar1 != '\0');
                *(undefined2 *)pcVar25 = uVar15;
              }
              else {
                uVar7 = *(undefined8 *)(param_1[0x10] + 0x48);
                *(undefined8 *)(puVar35 + -8) = 0x18004a619;
                iVar45 = HAIsNamedDimension(uVar7,uVar28,&local_490);
                uVar19 = uVar18;
                if ((iVar45 == 0) || ((int)local_368[uVar32] < 0)) {
                  do {
                    uVar24 = uVar19 + 1;
                    lVar20 = uVar19 + 2;
                    uVar19 = uVar24;
                  } while ((&cStack_239)[lVar20] != '\0');
                  if (0xf8 < uVar24) goto LAB_18004af20;
                  uVar17 = local_368[uVar32];
                  *(undefined8 *)(puVar35 + -8) = 0x18004a7b3;
                  FUN_180002a20(local_248,&DAT_180065a3c,(ulonglong)uVar17,pcVar42);
                  pcVar25 = &cStack_239;
                  do {
                    pcVar1 = pcVar25 + 1;
                    pcVar25 = pcVar25 + 1;
                  } while (*pcVar1 != '\0');
                  lVar20 = 0;
                  do {
                    cVar4 = local_248[lVar20];
                    pcVar25[lVar20] = cVar4;
                    lVar20 = lVar20 + 1;
                  } while (cVar4 != '\0');
                }
                else {
                  pcVar42 = local_138;
                  uVar7 = *(undefined8 *)(param_1[0x10] + 0x48);
                  *(undefined8 *)(puVar35 + -8) = 0x18004a64c;
                  puVar43 = (undefined8 *)HAGetLabel(uVar7,uVar28);
                  local_490 = puVar43;
                  if (puVar43 != (undefined8 *)0x0) {
                    pcVar6 = (code *)*puVar43;
                    if (pcVar6 != (code *)0x0) {
                      *(undefined8 *)(puVar35 + -8) = 0x18004a665;
                      (*pcVar6)(puVar43);
                    }
                    local_490 = (undefined8 *)0x0;
                    local_138[0] = '\0';
                  }
                  do {
                    uVar24 = uVar19 + 1;
                    lVar20 = uVar19 + 2;
                    uVar19 = uVar24;
                  } while ((&cStack_239)[lVar20] != '\0');
                  uVar19 = uVar18;
                  if (local_138[0] == '\0') {
                    if (0xf8 < uVar24) goto LAB_18004af20;
                    uVar17 = local_368[uVar32];
                    *(undefined8 *)(puVar35 + -8) = 0x18004a6bc;
                    FUN_180002a20(local_248,&DAT_180065a3c,(ulonglong)uVar17,pcVar42);
                    pcVar25 = &cStack_239;
                    do {
                      pcVar1 = pcVar25 + 1;
                      pcVar25 = pcVar25 + 1;
                    } while (*pcVar1 != '\0');
                    lVar20 = 0;
                    do {
                      cVar4 = local_248[lVar20];
                      pcVar25[lVar20] = cVar4;
                      lVar20 = lVar20 + 1;
                    } while (cVar4 != '\0');
                  }
                  else {
                    do {
                      uVar29 = uVar19 + 1;
                      lVar20 = uVar19 + 1;
                      uVar19 = uVar29;
                    } while (local_138[lVar20] != '\0');
                    if (0xfe < uVar29 + uVar24) goto LAB_18004af20;
                    pcVar25 = &cStack_239;
                    do {
                      pcVar42 = pcVar25 + 1;
                      pcVar25 = pcVar25 + 1;
                    } while (*pcVar42 != '\0');
                    pcVar42 = local_138;
                    lVar20 = 0;
                    do {
                      cVar4 = pcVar42[lVar20];
                      pcVar25[lVar20] = cVar4;
                      lVar20 = lVar20 + 1;
                    } while (cVar4 != '\0');
                    pcVar25 = &cStack_239;
                    do {
                      pcVar1 = pcVar25 + 1;
                      pcVar25 = pcVar25 + 1;
                    } while (*pcVar1 != '\0');
                    *(undefined2 *)pcVar25 = DAT_180064480;
                  }
                }
                puVar43 = local_490;
                uVar15 = DAT_180064480;
                if (local_490 != (undefined8 *)0x0) {
                  pcVar6 = (code *)*local_490;
                  if (pcVar6 != (code *)0x0) {
                    *(undefined8 *)(puVar35 + -8) = 0x18004a80d;
                    (*pcVar6)(puVar43);
                  }
                  local_490 = (undefined8 *)0x0;
                  uVar15 = DAT_180064480;
                }
              }
            }
            uVar28 = (ulonglong)((int)uVar28 + 1);
            uVar32 = uVar32 + 1;
            puVar41 = puVar41 + 0x18;
          } while ((longlong)uVar32 < lVar38);
        }
        pwVar37 = (wchar_t *)0x0;
        uVar28 = uVar18;
        do {
          uVar19 = uVar28;
          uVar28 = uVar19 + 1;
        } while ((&cStack_239)[uVar19 + 2] != '\0');
        uVar28 = uVar18;
        if ((&cStack_239)[uVar19 + 1] == '!') {
          if (0xff < uVar19) {
                    /* WARNING: Subroutine does not return */
            *(undefined **)(puVar35 + -8) = &UNK_18004af62;
            FUN_18005c254();
          }
          (&cStack_239)[uVar19 + 1] = '\0';
        }
        do {
          uVar19 = uVar28;
          uVar28 = uVar19 + 1;
        } while ((&cStack_239)[uVar19 + 2] != '\0');
        iVar45 = (int)uVar19 + 2;
        pwVar33 = pwVar37;
        puVar41 = puVar35;
        if (iVar45 < 0x40000000) {
          lVar38 = (longlong)(int)(uVar19 + 1) * 2;
          uVar28 = lVar38 + 0x11;
          if (uVar28 <= lVar38 + 2U) {
            uVar28 = 0xffffffffffffff0;
          }
          *(undefined8 *)(puVar35 + -8) = 0x18004a8b1;
          lVar38 = -(uVar28 & 0xfffffffffffffff0);
          pwVar3 = (wchar_t *)(puVar35 + lVar38 + 0x40);
          puVar41 = puVar35 + lVar38;
          if (pwVar3 != (wchar_t *)0x0) {
            *(int *)(puVar35 + lVar38 + 0x28) = iVar45;
            *pwVar3 = L'\0';
            *(wchar_t **)(puVar35 + lVar38 + 0x20) = pwVar3;
            *(undefined8 *)(puVar35 + lVar38 + -8) = 0x18004a8de;
            iVar45 = MultiByteToWideChar(0,0,local_238,-1,*(LPWSTR *)(puVar35 + lVar38 + 0x20),
                                         *(int *)(puVar35 + lVar38 + 0x28));
            pwVar33 = pwVar3;
            puVar41 = puVar35 + lVar38;
            if (iVar45 == 0) {
              pwVar33 = pwVar37;
              puVar41 = puVar35 + lVar38;
            }
          }
        }
        puVar35 = puVar41;
        plVar40 = local_488;
        *(undefined8 *)(puVar35 + -8) = 0x18004a8f8;
        FUN_180038480((longlong)plVar40,plVar44,pwVar33);
        do {
          uVar28 = uVar18;
          uVar18 = uVar28 + 1;
        } while ((&cStack_239)[uVar28 + 2] != '\0');
        if (*(longlong *)(param_1[0x10] + 0x178) == 0) {
          local_3a8 = (void *)0x0;
          lStack_3a0 = 0;
          if (0x7fffffffffffffff < uVar18) goto LAB_18004af57;
          local_398 = uVar18;
          if (uVar18 < 0x10) {
            uStack_390 = 0xf;
            *(undefined8 *)(puVar35 + -8) = 0x18004a96c;
            memcpy(&local_3a8,local_238,uVar18);
            *(undefined1 *)((longlong)&local_3a8 + uVar28 + 1) = 0;
            uVar28 = uStack_390;
          }
          else {
            uVar28 = uVar18 | 0xf;
            if (uVar28 < 0x8000000000000000) {
              if (uVar28 < 0x16) {
                uVar28 = 0x16;
              }
              uVar19 = uVar28 + 1;
              if (uVar19 < 0x1000) {
                if (uVar19 == 0) {
                  pvVar22 = (void *)0x0;
                }
                else {
                  *(undefined8 *)(puVar35 + -8) = 0x18004a9d9;
                  pvVar22 = operator_new(uVar19);
                }
              }
              else {
                *(undefined8 *)(puVar35 + -8) = 0x18004a9c7;
                pvVar22 = (void *)FUN_180001160(uVar19);
              }
            }
            else {
              *(undefined8 *)(puVar35 + -8) = 0x18004a99e;
              pvVar22 = (void *)FUN_180001160(0x8000000000000000);
              uVar28 = 0x7fffffffffffffff;
            }
            local_3a8 = pvVar22;
            uStack_390 = uVar28;
            *(undefined8 *)(puVar35 + -8) = 0x18004aa08;
            memcpy(pvVar22,local_238,uVar18);
            *(undefined1 *)((longlong)pvVar22 + uVar18) = 0;
          }
          plVar44 = local_488;
          plVar40 = local_488 + 0x2d;
          if (plVar40 != &local_3a8) {
            if (0xf < (ulonglong)local_488[0x30]) {
              pvVar22 = (void *)*plVar40;
              pvVar26 = pvVar22;
              if ((0xfff < local_488[0x30] + 1U) &&
                 (pvVar26 = *(void **)((longlong)pvVar22 + -8),
                 0x1f < (ulonglong)((longlong)pvVar22 + (-8 - (longlong)pvVar26))))
              goto LAB_18004adf1;
              *(undefined8 *)(puVar35 + -8) = 0x18004aa5e;
              FUN_180025ad0(pvVar26);
            }
            pvVar22 = local_3a8;
            *(undefined1 *)plVar40 = 0;
            uVar28 = 0xf;
            local_3a8 = (void *)((ulonglong)local_3a8 & 0xffffffffffffff00);
            *plVar40 = (longlong)pvVar22;
            plVar44[0x2e] = lStack_3a0;
            plVar44[0x2f] = local_398;
            plVar44[0x30] = uStack_390;
          }
          lVar38 = local_468;
          if (0xf < uVar28) {
            pvVar22 = local_3a8;
            if (0xfff < uVar28 + 1) {
              pvVar22 = *(void **)((longlong)local_3a8 + -8);
              lVar38 = (longlong)local_3a8 - (longlong)pvVar22;
joined_r0x00018004adeb:
              if (0x1f < lVar38 - 8U) {
LAB_18004adf1:
                    /* WARNING: Subroutine does not return */
                *(undefined **)(puVar35 + -8) = &UNK_18004adf7;
                _invalid_parameter_noinfo_noreturn();
              }
            }
LAB_18004aab6:
            *(undefined8 *)(puVar35 + -8) = 0x18004aabb;
            FUN_180025ad0(pvVar22);
            lVar38 = local_468;
          }
        }
        else {
          local_3e8 = (void *)0x0;
          _Stack_3e0 = (_union_1719)0x0;
          if (0x7fffffffffffffff < uVar18) {
LAB_18004af57:
                    /* WARNING: Subroutine does not return */
            *(undefined **)(puVar35 + -8) = &UNK_18004af5c;
            FUN_180002780();
          }
          local_3d8 = uVar18;
          if (uVar18 < 0x10) {
            local_3d0 = 0xf;
            *(undefined8 *)(puVar35 + -8) = 0x18004ab48;
            memcpy(&local_3e8,local_238,uVar18);
            *(undefined1 *)((longlong)&local_3e8 + uVar28 + 1) = 0;
          }
          else {
            uVar28 = uVar18 | 0xf;
            if (uVar28 < 0x8000000000000000) {
              if (uVar28 < 0x16) {
                uVar28 = 0x16;
              }
              uVar19 = uVar28 + 1;
              if (uVar19 < 0x1000) {
                if (uVar19 == 0) {
                  pvVar22 = (void *)0x0;
                }
                else {
                  *(undefined8 *)(puVar35 + -8) = 0x18004ab90;
                  pvVar22 = operator_new(uVar19);
                }
              }
              else {
                *(undefined8 *)(puVar35 + -8) = 0x18004ab84;
                pvVar22 = (void *)FUN_180001160(uVar19);
              }
            }
            else {
              uVar28 = 0x7fffffffffffffff;
              *(undefined8 *)(puVar35 + -8) = 0x18004ab69;
              pvVar22 = (void *)FUN_180001160(0x8000000000000000);
            }
            local_3e8 = pvVar22;
            local_3d0 = uVar28;
            *(undefined8 *)(puVar35 + -8) = 0x18004abbe;
            memcpy(pvVar22,local_238,uVar18);
            *(undefined1 *)((longlong)pvVar22 + uVar18) = 0;
          }
          lVar38 = param_1[0x10];
          puVar43 = (undefined8 *)(lVar38 + 0x168);
          local_478 = *(longlong **)(lVar38 + 0x178);
          if (local_478 == (longlong *)0x7fffffffffffffff) goto LAB_18004af57;
          if (0xf < *(ulonglong *)(lVar38 + 0x180)) {
            puVar43 = (undefined8 *)*puVar43;
          }
          uVar18 = (longlong)local_478 + 1;
          pppppppuVar23 = &local_3c8;
          local_3c8 = (undefined8 *******)0x0;
          uStack_3c0 = 0;
          uVar28 = 0xf;
          if (0xf < uVar18) {
            uVar28 = uVar18 | 0xf;
            if (uVar28 < 0x8000000000000000) {
              if (uVar28 < 0x16) {
                uVar28 = 0x16;
              }
              uVar19 = uVar28 + 1;
              if (uVar19 < 0x1000) {
                if (uVar19 == 0) {
                  pppppppuVar23 = (undefined8 *******)0x0;
                  local_3c8 = pppppppuVar23;
                }
                else {
                  *(undefined8 *)(puVar35 + -8) = 0x18004ac64;
                  pppppppuVar23 = operator_new(uVar19);
                  local_3c8 = pppppppuVar23;
                }
              }
              else {
                *(undefined8 *)(puVar35 + -8) = 0x18004ac51;
                pppppppuVar23 = (undefined8 *******)FUN_180001160(uVar19);
                local_3c8 = pppppppuVar23;
              }
            }
            else {
              uVar28 = 0x7fffffffffffffff;
              *(undefined8 *)(puVar35 + -8) = 0x18004ac29;
              pppppppuVar23 = (undefined8 *******)FUN_180001160(0x8000000000000000);
              local_3c8 = pppppppuVar23;
            }
          }
          plVar44 = local_478;
          local_3b8 = uVar18;
          local_3b0 = uVar28;
          *(undefined8 *)(puVar35 + -8) = 0x18004ac92;
          memcpy(pppppppuVar23,puVar43,(size_t)plVar44);
          *(undefined1 *)((longlong)pppppppuVar23 + (longlong)local_478) = 0x2e;
          *(undefined1 *)((longlong)pppppppuVar23 + uVar18) = 0;
          *(undefined8 *)(puVar35 + -8) = 0x18004acbe;
          FUN_180047180((undefined8 *)&local_388,(ulonglong)local_480,&local_3c8,&local_3e8);
          plVar44 = local_488;
          plVar40 = local_488 + 0x2d;
          if (plVar40 != (longlong *)&local_388) {
            if (0xf < (ulonglong)local_488[0x30]) {
              pvVar22 = (void *)*plVar40;
              pvVar26 = pvVar22;
              if ((0xfff < local_488[0x30] + 1U) &&
                 (pvVar26 = *(void **)((longlong)pvVar22 + -8),
                 0x1f < (ulonglong)((longlong)pvVar22 + (-8 - (longlong)pvVar26))))
              goto LAB_18004adf1;
              *(undefined8 *)(puVar35 + -8) = 0x18004ad0f;
              FUN_180025ad0(pvVar26);
            }
            lVar38 = CONCAT71(uStack_387,local_388);
            local_388 = 0;
            *plVar40 = lVar38;
            plVar44[0x2e] = lStack_380;
            plVar44[0x2f] = local_378;
            plVar44[0x30] = uStack_370;
            uStack_370 = 0xf;
          }
          if (0xf < uStack_370) {
            pvVar26 = (void *)CONCAT71(uStack_387,local_388);
            pvVar22 = pvVar26;
            if ((0xfff < uStack_370 + 1) &&
               (pvVar22 = *(void **)((longlong)pvVar26 + -8),
               0x1f < (ulonglong)((longlong)pvVar26 + (-8 - (longlong)pvVar22))))
            goto LAB_18004adf1;
            *(undefined8 *)(puVar35 + -8) = 0x18004ad70;
            FUN_180025ad0(pvVar22);
          }
          if (0xf < local_3b0) {
            pppppppuVar23 = local_3c8;
            if ((0xfff < local_3b0 + 1) &&
               (pppppppuVar23 = (undefined8 *******)local_3c8[-1],
               0x1f < (ulonglong)((longlong)local_3c8 + (-8 - (longlong)pppppppuVar23))))
            goto LAB_18004adf1;
            *(undefined8 *)(puVar35 + -8) = 0x18004adad;
            FUN_180025ad0(pppppppuVar23);
          }
          lVar38 = local_468;
          if (0xf < local_3d0) {
            pvVar22 = local_3e8;
            if (0xfff < local_3d0 + 1) {
              pvVar22 = *(void **)((longlong)local_3e8 + -8);
              lVar38 = (longlong)local_3e8 - (longlong)pvVar22;
              goto joined_r0x00018004adeb;
            }
            goto LAB_18004aab6;
          }
        }
      }
      puVar43 = local_470;
      plVar44 = local_488;
      if (0 < (int)(uStack_494 - iStack_47c)) {
        pcVar6 = *(code **)(*local_488 + 0x58);
        *(undefined8 *)(puVar35 + -8) = 0x18004aae2;
        uVar18 = (*pcVar6)(plVar44,&iStack_47c);
        plVar44 = local_488;
        if ((int)uVar18 != 0) goto LAB_18004af22;
        if (iStack_47c < 1) goto LAB_18004aaf4;
        pcVar6 = *(code **)(*local_488 + 200);
        *(undefined8 *)(puVar35 + -8) = 0x18004ae09;
        uVar18 = (*pcVar6)(plVar44,&local_478);
        plVar44 = local_478;
        if ((int)uVar18 != 0) goto LAB_18004af22;
        uVar10 = *(undefined8 *)((longlong)&local_328 + (lVar38 * 3 + 10) * 8 + 0x10);
        uVar11 = *(undefined8 *)((longlong)&local_328 + (lVar38 * 3 + 0xb) * 8 + 0x10);
        *(undefined8 **)(puVar35 + 0x30) = puVar43;
        uVar7 = *(undefined8 *)((longlong)&local_328 + (lVar38 * 3 + 0xc) * 8 + 0x10);
        local_3e8 = (void *)uVar10;
        _Stack_3e0 = (_union_1719)uVar11;
        ppppppuVar12 = *(undefined8 *******)((longlong)&local_328 + (lVar38 * 3 + 7) * 8 + 0x10);
        uVar10 = *(undefined8 *)((longlong)&local_328 + (lVar38 * 3 + 8) * 8 + 0x10);
        *(undefined8 **)(puVar35 + 0x28) = &local_3e8;
        local_3d8 = uVar7;
        uVar7 = *(undefined8 *)((longlong)&local_328 + (lVar38 * 3 + 9) * 8 + 0x10);
        local_3c8 = (undefined8 *******)ppppppuVar12;
        uStack_3c0 = uVar10;
        ppuVar13 = *(undefined8 ***)((longlong)&local_328 + (lVar38 * 3 + 4) * 8 + 0x10);
        uVar10 = *(undefined8 *)((longlong)&local_328 + (lVar38 * 3 + 5) * 8 + 0x10);
        *(undefined8 *********)(puVar35 + 0x20) = &local_3c8;
        local_3b8 = uVar7;
        local_408 = ppuVar13;
        uStack_400 = uVar10;
        local_3f8 = *(undefined8 *)((longlong)&local_328 + (lVar38 * 3 + 6) * 8 + 0x10);
        local_428 = *(undefined8 ***)((longlong)&local_328 + (lVar38 * 3 + 1) * 8 + 0x10);
        uStack_420 = *(undefined8 *)((longlong)&local_328 + (lVar38 * 3 + 2) * 8 + 0x10);
        local_418 = *(undefined8 *)((longlong)&local_328 + (lVar38 * 3 + 3) * 8 + 0x10);
        local_438 = *(undefined8 *)((longlong)&local_328 + lVar38 * 0x18 + 0x10);
        local_448 = CONCAT44(*(undefined4 *)((longlong)&local_328 + lVar38 * 0x18 + 4),
                             *(undefined4 *)((longlong)&local_328 + lVar38 * 0x18));
        uStack_440 = CONCAT44(*(undefined4 *)((longlong)&local_328 + lVar38 * 0x18 + 0xc),
                              *(undefined4 *)((longlong)&local_328 + (lVar38 * 3 + -1) * 8 + 0x10));
        pcVar6 = *(code **)(*plVar44 + 0x68);
        *(undefined8 *)(puVar35 + -8) = 0x18004aef2;
        uVar17 = (*pcVar6)(plVar44,&local_448,&local_428,&local_408);
        if (uVar17 == 0) {
          pcVar6 = *(code **)(*local_478 + 0x10);
          *(undefined8 *)(puVar35 + -8) = 0x18004af11;
          (*pcVar6)();
          pcVar6 = *(code **)(*local_488 + 0x10);
          *(undefined8 *)(puVar35 + -8) = 0x18004af1b;
          (*pcVar6)();
          local_498 = uVar17;
        }
        else {
          *puVar43 = local_488;
          pcVar6 = *(code **)(*local_478 + 0x10);
          *(undefined8 *)(puVar35 + -8) = 0x18004af09;
          (*pcVar6)();
          local_498 = uVar17;
        }
      }
    }
LAB_18004af20:
    uVar18 = (ulonglong)local_498;
  }
LAB_18004af22:
  *(undefined8 *)(puVar35 + -8) = 0x18004af31;
  return uVar18;
}

/* ---- FUNC 0004AF70 FUN_18004af70 (590 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_18004af70(longlong *param_1,int param_2,uint *param_3,undefined8 *param_4,undefined8 *param_5)

{
  undefined4 *puVar1;
  HRESULT HVar2;
  int iVar3;
  undefined8 uVar4;
  BSTR pOVar5;
  uint uVar6;
  LPCSTR pCVar7;
  undefined4 uVar8;
  undefined1 auStack_1f8 [32];
  undefined8 *local_1d8;
  longlong local_1c8;
  _union_2707 local_1c0;
  VARIANTARG local_1a8;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined4 local_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined8 local_158;
  CHAR local_148 [256];
  ulonglong local_48;
  
  local_48 = DAT_180077818 ^ (ulonglong)auStack_1f8;
  local_1c0._0_4_ = *param_3;
  local_1c0.decVal.Hi32 = param_3[1];
  local_1c0._12_4_ = param_3[3];
  local_1c0._16_8_ = *(undefined8 *)(param_3 + 4);
  local_1c0._8_2_ = (undefined2)param_3[2];
  local_1c0._10_2_ = (undefined2)(param_3[2] >> 0x10);
  local_1c8 = 0;
  VariantInit(&local_1a8);
  if (DAT_1800797f8 != 0) {
    uVar4 = (**(code **)(*param_1 + 0x108))(param_1,0x7f3);
    return uVar4;
  }
  if (*(longlong *)(param_1[0x10] + 0x48) == 0) {
    uVar4 = (**(code **)(*param_1 + 0x108))(param_1,0x7d9);
    return uVar4;
  }
  uVar6 = local_1c0._0_4_ & 0xffff;
  if (uVar6 < 0xb) {
    uVar8 = 0;
    if ((uVar6 == 10) || (uVar6 = local_1c0._0_4_ & 0xffff, uVar6 == 0)) goto LAB_18004b0fc;
    if (uVar6 == 2) {
      uVar8 = SEXT24((short)local_1c0._8_2_);
      goto LAB_18004b0fc;
    }
    if (uVar6 == 3) {
      uVar8 = CONCAT22(local_1c0._10_2_,local_1c0._8_2_);
      goto LAB_18004b0fc;
    }
  }
  else {
    if (uVar6 == 0x4002) {
      uVar8 = SEXT24(*(short *)CONCAT44(local_1c0._12_4_,CONCAT22(local_1c0._10_2_,local_1c0._8_2_))
                    );
      goto LAB_18004b0fc;
    }
    if (uVar6 == 0x4003) {
      uVar8 = *(int *)CONCAT44(local_1c0._12_4_,CONCAT22(local_1c0._10_2_,local_1c0._8_2_));
      goto LAB_18004b0fc;
    }
    if (uVar6 == 0x400c) {
      puVar1 = (undefined4 *)CONCAT44(local_1c0._12_4_,CONCAT22(local_1c0._10_2_,local_1c0._8_2_));
      local_188 = *param_4;
      uStack_180 = param_4[1];
      local_178 = param_4[2];
      local_168 = *puVar1;
      uStack_164 = puVar1[1];
      uStack_160 = puVar1[2];
      uStack_15c = puVar1[3];
      local_1d8 = param_5;
      local_158 = *(undefined8 *)(puVar1 + 4);
      uVar4 = (**(code **)(*param_1 + 0x70))(param_1,param_2,&local_168,&local_188);
      return uVar4;
    }
  }
  HVar2 = VariantChangeType(&local_1a8,(VARIANTARG *)&local_1c0.n2,0,3);
  if (HVar2 != 0) {
    uVar4 = (**(code **)(*param_1 + 0x108))(param_1,0x7d4);
    return uVar4;
  }
  VariantClear(&local_1a8);
  uVar8 = local_1a8.n1._8_4_;
LAB_18004b0fc:
  if (param_2 < 0) {
    pCVar7 = "";
  }
  else {
    iVar3 = HAIsNamedDimension(*(undefined8 *)(param_1[0x10] + 0x48),uVar8,&local_1c8);
    if (iVar3 == 0) {
      pOVar5 = FUN_1800019d0("");
      *param_5 = pOVar5;
      uVar4 = (**(code **)(*param_1 + 0x108))(param_1,0x7f0);
      return uVar4;
    }
    local_1c8 = HAGetLabel(*(undefined8 *)(param_1[0x10] + 0x48),uVar8,param_2,local_148);
    if (local_1c8 != 0) {
      pOVar5 = FUN_1800019d0("");
      *param_5 = pOVar5;
      uVar4 = (**(code **)(*param_1 + 0x100))(param_1,local_1c8);
      return uVar4;
    }
    pCVar7 = local_148;
    local_1c8 = 0;
  }
  pOVar5 = FUN_1800019d0(pCVar7);
  *param_5 = pOVar5;
  return 0;
}

/* ---- FUNC 0004B1C0 FUN_18004b1c0 (462 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_18004b1c0(longlong *param_1,ulonglong param_2,int param_3,short *param_4,undefined8 *param_5)

{
  int iVar1;
  undefined8 uVar2;
  BSTR pOVar3;
  longlong lVar4;
  LPCSTR pCVar5;
  undefined1 auStack_158 [32];
  undefined8 *local_138 [2];
  CHAR local_128 [256];
  ulonglong local_28;
  
  local_28 = DAT_180077818 ^ (ulonglong)auStack_158;
  local_138[0] = (undefined8 *)0x0;
  if (DAT_1800797f8 != 0) {
    uVar2 = (**(code **)(*param_1 + 0x108))(param_1,0x7f3);
    return uVar2;
  }
  if (*(longlong *)(param_1[0x10] + 0x48) == 0) {
    uVar2 = (**(code **)(*param_1 + 0x108))(param_1,0x7d9);
    return uVar2;
  }
  if ((param_3 < 0) || ((int)param_2 < 0)) {
    pCVar5 = "";
  }
  else {
    if ((*param_4 != 0xb) || (param_4[4] == 0)) {
      iVar1 = HAGetLength(*(longlong *)(param_1[0x10] + 0x48),param_2,local_138);
      if (iVar1 == -1) {
        lVar4 = *param_1;
        if (local_138[0] == (undefined8 *)0x0) {
          uVar2 = (**(code **)(lVar4 + 0x108))(param_1,0x7d1);
          return uVar2;
        }
        goto LAB_18004b34b;
      }
      if (iVar1 <= param_3) {
        pOVar3 = FUN_1800019d0("");
        *param_5 = pOVar3;
        uVar2 = (**(code **)(*param_1 + 0x108))(param_1,0x7de);
        return uVar2;
      }
    }
    iVar1 = HAIsNamedDimension(*(undefined8 *)(param_1[0x10] + 0x48),param_2 & 0xffffffff,local_138)
    ;
    if (iVar1 == 0) {
      pOVar3 = FUN_1800019d0("");
      *param_5 = pOVar3;
      uVar2 = (**(code **)(*param_1 + 0x108))(param_1,0x7f0);
      return uVar2;
    }
    local_138[0] = (undefined8 *)
                   HAGetLabel(*(undefined8 *)(param_1[0x10] + 0x48),param_2 & 0xffffffff,param_3,
                              local_128);
    if (local_138[0] != (undefined8 *)0x0) {
      pOVar3 = FUN_1800019d0("");
      *param_5 = pOVar3;
      if (*(short *)(local_138[0] + 1) == 6) {
        if ((code *)*local_138[0] == (code *)0x0) {
          return 0;
        }
        (*(code *)*local_138[0])(local_138[0]);
        return 0;
      }
      lVar4 = *param_1;
LAB_18004b34b:
      uVar2 = (**(code **)(lVar4 + 0x100))(param_1);
      return uVar2;
    }
    pCVar5 = local_128;
  }
  local_138[0] = (undefined8 *)0x0;
  pOVar3 = FUN_1800019d0(pCVar5);
  *param_5 = pOVar3;
  return 0;
}

/* ---- FUNC 0004B390 FUN_18004b390 (142 bytes) ---- */

int FUN_18004b390(longlong *param_1,ulonglong param_2,int param_3,short param_4,short *param_5,
                 SAFEARRAYBOUND param_6)

{
  short sVar1;
  short sVar2;
  SAFEARRAYBOUND pvargDest;
  longlong lVar3;
  bool bVar4;
  int iVar5;
  ULONG UVar6;
  HRESULT HVar7;
  code *pcVar8;
  SAFEARRAY *pSVar9;
  void *pvVar10;
  longlong lVar11;
  undefined7 extraout_var;
  BSTR pOVar12;
  IUnknownVtbl *pIVar13;
  int iVar14;
  undefined8 *local_58;
  void *local_50;
  undefined1 local_48 [8];
  IUnknownVtbl *local_40;
  code *local_38;
  
  pvargDest = param_6;
  iVar14 = (int)param_4;
  local_58 = (undefined8 *)0x0;
  *(undefined2 *)param_6 = 0;
  if (DAT_1800797f8 != 0) {
    iVar14 = (**(code **)(*param_1 + 0x108))(param_1,0x7f3);
    return iVar14;
  }
  if (*(longlong *)(param_1[0x10] + 0x48) == 0) {
    iVar14 = (**(code **)(*param_1 + 0x108))(param_1,0x7d9);
    return iVar14;
  }
  iVar5 = *(int *)(param_1[0x10] + 0x160);
  if (iVar5 == -1) {
    iVar14 = (**(code **)(*param_1 + 0x108))(param_1,0x7d1);
    return iVar14;
  }
  if (iVar5 < (int)param_2) {
    return 0;
  }
  if ((*param_5 != 0xb) || (param_5[4] == 0)) {
    iVar5 = (**(code **)(*param_1 + 0x50))(param_1,param_2,&param_6);
    if (iVar5 < 0) {
      return 0;
    }
    if ((int)param_6.cElements <= param_3) {
      return 0;
    }
  }
  UVar6 = HAGetLabelAttrType(*(undefined8 *)(param_1[0x10] + 0x48),param_2 & 0xffffffff,param_3,
                             iVar14,0,&local_58);
  if (UVar6 == 0xfffffc19) {
    if (local_58 == (undefined8 *)0x0) goto LAB_18004b4a1;
    pcVar8 = (code *)*local_58;
  }
  else {
    if (UVar6 == 0) goto LAB_18004b4a1;
    local_58 = (undefined8 *)
               HAGetLabelAttr(*(undefined8 *)(param_1[0x10] + 0x48),param_2 & 0xffffffff,param_3,
                              iVar14,0,local_48);
    if (local_58 == (undefined8 *)0x0) {
      if (local_40 != (IUnknownVtbl *)0x0) {
        if (0 < (int)UVar6) {
          param_6.lLbound = 0;
          param_6.cElements = UVar6;
          pSVar9 = SafeArrayCreate(0x11,1,&param_6);
          if (pSVar9 != (SAFEARRAY *)0x0) {
            iVar14 = (**(code **)(*param_1 + 0x108))(param_1,0x7e1);
            return iVar14;
          }
          HVar7 = SafeArrayAccessData((SAFEARRAY *)0x0,&local_50);
          if (-1 < HVar7) {
            pvVar10 = memcpy(local_50,local_40,(longlong)(int)UVar6);
            if (pvVar10 != (void *)0x0) {
              if (local_38 != (code *)0x0) {
                (*local_38)(local_40);
              }
              SafeArrayUnaccessData((SAFEARRAY *)0x0);
              *(undefined2 *)pvargDest = 0x2000;
              *(undefined8 *)((longlong)pvargDest + 8) = 0;
              return 0;
            }
            if (local_38 != (code *)0x0) {
              (*local_38)(local_40);
            }
            SafeArrayUnaccessData((SAFEARRAY *)0x0);
          }
          iVar14 = (**(code **)(*param_1 + 0x108))(param_1,0x7d1);
          return iVar14;
        }
        switch(UVar6) {
        case 0:
          *(undefined2 *)pvargDest = 0;
          break;
        case 0xfffffff6:
          *(undefined2 *)pvargDest = 9;
          iVar14 = FUN_1800389d0(local_40,(IUnknownVtbl *)param_1[0xf],(IUnknownVtbl *)param_1[0x10]
                                 ,0,(IUnknownVtbl *)((IUnknownVtbl *)param_1[0x10])->Release,
                                 &param_6);
          if (-1 < iVar14) {
            *(ulonglong *)((longlong)pvargDest + 8) = CONCAT44(param_6.lLbound,param_6.cElements);
            return 0;
          }
          return iVar14;
        case 0xfffffffa:
          VariantCopy((VARIANTARG *)pvargDest,(VARIANTARG *)local_40);
          break;
        case 0xfffffffd:
          *(undefined2 *)pvargDest = 8;
          pIVar13 = local_40;
          if (iVar14 == 0x13) {
            lVar3 = -1;
            do {
              lVar11 = lVar3;
              lVar3 = lVar11 + 1;
            } while (*(char *)((longlong)&local_40->QueryInterface + lVar11 + 1) != '\0');
            sVar1 = *(short *)((longlong)&local_40->QueryInterface + lVar11 + 2);
            lVar3 = -1;
            do {
              lVar11 = lVar3;
              lVar3 = lVar11 + 1;
            } while (*(char *)((longlong)&local_40->QueryInterface + lVar11 + 1) != '\0');
            sVar2 = *(short *)((longlong)&local_40->QueryInterface + lVar11 + 4);
            if (((ushort)(sVar2 - 1U) < 999) && (sVar1 != 0)) {
              bVar4 = FUN_18003b1d0(&DAT_180079d50,399,sVar2,sVar1);
              pIVar13 = (IUnknownVtbl *)&DAT_180079d50;
              if ((int)CONCAT71(extraout_var,bVar4) == 0) {
                pIVar13 = local_40;
              }
            }
          }
          pOVar12 = FUN_1800019d0((LPCSTR)pIVar13);
          *(BSTR *)((longlong)pvargDest + 8) = pOVar12;
          break;
        case 0xfffffffe:
          *(undefined2 *)pvargDest = 5;
          *(_func_5156 **)((longlong)pvargDest + 8) = local_40->QueryInterface;
          break;
        case 0xffffffff:
          *(undefined2 *)pvargDest = 3;
          *(undefined4 *)((longlong)pvargDest + 8) = *(undefined4 *)&local_40->QueryInterface;
        }
        if (local_38 != (code *)0x0) {
          (*local_38)(local_40);
        }
        return 0;
      }
      goto LAB_18004b4a1;
    }
    pcVar8 = (code *)*local_58;
  }
  if (pcVar8 != (code *)0x0) {
    (*pcVar8)(local_58);
  }
LAB_18004b4a1:
  *(undefined2 *)pvargDest = 0;
  return 0;
}

/* ---- FUNC 0004B41E FUN_18004b41e (389 bytes) ---- */

int FUN_18004b41e(longlong *param_1,undefined8 param_2)

{
  short sVar1;
  short sVar2;
  longlong lVar3;
  bool bVar4;
  int in_EAX;
  int iVar5;
  HRESULT HVar6;
  code *pcVar7;
  undefined8 *puVar8;
  SAFEARRAY *pSVar9;
  void *pvVar10;
  longlong lVar11;
  undefined7 extraout_var;
  _union_1719 _Var12;
  int unaff_EBX;
  IUnknownVtbl *pvargSrc;
  longlong unaff_RBP;
  VARIANTARG *unaff_RSI;
  longlong *unaff_RDI;
  int unaff_R12D;
  short unaff_R14W;
  int unaff_R15D;
  
  if (in_EAX < unaff_EBX) {
    return 0;
  }
  if ((**(short **)(unaff_RBP + 0x50) != 0xb) || ((*(short **)(unaff_RBP + 0x50))[4] == unaff_R14W))
  {
    iVar5 = (**(code **)(*param_1 + 0x50))(param_1,param_2,unaff_RBP + 0x58);
    if (iVar5 < 0) {
      return 0;
    }
    if (*(int *)(unaff_RBP + 0x58) <= unaff_R15D) {
      return 0;
    }
  }
  iVar5 = HAGetLabelAttrType(*(undefined8 *)(unaff_RDI[0x10] + 0x48),unaff_EBX,unaff_R15D,unaff_R12D
                            );
  if (iVar5 == -999) {
    puVar8 = *(undefined8 **)(unaff_RBP + -0x30);
    if (puVar8 == (undefined8 *)0x0) goto LAB_18004b4a1;
    pcVar7 = (code *)*puVar8;
LAB_18004b49a:
    if (pcVar7 != (code *)0x0) {
      (*pcVar7)(puVar8);
    }
LAB_18004b4a1:
    (unaff_RSI->n1).n2.vt = 0;
    return 0;
  }
  if (iVar5 == 0) goto LAB_18004b4a1;
  puVar8 = (undefined8 *)
           HAGetLabelAttr(*(undefined8 *)(unaff_RDI[0x10] + 0x48),unaff_EBX,unaff_R15D,unaff_R12D,0)
  ;
  *(undefined8 **)(unaff_RBP + -0x30) = puVar8;
  if (puVar8 != (undefined8 *)0x0) {
    pcVar7 = (code *)*puVar8;
    goto LAB_18004b49a;
  }
  pvargSrc = *(IUnknownVtbl **)(unaff_RBP + -0x18);
  if (pvargSrc == (IUnknownVtbl *)0x0) goto LAB_18004b4a1;
  if (0 < iVar5) {
    *(int *)(unaff_RBP + 0x58) = iVar5;
    *(undefined4 *)(unaff_RBP + 0x5c) = 0;
    pSVar9 = SafeArrayCreate(0x11,1,(SAFEARRAYBOUND *)(unaff_RBP + 0x58));
    if (pSVar9 != (SAFEARRAY *)0x0) {
      iVar5 = (**(code **)(*unaff_RDI + 0x108))();
      return iVar5;
    }
    HVar6 = SafeArrayAccessData((SAFEARRAY *)0x0,(void **)(unaff_RBP + -0x28));
    if (-1 < HVar6) {
      pvVar10 = memcpy(*(void **)(unaff_RBP + -0x28),*(void **)(unaff_RBP + -0x18),(longlong)iVar5);
      pcVar7 = *(code **)(unaff_RBP + -0x10);
      if (pvVar10 != (void *)0x0) {
        if (pcVar7 != (code *)0x0) {
          (*pcVar7)();
        }
        SafeArrayUnaccessData((SAFEARRAY *)0x0);
        (unaff_RSI->n1).n2.vt = 0x2000;
        (unaff_RSI->n1).decVal.u2.Lo64 = 0;
        return 0;
      }
      if (pcVar7 != (code *)0x0) {
        (*pcVar7)();
      }
      SafeArrayUnaccessData((SAFEARRAY *)0x0);
    }
    iVar5 = (**(code **)(*unaff_RDI + 0x108))();
    return iVar5;
  }
  switch(iVar5) {
  case 0:
    (unaff_RSI->n1).n2.vt = 0;
    break;
  case -10:
    (unaff_RSI->n1).n2.vt = 9;
    iVar5 = FUN_1800389d0(pvargSrc,(IUnknownVtbl *)unaff_RDI[0xf],(IUnknownVtbl *)unaff_RDI[0x10],0,
                          (IUnknownVtbl *)((IUnknownVtbl *)unaff_RDI[0x10])->Release,
                          (undefined8 *)(unaff_RBP + 0x58));
    if (-1 < iVar5) {
      (unaff_RSI->n1).decVal.u2 = *(_union_1719 *)(unaff_RBP + 0x58);
      return 0;
    }
    return iVar5;
  case -6:
    VariantCopy(unaff_RSI,(VARIANTARG *)pvargSrc);
    goto LAB_18004b6d0;
  case -3:
    (unaff_RSI->n1).n2.vt = 8;
    if (unaff_R12D == 0x13) {
      lVar3 = -1;
      do {
        lVar11 = lVar3;
        lVar3 = lVar11 + 1;
      } while (*(char *)((longlong)&pvargSrc->QueryInterface + lVar11 + 1) != '\0');
      sVar1 = *(short *)((longlong)&pvargSrc->QueryInterface + lVar11 + 2);
      lVar3 = -1;
      do {
        lVar11 = lVar3;
        lVar3 = lVar11 + 1;
      } while (*(char *)((longlong)&pvargSrc->QueryInterface + lVar11 + 1) != '\0');
      sVar2 = *(short *)((longlong)&pvargSrc->QueryInterface + lVar11 + 4);
      if (((ushort)(sVar2 - 1U) < 999) && (sVar1 != 0)) {
        pvargSrc = (IUnknownVtbl *)&DAT_180079d50;
        bVar4 = FUN_18003b1d0(&DAT_180079d50,399,sVar2,sVar1);
        if ((int)CONCAT71(extraout_var,bVar4) == 0) {
          pvargSrc = *(IUnknownVtbl **)(unaff_RBP + -0x18);
        }
      }
    }
    _Var12 = (_union_1719)FUN_1800019d0((LPCSTR)pvargSrc);
    (unaff_RSI->n1).decVal.u2 = _Var12;
LAB_18004b6d0:
    pvargSrc = *(IUnknownVtbl **)(unaff_RBP + -0x18);
    break;
  case -2:
    (unaff_RSI->n1).n2.vt = 5;
    (unaff_RSI->n1).decVal.u2 = (_union_1719)pvargSrc->QueryInterface;
    break;
  case -1:
    (unaff_RSI->n1).n2.vt = 3;
    *(undefined4 *)((longlong)&unaff_RSI->n1 + 8) = *(undefined4 *)&pvargSrc->QueryInterface;
  }
  if (*(code **)(unaff_RBP + -0x10) != (code *)0x0) {
    (**(code **)(unaff_RBP + -0x10))(pvargSrc);
  }
  return 0;
}

/* ---- FUNC 0004B5A3 FUN_18004b5a3 (25 bytes) ---- */

void FUN_18004b5a3(void)

{
  return;
}

/* ---- FUNC 0004B5BC FUN_18004b5bc (303 bytes) ---- */

int FUN_18004b5bc(void)

{
  short sVar1;
  short sVar2;
  longlong lVar3;
  bool bVar4;
  int iVar5;
  longlong lVar6;
  undefined7 extraout_var;
  _union_1719 _Var7;
  IUnknownVtbl *unaff_RBX;
  longlong unaff_RBP;
  VARIANTARG *unaff_RSI;
  longlong unaff_RDI;
  int unaff_R12D;
  undefined4 unaff_R14D;
  
  switch(unaff_R14D) {
  case 0:
    (unaff_RSI->n1).n2.vt = 0;
    break;
  case 0xfffffff6:
    (unaff_RSI->n1).n2.vt = 9;
    iVar5 = FUN_1800389d0(unaff_RBX,*(IUnknownVtbl **)(unaff_RDI + 0x78),
                          *(IUnknownVtbl **)(unaff_RDI + 0x80),0,
                          (IUnknownVtbl *)(*(IUnknownVtbl **)(unaff_RDI + 0x80))->Release,
                          (undefined8 *)(unaff_RBP + 0x58));
    if (-1 < iVar5) {
      (unaff_RSI->n1).decVal.u2 = *(_union_1719 *)(unaff_RBP + 0x58);
      return 0;
    }
    return iVar5;
  case 0xfffffffa:
    VariantCopy(unaff_RSI,(VARIANTARG *)unaff_RBX);
    goto LAB_18004b6d0;
  case 0xfffffffd:
    (unaff_RSI->n1).n2.vt = 8;
    if (unaff_R12D == 0x13) {
      lVar3 = -1;
      do {
        lVar6 = lVar3;
        lVar3 = lVar6 + 1;
      } while (*(char *)((longlong)&unaff_RBX->QueryInterface + lVar6 + 1) != '\0');
      sVar1 = *(short *)((longlong)&unaff_RBX->QueryInterface + lVar6 + 2);
      lVar3 = -1;
      do {
        lVar6 = lVar3;
        lVar3 = lVar6 + 1;
      } while (*(char *)((longlong)&unaff_RBX->QueryInterface + lVar6 + 1) != '\0');
      sVar2 = *(short *)((longlong)&unaff_RBX->QueryInterface + lVar6 + 4);
      if (((ushort)(sVar2 - 1U) < 999) && (sVar1 != 0)) {
        unaff_RBX = (IUnknownVtbl *)&DAT_180079d50;
        bVar4 = FUN_18003b1d0(&DAT_180079d50,399,sVar2,sVar1);
        if ((int)CONCAT71(extraout_var,bVar4) == 0) {
          unaff_RBX = *(IUnknownVtbl **)(unaff_RBP + -0x18);
        }
      }
    }
    _Var7 = (_union_1719)FUN_1800019d0((LPCSTR)unaff_RBX);
    (unaff_RSI->n1).decVal.u2 = _Var7;
LAB_18004b6d0:
    unaff_RBX = *(IUnknownVtbl **)(unaff_RBP + -0x18);
    break;
  case 0xfffffffe:
    (unaff_RSI->n1).n2.vt = 5;
    (unaff_RSI->n1).decVal.u2 = (_union_1719)unaff_RBX->QueryInterface;
    break;
  case 0xffffffff:
    (unaff_RSI->n1).n2.vt = 3;
    *(undefined4 *)((longlong)&unaff_RSI->n1 + 8) = *(undefined4 *)&unaff_RBX->QueryInterface;
  }
  if (*(code **)(unaff_RBP + -0x10) != (code *)0x0) {
    (**(code **)(unaff_RBP + -0x10))(unaff_RBX);
  }
  return 0;
}

/* ---- FUNC 0004B720 FUN_18004b720 (373 bytes) ---- */

undefined8
FUN_18004b720(longlong *param_1,ulonglong param_2,int param_3,short param_4,undefined2 *param_5)

{
  undefined2 *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 *local_28 [2];
  
  puVar1 = param_5;
  local_28[0] = (undefined8 *)0x0;
  *param_5 = 0;
  if (DAT_1800797f8 == 0) {
    if (*(longlong *)(param_1[0x10] + 0x48) == 0) {
      uVar3 = (**(code **)(*param_1 + 0x108))(param_1,0x7d9);
    }
    else {
      iVar2 = *(int *)(param_1[0x10] + 0x160);
      if (iVar2 == -1) {
        uVar3 = (**(code **)(*param_1 + 0x108))(param_1,0x7d1);
      }
      else {
        if ((int)param_2 <= iVar2) {
          iVar2 = (**(code **)(*param_1 + 0x50))(param_1,param_2,&param_5);
          if ((iVar2 < 0) || ((int)param_5 <= param_3)) {
            param_3 = -1;
          }
          iVar2 = HAGetLabelAttrType(*(undefined8 *)(param_1[0x10] + 0x48),param_2 & 0xffffffff,
                                     param_3,(int)param_4,0,local_28);
          if (iVar2 == -999) {
            if ((local_28[0] != (undefined8 *)0x0) && ((code *)*local_28[0] != (code *)0x0)) {
              (*(code *)*local_28[0])();
            }
          }
          else if (iVar2 < 1) {
            switch(iVar2) {
            case 0:
              *puVar1 = 0;
              break;
            case -10:
              *puVar1 = 4;
              break;
            default:
              uVar3 = (**(code **)(*param_1 + 0x108))(param_1,0x7d1);
              return uVar3;
            case -6:
              *puVar1 = 6;
              break;
            case -3:
              *puVar1 = 3;
              break;
            case -2:
              *puVar1 = 2;
              break;
            case -1:
              *puVar1 = 1;
            }
          }
          else {
            *puVar1 = 5;
          }
        }
        uVar3 = 0;
      }
    }
  }
  else {
    uVar3 = (**(code **)(*param_1 + 0x108))(param_1,0x7f3);
  }
  return uVar3;
}

/* ---- FUNC 0004B8D0 FUN_18004b8d0 (380 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined8 FUN_18004b8d0(longlong *param_1,LPCWSTR param_2,int param_3,int *param_4)

{
  undefined1 *puVar1;
  code *pcVar2;
  undefined8 uVar3;
  longlong lVar4;
  ulonglong uVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  int iVar10;
  undefined8 uStack_70;
  undefined1 auStack_68 [32];
  undefined8 uStack_48;
  int aiStack_40 [2];
  undefined8 local_38 [2];
  undefined8 *local_28;
  ulonglong local_20;
  longlong lVar5;
  
  puVar7 = auStack_68;
  local_20 = DAT_180077818 ^ (ulonglong)&local_28;
  puVar8 = (undefined1 *)0x0;
  local_28 = (undefined8 *)0x0;
  if (DAT_1800797f8 == 0) {
    if (*(longlong *)(param_1[0x10] + 0x48) == 0) {
      uStack_70 = 0x18004b93e;
      uVar3 = (**(code **)(*param_1 + 0x108))(param_1,0x7d9);
      puVar7 = auStack_68;
    }
    else if (param_3 < 0) {
      uStack_70 = 0x18004b956;
      uVar3 = (**(code **)(*param_1 + 0x108))(param_1,0x7eb);
    }
    else {
      puVar7 = auStack_68;
      puVar9 = puVar8;
      if (param_2 != (LPCWSTR)0x0) {
        lVar4 = -1;
        do {
          lVar5 = lVar4;
          lVar4 = lVar5 + 1;
        } while (param_2[lVar4] != L'\0');
        iVar10 = (int)lVar5 + 2;
        puVar7 = auStack_68;
        if (iVar10 < 0x40000000) {
          lVar4 = (longlong)(int)lVar4 * 2;
          uVar6 = lVar4 + 0x11;
          if (uVar6 <= lVar4 + 2U) {
            uVar6 = 0xffffffffffffff0;
          }
          uStack_70 = 0x18004b9af;
          lVar4 = -(uVar6 & 0xfffffffffffffff0);
          puVar1 = (undefined1 *)((longlong)&local_28 + lVar4);
          puVar7 = auStack_68 + lVar4;
          if (puVar1 != (undefined1 *)0x0) {
            *(undefined8 *)((longlong)local_38 + lVar4 + 8) = 0;
            *(undefined8 *)((longlong)local_38 + lVar4) = 0;
            *(int *)((longlong)aiStack_40 + lVar4) = iVar10 * 2;
            *(undefined1 **)((longlong)&uStack_48 + lVar4) = puVar1;
            *puVar1 = 0;
            *(undefined8 *)(auStack_68 + lVar4 + -8) = 0x18004b9e9;
            iVar10 = WideCharToMultiByte(0,0,param_2,-1,*(LPSTR *)((longlong)&uStack_48 + lVar4),
                                         *(int *)((longlong)aiStack_40 + lVar4),
                                         *(LPCSTR *)((longlong)local_38 + lVar4),
                                         *(LPBOOL *)((longlong)local_38 + lVar4 + 8));
            puVar7 = auStack_68 + lVar4;
            puVar9 = puVar1;
            if (iVar10 == 0) {
              puVar7 = auStack_68 + lVar4;
              puVar9 = puVar8;
            }
          }
        }
      }
      uVar3 = *(undefined8 *)(param_1[0x10] + 0x48);
      *(undefined8 *)(puVar7 + -8) = 0x18004ba0d;
      iVar10 = HAGetLabelLocation(uVar3,param_3,puVar9,&local_28);
      *param_4 = iVar10;
      if (((iVar10 == -1) && (local_28 != (undefined8 *)0x0)) &&
         (pcVar2 = (code *)*local_28, pcVar2 != (code *)0x0)) {
        *(undefined8 *)(puVar7 + -8) = 0x18004ba28;
        (*pcVar2)();
      }
      uVar3 = 0;
    }
  }
  else {
    uStack_70 = 0x18004b91e;
    uVar3 = (**(code **)(*param_1 + 0x108))(param_1,0x7f3);
    puVar7 = auStack_68;
  }
  *(undefined8 *)(puVar7 + -8) = 0x18004ba36;
  return uVar3;
}

/* ---- FUNC 0004BA50 FUN_18004ba50 (634 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

int FUN_18004ba50(longlong *param_1,ulonglong param_2,ulonglong param_3,short *param_4,
                 longlong *param_5)

{
  wchar_t *pwVar1;
  longlong *plVar2;
  int iVar3;
  IUnknownVtbl *pIVar4;
  BSTR pOVar5;
  longlong lVar6;
  ulonglong uVar8;
  undefined8 uVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  wchar_t *pwVar12;
  wchar_t *pwVar13;
  undefined8 uStackY_150;
  undefined1 auStackY_148 [32];
  int local_118 [2];
  longlong local_110;
  longlong local_108;
  OLECHAR local_100 [4];
  CHAR local_f8;
  char acStack_f7 [31];
  CHAR local_d8 [128];
  ulonglong local_58;
  longlong lVar7;
  
  puVar11 = auStackY_148;
  local_58 = DAT_180077818 ^ (ulonglong)local_118;
  pwVar12 = (wchar_t *)0x0;
  *param_5 = 0;
  if (DAT_1800797f8 == 0) {
    lVar7 = param_1[0x10];
    local_110 = 0;
    if ((lVar7 != 0) && (*(longlong *)(lVar7 + 0x48) != 0)) {
      uStackY_150 = 0x18004bacb;
      FUN_18003c040(lVar7,param_2,param_3,param_4);
      uStackY_150 = 0x18004bae3;
      iVar3 = HAIsNamedDimension(*(undefined8 *)(param_1[0x10] + 0x48),param_2 & 0xffffffff,
                                 &local_110);
      if (iVar3 == 0) {
        uStackY_150 = 0x18004baf9;
        iVar3 = (**(code **)(*param_1 + 0x108))(param_1,0x7f0);
        puVar11 = auStackY_148;
        goto LAB_18004bca7;
      }
      uStackY_150 = 0x18004bb09;
      iVar3 = (**(code **)(*param_1 + 0x50))(param_1,param_2 & 0xffffffff,local_118);
      puVar10 = auStackY_148;
      if ((-1 < iVar3) && (puVar10 = auStackY_148, (int)param_3 < local_118[0])) {
        uStackY_150 = 0x18004bb3f;
        pIVar4 = (IUnknownVtbl *)
                 HAGetLabelNode(*(undefined8 *)(param_1[0x10] + 0x48),param_2 & 0xffffffff,
                                param_3 & 0xffffffff);
        if (pIVar4 == (IUnknownVtbl *)0x0) {
          puVar10 = auStackY_148;
          if (local_110 != 0) {
            uStackY_150 = 0x18004bb60;
            iVar3 = (**(code **)(*param_1 + 0x100))(param_1);
            puVar11 = auStackY_148;
            goto LAB_18004bca7;
          }
        }
        else {
          if (*param_4 == 8) {
            uStackY_150 = 0x18004bb90;
            pOVar5 = FUN_1800019d0(local_d8);
LAB_18004bb90:
            *(BSTR *)(param_4 + 4) = pOVar5;
          }
          else if (*param_4 == 0x4008) {
            uStackY_150 = 0x18004bb81;
            FUN_1800019d0(local_d8);
            pOVar5 = local_100;
            goto LAB_18004bb90;
          }
          uStackY_150 = 0x18004bbbc;
          iVar3 = FUN_1800389d0(pIVar4,(IUnknownVtbl *)param_1[0xf],(IUnknownVtbl *)param_1[0x10],0,
                                (IUnknownVtbl *)((IUnknownVtbl *)param_1[0x10])->Release,&local_108)
          ;
          if (iVar3 < 0) goto LAB_18004bca7;
          *param_5 = local_108;
          puVar10 = auStackY_148;
          if ((param_1[0x10] != 0) &&
             (plVar2 = *(longlong **)(param_1[0x10] + 0xe8), puVar10 = auStackY_148,
             plVar2 != (longlong *)0x0)) {
            uStackY_150 = 0x18004bc02;
            FUN_180002a20(&local_f8,"@LABEL%ldx%ld",param_2 & 0xffffffff,param_3 & 0xffffffff);
            lVar7 = -1;
            do {
              lVar6 = lVar7;
              lVar7 = lVar6 + 1;
            } while (acStack_f7[lVar6] != '\0');
            iVar3 = (int)lVar6 + 2;
            puVar10 = auStackY_148;
            pwVar13 = pwVar12;
            if (iVar3 < 0x40000000) {
              lVar7 = (longlong)(int)(lVar6 + 1) * 2;
              uVar8 = lVar7 + 0x11;
              if (uVar8 <= lVar7 + 2U) {
                uVar8 = 0xffffffffffffff0;
              }
              uStackY_150 = 0x18004bc4d;
              lVar7 = -(uVar8 & 0xfffffffffffffff0);
              pwVar1 = (wchar_t *)((longlong)local_118 + lVar7);
              puVar10 = auStackY_148 + lVar7;
              if (pwVar1 != (wchar_t *)0x0) {
                *(int *)((longlong)local_100 + lVar7 + -0x20) = iVar3;
                *pwVar1 = L'\0';
                *(wchar_t **)(&stack0xfffffffffffffed8 + lVar7) = pwVar1;
                *(undefined8 *)(auStackY_148 + lVar7 + -8) = 0x18004bc7a;
                iVar3 = MultiByteToWideChar(0,0,&local_f8,-1,
                                            *(LPWSTR *)(&stack0xfffffffffffffed8 + lVar7),
                                            *(int *)((longlong)local_100 + lVar7 + -0x20));
                puVar10 = auStackY_148 + lVar7;
                pwVar13 = pwVar1;
                if (iVar3 == 0) {
                  puVar10 = auStackY_148 + lVar7;
                  pwVar13 = pwVar12;
                }
              }
            }
            *(undefined8 *)(puVar10 + -8) = 0x18004bc92;
            FUN_180038480(local_108,plVar2,pwVar13);
          }
        }
      }
      iVar3 = 0;
      puVar11 = puVar10;
      goto LAB_18004bca7;
    }
    lVar7 = *param_1;
    uVar9 = 0x7d9;
  }
  else {
    lVar7 = *param_1;
    uVar9 = 0x7f3;
  }
  uStackY_150 = 0x18004bca7;
  iVar3 = (**(code **)(lVar7 + 0x108))(param_1,uVar9);
  puVar11 = auStackY_148;
LAB_18004bca7:
  *(undefined8 *)(puVar11 + -8) = 0x18004bcb6;
  return iVar3;
}

/* ---- FUNC 0004BCD0 FUN_18004bcd0 (252 bytes) ---- */

undefined8 FUN_18004bcd0(longlong *param_1,undefined8 param_2,int *param_3)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  longlong local_res20;
  
  if (DAT_1800797f8 != 0) {
    uVar3 = (**(code **)(*param_1 + 0x108))(param_1,0x7f3);
    return uVar3;
  }
  local_res20 = 0;
  *param_3 = 0;
  lVar1 = *(longlong *)(param_1[0x10] + 0x48);
  if (lVar1 == 0) {
    uVar3 = (**(code **)(*param_1 + 0x108))(param_1,0x7d9);
    return uVar3;
  }
  iVar2 = *(int *)(param_1[0x10] + 0x160);
  if (iVar2 == -1) {
    uVar3 = (**(code **)(*param_1 + 0x108))(param_1,0x7d1);
    return uVar3;
  }
  if (-1 < (int)param_2) {
    if ((int)param_2 <= iVar2) {
      iVar2 = HAGetLength(lVar1,param_2,&local_res20);
      *param_3 = iVar2;
      if (iVar2 == -1) {
        if (local_res20 != 0) {
          uVar3 = (**(code **)(*param_1 + 0x100))();
          return uVar3;
        }
        uVar3 = (**(code **)(*param_1 + 0x108))(param_1,0x7d1);
        return uVar3;
      }
    }
    return 0;
  }
  uVar3 = (**(code **)(*param_1 + 0x108))(param_1,0x7eb);
  return uVar3;
}

/* ---- FUNC 0004BDD0 FUN_18004bdd0 (688 bytes) ---- */

int FUN_18004bdd0(longlong *param_1,undefined4 *param_2,undefined8 *param_3)

{
  int iVar1;
  SAFEARRAY *pSVar2;
  LONG local_res8 [4];
  ULONG local_res18 [2];
  longlong *local_res20;
  SAFEARRAYBOUND local_178;
  _union_2707 local_170;
  _union_2707 local_158;
  _union_2707 local_140;
  _union_2707 local_128;
  _union_2707 local_110;
  undefined4 local_f8;
  ULONG UStack_f4;
  int iStack_f0;
  undefined4 uStack_ec;
  undefined8 local_e8;
  _union_2707 local_d8;
  undefined8 local_b8;
  _union_1719 _Stack_b0;
  undefined8 local_a8;
  undefined8 local_98;
  _union_1719 _Stack_90;
  undefined8 local_88;
  undefined8 local_78;
  _union_1719 _Stack_70;
  undefined8 local_68;
  undefined8 local_58;
  _union_1719 _Stack_50;
  undefined8 local_48;
  
  (**(code **)(*param_1 + 0x48))(param_1,local_res18);
  local_178.cElements = local_res18[0];
  local_178.lLbound = 0;
  pSVar2 = SafeArrayCreate(0xc,1,&local_178);
  *param_3 = pSVar2;
  local_res8[0] = 0;
  if (0 < (int)local_res18[0]) {
    do {
      local_res20 = (longlong *)0x0;
      local_110._0_8_ = 0;
      local_110.decVal.u2 = (_union_1719)0x0;
      local_110._16_8_ = 0;
      VariantInit((VARIANTARG *)&local_110.n2);
      local_128._0_8_ = 0;
      local_128.decVal.u2.Lo64 = (_union_1719)0x0;
      local_128._16_8_ = 0;
      VariantInit((VARIANTARG *)&local_128.n2);
      local_140._0_8_ = 0;
      local_140.decVal.u2.Lo64 = (_union_1719)0x0;
      local_140._16_8_ = 0;
      VariantInit((VARIANTARG *)&local_140.n2);
      local_158._0_8_ = 0;
      local_158.decVal.u2.Lo64 = (_union_1719)0x0;
      local_158._16_8_ = 0;
      VariantInit((VARIANTARG *)&local_158.n2);
      local_b8 = local_158._0_8_;
      _Stack_b0.Lo64 = (ULONGLONG)local_158.decVal.u2;
      local_a8 = local_158._16_8_;
      local_98 = local_140._0_8_;
      _Stack_90.Lo64 = (ULONGLONG)local_140.decVal.u2;
      local_d8._8_4_ = local_res8[0];
      local_88 = local_140._16_8_;
      local_78 = local_128._0_8_;
      _Stack_70.Lo64 = (ULONGLONG)local_128.decVal.u2;
      local_d8.n2.vt = 3;
      local_68 = local_128._16_8_;
      local_58 = local_110._0_8_;
      _Stack_50 = local_110.decVal.u2;
      local_48 = local_110._16_8_;
      local_f8 = local_d8._0_4_;
      UStack_f4 = local_d8.decVal.Hi32;
      iStack_f0 = local_res8[0];
      uStack_ec = local_d8._12_4_;
      local_e8 = local_d8._16_8_;
      iVar1 = (**(code **)(*param_1 + 0x68))
                        (param_1,&local_f8,&local_58,&local_78,&local_98,&local_b8,&local_res20);
      VariantClear((VARIANTARG *)&local_d8.n2);
      if (iVar1 < 0) {
LAB_18004c040:
        VariantClear((VARIANTARG *)&local_158.n2);
        VariantClear((VARIANTARG *)&local_140.n2);
        VariantClear((VARIANTARG *)&local_128.n2);
        VariantClear((VARIANTARG *)&local_110.n2);
        if (local_res20 == (longlong *)0x0) {
          return iVar1;
        }
        (**(code **)(*local_res20 + 0x10))();
        return iVar1;
      }
      local_170._0_8_ = 0;
      local_170.decVal.u2.Lo64 = (_union_1719)0x0;
      local_170._16_8_ = 0;
      VariantInit((VARIANTARG *)&local_170.n2);
      local_f8 = *param_2;
      UStack_f4 = param_2[1];
      iStack_f0 = param_2[2];
      uStack_ec = param_2[3];
      local_e8 = *(undefined8 *)(param_2 + 4);
      iVar1 = (**(code **)(*local_res20 + 0x68))(local_res20,&local_f8,&local_170);
      if ((iVar1 < 0) ||
         (iVar1 = SafeArrayPutElement((SAFEARRAY *)*param_3,local_res8,&local_170), iVar1 < 0)) {
        VariantClear((VARIANTARG *)&local_170.n2);
        goto LAB_18004c040;
      }
      VariantClear((VARIANTARG *)&local_170.n2);
      VariantClear((VARIANTARG *)&local_158.n2);
      VariantClear((VARIANTARG *)&local_140.n2);
      VariantClear((VARIANTARG *)&local_128.n2);
      VariantClear((VARIANTARG *)&local_110.n2);
      if (local_res20 != (longlong *)0x0) {
        (**(code **)(*local_res20 + 0x10))();
      }
      local_res8[0] = local_res8[0] + 1;
    } while (local_res8[0] < (int)local_res18[0]);
  }
  return 0;
}

/* ---- FUNC 0004C080 FUN_18004c080 (1528 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

ulonglong FUN_18004c080(longlong *param_1,undefined8 *param_2)

{
  int iVar1;
  int iVar2;
  HRESULT HVar3;
  uint uVar4;
  int iVar5;
  ulonglong uVar6;
  int *piVar7;
  int *piVar8;
  ulonglong uVar9;
  SAFEARRAY *psa;
  int *piVar10;
  _union_2707 *p_Var11;
  ulonglong uVar12;
  _union_2709 *p_Var13;
  longlong lVar14;
  undefined8 *puVar15;
  longlong lVar16;
  undefined1 auStack_228 [32];
  undefined8 *local_208;
  undefined8 *local_200;
  _union_1719 *local_1f8;
  int local_1e8;
  int local_1e4;
  undefined8 *local_1e0;
  SAFEARRAY *local_1d8;
  undefined8 *local_1d0;
  SAFEARRAYBOUND local_1c8;
  undefined8 *local_1c0;
  longlong *local_1b8;
  int *local_1b0;
  int *local_1a8;
  longlong *local_1a0;
  undefined8 *local_198;
  longlong local_190;
  _union_1719 local_188;
  longlong local_180;
  _union_2707 local_178;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined4 local_d8;
  ULONG UStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined8 local_c8;
  undefined1 local_b8 [24];
  _union_2707 local_a0;
  _union_2707 local_88;
  _union_2707 local_70;
  _union_2707 local_58;
  ulonglong local_38;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStack_228;
  uVar6 = 0;
  local_1e0 = (undefined8 *)0x0;
  *param_2 = 0;
  local_1d0 = (undefined8 *)0x0;
  local_1c0 = param_2;
  local_1a0 = param_1;
  local_198 = param_2;
  if (DAT_1800797f8 == 0) {
    local_1b8 = param_1 + 0x10;
    iVar5 = *(int *)(*local_1b8 + 0x160);
    lVar16 = (longlong)iVar5;
    local_1e4 = iVar5;
    if (iVar5 == -1) {
      uVar6 = (**(code **)(*param_1 + 0x108))(param_1,0x7d1);
    }
    else {
      lVar14 = lVar16 * 4;
      local_190 = lVar16;
      local_180 = lVar14;
      piVar7 = (int *)MDmalloc(lVar14);
      local_1d8 = (SAFEARRAY *)piVar7;
      if (piVar7 != (int *)0x0) {
        piVar8 = (int *)MDmalloc(lVar14);
        uVar9 = uVar6;
        local_1a8 = piVar8;
        if (piVar8 != (int *)0x0) {
          while( true ) {
            iVar2 = (int)uVar9;
            local_1e8 = iVar2;
            if (iVar5 <= iVar2) break;
            iVar1 = HAGetLength(*(undefined8 *)(*local_1b8 + 0x48),uVar9,&local_1d0);
            local_1b0 = piVar7 + iVar2;
            *local_1b0 = iVar1;
            if (iVar1 == -1) {
              if (local_1d0 == (undefined8 *)0x0) {
                uVar6 = (**(code **)(*param_1 + 0x108))(param_1,0x7d1);
                return uVar6;
              }
              if (*(short *)(local_1d0 + 1) != 6) {
                uVar6 = (**(code **)(*param_1 + 0x100))(param_1);
                return uVar6;
              }
              if ((code *)*local_1d0 != (code *)0x0) {
                (*(code *)*local_1d0)(local_1d0);
              }
              local_1d0 = (undefined8 *)0x0;
              *local_1b0 = 0;
            }
            uVar9 = (ulonglong)(iVar2 + 1);
          }
          VariantInit((VARIANTARG *)&((_union_2707 *)local_b8)->n2);
          local_b8._0_2_ = 10;
          local_b8._8_4_ = 0x80020004;
          VariantInit((VARIANTARG *)&local_a0.n2);
          local_a0.n2.vt = 10;
          local_a0._8_4_ = 0x80020004;
          VariantInit((VARIANTARG *)&local_88.n2);
          local_88.n2.vt = 10;
          local_88._8_4_ = 0x80020004;
          VariantInit((VARIANTARG *)&local_70.n2);
          local_70.n2.vt = 10;
          local_70._8_4_ = 0x80020004;
          VariantInit((VARIANTARG *)&local_58.n2);
          local_58.n2.vt = 10;
          local_58._8_4_ = 0x80020004;
          VariantInit((VARIANTARG *)&local_178.n2);
          if (lVar16 < 1) {
            local_1c8.cElements = 1;
          }
          else {
            p_Var11 = (_union_2707 *)local_b8;
            uVar9 = uVar6;
            do {
              piVar8[uVar9] = 0;
              (p_Var11->n2).vt = 3;
              uVar9 = uVar9 + 1;
              p_Var11 = p_Var11 + 1;
            } while ((longlong)uVar9 < lVar16);
            local_1c8.cElements = 1;
            uVar9 = uVar6;
            do {
              local_1c8.cElements = local_1c8.cElements * piVar7[uVar9];
              uVar9 = uVar9 + 1;
            } while ((longlong)uVar9 < lVar16);
          }
          local_1c8.lLbound = 0;
          psa = SafeArrayCreate(0xc,1,&local_1c8);
          uVar9 = uVar6;
          local_1d8 = psa;
          if (psa == (SAFEARRAY *)0x0) {
            uVar6 = 0x8007000e;
            puVar15 = local_1e0;
          }
          else {
            while (iVar5 = (int)uVar9, *piVar8 < *piVar7) {
              if (0 < lVar16) {
                p_Var13 = &(((_union_2707 *)local_b8)->n2).n3;
                uVar12 = uVar6;
                do {
                  p_Var13->lVal = piVar8[uVar12];
                  uVar12 = uVar12 + 1;
                  p_Var13 = (_union_2709 *)(&p_Var13->lVal + 6);
                } while ((longlong)uVar12 < lVar16);
              }
              local_158 = CONCAT62(local_58._2_6_,local_58.n2.vt);
              uStack_150 = CONCAT44(local_58._12_4_,local_58._8_4_);
              local_148 = local_58._16_8_;
              local_138 = CONCAT62(local_70._2_6_,local_70.n2.vt);
              uStack_130 = CONCAT44(local_70._12_4_,local_70._8_4_);
              local_128 = local_70._16_8_;
              local_118 = CONCAT62(local_88._2_6_,local_88.n2.vt);
              uStack_110 = CONCAT44(local_88._12_4_,local_88._8_4_);
              local_108 = local_88._16_8_;
              local_f8 = CONCAT62(local_a0._2_6_,local_a0.n2.vt);
              uStack_f0 = CONCAT44(local_a0._12_4_,local_a0._8_4_);
              local_e8 = local_a0._16_8_;
              local_d8 = local_b8._0_4_;
              UStack_d4 = local_b8._4_4_;
              uStack_d0 = local_b8._8_4_;
              uStack_cc = local_b8._12_4_;
              local_c8 = local_b8._16_8_;
              local_1f8 = &local_188;
              local_200 = &local_158;
              local_208 = &local_138;
              local_1e4 = iVar5;
              iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_d8,&local_f8,&local_118);
              if (iVar2 < 0) {
                if ((int)param_1[0xe] != 0) {
                  *(undefined4 *)(param_1 + 0xe) = 0;
                }
              }
              else if (local_188.Lo64 != 0) {
                local_178.n2.vt = 9;
                local_178.decVal.u2.Lo64 = local_188;
                HVar3 = SafeArrayPutElement(psa,&local_1e4,&local_178);
                VariantClear((VARIANTARG *)&local_178.n2);
                if (HVar3 < 0) {
                  uVar4 = (**(code **)(*param_1 + 0x108))(param_1,0x7d1);
                  puVar15 = local_1e0;
                  goto LAB_18004c5f6;
                }
                uVar9 = (ulonglong)(iVar5 + 1);
                psa = local_1d8;
              }
              piVar10 = (int *)(local_180 + -4 + (longlong)piVar8);
              *piVar10 = *piVar10 + 1;
              lVar14 = lVar16 + -1;
              if (0 < lVar14) {
                piVar10 = piVar8 + lVar16 + -2;
                do {
                  if (*(int *)((longlong)piVar7 + (4 - (longlong)piVar8) + (longlong)piVar10) <=
                      piVar10[1]) {
                    *piVar10 = *piVar10 + 1;
                    piVar10[1] = 0;
                  }
                  lVar14 = lVar14 + -1;
                  piVar10 = piVar10 + -1;
                } while (0 < lVar14);
              }
            }
            MDfree(piVar7);
            MDfree(piVar8);
            HVar3 = FUN_180047be0(psa,iVar5,&local_1e0);
            puVar15 = local_1e0;
            if (HVar3 < 0) {
              uVar4 = (**(code **)(*param_1 + 0x108))(param_1,0x7e1);
              puVar15 = local_1e0;
            }
            else {
              iVar5 = (**(code **)*local_1e0)(local_1e0,&DAT_180066c58,local_1c0);
              if (-1 < iVar5) {
                SafeArrayDestroy(psa);
                return 0;
              }
              uVar4 = (**(code **)(*param_1 + 0x108))(param_1,0x7d1);
            }
LAB_18004c5f6:
            uVar6 = (ulonglong)uVar4;
          }
          if (puVar15 != (undefined8 *)0x0) {
            FUN_1800473d0(puVar15);
            FUN_180025ad0(puVar15);
          }
          FUN_180025ad0(piVar7);
          FUN_180025ad0(piVar8);
          if (local_1d8 == (SAFEARRAY *)0x0) {
            return uVar6;
          }
          SafeArrayDestroy(local_1d8);
          return uVar6;
        }
        MDfree(piVar7);
      }
      uVar6 = (**(code **)(*param_1 + 0x108))(param_1,0x7e1);
    }
  }
  else {
    uVar6 = (**(code **)(*param_1 + 0x108))(param_1,0x7f3);
  }
  return uVar6;
}

/* ---- FUNC 0004C680 FUN_18004c680 (885 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void FUN_18004c680(longlong *param_1,int param_2,VARIANTARG *param_3,VARIANTARG *param_4,
                  LPCWSTR param_5)

{
  undefined1 *puVar1;
  ushort uVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  code *pcVar5;
  HRESULT HVar6;
  longlong lVar7;
  ulonglong uVar9;
  int iVar10;
  undefined1 *puVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  undefined8 uStack_d0;
  undefined1 auStack_c8 [32];
  LPCWSTR local_a8;
  int aiStack_a0 [2];
  undefined8 local_98 [2];
  VARIANTARG local_88;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_48;
  _union_1719 _Stack_40;
  undefined8 local_38;
  ulonglong local_28;
  longlong lVar8;
  
  puVar11 = auStack_c8;
  local_28 = DAT_180077818 ^ (ulonglong)&local_88;
  uStack_d0 = 0x18004c6d2;
  VariantInit(&local_88);
  if (DAT_1800797f8 != 0) {
    uStack_d0 = 0x18004c6ec;
    (**(code **)(*param_1 + 0x108))(param_1,0x7f3);
    puVar11 = auStack_c8;
    goto LAB_18004c9c3;
  }
  if (*(longlong *)(param_1[0x10] + 0x48) == 0) {
    uStack_d0 = 0x18004c710;
    (**(code **)(*param_1 + 0x108))(param_1,0x7d9);
    puVar11 = auStack_c8;
    goto LAB_18004c9c3;
  }
  uVar2 = (param_4->n1).n2.vt;
  if (uVar2 == 0x400c) {
    puVar3 = *(undefined8 **)((longlong)&param_4->n1 + 8);
    local_68 = *puVar3;
    uStack_60 = puVar3[1];
    local_58 = puVar3[2];
    local_48 = *(undefined8 *)&param_3->n1;
    _Stack_40 = (param_3->n1).decVal.u2;
    local_a8 = param_5;
    local_38 = *(undefined8 *)((longlong)&param_3->n1 + 0x10);
    uStack_d0 = 0x18004c76b;
    (**(code **)(*param_1 + 0x78))(param_1,param_2,&local_48,&local_68);
    puVar11 = auStack_c8;
    goto LAB_18004c9c3;
  }
  puVar14 = (undefined1 *)0x0;
  uVar13 = 0;
  if (uVar2 < 0xc) {
    if (uVar2 == 0xb) {
      uVar13 = (uint)(*(short *)((longlong)&param_4->n1 + 8) != 0);
    }
    else if (uVar2 != 0) {
      if (uVar2 == 2) {
        uVar13 = (int)*(short *)((longlong)&param_4->n1 + 8);
      }
      else if (uVar2 == 3) {
        uVar13 = *(uint *)((longlong)&param_4->n1 + 8);
      }
      else if (uVar2 != 10) goto LAB_18004c7be;
    }
LAB_18004c812:
    uVar2 = (param_3->n1).n2.vt;
    if (uVar2 < 0xb) {
      if ((uVar2 == 10) || (uVar2 == 0)) {
        uVar12 = 0;
      }
      else if (uVar2 == 2) {
        uVar12 = SEXT24(*(short *)((longlong)&param_3->n1 + 8));
      }
      else {
        if (uVar2 != 3) goto LAB_18004c85c;
        uVar12 = *(uint *)((longlong)&param_3->n1 + 8);
      }
    }
    else if (uVar2 == 0x4002) {
      uVar12 = SEXT24(**(short **)((longlong)&param_3->n1 + 8));
    }
    else if (uVar2 == 0x4003) {
      uVar12 = **(uint **)((longlong)&param_3->n1 + 8);
    }
    else {
      if (uVar2 == 0x400c) {
        puVar3 = *(undefined8 **)((longlong)&param_3->n1 + 8);
        local_48 = *(undefined8 *)&param_4->n1;
        _Stack_40 = (param_4->n1).decVal.u2;
        local_38 = *(undefined8 *)((longlong)&param_4->n1 + 0x10);
        local_68 = *puVar3;
        uStack_60 = puVar3[1];
        local_58 = puVar3[2];
        local_a8 = param_5;
        uStack_d0 = 0x18004c8d0;
        (**(code **)(*param_1 + 0x78))(param_1,param_2,&local_68,&local_48);
        goto LAB_18004c9c3;
      }
LAB_18004c85c:
      uStack_d0 = 0x18004c872;
      HVar6 = VariantChangeType(&local_88,param_3,0,3);
      if (HVar6 != 0) goto LAB_18004c7d8;
      uStack_d0 = 0x18004c887;
      VariantClear(&local_88);
      uVar12 = local_88.n1._8_4_;
    }
    if (param_2 < 0) {
      uStack_d0 = 0x18004c8fa;
      (**(code **)(*param_1 + 0x108))(param_1,0x7de);
      puVar11 = auStack_c8;
    }
    else {
      puVar11 = auStack_c8;
      puVar15 = puVar14;
      if (param_5 != (LPCWSTR)0x0) {
        lVar7 = -1;
        do {
          lVar8 = lVar7;
          lVar7 = lVar8 + 1;
        } while (param_5[lVar7] != L'\0');
        iVar10 = (int)lVar8 + 2;
        puVar11 = auStack_c8;
        if (iVar10 < 0x40000000) {
          lVar7 = (longlong)(int)lVar7 * 2;
          uVar9 = lVar7 + 0x11;
          if (uVar9 <= lVar7 + 2U) {
            uVar9 = 0xffffffffffffff0;
          }
          uStack_d0 = 0x18004c954;
          lVar7 = -(uVar9 & 0xfffffffffffffff0);
          puVar1 = (undefined1 *)((longlong)&local_88 + lVar7);
          puVar11 = auStack_c8 + lVar7;
          if (puVar1 != (undefined1 *)0x0) {
            *(undefined8 *)((longlong)local_98 + lVar7 + 8) = 0;
            *(undefined8 *)((longlong)local_98 + lVar7) = 0;
            *(int *)((longlong)aiStack_a0 + lVar7) = iVar10 * 2;
            *puVar1 = 0;
            *(undefined1 **)((longlong)aiStack_a0 + lVar7 + -8) = puVar1;
            *(undefined8 *)(auStack_c8 + lVar7 + -8) = 0x18004c988;
            iVar10 = WideCharToMultiByte(0,0,param_5,-1,
                                         *(LPSTR *)((longlong)aiStack_a0 + lVar7 + -8),
                                         *(int *)((longlong)aiStack_a0 + lVar7),
                                         *(LPCSTR *)((longlong)local_98 + lVar7),
                                         *(LPBOOL *)((longlong)local_98 + lVar7 + 8));
            puVar11 = auStack_c8 + lVar7;
            puVar15 = puVar1;
            if (iVar10 == 0) {
              puVar11 = auStack_c8 + lVar7;
              puVar15 = puVar14;
            }
          }
        }
      }
      lVar7 = param_1[0x10];
      *(undefined4 *)(puVar11 + 0x20) = uVar13;
      uVar4 = *(undefined8 *)(lVar7 + 0x48);
      *(undefined8 *)(puVar11 + -8) = 0x18004c9ae;
      lVar7 = HASetLabel(uVar4,uVar12,param_2,puVar15);
      if (lVar7 != 0) {
        pcVar5 = *(code **)(*param_1 + 0x100);
        *(undefined8 *)(puVar11 + -8) = 0x18004c9c3;
        (*pcVar5)(param_1,lVar7);
      }
    }
  }
  else {
    if (uVar2 == 0x4002) {
      uVar13 = (int)**(short **)((longlong)&param_4->n1 + 8);
      goto LAB_18004c812;
    }
    if (uVar2 == 0x4003) {
      uVar13 = **(uint **)((longlong)&param_4->n1 + 8);
      goto LAB_18004c812;
    }
    if (uVar2 == 0x400b) {
      uVar13 = (uint)(**(short **)((longlong)&param_4->n1 + 8) != 0);
      goto LAB_18004c812;
    }
LAB_18004c7be:
    uStack_d0 = 0x18004c7d4;
    HVar6 = VariantChangeType(&local_88,param_4,0,3);
    uVar13 = local_88.n1._8_4_;
    if (HVar6 == 0) goto LAB_18004c812;
LAB_18004c7d8:
    uStack_d0 = 0x18004c7e9;
    (**(code **)(*param_1 + 0x108))(param_1,0x7d4);
    puVar11 = auStack_c8;
  }
LAB_18004c9c3:
  *(undefined8 *)(puVar11 + -8) = 0x18004c9cf;
  return;
}

/* ---- FUNC 0004CA00 FUN_18004ca00 (728 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined8
FUN_18004ca00(longlong *param_1,int param_2,int param_3,VARIANTARG *param_4,LPCWSTR param_5)

{
  undefined1 *puVar1;
  ushort uVar2;
  undefined4 *puVar3;
  code *pcVar4;
  HRESULT HVar5;
  longlong lVar6;
  ulonglong uVar8;
  int iVar9;
  undefined8 uVar10;
  undefined1 *puVar11;
  undefined4 uVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined8 uStack_a0;
  undefined1 auStack_98 [32];
  LPCWSTR local_78;
  int aiStack_70 [2];
  undefined8 local_68 [2];
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 local_48;
  VARIANTARG local_38;
  ulonglong local_20;
  longlong lVar7;
  
  puVar11 = auStack_98;
  local_20 = DAT_180077818 ^ (ulonglong)&local_58;
  uStack_a0 = 0x18004ca46;
  VariantInit(&local_38);
  if (DAT_1800797f8 == 0) {
    if (*(longlong *)(param_1[0x10] + 0x48) != 0) {
      uVar2 = (param_4->n1).n2.vt;
      if (uVar2 == 0x400c) {
        puVar3 = *(undefined4 **)((longlong)&param_4->n1 + 8);
        local_58 = *puVar3;
        uStack_54 = puVar3[1];
        uStack_50 = puVar3[2];
        uStack_4c = puVar3[3];
        local_48 = *(undefined8 *)(puVar3 + 4);
        local_78 = param_5;
        uStack_a0 = 0x18004cab6;
        uVar10 = (**(code **)(*param_1 + 0x88))(param_1,param_2,param_3,&local_58);
        puVar11 = auStack_98;
        goto LAB_18004ccb2;
      }
      puVar13 = (undefined1 *)0x0;
      uVar12 = 0;
      if (uVar2 < 0xc) {
        if (uVar2 == 0xb) {
          uVar12 = (uint)(*(short *)((longlong)&param_4->n1 + 8) != 0);
        }
        else if (uVar2 != 0) {
          if (uVar2 == 2) {
            uVar12 = (int)*(short *)((longlong)&param_4->n1 + 8);
          }
          else if (uVar2 == 3) {
            uVar12 = *(uint *)((longlong)&param_4->n1 + 8);
          }
          else if (uVar2 != 10) goto LAB_18004cb09;
        }
      }
      else if (uVar2 == 0x4002) {
        uVar12 = (int)**(short **)((longlong)&param_4->n1 + 8);
      }
      else if (uVar2 == 0x4003) {
        uVar12 = **(uint **)((longlong)&param_4->n1 + 8);
      }
      else if (uVar2 == 0x400b) {
        uVar12 = (uint)(**(short **)((longlong)&param_4->n1 + 8) != 0);
      }
      else {
LAB_18004cb09:
        uStack_a0 = 0x18004cb1f;
        HVar5 = VariantChangeType(&local_38,param_4,0,3);
        uVar12 = local_38.n1._8_4_;
        if (HVar5 != 0) {
          uVar10 = 0x7d4;
          goto LAB_18004cca6;
        }
      }
      lVar6 = param_1[0x10];
      if (*(longlong *)(lVar6 + 0x48) != 0) {
        if ((-1 < param_3) && (-1 < param_2)) {
          puVar14 = puVar13;
          if (param_5 != (LPCWSTR)0x0) {
            lVar6 = -1;
            do {
              lVar7 = lVar6;
              lVar6 = lVar7 + 1;
            } while (param_5[lVar6] != L'\0');
            iVar9 = (int)lVar7 + 2;
            puVar11 = auStack_98;
            if (iVar9 < 0x40000000) {
              lVar6 = (longlong)(int)lVar6 * 2;
              uVar8 = lVar6 + 0x11;
              if (uVar8 <= lVar6 + 2U) {
                uVar8 = 0xffffffffffffff0;
              }
              uStack_a0 = 0x18004cbce;
              lVar6 = -(uVar8 & 0xfffffffffffffff0);
              puVar1 = (undefined1 *)((longlong)&local_58 + lVar6);
              puVar11 = auStack_98 + lVar6;
              if (puVar1 != (undefined1 *)0x0) {
                *(undefined8 *)((longlong)local_68 + lVar6 + 8) = 0;
                *(undefined8 *)((longlong)local_68 + lVar6) = 0;
                *(int *)((longlong)aiStack_70 + lVar6) = iVar9 * 2;
                *puVar1 = 0;
                *(undefined1 **)((longlong)aiStack_70 + lVar6 + -8) = puVar1;
                *(undefined8 *)(auStack_98 + lVar6 + -8) = 0x18004cc02;
                iVar9 = WideCharToMultiByte(0,0,param_5,-1,
                                            *(LPSTR *)((longlong)aiStack_70 + lVar6 + -8),
                                            *(int *)((longlong)aiStack_70 + lVar6),
                                            *(LPCSTR *)((longlong)local_68 + lVar6),
                                            *(LPBOOL *)((longlong)local_68 + lVar6 + 8));
                puVar11 = auStack_98 + lVar6;
                puVar14 = puVar1;
                if (iVar9 == 0) {
                  puVar11 = auStack_98 + lVar6;
                  puVar14 = puVar13;
                }
              }
            }
            lVar6 = param_1[0x10];
          }
          uVar10 = *(undefined8 *)(lVar6 + 0x48);
          *(undefined4 *)(puVar11 + 0x20) = uVar12;
          *(undefined8 *)(puVar11 + -8) = 0x18004cc29;
          lVar6 = HASetLabel(uVar10,param_2,param_3,puVar14);
          if (lVar6 == 0) {
            lVar6 = param_1[0x10];
            *(undefined8 *)(puVar11 + -8) = 0x18004cc51;
            FUN_18003d280(lVar6,4);
            if (DAT_18007988c == 0) {
              lVar6 = param_1[0x10];
              *(undefined8 *)(puVar11 + -8) = 0x18004cc8a;
              FUN_1800374c0(0x66,(longlong *)(lVar6 + 0x1d8));
              lVar6 = param_1[0x10];
              lVar7 = *(longlong *)(lVar6 + 0x50);
              *(undefined8 *)(puVar11 + -8) = 0x18004cc9d;
              FUN_180011410(lVar7,lVar6);
              uVar10 = 0;
            }
            else {
              DAT_180079894 = 1;
              uVar10 = 0;
              DAT_180079890 = 1;
            }
          }
          else {
            pcVar4 = *(code **)(*param_1 + 0x100);
            *(undefined8 *)(puVar11 + -8) = 0x18004cc3e;
            uVar10 = (*pcVar4)(param_1,lVar6);
          }
          goto LAB_18004ccb2;
        }
        uVar10 = 0x7de;
        goto LAB_18004cca6;
      }
    }
    uVar10 = 0x7d9;
  }
  else {
    uVar10 = 0x7f3;
  }
LAB_18004cca6:
  uStack_a0 = 0x18004ccb2;
  uVar10 = (**(code **)(*param_1 + 0x108))(param_1,uVar10);
  puVar11 = auStack_98;
LAB_18004ccb2:
  *(undefined8 *)(puVar11 + -8) = 0x18004ccbe;
  return uVar10;
}

/* ---- FUNC 0004CCE0 FUN_18004cce0 (15 bytes) ---- */

void FUN_18004cce0(longlong *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018004cce8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x108))(param_1,0x7d3);
  return;
}

/* ---- FUNC 0004CCF0 FUN_18004ccf0 (48 bytes) ---- */

longlong FUN_18004ccf0(void *param_1,longlong param_2,void *param_3)

{
  memmove(param_3,param_1,param_2 - (longlong)param_1);
  return (param_2 - (longlong)param_1) + (longlong)param_3;
}

/* ---- FUNC 0004CD20 FUN_18004cd20 (328 bytes) ---- */

undefined4 * FUN_18004cd20(longlong *param_1,void *param_2,undefined4 *param_3)

{
  ulonglong uVar1;
  undefined4 *puVar2;
  longlong lVar3;
  code *pcVar4;
  longlong lVar5;
  undefined4 *puVar6;
  ulonglong uVar7;
  void *pvVar8;
  void *pvVar9;
  ulonglong uVar10;
  undefined4 *puVar11;
  
  lVar3 = *param_1;
  lVar5 = param_1[1] - lVar3 >> 2;
  uVar10 = 0x3fffffffffffffff;
  if (lVar5 == 0x3fffffffffffffff) {
    FUN_18004fd90();
    pcVar4 = (code *)swi(3);
    puVar6 = (undefined4 *)(*pcVar4)();
    return puVar6;
  }
  uVar1 = lVar5 + 1;
  uVar7 = param_1[2] - lVar3 >> 2;
  if (0x3fffffffffffffff - (uVar7 >> 1) < uVar7) {
    puVar6 = (undefined4 *)FUN_180001160(0xfffffffffffffffc);
  }
  else {
    uVar7 = (uVar7 >> 1) + uVar7;
    uVar10 = uVar1;
    if (uVar1 <= uVar7) {
      uVar10 = uVar7;
    }
    if (0x3fffffffffffffff < uVar10) {
                    /* WARNING: Subroutine does not return */
      FUN_180002760();
    }
    uVar7 = uVar10 * 4;
    if (uVar7 < 0x1000) {
      if (uVar7 == 0) {
        puVar6 = (undefined4 *)0x0;
      }
      else {
        puVar6 = operator_new(uVar7);
      }
    }
    else {
      puVar6 = (undefined4 *)FUN_180001160(uVar7);
    }
  }
  puVar2 = puVar6 + ((longlong)param_2 - lVar3 >> 2);
  *puVar2 = *param_3;
  pvVar9 = (void *)param_1[1];
  pvVar8 = (void *)*param_1;
  puVar11 = puVar6;
  if (param_2 != pvVar9) {
    FUN_18004ccf0((void *)*param_1,(longlong)param_2,puVar6);
    puVar11 = puVar2 + 1;
    pvVar9 = (void *)param_1[1];
    pvVar8 = param_2;
  }
  FUN_18004ccf0(pvVar8,(longlong)pvVar9,puVar11);
  FID_conflict__Change_array(param_1,(longlong)puVar6,uVar1,uVar10);
  return puVar2;
}

/* ---- FUNC 0004CE70 FUN_18004ce70 (36 bytes) ---- */

VARIANTARG * FUN_18004ce70(VARIANTARG *param_1)

{
  *(undefined8 *)&param_1->n1 = 0;
  (param_1->n1).decVal.u2.Lo64 = 0;
  *(undefined8 *)((longlong)&param_1->n1 + 0x10) = 0;
  VariantInit(param_1);
  return param_1;
}

/* ---- FUNC 0004CEC0 FUN_18004cec0 (269 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18004cec0(LPCWSTR param_1)

{
  longlong lVar1;
  undefined8 uVar3;
  ulonglong uVar4;
  int iVar5;
  char *_Str1;
  undefined1 *puVar6;
  undefined8 uStack_60;
  undefined1 auStack_58 [32];
  undefined8 uStack_38;
  int aiStack_30 [2];
  undefined8 local_28 [2];
  ulonglong local_18 [2];
  longlong lVar2;
  
  local_18[0] = DAT_180077818 ^ (ulonglong)local_18;
  puVar6 = auStack_58;
  if (param_1 != (LPCWSTR)0x0) {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_1[lVar1] != L'\0');
    iVar5 = (int)lVar2 + 2;
    puVar6 = auStack_58;
    if (iVar5 < 0x40000000) {
      lVar1 = (longlong)(int)lVar1 * 2;
      uVar4 = lVar1 + 0x11;
      if (uVar4 <= lVar1 + 2U) {
        uVar4 = 0xffffffffffffff0;
      }
      uStack_60 = 0x18004cf32;
      lVar1 = -(uVar4 & 0xfffffffffffffff0);
      puVar6 = auStack_58 + lVar1;
      _Str1 = (char *)((longlong)local_18 + lVar1);
      if (_Str1 != (char *)0x0) {
        *_Str1 = '\0';
        *(undefined8 *)((longlong)local_28 + lVar1 + 8) = 0;
        *(undefined8 *)((longlong)local_28 + lVar1) = 0;
        *(int *)((longlong)aiStack_30 + lVar1) = iVar5 * 2;
        *(char **)((longlong)&uStack_38 + lVar1) = _Str1;
        *(undefined8 *)(auStack_58 + lVar1 + -8) = 0x18004cf68;
        iVar5 = WideCharToMultiByte(0,0,param_1,-1,*(LPSTR *)((longlong)&uStack_38 + lVar1),
                                    *(int *)((longlong)aiStack_30 + lVar1),
                                    *(LPCSTR *)((longlong)local_28 + lVar1),
                                    *(LPBOOL *)((longlong)local_28 + lVar1 + 8));
        puVar6 = auStack_58 + lVar1;
        if (iVar5 == 0) {
          _Str1 = (char *)0x0;
          puVar6 = auStack_58 + lVar1;
        }
        goto LAB_18004cf75;
      }
    }
  }
  _Str1 = (char *)0x0;
LAB_18004cf75:
  *(undefined8 *)(puVar6 + -8) = 0x18004cf85;
  iVar5 = _stricmp(_Str1,"this");
  if (iVar5 == 0) {
    uVar3 = 0x80000001;
  }
  else {
    *(undefined8 *)(puVar6 + -8) = 0x18004cfa0;
    iVar5 = _stricmp(_Str1,"name");
    if (iVar5 == 0) {
      uVar3 = 0x80000002;
    }
    else {
      *(undefined8 *)(puVar6 + -8) = 0x18004cfb3;
      uVar3 = HAGetAttrNum(_Str1);
    }
  }
  *(undefined8 *)(puVar6 + -8) = 0x18004cfbf;
  return uVar3;
}

/* ---- FUNC 0004CFD0 FUN_18004cfd0 (1372 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18004cfd0(longlong *param_1,longlong *param_2,undefined2 *param_3)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  _union_1719 _Var4;
  int iVar5;
  UINT UVar6;
  HRESULT HVar7;
  ulonglong uVar8;
  SAFEARRAY *pSVar9;
  uint *puVar10;
  uint *puVar11;
  undefined1 auStack_508 [32];
  LONG local_4e8;
  int local_4e4;
  BSTR local_4e0;
  _union_2707 local_4d8;
  SAFEARRAYBOUND local_4c0;
  undefined4 local_4b8;
  undefined4 local_4b4;
  undefined4 local_4a8;
  ULONG UStack_4a4;
  undefined4 uStack_4a0;
  ULONG UStack_49c;
  undefined8 local_498;
  undefined2 *local_488;
  _union_2707 local_480;
  _union_2707 local_468;
  uint *local_450;
  longlong *local_448;
  undefined1 local_438 [1008];
  ulonglong local_48;
  
  local_48 = DAT_180077818 ^ (ulonglong)auStack_508;
  local_468._0_8_ = 0;
  local_468.decVal.u2 = (_union_1719)0x0;
  local_468._16_8_ = 0;
  local_488 = param_3;
  local_448 = param_1;
  VariantInit((VARIANTARG *)&local_468.n2);
  uVar8 = param_2[1] - *param_2 >> 2;
  if (uVar8 < 2) {
    if (uVar8 == 1) {
      uVar1 = *(uint *)*param_2;
      local_4c0.lLbound = 1;
      local_4c0.cElements = *(ULONG *)(param_1 + 1);
      *param_3 = 0x200c;
      pSVar9 = SafeArrayCreate(0xc,1,&local_4c0);
      *(SAFEARRAY **)(param_3 + 4) = pSVar9;
      puVar2 = (undefined8 *)*param_1;
      puVar3 = (undefined8 *)*puVar2;
      local_4e8 = 0;
      for (; puVar3 != puVar2; puVar3 = (undefined8 *)*puVar3) {
        local_4d8._0_8_ = 0;
        local_4d8.decVal.u2.Lo64 = (_union_1719)0x0;
        local_4d8._16_8_ = 0;
        VariantInit((VARIANTARG *)&local_4d8.n2);
        local_4e0 = (BSTR)0x0;
        _Var4 = (_union_1719)((_union_1719 *)(puVar3 + 2))->Lo64;
        if ((BSTR)_Var4.Lo64 != (BSTR)0x0) {
          if (uVar1 == 0x80000001) {
            if ((local_4d8.n2.vt != 9) || ((_union_1719)_Var4.Lo64 != local_4d8.decVal.u2.Lo64)) {
              HVar7 = VariantClear((VARIANTARG *)&local_4d8.n2);
              if (HVar7 < 0) {
                    /* WARNING: Subroutine does not return */
                FUN_180001a90(HVar7);
              }
              local_4d8.n2.vt = 9;
              local_4d8.decVal.u2 = _Var4;
              (**(code **)(*(longlong *)_Var4 + 8))(_Var4.Lo64);
            }
          }
          else if (uVar1 == 0x80000002) {
            local_4a8 = local_468._0_4_;
            UStack_4a4 = local_468.decVal.Hi32;
            uStack_4a0 = local_468._8_4_;
            UStack_49c = local_468._12_4_;
            local_498 = local_468._16_8_;
            iVar5 = (**(code **)(*(longlong *)_Var4 + 0x48))(_Var4.Lo64,&local_4a8,&local_4e0);
            if (iVar5 == 0) {
              HVar7 = VariantClear((VARIANTARG *)&local_4d8.n2);
              if (HVar7 < 0) {
                    /* WARNING: Subroutine does not return */
                FUN_180001a90(HVar7);
              }
              local_4d8.n2.vt = 8;
              if (local_4e0 == (BSTR)0x0) {
                local_4d8.decVal.u2.Lo64 = (_union_1719)0x0;
              }
              else {
                UVar6 = SysStringByteLen(local_4e0);
                local_4d8.decVal.u2 = (_union_1719)SysAllocStringByteLen((LPCSTR)local_4e0,UVar6);
                if (local_4d8.decVal.u2.Lo64 != (_union_1719)0x0) goto LAB_18004d48b;
              }
              if (local_4e0 != (BSTR)0x0) {
                local_4d8.n2.vt = 10;
                local_4d8._8_4_ = 0x8007000e;
                    /* WARNING: Subroutine does not return */
                FUN_180001a90(-0x7ff8fff2);
              }
            }
          }
          else if (uVar1 != 0xffffffff) {
            local_4a8 = local_468._0_4_;
            UStack_4a4 = local_468.decVal.Hi32;
            uStack_4a0 = local_468._8_4_;
            UStack_49c = local_468._12_4_;
            local_498 = local_468._16_8_;
            (**(code **)(*(longlong *)_Var4 + 0x98))
                      (_Var4.Lo64,uVar1 & 0xffff,&local_4a8,&local_4d8);
          }
        }
LAB_18004d48b:
        SafeArrayPutElement(*(SAFEARRAY **)(local_488 + 4),&local_4e8,&local_4d8);
        SysFreeString(local_4e0);
        VariantClear((VARIANTARG *)&local_4d8.n2);
        local_4e8 = local_4e8 + 1;
      }
    }
  }
  else {
    local_480._0_8_ = 0;
    local_480.decVal.u2.Lo64 = (_union_1719)0x0;
    local_480._16_8_ = 0;
    VariantInit((VARIANTARG *)&local_480.n2);
    local_4c0.lLbound = 1;
    local_4c0.cElements = *(ULONG *)(param_1 + 1);
    local_4b4 = 1;
    local_4b8 = (undefined4)(param_2[1] - *param_2 >> 2);
    local_4e8 = 0;
    *param_3 = 0x200c;
    pSVar9 = SafeArrayCreate(0xc,2,&local_4c0);
    *(SAFEARRAY **)(param_3 + 4) = pSVar9;
    puVar11 = (uint *)*param_2;
    puVar10 = (uint *)param_2[1];
    local_4e4 = 1;
    local_450 = puVar10;
    if (puVar11 != puVar10) {
      do {
        uVar1 = *puVar11;
        puVar2 = (undefined8 *)*param_1;
        puVar3 = (undefined8 *)*puVar2;
        local_4e8 = 1;
        param_1 = local_448;
        for (; local_448 = param_1, puVar3 != puVar2; puVar3 = (undefined8 *)*puVar3) {
          local_4d8._0_8_ = 0;
          local_4d8.decVal.u2.Lo64 = (_union_1719)0x0;
          local_4d8._16_8_ = 0;
          VariantInit((VARIANTARG *)&local_4d8.n2);
          local_4e0 = (BSTR)0x0;
          _Var4 = (_union_1719)((_union_1719 *)(puVar3 + 2))->Lo64;
          if ((BSTR)_Var4.Lo64 != (BSTR)0x0) {
            if (uVar1 == 0x80000001) {
              if ((local_4d8.n2.vt != 9) || ((_union_1719)_Var4.Lo64 != local_4d8.decVal.u2.Lo64)) {
                HVar7 = VariantClear((VARIANTARG *)&local_4d8.n2);
                if (HVar7 < 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_180001a90(HVar7);
                }
                local_4d8.n2.vt = 9;
                local_4d8.decVal.u2 = _Var4;
                (**(code **)(*(longlong *)_Var4 + 8))(_Var4.Lo64);
              }
            }
            else if (uVar1 == 0x80000002) {
              local_4a8 = local_480._0_4_;
              UStack_4a4 = local_480.decVal.Hi32;
              uStack_4a0 = local_480._8_4_;
              UStack_49c = local_480._12_4_;
              local_498 = local_480._16_8_;
              iVar5 = (**(code **)(*(longlong *)_Var4 + 0x48))(_Var4.Lo64,&local_4a8,&local_4e0);
              if (iVar5 == 0) {
                HVar7 = VariantClear((VARIANTARG *)&local_4d8.n2);
                if (HVar7 < 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_180001a90(HVar7);
                }
                local_4d8.n2.vt = 8;
                if (local_4e0 == (BSTR)0x0) {
                  local_4d8.decVal.u2.Lo64 = (_union_1719)0x0;
                }
                else {
                  UVar6 = SysStringByteLen(local_4e0);
                  local_4d8.decVal.u2 = (_union_1719)SysAllocStringByteLen((LPCSTR)local_4e0,UVar6);
                  if (local_4d8.decVal.u2.Lo64 != (_union_1719)0x0) goto LAB_18004d224;
                }
                if (local_4e0 != (BSTR)0x0) {
                  local_4d8.n2.vt = 10;
                  local_4d8._8_4_ = 0x8007000e;
                    /* WARNING: Subroutine does not return */
                  FUN_180001a90(-0x7ff8fff2);
                }
              }
            }
            else if (uVar1 != 0xffffffff) {
              local_4a8 = local_480._0_4_;
              UStack_4a4 = local_480.decVal.Hi32;
              uStack_4a0 = local_480._8_4_;
              UStack_49c = local_480._12_4_;
              local_498 = local_480._16_8_;
              (**(code **)(*(longlong *)_Var4 + 0x98))
                        (_Var4.Lo64,uVar1 & 0xffff,&local_4a8,&local_4d8);
            }
          }
LAB_18004d224:
          HVar7 = SafeArrayPutElement(*(SAFEARRAY **)(local_488 + 4),&local_4e8,&local_4d8);
          if (HVar7 < 0) {
            FUN_180002a20(local_438,"Assert failed in file %s line %d",
                          "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnodesel.cpp",0x2b4);
            LogMessage(local_438,2,1);
          }
          SysFreeString(local_4e0);
          VariantClear((VARIANTARG *)&local_4d8.n2);
          local_4e8 = local_4e8 + 1;
          puVar10 = local_450;
          param_1 = local_448;
        }
        puVar11 = puVar11 + 1;
        local_4e4 = local_4e4 + 1;
      } while (puVar11 != puVar10);
    }
    VariantClear((VARIANTARG *)&local_480.n2);
  }
  VariantClear((VARIANTARG *)&local_468.n2);
  return 0;
}

/* ---- FUNC 0004D530 FUN_18004d530 (59 bytes) ---- */

longlong FUN_18004d530(longlong *param_1,ushort *param_2)

{
  ushort uVar1;
  SAFEARRAY *psa;
  int *piVar2;
  undefined4 *puVar3;
  UINT UVar4;
  HRESULT HVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  uint uVar8;
  longlong *plVar9;
  int local_res10 [2];
  ushort *local_res18 [2];
  
  uVar1 = *param_2;
  if ((uVar1 >> 0xd & 1) == 0) {
    uVar7 = FUN_18004fb40(param_2);
    local_res10[0] = (int)uVar7;
    if (local_res10[0] == -1) {
      return 0x80070057;
    }
    piVar2 = (int *)param_1[1];
    if (piVar2 == (int *)param_1[2]) {
      FUN_18004cd20(param_1,piVar2,local_res10);
    }
    else {
      *piVar2 = local_res10[0];
      param_1[1] = param_1[1] + 4;
    }
  }
  else {
    psa = *(SAFEARRAY **)(param_2 + 4);
    UVar4 = SafeArrayGetDim(psa);
    if (1 < UVar4) {
      return 0x80070057;
    }
    UVar4 = SafeArrayGetElemsize(psa);
    HVar5 = SafeArrayAccessData(psa,local_res18);
    if (HVar5 == 0) {
      uVar8 = 0;
      if (psa->rgsabound[0].cElements != 0) {
        do {
          local_res10[0] = -1;
          switch(uVar1 & 0xfff) {
          case 2:
          case 0xb:
            local_res10[0] = (int)(short)*local_res18[0];
            break;
          case 3:
            local_res10[0] = *(int *)local_res18[0];
            break;
          default:
            goto switchD_18004d5cc_caseD_4;
          case 8:
            uVar6 = FUN_18004cec0(*(LPCWSTR *)local_res18[0]);
            local_res10[0] = (int)uVar6;
            break;
          case 0xc:
            uVar7 = FUN_18004fb40(local_res18[0]);
            local_res10[0] = (int)uVar7;
            break;
          case 0x10:
            local_res10[0] = (int)(char)*local_res18[0];
          }
          if (local_res10[0] != -1) {
            piVar2 = (int *)param_1[1];
            if (piVar2 == (int *)param_1[2]) {
              FUN_18004cd20(param_1,piVar2,local_res10);
            }
            else {
              *piVar2 = local_res10[0];
              param_1[1] = param_1[1] + 4;
            }
          }
switchD_18004d5cc_caseD_4:
          local_res18[0] = (ushort *)((longlong)local_res18[0] + (ulonglong)UVar4);
          uVar8 = uVar8 + 1;
        } while (uVar8 < psa->rgsabound[0].cElements);
      }
      SafeArrayUnaccessData(psa);
    }
  }
  plVar9 = param_1 + 1;
  puVar3 = (undefined4 *)*plVar9;
  if ((undefined4 *)*param_1 == puVar3) {
    local_res10[0] = 0;
    if (puVar3 == (undefined4 *)param_1[2]) {
      FUN_18004cd20(param_1,puVar3,local_res10);
    }
    else {
      *puVar3 = 0;
      *plVar9 = *plVar9 + 4;
    }
  }
  return *plVar9 - *param_1 >> 2;
}

/* ---- FUNC 0004D56B FUN_18004d56b (55 bytes) ---- */

longlong FUN_18004d56b(SAFEARRAY *param_1)

{
  longlong *plVar1;
  int *piVar2;
  undefined4 *puVar3;
  UINT UVar4;
  HRESULT HVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  uint uVar8;
  undefined2 unaff_BP;
  SAFEARRAY *unaff_RSI;
  longlong *unaff_RDI;
  int in_stack_00000058;
  ushort *in_stack_00000060;
  
  UVar4 = SafeArrayGetElemsize(param_1);
  HVar5 = SafeArrayAccessData(unaff_RSI,&stack0x00000060);
  if (HVar5 == 0) {
    uVar8 = 0;
    if (unaff_RSI->rgsabound[0].cElements != 0) {
      do {
        in_stack_00000058 = -1;
        switch(unaff_BP) {
        case 2:
        case 0xb:
          in_stack_00000058 = (int)(short)*in_stack_00000060;
          break;
        case 3:
          in_stack_00000058 = *(int *)in_stack_00000060;
          break;
        default:
          goto switchD_18004d5cc_caseD_4;
        case 8:
          uVar7 = FUN_18004cec0(*(LPCWSTR *)in_stack_00000060);
          in_stack_00000058 = (int)uVar7;
          break;
        case 0xc:
          uVar6 = FUN_18004fb40(in_stack_00000060);
          in_stack_00000058 = (int)uVar6;
          break;
        case 0x10:
          in_stack_00000058 = (int)(char)*in_stack_00000060;
        }
        if (in_stack_00000058 != -1) {
          piVar2 = (int *)unaff_RDI[1];
          if (piVar2 == (int *)unaff_RDI[2]) {
            FUN_18004cd20(unaff_RDI,piVar2,&stack0x00000058);
          }
          else {
            *piVar2 = in_stack_00000058;
            unaff_RDI[1] = unaff_RDI[1] + 4;
          }
        }
switchD_18004d5cc_caseD_4:
        in_stack_00000060 = (ushort *)((longlong)in_stack_00000060 + (ulonglong)UVar4);
        uVar8 = uVar8 + 1;
      } while (uVar8 < unaff_RSI->rgsabound[0].cElements);
    }
    SafeArrayUnaccessData(unaff_RSI);
  }
  plVar1 = unaff_RDI + 1;
  puVar3 = (undefined4 *)*plVar1;
  if ((undefined4 *)*unaff_RDI == puVar3) {
    in_stack_00000058 = 0;
    if (puVar3 == (undefined4 *)unaff_RDI[2]) {
      FUN_18004cd20(unaff_RDI,puVar3,&stack0x00000058);
    }
    else {
      *puVar3 = 0;
      *plVar1 = *plVar1 + 4;
    }
  }
  return *plVar1 - *unaff_RDI >> 2;
}

/* ---- FUNC 0004D5A2 FUN_18004d5a2 (153 bytes) ---- */

longlong FUN_18004d5a2(undefined8 param_1,ushort *param_2)

{
  longlong *plVar1;
  int *piVar2;
  undefined4 *puVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  uint unaff_EBX;
  undefined4 unaff_EBP;
  SAFEARRAY *unaff_RSI;
  longlong *unaff_RDI;
  longlong unaff_R14;
  int iStack0000000000000058;
  ushort *in_stack_00000060;
  
  do {
    iStack0000000000000058 = -1;
    switch(unaff_EBP) {
    case 2:
    case 0xb:
      iStack0000000000000058 = (int)(short)*param_2;
      break;
    case 3:
      iStack0000000000000058 = *(int *)param_2;
      break;
    default:
      goto switchD_18004d5cc_caseD_4;
    case 8:
      uVar5 = FUN_18004cec0(*(LPCWSTR *)param_2);
      iStack0000000000000058 = (int)uVar5;
      param_2 = in_stack_00000060;
      break;
    case 0xc:
      uVar4 = FUN_18004fb40(param_2);
      iStack0000000000000058 = (int)uVar4;
      param_2 = in_stack_00000060;
      break;
    case 0x10:
      iStack0000000000000058 = (int)(char)*param_2;
    }
    if (iStack0000000000000058 != -1) {
      piVar2 = (int *)unaff_RDI[1];
      if (piVar2 == (int *)unaff_RDI[2]) {
        FUN_18004cd20(unaff_RDI,piVar2,&stack0x00000058);
        param_2 = in_stack_00000060;
      }
      else {
        *piVar2 = iStack0000000000000058;
        unaff_RDI[1] = unaff_RDI[1] + 4;
        param_2 = in_stack_00000060;
      }
    }
switchD_18004d5cc_caseD_4:
    param_2 = (ushort *)((longlong)param_2 + unaff_R14);
    unaff_EBX = unaff_EBX + 1;
    in_stack_00000060 = param_2;
    if (unaff_RSI->rgsabound[0].cElements <= unaff_EBX) {
      SafeArrayUnaccessData(unaff_RSI);
      plVar1 = unaff_RDI + 1;
      puVar3 = (undefined4 *)*plVar1;
      if ((undefined4 *)*unaff_RDI == puVar3) {
        iStack0000000000000058 = 0;
        if (puVar3 == (undefined4 *)unaff_RDI[2]) {
          FUN_18004cd20(unaff_RDI,puVar3,&stack0x00000058);
        }
        else {
          *puVar3 = 0;
          *plVar1 = *plVar1 + 4;
        }
      }
      return *plVar1 - *unaff_RDI >> 2;
    }
  } while( true );
}

/* ---- FUNC 0004D63B FUN_18004d63b (20 bytes) ---- */

longlong FUN_18004d63b(void)

{
  longlong *plVar1;
  undefined4 *puVar2;
  SAFEARRAY *unaff_RSI;
  longlong *unaff_RDI;
  undefined4 in_stack_00000058;
  
  SafeArrayUnaccessData(unaff_RSI);
  plVar1 = unaff_RDI + 1;
  puVar2 = (undefined4 *)*plVar1;
  if ((undefined4 *)*unaff_RDI == puVar2) {
    in_stack_00000058 = 0;
    if (puVar2 == (undefined4 *)unaff_RDI[2]) {
      FUN_18004cd20(unaff_RDI,puVar2,&stack0x00000058);
    }
    else {
      *puVar2 = 0;
      *plVar1 = *plVar1 + 4;
    }
  }
  return *plVar1 - *unaff_RDI >> 2;
}

/* ---- FUNC 0004D64F FUN_18004d64f (140 bytes) ---- */

longlong FUN_18004d64f(undefined8 param_1,ushort *param_2)

{
  longlong *plVar1;
  int *piVar2;
  undefined4 *puVar3;
  ulonglong uVar4;
  longlong *unaff_RDI;
  int in_stack_00000058;
  
  uVar4 = FUN_18004fb40(param_2);
  in_stack_00000058 = (int)uVar4;
  if (in_stack_00000058 == -1) {
    return 0x80070057;
  }
  piVar2 = (int *)unaff_RDI[1];
  plVar1 = unaff_RDI + 1;
  if (piVar2 == (int *)unaff_RDI[2]) {
    FUN_18004cd20(unaff_RDI,piVar2,&stack0x00000058);
  }
  else {
    *piVar2 = in_stack_00000058;
    *plVar1 = *plVar1 + 4;
  }
  puVar3 = (undefined4 *)*plVar1;
  if ((undefined4 *)*unaff_RDI == puVar3) {
    in_stack_00000058 = 0;
    if (puVar3 == (undefined4 *)unaff_RDI[2]) {
      FUN_18004cd20(unaff_RDI,puVar3,&stack0x00000058);
    }
    else {
      *puVar3 = 0;
      *plVar1 = *plVar1 + 4;
    }
  }
  return *plVar1 - *unaff_RDI >> 2;
}

/* ---- FUNC 0004D720 FUN_18004d720 (697 bytes) ---- */

undefined4 FUN_18004d720(longlong *param_1,longlong *param_2,ushort *param_3)

{
  SAFEARRAY *psa;
  longlong lVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  UINT UVar4;
  HRESULT HVar5;
  longlong *plVar6;
  uint uVar7;
  ushort uVar8;
  longlong *local_res18;
  longlong *local_res20;
  longlong *local_78;
  SAFEARRAY *local_70;
  longlong *local_68;
  longlong *local_60;
  undefined8 local_58;
  longlong *local_50;
  undefined8 local_48;
  
  uVar8 = *param_3;
  if ((uVar8 >> 0xd & 1) == 0) {
    if (uVar8 == 8) {
      local_res18 = (longlong *)0x0;
      (**(code **)(*param_1 + 0x110))(param_1,*(undefined8 *)(param_3 + 4),&local_res18);
      plVar3 = local_res18;
      local_res20 = local_res18;
      if (local_res18 != (longlong *)0x0) {
        (**(code **)(*local_res18 + 8))(local_res18);
      }
      lVar1 = *param_2;
      if (param_2[1] == 0xaaaaaaaaaaaaaaa) {
                    /* WARNING: Subroutine does not return */
        std::_Xlength_error("list too long");
      }
      local_48 = 0;
      local_50 = param_2;
      plVar6 = operator_new(0x18);
      plVar6[2] = (longlong)plVar3;
      param_2[1] = param_2[1] + 1;
      puVar2 = *(undefined8 **)(lVar1 + 8);
      *plVar6 = lVar1;
      plVar6[1] = (longlong)puVar2;
      *(longlong **)(lVar1 + 8) = plVar6;
      *puVar2 = plVar6;
      if (local_res18 != (longlong *)0x0) {
        (**(code **)(*local_res18 + 0x10))();
      }
    }
  }
  else {
    psa = *(SAFEARRAY **)(param_3 + 4);
    uVar8 = uVar8 & 0xfff;
    local_70 = psa;
    UVar4 = SafeArrayGetDim(psa);
    if ((1 < UVar4) || ((uVar8 - 8 & 0xfffb) != 0)) {
      return 0x80070057;
    }
    UVar4 = SafeArrayGetElemsize(psa);
    local_res18 = (longlong *)CONCAT44(local_res18._4_4_,UVar4);
    HVar5 = SafeArrayAccessData(psa,&local_res20);
    if (HVar5 == 0) {
      uVar7 = 0;
      if (local_70->rgsabound[0].cElements != 0) {
        do {
          if (uVar8 == 8) {
            local_78 = (longlong *)0x0;
            (**(code **)(*param_1 + 0x110))(param_1,*local_res20,&local_78);
            plVar3 = local_78;
            local_68 = local_78;
            if (local_78 != (longlong *)0x0) {
              (**(code **)(*local_78 + 8))(local_78);
            }
            lVar1 = *param_2;
            if (param_2[1] == 0xaaaaaaaaaaaaaaa) {
                    /* WARNING: Subroutine does not return */
              std::_Xlength_error("list too long");
            }
            local_48 = 0;
            local_50 = param_2;
            plVar6 = operator_new(0x18);
            plVar6[2] = (longlong)plVar3;
            param_2[1] = param_2[1] + 1;
            puVar2 = *(undefined8 **)(lVar1 + 8);
            *plVar6 = lVar1;
            plVar6[1] = (longlong)puVar2;
            local_48 = 0;
            *(longlong **)(lVar1 + 8) = plVar6;
            *puVar2 = plVar6;
LAB_18004d8cf:
            if (local_78 != (longlong *)0x0) {
              (**(code **)(*local_78 + 0x10))();
            }
          }
          else if ((uVar8 == 0xc) && ((short)*local_res20 == 8)) {
            local_78 = (longlong *)0x0;
            (**(code **)(*param_1 + 0x110))(param_1,local_res20[1],&local_78);
            plVar3 = local_78;
            local_68 = local_78;
            if (local_78 != (longlong *)0x0) {
              (**(code **)(*local_78 + 8))(local_78);
            }
            lVar1 = *param_2;
            if (param_2[1] == 0xaaaaaaaaaaaaaaa) {
                    /* WARNING: Subroutine does not return */
              std::_Xlength_error("list too long");
            }
            local_58 = 0;
            local_60 = param_2;
            plVar6 = operator_new(0x18);
            plVar6[2] = (longlong)plVar3;
            param_2[1] = param_2[1] + 1;
            puVar2 = *(undefined8 **)(lVar1 + 8);
            *plVar6 = lVar1;
            plVar6[1] = (longlong)puVar2;
            local_58 = 0;
            *(longlong **)(lVar1 + 8) = plVar6;
            *puVar2 = plVar6;
            goto LAB_18004d8cf;
          }
          local_res20 = (longlong *)((longlong)local_res20 + ((ulonglong)local_res18 & 0xffffffff));
          uVar7 = uVar7 + 1;
        } while (uVar7 < local_70->rgsabound[0].cElements);
      }
      SafeArrayUnaccessData(local_70);
    }
  }
  return (int)param_2[1];
}

/* ---- FUNC 0004D9E0 FUN_18004d9e0 (1311 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FUN_18004d9e0(longlong *param_1)

{
  longlong *plVar1;
  LPCSTR lpMultiByteStr;
  longlong *plVar2;
  undefined8 *puVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  HRESULT HVar8;
  BSTR pOVar9;
  longlong *plVar10;
  longlong lVar11;
  _union_2707 *pvarg;
  int iVar12;
  int *piVar13;
  undefined1 auStackY_1f8 [32];
  int local_1b8 [2];
  longlong *local_1b0;
  longlong *local_1a8;
  BSTR local_1a0;
  longlong *local_198;
  longlong *local_190;
  undefined8 local_188;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined4 local_f8;
  ULONG UStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined8 local_e8;
  int local_d8 [8];
  _union_2707 local_b8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_38;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStackY_1f8;
  iVar12 = 0;
  local_1b0 = (longlong *)0x0;
  local_198 = param_1;
  if ((*(int *)(param_1[2] + -0x10) == 0) ||
     (iVar6 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         (param_1 + 2),"."), iVar6 == 0)) {
    plVar1 = (longlong *)*param_1;
    plVar2 = local_1b0;
    if (local_1b0 != plVar1) {
      if (plVar1 != (longlong *)0x0) {
        (**(code **)(*plVar1 + 8))(plVar1);
      }
      plVar2 = plVar1;
      if (local_1b0 != (longlong *)0x0) {
        lVar11 = *local_1b0;
        plVar2 = local_1b0;
        local_1b0 = plVar1;
        (**(code **)(lVar11 + 0x10))(plVar2);
        plVar2 = local_1b0;
      }
    }
  }
  else {
    plVar1 = (longlong *)*param_1;
    lpMultiByteStr = (LPCSTR)param_1[2];
    if (lpMultiByteStr == (LPCSTR)0x0) {
      local_1a0 = (BSTR)0x0;
    }
    else {
      iVar6 = MultiByteToWideChar(0,0,lpMultiByteStr,-1,(LPWSTR)0x0,0);
      pOVar9 = SysAllocStringLen((OLECHAR *)0x0,iVar6 - 1);
      if ((pOVar9 != (BSTR)0x0) &&
         (iVar7 = MultiByteToWideChar(0,0,lpMultiByteStr,-1,pOVar9,iVar6), iVar7 != iVar6)) {
        SysFreeString(pOVar9);
LAB_18004dee0:
                    /* WARNING: Subroutine does not return */
        FUN_180001a90(-0x7ff8fff2);
      }
      local_1a0 = pOVar9;
      if (pOVar9 == (BSTR)0x0) goto LAB_18004dee0;
    }
    pOVar9 = local_1a0;
    (**(code **)(*plVar1 + 0x110))(plVar1,local_1a0,&local_1b0);
    SysFreeString(pOVar9);
    plVar2 = local_1b0;
  }
  local_1b0 = plVar2;
  if (local_1b0 != (longlong *)0x0) {
    local_1b8[0] = 0;
    (**(code **)(*local_1b0 + 0x58))(local_1b0,local_1b8);
    plVar1 = local_1b0;
    if (local_1b8[0] < 1) {
      local_198 = local_1b0;
      if (local_1b0 != (longlong *)0x0) {
        (**(code **)(*local_1b0 + 8))(local_1b0);
      }
      plVar2 = (longlong *)param_1[1];
      lVar11 = *plVar2;
      if (plVar2[1] == 0xaaaaaaaaaaaaaaa) {
                    /* WARNING: Subroutine does not return */
        std::_Xlength_error("list too long");
      }
      local_188 = 0;
      local_190 = plVar2;
      plVar10 = operator_new(0x18);
      plVar10[2] = (longlong)plVar1;
      plVar2[1] = plVar2[1] + 1;
      puVar3 = *(undefined8 **)(lVar11 + 8);
      *plVar10 = lVar11;
      plVar10[1] = (longlong)puVar3;
      *(longlong **)(lVar11 + 8) = plVar10;
      *puVar3 = plVar10;
    }
    else {
      local_1a0 = (BSTR)0x0;
      iVar7 = (**(code **)(*local_1b0 + 200))(local_1b0,&local_1a0);
      iVar6 = iVar12;
      if (iVar7 == 0) {
        while( true ) {
          local_1a8 = (longlong *)CONCAT44(local_1a8._4_4_,iVar6);
          if (local_1b8[0] <= iVar6) break;
          local_d8[iVar6] = 0;
          (**(code **)(*(longlong *)local_1a0 + 0x50))(local_1a0,iVar6);
          iVar6 = iVar6 + 1;
        }
        _eh_vector_constructor_iterator_
                  (&local_b8,0x18,5,FUN_18004ce70,(_func_void_void_ptr *)&DAT_1800015e0);
        if (0 < local_1b8[0]) {
          pvarg = &local_b8;
          iVar6 = local_1b8[0];
          do {
            if ((((_union_2707 *)&(pvarg->n2).vt)->n2).vt != 3) {
              HVar8 = VariantClear((VARIANTARG *)&pvarg->n2);
              if (HVar8 < 0) {
                    /* WARNING: Subroutine does not return */
                FUN_180001a90(HVar8);
              }
              (((_union_2707 *)&(pvarg->n2).vt)->n2).vt = 3;
              iVar6 = local_1b8[0];
            }
            (pvarg->n2).n3.lVal = 0;
            iVar12 = iVar12 + 1;
            pvarg = pvarg + 1;
          } while (iVar12 < iVar6);
        }
        bVar4 = true;
        do {
          local_1a8 = (longlong *)0x0;
          local_178 = local_58;
          uStack_170 = uStack_50;
          local_168 = local_48;
          local_158 = local_70;
          uStack_150 = uStack_68;
          local_148 = local_60;
          local_138 = local_88;
          uStack_130 = uStack_80;
          local_128 = local_78;
          local_118 = local_a0;
          uStack_110 = uStack_98;
          local_108 = local_90;
          local_f8 = local_b8._0_4_;
          UStack_f4 = local_b8.decVal.Hi32;
          uStack_f0 = local_b8._8_4_;
          uStack_ec = local_b8._12_4_;
          local_e8 = local_b8._16_8_;
          iVar12 = (**(code **)(*(longlong *)local_1a0 + 0x68))
                             (local_1a0,&local_f8,&local_118,&local_138);
          plVar1 = local_1a8;
          if ((iVar12 == 0) && (local_1a8 != (longlong *)0x0)) {
            local_198 = local_1a8;
            (**(code **)(*local_1a8 + 8))(local_1a8);
            plVar2 = (longlong *)param_1[1];
            lVar11 = *plVar2;
            if (plVar2[1] == 0xaaaaaaaaaaaaaaa) {
                    /* WARNING: Subroutine does not return */
              std::_Xlength_error("list too long");
            }
            local_188 = 0;
            local_190 = plVar2;
            plVar10 = operator_new(0x18);
            plVar10[2] = (longlong)plVar1;
            plVar2[1] = plVar2[1] + 1;
            puVar3 = *(undefined8 **)(lVar11 + 8);
            *plVar10 = lVar11;
            plVar10[1] = (longlong)puVar3;
            local_188 = 0;
            *(longlong **)(lVar11 + 8) = plVar10;
            *puVar3 = plVar10;
          }
          lVar11 = (longlong)(local_1b8[0] + -1);
          if (-1 < local_1b8[0] + -1) {
            piVar13 = (int *)((longlong)&local_b8 + lVar11 * 0x18 + 8);
            do {
              iVar12 = 0;
              if (*piVar13 + 1 < local_d8[lVar11]) {
                iVar12 = *piVar13 + 1;
              }
              *piVar13 = iVar12;
              if (iVar12 != 0) break;
              piVar13 = piVar13 + -6;
              bVar5 = false;
              if (lVar11 != 0) {
                bVar5 = bVar4;
              }
              bVar4 = bVar5;
              lVar11 = lVar11 + -1;
            } while (-1 < lVar11);
          }
          if (local_1a8 != (longlong *)0x0) {
            (**(code **)(*local_1a8 + 0x10))(local_1a8);
          }
        } while (bVar4);
        _eh_vector_destructor_iterator_(&local_b8,0x18,5,(_func_void_void_ptr *)&DAT_1800015e0);
      }
      if (local_1a0 != (BSTR)0x0) {
        (**(code **)(*(longlong *)local_1a0 + 0x10))();
      }
    }
  }
  lVar11 = *(longlong *)(param_1[1] + 8);
  if (local_1b0 != (longlong *)0x0) {
    (**(code **)(*local_1b0 + 0x10))();
  }
  return lVar11 != 0;
}

/* ---- FUNC 0004DF00 FUN_18004df00 (884 bytes) ---- */

undefined8 FUN_18004df00(longlong param_1,wchar_t *param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  bool bVar7;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  undefined7 extraout_var;
  ulonglong uVar8;
  undefined8 uVar9;
  longlong *local_res8;
  undefined8 local_res20;
  longlong *local_1d8;
  longlong **local_1d0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_1c8 [8];
  longlong *local_1c0;
  undefined8 local_1b8;
  undefined8 local_1b0;
  undefined8 local_1a8;
  undefined8 local_1a0;
  undefined8 local_198;
  undefined8 local_190;
  _union_2707 local_188;
  _union_2707 local_170;
  _union_2707 local_158;
  undefined4 local_140;
  ULONG UStack_13c;
  undefined4 uStack_138;
  ULONG UStack_134;
  undefined4 local_128;
  ULONG UStack_124;
  undefined4 uStack_120;
  ULONG UStack_11c;
  undefined8 local_118;
  undefined4 local_108;
  ULONG UStack_104;
  undefined4 uStack_100;
  ULONG UStack_fc;
  undefined8 local_f8;
  undefined4 local_e8;
  ULONG UStack_e4;
  undefined4 uStack_e0;
  ULONG UStack_dc;
  undefined8 local_d8;
  undefined4 local_c8;
  ULONG UStack_c4;
  undefined4 uStack_c0;
  ULONG UStack_bc;
  undefined8 local_b8;
  undefined4 local_a8;
  ULONG UStack_a4;
  undefined4 uStack_a0;
  ULONG UStack_9c;
  undefined8 local_98;
  undefined4 local_88;
  ULONG UStack_84;
  undefined4 uStack_80;
  ULONG UStack_7c;
  undefined8 local_78;
  undefined8 local_68;
  _union_1719 _Stack_60;
  undefined8 local_58;
  undefined4 local_48;
  ULONG UStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  
  plVar1 = *(longlong **)(param_1 + 0x10);
  local_res8 = (longlong *)0x0;
  uVar9 = 0x80004005;
  if (plVar1 == (longlong *)0x0) {
    (**(code **)(*DAT_1800797f0 + 0x90))(DAT_1800797f0,&local_res8);
    plVar1 = local_res8;
  }
  else {
    (**(code **)(*plVar1 + 8))(plVar1);
    if (local_res8 != (longlong *)0x0) {
      lVar2 = *local_res8;
      local_res8 = plVar1;
      (**(code **)(lVar2 + 0x10))();
      plVar1 = local_res8;
    }
  }
  local_res8 = plVar1;
  if (local_res8 != (longlong *)0x0) {
    local_1b8 = 0;
    local_1c0 = operator_new(0x18);
    plVar1 = local_res8;
    *local_1c0 = (longlong)local_1c0;
    local_1c0[1] = (longlong)local_1c0;
    this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
           CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                     ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
                      param_2);
    local_1d8 = plVar1;
    if (plVar1 != (longlong *)0x0) {
      (**(code **)(*plVar1 + 8))(plVar1);
    }
    local_1d0 = &local_1c0;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              (local_1c8,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)this);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this);
    bVar7 = FUN_18004d9e0((longlong *)&local_1d8);
    if ((((int)CONCAT71(extraout_var,bVar7) != 0) && (local_1d0[1] != (longlong *)0x0)) &&
       (uVar8 = FUN_180019120(DAT_1800797f0,(char *)0x0,param_3,0), uVar9 = 0, (int)uVar8 == 0)) {
      local_158._8_4_ = 0xffffffff;
      local_158.n2.vt = 3;
      local_188._16_8_ = 0;
      local_188._0_8_ = 0;
      local_188.decVal.u2.Lo64 = (_union_1719)0x0;
      VariantInit((VARIANTARG *)&local_188.n2);
      plVar1 = *local_1d0;
      uVar5 = local_res20;
      local_res20 = local_188._16_8_;
      for (plVar3 = (longlong *)*plVar1; local_188._16_8_ = local_res20, plVar3 != plVar1;
          plVar3 = (longlong *)*plVar3) {
        local_170.decVal.u2 = (_union_1719)((_union_1719 *)(plVar3 + 2))->Lo64;
        local_170.n2.vt = 9;
        local_188.decVal.Hi32 = (ULONG)((ulonglong)local_188._0_8_ >> 0x20);
        local_140 = local_188._0_4_;
        UStack_13c = local_188.decVal.Hi32;
        uStack_138 = local_188._8_4_;
        UStack_134 = local_188._12_4_;
        local_1b0 = local_res20;
        local_1a8 = local_res20;
        local_1a0 = local_res20;
        local_198 = local_res20;
        local_190 = local_res20;
        if (local_170.decVal.u2.Lo64 != (_union_1719)0x0) {
          (**(code **)(*(longlong *)local_170.decVal.u2 + 8))();
        }
        local_118 = local_res20;
        local_f8 = local_1b0;
        local_d8 = local_1a8;
        local_b8 = local_1a0;
        local_98 = local_198;
        local_78 = local_190;
        local_68 = CONCAT62(local_170._2_6_,local_170.n2.vt);
        local_58 = local_170._16_8_;
        _Stack_60.Lo64 = (ULONGLONG)local_170.decVal.u2;
        local_48 = local_158._0_4_;
        UStack_44 = local_158.decVal.Hi32;
        uStack_40 = local_158._8_4_;
        uStack_3c = local_158._12_4_;
        local_38 = local_158._16_8_;
        local_128 = local_140;
        UStack_124 = UStack_13c;
        uStack_120 = uStack_138;
        UStack_11c = UStack_134;
        local_108 = local_140;
        UStack_104 = UStack_13c;
        uStack_100 = uStack_138;
        UStack_fc = UStack_134;
        local_e8 = local_140;
        UStack_e4 = UStack_13c;
        uStack_e0 = uStack_138;
        UStack_dc = UStack_134;
        local_c8 = local_140;
        UStack_c4 = UStack_13c;
        uStack_c0 = uStack_138;
        UStack_bc = UStack_134;
        local_a8 = local_140;
        UStack_a4 = UStack_13c;
        uStack_a0 = uStack_138;
        UStack_9c = UStack_134;
        local_88 = local_140;
        UStack_84 = UStack_13c;
        uStack_80 = uStack_138;
        UStack_7c = UStack_134;
        (**(code **)(*(longlong *)*param_3 + 0x78))
                  ((longlong *)*param_3,&local_48,0,&local_68,0,&local_88,&local_a8,&local_c8,
                   &local_e8,&local_108,&local_128);
        VariantClear((VARIANTARG *)&local_170.n2);
        uVar5 = local_res20;
        local_res20 = local_188._16_8_;
      }
      local_res20 = uVar5;
      VariantClear((VARIANTARG *)&local_188.n2);
      VariantClear((VARIANTARG *)&local_158.n2);
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1c8);
    if (local_1d8 != (longlong *)0x0) {
      (**(code **)(*local_1d8 + 0x10))();
    }
    *(undefined8 *)local_1c0[1] = 0;
    puVar6 = (undefined8 *)*local_1c0;
    while (puVar6 != (undefined8 *)0x0) {
      puVar4 = (undefined8 *)*puVar6;
      if ((longlong *)puVar6[2] != (longlong *)0x0) {
        (**(code **)(*(longlong *)puVar6[2] + 0x10))();
      }
      FUN_180025ad0(puVar6);
      puVar6 = puVar4;
    }
    FUN_180025ad0(local_1c0);
    if (local_res8 != (longlong *)0x0) {
      (**(code **)(*local_res8 + 0x10))(local_res8);
    }
  }
  return uVar9;
}

/* ---- FUNC 0004E280 FUN_18004e280 (626 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_18004e280(longlong param_1,wchar_t *param_2,undefined8 *param_3,short *param_4)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  bool bVar5;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  undefined7 extraout_var;
  void *pvVar6;
  ulonglong uVar7;
  undefined1 auStack_4b8 [32];
  longlong *local_498 [2];
  longlong *local_488;
  undefined8 **ppuStack_480;
  undefined8 local_478 [2];
  undefined8 *local_468;
  undefined8 local_460;
  void *local_458;
  undefined8 uStack_450;
  longlong local_448;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_440 [8];
  undefined1 local_438 [1008];
  ulonglong local_48;
  
  local_48 = DAT_180077818 ^ (ulonglong)auStack_4b8;
  if ((*param_4 != 0) && (*param_4 != 10)) {
    FUN_180002a20(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnodesel.cpp",0xab);
    LogMessage(local_438,2,1);
  }
  local_478[0] = param_3[2];
  local_458 = (void *)0x0;
  uStack_450 = 0;
  local_488 = (longlong *)*param_3;
  ppuStack_480 = (undefined8 **)param_3[1];
  local_448 = 0;
  FUN_18004d530((longlong *)&local_458,(ushort *)&local_488);
  plVar1 = *(longlong **)(param_1 + 0x10);
  uVar7 = 0x80004005;
  local_498[0] = (longlong *)0x0;
  if (plVar1 == (longlong *)0x0) {
    (**(code **)(*DAT_1800797f0 + 0x90))(DAT_1800797f0,local_498);
    plVar1 = local_498[0];
  }
  else {
    (**(code **)(*plVar1 + 8))(plVar1);
    if (local_498[0] != (longlong *)0x0) {
      lVar2 = *local_498[0];
      local_498[0] = plVar1;
      (**(code **)(lVar2 + 0x10))();
      plVar1 = local_498[0];
    }
  }
  local_498[0] = plVar1;
  if (local_498[0] != (longlong *)0x0) {
    local_460 = 0;
    local_468 = operator_new(0x18);
    plVar1 = local_498[0];
    *local_468 = local_468;
    local_468[1] = local_468;
    this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
           CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_440,param_2);
    local_488 = plVar1;
    if (plVar1 != (longlong *)0x0) {
      (**(code **)(*plVar1 + 8))(plVar1);
    }
    ppuStack_480 = &local_468;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_478,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)this);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this);
    bVar5 = FUN_18004d9e0((longlong *)&local_488);
    if (((int)CONCAT71(extraout_var,bVar5) != 0) && (ppuStack_480[1] != (undefined8 *)0x0)) {
      uVar7 = FUN_18004cfd0((longlong *)&local_468,(longlong *)&local_458,param_4);
      uVar7 = uVar7 & 0xffffffff;
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_478);
    if (local_488 != (longlong *)0x0) {
      (**(code **)(*local_488 + 0x10))();
    }
    *(undefined8 *)local_468[1] = 0;
    puVar4 = (undefined8 *)*local_468;
    while (puVar4 != (undefined8 *)0x0) {
      puVar3 = (undefined8 *)*puVar4;
      if ((longlong *)puVar4[2] != (longlong *)0x0) {
        (**(code **)(*(longlong *)puVar4[2] + 0x10))();
      }
      FUN_180025ad0(puVar4);
      puVar4 = puVar3;
    }
    FUN_180025ad0(local_468);
    if (local_498[0] != (longlong *)0x0) {
      (**(code **)(*local_498[0] + 0x10))(local_498[0]);
    }
  }
  if (local_458 != (void *)0x0) {
    pvVar6 = local_458;
    if ((0xfff < (local_448 - (longlong)local_458 & 0xfffffffffffffffcU)) &&
       (pvVar6 = *(void **)((longlong)local_458 + -8),
       0x1f < (ulonglong)((longlong)local_458 + (-8 - (longlong)pvVar6)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180025ad0(pvVar6);
  }
  return uVar7;
}

/* ---- FUNC 0004E500 FUN_18004e500 (933 bytes) ---- */

ulonglong FUN_18004e500(longlong param_1,ushort *param_2,undefined8 *param_3,undefined2 *param_4)

{
  ushort uVar1;
  SAFEARRAY *psa;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  UINT UVar5;
  int iVar6;
  longlong *plVar7;
  undefined8 *puVar8;
  longlong *plVar9;
  ulonglong uVar10;
  longlong *local_res10;
  longlong *local_78;
  undefined8 local_70;
  longlong *local_68;
  undefined8 uStack_60;
  longlong local_58;
  longlong *local_48;
  undefined8 uStack_40;
  longlong local_38;
  
  uVar1 = *param_2;
  uVar10 = 0x80004005;
  if ((uVar1 >> 0xd & 1) == 0) {
    if ((uVar1 & 8) == 0) {
      return 0x80004005;
    }
    local_58 = param_3[2];
    local_48 = (longlong *)0x0;
    uStack_40 = 0;
    local_68 = (longlong *)*param_3;
    uStack_60 = param_3[1];
    local_38 = 0;
    FUN_18004d530((longlong *)&local_48,(ushort *)&local_68);
    plVar9 = *(longlong **)(param_1 + 0x10);
    local_res10 = (longlong *)0x0;
    if (plVar9 == (longlong *)0x0) {
      (**(code **)(*DAT_1800797f0 + 0x90))(DAT_1800797f0,&local_res10);
      plVar9 = local_res10;
    }
    else {
      (**(code **)(*plVar9 + 8))(plVar9);
      if (local_res10 != (longlong *)0x0) {
        lVar2 = *local_res10;
        local_res10 = plVar9;
        (**(code **)(lVar2 + 0x10))();
        plVar9 = local_res10;
      }
    }
    local_res10 = plVar9;
    plVar7 = operator_new(0x18);
    uVar3 = *(undefined8 *)(param_2 + 4);
    *plVar7 = (longlong)plVar7;
    plVar7[1] = (longlong)plVar7;
    local_78 = (longlong *)0x0;
    local_68 = plVar7;
    iVar6 = (**(code **)(*local_res10 + 0x110))(local_res10,uVar3,&local_78);
    plVar9 = local_78;
    if (iVar6 == 0) {
      if (local_78 != (longlong *)0x0) {
        (**(code **)(*local_78 + 8))(local_78);
      }
      puVar8 = operator_new(0x18);
      uStack_60 = 1;
      puVar8[2] = plVar9;
      puVar4 = (undefined8 *)plVar7[1];
      puVar8[1] = puVar4;
      *puVar8 = plVar7;
      plVar7[1] = (longlong)puVar8;
      *puVar4 = puVar8;
      FUN_18004cfd0((longlong *)&local_68,(longlong *)&local_48,param_4);
    }
    if (local_78 != (longlong *)0x0) {
      (**(code **)(*local_78 + 0x10))();
    }
    *(undefined8 *)plVar7[1] = 0;
    puVar4 = (undefined8 *)*plVar7;
    while (puVar4 != (undefined8 *)0x0) {
      puVar8 = (undefined8 *)*puVar4;
      if ((longlong *)puVar4[2] != (longlong *)0x0) {
        (**(code **)(*(longlong *)puVar4[2] + 0x10))();
      }
      FUN_180025ad0(puVar4);
      puVar4 = puVar8;
    }
    FUN_180025ad0(plVar7);
    if (local_res10 != (longlong *)0x0) {
      (**(code **)(*local_res10 + 0x10))();
    }
    if (local_48 == (longlong *)0x0) {
      return 0x80004005;
    }
    plVar9 = local_48;
    if ((0xfff < (local_38 - (longlong)local_48 & 0xfffffffffffffffcU)) &&
       (plVar9 = (longlong *)local_48[-1],
       0x1f < (ulonglong)((longlong)local_48 + (-8 - (longlong)plVar9)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
  }
  else {
    psa = *(SAFEARRAY **)(param_2 + 4);
    UVar5 = SafeArrayGetDim(psa);
    if (((1 < UVar5) || (((uVar1 & 0xfff) - 8 & 0xfffb) != 0)) || (psa->rgsabound[0].cElements == 0)
       ) {
      return 0x80070057;
    }
    local_38 = param_3[2];
    local_68 = (longlong *)0x0;
    uStack_60 = 0;
    local_48 = (longlong *)*param_3;
    uStack_40 = param_3[1];
    local_58 = 0;
    FUN_18004d530((longlong *)&local_68,(ushort *)&local_48);
    plVar9 = *(longlong **)(param_1 + 0x10);
    local_res10 = (longlong *)0x0;
    if (plVar9 == (longlong *)0x0) {
      (**(code **)(*DAT_1800797f0 + 0x90))(DAT_1800797f0,&local_res10);
      plVar9 = local_res10;
    }
    else {
      (**(code **)(*plVar9 + 8))(plVar9);
      if (local_res10 != (longlong *)0x0) {
        lVar2 = *local_res10;
        local_res10 = plVar9;
        (**(code **)(lVar2 + 0x10))();
        plVar9 = local_res10;
      }
    }
    local_res10 = plVar9;
    local_70 = 0;
    local_78 = operator_new(0x18);
    local_48 = *(longlong **)param_2;
    uStack_40 = *(undefined8 *)(param_2 + 4);
    local_38 = *(longlong *)(param_2 + 8);
    *local_78 = (longlong)local_78;
    local_78[1] = (longlong)local_78;
    iVar6 = FUN_18004d720(local_res10,(longlong *)&local_78,(ushort *)&local_48);
    if (0 < iVar6) {
      uVar10 = FUN_18004cfd0((longlong *)&local_78,(longlong *)&local_68,param_4);
      uVar10 = uVar10 & 0xffffffff;
    }
    *(undefined8 *)local_78[1] = 0;
    puVar4 = (undefined8 *)*local_78;
    while (puVar4 != (undefined8 *)0x0) {
      puVar8 = (undefined8 *)*puVar4;
      if ((longlong *)puVar4[2] != (longlong *)0x0) {
        (**(code **)(*(longlong *)puVar4[2] + 0x10))();
      }
      FUN_180025ad0(puVar4);
      puVar4 = puVar8;
    }
    FUN_180025ad0(local_78);
    if (local_res10 != (longlong *)0x0) {
      (**(code **)(*local_res10 + 0x10))();
    }
    if (local_68 == (longlong *)0x0) {
      return uVar10;
    }
    plVar9 = local_68;
    if ((0xfff < (local_58 - (longlong)local_68 & 0xfffffffffffffffcU)) &&
       (plVar9 = (longlong *)local_68[-1],
       0x1f < (ulonglong)((longlong)local_68 + (-8 - (longlong)plVar9)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
  }
  FUN_180025ad0(plVar9);
  return uVar10;
}

/* ---- FUNC 0004E8B0 FUN_18004e8b0 (2199 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_18004e8b0(longlong param_1,BSTR param_2,int param_3,undefined8 *param_4,short *param_5)

{
  uint uVar1;
  longlong *plVar2;
  longlong lVar3;
  _union_1719 _Var4;
  UINT UVar5;
  ULONG UVar6;
  int iVar7;
  HRESULT HVar8;
  SAFEARRAY *pSVar9;
  longlong *plVar10;
  ulonglong uVar11;
  uint *puVar12;
  undefined4 uVar13;
  int iVar14;
  uint *puVar15;
  undefined1 auStack_558 [32];
  _union_1719 *local_538;
  _union_2707 *local_530;
  ULONG local_528 [2];
  LONG local_520;
  int local_51c;
  _union_1719 local_518;
  _union_2707 local_510;
  longlong *local_4f8;
  longlong *local_4f0;
  longlong *local_4e8;
  _union_1719 local_4e0;
  int local_4d8 [2];
  SAFEARRAYBOUND local_4d0;
  undefined4 local_4c8;
  undefined4 local_4c4;
  _union_2707 local_4b8;
  _union_1719 local_498;
  undefined4 uStack_490;
  ULONG UStack_48c;
  undefined8 local_488;
  short *local_478;
  _union_2707 local_470;
  uint *local_458;
  uint *puStack_450;
  longlong local_448;
  undefined1 local_438 [1008];
  ulonglong local_48;
  
  local_48 = DAT_180077818 ^ (ulonglong)auStack_558;
  local_478 = param_5;
  if ((*param_5 != 0) && (*param_5 != 10)) {
    FUN_180002a20(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnodesel.cpp",0xcb);
    LogMessage(local_438,2,1);
  }
  local_4b8._16_8_ = param_4[2];
  local_448 = 0;
  local_458 = (uint *)0x0;
  puStack_450 = (uint *)0x0;
  local_4b8._0_8_ = *param_4;
  local_4b8.decVal.u2 = *(_union_1719 *)(param_4 + 1);
  FUN_18004d530((longlong *)&local_458,(ushort *)&local_4b8);
  plVar2 = *(longlong **)(param_1 + 0x10);
  uVar13 = 0x80004005;
  local_4e8 = (longlong *)0x0;
  if (plVar2 == (longlong *)0x0) {
    (**(code **)(*DAT_1800797f0 + 0x90))(DAT_1800797f0,&local_4e8);
    plVar2 = local_4e8;
  }
  else {
    (**(code **)(*plVar2 + 8))(plVar2);
    if (local_4e8 != (longlong *)0x0) {
      lVar3 = *local_4e8;
      local_4e8 = plVar2;
      (**(code **)(lVar3 + 0x10))();
      plVar2 = local_4e8;
    }
  }
  local_4e8 = plVar2;
  puVar12 = local_458;
  if (local_4e8 == (longlong *)0x0) goto LAB_18004ede9;
  local_4f0 = (longlong *)0x0;
  if (((param_2 == (BSTR)0x0) || (UVar5 = SysStringLen(param_2), UVar5 == 0)) ||
     ((*param_2 == L'.' && (param_2[1] == L'\0')))) {
    plVar2 = local_4e8;
    if (local_4f0 != local_4e8) {
      plVar10 = local_4f0;
      if (local_4e8 != (longlong *)0x0) {
        (**(code **)(*local_4e8 + 8))(local_4e8);
        plVar10 = local_4f0;
      }
      local_4f0 = plVar2;
      if (plVar10 != (longlong *)0x0) {
        (**(code **)(*plVar10 + 0x10))(plVar10);
      }
    }
  }
  else {
    (**(code **)(*local_4e8 + 0x110))(local_4e8,param_2,&local_4f0);
  }
  if (local_4f0 == (longlong *)0x0) goto LAB_18004ede9;
  local_4d8[0] = 0;
  (**(code **)(*local_4f0 + 0x58))(local_4f0,local_4d8);
  if ((local_4d8[0] < 1) || (local_4d8[0] <= param_3)) {
    uVar13 = 0x80004005;
LAB_18004f0a0:
    if (local_4f0 != (longlong *)0x0) {
      (**(code **)(*local_4f0 + 0x10))();
    }
  }
  else {
    local_4f8 = (longlong *)0x0;
    UVar6 = (**(code **)(*local_4f0 + 200))(local_4f0,&local_4f8);
    if (UVar6 == 0) {
      local_528[0] = UVar6;
      (**(code **)(*local_4f8 + 0x50))(local_4f8,param_3,local_528);
      if (local_528[0] == 0) {
        uVar13 = 1;
        if (local_4f8 != (longlong *)0x0) {
          (**(code **)(*local_4f8 + 0x10))();
        }
        goto LAB_18004f0a0;
      }
      local_4b8._0_8_ = 0;
      local_4b8.decVal.u2.Lo64 = (_union_1719)0x0;
      local_4b8._16_8_ = 0;
      VariantInit((VARIANTARG *)&local_4b8.n2);
      puVar15 = puStack_450;
      uVar11 = (longlong)puStack_450 - (longlong)puVar12 >> 2;
      if (uVar11 < 2) {
        if (uVar11 == 1) {
          uVar1 = *puVar12;
          local_4d0.lLbound = 1;
          local_4d0.cElements = local_528[0];
          *param_5 = 0x200c;
          pSVar9 = SafeArrayCreate(0xc,1,&local_4d0);
          iVar14 = 0;
          local_520 = 1;
          *(SAFEARRAY **)(param_5 + 4) = pSVar9;
          if (0 < (int)local_528[0]) {
            do {
              local_510._0_8_ = 0;
              local_510.decVal.u2.Lo64 = (_union_1719)0x0;
              local_510._16_8_ = 0;
              VariantInit((VARIANTARG *)&local_510.n2);
              local_518.Lo64 = 0;
              local_4e0.Lo64 = 0;
              if (uVar1 == 0x80000001) {
                local_538 = &local_4e0;
                (**(code **)(*local_4f8 + 0x90))(local_4f8,param_3,iVar14,&local_4b8);
                _Var4 = local_4e0;
                if ((local_510.n2.vt != 9) ||
                   ((_union_1719)local_4e0.Lo64 != local_510.decVal.u2.Lo64)) {
                  HVar8 = VariantClear((VARIANTARG *)&local_510.n2);
                  if (HVar8 < 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_180001a90(HVar8);
                  }
                  local_510.n2.vt = 9;
                  local_510.decVal.u2.Lo64 = _Var4;
                  if ((BSTR)_Var4.Lo64 != (BSTR)0x0) {
                    (**(code **)(*(longlong *)_Var4 + 8))(_Var4.Lo64);
                  }
                }
              }
              else if (uVar1 == 0x80000002) {
                local_538 = &local_518;
                local_498.s2.Lo32 = local_4b8._0_4_;
                local_498.s2.Mid32 = local_4b8.decVal.Hi32;
                uStack_490 = local_4b8._8_4_;
                UStack_48c = local_4b8._12_4_;
                local_488 = local_4b8._16_8_;
                iVar7 = (**(code **)(*local_4f8 + 0x80))(local_4f8,param_3,iVar14,&local_498);
                if (iVar7 == 0) {
                  HVar8 = VariantClear((VARIANTARG *)&local_510.n2);
                  if (HVar8 < 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_180001a90(HVar8);
                  }
                  local_510.n2.vt = 8;
                  if ((BSTR)local_518.Lo64 == (BSTR)0x0) {
                    local_510.decVal.u2.Lo64 = local_518;
                  }
                  else {
                    UVar5 = SysStringByteLen((BSTR)local_518);
                    local_510.decVal.u2 =
                         (_union_1719)SysAllocStringByteLen((LPCSTR)local_518,UVar5);
                    if (local_510.decVal.u2.Lo64 != (_union_1719)0x0) goto LAB_18004f017;
                  }
                  if ((BSTR)local_518.Lo64 != (BSTR)0x0) {
                    local_510._8_4_ = 0x8007000e;
                    local_510.n2.vt = 10;
                    /* WARNING: Subroutine does not return */
                    FUN_180001a90(-0x7ff8fff2);
                  }
                }
              }
              else if (uVar1 != 0xffffffff) {
                local_530 = &local_510;
                local_538 = &local_498;
                local_498.s2.Lo32 = local_4b8._0_4_;
                local_498.s2.Mid32 = local_4b8.decVal.Hi32;
                uStack_490 = local_4b8._8_4_;
                UStack_48c = local_4b8._12_4_;
                local_488 = local_4b8._16_8_;
                (**(code **)(*local_4f8 + 0xa0))(local_4f8,param_3,iVar14,(short)uVar1);
              }
LAB_18004f017:
              HVar8 = SafeArrayPutElement(*(SAFEARRAY **)(local_478 + 4),&local_520,&local_510);
              if (HVar8 < 0) {
                FUN_180002a20(local_438,"Assert failed in file %s line %d",
                              "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnodesel.cpp",0x13c);
                LogMessage(local_438,2,1);
              }
              if ((BSTR)local_4e0.Lo64 != (BSTR)0x0) {
                (**(code **)(*(longlong *)local_4e0 + 0x10))();
              }
              SysFreeString((BSTR)local_518);
              VariantClear((VARIANTARG *)&local_510.n2);
              local_520 = local_520 + 1;
              iVar14 = iVar14 + 1;
            } while (iVar14 < (int)local_528[0]);
          }
        }
      }
      else {
        local_470._0_8_ = 0;
        local_470.decVal.u2.Lo64 = (_union_1719)0x0;
        local_470._16_8_ = 0;
        VariantInit((VARIANTARG *)&local_470.n2);
        local_4d0.lLbound = 1;
        local_4d0.cElements = local_528[0];
        local_4c4 = 1;
        local_4c8 = (undefined4)uVar11;
        local_520 = 1;
        *param_5 = 0x200c;
        pSVar9 = SafeArrayCreate(0xc,2,&local_4d0);
        *(SAFEARRAY **)(param_5 + 4) = pSVar9;
        local_51c = 1;
        UVar6 = local_528[0];
        if (puVar12 != puVar15) {
          do {
            uVar1 = *puVar12;
            iVar14 = 0;
            local_520 = 1;
            if (0 < (int)UVar6) {
              do {
                local_510._0_8_ = 0;
                local_510.decVal.u2.Lo64 = (_union_1719)0x0;
                local_510._16_8_ = 0;
                VariantInit((VARIANTARG *)&local_510.n2);
                local_518.Lo64 = 0;
                local_4e0.Lo64 = 0;
                if (uVar1 == 0x80000001) {
                  local_538 = &local_4e0;
                  (**(code **)(*local_4f8 + 0x90))(local_4f8,param_3,iVar14,&local_470);
                  _Var4 = local_4e0;
                  if ((local_510.n2.vt != 9) ||
                     ((_union_1719)local_4e0.Lo64 != local_510.decVal.u2.Lo64)) {
                    HVar8 = VariantClear((VARIANTARG *)&local_510.n2);
                    if (HVar8 < 0) {
                    /* WARNING: Subroutine does not return */
                      FUN_180001a90(HVar8);
                    }
                    local_510.decVal.u2.Lo64 = _Var4;
                    local_510.n2.vt = 9;
                    if ((BSTR)_Var4.Lo64 != (BSTR)0x0) {
                      (**(code **)(*(longlong *)_Var4 + 8))(_Var4.Lo64);
                    }
                  }
                }
                else if (uVar1 == 0x80000002) {
                  local_538 = &local_518;
                  local_498.s2.Lo32 = local_470._0_4_;
                  local_498.s2.Mid32 = local_470.decVal.Hi32;
                  uStack_490 = local_470._8_4_;
                  UStack_48c = local_470._12_4_;
                  local_488 = local_470._16_8_;
                  iVar7 = (**(code **)(*local_4f8 + 0x80))(local_4f8,param_3,iVar14,&local_498);
                  if (iVar7 == 0) {
                    HVar8 = VariantClear((VARIANTARG *)&local_510.n2);
                    if (HVar8 < 0) {
                    /* WARNING: Subroutine does not return */
                      FUN_180001a90(HVar8);
                    }
                    local_510.n2.vt = 8;
                    if ((BSTR)local_518.Lo64 == (BSTR)0x0) {
                      local_510.decVal.u2.Lo64 = local_518;
                    }
                    else {
                      UVar5 = SysStringByteLen((BSTR)local_518);
                      local_510.decVal.u2 =
                           (_union_1719)SysAllocStringByteLen((LPCSTR)local_518,UVar5);
                      if (local_510.decVal.u2.Lo64 != (_union_1719)0x0) goto LAB_18004ed0e;
                    }
                    if ((BSTR)local_518.Lo64 != (BSTR)0x0) {
                      local_510._8_4_ = 0x8007000e;
                      local_510.n2.vt = 10;
                    /* WARNING: Subroutine does not return */
                      FUN_180001a90(-0x7ff8fff2);
                    }
                  }
                }
                else if (uVar1 != 0xffffffff) {
                  local_530 = &local_510;
                  local_538 = &local_498;
                  local_498.s2.Lo32 = local_470._0_4_;
                  local_498.s2.Mid32 = local_470.decVal.Hi32;
                  uStack_490 = local_470._8_4_;
                  UStack_48c = local_470._12_4_;
                  local_488 = local_470._16_8_;
                  (**(code **)(*local_4f8 + 0xa0))(local_4f8,param_3,iVar14,uVar1 & 0xffff);
                }
LAB_18004ed0e:
                HVar8 = SafeArrayPutElement(*(SAFEARRAY **)(local_478 + 4),&local_520,&local_510);
                if (HVar8 < 0) {
                  FUN_180002a20(local_438,"Assert failed in file %s line %d",
                                "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnodesel.cpp",0x11a);
                  LogMessage(local_438,2,1);
                }
                if ((BSTR)local_4e0.Lo64 != (BSTR)0x0) {
                  (**(code **)(*(longlong *)local_4e0 + 0x10))();
                }
                SysFreeString((BSTR)local_518);
                VariantClear((VARIANTARG *)&local_510.n2);
                local_520 = local_520 + 1;
                iVar14 = iVar14 + 1;
                puVar15 = puStack_450;
                UVar6 = local_528[0];
              } while (iVar14 < (int)local_528[0]);
            }
            local_51c = local_51c + 1;
            puVar12 = puVar12 + 1;
          } while (puVar12 != puVar15);
        }
        VariantClear((VARIANTARG *)&local_470.n2);
      }
      VariantClear((VARIANTARG *)&local_4b8.n2);
      puVar12 = local_458;
    }
    uVar13 = 0;
    if (local_4f8 != (longlong *)0x0) {
      (**(code **)(*local_4f8 + 0x10))();
    }
    if (local_4f0 != (longlong *)0x0) {
      (**(code **)(*local_4f0 + 0x10))();
    }
  }
LAB_18004ede9:
  if (local_4e8 != (longlong *)0x0) {
    (**(code **)(*local_4e8 + 0x10))(local_4e8);
  }
  if (puVar12 != (uint *)0x0) {
    puVar15 = puVar12;
    if ((0xfff < (local_448 - (longlong)puVar12 & 0xfffffffffffffffcU)) &&
       (puVar15 = *(uint **)(puVar12 + -2),
       0x1f < (ulonglong)((longlong)puVar12 + (-8 - (longlong)puVar15)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180025ad0(puVar15);
  }
  return uVar13;
}

/* ---- FUNC 0004F150 FUN_18004f150 (674 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18004f150(longlong param_1,wchar_t *param_2,short *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  bool bVar6;
  HRESULT HVar7;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  undefined7 extraout_var;
  SAFEARRAY *pSVar8;
  undefined8 uVar9;
  undefined1 auStack_478 [32];
  LONG local_458 [2];
  longlong *local_450;
  SAFEARRAYBOUND local_448;
  longlong *local_440;
  longlong **local_438;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_430 [8];
  longlong *local_428;
  undefined8 local_420;
  undefined1 local_418 [1008];
  ulonglong local_28;
  
  local_28 = DAT_180077818 ^ (ulonglong)auStack_478;
  if ((*param_3 != 0) && (*param_3 != 10)) {
    FUN_180002a20(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnodesel.cpp",0x52);
    LogMessage(local_418,2,1);
  }
  plVar1 = *(longlong **)(param_1 + 0x10);
  uVar9 = 0x80004005;
  local_450 = (longlong *)0x0;
  if (plVar1 == (longlong *)0x0) {
    (**(code **)(*DAT_1800797f0 + 0x90))(DAT_1800797f0,&local_450);
    plVar1 = local_450;
  }
  else {
    (**(code **)(*plVar1 + 8))(plVar1);
    if (local_450 != (longlong *)0x0) {
      lVar2 = *local_450;
      local_450 = plVar1;
      (**(code **)(lVar2 + 0x10))();
      plVar1 = local_450;
    }
  }
  local_450 = plVar1;
  if (local_450 != (longlong *)0x0) {
    local_420 = 0;
    local_428 = operator_new(0x18);
    plVar1 = local_450;
    *local_428 = (longlong)local_428;
    local_428[1] = (longlong)local_428;
    this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
           CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                     ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_448,
                      param_2);
    local_440 = plVar1;
    if (plVar1 != (longlong *)0x0) {
      (**(code **)(*plVar1 + 8))(plVar1);
    }
    local_438 = &local_428;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              (local_430,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)this);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this);
    bVar6 = FUN_18004d9e0((longlong *)&local_440);
    if (((int)CONCAT71(extraout_var,bVar6) != 0) && (local_438[1] != (longlong *)0x0)) {
      local_448.cElements = (ULONG)local_438[1];
      local_448.lLbound = 1;
      *param_3 = 0x2009;
      pSVar8 = SafeArrayCreate(9,1,&local_448);
      *(SAFEARRAY **)(param_3 + 4) = pSVar8;
      local_458[0] = 1;
      plVar1 = *local_438;
      for (plVar3 = (longlong *)*plVar1; plVar3 != plVar1; plVar3 = (longlong *)*plVar3) {
        HVar7 = SafeArrayPutElement(*(SAFEARRAY **)(param_3 + 4),local_458,(void *)plVar3[2]);
        if (HVar7 != 0) {
          FUN_180002a20(local_418,"Assert failed in file %s line %d",
                        "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnodesel.cpp",0x70);
          LogMessage(local_418,2,1);
        }
        local_458[0] = local_458[0] + 1;
      }
      uVar9 = 0;
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_430);
    if (local_440 != (longlong *)0x0) {
      (**(code **)(*local_440 + 0x10))();
    }
    *(undefined8 *)local_428[1] = 0;
    puVar5 = (undefined8 *)*local_428;
    while (puVar5 != (undefined8 *)0x0) {
      puVar4 = (undefined8 *)*puVar5;
      if ((longlong *)puVar5[2] != (longlong *)0x0) {
        (**(code **)(*(longlong *)puVar5[2] + 0x10))();
      }
      FUN_180025ad0(puVar5);
      puVar5 = puVar4;
    }
    FUN_180025ad0(local_428);
    if (local_450 != (longlong *)0x0) {
      (**(code **)(*local_450 + 0x10))(local_450);
    }
  }
  return uVar9;
}

/* ---- FUNC 0004F400 FUN_18004f400 (972 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_18004f400(longlong param_1,undefined8 param_2,undefined8 *param_3,undefined2 *param_4)

{
  uint uVar1;
  longlong *plVar2;
  longlong lVar3;
  _union_1719 _Var4;
  uint *puVar5;
  uint *puVar6;
  int iVar7;
  UINT len;
  HRESULT HVar8;
  SAFEARRAY *pSVar9;
  uint *puVar10;
  undefined8 uVar11;
  undefined1 auStack_508 [32];
  longlong *local_4e8;
  BSTR local_4e0;
  _union_1719 local_4d8;
  _union_2707 local_4d0;
  LONG local_4b8;
  undefined4 local_4b4;
  _union_2707 local_4a8;
  uint *local_488;
  uint *puStack_480;
  longlong local_478;
  undefined4 local_468;
  ULONG UStack_464;
  undefined4 uStack_460;
  ULONG UStack_45c;
  undefined8 local_458;
  SAFEARRAYBOUND local_448 [2];
  undefined1 local_438 [1008];
  ulonglong local_48;
  
  local_48 = DAT_180077818 ^ (ulonglong)auStack_508;
  local_4a8._16_8_ = param_3[2];
  local_488 = (uint *)0x0;
  puStack_480 = (uint *)0x0;
  local_4a8._0_8_ = *param_3;
  local_4a8.decVal.u2 = *(_union_1719 *)(param_3 + 1);
  local_478 = 0;
  FUN_18004d530((longlong *)&local_488,(ushort *)&local_4a8);
  plVar2 = *(longlong **)(param_1 + 0x10);
  local_4e8 = (longlong *)0x0;
  if (plVar2 == (longlong *)0x0) {
    (**(code **)(*DAT_1800797f0 + 0x90))(DAT_1800797f0,&local_4e8);
    plVar2 = local_4e8;
  }
  else {
    (**(code **)(*plVar2 + 8))(plVar2);
    if (local_4e8 != (longlong *)0x0) {
      lVar3 = *local_4e8;
      local_4e8 = plVar2;
      (**(code **)(lVar3 + 0x10))();
      plVar2 = local_4e8;
    }
  }
  local_4e8 = plVar2;
  local_4d8.Lo64 = 0;
  iVar7 = (**(code **)(*local_4e8 + 0x110))(local_4e8,param_2,&local_4d8);
  puVar5 = local_488;
  uVar11 = 0x80004005;
  if (iVar7 == 0) {
    local_4a8._0_8_ = 0;
    local_4a8.decVal.u2.Lo64 = (_union_1719)0x0;
    local_4a8._16_8_ = 0;
    VariantInit((VARIANTARG *)&local_4a8.n2);
    puVar6 = puStack_480;
    local_448[0].lLbound = 1;
    local_4b4 = 0;
    *param_4 = 0x200c;
    local_448[0].cElements = (ULONG)((longlong)puStack_480 - (longlong)puVar5 >> 2);
    pSVar9 = SafeArrayCreate(0xc,1,local_448);
    local_4b8 = 1;
    *(SAFEARRAY **)(param_4 + 4) = pSVar9;
    for (puVar10 = puVar5; puVar10 != puVar6; puVar10 = puVar10 + 1) {
      uVar1 = *puVar10;
      local_4d0._0_8_ = 0;
      local_4d0.decVal.u2.Lo64 = (_union_1719)0x0;
      local_4d0._16_8_ = 0;
      VariantInit((VARIANTARG *)&local_4d0.n2);
      _Var4 = local_4d8;
      local_4e0 = (BSTR)0x0;
      if (uVar1 == 0x80000001) {
        if ((local_4d0.n2.vt != 9) || ((_union_1719)local_4d8.Lo64 != local_4d0.decVal.u2.Lo64)) {
          HVar8 = VariantClear((VARIANTARG *)&local_4d0.n2);
          if (HVar8 < 0) {
                    /* WARNING: Subroutine does not return */
            FUN_180001a90(HVar8);
          }
          local_4d0.decVal.u2.Lo64 = _Var4;
          local_4d0.n2.vt = 9;
          if ((BSTR)_Var4.Lo64 != (BSTR)0x0) {
            (**(code **)(*(longlong *)_Var4 + 8))(_Var4.Lo64);
          }
        }
      }
      else if (uVar1 == 0x80000002) {
        local_468 = local_4a8._0_4_;
        UStack_464 = local_4a8.decVal.Hi32;
        uStack_460 = local_4a8._8_4_;
        UStack_45c = local_4a8._12_4_;
        local_458 = local_4a8._16_8_;
        iVar7 = (**(code **)(*(longlong *)local_4d8 + 0x48))(local_4d8.Lo64,&local_468,&local_4e0);
        if (iVar7 == 0) {
          HVar8 = VariantClear((VARIANTARG *)&local_4d0.n2);
          if (HVar8 < 0) {
                    /* WARNING: Subroutine does not return */
            FUN_180001a90(HVar8);
          }
          local_4d0.n2.vt = 8;
          if (local_4e0 == (BSTR)0x0) {
            local_4d0.decVal.u2.Lo64 = (_union_1719)0x0;
          }
          else {
            len = SysStringByteLen(local_4e0);
            local_4d0.decVal.u2 = (_union_1719)SysAllocStringByteLen((LPCSTR)local_4e0,len);
            if (local_4d0.decVal.u2.Lo64 != (_union_1719)0x0) goto LAB_18004f692;
          }
          if (local_4e0 != (BSTR)0x0) {
            local_4d0._8_4_ = 0x8007000e;
            local_4d0.n2.vt = 10;
                    /* WARNING: Subroutine does not return */
            FUN_180001a90(-0x7ff8fff2);
          }
        }
      }
      else if (uVar1 != 0xffffffff) {
        local_468 = local_4a8._0_4_;
        UStack_464 = local_4a8.decVal.Hi32;
        uStack_460 = local_4a8._8_4_;
        UStack_45c = local_4a8._12_4_;
        local_458 = local_4a8._16_8_;
        (**(code **)(*(longlong *)local_4d8 + 0x98))
                  (local_4d8.Lo64,uVar1 & 0xffff,&local_468,&local_4d0);
      }
LAB_18004f692:
      HVar8 = SafeArrayPutElement(*(SAFEARRAY **)(param_4 + 4),&local_4b8,&local_4d0);
      if (HVar8 < 0) {
        FUN_180002a20(local_438,"Assert failed in file %s line %d",
                      "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnodesel.cpp",0x177);
        LogMessage(local_438,2,1);
      }
      SysFreeString(local_4e0);
      VariantClear((VARIANTARG *)&local_4d0.n2);
      local_4b8 = local_4b8 + 1;
    }
    VariantClear((VARIANTARG *)&local_4a8.n2);
    uVar11 = 0;
  }
  if ((BSTR)local_4d8.Lo64 != (BSTR)0x0) {
    (**(code **)(*(longlong *)local_4d8 + 0x10))();
  }
  if (local_4e8 != (longlong *)0x0) {
    (**(code **)(*local_4e8 + 0x10))();
  }
  if (puVar5 != (uint *)0x0) {
    puVar10 = puVar5;
    if ((0xfff < (local_478 - (longlong)puVar5 & 0xfffffffffffffffcU)) &&
       (puVar10 = *(uint **)(puVar5 + -2),
       0x1f < (ulonglong)((longlong)puVar5 + (-8 - (longlong)puVar10)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180025ad0(puVar10);
  }
  return uVar11;
}

/* ---- FUNC 0004F7D0 FUN_18004f7d0 (790 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18004f7d0(longlong param_1,wchar_t *param_2,short *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  bool bVar5;
  HRESULT HVar6;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  undefined7 extraout_var;
  SAFEARRAY *pSVar7;
  undefined8 uVar8;
  undefined1 auStack_4c8 [32];
  LONG local_4a8 [2];
  longlong *local_4a0;
  SAFEARRAYBOUND local_498;
  longlong *local_490;
  undefined8 **local_488;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_480 [8];
  undefined8 *local_478;
  undefined8 local_470;
  _union_2707 local_468;
  _union_2707 local_450;
  undefined4 local_438;
  ULONG UStack_434;
  undefined4 uStack_430;
  ULONG UStack_42c;
  undefined8 local_428;
  undefined1 local_418 [1008];
  ulonglong local_28;
  
  local_28 = DAT_180077818 ^ (ulonglong)auStack_4c8;
  if ((*param_3 != 0) && (*param_3 != 10)) {
    FUN_180002a20(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnodesel.cpp",0x7d);
    LogMessage(local_418,2,1);
  }
  plVar1 = *(longlong **)(param_1 + 0x10);
  uVar8 = 0x80004005;
  local_4a0 = (longlong *)0x0;
  if (plVar1 == (longlong *)0x0) {
    (**(code **)(*DAT_1800797f0 + 0x90))(DAT_1800797f0,&local_4a0);
    plVar1 = local_4a0;
  }
  else {
    (**(code **)(*plVar1 + 8))(plVar1);
    if (local_4a0 != (longlong *)0x0) {
      lVar2 = *local_4a0;
      local_4a0 = plVar1;
      (**(code **)(lVar2 + 0x10))();
      plVar1 = local_4a0;
    }
  }
  local_4a0 = plVar1;
  if (local_4a0 != (longlong *)0x0) {
    local_470 = 0;
    local_478 = operator_new(0x18);
    plVar1 = local_4a0;
    *local_478 = local_478;
    local_478[1] = local_478;
    this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
           CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                     ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_498,
                      param_2);
    local_490 = plVar1;
    if (plVar1 != (longlong *)0x0) {
      (**(code **)(*plVar1 + 8))(plVar1);
    }
    local_488 = &local_478;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              (local_480,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)this);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this);
    bVar5 = FUN_18004d9e0((longlong *)&local_490);
    if (((int)CONCAT71(extraout_var,bVar5) != 0) && (local_488[1] != (undefined8 *)0x0)) {
      local_450._0_8_ = 0;
      local_450.decVal.u2.Lo64 = (_union_1719)0x0;
      local_450._16_8_ = 0;
      VariantInit((VARIANTARG *)&local_450.n2);
      local_498.lLbound = 1;
      local_498.cElements = *(ULONG *)(local_488 + 1);
      *param_3 = 0x200c;
      pSVar7 = SafeArrayCreate(0xc,1,&local_498);
      *(SAFEARRAY **)(param_3 + 4) = pSVar7;
      local_4a8[0] = 1;
      puVar3 = *local_488;
      for (puVar4 = (undefined8 *)*puVar3; puVar4 != puVar3; puVar4 = (undefined8 *)*puVar4) {
        local_468._0_8_ = 0;
        local_468.decVal.u2.Lo64 = (_union_1719)0x0;
        local_468._16_8_ = 0;
        VariantInit((VARIANTARG *)&local_468.n2);
        local_438 = local_450._0_4_;
        UStack_434 = local_450.decVal.Hi32;
        uStack_430 = local_450._8_4_;
        UStack_42c = local_450._12_4_;
        local_428 = local_450._16_8_;
        (**(code **)(*(longlong *)puVar4[2] + 0x68))((longlong *)puVar4[2],&local_438,&local_468);
        HVar6 = SafeArrayPutElement(*(SAFEARRAY **)(param_3 + 4),local_4a8,&local_468);
        if (HVar6 != 0) {
          FUN_180002a20(local_418,"Assert failed in file %s line %d",
                        "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hnodesel.cpp",0x9d);
          LogMessage(local_418,2,1);
        }
        VariantClear((VARIANTARG *)&local_468.n2);
        local_4a8[0] = local_4a8[0] + 1;
      }
      uVar8 = 0;
      VariantClear((VARIANTARG *)&local_450.n2);
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_480);
    if (local_490 != (longlong *)0x0) {
      (**(code **)(*local_490 + 0x10))();
    }
    *(undefined8 *)local_478[1] = 0;
    puVar3 = (undefined8 *)*local_478;
    while (puVar3 != (undefined8 *)0x0) {
      puVar4 = (undefined8 *)*puVar3;
      if ((longlong *)puVar3[2] != (longlong *)0x0) {
        (**(code **)(*(longlong *)puVar3[2] + 0x10))();
      }
      FUN_180025ad0(puVar3);
      puVar3 = puVar4;
    }
    FUN_180025ad0(local_478);
    if (local_4a0 != (longlong *)0x0) {
      (**(code **)(*local_4a0 + 0x10))(local_4a0);
    }
  }
  return uVar8;
}

/* ---- FUNC 0004FAF0 FUN_18004faf0 (68 bytes) ---- */

undefined8 FUN_18004faf0(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  
  if (*(longlong **)(param_1 + 0x20) != param_2) {
    if (param_2 != (longlong *)0x0) {
      (**(code **)(*param_2 + 8))(param_2);
    }
    plVar1 = *(longlong **)(param_1 + 0x20);
    *(longlong **)(param_1 + 0x20) = param_2;
    if (plVar1 != (longlong *)0x0) {
      (**(code **)(*plVar1 + 0x10))();
    }
  }
  return 0;
}

/* ---- FUNC 0004FB40 FUN_18004fb40 (287 bytes) ---- */

ulonglong FUN_18004fb40(ushort *param_1)

{
  ushort uVar1;
  ulonglong uVar2;
  
  uVar1 = *param_1;
  uVar2 = 0xffffffff;
  if (uVar1 < 0x4003) {
    if (uVar1 == 0x4002) {
      return (ulonglong)(uint)(int)**(short **)(param_1 + 4);
    }
    switch(uVar1) {
    case 0:
    case 10:
      return 0;
    case 2:
      return (ulonglong)(uint)(int)(short)param_1[4];
    case 3:
    case 0x13:
      return (ulonglong)*(uint *)(param_1 + 4);
    case 8:
      uVar2 = FUN_18004cec0(*(LPCWSTR *)(param_1 + 4));
      return uVar2;
    case 0xb:
      return (ulonglong)(param_1[4] != 0);
    case 0x10:
      return (ulonglong)(uint)(int)(char)param_1[4];
    case 0x11:
      return (ulonglong)(byte)param_1[4];
    case 0x12:
      return (ulonglong)param_1[4];
    }
  }
  else {
    switch(uVar1) {
    case 0x4003:
    case 0x4013:
      return (ulonglong)**(uint **)(param_1 + 4);
    case 0x4008:
      uVar2 = FUN_18004cec0((LPCWSTR)**(undefined8 **)(param_1 + 4));
      uVar2 = uVar2 & 0xffffffff;
      break;
    case 0x400b:
      return (ulonglong)(**(short **)(param_1 + 4) != 0);
    case 0x4010:
      return (ulonglong)(uint)(int)**(char **)(param_1 + 4);
    case 0x4011:
      return (ulonglong)**(byte **)(param_1 + 4);
    case 0x4012:
      return (ulonglong)**(ushort **)(param_1 + 4);
    }
  }
  return uVar2;
}

/* ---- FUNC 0004FD00 FID_conflict:_Change_array (135 bytes) ---- */

/* Library Function - Multiple Matches With Different Base Names
    private: void __cdecl std::vector<struct CHN * __ptr64,class std::allocator<struct CHN *
   __ptr64> >::_Change_array(struct CHN * __ptr64 * __ptr64 const,unsigned __int64,unsigned __int64)
   __ptr64
    private: void __cdecl std::vector<unsigned __int64,struct std::_Parallelism_allocator<unsigned
   __int64> >::_Change_array(unsigned __int64 * __ptr64 const,unsigned __int64,unsigned __int64)
   __ptr64
    private: void __cdecl std::vector<unsigned __int64,class std::allocator<unsigned __int64>
   >::_Change_array(unsigned __int64 * __ptr64 const,unsigned __int64,unsigned __int64) __ptr64
   
   Library: Visual Studio 2019 Release */

void FID_conflict__Change_array
               (longlong *param_1,longlong param_2,longlong param_3,longlong param_4)

{
  void *pvVar1;
  void *pvVar2;
  
  pvVar1 = (void *)*param_1;
  if (pvVar1 != (void *)0x0) {
    pvVar2 = pvVar1;
    if ((0xfff < (param_1[2] - (longlong)pvVar1 & 0xfffffffffffffffcU)) &&
       (pvVar2 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180025ad0(pvVar2);
  }
  *param_1 = param_2;
  param_1[1] = param_2 + param_3 * 4;
  param_1[2] = param_2 + param_4 * 4;
  return;
}

/* ---- FUNC 0004FD90 FUN_18004fd90 (16 bytes) ---- */

void FUN_18004fd90(void)

{
                    /* WARNING: Subroutine does not return */
  std::_Xlength_error("vector too long");
}

/* ---- FUNC 0004FDB0 deallocate (66 bytes) ---- */

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
  FUN_180025ad0(pvVar1);
  return;
}

/* ---- FUNC 0004FE00 FUN_18004fe00 (44 bytes) ---- */

void FUN_18004fe00(CArchive *param_1,void *param_2,ulonglong param_3)

{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  if ((param_3 != 0) && (param_2 == (void *)0x0)) {
                    /* WARNING: Subroutine does not return */
    AfxThrowInvalidArgException();
  }
  if ((~*(uint *)(param_1 + 0x20) & 1) == 0) {
    for (; param_3 != 0; param_3 = param_3 - uVar4) {
      uVar4 = 0x1fffffff;
      if (param_3 < 0x1fffffff) {
        uVar4 = param_3 & 0xffffffff;
      }
      uVar3 = (int)uVar4 * 4;
      uVar2 = CArchive::Read(param_1,param_2,uVar3);
      if (uVar2 != uVar3) {
        AfxThrowArchiveException(3,(char *)0x0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      param_2 = (void *)((longlong)param_2 + uVar4 * 4);
    }
  }
  else {
    for (; param_3 != 0; param_3 = param_3 - uVar4) {
      uVar4 = 0x1fffffff;
      if (param_3 < 0x1fffffff) {
        uVar4 = param_3 & 0xffffffff;
      }
      CArchive::Write(param_1,param_2,(int)uVar4 * 4);
      param_2 = (void *)((longlong)param_2 + uVar4 * 4);
    }
  }
  return;
}

/* ---- FUNC 0004FE2C FUN_18004fe2c (68 bytes) ---- */

void FUN_18004fe2c(void)

{
  code *pcVar1;
  uint uVar2;
  ulonglong in_RAX;
  ulonglong unaff_RBX;
  void *unaff_RSI;
  uint uVar3;
  ulonglong uVar4;
  CArchive *unaff_R14;
  
  if ((in_RAX & 1) == 0) {
    for (; unaff_RBX != 0; unaff_RBX = unaff_RBX - uVar4) {
      uVar4 = 0x1fffffff;
      if (unaff_RBX < 0x1fffffff) {
        uVar4 = unaff_RBX & 0xffffffff;
      }
      uVar3 = (int)uVar4 * 4;
      uVar2 = CArchive::Read(unaff_R14,unaff_RSI,uVar3);
      if (uVar2 != uVar3) {
        AfxThrowArchiveException(3,(char *)0x0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      unaff_RSI = (void *)((longlong)unaff_RSI + uVar4 * 4);
    }
  }
  else {
    for (; unaff_RBX != 0; unaff_RBX = unaff_RBX - uVar4) {
      uVar4 = 0x1fffffff;
      if (unaff_RBX < 0x1fffffff) {
        uVar4 = unaff_RBX & 0xffffffff;
      }
      CArchive::Write(unaff_R14,unaff_RSI,(int)uVar4 * 4);
      unaff_RSI = (void *)((longlong)unaff_RSI + uVar4 * 4);
    }
  }
  return;
}

/* ---- FUNC 0004FE70 FUN_18004fe70 (68 bytes) ---- */

void FUN_18004fe70(void)

{
  code *pcVar1;
  uint uVar2;
  ulonglong unaff_RBX;
  ulonglong uVar3;
  void *unaff_RSI;
  uint uVar4;
  CArchive *unaff_R14;
  
  while( true ) {
    uVar3 = 0x1fffffff;
    if (unaff_RBX < 0x1fffffff) {
      uVar3 = unaff_RBX & 0xffffffff;
    }
    uVar4 = (int)uVar3 * 4;
    uVar2 = CArchive::Read(unaff_R14,unaff_RSI,uVar4);
    if (uVar2 != uVar4) break;
    unaff_RSI = (void *)((longlong)unaff_RSI + uVar3 * 4);
    unaff_RBX = unaff_RBX - uVar3;
    if (unaff_RBX == 0) {
      return;
    }
  }
  AfxThrowArchiveException(3,(char *)0x0);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

/* ---- FUNC 0004FEB4 FUN_18004feb4 (22 bytes) ---- */

void FUN_18004feb4(void)

{
  return;
}

/* ---- FUNC 0004FECA FUN_18004feca (11 bytes) ---- */

void FUN_18004feca(void)

{
  code *pcVar1;
  
  AfxThrowArchiveException(3,(char *)0x0);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

/* ---- FUNC 0004FED5 AfxThrowInvalidArgException (5 bytes) ---- */

void __cdecl AfxThrowInvalidArgException(void)

{
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 0004FEE0 FUN_18004fee0 (32 bytes) ---- */

undefined8 * FUN_18004fee0(undefined8 *param_1)

{
  *param_1 = CArray<long,long>::vftable;
  param_1[1] = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  return param_1;
}

/* ---- FUNC 0004FF00 FUN_18004ff00 (239 bytes) ---- */

undefined8 * FUN_18004ff00(undefined8 *param_1)

{
  *param_1 = CHPlotVal::vftable;
  FUN_1800212f0(param_1 + 5,param_1,&DAT_180063450);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x12));
  CStringArray::CStringArray((CStringArray *)(param_1 + 0x13));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x18));
  CPtrArray::CPtrArray((CPtrArray *)(param_1 + 0x1a));
  *(undefined ***)(param_1 + 0x1a) = CTypedPtrArray<CPtrArray,CPlotVariable*___ptr64>::vftable;
  CPtrArray::CPtrArray((CPtrArray *)(param_1 + 0x1f));
  *(undefined ***)(param_1 + 0x1f) = CTypedPtrArray<CPtrArray,CPlotVariable*___ptr64>::vftable;
  CPtrArray::CPtrArray((CPtrArray *)(param_1 + 0x24));
  *(undefined ***)(param_1 + 0x24) = CTypedPtrArray<CPtrArray,CPlotText*___ptr64>::vftable;
  *(undefined4 *)(param_1 + 2) = 0;
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  FUN_180055380((longlong)param_1);
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  return param_1;
}

/* ---- FUNC 0004FFF0 FUN_18004fff0 (276 bytes) ---- */

undefined8 * FUN_18004fff0(undefined8 *param_1)

{
  *param_1 = CHWizardPlot::vftable;
  param_1[1] = CHWizardPlot::CImpPersistStream::vftable;
  FUN_1800212f0(param_1 + 5,param_1,&DAT_180063550);
  CMapWordToPtr::CMapWordToPtr((CMapWordToPtr *)(param_1 + 0x13),10);
  FUN_18004fee0(param_1 + 0x1a);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x1f));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x21));
  CDWordArray::CDWordArray((CDWordArray *)(param_1 + 0x22));
  CStringArray::CStringArray((CStringArray *)(param_1 + 0x27));
  CPtrArray::CPtrArray((CPtrArray *)(param_1 + 0x2c));
  *(undefined4 *)(param_1 + 4) = 0;
  param_1[3] = 0;
  *(undefined4 *)((longlong)param_1 + 0x8c) = 0;
  param_1[0x12] = 0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x1f),"");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x21),"");
  param_1[0x20] = 0;
  param_1[2] = param_1;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  return param_1;
}

/* ---- FUNC 00050110 FUN_180050110 (20 bytes) ---- */

undefined8 * FUN_180050110(undefined8 *param_1)

{
  *param_1 = CHWizardPlotCF::vftable;
  param_1[1] = 0;
  return param_1;
}

/* ---- FUNC 00050130 FUN_180050130 (81 bytes) ---- */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_180050130(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_1,"");
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined8 *)(param_1 + 0x30) = 0;
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(undefined8 *)(param_1 + 0x14) = 0xffffffffffffffff;
  return param_1;
}

/* ---- FUNC 00050190 FUN_180050190 (24 bytes) ---- */

void FUN_180050190(undefined8 *param_1)

{
  *param_1 = CArray<long,long>::vftable;
  if ((void *)param_1[1] == (void *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00018005bd4f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete__((void *)param_1[1]);
  return;
}

/* ---- FUNC 000501C0 FUN_1800501c0 (548 bytes) ---- */

void FUN_1800501c0(undefined8 *param_1)

{
  ulonglong uVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar2;
  void *pvVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  *param_1 = CHPlotVal::vftable;
  uVar4 = 0;
  uVar1 = param_1[0x1c];
  uVar5 = uVar4;
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar5 < 0) || ((longlong)param_1[0x1c] <= (longlong)uVar5)) goto LAB_1800503df;
      pCVar2 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                (param_1[0x1b] + uVar5 * 8);
      if (pCVar2 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        FUN_180050580(pCVar2);
        FUN_180025ad0(pCVar2);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
  }
  CPtrArray::SetSize((CPtrArray *)(param_1 + 0x1a),0,-1);
  uVar1 = param_1[0x21];
  uVar5 = uVar4;
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar5 < 0) || ((longlong)param_1[0x21] <= (longlong)uVar5)) goto LAB_1800503df;
      pCVar2 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                (param_1[0x20] + uVar5 * 8);
      if (pCVar2 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        FUN_180050580(pCVar2);
        FUN_180025ad0(pCVar2);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
  }
  CPtrArray::SetSize((CPtrArray *)(param_1 + 0x1f),0,-1);
  uVar1 = param_1[0x26];
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar4 < 0) || ((longlong)param_1[0x26] <= (longlong)uVar4)) {
LAB_1800503df:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      pvVar3 = *(void **)(param_1[0x25] + uVar4 * 8);
      if (pvVar3 != (void *)0x0) {
        SysFreeString(*(BSTR *)((longlong)pvVar3 + 0x10));
        SysFreeString(*(BSTR *)((longlong)pvVar3 + 0x20));
        FUN_180025ad0(pvVar3);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  CPtrArray::SetSize((CPtrArray *)(param_1 + 0x24),0,-1);
  if ((longlong *)param_1[4] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[4] + 0x10))();
  }
  if ((longlong *)param_1[3] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[3] + 0x10))();
  }
  if ((longlong *)param_1[1] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[1] + 0x10))();
  }
  if ((BSTR)param_1[0xb] != (BSTR)0x0) {
    SysFreeString((BSTR)param_1[0xb]);
  }
  if ((BSTR)param_1[10] != (BSTR)0x0) {
    SysFreeString((BSTR)param_1[10]);
  }
  if ((BSTR)param_1[0xc] != (BSTR)0x0) {
    SysFreeString((BSTR)param_1[0xc]);
  }
  CPtrArray::~CPtrArray((CPtrArray *)(param_1 + 0x24));
  CPtrArray::~CPtrArray((CPtrArray *)(param_1 + 0x1f));
  CPtrArray::~CPtrArray((CPtrArray *)(param_1 + 0x1a));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x18));
  CStringArray::~CStringArray((CStringArray *)(param_1 + 0x13));
                    /* WARNING: Could not recover jumptable at 0x0001800503d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x12));
  return;
}

/* ---- FUNC 000503F0 FUN_1800503f0 (312 bytes) ---- */

void FUN_1800503f0(undefined8 *param_1)

{
  __POSITION *p_Var1;
  ushort local_res8 [4];
  __POSITION *local_res10;
  longlong *local_res18 [2];
  
  *param_1 = CHWizardPlot::vftable;
  local_res10 = (__POSITION *)-(ulonglong)((__POSITION *)param_1[0x16] != (__POSITION *)0x0);
  p_Var1 = (__POSITION *)param_1[0x16];
  while (p_Var1 != (__POSITION *)0x0) {
    CMapWordToPtr::GetNextAssoc
              ((CMapWordToPtr *)(param_1 + 0x13),&local_res10,local_res8,local_res18);
    p_Var1 = local_res10;
    if (local_res18[0] != (longlong *)0x0) {
      (**(code **)(*local_res18[0] + 0x10))();
      p_Var1 = local_res10;
    }
  }
  CMapWordToPtr::RemoveAll((CMapWordToPtr *)(param_1 + 0x13));
  FUN_180053c90((CDWordArray *)(param_1 + 0x22));
  if ((longlong *)param_1[0x20] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x20] + 0x10))();
  }
  if ((longlong *)param_1[0x12] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x12] + 0x10))();
  }
  if ((longlong *)param_1[3] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[3] + 0x10))();
  }
  if ((BSTR)param_1[0xb] != (BSTR)0x0) {
    SysFreeString((BSTR)param_1[0xb]);
  }
  if ((BSTR)param_1[10] != (BSTR)0x0) {
    SysFreeString((BSTR)param_1[10]);
  }
  if ((BSTR)param_1[0xc] != (BSTR)0x0) {
    SysFreeString((BSTR)param_1[0xc]);
  }
  CPtrArray::~CPtrArray((CPtrArray *)(param_1 + 0x2c));
  CStringArray::~CStringArray((CStringArray *)(param_1 + 0x27));
  CDWordArray::~CDWordArray((CDWordArray *)(param_1 + 0x22));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x21));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x1f));
  FUN_180050190(param_1 + 0x1a);
  CMapWordToPtr::~CMapWordToPtr((CMapWordToPtr *)(param_1 + 0x13));
  return;
}

/* ---- FUNC 00050530 FUN_180050530 (25 bytes) ---- */

void FUN_180050530(undefined8 *param_1)

{
  *param_1 = CHWizardPlotCF::vftable;
  if (*(DWORD *)((longlong)param_1 + 0xc) != 0) {
                    /* WARNING: Could not recover jumptable at 0x000180050541. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    CoRevokeClassObject(*(DWORD *)((longlong)param_1 + 0xc));
    return;
  }
  return;
}

/* ---- FUNC 00050550 FUN_180050550 (40 bytes) ---- */

void FUN_180050550(CDWordArray *param_1)

{
  CPtrArray::~CPtrArray((CPtrArray *)(param_1 + 0x50));
  CStringArray::~CStringArray((CStringArray *)(param_1 + 0x28));
  CDWordArray::~CDWordArray(param_1);
  return;
}

/* ---- FUNC 00050580 FUN_180050580 (125 bytes) ---- */

void FUN_180050580(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x1c)) {
    do {
      VariantClear((VARIANTARG *)(*(longlong *)(param_1 + 0x28) + (longlong)iVar1 * 0x18));
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x1c));
  }
  if (*(void **)(param_1 + 0x28) != (void *)0x0) {
    free(*(void **)(param_1 + 0x28));
  }
  if (*(void **)(param_1 + 0x20) != (void *)0x0) {
    free(*(void **)(param_1 + 0x20));
  }
  if (*(longlong **)(param_1 + 0x38) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0x38) + 0x10))();
  }
                    /* WARNING: Could not recover jumptable at 0x0001800505f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1);
  return;
}

/* ---- FUNC 00050600 FUN_180050600 (78 bytes) ---- */

undefined8 * FUN_180050600(undefined8 *param_1,uint param_2)

{
  FUN_180050190(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    _guard_check_icall();
  }
  return param_1;
}

/* ---- FUNC 00050650 FUN_180050650 (78 bytes) ---- */

CPtrArray * FUN_180050650(CPtrArray *param_1,uint param_2)

{
  CPtrArray::~CPtrArray(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    _guard_check_icall();
  }
  return param_1;
}

/* ---- FUNC 000506A0 FUN_1800506a0 (152 bytes) ---- */

undefined8 FUN_1800506a0(longlong param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  BSTR pOVar2;
  
  puVar1 = operator_new(0x30);
  if (puVar1 == (undefined8 *)0x0) {
    puVar1 = (undefined8 *)0x0;
  }
  else {
    pOVar2 = SysAllocString((OLECHAR *)param_2[2]);
    puVar1[2] = pOVar2;
    *puVar1 = *param_2;
    puVar1[1] = param_2[1];
    *(undefined4 *)(puVar1 + 3) = *(undefined4 *)(param_2 + 3);
    *(undefined2 *)(puVar1 + 5) = *(undefined2 *)(param_2 + 5);
    pOVar2 = SysAllocString((OLECHAR *)param_2[4]);
    puVar1[4] = pOVar2;
    *(undefined2 *)((longlong)puVar1 + 0x2a) = *(undefined2 *)((longlong)param_2 + 0x2a);
    *(undefined2 *)((longlong)puVar1 + 0x2c) = *(undefined2 *)((longlong)param_2 + 0x2c);
  }
  CPtrArray::SetAtGrow((CPtrArray *)(param_1 + 0x120),*(__int64 *)(param_1 + 0x130),puVar1);
  return 0;
}

/* ---- FUNC 00050740 FUN_180050740 (171 bytes) ---- */

void FUN_180050740(longlong *param_1,longlong *param_2,wchar_t *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res8 [8];
  
  plVar1 = (longlong *)param_1[0x12];
  lVar2 = plVar1[0x21];
  (**(code **)(*plVar1 + 0xc0))(plVar1,(ulong)lVar2 + 1);
  pCVar3 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
           CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8,param_3);
  FUN_180054c20((CDWordArray *)(param_1 + 0x22),(ulong)lVar2,pCVar3,param_2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
  if ((-1 < lVar2) && (lVar2 < *(longlong *)(param_1[0x12] + 0x108))) {
    FUN_180056190(param_1,*(longlong *)(*(longlong *)(param_1[0x12] + 0x100) + lVar2 * 8),param_2,
                  param_3);
    return;
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 000507F0 FUN_1800507f0 (9 bytes) ---- */

void FUN_1800507f0(longlong param_1)

{
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  return;
}

/* ---- FUNC 00050800 FUN_180050800 (248 bytes) ---- */

int FUN_180050800(longlong *param_1,longlong *param_2,wchar_t *param_3,wchar_t *param_4)

{
  longlong lVar1;
  longlong *plVar2;
  ulonglong uVar3;
  int iVar4;
  
  plVar2 = (longlong *)param_1[0x12];
  uVar3 = plVar2[0x1c];
  (**(code **)(*plVar2 + 0xd0))(plVar2,(int)uVar3 + 1);
  lVar1 = uVar3 + 1;
  if ((-1 < lVar1) && (lVar1 < *(longlong *)(param_1[0x12] + 0xe0))) {
    iVar4 = FUN_180056190(param_1,*(longlong *)(*(longlong *)(param_1[0x12] + 0xd8) + lVar1 * 8),
                          param_2,param_3);
    plVar2 = (longlong *)param_1[0x12];
    if (iVar4 < 0) {
      (**(code **)(*plVar2 + 0xd0))(plVar2,uVar3 & 0xffffffff);
    }
    else {
      lVar1 = plVar2[0x21];
      (**(code **)(*plVar2 + 0xc0))(plVar2,(int)lVar1 + 1);
      if ((lVar1 < 0) || (*(longlong *)(param_1[0x12] + 0x108) <= lVar1)) goto LAB_1800508f3;
      iVar4 = FUN_180056190(param_1,*(longlong *)(*(longlong *)(param_1[0x12] + 0x100) + lVar1 * 8),
                            param_2,param_4);
    }
    return iVar4;
  }
LAB_1800508f3:
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00050900 FUN_180050900 (380 bytes) ---- */

undefined8 FUN_180050900(longlong param_1)

{
  ulonglong uVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar2;
  void *pvVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  uVar1 = *(ulonglong *)(param_1 + 0xe0);
  uVar5 = 0;
  uVar4 = uVar5;
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar4 < 0) || (*(longlong *)(param_1 + 0xe0) <= (longlong)uVar4))
      goto LAB_180050a77;
      pCVar2 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                (*(longlong *)(param_1 + 0xd8) + uVar4 * 8);
      if (pCVar2 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        FUN_180050580(pCVar2);
        FUN_180025ad0(pCVar2);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  CPtrArray::SetSize((CPtrArray *)(param_1 + 0xd0),0,-1);
  uVar1 = *(ulonglong *)(param_1 + 0x108);
  uVar4 = uVar5;
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar4 < 0) || (*(longlong *)(param_1 + 0x108) <= (longlong)uVar4))
      goto LAB_180050a77;
      pCVar2 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                (*(longlong *)(param_1 + 0x100) + uVar4 * 8);
      if (pCVar2 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        FUN_180050580(pCVar2);
        FUN_180025ad0(pCVar2);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  CPtrArray::SetSize((CPtrArray *)(param_1 + 0xf8),0,-1);
  uVar1 = *(ulonglong *)(param_1 + 0x130);
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar5 < 0) || (*(longlong *)(param_1 + 0x130) <= (longlong)uVar5)) {
LAB_180050a77:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      pvVar3 = *(void **)(*(longlong *)(param_1 + 0x128) + uVar5 * 8);
      if (pvVar3 != (void *)0x0) {
        SysFreeString(*(BSTR *)((longlong)pvVar3 + 0x10));
        SysFreeString(*(BSTR *)((longlong)pvVar3 + 0x20));
        FUN_180025ad0(pvVar3);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
  }
  CPtrArray::SetSize((CPtrArray *)(param_1 + 0x120),0,-1);
  FUN_180055380(param_1);
  return 0;
}

/* ---- FUNC 00050A80 FUN_180050a80 (220 bytes) ---- */

undefined8 FUN_180050a80(longlong param_1)

{
  __POSITION *p_Var1;
  ushort local_res8 [4];
  __POSITION *local_res10;
  longlong *local_res18;
  
  *(undefined4 *)(param_1 + 0x8c) = 0;
  local_res10 = (__POSITION *)-(ulonglong)(*(__POSITION **)(param_1 + 0xb0) != (__POSITION *)0x0);
  p_Var1 = *(__POSITION **)(param_1 + 0xb0);
  while (p_Var1 != (__POSITION *)0x0) {
    CMapWordToPtr::GetNextAssoc
              ((CMapWordToPtr *)(param_1 + 0x98),&local_res10,local_res8,&local_res18);
    p_Var1 = local_res10;
    if (local_res18 != (longlong *)0x0) {
      (**(code **)(*local_res18 + 0x10))();
      p_Var1 = local_res10;
    }
  }
  CMapWordToPtr::RemoveAll((CMapWordToPtr *)(param_1 + 0x98));
  FUN_180053c90((CDWordArray *)(param_1 + 0x110));
  FUN_180055fb0(param_1 + 0xd0,0,-1);
  (**(code **)(**(longlong **)(param_1 + 0x90) + 0x108))();
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x108),"");
  if (*(longlong **)(param_1 + 0x100) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0x100) + 0x10))();
    *(undefined8 *)(param_1 + 0x100) = 0;
  }
  return 0;
}

/* ---- FUNC 00050B60 FUN_180050b60 (178 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_180050b60(longlong param_1)

{
  undefined1 auStack_428 [32];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_180077818 ^ (ulonglong)auStack_428;
  if (*(longlong *)(param_1 + 0x10) != *(longlong *)(param_1 + 0x38)) {
    FUN_180002a20(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0xd98);
    LogMessage(local_408,2,1);
  }
  if (*(longlong *)(param_1 + 0x10) != *(longlong *)(param_1 + 0x60)) {
    FUN_180002a20(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0xd99);
    LogMessage(local_408,2,1);
  }
  return *(undefined4 *)(param_1 + 0x10);
}

/* ---- FUNC 00050C20 FUN_180050c20 (156 bytes) ---- */

HRESULT FUN_180050c20(undefined8 *param_1)

{
  HRESULT HVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  
  puVar2 = operator_new(0x188);
  if (puVar2 == (undefined8 *)0x0) {
    plVar3 = (longlong *)0x0;
  }
  else {
    plVar3 = FUN_18004ff00(puVar2);
  }
  HVar1 = FUN_180033ad0(plVar3 + 1,(GUID *)&DAT_180063450);
  if (HVar1 < 0) {
    if (plVar3 != (longlong *)0x0) {
      FUN_1800501c0(plVar3);
      FUN_180025ad0(plVar3);
    }
    *param_1 = 0;
    return HVar1;
  }
  (**(code **)(*plVar3 + 8))(plVar3);
  *param_1 = plVar3;
  return 0;
}

/* ---- FUNC 00050CC0 FUN_180050cc0 (159 bytes) ---- */

HRESULT FUN_180050cc0(undefined8 *param_1)

{
  HRESULT HVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  
  puVar3 = (undefined8 *)0x0;
  *param_1 = 0;
  puVar2 = operator_new(0x188);
  if (puVar2 != (undefined8 *)0x0) {
    puVar3 = FUN_18004fff0(puVar2);
  }
  HVar1 = FUN_180033ad0(puVar3 + 3,(GUID *)&DAT_180063550);
  if (-1 < HVar1) {
    HVar1 = FUN_180050c20(puVar3 + 0x12);
    if (-1 < HVar1) {
      *param_1 = puVar3;
      return 0;
    }
  }
  if (puVar3 != (undefined8 *)0x0) {
    FUN_1800503f0(puVar3);
    FUN_180025ad0(puVar3);
  }
  return HVar1;
}

/* ---- FUNC 00050D60 FUN_180050d60 (68 bytes) ---- */

undefined8 FUN_180050d60(undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 *param_4)

{
  HRESULT HVar1;
  int iVar2;
  undefined8 *local_res20;
  
  *param_4 = 0;
  if (DAT_1800797f0 != 0) {
    if (param_2 != 0) {
      return 0x80040110;
    }
    HVar1 = FUN_180050cc0(&local_res20);
    if (-1 < HVar1) {
      iVar2 = (**(code **)*local_res20)(local_res20,param_3,param_4);
      if (iVar2 < 0) {
        FUN_1800503f0(local_res20);
        FUN_180025ad0(local_res20);
        return 0x80004002;
      }
      return 0;
    }
  }
  return 0x80004005;
}

/* ---- FUNC 00050DA4 FUN_180050da4 (70 bytes) ---- */

undefined8 FUN_180050da4(void)

{
  int iVar1;
  undefined8 *in_stack_00000048;
  
  iVar1 = (**(code **)*in_stack_00000048)(in_stack_00000048);
  if (iVar1 < 0) {
    FUN_1800503f0(in_stack_00000048);
    FUN_180025ad0(in_stack_00000048);
    return 0x80004002;
  }
  return 0;
}

/* ---- FUNC 00050DEA FUN_180050dea (18 bytes) ---- */

undefined8 FUN_180050dea(void)

{
  return 0;
}

/* ---- FUNC 00050DFC FUN_180050dfc (16 bytes) ---- */

undefined8 FUN_180050dfc(void)

{
  return 0x80004005;
}

/* ---- FUNC 00050E10 FUN_180050e10 (55 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_180050e10(undefined8 param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  
  iVar3 = MVGetProductCode();
  uVar2 = _UNK_1800635b8;
  uVar1 = DAT_180063568;
  if (iVar3 == 2) {
    *param_2 = _DAT_1800635b0;
    param_2[1] = uVar2;
    return 0;
  }
  *param_2 = DAT_180063560;
  param_2[1] = uVar1;
  return 0;
}

/* ---- FUNC 00050E50 FUN_180050e50 (14 bytes) ---- */

void FUN_180050e50(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180050e57. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(longlong **)(param_1 + 8) + 0x140))();
  return;
}

/* ---- FUNC 00050E60 FUN_180050e60 (287 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180050e60(longlong param_1,int param_2,short *param_3,VARIANTARG *param_4)

{
  undefined1 auStack_448 [32];
  undefined1 local_428 [1008];
  ulonglong local_38;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStack_448;
  if (param_2 < 0) {
    FUN_180002a20(local_428,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",299);
    LogMessage(local_428,2,1);
  }
  if (*(int *)(param_1 + 0x1c) <= param_2) {
    FUN_180002a20(local_428,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",300);
    LogMessage(local_428,2,1);
  }
  if ((*(longlong *)(param_1 + 0x28) == 0) || (*(longlong *)(param_1 + 0x20) == 0)) {
    FUN_180002a20(local_428,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0x12d);
    LogMessage(local_428,2,1);
  }
  *param_3 = (short)((*(int *)(*(longlong *)(param_1 + 0x20) + (longlong)param_2 * 4) << 0x1c) >>
                    0x1c);
  VariantCopy(param_4,(VARIANTARG *)(*(longlong *)(param_1 + 0x28) + (longlong)param_2 * 0x18));
  return;
}

/* ---- FUNC 00050F80 FUN_180050f80 (91 bytes) ---- */

short FUN_180050f80(longlong param_1)

{
  int iVar1;
  short sVar2;
  longlong lVar3;
  int *piVar4;
  
  sVar2 = 0;
  if (0 < *(int *)(param_1 + 0x1c)) {
    piVar4 = *(int **)(param_1 + 0x20);
    lVar3 = 0;
    do {
      iVar1 = (*piVar4 << 0x19) >> 0x1d;
      if (iVar1 == 1) {
        if (sVar2 == 5) {
          return 5;
        }
        sVar2 = 3;
      }
      else {
        if (iVar1 == 2) {
          return 5;
        }
        if (sVar2 == 5) {
          return 5;
        }
      }
      lVar3 = lVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (lVar3 < *(int *)(param_1 + 0x1c));
  }
  return sVar2;
}

/* ---- FUNC 00050FE0 FUN_180050fe0 (324 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180050fe0(longlong param_1,int param_2,_union_1719 *param_3)

{
  longlong *plVar1;
  VARIANTARG *pVVar2;
  longlong *plVar3;
  int iVar4;
  longlong lVar5;
  longlong *plVar6;
  bool bVar7;
  ULONGLONG UVar8;
  undefined1 auStack_4a8 [32];
  undefined8 *local_488;
  longlong **local_480;
  longlong *local_478;
  int local_470 [2];
  longlong *local_468;
  longlong *local_460;
  LPVOID local_458;
  longlong *local_450;
  IBindCtx *local_448 [2];
  undefined1 local_438 [1008];
  ulonglong local_48;
  
  local_48 = DAT_180077818 ^ (ulonglong)auStack_4a8;
  lVar5 = (longlong)param_2;
  if (param_2 < 0) {
    FUN_180002a20(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0x1d2);
    LogMessage(local_438,2,1);
  }
  if (*(int *)(param_1 + 0x1c) <= param_2) {
    FUN_180002a20(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0x1d3);
    LogMessage(local_438,2,1);
  }
  plVar1 = (longlong *)(param_1 + 0x20);
  if ((*(longlong *)(param_1 + 0x28) == 0) || (*plVar1 == 0)) {
    FUN_180002a20(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0x1d4);
    LogMessage(local_438,2,1);
  }
  UVar8 = nan(&DAT_18006271e);
  param_3->Lo64 = UVar8;
  pVVar2 = (VARIANTARG *)(*(longlong *)(param_1 + 0x28) + lVar5 * 0x18);
  iVar4 = (*(int *)(*plVar1 + lVar5 * 4) << 0x1c) >> 0x1c;
  if (iVar4 == 0) {
    FUN_1800516d0(pVVar2,param_3);
    return;
  }
  if (iVar4 == 1) {
    if ((pVVar2->n1).n2.vt != 9) {
      return;
    }
    UVar8 = (pVVar2->n1).decVal.u2.Lo64;
    if (UVar8 == 0) {
      return;
    }
    FUN_180051830(UVar8,param_3,*(int *)(param_1 + 0x30),*(int *)(param_1 + 0x34));
    return;
  }
  if (iVar4 == 2) {
    if ((pVVar2->n1).n2.vt != 9) {
      return;
    }
    UVar8 = (pVVar2->n1).decVal.u2.Lo64;
    if (UVar8 == 0) {
      return;
    }
    FUN_1800517a0(UVar8,(double *)param_3);
    return;
  }
  if ((iVar4 != 4) && (iVar4 != 5)) {
    return;
  }
  bVar7 = false;
  if (*(longlong *)(param_1 + 0x38) == 0) {
    FUN_180002a20(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0x1f0);
    LogMessage(local_438,2,1);
  }
  plVar6 = *(longlong **)(param_1 + 0x38);
  (**(code **)(*plVar6 + 8))(plVar6);
  plVar3 = *(longlong **)((longlong)&pVVar2->n1 + 8);
  iVar4 = (**(code **)(*plVar3 + 0x60))(plVar3,1,&local_460);
  if (-1 < iVar4) {
    CreateBindCtx(0,local_448);
    iVar4 = (**(code **)(*local_460 + 0x18))(local_460,1,&local_478);
    while (iVar4 == 0) {
      local_470[0] = 0;
      iVar4 = (**(code **)(*local_478 + 0xb0))(local_478,local_470);
      if (iVar4 < 0) {
        bVar7 = true;
LAB_1800512e2:
        (**(code **)(*local_478 + 0x10))();
        break;
      }
      if (local_470[0] != 3) {
        bVar7 = true;
        if ((local_470[0] == 4) &&
           (iVar4 = (**(code **)*plVar6)(plVar6,&DAT_180066dd8,&local_450), -1 < iVar4)) {
          iVar4 = (**(code **)(*local_478 + 0xa0))(local_478,local_448[0],0,&local_458);
          if (-1 < iVar4) {
            local_480 = &local_468;
            local_488 = &DAT_180063400;
            iVar4 = (**(code **)(*local_450 + 0x30))(local_450,(longlong)local_458 + 2,1,0);
            bVar7 = iVar4 < 0;
            if (!bVar7) {
              (**(code **)(*plVar6 + 0x10))(plVar6);
              plVar6 = local_468;
            }
            CoTaskMemFree(local_458);
          }
          (**(code **)(*local_450 + 0x10))();
          if (!bVar7) goto LAB_1800512b1;
        }
        goto LAB_1800512e2;
      }
      local_468 = (longlong *)plVar6[0xc];
      (**(code **)(*local_468 + 8))();
      (**(code **)(*plVar6 + 0x10))(plVar6);
      plVar6 = local_468;
LAB_1800512b1:
      (**(code **)(*local_478 + 0x10))();
      iVar4 = (**(code **)(*local_460 + 0x18))(local_460,1,&local_478);
    }
    (*local_448[0]->lpVtbl->Release)(local_448[0]);
    (**(code **)(*local_460 + 0x10))();
    if (bVar7) goto LAB_180051331;
  }
  if (((byte)*(undefined4 *)(*plVar1 + lVar5 * 4) & 0xf) == 4) {
    FUN_180051830((longlong)plVar6,param_3,*(int *)(param_1 + 0x30),*(int *)(param_1 + 0x34));
  }
  else {
    FUN_1800517a0((longlong)plVar6,(double *)param_3);
  }
LAB_180051331:
  (**(code **)(*plVar6 + 0x10))(plVar6);
  return;
}

/* ---- FUNC 00051124 FUN_180051124 (544 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180051124(void)

{
  int iVar1;
  longlong *plVar2;
  longlong unaff_RSI;
  longlong *unaff_R12;
  longlong unaff_R13;
  longlong unaff_R14;
  _union_1719 *unaff_R15;
  bool bVar3;
  longlong *in_stack_00000030;
  int in_stack_00000038;
  longlong *in_stack_00000040;
  longlong *in_stack_00000048;
  LPVOID in_stack_00000050;
  longlong *in_stack_00000058;
  IBindCtx *in_stack_00000060;
  
  bVar3 = false;
  if (*(longlong *)(unaff_R14 + 0x38) == 0) {
    FUN_180002a20(&stack0x00000070,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0x1f0);
    LogMessage(&stack0x00000070,2,1);
  }
  plVar2 = *(longlong **)(unaff_R14 + 0x38);
  (**(code **)(*plVar2 + 8))(plVar2);
  iVar1 = (**(code **)(**(longlong **)(unaff_RSI + 8) + 0x60))
                    (*(longlong **)(unaff_RSI + 8),1,&stack0x00000048);
  if (-1 < iVar1) {
    CreateBindCtx(0,&stack0x00000060);
    iVar1 = (**(code **)(*in_stack_00000048 + 0x18))(in_stack_00000048,1,&stack0x00000030);
    while (iVar1 == 0) {
      in_stack_00000038 = 0;
      iVar1 = (**(code **)(*in_stack_00000030 + 0xb0))(in_stack_00000030,&stack0x00000038);
      if (iVar1 < 0) {
        bVar3 = true;
LAB_1800512e2:
        (**(code **)(*in_stack_00000030 + 0x10))();
        break;
      }
      if (in_stack_00000038 != 3) {
        bVar3 = true;
        if ((in_stack_00000038 == 4) &&
           (iVar1 = (**(code **)*plVar2)(plVar2,&DAT_180066dd8,&stack0x00000058), -1 < iVar1)) {
          iVar1 = (**(code **)(*in_stack_00000030 + 0xa0))
                            (in_stack_00000030,in_stack_00000060,0,&stack0x00000050);
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*in_stack_00000058 + 0x30))
                              (in_stack_00000058,(longlong)in_stack_00000050 + 2,1,0,&DAT_180063400)
            ;
            bVar3 = iVar1 < 0;
            if (!bVar3) {
              (**(code **)(*plVar2 + 0x10))(plVar2);
              plVar2 = in_stack_00000040;
            }
            CoTaskMemFree(in_stack_00000050);
          }
          (**(code **)(*in_stack_00000058 + 0x10))();
          if (!bVar3) goto LAB_1800512b1;
        }
        goto LAB_1800512e2;
      }
      in_stack_00000040 = (longlong *)plVar2[0xc];
      (**(code **)(*in_stack_00000040 + 8))();
      (**(code **)(*plVar2 + 0x10))(plVar2);
      plVar2 = in_stack_00000040;
LAB_1800512b1:
      (**(code **)(*in_stack_00000030 + 0x10))();
      iVar1 = (**(code **)(*in_stack_00000048 + 0x18))(in_stack_00000048,1,&stack0x00000030);
    }
    (*in_stack_00000060->lpVtbl->Release)(in_stack_00000060);
    (**(code **)(*in_stack_00000048 + 0x10))();
    if (bVar3) goto LAB_180051331;
  }
  if (((byte)*(undefined4 *)(*unaff_R12 + unaff_R13 * 4) & 0xf) == 4) {
    FUN_180051830((longlong)plVar2,unaff_R15,*(int *)(unaff_R14 + 0x30),*(int *)(unaff_R14 + 0x34));
  }
  else {
    FUN_1800517a0((longlong)plVar2,(double *)unaff_R15);
  }
LAB_180051331:
  (**(code **)(*plVar2 + 0x10))(plVar2);
  return;
}

/* ---- FUNC 00051344 FUN_180051344 (103 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180051344(void)

{
  short *unaff_RSI;
  double *unaff_R15;
  
  if ((*unaff_RSI == 9) && (*(longlong *)(unaff_RSI + 4) != 0)) {
    FUN_1800517a0(*(longlong *)(unaff_RSI + 4),unaff_R15);
  }
  return;
}

/* ---- FUNC 000513B0 FUN_1800513b0 (68 bytes) ---- */

undefined8 FUN_1800513b0(longlong param_1,undefined8 *param_2)

{
  SAFEARRAY *pSVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar2;
  BSTR pv;
  uint uVar3;
  int local_res8 [2];
  SAFEARRAYBOUND local_res10;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res18 [8];
  
  local_res10.lLbound = 1;
  local_res10.cElements = FUN_180050b60(param_1 + 0x110);
  pSVar1 = SafeArrayCreate(8,1,&local_res10);
  uVar3 = 0;
  *param_2 = pSVar1;
  if (local_res10.cElements != 0) {
    do {
      local_res8[0] = local_res10.lLbound + uVar3;
      pCVar2 = FUN_1800514c0(param_1 + 0x110,local_res18,uVar3);
      pv = FUN_18005d480(*(LPCSTR *)pCVar2);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
      SafeArrayPutElement((SAFEARRAY *)*param_2,local_res8,pv);
      uVar3 = uVar3 + 1;
    } while (uVar3 < local_res10.cElements);
  }
  return 0;
}

/* ---- FUNC 000513F4 FUN_1800513f4 (90 bytes) ---- */

undefined8 FUN_1800513f4(void)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  BSTR pv;
  longlong unaff_RBP;
  undefined8 *unaff_RSI;
  uint unaff_EDI;
  int iStack0000000000000040;
  uint uStack0000000000000048;
  int iStack000000000000004c;
  
  do {
    iStack0000000000000040 = iStack000000000000004c + unaff_EDI;
    pCVar1 = FUN_1800514c0(unaff_RBP,
                           (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &stack0x00000050,unaff_EDI);
    pv = FUN_18005d480(*(LPCSTR *)pCVar1);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000050);
    SafeArrayPutElement((SAFEARRAY *)*unaff_RSI,&stack0x00000040,pv);
    unaff_EDI = unaff_EDI + 1;
  } while (unaff_EDI < uStack0000000000000048);
  return 0;
}

/* ---- FUNC 0005144E FUN_18005144e (10 bytes) ---- */

undefined8 FUN_18005144e(void)

{
  return 0;
}

/* ---- FUNC 00051460 FUN_180051460 (25 bytes) ---- */

void FUN_180051460(longlong param_1,undefined8 param_2,OLECHAR **param_3,UINT param_4,
                  undefined8 param_5,DISPID *param_6)

{
                    /* WARNING: Could not recover jumptable at 0x000180051472. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DispGetIDsOfNames(*(ITypeInfo **)(param_1 + 8),param_3,param_4,param_6);
  return;
}

/* ---- FUNC 00051480 FUN_180051480 (32 bytes) ---- */

undefined8 FUN_180051480(longlong param_1,undefined8 *param_2)

{
  BSTR pOVar1;
  
  pOVar1 = FUN_18005d480(*(LPCSTR *)(param_1 + 0x108));
  *param_2 = pOVar1;
  return 0;
}

/* ---- FUNC 000514A0 FUN_1800514a0 (17 bytes) ---- */

void FUN_1800514a0(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800514aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_180079800 + 0xa8))();
  return;
}

/* ---- FUNC 000514C0 FUN_1800514c0 (225 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_1800514c0(longlong param_1,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2,int param_3)

{
  undefined1 auStack_448 [40];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_420;
  undefined1 local_418 [1008];
  ulonglong local_28;
  
  local_28 = DAT_180077818 ^ (ulonglong)auStack_448;
  local_420 = param_2;
  if (*(longlong *)(param_1 + 0x10) != *(longlong *)(param_1 + 0x38)) {
    FUN_180002a20(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0xd9f);
    LogMessage(local_418,2,1);
  }
  if (*(longlong *)(param_1 + 0x10) != *(longlong *)(param_1 + 0x60)) {
    FUN_180002a20(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0xda0);
    LogMessage(local_418,2,1);
  }
  if ((-1 < param_3) && ((longlong)param_3 < *(longlong *)(param_1 + 0x38))) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              (param_2,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                       (*(longlong *)(param_1 + 0x30) + (longlong)param_3 * 8));
    return param_2;
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 000515B0 FUN_1800515b0 (12 bytes) ---- */

void FUN_1800515b0(longlong param_1,undefined4 *param_2,undefined4 *param_3)

{
  *param_2 = *(undefined4 *)(param_1 + 0x30);
  *param_3 = *(undefined4 *)(param_1 + 0x34);
  return;
}

/* ---- FUNC 000515C0 FUN_1800515c0 (65 bytes) ---- */

undefined8
FUN_1800515c0(longlong param_1,undefined2 *param_2,undefined2 *param_3,undefined2 *param_4,
             undefined2 *param_5,undefined2 *param_6)

{
  *param_2 = *(undefined2 *)(param_1 + 0x17c);
  *param_3 = *(undefined2 *)(param_1 + 0x17e);
  *param_4 = *(undefined2 *)(param_1 + 0x180);
  *param_5 = *(undefined2 *)(param_1 + 0x182);
  *param_6 = *(undefined2 *)(param_1 + 0x184);
  return 0;
}

/* ---- FUNC 00051610 FUN_180051610 (90 bytes) ---- */

undefined8
FUN_180051610(longlong *param_1,int param_2,int param_3,short *param_4,VARIANTARG *param_5)

{
  undefined8 uVar1;
  
  if ((((-1 < param_2) && ((longlong)param_2 < param_1[0x1c])) && (-1 < param_3)) &&
     (param_3 < (int)param_1[0x19])) {
    FUN_180050e60(*(longlong *)(param_1[0x1b] + (longlong)param_2 * 8),param_3,param_4,param_5);
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180051663. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*param_1 + 0x2b8))(param_1,0x7d1);
  return uVar1;
}

/* ---- FUNC 00051670 FUN_180051670 (90 bytes) ---- */

undefined8
FUN_180051670(longlong *param_1,int param_2,int param_3,short *param_4,VARIANTARG *param_5)

{
  undefined8 uVar1;
  
  if ((((-1 < param_2) && ((longlong)param_2 < param_1[0x21])) && (-1 < param_3)) &&
     (param_3 < (int)param_1[0x19])) {
    FUN_180050e60(*(longlong *)(param_1[0x20] + (longlong)param_2 * 8),param_3,param_4,param_5);
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0001800516c3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*param_1 + 0x2b8))(param_1,0x7d1);
  return uVar1;
}

/* ---- FUNC 000516D0 FUN_1800516d0 (206 bytes) ---- */

void FUN_1800516d0(VARIANTARG *param_1,_union_1719 *param_2)

{
  VARTYPE VVar1;
  HRESULT HVar2;
  _union_2707 local_28;
  
  VVar1 = (param_1->n1).n2.vt;
  if (VVar1 == 2) {
    *param_2 = (_union_1719)(double)(int)*(short *)((longlong)&param_1->n1 + 8);
  }
  else {
    if (VVar1 == 3) {
      *param_2 = (_union_1719)(double)*(int *)((longlong)&param_1->n1 + 8);
      return;
    }
    if (VVar1 == 4) {
      *param_2 = (_union_1719)(double)*(float *)((longlong)&param_1->n1 + 8);
      return;
    }
    if (VVar1 == 5) {
      *param_2 = (param_1->n1).decVal.u2;
      return;
    }
    if ((VVar1 == 8) && ((param_1->n1).decVal.u2.Lo64 != 0)) {
      local_28.n2.vt = 0;
      HVar2 = VariantChangeTypeEx((VARIANTARG *)&local_28.n2,param_1,0x400,0,5);
      if (-1 < HVar2) {
        *param_2 = local_28.decVal.u2;
      }
      VariantClear((VARIANTARG *)&local_28.n2);
      return;
    }
  }
  return;
}

/* ---- FUNC 000517A0 FUN_1800517a0 (132 bytes) ---- */

void FUN_1800517a0(longlong param_1,double *param_2)

{
  undefined8 *puVar1;
  undefined8 local_28;
  double *pdStack_20;
  code *local_18;
  
  if (*(longlong *)(param_1 + 0x48) != 0) {
    local_28 = 0;
    pdStack_20 = (double *)0x0;
    local_18 = (code *)0x0;
    puVar1 = (undefined8 *)HAGetElementLabel(*(longlong *)(param_1 + 0x48),0,&local_28);
    if (puVar1 == (undefined8 *)0x0) {
      if (pdStack_20 != (double *)0x0) {
        if ((int)local_28 == -2) {
          *param_2 = *pdStack_20;
        }
        else if ((int)local_28 == -1) {
          *param_2 = (double)*(int *)pdStack_20;
        }
        if (local_18 != (code *)0x0) {
          (*local_18)();
        }
      }
    }
    else if ((code *)*puVar1 != (code *)0x0) {
      (*(code *)*puVar1)(puVar1);
      return;
    }
  }
  return;
}

/* ---- FUNC 00051830 FUN_180051830 (674 bytes) ---- */

void FUN_180051830(longlong param_1,_union_1719 *param_2,int param_3,int param_4)

{
  _struct_1720 *lpMultiByteStr;
  int cchWideChar;
  int iVar1;
  HRESULT HVar2;
  undefined8 *puVar3;
  _union_1719 lpWideCharStr;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  _union_1719 bstrString;
  DOUBLE local_58;
  _union_1719 local_50;
  _union_2707 local_48;
  undefined8 local_30;
  _struct_1720 *p_Stack_28;
  code *local_20;
  
  if (*(longlong *)(param_1 + 0x48) == 0) {
    return;
  }
  VariantInit((VARIANTARG *)&local_48.n2);
  local_30 = 0;
  p_Stack_28 = (_struct_1720 *)0x0;
  local_20 = (code *)0x0;
  bstrString.Lo64 = 0;
  if ((param_3 < 1) || (param_4 < 1)) {
LAB_1800518af:
    puVar3 = (undefined8 *)HAGetAttr(*(undefined8 *)(param_1 + 0x48),0,0,&local_30);
    if (puVar3 != (undefined8 *)0x0) {
      if ((code *)*puVar3 != (code *)0x0) {
        (*(code *)*puVar3)(puVar3);
      }
      goto LAB_180051a88;
    }
  }
  else {
    puVar3 = (undefined8 *)
             HAGetValForUnitsBasis(*(undefined8 *)(param_1 + 0x48),&local_30,param_3,param_4,0);
    if (puVar3 != (undefined8 *)0x0) {
      if ((code *)*puVar3 != (code *)0x0) {
        (*(code *)*puVar3)(puVar3);
      }
      goto LAB_1800518af;
    }
  }
  lpMultiByteStr = p_Stack_28;
  if ((int)local_30 == -6) {
    VariantCopy((VARIANTARG *)&local_48.n2,(VARIANTARG *)p_Stack_28);
  }
  else if ((int)local_30 == -3) {
    if (p_Stack_28 == (_struct_1720 *)0x0) {
      local_48.n2.vt = 5;
      local_48.decVal.u2 = DAT_180066888;
    }
    else {
      cchWideChar = MultiByteToWideChar(0,0,(LPCSTR)p_Stack_28,-1,(LPWSTR)0x0,0);
      lpWideCharStr = (_union_1719)SysAllocStringLen((OLECHAR *)0x0,cchWideChar - 1);
      if ((lpWideCharStr.Lo64 != 0) &&
         (iVar1 = MultiByteToWideChar(0,0,(LPCSTR)lpMultiByteStr,-1,(LPWSTR)lpWideCharStr,
                                      cchWideChar), iVar1 != cchWideChar)) {
        SysFreeString((BSTR)lpWideCharStr);
LAB_180051ac8:
                    /* WARNING: Subroutine does not return */
        FUN_180001a90(-0x7ff8fff2);
      }
      if (lpWideCharStr.Lo64 == 0) goto LAB_180051ac8;
      HVar2 = VarR8FromStr((LPCOLESTR)lpWideCharStr,0x7f,0,&local_58);
      if (((HVar2 < 0) || (HVar2 = VarBstrFromR8(local_58,0x400,0,(BSTR *)&local_50), HVar2 < 0)) ||
         (SysFreeString((BSTR)lpWideCharStr), lpWideCharStr = local_50, HVar2 != 0)) {
        bstrString = lpWideCharStr;
        local_48.n2.vt = 8;
        this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
               CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          &local_50.s2,(char *)p_Stack_28);
        local_48.decVal.u2 =
             (_union_1719)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::AllocSysString
                       (this);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_50.s2);
      }
      else {
        local_48.n2.vt = 8;
        local_48.decVal.u2 = local_50;
      }
      SysFreeString((BSTR)bstrString);
    }
  }
  else if ((int)local_30 == -2) {
    local_48.n2.vt = 5;
    if (p_Stack_28 == (_struct_1720 *)0x0) {
      local_48.decVal.u2.Lo64 = (_union_1719)0x0;
    }
    else {
      local_48.decVal.u2 = (_union_1719)*p_Stack_28;
    }
  }
  else if ((int)local_30 == -1) {
    local_48.n2.vt = 3;
    if (p_Stack_28 == (_struct_1720 *)0x0) {
      local_48.decVal.u2 = (_union_1719)((ulonglong)(uint)local_48._12_4_ << 0x20);
    }
    else {
      local_48._8_4_ = p_Stack_28->Lo32;
    }
  }
  if (local_20 != (code *)0x0) {
    (*local_20)(p_Stack_28);
  }
LAB_180051a88:
  if (local_48.n2.vt != 0) {
    FUN_1800516d0((VARIANTARG *)&local_48.n2,param_2);
    VariantClear((VARIANTARG *)&local_48.n2);
  }
  return;
}

/* ---- FUNC 00051AE0 FUN_180051ae0 (14 bytes) ---- */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_180051ae0(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,
             longlong *param_2,int param_3,int param_4,wchar_t *param_5)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  longlong lVar4;
  int iVar5;
  wchar_t *_Str2;
  char *local_80;
  char *local_78;
  char *local_70;
  undefined2 local_68;
  undefined6 uStack_66;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  iVar5 = 0;
  local_68 = 0;
  cVar1 = (char)*param_5;
  _Str2 = param_5;
  do {
    if ((cVar1 == '\0') || (0xfe < iVar5)) {
      if ((ulonglong)(longlong)iVar5 < 0x100) {
        (&DAT_180079f10)[iVar5] = 0;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1,&DAT_180079f10);
        return param_1;
      }
                    /* WARNING: Subroutine does not return */
      FUN_18005c254();
    }
    if ((char)*_Str2 == '%') {
      iVar2 = _strnicmp("%ID%",(char *)_Str2,4);
      if (iVar2 == 0) {
        _Str2 = (wchar_t *)((longlong)_Str2 + 3);
        if (param_2 != (longlong *)0x0) {
          local_48 = CONCAT62(uStack_66,local_68);
          uStack_40 = uStack_60;
          local_38 = local_58;
          iVar2 = (**(code **)(*param_2 + 0x48))(param_2,&local_48,&param_5);
          if (-1 < iVar2) {
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_80,
                       param_5);
            pcVar3 = local_80;
            do {
              cVar1 = *pcVar3;
              pcVar3[(longlong)(&DAT_180079f10 + ((longlong)iVar5 - (longlong)local_80))] = cVar1;
              pcVar3 = pcVar3 + 1;
            } while (cVar1 != '\0');
            lVar4 = -1;
            do {
              lVar4 = lVar4 + 1;
            } while (local_80[lVar4] != '\0');
            iVar5 = iVar5 + (int)lVar4 + -1;
            SysFreeString(param_5);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_80);
          }
        }
      }
      else {
        iVar2 = _strnicmp("%Unit%",(char *)_Str2,6);
        if (iVar2 == 0) {
          _Str2 = (wchar_t *)((longlong)_Str2 + 5);
          if (((param_2 == (longlong *)0x0) || (param_3 < 1)) || (param_4 < 1)) {
LAB_180051ca4:
            iVar5 = iVar5 + -1;
          }
          else {
            pcVar3 = FUN_18003e780((longlong)param_2,param_3,param_4);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_78,
                       pcVar3);
            pcVar3 = local_78;
            do {
              cVar1 = *pcVar3;
              pcVar3[(longlong)(&DAT_180079f10 + ((longlong)iVar5 - (longlong)local_78))] = cVar1;
              pcVar3 = pcVar3 + 1;
            } while (cVar1 != '\0');
            lVar4 = -1;
            do {
              lVar4 = lVar4 + 1;
            } while (local_78[lVar4] != '\0');
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_78);
            iVar5 = (int)lVar4 + iVar5 + -1;
          }
        }
        else {
          iVar2 = _strnicmp("%Quantity%",(char *)_Str2,10);
          if (iVar2 == 0) {
            _Str2 = (wchar_t *)((longlong)_Str2 + 9);
            if (((param_2 == (longlong *)0x0) || (param_3 < 1)) || (param_4 < 1))
            goto LAB_180051ca4;
            pcVar3 = FUN_180052f70(param_3);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_70,
                       pcVar3);
            pcVar3 = local_70;
            do {
              cVar1 = *pcVar3;
              pcVar3[(longlong)(&DAT_180079f10 + ((longlong)iVar5 - (longlong)local_70))] = cVar1;
              pcVar3 = pcVar3 + 1;
            } while (cVar1 != '\0');
            lVar4 = -1;
            do {
              lVar4 = lVar4 + 1;
            } while (local_70[lVar4] != '\0');
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_70);
            iVar5 = (int)lVar4 + iVar5 + -1;
          }
          else {
            if (*(char *)((longlong)_Str2 + 1) != '%') goto LAB_180051d44;
            _Str2 = (wchar_t *)((longlong)_Str2 + 1);
            (&DAT_180079f10)[iVar5] = 0x25;
          }
        }
      }
    }
    else {
LAB_180051d44:
      (&DAT_180079f10)[iVar5] = (char)*_Str2;
    }
    _Str2 = (wchar_t *)((longlong)_Str2 + 1);
    iVar5 = iVar5 + 1;
    cVar1 = *(char *)_Str2;
  } while( true );
}

/* ---- FUNC 00051AEE FUN_180051aee (62 bytes) ---- */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_180051aee(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,
             longlong *param_2,int param_3,int param_4,char *param_5,char *param_6,char *param_7,
             undefined8 param_8,undefined8 param_9,undefined8 param_10,undefined8 param_11,
             undefined8 param_12,undefined8 param_13,undefined8 param_14)

{
  char cVar1;
  int iVar2;
  longlong in_RAX;
  char *pcVar3;
  longlong lVar4;
  undefined8 unaff_RBX;
  undefined8 unaff_RBP;
  int iVar5;
  undefined8 unaff_RSI;
  undefined8 unaff_RDI;
  wchar_t *_Str2;
  undefined8 unaff_R14;
  undefined8 unaff_R15;
  wchar_t *in_stack_000000d0;
  
  *(undefined8 *)(in_RAX + 0x10) = unaff_RBP;
  *(undefined8 *)(in_RAX + 0x18) = unaff_RSI;
  *(undefined8 *)(in_RAX + -0x18) = unaff_RDI;
  iVar5 = 0;
  *(undefined8 *)(in_RAX + -0x20) = unaff_R14;
  *(undefined8 *)(in_RAX + -0x28) = unaff_R15;
  *(undefined2 *)(in_RAX + -0x68) = 0;
  if ((char)*in_stack_000000d0 != '\0') {
    *(undefined8 *)(in_RAX + 8) = unaff_RBX;
    _Str2 = in_stack_000000d0;
    do {
      if (0xfe < iVar5) break;
      if ((char)*_Str2 == '%') {
        iVar2 = _strnicmp("%ID%",(char *)_Str2,4);
        if (iVar2 == 0) {
          _Str2 = (wchar_t *)((longlong)_Str2 + 3);
          if (param_2 != (longlong *)0x0) {
            param_12 = param_8;
            param_13 = param_9;
            param_14 = param_10;
            iVar2 = (**(code **)(*param_2 + 0x48))(param_2,&param_12,&stack0x000000d0);
            if (-1 < iVar2) {
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&param_5,
                         in_stack_000000d0);
              pcVar3 = param_5;
              do {
                cVar1 = *pcVar3;
                pcVar3[(longlong)(&DAT_180079f10 + ((longlong)iVar5 - (longlong)param_5))] = cVar1;
                pcVar3 = pcVar3 + 1;
              } while (cVar1 != '\0');
              lVar4 = -1;
              do {
                lVar4 = lVar4 + 1;
              } while (param_5[lVar4] != '\0');
              iVar5 = iVar5 + (int)lVar4 + -1;
              SysFreeString(in_stack_000000d0);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&param_5);
            }
          }
        }
        else {
          iVar2 = _strnicmp("%Unit%",(char *)_Str2,6);
          if (iVar2 == 0) {
            _Str2 = (wchar_t *)((longlong)_Str2 + 5);
            if (((param_2 == (longlong *)0x0) || (param_3 < 1)) || (param_4 < 1)) {
LAB_180051ca4:
              iVar5 = iVar5 + -1;
            }
            else {
              pcVar3 = FUN_18003e780((longlong)param_2,param_3,param_4);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&param_6,
                         pcVar3);
              pcVar3 = param_6;
              do {
                cVar1 = *pcVar3;
                pcVar3[(longlong)(&DAT_180079f10 + ((longlong)iVar5 - (longlong)param_6))] = cVar1;
                pcVar3 = pcVar3 + 1;
              } while (cVar1 != '\0');
              lVar4 = -1;
              do {
                lVar4 = lVar4 + 1;
              } while (param_6[lVar4] != '\0');
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&param_6);
              iVar5 = (int)lVar4 + iVar5 + -1;
            }
          }
          else {
            iVar2 = _strnicmp("%Quantity%",(char *)_Str2,10);
            if (iVar2 == 0) {
              _Str2 = (wchar_t *)((longlong)_Str2 + 9);
              if (((param_2 == (longlong *)0x0) || (param_3 < 1)) || (param_4 < 1))
              goto LAB_180051ca4;
              pcVar3 = FUN_180052f70(param_3);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&param_7,
                         pcVar3);
              pcVar3 = param_7;
              do {
                cVar1 = *pcVar3;
                pcVar3[(longlong)(&DAT_180079f10 + ((longlong)iVar5 - (longlong)param_7))] = cVar1;
                pcVar3 = pcVar3 + 1;
              } while (cVar1 != '\0');
              lVar4 = -1;
              do {
                lVar4 = lVar4 + 1;
              } while (param_7[lVar4] != '\0');
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&param_7);
              iVar5 = (int)lVar4 + iVar5 + -1;
            }
            else {
              if (*(char *)((longlong)_Str2 + 1) != '%') goto LAB_180051d44;
              _Str2 = (wchar_t *)((longlong)_Str2 + 1);
              (&DAT_180079f10)[iVar5] = 0x25;
            }
          }
        }
      }
      else {
LAB_180051d44:
        (&DAT_180079f10)[iVar5] = (char)*_Str2;
      }
      _Str2 = (wchar_t *)((longlong)_Str2 + 1);
      iVar5 = iVar5 + 1;
    } while (*(char *)_Str2 != '\0');
  }
  if (0xff < (ulonglong)(longlong)iVar5) {
                    /* WARNING: Subroutine does not return */
    FUN_18005c254();
  }
  (&DAT_180079f10)[iVar5] = 0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1,&DAT_180079f10);
  return param_1;
}

/* ---- FUNC 00051B2C FUN_180051b2c (568 bytes) ---- */

void FUN_180051b2c(void)

{
  char cVar1;
  int iVar2;
  longlong in_RAX;
  char *pcVar3;
  longlong lVar4;
  undefined8 unaff_RBX;
  int unaff_EBP;
  int unaff_ESI;
  char *unaff_RDI;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *unaff_R12;
  char *unaff_R13;
  longlong *unaff_R14;
  int unaff_R15D;
  char *in_stack_00000028;
  char *in_stack_00000030;
  char *in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  wchar_t *in_stack_000000d0;
  
  *(undefined8 *)(in_RAX + 8) = unaff_RBX;
  do {
    if (0xfe < unaff_ESI) break;
    if (*unaff_RDI == '%') {
      iVar2 = _strnicmp("%ID%",unaff_RDI,4);
      if (iVar2 == 0) {
        unaff_RDI = unaff_RDI + 3;
        if (unaff_R14 != (longlong *)0x0) {
          in_stack_00000060 = in_stack_00000040;
          in_stack_00000068 = in_stack_00000048;
          in_stack_00000070 = in_stack_00000050;
          iVar2 = (**(code **)(*unaff_R14 + 0x48))
                            ((int)in_stack_00000050,&stack0x00000060,&stack0x000000d0);
          if (-1 < iVar2) {
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       &stack0x00000028,in_stack_000000d0);
            pcVar3 = in_stack_00000028;
            do {
              cVar1 = *pcVar3;
              (unaff_R13 + ((longlong)unaff_ESI - (longlong)in_stack_00000028))[(longlong)pcVar3] =
                   cVar1;
              pcVar3 = pcVar3 + 1;
            } while (cVar1 != '\0');
            lVar4 = -1;
            do {
              lVar4 = lVar4 + 1;
            } while (in_stack_00000028[lVar4] != '\0');
            unaff_ESI = unaff_ESI + (int)lVar4 + -1;
            SysFreeString(in_stack_000000d0);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       &stack0x00000028);
          }
        }
      }
      else {
        iVar2 = _strnicmp("%Unit%",unaff_RDI,6);
        if (iVar2 == 0) {
          unaff_RDI = unaff_RDI + 5;
          if (((unaff_R14 == (longlong *)0x0) || (unaff_EBP < 1)) || (unaff_R15D < 1)) {
LAB_180051ca4:
            unaff_ESI = unaff_ESI + -1;
          }
          else {
            pcVar3 = FUN_18003e780((longlong)unaff_R14,unaff_EBP,unaff_R15D);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       &stack0x00000030,pcVar3);
            pcVar3 = in_stack_00000030;
            do {
              cVar1 = *pcVar3;
              (unaff_R13 + ((longlong)unaff_ESI - (longlong)in_stack_00000030))[(longlong)pcVar3] =
                   cVar1;
              pcVar3 = pcVar3 + 1;
            } while (cVar1 != '\0');
            lVar4 = -1;
            do {
              lVar4 = lVar4 + 1;
            } while (in_stack_00000030[lVar4] != '\0');
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       &stack0x00000030);
            unaff_ESI = (int)lVar4 + unaff_ESI + -1;
          }
        }
        else {
          iVar2 = _strnicmp("%Quantity%",unaff_RDI,10);
          if (iVar2 == 0) {
            unaff_RDI = unaff_RDI + 9;
            if (((unaff_R14 == (longlong *)0x0) || (unaff_EBP < 1)) || (unaff_R15D < 1))
            goto LAB_180051ca4;
            pcVar3 = FUN_180052f70(unaff_EBP);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       &stack0x00000038,pcVar3);
            pcVar3 = in_stack_00000038;
            do {
              cVar1 = *pcVar3;
              (unaff_R13 + ((longlong)unaff_ESI - (longlong)in_stack_00000038))[(longlong)pcVar3] =
                   cVar1;
              pcVar3 = pcVar3 + 1;
            } while (cVar1 != '\0');
            lVar4 = -1;
            do {
              lVar4 = lVar4 + 1;
            } while (in_stack_00000038[lVar4] != '\0');
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       &stack0x00000038);
            unaff_ESI = (int)lVar4 + unaff_ESI + -1;
          }
          else {
            if (unaff_RDI[1] != '%') goto LAB_180051d44;
            unaff_RDI = unaff_RDI + 1;
            unaff_R13[unaff_ESI] = '%';
          }
        }
      }
    }
    else {
LAB_180051d44:
      unaff_R13[unaff_ESI] = *unaff_RDI;
    }
    unaff_RDI = unaff_RDI + 1;
    unaff_ESI = unaff_ESI + 1;
  } while (*unaff_RDI != '\0');
  if ((ulonglong)(longlong)unaff_ESI < 0x100) {
    unaff_R13[unaff_ESI] = '\0';
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(unaff_R12,unaff_R13);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18005c254();
}

/* ---- FUNC 00051D64 FUN_180051d64 (88 bytes) ---- */

void FUN_180051d64(void)

{
  int unaff_ESI;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *unaff_R12;
  char *unaff_R13;
  
  if ((ulonglong)(longlong)unaff_ESI < 0x100) {
    unaff_R13[unaff_ESI] = '\0';
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(unaff_R12,unaff_R13);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18005c254();
}

/* ---- FUNC 00051D97 FUN_180051d97 (32 bytes) ---- */

void FUN_180051d97(void)

{
  longlong in_RAX;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *unaff_R12;
  char *unaff_R13;
  
  unaff_R13[in_RAX] = '\0';
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(unaff_R12,unaff_R13);
  return;
}

/* ---- FUNC 00051DC0 FUN_180051dc0 (171 bytes) ---- */

HRESULT FUN_180051dc0(void *param_1,DISPID param_2,undefined8 param_3,undefined8 param_4,
                     WORD param_5,DISPPARAMS *param_6,VARIANT *param_7,EXCEPINFO *param_8,
                     UINT *param_9)

{
  undefined8 uVar1;
  BSTR pOVar2;
  PVOID pvVar3;
  HRESULT HVar4;
  
  *(undefined4 *)((longlong)param_1 + 0x88) = 0;
  HVar4 = DispInvoke(param_1,*(ITypeInfo **)((longlong)param_1 + 8),param_2,param_5,param_6,param_7,
                     param_8,param_9);
  if (*(int *)((longlong)param_1 + 0x88) != 0) {
    if (param_8 != (EXCEPINFO *)0x0) {
      uVar1 = *(undefined8 *)((longlong)param_1 + 0x48);
      pOVar2 = *(BSTR *)((longlong)param_1 + 0x50);
      param_8->wCode = (short)uVar1;
      param_8->wReserved = (short)((ulonglong)uVar1 >> 0x10);
      *(int *)&param_8->field_0x4 = (int)((ulonglong)uVar1 >> 0x20);
      param_8->bstrSource = pOVar2;
      pOVar2 = *(BSTR *)((longlong)param_1 + 0x60);
      param_8->bstrDescription = *(BSTR *)((longlong)param_1 + 0x58);
      param_8->bstrHelpFile = pOVar2;
      pvVar3 = *(PVOID *)((longlong)param_1 + 0x70);
      *(undefined8 *)&param_8->dwHelpContext = *(undefined8 *)((longlong)param_1 + 0x68);
      param_8->pvReserved = pvVar3;
      uVar1 = *(undefined8 *)((longlong)param_1 + 0x80);
      param_8->pfnDeferredFillIn = *(_func_6477 **)((longlong)param_1 + 0x78);
      *(undefined8 *)&param_8->scode = uVar1;
      *(undefined8 *)((longlong)param_1 + 0x48) = 0;
      *(undefined8 *)((longlong)param_1 + 0x50) = 0;
      *(undefined8 *)((longlong)param_1 + 0x58) = 0;
      *(undefined8 *)((longlong)param_1 + 0x60) = 0;
      *(undefined8 *)((longlong)param_1 + 0x68) = 0;
      *(undefined8 *)((longlong)param_1 + 0x70) = 0;
      *(undefined8 *)((longlong)param_1 + 0x78) = 0;
      *(undefined8 *)((longlong)param_1 + 0x80) = 0;
    }
    HVar4 = -0x7ffdfff7;
  }
  return HVar4;
}

/* ---- FUNC 00051E70 FUN_180051e70 (1905 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HRESULT FUN_180051e70(longlong param_1,LPSTREAM param_2)

{
  IStreamVtbl *pIVar1;
  HRESULT HVar2;
  int iVar3;
  char *pcVar4;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar5;
  BSTR pOVar6;
  uint uVar7;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar9;
  undefined1 auStack_468 [32];
  ULONG local_448;
  ULONG local_444;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_440;
  undefined1 local_438 [1008];
  ulonglong local_48;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar8;
  
  local_48 = DAT_180077818 ^ (ulonglong)auStack_468;
  if (*(longlong *)(param_1 + 0x18) != 0) {
    FUN_180002a20(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0x93c);
    LogMessage(local_438,2,1);
  }
  if (*(longlong *)(param_1 + 0x20) != 0) {
    FUN_180002a20(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0x93d);
    LogMessage(local_438,2,1);
  }
  if (*(longlong *)(param_1 + 0xe0) != 1) {
    FUN_180002a20(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0x93e);
    LogMessage(local_438,2,1);
  }
  if (*(longlong *)(param_1 + 0x108) != 0) {
    FUN_180002a20(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0x93f);
    LogMessage(local_438,2,1);
  }
  if (*(longlong *)(param_1 + 0x130) != 0) {
    FUN_180002a20(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0x940);
    LogMessage(local_438,2,1);
  }
  if (*(longlong *)(param_1 + 0xe0) < 1) {
                    /* WARNING: Subroutine does not return */
    AfxThrowInvalidArgException();
  }
  pCVar8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
           **(undefined8 **)(param_1 + 0xd8);
  if (pCVar8 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
    FUN_180050580(pCVar8);
    FUN_180025ad0(pCVar8);
  }
  CPtrArray::SetSize((CPtrArray *)(param_1 + 0xd0),0,-1);
  HVar2 = FUN_18002b260(DAT_180079590,param_2,param_1 + 0x18,0);
  if ((-1 < HVar2) && (HVar2 = FUN_18002b260(DAT_180079590,param_2,param_1 + 0x20,0), -1 < HVar2)) {
    pCVar9 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    local_448 = 0;
    (*param_2->lpVtbl->Read)(param_2,&local_448,4,(ULONG *)0x0);
    pIVar1 = param_2->lpVtbl;
    pcVar4 = ATL::CSimpleStringT<char,1>::GetBuffer
                       ((CSimpleStringT<char,1> *)(param_1 + 0x90),local_448);
    (*pIVar1->Read)(param_2,pcVar4,local_448,(ULONG *)0x0);
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)(param_1 + 0x90),-1);
    (*param_2->lpVtbl->Read)(param_2,&local_448,4,(ULONG *)0x0);
    CStringArray::SetSize((CStringArray *)(param_1 + 0x98),(longlong)(int)local_448,-1);
    pCVar8 = pCVar9;
    if (0 < (int)local_448) {
      do {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_440);
        (*param_2->lpVtbl->Read)(param_2,&local_444,4,(ULONG *)0x0);
        pIVar1 = param_2->lpVtbl;
        pcVar4 = ATL::CSimpleStringT<char,1>::GetBuffer
                           ((CSimpleStringT<char,1> *)&local_440,local_444);
        (*pIVar1->Read)(param_2,pcVar4,local_444,(ULONG *)0x0);
        ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_440,-1);
        iVar3 = (int)pCVar8;
        if ((iVar3 < 0) || (*(longlong *)(param_1 + 0xa8) <= (longlong)iVar3)) {
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                   (*(longlong *)(param_1 + 0xa0) + (longlong)iVar3 * 8),
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   &local_440);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_440);
        pCVar8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                 (ulonglong)(iVar3 + 1U);
      } while ((int)(iVar3 + 1U) < (int)local_448);
    }
    (*param_2->lpVtbl->Read)(param_2,&local_448,4,(ULONG *)0x0);
    pIVar1 = param_2->lpVtbl;
    pcVar4 = ATL::CSimpleStringT<char,1>::GetBuffer
                       ((CSimpleStringT<char,1> *)(param_1 + 0xc0),local_448);
    (*pIVar1->Read)(param_2,pcVar4,local_448,(ULONG *)0x0);
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)(param_1 + 0xc0),-1);
    (*param_2->lpVtbl->Read)(param_2,(void *)(param_1 + 200),4,(ULONG *)0x0);
    (*param_2->lpVtbl->Read)(param_2,&local_448,4,(ULONG *)0x0);
    pCVar8 = pCVar9;
    if (0 < (int)local_448) {
      do {
        local_440 = operator_new(0x40);
        pCVar5 = pCVar9;
        if (local_440 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
          pCVar5 = FUN_180050130(local_440);
        }
        iVar3 = FUN_180052a30((CSimpleStringT<char,1> *)pCVar5,param_2);
        if (iVar3 < 0) goto LAB_180052294;
        CPtrArray::SetAtGrow((CPtrArray *)(param_1 + 0xd0),*(__int64 *)(param_1 + 0xe0),pCVar5);
        uVar7 = (int)pCVar8 + 1;
        pCVar8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(ulonglong)uVar7;
      } while ((int)uVar7 < (int)local_448);
    }
    (*param_2->lpVtbl->Read)(param_2,&local_448,4,(ULONG *)0x0);
    pCVar8 = pCVar9;
    if (0 < (int)local_448) {
      do {
        local_440 = operator_new(0x40);
        pCVar5 = pCVar9;
        if (local_440 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
          pCVar5 = FUN_180050130(local_440);
        }
        iVar3 = FUN_180052a30((CSimpleStringT<char,1> *)pCVar5,param_2);
        if (iVar3 < 0) {
LAB_180052294:
          if (pCVar5 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
            return iVar3;
          }
          FUN_180050580(pCVar5);
          FUN_180025ad0(pCVar5);
          return iVar3;
        }
        CPtrArray::SetAtGrow((CPtrArray *)(param_1 + 0xf8),*(__int64 *)(param_1 + 0x108),pCVar5);
        uVar7 = (int)pCVar8 + 1;
        pCVar8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(ulonglong)uVar7;
      } while ((int)uVar7 < (int)local_448);
    }
    (*param_2->lpVtbl->Read)(param_2,&local_448,4,(ULONG *)0x0);
    pCVar8 = pCVar9;
    if (0 < (int)local_448) {
      do {
        local_440 = operator_new(0x30);
        pCVar5 = pCVar9;
        if (local_440 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
          *(undefined8 *)(local_440 + 0x10) = 0;
          *(undefined8 *)local_440 = 0;
          *(undefined8 *)(local_440 + 8) = 0;
          *(undefined4 *)(local_440 + 0x18) = 0;
          *(undefined4 *)(local_440 + 0x28) = 0;
          *(undefined8 *)(local_440 + 0x20) = 0;
          *(undefined2 *)(local_440 + 0x2c) = 0;
          pCVar5 = local_440;
        }
        local_444 = 0;
        (*param_2->lpVtbl->Read)(param_2,&local_444,4,(ULONG *)0x0);
        pOVar6 = SysAllocStringLen((OLECHAR *)0x0,(int)local_444 / 2);
        *(BSTR *)(pCVar5 + 0x10) = pOVar6;
        (*param_2->lpVtbl->Read)(param_2,pOVar6,local_444,(ULONG *)0x0);
        (*param_2->lpVtbl->Read)(param_2,pCVar5,8,(ULONG *)0x0);
        (*param_2->lpVtbl->Read)(param_2,pCVar5 + 8,8,(ULONG *)0x0);
        (*param_2->lpVtbl->Read)(param_2,pCVar5 + 0x18,4,(ULONG *)0x0);
        (*param_2->lpVtbl->Read)(param_2,&local_444,4,(ULONG *)0x0);
        pOVar6 = SysAllocStringLen((OLECHAR *)0x0,(int)local_444 / 2);
        *(BSTR *)(pCVar5 + 0x20) = pOVar6;
        (*param_2->lpVtbl->Read)(param_2,pOVar6,local_444,(ULONG *)0x0);
        (*param_2->lpVtbl->Read)(param_2,pCVar5 + 0x28,2,(ULONG *)0x0);
        (*param_2->lpVtbl->Read)(param_2,pCVar5 + 0x2a,2,(ULONG *)0x0);
        (*param_2->lpVtbl->Read)(param_2,pCVar5 + 0x2c,2,(ULONG *)0x0);
        CPtrArray::SetAtGrow((CPtrArray *)(param_1 + 0x120),*(__int64 *)(param_1 + 0x130),pCVar5);
        uVar7 = (int)pCVar8 + 1;
        pCVar8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(ulonglong)uVar7;
      } while ((int)uVar7 < (int)local_448);
    }
    (*param_2->lpVtbl->Read)(param_2,(void *)(param_1 + 0x148),4,(ULONG *)0x0);
    (*param_2->lpVtbl->Read)(param_2,(void *)(param_1 + 0x14c),4,(ULONG *)0x0);
    (*param_2->lpVtbl->Read)(param_2,(void *)(param_1 + 0x150),4,(ULONG *)0x0);
    (*param_2->lpVtbl->Read)(param_2,(void *)(param_1 + 0x154),4,(ULONG *)0x0);
    (*param_2->lpVtbl->Read)(param_2,(void *)(param_1 + 0x158),4,(ULONG *)0x0);
    (*param_2->lpVtbl->Read)(param_2,(void *)(param_1 + 0x15c),4,(ULONG *)0x0);
    (*param_2->lpVtbl->Read)(param_2,(void *)(param_1 + 0x160),4,(ULONG *)0x0);
    (*param_2->lpVtbl->Read)(param_2,(void *)(param_1 + 0x164),2,(ULONG *)0x0);
    (*param_2->lpVtbl->Read)(param_2,(void *)(param_1 + 0x166),2,(ULONG *)0x0);
    (*param_2->lpVtbl->Read)(param_2,(void *)(param_1 + 0x16c),4,(ULONG *)0x0);
    (*param_2->lpVtbl->Read)(param_2,(void *)(param_1 + 0x168),2,(ULONG *)0x0);
    (*param_2->lpVtbl->Read)(param_2,(void *)(param_1 + 0x170),4,(ULONG *)0x0);
    (*param_2->lpVtbl->Read)(param_2,(void *)(param_1 + 0x174),4,(ULONG *)0x0);
    (*param_2->lpVtbl->Read)(param_2,(void *)(param_1 + 0x178),4,(ULONG *)0x0);
    HVar2 = 0;
  }
  return HVar2;
}

/* ---- FUNC 000525F0 FUN_1800525f0 (295 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HRESULT FUN_1800525f0(longlong param_1,IStream *param_2)

{
  IStreamVtbl *pIVar1;
  int iVar2;
  HRESULT HVar3;
  char *pcVar4;
  undefined1 auStack_458 [32];
  ULONG local_438 [2];
  undefined8 local_430 [3];
  undefined1 local_418 [1008];
  ulonglong local_28;
  
  local_28 = DAT_180077818 ^ (ulonglong)auStack_458;
  if (*(longlong *)(param_1 + 0xb0) != 0) {
    FUN_180002a20(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0xde5);
    LogMessage(local_418,2,1);
  }
  if (*(longlong *)(param_1 + 0xe0) != 0) {
    FUN_180002a20(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0xde6);
    LogMessage(local_418,2,1);
  }
  iVar2 = FUN_180050b60(param_1 + 0x110);
  if (iVar2 != 0) {
    FUN_180002a20(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0xde7);
    LogMessage(local_418,2,1);
  }
  FUN_1800255a0(local_430);
  (*param_2->lpVtbl->Read)(param_2,(void *)(param_1 + 0x8c),4,(ULONG *)0x0);
  HVar3 = FUN_180051e70(*(longlong *)(param_1 + 0x90),param_2);
  if (-1 < HVar3) {
    (*param_2->lpVtbl->Read)(param_2,local_438,4,(ULONG *)0x0);
    pIVar1 = param_2->lpVtbl;
    pcVar4 = ATL::CSimpleStringT<char,1>::GetBuffer
                       ((CSimpleStringT<char,1> *)(param_1 + 0xf8),local_438[0]);
    (*pIVar1->Read)(param_2,pcVar4,local_438[0],(ULONG *)0x0);
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)(param_1 + 0xf8),-1);
    (*param_2->lpVtbl->Read)(param_2,local_438,4,(ULONG *)0x0);
    pIVar1 = param_2->lpVtbl;
    pcVar4 = ATL::CSimpleStringT<char,1>::GetBuffer
                       ((CSimpleStringT<char,1> *)(param_1 + 0x108),local_438[0]);
    (*pIVar1->Read)(param_2,pcVar4,local_438[0],(ULONG *)0x0);
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)(param_1 + 0x108),-1);
    HVar3 = FUN_180052810((longlong *)(param_1 + 0x110),param_2);
  }
  FUN_180025a20(local_430);
  return HVar3;
}

/* ---- FUNC 00052717 FUN_180052717 (174 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HRESULT FUN_180052717(void)

{
  IStreamVtbl *pIVar1;
  HRESULT HVar2;
  longlong in_RAX;
  char *pcVar3;
  longlong unaff_RSI;
  IStream *unaff_R14;
  ULONG aUStackX_20 [2];
  
  (**(code **)(in_RAX + 0x18))();
  pIVar1 = unaff_R14->lpVtbl;
  pcVar3 = ATL::CSimpleStringT<char,1>::GetBuffer
                     ((CSimpleStringT<char,1> *)(unaff_RSI + 0xf8),aUStackX_20[0]);
  (*pIVar1->Read)(unaff_R14,pcVar3,aUStackX_20[0],(ULONG *)0x0);
  ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)(unaff_RSI + 0xf8),-1);
  (*unaff_R14->lpVtbl->Read)(unaff_R14,aUStackX_20,4,(ULONG *)0x0);
  pIVar1 = unaff_R14->lpVtbl;
  pcVar3 = ATL::CSimpleStringT<char,1>::GetBuffer
                     ((CSimpleStringT<char,1> *)(unaff_RSI + 0x108),aUStackX_20[0]);
  (*pIVar1->Read)(unaff_R14,pcVar3,aUStackX_20[0],(ULONG *)0x0);
  ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)(unaff_RSI + 0x108),-1);
  HVar2 = FUN_180052810((longlong *)(unaff_RSI + 0x110),unaff_R14);
  FUN_180025a20((undefined8 *)&stack0x00000028);
  return HVar2;
}

/* ---- FUNC 000527C5 FUN_1800527c5 (48 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_1800527c5(void)

{
  undefined4 unaff_EBX;
  
  FUN_180025a20((undefined8 *)&stack0x00000028);
  return unaff_EBX;
}

/* ---- FUNC 00052800 FUN_180052800 (14 bytes) ---- */

void FUN_180052800(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180052807. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(longlong **)(param_1 + 8) + 0x148))();
  return;
}

/* ---- FUNC 00052810 FUN_180052810 (531 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HRESULT FUN_180052810(longlong *param_1,LPSTREAM param_2)

{
  ulonglong uVar1;
  HRESULT HVar2;
  ulonglong uVar3;
  undefined1 auStackY_4f8 [32];
  longlong *local_4c8;
  COleStreamFile local_4c0 [56];
  CArchive local_488 [112];
  undefined1 local_418 [1008];
  ulonglong local_28;
  
  local_28 = DAT_180077818 ^ (ulonglong)auStackY_4f8;
  if (param_1[2] != 0) {
    FUN_180002a20(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0xdbd);
    LogMessage(local_418,2,1);
  }
  if (param_1[7] != 0) {
    FUN_180002a20(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0xdbe);
    LogMessage(local_418,2,1);
  }
  if (param_1[0xc] != 0) {
    FUN_180002a20(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0xdbf);
    LogMessage(local_418,2,1);
  }
  COleStreamFile::COleStreamFile(local_4c0,(IStream *)0x0);
  COleStreamFile::Attach(local_4c0,param_2);
  CArchive::CArchive(local_488,(CFile *)local_4c0,1,0x1000,(void *)0x0);
  (**(code **)(*param_1 + 0x10))(param_1,local_488);
  (**(code **)(param_1[5] + 0x10))(param_1 + 5,local_488);
  CArchive::Close(local_488);
  COleStreamFile::Detach(local_4c0);
  CPtrArray::SetSize((CPtrArray *)(param_1 + 10),param_1[2],-1);
  local_4c8 = (longlong *)0x0;
  uVar3 = 0;
  uVar1 = param_1[2];
  if (uVar1 != 0) {
    do {
      HVar2 = FUN_18002b260(DAT_180079590,param_2,&local_4c8,0);
      if (HVar2 < 0) goto LAB_1800529df;
      if (((longlong)uVar3 < 0) || (param_1[0xc] <= (longlong)uVar3)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      *(longlong **)(param_1[0xb] + uVar3 * 8) = local_4c8;
      (**(code **)(*local_4c8 + 0x10))();
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  HVar2 = 0;
LAB_1800529df:
  CArchive::~CArchive(local_488);
  COleStreamFile::~COleStreamFile(local_4c0);
  return HVar2;
}

/* ---- FUNC 00052A30 FUN_180052a30 (978 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180052a30(CSimpleStringT<char,1> *param_1,LPSTREAM param_2)

{
  IStreamVtbl *pIVar1;
  longlong lVar2;
  uint uVar3;
  HRESULT HVar4;
  char *pv;
  void *pvVar5;
  BSTR pOVar6;
  int iVar7;
  longlong lVar8;
  longlong lVar9;
  undefined1 auStack_458 [32];
  ULONG local_438 [2];
  OLECHAR *local_430;
  undefined1 local_428 [1008];
  ulonglong local_38;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStack_458;
  if (*(longlong *)(param_1 + 0x20) != 0) {
    FUN_180002a20(local_428,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0x381);
    LogMessage(local_428,2,1);
  }
  if (*(longlong *)(param_1 + 0x28) != 0) {
    FUN_180002a20(local_428,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0x382);
    LogMessage(local_428,2,1);
  }
  local_438[0] = 0;
  (*param_2->lpVtbl->Read)(param_2,local_438,4,(ULONG *)0x0);
  pIVar1 = param_2->lpVtbl;
  pv = ATL::CSimpleStringT<char,1>::GetBuffer(param_1,local_438[0]);
  (*pIVar1->Read)(param_2,pv,local_438[0],(ULONG *)0x0);
  ATL::CSimpleStringT<char,1>::ReleaseBuffer(param_1,-1);
  (*param_2->lpVtbl->Read)(param_2,param_1 + 0x1c,4,(ULONG *)0x0);
  pvVar5 = malloc((longlong)*(int *)(param_1 + 0x1c) << 2);
  *(void **)(param_1 + 0x20) = pvVar5;
  (*param_2->lpVtbl->Read)(param_2,pvVar5,*(int *)(param_1 + 0x1c) << 2,(ULONG *)0x0);
  pvVar5 = malloc((longlong)*(int *)(param_1 + 0x1c) * 0x18);
  *(void **)(param_1 + 0x28) = pvVar5;
  memset(pvVar5,0,(longlong)*(int *)(param_1 + 0x1c) * 0x18);
  iVar7 = 0;
  if (0 < *(int *)(param_1 + 0x1c)) {
    lVar9 = 0;
    lVar8 = 0;
    do {
      switch((*(int *)(*(longlong *)(param_1 + 0x20) + lVar8) << 0x1c) >> 0x1c) {
      case 0:
      case 6:
      case 7:
        (*param_2->lpVtbl->Read)
                  (param_2,(void *)(*(longlong *)(param_1 + 0x28) + (longlong)iVar7 * 0x18),0x18,
                   (ULONG *)0x0);
        if (*(short *)(lVar9 + *(longlong *)(param_1 + 0x28)) == 8) {
          (*param_2->lpVtbl->Read)(param_2,local_438,4,(ULONG *)0x0);
          pOVar6 = SysAllocStringLen((OLECHAR *)0x0,(int)local_438[0] / 2);
          *(BSTR *)(lVar9 + 8 + *(longlong *)(param_1 + 0x28)) = pOVar6;
          (*param_2->lpVtbl->Read)
                    (param_2,*(void **)(lVar9 + 8 + *(longlong *)(param_1 + 0x28)),local_438[0],
                     (ULONG *)0x0);
        }
        break;
      case 1:
      case 2:
        local_430 = (OLECHAR *)0x0;
        *(undefined2 *)(lVar9 + *(longlong *)(param_1 + 0x28)) = 9;
        HVar4 = FUN_18002b260(DAT_180079590,param_2,
                              *(longlong *)(param_1 + 0x28) + ((longlong)iVar7 * 3 + 1) * 8,
                              (longlong)&local_430);
        if (HVar4 < 0) {
          return;
        }
        if ((HVar4 == 1) && (local_430 != (OLECHAR *)0x0)) {
          *(undefined2 *)(lVar9 + *(longlong *)(param_1 + 0x28)) = 8;
          pOVar6 = SysAllocString(local_430);
          *(BSTR *)(lVar9 + 8 + *(longlong *)(param_1 + 0x28)) = pOVar6;
          lVar2 = *(longlong *)(param_1 + 0x20);
          uVar3 = ((*(int *)(lVar2 + lVar8) << 0x1c) >> 0x1c) + 5;
          *(uint *)(lVar2 + lVar8) = (uVar3 ^ *(uint *)(lVar2 + lVar8)) & 0xfffffff0 ^ uVar3;
          CoTaskMemFree(local_430);
        }
        break;
      case 4:
      case 5:
        *(undefined2 *)(lVar9 + *(longlong *)(param_1 + 0x28)) = 0xd;
        HVar4 = OleLoadFromStream(param_2,(IID *)&DAT_180066d18,
                                  (LPVOID *)
                                  (*(longlong *)(param_1 + 0x28) + ((longlong)iVar7 * 3 + 1) * 8));
        if (HVar4 < 0) {
          return;
        }
      }
      iVar7 = iVar7 + 1;
      lVar8 = lVar8 + 4;
      lVar9 = lVar9 + 0x18;
    } while (iVar7 < *(int *)(param_1 + 0x1c));
  }
  (*param_2->lpVtbl->Read)(param_2,param_1 + 8,4,(ULONG *)0x0);
  (*param_2->lpVtbl->Read)(param_2,param_1 + 0xc,4,(ULONG *)0x0);
  (*param_2->lpVtbl->Read)(param_2,param_1 + 0x10,4,(ULONG *)0x0);
  (*param_2->lpVtbl->Read)(param_2,param_1 + 0x30,4,(ULONG *)0x0);
  (*param_2->lpVtbl->Read)(param_2,param_1 + 0x34,4,(ULONG *)0x0);
  FUN_18002b260(DAT_180079590,param_2,param_1 + 0x38,0);
  return;
}

/* ---- FUNC 00052E30 FUN_180052e30 (305 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180052e30(longlong param_1,undefined4 *param_2,undefined8 *param_3,longlong param_4)

{
  ulonglong uVar1;
  int iVar2;
  ulonglong uVar3;
  undefined1 auStack_448 [32];
  undefined1 local_428 [1008];
  ulonglong local_38;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStack_448;
  if (*(longlong *)(param_1 + 0x10) != *(longlong *)(param_1 + 0x38)) {
    FUN_180002a20(local_428,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0xd6a);
    LogMessage(local_428,2,1);
  }
  if (*(longlong *)(param_1 + 0x10) != *(longlong *)(param_1 + 0x60)) {
    FUN_180002a20(local_428,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0xd6b);
    LogMessage(local_428,2,1);
  }
  uVar1 = *(ulonglong *)(param_1 + 0x10);
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar3 < 0) || (*(longlong *)(param_1 + 0x38) <= (longlong)uVar3))
      goto LAB_180052f5c;
      iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         (*(longlong *)(param_1 + 0x30) + uVar3 * 8),(char *)*param_3);
      if (iVar2 == 0) {
        if (*(longlong *)(param_1 + 0x60) <= (longlong)uVar3) {
LAB_180052f5c:
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        if (*(longlong *)(*(longlong *)(param_1 + 0x58) + uVar3 * 8) == param_4) {
          if ((longlong)uVar3 < *(longlong *)(param_1 + 0x10)) {
            *param_2 = *(undefined4 *)(*(longlong *)(param_1 + 8) + uVar3 * 4);
            return 1;
          }
          goto LAB_180052f5c;
        }
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return 0;
}

/* ---- FUNC 00052F70 FUN_180052f70 (250 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_180052f70(int param_1)

{
  longlong lVar1;
  undefined1 auStack_78 [32];
  undefined8 *local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined4 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = DAT_180077818 ^ (ulonglong)auStack_78;
  local_40 = 0xffffffff;
  local_58 = (undefined8 *)0x0;
  local_18 = 0;
  local_50 = _DAT_1800648b0;
  uStack_48 = _UNK_1800648b8;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  lVar1 = HAGetElement(*(undefined8 *)(DAT_1800797f0 + 0x20),&local_50,&local_38,&local_58);
  if (lVar1 == 0) {
    if ((local_58 != (undefined8 *)0x0) && ((code *)*local_58 != (code *)0x0)) {
      (*(code *)*local_58)();
      return (undefined *)0x0;
    }
  }
  else {
    local_50 = CONCAT44(local_50._4_4_,param_1 + -1);
    local_58 = (undefined8 *)HAGetLabel(lVar1,0,param_1 + -1,&DAT_180079ee0);
    if (local_58 == (undefined8 *)0x0) {
      return &DAT_180079ee0;
    }
    if ((code *)*local_58 != (code *)0x0) {
      (*(code *)*local_58)(local_58);
    }
  }
  return (undefined *)0x0;
}

/* ---- FUNC 00053070 FUN_180053070 (185 bytes) ---- */

undefined8 FUN_180053070(longlong *param_1,longlong *param_2,longlong *param_3)

{
  *param_3 = 0;
  if (((((*param_2 != DAT_180066c58) || (param_2[1] != DAT_180066c60)) &&
       ((*param_2 != DAT_180066c78 || (param_2[1] != DAT_180066c80)))) &&
      ((*param_2 != DAT_180063440 || (param_2[1] != DAT_180063448)))) &&
     ((*param_2 != DAT_180063450 || (param_2[1] != DAT_180063458)))) {
    if ((*param_2 == DAT_180066ca8) && (param_2[1] == DAT_180066cb0)) {
      *param_3 = (longlong)(param_1 + 5);
      (**(code **)(*param_1 + 8))();
      return 0;
    }
    return 0x80004002;
  }
  *param_3 = (longlong)param_1;
  (**(code **)(*param_1 + 8))();
  return 0;
}

/* ---- FUNC 00053130 FUN_180053130 (255 bytes) ---- */

undefined8 FUN_180053130(longlong *param_1,longlong *param_2,longlong *param_3)

{
  *param_3 = 0;
  if ((((*param_2 == DAT_180066c58) && (param_2[1] == DAT_180066c60)) ||
      ((*param_2 == DAT_180066c78 && (param_2[1] == DAT_180066c80)))) ||
     (((*param_2 == DAT_180063540 && (param_2[1] == DAT_180063548)) ||
      ((*param_2 == DAT_180063550 && (param_2[1] == DAT_180063558)))))) {
    *param_3 = (longlong)param_1;
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((*param_2 == DAT_180066ca8) && (param_2[1] == DAT_180066cb0)) {
    *param_3 = (longlong)(param_1 + 5);
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if (((*param_2 != DAT_180066d08) || (param_2[1] != DAT_180066d10)) &&
     ((*param_2 != DAT_180066cf8 || (param_2[1] != DAT_180066d00)))) {
    return 0x80004002;
  }
  *param_3 = (longlong)(param_1 + 1);
  (**(code **)(*param_1 + 8))();
  return 0;
}

/* ---- FUNC 00053230 FUN_180053230 (404 bytes) ---- */

undefined8 FUN_180053230(longlong param_1,uint param_2)

{
  HRESULT HVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar2;
  BSTR pOVar3;
  ICreateErrorInfo *local_res8;
  LPCSTR local_res18;
  LPCSTR local_res20;
  IErrorInfo *local_18;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_10 [8];
  
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18);
  if (*(BSTR *)(param_1 + 0x58) != (BSTR)0x0) {
    SysFreeString(*(BSTR *)(param_1 + 0x58));
  }
  if (*(BSTR *)(param_1 + 0x50) != (BSTR)0x0) {
    SysFreeString(*(BSTR *)(param_1 + 0x50));
  }
  if (*(BSTR *)(param_1 + 0x60) != (BSTR)0x0) {
    SysFreeString(*(BSTR *)(param_1 + 0x60));
  }
  *(undefined8 *)(param_1 + 0x48) = 0;
  *(undefined8 *)(param_1 + 0x50) = 0;
  *(undefined8 *)(param_1 + 0x58) = 0;
  *(undefined8 *)(param_1 + 0x60) = 0;
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined8 *)(param_1 + 0x78) = 0;
  *(undefined8 *)(param_1 + 0x80) = 0;
  *(short *)(param_1 + 0x48) = (short)param_2;
  pCVar2 = FUN_180020fe0(local_10,param_2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_10);
  pCVar2 = FUN_180020fe0(local_10,1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18,
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_10);
  if (*(int *)(local_res20 + -0x10) != 0) {
    pOVar3 = FUN_1800019d0(local_res20);
    *(BSTR *)(param_1 + 0x58) = pOVar3;
  }
  if (*(int *)(local_res18 + -0x10) != 0) {
    pOVar3 = FUN_1800019d0(local_res18);
    *(BSTR *)(param_1 + 0x50) = pOVar3;
  }
  *(undefined4 *)(param_1 + 0x88) = 1;
  HVar1 = CreateErrorInfo(&local_res8);
  if (-1 < HVar1) {
    (*local_res8->lpVtbl->SetGUID)(local_res8,(GUID *)&DAT_180063440);
    if (*(LPOLESTR *)(param_1 + 0x50) != (LPOLESTR)0x0) {
      (*local_res8->lpVtbl->SetSource)(local_res8,*(LPOLESTR *)(param_1 + 0x50));
    }
    if (*(LPOLESTR *)(param_1 + 0x58) != (LPOLESTR)0x0) {
      (*local_res8->lpVtbl->SetDescription)(local_res8,*(LPOLESTR *)(param_1 + 0x58));
    }
    HVar1 = (*local_res8->lpVtbl->QueryInterface)(local_res8,(IID *)&DAT_180066c98,&local_18);
    if (-1 < HVar1) {
      SetErrorInfo(0,local_18);
      (*local_18->lpVtbl->Release)(local_18);
    }
    (*local_res8->lpVtbl->Release)(local_res8);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
  return 0x80020009;
}

/* ---- FUNC 000533D0 FUN_1800533d0 (50 bytes) ---- */

undefined8 FUN_1800533d0(longlong *param_1,undefined8 *param_2)

{
  OLECHAR *pOVar1;
  HRESULT HVar2;
  undefined8 uVar3;
  BSTR pOVar4;
  short sVar5;
  longlong lVar6;
  longlong lVar7;
  ICreateErrorInfo *local_res10;
  IErrorInfo *local_res18;
  
  if (param_2 == (undefined8 *)0x0) {
    uVar3 = (**(code **)(*param_1 + 0x2b8))(param_1,0x7d1);
    return uVar3;
  }
  if ((BSTR)param_1[0xb] != (BSTR)0x0) {
    SysFreeString((BSTR)param_1[0xb]);
  }
  if ((BSTR)param_1[10] != (BSTR)0x0) {
    SysFreeString((BSTR)param_1[10]);
  }
  if ((BSTR)param_1[0xc] != (BSTR)0x0) {
    SysFreeString((BSTR)param_1[0xc]);
  }
  param_1[9] = 0;
  param_1[10] = 0;
  lVar7 = -1;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  sVar5 = 0x7d1;
  if (*(short *)(param_2 + 1) != 0) {
    sVar5 = *(short *)(param_2 + 1);
  }
  *(short *)(param_1 + 9) = sVar5;
  pOVar1 = (OLECHAR *)param_2[2];
  if (pOVar1 == (OLECHAR *)0x0) {
    pOVar4 = SysAllocString(L"Unexpected Error");
  }
  else {
    lVar6 = -1;
    do {
      lVar6 = lVar6 + 1;
    } while (pOVar1[lVar6] != L'\0');
    pOVar4 = SysAllocStringLen(pOVar1,(UINT)lVar6);
  }
  param_1[0xb] = (longlong)pOVar4;
  pOVar1 = (OLECHAR *)param_2[3];
  if (pOVar1 == (OLECHAR *)0x0) {
    pOVar4 = SysAllocString(L"Happ.Application");
  }
  else {
    do {
      lVar7 = lVar7 + 1;
    } while (pOVar1[lVar7] != L'\0');
    pOVar4 = SysAllocStringLen(pOVar1,(UINT)lVar7);
  }
  param_1[10] = (longlong)pOVar4;
  *(undefined4 *)(param_1 + 0xd) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_1 + 0x11) = 1;
  if ((code *)*param_2 != (code *)0x0) {
    (*(code *)*param_2)(param_2);
  }
  HVar2 = CreateErrorInfo(&local_res10);
  if (-1 < HVar2) {
    (*local_res10->lpVtbl->SetGUID)(local_res10,(GUID *)&DAT_180063460);
    if ((LPOLESTR)param_1[10] != (LPOLESTR)0x0) {
      (*local_res10->lpVtbl->SetSource)(local_res10,(LPOLESTR)param_1[10]);
    }
    if ((LPOLESTR)param_1[0xb] != (LPOLESTR)0x0) {
      (*local_res10->lpVtbl->SetDescription)(local_res10,(LPOLESTR)param_1[0xb]);
    }
    HVar2 = (*local_res10->lpVtbl->QueryInterface)(local_res10,(IID *)&DAT_180066c98,&local_res18);
    if (-1 < HVar2) {
      SetErrorInfo(0,local_res18);
      (*local_res18->lpVtbl->Release)(local_res18);
    }
    (*local_res10->lpVtbl->Release)(local_res10);
  }
  return 0x80020009;
}

/* ---- FUNC 00053402 FUN_180053402 (225 bytes) ---- */

undefined8 FUN_180053402(BSTR param_1)

{
  OLECHAR *pOVar1;
  HRESULT HVar2;
  BSTR pOVar3;
  short sVar4;
  longlong lVar5;
  longlong unaff_RBX;
  undefined8 *unaff_RSI;
  longlong lVar6;
  ICreateErrorInfo *in_stack_00000038;
  IErrorInfo *in_stack_00000040;
  
  if (param_1 != (BSTR)0x0) {
    SysFreeString(param_1);
  }
  if (*(BSTR *)(unaff_RBX + 0x50) != (BSTR)0x0) {
    SysFreeString(*(BSTR *)(unaff_RBX + 0x50));
  }
  if (*(BSTR *)(unaff_RBX + 0x60) != (BSTR)0x0) {
    SysFreeString(*(BSTR *)(unaff_RBX + 0x60));
  }
  *(undefined8 *)(unaff_RBX + 0x48) = 0;
  *(undefined8 *)(unaff_RBX + 0x50) = 0;
  lVar6 = -1;
  *(undefined8 *)(unaff_RBX + 0x58) = 0;
  *(undefined8 *)(unaff_RBX + 0x60) = 0;
  *(undefined8 *)(unaff_RBX + 0x68) = 0;
  *(undefined8 *)(unaff_RBX + 0x70) = 0;
  *(undefined8 *)(unaff_RBX + 0x78) = 0;
  *(undefined8 *)(unaff_RBX + 0x80) = 0;
  sVar4 = 0x7d1;
  if (*(short *)(unaff_RSI + 1) != 0) {
    sVar4 = *(short *)(unaff_RSI + 1);
  }
  *(short *)(unaff_RBX + 0x48) = sVar4;
  pOVar1 = (OLECHAR *)unaff_RSI[2];
  if (pOVar1 == (OLECHAR *)0x0) {
    pOVar3 = SysAllocString(L"Unexpected Error");
  }
  else {
    lVar5 = -1;
    do {
      lVar5 = lVar5 + 1;
    } while (pOVar1[lVar5] != L'\0');
    pOVar3 = SysAllocStringLen(pOVar1,(UINT)lVar5);
  }
  *(BSTR *)(unaff_RBX + 0x58) = pOVar3;
  pOVar1 = (OLECHAR *)unaff_RSI[3];
  if (pOVar1 == (OLECHAR *)0x0) {
    pOVar3 = SysAllocString(L"Happ.Application");
  }
  else {
    do {
      lVar6 = lVar6 + 1;
    } while (pOVar1[lVar6] != L'\0');
    pOVar3 = SysAllocStringLen(pOVar1,(UINT)lVar6);
  }
  *(BSTR *)(unaff_RBX + 0x50) = pOVar3;
  *(undefined4 *)(unaff_RBX + 0x68) = *(undefined4 *)(unaff_RSI + 4);
  *(undefined4 *)(unaff_RBX + 0x88) = 1;
  if ((code *)*unaff_RSI != (code *)0x0) {
    (*(code *)*unaff_RSI)();
  }
  HVar2 = CreateErrorInfo(&stack0x00000038);
  if (-1 < HVar2) {
    (*in_stack_00000038->lpVtbl->SetGUID)(in_stack_00000038,(GUID *)&DAT_180063460);
    if (*(LPOLESTR *)(unaff_RBX + 0x50) != (LPOLESTR)0x0) {
      (*in_stack_00000038->lpVtbl->SetSource)(in_stack_00000038,*(LPOLESTR *)(unaff_RBX + 0x50));
    }
    if (*(LPOLESTR *)(unaff_RBX + 0x58) != (LPOLESTR)0x0) {
      (*in_stack_00000038->lpVtbl->SetDescription)
                (in_stack_00000038,*(LPOLESTR *)(unaff_RBX + 0x58));
    }
    HVar2 = (*in_stack_00000038->lpVtbl->QueryInterface)
                      (in_stack_00000038,(IID *)&DAT_180066c98,&stack0x00000040);
    if (-1 < HVar2) {
      SetErrorInfo(0,in_stack_00000040);
      (*in_stack_00000040->lpVtbl->Release)(in_stack_00000040);
    }
    (*in_stack_00000038->lpVtbl->Release)(in_stack_00000038);
  }
  return 0x80020009;
}

/* ---- FUNC 000534E3 FUN_1800534e3 (155 bytes) ---- */

undefined8 FUN_1800534e3(void)

{
  HRESULT HVar1;
  code *in_RAX;
  longlong unaff_RBX;
  ICreateErrorInfo *in_stack_00000038;
  IErrorInfo *in_stack_00000040;
  
  (*in_RAX)();
  HVar1 = CreateErrorInfo(&stack0x00000038);
  if (-1 < HVar1) {
    (*in_stack_00000038->lpVtbl->SetGUID)(in_stack_00000038,(GUID *)&DAT_180063460);
    if (*(LPOLESTR *)(unaff_RBX + 0x50) != (LPOLESTR)0x0) {
      (*in_stack_00000038->lpVtbl->SetSource)(in_stack_00000038,*(LPOLESTR *)(unaff_RBX + 0x50));
    }
    if (*(LPOLESTR *)(unaff_RBX + 0x58) != (LPOLESTR)0x0) {
      (*in_stack_00000038->lpVtbl->SetDescription)
                (in_stack_00000038,*(LPOLESTR *)(unaff_RBX + 0x58));
    }
    HVar1 = (*in_stack_00000038->lpVtbl->QueryInterface)
                      (in_stack_00000038,(IID *)&DAT_180066c98,&stack0x00000040);
    if (-1 < HVar1) {
      SetErrorInfo(0,in_stack_00000040);
      (*in_stack_00000040->lpVtbl->Release)(in_stack_00000040);
    }
    (*in_stack_00000038->lpVtbl->Release)(in_stack_00000038);
  }
  return 0x80020009;
}

/* ---- FUNC 00053580 FUN_180053580 (404 bytes) ---- */

undefined8 FUN_180053580(longlong param_1,uint param_2)

{
  HRESULT HVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar2;
  BSTR pOVar3;
  ICreateErrorInfo *local_res8;
  LPCSTR local_res18;
  LPCSTR local_res20;
  IErrorInfo *local_18;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_10 [8];
  
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18);
  if (*(BSTR *)(param_1 + 0x58) != (BSTR)0x0) {
    SysFreeString(*(BSTR *)(param_1 + 0x58));
  }
  if (*(BSTR *)(param_1 + 0x50) != (BSTR)0x0) {
    SysFreeString(*(BSTR *)(param_1 + 0x50));
  }
  if (*(BSTR *)(param_1 + 0x60) != (BSTR)0x0) {
    SysFreeString(*(BSTR *)(param_1 + 0x60));
  }
  *(undefined8 *)(param_1 + 0x48) = 0;
  *(undefined8 *)(param_1 + 0x50) = 0;
  *(undefined8 *)(param_1 + 0x58) = 0;
  *(undefined8 *)(param_1 + 0x60) = 0;
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined8 *)(param_1 + 0x78) = 0;
  *(undefined8 *)(param_1 + 0x80) = 0;
  *(short *)(param_1 + 0x48) = (short)param_2;
  pCVar2 = FUN_180020fe0(local_10,param_2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_10);
  pCVar2 = FUN_180020fe0(local_10,1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18,
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_10);
  if (*(int *)(local_res20 + -0x10) != 0) {
    pOVar3 = FUN_1800019d0(local_res20);
    *(BSTR *)(param_1 + 0x58) = pOVar3;
  }
  if (*(int *)(local_res18 + -0x10) != 0) {
    pOVar3 = FUN_1800019d0(local_res18);
    *(BSTR *)(param_1 + 0x50) = pOVar3;
  }
  *(undefined4 *)(param_1 + 0x88) = 1;
  HVar1 = CreateErrorInfo(&local_res8);
  if (-1 < HVar1) {
    (*local_res8->lpVtbl->SetGUID)(local_res8,(GUID *)&DAT_180063450);
    if (*(LPOLESTR *)(param_1 + 0x50) != (LPOLESTR)0x0) {
      (*local_res8->lpVtbl->SetSource)(local_res8,*(LPOLESTR *)(param_1 + 0x50));
    }
    if (*(LPOLESTR *)(param_1 + 0x58) != (LPOLESTR)0x0) {
      (*local_res8->lpVtbl->SetDescription)(local_res8,*(LPOLESTR *)(param_1 + 0x58));
    }
    HVar1 = (*local_res8->lpVtbl->QueryInterface)(local_res8,(IID *)&DAT_180066c98,&local_18);
    if (-1 < HVar1) {
      SetErrorInfo(0,local_18);
      (*local_18->lpVtbl->Release)(local_18);
    }
    (*local_res8->lpVtbl->Release)(local_res8);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
  return 0x80020009;
}

/* ---- FUNC 00053720 FUN_180053720 (50 bytes) ---- */

undefined8 FUN_180053720(longlong *param_1,undefined8 *param_2)

{
  OLECHAR *pOVar1;
  HRESULT HVar2;
  undefined8 uVar3;
  BSTR pOVar4;
  short sVar5;
  longlong lVar6;
  longlong lVar7;
  ICreateErrorInfo *local_res10;
  IErrorInfo *local_res18;
  
  if (param_2 == (undefined8 *)0x0) {
    uVar3 = (**(code **)(*param_1 + 0x138))(param_1,0x7d1);
    return uVar3;
  }
  if ((BSTR)param_1[0xb] != (BSTR)0x0) {
    SysFreeString((BSTR)param_1[0xb]);
  }
  if ((BSTR)param_1[10] != (BSTR)0x0) {
    SysFreeString((BSTR)param_1[10]);
  }
  if ((BSTR)param_1[0xc] != (BSTR)0x0) {
    SysFreeString((BSTR)param_1[0xc]);
  }
  param_1[9] = 0;
  param_1[10] = 0;
  lVar7 = -1;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  sVar5 = 0x7d1;
  if (*(short *)(param_2 + 1) != 0) {
    sVar5 = *(short *)(param_2 + 1);
  }
  *(short *)(param_1 + 9) = sVar5;
  pOVar1 = (OLECHAR *)param_2[2];
  if (pOVar1 == (OLECHAR *)0x0) {
    pOVar4 = SysAllocString(L"Unexpected Error");
  }
  else {
    lVar6 = -1;
    do {
      lVar6 = lVar6 + 1;
    } while (pOVar1[lVar6] != L'\0');
    pOVar4 = SysAllocStringLen(pOVar1,(UINT)lVar6);
  }
  param_1[0xb] = (longlong)pOVar4;
  pOVar1 = (OLECHAR *)param_2[3];
  if (pOVar1 == (OLECHAR *)0x0) {
    pOVar4 = SysAllocString(L"Happ.Application");
  }
  else {
    do {
      lVar7 = lVar7 + 1;
    } while (pOVar1[lVar7] != L'\0');
    pOVar4 = SysAllocStringLen(pOVar1,(UINT)lVar7);
  }
  param_1[10] = (longlong)pOVar4;
  *(undefined4 *)(param_1 + 0xd) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_1 + 0x11) = 1;
  if ((code *)*param_2 != (code *)0x0) {
    (*(code *)*param_2)(param_2);
  }
  HVar2 = CreateErrorInfo(&local_res10);
  if (-1 < HVar2) {
    (*local_res10->lpVtbl->SetGUID)(local_res10,(GUID *)&DAT_180063460);
    if ((LPOLESTR)param_1[10] != (LPOLESTR)0x0) {
      (*local_res10->lpVtbl->SetSource)(local_res10,(LPOLESTR)param_1[10]);
    }
    if ((LPOLESTR)param_1[0xb] != (LPOLESTR)0x0) {
      (*local_res10->lpVtbl->SetDescription)(local_res10,(LPOLESTR)param_1[0xb]);
    }
    HVar2 = (*local_res10->lpVtbl->QueryInterface)(local_res10,(IID *)&DAT_180066c98,&local_res18);
    if (-1 < HVar2) {
      SetErrorInfo(0,local_res18);
      (*local_res18->lpVtbl->Release)(local_res18);
    }
    (*local_res10->lpVtbl->Release)(local_res10);
  }
  return 0x80020009;
}

/* ---- FUNC 00053752 FUN_180053752 (225 bytes) ---- */

undefined8 FUN_180053752(BSTR param_1)

{
  OLECHAR *pOVar1;
  HRESULT HVar2;
  BSTR pOVar3;
  short sVar4;
  longlong lVar5;
  longlong unaff_RBX;
  undefined8 *unaff_RSI;
  longlong lVar6;
  ICreateErrorInfo *in_stack_00000038;
  IErrorInfo *in_stack_00000040;
  
  if (param_1 != (BSTR)0x0) {
    SysFreeString(param_1);
  }
  if (*(BSTR *)(unaff_RBX + 0x50) != (BSTR)0x0) {
    SysFreeString(*(BSTR *)(unaff_RBX + 0x50));
  }
  if (*(BSTR *)(unaff_RBX + 0x60) != (BSTR)0x0) {
    SysFreeString(*(BSTR *)(unaff_RBX + 0x60));
  }
  *(undefined8 *)(unaff_RBX + 0x48) = 0;
  *(undefined8 *)(unaff_RBX + 0x50) = 0;
  lVar6 = -1;
  *(undefined8 *)(unaff_RBX + 0x58) = 0;
  *(undefined8 *)(unaff_RBX + 0x60) = 0;
  *(undefined8 *)(unaff_RBX + 0x68) = 0;
  *(undefined8 *)(unaff_RBX + 0x70) = 0;
  *(undefined8 *)(unaff_RBX + 0x78) = 0;
  *(undefined8 *)(unaff_RBX + 0x80) = 0;
  sVar4 = 0x7d1;
  if (*(short *)(unaff_RSI + 1) != 0) {
    sVar4 = *(short *)(unaff_RSI + 1);
  }
  *(short *)(unaff_RBX + 0x48) = sVar4;
  pOVar1 = (OLECHAR *)unaff_RSI[2];
  if (pOVar1 == (OLECHAR *)0x0) {
    pOVar3 = SysAllocString(L"Unexpected Error");
  }
  else {
    lVar5 = -1;
    do {
      lVar5 = lVar5 + 1;
    } while (pOVar1[lVar5] != L'\0');
    pOVar3 = SysAllocStringLen(pOVar1,(UINT)lVar5);
  }
  *(BSTR *)(unaff_RBX + 0x58) = pOVar3;
  pOVar1 = (OLECHAR *)unaff_RSI[3];
  if (pOVar1 == (OLECHAR *)0x0) {
    pOVar3 = SysAllocString(L"Happ.Application");
  }
  else {
    do {
      lVar6 = lVar6 + 1;
    } while (pOVar1[lVar6] != L'\0');
    pOVar3 = SysAllocStringLen(pOVar1,(UINT)lVar6);
  }
  *(BSTR *)(unaff_RBX + 0x50) = pOVar3;
  *(undefined4 *)(unaff_RBX + 0x68) = *(undefined4 *)(unaff_RSI + 4);
  *(undefined4 *)(unaff_RBX + 0x88) = 1;
  if ((code *)*unaff_RSI != (code *)0x0) {
    (*(code *)*unaff_RSI)();
  }
  HVar2 = CreateErrorInfo(&stack0x00000038);
  if (-1 < HVar2) {
    (*in_stack_00000038->lpVtbl->SetGUID)(in_stack_00000038,(GUID *)&DAT_180063460);
    if (*(LPOLESTR *)(unaff_RBX + 0x50) != (LPOLESTR)0x0) {
      (*in_stack_00000038->lpVtbl->SetSource)(in_stack_00000038,*(LPOLESTR *)(unaff_RBX + 0x50));
    }
    if (*(LPOLESTR *)(unaff_RBX + 0x58) != (LPOLESTR)0x0) {
      (*in_stack_00000038->lpVtbl->SetDescription)
                (in_stack_00000038,*(LPOLESTR *)(unaff_RBX + 0x58));
    }
    HVar2 = (*in_stack_00000038->lpVtbl->QueryInterface)
                      (in_stack_00000038,(IID *)&DAT_180066c98,&stack0x00000040);
    if (-1 < HVar2) {
      SetErrorInfo(0,in_stack_00000040);
      (*in_stack_00000040->lpVtbl->Release)(in_stack_00000040);
    }
    (*in_stack_00000038->lpVtbl->Release)(in_stack_00000038);
  }
  return 0x80020009;
}

/* ---- FUNC 00053833 FUN_180053833 (155 bytes) ---- */

undefined8 FUN_180053833(void)

{
  HRESULT HVar1;
  code *in_RAX;
  longlong unaff_RBX;
  ICreateErrorInfo *in_stack_00000038;
  IErrorInfo *in_stack_00000040;
  
  (*in_RAX)();
  HVar1 = CreateErrorInfo(&stack0x00000038);
  if (-1 < HVar1) {
    (*in_stack_00000038->lpVtbl->SetGUID)(in_stack_00000038,(GUID *)&DAT_180063460);
    if (*(LPOLESTR *)(unaff_RBX + 0x50) != (LPOLESTR)0x0) {
      (*in_stack_00000038->lpVtbl->SetSource)(in_stack_00000038,*(LPOLESTR *)(unaff_RBX + 0x50));
    }
    if (*(LPOLESTR *)(unaff_RBX + 0x58) != (LPOLESTR)0x0) {
      (*in_stack_00000038->lpVtbl->SetDescription)
                (in_stack_00000038,*(LPOLESTR *)(unaff_RBX + 0x58));
    }
    HVar1 = (*in_stack_00000038->lpVtbl->QueryInterface)
                      (in_stack_00000038,(IID *)&DAT_180066c98,&stack0x00000040);
    if (-1 < HVar1) {
      SetErrorInfo(0,in_stack_00000040);
      (*in_stack_00000040->lpVtbl->Release)(in_stack_00000040);
    }
    (*in_stack_00000038->lpVtbl->Release)(in_stack_00000038);
  }
  return 0x80020009;
}

/* ---- FUNC 000538D0 FUN_1800538d0 (160 bytes) ---- */

void FUN_1800538d0(longlong param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  uVar1 = *(ulonglong *)(param_1 + 0xe0);
  uVar2 = 0;
  uVar3 = uVar2;
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar3 < 0) || (*(longlong *)(param_1 + 0xe0) <= (longlong)uVar3))
      goto LAB_18005396b;
      FUN_180053980(*(longlong *)(*(longlong *)(param_1 + 0xd8) + uVar3 * 8));
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  uVar1 = *(ulonglong *)(param_1 + 0x108);
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar2 < 0) || (*(longlong *)(param_1 + 0x108) <= (longlong)uVar2)) {
LAB_18005396b:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      FUN_180053980(*(longlong *)(*(longlong *)(param_1 + 0x100) + uVar2 * 8));
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar1);
  }
  return;
}

/* ---- FUNC 00053980 FUN_180053980 (243 bytes) ---- */

void FUN_180053980(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  VARIANTARG *pvarg;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  void *local_res8;
  undefined8 local_38 [2];
  
  FUN_1800255a0(local_38);
  uVar5 = 0;
  uVar6 = uVar5;
  uVar7 = uVar5;
  if (0 < *(int *)(param_1 + 0x1c)) {
    do {
      iVar2 = (*(int *)(uVar6 + *(longlong *)(param_1 + 0x20)) << 0x1c) >> 0x1c;
      if ((((iVar2 == 6) || (iVar2 == 7)) &&
          (pvarg = (VARIANTARG *)(*(longlong *)(param_1 + 0x28) + uVar7), (pvarg->n1).n2.vt == 8))
         && ((pvarg->n1).decVal.u2.Lo64 != 0)) {
        local_res8 = (void *)0x0;
        uVar4 = FUN_180026ff0(DAT_180079590,(wchar_t *)(pvarg->n1).decVal.u2,&local_res8);
        if ((int)uVar4 < 0) break;
        VariantClear(pvarg);
        (pvarg->n1).n2.vt = 9;
        (pvarg->n1).decVal.u2.Lo64 = (ULONGLONG)local_res8;
        lVar1 = *(longlong *)(param_1 + 0x20);
        uVar3 = ((*(int *)(lVar1 + uVar6) << 0x1c) >> 0x1c) - 5;
        *(uint *)(lVar1 + uVar6) = (uVar3 ^ *(uint *)(lVar1 + uVar6)) & 0xfffffff0 ^ uVar3;
      }
      uVar3 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar3;
      uVar6 = uVar6 + 4;
      uVar7 = uVar7 + 0x18;
    } while ((int)uVar3 < *(int *)(param_1 + 0x1c));
  }
  FUN_180025a20(local_38);
  return;
}

/* ---- FUNC 00053A80 FUN_180053a80 (46 bytes) ---- */

int FUN_180053a80(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 2) + -1;
  *(int *)(param_1 + 2) = iVar1;
  if (iVar1 == 0) {
    FUN_1800501c0(param_1);
    FUN_180025ad0(param_1);
    iVar1 = 0;
  }
  return iVar1;
}

/* ---- FUNC 00053AB0 FUN_180053ab0 (46 bytes) ---- */

int FUN_180053ab0(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4) + -1;
  *(int *)(param_1 + 4) = iVar1;
  if (iVar1 == 0) {
    FUN_1800503f0(param_1);
    FUN_180025ad0(param_1);
    iVar1 = 0;
  }
  return iVar1;
}

/* ---- FUNC 00053AE0 FUN_180053ae0 (46 bytes) ---- */

int FUN_180053ae0(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 1) + -1;
  *(int *)(param_1 + 1) = iVar1;
  if (iVar1 == 0) {
    FUN_180050530(param_1);
    FUN_180025ad0(param_1);
    iVar1 = 0;
  }
  return iVar1;
}

/* ---- FUNC 00053B10 FUN_180053b10 (375 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180053b10(CDWordArray *param_1,uint param_2)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined1 auStack_428 [32];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_180077818 ^ (ulonglong)auStack_428;
  if (*(longlong *)(param_1 + 0x10) != *(longlong *)(param_1 + 0x38)) {
    FUN_180002a20(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0xd7b);
    LogMessage(local_408,2,1);
  }
  if (*(longlong *)(param_1 + 0x10) != *(longlong *)(param_1 + 0x60)) {
    FUN_180002a20(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0xd7c);
    LogMessage(local_408,2,1);
  }
  uVar2 = *(ulonglong *)(param_1 + 0x10);
  uVar3 = 0;
  uVar4 = uVar3;
  if (uVar2 != 0) {
    do {
      if (((longlong)uVar4 < 0) || ((longlong)uVar2 <= (longlong)uVar4)) goto LAB_180053c82;
      if (*(uint *)(*(longlong *)(param_1 + 8) + uVar4 * 4) == param_2) {
        CDWordArray::RemoveAt(param_1,uVar4,1);
        CStringArray::RemoveAt((CStringArray *)(param_1 + 0x28),uVar4,1);
        CPtrArray::RemoveAt((CPtrArray *)(param_1 + 0x50),uVar4,1);
        break;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar2);
  }
  uVar2 = *(ulonglong *)(param_1 + 0x10);
  uVar4 = uVar2;
  if (uVar2 != 0) {
    do {
      if (((longlong)uVar3 < 0) || ((longlong)uVar4 <= (longlong)uVar3)) {
LAB_180053c82:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      uVar1 = *(uint *)(*(longlong *)(param_1 + 8) + uVar3 * 4);
      if (param_2 < uVar1) {
        *(uint *)(*(longlong *)(param_1 + 8) + uVar3 * 4) = uVar1 - 1;
        uVar4 = *(ulonglong *)(param_1 + 0x10);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar2);
  }
  return;
}

/* ---- FUNC 00053C90 FUN_180053c90 (55 bytes) ---- */

void FUN_180053c90(CDWordArray *param_1)

{
  CDWordArray::SetSize(param_1,0,-1);
  CStringArray::SetSize((CStringArray *)(param_1 + 0x28),0,-1);
  CPtrArray::SetSize((CPtrArray *)(param_1 + 0x50),0,-1);
  return;
}

/* ---- FUNC 00053CD0 FUN_180053cd0 (179 bytes) ---- */

undefined8 FUN_180053cd0(longlong param_1)

{
  ulonglong uVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar2;
  ulonglong uVar3;
  
  uVar3 = 0;
  uVar1 = *(ulonglong *)(*(longlong *)(param_1 + 0x90) + 0x108);
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar3 < 0) ||
         (*(longlong *)(*(longlong *)(param_1 + 0x90) + 0x108) <= (longlong)uVar3)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      pCVar2 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                (*(longlong *)(*(longlong *)(param_1 + 0x90) + 0x100) + uVar3 * 8);
      if (pCVar2 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        FUN_180050580(pCVar2);
        FUN_180025ad0(pCVar2);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  CPtrArray::SetSize((CPtrArray *)(*(longlong *)(param_1 + 0x90) + 0xf8),0,-1);
  FUN_180053c90((CDWordArray *)(param_1 + 0x110));
  return 0;
}

/* ---- FUNC 00053D90 FUN_180053d90 (167 bytes) ---- */

undefined8 FUN_180053d90(longlong param_1)

{
  ulonglong uVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar2;
  ulonglong uVar3;
  
  uVar3 = 0;
  uVar1 = *(ulonglong *)(*(longlong *)(param_1 + 0x90) + 0xe0);
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar3 < 0) ||
         (*(longlong *)(*(longlong *)(param_1 + 0x90) + 0xe0) <= (longlong)uVar3)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      pCVar2 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                (*(longlong *)(*(longlong *)(param_1 + 0x90) + 0xd8) + uVar3 * 8);
      if (pCVar2 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        FUN_180050580(pCVar2);
        FUN_180025ad0(pCVar2);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  CPtrArray::SetSize((CPtrArray *)(*(longlong *)(param_1 + 0x90) + 0xd0),0,-1);
  return 0;
}

/* ---- FUNC 00053E40 FUN_180053e40 (154 bytes) ---- */

undefined8 FUN_180053e40(longlong param_1)

{
  ulonglong uVar1;
  void *pvVar2;
  ulonglong uVar3;
  
  uVar1 = *(ulonglong *)(param_1 + 0x130);
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar3 < 0) || (*(longlong *)(param_1 + 0x130) <= (longlong)uVar3)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      pvVar2 = *(void **)(*(longlong *)(param_1 + 0x128) + uVar3 * 8);
      if (pvVar2 != (void *)0x0) {
        SysFreeString(*(BSTR *)((longlong)pvVar2 + 0x10));
        SysFreeString(*(BSTR *)((longlong)pvVar2 + 0x20));
        FUN_180025ad0(pvVar2);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  CPtrArray::SetSize((CPtrArray *)(param_1 + 0x120),0,-1);
  return 0;
}

/* ---- FUNC 00053EE0 FUN_180053ee0 (138 bytes) ---- */

void FUN_180053ee0(longlong param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  void *_Src;
  void *_Dst;
  size_t _Size;
  longlong lVar2;
  int *piVar3;
  
  lVar1 = param_2 + param_3;
  if ((((-1 < param_2) && (-1 < param_3)) && (lVar1 <= *(longlong *)(param_1 + 0x10))) &&
     ((param_2 <= lVar1 && (param_3 <= lVar1)))) {
    lVar2 = *(longlong *)(param_1 + 0x10) - lVar1;
    if (lVar2 != 0) {
      _Size = lVar2 * 4;
      _Src = (void *)(*(longlong *)(param_1 + 8) + lVar1 * 4);
      _Dst = (void *)(*(longlong *)(param_1 + 8) + param_2 * 4);
      if (_Size != 0) {
        if ((_Dst == (void *)0x0) || (_Src == (void *)0x0)) {
          piVar3 = _errno();
          *piVar3 = 0x16;
          _invalid_parameter_noinfo();
          goto LAB_180053f65;
        }
        memmove(_Dst,_Src,_Size);
      }
    }
    *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) - param_3;
    return;
  }
LAB_180053f65:
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00053F70 FUN_180053f70 (240 bytes) ---- */

undefined8 FUN_180053f70(longlong *param_1,longlong param_2,wchar_t *param_3)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  longlong lVar4;
  uint local_res8 [2];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res20 [8];
  
  puVar2 = (undefined8 *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
           CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20,param_3);
  uVar3 = FUN_180052e30((longlong)(param_1 + 0x22),local_res8,puVar2,param_2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20);
  if ((int)uVar3 == 0) {
                    /* WARNING: Could not recover jumptable at 0x000180054054. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (**(code **)(*param_1 + 0x138))(param_1,0x7d1);
    return uVar3;
  }
  lVar4 = (longlong)(int)local_res8[0];
  if ((-1 < lVar4) && (lVar4 < *(longlong *)(param_1[0x12] + 0x108))) {
    pCVar1 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
              (*(longlong *)(param_1[0x12] + 0x100) + lVar4 * 8);
    if (pCVar1 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
      FUN_180050580(pCVar1);
      FUN_180025ad0(pCVar1);
    }
    CPtrArray::RemoveAt((CPtrArray *)(param_1[0x12] + 0xf8),lVar4,1);
    FUN_180053b10((CDWordArray *)(param_1 + 0x22),local_res8[0]);
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00053FE2 FUN_180053fe2 (95 bytes) ---- */

undefined8 FUN_180053fe2(void)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  longlong in_RAX;
  longlong unaff_RBX;
  longlong unaff_RDI;
  uint in_stack_00000040;
  
  pCVar1 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
            (in_RAX + unaff_RBX * 8);
  if (pCVar1 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
    FUN_180050580(pCVar1);
    FUN_180025ad0(pCVar1);
  }
  CPtrArray::RemoveAt((CPtrArray *)(*(longlong *)(unaff_RDI + 0x90) + 0xf8),unaff_RBX,1);
  FUN_180053b10((CDWordArray *)(unaff_RDI + 0x110),in_stack_00000040);
  return 0;
}

/* ---- FUNC 00054041 FUN_180054041 (26 bytes) ---- */

void FUN_180054041(void)

{
  longlong *unaff_RDI;
  
                    /* WARNING: Could not recover jumptable at 0x000180054054. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*unaff_RDI + 0x138))();
  return;
}

/* ---- FUNC 00054070 FUN_180054070 (44 bytes) ---- */

undefined8 FUN_180054070(longlong param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  longlong lVar2;
  
  lVar2 = (longlong)param_4;
  if ((-1 < param_4) && (lVar2 < *(longlong *)(*(longlong *)(param_1 + 0x90) + 0xe0))) {
    pCVar1 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
              (*(longlong *)(*(longlong *)(param_1 + 0x90) + 0xd8) + lVar2 * 8);
    if (pCVar1 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
      FUN_180050580(pCVar1);
      FUN_180025ad0(pCVar1);
    }
    CPtrArray::RemoveAt((CPtrArray *)(*(longlong *)(param_1 + 0x90) + 0xd0),lVar2,1);
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 0005409C FUN_18005409c (81 bytes) ---- */

undefined8 FUN_18005409c(void)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  longlong in_RAX;
  longlong unaff_RBX;
  longlong unaff_RSI;
  
  pCVar1 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
            (in_RAX + unaff_RBX * 8);
  if (pCVar1 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
    FUN_180050580(pCVar1);
    FUN_180025ad0(pCVar1);
  }
  CPtrArray::RemoveAt((CPtrArray *)(*(longlong *)(unaff_RSI + 0x90) + 0xd0),unaff_RBX,1);
  return 0;
}

/* ---- FUNC 000540ED AfxThrowInvalidArgException (5 bytes) ---- */

void __cdecl AfxThrowInvalidArgException(void)

{
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00054100 FUN_180054100 (82 bytes) ---- */

ulonglong FUN_180054100(longlong param_1,IStream *param_2)

{
  void *pv;
  UINT UVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong lVar4;
  ULONG local_res8 [2];
  longlong local_res18;
  
  uVar2 = FUN_18002ec50(DAT_180079590,param_2,*(longlong *)(param_1 + 0x18));
  if ((-1 < (int)uVar2) &&
     (uVar2 = FUN_18002ec50(DAT_180079590,param_2,*(longlong *)(param_1 + 0x20)), -1 < (int)uVar2))
  {
    local_res18 = (longlong)(*(int *)(*(longlong *)(param_1 + 0x90) + -0x10) + 1);
    (*param_2->lpVtbl->Write)(param_2,&local_res18,4,(ULONG *)0x0);
    (*param_2->lpVtbl->Write)(param_2,*(void **)(param_1 + 0x90),(ULONG)local_res18,(ULONG *)0x0);
    local_res18 = *(longlong *)(param_1 + 0xa8);
    (*param_2->lpVtbl->Write)(param_2,&local_res18,4,(ULONG *)0x0);
    lVar4 = 0;
    lVar3 = lVar4;
    if (0 < local_res18) {
      do {
        if ((lVar3 < 0) || (*(longlong *)(param_1 + 0xa8) <= lVar3)) {
LAB_1800545d4:
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        local_res8[0] =
             *(int *)(*(longlong *)(*(longlong *)(param_1 + 0xa0) + lVar3 * 8) + -0x10) + 1;
        (*param_2->lpVtbl->Write)(param_2,local_res8,4,(ULONG *)0x0);
        if (*(longlong *)(param_1 + 0xa8) <= lVar3) goto LAB_1800545d4;
        (*param_2->lpVtbl->Write)
                  (param_2,*(void **)(*(longlong *)(param_1 + 0xa0) + lVar3 * 8),local_res8[0],
                   (ULONG *)0x0);
        lVar3 = lVar3 + 1;
      } while (lVar3 < local_res18);
    }
    local_res18 = (longlong)(*(int *)(*(longlong *)(param_1 + 0xc0) + -0x10) + 1);
    (*param_2->lpVtbl->Write)(param_2,&local_res18,4,(ULONG *)0x0);
    (*param_2->lpVtbl->Write)(param_2,*(void **)(param_1 + 0xc0),(ULONG)local_res18,(ULONG *)0x0);
    (*param_2->lpVtbl->Write)(param_2,(void *)(param_1 + 200),4,(ULONG *)0x0);
    local_res18 = *(longlong *)(param_1 + 0xe0);
    (*param_2->lpVtbl->Write)(param_2,&local_res18,4,(ULONG *)0x0);
    lVar3 = lVar4;
    if (0 < local_res18) {
      do {
        if ((lVar3 < 0) || (*(longlong *)(param_1 + 0xe0) <= lVar3))
        goto MFC140_DLL_AfxThrowInvalidArgException;
        uVar2 = FUN_1800548a0(*(longlong **)(*(longlong *)(param_1 + 0xd8) + lVar3 * 8),param_2);
        if ((int)uVar2 < 0) {
          return uVar2;
        }
        lVar3 = lVar3 + 1;
      } while (lVar3 < local_res18);
    }
    local_res18 = *(longlong *)(param_1 + 0x108);
    (*param_2->lpVtbl->Write)(param_2,&local_res18,4,(ULONG *)0x0);
    lVar3 = lVar4;
    if (0 < local_res18) {
      do {
        if ((lVar3 < 0) || (*(longlong *)(param_1 + 0x108) <= lVar3))
        goto MFC140_DLL_AfxThrowInvalidArgException;
        uVar2 = FUN_1800548a0(*(longlong **)(*(longlong *)(param_1 + 0x100) + lVar3 * 8),param_2);
        if ((int)uVar2 < 0) {
          return uVar2;
        }
        lVar3 = lVar3 + 1;
      } while (lVar3 < local_res18);
    }
    local_res18 = *(longlong *)(param_1 + 0x130);
    (*param_2->lpVtbl->Write)(param_2,&local_res18,4,(ULONG *)0x0);
    if (0 < local_res18) {
      do {
        if ((lVar4 < 0) || (*(longlong *)(param_1 + 0x130) <= lVar4)) {
MFC140_DLL_AfxThrowInvalidArgException:
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        pv = *(void **)(*(longlong *)(param_1 + 0x128) + lVar4 * 8);
        UVar1 = SysStringLen(*(BSTR *)((longlong)pv + 0x10));
        local_res8[0] = UVar1 * 2;
        (*param_2->lpVtbl->Write)(param_2,local_res8,4,(ULONG *)0x0);
        (*param_2->lpVtbl->Write)
                  (param_2,*(void **)((longlong)pv + 0x10),local_res8[0],(ULONG *)0x0);
        (*param_2->lpVtbl->Write)(param_2,pv,8,(ULONG *)0x0);
        (*param_2->lpVtbl->Write)(param_2,(void *)((longlong)pv + 8),8,(ULONG *)0x0);
        (*param_2->lpVtbl->Write)(param_2,(void *)((longlong)pv + 0x18),4,(ULONG *)0x0);
        UVar1 = SysStringLen(*(BSTR *)((longlong)pv + 0x20));
        local_res8[0] = UVar1 * 2;
        (*param_2->lpVtbl->Write)(param_2,local_res8,4,(ULONG *)0x0);
        (*param_2->lpVtbl->Write)
                  (param_2,*(void **)((longlong)pv + 0x20),local_res8[0],(ULONG *)0x0);
        (*param_2->lpVtbl->Write)(param_2,(void *)((longlong)pv + 0x28),2,(ULONG *)0x0);
        (*param_2->lpVtbl->Write)(param_2,(void *)((longlong)pv + 0x2a),2,(ULONG *)0x0);
        (*param_2->lpVtbl->Write)(param_2,(void *)((longlong)pv + 0x2c),2,(ULONG *)0x0);
        lVar4 = lVar4 + 1;
      } while (lVar4 < local_res18);
    }
    (*param_2->lpVtbl->Write)(param_2,(void *)(param_1 + 0x148),4,(ULONG *)0x0);
    (*param_2->lpVtbl->Write)(param_2,(void *)(param_1 + 0x14c),4,(ULONG *)0x0);
    (*param_2->lpVtbl->Write)(param_2,(void *)(param_1 + 0x150),4,(ULONG *)0x0);
    (*param_2->lpVtbl->Write)(param_2,(void *)(param_1 + 0x154),4,(ULONG *)0x0);
    (*param_2->lpVtbl->Write)(param_2,(void *)(param_1 + 0x158),4,(ULONG *)0x0);
    (*param_2->lpVtbl->Write)(param_2,(void *)(param_1 + 0x15c),4,(ULONG *)0x0);
    (*param_2->lpVtbl->Write)(param_2,(void *)(param_1 + 0x160),4,(ULONG *)0x0);
    (*param_2->lpVtbl->Write)(param_2,(void *)(param_1 + 0x164),2,(ULONG *)0x0);
    (*param_2->lpVtbl->Write)(param_2,(void *)(param_1 + 0x166),2,(ULONG *)0x0);
    (*param_2->lpVtbl->Write)(param_2,(void *)(param_1 + 0x16c),4,(ULONG *)0x0);
    (*param_2->lpVtbl->Write)(param_2,(void *)(param_1 + 0x168),2,(ULONG *)0x0);
    (*param_2->lpVtbl->Write)(param_2,(void *)(param_1 + 0x170),4,(ULONG *)0x0);
    (*param_2->lpVtbl->Write)(param_2,(void *)(param_1 + 0x174),4,(ULONG *)0x0);
    (*param_2->lpVtbl->Write)(param_2,(void *)(param_1 + 0x178),4,(ULONG *)0x0);
    uVar2 = 0;
  }
  return uVar2;
}

/* ---- FUNC 00054152 FUN_180054152 (1159 bytes) ---- */

undefined8 FUN_180054152(undefined8 param_1,void *param_2,undefined8 param_3,ULONG *param_4)

{
  void *pv;
  UINT UVar1;
  longlong in_RAX;
  undefined8 uVar2;
  IStream *unaff_RBX;
  longlong unaff_RBP;
  longlong unaff_RSI;
  longlong lVar3;
  longlong lVar4;
  
  *(longlong *)(unaff_RBP + 0x30) = (longlong)(*(int *)(in_RAX + -0x10) + 1);
  (*unaff_RBX->lpVtbl->Write)(unaff_RBX,param_2,(int)param_4 + 4,param_4);
  (*unaff_RBX->lpVtbl->Write)
            (unaff_RBX,*(void **)(unaff_RSI + 0x90),*(ULONG *)(unaff_RBP + 0x30),(ULONG *)0x0);
  *(undefined8 *)(unaff_RBP + 0x30) = *(undefined8 *)(unaff_RSI + 0xa8);
  (*unaff_RBX->lpVtbl->Write)(unaff_RBX,(void *)(unaff_RBP + 0x30),4,(ULONG *)0x0);
  lVar4 = 0;
  lVar3 = lVar4;
  if (0 < *(longlong *)(unaff_RBP + 0x30)) {
    do {
      if ((lVar3 < 0) || (*(longlong *)(unaff_RSI + 0xa8) <= lVar3)) {
LAB_1800545d4:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      *(int *)(unaff_RBP + 0x20) =
           *(int *)(*(longlong *)(*(longlong *)(unaff_RSI + 0xa0) + lVar3 * 8) + -0x10) + 1;
      (*unaff_RBX->lpVtbl->Write)(unaff_RBX,(void *)(unaff_RBP + 0x20),4,(ULONG *)0x0);
      if (*(longlong *)(unaff_RSI + 0xa8) <= lVar3) goto LAB_1800545d4;
      (*unaff_RBX->lpVtbl->Write)
                (unaff_RBX,*(void **)(*(longlong *)(unaff_RSI + 0xa0) + lVar3 * 8),
                 *(ULONG *)(unaff_RBP + 0x20),(ULONG *)0x0);
      lVar3 = lVar3 + 1;
    } while (lVar3 < *(longlong *)(unaff_RBP + 0x30));
  }
  *(longlong *)(unaff_RBP + 0x30) =
       (longlong)(*(int *)(*(longlong *)(unaff_RSI + 0xc0) + -0x10) + 1);
  (*unaff_RBX->lpVtbl->Write)(unaff_RBX,(void *)(unaff_RBP + 0x30),4,(ULONG *)0x0);
  (*unaff_RBX->lpVtbl->Write)
            (unaff_RBX,*(void **)(unaff_RSI + 0xc0),*(ULONG *)(unaff_RBP + 0x30),(ULONG *)0x0);
  (*unaff_RBX->lpVtbl->Write)(unaff_RBX,(void *)(unaff_RSI + 200),4,(ULONG *)0x0);
  *(undefined8 *)(unaff_RBP + 0x30) = *(undefined8 *)(unaff_RSI + 0xe0);
  (*unaff_RBX->lpVtbl->Write)(unaff_RBX,(void *)(unaff_RBP + 0x30),4,(ULONG *)0x0);
  lVar3 = lVar4;
  if (0 < *(longlong *)(unaff_RBP + 0x30)) {
    do {
      if ((lVar3 < 0) || (*(longlong *)(unaff_RSI + 0xe0) <= lVar3))
      goto MFC140_DLL_AfxThrowInvalidArgException;
      uVar2 = FUN_1800548a0(*(longlong **)(*(longlong *)(unaff_RSI + 0xd8) + lVar3 * 8),unaff_RBX);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      lVar3 = lVar3 + 1;
    } while (lVar3 < *(longlong *)(unaff_RBP + 0x30));
  }
  *(undefined8 *)(unaff_RBP + 0x30) = *(undefined8 *)(unaff_RSI + 0x108);
  (*unaff_RBX->lpVtbl->Write)(unaff_RBX,(void *)(unaff_RBP + 0x30),4,(ULONG *)0x0);
  lVar3 = lVar4;
  if (0 < *(longlong *)(unaff_RBP + 0x30)) {
    do {
      if ((lVar3 < 0) || (*(longlong *)(unaff_RSI + 0x108) <= lVar3))
      goto MFC140_DLL_AfxThrowInvalidArgException;
      uVar2 = FUN_1800548a0(*(longlong **)(*(longlong *)(unaff_RSI + 0x100) + lVar3 * 8),unaff_RBX);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      lVar3 = lVar3 + 1;
    } while (lVar3 < *(longlong *)(unaff_RBP + 0x30));
  }
  *(undefined8 *)(unaff_RBP + 0x30) = *(undefined8 *)(unaff_RSI + 0x130);
  (*unaff_RBX->lpVtbl->Write)(unaff_RBX,(void *)(unaff_RBP + 0x30),4,(ULONG *)0x0);
  if (0 < *(longlong *)(unaff_RBP + 0x30)) {
    do {
      if ((lVar4 < 0) || (*(longlong *)(unaff_RSI + 0x130) <= lVar4)) {
MFC140_DLL_AfxThrowInvalidArgException:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      pv = *(void **)(*(longlong *)(unaff_RSI + 0x128) + lVar4 * 8);
      UVar1 = SysStringLen(*(BSTR *)((longlong)pv + 0x10));
      *(UINT *)(unaff_RBP + 0x20) = UVar1 * 2;
      (*unaff_RBX->lpVtbl->Write)(unaff_RBX,(void *)(unaff_RBP + 0x20),4,(ULONG *)0x0);
      (*unaff_RBX->lpVtbl->Write)
                (unaff_RBX,*(void **)((longlong)pv + 0x10),*(ULONG *)(unaff_RBP + 0x20),(ULONG *)0x0
                );
      (*unaff_RBX->lpVtbl->Write)(unaff_RBX,pv,8,(ULONG *)0x0);
      (*unaff_RBX->lpVtbl->Write)(unaff_RBX,(void *)((longlong)pv + 8),8,(ULONG *)0x0);
      (*unaff_RBX->lpVtbl->Write)(unaff_RBX,(void *)((longlong)pv + 0x18),4,(ULONG *)0x0);
      UVar1 = SysStringLen(*(BSTR *)((longlong)pv + 0x20));
      *(UINT *)(unaff_RBP + 0x20) = UVar1 * 2;
      (*unaff_RBX->lpVtbl->Write)(unaff_RBX,(void *)(unaff_RBP + 0x20),4,(ULONG *)0x0);
      (*unaff_RBX->lpVtbl->Write)
                (unaff_RBX,*(void **)((longlong)pv + 0x20),*(ULONG *)(unaff_RBP + 0x20),(ULONG *)0x0
                );
      (*unaff_RBX->lpVtbl->Write)(unaff_RBX,(void *)((longlong)pv + 0x28),2,(ULONG *)0x0);
      (*unaff_RBX->lpVtbl->Write)(unaff_RBX,(void *)((longlong)pv + 0x2a),2,(ULONG *)0x0);
      (*unaff_RBX->lpVtbl->Write)(unaff_RBX,(void *)((longlong)pv + 0x2c),2,(ULONG *)0x0);
      lVar4 = lVar4 + 1;
    } while (lVar4 < *(longlong *)(unaff_RBP + 0x30));
  }
  (*unaff_RBX->lpVtbl->Write)(unaff_RBX,(void *)(unaff_RSI + 0x148),4,(ULONG *)0x0);
  (*unaff_RBX->lpVtbl->Write)(unaff_RBX,(void *)(unaff_RSI + 0x14c),4,(ULONG *)0x0);
  (*unaff_RBX->lpVtbl->Write)(unaff_RBX,(void *)(unaff_RSI + 0x150),4,(ULONG *)0x0);
  (*unaff_RBX->lpVtbl->Write)(unaff_RBX,(void *)(unaff_RSI + 0x154),4,(ULONG *)0x0);
  (*unaff_RBX->lpVtbl->Write)(unaff_RBX,(void *)(unaff_RSI + 0x158),4,(ULONG *)0x0);
  (*unaff_RBX->lpVtbl->Write)(unaff_RBX,(void *)(unaff_RSI + 0x15c),4,(ULONG *)0x0);
  (*unaff_RBX->lpVtbl->Write)(unaff_RBX,(void *)(unaff_RSI + 0x160),4,(ULONG *)0x0);
  (*unaff_RBX->lpVtbl->Write)(unaff_RBX,(void *)(unaff_RSI + 0x164),2,(ULONG *)0x0);
  (*unaff_RBX->lpVtbl->Write)(unaff_RBX,(void *)(unaff_RSI + 0x166),2,(ULONG *)0x0);
  (*unaff_RBX->lpVtbl->Write)(unaff_RBX,(void *)(unaff_RSI + 0x16c),4,(ULONG *)0x0);
  (*unaff_RBX->lpVtbl->Write)(unaff_RBX,(void *)(unaff_RSI + 0x168),2,(ULONG *)0x0);
  (*unaff_RBX->lpVtbl->Write)(unaff_RBX,(void *)(unaff_RSI + 0x170),4,(ULONG *)0x0);
  (*unaff_RBX->lpVtbl->Write)(unaff_RBX,(void *)(unaff_RSI + 0x174),4,(ULONG *)0x0);
  (*unaff_RBX->lpVtbl->Write)(unaff_RBX,(void *)(unaff_RSI + 0x178),4,(ULONG *)0x0);
  return 0;
}

/* ---- FUNC 000545C6 FUN_1800545c6 (8 bytes) ---- */

void FUN_1800545c6(void)

{
  return;
}

/* ---- FUNC 000545CE AfxThrowInvalidArgException (5 bytes) ---- */

void __cdecl AfxThrowInvalidArgException(void)

{
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 000545E0 FUN_1800545e0 (246 bytes) ---- */

ulonglong FUN_1800545e0(longlong param_1,IStream *param_2)

{
  ulonglong uVar1;
  ULONG local_res8 [2];
  undefined8 local_18 [2];
  
  FUN_1800255a0(local_18);
  (*param_2->lpVtbl->Write)(param_2,(void *)(param_1 + 0x8c),4,(ULONG *)0x0);
  uVar1 = FUN_180054100(*(longlong *)(param_1 + 0x90),param_2);
  if (-1 < (int)uVar1) {
    local_res8[0] = *(int *)(*(longlong *)(param_1 + 0xf8) + -0x10) + 1;
    (*param_2->lpVtbl->Write)(param_2,local_res8,4,(ULONG *)0x0);
    (*param_2->lpVtbl->Write)(param_2,*(void **)(param_1 + 0xf8),local_res8[0],(ULONG *)0x0);
    local_res8[0] = *(int *)(*(longlong *)(param_1 + 0x108) + -0x10) + 1;
    (*param_2->lpVtbl->Write)(param_2,local_res8,4,(ULONG *)0x0);
    (*param_2->lpVtbl->Write)(param_2,*(void **)(param_1 + 0x108),local_res8[0],(ULONG *)0x0);
    uVar1 = FUN_1800546f0((longlong *)(param_1 + 0x110),param_2);
  }
  FUN_180025a20(local_18);
  return uVar1 & 0xffffffff;
}

/* ---- FUNC 000546E0 FUN_1800546e0 (14 bytes) ---- */

void FUN_1800546e0(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0001800546e7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(longlong **)(param_1 + 8) + 0x150))();
  return;
}

/* ---- FUNC 000546F0 FUN_1800546f0 (422 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_1800546f0(longlong *param_1,IStream *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined1 auStackY_4f8 [32];
  COleStreamFile local_4c8 [64];
  CArchive local_488 [112];
  undefined1 local_418 [1008];
  ulonglong local_28;
  
  local_28 = DAT_180077818 ^ (ulonglong)auStackY_4f8;
  if (param_1[2] != param_1[7]) {
    FUN_180002a20(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0xda6);
    LogMessage(local_418);
  }
  if (param_1[2] != param_1[0xc]) {
    FUN_180002a20(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0xda7);
    LogMessage(local_418);
  }
  COleStreamFile::COleStreamFile(local_4c8,(IStream *)0x0);
  COleStreamFile::Attach(local_4c8,param_2);
  CArchive::CArchive(local_488,(CFile *)local_4c8,0,0x1000,(void *)0x0);
  (**(code **)(*param_1 + 0x10))(param_1,local_488);
  (**(code **)(param_1[5] + 0x10))(param_1 + 5,local_488);
  CArchive::Close(local_488);
  COleStreamFile::Detach(local_4c8);
  uVar3 = 0;
  uVar1 = param_1[0xc];
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar3 < 0) || (param_1[0xc] <= (longlong)uVar3)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      uVar2 = FUN_18002ec50(DAT_180079590,param_2,*(longlong *)(param_1[0xb] + uVar3 * 8));
      uVar4 = uVar2 & 0xffffffff;
      if ((int)uVar2 < 0) goto LAB_180054852;
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  uVar4 = 0;
LAB_180054852:
  CArchive::~CArchive(local_488);
  COleStreamFile::~COleStreamFile(local_4c8);
  return uVar4;
}

/* ---- FUNC 000548A0 FUN_1800548a0 (758 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1800548a0(longlong *param_1,IStream *param_2)

{
  void *pv;
  _func_5371 *p_Var1;
  UINT UVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  int iVar6;
  longlong lVar7;
  undefined1 auStack_458 [32];
  ULONG local_438 [4];
  undefined1 local_428 [1008];
  ulonglong local_38;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStack_458;
  local_438[0] = *(int *)(*param_1 + -0x10) + 1;
  (*param_2->lpVtbl->Write)(param_2,local_438,4,(ULONG *)0x0);
  (*param_2->lpVtbl->Write)(param_2,(void *)*param_1,local_438[0],(ULONG *)0x0);
  (*param_2->lpVtbl->Write)(param_2,(void *)((longlong)param_1 + 0x1c),4,(ULONG *)0x0);
  (*param_2->lpVtbl->Write)
            (param_2,(void *)param_1[4],*(int *)((longlong)param_1 + 0x1c) << 2,(ULONG *)0x0);
  iVar6 = 0;
  if (0 < *(int *)((longlong)param_1 + 0x1c)) {
    lVar5 = 0;
    lVar7 = 0;
    do {
      switch((*(int *)(lVar7 + param_1[4]) << 0x1c) >> 0x1c) {
      case 1:
      case 2:
        if (*(short *)(lVar5 + param_1[5]) != 9) {
          FUN_180002a20(local_428,"Assert failed in file %s line %d",
                        "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0x367);
          LogMessage(local_428,2,1);
        }
        uVar4 = FUN_18002ec50(DAT_180079590,param_2,*(longlong *)(lVar5 + 8 + param_1[5]));
        iVar3 = (int)uVar4;
        goto LAB_180054ad8;
      case 4:
      case 5:
        if (*(short *)(lVar5 + param_1[5]) != 0xd) {
          FUN_180002a20(local_428,"Assert failed in file %s line %d",
                        "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0x36e);
          LogMessage(local_428,2,1);
        }
        iVar3 = OleSaveToStream(*(LPPERSISTSTREAM *)(lVar5 + 8 + param_1[5]),param_2);
LAB_180054ad8:
        if (iVar3 < 0) {
          return;
        }
        break;
      case 6:
      case 7:
        if (*(short *)(lVar5 + param_1[5]) != 8) {
          FUN_180002a20(local_428,"Assert failed in file %s line %d",
                        "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0x355);
          LogMessage(local_428,2,1);
        }
      case 0:
        pv = (void *)(param_1[5] + (longlong)iVar6 * 0x18);
        p_Var1 = param_2->lpVtbl->Write;
        if (*(short *)(lVar5 + param_1[5]) == 8) {
          (*p_Var1)(param_2,pv,0x18,(ULONG *)0x0);
          UVar2 = SysStringLen(*(BSTR *)(lVar5 + 8 + param_1[5]));
          local_438[0] = UVar2 * 2;
          (*param_2->lpVtbl->Write)(param_2,local_438,4,(ULONG *)0x0);
          (*param_2->lpVtbl->Write)
                    (param_2,*(void **)(lVar5 + 8 + param_1[5]),local_438[0],(ULONG *)0x0);
        }
        else {
          (*p_Var1)(param_2,pv,0x18,(ULONG *)0x0);
        }
      }
      iVar6 = iVar6 + 1;
      lVar7 = lVar7 + 4;
      lVar5 = lVar5 + 0x18;
    } while (iVar6 < *(int *)((longlong)param_1 + 0x1c));
  }
  (*param_2->lpVtbl->Write)(param_2,param_1 + 1,4,(ULONG *)0x0);
  (*param_2->lpVtbl->Write)(param_2,(void *)((longlong)param_1 + 0xc),4,(ULONG *)0x0);
  (*param_2->lpVtbl->Write)(param_2,param_1 + 2,4,(ULONG *)0x0);
  (*param_2->lpVtbl->Write)(param_2,param_1 + 6,4,(ULONG *)0x0);
  (*param_2->lpVtbl->Write)(param_2,(void *)((longlong)param_1 + 0x34),4,(ULONG *)0x0);
  FUN_18002ec50(DAT_180079590,param_2,param_1[7]);
  return;
}

/* ---- FUNC 00054BC0 FUN_180054bc0 (91 bytes) ---- */

void FUN_180054bc0(longlong param_1,CArchive *param_2)

{
  __uint64 _Var1;
  
  if ((~*(uint *)(param_2 + 0x20) & 1) == 0) {
    _Var1 = CArchive::ReadCount(param_2);
    FUN_180055fb0(param_1,_Var1,-1);
  }
  else {
    CArchive::WriteCount(param_2,*(__uint64 *)(param_1 + 0x10));
  }
  FUN_18004fe00(param_2,*(void **)(param_1 + 8),*(ulonglong *)(param_1 + 0x10));
  return;
}

/* ---- FUNC 00054C20 FUN_180054c20 (328 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180054c20(CDWordArray *param_1,ulong param_2,
                  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *param_3
                  ,void *param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined1 auStack_448 [32];
  undefined1 local_428 [1008];
  ulonglong local_38;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStack_448;
  if (*(longlong *)(param_1 + 0x10) != *(longlong *)(param_1 + 0x38)) {
    FUN_180002a20(local_428,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0xd57);
    LogMessage(local_428,2,1);
  }
  if (*(longlong *)(param_1 + 0x10) != *(longlong *)(param_1 + 0x60)) {
    FUN_180002a20(local_428,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0xd58);
    LogMessage(local_428,2,1);
  }
  uVar1 = *(ulonglong *)(param_1 + 0x10);
  uVar2 = 0;
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar2 < 0) || ((longlong)uVar1 <= (longlong)uVar2)) {
LAB_180054d63:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      if (*(ulong *)(*(longlong *)(param_1 + 8) + uVar2 * 4) == param_2) {
        if (((longlong)uVar2 < *(longlong *)(param_1 + 0x38)) &&
           (ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       (*(longlong *)(param_1 + 0x30) + uVar2 * 8),param_3),
           (longlong)uVar2 < *(longlong *)(param_1 + 0x60))) {
          *(void **)(*(longlong *)(param_1 + 0x58) + uVar2 * 8) = param_4;
          return;
        }
        goto LAB_180054d63;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar1);
  }
  CDWordArray::SetAtGrow(param_1,uVar1,param_2);
  CStringArray::SetAtGrow
            ((CStringArray *)(param_1 + 0x28),*(__int64 *)(param_1 + 0x38),
             (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_3);
  CPtrArray::SetAtGrow((CPtrArray *)(param_1 + 0x50),*(__int64 *)(param_1 + 0x60),param_4);
  return;
}

/* ---- FUNC 00054D70 FUN_180054d70 (78 bytes) ---- */

void FUN_180054d70(longlong param_1,longlong param_2,undefined4 param_3)

{
  if (-1 < param_2) {
    if (*(longlong *)(param_1 + 0x10) <= param_2) {
      FUN_180055fb0(param_1,param_2 + 1,-1);
    }
    *(undefined4 *)(*(longlong *)(param_1 + 8) + param_2 * 4) = param_3;
    return;
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00054DC0 FUN_180054dc0 (1460 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180054dc0(longlong param_1,int param_2,short param_3,uint *param_4)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  undefined8 *puVar7;
  longlong lVar8;
  VARIANTARG *pvarg;
  uint uVar9;
  longlong *plVar10;
  undefined1 auStack_4f8 [32];
  undefined8 *local_4d8;
  _union_2707 local_4d0;
  _union_2707 local_4b8;
  _union_2707 local_4a0;
  undefined4 local_488;
  ULONG UStack_484;
  undefined4 uStack_480;
  ULONG UStack_47c;
  code *local_478;
  _union_2707 local_468;
  _union_2707 local_450;
  undefined1 local_438 [1008];
  ulonglong local_48;
  
  local_48 = DAT_180077818 ^ (ulonglong)auStack_4f8;
  local_4b8._16_8_ = *(undefined8 *)(param_4 + 4);
  uVar9 = (uint)param_3;
  local_4b8._0_4_ = *param_4;
  local_4b8.decVal.Hi32 = param_4[1];
  local_4b8._8_4_ = param_4[2];
  local_4b8._12_4_ = param_4[3];
  if (param_2 < 0) {
    FUN_180002a20(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0x243);
    LogMessage(local_438,2,1);
  }
  if (*(int *)(param_1 + 0x1c) <= param_2) {
    FUN_180002a20(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0x244);
    LogMessage(local_438,2,1);
  }
  plVar1 = (longlong *)(param_1 + 0x20);
  if ((*(longlong *)(param_1 + 0x28) == 0) || (*plVar1 == 0)) {
    FUN_180002a20(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0x245);
    LogMessage(local_438,2,1);
  }
  lVar2 = (longlong)param_2 * 4;
  *(uint *)(*plVar1 + lVar2) = *(uint *)(*plVar1 + lVar2) & 0xffffff8f;
  *(uint *)(*plVar1 + lVar2) = *(uint *)(*plVar1 + lVar2) & 0xffffff7f;
  *(uint *)(*plVar1 + lVar2) = (uVar9 ^ *(uint *)(*plVar1 + lVar2)) & 0xfffffff0 ^ uVar9;
  lVar3 = (longlong)param_2 * 0x18;
  VariantCopy((VARIANTARG *)(*(longlong *)(param_1 + 0x28) + lVar3),(VARIANTARG *)&local_4b8.n2);
  if (param_3 == 0) {
    if ((((local_4b8._0_4_ & 0xffff) - 4 & 0xfffa) == 0) && (local_4b8.n2.vt != 9)) {
      lVar8 = *plVar1;
      uVar5 = *(uint *)(lVar8 + lVar2) & 0xffffffaf | 0x20;
    }
    else {
      if (1 < (ushort)(local_4b8.n2.vt - 2)) goto LAB_18005507e;
LAB_18005506d:
      lVar8 = *plVar1;
      uVar5 = *(uint *)(lVar8 + lVar2) & 0xffffff9f | 0x10;
    }
LAB_18005507a:
    *(uint *)(lVar8 + lVar2) = uVar5;
  }
  else if (uVar9 == 1) {
    if ((local_4b8.n2.vt == 9) && (CONCAT44(local_4b8._12_4_,local_4b8._8_4_) != 0)) {
      local_4d8 = (undefined8 *)0x0;
      lVar8 = *(longlong *)(CONCAT44(local_4b8._12_4_,local_4b8._8_4_) + 0x48);
      if (lVar8 != 0) {
        iVar6 = HAGetAttrType(lVar8,0,0,&local_4d8);
        if (iVar6 == -999) {
          if ((local_4d8 != (undefined8 *)0x0) && ((code *)*local_4d8 != (code *)0x0)) {
            (*(code *)*local_4d8)();
          }
        }
        else {
          if (iVar6 == -1) goto LAB_18005506d;
          if (iVar6 + 3U < 2) {
            lVar8 = *plVar1;
            uVar5 = *(uint *)(lVar8 + lVar2) & 0xffffffaf | 0x20;
            goto LAB_18005507a;
          }
        }
      }
    }
  }
  else if ((((uVar9 == 2) && (local_4b8.n2.vt == 9)) &&
           (CONCAT44(local_4b8._12_4_,local_4b8._8_4_) != 0)) &&
          (lVar8 = *(longlong *)(CONCAT44(local_4b8._12_4_,local_4b8._8_4_) + 0x48), lVar8 != 0)) {
    puVar7 = (undefined8 *)HAGetElementLabel(lVar8,0,&local_4a0);
    if (puVar7 == (undefined8 *)0x0) {
      if (CONCAT44(local_4a0._12_4_,CONCAT22(local_4a0._10_2_,local_4a0._8_2_)) != 0) {
        if (local_4a0._0_4_ == -2) {
          lVar8 = *plVar1;
          uVar5 = *(uint *)(lVar8 + lVar2) & 0xffffffaf | 0x20;
LAB_180054fab:
          *(uint *)(lVar8 + lVar2) = uVar5;
        }
        else if (local_4a0._0_4_ == -1) {
          lVar8 = *plVar1;
          uVar5 = *(uint *)(lVar8 + lVar2) & 0xffffff9f | 0x10;
          goto LAB_180054fab;
        }
        if ((code *)local_4a0._16_8_ != (code *)0x0) {
          (*(code *)local_4a0._16_8_)
                    (CONCAT44(local_4a0._12_4_,CONCAT22(local_4a0._10_2_,local_4a0._8_2_)));
        }
      }
    }
    else if ((code *)*puVar7 != (code *)0x0) {
      (*(code *)*puVar7)(puVar7);
    }
  }
LAB_18005507e:
  if ((uVar9 != 1) ||
     (plVar10 = (longlong *)CONCAT44(local_4b8._12_4_,local_4b8._8_4_), plVar10 == (longlong *)0x0))
  goto LAB_1800551cb;
  VariantInit((VARIANTARG *)&local_4d0.n2);
  VariantInit((VARIANTARG *)&local_450.n2);
  local_488 = local_4d0._0_4_;
  UStack_484 = local_4d0.decVal.Hi32;
  uStack_480 = local_4d0._8_4_;
  UStack_47c = local_4d0._12_4_;
  local_478 = (code *)local_4d0._16_8_;
  iVar6 = (**(code **)(*plVar10 + 0x98))(plVar10,0,&local_488,&local_450);
  if (-1 < iVar6) {
    VariantClear((VARIANTARG *)&local_450.n2);
  }
  VariantInit((VARIANTARG *)&local_468.n2);
  VariantInit((VARIANTARG *)&local_4a0.n2);
  if (-1 >= iVar6 || local_450.n2.vt == 0) goto LAB_1800551cb;
  local_488 = local_4d0._0_4_;
  UStack_484 = local_4d0.decVal.Hi32;
  uStack_480 = local_4d0._8_4_;
  UStack_47c = local_4d0._12_4_;
  local_478 = (code *)local_4d0._16_8_;
  iVar6 = (**(code **)(*plVar10 + 0x98))(plVar10,2,&local_488,&local_468);
  if (-1 < iVar6) {
    if (local_468.n2.vt == 2) {
      local_468._8_4_ = SEXT24((short)local_468._8_2_);
LAB_180055160:
      *(undefined4 *)(param_1 + 0x30) = local_468._8_4_;
    }
    else if (local_468.n2.vt == 3) goto LAB_180055160;
    VariantClear((VARIANTARG *)&local_468.n2);
  }
  local_488 = local_4d0._0_4_;
  UStack_484 = local_4d0.decVal.Hi32;
  uStack_480 = local_4d0._8_4_;
  UStack_47c = local_4d0._12_4_;
  local_478 = (code *)local_4d0._16_8_;
  iVar6 = (**(code **)(*plVar10 + 0x98))(plVar10,3,&local_488,&local_4a0);
  if (iVar6 < 0) goto LAB_1800551cb;
  if (local_4a0.n2.vt == 2) {
    iVar6 = (int)(short)local_4a0._8_2_;
LAB_1800551bc:
    *(int *)(param_1 + 0x34) = iVar6;
  }
  else if (local_4a0.n2.vt == 3) {
    iVar6 = CONCAT22(local_4a0._10_2_,local_4a0._8_2_);
    goto LAB_1800551bc;
  }
  VariantClear((VARIANTARG *)&local_4a0.n2);
LAB_1800551cb:
  if ((uVar9 == 1) || (uVar9 == 2)) {
    plVar10 = (longlong *)CONCAT44(local_4b8._12_4_,local_4b8._8_4_);
    if (plVar10 != (longlong *)0x0) {
      local_4d0._16_8_ = (code *)0x0;
      local_4d0._0_8_ = 0;
      local_4d0.decVal.u2.Lo64 = (_union_1719)0x0;
      puVar7 = (undefined8 *)HAGetAttr(plVar10[9],0x1b,0,&local_4d0);
      if (puVar7 == (undefined8 *)0x0) {
        if ((local_4d0.decVal.u2.Lo64 != 0) && (*(int *)local_4d0.decVal.u2 != 0)) {
          *(uint *)(lVar2 + *plVar1) = *(uint *)(lVar2 + *plVar1) | 0x80;
        }
        if ((code *)local_4d0._16_8_ != (code *)0x0) {
          (*(code *)local_4d0._16_8_)(local_4d0.decVal.u2.Lo64);
        }
      }
      else if ((code *)*puVar7 != (code *)0x0) {
        (*(code *)*puVar7)(puVar7);
      }
    }
    if ((*(byte *)(lVar2 + *plVar1) & 0x80) != 0) {
      if (*(longlong *)(param_1 + 0x38) == 0) {
        while ((int)plVar10[0xd] == 0) {
          plVar10 = (longlong *)plVar10[0xc];
          local_4d0._0_8_ = 0;
          local_4d0.decVal.u2.Lo64 = (_union_1719)0x0;
          local_4d0._16_8_ = (code *)0x0;
          puVar7 = (undefined8 *)HAGetAttr(plVar10[9],0x1b,0,&local_4d0);
          if (puVar7 != (undefined8 *)0x0) {
            if ((code *)*puVar7 != (code *)0x0) {
              (*(code *)*puVar7)(puVar7);
            }
            break;
          }
          bVar4 = true;
          if ((local_4d0.decVal.u2.Lo64 != 0) && (bVar4 = true, *(int *)local_4d0.decVal.u2 != 0)) {
            bVar4 = false;
          }
          if ((code *)local_4d0._16_8_ != (code *)0x0) {
            (*(code *)local_4d0._16_8_)();
          }
          if (bVar4) break;
        }
        *(longlong **)(param_1 + 0x38) = plVar10;
        (**(code **)(*plVar10 + 8))(plVar10);
      }
      pvarg = (VARIANTARG *)(*(longlong *)(param_1 + 0x28) + lVar3);
      VariantClear(pvarg);
      local_4d8 = (undefined8 *)0x0;
      plVar10 = *(longlong **)(*(longlong *)(param_1 + 0x38) + 0xe8);
      iVar6 = (**(code **)(*plVar10 + 0x98))
                        (plVar10,*(undefined8 *)(CONCAT44(local_4b8._12_4_,local_4b8._8_4_) + 0xe8),
                         &local_4d8);
      if (iVar6 < 0) {
        *(uint *)(lVar2 + *plVar1) = *(uint *)(lVar2 + *plVar1) & 0xfffffff0;
      }
      else {
        (pvarg->n1).n2.vt = 0xd;
        (pvarg->n1).decVal.u2.Lo64 = (ULONGLONG)local_4d8;
        lVar3 = *plVar1;
        uVar9 = ((*(int *)(lVar3 + lVar2) << 0x1c) >> 0x1c) + 3;
        *(uint *)(lVar3 + lVar2) = (uVar9 ^ *(uint *)(lVar3 + lVar2)) & 0xfffffff0 ^ uVar9;
      }
    }
  }
  return;
}

