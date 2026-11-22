/* NATIVE-337 reconstructed pseudo-C (editable) */

/* ---- FUNC 00001000 FUN_180001000 (40 bytes) ---- */

void FUN_180001000(void)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_18000b728,"");
  atexit(FUN_180006230);
  return;
}

/* ---- FUNC 00001028 FUN_180001028 (32 bytes) ---- */

void FUN_180001028(void)

{
  ATL::CAtlBaseModule::CAtlBaseModule((CAtlBaseModule *)&DAT_18000bd40);
  atexit(FUN_180006240);
  return;
}

/* ---- FUNC 00001050 FUN_180001050 (12 bytes) ---- */

void FUN_180001050(void)

{
  atexit(FUN_180006250);
  return;
}

/* ---- FUNC 00001060 FUN_180001060 (24 bytes) ---- */

void FUN_180001060(long param_1)

{
  code *pcVar1;
  
  if (param_1 == -0x7ff8fff2) {
    AfxThrowMemoryException();
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  AfxThrowOleException(param_1);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

/* ---- FUNC 00001080 InitializeCriticalSectionEx (7 bytes) ---- */

BOOL __stdcall
InitializeCriticalSectionEx(LPCRITICAL_SECTION lpCriticalSection,DWORD dwSpinCount,DWORD Flags)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180001080. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = InitializeCriticalSectionEx(lpCriticalSection,dwSpinCount,Flags);
  return BVar1;
}

/* ---- FUNC 00001090 _guard_check_icall (3 bytes) ---- */

void _guard_check_icall(void)

{
  return;
}

/* ---- FUNC 000010A0 gxSetRefState (7 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gxSetRefState(undefined4 param_1)

{
                    /* 0x10a0  17  gxSetRefState */
  _DAT_18000b5a4 = param_1;
  return;
}

/* ---- FUNC 000010B0 FUN_1800010b0 (50 bytes) ---- */

undefined8 FUN_1800010b0(undefined8 param_1,int param_2)

{
  AFX_MODULE_STATE *pAVar1;
  
  if (param_2 == 1) {
    pAVar1 = AfxGetModuleState();
    *(undefined8 *)(pAVar1 + 0x30) = *(undefined8 *)(pAVar1 + 0x38);
    *(undefined8 *)(pAVar1 + 0x48) = *(undefined8 *)(pAVar1 + 0x50);
    *(undefined8 *)(pAVar1 + 0x38) = 0;
    *(undefined8 *)(pAVar1 + 0x50) = 0;
  }
  return 1;
}

/* ---- FUNC 000010F0 FUN_1800010f0 (192 bytes) ---- */

undefined8 * FUN_1800010f0(undefined8 *param_1,LPCSTR param_2)

{
  int cchWideChar;
  int iVar1;
  BSTR lpWideCharStr;
  
  if (param_2 == (LPCSTR)0x0) {
    *param_1 = 0;
    return param_1;
  }
  cchWideChar = MultiByteToWideChar(0,0,param_2,-1,(LPWSTR)0x0,0);
  lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,cchWideChar - 1);
  if ((lpWideCharStr == (BSTR)0x0) ||
     (iVar1 = MultiByteToWideChar(0,0,param_2,-1,lpWideCharStr,cchWideChar), iVar1 == cchWideChar))
  {
    *param_1 = lpWideCharStr;
    if (lpWideCharStr != (BSTR)0x0) {
      return param_1;
    }
  }
  else {
    SysFreeString(lpWideCharStr);
    *param_1 = 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_180001060(-0x7ff8fff2);
}

/* ---- FUNC 000011C0 FUN_1800011c0 (10 bytes) ---- */

void FUN_1800011c0(undefined8 *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0001800011c3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SysFreeString((BSTR)*param_1);
  return;
}

/* ---- FUNC 000011D0 VariantClear (7 bytes) ---- */

HRESULT __stdcall VariantClear(VARIANTARG *pvarg)

{
  HRESULT HVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800011d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HVar1 = VariantClear(pvarg);
  return HVar1;
}

/* ---- FUNC 000011E0 FUN_1800011e0 (311 bytes) ---- */

HRESULT FUN_1800011e0(undefined8 *param_1,LPCSTR param_2)

{
  int cchWideChar;
  int iVar1;
  UINT UVar2;
  HRESULT HVar3;
  BSTR lpWideCharStr;
  BSTR local_res10;
  BSTR local_res18;
  
  if (param_2 == (LPCSTR)0x0) {
    return 0;
  }
  SysFreeString((BSTR)0x0);
  HVar3 = 0;
  cchWideChar = MultiByteToWideChar(0,0,param_2,-1,(LPWSTR)0x0,0);
  lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,cchWideChar - 1);
  if (lpWideCharStr != (BSTR)0x0) {
    iVar1 = MultiByteToWideChar(0,0,param_2,-1,lpWideCharStr,cchWideChar);
    if (iVar1 != cchWideChar) {
      SysFreeString(lpWideCharStr);
      local_res18 = (BSTR)0x0;
      goto LAB_18000130d;
    }
  }
  local_res18 = lpWideCharStr;
  if (lpWideCharStr != (BSTR)0x0) {
    local_res10 = lpWideCharStr;
    UVar2 = SysStringLen(lpWideCharStr);
    if (UVar2 != 0) {
      local_res10 = (BSTR)0x0;
      HVar3 = VarBstrCat((BSTR)*param_1,lpWideCharStr,&local_res10);
      if (-1 < HVar3) {
        SysFreeString((BSTR)*param_1);
        *param_1 = local_res10;
      }
    }
    SysFreeString(lpWideCharStr);
    return HVar3;
  }
LAB_18000130d:
  local_res10 = local_res18;
                    /* WARNING: Subroutine does not return */
  FUN_180001060(-0x7ff8fff2);
}

/* ---- FUNC 00001290 thunk_FUN_1800012bd (2 bytes) ---- */

ulonglong thunk_FUN_1800012bd(void)

{
  UINT UVar1;
  uint uVar2;
  BSTR unaff_RBX;
  ulonglong *unaff_RSI;
  BSTR unaff_RDI;
  BSTR in_stack_00000078;
  
  UVar1 = SysStringLen(unaff_RBX);
  if (UVar1 != 0) {
    in_stack_00000078 = unaff_RDI;
    uVar2 = VarBstrCat((BSTR)*unaff_RSI,unaff_RBX,&stack0x00000078);
    unaff_RDI = (BSTR)(ulonglong)uVar2;
    if (-1 < (int)uVar2) {
      SysFreeString((BSTR)*unaff_RSI);
      *unaff_RSI = (ulonglong)in_stack_00000078;
    }
  }
  SysFreeString(unaff_RBX);
  return (ulonglong)unaff_RDI & 0xffffffff;
}

/* ---- FUNC 0000129F FUN_18000129f (23 bytes) ---- */

undefined8 FUN_18000129f(BSTR param_1)

{
  SysFreeString(param_1);
  return 0x8007000e;
}

/* ---- FUNC 000012BD FUN_1800012bd (80 bytes) ---- */

ulonglong FUN_1800012bd(void)

{
  UINT UVar1;
  uint uVar2;
  BSTR unaff_RBX;
  ulonglong *unaff_RSI;
  BSTR unaff_RDI;
  BSTR in_stack_00000078;
  
  UVar1 = SysStringLen(unaff_RBX);
  if (UVar1 != 0) {
    in_stack_00000078 = unaff_RDI;
    uVar2 = VarBstrCat((BSTR)*unaff_RSI,unaff_RBX,&stack0x00000078);
    unaff_RDI = (BSTR)(ulonglong)uVar2;
    if (-1 < (int)uVar2) {
      SysFreeString((BSTR)*unaff_RSI);
      *unaff_RSI = (ulonglong)in_stack_00000078;
    }
  }
  SysFreeString(unaff_RBX);
  return (ulonglong)unaff_RDI & 0xffffffff;
}

/* ---- FUNC 00001320 FUN_180001320 (355 bytes) ---- */

ulonglong FUN_180001320(_union_1719 param_1)

{
  longlong lVar1;
  LCID LVar2;
  int iVar3;
  longlong *plVar4;
  uint uVar5;
  ulonglong uVar7;
  undefined4 local_res10 [2];
  wchar_t *local_res18;
  undefined2 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined1 local_50 [24];
  VARIANTARG local_38;
  ulonglong uVar6;
  
  plVar4 = (longlong *)FUN_180002330();
  if (plVar4 != (longlong *)0x0) {
    local_res18 = L"ShowDialog";
    lVar1 = *plVar4;
    LVar2 = GetUserDefaultLCID();
    iVar3 = (**(code **)(lVar1 + 0x28))(plVar4,&DAT_1800082f8,&local_res18,1,LVar2,local_res10);
    if (-1 < iVar3) {
      uVar7 = 0;
      local_60 = 0;
      local_58 = 1;
      local_68 = (undefined2 *)local_50;
      uVar6 = uVar7;
      do {
        VariantInit((VARIANTARG *)(local_50 + uVar6 * 0x18));
        uVar5 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar5;
      } while (uVar5 < (uint)local_58);
      local_50._0_2_ = 8;
      local_50._8_8_ = param_1;
      COleVariant::COleVariant((COleVariant *)&local_38,0,3);
      lVar1 = *plVar4;
      LVar2 = GetUserDefaultLCID();
      iVar3 = (**(code **)(lVar1 + 0x30))
                        (plVar4,local_res10[0],&DAT_1800082f8,LVar2,1,&local_68,&local_38,0,0);
      if (-1 < iVar3) {
        uVar7 = (ulonglong)(uint)local_38.n1._8_4_;
      }
      (**(code **)(*plVar4 + 0x10))(plVar4);
      VariantClear(&local_38);
      return uVar7;
    }
    (**(code **)(*plVar4 + 0x10))(plVar4);
  }
  return 0;
}

/* ---- FUNC 00001490 FUN_180001490 (352 bytes) ---- */

ulonglong FUN_180001490(undefined4 param_1)

{
  longlong lVar1;
  LCID LVar2;
  int iVar3;
  longlong *plVar4;
  uint uVar5;
  ulonglong uVar7;
  undefined4 local_res10 [2];
  wchar_t *local_res18;
  _union_2707 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  _union_2707 local_50;
  VARIANTARG local_38;
  ulonglong uVar6;
  
  plVar4 = (longlong *)FUN_180002330();
  if (plVar4 != (longlong *)0x0) {
    local_res18 = L"ShowElecWizard";
    lVar1 = *plVar4;
    LVar2 = GetUserDefaultLCID();
    iVar3 = (**(code **)(lVar1 + 0x28))(plVar4,&DAT_1800082f8,&local_res18,1,LVar2,local_res10);
    if (-1 < iVar3) {
      uVar7 = 0;
      local_60 = 0;
      local_58 = 1;
      local_68 = &local_50;
      uVar6 = uVar7;
      do {
        VariantInit((VARIANTARG *)&(&local_50)[uVar6].n2);
        uVar5 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar5;
      } while (uVar5 < (uint)local_58);
      local_50.n2.vt = 3;
      local_50._8_4_ = param_1;
      COleVariant::COleVariant((COleVariant *)&local_38,0,3);
      lVar1 = *plVar4;
      LVar2 = GetUserDefaultLCID();
      iVar3 = (**(code **)(lVar1 + 0x30))
                        (plVar4,local_res10[0],&DAT_1800082f8,LVar2,1,&local_68,&local_38,0,0);
      if (-1 < iVar3) {
        uVar7 = (ulonglong)(uint)local_38.n1._8_4_;
      }
      (**(code **)(*plVar4 + 0x10))(plVar4);
      VariantClear(&local_38);
      return uVar7;
    }
    (**(code **)(*plVar4 + 0x10))(plVar4);
  }
  return 0;
}

/* ---- FUNC 000015F0 FUN_1800015f0 (399 bytes) ---- */

ulonglong FUN_1800015f0(undefined8 *param_1)

{
  longlong lVar1;
  LCID LVar2;
  int iVar3;
  longlong *plVar4;
  uint uVar5;
  ulonglong uVar7;
  undefined4 local_res10 [2];
  BSTR local_res18;
  wchar_t *local_res20;
  undefined2 *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined1 local_60 [24];
  VARIANTARG local_48;
  ulonglong uVar6;
  
  plVar4 = (longlong *)FUN_180002330();
  if (plVar4 != (longlong *)0x0) {
    local_res20 = L"ShowNewPureCompParam";
    lVar1 = *plVar4;
    LVar2 = GetUserDefaultLCID();
    iVar3 = (**(code **)(lVar1 + 0x28))(plVar4,&DAT_1800082f8,&local_res20,1,LVar2,local_res10);
    if (-1 < iVar3) {
      uVar7 = 0;
      local_70 = 0;
      local_68 = 1;
      local_78 = (undefined2 *)local_60;
      uVar6 = uVar7;
      do {
        VariantInit((VARIANTARG *)(local_60 + uVar6 * 0x18));
        uVar5 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar5;
      } while (uVar5 < (uint)local_68);
      local_res18 = SysAllocString(L"");
      local_60._0_2_ = 0x4008;
      local_60._8_8_ = &local_res18;
      COleVariant::COleVariant((COleVariant *)&local_48,0,3);
      lVar1 = *plVar4;
      LVar2 = GetUserDefaultLCID();
      iVar3 = (**(code **)(lVar1 + 0x30))
                        (plVar4,local_res10[0],&DAT_1800082f8,LVar2,1,&local_78,&local_48,0,0);
      if (-1 < iVar3) {
        uVar7 = (ulonglong)(uint)local_48.n1._8_4_;
        *param_1 = local_res18;
      }
      (**(code **)(*plVar4 + 0x10))(plVar4);
      SysFreeString(local_res18);
      VariantClear(&local_48);
      return uVar7;
    }
    (**(code **)(*plVar4 + 0x10))(plVar4);
  }
  return 0;
}

/* ---- FUNC 00001780 FUN_180001780 (352 bytes) ---- */

ulonglong FUN_180001780(undefined4 param_1)

{
  longlong lVar1;
  LCID LVar2;
  int iVar3;
  longlong *plVar4;
  uint uVar5;
  ulonglong uVar7;
  undefined4 local_res10 [2];
  wchar_t *local_res18;
  _union_2707 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  _union_2707 local_50;
  VARIANTARG local_38;
  ulonglong uVar6;
  
  plVar4 = (longlong *)FUN_180002330();
  if (plVar4 != (longlong *)0x0) {
    local_res18 = L"ShowSFEAssistant";
    lVar1 = *plVar4;
    LVar2 = GetUserDefaultLCID();
    iVar3 = (**(code **)(lVar1 + 0x28))(plVar4,&DAT_1800082f8,&local_res18,1,LVar2,local_res10);
    if (-1 < iVar3) {
      uVar7 = 0;
      local_60 = 0;
      local_58 = 1;
      local_68 = &local_50;
      uVar6 = uVar7;
      do {
        VariantInit((VARIANTARG *)&(&local_50)[uVar6].n2);
        uVar5 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar5;
      } while (uVar5 < (uint)local_58);
      local_50.n2.vt = 3;
      local_50._8_4_ = param_1;
      COleVariant::COleVariant((COleVariant *)&local_38,0,3);
      lVar1 = *plVar4;
      LVar2 = GetUserDefaultLCID();
      iVar3 = (**(code **)(lVar1 + 0x30))
                        (plVar4,local_res10[0],&DAT_1800082f8,LVar2,1,&local_68,&local_38,0,0);
      if (-1 < iVar3) {
        uVar7 = (ulonglong)(uint)local_38.n1._8_4_;
      }
      (**(code **)(*plVar4 + 0x10))(plVar4);
      VariantClear(&local_38);
      return uVar7;
    }
    (**(code **)(*plVar4 + 0x10))(plVar4);
  }
  return 0;
}

/* ---- FUNC 000018E0 FUN_1800018e0 (352 bytes) ---- */

ulonglong FUN_1800018e0(undefined4 param_1)

{
  longlong lVar1;
  LCID LVar2;
  int iVar3;
  longlong *plVar4;
  uint uVar5;
  ulonglong uVar7;
  undefined4 local_res10 [2];
  wchar_t *local_res18;
  _union_2707 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  _union_2707 local_50;
  VARIANTARG local_38;
  ulonglong uVar6;
  
  plVar4 = (longlong *)FUN_180002330();
  if (plVar4 != (longlong *)0x0) {
    local_res18 = L"ShowSFEAssistantMain";
    lVar1 = *plVar4;
    LVar2 = GetUserDefaultLCID();
    iVar3 = (**(code **)(lVar1 + 0x28))(plVar4,&DAT_1800082f8,&local_res18,1,LVar2,local_res10);
    if (-1 < iVar3) {
      uVar7 = 0;
      local_60 = 0;
      local_58 = 1;
      local_68 = &local_50;
      uVar6 = uVar7;
      do {
        VariantInit((VARIANTARG *)&(&local_50)[uVar6].n2);
        uVar5 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar5;
      } while (uVar5 < (uint)local_58);
      local_50.n2.vt = 3;
      local_50._8_4_ = param_1;
      COleVariant::COleVariant((COleVariant *)&local_38,0,3);
      lVar1 = *plVar4;
      LVar2 = GetUserDefaultLCID();
      iVar3 = (**(code **)(lVar1 + 0x30))
                        (plVar4,local_res10[0],&DAT_1800082f8,LVar2,1,&local_68,&local_38,0,0);
      if (-1 < iVar3) {
        uVar7 = (ulonglong)(uint)local_38.n1._8_4_;
      }
      (**(code **)(*plVar4 + 0x10))(plVar4);
      VariantClear(&local_38);
      return uVar7;
    }
    (**(code **)(*plVar4 + 0x10))(plVar4);
  }
  return 0;
}

/* ---- FUNC 00001A40 FUN_180001a40 (441 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180001a40(undefined8 param_1,undefined4 param_2,_union_1719 param_3)

{
  longlong lVar1;
  int iVar2;
  LCID LVar3;
  longlong *plVar4;
  uint uVar5;
  ulonglong uVar7;
  undefined1 auStack_118 [32];
  LCID local_f8;
  undefined2 **local_f0;
  VARIANTARG *local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined4 local_c8 [2];
  wchar_t *local_c0;
  undefined2 *local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  VARIANTARG local_a0;
  undefined1 local_88 [24];
  undefined2 local_70;
  undefined4 local_68;
  undefined2 local_58;
  undefined8 local_50;
  ulonglong local_38;
  ulonglong uVar6;
  
  local_38 = DAT_18000b3e8 ^ (ulonglong)auStack_118;
  plVar4 = (longlong *)FUN_180002330();
  if (plVar4 != (longlong *)0x0) {
    local_c0 = L"ShowSearchComponent";
    lVar1 = *plVar4;
    local_f8 = GetUserDefaultLCID();
    local_f0 = (undefined2 **)local_c8;
    iVar2 = (**(code **)(lVar1 + 0x28))(plVar4,&DAT_1800082f8,&local_c0,1);
    if (-1 < iVar2) {
      uVar7 = 0;
      local_b0 = 0;
      local_a8 = 3;
      local_b8 = (undefined2 *)local_88;
      uVar6 = uVar7;
      do {
        VariantInit((VARIANTARG *)(local_88 + uVar6 * 0x18));
        uVar5 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar5;
      } while (uVar5 < (uint)local_a8);
      local_58 = 8;
      local_70 = 3;
      local_88._0_2_ = 8;
      local_88._8_8_ = param_3;
      local_68 = param_2;
      local_50 = param_1;
      COleVariant::COleVariant((COleVariant *)&local_a0,0,3);
      lVar1 = *plVar4;
      LVar3 = GetUserDefaultLCID();
      local_d8 = 0;
      local_e0 = 0;
      local_e8 = &local_a0;
      local_f0 = &local_b8;
      local_f8 = CONCAT22(local_f8._2_2_,1);
      iVar2 = (**(code **)(lVar1 + 0x30))(plVar4,local_c8[0],&DAT_1800082f8,LVar3);
      if (-1 < iVar2) {
        uVar7 = (ulonglong)(uint)local_a0.n1._8_4_;
      }
      (**(code **)(*plVar4 + 0x10))(plVar4);
      VariantClear(&local_a0);
      return uVar7;
    }
    (**(code **)(*plVar4 + 0x10))(plVar4);
  }
  return 0;
}

/* ---- FUNC 00001C00 FUN_180001c00 (355 bytes) ---- */

ulonglong FUN_180001c00(_union_1719 param_1)

{
  longlong lVar1;
  LCID LVar2;
  int iVar3;
  longlong *plVar4;
  uint uVar5;
  ulonglong uVar7;
  undefined4 local_res10 [2];
  wchar_t *local_res18;
  undefined2 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined1 local_50 [24];
  VARIANTARG local_38;
  ulonglong uVar6;
  
  plVar4 = (longlong *)FUN_180002330();
  if (plVar4 != (longlong *)0x0) {
    local_res18 = L"ShowSearchProperty";
    lVar1 = *plVar4;
    LVar2 = GetUserDefaultLCID();
    iVar3 = (**(code **)(lVar1 + 0x28))(plVar4,&DAT_1800082f8,&local_res18,1,LVar2,local_res10);
    if (-1 < iVar3) {
      uVar7 = 0;
      local_60 = 0;
      local_58 = 1;
      local_68 = (undefined2 *)local_50;
      uVar6 = uVar7;
      do {
        VariantInit((VARIANTARG *)(local_50 + uVar6 * 0x18));
        uVar5 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar5;
      } while (uVar5 < (uint)local_58);
      local_50._0_2_ = 8;
      local_50._8_8_ = param_1;
      COleVariant::COleVariant((COleVariant *)&local_38,0,3);
      lVar1 = *plVar4;
      LVar2 = GetUserDefaultLCID();
      iVar3 = (**(code **)(lVar1 + 0x30))
                        (plVar4,local_res10[0],&DAT_1800082f8,LVar2,1,&local_68,&local_38,0,0);
      if (-1 < iVar3) {
        uVar7 = (ulonglong)(uint)local_38.n1._8_4_;
      }
      (**(code **)(*plVar4 + 0x10))(plVar4);
      VariantClear(&local_38);
      return uVar7;
    }
    (**(code **)(*plVar4 + 0x10))(plVar4);
  }
  return 0;
}

/* ---- FUNC 00001D70 FUN_180001d70 (399 bytes) ---- */

ulonglong FUN_180001d70(undefined4 param_1,undefined4 *param_2)

