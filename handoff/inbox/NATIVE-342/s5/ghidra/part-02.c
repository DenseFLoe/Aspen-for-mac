/* RVA 0x6b40 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180006b40(ulonglong param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined1 *puVar3;
  undefined1 auStack_38 [48];
  
  puVar3 = auStack_38;
  uVar2 = 1;
  if (~param_1 < 0x4000) {
    uVar2 = 0;
  }
  else {
    uVar1 = param_1 + 0x400f;
    if (uVar1 <= param_1 + 0x4000) {
      uVar1 = 0xffffffffffffff0;
    }
    puVar3 = auStack_38 + -(uVar1 & 0xfffffffffffffff0);
  }
  *(undefined8 *)(puVar3 + -8) = 0x180006bba;
  return uVar2;
}

/* RVA 0x6bd0 */
HRESULT __stdcall DllCanUnloadNow(void)

{
  int iVar1;
  
                    /* 0x6bd0  13  DllCanUnloadNow */
  iVar1 = (**(code **)(DAT_1800540e0 + 0x18))(&DAT_1800540e0);
  return (uint)(iVar1 != 0);
}

/* RVA 0x6c00 */
HRESULT __stdcall DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  HRESULT HVar1;
  longlong *local_res20;
  
                    /* 0x6c00  14  DllGetClassObject */
  if (DAT_180054050 == 0) {
    local_res20 = (longlong *)0x0;
    FUN_180003c00(0,&DAT_180040ee0,&local_res20);
    (**(code **)(*local_res20 + 0x10))();
  }
  HVar1 = HappGetClassObject(rclsid,riid,ppv);
  return HVar1;
}

/* RVA 0x6c70 */
DWORD DllRegisterServer(void)

{
  undefined8 *puVar1;
  LCID Locale;
  DWORD DVar2;
  int *piVar3;
  longlong *plVar4;
  ulonglong uVar5;
  longlong *plVar6;
  wchar_t *local_28;
  wchar_t *local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
                    /* 0x6c70  15  DllRegisterServer */
  Locale = GetThreadLocale();
  SetThreadLocale(0x800);
  local_28 = L"APPID";
  local_20 = L"{5B52D748-52AB-47EE-8180-D7E0F50C5219}";
  local_18 = 0;
  uStack_10 = 0;
  DVar2 = FUN_180005e20(DAT_1800534d0,0x65,1,&local_28);
  if ((int)DVar2 < 0) goto LAB_180006d6a;
  DVar2 = 0;
  plVar4 = (longlong *)PTR_DAT_1800527b8;
  plVar6 = (longlong *)PTR_PTR_1800527b0;
  if (PTR_PTR_1800527b0 < PTR_DAT_1800527b8) {
    do {
      puVar1 = (undefined8 *)*plVar6;
      if (puVar1 != (undefined8 *)0x0) {
        DVar2 = (*(code *)puVar1[1])(1);
        if ((int)DVar2 < 0) goto LAB_180006d45;
        piVar3 = (int *)(*(code *)puVar1[6])();
        DVar2 = FUN_1800032e0((GUID *)*puVar1,piVar3,1);
        if ((int)DVar2 < 0) goto LAB_180006d45;
        plVar4 = (longlong *)PTR_DAT_1800527b8;
      }
      plVar6 = plVar6 + 1;
    } while (plVar6 < plVar4);
    if (-1 < (int)DVar2) goto LAB_180006d35;
  }
  else {
LAB_180006d35:
    uVar5 = FUN_180003890((HMODULE)PTR_IMAGE_DOS_HEADER_1800527a8,(LPCWSTR)0x0);
    DVar2 = (DWORD)uVar5;
  }
LAB_180006d45:
  if ((-1 < (int)DVar2) && (DAT_1800534b8 != (code *)0x0)) {
    DVar2 = (*DAT_1800534b8)(DAT_1800547c8);
  }
LAB_180006d6a:
  SetThreadLocale(Locale);
  return DVar2;
}

/* RVA 0x6d80 */
DWORD DllUnregisterServer(void)

{
  undefined8 *puVar1;
  LCID Locale;
  DWORD DVar2;
  int *piVar3;
  longlong *plVar4;
  longlong *plVar5;
  wchar_t *local_28;
  wchar_t *local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
                    /* 0x6d80  16  DllUnregisterServer */
  Locale = GetThreadLocale();
  SetThreadLocale(0x800);
  if ((DAT_1800534c0 == (code *)0x0) || (DVar2 = (*DAT_1800534c0)(), -1 < (int)DVar2)) {
    DVar2 = 0;
    plVar4 = (longlong *)PTR_DAT_1800527b8;
    plVar5 = (longlong *)PTR_PTR_1800527b0;
    if (PTR_PTR_1800527b0 < PTR_DAT_1800527b8) {
      do {
        puVar1 = (undefined8 *)*plVar5;
        if (puVar1 != (undefined8 *)0x0) {
          piVar3 = (int *)(*(code *)puVar1[6])();
          DVar2 = FUN_1800032e0((GUID *)*puVar1,piVar3,0);
          if (((int)DVar2 < 0) || (DVar2 = (*(code *)puVar1[1])(0), (int)DVar2 < 0))
          goto LAB_180006e28;
          plVar4 = (longlong *)PTR_DAT_1800527b8;
        }
        plVar5 = plVar5 + 1;
      } while (plVar5 < plVar4);
      if ((int)DVar2 < 0) goto LAB_180006e28;
    }
    DVar2 = FUN_180003a70((HMODULE)PTR_IMAGE_DOS_HEADER_1800527a8,(LPCWSTR)0x0);
  }
LAB_180006e28:
  if (-1 < (int)DVar2) {
    local_28 = L"APPID";
    local_20 = L"{5B52D748-52AB-47EE-8180-D7E0F50C5219}";
    local_18 = 0;
    uStack_10 = 0;
    DVar2 = FUN_180005e20(DAT_1800534d0,0x65,0,&local_28);
  }
  SetThreadLocale(Locale);
  return DVar2;
}

/* RVA 0x6e80 */
void FUN_180006e80(void *param_1,void *param_2)

{
  if (param_1 == param_2) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000180006e85. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  free(param_1);
  return;
}

/* RVA 0x6e90 */
void FUN_180006e90(undefined8 *param_1,void *param_2,size_t param_3)

{
  ulonglong uVar1;
  void *_Dst;
  ulonglong uVar2;
  
  if (0x7fffffffffffffff < param_3) {
                    /* WARNING: Subroutine does not return */
    FUN_18001d1b0();
  }
  param_1[3] = 0xf;
  if (param_3 < 0x10) {
    param_1[2] = param_3;
    memcpy(param_1,param_2,param_3);
    *(undefined1 *)(param_3 + (longlong)param_1) = 0;
  }
  else {
    uVar1 = param_3 | 0xf;
    uVar2 = 0x7fffffffffffffff;
    if ((uVar1 < 0x8000000000000000) && (uVar2 = uVar1, uVar1 < 0x16)) {
      uVar2 = 0x16;
    }
    _Dst = FUN_18001d210(param_1,uVar2 + 1);
    *param_1 = _Dst;
    param_1[2] = param_3;
    param_1[3] = uVar2;
    memcpy(_Dst,param_2,param_3);
    *(undefined1 *)((longlong)_Dst + param_3) = 0;
  }
  return;
}

/* RVA 0x6f50 */
void FUN_180006f50(undefined8 *param_1,void *param_2,ulonglong param_3)

{
  ulonglong uVar1;
  void *_Dst;
  ulonglong uVar2;
  
  if (0x7ffffffffffffffe < param_3) {
                    /* WARNING: Subroutine does not return */
    FUN_18001d1b0();
  }
  param_1[3] = 7;
  if (param_3 < 8) {
    param_1[2] = param_3;
    memcpy(param_1,param_2,param_3 * 2);
    *(undefined2 *)(param_3 * 2 + (longlong)param_1) = 0;
  }
  else {
    uVar1 = param_3 | 7;
    uVar2 = 0x7ffffffffffffffe;
    if ((uVar1 < 0x7fffffffffffffff) && (uVar2 = uVar1, uVar1 < 10)) {
      uVar2 = 10;
    }
    _Dst = FUN_18001d2e0(param_1,uVar2 + 1);
    param_1[2] = param_3;
    *param_1 = _Dst;
    param_1[3] = uVar2;
    memcpy(_Dst,param_2,param_3 * 2);
    *(undefined2 *)(param_3 * 2 + (longlong)_Dst) = 0;
  }
  return;
}

/* RVA 0x7020 */
void FUN_180007020(longlong *param_1,longlong *param_2)

{
  if (param_1 != param_2) {
    do {
      FUN_180008b00(param_1);
      param_1 = param_1 + 8;
    } while (param_1 != param_2);
  }
  return;
}

/* RVA 0x7060 */
void FUN_180007060(longlong *param_1,longlong *param_2)

