/* RVA 0x24de0 */
void FUN_180024de0(void)

{
  longlong lVar1;
  
  lVar1 = DAT_180054050;
  *(undefined4 *)(DAT_180054050 + 0xe4) = 0;
  *(undefined1 *)(lVar1 + 0xe0) = 1;
  MMSetVisibleSuppress(0);
  SetGlobalPointer("DontShowUpward",&DAT_1800527f4,0);
  GRsetAutomationMode(1);
  RegisterClassFactory();
  LockGlobalObject(0,0);
  return;
}

/* RVA 0x24e40 */
longlong * FUN_180024e40(longlong *param_1,void *param_2,ulonglong param_3)

{
  longlong lVar1;
  longlong *plVar2;
  
  lVar1 = param_1[2];
  if ((ulonglong)(param_1[3] - lVar1) < param_3) {
    plVar2 = FUN_180007e40(param_1,param_3,0,param_2,param_3);
    return plVar2;
  }
  param_1[2] = lVar1 + param_3;
  plVar2 = param_1;
  if (0xf < (ulonglong)param_1[3]) {
    plVar2 = (longlong *)*param_1;
  }
  memmove((void *)((longlong)plVar2 + lVar1),param_2,param_3);
  *(undefined1 *)((longlong)plVar2 + lVar1 + param_3) = 0;
  return param_1;
}

/* RVA 0x24ed0 */
void FUN_180024ed0(undefined8 param_1,void *param_2,ulonglong param_3)

{
  void *pvVar1;
  
  pvVar1 = param_2;
  if ((0xfff < param_3) &&
     (pvVar1 = *(void **)((longlong)param_2 + -8),
     0x1f < (ulonglong)((longlong)param_2 + (-8 - (longlong)pvVar1)))) {
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
  FUN_180035134(pvVar1);
  return;
}

/* RVA 0x24f10 */
ulonglong FUN_180024f10(undefined8 *param_1,char *param_2,ulonglong param_3)

{
  char cVar1;
  ulonglong _Size;
  int iVar2;
  void *_Buf1;
  ulonglong uVar3;
  char *_Buf2;
  undefined8 *puVar4;
  
  _Buf2 = param_2;
  if (0xf < *(ulonglong *)(param_2 + 0x18)) {
    _Buf2 = *(char **)param_2;
  }
  puVar4 = param_1;
  if (0xf < (ulonglong)param_1[3]) {
    puVar4 = (undefined8 *)*param_1;
  }
  _Size = *(ulonglong *)(param_2 + 0x10);
  if (((ulonglong)param_1[2] < _Size) || (uVar3 = param_1[2] - _Size, uVar3 < param_3)) {
    return 0xffffffffffffffff;
  }
  if (_Size == 0) {
    return param_3;
  }
  cVar1 = *_Buf2;
  _Buf1 = memchr((void *)((longlong)puVar4 + param_3),(int)cVar1,
                 (longlong)puVar4 + ((uVar3 + 1) - (longlong)((longlong)puVar4 + param_3)));
  while( true ) {
    if (_Buf1 == (void *)0x0) {
      return 0xffffffffffffffff;
    }
    iVar2 = memcmp(_Buf1,_Buf2,_Size);
    if (iVar2 == 0) break;
    _Buf1 = memchr((void *)((longlong)_Buf1 + 1),(int)cVar1,
                   (longlong)puVar4 + ((uVar3 + 1) - ((longlong)_Buf1 + 1)));
  }
  return (longlong)_Buf1 - (longlong)puVar4;
}

/* RVA 0x25010 */
undefined8 FUN_180025010(undefined8 param_1,undefined8 *param_2)

{
  HANDLE pvVar1;
  
  pvVar1 = GetCurrentProcess();
  *param_2 = pvVar1;
  return 0;
}

/* RVA 0x25030 */
undefined8 FUN_180025030(undefined8 param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 *puVar3;
  
  if (param_2 != (undefined8 *)0x0) {
    iVar2 = FUN_180033bd0();
    puVar3 = (undefined8 *)&DAT_180041fe0;
    if (iVar2 == 2) {
      puVar3 = (undefined8 *)&DAT_180042000;
    }
    uVar1 = puVar3[1];
    *param_2 = *puVar3;
    param_2[1] = uVar1;
  }
  return 0;
}

/* RVA 0x25070 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180025070(ulong *param_1,LPCSTR param_2,undefined8 *param_3)

{
  ulong uVar1;
  IUnknown *pIVar2;
  IDispatch *This;
  BSTR bstrString;
  undefined8 uVar3;
  undefined1 auStackY_178 [32];
  WORD in_stack_fffffffffffffea8;
  DISPPARAMS *in_stack_fffffffffffffeb0;
  IDispatch *This_00;
  EXCEPINFO *in_stack_fffffffffffffec0;
  OLECHAR *psz;
  OLECHAR local_130;
  OLECHAR aOStack_12e [131];
  ulonglong local_28;
  
  local_28 = DAT_180052888 ^ (ulonglong)auStackY_178;
  if ((((DAT_180054050 == 0) || (*(longlong *)(DAT_180054050 + 200) == 0)) ||
      (param_3 == (undefined8 *)0x0)) || (param_1 == (ulong *)0x0)) {
    return 0;
  }
  uVar3 = 0;
  *param_3 = 0;
  uVar1 = *param_1;
  if (uVar1 == 0) {
    uVar1 = APXLCreateItem(*(void **)(*(longlong *)(DAT_180054050 + 200) + 0xb0));
    *param_1 = uVar1;
    if (uVar1 == 0) {
      return 0;
    }
  }
  pIVar2 = APXLFindItemUnk(*(void **)(*(longlong *)(DAT_180054050 + 200) + 0xb0),
                           *(bool *)(*(longlong *)(DAT_180054050 + 200) + 0xa9),uVar1);
  *param_3 = pIVar2;
  if (pIVar2 != (IUnknown *)0x0) {
    uVar3 = 1;
    This = (IDispatch *)HappGetTree();
    if (This != (IDispatch *)0x0) {
      (*This->lpVtbl->AddRef)(This);
      psz = &local_130;
      FUN_18000d660((undefined8 *)(aOStack_12e + -5),param_2,0);
      bstrString = SysAllocString(psz);
      if (psz != &local_130) {
        free(psz);
      }
      This_00 = (IDispatch *)0x0;
      (*This->lpVtbl[4].Invoke)
                (This,(DISPID)bstrString,(IID *)(auStackY_178 + 0x30),(LCID)This->lpVtbl,
                 in_stack_fffffffffffffea8,in_stack_fffffffffffffeb0,(VARIANT *)0x0,
                 in_stack_fffffffffffffec0,(UINT *)psz);
      SysFreeString(bstrString);
      APXLSetBlockNodes(*(void **)(*(longlong *)(DAT_180054050 + 200) + 0xb0),
                        *(bool *)(*(longlong *)(DAT_180054050 + 200) + 0xa9),*param_1,This,This_00);
      if (This_00 != (IDispatch *)0x0) {
        (*This_00->lpVtbl->Release)(This_00);
      }
      (*This->lpVtbl->Release)(This);
    }
  }
  return uVar3;
}

/* RVA 0x25260 */
bool FUN_180025260(ulong param_1)

{
  bool bVar1;
  
  if ((DAT_180054050 == 0) || (*(longlong *)(DAT_180054050 + 200) == 0)) {
    return false;
  }
  bVar1 = APXLCommitItem(*(void **)(*(longlong *)(DAT_180054050 + 200) + 0xb0),param_1);
  return bVar1;
}

/* RVA 0x252a0 */
void FUN_1800252a0(void *param_1)

{
  void *pvVar1;
  DWORD DVar2;
  
  if ((DAT_180054050 == 0) || (*(longlong *)(DAT_180054050 + 200) == 0)) {
    return;
  }
  DVar2 = GetCurrentThreadId();
  pvVar1 = *(void **)(*(longlong *)(DAT_180054050 + 200) + 0xb0);
  if (*(DWORD *)(DAT_180054050 + 0x378) == DVar2) {
    APXLDoCalcSync(pvVar1,param_1);
    return;
  }
  APXLDoCalc(pvVar1,param_1,DAT_180054068);
  return;
}

/* RVA 0x25310 */
void FUN_180025310(__int64 param_1,char *param_2,char *param_3,char *param_4)

{
  if ((DAT_180054050 != 0) && (*(longlong *)(DAT_180054050 + 200) != 0)) {
    APXLEditDefVars(*(void **)(*(longlong *)(DAT_180054050 + 200) + 0xb0),param_1,param_2,param_3,
                    param_4);
  }
  return;
}

/* RVA 0x25350 */
bool FUN_180025350(ulong param_1)

{
  bool bVar1;
  
  if ((DAT_180054050 == 0) || (*(longlong *)(DAT_180054050 + 200) == 0)) {
    return false;
  }
  bVar1 = APXLRemoveItem(*(void **)(*(longlong *)(DAT_180054050 + 200) + 0xb0),param_1);
  return bVar1;
}

/* RVA 0x253c0 */
void FUN_1800253c0(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,
                  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2)

{
  if (param_1 != param_2) {
    do {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1);
      param_1 = param_1 + 8;
    } while (param_1 != param_2);
  }
  return;
}

/* RVA 0x25400 */
CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_180025400(longlong *param_1,
             CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *param_2,
             CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *param_3)

{
  ulonglong uVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  longlong lVar2;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar4;
  longlong lVar5;
  void *pvVar6;
  ulonglong uVar7;
  void *pvVar8;
  ulonglong uVar9;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar10;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar11;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar12;
  
  lVar2 = *param_1;
  lVar5 = param_1[1] - lVar2 >> 3;
  if (lVar5 == 0x1fffffffffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_18001d1d0();
  }
  uVar1 = lVar5 + 1;
  uVar7 = param_1[2] - lVar2 >> 3;
  if (0x1fffffffffffffff - (uVar7 >> 1) < uVar7) {
LAB_18002561d:
                    /* WARNING: Subroutine does not return */
    FUN_18001d0c0();
  }
  uVar7 = (uVar7 >> 1) + uVar7;
  uVar9 = uVar1;
  if (uVar1 <= uVar7) {
    uVar9 = uVar7;
  }
  if (0x1fffffffffffffff < uVar9) goto LAB_18002561d;
  uVar9 = uVar9 * 8;
  if (uVar9 < 0x1000) {
    if (uVar9 == 0) {
      pCVar12 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    }
    else {
      pCVar12 = operator_new(uVar9);
    }
  }
  else {
    if (uVar9 + 0x27 <= uVar9) goto LAB_18002561d;
    pvVar6 = operator_new(uVar9 + 0x27);
    if (pvVar6 == (void *)0x0) goto LAB_180025616;
    pCVar12 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
              ((longlong)pvVar6 + 0x27U & 0xffffffffffffffe0);
    *(void **)(pCVar12 + -8) = pvVar6;
  }
  this = pCVar12 + ((longlong)param_2 - lVar2 >> 3) * 8;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this,param_3);
  pCVar3 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)param_1[1];
  pCVar10 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)*param_1;
  if (param_2 == pCVar3) {
    pCVar11 = pCVar12;
    for (; pCVar10 != pCVar3; pCVar10 = pCVar10 + 8) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar11,pCVar10);
      pCVar11 = pCVar11 + 8;
    }
  }
  else {
    FUN_180025630(pCVar10,param_2,pCVar12);
    FUN_180025630(param_2,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                           *)param_1[1],this + 8);
  }
  pCVar11 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)*param_1;
  if (pCVar11 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
    pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_1[1];
    for (; pCVar11 != pCVar4; pCVar11 = pCVar11 + 8) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar11);
    }
    pvVar6 = (void *)*param_1;
    pvVar8 = pvVar6;
    if ((0xfff < (param_1[2] - (longlong)pvVar6 & 0xfffffffffffffff8U)) &&
       (pvVar8 = *(void **)((longlong)pvVar6 + -8),
       0x1f < (ulonglong)((longlong)pvVar6 + (-8 - (longlong)pvVar8)))) {
LAB_180025616:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(pvVar8);
  }
  *param_1 = (longlong)pCVar12;
  param_1[1] = (longlong)(pCVar12 + uVar1 * 8);
  param_1[2] = (longlong)(pCVar12 + uVar9);
  return this;
}

/* RVA 0x25630 */
CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_180025630(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *param_1,
             CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *param_2,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 8) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_3,param_1);
    param_3 = param_3 + 8;
  }
  return param_3;
}

/* RVA 0x256a0 */
undefined8 * FUN_1800256a0(undefined8 *param_1,void *param_2)