{
  longlong lVar1;
  LCID LVar2;
  int iVar3;
  longlong *plVar4;
  uint uVar5;
  ulonglong uVar7;
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  wchar_t *local_98;
  undefined2 *local_90;
  undefined8 local_88;
  undefined8 local_80;
  VARIANTARG local_78;
  undefined1 local_60 [24];
  undefined2 local_48;
  undefined4 local_40;
  ulonglong uVar6;
  
  plVar4 = (longlong *)FUN_180002330();
  if (plVar4 != (longlong *)0x0) {
    local_98 = L"ShowUpgradeRetired";
    lVar1 = *plVar4;
    LVar2 = GetUserDefaultLCID();
    iVar3 = (**(code **)(lVar1 + 0x28))(plVar4,&DAT_1800082f8,&local_98,1,LVar2,local_res20);
    if (-1 < iVar3) {
      uVar7 = 0;
      local_88 = 0;
      local_80 = 2;
      local_90 = (undefined2 *)local_60;
      uVar6 = uVar7;
      do {
        VariantInit((VARIANTARG *)(local_60 + uVar6 * 0x18));
        uVar5 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar5;
      } while (uVar5 < (uint)local_80);
      local_res18[0] = 0xffffffff;
      local_48 = 3;
      local_60._0_2_ = 0x4003;
      local_60._8_8_ = local_res18;
      local_40 = param_1;
      COleVariant::COleVariant((COleVariant *)&local_78,0,3);
      lVar1 = *plVar4;
      LVar2 = GetUserDefaultLCID();
      iVar3 = (**(code **)(lVar1 + 0x30))
                        (plVar4,local_res20[0],&DAT_1800082f8,LVar2,1,&local_90,&local_78,0,0);
      if (-1 < iVar3) {
        uVar7 = (ulonglong)(uint)local_78.n1._8_4_;
        *param_2 = local_res18[0];
      }
      (**(code **)(*plVar4 + 0x10))(plVar4);
      VariantClear(&local_78);
      return uVar7;
    }
    (**(code **)(*plVar4 + 0x10))(plVar4);
  }
  return 0;
}

/* ---- FUNC 00001F00 FUN_180001f00 (352 bytes) ---- */

ulonglong FUN_180001f00(undefined4 param_1)

{
  longlong lVar1;
  LCID LVar2;
  int iVar3;
  longlong *plVar4;
  uint uVar5;
  ulonglong uVar7;
  undefined4 local_res10 [2];
  wchar_t *local_res18;
  _union_2707 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  _union_2707 local_50;
  VARIANTARG local_38;
  ulonglong uVar6;
  
  plVar4 = (longlong *)FUN_180002330();
  if (plVar4 != (longlong *)0x0) {
    local_res18 = L"ShowUpwardComp1";
    lVar1 = *plVar4;
    LVar2 = GetUserDefaultLCID();
    iVar3 = (**(code **)(lVar1 + 0x28))(plVar4,&DAT_1800082f8,&local_res18,1,LVar2,local_res10);
    if (-1 < iVar3) {
      uVar7 = 0;
      local_60 = 0;
      local_58 = 1;
      local_68 = &local_50;
      uVar6 = uVar7;
      do {
        VariantInit((VARIANTARG *)&(&local_50)[uVar6].n2);
        uVar5 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar5;
      } while (uVar5 < (uint)local_58);
      local_50.n2.vt = 3;
      local_50._8_4_ = param_1;
      COleVariant::COleVariant((COleVariant *)&local_38,0,3);
      lVar1 = *plVar4;
      LVar2 = GetUserDefaultLCID();
      iVar3 = (**(code **)(lVar1 + 0x30))
                        (plVar4,local_res10[0],&DAT_1800082f8,LVar2,1,&local_68,&local_38,0,0);
      if (-1 < iVar3) {
        uVar7 = (ulonglong)(uint)local_38.n1._8_4_;
      }
      (**(code **)(*plVar4 + 0x10))(plVar4);
      VariantClear(&local_38);
      return uVar7;
    }
    (**(code **)(*plVar4 + 0x10))(plVar4);
  }
  return 0;
}

/* ---- FUNC 00002060 FUN_180002060 (365 bytes) ---- */

ulonglong FUN_180002060(undefined4 param_1,undefined4 param_2)

{
  longlong lVar1;
  LCID LVar2;
  int iVar3;
  longlong *plVar4;
  uint uVar5;
  ulonglong uVar7;
  undefined4 local_res18 [2];
  wchar_t *local_res20;
  _union_2707 *local_88;
  undefined8 local_80;
  undefined8 local_78;
  VARIANTARG local_70;
  _union_2707 local_58;
  undefined2 local_40;
  undefined4 local_38;
  ulonglong uVar6;
  
  plVar4 = (longlong *)FUN_180002330();
  if (plVar4 != (longlong *)0x0) {
    local_res20 = L"ShowUpwardComp";
    lVar1 = *plVar4;
    LVar2 = GetUserDefaultLCID();
    iVar3 = (**(code **)(lVar1 + 0x28))(plVar4,&DAT_1800082f8,&local_res20,1,LVar2,local_res18);
    if (-1 < iVar3) {
      uVar7 = 0;
      local_80 = 0;
      local_78 = 2;
      local_88 = &local_58;
      uVar6 = uVar7;
      do {
        VariantInit((VARIANTARG *)&(&local_58)[uVar6].n2);
        uVar5 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar5;
      } while (uVar5 < (uint)local_78);
      local_40 = 3;
      local_58.n2.vt = 3;
      local_58._8_4_ = param_2;
      local_38 = param_1;
      COleVariant::COleVariant((COleVariant *)&local_70,0,3);
      lVar1 = *plVar4;
      LVar2 = GetUserDefaultLCID();
      iVar3 = (**(code **)(lVar1 + 0x30))
                        (plVar4,local_res18[0],&DAT_1800082f8,LVar2,1,&local_88,&local_70,0,0);
      if (-1 < iVar3) {
        uVar7 = (ulonglong)(uint)local_70.n1._8_4_;
      }
      (**(code **)(*plVar4 + 0x10))(plVar4);
      VariantClear(&local_70);
      return uVar7;
    }
    (**(code **)(*plVar4 + 0x10))(plVar4);
  }
  return 0;
}

/* ---- FUNC 000021D0 FUN_1800021d0 (352 bytes) ---- */

ulonglong FUN_1800021d0(undefined4 param_1)

{
  longlong lVar1;
  LCID LVar2;
  int iVar3;
  longlong *plVar4;
  uint uVar5;
  ulonglong uVar7;
  undefined4 local_res10 [2];
  wchar_t *local_res18;
  _union_2707 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  _union_2707 local_50;
  VARIANTARG local_38;
  ulonglong uVar6;
  
  plVar4 = (longlong *)FUN_180002330();
  if (plVar4 != (longlong *)0x0) {
    local_res18 = L"ShowUserDefinedWizard";
    lVar1 = *plVar4;
    LVar2 = GetUserDefaultLCID();
    iVar3 = (**(code **)(lVar1 + 0x28))(plVar4,&DAT_1800082f8,&local_res18,1,LVar2,local_res10);
    if (-1 < iVar3) {
      uVar7 = 0;
      local_60 = 0;
      local_58 = 1;
      local_68 = &local_50;
      uVar6 = uVar7;
      do {
        VariantInit((VARIANTARG *)&(&local_50)[uVar6].n2);
        uVar5 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar5;
      } while (uVar5 < (uint)local_58);
      local_50.n2.vt = 3;
      local_50._8_4_ = param_1;
      COleVariant::COleVariant((COleVariant *)&local_38,0,3);
      lVar1 = *plVar4;
      LVar2 = GetUserDefaultLCID();
      iVar3 = (**(code **)(lVar1 + 0x30))
                        (plVar4,local_res10[0],&DAT_1800082f8,LVar2,1,&local_68,&local_38,0,0);
      if (-1 < iVar3) {
        uVar7 = (ulonglong)(uint)local_38.n1._8_4_;
      }
      (**(code **)(*plVar4 + 0x10))(plVar4);
      VariantClear(&local_38);
      return uVar7;
    }
    (**(code **)(*plVar4 + 0x10))(plVar4);
  }
  return 0;
}

/* ---- FUNC 00002330 FUN_180002330 (196 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180002330(void)

{
  int iVar1;
  HRESULT HVar2;
  LPCOLESTR lpszProgID;
  WCHAR local_a8 [64];
  LPVOID local_28;
  CLSID local_20;
  ulonglong local_10;
  
  local_10 = DAT_18000b3e8 ^ (ulonglong)&local_28;
  lpszProgID = (LPCOLESTR)0x0;
  if (local_a8 != (LPWSTR)0x0) {
    local_a8[0] = L'\0';
    iVar1 = MultiByteToWideChar(0,0,"AspenTech.AspenPlus.WpfFindComponent.FindComponentDriver.410",
                                -1,local_a8,0x3d);
    lpszProgID = local_a8;
    if (iVar1 == 0) {
      lpszProgID = (LPCOLESTR)0x0;
    }
  }
  HVar2 = CLSIDFromProgID(lpszProgID,&local_20);
  if (-1 < HVar2) {
    local_28 = (LPVOID)0x0;
    HVar2 = CoCreateInstance(&local_20,(LPUNKNOWN)0x0,1,(IID *)&DAT_180008308,&local_28);
    if (-1 < HVar2) {
      return local_28;
    }
  }
  return 0;
}

/* ---- FUNC 00002400 FUN_180002400 (7 bytes) ---- */

undefined4 FUN_180002400(void)

{
  return DAT_18000b5b4;
}

/* ---- FUNC 00002410 FUN_180002410 (193 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180002410(void)

{
  int iVar1;
  HRESULT HVar2;
  LPCOLESTR lpszProgID;
  WCHAR local_88 [48];
  LPVOID local_28;
  CLSID local_20;
  ulonglong local_10;
  
  local_10 = DAT_18000b3e8 ^ (ulonglong)&local_28;
  lpszProgID = (LPCOLESTR)0x0;
  if (local_88 != (LPWSTR)0x0) {
    local_88[0] = L'\0';
    iVar1 = MultiByteToWideChar(0,0,"AspenTech.AspenPlus.WpfMMDialog.MessageBox.410",-1,local_88,
                                0x2f);
    lpszProgID = local_88;
    if (iVar1 == 0) {
      lpszProgID = (LPCOLESTR)0x0;
    }
  }
  HVar2 = CLSIDFromProgID(lpszProgID,&local_20);
  if (-1 < HVar2) {
    local_28 = (LPVOID)0x0;
    HVar2 = CoCreateInstance(&local_20,(LPUNKNOWN)0x0,1,(IID *)&DAT_180008308,&local_28);
    if (-1 < HVar2) {
      return local_28;
    }
  }
  return 0;
}

/* ---- FUNC 000024E0 FUN_1800024e0 (193 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1800024e0(void)

{
  int iVar1;
  HRESULT HVar2;
  LPCOLESTR lpszProgID;
  WCHAR local_98 [56];
  LPVOID local_28;
  CLSID local_20;
  ulonglong local_10;
  
  local_10 = DAT_18000b3e8 ^ (ulonglong)&local_28;
  lpszProgID = (LPCOLESTR)0x0;
  if (local_98 != (LPWSTR)0x0) {
    local_98[0] = L'\0';
    iVar1 = MultiByteToWideChar(0,0,"AspenTech.AspenPlus.WpfMMDialog.DialogDriver.410",-1,local_98,
                                0x31);
    lpszProgID = local_98;
    if (iVar1 == 0) {
      lpszProgID = (LPCOLESTR)0x0;
    }
  }
  HVar2 = CLSIDFromProgID(lpszProgID,&local_20);
  if (-1 < HVar2) {
    local_28 = (LPVOID)0x0;
    HVar2 = CoCreateInstance(&local_20,(LPUNKNOWN)0x0,1,(IID *)&DAT_180008308,&local_28);
    if (-1 < HVar2) {
      return local_28;
    }
  }
  return 0;
}

/* ---- FUNC 000025B0 FUN_1800025b0 (510 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_1800025b0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                       undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined4 param_8,
                       undefined4 param_9)

{
  longlong lVar1;
  int iVar2;
  LCID LVar3;
  longlong *plVar4;
  uint uVar5;
  ulonglong uVar7;
  undefined1 auStack_1e8 [32];
  LCID local_1c8;
  VARIANTARG **local_1c0;
  VARIANTARG *local_1b8;
  undefined1 *local_1b0;
  undefined1 *local_1a8;
  undefined4 local_198;
  undefined1 local_194 [4];
  wchar_t *local_190;
  _union_2707 *local_188;
  undefined8 local_180;
  undefined8 local_178;
  VARIANTARG local_170;
  undefined1 local_158 [64];
  _union_2707 local_118;
  undefined2 local_100;
  undefined4 local_f8;
  undefined2 local_e8;
  undefined8 local_e0;
  undefined2 local_d0;
  undefined8 local_c8;
  undefined2 local_b8;
  undefined8 local_b0;
  undefined2 local_a0;
  undefined8 local_98;
  undefined2 local_88;
  undefined8 local_80;
  undefined2 local_70;
  undefined8 local_68;
  undefined2 local_58;
  undefined8 local_50;
  ulonglong local_38;
  ulonglong uVar6;
  
  local_38 = DAT_18000b3e8 ^ (ulonglong)auStack_1e8;
  plVar4 = (longlong *)FUN_180002410();
  if (plVar4 != (longlong *)0x0) {
    local_190 = L"ShowOpenMessageBox";
    lVar1 = *plVar4;
    local_1c8 = GetUserDefaultLCID();
    local_1c0 = (VARIANTARG **)&local_198;
    iVar2 = (**(code **)(lVar1 + 0x28))(plVar4,&DAT_1800082f8,&local_190,1);
    if (-1 < iVar2) {
      uVar7 = 0;
      local_180 = 0;
      local_178 = 9;
      local_188 = &local_118;
      uVar6 = uVar7;
      do {
        VariantInit((VARIANTARG *)&(&local_118)[uVar6].n2);
        uVar5 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar5;
      } while (uVar5 < (uint)local_178);
      local_58 = 8;
      local_70 = 8;
      local_88 = 8;
      local_a0 = 8;
      local_b8 = 8;
      local_b0 = param_5;
      local_d0 = 8;
      local_c8 = param_6;
      local_e8 = 8;
      local_e0 = param_7;
      local_100 = 3;
      local_f8 = param_8;
      local_118.n2.vt = 3;
      local_118._8_4_ = param_9;
      local_98 = param_4;
      local_80 = param_3;
      local_68 = param_2;
      local_50 = param_1;
      COleVariant::COleVariant((COleVariant *)&local_170,0,3);
      lVar1 = *plVar4;
      LVar3 = GetUserDefaultLCID();
      local_1a8 = local_194;
      local_1b0 = local_158;
      local_1b8 = &local_170;
      local_1c0 = (VARIANTARG **)&local_188;
      local_1c8 = CONCAT22(local_1c8._2_2_,1);
      iVar2 = (**(code **)(lVar1 + 0x30))(plVar4,local_198,&DAT_1800082f8,LVar3);
      if (-1 < iVar2) {
        uVar7 = (ulonglong)(uint)local_170.n1._8_4_;
      }
      (**(code **)(*plVar4 + 0x10))(plVar4);
      VariantClear(&local_170);
      return uVar7;
    }
    (**(code **)(*plVar4 + 0x10))(plVar4);
  }
  return 0;
}

/* ---- FUNC 000027B0 FUN_1800027b0 (570 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_1800027b0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                       undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined4 param_8,
                       undefined4 *param_9,undefined4 param_10)

{
  longlong lVar1;
  int iVar2;
  LCID LVar3;
  longlong *plVar4;
  uint uVar5;
  ulonglong uVar7;
  undefined1 auStack_208 [32];
  LCID local_1e8;
  VARIANTARG **local_1e0;
  VARIANTARG *local_1d8;
  undefined1 *local_1d0;
  undefined1 *local_1c8;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined1 local_1b0 [8];
  wchar_t *local_1a8;
  undefined8 local_1a0;
  _union_2707 *local_198;
  undefined8 local_190;
  undefined8 local_188;
  VARIANTARG local_180;
  undefined1 local_168 [64];
  _union_2707 local_128;
  undefined2 local_110;
  undefined4 *local_108;
  undefined2 local_f8;
  undefined4 local_f0;
  undefined2 local_e0;
  undefined8 local_d8;
  undefined2 local_c8;
  undefined8 local_c0;
  undefined2 local_b0;
  undefined8 local_a8;
  undefined2 local_98;
  undefined8 local_90;
  undefined2 local_80;
  undefined8 local_78;
  undefined2 local_68;
  undefined8 local_60;
  undefined2 local_50;
  undefined8 local_48;
  ulonglong local_38;
  ulonglong uVar6;
  
  local_38 = DAT_18000b3e8 ^ (ulonglong)auStack_208;
  local_1a0 = param_1;
  plVar4 = (longlong *)FUN_180002410();
  if (plVar4 != (longlong *)0x0) {
    local_1a8 = L"ShowOpenMessageBoxWithCheckBox";
    lVar1 = *plVar4;
    local_1e8 = GetUserDefaultLCID();
    local_1e0 = (VARIANTARG **)&local_1b4;
    iVar2 = (**(code **)(lVar1 + 0x28))(plVar4,&DAT_1800082f8,&local_1a8,1);
    if (-1 < iVar2) {
      uVar7 = 0;
      local_190 = 0;
      local_188 = 10;
      local_198 = &local_128;
      uVar6 = uVar7;
      do {
        VariantInit((VARIANTARG *)&(&local_128)[uVar6].n2);
        uVar5 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar5;
      } while (uVar5 < (uint)local_188);
      local_1b8 = 0xffffffff;
      local_50 = 8;
      local_48 = local_1a0;
      local_68 = 8;
      local_80 = 8;
      local_98 = 8;
      local_b0 = 8;
      local_a8 = param_5;
      local_c8 = 8;
      local_c0 = param_6;
      local_e0 = 8;
      local_d8 = param_7;
      local_f8 = 3;
      local_f0 = param_8;
      local_110 = 0x4016;
      local_108 = &local_1b8;
      local_128.n2.vt = 3;
      local_128._8_4_ = param_10;
      local_90 = param_4;
      local_78 = param_3;
      local_60 = param_2;
      COleVariant::COleVariant((COleVariant *)&local_180,0,3);
      lVar1 = *plVar4;
      LVar3 = GetUserDefaultLCID();
      local_1c8 = local_1b0;
      local_1d0 = local_168;
      local_1d8 = &local_180;
      local_1e0 = (VARIANTARG **)&local_198;
      local_1e8 = CONCAT22(local_1e8._2_2_,1);
      iVar2 = (**(code **)(lVar1 + 0x30))(plVar4,local_1b4,&DAT_1800082f8,LVar3);
      if (-1 < iVar2) {
        uVar7 = (ulonglong)(uint)local_180.n1._8_4_;
        *param_9 = local_1b8;
      }
      (**(code **)(*plVar4 + 0x10))(plVar4);
      VariantClear(&local_180);
      return uVar7;
    }
    (**(code **)(*plVar4 + 0x10))(plVar4);
  }
  return 0;
}

/* ---- FUNC 000029F0 FUN_1800029f0 (281 bytes) ---- */

undefined4 FUN_1800029f0(void)

{
  longlong lVar1;
  LCID LVar2;
  int iVar3;
  longlong *plVar4;
  undefined4 uVar5;
  undefined4 local_res8 [2];
  wchar_t *local_res10;
  VARIANTARG local_48;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  
  plVar4 = (longlong *)FUN_1800024e0();
  if (plVar4 != (longlong *)0x0) {
    local_res10 = L"ShowResultsInconsistentDlg";
    lVar1 = *plVar4;
    LVar2 = GetUserDefaultLCID();
    iVar3 = (**(code **)(lVar1 + 0x28))(plVar4,&DAT_1800082f8,&local_res10,1,LVar2,local_res8);
    if (-1 < iVar3) {
      local_30 = 0;
      uStack_28 = 0;
      local_20 = 0;
      SysAllocString(L"");
      COleVariant::COleVariant((COleVariant *)&local_48,0,3);
      lVar1 = *plVar4;
      LVar2 = GetUserDefaultLCID();
      iVar3 = (**(code **)(lVar1 + 0x30))
                        (plVar4,local_res8[0],&DAT_1800082f8,LVar2,1,&local_30,&local_48,0,0);
      uVar5 = 0;
      if (-1 < iVar3) {
        uVar5 = local_48.n1._8_4_;
      }
      (**(code **)(*plVar4 + 0x10))(plVar4);
      VariantClear(&local_48);
      return uVar5;
    }
    (**(code **)(*plVar4 + 0x10))(plVar4);
  }
  return 0;
}

/* ---- FUNC 00002B10 FUN_180002b10 (742 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180002b10(LPCSTR param_1,LPCSTR param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5,undefined4 param_6)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  LCID LVar4;
  longlong *plVar5;
  uint uVar6;
  ulonglong uVar8;
  undefined1 auStackY_1c8 [32];
  undefined4 local_174;
  BSTR local_170;
  BSTR local_168;
  wchar_t *local_158;
  _union_2707 *local_150;
  undefined8 local_148;
  undefined8 local_140;
  VARIANTARG local_138 [4];
  _union_2707 local_d8;
  undefined2 local_c0;
  undefined4 local_b8;
  undefined2 local_a8;
  undefined4 local_a0;
  undefined2 local_90;
  undefined4 local_88;
  undefined2 local_78;
  BSTR local_70;
  undefined2 local_60;
  BSTR local_58;
  ulonglong local_48;
  ulonglong uVar7;
  
  local_48 = DAT_18000b3e8 ^ (ulonglong)auStackY_1c8;
  plVar5 = (longlong *)FUN_180002410();
  if (plVar5 != (longlong *)0x0) {
    local_158 = L"Show_3";
    lVar1 = *plVar5;
    GetUserDefaultLCID();
    iVar2 = (**(code **)(lVar1 + 0x28))(plVar5,&DAT_1800082f8,&local_158,1);
    if (-1 < iVar2) {
      uVar8 = 0;
      local_148 = 0;
      local_140 = 6;
      local_150 = &local_d8;
      uVar7 = uVar8;
      do {
        VariantInit((VARIANTARG *)&(&local_d8)[uVar7].n2);
        uVar6 = (int)uVar7 + 1;
        uVar7 = (ulonglong)uVar6;
      } while (uVar6 < (uint)local_140);
      if (param_1 == (LPCSTR)0x0) {
        local_170 = (BSTR)0x0;
      }
      else {
        iVar2 = MultiByteToWideChar(0,0,param_1,-1,(LPWSTR)0x0,0);
        local_170 = SysAllocStringLen((OLECHAR *)0x0,iVar2 - 1);
        if ((local_170 != (BSTR)0x0) &&
           (iVar3 = MultiByteToWideChar(0,0,param_1,-1,local_170,iVar2), iVar3 != iVar2)) {
          SysFreeString(local_170);
LAB_180002dd8:
                    /* WARNING: Subroutine does not return */
          FUN_180001060(-0x7ff8fff2);
        }
        if (local_170 == (BSTR)0x0) goto LAB_180002dd8;
      }
      if (param_2 != (LPCSTR)0x0) {
        iVar2 = MultiByteToWideChar(0,0,param_2,-1,(LPWSTR)0x0,0);
        local_168 = SysAllocStringLen((OLECHAR *)0x0,iVar2 - 1);
        if ((local_168 == (BSTR)0x0) ||
           (iVar3 = MultiByteToWideChar(0,0,param_2,-1,local_168,iVar2), iVar3 == iVar2)) {
          if (local_168 != (BSTR)0x0) goto LAB_180002cd1;
        }
        else {
          SysFreeString(local_168);
        }
                    /* WARNING: Subroutine does not return */
        FUN_180001060(-0x7ff8fff2);
      }
      local_168 = (BSTR)0x0;