{
  void *pvVar1;
  void *pvVar2;
  
  if (param_1 != param_2) {
    do {
      if (0xf < (ulonglong)param_1[3]) {
        pvVar1 = (void *)*param_1;
        pvVar2 = pvVar1;
        if ((0xfff < param_1[3] + 1U) &&
           (pvVar2 = *(void **)((longlong)pvVar1 + -8),
           0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        FUN_180035134(pvVar2);
      }
      param_1[2] = 0;
      param_1[3] = 0xf;
      *(undefined1 *)param_1 = 0;
      param_1 = param_1 + 4;
    } while (param_1 != param_2);
  }
  return;
}

/* RVA 0x70f0 */
undefined8 * FUN_1800070f0(longlong *param_1,undefined8 *param_2,undefined8 *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  code *pcVar3;
  uint uVar4;
  longlong *plVar5;
  longlong *plVar6;
  undefined8 *puVar7;
  longlong *plVar8;
  longlong *plVar9;
  ulonglong _Size;
  longlong *local_68;
  longlong *plStack_60;
  longlong *local_58;
  uint uStack_50;
  undefined4 uStack_4c;
  
  plVar6 = (longlong *)*param_1;
  local_58 = (longlong *)plVar6[1];
  uStack_50 = 0;
  plVar9 = plVar6;
  if (*(char *)((longlong)local_58 + 0x19) == '\0') {
    uVar1 = param_3[2];
    plVar5 = local_58;
    do {
      puVar7 = param_3;
      if (0xf < (ulonglong)param_3[3]) {
        puVar7 = (undefined8 *)*param_3;
      }
      plVar8 = plVar5 + 4;
      if (0xf < (ulonglong)plVar5[7]) {
        plVar8 = (longlong *)plVar5[4];
      }
      uVar2 = plVar5[6];
      _Size = uVar2;
      if (uVar1 < uVar2) {
        _Size = uVar1;
      }
      local_58 = plVar5;
      uVar4 = memcmp(plVar8,puVar7,_Size);
      if (uVar4 == 0) {
        if (uVar2 < uVar1) {
          uVar4 = 0xffffffff;
        }
        else {
          uVar4 = (uint)(uVar1 < uVar2);
        }
      }
      if (-1 < (int)uVar4) {
        plVar8 = (longlong *)*plVar5;
        plVar9 = plVar5;
      }
      else {
        plVar8 = (longlong *)plVar5[2];
      }
      uStack_50 = (uint)(-1 < (int)uVar4);
      plVar5 = plVar8;
    } while (*(char *)((longlong)plVar8 + 0x19) == '\0');
  }
  if ((*(char *)((longlong)plVar9 + 0x19) == '\0') &&
     (uVar4 = FUN_180009190(param_1,param_3,plVar9 + 4), (char)uVar4 == '\0')) {
    *param_2 = plVar9;
    *(undefined1 *)(param_2 + 1) = 0;
    return param_2;
  }
  if (param_1[1] == 0x276276276276276) {
    FUN_18001d100();
    pcVar3 = (code *)swi(3);
    puVar7 = (undefined8 *)(*pcVar3)();
    return puVar7;
  }
  plStack_60 = (longlong *)0x0;
  local_68 = param_1;
  plVar5 = operator_new(0x68);
  plStack_60 = plVar5;
  FUN_180008630(plVar5 + 4,param_3);
  plVar9 = param_3 + 4;
  plVar8 = plVar5 + 8;
  *plVar8 = 0;
  plVar5[9] = 0;
  plVar5[10] = 0;
  plVar5[0xb] = 0xf;
  *(undefined1 *)plVar8 = 0;
  if (plVar8 != plVar9) {
    if (0xf < (ulonglong)param_3[7]) {
      plVar9 = (longlong *)*plVar9;
    }
    FUN_18001d350(plVar8,plVar9,param_3[6]);
  }
  *(undefined4 *)(plVar5 + 0xc) = *(undefined4 *)(param_3 + 8);
  *plVar5 = (longlong)plVar6;
  plVar5[1] = (longlong)plVar6;
  plVar5[2] = (longlong)plVar6;
  *(undefined2 *)(plVar5 + 3) = 0;
  plStack_60 = (longlong *)CONCAT44(uStack_4c,uStack_50);
  local_68 = local_58;
  plVar6 = FUN_18001cd40(param_1,(longlong *)&local_68,plVar5);
  *param_2 = plVar6;
  *(undefined1 *)(param_2 + 1) = 1;
  return param_2;
}

/* RVA 0x72c0 */
undefined4 * FUN_1800072c0(longlong *param_1,void *param_2,undefined4 *param_3)

{
  ulonglong uVar1;
  undefined4 *puVar2;
  longlong lVar3;
  longlong lVar4;
  void *pvVar5;
  ulonglong uVar6;
  undefined4 *_Dst;
  void *pvVar7;
  undefined4 *_Dst_00;
  ulonglong uVar8;
  size_t _Size;
  
  lVar3 = *param_1;
  lVar4 = param_1[1] - lVar3 >> 2;
  if (lVar4 == 0x3fffffffffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_18001d1d0();
  }
  uVar1 = lVar4 + 1;
  uVar6 = param_1[2] - lVar3 >> 2;
  if (0x3fffffffffffffff - (uVar6 >> 1) < uVar6) {
LAB_180007452:
                    /* WARNING: Subroutine does not return */
    FUN_18001d0c0();
  }
  uVar6 = (uVar6 >> 1) + uVar6;
  uVar8 = uVar1;
  if (uVar1 <= uVar6) {
    uVar8 = uVar6;
  }
  if (0x3fffffffffffffff < uVar8) goto LAB_180007452;
  uVar6 = uVar8 * 4;
  if (uVar6 < 0x1000) {
    if (uVar6 == 0) {
      _Dst_00 = (undefined4 *)0x0;
    }
    else {
      _Dst_00 = operator_new(uVar6);
    }
  }
  else {
    if (uVar6 + 0x27 <= uVar6) goto LAB_180007452;
    pvVar5 = operator_new(uVar6 + 0x27);
    if (pvVar5 == (void *)0x0) goto LAB_18000744b;
    _Dst_00 = (undefined4 *)((longlong)pvVar5 + 0x27U & 0xffffffffffffffe0);
    *(void **)(_Dst_00 + -2) = pvVar5;
  }
  puVar2 = _Dst_00 + ((longlong)param_2 - lVar3 >> 2);
  *puVar2 = *param_3;
  pvVar5 = (void *)*param_1;
  if (param_2 == (void *)param_1[1]) {
    _Size = param_1[1] - (longlong)pvVar5;
    _Dst = _Dst_00;
    param_2 = pvVar5;
  }
  else {
    memmove(_Dst_00,pvVar5,(longlong)param_2 - (longlong)pvVar5);
    _Dst = puVar2 + 1;
    _Size = param_1[1] - (longlong)param_2;
  }
  memmove(_Dst,param_2,_Size);
  pvVar5 = (void *)*param_1;
  if (pvVar5 != (void *)0x0) {
    pvVar7 = pvVar5;
    if ((0xfff < (param_1[2] - (longlong)pvVar5 & 0xfffffffffffffffcU)) &&
       (pvVar7 = *(void **)((longlong)pvVar5 + -8),
       0x1f < (ulonglong)((longlong)pvVar5 + (-8 - (longlong)pvVar7)))) {
LAB_18000744b:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(pvVar7);
  }
  *param_1 = (longlong)_Dst_00;
  param_1[1] = (longlong)(_Dst_00 + uVar1);
  param_1[2] = (longlong)(_Dst_00 + uVar8);
  return puVar2;
}

/* RVA 0x7460 */
undefined8 * FUN_180007460(longlong *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  longlong *plVar3;
  void *pvVar4;
  ulonglong uVar5;
  void *pvVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  longlong *plVar9;
  undefined8 *puVar10;
  longlong lVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  
  lVar2 = *param_1;
  lVar11 = param_1[1] - lVar2 >> 6;
  if (lVar11 == 0x3ffffffffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_18001d1d0();
  }
  uVar12 = lVar11 + 1;
  uVar5 = param_1[2] - lVar2 >> 6;
  if (0x3ffffffffffffff - (uVar5 >> 1) < uVar5) {
    uVar13 = 0xffffffffffffffc0;
    uVar5 = 0xffffffffffffffe7;
LAB_180007518:
    pvVar4 = operator_new(uVar5);
    if (pvVar4 == (void *)0x0) goto LAB_180007665;
    puVar10 = (undefined8 *)((longlong)pvVar4 + 0x27U & 0xffffffffffffffe0);
    puVar10[-1] = pvVar4;
  }
  else {
    uVar5 = (uVar5 >> 1) + uVar5;
    uVar13 = uVar12;
    if (uVar12 <= uVar5) {
      uVar13 = uVar5;
    }
    if (0x3ffffffffffffff < uVar13) {
LAB_18000766c:
                    /* WARNING: Subroutine does not return */
      FUN_18001d0c0();
    }
    uVar13 = uVar13 * 0x40;
    if (0xfff < uVar13) {
      uVar5 = uVar13 + 0x27;
      if (uVar5 <= uVar13) goto LAB_18000766c;
      goto LAB_180007518;
    }
    if (uVar13 == 0) {
      puVar10 = (undefined8 *)0x0;
    }
    else {
      puVar10 = operator_new(uVar13);
    }
  }
  puVar1 = (undefined8 *)(((longlong)param_2 - lVar2 & 0xffffffffffffffc0U) + (longlong)puVar10);
  puVar8 = puVar1 + 8;
  FUN_180008630(puVar1,param_3);
  FUN_180008630(puVar1 + 4,param_3 + 4);
  puVar7 = (undefined8 *)param_1[1];
  if (param_2 == puVar7) {
    param_2 = (undefined8 *)*param_1;
    puVar8 = puVar10;
  }
  else {
    FUN_180008120((undefined8 *)*param_1,param_2,puVar10);
    puVar7 = (undefined8 *)param_1[1];
  }
  FUN_180008120(param_2,puVar7,puVar8);
  plVar9 = (longlong *)*param_1;
  if (plVar9 != (longlong *)0x0) {
    plVar3 = (longlong *)param_1[1];
    for (; plVar9 != plVar3; plVar9 = plVar9 + 8) {
      FUN_180008b00(plVar9);
    }
    pvVar4 = (void *)*param_1;
    pvVar6 = pvVar4;
    if ((0xfff < (param_1[2] - (longlong)pvVar4 & 0xffffffffffffffc0U)) &&
       (pvVar6 = *(void **)((longlong)pvVar4 + -8),
       0x1f < (ulonglong)((longlong)pvVar4 + (-8 - (longlong)pvVar6)))) {
LAB_180007665:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(pvVar6);
  }
  *param_1 = (longlong)puVar10;
  param_1[1] = (longlong)(puVar10 + uVar12 * 8);
  param_1[2] = uVar13 + (longlong)puVar10;
  return puVar1;
}

/* RVA 0x7680 */
undefined8 * FUN_180007680(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  ulonglong uVar5;
  longlong *plVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  longlong *plVar9;
  
  lVar2 = *param_1;
  lVar3 = param_1[1] - lVar2 >> 5;
  if (lVar3 == 0x7ffffffffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_18001d1d0();
  }
  uVar1 = lVar3 + 1;
  uVar5 = param_1[2] - lVar2 >> 5;
  uVar7 = 0x7ffffffffffffff;
  if ((uVar5 <= 0x7ffffffffffffff - (uVar5 >> 1)) && (uVar7 = (uVar5 >> 1) + uVar5, uVar7 < uVar1))
  {
    uVar7 = uVar1;
  }
  plVar4 = FUN_18001d270(param_1,uVar7);
  puVar8 = (undefined8 *)(((longlong)param_2 - lVar2 & 0xffffffffffffffe0U) + (longlong)plVar4);
  plVar9 = puVar8 + 4;
  FUN_180008630(puVar8,param_3);
  plVar6 = (longlong *)param_1[1];
  if (param_2 == plVar6) {
    param_2 = (longlong *)*param_1;
    plVar9 = plVar4;
  }
  else {
    FUN_1800081c0((longlong *)*param_1,param_2,plVar4);
    plVar6 = (longlong *)param_1[1];
  }
  FUN_1800081c0(param_2,plVar6,plVar9);
  FUN_18001c5d0(param_1,(longlong)plVar4,uVar1,uVar7);
  return puVar8;
}

/* RVA 0x77a0 */
undefined8 * FUN_1800077a0(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong *plVar5;
  ulonglong uVar6;
  longlong *plVar7;
  ulonglong uVar8;
  longlong *plVar9;
  undefined8 *puVar10;
  
  lVar2 = *param_1;
  lVar4 = param_1[1] - lVar2 >> 5;
  if (lVar4 == 0x7ffffffffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_18001d1d0();
  }
  uVar1 = lVar4 + 1;
  uVar6 = param_1[2] - lVar2 >> 5;
  uVar8 = 0x7ffffffffffffff;
  if ((uVar6 <= 0x7ffffffffffffff - (uVar6 >> 1)) && (uVar8 = (uVar6 >> 1) + uVar6, uVar8 < uVar1))
  {
    uVar8 = uVar1;
  }
  plVar5 = FUN_18001d270(param_1,uVar8);
  puVar10 = (undefined8 *)(((longlong)param_2 - lVar2 & 0xffffffffffffffe0U) + (longlong)plVar5);
  plVar9 = puVar10 + 4;
  *puVar10 = 0;
  puVar10[1] = 0;
  puVar10[2] = 0;
  puVar10[3] = 0;
  uVar3 = param_3[1];
  *puVar10 = *param_3;
  puVar10[1] = uVar3;
  uVar3 = param_3[3];
  puVar10[2] = param_3[2];
  puVar10[3] = uVar3;
  param_3[2] = 0;
  param_3[3] = 0xf;
  *(undefined1 *)param_3 = 0;
  plVar7 = (longlong *)param_1[1];
  if (param_2 == plVar7) {
    param_2 = (longlong *)*param_1;
    plVar9 = plVar5;
  }
  else {
    FUN_1800081c0((longlong *)*param_1,param_2,plVar5);
    plVar7 = (longlong *)param_1[1];
  }
  FUN_1800081c0(param_2,plVar7,plVar9);
  FUN_18001c5d0(param_1,(longlong)plVar5,uVar1,uVar8);
  return puVar10;
}

/* RVA 0x78e0 */
longlong * FUN_1800078e0(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  int iVar3;
  undefined8 *_Buf1;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  undefined8 *local_res8;
  
  puVar10 = (undefined8 *)*param_1;
  puVar7 = (undefined8 *)puVar10[1];
  local_res8 = puVar10;
  if (*(char *)((longlong)puVar7 + 0x19) == '\0') {
    uVar1 = param_3[2];
    puVar6 = puVar7;
    do {
      puVar5 = puVar6 + 4;
      puVar4 = param_3;
      if (0xf < (ulonglong)param_3[3]) {
        puVar4 = (undefined8 *)*param_3;
      }
      uVar8 = puVar6[7];
      _Buf1 = puVar5;
      if (0xf < uVar8) {
        _Buf1 = (undefined8 *)*puVar5;
      }
      uVar2 = puVar6[6];
      uVar9 = uVar2;
      if (uVar1 < uVar2) {
        uVar9 = uVar1;
      }
      iVar3 = memcmp(_Buf1,puVar4,uVar9);
      if (iVar3 == 0) {
        if (uVar2 < uVar1) goto LAB_1800079a7;
LAB_18000796a:
        if (*(char *)((longlong)puVar10 + 0x19) != '\0') {
          if (0xf < uVar8) {
            puVar5 = (undefined8 *)*puVar5;
          }
          puVar4 = param_3;
          if (0xf < (ulonglong)param_3[3]) {
            puVar4 = (undefined8 *)*param_3;
          }
          uVar8 = uVar1;
          if (uVar2 < uVar1) {
            uVar8 = uVar2;
          }
          iVar3 = memcmp(puVar4,puVar5,uVar8);
          if (iVar3 == 0) {
            if (uVar1 < uVar2) goto LAB_1800079b7;
          }
          else if (iVar3 < 0) {
LAB_1800079b7:
            puVar10 = puVar6;
          }
        }
        puVar5 = (undefined8 *)*puVar6;
        local_res8 = puVar6;
      }
      else {
        if (-1 < iVar3) goto LAB_18000796a;
LAB_1800079a7:
        puVar5 = (undefined8 *)puVar6[2];
      }
      puVar6 = puVar5;
    } while (*(char *)((longlong)puVar5 + 0x19) == '\0');
  }
  if (*(char *)((longlong)puVar10 + 0x19) == '\0') {
    puVar7 = (undefined8 *)*puVar10;
  }
  if (*(char *)((longlong)puVar7 + 0x19) == '\0') {
    uVar1 = param_3[3];
    uVar8 = param_3[2];
    do {
      puVar6 = puVar7 + 4;
      if (0xf < (ulonglong)puVar7[7]) {
        puVar6 = (undefined8 *)puVar7[4];
      }
      puVar5 = param_3;
      if (0xf < uVar1) {
        puVar5 = (undefined8 *)*param_3;
      }
      uVar2 = puVar7[6];
      uVar9 = uVar8;
      if (uVar2 < uVar8) {
        uVar9 = uVar2;
      }
      iVar3 = memcmp(puVar5,puVar6,uVar9);
      if (iVar3 == 0) {
        if (uVar8 < uVar2) goto LAB_180007a57;
LAB_180007a29:
        puVar6 = (undefined8 *)puVar7[2];
      }
      else {
        if (-1 < iVar3) goto LAB_180007a29;
LAB_180007a57:
        puVar6 = (undefined8 *)*puVar7;
        puVar10 = puVar7;
      }
      puVar7 = puVar6;
    } while (*(char *)((longlong)puVar6 + 0x19) == '\0');
  }
  *param_2 = (longlong)local_res8;
  param_2[1] = (longlong)puVar10;
  return param_2;
}

/* RVA 0x7a60 */
void FUN_180007a60(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  char cVar1;
  longlong *plVar2;
  
  cVar1 = *(char *)((longlong)param_3 + 0x19);
  while (cVar1 == '\0') {
    FUN_180007a60(param_1,param_2,(longlong *)param_3[2]);
    plVar2 = (longlong *)*param_3;
    FUN_180008b00(param_3 + 4);
    FUN_180035134(param_3);
    param_3 = plVar2;
    cVar1 = *(char *)((longlong)plVar2 + 0x19);
  }
  return;
}

/* RVA 0x7ae0 */
void FUN_180007ae0(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  char cVar1;
  longlong *plVar2;
  void *pvVar3;
  void *pvVar4;
  
  cVar1 = *(char *)((longlong)param_3 + 0x19);
  do {
    if (cVar1 != '\0') {
      return;
    }
    FUN_180007ae0(param_1,param_2,(longlong *)param_3[2]);
    plVar2 = (longlong *)*param_3;
    if (0xf < (ulonglong)param_3[7]) {
      pvVar3 = (void *)param_3[4];
      pvVar4 = pvVar3;
      if ((0xfff < param_3[7] + 1U) &&
         (pvVar4 = *(void **)((longlong)pvVar3 + -8),
         0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)pvVar4)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      FUN_180035134(pvVar4);
    }
    param_3[6] = 0;
    param_3[7] = 0xf;
    *(undefined1 *)(param_3 + 4) = 0;
    FUN_180035134(param_3);
    cVar1 = *(char *)((longlong)plVar2 + 0x19);
    param_3 = plVar2;
  } while( true );
}

/* RVA 0x7ba0 */
longlong * FUN_180007ba0(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 *_Buf1;
  undefined8 *_Buf2;
  undefined8 *puVar7;
  ulonglong _Size;
  
  lVar1 = *param_1;
  *(undefined4 *)(param_2 + 1) = 0;
  param_2[2] = lVar1;
  puVar7 = *(undefined8 **)(lVar1 + 8);
  *param_2 = (longlong)puVar7;
  if (*(char *)((longlong)puVar7 + 0x19) == '\0') {
    uVar2 = param_3[2];
    uVar3 = param_3[3];
    do {
      *param_2 = (longlong)puVar7;
      _Buf2 = param_3;
      if (0xf < uVar3) {
        _Buf2 = (undefined8 *)*param_3;
      }
      _Buf1 = puVar7 + 4;
      if (0xf < (ulonglong)puVar7[7]) {
        _Buf1 = (undefined8 *)puVar7[4];
      }
      uVar4 = puVar7[6];
      _Size = uVar4;
      if (uVar2 < uVar4) {
        _Size = uVar2;
      }
      iVar5 = memcmp(_Buf1,_Buf2,_Size);
      if (iVar5 == 0) {
        if (uVar2 <= uVar4) goto LAB_180007c18;
LAB_180007c4d:
        puVar7 = (undefined8 *)puVar7[2];
        uVar6 = 0;
      }
      else {
        if (iVar5 < 0) goto LAB_180007c4d;
LAB_180007c18:
        param_2[2] = (longlong)puVar7;
        uVar6 = 1;
        puVar7 = (undefined8 *)*puVar7;
      }
      *(undefined4 *)(param_2 + 1) = uVar6;
    } while (*(char *)((longlong)puVar7 + 0x19) == '\0');
  }
  return param_2;
}

/* RVA 0x7c60 */
void FUN_180007c60(undefined8 param_1,void *param_2)

{
  void *pvVar1;
  void *pvVar2;
  
  if (0xf < *(ulonglong *)((longlong)param_2 + 0x38)) {
    pvVar1 = *(void **)((longlong)param_2 + 0x20);
    pvVar2 = pvVar1;
    if ((0xfff < *(ulonglong *)((longlong)param_2 + 0x38) + 1) &&
       (pvVar2 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(pvVar2);
  }
  *(undefined8 *)((longlong)param_2 + 0x30) = 0;
  *(undefined8 *)((longlong)param_2 + 0x38) = 0xf;
  *(undefined1 *)((longlong)param_2 + 0x20) = 0;
  FUN_180035134(param_2);
  return;
}

/* RVA 0x7cd0 */
undefined8 *
FUN_180007cd0(undefined8 *param_1,ulonglong param_2,undefined8 param_3,undefined1 param_4)

{
  ulonglong uVar1;
  size_t _Size;
  ulonglong uVar2;
  void *pvVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  void *pvVar6;
  void *_Dst;
  
  _Size = param_1[2];
  uVar5 = 0x7fffffffffffffff;
  if (0x7fffffffffffffff - _Size < param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_18001d1b0();
  }
  uVar2 = param_1[3];
  uVar4 = _Size + param_2 | 0xf;
  if ((uVar4 < 0x8000000000000000) && (uVar2 <= 0x7fffffffffffffff - (uVar2 >> 1))) {
    uVar1 = (uVar2 >> 1) + uVar2;
    uVar5 = uVar4;
    if (uVar4 < uVar1) {
      uVar5 = uVar1;
    }
    uVar1 = uVar5 + 1;
    if (0xfff < uVar1) {
      uVar4 = uVar5 + 0x28;
      if (uVar4 <= uVar1) {
                    /* WARNING: Subroutine does not return */
        FUN_18001d0c0();
      }
      goto LAB_180007d6d;
    }
    if (uVar1 == 0) {
      _Dst = (void *)0x0;
    }
    else {
      _Dst = operator_new(uVar1);
    }
  }
  else {
    uVar4 = 0x8000000000000027;
LAB_180007d6d:
    pvVar3 = operator_new(uVar4);
    if (pvVar3 == (void *)0x0) goto LAB_180007df1;
    _Dst = (void *)((longlong)pvVar3 + 0x27U & 0xffffffffffffffe0);
    *(void **)((longlong)_Dst - 8) = pvVar3;
  }
  param_1[2] = _Size + param_2;
  param_1[3] = uVar5;
  if (uVar2 < 0x10) {
    memcpy(_Dst,param_1,_Size);
    *(undefined1 *)((longlong)_Dst + _Size) = param_4;
    *(undefined1 *)((longlong)_Dst + _Size + 1) = 0;
  }
  else {
    pvVar3 = (void *)*param_1;
    memcpy(_Dst,pvVar3,_Size);
    *(undefined1 *)((longlong)_Dst + _Size) = param_4;
    *(undefined1 *)((longlong)_Dst + _Size + 1) = 0;
    pvVar6 = pvVar3;
    if ((0xfff < uVar2 + 1) &&
       (pvVar6 = *(void **)((longlong)pvVar3 + -8),
       0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)pvVar6)))) {
LAB_180007df1:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(pvVar6);
  }
  *param_1 = _Dst;
  return param_1;
}

/* RVA 0x7e40 */
undefined8 *
FUN_180007e40(undefined8 *param_1,ulonglong param_2,undefined8 param_3,void *param_4,size_t param_5)

{
  ulonglong uVar1;
  size_t _Size;
  ulonglong uVar2;
  void *_Src;
  void *pvVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  void *_Dst;
  
  _Size = param_1[2];
  uVar5 = 0x7fffffffffffffff;
  if (0x7fffffffffffffff - _Size < param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_18001d1b0();
  }
  uVar4 = _Size + param_2 | 0xf;
  uVar2 = param_1[3];
  if ((uVar4 < 0x8000000000000000) && (uVar2 <= 0x7fffffffffffffff - (uVar2 >> 1))) {
    uVar1 = (uVar2 >> 1) + uVar2;
    uVar5 = uVar4;
    if (uVar4 < uVar1) {
      uVar5 = uVar1;
    }
    uVar1 = uVar5 + 1;
    if (0xfff < uVar1) {
      uVar4 = uVar5 + 0x28;
      if (uVar4 <= uVar1) {
                    /* WARNING: Subroutine does not return */
        FUN_18001d0c0();
      }
      goto LAB_180007ede;
    }
    if (uVar1 == 0) {
      _Dst = (void *)0x0;
    }
    else {
      _Dst = operator_new(uVar1);
    }
  }
  else {
    uVar4 = 0x8000000000000027;
LAB_180007ede:
    pvVar3 = operator_new(uVar4);
    if (pvVar3 == (void *)0x0) goto LAB_180007f78;
    _Dst = (void *)((longlong)pvVar3 + 0x27U & 0xffffffffffffffe0);
    *(void **)((longlong)_Dst - 8) = pvVar3;
  }
  param_1[2] = _Size + param_2;
  pvVar3 = (void *)((longlong)_Dst + _Size);
  param_1[3] = uVar5;
  if (uVar2 < 0x10) {
    memcpy(_Dst,param_1,_Size);
    memcpy(pvVar3,param_4,param_5);
    *(undefined1 *)((longlong)pvVar3 + param_5) = 0;
  }
  else {
    _Src = (void *)*param_1;
    memcpy(_Dst,_Src,_Size);
    memcpy(pvVar3,param_4,param_5);
    *(undefined1 *)((longlong)pvVar3 + param_5) = 0;
    pvVar3 = _Src;
    if ((0xfff < uVar2 + 1) &&
       (pvVar3 = *(void **)((longlong)_Src + -8),
       0x1f < (ulonglong)((longlong)_Src + (-8 - (longlong)pvVar3)))) {
LAB_180007f78:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(pvVar3);
  }
  *param_1 = _Dst;
  return param_1;
}

/* RVA 0x7fd0 */
undefined8 *
FUN_180007fd0(undefined8 *param_1,ulonglong param_2,undefined8 param_3,longlong param_4,
             undefined2 param_5)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  void *_Src;
  size_t _Size;
  void *_Dst;
  longlong lVar4;
  ulonglong uVar5;
  void *pvVar6;
  ulonglong uVar7;
  undefined2 *puVar8;
  
  lVar2 = param_1[2];
  if (0x7ffffffffffffffeU - lVar2 < param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_18001d1b0();
  }
  uVar3 = param_1[3];
  uVar5 = lVar2 + param_2 | 7;
  uVar7 = 0x7ffffffffffffffe;
  if ((uVar5 < 0x7fffffffffffffff) && (uVar3 <= 0x7ffffffffffffffe - (uVar3 >> 1))) {
    uVar1 = (uVar3 >> 1) + uVar3;
    uVar7 = uVar5;
    if (uVar5 < uVar1) {
      uVar7 = uVar1;
    }
  }
  _Dst = FUN_18001d2e0(param_1,uVar7 + 1);
  param_1[3] = uVar7;
  _Size = lVar2 * 2;
  param_1[2] = lVar2 + param_2;
  if (uVar3 < 8) {
    memcpy(_Dst,param_1,_Size);
    if (param_4 != 0) {
      puVar8 = (undefined2 *)(_Size + (longlong)_Dst);
      for (lVar4 = param_4; lVar4 != 0; lVar4 = lVar4 + -1) {
        *puVar8 = param_5;
        puVar8 = puVar8 + 1;
      }
    }
    *(undefined2 *)((longlong)_Dst + (lVar2 + param_4) * 2) = 0;
  }
  else {
    _Src = (void *)*param_1;
    memcpy(_Dst,_Src,_Size);
    if (param_4 != 0) {
      puVar8 = (undefined2 *)(_Size + (longlong)_Dst);
      for (lVar4 = param_4; lVar4 != 0; lVar4 = lVar4 + -1) {
        *puVar8 = param_5;
        puVar8 = puVar8 + 1;
      }
    }
    *(undefined2 *)((longlong)_Dst + (lVar2 + param_4) * 2) = 0;
    pvVar6 = _Src;
    if ((0xfff < uVar3 * 2 + 2) &&
       (pvVar6 = *(void **)((longlong)_Src + -8),
       0x1f < (ulonglong)((longlong)_Src + (-8 - (longlong)pvVar6)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(pvVar6);
  }
  *param_1 = _Dst;
  return param_1;
}

/* RVA 0x8120 */
void FUN_180008120(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  longlong lVar6;
  
  if (param_1 != param_2) {
    lVar6 = (longlong)param_3 - (longlong)param_1;
    puVar5 = param_1 + 7;
    do {
      puVar1 = puVar5 + 8;
      *param_3 = 0;
      param_3[1] = 0;
      *(undefined8 *)(lVar6 + -0x68 + (longlong)puVar1) = 0;
      puVar2 = puVar5 + 1;
      *(undefined8 *)(lVar6 + -0x60 + (longlong)puVar1) = 0;
      uVar4 = puVar5[-6];
      *param_3 = puVar5[-7];
      param_3[1] = uVar4;
      uVar4 = puVar5[-4];
      param_3[2] = puVar5[-5];
      param_3[3] = uVar4;
      puVar5[-5] = 0;
      param_3 = param_3 + 8;
      puVar5[-4] = 0xf;
      *(undefined1 *)(puVar5 + -7) = 0;
      puVar3 = (undefined8 *)(lVar6 + -0x58 + (longlong)puVar1);
      *puVar3 = 0;
      puVar3[1] = 0;
      *(undefined8 *)(lVar6 + -0x48 + (longlong)puVar1) = 0;
      *(undefined8 *)((longlong)puVar5 + lVar6) = 0;
      uVar4 = puVar5[-2];
      puVar3 = (undefined8 *)(lVar6 + -0x58 + (longlong)puVar1);
      *puVar3 = puVar5[-3];
      puVar3[1] = uVar4;
      uVar4 = *puVar5;
      puVar3 = (undefined8 *)(lVar6 + -0x48 + (longlong)puVar1);
      *puVar3 = puVar5[-1];
      puVar3[1] = uVar4;
      puVar5[-1] = 0;
      *puVar5 = 0xf;
      *(undefined1 *)(puVar5 + -3) = 0;
      puVar5 = puVar1;
    } while (puVar2 != param_2);
  }
  return;
}

/* RVA 0x81c0 */
longlong * FUN_1800081c0(longlong *param_1,longlong *param_2,longlong *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  
  if (param_1 != param_2) {
    lVar3 = (longlong)param_3 - (longlong)param_1;
    plVar4 = param_1 + 3;
    do {
      *param_3 = 0;
      param_3[1] = 0;
      *(undefined8 *)(lVar3 + -0x28 + (longlong)(plVar4 + 4)) = 0;
      plVar1 = plVar4 + 1;
      *(undefined8 *)((longlong)plVar4 + lVar3) = 0;
      lVar2 = plVar4[-2];
      *param_3 = plVar4[-3];
      param_3[1] = lVar2;
      lVar2 = *plVar4;
      param_3[2] = plVar4[-1];
      param_3[3] = lVar2;
      plVar4[-1] = 0;
      param_3 = param_3 + 4;
      *plVar4 = 0xf;
      *(undefined1 *)(plVar4 + -3) = 0;
      plVar4 = plVar4 + 4;
    } while (plVar1 != param_2);
  }
  FUN_180007060(param_3,param_3);
  return param_3;
}

/* RVA 0x8240 */
longlong * FUN_180008240(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  longlong lVar1;
  code *pcVar2;
  undefined1 uVar3;
  uint uVar4;
  longlong *plVar5;
  longlong local_48;
  longlong lStack_40;
  longlong local_38 [4];
  
  plVar5 = FUN_180007ba0(param_1,local_38,param_3);
  local_48 = *plVar5;
  lStack_40 = plVar5[1];
  plVar5 = (longlong *)plVar5[2];
  if (*(char *)((longlong)plVar5 + 0x19) == '\0') {
    uVar4 = FUN_180009190(param_1,param_3,plVar5 + 4);
    uVar3 = 0;
    if ((char)uVar4 == '\0') goto LAB_180008323;
  }
  if (param_1[1] == 0x333333333333333) {
    FUN_18001d100();
    pcVar2 = (code *)swi(3);
    plVar5 = (longlong *)(*pcVar2)();
    return plVar5;
  }
  lVar1 = *param_1;
  plVar5 = operator_new(0x50);
  FUN_180008630(plVar5 + 4,param_3);
  plVar5[8] = param_3[4];
  plVar5[9] = param_3[5];
  *plVar5 = lVar1;
  plVar5[1] = lVar1;
  plVar5[2] = lVar1;
  *(undefined2 *)(plVar5 + 3) = 0;
  plVar5 = FUN_18001cd40(param_1,&local_48,plVar5);
  uVar3 = 1;
LAB_180008323:
  *param_2 = (longlong)plVar5;
  *(undefined1 *)(param_2 + 1) = uVar3;
  return param_2;
}

/* RVA 0x8350 */
_Facet_base * FUN_180008350(locale *param_1)

{
  longlong lVar1;
  __uint64 _Var2;
  _Locimp *p_Var3;
  _Facet_base *p_Var4;
  _Lockit local_res8 [8];
  _Facet_base *local_res10;
  _Facet_base *local_res18;
  
  std::_Lockit::_Lockit(local_res8,0);
  local_res10 = DAT_1800535a0;
  _Var2 = std::locale::id::operator_unsigned___int64((id *)id_exref);
  lVar1 = *(longlong *)(param_1 + 8);
  if (_Var2 < *(ulonglong *)(lVar1 + 0x18)) {
    p_Var4 = *(_Facet_base **)(_Var2 * 8 + *(longlong *)(lVar1 + 0x10));
    if (p_Var4 != (_Facet_base *)0x0) goto LAB_18000840f;
  }
  else {
    p_Var4 = (_Facet_base *)0x0;
  }
  if (*(char *)(lVar1 + 0x24) == '\0') {
LAB_1800083c5:
    if (p_Var4 != (_Facet_base *)0x0) goto LAB_18000840f;
  }
  else {
    p_Var3 = std::locale::_Getgloballocale();
    if (_Var2 < *(ulonglong *)(p_Var3 + 0x18)) {
      p_Var4 = *(_Facet_base **)(_Var2 * 8 + *(longlong *)(p_Var3 + 0x10));
      goto LAB_1800083c5;
    }
  }
  p_Var4 = local_res10;
  if (local_res10 == (_Facet_base *)0x0) {
    _Var2 = std::codecvt<char,char,_Mbstatet>::_Getcat((facet **)&local_res10,param_1);
    p_Var4 = local_res10;
    if (_Var2 == 0xffffffffffffffff) {
                    /* WARNING: Subroutine does not return */
      FUN_18001d0e0();
    }
    local_res18 = local_res10;
    std::_Facet_Register(local_res10);
    (**(code **)(*(longlong *)p_Var4 + 8))(p_Var4);
    DAT_1800535a0 = local_res10;
    p_Var4 = local_res10;
  }
LAB_18000840f:
  std::_Lockit::~_Lockit(local_res8);
  return p_Var4;
}

/* RVA 0x8430 */
basic_istream<char,std::char_traits<char>_> *
FUN_180008430(basic_istream<char,std::char_traits<char>_> *param_1,char *param_2,uint param_3,
             int param_4,int param_5)

{
  basic_streambuf<char,std::char_traits<char>_> *this;
  bool bVar1;
  _iobuf *p_Var2;
  locale *plVar3;
  _Facet_base *this_00;
  undefined8 *puVar4;
  int *local_40;
  char **local_38;
  basic_streambuf<char,std::char_traits<char>_> *local_30 [2];
  longlong *local_20;
  
  if (param_5 != 0) {
    *(undefined **)param_1 = &DAT_180041ba0;
    std::basic_ios<char,std::char_traits<char>_>::basic_ios<char,std::char_traits<char>_>
              ((basic_ios<char,std::char_traits<char>_> *)(param_1 + 0xb0));
  }
  this = (basic_streambuf<char,std::char_traits<char>_> *)(param_1 + 0x10);
  std::basic_istream<char,std::char_traits<char>_>::basic_istream<char,std::char_traits<char>_>
            (param_1,this,false);
  *(undefined ***)(param_1 + *(int *)(*(longlong *)param_1 + 4)) =
       std::basic_ifstream<char,std::char_traits<char>_>::vftable;
  *(int *)(param_1 + (longlong)*(int *)(*(longlong *)param_1 + 4) + -4) =
       *(int *)(*(longlong *)param_1 + 4) + -0xb0;
  local_30[0] = this;
  std::basic_streambuf<char,std::char_traits<char>_>::basic_streambuf<char,std::char_traits<char>_>
            (this);
  *(undefined ***)this = std::basic_filebuf<char,std::char_traits<char>_>::vftable;
  param_1[0x8c] = (basic_istream<char,std::char_traits<char>_>)0x0;
  param_1[0x81] = (basic_istream<char,std::char_traits<char>_>)0x0;
  std::basic_streambuf<char,std::char_traits<char>_>::_Init(this);
  *(undefined8 *)(param_1 + 0x90) = 0;
  *(undefined8 *)(param_1 + 0x84) = DAT_180053598;
  *(undefined8 *)(param_1 + 0x78) = 0;
  p_Var2 = std::_Fiopen(param_2,param_3 | 1,param_4);
  if (p_Var2 == (_iobuf *)0x0) {
    std::basic_ios<char,std::char_traits<char>_>::setstate
              ((basic_ios<char,std::char_traits<char>_> *)
               (param_1 + *(int *)(*(longlong *)param_1 + 4)),2,false);
  }
  else {
    param_1[0x8c] = (basic_istream<char,std::char_traits<char>_>)0x1;
    param_1[0x81] = (basic_istream<char,std::char_traits<char>_>)0x0;
    std::basic_streambuf<char,std::char_traits<char>_>::_Init(this);
    local_30[0] = (basic_streambuf<char,std::char_traits<char>_> *)0x0;
    local_38 = (char **)0x0;
    local_40 = (int *)0x0;
    _get_stream_buffer_pointers(p_Var2,local_30,&local_38,&local_40);
    std::basic_streambuf<char,std::char_traits<char>_>::_Init
              (this,(char **)local_30[0],local_38,local_40,(char **)local_30[0],local_38,local_40);
    *(_iobuf **)(param_1 + 0x90) = p_Var2;
    *(undefined8 *)(param_1 + 0x84) = DAT_180053598;
    *(undefined8 *)(param_1 + 0x78) = 0;
    plVar3 = (locale *)std::basic_streambuf<char,std::char_traits<char>_>::getloc(this);
    this_00 = FUN_180008350(plVar3);
    bVar1 = std::codecvt_base::always_noconv((codecvt_base *)this_00);
    if (bVar1) {
      *(undefined8 *)(param_1 + 0x78) = 0;
    }
    else {
      *(_Facet_base **)(param_1 + 0x78) = this_00;
      std::basic_streambuf<char,std::char_traits<char>_>::_Init(this);
    }
    if (local_20 != (longlong *)0x0) {
      puVar4 = (undefined8 *)(**(code **)(*local_20 + 0x10))();
      if (puVar4 != (undefined8 *)0x0) {
        (**(code **)*puVar4)(puVar4,1);
      }
    }
  }
  return param_1;
}

/* RVA 0x8630 */
undefined8 * FUN_180008630(undefined8 *param_1,undefined8 *param_2)

{
  ulonglong uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  void *_Dst;
  undefined8 *_Src;
  ulonglong uVar4;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  _Src = param_2;
  if (0xf < (ulonglong)param_2[3]) {
    _Src = (undefined8 *)*param_2;
  }
  uVar1 = param_2[2];
  if (0x7fffffffffffffff < uVar1) {
                    /* WARNING: Subroutine does not return */
    FUN_18001d1b0();
  }
  param_1[3] = 0xf;
  if (uVar1 < 0x10) {
    param_1[2] = uVar1;
    uVar2 = _Src[1];
    *param_1 = *_Src;
    param_1[1] = uVar2;
  }
  else {
    uVar3 = uVar1 | 0xf;
    uVar4 = 0x7fffffffffffffff;
    if ((uVar3 < 0x8000000000000000) && (uVar4 = uVar3, uVar3 < 0x16)) {
      uVar4 = 0x16;
    }
    _Dst = FUN_18001d210(param_1,uVar4 + 1);
    *param_1 = _Dst;
    param_1[2] = uVar1;
    param_1[3] = uVar4;
    memcpy(_Dst,_Src,uVar1 + 1);
  }
  return param_1;
}

/* RVA 0x8700 */
undefined8 * FUN_180008700(undefined8 *param_1,LPCSTR param_2)

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
  FUN_1800018d0(-0x7ff8fff2);
}

/* RVA 0x87d0 */
undefined8 * FUN_1800087d0(undefined8 *param_1,LPCSTR param_2)

{
  undefined8 *puVar1;
  BSTR pOVar2;
  
  puVar1 = operator_new(0x18);
  if (puVar1 == (undefined8 *)0x0) {
    puVar1 = (undefined8 *)0x0;
  }
  else {
    puVar1[1] = 0;
    *(undefined4 *)(puVar1 + 2) = 1;
    pOVar2 = FUN_180034c50(param_2);
    *puVar1 = pOVar2;
  }
  *param_1 = puVar1;
  if (puVar1 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_180034a60(0x8007000e);
  }
  return param_1;
}

/* RVA 0x8840 */
undefined8 * FUN_180008840(undefined8 *param_1,longlong param_2)

{
  *param_1 = std::exception::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  __std_exception_copy(param_2 + 8);
  *param_1 = std::bad_alloc::vftable;
  return param_1;
}

/* RVA 0x8880 */
undefined8 * FUN_180008880(undefined8 *param_1,longlong param_2)

{
  *param_1 = std::exception::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  __std_exception_copy(param_2 + 8);
  *param_1 = std::bad_array_new_length::vftable;
  return param_1;
}

/* RVA 0x88c0 */
undefined8 * FUN_1800088c0(undefined8 *param_1)

{
  param_1[2] = 0;
  param_1[1] = "bad array new length";
  *param_1 = std::bad_array_new_length::vftable;
  return param_1;
}

/* RVA 0x88f0 */
undefined8 * FUN_1800088f0(undefined8 *param_1,longlong param_2)

{
  *param_1 = std::exception::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  __std_exception_copy(param_2 + 8);
  *param_1 = std::bad_cast::vftable;
  return param_1;
}

/* RVA 0x8930 */
undefined8 * FUN_180008930(undefined8 *param_1)

{
  param_1[2] = 0;
  param_1[1] = "bad cast";
  *param_1 = std::bad_cast::vftable;
  return param_1;
}

/* RVA 0x8960 */
/* Library Function - Single Match
    public: __cdecl std::exception::exception(class std::exception const & __ptr64) __ptr64
   
   Library: Visual Studio 2019 Release */

exception * __thiscall std::exception::exception(exception *this,exception *param_1)

{
  *(undefined ***)this = vftable;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  __std_exception_copy(param_1 + 8);
  return this;
}

/* RVA 0x89c0 */
void FUN_1800089c0(longlong *param_1)

{
  if ((longlong *)*param_1 != (longlong *)0x0) {
    (**(code **)(*(longlong *)*param_1 + 0x10))();
  }
  return;
}

/* RVA 0x8a20 */
void FUN_180008a20(basic_streambuf<char,std::char_traits<char>_> *param_1)

{
  basic_streambuf<char,std::char_traits<char>_> *pbVar1;
  
  *(undefined ***)param_1 = std::basic_filebuf<char,std::char_traits<char>_>::vftable;
  if (*(longlong *)(param_1 + 0x80) != 0) {
    pbVar1 = (basic_streambuf<char,std::char_traits<char>_> *)
             std::basic_streambuf<char,std::char_traits<char>_>::eback(param_1);
    if (pbVar1 == param_1 + 0x70) {
      std::basic_streambuf<char,std::char_traits<char>_>::setg
                (param_1,*(char **)(param_1 + 0x88),*(char **)(param_1 + 0x88),
                 *(char **)(param_1 + 0x90));
    }
  }
  if (param_1[0x7c] != (basic_streambuf<char,std::char_traits<char>_>)0x0) {
    FUN_18001d4c0(param_1);
  }
                    /* WARNING: Could not recover jumptable at 0x000180008a7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<char,std::char_traits<char>_>::~basic_streambuf<char,std::char_traits<char>_>
            (param_1);
  return;
}

/* RVA 0x8a90 */
void FUN_180008a90(longlong *param_1)

{
  void *pvVar1;
  void *pvVar2;
  
  if (0xf < (ulonglong)param_1[3]) {
    pvVar1 = (void *)*param_1;
    pvVar2 = pvVar1;
    if ((0xfff < param_1[3] + 1U) &&
       (pvVar2 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(pvVar2);
  }
  param_1[2] = 0;
  param_1[3] = 0xf;
  *(undefined1 *)param_1 = 0;
  return;
}

/* RVA 0x8b00 */
void FUN_180008b00(longlong *param_1)

{
  void *pvVar1;
  void *pvVar2;
  
  if (0xf < (ulonglong)param_1[7]) {
    pvVar1 = (void *)param_1[4];
    pvVar2 = pvVar1;
    if ((0xfff < param_1[7] + 1U) &&
       (pvVar2 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) goto LAB_180008ba3;
    FUN_180035134(pvVar2);
  }
  param_1[6] = 0;
  param_1[7] = 0xf;
  *(undefined1 *)(param_1 + 4) = 0;
  if (0xf < (ulonglong)param_1[3]) {
    pvVar1 = (void *)*param_1;
    pvVar2 = pvVar1;
    if ((0xfff < param_1[3] + 1U) &&
       (pvVar2 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) {
LAB_180008ba3:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(pvVar2);
  }
  param_1[2] = 0;
  param_1[3] = 0xf;
  *(undefined1 *)param_1 = 0;
  return;
}

/* RVA 0x8bd0 */
void FUN_180008bd0(longlong *param_1)

{
  longlong *plVar1;
  void *pvVar2;
  void *pvVar3;
  longlong *plVar4;
  
  plVar4 = (longlong *)*param_1;
  if (plVar4 != (longlong *)0x0) {
    plVar1 = (longlong *)param_1[1];
    for (; plVar4 != plVar1; plVar4 = plVar4 + 8) {
      FUN_180008b00(plVar4);
    }
    pvVar2 = (void *)*param_1;
    pvVar3 = pvVar2;
    if ((0xfff < (param_1[2] - (longlong)pvVar2 & 0xffffffffffffffc0U)) &&
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

/* RVA 0x8c60 */
void FUN_180008c60(longlong *param_1)

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
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}

/* RVA 0x8cd0 */
void FUN_180008cd0(undefined8 *param_1)

{
  void *pvVar1;
  void *pvVar2;
  
  *param_1 = CApwnLWDocument::vftable;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x1e));
  FUN_180007ae0(param_1 + 0x1c,param_1 + 0x1c,*(longlong **)(param_1[0x1c] + 8));
  FUN_180035134((void *)param_1[0x1c]);
  FUN_180007ae0(param_1 + 0x1a,param_1 + 0x1a,*(longlong **)(param_1[0x1a] + 8));
  FUN_180035134((void *)param_1[0x1a]);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x14));
  if (0xf < (ulonglong)param_1[0x13]) {
    pvVar1 = (void *)param_1[0x10];
    pvVar2 = pvVar1;
    if ((0xfff < param_1[0x13] + 1) &&
       (pvVar2 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) goto LAB_180008eb0;
    FUN_180035134(pvVar2);
  }
  param_1[0x12] = 0;
  param_1[0x13] = 0xf;
  *(undefined1 *)(param_1 + 0x10) = 0;
  if (0xf < (ulonglong)param_1[0xf]) {
    pvVar1 = (void *)param_1[0xc];
    pvVar2 = pvVar1;
    if ((0xfff < param_1[0xf] + 1) &&
       (pvVar2 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) goto LAB_180008eb0;
    FUN_180035134(pvVar2);
  }
  param_1[0xe] = 0;
  param_1[0xf] = 0xf;
  *(undefined1 *)(param_1 + 0xc) = 0;
  if (0xf < (ulonglong)param_1[0xb]) {
    pvVar1 = (void *)param_1[8];
    pvVar2 = pvVar1;
    if ((0xfff < param_1[0xb] + 1) &&
       (pvVar2 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) {
LAB_180008eb0:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(pvVar2);
  }
  param_1[10] = 0;
  param_1[0xb] = 0xf;
  *(undefined1 *)(param_1 + 8) = 0;
  if ((longlong *)param_1[7] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[7] + 0x10))();
  }
  if ((longlong *)param_1[6] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[6] + 0x10))();
  }
  if ((longlong *)param_1[5] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[5] + 0x10))();
  }
  if ((longlong *)param_1[4] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[4] + 0x10))();
  }
  if ((longlong *)param_1[3] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[3] + 0x10))();
  }
  if ((longlong *)param_1[1] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[1] + 0x10))();
  }
  return;
}

/* RVA 0x8ee0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180008ee0(void)

{
  AFX_MODULE_STATE *pAVar1;
  undefined1 auStack_258 [576];
  ulonglong local_18;
  
  local_18 = DAT_180052888 ^ (ulonglong)auStack_258;
  pAVar1 = AfxGetModuleState();
  CCmdTarget::EndWaitCursor(*(CCmdTarget **)(pAVar1 + 8));
  return;
}

/* RVA 0x8f40 */
void thunk_FUN_18001ccd0(undefined8 *param_1)

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

/* RVA 0x8f50 */
void FUN_180008f50(longlong param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(param_1 + 8);
  FUN_180007a60(puVar1,puVar1,*(longlong **)(*(longlong *)(param_1 + 8) + 8));
  FUN_180035134((void *)*puVar1);
  return;
}

/* RVA 0x8fa0 */
void FUN_180008fa0(longlong param_1)

{
  undefined8 *puVar1;
  
  if (*(longlong **)(param_1 + 8) != (longlong *)0x0) {
    puVar1 = (undefined8 *)(**(code **)(**(longlong **)(param_1 + 8) + 0x10))();
    if (puVar1 != (undefined8 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000180008fc7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)*puVar1)(puVar1,1);
      return;
    }
  }
  return;
}

/* RVA 0x8fd0 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

VARIANTARG * FUN_180008fd0(VARIANTARG *param_1,LPCSTR param_2)

{
  HRESULT HVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined8 *_Memory;
  BSTR pOVar6;
  undefined8 *puVar7;
  undefined1 *puVar8;
  ulonglong uVar9;
  OLECHAR *pOVar10;
  OLECHAR *psz;
  undefined1 auStack_58 [48];
  undefined8 *local_28;
  ulonglong local_20;
  
  local_20 = DAT_180052888 ^ (ulonglong)&local_28;
  psz = (OLECHAR *)0x0;
  puVar7 = (undefined8 *)0x0;
  local_28 = (undefined8 *)0x0;
  HVar1 = VariantClear(param_1);
  if (HVar1 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_1800018d0(HVar1);
  }
  (param_1->n1).n2.vt = 8;
  _Memory = puVar7;
  puVar8 = auStack_58;
  if (param_2 != (LPCSTR)0x0) {
    lVar3 = -1;
    do {
      lVar3 = lVar3 + 1;
    } while (param_2[lVar3] != '\0');
    lVar3 = (longlong)((int)lVar3 + 1) * 2;
    puVar8 = auStack_58;
    if (lVar3 + 0x80000000U < 0x100000000) {
      iVar2 = (int)lVar3;
      uVar9 = (ulonglong)iVar2;
      if ((iVar2 < 0x401) && (uVar4 = FUN_180006b40(uVar9), (char)uVar4 != '\0')) {
        uVar5 = uVar9 + 0xf;
        if (uVar5 <= uVar9) {
          uVar5 = 0xffffffffffffff0;
        }
        pOVar10 = (OLECHAR *)(auStack_58 + -(uVar5 & 0xfffffffffffffff0) + 0x30);
        puVar8 = auStack_58 + -(uVar5 & 0xfffffffffffffff0);
      }
      else {
        if (~uVar9 < 0x10) {
                    /* WARNING: Subroutine does not return */
          FUN_1800018d0(-0x7ff8fdea);
        }
        _Memory = malloc(uVar9 + 0x10);
        puVar8 = auStack_58;
        if (_Memory == (undefined8 *)0x0) {
          pOVar10 = (OLECHAR *)0x0;
          _Memory = puVar7;
          puVar8 = auStack_58;
        }
        else {
          *_Memory = 0;
          local_28 = _Memory;
          pOVar10 = (OLECHAR *)(_Memory + 2);
        }
      }
      if (pOVar10 != (OLECHAR *)0x0) {
        *pOVar10 = L'\0';
        *(int *)(puVar8 + 0x28) = (int)(uVar9 >> 1);
        *(OLECHAR **)(puVar8 + 0x20) = pOVar10;
        *(undefined8 *)(puVar8 + -8) = 0x1800090f0;
        iVar2 = MultiByteToWideChar(0,0,param_2,-1,*(LPWSTR *)(puVar8 + 0x20),
                                    *(int *)(puVar8 + 0x28));
        psz = pOVar10;
        if (iVar2 == 0) {
          psz = (OLECHAR *)0x0;
        }
      }
    }
  }
  *(undefined8 *)(puVar8 + -8) = 0x180009102;
  pOVar6 = SysAllocString(psz);
  (param_1->n1).decVal.u2.Lo64 = (ULONGLONG)pOVar6;
  if ((pOVar6 == (BSTR)0x0) && (param_2 != (LPCSTR)0x0)) {
    (param_1->n1).n2.vt = 10;
    (param_1->n1).n2.n3.lVal = -0x7ff8fff2;
                    /* WARNING: Subroutine does not return */
    *(undefined **)(puVar8 + -8) = &UNK_180009185;
    FUN_1800018d0(-0x7ff8fff2);
  }
  while (_Memory != (undefined8 *)0x0) {
    puVar7 = (undefined8 *)*_Memory;
    *(undefined8 *)(puVar8 + -8) = 0x18000912c;
    free(_Memory);
    _Memory = puVar7;
  }
  *(undefined8 *)(puVar8 + -8) = 0x180009140;
  return param_1;
}