{
  size_t sVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  sVar1 = 0xffffffffffffffff;
  do {
    sVar1 = sVar1 + 1;
  } while (*(char *)((longlong)param_2 + sVar1) != '\0');
  FUN_180006e90(param_1,param_2,sVar1);
  return param_1;
}

/* RVA 0x256e0 */
longlong * FUN_1800256e0(longlong *param_1,longlong *param_2,longlong *param_3)

{
  void *pvVar1;
  ulonglong _Size;
  size_t _Size_00;
  UINT UVar2;
  UINT UVar3;
  BSTR pOVar4;
  int *piVar5;
  ulonglong uVar6;
  uint uVar7;
  ulonglong uVar8;
  
  UVar3 = 0;
  *(undefined4 *)(param_1 + 2) = 1;
  param_1[1] = 0;
  if (((undefined8 *)*param_2 == (undefined8 *)0x0) ||
     (pOVar4 = *(BSTR *)*param_2, pOVar4 == (BSTR)0x0)) {
    uVar6 = 0;
  }
  else {
    UVar2 = SysStringLen(pOVar4);
    uVar6 = (ulonglong)UVar2;
  }
  if (((undefined8 *)*param_3 != (undefined8 *)0x0) &&
     (pOVar4 = *(BSTR *)*param_3, pOVar4 != (BSTR)0x0)) {
    UVar3 = SysStringLen(pOVar4);
  }
  uVar7 = UVar3 + (int)uVar6;
  if ((uVar7 < UVar3) || (0xffffffff < (ulonglong)uVar7 * 2)) {
LAB_18002582c:
                    /* WARNING: Subroutine does not return */
    FUN_180034a60(0x8007000e);
  }
  pOVar4 = SysAllocStringByteLen((LPCSTR)0x0,uVar7 * 2);
  *param_1 = (longlong)pOVar4;
  if (pOVar4 == (BSTR)0x0) {
    if (uVar7 != 0) goto LAB_18002582c;
  }
  else {
    if (((undefined8 *)*param_2 != (undefined8 *)0x0) &&
       (pvVar1 = *(void **)*param_2, pvVar1 != (void *)0x0)) {
      _Size = (ulonglong)(uVar7 + 1) * 2;
      uVar8 = (ulonglong)((int)uVar6 + 1);
      _Size_00 = uVar8 * 2;
      if (uVar8 != 0) {
        if (_Size < _Size_00) {
          memset(pOVar4,0,_Size);
          piVar5 = _errno();
          *piVar5 = 0x22;
          _invalid_parameter_noinfo();
        }
        else {
          memcpy(pOVar4,pvVar1,_Size_00);
        }
      }
    }
    if (((undefined8 *)*param_3 != (undefined8 *)0x0) &&
       (pvVar1 = *(void **)*param_3, pvVar1 != (void *)0x0)) {
      pOVar4 = (BSTR)(*param_1 + uVar6 * 2);
      if ((ulonglong)(UVar3 + 1) != 0) {
        if (pOVar4 == (BSTR)0x0) {
          piVar5 = _errno();
          *piVar5 = 0x16;
          _invalid_parameter_noinfo();
        }
        else {
          memcpy(pOVar4,pvVar1,(ulonglong)(UVar3 + 1) * 2);
        }
      }
    }
  }
  return (longlong *)pOVar4;
}

/* RVA 0x25840 */
undefined8 * FUN_180025840(undefined8 *param_1,longlong param_2)

{
  *param_1 = std::exception::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  __std_exception_copy(param_2 + 8);
  *param_1 = std::length_error::vftable;
  return param_1;
}

/* RVA 0x25880 */
undefined8 * FUN_180025880(undefined8 *param_1,undefined8 param_2)

{
  undefined8 local_18;
  undefined1 local_10;
  
  local_10 = 1;
  *param_1 = std::exception::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  local_18 = param_2;
  __std_exception_copy(&local_18);
  *param_1 = std::length_error::vftable;
  return param_1;
}

/* RVA 0x258d0 */
undefined8 * FUN_1800258d0(undefined8 *param_1,longlong param_2)

{
  *param_1 = std::exception::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  __std_exception_copy(param_2 + 8);
  *param_1 = std::logic_error::vftable;
  return param_1;
}

/* RVA 0x25910 */
void FUN_180025910(undefined8 *param_1)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  
  pCVar1 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_1[1];
  for (this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)*param_1;
      this != pCVar1; this = this + 8) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this);
  }
  return;
}

/* RVA 0x25950 */
void FUN_180025950(longlong *param_1)

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
    FUN_180035134(pvVar2);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}

/* RVA 0x259b0 */
void FUN_1800259b0(longlong *param_1)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  void *pvVar2;
  void *pvVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  
  this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)*param_1;
  if (this != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
    pCVar1 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_1[1];
    for (; this != pCVar1; this = this + 8) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this);
    }
    pvVar2 = (void *)*param_1;
    pvVar3 = pvVar2;
    if ((0xfff < (param_1[2] - (longlong)pvVar2 & 0xfffffffffffffff8U)) &&
       (pvVar3 = *(void **)((longlong)pvVar2 + -8),
       0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar3)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(pvVar3);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}

/* RVA 0x25a40 */
longlong * FUN_180025a40(longlong *param_1,longlong *param_2,longlong *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong extraout_RAX;
  longlong lVar3;
  
  lVar3 = 0;
  lVar1 = *param_1;
  *param_2 = lVar1;
  if (lVar1 != 0) {
    LOCK();
    *(int *)(lVar1 + 0x10) = *(int *)(lVar1 + 0x10) + 1;
    UNLOCK();
  }
  plVar2 = operator_new(0x18);
  if (plVar2 != (longlong *)0x0) {
    FUN_1800256e0(plVar2,param_2,param_3);
    lVar3 = extraout_RAX;
  }
  if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_180034a60(0x8007000e);
  }
  FUN_18001ccd0(param_2);
  *param_2 = lVar3;
  return param_2;
}

/* RVA 0x25ad0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180025ad0(IUnknown *param_1,char *param_2,char *param_3,char *param_4)

{
  int *piVar1;
  int iVar2;
  longlong *plVar3;
  BSTR pOVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong *plVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  longlong lVar10;
  longlong lVar11;
  undefined1 auStackY_878 [32];
  char local_848 [8];
  longlong *local_840;
  longlong *local_838;
  undefined8 *local_830;
  longlong *local_828;
  longlong **local_820;
  longlong *local_818;
  undefined8 *local_810;
  longlong *local_808;
  longlong *local_800;
  longlong *local_7f8;
  longlong *local_7f0;
  longlong *local_7e8;
  longlong local_7e0;
  undefined8 local_7d8;
  longlong local_7d0;
  longlong *local_7c8;
  undefined8 local_7c0;
  longlong *local_7b8;
  _WIN32_FIND_DATAA local_7a8;
  char local_668 [256];
  char local_568 [272];
  char local_458 [256];
  char local_358 [272];
  char local_248 [256];
  char local_148 [256];
  ulonglong local_48;
  
  local_48 = DAT_180052888 ^ (ulonglong)auStackY_878;
  local_818 = (longlong *)0x0;
  _splitpath(param_2,local_848,local_458,local_668,local_248);
  _makepath(local_568,(char *)0x0,(char *)0x0,local_668,param_4);
  lVar11 = 0;
  while (lVar10 = lVar11 + 1, param_4[lVar11] == (&DAT_180041ae8)[lVar11]) {
    lVar11 = lVar10;
    if (lVar10 == 4) {
      plVar3 = operator_new(0x18);
      local_838 = plVar3;
      if (plVar3 == (longlong *)0x0) {
        plVar3 = (longlong *)0x0;
      }
      else {
        plVar3[1] = 0;
        *(undefined4 *)(plVar3 + 2) = 1;
        pOVar4 = FUN_180034c50(local_568);
        *plVar3 = (longlong)pOVar4;
      }
      local_840 = plVar3;
      if (plVar3 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_180034a60(0x8007000e);
      }
      LOCK();
      *(int *)(plVar3 + 2) = (int)plVar3[2] + 1;
      UNLOCK();
      local_828 = plVar3;
      FUN_180026570(param_1,&local_828);
      LOCK();
      plVar5 = plVar3 + 2;
      lVar11 = *plVar5;
      *(int *)plVar5 = (int)*plVar5 + -1;
      UNLOCK();
      if ((int)lVar11 != 1) {
        return;
      }
      if ((BSTR)*plVar3 != (BSTR)0x0) {
        SysFreeString((BSTR)*plVar3);
        *plVar3 = 0;
      }
      if ((void *)plVar3[1] != (void *)0x0) {
        operator_delete__((void *)plVar3[1]);
        plVar3[1] = 0;
      }
      FUN_180035134(plVar3);
      return;
    }
  }
  _splitpath(param_3,local_848,local_458,local_668,local_248);
  _makepath(local_148,local_848,local_458,(char *)0x0,(char *)0x0);
  _makepath(local_358,(char *)0x0,local_148,local_668,param_4);
  local_828 = FindFirstFileA(local_358,&local_7a8);
  plVar3 = (longlong *)0x0;
  if (local_828 != (longlong *)0xffffffffffffffff) {
    plVar3 = operator_new(0x18);
    local_838 = plVar3;
    if (plVar3 == (longlong *)0x0) {
      plVar3 = (longlong *)0x0;
    }
    else {
      plVar3[1] = 0;
      *(undefined4 *)(plVar3 + 2) = 1;
      pOVar4 = FUN_180034c50(local_568);
      *plVar3 = (longlong)pOVar4;
    }
    local_808 = plVar3;
    if (plVar3 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_180034a60(0x8007000e);
    }
    plVar5 = operator_new(0x18);
    local_838 = plVar5;
    if (plVar5 == (longlong *)0x0) {
      plVar5 = (longlong *)0x0;
    }
    else {
      plVar5[1] = 0;
      *(undefined4 *)(plVar5 + 2) = 1;
      pOVar4 = FUN_180034c50(local_358);
      *plVar5 = (longlong)pOVar4;
    }
    local_7b8 = plVar5;
    if (plVar5 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_180034a60(0x8007000e);
    }
    lVar11 = 0;
    do {
      lVar10 = lVar11 + 1;
      if (param_4[lVar11] != (&DAT_1800417b0)[lVar11]) {
        LOCK();
        *(int *)(plVar3 + 2) = (int)plVar3[2] + 1;
        UNLOCK();
        local_7f8 = plVar3;
        FUN_180026570(param_1,&local_7f8);
        puVar8 = FUN_1800087d0(&local_7c0,"");
        LOCK();
        *(int *)(plVar5 + 2) = (int)plVar5[2] + 1;
        UNLOCK();
        LOCK();
        *(int *)(plVar3 + 2) = (int)plVar3[2] + 1;
        UNLOCK();
        local_7f0 = plVar5;
        local_7e8 = plVar3;
        puVar8 = FUN_180026260(param_1,&local_838,(longlong *)&local_7e8,(longlong *)&local_7f0,
                               puVar8);
        plVar6 = (longlong *)*puVar8;
        if (plVar6 != (longlong *)0x0) {
          (**(code **)(*plVar6 + 8))(plVar6);
          local_818 = plVar6;
        }
        if (local_838 != (longlong *)0x0) {
          (**(code **)(*local_838 + 0x10))();
        }
        goto LAB_180025fd1;
      }
      lVar11 = lVar10;
    } while (lVar10 != 4);
    plVar6 = operator_new(0x18);
    local_838 = plVar6;
    if (plVar6 == (longlong *)0x0) {
      plVar6 = (longlong *)0x0;
    }
    else {
      plVar6[1] = 0;
      *(undefined4 *)(plVar6 + 2) = 1;
      pOVar4 = FUN_180034c50(".backup");
      *plVar6 = (longlong)pOVar4;
    }
    local_840 = plVar6;
    if (plVar6 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_180034a60(0x8007000e);
    }
    plVar7 = FUN_180025a40((longlong *)&local_808,&local_7e0,(longlong *)&local_840);
    FUN_180026570(param_1,plVar7);
    LOCK();
    plVar7 = plVar6 + 2;
    lVar11 = *plVar7;
    *(int *)plVar7 = (int)*plVar7 + -1;
    UNLOCK();
    if ((int)lVar11 == 1) {
      if ((BSTR)*plVar6 != (BSTR)0x0) {
        SysFreeString((BSTR)*plVar6);
        *plVar6 = 0;
      }
      if ((void *)plVar6[1] != (void *)0x0) {
        operator_delete__((void *)plVar6[1]);
        plVar6[1] = 0;
      }
      FUN_180035134(plVar6);
    }
    local_830 = &local_7d8;
    local_820 = &local_800;
    puVar8 = operator_new(0x18);
    if (puVar8 == (undefined8 *)0x0) {
      puVar8 = (undefined8 *)0x0;
    }
    else {
      puVar8[1] = 0;
      *(undefined4 *)(puVar8 + 2) = 1;
      local_810 = puVar8;
      pOVar4 = FUN_180034c50(".backup");
      *puVar8 = pOVar4;
    }
    local_810 = puVar8;
    if (puVar8 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_180034a60(0x8007000e);
    }
    puVar9 = FUN_1800087d0(&local_7d8,"");
    LOCK();
    *(int *)(plVar5 + 2) = (int)plVar5[2] + 1;
    UNLOCK();
    local_800 = plVar5;
    plVar6 = FUN_180025a40((longlong *)&local_808,&local_7d0,(longlong *)&local_810);
    plVar6 = FUN_180026260(param_1,&local_7c8,plVar6,(longlong *)&local_800,puVar9);
    plVar6 = (longlong *)*plVar6;
    if (plVar6 != (longlong *)0x0) {
      (**(code **)(*plVar6 + 8))(plVar6);
      local_818 = plVar6;
    }
    if (local_7c8 != (longlong *)0x0) {
      (**(code **)(*local_7c8 + 0x10))();
    }
    LOCK();
    piVar1 = (int *)(puVar8 + 2);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
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
LAB_180025fd1:
    LOCK();
    plVar6 = plVar5 + 2;
    lVar11 = *plVar6;
    *(int *)plVar6 = (int)*plVar6 + -1;
    UNLOCK();
    if ((int)lVar11 == 1) {
      if ((BSTR)*plVar5 != (BSTR)0x0) {
        SysFreeString((BSTR)*plVar5);
        *plVar5 = 0;
      }
      if ((void *)plVar5[1] != (void *)0x0) {
        operator_delete__((void *)plVar5[1]);
        plVar5[1] = 0;
      }
      FUN_180035134(plVar5);
    }
    LOCK();
    plVar5 = plVar3 + 2;
    lVar11 = *plVar5;
    *(int *)plVar5 = (int)*plVar5 + -1;
    UNLOCK();
    if ((int)lVar11 == 1) {
      if ((BSTR)*plVar3 != (BSTR)0x0) {
        SysFreeString((BSTR)*plVar3);
        *plVar3 = 0;
      }
      if ((void *)plVar3[1] != (void *)0x0) {
        operator_delete__((void *)plVar3[1]);
        plVar3[1] = 0;
      }
      FUN_180035134(plVar3);
    }
    FindClose(local_828);
    plVar3 = local_818;
  }
  if (plVar3 != (longlong *)0x0) {
    (**(code **)(*plVar3 + 0x10))(plVar3);
  }
  return;
}

/* RVA 0x260d0 */
undefined8 FUN_1800260d0(char *param_1)