LAB_180002cd1:
      local_60 = 8;
      local_78 = 8;
      local_90 = 3;
      local_a8 = 3;
      local_c0 = 3;
      local_b8 = param_5;
      local_d8.n2.vt = 3;
      local_d8._8_4_ = param_6;
      local_a0 = param_4;
      local_88 = param_3;
      local_70 = local_168;
      local_58 = local_170;
      COleVariant::COleVariant((COleVariant *)local_138,0,3);
      lVar1 = *plVar5;
      LVar4 = GetUserDefaultLCID();
      iVar2 = (**(code **)(lVar1 + 0x30))(plVar5,local_174,&DAT_1800082f8,LVar4);
      if (-1 < iVar2) {
        uVar8 = (ulonglong)(uint)local_138[0].n1._8_4_;
      }
      (**(code **)(*plVar5 + 0x10))(plVar5);
      VariantClear(local_138);
      SysFreeString(local_168);
      SysFreeString(local_170);
      return uVar8;
    }
    (**(code **)(*plVar5 + 0x10))(plVar5);
  }
  return 0;
}

/* ---- FUNC 00002E00 FUN_180002e00 (390 bytes) ---- */

ulonglong FUN_180002e00(undefined4 *param_1)

{
  longlong lVar1;
  LCID LVar2;
  int iVar3;
  longlong *plVar4;
  uint uVar5;
  ulonglong uVar7;
  undefined4 local_res10 [2];
  undefined4 local_res18 [2];
  undefined1 local_res20 [8];
  wchar_t *local_b8;
  undefined2 *local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined1 local_98 [24];
  VARIANTARG local_80;
  undefined1 local_68 [64];
  ulonglong uVar6;
  
  plVar4 = (longlong *)FUN_1800024e0();
  if (plVar4 != (longlong *)0x0) {
    local_b8 = L"ShowTPSARUpgradeDialog";
    lVar1 = *plVar4;
    LVar2 = GetUserDefaultLCID();
    iVar3 = (**(code **)(lVar1 + 0x28))(plVar4,&DAT_1800082f8,&local_b8,1,LVar2,local_res18);
    if (-1 < iVar3) {
      uVar7 = 0;
      local_a8 = 0;
      local_a0 = 1;
      local_b0 = (undefined2 *)local_98;
      uVar6 = uVar7;
      do {
        VariantInit((VARIANTARG *)(local_98 + uVar6 * 0x18));
        uVar5 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar5;
      } while (uVar5 < (uint)local_a0);
      local_res10[0] = 0xffffffff;
      local_98._0_2_ = 0x4003;
      local_98._8_8_ = local_res10;
      COleVariant::COleVariant((COleVariant *)&local_80,0,3);
      lVar1 = *plVar4;
      LVar2 = GetUserDefaultLCID();
      iVar3 = (**(code **)(lVar1 + 0x30))
                        (plVar4,local_res18[0],&DAT_1800082f8,LVar2,1,&local_b0,&local_80,local_68,
                         local_res20);
      if (-1 < iVar3) {
        uVar7 = (ulonglong)(uint)local_80.n1._8_4_;
        *param_1 = local_res10[0];
      }
      (**(code **)(*plVar4 + 0x10))(plVar4);
      VariantClear(&local_80);
      return uVar7;
    }
    (**(code **)(*plVar4 + 0x10))(plVar4);
  }
  return 0;
}

/* ---- FUNC 00002F90 FUN_180002f90 (33 bytes) ---- */

undefined4 FUN_180002f90(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)GetGlobalPointer("DontShowUpward");
  if (puVar1 == (undefined4 *)0x0) {
    return 0;
  }
  return *puVar1;
}

/* ---- FUNC 00002FC0 FUN_180002fc0 (47 bytes) ---- */

undefined8 FUN_180002fc0(HINSTANCE__ *param_1,int param_2)

{
  if (param_2 == 1) {
    AfxInitExtensionModule((AFX_EXTENSION_MODULE *)&DAT_18000b5b8,param_1);
    DAT_18000b5a8 = param_1;
  }
  return 1;
}

/* ---- FUNC 00002FF0 FindComponentInitExtDLL (54 bytes) ---- */

void FindComponentInitExtDLL(void)

{
  CDynLinkLibrary *this;
  
                    /* 0x2ff0  1  FindComponentInitExtDLL */
  this = operator_new(0x80);
  if (this != (CDynLinkLibrary *)0x0) {
    CDynLinkLibrary::CDynLinkLibrary(this,(AFX_EXTENSION_MODULE *)&DAT_18000b5b8,0);
  }
  DAT_18000b5e0 = AfxGetModuleState();
  return;
}

/* ---- FUNC 00003030 FUN_180003030 (8 bytes) ---- */

undefined * FUN_180003030(void)

{
  return &DAT_18000b608;
}

/* ---- FUNC 00003040 gxAskReconcile (399 bytes) ---- */

ulonglong gxAskReconcile(LPCSTR param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int cchWideChar;
  int iVar3;
  AFX_MODULE_STATE *pAVar4;
  CWinThread *pCVar5;
  longlong lVar6;
  BSTR pOVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  BSTR local_res10;
  AFX_MAINTAIN_STATE2 local_18 [16];
  
                    /* 0x3040  2  gxAskReconcile */
  if (DAT_18000b5e0 == (AFX_MODULE_STATE *)0x0) {
    return 1;
  }
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_18,DAT_18000b5e0);
  uVar2 = DAT_18000b5a8;
  pAVar4 = AfxGetModuleState();
  uVar1 = *(undefined8 *)(pAVar4 + 0x18);
  pAVar4 = AfxGetModuleState();
  *(undefined8 *)(pAVar4 + 0x18) = uVar2;
  pCVar5 = AfxGetThread();
  if ((pCVar5 != (CWinThread *)0x0) &&
     (lVar6 = (**(code **)(*(longlong *)pCVar5 + 0xf8))(), lVar6 != 0)) {
    cchWideChar = MultiByteToWideChar(0,0,"Block ",-1,(LPWSTR)0x0,0);
    pOVar7 = SysAllocStringLen((OLECHAR *)0x0,cchWideChar - 1);
    if ((pOVar7 == (BSTR)0x0) ||
       (iVar3 = MultiByteToWideChar(0,0,"Block ",-1,pOVar7,cchWideChar), iVar3 == cchWideChar)) {
      local_res10 = pOVar7;
      if (pOVar7 != (BSTR)0x0) {
        FUN_1800011e0(&local_res10,param_1);
        FUN_1800011e0(&local_res10," has errors or warnings. Do you wish to reconcile?");
        pOVar7 = local_res10;
        puVar8 = (undefined8 *)
                 ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                 CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                           ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_res10,local_res10);
        uVar9 = FUN_180002b10((LPCSTR)*puVar8,"Reconcile blocks with errors or warnings?",0,0xe,0x20
                              ,2);
        uVar9 = uVar9 & 0xffffffff;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10);
        SysFreeString(pOVar7);
        goto LAB_180003192;
      }
    }
    else {
      SysFreeString(pOVar7);
    }
                    /* WARNING: Subroutine does not return */
    FUN_180001060(-0x7ff8fff2);
  }
  uVar9 = 1;
LAB_180003192:
  pAVar4 = AfxGetModuleState();
  *(undefined8 *)(pAVar4 + 0x18) = uVar1;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_18);
  return uVar9;
}

/* ---- FUNC 000031D0 gxElectrolyteWizard (139 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 gxElectrolyteWizard(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  AFX_MODULE_STATE *pAVar4;
  CWinThread *pCVar5;
  longlong lVar6;
  AFX_MAINTAIN_STATE2 local_18 [16];
  
                    /* 0x31d0  4  gxElectrolyteWizard */
  if (DAT_18000b5e0 != (AFX_MODULE_STATE *)0x0) {
    AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_18,DAT_18000b5e0);
    uVar2 = DAT_18000b5a8;
    pAVar4 = AfxGetModuleState();
    uVar1 = *(undefined8 *)(pAVar4 + 0x18);
    pAVar4 = AfxGetModuleState();
    *(undefined8 *)(pAVar4 + 0x18) = uVar2;
    pCVar5 = AfxGetThread();
    if (pCVar5 != (CWinThread *)0x0) {
      lVar6 = (**(code **)(*(longlong *)pCVar5 + 0xf8))(pCVar5);
      if (lVar6 != 0) {
        _DAT_18000b5ec = 0;
        uVar3 = FUN_180002400();
        FUN_180001490(uVar3);
      }
    }
    pAVar4 = AfxGetModuleState();
    *(undefined8 *)(pAVar4 + 0x18) = uVar1;
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_18);
  }
  return 0;
}

/* ---- FUNC 00003260 gxFindTemplate (195 bytes) ---- */

ulonglong gxFindTemplate(longlong *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  AFX_MODULE_STATE *pAVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  AFX_MAINTAIN_STATE2 local_258 [16];
  CMMDialog local_248 [328];
  undefined8 local_100;
  
                    /* 0x3260  5  gxFindTemplate */
  if (DAT_18000b5e0 == (AFX_MODULE_STATE *)0x0) {
    uVar5 = 0;
  }
  else {
    AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_258,DAT_18000b5e0);
    uVar2 = DAT_18000b5a8;
    pAVar3 = AfxGetModuleState();
    uVar1 = *(undefined8 *)(pAVar3 + 0x18);
    pAVar3 = AfxGetModuleState();
    *(undefined8 *)(pAVar3 + 0x18) = uVar2;
    *param_2 = 0;
    FUN_1800043c0(local_248,param_1,(CWnd *)0x0);
    uVar4 = CMMDialog::DoModal(local_248);
    *param_2 = local_100;
    uVar5 = 0xffffffff;
    if (uVar4 < 0x80000000) {
      uVar5 = uVar4 & 0xffffffff;
    }
    FUN_180004460((CDialog *)local_248);
    pAVar3 = AfxGetModuleState();
    *(undefined8 *)(pAVar3 + 0x18) = uVar1;
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_258);
  }
  return uVar5;
}

/* ---- FUNC 00003330 gxOpen_message_box (68 bytes) ---- */

void gxOpen_message_box(LPCSTR param_1,LPCSTR param_2,LPCSTR param_3,LPCSTR param_4,LPCSTR param_5,
                       LPCSTR param_6,LPCSTR param_7,uint param_8)

{
                    /* 0x3330  6  gxOpen_message_box */
  gxOpen_message_box2(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_8);
  return;
}

/* ---- FUNC 00003380 gxOpen_message_box2 (49 bytes) ---- */

BSTR gxOpen_message_box2(LPCSTR param_1,LPCSTR param_2,LPCSTR param_3,LPCSTR param_4,LPCSTR param_5,
                        LPCSTR param_6,LPCSTR param_7,uint param_8,undefined4 param_9)

{
  int iVar1;
  int iVar2;
  BSTR pOVar3;
  BSTR lpWideCharStr;
  BSTR lpWideCharStr_00;
  BSTR lpWideCharStr_01;
  BSTR lpWideCharStr_02;
  BSTR lpWideCharStr_03;
  BSTR lpWideCharStr_04;
  ulonglong uVar4;
  BSTR pOVar5;
  AFX_MAINTAIN_STATE2 local_50 [24];
  
                    /* 0x3380  7  gxOpen_message_box2 */
  if (DAT_18000b5e0 == (AFX_MODULE_STATE *)0x0) {
    return (BSTR)0x0;
  }
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_50,DAT_18000b5e0);
  iVar1 = MMGetSuppress();
  if (iVar1 == 0) {
    pOVar5 = (BSTR)0x0;
    pOVar3 = pOVar5;
    if (param_7 != (LPCSTR)0x0) {
      iVar1 = MultiByteToWideChar(0,0,param_7,-1,(LPWSTR)0x0,0);
      pOVar3 = SysAllocStringLen((OLECHAR *)0x0,iVar1 - 1);
      if ((pOVar3 != (BSTR)0x0) &&
         (iVar2 = MultiByteToWideChar(0,0,param_7,-1,pOVar3,iVar1), iVar2 != iVar1)) {
        SysFreeString(pOVar3);
        goto LAB_180003838;
      }
      if (pOVar3 == (BSTR)0x0) goto LAB_180003838;
    }
    lpWideCharStr = pOVar5;
    if (param_6 != (LPCSTR)0x0) {
      iVar1 = MultiByteToWideChar(0,0,param_6,-1,(LPWSTR)0x0,0);
      lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,iVar1 - 1);
      if ((lpWideCharStr != (BSTR)0x0) &&
         (iVar2 = MultiByteToWideChar(0,0,param_6,-1,lpWideCharStr,iVar1), iVar2 != iVar1)) {
        SysFreeString(lpWideCharStr);
        goto LAB_180003838;
      }
      if (lpWideCharStr == (BSTR)0x0) goto LAB_180003838;
    }
    lpWideCharStr_00 = pOVar5;
    if (param_5 != (LPCSTR)0x0) {
      iVar1 = MultiByteToWideChar(0,0,param_5,-1,(LPWSTR)0x0,0);
      lpWideCharStr_00 = SysAllocStringLen((OLECHAR *)0x0,iVar1 - 1);
      if ((lpWideCharStr_00 != (BSTR)0x0) &&
         (iVar2 = MultiByteToWideChar(0,0,param_5,-1,lpWideCharStr_00,iVar1), iVar2 != iVar1)) {
        SysFreeString(lpWideCharStr_00);
        goto LAB_180003838;
      }
      if (lpWideCharStr_00 == (BSTR)0x0) goto LAB_180003838;
    }
    lpWideCharStr_01 = pOVar5;
    if (param_4 != (LPCSTR)0x0) {
      iVar1 = MultiByteToWideChar(0,0,param_4,-1,(LPWSTR)0x0,0);
      lpWideCharStr_01 = SysAllocStringLen((OLECHAR *)0x0,iVar1 - 1);
      if ((lpWideCharStr_01 != (BSTR)0x0) &&
         (iVar2 = MultiByteToWideChar(0,0,param_4,-1,lpWideCharStr_01,iVar1), iVar2 != iVar1)) {
        SysFreeString(lpWideCharStr_01);
        goto LAB_180003838;
      }
      if (lpWideCharStr_01 == (BSTR)0x0) goto LAB_180003838;
    }
    lpWideCharStr_02 = pOVar5;
    if (param_3 != (LPCSTR)0x0) {
      iVar1 = MultiByteToWideChar(0,0,param_3,-1,(LPWSTR)0x0,0);
      lpWideCharStr_02 = SysAllocStringLen((OLECHAR *)0x0,iVar1 - 1);
      if ((lpWideCharStr_02 != (BSTR)0x0) &&
         (iVar2 = MultiByteToWideChar(0,0,param_3,-1,lpWideCharStr_02,iVar1), iVar2 != iVar1)) {
        SysFreeString(lpWideCharStr_02);
        goto LAB_180003838;
      }
      if (lpWideCharStr_02 == (BSTR)0x0) goto LAB_180003838;
    }
    lpWideCharStr_03 = pOVar5;
    if (param_2 != (LPCSTR)0x0) {
      iVar1 = MultiByteToWideChar(0,0,param_2,-1,(LPWSTR)0x0,0);
      lpWideCharStr_03 = SysAllocStringLen((OLECHAR *)0x0,iVar1 - 1);
      if ((lpWideCharStr_03 != (BSTR)0x0) &&
         (iVar2 = MultiByteToWideChar(0,0,param_2,-1,lpWideCharStr_03,iVar1), iVar2 != iVar1)) {
        SysFreeString(lpWideCharStr_03);
        goto LAB_180003838;
      }
      if (lpWideCharStr_03 == (BSTR)0x0) goto LAB_180003838;
    }
    lpWideCharStr_04 = pOVar5;
    if (param_1 != (LPCSTR)0x0) {
      iVar1 = MultiByteToWideChar(0,0,param_1,-1,(LPWSTR)0x0,0);
      lpWideCharStr_04 = SysAllocStringLen((OLECHAR *)0x0,iVar1 - 1);
      if ((lpWideCharStr_04 != (BSTR)0x0) &&
         (iVar2 = MultiByteToWideChar(0,0,param_1,-1,lpWideCharStr_04,iVar1), iVar2 != iVar1)) {
        SysFreeString(lpWideCharStr_04);
LAB_180003838:
                    /* WARNING: Subroutine does not return */
        FUN_180001060(-0x7ff8fff2);
      }
      if (lpWideCharStr_04 == (BSTR)0x0) goto LAB_180003838;
    }
    uVar4 = FUN_1800025b0(lpWideCharStr_04,lpWideCharStr_03,lpWideCharStr_02,lpWideCharStr_01,
                          lpWideCharStr_00,lpWideCharStr,pOVar3,param_8,param_9);
    SysFreeString(lpWideCharStr_04);
    SysFreeString(lpWideCharStr_03);
    SysFreeString(lpWideCharStr_02);
    SysFreeString(lpWideCharStr_01);
    SysFreeString(lpWideCharStr_00);
    SysFreeString(lpWideCharStr);
    SysFreeString(pOVar3);
    pOVar3 = (BSTR)(uVar4 & 0xffffffff);
    if ((int)uVar4 == -1) {
      pOVar3 = pOVar5;
    }
  }
  else {
    pOVar3 = (BSTR)(ulonglong)param_8;
  }
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_50);
  return pOVar3;
}

/* ---- FUNC 000033B1 FUN_1800033b1 (1150 bytes) ---- */

BSTR FUN_1800033b1(undefined8 param_1,AFX_MODULE_STATE *param_2)

{
  int iVar1;
  int iVar2;
  BSTR pOVar3;
  BSTR lpWideCharStr;
  BSTR lpWideCharStr_00;
  BSTR lpWideCharStr_01;
  BSTR lpWideCharStr_02;
  BSTR lpWideCharStr_03;
  BSTR lpWideCharStr_04;
  ulonglong uVar4;
  LPCSTR unaff_RSI;
  BSTR pOVar5;
  LPCSTR in_stack_000000b0;
  LPCSTR in_stack_000000b8;
  LPCSTR in_stack_000000c0;
  LPCSTR in_stack_000000d0;
  LPCSTR in_stack_000000d8;
  LPCSTR in_stack_000000e0;
  uint in_stack_000000e8;
  undefined4 in_stack_000000f0;
  
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)&stack0x00000058,param_2);
  iVar1 = MMGetSuppress();
  if (iVar1 == 0) {
    pOVar5 = (BSTR)0x0;
    pOVar3 = pOVar5;
    if (in_stack_000000e0 != (LPCSTR)0x0) {
      iVar1 = MultiByteToWideChar(0,0,in_stack_000000e0,-1,(LPWSTR)0x0,0);
      pOVar3 = SysAllocStringLen((OLECHAR *)0x0,iVar1 - 1);
      if ((pOVar3 != (BSTR)0x0) &&
         (iVar2 = MultiByteToWideChar(0,0,in_stack_000000e0,-1,pOVar3,iVar1), iVar2 != iVar1)) {
        SysFreeString(pOVar3);
        goto LAB_180003838;
      }
      if (pOVar3 == (BSTR)0x0) goto LAB_180003838;
    }
    lpWideCharStr = pOVar5;
    if (in_stack_000000d8 != (LPCSTR)0x0) {
      iVar1 = MultiByteToWideChar(0,0,in_stack_000000d8,-1,(LPWSTR)0x0,0);
      lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,iVar1 - 1);
      if ((lpWideCharStr != (BSTR)0x0) &&
         (iVar2 = MultiByteToWideChar(0,0,in_stack_000000d8,-1,lpWideCharStr,iVar1), iVar2 != iVar1)
         ) {
        SysFreeString(lpWideCharStr);
        goto LAB_180003838;
      }
      if (lpWideCharStr == (BSTR)0x0) goto LAB_180003838;
    }
    lpWideCharStr_00 = pOVar5;
    if (in_stack_000000d0 != (LPCSTR)0x0) {
      iVar1 = MultiByteToWideChar(0,0,in_stack_000000d0,-1,(LPWSTR)0x0,0);
      lpWideCharStr_00 = SysAllocStringLen((OLECHAR *)0x0,iVar1 - 1);
      if ((lpWideCharStr_00 != (BSTR)0x0) &&
         (iVar2 = MultiByteToWideChar(0,0,in_stack_000000d0,-1,lpWideCharStr_00,iVar1),
         iVar2 != iVar1)) {
        SysFreeString(lpWideCharStr_00);
        goto LAB_180003838;
      }
      if (lpWideCharStr_00 == (BSTR)0x0) goto LAB_180003838;
    }
    lpWideCharStr_01 = pOVar5;
    if (unaff_RSI != (LPCSTR)0x0) {
      iVar1 = MultiByteToWideChar(0,0,unaff_RSI,-1,(LPWSTR)0x0,0);
      lpWideCharStr_01 = SysAllocStringLen((OLECHAR *)0x0,iVar1 - 1);
      if ((lpWideCharStr_01 != (BSTR)0x0) &&
         (iVar2 = MultiByteToWideChar(0,0,unaff_RSI,-1,lpWideCharStr_01,iVar1), iVar2 != iVar1)) {
        SysFreeString(lpWideCharStr_01);
        goto LAB_180003838;
      }
      if (lpWideCharStr_01 == (BSTR)0x0) goto LAB_180003838;
    }
    lpWideCharStr_02 = pOVar5;
    if (in_stack_000000c0 != (LPCSTR)0x0) {
      iVar1 = MultiByteToWideChar(0,0,in_stack_000000c0,-1,(LPWSTR)0x0,0);
      lpWideCharStr_02 = SysAllocStringLen((OLECHAR *)0x0,iVar1 - 1);
      if ((lpWideCharStr_02 != (BSTR)0x0) &&
         (iVar2 = MultiByteToWideChar(0,0,in_stack_000000c0,-1,lpWideCharStr_02,iVar1),
         iVar2 != iVar1)) {
        SysFreeString(lpWideCharStr_02);
        goto LAB_180003838;
      }
      if (lpWideCharStr_02 == (BSTR)0x0) goto LAB_180003838;
    }
    lpWideCharStr_03 = pOVar5;
    if (in_stack_000000b8 != (LPCSTR)0x0) {
      iVar1 = MultiByteToWideChar(0,0,in_stack_000000b8,-1,(LPWSTR)0x0,0);
      lpWideCharStr_03 = SysAllocStringLen((OLECHAR *)0x0,iVar1 - 1);
      if ((lpWideCharStr_03 != (BSTR)0x0) &&
         (iVar2 = MultiByteToWideChar(0,0,in_stack_000000b8,-1,lpWideCharStr_03,iVar1),
         iVar2 != iVar1)) {
        SysFreeString(lpWideCharStr_03);
        goto LAB_180003838;
      }
      if (lpWideCharStr_03 == (BSTR)0x0) goto LAB_180003838;
    }
    lpWideCharStr_04 = pOVar5;
    if (in_stack_000000b0 != (LPCSTR)0x0) {
      iVar1 = MultiByteToWideChar(0,0,in_stack_000000b0,-1,(LPWSTR)0x0,0);
      lpWideCharStr_04 = SysAllocStringLen((OLECHAR *)0x0,iVar1 - 1);
      if ((lpWideCharStr_04 != (BSTR)0x0) &&
         (iVar2 = MultiByteToWideChar(0,0,in_stack_000000b0,-1,lpWideCharStr_04,iVar1),
         iVar2 != iVar1)) {
        SysFreeString(lpWideCharStr_04);
LAB_180003838:
                    /* WARNING: Subroutine does not return */
        FUN_180001060(-0x7ff8fff2);
      }
      if (lpWideCharStr_04 == (BSTR)0x0) goto LAB_180003838;
    }
    uVar4 = FUN_1800025b0(lpWideCharStr_04,lpWideCharStr_03,lpWideCharStr_02,lpWideCharStr_01,
                          lpWideCharStr_00,lpWideCharStr,pOVar3,in_stack_000000e8,in_stack_000000f0)
    ;
    SysFreeString(lpWideCharStr_04);
    SysFreeString(lpWideCharStr_03);
    SysFreeString(lpWideCharStr_02);
    SysFreeString(lpWideCharStr_01);
    SysFreeString(lpWideCharStr_00);
    SysFreeString(lpWideCharStr);
    SysFreeString(pOVar3);
    pOVar3 = (BSTR)(uVar4 & 0xffffffff);
    if ((int)uVar4 == -1) {
      pOVar3 = pOVar5;
    }
  }
  else {
    pOVar3 = (BSTR)(ulonglong)in_stack_000000e8;
  }
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)&stack0x00000058);
  return pOVar3;
}