/* RVA 0x9190 */
uint FUN_180009190(undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  uint uVar3;
  undefined8 *_Buf2;
  undefined8 *_Buf1;
  ulonglong _Size;
  
  _Buf2 = param_3;
  if (0xf < (ulonglong)param_3[3]) {
    _Buf2 = (undefined8 *)*param_3;
  }
  _Buf1 = param_2;
  if (0xf < (ulonglong)param_2[3]) {
    _Buf1 = (undefined8 *)*param_2;
  }
  uVar1 = param_3[2];
  uVar2 = param_2[2];
  _Size = uVar2;
  if (uVar1 < uVar2) {
    _Size = uVar1;
  }
  uVar3 = memcmp(_Buf1,_Buf2,_Size);
  if (uVar3 == 0) {
    if (uVar2 < uVar1) {
      return 1;
    }
    uVar3 = 0;
  }
  return uVar3 >> 0x1f;
}

/* RVA 0x9200 */
void FUN_180009200(longlong *param_1)

{
  basic_ios<char,std::char_traits<char>_> *this;
  
  this = (basic_ios<char,std::char_traits<char>_> *)(param_1 + 0x16);
  *(undefined ***)(this + (longlong)*(int *)(*param_1 + 4) + -0xb0) =
       std::basic_ifstream<char,std::char_traits<char>_>::vftable;
  *(int *)(this + (longlong)*(int *)(*param_1 + 4) + -0xb4) = *(int *)(*param_1 + 4) + -0xb0;
  FUN_180008a20((basic_streambuf<char,std::char_traits<char>_> *)(param_1 + 2));
  std::basic_istream<char,std::char_traits<char>_>::~basic_istream<char,std::char_traits<char>_>
            ((basic_istream<char,std::char_traits<char>_> *)(param_1 + 3));
                    /* WARNING: Could not recover jumptable at 0x00018000925a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>(this);
  return;
}

/* RVA 0x9264 */
void FUN_180009264(longlong param_1,uint param_2)

{
  FUN_1800092b0(param_1 - *(int *)(param_1 + -4),param_2);
  return;
}

/* RVA 0x9270 */
basic_streambuf<char,std::char_traits<char>_> *
FUN_180009270(basic_streambuf<char,std::char_traits<char>_> *param_1,uint param_2)

{
  FUN_180008a20(param_1);
  if ((param_2 & 1) != 0) {
    FUN_180035134(param_1);
  }
  return param_1;
}

/* RVA 0x92b0 */
longlong * FUN_1800092b0(longlong param_1,uint param_2)

{
  longlong *plVar1;
  
  plVar1 = (longlong *)(param_1 + -0xb0);
  FUN_180009200(plVar1);
  if ((param_2 & 1) != 0) {
    FUN_180035134(plVar1);
  }
  return plVar1;
}

/* RVA 0x92f0 */
undefined8 * FUN_1800092f0(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = std::exception::vftable;
  __std_exception_destroy(param_1 + 1);
  if ((param_2 & 1) != 0) {
    FUN_180035134(param_1);
  }
  return param_1;
}

/* RVA 0x9340 */
void FUN_180009340(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1800018d0(DVar1);
}

/* RVA 0x9360 */
undefined4 FUN_180009360(longlong param_1)

{
  char *pcVar1;
  undefined4 extraout_EAX;
  longlong *plVar2;
  LPCSTR local_res8 [4];
  
  pcVar1 = (char *)GRemrbkpfull();
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res8,pcVar1);
  DeleteFileA(local_res8[0]);
  plVar2 = (longlong *)(param_1 + 0x60);
  if (0xf < *(ulonglong *)(param_1 + 0x78)) {
    plVar2 = (longlong *)*plVar2;
  }
  GRDeleteEmergencyFiles(plVar2,local_res8[0]);
  FUN_18000bfd0(param_1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res8);
  return CONCAT31((int3)((uint)extraout_EAX >> 8),1);
}