{
  int _FileHandle;
  char *pcVar1;
  char *local_res10 [3];
  
  _FileHandle = _open(param_1,0x102,0x180);
  if (_FileHandle < 1) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res10);
    pcVar1 = (char *)GetSorResStringEx(0x597);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res10,pcVar1,
               param_1);
    MMAfxMessageBox(local_res10[0],0,-1,0);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res10);
    return 0;
  }
  _close(_FileHandle);
  return 1;
}

/* RVA 0x26150 */
HRESULT FUN_180026150(IUnknown *param_1,IID *param_2,void **param_3)

{
  HRESULT HVar1;
  
  HVar1 = (*param_1->lpVtbl[6].QueryInterface)(param_1,param_2,param_3);
  if (HVar1 < 0) {
    _com_issue_errorex(HVar1,param_1,(_GUID *)&DAT_1800424d8);
  }
  return HVar1;
}

/* RVA 0x26190 */
undefined8 *
FUN_180026190(IUnknown *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
             undefined8 param_5,undefined8 *param_6)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[8].AddRef)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_1800424d8);
  }
  *param_2 = 0;
  FUN_18001ccd0(param_3);
  FUN_18001ccd0(param_4);
  FUN_18001ccd0(param_6);
  return param_2;
}

/* RVA 0x26260 */
undefined8 *
FUN_180026260(IUnknown *param_1,undefined8 *param_2,longlong *param_3,longlong *param_4,
             undefined8 *param_5)

{
  HRESULT HVar1;
  IID *riid;
  void **ppvObject;
  
  riid = (IID *)0x0;
  if ((undefined8 *)*param_4 == (undefined8 *)0x0) {
    ppvObject = (void **)0x0;
  }
  else {
    ppvObject = *(void ***)*param_4;
  }
  if ((undefined8 *)*param_3 != (undefined8 *)0x0) {
    riid = *(IID **)*param_3;
  }
  HVar1 = (*param_1->lpVtbl[8].QueryInterface)(param_1,riid,ppvObject);
  if (HVar1 < 0) {
    _com_issue_errorex(HVar1,param_1,(_GUID *)&DAT_1800424d8);
  }
  *param_2 = 0;
  FUN_18001ccd0(param_3);
  FUN_18001ccd0(param_4);
  FUN_18001ccd0(param_5);
  return param_2;
}

/* RVA 0x26330 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

BOOL FUN_180026330(LPCSTR param_1)

{
  char cVar1;
  longlong lVar2;
  BOOL BVar3;
  DWORD DVar4;
  HANDLE hFindFile;
  undefined1 *puVar5;
  undefined2 *puVar6;
  char *pcVar7;
  undefined2 *puVar8;
  longlong lVar9;
  undefined1 auStack_398 [32];
  undefined1 local_378 [320];
  CHAR local_238 [271];
  undefined2 uStack_129;
  undefined1 local_126 [270];
  ulonglong local_18;
  
  local_18 = DAT_180052888 ^ (ulonglong)auStack_398;
  pcVar7 = param_1;
  do {
    cVar1 = *pcVar7;
    pcVar7[(longlong)(local_238 + (0x110 - (longlong)param_1))] = cVar1;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  puVar8 = &uStack_129;
  do {
    puVar6 = puVar8;
    puVar8 = (undefined2 *)((longlong)puVar6 + 1);
  } while (*(char *)((longlong)puVar6 + 1) != '\0');
  *(undefined2 *)((longlong)puVar6 + 1) = DAT_180041ed0;
  *(undefined1 *)((longlong)puVar6 + 3) = DAT_180041ed2;
  pcVar7 = param_1;
  do {
    cVar1 = *pcVar7;
    pcVar7[(longlong)(local_238 + -(longlong)param_1)] = cVar1;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  puVar8 = (undefined2 *)(local_378 + 0x13f);
  do {
    pcVar7 = (char *)((longlong)puVar8 + 1);
    puVar8 = (undefined2 *)((longlong)puVar8 + 1);
  } while (*pcVar7 != '\0');
  *puVar8 = DAT_1800409c4;
  hFindFile = FindFirstFileA((LPCSTR)((longlong)&uStack_129 + 1),(LPWIN32_FIND_DATAA)local_378);
  if (hFindFile != (HANDLE)0xffffffffffffffff) {
    lVar9 = 0;
    do {
      pcVar7 = local_238 + lVar9;
      local_238[lVar9 + 0x110] = *pcVar7;
      lVar9 = lVar9 + 1;
    } while (*pcVar7 != '\0');
    while (BVar3 = FindNextFileA(hFindFile,(LPWIN32_FIND_DATAA)local_378), BVar3 != 0) {
      if ((local_378[0x2c] != '.') ||
         ((local_378[0x2d] != '\0' && ((local_378[0x2d] != '.' || (local_378[0x2e] != '\0')))))) {
        puVar5 = local_378 + 0x13f;
        do {
          pcVar7 = puVar5 + 1;
          puVar5 = puVar5 + 1;
        } while (*pcVar7 != '\0');
        lVar9 = 0;
        do {
          cVar1 = local_378[lVar9 + 0x2c];
          puVar5[lVar9] = cVar1;
          lVar9 = lVar9 + 1;
        } while (cVar1 != '\0');
        if ((local_378[0] & 0x10) == 0) {
          DeleteFileA(local_238);
          lVar9 = 0;
          do {
            lVar2 = lVar9 + 0x110;
            local_238[lVar9] = local_238[lVar2];
            lVar9 = lVar9 + 1;
          } while (local_238[lVar2] != '\0');
        }
        else {
          FUN_180026330(local_238);
          RemoveDirectoryA(local_238);
          lVar9 = 0;
          do {
            lVar2 = lVar9 + 0x110;
            local_238[lVar9] = local_238[lVar2];
            lVar9 = lVar9 + 1;
          } while (local_238[lVar2] != '\0');
        }
      }
    }
    DVar4 = GetLastError();
    if (DVar4 == 0x12) {
      FindClose(hFindFile);
      BVar3 = RemoveDirectoryA(param_1);
      return BVar3;
    }
    FindClose(hFindFile);
  }
  return 0;
}

/* RVA 0x26570 */
undefined2 FUN_180026570(IUnknown *param_1,undefined8 *param_2)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[9].AddRef)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_1800424d8);
  }
  FUN_18001ccd0(param_2);
  return 0;
}

/* RVA 0x265e0 */
void FUN_1800265e0(void)

{
  CFutilit(FUN_180026c60,1);
  return;
}