/* ---- FUNC 0000382F FUN_18000382f (19 bytes) ---- */

void FUN_18000382f(void)

{
  BSTR unaff_R12;
  
  SysFreeString(unaff_R12);
                    /* WARNING: Subroutine does not return */
  FUN_180001060(-0x7ff8fff2);
}

/* ---- FUNC 00003850 gxOpen_message_box_wcheck (696 bytes) ---- */

ulonglong gxOpen_message_box_wcheck
                    (LPCSTR param_1,LPCSTR param_2,LPCSTR param_3,LPCSTR param_4,LPCSTR param_5,
                    LPCSTR param_6,LPCSTR param_7,uint param_8,undefined4 *param_9)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  int iVar8;
  BOOL BVar9;
  AFX_MODULE_STATE *pAVar10;
  CWinThread *pCVar11;
  CWnd *pCVar12;
  HWND pHVar13;
  CWnd *pCVar14;
  undefined8 *puVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  CWnd *pCVar18;
  undefined4 local_88 [2];
  BSTR local_80;
  BSTR local_78;
  BSTR local_70;
  BSTR local_68;
  BSTR local_60;
  BSTR local_58;
  BSTR local_50;
  AFX_MAINTAIN_STATE2 local_48 [16];
  
                    /* 0x3850  8  gxOpen_message_box_wcheck */
  iVar8 = MMGetSuppress();
  if (iVar8 != 0) {
    return (ulonglong)param_8;
  }
  if (DAT_18000b5e0 == (AFX_MODULE_STATE *)0x0) {
    return 0;
  }
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_48,DAT_18000b5e0);
  uVar2 = DAT_18000b5a8;
  pAVar10 = AfxGetModuleState();
  uVar1 = *(undefined8 *)(pAVar10 + 0x18);
  pAVar10 = AfxGetModuleState();
  *(undefined8 *)(pAVar10 + 0x18) = uVar2;
  pCVar11 = AfxGetThread();
  if ((pCVar11 != (CWinThread *)0x0) &&
     (pCVar12 = (CWnd *)(**(code **)(*(longlong *)pCVar11 + 0xf8))(pCVar11), pCVar12 != (CWnd *)0x0)
     ) {
    pHVar13 = GetForegroundWindow();
    pCVar14 = CWnd::FromHandle(pHVar13);
    if (pCVar14 == pCVar12) {
      pCVar18 = pCVar14 + 0x40;
LAB_180003a90:
      if (pCVar14 == (CWnd *)0x0) {
        pHVar13 = (HWND)0x0;
      }
      else {
        pHVar13 = *(HWND *)pCVar18;
      }
      local_88[0] = 1;
      SendMessageA(pHVar13,0x4d2,0,0);
    }
    else {
      if (pCVar14 == (CWnd *)0x0) {
        pHVar13 = (HWND)0x0;
      }
      else {
        pHVar13 = *(HWND *)(pCVar14 + 0x40);
      }
      pCVar18 = (CWnd *)0x40;
      if (pCVar14 != (CWnd *)0x0) {
        pCVar18 = pCVar14 + 0x40;
      }
      BVar9 = IsChild(*(HWND *)(pCVar12 + 0x40),pHVar13);
      if (BVar9 != 0) goto LAB_180003a90;
      local_88[0] = 1;
    }
    puVar15 = FUN_1800010f0(&local_50,param_7);
    uVar2 = *puVar15;
    puVar15 = FUN_1800010f0(&local_58,param_6);
    uVar3 = *puVar15;
    puVar15 = FUN_1800010f0(&local_60,param_5);
    uVar4 = *puVar15;
    puVar15 = FUN_1800010f0(&local_68,param_4);
    uVar5 = *puVar15;
    puVar15 = FUN_1800010f0(&local_70,param_3);
    uVar6 = *puVar15;
    puVar15 = FUN_1800010f0(&local_78,param_2);
    uVar7 = *puVar15;
    puVar15 = FUN_1800010f0(&local_80,param_1);
    uVar16 = FUN_1800027b0(*puVar15,uVar7,uVar6,uVar5,uVar4,uVar3,uVar2,param_8,local_88,0xffffffff)
    ;
    uVar17 = uVar16 & 0xffffffff;
    SysFreeString(local_80);
    SysFreeString(local_78);
    SysFreeString(local_70);
    SysFreeString(local_68);
    SysFreeString(local_60);
    SysFreeString(local_58);
    SysFreeString(local_50);
    if ((int)uVar16 != -1) {
      *param_9 = local_88[0];
      goto LAB_180003ad5;
    }
  }
  uVar17 = 0;
LAB_180003ad5:
  pAVar10 = AfxGetModuleState();
  *(undefined8 *)(pAVar10 + 0x18) = uVar1;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_48);
  return uVar17;
}

/* ---- FUNC 00003B10 gxPure_component_param (224 bytes) ---- */

undefined8 gxPure_component_param(char *param_1)

{
  undefined8 uVar1;
  AFX_MODULE_STATE *pAVar2;
  CWinThread *pCVar3;
  longlong lVar4;
  ulonglong uVar5;
  LPSTR _Source;
  undefined8 uVar6;
  LPCWSTR local_res10;
  AFX_MAINTAIN_STATE2 local_18 [16];
  
                    /* 0x3b10  9  gxPure_component_param */
  if (DAT_18000b5e0 == (AFX_MODULE_STATE *)0x0) {
    return 0;
  }
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_18,DAT_18000b5e0);
  uVar6 = DAT_18000b5a8;
  pAVar2 = AfxGetModuleState();
  uVar1 = *(undefined8 *)(pAVar2 + 0x18);
  pAVar2 = AfxGetModuleState();
  *(undefined8 *)(pAVar2 + 0x18) = uVar6;
  pCVar3 = AfxGetThread();
  if (pCVar3 != (CWinThread *)0x0) {
    lVar4 = (**(code **)(*(longlong *)pCVar3 + 0xf8))(pCVar3);
    if (lVar4 != 0) {
      uVar6 = 0;
      local_res10 = (LPCWSTR)0x0;
      uVar5 = FUN_1800015f0(&local_res10);
      if (((int)uVar5 == 1) && (local_res10 != (LPCWSTR)0x0)) {
        if (param_1 != (char *)0x0) {
          _Source = FUN_180005d10(local_res10);
          strncpy(param_1,_Source,0x20);
        }
        uVar6 = 1;
      }
      else if (param_1 != (char *)0x0) {
        *param_1 = '\0';
      }
      goto LAB_180003bcb;
    }
  }
  uVar6 = 0;
LAB_180003bcb:
  pAVar2 = AfxGetModuleState();
  *(undefined8 *)(pAVar2 + 0x18) = uVar1;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_18);
  return uVar6;
}

/* ---- FUNC 00003BF0 gxReorderComp (165 bytes) ---- */

undefined8 gxReorderComp(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  AFX_MODULE_STATE *pAVar3;
  CWinThread *pCVar4;
  longlong lVar5;
  _union_1719 bstrString;
  AFX_MAINTAIN_STATE2 local_18 [16];
  
                    /* 0x3bf0  10  gxReorderComp */
  if (DAT_18000b5e0 != (AFX_MODULE_STATE *)0x0) {
    AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_18,DAT_18000b5e0);
    uVar2 = DAT_18000b5a8;
    pAVar3 = AfxGetModuleState();
    uVar1 = *(undefined8 *)(pAVar3 + 0x18);
    pAVar3 = AfxGetModuleState();
    *(undefined8 *)(pAVar3 + 0x18) = uVar2;
    pCVar4 = AfxGetThread();
    if (pCVar4 != (CWinThread *)0x0) {
      lVar5 = (**(code **)(*(longlong *)pCVar4 + 0xf8))(pCVar4);
      if (lVar5 != 0) {
        bstrString = (_union_1719)SysAllocString(L"ReorderComp");
        if (bstrString.Lo64 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_180001060(-0x7ff8fff2);
        }
        FUN_180001320(bstrString);
        SysFreeString((BSTR)bstrString);
      }
    }
    pAVar3 = AfxGetModuleState();
    *(undefined8 *)(pAVar3 + 0x18) = uVar1;
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_18);
  }
  return 0;
}

/* ---- FUNC 00003CA0 gxResults_inconsistent_dialog (90 bytes) ---- */

int gxResults_inconsistent_dialog(void)

{
  int iVar1;
  AFX_MAINTAIN_STATE2 local_18 [16];
  
                    /* 0x3ca0  11  gxResults_inconsistent_dialog */
  if (DAT_18000b5e0 != (AFX_MODULE_STATE *)0x0) {
    AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_18,DAT_18000b5e0);
    iVar1 = MMGetSuppress();
    if (iVar1 == 0) {
      iVar1 = FUN_1800029f0();
      if (iVar1 == -1) {
        iVar1 = 0;
      }
    }
    else {
      iVar1 = 0;
    }
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_18);
    return iVar1;
  }
  return 0;
}

/* ---- FUNC 00003D00 gxSFEAssistant (129 bytes) ---- */

undefined8 gxSFEAssistant(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  AFX_MODULE_STATE *pAVar4;
  CWinThread *pCVar5;
  longlong lVar6;
  AFX_MAINTAIN_STATE2 local_18 [16];
  
                    /* 0x3d00  12  gxSFEAssistant */
  if (DAT_18000b5e0 != (AFX_MODULE_STATE *)0x0) {
    AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_18,DAT_18000b5e0);
    uVar2 = DAT_18000b5a8;
    pAVar4 = AfxGetModuleState();
    uVar1 = *(undefined8 *)(pAVar4 + 0x18);
    pAVar4 = AfxGetModuleState();
    *(undefined8 *)(pAVar4 + 0x18) = uVar2;
    pCVar5 = AfxGetThread();
    if (pCVar5 != (CWinThread *)0x0) {
      lVar6 = (**(code **)(*(longlong *)pCVar5 + 0xf8))(pCVar5);
      if (lVar6 != 0) {
        uVar3 = FUN_180002400();
        FUN_180001780(uVar3);
      }
    }
    pAVar4 = AfxGetModuleState();
    *(undefined8 *)(pAVar4 + 0x18) = uVar1;
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_18);
  }
  return 0;
}

/* ---- FUNC 00003D90 gxSFEAssistantMain (129 bytes) ---- */

undefined8 gxSFEAssistantMain(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  AFX_MODULE_STATE *pAVar4;
  CWinThread *pCVar5;
  longlong lVar6;
  AFX_MAINTAIN_STATE2 local_18 [16];
  
                    /* 0x3d90  13  gxSFEAssistantMain */
  if (DAT_18000b5e0 != (AFX_MODULE_STATE *)0x0) {
    AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_18,DAT_18000b5e0);
    uVar2 = DAT_18000b5a8;
    pAVar4 = AfxGetModuleState();
    uVar1 = *(undefined8 *)(pAVar4 + 0x18);
    pAVar4 = AfxGetModuleState();
    *(undefined8 *)(pAVar4 + 0x18) = uVar2;
    pCVar5 = AfxGetThread();
    if (pCVar5 != (CWinThread *)0x0) {
      lVar6 = (**(code **)(*(longlong *)pCVar5 + 0xf8))(pCVar5);
      if (lVar6 != 0) {
        uVar3 = FUN_180002400();
        FUN_1800018e0(uVar3);
      }
    }
    pAVar4 = AfxGetModuleState();
    *(undefined8 *)(pAVar4 + 0x18) = uVar1;
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_18);
  }
  return 0;
}

/* ---- FUNC 00003E20 gxSearchComponents (243 bytes) ---- */

ulonglong gxSearchComponents(undefined8 param_1,int param_2,LPCSTR param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  uint uVar4;
  AFX_MODULE_STATE *pAVar5;
  CWinThread *pCVar6;
  longlong lVar7;
  BSTR bstrString;
  _union_1719 *p_Var8;
  ulonglong uVar9;
  BSTR local_res20;
  AFX_MAINTAIN_STATE2 local_28 [16];
  
                    /* 0x3e20  14  gxSearchComponents */
  if (DAT_18000b5e0 == (AFX_MODULE_STATE *)0x0) {
    return 0;
  }
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_28,DAT_18000b5e0);
  uVar2 = DAT_18000b5a8;
  pAVar5 = AfxGetModuleState();
  uVar1 = *(undefined8 *)(pAVar5 + 0x18);
  pAVar5 = AfxGetModuleState();
  *(undefined8 *)(pAVar5 + 0x18) = uVar2;
  pCVar6 = AfxGetThread();
  if ((pCVar6 == (CWinThread *)0x0) ||
     (lVar7 = (**(code **)(*(longlong *)pCVar6 + 0xf8))(pCVar6), lVar7 == 0)) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0;
    iVar3 = MMGetSuppress();
    if (iVar3 == 0) {
      iVar3 = 0;
      if (-1 < param_2) {
        iVar3 = param_2;
      }
      bstrString = SysAllocString(L"Happ");
      if (bstrString == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_180001060(-0x7ff8fff2);
      }
      p_Var8 = (_union_1719 *)FUN_1800010f0(&local_res20,param_3);
      uVar9 = FUN_180001a40(bstrString,iVar3,*p_Var8);
      uVar4 = (uint)uVar9;
      SysFreeString(bstrString);
      SysFreeString(local_res20);
    }
  }
  pAVar5 = AfxGetModuleState();
  *(undefined8 *)(pAVar5 + 0x18) = uVar1;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_28);
  return (ulonglong)uVar4;
}

/* ---- FUNC 00003F20 gxSearchProperty (271 bytes) ---- */

undefined8 gxSearchProperty(LPCSTR param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int cchWideChar;
  int iVar3;
  AFX_MODULE_STATE *pAVar4;
  CWinThread *pCVar5;
  longlong lVar6;
  _union_1719 lpWideCharStr;
  AFX_MAINTAIN_STATE2 local_18 [16];
  
                    /* 0x3f20  15  gxSearchProperty */
  if (DAT_18000b5e0 != (AFX_MODULE_STATE *)0x0) {
    AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_18,DAT_18000b5e0);
    uVar2 = DAT_18000b5a8;
    pAVar4 = AfxGetModuleState();
    uVar1 = *(undefined8 *)(pAVar4 + 0x18);
    pAVar4 = AfxGetModuleState();
    *(undefined8 *)(pAVar4 + 0x18) = uVar2;
    pCVar5 = AfxGetThread();
    if (pCVar5 != (CWinThread *)0x0) {
      lVar6 = (**(code **)(*(longlong *)pCVar5 + 0xf8))(pCVar5);
      if (lVar6 != 0) {
        lpWideCharStr.Lo64 = 0;
        if (param_1 != (LPCSTR)0x0) {
          cchWideChar = MultiByteToWideChar(0,0,param_1,-1,(LPWSTR)0x0,0);
          lpWideCharStr = (_union_1719)SysAllocStringLen((OLECHAR *)0x0,cchWideChar - 1);
          if ((BSTR)lpWideCharStr.Lo64 != (BSTR)0x0) {
            iVar3 = MultiByteToWideChar(0,0,param_1,-1,(LPWSTR)lpWideCharStr,cchWideChar);
            if (iVar3 != cchWideChar) {
              SysFreeString((BSTR)lpWideCharStr);
              goto LAB_180004025;
            }
          }
          if ((BSTR)lpWideCharStr.Lo64 == (BSTR)0x0) {
LAB_180004025:
                    /* WARNING: Subroutine does not return */
            FUN_180001060(-0x7ff8fff2);
          }
        }
        FUN_180001c00(lpWideCharStr);
        SysFreeString((BSTR)lpWideCharStr);
      }
    }
    pAVar4 = AfxGetModuleState();
    *(undefined8 *)(pAVar4 + 0x18) = uVar1;
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_18);
  }
  return 0;
}

/* ---- FUNC 00004030 gxSetApedFlag (7 bytes) ---- */

void gxSetApedFlag(undefined4 param_1)

{
                    /* 0x4030  16  gxSetApedFlag */
  DAT_18000b5b4 = param_1;
  return;
}

/* ---- FUNC 00004040 gxShowTPSARUpgradeDialog (56 bytes) ---- */

ulonglong gxShowTPSARUpgradeDialog(undefined4 *param_1)

{
  int iVar1;
  ulonglong uVar2;
  undefined4 local_res10 [6];
  
                    /* 0x4040  18  gxShowTPSARUpgradeDialog */
  iVar1 = MMGetSuppress();
  if (iVar1 != 0) {
    return 0;
  }
  local_res10[0] = 0;
  uVar2 = FUN_180002e00(local_res10);
  *param_1 = local_res10[0];
  return uVar2;
}

/* ---- FUNC 00004080 gxUpgradeRetired (381 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
gxUpgradeRetired(undefined4 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  int iVar2;
  DWORD DVar3;
  DWORD DVar4;
  undefined4 uVar5;
  AFX_MODULE_STATE *pAVar6;
  CWinThread *pCVar7;
  longlong lVar8;
  undefined8 uVar9;
  undefined1 auStack_458 [32];
  undefined4 local_438 [2];
  AFX_MAINTAIN_STATE2 local_430 [24];
  CHAR local_418 [1024];
  ulonglong local_18;
  
                    /* 0x4080  19  gxUpgradeRetired */
  local_18 = DAT_18000b3e8 ^ (ulonglong)auStack_458;
  if (DAT_18000b5e0 != (AFX_MODULE_STATE *)0x0) {
    AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_430,DAT_18000b5e0);
    uVar9 = DAT_18000b5a8;
    pAVar6 = AfxGetModuleState();
    uVar1 = *(undefined8 *)(pAVar6 + 0x18);
    pAVar6 = AfxGetModuleState();
    *(undefined8 *)(pAVar6 + 0x18) = uVar9;
    pCVar7 = AfxGetThread();
    if ((pCVar7 == (CWinThread *)0x0) ||
       (lVar8 = (**(code **)(*(longlong *)pCVar7 + 0xf8))(pCVar7), lVar8 == 0)) {
      uVar9 = 0;
    }
    else {
      iVar2 = FUN_180002f90();
      if (iVar2 == 0) {
        DVar3 = GetTickCount();
        DVar4 = GetTickCount();
        FUN_180004360(local_418,
                      "\n+++++++++++++ CComPtr<AspenTech_AspenPlus_WpfFindComponent::IFindComponentDriver>: %d\n"
                      ,(ulonglong)(DVar4 - DVar3),param_4);
        OutputDebugStringA(local_418);
        DVar3 = GetTickCount();
        uVar5 = FUN_180002400();
        local_438[0] = 0;
        FUN_180001d70(uVar5,local_438);
        *param_1 = local_438[0];
        pAVar6 = AfxGetModuleState();
        CCmdTarget::RestoreWaitCursor(*(CCmdTarget **)(pAVar6 + 8));
        DVar4 = GetTickCount();
        FUN_180004360(local_418,"\n+++++++++++++ ShowUpgradeRetired %d\n",(ulonglong)(DVar4 - DVar3)
                      ,param_4);
        OutputDebugStringA(local_418);
        GetTickCount();
        uVar9 = 1;
      }
      else {
        uVar9 = 1;
        if (param_1 != (undefined4 *)0x0) {
          *param_1 = 1;
        }
      }
    }
    pAVar6 = AfxGetModuleState();
    *(undefined8 *)(pAVar6 + 0x18) = uVar1;
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_430);
    return uVar9;
  }
  return 0;
}

/* ---- FUNC 00004200 gxUpwardComp (104 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong gxUpwardComp(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint *puVar2;
  ulonglong uVar3;
  
                    /* 0x4200  20  gxUpwardComp */
  iVar1 = FUN_180002f90();
  if (iVar1 == 0) {
    _DAT_18000b5e8 = param_2;
    uVar3 = FUN_180002060(param_2,param_1);
    return uVar3;
  }
  puVar2 = (uint *)GetGlobalPointer("UpwardOption");
  if (puVar2 == (uint *)0x0) {
    return 0xffffffff;
  }
  uVar3 = (ulonglong)*puVar2;
  if (*puVar2 == 0) {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

/* ---- FUNC 00004270 gxUpwardComp1 (81 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong gxUpwardComp1(undefined4 param_1)

{
  int iVar1;
  uint *puVar2;
  ulonglong uVar3;
  
                    /* 0x4270  21  gxUpwardComp1 */
  iVar1 = FUN_180002f90();
  if (iVar1 == 0) {
    _DAT_18000b5e8 = param_1;
    uVar3 = FUN_180001f00(param_1);
    return uVar3;
  }
  puVar2 = (uint *)GetGlobalPointer("UpwardOption");
  if (puVar2 == (uint *)0x0) {
    return 0xffffffff;
  }
  uVar3 = (ulonglong)*puVar2;
  if (*puVar2 == 0) {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

/* ---- FUNC 000042D0 gxUserDefWizard (136 bytes) ---- */

undefined8 gxUserDefWizard(undefined4 param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  AFX_MODULE_STATE *pAVar3;
  CWinThread *pCVar4;
  longlong lVar5;
  AFX_MAINTAIN_STATE2 local_18 [16];
  
                    /* 0x42d0  22  gxUserDefWizard */
  if (DAT_18000b5e0 != (AFX_MODULE_STATE *)0x0) {
    AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_18,DAT_18000b5e0);
    uVar2 = DAT_18000b5a8;
    pAVar3 = AfxGetModuleState();
    uVar1 = *(undefined8 *)(pAVar3 + 0x18);
    pAVar3 = AfxGetModuleState();
    *(undefined8 *)(pAVar3 + 0x18) = uVar2;
    pCVar4 = AfxGetThread();
    if (pCVar4 != (CWinThread *)0x0) {
      lVar5 = (**(code **)(*(longlong *)pCVar4 + 0xf8))(pCVar4);
      if (lVar5 != 0) {
        FUN_1800021d0(param_1);
      }
    }
    pAVar3 = AfxGetModuleState();
    *(undefined8 *)(pAVar3 + 0x18) = uVar1;
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_18);
  }
  return 0;
}

/* ---- FUNC 00004360 FUN_180004360 (94 bytes) ---- */

int FUN_180004360(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong *puVar2;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  puVar2 = (ulonglong *)FUN_180003030();
  iVar1 = __stdio_common_vsprintf(*puVar2 | 1,param_1,0xffffffffffffffff,param_2,0,&local_res18);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  return iVar1;
}

/* ---- FUNC 000043C0 FUN_1800043c0 (159 bytes) ---- */