/* RVA 0x93c0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1800093c0(longlong param_1,BSTR param_2)

{
  char cVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  UINT UVar4;
  uint uVar5;
  longlong *plVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined8 ****ppppuVar10;
  undefined8 ****ppppuVar11;
  undefined8 *puVar12;
  size_t sVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  undefined1 auStack_148 [32];
  longlong *local_128;
  undefined8 *local_118;
  longlong lStack_110;
  longlong local_108 [2];
  undefined8 ****local_f8;
  undefined8 uStack_f0;
  ulonglong local_e8;
  ulonglong local_e0;
  undefined1 *local_d8;
  undefined1 local_d0 [136];
  ulonglong local_48;
  
  local_48 = DAT_180052888 ^ (ulonglong)auStack_148;
  uStack_f0 = 0;
  local_e8 = 0;
  uVar15 = 0xf;
  local_e0 = 0xf;
  local_f8 = (undefined8 ****)0x0;
  if ((param_2 == (BSTR)0x0) || (UVar4 = SysStringLen(param_2), UVar4 == 0)) {
    local_e8 = 4;
    local_f8 = (undefined8 ****)CONCAT35(local_f8._5_3_,0x746f6f52);
  }
  else {
    local_d8 = local_d0;
    FUN_18000d880(&local_d8,param_2,0);
    sVar13 = 0xffffffffffffffff;
    do {
      sVar13 = sVar13 + 1;
    } while (local_d8[sVar13] != '\0');
    FUN_18001d350((longlong *)&local_f8,local_d8,sVar13);
    if (local_d8 != local_d0) {
      free(local_d8);
    }
    uVar15 = local_e0;
  }
  uVar3 = local_e8;
  ppppuVar11 = local_f8;
  local_128 = (longlong *)(param_1 + 0xe0);
  puVar7 = (undefined8 *)*local_128;
  puVar9 = (undefined8 *)puVar7[1];
  puVar12 = puVar7;
  local_118 = puVar7;
  if (*(char *)((longlong)puVar9 + 0x19) == '\0') {
    do {
      ppppuVar10 = &local_f8;
      if (0xf < uVar15) {
        ppppuVar10 = ppppuVar11;
      }
      puVar8 = puVar9 + 4;
      if (0xf < (ulonglong)puVar9[7]) {
        puVar8 = (undefined8 *)puVar9[4];
      }
      uVar2 = puVar9[6];
      uVar14 = uVar2;
      if (uVar3 < uVar2) {
        uVar14 = uVar3;
      }
      uVar5 = memcmp(puVar8,ppppuVar10,uVar14);
      if (uVar5 == 0) {
        if (uVar2 < uVar3) {
          uVar5 = 0xffffffff;
        }
        else {
          uVar5 = (uint)(uVar3 < uVar2);
        }
      }
      if ((int)uVar5 < 0) {
        puVar8 = (undefined8 *)puVar9[2];
      }
      else {
        puVar8 = (undefined8 *)*puVar9;
        puVar12 = puVar9;
      }
      puVar9 = puVar8;
    } while (*(char *)((longlong)puVar8 + 0x19) == '\0');
    puVar9 = (undefined8 *)puVar7[1];
  }
  ppppuVar11 = local_f8;
  if (*(char *)((longlong)puVar12 + 0x19) != '\0') goto LAB_180009947;
  puVar8 = puVar12 + 4;
  if (0xf < (ulonglong)puVar12[7]) {
    puVar8 = (undefined8 *)puVar12[4];
  }
  ppppuVar10 = &local_f8;
  if (0xf < uVar15) {
    ppppuVar10 = local_f8;
  }
  uVar2 = puVar12[6];
  uVar14 = uVar3;
  if (uVar2 < uVar3) {
    uVar14 = uVar2;
  }
  uVar5 = memcmp(ppppuVar10,puVar8,uVar14);
  ppppuVar10 = local_f8;
  if (uVar5 == 0) {
    if (uVar3 < uVar2) {
      uVar5 = 0xffffffff;
    }
    else {
      uVar5 = (uint)(uVar2 < uVar3);
    }
  }
  if (((int)uVar5 < 0) || (puVar12 == puVar7)) goto LAB_180009947;
  puVar12 = puVar7;
  if (*(char *)((longlong)puVar9 + 0x19) == (char)-(char)((int)uVar5 >> 0x1f)) {
    puVar12 = puVar9;
    do {
      ppppuVar11 = &local_f8;
      if (0xf < uVar15) {
        ppppuVar11 = ppppuVar10;
      }
      puVar8 = puVar12 + 4;
      if (0xf < (ulonglong)puVar12[7]) {
        puVar8 = (undefined8 *)puVar12[4];
      }
      uVar2 = puVar12[6];
      uVar14 = uVar2;
      if (uVar3 < uVar2) {
        uVar14 = uVar3;
      }
      uVar5 = memcmp(puVar8,ppppuVar11,uVar14);
      if (uVar5 == 0) {
        if (uVar2 < uVar3) {
          uVar5 = 0xffffffff;
        }
        else {
          uVar5 = (uint)(uVar3 < uVar2);
        }
      }
      if ((int)uVar5 < 0) {
        puVar8 = (undefined8 *)puVar12[2];
      }
      else {
        puVar8 = (undefined8 *)*puVar12;
        puVar7 = puVar12;
      }
      puVar12 = puVar8;
    } while (*(char *)((longlong)puVar8 + 0x19) == '\0');
    puVar12 = local_118;
    ppppuVar11 = local_f8;
  }
  if (*(char *)((longlong)puVar7 + 0x19) == '\0') {
    puVar8 = puVar7 + 4;
    if (0xf < (ulonglong)puVar7[7]) {
      puVar8 = (undefined8 *)puVar7[4];
    }
    ppppuVar10 = &local_f8;
    if (0xf < uVar15) {
      ppppuVar10 = ppppuVar11;
    }
    uVar2 = puVar7[6];
    uVar14 = uVar3;
    if (uVar2 < uVar3) {
      uVar14 = uVar2;
    }
    uVar5 = memcmp(ppppuVar10,puVar8,uVar14);
    if (uVar5 == 0) {
      if (uVar3 < uVar2) {
        uVar5 = 0xffffffff;
      }
      else {
        uVar5 = (uint)(uVar2 < uVar3);
      }
    }
    if ((int)uVar5 < 0) goto LAB_18000966f;
  }
  else {
LAB_18000966f:
    puVar7 = puVar12;
  }
  ppppuVar10 = local_f8;
  if (puVar7[9] != 0) {
    puVar7 = puVar12;
    if (*(char *)((longlong)puVar9 + 0x19) == '\0') {
      do {
        ppppuVar11 = &local_f8;
        if (0xf < uVar15) {
          ppppuVar11 = ppppuVar10;
        }
        puVar7 = puVar9 + 4;
        if (0xf < (ulonglong)puVar9[7]) {
          puVar7 = (undefined8 *)puVar9[4];
        }
        uVar2 = puVar9[6];
        uVar14 = uVar2;
        if (uVar3 < uVar2) {
          uVar14 = uVar3;
        }
        uVar5 = memcmp(puVar7,ppppuVar11,uVar14);
        if (uVar5 == 0) {
          if (uVar2 < uVar3) {
            uVar5 = 0xffffffff;
          }
          else {
            uVar5 = (uint)(uVar3 < uVar2);
          }
        }
        if ((int)uVar5 < 0) {
          puVar7 = (undefined8 *)puVar9[2];
        }
        else {
          puVar7 = (undefined8 *)*puVar9;
          puVar12 = puVar9;
        }
        puVar9 = puVar7;
      } while (*(char *)((longlong)puVar7 + 0x19) == '\0');
      puVar7 = local_118;
      ppppuVar11 = local_f8;
    }
    if (*(char *)((longlong)puVar12 + 0x19) == '\0') {
      puVar9 = puVar12 + 4;
      if (0xf < (ulonglong)puVar12[7]) {
        puVar9 = (undefined8 *)puVar12[4];
      }
      ppppuVar10 = &local_f8;
      if (0xf < uVar15) {
        ppppuVar10 = ppppuVar11;
      }
      uVar2 = puVar12[6];
      uVar14 = uVar3;
      if (uVar2 < uVar3) {
        uVar14 = uVar2;
      }
      uVar5 = memcmp(ppppuVar10,puVar9,uVar14);
      if (uVar5 == 0) {
        if (uVar3 < uVar2) {
          uVar5 = 0xffffffff;
        }
        else {
          uVar5 = (uint)(uVar2 < uVar3);
        }
      }
      if ((int)uVar5 < 0) goto LAB_180009750;
    }
    else {
LAB_180009750:
      puVar12 = puVar7;
    }
    (**(code **)(*(longlong *)puVar12[9] + 0x10))();
  }
  ppppuVar11 = local_f8;
  puVar7 = (undefined8 *)*local_128;
  puVar9 = (undefined8 *)puVar7[1];
  local_118 = puVar7;
  if (*(char *)((longlong)puVar9 + 0x19) == '\0') {
    puVar12 = puVar9;
    do {
      ppppuVar10 = &local_f8;
      if (0xf < uVar15) {
        ppppuVar10 = ppppuVar11;
      }
      puVar8 = puVar12 + 4;
      if (0xf < (ulonglong)puVar12[7]) {
        puVar8 = (undefined8 *)puVar12[4];
      }
      uVar2 = puVar12[6];
      uVar14 = uVar2;
      if (uVar3 < uVar2) {
        uVar14 = uVar3;
      }
      uVar5 = memcmp(puVar8,ppppuVar10,uVar14);
      if (uVar5 == 0) {
        if (uVar2 < uVar3) {
          uVar5 = 0xffffffff;
        }
        else {
          uVar5 = (uint)(uVar3 < uVar2);
        }
      }
      if ((int)uVar5 < 0) {
        puVar8 = (undefined8 *)puVar12[2];
      }
      else {
        puVar8 = (undefined8 *)*puVar12;
        puVar7 = puVar12;
      }
      puVar12 = puVar8;
    } while (*(char *)((longlong)puVar8 + 0x19) == '\0');
  }
  puVar12 = local_118;
  if (*(char *)((longlong)puVar7 + 0x19) == '\0') {
    puVar8 = puVar7 + 4;
    if (0xf < (ulonglong)puVar7[7]) {
      puVar8 = (undefined8 *)puVar7[4];
    }
    ppppuVar10 = &local_f8;
    if (0xf < uVar15) {
      ppppuVar10 = ppppuVar11;
    }
    uVar2 = puVar7[6];
    uVar14 = uVar3;
    if (uVar2 < uVar3) {
      uVar14 = uVar2;
    }
    uVar5 = memcmp(ppppuVar10,puVar8,uVar14);
    if (uVar5 == 0) {
      if (uVar3 < uVar2) {
        uVar5 = 0xffffffff;
      }
      else {
        uVar5 = (uint)(uVar2 < uVar3);
      }
    }
    if ((int)uVar5 < 0) goto LAB_18000983a;
  }
  else {
LAB_18000983a:
    puVar7 = puVar12;
  }
  if (puVar7[8] != 0) {
    cVar1 = *(char *)((longlong)puVar9 + 0x19);
    while (puVar7 = puVar9, cVar1 == '\0') {
      ppppuVar10 = &local_f8;
      if (0xf < uVar15) {
        ppppuVar10 = ppppuVar11;
      }
      puVar9 = puVar7 + 4;
      if (0xf < (ulonglong)puVar7[7]) {
        puVar9 = (undefined8 *)puVar7[4];
      }
      uVar2 = puVar7[6];
      uVar14 = uVar2;
      if (uVar3 < uVar2) {
        uVar14 = uVar3;
      }
      uVar5 = memcmp(puVar9,ppppuVar10,uVar14);
      if (uVar5 == 0) {
        if (uVar2 < uVar3) {
          uVar5 = 0xffffffff;
        }
        else {
          uVar5 = (uint)(uVar3 < uVar2);
        }
      }
      if ((int)uVar5 < 0) {
        puVar9 = (undefined8 *)puVar7[2];
        puVar7 = puVar12;
      }
      else {
        puVar9 = (undefined8 *)*puVar7;
      }
      cVar1 = *(char *)((longlong)puVar9 + 0x19);
      puVar12 = puVar7;
    }
    if (*(char *)((longlong)puVar12 + 0x19) == '\0') {
      puVar7 = puVar12 + 4;
      if (0xf < (ulonglong)puVar12[7]) {
        puVar7 = (undefined8 *)puVar12[4];
      }
      ppppuVar10 = &local_f8;
      if (0xf < uVar15) {
        ppppuVar10 = ppppuVar11;
      }
      uVar2 = puVar12[6];
      uVar14 = uVar3;
      if (uVar2 < uVar3) {
        uVar14 = uVar2;
      }
      uVar5 = memcmp(ppppuVar10,puVar7,uVar14);
      if (uVar5 == 0) {
        if (uVar3 < uVar2) {
          uVar5 = 0xffffffff;
        }
        else {
          uVar5 = (uint)(uVar2 < uVar3);
        }
      }
      if ((int)uVar5 < 0) goto LAB_180009905;
    }
    else {
LAB_180009905:
      puVar12 = (undefined8 *)*local_128;
    }
    (**(code **)(*(longlong *)puVar12[8] + 0x10))();
  }
  plVar6 = FUN_1800078e0(local_128,local_108,&local_f8);
  local_118 = (undefined8 *)*plVar6;
  lStack_110 = plVar6[1];
  FUN_18001c760(local_128,(longlong *)&local_118);
  ppppuVar11 = local_f8;
LAB_180009947:
  if (0xf < uVar15) {
    ppppuVar10 = ppppuVar11;
    if ((0xfff < uVar15 + 1) &&
       (ppppuVar10 = (undefined8 ****)ppppuVar11[-1],
       0x1f < (ulonglong)((longlong)ppppuVar11 + (-8 - (longlong)ppppuVar10)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(ppppuVar10);
  }
  return;
}

/* RVA 0x99b0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1800099b0(undefined8 param_1,
                  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2)

{
  int iVar1;
  BOOL BVar2;
  undefined8 *puVar3;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar4;
  HANDLE hFindFile;
  longlong lVar5;
  IcarusInfoHelper *this;
  undefined1 auStack_2a8 [32];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_288 [8];
  LPCSTR local_280;
  LPCSTR local_278;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_270;
  _WIN32_FIND_DATAA local_268;
  char local_128 [260];
  undefined1 local_24;
  ulonglong local_18;
  
  local_18 = DAT_180052888 ^ (ulonglong)auStack_2a8;
  local_270 = param_2;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind(param_2,'.');
  puVar3 = (undefined8 *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                     (param_2,(int)local_288);
  strncpy(local_128,(char *)*puVar3,0x104);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_288);
  strncat(local_128,"Cost",0x104);
  local_24 = 0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind(param_2,'\\');
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left(param_2,(int)&local_278);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_278,"*");
  pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                     (param_2,(int)local_288);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_2,pCVar4);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_288);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind(param_2,'.');
  pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                     (param_2,(int)local_288);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_2,pCVar4);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_288);
  hFindFile = FindFirstFileA(local_278,&local_268);
  if (hFindFile != (HANDLE)0xffffffffffffffff) {
    while( true ) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_280,
                 local_268.cFileName);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_280,'.');
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_280,
                 (int)local_288);
      iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                        (local_288,*(char **)param_2);
      if (iVar1 == 0) {
        DeleteFileA(local_280);
      }
      BVar2 = FindNextFileA(hFindFile,&local_268);
      if (BVar2 == 0) break;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_288);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_280);
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_288);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_280);
  }
  FindClose(hFindFile);
  lVar5 = GetpIcarusInfoHelper();
  if (lVar5 != 0) {
    this = (IcarusInfoHelper *)GetpIcarusInfoHelper();
    IcarusInfoHelper::ReleaseProjectLock(this);
    GRRemoveCostDir(local_128,1);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_278);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_2);
  return;
}

/* RVA 0x9bf0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_180009bf0(longlong param_1,int param_2,int param_3,char *param_4,CSimpleStringT<char,1> *param_5
             )

{
  int iVar1;
  int iVar2;
  BOOL BVar3;
  FILE *_File;
  char *pcVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong *plVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  int *piVar11;
  undefined8 uVar12;
  CHAR *pCVar13;
  undefined8 uVar14;
  char *pcVar15;
  char *pcVar16;
  undefined1 auStackY_858 [32];
  undefined8 *local_800;
  undefined8 *local_7f8;
  undefined8 *local_7f0;
  undefined8 *local_7e8;
  undefined8 *local_7e0;
  undefined8 *local_7d8;
  longlong local_7d0;
  undefined8 *local_7c8;
  undefined8 *local_7c0;
  char local_7b8 [272];
  CHAR local_6a8 [272];
  char local_598 [272];
  CHAR local_488 [272];
  CHAR local_378 [272];
  undefined1 local_268 [272];
  char local_158 [272];
  ulonglong local_48;
  
  local_48 = DAT_180052888 ^ (ulonglong)auStackY_858;
  if (*(int *)(param_1 + 0xc4) == 0) {
    *(undefined4 *)(param_1 + 0xc4) = 1;
    local_7d0 = param_1;
    GRSetEmerBkpDlgOption(0);
    pcVar16 = "";
    pcVar15 = "";
    piVar11 = (int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8)
                     + 4);
    if ((*piVar11 < DAT_180053558) && (FUN_180035090(&DAT_180053558), DAT_180053558 == -1)) {
      DAT_180053550 = (LPCSTR)GetSorResStringEx(0x569);
      _Init_thread_footer(&DAT_180053558);
    }
    if ((*piVar11 < DAT_180053568) && (FUN_180035090(&DAT_180053568), DAT_180053568 == -1)) {
      DAT_180053560 = (LPCSTR)GetSorResStringEx(0xa408);
      _Init_thread_footer(&DAT_180053568);
    }
    if ((*piVar11 < DAT_180053578) && (FUN_180035090(&DAT_180053578), DAT_180053578 == -1)) {
      DAT_180053570 = (LPCSTR)GetSorResStringEx(0xa409);
      _Init_thread_footer(&DAT_180053578);
    }
    ATL::CSimpleStringT<char,1>::Empty(param_5);
    local_598[0] = '\0';
    if (param_3 == 0) {
      iVar2 = _access(param_4,0);
      if (iVar2 != 0) {
        _File = fopen(param_4,"a");
        if (_File == (FILE *)0x0) {
          return 0;
        }
        fclose(_File);
      }
      strncpy(local_598,param_4,0x104);
      pcVar16 = strrchr(local_598,0x2e);
      if (pcVar16 == (char *)0x0) {
        local_598[0] = '\0';
      }
      else {
        *pcVar16 = '\0';
      }
      pcVar15 = strrchr(local_598,0x5c);
      if (pcVar15 == (char *)0x0) {
        pcVar16 = local_598;
        pcVar15 = (char *)0x0;
      }
      else {
        pcVar16 = pcVar15 + 1;
        *pcVar15 = '\0';
        pcVar15 = local_598;
      }
    }
    iVar2 = FUN_180033bd0();
    if (iVar2 == 1) {
      GRbldemrbkp(pcVar15,pcVar16,&DAT_180041654,local_7b8);
      iVar2 = _access(local_7b8,0);
      if (iVar2 == 0) {
        pCVar13 = local_488;
        GRbldemrbkp(pcVar15,pcVar16,&DAT_180041658);
        FUN_180001ce0(local_488,"%s$backup.ap$",local_598,pCVar13);
        pcVar4 = (char *)GRemrcostdir(pcVar15,pcVar16);
        strncpy(local_158,pcVar4,0x104);
        if (param_2 == 0) {
          plVar5 = FUN_1800087d0(&local_7c8,DAT_180053570);
          plVar6 = FUN_1800087d0(&local_7f0,DAT_180053560);
          plVar7 = FUN_1800087d0(&local_7f8,DAT_180053550);
          pcVar4 = FUN_180033be0();
          plVar8 = FUN_1800087d0(&local_800,pcVar4);
          uVar14 = 0;
          if ((undefined8 *)*plVar5 != (undefined8 *)0x0) {
            uVar14 = *(undefined8 *)*plVar5;
          }
          if ((undefined8 *)*plVar6 == (undefined8 *)0x0) {
            uVar12 = 0;
          }
          else {
            uVar12 = *(undefined8 *)*plVar6;
          }
          if ((undefined8 *)*plVar7 == (undefined8 *)0x0) {
            uVar10 = 0;
          }
          else {
            uVar10 = *(undefined8 *)*plVar7;
          }
          if ((undefined8 *)*plVar8 == (undefined8 *)0x0) {
            uVar9 = 0;
          }
          else {
            uVar9 = *(undefined8 *)*plVar8;
          }
          iVar2 = FUN_180010cc0(uVar9,uVar10,uVar12,uVar14,0,0,0,2,0xffffffff);
          if (local_800 != (undefined8 *)0x0) {
            LOCK();
            piVar11 = (int *)(local_800 + 2);
            iVar1 = *piVar11;
            *piVar11 = *piVar11 + -1;
            UNLOCK();
            if ((iVar1 == 1) && (local_800 != (undefined8 *)0x0)) {
              if ((BSTR)*local_800 != (BSTR)0x0) {
                SysFreeString((BSTR)*local_800);
                *local_800 = 0;
              }
              if ((void *)local_800[1] != (void *)0x0) {
                operator_delete__((void *)local_800[1]);
                local_800[1] = 0;
              }
              FUN_180035134(local_800);
            }
            local_800 = (undefined8 *)0x0;
          }
          if (local_7f8 != (undefined8 *)0x0) {
            LOCK();
            piVar11 = (int *)(local_7f8 + 2);
            iVar1 = *piVar11;
            *piVar11 = *piVar11 + -1;
            UNLOCK();
            if ((iVar1 == 1) && (local_7f8 != (undefined8 *)0x0)) {
              if ((BSTR)*local_7f8 != (BSTR)0x0) {
                SysFreeString((BSTR)*local_7f8);
                *local_7f8 = 0;
              }
              if ((void *)local_7f8[1] != (void *)0x0) {
                operator_delete__((void *)local_7f8[1]);
                local_7f8[1] = 0;
              }
              FUN_180035134(local_7f8);
            }
            local_7f8 = (undefined8 *)0x0;
          }
          if (local_7f0 != (undefined8 *)0x0) {
            LOCK();
            piVar11 = (int *)(local_7f0 + 2);
            iVar1 = *piVar11;
            *piVar11 = *piVar11 + -1;
            UNLOCK();
            if ((iVar1 == 1) && (local_7f0 != (undefined8 *)0x0)) {
              if ((BSTR)*local_7f0 != (BSTR)0x0) {
                SysFreeString((BSTR)*local_7f0);
                *local_7f0 = 0;
              }
              if ((void *)local_7f0[1] != (void *)0x0) {
                operator_delete__((void *)local_7f0[1]);
                local_7f0[1] = 0;
              }
              FUN_180035134(local_7f0);
            }
            local_7f0 = (undefined8 *)0x0;
          }
          if (local_7c8 != (undefined8 *)0x0) {
            LOCK();
            piVar11 = (int *)(local_7c8 + 2);
            iVar1 = *piVar11;
            *piVar11 = *piVar11 + -1;
            UNLOCK();
            if ((iVar1 == 1) && (local_7c8 != (undefined8 *)0x0)) {
              if ((BSTR)*local_7c8 != (BSTR)0x0) {
                SysFreeString((BSTR)*local_7c8);
                *local_7c8 = 0;
              }
              if ((void *)local_7c8[1] != (void *)0x0) {
                operator_delete__((void *)local_7c8[1]);
                local_7c8[1] = 0;
              }
              FUN_180035134(local_7c8);
            }
          }
          if (iVar2 == -1) {
            GRsetsme(1);
            GRSetEmerBkpDlgOption(3);
            return 0xffffffff;
          }
          if (iVar2 != 1) {
            *(undefined1 *)(local_7d0 + 0xa8) = 1;
            GRbldbkprun(pcVar15,pcVar16,&DAT_180041670,local_6a8);
            GRbldbkprun(pcVar15,pcVar16,".apmbd",local_378);
            GRbldbkprun(pcVar15,pcVar16,&DAT_180041680,local_268);
            DeleteFileA(local_6a8);
            DeleteFileA(local_378);
            GRRemoveCostDir(local_268,0);
            BVar3 = MoveFileA(local_7b8,local_6a8);
            if (BVar3 == 0) {
              return 0;
            }
            GRRestoreEmergencyFiles(local_6a8,local_7b8);
            MoveFileA(local_488,local_378);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_5,
                       local_6a8);
            GRSetEmerBkpDlgOption(1);
            return 1;
          }
        }
        DeleteFileA(local_7b8);
        DeleteFileA(local_488);
        GRDeleteEmergencyFiles(param_4,local_7b8);
        GRSetEmerBkpDlgOption(2);
      }
    }
    else {
      GRbldemrbkp(pcVar15,pcVar16,"aprbk$",local_7b8);
      iVar2 = _access(local_7b8,0);
      if (iVar2 == 0) {
        if (param_2 == 0) {
          plVar5 = FUN_1800087d0(&local_7c0,DAT_180053570);
          plVar6 = FUN_1800087d0(&local_7d8,DAT_180053560);
          plVar7 = FUN_1800087d0(&local_7e0,DAT_180053550);
          pcVar4 = FUN_180033be0();
          plVar8 = FUN_1800087d0(&local_7e8,pcVar4);
          if ((undefined8 *)*plVar5 == (undefined8 *)0x0) {
            uVar14 = 0;
          }
          else {
            uVar14 = *(undefined8 *)*plVar5;
          }
          if ((undefined8 *)*plVar6 == (undefined8 *)0x0) {
            uVar12 = 0;
          }
          else {
            uVar12 = *(undefined8 *)*plVar6;
          }
          if ((undefined8 *)*plVar7 == (undefined8 *)0x0) {
            uVar10 = 0;
          }
          else {
            uVar10 = *(undefined8 *)*plVar7;
          }
          if ((undefined8 *)*plVar8 == (undefined8 *)0x0) {
            uVar9 = 0;
          }
          else {
            uVar9 = *(undefined8 *)*plVar8;
          }
          iVar2 = FUN_180010cc0(uVar9,uVar10,uVar12,uVar14,0,0,0,2,0xffffffff);
          if (local_7e8 != (undefined8 *)0x0) {
            LOCK();
            piVar11 = (int *)(local_7e8 + 2);
            iVar1 = *piVar11;
            *piVar11 = *piVar11 + -1;
            UNLOCK();
            if ((iVar1 == 1) && (local_7e8 != (undefined8 *)0x0)) {
              if ((BSTR)*local_7e8 != (BSTR)0x0) {
                SysFreeString((BSTR)*local_7e8);
                *local_7e8 = 0;
              }
              if ((void *)local_7e8[1] != (void *)0x0) {
                operator_delete__((void *)local_7e8[1]);
                local_7e8[1] = 0;
              }
              FUN_180035134(local_7e8);
            }
            local_7e8 = (undefined8 *)0x0;
          }
          if (local_7e0 != (undefined8 *)0x0) {
            LOCK();
            piVar11 = (int *)(local_7e0 + 2);
            iVar1 = *piVar11;
            *piVar11 = *piVar11 + -1;
            UNLOCK();
            if ((iVar1 == 1) && (local_7e0 != (undefined8 *)0x0)) {
              if ((BSTR)*local_7e0 != (BSTR)0x0) {
                SysFreeString((BSTR)*local_7e0);
                *local_7e0 = 0;
              }
              if ((void *)local_7e0[1] != (void *)0x0) {
                operator_delete__((void *)local_7e0[1]);
                local_7e0[1] = 0;
              }
              FUN_180035134(local_7e0);
            }
            local_7e0 = (undefined8 *)0x0;
          }
          if (local_7d8 != (undefined8 *)0x0) {
            LOCK();
            piVar11 = (int *)(local_7d8 + 2);
            iVar1 = *piVar11;
            *piVar11 = *piVar11 + -1;
            UNLOCK();
            if ((iVar1 == 1) && (local_7d8 != (undefined8 *)0x0)) {
              if ((BSTR)*local_7d8 != (BSTR)0x0) {
                SysFreeString((BSTR)*local_7d8);
                *local_7d8 = 0;
              }
              if ((void *)local_7d8[1] != (void *)0x0) {
                operator_delete__((void *)local_7d8[1]);
                local_7d8[1] = 0;
              }
              FUN_180035134(local_7d8);
            }
            local_7d8 = (undefined8 *)0x0;
          }
          if (local_7c0 != (undefined8 *)0x0) {
            LOCK();
            piVar11 = (int *)(local_7c0 + 2);
            iVar1 = *piVar11;
            *piVar11 = *piVar11 + -1;
            UNLOCK();
            if ((iVar1 == 1) && (local_7c0 != (undefined8 *)0x0)) {
              if ((BSTR)*local_7c0 != (BSTR)0x0) {
                SysFreeString((BSTR)*local_7c0);
                *local_7c0 = 0;
              }
              if ((void *)local_7c0[1] != (void *)0x0) {
                operator_delete__((void *)local_7c0[1]);
                local_7c0[1] = 0;
              }
              FUN_180035134(local_7c0);
            }
          }
          if (iVar2 == -1) {
            GRsetsme(1);
            return 0xffffffff;
          }
          if (iVar2 == 1) {
            DeleteFileA(local_7b8);
            return 0;
          }
        }
        *(undefined1 *)(local_7d0 + 0xa8) = 1;
        GRbldbkprun(pcVar15,pcVar16,".aprbkp",local_6a8);
        DeleteFileA(local_6a8);
        BVar3 = MoveFileA(local_7b8,local_6a8);
        if (BVar3 != 0) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_5,
                     local_6a8);
          return 1;
        }
      }
    }
  }
  return 0;
}

/* RVA 0xa4e0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined8
FUN_18000a4e0(undefined8 param_1,
             CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *param_2)

{
  _func_5302 *p_Var1;
  _func_5158 *p_Var2;
  _func_5320 *p_Var3;
  _func_5298 *p_Var4;
  LPRUNNINGOBJECTTABLE pIVar5;
  LPMONIKER pIVar6;
  IUnknown *This;
  int iVar7;
  int iVar8;
  HRESULT HVar9;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar10;
  longlong lVar11;
  char *pcVar12;
  undefined8 *puVar13;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar14;
  IAtlStringMgr *pIVar15;
  longlong lVar16;
  ulonglong uVar17;
  char *pcVar18;
  LPCOLESTR lpszPathName;
  undefined1 *puVar19;
  undefined8 uVar20;
  undefined8 uStack_a0;
  undefined1 auStack_98 [32];
  undefined8 uStack_78;
  int aiStack_70 [2];
  char *local_68;
  undefined4 local_60;
  char *local_58;
  char *local_50;
  char *local_48;
  LPRUNNINGOBJECTTABLE local_40;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_38 [8];
  LPMONIKER local_30;
  IUnknown *local_28;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_20 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_18 [8];
  ulonglong local_10;
  
  local_10 = DAT_180052888 ^ (ulonglong)&local_68;
  uVar20 = 0;
  local_60 = 0;
  uStack_a0 = 0x18000a524;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_68,param_2);
  uStack_a0 = 0x18000a531;
  iVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_68,'.')
  ;
  if (iVar7 != -1) {
    uStack_a0 = 0x18000a544;
    iVar8 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_68,
                       '\\');
    if (iVar8 <= iVar7) {
      uStack_a0 = 0x18000a559;
      pCVar10 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_68,(int)&local_28);
      uStack_a0 = 0x18000a567;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_68,pCVar10)
      ;
      uStack_a0 = 0x18000a572;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_28);
    }
  }
  puVar19 = auStack_98;
  uStack_a0 = 0x18000a577;
  iVar7 = FUN_180033bd0();
  pcVar18 = ".aprbkp";
  if (iVar7 == 1) {
    pcVar18 = ".bkp";
  }
  uStack_a0 = 0x18000a596;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_68,pcVar18);
  uStack_a0 = 0x18000a5a2;
  iVar7 = _access(local_68,0);
  if (iVar7 == 0) {
    uStack_a0 = 0x18000a5b4;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58);
    uStack_a0 = 0x18000a5c4;
    iVar7 = _access(local_68,2);
    if (iVar7 == -1) {
      uStack_a0 = 0x18000a5ce;
      FUN_180033be0();
      uStack_a0 = 0x18000a5dc;
      pcVar18 = (char *)GetSorResStringEx(0x573);
      uStack_a0 = 0x18000a5f0;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58,pcVar18,
                 local_68);
      puVar19 = auStack_98;
LAB_18000a721:
      *(undefined8 *)(puVar19 + -8) = 0x18000a735;
      MMAfxMessageBox(local_58,0x30,-1,0);
    }
    else {
      local_28 = (IUnknown *)0x0;
      local_30 = (IMoniker *)0x0;
      local_40 = (IRunningObjectTable *)0x0;
      uStack_a0 = 0x18000a60d;
      HVar9 = GetRunningObjectTable(0,&local_40);
      pcVar18 = local_68;
      puVar19 = auStack_98;
      if (-1 < HVar9) {
        puVar19 = auStack_98;
        if (local_68 == (LPCSTR)0x0) {
LAB_18000a692:
          lpszPathName = (LPCOLESTR)0x0;
        }
        else {
          lVar11 = -1;
          do {
            lVar16 = lVar11;
            lVar11 = lVar16 + 1;
          } while (local_68[lVar11] != '\0');
          iVar7 = (int)lVar16 + 2;
          puVar19 = auStack_98;
          if (0x3fffffff < iVar7) goto LAB_18000a692;
          lVar11 = (longlong)(int)lVar11 * 2;
          uVar17 = lVar11 + 0x11;
          if (uVar17 <= lVar11 + 2U) {
            uVar17 = 0xffffffffffffff0;
          }
          uStack_a0 = 0x18000a663;
          lVar11 = -(uVar17 & 0xfffffffffffffff0);
          puVar19 = auStack_98 + lVar11;
          lpszPathName = (LPCOLESTR)((longlong)aiStack_70 + lVar11 + 8);
          if (lpszPathName == (LPCOLESTR)0x0) goto LAB_18000a692;
          *lpszPathName = L'\0';
          *(int *)((longlong)aiStack_70 + lVar11) = iVar7;
          *(LPCOLESTR *)(auStack_98 + lVar11 + 0x20) = lpszPathName;
          *(undefined8 *)(auStack_98 + lVar11 + -8) = 0x18000a68a;
          iVar7 = MultiByteToWideChar(0,0,pcVar18,-1,*(LPWSTR *)(auStack_98 + lVar11 + 0x20),
                                      *(int *)((longlong)aiStack_70 + lVar11));
          puVar19 = auStack_98 + lVar11;
          if (iVar7 == 0) {
            lpszPathName = (LPCOLESTR)0x0;
            puVar19 = auStack_98 + lVar11;
          }
        }
        *(undefined8 *)(puVar19 + -8) = 0x18000a6a2;
        HVar9 = CreateFileMoniker(lpszPathName,&local_30);
        if (-1 < HVar9) {
          *(undefined8 *)(puVar19 + -8) = 0x18000a6b9;
          ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_68,-1);
          pIVar6 = local_30;
          pIVar5 = local_40;
          p_Var1 = local_40->lpVtbl->GetObjectA;
          *(undefined8 *)(puVar19 + -8) = 0x18000a6cb;
          HVar9 = (*p_Var1)(pIVar5,pIVar6,&local_28);
          This = local_28;
          pIVar6 = local_30;
          if (-1 < HVar9) {
            p_Var2 = local_28->lpVtbl->Release;
            *(undefined8 *)(puVar19 + -8) = 0x18000a6d9;
            (*p_Var2)(This);
            pIVar6 = local_30;
            p_Var3 = local_30->lpVtbl->Release;
            *(undefined8 *)(puVar19 + -8) = 0x18000a6e3;
            (*p_Var3)(pIVar6);
            pIVar5 = local_40;
            p_Var4 = local_40->lpVtbl->Release;
            *(undefined8 *)(puVar19 + -8) = 0x18000a6ed;
            (*p_Var4)(pIVar5);
            *(undefined8 *)(puVar19 + -8) = 0x18000a6f2;
            pcVar18 = FUN_180033be0();
            *(undefined8 *)(puVar19 + -8) = 0x18000a6fa;
            FUN_180033be0();
            *(undefined8 *)(puVar19 + -8) = 0x18000a708;
            pcVar12 = (char *)GetSorResStringEx(0x574);
            *(char **)(puVar19 + 0x20) = pcVar18;
            *(undefined8 *)(puVar19 + -8) = 0x18000a721;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58,
                       pcVar12,local_68);
            goto LAB_18000a721;
          }
          p_Var3 = local_30->lpVtbl->Release;
          *(undefined8 *)(puVar19 + -8) = 0x18000a744;
          (*p_Var3)(pIVar6);
        }
        pIVar5 = local_40;
        p_Var4 = local_40->lpVtbl->Release;
        *(undefined8 *)(puVar19 + -8) = 0x18000a74e;
        (*p_Var4)(pIVar5);
      }
      *(undefined8 *)(puVar19 + -8) = 0x18000a759;
      pcVar18 = (char *)GetSorResStringEx(0x575);
      *(undefined8 *)(puVar19 + -8) = 0x18000a766;
      puVar13 = (undefined8 *)
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_48,pcVar18);
      *(undefined8 *)(puVar19 + -8) = 0x18000a77a;
      pCVar14 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_38,"%s\n");
      *(undefined8 *)(puVar19 + -8) = 0x18000a786;
      pIVar15 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                          (pCVar14);
      *(undefined8 *)(puVar19 + -8) = 0x18000a793;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_50,pIVar15)
      ;
      local_60 = 1;
      pcVar18 = (char *)*puVar13;
      pcVar12 = *(char **)pCVar14;
      *(undefined4 *)(puVar19 + 0x20) = *(undefined4 *)(pcVar18 + -0x10);
      iVar7 = *(int *)(pcVar12 + -0x10);
      *(undefined8 *)(puVar19 + -8) = 0x18000a7b6;
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)&local_50,pcVar12,iVar7,pcVar18,*(int *)(puVar19 + 0x20))
      ;
      pcVar18 = local_50;
      *(undefined8 *)(puVar19 + -8) = 0x18000a7c8;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58,pcVar18,
                 local_68);
      *(undefined8 *)(puVar19 + -8) = 0x18000a7d3;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_50);
      *(undefined8 *)(puVar19 + -8) = 0x18000a7de;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_38);
      *(undefined8 *)(puVar19 + -8) = 0x18000a7e9;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48);
      *(undefined8 *)(puVar19 + -8) = 0x18000a7f4;
      pcVar18 = (char *)GetSorResStringEx(0x576);
      *(undefined8 *)(puVar19 + -8) = 0x18000a801;
      puVar13 = (undefined8 *)
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_18,pcVar18);
      *(undefined8 *)(puVar19 + -8) = 0x18000a815;
      pCVar14 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_20,"\n(");
      *(undefined8 *)(puVar19 + -8) = 0x18000a821;
      pIVar15 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                          (pCVar14);
      *(undefined8 *)(puVar19 + -8) = 0x18000a82e;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_50,pIVar15)
      ;
      local_60 = 2;
      pcVar18 = (char *)*puVar13;
      pcVar12 = *(char **)pCVar14;
      *(undefined4 *)(puVar19 + 0x20) = *(undefined4 *)(pcVar18 + -0x10);
      iVar7 = *(int *)(pcVar12 + -0x10);
      *(undefined8 *)(puVar19 + -8) = 0x18000a851;
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)&local_50,pcVar12,iVar7,pcVar18,*(int *)(puVar19 + 0x20))
      ;
      *(undefined8 *)(puVar19 + -8) = 0x18000a856;
      pcVar18 = (char *)MVGetI18nProductName();
      *(undefined8 *)(puVar19 + -8) = 0x18000a863;
      pIVar15 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_50);
      *(undefined8 *)(puVar19 + -8) = 0x18000a870;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48,pIVar15)
      ;
      local_60 = 6;
      if (pcVar18 == (char *)0x0) {
        lVar11 = 0;
      }
      else {
        lVar11 = -1;
        do {
          lVar11 = lVar11 + 1;
        } while (pcVar18[lVar11] != '\0');
      }
      *(int *)(puVar19 + 0x20) = (int)lVar11;
      iVar7 = *(int *)(local_50 + -0x10);
      *(undefined8 *)(puVar19 + -8) = 0x18000a8a9;
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)&local_48,local_50,iVar7,pcVar18,*(int *)(puVar19 + 0x20)
                );
      *(undefined8 *)(puVar19 + -8) = 0x18000a8b4;
      pIVar15 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_48);
      *(undefined8 *)(puVar19 + -8) = 0x18000a8c1;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_38,pIVar15);
      local_60 = 0xe;
      lVar11 = -1;
      do {
        lVar16 = lVar11 + 1;
        pcVar18 = &DAT_1800417a9 + lVar11;
        lVar11 = lVar16;
      } while (*pcVar18 != '\0');
      *(int *)(puVar19 + 0x20) = (int)lVar16;
      iVar7 = *(int *)(local_48 + -0x10);
      *(undefined8 *)(puVar19 + -8) = 0x18000a8f6;
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)local_38,local_48,iVar7,")",*(int *)(puVar19 + 0x20));
      *(undefined8 *)(puVar19 + -8) = 0x18000a904;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58,
                 (CSimpleStringT<char,1> *)local_38);
      *(undefined8 *)(puVar19 + -8) = 0x18000a90f;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_38);
      *(undefined8 *)(puVar19 + -8) = 0x18000a91a;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48);
      *(undefined8 *)(puVar19 + -8) = 0x18000a925;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_50);
      *(undefined8 *)(puVar19 + -8) = 0x18000a930;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_20);
      *(undefined8 *)(puVar19 + -8) = 0x18000a93b;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_18);
      *(undefined8 *)(puVar19 + -8) = 0x18000a94f;
      iVar7 = MMAfxMessageBox(local_58,0x31,-1,0);
      if (iVar7 != 2) {
        *(undefined8 *)(puVar19 + -8) = 0x18000a970;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58);
        goto LAB_18000a970;
      }
      *(undefined8 *)(puVar19 + -8) = 0x18000a959;
      SimExit();
    }
    *(undefined8 *)(puVar19 + -8) = 0x18000a964;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58);
  }
  else {
LAB_18000a970:
    *(undefined8 *)(puVar19 + -8) = 0x18000a97d;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               &local_68);
    uVar20 = 1;
  }
  *(undefined8 *)(puVar19 + -8) = 0x18000a98c;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_68);
  *(undefined8 *)(puVar19 + -8) = 0x18000a99a;
  return uVar20;
}

/* RVA 0xa9c0 */
byte FUN_18000a9c0(longlong param_1,char param_2)