/* RVA 0x26600 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_180026600(char *param_1,LPCSTR param_2,void **param_3,ulonglong param_4)

{
  int *piVar1;
  void *pvVar2;
  longlong *plVar3;
  short sVar4;
  HRESULT HVar5;
  int iVar6;
  char *pcVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  undefined8 *puVar10;
  BSTR pOVar11;
  void *pvVar12;
  LPCSTR lpPathName;
  IID *pIVar13;
  IID *pIVar14;
  longlong *plVar15;
  void **ppvVar16;
  undefined4 uVar17;
  undefined1 auStackY_708 [32];
  IID *local_6b8;
  char *local_6b0;
  short local_6a8;
  short local_6a4 [2];
  char *local_6a0;
  undefined8 *local_698;
  undefined8 **local_690;
  ulonglong local_688;
  undefined8 local_680;
  undefined8 *local_678;
  undefined8 *local_670;
  undefined8 *local_668;
  wchar_t local_660 [4];
  wchar_t local_658 [256];
  wchar_t local_458 [256];
  wchar_t local_258 [256];
  ulonglong local_58;
  
  local_58 = DAT_180052888 ^ (ulonglong)auStackY_708;
  local_6b8 = (IID *)0x0;
  local_680 = 0;
  ppvVar16 = param_3;
  local_688 = param_4;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6b0);
  HVar5 = FUN_18002c9d0(&local_6b8,param_2);
  if (HVar5 < 0) {
    pcVar7 = (char *)GetSorResStringEx(0x585);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6b0,pcVar7);
    MMAfxMessageBox(local_6b0,0,-1,0);
    uVar17 = 1;
    goto LAB_180026bf1;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6a0);
  uVar17 = 1;
  if (param_1 == (char *)0x0) {
    puVar10 = operator_new(0x18);
    local_698 = puVar10;
    if (puVar10 == (undefined8 *)0x0) {
      puVar10 = (undefined8 *)0x0;
    }
    else {
      puVar10[1] = 0;
      *(undefined4 *)(puVar10 + 2) = 1;
      pOVar11 = FUN_180034c50((LPCSTR)param_3);
      *puVar10 = pOVar11;
    }
    local_678 = puVar10;
    if (puVar10 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_180034a60(0x8007000e);
    }
    _wsplitpath_s((wchar_t *)*puVar10,local_660,3,local_658,0x100,local_458,0x100,local_258,0x100);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6a0,local_660
              );
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6a0,local_658
              );
    puVar8 = operator_new(0x18);
    local_698 = puVar8;
    if (puVar8 == (undefined8 *)0x0) {
      puVar8 = (undefined8 *)0x0;
    }
    else {
      puVar8[1] = 0;
      *(undefined4 *)(puVar8 + 2) = 1;
      pOVar11 = FUN_180034c50(param_2);
      *puVar8 = pOVar11;
    }
    local_670 = puVar8;
    if (puVar8 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_180034a60(0x8007000e);
    }
    ppvVar16 = (void **)0x3;
    _wsplitpath_s((wchar_t *)*puVar8,local_660,3,local_658,0x100,local_458,0x100,local_258,0x100);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6a0,local_458
              );
    iVar6 = FUN_180033bd0();
    param_1 = ".apropz";
    if (iVar6 == 1) {
      param_1 = ".apwz";
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6a0,param_1);
    LOCK();
    piVar1 = (int *)(puVar8 + 2);
    iVar6 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar6 == 1) {
      if ((BSTR)*puVar8 != (BSTR)0x0) {
        SysFreeString((BSTR)*puVar8);
        *puVar8 = 0;
      }
      if ((void *)puVar8[1] != (void *)0x0) {
        operator_delete__((void *)puVar8[1]);
        puVar8[1] = 0;
      }
      param_1 = (char *)0x18;
      FUN_180035134(puVar8);
    }
    LOCK();
    piVar1 = (int *)(puVar10 + 2);
    iVar6 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar6 == 1) {
      if ((BSTR)*puVar10 != (BSTR)0x0) {
        SysFreeString((BSTR)*puVar10);
        *puVar10 = 0;
      }
      if ((void *)puVar10[1] != (void *)0x0) {
        operator_delete__((void *)puVar10[1]);
        puVar10[1] = 0;
      }
      param_1 = (char *)0x18;
      FUN_180035134(puVar10);
    }
  }
  else {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6a0,param_1);
  }
  uVar9 = FUN_1800260d0(local_6a0);
  pIVar13 = local_6b8;
  if ((short)uVar9 == 0) {
    iVar6 = (**(code **)(*(longlong *)local_6b8 + 0x90))(local_6b8);
    if (iVar6 < 0) {
      _com_issue_errorex(iVar6,(IUnknown *)pIVar13,(_GUID *)&DAT_1800424d8);
    }
  }
  else {
    FUN_180031650((IUnknown *)local_6b8,param_1,ppvVar16);
    pcVar7 = local_6a0;
    puVar10 = operator_new(0x18);
    local_698 = puVar10;
    if (puVar10 == (undefined8 *)0x0) {
      puVar10 = (undefined8 *)0x0;
    }
    else {
      puVar10[1] = 0;
      *(undefined4 *)(puVar10 + 2) = 1;
      pOVar11 = FUN_180034c50(pcVar7);
      *puVar10 = pOVar11;
    }
    pIVar13 = local_6b8;
    local_668 = puVar10;
    if (puVar10 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_180034a60(0x8007000e);
    }
    LOCK();
    *(int *)(puVar10 + 2) = *(int *)(puVar10 + 2) + 1;
    UNLOCK();
    local_690 = &local_698;
    local_6a8 = 0;
    if (puVar10 == (undefined8 *)0x0) {
      uVar9 = 0;
    }
    else {
      uVar9 = *puVar10;
    }
    local_698 = puVar10;
    iVar6 = (**(code **)(*(longlong *)local_6b8 + 0x100))(local_6b8,uVar9,4);
    if (iVar6 < 0) {
      _com_issue_errorex(iVar6,(IUnknown *)pIVar13,(_GUID *)&DAT_1800424d8);
    }
    sVar4 = local_6a8;
    FUN_18001ccd0(&local_698);
    if (sVar4 == 0) {
      pcVar7 = (char *)GetSorResStringEx(0x586);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6b0,pcVar7,
                 local_6a0);
LAB_180026b65:
      ppvVar16 = (void **)0xffffffff;
      pIVar13 = (IID *)0x0;
      MMAfxMessageBox(local_6b0,0,-1,0);
      FUN_180026150((IUnknown *)local_6b8,pIVar13,ppvVar16);
    }
    else {
      uVar9 = FUN_18002fa70((IUnknown *)local_6b8,param_2,(char *)param_3);
      plVar3 = DAT_180054098;
      if ((short)uVar9 == 0) {
        uVar9 = 0x587;
LAB_180026b51:
        pcVar7 = (char *)GetSorResStringEx(uVar9);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6b0,
                   pcVar7);
        goto LAB_180026b65;
      }
      plVar15 = DAT_180054090;
      if (DAT_180054090 != DAT_180054098) {
        do {
          if (0xf < (ulonglong)plVar15[3]) {
            pvVar2 = (void *)*plVar15;
            pvVar12 = pvVar2;
            if ((0xfff < plVar15[3] + 1U) &&
               (pvVar12 = *(void **)((longlong)pvVar2 + -8),
               0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar12)))) {
                    /* WARNING: Subroutine does not return */
              _invalid_parameter_noinfo_noreturn();
            }
            FUN_180035134(pvVar12);
          }
          plVar15[2] = 0;
          plVar15[3] = 0xf;
          *(undefined1 *)plVar15 = 0;
          plVar15 = plVar15 + 4;
        } while (plVar15 != plVar3);
        DAT_180054098 = DAT_180054090;
      }
      CFutilit(FUN_180026c60,0);
      CfNonRegistrySettings(FUN_180026c60);
      iVar6 = FUN_180033bd0();
      if (iVar6 == 1) {
        FUN_180032010((IUnknown *)local_6b8);
      }
      uVar9 = FUN_1800301e0((IUnknown *)local_6b8);
      if ((short)uVar9 == 0) {
        uVar9 = 0x588;
LAB_180026ad4:
        pcVar7 = (char *)GetSorResStringEx(uVar9);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6b0,
                   pcVar7);
        ppvVar16 = (void **)0xffffffff;
        pIVar13 = (IID *)0x0;
        MMAfxMessageBox(local_6b0,0,-1,0);
        FUN_180026150((IUnknown *)local_6b8,pIVar13,ppvVar16);
      }
      else {
        ppvVar16 = param_3;
        uVar9 = FUN_18002e010((IUnknown *)local_6b8,param_2,(char *)param_3);
        if ((short)uVar9 == 0) {
          uVar9 = 0x589;
          goto LAB_180026ad4;
        }
        uVar9 = FUN_18002ccc0((IUnknown *)local_6b8,(char *)param_3,ppvVar16);
        pIVar13 = local_6b8;
        if ((short)uVar9 == 0) {
          uVar9 = 0x822;
          goto LAB_180026ad4;
        }
        local_6a4[0] = 0;
        ppvVar16 = (void **)local_6a4;
        pIVar14 = (IID *)(local_688 & 0xffffffff);
        iVar6 = (**(code **)(*(longlong *)local_6b8 + 0x120))(local_6b8);
        if (iVar6 < 0) {
          ppvVar16 = (void **)&DAT_1800424d8;
          _com_issue_errorex(iVar6,(IUnknown *)pIVar13,(_GUID *)&DAT_1800424d8);
          pIVar14 = pIVar13;
        }
        if (local_6a4[0] < 0) {
          uVar9 = 0x58c;
          goto LAB_180026b51;
        }
        lpPathName = DAT_1800540c0;
        if (*(int *)(DAT_1800540c0 + -0x10) == 0) {
          lpPathName = DAT_1800540b0;
        }
        SetCurrentDirectoryA(lpPathName);
        FUN_180026150((IUnknown *)local_6b8,pIVar14,ppvVar16);
        uVar17 = 0;
      }
    }
    LOCK();
    piVar1 = (int *)(puVar10 + 2);
    iVar6 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar6 == 1) {
      if ((BSTR)*puVar10 != (BSTR)0x0) {
        SysFreeString((BSTR)*puVar10);
        *puVar10 = 0;
      }
      if ((void *)puVar10[1] != (void *)0x0) {
        operator_delete__((void *)puVar10[1]);
        puVar10[1] = 0;
      }
      FUN_180035134(puVar10);
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6a0);
LAB_180026bf1:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6b0);
  if (local_6b8 != (IID *)0x0) {
    (**(code **)(*(longlong *)local_6b8 + 0x10))();
  }
  return uVar17;
}

/* RVA 0x26c60 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180026c60(char *param_1)

{
  longlong *plVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  BOOL BVar6;
  int iVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar10;
  IAtlStringMgr *pIVar11;
  char *pcVar12;
  HANDLE pvVar13;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar14;
  CSimpleStringT<char,1> *this;
  char *pcVar15;
  void *pvVar16;
  ulonglong uVar17;
  longlong lVar18;
  size_t sVar19;
  bool bVar20;
  undefined1 auStackY_358 [32];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_328 [8];
  char *local_320;
  undefined4 local_318;
  longlong local_310;
  int local_308;
  undefined4 uStack_304;
  int local_300;
  undefined4 uStack_2fc;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_2f8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_2f0 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_2e8 [8];
  char *local_2e0;
  CStdioFile local_2d8 [48];
  void *local_2a8;
  longlong lStack_2a0;
  undefined8 local_298;
  undefined8 uStack_290;
  _WIN32_FIND_DATAA local_288;
  char local_148 [272];
  ulonglong local_38;
  
  local_38 = DAT_180052888 ^ (ulonglong)auStackY_358;
  local_318 = 0;
  local_2e0 = param_1;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_2f0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_310,param_1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_2e8);
  bVar20 = false;
  uVar8 = FUN_180029600("streamformat");
  local_300 = (int)uVar8;
  uVar8 = FUN_180029600("usermodelfile");
  uVar9 = FUN_180029600("fortranfile");
  iVar7 = (int)uVar9;
  local_308 = iVar7;
  iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_310,'.'
                    );
  if (iVar4 == -1) {
    pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                        ((CSimpleStringT<char,1> *)&local_310);
    lVar18 = -1;
    do {
      lVar18 = lVar18 + 1;
    } while (pcVar12[lVar18] != '\0');
    iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_310,
                       '\\');
    if (lVar18 != iVar4 + 1) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_310,"\\");
    }
    if ((int)uVar8 != 0) {
      pIVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_310);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320,pIVar11
                );
      local_318 = 0x80000;
      iVar7 = ATL::CSimpleStringT<char,1>::StringLength("*.ini");
      iVar4 = ATL::CSimpleStringT<char,1>::GetLength((CSimpleStringT<char,1> *)&local_310);
      pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                          ((CSimpleStringT<char,1> *)&local_310);
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)&local_320,pcVar12,iVar4,"*.ini",iVar7);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                (local_2f0,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 &local_320);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320);
      pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                          ((CSimpleStringT<char,1> *)local_2f0);
      pvVar13 = FindFirstFileA(pcVar12,&local_288);
      if (pvVar13 != (HANDLE)0xffffffffffffffff) {
        while( true ) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320,
                     local_288.cFileName);
          pIVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &local_310);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328,pIVar11);
          local_318 = 0x80;
          iVar7 = ATL::CSimpleStringT<char,1>::GetLength((CSimpleStringT<char,1> *)&local_320);
          pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                              ((CSimpleStringT<char,1> *)&local_320);
          iVar4 = ATL::CSimpleStringT<char,1>::GetLength((CSimpleStringT<char,1> *)&local_310);
          pcVar15 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                              ((CSimpleStringT<char,1> *)&local_310);
          ATL::CSimpleStringT<char,1>::Concatenate
                    ((CSimpleStringT<char,1> *)local_328,pcVar15,iVar4,pcVar12,iVar7);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320,
                     (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     local_328);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328);
          pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                              ((CSimpleStringT<char,1> *)&local_320);
          local_2a8 = (void *)0x0;
          lStack_2a0 = 0;
          local_298 = 0;
          uStack_290 = 0;
          sVar19 = 0xffffffffffffffff;
          do {
            sVar19 = sVar19 + 1;
          } while (pcVar12[sVar19] != '\0');
          FUN_180006e90(&local_2a8,pcVar12,sVar19);
          plVar1 = DAT_180054098;
          if (DAT_180054098 == DAT_1800540a0) {
            FUN_1800077a0(&DAT_180054090,DAT_180054098,&local_2a8);
            uVar17 = uStack_290;
          }
          else {
            *DAT_180054098 = (longlong)local_2a8;
            plVar1[1] = lStack_2a0;
            *(undefined4 *)(plVar1 + 2) = (undefined4)local_298;
            *(undefined4 *)((longlong)plVar1 + 0x14) = local_298._4_4_;
            *(undefined4 *)(plVar1 + 3) = (undefined4)uStack_290;
            *(undefined4 *)((longlong)plVar1 + 0x1c) = uStack_290._4_4_;
            local_2a8 = (void *)((ulonglong)local_2a8 & 0xffffffffffffff00);
            DAT_180054098 = DAT_180054098 + 4;
            uVar17 = 0xf;
          }
          if (0xf < uVar17) {
            pvVar16 = local_2a8;
            if ((0xfff < uVar17 + 1) &&
               (pvVar16 = *(void **)((longlong)local_2a8 + -8),
               0x1f < (ulonglong)((longlong)local_2a8 + (-8 - (longlong)pvVar16)))) {
                    /* WARNING: Subroutine does not return */
              _invalid_parameter_noinfo_noreturn();
            }
            FUN_180035134(pvVar16);
          }
          BVar6 = FindNextFileA(pvVar13,&local_288);
          if (BVar6 == 0) break;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320);
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320);
      }
      FindClose(pvVar13);
      pIVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_310);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328,pIVar11);
      local_318 = 0x20000;
      iVar7 = ATL::CSimpleStringT<char,1>::StringLength("*.cfg");
      iVar4 = ATL::CSimpleStringT<char,1>::GetLength((CSimpleStringT<char,1> *)&local_310);
      pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                          ((CSimpleStringT<char,1> *)&local_310);
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)local_328,pcVar12,iVar4,"*.cfg",iVar7);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                (local_2f0,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 local_328);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328);
      pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                          ((CSimpleStringT<char,1> *)local_2f0);
      pvVar13 = FindFirstFileA(pcVar12,&local_288);
      if (pvVar13 != (HANDLE)0xffffffffffffffff) {
        while( true ) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320,
                     local_288.cFileName);
          pIVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &local_310);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328,pIVar11);
          local_318 = 0x200;
          iVar7 = ATL::CSimpleStringT<char,1>::GetLength((CSimpleStringT<char,1> *)&local_320);
          pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                              ((CSimpleStringT<char,1> *)&local_320);
          iVar4 = ATL::CSimpleStringT<char,1>::GetLength((CSimpleStringT<char,1> *)&local_310);
          pcVar15 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                              ((CSimpleStringT<char,1> *)&local_310);
          ATL::CSimpleStringT<char,1>::Concatenate
                    ((CSimpleStringT<char,1> *)local_328,pcVar15,iVar4,pcVar12,iVar7);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320,
                     (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     local_328);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328);
          pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                              ((CSimpleStringT<char,1> *)&local_320);
          local_2a8 = (void *)0x0;
          lStack_2a0 = 0;
          local_298 = 0;
          uStack_290 = 0;
          sVar19 = 0xffffffffffffffff;
          do {
            sVar19 = sVar19 + 1;
          } while (pcVar12[sVar19] != '\0');
          FUN_180006e90(&local_2a8,pcVar12,sVar19);
          plVar1 = DAT_180054098;
          if (DAT_180054098 == DAT_1800540a0) {
            FUN_1800077a0(&DAT_180054090,DAT_180054098,&local_2a8);
            uVar17 = uStack_290;
          }
          else {
            *DAT_180054098 = (longlong)local_2a8;
            plVar1[1] = lStack_2a0;
            *(undefined4 *)(plVar1 + 2) = (undefined4)local_298;
            *(undefined4 *)((longlong)plVar1 + 0x14) = local_298._4_4_;
            *(undefined4 *)(plVar1 + 3) = (undefined4)uStack_290;
            *(undefined4 *)((longlong)plVar1 + 0x1c) = uStack_290._4_4_;
            local_2a8 = (void *)((ulonglong)local_2a8 & 0xffffffffffffff00);
            DAT_180054098 = DAT_180054098 + 4;
            uVar17 = 0xf;
          }
          if (0xf < uVar17) {
            pvVar16 = local_2a8;
            if ((0xfff < uVar17 + 1) &&
               (pvVar16 = *(void **)((longlong)local_2a8 + -8),
               0x1f < (ulonglong)((longlong)local_2a8 + (-8 - (longlong)pvVar16)))) {
                    /* WARNING: Subroutine does not return */
              _invalid_parameter_noinfo_noreturn();
            }
            FUN_180035134(pvVar16);
          }
          BVar6 = FindNextFileA(pvVar13,&local_288);
          if (BVar6 == 0) break;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320);
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320);
      }
      FindClose(pvVar13);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_310,"");
      bVar20 = true;
      iVar7 = local_308;
      goto LAB_180027225;
    }
  }
  else {
    pCVar10 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_310
                         ,(int)local_2f8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(local_2e8,pCVar10)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_2f8);