CMMDialog * FUN_1800043c0(CMMDialog *param_1,longlong *param_2,CWnd *param_3)

{
  CMMDialog::CMMDialog(param_1,0x3170,param_3);
  *(undefined ***)param_1 = CFindTemplateDlg::vftable;
  CWnd::CWnd((CWnd *)(param_1 + 0x150));
  *(undefined ***)(param_1 + 0x150) = CTreeCtrl::vftable;
  *(undefined4 *)(param_1 + 0x130) = 2;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x138),
             "Select Template dialog is not shown when dialogs are suppressed.");
  *(undefined8 *)(param_1 + 0x148) = 0;
  *(longlong **)(param_1 + 0x238) = param_2;
  if (param_2 != (longlong *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  return param_1;
}

/* ---- FUNC 00004460 FUN_180004460 (88 bytes) ---- */

void FUN_180004460(CDialog *param_1)

{
  *(undefined ***)param_1 = CFindTemplateDlg::vftable;
  if (*(longlong **)(param_1 + 0x238) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0x238) + 0x10))();
  }
  CTreeCtrl::~CTreeCtrl((CTreeCtrl *)(param_1 + 0x150));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x140));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x138));
  CDialog::~CDialog(param_1);
  return;
}

/* ---- FUNC 000044C0 FUN_1800044c0 (48 bytes) ---- */

void FUN_1800044c0(CDialog *param_1)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x140));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x138));
  CDialog::~CDialog(param_1);
  return;
}

/* ---- FUNC 000044F0 FUN_1800044f0 (78 bytes) ---- */

CDialog * FUN_1800044f0(CDialog *param_1,uint param_2)

{
  FUN_180004460(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    _guard_check_icall();
  }
  return param_1;
}

/* ---- FUNC 00004540 FUN_180004540 (78 bytes) ---- */

CTreeCtrl * FUN_180004540(CTreeCtrl *param_1,uint param_2)

{
  CTreeCtrl::~CTreeCtrl(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    _guard_check_icall();
  }
  return param_1;
}

/* ---- FUNC 00004590 FUN_180004590 (13 bytes) ---- */

void FUN_180004590(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180004596. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EnableWindow(*(undefined8 *)(param_1 + 0x40),0);
  return;
}

/* ---- FUNC 000045A0 FUN_1800045a0 (8 bytes) ---- */

void FUN_1800045a0(CDialog *param_1,ushort param_2,CWnd *param_3)

{
  CDialog::Create(param_1,(char *)(ulonglong)param_2,param_3);
  return;
}

/* ---- FUNC 000045B0 FUN_1800045b0 (23 bytes) ---- */

void FUN_1800045b0(longlong param_1,CDataExchange *param_2)

{
  DDX_Control(param_2,0x3171,(CWnd *)(param_1 + 0x150));
  return;
}

/* ---- FUNC 000045D0 FUN_1800045d0 (16 bytes) ---- */

void FUN_1800045d0(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0001800045d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EnableWindow(*(undefined8 *)(param_1 + 0x40),1);
  return;
}

/* ---- FUNC 000045E0 thunk_FUN_1800045f0 (5 bytes) ---- */

undefined ** thunk_FUN_1800045f0(void)

{
  return &PTR_GetThisMessageMap_1800082a0;
}

/* ---- FUNC 000045F0 FUN_1800045f0 (8 bytes) ---- */

undefined ** FUN_1800045f0(void)

{
  return &PTR_GetThisMessageMap_1800082a0;
}

/* ---- FUNC 00004600 FUN_180004600 (51 bytes) ---- */

void FUN_180004600(CDialog *param_1)

{
  if (*(longlong **)(param_1 + 0x148) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0x148) + 0x10))();
    *(undefined8 *)(param_1 + 0x148) = 0;
  }
  CDialog::OnCancel(param_1);
  return;
}

/* ---- FUNC 00004640 FUN_180004640 (8 bytes) ---- */

void FUN_180004640(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  *param_3 = 0;
  return;
}

/* ---- FUNC 00004650 FUN_180004650 (50 bytes) ---- */

void FUN_180004650(undefined8 param_1,longlong param_2,undefined8 *param_3)

{
  if (*(longlong **)(param_2 + 0x50) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_2 + 0x50) + 0x10))();
    *param_3 = 0;
    return;
  }
  *param_3 = 0;
  return;
}

/* ---- FUNC 00004690 FUN_180004690 (118 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180004690(CDialog *param_1)

{
  int iVar1;
  CWnd *this;
  IAUserModelLibrary *pIVar2;
  _TREEITEM *lParam;
  _TREEITEM *p_Var3;
  _TREEITEM *lParam_00;
  uint uVar4;
  _TREEITEM *p_Var5;
  int iVar6;
  undefined1 auStackY_f8 [32];
  int local_a8;
  int local_a4;
  longlong *local_a0;
  longlong *local_98;
  longlong *local_90;
  longlong *local_88;
  __int64 local_80;
  char local_78 [64];
  ulonglong local_38;
  
  local_38 = DAT_18000b3e8 ^ (ulonglong)auStackY_f8;
  CDialog::OnInitDialog(param_1);
  this = CWnd::GetDlgItem((CWnd *)param_1,1);
  CWnd::EnableWindow(this,0);
  lParam_00 = (_TREEITEM *)0x0;
  iVar6 = 1;
  if (*(longlong *)(param_1 + 0x238) == 0) {
    iVar6 = CApwnLibraries::CountLibraries(*(CApwnLibraries **)g_pApwnLibs_exref);
  }
  p_Var5 = lParam_00;
  if (0 < iVar6) {
    do {
      lParam = (_TREEITEM *)0x0;
      pIVar2 = *(IAUserModelLibrary **)(param_1 + 0x238);
      if (pIVar2 == (IAUserModelLibrary *)0x0) {
        pIVar2 = CApwnLibraries::GetLibrary(*(CApwnLibraries **)g_pApwnLibs_exref,(int)p_Var5);
        if (pIVar2 != (IAUserModelLibrary *)0x0) goto LAB_180004756;
      }
      else {
        (**(code **)(*(longlong *)pIVar2 + 8))(pIVar2);
LAB_180004756:
        local_a8 = 1;
        (**(code **)(*(longlong *)pIVar2 + 0x30))(pIVar2,&local_a8);
        if (local_a8 == 0) {
          (**(code **)(*(longlong *)pIVar2 + 0x38))(pIVar2,local_78,0x40);
          local_88 = (longlong *)0x0;
          iVar1 = (*(code *)**(undefined8 **)pIVar2)(pIVar2,&DAT_180007700);
          if (-1 < iVar1) {
            local_98 = (longlong *)0x0;
            iVar1 = (**(code **)(*local_88 + 0x40))(local_88,&local_98);
            if (-1 < iVar1) {
              iVar1 = (**(code **)(*local_98 + 0x18))(local_98,1);
              while (iVar1 == 0) {
                local_90 = (longlong *)0x0;
                iVar1 = (**(code **)*local_a0)(local_a0,&DAT_180007710,&local_90);
                if (-1 < iVar1) {
                  local_a4 = 0;
                  (**(code **)(*local_90 + 0x20))(local_90,&local_a4);
                  (**(code **)(*local_90 + 0x10))();
                  if (local_a4 != 0) {
                    if ((lParam == (_TREEITEM *)0x0) &&
                       (lParam = CTreeCtrl::InsertItem
                                           ((CTreeCtrl *)(param_1 + 0x150),1,local_78,0,0,0,0,0,
                                            (_TREEITEM *)0xffffffffffff0000,
                                            (_TREEITEM *)0xffffffffffff0002),
                       lParam_00 == (_TREEITEM *)0x0)) {
                      lParam_00 = lParam;
                    }
                    (**(code **)(*local_a0 + 0x18))(local_a0,local_78,0x40);
                    local_80 = 0;
                    (**(code **)*local_a0)(local_a0,&DAT_180007720,&local_80);
                    p_Var3 = CTreeCtrl::InsertItem
                                       ((CTreeCtrl *)(param_1 + 0x150),1,local_78,0,0,0,0,0,lParam,
                                        (_TREEITEM *)0xffffffffffff0002);
                    CTreeCtrl::SetItem((CTreeCtrl *)(param_1 + 0x150),p_Var3,4,(char *)0x0,0,0,0,0,
                                       local_80);
                  }
                }
                (**(code **)(*local_a0 + 0x10))();
                iVar1 = (**(code **)(*local_98 + 0x18))(local_98,1);
              }
              (**(code **)(*local_98 + 0x10))();
            }
            (**(code **)(*local_88 + 0x10))();
            if (lParam != (_TREEITEM *)0x0) {
              SendMessageA(*(HWND *)(param_1 + 400),0x1102,2,(LPARAM)lParam);
            }
          }
        }
        (**(code **)(*(longlong *)pIVar2 + 0x10))(pIVar2);
      }
      uVar4 = (int)p_Var5 + 1;
      p_Var5 = (_TREEITEM *)(ulonglong)uVar4;
    } while ((int)uVar4 < iVar6);
    if (lParam_00 != (_TREEITEM *)0x0) {
      SendMessageA(*(HWND *)(param_1 + 400),0x1114,0,(LPARAM)lParam_00);
    }
  }
  return 1;
}

/* ---- FUNC 00004706 FUN_180004706 (642 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180004706(void)

{
  longlong lVar1;
  undefined8 *puVar2;
  int iVar3;
  IAUserModelLibrary *pIVar4;
  _TREEITEM *p_Var5;
  _TREEITEM *unaff_RBX;
  longlong unaff_RBP;
  _TREEITEM *unaff_RDI;
  int unaff_R12D;
  int unaff_R13D;
  longlong unaff_R15;
  
  do {
    pIVar4 = *(IAUserModelLibrary **)(unaff_R15 + 0x238);
    if (pIVar4 == (IAUserModelLibrary *)0x0) {
      pIVar4 = CApwnLibraries::GetLibrary(*(CApwnLibraries **)g_pApwnLibs_exref,unaff_R12D);
      if (pIVar4 != (IAUserModelLibrary *)0x0) goto LAB_180004756;
    }
    else {
      (**(code **)(*(longlong *)pIVar4 + 8))(pIVar4);
LAB_180004756:
      lVar1 = *(longlong *)pIVar4;
      *(undefined4 *)(unaff_RBP + -0x49) = 1;
      (**(code **)(lVar1 + 0x30))(pIVar4,unaff_RBP + -0x49);
      p_Var5 = unaff_RDI;
      if (*(int *)(unaff_RBP + -0x49) == 0) {
        (**(code **)(*(longlong *)pIVar4 + 0x38))(pIVar4,unaff_RBP + -0x19,0x40);
        puVar2 = *(undefined8 **)pIVar4;
        *(_TREEITEM **)(unaff_RBP + -0x29) = unaff_RDI;
        iVar3 = (*(code *)*puVar2)(pIVar4,&DAT_180007700);
        if (-1 < iVar3) {
          *(_TREEITEM **)(unaff_RBP + -0x39) = unaff_RDI;
          iVar3 = (**(code **)(**(longlong **)(unaff_RBP + -0x29) + 0x40))
                            (*(longlong **)(unaff_RBP + -0x29),unaff_RBP + -0x39);
          if (-1 < iVar3) {
            iVar3 = (**(code **)(**(longlong **)(unaff_RBP + -0x39) + 0x18))
                              (*(longlong **)(unaff_RBP + -0x39),1);
            while (iVar3 == 0) {
              *(_TREEITEM **)(unaff_RBP + -0x31) = p_Var5;
              iVar3 = (**(code **)**(undefined8 **)(unaff_RBP + -0x41))
                                (*(undefined8 **)(unaff_RBP + -0x41),&DAT_180007710,
                                 unaff_RBP + -0x31);
              if (-1 < iVar3) {
                iVar3 = (int)p_Var5;
                *(int *)(unaff_RBP + -0x45) = iVar3;
                (**(code **)(**(longlong **)(unaff_RBP + -0x31) + 0x20))
                          (*(longlong **)(unaff_RBP + -0x31),unaff_RBP + -0x45);
                (**(code **)(**(longlong **)(unaff_RBP + -0x31) + 0x10))();
                if (*(int *)(unaff_RBP + -0x45) != 0) {
                  if ((unaff_RDI == (_TREEITEM *)0x0) &&
                     (unaff_RDI = CTreeCtrl::InsertItem
                                            ((CTreeCtrl *)(unaff_R15 + 0x150),1,
                                             (char *)(unaff_RBP + -0x19),0,iVar3,iVar3,iVar3,
                                             (__int64)p_Var5,(_TREEITEM *)0xffffffffffff0000,
                                             (_TREEITEM *)0xffffffffffff0002),
                     unaff_RBX == (_TREEITEM *)0x0)) {
                    unaff_RBX = unaff_RDI;
                  }
                  (**(code **)(**(longlong **)(unaff_RBP + -0x41) + 0x18))
                            (*(longlong **)(unaff_RBP + -0x41),unaff_RBP + -0x19,0x40);
                  *(_TREEITEM **)(unaff_RBP + -0x21) = p_Var5;
                  (**(code **)**(undefined8 **)(unaff_RBP + -0x41))
                            (*(undefined8 **)(unaff_RBP + -0x41),&DAT_180007720,unaff_RBP + -0x21);
                  p_Var5 = CTreeCtrl::InsertItem
                                     ((CTreeCtrl *)(unaff_R15 + 0x150),1,(char *)(unaff_RBP + -0x19)
                                      ,0,0,0,0,0,unaff_RDI,(_TREEITEM *)0xffffffffffff0002);
                  CTreeCtrl::SetItem((CTreeCtrl *)(unaff_R15 + 0x150),p_Var5,4,(char *)0x0,0,0,0,0,
                                     *(__int64 *)(unaff_RBP + -0x21));
                  p_Var5 = (_TREEITEM *)0x0;
                }
              }
              (**(code **)(**(longlong **)(unaff_RBP + -0x41) + 0x10))();
              iVar3 = (**(code **)(**(longlong **)(unaff_RBP + -0x39) + 0x18))
                                (*(longlong **)(unaff_RBP + -0x39),1);
            }
            (**(code **)(**(longlong **)(unaff_RBP + -0x39) + 0x10))();
          }
          (**(code **)(**(longlong **)(unaff_RBP + -0x29) + 0x10))();
          if (unaff_RDI != (_TREEITEM *)0x0) {
            SendMessageA(*(HWND *)(unaff_R15 + 400),0x1102,2,(LPARAM)unaff_RDI);
          }
        }
      }
      (**(code **)(*(longlong *)pIVar4 + 0x10))(pIVar4);
      unaff_RDI = p_Var5;
    }
    unaff_R12D = unaff_R12D + 1;
    if (unaff_R13D <= unaff_R12D) {
      if (unaff_RBX != (_TREEITEM *)0x0) {
        SendMessageA(*(HWND *)(unaff_R15 + 400),0x1114,0,(LPARAM)unaff_RBX);
      }
      return 1;
    }
  } while( true );
}

/* ---- FUNC 00004988 FUN_180004988 (65 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180004988(void)

{
  LPARAM unaff_RBX;
  longlong unaff_R15;
  
  SendMessageA(*(HWND *)(unaff_R15 + 400),0x1114,0,unaff_RBX);
  return 1;
}

/* ---- FUNC 000049D0 FUN_1800049d0 (133 bytes) ---- */

void FUN_1800049d0(CWnd *param_1,longlong param_2,undefined8 *param_3)

{
  longlong *plVar1;
  CWnd *this;
  
  if (*(longlong **)(param_1 + 0x148) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0x148) + 0x10))();
    *(undefined8 *)(param_1 + 0x148) = 0;
  }
  plVar1 = *(longlong **)(param_2 + 0x88);
  *(longlong **)(param_1 + 0x148) = plVar1;
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 8))();
  }
  this = CWnd::GetDlgItem(param_1,1);
  CWnd::EnableWindow(this,(uint)(plVar1 != (longlong *)0x0));
  *param_3 = 0;
  return;
}

/* ---- FUNC 00004A60 gxDelStruct (37 bytes) ---- */

undefined8 gxDelStruct(void)

{
                    /* 0x4a60  3  gxDelStruct */
  if ((DAT_18000b6f8 != (code *)0x0) && (DAT_18000b618 != 0)) {
    (*DAT_18000b6f8)();
  }
  return 0;
}

/* ---- FUNC 00004A85 MMGetSuppress (6 bytes) ---- */

void MMGetSuppress(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180004a85. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MMGetSuppress();
  return;
}

/* ---- FUNC 00004A8B DoModal (6 bytes) ---- */

__int64 __thiscall CMMDialog::DoModal(CMMDialog *this)

{
  __int64 _Var1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004a8b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = DoModal(this);
  return _Var1;
}

/* ---- FUNC 00004A91 GetGlobalPointer (6 bytes) ---- */

void GetGlobalPointer(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180004a91. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetGlobalPointer();
  return;
}

/* ---- FUNC 00004A97 CMMDialog (6 bytes) ---- */

void __thiscall CMMDialog::CMMDialog(CMMDialog *this,uint param_1,CWnd *param_2)