{
  longlong *plVar1;
  int iVar2;
  byte extraout_var;
  longlong *plVar3;
  byte bVar4;
  longlong *local_res8;
  
  bVar4 = 0;
  iVar2 = FUN_180033bd0();
  if (iVar2 == 1) {
    if (*(longlong *)(param_1 + 0x38) == 0) {
      plVar3 = (longlong *)HappGetTree();
      plVar1 = *(longlong **)(param_1 + 0x38);
      if (plVar1 != plVar3) {
        if ((plVar3 == (longlong *)0x0) ||
           (iVar2 = (**(code **)*plVar3)(plVar3,&DAT_1800413f0,param_1 + 0x38), iVar2 < 0)) {
          *(undefined8 *)(param_1 + 0x38) = 0;
        }
        if (plVar1 != (longlong *)0x0) {
          (**(code **)(*plVar1 + 0x10))(plVar1);
        }
      }
    }
    InitGlobalBlockUsage(*(undefined8 *)(param_1 + 0x38));
    if (param_2 != '\0') {
      MDintbku();
      MDintecn();
    }
    local_res8 = (longlong *)0x0;
    iVar2 = FUN_18000c8a0(param_1,*(undefined8 **)(param_1 + 0x38),&local_res8);
    plVar1 = local_res8;
    bVar4 = (byte)((uint)iVar2 >> 0x18);
    if (local_res8 != (longlong *)0x0) {
      SEInitializeVData(local_res8);
      (**(code **)(*plVar1 + 0x10))(plVar1);
      bVar4 = extraout_var;
    }
  }
  SetGlobalPointer("ApwnDocStorage",*(undefined8 *)(param_1 + 8),0);
  SetGlobalPointer("LoadPFSFromDoc",&LAB_18000d600,0);
  SetGlobalPointer("SavePFSFToDoc",&LAB_18000d640,0);
  SetGlobalPointer("ClearPFSEmbedding",&LAB_18000d5b0,0);
  SetGlobalPointer("GetPFSEmbedding",&LAB_18000d5d0,0);
  SetGlobalPointer("RestorePFSEmbedding",&LAB_18000d620,0);
  return bVar4 >> 7 ^ 1;
}