LAB_180027225:
    if (((int)uVar8 != 0) && (!bVar20)) {
      pIVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &DAT_1800540b8);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328,pIVar11);
      local_318 = 0x40000;
      iVar4 = ATL::CSimpleStringT<char,1>::StringLength("*.ini");
      iVar5 = ATL::CSimpleStringT<char,1>::GetLength((CSimpleStringT<char,1> *)&DAT_1800540b8);
      pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                          ((CSimpleStringT<char,1> *)&DAT_1800540b8);
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)local_328,pcVar12,iVar5,"*.ini",iVar4);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                (local_2f0,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 local_328);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328);
      pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                          ((CSimpleStringT<char,1> *)local_2f0);
      pvVar13 = FindFirstFileA(pcVar12,&local_288);
      if (pvVar13 != (HANDLE)0xffffffffffffffff) {
        while( true ) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320,
                     local_288.cFileName);
          pIVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &DAT_1800540b8);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328,pIVar11);
          local_318 = 0x20;
          ATL::CSimpleStringT<char,1>::Concatenate
                    ((CSimpleStringT<char,1> *)local_328,DAT_1800540b8,
                     *(int *)(DAT_1800540b8 + -0x10),local_320,*(int *)(local_320 + -0x10));
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320,
                     (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     local_328);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328);
          local_2a8 = (void *)0x0;
          lStack_2a0 = 0;
          local_298 = 0;
          uStack_290 = 0;
          sVar19 = 0xffffffffffffffff;
          do {
            sVar19 = sVar19 + 1;
          } while (local_320[sVar19] != '\0');
          FUN_180006e90(&local_2a8,local_320,sVar19);
          plVar1 = DAT_180054098;
          if (DAT_180054098 == DAT_1800540a0) {
            FUN_1800077a0(&DAT_180054090,DAT_180054098,&local_2a8);
            uVar17 = uStack_290;
          }
          else {
            *DAT_180054098 = (longlong)local_2a8;
            plVar1[1] = lStack_2a0;
            *(undefined4 *)(plVar1 + 2) = (undefined4)local_298;
            *(undefined4 *)((longlong)plVar1 + 0x14) = local_298._4_4_;
            *(undefined4 *)(plVar1 + 3) = (undefined4)uStack_290;
            *(undefined4 *)((longlong)plVar1 + 0x1c) = uStack_290._4_4_;
            local_2a8 = (void *)((ulonglong)local_2a8 & 0xffffffffffffff00);
            DAT_180054098 = DAT_180054098 + 4;
            uVar17 = 0xf;
          }
          if (0xf < uVar17) {
            pvVar16 = local_2a8;
            if ((0xfff < uVar17 + 1) &&
               (pvVar16 = *(void **)((longlong)local_2a8 + -8),
               0x1f < (ulonglong)((longlong)local_2a8 + (-8 - (longlong)pvVar16)))) {
                    /* WARNING: Subroutine does not return */
              _invalid_parameter_noinfo_noreturn();
            }
            FUN_180035134(pvVar16);
          }
          BVar6 = FindNextFileA(pvVar13,&local_288);
          if (BVar6 == 0) break;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320);
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320);
      }
      FindClose(pvVar13);
      pIVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &DAT_1800540b8);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328,pIVar11);
      local_318 = 0x100000;
      iVar4 = ATL::CSimpleStringT<char,1>::StringLength("*.cfg");
      iVar5 = ATL::CSimpleStringT<char,1>::GetLength((CSimpleStringT<char,1> *)&DAT_1800540b8);
      pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                          ((CSimpleStringT<char,1> *)&DAT_1800540b8);
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)local_328,pcVar12,iVar5,"*.cfg",iVar4);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                (local_2f0,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 local_328);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328);
      pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                          ((CSimpleStringT<char,1> *)local_2f0);
      pvVar13 = FindFirstFileA(pcVar12,&local_288);
      if (pvVar13 != (HANDLE)0xffffffffffffffff) {
        while( true ) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320,
                     local_288.cFileName);
          pIVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &DAT_1800540b8);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328,pIVar11);
          local_318 = 0x10;
          ATL::CSimpleStringT<char,1>::Concatenate
                    ((CSimpleStringT<char,1> *)local_328,DAT_1800540b8,
                     *(int *)(DAT_1800540b8 + -0x10),local_320,*(int *)(local_320 + -0x10));
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320,
                     (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     local_328);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328);
          pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                              ((CSimpleStringT<char,1> *)&local_320);
          local_2a8 = (void *)0x0;
          lStack_2a0 = 0;
          local_298 = 0;
          uStack_290 = 0;
          sVar19 = 0xffffffffffffffff;
          do {
            sVar19 = sVar19 + 1;
          } while (pcVar12[sVar19] != '\0');
          FUN_180006e90(&local_2a8,pcVar12,sVar19);
          plVar1 = DAT_180054098;
          if (DAT_180054098 == DAT_1800540a0) {
            FUN_1800077a0(&DAT_180054090,DAT_180054098,&local_2a8);
            uVar17 = uStack_290;
          }
          else {
            *DAT_180054098 = (longlong)local_2a8;
            plVar1[1] = lStack_2a0;
            *(undefined4 *)(plVar1 + 2) = (undefined4)local_298;
            *(undefined4 *)((longlong)plVar1 + 0x14) = local_298._4_4_;
            *(undefined4 *)(plVar1 + 3) = (undefined4)uStack_290;
            *(undefined4 *)((longlong)plVar1 + 0x1c) = uStack_290._4_4_;
            local_2a8 = (void *)((ulonglong)local_2a8 & 0xffffffffffffff00);
            DAT_180054098 = DAT_180054098 + 4;
            uVar17 = 0xf;
          }
          if (0xf < uVar17) {
            pvVar16 = local_2a8;
            if ((0xfff < uVar17 + 1) &&
               (pvVar16 = *(void **)((longlong)local_2a8 + -8),
               0x1f < (ulonglong)((longlong)local_2a8 + (-8 - (longlong)pvVar16)))) {
                    /* WARNING: Subroutine does not return */
              _invalid_parameter_noinfo_noreturn();
            }
            FUN_180035134(pvVar16);
          }
          BVar6 = FindNextFileA(pvVar13,&local_288);
          if (BVar6 == 0) break;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320);
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320);
      }
      FindClose(pvVar13);
    }
  }
  if (iVar7 != 0) {
    pIVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         &DAT_1800540b8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328,pIVar11);
    local_318 = 0x1000;
    iVar7 = ATL::CSimpleStringT<char,1>::StringLength("*.f");
    iVar4 = ATL::CSimpleStringT<char,1>::GetLength((CSimpleStringT<char,1> *)&DAT_1800540b8);
    pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                        ((CSimpleStringT<char,1> *)&DAT_1800540b8);
    ATL::CSimpleStringT<char,1>::Concatenate
              ((CSimpleStringT<char,1> *)local_328,pcVar12,iVar4,"*.f",iVar7);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              (local_2f0,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               local_328);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328);
    pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                        ((CSimpleStringT<char,1> *)local_2f0);
    pvVar13 = FindFirstFileA(pcVar12,&local_288);
    if (pvVar13 != (HANDLE)0xffffffffffffffff) {
      do {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_308,
                   local_288.cFileName);
        iVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_308,'.');
        if ((iVar7 == 8) &&
           (cVar2 = ATL::CSimpleStringT<char,1>::operator[]((CSimpleStringT<char,1> *)&local_308,0),
           cVar2 == '_')) {
          iVar7 = 1;
          do {
            cVar2 = ATL::CSimpleStringT<char,1>::operator[]
                              ((CSimpleStringT<char,1> *)&local_308,iVar7);
            iVar4 = isdigit((int)cVar2);
            if (iVar4 == 0) goto LAB_1800277b6;
            iVar7 = iVar7 + 1;
          } while (iVar7 < 5);
          iVar7 = 5;
          do {
            cVar2 = ATL::CSimpleStringT<char,1>::operator[]
                              ((CSimpleStringT<char,1> *)&local_308,iVar7);
            iVar4 = isalpha((int)cVar2);
            if (iVar4 == 0) goto LAB_1800277b6;
            iVar7 = iVar7 + 1;
          } while (iVar7 < 8);
        }
        else {
LAB_1800277b6:
          pIVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &DAT_1800540b8);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328,pIVar11);
          local_318 = 0x40;
          ATL::CSimpleStringT<char,1>::Concatenate
                    ((CSimpleStringT<char,1> *)local_328,DAT_1800540b8,
                     *(int *)(DAT_1800540b8 + -0x10),(char *)CONCAT44(uStack_304,local_308),
                     *(int *)((char *)CONCAT44(uStack_304,local_308) + -0x10));
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_308,
                     (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     local_328);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328);
          local_2a8 = (void *)0x0;
          lStack_2a0 = 0;
          local_298 = 0;
          uStack_290 = 0;
          sVar19 = 0xffffffffffffffff;
          do {
            sVar19 = sVar19 + 1;
          } while (*(char *)((longlong)CONCAT44(uStack_304,local_308) + sVar19) != '\0');
          FUN_180006e90(&local_2a8,(void *)CONCAT44(uStack_304,local_308),sVar19);
          plVar1 = DAT_180054098;
          if (DAT_180054098 == DAT_1800540a0) {
            FUN_1800077a0(&DAT_180054090,DAT_180054098,&local_2a8);
            uVar17 = uStack_290;
          }
          else {
            *DAT_180054098 = (longlong)local_2a8;
            plVar1[1] = lStack_2a0;
            *(undefined4 *)(plVar1 + 2) = (undefined4)local_298;
            *(undefined4 *)((longlong)plVar1 + 0x14) = local_298._4_4_;
            *(undefined4 *)(plVar1 + 3) = (undefined4)uStack_290;
            *(undefined4 *)((longlong)plVar1 + 0x1c) = uStack_290._4_4_;
            local_2a8 = (void *)((ulonglong)local_2a8 & 0xffffffffffffff00);
            DAT_180054098 = DAT_180054098 + 4;
            uVar17 = 0xf;
          }
          if (0xf < uVar17) {
            pvVar16 = local_2a8;
            if ((0xfff < uVar17 + 1) &&
               (pvVar16 = *(void **)((longlong)local_2a8 + -8),
               0x1f < (ulonglong)((longlong)local_2a8 + (-8 - (longlong)pvVar16)))) {
                    /* WARNING: Subroutine does not return */
              _invalid_parameter_noinfo_noreturn();
            }
            FUN_180035134(pvVar16);
          }
        }
        BVar6 = FindNextFileA(pvVar13,&local_288);
        if (BVar6 == 0) goto LAB_1800278e8;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_308);
      } while( true );
    }
    goto LAB_1800278ee;
  }
  goto LAB_180027dd5;