{
                    /* WARNING: Could not recover jumptable at 0x000180004a97. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CMMDialog(this,param_1,param_2);
  return;
}

/* ---- FUNC 00004A9D InitSuppressed (6 bytes) ---- */

void __thiscall CMMDialog::InitSuppressed(CMMDialog *this)

{
                    /* WARNING: Could not recover jumptable at 0x000180004a9d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InitSuppressed(this);
  return;
}

/* ---- FUNC 00004AA3 AfxThrowMemoryException (6 bytes) ---- */

void __cdecl AfxThrowMemoryException(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180004aa3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AfxThrowMemoryException();
  return;
}

/* ---- FUNC 00004AA9 AfxThrowOleException (6 bytes) ---- */

void __cdecl AfxThrowOleException(long param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180004aa9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AfxThrowOleException(param_1);
  return;
}

/* ---- FUNC 00004AAF operator_delete (6 bytes) ---- */

void __cdecl operator_delete(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180004aaf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete(param_1);
  return;
}

/* ---- FUNC 00004AB5 operator_new (6 bytes) ---- */

void * __cdecl operator_new(__uint64 param_1)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004ab5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = operator_new(param_1);
  return pvVar1;
}

/* ---- FUNC 00004ABB operator_delete[] (6 bytes) ---- */

void __cdecl operator_delete__(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180004abb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete__(param_1);
  return;
}

/* ---- FUNC 00004AC1 Delete (6 bytes) ---- */

void __thiscall CException::Delete(CException *this)

{
                    /* WARNING: Could not recover jumptable at 0x000180004ac1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Delete(this);
  return;
}

/* ---- FUNC 00004AC7 AfxGetModuleState (6 bytes) ---- */

AFX_MODULE_STATE * __cdecl AfxGetModuleState(void)

{
  AFX_MODULE_STATE *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004ac7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = AfxGetModuleState();
  return pAVar1;
}

/* ---- FUNC 00004ACD AFX_MAINTAIN_STATE2 (6 bytes) ---- */

void __thiscall
AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(AFX_MAINTAIN_STATE2 *this,AFX_MODULE_STATE *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180004acd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AFX_MAINTAIN_STATE2(this,param_1);
  return;
}

/* ---- FUNC 00004AD3 ~AFX_MAINTAIN_STATE2 (6 bytes) ---- */

void __thiscall AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(AFX_MAINTAIN_STATE2 *this)

{
                    /* WARNING: Could not recover jumptable at 0x000180004ad3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~AFX_MAINTAIN_STATE2(this);
  return;
}

/* ---- FUNC 00004AD9 RestoreWaitCursor (6 bytes) ---- */

void __thiscall CCmdTarget::RestoreWaitCursor(CCmdTarget *this)

{
                    /* WARNING: Could not recover jumptable at 0x000180004ad9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RestoreWaitCursor(this);
  return;
}

/* ---- FUNC 00004ADF FromHandle (6 bytes) ---- */

CWnd * __cdecl CWnd::FromHandle(HWND__ *param_1)

{
  CWnd *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004adf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = FromHandle(param_1);
  return pCVar1;
}

/* ---- FUNC 00004AE5 AfxGetThread (6 bytes) ---- */

CWinThread * __cdecl AfxGetThread(void)

{
  CWinThread *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004ae5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = AfxGetThread();
  return pCVar1;
}

/* ---- FUNC 00004AEB CDynLinkLibrary (6 bytes) ---- */

void __thiscall
CDynLinkLibrary::CDynLinkLibrary(CDynLinkLibrary *this,AFX_EXTENSION_MODULE *param_1,int param_2)

{
                    /* WARNING: Could not recover jumptable at 0x000180004aeb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CDynLinkLibrary(this,param_1,param_2);
  return;
}

/* ---- FUNC 00004AF1 AfxInitExtensionModule (6 bytes) ---- */

int __cdecl AfxInitExtensionModule(AFX_EXTENSION_MODULE *param_1,HINSTANCE__ *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004af1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = AfxInitExtensionModule(param_1,param_2);
  return iVar1;
}

/* ---- FUNC 00004AF7 COleVariant (6 bytes) ---- */

void __thiscall COleVariant::COleVariant(COleVariant *this,long param_1,ushort param_2)

{
                    /* WARNING: Could not recover jumptable at 0x000180004af7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  COleVariant(this,param_1,param_2);
  return;
}

/* ---- FUNC 00004AFD DDX_Control (6 bytes) ---- */

void __cdecl DDX_Control(CDataExchange *param_1,int param_2,CWnd *param_3)

{
                    /* WARNING: Could not recover jumptable at 0x000180004afd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DDX_Control(param_1,param_2,param_3);
  return;
}

/* ---- FUNC 00004B03 OnCmdMsg (6 bytes) ---- */

int __thiscall
CCmdTarget::OnCmdMsg
          (CCmdTarget *this,uint param_1,int param_2,void *param_3,AFX_CMDHANDLERINFO *param_4)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004b03. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnCmdMsg(this,param_1,param_2,param_3,param_4);
  return iVar1;
}

/* ---- FUNC 00004B09 IsInvokeAllowed (6 bytes) ---- */

int __thiscall CCmdTarget::IsInvokeAllowed(CCmdTarget *this,long param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004b09. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = IsInvokeAllowed(this,param_1);
  return iVar1;
}

/* ---- FUNC 00004B0F GetDispatchIID (6 bytes) ---- */

int __thiscall CCmdTarget::GetDispatchIID(CCmdTarget *this,_GUID *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004b0f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = GetDispatchIID(this,param_1);
  return iVar1;
}

/* ---- FUNC 00004B15 GetTypeInfoCount (6 bytes) ---- */

uint __thiscall CCmdTarget::GetTypeInfoCount(CCmdTarget *this)

{
  uint uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004b15. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = GetTypeInfoCount(this);
  return uVar1;
}

/* ---- FUNC 00004B1B GetTypeLibCache (6 bytes) ---- */

CTypeLibCache * __thiscall CCmdTarget::GetTypeLibCache(CCmdTarget *this)

{
  CTypeLibCache *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004b1b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetTypeLibCache(this);
  return pCVar1;
}

/* ---- FUNC 00004B21 GetTypeLib (6 bytes) ---- */

long __thiscall CCmdTarget::GetTypeLib(CCmdTarget *this,ulong param_1,ITypeLib **param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004b21. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = GetTypeLib(this,param_1,param_2);
  return lVar1;
}

/* ---- FUNC 00004B27 GetCommandMap (6 bytes) ---- */

AFX_OLECMDMAP * __thiscall CCmdTarget::GetCommandMap(CCmdTarget *this)

{
  AFX_OLECMDMAP *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004b27. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = GetCommandMap(this);
  return pAVar1;
}

/* ---- FUNC 00004B2D GetDispatchMap (6 bytes) ---- */

AFX_DISPMAP * __thiscall CCmdTarget::GetDispatchMap(CCmdTarget *this)

{
  AFX_DISPMAP *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004b2d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = GetDispatchMap(this);
  return pAVar1;
}

/* ---- FUNC 00004B33 GetConnectionMap (6 bytes) ---- */

AFX_CONNECTIONMAP * __thiscall CCmdTarget::GetConnectionMap(CCmdTarget *this)

{
  AFX_CONNECTIONMAP *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004b33. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = GetConnectionMap(this);
  return pAVar1;
}

/* ---- FUNC 00004B39 GetEventSinkMap (6 bytes) ---- */

AFX_EVENTSINKMAP * __thiscall CCmdTarget::GetEventSinkMap(CCmdTarget *this)

{
  AFX_EVENTSINKMAP *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004b39. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = GetEventSinkMap(this);
  return pAVar1;
}

/* ---- FUNC 00004B3F OnCreateAggregates (6 bytes) ---- */

int __thiscall CCmdTarget::OnCreateAggregates(CCmdTarget *this)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004b3f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnCreateAggregates(this);
  return iVar1;
}

/* ---- FUNC 00004B45 GetInterfaceHook (6 bytes) ---- */

IUnknown * __thiscall CCmdTarget::GetInterfaceHook(CCmdTarget *this,void *param_1)

{
  IUnknown *pIVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004b45. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pIVar1 = GetInterfaceHook(this,param_1);
  return pIVar1;
}

/* ---- FUNC 00004B4B GetExtraConnectionPoints (6 bytes) ---- */

int __thiscall CCmdTarget::GetExtraConnectionPoints(CCmdTarget *this,CPtrArray *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004b4b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = GetExtraConnectionPoints(this,param_1);
  return iVar1;
}

/* ---- FUNC 00004B51 GetConnectionHook (6 bytes) ---- */

IConnectionPoint * __thiscall CCmdTarget::GetConnectionHook(CCmdTarget *this,_GUID *param_1)

{
  IConnectionPoint *pIVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004b51. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pIVar1 = GetConnectionHook(this,param_1);
  return pIVar1;
}

/* ---- FUNC 00004B57 CWnd (6 bytes) ---- */

void __thiscall CWnd::CWnd(CWnd *this)

{
                    /* WARNING: Could not recover jumptable at 0x000180004b57. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CWnd(this);
  return;
}

/* ---- FUNC 00004B5D PreSubclassWindow (6 bytes) ---- */

void __thiscall CWnd::PreSubclassWindow(CWnd *this)

{
                    /* WARNING: Could not recover jumptable at 0x000180004b5d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  PreSubclassWindow(this);
  return;
}

/* ---- FUNC 00004B63 Create (6 bytes) ---- */

int __thiscall
CWnd::Create(CWnd *this,char *param_1,char *param_2,ulong param_3,tagRECT *param_4,CWnd *param_5,
            uint param_6,CCreateContext *param_7)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004b63. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = Create(this,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return iVar1;
}

/* ---- FUNC 00004B69 CreateEx (6 bytes) ---- */

int __thiscall
CWnd::CreateEx(CWnd *this,ulong param_1,char *param_2,char *param_3,ulong param_4,int param_5,
              int param_6,int param_7,int param_8,HWND__ *param_9,HMENU__ *param_10,void *param_11)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004b69. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = CreateEx(this,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                   param_10,param_11);
  return iVar1;
}

/* ---- FUNC 00004B6F CreateEx (6 bytes) ---- */

int __thiscall
CWnd::CreateEx(CWnd *this,ulong param_1,char *param_2,char *param_3,ulong param_4,tagRECT *param_5,
              CWnd *param_6,uint param_7,void *param_8)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004b6f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = CreateEx(this,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return iVar1;
}

/* ---- FUNC 00004B75 DestroyWindow (6 bytes) ---- */

int __thiscall CWnd::DestroyWindow(CWnd *this)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004b75. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = DestroyWindow(this);
  return iVar1;
}

/* ---- FUNC 00004B7B PreCreateWindow (6 bytes) ---- */

int __thiscall CWnd::PreCreateWindow(CWnd *this,tagCREATESTRUCTA *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004b7b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = PreCreateWindow(this,param_1);
  return iVar1;
}

/* ---- FUNC 00004B81 CalcWindowRect (6 bytes) ---- */

void __thiscall CWnd::CalcWindowRect(CWnd *this,tagRECT *param_1,uint param_2)

{
                    /* WARNING: Could not recover jumptable at 0x000180004b81. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CalcWindowRect(this,param_1,param_2);
  return;
}

/* ---- FUNC 00004B87 GetDlgItem (6 bytes) ---- */

CWnd * __thiscall CWnd::GetDlgItem(CWnd *this,int param_1)

{
  CWnd *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004b87. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetDlgItem(this,param_1);
  return pCVar1;
}

/* ---- FUNC 00004B8D GetMenu (6 bytes) ---- */

CMenu * __thiscall CWnd::GetMenu(CWnd *this)

{
  CMenu *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004b8d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetMenu(this);
  return pCVar1;
}

/* ---- FUNC 00004B93 SetMenu (6 bytes) ---- */

int __thiscall CWnd::SetMenu(CWnd *this,CMenu *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004b93. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = SetMenu(this,param_1);
  return iVar1;
}

/* ---- FUNC 00004B99 OnToolHitTest (6 bytes) ---- */

__int64 __thiscall CWnd::OnToolHitTest(void)

{
  __int64 _Var1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004b99. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = OnToolHitTest();
  return _Var1;
}

/* ---- FUNC 00004B9F EnableWindow (6 bytes) ---- */

int __thiscall CWnd::EnableWindow(CWnd *this,int param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004b9f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = EnableWindow(this,param_1);
  return iVar1;
}

/* ---- FUNC 00004BA5 GetScrollBarCtrl (6 bytes) ---- */

CScrollBar * __thiscall CWnd::GetScrollBarCtrl(CWnd *this,int param_1)

{
  CScrollBar *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004ba5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetScrollBarCtrl(this,param_1);
  return pCVar1;
}

/* ---- FUNC 00004BAB WinHelpA (6 bytes) ---- */

void __thiscall CWnd::WinHelpA(CWnd *this,__uint64 param_1,uint param_2)

{
                    /* WARNING: Could not recover jumptable at 0x000180004bab. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WinHelpA(this,param_1,param_2);
  return;
}

/* ---- FUNC 00004BB1 HtmlHelpA (6 bytes) ---- */

void __thiscall CWnd::HtmlHelpA(CWnd *this,__uint64 param_1,uint param_2)

{
                    /* WARNING: Could not recover jumptable at 0x000180004bb1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HtmlHelpA(this,param_1,param_2);
  return;
}

/* ---- FUNC 00004BB7 WinHelpInternal (6 bytes) ---- */

void __thiscall CWnd::WinHelpInternal(CWnd *this,__uint64 param_1,uint param_2)

{
                    /* WARNING: Could not recover jumptable at 0x000180004bb7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WinHelpInternal(this,param_1,param_2);
  return;
}

/* ---- FUNC 00004BBD ContinueModal (6 bytes) ---- */

int __thiscall CWnd::ContinueModal(CWnd *this)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004bbd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = ContinueModal(this);
  return iVar1;
}

/* ---- FUNC 00004BC3 EndModalLoop (6 bytes) ---- */

void __thiscall CWnd::EndModalLoop(CWnd *this,int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180004bc3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EndModalLoop(this,param_1);
  return;
}

/* ---- FUNC 00004BC9 OnDrawIconicThumbnailOrLivePreview (6 bytes) ---- */

void __thiscall CWnd::OnDrawIconicThumbnailOrLivePreview(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180004bc9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OnDrawIconicThumbnailOrLivePreview();
  return;
}

/* ---- FUNC 00004BCF GetInterfaceMap (6 bytes) ---- */

AFX_INTERFACEMAP * __thiscall CWnd::GetInterfaceMap(CWnd *this)

{
  AFX_INTERFACEMAP *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004bcf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = GetInterfaceMap(this);
  return pAVar1;
}

/* ---- FUNC 00004BD5 EnsureStdObj (6 bytes) ---- */

long __thiscall CWnd::EnsureStdObj(CWnd *this)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004bd5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = EnsureStdObj(this);
  return lVar1;
}

/* ---- FUNC 00004BDB get_accParent (6 bytes) ---- */

long __thiscall CWnd::get_accParent(CWnd *this,IDispatch **param_1)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004bdb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accParent(this,param_1);
  return lVar1;
}

/* ---- FUNC 00004BE1 get_accChildCount (6 bytes) ---- */

long __thiscall CWnd::get_accChildCount(CWnd *this,long *param_1)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004be1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accChildCount(this,param_1);
  return lVar1;
}

/* ---- FUNC 00004BE7 get_accChild (6 bytes) ---- */

long __thiscall CWnd::get_accChild(CWnd *this,tagVARIANT *param_1,IDispatch **param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004be7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accChild(this,param_1,param_2);
  return lVar1;
}

/* ---- FUNC 00004BED get_accName (6 bytes) ---- */

long __thiscall CWnd::get_accName(CWnd *this,tagVARIANT *param_1,wchar_t **param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004bed. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accName(this,param_1,param_2);
  return lVar1;
}

/* ---- FUNC 00004BF3 get_accValue (6 bytes) ---- */

long __thiscall CWnd::get_accValue(CWnd *this,tagVARIANT *param_1,wchar_t **param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004bf3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accValue(this,param_1,param_2);
  return lVar1;
}

/* ---- FUNC 00004BF9 get_accDescription (6 bytes) ---- */

long __thiscall CWnd::get_accDescription(CWnd *this,tagVARIANT *param_1,wchar_t **param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004bf9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accDescription(this,param_1,param_2);
  return lVar1;
}

/* ---- FUNC 00004BFF get_accRole (6 bytes) ---- */

long __thiscall CWnd::get_accRole(CWnd *this,tagVARIANT *param_1,tagVARIANT *param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004bff. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accRole(this,param_1,param_2);
  return lVar1;
}

/* ---- FUNC 00004C05 get_accState (6 bytes) ---- */

long __thiscall CWnd::get_accState(CWnd *this,tagVARIANT *param_1,tagVARIANT *param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004c05. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accState(this,param_1,param_2);
  return lVar1;
}

/* ---- FUNC 00004C0B get_accHelp (6 bytes) ---- */

long __thiscall CWnd::get_accHelp(CWnd *this,tagVARIANT *param_1,wchar_t **param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004c0b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accHelp(this,param_1,param_2);
  return lVar1;
}

/* ---- FUNC 00004C11 get_accHelpTopic (6 bytes) ---- */

long __thiscall
CWnd::get_accHelpTopic(CWnd *this,wchar_t **param_1,tagVARIANT *param_2,long *param_3)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004c11. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accHelpTopic(this,param_1,param_2,param_3);
  return lVar1;
}

/* ---- FUNC 00004C17 get_accKeyboardShortcut (6 bytes) ---- */

long __thiscall CWnd::get_accKeyboardShortcut(CWnd *this,tagVARIANT *param_1,wchar_t **param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004c17. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accKeyboardShortcut(this,param_1,param_2);
  return lVar1;
}

/* ---- FUNC 00004C1D get_accFocus (6 bytes) ---- */

long __thiscall CWnd::get_accFocus(CWnd *this,tagVARIANT *param_1)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004c1d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accFocus(this,param_1);
  return lVar1;
}

/* ---- FUNC 00004C23 get_accSelection (6 bytes) ---- */

long __thiscall CWnd::get_accSelection(CWnd *this,tagVARIANT *param_1)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004c23. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accSelection(this,param_1);
  return lVar1;
}

/* ---- FUNC 00004C29 get_accDefaultAction (6 bytes) ---- */

long __thiscall CWnd::get_accDefaultAction(CWnd *this,tagVARIANT *param_1,wchar_t **param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004c29. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accDefaultAction(this,param_1,param_2);
  return lVar1;
}

/* ---- FUNC 00004C2F accSelect (6 bytes) ---- */

long __thiscall CWnd::accSelect(CWnd *this,long param_1,tagVARIANT *param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004c2f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = accSelect(this,param_1,param_2);
  return lVar1;
}

/* ---- FUNC 00004C35 accLocation (6 bytes) ---- */

long __thiscall
CWnd::accLocation(CWnd *this,long *param_1,long *param_2,long *param_3,long *param_4,
                 tagVARIANT *param_5)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004c35. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = accLocation(this,param_1,param_2,param_3,param_4,param_5);
  return lVar1;
}

/* ---- FUNC 00004C3B accNavigate (6 bytes) ---- */

long __thiscall CWnd::accNavigate(CWnd *this,long param_1,tagVARIANT *param_2,tagVARIANT *param_3)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004c3b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = accNavigate(this,param_1,param_2,param_3);
  return lVar1;
}

/* ---- FUNC 00004C41 accHitTest (6 bytes) ---- */

long __thiscall CWnd::accHitTest(CWnd *this,long param_1,long param_2,tagVARIANT *param_3)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004c41. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = accHitTest(this,param_1,param_2,param_3);
  return lVar1;
}

/* ---- FUNC 00004C47 accDoDefaultAction (6 bytes) ---- */

long __thiscall CWnd::accDoDefaultAction(CWnd *this,tagVARIANT *param_1)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004c47. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = accDoDefaultAction(this,param_1);
  return lVar1;
}

/* ---- FUNC 00004C4D put_accName (6 bytes) ---- */

long __thiscall CWnd::put_accName(CWnd *this,tagVARIANT *param_1,wchar_t *param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004c4d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = put_accName(this,param_1,param_2);
  return lVar1;
}

/* ---- FUNC 00004C53 put_accValue (6 bytes) ---- */

long __thiscall CWnd::put_accValue(CWnd *this,tagVARIANT *param_1,wchar_t *param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004c53. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = put_accValue(this,param_1,param_2);
  return lVar1;
}

/* ---- FUNC 00004C59 SetProxy (6 bytes) ---- */

long __thiscall CWnd::SetProxy(CWnd *this,IAccessibleProxy *param_1)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004c59. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = SetProxy(this,param_1);
  return lVar1;
}

/* ---- FUNC 00004C5F CreateAccessibleProxy (6 bytes) ---- */

long __thiscall
CWnd::CreateAccessibleProxy(CWnd *this,__uint64 param_1,__int64 param_2,__int64 *param_3)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004c5f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = CreateAccessibleProxy(this,param_1,param_2,param_3);
  return lVar1;
}

/* ---- FUNC 00004C65 OnCommand (6 bytes) ---- */

int __thiscall CWnd::OnCommand(CWnd *this,__uint64 param_1,__int64 param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004c65. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnCommand(this,param_1,param_2);
  return iVar1;
}

/* ---- FUNC 00004C6B OnNotify (6 bytes) ---- */

int __thiscall CWnd::OnNotify(CWnd *this,__uint64 param_1,__int64 param_2,__int64 *param_3)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004c6b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnNotify(this,param_1,param_2,param_3);
  return iVar1;
}

/* ---- FUNC 00004C71 GetSuperWndProcAddr (6 bytes) ---- */

_func___int64_HWND___ptr_uint___uint64___int64 ** __thiscall CWnd::GetSuperWndProcAddr(CWnd *this)

{
  _func___int64_HWND___ptr_uint___uint64___int64 **pp_Var1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004c71. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pp_Var1 = GetSuperWndProcAddr(this);
  return pp_Var1;
}

/* ---- FUNC 00004C77 PreTranslateMessage (6 bytes) ---- */

int __thiscall CWnd::PreTranslateMessage(CWnd *this,tagMSG *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004c77. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = PreTranslateMessage(this,param_1);
  return iVar1;
}

/* ---- FUNC 00004C7D OnAmbientProperty (6 bytes) ---- */

int __thiscall
CWnd::OnAmbientProperty(CWnd *this,COleControlSite *param_1,long param_2,tagVARIANT *param_3)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004c7d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnAmbientProperty(this,param_1,param_2,param_3);
  return iVar1;
}

/* ---- FUNC 00004C83 WindowProc (6 bytes) ---- */

__int64 __thiscall CWnd::WindowProc(CWnd *this,uint param_1,__uint64 param_2,__int64 param_3)

{
  __int64 _Var1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004c83. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = WindowProc(this,param_1,param_2,param_3);
  return _Var1;
}

/* ---- FUNC 00004C89 OnWndMsg (6 bytes) ---- */

int __thiscall
CWnd::OnWndMsg(CWnd *this,uint param_1,__uint64 param_2,__int64 param_3,__int64 *param_4)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004c89. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnWndMsg(this,param_1,param_2,param_3,param_4);
  return iVar1;
}

/* ---- FUNC 00004C8F DefWindowProcA (6 bytes) ---- */

__int64 __thiscall CWnd::DefWindowProcA(CWnd *this,uint param_1,__uint64 param_2,__int64 param_3)

{
  __int64 _Var1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004c8f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = DefWindowProcA(this,param_1,param_2,param_3);
  return _Var1;
}

/* ---- FUNC 00004C95 PostNcDestroy (6 bytes) ---- */

void __thiscall CWnd::PostNcDestroy(CWnd *this)

{
                    /* WARNING: Could not recover jumptable at 0x000180004c95. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  PostNcDestroy(this);
  return;
}

/* ---- FUNC 00004C9B OnChildNotify (6 bytes) ---- */

int __thiscall
CWnd::OnChildNotify(CWnd *this,uint param_1,__uint64 param_2,__int64 param_3,__int64 *param_4)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004c9b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnChildNotify(this,param_1,param_2,param_3,param_4);
  return iVar1;
}

/* ---- FUNC 00004CA1 OnTouchInputs (6 bytes) ---- */

int __thiscall CWnd::OnTouchInputs(CWnd *this,uint param_1,tagTOUCHINPUT *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004ca1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnTouchInputs(this,param_1,param_2);
  return iVar1;
}

/* ---- FUNC 00004CA7 OnTouchInput (6 bytes) ---- */

int __thiscall CWnd::OnTouchInput(void)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004ca7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnTouchInput();
  return iVar1;
}

/* ---- FUNC 00004CAD GetGestureStatus (6 bytes) ---- */

ulong __thiscall CWnd::GetGestureStatus(void)

{
  ulong uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004cad. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = GetGestureStatus();
  return uVar1;
}

/* ---- FUNC 00004CB3 OnGestureZoom (6 bytes) ---- */

int __thiscall CWnd::OnGestureZoom(void)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004cb3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnGestureZoom();
  return iVar1;
}

/* ---- FUNC 00004CB9 OnGesturePan (6 bytes) ---- */

int __thiscall CWnd::OnGesturePan(void)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004cb9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnGesturePan();
  return iVar1;
}

/* ---- FUNC 00004CBF OnGestureRotate (6 bytes) ---- */

int __thiscall CWnd::OnGestureRotate(void)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004cbf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnGestureRotate();
  return iVar1;
}

/* ---- FUNC 00004CC5 OnGestureTwoFingerTap (6 bytes) ---- */

int __thiscall CWnd::OnGestureTwoFingerTap(void)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004cc5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnGestureTwoFingerTap();
  return iVar1;
}

/* ---- FUNC 00004CCB OnGesturePressAndTap (6 bytes) ---- */

int __thiscall CWnd::OnGesturePressAndTap(void)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004ccb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnGesturePressAndTap();
  return iVar1;
}

/* ---- FUNC 00004CD1 ResizeDynamicLayout (6 bytes) ---- */

void __thiscall CWnd::ResizeDynamicLayout(CWnd *this)

{
                    /* WARNING: Could not recover jumptable at 0x000180004cd1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ResizeDynamicLayout(this);
  return;
}

/* ---- FUNC 00004CD7 CheckAutoCenter (6 bytes) ---- */

int __thiscall CWnd::CheckAutoCenter(CWnd *this)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004cd7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = CheckAutoCenter(this);
  return iVar1;
}

/* ---- FUNC 00004CDD IsFrameWnd (6 bytes) ---- */

int __thiscall CWnd::IsFrameWnd(CWnd *this)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004cdd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = IsFrameWnd(this);
  return iVar1;
}

/* ---- FUNC 00004CE3 OnFinalRelease (6 bytes) ---- */

void __thiscall CWnd::OnFinalRelease(CWnd *this)

{
                    /* WARNING: Could not recover jumptable at 0x000180004ce3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OnFinalRelease(this);
  return;
}

/* ---- FUNC 00004CE9 CreateControlContainer (6 bytes) ---- */

int __thiscall CWnd::CreateControlContainer(CWnd *this,COleControlContainer **param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004ce9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = CreateControlContainer(this,param_1);
  return iVar1;
}

/* ---- FUNC 00004CEF CreateControlSite (6 bytes) ---- */

int __thiscall
CWnd::CreateControlSite
          (CWnd *this,COleControlContainer *param_1,COleControlSite **param_2,uint param_3,
          _GUID *param_4)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004cef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = CreateControlSite(this,param_1,param_2,param_3,param_4);
  return iVar1;
}

/* ---- FUNC 00004CF5 SetOccDialogInfo (6 bytes) ---- */

int __thiscall CWnd::SetOccDialogInfo(CWnd *this,_AFX_OCC_DIALOG_INFO *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004cf5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = SetOccDialogInfo(this,param_1);
  return iVar1;
}

/* ---- FUNC 00004CFB GetOccDialogInfo (6 bytes) ---- */

_AFX_OCC_DIALOG_INFO * __thiscall CWnd::GetOccDialogInfo(CWnd *this)

{
  _AFX_OCC_DIALOG_INFO *p_Var1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004cfb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  p_Var1 = GetOccDialogInfo(this);
  return p_Var1;
}

/* ---- FUNC 00004D01 GetRuntimeClass (6 bytes) ---- */

CRuntimeClass * __thiscall CDialog::GetRuntimeClass(CDialog *this)

{
  CRuntimeClass *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004d01. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetRuntimeClass(this);
  return pCVar1;
}

/* ---- FUNC 00004D07 Create (6 bytes) ---- */

int __thiscall CDialog::Create(CDialog *this,char *param_1,CWnd *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004d07. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = Create(this,param_1,param_2);
  return iVar1;
}

/* ---- FUNC 00004D0D CreateIndirect (6 bytes) ---- */

int __thiscall
CDialog::CreateIndirect(CDialog *this,DLGTEMPLATE *param_1,CWnd *param_2,void *param_3)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004d0d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = CreateIndirect(this,param_1,param_2,param_3);
  return iVar1;
}

/* ---- FUNC 00004D13 CreateIndirect (6 bytes) ---- */

int __thiscall CDialog::CreateIndirect(CDialog *this,void *param_1,CWnd *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004d13. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = CreateIndirect(this,param_1,param_2);
  return iVar1;
}

/* ---- FUNC 00004D19 OnInitDialog (6 bytes) ---- */

int __thiscall CDialog::OnInitDialog(CDialog *this)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004d19. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnInitDialog(this);
  return iVar1;
}