/* RVA 0xab20 */
undefined4 FUN_18000ab20(void)

{
  undefined4 uVar1;
  longlong lVar2;
  
  FUN_180033bd0();
  lVar2 = GetGlobalPointer("CompoundFileName");
  uVar1 = (undefined4)lVar2;
  if (lVar2 != 0) {
    uVar1 = HappUpdateMoniker(lVar2);
  }
  return CONCAT31((int3)((uint)uVar1 >> 8),1);
}

/* RVA 0xab50 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18000ab50(void)

{
  longlong *plVar1;
  undefined8 uVar2;
  undefined1 auStack_488 [32];
  longlong *local_468;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_460 [8];
  _union_2707 local_458;
  _union_2707 local_440;
  undefined4 local_428;
  ULONG UStack_424;
  undefined4 uStack_420;
  undefined4 uStack_41c;
  undefined8 local_418;
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_180052888 ^ (ulonglong)auStack_488;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_460);
  VariantInit((VARIANTARG *)&local_440.n2);
  VariantInit((VARIANTARG *)&local_458.n2);
  plVar1 = (longlong *)HappGetTree();
  if (plVar1 == (longlong *)0x0) {
    uVar2 = 1;
  }
  else {
    local_468 = (longlong *)0x0;
    (**(code **)(*plVar1 + 200))(plVar1,&local_468);
    (**(code **)(*plVar1 + 0x10))(plVar1);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              (local_460,"Settings");
    plVar1 = (longlong *)FUN_1800116a0(&local_468,local_460);
    (**(code **)(*local_468 + 0x10))();
    uVar2 = 1;
    if (plVar1 == (longlong *)0x0) {
      FUN_180001ce0(local_408,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\ApwnShellIP\\ApwnLWDocument.cpp",0x9b);
      LogMessage(local_408,2,1);
    }
    local_468 = (longlong *)0x0;
    (**(code **)(*plVar1 + 200))(plVar1,&local_468);
    (**(code **)(*plVar1 + 0x10))(plVar1);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              (local_460,"roottype");
    plVar1 = (longlong *)FUN_1800116a0(&local_468,local_460);
    (**(code **)(*local_468 + 0x10))();
    local_428 = local_440._0_4_;
    UStack_424 = local_440.decVal.Hi32;
    uStack_420 = local_440._8_4_;
    uStack_41c = local_440._12_4_;
    local_418 = local_440._16_8_;
    (**(code **)(*plVar1 + 0x68))(plVar1,&local_428,&local_458);
    (**(code **)(*plVar1 + 0x10))(plVar1);
    if ((local_458.n2.vt == 3) && (local_458._8_4_ == 0)) {
      VariantClear((VARIANTARG *)&local_440.n2);
      VariantClear((VARIANTARG *)&local_458.n2);
    }
    else {
      VariantClear((VARIANTARG *)&local_440.n2);
      VariantClear((VARIANTARG *)&local_458.n2);
      uVar2 = 0;
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_460);
  return uVar2;
}

/* RVA 0xad50 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

undefined8 FUN_18000ad50(void *param_1,char *param_2,int param_3,LPCSTR param_4)

{
  int *piVar1;
  char cVar2;
  char cVar3;
  longlong *plVar4;
  LPCSTR pCVar5;
  bool bVar6;
  int iVar7;
  UINT UVar8;
  char *******pppppppcVar9;
  IStorage *This;
  IStorageVtbl *pIVar10;
  char *******pppppppcVar11;
  undefined8 *puVar12;
  BSTR pOVar13;
  IStorage *This_00;
  char *******pppppppcVar14;
  ulonglong uVar15;
  longlong lVar16;
  size_t sVar17;
  ulonglong uVar18;
  ulonglong _Size;
  undefined1 auStackY_d8 [32];
  int local_a8 [2];
  LPCSTR local_a0;
  char *local_98;
  char *******local_90;
  undefined8 uStack_88;
  size_t local_80;
  ulonglong uStack_78;
  char *******local_70;
  undefined8 uStack_68;
  ulonglong local_60;
  ulonglong uStack_58;
  ulonglong local_50;
  
  local_50 = DAT_180052888 ^ (ulonglong)auStackY_d8;
  local_a8[0] = 0;
  local_a0 = param_4;
  HappFireBeforeSave(param_2,local_a8);
  if (local_a8[0] != 0) {
    return 0;
  }
  pppppppcVar11 = (char *******)((longlong)param_1 + 0x60);
  pppppppcVar9 = pppppppcVar11;
  if (0xf < *(ulonglong *)((longlong)param_1 + 0x78)) {
    pppppppcVar9 = (char *******)*pppppppcVar11;
  }
  lVar16 = (longlong)param_2 - (longlong)pppppppcVar9;
  do {
    cVar2 = *(char *)pppppppcVar9;
    cVar3 = *(char *)((longlong)pppppppcVar9 + lVar16);
    if (cVar2 != cVar3) break;
    pppppppcVar9 = (char *******)((longlong)pppppppcVar9 + 1);
  } while (cVar3 != '\0');
  *(bool *)((longlong)param_1 + 0xb8) = cVar2 != cVar3;
  sVar17 = 0xffffffffffffffff;
  do {
    sVar17 = sVar17 + 1;
  } while (param_2[sVar17] != '\0');
  FUN_18001d350((longlong *)((longlong)param_1 + 0x80),param_2,sVar17);
  This_00 = *(IStorage **)((longlong)param_1 + 8);
  (*This_00->lpVtbl->AddRef)(This_00);
  local_a8[1] = 1;
  iVar7 = GRinqcolumnanalyzer();
  if (iVar7 != 0) {
    SESetSettingValue("tpsaupgrade",local_a8 + 1,0,0);
  }
  bVar6 = ApwnContextDocumentSave
                    (*(void **)((longlong)param_1 + 0xb0),param_2,param_3 != 0,FUN_18000bc20,param_1
                    );
  if (!bVar6) {
    (*This_00->lpVtbl->Release)(This_00);
    return 1;
  }
  This = ApwnContextDocumentRootStorage(*(void **)((longlong)param_1 + 0xb0));
  if (This == *(IStorage **)((longlong)param_1 + 8)) {
    pIVar10 = This_00->lpVtbl;
  }
  else {
    SetGlobalPointer("ApwnDocStorage",This,0);
    STclsstg(*(undefined8 *)((longlong)param_1 + 8));
    if (*(IStorage **)((longlong)param_1 + 8) != This) {
      if (This != (IStorage *)0x0) {
        (*This->lpVtbl->AddRef)(This);
      }
      plVar4 = *(longlong **)((longlong)param_1 + 8);
      *(IStorage **)((longlong)param_1 + 8) = This;
      if (plVar4 != (longlong *)0x0) {
        (**(code **)(*plVar4 + 0x10))();
      }
    }
    pIVar10 = This->lpVtbl;
    This_00 = This;
  }
  (*pIVar10->Release)(This_00);
  if (param_3 != 0) {
    local_90 = (char *******)0x0;
    uStack_88 = 0;
    local_80 = 0;
    uStack_78 = 0;
    sVar17 = 0xffffffffffffffff;
    do {
      sVar17 = sVar17 + 1;
    } while (param_2[sVar17] != '\0');
    FUN_180006e90(&local_90,param_2,sVar17);
    if ((char ********)pppppppcVar11 != &local_90) {
      pppppppcVar9 = (char *******)&local_90;
      if (0xf < uStack_78) {
        pppppppcVar9 = local_90;
      }
      FUN_18001d350((longlong *)pppppppcVar11,pppppppcVar9,local_80);
    }
    uVar18 = uStack_78;
    pppppppcVar11 = local_90;
    pppppppcVar9 = (char *******)&local_90;
    if (0xf < uStack_78) {
      pppppppcVar9 = local_90;
    }
    if (local_80 == 0) {
LAB_18000af72:
      lVar16 = -1;
    }
    else {
      lVar16 = -1;
      if (local_80 - 1 != -1) {
        lVar16 = local_80 - 1;
      }
      pppppppcVar14 = (char *******)((longlong)pppppppcVar9 + lVar16);
      cVar2 = *(char *)pppppppcVar14;
      while (cVar2 != '\\') {
        if (pppppppcVar14 == pppppppcVar9) goto LAB_18000af72;
        pppppppcVar14 = (char *******)((longlong)pppppppcVar14 + -1);
        cVar2 = *(char *)pppppppcVar14;
      }
      lVar16 = (longlong)pppppppcVar14 - (longlong)pppppppcVar9;
    }
    if (lVar16 == -1) {
      if ((char ********)((longlong)param_1 + 0x40) != &local_90) {
        pppppppcVar11 = (char *******)&local_90;
        if (0xf < uStack_78) {
          pppppppcVar11 = local_90;
        }
        goto LAB_18000b0c6;
      }
    }
    else {
      uVar15 = lVar16 + 1;
      local_70 = (char *******)0x0;
      uStack_68 = 0;
      if (local_80 < uVar15) {
                    /* WARNING: Subroutine does not return */
        FUN_18001d1f0();
      }
      _Size = 0xffffffffffffffff;
      if (local_80 - uVar15 != 0xffffffffffffffff) {
        _Size = local_80 - uVar15;
      }
      pppppppcVar9 = (char *******)&local_90;
      if (0xf < uStack_78) {
        pppppppcVar9 = local_90;
      }
      local_98 = (char *)((longlong)pppppppcVar9 + uVar15);
      if (0x7fffffffffffffff < _Size) {
                    /* WARNING: Subroutine does not return */
        FUN_18001d1b0();
      }
      local_60 = _Size;
      if (_Size < 0x10) {
        uStack_58 = 0xf;
        memcpy(&local_70,local_98,_Size);
        *(undefined1 *)((longlong)&local_70 + _Size) = 0;
      }
      else {
        uVar15 = _Size | 0xf;
        uVar18 = 0x7fffffffffffffff;
        if ((uVar15 < 0x8000000000000000) && (uVar18 = uVar15, uVar15 < 0x16)) {
          uVar18 = 0x16;
        }
        pppppppcVar11 = FUN_18001d210(&local_70,uVar18 + 1);
        local_70 = pppppppcVar11;
        uStack_58 = uVar18;
        memcpy(pppppppcVar11,local_98,_Size);
        *(char *)((longlong)pppppppcVar11 + _Size) = '\0';
        pppppppcVar11 = local_90;
        uVar18 = uStack_78;
      }
      if (0xf < uVar18) {
        pppppppcVar9 = pppppppcVar11;
        if ((0xfff < uVar18 + 1) &&
           (pppppppcVar9 = (char *******)pppppppcVar11[-1],
           (char *)0x1f < (char *)((longlong)pppppppcVar11 + (-8 - (longlong)pppppppcVar9)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        FUN_180035134(pppppppcVar9);
      }
      local_90 = local_70;
      uStack_88 = uStack_68;
      local_80 = local_60;
      uStack_78 = uStack_58;
      if ((char ********)((longlong)param_1 + 0x40) != &local_90) {
        pppppppcVar11 = (char *******)&local_90;
        if (0xf < uStack_58) {
          pppppppcVar11 = local_70;
        }
LAB_18000b0c6:
        FUN_18001d350((longlong *)((longlong)param_1 + 0x40),pppppppcVar11,local_80);
      }
    }
    if (0xf < uStack_78) {
      pppppppcVar11 = local_90;
      if ((0xfff < uStack_78 + 1) &&
         (pppppppcVar11 = (char *******)local_90[-1],
         (char *)0x1f < (char *)((longlong)local_90 + (-8 - (longlong)pppppppcVar11)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      FUN_180035134(pppppppcVar11);
    }
  }
  pCVar5 = local_a0;
  puVar12 = operator_new(0x18);
  local_a0 = (LPCSTR)puVar12;
  if (pCVar5 == (LPCSTR)0x0) {
    if (puVar12 == (undefined8 *)0x0) {
      puVar12 = (undefined8 *)0x0;
    }
    else {
      puVar12[1] = 0;
      *(undefined4 *)(puVar12 + 2) = 1;
      pOVar13 = FUN_180034c50(param_2);
      *puVar12 = pOVar13;
    }
    local_a0 = (LPCSTR)puVar12;
    if (puVar12 == (undefined8 *)0x0) goto LAB_18000b293;
    if ((BSTR)*puVar12 == (BSTR)0x0) {
      pOVar13 = (BSTR)0x0;
    }
    else {
      UVar8 = SysStringByteLen((BSTR)*puVar12);
      pOVar13 = SysAllocStringByteLen((LPCSTR)*puVar12,UVar8);
      if (pOVar13 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_180034a60(0x8007000e);
      }
    }
    LOCK();
    piVar1 = (int *)(puVar12 + 2);
    iVar7 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar7 != 1) goto LAB_18000b25a;
    if ((BSTR)*puVar12 != (BSTR)0x0) {
      SysFreeString((BSTR)*puVar12);
      *puVar12 = 0;
    }
    if ((void *)puVar12[1] != (void *)0x0) {
      operator_delete__((void *)puVar12[1]);
      puVar12[1] = 0;
    }
  }
  else {
    if (puVar12 == (undefined8 *)0x0) {
      puVar12 = (undefined8 *)0x0;
    }
    else {
      puVar12[1] = 0;
      *(undefined4 *)(puVar12 + 2) = 1;
      pOVar13 = FUN_180034c50(pCVar5);
      *puVar12 = pOVar13;
    }
    local_a0 = (LPCSTR)puVar12;
    if (puVar12 == (undefined8 *)0x0) {
LAB_18000b293:
                    /* WARNING: Subroutine does not return */
      FUN_180034a60(0x8007000e);
    }
    if ((BSTR)*puVar12 == (BSTR)0x0) {
      pOVar13 = (BSTR)0x0;
    }
    else {
      UVar8 = SysStringByteLen((BSTR)*puVar12);
      pOVar13 = SysAllocStringByteLen((LPCSTR)*puVar12,UVar8);
      if (pOVar13 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_180034a60(0x8007000e);
      }
    }
    LOCK();
    piVar1 = (int *)(puVar12 + 2);
    iVar7 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar7 != 1) goto LAB_18000b25a;
    if ((BSTR)*puVar12 != (BSTR)0x0) {
      SysFreeString((BSTR)*puVar12);
      *puVar12 = 0;
    }
    if ((void *)puVar12[1] != (void *)0x0) {
      operator_delete__((void *)puVar12[1]);
      puVar12[1] = 0;
    }
  }
  FUN_180035134(puVar12);
LAB_18000b25a:
  SysFreeString(pOVar13);
  return 1;
}

/* RVA 0xb2c0 */
ulonglong FUN_18000b2c0(undefined8 *param_1,char *param_2)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  ulonglong uVar2;
  CWinThread *pCVar3;
  undefined8 uVar4;
  char *pcVar5;
  ulonglong uVar6;
  char *local_res8;
  char *local_res18;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res20 [8];
  
  FUN_18000d4d0(param_1,(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8
               );
  pcVar5 = (char *)(param_1 + 0xc);
  if (0xf < (ulonglong)param_1[0xf]) {
    pcVar5 = *(char **)pcVar5;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18,pcVar5);
  pCVar1 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
           CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20,param_2);
  uVar2 = FUN_18000b660(param_1,param_2,
                        (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                        &local_res18,
                        (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8
                        ,pCVar1);
  if ((int)uVar2 != 0) {
    if (*(int *)(local_res18 + -0x10) != 0) {
      pCVar3 = AfxGetThread();
      uVar6 = 0;
      if (pCVar3 != (CWinThread *)0x0) {
        (**(code **)(*(longlong *)pCVar3 + 0xf8))(pCVar3);
      }
      uVar4 = FUN_180031b00(param_2,local_res18,local_res8);
      if ((int)uVar4 == 1) {
        pCVar1 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                 ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                 CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                           (local_res20,
                            (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                             *)&local_res8);
        FUN_1800099b0(param_1,pCVar1);
        goto LAB_18000b3c8;
      }
      HappUpdateMoniker(param_2);
    }
    uVar4 = GetSorResStringEx(0x57e);
    SimUpdateMessageView(0,uVar4);
  }
  pCVar1 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
           CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                     (local_res20,
                      (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                      &local_res8);
  FUN_1800099b0(param_1,pCVar1);
  uVar6 = uVar2 & 0xffffffff;
LAB_18000b3c8:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
  return uVar6;
}

/* RVA 0xb3f0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18000b3f0(undefined8 *param_1,
                  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2,
                  undefined8 param_3)

{
  int iVar1;
  char *pcVar2;
  IStorage *This;
  longlong lVar3;
  longlong *plVar4;
  longlong *plVar5;
  char *pcVar6;
  undefined1 auStackY_4a8 [32];
  char local_478 [8];
  LPCSTR local_470;
  undefined8 local_468;
  LPCSTR local_460;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_458;
  char local_448 [256];
  char local_348 [256];
  char local_248 [272];
  char local_138 [256];
  ulonglong local_38;
  
  local_38 = DAT_180052888 ^ (ulonglong)auStackY_4a8;
  plVar4 = (longlong *)param_1[1];
  local_458 = param_2;
  (**(code **)(*plVar4 + 8))(plVar4);
  pcVar2 = *(char **)param_2;
  iVar1 = FUN_180033bd0();
  pcVar6 = ".aprop";
  if (iVar1 == 1) {
    pcVar6 = ".apw";
  }
  FUN_18000bf20((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_468,pcVar2,
                pcVar6);
  ApwnContextDocumentSetRememberFlag((void *)param_1[0x16],false);
  param_1[2] = 0;
  pcVar2 = (char *)GRemrbkpfull();
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_470,pcVar2);
  (**(code **)*param_1)(param_1,local_468,0,param_3);
  This = ApwnContextDocumentRootStorage((void *)param_1[0x16]);
  if ((IStorage *)param_1[1] == This) {
    if (((IStorage *)param_1[1] != (IStorage *)param_1[2]) &&
       ((IStorage *)param_1[2] != (IStorage *)0x0)) {
      SetGlobalPointer("ApwnDocStorage",This,0);
      STclsstg(param_1[2]);
    }
    lVar3 = *plVar4;
  }
  else {
    SetGlobalPointer("ApwnDocStorage",plVar4,0);
    STclsstg(param_1[1]);
    if ((IStorage *)param_1[1] == This) goto LAB_18000b522;
    if (This != (IStorage *)0x0) {
      (*This->lpVtbl->AddRef)(This);
    }
    plVar4 = (longlong *)param_1[1];
    param_1[1] = This;
    if (plVar4 == (longlong *)0x0) goto LAB_18000b522;
    lVar3 = *plVar4;
  }
  (**(code **)(lVar3 + 0x10))(plVar4);
LAB_18000b522:
  if (param_1[2] != 0) {
    param_1[2] = 0;
  }
  plVar4 = param_1 + 0xc;
  if (param_1[0xe] != 0) {
    plVar5 = plVar4;
    if (0xf < (ulonglong)param_1[0xf]) {
      plVar5 = (longlong *)*plVar4;
    }
    HappUpdateMoniker(plVar5);
  }
  plVar5 = plVar4;
  if (0xf < (ulonglong)param_1[0xf]) {
    plVar5 = (longlong *)*plVar4;
  }
  GRAuxFileOnSaveAs(plVar5,local_468);
  DeleteFileA(local_470);
  DeleteFileA("$backup.bkp");
  if (0xf < (ulonglong)param_1[0xf]) {
    plVar4 = (longlong *)*plVar4;
  }
  GRDeleteEmergencyFiles(plVar4,local_470);
  _splitpath(*(char **)param_2,local_478,local_348,local_448,local_138);
  _makepath(local_248,local_478,local_348,local_448,"ads");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_460,local_248);
  DeleteFileA(local_460);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_460);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_470);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_468);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_2);
  return;
}

/* RVA 0xb660 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_18000b660(undefined8 *param_1,char *param_2,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_3,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_4,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_5)

{
  void *_Src;
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar4;
  IAtlStringMgr *pIVar5;
  longlong lVar6;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar7;
  longlong lVar8;
  size_t _Count;
  char *pcVar9;
  char *pcVar10;
  undefined1 auStackY_188 [32];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_158 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_150 [8];
  undefined8 local_148;
  undefined4 local_140;
  int local_138;
  undefined4 uStack_134;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_130;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_128;
  char *local_120;
  undefined8 *local_118;
  char *local_110;
  char *local_108;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_100;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_f8;
  undefined1 *local_e8;
  undefined1 local_e0 [136];
  ulonglong local_58;
  
  local_58 = DAT_180052888 ^ (ulonglong)auStackY_188;
  local_f8 = param_5;
  local_140 = 0;
  local_128 = param_4;
  local_120 = param_2;
  local_118 = param_1;
  local_100 = param_3;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_148);
  uVar2 = FUN_18000ab50();
  local_138 = (int)uVar2;
  pcVar3 = (char *)GRemrbkp();
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_108,pcVar3);
  if (param_1[0xe] == 0) {
    if (*(int *)(*(longlong *)param_5 + -0x10) == 0) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_5,param_2)
      ;
    }
  }
  else {
    pcVar3 = (char *)(param_1 + 0xc);
    if (0xf < (ulonglong)param_1[0xf]) {
      pcVar3 = *(char **)pcVar3;
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_5,pcVar3);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind(param_4,'.');
  pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                     (param_4,(int)local_150);
  local_130 = pCVar4;
  iVar1 = FUN_180033bd0();
  pcVar9 = ".aprbkp";
  pcVar3 = ".aprbkp";
  if (iVar1 == 1) {
    pcVar3 = ".bkp";
  }
  pIVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager(pCVar4);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_158,pIVar5);
  local_140 = 1;
  lVar8 = -1;
  lVar6 = -1;
  do {
    lVar6 = lVar6 + 1;
  } while (pcVar3[lVar6] != '\0');
  ATL::CSimpleStringT<char,1>::Concatenate
            ((CSimpleStringT<char,1> *)local_158,*(char **)local_130,
             *(int *)(*(char **)local_130 + -0x10),pcVar3,(int)lVar6);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_148,
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)local_158)
  ;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_158);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_150);
  HappUpdateMoniker(local_148);
  if (local_138 == 0) {
    WriteHappArchive(local_148,*(undefined4 *)((longlong)param_1 + 0xbc));
    pCVar4 = local_128;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind(local_128,'.');
    pCVar7 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                       (pCVar4,(int)local_150);
    iVar1 = FUN_180033bd0();
    pcVar9 = ".aprop";
    pcVar3 = ".aprop";
    if (iVar1 == 1) {
      pcVar3 = ".apw";
    }
    pIVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager(pCVar7);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_158,pIVar5);
    local_140 = 4;
    lVar6 = -1;
    do {
      lVar6 = lVar6 + 1;
    } while (pcVar3[lVar6] != '\0');
    ATL::CSimpleStringT<char,1>::Concatenate
              ((CSimpleStringT<char,1> *)local_158,*(char **)pCVar7,
               *(int *)(*(char **)pCVar7 + -0x10),pcVar3,(int)lVar6);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_148,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               local_158);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_158);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_150);
    pCVar7 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                       (local_150,
                        (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *
                        )&local_148);
    FUN_18000b3f0(local_118,pCVar7,local_120);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind(param_5,'.');
    pCVar7 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                       (param_5,(int)local_150);
    iVar1 = FUN_180033bd0();
    if (iVar1 == 1) {
      pcVar9 = ".apw";
    }
    pIVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager(pCVar7);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_158,pIVar5);
    local_140 = 8;
    do {
      lVar8 = lVar8 + 1;
    } while (pcVar9[lVar8] != '\0');
    ATL::CSimpleStringT<char,1>::Concatenate
              ((CSimpleStringT<char,1> *)local_158,*(char **)pCVar7,
               *(int *)(*(char **)pCVar7 + -0x10),pcVar9,(int)lVar8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              (param_5,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                       local_158);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_158);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_150);
  }
  else {
    WriteHappArchive(local_148,*(undefined4 *)((longlong)param_1 + 0xbc));
    pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                       ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_130,
                        local_120);
    pCVar7 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_150,local_120);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind(pCVar4,'.');
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left(pCVar7,(int)&local_138)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_150);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_130);
    _Src = (void *)CONCAT44(uStack_134,local_138);
    local_e8 = local_e0;
    if (_Src == (void *)0x0) {
      local_e8 = (undefined1 *)0x0;
    }
    else {
      lVar6 = -1;
      do {
        lVar6 = lVar6 + 1;
      } while (*(char *)((longlong)_Src + lVar6) != '\0');
      iVar1 = (int)lVar6 + 1;
      if (iVar1 < 0) {
                    /* WARNING: Subroutine does not return */
        FUN_1800018d0(-0x7ff8ffa9);
      }
      _Count = (size_t)iVar1;
      if (iVar1 < 0x81) {
        local_e8 = local_e0;
      }
      else {
        local_e8 = calloc(_Count,1);
        if (local_e8 == (undefined1 *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_1800018d0(-0x7ff8fff2);
        }
      }
      if (_Count != 0) {
        memcpy(local_e8,_Src,_Count);
      }
      param_1 = local_118;
    }
    pcVar10 = (char *)(param_1 + 0xc);
    rename_MM_runid(local_e8);
    HappUpdateMoniker(local_e8);
    pcVar3 = pcVar10;
    if (0xf < (ulonglong)param_1[0xf]) {
      pcVar3 = *(char **)pcVar10;
    }
    iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_148,
                       pcVar3);
    if (iVar1 == 0) {
      if (0xf < (ulonglong)param_1[0xf]) {
        pcVar10 = *(char **)pcVar10;
      }
      GRAuxFileOnSave(pcVar10);
    }
    else {
      if (0xf < (ulonglong)param_1[0xf]) {
        pcVar10 = *(char **)pcVar10;
      }
      GRAuxFileOnSaveAs(pcVar10,local_148);
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind(param_5,'.');
    pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                       (param_5,(int)local_150);
    iVar1 = FUN_180033bd0();
    if (iVar1 == 1) {
      pcVar9 = ".bkp";
    }
    pIVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager(pCVar4);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_158,pIVar5);
    local_140 = 2;
    do {
      lVar8 = lVar8 + 1;
    } while (pcVar9[lVar8] != '\0');
    ATL::CSimpleStringT<char,1>::Concatenate
              ((CSimpleStringT<char,1> *)local_158,*(char **)pCVar4,
               *(int *)(*(char **)pCVar4 + -0x10),pcVar9,(int)lVar8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              (param_5,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                       local_158);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_158);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_150);
    if (local_e8 != local_e0) {
      free(local_e8);
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_138);
    pCVar4 = local_128;
  }
  pcVar3 = (char *)GRemrbkp();
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_110,pcVar3);
  rename(local_108,local_110);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            (local_100,
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)param_5);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            (pCVar4,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                    &local_148);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_110);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_108);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_148);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_5);
  return 1;
}