LAB_1800278e8:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_308);
LAB_1800278ee:
  FindClose(pvVar13);
  pIVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       &DAT_1800540b8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328,pIVar11);
  local_318 = 0x2000;
  iVar7 = ATL::CSimpleStringT<char,1>::StringLength("*.for");
  iVar4 = ATL::CSimpleStringT<char,1>::GetLength((CSimpleStringT<char,1> *)&DAT_1800540b8);
  pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                      ((CSimpleStringT<char,1> *)&DAT_1800540b8);
  ATL::CSimpleStringT<char,1>::Concatenate
            ((CSimpleStringT<char,1> *)local_328,pcVar12,iVar4,"*.for",iVar7);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            (local_2f0,
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)local_328)
  ;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328);
  pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                      ((CSimpleStringT<char,1> *)local_2f0);
  pvVar13 = FindFirstFileA(pcVar12,&local_288);
  if (pvVar13 != (HANDLE)0xffffffffffffffff) {
    do {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_308,
                 local_288.cFileName);
      iVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_308
                         ,'.');
      if ((iVar7 == 8) &&
         (cVar2 = ATL::CSimpleStringT<char,1>::operator[]((CSimpleStringT<char,1> *)&local_308,0),
         cVar2 == '_')) {
        iVar7 = 1;
        do {
          cVar2 = ATL::CSimpleStringT<char,1>::operator[]
                            ((CSimpleStringT<char,1> *)&local_308,iVar7);
          iVar4 = isdigit((int)cVar2);
          if (iVar4 == 0) goto LAB_180027a46;
          iVar7 = iVar7 + 1;
        } while (iVar7 < 5);
        iVar7 = 5;
        do {
          cVar2 = ATL::CSimpleStringT<char,1>::operator[]
                            ((CSimpleStringT<char,1> *)&local_308,iVar7);
          iVar4 = isalpha((int)cVar2);
          if (iVar4 == 0) goto LAB_180027a46;
          iVar7 = iVar7 + 1;
        } while (iVar7 < 8);
      }
      else {
LAB_180027a46:
        pIVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &DAT_1800540b8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328,pIVar11);
        local_318 = 0x100;
        iVar7 = ATL::CSimpleStringT<char,1>::GetLength((CSimpleStringT<char,1> *)&local_308);
        pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                            ((CSimpleStringT<char,1> *)&local_308);
        iVar4 = ATL::CSimpleStringT<char,1>::GetLength((CSimpleStringT<char,1> *)&DAT_1800540b8);
        pcVar15 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                            ((CSimpleStringT<char,1> *)&DAT_1800540b8);
        ATL::CSimpleStringT<char,1>::Concatenate
                  ((CSimpleStringT<char,1> *)local_328,pcVar15,iVar4,pcVar12,iVar7);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_308,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   local_328);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328);
        pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                            ((CSimpleStringT<char,1> *)&local_308);
        local_2a8 = (void *)0x0;
        lStack_2a0 = 0;
        local_298 = 0;
        uStack_290 = 0;
        sVar19 = 0xffffffffffffffff;
        do {
          sVar19 = sVar19 + 1;
        } while (pcVar12[sVar19] != '\0');
        FUN_180006e90(&local_2a8,pcVar12,sVar19);
        plVar1 = DAT_180054098;
        if (DAT_180054098 == DAT_1800540a0) {
          FUN_1800077a0(&DAT_180054090,DAT_180054098,&local_2a8);
          uVar17 = uStack_290;
        }
        else {
          *DAT_180054098 = (longlong)local_2a8;
          plVar1[1] = lStack_2a0;
          *(undefined4 *)(plVar1 + 2) = (undefined4)local_298;
          *(undefined4 *)((longlong)plVar1 + 0x14) = local_298._4_4_;
          *(undefined4 *)(plVar1 + 3) = (undefined4)uStack_290;
          *(undefined4 *)((longlong)plVar1 + 0x1c) = uStack_290._4_4_;
          local_2a8 = (void *)((ulonglong)local_2a8 & 0xffffffffffffff00);
          DAT_180054098 = DAT_180054098 + 4;
          uVar17 = 0xf;
        }
        if (0xf < uVar17) {
          pvVar16 = local_2a8;
          if ((0xfff < uVar17 + 1) &&
             (pvVar16 = *(void **)((longlong)local_2a8 + -8),
             0x1f < (ulonglong)((longlong)local_2a8 + (-8 - (longlong)pvVar16)))) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
          FUN_180035134(pvVar16);
        }
      }
      BVar6 = FindNextFileA(pvVar13,&local_288);
      if (BVar6 == 0) goto LAB_180027bb6;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_308);
    } while( true );
  }
  goto LAB_180027bbc;
LAB_180027bb6:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_308);
LAB_180027bbc:
  FindClose(pvVar13);
  pIVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       &DAT_1800540b8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328,pIVar11);
  local_318 = 0x400;
  iVar7 = ATL::CSimpleStringT<char,1>::StringLength("*.obj");
  iVar4 = ATL::CSimpleStringT<char,1>::GetLength((CSimpleStringT<char,1> *)&DAT_1800540b8);
  pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                      ((CSimpleStringT<char,1> *)&DAT_1800540b8);
  ATL::CSimpleStringT<char,1>::Concatenate
            ((CSimpleStringT<char,1> *)local_328,pcVar12,iVar4,"*.obj",iVar7);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            (local_2f0,
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)local_328)
  ;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328);
  pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                      ((CSimpleStringT<char,1> *)local_2f0);
  pvVar13 = FindFirstFileA(pcVar12,&local_288);
  if (pvVar13 != (HANDLE)0xffffffffffffffff) {
    while( true ) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320,
                 local_288.cFileName);
      pIVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &DAT_1800540b8);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328,pIVar11);
      local_318 = 2;
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)local_328,DAT_1800540b8,*(int *)(DAT_1800540b8 + -0x10),
                 local_320,*(int *)(local_320 + -0x10));
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 local_328);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328);
      local_2a8 = (void *)0x0;
      lStack_2a0 = 0;
      local_298 = 0;
      uStack_290 = 0;
      sVar19 = 0xffffffffffffffff;
      do {
        sVar19 = sVar19 + 1;
      } while (local_320[sVar19] != '\0');
      FUN_180006e90(&local_2a8,local_320,sVar19);
      plVar1 = DAT_180054098;
      if (DAT_180054098 == DAT_1800540a0) {
        FUN_1800077a0(&DAT_180054090,DAT_180054098,&local_2a8);
        uVar17 = uStack_290;
      }
      else {
        *DAT_180054098 = (longlong)local_2a8;
        plVar1[1] = lStack_2a0;
        *(undefined4 *)(plVar1 + 2) = (undefined4)local_298;
        *(undefined4 *)((longlong)plVar1 + 0x14) = local_298._4_4_;
        *(undefined4 *)(plVar1 + 3) = (undefined4)uStack_290;
        *(undefined4 *)((longlong)plVar1 + 0x1c) = uStack_290._4_4_;
        local_2a8 = (void *)((ulonglong)local_2a8 & 0xffffffffffffff00);
        DAT_180054098 = DAT_180054098 + 4;
        uVar17 = 0xf;
      }
      if (0xf < uVar17) {
        pvVar16 = local_2a8;
        if ((0xfff < uVar17 + 1) &&
           (pvVar16 = *(void **)((longlong)local_2a8 + -8),
           0x1f < (ulonglong)((longlong)local_2a8 + (-8 - (longlong)pvVar16)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        FUN_180035134(pvVar16);
      }
      BVar6 = FindNextFileA(pvVar13,&local_288);
      if (BVar6 == 0) break;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320);
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320);
  }
  FindClose(pvVar13);