/* ---- FUNC 00004D1F OnSetFont (6 bytes) ---- */

void __thiscall CDialog::OnSetFont(CDialog *this,CFont *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180004d1f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OnSetFont(this,param_1);
  return;
}

/* ---- FUNC 00004D25 OnOK (6 bytes) ---- */

void __thiscall CDialog::OnOK(CDialog *this)

{
                    /* WARNING: Could not recover jumptable at 0x000180004d25. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OnOK(this);
  return;
}

/* ---- FUNC 00004D2B OnCancel (6 bytes) ---- */

void __thiscall CDialog::OnCancel(CDialog *this)

{
                    /* WARNING: Could not recover jumptable at 0x000180004d2b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OnCancel(this);
  return;
}

/* ---- FUNC 00004D31 ~CDialog (6 bytes) ---- */

void __thiscall CDialog::~CDialog(CDialog *this)

{
                    /* WARNING: Could not recover jumptable at 0x000180004d31. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CDialog(this);
  return;
}

/* ---- FUNC 00004D37 PreTranslateMessage (6 bytes) ---- */

int __thiscall CDialog::PreTranslateMessage(CDialog *this,tagMSG *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004d37. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = PreTranslateMessage(this,param_1);
  return iVar1;
}

/* ---- FUNC 00004D3D OnCmdMsg (6 bytes) ---- */

int __thiscall
CDialog::OnCmdMsg(CDialog *this,uint param_1,int param_2,void *param_3,AFX_CMDHANDLERINFO *param_4)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004d3d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnCmdMsg(this,param_1,param_2,param_3,param_4);
  return iVar1;
}

/* ---- FUNC 00004D43 CheckAutoCenter (6 bytes) ---- */

int __thiscall CDialog::CheckAutoCenter(CDialog *this)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004d43. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = CheckAutoCenter(this);
  return iVar1;
}

/* ---- FUNC 00004D49 SetOccDialogInfo (6 bytes) ---- */

int __thiscall CDialog::SetOccDialogInfo(CDialog *this,_AFX_OCC_DIALOG_INFO *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004d49. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = SetOccDialogInfo(this,param_1);
  return iVar1;
}

/* ---- FUNC 00004D4F GetOccDialogInfo (6 bytes) ---- */

_AFX_OCC_DIALOG_INFO * __thiscall CDialog::GetOccDialogInfo(CDialog *this)

{
  _AFX_OCC_DIALOG_INFO *p_Var1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004d4f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  p_Var1 = GetOccDialogInfo(this);
  return p_Var1;
}

/* ---- FUNC 00004D55 PreInitDialog (6 bytes) ---- */

void __thiscall CDialog::PreInitDialog(CDialog *this)

{
                    /* WARNING: Could not recover jumptable at 0x000180004d55. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  PreInitDialog(this);
  return;
}

/* ---- FUNC 00004D5B GetThisMessageMap (6 bytes) ---- */

AFX_MSGMAP * __cdecl CDialog::GetThisMessageMap(void)

{
  AFX_MSGMAP *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004d5b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = GetThisMessageMap();
  return pAVar1;
}

/* ---- FUNC 00004D61 GetRuntimeClass (6 bytes) ---- */

CRuntimeClass * __thiscall CTreeCtrl::GetRuntimeClass(CTreeCtrl *this)

{
  CRuntimeClass *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004d61. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetRuntimeClass(this);
  return pCVar1;
}

/* ---- FUNC 00004D67 SetItem (6 bytes) ---- */

int __thiscall
CTreeCtrl::SetItem(CTreeCtrl *this,_TREEITEM *param_1,uint param_2,char *param_3,int param_4,
                  int param_5,uint param_6,uint param_7,__int64 param_8)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004d67. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = SetItem(this,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return iVar1;
}

/* ---- FUNC 00004D6D InsertItem (6 bytes) ---- */

_TREEITEM * __thiscall
CTreeCtrl::InsertItem
          (CTreeCtrl *this,uint param_1,char *param_2,int param_3,int param_4,uint param_5,
          uint param_6,__int64 param_7,_TREEITEM *param_8,_TREEITEM *param_9)

{
  _TREEITEM *p_Var1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004d6d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  p_Var1 = InsertItem(this,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  return p_Var1;
}

/* ---- FUNC 00004D73 ~CTreeCtrl (6 bytes) ---- */

void __thiscall CTreeCtrl::~CTreeCtrl(CTreeCtrl *this)

{
                    /* WARNING: Could not recover jumptable at 0x000180004d73. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CTreeCtrl(this);
  return;
}

/* ---- FUNC 00004D79 GetMessageMap (6 bytes) ---- */

AFX_MSGMAP * __thiscall CTreeCtrl::GetMessageMap(CTreeCtrl *this)

{
  AFX_MSGMAP *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004d79. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = GetMessageMap(this);
  return pAVar1;
}

/* ---- FUNC 00004D80 FUN_180004d80 (43 bytes) ---- */

undefined8 * FUN_180004d80(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = type_info::vftable;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

/* ---- FUNC 00004DAC operator_delete (5 bytes) ---- */

void __cdecl operator_delete(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180004aaf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete(param_1);
  return;
}

/* ---- FUNC 00004DB4 __scrt_acquire_startup_lock (57 bytes) ---- */

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
LAB_180004de2:
    uVar3 = uVar3 & 0xffffffffffffff00;
  }
  else {
    do {
      uVar3 = 0;
      LOCK();
      bVar2 = DAT_18000b758 == 0;
      uVar1 = *(ulonglong *)((longlong)Self + 8);
      if (!bVar2) {
        uVar3 = DAT_18000b758;
        uVar1 = DAT_18000b758;
      }
      DAT_18000b758 = uVar1;
      UNLOCK();
      if (bVar2) goto LAB_180004de2;
    } while (*(ulonglong *)((longlong)Self + 8) != uVar3);
    uVar3 = CONCAT71((int7)(uVar3 >> 8),1);
  }
  return uVar3;
}

/* ---- FUNC 00004DF0 __scrt_dllmain_after_initialize_c (52 bytes) ---- */

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
    uVar3 = FUN_1800057cc();
    uVar3 = _configure_narrow_argv(uVar3 & 0xffffffff);
    if ((int)uVar3 != 0) {
      return uVar3 & 0xffffffffffffff00;
    }
    uVar2 = _initialize_narrow_environment();
  }
  else {
    uVar2 = FUN_180005620();
  }
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}

/* ---- FUNC 00004E24 FUN_180004e24 (21 bytes) ---- */

bool FUN_180004e24(void)

{
  undefined8 uVar1;
  
  uVar1 = FUN_180004f6c(0);
  return (char)uVar1 != '\0';
}

/* ---- FUNC 00004E3C FUN_180004e3c (40 bytes) ---- */

undefined1 FUN_180004e3c(void)

{
  char cVar1;
  
  cVar1 = FUN_180006024();
  if (cVar1 != '\0') {
    cVar1 = FUN_180006024();
    if (cVar1 != '\0') {
      return 1;
    }
    FUN_180006024();
  }
  return 0;
}

/* ---- FUNC 00004E64 FUN_180004e64 (21 bytes) ---- */

undefined1 FUN_180004e64(void)

{
  FUN_180006024();
  FUN_180006024();
  return 1;
}

/* ---- FUNC 00004E7C __scrt_dllmain_exception_filter (96 bytes) ---- */

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
    (*(code *)PTR__guard_dispatch_icall_180007670)(param_1,0,param_3);
  }
  _seh_filter_dll(param_5,param_6);
  return;
}

/* ---- FUNC 00004EDC __scrt_dllmain_uninitialize_c (48 bytes) ---- */

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
    _execute_onexit_table(&DAT_18000b768);
    return;
  }
  uVar2 = FUN_180006028();
  if ((int)uVar2 == 0) {
    _cexit();
  }
  return;
}

/* ---- FUNC 00004F0C FUN_180004f0c (20 bytes) ---- */

void FUN_180004f0c(void)

{
  FUN_180006024();
  FUN_180006024();
  return;
}

/* ---- FUNC 00004F20 __scrt_initialize_crt (73 bytes) ---- */

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
    DAT_18000b760 = 1;
  }
  FUN_180005620();
  cVar1 = FUN_180006024();
  uVar2 = extraout_var;
  if (cVar1 != '\0') {
    cVar1 = FUN_180006024();
    if (cVar1 != '\0') {
      return CONCAT71(extraout_var_00,1);
    }
    FUN_180006024();
    uVar2 = extraout_var_01;
  }
  return (ulonglong)uVar2 << 8;
}

/* ---- FUNC 00004F6C FUN_180004f6c (138 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_180004f6c(uint param_1)

{
  bool bVar1;
  ulonglong in_RAX;
  undefined7 extraout_var;
  
  if (DAT_18000b761 == '\0') {
    if (1 < param_1) {
                    /* WARNING: Subroutine does not return */
      FUN_1800057e8(5);
    }
    bVar1 = __scrt_is_ucrt_dll_in_use();
    if (((int)CONCAT71(extraout_var,bVar1) == 0) || (param_1 != 0)) {
      in_RAX = 0xffffffffffffffff;
      DAT_18000b768 = _DAT_1800082d0;
      uRam000000018000b770 = _UNK_1800082d8;
      _DAT_18000b778 = 0xffffffffffffffff;
      _DAT_18000b780 = _DAT_1800082d0;
      uRam000000018000b788 = _UNK_1800082d8;
      _DAT_18000b790 = 0xffffffffffffffff;
    }
    else {
      in_RAX = _initialize_onexit_table(&DAT_18000b768);
      if (((int)in_RAX != 0) ||
         (in_RAX = _initialize_onexit_table(&DAT_18000b780), (int)in_RAX != 0)) {
        return in_RAX & 0xffffffffffffff00;
      }
    }
    DAT_18000b761 = '\x01';
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}

/* ---- FUNC 00004FF8 FUN_180004ff8 (152 bytes) ---- */

ulonglong FUN_180004ff8(longlong param_1)

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
           param_1 - 0x180000000U < uVar1)) goto LAB_18000506e;
      }
      lVar4 = 0;
LAB_18000506e:
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

/* ---- FUNC 00005090 __scrt_release_startup_lock (36 bytes) ---- */

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
    DAT_18000b758 = 0;
    UNLOCK();
  }
  return;
}

/* ---- FUNC 000050B4 __scrt_uninitialize_crt (41 bytes) ---- */

/* Library Function - Single Match
    __scrt_uninitialize_crt
   
   Library: Visual Studio 2019 Release */

undefined1 __scrt_uninitialize_crt(undefined8 param_1,char param_2)

{
  if ((DAT_18000b760 == '\0') || (param_2 == '\0')) {
    FUN_180006024();
    FUN_180006024();
  }
  return 1;
}

/* ---- FUNC 000050E0 _onexit (58 bytes) ---- */

/* Library Function - Single Match
    _onexit
   
   Library: Visual Studio 2019 Release */

_onexit_t __cdecl _onexit(_onexit_t _Func)

{
  int iVar1;
  _onexit_t p_Var2;
  
  if (DAT_18000b768 == -1) {
    iVar1 = _crt_atexit();
  }
  else {
    iVar1 = _register_onexit_function(&DAT_18000b768);
  }
  p_Var2 = (_onexit_t)0x0;
  if (iVar1 == 0) {
    p_Var2 = _Func;
  }
  return p_Var2;
}

/* ---- FUNC 0000511C atexit (23 bytes) ---- */

/* Library Function - Single Match
    atexit
   
   Library: Visual Studio 2019 Release */

int __cdecl atexit(_func_5014 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = _onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}

/* ---- FUNC 00005134 __GSHandlerCheck (29 bytes) ---- */

/* Library Function - Single Match
    __GSHandlerCheck
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}

/* ---- FUNC 00005154 __GSHandlerCheckCommon (91 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Single Match
    __GSHandlerCheckCommon
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

ulonglong __GSHandlerCheckCommon(undefined8 param_1,longlong param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar2 = (ulonglong)*(uint *)(*(longlong *)(param_2 + 0x10) + 8);
  uVar1 = *(ulonglong *)(param_2 + 8);
  if ((*(byte *)(uVar2 + 3 + uVar1) & 0xf) != 0) {
    uVar1 = (ulonglong)(*(byte *)(uVar2 + 3 + uVar1) & 0xfffffff0);
  }
  return uVar1;
}

/* ---- FUNC 000051B0 FID_conflict:__GSHandlerCheck_EH (127 bytes) ---- */

/* Library Function - Multiple Matches With Different Base Names
    __GSHandlerCheck_EH
    __GSHandlerCheck_EH4
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void FID_conflict___GSHandlerCheck_EH
               (longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_4 + 0x38);
  __GSHandlerCheckCommon(param_2,param_4);
  if ((*(uint *)(lVar1 + 4) & ((*(uint *)(param_1 + 4) & 0x66) != 0) + 1) != 0) {
    __CxxFrameHandler4(param_1,param_2,param_3,param_4);
  }
  return;
}

/* ---- FUNC 00005240 __chkstk (78 bytes) ---- */

/* WARNING: This is an inlined function */
/* Library Function - Single Match
    __chkstk
   
   Libraries: Visual Studio 2005, Visual Studio 2008, Visual Studio 2010, Visual Studio 2012 */

void __chkstk(void)

{
  undefined1 *in_RAX;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 local_res8 [32];
  
  puVar1 = local_res8 + -(longlong)in_RAX;
  if (local_res8 < in_RAX) {
    puVar1 = (undefined1 *)0x0;
  }
  if (puVar1 < StackLimit) {
    puVar2 = StackLimit;
    do {
      puVar2 = puVar2 + -0x1000;
      *puVar2 = 0;
    } while ((undefined1 *)((ulonglong)puVar1 & 0xfffffffffffff000) != puVar2);
  }
  return;
}

/* ---- FUNC 000052A0 __security_check_cookie (30 bytes) ---- */

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie == DAT_18000b3e8) && ((short)(_StackCookie >> 0x30) == 0)) {
    return;
  }
  FUN_180005968();
  return;
}

/* ---- FUNC 000052C0 FUN_1800052c0 (80 bytes) ---- */

ulonglong FUN_1800052c0(undefined8 param_1,int param_2,longlong param_3)

{
  byte bVar1;
  ulonglong uVar2;
  undefined7 extraout_var;
  
  if (param_2 == 0) {
    bVar1 = FUN_180005428(CONCAT71((int7)((ulonglong)param_1 >> 8),param_3 != 0));
    return CONCAT71(extraout_var,bVar1);
  }
  if (param_2 != 1) {
    if (param_2 == 2) {
      bVar1 = FUN_180004e3c();
    }
    else {
      if (param_2 != 3) {
        return 1;
      }
      bVar1 = FUN_180004e64();
    }
    return (ulonglong)bVar1;
  }
  uVar2 = FUN_180005310(param_1,param_3);
  return uVar2;
}

/* ---- FUNC 00005310 FUN_180005310 (276 bytes) ---- */

undefined8 FUN_180005310(undefined8 param_1,undefined8 param_2)

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
    if (DAT_18000b750 != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_1800057e8(7);
    }
    DAT_18000b750 = 1;
    bVar2 = FUN_180004e24();
    if (bVar2) {
      FUN_180005ba4();
      FUN_180005b5c();
      FUN_180005b80();
      iVar3 = _initterm_e(&DAT_1800076c0,&DAT_1800076c8);
      if ((iVar3 == 0) && (uVar5 = __scrt_dllmain_after_initialize_c(), (char)uVar5 != '\0')) {
        _initterm(&DAT_180007698,&DAT_1800076b8);
        DAT_18000b750 = 2;
        bVar1 = false;
      }
    }
    __scrt_release_startup_lock((char)uVar4);
    if (!bVar1) {
      plVar6 = (longlong *)FUN_180005b9c();
      if ((*plVar6 != 0) && (uVar7 = FUN_180004ff8((longlong)plVar6), (char)uVar7 != '\0')) {
        (*(code *)PTR__guard_dispatch_icall_180007670)(param_1,2,param_2);
      }
      DAT_18000b79c = DAT_18000b79c + 1;
      return 1;
    }
  }
  return 0;
}

/* ---- FUNC 00005428 FUN_180005428 (129 bytes) ---- */

byte FUN_180005428(undefined8 param_1)

{
  undefined1 uVar1;
  char cVar2;
  undefined8 uVar3;
  undefined7 uVar4;
  byte bVar5;
  
  uVar1 = (undefined1)param_1;
  if (DAT_18000b79c < 1) {
    bVar5 = 0;
  }
  else {
    DAT_18000b79c = DAT_18000b79c + -1;
    uVar3 = __scrt_acquire_startup_lock();
    if (DAT_18000b750 != 2) {
                    /* WARNING: Subroutine does not return */
      FUN_1800057e8(7);
    }
    __scrt_dllmain_uninitialize_c();
    FUN_180005b6c();
    FUN_180005be0();
    DAT_18000b750 = 0;
    uVar4 = (undefined7)((ulonglong)param_1 >> 8);
    __scrt_release_startup_lock((char)uVar3);
    cVar2 = __scrt_uninitialize_crt(CONCAT71(uVar4,uVar1),'\0');
    bVar5 = -(cVar2 != '\0') & 1;
    FUN_180004f0c();
  }
  return bVar5;
}

/* ---- FUNC 000054AC dllmain_dispatch (305 bytes) ---- */

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
  
  if ((param_2 == 0) && (DAT_18000b79c < 1)) {
    iVar4 = 0;
  }
  else {
    if (param_2 - 1 < 2) {
      if ((PTR_FUN_180007730 != (undefined *)0x0) &&
         (iVar4 = (*(code *)PTR__guard_dispatch_icall_180007670)(), iVar4 == 0)) {
        return 0;
      }
      uVar1 = FUN_1800052c0(param_1,param_2,(longlong)param_3);
      if ((int)uVar1 == 0) {
        return 0;
      }
    }
    uVar2 = FUN_180002fc0(param_1,param_2);
    iVar4 = (int)uVar2;
    if ((param_2 == 1) && (iVar4 == 0)) {
      pHVar3 = param_1;
      FUN_180002fc0(param_1,0);
      FUN_180005428(CONCAT71((int7)((ulonglong)pHVar3 >> 8),param_3 != (void *)0x0));
      if (PTR_FUN_180007730 != (undefined *)0x0) {
        (*(code *)PTR__guard_dispatch_icall_180007670)(param_1,0,param_3);
      }
    }
    if ((param_2 == 0) || (param_2 == 3)) {
      uVar1 = FUN_1800052c0(param_1,param_2,(longlong)param_3);
      iVar4 = 0;
      if ((int)uVar1 != 0) {
        if (PTR_FUN_180007730 == (undefined *)0x0) {
          iVar4 = 1;
        }
        else {
          iVar4 = (*(code *)PTR__guard_dispatch_icall_180007670)(param_1,param_2,param_3);
        }
      }
    }
  }
  return iVar4;
}

/* ---- FUNC 000055E0 entry (61 bytes) ---- */

void entry(HINSTANCE__ *param_1,ulong param_2,void *param_3)

{
  if (param_2 == 1) {
    __security_init_cookie();
  }
  dllmain_dispatch(param_1,param_2,param_3);
  return;
}

/* ---- FUNC 00005620 FUN_180005620 (428 bytes) ---- */

/* WARNING: Removing unreachable block (ram,0x0001800056ea) */
/* WARNING: Removing unreachable block (ram,0x00018000565a) */
/* WARNING: Removing unreachable block (ram,0x000180005633) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_180005620(void)

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
    _DAT_18000b400 = 0xffffffffffffffff;
    uVar7 = *puVar2 & 0xfff3ff0;
    _DAT_18000b3f8 = 0x8000;
    if ((((uVar7 == 0x106c0) || (uVar7 == 0x20660)) || (uVar7 == 0x20670)) ||
       ((uVar7 - 0x30650 < 0x21 &&
        ((0x100010001U >> ((ulonglong)(uVar7 - 0x30650) & 0x3f) & 1) != 0)))) {
      DAT_18000b7a0 = DAT_18000b7a0 | 1;
    }
  }
  if (6 < *piVar1) {
    lVar3 = cpuid_Extended_Feature_Enumeration_info(7);
    uVar8 = *(uint *)(lVar3 + 4);
    if ((uVar8 >> 9 & 1) != 0) {
      DAT_18000b7a0 = DAT_18000b7a0 | 2;
    }
  }
  _DAT_18000b3f0 = 1;
  DAT_18000b3f4 = 2;
  if ((uVar4 >> 0x14 & 1) != 0) {
    _DAT_18000b3f0 = 2;
    DAT_18000b3f4 = 6;
    if (((uVar4 >> 0x1b & 1) != 0) && ((uVar4 >> 0x1c & 1) != 0)) {
      uVar5 = xinuse(0);
      bVar6 = in_XCR0 & (byte)uVar5;
      if ((bVar6 & 6) == 6) {
        DAT_18000b3f4 = 0xe;
        _DAT_18000b3f0 = 3;
        if ((uVar8 & 0x20) != 0) {
          _DAT_18000b3f0 = 5;
          DAT_18000b3f4 = 0x2e;
          if (((uVar8 & 0xd0030000) == 0xd0030000) && ((bVar6 & 0xe0) == 0xe0)) {
            DAT_18000b3f4 = 0x6e;
            _DAT_18000b3f0 = 6;
          }
        }
      }
    }
  }
  return 0;
}

/* ---- FUNC 000057CC FUN_1800057cc (6 bytes) ---- */

undefined8 FUN_1800057cc(void)

{
  return 1;
}

/* ---- FUNC 000057D4 __scrt_is_ucrt_dll_in_use (12 bytes) ---- */

/* Library Function - Single Match
    __scrt_is_ucrt_dll_in_use
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

bool __scrt_is_ucrt_dll_in_use(void)

{
  return DAT_18000b434 != 0;
}

/* ---- FUNC 000057E0 FUN_1800057e0 (8 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1800057e0(void)

{
  _DAT_18000b7a4 = 0;
  return;
}

/* ---- FUNC 000057E8 FUN_1800057e8 (331 bytes) ---- */