LAB_180027dd5:
  if (local_300 != 0) {
    pIVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         &DAT_1800540b8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328,pIVar11);
    local_318 = 0x800;
    iVar7 = ATL::CSimpleStringT<char,1>::StringLength("*.apcsv");
    iVar4 = ATL::CSimpleStringT<char,1>::GetLength((CSimpleStringT<char,1> *)&DAT_1800540b8);
    pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                        ((CSimpleStringT<char,1> *)&DAT_1800540b8);
    ATL::CSimpleStringT<char,1>::Concatenate
              ((CSimpleStringT<char,1> *)local_328,pcVar12,iVar4,"*.apcsv",iVar7);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              (local_2f0,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               local_328);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328);
    pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                        ((CSimpleStringT<char,1> *)local_2f0);
    pvVar13 = FindFirstFileA(pcVar12,&local_288);
    if (pvVar13 != (HANDLE)0xffffffffffffffff) {
      while( true ) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320,
                   local_288.cFileName);
        pIVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &DAT_1800540b8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328,pIVar11);
        local_318 = 1;
        ATL::CSimpleStringT<char,1>::Concatenate
                  ((CSimpleStringT<char,1> *)local_328,DAT_1800540b8,*(int *)(DAT_1800540b8 + -0x10)
                   ,local_320,*(int *)(local_320 + -0x10));
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   local_328);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328);
        local_2a8 = (void *)0x0;
        lStack_2a0 = 0;
        local_298 = 0;
        uStack_290 = 0;
        sVar19 = 0xffffffffffffffff;
        do {
          sVar19 = sVar19 + 1;
        } while (local_320[sVar19] != '\0');
        FUN_180006e90(&local_2a8,local_320,sVar19);
        plVar1 = DAT_180054098;
        if (DAT_180054098 == DAT_1800540a0) {
          FUN_1800077a0(&DAT_180054090,DAT_180054098,&local_2a8);
          uVar17 = uStack_290;
        }
        else {
          *DAT_180054098 = (longlong)local_2a8;
          plVar1[1] = lStack_2a0;
          *(undefined4 *)(plVar1 + 2) = (undefined4)local_298;
          *(undefined4 *)((longlong)plVar1 + 0x14) = local_298._4_4_;
          *(undefined4 *)(plVar1 + 3) = (undefined4)uStack_290;
          *(undefined4 *)((longlong)plVar1 + 0x1c) = uStack_290._4_4_;
          local_2a8 = (void *)((ulonglong)local_2a8 & 0xffffffffffffff00);
          DAT_180054098 = DAT_180054098 + 4;
          uVar17 = 0xf;
        }
        if (0xf < uVar17) {
          pvVar16 = local_2a8;
          if ((0xfff < uVar17 + 1) &&
             (pvVar16 = *(void **)((longlong)local_2a8 + -8),
             0x1f < (ulonglong)((longlong)local_2a8 + (-8 - (longlong)pvVar16)))) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
          FUN_180035134(pvVar16);
        }
        BVar6 = FindNextFileA(pvVar13,&local_288);
        if (BVar6 == 0) break;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320);
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320);
    }
    FindClose(pvVar13);
  }
  iVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_310,':'
                     ,0);
  if (iVar7 < 1) {
    iVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                      (local_2e8,"tff");
    if (iVar7 == 0) {
      pcVar12 = (char *)SEGetSettingValue("tffdir",0);
      if (pcVar12 == (char *)0x0) {
        pCVar14 = FUN_180001320(local_2f8,
                                (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                &DAT_1800540b8,&local_310);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_310,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   pCVar14);
        pCVar14 = local_2f8;
LAB_1800280b7:
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar14);
      }
      else if (*pcVar12 != '\0') {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328,pcVar12);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                  (local_328,"\\");
        pCVar14 = FUN_180001320(local_2f8,local_328,&local_310);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_310,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   pCVar14);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_2f8);
        pCVar14 = local_328;
        goto LAB_1800280b7;
      }
      pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                          ((CSimpleStringT<char,1> *)&local_310);
      pvVar13 = FindFirstFileA(pcVar12,&local_288);
      if (pvVar13 == (HANDLE)0xffffffffffffffff) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_310,"");
      }
      FindClose(pvVar13);
    }
    else {
      bVar20 = ATL::CSimpleStringT<char,1>::IsEmpty((CSimpleStringT<char,1> *)local_2e8);
      if ((!bVar20) &&
         ((iVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                             (local_2e8,"cfg"), iVar7 != 0 ||
          (iVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                             (local_2e8,"ini"), iVar7 != 0)))) {
        pCVar14 = FUN_180001320(local_2f8,
                                (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                &DAT_1800540b8,&local_310);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_310,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   pCVar14);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_2f8);
      }
    }
  }
  iVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                    (local_2e8,"opt");
  if ((iVar7 == 0) ||
     (iVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                        (local_2e8,"dlopt"), iVar7 == 0)) {
    CStdioFile::CStdioFile(local_2d8);
    pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                        ((CSimpleStringT<char,1> *)&local_310);
    iVar7 = CStdioFile::Open(local_2d8,pcVar12,0,(CFileException *)0x0);
    bVar20 = iVar7 != 0;
    if ((iVar7 == 0) &&
       (bVar3 = ATL::CSimpleStringT<char,1>::IsEmpty((CSimpleStringT<char,1> *)&DAT_180054088),
       !bVar3)) {
      ATL::CSimpleStringT<char,1>::GetLength((CSimpleStringT<char,1> *)&local_310);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_310,'\\');
      this = (CSimpleStringT<char,1> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Right
                       ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_310,
                        (int)local_2f8);
      pIVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &DAT_180054088);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320,pIVar11
                );
      local_318 = 0x200000;
      iVar7 = ATL::CSimpleStringT<char,1>::GetLength(this);
      pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64(this);
      iVar4 = ATL::CSimpleStringT<char,1>::GetLength((CSimpleStringT<char,1> *)&DAT_180054088);
      pcVar15 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                          ((CSimpleStringT<char,1> *)&DAT_180054088);
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)&local_320,pcVar15,iVar4,pcVar12,iVar7);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_2f8);
      pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                          ((CSimpleStringT<char,1> *)&local_320);
      iVar7 = CStdioFile::Open(local_2d8,pcVar12,0,(CFileException *)0x0);
      bVar20 = iVar7 != 0;
      if (iVar7 != 0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_310,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   &local_320);
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320);
    }
    if (bVar20) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_310,'\\');
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_310,
                 (int)&local_300);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_308);
      while (pcVar12 = CStdioFile::ReadString(local_2d8,local_148,0x100), pcVar12 != (char *)0x0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_308,
                   local_148);
        if ((*(int *)(local_310 + -0x10) != 0) &&
           (iVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &local_308,'#',0), iVar7 != 0)) {
          iVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_308,'\\',0);
          if (iVar7 < 1) {
            pCVar10 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Trim
                                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                 &local_308);
            pIVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                 &local_300);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328,pIVar11);
            local_318 = 0x8000;
            iVar7 = ATL::CSimpleStringT<char,1>::GetLength((CSimpleStringT<char,1> *)pCVar10);
            pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                                ((CSimpleStringT<char,1> *)pCVar10);
            iVar4 = ATL::CSimpleStringT<char,1>::GetLength((CSimpleStringT<char,1> *)&local_300);
            pcVar15 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                                ((CSimpleStringT<char,1> *)&local_300);
            ATL::CSimpleStringT<char,1>::Concatenate
                      ((CSimpleStringT<char,1> *)local_328,pcVar15,iVar4,pcVar12,iVar7);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_308,
                       (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                       local_328);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_328);
          }
          pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                              ((CSimpleStringT<char,1> *)&local_308);
          local_2a8 = (void *)0x0;
          lStack_2a0 = 0;
          local_298 = 0;
          uStack_290 = 0;
          sVar19 = 0xffffffffffffffff;
          do {
            sVar19 = sVar19 + 1;
          } while (pcVar12[sVar19] != '\0');
          FUN_180006e90(&local_2a8,pcVar12,sVar19);
          plVar1 = DAT_180054098;
          if (DAT_180054098 == DAT_1800540a0) {
            FUN_1800077a0(&DAT_180054090,DAT_180054098,&local_2a8);
            uVar17 = uStack_290;
          }
          else {
            *DAT_180054098 = (longlong)local_2a8;
            plVar1[1] = lStack_2a0;
            *(undefined4 *)(plVar1 + 2) = (undefined4)local_298;
            *(undefined4 *)((longlong)plVar1 + 0x14) = local_298._4_4_;
            *(undefined4 *)(plVar1 + 3) = (undefined4)uStack_290;
            *(undefined4 *)((longlong)plVar1 + 0x1c) = uStack_290._4_4_;
            local_2a8 = (void *)((ulonglong)local_2a8 & 0xffffffffffffff00);
            DAT_180054098 = DAT_180054098 + 4;
            uVar17 = 0xf;
          }
          if (0xf < uVar17) {
            pvVar16 = local_2a8;
            if ((0xfff < uVar17 + 1) &&
               (pvVar16 = *(void **)((longlong)local_2a8 + -8),
               0x1f < (ulonglong)((longlong)local_2a8 + (-8 - (longlong)pvVar16)))) {
                    /* WARNING: Subroutine does not return */
              _invalid_parameter_noinfo_noreturn();
            }
            FUN_180035134(pvVar16);
          }
          iVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_308,'*',0);
          if (-1 < iVar7) {
            pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                                ((CSimpleStringT<char,1> *)&local_308);
            pvVar13 = FindFirstFileA(pcVar12,&local_288);
            if (pvVar13 != (HANDLE)0xffffffffffffffff) {
              while( true ) {
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_320,local_288.cFileName);
                pIVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                          GetManager((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                      *)&local_300);
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_2f8,pIVar11);
                local_318 = 4;
                ATL::CSimpleStringT<char,1>::Concatenate
                          ((CSimpleStringT<char,1> *)local_2f8,
                           (char *)CONCAT44(uStack_2fc,local_300),
                           *(int *)((char *)CONCAT44(uStack_2fc,local_300) + -0x10),local_320,
                           *(int *)(local_320 + -0x10));
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_320,
                           (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                            *)local_2f8);
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_2f8);
                local_2a8 = (void *)0x0;
                lStack_2a0 = 0;
                local_298 = 0;
                uStack_290 = 0;
                sVar19 = 0xffffffffffffffff;
                do {
                  sVar19 = sVar19 + 1;
                } while (local_320[sVar19] != '\0');
                FUN_180006e90(&local_2a8,local_320,sVar19);
                plVar1 = DAT_180054098;
                if (DAT_180054098 == DAT_1800540a0) {
                  FUN_1800077a0(&DAT_180054090,DAT_180054098,&local_2a8);
                  uVar17 = uStack_290;
                }
                else {
                  *DAT_180054098 = (longlong)local_2a8;
                  plVar1[1] = lStack_2a0;
                  *(undefined4 *)(plVar1 + 2) = (undefined4)local_298;
                  *(undefined4 *)((longlong)plVar1 + 0x14) = local_298._4_4_;
                  *(undefined4 *)(plVar1 + 3) = (undefined4)uStack_290;
                  *(undefined4 *)((longlong)plVar1 + 0x1c) = uStack_290._4_4_;
                  local_2a8 = (void *)((ulonglong)local_2a8 & 0xffffffffffffff00);
                  DAT_180054098 = DAT_180054098 + 4;
                  uVar17 = 0xf;
                }
                if (0xf < uVar17) {
                  pvVar16 = local_2a8;
                  if ((0xfff < uVar17 + 1) &&
                     (pvVar16 = *(void **)((longlong)local_2a8 + -8),
                     0x1f < (ulonglong)((longlong)local_2a8 + (-8 - (longlong)pvVar16)))) {
                    /* WARNING: Subroutine does not return */
                    _invalid_parameter_noinfo_noreturn();
                  }
                  FUN_180035134(pvVar16);
                }
                BVar6 = FindNextFileA(pvVar13,&local_288);
                if (BVar6 == 0) break;
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_320);
              }
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320
                        );
            }
            FindClose(pvVar13);
          }
        }
      }
      pIVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_300);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_2f8,pIVar11);
      local_318 = 0x10000;
      iVar7 = ATL::CSimpleStringT<char,1>::StringLength("*.obj");
      iVar4 = ATL::CSimpleStringT<char,1>::GetLength((CSimpleStringT<char,1> *)&local_300);
      pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                          ((CSimpleStringT<char,1> *)&local_300);
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)local_2f8,pcVar12,iVar4,"*.obj",iVar7);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                (local_2f0,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 local_2f8);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_2f8);
      pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                          ((CSimpleStringT<char,1> *)local_2f0);
      pvVar13 = FindFirstFileA(pcVar12,&local_288);
      if (pvVar13 != (HANDLE)0xffffffffffffffff) {
        while( true ) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320,
                     local_288.cFileName);
          pIVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &local_300);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_2f8,pIVar11);
          local_318 = 8;
          ATL::CSimpleStringT<char,1>::Concatenate
                    ((CSimpleStringT<char,1> *)local_2f8,(char *)CONCAT44(uStack_2fc,local_300),
                     *(int *)((char *)CONCAT44(uStack_2fc,local_300) + -0x10),local_320,
                     *(int *)(local_320 + -0x10));
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320,
                     (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     local_2f8);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_2f8);
          local_2a8 = (void *)0x0;
          lStack_2a0 = 0;
          local_298 = 0;
          uStack_290 = 0;
          sVar19 = 0xffffffffffffffff;
          do {
            sVar19 = sVar19 + 1;
          } while (local_320[sVar19] != '\0');
          FUN_180006e90(&local_2a8,local_320,sVar19);
          plVar1 = DAT_180054098;
          if (DAT_180054098 == DAT_1800540a0) {
            FUN_1800077a0(&DAT_180054090,DAT_180054098,&local_2a8);
            uVar17 = uStack_290;
          }
          else {
            *DAT_180054098 = (longlong)local_2a8;
            plVar1[1] = lStack_2a0;
            *(undefined4 *)(plVar1 + 2) = (undefined4)local_298;
            *(undefined4 *)((longlong)plVar1 + 0x14) = local_298._4_4_;
            *(undefined4 *)(plVar1 + 3) = (undefined4)uStack_290;
            *(undefined4 *)((longlong)plVar1 + 0x1c) = uStack_290._4_4_;
            local_2a8 = (void *)((ulonglong)local_2a8 & 0xffffffffffffff00);
            DAT_180054098 = DAT_180054098 + 4;
            uVar17 = 0xf;
          }
          if (0xf < uVar17) {
            pvVar16 = local_2a8;
            if ((0xfff < uVar17 + 1) &&
               (pvVar16 = *(void **)((longlong)local_2a8 + -8),
               0x1f < (ulonglong)((longlong)local_2a8 + (-8 - (longlong)pvVar16)))) {
                    /* WARNING: Subroutine does not return */
              _invalid_parameter_noinfo_noreturn();
            }
            FUN_180035134(pvVar16);
          }
          BVar6 = FindNextFileA(pvVar13,&local_288);
          if (BVar6 == 0) break;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320);
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320);
      }
      FindClose(pvVar13);
      CStdioFile::Close(local_2d8);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_1800540b8,"")
      ;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_308);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_300);
    }
    CStdioFile::~CStdioFile(local_2d8);
  }
  iVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                    (local_2e8,"apsst");
  if (iVar7 != 0) goto LAB_180028baf;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_310,"");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320,local_2e0);
  FUN_180001320((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_300,
                (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_1800540b8,
                &local_320);
  pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                      ((CSimpleStringT<char,1> *)&local_300);
  pvVar13 = FindFirstFileA(pcVar12,&local_288);
  if (pvVar13 == (HANDLE)0xffffffffffffffff) {
    FindClose((HANDLE)0xffffffffffffffff);
    pcVar12 = (char *)GetGlobalPointer("MMTOP");
    pCVar10 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2e0
                         ,pcVar12);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_300,pCVar10);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2e0);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_300,
               "\\Stream Summary Templates\\");
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_300,
               (CSimpleStringT<char,1> *)&local_320);
    pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                        ((CSimpleStringT<char,1> *)&local_300);
    pvVar13 = FindFirstFileA(pcVar12,&local_288);
    bVar20 = false;
    if (pvVar13 != (HANDLE)0xffffffffffffffff) {
      pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                          ((CSimpleStringT<char,1> *)&local_300);
      FUN_1800256a0(&local_2a8,pcVar12);
      plVar1 = DAT_180054098;
      if (DAT_180054098 == DAT_1800540a0) {
        FUN_1800077a0(&DAT_180054090,DAT_180054098,&local_2a8);
      }
      else {
        *DAT_180054098 = (longlong)local_2a8;
        plVar1[1] = lStack_2a0;
        plVar1[2] = local_298;
        plVar1[3] = uStack_290;
        local_298 = _DAT_180041f70;
        uStack_290 = _UNK_180041f78;
        local_2a8 = (void *)((ulonglong)local_2a8 & 0xffffffffffffff00);
        DAT_180054098 = DAT_180054098 + 4;
      }
      FUN_180008a90((longlong *)&local_2a8);
      bVar20 = true;
    }
    FindClose(pvVar13);
    if ((!bVar20) && (iVar7 = SHGetFolderPathA(0,5,0), -1 < iVar7)) {
      FUN_180033bc0();
      pcVar12 = FUN_180033be0();
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_300,
                 "%s\\AspenTech\\%s %s\\Templates\\%s",local_148,pcVar12);
      pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                          ((CSimpleStringT<char,1> *)&local_300);
      pvVar13 = FindFirstFileA(pcVar12,&local_288);
      if (pvVar13 != (HANDLE)0xffffffffffffffff) {
        pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                            ((CSimpleStringT<char,1> *)&local_300);
        FUN_1800256a0(&local_2a8,pcVar12);
        FUN_180032470(&DAT_180054090,(longlong *)&local_2a8);
        FUN_180008a90((longlong *)&local_2a8);
      }
      goto LAB_180028b8e;
    }
  }
  else {
    pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                        ((CSimpleStringT<char,1> *)&local_300);
    local_2a8 = (void *)0x0;
    lStack_2a0 = 0;
    local_298 = 0;
    uStack_290 = 0;
    sVar19 = 0xffffffffffffffff;
    do {
      sVar19 = sVar19 + 1;
    } while (pcVar12[sVar19] != '\0');
    FUN_180006e90(&local_2a8,pcVar12,sVar19);
    plVar1 = DAT_180054098;
    if (DAT_180054098 == DAT_1800540a0) {
      FUN_1800077a0(&DAT_180054090,DAT_180054098,&local_2a8);
      uVar17 = uStack_290;
    }
    else {
      *DAT_180054098 = (longlong)local_2a8;
      plVar1[1] = lStack_2a0;
      plVar1[2] = local_298;
      plVar1[3] = uStack_290;
      local_2a8 = (void *)((ulonglong)local_2a8 & 0xffffffffffffff00);
      DAT_180054098 = DAT_180054098 + 4;
      uVar17 = 0xf;
    }
    if (0xf < uVar17) {
      pvVar16 = local_2a8;
      if ((0xfff < uVar17 + 1) &&
         (pvVar16 = *(void **)((longlong)local_2a8 + -8),
         0x1f < (ulonglong)((longlong)local_2a8 + (-8 - (longlong)pvVar16)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      FUN_180035134(pvVar16);
    }
LAB_180028b8e:
    FindClose(pvVar13);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_300);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_320);
LAB_180028baf:
  bVar20 = ATL::CSimpleStringT<char,1>::IsEmpty((CSimpleStringT<char,1> *)&local_310);
  if (!bVar20) {
    pcVar12 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64
                        ((CSimpleStringT<char,1> *)&local_310);
    local_2a8 = (void *)0x0;
    lStack_2a0 = 0;
    local_298 = 0;
    uStack_290 = 0;
    sVar19 = 0xffffffffffffffff;
    do {
      sVar19 = sVar19 + 1;
    } while (pcVar12[sVar19] != '\0');
    FUN_180006e90(&local_2a8,pcVar12,sVar19);
    plVar1 = DAT_180054098;
    if (DAT_180054098 == DAT_1800540a0) {
      FUN_1800077a0(&DAT_180054090,DAT_180054098,&local_2a8);
    }
    else {
      *DAT_180054098 = (longlong)local_2a8;
      plVar1[1] = lStack_2a0;
      plVar1[2] = local_298;
      plVar1[3] = uStack_290;
      local_298 = _DAT_180041f70;
      uStack_290 = _UNK_180041f78;
      local_2a8 = (void *)((ulonglong)local_2a8 & 0xffffffffffffff00);
      DAT_180054098 = DAT_180054098 + 4;
    }
    FUN_180008a90((longlong *)&local_2a8);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_2e8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_310);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_2f0);
  return;
}

/* RVA 0x28cb0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180028cb0(longlong *param_1,longlong *param_2,
                  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_3)

{
  char *pcVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar2;
  int iVar3;
  DWORD DVar4;
  int iVar5;
  BOOL BVar6;
  IAtlStringMgr *pIVar7;
  longlong lVar8;
  longlong lVar10;
  longlong lVar9;
  HANDLE hFindFile;
  LPCSTR ***ppppCVar11;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar12;
  size_t sVar13;
  undefined1 auStackY_218 [32];
  wchar_t *local_1e8;
  undefined4 local_1e0 [2];
  LPCSTR local_1d8;
  LPCSTR local_1d0;
  char *local_1c8;
  LPCSTR local_1c0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_1b8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_1b0 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_1a8 [8];
  LPCSTR ***local_1a0;
  undefined8 uStack_198;
  undefined8 local_190;
  ulonglong uStack_188;
  _WIN32_FIND_DATAA local_178;
  ulonglong local_38;
  
  local_38 = DAT_180052888 ^ (ulonglong)auStackY_218;
  local_1e0[0] = 0;
  pCVar12 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)*param_2;
  pCVar2 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2[1];
  if (pCVar12 != pCVar2) {
    do {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar12);
      pCVar12 = pCVar12 + 8;
    } while (pCVar12 != pCVar2);
    param_2[1] = *param_2;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1c8,"");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_3,"");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1c8,"");
  local_1e8 = malloc(0x400);
  iVar3 = SHGetKnownFolderPath(&DAT_180042ad8,0,0,&local_1e8);
  if (iVar3 == 0) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1d0,local_1e8
              );
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1c8,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               &local_1d0);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1d0);
    if (*(int *)(local_1c8 + -0x10) != 0) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1a8,"AspenTech");
      pIVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          &local_1c8);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1d8,pIVar7)
      ;
      local_1e0[0] = 1;
      sVar13 = 0xffffffffffffffff;
      lVar10 = -1;
      do {
        lVar8 = lVar10 + 1;
        lVar9 = lVar10 + 1;
        lVar10 = lVar8;
      } while (*(char *)((longlong)&DAT_1800409c4 + lVar9) != '\0');
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)&local_1d8,local_1c8,*(int *)(local_1c8 + -0x10),"\\",
                 (int)lVar8);
      FUN_180001320((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1d0,
                    (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1d8,
                    (undefined8 *)local_1a8);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1d8);
      if (((*(int *)(local_1d0 + -0x10) != 0) &&
          (DVar4 = GetFileAttributesA(local_1d0), DVar4 != 0xffffffff)) && ((DVar4 & 0x10) != 0)) {
        FUN_180001430(local_1b0,"Aspen Plus ",
                      (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                      &DAT_1800540a8);
        pIVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                           ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_1d0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1e8,
                   pIVar7);
        local_1e0[0] = 8;
        lVar10 = -1;
        do {
          lVar8 = lVar10 + 1;
          lVar9 = lVar10 + 1;
          lVar10 = lVar8;
        } while (*(char *)((longlong)&DAT_1800409c4 + lVar9) != '\0');
        ATL::CSimpleStringT<char,1>::Concatenate
                  ((CSimpleStringT<char,1> *)&local_1e8,local_1d0,*(int *)(local_1d0 + -0x10),"\\",
                   (int)lVar8);
        FUN_180001320((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1c0,
                      (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1e8,
                      (undefined8 *)local_1b0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1e8);
        if (((*(int *)(local_1c0 + -0x10) != 0) &&
            (DVar4 = GetFileAttributesA(local_1c0), DVar4 != 0xffffffff)) && ((DVar4 & 0x10) != 0))
        {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1b8,"AM Models");
          pIVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                             ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                              &local_1c0);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1e8,
                     pIVar7);
          local_1e0[0] = 0x20;
          lVar10 = -1;
          do {
            lVar8 = lVar10 + 1;
            lVar9 = lVar10 + 1;
            lVar10 = lVar8;
          } while (*(char *)((longlong)&DAT_1800409c4 + lVar9) != '\0');
          ATL::CSimpleStringT<char,1>::Concatenate
                    ((CSimpleStringT<char,1> *)&local_1e8,local_1c0,*(int *)(local_1c0 + -0x10),"\\"
                     ,(int)lVar8);
          FUN_180001320((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1d8,
                        (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1e8,
                        (undefined8 *)local_1b8);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1e8);
          if (((*(int *)(local_1d8 + -0x10) != 0) &&
              (DVar4 = GetFileAttributesA(local_1d8), DVar4 != 0xffffffff)) && ((DVar4 & 0x10) != 0)
             ) {
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      (param_3,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                *)&local_1d8);
            pIVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                               ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                &local_1d8);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1e8,
                       pIVar7);
            local_1e0[0] = 0x80;
            lVar10 = -1;
            do {
              lVar9 = lVar10 + 1;
              pcVar1 = "*.atmlz" + lVar10;
              lVar10 = lVar9;
            } while (*pcVar1 != '\0');
            ATL::CSimpleStringT<char,1>::Concatenate
                      ((CSimpleStringT<char,1> *)&local_1e8,local_1d8,*(int *)(local_1d8 + -0x10),
                       "/*.atmlz",(int)lVar9);
            local_1a0 = (LPCSTR ***)0x0;
            uStack_198 = 0;
            local_190 = 0;
            uStack_188 = 0;
            do {
              sVar13 = sVar13 + 1;
            } while (*(char *)((longlong)local_1e8 + sVar13) != '\0');
            FUN_180006e90(&local_1a0,local_1e8,sVar13);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1e8);
            ppppCVar11 = (LPCSTR ***)&local_1a0;
            if (0xf < uStack_188) {
              ppppCVar11 = local_1a0;
            }
            hFindFile = FindFirstFileA((LPCSTR)ppppCVar11,&local_178);
            if (hFindFile != (HANDLE)0xffffffffffffffff) {
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_1e0,
                         "");
              do {
                if (((byte)local_178.dwFileAttributes & 0x10) == 0) {
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             local_1e0,local_178.cFileName);
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Replace
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             local_1e0,".atmlz","");
                  iVar3 = 0;
                  lVar10 = *param_1;
                  if (param_1[1] - lVar10 >> 3 != 0) {
                    lVar9 = 0;
                    do {
                      iVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                              CompareNoCase((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                             *)local_1e0,*(char **)(lVar10 + lVar9));
                      if (iVar5 == 0) {
                        pCVar12 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                  param_2[1];
                        if (pCVar12 ==
                            (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            param_2[2]) {
                          FUN_180025400(param_2,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                                 *)pCVar12,
                                        (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                         *)local_1e0);
                        }
                        else {
                          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                    (pCVar12,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                              *)local_1e0);
                          param_2[1] = param_2[1] + 8;
                        }
                        break;
                      }
                      iVar3 = iVar3 + 1;
                      lVar9 = lVar9 + 8;
                      lVar10 = *param_1;
                    } while ((ulonglong)(longlong)iVar3 < (ulonglong)(param_1[1] - lVar10 >> 3));
                  }
                }
                BVar6 = FindNextFileA(hFindFile,&local_178);
              } while (BVar6 != 0);
              FindClose(hFindFile);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_1e0)
              ;
            }
            if (0xf < uStack_188) {
              ppppCVar11 = local_1a0;
              if ((0xfff < uStack_188 + 1) &&
                 (ppppCVar11 = (LPCSTR ***)local_1a0[-1],
                 (LPCSTR)0x1f < (LPCSTR)((longlong)local_1a0 + (-8 - (longlong)ppppCVar11)))) {
                    /* WARNING: Subroutine does not return */
                _invalid_parameter_noinfo_noreturn();
              }
              FUN_180035134(ppppCVar11);
            }
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1d8);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1b8);
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1c0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1b0);
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1d0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1a8);
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1c8);
  return;
}