void FUN_1800057e8(undefined4 param_1)

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
  *(undefined8 *)(puVar4 + -8) = 0x18000581c;
  FUN_1800057e0();
  *(undefined8 *)(puVar4 + -8) = 0x18000582d;
  memset(local_4d8,0,0x4d0);
  *(undefined8 *)(puVar4 + -8) = 0x180005837;
  RtlCaptureContext(local_4d8);
  *(undefined8 *)(puVar4 + -8) = 0x180005851;
  FunctionEntry = RtlLookupFunctionEntry(local_3e0,&local_res10,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry != (PRUNTIME_FUNCTION)0x0) {
    *(undefined8 *)(puVar4 + 0x38) = 0;
    *(undefined1 **)(puVar4 + 0x30) = local_res18;
    *(undefined1 **)(puVar4 + 0x28) = local_res20;
    *(undefined1 **)(puVar4 + 0x20) = local_4d8;
    *(undefined8 *)(puVar4 + -8) = 0x180005892;
    RtlVirtualUnwind(0,local_res10,local_3e0,FunctionEntry,*(PCONTEXT *)(puVar4 + 0x20),
                     *(PVOID **)(puVar4 + 0x28),*(PDWORD64 *)(puVar4 + 0x30),
                     *(PKNONVOLATILE_CONTEXT_POINTERS *)(puVar4 + 0x38));
  }
  local_440 = &stack0x00000008;
  *(undefined8 *)(puVar4 + -8) = 0x1800058c4;
  memset(puVar4 + 0x50,0,0x98);
  *(undefined8 *)(puVar4 + 0x60) = unaff_retaddr;
  *(undefined4 *)(puVar4 + 0x50) = 0x40000015;
  *(undefined4 *)(puVar4 + 0x54) = 1;
  *(undefined8 *)(puVar4 + -8) = 0x1800058e6;
  BVar2 = IsDebuggerPresent();
  *(undefined1 **)(puVar4 + 0x40) = puVar4 + 0x50;
  *(undefined1 **)(puVar4 + 0x48) = local_4d8;
  *(undefined8 *)(puVar4 + -8) = 0x180005907;
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  *(undefined8 *)(puVar4 + -8) = 0x180005912;
  LVar3 = UnhandledExceptionFilter((_EXCEPTION_POINTERS *)(puVar4 + 0x40));
  if ((LVar3 == 0) && (BVar2 != 1)) {
    *(undefined8 *)(puVar4 + -8) = 0x180005922;
    FUN_1800057e0();
  }
  return;
}

/* ---- FUNC 00005934 __raise_securityfailure (52 bytes) ---- */

/* Library Function - Single Match
    __raise_securityfailure
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __raise_securityfailure(_EXCEPTION_POINTERS *param_1)

{
  HANDLE pvVar1;
  
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter(param_1);
  pvVar1 = GetCurrentProcess();
                    /* WARNING: Could not recover jumptable at 0x000180005961. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TerminateProcess(pvVar1,0xc0000409);
  return;
}

/* ---- FUNC 00005968 FUN_180005968 (210 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180005968(void)

{
  code *pcVar1;
  BOOL BVar2;
  undefined1 *puVar3;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [48];
  
  puVar3 = auStack_38;
  BVar2 = IsProcessorFeaturePresent(0x17);
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(2);
    puVar3 = auStack_30;
  }
  *(undefined8 *)(puVar3 + -8) = 0x180005993;
  capture_previous_context((PCONTEXT)&DAT_18000b850);
  _DAT_18000b7c0 = *(undefined8 *)(puVar3 + 0x38);
  _DAT_18000b8e8 = puVar3 + 0x40;
  _DAT_18000b8d0 = *(undefined8 *)(puVar3 + 0x40);
  _DAT_18000b7b0 = 0xc0000409;
  _DAT_18000b7b4 = 1;
  _DAT_18000b7c8 = 1;
  DAT_18000b7d0 = 2;
  *(undefined8 *)(puVar3 + 0x20) = DAT_18000b3e8;
  *(undefined8 *)(puVar3 + 0x28) = DAT_18000b3e0;
  *(undefined8 *)(puVar3 + -8) = 0x180005a35;
  DAT_18000b948 = _DAT_18000b7c0;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_1800082e8);
  return;
}

/* ---- FUNC 00005A3C capture_previous_context (113 bytes) ---- */

/* Library Function - Single Match
    capture_previous_context
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void capture_previous_context(PCONTEXT param_1)

{
  DWORD64 ControlPc;
  PRUNTIME_FUNCTION FunctionEntry;
  int iVar1;
  DWORD64 local_res8;
  ulonglong local_res10;
  PVOID local_res18 [2];
  
  RtlCaptureContext();
  ControlPc = param_1->Rip;
  iVar1 = 0;
  do {
    FunctionEntry = RtlLookupFunctionEntry(ControlPc,&local_res8,(PUNWIND_HISTORY_TABLE)0x0);
    if (FunctionEntry == (PRUNTIME_FUNCTION)0x0) {
      return;
    }
    RtlVirtualUnwind(0,local_res8,ControlPc,FunctionEntry,param_1,local_res18,&local_res10,
                     (PKNONVOLATILE_CONTEXT_POINTERS)0x0);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  return;
}

/* ---- FUNC 00005AB0 __security_init_cookie (172 bytes) ---- */

/* Library Function - Single Match
    __security_init_cookie
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl __security_init_cookie(void)

{
  DWORD DVar1;
  _FILETIME local_res8;
  LARGE_INTEGER local_res10;
  _FILETIME local_18 [2];
  
  if (DAT_18000b3e8 == 0x2b992ddfa232) {
    local_res8.dwLowDateTime = 0;
    local_res8.dwHighDateTime = 0;
    GetSystemTimeAsFileTime(&local_res8);
    local_18[0] = local_res8;
    DVar1 = GetCurrentThreadId();
    local_18[0] = (_FILETIME)((ulonglong)local_18[0] ^ (ulonglong)DVar1);
    DVar1 = GetCurrentProcessId();
    local_18[0] = (_FILETIME)((ulonglong)local_18[0] ^ (ulonglong)DVar1);
    QueryPerformanceCounter(&local_res10);
    DAT_18000b3e8 =
         ((ulonglong)local_res10.s.LowPart << 0x20 ^
          CONCAT44(local_res10.s.HighPart,local_res10.s.LowPart) ^ (ulonglong)local_18[0] ^
         (ulonglong)local_18) & 0xffffffffffff;
    if (DAT_18000b3e8 == 0x2b992ddfa232) {
      DAT_18000b3e8 = 0x2b992ddfa233;
    }
  }
  DAT_18000b3e0 = ~DAT_18000b3e8;
  return;
}

/* ---- FUNC 00005B5C FUN_180005b5c (14 bytes) ---- */

void FUN_180005b5c(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180005b63. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InitializeSListHead(&DAT_18000bd20);
  return;
}

/* ---- FUNC 00005B6C FUN_180005b6c (12 bytes) ---- */

void FUN_180005b6c(void)

{
  __std_type_info_destroy_list(&DAT_18000bd20);
  return;
}

/* ---- FUNC 00005B78 FUN_180005b78 (8 bytes) ---- */

undefined * FUN_180005b78(void)

{
  return &DAT_18000bd30;
}

/* ---- FUNC 00005B80 FUN_180005b80 (27 bytes) ---- */

void FUN_180005b80(void)

{
  ulonglong *puVar1;
  
  puVar1 = (ulonglong *)FUN_180003030();
  *puVar1 = *puVar1 | 0x24;
  puVar1 = (ulonglong *)FUN_180005b78();
  *puVar1 = *puVar1 | 2;
  return;
}

/* ---- FUNC 00005B9C FUN_180005b9c (8 bytes) ---- */

undefined * FUN_180005b9c(void)

{
  return &DAT_18000bda8;
}

/* ---- FUNC 00005BA4 FUN_180005ba4 (60 bytes) ---- */

void FUN_180005ba4(void)

{
  longlong *plVar1;
  
  for (plVar1 = &DAT_180008d88; plVar1 < &DAT_180008d88; plVar1 = plVar1 + 1) {
    if (*plVar1 != 0) {
      (*(code *)PTR__guard_dispatch_icall_180007670)();
    }
  }
  return;
}

/* ---- FUNC 00005BE0 FUN_180005be0 (60 bytes) ---- */

void FUN_180005be0(void)

{
  longlong *plVar1;
  
  for (plVar1 = &DAT_180008d98; plVar1 < &DAT_180008d98; plVar1 = plVar1 + 1) {
    if (*plVar1 != 0) {
      (*(code *)PTR__guard_dispatch_icall_180007670)();
    }
  }
  return;
}

/* ---- FUNC 00005C20 CAtlBaseModule (165 bytes) ---- */

/* Library Function - Single Match
    public: __cdecl ATL::CAtlBaseModule::CAtlBaseModule(void) __ptr64
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

CAtlBaseModule * __thiscall ATL::CAtlBaseModule::CAtlBaseModule(CAtlBaseModule *this)

{
  DWORD DVar1;
  BOOL BVar2;
  DWORD DVar3;
  
  memset(this + 0x28,0,0x28);
  *(undefined8 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined8 *)(this + 0x10) = 0x180000000;
  *(undefined8 *)(this + 8) = 0x180000000;
  *(undefined **)(this + 0x20) = &DAT_180008318;
  *(undefined4 *)this = 0x60;
  *(undefined4 *)(this + 0x18) = 0xe00;
  BVar2 = InitializeCriticalSectionEx((LPCRITICAL_SECTION)(this + 0x28),0,0);
  if (BVar2 == 0) {
    DVar3 = GetLastError();
    DVar1 = DVar3 & 0xffff | 0x80070000;
    if ((int)DVar3 < 1) {
      DVar1 = DVar3;
    }
    if ((int)DVar1 < 0) {
      BVar2 = IsDebuggerPresent();
      if (BVar2 != 0) {
        OutputDebugStringW(L"ERROR : Unable to initialize critical section in CAtlBaseModule\n");
      }
      DAT_18000b5a0 = 1;
    }
  }
  return this;
}

/* ---- FUNC 00005CC8 ~CAtlBaseModule (52 bytes) ---- */

/* Library Function - Single Match
    public: __cdecl ATL::CAtlBaseModule::~CAtlBaseModule(void) __ptr64
   
   Library: Visual Studio */

void __thiscall ATL::CAtlBaseModule::~CAtlBaseModule(CAtlBaseModule *this)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(this + 0x28));
  if (*(void **)(this + 0x50) != (void *)0x0) {
    free(*(void **)(this + 0x50));
    *(undefined8 *)(this + 0x50) = 0;
  }
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  return;
}

/* ---- FUNC 00005CFC VarBstrCat (6 bytes) ---- */

HRESULT __stdcall VarBstrCat(BSTR bstrLeft,BSTR bstrRight,LPBSTR pbstrResult)

{
  HRESULT HVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180005cfc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HVar1 = VarBstrCat(bstrLeft,bstrRight,pbstrResult);
  return HVar1;
}

/* ---- FUNC 00005D10 FUN_180005d10 (273 bytes) ---- */

LPSTR FUN_180005d10(LPCWSTR param_1)

{
  int iVar1;
  uint uVar2;
  LPSTR lpMultiByteStr;
  longlong lVar3;
  
  if (param_1 == (LPCWSTR)0x0) {
    lpMultiByteStr = (LPSTR)0x0;
  }
  else {
    lVar3 = -1;
    do {
      lVar3 = lVar3 + 1;
    } while (param_1[lVar3] != L'\0');
    iVar1 = WideCharToMultiByte(0,0,param_1,(int)lVar3 + 1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    if (iVar1 == 0) {
      uVar2 = GetLastError();
      if (0 < (int)uVar2) {
        uVar2 = uVar2 & 0xffff | 0x80070000;
      }
                    /* WARNING: Subroutine does not return */
      FUN_180005e30((ulonglong)uVar2);
    }
    lpMultiByteStr = operator_new__((longlong)iVar1);
    if (lpMultiByteStr == (LPSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_180005e30(0x8007000e);
    }
    iVar1 = WideCharToMultiByte(0,0,param_1,(int)lVar3 + 1,lpMultiByteStr,iVar1,(LPCSTR)0x0,
                                (LPBOOL)0x0);
    if (iVar1 == 0) {
      operator_delete__(lpMultiByteStr);
      uVar2 = GetLastError();
      if (0 < (int)uVar2) {
        uVar2 = uVar2 & 0xffff | 0x80070000;
      }
                    /* WARNING: Subroutine does not return */
      FUN_180005e30((ulonglong)uVar2);
    }
  }
  return lpMultiByteStr;
}

/* ---- FUNC 00005E30 FUN_180005e30 (16 bytes) ---- */

/* WARNING: Switch with 1 destination removed at 0x000180005e39 */

void FUN_180005e30(undefined8 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180006050. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_18000b428)(param_1,0);
  return;
}

/* ---- FUNC 00005E40 _com_error (68 bytes) ---- */

/* Library Function - Single Match
    public: __cdecl _com_error::_com_error(class _com_error const & __ptr64) __ptr64
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

_com_error * __thiscall _com_error::_com_error(_com_error *this,_com_error *param_1)

{
  longlong lVar1;
  
  *(undefined ***)this = &PTR__scalar_deleting_destructor__1800083b8;
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  lVar1 = *(longlong *)(param_1 + 0x10);
  *(longlong *)(this + 0x10) = lVar1;
  *(undefined8 *)(this + 0x18) = 0;
  if (lVar1 != 0) {
    (*(code *)PTR__guard_dispatch_icall_180007670)();
  }
  return this;
}

/* ---- FUNC 00005E90 _com_error (69 bytes) ---- */

/* Library Function - Single Match
    public: __cdecl _com_error::_com_error(long,struct IErrorInfo * __ptr64,bool) __ptr64
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

_com_error * __thiscall
_com_error::_com_error(_com_error *this,long param_1,IErrorInfo *param_2,bool param_3)

{
  *(long *)(this + 8) = param_1;
  *(undefined ***)this = &PTR__scalar_deleting_destructor__1800083b8;
  *(IErrorInfo **)(this + 0x10) = param_2;
  *(undefined8 *)(this + 0x18) = 0;
  if ((param_2 != (IErrorInfo *)0x0) && (param_3)) {
    (*(code *)PTR__guard_dispatch_icall_180007670)(param_2);
  }
  return this;
}

/* ---- FUNC 00005EE0 ~_com_error (68 bytes) ---- */

/* Library Function - Single Match
    public: virtual __cdecl _com_error::~_com_error(void) __ptr64
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __thiscall _com_error::~_com_error(_com_error *this)

{
  *(undefined ***)this = &PTR__scalar_deleting_destructor__1800083b8;
  if (*(longlong *)(this + 0x10) != 0) {
    (*(code *)PTR__guard_dispatch_icall_180007670)();
  }
  if (*(HLOCAL *)(this + 0x18) != (HLOCAL)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000180005f17. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    LocalFree(*(HLOCAL *)(this + 0x18));
    return;
  }
  return;
}

/* ---- FUNC 00005F30 `scalar_deleting_destructor' (95 bytes) ---- */

/* Library Function - Single Match
    public: virtual void * __ptr64 __cdecl _com_error::`scalar deleting destructor'(unsigned int)
   __ptr64
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void * __thiscall _com_error::_scalar_deleting_destructor_(_com_error *this,uint param_1)

{
  *(undefined ***)this = &PTR__scalar_deleting_destructor__1800083b8;
  if (*(longlong *)(this + 0x10) != 0) {
    (*(code *)PTR__guard_dispatch_icall_180007670)();
  }
  if (*(HLOCAL *)(this + 0x18) != (HLOCAL)0x0) {
    LocalFree(*(HLOCAL *)(this + 0x18));
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

/* ---- FUNC 00005F90 FUN_180005f90 (39 bytes) ---- */

void FUN_180005f90(long param_1,IErrorInfo *param_2)

{
  _com_error local_28 [40];
  
  _com_error::_com_error(local_28,param_1,param_2,false);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_28,(ThrowInfo *)&DAT_1800095f0);
}

/* ---- FUNC 00005FB8 __std_terminate (6 bytes) ---- */

void __std_terminate(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180005fb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __std_terminate();
  return;
}

/* ---- FUNC 00005FBE __CxxFrameHandler4 (6 bytes) ---- */

void __CxxFrameHandler4(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180005fbe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __CxxFrameHandler4();
  return;
}

/* ---- FUNC 00005FC4 _CxxThrowException (6 bytes) ---- */

void __stdcall _CxxThrowException(void *pExceptionObject,ThrowInfo *pThrowInfo)

{
                    /* WARNING: Could not recover jumptable at 0x000180005fc4. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  _CxxThrowException(pExceptionObject,pThrowInfo);
  return;
}

/* ---- FUNC 00005FCA memset (6 bytes) ---- */

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180005fca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}

/* ---- FUNC 00005FD0 __C_specific_handler (6 bytes) ---- */

void __C_specific_handler(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180005fd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __C_specific_handler();
  return;
}

/* ---- FUNC 00005FD6 __std_type_info_destroy_list (6 bytes) ---- */

void __std_type_info_destroy_list(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180005fd6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __std_type_info_destroy_list();
  return;
}

/* ---- FUNC 00005FDC free (6 bytes) ---- */

void __cdecl free(void *_Memory)

{
                    /* WARNING: Could not recover jumptable at 0x000180005fdc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  free(_Memory);
  return;
}

/* ---- FUNC 00005FE2 _seh_filter_dll (6 bytes) ---- */

void _seh_filter_dll(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180005fe2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _seh_filter_dll();
  return;
}

/* ---- FUNC 00005FE8 _configure_narrow_argv (6 bytes) ---- */

void _configure_narrow_argv(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180005fe8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _configure_narrow_argv();
  return;
}

/* ---- FUNC 00005FEE _initialize_narrow_environment (6 bytes) ---- */

void _initialize_narrow_environment(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180005fee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initialize_narrow_environment();
  return;
}

/* ---- FUNC 00005FF4 _initialize_onexit_table (6 bytes) ---- */

void _initialize_onexit_table(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180005ff4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initialize_onexit_table();
  return;
}

/* ---- FUNC 00005FFA _register_onexit_function (6 bytes) ---- */

void _register_onexit_function(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180005ffa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _register_onexit_function();
  return;
}

/* ---- FUNC 00006000 _execute_onexit_table (6 bytes) ---- */

void _execute_onexit_table(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180006000. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _execute_onexit_table();
  return;
}

/* ---- FUNC 00006006 _crt_atexit (6 bytes) ---- */

void _crt_atexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180006006. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _crt_atexit();
  return;
}

/* ---- FUNC 0000600C _cexit (6 bytes) ---- */

void __cdecl _cexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000600c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _cexit();
  return;
}

/* ---- FUNC 00006012 _initterm (6 bytes) ---- */

void _initterm(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180006012. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm();
  return;
}

/* ---- FUNC 00006018 _initterm_e (6 bytes) ---- */

void _initterm_e(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180006018. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm_e();
  return;
}

/* ---- FUNC 0000601E operator_new[] (6 bytes) ---- */

void * __cdecl operator_new__(__uint64 param_1)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000601e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = operator_new__(param_1);
  return pvVar1;
}

/* ---- FUNC 00006024 FUN_180006024 (3 bytes) ---- */

undefined1 FUN_180006024(void)

{
  return 1;
}

/* ---- FUNC 00006028 FUN_180006028 (3 bytes) ---- */

undefined8 FUN_180006028(void)

{
  return 0;
}

/* ---- FUNC 0000602B memcpy (6 bytes) ---- */

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000602b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memcpy(_Dst,_Src,_Size);
  return pvVar1;
}

/* ---- FUNC 00006050 _guard_dispatch_icall (2 bytes) ---- */

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000180006050. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

/* ---- FUNC 00006070 _guard_dispatch_icall (6 bytes) ---- */

/* WARNING: This is an inlined function */
/* WARNING: Switch with 1 destination removed at 0x000180006070 */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000180006050. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

/* ---- FUNC 00006080 FUN_180006080 (12 bytes) ---- */

void FUN_180006080(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x0001800011c3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SysFreeString(*(BSTR *)(param_2 + 0x80));
  return;
}

/* ---- FUNC 00006090 FUN_180006090 (39 bytes) ---- */

undefined8 FUN_180006090(undefined8 param_1,longlong param_2)

{
  CException::Delete(*(CException **)(param_2 + 0x30));
  return 0;
}

/* ---- FUNC 000060C0 FUN_1800060c0 (12 bytes) ---- */

void FUN_1800060c0(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x0001800011d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  VariantClear((VARIANTARG *)(param_2 + 0x80));
  return;
}

/* ---- FUNC 000060D0 FUN_1800060d0 (12 bytes) ---- */

void FUN_1800060d0(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x0001800011d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  VariantClear((VARIANTARG *)(param_2 + 0x78));
  return;
}

/* ---- FUNC 000060E0 FUN_1800060e0 (12 bytes) ---- */

void FUN_1800060e0(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x0001800011d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  VariantClear((VARIANTARG *)(param_2 + 0x70));
  return;
}

/* ---- FUNC 000060F0 FUN_1800060f0 (12 bytes) ---- */

void FUN_1800060f0(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x0001800011d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  VariantClear((VARIANTARG *)(param_2 + 0x68));
  return;
}

/* ---- FUNC 00006100 FUN_180006100 (12 bytes) ---- */

void FUN_180006100(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x0001800011d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  VariantClear((VARIANTARG *)(param_2 + 0x88));
  return;
}

/* ---- FUNC 00006110 FUN_180006110 (12 bytes) ---- */

void FUN_180006110(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x0001800011d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  VariantClear((VARIANTARG *)(param_2 + 0x50));
  return;
}

/* ---- FUNC 00006140 FUN_180006140 (12 bytes) ---- */

void FUN_180006140(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x0001800011d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  VariantClear((VARIANTARG *)(param_2 + 0x90));
  return;
}

/* ---- FUNC 00006150 FUN_180006150 (12 bytes) ---- */

void FUN_180006150(undefined8 param_1,longlong param_2)

{
  CDialog *this;
  
  this = *(CDialog **)(param_2 + 0x30);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(this + 0x140));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(this + 0x138));
  CDialog::~CDialog(this);
  return;
}

/* ---- FUNC 00006160 FUN_180006160 (19 bytes) ---- */

void FUN_180006160(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x000180004d73. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CTreeCtrl::~CTreeCtrl((CTreeCtrl *)(*(longlong *)(param_2 + 0x30) + 0x150));
  return;
}

/* ---- FUNC 00006173 FUN_180006173 (23 bytes) ---- */

bool FUN_180006173(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}

/* ---- FUNC 0000618B FUN_18000618b (22 bytes) ---- */

void FUN_18000618b(undefined8 param_1,longlong param_2)

{
  __scrt_release_startup_lock(*(char *)(param_2 + 0x40));
  return;
}

/* ---- FUNC 000061A2 FUN_1800061a2 (24 bytes) ---- */

void FUN_1800061a2(undefined8 param_1,longlong param_2)

{
  __scrt_release_startup_lock(*(char *)(param_2 + 0x20));
  return;
}

/* ---- FUNC 000061BB FUN_1800061bb (19 bytes) ---- */

void FUN_1800061bb(void)

{
  FUN_180004f0c();
  return;
}

/* ---- FUNC 000061CF FUN_1800061cf (53 bytes) ---- */

void FUN_1800061cf(undefined8 *param_1,longlong param_2)

{
  __scrt_dllmain_exception_filter
            (*(undefined8 *)(param_2 + 0x60),*(int *)(param_2 + 0x68),
             *(undefined8 *)(param_2 + 0x70),FUN_1800052c0,*(undefined4 *)*param_1,param_1);
  return;
}

/* ---- FUNC 00006210 FUN_180006210 (29 bytes) ---- */

undefined8 FUN_180006210(void)

{
  return 0;
}

/* ---- FUNC 00006230 FUN_180006230 (14 bytes) ---- */

void FUN_180006230(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180006237. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_18000b728);
  return;
}

/* ---- FUNC 00006240 FUN_180006240 (12 bytes) ---- */

void FUN_180006240(void)

{
  ATL::CAtlBaseModule::~CAtlBaseModule((CAtlBaseModule *)&DAT_18000bd40);
  return;
}

/* ---- FUNC 00006250 FUN_180006250 (14 bytes) ---- */

void FUN_180006250(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180006257. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  VariantClear((VARIANTARG *)&DAT_18000b410);
  return;
}
