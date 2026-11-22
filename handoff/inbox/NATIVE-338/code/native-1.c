/* NATIVE-338 reconstructed pseudo-C (editable) */

/* ---- FUNC 00001000 FUN_180001000 (97 bytes) ---- */

void FUN_180001000(void)

{
  BOOL BVar1;
  DWORD DVar2;
  
  BVar1 = InitializeCriticalSectionEx((LPCRITICAL_SECTION)&DAT_1800777e0,0,0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if (0 < (int)DVar2) {
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
    if ((int)DVar2 < 0) {
      DAT_180079879 = 1;
      atexit(FUN_180060410);
      return;
    }
  }
  DAT_1800777c0 = 0x48;
  atexit(FUN_180060410);
  return;
}

/* ---- FUNC 00001070 FUN_180001070 (121 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180001070(void)

{
  BOOL BVar1;
  DWORD DVar2;
  
  DAT_180079320 = &DAT_180079810;
  BVar1 = InitializeCriticalSectionEx((LPCRITICAL_SECTION)&DAT_180079828,0,0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if (0 < (int)DVar2) {
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
    if ((int)DVar2 < 0) {
      DAT_180079879 = 1;
      goto LAB_1800010c3;
    }
  }
  _DAT_180079818 = 0x38;
LAB_1800010c3:
  _DAT_180079868 = &DAT_180079810;
  _DAT_180079810 = ATL::CComModule::vftable;
  atexit((_func_5014 *)&LAB_1800604a0);
  return;
}

/* ---- FUNC 000010F0 FUN_1800010f0 (54 bytes) ---- */

void FUN_1800010f0(void)

{
  DAT_180079c30 = operator_new(0x30);
  *(void **)DAT_180079c30 = DAT_180079c30;
  *(void **)((longlong)DAT_180079c30 + 8) = DAT_180079c30;
  *(void **)((longlong)DAT_180079c30 + 0x10) = DAT_180079c30;
  *(undefined2 *)((longlong)DAT_180079c30 + 0x18) = 0x101;
  atexit(FUN_1800604c0);
  return;
}

/* ---- FUNC 00001128 FUN_180001128 (32 bytes) ---- */

void FUN_180001128(void)

{
  ATL::CAtlBaseModule::CAtlBaseModule((CAtlBaseModule *)&DAT_18007a610);
  atexit((_func_5014 *)&LAB_180060524);
  return;
}

/* ---- FUNC 00001160 FUN_180001160 (58 bytes) ---- */

void FUN_180001160(ulonglong param_1)

{
  void *pvVar1;
  
  if (param_1 + 0x27 <= param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_180002760();
  }
  pvVar1 = operator_new(param_1 + 0x27);
  if (pvVar1 != (void *)0x0) {
    *(void **)(((longlong)pvVar1 + 0x27U & 0xffffffffffffffe0) - 8) = pvVar1;
    return;
  }
                    /* WARNING: Subroutine does not return */
  _invalid_parameter_noinfo_noreturn();
}

/* ---- FUNC 000011A0 FUN_1800011a0 (375 bytes) ---- */

undefined8 * FUN_1800011a0(undefined8 *param_1)

{
  undefined8 *puVar1;
  longlong *plVar2;
  
  *param_1 = CAdsNode::vftable;
  plVar2 = (longlong *)0x0;
  *(undefined4 *)(param_1 + 1) = 0;
  FUN_1800212f0(param_1 + 2,param_1,&DAT_1800634b0);
  FUN_180058ec0(param_1 + 0xf,param_1,param_1,0);
  FUN_1800589e0(param_1 + 0x14,param_1,param_1,0);
  param_1[0x1a] = 0;
  FUN_180059ca0(param_1 + 0x1c,param_1,param_1,0);
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  FUN_180058e20(param_1 + 0x26,param_1,param_1,0);
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  *(undefined4 *)(param_1 + 0x2f) = 0;
  param_1[0x33] = 0;
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0xf;
  *(undefined1 *)(param_1 + 0x33) = 0;
  *(undefined4 *)((longlong)param_1 + 0x1bc) = 0;
  *(undefined4 *)(param_1 + 1) = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x1a] = 0;
  param_1[0x22] = 0;
  param_1[0x21] = 0;
  VariantInit((VARIANTARG *)(param_1 + 0x30));
  *(undefined4 *)(param_1 + 0x1b) = 0;
  puVar1 = operator_new(0x28);
  if (puVar1 != (undefined8 *)0x0) {
    plVar2 = FUN_180058810(puVar1,param_1,param_1,0);
  }
  param_1[0x23] = plVar2;
  if (plVar2 != (longlong *)0x0) {
    (**(code **)(*plVar2 + 8))(plVar2);
  }
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

/* ---- FUNC 00001320 FUN_180001320 (60 bytes) ---- */

undefined8 * FUN_180001320(undefined8 *param_1,longlong param_2)

{
  *param_1 = std::exception::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  __std_exception_copy(param_2 + 8);
  *param_1 = std::bad_alloc::vftable;
  return param_1;
}

/* ---- FUNC 00001360 FUN_180001360 (60 bytes) ---- */

undefined8 * FUN_180001360(undefined8 *param_1,longlong param_2)

{
  *param_1 = std::exception::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  __std_exception_copy(param_2 + 8);
  *param_1 = std::bad_array_new_length::vftable;
  return param_1;
}

/* ---- FUNC 000013A0 FUN_1800013a0 (33 bytes) ---- */

undefined8 * FUN_1800013a0(undefined8 *param_1)

{
  param_1[2] = 0;
  param_1[1] = "bad array new length";
  *param_1 = std::bad_array_new_length::vftable;
  return param_1;
}

/* ---- FUNC 000013D0 exception (50 bytes) ---- */

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

/* ---- FUNC 00001410 FUN_180001410 (46 bytes) ---- */

void FUN_180001410(undefined8 *param_1)

{
  undefined8 *_Memory;
  
  _Memory = (undefined8 *)*param_1;
  while (_Memory != (undefined8 *)0x0) {
    *param_1 = *_Memory;
    free(_Memory);
    _Memory = (undefined8 *)*param_1;
  }
  return;
}

/* ---- FUNC 00001440 FUN_180001440 (94 bytes) ---- */

void FUN_180001440(longlong *param_1)

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
    FUN_180025ad0(pvVar2);
  }
  param_1[2] = 0;
  param_1[3] = 0xf;
  *(undefined1 *)param_1 = 0;
  return;
}

/* ---- FUNC 000014A0 FUN_1800014a0 (315 bytes) ---- */

void FUN_1800014a0(undefined8 *param_1)

{
  undefined8 *puVar1;
  AcpUntypedArray *this;
  void *pvVar2;
  void *pvVar3;
  
  *param_1 = CAdsNode::vftable;
  puVar1 = (undefined8 *)param_1[0x2d];
  if (puVar1 != (undefined8 *)0x0) {
    (**(code **)*puVar1)(puVar1,1);
    param_1[0x2d] = 0;
  }
  this = (AcpUntypedArray *)param_1[0x2e];
  if (this != (AcpUntypedArray *)0x0) {
    AcpUntypedArray::~AcpUntypedArray(this);
    FUN_180025ad0(this);
    param_1[0x2e] = 0;
  }
  if ((longlong *)param_1[0x38] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x38] + 0x10))();
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
  if (0xf < (ulonglong)param_1[0x36]) {
    pvVar2 = (void *)param_1[0x33];
    pvVar3 = pvVar2;
    if ((0xfff < param_1[0x36] + 1) &&
       (pvVar3 = *(void **)((longlong)pvVar2 + -8),
       0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar3)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180025ad0(pvVar3);
  }
  param_1[0x35] = 0;
  param_1[0x36] = 0xf;
  *(undefined1 *)(param_1 + 0x33) = 0;
  FUN_180058e50(param_1 + 0x26);
  FUN_180059cd0(param_1 + 0x1c);
  FUN_180058a30(param_1 + 0x14);
  FUN_180058ef0(param_1 + 0xf);
  return;
}

/* ---- FUNC 00001610 FUN_180001610 (359 bytes) ---- */

longlong * FUN_180001610(longlong *param_1,void *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  void *pvVar3;
  void *_Dst;
  ulonglong uVar4;
  void *pvVar5;
  ulonglong _Size;
  longlong *_Dst_00;
  ulonglong uVar6;
  
  _Size = 0xffffffffffffffff;
  do {
    _Size = _Size + 1;
  } while (*(char *)(_Size + (longlong)param_2) != '\0');
  uVar2 = param_1[3];
  if (uVar2 < _Size) {
    uVar6 = 0x7fffffffffffffff;
    if (0x7fffffffffffffff < _Size) {
                    /* WARNING: Subroutine does not return */
      FUN_180002780();
    }
    uVar4 = _Size | 0xf;
    if (uVar4 < 0x8000000000000000) {
      if (0x7fffffffffffffff - (uVar2 >> 1) < uVar2) {
        _Dst = (void *)FUN_180001160(0x8000000000000000);
      }
      else {
        uVar1 = (uVar2 >> 1) + uVar2;
        uVar6 = uVar4;
        if (uVar4 < uVar1) {
          uVar6 = uVar1;
        }
        uVar4 = uVar6 + 1;
        if (uVar4 < 0x1000) {
          if (uVar4 == 0) {
            _Dst = (void *)0x0;
          }
          else {
            _Dst = operator_new(uVar4);
          }
        }
        else {
          _Dst = (void *)FUN_180001160(uVar4);
        }
      }
    }
    else {
      _Dst = (void *)FUN_180001160(0x8000000000000000);
    }
    param_1[2] = _Size;
    param_1[3] = uVar6;
    memcpy(_Dst,param_2,_Size);
    *(undefined1 *)((longlong)_Dst + _Size) = 0;
    if (0xf < uVar2) {
      pvVar3 = (void *)*param_1;
      pvVar5 = pvVar3;
      if ((0xfff < uVar2 + 1) &&
         (pvVar5 = *(void **)((longlong)pvVar3 + -8),
         0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)pvVar5)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      FUN_180025ad0(pvVar5);
    }
    *param_1 = (longlong)_Dst;
  }
  else {
    _Dst_00 = param_1;
    if (0xf < uVar2) {
      _Dst_00 = (longlong *)*param_1;
    }
    param_1[2] = _Size;
    memmove(_Dst_00,param_2,_Size);
    *(undefined1 *)((longlong)_Dst_00 + _Size) = 0;
  }
  return param_1;
}

/* ---- FUNC 00001780 FUN_180001780 (437 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

VARIANTARG * FUN_180001780(VARIANTARG *param_1,LPCSTR param_2)

{
  char cVar1;
  HRESULT HVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  OLECHAR *pOVar6;
  BSTR pOVar7;
  OLECHAR *pOVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  ulonglong uVar11;
  OLECHAR *pOVar12;
  OLECHAR *psz;
  OLECHAR *pOVar13;
  undefined1 auStack_58 [48];
  OLECHAR *local_28;
  ulonglong local_20;
  
  puVar9 = auStack_58;
  local_20 = DAT_180077818 ^ (ulonglong)&local_28;
  pOVar12 = (OLECHAR *)0x0;
  pOVar8 = (OLECHAR *)0x0;
  local_28 = (OLECHAR *)0x0;
  HVar2 = VariantClear(param_1);
  if (HVar2 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_180001a90(HVar2);
  }
  (param_1->n1).n2.vt = 8;
  pOVar6 = pOVar12;
  puVar10 = auStack_58;
  psz = pOVar12;
  if (param_2 != (LPCSTR)0x0) {
    lVar4 = -1;
    do {
      lVar4 = lVar4 + 1;
    } while (param_2[lVar4] != '\0');
    lVar4 = (longlong)((int)lVar4 + 1) * 2;
    pOVar6 = pOVar8;
    puVar10 = auStack_58;
    if (lVar4 + 0x80000000U < 0x100000000) {
      iVar3 = (int)lVar4;
      uVar11 = (ulonglong)iVar3;
      if ((iVar3 < 0x401) && (cVar1 = FUN_1800026d0(uVar11), cVar1 != '\0')) {
        uVar5 = uVar11 + 0xf;
        if (uVar5 <= uVar11) {
          uVar5 = 0xffffffffffffff0;
        }
        pOVar8 = pOVar12;
        puVar9 = auStack_58 + -(uVar5 & 0xfffffffffffffff0);
        pOVar13 = (OLECHAR *)((longlong)&local_28 + -(uVar5 & 0xfffffffffffffff0));
      }
      else {
        if (~uVar11 < 0x10) {
                    /* WARNING: Subroutine does not return */
          FUN_180001a90(-0x7ff8fdea);
        }
        pOVar6 = malloc(uVar11 + 0x10);
        pOVar13 = pOVar12;
        if (pOVar6 != (OLECHAR *)0x0) {
          pOVar6[0] = L'\0';
          pOVar6[1] = L'\0';
          pOVar6[2] = L'\0';
          pOVar6[3] = L'\0';
          local_28 = pOVar6;
          pOVar8 = pOVar6;
          puVar9 = auStack_58;
          pOVar13 = pOVar6 + 8;
        }
      }
      pOVar6 = pOVar8;
      puVar10 = puVar9;
      if (pOVar13 != (OLECHAR *)0x0) {
        *pOVar13 = L'\0';
        *(int *)(puVar9 + 0x28) = (int)(uVar11 >> 1);
        *(OLECHAR **)(puVar9 + 0x20) = pOVar13;
        *(undefined8 *)(puVar9 + -8) = 0x1800018a0;
        iVar3 = MultiByteToWideChar(0,0,param_2,-1,*(LPWSTR *)(puVar9 + 0x20),
                                    *(int *)(puVar9 + 0x28));
        psz = pOVar13;
        if (iVar3 == 0) {
          psz = pOVar12;
        }
      }
    }
  }
  *(undefined8 *)(puVar10 + -8) = 0x1800018b2;
  pOVar7 = SysAllocString(psz);
  (param_1->n1).decVal.u2.Lo64 = (ULONGLONG)pOVar7;
  if ((pOVar7 == (BSTR)0x0) && (param_2 != (LPCSTR)0x0)) {
    (param_1->n1).n2.vt = 10;
    *(undefined4 *)((longlong)&param_1->n1 + 8) = 0x8007000e;
                    /* WARNING: Subroutine does not return */
    *(undefined **)(puVar10 + -8) = &UNK_180001935;
    FUN_180001a90(-0x7ff8fff2);
  }
  while (pOVar6 != (OLECHAR *)0x0) {
    pOVar8 = *(OLECHAR **)pOVar6;
    *(undefined8 *)(puVar10 + -8) = 0x1800018dc;
    free(pOVar6);
    pOVar6 = pOVar8;
  }
  *(undefined8 *)(puVar10 + -8) = 0x1800018f0;
  return param_1;
}

/* ---- FUNC 00001940 FUN_180001940 (53 bytes) ---- */

AcpBase * FUN_180001940(AcpBase *param_1,uint param_2)

{
  AcpBase::~AcpBase(param_1);
  if ((param_2 & 1) != 0) {
    FUN_180025ad0(param_1);
  }
  return param_1;
}

/* ---- FUNC 00001980 FUN_180001980 (66 bytes) ---- */

undefined8 * FUN_180001980(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = std::exception::vftable;
  __std_exception_destroy(param_1 + 1);
  if ((param_2 & 1) != 0) {
    FUN_180025ad0(param_1);
  }
  return param_1;
}

/* ---- FUNC 000019D0 FUN_1800019d0 (21 bytes) ---- */

BSTR FUN_1800019d0(LPCSTR param_1)

{
  int cchWideChar;
  int iVar1;
  BSTR lpWideCharStr;
  
  if (param_1 == (LPCSTR)0x0) {
    return (BSTR)0x0;
  }
  cchWideChar = MultiByteToWideChar(0,0,param_1,-1,(LPWSTR)0x0,0);
  lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,cchWideChar - 1);
  if (lpWideCharStr != (BSTR)0x0) {
    iVar1 = MultiByteToWideChar(0,0,param_1,-1,lpWideCharStr,cchWideChar);
    if (iVar1 != cchWideChar) {
      SysFreeString(lpWideCharStr);
      return (BSTR)0x0;
    }
  }
  return lpWideCharStr;
}

/* ---- FUNC 000019E5 FUN_1800019e5 (123 bytes) ---- */

BSTR FUN_1800019e5(undefined8 param_1,undefined8 param_2,LPCSTR param_3)

{
  int cchWideChar;
  int iVar1;
  BSTR lpWideCharStr;
  LPCSTR unaff_RDI;
  
  cchWideChar = MultiByteToWideChar(0,0,param_3,-1,(LPWSTR)0x0,0);
  lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,cchWideChar - 1);
  if (lpWideCharStr != (BSTR)0x0) {
    iVar1 = MultiByteToWideChar(0,0,unaff_RDI,-1,lpWideCharStr,cchWideChar);
    if (iVar1 != cchWideChar) {
      SysFreeString(lpWideCharStr);
      return (BSTR)0x0;
    }
  }
  return lpWideCharStr;
}

/* ---- FUNC 00001A60 FUN_180001a60 (19 bytes) ---- */

void FUN_180001a60(void)

{
  return;
}

/* ---- FUNC 00001A73 FUN_180001a73 (8 bytes) ---- */

undefined8 FUN_180001a73(void)

{
  return 0;
}

/* ---- FUNC 00001A80 FUN_180001a80 (9 bytes) ---- */

void FUN_180001a80(longlong param_1)

{
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  return;
}

/* ---- FUNC 00001A90 FUN_180001a90 (24 bytes) ---- */

void FUN_180001a90(long param_1)

{
  code *pcVar1;
  
  if (param_1 == -0x7ff8fff2) {
                    /* WARNING: Subroutine does not return */
    AfxThrowMemoryException();
  }
  AfxThrowOleException(param_1);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

/* ---- FUNC 00001AB0 FUN_180001ab0 (293 bytes) ---- */

undefined8
FUN_180001ab0(AcpBase *param_1,longlong *param_2,undefined8 *param_3,longlong *param_4,
             longlong param_5)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  AcpBase *this;
  AString *this_00;
  char *pcVar4;
  AString local_28 [16];
  
  puVar2 = operator_new(0x1d0);
  if (puVar2 == (undefined8 *)0x0) {
    plVar3 = (longlong *)0x0;
  }
  else {
    plVar3 = FUN_1800011a0(puVar2);
  }
  plVar3[0x2c] = (longlong)param_4;
  (**(code **)(*param_4 + 8))(param_4);
  plVar3[0x38] = param_5;
  *(undefined4 *)(plVar3 + 0x39) = 0;
  lVar1 = param_2[1];
  plVar3[0x30] = *param_2;
  plVar3[0x31] = lVar1;
  plVar3[0x32] = param_2[2];
  if (param_1 == (AcpBase *)0x0) {
    FUN_180001610(plVar3 + 0x33,"SharedData");
  }
  else {
    this = operator_new(0x58);
    if (this == (AcpBase *)0x0) {
      this = (AcpBase *)0x0;
    }
    else {
      AcpBase::AcpBase(this,param_1);
      *(undefined ***)this = AcpBase::vftable;
    }
    plVar3[0x2d] = (longlong)this;
    this_00 = (AString *)AcpBase::StringId(param_1);
    pcVar4 = AString::CValue(this_00);
    FUN_180001610(plVar3 + 0x33,pcVar4);
    AString::~AString(local_28);
  }
  *param_3 = plVar3;
  (**(code **)(*plVar3 + 8))(plVar3);
  return 0;
}

/* ---- FUNC 00001BE0 FUN_180001be0 (218 bytes) ---- */

undefined8
FUN_180001be0(AcpUntypedArray *param_1,undefined4 *param_2,undefined8 *param_3,longlong *param_4,
             longlong param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  AcpUntypedArray *this;
  longlong *plVar6;
  
  puVar4 = operator_new(0x1d0);
  plVar6 = (longlong *)0x0;
  plVar5 = plVar6;
  if (puVar4 != (undefined8 *)0x0) {
    plVar5 = FUN_1800011a0(puVar4);
  }
  plVar5[0x2c] = (longlong)param_4;
  (**(code **)(*param_4 + 8))(param_4);
  plVar5[0x38] = param_5;
  *(undefined4 *)(plVar5 + 0x39) = 0;
  uVar1 = param_2[1];
  uVar2 = param_2[2];
  uVar3 = param_2[3];
  *(undefined4 *)(plVar5 + 0x30) = *param_2;
  *(undefined4 *)((longlong)plVar5 + 0x184) = uVar1;
  *(undefined4 *)(plVar5 + 0x31) = uVar2;
  *(undefined4 *)((longlong)plVar5 + 0x18c) = uVar3;
  plVar5[0x32] = *(longlong *)(param_2 + 4);
  if (param_1 != (AcpUntypedArray *)0x0) {
    this = operator_new(0x48);
    if (this != (AcpUntypedArray *)0x0) {
      plVar6 = (longlong *)AcpUntypedArray::AcpUntypedArray(this,param_1);
    }
    plVar5[0x2e] = (longlong)plVar6;
  }
  *param_3 = plVar5;
  (**(code **)(*plVar5 + 8))(plVar5);
  return 0;
}

/* ---- FUNC 00001CC0 FUN_180001cc0 (58 bytes) ---- */

undefined8 FUN_180001cc0(longlong *param_1,wchar_t *param_2,undefined8 *param_3)

{
  ulonglong uVar1;
  int iVar2;
  undefined8 uVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar4;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar5;
  ulonglong uVar6;
  uint uVar7;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res20 [8];
  LPCSTR local_1d8;
  longlong *local_1d0;
  _union_2707 local_1c8;
  _union_2707 local_1b0;
  _union_2707 local_198;
  _union_2707 local_180;
  undefined8 local_168;
  undefined8 local_160;
  undefined8 local_158;
  undefined8 local_150;
  longlong *local_148;
  CStringArray local_140 [8];
  longlong local_138;
  ulonglong local_130;
  _union_2707 local_118;
  undefined8 local_100;
  _union_1719 _Stack_f8;
  undefined8 local_f0;
  _union_1719 _Stack_e8;
  undefined8 local_e0;
  _union_1719 _Stack_d8;
  undefined8 local_d0;
  _union_1719 _Stack_c8;
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
  uint local_38;
  ULONG UStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined8 local_28;
  ulonglong uVar8;
  
  if (DAT_1800797f8 != 0) {
    uVar3 = (**(code **)(*param_1 + 0x78))(param_1,0x7f3);
    return uVar3;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20,param_2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Trim(local_res20,'\\');
  CStringArray::CStringArray(local_140);
  while (iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                           (local_res20,'\\',0), -1 < iVar2) {
    pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                       (local_res20,(int)&local_1d0);
    CStringArray::SetAtGrow(local_140,local_130,pCVar4);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1d0);
    pCVar5 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Right
                       (local_res20,(int)&local_1d8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              (local_res20,pCVar5);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1d8);
  }
  CStringArray::SetAtGrow(local_140,local_130,local_res20);
  uVar1 = local_130;
  uVar6 = 0;
  if (local_130 == 0) {
    *param_3 = 0;
  }
  else {
    uVar8 = uVar6;
    if (local_130 != 0) {
      do {
        if (((longlong)uVar6 < 0) || ((longlong)local_130 <= (longlong)uVar6)) {
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1d8,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   (local_138 + uVar6 * 8));
        local_1d0 = (longlong *)0x0;
        iVar2 = (**(code **)(*param_1 + 0x38))(param_1,&local_1d0);
        if (iVar2 < 0) {
          *param_3 = 0;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1d8);
          goto LAB_18000205d;
        }
        local_180._0_8_ = 0;
        local_180.decVal.u2.Lo64 = (_union_1719)0x0;
        local_180._16_8_ = 0;
        VariantInit((VARIANTARG *)&local_180.n2);
        local_198._0_8_ = 0;
        local_198.decVal.u2.Lo64 = (_union_1719)0x0;
        local_198._16_8_ = 0;
        VariantInit((VARIANTARG *)&local_198.n2);
        local_1b0._0_8_ = 0;
        local_1b0.decVal.u2.Lo64 = (_union_1719)0x0;
        local_1b0._16_8_ = 0;
        VariantInit((VARIANTARG *)&local_1b0.n2);
        local_1c8._0_8_ = 0;
        local_1c8.decVal.u2.Lo64 = (_union_1719)0x0;
        local_1c8._16_8_ = 0;
        VariantInit((VARIANTARG *)&local_1c8.n2);
        local_118._0_4_ = local_118._0_4_ & 0xffff0000;
        local_100 = local_1c8._0_8_;
        _Stack_f8.Lo64 = (ULONGLONG)local_1c8.decVal.u2;
        local_168 = local_1c8._16_8_;
        local_f0 = local_1b0._0_8_;
        _Stack_e8.Lo64 = (ULONGLONG)local_1b0.decVal.u2;
        local_160 = local_1b0._16_8_;
        local_e0 = local_198._0_8_;
        _Stack_d8.Lo64 = (ULONGLONG)local_198.decVal.u2;
        local_158 = local_198._16_8_;
        local_d0 = local_180._0_8_;
        _Stack_c8 = local_180.decVal.u2;
        local_150 = local_180._16_8_;
        FUN_180001780((VARIANTARG *)&local_118.n2,local_1d8);
        local_b8 = local_100;
        _Stack_b0.s2 = _Stack_f8.s2;
        local_a8 = local_168;
        local_98 = local_f0;
        _Stack_90 = _Stack_e8;
        local_88 = local_160;
        local_28 = local_118._16_8_;
        local_78 = local_e0;
        _Stack_70 = _Stack_d8;
        local_68 = local_158;
        local_58 = local_d0;
        _Stack_50 = _Stack_c8;
        local_48 = local_150;
        local_38 = local_118._0_4_;
        UStack_34 = local_118.decVal.Hi32;
        uStack_30 = local_118._8_4_;
        uStack_2c = local_118._12_4_;
        iVar2 = (**(code **)(*local_1d0 + 0x38))
                          (local_1d0,&local_38,&local_58,&local_78,&local_98,&local_b8,&local_148);
        VariantClear((VARIANTARG *)&local_118.n2);
        param_1 = local_148;
        if (iVar2 < 0) {
          *param_3 = 0;
          VariantClear((VARIANTARG *)&local_1c8.n2);
          VariantClear((VARIANTARG *)&local_1b0.n2);
          VariantClear((VARIANTARG *)&local_198.n2);
          VariantClear((VARIANTARG *)&local_180.n2);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1d8);
          goto LAB_18000205d;
        }
        VariantClear((VARIANTARG *)&local_1c8.n2);
        VariantClear((VARIANTARG *)&local_1b0.n2);
        VariantClear((VARIANTARG *)&local_198.n2);
        VariantClear((VARIANTARG *)&local_180.n2);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1d8);
        uVar7 = (int)uVar8 + 1;
        uVar8 = (ulonglong)uVar7;
        uVar6 = (ulonglong)(int)uVar7;
      } while (uVar6 < uVar1);
    }
    *param_3 = param_1;
    (**(code **)(*param_1 + 8))(param_1);
  }
LAB_18000205d:
  CStringArray::~CStringArray(local_140);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20);
  return 0;
}

/* ---- FUNC 00001CFA FUN_180001cfa (927 bytes) ---- */

undefined8 FUN_180001cfa(undefined8 param_1,wchar_t *param_2)

{
  undefined8 uVar1;
  ulonglong uVar2;
  longlong lVar3;
  ULONG UVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  _union_1719 _Var7;
  undefined8 uVar8;
  int iVar9;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar10;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  longlong *unaff_RBX;
  VARIANTARG *unaff_RBP;
  uint uVar14;
  ulonglong uVar15;
  undefined8 *unaff_R15;
  LPCSTR in_stack_00000040;
  longlong *in_stack_00000048;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000078;
  
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + 0xd),
             param_2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Trim
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + 0xd),'\\'
            );
  CStringArray::CStringArray((CStringArray *)((longlong)&unaff_RBP[-2].n1 + 8));
  while (iVar9 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                           ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            (unaff_RBP + 0xd),'\\',0), -1 < iVar9) {
    pCVar10 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         (unaff_RBP + 0xd),(int)&stack0x00000048);
    CStringArray::SetAtGrow
              ((CStringArray *)((longlong)&unaff_RBP[-2].n1 + 8),*(__int64 *)&unaff_RBP[-1].n1,
               pCVar10);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000048);
    pCVar11 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Right
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         (unaff_RBP + 0xd),(int)&stack0x00000040);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + 0xd),
               pCVar11);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000040);
  }
  CStringArray::SetAtGrow
            ((CStringArray *)((longlong)&unaff_RBP[-2].n1 + 8),*(__int64 *)&unaff_RBP[-1].n1,
             (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + 0xd));
  uVar2 = *(ulonglong *)&unaff_RBP[-1].n1;
  uVar12 = 0;
  if (uVar2 == 0) {
    *unaff_R15 = 0;
  }
  else {
    uVar13 = uVar2;
    uVar15 = uVar12;
    if (uVar2 == 0) {
LAB_180002051:
      *unaff_R15 = unaff_RBX;
      (**(code **)(*unaff_RBX + 8))(unaff_RBX);
    }
    else {
      while( true ) {
        if (((longlong)uVar12 < 0) || ((longlong)uVar13 <= (longlong)uVar12)) {
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000040
                   ,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                    (*(longlong *)((longlong)&unaff_RBP[-2].n1 + 0x10) + uVar12 * 8));
        in_stack_00000048 = (longlong *)0x0;
        iVar9 = (**(code **)(*unaff_RBX + 0x38))(unaff_RBX,&stack0x00000048);
        if (iVar9 < 0) break;
        *(undefined8 *)((longlong)&unaff_RBP[-5].n1 + 0x10) = 0;
        *(undefined8 *)&unaff_RBP[-4].n1 = 0;
        unaff_RBP[-4].n1.decVal.u2.Lo64 = 0;
        VariantInit((VARIANTARG *)((longlong)&unaff_RBP[-5].n1 + 0x10));
        *(undefined8 *)((longlong)&unaff_RBP[-6].n1 + 0x10) = 0;
        *(undefined8 *)&unaff_RBP[-5].n1 = 0;
        unaff_RBP[-5].n1.decVal.u2.Lo64 = 0;
        VariantInit((VARIANTARG *)((longlong)&unaff_RBP[-6].n1 + 0x10));
        in_stack_00000068 = 0;
        in_stack_00000070 = (_union_1719)0x0;
        in_stack_00000078 = 0;
        VariantInit((VARIANTARG *)&stack0x00000068);
        in_stack_00000050 = 0;
        in_stack_00000058 = (_union_1719)0x0;
        in_stack_00000060 = 0;
        VariantInit((VARIANTARG *)&stack0x00000050);
        (unaff_RBP->n1).n2.vt = 0;
        *(undefined8 *)&unaff_RBP[1].n1 = in_stack_00000050;
        unaff_RBP[1].n1.decVal.u2.Lo64 = in_stack_00000058;
        *(undefined8 *)((longlong)&unaff_RBP[-4].n1 + 0x10) = in_stack_00000060;
        *(undefined8 *)((longlong)&unaff_RBP[1].n1 + 0x10) = in_stack_00000068;
        ((_union_1719 *)(unaff_RBP + 2))->Lo64 = in_stack_00000070;
        *(undefined8 *)&unaff_RBP[-3].n1 = in_stack_00000078;
        uVar1 = *(undefined8 *)&unaff_RBP[-5].n1;
        unaff_RBP[2].n1.decVal.u2 = *(_union_1719 *)((longlong)&unaff_RBP[-6].n1 + 0x10);
        *(undefined8 *)((longlong)&unaff_RBP[2].n1 + 0x10) = uVar1;
        unaff_RBP[-3].n1.decVal.u2 = unaff_RBP[-5].n1.decVal.u2;
        *(undefined8 *)&unaff_RBP[3].n1 = *(undefined8 *)((longlong)&unaff_RBP[-5].n1 + 0x10);
        unaff_RBP[3].n1.decVal.u2 = *(_union_1719 *)&unaff_RBP[-4].n1;
        *(_union_1719 *)((longlong)&unaff_RBP[-3].n1 + 0x10) = unaff_RBP[-4].n1.decVal.u2;
        FUN_180001780(unaff_RBP,in_stack_00000040);
        _Var7 = unaff_RBP[1].n1.decVal.u2;
        uVar1 = *(undefined8 *)((longlong)&unaff_RBP->n1 + 0x10);
        *(undefined8 *)&unaff_RBP[4].n1 = *(undefined8 *)&unaff_RBP[1].n1;
        unaff_RBP[4].n1.decVal.u2 = _Var7;
        lVar3 = *in_stack_00000048;
        *(undefined8 *)((longlong)&unaff_RBP[4].n1 + 0x10) =
             *(undefined8 *)((longlong)&unaff_RBP[-4].n1 + 0x10);
        uVar8 = *(undefined8 *)&unaff_RBP[2].n1;
        unaff_RBP[5].n1.decVal.u2 = *(_union_1719 *)((longlong)&unaff_RBP[1].n1 + 0x10);
        *(undefined8 *)((longlong)&unaff_RBP[5].n1 + 0x10) = uVar8;
        *(undefined8 *)&unaff_RBP[6].n1 = *(undefined8 *)&unaff_RBP[-3].n1;
        _Var7 = unaff_RBP[2].n1.decVal.u2;
        uVar8 = *(undefined8 *)((longlong)&unaff_RBP[2].n1 + 0x10);
        *(undefined8 *)&unaff_RBP[10].n1 = uVar1;
        *(_union_1719 *)((longlong)&unaff_RBP[6].n1 + 0x10) = _Var7;
        *(undefined8 *)&unaff_RBP[7].n1 = uVar8;
        unaff_RBP[7].n1.decVal.u2 = unaff_RBP[-3].n1.decVal.u2;
        _Var7 = unaff_RBP[3].n1.decVal.u2;
        *(undefined8 *)&unaff_RBP[8].n1 = *(undefined8 *)&unaff_RBP[3].n1;
        unaff_RBP[8].n1.decVal.u2 = _Var7;
        *(undefined8 *)((longlong)&unaff_RBP[8].n1 + 0x10) =
             *(undefined8 *)((longlong)&unaff_RBP[-3].n1 + 0x10);
        UVar4 = (unaff_RBP->n1).decVal.Hi32;
        uVar5 = *(undefined4 *)((longlong)&unaff_RBP->n1 + 8);
        uVar6 = *(undefined4 *)((longlong)&unaff_RBP->n1 + 0xc);
        *(undefined4 *)((longlong)&unaff_RBP[9].n1 + 8) = *(undefined4 *)&unaff_RBP->n1;
        *(ULONG *)((longlong)&unaff_RBP[9].n1 + 0xc) = UVar4;
        *(undefined4 *)((longlong)&unaff_RBP[9].n1 + 0x10) = uVar5;
        *(undefined4 *)((longlong)&unaff_RBP[9].n1 + 0x14) = uVar6;
        iVar9 = (**(code **)(lVar3 + 0x38))
                          (in_stack_00000048,(undefined1 *)((longlong)&unaff_RBP[9].n1 + 8),
                           unaff_RBP + 8,(undefined1 *)((longlong)&unaff_RBP[6].n1 + 0x10),
                           (undefined1 *)((longlong)&unaff_RBP[5].n1 + 8));
        VariantClear(unaff_RBP);
        if (iVar9 < 0) {
          *unaff_R15 = 0;
          VariantClear((VARIANTARG *)&stack0x00000050);
          VariantClear((VARIANTARG *)&stack0x00000068);
          VariantClear((VARIANTARG *)((longlong)&unaff_RBP[-6].n1 + 0x10));
          VariantClear((VARIANTARG *)((longlong)&unaff_RBP[-5].n1 + 0x10));
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                     &stack0x00000040);
          goto LAB_18000205d;
        }
        unaff_RBX = *(longlong **)&unaff_RBP[-2].n1;
        VariantClear((VARIANTARG *)&stack0x00000050);
        VariantClear((VARIANTARG *)&stack0x00000068);
        VariantClear((VARIANTARG *)((longlong)&unaff_RBP[-6].n1 + 0x10));
        VariantClear((VARIANTARG *)((longlong)&unaff_RBP[-5].n1 + 0x10));
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000040
                  );
        uVar14 = (int)uVar15 + 1;
        uVar12 = (ulonglong)(int)uVar14;
        if (uVar2 <= uVar12) goto LAB_180002051;
        uVar13 = *(ulonglong *)&unaff_RBP[-1].n1;
        uVar15 = (ulonglong)uVar14;
      }
      *unaff_R15 = 0;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000040);
    }
  }
LAB_18000205d:
  CStringArray::~CStringArray((CStringArray *)((longlong)&unaff_RBP[-2].n1 + 8));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + 0xd));
  return 0;
}

/* ---- FUNC 00002099 AfxThrowInvalidArgException (5 bytes) ---- */

void __cdecl AfxThrowInvalidArgException(void)

{
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 000020A0 FUN_1800020a0 (28 bytes) ---- */

void FUN_1800020a0(undefined8 param_1,undefined8 param_2,OLECHAR **param_3,UINT param_4,
                  undefined8 param_5,DISPID *param_6)

{
                    /* WARNING: Could not recover jumptable at 0x0001800020b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DispGetIDsOfNames(DAT_1800791e0,param_3,param_4,param_6);
  return;
}

/* ---- FUNC 000020C0 FUN_1800020c0 (62 bytes) ---- */

undefined8 FUN_1800020c0(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  *param_4 = 0;
  if (param_2 != 0) {
    return 0x8002000b;
  }
  (**(code **)(*DAT_1800791e0 + 8))();
  *param_4 = DAT_1800791e0;
  return 0;
}

/* ---- FUNC 00002100 FUN_180002100 (9 bytes) ---- */

undefined8 FUN_180002100(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 1;
  return 0;
}

/* ---- FUNC 00002110 FUN_180002110 (168 bytes) ---- */

HRESULT FUN_180002110(void *param_1,DISPID param_2,undefined8 param_3,undefined8 param_4,
                     WORD param_5,DISPPARAMS *param_6,VARIANT *param_7,EXCEPINFO *param_8,
                     UINT *param_9)

{
  undefined8 uVar1;
  BSTR pOVar2;
  PVOID pvVar3;
  HRESULT HVar4;
  
  *(undefined4 *)((longlong)param_1 + 0x70) = 0;
  HVar4 = DispInvoke(param_1,DAT_1800791e0,param_2,param_5,param_6,param_7,param_8,param_9);
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

/* ---- FUNC 000021C0 FUN_1800021c0 (112 bytes) ---- */

undefined8 FUN_1800021c0(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  *param_3 = 0;
  if ((((*param_2 != DAT_180066c58) || (param_2[1] != DAT_180066c60)) &&
      ((*param_2 != DAT_180066c78 || (param_2[1] != DAT_180066c80)))) &&
     ((*param_2 != DAT_1800634b0 || (param_2[1] != DAT_1800634b8)))) {
    return 0x80004002;
  }
  *param_3 = param_1;
  (**(code **)(*param_1 + 8))();
  return 0;
}

/* ---- FUNC 00002230 FUN_180002230 (401 bytes) ---- */

undefined8 FUN_180002230(longlong param_1,uint param_2)

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
    (*local_res8->lpVtbl->SetGUID)(local_res8,(GUID *)&DAT_180063400);
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

/* ---- FUNC 000023D0 FUN_1800023d0 (40 bytes) ---- */

undefined8 FUN_1800023d0(longlong *param_1,undefined8 *param_2)

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
    uVar3 = (**(code **)(*param_1 + 0x78))(param_1,0x7d1);
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
      goto LAB_180002521;
    }
    pOVar4 = SysAllocStringLen(pOVar5,(UINT)lVar7);
  }
  param_1[7] = (longlong)pOVar4;
LAB_180002521:
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

/* ---- FUNC 000023F8 FUN_1800023f8 (333 bytes) ---- */

undefined8 FUN_1800023f8(BSTR param_1)

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
      goto LAB_180002521;
    }
    pOVar3 = SysAllocStringLen(pOVar4,(UINT)lVar6);
  }
  *(BSTR *)(unaff_RBX + 0x38) = pOVar3;
LAB_180002521:
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

/* ---- FUNC 00002545 FUN_180002545 (151 bytes) ---- */

undefined8 FUN_180002545(void)

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

/* ---- FUNC 000025E0 FUN_1800025e0 (234 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_1800025e0(undefined8 *param_1)

{
  int *piVar1;
  DWORD DVar2;
  undefined8 uVar3;
  undefined1 auStack_428 [32];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_180077818 ^ (ulonglong)auStack_428;
  if (DAT_1800797e8 != (HANDLE)0x0) {
    DVar2 = WaitForSingleObject(DAT_1800797e8,100);
    if (DVar2 == 0x102) {
      uVar3 = 0xb2;
      FUN_180002a20(local_408,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\AdsNode.cpp",0xb2);
      LogMessage(local_408,2,1);
      DVar2 = GetLastError();
      FUN_180002a20(local_408,"CAdsNode: Release --- LastError: %d",(ulonglong)DVar2,uVar3);
      LogMessage(local_408,0,1);
    }
    piVar1 = (int *)(param_1 + 1);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      FUN_1800014a0(param_1);
      FUN_180025ad0(param_1);
      return 0;
    }
    ReleaseSemaphore(DAT_1800797e8,1,(LPLONG)0x0);
  }
  return *(undefined4 *)(param_1 + 1);
}

/* ---- FUNC 000026D0 FUN_1800026d0 (132 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 FUN_1800026d0(ulonglong param_1)

{
  ulonglong uVar1;
  undefined1 uVar2;
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
  *(undefined8 *)(puVar3 + -8) = 0x18000274a;
  return uVar2;
}

/* ---- FUNC 00002760 FUN_180002760 (31 bytes) ---- */

void FUN_180002760(void)

{
  undefined8 local_28 [5];
  
  FUN_1800013a0(local_28);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_28,(ThrowInfo *)&DAT_180072aa8);
}

/* ---- FUNC 00002780 FUN_180002780 (16 bytes) ---- */

void FUN_180002780(void)

{
                    /* WARNING: Subroutine does not return */
  std::_Xlength_error("string too long");
}

/* ---- FUNC 000027A0 _guard_check_icall (3 bytes) ---- */

void _guard_check_icall(void)

{
  return;
}

/* ---- FUNC 000027B0 FUN_1800027b0 (107 bytes) ---- */

undefined8 FUN_1800027b0(longlong *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0001800027db. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x78))(param_1,0x7f3);
    return uVar1;
  }
  puVar2 = operator_new(0x160);
  puVar3 = (undefined8 *)0x0;
  if (puVar2 != (undefined8 *)0x0) {
    puVar3 = FUN_180002a80(puVar2,param_1);
  }
  *param_2 = puVar3;
  (**(code **)(*param_1 + 8))(param_1);
  (**(code **)(*(longlong *)*param_2 + 8))();
  return 0;
}

/* ---- FUNC 00002820 FUN_180002820 (68 bytes) ---- */

undefined8 FUN_180002820(longlong *param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  BSTR pOVar2;
  longlong *plVar3;
  
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018000283f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x78))(param_1,0x7f3);
    return uVar1;
  }
  plVar3 = param_1 + 0x33;
  if (0xf < (ulonglong)param_1[0x36]) {
    plVar3 = (longlong *)*plVar3;
  }
  pOVar2 = FUN_1800019d0((LPCSTR)plVar3);
  *param_3 = pOVar2;
  return 0;
}

/* ---- FUNC 00002870 FUN_180002870 (33 bytes) ---- */

undefined8 FUN_180002870(longlong *param_1,undefined8 param_2,undefined4 *param_3)

{
  undefined8 uVar1;
  
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x000180002881. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x78))(param_1,0x7f3);
    return uVar1;
  }
  *param_3 = *(undefined4 *)((longlong)param_1 + 0x1bc);
  return 0;
}

/* ---- FUNC 000028A0 FUN_1800028a0 (78 bytes) ---- */

undefined8 FUN_1800028a0(longlong *param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  LPCSTR pCVar2;
  BSTR pOVar3;
  
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0001800028bf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x78))(param_1,0x7f3);
    return uVar1;
  }
  pCVar2 = FUN_18001d4a0(param_1[0x2c],*(int *)((longlong)param_1 + 0x1bc),1);
  pOVar3 = FUN_1800019d0(pCVar2);
  *param_3 = pOVar3;
  return 0;
}

/* ---- FUNC 000028F0 FUN_1800028f0 (49 bytes) ---- */

undefined8 FUN_1800028f0(longlong *param_1,undefined8 param_2,longlong *param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x000180002901. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(*param_1 + 0x78))(param_1,0x7f3);
    return uVar2;
  }
  lVar1 = param_1[0x31];
  *param_3 = param_1[0x30];
  param_3[1] = lVar1;
  param_3[2] = param_1[0x32];
  return 0;
}

/* ---- FUNC 00002930 FUN_180002930 (107 bytes) ---- */

undefined8 FUN_180002930(longlong *param_1,undefined2 *param_2)

{
  undefined8 uVar1;
  
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x000180002941. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x78))(param_1,0x7f3);
    return uVar1;
  }
  switch((char)param_1[0x37]) {
  case 'A':
  case 'a':
    *param_2 = 6;
    break;
  case 'b':
  case 'i':
    *param_2 = 1;
    return 0;
  case 'c':
    *param_2 = 3;
    return 0;
  case 'f':
    *param_2 = 5;
    return 0;
  case 'r':
    *param_2 = 2;
    return 0;
  }
  return 0;
}

/* ---- FUNC 000029F0 FUN_1800029f0 (19 bytes) ---- */

char * FUN_1800029f0(longlong param_1)

{
  char *pcVar1;
  
  pcVar1 = "Unknown exception";
  if (*(char **)(param_1 + 8) != (char *)0x0) {
    pcVar1 = *(char **)(param_1 + 8);
  }
  return pcVar1;
}

/* ---- FUNC 00002A10 FUN_180002a10 (8 bytes) ---- */

undefined * FUN_180002a10(void)

{
  return &DAT_1800791f0;
}

/* ---- FUNC 00002A20 FUN_180002a20 (94 bytes) ---- */

int FUN_180002a20(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong *puVar2;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  puVar2 = (ulonglong *)FUN_180002a10();
  iVar1 = __stdio_common_vsprintf(*puVar2 | 1,param_1,0xffffffffffffffff,param_2,0,&local_res18);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  return iVar1;
}

/* ---- FUNC 00002A80 FUN_180002a80 (188 bytes) ---- */

undefined8 * FUN_180002a80(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = CAdsNodeCol::vftable;
  *(undefined4 *)(param_1 + 1) = 0;
  FUN_1800212f0(param_1 + 2,param_1,&DAT_180063400);
  FUN_180058ec0(param_1 + 0xf,param_1,param_1,0);
  FUN_1800589e0(param_1 + 0x14,param_1,param_1,0);
  FUN_180059ca0(param_1 + 0x1c,param_1,param_1,0);
  FUN_180058e20(param_1 + 0x26,param_1,param_1,0);
  param_1[0x2b] = param_2;
  *(undefined4 *)(param_1 + 1) = 0;
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

/* ---- FUNC 00002B40 FUN_180002b40 (69 bytes) ---- */

void FUN_180002b40(undefined8 *param_1)

{
  *param_1 = CAdsNodeCol::vftable;
  FUN_180058e50(param_1 + 0x26);
  FUN_180059cd0(param_1 + 0x1c);
  FUN_180058a30(param_1 + 0x14);
  FUN_180058ef0(param_1 + 0xf);
  return;
}

/* ---- FUNC 00002B90 FUN_180002b90 (28 bytes) ---- */

void FUN_180002b90(undefined8 param_1,undefined8 param_2,OLECHAR **param_3,UINT param_4,
                  undefined8 param_5,DISPID *param_6)

{
                    /* WARNING: Could not recover jumptable at 0x000180002ba5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DispGetIDsOfNames(DAT_1800791f8,param_3,param_4,param_6);
  return;
}

/* ---- FUNC 00002BB0 FUN_180002bb0 (62 bytes) ---- */

undefined8 FUN_180002bb0(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  *param_4 = 0;
  if (param_2 != 0) {
    return 0x8002000b;
  }
  (**(code **)(*DAT_1800791f8 + 8))();
  *param_4 = DAT_1800791f8;
  return 0;
}

/* ---- FUNC 00002BF0 FUN_180002bf0 (168 bytes) ---- */

HRESULT FUN_180002bf0(void *param_1,DISPID param_2,undefined8 param_3,undefined8 param_4,
                     WORD param_5,DISPPARAMS *param_6,VARIANT *param_7,EXCEPINFO *param_8,
                     UINT *param_9)

{
  undefined8 uVar1;
  BSTR pOVar2;
  PVOID pvVar3;
  HRESULT HVar4;
  
  *(undefined4 *)((longlong)param_1 + 0x70) = 0;
  HVar4 = DispInvoke(param_1,DAT_1800791f8,param_2,param_5,param_6,param_7,param_8,param_9);
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

/* ---- FUNC 00002CA0 FUN_180002ca0 (112 bytes) ---- */

undefined8 FUN_180002ca0(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  *param_3 = 0;
  if ((((*param_2 != DAT_180066c58) || (param_2[1] != DAT_180066c60)) &&
      ((*param_2 != DAT_180066c78 || (param_2[1] != DAT_180066c80)))) &&
     ((*param_2 != DAT_1800634c0 || (param_2[1] != DAT_1800634c8)))) {
    return 0x80004002;
  }
  *param_3 = param_1;
  (**(code **)(*param_1 + 8))();
  return 0;
}

/* ---- FUNC 00002D10 FUN_180002d10 (40 bytes) ---- */

undefined8 FUN_180002d10(longlong *param_1,undefined8 *param_2)

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
    uVar3 = (**(code **)(*param_1 + 0x58))(param_1,0x7d1);
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
      goto LAB_180002e61;
    }
    pOVar4 = SysAllocStringLen(pOVar5,(UINT)lVar7);
  }
  param_1[7] = (longlong)pOVar4;
LAB_180002e61:
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

/* ---- FUNC 00002D38 FUN_180002d38 (333 bytes) ---- */

undefined8 FUN_180002d38(BSTR param_1)

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
      goto LAB_180002e61;
    }
    pOVar3 = SysAllocStringLen(pOVar4,(UINT)lVar6);
  }
  *(BSTR *)(unaff_RBX + 0x38) = pOVar3;
LAB_180002e61:
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

/* ---- FUNC 00002E85 FUN_180002e85 (151 bytes) ---- */

undefined8 FUN_180002e85(void)

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

/* ---- FUNC 00002F20 FUN_180002f20 (189 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_180002f20(undefined8 *param_1)

{
  int *piVar1;
  DWORD DVar2;
  undefined1 auStack_428 [32];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_180077818 ^ (ulonglong)auStack_428;
  if (DAT_1800797e8 != (HANDLE)0x0) {
    DVar2 = WaitForSingleObject(DAT_1800797e8,100);
    if (DVar2 == 0x102) {
      FUN_180002a20(local_408,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\AdsNodeCol.cpp",0x3e);
      LogMessage(local_408,2,1);
    }
    piVar1 = (int *)(param_1 + 1);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      FUN_180002b40(param_1);
      FUN_180025ad0(param_1);
      return 0;
    }
    ReleaseSemaphore(DAT_1800797e8,1,(LPLONG)0x0);
  }
  return *(undefined4 *)(param_1 + 1);
}

/* ---- FUNC 00002FE0 FUN_180002fe0 (98 bytes) ---- */

undefined8 FUN_180002fe0(longlong *param_1,int *param_2)

{
  AcpUntypedArray *this;
  AcpBase *this_00;
  int iVar1;
  undefined8 uVar2;
  
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x000180002fff. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(*param_1 + 0x58))(param_1,0x7f3);
    return uVar2;
  }
  this = *(AcpUntypedArray **)(param_1[0x2b] + 0x170);
  if (this != (AcpUntypedArray *)0x0) {
    iVar1 = AcpUntypedArray::Length(this);
    *param_2 = iVar1;
    return 0;
  }
  this_00 = *(AcpBase **)(param_1[0x2b] + 0x168);
  if (this_00 != (AcpBase *)0x0) {
    iVar1 = AcpBase::NumberOfVariables(this_00);
    *param_2 = iVar1;
  }
  return 0;
}

/* ---- FUNC 00003050 FUN_180003050 (98 bytes) ---- */

ulonglong FUN_180003050(longlong *param_1,tagVARIANT *param_2)

{
  char cVar1;
  VARTYPE VVar2;
  longlong lVar3;
  longlong *plVar4;
  uint uVar5;
  int iVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  char *pcVar9;
  AcpBase *pAVar10;
  IAdbRecord *pIVar11;
  AString *pAVar12;
  AcpUntypedArray *this;
  AcpBase *this_00;
  tagVARIANT *ptVar13;
  ulonglong uVar14;
  longlong *in_stack_00000038;
  longlong local_a8;
  _union_1719 _Stack_a0;
  undefined8 local_98;
  _union_2707 local_88;
  AString local_70 [16];
  IAdbRecord *local_60;
  AString local_58 [16];
  tagVARIANT local_48;
  
  plVar4 = in_stack_00000038;
  this_00 = (AcpBase *)0x0;
  *in_stack_00000038 = 0;
  if (DAT_1800797f8 != 0) {
    uVar7 = (**(code **)(*param_1 + 0x58))(param_1,0x7f3);
    return uVar7;
  }
  lVar3 = param_1[0x2b];
  if (lVar3 == 0) {
    uVar7 = (**(code **)(*param_1 + 0x58))(param_1,0x7d9);
    return uVar7;
  }
  if (*(longlong *)(lVar3 + 0x168) == 0) {
    if (*(AcpUntypedArray **)(lVar3 + 0x170) == (AcpUntypedArray *)0x0) {
      return 0;
    }
    VVar2 = (param_2->n1).n2.vt;
    if (VVar2 == 3) {
LAB_1800034ad:
      uVar5 = *(uint *)((longlong)&param_2->n1 + 8);
    }
    else {
      if (VVar2 != 8) {
        if (VVar2 != 0x14) goto LAB_18000353f;
        goto LAB_1800034ad;
      }
      uVar5 = AcpUntypedArray::FindID(*(AcpUntypedArray **)(lVar3 + 0x170),param_2);
    }
    if ((-1 < (int)uVar5) && (uVar5 < 999999)) {
      AcpUntypedArray::ValueAtLocation
                (*(AcpUntypedArray **)(param_1[0x2b] + 0x170),(tagVARIANT *)&local_88.n2,uVar5);
      iVar6 = AcpUntypedArray::unitRowAtLocation(*(AcpUntypedArray **)(param_1[0x2b] + 0x170),uVar5)
      ;
      pAVar10 = operator_new(0x58);
      if (pAVar10 != (AcpBase *)0x0) {
        pIVar11 = AcpVariableBase::VariantToValue((tagVARIANT *)&local_88.n2,&local_60);
        AcpBase::AcpBase(pAVar10,pIVar11,true);
        *(undefined ***)pAVar10 = AcpBase::vftable;
        this_00 = pAVar10;
      }
      local_a8 = local_88._0_8_;
      _Stack_a0 = local_88.decVal.u2;
      local_98 = local_88._16_8_;
      uVar7 = FUN_180001ab0(this_00,&local_a8,&stack0x00000038,*(longlong **)(param_1[0x2b] + 0x160)
                            ,param_1[0x2b]);
      uVar14 = uVar7 & 0xffffffff;
      if ((int)uVar7 < 0) {
        if (this_00 == (AcpBase *)0x0) {
          return uVar14;
        }
        (*(code *)**(undefined8 **)this_00)(this_00,1);
        return uVar14;
      }
      *(int *)((longlong)in_stack_00000038 + 0x1bc) = iVar6;
      if (this_00 != (AcpBase *)0x0) {
        (*(code *)**(undefined8 **)this_00)(this_00,1);
      }
      *plVar4 = (longlong)in_stack_00000038;
      (**(code **)(*in_stack_00000038 + 8))();
      return uVar14;
    }
    goto LAB_18000353f;
  }
  VVar2 = (param_2->n1).n2.vt;
  if (VVar2 == 3) {
LAB_1800030f8:
    uVar5 = *(uint *)((longlong)&param_2->n1 + 8);
    if ((int)uVar5 < 0) {
      uVar7 = (**(code **)(*param_1 + 0x58))(param_1,0x7db);
      return uVar7;
    }
  }
  else {
    if (VVar2 != 8) {
      if (VVar2 != 0x14) goto LAB_18000353f;
      goto LAB_1800030f8;
    }
    uVar8 = AString::AString((AString *)&local_a8,param_2);
    uVar5 = AcpBase::LocationOfID(*(AcpBase **)(param_1[0x2b] + 0x168),uVar8);
    if ((int)uVar5 < 0) {
      uVar7 = (**(code **)(*param_1 + 0x58))(param_1,0x7db);
      return uVar7;
    }
  }
  if (0xf423e < uVar5) {
LAB_18000353f:
    uVar7 = (**(code **)(*param_1 + 0x58))(param_1,0x7db);
    return uVar7;
  }
  AcpBase::ValueAtLocation(*(AcpBase **)(param_1[0x2b] + 0x168),(tagVARIANT *)&local_88.n2,uVar5);
  AcpBase::GuidAtLocation(*(AcpBase **)(param_1[0x2b] + 0x168),(int)local_70);
  uVar8 = AString::AString((AString *)&local_a8,local_70);
  iVar6 = AcpBase::UnitRow(*(AcpBase **)(param_1[0x2b] + 0x168),uVar8);
  AcpBase::VariableTypeAtLocation(*(AcpBase **)(param_1[0x2b] + 0x168),(int)local_58);
  pcVar9 = AString::CValue(local_58);
  cVar1 = *pcVar9;
  if ((cVar1 + 0xbfU & 0xdf) == 0) {
    this = operator_new(0x48);
    if (this != (AcpUntypedArray *)0x0) {
      pcVar9 = AString::CValue(local_70);
      this_00 = (AcpBase *)
                AcpUntypedArray::AcpUntypedArray
                          (this,*(AcpBaseRecord **)(param_1[0x2b] + 0x168),pcVar9);
    }
    ptVar13 = AcpUntypedArray::ValueAtLocation((AcpUntypedArray *)this_00,&local_48,-1);
    local_88._0_8_ = *(undefined8 *)&ptVar13->n1;
    local_88.decVal.u2 = (ptVar13->n1).decVal.u2;
    local_88._16_8_ = *(undefined8 *)((longlong)&ptVar13->n1 + 0x10);
    local_a8 = *(longlong *)&ptVar13->n1;
    _Stack_a0 = (ptVar13->n1).decVal.u2;
    local_98 = *(undefined8 *)((longlong)&ptVar13->n1 + 0x10);
    uVar7 = FUN_180001be0((AcpUntypedArray *)this_00,(undefined4 *)&local_a8,&stack0x00000038,
                          *(longlong **)(param_1[0x2b] + 0x160),param_1[0x2b]);
    uVar14 = uVar7 & 0xffffffff;
    if ((int)uVar7 < 0) {
      if (this_00 != (AcpBase *)0x0) {
        AcpUntypedArray::~AcpUntypedArray((AcpUntypedArray *)this_00);
        FUN_180025ad0(this_00);
      }
      goto LAB_18000327a;
    }
    pAVar12 = (AString *)AcpBase::IDAtLocation(*(AcpBase **)(param_1[0x2b] + 0x168),(int)&local_a8);
    pcVar9 = AString::CValue(pAVar12);
    FUN_180001610(in_stack_00000038 + 0x33,pcVar9);
    AString::~AString((AString *)&local_a8);
    *(int *)((longlong)in_stack_00000038 + 0x1bc) = iVar6;
    *(char *)(in_stack_00000038 + 0x37) = cVar1;
    if (this_00 != (AcpBase *)0x0) {
      AcpUntypedArray::~AcpUntypedArray((AcpUntypedArray *)this_00);
      FUN_180025ad0(this_00);
    }
  }
  else {
    pAVar10 = operator_new(0x58);
    if (pAVar10 != (AcpBase *)0x0) {
      pIVar11 = AcpVariableBase::VariantToValue((tagVARIANT *)&local_88.n2,&local_60);
      AcpBase::AcpBase(pAVar10,pIVar11,true);
      *(undefined ***)pAVar10 = AcpBase::vftable;
      this_00 = pAVar10;
    }
    local_a8 = local_88._0_8_;
    _Stack_a0 = local_88.decVal.u2;
    local_98 = local_88._16_8_;
    uVar7 = FUN_180001ab0(this_00,&local_a8,&stack0x00000038,*(longlong **)(param_1[0x2b] + 0x160),
                          param_1[0x2b]);
    uVar14 = uVar7 & 0xffffffff;
    if ((int)uVar7 < 0) {
      if (this_00 != (AcpBase *)0x0) {
        (*(code *)**(undefined8 **)this_00)(this_00,1);
      }
      goto LAB_18000327a;
    }
    pAVar12 = (AString *)AcpBase::IDAtLocation(*(AcpBase **)(param_1[0x2b] + 0x168),(int)&local_a8);
    pcVar9 = AString::CValue(pAVar12);
    FUN_180001610(in_stack_00000038 + 0x33,pcVar9);
    AString::~AString((AString *)&local_a8);
    *(int *)((longlong)in_stack_00000038 + 0x1bc) = iVar6;
    *(char *)(in_stack_00000038 + 0x37) = cVar1;
    if (this_00 != (AcpBase *)0x0) {
      (*(code *)**(undefined8 **)this_00)(this_00,1);
      *plVar4 = (longlong)in_stack_00000038;
      (**(code **)(*in_stack_00000038 + 8))();
      goto LAB_18000327a;
    }
  }
  *plVar4 = (longlong)in_stack_00000038;
  (**(code **)(*in_stack_00000038 + 8))();
LAB_18000327a:
  AString::~AString(local_58);
  AString::~AString(local_70);
  return uVar14;
}

/* ---- FUNC 000030B2 FUN_1800030b2 (1320 bytes) ---- */

ulonglong FUN_1800030b2(longlong *param_1,tagVARIANT *param_2)

{
  char cVar1;
  VARTYPE VVar2;
  longlong lVar3;
  longlong *plVar4;
  _union_1719 _Var5;
  uint uVar6;
  int iVar7;
  int iVar8;
  longlong in_RAX;
  ulonglong uVar9;
  undefined8 uVar10;
  char *pcVar11;
  AcpBase *pAVar12;
  IAdbRecord *pIVar13;
  AString *pAVar14;
  AcpUntypedArray *this;
  AcpUntypedArray *this_00;
  tagVARIANT *ptVar15;
  longlong *unaff_RBX;
  longlong unaff_RBP;
  AcpBase *unaff_RSI;
  AcpBase *pAVar16;
  undefined8 *unaff_R15;
  
  if (*(AcpBase **)(in_RAX + 0x168) == unaff_RSI) {
    if (*(AcpUntypedArray **)(in_RAX + 0x170) != (AcpUntypedArray *)0x0) {
      VVar2 = (param_2->n1).n2.vt;
      if (VVar2 == 3) {
LAB_1800034ad:
        uVar6 = *(uint *)((longlong)&param_2->n1 + 8);
      }
      else {
        if (VVar2 != 8) {
          if (VVar2 != 0x14) goto LAB_18000353f;
          goto LAB_1800034ad;
        }
        uVar6 = AcpUntypedArray::FindID(*(AcpUntypedArray **)(in_RAX + 0x170),param_2);
      }
      if (((int)uVar6 < 0) || (0xf423e < uVar6)) goto LAB_18000353f;
      AcpUntypedArray::ValueAtLocation
                (*(AcpUntypedArray **)(unaff_RBX[0x2b] + 0x170),(tagVARIANT *)(unaff_RBP + -0x41),
                 uVar6);
      iVar8 = AcpUntypedArray::unitRowAtLocation
                        (*(AcpUntypedArray **)(unaff_RBX[0x2b] + 0x170),uVar6);
      pAVar12 = operator_new(0x58);
      pAVar16 = unaff_RSI;
      if (pAVar12 != (AcpBase *)0x0) {
        pIVar13 = AcpVariableBase::VariantToValue
                            ((tagVARIANT *)(unaff_RBP + -0x41),(IAdbRecord **)(unaff_RBP + -0x19));
        AcpBase::AcpBase(pAVar12,pIVar13,true);
        *(undefined ***)pAVar12 = AcpBase::vftable;
        pAVar16 = pAVar12;
      }
      lVar3 = unaff_RBX[0x2b];
      plVar4 = *(longlong **)(lVar3 + 0x160);
      *(undefined8 *)(unaff_RBP + -0x61) = *(undefined8 *)(unaff_RBP + -0x41);
      *(undefined8 *)(unaff_RBP + -0x59) = *(undefined8 *)(unaff_RBP + -0x39);
      *(undefined8 *)(unaff_RBP + -0x51) = *(undefined8 *)(unaff_RBP + -0x31);
      uVar9 = FUN_180001ab0(pAVar16,(longlong *)(unaff_RBP + -0x61),(undefined8 *)(unaff_RBP + 0x7f)
                            ,plVar4,lVar3);
      unaff_RSI = (AcpBase *)(uVar9 & 0xffffffff);
      if ((int)uVar9 < 0) {
        if (pAVar16 != (AcpBase *)0x0) {
          (*(code *)**(undefined8 **)pAVar16)(pAVar16,1);
        }
      }
      else {
        *(int *)(*(longlong *)(unaff_RBP + 0x7f) + 0x1bc) = iVar8;
        if (pAVar16 != (AcpBase *)0x0) {
          (*(code *)**(undefined8 **)pAVar16)(pAVar16,1);
        }
        plVar4 = *(longlong **)(unaff_RBP + 0x7f);
        *unaff_R15 = plVar4;
        (**(code **)(*plVar4 + 8))();
      }
    }
LAB_18000328e:
    uVar9 = (ulonglong)unaff_RSI & 0xffffffff;
  }
  else {
    VVar2 = (param_2->n1).n2.vt;
    if (VVar2 == 3) {
LAB_1800030f8:
      uVar6 = *(uint *)((longlong)&param_2->n1 + 8);
      if ((int)uVar6 < 0) {
        uVar9 = (**(code **)(*param_1 + 0x58))(param_1,0x7db);
        return uVar9;
      }
LAB_18000314c:
      if (uVar6 < 999999) {
        AcpBase::ValueAtLocation
                  (*(AcpBase **)(unaff_RBX[0x2b] + 0x168),(tagVARIANT *)(unaff_RBP + -0x41),uVar6);
        iVar8 = (int)unaff_RBP;
        AcpBase::GuidAtLocation(*(AcpBase **)(unaff_RBX[0x2b] + 0x168),iVar8 + -0x29);
        uVar10 = AString::AString((AString *)(unaff_RBP + -0x61),(AString *)(unaff_RBP + -0x29));
        iVar7 = AcpBase::UnitRow(*(AcpBase **)(unaff_RBX[0x2b] + 0x168),uVar10);
        AcpBase::VariableTypeAtLocation(*(AcpBase **)(unaff_RBX[0x2b] + 0x168),iVar8 + -0x11);
        pcVar11 = AString::CValue((AString *)(unaff_RBP + -0x11));
        cVar1 = *pcVar11;
        if ((cVar1 + 0xbfU & 0xdf) == 0) {
          this = operator_new(0x48);
          this_00 = (AcpUntypedArray *)unaff_RSI;
          if (this != (AcpUntypedArray *)0x0) {
            pcVar11 = AString::CValue((AString *)(unaff_RBP + -0x29));
            this_00 = (AcpUntypedArray *)
                      AcpUntypedArray::AcpUntypedArray
                                (this,*(AcpBaseRecord **)(unaff_RBX[0x2b] + 0x168),pcVar11);
          }
          ptVar15 = AcpUntypedArray::ValueAtLocation(this_00,(tagVARIANT *)(unaff_RBP + -1),-1);
          lVar3 = unaff_RBX[0x2b];
          _Var5 = (ptVar15->n1).decVal.u2;
          *(undefined8 *)(unaff_RBP + -0x41) = *(undefined8 *)&ptVar15->n1;
          *(_union_1719 *)(unaff_RBP + -0x39) = _Var5;
          *(undefined8 *)(unaff_RBP + -0x31) = *(undefined8 *)((longlong)&ptVar15->n1 + 0x10);
          _Var5 = (ptVar15->n1).decVal.u2;
          plVar4 = *(longlong **)(lVar3 + 0x160);
          uVar10 = *(undefined8 *)((longlong)&ptVar15->n1 + 0x10);
          *(undefined8 *)(unaff_RBP + -0x61) = *(undefined8 *)&ptVar15->n1;
          *(_union_1719 *)(unaff_RBP + -0x59) = _Var5;
          *(undefined8 *)(unaff_RBP + -0x51) = uVar10;
          uVar9 = FUN_180001be0(this_00,(undefined4 *)(unaff_RBP + -0x61),
                                (undefined8 *)(unaff_RBP + 0x7f),plVar4,lVar3);
          unaff_RSI = (AcpBase *)(uVar9 & 0xffffffff);
          if ((int)uVar9 < 0) {
            if (this_00 != (AcpUntypedArray *)0x0) {
              AcpUntypedArray::~AcpUntypedArray(this_00);
              FUN_180025ad0(this_00);
            }
          }
          else {
            pAVar14 = (AString *)
                      AcpBase::IDAtLocation(*(AcpBase **)(unaff_RBX[0x2b] + 0x168),iVar8 + -0x61);
            pcVar11 = AString::CValue(pAVar14);
            FUN_180001610((longlong *)(*(longlong *)(unaff_RBP + 0x7f) + 0x198),pcVar11);
            AString::~AString((AString *)(unaff_RBP + -0x61));
            *(int *)(*(longlong *)(unaff_RBP + 0x7f) + 0x1bc) = iVar7;
            *(char *)(*(longlong *)(unaff_RBP + 0x7f) + 0x1b8) = cVar1;
            if (this_00 != (AcpUntypedArray *)0x0) {
              AcpUntypedArray::~AcpUntypedArray(this_00);
              FUN_180025ad0(this_00);
            }
LAB_18000346e:
            plVar4 = *(longlong **)(unaff_RBP + 0x7f);
            *unaff_R15 = plVar4;
            (**(code **)(*plVar4 + 8))();
          }
        }
        else {
          pAVar12 = operator_new(0x58);
          pAVar16 = unaff_RSI;
          if (pAVar12 != (AcpBase *)0x0) {
            pIVar13 = AcpVariableBase::VariantToValue
                                ((tagVARIANT *)(unaff_RBP + -0x41),
                                 (IAdbRecord **)(unaff_RBP + -0x19));
            AcpBase::AcpBase(pAVar12,pIVar13,true);
            *(undefined ***)pAVar12 = AcpBase::vftable;
            pAVar16 = pAVar12;
          }
          lVar3 = unaff_RBX[0x2b];
          plVar4 = *(longlong **)(lVar3 + 0x160);
          *(undefined8 *)(unaff_RBP + -0x61) = *(undefined8 *)(unaff_RBP + -0x41);
          *(undefined8 *)(unaff_RBP + -0x59) = *(undefined8 *)(unaff_RBP + -0x39);
          *(undefined8 *)(unaff_RBP + -0x51) = *(undefined8 *)(unaff_RBP + -0x31);
          uVar9 = FUN_180001ab0(pAVar16,(longlong *)(unaff_RBP + -0x61),
                                (undefined8 *)(unaff_RBP + 0x7f),plVar4,lVar3);
          unaff_RSI = (AcpBase *)(uVar9 & 0xffffffff);
          if ((int)uVar9 < 0) {
            if (pAVar16 != (AcpBase *)0x0) {
              (*(code *)**(undefined8 **)pAVar16)(pAVar16,1);
            }
          }
          else {
            pAVar14 = (AString *)
                      AcpBase::IDAtLocation(*(AcpBase **)(unaff_RBX[0x2b] + 0x168),iVar8 + -0x61);
            pcVar11 = AString::CValue(pAVar14);
            FUN_180001610((longlong *)(*(longlong *)(unaff_RBP + 0x7f) + 0x198),pcVar11);
            AString::~AString((AString *)(unaff_RBP + -0x61));
            *(int *)(*(longlong *)(unaff_RBP + 0x7f) + 0x1bc) = iVar7;
            *(char *)(*(longlong *)(unaff_RBP + 0x7f) + 0x1b8) = cVar1;
            if (pAVar16 == (AcpBase *)0x0) goto LAB_18000346e;
            (*(code *)**(undefined8 **)pAVar16)(pAVar16,1);
            plVar4 = *(longlong **)(unaff_RBP + 0x7f);
            *unaff_R15 = plVar4;
            (**(code **)(*plVar4 + 8))();
          }
        }
        AString::~AString((AString *)(unaff_RBP + -0x11));
        AString::~AString((AString *)(unaff_RBP + -0x29));
        goto LAB_18000328e;
      }
    }
    else {
      if (VVar2 == 8) {
        uVar10 = AString::AString((AString *)(unaff_RBP + -0x61),param_2);
        uVar6 = AcpBase::LocationOfID(*(AcpBase **)(unaff_RBX[0x2b] + 0x168),uVar10);
        if ((int)uVar6 < 0) {
          uVar9 = (**(code **)(*unaff_RBX + 0x58))();
          return uVar9;
        }
        goto LAB_18000314c;
      }
      if (VVar2 == 0x14) goto LAB_1800030f8;
    }
LAB_18000353f:
    uVar9 = (**(code **)(*unaff_RBX + 0x58))();
  }
  return uVar9;
}

/* ---- FUNC 000032BD FUN_1800032bd (451 bytes) ---- */

undefined4 FUN_1800032bd(void)

{
  longlong *plVar1;
  AString *this;
  char *pcVar2;
  longlong unaff_RBX;
  longlong unaff_RBP;
  undefined4 unaff_ESI;
  undefined8 *unaff_RDI;
  undefined1 unaff_R12B;
  undefined4 unaff_R13D;
  undefined8 *unaff_R15;
  
  this = (AString *)
         AcpBase::IDAtLocation
                   (*(AcpBase **)(*(longlong *)(unaff_RBX + 0x158) + 0x168),(int)unaff_RBP + -0x61);
  pcVar2 = AString::CValue(this);
  FUN_180001610((longlong *)(*(longlong *)(unaff_RBP + 0x7f) + 0x198),pcVar2);
  AString::~AString((AString *)(unaff_RBP + -0x61));
  *(undefined4 *)(*(longlong *)(unaff_RBP + 0x7f) + 0x1bc) = unaff_R13D;
  *(undefined1 *)(*(longlong *)(unaff_RBP + 0x7f) + 0x1b8) = unaff_R12B;
  if (unaff_RDI == (undefined8 *)0x0) {
    plVar1 = *(longlong **)(unaff_RBP + 0x7f);
    *unaff_R15 = plVar1;
    (**(code **)(*plVar1 + 8))();
  }
  else {
    (**(code **)*unaff_RDI)();
    plVar1 = *(longlong **)(unaff_RBP + 0x7f);
    *unaff_R15 = plVar1;
    (**(code **)(*plVar1 + 8))();
  }
  AString::~AString((AString *)(unaff_RBP + -0x11));
  AString::~AString((AString *)(unaff_RBP + -0x29));
  return unaff_ESI;
}

/* ---- FUNC 000035E0 FUN_1800035e0 (63 bytes) ---- */

ulonglong FUN_1800035e0(longlong *param_1,undefined4 *param_2,undefined8 *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  SAFEARRAY *pSVar3;
  LONG local_res20 [2];
  ULONG local_178 [2];
  longlong *local_170;
  SAFEARRAYBOUND local_168;
  _union_2707 local_160;
  _union_2707 local_148;
  _union_2707 local_130;
  _union_2707 local_118;
  _union_2707 local_100;
  undefined4 local_e8;
  ULONG UStack_e4;
  int iStack_e0;
  undefined4 uStack_dc;
  undefined8 local_d8;
  _union_2707 local_c8;
  undefined8 local_a8;
  _union_1719 _Stack_a0;
  undefined8 local_98;
  undefined8 local_88;
  _union_1719 _Stack_80;
  undefined8 local_78;
  undefined8 local_68;
  _union_1719 _Stack_60;
  undefined8 local_58;
  undefined8 local_48;
  _union_1719 _Stack_40;
  undefined8 local_38;
  
  if (DAT_1800797f8 != 0) {
    uVar2 = (**(code **)(*param_1 + 0x58))(param_1,0x7f3);
    return uVar2;
  }
  local_178[0] = 0;
  (**(code **)(*param_1 + 0x40))(param_1,local_178);
  local_168.lLbound = 0;
  local_168.cElements = local_178[0];
  pSVar3 = SafeArrayCreate(0xc,1,&local_168);
  *param_3 = pSVar3;
  local_res20[0] = 0;
  if (0 < (int)local_178[0]) {
    do {
      local_170 = (longlong *)0x0;
      local_100._0_8_ = 0;
      local_100.decVal.u2 = (_union_1719)0x0;
      local_100._16_8_ = 0;
      VariantInit((VARIANTARG *)&local_100.n2);
      local_118._0_8_ = 0;
      local_118.decVal.u2.Lo64 = (_union_1719)0x0;
      local_118._16_8_ = 0;
      VariantInit((VARIANTARG *)&local_118.n2);
      local_130._0_8_ = 0;
      local_130.decVal.u2.Lo64 = (_union_1719)0x0;
      local_130._16_8_ = 0;
      VariantInit((VARIANTARG *)&local_130.n2);
      local_148._0_8_ = 0;
      local_148.decVal.u2.Lo64 = (_union_1719)0x0;
      local_148._16_8_ = 0;
      VariantInit((VARIANTARG *)&local_148.n2);
      local_a8 = local_148._0_8_;
      _Stack_a0.Lo64 = (ULONGLONG)local_148.decVal.u2;
      local_98 = local_148._16_8_;
      local_88 = local_130._0_8_;
      _Stack_80.Lo64 = (ULONGLONG)local_130.decVal.u2;
      local_c8._8_4_ = local_res20[0];
      local_78 = local_130._16_8_;
      local_68 = local_118._0_8_;
      _Stack_60.Lo64 = (ULONGLONG)local_118.decVal.u2;
      local_c8.n2.vt = 3;
      local_58 = local_118._16_8_;
      local_48 = local_100._0_8_;
      _Stack_40 = local_100.decVal.u2;
      local_38 = local_100._16_8_;
      local_e8 = local_c8._0_4_;
      UStack_e4 = local_c8.decVal.Hi32;
      iStack_e0 = local_res20[0];
      uStack_dc = local_c8._12_4_;
      local_d8 = local_c8._16_8_;
      uVar1 = (**(code **)(*param_1 + 0x38))
                        (param_1,&local_e8,&local_48,&local_68,&local_88,&local_a8,&local_170);
      VariantClear((VARIANTARG *)&local_c8.n2);
      if ((int)uVar1 < 0) {
LAB_18000388a:
        VariantClear((VARIANTARG *)&local_148.n2);
        VariantClear((VARIANTARG *)&local_130.n2);
        VariantClear((VARIANTARG *)&local_118.n2);
        VariantClear((VARIANTARG *)&local_100.n2);
        if (local_170 == (longlong *)0x0) {
          return (ulonglong)uVar1;
        }
        (**(code **)(*local_170 + 0x10))();
        return (ulonglong)uVar1;
      }
      local_160._0_8_ = 0;
      local_160.decVal.u2.Lo64 = (_union_1719)0x0;
      local_160._16_8_ = 0;
      VariantInit((VARIANTARG *)&local_160.n2);
      local_e8 = *param_2;
      UStack_e4 = param_2[1];
      iStack_e0 = param_2[2];
      uStack_dc = param_2[3];
      local_d8 = *(undefined8 *)(param_2 + 4);
      uVar1 = (**(code **)(*local_170 + 0x40))(local_170,&local_e8,&local_160);
      if (((int)uVar1 < 0) ||
         (uVar1 = SafeArrayPutElement((SAFEARRAY *)*param_3,local_res20,&local_160), (int)uVar1 < 0)
         ) {
        VariantClear((VARIANTARG *)&local_160.n2);
        goto LAB_18000388a;
      }
      VariantClear((VARIANTARG *)&local_160.n2);
      VariantClear((VARIANTARG *)&local_148.n2);
      VariantClear((VARIANTARG *)&local_130.n2);
      VariantClear((VARIANTARG *)&local_118.n2);
      VariantClear((VARIANTARG *)&local_100.n2);
      if (local_170 != (longlong *)0x0) {
        (**(code **)(*local_170 + 0x10))();
      }
      local_res20[0] = local_res20[0] + 1;
    } while (local_res20[0] < (int)local_178[0]);
  }
  return 0;
}

/* ---- FUNC 0000361F FUN_18000361f (608 bytes) ---- */

int FUN_18000361f(undefined8 param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  longlong in_RAX;
  SAFEARRAY *pSVar7;
  undefined8 *unaff_RBP;
  undefined8 *unaff_RSI;
  undefined4 *unaff_RDI;
  longlong *unaff_R14;
  ULONG UStack0000000000000040;
  longlong *in_stack_00000048;
  ULONG in_stack_00000050;
  LONG LStack0000000000000054;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000078;
  
  UStack0000000000000040 = 0;
  (**(code **)(in_RAX + 0x40))(param_1,&stack0x00000040);
  LStack0000000000000054 = 0;
  in_stack_00000050 = UStack0000000000000040;
  pSVar7 = SafeArrayCreate(0xc,1,(SAFEARRAYBOUND *)&stack0x00000050);
  *unaff_RSI = pSVar7;
  *(undefined4 *)(unaff_RBP + 0x1b) = 0;
  if (0 < (int)UStack0000000000000040) {
    do {
      in_stack_00000048 = (longlong *)0x0;
      unaff_RBP[-9] = 0;
      unaff_RBP[-8] = 0;
      unaff_RBP[-7] = 0;
      VariantInit((VARIANTARG *)(unaff_RBP + -9));
      unaff_RBP[-0xc] = 0;
      unaff_RBP[-0xb] = 0;
      unaff_RBP[-10] = 0;
      VariantInit((VARIANTARG *)(unaff_RBP + -0xc));
      unaff_RBP[-0xf] = 0;
      unaff_RBP[-0xe] = 0;
      unaff_RBP[-0xd] = 0;
      VariantInit((VARIANTARG *)(unaff_RBP + -0xf));
      in_stack_00000070 = 0;
      in_stack_00000078 = (_union_1719)0x0;
      unaff_RBP[-0x10] = 0;
      VariantInit((VARIANTARG *)&stack0x00000070);
      unaff_RBP[2] = in_stack_00000070;
      ((_union_1719 *)(unaff_RBP + 3))->Lo64 = in_stack_00000078;
      unaff_RBP[4] = unaff_RBP[-0x10];
      unaff_RBP[6] = unaff_RBP[-0xf];
      unaff_RBP[7] = unaff_RBP[-0xe];
      *(undefined4 *)(unaff_RBP + -1) = *(undefined4 *)(unaff_RBP + 0x1b);
      lVar2 = *unaff_R14;
      unaff_RBP[8] = unaff_RBP[-0xd];
      unaff_RBP[10] = unaff_RBP[-0xc];
      unaff_RBP[0xb] = unaff_RBP[-0xb];
      *(undefined2 *)(unaff_RBP + -2) = 3;
      unaff_RBP[0xc] = unaff_RBP[-10];
      unaff_RBP[0xe] = unaff_RBP[-9];
      unaff_RBP[0xf] = unaff_RBP[-8];
      unaff_RBP[0x10] = unaff_RBP[-7];
      *(undefined4 *)(unaff_RBP + -6) = *(undefined4 *)(unaff_RBP + -2);
      *(undefined4 *)((longlong)unaff_RBP + -0x2c) = *(undefined4 *)((longlong)unaff_RBP + -0xc);
      *(undefined4 *)(unaff_RBP + -5) = *(undefined4 *)(unaff_RBP + -1);
      *(undefined4 *)((longlong)unaff_RBP + -0x24) = *(undefined4 *)((longlong)unaff_RBP + -4);
      unaff_RBP[-4] = *unaff_RBP;
      iVar6 = (**(code **)(lVar2 + 0x38))
                        (*(undefined4 *)(unaff_RBP + -2),unaff_RBP + -6,unaff_RBP + 0xe,
                         unaff_RBP + 10,unaff_RBP + 6);
      VariantClear((VARIANTARG *)(unaff_RBP + -2));
      if (iVar6 < 0) {
LAB_18000388a:
        VariantClear((VARIANTARG *)&stack0x00000070);
        VariantClear((VARIANTARG *)(unaff_RBP + -0xf));
        VariantClear((VARIANTARG *)(unaff_RBP + -0xc));
        VariantClear((VARIANTARG *)(unaff_RBP + -9));
        if (in_stack_00000048 == (longlong *)0x0) {
          return iVar6;
        }
        (**(code **)(*in_stack_00000048 + 0x10))();
        return iVar6;
      }
      in_stack_00000058 = 0;
      in_stack_00000060 = (_union_1719)0x0;
      in_stack_00000068 = 0;
      VariantInit((VARIANTARG *)&stack0x00000058);
      uVar3 = unaff_RDI[1];
      uVar4 = unaff_RDI[2];
      uVar5 = unaff_RDI[3];
      uVar1 = *(undefined8 *)(unaff_RDI + 4);
      lVar2 = *in_stack_00000048;
      *(undefined4 *)(unaff_RBP + -6) = *unaff_RDI;
      *(undefined4 *)((longlong)unaff_RBP + -0x2c) = uVar3;
      *(undefined4 *)(unaff_RBP + -5) = uVar4;
      *(undefined4 *)((longlong)unaff_RBP + -0x24) = uVar5;
      unaff_RBP[-4] = uVar1;
      iVar6 = (**(code **)(lVar2 + 0x40))(in_stack_00000048,unaff_RBP + -6,&stack0x00000058);
      if ((iVar6 < 0) ||
         (iVar6 = SafeArrayPutElement((SAFEARRAY *)*unaff_RSI,(LONG *)(unaff_RBP + 0x1b),
                                      &stack0x00000058), iVar6 < 0)) {
        VariantClear((VARIANTARG *)&stack0x00000058);
        goto LAB_18000388a;
      }
      VariantClear((VARIANTARG *)&stack0x00000058);
      VariantClear((VARIANTARG *)&stack0x00000070);
      VariantClear((VARIANTARG *)(unaff_RBP + -0xf));
      VariantClear((VARIANTARG *)(unaff_RBP + -0xc));
      VariantClear((VARIANTARG *)(unaff_RBP + -9));
      if (in_stack_00000048 != (longlong *)0x0) {
        (**(code **)(*in_stack_00000048 + 0x10))();
      }
      iVar6 = *(int *)(unaff_RBP + 0x1b);
      *(int *)(unaff_RBP + 0x1b) = iVar6 + 1;
    } while (iVar6 + 1 < (int)UStack0000000000000040);
  }
  return 0;
}

/* ---- FUNC 0000387F FUN_18000387f (72 bytes) ---- */

undefined4 FUN_18000387f(void)

{
  undefined4 unaff_EBX;
  longlong unaff_RBP;
  longlong *in_stack_00000048;
  
  VariantClear((VARIANTARG *)&stack0x00000058);
  VariantClear((VARIANTARG *)&stack0x00000070);
  VariantClear((VARIANTARG *)(unaff_RBP + -0x78));
  VariantClear((VARIANTARG *)(unaff_RBP + -0x60));
  VariantClear((VARIANTARG *)(unaff_RBP + -0x48));
  if (in_stack_00000048 != (longlong *)0x0) {
    (**(code **)(*in_stack_00000048 + 0x10))();
  }
  return unaff_EBX;
}

/* ---- FUNC 000038D0 FUN_1800038d0 (538 bytes) ---- */

undefined8 FUN_1800038d0(HWND param_1,int param_2,longlong param_3)

{
  UINT UVar1;
  HWND pHVar2;
  
  if (param_2 == 0x110) {
    DAT_180079208 = GetDefaultCopyContent();
    if ((DAT_180079204 & 1) == 0) {
      pHVar2 = GetDlgItem(param_1,0x3ea);
      EnableWindow(pHVar2,0);
    }
    else if ((DAT_180079208 & 1) != 0) {
      CheckDlgButton(param_1,0x3ea,1);
    }
    if ((DAT_180079204 & 2) == 0) {
      pHVar2 = GetDlgItem(param_1,0x3eb);
      EnableWindow(pHVar2,0);
    }
    else if ((DAT_180079208 & 2) != 0) {
      CheckDlgButton(param_1,0x3eb,1);
    }
    if ((DAT_180079204 & 4) == 0) {
      pHVar2 = GetDlgItem(param_1,0x3ec);
      EnableWindow(pHVar2,0);
    }
    else if ((DAT_180079208 & 4) != 0) {
      CheckDlgButton(param_1,0x3ec,1);
    }
    if ((DAT_180079204 & 8) == 0) {
      pHVar2 = GetDlgItem(param_1,0x3ed);
      EnableWindow(pHVar2,0);
    }
    else if ((DAT_180079208 & 8) != 0) {
      CheckDlgButton(param_1,0x3ed,1);
    }
    pHVar2 = GetDlgItem(param_1,1);
    SetFocus(pHVar2);
    return 0;
  }
  if (param_2 == 0x111) {
    if ((short)param_3 == 1) {
      EndDialog(param_1,1);
      DAT_180079208 = 0;
      UVar1 = IsDlgButtonChecked(param_1,0x3ea);
      if (UVar1 == 1) {
        DAT_180079208 = DAT_180079208 | 1;
      }
      UVar1 = IsDlgButtonChecked(param_1,0x3eb);
      if (UVar1 == 1) {
        DAT_180079208 = DAT_180079208 | 2;
      }
      UVar1 = IsDlgButtonChecked(param_1,0x3ec);
      if (UVar1 == 1) {
        DAT_180079208 = DAT_180079208 | 4;
      }
      UVar1 = IsDlgButtonChecked(param_1,0x3ed);
      if (UVar1 == 1) {
        DAT_180079208 = DAT_180079208 | 8;
      }
      return 1;
    }
    if ((short)param_3 != 2) {
      return 0;
    }
  }
  else {
    if (param_2 != 0x112) {
      return 0;
    }
    if (param_3 != 0xf060) {
      return 0;
    }
  }
  EndDialog(param_1,2);
  return 1;
}

/* ---- FUNC 00003AF0 FUN_180003af0 (112 bytes) ---- */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_180003af0(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2,
             undefined8 *param_3)

{
  IAtlStringMgr *pIVar1;
  
  pIVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager(param_2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1,pIVar1);
  ATL::CSimpleStringT<char,1>::Concatenate
            ((CSimpleStringT<char,1> *)param_1,*(char **)param_2,*(int *)(*(char **)param_2 + -0x10)
             ,(char *)*param_3,*(int *)((char *)*param_3 + -0x10));
  return param_1;
}

/* ---- FUNC 00003B70 FUN_180003b70 (171 bytes) ---- */

wchar_t * FUN_180003b70(longlong *param_1,wchar_t *param_2,int param_3)

{
  undefined1 auVar1 [16];
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  
  lVar2 = *param_1 / 10000;
  uVar3 = (longlong)param_1 + lVar2 * -80000 + 0x32;
  auVar1._8_8_ = 0;
  auVar1._0_8_ = uVar3;
  lVar4 = SUB168(ZEXT816(0x47ae147ae147ae15) * auVar1,8);
  uVar3 = (uVar3 - lVar4 >> 1) + lVar4 >> 6;
  lVar4 = (longlong)param_1 + uVar3 * -100 + lVar2 * -80000;
  if (lVar4 == 0) {
    _snwprintf_s(param_2,(longlong)param_3,0xffffffffffffffff,(wchar_t *)"$%I64d.%I64u",lVar2,uVar3)
    ;
    return param_2;
  }
  _snwprintf_s(param_2,(longlong)param_3,0xffffffffffffffff,(wchar_t *)"$%I64d.%I64u.%I64u",lVar2,
               uVar3,lVar4);
  return param_2;
}

/* ---- FUNC 00003C20 FUN_180003c20 (739 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

wchar_t * FUN_180003c20(double param_1,wchar_t *param_2,int param_3)

{
  uint uVar1;
  int *piVar2;
  ulonglong uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined1 auStack_d8 [32];
  uint local_b8;
  int local_b0;
  int local_a8;
  int local_a0;
  int local_98;
  int local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = DAT_180077818 ^ (ulonglong)auStack_d8;
  local_88 = _DAT_1800633b0;
  uStack_80 = _UNK_1800633b8;
  uVar7 = 0;
  local_b8 = 0x76c;
  local_68 = _DAT_1800633d0;
  uStack_60 = _UNK_1800633d8;
  uVar6 = 0;
  local_78 = _DAT_1800633e0;
  uStack_70 = _UNK_1800633e8;
  local_58 = _DAT_1800633c0;
  uStack_50 = _UNK_1800633c8;
  local_48 = _DAT_1800633e0;
  uStack_40 = _UNK_1800633e8;
  local_38 = _DAT_1800633d0;
  uStack_30 = _UNK_1800633d8;
  uVar5 = (uint)param_1;
  local_90 = (int)((param_1 - (double)(int)uVar5) * _DAT_1800633a8);
  local_98 = local_90 / 0x3c;
  local_90 = local_90 % 0x3c;
  local_a0 = local_98 / 0x3c;
  local_98 = local_98 % 0x3c;
  uVar3 = uVar7;
  if ((int)uVar5 < 0) {
    uVar5 = (uVar5 ^ (int)uVar5 >> 0x1f) - ((int)uVar5 >> 0x1f);
    while ((((int)uVar3 != 0 && (0x16e < (int)uVar5)) || (0x16d < (int)uVar5))) {
      local_b8 = local_b8 - 1;
      uVar5 = uVar5 + (-0x16d - (int)uVar3);
      uVar6 = local_b8 & 0x80000003;
      if ((int)uVar6 < 0) {
        uVar6 = (uVar6 - 1 | 0xfffffffc) + 1;
      }
      uVar3 = uVar7;
      if ((uVar6 == 0) &&
         ((local_b8 != ((int)local_b8 / 100) * 100 || (local_b8 == ((int)local_b8 / 400) * 400)))) {
        uVar3 = 1;
      }
    }
    uVar6 = 0xb;
    if (*(int *)((longlong)&uStack_60 + uVar3 * 0x30 + 4) < (int)uVar5) {
      iVar4 = *(int *)((longlong)&uStack_60 + uVar3 * 0x30 + 4);
      piVar2 = (int *)((longlong)&uStack_60 + uVar3 * 0x30 + 4);
      uVar6 = 0xb;
      do {
        uVar5 = uVar5 - iVar4;
        piVar2 = piVar2 + -1;
        iVar4 = *piVar2;
        uVar6 = uVar6 - 1;
      } while (iVar4 < (int)uVar5);
    }
  }
  else {
    while ((((int)uVar3 != 0 && (0x16e < (int)uVar5)) || (0x16d < (int)uVar5))) {
      local_b8 = local_b8 + 1;
      uVar5 = uVar5 + (-0x16d - (int)uVar3);
      uVar1 = local_b8 & 0x80000003;
      if ((int)uVar1 < 0) {
        uVar1 = (uVar1 - 1 | 0xfffffffc) + 1;
      }
      uVar3 = uVar7;
      if ((uVar1 == 0) &&
         ((local_b8 != ((int)local_b8 / 100) * 100 || (local_b8 == ((int)local_b8 / 400) * 400)))) {
        uVar3 = 1;
      }
    }
    piVar2 = (int *)(&local_88 + uVar3 * 6);
    if (*piVar2 < (int)uVar5) {
      iVar4 = *(int *)(&local_88 + uVar3 * 6);
      do {
        uVar5 = uVar5 - iVar4;
        piVar2 = piVar2 + 1;
        iVar4 = *piVar2;
        uVar6 = (int)uVar7 + 1;
        uVar7 = (ulonglong)uVar6;
      } while (iVar4 < (int)uVar5);
    }
  }
  local_a8 = uVar5 + 1;
  local_b0 = uVar6 + 1;
  _snwprintf_s(param_2,(longlong)param_3,0xffffffffffffffff,
               (wchar_t *)"%04u/%02u/%02u-%02u:%02u:%02u");
  return param_2;
}

/* ---- FUNC 00003F10 FUN_180003f10 (95 bytes) ---- */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_180003f10(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,ushort *param_2
             )

{
  char *pcVar1;
  
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1,"");
  pcVar1 = ATL::CSimpleStringT<char,1>::GetBufferSetLength((CSimpleStringT<char,1> *)param_1,0x100);
  FUN_180004cb0(param_2,pcVar1,0x100);
  return param_1;
}

/* ---- FUNC 00003F70 FUN_180003f70 (1994 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

wchar_t * FUN_180003f70(int param_1,wchar_t *param_2,int param_3)

{
  ushort uVar1;
  undefined8 uVar3;
  char *_Format;
  ushort uVar4;
  undefined1 auStack_98 [32];
  int local_78;
  char *local_70;
  undefined *local_68;
  undefined8 local_60;
  char local_58 [8];
  char local_50 [4];
  char local_4c [2];
  char local_4a;
  undefined1 local_49;
  char local_48 [8];
  char local_40 [4];
  char local_3c [2];
  char local_3a;
  undefined1 local_39;
  ulonglong local_38;
  ushort uVar2;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStack_98;
  local_58 = (char  [8])s_Success________180062d00._0_8_;
  uVar2 = (ushort)((uint)param_1 >> 0x10);
  uVar1 = uVar2 & 0x7ff;
  uVar4 = (short)uVar2 >> 0xf & 1;
  local_48 = (char  [8])s_Error__________180062d10._0_8_;
  uVar2 = 0x1e;
  if (uVar1 < 0x51) {
    uVar2 = uVar1;
  }
  local_50 = (char  [4])s_Success________180062d00._8_4_;
  local_4c = (char  [2])s_Success________180062d00._12_2_;
  local_4a = s_Success________180062d00[0xe];
  local_49 = 0;
  local_40 = (char  [4])s_Error__________180062d10._8_4_;
  local_3c = (char  [2])s_Error__________180062d10._12_2_;
  local_3a = s_Error__________180062d10[0xe];
  local_39 = 0;
  uVar3 = FUN_180004780((longlong)param_2);
  if (((int)uVar3 != 0) || (param_3 == 0)) {
    return (wchar_t *)"(Invalid Buffer)";
  }
  if (param_1 < -0x7ffdfffe) {
    if (param_1 == -0x7ffdffff) {
      local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
      local_70 = local_48;
      local_60 = "DISP_E_UNKNOWNINTERFACE: Unknown IDispatch Interface";
    }
    else if (param_1 < -0x7fffbffb) {
      if (param_1 == -0x7fffbffc) {
        local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
        local_70 = local_48;
        local_60 = "E_ABORT: Operation aborted";
      }
      else if (param_1 == -0x7fffbfff) {
        local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
        local_70 = local_48;
        local_60 = "E_NOTIMPL: Not implemented";
      }
      else if (param_1 == -0x7fffbffe) {
        local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
        local_70 = local_48;
        local_60 = "E_NOINTERFACE: No such interface supported";
      }
      else {
        if (param_1 != -0x7fffbffd) goto switchD_180004234_default;
        local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
        local_70 = local_48;
        local_60 = "E_POINTER: Invalid pointer";
      }
    }
    else if (param_1 == -0x7fffbffb) {
      local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
      local_70 = local_48;
      local_60 = "E_FAIL: Unspecified error";
    }
    else {
      if (param_1 != -0x7fff0001) {
switchD_180004234_default:
        local_60 = (char *)(CONCAT44(local_60._4_4_,param_1) & 0xffffffff0000ffff);
        _Format = "0X%08X - %s Facility[%s], Code[0X%04X]";
        local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
        local_70 = local_58 + (ulonglong)uVar4 * 0x10;
        goto LAB_1800046ee;
      }
      local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
      local_70 = local_48;
      local_60 = "E_UNEXPECTED: Catastrophic failure";
    }
  }
  else if (param_1 < -0x7ff8fffa) {
    if (param_1 == -0x7ff8fffb) {
      local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
      local_70 = local_48;
      local_60 = "E_ACCESSDENIED: General access denied error";
    }
    else {
      switch(param_1) {
      case -0x7ffdfffd:
        local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
        local_70 = local_58 + (ulonglong)uVar4 * 0x10;
        local_60 = "DISP_E_MEMBERNOTFOUND: Class Member not found";
        break;
      case -0x7ffdfffc:
        local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
        local_70 = local_58 + (ulonglong)uVar4 * 0x10;
        local_60 = "DISP_E_PARAMNOTFOUND: Member Function Parameter not found";
        break;
      case -0x7ffdfffb:
        local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
        local_70 = local_58 + (ulonglong)uVar4 * 0x10;
        local_60 = "DISP_E_TYPEMISMATCH: Member Function Parameter Type mismatch";
        break;
      case -0x7ffdfffa:
        local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
        local_70 = local_58 + (ulonglong)uVar4 * 0x10;
        local_60 = "DISP_E_UNKNOWNNAME: Unknown Member Function Name";
        break;
      case -0x7ffdfff9:
        local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
        local_70 = local_58 + (ulonglong)uVar4 * 0x10;
        local_60 = "DISP_E_NONAMEDARGS: This Class\'s IDispatch does not support named arguments";
        break;
      case -0x7ffdfff8:
        local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
        local_70 = local_58 + (ulonglong)uVar4 * 0x10;
        local_60 = "DISP_E_BADVARTYPE: Argument(s) are not supported variant type(s)";
        break;
      case -0x7ffdfff7:
        local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
        local_70 = local_58 + (ulonglong)uVar4 * 0x10;
        local_60 = "DISP_E_EXCEPTION: Exception occurred";
        break;
      case -0x7ffdfff6:
        local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
        local_70 = local_58 + (ulonglong)uVar4 * 0x10;
        local_60 = "DISP_E_OVERFLOW: Arithmetic Overflow or Value Out of Range";
        break;
      case -0x7ffdfff5:
        local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
        local_70 = local_58 + (ulonglong)uVar4 * 0x10;
        local_60 = "DISP_E_BADINDEX: Invalid index";
        break;
      case -0x7ffdfff4:
        local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
        local_70 = local_58 + (ulonglong)uVar4 * 0x10;
        local_60 = "DISP_E_UNKNOWNLCID: Unknown language";
        break;
      case -0x7ffdfff3:
        local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
        local_70 = local_58 + (ulonglong)uVar4 * 0x10;
        local_60 = "DISP_E_ARRAYISLOCKED: SAFEARRAY Memory is locked";
        break;
      case -0x7ffdfff2:
        local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
        local_70 = local_58 + (ulonglong)uVar4 * 0x10;
        local_60 = "DISP_E_BADPARAMCOUNT: Invalid number of parameters to Member Function";
        break;
      case -0x7ffdfff1:
        local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
        local_70 = local_58 + (ulonglong)uVar4 * 0x10;
        local_60 = "DISP_E_PARAMNOTOPTIONAL: A required parameter was omitted";
        break;
      case -0x7ffdfff0:
        local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
        local_70 = local_58 + (ulonglong)uVar4 * 0x10;
        local_60 = "DISP_E_BADCALLEE: Member Function not CLS-compliant or Untrusted Caller";
        break;
      case -0x7ffdffef:
        local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
        local_70 = local_58 + (ulonglong)uVar4 * 0x10;
        local_60 = "DISP_E_NOTACOLLECTION: Does not support a collection argument";
        break;
      case -0x7ffdffee:
        local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
        local_70 = local_58 + (ulonglong)uVar4 * 0x10;
        local_60 = "DISP_E_DIVBYZERO: Division by zero";
        break;
      case -0x7ffdffed:
        local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
        local_70 = local_58 + (ulonglong)uVar4 * 0x10;
        local_60 = "DISP_E_BUFFERTOOSMALL: Output Buffer too small";
        break;
      default:
        goto switchD_180004234_default;
      }
    }
  }
  else if (param_1 == -0x7ff8fffa) {
    local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
    local_70 = local_48;
    local_60 = "E_HANDLE: Invalid handle";
  }
  else {
    if (param_1 == -0x7ff8fff2) {
      _Format = "0X%08X - %s Facility[%s], Code[%S]";
      local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
      local_70 = local_48;
      local_60 = "E_OUTOFMEMORY: Out of memory";
      goto LAB_1800046ee;
    }
    if (param_1 == -0x7ff8ffa9) {
      local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
      local_70 = local_48;
      local_60 = "E_INVALIDARG: One or more arguments are invalid";
    }
    else if (param_1 == 0) {
      local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
      local_70 = local_58;
      local_60 = "S_OK: Successful";
    }
    else {
      if (param_1 != 1) goto switchD_180004234_default;
      local_68 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
      local_70 = local_58;
      local_60 = "S_FALSE: Not successful";
    }
  }
  _Format = "0X%08X - %s Facility[%s], Code[%s]";
LAB_1800046ee:
  local_78 = param_1;
  _snwprintf_s(param_2,(longlong)param_3,0xffffffffffffffff,(wchar_t *)_Format);
  return param_2;
}

/* ---- FUNC 00004780 FUN_180004780 (174 bytes) ---- */

undefined8 FUN_180004780(longlong param_1)

{
  if ((((((0xfffe < param_1 - 1U) && (param_1 != -0x2323232323232324)) &&
        (param_1 != -0x3232323232323233)) &&
       ((param_1 != -0x2222222222222223 && (param_1 != -0x3333333333333334)))) &&
      ((param_1 != -0x202020202020203 &&
       ((param_1 != -0x5454545454545455 && (param_1 != -0x45520ff245520ff3)))))) &&
     ((param_1 != -0x2152215221522153 && (param_1 != -0x2152411021524111)))) {
    return 0;
  }
  return 1;
}

/* ---- FUNC 00004830 FUN_180004830 (492 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char * FUN_180004830(char *param_1)

{
  char cVar1;
  errno_t eVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_138 [32];
  char local_118 [256];
  ulonglong local_18;
  
  local_18 = DAT_180077818 ^ (ulonglong)auStack_138;
  if (param_1 == (char *)0x0) {
    param_1 = "(null)";
  }
  else if ((longlong)param_1 < 0x10000) {
    param_1 = "(Low Mem pointer <= 0x0000ffff)";
  }
  else if (param_1 == (char *)0xdcdcdcdcdcdcdcdc) {
    param_1 = "(Clean Mem pointer == 0xdcdcdcdcdcdcdcdc)";
  }
  else if (param_1 == (char *)0xcdcdcdcdcdcdcdcd) {
    param_1 = "(Clean Mem pointer == 0xcdcdcdcdcdcdcdcd)";
  }
  else if (param_1 == (char *)0xdddddddddddddddd) {
    param_1 = "(Dead Mem pointer == 0xdddddddddddddddd)";
  }
  else if (param_1 == (char *)0xcccccccccccccccc) {
    param_1 = "(Uninitialized pointer == 0xcccccccccccccccc)";
  }
  else if (param_1 == (char *)0xfdfdfdfdfdfdfdfd) {
    param_1 = "(Fence Memory pointer == 0xfdfdfdfdfdfdfdfd, indexing arrays out of bounds)";
  }
  else if (param_1 == (char *)0xabababababababab) {
    param_1 = 
    "(Allocated Block == 0xabababababababab, Uninitialized Memory allocated by LocalAlloc())";
  }
  else if (param_1 == (char *)0xbaadf00dbaadf00d) {
    param_1 = 
    "(Uninitialized Block == 0xbaadf00dbaadf00d, Uninitialized Memory allocated by LocalAlloc(LMEM_FIXED))"
    ;
  }
  else if (param_1 == (char *)0xbaadbaadbaadbaad) {
    param_1 = 
    "(Uninitialized Block == 0xbaadbaadbaadbaad, Uninitialized Memory allocated by User Malloc())";
  }
  else if (param_1 == (char *)0xdeaddeaddeaddead) {
    param_1 = "(Dead Block == 0xdeaddeaddeaddead, Freed Memory allocated by User Malloc())";
  }
  else if (param_1 == (char *)0xdeadbeefdeadbeef) {
    param_1 = "(Dead Block == 0xdeadbeefdeadbeef, Freed Memory allocated by User Malloc())";
  }
  else if (*param_1 == '\0') {
    param_1 = "(empty)";
  }
  else {
    eVar2 = strncpy_s(local_118,0x100,param_1,0xff);
    if (eVar2 == 0) {
      for (iVar4 = 0; iVar4 < 0x100; iVar4 = iVar4 + 1) {
        cVar1 = local_118[iVar4];
        if (cVar1 == '\0') {
          return param_1;
        }
        if (cVar1 < '\0') {
          return "(not-printable)";
        }
        iVar3 = isprint((int)cVar1);
        if (iVar3 == 0) {
          return "(not-printable)";
        }
      }
    }
    else {
      param_1 = "(invalid [strlen > 255])";
    }
  }
  return param_1;
}

/* ---- FUNC 00004A20 FUN_180004a20 (166 bytes) ---- */

undefined8 FUN_180004a20(longlong param_1)

{
  if ((((((0xffff < param_1) && (param_1 != -0x2323232323232324)) &&
        (param_1 != -0x3232323232323233)) &&
       ((param_1 != -0x2222222222222223 && (param_1 != -0x3333333333333334)))) &&
      ((param_1 != -0x202020202020203 &&
       ((param_1 != -0x5454545454545455 && (param_1 != -0x45520ff245520ff3)))))) &&
     ((param_1 != -0x2152215221522153 && (param_1 != -0x2152411021524111)))) {
    return 0;
  }
  return 1;
}

/* ---- FUNC 00004AD0 FUN_180004ad0 (477 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char * FUN_180004ad0(uint param_1,char *param_2,int param_3)

{
  undefined8 uVar1;
  char *_Format;
  ushort uVar2;
  ushort uVar3;
  undefined1 auStack_c8 [32];
  uint local_a8;
  char *local_a0;
  undefined *local_98;
  uint local_90;
  char local_88 [8];
  char local_80 [4];
  char local_7c [2];
  char local_7a;
  undefined1 local_79;
  char local_78 [8];
  char local_70 [4];
  char local_6c [2];
  char local_6a;
  undefined1 local_69;
  char local_68 [8];
  char local_60 [4];
  char local_5c [2];
  char local_5a;
  undefined1 local_59;
  char local_58 [8];
  char local_50 [4];
  char local_4c [2];
  char local_4a;
  undefined1 local_49;
  ulonglong local_48;
  ushort uVar4;
  
  local_48 = DAT_180077818 ^ (ulonglong)auStack_c8;
  local_88 = (char  [8])s_Success________180062d00._0_8_;
  uVar4 = (ushort)(param_1 >> 0x10);
  uVar3 = uVar4 & 0xfff;
  local_80 = (char  [4])s_Success________180062d00._8_4_;
  local_7c = (char  [2])s_Success________180062d00._12_2_;
  local_7a = s_Success________180062d00[0xe];
  local_78 = (char  [8])s_Informational__180063358._0_8_;
  local_68 = (char  [8])s_Warning________180063368._0_8_;
  uVar2 = 0x1e;
  if (uVar3 < 0x51) {
    uVar2 = uVar3;
  }
  local_58 = (char  [8])s_Error__________180062d10._0_8_;
  local_79 = 0;
  local_70 = (char  [4])s_Informational__180063358._8_4_;
  local_6c = (char  [2])s_Informational__180063358._12_2_;
  local_6a = s_Informational__180063358[0xe];
  local_69 = 0;
  local_60 = (char  [4])s_Warning________180063368._8_4_;
  local_5c = (char  [2])s_Warning________180063368._12_2_;
  local_5a = s_Warning________180063368[0xe];
  local_59 = 0;
  local_50 = (char  [4])s_Error__________180062d10._8_4_;
  local_4c = (char  [2])s_Error__________180062d10._12_2_;
  local_4a = s_Error__________180062d10[0xe];
  local_49 = 0;
  uVar1 = FUN_180004780((longlong)param_2);
  if (((int)uVar1 == 0) && (param_3 != 0)) {
    local_90 = param_1 & 0xffff;
    local_a0 = local_88 + (ulonglong)((int)param_1 >> 0x1e & 3) * 0x10;
    if (((short)uVar4 >> 0xd & 1U) == 0) {
      local_98 = &DAT_180077010 + (ulonglong)uVar2 * 0x12;
      _Format = "0X%08X - %s Facility[%s], Code[0X%04X]";
    }
    else {
      local_98 = (undefined *)CONCAT44(local_98._4_4_,(uint)uVar3);
      _Format = "0X%08X - %s Facility[0X%04X], Code[0X%04X]";
    }
    local_a8 = param_1;
    _snwprintf_s((wchar_t *)param_2,(longlong)param_3,0xffffffffffffffff,(wchar_t *)_Format);
  }
  else {
    param_2 = "(Invalid Buffer)";
  }
  return param_2;
}

/* ---- FUNC 00004CB0 FUN_180004cb0 (3071 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

char * FUN_180004cb0(ushort *param_1,char *param_2,int param_3)

{
  HRESULT HVar1;
  int iVar2;
  undefined8 uVar3;
  ushort *puVar4;
  longlong lVar5;
  char cVar6;
  ushort uVar7;
  undefined4 uVar8;
  float *pfVar9;
  wchar_t *pwVar10;
  longlong lVar11;
  uint uVar12;
  SAFEARRAY *psa;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  uint uVar18;
  char *pcVar19;
  LPCWSTR pWVar20;
  char *pcVar21;
  ulonglong uVar22;
  size_t _SizeInWords;
  ushort uVar23;
  int iVar24;
  float fVar25;
  undefined8 uStack_1b0;
  undefined1 auStack_1a8 [32];
  wchar_t *local_188;
  wchar_t *local_180;
  wchar_t *local_178 [2];
  float *local_168;
  ushort local_160 [2];
  int iStack_15c;
  wchar_t *local_158;
  float *local_150;
  wchar_t local_148 [128];
  ulonglong local_48;
  
  puVar15 = auStack_1a8;
  puVar14 = auStack_1a8;
  puVar17 = auStack_1a8;
  puVar13 = auStack_1a8;
  puVar16 = auStack_1a8;
  local_48 = DAT_180077818 ^ (ulonglong)&local_168;
  _SizeInWords = (size_t)param_3;
  uStack_1b0 = 0x180004cf1;
  uVar3 = FUN_180004a20((longlong)param_2);
  if ((int)uVar3 != 0) {
    uStack_1b0 = 0x180004cfd;
    param_2 = FUN_180004830(param_2);
    puVar17 = auStack_1a8;
    goto LAB_180005886;
  }
  if (param_3 < 4) {
    param_2 = "valueLen too small";
    puVar17 = auStack_1a8;
    goto LAB_180005886;
  }
  uStack_1b0 = 0x180004d1c;
  uVar3 = FUN_180004780((longlong)param_1);
  if ((int)uVar3 != 0) {
    uStack_1b0 = 0x180004d39;
    _snwprintf_s((wchar_t *)param_2,_SizeInWords,0xffffffffffffffff,
                 (wchar_t *)"INVALID_VARIANT_POINTER");
    puVar17 = auStack_1a8;
    goto LAB_180005886;
  }
  uStack_1b0 = 0x180004d4c;
  memset(param_2,0x20,_SizeInWords - 1);
  *param_2 = '\0';
  uVar7 = *param_1;
  pcVar19 = "";
  uVar23 = uVar7 & 0x4000;
  if (uVar23 != 0) {
    pcVar19 = " (byref) ";
  }
  local_158 = (wchar_t *)pcVar19;
  pwVar10 = (wchar_t *)param_2;
  if (((uVar7 & 0x3000) != 0) || ((uVar7 & 0x8fff) == 0x1b)) {
    psa = *(SAFEARRAY **)(param_1 + 4);
    puVar13 = (undefined1 *)0x0;
    uVar12 = 0;
    local_168 = (float *)0x0;
    if (uVar23 != 0) {
      psa = *(SAFEARRAY **)psa;
    }
    uStack_1b0 = 0x1800052ae;
    HVar1 = SafeArrayAccessData(psa,&local_168);
    if (HVar1 < 0) {
      pcVar19 = "(SAFEARRAY)%s";
      local_188 = local_158;
      goto LAB_180005877;
    }
    iVar24 = psa->rgsabound[0].cElements - psa->rgsabound[0].lLbound;
    local_160[0] = uVar7 & 0x8fff;
    if (psa->cDims != 1) {
      pcVar19 = "(SAFEARRAY Dim!=1)%s";
      puVar14 = auStack_1a8;
      local_188 = local_158;
      goto LAB_180005877;
    }
    if ((psa->fFeatures & 0x80) != 0) {
      uStack_1b0 = 0x1800052e8;
      SafeArrayGetVartype(psa,local_160);
    }
    lVar11 = (longlong)iVar24;
    switch(local_160[0]) {
    case 2:
      uVar12 = 0;
      if (0 < iVar24) {
        puVar15 = puVar13;
        pfVar9 = local_168;
        do {
          uVar12 = (uint)puVar13;
          if (param_3 + -8 <= (int)uVar12) break;
          local_188 = (wchar_t *)CONCAT44(local_188._4_4_,(int)*(short *)pfVar9);
          uStack_1b0 = 0x1800053d5;
          iVar2 = _snwprintf_s((wchar_t *)(param_2 + (int)uVar12),(longlong)(int)(param_3 - uVar12),
                               0xffffffffffffffff,(wchar_t *)"%+05hi,");
          uVar12 = uVar12 + iVar2;
          puVar13 = (undefined1 *)(ulonglong)uVar12;
          pfVar9 = (float *)((longlong)pfVar9 + 2);
          uVar18 = (int)puVar15 + 1;
          puVar15 = (undefined1 *)(ulonglong)uVar18;
        } while ((int)uVar18 < iVar24);
      }
      break;
    case 3:
      uVar12 = 0;
      if (iVar24 < 1) break;
      puVar15 = puVar13;
      pfVar9 = local_168;
      do {
        uVar12 = (uint)puVar13;
        if (param_3 + -0xd <= (int)uVar12) goto LAB_1800053e2;
        local_188 = (wchar_t *)CONCAT44(local_188._4_4_,*pfVar9);
        uStack_1b0 = 0x180005484;
        iVar2 = _snwprintf_s((wchar_t *)(param_2 + (int)uVar12),(longlong)(int)(param_3 - uVar12),
                             0xffffffffffffffff,(wchar_t *)"%+010i,");
        uVar12 = uVar12 + iVar2;
        puVar13 = (undefined1 *)(ulonglong)uVar12;
        pfVar9 = pfVar9 + 1;
        uVar18 = (int)puVar15 + 1;
        puVar15 = (undefined1 *)(ulonglong)uVar18;
      } while ((int)uVar18 < iVar24);
      param_2[(int)uVar12] = '\0';
      goto LAB_180005843;
    case 4:
      uVar12 = 0;
      if (0 < iVar24) {
        puVar15 = puVar13;
        pfVar9 = local_168;
        do {
          uVar12 = (uint)puVar13;
          if (param_3 + -0x15 <= (int)uVar12) goto LAB_1800053e2;
          local_188 = (wchar_t *)(double)*pfVar9;
          uStack_1b0 = 0x180005608;
          iVar2 = _snwprintf_s((wchar_t *)(param_2 + (int)uVar12),(longlong)(int)(param_3 - uVar12),
                               0xffffffffffffffff,(wchar_t *)"%+18.5g,");
          uVar12 = uVar12 + iVar2;
          puVar13 = (undefined1 *)(ulonglong)uVar12;
          pfVar9 = pfVar9 + 1;
          uVar18 = (int)puVar15 + 1;
          puVar15 = (undefined1 *)(ulonglong)uVar18;
        } while ((int)uVar18 < iVar24);
        param_2[(int)uVar12] = '\0';
        puVar16 = auStack_1a8;
        goto LAB_180005843;
      }
      break;
    case 5:
      uVar12 = 0;
      if (0 < iVar24) {
        puVar15 = puVar13;
        pfVar9 = local_168;
        do {
          uVar12 = (uint)puVar13;
          if (param_3 + -0x1b <= (int)uVar12) goto LAB_1800053e2;
          local_188 = *(wchar_t **)pfVar9;
          uStack_1b0 = 0x180005669;
          iVar2 = _snwprintf_s((wchar_t *)(param_2 + (int)uVar12),(longlong)(int)(param_3 - uVar12),
                               0xffffffffffffffff,(wchar_t *)"%+24.5g,");
          uVar12 = uVar12 + iVar2;
          puVar13 = (undefined1 *)(ulonglong)uVar12;
          pfVar9 = pfVar9 + 2;
          uVar18 = (int)puVar15 + 1;
          puVar15 = (undefined1 *)(ulonglong)uVar18;
        } while ((int)uVar18 < iVar24);
        param_2[(int)uVar12] = '\0';
        puVar16 = auStack_1a8;
        goto LAB_180005843;
      }
      break;
    default:
      puVar16 = auStack_1a8;
      if (0 < iVar24) {
        pfVar9 = local_168;
        do {
          uVar12 = (uint)puVar13;
          puVar16 = auStack_1a8;
          if (param_3 + -1 <= (int)uVar12) break;
          uVar12 = uVar12 + 1;
          puVar13 = (undefined1 *)(ulonglong)uVar12;
          *(undefined1 *)(((longlong)param_2 - (longlong)local_168) + (longlong)pfVar9) =
               *(undefined1 *)pfVar9;
          pfVar9 = (float *)((longlong)pfVar9 + 1);
          puVar16 = auStack_1a8;
        } while ((longlong)pfVar9 - (longlong)local_168 < lVar11);
      }
      goto LAB_18000583c;
    case 8:
      uVar12 = 0;
      local_150 = local_168;
      iStack_15c = 0;
      puVar14 = puVar13;
      puVar16 = auStack_1a8;
      if (0 < iVar24) {
        do {
          uVar12 = (uint)puVar14;
          puVar16 = puVar15;
          if (param_3 + -5 <= (int)uVar12) break;
          pWVar20 = *(LPCWSTR *)local_150;
          puVar14 = puVar13;
          if (pWVar20 != (LPCWSTR)0x0) {
            lVar11 = -1;
            do {
              lVar5 = lVar11;
              lVar11 = lVar5 + 1;
            } while (pWVar20[lVar11] != L'\0');
            iVar2 = (int)lVar5 + 2;
            if (iVar2 < 0x40000000) {
              lVar11 = (longlong)(int)lVar11 * 2;
              uVar22 = lVar11 + 0x11;
              if (uVar22 <= lVar11 + 2U) {
                uVar22 = 0xffffffffffffff0;
              }
              *(undefined8 *)(puVar15 + -8) = 0x180005777;
              lVar11 = -(uVar22 & 0xfffffffffffffff0);
              puVar17 = puVar15 + lVar11 + 0x40;
              puVar16 = puVar15 + lVar11;
              if (puVar17 != (undefined1 *)0x0) {
                *(undefined8 *)(puVar15 + lVar11 + 0x38) = 0;
                *(undefined8 *)(puVar15 + lVar11 + 0x30) = 0;
                *(int *)(puVar15 + lVar11 + 0x28) = iVar2 * 2;
                *puVar17 = 0;
                *(undefined1 **)(puVar15 + lVar11 + 0x20) = puVar17;
                *(undefined8 *)(puVar15 + lVar11 + -8) = 0x1800057ab;
                iVar2 = WideCharToMultiByte(0,0,pWVar20,-1,*(LPSTR *)(puVar15 + lVar11 + 0x20),
                                            *(int *)(puVar15 + lVar11 + 0x28),
                                            *(LPCSTR *)(puVar15 + lVar11 + 0x30),
                                            *(LPBOOL *)(puVar15 + lVar11 + 0x38));
                puVar16 = puVar15 + lVar11;
                puVar14 = puVar17;
                if (iVar2 == 0) {
                  puVar16 = puVar15 + lVar11;
                  puVar14 = puVar13;
                }
              }
            }
          }
          *(undefined1 **)(puVar16 + 0x20) = puVar14;
          *(undefined8 *)(puVar16 + -8) = 0x1800057dc;
          iVar2 = _snwprintf_s((wchar_t *)(param_2 + (int)uVar12),(longlong)(int)(param_3 - uVar12),
                               0xffffffffffffffff,(wchar_t *)"\"%s\",");
          uVar12 = uVar12 + iVar2;
          iStack_15c = iStack_15c + 1;
          local_150 = local_150 + 2;
          puVar14 = (undefined1 *)(ulonglong)uVar12;
          puVar15 = puVar16;
        } while (iStack_15c < iVar24);
      }
      goto LAB_18000583c;
    case 0xb:
      uVar12 = 0;
      puVar15 = puVar13;
      pfVar9 = local_168;
      if (0 < iVar24) {
        do {
          uVar12 = (uint)puVar13;
          if (param_3 + -7 <= (int)uVar12) goto LAB_1800053e2;
          local_188 = L"false";
          if (*(short *)pfVar9 == -1) {
            local_188 = L" true";
          }
          uStack_1b0 = 0x1800056dd;
          iVar2 = _snwprintf_s((wchar_t *)(param_2 + (int)uVar12),(longlong)(int)(param_3 - uVar12),
                               0xffffffffffffffff,L"猥,┢≳,");
          uVar12 = uVar12 + iVar2;
          puVar13 = (undefined1 *)(ulonglong)uVar12;
          uVar18 = (int)puVar15 + 1;
          puVar15 = (undefined1 *)(ulonglong)uVar18;
          pfVar9 = (float *)((longlong)pfVar9 + 2);
        } while ((int)uVar18 < iVar24);
        param_2[(int)uVar12] = '\0';
        puVar16 = auStack_1a8;
        goto LAB_180005843;
      }
      break;
    case 0x10:
      uVar12 = 0;
      puVar16 = auStack_1a8;
      if (0 < iVar24) {
        pfVar9 = local_168;
        do {
          uVar12 = (uint)puVar13;
          puVar16 = auStack_1a8;
          if (param_3 + -1 <= (int)uVar12) break;
          uVar12 = uVar12 + 1;
          puVar13 = (undefined1 *)(ulonglong)uVar12;
          *(undefined1 *)((longlong)pfVar9 + ((longlong)param_2 - (longlong)local_168)) =
               *(undefined1 *)pfVar9;
          pfVar9 = (float *)((longlong)pfVar9 + 1);
          puVar16 = auStack_1a8;
        } while ((longlong)pfVar9 - (longlong)local_168 < lVar11);
      }
      goto LAB_18000583c;
    case 0x11:
      uVar12 = 0;
      puVar16 = auStack_1a8;
      if (0 < iVar24) {
        pfVar9 = local_168;
        do {
          uVar12 = (uint)puVar13;
          puVar16 = auStack_1a8;
          if (param_3 + -1 <= (int)uVar12) break;
          uVar12 = uVar12 + 1;
          puVar13 = (undefined1 *)(ulonglong)uVar12;
          *(undefined1 *)(((longlong)param_2 - (longlong)local_168) + (longlong)pfVar9) =
               *(undefined1 *)pfVar9;
          pfVar9 = (float *)((longlong)pfVar9 + 1);
          puVar16 = auStack_1a8;
        } while ((longlong)pfVar9 - (longlong)local_168 < lVar11);
      }
LAB_18000583c:
      param_2[(int)uVar12] = '\0';
      goto LAB_180005843;
    case 0x12:
      uVar12 = 0;
      if (0 < iVar24) {
        puVar15 = puVar13;
        pfVar9 = local_168;
        do {
          uVar12 = (uint)puVar13;
          if (param_3 + -8 <= (int)uVar12) goto LAB_1800053e2;
          local_188 = (wchar_t *)CONCAT44(local_188._4_4_,(uint)*(ushort *)pfVar9);
          uStack_1b0 = 0x18000542f;
          iVar2 = _snwprintf_s((wchar_t *)(param_2 + (int)uVar12),(longlong)(int)(param_3 - uVar12),
                               0xffffffffffffffff,(wchar_t *)"+%05hu,");
          uVar12 = uVar12 + iVar2;
          puVar13 = (undefined1 *)(ulonglong)uVar12;
          pfVar9 = (float *)((longlong)pfVar9 + 2);
          uVar18 = (int)puVar15 + 1;
          puVar15 = (undefined1 *)(ulonglong)uVar18;
        } while ((int)uVar18 < iVar24);
        param_2[(int)uVar12] = '\0';
        puVar16 = auStack_1a8;
        goto LAB_180005843;
      }
      break;
    case 0x13:
      uVar12 = 0;
      if (0 < iVar24) {
        puVar15 = puVar13;
        pfVar9 = local_168;
        do {
          uVar12 = (uint)puVar13;
          if (param_3 + -0xd <= (int)uVar12) goto LAB_1800053e2;
          local_188 = (wchar_t *)CONCAT44(local_188._4_4_,*pfVar9);
          uStack_1b0 = 0x1800054e1;
          iVar2 = _snwprintf_s((wchar_t *)(param_2 + (int)uVar12),(longlong)(int)(param_3 - uVar12),
                               0xffffffffffffffff,(wchar_t *)"+%010i,");
          uVar12 = uVar12 + iVar2;
          puVar13 = (undefined1 *)(ulonglong)uVar12;
          pfVar9 = pfVar9 + 1;
          uVar18 = (int)puVar15 + 1;
          puVar15 = (undefined1 *)(ulonglong)uVar18;
        } while ((int)uVar18 < iVar24);
        param_2[(int)uVar12] = '\0';
        puVar16 = auStack_1a8;
        goto LAB_180005843;
      }
      break;
    case 0x14:
      uVar12 = 0;
      if (0 < iVar24) {
        puVar15 = puVar13;
        pfVar9 = local_168;
        do {
          uVar12 = (uint)puVar13;
          if (param_3 + -0x12 <= (int)uVar12) goto LAB_1800053e2;
          local_188 = *(wchar_t **)pfVar9;
          uStack_1b0 = 0x180005542;
          iVar2 = _snwprintf_s((wchar_t *)(param_2 + (int)uVar12),(longlong)(int)(param_3 - uVar12),
                               0xffffffffffffffff,(wchar_t *)"%+015i,");
          uVar12 = uVar12 + iVar2;
          puVar13 = (undefined1 *)(ulonglong)uVar12;
          pfVar9 = pfVar9 + 2;
          uVar18 = (int)puVar15 + 1;
          puVar15 = (undefined1 *)(ulonglong)uVar18;
        } while ((int)uVar18 < iVar24);
        param_2[(int)uVar12] = '\0';
        puVar16 = auStack_1a8;
        goto LAB_180005843;
      }
      break;
    case 0x15:
      uVar12 = 0;
      if (0 < iVar24) {
        puVar15 = puVar13;
        pfVar9 = local_168;
        do {
          uVar12 = (uint)puVar13;
          if (param_3 + -0x12 <= (int)uVar12) goto LAB_1800053e2;
          local_188 = *(wchar_t **)pfVar9;
          uStack_1b0 = 0x1800055a2;
          iVar2 = _snwprintf_s((wchar_t *)(param_2 + (int)uVar12),(longlong)(int)(param_3 - uVar12),
                               0xffffffffffffffff,(wchar_t *)"+%015i,");
          uVar12 = uVar12 + iVar2;
          puVar13 = (undefined1 *)(ulonglong)uVar12;
          pfVar9 = pfVar9 + 2;
          uVar18 = (int)puVar15 + 1;
          puVar15 = (undefined1 *)(ulonglong)uVar18;
        } while ((int)uVar18 < iVar24);
        param_2[(int)uVar12] = '\0';
        puVar16 = auStack_1a8;
        goto LAB_180005843;
      }
    }
LAB_1800053e2:
    param_2[(int)uVar12] = '\0';
    puVar16 = auStack_1a8;
LAB_180005843:
    pcVar19 = "猥,┢≳,";
    _SizeInWords = (size_t)(int)(param_3 - uVar12);
    *(wchar_t **)(puVar16 + 0x20) = local_158;
    pwVar10 = (wchar_t *)(param_2 + (int)uVar12);
    puVar14 = puVar16;
LAB_180005877:
    *(undefined8 *)(puVar14 + -8) = 0x180005883;
    _snwprintf_s(pwVar10,_SizeInWords,0xffffffffffffffff,(wchar_t *)pcVar19);
    puVar17 = puVar14;
    goto LAB_180005886;
  }
  if (((uVar7 & 0xbfff) - 0x1c & 0xfff7) == 0) {
    pcVar19 = "VariantToString[Error]: can\'t convert Carray, or Record values";
LAB_180005265:
    uStack_1b0 = 0x180005277;
    _snwprintf_s((wchar_t *)param_2,_SizeInWords,0xffffffffffffffff,(wchar_t *)pcVar19);
    puVar17 = auStack_1a8;
    goto LAB_180005886;
  }
  switch(uVar7 & 0xbfff) {
  case 0:
    pcVar19 = "(EMPTY)%s";
    puVar14 = auStack_1a8;
    local_188 = local_158;
    goto LAB_180005877;
  case 1:
    pcVar19 = "(NULL)%s";
    puVar14 = auStack_1a8;
    local_188 = local_158;
    goto LAB_180005877;
  case 2:
    if (uVar23 == 0) {
      uVar7 = param_1[4];
    }
    else {
      uVar7 = **(ushort **)(param_1 + 4);
    }
    uVar12 = (uint)(short)uVar7;
    pcVar21 = "%hi%s";
    goto LAB_180004df1;
  case 3:
    if (uVar23 == 0) {
      uVar8 = *(undefined4 *)(param_1 + 4);
    }
    else {
      uVar8 = **(undefined4 **)(param_1 + 4);
    }
    pcVar21 = "椥猥";
    local_188 = (wchar_t *)CONCAT44(local_188._4_4_,uVar8);
    local_180 = (wchar_t *)pcVar19;
    break;
  case 4:
    if (uVar23 == 0) {
      fVar25 = *(float *)(param_1 + 4);
    }
    else {
      fVar25 = **(float **)(param_1 + 4);
    }
    local_188 = (wchar_t *)(double)fVar25;
    goto LAB_180004e4c;
  case 5:
    if (uVar23 == 0) {
      local_188 = *(wchar_t **)(param_1 + 4);
    }
    else {
      local_188 = (wchar_t *)**(undefined8 **)(param_1 + 4);
    }
LAB_180004e4c:
    pcVar21 = "春猥";
    puVar13 = auStack_1a8;
    local_180 = (wchar_t *)pcVar19;
    break;
  case 6:
    uStack_1b0 = 0x18000513b;
    memset(local_148,0,0x100);
    puVar4 = param_1 + 4;
    if (uVar23 != 0) {
      puVar4 = *(ushort **)puVar4;
    }
    local_150 = *(float **)puVar4;
    uStack_1b0 = 0x180005162;
    FUN_180003b70((longlong *)&local_150,local_148,0x100);
    goto LAB_1800050ab;
  case 7:
    uStack_1b0 = 0x180005178;
    memset(local_148,0,0x100);
    if (uVar23 == 0) {
      uStack_1b0 = 0x1800051ae;
      FUN_180003c20(*(double *)(param_1 + 4),local_148,0x100);
    }
    else {
      uStack_1b0 = 0x180005195;
      FUN_180003c20(**(double **)(param_1 + 4),local_148,0x100);
    }
    goto LAB_1800050ab;
  case 8:
    pWVar20 = *(LPCWSTR *)(param_1 + 4);
    if (uVar23 != 0) {
      pWVar20 = *(LPCWSTR *)pWVar20;
    }
    puVar15 = auStack_1a8;
    if (pWVar20 == (LPCWSTR)0x0) {
LAB_180004f14:
      puVar16 = (undefined1 *)0x0;
    }
    else {
      lVar11 = -1;
      do {
        lVar5 = lVar11;
        lVar11 = lVar5 + 1;
      } while (pWVar20[lVar11] != L'\0');
      iVar24 = (int)lVar5 + 2;
      puVar15 = auStack_1a8;
      if (0x3fffffff < iVar24) goto LAB_180004f14;
      lVar11 = (longlong)(int)lVar11 * 2;
      uVar22 = lVar11 + 0x11;
      if (uVar22 <= lVar11 + 2U) {
        uVar22 = 0xffffffffffffff0;
      }
      uStack_1b0 = 0x180004ed3;
      lVar11 = -(uVar22 & 0xfffffffffffffff0);
      puVar15 = auStack_1a8 + lVar11;
      puVar16 = (undefined1 *)((longlong)local_160 + lVar11 + -8);
      if (puVar16 == (undefined1 *)0x0) goto LAB_180004f14;
      *puVar16 = 0;
      *(undefined8 *)((longlong)local_178 + lVar11 + 8) = 0;
      *(undefined8 *)((longlong)local_178 + lVar11) = 0;
      *(int *)((longlong)&local_180 + lVar11) = iVar24 * 2;
      *(undefined1 **)((longlong)&local_188 + lVar11) = puVar16;
      *(undefined8 *)(auStack_1a8 + lVar11 + -8) = 0x180004f09;
      iVar24 = WideCharToMultiByte(0,0,pWVar20,-1,*(LPSTR *)((longlong)&local_188 + lVar11),
                                   *(int *)((longlong)&local_180 + lVar11),
                                   *(LPCSTR *)((longlong)local_178 + lVar11),
                                   *(LPBOOL *)((longlong)local_178 + lVar11 + 8));
      puVar15 = auStack_1a8 + lVar11;
      if (iVar24 == 0) {
        puVar15 = auStack_1a8 + lVar11;
        puVar16 = (undefined1 *)0x0;
      }
    }
    pcVar21 = "\"%s\"%s";
    *(wchar_t **)(puVar15 + 0x28) = local_158;
    *(undefined1 **)(puVar15 + 0x20) = puVar16;
    puVar13 = puVar15;
    break;
  case 9:
    local_188 = *(wchar_t **)(param_1 + 4);
    if (uVar23 != 0) {
      local_188 = *(wchar_t **)local_188;
    }
    pcVar21 = "IDispatch*[0x%p]%s";
    puVar13 = auStack_1a8;
    local_180 = (wchar_t *)pcVar19;
    break;
  case 10:
    uStack_1b0 = 0x1800050d6;
    memset(local_148,0,0x100);
    if (uVar23 == 0) {
      uStack_1b0 = 0x180005105;
      FUN_180004ad0(*(uint *)(param_1 + 4),(char *)local_148,0x100);
    }
    else {
      uStack_1b0 = 0x1800050f1;
      FUN_180004ad0(**(uint **)(param_1 + 4),(char *)local_148,0x100);
    }
    goto LAB_1800050ab;
  case 0xb:
    if (uVar23 == 0) {
      uVar7 = param_1[4];
    }
    else {
      uVar7 = **(ushort **)(param_1 + 4);
    }
    local_188 = L"false";
    if (uVar7 == 0xffff) {
      local_188 = L"牴敵";
    }
    pcVar21 = "猥猥";
    puVar13 = auStack_1a8;
    local_180 = (wchar_t *)pcVar19;
    break;
  case 0xc:
    uStack_1b0 = 0x1800051c4;
    memset(local_148,0,0x100);
    puVar4 = *(ushort **)(param_1 + 4);
    if (uVar23 != 0) {
      puVar4 = *(ushort **)puVar4;
    }
    uStack_1b0 = 0x1800051e0;
    FUN_180004cb0(puVar4,(char *)local_148,0x100);
    goto LAB_1800050ab;
  case 0xd:
    local_188 = *(wchar_t **)(param_1 + 4);
    if (uVar23 != 0) {
      local_188 = *(wchar_t **)local_188;
    }
    pcVar21 = "IUnknown*[0x%p]%s";
    puVar13 = auStack_1a8;
    local_180 = (wchar_t *)pcVar19;
    break;
  case 0xe:
    pcVar19 = "(DECIMAL)%s";
    puVar14 = auStack_1a8;
    local_188 = local_158;
    goto LAB_180005877;
  default:
    pcVar19 = "(UNSUPPORTED VARIANT TYPE)";
    goto LAB_180005265;
  case 0x10:
    if (uVar23 == 0) {
      cVar6 = (char)param_1[4];
    }
    else {
      cVar6 = **(char **)(param_1 + 4);
    }
    uVar12 = (uint)cVar6;
    pcVar21 = "[%c][%i]%s";
    goto LAB_180004f8c;
  case 0x11:
    if (uVar23 == 0) {
      pcVar21 = "[%c][0x%02X]%s";
      uVar12 = (uint)(byte)param_1[4];
    }
    else {
      pcVar21 = "[%c][0x%02X]%s";
      uVar12 = (uint)**(byte **)(param_1 + 4);
    }
LAB_180004f8c:
    local_180 = (wchar_t *)CONCAT44(local_180._4_4_,uVar12);
    local_188 = (wchar_t *)CONCAT44(local_188._4_4_,uVar12);
    uStack_1b0 = 0x180004fab;
    local_178[0] = (wchar_t *)pcVar19;
    _snwprintf_s((wchar_t *)param_2,_SizeInWords,0xffffffffffffffff,(wchar_t *)pcVar21);
    goto LAB_180005886;
  case 0x12:
    if (uVar23 == 0) {
      pcVar21 = "%hu%s";
      uVar12 = (uint)param_1[4];
    }
    else {
      pcVar21 = "%hu%s";
      uVar12 = (uint)**(ushort **)(param_1 + 4);
    }
LAB_180004df1:
    local_188 = (wchar_t *)CONCAT44(local_188._4_4_,uVar12);
    puVar13 = auStack_1a8;
    local_180 = (wchar_t *)pcVar19;
    break;
  case 0x13:
    if (uVar23 == 0) {
      uVar8 = *(undefined4 *)(param_1 + 4);
    }
    else {
      uVar8 = **(undefined4 **)(param_1 + 4);
    }
    pcVar21 = "甥猥";
    local_188 = (wchar_t *)CONCAT44(local_188._4_4_,uVar8);
    puVar13 = auStack_1a8;
    local_180 = (wchar_t *)pcVar19;
    break;
  case 0x14:
    local_188 = *(wchar_t **)(param_1 + 4);
    if (uVar23 != 0) {
      local_188 = *(wchar_t **)local_188;
    }
    pcVar21 = "%I64i%s";
    puVar13 = auStack_1a8;
    local_180 = (wchar_t *)pcVar19;
    break;
  case 0x15:
    if (uVar23 == 0) {
      local_188 = *(wchar_t **)(param_1 + 4);
    }
    else {
      local_188 = (wchar_t *)**(undefined8 **)(param_1 + 4);
    }
    pcVar21 = "%I64u%s";
    puVar13 = auStack_1a8;
    local_180 = (wchar_t *)pcVar19;
    break;
  case 0x18:
  case 0x1a:
    local_188 = *(wchar_t **)(param_1 + 4);
    if (uVar23 != 0) {
      local_188 = *(wchar_t **)local_188;
    }
    pcVar21 = "VOID Pointer[0x%p]%s";
    puVar13 = auStack_1a8;
    local_180 = (wchar_t *)pcVar19;
    break;
  case 0x19:
    uStack_1b0 = 0x18000508b;
    memset(local_148,0,0x100);
    if (uVar23 == 0) {
      iVar24 = *(int *)(param_1 + 4);
    }
    else {
      iVar24 = **(int **)(param_1 + 4);
    }
    uStack_1b0 = 0x1800050ab;
    FUN_180003f70(iVar24,local_148,0x100);
LAB_1800050ab:
    local_188 = local_148;
    pcVar21 = "猥猥";
    puVar13 = auStack_1a8;
    local_180 = (wchar_t *)pcVar19;
  }
  *(undefined8 *)(puVar13 + -8) = 0x180004e0c;
  _snwprintf_s((wchar_t *)param_2,_SizeInWords,0xffffffffffffffff,(wchar_t *)pcVar21);
  puVar17 = puVar13;
LAB_180005886:
  *(undefined8 *)(puVar17 + -8) = 0x180005895;
  return param_2;
}

/* ---- FUNC 00005970 FUN_180005970 (8 bytes) ---- */

undefined * FUN_180005970(void)

{
  return &DAT_180079318;
}

/* ---- FUNC 00005980 _snwprintf_s (98 bytes) ---- */

/* Library Function - Single Match
    _snwprintf_s
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

int __cdecl _snwprintf_s(wchar_t *_DstBuf,size_t _SizeInWords,size_t _MaxCount,wchar_t *_Format,...)

{
  int iVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)FUN_180002a10();
  iVar1 = __stdio_common_vsnprintf_s
                    (*puVar2,_DstBuf,_SizeInWords,_MaxCount,_Format,0,&stack0x00000028);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  return iVar1;
}

/* ---- FUNC 000059F0 FUN_1800059f0 (98 bytes) ---- */

undefined8 * FUN_1800059f0(undefined8 *param_1)

{
  *param_1 = CHAdhocPlot::vftable;
  param_1[1] = CHAdhocPlot::CImpPersistStream::vftable;
  FUN_180005bf0(param_1 + 7);
  FUN_180005c50((CPtrArray *)(param_1 + 0x11));
  FUN_180005bf0(param_1 + 0x16);
  param_1[3] = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  param_1[5] = 0;
  *(undefined4 *)(param_1 + 6) = 0;
  param_1[2] = param_1;
  return param_1;
}

/* ---- FUNC 00005A60 FUN_180005a60 (20 bytes) ---- */

undefined8 * FUN_180005a60(undefined8 *param_1)

{
  *param_1 = CHAdhocPlotCF::vftable;
  param_1[1] = 0;
  return param_1;
}

/* ---- FUNC 00005A80 FUN_180005a80 (358 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 *
FUN_180005a80(undefined8 *param_1,longlong *param_2,int param_3,int *param_4,char *param_5)

{
  int iVar1;
  int *piVar2;
  void *pvVar3;
  int iVar4;
  longlong lVar5;
  undefined1 auStack_448 [32];
  undefined8 *local_428;
  undefined1 local_418 [1008];
  ulonglong local_28;
  
  local_28 = DAT_180077818 ^ (ulonglong)auStack_448;
  local_428 = param_1;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 3));
  CPtrArray::CPtrArray((CPtrArray *)(param_1 + 4));
  *param_1 = param_2;
  if (param_2 != (longlong *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  *(int *)(param_1 + 1) = param_3;
  iVar4 = 0;
  param_1[2] = 0;
  if (param_3 == -2) {
    if (param_4 == (int *)0x0) {
      FUN_180002a20(local_418,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hadhocpl.cpp",0x524);
      LogMessage(local_418,2,1);
    }
    piVar2 = malloc(4);
    param_1[2] = piVar2;
    *piVar2 = *param_4;
  }
  else if ((-1 < param_3) && (param_4 != (int *)0x0)) {
    iVar1 = *param_4;
    piVar2 = param_4;
    while (iVar1 != -1) {
      iVar4 = iVar4 + 1;
      piVar2 = piVar2 + 1;
      iVar1 = *piVar2;
    }
    pvVar3 = malloc((longlong)(iVar4 + 1) << 2);
    param_1[2] = pvVar3;
    lVar5 = (longlong)iVar4;
    if (-1 < iVar4) {
      do {
        *(int *)(param_1[2] + lVar5 * 4) = param_4[lVar5];
        lVar5 = lVar5 + -1;
      } while (-1 < lVar5);
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 3),param_5)
  ;
  *(undefined4 *)(param_1 + 9) = 0xffffffff;
  return param_1;
}

/* ---- FUNC 00005BF0 FUN_180005bf0 (89 bytes) ---- */

undefined8 * FUN_180005bf0(undefined8 *param_1)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 3));
  CPtrArray::CPtrArray((CPtrArray *)(param_1 + 4));
  *param_1 = 0;
  *(undefined4 *)(param_1 + 1) = 0;
  param_1[2] = 0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 3),"");
  *(undefined4 *)(param_1 + 9) = 0xffffffff;
  return param_1;
}

/* ---- FUNC 00005C50 FUN_180005c50 (33 bytes) ---- */

CPtrArray * FUN_180005c50(CPtrArray *param_1)

{
  CPtrArray::CPtrArray(param_1);
  *(undefined ***)param_1 = CHPlotValDataSetArray::vftable;
  return param_1;
}

/* ---- FUNC 00005C80 FUN_180005c80 (24 bytes) ---- */

void FUN_180005c80(longlong *param_1)

{
  if ((longlong *)*param_1 != (longlong *)0x0) {
    (**(code **)(*(longlong *)*param_1 + 0x10))();
  }
  return;
}

/* ---- FUNC 00005CA0 FUN_180005ca0 (87 bytes) ---- */

void FUN_180005ca0(undefined8 *param_1)

{
  *param_1 = CHAdhocPlot::vftable;
  if ((longlong *)param_1[5] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[5] + 0x10))();
  }
  if ((longlong *)param_1[3] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[3] + 0x10))();
  }
  FUN_180005d20(param_1 + 0x16);
  FUN_180005d50((CPtrArray *)(param_1 + 0x11));
  FUN_180005d20(param_1 + 7);
  return;
}

/* ---- FUNC 00005D00 FUN_180005d00 (25 bytes) ---- */

void FUN_180005d00(undefined8 *param_1)

{
  *param_1 = CHAdhocPlotCF::vftable;
  if (*(DWORD *)((longlong)param_1 + 0xc) != 0) {
                    /* WARNING: Could not recover jumptable at 0x000180005d11. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    CoRevokeClassObject(*(DWORD *)((longlong)param_1 + 0xc));
    return;
  }
  return;
}

/* ---- FUNC 00005D20 FUN_180005d20 (39 bytes) ---- */

void FUN_180005d20(longlong *param_1)

{
  FUN_180005fc0(param_1);
  CPtrArray::~CPtrArray((CPtrArray *)(param_1 + 4));
                    /* WARNING: Could not recover jumptable at 0x000180005d40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 3));
  return;
}

/* ---- FUNC 00005D50 FUN_180005d50 (37 bytes) ---- */

void FUN_180005d50(CPtrArray *param_1)

{
  *(undefined ***)param_1 = CHPlotValDataSetArray::vftable;
  FUN_180006090(param_1);
  CPtrArray::~CPtrArray(param_1);
  return;
}

/* ---- FUNC 00005D90 FUN_180005d90 (139 bytes) ---- */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_180005d90(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2,char *param_3)

{
  IAtlStringMgr *pIVar1;
  longlong lVar2;
  
  lVar2 = 0;
  pIVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager(param_2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1,pIVar1);
  if (param_3 != (char *)0x0) {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_3[lVar2] != '\0');
  }
  ATL::CSimpleStringT<char,1>::Concatenate
            ((CSimpleStringT<char,1> *)param_1,*(char **)param_2,*(int *)(*(char **)param_2 + -0x10)
             ,param_3,(int)lVar2);
  return param_1;
}

/* ---- FUNC 00005E20 FUN_180005e20 (78 bytes) ---- */

CPtrArray * FUN_180005e20(CPtrArray *param_1,uint param_2)

{
  FUN_180005d50(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    _guard_check_icall();
  }
  return param_1;
}

/* ---- FUNC 00005E70 FUN_180005e70 (130 bytes) ---- */

void FUN_180005e70(longlong param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  puVar1 = operator_new(0x18);
  if (puVar1 == (undefined8 *)0x0) {
    puVar1 = (undefined8 *)0x0;
  }
  else {
    *puVar1 = 0;
    *(undefined4 *)(puVar1 + 1) = 0xffffffff;
    uVar2 = nan(&DAT_18006271e);
    puVar1[2] = uVar2;
  }
  puVar1[2] = param_2;
  *(undefined4 *)(puVar1 + 1) = *(undefined4 *)(param_1 + 0x30);
  CPtrArray::SetAtGrow((CPtrArray *)(param_1 + 0x20),*(__int64 *)(param_1 + 0x30),puVar1);
  *(undefined4 *)(param_1 + 0x48) = 0xffffffff;
  return;
}

/* ---- FUNC 00005F00 FUN_180005f00 (152 bytes) ---- */

void FUN_180005f00(longlong param_1,longlong *param_2,undefined4 param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  puVar1 = operator_new(0x18);
  if (puVar1 == (undefined8 *)0x0) {
    puVar1 = (undefined8 *)0x0;
  }
  else {
    *puVar1 = 0;
    *(undefined4 *)(puVar1 + 1) = 0xffffffff;
    uVar2 = nan(&DAT_18006271e);
    puVar1[2] = uVar2;
  }
  *puVar1 = param_2;
  if (param_2 != (longlong *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  *(undefined4 *)(puVar1 + 1) = param_3;
  CPtrArray::SetAtGrow((CPtrArray *)(param_1 + 0x20),*(__int64 *)(param_1 + 0x30),puVar1);
  *(undefined4 *)(param_1 + 0x48) = 0xffffffff;
  return;
}

/* ---- FUNC 00005FA0 FUN_180005fa0 (9 bytes) ---- */

void FUN_180005fa0(longlong param_1)

{
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  return;
}

/* ---- FUNC 00005FB0 FUN_180005fb0 (11 bytes) ---- */

void FUN_180005fb0(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180005fb7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(longlong **)(param_1 + 8) + 8))();
  return;
}

/* ---- FUNC 00005FC0 FUN_180005fc0 (205 bytes) ---- */

void FUN_180005fc0(longlong *param_1)

{
  ulonglong uVar1;
  longlong *plVar2;
  ulonglong uVar3;
  
  if ((longlong *)*param_1 != (longlong *)0x0) {
    (**(code **)(*(longlong *)*param_1 + 0x10))();
  }
  uVar3 = 0;
  *param_1 = 0;
  *(undefined4 *)(param_1 + 1) = 0;
  if ((void *)param_1[2] != (void *)0x0) {
    free((void *)param_1[2]);
    param_1[2] = 0;
  }
  uVar1 = param_1[6];
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar3 < 0) || (param_1[6] <= (longlong)uVar3)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar2 = *(longlong **)(param_1[5] + uVar3 * 8);
      if (plVar2 != (longlong *)0x0) {
        if ((longlong *)*plVar2 != (longlong *)0x0) {
          (**(code **)(*(longlong *)*plVar2 + 0x10))();
        }
        FUN_180025ad0(plVar2);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  CPtrArray::SetSize((CPtrArray *)(param_1 + 4),0,-1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 3),"");
  *(undefined4 *)(param_1 + 9) = 0xffffffff;
  return;
}

/* ---- FUNC 00006090 FUN_180006090 (126 bytes) ---- */

void FUN_180006090(CPtrArray *param_1)

{
  ulonglong uVar1;
  longlong *plVar2;
  ulonglong uVar3;
  
  uVar1 = *(ulonglong *)(param_1 + 0x10);
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar3 < 0) || (*(longlong *)(param_1 + 0x10) <= (longlong)uVar3)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar2 = *(longlong **)(*(longlong *)(param_1 + 8) + uVar3 * 8);
      if (plVar2 != (longlong *)0x0) {
        FUN_180005d20(plVar2);
        FUN_180025ad0(plVar2);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  CPtrArray::SetSize(param_1,0,-1);
  return;
}

/* ---- FUNC 00006110 FUN_180006110 (264 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180006110(longlong *param_1,longlong *param_2)

{
  int iVar1;
  int *piVar2;
  longlong *plVar3;
  undefined4 *puVar4;
  void *pvVar5;
  longlong *plVar6;
  uint uVar7;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong lVar12;
  undefined1 auStack_458 [32];
  longlong *local_438;
  undefined1 local_428 [1008];
  ulonglong local_38;
  longlong *plVar8;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStack_458;
  FUN_180005fc0(param_1);
  plVar11 = (longlong *)*param_2;
  *param_1 = (longlong)plVar11;
  if (plVar11 != (longlong *)0x0) {
    (**(code **)(*plVar11 + 8))();
  }
  iVar1 = (int)param_2[1];
  plVar11 = (longlong *)0x0;
  *(int *)(param_1 + 1) = iVar1;
  if (iVar1 == -2) {
    if (param_2[2] == 0) {
      FUN_180002a20(local_428,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hadhocpl.cpp",0x5ad);
      LogMessage(local_428,2,1);
    }
    puVar4 = malloc(4);
    param_1[2] = (longlong)puVar4;
    *puVar4 = *(undefined4 *)param_2[2];
  }
  else if ((-1 < iVar1) && (piVar2 = (int *)param_2[2], piVar2 != (int *)0x0)) {
    uVar7 = 0;
    iVar1 = *piVar2;
    plVar8 = plVar11;
    while (iVar1 != -1) {
      uVar7 = (int)plVar8 + 1;
      plVar8 = (longlong *)(ulonglong)uVar7;
      piVar2 = piVar2 + 1;
      iVar1 = *piVar2;
    }
    pvVar5 = malloc((longlong)(int)(uVar7 + 1) << 2);
    lVar12 = (longlong)(int)uVar7;
    param_1[2] = (longlong)pvVar5;
    if (-1 < (int)uVar7) {
      do {
        *(undefined4 *)(param_1[2] + lVar12 * 4) = *(undefined4 *)(param_2[2] + lVar12 * 4);
        lVar12 = lVar12 + -1;
      } while (-1 < lVar12);
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 3),
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_2 + 3));
  plVar8 = (longlong *)param_2[6];
  plVar10 = plVar11;
  if (plVar8 != (longlong *)0x0) {
    do {
      if (((longlong)plVar10 < 0) || (param_2[6] <= (longlong)plVar10)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar3 = *(longlong **)(param_2[5] + (longlong)plVar10 * 8);
      plVar6 = operator_new(0x18);
      plVar9 = plVar11;
      local_438 = plVar6;
      if (plVar6 != (longlong *)0x0) {
        *plVar6 = 0;
        *(undefined4 *)(plVar6 + 1) = 0xffffffff;
        lVar12 = nan(&DAT_18006271e);
        plVar6[2] = lVar12;
        plVar9 = plVar6;
      }
      plVar6 = (longlong *)*plVar3;
      *plVar9 = (longlong)plVar6;
      if (plVar6 != (longlong *)0x0) {
        (**(code **)(*plVar6 + 8))();
      }
      *(int *)(plVar9 + 1) = (int)plVar3[1];
      plVar9[2] = plVar3[2];
      CPtrArray::SetAtGrow((CPtrArray *)(param_1 + 4),param_1[6],plVar9);
      plVar10 = (longlong *)((longlong)plVar10 + 1);
    } while (plVar10 < plVar8);
  }
  *(int *)(param_1 + 9) = (int)param_2[9];
  return;
}

/* ---- FUNC 00006218 FUN_180006218 (242 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180006218(undefined8 param_1,
                  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *param_2
                  )

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong unaff_RDI;
  longlong *unaff_R12;
  longlong unaff_R14;
  longlong lVar6;
  
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_R14 + 0x18),
             param_2);
  plVar1 = *(longlong **)(unaff_RDI + 0x30);
  plVar5 = unaff_R12;
  if (plVar1 != (longlong *)0x0) {
    do {
      if (((longlong)plVar5 < 0) || (*(longlong *)(unaff_RDI + 0x30) <= (longlong)plVar5)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar2 = *(longlong **)(*(longlong *)(unaff_RDI + 0x28) + (longlong)plVar5 * 8);
      plVar3 = operator_new(0x18);
      plVar4 = unaff_R12;
      if (plVar3 != (longlong *)0x0) {
        *plVar3 = (longlong)unaff_R12;
        *(undefined4 *)(plVar3 + 1) = 0xffffffff;
        lVar6 = nan(&DAT_18006271e);
        plVar3[2] = lVar6;
        plVar4 = plVar3;
      }
      plVar3 = (longlong *)*plVar2;
      *plVar4 = (longlong)plVar3;
      if (plVar3 != (longlong *)0x0) {
        (**(code **)(*plVar3 + 8))();
      }
      *(int *)(plVar4 + 1) = (int)plVar2[1];
      plVar4[2] = plVar2[2];
      CPtrArray::SetAtGrow((CPtrArray *)(unaff_R14 + 0x20),*(__int64 *)(unaff_R14 + 0x30),plVar4);
      plVar5 = (longlong *)((longlong)plVar5 + 1);
    } while (plVar5 < plVar1);
  }
  *(undefined4 *)(unaff_R14 + 0x48) = *(undefined4 *)(unaff_RDI + 0x48);
  return;
}

/* ---- FUNC 00006310 FUN_180006310 (156 bytes) ---- */

HRESULT FUN_180006310(undefined8 *param_1)

{
  HRESULT HVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  
  puVar3 = (undefined8 *)0x0;
  *param_1 = 0;
  puVar2 = operator_new(0x100);
  if (puVar2 != (undefined8 *)0x0) {
    puVar3 = FUN_1800059f0(puVar2);
  }
  HVar1 = FUN_180033ad0(puVar3 + 3,(GUID *)&DAT_180063570);
  if (-1 < HVar1) {
    HVar1 = FUN_180050c20(puVar3 + 5);
    if (-1 < HVar1) {
      *param_1 = puVar3;
      return 0;
    }
  }
  if (puVar3 != (undefined8 *)0x0) {
    FUN_180005ca0(puVar3);
    FUN_180025ad0(puVar3);
  }
  return HVar1;
}

/* ---- FUNC 000063B0 FUN_1800063b0 (104 bytes) ---- */

void FUN_1800063b0(longlong param_1)

{
  ulonglong uVar1;
  longlong *plVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int *_Dst;
  undefined7 extraout_var;
  int iVar6;
  int iVar7;
  ulonglong uVar8;
  int *piVar9;
  _union_1719 _Var10;
  
  uVar1 = *(ulonglong *)(param_1 + 0x98);
  _Dst = malloc(uVar1 * 4);
  memset(_Dst,0,uVar1 * 4);
  FUN_180005fc0((longlong *)(param_1 + 0x38));
  *(undefined4 *)(param_1 + 0x40) = 0xffffffff;
  iVar7 = 0;
  if (uVar1 != 0) {
LAB_180006420:
    bVar3 = true;
    uVar8 = 0;
    piVar9 = _Dst;
    do {
      if (((longlong)uVar8 < 0) || (*(longlong *)(param_1 + 0x98) <= (longlong)uVar8)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar2 = *(longlong **)(*(longlong *)(param_1 + 0x90) + uVar8 * 8);
      bVar4 = FUN_1800079d0(plVar2);
      if ((int)CONCAT71(extraout_var,bVar4) != 0) {
        iVar6 = *piVar9;
        iVar5 = FUN_180007650((longlong)plVar2);
        if (iVar6 < iVar5) {
          do {
            iVar5 = FUN_180007580((longlong)plVar2,iVar6);
            if (iVar7 <= iVar5) break;
            iVar6 = iVar6 + 1;
            *piVar9 = iVar6;
            iVar5 = FUN_180007650((longlong)plVar2);
          } while (iVar6 < iVar5);
        }
        iVar5 = FUN_180007650((longlong)plVar2);
        if (iVar6 < iVar5) {
          bVar3 = false;
          iVar5 = FUN_180007580((longlong)plVar2,iVar6);
          if ((iVar5 == iVar7) && (_Var10 = FUN_180006e60(plVar2,iVar6), !NAN((double)_Var10))) {
            FUN_180005e70(param_1 + 0x38,_Var10);
            iVar7 = iVar7 + 1;
            goto LAB_180006420;
          }
        }
      }
      uVar8 = uVar8 + 1;
      piVar9 = piVar9 + 1;
    } while (uVar8 < uVar1);
    if (!bVar3) {
      iVar7 = iVar7 + 1;
      goto LAB_180006420;
    }
  }
  return;
}

/* ---- FUNC 00006418 FUN_180006418 (227 bytes) ---- */

void FUN_180006418(void)

{
  longlong *plVar1;
  bool bVar2;
  int iVar3;
  undefined7 extraout_var;
  int iVar4;
  int unaff_EBP;
  ulonglong unaff_RSI;
  int *unaff_RDI;
  int unaff_R12D;
  ulonglong unaff_R13;
  longlong unaff_R15;
  _union_1719 _Var5;
  int *in_stack_00000050;
  
  do {
    while( true ) {
      if (((longlong)unaff_RSI < 0) || (*(longlong *)(unaff_R15 + 0x98) <= (longlong)unaff_RSI)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar1 = *(longlong **)(*(longlong *)(unaff_R15 + 0x90) + unaff_RSI * 8);
      bVar2 = FUN_1800079d0(plVar1);
      if ((int)CONCAT71(extraout_var,bVar2) != 0) break;
LAB_1800064b1:
      unaff_RSI = unaff_RSI + 1;
      unaff_RDI = unaff_RDI + 1;
      if (unaff_R13 <= unaff_RSI) {
        if (unaff_R12D != 0) {
          return;
        }
        unaff_EBP = unaff_EBP + 1;
        unaff_RSI = 0;
        unaff_R12D = 1;
        unaff_RDI = in_stack_00000050;
      }
    }
    iVar4 = *unaff_RDI;
    iVar3 = FUN_180007650((longlong)plVar1);
    if (iVar4 < iVar3) {
      do {
        iVar3 = FUN_180007580((longlong)plVar1,iVar4);
        if (unaff_EBP <= iVar3) break;
        iVar4 = iVar4 + 1;
        *unaff_RDI = iVar4;
        iVar3 = FUN_180007650((longlong)plVar1);
      } while (iVar4 < iVar3);
    }
    iVar3 = FUN_180007650((longlong)plVar1);
    if (iVar3 <= iVar4) goto LAB_1800064b1;
    iVar3 = FUN_180007580((longlong)plVar1,iVar4);
    unaff_R12D = 0;
    if ((iVar3 != unaff_EBP) ||
       (_Var5 = FUN_180006e60(plVar1,iVar4), unaff_R12D = 0, NAN((double)_Var5)))
    goto LAB_1800064b1;
    FUN_180005e70(unaff_R15 + 0x38,_Var5);
    unaff_EBP = unaff_EBP + 1;
    unaff_RSI = 0;
    unaff_R12D = 1;
    unaff_RDI = in_stack_00000050;
  } while( true );
}

/* ---- FUNC 000064FB FUN_1800064fb (23 bytes) ---- */

void FUN_1800064fb(void)

{
  return;
}

/* ---- FUNC 00006512 AfxThrowInvalidArgException (5 bytes) ---- */

void __cdecl AfxThrowInvalidArgException(void)

{
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00006520 FUN_180006520 (68 bytes) ---- */

undefined8 FUN_180006520(undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 *param_4)

{
  HRESULT HVar1;
  int iVar2;
  undefined8 *local_res20;
  
  *param_4 = 0;
  if (DAT_1800797f0 != 0) {
    if (param_2 != 0) {
      return 0x80040110;
    }
    HVar1 = FUN_180006310(&local_res20);
    if (-1 < HVar1) {
      iVar2 = (**(code **)*local_res20)(local_res20,param_3,param_4);
      if (iVar2 < 0) {
        FUN_180005ca0(local_res20);
        FUN_180025ad0(local_res20);
        return 0x80004005;
      }
      return 0;
    }
  }
  return 0x80004005;
}

/* ---- FUNC 00006564 FUN_180006564 (70 bytes) ---- */

undefined8 FUN_180006564(void)

{
  int iVar1;
  undefined8 *in_stack_00000048;
  
  iVar1 = (**(code **)*in_stack_00000048)(in_stack_00000048);
  if (iVar1 < 0) {
    FUN_180005ca0(in_stack_00000048);
    FUN_180025ad0(in_stack_00000048);
    return 0x80004005;
  }
  return 0;
}

/* ---- FUNC 000065AA FUN_1800065aa (18 bytes) ---- */

undefined8 FUN_1800065aa(void)

{
  return 0;
}

/* ---- FUNC 000065BC FUN_1800065bc (16 bytes) ---- */

undefined8 FUN_1800065bc(void)

{
  return 0x80004005;
}

/* ---- FUNC 000065D0 FUN_1800065d0 (454 bytes) ---- */

longlong *
FUN_1800065d0(CPtrArray *param_1,longlong *param_2,int param_3,int *param_4,char *param_5)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  int iVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  bool bVar11;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_48 [8];
  longlong *local_40;
  
  plVar6 = (longlong *)0x0;
  local_40 = *(longlong **)(param_1 + 0x10);
  plVar9 = plVar6;
  plVar10 = plVar6;
  if (local_40 != (longlong *)0x0) {
    do {
      if (((longlong)plVar9 < 0) || (*(longlong *)(param_1 + 0x10) <= (longlong)plVar9)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar2 = *(longlong **)(*(longlong *)(param_1 + 8) + (longlong)plVar9 * 8);
      if (((longlong *)*plVar2 == param_2) && ((int)plVar2[1] == param_3)) {
        puVar5 = (undefined8 *)
                 ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                 CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_48,param_5);
        plVar10 = (longlong *)0x1;
        iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           (plVar2 + 3),(char *)*puVar5);
        if (iVar4 != 0) goto LAB_18000667b;
        bVar11 = true;
      }
      else {
LAB_18000667b:
        bVar11 = false;
      }
      if (plVar10 != (longlong *)0x0) {
        plVar10 = (longlong *)0x0;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_48);
      }
      if (!bVar11) goto LAB_180006714;
      if (param_3 == -2) {
        bVar11 = *param_4 == *(int *)plVar2[2];
LAB_180006712:
        if (bVar11) {
          return plVar2;
        }
      }
      else if (param_3 == -1) {
        if (param_4 == (int *)0x0) {
          bVar11 = plVar2[2] == 0;
          goto LAB_180006712;
        }
      }
      else if (-1 < param_3) {
        lVar3 = plVar2[2];
        if (param_4 == (int *)0x0) {
          bVar11 = lVar3 == 0;
          goto LAB_180006712;
        }
        if (lVar3 != 0) {
          iVar4 = *param_4;
          plVar7 = plVar6;
          plVar1 = plVar6;
          plVar8 = plVar6;
          while (((iVar4 != -1 && (*(int *)((longlong)plVar1 + lVar3) != -1)) &&
                 (((int)plVar8 == param_3 ||
                  (*(int *)((longlong)plVar1 + (longlong)param_4) ==
                   *(int *)((longlong)plVar1 + lVar3)))))) {
            plVar8 = (longlong *)(ulonglong)((int)plVar8 + 1);
            plVar7 = (longlong *)((longlong)plVar7 + 1);
            plVar1 = (longlong *)((longlong)plVar7 * 4);
            iVar4 = *(int *)((longlong)plVar1 + (longlong)param_4);
          }
          if (param_4[(longlong)plVar7] == -1) {
            bVar11 = *(int *)(lVar3 + (longlong)plVar7 * 4) == -1;
            goto LAB_180006712;
          }
        }
      }
LAB_180006714:
      plVar9 = (longlong *)((longlong)plVar9 + 1);
    } while (plVar9 < local_40);
  }
  puVar5 = operator_new(0x50);
  if (puVar5 != (undefined8 *)0x0) {
    plVar6 = FUN_180005a80(puVar5,param_2,param_3,param_4,param_5);
  }
  CPtrArray::SetAtGrow(param_1,*(__int64 *)(param_1 + 0x10),plVar6);
  return plVar6;
}

/* ---- FUNC 000067A0 FUN_1800067a0 (55 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1800067a0(undefined8 param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  
  iVar3 = MVGetProductCode();
  uVar2 = _UNK_1800635a8;
  uVar1 = DAT_180063588;
  if (iVar3 == 2) {
    *param_2 = _DAT_1800635a0;
    param_2[1] = uVar2;
    return 0;
  }
  *param_2 = DAT_180063580;
  param_2[1] = uVar1;
  return 0;
}

/* ---- FUNC 000067E0 FUN_1800067e0 (11 bytes) ---- */

void FUN_1800067e0(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0001800067e7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(longlong **)(param_1 + 8) + 0x68))();
  return;
}

/* ---- FUNC 000067F0 FUN_1800067f0 (1487 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_1800067f0(longlong *param_1,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2)

{
  char cVar1;
  ulonglong uVar2;
  longlong *plVar3;
  double dVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  int *piVar8;
  undefined8 *puVar9;
  IAtlStringMgr *pIVar10;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar11;
  char *pcVar12;
  longlong lVar13;
  ulonglong uVar14;
  int iVar15;
  longlong *plVar16;
  longlong lVar17;
  undefined1 auStackY_248 [32];
  char *local_218;
  char *local_210;
  undefined4 local_208;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_200;
  char *local_1f8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_1f0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_1e8 [8];
  _union_2707 local_1e0;
  _union_2707 local_1c8;
  undefined4 local_1a8;
  ULONG UStack_1a4;
  undefined4 uStack_1a0;
  undefined4 uStack_19c;
  undefined8 local_198;
  char cStack_189;
  uint local_188;
  char local_184 [252];
  char local_88 [64];
  ulonglong local_48;
  
  local_48 = DAT_180077818 ^ (ulonglong)auStackY_248;
  local_208 = 0;
  bVar6 = true;
  local_188 = local_188 & 0xffffff00;
  local_200 = param_2;
  local_1f0 = param_2;
  bVar5 = bVar6;
  if ((int)param_1[1] == -2) {
    puVar9 = (undefined8 *)
             HAGetDimensionName(*(undefined8 *)(*param_1 + 0x48),*(undefined4 *)param_1[2],
                                &local_188);
    if (puVar9 == (undefined8 *)0x0) {
      if ((char)local_188 != '\0') goto LAB_180006d23;
    }
    else if ((code *)*puVar9 != (code *)0x0) {
      (*(code *)*puVar9)(puVar9);
    }
    local_188._0_1_ = s_Label_180063844[0];
    local_188._1_1_ = s_Label_180063844[1];
    local_188._2_1_ = s_Label_180063844[2];
    local_188._3_1_ = s_Label_180063844[3];
    local_184[0] = s_Label_180063844[4];
    local_184[1] = s_Label_180063844[5];
  }
  else if ((int)param_1[1] == -1) {
    local_188 = DAT_18006384c;
    local_184[0] = DAT_180063850;
  }
  else {
    piVar8 = (int *)param_1[2];
    if ((piVar8 != (int *)0x0) && (iVar15 = 0, *piVar8 != -1)) {
      lVar17 = 0;
      lVar13 = 0;
      do {
        if (iVar15 != (int)param_1[1]) {
          local_88[0] = '\0';
          puVar9 = (undefined8 *)
                   HAGetDecoratedColumn
                             (*(undefined8 *)(*param_1 + 0x48),iVar15,
                              *(undefined4 *)(lVar13 + (longlong)piVar8),local_88);
          if (puVar9 == (undefined8 *)0x0) {
            if (local_88[0] != '\0') {
              if ((char)local_188 == '\0') {
                lVar13 = 0;
                do {
                  pcVar12 = local_88 + lVar13;
                  *(char *)((longlong)&local_188 + lVar13) = *pcVar12;
                  lVar13 = lVar13 + 1;
                } while (*pcVar12 != '\0');
              }
              else {
                pcVar12 = &cStack_189;
                do {
                  pcVar12 = pcVar12 + 1;
                } while (*pcVar12 != '\0');
                *(undefined2 *)pcVar12 = DAT_1800633a4;
                pcVar12 = &cStack_189;
                do {
                  pcVar12 = pcVar12 + 1;
                } while (*pcVar12 != '\0');
                lVar13 = 0;
                do {
                  cVar1 = local_88[lVar13];
                  pcVar12[lVar13] = cVar1;
                  lVar13 = lVar13 + 1;
                } while (cVar1 != '\0');
              }
            }
          }
          else if ((code *)*puVar9 != (code *)0x0) {
            (*(code *)*puVar9)(puVar9);
          }
        }
        iVar15 = iVar15 + 1;
        lVar17 = lVar17 + 1;
        lVar13 = lVar17 * 4;
        piVar8 = (int *)param_1[2];
      } while (piVar8[lVar17] != -1);
      bVar5 = true;
      if ((char)local_188 != '\0') goto LAB_180006d23;
    }
    uVar14 = 0;
    uVar2 = param_1[6];
    if (uVar2 != 0) {
      do {
        if (((longlong)uVar14 < 0) || ((longlong)uVar2 <= (longlong)uVar14)) {
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        lVar13 = **(longlong **)(param_1[5] + uVar14 * 8);
        if (lVar13 != 0) {
          puVar9 = (undefined8 *)HAGetDecoratedName(*(undefined8 *)(lVar13 + 0x48),&local_188);
          if (puVar9 == (undefined8 *)0x0) {
            if ((char)local_188 != '\0') {
              bVar5 = false;
              goto LAB_180006d23;
            }
          }
          else {
            if ((code *)*puVar9 != (code *)0x0) {
              (*(code *)*puVar9)(puVar9);
            }
            local_188 = local_188 & 0xffffff00;
          }
          break;
        }
        uVar14 = uVar14 + 1;
      } while (uVar14 < uVar2);
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_210,"");
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_218,"");
    for (plVar3 = (longlong *)*param_1;
        (plVar3 != (longlong *)0x0 && (param_2 = local_200, (int)plVar3[0xd] == 0));
        plVar3 = (longlong *)plVar3[0xc]) {
      puVar9 = (undefined8 *)HAGetDecoratedName(plVar3[9]);
      if (puVar9 == (undefined8 *)0x0) {
        param_2 = local_200;
        if ((char)local_188 != '\0') goto LAB_180006c65;
      }
      else {
        if ((code *)*puVar9 != (code *)0x0) {
          (*(code *)*puVar9)(puVar9);
        }
        local_188 = local_188 & 0xffffff00;
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_218,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 (plVar3 + 0x3b));
      iVar15 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          &local_218,' ',0);
      iVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_218
                         ,'.',0);
      if (-1 < iVar7) {
        AfxVariantInit((tagVARIANT *)&local_1e0.n2);
        VariantInit((VARIANTARG *)&local_1c8.n2);
        iVar7 = (int)plVar3[0xd];
        plVar16 = plVar3;
        while (bVar5 = false, iVar7 == 0) {
          plVar16 = (longlong *)plVar16[0xc];
          local_1a8 = local_1c8._0_4_;
          UStack_1a4 = local_1c8.decVal.Hi32;
          uStack_1a0 = local_1c8._8_4_;
          uStack_19c = local_1c8._12_4_;
          local_198 = local_1c8._16_8_;
          iVar7 = (**(code **)(*plVar16 + 0x98))(plVar16,0x3b,&local_1a8,&local_1e0);
          if (((-1 < iVar7) && (local_1e0.n2.vt == 8)) &&
             (iVar7 = _wcsicmp(L"BATCHFRAC",(wchar_t *)local_1e0.decVal.u2), bVar5 = true,
             iVar7 == 0)) break;
          iVar7 = (int)plVar16[0xd];
        }
        VariantClear((VARIANTARG *)&local_1e0.n2);
        if (bVar5) {
          if (-1 < iVar15) {
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_218,
                       (int)&local_1f0);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1f0);
          }
          dVar4 = atof(local_218);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_218,
                     "%g",SUB84(dVar4,0));
        }
      }
      if (*(int *)(local_210 + -0x10) == 0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_210,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   &local_218);
      }
      else {
        pIVar10 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_218);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1f8,
                   pIVar10);
        local_208 = 2;
        ATL::CSimpleStringT<char,1>::Concatenate
                  ((CSimpleStringT<char,1> *)&local_1f8,local_218,*(int *)(local_218 + -0x10)," ",1)
        ;
        pIVar10 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_1f8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1e8,pIVar10);
        local_208 = 6;
        ATL::CSimpleStringT<char,1>::Concatenate
                  ((CSimpleStringT<char,1> *)local_1e8,local_1f8,*(int *)(local_1f8 + -0x10),
                   local_210,*(int *)(local_210 + -0x10));
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_210,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   local_1e8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1e8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1f8);
      }
      param_2 = local_200;
    }
    if ((char)local_188 == '\0') {
      lVar13 = (longlong)&local_188 - (longlong)local_210;
      do {
        cVar1 = *local_210;
        local_210[lVar13] = cVar1;
        local_210 = local_210 + 1;
      } while (cVar1 != '\0');
    }
    else {
LAB_180006c65:
      pcVar12 = &cStack_189;
      do {
        pcVar12 = pcVar12 + 1;
      } while (*pcVar12 != '\0');
      *(undefined2 *)pcVar12 = DAT_1800633a4;
      pcVar12 = &cStack_189;
      do {
        pcVar12 = pcVar12 + 1;
      } while (*pcVar12 != '\0');
      lVar13 = 0;
      do {
        cVar1 = local_210[lVar13];
        pcVar12[lVar13] = cVar1;
        lVar13 = lVar13 + 1;
      } while (cVar1 != '\0');
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_218);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_210);
    bVar5 = bVar6;
  }
LAB_180006d23:
  if ((*(int *)(param_1[3] + -0x10) == 0) || (!bVar5)) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_2,(char *)&local_188);
  }
  else {
    pCVar11 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_200
                         ,(char *)&local_188);
    pCVar11 = FUN_180005d90((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_1f0,pCVar11," ");
    FUN_180003af0(param_2,pCVar11,param_1 + 3);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1f0);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_200);
  }
  return param_2;
}

/* ---- FUNC 00006DC0 FUN_180006dc0 (124 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_180006dc0(longlong *param_1,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2)

{
  undefined8 *puVar1;
  undefined1 auStack_88 [40];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_60;
  char local_58 [64];
  ulonglong local_18;
  
  local_18 = DAT_180077818 ^ (ulonglong)auStack_88;
  local_58[0] = '\0';
  local_60 = param_2;
  if (-1 < (int)param_1[1]) {
    puVar1 = (undefined8 *)
             HAGetDimensionName(*(undefined8 *)(*param_1 + 0x48),(int)param_1[1],local_58);
    if (puVar1 != (undefined8 *)0x0) {
      if ((code *)*puVar1 != (code *)0x0) {
        (*(code *)*puVar1)(puVar1);
      }
      local_58[0] = '\0';
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_2,local_58);
  return param_2;
}

/* ---- FUNC 00006E40 FUN_180006e40 (25 bytes) ---- */

void FUN_180006e40(longlong param_1,undefined8 param_2,OLECHAR **param_3,UINT param_4,
                  undefined8 param_5,DISPID *param_6)

{
                    /* WARNING: Could not recover jumptable at 0x000180006e52. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DispGetIDsOfNames(*(ITypeInfo **)(param_1 + 0x18),param_3,param_4,param_6);
  return;
}

/* ---- FUNC 00006E60 FUN_180006e60 (1813 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

_union_1719 FUN_180006e60(longlong *param_1,int param_2)

{
  code *pcVar1;
  bool bVar2;
  undefined2 uVar3;
  undefined8 uVar4;
  char cVar5;
  int iVar6;
  HRESULT HVar7;
  int iVar8;
  UINT UVar9;
  INT IVar10;
  undefined8 *puVar11;
  char *pcVar12;
  longlong lVar13;
  ulonglong uVar14;
  _union_1719 _Var15;
  longlong lVar16;
  _union_1719 _Var18;
  longlong *plVar19;
  _union_1719 _Var20;
  undefined1 *puVar21;
  undefined1 *puVar22;
  undefined1 *puVar23;
  _union_1719 _Var24;
  _union_1719 _Var25;
  ulonglong uVar26;
  undefined8 uVar27;
  undefined1 auStack_238 [32];
  _union_2707 *local_218;
  _union_2707 *local_210;
  _union_2707 local_1f8;
  _union_1719 local_1d8;
  longlong *local_1d0;
  _union_2707 local_1c8;
  _union_2707 local_1b0;
  _union_2707 local_198;
  undefined4 local_178;
  ULONG UStack_174;
  ULONG UStack_170;
  ULONG UStack_16c;
  undefined8 local_168;
  char local_158 [256];
  ulonglong local_58;
  longlong lVar17;
  
  puVar22 = auStack_238;
  puVar21 = auStack_238;
  local_58 = DAT_180077818 ^ (ulonglong)&local_1f8;
  if ((param_2 < 0) || (param_1[6] <= (longlong)param_2)) {
                    /* WARNING: Subroutine does not return */
    AfxThrowInvalidArgException();
  }
  lVar16 = *(longlong *)(param_1[5] + (longlong)param_2 * 8);
  uVar27 = nan(&DAT_18006271e);
  iVar8 = (int)param_1[1];
  if (iVar8 == -2) {
    iVar8 = *(int *)param_1[2];
  }
  puVar23 = auStack_238;
  if ((iVar8 < 0) || (puVar23 = auStack_238, *param_1 == 0)) goto LAB_18000750f;
  puVar11 = (undefined8 *)
            HAGetLabel(*(undefined8 *)(*param_1 + 0x48),iVar8,*(undefined4 *)(lVar16 + 8),local_158)
  ;
  if (puVar11 != (undefined8 *)0x0) {
    puVar23 = auStack_238;
    if ((code *)*puVar11 != (code *)0x0) {
      (*(code *)*puVar11)(puVar11);
      puVar23 = auStack_238;
    }
    goto LAB_18000750f;
  }
  _Var25.Lo64 = 0;
  local_1d0 = (longlong *)0x0;
  iVar6 = (**(code **)(*(longlong *)*param_1 + 200))((longlong *)*param_1,&local_1d0);
  bVar2 = false;
  puVar23 = auStack_238;
  if ((-1 < iVar6) && (cVar5 = FUN_18002f2c0(), puVar23 = auStack_238, cVar5 != '\0')) {
    local_1b0._0_8_ = 0;
    local_1b0.decVal.u2.Lo64 = (_union_1719)0x0;
    local_1b0._16_8_ = 0;
    VariantInit((VARIANTARG *)&local_1b0.n2);
    local_1c8._0_8_ = 0;
    local_1c8.decVal.u2.Lo64 = (_union_1719)0x0;
    local_1c8._16_8_ = 0;
    VariantInit((VARIANTARG *)&local_1c8.n2);
    local_198._0_8_ = 0;
    local_198.decVal.u2.Lo64 = (_union_1719)0x0;
    local_198._16_8_ = 0;
    VariantInit((VARIANTARG *)&local_198.n2);
    local_1f8._0_8_ = local_1b0._0_8_;
    local_1f8.decVal.u2.Lo64 = local_1b0.decVal.u2;
    local_1f8._16_8_ = local_1b0._16_8_;
    local_210 = &local_1c8;
    local_218 = &local_1f8;
    iVar6 = (**(code **)(*local_1d0 + 0xa0))(local_1d0,iVar8,0xffffffff,0x34);
    if ((iVar6 < 0) || ((local_1c8.n2.vt != 3 || (local_1c8._8_4_ == 0)))) {
      local_1f8._0_8_ = local_1b0._0_8_;
      local_1f8.decVal.u2.s2 = local_1b0.decVal.u2;
      local_1f8._16_8_ = local_1b0._16_8_;
      local_210 = &local_198;
      local_218 = &local_1f8;
      iVar8 = (**(code **)(*local_1d0 + 0xa0))(local_1d0,iVar8,0xffffffff);
      if ((-1 < iVar8) &&
         (((local_198.n2.vt == 3 && (local_198._8_4_ != 0)) &&
          (pcVar12 = strchr(local_158,0x20), pcVar12 != (char *)0x0)))) {
        plVar19 = (longlong *)*param_1;
        while ((int)plVar19[0xd] == 0) {
          plVar19 = (longlong *)plVar19[0xc];
          local_1f8._0_8_ = 0;
          local_1f8.decVal.u2.Lo64 = (_union_1719)0x0;
          local_1f8._16_8_ = 0;
          VariantInit((VARIANTARG *)&local_1f8.n2);
          local_178 = local_1b0._0_4_;
          UStack_174 = local_1b0.decVal.Hi32;
          UStack_170 = local_1b0._8_4_;
          UStack_16c = local_1b0._12_4_;
          local_168 = local_1b0._16_8_;
          iVar8 = (**(code **)(*plVar19 + 0x98))(plVar19,0x3b,&local_178,&local_1f8);
          if (((-1 < iVar8) && (local_1f8.n2.vt == 8)) &&
             (iVar8 = _wcsicmp(L"BATCHFRAC",(wchar_t *)local_1f8.decVal.u2), iVar8 == 0)) {
            pcVar12 = strrchr(local_158,0x20);
            if (pcVar12 != (char *)0x0) {
              *pcVar12 = '\0';
            }
            bVar2 = true;
            VariantClear((VARIANTARG *)&local_1f8.n2);
            break;
          }
          VariantClear((VARIANTARG *)&local_1f8.n2);
        }
      }
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      local_1f8._0_8_ = local_1f8._0_8_ & 0xffffffffffff0000;
      local_1d8.Lo64 = 0;
      HVar7 = VariantClear((VARIANTARG *)&local_1f8.n2);
      if (HVar7 < 0) {
                    /* WARNING: Subroutine does not return */
        FUN_180001a90(HVar7);
      }
      local_1f8.n2.vt = 8;
      lVar16 = -1;
      do {
        lVar13 = lVar16 + 1;
        lVar17 = lVar16 + 1;
        lVar16 = lVar13;
      } while (local_158[lVar17] != '\0');
      lVar16 = (longlong)((int)lVar13 + 1) * 2;
      _Var18.Lo64 = _Var25.Lo64;
      puVar22 = auStack_238;
      _Var20.Lo64 = _Var25.Lo64;
      if (lVar16 + 0x80000000U < 0x100000000) {
        iVar8 = (int)lVar16;
        uVar26 = (ulonglong)iVar8;
        if ((iVar8 < 0x401) && (cVar5 = FUN_1800026d0(uVar26), cVar5 != '\0')) {
          uVar14 = uVar26 + 0xf;
          if (uVar14 <= uVar26) {
            uVar14 = 0xffffffffffffff0;
          }
          puVar21 = auStack_238 + -(uVar14 & 0xfffffffffffffff0);
          _Var24.Lo64 = (longlong)&local_1f8 + -(uVar14 & 0xfffffffffffffff0);
        }
        else {
          if (~uVar26 < 0x10) {
                    /* WARNING: Subroutine does not return */
            FUN_180001a90(-0x7ff8fdea);
          }
          _Var15 = (_union_1719)malloc(uVar26 + 0x10);
          _Var24.Lo64 = _Var25.Lo64;
          if ((BSTR)_Var15.Lo64 != (BSTR)0x0) {
            *(undefined8 *)_Var15 = 0;
            local_1d8.Lo64 = (ULONGLONG)_Var15;
            _Var18 = _Var15;
            puVar21 = auStack_238;
            _Var24.Lo64 = _Var15.Lo64 + 0x10;
          }
        }
        puVar22 = puVar21;
        if ((BSTR)_Var24.Lo64 != (BSTR)0x0) {
          *(OLECHAR *)_Var24 = L'\0';
          *(int *)(puVar21 + 0x28) = (int)(uVar26 >> 1);
          ((_union_1719 *)(puVar21 + 0x20))->Lo64 = (ULONGLONG)_Var24;
          *(undefined8 *)(puVar21 + -8) = 0x180007215;
          iVar8 = MultiByteToWideChar(0,0,local_158,-1,*(LPWSTR *)(puVar21 + 0x20),
                                      *(int *)(puVar21 + 0x28));
          _Var20 = _Var24;
          if (iVar8 == 0) {
            _Var20.Lo64 = _Var25.Lo64;
          }
        }
      }
      *(undefined8 *)(puVar22 + -8) = 0x180007229;
      local_1f8.decVal.u2 = (_union_1719)SysAllocString((OLECHAR *)_Var20);
      if (local_1f8.decVal.u2.Lo64 == (_union_1719)0x0) {
        local_1f8.n2.vt = 10;
        local_1f8.decVal.u2 = (_union_1719)0x8007000e;
                    /* WARNING: Subroutine does not return */
        *(undefined8 *)(puVar22 + -8) = 0x18000755c;
        FUN_180001a90(-0x7ff8fff2);
      }
      while ((BSTR)_Var18.Lo64 != (BSTR)0x0) {
                    /* WARNING: Load size is inaccurate */
        _Var20.s2 = *_Var18.s2;
        *(undefined8 *)(puVar22 + -8) = 0x18000724c;
        free((void *)_Var18);
        _Var18 = _Var20;
      }
      if ((local_1f8.n2.vt._0_1_ & 5) == 5) {
LAB_180007381:
        uVar4 = local_1f8.decVal.u2;
        _Var18.Lo64 = _Var25.Lo64;
        puVar21 = puVar22;
        if (local_1f8.decVal.u2.Lo64 != 0) {
          lVar16 = -1;
          do {
            lVar17 = lVar16;
            lVar16 = lVar17 + 1;
          } while (*(LPCWSTR)((longlong)local_1f8.decVal.u2 + lVar16 * 2) != L'\0');
          iVar8 = (int)lVar17 + 2;
          if (iVar8 < 0x40000000) {
            lVar16 = (longlong)(int)lVar16 * 2;
            uVar26 = lVar16 + 0x11;
            if (uVar26 <= lVar16 + 2U) {
              uVar26 = 0xffffffffffffff0;
            }
            *(undefined8 *)(puVar22 + -8) = 0x1800073c9;
            lVar16 = -(uVar26 & 0xfffffffffffffff0);
            _Var20.Lo64 = (longlong)puVar22 + lVar16 + 0x40;
            puVar21 = puVar22 + lVar16;
            if ((BSTR)_Var20.Lo64 != (BSTR)0x0) {
              *(char *)_Var20 = '\0';
              *(undefined8 *)(puVar22 + lVar16 + 0x38) = 0;
              *(undefined8 *)(puVar22 + lVar16 + 0x30) = 0;
              *(int *)(puVar22 + lVar16 + 0x28) = iVar8 * 2;
              ((_union_1719 *)(puVar22 + lVar16 + 0x20))->Lo64 = (ULONGLONG)_Var20;
              *(undefined8 *)(puVar22 + lVar16 + -8) = 0x1800073fd;
              iVar8 = WideCharToMultiByte(0,0,(LPCWSTR)uVar4,-1,*(LPSTR *)(puVar22 + lVar16 + 0x20),
                                          *(int *)(puVar22 + lVar16 + 0x28),
                                          *(LPCSTR *)(puVar22 + lVar16 + 0x30),
                                          *(LPBOOL *)(puVar22 + lVar16 + 0x38));
              _Var18.Lo64 = _Var20.Lo64;
              puVar21 = puVar22 + lVar16;
              if (iVar8 == 0) {
                _Var18.Lo64 = _Var25.Lo64;
                puVar21 = puVar22 + lVar16;
              }
            }
          }
        }
        _Var20 = _Var18;
        do {
          cVar5 = *(char *)_Var20;
          local_158[_Var20.Lo64 - (longlong)_Var18] = cVar5;
          _Var20.Lo64 = _Var20.Lo64 + 1;
          puVar22 = puVar21;
        } while (cVar5 != '\0');
      }
      else {
        uVar3 = local_1f8.n2.vt;
        *(undefined2 *)(puVar22 + 0x20) = 5;
        *(undefined8 *)(puVar22 + -8) = 0x18000727f;
        HVar7 = VariantChangeTypeEx((VARIANTARG *)&local_1f8.n2,(VARIANTARG *)&local_1f8,0x7f,0,
                                    *(VARTYPE *)(puVar22 + 0x20));
        uVar4 = local_1f8.decVal.u2;
        if (HVar7 == 0) {
LAB_18000735a:
          *(undefined2 *)(puVar22 + 0x20) = uVar3;
          *(undefined8 *)(puVar22 + -8) = 0x180007377;
          IVar10 = VariantChangeTypeEx((VARIANTARG *)&local_1f8.n2,(VARIANTARG *)&local_1f8,0x400,0,
                                       *(VARTYPE *)(puVar22 + 0x20));
LAB_180007379:
          if (IVar10 == 0) goto LAB_180007381;
        }
        else {
          if (local_1f8.n2.vt == 8) {
            *(undefined8 *)(puVar22 + -8) = 0x1800072a1;
            UVar9 = SysStringLen((BSTR)uVar4);
            if (*(BSTR)(uVar4 + (ulonglong)(UVar9 - 1) * 2) != L'%') goto LAB_180007352;
            *(undefined8 *)(puVar22 + -8) = 0x1800072b7;
            UVar9 = SysStringLen((BSTR)uVar4);
            *(OLECHAR *)(uVar4 + (ulonglong)(UVar9 - 1) * 2) = L'\0';
            *(undefined2 *)(puVar22 + 0x20) = 5;
            *(undefined8 *)(puVar22 + -8) = 0x1800072d8;
            HVar7 = VariantChangeTypeEx((VARIANTARG *)&local_1f8.n2,(VARIANTARG *)&local_1f8,0x7f,0,
                                        *(VARTYPE *)(puVar22 + 0x20));
            if (HVar7 < 0) goto LAB_180007420;
            *(undefined2 *)(puVar22 + 0x20) = uVar3;
            *(undefined8 *)(puVar22 + -8) = 0x1800072fd;
            HVar7 = VariantChangeTypeEx((VARIANTARG *)&local_1f8.n2,(VARIANTARG *)&local_1f8,0x400,0
                                        ,*(VARTYPE *)(puVar22 + 0x20));
            uVar4 = local_1f8.decVal.u2;
            if (HVar7 < 0) goto LAB_180007420;
            *(undefined8 *)(puVar22 + -8) = 0x180007312;
            UVar9 = SysStringLen((BSTR)uVar4);
            local_1d8.Lo64 = 0;
            *(undefined8 *)(puVar22 + -8) = 0x18000732a;
            IVar10 = SysReAllocStringLen((BSTR *)&local_1d8,(OLECHAR *)uVar4,UVar9 + 1);
            if ((BSTR)local_1d8.Lo64 != (BSTR)0x0) {
              ((BSTR)(local_1d8.Lo64 - 2))[(int)(UVar9 + 1)] = L'%';
              local_1f8.decVal.u2.Lo64 = local_1d8;
              *(undefined8 *)(puVar22 + -8) = 0x180007350;
              SysFreeString((BSTR)uVar4);
            }
            goto LAB_180007379;
          }
LAB_180007352:
          if (-1 < HVar7) goto LAB_18000735a;
        }
      }
LAB_180007420:
      *(undefined8 *)(puVar22 + -8) = 0x18000742a;
      VariantClear((VARIANTARG *)&local_1f8.n2);
    }
    *(undefined8 *)(puVar22 + -8) = 0x180007435;
    VariantClear((VARIANTARG *)&local_198.n2);
    *(undefined8 *)(puVar22 + -8) = 0x180007440;
    VariantClear((VARIANTARG *)&local_1c8.n2);
    *(undefined8 *)(puVar22 + -8) = 0x18000744b;
    VariantClear((VARIANTARG *)&local_1b0.n2);
    puVar23 = puVar22;
  }
  *(undefined8 *)(puVar23 + -8) = 0x180007457;
  iVar8 = FUN_180007ae0(local_158);
  if (iVar8 != 0) {
    local_1c8.n2.vt = 8;
    *(undefined4 *)(puVar23 + 0x28) = 0;
    *(undefined8 *)(puVar23 + 0x20) = 0;
    *(undefined8 *)(puVar23 + -8) = 0x180007484;
    iVar8 = MultiByteToWideChar(0,0,local_158,-1,*(LPWSTR *)(puVar23 + 0x20),
                                *(int *)(puVar23 + 0x28));
    *(undefined8 *)(puVar23 + -8) = 0x180007491;
    _Var18 = (_union_1719)SysAllocStringLen((OLECHAR *)0x0,iVar8 - 1);
    if ((BSTR)_Var18.Lo64 != (BSTR)0x0) {
      *(int *)(puVar23 + 0x28) = iVar8;
      ((_union_1719 *)(puVar23 + 0x20))->Lo64 = (ULONGLONG)_Var18;
      *(undefined8 *)(puVar23 + -8) = 0x1800074b9;
      iVar6 = MultiByteToWideChar(0,0,local_158,-1,*(LPWSTR *)(puVar23 + 0x20),
                                  *(int *)(puVar23 + 0x28));
      if (iVar6 != iVar8) {
        *(undefined8 *)(puVar23 + -8) = 0x1800074c6;
        SysFreeString((BSTR)_Var18);
        _Var18.Lo64 = _Var25.Lo64;
      }
    }
    local_1c8.decVal.u2.Lo64 = _Var18;
    *(undefined2 *)(puVar23 + 0x20) = 5;
    *(undefined8 *)(puVar23 + -8) = 0x1800074ec;
    HVar7 = VariantChangeTypeEx((VARIANTARG *)&local_1c8.n2,(VARIANTARG *)&local_1c8.n2,0x400,0,
                                *(VARTYPE *)(puVar23 + 0x20));
    if (-1 < HVar7) {
      uVar27 = local_1c8.decVal.u2;
    }
    *(undefined8 *)(puVar23 + -8) = 0x1800074ff;
    VariantClear((VARIANTARG *)&local_1c8.n2);
  }
  if (local_1d0 != (longlong *)0x0) {
    pcVar1 = *(code **)(*local_1d0 + 0x10);
    *(undefined8 *)(puVar23 + -8) = 0x18000750f;
    (*pcVar1)();
  }
LAB_18000750f:
  *(undefined8 *)(puVar23 + -8) = 0x180007521;
  return (_union_1719)((_union_1719)uVar27).Lo64;
}

/* ---- FUNC 00007580 FUN_180007580 (207 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_180007580(longlong param_1,int param_2)

{
  longlong lVar1;
  undefined1 auStack_428 [32];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_180077818 ^ (ulonglong)auStack_428;
  lVar1 = (longlong)param_2;
  if (param_2 < 0) {
    FUN_180002a20(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hadhocpl.cpp",0x5e4);
    LogMessage(local_408,2,1);
  }
  if (*(longlong *)(param_1 + 0x30) <= lVar1) {
    FUN_180002a20(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hadhocpl.cpp",0x5e5);
    LogMessage(local_408,2,1);
  }
  if ((-1 < lVar1) && (lVar1 < *(longlong *)(param_1 + 0x30))) {
    return *(undefined4 *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + lVar1 * 8) + 8);
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00007650 FUN_180007650 (4 bytes) ---- */

undefined4 FUN_180007650(longlong param_1)

{
  return *(undefined4 *)(param_1 + 0x30);
}

/* ---- FUNC 00007660 FUN_180007660 (6 bytes) ---- */

undefined8 FUN_180007660(void)

{
  return 0x80004001;
}

/* ---- FUNC 00007670 FUN_180007670 (73 bytes) ---- */

undefined8 FUN_180007670(longlong param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  *param_4 = 0;
  if (param_2 != 0) {
    return 0x8002000b;
  }
  (**(code **)(**(longlong **)(param_1 + 0x18) + 8))();
  *param_4 = *(undefined8 *)(param_1 + 0x18);
  return 0;
}

/* ---- FUNC 000076C0 FUN_1800076c0 (175 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined2 * FUN_1800076c0(longlong *param_1,undefined2 *param_2,int param_3)

{
  longlong *plVar1;
  longlong lVar2;
  double dVar3;
  double dVar4;
  _union_1719 _X;
  undefined1 auStack_448 [32];
  undefined1 local_428 [1008];
  ulonglong local_38;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStack_448;
  lVar2 = (longlong)param_3;
  if (param_3 < 0) {
    FUN_180002a20(local_428,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hadhocpl.cpp",0x632);
    LogMessage(local_428,2,1);
  }
  if (param_1[6] <= lVar2) {
    FUN_180002a20(local_428,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hadhocpl.cpp",0x633);
    LogMessage(local_428,2,1);
  }
  if ((-1 < param_3) && (lVar2 < param_1[6])) {
    plVar1 = *(longlong **)(param_1[5] + lVar2 * 8);
    *param_2 = 0;
    if ((int)param_1[1] == -1) {
      dVar4 = (double)plVar1[2];
      if (!NAN(dVar4)) {
        dVar3 = ceil(dVar4);
        if (dVar3 == dVar4) {
          *param_2 = 3;
          dVar4 = ceil((double)plVar1[2]);
          *(int *)(param_2 + 4) = (int)dVar4;
        }
        else {
          *param_2 = 5;
          *(longlong *)(param_2 + 4) = plVar1[2];
        }
      }
    }
    else if ((int)param_1[1] == -2) {
      _X = FUN_180006e60(param_1,param_3);
      if (!NAN((double)_X)) {
        dVar4 = ceil((double)_X);
        if (dVar4 == (double)_X) {
          *param_2 = 3;
          *(int *)(param_2 + 4) = (int)dVar4;
        }
        else {
          *(_union_1719 *)(param_2 + 4) = _X;
          *param_2 = 5;
        }
      }
    }
    else if (*plVar1 != 0) {
      *param_2 = 9;
      *(longlong *)(param_2 + 4) = *plVar1;
    }
    return param_2;
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 0000776F FUN_18000776f (232 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18000776f(void)

{
  longlong *plVar1;
  longlong in_RAX;
  undefined2 *unaff_RBX;
  longlong unaff_RBP;
  longlong *unaff_RSI;
  double dVar2;
  double dVar3;
  _union_1719 _X;
  
  plVar1 = *(longlong **)(in_RAX + unaff_RBP * 8);
  *unaff_RBX = 0;
  if ((int)unaff_RSI[1] == -1) {
    dVar3 = (double)plVar1[2];
    if (!NAN(dVar3)) {
      dVar2 = ceil(dVar3);
      if (dVar2 == dVar3) {
        *unaff_RBX = 3;
        dVar3 = ceil((double)plVar1[2]);
        *(int *)(unaff_RBX + 4) = (int)dVar3;
      }
      else {
        *unaff_RBX = 5;
        *(longlong *)(unaff_RBX + 4) = plVar1[2];
      }
    }
  }
  else if ((int)unaff_RSI[1] == -2) {
    _X = FUN_180006e60(unaff_RSI,(int)unaff_RBP);
    if (!NAN((double)_X)) {
      dVar3 = ceil((double)_X);
      if (dVar3 == (double)_X) {
        *unaff_RBX = 3;
        *(int *)(unaff_RBX + 4) = (int)dVar3;
      }
      else {
        *(_union_1719 *)(unaff_RBX + 4) = _X;
        *unaff_RBX = 5;
      }
    }
  }
  else if (*plVar1 != 0) {
    *unaff_RBX = 9;
    *(longlong *)(unaff_RBX + 4) = *plVar1;
  }
  return;
}

/* ---- FUNC 00007857 AfxThrowInvalidArgException (5 bytes) ---- */

void __cdecl AfxThrowInvalidArgException(void)

{
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00007860 FUN_180007860 (17 bytes) ---- */

bool FUN_180007860(longlong param_1)

{
  return *(uint *)(param_1 + 8) < 0xfffffffe;
}

/* ---- FUNC 00007880 FUN_180007880 (156 bytes) ---- */

void FUN_180007880(longlong param_1,int param_2,longlong *param_3,undefined4 param_4)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  puVar1 = operator_new(0x18);
  if (puVar1 == (undefined8 *)0x0) {
    puVar1 = (undefined8 *)0x0;
  }
  else {
    *puVar1 = 0;
    *(undefined4 *)(puVar1 + 1) = 0xffffffff;
    uVar2 = nan(&DAT_18006271e);
    puVar1[2] = uVar2;
  }
  *puVar1 = param_3;
  if (param_3 != (longlong *)0x0) {
    (**(code **)(*param_3 + 8))(param_3);
  }
  *(undefined4 *)(puVar1 + 1) = param_4;
  CPtrArray::InsertAt((CPtrArray *)(param_1 + 0x20),(longlong)param_2,puVar1,1);
  *(undefined4 *)(param_1 + 0x48) = 0xffffffff;
  return;
}

/* ---- FUNC 00007920 FUN_180007920 (77 bytes) ---- */

void FUN_180007920(void *param_1,DISPID param_2,undefined8 param_3,undefined8 param_4,WORD param_5,
                  DISPPARAMS *param_6,VARIANT *param_7,EXCEPINFO *param_8,UINT *param_9)

{
  DispInvoke(param_1,*(ITypeInfo **)((longlong)param_1 + 0x18),param_2,param_5,param_6,param_7,
             param_8,param_9);
  return;
}

/* ---- FUNC 00007970 FUN_180007970 (88 bytes) ---- */

undefined8 FUN_180007970(longlong param_1)

{
  ulonglong uVar1;
  longlong *plVar2;
  ulonglong uVar3;
  
  uVar1 = *(ulonglong *)(param_1 + 0x30);
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar3 < 0) || ((longlong)uVar1 <= (longlong)uVar3)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar2 = *(longlong **)(*(longlong *)(param_1 + 0x28) + uVar3 * 8);
      if ((*plVar2 != 0) || (!NAN((double)plVar2[2]))) {
        return 0;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return 1;
}

/* ---- FUNC 000079D0 FUN_1800079d0 (38 bytes) ---- */

bool FUN_1800079d0(longlong *param_1)

{
  ulonglong uVar1;
  int iVar2;
  ulonglong uVar3;
  _union_1719 _Var4;
  
  if (-1 < (int)param_1[1]) {
    iVar2 = (int)param_1[9];
    if (iVar2 == -1) {
      iVar2 = 0;
      uVar1 = param_1[6];
      uVar3 = 0;
      *(undefined4 *)(param_1 + 9) = 0;
      if (uVar1 != 0) {
        do {
          _Var4 = FUN_180006e60(param_1,(int)uVar3);
          iVar2 = 5;
          if (NAN((double)_Var4)) {
            iVar2 = 0;
          }
          uVar3 = uVar3 + 1;
          *(int *)(param_1 + 9) = iVar2;
        } while (uVar3 < uVar1);
      }
    }
    return iVar2 == 5;
  }
  return false;
}

/* ---- FUNC 000079F6 FUN_1800079f6 (78 bytes) ---- */

ulonglong FUN_1800079f6(longlong param_1)

{
  ulonglong uVar1;
  int iVar2;
  longlong *unaff_RBX;
  ulonglong uVar3;
  int iVar4;
  ulonglong unaff_RDI;
  _union_1719 _Var5;
  
  iVar4 = (int)unaff_RDI;
  uVar1 = *(ulonglong *)(param_1 + 0x30);
  uVar3 = unaff_RDI & 0xffffffff;
  *(int *)(param_1 + 0x48) = iVar4;
  iVar2 = iVar4;
  if (uVar1 != 0) {
    do {
      _Var5 = FUN_180006e60(unaff_RBX,(int)uVar3);
      iVar2 = 5;
      if (NAN((double)_Var5)) {
        iVar2 = iVar4;
      }
      uVar3 = uVar3 + 1;
      *(int *)(unaff_RBX + 9) = iVar2;
    } while (uVar3 < uVar1);
  }
  return CONCAT71((int7)(unaff_RDI >> 8),iVar2 == 5) & 0xffffffff;
}

/* ---- FUNC 00007A44 FUN_180007a44 (20 bytes) ---- */

ulonglong FUN_180007a44(void)

{
  int in_EAX;
  undefined8 unaff_RDI;
  
  return CONCAT71((int7)((ulonglong)unaff_RDI >> 8),in_EAX == 5) & 0xffffffff;
}

/* ---- FUNC 00007A60 FUN_180007a60 (112 bytes) ---- */

undefined8 FUN_180007a60(longlong param_1)

{
  ulonglong uVar1;
  bool bVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  
  uVar1 = *(ulonglong *)(param_1 + 0x10);
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar3 < 0) || (*(longlong *)(param_1 + 0x10) <= (longlong)uVar3)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      bVar2 = FUN_1800079d0(*(longlong **)(*(longlong *)(param_1 + 8) + uVar3 * 8));
      if ((int)CONCAT71(extraout_var,bVar2) != 0) {
        return 1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return 0;
}

/* ---- FUNC 00007AE0 FUN_180007ae0 (338 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_180007ae0(char *param_1)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  undefined1 auStack_58 [32];
  char local_38 [8];
  ulonglong local_30;
  
  local_30 = DAT_180077818 ^ (ulonglong)auStack_58;
  iVar4 = GetLocaleInfoA(0x400,0xe,local_38,5);
  cVar8 = '.';
  if (iVar4 != 0) {
    cVar8 = local_38[0];
  }
  iVar4 = GetLocaleInfoA(0x400,0x50,local_38,5);
  cVar6 = '+';
  if (iVar4 != 0) {
    cVar6 = local_38[0];
  }
  iVar4 = GetLocaleInfoA(0x400,0x51,local_38,5);
  cVar7 = '-';
  if (iVar4 != 0) {
    cVar7 = local_38[0];
  }
  iVar4 = 0;
  if (param_1 != (char *)0x0) {
    bVar2 = false;
    bVar3 = false;
    if (*param_1 == '\0') goto LAB_180007bb0;
    iVar4 = 0;
    bVar2 = false;
    bVar3 = false;
    if (*param_1 != cVar7) goto LAB_180007bb0;
    while (param_1 = param_1 + 1, param_1 != (char *)0x0) {
LAB_180007bb0:
      if (*param_1 == '\0') {
        return iVar4;
      }
      iVar5 = isdigit((int)*param_1);
      if (iVar5 == 0) {
        cVar1 = *param_1;
        if ((cVar1 != cVar8) || (bVar2)) {
          if (((cVar1 + 0xbbU & 0xdf) != 0) || (iVar4 == 0)) {
            if (((cVar1 != cVar6) && (cVar1 != cVar7)) || (!bVar3)) {
              return 0;
            }
            goto LAB_180007c00;
          }
          bVar2 = true;
          bVar3 = true;
        }
        else {
          bVar2 = true;
        }
      }
      else {
        iVar4 = 1;
LAB_180007c00:
        bVar3 = false;
      }
    }
  }
  return iVar4;
}

/* ---- FUNC 00007C40 FUN_180007c40 (239 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180007c40(longlong param_1,LPSTREAM param_2)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined1 auStack_438 [32];
  undefined8 local_418 [2];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_180077818 ^ (ulonglong)auStack_438;
  if (*(longlong *)(param_1 + 0x28) == 0) {
    FUN_180002a20(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hadhocpl.cpp",0x1ab);
    LogMessage(local_408,2,1);
  }
  FUN_1800255a0(local_418);
  uVar2 = FUN_180007d30((longlong *)(param_1 + 0x38),param_2);
  uVar3 = uVar2 & 0xffffffff;
  if (-1 < (int)uVar2) {
    uVar2 = FUN_180007f90((CPtrArray *)(param_1 + 0x88),param_2);
    uVar3 = uVar2 & 0xffffffff;
    if (-1 < (int)uVar2) {
      uVar2 = FUN_180007d30((longlong *)(param_1 + 0xb0),param_2);
      uVar3 = uVar2 & 0xffffffff;
      if (-1 < (int)uVar2) {
        uVar1 = FUN_180051e70(*(longlong *)(param_1 + 0x28),param_2);
        uVar3 = (ulonglong)uVar1;
        *(undefined4 *)(param_1 + 0x30) = 1;
      }
    }
  }
  FUN_180025a20(local_418);
  return uVar3;
}

/* ---- FUNC 00007D30 FUN_180007d30 (594 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180007d30(longlong *param_1,LPSTREAM param_2)

{
  IStreamVtbl *pIVar1;
  void *pv;
  char *pv_00;
  undefined8 *puVar2;
  undefined8 *puVar3;
  uint uVar4;
  undefined8 uVar6;
  undefined1 auStack_458 [32];
  ULONG local_438;
  int local_434;
  undefined8 *local_430;
  undefined1 local_428 [1008];
  ulonglong local_38;
  undefined8 *puVar5;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStack_458;
  if (*param_1 != 0) {
    FUN_180002a20(local_428,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hadhocpl.cpp",0x547);
    LogMessage(local_428,2,1);
  }
  if (param_1[6] != 0) {
    FUN_180002a20(local_428,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hadhocpl.cpp",0x548);
    LogMessage(local_428,2,1);
  }
  FUN_18002b260(DAT_180079590,param_2,param_1,0);
  (*param_2->lpVtbl->Read)(param_2,param_1 + 1,4,(ULONG *)0x0);
  local_434 = 0;
  (*param_2->lpVtbl->Read)(param_2,&local_434,4,(ULONG *)0x0);
  if (0 < local_434) {
    pv = malloc((longlong)local_434 << 2);
    param_1[2] = (longlong)pv;
    (*param_2->lpVtbl->Read)(param_2,pv,local_434 * 4,(ULONG *)0x0);
  }
  (*param_2->lpVtbl->Read)(param_2,&local_438,4,(ULONG *)0x0);
  pIVar1 = param_2->lpVtbl;
  pv_00 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)(param_1 + 3),local_438);
  (*pIVar1->Read)(param_2,pv_00,local_438,(ULONG *)0x0);
  ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)(param_1 + 3),-1);
  (*param_2->lpVtbl->Read)(param_2,&local_438,4,(ULONG *)0x0);
  puVar5 = (undefined8 *)0x0;
  if (0 < (int)local_438) {
    do {
      puVar2 = operator_new(0x18);
      puVar3 = (undefined8 *)0x0;
      local_430 = puVar2;
      if (puVar2 != (undefined8 *)0x0) {
        *puVar2 = 0;
        *(undefined4 *)(puVar2 + 1) = 0xffffffff;
        uVar6 = nan(&DAT_18006271e);
        puVar2[2] = uVar6;
        puVar3 = puVar2;
      }
      FUN_18002b260(DAT_180079590,param_2,puVar3,0);
      (*param_2->lpVtbl->Read)(param_2,puVar3 + 1,4,(ULONG *)0x0);
      (*param_2->lpVtbl->Read)(param_2,puVar3 + 2,8,(ULONG *)0x0);
      CPtrArray::SetAtGrow((CPtrArray *)(param_1 + 4),param_1[6],puVar3);
      uVar4 = (int)puVar5 + 1;
      puVar5 = (undefined8 *)(ulonglong)uVar4;
    } while ((int)uVar4 < (int)local_438);
  }
  (*param_2->lpVtbl->Read)(param_2,param_1 + 9,4,(ULONG *)0x0);
  return 0;
}

/* ---- FUNC 00007F90 FUN_180007f90 (295 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180007f90(CPtrArray *param_1,IStream *param_2)

{
  longlong *plVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  int iVar4;
  undefined1 auStack_448 [32];
  int local_428 [2];
  undefined8 *local_420;
  undefined1 local_418 [1008];
  ulonglong local_28;
  
  local_28 = DAT_180077818 ^ (ulonglong)auStack_448;
  if (*(longlong *)(param_1 + 0x10) != 0) {
    FUN_180002a20(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hadhocpl.cpp",0x490);
    LogMessage(local_418,2,1);
  }
  local_428[0] = 0;
  (*param_2->lpVtbl->Read)(param_2,local_428,4,(ULONG *)0x0);
  iVar4 = 0;
  if (local_428[0] < 1) {
    uVar3 = 0;
  }
  else {
    do {
      local_420 = operator_new(0x50);
      if (local_420 == (undefined8 *)0x0) {
        plVar1 = (longlong *)0x0;
      }
      else {
        plVar1 = FUN_180005bf0(local_420);
      }
      uVar2 = FUN_180007d30(plVar1,param_2);
      uVar3 = uVar2 & 0xffffffff;
      if ((int)uVar2 < 0) {
        if (plVar1 == (longlong *)0x0) {
          return uVar2;
        }
        FUN_180005d20(plVar1);
        FUN_180025ad0(plVar1);
        return uVar3;
      }
      CPtrArray::SetAtGrow(param_1,*(__int64 *)(param_1 + 0x10),plVar1);
      iVar4 = iVar4 + 1;
    } while (iVar4 < local_428[0]);
  }
  return uVar3;
}

/* ---- FUNC 000080C0 FUN_1800080c0 (11 bytes) ---- */

void FUN_1800080c0(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0001800080c7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(longlong **)(param_1 + 8) + 0x70))();
  return;
}

/* ---- FUNC 000080D0 FUN_1800080d0 (219 bytes) ---- */

void FUN_1800080d0(undefined8 param_1,longlong *param_2,longlong param_3)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  ulonglong uVar4;
  int iVar5;
  CPtrArray local_48 [8];
  longlong local_40;
  ulonglong local_38;
  
  FUN_180005c50(local_48);
  FUN_180008260(param_1,local_48,param_3,0);
  iVar3 = 0;
  iVar5 = -1;
  uVar4 = 0;
  if (local_38 != 0) {
    do {
      if (((longlong)uVar4 < 0) || ((longlong)local_38 <= (longlong)uVar4)) goto LAB_1800081a6;
      lVar1 = *(longlong *)(local_40 + uVar4 * 8);
      iVar2 = FUN_180007650(lVar1);
      if (iVar3 < iVar2) {
        iVar3 = FUN_180007650(lVar1);
        iVar5 = (int)uVar4;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < local_38);
    if (0 < iVar3) {
      if ((iVar5 < 0) || ((longlong)local_38 <= (longlong)iVar5)) {
LAB_1800081a6:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      FUN_180006110(param_2,*(longlong **)(local_40 + (longlong)iVar5 * 8));
    }
  }
  FUN_180005d50(local_48);
  return;
}

/* ---- FUNC 000081B0 FUN_1800081b0 (166 bytes) ---- */

void FUN_1800081b0(undefined8 param_1,CPtrArray *param_2,longlong param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  CPtrArray local_38 [8];
  longlong local_30;
  ulonglong local_28;
  
  FUN_180005c50(local_38);
  FUN_180008260(param_1,local_38,param_3,1);
  uVar1 = local_28;
  uVar2 = 0;
  if (local_28 != 0) {
    do {
      if (((longlong)uVar2 < 0) || ((longlong)local_28 <= (longlong)uVar2)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      CPtrArray::SetAtGrow(param_2,*(__int64 *)(param_2 + 0x10),*(void **)(local_30 + uVar2 * 8));
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar1);
  }
  CPtrArray::SetSize(local_38,0,-1);
  FUN_180005d50(local_38);
  return;
}

/* ---- FUNC 00008260 FUN_180008260 (2868 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void FUN_180008260(undefined8 param_1,CPtrArray *param_2,longlong param_3,undefined4 param_4)

{
  char *pcVar1;
  code *pcVar2;
  LPCWSTR lpWideCharStr;
  longlong *plVar3;
  wchar_t *pwVar4;
  bool bVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  CPtrArray *pCVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  int iVar12;
  bool bVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  HRESULT HVar17;
  undefined8 *puVar18;
  char *pcVar19;
  longlong *plVar20;
  longlong *plVar21;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar22;
  int *_Memory;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar23;
  IAtlStringMgr *pIVar24;
  longlong *plVar25;
  ulonglong uVar26;
  char *pcVar27;
  undefined1 *puVar28;
  undefined1 *puVar29;
  longlong lVar30;
  longlong lVar31;
  longlong lVar32;
  undefined1 auStack_348 [64];
  longlong local_308;
  uint local_300;
  int iStack_2fc;
  longlong local_2f8;
  longlong *local_2f0;
  uint local_2e8 [2];
  longlong *local_2e0;
  _union_2707 local_2d8;
  char *local_2c0;
  longlong *local_2b8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_2b0 [8];
  char *local_2a8;
  undefined4 local_2a0;
  undefined4 local_29c;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_298 [8];
  CPtrArray *local_290;
  _union_2707 local_288;
  wchar_t *local_270;
  _union_2707 local_268;
  _union_2707 local_248;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_230 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_228 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_220 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_218 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_210 [8];
  longlong local_208;
  undefined8 local_200;
  _union_2707 local_1f8;
  _union_2707 local_1d8;
  char local_1b8;
  char local_178 [256];
  ulonglong local_78;
  
  uVar11 = local_248._16_8_;
  puVar29 = auStack_348;
  local_78 = DAT_180077818 ^ (ulonglong)&local_308;
  uVar15 = 0;
  local_300 = 0;
  local_2e8[0] = 0;
  local_248._0_8_ = local_248._0_8_ & 0xffffffffffff0000;
  uVar10 = local_248._0_8_;
  lVar31 = (longlong)*(int *)(param_3 + 0xb0);
  if (0 < lVar31) {
    local_2f0 = (longlong *)0x0;
    puVar29 = auStack_348;
    local_2f8 = lVar31;
    local_29c = param_4;
    local_290 = param_2;
    local_208 = param_3;
    local_200 = param_1;
    do {
      plVar20 = local_2f0;
      pcVar19 = (char *)0x0;
      local_308 = 0;
      if (((longlong)local_2f0 < 0) || (*(longlong *)(param_3 + 0xb0) <= (longlong)local_2f0)) {
                    /* WARNING: Subroutine does not return */
        *(undefined **)(puVar29 + -8) = &UNK_180008d94;
        AfxThrowInvalidArgException();
      }
      lVar30 = *(longlong *)(*(longlong *)(param_3 + 0xa8) + (longlong)local_2f0 * 8);
      if ((*(longlong *)(lVar30 + 0x38) == 0) || (*(int *)(*(longlong *)(lVar30 + 0x38) + 8) != -1))
      {
        iVar14 = *(int *)(lVar30 + 0x30);
        if (iVar14 == 0) {
          plVar21 = *(longlong **)(lVar30 + 0x28);
          local_2e0 = (longlong *)0x0;
          lVar31 = plVar21[9];
          *(undefined8 *)(puVar29 + -8) = 0x180008789;
          iVar14 = HAGetAttrType(lVar31);
          *(undefined8 *)(puVar29 + -8) = 0x180008795;
          ReleaseErrorStruct(&local_2e0);
          lVar31 = local_2f8;
          if (iVar14 != -999) {
            if (iVar14 == -3) {
              local_2d8._0_8_ = 0;
              local_2d8.decVal.u2.Lo64 = (_union_1719)0x0;
              local_2d8._16_8_ = (code *)0x0;
              lVar31 = plVar21[9];
              *(undefined8 *)(puVar29 + -8) = 0x1800087c6;
              HAGetAttr(lVar31,0);
              *(undefined8 *)(puVar29 + -8) = 0x1800087d3;
              AssignErrorStruct(&local_308);
              uVar7 = local_2d8._16_8_;
              uVar6 = local_2d8.decVal.u2;
              if (local_308 == 0) {
                *(undefined8 *)(puVar29 + -8) = 0x1800087f8;
                iVar14 = FUN_180007ae0((char *)uVar6);
                uVar7 = local_2d8._16_8_;
                uVar6 = local_2d8.decVal.u2;
                if (iVar14 == 0) {
                  lVar31 = local_2f8;
                  if ((code *)local_2d8._16_8_ != (code *)0x0) {
                    *(undefined8 *)(puVar29 + -8) = 0x18000880b;
                    (*(code *)uVar7)(uVar6);
                    lVar31 = local_2f8;
                  }
                }
                else {
LAB_18000893f:
                  uVar7 = local_2d8._16_8_;
                  uVar6 = local_2d8.decVal.u2;
                  if ((code *)local_2d8._16_8_ != (code *)0x0) {
                    *(undefined8 *)(puVar29 + -8) = 0x18000894e;
                    (*(code *)uVar7)(uVar6);
                  }
LAB_18000896e:
                  local_2b8 = (longlong *)0x0;
                  pcVar2 = (code *)**(undefined8 **)plVar21[0xc];
                  *(undefined8 *)(puVar29 + -8) = 0x180008986;
                  iVar14 = (*pcVar2)();
                  lVar31 = local_2f8;
                  if (-1 < iVar14) {
                    pcVar2 = *(code **)(*local_2b8 + 0x58);
                    *(undefined8 *)(puVar29 + -8) = 0x18000899c;
                    (*pcVar2)();
                    bVar5 = false;
                    if (iStack_2fc < 2) {
                      if (iStack_2fc == 1) {
                        *(undefined8 *)(puVar29 + -8) = 0x180008aea;
                        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                   &local_2c0);
                        plVar25 = plVar21;
                        for (plVar3 = local_2b8;
                            (plVar3 != (longlong *)0x0 && ((int)plVar3[0xd] == 0));
                            plVar3 = (longlong *)plVar3[0xc]) {
                          local_2e0 = (longlong *)0x0;
                          lVar31 = plVar3[9];
                          *(undefined8 *)(puVar29 + -8) = 0x180008b20;
                          iVar14 = HAGroupChildren(lVar31);
                          *(undefined8 *)(puVar29 + -8) = 0x180008b2c;
                          ReleaseErrorStruct(&local_2e0);
                          if (iVar14 != 0) goto LAB_180008c8f;
                          local_1f8._0_8_ = uVar10;
                          local_1f8._16_8_ = uVar11;
                          pcVar2 = *(code **)(*plVar25 + 0x48);
                          *(undefined8 *)(puVar29 + -8) = 0x180008b5a;
                          iVar14 = (*pcVar2)(plVar25);
                          pwVar4 = local_270;
                          if ((-1 < iVar14) && (local_270 != (wchar_t *)0x0)) {
                            if (*(int *)(local_2c0 + -0x10) == 0) {
                              *(undefined8 *)(puVar29 + -8) = 0x180008b88;
                              pCVar23 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                         *)ATL::
                                           CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                           ::
                                           CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                                     (local_218,pwVar4);
                              *(undefined8 *)(puVar29 + -8) = 0x180008b96;
                              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                              operator=((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                         *)&local_2c0,pCVar23);
                              pCVar22 = local_218;
                            }
                            else {
                              *(undefined8 *)(puVar29 + -8) = 0x180008bb0;
                              pCVar22 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                         *)ATL::
                                           CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                           ::
                                           CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                                     (local_210,pwVar4);
                              *(undefined8 *)(puVar29 + -8) = 0x180008bbc;
                              pIVar24 = ATL::
                                        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                        ::GetManager(pCVar22);
                              *(undefined8 *)(puVar29 + -8) = 0x180008bc9;
                              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                              CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                          *)&local_2a8,pIVar24);
                              local_2e8[0] = uVar15 | 4;
                              pcVar19 = *(char **)pCVar22;
                              *(undefined4 *)(puVar29 + 0x20) = 1;
                              iVar14 = *(int *)(pcVar19 + -0x10);
                              *(undefined8 *)(puVar29 + -8) = 0x180008bf1;
                              ATL::CSimpleStringT<char,1>::Concatenate
                                        ((CSimpleStringT<char,1> *)&local_2a8,pcVar19,iVar14," ",
                                         *(int *)(puVar29 + 0x20));
                              *(undefined8 *)(puVar29 + -8) = 0x180008bfc;
                              pIVar24 = ATL::
                                        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                        ::GetManager((
                                                  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                                  *)&local_2a8);
                              *(undefined8 *)(puVar29 + -8) = 0x180008c09;
                              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                              CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                        (local_298,pIVar24);
                              pcVar27 = local_2a8;
                              pcVar19 = local_2c0;
                              local_2e8[0] = uVar15 | 6;
                              *(undefined4 *)(puVar29 + 0x20) = *(undefined4 *)(local_2c0 + -0x10);
                              iVar14 = *(int *)(pcVar27 + -0x10);
                              *(undefined8 *)(puVar29 + -8) = 0x180008c2f;
                              ATL::CSimpleStringT<char,1>::Concatenate
                                        ((CSimpleStringT<char,1> *)local_298,pcVar27,iVar14,pcVar19,
                                         *(int *)(puVar29 + 0x20));
                              *(undefined8 *)(puVar29 + -8) = 0x180008c3d;
                              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                              operator=((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                         *)&local_2c0,
                                        (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                         *)local_298);
                              *(undefined8 *)(puVar29 + -8) = 0x180008c4b;
                              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                        (local_298);
                              uVar15 = uVar15 & 0xfffffff9;
                              local_300 = uVar15;
                              *(undefined8 *)(puVar29 + -8) = 0x180008c5d;
                              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                          *)&local_2a8);
                              pCVar22 = local_210;
                            }
                            *(undefined8 *)(puVar29 + -8) = 0x180008c6b;
                            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar22);
                            pwVar4 = local_270;
                            *(undefined8 *)(puVar29 + -8) = 0x180008c78;
                            SysFreeString(pwVar4);
                          }
                          plVar25 = (longlong *)plVar25[0xc];
                        }
                        bVar5 = true;
LAB_180008c8f:
                        if (!bVar5) {
                          lVar31 = plVar25[9];
                          *(undefined8 *)(puVar29 + -8) = 0x180008ca4;
                          HAGetElementLocation(lVar31,0);
                          *(undefined8 *)(puVar29 + -8) = 0x180008cb1;
                          AssignErrorStruct(&local_308);
                          if (local_308 == 0) {
                            *(char **)(puVar29 + 0x20) = local_2c0;
                            pCVar9 = local_290;
                            *(undefined8 *)(puVar29 + -8) = 0x180008cd3;
                            plVar25 = FUN_1800065d0(pCVar9,plVar3,0,(int *)0x0,
                                                    *(char **)(puVar29 + 0x20));
                            uVar8 = local_2a0;
                            *(undefined8 *)(puVar29 + -8) = 0x180008ce2;
                            FUN_180005f00((longlong)plVar25,plVar21,uVar8);
                          }
                        }
                        *(undefined8 *)(puVar29 + -8) = 0x180008ced;
                        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                   &local_2c0);
                      }
                    }
                    else {
                      iVar14 = iStack_2fc + 1;
                      *(undefined8 *)(puVar29 + -8) = 0x1800089ba;
                      _Memory = malloc((longlong)iVar14 << 2);
                      iVar14 = 0;
                      lVar30 = 0;
                      iVar16 = -1;
                      lVar31 = -1;
                      if (iStack_2fc < 1) {
LAB_180008ab7:
                        _Memory[iStack_2fc] = -1;
                      }
                      else {
                        do {
                          lVar32 = plVar21[9];
                          *(undefined8 *)(puVar29 + -8) = 0x1800089f3;
                          HAGetElementLocation(lVar32,iVar14);
                          *(undefined8 *)(puVar29 + -8) = 0x180008a00;
                          AssignErrorStruct(&local_308);
                          if (local_308 != 0) {
LAB_180008a6c:
                            bVar5 = true;
                            break;
                          }
                          local_1b8 = '\0';
                          lVar32 = local_2b8[9];
                          *(undefined8 *)(puVar29 + -8) = 0x180008a29;
                          HAGetDecoratedColumn(lVar32,iVar14);
                          *(undefined8 *)(puVar29 + -8) = 0x180008a36;
                          AssignErrorStruct(&local_308);
                          if (local_308 == 0) {
                            lVar32 = lVar31;
                            iVar12 = iVar16;
                            if (local_1b8 == '\0') goto LAB_180008a4f;
                          }
                          else {
                            local_1b8 = '\0';
LAB_180008a4f:
                            lVar32 = lVar30;
                            iVar12 = iVar14;
                            if (lVar31 != -1) goto LAB_180008a6c;
                          }
                          iVar16 = iVar12;
                          iVar14 = iVar14 + 1;
                          lVar30 = lVar30 + 1;
                          lVar31 = lVar32;
                        } while (iVar14 < iStack_2fc);
                        if (iVar16 == -1) goto LAB_180008ab7;
                        _Memory[iStack_2fc] = -1;
                        if (!bVar5) {
                          *(undefined8 *)(puVar29 + 0x20) = 0;
                          pCVar9 = local_290;
                          plVar20 = local_2b8;
                          *(undefined8 *)(puVar29 + -8) = 0x180008aa6;
                          plVar20 = FUN_1800065d0(pCVar9,plVar20,iVar16,_Memory,
                                                  *(char **)(puVar29 + 0x20));
                          iVar14 = _Memory[lVar31];
                          *(undefined8 *)(puVar29 + -8) = 0x180008ab5;
                          FUN_180005f00((longlong)plVar20,plVar21,iVar14);
                        }
                      }
                      *(undefined8 *)(puVar29 + -8) = 0x180008aca;
                      free(_Memory);
                      plVar20 = local_2f0;
                      uVar15 = local_300;
                    }
                    pcVar2 = *(code **)(*local_2b8 + 0x10);
                    *(undefined8 *)(puVar29 + -8) = 0x180008cf7;
                    (*pcVar2)();
                    param_2 = local_290;
                    lVar31 = local_2f8;
                  }
                }
              }
              else {
                lVar31 = local_2f8;
                if ((code *)local_2d8._16_8_ != (code *)0x0) {
                  *(undefined8 *)(puVar29 + -8) = 0x1800087e9;
                  (*(code *)uVar7)(uVar6);
                  lVar31 = local_2f8;
                }
              }
            }
            else if (iVar14 == -6) {
              local_2d8._0_8_ = 0;
              local_2d8.decVal.u2.Lo64 = (_union_1719)0x0;
              local_2d8._16_8_ = (code *)0x0;
              lVar31 = plVar21[9];
              *(undefined8 *)(puVar29 + -8) = 0x18000883f;
              HAGetAttr(lVar31,0);
              *(undefined8 *)(puVar29 + -8) = 0x18000884c;
              AssignErrorStruct(&local_308);
              uVar7 = local_2d8._16_8_;
              uVar6 = local_2d8.decVal.u2;
              lVar31 = local_2f8;
              if (local_308 == 0) {
                if (local_2d8.decVal.u2.Lo64 == 0) {
                  if ((code *)local_2d8._16_8_ != (code *)0x0) {
                    *(undefined8 *)(puVar29 + -8) = 0x18000887c;
                    (*(code *)uVar7)();
                    lVar31 = local_2f8;
                  }
                }
                else if (*(short *)local_2d8.decVal.u2 == 8) {
                  lpWideCharStr = *(LPCWSTR *)((longlong)local_2d8.decVal.u2 + 8);
                  pcVar27 = pcVar19;
                  puVar28 = puVar29;
                  if (lpWideCharStr != (LPCWSTR)0x0) {
                    lVar31 = -1;
                    do {
                      lVar30 = lVar31;
                      lVar31 = lVar30 + 1;
                    } while (lpWideCharStr[lVar31] != L'\0');
                    iVar14 = (int)lVar30 + 2;
                    if (iVar14 < 0x40000000) {
                      lVar31 = (longlong)(int)lVar31 * 2;
                      uVar26 = lVar31 + 0x11;
                      if (uVar26 <= lVar31 + 2U) {
                        uVar26 = 0xffffffffffffff0;
                      }
                      *(undefined8 *)(puVar29 + -8) = 0x1800088df;
                      lVar31 = -(uVar26 & 0xfffffffffffffff0);
                      pcVar1 = puVar29 + lVar31 + 0x40;
                      puVar28 = puVar29 + lVar31;
                      if (pcVar1 != (char *)0x0) {
                        *pcVar1 = '\0';
                        *(undefined8 *)(puVar29 + lVar31 + 0x38) = 0;
                        *(undefined8 *)(puVar29 + lVar31 + 0x30) = 0;
                        *(int *)(puVar29 + lVar31 + 0x28) = iVar14 * 2;
                        *(char **)(puVar29 + lVar31 + 0x20) = pcVar1;
                        *(undefined8 *)(puVar29 + lVar31 + -8) = 0x180008913;
                        iVar14 = WideCharToMultiByte(0,0,lpWideCharStr,-1,
                                                     *(LPSTR *)(puVar29 + lVar31 + 0x20),
                                                     *(int *)(puVar29 + lVar31 + 0x28),
                                                     *(LPCSTR *)(puVar29 + lVar31 + 0x30),
                                                     *(LPBOOL *)(puVar29 + lVar31 + 0x38));
                        pcVar27 = pcVar1;
                        puVar28 = puVar29 + lVar31;
                        if (iVar14 == 0) {
                          pcVar27 = pcVar19;
                          puVar28 = puVar29 + lVar31;
                        }
                      }
                    }
                  }
                  *(undefined8 *)(puVar28 + -8) = 0x180008926;
                  iVar14 = FUN_180007ae0(pcVar27);
                  uVar7 = local_2d8._16_8_;
                  uVar6 = local_2d8.decVal.u2;
                  puVar29 = puVar28;
                  if (iVar14 != 0) goto LAB_18000893f;
                  lVar31 = local_2f8;
                  if ((code *)local_2d8._16_8_ != (code *)0x0) {
                    *(undefined8 *)(puVar28 + -8) = 0x180008939;
                    (*(code *)uVar7)(uVar6);
                    lVar31 = local_2f8;
                  }
                }
                else if ((code *)local_2d8._16_8_ != (code *)0x0) {
                  *(undefined8 *)(puVar29 + -8) = 0x18000895c;
                  (*(code *)uVar7)();
                  lVar31 = local_2f8;
                }
              }
              else if ((code *)local_2d8._16_8_ != (code *)0x0) {
                *(undefined8 *)(puVar29 + -8) = 0x180008862;
                (*(code *)uVar7)(uVar6);
                lVar31 = local_2f8;
              }
            }
            else if (iVar14 + 2U < 2) goto LAB_18000896e;
          }
        }
        else if (iVar14 == 2) {
          pcVar19 = *(char **)(lVar30 + 0x28);
          *(undefined8 *)(puVar29 + -8) = 0x1800086c9;
          iVar14 = FUN_180007ae0(pcVar19);
          if (iVar14 != 0) {
            *(undefined8 *)(puVar29 + 0x20) = 0;
            *(undefined8 *)(puVar29 + -8) = 0x1800086e7;
            plVar21 = FUN_1800065d0(param_2,(longlong *)0x0,-1,(int *)0x0,*(char **)(puVar29 + 0x20)
                                   );
            local_288.n2.vt = 8;
            *(undefined8 *)(puVar29 + -8) = 0x180008706;
            pCVar22 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                (local_220,pcVar19);
            *(undefined8 *)(puVar29 + -8) = 0x180008710;
            local_288.decVal.u2 =
                 (_union_1719)
                 ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::AllocSysString
                           (pCVar22);
            *(undefined8 *)(puVar29 + -8) = 0x180008724;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_220);
            *(undefined2 *)(puVar29 + 0x20) = 5;
            *(undefined8 *)(puVar29 + -8) = 0x180008748;
            HVar17 = VariantChangeTypeEx((VARIANTARG *)&local_288.n2,(VARIANTARG *)&local_288.n2,
                                         0x400,0,*(VARTYPE *)(puVar29 + 0x20));
            uVar6 = local_288.decVal.u2;
            if (-1 < HVar17) {
              *(undefined8 *)(puVar29 + -8) = 0x18000875c;
              FUN_180005e70((longlong)plVar21,uVar6);
            }
            *(undefined8 *)(puVar29 + -8) = 0x180008769;
            VariantClear((VARIANTARG *)&local_288.n2);
          }
        }
        else if (iVar14 == 3) {
          *(undefined8 *)(puVar29 + -8) = 0x1800083a5;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    (local_2b0,
                     (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     (lVar30 + 0x18));
          plVar21 = *(longlong **)(lVar30 + 0x28);
          local_300 = uVar15 | 1;
          *(undefined8 *)(puVar29 + -8) = 0x1800083c0;
          iVar14 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                             (local_2b0,'x',0);
          uVar15 = uVar15 | 1;
          if (iVar14 != -1) {
            *(undefined8 *)(puVar29 + -8) = 0x1800083df;
            puVar18 = (undefined8 *)
                      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                                (local_2b0,(int)local_230);
            pcVar19 = (char *)*puVar18;
            *(undefined8 *)(puVar29 + -8) = 0x1800083e8;
            uVar15 = atoi(pcVar19);
            local_2e8[0] = uVar15;
            *(undefined8 *)(puVar29 + -8) = 0x1800083fb;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_230);
            *(undefined8 *)(puVar29 + -8) = 0x180008410;
            puVar18 = (undefined8 *)
                      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                                (local_2b0,(int)local_228);
            pcVar19 = (char *)*puVar18;
            *(undefined8 *)(puVar29 + -8) = 0x180008419;
            iVar14 = atoi(pcVar19);
            *(undefined8 *)(puVar29 + -8) = 0x180008429;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_228);
            lVar30 = plVar21[9];
            *(undefined8 *)(puVar29 + -8) = 0x180008440;
            HAGetLabel(lVar30,uVar15);
            *(undefined8 *)(puVar29 + -8) = 0x18000844d;
            AssignErrorStruct(&local_308);
            if (local_308 == 0) {
              bVar5 = false;
              local_2e0 = (longlong *)0x0;
              pcVar2 = *(code **)(*plVar21 + 200);
              *(undefined8 *)(puVar29 + -8) = 0x18000847b;
              iVar16 = (*pcVar2)(plVar21);
              if (iVar16 < 0) {
LAB_18000865e:
                *(undefined8 *)(puVar29 + -8) = 0x18000866a;
                iVar16 = FUN_180007ae0(local_178);
                if (iVar16 != 0) goto LAB_18000866e;
              }
              else {
                local_288._0_8_ = 0;
                local_288.decVal.u2.Lo64 = (_union_1719)0x0;
                local_288._16_8_ = 0;
                *(undefined8 *)(puVar29 + -8) = 0x1800084a3;
                VariantInit((VARIANTARG *)&local_288.n2);
                local_2d8._0_8_ = 0;
                local_2d8.decVal.u2.Lo64 = (_union_1719)0x0;
                local_2d8._16_8_ = (code *)0x0;
                *(undefined8 *)(puVar29 + -8) = 0x1800084bb;
                VariantInit((VARIANTARG *)&local_2d8.n2);
                local_248._0_8_ = 0;
                local_248.decVal.u2.Lo64 = (_union_1719)0x0;
                local_248._16_8_ = 0;
                *(undefined8 *)(puVar29 + -8) = 0x1800084dc;
                VariantInit((VARIANTARG *)&local_248.n2);
                plVar20 = local_2e0;
                local_268._0_4_ = local_288._0_4_;
                local_268.decVal.Hi32 = local_288.decVal.Hi32;
                local_268._8_4_ = local_288._8_4_;
                local_268._12_4_ = local_288._12_4_;
                local_268._16_8_ = local_288._16_8_;
                lVar30 = *local_2e0;
                *(_union_2707 **)(puVar29 + 0x28) = &local_2d8;
                *(_union_2707 **)(puVar29 + 0x20) = &local_268;
                pcVar2 = *(code **)(lVar30 + 0xa0);
                *(undefined8 *)(puVar29 + -8) = 0x180008528;
                iVar16 = (*pcVar2)(plVar20,uVar15);
                if (((-1 < iVar16) && (local_2d8.n2.vt == 3)) && (local_2d8._8_4_ != 0)) {
                  bVar5 = true;
                }
                *(undefined8 *)(puVar29 + -8) = 0x180008551;
                pcVar19 = strstr(local_178," ");
                if (pcVar19 != (char *)0x0) {
                  *(undefined8 *)(puVar29 + -8) = 0x18000856d;
                  pcVar19 = strstr(local_178,".");
                  if (pcVar19 != (char *)0x0) {
                    *(undefined8 *)(puVar29 + -8) = 0x180008589;
                    pcVar19 = strstr(local_178,"D");
                    if (pcVar19 != (char *)0x0) {
                      *(undefined8 *)(puVar29 + -8) = 0x18000859e;
                      AfxVariantInit((tagVARIANT *)&local_268.n2);
                      *(undefined8 *)(puVar29 + -8) = 0x1800085ac;
                      VariantInit((VARIANTARG *)&local_1d8.n2);
                      iVar16 = (int)plVar21[0xd];
                      plVar20 = plVar21;
                      while (bVar13 = bVar5, iVar16 == 0) {
                        plVar20 = (longlong *)plVar20[0xc];
                        local_1f8.decVal.Hi32 = local_1d8.decVal.Hi32;
                        local_1f8._0_4_ = local_1d8._0_4_;
                        local_1f8._16_8_ = local_1d8._16_8_;
                        pcVar2 = *(code **)(*plVar20 + 0x98);
                        *(undefined8 *)(puVar29 + -8) = 0x1800085f6;
                        iVar16 = (*pcVar2)(plVar20);
                        if ((-1 < iVar16) && (local_268.n2.vt == 8)) {
                          pwVar4 = (wchar_t *)CONCAT44(local_268._12_4_,local_268._8_4_);
                          *(undefined8 *)(puVar29 + -8) = 0x180008618;
                          iVar16 = _wcsicmp(L"BATCHFRAC",pwVar4);
                          bVar13 = true;
                          if (iVar16 == 0) break;
                        }
                        iVar16 = (int)plVar20[0xd];
                      }
                      bVar5 = bVar13;
                      *(undefined8 *)(puVar29 + -8) = 0x180008632;
                      VariantClear((VARIANTARG *)&local_268.n2);
                    }
                  }
                }
                *(undefined8 *)(puVar29 + -8) = 0x180008641;
                VariantClear((VARIANTARG *)&local_248.n2);
                *(undefined8 *)(puVar29 + -8) = 0x18000864c;
                VariantClear((VARIANTARG *)&local_2d8.n2);
                *(undefined8 *)(puVar29 + -8) = 0x18000865a;
                VariantClear((VARIANTARG *)&local_288.n2);
                if (!bVar5) goto LAB_18000865e;
LAB_18000866e:
                *(undefined8 *)(puVar29 + 0x20) = 0;
                *(undefined8 *)(puVar29 + -8) = 0x180008688;
                plVar20 = FUN_1800065d0(param_2,plVar21,-2,(int *)local_2e8,
                                        *(char **)(puVar29 + 0x20));
                *(undefined8 *)(puVar29 + -8) = 0x180008696;
                FUN_180005f00((longlong)plVar20,plVar21,iVar14);
              }
              plVar20 = local_2f0;
              uVar15 = local_300;
              if (local_2e0 != (longlong *)0x0) {
                pcVar2 = *(code **)(*local_2e0 + 0x10);
                *(undefined8 *)(puVar29 + -8) = 0x1800086a6;
                (*pcVar2)();
                plVar20 = local_2f0;
                uVar15 = local_300;
              }
            }
            else {
              *(undefined8 *)(puVar29 + -8) = 0x18000845e;
              ReleaseErrorStruct(&local_308);
              plVar20 = local_2f0;
              uVar15 = local_300;
            }
          }
          *(undefined8 *)(puVar29 + -8) = 0x1800086b8;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_2b0);
        }
        else if (iVar14 == 100) {
          puVar18 = *(undefined8 **)(lVar30 + 0x28);
          local_2f0 = (longlong *)0x0;
          if (puVar18 != (undefined8 *)0x0) {
            pcVar2 = *(code **)*puVar18;
            *(undefined8 *)(puVar29 + -8) = 0x180008378;
            iVar14 = (*pcVar2)(puVar18);
            if (iVar14 < 0) {
              local_2f0 = (longlong *)0x0;
            }
          }
          plVar21 = local_2f0;
          if (local_2f0 != (longlong *)0x0) {
            pcVar2 = *(code **)(*local_2f0 + 0x20);
            *(undefined8 *)(puVar29 + -8) = 0x180008d5c;
            (*pcVar2)(plVar21,param_3);
            uVar10 = local_200;
            uVar8 = local_29c;
            *(undefined8 *)(puVar29 + -8) = 0x180008d72;
            FUN_180008260(uVar10,param_2,param_3,uVar8);
            if (local_2f0 != (longlong *)0x0) {
              pcVar2 = *(code **)(*local_2f0 + 0x10);
              *(undefined8 *)(puVar29 + -8) = 0x180008d82;
              (*pcVar2)();
            }
            *(undefined8 *)(puVar29 + -8) = 0x180008d8d;
            ReleaseErrorStruct(&local_308);
            break;
          }
        }
        *(undefined8 *)(puVar29 + -8) = 0x180008d09;
        ReleaseErrorStruct(&local_308);
        param_3 = local_208;
      }
      else {
        *(undefined8 *)(puVar29 + -8) = 0x18000832e;
        ReleaseErrorStruct(&local_308);
      }
      local_2f0 = (longlong *)((longlong)plVar20 + 1);
    } while ((longlong)local_2f0 < lVar31);
  }
  *(undefined8 *)(puVar29 + -8) = 0x180008d31;
  return;
}

/* ---- FUNC 00008DA0 FUN_180008da0 (22 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_180008da0(undefined8 param_1,int param_2)

{
  if (param_2 != 0) {
    _DAT_1800797d0 = _DAT_1800797d0 + 1;
    return 0;
  }
  _DAT_1800797d0 = _DAT_1800797d0 + -1;
  return 0;
}

/* ---- FUNC 00008DC0 FUN_180008dc0 (185 bytes) ---- */

undefined8 FUN_180008dc0(longlong *param_1,longlong *param_2,longlong *param_3)

{
  *param_3 = 0;
  if ((((*param_2 == DAT_180066c58) && (param_2[1] == DAT_180066c60)) ||
      ((*param_2 == DAT_180066c78 && (param_2[1] == DAT_180066c80)))) ||
     ((*param_2 == DAT_180063570 && (param_2[1] == DAT_180063578)))) {
    *param_3 = (longlong)param_1;
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

/* ---- FUNC 00008E80 FUN_180008e80 (87 bytes) ---- */

undefined8 FUN_180008e80(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  *param_3 = 0;
  if (((*param_2 != DAT_180066c58) || (param_2[1] != DAT_180066c60)) &&
     ((*param_2 != DAT_180066c68 || (param_2[1] != DAT_180066c70)))) {
    return 0x80004002;
  }
  *param_3 = param_1;
  (**(code **)(*param_1 + 8))();
  return 0;
}

/* ---- FUNC 00008EE0 FUN_180008ee0 (10 bytes) ---- */

void FUN_180008ee0(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180008ee7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)**(undefined8 **)(param_1 + 8))();
  return;
}

/* ---- FUNC 00008EF0 FUN_180008ef0 (78 bytes) ---- */

bool FUN_180008ef0(longlong param_1)

{
  undefined8 uVar1;
  
  if (*(longlong *)(param_1 + 0x98) < 1) {
    return true;
  }
  uVar1 = FUN_180007970(param_1 + 0x38);
  if ((int)uVar1 != 0) {
    uVar1 = FUN_180007a60(param_1 + 0x88);
    return (int)uVar1 == 0;
  }
  return false;
}

/* ---- FUNC 00008F40 FUN_180008f40 (54 bytes) ---- */

undefined8 FUN_180008f40(longlong param_1)

{
  if (*(int *)(param_1 + 0x30) == 0) {
    FUN_180008ff0(param_1);
  }
  if (*(int *)(param_1 + 0x30) != 0) {
    FUN_1800538d0(*(longlong *)(param_1 + 0x28));
    return 0;
  }
  return 0x80004005;
}

/* ---- FUNC 00008F80 FUN_180008f80 (46 bytes) ---- */

int FUN_180008f80(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4) + -1;
  *(int *)(param_1 + 4) = iVar1;
  if (iVar1 == 0) {
    FUN_180005ca0(param_1);
    FUN_180025ad0(param_1);
    iVar1 = 0;
  }
  return iVar1;
}

/* ---- FUNC 00008FB0 FUN_180008fb0 (46 bytes) ---- */

int FUN_180008fb0(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 1) + -1;
  *(int *)(param_1 + 1) = iVar1;
  if (iVar1 == 0) {
    FUN_180005d00(param_1);
    FUN_180025ad0(param_1);
    iVar1 = 0;
  }
  return iVar1;
}

/* ---- FUNC 00008FE0 FUN_180008fe0 (11 bytes) ---- */

void FUN_180008fe0(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180008fe7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(longlong **)(param_1 + 8) + 0x10))();
  return;
}

/* ---- FUNC 00008FF0 FUN_180008ff0 (3715 bytes) ---- */

void FUN_180008ff0(longlong param_1)

{
  longlong *plVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined8 uVar5;
  undefined7 extraout_var;
  undefined4 *puVar6;
  undefined7 extraout_var_00;
  undefined7 extraout_var_01;
  undefined7 extraout_var_02;
  undefined7 extraout_var_03;
  undefined7 extraout_var_04;
  undefined7 extraout_var_05;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar7;
  longlong lVar8;
  wchar_t *pwVar9;
  undefined7 extraout_var_06;
  IAtlStringMgr *pIVar10;
  longlong lVar11;
  char *pcVar12;
  undefined8 *puVar13;
  int iVar14;
  longlong lVar15;
  ulonglong uVar16;
  undefined2 uVar17;
  int iVar18;
  uint uVar19;
  ulong uVar21;
  ulonglong uVar22;
  int iVar23;
  uint uVar24;
  uint local_res8 [2];
  int local_res10 [2];
  int local_res18;
  int local_res20;
  undefined4 local_198;
  undefined4 uStack_194;
  longlong local_190;
  undefined4 local_188;
  uint local_180 [2];
  ulong local_178;
  undefined4 uStack_174;
  char *local_170;
  char *local_168;
  char *local_160;
  undefined4 local_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined8 local_148;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_138 [8];
  _union_2707 local_130;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_118 [16];
  undefined4 local_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined8 local_f8;
  CDWordArray local_e8 [8];
  longlong local_e0;
  longlong local_d8;
  CStringArray local_c0 [8];
  longlong local_b8;
  longlong local_b0;
  CDWordArray local_98 [8];
  longlong local_90;
  int local_88;
  undefined4 uStack_84;
  CDWordArray local_70 [8];
  longlong local_68;
  longlong local_60;
  ulonglong uVar20;
  
  local_180[0] = 0;
  local_res8[0] = 0;
  (**(code **)(**(longlong **)(param_1 + 0x28) + 0x108))();
  FUN_18000a830(param_1 + 0x38);
  FUN_18000a830(param_1 + 0xb0);
  local_res10[0] = *(int *)(param_1 + 0x98);
  iVar18 = 0;
  if (0 < local_res10[0]) {
    lVar15 = 0;
    do {
      if ((lVar15 < 0) || (*(longlong *)(param_1 + 0x98) <= lVar15)) goto LAB_180009e68;
      FUN_18000a830(*(longlong *)(*(longlong *)(param_1 + 0x90) + lVar15 * 8));
      iVar18 = iVar18 + 1;
      lVar15 = lVar15 + 1;
    } while (iVar18 < local_res10[0]);
  }
  local_res20 = 0;
  uVar5 = FUN_180007970(param_1 + 0x38);
  bVar3 = false;
  if (((int)uVar5 != 0) && (uVar5 = FUN_180007a60(param_1 + 0x88), bVar3 = false, (int)uVar5 != 0))
  {
    FUN_1800063b0(param_1);
    bVar3 = true;
    local_res20 = 1;
  }
  FUN_180009f90(param_1);
  local_res10[0] = *(int *)(param_1 + 0x98);
  iVar18 = FUN_180007650(param_1 + 0x38);
  local_res18 = iVar18;
  (**(code **)(**(longlong **)(param_1 + 0x28) + 0xb0))(*(longlong **)(param_1 + 0x28),iVar18);
  if (bVar3) {
    uVar17 = 0;
  }
  else {
    bVar2 = FUN_180007860(param_1 + 0x38);
    uVar17 = (undefined2)CONCAT71(extraout_var,bVar2);
  }
  iVar14 = 0;
  uVar24 = 0;
  if (0 < iVar18) {
    do {
      puVar6 = (undefined4 *)
               FUN_1800076c0((longlong *)(param_1 + 0x38),(undefined2 *)&local_108,iVar14);
      local_158 = *puVar6;
      uStack_154 = puVar6[1];
      uStack_150 = puVar6[2];
      uStack_14c = puVar6[3];
      local_148 = *(undefined8 *)(puVar6 + 4);
      (**(code **)(**(longlong **)(param_1 + 0x28) + 0xe0))
                (*(longlong **)(param_1 + 0x28),0,iVar14,uVar17,&local_158);
      iVar14 = iVar14 + 1;
      uVar24 = local_180[0];
    } while (iVar14 < iVar18);
  }
  lVar15 = 0;
  local_188 = (uint)local_188._2_2_ << 0x10;
  iVar14 = local_res10[0];
  if ((bVar3) && (iVar23 = 0, iVar18 = local_res18, iVar4 = local_res10[0], 0 < local_res10[0])) {
    do {
      if ((lVar15 < 0) || (*(longlong *)(param_1 + 0x98) <= lVar15)) goto LAB_180009e68;
      bVar2 = FUN_1800079d0(*(longlong **)(*(longlong *)(param_1 + 0x90) + lVar15 * 8));
      iVar14 = iVar4 + -1;
      if ((int)CONCAT71(extraout_var_00,bVar2) != 0) {
        iVar14 = iVar4;
      }
      iVar23 = iVar23 + 1;
      lVar15 = lVar15 + 1;
      iVar18 = local_res18;
      iVar4 = iVar14;
    } while (iVar23 < local_res10[0]);
  }
  iVar4 = FUN_180007650(param_1 + 0xb0);
  uVar19 = local_188;
  if (0 < iVar4) {
    local_188 = 0xffffffff;
    uVar19 = local_188;
    if ((bVar3) &&
       (bVar3 = FUN_1800079d0((longlong *)(param_1 + 0xb0)), uVar19 = 0xffffffff,
       (int)CONCAT71(extraout_var_01,bVar3) == 0)) {
      local_188 = 0;
      uVar19 = 0;
    }
  }
  bVar3 = (short)uVar19 == -1;
  uVar16 = (ulonglong)bVar3;
  local_res8[0] = (uint)bVar3;
  (**(code **)(**(longlong **)(param_1 + 0x28) + 0xc0))
            (*(longlong **)(param_1 + 0x28),iVar14 + (uint)bVar3);
  (**(code **)(**(longlong **)(param_1 + 0x28) + 0x168))
            (*(longlong **)(param_1 + 0x28),uVar19 & 0xffff);
  uVar22 = uVar16;
  if ((short)uVar19 == -1) {
    bVar3 = FUN_180007860(param_1 + 0xb0);
    iVar14 = 0;
    if (0 < iVar18) {
      do {
        puVar6 = (undefined4 *)
                 FUN_1800076c0((longlong *)(param_1 + 0xb0),(undefined2 *)&local_108,iVar14);
        local_158 = *puVar6;
        uStack_154 = puVar6[1];
        uStack_150 = puVar6[2];
        uStack_14c = puVar6[3];
        local_148 = *(undefined8 *)(puVar6 + 4);
        uVar22 = CONCAT71(extraout_var_02,bVar3) & 0xffff;
        if ((short)*puVar6 == 0) {
          uVar22 = 0;
        }
        (**(code **)(**(longlong **)(param_1 + 0x28) + 0xf0))
                  (*(longlong **)(param_1 + 0x28),0,iVar14,uVar22,&local_158);
        iVar14 = iVar14 + 1;
      } while (iVar14 < iVar18);
      uVar22 = (ulonglong)local_res8[0];
      uVar24 = local_180[0];
    }
  }
  local_178 = 0;
  if (0 < local_res10[0]) {
    local_190 = 0;
    do {
      lVar15 = local_190;
      iVar18 = 0;
      if ((local_190 < 0) || (*(longlong *)(param_1 + 0x98) <= local_190)) {
LAB_180009e68:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x90) + local_190 * 8);
      if ((local_res20 == 0) ||
         (bVar3 = FUN_1800079d0(plVar1), (int)CONCAT71(extraout_var_03,bVar3) != 0)) {
        bVar3 = FUN_180007860((longlong)plVar1);
        iVar14 = local_res18;
        local_198 = (undefined4)CONCAT71(extraout_var_04,bVar3);
        if (0 < local_res18) {
          do {
            puVar6 = (undefined4 *)FUN_1800076c0(plVar1,(undefined2 *)&local_108,iVar18);
            local_158 = *puVar6;
            uStack_154 = puVar6[1];
            uStack_150 = puVar6[2];
            uStack_14c = puVar6[3];
            local_148 = *(undefined8 *)(puVar6 + 4);
            uVar22 = CONCAT71(extraout_var_04,bVar3) & 0xffff;
            if ((short)*puVar6 == 0) {
              uVar22 = 0;
            }
            (**(code **)(**(longlong **)(param_1 + 0x28) + 0xf0))
                      (*(longlong **)(param_1 + 0x28),uVar16,iVar18,uVar22,&local_158);
            iVar18 = iVar18 + 1;
          } while (iVar18 < iVar14);
          uVar22 = (ulonglong)local_res8[0];
          lVar15 = local_190;
          uVar24 = local_180[0];
        }
        uVar16 = (ulonglong)((int)uVar16 + 1);
      }
      local_178 = local_178 + 1;
      local_190 = lVar15 + 1;
    } while ((int)local_178 < local_res10[0]);
  }
  uVar16 = 0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_138,"");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_160,"");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_170,"");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_168);
  if (local_res20 == 0) {
    pCVar7 = FUN_1800067f0((longlong *)(param_1 + 0x38),
                           (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           local_res8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_170,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar7);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res8);
    iVar18 = local_res18;
    local_130.n2.vt = 0;
    if (0 < local_res18) {
      do {
        iVar14 = (**(code **)(**(longlong **)(param_1 + 0x28) + 0xf8))
                           (*(longlong **)(param_1 + 0x28),0,uVar16,local_res8,&local_130);
        if (-1 < iVar14) {
          if ((((short)local_res8[0] == 1) && (local_130.n2.vt == 9)) &&
             (local_130.decVal.u2.Lo64 != 0)) {
            pcVar12 = ATL::CSimpleStringT<char,1>::GetBufferSetLength
                                ((CSimpleStringT<char,1> *)&local_168,0x40);
            puVar13 = (undefined8 *)
                      HAGetDecoratedUnit(*(undefined8 *)((longlong)local_130.decVal.u2 + 0x48),
                                         pcVar12);
            if (puVar13 != (undefined8 *)0x0) {
              if ((code *)*puVar13 != (code *)0x0) {
                (*(code *)*puVar13)(puVar13);
              }
              *pcVar12 = '\0';
            }
            ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_168,-1);
            break;
          }
          VariantClear((VARIANTARG *)&local_130.n2);
        }
        uVar24 = (int)uVar16 + 1;
        uVar16 = (ulonglong)uVar24;
      } while ((int)uVar24 < iVar18);
    }
    if (*(int *)(local_168 + -0x10) == 0) {
      pIVar10 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_170);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_190,pIVar10
                );
      local_res8[0] = 0x80;
      lVar15 = -1;
      do {
        lVar11 = lVar15 + 1;
        pcVar12 = "%Unit%" + lVar15;
        lVar15 = lVar11;
      } while (*pcVar12 != '\0');
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)&local_190,local_170,*(int *)(local_170 + -0x10),
                 " %Unit%",(int)lVar11);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_168,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 &local_190);
      pCVar7 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_190;
    }
    else {
      pIVar10 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_170);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_198,pIVar10
                );
      local_res8[0] = 0x40;
      lVar15 = -1;
      do {
        lVar8 = lVar15 + 1;
        lVar11 = lVar15 + 1;
        lVar15 = lVar8;
      } while (*(char *)((longlong)&DAT_1800633a4 + lVar11) != '\0');
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)&local_198,local_170,*(int *)(local_170 + -0x10)," ",
                 (int)lVar8);
      pIVar10 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_198);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_190,pIVar10
                );
      local_res8[0] = 0x60;
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)&local_190,(char *)CONCAT44(uStack_194,local_198),
                 *(int *)((char *)CONCAT44(uStack_194,local_198) + -0x10),local_168,
                 *(int *)(local_168 + -0x10));
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_168,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 &local_190);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_190);
      pCVar7 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_198;
    }
    uVar24 = 0;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar7);
  }
  else {
    uVar20 = uVar16;
    if (0 < local_res10[0]) {
      do {
        if (((longlong)uVar16 < 0) || (*(longlong *)(param_1 + 0x98) <= (longlong)uVar16)) {
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x90) + uVar16 * 8);
        bVar3 = FUN_1800079d0(plVar1);
        if ((int)CONCAT71(extraout_var_05,bVar3) != 0) {
          pCVar7 = FUN_180006dc0(plVar1,(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                         *)local_res8);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_170,
                     (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     pCVar7);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res8);
          if (*(int *)(local_170 + -0x10) != 0) break;
        }
        uVar19 = (int)uVar20 + 1;
        uVar20 = (ulonglong)uVar19;
        uVar16 = uVar16 + 1;
      } while ((int)uVar19 < local_res10[0]);
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_168,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               &local_170);
  }
  pwVar9 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::AllocSysString
                     ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_168);
  (**(code **)(**(longlong **)(param_1 + 0x28) + 0x70))(*(longlong **)(param_1 + 0x28),pwVar9);
  SysFreeString(pwVar9);
  iVar18 = 0;
  if (0 < local_res10[0]) {
    lVar15 = 0;
    uVar16 = uVar22;
    do {
      if ((lVar15 < 0) || (*(longlong *)(param_1 + 0x98) <= lVar15)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x90) + lVar15 * 8);
      if ((local_res20 == 0) ||
         (bVar3 = FUN_1800079d0(plVar1), (int)CONCAT71(extraout_var_06,bVar3) != 0)) {
        FUN_1800067f0(plVar1,(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_198);
        if (*(int *)(local_160 + -0x10) == 0) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_160,
                     (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     &local_198);
        }
        else {
          pIVar10 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &local_160);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_178,
                     pIVar10);
          local_res8[0] = uVar24 | 8;
          ATL::CSimpleStringT<char,1>::Concatenate
                    ((CSimpleStringT<char,1> *)&local_178,local_160,*(int *)(local_160 + -0x10),
                     " & ",3);
          pIVar10 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &local_178);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_190,
                     pIVar10);
          local_res8[0] = uVar24 | 0xc;
          ATL::CSimpleStringT<char,1>::Concatenate
                    ((CSimpleStringT<char,1> *)&local_190,(char *)CONCAT44(uStack_174,local_178),
                     *(int *)((char *)CONCAT44(uStack_174,local_178) + -0x10),
                     (char *)CONCAT44(uStack_194,local_198),
                     *(int *)((char *)CONCAT44(uStack_194,local_198) + -0x10));
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_160,
                     (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     &local_190);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_190);
          uVar24 = uVar24 & 0xfffffff3;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_178);
        }
        if ((short)local_188 == -1) {
          pCVar7 = FUN_1800067f0((longlong *)(param_1 + 0xb0),local_118);
          pIVar10 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                              (pCVar7);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_180,
                     pIVar10);
          local_res8[0] = uVar24 | 0x10;
          ATL::CSimpleStringT<char,1>::Concatenate
                    ((CSimpleStringT<char,1> *)local_180,*(char **)pCVar7,
                     *(int *)(*(char **)pCVar7 + -0x10)," = %Param%",10);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_198,
                     (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     local_180);
          uVar24 = uVar24 & 0xffffffef;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_180);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_118);
        }
        pwVar9 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::AllocSysString
                           ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_198);
        (**(code **)(**(longlong **)(param_1 + 0x28) + 0xa0))
                  (*(longlong **)(param_1 + 0x28),uVar16,pwVar9);
        SysFreeString(pwVar9);
        uVar16 = (ulonglong)((int)uVar16 + 1);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_198);
      }
      iVar18 = iVar18 + 1;
      lVar15 = lVar15 + 1;
    } while (iVar18 < local_res10[0]);
  }
  pIVar10 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_160);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_198,pIVar10);
  local_res8[0] = uVar24 | 1;
  lVar15 = -1;
  do {
    lVar11 = lVar15 + 1;
    pcVar12 = &DAT_1800637f5 + lVar15;
    lVar15 = lVar11;
  } while (*pcVar12 != '\0');
  ATL::CSimpleStringT<char,1>::Concatenate
            ((CSimpleStringT<char,1> *)&local_198,local_160,*(int *)(local_160 + -0x10)," vs. ",
             (int)lVar11);
  pIVar10 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_198);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_190,pIVar10);
  local_res8[0] = uVar24 | 3;
  ATL::CSimpleStringT<char,1>::Concatenate
            ((CSimpleStringT<char,1> *)&local_190,(char *)CONCAT44(uStack_194,local_198),
             *(int *)((char *)CONCAT44(uStack_194,local_198) + -0x10),local_170,
             *(int *)(local_170 + -0x10));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            (local_138,
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)&local_190
            );
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_190);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_198);
  pwVar9 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::AllocSysString
                     (local_138);
  (**(code **)(**(longlong **)(param_1 + 0x28) + 0x58))(*(longlong **)(param_1 + 0x28),pwVar9);
  SysFreeString(pwVar9);
  uVar21 = 0;
  local_188 = 0;
  CDWordArray::CDWordArray(local_98);
  CDWordArray::CDWordArray(local_70);
  CStringArray::CStringArray(local_c0);
  CDWordArray::CDWordArray(local_e8);
  (**(code **)(**(longlong **)(param_1 + 0x28) + 0xb8))(*(longlong **)(param_1 + 0x28),local_res10);
  uVar16 = uVar22;
  if ((int)uVar22 < local_res10[0]) {
    do {
      iVar14 = 0;
      local_180[0] = 0;
      local_178 = 0;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_198,"");
      iVar18 = local_res18;
      bVar3 = false;
      local_130.n2.vt = 0;
      if (0 < local_res18) {
        do {
          iVar4 = (**(code **)(**(longlong **)(param_1 + 0x28) + 0x100))
                            (*(longlong **)(param_1 + 0x28),uVar16,iVar14,local_res8,&local_130);
          if (-1 < iVar4) {
            if ((((short)local_res8[0] == 1) && (local_130.n2.vt == 9)) &&
               (local_130.decVal.u2.Lo64 != 0)) {
              pcVar12 = ATL::CSimpleStringT<char,1>::GetBufferSetLength
                                  ((CSimpleStringT<char,1> *)&local_198,0x40);
              puVar13 = (undefined8 *)
                        HAGetDecoratedUnit(*(undefined8 *)((longlong)local_130.decVal.u2 + 0x48),
                                           pcVar12);
              if (puVar13 != (undefined8 *)0x0) {
                if ((code *)*puVar13 != (code *)0x0) {
                  (*(code *)*puVar13)(puVar13);
                }
                *pcVar12 = '\0';
              }
              ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_198,-1);
              break;
            }
            VariantClear((VARIANTARG *)&local_130.n2);
          }
          iVar14 = iVar14 + 1;
        } while (iVar14 < iVar18);
      }
      pcVar12 = (char *)CONCAT44(uStack_194,local_198);
      if (*(int *)(pcVar12 + -0x10) == 0) {
        if (((longlong)uVar22 < 0) ||
           (*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x108) <= (longlong)uVar22)) {
LAB_180009e62:
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        FUN_1800515b0(*(longlong *)
                       (*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x100) + uVar22 * 8),local_180
                      ,&local_178);
        lVar15 = 0;
        lVar11 = (longlong)local_88;
        if (0 < lVar11) {
          do {
            if (bVar3) goto LAB_180009db6;
            if ((lVar15 < 0) || (CONCAT44(uStack_84,local_88) <= lVar15)) goto LAB_180009e62;
            if (*(uint *)(local_90 + lVar15 * 4) == local_180[0]) {
              if (local_60 <= lVar15) goto LAB_180009e62;
              if (*(ulong *)(local_68 + lVar15 * 4) == local_178) {
                if (local_d8 <= lVar15) goto LAB_180009e62;
                (**(code **)(**(longlong **)(param_1 + 0x28) + 0x210))
                          (*(longlong **)(param_1 + 0x28),uVar16,
                           *(undefined4 *)(local_e0 + lVar15 * 4));
                bVar3 = true;
              }
            }
            lVar15 = lVar15 + 1;
          } while (lVar15 < lVar11);
LAB_180009cbe:
          if (bVar3) goto LAB_180009db6;
        }
LAB_180009cc6:
        CDWordArray::SetAtGrow(local_98,CONCAT44(uStack_84,local_88),local_180[0]);
        CDWordArray::SetAtGrow(local_70,local_60,local_178);
        CStringArray::SetAtGrow
                  (local_c0,local_b0,
                   (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_198);
        CDWordArray::SetAtGrow(local_e8,local_d8,uVar21);
        (**(code **)(**(longlong **)(param_1 + 0x28) + 0x210))
                  (*(longlong **)(param_1 + 0x28),uVar16,uVar21);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_190,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   &local_198);
        if (*(int *)(local_190 + -0x10) == 0) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_190,
                     "%Quantity% %Unit%");
        }
        local_158 = CONCAT22(local_158._2_2_,2);
        uStack_150 = CONCAT22(uStack_150._2_2_,(short)uVar21);
        pwVar9 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::AllocSysString
                           ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_190);
        local_108 = local_158;
        uStack_104 = uStack_154;
        uStack_100 = uStack_150;
        uStack_fc = uStack_14c;
        local_f8 = local_148;
        (**(code **)(**(longlong **)(param_1 + 0x28) + 0x88))
                  (*(longlong **)(param_1 + 0x28),&local_108,pwVar9);
        SysFreeString(pwVar9);
        local_188 = uVar21 + 1;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_190);
        uVar21 = uVar21 + 1;
      }
      else {
        iVar14 = 0;
        lVar15 = 0;
        iVar18 = (int)local_b0;
        uVar21 = local_188;
        if (iVar18 < 1) goto LAB_180009cc6;
        while (uVar21 = local_188, !bVar3) {
          if ((iVar14 < 0) || (local_b0 <= iVar14)) goto LAB_180009e62;
          iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             (local_b8 + (longlong)iVar14 * 8),pcVar12);
          if (iVar4 == 0) {
            if ((lVar15 < 0) || (local_d8 <= lVar15)) goto LAB_180009e62;
            (**(code **)(**(longlong **)(param_1 + 0x28) + 0x210))
                      (*(longlong **)(param_1 + 0x28),uVar16,*(undefined4 *)(local_e0 + lVar15 * 4))
            ;
            bVar3 = true;
          }
          iVar14 = iVar14 + 1;
          lVar15 = lVar15 + 1;
          uVar21 = local_188;
          if (iVar18 <= lVar15) goto LAB_180009cbe;
          pcVar12 = (char *)CONCAT44(uStack_194,local_198);
        }
      }
LAB_180009db6:
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_198);
      uVar24 = (int)uVar16 + 1;
      uVar22 = uVar22 + 1;
      uVar16 = (ulonglong)uVar24;
    } while ((int)uVar24 < local_res10[0]);
  }
  if (local_res20 != 0) {
    FUN_180005fc0((longlong *)(param_1 + 0x38));
  }
  *(undefined4 *)(param_1 + 0x30) = 1;
  CDWordArray::~CDWordArray(local_e8);
  CStringArray::~CStringArray(local_c0);
  CDWordArray::~CDWordArray(local_70);
  CDWordArray::~CDWordArray(local_98);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_168);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_170);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_160);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_138);
  return;
}

/* ---- FUNC 00009E80 FUN_180009e80 (266 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180009e80(longlong param_1,int param_2)

{
  longlong *plVar1;
  longlong lVar2;
  undefined1 auStack_438 [32];
  undefined1 local_418 [1008];
  ulonglong local_28;
  
  local_28 = DAT_180077818 ^ (ulonglong)auStack_438;
  lVar2 = (longlong)param_2;
  if (param_2 < 0) {
    FUN_180002a20(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hadhocpl.cpp",0x60b);
    LogMessage(local_418,2,1);
  }
  if (*(longlong *)(param_1 + 0x30) <= lVar2) {
    FUN_180002a20(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hadhocpl.cpp",0x60c);
    LogMessage(local_418,2,1);
  }
  if ((-1 < lVar2) && (lVar2 < *(longlong *)(param_1 + 0x30))) {
    plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x28) + lVar2 * 8);
    if (plVar1 != (longlong *)0x0) {
      if ((longlong *)*plVar1 != (longlong *)0x0) {
        (**(code **)(*(longlong *)*plVar1 + 0x10))();
      }
      FUN_180025ad0(plVar1);
    }
    CPtrArray::RemoveAt((CPtrArray *)(param_1 + 0x20),lVar2,1);
    *(undefined4 *)(param_1 + 0x48) = 0xffffffff;
    return;
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00009F90 FUN_180009f90 (648 bytes) ---- */

void FUN_180009f90(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar7;
  int iVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  ulonglong local_res8;
  ulonglong local_res10;
  
  uVar12 = 0;
  iVar4 = 0;
  uVar6 = *(ulonglong *)(param_1 + 0x98);
  local_res8 = uVar6;
  iVar3 = FUN_180007650(param_1 + 0x38);
  local_res10 = (ulonglong)iVar3;
  plVar1 = (longlong *)(param_1 + 0xb0);
  uVar9 = uVar12;
  uVar11 = uVar12;
  if (local_res10 != 0) {
    do {
      iVar8 = (int)uVar9;
      iVar3 = FUN_180007580(param_1 + 0x38,iVar8);
      iVar4 = FUN_180007650((longlong)plVar1);
      if (0 < iVar4) {
        iVar4 = FUN_180007650((longlong)plVar1);
        while ((uVar9 < (ulonglong)(longlong)iVar4 &&
               (iVar4 = FUN_180007580((longlong)plVar1,iVar8), iVar4 < iVar3))) {
          FUN_180009e80((longlong)plVar1,iVar8);
          uVar11 = 1;
          iVar4 = FUN_180007650((longlong)plVar1);
        }
        iVar4 = FUN_180007650((longlong)plVar1);
        if (uVar9 < (ulonglong)(longlong)iVar4) {
          iVar4 = FUN_180007580((longlong)plVar1,iVar8);
          if (iVar3 < iVar4) {
            FUN_180007880((longlong)plVar1,iVar8,(longlong *)0x0,iVar3);
          }
        }
        else {
          FUN_180005f00((longlong)plVar1,(longlong *)0x0,iVar3);
        }
      }
      uVar10 = uVar12;
      if (uVar6 != 0) {
        do {
          if (((longlong)uVar10 < 0) || (*(longlong *)(param_1 + 0x98) <= (longlong)uVar10))
          goto LAB_18000a213;
          lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x90) + uVar10 * 8);
          iVar4 = FUN_180007650(lVar2);
          while ((uVar9 < (ulonglong)(longlong)iVar4 &&
                 (iVar4 = FUN_180007580(lVar2,iVar8), iVar4 < iVar3))) {
            FUN_180009e80(lVar2,iVar8);
            uVar11 = 1;
            iVar4 = FUN_180007650(lVar2);
          }
          iVar4 = FUN_180007650(lVar2);
          if (uVar9 < (ulonglong)(longlong)iVar4) {
            iVar4 = FUN_180007580(lVar2,iVar8);
            if (iVar3 < iVar4) {
              FUN_180007880(lVar2,iVar8,(longlong *)0x0,iVar3);
            }
          }
          else {
            FUN_180005f00(lVar2,(longlong *)0x0,iVar3);
          }
          uVar10 = uVar10 + 1;
          uVar6 = local_res8;
        } while (uVar10 < local_res8);
      }
      iVar4 = (int)uVar11;
      uVar9 = uVar9 + 1;
    } while (uVar9 < local_res10);
  }
  uVar5 = FUN_180007970((longlong)plVar1);
  if ((int)uVar5 != 0) {
    FUN_180005fc0(plVar1);
  }
  uVar6 = *(ulonglong *)(param_1 + 0x98);
  if (uVar6 != 0) {
    do {
      if (((longlong)uVar12 < 0) || ((longlong)uVar6 <= (longlong)uVar12)) {
LAB_18000a213:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x90) + uVar12 * 8);
      uVar5 = FUN_180007970((longlong)plVar1);
      if ((int)uVar5 != 0) {
        if (plVar1 != (longlong *)0x0) {
          FUN_180005d20(plVar1);
          FUN_180025ad0(plVar1);
        }
        CPtrArray::RemoveAt((CPtrArray *)(param_1 + 0x88),uVar12,1);
        uVar12 = uVar12 - 1;
      }
      uVar12 = uVar12 + 1;
      uVar6 = *(ulonglong *)(param_1 + 0x98);
    } while (uVar12 < uVar6);
  }
  if (iVar4 != 0) {
    pCVar7 = FUN_180020fe0((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_res8,6);
    MMAfxMessageBox(*(char **)pCVar7,0x40,-1,0);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
  }
  return;
}

/* ---- FUNC 0000A220 FUN_18000a220 (231 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_18000a220(longlong param_1,IStream *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined1 auStack_438 [32];
  undefined8 local_418 [2];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_180077818 ^ (ulonglong)auStack_438;
  if (*(int *)(param_1 + 0x30) == 0) {
    FUN_180002a20(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hadhocpl.cpp",0x1c2);
    LogMessage(local_408,2,1);
  }
  FUN_1800255a0(local_418);
  uVar1 = FUN_18000a310((longlong *)(param_1 + 0x38),param_2);
  uVar2 = uVar1 & 0xffffffff;
  if (-1 < (int)uVar1) {
    uVar1 = FUN_18000a580(param_1 + 0x88,param_2);
    uVar2 = uVar1 & 0xffffffff;
    if (-1 < (int)uVar1) {
      uVar1 = FUN_18000a310((longlong *)(param_1 + 0xb0),param_2);
      uVar2 = uVar1 & 0xffffffff;
      if (-1 < (int)uVar1) {
        uVar2 = FUN_180054100(*(longlong *)(param_1 + 0x28),param_2);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
  }
  FUN_180025a20(local_418);
  return uVar2;
}

/* ---- FUNC 0000A310 FUN_18000a310 (67 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_18000a310(longlong *param_1,IStream *param_2)

{
  int iVar1;
  int *piVar2;
  longlong *plVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  uint uVar7;
  undefined1 auStack_448 [32];
  ULONG local_428;
  int local_424 [3];
  undefined1 local_418 [1008];
  ulonglong local_28;
  
  local_28 = DAT_180077818 ^ (ulonglong)auStack_448;
  uVar4 = FUN_18002ec50(DAT_180079590,param_2,*param_1);
  if (-1 < (int)uVar4) {
    (*param_2->lpVtbl->Write)(param_2,param_1 + 1,4,(ULONG *)0x0);
    uVar4 = 0;
    uVar7 = 0;
    local_424[0] = 0;
    if ((int)param_1[1] == -2) {
      local_424[0] = 1;
    }
    else if ((-1 < (int)param_1[1]) && (piVar2 = (int *)param_1[2], piVar2 != (int *)0x0)) {
      iVar1 = *piVar2;
      uVar6 = uVar4;
      while (iVar1 != -1) {
        uVar7 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar7;
        iVar1 = piVar2[(int)uVar7];
      }
      local_424[0] = uVar7 + 1;
    }
    (*param_2->lpVtbl->Write)(param_2,local_424,4,(ULONG *)0x0);
    if (local_424[0] < 1) {
      if (param_1[2] != 0) {
        FUN_180002a20(local_418,"Assert failed in file %s line %d",
                      "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hadhocpl.cpp",0x58c);
        LogMessage(local_418,2,1);
      }
    }
    else {
      if (param_1[2] == 0) {
        FUN_180002a20(local_418,"Assert failed in file %s line %d",
                      "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hadhocpl.cpp",0x588);
        LogMessage(local_418,2,1);
      }
      (*param_2->lpVtbl->Write)(param_2,(void *)param_1[2],local_424[0] * 4,(ULONG *)0x0);
    }
    local_428 = *(int *)(param_1[3] + -0x10) + 1;
    (*param_2->lpVtbl->Write)(param_2,&local_428,4,(ULONG *)0x0);
    (*param_2->lpVtbl->Write)(param_2,(void *)param_1[3],local_428,(ULONG *)0x0);
    local_428 = *(ULONG *)(param_1 + 6);
    (*param_2->lpVtbl->Write)(param_2,&local_428,4,(ULONG *)0x0);
    uVar6 = uVar4;
    if (0 < (int)local_428) {
      do {
        if (((longlong)uVar4 < 0) || (param_1[6] <= (longlong)uVar4)) {
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        plVar3 = *(longlong **)(param_1[5] + uVar4 * 8);
        uVar5 = FUN_18002ec50(DAT_180079590,param_2,*plVar3);
        if ((int)uVar5 < 0) {
          return uVar5;
        }
        (*param_2->lpVtbl->Write)(param_2,plVar3 + 1,4,(ULONG *)0x0);
        (*param_2->lpVtbl->Write)(param_2,plVar3 + 2,8,(ULONG *)0x0);
        uVar7 = (int)uVar6 + 1;
        uVar4 = uVar4 + 1;
        uVar6 = (ulonglong)uVar7;
      } while ((int)uVar7 < (int)local_428);
    }
    (*param_2->lpVtbl->Write)(param_2,param_1 + 9,4,(ULONG *)0x0);
    uVar4 = 0;
  }
  return uVar4;
}

/* ---- FUNC 0000A353 FUN_18000a353 (283 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_18000a353(void)

{
  int iVar1;
  int *piVar2;
  longlong *plVar3;
  longlong in_RAX;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  uint uVar7;
  longlong unaff_RSI;
  IStream *unaff_RDI;
  ULONG UStackX_20;
  int iStackX_24;
  
  (**(code **)(in_RAX + 0x20))();
  uVar6 = 0;
  uVar7 = 0;
  iStackX_24 = 0;
  if (*(int *)(unaff_RSI + 8) == -2) {
    iStackX_24 = 1;
  }
  else if ((-1 < *(int *)(unaff_RSI + 8)) &&
          (piVar2 = *(int **)(unaff_RSI + 0x10), piVar2 != (int *)0x0)) {
    iVar1 = *piVar2;
    uVar5 = uVar6;
    while (iVar1 != -1) {
      uVar7 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar7;
      iVar1 = piVar2[(int)uVar7];
    }
    iStackX_24 = uVar7 + 1;
  }
  (*unaff_RDI->lpVtbl->Write)(unaff_RDI,&iStackX_24,4,(ULONG *)0x0);
  if (iStackX_24 < 1) {
    if (*(longlong *)(unaff_RSI + 0x10) != 0) {
      FUN_180002a20(&stack0x00000030,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hadhocpl.cpp",0x58c);
      LogMessage(&stack0x00000030,2,1);
    }
  }
  else {
    if (*(longlong *)(unaff_RSI + 0x10) == 0) {
      FUN_180002a20(&stack0x00000030,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hadhocpl.cpp",0x588);
      LogMessage(&stack0x00000030,2,1);
    }
    (*unaff_RDI->lpVtbl->Write)(unaff_RDI,*(void **)(unaff_RSI + 0x10),iStackX_24 * 4,(ULONG *)0x0);
  }
  UStackX_20 = *(int *)(*(longlong *)(unaff_RSI + 0x18) + -0x10) + 1;
  (*unaff_RDI->lpVtbl->Write)(unaff_RDI,&UStackX_20,4,(ULONG *)0x0);
  (*unaff_RDI->lpVtbl->Write)(unaff_RDI,*(void **)(unaff_RSI + 0x18),UStackX_20,(ULONG *)0x0);
  UStackX_20 = *(ULONG *)(unaff_RSI + 0x30);
  (*unaff_RDI->lpVtbl->Write)(unaff_RDI,&UStackX_20,4,(ULONG *)0x0);
  uVar5 = uVar6;
  if (0 < (int)UStackX_20) {
    do {
      if (((longlong)uVar6 < 0) || (*(longlong *)(unaff_RSI + 0x30) <= (longlong)uVar6)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar3 = *(longlong **)(*(longlong *)(unaff_RSI + 0x28) + uVar6 * 8);
      uVar4 = FUN_18002ec50(DAT_180079590,unaff_RDI,*plVar3);
      if ((int)uVar4 < 0) {
        return uVar4;
      }
      (*unaff_RDI->lpVtbl->Write)(unaff_RDI,plVar3 + 1,4,(ULONG *)0x0);
      (*unaff_RDI->lpVtbl->Write)(unaff_RDI,plVar3 + 2,8,(ULONG *)0x0);
      uVar7 = (int)uVar5 + 1;
      uVar6 = uVar6 + 1;
      uVar5 = (ulonglong)uVar7;
    } while ((int)uVar7 < (int)UStackX_20);
  }
  (*unaff_RDI->lpVtbl->Write)(unaff_RDI,(void *)(unaff_RSI + 0x48),4,(ULONG *)0x0);
  return 0;
}

/* ---- FUNC 0000A46E FUN_18000a46e (234 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_18000a46e(undefined8 param_1,void *param_2,undefined8 param_3,ULONG *param_4)

{
  longlong *plVar1;
  longlong in_RAX;
  ulonglong uVar2;
  uint uVar3;
  ulonglong unaff_RBP;
  ulonglong uVar4;
  longlong unaff_RSI;
  IStream *unaff_RDI;
  ULONG aUStackX_20 [2];
  
  aUStackX_20[0] = *(int *)(in_RAX + -0x10) + 1;
  (*unaff_RDI->lpVtbl->Write)(unaff_RDI,param_2,(int)param_4 + 4,param_4);
  (*unaff_RDI->lpVtbl->Write)(unaff_RDI,*(void **)(unaff_RSI + 0x18),aUStackX_20[0],(ULONG *)0x0);
  aUStackX_20[0] = *(ULONG *)(unaff_RSI + 0x30);
  (*unaff_RDI->lpVtbl->Write)(unaff_RDI,aUStackX_20,4,(ULONG *)0x0);
  uVar4 = unaff_RBP;
  if ((int)unaff_RBP < (int)aUStackX_20[0]) {
    do {
      if (((longlong)unaff_RBP < 0) || (*(longlong *)(unaff_RSI + 0x30) <= (longlong)unaff_RBP)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar1 = *(longlong **)(*(longlong *)(unaff_RSI + 0x28) + unaff_RBP * 8);
      uVar2 = FUN_18002ec50(DAT_180079590,unaff_RDI,*plVar1);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      (*unaff_RDI->lpVtbl->Write)(unaff_RDI,plVar1 + 1,4,(ULONG *)0x0);
      (*unaff_RDI->lpVtbl->Write)(unaff_RDI,plVar1 + 2,8,(ULONG *)0x0);
      uVar3 = (int)uVar4 + 1;
      unaff_RBP = unaff_RBP + 1;
      uVar4 = (ulonglong)uVar3;
    } while ((int)uVar3 < (int)aUStackX_20[0]);
  }
  (*unaff_RDI->lpVtbl->Write)(unaff_RDI,(void *)(unaff_RSI + 0x48),4,(ULONG *)0x0);
  return 0;
}

/* ---- FUNC 0000A558 FUN_18000a558 (26 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18000a558(void)

{
  return;
}

/* ---- FUNC 0000A572 AfxThrowInvalidArgException (5 bytes) ---- */

void __cdecl AfxThrowInvalidArgException(void)

{
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 0000A580 FUN_18000a580 (141 bytes) ---- */

ulonglong FUN_18000a580(longlong param_1,IStream *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  ulonglong uVar5;
  ulonglong local_res8;
  
  local_res8 = *(ulonglong *)(param_1 + 0x10);
  uVar2 = 0;
  (*param_2->lpVtbl->Write)(param_2,&local_res8,4,(ULONG *)0x0);
  uVar3 = uVar2;
  uVar5 = uVar2;
  if (local_res8 != 0) {
    do {
      if (((longlong)uVar2 < 0) || (*(longlong *)(param_1 + 0x10) <= (longlong)uVar2)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      uVar1 = FUN_18000a310(*(longlong **)(*(longlong *)(param_1 + 8) + uVar2 * 8),param_2);
      uVar3 = uVar1 & 0xffffffff;
      if ((int)uVar1 < 0) {
        return uVar3;
      }
      uVar4 = (int)uVar5 + 1;
      uVar2 = uVar2 + 1;
      uVar5 = (ulonglong)uVar4;
    } while ((ulonglong)(longlong)(int)uVar4 < local_res8);
  }
  return uVar3;
}

/* ---- FUNC 0000A610 FUN_18000a610 (11 bytes) ---- */

void FUN_18000a610(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018000a617. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(longlong **)(param_1 + 8) + 0x78))();
  return;
}

/* ---- FUNC 0000A620 FUN_18000a620 (168 bytes) ---- */

undefined4 FUN_18000a620(longlong param_1)

{
  int iVar1;
  wchar_t *bstrString;
  undefined4 uVar2;
  longlong *local_res10;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res18 [16];
  
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18,"VBSelect");
  bstrString = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::AllocSysString
                         (local_res18);
  iVar1 = (**(code **)(*DAT_1800797f0 + 0xd0))(DAT_1800797f0,bstrString,&local_res10);
  if (iVar1 < 0) {
    SysFreeString(bstrString);
    uVar2 = 0x80004005;
  }
  else {
    SysFreeString(bstrString);
    FUN_180006090((CPtrArray *)(param_1 + 0x88));
    FUN_1800081b0(param_1,(CPtrArray *)(param_1 + 0x88),(longlong)local_res10);
    (**(code **)(*local_res10 + 0x10))();
    uVar2 = 0;
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
  return uVar2;
}

/* ---- FUNC 0000A6D0 FUN_18000a6d0 (162 bytes) ---- */

undefined4 FUN_18000a6d0(longlong param_1)

{
  int iVar1;
  wchar_t *bstrString;
  undefined4 uVar2;
  longlong *local_res10;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res18 [16];
  
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18,"VBSelect");
  bstrString = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::AllocSysString
                         (local_res18);
  iVar1 = (**(code **)(*DAT_1800797f0 + 0xd0))(DAT_1800797f0,bstrString,&local_res10);
  if (iVar1 < 0) {
    SysFreeString(bstrString);
    uVar2 = 0x80004005;
  }
  else {
    SysFreeString(bstrString);
    FUN_180005fc0((longlong *)(param_1 + 0x38));
    FUN_1800080d0(param_1,(longlong *)(param_1 + 0x38),(longlong)local_res10);
    (**(code **)(*local_res10 + 0x10))();
    uVar2 = 0;
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
  return uVar2;
}

/* ---- FUNC 0000A780 FUN_18000a780 (168 bytes) ---- */

undefined4 FUN_18000a780(longlong param_1)

{
  int iVar1;
  wchar_t *bstrString;
  undefined4 uVar2;
  longlong *local_res10;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res18 [16];
  
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18,"VBSelect");
  bstrString = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::AllocSysString
                         (local_res18);
  iVar1 = (**(code **)(*DAT_1800797f0 + 0xd0))(DAT_1800797f0,bstrString,&local_res10);
  if (iVar1 < 0) {
    SysFreeString(bstrString);
    uVar2 = 0x80004005;
  }
  else {
    SysFreeString(bstrString);
    FUN_180005fc0((longlong *)(param_1 + 0xb0));
    FUN_1800080d0(param_1,(longlong *)(param_1 + 0xb0),(longlong)local_res10);
    (**(code **)(*local_res10 + 0x10))();
    uVar2 = 0;
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
  return uVar2;
}

/* ---- FUNC 0000A830 FUN_18000a830 (21 bytes) ---- */

void FUN_18000a830(longlong param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  
  uVar2 = *(ulonglong *)(param_1 + 0x30);
  uVar7 = 0;
  if (uVar2 != 0) {
    do {
      uVar1 = uVar7 + 1;
      if (uVar1 < uVar2) {
        uVar6 = uVar1;
        if ((longlong)uVar7 < 0) {
MFC140_DLL_AfxThrowInvalidArgException:
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        do {
          if (*(longlong *)(param_1 + 0x30) <= (longlong)uVar7)
          goto MFC140_DLL_AfxThrowInvalidArgException;
          lVar3 = *(longlong *)(param_1 + 0x28);
          lVar4 = *(longlong *)(lVar3 + uVar7 * 8);
          if (((longlong)uVar6 < 0) || (*(longlong *)(param_1 + 0x30) <= (longlong)uVar6))
          goto MFC140_DLL_AfxThrowInvalidArgException;
          lVar5 = *(longlong *)(lVar3 + uVar6 * 8);
          if (*(int *)(lVar5 + 8) < *(int *)(lVar4 + 8)) {
            *(longlong *)(lVar3 + uVar7 * 8) = lVar5;
            if (*(longlong *)(param_1 + 0x30) <= (longlong)uVar6)
            goto MFC140_DLL_AfxThrowInvalidArgException;
            *(longlong *)(*(longlong *)(param_1 + 0x28) + uVar6 * 8) = lVar4;
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar2);
      }
      uVar7 = uVar1;
    } while (uVar1 < uVar2);
  }
  return;
}

/* ---- FUNC 0000A845 FUN_18000a845 (108 bytes) ---- */

void FUN_18000a845(undefined8 param_1,longlong param_2,ulonglong param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong unaff_RBX;
  
  do {
    uVar1 = param_3 + 1;
    if (uVar1 < unaff_RBX) {
      uVar5 = uVar1;
      if ((longlong)param_3 < 0) {
MFC140_DLL_AfxThrowInvalidArgException:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      do {
        if (*(longlong *)(param_2 + 0x30) <= (longlong)param_3)
        goto MFC140_DLL_AfxThrowInvalidArgException;
        lVar2 = *(longlong *)(param_2 + 0x28);
        lVar3 = *(longlong *)(lVar2 + param_3 * 8);
        if (((longlong)uVar5 < 0) || (*(longlong *)(param_2 + 0x30) <= (longlong)uVar5))
        goto MFC140_DLL_AfxThrowInvalidArgException;
        lVar4 = *(longlong *)(lVar2 + uVar5 * 8);
        if (*(int *)(lVar4 + 8) < *(int *)(lVar3 + 8)) {
          *(longlong *)(lVar2 + param_3 * 8) = lVar4;
          if (*(longlong *)(param_2 + 0x30) <= (longlong)uVar5)
          goto MFC140_DLL_AfxThrowInvalidArgException;
          *(longlong *)(*(longlong *)(param_2 + 0x28) + uVar5 * 8) = lVar3;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < unaff_RBX);
    }
    param_3 = uVar1;
    if (unaff_RBX <= uVar1) {
      return;
    }
  } while( true );
}

/* ---- FUNC 0000A8B1 FUN_18000a8b1 (6 bytes) ---- */

void FUN_18000a8b1(void)

{
  return;
}

/* ---- FUNC 0000A8B7 AfxThrowInvalidArgException (5 bytes) ---- */

void __cdecl AfxThrowInvalidArgException(void)

{
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 0000A8C0 FUN_18000a8c0 (79 bytes) ---- */

undefined8 FUN_18000a8c0(longlong param_1,undefined8 *param_2)

{
  if (*(int *)(param_1 + 0x30) == 0) {
    FUN_180008ff0(param_1);
  }
  if (*(int *)(param_1 + 0x30) != 0) {
    *param_2 = *(undefined8 *)(param_1 + 0x28);
    (**(code **)(**(longlong **)(param_1 + 0x28) + 8))();
    return 0;
  }
  return 0x80004005;
}

/* ---- FUNC 0000A910 FUN_18000a910 (69 bytes) ---- */

undefined8 * FUN_18000a910(undefined8 *param_1,undefined8 param_2)

{
  HRESULT HVar1;
  
  param_1[1] = param_2;
  *param_1 = CHapp::CHAPEngine::vftable;
  HVar1 = FUN_180033ad0(param_1 + 2,(GUID *)&DAT_180063500);
  if (HVar1 < 0) {
    param_1[2] = 0;
  }
  return param_1;
}

/* ---- FUNC 0000A960 FUN_18000a960 (69 bytes) ---- */

undefined8 * FUN_18000a960(undefined8 *param_1,undefined8 param_2)

{
  HRESULT HVar1;
  
  param_1[1] = param_2;
  *param_1 = CHapp::CHAPLibRef::vftable;
  HVar1 = FUN_180033ad0(param_1 + 2,(GUID *)&DAT_1800634e0);
  if (HVar1 < 0) {
    param_1[2] = 0;
  }
  return param_1;
}

/* ---- FUNC 0000A9B0 FUN_18000a9b0 (495 bytes) ---- */

undefined8 * FUN_18000a9b0(undefined8 *param_1)

{
  *param_1 = CHapp::vftable;
  FUN_1800212f0(param_1 + 6,param_1,&DAT_180063460);
  CStringArray::CStringArray((CStringArray *)(param_1 + 0x15));
  FUN_18005a010(param_1 + 0x1c,param_1,param_1);
  FUN_180058ec0(param_1 + 0x25,param_1,param_1,1);
  FUN_180059ca0(param_1 + 0x2b,param_1,param_1,1);
  FUN_180058e20(param_1 + 0x31,param_1,param_1,1);
  CMapStringToPtr::CMapStringToPtr((CMapStringToPtr *)(param_1 + 0x37),10);
  CPtrArray::CPtrArray((CPtrArray *)(param_1 + 0x3e));
  CPtrArray::CPtrArray((CPtrArray *)(param_1 + 0x43));
  FUN_18000a960(param_1 + 0x48,param_1);
  FUN_18000a910(param_1 + 0x4b,param_1);
  FUN_18000ae50(param_1 + 0x4e,param_1);
  FUN_18000aea0(param_1 + 0x51,param_1);
  param_1[0x5b] = CHapp::CImpIParentAdviseSink::vftable;
  param_1[0x5c] = param_1;
  FUN_18000aba0(param_1 + 0x5f,param_1);
  FUN_18000ac60(param_1 + 0x62,param_1);
  FUN_18000abf0(param_1 + 0x65,param_1);
  FUN_18000ac10(param_1 + 0x67,param_1);
  param_1[0x6a] = CHapp::CImpIServiceProvider::vftable;
  param_1[0x6b] = param_1;
  param_1[4] = 0;
  param_1[1] = 0;
  param_1[5] = 0;
  param_1[2] = 0;
  param_1[0x1a] = 0;
  *(undefined4 *)(param_1 + 3) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x30] = 0;
  param_1[0x2a] = 0;
  param_1[0x14] = 0;
  param_1[0x5e] = 0;
  param_1[0x36] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  *(undefined4 *)(param_1 + 0x1b) = 0;
  *(undefined4 *)(param_1 + 0x13) = 0;
  return param_1;
}

/* ---- FUNC 0000ABA0 FUN_18000aba0 (69 bytes) ---- */

undefined8 * FUN_18000aba0(undefined8 *param_1,undefined8 param_2)

{
  HRESULT HVar1;
  
  param_1[1] = param_2;
  *param_1 = CHapp::CImpIHAPHandle::vftable;
  HVar1 = FUN_180033ad0(param_1 + 2,(GUID *)&DAT_180063490);
  if (HVar1 < 0) {
    param_1[2] = 0;
  }
  return param_1;
}

/* ---- FUNC 0000ABF0 FUN_18000abf0 (18 bytes) ---- */

undefined8 * FUN_18000abf0(undefined8 *param_1,undefined8 param_2)

{
  param_1[1] = param_2;
  *param_1 = CHapp::CImpIHappInternalMessage::vftable;
  return param_1;
}

/* ---- FUNC 0000AC10 FUN_18000ac10 (69 bytes) ---- */

undefined8 * FUN_18000ac10(undefined8 *param_1,undefined8 param_2)

{
  HRESULT HVar1;
  
  param_1[1] = param_2;
  *param_1 = CHapp::CImpIHappServiceProvider::vftable;
  HVar1 = FUN_180033ad0(param_1 + 2,(GUID *)&DAT_1800635c0);
  if (HVar1 < 0) {
    param_1[2] = 0;
  }
  return param_1;
}

/* ---- FUNC 0000AC60 FUN_18000ac60 (107 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 * FUN_18000ac60(undefined8 *param_1,undefined8 param_2)

{
  HRESULT HVar1;
  undefined1 auStack_48 [32];
  GUID local_28;
  ulonglong local_18;
  
  local_18 = DAT_180077818 ^ (ulonglong)auStack_48;
  param_1[1] = param_2;
  *param_1 = CHapp::CImpIProvideClassInfo::vftable;
  local_28.Data1 = (ulong)DAT_180063520;
  local_28.Data2 = DAT_180063520._4_2_;
  local_28.Data3 = DAT_180063520._6_2_;
  local_28.Data4[0] = DAT_180063528[0];
  local_28.Data4[1] = DAT_180063528[1];
  local_28.Data4[2] = DAT_180063528[2];
  local_28.Data4[3] = DAT_180063528[3];
  local_28.Data4[4] = DAT_180063528[4];
  local_28.Data4[5] = DAT_180063528[5];
  local_28.Data4[6] = DAT_180063528[6];
  local_28.Data4[7] = DAT_180063528[7];
  HVar1 = FUN_180033ad0(param_1 + 2,&local_28);
  if (HVar1 < 0) {
    param_1[2] = 0;
  }
  return param_1;
}

/* ---- FUNC 0000ACD0 FUN_18000acd0 (86 bytes) ---- */

undefined8 * FUN_18000acd0(undefined8 *param_1,longlong param_2)

{
  undefined1 auVar1 [16];
  __uint64 _Var2;
  void *pvVar3;
  longlong lVar4;
  int iVar5;
  
  *(undefined4 *)(param_1 + 1) = 1;
  *param_1 = CImplEnumAModelLibrary::vftable;
  iVar5 = *(int *)(param_2 + 0xc);
  *(int *)((longlong)param_1 + 0xc) = iVar5;
  auVar1._8_8_ = 0;
  auVar1._0_8_ = (longlong)iVar5;
  _Var2 = SUB168(ZEXT816(8) * auVar1,0);
  if (SUB168(ZEXT816(8) * auVar1,8) != 0) {
    _Var2 = 0xffffffffffffffff;
  }
  pvVar3 = operator_new__(_Var2);
  iVar5 = 0;
  param_1[3] = pvVar3;
  if (0 < *(int *)((longlong)param_1 + 0xc)) {
    lVar4 = 0;
    do {
      *(undefined8 *)(lVar4 + param_1[3]) = *(undefined8 *)(lVar4 + *(longlong *)(param_2 + 0x18));
      if (*(longlong **)(lVar4 + param_1[3]) != (longlong *)0x0) {
        (**(code **)(**(longlong **)(lVar4 + param_1[3]) + 8))();
      }
      iVar5 = iVar5 + 1;
      lVar4 = lVar4 + 8;
    } while (iVar5 < *(int *)((longlong)param_1 + 0xc));
  }
  *(undefined4 *)(param_1 + 2) = *(undefined4 *)(param_2 + 0x10);
  return param_1;
}

/* ---- FUNC 0000AD26 FUN_18000ad26 (61 bytes) ---- */

void FUN_18000ad26(void)

{
  longlong *plVar1;
  ulonglong uVar2;
  longlong unaff_RBP;
  uint unaff_ESI;
  longlong unaff_RDI;
  
  uVar2 = (ulonglong)unaff_ESI;
  do {
    *(undefined8 *)(uVar2 + *(longlong *)(unaff_RDI + 0x18)) =
         *(undefined8 *)(uVar2 + *(longlong *)(unaff_RBP + 0x18));
    plVar1 = *(longlong **)(uVar2 + *(longlong *)(unaff_RDI + 0x18));
    if (plVar1 != (longlong *)0x0) {
      (**(code **)(*plVar1 + 8))();
    }
    unaff_ESI = unaff_ESI + 1;
    uVar2 = uVar2 + 8;
  } while ((int)unaff_ESI < *(int *)(unaff_RDI + 0xc));
  *(undefined4 *)(unaff_RDI + 0x10) = *(undefined4 *)(unaff_RBP + 0x10);
  return;
}

/* ---- FUNC 0000AD63 FUN_18000ad63 (25 bytes) ---- */

void FUN_18000ad63(void)

{
  longlong unaff_RBP;
  longlong unaff_RDI;
  
  *(undefined4 *)(unaff_RDI + 0x10) = *(undefined4 *)(unaff_RBP + 0x10);
  return;
}

/* ---- FUNC 0000AD80 FUN_18000ad80 (49 bytes) ---- */

undefined8 * FUN_18000ad80(undefined8 *param_1)

{
  undefined1 auVar1 [16];
  int iVar2;
  __uint64 _Var3;
  void *pvVar4;
  IAUserModelLibrary *pIVar5;
  longlong lVar6;
  
  *(undefined4 *)(param_1 + 1) = 1;
  *param_1 = CImplEnumAModelLibrary::vftable;
  if (*(CApwnLibraries **)g_pApwnLibs_exref == (CApwnLibraries *)0x0) {
    *(undefined8 *)((longlong)param_1 + 0xc) = 0;
    param_1[3] = 0;
    return param_1;
  }
  iVar2 = CApwnLibraries::CountLibraries(*(CApwnLibraries **)g_pApwnLibs_exref);
  *(int *)((longlong)param_1 + 0xc) = iVar2;
  auVar1._8_8_ = 0;
  auVar1._0_8_ = (longlong)iVar2;
  _Var3 = SUB168(ZEXT816(8) * auVar1,0);
  if (SUB168(ZEXT816(8) * auVar1,8) != 0) {
    _Var3 = 0xffffffffffffffff;
  }
  pvVar4 = operator_new__(_Var3);
  param_1[3] = pvVar4;
  iVar2 = 0;
  if (0 < *(int *)((longlong)param_1 + 0xc)) {
    lVar6 = 0;
    do {
      pIVar5 = CApwnLibraries::GetLibrary(*(CApwnLibraries **)g_pApwnLibs_exref,iVar2);
      iVar2 = iVar2 + 1;
      *(IAUserModelLibrary **)(lVar6 + param_1[3]) = pIVar5;
      lVar6 = lVar6 + 8;
    } while (iVar2 < *(int *)((longlong)param_1 + 0xc));
  }
  *(undefined4 *)(param_1 + 2) = 0;
  return param_1;
}

/* ---- FUNC 0000ADB1 FUN_18000adb1 (57 bytes) ---- */

void FUN_18000adb1(CApwnLibraries *param_1)

{
  undefined1 auVar1 [16];
  int iVar2;
  __uint64 _Var3;
  void *pvVar4;
  IAUserModelLibrary *pIVar5;
  longlong unaff_RBX;
  longlong lVar6;
  
  iVar2 = CApwnLibraries::CountLibraries(param_1);
  *(int *)(unaff_RBX + 0xc) = iVar2;
  auVar1._8_8_ = 0;
  auVar1._0_8_ = (longlong)iVar2;
  _Var3 = SUB168(ZEXT816(8) * auVar1,0);
  if (SUB168(ZEXT816(8) * auVar1,8) != 0) {
    _Var3 = 0xffffffffffffffff;
  }
  pvVar4 = operator_new__(_Var3);
  *(void **)(unaff_RBX + 0x18) = pvVar4;
  iVar2 = 0;
  if (0 < *(int *)(unaff_RBX + 0xc)) {
    lVar6 = 0;
    do {
      pIVar5 = CApwnLibraries::GetLibrary(*(CApwnLibraries **)g_pApwnLibs_exref,iVar2);
      iVar2 = iVar2 + 1;
      *(IAUserModelLibrary **)(lVar6 + *(longlong *)(unaff_RBX + 0x18)) = pIVar5;
      lVar6 = lVar6 + 8;
    } while (iVar2 < *(int *)(unaff_RBX + 0xc));
  }
  *(undefined4 *)(unaff_RBX + 0x10) = 0;
  return;
}

/* ---- FUNC 0000ADEA FUN_18000adea (50 bytes) ---- */

void FUN_18000adea(void)

{
  IAUserModelLibrary *pIVar1;
  longlong unaff_RBX;
  uint unaff_EBP;
  ulonglong uVar2;
  int unaff_EDI;
  
  uVar2 = (ulonglong)unaff_EBP;
  do {
    pIVar1 = CApwnLibraries::GetLibrary(*(CApwnLibraries **)g_pApwnLibs_exref,unaff_EDI);
    unaff_EDI = unaff_EDI + 1;
    *(IAUserModelLibrary **)(uVar2 + *(longlong *)(unaff_RBX + 0x18)) = pIVar1;
    uVar2 = uVar2 + 8;
  } while (unaff_EDI < *(int *)(unaff_RBX + 0xc));
  *(uint *)(unaff_RBX + 0x10) = unaff_EBP;
  return;
}

/* ---- FUNC 0000AE1C FUN_18000ae1c (22 bytes) ---- */

void FUN_18000ae1c(void)

{
  longlong unaff_RBX;
  undefined4 unaff_EBP;
  
  *(undefined4 *)(unaff_RBX + 0x10) = unaff_EBP;
  return;
}

/* ---- FUNC 0000AE32 FUN_18000ae32 (24 bytes) ---- */

void FUN_18000ae32(void)

{
  longlong unaff_RBX;
  
  *(undefined8 *)(unaff_RBX + 0xc) = 0;
  *(undefined8 *)(unaff_RBX + 0x18) = 0;
  return;
}

/* ---- FUNC 0000AE50 FUN_18000ae50 (69 bytes) ---- */

undefined8 * FUN_18000ae50(undefined8 *param_1,undefined8 param_2)

{
  HRESULT HVar1;
  
  param_1[1] = param_2;
  *param_1 = CHapp::CPIAPPDF::vftable;
  HVar1 = FUN_180033ad0(param_1 + 2,(GUID *)&DAT_180063470);
  if (HVar1 < 0) {
    param_1[2] = 0;
  }
  return param_1;
}

/* ---- FUNC 0000AEA0 FUN_18000aea0 (100 bytes) ---- */

undefined8 * FUN_18000aea0(undefined8 *param_1,undefined8 param_2)

{
  HRESULT HVar1;
  
  param_1[1] = param_2;
  param_1[3] = 0;
  *param_1 = CHapp::CPIAPropData::vftable;
  param_1[5] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[6] = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  HVar1 = FUN_180033ad0(param_1 + 2,(GUID *)&DAT_1800634a0);
  if (HVar1 < 0) {
    param_1[2] = 0;
  }
  return param_1;
}

/* ---- FUNC 0000AF30 FUN_18000af30 (34 bytes) ---- */

void FUN_18000af30(undefined8 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}

/* ---- FUNC 0000AF60 FUN_18000af60 (24 bytes) ---- */

void FUN_18000af60(longlong *param_1)

{
  if ((longlong *)*param_1 != (longlong *)0x0) {
    (**(code **)(*(longlong *)*param_1 + 0x10))();
  }
  return;
}

/* ---- FUNC 0000AF80 FUN_18000af80 (15 bytes) ---- */

void FUN_18000af80(void)

{
  AfxTryCleanup();
  return;
}

/* ---- FUNC 0000AF90 FUN_18000af90 (141 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18000af90(undefined8 *param_1)

{
  SAFEARRAY *psa;
  undefined1 auStack_428 [32];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_180077818 ^ (ulonglong)auStack_428;
  *param_1 = APVControlPanelHandler::vftable;
  psa = (SAFEARRAY *)FUN_18000fb50((longlong)param_1);
  if (psa != (SAFEARRAY *)0x0) {
    SafeArrayDestroy(psa);
  }
  if (*(int *)(param_1 + 1) != 0) {
    FUN_180002a20(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\happ.cpp",0x1b49);
    LogMessage(local_408,2,1);
  }
  return;
}

/* ---- FUNC 0000B030 FUN_18000b030 (35 bytes) ---- */

void FUN_18000b030(undefined8 *param_1)

{
  *param_1 = CHapp::CHAPEngine::vftable;
  if ((longlong *)param_1[2] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[2] + 0x10))();
  }
  return;
}

/* ---- FUNC 0000B060 FUN_18000b060 (35 bytes) ---- */

void FUN_18000b060(undefined8 *param_1)

{
  *param_1 = CHapp::CHAPLibRef::vftable;
  if ((longlong *)param_1[2] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[2] + 0x10))();
  }
  return;
}

/* ---- FUNC 0000B090 FUN_18000b090 (25 bytes) ---- */

void FUN_18000b090(longlong param_1)

{
  if (*(longlong **)(param_1 + 0x20) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0x20) + 0x10))();
  }
  return;
}

/* ---- FUNC 0000B0B0 FUN_18000b0b0 (249 bytes) ---- */

void FUN_18000b0b0(undefined8 *param_1)

{
  *param_1 = CHapp::vftable;
  FUN_1800111f0((longlong)param_1);
  param_1[0x6a] = CHapp::CImpIServiceProvider::vftable;
  FUN_18000b1f0(param_1 + 0x67);
  FUN_18000b1e0(param_1 + 0x65);
  FUN_18000b230(param_1 + 0x62);
  FUN_18000b1b0(param_1 + 0x5f);
  param_1[0x5b] = CHapp::CImpIParentAdviseSink::vftable;
  FUN_18000b310(param_1 + 0x51);
  FUN_18000b2e0(param_1 + 0x4e);
  FUN_18000b030(param_1 + 0x4b);
  FUN_18000b060(param_1 + 0x48);
  CPtrArray::~CPtrArray((CPtrArray *)(param_1 + 0x43));
  CPtrArray::~CPtrArray((CPtrArray *)(param_1 + 0x3e));
  CMapStringToPtr::~CMapStringToPtr((CMapStringToPtr *)(param_1 + 0x37));
  FUN_180058e50(param_1 + 0x31);
  FUN_180059cd0(param_1 + 0x2b);
  FUN_180058ef0(param_1 + 0x25);
  FUN_18005a030(param_1 + 0x1c);
  CStringArray::~CStringArray((CStringArray *)(param_1 + 0x15));
  return;
}

/* ---- FUNC 0000B1B0 FUN_18000b1b0 (35 bytes) ---- */

void FUN_18000b1b0(undefined8 *param_1)

{
  *param_1 = CHapp::CImpIHAPHandle::vftable;
  if ((longlong *)param_1[2] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[2] + 0x10))();
  }
  return;
}

/* ---- FUNC 0000B1E0 FUN_18000b1e0 (11 bytes) ---- */

void FUN_18000b1e0(undefined8 *param_1)

{
  *param_1 = CHapp::CImpIHappInternalMessage::vftable;
  return;
}

/* ---- FUNC 0000B1F0 FUN_18000b1f0 (35 bytes) ---- */

void FUN_18000b1f0(undefined8 *param_1)

{
  *param_1 = CHapp::CImpIHappServiceProvider::vftable;
  if ((longlong *)param_1[2] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[2] + 0x10))();
  }
  return;
}

/* ---- FUNC 0000B230 FUN_18000b230 (35 bytes) ---- */

void FUN_18000b230(undefined8 *param_1)

{
  *param_1 = CHapp::CImpIProvideClassInfo::vftable;
  if ((longlong *)param_1[2] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[2] + 0x10))();
  }
  return;
}

/* ---- FUNC 0000B260 FUN_18000b260 (104 bytes) ---- */

void FUN_18000b260(undefined8 *param_1)

{
  int iVar1;
  longlong lVar2;
  
  *param_1 = CImplEnumAModelLibrary::vftable;
  if (0 < *(int *)((longlong)param_1 + 0xc)) {
    iVar1 = 0;
    lVar2 = 0;
    do {
      if (*(longlong **)(lVar2 + param_1[3]) != (longlong *)0x0) {
        (**(code **)(**(longlong **)(lVar2 + param_1[3]) + 0x10))();
      }
      iVar1 = iVar1 + 1;
      lVar2 = lVar2 + 8;
    } while (iVar1 < *(int *)((longlong)param_1 + 0xc));
    operator_delete__((void *)param_1[3]);
  }
  return;
}

/* ---- FUNC 0000B2D0 FUN_18000b2d0 (15 bytes) ---- */

void FUN_18000b2d0(COleDispatchDriver *param_1)

{
  COleDispatchDriver::ReleaseDispatch(param_1);
  return;
}

/* ---- FUNC 0000B2E0 FUN_18000b2e0 (35 bytes) ---- */

void FUN_18000b2e0(undefined8 *param_1)

{
  *param_1 = CHapp::CPIAPPDF::vftable;
  if ((longlong *)param_1[2] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[2] + 0x10))();
  }
  return;
}

/* ---- FUNC 0000B310 FUN_18000b310 (54 bytes) ---- */

void FUN_18000b310(undefined8 *param_1)

{
  *param_1 = CHapp::CPIAPropData::vftable;
  FUN_180011600((longlong)param_1);
  FUN_18000eda0((longlong)param_1);
  if ((longlong *)param_1[2] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[2] + 0x10))();
  }
  return;
}

/* ---- FUNC 0000B350 FUN_18000b350 (110 bytes) ---- */

void FUN_18000b350(undefined8 *param_1)

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
      FUN_180025ad0(puVar3);
    }
    *param_1 = 0;
  }
  return;
}

/* ---- FUNC 0000B3C0 FUN_18000b3c0 (110 bytes) ---- */

undefined8 * FUN_18000b3c0(undefined8 *param_1,uint param_2)

{
  *param_1 = ATL::CComObject<CHNodeSelection>::vftable;
  param_1[2] = ATL::CComObject<CHNodeSelection>::vftable;
  *(undefined4 *)(param_1 + 3) = 0xc0000001;
  FUN_18002e4b0();
  (**(code **)(*DAT_180079320 + 0x10))();
  if ((longlong *)param_1[4] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[4] + 0x10))();
  }
  if ((param_2 & 1) != 0) {
    FUN_180025ad0(param_1);
  }
  return param_1;
}

/* ---- FUNC 0000B430 FUN_18000b430 (94 bytes) ---- */

undefined8 * FUN_18000b430(undefined8 *param_1,uint param_2)

{
  *param_1 = ATL::CComObject<CHappConnectInfo>::vftable;
  param_1[2] = ATL::CComObject<CHappConnectInfo>::vftable;
  *(undefined4 *)(param_1 + 3) = 0xc0000001;
  FUN_18002e4b0();
  (**(code **)(*DAT_180079320 + 0x10))();
  if ((param_2 & 1) != 0) {
    FUN_180025ad0(param_1);
  }
  return param_1;
}

/* ---- FUNC 0000B490 FUN_18000b490 (13186 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_18000b490(longlong *param_1,longlong *param_2)

{
  short *psVar1;
  VARIANTARG *pVVar2;
  short sVar3;
  OLECHAR *pOVar4;
  _union_1719 _Var5;
  int iVar6;
  uint uVar7;
  int iVar8;
  HRESULT HVar9;
  ulonglong uVar10;
  SAFEARRAY *bstrString;
  SAFEARRAY *bstrString_00;
  wchar_t *pwVar11;
  char *pcVar12;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar13;
  BSTR lpWideCharStr;
  undefined8 uVar14;
  SAFEARRAY *pSVar15;
  SAFEARRAYBOUND psa;
  SAFEARRAY *pSVar16;
  undefined1 auStackY_768 [32];
  SAFEARRAYBOUND local_708;
  SAFEARRAYBOUND local_700;
  undefined **local_6f8;
  int local_6f0;
  undefined8 *local_6e8;
  SAFEARRAY *local_6e0;
  int local_6d8;
  undefined8 local_6d4;
  int local_6cc;
  BSTR local_6c8;
  uint local_6c0 [2];
  longlong *local_6b8;
  undefined8 local_6b0;
  LPCSTR local_6a8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_6a0 [8];
  SAFEARRAYBOUND local_698;
  wchar_t *local_690;
  SAFEARRAYBOUND local_688;
  _union_1719 _Stack_680;
  BSTR local_678;
  _union_2707 local_668;
  _union_2707 local_650;
  _union_2707 local_638;
  _union_2707 local_620;
  LONG local_608;
  int local_604;
  BSTR local_600;
  _union_2707 local_5f8;
  _union_2707 local_5e0;
  _union_2707 local_5c8;
  _union_2707 local_5b0;
  _union_2707 local_598;
  _union_2707 local_578;
  _union_2707 local_558;
  SAFEARRAY *local_538;
  SAFEARRAY *local_530;
  longlong *local_528;
  BSTR local_518;
  _union_1719 _Stack_510;
  BSTR local_508;
  SAFEARRAYBOUND local_4f8;
  _union_1719 _Stack_4f0;
  BSTR local_4e8;
  undefined8 local_4d8;
  _union_1719 _Stack_4d0;
  undefined8 local_4c8;
  undefined8 local_4b8;
  _union_1719 _Stack_4b0;
  undefined8 local_4a8;
  undefined8 local_498;
  _union_1719 _Stack_490;
  undefined8 local_488;
  undefined8 local_478;
  _union_1719 _Stack_470;
  undefined8 local_468;
  undefined8 local_458;
  _union_1719 _Stack_450;
  BSTR local_448;
  longlong *local_438;
  undefined1 local_428 [1008];
  ulonglong local_38;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStackY_768;
  local_438 = param_1 + 3;
  local_528 = param_1;
  if ((int)*local_438 != 0) {
    uVar10 = (**(code **)(*param_1 + 0x280))(param_1,0x7e5);
    return uVar10;
  }
  local_620.n2.vt = 8;
  local_620.decVal.u2 = (_union_1719)FUN_18005d480("Local PC");
  local_638.n2.vt = 2;
  local_638._8_2_ = 0xffff;
  pSVar15 = (SAFEARRAY *)0x0;
  local_6c8 = (BSTR)0x0;
  local_538 = (SAFEARRAY *)0x0;
  local_530 = (SAFEARRAY *)0x0;
  VariantInit((VARIANTARG *)&local_598.n2);
  VariantInit((VARIANTARG *)&local_5b0.n2);
  VariantInit((VARIANTARG *)&local_5c8.n2);
  VariantInit((VARIANTARG *)&local_5e0.n2);
  VariantInit((VARIANTARG *)&local_650.n2);
  VariantInit((VARIANTARG *)&local_668.n2);
  VariantInit((VARIANTARG *)&local_5f8.n2);
  local_708.cElements = 0;
  local_708.lLbound = 0;
  local_6f8 = APVControlPanelHandler::vftable;
  local_6e0 = (SAFEARRAY *)0x0;
  local_6e8 = (undefined8 *)0x0;
  local_6f0 = 0;
  local_6cc = -0x55555556;
  local_6d4 = 0;
  local_6d8 = 0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_6a0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6a8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6b0);
  (**(code **)(*param_1 + 0x1c0))(param_1,1);
  if ((int)param_2[2] != 0) {
    psVar1 = (short *)(*param_2 + (ulonglong)((int)param_2[2] - 1) * 0x18);
    sVar3 = *psVar1;
    if (sVar3 == 8) {
      pOVar4 = *(OLECHAR **)(psVar1 + 4);
      if (pOVar4 != local_6c8) {
        SysFreeString(local_6c8);
        if (pOVar4 == (OLECHAR *)0x0) {
          local_6c8 = (BSTR)0x0;
        }
        else {
          local_6c8 = SysAllocString(pOVar4);
          if (local_6c8 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
            FUN_180001a90(-0x7ff8fff2);
          }
        }
      }
    }
    else if (sVar3 == 0x2008) {
      local_708 = *(SAFEARRAYBOUND *)(psVar1 + 4);
    }
    else {
      if ((sVar3 != 0x6008) || (*(SAFEARRAYBOUND **)(psVar1 + 4) == (SAFEARRAYBOUND *)0x0)) {
        uVar7 = (**(code **)(*param_1 + 0x280))(param_1,0x7d4);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6b0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6a8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_6a0);
        iVar6 = local_6cc;
        local_6f8 = APVControlPanelHandler::vftable;
        if ((local_6cc != -0x55555556) && (local_6e8 != (undefined8 *)0x0)) {
          local_700.cElements = 0;
          local_700.lLbound = 0;
          local_708.cElements = 0;
          local_708.lLbound = 0;
          iVar8 = (**(code **)*local_6e8)(local_6e8,&DAT_1800638b8,&local_700);
          if ((-1 < iVar8) &&
             (iVar8 = (**(code **)(*(longlong *)local_700 + 0x20))
                                (local_700,&DAT_180063510,&local_708), -1 < iVar8)) {
            (**(code **)(*(longlong *)local_708 + 0x30))(local_708,iVar6);
          }
          if (local_708 != (SAFEARRAYBOUND)0x0) {
            (**(code **)(*(longlong *)local_708 + 0x10))();
          }
          if (local_700 != (SAFEARRAYBOUND)0x0) {
            (**(code **)(*(longlong *)local_700 + 0x10))();
          }
          local_6e8 = (undefined8 *)0x0;
          local_6cc = -0x55555556;
        }
        if (local_6e0 != (SAFEARRAY *)0x0) {
          pSVar15 = local_6e0;
          if ((int)local_6d4 != local_6d4._4_4_) {
            local_708.lLbound = local_6d8;
            local_708.cElements = ((int)local_6d4 - local_6d8) + 1;
            SafeArrayRedim(local_6e0,&local_708);
            local_6d4 = CONCAT44((local_708.cElements - 1) + local_6d8,(int)local_6d4);
            pSVar15 = local_6e0;
          }
          local_6e0 = (SAFEARRAY *)0x0;
          if (pSVar15 != (SAFEARRAY *)0x0) {
            SafeArrayDestroy(pSVar15);
          }
        }
        if (local_6f0 != 0) {
          FUN_180002a20(local_428,"Assert failed in file %s line %d",
                        "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\happ.cpp",0x1b49);
          LogMessage(local_428,2,1);
        }
        VariantClear((VARIANTARG *)&local_5f8.n2);
        VariantClear((VARIANTARG *)&local_668.n2);
        VariantClear((VARIANTARG *)&local_650.n2);
        VariantClear((VARIANTARG *)&local_5e0.n2);
        VariantClear((VARIANTARG *)&local_5c8.n2);
        VariantClear((VARIANTARG *)&local_5b0.n2);
        VariantClear((VARIANTARG *)&local_598.n2);
        SysFreeString((BSTR)0x0);
        SysFreeString((BSTR)0x0);
        SysFreeString(local_6c8);
        VariantClear((VARIANTARG *)&local_638.n2);
        VariantClear((VARIANTARG *)&local_620.n2);
        return (ulonglong)uVar7;
      }
      local_708 = **(SAFEARRAYBOUND **)(psVar1 + 4);
    }
  }
  if (*(uint *)(param_2 + 2) < 2) {
LAB_18000e534:
    uVar7 = (**(code **)(*param_1 + 0x280))(param_1,0x7d4);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6b0);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6a8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_6a0);
    iVar6 = local_6cc;
    local_6f8 = APVControlPanelHandler::vftable;
    if ((local_6cc != -0x55555556) && (local_6e8 != (undefined8 *)0x0)) {
      local_700.cElements = 0;
      local_700.lLbound = 0;
      local_708.cElements = 0;
      local_708.lLbound = 0;
      iVar8 = (**(code **)*local_6e8)(local_6e8,&DAT_1800638b8,&local_700);
      if ((-1 < iVar8) &&
         (iVar8 = (**(code **)(*(longlong *)local_700 + 0x20))(local_700,&DAT_180063510,&local_708),
         -1 < iVar8)) {
        (**(code **)(*(longlong *)local_708 + 0x30))(local_708,iVar6);
      }
      if (local_708 != (SAFEARRAYBOUND)0x0) {
        (**(code **)(*(longlong *)local_708 + 0x10))();
      }
      if (local_700 != (SAFEARRAYBOUND)0x0) {
        (**(code **)(*(longlong *)local_700 + 0x10))();
      }
      local_6e8 = (undefined8 *)0x0;
      local_6cc = -0x55555556;
    }
    if (local_6e0 != (SAFEARRAY *)0x0) {
      pSVar15 = local_6e0;
      if ((int)local_6d4 != local_6d4._4_4_) {
        local_708.lLbound = local_6d8;
        local_708.cElements = ((int)local_6d4 - local_6d8) + 1;
        SafeArrayRedim(local_6e0,&local_708);
        local_6d4 = CONCAT44((local_708.cElements - 1) + local_6d8,(int)local_6d4);
        pSVar15 = local_6e0;
      }
      local_6e0 = (SAFEARRAY *)0x0;
      if (pSVar15 != (SAFEARRAY *)0x0) {
        SafeArrayDestroy(pSVar15);
      }
    }
    if (local_6f0 != 0) {
      FUN_180002a20(local_428,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\happ.cpp",0x1b49);
      LogMessage(local_428,2,1);
    }
    VariantClear((VARIANTARG *)&local_5f8.n2);
    VariantClear((VARIANTARG *)&local_668.n2);
    VariantClear((VARIANTARG *)&local_650.n2);
    VariantClear((VARIANTARG *)&local_5e0.n2);
    VariantClear((VARIANTARG *)&local_5c8.n2);
    VariantClear((VARIANTARG *)&local_5b0.n2);
    VariantClear((VARIANTARG *)&local_598.n2);
    SysFreeString((BSTR)0x0);
    SysFreeString((BSTR)0x0);
    SysFreeString(local_6c8);
    VariantClear((VARIANTARG *)&local_638.n2);
    VariantClear((VARIANTARG *)&local_620.n2);
    return (ulonglong)uVar7;
  }
  uVar10 = (ulonglong)(*(uint *)(param_2 + 2) - 2);
  if (*(short *)(*param_2 + uVar10 * 0x18) != 8) goto LAB_18000e534;
  pOVar4 = *(OLECHAR **)(*param_2 + 8 + uVar10 * 0x18);
  bstrString = pSVar15;
  if (pOVar4 != (OLECHAR *)0x0) {
    SysFreeString((BSTR)0x0);
    bstrString = (SAFEARRAY *)SysAllocString(pOVar4);
    local_538 = bstrString;
    if (bstrString == (SAFEARRAY *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_180001a90(-0x7ff8fff2);
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6b0,
             (wchar_t *)bstrString);
  iVar6 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6b0,
                     ".aprpdf",0);
  local_6b8 = (longlong *)CONCAT44(local_6b8._4_4_,iVar6);
  if ((*(uint *)(param_2 + 2) < 3) ||
     (pVVar2 = (VARIANTARG *)(*param_2 + (ulonglong)(*(uint *)(param_2 + 2) - 3) * 0x18),
     ((pVVar2->n1).n2.vt - 8 & 0xfffb) != 0)) {
    uVar7 = (**(code **)(*param_1 + 0x280))(param_1,0x7d4);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6b0);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6a8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_6a0);
    iVar6 = local_6cc;
    local_6f8 = APVControlPanelHandler::vftable;
    if ((local_6cc != -0x55555556) && (local_6e8 != (undefined8 *)0x0)) {
      local_700.cElements = 0;
      local_700.lLbound = 0;
      local_708.cElements = 0;
      local_708.lLbound = 0;
      iVar8 = (**(code **)*local_6e8)(local_6e8,&DAT_1800638b8,&local_700);
      if ((-1 < iVar8) &&
         (iVar8 = (**(code **)(*(longlong *)local_700 + 0x20))(local_700,&DAT_180063510,&local_708),
         -1 < iVar8)) {
        (**(code **)(*(longlong *)local_708 + 0x30))(local_708,iVar6);
      }
      if (local_708 != (SAFEARRAYBOUND)0x0) {
        (**(code **)(*(longlong *)local_708 + 0x10))();
      }
      if (local_700 != (SAFEARRAYBOUND)0x0) {
        (**(code **)(*(longlong *)local_700 + 0x10))();
      }
      local_6e8 = (undefined8 *)0x0;
      local_6cc = -0x55555556;
    }
    if (local_6e0 != (SAFEARRAY *)0x0) {
      pSVar15 = local_6e0;
      if ((int)local_6d4 != local_6d4._4_4_) {
        local_708.lLbound = local_6d8;
        local_708.cElements = ((int)local_6d4 - local_6d8) + 1;
        SafeArrayRedim(local_6e0,&local_708);
        local_6d4 = CONCAT44((local_708.cElements - 1) + local_6d8,(int)local_6d4);
        pSVar15 = local_6e0;
      }
      local_6e0 = (SAFEARRAY *)0x0;
      if (pSVar15 != (SAFEARRAY *)0x0) {
        SafeArrayDestroy(pSVar15);
      }
    }
    if (local_6f0 != 0) {
      FUN_180002a20(local_428,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\happ.cpp",0x1b49);
      LogMessage(local_428,2,1);
    }
    VariantClear((VARIANTARG *)&local_5f8.n2);
    VariantClear((VARIANTARG *)&local_668.n2);
    VariantClear((VARIANTARG *)&local_650.n2);
    VariantClear((VARIANTARG *)&local_5e0.n2);
    VariantClear((VARIANTARG *)&local_5c8.n2);
    VariantClear((VARIANTARG *)&local_5b0.n2);
    VariantClear((VARIANTARG *)&local_598.n2);
    SysFreeString((BSTR)0x0);
    SysFreeString((BSTR)bstrString);
    SysFreeString(local_6c8);
    VariantClear((VARIANTARG *)&local_638.n2);
    VariantClear((VARIANTARG *)&local_620.n2);
    return (ulonglong)uVar7;
  }
  uVar7 = VariantCopy((VARIANTARG *)&local_668.n2,pVVar2);
  if ((int)uVar7 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18005d290((ulonglong)uVar7);
  }
  VariantChangeType((VARIANTARG *)&local_668.n2,(VARIANTARG *)&local_668.n2,0,8);
  if (local_668.n2.vt == 8) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              (local_6a0,(wchar_t *)local_668.decVal.u2);
  }
  pSVar16 = pSVar15;
  if (3 < *(uint *)(param_2 + 2)) {
    psVar1 = (short *)(*param_2 + (ulonglong)(*(uint *)(param_2 + 2) - 4) * 0x18);
    if ((*psVar1 + 0xa000U & 0xfff7) == 0) {
      pSVar16 = *(SAFEARRAY **)(psVar1 + 4);
      if (pSVar16 != (SAFEARRAY *)0x0) {
        _Var5._0_2_ = pSVar16->cDims;
        _Var5._2_2_ = pSVar16->fFeatures;
        _Var5._4_4_ = pSVar16->cbElements;
        FUN_18000eb20((longlong)&local_6f8,(SAFEARRAY *)_Var5,param_1);
      }
    }
    else {
      pSVar16 = (SAFEARRAY *)0x0;
      if (*psVar1 == 0x400c) {
        pVVar2 = *(VARIANTARG **)(psVar1 + 4);
        VariantClear(pVVar2);
        (pVVar2->n1).n2.vt = 0x2008;
        pSVar16 = (SAFEARRAY *)&(pVVar2->n1).decVal.u2;
        *(ULONGLONG *)pSVar16 = 0;
        if (pSVar16 != (SAFEARRAY *)0x0) {
          FUN_18000eb20((longlong)&local_6f8,(SAFEARRAY *)0x0,param_1);
        }
      }
    }
  }
  if (*(uint *)(param_2 + 2) < 5) {
    uVar7 = (**(code **)(*param_1 + 0x280))(param_1,0x7d4);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6b0);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6a8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_6a0);
    iVar6 = local_6cc;
    local_6f8 = APVControlPanelHandler::vftable;
    if ((local_6cc != -0x55555556) && (local_6e8 != (undefined8 *)0x0)) {
      local_700.cElements = 0;
      local_700.lLbound = 0;
      local_708.cElements = 0;
      local_708.lLbound = 0;
      iVar8 = (**(code **)*local_6e8)(local_6e8,&DAT_1800638b8,&local_700);
      if ((-1 < iVar8) &&
         (iVar8 = (**(code **)(*(longlong *)local_700 + 0x20))(local_700,&DAT_180063510,&local_708),
         -1 < iVar8)) {
        (**(code **)(*(longlong *)local_708 + 0x30))(local_708,iVar6);
      }
      if (local_708 != (SAFEARRAYBOUND)0x0) {
        (**(code **)(*(longlong *)local_708 + 0x10))();
      }
      if (local_700 != (SAFEARRAYBOUND)0x0) {
        (**(code **)(*(longlong *)local_700 + 0x10))();
      }
      local_6e8 = (undefined8 *)0x0;
      local_6cc = -0x55555556;
    }
    if (local_6e0 != (SAFEARRAY *)0x0) {
      pSVar15 = local_6e0;
      if ((int)local_6d4 != local_6d4._4_4_) {
        local_708.lLbound = local_6d8;
        local_708.cElements = ((int)local_6d4 - local_6d8) + 1;
        SafeArrayRedim(local_6e0,&local_708);
        local_6d4 = CONCAT44((local_708.cElements - 1) + local_6d8,(int)local_6d4);
        pSVar15 = local_6e0;
      }
      local_6e0 = (SAFEARRAY *)0x0;
      if (pSVar15 != (SAFEARRAY *)0x0) {
        SafeArrayDestroy(pSVar15);
      }
    }
    if (local_6f0 != 0) {
      FUN_180002a20(local_428,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\happ.cpp",0x1b49);
      LogMessage(local_428,2,1);
    }
    VariantClear((VARIANTARG *)&local_5f8.n2);
    VariantClear((VARIANTARG *)&local_668.n2);
    VariantClear((VARIANTARG *)&local_650.n2);
    VariantClear((VARIANTARG *)&local_5e0.n2);
    VariantClear((VARIANTARG *)&local_5c8.n2);
    VariantClear((VARIANTARG *)&local_5b0.n2);
    VariantClear((VARIANTARG *)&local_598.n2);
    SysFreeString((BSTR)0x0);
    SysFreeString((BSTR)bstrString);
    SysFreeString(local_6c8);
    VariantClear((VARIANTARG *)&local_638.n2);
    VariantClear((VARIANTARG *)&local_620.n2);
    return (ulonglong)uVar7;
  }
  uVar10 = (ulonglong)(*(uint *)(param_2 + 2) - 5);
  if (*(short *)(*param_2 + uVar10 * 0x18) != 8) {
    uVar7 = (**(code **)(*param_1 + 0x280))(param_1,0x7d4);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6b0);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6a8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_6a0);
    iVar6 = local_6cc;
    local_6f8 = APVControlPanelHandler::vftable;
    if ((local_6cc != -0x55555556) && (local_6e8 != (undefined8 *)0x0)) {
      local_700.cElements = 0;
      local_700.lLbound = 0;
      local_708.cElements = 0;
      local_708.lLbound = 0;
      iVar8 = (**(code **)*local_6e8)(local_6e8,&DAT_1800638b8,&local_700);
      if ((-1 < iVar8) &&
         (iVar8 = (**(code **)(*(longlong *)local_700 + 0x20))(local_700,&DAT_180063510,&local_708),
         -1 < iVar8)) {
        (**(code **)(*(longlong *)local_708 + 0x30))(local_708,iVar6);
      }
      if (local_708 != (SAFEARRAYBOUND)0x0) {
        (**(code **)(*(longlong *)local_708 + 0x10))();
      }
      if (local_700 != (SAFEARRAYBOUND)0x0) {
        (**(code **)(*(longlong *)local_700 + 0x10))();
      }
      local_6e8 = (undefined8 *)0x0;
      local_6cc = -0x55555556;
    }
    if (local_6e0 != (SAFEARRAY *)0x0) {
      pSVar15 = local_6e0;
      if ((int)local_6d4 != local_6d4._4_4_) {
        local_708.lLbound = local_6d8;
        local_708.cElements = ((int)local_6d4 - local_6d8) + 1;
        SafeArrayRedim(local_6e0,&local_708);
        local_6d4 = CONCAT44((local_708.cElements - 1) + local_6d8,(int)local_6d4);
        pSVar15 = local_6e0;
      }
      local_6e0 = (SAFEARRAY *)0x0;
      if (pSVar15 != (SAFEARRAY *)0x0) {
        SafeArrayDestroy(pSVar15);
      }
    }
    if (local_6f0 != 0) {
      FUN_180002a20(local_428,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\happ.cpp",0x1b49);
      LogMessage(local_428,2,1);
    }
    VariantClear((VARIANTARG *)&local_5f8.n2);
    VariantClear((VARIANTARG *)&local_668.n2);
    VariantClear((VARIANTARG *)&local_650.n2);
    VariantClear((VARIANTARG *)&local_5e0.n2);
    VariantClear((VARIANTARG *)&local_5c8.n2);
    VariantClear((VARIANTARG *)&local_5b0.n2);
    VariantClear((VARIANTARG *)&local_598.n2);
    SysFreeString((BSTR)0x0);
    SysFreeString((BSTR)bstrString);
    SysFreeString(local_6c8);
    VariantClear((VARIANTARG *)&local_638.n2);
    VariantClear((VARIANTARG *)&local_620.n2);
    return (ulonglong)uVar7;
  }
  pOVar4 = *(OLECHAR **)(*param_2 + 8 + uVar10 * 0x18);
  bstrString_00 = pSVar15;
  if (pOVar4 != (OLECHAR *)0x0) {
    SysFreeString((BSTR)0x0);
    bstrString_00 = (SAFEARRAY *)SysAllocString(pOVar4);
    local_530 = bstrString_00;
    if (bstrString_00 == (SAFEARRAY *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_180001a90(-0x7ff8fff2);
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6a8,
             (wchar_t *)bstrString_00);
  if (*(int *)(local_6a8 + -0x10) == 0) {
    uVar7 = (**(code **)(*param_1 + 0x280))(param_1,0x7d4);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6b0);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6a8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_6a0);
    iVar6 = local_6cc;
    local_6f8 = APVControlPanelHandler::vftable;
    if ((local_6cc != -0x55555556) && (local_6e8 != (undefined8 *)0x0)) {
      local_700.cElements = 0;
      local_700.lLbound = 0;
      local_708.cElements = 0;
      local_708.lLbound = 0;
      iVar8 = (**(code **)*local_6e8)(local_6e8,&DAT_1800638b8,&local_700);
      if ((-1 < iVar8) &&
         (iVar8 = (**(code **)(*(longlong *)local_700 + 0x20))(local_700,&DAT_180063510,&local_708),
         -1 < iVar8)) {
        (**(code **)(*(longlong *)local_708 + 0x30))(local_708,iVar6);
      }
      if (local_708 != (SAFEARRAYBOUND)0x0) {
        (**(code **)(*(longlong *)local_708 + 0x10))();
      }
      if (local_700 != (SAFEARRAYBOUND)0x0) {
        (**(code **)(*(longlong *)local_700 + 0x10))();
      }
      local_6e8 = (undefined8 *)0x0;
      local_6cc = -0x55555556;
    }
    if (local_6e0 != (SAFEARRAY *)0x0) {
      pSVar15 = local_6e0;
      if ((int)local_6d4 != local_6d4._4_4_) {
        local_708.lLbound = local_6d8;
        local_708.cElements = ((int)local_6d4 - local_6d8) + 1;
        SafeArrayRedim(local_6e0,&local_708);
        local_6d4 = CONCAT44((local_708.cElements - 1) + local_6d8,(int)local_6d4);
        pSVar15 = local_6e0;
      }
      local_6e0 = (SAFEARRAY *)0x0;
      if (pSVar15 != (SAFEARRAY *)0x0) {
        SafeArrayDestroy(pSVar15);
      }
    }
    if (local_6f0 != 0) {
      FUN_180002a20(local_428,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\happ.cpp",0x1b49);
      LogMessage(local_428,2,1);
    }
    VariantClear((VARIANTARG *)&local_5f8.n2);
    VariantClear((VARIANTARG *)&local_668.n2);
    VariantClear((VARIANTARG *)&local_650.n2);
    VariantClear((VARIANTARG *)&local_5e0.n2);
    VariantClear((VARIANTARG *)&local_5c8.n2);
    VariantClear((VARIANTARG *)&local_5b0.n2);
    VariantClear((VARIANTARG *)&local_598.n2);
    SysFreeString((BSTR)bstrString_00);
    SysFreeString((BSTR)bstrString);
    SysFreeString(local_6c8);
    VariantClear((VARIANTARG *)&local_638.n2);
    VariantClear((VARIANTARG *)&local_620.n2);
    return (ulonglong)uVar7;
  }
  uVar7 = VariantClear((VARIANTARG *)&local_650.n2);
  if ((int)uVar7 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18005d290((ulonglong)uVar7);
  }
  local_650.n2.vt = 8;
  local_650.decVal.u2 = (_union_1719)FUN_18005d480(local_6a8);
  psa = local_708;
  if (local_6c8 == (wchar_t *)0x0) {
    if (local_708 == (SAFEARRAYBOUND)0x0) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6b0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6a8);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_6a0);
      iVar6 = local_6cc;
      local_6f8 = APVControlPanelHandler::vftable;
      if ((local_6cc != -0x55555556) && (local_6e8 != (undefined8 *)0x0)) {
        local_700.cElements = 0;
        local_700.lLbound = 0;
        local_708.cElements = 0;
        local_708.lLbound = 0;
        iVar8 = (**(code **)*local_6e8)(local_6e8,&DAT_1800638b8,&local_700);
        if ((-1 < iVar8) &&
           (iVar8 = (**(code **)(*(longlong *)local_700 + 0x20))
                              (local_700,&DAT_180063510,&local_708), -1 < iVar8)) {
          (**(code **)(*(longlong *)local_708 + 0x30))(local_708,iVar6);
        }
        if (local_708 != (SAFEARRAYBOUND)0x0) {
          (**(code **)(*(longlong *)local_708 + 0x10))();
        }
        if (local_700 != (SAFEARRAYBOUND)0x0) {
          (**(code **)(*(longlong *)local_700 + 0x10))();
        }
        local_6e8 = (undefined8 *)0x0;
        local_6cc = -0x55555556;
      }
      if (local_6e0 != (SAFEARRAY *)0x0) {
        pSVar15 = local_6e0;
        if ((int)local_6d4 != local_6d4._4_4_) {
          local_708.lLbound = local_6d8;
          local_708.cElements = ((int)local_6d4 - local_6d8) + 1;
          SafeArrayRedim(local_6e0,&local_708);
          local_6d4 = CONCAT44((local_708.cElements - 1) + local_6d8,(int)local_6d4);
          pSVar15 = local_6e0;
        }
        local_6e0 = (SAFEARRAY *)0x0;
        if (pSVar15 != (SAFEARRAY *)0x0) {
          SafeArrayDestroy(pSVar15);
        }
      }
      if (local_6f0 != 0) {
        FUN_180002a20(local_428,"Assert failed in file %s line %d",
                      "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\happ.cpp",0x1b49);
        LogMessage(local_428,2,1);
      }
      VariantClear((VARIANTARG *)&local_5f8.n2);
      VariantClear((VARIANTARG *)&local_668.n2);
      VariantClear((VARIANTARG *)&local_650.n2);
      VariantClear((VARIANTARG *)&local_5e0.n2);
      VariantClear((VARIANTARG *)&local_5c8.n2);
      VariantClear((VARIANTARG *)&local_5b0.n2);
      VariantClear((VARIANTARG *)&local_598.n2);
      SysFreeString((BSTR)bstrString_00);
      SysFreeString((BSTR)bstrString);
      SysFreeString(local_6c8);
      VariantClear((VARIANTARG *)&local_638.n2);
      VariantClear((VARIANTARG *)&local_620.n2);
      return 0x80070057;
    }
    local_6c0[0] = 0;
    local_608 = 0;
    HVar9 = SafeArrayGetLBound((SAFEARRAY *)local_708,1,(LONG *)local_6c0);
    if ((-1 < HVar9) && (HVar9 = SafeArrayGetUBound((SAFEARRAY *)psa,1,&local_608), -1 < HVar9)) {
      local_698.cElements = (local_608 - local_6c0[0]) + 1;
      if (0 < (int)local_698.cElements) {
        local_690 = (wchar_t *)0x0;
        HVar9 = SafeArrayGetElement((SAFEARRAY *)psa,(LONG *)local_6c0,&local_690);
        if (HVar9 < 0) {
          uVar7 = (**(code **)(*param_1 + 0x280))(param_1,0x7d4);
          SysFreeString(local_690);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6b0);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6a8);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_6a0);
          iVar6 = local_6cc;
          local_6f8 = APVControlPanelHandler::vftable;
          if ((local_6cc != -0x55555556) && (local_6e8 != (undefined8 *)0x0)) {
            local_700.cElements = 0;
            local_700.lLbound = 0;
            local_708.cElements = 0;
            local_708.lLbound = 0;
            iVar8 = (**(code **)*local_6e8)(local_6e8,&DAT_1800638b8,&local_700);
            if ((-1 < iVar8) &&
               (iVar8 = (**(code **)(*(longlong *)local_700 + 0x20))
                                  (local_700,&DAT_180063510,&local_708), -1 < iVar8)) {
              (**(code **)(*(longlong *)local_708 + 0x30))(local_708,iVar6);
            }
            if (local_708 != (SAFEARRAYBOUND)0x0) {
              (**(code **)(*(longlong *)local_708 + 0x10))();
            }
            if (local_700 != (SAFEARRAYBOUND)0x0) {
              (**(code **)(*(longlong *)local_700 + 0x10))();
            }
            local_6e8 = (undefined8 *)0x0;
            local_6cc = -0x55555556;
          }
          if (local_6e0 != (SAFEARRAY *)0x0) {
            pSVar15 = local_6e0;
            if ((int)local_6d4 != local_6d4._4_4_) {
              local_708.lLbound = local_6d8;
              local_708.cElements = ((int)local_6d4 - local_6d8) + 1;
              SafeArrayRedim(local_6e0,&local_708);
              local_6d4 = CONCAT44((local_708.cElements - 1) + local_6d8,(int)local_6d4);
              pSVar15 = local_6e0;
            }
            local_6e0 = (SAFEARRAY *)0x0;
            if (pSVar15 != (SAFEARRAY *)0x0) {
              SafeArrayDestroy(pSVar15);
            }
          }
          if (local_6f0 != 0) {
            FUN_180002a20(local_428,"Assert failed in file %s line %d",
                          "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\happ.cpp",0x1b49);
            LogMessage(local_428,2,1);
          }
          VariantClear((VARIANTARG *)&local_5f8.n2);
          VariantClear((VARIANTARG *)&local_668.n2);
          VariantClear((VARIANTARG *)&local_650.n2);
          VariantClear((VARIANTARG *)&local_5e0.n2);
          VariantClear((VARIANTARG *)&local_5c8.n2);
          VariantClear((VARIANTARG *)&local_5b0.n2);
          VariantClear((VARIANTARG *)&local_598.n2);
          SysFreeString((BSTR)bstrString_00);
          SysFreeString((BSTR)bstrString);
          SysFreeString(local_6c8);
          VariantClear((VARIANTARG *)&local_638.n2);
          VariantClear((VARIANTARG *)&local_620.n2);
          return (ulonglong)uVar7;
        }
        pwVar11 = wcsrchr(local_690,L'.');
        local_4f8._2_6_ = local_650._2_6_;
        local_4f8.cElements._0_2_ = local_650.n2.vt;
        _Stack_4f0 = local_650.decVal.u2;
        local_4e8 = (BSTR)local_650._16_8_;
        local_518 = (BSTR)CONCAT62(local_668._2_6_,local_668.n2.vt);
        _Stack_510 = local_668.decVal.u2;
        local_508 = (BSTR)local_668._16_8_;
        local_458 = CONCAT62(local_638._2_6_,local_638.n2.vt);
        _Stack_450.Lo64._2_6_ = local_638._10_6_;
        _Stack_450.s2.Lo32._0_2_ = local_638._8_2_;
        local_448 = (BSTR)local_638._16_8_;
        local_478 = local_5e0._0_8_;
        _Stack_470 = local_5e0.decVal.u2;
        local_468 = local_5e0._16_8_;
        local_498 = local_5c8._0_8_;
        _Stack_490 = local_5c8.decVal.u2;
        local_488 = local_5c8._16_8_;
        local_4b8 = local_5b0._0_8_;
        _Stack_4b0 = local_5b0.decVal.u2;
        local_4a8 = local_5b0._16_8_;
        local_4d8 = local_598._0_8_;
        _Stack_4d0 = local_598.decVal.u2;
        local_4c8 = local_598._16_8_;
        local_558._2_6_ = local_620._2_6_;
        local_558.n2.vt = local_620.n2.vt;
        local_558.decVal.u2 = local_620.decVal.u2;
        local_558._16_8_ = local_620._16_8_;
        local_578._0_8_ = local_5f8._0_8_;
        local_578.decVal.u2 = local_5f8.decVal.u2;
        local_578._16_8_ = local_5f8._16_8_;
        local_688.cElements = local_5f8._0_4_;
        local_688.lLbound = local_5f8.decVal.Hi32;
        _Stack_680 = local_5f8.decVal.u2;
        local_678 = (BSTR)local_5f8._16_8_;
        pcVar12 = FUN_180017c40(param_1,&local_688,&local_578,(undefined8 *)&local_558,&local_4d8,
                                &local_4b8,&local_498,&local_478,&local_458,&local_518,&local_4f8);
        uVar7 = (uint)pcVar12;
        if (uVar7 == 0) {
          FUN_1800373a0();
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_700,
                     local_690);
          if ((pwVar11 == (wchar_t *)0x0) ||
             ((iVar6 = _wcsicmp(pwVar11,L".inp"), iVar6 != 0 &&
              (iVar6 = _wcsicmp(pwVar11,L".aprinp"), iVar6 != 0)))) {
LAB_18000c9b2:
            uVar7 = (**(code **)(*param_1 + 0x2c8))(param_1,local_700);
          }
          else {
            pCVar13 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                 &local_700,(int)&local_688);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_700,
                       pCVar13);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_688);
            iVar6 = MVGetProductCode();
            pcVar12 = ".aprbkp";
            if (iVar6 == 1) {
              pcVar12 = ".bkp";
            }
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_700,
                       pcVar12);
            iVar6 = _access((char *)local_700,0);
            if ((iVar6 != -1) ||
               (uVar7 = (**(code **)(*param_1 + 0x2a0))(param_1,&local_690), uVar7 == 0))
            goto LAB_18000c9b2;
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_700);
        }
        FUN_1800373a0();
        iVar6 = local_6cc;
        if ((int)uVar7 < 0) {
          if (pSVar16 != (SAFEARRAY *)0x0) {
            if ((local_6cc != -0x55555556) && (local_6e8 != (undefined8 *)0x0)) {
              local_700.cElements = 0;
              local_700.lLbound = 0;
              local_708.cElements = 0;
              local_708.lLbound = 0;
              iVar8 = (**(code **)*local_6e8)(local_6e8,&DAT_1800638b8,&local_700);
              if ((-1 < iVar8) &&
                 (iVar8 = (**(code **)(*(longlong *)local_700 + 0x20))
                                    (local_700,&DAT_180063510,&local_708), -1 < iVar8)) {
                (**(code **)(*(longlong *)local_708 + 0x30))(local_708,iVar6);
              }
              if (local_708 != (SAFEARRAYBOUND)0x0) {
                (**(code **)(*(longlong *)local_708 + 0x10))();
              }
              if (local_700 != (SAFEARRAYBOUND)0x0) {
                (**(code **)(*(longlong *)local_700 + 0x10))();
              }
              local_6e8 = (undefined8 *)0x0;
              local_6cc = -0x55555556;
            }
            if (local_6e0 != (SAFEARRAY *)0x0) {
              pSVar15 = local_6e0;
              if ((int)local_6d4 != local_6d4._4_4_) {
                local_688.lLbound = local_6d8;
                local_688.cElements = ((int)local_6d4 - local_6d8) + 1;
                SafeArrayRedim(local_6e0,&local_688);
                local_6d4 = CONCAT44((local_688.cElements - 1) + local_6d8,(int)local_6d4);
                pSVar15 = local_6e0;
              }
              local_6e0 = (SAFEARRAY *)0x0;
            }
            *(SAFEARRAY **)pSVar16 = pSVar15;
          }
          Ordinal_129(&DAT_18006271e,&DAT_18006271e);
          if ((int)param_1[3] != 0) {
            FUN_18000ef30(param_1,1);
          }
          SysFreeString(local_690);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6b0);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6a8);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_6a0);
          iVar6 = local_6cc;
          local_6f8 = APVControlPanelHandler::vftable;
          if ((local_6cc != -0x55555556) && (local_6e8 != (undefined8 *)0x0)) {
            local_700.cElements = 0;
            local_700.lLbound = 0;
            local_708.cElements = 0;
            local_708.lLbound = 0;
            iVar8 = (**(code **)*local_6e8)(local_6e8,&DAT_1800638b8,&local_700);
            if ((-1 < iVar8) &&
               (iVar8 = (**(code **)(*(longlong *)local_700 + 0x20))
                                  (local_700,&DAT_180063510,&local_708), -1 < iVar8)) {
              (**(code **)(*(longlong *)local_708 + 0x30))(local_708,iVar6);
            }
            if (local_708 != (SAFEARRAYBOUND)0x0) {
              (**(code **)(*(longlong *)local_708 + 0x10))();
            }
            if (local_700 != (SAFEARRAYBOUND)0x0) {
              (**(code **)(*(longlong *)local_700 + 0x10))();
            }
            local_6e8 = (undefined8 *)0x0;
            local_6cc = -0x55555556;
          }
          if (local_6e0 != (SAFEARRAY *)0x0) {
            pSVar15 = local_6e0;
            if ((int)local_6d4 != local_6d4._4_4_) {
              local_708.lLbound = local_6d8;
              local_708.cElements = ((int)local_6d4 - local_6d8) + 1;
              SafeArrayRedim(local_6e0,&local_708);
              local_6d4 = CONCAT44((local_708.cElements - 1) + local_6d8,(int)local_6d4);
              pSVar15 = local_6e0;
            }
            local_6e0 = (SAFEARRAY *)0x0;
            if (pSVar15 != (SAFEARRAY *)0x0) {
              SafeArrayDestroy(pSVar15);
            }
          }
          if (local_6f0 != 0) {
            FUN_180002a20(local_428,"Assert failed in file %s line %d",
                          "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\happ.cpp",0x1b49);
            LogMessage(local_428,2,1);
          }
          VariantClear((VARIANTARG *)&local_5f8.n2);
          VariantClear((VARIANTARG *)&local_668.n2);
          VariantClear((VARIANTARG *)&local_650.n2);
          VariantClear((VARIANTARG *)&local_5e0.n2);
          VariantClear((VARIANTARG *)&local_5c8.n2);
          VariantClear((VARIANTARG *)&local_5b0.n2);
          VariantClear((VARIANTARG *)&local_598.n2);
          SysFreeString((BSTR)bstrString_00);
          SysFreeString((BSTR)bstrString);
          SysFreeString(local_6c8);
          VariantClear((VARIANTARG *)&local_638.n2);
          VariantClear((VARIANTARG *)&local_620.n2);
          return (ulonglong)uVar7;
        }
        SysFreeString(local_690);
        psa = local_708;
      }
      for (local_604 = 1; local_604 < (int)local_698.cElements; local_604 = local_604 + 1) {
        local_690 = (wchar_t *)CONCAT44(local_690._4_4_,local_604 + local_6c0[0]);
        local_688.cElements = 0;
        local_688.lLbound = 0;
        uVar7 = SafeArrayGetElement((SAFEARRAY *)psa,(LONG *)&local_690,&local_688);
        iVar6 = local_6cc;
        if ((int)uVar7 < 0) {
          if (pSVar16 != (SAFEARRAY *)0x0) {
            if ((local_6cc != -0x55555556) && (local_6e8 != (undefined8 *)0x0)) {
              local_6b8 = (longlong *)0x0;
              local_708.cElements = 0;
              local_708.lLbound = 0;
              iVar8 = (**(code **)*local_6e8)(local_6e8,&DAT_1800638b8,&local_6b8);
              if ((-1 < iVar8) &&
                 (iVar8 = (**(code **)(*local_6b8 + 0x20))(local_6b8,&DAT_180063510,&local_708),
                 -1 < iVar8)) {
                (**(code **)(*(longlong *)local_708 + 0x30))(local_708,iVar6);
              }
              if (local_708 != (SAFEARRAYBOUND)0x0) {
                (**(code **)(*(longlong *)local_708 + 0x10))();
              }
              if (local_6b8 != (longlong *)0x0) {
                (**(code **)(*local_6b8 + 0x10))();
              }
              local_6e8 = (undefined8 *)0x0;
              local_6cc = -0x55555556;
            }
            if (local_6e0 != (SAFEARRAY *)0x0) {
              pSVar15 = local_6e0;
              if ((int)local_6d4 != local_6d4._4_4_) {
                local_698.cElements = ((int)local_6d4 - local_6d8) + 1;
                local_698.lLbound = local_6d8;
                SafeArrayRedim(local_6e0,&local_698);
                local_6d4 = CONCAT44((local_698.cElements - 1) + local_6d8,(int)local_6d4);
                pSVar15 = local_6e0;
              }
              local_6e0 = (SAFEARRAY *)0x0;
            }
            *(SAFEARRAY **)pSVar16 = pSVar15;
          }
          Ordinal_129(&DAT_18006271e,&DAT_18006271e);
          if ((int)param_1[3] != 0) {
            FUN_18000ef30(param_1,1);
          }
          uVar7 = (**(code **)(*param_1 + 0x280))(param_1,0x7d4);
          SysFreeString((BSTR)local_688);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6b0);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6a8);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_6a0);
          iVar6 = local_6cc;
          local_6f8 = APVControlPanelHandler::vftable;
          if ((local_6cc != -0x55555556) && (local_6e8 != (undefined8 *)0x0)) {
            local_6b8 = (longlong *)0x0;
            local_708.cElements = 0;
            local_708.lLbound = 0;
            iVar8 = (**(code **)*local_6e8)(local_6e8,&DAT_1800638b8,&local_6b8);
            if ((-1 < iVar8) &&
               (iVar8 = (**(code **)(*local_6b8 + 0x20))(local_6b8,&DAT_180063510,&local_708),
               -1 < iVar8)) {
              (**(code **)(*(longlong *)local_708 + 0x30))(local_708,iVar6);
            }
            if (local_708 != (SAFEARRAYBOUND)0x0) {
              (**(code **)(*(longlong *)local_708 + 0x10))();
            }
            if (local_6b8 != (longlong *)0x0) {
              (**(code **)(*local_6b8 + 0x10))();
            }
            local_6e8 = (undefined8 *)0x0;
            local_6cc = -0x55555556;
          }
          if (local_6e0 != (SAFEARRAY *)0x0) {
            pSVar15 = local_6e0;
            if ((int)local_6d4 != local_6d4._4_4_) {
              local_708.lLbound = local_6d8;
              local_708.cElements = ((int)local_6d4 - local_6d8) + 1;
              SafeArrayRedim(local_6e0,&local_708);
              local_6d4 = CONCAT44((local_708.cElements - 1) + local_6d8,(int)local_6d4);
              pSVar15 = local_6e0;
            }
            local_6e0 = (SAFEARRAY *)0x0;
            if (pSVar15 != (SAFEARRAY *)0x0) {
              SafeArrayDestroy(pSVar15);
            }
          }
          if (local_6f0 != 0) {
            FUN_180002a20(local_428,"Assert failed in file %s line %d",
                          "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\happ.cpp",0x1b49);
            LogMessage(local_428,2,1);
          }
          VariantClear((VARIANTARG *)&local_5f8.n2);
          VariantClear((VARIANTARG *)&local_668.n2);
          VariantClear((VARIANTARG *)&local_650.n2);
          VariantClear((VARIANTARG *)&local_5e0.n2);
          VariantClear((VARIANTARG *)&local_5c8.n2);
          VariantClear((VARIANTARG *)&local_5b0.n2);
          VariantClear((VARIANTARG *)&local_598.n2);
          SysFreeString((BSTR)bstrString_00);
          SysFreeString((BSTR)bstrString);
          SysFreeString(local_6c8);
          VariantClear((VARIANTARG *)&local_638.n2);
          VariantClear((VARIANTARG *)&local_620.n2);
          return (ulonglong)uVar7;
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_700,
                   (wchar_t *)local_688);
        pwVar11 = wcsrchr((wchar_t *)local_688,L'.');
        if ((pwVar11 != (wchar_t *)0x0) &&
           ((iVar6 = _wcsicmp(pwVar11,L".inp"), iVar6 == 0 ||
            (iVar6 = _wcsicmp(pwVar11,L".aprinp"), iVar6 == 0)))) {
          pCVar13 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &local_700,(int)&local_600);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_700,
                     pCVar13);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_600);
          iVar6 = MVGetProductCode();
          pcVar12 = ".aprbkp";
          if (iVar6 == 1) {
            pcVar12 = ".bkp";
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_700,
                     pcVar12);
          iVar6 = _access((char *)local_700,0);
          if (iVar6 == -1) {
            uVar7 = (**(code **)(*param_1 + 0x2a0))(param_1,&local_688);
          }
        }
        if (uVar7 == 0) {
          uVar7 = (**(code **)(*param_1 + 0x2c8))(param_1,local_700);
        }
        FUN_1800373a0();
        iVar6 = local_6cc;
        if ((int)uVar7 < 0) {
          if (pSVar16 != (SAFEARRAY *)0x0) {
            if ((local_6cc != -0x55555556) && (local_6e8 != (undefined8 *)0x0)) {
              local_6b8 = (longlong *)0x0;
              local_708.cElements = 0;
              local_708.lLbound = 0;
              iVar8 = (**(code **)*local_6e8)(local_6e8,&DAT_1800638b8,&local_6b8);
              if ((-1 < iVar8) &&
                 (iVar8 = (**(code **)(*local_6b8 + 0x20))(local_6b8,&DAT_180063510,&local_708),
                 -1 < iVar8)) {
                (**(code **)(*(longlong *)local_708 + 0x30))(local_708,iVar6);
              }
              if (local_708 != (SAFEARRAYBOUND)0x0) {
                (**(code **)(*(longlong *)local_708 + 0x10))();
              }
              if (local_6b8 != (longlong *)0x0) {
                (**(code **)(*local_6b8 + 0x10))();
              }
              local_6e8 = (undefined8 *)0x0;
              local_6cc = -0x55555556;
            }
            if (local_6e0 != (SAFEARRAY *)0x0) {
              pSVar15 = local_6e0;
              if ((int)local_6d4 != local_6d4._4_4_) {
                local_698.cElements = ((int)local_6d4 - local_6d8) + 1;
                local_698.lLbound = local_6d8;
                SafeArrayRedim(local_6e0,&local_698);
                local_6d4 = CONCAT44((local_698.cElements - 1) + local_6d8,(int)local_6d4);
                pSVar15 = local_6e0;
              }
              local_6e0 = (SAFEARRAY *)0x0;
            }
            *(SAFEARRAY **)pSVar16 = pSVar15;
          }
          Ordinal_129(&DAT_18006271e,&DAT_18006271e);
          if ((int)param_1[3] != 0) {
            FUN_18000ef30(param_1,1);
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_700);
          SysFreeString((BSTR)local_688);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6b0);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6a8);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_6a0);
          iVar6 = local_6cc;
          local_6f8 = APVControlPanelHandler::vftable;
          if ((local_6cc != -0x55555556) && (local_6e8 != (undefined8 *)0x0)) {
            local_6b8 = (longlong *)0x0;
            local_708.cElements = 0;
            local_708.lLbound = 0;
            iVar8 = (**(code **)*local_6e8)(local_6e8,&DAT_1800638b8,&local_6b8);
            if ((-1 < iVar8) &&
               (iVar8 = (**(code **)(*local_6b8 + 0x20))(local_6b8,&DAT_180063510,&local_708),
               -1 < iVar8)) {
              (**(code **)(*(longlong *)local_708 + 0x30))(local_708,iVar6);
            }
            if (local_708 != (SAFEARRAYBOUND)0x0) {
              (**(code **)(*(longlong *)local_708 + 0x10))();
            }
            if (local_6b8 != (longlong *)0x0) {
              (**(code **)(*local_6b8 + 0x10))();
            }
            local_6e8 = (undefined8 *)0x0;
            local_6cc = -0x55555556;
          }
          if (local_6e0 != (SAFEARRAY *)0x0) {
            pSVar15 = local_6e0;
            if ((int)local_6d4 != local_6d4._4_4_) {
              local_708.lLbound = local_6d8;
              local_708.cElements = ((int)local_6d4 - local_6d8) + 1;
              SafeArrayRedim(local_6e0,&local_708);
              local_6d4 = CONCAT44((local_708.cElements - 1) + local_6d8,(int)local_6d4);
              pSVar15 = local_6e0;
            }
            local_6e0 = (SAFEARRAY *)0x0;
            if (pSVar15 != (SAFEARRAY *)0x0) {
              SafeArrayDestroy(pSVar15);
            }
          }
          if (local_6f0 != 0) {
            FUN_180002a20(local_428,"Assert failed in file %s line %d",
                          "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\happ.cpp",0x1b49);
            LogMessage(local_428,2,1);
          }
          VariantClear((VARIANTARG *)&local_5f8.n2);
          VariantClear((VARIANTARG *)&local_668.n2);
          VariantClear((VARIANTARG *)&local_650.n2);
          VariantClear((VARIANTARG *)&local_5e0.n2);
          VariantClear((VARIANTARG *)&local_5c8.n2);
          VariantClear((VARIANTARG *)&local_5b0.n2);
          VariantClear((VARIANTARG *)&local_598.n2);
          SysFreeString((BSTR)bstrString_00);
          SysFreeString((BSTR)bstrString);
          SysFreeString(local_6c8);
          VariantClear((VARIANTARG *)&local_638.n2);
          VariantClear((VARIANTARG *)&local_620.n2);
          return (ulonglong)uVar7;
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_700);
        SysFreeString((BSTR)local_688);
        psa = local_708;
      }
    }
  }
  else {
    pwVar11 = wcsrchr(local_6c8,L'.');
    local_558._2_6_ = local_650._2_6_;
    local_558.n2.vt = local_650.n2.vt;
    local_558.decVal.u2 = local_650.decVal.u2;
    local_558._16_8_ = local_650._16_8_;
    local_578._0_8_ = CONCAT62(local_668._2_6_,local_668.n2.vt);
    local_578.decVal.u2 = local_668.decVal.u2;
    local_578._16_8_ = local_668._16_8_;
    local_688._2_6_ = local_638._2_6_;
    local_688.cElements._0_2_ = local_638.n2.vt;
    _Stack_680.Lo64._2_6_ = local_638._10_6_;
    _Stack_680.s2.Lo32._0_2_ = local_638._8_2_;
    local_678 = (BSTR)local_638._16_8_;
    local_4d8 = local_5e0._0_8_;
    _Stack_4d0 = local_5e0.decVal.u2;
    local_4c8 = local_5e0._16_8_;
    local_4b8 = local_5c8._0_8_;
    _Stack_4b0 = local_5c8.decVal.u2;
    local_4a8 = local_5c8._16_8_;
    local_498 = local_5b0._0_8_;
    _Stack_490 = local_5b0.decVal.u2;
    local_488 = local_5b0._16_8_;
    local_478 = local_598._0_8_;
    _Stack_470 = local_598.decVal.u2;
    local_468 = local_598._16_8_;
    local_458 = CONCAT62(local_620._2_6_,local_620.n2.vt);
    _Stack_450 = local_620.decVal.u2;
    local_448 = (BSTR)local_620._16_8_;
    local_518 = (BSTR)local_5f8._0_8_;
    _Stack_510 = local_5f8.decVal.u2;
    local_508 = (BSTR)local_5f8._16_8_;
    local_4f8.cElements = local_5f8._0_4_;
    local_4f8.lLbound = local_5f8.decVal.Hi32;
    _Stack_4f0 = local_5f8.decVal.u2;
    local_4e8 = (BSTR)local_5f8._16_8_;
    pcVar12 = FUN_180017c40(param_1,&local_4f8,&local_518,&local_458,&local_478,&local_498,
                            &local_4b8,&local_4d8,&local_688,(undefined8 *)&local_578,
                            (undefined8 *)&local_558);
    uVar7 = (uint)pcVar12;
    if (uVar7 == 0) {
      FUN_1800373a0();
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_700,
                 local_6c8);
      if ((pwVar11 == (wchar_t *)0x0) ||
         ((iVar6 = _wcsicmp(pwVar11,L".inp"), iVar6 != 0 &&
          (iVar6 = _wcsicmp(pwVar11,L".aprinp"), iVar6 != 0)))) {
LAB_18000c05c:
        uVar7 = (**(code **)(*param_1 + 0x2c8))(param_1,local_700);
      }
      else {
        pCVar13 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_700,(int)&local_708);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_700,
                   pCVar13);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_708);
        iVar6 = MVGetProductCode();
        pcVar12 = ".aprbkp";
        if (iVar6 == 1) {
          pcVar12 = ".bkp";
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_700,
                   pcVar12);
        iVar6 = _access((char *)local_700,0);
        if ((iVar6 != -1) ||
           (uVar7 = (**(code **)(*param_1 + 0x2a0))(param_1,&local_6c8), uVar7 == 0))
        goto LAB_18000c05c;
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_700);
    }
    FUN_1800373a0();
    iVar6 = local_6cc;
    if ((int)uVar7 < 0) {
      if (pSVar16 != (SAFEARRAY *)0x0) {
        if ((local_6cc != -0x55555556) && (local_6e8 != (undefined8 *)0x0)) {
          local_700.cElements = 0;
          local_700.lLbound = 0;
          local_708.cElements = 0;
          local_708.lLbound = 0;
          iVar8 = (**(code **)*local_6e8)(local_6e8,&DAT_1800638b8,&local_700);
          if ((-1 < iVar8) &&
             (iVar8 = (**(code **)(*(longlong *)local_700 + 0x20))
                                (local_700,&DAT_180063510,&local_708), -1 < iVar8)) {
            (**(code **)(*(longlong *)local_708 + 0x30))(local_708,iVar6);
          }
          if (local_708 != (SAFEARRAYBOUND)0x0) {
            (**(code **)(*(longlong *)local_708 + 0x10))();
          }
          if (local_700 != (SAFEARRAYBOUND)0x0) {
            (**(code **)(*(longlong *)local_700 + 0x10))();
          }
          local_6e8 = (undefined8 *)0x0;
          local_6cc = -0x55555556;
        }
        if (local_6e0 != (SAFEARRAY *)0x0) {
          pSVar15 = local_6e0;
          if ((int)local_6d4 != local_6d4._4_4_) {
            local_688.lLbound = local_6d8;
            local_688.cElements = ((int)local_6d4 - local_6d8) + 1;
            SafeArrayRedim(local_6e0,&local_688);
            local_6d4 = CONCAT44((local_688.cElements - 1) + local_6d8,(int)local_6d4);
            pSVar15 = local_6e0;
          }
          local_6e0 = (SAFEARRAY *)0x0;
        }
        *(SAFEARRAY **)pSVar16 = pSVar15;
      }
      Ordinal_129(&DAT_18006271e,&DAT_18006271e);
      if ((int)param_1[3] != 0) {
        FUN_18000ef30(param_1,1);
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6b0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6a8);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_6a0);
      iVar6 = local_6cc;
      local_6f8 = APVControlPanelHandler::vftable;
      if ((local_6cc != -0x55555556) && (local_6e8 != (undefined8 *)0x0)) {
        local_700.cElements = 0;
        local_700.lLbound = 0;
        local_708.cElements = 0;
        local_708.lLbound = 0;
        iVar8 = (**(code **)*local_6e8)(local_6e8,&DAT_1800638b8,&local_700);
        if ((-1 < iVar8) &&
           (iVar8 = (**(code **)(*(longlong *)local_700 + 0x20))
                              (local_700,&DAT_180063510,&local_708), -1 < iVar8)) {
          (**(code **)(*(longlong *)local_708 + 0x30))(local_708,iVar6);
        }
        if (local_708 != (SAFEARRAYBOUND)0x0) {
          (**(code **)(*(longlong *)local_708 + 0x10))();
        }
        if (local_700 != (SAFEARRAYBOUND)0x0) {
          (**(code **)(*(longlong *)local_700 + 0x10))();
        }
        local_6e8 = (undefined8 *)0x0;
        local_6cc = -0x55555556;
      }
      if (local_6e0 != (SAFEARRAY *)0x0) {
        pSVar15 = local_6e0;
        if ((int)local_6d4 != local_6d4._4_4_) {
          local_708.lLbound = local_6d8;
          local_708.cElements = ((int)local_6d4 - local_6d8) + 1;
          SafeArrayRedim(local_6e0,&local_708);
          local_6d4 = CONCAT44((local_708.cElements - 1) + local_6d8,(int)local_6d4);
          pSVar15 = local_6e0;
        }
        local_6e0 = (SAFEARRAY *)0x0;
        if (pSVar15 != (SAFEARRAY *)0x0) {
          SafeArrayDestroy(pSVar15);
        }
      }
      if (local_6f0 != 0) {
        FUN_180002a20(local_428,"Assert failed in file %s line %d",
                      "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\happ.cpp",0x1b49);
        LogMessage(local_428,2,1);
      }
      VariantClear((VARIANTARG *)&local_5f8.n2);
      VariantClear((VARIANTARG *)&local_668.n2);
      VariantClear((VARIANTARG *)&local_650.n2);
      VariantClear((VARIANTARG *)&local_5e0.n2);
      VariantClear((VARIANTARG *)&local_5c8.n2);
      VariantClear((VARIANTARG *)&local_5b0.n2);
      VariantClear((VARIANTARG *)&local_598.n2);
      SysFreeString((BSTR)bstrString_00);
      SysFreeString((BSTR)bstrString);
      SysFreeString(local_6c8);
      VariantClear((VARIANTARG *)&local_638.n2);
      VariantClear((VARIANTARG *)&local_620.n2);
      return (ulonglong)uVar7;
    }
  }
  iVar6 = MVGetProductCode();
  if (iVar6 != 2) {
    local_700.cElements = 0;
    local_700.lLbound = 0;
    local_708.cElements = 0;
    local_708.lLbound = 0;
    iVar6 = (**(code **)(*param_1 + 0x90))();
    if (iVar6 == 0) {
      local_688 = local_700;
      iVar6 = MultiByteToWideChar(0,0,"\\Data\\Setup\\Main\\Input\\RUN_CLASS",-1,(LPWSTR)0x0,0);
      lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,iVar6 - 1);
      if ((lpWideCharStr != (BSTR)0x0) &&
         (iVar8 = MultiByteToWideChar(0,0,"\\Data\\Setup\\Main\\Input\\RUN_CLASS",-1,lpWideCharStr,
                                      iVar6), iVar8 != iVar6)) {
        SysFreeString(lpWideCharStr);
LAB_18000e808:
                    /* WARNING: Subroutine does not return */
        FUN_180001a90(-0x7ff8fff2);
      }
      local_600 = lpWideCharStr;
      if (lpWideCharStr == (BSTR)0x0) goto LAB_18000e808;
      (**(code **)(*(longlong *)local_688 + 0x110))(local_688,lpWideCharStr,&local_708);
      SysFreeString(lpWideCharStr);
      if (local_708 != (SAFEARRAYBOUND)0x0) {
        local_558._0_8_ = local_558._0_8_ & 0xffffffffffff0000;
        FUN_180001780((VARIANTARG *)&local_558.n2,"PROP");
        local_688.cElements = local_558._0_4_;
        local_688.lLbound = local_558.decVal.Hi32;
        _Stack_680 = local_558.decVal.u2;
        local_600 = (BSTR)local_558._16_8_;
        local_578._0_8_ = (BSTR)0x0;
        local_578.decVal.u2.Lo64 = (_union_1719)0x0;
        local_578._16_8_ = (BSTR)0x0;
        VariantInit((VARIANTARG *)&local_578.n2);
        local_4f8 = local_688;
        _Stack_4f0 = _Stack_680;
        local_4e8 = local_600;
        local_518 = (BSTR)local_578._0_8_;
        _Stack_510.Lo64 = (ULONGLONG)local_578.decVal.u2;
        local_508 = (BSTR)local_578._16_8_;
        (**(code **)(*(longlong *)local_708 + 0x70))(local_708,&local_518,&local_4f8);
        VariantClear((VARIANTARG *)&local_578.n2);
        VariantClear((VARIANTARG *)&local_558.n2);
      }
    }
    if (local_708 != (SAFEARRAYBOUND)0x0) {
      (**(code **)(*(longlong *)local_708 + 0x10))();
    }
    if (local_700 != (SAFEARRAYBOUND)0x0) {
      (**(code **)(*(longlong *)local_700 + 0x10))();
    }
  }
  if ((int)local_6b8 == -1) {
    uVar14 = FUN_1800373e0(local_6b0,0xf);
    uVar7 = (uint)uVar14;
  }
  else {
    uVar14 = FUN_1800373e0(local_6b0,0x14);
    uVar7 = (uint)uVar14;
  }
  local_6c0[0] = uVar7;
  FUN_1800373a0();
  iVar6 = local_6cc;
  if (pSVar16 != (SAFEARRAY *)0x0) {
    if ((local_6cc != -0x55555556) && (local_6e8 != (undefined8 *)0x0)) {
      local_700.cElements = 0;
      local_700.lLbound = 0;
      local_708.cElements = 0;
      local_708.lLbound = 0;
      iVar8 = (**(code **)*local_6e8)(local_6e8,&DAT_1800638b8,&local_700);
      if ((-1 < iVar8) &&
         (iVar8 = (**(code **)(*(longlong *)local_700 + 0x20))(local_700,&DAT_180063510,&local_708),
         -1 < iVar8)) {
        (**(code **)(*(longlong *)local_708 + 0x30))(local_708,iVar6);
      }
      if (local_708 != (SAFEARRAYBOUND)0x0) {
        (**(code **)(*(longlong *)local_708 + 0x10))();
      }
      if (local_700 != (SAFEARRAYBOUND)0x0) {
        (**(code **)(*(longlong *)local_700 + 0x10))();
      }
      local_6e8 = (undefined8 *)0x0;
      local_6cc = -0x55555556;
    }
    if (local_6e0 != (SAFEARRAY *)0x0) {
      pSVar15 = local_6e0;
      if ((int)local_6d4 != local_6d4._4_4_) {
        local_688.lLbound = local_6d8;
        local_688.cElements = ((int)local_6d4 - local_6d8) + 1;
        SafeArrayRedim(local_6e0,&local_688);
        local_6d4 = CONCAT44((local_688.cElements - 1) + local_6d8,(int)local_6d4);
        pSVar15 = local_6e0;
      }
      local_6e0 = (SAFEARRAY *)0x0;
    }
    *(SAFEARRAY **)pSVar16 = pSVar15;
  }
  Ordinal_129(&DAT_18006271e,&DAT_18006271e);
  if (((int)uVar7 < 0) && ((int)param_1[3] != 0)) {
    FUN_18000ef30(param_1,1);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6b0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6a8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_6a0);
  iVar6 = local_6cc;
  local_6f8 = APVControlPanelHandler::vftable;
  if ((local_6cc != -0x55555556) && (local_6e8 != (undefined8 *)0x0)) {
    local_700.cElements = 0;
    local_700.lLbound = 0;
    local_708.cElements = 0;
    local_708.lLbound = 0;
    iVar8 = (**(code **)*local_6e8)(local_6e8,&DAT_1800638b8,&local_700);
    if ((-1 < iVar8) &&
       (iVar8 = (**(code **)(*(longlong *)local_700 + 0x20))(local_700,&DAT_180063510,&local_708),
       -1 < iVar8)) {
      (**(code **)(*(longlong *)local_708 + 0x30))(local_708,iVar6);
    }
    if (local_708 != (SAFEARRAYBOUND)0x0) {
      (**(code **)(*(longlong *)local_708 + 0x10))();
    }
    if (local_700 != (SAFEARRAYBOUND)0x0) {
      (**(code **)(*(longlong *)local_700 + 0x10))();
    }
    local_6e8 = (undefined8 *)0x0;
    local_6cc = -0x55555556;
  }
  if (local_6e0 != (SAFEARRAY *)0x0) {
    pSVar15 = local_6e0;
    if ((int)local_6d4 != local_6d4._4_4_) {
      local_708.lLbound = local_6d8;
      local_708.cElements = ((int)local_6d4 - local_6d8) + 1;
      SafeArrayRedim(local_6e0,&local_708);
      local_6d4 = CONCAT44((local_708.cElements - 1) + local_6d8,(int)local_6d4);
      pSVar15 = local_6e0;
    }
    local_6e0 = (SAFEARRAY *)0x0;
    if (pSVar15 != (SAFEARRAY *)0x0) {
      SafeArrayDestroy(pSVar15);
    }
  }
  if (local_6f0 != 0) {
    FUN_180002a20(local_428,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\happ.cpp",0x1b49);
    LogMessage(local_428,2,1);
  }
  VariantClear((VARIANTARG *)&local_5f8.n2);
  VariantClear((VARIANTARG *)&local_668.n2);
  VariantClear((VARIANTARG *)&local_650.n2);
  VariantClear((VARIANTARG *)&local_5e0.n2);
  VariantClear((VARIANTARG *)&local_5c8.n2);
  VariantClear((VARIANTARG *)&local_5b0.n2);
  VariantClear((VARIANTARG *)&local_598.n2);
  SysFreeString((BSTR)bstrString_00);
  SysFreeString((BSTR)bstrString);
  SysFreeString(local_6c8);
  VariantClear((VARIANTARG *)&local_638.n2);
  VariantClear((VARIANTARG *)&local_620.n2);
  return (ulonglong)uVar7;
}

/* ---- FUNC 0000E820 FUN_18000e820 (26 bytes) ---- */

void FUN_18000e820(longlong *param_1)

{
  if ((int)param_1[3] == 0) {
                    /* WARNING: Could not recover jumptable at 0x00018000e82e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x280))(param_1,0x7d2);
    return;
  }
  FUN_180037380();
  return;
}

/* ---- FUNC 0000E840 FUN_18000e840 (153 bytes) ---- */

int FUN_18000e840(longlong param_1,ulonglong param_2)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  longlong *local_res20;
  
  if ((param_2 & 1) == 0) {
    return 0;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == 1) {
    puVar3 = (undefined8 *)GetGlobalPointer("HappNode");
    local_res20 = (longlong *)0x0;
    if ((puVar3 != (undefined8 *)0x0) &&
       (iVar2 = (**(code **)*puVar3)(puVar3,&DAT_1800638d8,&local_res20), iVar2 < 0)) {
      local_res20 = (longlong *)0x0;
    }
    if (local_res20 != (longlong *)0x0) {
      (**(code **)(*local_res20 + 0x18))(local_res20,1);
    }
    if (local_res20 != (longlong *)0x0) {
      (**(code **)(*local_res20 + 0x10))(local_res20);
    }
  }
  return iVar1;
}

/* ---- FUNC 0000E8E0 FUN_18000e8e0 (9 bytes) ---- */

void FUN_18000e8e0(longlong param_1)

{
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  return;
}

/* ---- FUNC 0000E8EC FUN_18000e8ec (9 bytes) ---- */

void FUN_18000e8ec(longlong param_1)

{
  FUN_18000e8e0(param_1 + -0x10);
  return;
}

/* ---- FUNC 0000E900 FUN_18000e900 (10 bytes) ---- */

void FUN_18000e900(longlong param_1)

{
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  return;
}

/* ---- FUNC 0000E910 FUN_18000e910 (78 bytes) ---- */

void FUN_18000e910(longlong param_1,longlong *param_2)

{
  (**(code **)(*param_2 + 8))(param_2);
  FUN_18002f6d0((longlong)param_2,1);
  CPtrArray::SetAtGrow((CPtrArray *)(param_1 + 0x218),*(__int64 *)(param_1 + 0x228),param_2);
  *(undefined4 *)(param_1 + 0x100) = 1;
  return;
}

/* ---- FUNC 0000E960 FUN_18000e960 (65 bytes) ---- */

void FUN_18000e960(longlong param_1,longlong *param_2)

{
  (**(code **)(*param_2 + 8))(param_2);
  CPtrArray::SetAtGrow((CPtrArray *)(param_1 + 0x1f0),*(__int64 *)(param_1 + 0x200),param_2);
  *(undefined4 *)(param_1 + 0x100) = 1;
  return;
}

/* ---- FUNC 0000E9B0 FUN_18000e9b0 (308 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined8 FUN_18000e9b0(longlong param_1,undefined4 param_2,LPCWSTR param_3,int param_4)

{
  undefined8 uVar1;
  longlong lVar2;
  ulonglong uVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined8 uStack_60;
  undefined1 auStack_58 [32];
  undefined8 uStack_38;
  int aiStack_30 [2];
  undefined8 local_28 [2];
  ulonglong local_18 [2];
  longlong lVar3;
  
  puVar7 = auStack_58;
  local_18[0] = DAT_180077818 ^ (ulonglong)local_18;
  if (DAT_1800797f8 != 0) {
    uStack_60 = 0x18000e9fa;
    uVar1 = (**(code **)(**(longlong **)(param_1 + 8) + 0x280))(*(longlong **)(param_1 + 8),0x7f3);
    puVar7 = auStack_58;
    goto LAB_18000eac2;
  }
  if (1 < param_4 - 1U) {
    uStack_60 = 0x18000ea1a;
    uVar1 = (**(code **)(**(longlong **)(param_1 + 8) + 0x280))(*(longlong **)(param_1 + 8),0x7d4);
    goto LAB_18000eac2;
  }
  puVar7 = auStack_58;
  if (param_3 == (LPCWSTR)0x0) {
LAB_18000eab0:
    puVar6 = (undefined1 *)0x0;
  }
  else {
    lVar2 = -1;
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_3[lVar2] != L'\0');
    iVar5 = (int)lVar3 + 2;
    puVar7 = auStack_58;
    if (0x3fffffff < iVar5) goto LAB_18000eab0;
    lVar2 = (longlong)(int)lVar2 * 2;
    uVar4 = lVar2 + 0x11;
    if (uVar4 <= lVar2 + 2U) {
      uVar4 = 0xffffffffffffff0;
    }
    uStack_60 = 0x18000ea6f;
    lVar2 = -(uVar4 & 0xfffffffffffffff0);
    puVar7 = auStack_58 + lVar2;
    puVar6 = (undefined1 *)((longlong)local_18 + lVar2);
    if (puVar6 == (undefined1 *)0x0) goto LAB_18000eab0;
    *puVar6 = 0;
    *(undefined8 *)((longlong)local_28 + lVar2 + 8) = 0;
    *(undefined8 *)((longlong)local_28 + lVar2) = 0;
    *(int *)((longlong)aiStack_30 + lVar2) = iVar5 * 2;
    *(undefined1 **)((longlong)&uStack_38 + lVar2) = puVar6;
    *(undefined8 *)(auStack_58 + lVar2 + -8) = 0x18000eaa5;
    iVar5 = WideCharToMultiByte(0,0,param_3,-1,*(LPSTR *)((longlong)&uStack_38 + lVar2),
                                *(int *)((longlong)aiStack_30 + lVar2),
                                *(LPCSTR *)((longlong)local_28 + lVar2),
                                *(LPBOOL *)((longlong)local_28 + lVar2 + 8));
    puVar7 = auStack_58 + lVar2;
    if (iVar5 == 0) {
      puVar6 = (undefined1 *)0x0;
      puVar7 = auStack_58 + lVar2;
    }
  }
  *(undefined8 *)(puVar7 + -8) = 0x18000eac0;
  Ordinal_80(param_2,puVar6,param_4);
  uVar1 = 0;
LAB_18000eac2:
  *(undefined8 *)(puVar7 + -8) = 0x18000eace;
  return uVar1;
}

/* ---- FUNC 0000EAF0 FUN_18000eaf0 (38 bytes) ---- */

undefined8 FUN_18000eaf0(longlong param_1)

{
  longlong *plVar1;
  
  plVar1 = *(longlong **)(param_1 + 0x2f0);
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x18))(plVar1,*(undefined4 *)(param_1 + 0x2d0));
  }
  return 0;
}

/* ---- FUNC 0000EB20 FUN_18000eb20 (330 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18000eb20(longlong param_1,SAFEARRAY *param_2,undefined8 *param_3)

{
  UINT UVar1;
  int iVar2;
  undefined1 auStack_448 [32];
  longlong *local_428;
  longlong *local_420;
  undefined1 local_418 [1008];
  ulonglong local_28;
  
  local_28 = DAT_180077818 ^ (ulonglong)auStack_448;
  FUN_18000fb50(param_1);
  if (param_2 == (SAFEARRAY *)0x0) {
    param_2 = SafeArrayCreateVector(8,0,0);
  }
  UVar1 = SafeArrayGetDim(param_2);
  if (UVar1 != 1) {
    FUN_180002a20(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\happ.cpp",0x1b77);
    LogMessage(local_418,2,1);
  }
  *(SAFEARRAY **)(param_1 + 0x18) = param_2;
  SafeArrayGetLBound(param_2,0,(LONG *)(param_1 + 0x20));
  SafeArrayGetUBound(param_2,0,(LONG *)(param_1 + 0x24));
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x24);
  if (param_3 != (undefined8 *)0x0) {
    local_420 = (longlong *)0x0;
    local_428 = (longlong *)0x0;
    iVar2 = (**(code **)*param_3)(param_3,&DAT_1800638b8,&local_420);
    if (-1 < iVar2) {
      iVar2 = (**(code **)(*local_420 + 0x20))(local_420,&DAT_180063510,&local_428);
      if (-1 < iVar2) {
        (**(code **)(*local_428 + 0x28))(local_428,param_1,param_1 + 0x2c);
      }
    }
    if (local_428 != (longlong *)0x0) {
      (**(code **)(*local_428 + 0x10))();
    }
    if (local_420 != (longlong *)0x0) {
      (**(code **)(*local_420 + 0x10))();
    }
  }
  *(undefined8 **)(param_1 + 0x10) = param_3;
  return;
}

/* ---- FUNC 0000EC70 FUN_18000ec70 (67 bytes) ---- */

undefined8 FUN_18000ec70(longlong *param_1)

{
  byte extraout_var;
  undefined8 uVar1;
  byte bVar2;
  undefined4 local_res10 [6];
  
  if (DAT_1800797f8 != 0) {
    uVar1 = (**(code **)(*param_1 + 0x280))(param_1,0x7f3);
    return uVar1;
  }
  if ((int)param_1[3] == 0) {
    uVar1 = (**(code **)(*param_1 + 0x280))(param_1,0x7d2);
    return uVar1;
  }
  if (param_1[4] != 0) {
    local_res10[0] = 1;
    SetGlobalPointer("InSave",local_res10,0);
    bVar2 = 0;
    if (DAT_180079800 != (longlong *)0x0) {
      (**(code **)(*DAT_180079800 + 0x50))();
      bVar2 = extraout_var >> 7 ^ 1;
    }
    SetGlobalPointer("InSave",local_res10,0);
    uVar1 = 0;
    if (bVar2 == 0) {
      uVar1 = 0x80004005;
    }
    return uVar1;
  }
  return 0x80004005;
}

/* ---- FUNC 0000ECB3 FUN_18000ecb3 (100 bytes) ---- */

undefined8 FUN_18000ecb3(void)

{
  byte extraout_var;
  undefined8 uVar1;
  byte bVar2;
  undefined4 uStack0000000000000038;
  
  uStack0000000000000038 = 1;
  SetGlobalPointer("InSave",&stack0x00000038);
  bVar2 = 0;
  if (DAT_180079800 != (longlong *)0x0) {
    (**(code **)(*DAT_180079800 + 0x50))();
    bVar2 = extraout_var >> 7 ^ 1;
  }
  SetGlobalPointer("InSave",&stack0x00000038,0);
  uVar1 = 0;
  if (bVar2 == 0) {
    uVar1 = 0x80004005;
  }
  return uVar1;
}

/* ---- FUNC 0000ED17 FUN_18000ed17 (10 bytes) ---- */

undefined8 FUN_18000ed17(void)

{
  return 0x80004005;
}

/* ---- FUNC 0000ED30 FUN_18000ed30 (92 bytes) ---- */

longlong * FUN_18000ed30(longlong *param_1)

{
  undefined8 *puVar1;
  longlong *plVar2;
  
  puVar1 = operator_new(0x168);
  if (puVar1 == (undefined8 *)0x0) {
    plVar2 = (longlong *)0x0;
  }
  else {
    plVar2 = FUN_180025480(puVar1);
  }
  (**(code **)(*plVar2 + 8))(plVar2);
  plVar2[1] = (longlong)param_1;
  (**(code **)(*param_1 + 8))(param_1);
  FUN_180026fe0((longlong)plVar2);
  return plVar2;
}

/* ---- FUNC 0000ED90 FUN_18000ed90 (13 bytes) ---- */

bool FUN_18000ed90(longlong param_1)

{
  return 0 < *(longlong *)(param_1 + 0x228);
}

/* ---- FUNC 0000EDA0 FUN_18000eda0 (16 bytes) ---- */

void FUN_18000eda0(longlong param_1)

{
  void *_Memory;
  ulonglong uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  if (*(longlong *)(param_1 + 0x18) != 0) {
    uVar1 = 0;
    uVar3 = uVar1;
    if (0 < *(int *)(param_1 + 0x20)) {
      do {
        _Memory = *(void **)(uVar3 + *(longlong *)(param_1 + 0x18));
        if (_Memory != (void *)0x0) {
          free(_Memory);
          *(undefined8 *)(uVar3 + *(longlong *)(param_1 + 0x18)) = 0;
        }
        uVar2 = (int)uVar1 + 1;
        uVar1 = (ulonglong)uVar2;
        uVar3 = uVar3 + 8;
      } while ((int)uVar2 < *(int *)(param_1 + 0x20));
    }
    free(*(void **)(param_1 + 0x18));
    *(undefined8 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  return;
}

/* ---- FUNC 0000EDB0 FUN_18000edb0 (19 bytes) ---- */

void FUN_18000edb0(longlong param_1)

{
  void *_Memory;
  longlong unaff_RBX;
  ulonglong uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar1 = 0;
  uVar3 = uVar1;
  if (0 < *(int *)(param_1 + 0x20)) {
    do {
      _Memory = *(void **)(uVar3 + *(longlong *)(unaff_RBX + 0x18));
      if (_Memory != (void *)0x0) {
        free(_Memory);
        *(undefined8 *)(uVar3 + *(longlong *)(unaff_RBX + 0x18)) = 0;
      }
      uVar2 = (int)uVar1 + 1;
      uVar1 = (ulonglong)uVar2;
      uVar3 = uVar3 + 8;
    } while ((int)uVar2 < *(int *)(unaff_RBX + 0x20));
  }
  free(*(void **)(unaff_RBX + 0x18));
  *(undefined8 *)(unaff_RBX + 0x18) = 0;
  *(undefined4 *)(unaff_RBX + 0x20) = 0;
  return;
}

/* ---- FUNC 0000EDC3 FUN_18000edc3 (56 bytes) ---- */

void FUN_18000edc3(void)

{
  void *_Memory;
  longlong unaff_RBX;
  ulonglong unaff_RBP;
  int unaff_ESI;
  ulonglong uVar1;
  
  uVar1 = unaff_RBP & 0xffffffff;
  do {
    _Memory = *(void **)(uVar1 + *(longlong *)(unaff_RBX + 0x18));
    if (_Memory != (void *)0x0) {
      free(_Memory);
      *(ulonglong *)(uVar1 + *(longlong *)(unaff_RBX + 0x18)) = unaff_RBP;
    }
    unaff_ESI = unaff_ESI + 1;
    uVar1 = uVar1 + 8;
  } while (unaff_ESI < *(int *)(unaff_RBX + 0x20));
  free(*(void **)(unaff_RBX + 0x18));
  *(ulonglong *)(unaff_RBX + 0x18) = unaff_RBP;
  *(int *)(unaff_RBX + 0x20) = (int)unaff_RBP;
  return;
}

/* ---- FUNC 0000EDFB FUN_18000edfb (27 bytes) ---- */

void FUN_18000edfb(void)

{
  longlong unaff_RBX;
  undefined8 unaff_RBP;
  
  free(*(void **)(unaff_RBX + 0x18));
  *(undefined8 *)(unaff_RBX + 0x18) = unaff_RBP;
  *(int *)(unaff_RBX + 0x20) = (int)unaff_RBP;
  return;
}

/* ---- FUNC 0000EE16 FUN_18000ee16 (6 bytes) ---- */

void FUN_18000ee16(void)

{
  return;
}

/* ---- FUNC 0000EE20 FUN_18000ee20 (113 bytes) ---- */

void FUN_18000ee20(longlong param_1)

{
  void *pvVar1;
  
  if (param_1 != 0) {
    if (*(longlong **)(param_1 + 0x18) != (longlong *)0x0) {
      (**(code **)(**(longlong **)(param_1 + 0x18) + 0x10))();
    }
    *(undefined8 *)(param_1 + 0x18) = 0;
    pvVar1 = *(void **)(param_1 + 0x28);
    if (pvVar1 != (void *)0x0) {
      _eh_vector_destructor_iterator_
                (pvVar1,0x10,*(__uint64 *)((longlong)pvVar1 + -8),
                 (_func_void_void_ptr *)&LAB_18000b020);
      operator_delete__((__uint64 *)((longlong)pvVar1 + -8));
    }
    *(undefined8 *)(param_1 + 0x28) = 0;
  }
  return;
}

/* ---- FUNC 0000EEA0 FUN_18000eea0 (48 bytes) ---- */

undefined8 FUN_18000eea0(longlong param_1)

{
  undefined8 uVar1;
  
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018000eebd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(**(longlong **)(param_1 + 8) + 0x280))(*(longlong **)(param_1 + 8),0x7f3);
    return uVar1;
  }
  Ordinal_77();
  return 0;
}

/* ---- FUNC 0000EED0 FUN_18000eed0 (87 bytes) ---- */

undefined8 * FUN_18000eed0(longlong param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar1 = operator_new(0x20);
  puVar2 = (undefined8 *)0x0;
  if (puVar1 != (undefined8 *)0x0) {
    puVar2 = FUN_18000acd0(puVar1,param_1);
  }
  *param_2 = puVar2;
  puVar1 = (undefined8 *)0x8007000e;
  if (puVar2 != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)0x0;
  }
  return puVar1;
}

/* ---- FUNC 0000EF30 FUN_18000ef30 (519 bytes) ---- */

undefined8 FUN_18000ef30(longlong *param_1,int param_2)

{
  int iVar1;
  HRESULT HVar2;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar3;
  longlong *plVar4;
  LPCSTR pCVar5;
  undefined8 uVar6;
  IRunningObjectTable *local_res8;
  
  if ((param_1[4] != 0) && ((int)param_1[0x1a] == 0)) {
    *(undefined4 *)partial_results_exref = 0;
    if (param_2 == 2) {
      pCVar3 = FUN_180020fe0((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_res8,0x10);
      iVar1 = MMAfxMessageBox(*(char **)pCVar3,3,-1,0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
      if (iVar1 == 2) {
        return 0x8004000c;
      }
    }
    *(undefined4 *)(param_1 + 0x1a) = 1;
    (**(code **)(*param_1 + 8))();
    if (((int)param_1[0x22] != 0) || (*(int *)((longlong)param_1 + 0x114) != 0)) {
      HVar2 = GetRunningObjectTable(0,&local_res8);
      if (-1 < HVar2) {
        if (*(DWORD *)(param_1 + 0x22) != 0) {
          (*local_res8->lpVtbl->Revoke)(local_res8,*(DWORD *)(param_1 + 0x22));
          *(undefined4 *)(param_1 + 0x22) = 0;
        }
        if (*(DWORD *)((longlong)param_1 + 0x114) != 0) {
          (*local_res8->lpVtbl->Revoke)(local_res8,*(DWORD *)((longlong)param_1 + 0x114));
          *(undefined4 *)((longlong)param_1 + 0x114) = 0;
        }
        (*local_res8->lpVtbl->Release)(local_res8);
      }
    }
    FUN_18000f1a0((longlong)param_1);
    HAReleasePointers();
    if ((longlong *)param_1[0x30] != (longlong *)0x0) {
      (**(code **)(*(longlong *)param_1[0x30] + 0x40))();
    }
    plVar4 = (longlong *)GetGlobalPointer("ApwnDocStorage");
    if (plVar4 != (longlong *)0x0) {
      (**(code **)(*plVar4 + 8))(plVar4);
    }
    (**(code **)(*DAT_180079800 + 0x58))();
    Ordinal_42();
    iVar1 = GRinqsme();
    if (iVar1 == 0) {
      iVar1 = MVGetProductCode();
      if (iVar1 == 1) {
        pCVar5 = (LPCSTR)GRemrbkp();
        DeleteFileA(pCVar5);
        DeleteFileA("$backup.bkp");
        uVar6 = GRemrbkpfull();
        GRDeleteEmergencyFiles(0,uVar6);
        GRAuxFileOnQuit(0);
      }
      else {
        pCVar5 = (LPCSTR)GRemrprp();
        DeleteFileA(pCVar5);
        DeleteFileA("$backup.aprbkp");
      }
      pCVar5 = (LPCSTR)GRemrbka();
      DeleteFileA(pCVar5);
      DeleteFileA("$backup.apmbd");
    }
    FUN_18000f300((longlong)param_1);
    if (plVar4 != (longlong *)0x0) {
      (**(code **)(*plVar4 + 0x10))(plVar4);
    }
    (**(code **)(*DAT_180079800 + 0x60))();
    *(undefined4 *)(param_1 + 0x1a) = 0;
  }
  return 1;
}

/* ---- FUNC 0000F140 FUN_18000f140 (42 bytes) ---- */

void FUN_18000f140(longlong *param_1,undefined4 *param_2)

{
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined8 local_18;
  
  local_28 = *param_2;
  uStack_24 = param_2[1];
  uStack_20 = param_2[2];
  uStack_1c = param_2[3];
  local_18 = *(undefined8 *)(param_2 + 4);
  (**(code **)(*param_1 + 0x250))(local_28,&local_28);
  return;
}

/* ---- FUNC 0000F170 FUN_18000f170 (35 bytes) ---- */

undefined8 FUN_18000f170(longlong *param_1)

{
  FUN_1800230b0();
  FUN_18000ef30(param_1,1);
  return 0;
}

/* ---- FUNC 0000F1A0 FUN_18000f1a0 (336 bytes) ---- */

void FUN_18000f1a0(longlong param_1)

{
  ulonglong uVar1;
  longlong *plVar2;
  __POSITION *p_Var3;
  ulonglong uVar4;
  ulonglong uVar5;
  __POSITION *local_res8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res10 [8];
  longlong *local_res18 [2];
  
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10);
  local_res8 = (__POSITION *)-(ulonglong)(*(__POSITION **)(param_1 + 0x1d0) != (__POSITION *)0x0);
  p_Var3 = *(__POSITION **)(param_1 + 0x1d0);
  while (p_Var3 != (__POSITION *)0x0) {
    CMapStringToPtr::GetNextAssoc
              ((CMapStringToPtr *)(param_1 + 0x1b8),&local_res8,local_res10,local_res18);
    plVar2 = local_res18[0];
    FUN_180027540(local_res18[0]);
    (**(code **)(*plVar2 + 0x10))(plVar2);
    p_Var3 = local_res8;
  }
  CMapStringToPtr::RemoveAll((CMapStringToPtr *)(param_1 + 0x1b8));
  uVar4 = 0;
  uVar1 = *(ulonglong *)(param_1 + 0x200);
  uVar5 = uVar4;
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar5 < 0) || (*(longlong *)(param_1 + 0x200) <= (longlong)uVar5))
      goto LAB_18000f2eb;
      plVar2 = *(longlong **)(*(longlong *)(param_1 + 0x1f8) + uVar5 * 8);
      FUN_1800275b0((longlong)plVar2);
      (**(code **)(*plVar2 + 0x10))(plVar2);
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
  }
  CPtrArray::SetSize((CPtrArray *)(param_1 + 0x1f0),0,-1);
  uVar1 = *(ulonglong *)(param_1 + 0x228);
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar4 < 0) || (*(longlong *)(param_1 + 0x228) <= (longlong)uVar4)) {
LAB_18000f2eb:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar2 = *(longlong **)(*(longlong *)(param_1 + 0x220) + uVar4 * 8);
      FUN_180027550((longlong)plVar2);
      (**(code **)(*plVar2 + 0x10))(plVar2);
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  CPtrArray::SetSize((CPtrArray *)(param_1 + 0x218),0,-1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10);
  return;
}

/* ---- FUNC 0000F300 FUN_18000f300 (398 bytes) ---- */

void FUN_18000f300(longlong param_1)

{
  int iVar1;
  HMODULE hModule;
  FARPROC pFVar2;
  char *pcVar3;
  undefined8 *puVar4;
  
  hModule = LoadLibraryExA("fimmtop.dll",(HANDLE)0x0,0);
  if (hModule != (HMODULE)0x0) {
    pFVar2 = GetProcAddress(hModule,"CxsClearNodeCaches_C");
    if (pFVar2 != (FARPROC)0x0) {
      (*pFVar2)();
    }
  }
  if (*(longlong *)(param_1 + 0x20) != 0) {
    if (*(longlong *)(param_1 + 0x108) == 0) {
      puVar4 = (undefined8 *)HACloseFile();
      if ((puVar4 != (undefined8 *)0x0) && ((code *)*puVar4 != (code *)0x0)) {
        (*(code *)*puVar4)(puVar4);
      }
    }
    else {
      pcVar3 = operator_new(800);
      if (pcVar3 == (char *)0x0) {
        pcVar3 = (char *)0x0;
      }
      else {
        pcVar3 = FUN_180024da0(pcVar3,*(char **)(param_1 + 0x108));
      }
      FUN_180025150((longlong)pcVar3);
      puVar4 = (undefined8 *)HACloseFile(*(undefined8 *)(param_1 + 0x20));
      if ((puVar4 != (undefined8 *)0x0) && ((code *)*puVar4 != (code *)0x0)) {
        (*(code *)*puVar4)(puVar4);
      }
      FUN_180025110((longlong)pcVar3);
      if (pcVar3 != (char *)0x0) {
        _guard_check_icall();
        FUN_180025ad0(pcVar3);
      }
    }
  }
  iVar1 = GRinqsme();
  if (iVar1 == 0) {
    iVar1 = MVGetProductCode();
    if (iVar1 == 1) {
      DeleteFileA("$backup.bk$");
      pcVar3 = "$backup.bkp";
    }
    else {
      DeleteFileA("$backup.aprbk$");
      pcVar3 = "$backup.aprbkp";
    }
    DeleteFileA(pcVar3);
    DeleteFileA("$backup.ap$");
    DeleteFileA("$backup.apmbd");
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  SetGlobalPointer("FileNode",0,0);
  *(undefined8 *)(param_1 + 0x20) = 0;
  SetGlobalPointer("HappNode",0,0);
  puVar4 = (undefined8 *)HAExit();
  if ((puVar4 != (undefined8 *)0x0) && ((code *)*puVar4 != (code *)0x0)) {
    (*(code *)*puVar4)(puVar4);
  }
  return;
}

/* ---- FUNC 0000F490 FUN_18000f490 (38 bytes) ---- */

void FUN_18000f490(longlong param_1)

{
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018000f4a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(longlong **)(param_1 + 8) + 0x280))(*(longlong **)(param_1 + 8),0x7f3);
    return;
  }
  Ordinal_40(0xc);
  return;
}

/* ---- FUNC 0000F4C0 FUN_18000f4c0 (218 bytes) ---- */

HRESULT FUN_18000f4c0(undefined8 *param_1,undefined8 param_2)

{
  HRESULT HVar1;
  undefined8 *puVar2;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar3;
  undefined8 *local_res18;
  
  local_res18 = operator_new(0x360);
  if (local_res18 == (undefined8 *)0x0) {
    puVar2 = (undefined8 *)0x0;
  }
  else {
    puVar2 = FUN_18000a9b0(local_res18);
  }
  HVar1 = FUN_180033ad0(puVar2 + 1,(GUID *)&DAT_180063460);
  if (HVar1 < 0) {
    pCVar3 = FUN_180020fe0((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_res18,3);
    MMAfxMessageBox(*(char **)pCVar3,0,-1,0);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18);
    if (puVar2 != (undefined8 *)0x0) {
      FUN_18000b0b0(puVar2);
      FUN_180025ad0(puVar2);
    }
  }
  else {
    puVar2[5] = param_2;
    *(undefined4 *)(puVar2 + 0x24) = 0;
    *param_1 = puVar2;
    SetGlobalPointer("HappNode",puVar2,0);
    HVar1 = 0;
  }
  return HVar1;
}

/* ---- FUNC 0000F5A0 FUN_18000f5a0 (207 bytes) ---- */

longlong * FUN_18000f5a0(undefined8 *param_1)

{
  longlong *plVar1;
  ulonglong uVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong *plVar5;
  
  if (param_1 != (undefined8 *)0x0) {
    plVar5 = (longlong *)0x0;
    *param_1 = 0;
    plVar4 = (longlong *)0x8007000e;
    plVar1 = operator_new(0x28);
    plVar3 = plVar5;
    if (plVar1 != (longlong *)0x0) {
      *(undefined4 *)(plVar1 + 3) = 0;
      *(undefined4 *)(plVar1 + 1) = 0;
      plVar1[4] = 0;
      *plVar1 = (longlong)ATL::CComObject<CHNodeSelection>::vftable;
      plVar1[2] = (longlong)ATL::CComObject<CHNodeSelection>::vftable;
      (**(code **)(*DAT_180079320 + 8))();
      plVar3 = plVar1;
    }
    if (plVar3 != (longlong *)0x0) {
      uVar2 = FUN_18002e4b0();
      plVar4 = plVar5;
      if ((int)uVar2 < 0) {
        plVar4 = (longlong *)(uVar2 & 0xffffffff);
      }
      if ((int)plVar4 != 0) {
        (**(code **)(*plVar3 + 0x28))(plVar3,1);
        plVar3 = plVar5;
      }
    }
    *param_1 = plVar3;
    return plVar4;
  }
  return (longlong *)0x80004003;
}

/* ---- FUNC 0000F670 FUN_18000f670 (208 bytes) ---- */

ulonglong FUN_18000f670(undefined8 *param_1)

{
  longlong *plVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  if (param_1 != (undefined8 *)0x0) {
    *param_1 = 0;
    uVar3 = 0x8007000e;
    plVar1 = operator_new(0x28);
    if (plVar1 != (longlong *)0x0) {
      *(undefined4 *)(plVar1 + 3) = 0;
      *(undefined4 *)(plVar1 + 1) = 0;
      *plVar1 = (longlong)ATL::CComObject<CHappConnectInfo>::vftable;
      plVar1[2] = (longlong)ATL::CComObject<CHappConnectInfo>::vftable;
      (**(code **)(*DAT_180079320 + 8))();
      uVar2 = FUN_18002e4b0();
      uVar3 = 0;
      if ((int)uVar2 < 0) {
        uVar3 = uVar2 & 0xffffffff;
      }
      if ((int)uVar3 != 0) {
        (**(code **)(*plVar1 + 0x28))(plVar1,1);
        plVar1 = (longlong *)0x0;
      }
    }
    *param_1 = plVar1;
    return uVar3;
  }
  return 0x80004003;
}

/* ---- FUNC 0000F740 FUN_18000f740 (822 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

int FUN_18000f740(IUnknownVtbl *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                 short param_5,undefined8 *param_6)

{
  char *pcVar1;
  char cVar2;
  code *pcVar3;
  LPCWSTR pWVar4;
  int iVar5;
  _func_5156 *p_Var6;
  longlong lVar7;
  longlong lVar8;
  IUnknownVtbl *pIVar9;
  ulonglong uVar10;
  char *pcVar11;
  char *pcVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined8 uStack_f0;
  undefined1 auStack_e8 [32];
  undefined8 uStack_c8;
  int aiStack_c0 [2];
  undefined8 local_b8 [2];
  longlong local_a8;
  undefined8 local_a0;
  char local_98 [24];
  char local_80 [24];
  char local_68 [24];
  ulonglong local_50;
  
  puVar14 = auStack_e8;
  local_50 = DAT_180077818 ^ (ulonglong)&local_a8;
  if (DAT_1800797f8 == 0) {
    pcVar11 = (char *)0x0;
    local_a8 = 0;
    if (*(int *)&param_1[1].QueryInterface == 0) {
      uStack_f0 = 0x18000f7b4;
      iVar5 = (**(code **)(param_1->QueryInterface + 0x280))(param_1,0x7d2);
    }
    else {
      if (param_1[1].AddRef == (_func_5157 *)0x0) {
        p_Var6 = param_1->QueryInterface;
        puVar14 = auStack_e8;
      }
      else {
        pWVar4 = (LPCWSTR)*param_2;
        puVar14 = auStack_e8;
        pcVar12 = pcVar11;
        if (pWVar4 != (LPCWSTR)0x0) {
          lVar7 = -1;
          do {
            lVar8 = lVar7;
            lVar7 = lVar8 + 1;
          } while (pWVar4[lVar7] != L'\0');
          iVar5 = (int)lVar8 + 2;
          puVar14 = auStack_e8;
          if (iVar5 < 0x40000000) {
            lVar7 = (longlong)(int)lVar7 * 2;
            uVar10 = lVar7 + 0x11;
            if (uVar10 <= lVar7 + 2U) {
              uVar10 = 0xffffffffffffff0;
            }
            uStack_f0 = 0x18000f827;
            lVar7 = -(uVar10 & 0xfffffffffffffff0);
            pcVar1 = (char *)((longlong)&local_a8 + lVar7);
            puVar14 = auStack_e8 + lVar7;
            if (pcVar1 != (char *)0x0) {
              *(undefined8 *)((longlong)local_b8 + lVar7 + 8) = 0;
              *(undefined8 *)((longlong)local_b8 + lVar7) = 0;
              *(int *)((longlong)aiStack_c0 + lVar7) = iVar5 * 2;
              *pcVar1 = '\0';
              *(char **)((longlong)&uStack_c8 + lVar7) = pcVar1;
              *(undefined8 *)(auStack_e8 + lVar7 + -8) = 0x18000f85a;
              iVar5 = WideCharToMultiByte(0,0,pWVar4,-1,*(LPSTR *)((longlong)&uStack_c8 + lVar7),
                                          *(int *)((longlong)aiStack_c0 + lVar7),
                                          *(LPCSTR *)((longlong)local_b8 + lVar7),
                                          *(LPBOOL *)((longlong)local_b8 + lVar7 + 8));
              puVar14 = auStack_e8 + lVar7;
              pcVar12 = pcVar1;
              if (iVar5 == 0) {
                puVar14 = auStack_e8 + lVar7;
                pcVar12 = pcVar11;
              }
            }
          }
        }
        lVar7 = -(longlong)pcVar12;
        do {
          cVar2 = *pcVar12;
          pcVar12[(longlong)(local_68 + lVar7)] = cVar2;
          pcVar12 = pcVar12 + 1;
        } while (cVar2 != '\0');
        pWVar4 = (LPCWSTR)*param_3;
        puVar13 = puVar14;
        pcVar12 = pcVar11;
        if (pWVar4 != (LPCWSTR)0x0) {
          lVar7 = -1;
          do {
            lVar8 = lVar7;
            lVar7 = lVar8 + 1;
          } while (pWVar4[lVar7] != L'\0');
          iVar5 = (int)lVar8 + 2;
          if (iVar5 < 0x40000000) {
            lVar7 = (longlong)(int)lVar7 * 2;
            uVar10 = lVar7 + 0x11;
            if (uVar10 <= lVar7 + 2U) {
              uVar10 = 0xffffffffffffff0;
            }
            *(undefined8 *)(puVar14 + -8) = 0x18000f8d7;
            lVar7 = -(uVar10 & 0xfffffffffffffff0);
            pcVar1 = puVar14 + lVar7 + 0x40;
            puVar13 = puVar14 + lVar7;
            if (pcVar1 != (char *)0x0) {
              *(undefined8 *)(puVar14 + lVar7 + 0x38) = 0;
              *(undefined8 *)(puVar14 + lVar7 + 0x30) = 0;
              *(int *)(puVar14 + lVar7 + 0x28) = iVar5 * 2;
              *pcVar1 = '\0';
              *(char **)(puVar14 + lVar7 + 0x20) = pcVar1;
              *(undefined8 *)(puVar14 + lVar7 + -8) = 0x18000f90a;
              iVar5 = WideCharToMultiByte(0,0,pWVar4,-1,*(LPSTR *)(puVar14 + lVar7 + 0x20),
                                          *(int *)(puVar14 + lVar7 + 0x28),
                                          *(LPCSTR *)(puVar14 + lVar7 + 0x30),
                                          *(LPBOOL *)(puVar14 + lVar7 + 0x38));
              puVar13 = puVar14 + lVar7;
              pcVar12 = pcVar1;
              if (iVar5 == 0) {
                puVar13 = puVar14 + lVar7;
                pcVar12 = pcVar11;
              }
            }
          }
        }
        lVar7 = -(longlong)pcVar12;
        do {
          cVar2 = *pcVar12;
          pcVar12[(longlong)(local_80 + lVar7)] = cVar2;
          pcVar12 = pcVar12 + 1;
        } while (cVar2 != '\0');
        puVar14 = puVar13;
        if (param_5 == 2) {
          pWVar4 = (LPCWSTR)*param_4;
          pcVar12 = pcVar11;
          if (pWVar4 != (LPCWSTR)0x0) {
            lVar7 = -1;
            do {
              lVar8 = lVar7;
              lVar7 = lVar8 + 1;
            } while (pWVar4[lVar7] != L'\0');
            iVar5 = (int)lVar8 + 2;
            if (iVar5 < 0x40000000) {
              lVar7 = (longlong)(int)lVar7 * 2;
              uVar10 = lVar7 + 0x11;
              if (uVar10 <= lVar7 + 2U) {
                uVar10 = 0xffffffffffffff0;
              }
              *(undefined8 *)(puVar13 + -8) = 0x18000f98e;
              lVar7 = -(uVar10 & 0xfffffffffffffff0);
              pcVar1 = puVar13 + lVar7 + 0x40;
              puVar14 = puVar13 + lVar7;
              if (pcVar1 != (char *)0x0) {
                *(undefined8 *)(puVar13 + lVar7 + 0x38) = 0;
                *(undefined8 *)(puVar13 + lVar7 + 0x30) = 0;
                *(int *)(puVar13 + lVar7 + 0x28) = iVar5 * 2;
                *pcVar1 = '\0';
                *(char **)(puVar13 + lVar7 + 0x20) = pcVar1;
                *(undefined8 *)(puVar13 + lVar7 + -8) = 0x18000f9c1;
                iVar5 = WideCharToMultiByte(0,0,pWVar4,-1,*(LPSTR *)(puVar13 + lVar7 + 0x20),
                                            *(int *)(puVar13 + lVar7 + 0x28),
                                            *(LPCSTR *)(puVar13 + lVar7 + 0x30),
                                            *(LPBOOL *)(puVar13 + lVar7 + 0x38));
                pcVar12 = pcVar1;
                puVar14 = puVar13 + lVar7;
                if (iVar5 == 0) {
                  pcVar12 = pcVar11;
                  puVar14 = puVar13 + lVar7;
                }
              }
            }
          }
          lVar7 = -(longlong)pcVar12;
          do {
            cVar2 = *pcVar12;
            pcVar12[(longlong)(local_98 + lVar7)] = cVar2;
            pcVar12 = pcVar12 + 1;
          } while (cVar2 != '\0');
        }
        else {
          local_98[0] = '\0';
        }
        *(longlong **)(puVar14 + 0x20) = &local_a8;
        *(undefined8 *)(puVar14 + -8) = 0x18000fa03;
        pIVar9 = (IUnknownVtbl *)HACreateRouteTree(local_68,local_80,local_98,param_5);
        if (pIVar9 != (IUnknownVtbl *)0x0) {
          *(undefined8 **)(puVar14 + 0x28) = &local_a0;
          *(_func_5158 **)(puVar14 + 0x20) = param_1[1].Release;
          *(undefined8 *)(puVar14 + -8) = 0x18000fa49;
          iVar5 = FUN_1800389d0(pIVar9,param_1,param_1,1,*(IUnknownVtbl **)(puVar14 + 0x20),
                                *(undefined8 **)(puVar14 + 0x28));
          if (-1 < iVar5) {
            *param_6 = local_a0;
          }
          goto LAB_18000fa59;
        }
        p_Var6 = param_1->QueryInterface;
        if (local_a8 != 0) {
          pcVar3 = *(code **)(p_Var6 + 0x278);
          *(undefined8 *)(puVar14 + -8) = 0x18000fa24;
          iVar5 = (*pcVar3)(param_1);
          goto LAB_18000fa59;
        }
      }
      pcVar3 = *(code **)(p_Var6 + 0x280);
      *(undefined8 *)(puVar14 + -8) = 0x18000f7cd;
      iVar5 = (*pcVar3)(param_1,0x7d1);
    }
  }
  else {
    uStack_f0 = 0x18000f796;
    iVar5 = (**(code **)(param_1->QueryInterface + 0x280))(param_1,0x7f3);
    puVar14 = auStack_e8;
  }
LAB_18000fa59:
  *(undefined8 *)(puVar14 + -8) = 0x18000fa65;
  return iVar5;
}

/* ---- FUNC 0000FA80 FUN_18000fa80 (133 bytes) ---- */

undefined8 FUN_18000fa80(longlong *param_1,wchar_t *param_2)

{
  int iVar1;
  undefined8 uVar2;
  char *local_res18;
  longlong *local_res20;
  
  if (DAT_1800797f8 != 0) {
    uVar2 = (**(code **)(*param_1 + 0x280))(param_1,0x7f3);
    return uVar2;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18,param_2);
  iVar1 = CMapStringToPtr::Lookup((CMapStringToPtr *)(param_1 + 0x37),local_res18,&local_res20);
  if (iVar1 != 0) {
    CMapStringToPtr::RemoveKey((CMapStringToPtr *)(param_1 + 0x37),local_res18);
    FUN_180027540(local_res20);
    (**(code **)(*local_res20 + 0x10))(local_res20);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18);
  return 0;
}

/* ---- FUNC 0000FB10 FUN_18000fb10 (50 bytes) ---- */

undefined8 FUN_18000fb10(longlong param_1,undefined4 param_2)

{
  undefined8 uVar1;
  
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018000fb2d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(**(longlong **)(param_1 + 8) + 0x280))(*(longlong **)(param_1 + 8),0x7f3);
    return uVar1;
  }
  Ordinal_81(param_2);
  return 0;
}

/* ---- FUNC 0000FB50 FUN_18000fb50 (253 bytes) ---- */

undefined8 FUN_18000fb50(longlong param_1)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  int iVar4;
  SAFEARRAYBOUND local_res8;
  longlong *local_res10;
  
  iVar1 = *(int *)(param_1 + 0x2c);
  if ((iVar1 != -0x55555556) &&
     (puVar2 = *(undefined8 **)(param_1 + 0x10), puVar2 != (undefined8 *)0x0)) {
    local_res10 = (longlong *)0x0;
    local_res8.cElements = 0;
    local_res8.lLbound = 0;
    iVar4 = (**(code **)*puVar2)(puVar2,&DAT_1800638b8,&local_res10);
    if (-1 < iVar4) {
      iVar4 = (**(code **)(*local_res10 + 0x20))(local_res10,&DAT_180063510,&local_res8);
      if (-1 < iVar4) {
        (**(code **)(*(longlong *)local_res8 + 0x30))(local_res8,iVar1);
      }
    }
    if (local_res8 != (SAFEARRAYBOUND)0x0) {
      (**(code **)(*(longlong *)local_res8 + 0x10))();
    }
    if (local_res10 != (longlong *)0x0) {
      (**(code **)(*local_res10 + 0x10))();
    }
    *(undefined8 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0xaaaaaaaa;
  }
  if (*(SAFEARRAY **)(param_1 + 0x18) != (SAFEARRAY *)0x0) {
    if (*(int *)(param_1 + 0x24) != *(int *)(param_1 + 0x28)) {
      local_res8.lLbound = *(int *)(param_1 + 0x20);
      local_res8.cElements = (*(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20)) + 1;
      SafeArrayRedim(*(SAFEARRAY **)(param_1 + 0x18),&local_res8);
      *(ULONG *)(param_1 + 0x28) = *(int *)(param_1 + 0x20) + (local_res8.cElements - 1);
    }
    uVar3 = *(undefined8 *)(param_1 + 0x18);
    *(undefined8 *)(param_1 + 0x18) = 0;
    return uVar3;
  }
  return 0;
}

/* ---- FUNC 0000FC50 FUN_18000fc50 (8 bytes) ---- */

void FUN_18000fc50(undefined8 param_1,undefined8 param_2)

{
  FUN_1800373c0(param_2);
  return;
}

/* ---- FUNC 0000FC60 FUN_18000fc60 (637 bytes) ---- */

void FUN_18000fc60(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong *plVar4;
  int iVar5;
  longlong *plVar6;
  uint uVar7;
  longlong *plVar8;
  undefined8 *local_res10;
  longlong *local_res18;
  BSTR local_res20;
  CStringArray local_d8 [8];
  longlong local_d0;
  longlong *local_c8;
  CStringArray local_b0 [16];
  __int64 local_a0;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  CStringArray *local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  longlong *local_48;
  
  if (DAT_1800797f8 == 0) {
    local_res10 = operator_new(0x30);
    plVar4 = (longlong *)0x0;
    plVar1 = plVar4;
    if (local_res10 != (undefined8 *)0x0) {
      plVar1 = FUN_18005a5f0(local_res10,param_1 + 0x218);
    }
    local_res18 = plVar1;
    (**(code **)(*plVar1 + 8))(plVar1);
    FUN_18005af40((longlong)plVar1);
    local_88 = 0x48;
    local_78 = 0;
    uStack_70 = 0;
    local_68 = (CStringArray *)0x0;
    uStack_60 = 0;
    local_58 = 0;
    uStack_50 = 0;
    local_80 = DAT_1800797e0;
    local_48 = plVar1;
    CStringArray::CStringArray(local_b0);
    plVar6 = plVar4;
    plVar8 = plVar4;
    if (0 < *(longlong *)(param_1 + 0x228)) {
      do {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10,"")
        ;
        CStringArray::CStringArray(local_d8);
        if (((longlong)plVar8 < 0) || (*(longlong *)(param_1 + 0x228) <= (longlong)plVar8)) {
LAB_18000fed2:
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x220) + (longlong)plVar8 * 8);
        if (lVar2 != 0) {
          FUN_180029f30(lVar2,local_d8);
        }
        plVar1 = local_c8;
        plVar3 = plVar4;
        if (local_c8 != (longlong *)0x0) {
          do {
            if (((longlong)plVar3 < 0) || ((longlong)local_c8 <= (longlong)plVar3))
            goto LAB_18000fed2;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10
                       ,(CSimpleStringT<char,1> *)(local_d0 + (longlong)plVar3 * 8));
            plVar3 = (longlong *)((longlong)plVar3 + 1);
          } while (plVar3 < plVar1);
        }
        CStringArray::SetAtGrow
                  (local_b0,local_a0,
                   (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10);
        CStringArray::~CStringArray(local_d8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10);
        uVar7 = (int)plVar6 + 1;
        plVar6 = (longlong *)(ulonglong)uVar7;
        plVar1 = local_res18;
        plVar8 = (longlong *)((longlong)plVar8 + 1);
      } while ((longlong)(int)uVar7 < *(longlong *)(param_1 + 0x228));
    }
    local_68 = local_b0;
    local_res20 = SysAllocString(L"EditLinksDialog");
    (**(code **)(*DAT_180079800 + 0xb0))(DAT_180079800,&local_88,&local_res20);
    SysFreeString(local_res20);
    lVar2 = *(longlong *)(param_1 + 0x228);
    plVar6 = plVar4;
    if (0 < lVar2) {
      do {
        iVar5 = (int)plVar6;
        if (((longlong)plVar4 < 0) || (lVar2 <= (longlong)plVar4)) {
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        plVar6 = *(longlong **)(*(longlong *)(param_1 + 0x220) + (longlong)plVar4 * 8);
        if ((int)plVar6[1] == 1) {
          FUN_18002f6d0((longlong)plVar6,0);
          (**(code **)(*plVar6 + 0x10))(plVar6);
          CPtrArray::RemoveAt((CPtrArray *)(param_1 + 0x218),(longlong)iVar5,1);
          iVar5 = iVar5 + -1;
          plVar4 = (longlong *)((longlong)plVar4 + -1);
        }
        plVar4 = (longlong *)((longlong)plVar4 + 1);
        lVar2 = *(longlong *)(param_1 + 0x228);
        plVar6 = (longlong *)(ulonglong)(iVar5 + 1U);
      } while ((int)(iVar5 + 1U) < lVar2);
    }
    (**(code **)(*plVar1 + 0x10))(plVar1);
    CStringArray::~CStringArray(local_b0);
  }
  return;
}

/* ---- FUNC 0000FEE0 FUN_18000fee0 (77 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18000fee0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  longlong lVar2;
  DWORD nSize;
  ulonglong uVar3;
  LPCSTR lpValue;
  longlong lVar4;
  LPCSTR pCVar6;
  char *pcVar7;
  longlong lVar8;
  undefined1 auStack_138 [32];
  char local_118 [256];
  ulonglong local_18;
  longlong lVar5;
  
  local_18 = DAT_180077818 ^ (ulonglong)auStack_138;
  if (DAT_180079444 == '\0') {
    local_118[0] = '\0';
    uVar3 = FUN_1800118e0(local_118,0xfc,param_3,param_4);
    if (((int)uVar3 != 0) && (local_118[0] != '\0')) {
      nSize = GetEnvironmentVariableA("path",(LPSTR)0x0,0);
      lVar8 = -1;
      lVar5 = -1;
      do {
        lVar4 = lVar5 + 1;
        lVar2 = lVar5 + 1;
        lVar5 = lVar4;
      } while (local_118[lVar2] != '\0');
      lpValue = malloc(lVar4 + (longlong)(int)nSize + 2);
      if (lpValue != (LPCSTR)0x0) {
        pcVar7 = local_118;
        do {
          cVar1 = *pcVar7;
          pcVar7[(longlong)lpValue - (longlong)local_118] = cVar1;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        pCVar6 = lpValue + -1;
        do {
          pcVar7 = pCVar6 + 1;
          pCVar6 = pCVar6 + 1;
        } while (*pcVar7 != '\0');
        *(undefined2 *)pCVar6 = DAT_180064150;
        do {
          lVar5 = lVar8 + 1;
          lVar8 = lVar8 + 1;
        } while (lpValue[lVar5] != '\0');
        GetEnvironmentVariableA("path",lpValue + lVar8,nSize);
        SetEnvironmentVariableA("path",lpValue);
        DAT_180079444 = '\x01';
        free(lpValue);
      }
    }
  }
  return;
}

/* ---- FUNC 0000FF2D FUN_18000ff2d (250 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18000ff2d(void)

{
  char cVar1;
  longlong lVar2;
  DWORD nSize;
  LPCSTR lpValue;
  longlong lVar3;
  LPCSTR pCVar5;
  char *pcVar6;
  longlong lVar7;
  char acStackX_20 [8];
  longlong lVar4;
  
  nSize = GetEnvironmentVariableA("path",(LPSTR)0x0,0);
  lVar7 = -1;
  lVar4 = -1;
  do {
    lVar3 = lVar4 + 1;
    lVar2 = lVar4 + 1;
    lVar4 = lVar3;
  } while (acStackX_20[lVar2] != '\0');
  lpValue = malloc(lVar3 + (longlong)(int)nSize + 2);
  if (lpValue != (LPCSTR)0x0) {
    pcVar6 = acStackX_20;
    do {
      cVar1 = *pcVar6;
      pcVar6[(longlong)lpValue - (longlong)acStackX_20] = cVar1;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    pCVar5 = lpValue + -1;
    do {
      pcVar6 = pCVar5 + 1;
      pCVar5 = pCVar5 + 1;
    } while (*pcVar6 != '\0');
    *(undefined2 *)pCVar5 = DAT_180064150;
    do {
      lVar4 = lVar7 + 1;
      lVar7 = lVar7 + 1;
    } while (lpValue[lVar4] != '\0');
    GetEnvironmentVariableA("path",lpValue + lVar7,nSize);
    SetEnvironmentVariableA("path",lpValue);
    DAT_180079444 = 1;
    free(lpValue);
  }
  return;
}

/* ---- FUNC 00010027 FUN_180010027 (24 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180010027(void)

{
  return;
}

/* ---- FUNC 00010040 FUN_180010040 (76 bytes) ---- */

undefined8 * FUN_180010040(undefined8 param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar1 = operator_new(0x20);
  puVar2 = (undefined8 *)0x0;
  if (puVar1 != (undefined8 *)0x0) {
    puVar2 = FUN_18000ad80(puVar1);
  }
  *param_2 = puVar2;
  puVar1 = (undefined8 *)0x8007000e;
  if (puVar2 != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)0x0;
  }
  return puVar1;
}

/* ---- FUNC 00010090 FUN_180010090 (679 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180010090(longlong *param_1)

{
  char cVar1;
  int iVar2;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar3;
  longlong *plVar4;
  undefined8 uVar5;
  longlong *plVar6;
  char *pcVar7;
  longlong lVar8;
  longlong lVar9;
  uint uVar10;
  bool bVar12;
  undefined1 auStack_88 [32];
  int local_68 [2];
  undefined8 *local_60;
  undefined8 local_58;
  char local_50 [32];
  ulonglong local_30;
  longlong *plVar11;
  
  local_30 = DAT_180077818 ^ (ulonglong)auStack_88;
  if (param_1[0x17] != 0) {
    *(int *)((longlong)param_1 + 0x14) = *(int *)((longlong)param_1 + 0x14) + 1;
    plVar6 = (longlong *)0x0;
    bVar12 = false;
    local_68[1] = 1;
    if (param_1[0x17] < 1) {
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               param_1[0x16]);
    local_68[0] = 0;
    sscanf(local_58,"container = %d",local_68);
    if (0 < local_68[0]) {
      pCVar3 = FUN_180020fe0((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_60,4);
      iVar2 = MMAfxMessageBox(*(char **)pCVar3,0x2004,-1,0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_60);
      bVar12 = iVar2 == 6;
    }
    plVar11 = plVar6;
    if (0 < local_68[0]) {
      do {
        local_60 = operator_new(0x100);
        plVar4 = plVar6;
        if (local_60 != (undefined8 *)0x0) {
          plVar4 = FUN_180025390(local_60);
        }
        (**(code **)(*plVar4 + 8))(plVar4);
        plVar4[2] = (longlong)param_1;
        (**(code **)(*param_1 + 8))(param_1);
        uVar5 = FUN_18002b380(plVar4,(longlong)(param_1 + 0x15),local_68 + 1);
        if ((int)uVar5 < 0) {
          (**(code **)(*plVar4 + 0x10))();
          break;
        }
        FUN_18002f6d0((longlong)plVar4,1);
        CPtrArray::SetAtGrow((CPtrArray *)(param_1 + 0x43),param_1[0x45],plVar4);
        uVar10 = (int)plVar11 + 1;
        plVar11 = (longlong *)(ulonglong)uVar10;
      } while ((int)uVar10 < local_68[0]);
    }
    CStringArray::SetSize((CStringArray *)(param_1 + 0x15),0,-1);
    if (bVar12) {
      local_60 = operator_new(0x30);
      if (local_60 != (undefined8 *)0x0) {
        plVar6 = FUN_18005a5f0(local_60,param_1 + 0x43);
      }
      (**(code **)(*plVar6 + 8))(plVar6);
      FUN_18005af40((longlong)plVar6);
      iVar2 = OleUIUpdateLinksA(plVar6,DAT_1800797e0,"Update Links",(int)param_1[0x45]);
      if (iVar2 == 0) {
        pcVar7 = (char *)MVGetProductName();
        lVar8 = -(longlong)pcVar7;
        do {
          cVar1 = *pcVar7;
          pcVar7[(longlong)(local_50 + lVar8)] = cVar1;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        pcVar7 = (char *)((longlong)&local_58 + 7);
        do {
          pcVar7 = pcVar7 + 1;
        } while (*pcVar7 != '\0');
        *(undefined2 *)pcVar7 = DAT_1800633a4;
        lVar8 = MVGetVersionString();
        pcVar7 = (char *)((longlong)&local_58 + 7);
        do {
          pcVar7 = pcVar7 + 1;
        } while (*pcVar7 != '\0');
        lVar9 = 0;
        do {
          cVar1 = *(char *)(lVar8 + lVar9);
          pcVar7[lVar9] = cVar1;
          lVar9 = lVar9 + 1;
        } while (cVar1 != '\0');
        iVar2 = OleUIPromptUserA(0x3f0,DAT_1800797e0,local_50);
        if (iVar2 == 900) {
          FUN_18000fc60((longlong)param_1);
        }
      }
      (**(code **)(*plVar6 + 0x10))(plVar6);
    }
    *(int *)((longlong)param_1 + 0x14) = *(int *)((longlong)param_1 + 0x14) + -1;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58);
  }
  return;
}

/* ---- FUNC 00010340 FUN_180010340 (300 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_180010340(longlong *param_1,undefined4 param_2,LPCWSTR param_3)

{
  code *pcVar1;
  undefined4 uVar2;
  longlong lVar3;
  ulonglong uVar5;
  int iVar6;
  undefined8 uVar7;
  undefined1 *puVar8;
  char *pcVar9;
  undefined8 uStack_60;
  undefined1 auStack_58 [32];
  undefined8 uStack_38;
  int aiStack_30 [2];
  undefined8 local_28 [2];
  longlong local_18;
  ulonglong local_10;
  longlong lVar4;
  
  local_10 = DAT_180077818 ^ (ulonglong)&local_18;
  puVar8 = auStack_58;
  if (param_3 == (LPCWSTR)0x0) {
LAB_1800103fd:
    pcVar9 = (char *)0x0;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_3[lVar3] != L'\0');
    iVar6 = (int)lVar4 + 2;
    puVar8 = auStack_58;
    if (0x3fffffff < iVar6) goto LAB_1800103fd;
    lVar3 = (longlong)(int)lVar3 * 2;
    uVar5 = lVar3 + 0x11;
    if (uVar5 <= lVar3 + 2U) {
      uVar5 = 0xffffffffffffff0;
    }
    uStack_60 = 0x1800103bf;
    lVar3 = -(uVar5 & 0xfffffffffffffff0);
    puVar8 = auStack_58 + lVar3;
    pcVar9 = (char *)((longlong)&local_18 + lVar3);
    if (pcVar9 == (char *)0x0) goto LAB_1800103fd;
    *pcVar9 = '\0';
    *(undefined8 *)((longlong)local_28 + lVar3 + 8) = 0;
    *(undefined8 *)((longlong)local_28 + lVar3) = 0;
    *(int *)((longlong)aiStack_30 + lVar3) = iVar6 * 2;
    *(char **)((longlong)&uStack_38 + lVar3) = pcVar9;
    *(undefined8 *)(auStack_58 + lVar3 + -8) = 0x1800103f5;
    iVar6 = WideCharToMultiByte(0,0,param_3,-1,*(LPSTR *)((longlong)&uStack_38 + lVar3),
                                *(int *)((longlong)aiStack_30 + lVar3),
                                *(LPCSTR *)((longlong)local_28 + lVar3),
                                *(LPBOOL *)((longlong)local_28 + lVar3 + 8));
    puVar8 = auStack_58 + lVar3;
    if (iVar6 == 0) {
      puVar8 = auStack_58 + lVar3;
      pcVar9 = (char *)0x0;
    }
  }
  uVar2 = 0;
  *(undefined8 *)(puVar8 + -8) = 0x18001040e;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_18,pcVar9);
  if (*(int *)(local_18 + -0x10) == 0) {
    uVar7 = 0x7d4;
  }
  else {
    *(undefined8 *)(puVar8 + -8) = 0x180010427;
    uVar7 = FUN_1800373e0(local_18,param_2);
    if (-1 < (int)uVar7) goto LAB_18001043e;
    uVar7 = 0x7f4;
  }
  pcVar1 = *(code **)(*param_1 + 0x280);
  *(undefined8 *)(puVar8 + -8) = 0x18001043c;
  uVar2 = (*pcVar1)(param_1,uVar7);
LAB_18001043e:
  *(undefined8 *)(puVar8 + -8) = 0x180010448;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_18);
  *(undefined8 *)(puVar8 + -8) = 0x180010456;
  return uVar2;
}

/* ---- FUNC 00010470 FUN_180010470 (861 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined8 FUN_180010470(longlong *param_1,LPCWSTR param_2,undefined4 param_3,VARIANTARG *param_4)

{
  undefined1 *puVar1;
  VARTYPE VVar2;
  undefined4 *puVar3;
  longlong *plVar4;
  code *pcVar5;
  HRESULT HVar6;
  undefined8 uVar7;
  longlong lVar8;
  ulonglong uVar10;
  int iVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  LPCWSTR lpWideCharStr;
  undefined8 uStack_b0;
  undefined1 auStack_a8 [32];
  undefined8 uStack_88;
  int aiStack_80 [2];
  undefined8 local_78 [2];
  VARIANTARG local_68;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  ulonglong local_28;
  longlong lVar9;
  
  puVar13 = auStack_a8;
  puVar14 = auStack_a8;
  local_28 = DAT_180077818 ^ (ulonglong)&local_68;
  if (DAT_1800797f8 != 0) {
    uStack_b0 = 0x1800104cd;
    uVar7 = (**(code **)(*(longlong *)param_1[1] + 0x280))((longlong *)param_1[1],0x7f3);
    puVar14 = auStack_a8;
    goto LAB_1800107a1;
  }
  uStack_b0 = 0x1800104dc;
  VariantInit(&local_68);
  VVar2 = (param_4->n1).n2.vt;
  if (VVar2 == 0x400c) {
    puVar3 = *(undefined4 **)((longlong)&param_4->n1 + 8);
    local_48 = *puVar3;
    uStack_44 = puVar3[1];
    uStack_40 = puVar3[2];
    uStack_3c = puVar3[3];
    local_38 = *(undefined8 *)(puVar3 + 4);
    uStack_b0 = 0x180010514;
    uVar7 = (**(code **)(*param_1 + 0x120))(param_1,param_2,param_3,&local_48);
    puVar14 = auStack_a8;
    goto LAB_1800107a1;
  }
  if (param_2 == (LPCWSTR)0x0) {
LAB_18001051e:
    uStack_b0 = 0x180010530;
    uVar7 = (**(code **)(*(longlong *)param_1[1] + 0x280))((longlong *)param_1[1],0x7d4);
    goto LAB_1800107a1;
  }
  puVar15 = (undefined1 *)0x0;
  if ((VVar2 == 0) || (VVar2 == 1)) {
LAB_1800106ef:
    puVar12 = &DAT_18006271e;
    puVar13 = auStack_a8;
  }
  else {
    puVar12 = puVar15;
    if (VVar2 == 8) {
      lpWideCharStr = *(LPCWSTR *)((longlong)&param_4->n1 + 8);
      if (lpWideCharStr == (LPCWSTR)0x0) {
        puVar12 = (undefined1 *)0x0;
        puVar13 = auStack_a8;
      }
      else {
        lVar8 = -1;
        do {
          lVar8 = lVar8 + 1;
        } while (lpWideCharStr[lVar8] != L'\0');
LAB_18001065a:
        iVar11 = (int)lVar8 + 1;
        if (iVar11 < 0x40000000) {
          lVar8 = (longlong)(int)lVar8 * 2;
          uVar10 = lVar8 + 0x11;
          if (uVar10 <= lVar8 + 2U) {
            uVar10 = 0xffffffffffffff0;
          }
          uStack_b0 = 0x18001068f;
          lVar8 = -(uVar10 & 0xfffffffffffffff0);
          puVar13 = auStack_a8 + lVar8;
          puVar14 = (undefined1 *)((longlong)&local_68 + lVar8);
          if (puVar14 != (undefined1 *)0x0) {
            *(undefined8 *)((longlong)local_78 + lVar8 + 8) = 0;
            *(undefined8 *)((longlong)local_78 + lVar8) = 0;
            *(int *)((longlong)aiStack_80 + lVar8) = iVar11 * 2;
            *puVar14 = 0;
            *(undefined1 **)((longlong)&uStack_88 + lVar8) = puVar14;
            *(undefined8 *)(auStack_a8 + lVar8 + -8) = 0x1800106c3;
            iVar11 = WideCharToMultiByte(0,0,lpWideCharStr,-1,
                                         *(LPSTR *)((longlong)&uStack_88 + lVar8),
                                         *(int *)((longlong)aiStack_80 + lVar8),
                                         *(LPCSTR *)((longlong)local_78 + lVar8),
                                         *(LPBOOL *)((longlong)local_78 + lVar8 + 8));
            puVar12 = puVar14;
            puVar13 = auStack_a8 + lVar8;
            if (iVar11 == 0) {
              puVar12 = puVar15;
              puVar13 = auStack_a8 + lVar8;
            }
          }
        }
        else {
          puVar12 = (undefined1 *)0x0;
          puVar13 = auStack_a8;
        }
      }
    }
    else {
      if (VVar2 == 10) goto LAB_1800106ef;
      if (VVar2 == 0x4008) {
        lpWideCharStr = (LPCWSTR)**(longlong **)((longlong)&param_4->n1 + 8);
        if (lpWideCharStr != (LPCWSTR)0x0) {
          lVar8 = -1;
          do {
            lVar8 = lVar8 + 1;
          } while (lpWideCharStr[lVar8] != L'\0');
          goto LAB_18001065a;
        }
      }
      else {
        uStack_b0 = 0x180010586;
        HVar6 = VariantChangeType(&local_68,param_4,0,8);
        if (HVar6 < 0) goto LAB_18001051e;
        puVar13 = auStack_a8;
        if (local_68.n1.decVal.u2.Lo64 != 0) {
          lVar8 = -1;
          do {
            lVar9 = lVar8;
            lVar8 = lVar9 + 1;
          } while (*(LPCWSTR)((longlong)local_68.n1.decVal.u2 + lVar8 * 2) != L'\0');
          iVar11 = (int)lVar9 + 2;
          puVar13 = auStack_a8;
          if (iVar11 < 0x40000000) {
            lVar8 = (longlong)(int)lVar8 * 2;
            uVar10 = lVar8 + 0x11;
            if (uVar10 <= lVar8 + 2U) {
              uVar10 = 0xffffffffffffff0;
            }
            uStack_b0 = 0x1800105d7;
            lVar8 = -(uVar10 & 0xfffffffffffffff0);
            puVar13 = auStack_a8 + lVar8;
            puVar12 = (undefined1 *)((longlong)&local_68 + lVar8);
            if (puVar12 != (undefined1 *)0x0) {
              *(undefined8 *)((longlong)local_78 + lVar8 + 8) = 0;
              *(undefined8 *)((longlong)local_78 + lVar8) = 0;
              *(int *)((longlong)aiStack_80 + lVar8) = iVar11 * 2;
              *puVar12 = 0;
              *(undefined1 **)((longlong)&uStack_88 + lVar8) = puVar12;
              *(undefined8 *)(auStack_a8 + lVar8 + -8) = 0x18001060b;
              iVar11 = WideCharToMultiByte(0,0,(LPCWSTR)local_68.n1.decVal.u2,-1,
                                           *(LPSTR *)((longlong)&uStack_88 + lVar8),
                                           *(int *)((longlong)aiStack_80 + lVar8),
                                           *(LPCSTR *)((longlong)local_78 + lVar8),
                                           *(LPBOOL *)((longlong)local_78 + lVar8 + 8));
              if (iVar11 == 0) {
                puVar12 = puVar15;
              }
              *(undefined8 *)(auStack_a8 + lVar8 + -8) = 0x18001061b;
              VariantClear(&local_68);
              puVar13 = auStack_a8 + lVar8;
              goto LAB_1800106f6;
            }
          }
        }
        *(undefined8 *)(puVar13 + -8) = 0x18001062d;
        VariantClear(&local_68);
        puVar12 = puVar15;
      }
    }
  }
LAB_1800106f6:
  lVar8 = -1;
  do {
    lVar9 = lVar8;
    lVar8 = lVar9 + 1;
  } while (param_2[lVar8] != L'\0');
  iVar11 = (int)lVar9 + 2;
  puVar14 = puVar13;
  puVar16 = puVar15;
  if (iVar11 < 0x40000000) {
    lVar8 = (longlong)(int)lVar8 * 2;
    uVar10 = lVar8 + 0x11;
    if (uVar10 <= lVar8 + 2U) {
      uVar10 = 0xffffffffffffff0;
    }
    *(undefined8 *)(puVar13 + -8) = 0x180010737;
    lVar8 = -(uVar10 & 0xfffffffffffffff0);
    puVar1 = puVar13 + lVar8 + 0x40;
    puVar14 = puVar13 + lVar8;
    if (puVar1 != (undefined1 *)0x0) {
      *(undefined8 *)(puVar13 + lVar8 + 0x38) = 0;
      *(undefined8 *)(puVar13 + lVar8 + 0x30) = 0;
      *(int *)(puVar13 + lVar8 + 0x28) = iVar11 * 2;
      *(undefined1 **)(puVar13 + lVar8 + 0x20) = puVar1;
      *puVar1 = 0;
      *(undefined8 *)(puVar13 + lVar8 + -8) = 0x180010770;
      iVar11 = WideCharToMultiByte(0,0,param_2,-1,*(LPSTR *)(puVar13 + lVar8 + 0x20),
                                   *(int *)(puVar13 + lVar8 + 0x28),
                                   *(LPCSTR *)(puVar13 + lVar8 + 0x30),
                                   *(LPBOOL *)(puVar13 + lVar8 + 0x38));
      puVar14 = puVar13 + lVar8;
      puVar16 = puVar1;
      if (iVar11 == 0) {
        puVar14 = puVar13 + lVar8;
        puVar16 = puVar15;
      }
    }
  }
  *(undefined8 *)(puVar14 + -8) = 0x180010787;
  iVar11 = Ordinal_112(puVar16,param_3,puVar12);
  if (iVar11 < 0) {
    plVar4 = (longlong *)param_1[1];
    pcVar5 = *(code **)(*plVar4 + 0x280);
    *(undefined8 *)(puVar14 + -8) = 0x18001079d;
    uVar7 = (*pcVar5)(plVar4,0x7d1);
  }
  else {
    uVar7 = 0;
  }
LAB_1800107a1:
  *(undefined8 *)(puVar14 + -8) = 0x1800107ad;
  return uVar7;
}

/* ---- FUNC 000107D0 FUN_1800107d0 (1072 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_1800107d0(undefined8 param_1,int param_2,undefined8 *param_3,undefined8 *param_4,
             undefined8 *param_5,undefined8 *param_6,undefined8 *param_7,undefined8 *param_8,
             undefined8 *param_9,undefined8 *param_10)

{
  OLECHAR *pOVar1;
  LPCSTR lpMultiByteStr;
  int iVar2;
  BSTR pOVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  OLECHAR *pOVar8;
  OLECHAR *pOVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined8 uStack_190;
  undefined1 auStack_188 [32];
  undefined8 uStack_168;
  int aiStack_160 [2];
  LPCSTR local_158;
  undefined8 *local_150;
  undefined8 *local_148;
  undefined8 *local_140;
  CHAR local_138;
  char acStack_137 [15];
  CHAR local_128;
  char acStack_127 [63];
  undefined8 local_e8;
  undefined8 local_e0;
  CHAR local_d0;
  char acStack_cf [19];
  CHAR local_bc;
  char acStack_bb [49];
  CHAR local_8a;
  char acStack_89 [65];
  ulonglong local_48;
  
  puVar12 = auStack_188;
  puVar10 = auStack_188;
  local_48 = DAT_180077818 ^ (ulonglong)&local_158;
  pOVar8 = (OLECHAR *)0x0;
  local_150 = param_8;
  local_148 = param_9;
  local_140 = param_10;
  local_158 = (LPCSTR)0x0;
  uStack_190 = 0x180010859;
  iVar2 = FetchNextComponent_Mmg(param_2 == 1,&local_138,&local_158);
  if (iVar2 == 0) {
    uVar6 = 0x80004005;
  }
  else {
    if (param_2 != 1) {
      lVar4 = -1;
      do {
        lVar5 = lVar4;
        lVar4 = lVar5 + 1;
      } while (acStack_137[lVar5] != '\0');
      iVar2 = (int)lVar5 + 2;
      puVar12 = auStack_188;
      pOVar9 = pOVar8;
      if (iVar2 < 0x40000000) {
        lVar4 = (longlong)(int)(lVar5 + 1) * 2;
        uVar7 = lVar4 + 0x11;
        if (uVar7 <= lVar4 + 2U) {
          uVar7 = 0xffffffffffffff0;
        }
        uStack_190 = 0x1800108b4;
        lVar4 = -(uVar7 & 0xfffffffffffffff0);
        pOVar1 = (OLECHAR *)((longlong)&local_158 + lVar4);
        puVar12 = auStack_188 + lVar4;
        if (pOVar1 != (OLECHAR *)0x0) {
          *(int *)((longlong)aiStack_160 + lVar4) = iVar2;
          *pOVar1 = L'\0';
          *(OLECHAR **)((longlong)&uStack_168 + lVar4) = pOVar1;
          *(undefined8 *)(auStack_188 + lVar4 + -8) = 0x1800108e1;
          iVar2 = MultiByteToWideChar(0,0,&local_138,-1,*(LPWSTR *)((longlong)&uStack_168 + lVar4),
                                      *(int *)((longlong)aiStack_160 + lVar4));
          puVar12 = auStack_188 + lVar4;
          pOVar9 = pOVar1;
          if (iVar2 == 0) {
            puVar12 = auStack_188 + lVar4;
            pOVar9 = pOVar8;
          }
        }
      }
      *(undefined8 *)(puVar12 + -8) = 0x1800108f5;
      pOVar3 = SysAllocString(pOVar9);
      *param_3 = pOVar3;
      lVar4 = -1;
      do {
        lVar5 = lVar4;
        lVar4 = lVar5 + 1;
      } while (acStack_127[lVar5] != '\0');
      iVar2 = (int)lVar5 + 2;
      puVar10 = puVar12;
      pOVar9 = pOVar8;
      if (iVar2 < 0x40000000) {
        lVar4 = (longlong)(int)(lVar5 + 1) * 2;
        uVar7 = lVar4 + 0x11;
        if (uVar7 <= lVar4 + 2U) {
          uVar7 = 0xffffffffffffff0;
        }
        *(undefined8 *)(puVar12 + -8) = 0x180010942;
        lVar4 = -(uVar7 & 0xfffffffffffffff0);
        pOVar1 = (OLECHAR *)(puVar12 + lVar4 + 0x30);
        puVar10 = puVar12 + lVar4;
        if (pOVar1 != (OLECHAR *)0x0) {
          *(int *)(puVar12 + lVar4 + 0x28) = iVar2;
          *pOVar1 = L'\0';
          *(OLECHAR **)(puVar12 + lVar4 + 0x20) = pOVar1;
          *(undefined8 *)(puVar12 + lVar4 + -8) = 0x18001096f;
          iVar2 = MultiByteToWideChar(0,0,&local_128,-1,*(LPWSTR *)(puVar12 + lVar4 + 0x20),
                                      *(int *)(puVar12 + lVar4 + 0x28));
          puVar10 = puVar12 + lVar4;
          pOVar9 = pOVar1;
          if (iVar2 == 0) {
            puVar10 = puVar12 + lVar4;
            pOVar9 = pOVar8;
          }
        }
      }
      *(undefined8 *)(puVar10 + -8) = 0x180010983;
      pOVar3 = SysAllocString(pOVar9);
      lpMultiByteStr = local_158;
      *param_6 = local_e0;
      *param_5 = local_e8;
      *param_4 = pOVar3;
      puVar12 = puVar10;
      pOVar9 = pOVar8;
      if (local_158 != (LPCSTR)0x0) {
        lVar4 = -1;
        do {
          lVar5 = lVar4;
          lVar4 = lVar5 + 1;
        } while (local_158[lVar4] != '\0');
        iVar2 = (int)lVar5 + 2;
        if (iVar2 < 0x40000000) {
          lVar4 = (longlong)(int)lVar4 * 2;
          uVar7 = lVar4 + 0x11;
          if (uVar7 <= lVar4 + 2U) {
            uVar7 = 0xffffffffffffff0;
          }
          *(undefined8 *)(puVar10 + -8) = 0x1800109e6;
          lVar4 = -(uVar7 & 0xfffffffffffffff0);
          pOVar1 = (OLECHAR *)(puVar10 + lVar4 + 0x30);
          puVar12 = puVar10 + lVar4;
          if (pOVar1 != (OLECHAR *)0x0) {
            *(int *)(puVar10 + lVar4 + 0x28) = iVar2;
            *pOVar1 = L'\0';
            *(OLECHAR **)(puVar10 + lVar4 + 0x20) = pOVar1;
            *(undefined8 *)(puVar10 + lVar4 + -8) = 0x180010a0d;
            iVar2 = MultiByteToWideChar(0,0,lpMultiByteStr,-1,*(LPWSTR *)(puVar10 + lVar4 + 0x20),
                                        *(int *)(puVar10 + lVar4 + 0x28));
            puVar12 = puVar10 + lVar4;
            pOVar9 = pOVar1;
            if (iVar2 == 0) {
              puVar12 = puVar10 + lVar4;
              pOVar9 = pOVar8;
            }
          }
        }
      }
      *(undefined8 *)(puVar12 + -8) = 0x180010a21;
      pOVar3 = SysAllocString(pOVar9);
      *param_7 = pOVar3;
      lVar4 = -1;
      do {
        lVar5 = lVar4;
        lVar4 = lVar5 + 1;
      } while (acStack_cf[lVar5] != '\0');
      iVar2 = (int)lVar5 + 2;
      puVar10 = puVar12;
      pOVar9 = pOVar8;
      if (iVar2 < 0x40000000) {
        lVar4 = (longlong)(int)(lVar5 + 1) * 2;
        uVar7 = lVar4 + 0x11;
        if (uVar7 <= lVar4 + 2U) {
          uVar7 = 0xffffffffffffff0;
        }
        *(undefined8 *)(puVar12 + -8) = 0x180010a68;
        lVar4 = -(uVar7 & 0xfffffffffffffff0);
        pOVar1 = (OLECHAR *)(puVar12 + lVar4 + 0x30);
        puVar10 = puVar12 + lVar4;
        if (pOVar1 != (OLECHAR *)0x0) {
          *(int *)(puVar12 + lVar4 + 0x28) = iVar2;
          *pOVar1 = L'\0';
          *(OLECHAR **)(puVar12 + lVar4 + 0x20) = pOVar1;
          *(undefined8 *)(puVar12 + lVar4 + -8) = 0x180010a98;
          iVar2 = MultiByteToWideChar(0,0,&local_d0,-1,*(LPWSTR *)(puVar12 + lVar4 + 0x20),
                                      *(int *)(puVar12 + lVar4 + 0x28));
          puVar10 = puVar12 + lVar4;
          pOVar9 = pOVar1;
          if (iVar2 == 0) {
            puVar10 = puVar12 + lVar4;
            pOVar9 = pOVar8;
          }
        }
      }
      *(undefined8 *)(puVar10 + -8) = 0x180010aac;
      pOVar3 = SysAllocString(pOVar9);
      *local_150 = pOVar3;
      lVar4 = -1;
      do {
        lVar5 = lVar4;
        lVar4 = lVar5 + 1;
      } while (acStack_bb[lVar5] != '\0');
      iVar2 = (int)lVar5 + 2;
      puVar11 = puVar10;
      pOVar9 = pOVar8;
      if (iVar2 < 0x40000000) {
        lVar4 = (longlong)(int)(lVar5 + 1) * 2;
        uVar7 = lVar4 + 0x11;
        if (uVar7 <= lVar4 + 2U) {
          uVar7 = 0xffffffffffffff0;
        }
        *(undefined8 *)(puVar10 + -8) = 0x180010af6;
        lVar4 = -(uVar7 & 0xfffffffffffffff0);
        pOVar1 = (OLECHAR *)(puVar10 + lVar4 + 0x30);
        puVar11 = puVar10 + lVar4;
        if (pOVar1 != (OLECHAR *)0x0) {
          *(int *)(puVar10 + lVar4 + 0x28) = iVar2;
          *pOVar1 = L'\0';
          *(OLECHAR **)(puVar10 + lVar4 + 0x20) = pOVar1;
          *(undefined8 *)(puVar10 + lVar4 + -8) = 0x180010b26;
          iVar2 = MultiByteToWideChar(0,0,&local_bc,-1,*(LPWSTR *)(puVar10 + lVar4 + 0x20),
                                      *(int *)(puVar10 + lVar4 + 0x28));
          puVar11 = puVar10 + lVar4;
          pOVar9 = pOVar1;
          if (iVar2 == 0) {
            puVar11 = puVar10 + lVar4;
            pOVar9 = pOVar8;
          }
        }
      }
      *(undefined8 *)(puVar11 + -8) = 0x180010b3a;
      pOVar3 = SysAllocString(pOVar9);
      *local_148 = pOVar3;
      lVar4 = -1;
      do {
        lVar5 = lVar4;
        lVar4 = lVar5 + 1;
      } while (acStack_89[lVar5] != '\0');
      iVar2 = (int)lVar5 + 2;
      pOVar9 = pOVar8;
      puVar12 = puVar11;
      if (iVar2 < 0x40000000) {
        lVar4 = (longlong)(int)(lVar5 + 1) * 2;
        uVar7 = lVar4 + 0x11;
        if (uVar7 <= lVar4 + 2U) {
          uVar7 = 0xffffffffffffff0;
        }
        *(undefined8 *)(puVar11 + -8) = 0x180010b85;
        lVar4 = -(uVar7 & 0xfffffffffffffff0);
        pOVar1 = (OLECHAR *)(puVar11 + lVar4 + 0x30);
        puVar12 = puVar11 + lVar4;
        if (pOVar1 != (OLECHAR *)0x0) {
          *(int *)(puVar11 + lVar4 + 0x28) = iVar2;
          *pOVar1 = L'\0';
          *(OLECHAR **)(puVar11 + lVar4 + 0x20) = pOVar1;
          *(undefined8 *)(puVar11 + lVar4 + -8) = 0x180010bb5;
          iVar2 = MultiByteToWideChar(0,0,&local_8a,-1,*(LPWSTR *)(puVar11 + lVar4 + 0x20),
                                      *(int *)(puVar11 + lVar4 + 0x28));
          pOVar9 = pOVar1;
          puVar12 = puVar11 + lVar4;
          if (iVar2 == 0) {
            pOVar9 = pOVar8;
            puVar12 = puVar11 + lVar4;
          }
        }
      }
      *(undefined8 *)(puVar12 + -8) = 0x180010bc7;
      pOVar3 = SysAllocString(pOVar9);
      *local_140 = pOVar3;
    }
    uVar6 = 0;
    puVar10 = puVar12;
  }
  *(undefined8 *)(puVar10 + -8) = 0x180010be6;
  return uVar6;
}

/* ---- FUNC 00010C00 FUN_180010c00 (487 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HRESULT FUN_180010c00(longlong param_1,ushort *param_2)

{
  SAFEARRAY *psa;
  LPCWSTR lpWideCharStr;
  HRESULT HVar1;
  void *_Dst;
  longlong lVar2;
  ulonglong uVar4;
  int iVar5;
  ulonglong uVar6;
  char *pcVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  ulonglong uVar11;
  longlong lVar12;
  undefined1 auStack_88 [64];
  LONG local_48;
  LONG LStack_44;
  int local_40 [2];
  LPCWSTR local_38;
  ulonglong local_30;
  longlong lVar3;
  
  puVar9 = auStack_88;
  local_30 = DAT_180077818 ^ (ulonglong)&local_48;
  FUN_18000eda0(param_1);
  if ((*param_2 == 0) || ((*param_2 >> 0xd & 1) == 0)) {
    HVar1 = -0x7fffbffb;
    puVar10 = auStack_88;
  }
  else {
    psa = *(SAFEARRAY **)(param_2 + 4);
    local_48 = 0;
    LStack_44 = 0;
    HVar1 = SafeArrayGetLBound(psa,1,&local_48);
    puVar10 = auStack_88;
    if ((-1 < HVar1) &&
       (HVar1 = SafeArrayGetUBound(psa,1,&LStack_44), puVar10 = auStack_88, -1 < HVar1)) {
      iVar5 = (LStack_44 - local_48) + 1;
      lVar12 = (longlong)iVar5;
      *(int *)(param_1 + 0x20) = iVar5;
      _Dst = malloc(lVar12 * 8);
      *(void **)(param_1 + 0x18) = _Dst;
      memset(_Dst,0,lVar12 * 8);
      uVar6 = 0;
      puVar10 = auStack_88;
      uVar11 = uVar6;
      if (0 < lVar12) {
        do {
          pcVar7 = (char *)0x0;
          local_40[0] = local_48 + (int)uVar6;
          *(undefined8 *)(puVar9 + -8) = 0x180010ce9;
          HVar1 = SafeArrayGetElement(psa,local_40,&local_38);
          lpWideCharStr = local_38;
          if (-1 < HVar1) {
            if (local_38 != (LPCWSTR)0x0) {
              lVar2 = -1;
              do {
                lVar3 = lVar2;
                lVar2 = lVar3 + 1;
              } while (local_38[lVar2] != L'\0');
              iVar5 = (int)lVar3 + 2;
              if (iVar5 < 0x40000000) {
                lVar2 = (longlong)(int)lVar2 * 2;
                uVar4 = lVar2 + 0x11;
                if (uVar4 <= lVar2 + 2U) {
                  uVar4 = 0xffffffffffffff0;
                }
                *(undefined8 *)(puVar9 + -8) = 0x180010d4d;
                lVar2 = -(uVar4 & 0xfffffffffffffff0);
                puVar8 = puVar9 + lVar2;
                pcVar7 = puVar9 + lVar2 + 0x40;
                if (pcVar7 == (char *)0x0) {
                  pcVar7 = (char *)0x0;
                  puVar9 = puVar9 + lVar2;
                }
                else {
                  *pcVar7 = '\0';
                  *(undefined8 *)(puVar9 + lVar2 + 0x38) = 0;
                  *(undefined8 *)(puVar9 + lVar2 + 0x30) = 0;
                  *(int *)(puVar9 + lVar2 + 0x28) = iVar5 * 2;
                  *(char **)(puVar9 + lVar2 + 0x20) = pcVar7;
                  *(undefined8 *)(puVar9 + lVar2 + -8) = 0x180010d81;
                  iVar5 = WideCharToMultiByte(0,0,lpWideCharStr,-1,*(LPSTR *)(puVar9 + lVar2 + 0x20)
                                              ,*(int *)(puVar9 + lVar2 + 0x28),
                                              *(LPCSTR *)(puVar9 + lVar2 + 0x30),
                                              *(LPBOOL *)(puVar9 + lVar2 + 0x38));
                  puVar9 = puVar9 + lVar2;
                  if (iVar5 == 0) {
                    pcVar7 = (char *)0x0;
                    puVar9 = puVar8;
                  }
                }
              }
            }
            *(undefined8 *)(puVar9 + -8) = 0x180010d9b;
            pcVar7 = _strdup(pcVar7);
            *(char **)(*(longlong *)(param_1 + 0x18) + uVar11 * 8) = pcVar7;
          }
          uVar6 = (ulonglong)((int)uVar6 + 1);
          uVar11 = uVar11 + 1;
          puVar10 = puVar9;
        } while ((longlong)uVar11 < lVar12);
      }
    }
  }
  *(undefined8 *)(puVar10 + -8) = 0x180010dcd;
  return HVar1;
}

/* ---- FUNC 00010DF0 FUN_180010df0 (1012 bytes) ---- */

void FUN_180010df0(longlong param_1,OLECHAR *param_2,OLECHAR *param_3,OLECHAR *param_4,
                  OLECHAR *param_5)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  BSTR pOVar4;
  char *pcVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  
  FUN_180011600(param_1);
  puVar3 = operator_new(0x18);
  if (puVar3 == (undefined8 *)0x0) {
    puVar3 = (undefined8 *)0x0;
  }
  else {
    puVar3[1] = 0;
    *(undefined4 *)(puVar3 + 2) = 1;
    pOVar4 = SysAllocString(param_2);
    *puVar3 = pOVar4;
    if ((pOVar4 == (BSTR)0x0) && (param_2 != (OLECHAR *)0x0)) {
                    /* WARNING: Subroutine does not return */
      FUN_18005d290(0x8007000e);
    }
  }
  if (puVar3 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_18005d290(0x8007000e);
  }
  pcVar5 = (char *)puVar3[1];
  if (pcVar5 == (char *)0x0) {
    pcVar5 = FUN_18005d360((LPCWSTR)*puVar3);
    puVar3[1] = pcVar5;
    if (pcVar5 != (LPSTR)0x0) goto LAB_180010e8a;
  }
  else {
LAB_180010e8a:
    pcVar5 = _strdup(pcVar5);
    *(char **)(param_1 + 0x28) = pcVar5;
    _strupr(pcVar5);
  }
  puVar6 = operator_new(0x18);
  if (puVar6 == (undefined8 *)0x0) {
    puVar6 = (undefined8 *)0x0;
  }
  else {
    puVar6[1] = 0;
    *(undefined4 *)(puVar6 + 2) = 1;
    pOVar4 = SysAllocString(param_3);
    *puVar6 = pOVar4;
    if ((pOVar4 == (BSTR)0x0) && (param_3 != (OLECHAR *)0x0)) {
                    /* WARNING: Subroutine does not return */
      FUN_18005d290(0x8007000e);
    }
  }
  if (puVar6 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_18005d290(0x8007000e);
  }
  pcVar5 = (char *)puVar6[1];
  if (pcVar5 == (char *)0x0) {
    pcVar5 = FUN_18005d360((LPCWSTR)*puVar6);
    puVar6[1] = pcVar5;
    if (pcVar5 != (LPSTR)0x0) goto LAB_180010f09;
  }
  else {
LAB_180010f09:
    pcVar5 = _strdup(pcVar5);
    *(char **)(param_1 + 0x38) = pcVar5;
    _strupr(pcVar5);
  }
  puVar7 = operator_new(0x18);
  if (puVar7 == (undefined8 *)0x0) {
    puVar7 = (undefined8 *)0x0;
  }
  else {
    puVar7[1] = 0;
    *(undefined4 *)(puVar7 + 2) = 1;
    pOVar4 = SysAllocString(param_4);
    *puVar7 = pOVar4;
    if ((pOVar4 == (BSTR)0x0) && (param_4 != (OLECHAR *)0x0)) {
                    /* WARNING: Subroutine does not return */
      FUN_18005d290(0x8007000e);
    }
  }
  if (puVar7 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_18005d290(0x8007000e);
  }
  LOCK();
  *(int *)(puVar7 + 2) = *(int *)(puVar7 + 2) + 1;
  UNLOCK();
  pcVar5 = (char *)puVar7[1];
  if (pcVar5 == (char *)0x0) {
    pcVar5 = FUN_18005d360((LPCWSTR)*puVar7);
    puVar7[1] = pcVar5;
  }
  LOCK();
  piVar1 = (int *)(puVar7 + 2);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    if ((BSTR)*puVar7 != (BSTR)0x0) {
      SysFreeString((BSTR)*puVar7);
      *puVar7 = 0;
    }
    if ((void *)puVar7[1] != (void *)0x0) {
      operator_delete__((void *)puVar7[1]);
      puVar7[1] = 0;
    }
    FUN_180025ad0(puVar7);
  }
  if (pcVar5 != (char *)0x0) {
    pcVar5 = _strdup(pcVar5);
    *(char **)(param_1 + 0x40) = pcVar5;
    _strupr(pcVar5);
  }
  puVar8 = operator_new(0x18);
  if (puVar8 == (undefined8 *)0x0) {
    puVar8 = (undefined8 *)0x0;
  }
  else {
    puVar8[1] = 0;
    *(undefined4 *)(puVar8 + 2) = 1;
    pOVar4 = SysAllocString(param_5);
    *puVar8 = pOVar4;
    if ((pOVar4 == (BSTR)0x0) && (param_5 != (OLECHAR *)0x0)) {
                    /* WARNING: Subroutine does not return */
      FUN_18005d290(0x8007000e);
    }
  }
  if (puVar8 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_18005d290(0x8007000e);
  }
  pcVar5 = (char *)puVar8[1];
  if (pcVar5 == (char *)0x0) {
    pcVar5 = FUN_18005d360((LPCWSTR)*puVar8);
    puVar8[1] = pcVar5;
    if (pcVar5 == (LPSTR)0x0) goto LAB_180011077;
  }
  pcVar5 = _strdup(pcVar5);
  *(char **)(param_1 + 0x30) = pcVar5;
  _strupr(pcVar5);
LAB_180011077:
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
    FUN_180025ad0(puVar8);
  }
  LOCK();
  piVar1 = (int *)(puVar7 + 2);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    if ((BSTR)*puVar7 != (BSTR)0x0) {
      SysFreeString((BSTR)*puVar7);
      *puVar7 = 0;
    }
    if ((void *)puVar7[1] != (void *)0x0) {
      operator_delete__((void *)puVar7[1]);
      puVar7[1] = 0;
    }
    FUN_180025ad0(puVar7);
  }
  LOCK();
  piVar1 = (int *)(puVar6 + 2);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    if ((BSTR)*puVar6 != (BSTR)0x0) {
      SysFreeString((BSTR)*puVar6);
      *puVar6 = 0;
    }
    if ((void *)puVar6[1] != (void *)0x0) {
      operator_delete__((void *)puVar6[1]);
      puVar6[1] = 0;
    }
    FUN_180025ad0(puVar6);
  }
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
    FUN_180025ad0(puVar3);
  }
  return;
}

/* ---- FUNC 000111F0 FUN_1800111f0 (22 bytes) ---- */

void FUN_1800111f0(longlong param_1)

{
  HRESULT HVar1;
  LPRUNNINGOBJECTTABLE local_res8;
  
  if (*(int *)(param_1 + 0xd8) == 0) {
    *(undefined4 *)(param_1 + 0xd8) = 1;
    CoSuspendClassObjects();
    DAT_1800797f0 = 0;
    if (*(longlong **)(param_1 + 8) != (longlong *)0x0) {
      (**(code **)(**(longlong **)(param_1 + 8) + 0x10))();
    }
    if (*(longlong **)(param_1 + 0x118) != (longlong *)0x0) {
      (**(code **)(**(longlong **)(param_1 + 0x118) + 0x10))();
    }
    if (*(longlong **)(param_1 + 0x180) != (longlong *)0x0) {
      (**(code **)(**(longlong **)(param_1 + 0x180) + 0x10))();
    }
    if (*(longlong **)(param_1 + 0x150) != (longlong *)0x0) {
      (**(code **)(**(longlong **)(param_1 + 0x150) + 0x10))();
    }
    if (*(longlong **)(param_1 + 0x2f0) != (longlong *)0x0) {
      (**(code **)(**(longlong **)(param_1 + 0x2f0) + 0x10))();
    }
    if (*(longlong **)(param_1 + 0x1b0) != (longlong *)0x0) {
      (**(code **)(**(longlong **)(param_1 + 0x1b0) + 0x10))();
    }
    if ((*(int *)(param_1 + 0x110) != 0) || (*(int *)(param_1 + 0x114) != 0)) {
      HVar1 = GetRunningObjectTable(0,&local_res8);
      if (-1 < HVar1) {
        if (*(DWORD *)(param_1 + 0x110) != 0) {
          (*local_res8->lpVtbl->Revoke)(local_res8,*(DWORD *)(param_1 + 0x110));
          *(undefined4 *)(param_1 + 0x110) = 0;
        }
        if (*(DWORD *)(param_1 + 0x114) != 0) {
          (*local_res8->lpVtbl->Revoke)(local_res8,*(DWORD *)(param_1 + 0x114));
          *(undefined4 *)(param_1 + 0x114) = 0;
        }
        (*local_res8->lpVtbl->Release)(local_res8);
      }
    }
    if (*(DWORD *)(param_1 + 0x120) != 0) {
      CoRevokeClassObject(*(DWORD *)(param_1 + 0x120));
    }
    if (*(void **)(param_1 + 0x108) != (void *)0x0) {
      operator_delete__(*(void **)(param_1 + 0x108));
    }
    if (*(longlong *)(param_1 + 0x20) != 0) {
      local_res8 = (IRunningObjectTable *)0x0;
      HARelease(*(longlong *)(param_1 + 0x20),&local_res8);
    }
    if (*(BSTR *)(param_1 + 0x60) != (BSTR)0x0) {
      SysFreeString(*(BSTR *)(param_1 + 0x60));
    }
    if (*(BSTR *)(param_1 + 0x58) != (BSTR)0x0) {
      SysFreeString(*(BSTR *)(param_1 + 0x58));
    }
    if (*(BSTR *)(param_1 + 0x68) != (BSTR)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00018001135a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      SysFreeString(*(BSTR *)(param_1 + 0x68));
      return;
    }
  }
  return;
}

/* ---- FUNC 00011206 FUN_180011206 (305 bytes) ---- */

void FUN_180011206(longlong param_1)

{
  HRESULT HVar1;
  longlong unaff_RBX;
  IRunningObjectTable *in_stack_00000030;
  
  *(undefined4 *)(param_1 + 0xd8) = 1;
  CoSuspendClassObjects();
  DAT_1800797f0 = 0;
  if (*(longlong **)(unaff_RBX + 8) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(unaff_RBX + 8) + 0x10))();
  }
  if (*(longlong **)(unaff_RBX + 0x118) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(unaff_RBX + 0x118) + 0x10))();
  }
  if (*(longlong **)(unaff_RBX + 0x180) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(unaff_RBX + 0x180) + 0x10))();
  }
  if (*(longlong **)(unaff_RBX + 0x150) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(unaff_RBX + 0x150) + 0x10))();
  }
  if (*(longlong **)(unaff_RBX + 0x2f0) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(unaff_RBX + 0x2f0) + 0x10))();
  }
  if (*(longlong **)(unaff_RBX + 0x1b0) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(unaff_RBX + 0x1b0) + 0x10))();
  }
  if ((*(int *)(unaff_RBX + 0x110) != 0) || (*(int *)(unaff_RBX + 0x114) != 0)) {
    HVar1 = GetRunningObjectTable(0,&stack0x00000030);
    if (-1 < HVar1) {
      if (*(DWORD *)(unaff_RBX + 0x110) != 0) {
        (*in_stack_00000030->lpVtbl->Revoke)(in_stack_00000030,*(DWORD *)(unaff_RBX + 0x110));
        *(undefined4 *)(unaff_RBX + 0x110) = 0;
      }
      if (*(DWORD *)(unaff_RBX + 0x114) != 0) {
        (*in_stack_00000030->lpVtbl->Revoke)(in_stack_00000030,*(DWORD *)(unaff_RBX + 0x114));
        *(undefined4 *)(unaff_RBX + 0x114) = 0;
      }
      (*in_stack_00000030->lpVtbl->Release)(in_stack_00000030);
    }
  }
  if (*(DWORD *)(unaff_RBX + 0x120) != 0) {
    CoRevokeClassObject(*(DWORD *)(unaff_RBX + 0x120));
  }
  if (*(void **)(unaff_RBX + 0x108) != (void *)0x0) {
    operator_delete__(*(void **)(unaff_RBX + 0x108));
  }
  if (*(longlong *)(unaff_RBX + 0x20) != 0) {
    in_stack_00000030 = (IRunningObjectTable *)0x0;
    HARelease(*(longlong *)(unaff_RBX + 0x20),&stack0x00000030);
  }
  if (*(BSTR *)(unaff_RBX + 0x60) != (BSTR)0x0) {
    SysFreeString(*(BSTR *)(unaff_RBX + 0x60));
  }
  if (*(BSTR *)(unaff_RBX + 0x58) != (BSTR)0x0) {
    SysFreeString(*(BSTR *)(unaff_RBX + 0x58));
  }
  if (*(BSTR *)(unaff_RBX + 0x68) != (BSTR)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00018001135a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    SysFreeString(*(BSTR *)(unaff_RBX + 0x68));
    return;
  }
  return;
}

/* ---- FUNC 00011337 FUN_180011337 (48 bytes) ---- */

void FUN_180011337(BSTR param_1)

{
  longlong unaff_RBX;
  
  SysFreeString(param_1);
  if (*(BSTR *)(unaff_RBX + 0x58) != (BSTR)0x0) {
    SysFreeString(*(BSTR *)(unaff_RBX + 0x58));
  }
  if (*(BSTR *)(unaff_RBX + 0x68) != (BSTR)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00018001135a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    SysFreeString(*(BSTR *)(unaff_RBX + 0x68));
    return;
  }
  return;
}

/* ---- FUNC 00011370 FUN_180011370 (146 bytes) ---- */

longlong * FUN_180011370(longlong param_1,undefined8 *param_2)

{
  ulonglong uVar1;
  longlong *plVar2;
  int iVar3;
  ulonglong uVar4;
  
  uVar1 = *(ulonglong *)(param_1 + 0x200);
  uVar4 = 0;
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar4 < 0) || (*(longlong *)(param_1 + 0x200) <= (longlong)uVar4)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar2 = *(longlong **)(*(longlong *)(param_1 + 0x1f8) + uVar4 * 8);
      iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         (plVar2 + 2),(char *)*param_2);
      if (iVar3 == 0) {
        (**(code **)(*plVar2 + 8))(plVar2);
        return plVar2;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  return (longlong *)0x0;
}

/* ---- FUNC 00011410 FUN_180011410 (406 bytes) ---- */

void FUN_180011410(longlong param_1,undefined8 param_2)

{
  longlong *plVar1;
  int iVar2;
  undefined1 local_res8 [8];
  undefined8 local_res10;
  longlong *local_res18;
  IDispatch *local_res20;
  longlong *local_78;
  longlong local_70;
  COleDispatchDriver local_50 [16];
  AFX_EXCEPTION_LINK local_40 [16];
  longlong *local_30 [3];
  
  plVar1 = *(longlong **)(param_1 + 0x1b0);
  local_res10 = param_2;
  local_70 = param_1;
  if ((plVar1 != (longlong *)0x0) &&
     (iVar2 = (**(code **)(*plVar1 + 0x20))(plVar1,&DAT_180063510,&local_78), -1 < iVar2)) {
    COleDispatchDriver::COleDispatchDriver(local_50);
    iVar2 = (**(code **)(*local_78 + 0x38))(local_78,&local_res18);
    if (-1 < iVar2) {
      (**(code **)(*local_res18 + 0x28))();
      while (iVar2 = (**(code **)(*local_res18 + 0x18))(local_res18,1,local_30,local_res8),
            iVar2 == 0) {
        if (local_30[0] != (longlong *)0x0) {
          local_res20 = (IDispatch *)0x0;
          iVar2 = (**(code **)*local_30[0])(local_30[0],&DAT_180066c78,&local_res20);
          if (-1 < iVar2) {
            COleDispatchDriver::AttachDispatch(local_50,local_res20,1);
            AFX_EXCEPTION_LINK::AFX_EXCEPTION_LINK(local_40);
            COleDispatchDriver::InvokeHelper
                      (local_50,0x68,1,0,(void *)0x0,&DAT_1800776dc,local_res10);
            AfxTryCleanup();
            COleDispatchDriver::ReleaseDispatch(local_50);
          }
          (**(code **)(*local_30[0] + 0x10))();
        }
      }
      (**(code **)(*local_res18 + 0x10))();
    }
    (**(code **)(*local_78 + 0x10))();
    COleDispatchDriver::ReleaseDispatch(local_50);
  }
  FUN_18001bec0(local_70);
  return;
}

/* ---- FUNC 000115B0 FUN_1800115b0 (66 bytes) ---- */

undefined8 FUN_1800115b0(undefined8 param_1,uint param_2,wchar_t *param_3,undefined8 *param_4)

{
  undefined8 *puVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_18 [16];
  
  puVar1 = (undefined8 *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
           CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_18,param_3);
  HappFireUpdateMessage((ulonglong)param_2,*puVar1,param_4);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_18);
  return 0;
}

/* ---- FUNC 00011600 FUN_180011600 (102 bytes) ---- */

void FUN_180011600(longlong param_1)

{
  if (*(void **)(param_1 + 0x28) != (void *)0x0) {
    free(*(void **)(param_1 + 0x28));
    *(undefined8 *)(param_1 + 0x28) = 0;
  }
  if (*(void **)(param_1 + 0x30) != (void *)0x0) {
    free(*(void **)(param_1 + 0x30));
    *(undefined8 *)(param_1 + 0x30) = 0;
  }
  if (*(void **)(param_1 + 0x38) != (void *)0x0) {
    free(*(void **)(param_1 + 0x38));
    *(undefined8 *)(param_1 + 0x38) = 0;
  }
  if (*(void **)(param_1 + 0x40) != (void *)0x0) {
    free(*(void **)(param_1 + 0x40));
    *(undefined8 *)(param_1 + 0x40) = 0;
  }
  return;
}

/* ---- FUNC 00011670 FUN_180011670 (355 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined8 FUN_180011670(longlong *param_1,LPCWSTR param_2,int param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  char *pcVar4;
  ulonglong uVar5;
  int iVar6;
  undefined1 *puVar7;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar8;
  undefined8 uStack_60;
  undefined1 auStack_58 [32];
  undefined8 uStack_38;
  int aiStack_30 [2];
  undefined8 local_28 [2];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_18 [8];
  ulonglong local_10;
  longlong lVar3;
  
  puVar7 = auStack_58;
  local_10 = DAT_180077818 ^ (ulonglong)local_18;
  if (DAT_1800797f8 != 0) {
    uStack_60 = 0x1800116b6;
    uVar1 = (**(code **)(*param_1 + 0x280))(param_1,0x7f3);
    goto LAB_1800117b1;
  }
  uStack_60 = 0x1800116cc;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_18,"");
  puVar7 = auStack_58;
  if (param_2 == (LPCWSTR)0x0) {
LAB_18001175f:
    pCVar8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  }
  else {
    lVar2 = -1;
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_2[lVar2] != L'\0');
    iVar6 = (int)lVar3 + 2;
    puVar7 = auStack_58;
    if (0x3fffffff < iVar6) goto LAB_18001175f;
    lVar2 = (longlong)(int)lVar2 * 2;
    uVar5 = lVar2 + 0x11;
    if (uVar5 <= lVar2 + 2U) {
      uVar5 = 0xffffffffffffff0;
    }
    uStack_60 = 0x18001171e;
    lVar2 = -(uVar5 & 0xfffffffffffffff0);
    puVar7 = auStack_58 + lVar2;
    pCVar8 = local_18 + lVar2;
    if (pCVar8 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0)
    goto LAB_18001175f;
    *pCVar8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>)0x0;
    *(undefined8 *)((longlong)local_28 + lVar2 + 8) = 0;
    *(undefined8 *)((longlong)local_28 + lVar2) = 0;
    *(int *)((longlong)aiStack_30 + lVar2) = iVar6 * 2;
    *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
     ((longlong)&uStack_38 + lVar2) = pCVar8;
    *(undefined8 *)(auStack_58 + lVar2 + -8) = 0x180011757;
    iVar6 = WideCharToMultiByte(0,0,param_2,-1,*(LPSTR *)((longlong)&uStack_38 + lVar2),
                                *(int *)((longlong)aiStack_30 + lVar2),
                                *(LPCSTR *)((longlong)local_28 + lVar2),
                                *(LPBOOL *)((longlong)local_28 + lVar2 + 8));
    puVar7 = auStack_58 + lVar2;
    if (iVar6 == 0) {
      puVar7 = auStack_58 + lVar2;
      pCVar8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    }
  }
  *(undefined8 *)(puVar7 + -8) = 0x180011770;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            (local_18,(char *)pCVar8);
  *(undefined8 *)(puVar7 + -8) = 0x18001177c;
  pcVar4 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)local_18,0);
  *(undefined8 *)(puVar7 + -8) = 0x180011791;
  export_MM_file_MAX((param_3 != 1) + '\t',pcVar4,0);
  *(undefined8 *)(puVar7 + -8) = 0x1800117a0;
  ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)local_18,-1);
  *(undefined8 *)(puVar7 + -8) = 0x1800117a5;
  GRsetgfl();
  *(undefined8 *)(puVar7 + -8) = 0x1800117af;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_18);
  uVar1 = 0;
LAB_1800117b1:
  *(undefined8 *)(puVar7 + -8) = 0x1800117bd;
  return uVar1;
}

/* ---- FUNC 000117E0 FUN_1800117e0 (255 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void FUN_1800117e0(longlong param_1,LPCWSTR param_2)

{
  longlong lVar1;
  ulonglong uVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined8 uStack_60;
  undefined1 auStack_58 [32];
  undefined8 uStack_38;
  int aiStack_30 [2];
  undefined8 local_28 [2];
  ulonglong local_18 [2];
  longlong lVar2;
  
  puVar5 = auStack_58;
  local_18[0] = DAT_180077818 ^ (ulonglong)local_18;
  if (DAT_1800797f8 != 0) {
    uStack_60 = 0x18001181c;
    (**(code **)(**(longlong **)(param_1 + 8) + 0x280))(*(longlong **)(param_1 + 8),0x7f3);
    goto LAB_1800118c5;
  }
  puVar5 = auStack_58;
  if (param_2 == (LPCWSTR)0x0) {
LAB_1800118b6:
    puVar4 = (undefined1 *)0x0;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_2[lVar1] != L'\0');
    iVar6 = (int)lVar2 + 2;
    puVar5 = auStack_58;
    if (0x3fffffff < iVar6) goto LAB_1800118b6;
    lVar1 = (longlong)(int)lVar1 * 2;
    uVar3 = lVar1 + 0x11;
    if (uVar3 <= lVar1 + 2U) {
      uVar3 = 0xffffffffffffff0;
    }
    uStack_60 = 0x180011871;
    lVar1 = -(uVar3 & 0xfffffffffffffff0);
    puVar5 = auStack_58 + lVar1;
    puVar4 = (undefined1 *)((longlong)local_18 + lVar1);
    if (puVar4 == (undefined1 *)0x0) goto LAB_1800118b6;
    *puVar4 = 0;
    *(undefined8 *)((longlong)local_28 + lVar1 + 8) = 0;
    *(undefined8 *)((longlong)local_28 + lVar1) = 0;
    *(int *)((longlong)aiStack_30 + lVar1) = iVar6 * 2;
    *(undefined1 **)((longlong)&uStack_38 + lVar1) = puVar4;
    *(undefined8 *)(auStack_58 + lVar1 + -8) = 0x1800118ab;
    iVar6 = WideCharToMultiByte(0,0,param_2,-1,*(LPSTR *)((longlong)&uStack_38 + lVar1),
                                *(int *)((longlong)aiStack_30 + lVar1),
                                *(LPCSTR *)((longlong)local_28 + lVar1),
                                *(LPBOOL *)((longlong)local_28 + lVar1 + 8));
    puVar5 = auStack_58 + lVar1;
    if (iVar6 == 0) {
      puVar4 = (undefined1 *)0x0;
      puVar5 = auStack_58 + lVar1;
    }
  }
  *(undefined8 *)(puVar5 + -8) = 0x1800118c5;
  Ordinal_40(0x1b,puVar4);
LAB_1800118c5:
  *(undefined8 *)(puVar5 + -8) = 0x1800118d1;
  return;
}

/* ---- FUNC 000118E0 FUN_1800118e0 (420 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_1800118e0(char *param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  undefined1 *puVar2;
  LPOLESTR pOVar3;
  HKEY pHVar4;
  LSTATUS LVar5;
  ulonglong uVar6;
  char *pcVar8;
  int iVar9;
  ulonglong uVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined8 uStack_170;
  undefined1 auStack_168 [32];
  undefined8 uStack_148;
  int aiStack_140 [2];
  undefined8 local_138 [2];
  undefined4 local_128 [2];
  LPOLESTR local_120;
  HKEY local_118;
  DWORD local_110 [2];
  CHAR local_108 [208];
  ulonglong local_38;
  ulonglong uVar7;
  
  local_38 = DAT_180077818 ^ (ulonglong)local_128;
  *param_1 = '\0';
  puVar13 = (undefined1 *)0x0;
  local_120 = (LPCWSTR)0x0;
  uStack_170 = 0x18001192d;
  StringFromCLSID((IID *)&DAT_180063880,&local_120);
  pOVar3 = local_120;
  uVar10 = 0xffffffffffffffff;
  uVar6 = uVar10;
  puVar11 = auStack_168;
  puVar12 = puVar13;
  if (local_120 != (LPCWSTR)0x0) {
    do {
      uVar7 = uVar6;
      uVar6 = uVar7 + 1;
    } while (local_120[uVar6] != L'\0');
    iVar9 = (int)uVar7 + 2;
    puVar11 = auStack_168;
    if (iVar9 < 0x40000000) {
      lVar1 = (longlong)(int)uVar6 * 2;
      uVar6 = lVar1 + 0x11;
      if (uVar6 <= lVar1 + 2U) {
        uVar6 = 0xffffffffffffff0;
      }
      uStack_170 = 0x18001197e;
      lVar1 = -(uVar6 & 0xfffffffffffffff0);
      puVar2 = (undefined1 *)((longlong)local_128 + lVar1);
      puVar11 = auStack_168 + lVar1;
      if (puVar2 != (undefined1 *)0x0) {
        *(undefined8 *)((longlong)local_138 + lVar1 + 8) = 0;
        *(undefined8 *)((longlong)local_138 + lVar1) = 0;
        param_4 = 0xffffffff;
        *(int *)((longlong)aiStack_140 + lVar1) = iVar9 * 2;
        *(undefined1 **)((longlong)&uStack_148 + lVar1) = puVar2;
        *puVar2 = 0;
        *(undefined8 *)(auStack_168 + lVar1 + -8) = 0x1800119b1;
        iVar9 = WideCharToMultiByte(0,0,pOVar3,-1,*(LPSTR *)((longlong)&uStack_148 + lVar1),
                                    *(int *)((longlong)aiStack_140 + lVar1),
                                    *(LPCSTR *)((longlong)local_138 + lVar1),
                                    *(LPBOOL *)((longlong)local_138 + lVar1 + 8));
        puVar11 = auStack_168 + lVar1;
        puVar12 = puVar2;
        if (iVar9 == 0) {
          puVar11 = auStack_168 + lVar1;
          puVar12 = puVar13;
        }
      }
    }
  }
  *(undefined8 *)(puVar11 + -8) = 0x1800119cf;
  FUN_180002a20(local_108,"CLSID\\%s\\InProcServer32",puVar12,param_4);
  pOVar3 = local_120;
  *(undefined8 *)(puVar11 + -8) = 0x1800119d9;
  CoTaskMemFree(pOVar3);
  local_118 = (HKEY)0x0;
  *(undefined8 *)(puVar11 + -8) = 0x1800119f2;
  LVar5 = RegOpenKeyA((HKEY)0xffffffff80000000,local_108,&local_118);
  pHVar4 = local_118;
  if (LVar5 == 0) {
    *(undefined4 **)(puVar11 + 0x28) = local_128;
    *(undefined **)(puVar11 + 0x20) = &DAT_180079340;
    local_128[0] = 0x104;
    *(undefined8 *)(puVar11 + -8) = 0x180011a25;
    LVar5 = RegQueryValueExA(pHVar4,(LPCSTR)0x0,(LPDWORD)0x0,local_110,*(LPBYTE *)(puVar11 + 0x20),
                             *(LPDWORD *)(puVar11 + 0x28));
    pHVar4 = local_118;
    if (LVar5 == 0) {
      *(undefined8 *)(puVar11 + -8) = 0x180011a34;
      pcVar8 = strrchr(&DAT_180079340,0x5c);
      *pcVar8 = '\0';
      *(undefined8 *)(puVar11 + -8) = 0x180011a46;
      strncpy(param_1,&DAT_180079340,(longlong)param_2);
      do {
        uVar10 = uVar10 + 1;
      } while (param_1[uVar10] != '\0');
      uVar10 = uVar10 & 0xffffffff;
      goto LAB_180011a5f;
    }
    *(undefined8 *)(puVar11 + -8) = 0x180011a5d;
    RegCloseKey(pHVar4);
  }
  uVar10 = 0;
LAB_180011a5f:
  *(undefined8 *)(puVar11 + -8) = 0x180011a6e;
  return uVar10;
}

/* ---- FUNC 00011A90 FUN_180011a90 (325 bytes) ---- */

undefined8 FUN_180011a90(longlong param_1,int *param_2,undefined2 *param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  char *pcVar3;
  SAFEARRAY *pSVar4;
  wchar_t *pv;
  LONG local_res20 [2];
  undefined4 local_58 [2];
  undefined8 local_50;
  SAFEARRAYBOUND local_48;
  CStringList local_40 [8];
  undefined8 *local_38;
  int local_28;
  
  if (DAT_1800797f8 != 0) {
    uVar2 = (**(code **)(**(longlong **)(param_1 + 8) + 0x280))(*(longlong **)(param_1 + 8),0x7f3);
    return uVar2;
  }
  local_58[0] = 1;
  CStringList::CStringList(local_40,10);
  local_50 = 0;
  pcVar3 = (char *)GetNextAvailableDatabank(local_58,&local_50);
  while (pcVar3 != (char *)0x0) {
    CStringList::AddTail(local_40,pcVar3);
    pcVar3 = (char *)GetNextAvailableDatabank(local_58,&local_50);
  }
  *param_2 = local_28;
  local_48.lLbound = 0;
  *param_3 = 0x2008;
  pSVar4 = SafeArrayCreate(8,1,&local_48);
  *(SAFEARRAY **)(param_3 + 4) = pSVar4;
  local_res20[0] = 0;
  if (0 < *param_2) {
    do {
      if (local_38 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      puVar1 = (undefined8 *)*local_38;
      pv = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::AllocSysString
                     ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                      (local_38 + 2));
      SafeArrayPutElement(*(SAFEARRAY **)(param_3 + 4),local_res20,pv);
      local_res20[0] = local_res20[0] + 1;
      local_38 = puVar1;
    } while (local_res20[0] < *param_2);
  }
  CStringList::~CStringList(local_40);
  return 0;
}

/* ---- FUNC 00011BE0 FUN_180011be0 (63 bytes) ---- */

undefined8 FUN_180011be0(longlong param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  if (*(longlong **)(param_1 + 0x10) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0x10) + 8))();
  }
  *param_2 = *(undefined8 *)(param_1 + 0x10);
  uVar1 = 0x80004005;
  if (*(longlong *)(param_1 + 0x10) != 0) {
    uVar1 = 0;
  }
  return uVar1;
}

/* ---- FUNC 00011C20 FUN_180011c20 (305 bytes) ---- */

undefined8 FUN_180011c20(longlong param_1,int *param_2,undefined2 *param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  char *pcVar3;
  SAFEARRAY *pSVar4;
  wchar_t *pv;
  LONG local_res20 [2];
  undefined4 local_58 [2];
  SAFEARRAYBOUND local_50;
  CStringList local_48 [8];
  undefined8 *local_40;
  int local_30;
  
  if (DAT_1800797f8 != 0) {
    uVar2 = (**(code **)(**(longlong **)(param_1 + 8) + 0x280))(*(longlong **)(param_1 + 8),0x7f3);
    return uVar2;
  }
  local_58[0] = 0;
  CStringList::CStringList(local_48,10);
  pcVar3 = (char *)GetNextDefaultDatabank(local_58);
  while (pcVar3 != (char *)0x0) {
    CStringList::AddTail(local_48,pcVar3);
    pcVar3 = (char *)GetNextDefaultDatabank(local_58);
  }
  *param_2 = local_30;
  local_50.lLbound = 0;
  *param_3 = 0x2008;
  pSVar4 = SafeArrayCreate(8,1,&local_50);
  *(SAFEARRAY **)(param_3 + 4) = pSVar4;
  local_res20[0] = 0;
  if (0 < *param_2) {
    do {
      if (local_40 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      puVar1 = (undefined8 *)*local_40;
      pv = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::AllocSysString
                     ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                      (local_40 + 2));
      SafeArrayPutElement(*(SAFEARRAY **)(param_3 + 4),local_res20,pv);
      local_res20[0] = local_res20[0] + 1;
      local_40 = puVar1;
    } while (local_res20[0] < *param_2);
  }
  CStringList::~CStringList(local_48);
  return 0;
}

/* ---- FUNC 00011D60 FUN_180011d60 (12 bytes) ---- */

void FUN_180011d60(undefined8 param_1,undefined8 param_2,undefined8 *param_3,int param_4,
                  LCID param_5,undefined4 *param_6)

{
  FUN_180011d80(&PTR_DAT_180077660,param_2,param_3,param_4,param_5,param_6);
  return;
}

/* ---- FUNC 00011D70 FUN_180011d70 (12 bytes) ---- */

void FUN_180011d70(undefined8 param_1,undefined8 param_2,undefined8 *param_3,int param_4,
                  LCID param_5,undefined4 *param_6)

{
  FUN_180011d80(&PTR_DAT_180077698,param_2,param_3,param_4,param_5,param_6);
  return;
}

/* ---- FUNC 00011D80 FUN_180011d80 (62 bytes) ---- */

HRESULT FUN_180011d80(undefined8 *param_1,undefined8 param_2,undefined8 *param_3,int param_4,
                     LCID param_5,undefined4 *param_6)

{
  longlong *plVar1;
  longlong lVar2;
  void *_Buf2;
  HRESULT HVar3;
  int iVar4;
  undefined8 *puVar5;
  int iVar6;
  longlong lVar7;
  longlong lVar8;
  
  HVar3 = 0;
  if ((param_1[3] == 0) || (param_1[5] == 0)) {
    HVar3 = FUN_1800123a0(param_1,param_5);
  }
  plVar1 = (longlong *)param_1[3];
  if (plVar1 != (longlong *)0x0) {
    lVar2 = param_1[5];
    if ((lVar2 != 0) && (param_4 == 1)) {
      _Buf2 = (void *)*param_3;
      if (_Buf2 == (void *)0x0) {
        lVar8 = 0;
      }
      else {
        lVar8 = -1;
        do {
          lVar8 = lVar8 + 1;
        } while (*(short *)((longlong)_Buf2 + lVar8 * 2) != 0);
      }
      iVar6 = *(int *)(param_1 + 6) + -1;
      if (-1 < iVar6) {
        lVar7 = (longlong)iVar6;
        puVar5 = (undefined8 *)(lVar7 * 0x10 + lVar2);
        do {
          if (((int)lVar8 == *(int *)(puVar5 + 1)) &&
             (iVar4 = memcmp((void *)*puVar5,_Buf2,(longlong)*(int *)(puVar5 + 1) * 2), iVar4 == 0))
          {
            *param_6 = *(undefined4 *)(lVar2 + 0xc + (longlong)iVar6 * 0x10);
            return 0;
          }
          iVar6 = iVar6 + -1;
          puVar5 = puVar5 + -2;
          lVar7 = lVar7 + -1;
        } while (-1 < lVar7);
      }
    }
    HVar3 = (**(code **)(*plVar1 + 0x50))(plVar1,param_3,param_4,param_6);
  }
  return HVar3;
}

/* ---- FUNC 00011DBE FUN_180011dbe (170 bytes) ---- */

undefined8 FUN_180011dbe(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  void *_Buf2;
  int iVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  int iVar5;
  longlong unaff_RBP;
  longlong lVar6;
  longlong lVar7;
  longlong *unaff_R12;
  int unaff_R13D;
  undefined4 *in_stack_00000078;
  
  lVar1 = *(longlong *)(unaff_RBP + 0x28);
  if ((lVar1 != 0) && (unaff_R13D == 1)) {
    _Buf2 = (void *)*param_3;
    if (_Buf2 == (void *)0x0) {
      lVar7 = 0;
    }
    else {
      lVar7 = -1;
      do {
        lVar7 = lVar7 + 1;
      } while (*(short *)((longlong)_Buf2 + lVar7 * 2) != 0);
    }
    iVar5 = *(int *)(unaff_RBP + 0x30) + -1;
    if (-1 < iVar5) {
      lVar6 = (longlong)iVar5;
      puVar4 = (undefined8 *)(lVar6 * 0x10 + lVar1);
      do {
        if (((int)lVar7 == *(int *)(puVar4 + 1)) &&
           (iVar2 = memcmp((void *)*puVar4,_Buf2,(longlong)*(int *)(puVar4 + 1) * 2), iVar2 == 0)) {
          *in_stack_00000078 = *(undefined4 *)(lVar1 + 0xc + (longlong)iVar5 * 0x10);
          return 0;
        }
        iVar5 = iVar5 + -1;
        puVar4 = puVar4 + -2;
        lVar6 = lVar6 + -1;
      } while (-1 < lVar6);
    }
  }
  uVar3 = (**(code **)(*unaff_R12 + 0x50))();
  return uVar3;
}

/* ---- FUNC 00011E68 FUN_180011e68 (11 bytes) ---- */

void FUN_180011e68(void)

{
  return;
}

/* ---- FUNC 00011E73 FUN_180011e73 (22 bytes) ---- */

undefined8 FUN_180011e73(void)

{
  int unaff_EBP;
  longlong unaff_R15;
  undefined4 *in_stack_00000078;
  
  *in_stack_00000078 = *(undefined4 *)(unaff_R15 + 0xc + (longlong)unaff_EBP * 0x10);
  return 0;
}

/* ---- FUNC 00011E90 FUN_180011e90 (25 bytes) ---- */

void FUN_180011e90(longlong param_1,undefined8 param_2,OLECHAR **param_3,UINT param_4,
                  undefined8 param_5,DISPID *param_6)

{
                    /* WARNING: Could not recover jumptable at 0x000180011ea2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DispGetIDsOfNames(*(ITypeInfo **)(param_1 + 0x10),param_3,param_4,param_6);
  return;
}

/* ---- FUNC 00011EB0 FUN_180011eb0 (177 bytes) ---- */

HRESULT FUN_180011eb0(longlong param_1,undefined8 param_2,OLECHAR **param_3,UINT param_4,
                     undefined8 param_5,DISPID *param_6)

{
  OLECHAR *pOVar1;
  HRESULT HVar2;
  longlong lVar3;
  
  HVar2 = DispGetIDsOfNames(*(ITypeInfo **)(param_1 + 8),param_3,param_4,param_6);
  if ((((HVar2 == -0x7ffdfffa) &&
       (HVar2 = DispGetIDsOfNames(*(ITypeInfo **)(param_1 + 0x280),param_3,param_4,param_6),
       HVar2 == -0x7ffdfffa)) && (param_4 != 0)) && (pOVar1 = *param_3, pOVar1 != (OLECHAR *)0x0)) {
    lVar3 = 0;
    do {
      if (pOVar1[lVar3] != L"GeneratePDF"[lVar3]) {
        return -0x7ffdfffa;
      }
      if (pOVar1[lVar3 + 1] != L"GeneratePDF"[lVar3 + 1]) {
        return -0x7ffdfffa;
      }
      lVar3 = lVar3 + 2;
    } while (lVar3 != 0xc);
    *param_6 = -0x55555556;
    HVar2 = 0;
  }
  return HVar2;
}

/* ---- FUNC 00011F70 FUN_180011f70 (798 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

ulonglong FUN_180011f70(longlong param_1,LPCWSTR param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  longlong lVar6;
  longlong *plVar7;
  undefined1 *puVar8;
  longlong lVar9;
  undefined1 *puVar10;
  int iVar11;
  undefined *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined8 uStack_70;
  undefined1 auStack_68 [32];
  undefined8 uStack_48;
  int aiStack_40 [2];
  undefined8 local_38 [2];
  undefined8 *local_28;
  ulonglong local_20;
  
  puVar13 = auStack_68;
  puVar10 = auStack_68;
  local_20 = DAT_180077818 ^ (ulonglong)&local_28;
  if (param_3 == (undefined8 *)0x0) {
    uVar4 = 0x80070057;
    puVar10 = auStack_68;
    goto LAB_18001226c;
  }
  puVar14 = (undefined1 *)0x0;
  puVar8 = puVar14;
  do {
    if ((param_2[(longlong)puVar8] != L"ApwnHostContainer"[(longlong)puVar8]) ||
       (param_2[(longlong)(puVar8 + 1)] != L"ApwnHostContainer"[(longlong)(puVar8 + 1)])) {
      lVar9 = -1;
      goto LAB_180012020;
    }
    puVar8 = puVar8 + 2;
  } while (puVar8 != (undefined1 *)0x12);
  if (DAT_180079800 != (longlong *)0x0) {
    uStack_70 = 0x180011ff6;
    (**(code **)(*DAT_180079800 + 8))();
    *param_3 = DAT_180079800;
    uVar4 = 0;
    puVar10 = auStack_68;
    goto LAB_18001226c;
  }
  goto LAB_1800120aa;
  while( true ) {
    lVar9 = lVar9 + 2;
    if (lVar9 == 0xf) {
      uStack_70 = 0x18001220c;
      plVar7 = FUN_18000f5a0(&local_28);
      if ((int)plVar7 != 0) goto LAB_18001216c;
      puVar12 = &DAT_1800635d0;
      puVar5 = (undefined8 *)*local_28;
      goto LAB_18001215a;
    }
    if (param_2[lVar9] != L"HNodeSelection"[lVar9]) break;
LAB_1800120e0:
    puVar10 = puVar14;
    if (param_2[lVar9 + 1] != L"HNodeSelection"[lVar9 + 1]) break;
  }
  do {
    if ((param_2[(longlong)puVar10] != L"HappConnectInfo"[(longlong)puVar10]) ||
       (param_2[(longlong)(puVar10 + 1)] != L"HappConnectInfo"[(longlong)(puVar10 + 1)]))
    goto LAB_18001216c;
    puVar10 = puVar10 + 2;
  } while (puVar10 != (undefined1 *)0x10);
  uStack_70 = 0x180012139;
  uVar4 = FUN_18000f670(&local_28);
  if ((int)uVar4 == 0) {
    uStack_70 = 0x18001214d;
    FUN_180030de0((longlong)local_28,*(undefined8 *)(param_1 + 8));
    puVar5 = (undefined8 *)*local_28;
    puVar12 = &DAT_1800635e0;
LAB_18001215a:
    uStack_70 = 0x18001215f;
    uVar3 = (*(code *)*puVar5)(local_28,puVar12,param_3);
    if (uVar3 == 0x80004002) goto LAB_18001216c;
  }
  else {
LAB_18001216c:
    local_28 = (undefined8 *)0x0;
    puVar10 = puVar14;
    puVar13 = auStack_68;
    if (param_2 != (LPCWSTR)0x0) {
      lVar9 = -1;
      do {
        lVar6 = lVar9;
        lVar9 = lVar6 + 1;
      } while (param_2[lVar9] != L'\0');
      iVar11 = (int)lVar6 + 2;
      puVar13 = auStack_68;
      if (iVar11 < 0x40000000) {
        lVar9 = (longlong)(int)lVar9 * 2;
        uVar4 = lVar9 + 0x11;
        if (uVar4 <= lVar9 + 2U) {
          uVar4 = 0xffffffffffffff0;
        }
        uStack_70 = 0x1800121c2;
        lVar9 = -(uVar4 & 0xfffffffffffffff0);
        puVar8 = (undefined1 *)((longlong)&local_28 + lVar9);
        puVar13 = auStack_68 + lVar9;
        if (puVar8 != (undefined1 *)0x0) {
          *(undefined8 *)((longlong)local_38 + lVar9 + 8) = 0;
          *(undefined8 *)((longlong)local_38 + lVar9) = 0;
          *(int *)((longlong)aiStack_40 + lVar9) = iVar11 * 2;
          *(undefined1 **)((longlong)&uStack_48 + lVar9) = puVar8;
          *puVar8 = 0;
          *(undefined8 *)(auStack_68 + lVar9 + -8) = 0x1800121fb;
          iVar11 = WideCharToMultiByte(0,0,param_2,-1,*(LPSTR *)((longlong)&uStack_48 + lVar9),
                                       *(int *)((longlong)aiStack_40 + lVar9),
                                       *(LPCSTR *)((longlong)local_38 + lVar9),
                                       *(LPBOOL *)((longlong)local_38 + lVar9 + 8));
          puVar10 = puVar8;
          puVar13 = auStack_68 + lVar9;
          if (iVar11 == 0) {
            puVar10 = puVar14;
            puVar13 = auStack_68 + lVar9;
          }
        }
      }
    }
    uVar1 = *(undefined8 *)(*(longlong *)(param_1 + 8) + 0x20);
    *(undefined8 *)(puVar13 + -8) = 0x180012242;
    uVar3 = HAGetService(uVar1,puVar10,param_3,&local_28);
    if (local_28 != (undefined8 *)0x0) {
      local_28 = (undefined8 *)0x0;
      pcVar2 = *(code **)(**(longlong **)(param_1 + 8) + 0x278);
      *(undefined8 *)(puVar13 + -8) = 0x18001225e;
      uVar3 = (*pcVar2)();
    }
    *(undefined8 *)(puVar13 + -8) = 0x18001226a;
    ReleaseErrorStruct(&local_28);
  }
  uVar4 = (ulonglong)uVar3;
  puVar10 = puVar13;
  goto LAB_18001226c;
  while( true ) {
    lVar9 = lVar9 + 2;
    if (lVar9 == 0x11) {
      if (DAT_180079800 == (longlong *)0x0) goto LAB_1800120aa;
      uStack_70 = 0x1800120a5;
      uVar4 = (**(code **)*DAT_180079800)(DAT_180079800,&DAT_1800635f0);
      goto LAB_18001226c;
    }
    if (param_2[lVar9] != L"ApwnSimContainer"[lVar9]) break;
LAB_180012020:
    puVar8 = puVar14;
    if (param_2[lVar9 + 1] != L"ApwnSimContainer"[lVar9 + 1]) break;
  }
  do {
    if ((param_2[(longlong)puVar8] != L"ApwnSafetyContainer"[(longlong)puVar8]) ||
       (param_2[(longlong)(puVar8 + 1)] != L"ApwnSafetyContainer"[(longlong)(puVar8 + 1)])) {
      plVar7 = *(longlong **)(param_1 + 8);
      if ((int)plVar7[3] != 0) {
        lVar9 = -1;
        goto LAB_1800120e0;
      }
      uStack_70 = 0x1800120cc;
      uVar4 = (**(code **)(*plVar7 + 0x280))(plVar7,0x7d2);
      puVar10 = auStack_68;
      goto LAB_18001226c;
    }
    puVar8 = puVar8 + 2;
  } while (puVar8 != (undefined1 *)0x14);
  if (DAT_180079800 != (longlong *)0x0) {
    uStack_70 = 0x180012088;
    uVar4 = (**(code **)*DAT_180079800)(DAT_180079800,&DAT_180063600);
    puVar10 = auStack_68;
    goto LAB_18001226c;
  }
LAB_1800120aa:
  uVar4 = 0x80004002;
  puVar10 = auStack_68;
LAB_18001226c:
  *(undefined8 *)(puVar10 + -8) = 0x180012278;
  return uVar4;
}

/* ---- FUNC 00012290 FUN_180012290 (77 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_180012290(longlong param_1,undefined4 param_2,undefined4 *param_3,undefined8 *param_4,
             undefined8 param_5)

{
  int cchWideChar;
  int iVar1;
  undefined8 uVar2;
  BSTR lpWideCharStr;
  undefined1 auStackY_c8 [32];
  undefined4 local_98 [4];
  CHAR local_88 [80];
  ulonglong local_38;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStackY_c8;
  if (DAT_1800797f8 == 0) {
    Ordinal_79(param_2,local_98,local_88,param_5);
    *param_3 = local_98[0];
    cchWideChar = MultiByteToWideChar(0,0,local_88,-1,(LPWSTR)0x0,0);
    lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,cchWideChar - 1);
    if ((lpWideCharStr != (BSTR)0x0) &&
       (iVar1 = MultiByteToWideChar(0,0,local_88,-1,lpWideCharStr,cchWideChar), iVar1 != cchWideChar
       )) {
      SysFreeString(lpWideCharStr);
      lpWideCharStr = (BSTR)0x0;
    }
    uVar2 = 0;
    *param_4 = lpWideCharStr;
  }
  else {
    uVar2 = (**(code **)(**(longlong **)(param_1 + 8) + 0x280))(*(longlong **)(param_1 + 8),0x7f3);
  }
  return uVar2;
}

/* ---- FUNC 000122DD FUN_1800122dd (157 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1800122dd(void)

{
  undefined4 in_EAX;
  int cchWideChar;
  int iVar1;
  BSTR lpWideCharStr;
  undefined4 *unaff_RBX;
  undefined8 *unaff_R14;
  undefined4 in_stack_00000030;
  
  Ordinal_79(in_EAX,&stack0x00000030,&stack0x00000040);
  *unaff_RBX = in_stack_00000030;
  cchWideChar = MultiByteToWideChar(0,0,&stack0x00000040,-1,(LPWSTR)0x0,0);
  lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,cchWideChar - 1);
  if ((lpWideCharStr != (BSTR)0x0) &&
     (iVar1 = MultiByteToWideChar(0,0,&stack0x00000040,-1,lpWideCharStr,cchWideChar),
     iVar1 != cchWideChar)) {
    SysFreeString(lpWideCharStr);
    lpWideCharStr = (BSTR)0x0;
  }
  *unaff_R14 = lpWideCharStr;
  return 0;
}

/* ---- FUNC 0001237A FUN_18001237a (27 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001237a(void)

{
  return;
}

/* ---- FUNC 000123A0 FUN_1800123a0 (1125 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

HRESULT FUN_1800123a0(undefined8 *param_1,LCID param_2)

{
  char *pcVar1;
  GUID *pGVar2;
  _func_6697 *p_Var3;
  _func_6603 *p_Var4;
  _func_6602 *p_Var5;
  code *pcVar6;
  _func_6604 *p_Var7;
  _func_6693 *p_Var8;
  longlong *plVar9;
  ITypeInfo *This;
  ITypeLib *pIVar10;
  undefined1 *puVar11;
  char cVar12;
  DWORD DVar13;
  int iVar14;
  HRESULT HVar15;
  HRESULT HVar16;
  longlong lVar17;
  ulonglong uVar19;
  LPCOLESTR pOVar20;
  undefined8 *puVar21;
  undefined8 uVar22;
  ITypeInfo *pIVar23;
  LPCOLESTR pOVar24;
  undefined1 *puVar25;
  undefined1 *puVar26;
  LPCOLESTR pOVar27;
  LPCOLESTR szFile;
  LPCOLESTR pOVar28;
  LPCRITICAL_SECTION lpCriticalSection;
  ulonglong uVar29;
  bool bVar30;
  undefined1 auStackY_1b8 [32];
  ITypeInfo *local_188;
  longlong *local_180;
  ITypeLib *local_178;
  ITypeInfo *local_170;
  longlong *local_168;
  longlong *local_160;
  LPCRITICAL_SECTION local_158;
  undefined1 local_150;
  CHAR local_148;
  char acStack_147 [271];
  ulonglong local_38;
  longlong lVar18;
  
  puVar25 = auStackY_1b8;
  puVar26 = auStackY_1b8;
  local_38 = DAT_180077818 ^ (ulonglong)&local_188;
  if ((param_1[3] != 0) && (param_1[5] != 0)) {
    HVar15 = 0;
    puVar26 = auStackY_1b8;
    goto LAB_1800127ce;
  }
  lpCriticalSection = (LPCRITICAL_SECTION)(DAT_180079320 + 0x18);
  local_158 = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  local_150 = 1;
  pOVar28 = (LPCOLESTR)0x0;
  puVar11 = auStackY_1b8;
  HVar15 = 0;
  if (param_1[3] == 0) {
    local_178 = (ITypeLib *)0x0;
    pGVar2 = (GUID *)param_1[1];
    if (((((DAT_180079328 != pGVar2->Data1) ||
          (iVar14._0_2_ = pGVar2->Data2, iVar14._2_2_ = pGVar2->Data3, DAT_18007932c != iVar14)) ||
         (DAT_180079330 != *(int *)pGVar2->Data4)) ||
        ((DAT_180079334 != *(int *)(pGVar2->Data4 + 4) || (*(short *)(param_1 + 2) != -1)))) ||
       (*(short *)((longlong)param_1 + 0x12) != -1)) {
      HVar15 = LoadRegTypeLib(pGVar2,*(WORD *)(param_1 + 2),*(WORD *)((longlong)param_1 + 0x12),
                              param_2,&local_178);
LAB_1800125f1:
      pIVar10 = local_178;
      puVar11 = puVar26;
      if (HVar15 < 0) goto LAB_1800127aa;
      local_170 = (ITypeInfo *)0x0;
      pGVar2 = (GUID *)*param_1;
      p_Var3 = local_178->lpVtbl->GetTypeInfoOfGuid;
      *(undefined8 *)(puVar26 + -8) = 0x18001260e;
      HVar15 = (*p_Var3)(pIVar10,pGVar2,&local_170);
      pIVar23 = local_170;
      if (-1 < HVar15) {
        local_188 = local_170;
        if (local_170 != (ITypeInfo *)0x0) {
          p_Var4 = local_170->lpVtbl->AddRef;
          *(undefined8 *)(puVar26 + -8) = 0x18001262b;
          (*p_Var4)(pIVar23);
        }
        pIVar23 = local_170;
        local_180 = (longlong *)0x0;
        p_Var5 = local_170->lpVtbl->QueryInterface;
        *(undefined8 *)(puVar26 + -8) = 0x180012643;
        HVar16 = (*p_Var5)(pIVar23,(IID *)&DAT_1800638f8,&local_180);
        plVar9 = local_180;
        pIVar23 = local_188;
        if (-1 < HVar16) {
          if (local_188 == (ITypeInfo *)0x0) {
            if (local_180 == (longlong *)0x0) goto LAB_180012704;
          }
          else if (local_180 != (longlong *)0x0) {
            local_168 = (longlong *)0x0;
            local_160 = (longlong *)0x0;
            p_Var5 = local_188->lpVtbl->QueryInterface;
            *(undefined8 *)(puVar26 + -8) = 0x18001267f;
            (*p_Var5)(pIVar23,(IID *)&DAT_180063898,&local_168);
            pcVar6 = *(code **)*plVar9;
            *(undefined8 *)(puVar26 + -8) = 0x180012692;
            (*pcVar6)(plVar9,&DAT_180063898,&local_160);
            plVar9 = local_160;
            bVar30 = local_168 == local_160;
            if (local_160 != (longlong *)0x0) {
              pcVar6 = *(code **)(*local_160 + 0x10);
              *(undefined8 *)(puVar26 + -8) = 0x1800126ae;
              (*pcVar6)(plVar9);
            }
            if (local_168 != (longlong *)0x0) {
              pcVar6 = *(code **)(*local_168 + 0x10);
              *(undefined8 *)(puVar26 + -8) = 0x1800126bd;
              (*pcVar6)();
            }
            pIVar23 = local_188;
            if (bVar30) goto LAB_180012704;
          }
          plVar9 = local_180;
          This = local_188;
          if (local_180 == (longlong *)0x0) {
LAB_1800126eb:
            local_188 = (ITypeInfo *)0x0;
          }
          else {
            pcVar6 = *(code **)*local_180;
            *(undefined8 *)(puVar26 + -8) = 0x1800126e1;
            iVar14 = (*pcVar6)(plVar9,&DAT_1800638e8,&local_188);
            if (iVar14 < 0) goto LAB_1800126eb;
          }
          pIVar23 = local_188;
          if (This != (ITypeInfo *)0x0) {
            p_Var7 = This->lpVtbl->Release;
            *(undefined8 *)(puVar26 + -8) = 0x180012700;
            (*p_Var7)(This);
            pIVar23 = local_188;
          }
        }
LAB_180012704:
        local_188 = (ITypeInfo *)0x0;
        param_1[3] = pIVar23;
        pOVar24 = (LPCOLESTR)(DAT_180079320 + 8);
        if (DAT_180079320 == 0) {
          pOVar24 = pOVar28;
        }
        if (pOVar24 != (LPCOLESTR)0x0) {
          *(undefined8 *)(puVar26 + -8) = 0x18001272d;
          puVar21 = operator_new(0x18);
          if (puVar21 != (undefined8 *)0x0) {
            *puVar21 = FUN_18000ee20;
            puVar21[1] = param_1;
            *(undefined8 *)(puVar26 + -8) = 0x18001274d;
            EnterCriticalSection((LPCRITICAL_SECTION)(pOVar24 + 8));
            puVar21[2] = *(undefined8 *)(pOVar24 + 4);
            *(undefined8 **)(pOVar24 + 4) = puVar21;
            *(undefined8 *)(puVar26 + -8) = 0x180012763;
            LeaveCriticalSection((LPCRITICAL_SECTION)(pOVar24 + 8));
          }
        }
        if (local_180 != (longlong *)0x0) {
          pcVar6 = *(code **)(*local_180 + 0x10);
          *(undefined8 *)(puVar26 + -8) = 0x180012776;
          (*pcVar6)();
        }
        pIVar23 = local_188;
        if (local_188 != (ITypeInfo *)0x0) {
          p_Var7 = local_188->lpVtbl->Release;
          *(undefined8 *)(puVar26 + -8) = 0x180012788;
          (*p_Var7)(pIVar23);
        }
      }
      pIVar10 = local_178;
      p_Var8 = local_178->lpVtbl->Release;
      *(undefined8 *)(puVar26 + -8) = 0x180012792;
      (*p_Var8)(pIVar10);
      pIVar23 = local_170;
      if (local_170 != (ITypeInfo *)0x0) {
        p_Var7 = local_170->lpVtbl->Release;
        *(undefined8 *)(puVar26 + -8) = 0x1800127a2;
        (*p_Var7)(pIVar23);
      }
      goto LAB_1800127aa;
    }
    DVar13 = GetModuleFileNameA(DAT_18007a618,&local_148,0x104);
    puVar11 = auStackY_1b8;
    HVar15 = -0x7fffbffb;
    if ((DVar13 == 0) || (puVar11 = auStackY_1b8, DVar13 == 0x104)) goto LAB_1800127aa;
    pOVar24 = (LPCOLESTR)0x0;
    local_160 = (longlong *)0x0;
    lVar18 = -1;
    do {
      lVar17 = lVar18 + 1;
      pcVar1 = acStack_147 + lVar18;
      lVar18 = lVar17;
    } while (*pcVar1 != '\0');
    lVar18 = (longlong)((int)lVar17 + 1) * 2;
    pOVar20 = pOVar28;
    puVar26 = auStackY_1b8;
    szFile = pOVar28;
    if (lVar18 + 0x80000000U < 0x100000000) {
      iVar14 = (int)lVar18;
      uVar29 = (ulonglong)iVar14;
      if ((iVar14 < 0x401) && (cVar12 = FUN_1800026d0(uVar29), cVar12 != '\0')) {
        uVar19 = uVar29 + 0xf;
        if (uVar19 <= uVar29) {
          uVar19 = 0xffffffffffffff0;
        }
        pOVar24 = pOVar28;
        puVar25 = auStackY_1b8 + -(uVar19 & 0xfffffffffffffff0);
        pOVar27 = (LPCOLESTR)((longlong)&local_188 + -(uVar19 & 0xfffffffffffffff0));
      }
      else {
        if (~uVar29 < 0x10) {
                    /* WARNING: Subroutine does not return */
          FUN_180001a90(-0x7ff8fdea);
        }
        pOVar20 = malloc(uVar29 + 0x10);
        pOVar27 = pOVar28;
        if (pOVar20 != (LPCOLESTR)0x0) {
          pOVar20[0] = L'\0';
          pOVar20[1] = L'\0';
          pOVar20[2] = L'\0';
          pOVar20[3] = L'\0';
          pOVar24 = pOVar20;
          puVar25 = auStackY_1b8;
          pOVar27 = pOVar20 + 8;
        }
      }
      pOVar20 = pOVar24;
      puVar26 = puVar25;
      if (pOVar27 != (LPCOLESTR)0x0) {
        *pOVar27 = L'\0';
        *(int *)(puVar25 + 0x28) = (int)(uVar29 >> 1);
        *(LPCOLESTR *)(puVar25 + 0x20) = pOVar27;
        *(undefined8 *)(puVar25 + -8) = 0x18001257b;
        iVar14 = MultiByteToWideChar(0,0,&local_148,-1,*(LPWSTR *)(puVar25 + 0x20),
                                     *(int *)(puVar25 + 0x28));
        szFile = pOVar27;
        if (iVar14 == 0) {
          szFile = pOVar28;
        }
      }
    }
    if (szFile != (LPCOLESTR)0x0) {
      *(undefined8 *)(puVar26 + -8) = 0x1800125b8;
      HVar15 = LoadTypeLib(szFile,&local_178);
      while (pOVar20 != (LPCOLESTR)0x0) {
        pOVar24 = *(LPCOLESTR *)pOVar20;
        *(undefined8 *)(puVar26 + -8) = 0x1800125cc;
        free(pOVar20);
        pOVar20 = pOVar24;
      }
      goto LAB_1800125f1;
    }
    while (pOVar20 != (LPCOLESTR)0x0) {
      pOVar28 = *(LPCOLESTR *)pOVar20;
      *(undefined8 *)(puVar26 + -8) = 0x18001259c;
      free(pOVar20);
      pOVar20 = pOVar28;
    }
    HVar15 = -0x7ff8fff2;
  }
  else {
LAB_1800127aa:
    puVar26 = puVar11;
    plVar9 = (longlong *)param_1[3];
    if ((plVar9 != (longlong *)0x0) && (param_1[5] == 0)) {
      *(undefined8 *)(puVar26 + -8) = 0x1800127c1;
      uVar22 = FUN_180018c50((longlong)param_1,plVar9);
      HVar15 = (HRESULT)uVar22;
    }
  }
  *(undefined8 *)(puVar26 + -8) = 0x1800127cc;
  LeaveCriticalSection(lpCriticalSection);
LAB_1800127ce:
  *(undefined8 *)(puVar26 + -8) = 0x1800127dd;
  return HVar15;
}

/* ---- FUNC 00012810 FUN_180012810 (105 bytes) ---- */

HRESULT FUN_180012810(undefined8 param_1,int param_2,LCID param_3,undefined8 *param_4)

{
  HRESULT HVar1;
  
  if (param_2 != 0) {
    return -0x7ffdfff5;
  }
  if (param_4 == (undefined8 *)0x0) {
    return -0x7fffbffd;
  }
  HVar1 = 0;
  if (DAT_180077678 == (longlong *)0x0) {
    HVar1 = FUN_1800123a0(&PTR_DAT_180077660,param_3);
  }
  *param_4 = DAT_180077678;
  if (DAT_180077678 != (longlong *)0x0) {
    (**(code **)(*DAT_180077678 + 8))();
    HVar1 = 0;
  }
  return HVar1;
}

/* ---- FUNC 00012880 FUN_180012880 (105 bytes) ---- */

HRESULT FUN_180012880(undefined8 param_1,int param_2,LCID param_3,undefined8 *param_4)

{
  HRESULT HVar1;
  
  if (param_2 != 0) {
    return -0x7ffdfff5;
  }
  if (param_4 == (undefined8 *)0x0) {
    return -0x7fffbffd;
  }
  HVar1 = 0;
  if (DAT_1800776b0 == (longlong *)0x0) {
    HVar1 = FUN_1800123a0(&PTR_DAT_180077698,param_3);
  }
  *param_4 = DAT_1800776b0;
  if (DAT_1800776b0 != (longlong *)0x0) {
    (**(code **)(*DAT_1800776b0 + 8))();
    HVar1 = 0;
  }
  return HVar1;
}

/* ---- FUNC 000128F0 FUN_1800128f0 (73 bytes) ---- */

undefined8 FUN_1800128f0(longlong param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  *param_4 = 0;
  if (param_2 != 0) {
    return 0x8002000b;
  }
  (**(code **)(**(longlong **)(param_1 + 0x10) + 8))();
  *param_4 = *(undefined8 *)(param_1 + 0x10);
  return 0;
}

/* ---- FUNC 00012940 FUN_180012940 (73 bytes) ---- */

undefined8 FUN_180012940(longlong param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  *param_4 = 0;
  if (param_2 != 0) {
    return 0x8002000b;
  }
  (**(code **)(**(longlong **)(param_1 + 8) + 8))();
  *param_4 = *(undefined8 *)(param_1 + 8);
  return 0;
}

/* ---- FUNC 00012990 FUN_180012990 (20 bytes) ---- */

undefined8 FUN_180012990(undefined8 param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = 1;
  return 0;
}

/* ---- FUNC 000129B0 FUN_1800129b0 (14 bytes) ---- */

undefined8 FUN_1800129b0(undefined8 param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 1;
  }
  return 0;
}

/* ---- FUNC 000129C0 FUN_1800129c0 (4019 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

char * FUN_1800129c0(longlong *param_1,VARIANTARG *param_2,VARIANTARG *param_3,VARIANTARG *param_4,
                    VARIANTARG *param_5,VARIANTARG *param_6,VARIANTARG *param_7,uint *param_8)

{
  char *pcVar1;
  ushort uVar2;
  VARTYPE VVar3;
  undefined8 *puVar4;
  undefined4 *puVar5;
  code *pcVar6;
  HRESULT HVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  longlong lVar11;
  longlong lVar12;
  ulonglong uVar13;
  int iVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined4 uVar17;
  char *pcVar18;
  LPCWSTR pWVar19;
  undefined4 uVar20;
  undefined8 uStackY_1a0;
  undefined1 auStackY_198 [32];
  uint local_158 [2];
  VARIANTARG local_150;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_138 [8];
  undefined8 local_130;
  undefined8 local_128;
  undefined8 local_120;
  undefined8 local_118 [2];
  _union_2707 local_108;
  _union_2707 local_e8;
  _union_2707 local_c8;
  _union_2707 local_a8;
  _union_2707 local_88;
  _union_2707 local_68;
  VARIANTARG *local_48;
  char *local_40;
  ulonglong local_38;
  
  puVar15 = auStackY_198;
  local_38 = DAT_180077818 ^ (ulonglong)local_158;
  pcVar10 = (char *)0x0;
  local_158[0] = 0;
  uStackY_1a0 = 0x180012a1e;
  local_48 = param_4;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_118);
  uStackY_1a0 = 0x180012a29;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_120);
  uStackY_1a0 = 0x180012a34;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_128);
  uStackY_1a0 = 0x180012a3f;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_130);
  uStackY_1a0 = 0x180012a4a;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_138);
  *param_8 = 0;
  uStackY_1a0 = 0x180012a5e;
  VariantInit(&local_150);
  if ((param_2->n1).n2.vt == 0x400c) {
    local_108._0_8_ = *(undefined8 *)&param_7->n1;
    local_108.decVal.u2 = (param_7->n1).decVal.u2;
    local_108._16_8_ = *(undefined8 *)((longlong)&param_7->n1 + 0x10);
    local_e8._0_8_ = *(undefined8 *)&param_6->n1;
    local_e8.decVal.u2 = (param_6->n1).decVal.u2;
    local_e8._16_8_ = *(undefined8 *)((longlong)&param_6->n1 + 0x10);
    local_c8._0_8_ = *(undefined8 *)&param_5->n1;
    local_c8.decVal.u2 = (param_5->n1).decVal.u2;
    local_c8._16_8_ = *(undefined8 *)((longlong)&param_5->n1 + 0x10);
    local_a8._0_8_ = *(undefined8 *)&param_4->n1;
    local_a8.decVal.u2 = (param_4->n1).decVal.u2;
    local_a8._16_8_ = *(undefined8 *)((longlong)&param_4->n1 + 0x10);
    local_88._0_8_ = *(undefined8 *)&param_3->n1;
    local_88.decVal.u2 = (param_3->n1).decVal.u2;
    local_88._16_8_ = *(undefined8 *)((longlong)&param_3->n1 + 0x10);
    puVar4 = *(undefined8 **)((longlong)&param_2->n1 + 8);
    local_68._0_8_ = *puVar4;
    local_68.decVal.u2 = *(_union_1719 *)(puVar4 + 1);
    local_68._16_8_ = puVar4[2];
    uStackY_1a0 = 0x180012b4d;
    pcVar10 = FUN_1800129c0(param_1,(VARIANTARG *)&local_68.n2,(VARIANTARG *)&local_88.n2,
                            (VARIANTARG *)&local_a8.n2,(VARIANTARG *)&local_c8.n2,
                            (VARIANTARG *)&local_e8.n2,(VARIANTARG *)&local_108.n2,param_8);
    pcVar10 = (char *)((ulonglong)pcVar10 & 0xffffffff);
    puVar16 = auStackY_198;
    goto switchD_180012ea0_caseD_0;
  }
  if ((param_3->n1).n2.vt == 0x400c) {
    local_68._0_8_ = *(undefined8 *)&param_7->n1;
    local_68.decVal.u2 = (param_7->n1).decVal.u2;
    local_68._16_8_ = *(undefined8 *)((longlong)&param_7->n1 + 0x10);
    local_88._0_8_ = *(undefined8 *)&param_6->n1;
    local_88.decVal.u2 = (param_6->n1).decVal.u2;
    local_88._16_8_ = *(undefined8 *)((longlong)&param_6->n1 + 0x10);
    local_a8._0_8_ = *(undefined8 *)&param_5->n1;
    local_a8.decVal.u2 = (param_5->n1).decVal.u2;
    local_a8._16_8_ = *(undefined8 *)((longlong)&param_5->n1 + 0x10);
    local_c8._0_8_ = *(undefined8 *)&param_4->n1;
    local_c8.decVal.u2 = (param_4->n1).decVal.u2;
    local_c8._16_8_ = *(undefined8 *)((longlong)&param_4->n1 + 0x10);
    puVar5 = *(undefined4 **)((longlong)&param_3->n1 + 8);
    local_e8._0_4_ = *puVar5;
    local_e8.decVal.Hi32 = puVar5[1];
    local_e8._8_4_ = puVar5[2];
    local_e8._12_4_ = puVar5[3];
    local_e8._16_8_ = *(undefined8 *)(puVar5 + 4);
LAB_180012d6a:
    local_108._0_8_ = *(undefined8 *)&param_2->n1;
    local_108.decVal.u2 = (param_2->n1).decVal.u2;
    local_108._16_8_ = *(undefined8 *)((longlong)&param_2->n1 + 0x10);
    uStackY_1a0 = 0x180012dc7;
    pcVar10 = FUN_1800129c0(param_1,(VARIANTARG *)&local_108.n2,(VARIANTARG *)&local_e8.n2,
                            (VARIANTARG *)&local_c8.n2,(VARIANTARG *)&local_a8.n2,
                            (VARIANTARG *)&local_88.n2,(VARIANTARG *)&local_68.n2,param_8);
    pcVar10 = (char *)((ulonglong)pcVar10 & 0xffffffff);
    puVar16 = auStackY_198;
    goto switchD_180012ea0_caseD_0;
  }
  if ((param_4->n1).n2.vt == 0x400c) {
    local_68._0_8_ = *(undefined8 *)&param_7->n1;
    local_68.decVal.u2 = (param_7->n1).decVal.u2;
    local_68._16_8_ = *(undefined8 *)((longlong)&param_7->n1 + 0x10);
    local_88._0_8_ = *(undefined8 *)&param_6->n1;
    local_88.decVal.u2 = (param_6->n1).decVal.u2;
    local_88._16_8_ = *(undefined8 *)((longlong)&param_6->n1 + 0x10);
    local_a8._0_8_ = *(undefined8 *)&param_5->n1;
    local_a8.decVal.u2 = (param_5->n1).decVal.u2;
    local_a8._16_8_ = *(undefined8 *)((longlong)&param_5->n1 + 0x10);
    puVar5 = *(undefined4 **)((longlong)&param_4->n1 + 8);
    local_c8._0_4_ = *puVar5;
    local_c8.decVal.Hi32 = puVar5[1];
    local_c8._8_4_ = puVar5[2];
    local_c8._12_4_ = puVar5[3];
    local_c8._16_8_ = *(undefined8 *)(puVar5 + 4);
LAB_180012d50:
    local_e8._0_4_ = *(undefined4 *)&param_3->n1;
    local_e8.decVal.Hi32 = (param_3->n1).decVal.Hi32;
    local_e8._8_4_ = *(undefined4 *)((longlong)&param_3->n1 + 8);
    local_e8._12_4_ = *(undefined4 *)((longlong)&param_3->n1 + 0xc);
    local_e8._16_8_ = *(undefined8 *)((longlong)&param_3->n1 + 0x10);
    goto LAB_180012d6a;
  }
  if ((param_5->n1).n2.vt == 0x400c) {
    local_68._0_8_ = *(undefined8 *)&param_7->n1;
    local_68.decVal.u2 = (param_7->n1).decVal.u2;
    local_68._16_8_ = *(undefined8 *)((longlong)&param_7->n1 + 0x10);
    local_88._0_8_ = *(undefined8 *)&param_6->n1;
    local_88.decVal.u2 = (param_6->n1).decVal.u2;
    local_88._16_8_ = *(undefined8 *)((longlong)&param_6->n1 + 0x10);
    puVar5 = *(undefined4 **)((longlong)&param_5->n1 + 8);
    local_a8._0_4_ = *puVar5;
    local_a8.decVal.Hi32 = puVar5[1];
    local_a8._8_4_ = puVar5[2];
    local_a8._12_4_ = puVar5[3];
    local_a8._16_8_ = *(undefined8 *)(puVar5 + 4);
LAB_180012d37:
    local_c8._0_4_ = *(undefined4 *)&param_4->n1;
    local_c8.decVal.Hi32 = (param_4->n1).decVal.Hi32;
    local_c8._8_4_ = *(undefined4 *)((longlong)&param_4->n1 + 8);
    local_c8._12_4_ = *(undefined4 *)((longlong)&param_4->n1 + 0xc);
    local_c8._16_8_ = *(undefined8 *)((longlong)&param_4->n1 + 0x10);
    goto LAB_180012d50;
  }
  if ((param_6->n1).n2.vt == 0x400c) {
    local_68._0_8_ = *(undefined8 *)&param_7->n1;
    local_68.decVal.u2 = (param_7->n1).decVal.u2;
    local_68._16_8_ = *(undefined8 *)((longlong)&param_7->n1 + 0x10);
    puVar5 = *(undefined4 **)((longlong)&param_6->n1 + 8);
    local_88._0_4_ = *puVar5;
    local_88.decVal.Hi32 = puVar5[1];
    local_88._8_4_ = puVar5[2];
    local_88._12_4_ = puVar5[3];
    local_88._16_8_ = *(undefined8 *)(puVar5 + 4);
LAB_180012d20:
    local_a8._0_4_ = *(undefined4 *)&param_5->n1;
    local_a8.decVal.Hi32 = (param_5->n1).decVal.Hi32;
    local_a8._8_4_ = *(undefined4 *)((longlong)&param_5->n1 + 8);
    local_a8._12_4_ = *(undefined4 *)((longlong)&param_5->n1 + 0xc);
    local_a8._16_8_ = *(undefined8 *)((longlong)&param_5->n1 + 0x10);
    goto LAB_180012d37;
  }
  uVar2 = (param_7->n1).n2.vt;
  if (uVar2 == 0x400c) {
    puVar4 = *(undefined8 **)((longlong)&param_7->n1 + 8);
    local_68._0_8_ = *puVar4;
    local_68.decVal.u2 = *(_union_1719 *)(puVar4 + 1);
    local_68._16_8_ = puVar4[2];
    local_88._0_4_ = *(undefined4 *)&param_6->n1;
    local_88.decVal.Hi32 = (param_6->n1).decVal.Hi32;
    local_88._8_4_ = *(undefined4 *)((longlong)&param_6->n1 + 8);
    local_88._12_4_ = *(undefined4 *)((longlong)&param_6->n1 + 0xc);
    local_88._16_8_ = *(undefined8 *)((longlong)&param_6->n1 + 0x10);
    goto LAB_180012d20;
  }
  if (uVar2 < 0x4003) {
    if (uVar2 == 0x4002) {
      uVar20 = (int)**(short **)((longlong)&param_7->n1 + 8);
    }
    else {
      switch(uVar2) {
      case 0:
      case 1:
      case 10:
        uVar20 = 0;
        break;
      case 2:
        uVar20 = (int)*(short *)((longlong)&param_7->n1 + 8);
        break;
      case 3:
        uVar20 = *(uint *)((longlong)&param_7->n1 + 8);
        break;
      default:
        goto switchD_180012df1_caseD_4;
      case 0xb:
        uVar20 = (uint)(*(short *)((longlong)&param_7->n1 + 8) != 0);
      }
    }
LAB_180012e6a:
    *param_8 = uVar20;
    uVar2 = (param_2->n1).n2.vt;
    uVar9 = 0;
    if (0x4002 < uVar2) {
      if (uVar2 == 0x4003) {
        puVar15 = auStackY_198;
        uVar17 = **(uint **)((longlong)&param_2->n1 + 8);
      }
      else if (uVar2 == 0x4008) {
        uStackY_1a0 = 0x180013136;
        uVar8 = Ordinal_82();
        pWVar19 = (LPCWSTR)**(undefined8 **)((longlong)&param_2->n1 + 8);
        puVar15 = auStackY_198;
        pcVar18 = pcVar10;
        if (pWVar19 != (LPCWSTR)0x0) {
          lVar11 = -1;
          do {
            lVar12 = lVar11;
            lVar11 = lVar12 + 1;
          } while (pWVar19[lVar11] != L'\0');
          iVar14 = (int)lVar12 + 2;
          puVar15 = auStackY_198;
          if (iVar14 < 0x40000000) {
            lVar11 = (longlong)(int)lVar11 * 2;
            uVar13 = lVar11 + 0x11;
            if (uVar13 <= lVar11 + 2U) {
              uVar13 = 0xffffffffffffff0;
            }
            uStackY_1a0 = 0x180013188;
            lVar11 = -(uVar13 & 0xfffffffffffffff0);
            pcVar1 = (char *)((longlong)local_158 + lVar11);
            puVar15 = auStackY_198 + lVar11;
            if (pcVar1 != (char *)0x0) {
              *pcVar1 = '\0';
              *(undefined8 *)(&stack0xfffffffffffffea0 + lVar11) = 0;
              *(undefined8 *)(&stack0xfffffffffffffe98 + lVar11) = 0;
              *(int *)(&stack0xfffffffffffffe90 + lVar11) = iVar14 * 2;
              *(char **)((longlong)local_158 + lVar11 + -0x20) = pcVar1;
              *(undefined8 *)(auStackY_198 + lVar11 + -8) = 0x1800131bc;
              iVar14 = WideCharToMultiByte(0,0,pWVar19,-1,
                                           *(LPSTR *)((longlong)local_158 + lVar11 + -0x20),
                                           *(int *)(&stack0xfffffffffffffe90 + lVar11),
                                           *(LPCSTR *)(&stack0xfffffffffffffe98 + lVar11),
                                           *(LPBOOL *)(&stack0xfffffffffffffea0 + lVar11));
              puVar15 = auStackY_198 + lVar11;
              pcVar18 = pcVar1;
              if (iVar14 == 0) {
                puVar15 = auStackY_198 + lVar11;
                pcVar18 = pcVar10;
              }
            }
          }
        }
        *(undefined8 *)(puVar15 + -8) = 0x1800131d4;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  (local_138,pcVar18);
        pcVar18 = pcVar10;
        if (0 < (int)uVar8) {
          do {
            *(undefined8 *)(puVar15 + 0x20) = 0;
            uVar9 = (uint)pcVar18;
            *(undefined8 *)(puVar15 + -8) = 0x1800131f8;
            Ordinal_83(pcVar18,0,&local_40,0);
            pcVar18 = local_40;
            *(undefined8 *)(puVar15 + -8) = 0x180013209;
            iVar14 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                     CompareNoCase(local_138,pcVar18);
            if (iVar14 == 0) {
              local_158[0] = uVar9;
              break;
            }
            uVar9 = uVar9 + 1;
            pcVar18 = (char *)(ulonglong)uVar9;
          } while ((int)uVar9 < (int)uVar8);
        }
        param_4 = local_48;
        uVar17 = local_158[0];
        if (uVar9 == uVar8) {
          *(undefined8 *)(puVar15 + -8) = 0x180013238;
          HVar7 = VariantChangeType(&local_150,param_2,0,3);
          param_4 = local_48;
          uVar17 = local_150.n1._8_4_;
          if (HVar7 != 0) goto LAB_180013754;
        }
      }
      else {
        if (uVar2 != 0x400b) goto switchD_180012ea0_caseD_4;
        local_158[0] = (uint)(**(short **)((longlong)&param_2->n1 + 8) != 0);
        puVar15 = auStackY_198;
        uVar17 = local_158[0];
      }
      goto LAB_180012fe6;
    }
    if (uVar2 == 0x4002) {
      local_158[0] = (int)**(short **)((longlong)&param_2->n1 + 8);
      puVar15 = auStackY_198;
      uVar17 = local_158[0];
      goto LAB_180012fe6;
    }
    puVar16 = auStackY_198;
    switch(uVar2) {
    case 0:
    case 1:
    case 10:
      goto switchD_180012ea0_caseD_0;
    case 2:
      local_158[0] = (int)*(short *)((longlong)&param_2->n1 + 8);
      uVar17 = local_158[0];
      break;
    case 3:
      local_158[0] = *(uint *)((longlong)&param_2->n1 + 8);
      puVar15 = auStackY_198;
      uVar17 = local_158[0];
      break;
    default:
switchD_180012ea0_caseD_4:
      uStackY_1a0 = 0x18001310a;
      HVar7 = VariantChangeType(&local_150,param_2,0,3);
      puVar15 = auStackY_198;
      if (HVar7 == 0) {
        local_158[0] = local_150.n1._8_4_;
        puVar15 = auStackY_198;
        uVar17 = local_158[0];
        break;
      }
      goto LAB_180013754;
    case 8:
      uStackY_1a0 = 0x180012ecf;
      uVar8 = Ordinal_82();
      pWVar19 = *(LPCWSTR *)((longlong)&param_2->n1 + 8);
      puVar15 = auStackY_198;
      pcVar18 = pcVar10;
      if (pWVar19 != (LPCWSTR)0x0) {
        lVar11 = -1;
        do {
          lVar12 = lVar11;
          lVar11 = lVar12 + 1;
        } while (pWVar19[lVar11] != L'\0');
        iVar14 = (int)lVar12 + 2;
        puVar15 = auStackY_198;
        if (iVar14 < 0x40000000) {
          lVar11 = (longlong)(int)lVar11 * 2;
          uVar13 = lVar11 + 0x11;
          if (uVar13 <= lVar11 + 2U) {
            uVar13 = 0xffffffffffffff0;
          }
          uStackY_1a0 = 0x180012f1a;
          lVar11 = -(uVar13 & 0xfffffffffffffff0);
          pcVar1 = (char *)((longlong)local_158 + lVar11);
          puVar15 = auStackY_198 + lVar11;
          if (pcVar1 != (char *)0x0) {
            *pcVar1 = '\0';
            *(undefined8 *)(&stack0xfffffffffffffea0 + lVar11) = 0;
            *(undefined8 *)(&stack0xfffffffffffffe98 + lVar11) = 0;
            *(int *)(&stack0xfffffffffffffe90 + lVar11) = iVar14 * 2;
            *(char **)((longlong)local_158 + lVar11 + -0x20) = pcVar1;
            *(undefined8 *)(auStackY_198 + lVar11 + -8) = 0x180012f4e;
            iVar14 = WideCharToMultiByte(0,0,pWVar19,-1,
                                         *(LPSTR *)((longlong)local_158 + lVar11 + -0x20),
                                         *(int *)(&stack0xfffffffffffffe90 + lVar11),
                                         *(LPCSTR *)(&stack0xfffffffffffffe98 + lVar11),
                                         *(LPBOOL *)(&stack0xfffffffffffffea0 + lVar11));
            puVar15 = auStackY_198 + lVar11;
            pcVar18 = pcVar1;
            if (iVar14 == 0) {
              puVar15 = auStackY_198 + lVar11;
              pcVar18 = pcVar10;
            }
          }
        }
      }
      *(undefined8 *)(puVar15 + -8) = 0x180012f66;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                (local_138,pcVar18);
      pcVar18 = pcVar10;
      if (0 < (int)uVar8) {
        do {
          *(undefined8 *)(puVar15 + 0x20) = 0;
          uVar9 = (uint)pcVar18;
          *(undefined8 *)(puVar15 + -8) = 0x180012f88;
          Ordinal_83(pcVar18,0,&local_40,0);
          pcVar18 = local_40;
          *(undefined8 *)(puVar15 + -8) = 0x180012f99;
          iVar14 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                             (local_138,pcVar18);
          if (iVar14 == 0) {
            local_158[0] = uVar9;
            break;
          }
          uVar9 = uVar9 + 1;
          pcVar18 = (char *)(ulonglong)uVar9;
        } while ((int)uVar9 < (int)uVar8);
      }
      param_4 = local_48;
      uVar17 = local_158[0];
      if (uVar9 == uVar8) {
        *(undefined8 *)(puVar15 + -8) = 0x180012fc4;
        HVar7 = VariantChangeType(&local_150,param_2,0,3);
        if (HVar7 != 0) goto LAB_180013754;
        local_158[0] = local_150.n1._8_4_;
        param_4 = local_48;
        uVar17 = local_158[0];
      }
      break;
    case 0xb:
      local_158[0] = (uint)(*(short *)((longlong)&param_2->n1 + 8) != 0);
      puVar15 = auStackY_198;
      uVar17 = local_158[0];
    }
LAB_180012fe6:
    VVar3 = (param_3->n1).n2.vt;
    puVar16 = puVar15;
    if ((VVar3 == 0) || (VVar3 == 1)) {
LAB_180013344:
      VVar3 = (param_4->n1).n2.vt;
      if ((VVar3 != 0) && (VVar3 != 1)) {
        puVar15 = puVar16;
        if (VVar3 == 8) {
          pWVar19 = *(LPCWSTR *)((longlong)&param_4->n1 + 8);
          if (pWVar19 != (LPCWSTR)0x0) {
            lVar11 = -1;
            do {
              lVar11 = lVar11 + 1;
            } while (pWVar19[lVar11] != L'\0');
LAB_18001347b:
            iVar14 = (int)lVar11 + 1;
            if (iVar14 < 0x40000000) {
              lVar11 = (longlong)(int)lVar11 * 2;
              uVar13 = lVar11 + 0x11;
              if (uVar13 <= lVar11 + 2U) {
                uVar13 = 0xffffffffffffff0;
              }
              *(undefined8 *)(puVar16 + -8) = 0x1800134b2;
              lVar11 = -(uVar13 & 0xfffffffffffffff0);
              pcVar18 = puVar16 + lVar11 + 0x40;
              puVar15 = puVar16 + lVar11;
              if (pcVar18 != (char *)0x0) {
                *pcVar18 = '\0';
                *(undefined8 *)(puVar16 + lVar11 + 0x38) = 0;
                *(undefined8 *)(puVar16 + lVar11 + 0x30) = 0;
                *(int *)(puVar16 + lVar11 + 0x28) = iVar14 * 2;
                *(char **)(puVar16 + lVar11 + 0x20) = pcVar18;
                *(undefined8 *)(puVar16 + lVar11 + -8) = 0x1800134e6;
                iVar14 = WideCharToMultiByte(0,0,pWVar19,-1,*(LPSTR *)(puVar16 + lVar11 + 0x20),
                                             *(int *)(puVar16 + lVar11 + 0x28),
                                             *(LPCSTR *)(puVar16 + lVar11 + 0x30),
                                             *(LPBOOL *)(puVar16 + lVar11 + 0x38));
                if (iVar14 == 0) {
                  pcVar18 = pcVar10;
                }
                *(undefined8 *)(puVar16 + lVar11 + -8) = 0x1800134f9;
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_120,pcVar18);
                puVar16 = puVar16 + lVar11;
                goto LAB_18001354a;
              }
            }
          }
LAB_180013505:
          puVar16 = puVar15;
          *(undefined8 *)(puVar16 + -8) = 0x180013515;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_120,
                     (char *)0x0);
        }
        else if (VVar3 != 10) {
          if (VVar3 == 0x4008) {
            pWVar19 = (LPCWSTR)**(longlong **)((longlong)&param_4->n1 + 8);
            if (pWVar19 != (LPCWSTR)0x0) {
              lVar11 = -1;
              do {
                lVar11 = lVar11 + 1;
              } while (pWVar19[lVar11] != L'\0');
              goto LAB_18001347b;
            }
            goto LAB_180013505;
          }
          *(undefined8 *)(puVar16 + -8) = 0x18001338d;
          HVar7 = VariantChangeType(&local_150,param_4,0,8);
          if (HVar7 < 0) goto LAB_180013754;
          pWVar19 = (LPCWSTR)CONCAT44(local_150.n1._12_4_,local_150.n1._8_4_);
          pcVar18 = pcVar10;
          if (pWVar19 != (LPCWSTR)0x0) {
            lVar11 = -1;
            do {
              lVar12 = lVar11;
              lVar11 = lVar12 + 1;
            } while (pWVar19[lVar11] != L'\0');
            iVar14 = (int)lVar12 + 2;
            if (iVar14 < 0x40000000) {
              lVar11 = (longlong)(int)lVar11 * 2;
              uVar13 = lVar11 + 0x11;
              if (uVar13 <= lVar11 + 2U) {
                uVar13 = 0xffffffffffffff0;
              }
              *(undefined8 *)(puVar16 + -8) = 0x1800133f2;
              lVar11 = -(uVar13 & 0xfffffffffffffff0);
              pcVar1 = puVar16 + lVar11 + 0x40;
              puVar15 = puVar16 + lVar11;
              if (pcVar1 != (char *)0x0) {
                *pcVar1 = '\0';
                *(undefined8 *)(puVar16 + lVar11 + 0x38) = 0;
                *(undefined8 *)(puVar16 + lVar11 + 0x30) = 0;
                *(int *)(puVar16 + lVar11 + 0x28) = iVar14 * 2;
                *(char **)(puVar16 + lVar11 + 0x20) = pcVar1;
                *(undefined8 *)(puVar16 + lVar11 + -8) = 0x180013426;
                iVar14 = WideCharToMultiByte(0,0,pWVar19,-1,*(LPSTR *)(puVar16 + lVar11 + 0x20),
                                             *(int *)(puVar16 + lVar11 + 0x28),
                                             *(LPCSTR *)(puVar16 + lVar11 + 0x30),
                                             *(LPBOOL *)(puVar16 + lVar11 + 0x38));
                puVar15 = puVar16 + lVar11;
                pcVar18 = pcVar1;
                if (iVar14 == 0) {
                  puVar15 = puVar16 + lVar11;
                  pcVar18 = pcVar10;
                }
              }
            }
          }
          *(undefined8 *)(puVar15 + -8) = 0x180013448;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_120,
                     pcVar18);
          *(undefined8 *)(puVar15 + -8) = 0x180013452;
          VariantClear(&local_150);
          puVar16 = puVar15;
        }
      }
LAB_18001354a:
      VVar3 = (param_5->n1).n2.vt;
      puVar15 = puVar16;
      if ((VVar3 != 0) && (VVar3 != 1)) {
        pcVar18 = pcVar10;
        if (VVar3 == 8) {
          pWVar19 = *(LPCWSTR *)((longlong)&param_5->n1 + 8);
          if (pWVar19 != (LPCWSTR)0x0) {
            lVar11 = -1;
            do {
              lVar11 = lVar11 + 1;
            } while (pWVar19[lVar11] != L'\0');
LAB_18001368b:
            iVar14 = (int)lVar11 + 1;
            if (iVar14 < 0x40000000) {
              lVar11 = (longlong)(int)lVar11 * 2;
              uVar13 = lVar11 + 0x11;
              if (uVar13 <= lVar11 + 2U) {
                uVar13 = 0xffffffffffffff0;
              }
              *(undefined8 *)(puVar16 + -8) = 0x1800136b8;
              lVar11 = -(uVar13 & 0xfffffffffffffff0);
              pcVar1 = puVar16 + lVar11 + 0x40;
              puVar15 = puVar16 + lVar11;
              if (pcVar1 != (char *)0x0) {
                *pcVar1 = '\0';
                *(undefined8 *)(puVar16 + lVar11 + 0x38) = 0;
                *(undefined8 *)(puVar16 + lVar11 + 0x30) = 0;
                *(int *)(puVar16 + lVar11 + 0x28) = iVar14 * 2;
                *(char **)(puVar16 + lVar11 + 0x20) = pcVar1;
                *(undefined8 *)(puVar16 + lVar11 + -8) = 0x1800136ec;
                iVar14 = WideCharToMultiByte(0,0,pWVar19,-1,*(LPSTR *)(puVar16 + lVar11 + 0x20),
                                             *(int *)(puVar16 + lVar11 + 0x28),
                                             *(LPCSTR *)(puVar16 + lVar11 + 0x30),
                                             *(LPBOOL *)(puVar16 + lVar11 + 0x38));
                puVar15 = puVar16 + lVar11;
                pcVar18 = pcVar1;
                if (iVar14 == 0) {
                  puVar15 = puVar16 + lVar11;
                  pcVar18 = pcVar10;
                }
              }
            }
          }
LAB_1800136f7:
          *(undefined8 *)(puVar15 + -8) = 0x180013704;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_128,
                     pcVar18);
        }
        else if (VVar3 != 10) {
          if (VVar3 == 0x4008) {
            pWVar19 = (LPCWSTR)**(longlong **)((longlong)&param_5->n1 + 8);
            if (pWVar19 != (LPCWSTR)0x0) {
              lVar11 = -1;
              do {
                lVar11 = lVar11 + 1;
              } while (pWVar19[lVar11] != L'\0');
              goto LAB_18001368b;
            }
            goto LAB_1800136f7;
          }
          *(undefined8 *)(puVar16 + -8) = 0x180013596;
          HVar7 = VariantChangeType(&local_150,param_5,0,8);
          if (HVar7 < 0) goto LAB_180013754;
          pWVar19 = (LPCWSTR)CONCAT44(local_150.n1._12_4_,local_150.n1._8_4_);
          if (pWVar19 != (LPCWSTR)0x0) {
            lVar11 = -1;
            do {
              lVar12 = lVar11;
              lVar11 = lVar12 + 1;
            } while (pWVar19[lVar11] != L'\0');
            iVar14 = (int)lVar12 + 2;
            if (iVar14 < 0x40000000) {
              lVar11 = (longlong)(int)lVar11 * 2;
              uVar13 = lVar11 + 0x11;
              if (uVar13 <= lVar11 + 2U) {
                uVar13 = 0xffffffffffffff0;
              }
              *(undefined8 *)(puVar16 + -8) = 0x1800135e8;
              lVar11 = -(uVar13 & 0xfffffffffffffff0);
              pcVar1 = puVar16 + lVar11 + 0x40;
              puVar15 = puVar16 + lVar11;
              if (pcVar1 != (char *)0x0) {
                *pcVar1 = '\0';
                *(undefined8 *)(puVar16 + lVar11 + 0x38) = 0;
                *(undefined8 *)(puVar16 + lVar11 + 0x30) = 0;
                *(int *)(puVar16 + lVar11 + 0x28) = iVar14 * 2;
                *(char **)(puVar16 + lVar11 + 0x20) = pcVar1;
                *(undefined8 *)(puVar16 + lVar11 + -8) = 0x18001361c;
                iVar14 = WideCharToMultiByte(0,0,pWVar19,-1,*(LPSTR *)(puVar16 + lVar11 + 0x20),
                                             *(int *)(puVar16 + lVar11 + 0x28),
                                             *(LPCSTR *)(puVar16 + lVar11 + 0x30),
                                             *(LPBOOL *)(puVar16 + lVar11 + 0x38));
                puVar15 = puVar16 + lVar11;
                pcVar18 = pcVar1;
                if (iVar14 == 0) {
                  puVar15 = puVar16 + lVar11;
                  pcVar18 = pcVar10;
                }
              }
            }
          }
          *(undefined8 *)(puVar15 + -8) = 0x180013634;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_128,
                     pcVar18);
          *(undefined8 *)(puVar15 + -8) = 0x18001363e;
          VariantClear(&local_150);
        }
      }
      VVar3 = (param_6->n1).n2.vt;
      puVar16 = puVar15;
      if ((VVar3 != 0) && (VVar3 != 1)) {
        pcVar18 = pcVar10;
        if (VVar3 == 8) {
          pWVar19 = *(LPCWSTR *)((longlong)&param_6->n1 + 8);
          if (pWVar19 != (LPCWSTR)0x0) {
            lVar11 = -1;
            do {
              lVar11 = lVar11 + 1;
            } while (pWVar19[lVar11] != L'\0');
LAB_18001386b:
            iVar14 = (int)lVar11 + 1;
            if (iVar14 < 0x40000000) {
              lVar11 = (longlong)(int)lVar11 * 2;
              uVar13 = lVar11 + 0x11;
              if (uVar13 <= lVar11 + 2U) {
                uVar13 = 0xffffffffffffff0;
              }
              *(undefined8 *)(puVar15 + -8) = 0x180013898;
              lVar11 = -(uVar13 & 0xfffffffffffffff0);
              pcVar1 = puVar15 + lVar11 + 0x40;
              puVar16 = puVar15 + lVar11;
              if (pcVar1 != (char *)0x0) {
                *pcVar1 = '\0';
                *(undefined8 *)(puVar15 + lVar11 + 0x38) = 0;
                *(undefined8 *)(puVar15 + lVar11 + 0x30) = 0;
                *(int *)(puVar15 + lVar11 + 0x28) = iVar14 * 2;
                *(char **)(puVar15 + lVar11 + 0x20) = pcVar1;
                *(undefined8 *)(puVar15 + lVar11 + -8) = 0x1800138cc;
                iVar14 = WideCharToMultiByte(0,0,pWVar19,-1,*(LPSTR *)(puVar15 + lVar11 + 0x20),
                                             *(int *)(puVar15 + lVar11 + 0x28),
                                             *(LPCSTR *)(puVar15 + lVar11 + 0x30),
                                             *(LPBOOL *)(puVar15 + lVar11 + 0x38));
                puVar16 = puVar15 + lVar11;
                pcVar18 = pcVar1;
                if (iVar14 == 0) {
                  puVar16 = puVar15 + lVar11;
                  pcVar18 = pcVar10;
                }
              }
            }
          }
LAB_1800138d7:
          *(undefined8 *)(puVar16 + -8) = 0x1800138e4;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_130,
                     pcVar18);
        }
        else if (VVar3 != 10) {
          if (VVar3 == 0x4008) {
            pWVar19 = (LPCWSTR)**(longlong **)((longlong)&param_6->n1 + 8);
            if (pWVar19 != (LPCWSTR)0x0) {
              lVar11 = -1;
              do {
                lVar11 = lVar11 + 1;
              } while (pWVar19[lVar11] != L'\0');
              goto LAB_18001386b;
            }
            goto LAB_1800138d7;
          }
          *(undefined8 *)(puVar15 + -8) = 0x180013750;
          HVar7 = VariantChangeType(&local_150,param_6,0,8);
          if (HVar7 < 0) goto LAB_180013754;
          pWVar19 = (LPCWSTR)CONCAT44(local_150.n1._12_4_,local_150.n1._8_4_);
          if (pWVar19 != (LPCWSTR)0x0) {
            lVar11 = -1;
            do {
              lVar12 = lVar11;
              lVar11 = lVar12 + 1;
            } while (pWVar19[lVar11] != L'\0');
            iVar14 = (int)lVar12 + 2;
            if (iVar14 < 0x40000000) {
              lVar11 = (longlong)(int)lVar11 * 2;
              uVar13 = lVar11 + 0x11;
              if (uVar13 <= lVar11 + 2U) {
                uVar13 = 0xffffffffffffff0;
              }
              *(undefined8 *)(puVar15 + -8) = 0x1800137c8;
              lVar11 = -(uVar13 & 0xfffffffffffffff0);
              pcVar1 = puVar15 + lVar11 + 0x40;
              puVar16 = puVar15 + lVar11;
              if (pcVar1 != (char *)0x0) {
                *pcVar1 = '\0';
                *(undefined8 *)(puVar15 + lVar11 + 0x38) = 0;
                *(undefined8 *)(puVar15 + lVar11 + 0x30) = 0;
                *(int *)(puVar15 + lVar11 + 0x28) = iVar14 * 2;
                *(char **)(puVar15 + lVar11 + 0x20) = pcVar1;
                *(undefined8 *)(puVar15 + lVar11 + -8) = 0x1800137fc;
                iVar14 = WideCharToMultiByte(0,0,pWVar19,-1,*(LPSTR *)(puVar15 + lVar11 + 0x20),
                                             *(int *)(puVar15 + lVar11 + 0x28),
                                             *(LPCSTR *)(puVar15 + lVar11 + 0x30),
                                             *(LPBOOL *)(puVar15 + lVar11 + 0x38));
                puVar16 = puVar15 + lVar11;
                pcVar18 = pcVar1;
                if (iVar14 == 0) {
                  puVar16 = puVar15 + lVar11;
                  pcVar18 = pcVar10;
                }
              }
            }
          }
          *(undefined8 *)(puVar16 + -8) = 0x180013814;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_130,
                     pcVar18);
          *(undefined8 *)(puVar16 + -8) = 0x18001381e;
          VariantClear(&local_150);
        }
      }
      *(undefined4 *)(puVar16 + 0x28) = uVar20;
      *(undefined8 *)(puVar16 + 0x20) = local_130;
      *(undefined8 *)(puVar16 + -8) = 0x180013905;
      Ordinal_104(uVar17,local_118[0],local_120,local_128);
      pcVar10 = (char *)0x0;
      goto switchD_180012ea0_caseD_0;
    }
    pcVar18 = pcVar10;
    if (VVar3 == 8) {
      pWVar19 = *(LPCWSTR *)((longlong)&param_3->n1 + 8);
      if (pWVar19 != (LPCWSTR)0x0) {
        lVar11 = -1;
        do {
          lVar11 = lVar11 + 1;
        } while (pWVar19[lVar11] != L'\0');
LAB_1800132cb:
        iVar14 = (int)lVar11 + 1;
        if (iVar14 < 0x40000000) {
          lVar11 = (longlong)(int)lVar11 * 2;
          uVar13 = lVar11 + 0x11;
          if (uVar13 <= lVar11 + 2U) {
            uVar13 = 0xffffffffffffff0;
          }
          *(undefined8 *)(puVar15 + -8) = 0x1800132f8;
          lVar11 = -(uVar13 & 0xfffffffffffffff0);
          pcVar1 = puVar15 + lVar11 + 0x40;
          puVar16 = puVar15 + lVar11;
          if (pcVar1 != (char *)0x0) {
            *pcVar1 = '\0';
            *(undefined8 *)(puVar15 + lVar11 + 0x38) = 0;
            *(undefined8 *)(puVar15 + lVar11 + 0x30) = 0;
            *(int *)(puVar15 + lVar11 + 0x28) = iVar14 * 2;
            *(char **)(puVar15 + lVar11 + 0x20) = pcVar1;
            *(undefined8 *)(puVar15 + lVar11 + -8) = 0x18001332c;
            iVar14 = WideCharToMultiByte(0,0,pWVar19,-1,*(LPSTR *)(puVar15 + lVar11 + 0x20),
                                         *(int *)(puVar15 + lVar11 + 0x28),
                                         *(LPCSTR *)(puVar15 + lVar11 + 0x30),
                                         *(LPBOOL *)(puVar15 + lVar11 + 0x38));
            puVar16 = puVar15 + lVar11;
            pcVar18 = pcVar1;
            if (iVar14 == 0) {
              puVar16 = puVar15 + lVar11;
              pcVar18 = pcVar10;
            }
          }
        }
      }
LAB_180013337:
      *(undefined8 *)(puVar16 + -8) = 0x180013344;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_118,pcVar18)
      ;
      goto LAB_180013344;
    }
    if (VVar3 == 10) goto LAB_180013344;
    if (VVar3 == 0x4008) {
      pWVar19 = (LPCWSTR)**(longlong **)((longlong)&param_3->n1 + 8);
      if (pWVar19 != (LPCWSTR)0x0) {
        lVar11 = -1;
        do {
          lVar11 = lVar11 + 1;
        } while (pWVar19[lVar11] != L'\0');
        goto LAB_1800132cb;
      }
      goto LAB_180013337;
    }
    *(undefined8 *)(puVar15 + -8) = 0x180013030;
    HVar7 = VariantChangeType(&local_150,param_3,0,8);
    if (-1 < HVar7) {
      pWVar19 = (LPCWSTR)CONCAT44(local_150.n1._12_4_,local_150.n1._8_4_);
      if (pWVar19 != (LPCWSTR)0x0) {
        lVar11 = -1;
        do {
          lVar12 = lVar11;
          lVar11 = lVar12 + 1;
        } while (pWVar19[lVar11] != L'\0');
        iVar14 = (int)lVar12 + 2;
        if (iVar14 < 0x40000000) {
          lVar11 = (longlong)(int)lVar11 * 2;
          uVar13 = lVar11 + 0x11;
          if (uVar13 <= lVar11 + 2U) {
            uVar13 = 0xffffffffffffff0;
          }
          *(undefined8 *)(puVar15 + -8) = 0x18001308c;
          lVar11 = -(uVar13 & 0xfffffffffffffff0);
          pcVar1 = puVar15 + lVar11 + 0x40;
          puVar16 = puVar15 + lVar11;
          if (pcVar1 != (char *)0x0) {
            *pcVar1 = '\0';
            *(undefined8 *)(puVar15 + lVar11 + 0x38) = 0;
            *(undefined8 *)(puVar15 + lVar11 + 0x30) = 0;
            *(int *)(puVar15 + lVar11 + 0x28) = iVar14 * 2;
            *(char **)(puVar15 + lVar11 + 0x20) = pcVar1;
            *(undefined8 *)(puVar15 + lVar11 + -8) = 0x1800130c4;
            iVar14 = WideCharToMultiByte(0,0,pWVar19,-1,*(LPSTR *)(puVar15 + lVar11 + 0x20),
                                         *(int *)(puVar15 + lVar11 + 0x28),
                                         *(LPCSTR *)(puVar15 + lVar11 + 0x30),
                                         *(LPBOOL *)(puVar15 + lVar11 + 0x38));
            puVar16 = puVar15 + lVar11;
            pcVar18 = pcVar1;
            if (iVar14 == 0) {
              puVar16 = puVar15 + lVar11;
              pcVar18 = pcVar10;
            }
          }
        }
      }
      *(undefined8 *)(puVar16 + -8) = 0x180013274;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_118,pcVar18)
      ;
      *(undefined8 *)(puVar16 + -8) = 0x18001327e;
      VariantClear(&local_150);
      goto LAB_180013344;
    }
LAB_180013754:
    pcVar10 = (char *)0x0;
    puVar16 = puVar15;
    if (uVar20 == 0) goto switchD_180012ea0_caseD_0;
  }
  else {
    if (uVar2 == 0x4003) {
      uVar20 = **(uint **)((longlong)&param_7->n1 + 8);
      goto LAB_180012e6a;
    }
    if (uVar2 == 0x400b) {
      uVar20 = (uint)(**(short **)((longlong)&param_7->n1 + 8) != 0);
      goto LAB_180012e6a;
    }
switchD_180012df1_caseD_4:
    uStackY_1a0 = 0x180012e3d;
    HVar7 = VariantChangeType(&local_150,param_7,0,3);
    puVar16 = auStackY_198;
    uVar20 = local_150.n1._8_4_;
    if (HVar7 == 0) goto LAB_180012e6a;
  }
  pcVar6 = *(code **)(*param_1 + 0x280);
  *(undefined8 *)(puVar16 + -8) = 0x18001376e;
  uVar9 = (*pcVar6)(param_1,0x7d4);
  pcVar10 = (char *)(ulonglong)uVar9;
switchD_180012ea0_caseD_0:
  *(undefined8 *)(puVar16 + -8) = 0x180013910;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_138);
  *(undefined8 *)(puVar16 + -8) = 0x18001391b;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_130);
  *(undefined8 *)(puVar16 + -8) = 0x180013926;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_128);
  *(undefined8 *)(puVar16 + -8) = 0x180013931;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_120);
  *(undefined8 *)(puVar16 + -8) = 0x18001393c;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_118);
  *(undefined8 *)(puVar16 + -8) = 0x18001394d;
  return pcVar10;
}

/* ---- FUNC 000139E0 FUN_1800139e0 (1126 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

char * FUN_1800139e0(longlong *param_1,VARIANTARG *param_2,VARIANTARG *param_3,int param_4)

{
  char *pcVar1;
  VARTYPE VVar2;
  code *pcVar3;
  undefined8 lpWideCharStr;
  HRESULT HVar4;
  uint uVar5;
  longlong lVar6;
  longlong lVar7;
  ulonglong uVar8;
  int iVar9;
  char *pcVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  char *pcVar13;
  LPCWSTR pWVar14;
  undefined8 uStack_90;
  undefined1 auStack_88 [32];
  undefined8 uStack_68;
  int aiStack_60 [2];
  undefined8 local_58 [2];
  undefined8 local_48;
  undefined8 local_40;
  VARIANTARG local_38;
  ulonglong local_20;
  
  puVar11 = auStack_88;
  puVar12 = auStack_88;
  local_20 = DAT_180077818 ^ (ulonglong)&local_48;
  uStack_90 = 0x180013a23;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_40);
  uStack_90 = 0x180013a2e;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48);
  uStack_90 = 0x180013a39;
  VariantInit(&local_38);
  VVar2 = (param_2->n1).n2.vt;
  if ((VVar2 == 0) || (VVar2 == 1)) {
LAB_180013a88:
    pcVar10 = (char *)0x0;
    puVar12 = auStack_88;
    goto LAB_180013a8a;
  }
  if (VVar2 != 8) {
    if (VVar2 == 10) goto LAB_180013a88;
    if (VVar2 == 0x4008) {
      pWVar14 = (LPCWSTR)**(longlong **)((longlong)&param_2->n1 + 8);
      puVar12 = auStack_88;
      if (pWVar14 != (LPCWSTR)0x0) {
        lVar6 = -1;
        do {
          lVar6 = lVar6 + 1;
        } while (pWVar14[lVar6] != L'\0');
        goto LAB_180013bdb;
      }
      goto LAB_180013c46;
    }
    uStack_90 = 0x180013a7b;
    HVar4 = VariantChangeType(&local_38,param_2,0,8);
    lpWideCharStr = local_38.n1.decVal.u2;
    if (-1 < HVar4) {
      puVar11 = auStack_88;
      if (local_38.n1.decVal.u2.Lo64 == 0) {
LAB_180013b57:
        pcVar10 = (char *)0x0;
      }
      else {
        lVar6 = -1;
        do {
          lVar7 = lVar6;
          lVar6 = lVar7 + 1;
        } while (*(LPCWSTR)((longlong)local_38.n1.decVal.u2 + lVar6 * 2) != L'\0');
        iVar9 = (int)lVar7 + 2;
        puVar11 = auStack_88;
        if (0x3fffffff < iVar9) goto LAB_180013b57;
        lVar6 = (longlong)(int)lVar6 * 2;
        uVar8 = lVar6 + 0x11;
        if (uVar8 <= lVar6 + 2U) {
          uVar8 = 0xffffffffffffff0;
        }
        uStack_90 = 0x180013b19;
        lVar6 = -(uVar8 & 0xfffffffffffffff0);
        puVar11 = auStack_88 + lVar6;
        pcVar10 = (char *)((longlong)&local_48 + lVar6);
        if (pcVar10 == (char *)0x0) goto LAB_180013b57;
        *pcVar10 = '\0';
        *(undefined8 *)((longlong)local_58 + lVar6 + 8) = 0;
        *(undefined8 *)((longlong)local_58 + lVar6) = 0;
        *(int *)((longlong)aiStack_60 + lVar6) = iVar9 * 2;
        *(char **)((longlong)&uStack_68 + lVar6) = pcVar10;
        *(undefined8 *)(auStack_88 + lVar6 + -8) = 0x180013b4f;
        iVar9 = WideCharToMultiByte(0,0,(LPCWSTR)lpWideCharStr,-1,
                                    *(LPSTR *)((longlong)&uStack_68 + lVar6),
                                    *(int *)((longlong)aiStack_60 + lVar6),
                                    *(LPCSTR *)((longlong)local_58 + lVar6),
                                    *(LPBOOL *)((longlong)local_58 + lVar6 + 8));
        puVar11 = auStack_88 + lVar6;
        if (iVar9 == 0) {
          puVar11 = auStack_88 + lVar6;
          pcVar10 = (char *)0x0;
        }
      }
      *(undefined8 *)(puVar11 + -8) = 0x180013b68;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_40,pcVar10)
      ;
      *(undefined8 *)(puVar11 + -8) = 0x180013b72;
      VariantClear(&local_38);
      goto LAB_180013c57;
    }
    if (param_4 == 0) goto LAB_180013a88;
LAB_180013cad:
    pcVar3 = *(code **)(*param_1 + 0x280);
    *(undefined8 *)(puVar11 + -8) = 0x180013cbe;
    uVar5 = (*pcVar3)(param_1,0x7d4);
    pcVar10 = (char *)(ulonglong)uVar5;
    puVar12 = puVar11;
    goto LAB_180013a8a;
  }
  pWVar14 = *(LPCWSTR *)((longlong)&param_2->n1 + 8);
  if (pWVar14 == (LPCWSTR)0x0) {
LAB_180013c46:
    puVar11 = puVar12;
    pcVar10 = (char *)0x0;
  }
  else {
    lVar6 = -1;
    do {
      lVar6 = lVar6 + 1;
    } while (pWVar14[lVar6] != L'\0');
LAB_180013bdb:
    iVar9 = (int)lVar6 + 1;
    puVar12 = auStack_88;
    if (0x3fffffff < iVar9) goto LAB_180013c46;
    lVar6 = (longlong)(int)lVar6 * 2;
    uVar8 = lVar6 + 0x11;
    if (uVar8 <= lVar6 + 2U) {
      uVar8 = 0xffffffffffffff0;
    }
    uStack_90 = 0x180013c08;
    lVar6 = -(uVar8 & 0xfffffffffffffff0);
    puVar12 = auStack_88 + lVar6;
    pcVar10 = (char *)((longlong)&local_48 + lVar6);
    if (pcVar10 == (char *)0x0) goto LAB_180013c46;
    *pcVar10 = '\0';
    *(undefined8 *)((longlong)local_58 + lVar6 + 8) = 0;
    *(undefined8 *)((longlong)local_58 + lVar6) = 0;
    *(int *)((longlong)aiStack_60 + lVar6) = iVar9 * 2;
    *(char **)((longlong)&uStack_68 + lVar6) = pcVar10;
    *(undefined8 *)(auStack_88 + lVar6 + -8) = 0x180013c3e;
    iVar9 = WideCharToMultiByte(0,0,pWVar14,-1,*(LPSTR *)((longlong)&uStack_68 + lVar6),
                                *(int *)((longlong)aiStack_60 + lVar6),
                                *(LPCSTR *)((longlong)local_58 + lVar6),
                                *(LPBOOL *)((longlong)local_58 + lVar6 + 8));
    puVar11 = auStack_88 + lVar6;
    if (iVar9 == 0) {
      puVar11 = auStack_88 + lVar6;
      pcVar10 = (char *)0x0;
    }
  }
  *(undefined8 *)(puVar11 + -8) = 0x180013c57;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_40,pcVar10);
LAB_180013c57:
  pcVar10 = (char *)0x0;
  VVar2 = (param_3->n1).n2.vt;
  puVar12 = puVar11;
  if ((VVar2 != 0) && (VVar2 != 1)) {
    pcVar13 = pcVar10;
    if (VVar2 == 8) {
      pWVar14 = *(LPCWSTR *)((longlong)&param_3->n1 + 8);
      if (pWVar14 != (LPCWSTR)0x0) {
        lVar6 = -1;
        do {
          lVar6 = lVar6 + 1;
        } while (pWVar14[lVar6] != L'\0');
LAB_180013dbb:
        iVar9 = (int)lVar6 + 1;
        if (iVar9 < 0x40000000) {
          lVar6 = (longlong)(int)lVar6 * 2;
          uVar8 = lVar6 + 0x11;
          if (uVar8 <= lVar6 + 2U) {
            uVar8 = 0xffffffffffffff0;
          }
          *(undefined8 *)(puVar11 + -8) = 0x180013de8;
          lVar6 = -(uVar8 & 0xfffffffffffffff0);
          pcVar1 = puVar11 + lVar6 + 0x40;
          puVar12 = puVar11 + lVar6;
          if (pcVar1 != (char *)0x0) {
            *pcVar1 = '\0';
            *(undefined8 *)(puVar11 + lVar6 + 0x38) = 0;
            *(undefined8 *)(puVar11 + lVar6 + 0x30) = 0;
            *(int *)(puVar11 + lVar6 + 0x28) = iVar9 * 2;
            *(char **)(puVar11 + lVar6 + 0x20) = pcVar1;
            *(undefined8 *)(puVar11 + lVar6 + -8) = 0x180013e1c;
            iVar9 = WideCharToMultiByte(0,0,pWVar14,-1,*(LPSTR *)(puVar11 + lVar6 + 0x20),
                                        *(int *)(puVar11 + lVar6 + 0x28),
                                        *(LPCSTR *)(puVar11 + lVar6 + 0x30),
                                        *(LPBOOL *)(puVar11 + lVar6 + 0x38));
            puVar12 = puVar11 + lVar6;
            pcVar13 = pcVar1;
            if (iVar9 == 0) {
              puVar12 = puVar11 + lVar6;
              pcVar13 = pcVar10;
            }
          }
        }
      }
    }
    else {
      if (VVar2 == 10) goto LAB_180013e34;
      if (VVar2 != 0x4008) {
        *(undefined8 *)(puVar11 + -8) = 0x180013ca0;
        HVar4 = VariantChangeType(&local_38,param_3,0,8);
        if (-1 < HVar4) {
          if (local_38.n1.decVal.u2.Lo64 != 0) {
            lVar6 = -1;
            do {
              lVar7 = lVar6;
              lVar6 = lVar7 + 1;
            } while (*(LPCWSTR)((longlong)local_38.n1.decVal.u2 + lVar6 * 2) != L'\0');
            iVar9 = (int)lVar7 + 2;
            if (iVar9 < 0x40000000) {
              lVar6 = (longlong)(int)lVar6 * 2;
              uVar8 = lVar6 + 0x11;
              if (uVar8 <= lVar6 + 2U) {
                uVar8 = 0xffffffffffffff0;
              }
              *(undefined8 *)(puVar11 + -8) = 0x180013d0d;
              lVar6 = -(uVar8 & 0xfffffffffffffff0);
              pcVar1 = puVar11 + lVar6 + 0x40;
              puVar12 = puVar11 + lVar6;
              if (pcVar1 != (char *)0x0) {
                *pcVar1 = '\0';
                *(undefined8 *)(puVar11 + lVar6 + 0x38) = 0;
                *(undefined8 *)(puVar11 + lVar6 + 0x30) = 0;
                *(int *)(puVar11 + lVar6 + 0x28) = iVar9 * 2;
                *(char **)(puVar11 + lVar6 + 0x20) = pcVar1;
                *(undefined8 *)(puVar11 + lVar6 + -8) = 0x180013d41;
                iVar9 = WideCharToMultiByte(0,0,(LPCWSTR)local_38.n1.decVal.u2,-1,
                                            *(LPSTR *)(puVar11 + lVar6 + 0x20),
                                            *(int *)(puVar11 + lVar6 + 0x28),
                                            *(LPCSTR *)(puVar11 + lVar6 + 0x30),
                                            *(LPBOOL *)(puVar11 + lVar6 + 0x38));
                puVar12 = puVar11 + lVar6;
                pcVar13 = pcVar1;
                if (iVar9 == 0) {
                  puVar12 = puVar11 + lVar6;
                  pcVar13 = pcVar10;
                }
              }
            }
          }
          *(undefined8 *)(puVar12 + -8) = 0x180013d59;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48,
                     pcVar13);
          *(undefined8 *)(puVar12 + -8) = 0x180013d63;
          VariantClear(&local_38);
          *(undefined8 *)(puVar12 + -8) = 0x180013d70;
          Ordinal_129(local_40,local_48);
          goto LAB_180013a8a;
        }
        if (param_4 == 0) goto LAB_180013a8a;
        goto LAB_180013cad;
      }
      pWVar14 = (LPCWSTR)**(longlong **)((longlong)&param_3->n1 + 8);
      if (pWVar14 != (LPCWSTR)0x0) {
        lVar6 = -1;
        do {
          lVar6 = lVar6 + 1;
        } while (pWVar14[lVar6] != L'\0');
        goto LAB_180013dbb;
      }
    }
    *(undefined8 *)(puVar12 + -8) = 0x180013e34;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48,pcVar13);
  }
LAB_180013e34:
  *(undefined8 *)(puVar12 + -8) = 0x180013e41;
  Ordinal_129(local_40,local_48);
LAB_180013a8a:
  *(undefined8 *)(puVar12 + -8) = 0x180013a94;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48);
  *(undefined8 *)(puVar12 + -8) = 0x180013a9f;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_40);
  *(undefined8 *)(puVar12 + -8) = 0x180013aad;
  return pcVar10;
}

/* ---- FUNC 00013E50 FUN_180013e50 (2110 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

ulonglong FUN_180013e50(longlong *param_1,undefined4 param_2,short *param_3,short *param_4,
                       short *param_5,short *param_6,undefined2 *param_7)

{
  short sVar1;
  undefined4 *puVar2;
  BSTR lpWideCharStr;
  longlong *plVar3;
  code *pcVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong lVar8;
  undefined8 *puVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  char *pcVar13;
  ulonglong uVar14;
  int iVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  undefined8 *puVar19;
  LPCWSTR pWVar20;
  undefined8 *puVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined8 uStack_120;
  undefined1 auStack_118 [32];
  undefined8 local_f8;
  undefined8 *local_f0;
  undefined2 *local_e8 [2];
  longlong local_d8;
  longlong local_d0;
  longlong local_c8;
  longlong local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_38;
  
  puVar18 = auStack_118;
  puVar17 = auStack_118;
  puVar16 = auStack_118;
  local_38 = DAT_180077818 ^ (ulonglong)&local_d8;
  if (DAT_1800797f8 != 0) {
    uStack_120 = 0x180013eb3;
    uVar6 = (**(code **)(*(longlong *)param_1[1] + 0x280))((longlong *)param_1[1],0x7f3);
    puVar18 = auStack_118;
    goto LAB_180014659;
  }
  uStack_120 = 0x180013ec2;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_c0);
  uStack_120 = 0x180013ecd;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_c8);
  uStack_120 = 0x180013ed8;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d0);
  uStack_120 = 0x180013ee3;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8);
  sVar1 = *param_3;
  pcVar10 = (char *)0x0;
  uVar6 = 0;
  if (sVar1 == 0) {
LAB_18001406f:
    uStack_120 = 0x180014079;
    ATL::CSimpleStringT<char,1>::Empty((CSimpleStringT<char,1> *)&local_c0);
LAB_180014079:
    sVar1 = *param_4;
    puVar18 = puVar17;
    if (sVar1 != 0) {
      if (sVar1 == 8) {
        pWVar20 = *(LPCWSTR *)(param_4 + 4);
        puVar16 = puVar17;
        if (pWVar20 != (LPCWSTR)0x0) {
          lVar7 = -1;
          do {
            lVar8 = lVar7;
            lVar7 = lVar8 + 1;
          } while (pWVar20[lVar7] != L'\0');
          iVar15 = (int)lVar8 + 2;
          if (iVar15 < 0x40000000) {
            lVar7 = (longlong)(int)lVar7 * 2;
            uVar14 = lVar7 + 0x11;
            if (uVar14 <= lVar7 + 2U) {
              uVar14 = 0xffffffffffffff0;
            }
            *(undefined8 *)(puVar17 + -8) = 0x1800141e7;
            lVar7 = -(uVar14 & 0xfffffffffffffff0);
            puVar18 = puVar17 + lVar7;
            pcVar11 = puVar17 + lVar7 + 0x40;
            puVar16 = puVar17 + lVar7;
            if (pcVar11 != (char *)0x0) {
              *pcVar11 = '\0';
              *(undefined8 *)(puVar17 + lVar7 + 0x38) = 0;
              *(undefined8 *)(puVar17 + lVar7 + 0x30) = 0;
              *(int *)(puVar17 + lVar7 + 0x28) = iVar15 * 2;
              *(char **)(puVar17 + lVar7 + 0x20) = pcVar11;
              *(undefined8 *)(puVar17 + lVar7 + -8) = 0x18001421b;
              iVar15 = WideCharToMultiByte(0,0,pWVar20,-1,*(LPSTR *)(puVar17 + lVar7 + 0x20),
                                           *(int *)(puVar17 + lVar7 + 0x28),
                                           *(LPCSTR *)(puVar17 + lVar7 + 0x30),
                                           *(LPBOOL *)(puVar17 + lVar7 + 0x38));
              if (iVar15 == 0) {
                pcVar11 = pcVar10;
              }
              *(undefined8 *)(puVar17 + lVar7 + -8) = 0x18001422e;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_c8,
                         pcVar11);
              goto LAB_18001424c;
            }
          }
        }
        puVar18 = puVar16;
        *(undefined8 *)(puVar18 + -8) = 0x180014240;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_c8,
                   (char *)0x0);
        goto LAB_18001424c;
      }
      if (sVar1 == 10) goto LAB_180014242;
      if (sVar1 == 0x4008) {
        lpWideCharStr = (BSTR)**(undefined8 **)(param_4 + 4);
        pcVar11 = pcVar10;
        if (lpWideCharStr != (BSTR)0x0) {
          lVar7 = -1;
          do {
            lVar8 = lVar7;
            lVar7 = lVar8 + 1;
          } while (lpWideCharStr[lVar7] != L'\0');
          iVar15 = (int)lVar8 + 2;
          if (iVar15 < 0x40000000) {
            lVar7 = (longlong)(int)lVar7 * 2;
            uVar14 = lVar7 + 0x11;
            if (uVar14 <= lVar7 + 2U) {
              uVar14 = 0xffffffffffffff0;
            }
            *(undefined8 *)(puVar17 + -8) = 0x180014138;
            lVar7 = -(uVar14 & 0xfffffffffffffff0);
            pcVar12 = puVar17 + lVar7 + 0x40;
            puVar18 = puVar17 + lVar7;
            if (pcVar12 != (char *)0x0) {
              *pcVar12 = '\0';
              *(undefined8 *)(puVar17 + lVar7 + 0x38) = 0;
              *(undefined8 *)(puVar17 + lVar7 + 0x30) = 0;
              *(int *)(puVar17 + lVar7 + 0x28) = iVar15 * 2;
              *(char **)(puVar17 + lVar7 + 0x20) = pcVar12;
              *(undefined8 *)(puVar17 + lVar7 + -8) = 0x180014171;
              iVar15 = WideCharToMultiByte(0,0,lpWideCharStr,-1,*(LPSTR *)(puVar17 + lVar7 + 0x20),
                                           *(int *)(puVar17 + lVar7 + 0x28),
                                           *(LPCSTR *)(puVar17 + lVar7 + 0x30),
                                           *(LPBOOL *)(puVar17 + lVar7 + 0x38));
              pcVar11 = pcVar12;
              puVar18 = puVar17 + lVar7;
              if (iVar15 == 0) {
                pcVar11 = pcVar10;
                puVar18 = puVar17 + lVar7;
              }
            }
          }
        }
        *(undefined8 *)(puVar18 + -8) = 0x180014189;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_c8,
                   pcVar11);
        *(undefined8 *)(puVar18 + -8) = 0x180014192;
        SysFreeString(lpWideCharStr);
        goto LAB_18001424c;
      }
      puVar16 = puVar17;
      if (sVar1 != 0x400c) goto LAB_18001427d;
      local_58 = *(undefined8 *)param_6;
      uStack_50 = *(undefined8 *)(param_6 + 4);
      local_48 = *(undefined8 *)(param_6 + 8);
      local_78 = *(undefined8 *)param_5;
      uStack_70 = *(undefined8 *)(param_5 + 4);
      local_68 = *(undefined8 *)(param_5 + 8);
      puVar2 = *(undefined4 **)(param_4 + 4);
      uVar22 = *puVar2;
      uVar23 = puVar2[1];
      uVar24 = puVar2[2];
      uVar25 = puVar2[3];
      local_88 = *(undefined8 *)(puVar2 + 4);
LAB_180014427:
      local_98 = CONCAT44(uVar23,uVar22);
      uStack_90 = CONCAT44(uVar25,uVar24);
      local_b8 = *(undefined8 *)param_3;
      uStack_b0 = *(undefined8 *)(param_3 + 4);
      local_a8 = *(undefined8 *)(param_3 + 8);
      *(undefined2 **)(puVar18 + 0x30) = param_7;
      *(undefined8 **)(puVar18 + 0x28) = &local_58;
      puVar9 = &local_78;
      puVar21 = &local_98;
      puVar19 = &local_b8;
      goto LAB_180014468;
    }
LAB_180014242:
    *(undefined8 *)(puVar17 + -8) = 0x18001424c;
    ATL::CSimpleStringT<char,1>::Empty((CSimpleStringT<char,1> *)&local_c8);
LAB_18001424c:
    sVar1 = *param_5;
    if (sVar1 != 0) {
      puVar16 = puVar18;
      if (sVar1 == 8) {
        pWVar20 = *(LPCWSTR *)(param_5 + 4);
        if (pWVar20 != (LPCWSTR)0x0) {
          lVar7 = -1;
          do {
            lVar7 = lVar7 + 1;
          } while (pWVar20[lVar7] != L'\0');
LAB_18001430a:
          iVar15 = (int)lVar7 + 1;
          if (iVar15 < 0x40000000) {
            lVar7 = (longlong)(int)lVar7 * 2;
            uVar14 = lVar7 + 0x11;
            if (uVar14 <= lVar7 + 2U) {
              uVar14 = 0xffffffffffffff0;
            }
            *(undefined8 *)(puVar18 + -8) = 0x18001433e;
            lVar7 = -(uVar14 & 0xfffffffffffffff0);
            pcVar11 = puVar18 + lVar7 + 0x40;
            puVar16 = puVar18 + lVar7;
            if (pcVar11 != (char *)0x0) {
              *pcVar11 = '\0';
              *(undefined8 *)(puVar18 + lVar7 + 0x38) = 0;
              *(undefined8 *)(puVar18 + lVar7 + 0x30) = 0;
              *(int *)(puVar18 + lVar7 + 0x28) = iVar15 * 2;
              *(char **)(puVar18 + lVar7 + 0x20) = pcVar11;
              *(undefined8 *)(puVar18 + lVar7 + -8) = 0x180014372;
              iVar15 = WideCharToMultiByte(0,0,pWVar20,-1,*(LPSTR *)(puVar18 + lVar7 + 0x20),
                                           *(int *)(puVar18 + lVar7 + 0x28),
                                           *(LPCSTR *)(puVar18 + lVar7 + 0x30),
                                           *(LPBOOL *)(puVar18 + lVar7 + 0x38));
              if (iVar15 == 0) {
                pcVar11 = pcVar10;
              }
              *(undefined8 *)(puVar18 + lVar7 + -8) = 0x180014385;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d0,
                         pcVar11);
              puVar18 = puVar18 + lVar7;
              goto LAB_1800143a3;
            }
          }
        }
LAB_180014387:
        puVar18 = puVar16;
        *(undefined8 *)(puVar18 + -8) = 0x180014397;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d0,
                   (char *)0x0);
        goto LAB_1800143a3;
      }
      if (sVar1 == 10) goto LAB_180014399;
      if (sVar1 == 0x4008) {
        pWVar20 = (LPCWSTR)**(longlong **)(param_5 + 4);
        if (pWVar20 != (LPCWSTR)0x0) {
          lVar7 = -1;
          do {
            lVar7 = lVar7 + 1;
          } while (pWVar20[lVar7] != L'\0');
          goto LAB_18001430a;
        }
        goto LAB_180014387;
      }
      if (sVar1 != 0x400c) goto LAB_18001427d;
      local_58 = *(undefined8 *)param_6;
      uStack_50 = *(undefined8 *)(param_6 + 4);
      local_48 = *(undefined8 *)(param_6 + 8);
      puVar2 = *(undefined4 **)(param_5 + 4);
      uVar22 = *puVar2;
      uVar23 = puVar2[1];
      uVar24 = puVar2[2];
      uVar25 = puVar2[3];
      local_68 = *(undefined8 *)(puVar2 + 4);
LAB_180014416:
      local_78 = CONCAT44(uVar23,uVar22);
      uStack_70 = CONCAT44(uVar25,uVar24);
      uVar22 = *(undefined4 *)param_4;
      uVar23 = *(undefined4 *)(param_4 + 2);
      uVar24 = *(undefined4 *)(param_4 + 4);
      uVar25 = *(undefined4 *)(param_4 + 6);
      local_88 = *(undefined8 *)(param_4 + 8);
      goto LAB_180014427;
    }
LAB_180014399:
    *(undefined8 *)(puVar18 + -8) = 0x1800143a3;
    ATL::CSimpleStringT<char,1>::Empty((CSimpleStringT<char,1> *)&local_d0);
LAB_1800143a3:
    sVar1 = *param_6;
    if (sVar1 == 0) {
LAB_180014559:
      *(undefined8 *)(puVar18 + -8) = 0x180014563;
      ATL::CSimpleStringT<char,1>::Empty((CSimpleStringT<char,1> *)&local_d8);
    }
    else {
      puVar16 = puVar18;
      if (sVar1 == 8) {
        pWVar20 = *(LPCWSTR *)(param_6 + 4);
        if (pWVar20 != (LPCWSTR)0x0) {
          lVar7 = -1;
          do {
            lVar7 = lVar7 + 1;
          } while (pWVar20[lVar7] != L'\0');
LAB_1800144ca:
          iVar15 = (int)lVar7 + 1;
          if (iVar15 < 0x40000000) {
            lVar7 = (longlong)(int)lVar7 * 2;
            uVar14 = lVar7 + 0x11;
            if (uVar14 <= lVar7 + 2U) {
              uVar14 = 0xffffffffffffff0;
            }
            *(undefined8 *)(puVar18 + -8) = 0x1800144fe;
            lVar7 = -(uVar14 & 0xfffffffffffffff0);
            pcVar11 = puVar18 + lVar7 + 0x40;
            puVar16 = puVar18 + lVar7;
            if (pcVar11 != (char *)0x0) {
              *pcVar11 = '\0';
              *(undefined8 *)(puVar18 + lVar7 + 0x38) = 0;
              *(undefined8 *)(puVar18 + lVar7 + 0x30) = 0;
              *(int *)(puVar18 + lVar7 + 0x28) = iVar15 * 2;
              *(char **)(puVar18 + lVar7 + 0x20) = pcVar11;
              *(undefined8 *)(puVar18 + lVar7 + -8) = 0x180014532;
              iVar15 = WideCharToMultiByte(0,0,pWVar20,-1,*(LPSTR *)(puVar18 + lVar7 + 0x20),
                                           *(int *)(puVar18 + lVar7 + 0x28),
                                           *(LPCSTR *)(puVar18 + lVar7 + 0x30),
                                           *(LPBOOL *)(puVar18 + lVar7 + 0x38));
              if (iVar15 == 0) {
                pcVar11 = pcVar10;
              }
              *(undefined8 *)(puVar18 + lVar7 + -8) = 0x180014545;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8,
                         pcVar11);
              puVar18 = puVar18 + lVar7;
              goto LAB_180014563;
            }
          }
        }
      }
      else {
        if (sVar1 == 10) goto LAB_180014559;
        if (sVar1 != 0x4008) {
          if (sVar1 != 0x400c) {
            plVar3 = (longlong *)param_1[1];
            pcVar4 = *(code **)(*plVar3 + 0x280);
            *(undefined8 *)(puVar18 + -8) = 0x1800143eb;
            uVar5 = (*pcVar4)(plVar3,0x7d4);
            uVar6 = (ulonglong)uVar5;
            goto LAB_18001462b;
          }
          puVar9 = *(undefined8 **)(param_6 + 4);
          local_58 = *puVar9;
          uStack_50 = puVar9[1];
          local_48 = puVar9[2];
          uVar22 = *(undefined4 *)param_5;
          uVar23 = *(undefined4 *)(param_5 + 2);
          uVar24 = *(undefined4 *)(param_5 + 4);
          uVar25 = *(undefined4 *)(param_5 + 6);
          local_68 = *(undefined8 *)(param_5 + 8);
          goto LAB_180014416;
        }
        pWVar20 = (LPCWSTR)**(longlong **)(param_6 + 4);
        if (pWVar20 != (LPCWSTR)0x0) {
          lVar7 = -1;
          do {
            lVar7 = lVar7 + 1;
          } while (pWVar20[lVar7] != L'\0');
          goto LAB_1800144ca;
        }
      }
      puVar18 = puVar16;
      *(undefined8 *)(puVar18 + -8) = 0x180014557;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8,
                 (char *)0x0);
    }
LAB_180014563:
    iVar15 = *(int *)(local_c0 + -0x10);
    *(undefined8 *)(puVar18 + -8) = 0x180014574;
    pcVar10 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)&local_c0,iVar15);
    iVar15 = *(int *)(local_c8 + -0x10);
    *(undefined8 *)(puVar18 + -8) = 0x180014588;
    pcVar11 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)&local_c8,iVar15);
    iVar15 = *(int *)(local_d0 + -0x10);
    *(undefined8 *)(puVar18 + -8) = 0x18001459c;
    pcVar12 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)&local_d0,iVar15);
    iVar15 = *(int *)(local_d8 + -0x10);
    *(undefined8 *)(puVar18 + -8) = 0x1800145b0;
    pcVar13 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)&local_d8,iVar15);
    *(char **)(puVar18 + 0x20) = pcVar13;
    *(undefined8 *)(puVar18 + -8) = 0x1800145c6;
    iVar15 = Ordinal_84(param_2,pcVar10,pcVar11,pcVar12);
    *(undefined8 *)(puVar18 + -8) = 0x1800145d7;
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_c0,-1);
    *(undefined8 *)(puVar18 + -8) = 0x1800145e6;
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_c8,-1);
    *(undefined8 *)(puVar18 + -8) = 0x1800145f5;
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_d0,-1);
    *(undefined8 *)(puVar18 + -8) = 0x180014604;
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_d8,-1);
    if (iVar15 == 0) {
      *param_7 = 1;
    }
    else {
      plVar3 = (longlong *)param_1[1];
      pcVar4 = *(code **)(*plVar3 + 0x280);
      *(undefined8 *)(puVar18 + -8) = 0x18001461a;
      uVar5 = (*pcVar4)(plVar3,0x7d1);
      uVar6 = (ulonglong)uVar5;
    }
  }
  else {
    pcVar11 = pcVar10;
    if (sVar1 == 8) {
      pWVar20 = *(LPCWSTR *)(param_3 + 4);
      if (pWVar20 != (LPCWSTR)0x0) {
        lVar7 = -1;
        do {
          lVar7 = lVar7 + 1;
        } while (pWVar20[lVar7] != L'\0');
LAB_180013fea:
        iVar15 = (int)lVar7 + 1;
        puVar16 = auStack_118;
        if (iVar15 < 0x40000000) {
          lVar7 = (longlong)(int)lVar7 * 2;
          uVar14 = lVar7 + 0x11;
          if (uVar14 <= lVar7 + 2U) {
            uVar14 = 0xffffffffffffff0;
          }
          uStack_120 = 0x180014017;
          lVar7 = -(uVar14 & 0xfffffffffffffff0);
          puVar16 = auStack_118 + lVar7;
          pcVar12 = (char *)((longlong)&local_d8 + lVar7);
          if (pcVar12 != (char *)0x0) {
            *pcVar12 = '\0';
            *(undefined8 *)((longlong)local_e8 + lVar7 + 8) = 0;
            *(undefined8 *)((longlong)local_e8 + lVar7) = 0;
            *(int *)((longlong)&local_f0 + lVar7) = iVar15 * 2;
            *(char **)((longlong)&local_f8 + lVar7) = pcVar12;
            *(undefined8 *)(auStack_118 + lVar7 + -8) = 0x18001404b;
            iVar15 = WideCharToMultiByte(0,0,pWVar20,-1,*(LPSTR *)((longlong)&local_f8 + lVar7),
                                         *(int *)((longlong)&local_f0 + lVar7),
                                         *(LPCSTR *)((longlong)local_e8 + lVar7),
                                         *(LPBOOL *)((longlong)local_e8 + lVar7 + 8));
            pcVar11 = pcVar12;
            puVar16 = auStack_118 + lVar7;
            if (iVar15 == 0) {
              pcVar11 = pcVar10;
              puVar16 = auStack_118 + lVar7;
            }
          }
        }
      }
LAB_180014056:
      *(undefined8 *)(puVar16 + -8) = 0x180014063;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_c0,pcVar11)
      ;
      puVar17 = puVar16;
      goto LAB_180014079;
    }
    if (sVar1 == 10) goto LAB_18001406f;
    if (sVar1 == 0x4008) {
      pWVar20 = (LPCWSTR)**(longlong **)(param_3 + 4);
      puVar16 = auStack_118;
      if (pWVar20 != (LPCWSTR)0x0) {
        lVar7 = -1;
        do {
          lVar7 = lVar7 + 1;
        } while (pWVar20[lVar7] != L'\0');
        goto LAB_180013fea;
      }
      goto LAB_180014056;
    }
    puVar16 = auStack_118;
    if (sVar1 != 0x400c) {
LAB_18001427d:
      puVar18 = puVar16;
      plVar3 = (longlong *)param_1[1];
      pcVar4 = *(code **)(*plVar3 + 0x280);
      *(undefined8 *)(puVar18 + -8) = 0x18001428f;
      uVar5 = (*pcVar4)(plVar3,0x7d4);
      uVar6 = (ulonglong)uVar5;
      goto LAB_18001462b;
    }
    local_b8 = *(undefined8 *)param_6;
    uStack_b0 = *(undefined8 *)(param_6 + 4);
    local_a8 = *(undefined8 *)(param_6 + 8);
    local_98 = *(undefined8 *)param_5;
    uStack_90 = *(undefined8 *)(param_5 + 4);
    local_88 = *(undefined8 *)(param_5 + 8);
    local_78 = *(undefined8 *)param_4;
    uStack_70 = *(undefined8 *)(param_4 + 4);
    local_68 = *(undefined8 *)(param_4 + 8);
    puVar9 = *(undefined8 **)(param_3 + 4);
    local_58 = *puVar9;
    uStack_50 = puVar9[1];
    local_48 = puVar9[2];
    local_e8[0] = param_7;
    local_f0 = &local_b8;
    puVar9 = &local_98;
    puVar21 = &local_78;
    puVar19 = &local_58;
LAB_180014468:
    *(undefined8 **)(puVar18 + 0x20) = puVar9;
    pcVar4 = *(code **)(*param_1 + 0x90);
    *(undefined8 *)(puVar18 + -8) = 0x18001447d;
    uVar5 = (*pcVar4)(param_1,param_2,puVar19,puVar21);
    uVar6 = (ulonglong)uVar5;
  }
LAB_18001462b:
  *(undefined8 *)(puVar18 + -8) = 0x180014635;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8);
  *(undefined8 *)(puVar18 + -8) = 0x180014640;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d0);
  *(undefined8 *)(puVar18 + -8) = 0x18001464b;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_c8);
  *(undefined8 *)(puVar18 + -8) = 0x180014656;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_c0);
LAB_180014659:
  *(undefined8 *)(puVar18 + -8) = 0x180014668;
  return uVar6;
}

/* ---- FUNC 00014690 FUN_180014690 (91 bytes) ---- */

undefined8 FUN_180014690(longlong param_1,undefined4 param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  BSTR pOVar2;
  LPCSTR local_res20;
  
  if (DAT_1800797f8 != 0) {
    uVar1 = (**(code **)(**(longlong **)(param_1 + 8) + 0x280))(*(longlong **)(param_1 + 8),0x7f3);
    return uVar1;
  }
  Ordinal_83(param_2,0,&local_res20,0,0);
  pOVar2 = FUN_1800019d0(local_res20);
  *param_3 = pOVar2;
  return 0;
}

/* ---- FUNC 000146F0 FUN_1800146f0 (298 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_1800146f0(longlong *param_1,LPCWSTR param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  longlong lVar3;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined1 *puVar7;
  char *pcVar8;
  int iVar9;
  undefined8 uStack_60;
  undefined1 auStack_58 [32];
  undefined8 uStack_38;
  int aiStack_30 [2];
  undefined8 local_28 [2];
  longlong local_18;
  ulonglong local_10;
  longlong lVar4;
  
  local_10 = DAT_180077818 ^ (ulonglong)&local_18;
  puVar7 = auStack_58;
  if (param_2 == (LPCWSTR)0x0) {
LAB_1800147b2:
    pcVar8 = (char *)0x0;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_2[lVar3] != L'\0');
    iVar9 = (int)lVar4 + 2;
    puVar7 = auStack_58;
    if (0x3fffffff < iVar9) goto LAB_1800147b2;
    lVar3 = (longlong)(int)lVar3 * 2;
    uVar5 = lVar3 + 0x11;
    if (uVar5 <= lVar3 + 2U) {
      uVar5 = 0xffffffffffffff0;
    }
    uStack_60 = 0x180014770;
    lVar3 = -(uVar5 & 0xfffffffffffffff0);
    puVar7 = auStack_58 + lVar3;
    pcVar8 = (char *)((longlong)&local_18 + lVar3);
    if (pcVar8 == (char *)0x0) goto LAB_1800147b2;
    *pcVar8 = '\0';
    *(undefined8 *)((longlong)local_28 + lVar3 + 8) = 0;
    *(undefined8 *)((longlong)local_28 + lVar3) = 0;
    *(int *)((longlong)aiStack_30 + lVar3) = iVar9 * 2;
    *(char **)((longlong)&uStack_38 + lVar3) = pcVar8;
    *(undefined8 *)(auStack_58 + lVar3 + -8) = 0x1800147aa;
    iVar9 = WideCharToMultiByte(0,0,param_2,-1,*(LPSTR *)((longlong)&uStack_38 + lVar3),
                                *(int *)((longlong)aiStack_30 + lVar3),
                                *(LPCSTR *)((longlong)local_28 + lVar3),
                                *(LPBOOL *)((longlong)local_28 + lVar3 + 8));
    puVar7 = auStack_58 + lVar3;
    if (iVar9 == 0) {
      puVar7 = auStack_58 + lVar3;
      pcVar8 = (char *)0x0;
    }
  }
  uVar2 = 0;
  *(undefined8 *)(puVar7 + -8) = 0x1800147c3;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_18,pcVar8);
  if (*(int *)(local_18 + -0x10) == 0) {
    uVar6 = 0x7d4;
  }
  else {
    *(undefined8 *)(puVar7 + -8) = 0x1800147d9;
    uVar6 = FUN_180037590(local_18);
    if (-1 < (int)uVar6) goto LAB_1800147f0;
    uVar6 = 0x7f4;
  }
  pcVar1 = *(code **)(*param_1 + 0x280);
  *(undefined8 *)(puVar7 + -8) = 0x1800147ee;
  uVar2 = (*pcVar1)(param_1,uVar6);
LAB_1800147f0:
  *(undefined8 *)(puVar7 + -8) = 0x1800147fa;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_18);
  *(undefined8 *)(puVar7 + -8) = 0x180014808;
  return uVar2;
}

/* ---- FUNC 00014820 FUN_180014820 (319 bytes) ---- */

void FUN_180014820(longlong *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                  undefined8 *param_5,undefined8 *param_6,undefined8 *param_7,undefined8 *param_8)

{
  _union_2707 local_128;
  undefined8 local_108;
  _union_1719 _Stack_100;
  undefined8 local_f8;
  undefined8 local_e8;
  _union_1719 _Stack_e0;
  undefined8 local_d8;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  VariantInit((VARIANTARG *)&local_128.n2);
  local_108 = local_128._0_8_;
  _Stack_100 = local_128.decVal.u2;
  local_e8 = local_128._0_8_;
  _Stack_e0 = local_128.decVal.u2;
  local_b8 = param_8[2];
  local_f8 = local_128._16_8_;
  local_d8 = local_128._16_8_;
  local_c8 = *param_8;
  uStack_c0 = param_8[1];
  local_a8 = *param_7;
  uStack_a0 = param_7[1];
  local_98 = param_7[2];
  local_88 = *param_6;
  uStack_80 = param_6[1];
  local_78 = param_6[2];
  local_68 = *param_5;
  uStack_60 = param_5[1];
  local_58 = param_5[2];
  local_48 = *param_4;
  uStack_40 = param_4[1];
  local_38 = param_4[2];
  local_28 = *param_3;
  uStack_20 = param_3[1];
  local_18 = param_3[2];
  FUN_180014960(param_1,param_2,&local_28,&local_48,&local_68,&local_88,&local_a8,&local_c8,
                (short *)&local_e8,&local_108);
  return;
}

/* ---- FUNC 00014960 FUN_180014960 (680 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char * FUN_180014960(longlong *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                    undefined8 *param_5,undefined8 *param_6,undefined8 *param_7,undefined8 *param_8,
                    short *param_9,undefined8 *param_10)

{
  undefined1 *puVar1;
  LPCWSTR lpWideCharStr;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  longlong lVar5;
  ulonglong uVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined8 uStackY_130;
  undefined1 auStackY_128 [32];
  uint local_e8 [4];
  _union_2707 local_d8;
  _union_2707 local_b8;
  _union_2707 local_98;
  _union_2707 local_78;
  _union_2707 local_58;
  _union_2707 local_38;
  ulonglong local_18;
  longlong lVar6;
  
  puVar10 = auStackY_128;
  local_18 = DAT_180077818 ^ (ulonglong)local_e8;
  puVar9 = (undefined1 *)0x0;
  *(undefined4 *)(param_1 + 0x12) = 0;
  local_e8[0] = 0;
  local_98._0_8_ = *param_8;
  local_98.decVal.u2 = *(_union_1719 *)(param_8 + 1);
  local_98._16_8_ = param_8[2];
  local_78._0_8_ = *param_7;
  local_78.decVal.u2 = *(_union_1719 *)(param_7 + 1);
  local_78._16_8_ = param_7[2];
  local_58._0_8_ = *param_6;
  local_58.decVal.u2 = *(_union_1719 *)(param_6 + 1);
  local_58._16_8_ = param_6[2];
  local_38._0_8_ = *param_5;
  local_38.decVal.u2 = *(_union_1719 *)(param_5 + 1);
  local_38._16_8_ = param_5[2];
  local_d8._0_8_ = *param_4;
  local_d8.decVal.u2 = *(_union_1719 *)(param_4 + 1);
  local_d8._16_8_ = param_4[2];
  local_b8._0_8_ = *param_3;
  local_b8.decVal.u2 = *(_union_1719 *)(param_3 + 1);
  local_b8._16_8_ = param_3[2];
  uStackY_130 = 0x180014a7c;
  pcVar4 = FUN_1800129c0(param_1,(VARIANTARG *)&local_b8.n2,(VARIANTARG *)&local_d8.n2,
                         (VARIANTARG *)&local_38.n2,(VARIANTARG *)&local_58.n2,
                         (VARIANTARG *)&local_78.n2,(VARIANTARG *)&local_98.n2,local_e8);
  if (-1 < (int)pcVar4) {
    local_b8._0_8_ = *param_10;
    local_b8.decVal.u2 = *(_union_1719 *)(param_10 + 1);
    local_b8._16_8_ = param_10[2];
    local_d8._0_8_ = *(undefined8 *)param_9;
    local_d8.decVal.u2 = *(_union_1719 *)(param_9 + 4);
    local_d8._16_8_ = *(undefined8 *)(param_9 + 8);
    uStackY_130 = 0x180014ac8;
    FUN_1800139e0(param_1,(VARIANTARG *)&local_d8.n2,(VARIANTARG *)&local_b8.n2,local_e8[0]);
    lpWideCharStr = (LPCWSTR)*param_2;
    puVar10 = auStackY_128;
    puVar11 = puVar9;
    if (lpWideCharStr != (LPCWSTR)0x0) {
      lVar5 = -1;
      do {
        lVar6 = lVar5;
        lVar5 = lVar6 + 1;
      } while (lpWideCharStr[lVar5] != L'\0');
      iVar8 = (int)lVar6 + 2;
      puVar10 = auStackY_128;
      if (iVar8 < 0x40000000) {
        lVar5 = (longlong)(int)lVar5 * 2;
        uVar7 = lVar5 + 0x11;
        if (uVar7 <= lVar5 + 2U) {
          uVar7 = 0xffffffffffffff0;
        }
        uStackY_130 = 0x180014b1e;
        lVar5 = -(uVar7 & 0xfffffffffffffff0);
        puVar1 = (undefined1 *)((longlong)local_e8 + lVar5);
        puVar10 = auStackY_128 + lVar5;
        if (puVar1 != (undefined1 *)0x0) {
          *(undefined8 *)(&stack0xffffffffffffff10 + lVar5) = 0;
          *(undefined8 *)(&stack0xffffffffffffff08 + lVar5) = 0;
          *(int *)((longlong)local_e8 + lVar5 + -0x18) = iVar8 * 2;
          *puVar1 = 0;
          *(undefined1 **)((longlong)local_e8 + lVar5 + -0x20) = puVar1;
          *(undefined8 *)(auStackY_128 + lVar5 + -8) = 0x180014b51;
          iVar8 = WideCharToMultiByte(0,0,lpWideCharStr,-1,
                                      *(LPSTR *)((longlong)local_e8 + lVar5 + -0x20),
                                      *(int *)((longlong)local_e8 + lVar5 + -0x18),
                                      *(LPCSTR *)(&stack0xffffffffffffff08 + lVar5),
                                      *(LPBOOL *)(&stack0xffffffffffffff10 + lVar5));
          puVar10 = auStackY_128 + lVar5;
          puVar11 = puVar1;
          if (iVar8 == 0) {
            puVar10 = auStackY_128 + lVar5;
            puVar11 = puVar9;
          }
        }
      }
    }
    *(undefined8 *)(puVar10 + -8) = 0x180014b69;
    uVar3 = FUN_1800374f0(puVar11,0xffffffff);
    if (uVar3 == 0) {
      *(undefined8 *)(puVar10 + -8) = 0x180014b72;
      cVar2 = MMWaitFailed();
      if (cVar2 == '\0') {
        *(undefined8 *)(puVar10 + -8) = 0x180014b8f;
        pcVar4 = (char *)FUN_18001a850(param_1,0x7f9);
      }
      else {
        *(undefined8 *)(puVar10 + -8) = 0x180014b83;
        pcVar4 = (char *)FUN_18001a850(param_1,0x7f8);
      }
    }
    else {
      if (*param_9 == 8) {
        do {
          puVar11 = puVar9;
          if ((*(wchar_t *)(*(longlong *)(param_9 + 4) + (longlong)puVar11 * 2) !=
               L"AspenEDRExtract"[(longlong)puVar11]) ||
             (*(wchar_t *)(*(longlong *)(param_9 + 4) + 2 + (longlong)puVar11 * 2) !=
              L"AspenEDRExtract"[(longlong)(puVar11 + 1)])) goto LAB_180014bd2;
          puVar9 = puVar11 + 2;
        } while (puVar11 + 2 != (undefined1 *)0x10);
        *(undefined8 *)(puVar10 + -8) = 0x180014bd2;
        PostMainWndMessage(0x4f8,(int)puVar11 + -8,0);
      }
LAB_180014bd2:
      pcVar4 = (char *)0x0;
    }
  }
  *(undefined8 *)(puVar10 + -8) = 0x180014be3;
  return pcVar4;
}

/* ---- FUNC 00014C10 FUN_180014c10 (362 bytes) ---- */

void FUN_180014c10(longlong *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                  undefined8 *param_5,undefined8 *param_6,undefined8 *param_7,undefined8 *param_8,
                  undefined8 *param_9)

{
  _union_2707 local_148;
  undefined8 local_128;
  _union_1719 _Stack_120;
  undefined8 local_118;
  undefined8 local_108;
  _union_1719 _Stack_100;
  undefined8 local_f8;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  VariantInit((VARIANTARG *)&local_148.n2);
  local_128 = local_148._0_8_;
  _Stack_120 = local_148.decVal.u2;
  local_108 = local_148._0_8_;
  _Stack_100 = local_148.decVal.u2;
  local_d8 = param_9[2];
  local_118 = local_148._16_8_;
  local_f8 = local_148._16_8_;
  local_e8 = *param_9;
  uStack_e0 = param_9[1];
  local_c8 = *param_8;
  uStack_c0 = param_8[1];
  local_b8 = param_8[2];
  local_a8 = *param_7;
  uStack_a0 = param_7[1];
  local_98 = param_7[2];
  local_88 = *param_6;
  uStack_80 = param_6[1];
  local_78 = param_6[2];
  local_68 = *param_5;
  uStack_60 = param_5[1];
  local_58 = param_5[2];
  local_48 = *param_4;
  uStack_40 = param_4[1];
  local_38 = param_4[2];
  local_28 = *param_3;
  uStack_20 = param_3[1];
  local_18 = param_3[2];
  FUN_180014d80(param_1,param_2,(longlong)&local_28,&local_48,&local_68,&local_88,&local_a8,
                &local_c8,&local_e8,&local_108,&local_128);
  return;
}

/* ---- FUNC 00014D80 FUN_180014d80 (604 bytes) ---- */

char * FUN_180014d80(longlong *param_1,undefined8 *param_2,longlong param_3,undefined8 *param_4,
                    undefined8 *param_5,undefined8 *param_6,undefined8 *param_7,undefined8 *param_8,
                    undefined8 *param_9,undefined8 *param_10,undefined8 *param_11)

{
  int *piVar1;
  int iVar2;
  OLECHAR *psz;
  char cVar3;
  uint uVar4;
  char *pcVar5;
  undefined8 *puVar6;
  BSTR pOVar7;
  LPSTR pCVar8;
  uint local_res8 [2];
  _union_2707 local_118;
  _union_2707 local_f8;
  _union_2707 local_d8;
  _union_2707 local_b8;
  _union_2707 local_98;
  _union_2707 local_78;
  _union_2707 local_58;
  _union_2707 local_38;
  
  *(undefined4 *)(param_1 + 0x12) = 0;
  local_res8[0] = 0;
  local_118._0_8_ = *param_9;
  local_118.decVal.u2 = *(_union_1719 *)(param_9 + 1);
  local_118._16_8_ = param_9[2];
  local_f8._0_8_ = *param_8;
  local_f8.decVal.u2 = *(_union_1719 *)(param_8 + 1);
  local_f8._16_8_ = param_8[2];
  local_d8._0_8_ = *param_7;
  local_d8.decVal.u2 = *(_union_1719 *)(param_7 + 1);
  local_d8._16_8_ = param_7[2];
  local_b8._0_8_ = *param_6;
  local_b8.decVal.u2 = *(_union_1719 *)(param_6 + 1);
  local_b8._16_8_ = param_6[2];
  local_98._0_8_ = *param_5;
  local_98.decVal.u2 = *(_union_1719 *)(param_5 + 1);
  local_98._16_8_ = param_5[2];
  local_78._0_8_ = *param_4;
  local_78.decVal.u2 = *(_union_1719 *)(param_4 + 1);
  local_78._16_8_ = param_4[2];
  pcVar5 = FUN_1800129c0(param_1,(VARIANTARG *)&local_78.n2,(VARIANTARG *)&local_98.n2,
                         (VARIANTARG *)&local_b8.n2,(VARIANTARG *)&local_d8.n2,
                         (VARIANTARG *)&local_f8.n2,(VARIANTARG *)&local_118.n2,local_res8);
  if (-1 < (int)pcVar5) {
    local_58._0_8_ = *param_11;
    local_58.decVal.u2 = *(_union_1719 *)(param_11 + 1);
    local_58._16_8_ = param_11[2];
    local_38._0_8_ = *param_10;
    local_38.decVal.u2 = *(_union_1719 *)(param_10 + 1);
    local_38._16_8_ = param_10[2];
    FUN_1800139e0(param_1,(VARIANTARG *)&local_38.n2,(VARIANTARG *)&local_58.n2,local_res8[0]);
    psz = (OLECHAR *)*param_2;
    puVar6 = operator_new(0x18);
    if (puVar6 == (undefined8 *)0x0) {
      puVar6 = (undefined8 *)0x0;
    }
    else {
      puVar6[1] = 0;
      *(undefined4 *)(puVar6 + 2) = 1;
      pOVar7 = SysAllocString(psz);
      *puVar6 = pOVar7;
      if ((pOVar7 == (BSTR)0x0) && (psz != (OLECHAR *)0x0)) {
                    /* WARNING: Subroutine does not return */
        FUN_18005d290(0x8007000e);
      }
    }
    if (puVar6 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_18005d290(0x8007000e);
    }
    pCVar8 = (LPSTR)puVar6[1];
    if (pCVar8 == (LPSTR)0x0) {
      pCVar8 = FUN_18005d360((LPCWSTR)*puVar6);
      puVar6[1] = pCVar8;
    }
    uVar4 = FUN_1800374f0(pCVar8,*(undefined4 *)(param_3 + 8));
    LOCK();
    piVar1 = (int *)(puVar6 + 2);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      if ((BSTR)*puVar6 != (BSTR)0x0) {
        SysFreeString((BSTR)*puVar6);
        *puVar6 = 0;
      }
      if ((void *)puVar6[1] != (void *)0x0) {
        operator_delete__((void *)puVar6[1]);
        puVar6[1] = 0;
      }
      FUN_180025ad0(puVar6);
    }
    if (uVar4 == 0) {
      cVar3 = MMWaitFailed();
      if (cVar3 == '\0') {
        pcVar5 = (char *)FUN_18001a850(param_1,0x7f9);
      }
      else {
        pcVar5 = (char *)FUN_18001a850(param_1,0x7f8);
      }
    }
    else {
      pcVar5 = (char *)0x0;
    }
  }
  return pcVar5;
}

/* ---- FUNC 00014FE0 FUN_180014fe0 (218 bytes) ---- */

undefined4 FUN_180014fe0(longlong *param_1,undefined8 param_2)

{
  undefined4 uVar1;
  _union_2707 local_108;
  undefined4 local_e8;
  ULONG UStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined8 local_d8;
  undefined4 local_c8;
  ULONG UStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined8 local_b8;
  undefined4 local_a8;
  ULONG UStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined8 local_98;
  undefined4 local_88;
  ULONG UStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined8 local_78;
  undefined4 local_68;
  ULONG UStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined8 local_58;
  undefined4 local_48;
  ULONG UStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  _union_2707 local_28;
  
  VariantInit((VARIANTARG *)&local_108.n2);
  local_28.n2.vt = 3;
  local_28._8_4_ = 0xffffffff;
  local_e8 = local_108._0_4_;
  UStack_e4 = local_108.decVal.Hi32;
  uStack_e0 = local_108._8_4_;
  uStack_dc = local_108._12_4_;
  local_d8 = local_108._16_8_;
  local_c8 = local_108._0_4_;
  UStack_c4 = local_108.decVal.Hi32;
  uStack_c0 = local_108._8_4_;
  uStack_bc = local_108._12_4_;
  local_b8 = local_108._16_8_;
  local_a8 = local_108._0_4_;
  UStack_a4 = local_108.decVal.Hi32;
  uStack_a0 = local_108._8_4_;
  uStack_9c = local_108._12_4_;
  local_98 = local_108._16_8_;
  local_88 = local_108._0_4_;
  UStack_84 = local_108.decVal.Hi32;
  uStack_80 = local_108._8_4_;
  uStack_7c = local_108._12_4_;
  local_78 = local_108._16_8_;
  local_68 = local_108._0_4_;
  UStack_64 = local_108.decVal.Hi32;
  uStack_60 = local_108._8_4_;
  uStack_5c = local_108._12_4_;
  local_58 = local_108._16_8_;
  local_48 = local_108._0_4_;
  UStack_44 = local_108.decVal.Hi32;
  uStack_40 = local_108._8_4_;
  uStack_3c = local_108._12_4_;
  local_38 = local_108._16_8_;
  uVar1 = (**(code **)(*param_1 + 0x198))
                    (param_1,param_2,&local_48,&local_68,&local_88,&local_a8,&local_c8,&local_e8);
  VariantClear((VARIANTARG *)&local_28.n2);
  return uVar1;
}

/* ---- FUNC 000150C0 FUN_1800150c0 (100 bytes) ---- */

undefined8 FUN_1800150c0(longlong *param_1,undefined8 param_2,char *param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = HAOpenArchive(param_2,param_3);
  if (lVar1 != 0) {
    *(undefined4 *)(param_1 + 3) = 0;
                    /* WARNING: Could not recover jumptable at 0x0001800150fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(*param_1 + 0x278))(param_1,lVar1);
    return uVar2;
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  FUN_18001cbb0((longlong)param_1,param_3);
  return 0;
}

/* ---- FUNC 00015130 FUN_180015130 (369 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined8 FUN_180015130(longlong *param_1,undefined8 *param_2)

{
  LPCWSTR lpWideCharStr;
  code *pcVar1;
  longlong *plVar2;
  undefined8 uVar3;
  longlong lVar4;
  ulonglong uVar6;
  int iVar7;
  undefined1 *puVar8;
  char *pcVar9;
  undefined8 uStack_60;
  undefined1 auStack_58 [32];
  undefined8 uStack_38;
  int aiStack_30 [2];
  undefined8 local_28 [2];
  longlong *local_18;
  ulonglong local_10;
  longlong lVar5;
  
  puVar8 = auStack_58;
  local_10 = DAT_180077818 ^ (ulonglong)&local_18;
  uStack_60 = 0x18001516c;
  (**(code **)(*param_1 + 0x90))(param_1,&local_18);
  if (local_18 == (longlong *)0x0) {
    uVar3 = 0x80004005;
    goto LAB_18001527f;
  }
  lpWideCharStr = (LPCWSTR)*param_2;
  puVar8 = auStack_58;
  if (lpWideCharStr == (LPCWSTR)0x0) {
LAB_180015213:
    pcVar9 = (char *)0x0;
  }
  else {
    lVar4 = -1;
    do {
      lVar5 = lVar4;
      lVar4 = lVar5 + 1;
    } while (lpWideCharStr[lVar4] != L'\0');
    iVar7 = (int)lVar5 + 2;
    puVar8 = auStack_58;
    if (0x3fffffff < iVar7) goto LAB_180015213;
    lVar4 = (longlong)(int)lVar4 * 2;
    uVar6 = lVar4 + 0x11;
    if (uVar6 <= lVar4 + 2U) {
      uVar6 = 0xffffffffffffff0;
    }
    uStack_60 = 0x1800151d1;
    lVar4 = -(uVar6 & 0xfffffffffffffff0);
    puVar8 = auStack_58 + lVar4;
    pcVar9 = (char *)((longlong)&local_18 + lVar4);
    if (pcVar9 == (char *)0x0) goto LAB_180015213;
    *pcVar9 = '\0';
    *(undefined8 *)((longlong)local_28 + lVar4 + 8) = 0;
    *(undefined8 *)((longlong)local_28 + lVar4) = 0;
    *(int *)((longlong)aiStack_30 + lVar4) = iVar7 * 2;
    *(char **)((longlong)&uStack_38 + lVar4) = pcVar9;
    *(undefined8 *)(auStack_58 + lVar4 + -8) = 0x180015207;
    iVar7 = WideCharToMultiByte(0,0,lpWideCharStr,-1,*(LPSTR *)((longlong)&uStack_38 + lVar4),
                                *(int *)((longlong)aiStack_30 + lVar4),
                                *(LPCSTR *)((longlong)local_28 + lVar4),
                                *(LPBOOL *)((longlong)local_28 + lVar4 + 8));
    puVar8 = auStack_58 + lVar4;
    if (iVar7 == 0) {
      puVar8 = auStack_58 + lVar4;
      pcVar9 = (char *)0x0;
    }
  }
  plVar2 = local_18;
  lVar4 = param_1[4];
  *(undefined8 *)(puVar8 + -8) = 0x180015227;
  lVar4 = HAOpenArchiveByName(pcVar9,lVar4,plVar2);
  pcVar1 = *(code **)(*local_18 + 0x10);
  *(undefined8 *)(puVar8 + -8) = 0x180015234;
  (*pcVar1)();
  if (lVar4 == 0) {
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined8 *)(puVar8 + -8) = 0x18001527d;
    FUN_18001cbb0((longlong)param_1,pcVar9);
    uVar3 = 0;
  }
  else {
    *(undefined4 *)(param_1 + 3) = 0;
    if ((longlong *)param_1[0x30] != (longlong *)0x0) {
      pcVar1 = *(code **)(*(longlong *)param_1[0x30] + 0x40);
      *(undefined8 *)(puVar8 + -8) = 0x18001524e;
      (*pcVar1)();
    }
    *(undefined8 *)(puVar8 + -8) = 0x180015253;
    Ordinal_42();
    *(undefined8 *)(puVar8 + -8) = 0x18001525b;
    FUN_18000f300((longlong)param_1);
    pcVar1 = *(code **)(*param_1 + 0x278);
    *(undefined8 *)(puVar8 + -8) = 0x18001526a;
    uVar3 = (*pcVar1)(param_1,lVar4);
  }
LAB_18001527f:
  *(undefined8 *)(puVar8 + -8) = 0x18001528b;
  return uVar3;
}

/* ---- FUNC 000152B0 FUN_1800152b0 (362 bytes) ---- */

void FUN_1800152b0(longlong *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                  undefined8 *param_5,undefined8 *param_6,undefined8 *param_7,undefined8 *param_8,
                  undefined8 *param_9)

{
  _union_2707 local_148;
  undefined8 local_128;
  _union_1719 _Stack_120;
  undefined8 local_118;
  undefined8 local_108;
  _union_1719 _Stack_100;
  undefined8 local_f8;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  VariantInit((VARIANTARG *)&local_148.n2);
  local_128 = local_148._0_8_;
  _Stack_120 = local_148.decVal.u2;
  local_108 = local_148._0_8_;
  _Stack_100 = local_148.decVal.u2;
  local_d8 = param_9[2];
  local_118 = local_148._16_8_;
  local_f8 = local_148._16_8_;
  local_e8 = *param_9;
  uStack_e0 = param_9[1];
  local_c8 = *param_8;
  uStack_c0 = param_8[1];
  local_b8 = param_8[2];
  local_a8 = *param_7;
  uStack_a0 = param_7[1];
  local_98 = param_7[2];
  local_88 = *param_6;
  uStack_80 = param_6[1];
  local_78 = param_6[2];
  local_68 = *param_5;
  uStack_60 = param_5[1];
  local_58 = param_5[2];
  local_48 = *param_4;
  uStack_40 = param_4[1];
  local_38 = param_4[2];
  local_28 = *param_3;
  uStack_20 = param_3[1];
  local_18 = param_3[2];
  FUN_180015420(param_1,param_2,&local_28,&local_48,&local_68,&local_88,&local_a8,&local_c8,
                &local_e8,(short *)&local_108,&local_128);
  return;
}

/* ---- FUNC 00015420 FUN_180015420 (678 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char * FUN_180015420(longlong *param_1,undefined8 *param_2,undefined8 param_3,undefined8 *param_4,
                    undefined8 *param_5,undefined8 *param_6,undefined8 *param_7,undefined8 *param_8,
                    undefined8 *param_9,short *param_10,undefined8 *param_11)

{
  undefined1 *puVar1;
  LPCWSTR lpWideCharStr;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  longlong lVar5;
  ulonglong uVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined8 uStackY_130;
  undefined1 auStackY_128 [32];
  uint local_e8 [4];
  _union_2707 local_d8;
  _union_2707 local_b8;
  _union_2707 local_98;
  _union_2707 local_78;
  _union_2707 local_58;
  _union_2707 local_38;
  ulonglong local_18;
  longlong lVar6;
  
  puVar10 = auStackY_128;
  local_18 = DAT_180077818 ^ (ulonglong)local_e8;
  puVar9 = (undefined1 *)0x0;
  *(undefined4 *)(param_1 + 0x12) = 0;
  local_e8[0] = 0;
  local_98._0_8_ = *param_9;
  local_98.decVal.u2 = *(_union_1719 *)(param_9 + 1);
  local_98._16_8_ = param_9[2];
  local_78._0_8_ = *param_8;
  local_78.decVal.u2 = *(_union_1719 *)(param_8 + 1);
  local_78._16_8_ = param_8[2];
  local_58._0_8_ = *param_7;
  local_58.decVal.u2 = *(_union_1719 *)(param_7 + 1);
  local_58._16_8_ = param_7[2];
  local_38._0_8_ = *param_6;
  local_38.decVal.u2 = *(_union_1719 *)(param_6 + 1);
  local_38._16_8_ = param_6[2];
  local_d8._0_8_ = *param_5;
  local_d8.decVal.u2 = *(_union_1719 *)(param_5 + 1);
  local_d8._16_8_ = param_5[2];
  local_b8._0_8_ = *param_4;
  local_b8.decVal.u2 = *(_union_1719 *)(param_4 + 1);
  local_b8._16_8_ = param_4[2];
  uStackY_130 = 0x180015541;
  pcVar4 = FUN_1800129c0(param_1,(VARIANTARG *)&local_b8.n2,(VARIANTARG *)&local_d8.n2,
                         (VARIANTARG *)&local_38.n2,(VARIANTARG *)&local_58.n2,
                         (VARIANTARG *)&local_78.n2,(VARIANTARG *)&local_98.n2,local_e8);
  if (-1 < (int)pcVar4) {
    local_b8._0_8_ = *param_11;
    local_b8.decVal.u2 = *(_union_1719 *)(param_11 + 1);
    local_b8._16_8_ = param_11[2];
    local_d8._0_8_ = *(undefined8 *)param_10;
    local_d8.decVal.u2 = *(_union_1719 *)(param_10 + 4);
    local_d8._16_8_ = *(undefined8 *)(param_10 + 8);
    uStackY_130 = 0x18001558d;
    FUN_1800139e0(param_1,(VARIANTARG *)&local_d8.n2,(VARIANTARG *)&local_b8.n2,local_e8[0]);
    lpWideCharStr = (LPCWSTR)*param_2;
    puVar10 = auStackY_128;
    puVar11 = puVar9;
    if (lpWideCharStr != (LPCWSTR)0x0) {
      lVar5 = -1;
      do {
        lVar6 = lVar5;
        lVar5 = lVar6 + 1;
      } while (lpWideCharStr[lVar5] != L'\0');
      iVar8 = (int)lVar6 + 2;
      puVar10 = auStackY_128;
      if (iVar8 < 0x40000000) {
        lVar5 = (longlong)(int)lVar5 * 2;
        uVar7 = lVar5 + 0x11;
        if (uVar7 <= lVar5 + 2U) {
          uVar7 = 0xffffffffffffff0;
        }
        uStackY_130 = 0x1800155de;
        lVar5 = -(uVar7 & 0xfffffffffffffff0);
        puVar1 = (undefined1 *)((longlong)local_e8 + lVar5);
        puVar10 = auStackY_128 + lVar5;
        if (puVar1 != (undefined1 *)0x0) {
          *(undefined8 *)(&stack0xffffffffffffff10 + lVar5) = 0;
          *(undefined8 *)(&stack0xffffffffffffff08 + lVar5) = 0;
          *(int *)((longlong)local_e8 + lVar5 + -0x18) = iVar8 * 2;
          *puVar1 = 0;
          *(undefined1 **)((longlong)local_e8 + lVar5 + -0x20) = puVar1;
          *(undefined8 *)(auStackY_128 + lVar5 + -8) = 0x180015611;
          iVar8 = WideCharToMultiByte(0,0,lpWideCharStr,-1,
                                      *(LPSTR *)((longlong)local_e8 + lVar5 + -0x20),
                                      *(int *)((longlong)local_e8 + lVar5 + -0x18),
                                      *(LPCSTR *)(&stack0xffffffffffffff08 + lVar5),
                                      *(LPBOOL *)(&stack0xffffffffffffff10 + lVar5));
          puVar10 = auStackY_128 + lVar5;
          puVar11 = puVar1;
          if (iVar8 == 0) {
            puVar10 = auStackY_128 + lVar5;
            puVar11 = puVar9;
          }
        }
      }
    }
    *(undefined8 *)(puVar10 + -8) = 0x180015624;
    uVar3 = FUN_180037480(puVar11);
    if (uVar3 == 0) {
      *(undefined8 *)(puVar10 + -8) = 0x18001562d;
      cVar2 = MMWaitFailed();
      if (cVar2 == '\0') {
        *(undefined8 *)(puVar10 + -8) = 0x18001564a;
        pcVar4 = (char *)FUN_18001a850(param_1,0x7f9);
      }
      else {
        *(undefined8 *)(puVar10 + -8) = 0x18001563e;
        pcVar4 = (char *)FUN_18001a850(param_1,0x7f8);
      }
    }
    else {
      if (*param_10 == 8) {
        do {
          puVar11 = puVar9;
          if ((*(wchar_t *)(*(longlong *)(param_10 + 4) + (longlong)puVar11 * 2) !=
               L"AspenEDRExtract"[(longlong)puVar11]) ||
             (*(wchar_t *)(*(longlong *)(param_10 + 4) + 2 + (longlong)puVar11 * 2) !=
              L"AspenEDRExtract"[(longlong)(puVar11 + 1)])) goto LAB_180015690;
          puVar9 = puVar11 + 2;
        } while (puVar11 + 2 != (undefined1 *)0x10);
        *(undefined8 *)(puVar10 + -8) = 0x180015690;
        PostMainWndMessage(0x4f8,(int)puVar11 + -8,0);
      }
LAB_180015690:
      pcVar4 = (char *)0x0;
    }
  }
  *(undefined8 *)(puVar10 + -8) = 0x1800156a1;
  return pcVar4;
}

/* ---- FUNC 000156D0 FUN_1800156d0 (225 bytes) ---- */

void FUN_1800156d0(longlong *param_1,undefined8 param_2,undefined4 *param_3)

{
  _union_2707 local_108;
  undefined8 local_e8;
  _union_1719 _Stack_e0;
  undefined8 local_d8;
  undefined8 local_c8;
  _union_1719 _Stack_c0;
  undefined8 local_b8;
  undefined8 local_a8;
  _union_1719 _Stack_a0;
  undefined8 local_98;
  undefined8 local_88;
  _union_1719 _Stack_80;
  undefined8 local_78;
  undefined8 local_68;
  _union_1719 _Stack_60;
  undefined8 local_58;
  undefined8 local_48;
  _union_1719 _Stack_40;
  undefined8 local_38;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined8 local_18;
  
  VariantInit((VARIANTARG *)&local_108.n2);
  local_d8 = local_108._16_8_;
  local_b8 = local_108._16_8_;
  local_98 = local_108._16_8_;
  local_78 = local_108._16_8_;
  local_58 = local_108._16_8_;
  local_38 = local_108._16_8_;
  local_28 = *param_3;
  uStack_24 = param_3[1];
  uStack_20 = param_3[2];
  uStack_1c = param_3[3];
  local_e8 = local_108._0_8_;
  _Stack_e0 = local_108.decVal.u2;
  local_c8 = local_108._0_8_;
  _Stack_c0 = local_108.decVal.u2;
  local_a8 = local_108._0_8_;
  _Stack_a0 = local_108.decVal.u2;
  local_88 = local_108._0_8_;
  _Stack_80 = local_108.decVal.u2;
  local_68 = local_108._0_8_;
  _Stack_60 = local_108.decVal.u2;
  local_48 = local_108._0_8_;
  _Stack_40 = local_108.decVal.u2;
  local_18 = *(undefined8 *)(param_3 + 4);
  (**(code **)(*param_1 + 400))
            (param_1,param_2,&local_28,&local_48,&local_68,&local_88,&local_a8,&local_c8,&local_e8);
  return;
}

/* ---- FUNC 000157C0 FUN_1800157c0 (635 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_1800157c0(longlong *param_1,undefined8 param_2,char *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  char *pcVar3;
  char *pcVar4;
  longlong *local_res8;
  longlong *local_res20;
  
  pcVar4 = (char *)0x0;
  local_res8 = (longlong *)0x0;
  if ((int)param_1[3] == 0) {
    SetGlobalPointer("HappNode",param_1,0);
    pcVar3 = operator_new(800);
    if (pcVar3 != (char *)0x0) {
      pcVar4 = FUN_180024da0(pcVar3,param_3);
    }
    FUN_180025150((longlong)pcVar4);
    _DAT_180079450 = "mmg.exe";
    strncpy(&DAT_180079460,pcVar4 + 0x311,8);
    DAT_180079468 = 0;
    _DAT_180079458 = &DAT_180079460;
    HAInitialize(DAT_1800776d0,&DAT_180079450,&PTR_HappNotifyThread_1800776f0,
                 &PTR_Ordinal_41_1800775d0,&local_res8);
    if ((local_res8 == (longlong *)0x0) || (*local_res8 == 0)) {
      FUN_180025110((longlong)pcVar4);
      if (pcVar4 != (char *)0x0) {
        _guard_check_icall();
        FUN_180025ad0(pcVar4);
      }
      *(undefined4 *)(param_1 + 3) = 1;
      uVar1 = HALoad2(param_2,param_3,param_1 + 4,&local_res8);
      if (((int)uVar1 < 0) || (param_1[4] == 0)) {
        *(undefined4 *)(param_1 + 3) = 0;
        if ((longlong *)param_1[0x30] != (longlong *)0x0) {
          (**(code **)(*(longlong *)param_1[0x30] + 0x40))();
        }
        Ordinal_42();
        FUN_18000f300((longlong)param_1);
        if (uVar1 == 0x8aaa0001) {
          if ((local_res8 != (longlong *)0x0) && ((code *)*local_res8 != (code *)0x0)) {
            (*(code *)*local_res8)();
          }
          uVar2 = 0x8aaa0001;
        }
        else if (local_res8 == (longlong *)0x0) {
          uVar2 = (**(code **)(*param_1 + 0x280))(param_1,0x7d1);
        }
        else {
          (**(code **)(*param_1 + 0x278))();
          uVar2 = (ulonglong)uVar1;
        }
      }
      else {
        SetGlobalPointer("FileNode",param_1[4],0);
        if (DAT_180079800 == (undefined8 *)0x0) {
          uVar2 = (*(code *)PTR_Ordinal_41_1800775d0)(param_2,0);
        }
        else {
          local_res20 = (longlong *)0x0;
          (**(code **)*DAT_180079800)(DAT_180079800,&DAT_1800635f0,&local_res20);
          uVar1 = (*(code *)PTR_Ordinal_41_1800775d0)(param_2,local_res20);
          uVar2 = (ulonglong)uVar1;
          if (local_res20 != (longlong *)0x0) {
            (**(code **)(*local_res20 + 0x10))();
          }
        }
      }
    }
    else {
      *(undefined4 *)(param_1 + 3) = 0;
      if ((longlong *)param_1[0x30] != (longlong *)0x0) {
        (**(code **)(*(longlong *)param_1[0x30] + 0x40))();
      }
      Ordinal_42();
      FUN_18000f300((longlong)param_1);
      FUN_180025110((longlong)pcVar4);
      if (pcVar4 != (char *)0x0) {
        _guard_check_icall();
        FUN_180025ad0(pcVar4);
      }
      uVar2 = (**(code **)(*param_1 + 0x278))(param_1,local_res8);
    }
    return uVar2;
  }
  uVar2 = (**(code **)(*param_1 + 0x280))(param_1,0x7e5);
  return uVar2;
}

/* ---- FUNC 00015A40 FUN_180015a40 (533 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180015a40(undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  longlong lVar1;
  char *pcVar2;
  char cVar3;
  LPCWSTR pWVar4;
  UINT UVar5;
  UINT UVar6;
  longlong lVar7;
  ulonglong uVar9;
  ulonglong uVar10;
  longlong lVar11;
  int iVar12;
  char *pcVar13;
  char *pcVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  undefined8 uStack_70;
  undefined1 auStack_68 [32];
  undefined8 uStack_48;
  int aiStack_40 [2];
  undefined8 auStack_38 [2];
  undefined8 local_28;
  longlong lVar8;
  
  local_28 = DAT_180077818 ^ (ulonglong)&local_28;
  uStack_70 = 0x180015a7c;
  UVar5 = SysStringLen((BSTR)*param_2);
  uStack_70 = 0x180015a87;
  UVar6 = SysStringLen((BSTR)*param_3);
  uVar10 = (ulonglong)(UVar6 + 3 + UVar5);
  uVar9 = uVar10 + 0xf;
  if (uVar9 <= uVar10) {
    uVar9 = 0xffffffffffffff0;
  }
  uStack_70 = 0x180015ab0;
  pWVar4 = (LPCWSTR)*param_2;
  lVar11 = -(uVar9 & 0xfffffffffffffff0);
  lVar1 = (longlong)&local_28 + lVar11;
  puVar15 = auStack_68 + lVar11;
  if (pWVar4 != (LPCWSTR)0x0) {
    lVar7 = -1;
    do {
      lVar8 = lVar7;
      lVar7 = lVar8 + 1;
    } while (pWVar4[lVar7] != L'\0');
    iVar12 = (int)lVar8 + 2;
    puVar15 = auStack_68 + lVar11;
    if (iVar12 < 0x40000000) {
      lVar7 = (longlong)(int)lVar7 * 2;
      uVar10 = lVar7 + 0x11;
      if (uVar10 <= lVar7 + 2U) {
        uVar10 = 0xffffffffffffff0;
      }
      *(undefined8 *)(auStack_68 + lVar11 + -8) = 0x180015b08;
      lVar7 = -(uVar10 & 0xfffffffffffffff0);
      puVar15 = auStack_68 + lVar7 + lVar11;
      pcVar14 = (char *)((longlong)&local_28 + lVar7 + lVar11);
      if (pcVar14 != (char *)0x0) {
        *pcVar14 = '\0';
        *(undefined8 *)((longlong)auStack_38 + lVar7 + lVar11 + 8) = 0;
        *(undefined8 *)((longlong)auStack_38 + lVar7 + lVar11) = 0;
        *(int *)((longlong)aiStack_40 + lVar7 + lVar11) = iVar12 * 2;
        *(char **)((longlong)&uStack_48 + lVar7 + lVar11) = pcVar14;
        *(undefined8 *)(auStack_68 + lVar7 + lVar11 + -8) = 0x180015b3d;
        iVar12 = WideCharToMultiByte(0,0,pWVar4,-1,*(LPSTR *)((longlong)&uStack_48 + lVar7 + lVar11)
                                     ,*(int *)((longlong)aiStack_40 + lVar7 + lVar11),
                                     *(LPCSTR *)((longlong)auStack_38 + lVar7 + lVar11),
                                     *(LPBOOL *)((longlong)auStack_38 + lVar7 + lVar11 + 8));
        puVar15 = auStack_68 + lVar7 + lVar11 + -0x68 + 0x68;
        if (iVar12 == 0) {
          puVar15 = auStack_68 + lVar7 + lVar11 + -0x68 + 0x68;
          pcVar14 = (char *)0x0;
        }
        goto LAB_180015b49;
      }
    }
  }
  pcVar14 = (char *)0x0;
LAB_180015b49:
  pcVar13 = (char *)0x0;
  lVar11 = lVar1 - (longlong)pcVar14;
  do {
    cVar3 = *pcVar14;
    pcVar14[lVar11] = cVar3;
    pcVar14 = pcVar14 + 1;
  } while (cVar3 != '\0');
  lVar11 = -1;
  do {
    lVar11 = lVar11 + 1;
  } while (*(char *)(lVar1 + lVar11) != '\0');
  puVar17 = (undefined1 *)(lVar11 + lVar1);
  *puVar17 = 0;
  pWVar4 = (LPCWSTR)*param_3;
  pcVar14 = pcVar13;
  puVar16 = puVar15;
  if (pWVar4 != (LPCWSTR)0x0) {
    lVar11 = -1;
    do {
      lVar7 = lVar11;
      lVar11 = lVar7 + 1;
    } while (pWVar4[lVar11] != L'\0');
    iVar12 = (int)lVar7 + 2;
    if (iVar12 < 0x40000000) {
      lVar11 = (longlong)(int)lVar11 * 2;
      uVar10 = lVar11 + 0x11;
      if (uVar10 <= lVar11 + 2U) {
        uVar10 = 0xffffffffffffff0;
      }
      *(undefined8 *)(puVar15 + -8) = 0x180015bb8;
      lVar11 = -(uVar10 & 0xfffffffffffffff0);
      pcVar2 = puVar15 + lVar11 + 0x40;
      puVar16 = puVar15 + lVar11;
      if (pcVar2 != (char *)0x0) {
        *(undefined8 *)(puVar15 + lVar11 + 0x38) = 0;
        *(undefined8 *)(puVar15 + lVar11 + 0x30) = 0;
        *(int *)(puVar15 + lVar11 + 0x28) = iVar12 * 2;
        *(char **)(puVar15 + lVar11 + 0x20) = pcVar2;
        *pcVar2 = '\0';
        *(undefined8 *)(puVar15 + lVar11 + -8) = 0x180015bec;
        iVar12 = WideCharToMultiByte(0,0,pWVar4,-1,*(LPSTR *)(puVar15 + lVar11 + 0x20),
                                     *(int *)(puVar15 + lVar11 + 0x28),
                                     *(LPCSTR *)(puVar15 + lVar11 + 0x30),
                                     *(LPBOOL *)(puVar15 + lVar11 + 0x38));
        pcVar14 = pcVar2;
        puVar16 = puVar15 + lVar11;
        if (iVar12 == 0) {
          pcVar14 = pcVar13;
          puVar16 = puVar15 + lVar11;
        }
      }
    }
  }
  lVar11 = 1 - (longlong)pcVar14;
  do {
    cVar3 = *pcVar14;
    pcVar14[(longlong)(puVar17 + lVar11)] = cVar3;
    pcVar14 = pcVar14 + 1;
    lVar7 = -1;
  } while (cVar3 != '\0');
  do {
    lVar11 = lVar7;
    lVar7 = lVar11 + 1;
  } while (puVar17[lVar11 + 2] != '\0');
  *(undefined2 *)(puVar17 + lVar11 + 2) = 0;
  *(undefined8 *)(puVar16 + -8) = 0x180015c2f;
  Ordinal_40(0x28,lVar1);
  *(undefined8 *)(puVar16 + -8) = 0x180015c3b;
  return;
}

/* ---- FUNC 00015C60 FUN_180015c60 (219 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180015c60(undefined8 param_1,undefined8 *param_2)

{
  LPCWSTR lpWideCharStr;
  longlong lVar1;
  ulonglong uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined8 uStack_60;
  undefined1 auStack_58 [32];
  undefined8 uStack_38;
  int aiStack_30 [2];
  undefined8 local_28 [2];
  ulonglong local_18 [2];
  longlong lVar2;
  
  local_18[0] = DAT_180077818 ^ (ulonglong)local_18;
  lpWideCharStr = (LPCWSTR)*param_2;
  puVar6 = auStack_58;
  if (lpWideCharStr != (LPCWSTR)0x0) {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (lpWideCharStr[lVar1] != L'\0');
    iVar4 = (int)lVar2 + 2;
    puVar6 = auStack_58;
    if (iVar4 < 0x40000000) {
      lVar1 = (longlong)(int)lVar1 * 2;
      uVar3 = lVar1 + 0x11;
      if (uVar3 <= lVar1 + 2U) {
        uVar3 = 0xffffffffffffff0;
      }
      uStack_60 = 0x180015cd1;
      lVar1 = -(uVar3 & 0xfffffffffffffff0);
      puVar6 = auStack_58 + lVar1;
      puVar5 = (undefined1 *)((longlong)local_18 + lVar1);
      if (puVar5 != (undefined1 *)0x0) {
        *puVar5 = 0;
        *(undefined8 *)((longlong)local_28 + lVar1 + 8) = 0;
        *(undefined8 *)((longlong)local_28 + lVar1) = 0;
        *(int *)((longlong)aiStack_30 + lVar1) = iVar4 * 2;
        *(undefined1 **)((longlong)&uStack_38 + lVar1) = puVar5;
        *(undefined8 *)(auStack_58 + lVar1 + -8) = 0x180015d07;
        iVar4 = WideCharToMultiByte(0,0,lpWideCharStr,-1,*(LPSTR *)((longlong)&uStack_38 + lVar1),
                                    *(int *)((longlong)aiStack_30 + lVar1),
                                    *(LPCSTR *)((longlong)local_28 + lVar1),
                                    *(LPBOOL *)((longlong)local_28 + lVar1 + 8));
        puVar6 = auStack_58 + lVar1;
        if (iVar4 == 0) {
          puVar5 = (undefined1 *)0x0;
          puVar6 = auStack_58 + lVar1;
        }
        goto LAB_180015d14;
      }
    }
  }
  puVar5 = (undefined1 *)0x0;
LAB_180015d14:
  *(undefined8 *)(puVar6 + -8) = 0x180015d21;
  Ordinal_40(0x1a,puVar5);
  *(undefined8 *)(puVar6 + -8) = 0x180015d2d;
  return;
}

/* ---- FUNC 00015D40 FUN_180015d40 (319 bytes) ---- */

void FUN_180015d40(longlong *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                  undefined8 *param_5,undefined8 *param_6,undefined8 *param_7,undefined8 *param_8)

{
  _union_2707 local_128;
  undefined8 local_108;
  _union_1719 _Stack_100;
  undefined8 local_f8;
  undefined8 local_e8;
  _union_1719 _Stack_e0;
  undefined8 local_d8;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  VariantInit((VARIANTARG *)&local_128.n2);
  local_108 = local_128._0_8_;
  _Stack_100 = local_128.decVal.u2;
  local_e8 = local_128._0_8_;
  _Stack_e0 = local_128.decVal.u2;
  local_b8 = param_8[2];
  local_f8 = local_128._16_8_;
  local_d8 = local_128._16_8_;
  local_c8 = *param_8;
  uStack_c0 = param_8[1];
  local_a8 = *param_7;
  uStack_a0 = param_7[1];
  local_98 = param_7[2];
  local_88 = *param_6;
  uStack_80 = param_6[1];
  local_78 = param_6[2];
  local_68 = *param_5;
  uStack_60 = param_5[1];
  local_58 = param_5[2];
  local_48 = *param_4;
  uStack_40 = param_4[1];
  local_38 = param_4[2];
  local_28 = *param_3;
  uStack_20 = param_3[1];
  local_18 = param_3[2];
  FUN_180015e80(param_1,param_2,&local_28,&local_48,&local_68,&local_88,&local_a8,&local_c8,
                &local_e8,&local_108);
  return;
}

/* ---- FUNC 00015E80 FUN_180015e80 (668 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char * FUN_180015e80(longlong *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                    undefined8 *param_5,undefined8 *param_6,undefined8 *param_7,undefined8 *param_8,
                    undefined8 *param_9,undefined8 *param_10)

{
  undefined1 *puVar1;
  LPCWSTR lpWideCharStr;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  longlong lVar5;
  ulonglong uVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined8 uStackY_130;
  undefined1 auStackY_128 [32];
  uint local_e8 [2];
  LPCSTR local_e0;
  _union_2707 local_d8;
  _union_2707 local_b8;
  _union_2707 local_98;
  _union_2707 local_78;
  _union_2707 local_58;
  _union_2707 local_38;
  ulonglong local_18;
  longlong lVar6;
  
  puVar11 = auStackY_128;
  local_18 = DAT_180077818 ^ (ulonglong)local_e8;
  puVar9 = (undefined1 *)0x0;
  *(undefined4 *)(param_1 + 0x12) = 0;
  local_e8[0] = 0;
  local_98._0_8_ = *param_8;
  local_98.decVal.u2 = *(_union_1719 *)(param_8 + 1);
  local_98._16_8_ = param_8[2];
  local_78._0_8_ = *param_7;
  local_78.decVal.u2 = *(_union_1719 *)(param_7 + 1);
  local_78._16_8_ = param_7[2];
  local_58._0_8_ = *param_6;
  local_58.decVal.u2 = *(_union_1719 *)(param_6 + 1);
  local_58._16_8_ = param_6[2];
  local_38._0_8_ = *param_5;
  local_38.decVal.u2 = *(_union_1719 *)(param_5 + 1);
  local_38._16_8_ = param_5[2];
  local_d8._0_8_ = *param_4;
  local_d8.decVal.u2 = *(_union_1719 *)(param_4 + 1);
  local_d8._16_8_ = param_4[2];
  local_b8._0_8_ = *param_3;
  local_b8.decVal.u2 = *(_union_1719 *)(param_3 + 1);
  local_b8._16_8_ = param_3[2];
  uStackY_130 = 0x180015f95;
  pcVar4 = FUN_1800129c0(param_1,(VARIANTARG *)&local_b8.n2,(VARIANTARG *)&local_d8.n2,
                         (VARIANTARG *)&local_38.n2,(VARIANTARG *)&local_58.n2,
                         (VARIANTARG *)&local_78.n2,(VARIANTARG *)&local_98.n2,local_e8);
  if (-1 < (int)pcVar4) {
    local_b8._0_8_ = *param_10;
    local_b8.decVal.u2 = *(_union_1719 *)(param_10 + 1);
    local_b8._16_8_ = param_10[2];
    local_d8._0_8_ = *param_9;
    local_d8.decVal.u2 = *(_union_1719 *)(param_9 + 1);
    local_d8._16_8_ = param_9[2];
    uStackY_130 = 0x180015fe1;
    FUN_1800139e0(param_1,(VARIANTARG *)&local_d8.n2,(VARIANTARG *)&local_b8.n2,local_e8[0]);
    if (DAT_180079800 != (longlong *)0x0) {
      uStackY_130 = 0x180015ff9;
      (**(code **)(*DAT_180079800 + 0x80))(DAT_180079800,1);
    }
    uStackY_130 = 0x18001600a;
    (**(code **)(*DAT_180079800 + 0x28))(DAT_180079800,&local_e0);
    if (local_e0 == (LPCSTR)0x0) {
      uStackY_130 = 0x18001601f;
      local_e0 = (LPCSTR)GetGlobalPointer("MMXEQ");
    }
    uStackY_130 = 0x180016028;
    SetCurrentDirectoryA(local_e0);
    lpWideCharStr = (LPCWSTR)*param_2;
    puVar10 = puVar9;
    puVar11 = auStackY_128;
    if (lpWideCharStr != (LPCWSTR)0x0) {
      lVar5 = -1;
      do {
        lVar6 = lVar5;
        lVar5 = lVar6 + 1;
      } while (lpWideCharStr[lVar5] != L'\0');
      iVar8 = (int)lVar6 + 2;
      puVar11 = auStackY_128;
      if (iVar8 < 0x40000000) {
        lVar5 = (longlong)(int)lVar5 * 2;
        uVar7 = lVar5 + 0x11;
        if (uVar7 <= lVar5 + 2U) {
          uVar7 = 0xffffffffffffff0;
        }
        uStackY_130 = 0x18001607c;
        lVar5 = -(uVar7 & 0xfffffffffffffff0);
        puVar1 = (undefined1 *)((longlong)local_e8 + lVar5);
        puVar11 = auStackY_128 + lVar5;
        if (puVar1 != (undefined1 *)0x0) {
          *(undefined8 *)(&stack0xffffffffffffff10 + lVar5) = 0;
          *(undefined8 *)(&stack0xffffffffffffff08 + lVar5) = 0;
          *(int *)(&stack0xffffffffffffff00 + lVar5) = iVar8 * 2;
          *puVar1 = 0;
          *(undefined1 **)((longlong)local_e8 + lVar5 + -0x20) = puVar1;
          *(undefined8 *)(auStackY_128 + lVar5 + -8) = 0x1800160af;
          iVar8 = WideCharToMultiByte(0,0,lpWideCharStr,-1,
                                      *(LPSTR *)((longlong)local_e8 + lVar5 + -0x20),
                                      *(int *)(&stack0xffffffffffffff00 + lVar5),
                                      *(LPCSTR *)(&stack0xffffffffffffff08 + lVar5),
                                      *(LPBOOL *)(&stack0xffffffffffffff10 + lVar5));
          puVar10 = puVar1;
          puVar11 = auStackY_128 + lVar5;
          if (iVar8 == 0) {
            puVar10 = puVar9;
            puVar11 = auStackY_128 + lVar5;
          }
        }
      }
    }
    *(undefined8 *)(puVar11 + -8) = 0x1800160c5;
    uVar3 = FUN_1800374f0(puVar10,0xffffffff);
    if (uVar3 == 0) {
      *(undefined8 *)(puVar11 + -8) = 0x1800160ce;
      cVar2 = MMWaitFailed();
      if (cVar2 == '\0') {
        *(undefined8 *)(puVar11 + -8) = 0x1800160eb;
        pcVar4 = (char *)FUN_18001a850(param_1,0x7f9);
      }
      else {
        *(undefined8 *)(puVar11 + -8) = 0x1800160df;
        pcVar4 = (char *)FUN_18001a850(param_1,0x7f8);
      }
    }
    else {
      pcVar4 = (char *)0x0;
    }
  }
  *(undefined8 *)(puVar11 + -8) = 0x1800160fe;
  return pcVar4;
}

/* ---- FUNC 00016120 FUN_180016120 (234 bytes) ---- */

void FUN_180016120(longlong *param_1,undefined8 param_2)

{
  _union_2707 local_e8;
  undefined4 local_c8;
  ULONG UStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined8 local_b8;
  undefined4 local_a8;
  ULONG UStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined8 local_98;
  undefined4 local_88;
  ULONG UStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined8 local_78;
  undefined4 local_68;
  ULONG UStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined8 local_58;
  undefined4 local_48;
  ULONG UStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  undefined4 local_28;
  ULONG UStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined8 local_18;
  
  VariantInit((VARIANTARG *)&local_e8.n2);
  local_c8 = local_e8._0_4_;
  UStack_c4 = local_e8.decVal.Hi32;
  uStack_c0 = local_e8._8_4_;
  uStack_bc = local_e8._12_4_;
  local_b8 = local_e8._16_8_;
  local_a8 = local_e8._0_4_;
  UStack_a4 = local_e8.decVal.Hi32;
  uStack_a0 = local_e8._8_4_;
  uStack_9c = local_e8._12_4_;
  local_98 = local_e8._16_8_;
  local_88 = local_e8._0_4_;
  UStack_84 = local_e8.decVal.Hi32;
  uStack_80 = local_e8._8_4_;
  uStack_7c = local_e8._12_4_;
  local_78 = local_e8._16_8_;
  local_68 = local_e8._0_4_;
  UStack_64 = local_e8.decVal.Hi32;
  uStack_60 = local_e8._8_4_;
  uStack_5c = local_e8._12_4_;
  local_58 = local_e8._16_8_;
  local_48 = local_e8._0_4_;
  UStack_44 = local_e8.decVal.Hi32;
  uStack_40 = local_e8._8_4_;
  uStack_3c = local_e8._12_4_;
  local_38 = local_e8._16_8_;
  local_28 = local_e8._0_4_;
  UStack_24 = local_e8.decVal.Hi32;
  uStack_20 = local_e8._8_4_;
  uStack_1c = local_e8._12_4_;
  local_18 = local_e8._16_8_;
  (**(code **)(*param_1 + 0x1a8))
            (param_1,param_2,&local_28,&local_48,&local_68,&local_88,&local_a8,&local_c8);
  return;
}

/* ---- FUNC 00016210 FUN_180016210 (6294 bytes) ---- */

ulonglong FUN_180016210(longlong *param_1,OLECHAR *param_2)

{
  int *piVar1;
  longlong lVar2;
  short sVar3;
  IUnknown *pIVar4;
  undefined8 **ppuVar5;
  undefined8 uVar6;
  HRESULT HVar7;
  ULONG UVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  long lVar12;
  BSTR pOVar13;
  wchar_t *pwVar14;
  char *pcVar15;
  ulonglong uVar16;
  longlong *plVar17;
  undefined8 *puVar18;
  longlong *plVar19;
  undefined8 ***ppvObject;
  int iVar20;
  undefined8 **local_res18;
  undefined8 *local_res20;
  char *local_318;
  longlong *local_310;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_308 [8];
  IUnknown *local_300;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_2f8 [8];
  longlong *local_2f0;
  _union_2707 local_2e8;
  _union_2707 local_2d0;
  _union_2707 local_2b8;
  _union_2707 local_2a0;
  _union_2707 local_288;
  _union_2707 local_270;
  _union_2707 local_258;
  _union_2707 local_240;
  int local_228;
  longlong *local_220;
  _union_2707 local_218;
  undefined4 local_200;
  undefined4 local_1fc;
  longlong *local_1f8;
  LPUNKNOWN local_1f0;
  undefined8 **local_1e8;
  undefined8 **local_1e0;
  wchar_t *local_1d8;
  longlong local_1d0;
  _union_2707 local_1c8;
  undefined8 local_1a8;
  _union_1719 _Stack_1a0;
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
  undefined8 local_128;
  _union_1719 _Stack_120;
  undefined8 local_118;
  undefined8 local_108;
  _union_1719 _Stack_100;
  undefined8 local_f8;
  undefined8 local_e8;
  _union_1719 _Stack_e0;
  undefined8 local_d8;
  undefined8 local_c8;
  _union_1719 _Stack_c0;
  undefined8 local_b8;
  undefined8 local_a8 [2];
  undefined8 local_98;
  _union_1719 _Stack_90;
  undefined8 local_88;
  longlong *local_78;
  undefined8 *local_70;
  undefined8 *local_68;
  undefined8 local_58;
  _union_1719 _Stack_50;
  undefined8 local_48;
  
  iVar11 = 0;
  local_res20 = (undefined8 *)((ulonglong)local_res20 & 0xffffffff00000000);
  local_228 = 0;
  VariantInit((VARIANTARG *)&local_2d0.n2);
  VariantInit((VARIANTARG *)&local_2e8.n2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_2f8);
  VariantInit((VARIANTARG *)&local_240.n2);
  VariantInit((VARIANTARG *)&local_2b8.n2);
  VariantInit((VARIANTARG *)&local_2a0.n2);
  VariantInit((VARIANTARG *)&local_288.n2);
  VariantInit((VARIANTARG *)&local_270.n2);
  VariantInit((VARIANTARG *)&local_258.n2);
  VariantInit((VARIANTARG *)&local_218.n2);
  VariantInit((VARIANTARG *)&local_1c8.n2);
  local_300 = (IUnknown *)0x0;
  HVar7 = CoCreateInstance((IID *)&DAT_1800642f0,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_180063898,
                           &local_1f0);
  if (-1 < HVar7) {
    HVar7 = OleRun(local_1f0);
    if (-1 < HVar7) {
      HVar7 = (*local_1f0->lpVtbl->QueryInterface)(local_1f0,(IID *)&DAT_180064110,&local_300);
    }
    (*local_1f0->lpVtbl->Release)(local_1f0);
    if (-1 < HVar7) goto LAB_180016361;
  }
  local_300 = (IUnknown *)0x0;
LAB_180016361:
  local_res18 = &local_1e8;
  local_1e8 = operator_new(0x18);
  local_1e0 = local_1e8;
  if (local_1e8 == (undefined8 **)0x0) {
    local_1e8 = (undefined8 **)0x0;
  }
  else {
    local_1e8[1] = (undefined8 *)0x0;
    *(undefined4 *)(local_1e8 + 2) = 1;
    pOVar13 = SysAllocString(param_2);
    *local_1e8 = (undefined8 *)pOVar13;
    if ((pOVar13 == (BSTR)0x0) && (param_2 != (OLECHAR *)0x0)) {
                    /* WARNING: Subroutine does not return */
      FUN_18005d290(0x8007000e);
    }
  }
  pIVar4 = local_300;
  if (local_1e8 == (undefined8 **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_18005d290(0x8007000e);
  }
  local_1e0 = &local_1e8;
  if (local_300 == (IUnknown *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_18005d290(0x80004003);
  }
  local_res18 = (undefined8 **)((ulonglong)local_res18 & 0xffffffffffff0000);
  ppvObject = &local_res18;
  UVar8 = (*local_300->lpVtbl[0x15].Release)(local_300);
  if ((int)UVar8 < 0) {
    ppvObject = (undefined8 ***)&DAT_180063908;
    _com_issue_errorex(UVar8,pIVar4,(_GUID *)&DAT_180063908);
  }
  sVar3 = (short)local_res18;
  FUN_18000b350(&local_1e8);
  if (sVar3 == 0) {
    uVar9 = (**(code **)(*param_1 + 0x280))(param_1,0x7fa);
    uVar16 = (ulonglong)uVar9;
    if (local_300 != (IUnknown *)0x0) {
      (*local_300->lpVtbl->Release)(local_300);
    }
    VariantClear((VARIANTARG *)&local_1c8.n2);
    VariantClear((VARIANTARG *)&local_218.n2);
    VariantClear((VARIANTARG *)&local_258.n2);
    VariantClear((VARIANTARG *)&local_270.n2);
    VariantClear((VARIANTARG *)&local_288.n2);
    VariantClear((VARIANTARG *)&local_2a0.n2);
    VariantClear((VARIANTARG *)&local_2b8.n2);
    VariantClear((VARIANTARG *)&local_240.n2);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_2f8);
    VariantClear((VARIANTARG *)&local_2e8.n2);
    VariantClear((VARIANTARG *)&local_2d0.n2);
  }
  else {
    local_220 = (longlong *)0x0;
    local_310 = (longlong *)0x0;
    local_2f0 = (longlong *)0x0;
    if (local_300 == (IUnknown *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_18005d290(0x80004003);
    }
    local_220 = (longlong *)0x0;
    HVar7 = (*local_300->lpVtbl[0xf].QueryInterface)(local_300,(IID *)&local_220,ppvObject);
    plVar19 = local_220;
    if (HVar7 == 0) {
      if (local_220 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_18005d290(0x80004003);
      }
      if (local_310 != (longlong *)0x0) {
        (**(code **)(*local_310 + 0x10))();
      }
      local_310 = (longlong *)0x0;
      iVar10 = (**(code **)(*plVar19 + 0x68))(plVar19,&local_310);
      plVar19 = local_310;
      iVar20 = iVar11;
      if (local_2f0 != local_310) {
        plVar17 = local_2f0;
        if (local_310 != (longlong *)0x0) {
          (**(code **)(*local_310 + 8))();
          plVar17 = local_2f0;
        }
        local_2f0 = plVar19;
        if (plVar17 != (longlong *)0x0) {
          (**(code **)(*plVar17 + 0x10))(plVar17);
        }
      }
      while (plVar19 = local_2f0, puVar18 = (undefined8 *)0x0, iVar10 == 0) {
        plVar17 = local_310;
        if (local_310 != local_2f0) {
          if (local_2f0 != (longlong *)0x0) {
            (**(code **)(*local_2f0 + 8))(local_2f0);
          }
          plVar17 = plVar19;
          if (local_310 != (longlong *)0x0) {
            lVar2 = *local_310;
            plVar17 = local_310;
            local_310 = plVar19;
            (**(code **)(lVar2 + 0x10))(plVar17);
            plVar17 = local_310;
          }
        }
        local_310 = plVar17;
        if (local_310 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_18005d290(0x80004003);
        }
        (**(code **)(*local_310 + 0x38))(local_310,local_a8);
        if (local_310 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_18005d290(0x80004003);
        }
        (**(code **)(*local_310 + 0xd0))(local_310,&local_1e0);
        uVar6 = local_a8[0];
        local_1f8 = operator_new(0x18);
        ppuVar5 = local_1e0;
        if (local_1f8 != (undefined8 *)0x0) {
          local_1f8[1] = 0;
          *(undefined4 *)(local_1f8 + 2) = 1;
          *local_1f8 = uVar6;
          puVar18 = local_1f8;
        }
        local_70 = puVar18;
        if (puVar18 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_18005d290(0x8007000e);
        }
        local_1f8 = operator_new(0x18);
        if (local_1f8 == (longlong *)0x0) {
          plVar19 = (longlong *)0x0;
        }
        else {
          local_1f8[1] = 0;
          *(undefined4 *)(local_1f8 + 2) = 1;
          *local_1f8 = (longlong)ppuVar5;
          plVar19 = local_1f8;
        }
        local_78 = plVar19;
        if (plVar19 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_18005d290(0x8007000e);
        }
        pcVar15 = (char *)puVar18[1];
        if (pcVar15 == (char *)0x0) {
          pcVar15 = FUN_18005d360((LPCWSTR)*puVar18);
          puVar18[1] = pcVar15;
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_308,pcVar15);
        pcVar15 = (char *)plVar19[1];
        if (pcVar15 == (char *)0x0) {
          pcVar15 = FUN_18005d360((LPCWSTR)*plVar19);
          plVar19[1] = (longlong)pcVar15;
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_318,
                   pcVar15);
        iVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                           (local_308,"template");
        if (iVar11 == 0) {
          if (*(int *)(local_318 + -0x10) != 0) {
            local_res20 = (undefined8 *)CONCAT44(local_res20._4_4_,1);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      (local_2f8,
                       (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                       &local_318);
          }
        }
        else {
          iVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                             (local_308,"archive");
          if (iVar11 == 0) {
            if (*(int *)(local_318 + -0x10) != 0) {
              local_228 = 1;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                        (local_2f8,
                         (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                          *)&local_318);
            }
          }
          else {
            iVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                     CompareNoCase(local_308,"file");
            if (iVar11 == 0) {
              if (*(int *)(local_318 + -0x10) != 0) {
                iVar20 = 1;
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                          (local_2f8,
                           (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                            *)&local_318);
              }
            }
            else {
              iVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                       CompareNoCase(local_308,"host_type");
              if (iVar11 == 0) {
                if (*(int *)(local_318 + -0x10) != 0) {
                  lVar12 = atol(local_318);
                  if ((local_2d0.n2.vt != 3) && (local_2d0.n2.vt != 10)) {
                    if (local_2d0.n2.vt == 0xb) {
                      local_2d0._8_2_ = -(ushort)(lVar12 != 0);
                      goto LAB_180017809;
                    }
                    uVar9 = VariantClear((VARIANTARG *)&local_2d0.n2);
                    if ((int)uVar9 < 0) {
                    /* WARNING: Subroutine does not return */
                      FUN_18005d290((ulonglong)uVar9);
                    }
                    local_2d0.n2.vt = 3;
                  }
                  local_2d0._8_2_ = (undefined2)lVar12;
                  local_2d0._10_2_ = (undefined2)((uint)lVar12 >> 0x10);
                }
              }
              else {
                iVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                         CompareNoCase(local_308,"node");
                pcVar15 = local_318;
                if (iVar11 == 0) {
                  if (*(int *)(local_318 + -0x10) != 0) {
                    uVar9 = VariantClear((VARIANTARG *)&local_240.n2);
                    if ((int)uVar9 < 0) {
                    /* WARNING: Subroutine does not return */
                      FUN_18005d290((ulonglong)uVar9);
                    }
                    local_240.n2.vt = 8;
                    local_240.decVal.u2 = (_union_1719)FUN_18005d480(pcVar15);
                  }
                }
                else {
                  iVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                           CompareNoCase(local_308,"username");
                  pcVar15 = local_318;
                  if (iVar11 == 0) {
                    if (*(int *)(local_318 + -0x10) != 0) {
                      uVar9 = VariantClear((VARIANTARG *)&local_2b8.n2);
                      if ((int)uVar9 < 0) {
                    /* WARNING: Subroutine does not return */
                        FUN_18005d290((ulonglong)uVar9);
                      }
                      local_2b8.n2.vt = 8;
                      local_2b8.decVal.u2 = (_union_1719)FUN_18005d480(pcVar15);
                    }
                  }
                  else {
                    iVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                             CompareNoCase(local_308,"password");
                    pcVar15 = local_318;
                    if (iVar11 == 0) {
                      if (*(int *)(local_318 + -0x10) != 0) {
                        uVar9 = VariantClear((VARIANTARG *)&local_2a0.n2);
                        if ((int)uVar9 < 0) {
                    /* WARNING: Subroutine does not return */
                          FUN_18005d290((ulonglong)uVar9);
                        }
                        local_2a0.n2.vt = 8;
                        local_2a0.decVal.u2 = (_union_1719)FUN_18005d480(pcVar15);
                      }
                    }
                    else {
                      iVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                               CompareNoCase(local_308,"working_directory");
                      pcVar15 = local_318;
                      if (iVar11 == 0) {
                        if (*(int *)(local_318 + -0x10) != 0) {
                          uVar9 = VariantClear((VARIANTARG *)&local_288.n2);
                          if ((int)uVar9 < 0) {
                    /* WARNING: Subroutine does not return */
                            FUN_18005d290((ulonglong)uVar9);
                          }
                          local_288.n2.vt = 8;
                          local_288.decVal.u2 = (_union_1719)FUN_18005d480(pcVar15);
                        }
                      }
                      else {
                        iVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                 ::CompareNoCase(local_308,"failmode");
                        if (iVar11 == 0) {
                          if (*(int *)(local_318 + -0x10) != 0) {
                            lVar12 = atol(local_318);
                            if ((local_2e8.n2.vt != 3) && (local_2e8.n2.vt != 10)) {
                              if (local_2e8.n2.vt == 0xb) {
                                local_2e8._8_2_ = -(ushort)(lVar12 != 0);
                                goto LAB_180017809;
                              }
                              uVar9 = VariantClear((VARIANTARG *)&local_2e8.n2);
                              if ((int)uVar9 < 0) {
                    /* WARNING: Subroutine does not return */
                                FUN_18005d290((ulonglong)uVar9);
                              }
                              local_2e8.n2.vt = 3;
                            }
                            local_2e8._8_2_ = (undefined2)lVar12;
                            local_2e8._10_2_ = (undefined2)((uint)lVar12 >> 0x10);
                          }
                        }
                        else {
                          iVar11 = ATL::
                                   CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                                   CompareNoCase(local_308,"CallingApp");
                          pcVar15 = local_318;
                          if (iVar11 == 0) {
                            if (*(int *)(local_318 + -0x10) != 0) {
                              uVar9 = VariantClear((VARIANTARG *)&local_258.n2);
                              if ((int)uVar9 < 0) {
                    /* WARNING: Subroutine does not return */
                                FUN_18005d290((ulonglong)uVar9);
                              }
                              local_258.n2.vt = 8;
                              local_258.decVal.u2 = (_union_1719)FUN_18005d480(pcVar15);
                            }
                          }
                          else {
                            iVar11 = ATL::
                                     CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                                     CompareNoCase(local_308,"dup_lic_string");
                            pcVar15 = local_318;
                            if (iVar11 == 0) {
                              if (*(int *)(local_318 + -0x10) != 0) {
                                uVar9 = VariantClear((VARIANTARG *)&local_270.n2);
                                if ((int)uVar9 < 0) {
                    /* WARNING: Subroutine does not return */
                                  FUN_18005d290((ulonglong)uVar9);
                                }
                                local_270.n2.vt = 8;
                                local_270.decVal.u2 = (_union_1719)FUN_18005d480(pcVar15);
                              }
                            }
                            else {
                              iVar11 = ATL::
                                       CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                       ::CompareNoCase(local_308,"UpwardCompDB");
                              pcVar15 = local_318;
                              if ((iVar11 == 0) && (*(int *)(local_318 + -0x10) != 0)) {
                                uVar9 = VariantClear((VARIANTARG *)&local_218.n2);
                                if ((int)uVar9 < 0) {
                    /* WARNING: Subroutine does not return */
                                  FUN_18005d290((ulonglong)uVar9);
                                }
                                local_218.n2.vt = 8;
                                local_218.decVal.u2 = (_union_1719)FUN_18005d480(pcVar15);
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
LAB_180017809:
        plVar17 = local_310;
        if (local_310 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_18005d290(0x80004003);
        }
        if (local_2f0 != (longlong *)0x0) {
          (**(code **)(*local_2f0 + 0x10))();
        }
        local_2f0 = (longlong *)0x0;
        iVar10 = (**(code **)(*plVar17 + 0x80))(plVar17,&local_2f0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_318);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_308);
        LOCK();
        plVar17 = plVar19 + 2;
        lVar2 = *plVar17;
        *(int *)plVar17 = (int)*plVar17 + -1;
        UNLOCK();
        if ((int)lVar2 == 1) {
          if ((BSTR)*plVar19 != (BSTR)0x0) {
            SysFreeString((BSTR)*plVar19);
            *plVar19 = 0;
          }
          if ((void *)plVar19[1] != (void *)0x0) {
            operator_delete__((void *)plVar19[1]);
            plVar19[1] = 0;
          }
          FUN_180025ad0(plVar19);
        }
        LOCK();
        piVar1 = (int *)(puVar18 + 2);
        iVar11 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar11 == 1) {
          if ((BSTR)*puVar18 != (BSTR)0x0) {
            SysFreeString((BSTR)*puVar18);
            *puVar18 = 0;
          }
          if ((void *)puVar18[1] != (void *)0x0) {
            operator_delete__((void *)puVar18[1]);
            puVar18[1] = 0;
          }
          FUN_180025ad0(puVar18);
          iVar11 = (int)local_res20;
        }
        else {
          iVar11 = (int)local_res20;
        }
      }
      if (local_2f0 != (longlong *)0x0) {
        (**(code **)(*local_2f0 + 0x10))(local_2f0);
      }
      if (local_310 != (longlong *)0x0) {
        (**(code **)(*local_310 + 0x10))();
      }
      if (local_220 != (longlong *)0x0) {
        (**(code **)(*local_220 + 0x10))();
      }
      if (local_218.n2.vt == 8) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1d0,
                   (wchar_t *)local_218.decVal.u2);
        if ((0 < *(int *)(local_1d0 + -0x10)) &&
           (iVar10 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                     CompareNoCase((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                   &local_1d0,"NO"), iVar10 == 0)) {
          local_200 = 1;
          SetGlobalPointer("DontShowUpward",&local_200,0);
          local_1fc = 1;
          SESetSettingValue("dontshow_upwardcompDB",&local_1fc,0,0,0);
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1d0);
      }
      pwVar14 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::AllocSysString
                          (local_2f8);
      local_1d8 = pwVar14;
      local_res20 = operator_new(0x18);
      puVar18 = (undefined8 *)0x0;
      if (local_res20 != (undefined8 *)0x0) {
        local_res20[1] = 0;
        *(undefined4 *)(local_res20 + 2) = 1;
        *local_res20 = pwVar14;
        puVar18 = local_res20;
      }
      local_68 = puVar18;
      if (puVar18 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_18005d290(0x8007000e);
      }
      local_98 = CONCAT62(local_270._2_6_,local_270.n2.vt);
      if (iVar11 == 1) {
        _Stack_1a0 = local_270.decVal.u2;
        local_198 = local_270._16_8_;
        local_188 = CONCAT62(local_258._2_6_,local_258.n2.vt);
        _Stack_180 = local_258.decVal.u2;
        local_178 = local_258._16_8_;
        local_168 = CONCAT62(local_2e8._2_6_,local_2e8.n2.vt);
        _Stack_160 = (_union_1719)
                     CONCAT44(local_2e8._12_4_,CONCAT22(local_2e8._10_2_,local_2e8._8_2_));
        local_158 = local_2e8._16_8_;
        local_148 = CONCAT62(local_288._2_6_,local_288.n2.vt);
        _Stack_140 = local_288.decVal.u2;
        local_138 = local_288._16_8_;
        local_128 = CONCAT62(local_2a0._2_6_,local_2a0.n2.vt);
        _Stack_120 = local_2a0.decVal.u2;
        local_118 = local_2a0._16_8_;
        local_108 = CONCAT62(local_2b8._2_6_,local_2b8.n2.vt);
        _Stack_100 = local_2b8.decVal.u2;
        local_f8 = local_2b8._16_8_;
        local_e8 = CONCAT62(local_240._2_6_,local_240.n2.vt);
        _Stack_e0 = local_240.decVal.u2;
        local_d8 = local_240._16_8_;
        local_c8 = CONCAT62(local_2d0._2_6_,local_2d0.n2.vt);
        _Stack_c0 = (_union_1719)
                    CONCAT44(local_2d0._12_4_,CONCAT22(local_2d0._10_2_,local_2d0._8_2_));
        local_b8 = local_2d0._16_8_;
        local_1a8 = local_98;
        pcVar15 = FUN_180015e80(param_1,&local_1d8,&local_c8,&local_e8,&local_108,&local_128,
                                &local_148,&local_168,&local_188,&local_1a8);
        uVar16 = (ulonglong)pcVar15 & 0xffffffff;
        LOCK();
        piVar1 = (int *)(puVar18 + 2);
        iVar11 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar11 == 1) {
          if ((BSTR)*puVar18 != (BSTR)0x0) {
            SysFreeString((BSTR)*puVar18);
            *puVar18 = 0;
          }
          if ((void *)puVar18[1] != (void *)0x0) {
            operator_delete__((void *)puVar18[1]);
            puVar18[1] = 0;
          }
          FUN_180025ad0(puVar18);
        }
        if (local_300 != (IUnknown *)0x0) {
          (*local_300->lpVtbl->Release)(local_300);
        }
        VariantClear((VARIANTARG *)&local_1c8.n2);
        VariantClear((VARIANTARG *)&local_218.n2);
        VariantClear((VARIANTARG *)&local_258.n2);
        VariantClear((VARIANTARG *)&local_270.n2);
        VariantClear((VARIANTARG *)&local_288.n2);
        VariantClear((VARIANTARG *)&local_2a0.n2);
        VariantClear((VARIANTARG *)&local_2b8.n2);
        VariantClear((VARIANTARG *)&local_240.n2);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_2f8);
        VariantClear((VARIANTARG *)&local_2e8.n2);
        VariantClear((VARIANTARG *)&local_2d0.n2);
      }
      else {
        local_c8 = local_98;
        if (local_228 == 1) {
          _Stack_c0 = local_270.decVal.u2;
          local_b8 = local_270._16_8_;
          local_e8 = CONCAT62(local_258._2_6_,local_258.n2.vt);
          _Stack_e0 = local_258.decVal.u2;
          local_d8 = local_258._16_8_;
          local_108 = CONCAT62(local_2e8._2_6_,local_2e8.n2.vt);
          _Stack_100 = (_union_1719)
                       CONCAT44(local_2e8._12_4_,CONCAT22(local_2e8._10_2_,local_2e8._8_2_));
          local_f8 = local_2e8._16_8_;
          local_128 = CONCAT62(local_288._2_6_,local_288.n2.vt);
          _Stack_120 = local_288.decVal.u2;
          local_118 = local_288._16_8_;
          local_148 = CONCAT62(local_2a0._2_6_,local_2a0.n2.vt);
          _Stack_140 = local_2a0.decVal.u2;
          local_138 = local_2a0._16_8_;
          local_168 = CONCAT62(local_2b8._2_6_,local_2b8.n2.vt);
          _Stack_160 = local_2b8.decVal.u2;
          local_158 = local_2b8._16_8_;
          local_188 = CONCAT62(local_240._2_6_,local_240.n2.vt);
          _Stack_180 = local_240.decVal.u2;
          local_178 = local_240._16_8_;
          local_1a8 = CONCAT62(local_2d0._2_6_,local_2d0.n2.vt);
          _Stack_1a0 = (_union_1719)
                       CONCAT44(local_2d0._12_4_,CONCAT22(local_2d0._10_2_,local_2d0._8_2_));
          local_198 = local_2d0._16_8_;
          pcVar15 = FUN_180014960(param_1,&local_1d8,&local_1a8,&local_188,&local_168,&local_148,
                                  &local_128,&local_108,(short *)&local_e8,&local_c8);
          uVar16 = (ulonglong)pcVar15 & 0xffffffff;
          LOCK();
          piVar1 = (int *)(puVar18 + 2);
          iVar11 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar11 == 1) {
            if ((BSTR)*puVar18 != (BSTR)0x0) {
              SysFreeString((BSTR)*puVar18);
              *puVar18 = 0;
            }
            if ((void *)puVar18[1] != (void *)0x0) {
              operator_delete__((void *)puVar18[1]);
              puVar18[1] = 0;
            }
            FUN_180025ad0(puVar18);
          }
          if (local_300 != (IUnknown *)0x0) {
            (*local_300->lpVtbl->Release)(local_300);
          }
          VariantClear((VARIANTARG *)&local_1c8.n2);
          VariantClear((VARIANTARG *)&local_218.n2);
          VariantClear((VARIANTARG *)&local_258.n2);
          VariantClear((VARIANTARG *)&local_270.n2);
          VariantClear((VARIANTARG *)&local_288.n2);
          VariantClear((VARIANTARG *)&local_2a0.n2);
          VariantClear((VARIANTARG *)&local_2b8.n2);
          VariantClear((VARIANTARG *)&local_240.n2);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_2f8);
          VariantClear((VARIANTARG *)&local_2e8.n2);
          VariantClear((VARIANTARG *)&local_2d0.n2);
        }
        else if (iVar20 == 1) {
          _Stack_c0 = local_270.decVal.u2;
          local_b8 = local_270._16_8_;
          local_e8 = CONCAT62(local_258._2_6_,local_258.n2.vt);
          _Stack_e0 = local_258.decVal.u2;
          local_d8 = local_258._16_8_;
          local_108 = CONCAT62(local_2e8._2_6_,local_2e8.n2.vt);
          _Stack_100 = (_union_1719)
                       CONCAT44(local_2e8._12_4_,CONCAT22(local_2e8._10_2_,local_2e8._8_2_));
          local_f8 = local_2e8._16_8_;
          local_128 = CONCAT62(local_288._2_6_,local_288.n2.vt);
          _Stack_120 = local_288.decVal.u2;
          local_118 = local_288._16_8_;
          local_148 = CONCAT62(local_2a0._2_6_,local_2a0.n2.vt);
          _Stack_140 = local_2a0.decVal.u2;
          local_138 = local_2a0._16_8_;
          local_168 = CONCAT62(local_2b8._2_6_,local_2b8.n2.vt);
          _Stack_160 = local_2b8.decVal.u2;
          local_158 = local_2b8._16_8_;
          local_188 = CONCAT62(local_240._2_6_,local_240.n2.vt);
          _Stack_180 = local_240.decVal.u2;
          local_178 = local_240._16_8_;
          local_1a8 = CONCAT62(local_2d0._2_6_,local_2d0.n2.vt);
          _Stack_1a0 = (_union_1719)
                       CONCAT44(local_2d0._12_4_,CONCAT22(local_2d0._10_2_,local_2d0._8_2_));
          local_198 = local_2d0._16_8_;
          local_98 = local_1c8._0_8_;
          _Stack_90 = local_1c8.decVal.u2;
          local_88 = local_1c8._16_8_;
          pcVar15 = FUN_180015420(param_1,&local_1d8,&local_98,&local_1a8,&local_188,&local_168,
                                  &local_148,&local_128,&local_108,(short *)&local_e8,&local_c8);
          uVar16 = (ulonglong)pcVar15 & 0xffffffff;
          LOCK();
          piVar1 = (int *)(puVar18 + 2);
          iVar11 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar11 == 1) {
            if ((BSTR)*puVar18 != (BSTR)0x0) {
              SysFreeString((BSTR)*puVar18);
              *puVar18 = 0;
            }
            if ((void *)puVar18[1] != (void *)0x0) {
              operator_delete__((void *)puVar18[1]);
              puVar18[1] = 0;
            }
            FUN_180025ad0(puVar18);
          }
          if (local_300 != (IUnknown *)0x0) {
            (*local_300->lpVtbl->Release)(local_300);
          }
          VariantClear((VARIANTARG *)&local_1c8.n2);
          VariantClear((VARIANTARG *)&local_218.n2);
          VariantClear((VARIANTARG *)&local_258.n2);
          VariantClear((VARIANTARG *)&local_270.n2);
          VariantClear((VARIANTARG *)&local_288.n2);
          VariantClear((VARIANTARG *)&local_2a0.n2);
          VariantClear((VARIANTARG *)&local_2b8.n2);
          VariantClear((VARIANTARG *)&local_240.n2);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_2f8);
          VariantClear((VARIANTARG *)&local_2e8.n2);
          VariantClear((VARIANTARG *)&local_2d0.n2);
        }
        else {
          _Stack_90 = local_270.decVal.u2;
          local_88 = local_270._16_8_;
          local_c8 = CONCAT62(local_258._2_6_,local_258.n2.vt);
          _Stack_c0 = local_258.decVal.u2;
          local_b8 = local_258._16_8_;
          local_e8 = CONCAT62(local_2e8._2_6_,local_2e8.n2.vt);
          _Stack_e0 = (_union_1719)
                      CONCAT44(local_2e8._12_4_,CONCAT22(local_2e8._10_2_,local_2e8._8_2_));
          local_d8 = local_2e8._16_8_;
          local_108 = CONCAT62(local_288._2_6_,local_288.n2.vt);
          _Stack_100 = local_288.decVal.u2;
          local_f8 = local_288._16_8_;
          local_128 = CONCAT62(local_2a0._2_6_,local_2a0.n2.vt);
          _Stack_120 = local_2a0.decVal.u2;
          local_118 = local_2a0._16_8_;
          local_148 = CONCAT62(local_2b8._2_6_,local_2b8.n2.vt);
          _Stack_140 = local_2b8.decVal.u2;
          local_138 = local_2b8._16_8_;
          local_168 = CONCAT62(local_240._2_6_,local_240.n2.vt);
          _Stack_160 = local_240.decVal.u2;
          local_158 = local_240._16_8_;
          local_188 = CONCAT62(local_2d0._2_6_,local_2d0.n2.vt);
          _Stack_180 = (_union_1719)
                       CONCAT44(local_2d0._12_4_,CONCAT22(local_2d0._10_2_,local_2d0._8_2_));
          local_178 = local_2d0._16_8_;
          local_1a8 = local_1c8._0_8_;
          _Stack_1a0 = local_1c8.decVal.u2;
          local_198 = local_1c8._16_8_;
          local_58 = local_1c8._0_8_;
          _Stack_50 = local_1c8.decVal.u2;
          local_48 = local_1c8._16_8_;
          pcVar15 = FUN_180017c40(param_1,&local_58,&local_1a8,&local_188,&local_168,&local_148,
                                  &local_128,&local_108,&local_e8,&local_c8,&local_98);
          uVar16 = (ulonglong)pcVar15 & 0xffffffff;
          LOCK();
          piVar1 = (int *)(puVar18 + 2);
          iVar11 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar11 == 1) {
            if ((BSTR)*puVar18 != (BSTR)0x0) {
              SysFreeString((BSTR)*puVar18);
              *puVar18 = 0;
            }
            if ((void *)puVar18[1] != (void *)0x0) {
              operator_delete__((void *)puVar18[1]);
              puVar18[1] = 0;
            }
            FUN_180025ad0(puVar18);
          }
          if (local_300 != (IUnknown *)0x0) {
            (*local_300->lpVtbl->Release)(local_300);
          }
          VariantClear((VARIANTARG *)&local_1c8.n2);
          VariantClear((VARIANTARG *)&local_218.n2);
          VariantClear((VARIANTARG *)&local_258.n2);
          VariantClear((VARIANTARG *)&local_270.n2);
          VariantClear((VARIANTARG *)&local_288.n2);
          VariantClear((VARIANTARG *)&local_2a0.n2);
          VariantClear((VARIANTARG *)&local_2b8.n2);
          VariantClear((VARIANTARG *)&local_240.n2);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_2f8);
          VariantClear((VARIANTARG *)&local_2e8.n2);
          VariantClear((VARIANTARG *)&local_2d0.n2);
        }
      }
    }
    else {
      uVar9 = (**(code **)(*param_1 + 0x280))(param_1,0x7fa);
      uVar16 = (ulonglong)uVar9;
      if (local_2f0 != (longlong *)0x0) {
        (**(code **)(*local_2f0 + 0x10))();
      }
      if (local_310 != (longlong *)0x0) {
        (**(code **)(*local_310 + 0x10))();
      }
      if (local_220 != (longlong *)0x0) {
        (**(code **)(*local_220 + 0x10))();
      }
      if (local_300 != (IUnknown *)0x0) {
        (*local_300->lpVtbl->Release)(local_300);
      }
      VariantClear((VARIANTARG *)&local_1c8.n2);
      VariantClear((VARIANTARG *)&local_218.n2);
      VariantClear((VARIANTARG *)&local_258.n2);
      VariantClear((VARIANTARG *)&local_270.n2);
      VariantClear((VARIANTARG *)&local_288.n2);
      VariantClear((VARIANTARG *)&local_2a0.n2);
      VariantClear((VARIANTARG *)&local_2b8.n2);
      VariantClear((VARIANTARG *)&local_240.n2);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_2f8);
      VariantClear((VARIANTARG *)&local_2e8.n2);
      VariantClear((VARIANTARG *)&local_2d0.n2);
    }
  }
  return uVar16;
}

/* ---- FUNC 00017AB0 FUN_180017ab0 (389 bytes) ---- */

void FUN_180017ab0(longlong *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                  undefined8 *param_5,undefined8 *param_6,undefined8 *param_7,undefined8 *param_8,
                  undefined8 *param_9)

{
  _union_2707 local_168;
  undefined8 local_148;
  _union_1719 _Stack_140;
  undefined8 local_138;
  undefined8 local_128;
  _union_1719 _Stack_120;
  undefined8 local_118;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  VariantInit((VARIANTARG *)&local_168.n2);
  local_148 = local_168._0_8_;
  _Stack_140 = local_168.decVal.u2;
  local_128 = local_168._0_8_;
  _Stack_120 = local_168.decVal.u2;
  local_f8 = param_9[2];
  local_138 = local_168._16_8_;
  local_118 = local_168._16_8_;
  local_108 = *param_9;
  uStack_100 = param_9[1];
  local_e8 = *param_8;
  uStack_e0 = param_8[1];
  local_d8 = param_8[2];
  local_c8 = *param_7;
  uStack_c0 = param_7[1];
  local_b8 = param_7[2];
  local_a8 = *param_6;
  uStack_a0 = param_6[1];
  local_98 = param_6[2];
  local_88 = *param_5;
  uStack_80 = param_5[1];
  local_78 = param_5[2];
  local_68 = *param_4;
  uStack_60 = param_4[1];
  local_58 = param_4[2];
  local_48 = *param_3;
  uStack_40 = param_3[1];
  local_38 = param_3[2];
  local_28 = *param_2;
  uStack_20 = param_2[1];
  local_18 = param_2[2];
  FUN_180017c40(param_1,&local_28,&local_48,&local_68,&local_88,&local_a8,&local_c8,&local_e8,
                &local_108,&local_128,&local_148);
  return;
}

/* ---- FUNC 00017C40 FUN_180017c40 (394 bytes) ---- */

char * FUN_180017c40(longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4,
                    undefined8 *param_5,undefined8 *param_6,undefined8 *param_7,undefined8 *param_8,
                    undefined8 *param_9,undefined8 *param_10,undefined8 *param_11)

{
  uint uVar1;
  char *pcVar2;
  uint local_res8 [2];
  LPCSTR local_res20;
  _union_2707 local_c8;
  _union_2707 local_a8;
  _union_2707 local_88;
  _union_2707 local_68;
  _union_2707 local_48;
  _union_2707 local_28;
  
  *(undefined4 *)(param_1 + 0x12) = 0;
  (**(code **)(*DAT_180079800 + 0x28))(DAT_180079800,&local_res20);
  if (local_res20 == (LPCSTR)0x0) {
    local_res20 = (LPCSTR)GetGlobalPointer("MMXEQ");
  }
  SetCurrentDirectoryA(local_res20);
  local_res8[0] = 0;
  local_88._0_8_ = *param_9;
  local_88.decVal.u2 = *(_union_1719 *)(param_9 + 1);
  local_88._16_8_ = param_9[2];
  local_68._0_8_ = *param_8;
  local_68.decVal.u2 = *(_union_1719 *)(param_8 + 1);
  local_68._16_8_ = param_8[2];
  local_48._0_8_ = *param_7;
  local_48.decVal.u2 = *(_union_1719 *)(param_7 + 1);
  local_48._16_8_ = param_7[2];
  local_28._0_8_ = *param_6;
  local_28.decVal.u2 = *(_union_1719 *)(param_6 + 1);
  local_28._16_8_ = param_6[2];
  local_c8._0_8_ = *param_5;
  local_c8.decVal.u2 = *(_union_1719 *)(param_5 + 1);
  local_c8._16_8_ = param_5[2];
  local_a8._0_8_ = *param_4;
  local_a8.decVal.u2 = *(_union_1719 *)(param_4 + 1);
  local_a8._16_8_ = param_4[2];
  pcVar2 = FUN_1800129c0(param_1,(VARIANTARG *)&local_a8.n2,(VARIANTARG *)&local_c8.n2,
                         (VARIANTARG *)&local_28.n2,(VARIANTARG *)&local_48.n2,
                         (VARIANTARG *)&local_68.n2,(VARIANTARG *)&local_88.n2,local_res8);
  if (-1 < (int)pcVar2) {
    local_a8._0_8_ = *param_11;
    local_a8.decVal.u2 = *(_union_1719 *)(param_11 + 1);
    local_a8._16_8_ = param_11[2];
    local_c8._0_8_ = *param_10;
    local_c8.decVal.u2 = *(_union_1719 *)(param_10 + 1);
    local_c8._16_8_ = param_10[2];
    FUN_1800139e0(param_1,(VARIANTARG *)&local_c8.n2,(VARIANTARG *)&local_a8.n2,local_res8[0]);
    uVar1 = FUN_180037440();
    if (uVar1 == 0) {
      pcVar2 = (char *)FUN_18001a850(param_1,0x7d1);
    }
    else {
      pcVar2 = (char *)0x0;
    }
  }
  return pcVar2;
}

/* ---- FUNC 00017DD0 FUN_180017dd0 (243 bytes) ---- */

void FUN_180017dd0(longlong *param_1,undefined4 *param_2,undefined8 *param_3)

{
  _union_2707 local_128;
  undefined8 local_108;
  _union_1719 _Stack_100;
  undefined8 local_f8;
  undefined8 local_e8;
  _union_1719 _Stack_e0;
  undefined8 local_d8;
  undefined8 local_c8;
  _union_1719 _Stack_c0;
  undefined8 local_b8;
  undefined8 local_a8;
  _union_1719 _Stack_a0;
  undefined8 local_98;
  undefined8 local_88;
  _union_1719 _Stack_80;
  undefined8 local_78;
  undefined8 local_68;
  _union_1719 _Stack_60;
  undefined8 local_58;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined8 local_18;
  
  VariantInit((VARIANTARG *)&local_128.n2);
  local_f8 = local_128._16_8_;
  local_d8 = local_128._16_8_;
  local_b8 = local_128._16_8_;
  local_98 = local_128._16_8_;
  local_78 = local_128._16_8_;
  local_58 = local_128._16_8_;
  local_48 = *param_3;
  uStack_40 = param_3[1];
  local_108 = local_128._0_8_;
  _Stack_100 = local_128.decVal.u2;
  local_e8 = local_128._0_8_;
  _Stack_e0 = local_128.decVal.u2;
  local_c8 = local_128._0_8_;
  _Stack_c0 = local_128.decVal.u2;
  local_a8 = local_128._0_8_;
  _Stack_a0 = local_128.decVal.u2;
  local_88 = local_128._0_8_;
  _Stack_80 = local_128.decVal.u2;
  local_68 = local_128._0_8_;
  _Stack_60 = local_128.decVal.u2;
  local_38 = param_3[2];
  local_28 = *param_2;
  uStack_24 = param_2[1];
  uStack_20 = param_2[2];
  uStack_1c = param_2[3];
  local_18 = *(undefined8 *)(param_2 + 4);
  (**(code **)(*param_1 + 0x188))
            (param_1,&local_28,&local_48,&local_68,&local_88,&local_a8,&local_c8,&local_e8,
             &local_108);
  return;
}

/* ---- FUNC 00017ED0 FUN_180017ed0 (457 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_180017ed0(longlong *param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong local_res8;
  undefined8 local_res18 [2];
  
  local_res8 = 0;
  if ((int)param_1[3] != 0) {
    uVar2 = (**(code **)(*param_1 + 0x280))(param_1,0x7e5);
    return uVar2;
  }
  SetGlobalPointer("HappNode",param_1,0);
  _DAT_180079470 = "mmg.exe";
  HAInitialize(DAT_1800776d4,&DAT_180079470,&PTR_HappNotifyThread_1800776f0,
               &PTR_Ordinal_41_1800775d0,&local_res8);
  if (local_res8 == 0) {
    lVar3 = HAInitNew(param_2,&local_res8,0);
    param_1[4] = lVar3;
    if (lVar3 != 0) {
      local_res18[0] = 0;
      if (DAT_180079800 != (undefined8 *)0x0) {
        (**(code **)*DAT_180079800)(DAT_180079800,&DAT_1800635f0,local_res18);
      }
      iVar1 = (*(code *)PTR_Ordinal_41_1800775d0)(0,local_res18[0]);
      if (iVar1 == 0) {
        SetGlobalPointer("FileNode",param_1[4],0);
        *(undefined4 *)(param_1 + 3) = 1;
        *(undefined4 *)(param_1 + 0x20) = 0;
        return 0;
      }
      lVar3 = *param_1;
      iVar1 = GRinqsme();
      if (iVar1 == 1) {
        uVar2 = (**(code **)(lVar3 + 0x280))(param_1,0x7f6);
        return uVar2;
      }
      if (iVar1 != 2) {
        if (iVar1 != 3) {
          uVar2 = (**(code **)(lVar3 + 0x280))(param_1,0x7d1);
          return uVar2;
        }
        uVar2 = (**(code **)(lVar3 + 0x280))(param_1,0x7f8);
        return uVar2;
      }
      uVar2 = (**(code **)(lVar3 + 0x280))(param_1,0x7f7);
      return uVar2;
    }
    lVar3 = *param_1;
    if (local_res8 == 0) {
      uVar2 = (**(code **)(lVar3 + 0x280))(param_1,0x7d1);
      return uVar2;
    }
  }
  else {
    lVar3 = *param_1;
    *(undefined4 *)(param_1 + 3) = 0;
  }
  uVar2 = (**(code **)(lVar3 + 0x278))(param_1);
  return uVar2;
}

/* ---- FUNC 000180A0 FUN_1800180a0 (455 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

BSTR FUN_1800180a0(undefined8 param_1,BSTR param_2,short param_3,undefined8 *param_4)

{
  CApwnLibraries *this;
  bool bVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar5;
  BSTR bstrString;
  int iVar6;
  undefined1 *puVar7;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar8;
  BSTR pOVar9;
  undefined8 uStack_e0;
  undefined1 auStack_d8 [32];
  undefined8 uStack_b8;
  int aiStack_b0 [2];
  undefined8 local_a8 [2];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_98 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_90 [8];
  char local_88 [80];
  ulonglong local_38;
  longlong lVar4;
  
  local_38 = DAT_180077818 ^ (ulonglong)local_98;
  uStack_e0 = 0x1800180dd;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_98);
  puVar7 = auStack_d8;
  if (param_2 != (BSTR)0x0) {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_2[lVar3] != L'\0');
    iVar6 = (int)lVar4 + 2;
    puVar7 = auStack_d8;
    if (iVar6 < 0x40000000) {
      lVar3 = (longlong)(int)lVar3 * 2;
      uVar5 = lVar3 + 0x11;
      if (uVar5 <= lVar3 + 2U) {
        uVar5 = 0xffffffffffffff0;
      }
      uStack_e0 = 0x18001812c;
      lVar3 = -(uVar5 & 0xfffffffffffffff0);
      puVar7 = auStack_d8 + lVar3;
      pCVar8 = local_98 + lVar3;
      if (pCVar8 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        *pCVar8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>)0x0;
        *(undefined8 *)((longlong)local_a8 + lVar3 + 8) = 0;
        *(undefined8 *)((longlong)local_a8 + lVar3) = 0;
        *(int *)((longlong)aiStack_b0 + lVar3) = iVar6 * 2;
        *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
         ((longlong)&uStack_b8 + lVar3) = pCVar8;
        *(undefined8 *)(auStack_d8 + lVar3 + -8) = 0x180018165;
        iVar6 = WideCharToMultiByte(0,0,param_2,-1,*(LPSTR *)((longlong)&uStack_b8 + lVar3),
                                    *(int *)((longlong)aiStack_b0 + lVar3),
                                    *(LPCSTR *)((longlong)local_a8 + lVar3),
                                    *(LPBOOL *)((longlong)local_a8 + lVar3 + 8));
        puVar7 = auStack_d8 + lVar3;
        if (iVar6 == 0) {
          puVar7 = auStack_d8 + lVar3;
          pCVar8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
        }
        goto LAB_180018171;
      }
    }
  }
  pCVar8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
LAB_180018171:
  *(undefined8 *)(puVar7 + -8) = 0x18001817e;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            (local_98,(char *)pCVar8);
  *(undefined8 *)(puVar7 + -8) = 0x180018187;
  SysFreeString(param_2);
  *(undefined4 *)(puVar7 + 0x28) = 1;
  *(undefined4 *)(puVar7 + 0x20) = 0x50;
  this = *(CApwnLibraries **)g_pApwnLibs_exref;
  *(undefined8 *)(puVar7 + -8) = 0x1800181b2;
  bVar1 = CApwnLibraries::InsertLibrary
                    (this,local_98,(int)param_3,local_88,*(long *)(puVar7 + 0x20),
                     *(int *)(puVar7 + 0x28));
  pOVar9 = (BSTR)0x80004005;
  if (bVar1) {
    pOVar9 = (BSTR)0x0;
  }
  *(undefined8 *)(puVar7 + -8) = 0x1800181cc;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_90,local_88);
  *(undefined4 *)(puVar7 + 0x28) = 0;
  *(undefined8 *)(puVar7 + 0x20) = 0;
  *(undefined8 *)(puVar7 + -8) = 0x1800181e9;
  iVar6 = MultiByteToWideChar(0,0,local_88,-1,*(LPWSTR *)(puVar7 + 0x20),*(int *)(puVar7 + 0x28));
  *(undefined8 *)(puVar7 + -8) = 0x1800181f6;
  bstrString = SysAllocStringLen((OLECHAR *)0x0,iVar6 - 1);
  if (bstrString != (BSTR)0x0) {
    *(int *)(puVar7 + 0x28) = iVar6;
    *(BSTR *)(puVar7 + 0x20) = bstrString;
    *(undefined8 *)(puVar7 + -8) = 0x18001821b;
    iVar2 = MultiByteToWideChar(0,0,local_88,-1,*(LPWSTR *)(puVar7 + 0x20),*(int *)(puVar7 + 0x28));
    if (iVar2 != iVar6) {
      *(undefined8 *)(puVar7 + -8) = 0x180018228;
      SysFreeString(bstrString);
      bstrString = (BSTR)0x0;
    }
  }
  *param_4 = bstrString;
  *(undefined8 *)(puVar7 + -8) = 0x18001823a;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_90);
  *(undefined8 *)(puVar7 + -8) = 0x180018245;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_98);
  *(undefined8 *)(puVar7 + -8) = 0x180018254;
  return pOVar9;
}

/* ---- FUNC 00018270 FUN_180018270 (144 bytes) ---- */

void FUN_180018270(undefined8 param_1,undefined4 param_2,undefined8 param_3,LCID param_4,
                  undefined2 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
                  undefined8 param_9)

{
  if ((DAT_180077678 == (longlong *)0x0) || (DAT_180077688 == 0)) {
    FUN_1800123a0(&PTR_DAT_180077660,param_4);
  }
  if (DAT_180077678 != (longlong *)0x0) {
    (**(code **)(*DAT_180077678 + 0x58))
              (DAT_180077678,param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}

/* ---- FUNC 00018300 FUN_180018300 (144 bytes) ---- */

void FUN_180018300(undefined8 param_1,undefined4 param_2,undefined8 param_3,LCID param_4,
                  undefined2 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
                  undefined8 param_9)

{
  if ((DAT_1800776b0 == (longlong *)0x0) || (DAT_1800776c0 == 0)) {
    FUN_1800123a0(&PTR_DAT_180077698,param_4);
  }
  if (DAT_1800776b0 != (longlong *)0x0) {
    (**(code **)(*DAT_1800776b0 + 0x58))
              (DAT_1800776b0,param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}

/* ---- FUNC 00018390 FUN_180018390 (46 bytes) ---- */

undefined8 FUN_180018390(longlong param_1,int param_2)

{
  void *pv;
  int iVar1;
  undefined8 *in_stack_00000030;
  SAFEARRAYBOUND local_18 [2];
  
  if (((param_2 == 0x65) && (*(int *)(in_stack_00000030 + 2) == 2)) &&
     (*(short *)*in_stack_00000030 == 8)) {
    pv = *(void **)((short *)*in_stack_00000030 + 4);
    if ((*(SAFEARRAY **)(param_1 + 0x18) != (SAFEARRAY *)0x0) &&
       (*(int *)(param_1 + 0x28) <= *(int *)(param_1 + 0x24))) {
      local_18[0].lLbound = *(int *)(param_1 + 0x20);
      iVar1 = ((*(int *)(param_1 + 0x28) - local_18[0].lLbound) + 1) * 3;
      local_18[0].cElements = 10;
      if (0x15 < iVar1) {
        local_18[0].cElements = iVar1 / 2;
      }
      SafeArrayRedim(*(SAFEARRAY **)(param_1 + 0x18),local_18);
      *(ULONG *)(param_1 + 0x28) = *(int *)(param_1 + 0x20) + (local_18[0].cElements - 1);
    }
    if (*(SAFEARRAY **)(param_1 + 0x18) != (SAFEARRAY *)0x0) {
      SafeArrayPutElement(*(SAFEARRAY **)(param_1 + 0x18),(LONG *)(param_1 + 0x24),pv);
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
    }
    return 0;
  }
  return 0;
}

/* ---- FUNC 000183BE FUN_1800183be (131 bytes) ---- */

undefined8 FUN_1800183be(longlong param_1)

{
  void *pv;
  int iVar1;
  longlong unaff_RBX;
  SAFEARRAYBOUND SStackX_20;
  
  pv = *(void **)(param_1 + 8);
  if ((*(SAFEARRAY **)(unaff_RBX + 0x18) != (SAFEARRAY *)0x0) &&
     (*(int *)(unaff_RBX + 0x28) <= *(int *)(unaff_RBX + 0x24))) {
    SStackX_20.lLbound = *(int *)(unaff_RBX + 0x20);
    iVar1 = ((*(int *)(unaff_RBX + 0x28) - SStackX_20.lLbound) + 1) * 3;
    SStackX_20.cElements = 10;
    if (0x15 < iVar1) {
      SStackX_20.cElements = iVar1 / 2;
    }
    SafeArrayRedim(*(SAFEARRAY **)(unaff_RBX + 0x18),&SStackX_20);
    *(ULONG *)(unaff_RBX + 0x28) = *(int *)(unaff_RBX + 0x20) + (SStackX_20.cElements - 1);
  }
  if (*(SAFEARRAY **)(unaff_RBX + 0x18) != (SAFEARRAY *)0x0) {
    SafeArrayPutElement(*(SAFEARRAY **)(unaff_RBX + 0x18),(LONG *)(unaff_RBX + 0x24),pv);
    *(int *)(unaff_RBX + 0x24) = *(int *)(unaff_RBX + 0x24) + 1;
  }
  return 0;
}

/* ---- FUNC 00018441 FUN_180018441 (8 bytes) ---- */

undefined8 FUN_180018441(void)

{
  return 0;
}

/* ---- FUNC 00018450 FUN_180018450 (163 bytes) ---- */

HRESULT FUN_180018450(void *param_1,DISPID param_2,undefined8 param_3,undefined8 param_4,
                     WORD param_5,DISPPARAMS *param_6,VARIANT *param_7,EXCEPINFO *param_8,
                     UINT *param_9)

{
  longlong lVar1;
  undefined8 uVar2;
  BSTR pOVar3;
  PVOID pvVar4;
  HRESULT HVar5;
  
  *(undefined4 *)(*(longlong *)((longlong)param_1 + 8) + 0x90) = 0;
  HVar5 = DispInvoke(param_1,*(ITypeInfo **)((longlong)param_1 + 0x10),param_2,param_5,param_6,
                     param_7,param_8,param_9);
  lVar1 = *(longlong *)((longlong)param_1 + 8);
  if (*(int *)(lVar1 + 0x90) != 0) {
    if (param_8 != (EXCEPINFO *)0x0) {
      uVar2 = *(undefined8 *)(lVar1 + 0x50);
      pOVar3 = *(BSTR *)(lVar1 + 0x58);
      param_8->wCode = (short)uVar2;
      param_8->wReserved = (short)((ulonglong)uVar2 >> 0x10);
      *(int *)&param_8->field_0x4 = (int)((ulonglong)uVar2 >> 0x20);
      param_8->bstrSource = pOVar3;
      pOVar3 = *(BSTR *)(lVar1 + 0x68);
      param_8->bstrDescription = *(BSTR *)(lVar1 + 0x60);
      param_8->bstrHelpFile = pOVar3;
      pvVar4 = *(PVOID *)(lVar1 + 0x78);
      *(undefined8 *)&param_8->dwHelpContext = *(undefined8 *)(lVar1 + 0x70);
      param_8->pvReserved = pvVar4;
      uVar2 = *(undefined8 *)(lVar1 + 0x88);
      param_8->pfnDeferredFillIn = *(_func_6477 **)(lVar1 + 0x80);
      *(undefined8 *)&param_8->scode = uVar2;
    }
    HVar5 = -0x7ffdfff7;
  }
  return HVar5;
}

/* ---- FUNC 00018500 FUN_180018500 (18 bytes) ---- */

ulonglong FUN_180018500(longlong *param_1,int param_2,undefined8 param_3,undefined8 param_4,
                       WORD param_5,DISPPARAMS *param_6,VARIANT *param_7,EXCEPINFO *param_8,
                       UINT *param_9)

{
  longlong lVar1;
  BSTR pOVar2;
  PVOID pvVar3;
  HRESULT HVar4;
  ulonglong uVar5;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  
  *(undefined4 *)(param_1 + 0x12) = 0;
  if (param_2 == -0x55555556) {
    uVar5 = FUN_18000b490(param_1,(longlong *)param_6);
  }
  else {
    HVar4 = DispInvoke(param_1,(ITypeInfo *)param_1[1],param_2,param_5,param_6,param_7,param_8,
                       param_9);
    uVar5 = CONCAT44(extraout_var,HVar4);
    if (HVar4 == -0x7ffdfffd) {
      HVar4 = DispInvoke(param_1 + 0x4e,(ITypeInfo *)param_1[0x50],param_2,param_5,param_6,param_7,
                         param_8,param_9);
      uVar5 = CONCAT44(extraout_var_00,HVar4);
    }
  }
  if ((int)param_1[0x12] != 0) {
    if (param_8 != (EXCEPINFO *)0x0) {
      lVar1 = param_1[10];
      pOVar2 = (BSTR)param_1[0xb];
      param_8->wCode = (short)lVar1;
      param_8->wReserved = (short)((ulonglong)lVar1 >> 0x10);
      *(int *)&param_8->field_0x4 = (int)((ulonglong)lVar1 >> 0x20);
      param_8->bstrSource = pOVar2;
      pOVar2 = (BSTR)param_1[0xd];
      param_8->bstrDescription = (BSTR)param_1[0xc];
      param_8->bstrHelpFile = pOVar2;
      pvVar3 = (PVOID)param_1[0xf];
      *(longlong *)&param_8->dwHelpContext = param_1[0xe];
      param_8->pvReserved = pvVar3;
      lVar1 = param_1[0x11];
      param_8->pfnDeferredFillIn = (_func_6477 *)param_1[0x10];
      *(longlong *)&param_8->scode = lVar1;
      param_1[10] = 0;
      param_1[0xb] = 0;
      param_1[0xc] = 0;
      param_1[0xd] = 0;
      param_1[0xe] = 0;
      param_1[0xf] = 0;
      param_1[0x10] = 0;
      param_1[0x11] = 0;
    }
    uVar5 = 0x80020009;
  }
  return uVar5;
}

/* ---- FUNC 00018512 FUN_180018512 (67 bytes) ---- */

ulonglong FUN_180018512(longlong *param_1,int param_2)

{
  undefined8 uVar1;
  BSTR pOVar2;
  PVOID pvVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong unaff_RBX;
  EXCEPINFO *unaff_RDI;
  WORD in_stack_00000080;
  DISPPARAMS *in_stack_00000088;
  VARIANT *in_stack_00000090;
  UINT *in_stack_000000a0;
  
  *(undefined4 *)(param_1 + 0x12) = 0;
  if (param_2 == -0x55555556) {
    uVar5 = FUN_18000b490(param_1,(longlong *)in_stack_00000088);
  }
  else {
    uVar4 = DispInvoke(param_1,(ITypeInfo *)param_1[1],param_2,in_stack_00000080,in_stack_00000088,
                       in_stack_00000090,unaff_RDI,in_stack_000000a0);
    if (uVar4 == 0x80020003) {
      uVar4 = DispInvoke((void *)(unaff_RBX + 0x270),*(ITypeInfo **)(unaff_RBX + 0x280),param_2,
                         in_stack_00000080,in_stack_00000088,in_stack_00000090,unaff_RDI,
                         in_stack_000000a0);
    }
    uVar5 = (ulonglong)uVar4;
  }
  if (*(int *)(unaff_RBX + 0x90) != 0) {
    if (unaff_RDI != (EXCEPINFO *)0x0) {
      uVar1 = *(undefined8 *)(unaff_RBX + 0x50);
      pOVar2 = *(BSTR *)(unaff_RBX + 0x58);
      unaff_RDI->wCode = (short)uVar1;
      unaff_RDI->wReserved = (short)((ulonglong)uVar1 >> 0x10);
      *(int *)&unaff_RDI->field_0x4 = (int)((ulonglong)uVar1 >> 0x20);
      unaff_RDI->bstrSource = pOVar2;
      pOVar2 = *(BSTR *)(unaff_RBX + 0x68);
      unaff_RDI->bstrDescription = *(BSTR *)(unaff_RBX + 0x60);
      unaff_RDI->bstrHelpFile = pOVar2;
      pvVar3 = *(PVOID *)(unaff_RBX + 0x78);
      *(undefined8 *)&unaff_RDI->dwHelpContext = *(undefined8 *)(unaff_RBX + 0x70);
      unaff_RDI->pvReserved = pvVar3;
      uVar1 = *(undefined8 *)(unaff_RBX + 0x88);
      unaff_RDI->pfnDeferredFillIn = *(_func_6477 **)(unaff_RBX + 0x80);
      *(undefined8 *)&unaff_RDI->scode = uVar1;
      *(undefined8 *)(unaff_RBX + 0x50) = 0;
      *(undefined8 *)(unaff_RBX + 0x58) = 0;
      *(undefined8 *)(unaff_RBX + 0x60) = 0;
      *(undefined8 *)(unaff_RBX + 0x68) = 0;
      *(undefined8 *)(unaff_RBX + 0x70) = 0;
      *(undefined8 *)(unaff_RBX + 0x78) = 0;
      *(undefined8 *)(unaff_RBX + 0x80) = 0;
      *(undefined8 *)(unaff_RBX + 0x88) = 0;
    }
    uVar5 = 0x80020009;
  }
  return uVar5;
}

/* ---- FUNC 00018555 FUN_180018555 (139 bytes) ---- */

HRESULT FUN_180018555(void *param_1,ITypeInfo *param_2,DISPID param_3,WORD param_4)

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
    HVar4 = DispInvoke((void *)(unaff_RBX + 0x270),*(ITypeInfo **)(unaff_RBX + 0x280),unaff_ESI,
                       in_stack_00000080,in_stack_00000088,in_stack_00000090,unaff_RDI,
                       in_stack_000000a0);
  }
  if (*(int *)(unaff_RBX + 0x90) != 0) {
    if (unaff_RDI != (EXCEPINFO *)0x0) {
      uVar1 = *(undefined8 *)(unaff_RBX + 0x50);
      pOVar2 = *(BSTR *)(unaff_RBX + 0x58);
      unaff_RDI->wCode = (short)uVar1;
      unaff_RDI->wReserved = (short)((ulonglong)uVar1 >> 0x10);
      *(int *)&unaff_RDI->field_0x4 = (int)((ulonglong)uVar1 >> 0x20);
      unaff_RDI->bstrSource = pOVar2;
      pOVar2 = *(BSTR *)(unaff_RBX + 0x68);
      unaff_RDI->bstrDescription = *(BSTR *)(unaff_RBX + 0x60);
      unaff_RDI->bstrHelpFile = pOVar2;
      pvVar3 = *(PVOID *)(unaff_RBX + 0x78);
      *(undefined8 *)&unaff_RDI->dwHelpContext = *(undefined8 *)(unaff_RBX + 0x70);
      unaff_RDI->pvReserved = pvVar3;
      uVar1 = *(undefined8 *)(unaff_RBX + 0x88);
      unaff_RDI->pfnDeferredFillIn = *(_func_6477 **)(unaff_RBX + 0x80);
      *(undefined8 *)&unaff_RDI->scode = uVar1;
      *(undefined8 *)(unaff_RBX + 0x50) = 0;
      *(undefined8 *)(unaff_RBX + 0x58) = 0;
      *(undefined8 *)(unaff_RBX + 0x60) = 0;
      *(undefined8 *)(unaff_RBX + 0x68) = 0;
      *(undefined8 *)(unaff_RBX + 0x70) = 0;
      *(undefined8 *)(unaff_RBX + 0x78) = 0;
      *(undefined8 *)(unaff_RBX + 0x80) = 0;
      *(undefined8 *)(unaff_RBX + 0x88) = 0;
    }
    HVar4 = -0x7ffdfff7;
  }
  return HVar4;
}

/* ---- FUNC 000185E0 FUN_1800185e0 (14 bytes) ---- */

void FUN_1800185e0(void)

{
  undefined8 uVar1;
  longlong unaff_RBX;
  undefined8 *unaff_RDI;
  
  if ((*(int *)(unaff_RBX + 0x90) != 0) && (unaff_RDI != (undefined8 *)0x0)) {
    uVar1 = *(undefined8 *)(unaff_RBX + 0x58);
    *unaff_RDI = *(undefined8 *)(unaff_RBX + 0x50);
    unaff_RDI[1] = uVar1;
    uVar1 = *(undefined8 *)(unaff_RBX + 0x68);
    unaff_RDI[2] = *(undefined8 *)(unaff_RBX + 0x60);
    unaff_RDI[3] = uVar1;
    uVar1 = *(undefined8 *)(unaff_RBX + 0x78);
    unaff_RDI[4] = *(undefined8 *)(unaff_RBX + 0x70);
    unaff_RDI[5] = uVar1;
    uVar1 = *(undefined8 *)(unaff_RBX + 0x88);
    unaff_RDI[6] = *(undefined8 *)(unaff_RBX + 0x80);
    unaff_RDI[7] = uVar1;
    *(undefined8 *)(unaff_RBX + 0x50) = 0;
    *(undefined8 *)(unaff_RBX + 0x58) = 0;
    *(undefined8 *)(unaff_RBX + 0x60) = 0;
    *(undefined8 *)(unaff_RBX + 0x68) = 0;
    *(undefined8 *)(unaff_RBX + 0x70) = 0;
    *(undefined8 *)(unaff_RBX + 0x78) = 0;
    *(undefined8 *)(unaff_RBX + 0x80) = 0;
    *(undefined8 *)(unaff_RBX + 0x88) = 0;
  }
  return;
}

/* ---- FUNC 000185EE FUN_1800185ee (73 bytes) ---- */

undefined8 FUN_1800185ee(void)

{
  undefined8 uVar1;
  longlong unaff_RBX;
  undefined8 *unaff_RDI;
  
  if (unaff_RDI != (undefined8 *)0x0) {
    uVar1 = *(undefined8 *)(unaff_RBX + 0x58);
    *unaff_RDI = *(undefined8 *)(unaff_RBX + 0x50);
    unaff_RDI[1] = uVar1;
    uVar1 = *(undefined8 *)(unaff_RBX + 0x68);
    unaff_RDI[2] = *(undefined8 *)(unaff_RBX + 0x60);
    unaff_RDI[3] = uVar1;
    uVar1 = *(undefined8 *)(unaff_RBX + 0x78);
    unaff_RDI[4] = *(undefined8 *)(unaff_RBX + 0x70);
    unaff_RDI[5] = uVar1;
    uVar1 = *(undefined8 *)(unaff_RBX + 0x88);
    unaff_RDI[6] = *(undefined8 *)(unaff_RBX + 0x80);
    unaff_RDI[7] = uVar1;
    *(undefined8 *)(unaff_RBX + 0x50) = 0;
    *(undefined8 *)(unaff_RBX + 0x58) = 0;
    *(undefined8 *)(unaff_RBX + 0x60) = 0;
    *(undefined8 *)(unaff_RBX + 0x68) = 0;
    *(undefined8 *)(unaff_RBX + 0x70) = 0;
    *(undefined8 *)(unaff_RBX + 0x78) = 0;
    *(undefined8 *)(unaff_RBX + 0x80) = 0;
    *(undefined8 *)(unaff_RBX + 0x88) = 0;
  }
  return 0x80020009;
}

/* ---- FUNC 00018640 FUN_180018640 (112 bytes) ---- */

undefined1 FUN_180018640(longlong param_1)

{
  undefined1 uVar1;
  int iVar2;
  bool bVar3;
  ulonglong local_res8;
  
  bVar3 = false;
  local_res8 = local_res8 & 0xffffffff00000000;
  if (*(int *)(param_1 + 0x100) == 0) {
    if (*(longlong *)(param_1 + 0x20) != 0) {
      local_res8 = 0;
      bVar3 = true;
      iVar2 = HAIsDirty(*(longlong *)(param_1 + 0x20),&local_res8);
      if (iVar2 != 0) goto LAB_180018684;
    }
    uVar1 = 0;
  }
  else {
LAB_180018684:
    uVar1 = 1;
  }
  if (bVar3) {
    ReleaseErrorStruct(&local_res8);
  }
  return uVar1;
}

/* ---- FUNC 000186B0 FUN_1800186b0 (65 bytes) ---- */

ulonglong FUN_1800186b0(longlong *param_1,IStream *param_2,int param_3)

{
  int iVar1;
  undefined4 extraout_var;
  ulonglong uVar2;
  
  *(int *)((longlong)param_1 + 0x14) = *(int *)((longlong)param_1 + 0x14) + 1;
  if (param_3 == 0) {
    iVar1 = FUN_180018700(param_1,param_2);
    *(int *)((longlong)param_1 + 0x14) = *(int *)((longlong)param_1 + 0x14) + -1;
    return CONCAT44(extraout_var,iVar1);
  }
  if (param_3 == 1) {
    uVar2 = FUN_180018a10(param_1,(longlong *)param_2);
    *(int *)((longlong)param_1 + 0x14) = *(int *)((longlong)param_1 + 0x14) + -1;
    return uVar2;
  }
  *(int *)((longlong)param_1 + 0x14) = *(int *)((longlong)param_1 + 0x14) + -1;
  return 0x80070057;
}

/* ---- FUNC 00018700 FUN_180018700 (782 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_180018700(longlong *param_1,IStream *param_2)

{
  char cVar1;
  HRESULT HVar2;
  int iVar3;
  longlong *plVar4;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar5;
  CPtrArray *pCVar6;
  longlong *plVar7;
  char *pcVar8;
  longlong lVar9;
  uint uVar10;
  longlong lVar12;
  bool bVar13;
  undefined1 auStack_88 [32];
  ULONG local_68;
  int local_64;
  int local_60 [2];
  undefined8 local_58;
  char local_50 [32];
  ulonglong local_30;
  longlong *plVar11;
  
  local_30 = DAT_180077818 ^ (ulonglong)auStack_88;
  HVar2 = (*param_2->lpVtbl->Read)(param_2,local_60,4,&local_68);
  if ((-1 < HVar2) && (local_68 == 4)) {
    plVar7 = (longlong *)0x0;
    bVar13 = false;
    plVar11 = plVar7;
    if (0 < local_60[0]) {
      do {
        local_58 = operator_new(0x168);
        plVar4 = plVar7;
        if (local_58 != (undefined8 *)0x0) {
          plVar4 = FUN_180025480(local_58);
        }
        (**(code **)(*plVar4 + 8))(plVar4);
        plVar4[1] = (longlong)param_1;
        (**(code **)(*param_1 + 8))(param_1);
        iVar3 = FUN_18002b050((longlong)plVar4,(longlong *)param_2);
        if (iVar3 < 0) {
          (**(code **)(*plVar4 + 0x10))(plVar4);
          return iVar3;
        }
        (**(code **)(*plVar4 + 0x10))();
        uVar10 = (int)plVar11 + 1;
        plVar11 = (longlong *)(ulonglong)uVar10;
      } while ((int)uVar10 < local_60[0]);
    }
    HVar2 = (*param_2->lpVtbl->Read)(param_2,&local_64,4,&local_68);
    if ((-1 < HVar2) && (local_68 == 4)) {
      if (0 < local_64) {
        pCVar5 = FUN_180020fe0((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &local_58,4);
        iVar3 = MMAfxMessageBox(*(char **)pCVar5,0x2004,-1,0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58);
        bVar13 = iVar3 == 6;
      }
      plVar11 = plVar7;
      if (0 < local_64) {
        do {
          local_58 = operator_new(0x100);
          plVar4 = plVar7;
          if (local_58 != (undefined8 *)0x0) {
            plVar4 = FUN_180025390(local_58);
          }
          (**(code **)(*plVar4 + 8))(plVar4);
          plVar4[2] = (longlong)param_1;
          (**(code **)(*param_1 + 8))(param_1);
          pCVar6 = FUN_18002ad60((longlong)plVar4,param_2);
          if ((int)pCVar6 < 0) {
            (**(code **)(*plVar4 + 0x10))();
            break;
          }
          FUN_18002f6d0((longlong)plVar4,1);
          CPtrArray::SetAtGrow((CPtrArray *)(param_1 + 0x43),param_1[0x45],plVar4);
          uVar10 = (int)plVar11 + 1;
          plVar11 = (longlong *)(ulonglong)uVar10;
        } while ((int)uVar10 < local_64);
      }
      if (bVar13) {
        local_58 = operator_new(0x30);
        if (local_58 != (undefined8 *)0x0) {
          plVar7 = FUN_18005a5f0(local_58,param_1 + 0x43);
        }
        (**(code **)(*plVar7 + 8))(plVar7);
        FUN_18005af40((longlong)plVar7);
        iVar3 = OleUIUpdateLinksA(plVar7,DAT_1800797e0,"Update Links",(int)param_1[0x45]);
        if (iVar3 == 0) {
          pcVar8 = (char *)MVGetProductName();
          lVar9 = -(longlong)pcVar8;
          do {
            cVar1 = *pcVar8;
            pcVar8[(longlong)(local_50 + lVar9)] = cVar1;
            pcVar8 = pcVar8 + 1;
          } while (cVar1 != '\0');
          pcVar8 = (char *)((longlong)&local_58 + 7);
          do {
            pcVar8 = pcVar8 + 1;
          } while (*pcVar8 != '\0');
          *(undefined2 *)pcVar8 = DAT_1800633a4;
          lVar9 = MVGetVersionString();
          pcVar8 = (char *)((longlong)&local_58 + 7);
          do {
            pcVar8 = pcVar8 + 1;
          } while (*pcVar8 != '\0');
          lVar12 = 0;
          do {
            cVar1 = *(char *)(lVar9 + lVar12);
            pcVar8[lVar12] = cVar1;
            lVar12 = lVar12 + 1;
          } while (cVar1 != '\0');
          iVar3 = OleUIPromptUserA(0x3f0,DAT_1800797e0,local_50);
          if (iVar3 == 900) {
            FUN_18000fc60((longlong)param_1);
          }
        }
        (**(code **)(*plVar7 + 0x10))(plVar7);
      }
      return 0;
    }
  }
  return -0x7fffbffb;
}

/* ---- FUNC 00018A10 FUN_180018a10 (565 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180018a10(longlong *param_1,longlong *param_2)

{
  int iVar1;
  longlong *plVar2;
  undefined8 uVar3;
  int iVar4;
  undefined1 auStack_5b8 [32];
  undefined8 *local_598;
  char local_588 [9];
  char local_57f [359];
  undefined1 local_418 [1008];
  ulonglong local_28;
  
  local_28 = DAT_180077818 ^ (ulonglong)auStack_5b8;
  FUN_180020f00(param_2,local_588);
  iVar1 = strncmp(local_588,"source = ",9);
  if (iVar1 == 0) {
    iVar1 = atoi(local_57f);
    iVar4 = 0;
    if (0 < iVar1) {
      do {
        local_598 = operator_new(0x168);
        if (local_598 == (undefined8 *)0x0) {
          plVar2 = (longlong *)0x0;
        }
        else {
          plVar2 = FUN_180025480(local_598);
        }
        (**(code **)(*plVar2 + 8))(plVar2);
        plVar2[1] = (longlong)param_1;
        (**(code **)(*param_1 + 8))(param_1);
        uVar3 = FUN_18002b8f0((longlong)plVar2,param_2);
        if ((int)uVar3 < 0) {
          (**(code **)(*plVar2 + 0x10))(plVar2);
          break;
        }
        (**(code **)(*plVar2 + 0x10))();
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar1);
    }
    FUN_180020f00(param_2,local_588);
  }
  while (((local_588[0] != '\0' && (iVar1 = strncmp(local_588,"container = ",0xc), iVar1 != 0)) &&
         (iVar1 = strcmp(local_588,"end ole link\n"), iVar1 != 0))) {
    FUN_180002a20(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\happ.cpp",0x10dc);
    LogMessage(local_418,2,1);
    FUN_180020f00(param_2,local_588);
  }
  iVar1 = strncmp(local_588,"container = ",0xc);
  if (iVar1 == 0) {
    while ((local_588[0] != '\0' && (iVar1 = strcmp(local_588,"end ole link\n"), iVar1 != 0))) {
      CStringArray::SetAtGrow((CStringArray *)(param_1 + 0x15),param_1[0x17],local_588);
      FUN_180020f00(param_2,local_588);
    }
  }
  iVar1 = strcmp(local_588,"end ole link\n");
  if (iVar1 != 0) {
    FUN_180002a20(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\happ.cpp",0x10e9);
    LogMessage(local_418,2,1);
  }
  return 0;
}

/* ---- FUNC 00018C50 FUN_180018c50 (472 bytes) ---- */

undefined8 FUN_180018c50(longlong param_1,longlong *param_2)

{
  ushort uVar1;
  undefined1 auVar2 [16];
  BSTR pOVar3;
  int iVar4;
  UINT UVar5;
  ulonglong uVar6;
  __uint64 _Var7;
  BSTR bstrString;
  uint uVar8;
  ulonglong *puVar10;
  ulonglong *puVar11;
  BSTR local_res10;
  ulonglong *local_res18;
  longlong local_res20;
  ulonglong *puVar9;
  
  iVar4 = (**(code **)(*param_2 + 0x18))(param_2,&local_res20);
  if (-1 < iVar4) {
    puVar9 = (ulonglong *)0x0;
    uVar1 = *(ushort *)(local_res20 + 0x30);
    uVar8 = (uint)uVar1;
    *(uint *)(param_1 + 0x30) = uVar8;
    *(undefined8 *)(param_1 + 0x28) = 0;
    puVar11 = puVar9;
    if (uVar1 != 0) {
      auVar2._8_8_ = 0;
      auVar2._0_8_ = (BSTR)CONCAT62(0,uVar1);
      uVar6 = SUB168(ZEXT816(0x10) * auVar2,0);
      if (SUB168(ZEXT816(0x10) * auVar2,8) != 0) {
        uVar6 = 0xffffffffffffffff;
      }
      _Var7 = uVar6 + 8;
      if (0xfffffffffffffff7 < uVar6) {
        _Var7 = 0xffffffffffffffff;
      }
      local_res10 = (BSTR)CONCAT62(0,uVar1);
      local_res18 = operator_new__(_Var7);
      if (local_res18 != (ulonglong *)0x0) {
        *local_res18 = (ulonglong)uVar8;
        puVar11 = local_res18 + 1;
        _eh_vector_constructor_iterator_
                  (puVar11,0x10,(ulonglong)uVar8,(_func_void_void_ptr *)&LAB_18000af10,
                   (_func_void_void_ptr *)&LAB_18000b020);
      }
      if (puVar11 == (ulonglong *)0x0) {
        (**(code **)(*param_2 + 0x98))(param_2,local_res20);
        return 0x8007000e;
      }
    }
    puVar10 = puVar11;
    if (0 < *(int *)(param_1 + 0x30)) {
      do {
        iVar4 = (**(code **)(*param_2 + 0x28))(param_2,puVar9,&local_res18);
        if (-1 < iVar4) {
          local_res10 = (BSTR)0x0;
          iVar4 = (**(code **)(*param_2 + 0x60))(param_2,(int)*local_res18,&local_res10,0,0,0);
          pOVar3 = local_res10;
          if (-1 < iVar4) {
            local_res10 = (BSTR)0x0;
            bstrString = (BSTR)*puVar10;
            if (bstrString != pOVar3) {
              SysFreeString(bstrString);
              *puVar10 = (ulonglong)pOVar3;
              bstrString = pOVar3;
            }
            UVar5 = SysStringLen(bstrString);
            *(UINT *)(puVar10 + 1) = UVar5;
            *(int *)((longlong)puVar10 + 0xc) = (int)*local_res18;
          }
          (**(code **)(*param_2 + 0xa0))(param_2,local_res18);
          SysFreeString(local_res10);
        }
        uVar8 = (int)puVar9 + 1;
        puVar9 = (ulonglong *)(ulonglong)uVar8;
        puVar10 = puVar10 + 2;
      } while ((int)uVar8 < *(int *)(param_1 + 0x30));
    }
    *(ulonglong **)(param_1 + 0x28) = puVar11;
    (**(code **)(*param_2 + 0x98))(param_2,local_res20);
  }
  return 0;
}

/* ---- FUNC 00018E30 FUN_180018e30 (127 bytes) ---- */

int FUN_180018e30(IUnknown *param_1,int param_2,int param_3)

{
  IUnknownVtbl *pIVar1;
  int iVar2;
  
  iVar2 = *(int *)((longlong)&param_1[2].lpVtbl + 4);
  if (param_2 != 0) {
    pIVar1 = param_1->lpVtbl;
    *(int *)((longlong)&param_1[2].lpVtbl + 4) = iVar2 + 1;
    (*pIVar1->AddRef)(param_1);
    return iVar2 + 1;
  }
  if (iVar2 != 0) {
    iVar2 = iVar2 + -1;
    *(int *)((longlong)&param_1[2].lpVtbl + 4) = iVar2;
    if ((iVar2 == 0) && (param_3 != 0)) {
      FUN_18000ef30((longlong *)param_1,1);
      FUN_18001a6a0(param_1);
      FUN_1800111f0((longlong)param_1);
    }
    (*param_1->lpVtbl->Release)(param_1);
    return iVar2;
  }
  return 0;
}

/* ---- FUNC 00018EB0 FUN_180018eb0 (45 bytes) ---- */

undefined4 FUN_180018eb0(undefined8 param_1,short param_2,short param_3)

{
  bool bVar1;
  undefined4 uVar2;
  
  bVar1 = CApwnLibraries::MoveCategory(*(CApwnLibraries **)g_pApwnLibs_exref,param_2,param_3,1);
  uVar2 = 0x80004005;
  if (bVar1) {
    uVar2 = 0;
  }
  return uVar2;
}

/* ---- FUNC 00018EE0 FUN_180018ee0 (33 bytes) ---- */

undefined8 FUN_180018ee0(undefined8 param_1,short param_2,short param_3)

{
  CApwnLibraries::MoveLibrary(*(CApwnLibraries **)g_pApwnLibs_exref,param_2,param_3,1);
  return 0;
}

/* ---- FUNC 00018F10 FUN_180018f10 (518 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

ulonglong FUN_180018f10(longlong *param_1,int param_2,VARIANTARG *param_3)

{
  VARTYPE VVar1;
  undefined4 *puVar2;
  HRESULT HVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  int iVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar11;
  undefined8 lpWideCharStr;
  undefined8 uStack_a0;
  undefined1 auStack_98 [32];
  undefined8 uStack_78;
  int aiStack_70 [2];
  undefined8 local_68 [2];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_58 [8];
  VARIANTARG local_50;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined8 local_28;
  ulonglong local_18;
  longlong lVar7;
  
  puVar9 = auStack_98;
  puVar10 = auStack_98;
  local_18 = DAT_180077818 ^ (ulonglong)local_58;
  if (DAT_1800797f8 != 0) {
    uStack_a0 = 0x180018f5f;
    uVar5 = (**(code **)(*(longlong *)param_1[1] + 0x280))((longlong *)param_1[1],0x7f3);
    puVar10 = auStack_98;
    goto LAB_1800190f4;
  }
  uStack_a0 = 0x180018f6e;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_58);
  uStack_a0 = 0x180018f79;
  VariantInit(&local_50);
  VVar1 = (param_3->n1).n2.vt;
  if (VVar1 == 1) {
LAB_1800190c2:
    uStack_a0 = 0x1800190cc;
    Ordinal_99(1);
    goto LAB_1800190d2;
  }
  if (VVar1 == 8) {
    lpWideCharStr = ((_union_1719 *)((longlong)&param_3->n1 + 8))->Lo64;
LAB_180019022:
    uStack_a0 = 0x180019030;
    Ordinal_99(1);
    puVar9 = auStack_98;
    if ((LPCWSTR)lpWideCharStr == (LPCWSTR)0x0) {
LAB_1800190d2:
      puVar10 = puVar9;
      pCVar11 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    }
    else {
      lVar6 = -1;
      do {
        lVar7 = lVar6;
        lVar6 = lVar7 + 1;
      } while (*(LPCWSTR)(lpWideCharStr + lVar6 * 2) != L'\0');
      iVar8 = (int)lVar7 + 2;
      puVar9 = auStack_98;
      if (0x3fffffff < iVar8) goto LAB_1800190d2;
      lVar6 = (longlong)(int)lVar6 * 2;
      uVar5 = lVar6 + 0x11;
      if (uVar5 <= lVar6 + 2U) {
        uVar5 = 0xffffffffffffff0;
      }
      uStack_a0 = 0x180019082;
      lVar6 = -(uVar5 & 0xfffffffffffffff0);
      pCVar11 = local_58 + lVar6;
      puVar9 = auStack_98 + lVar6;
      if (pCVar11 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0)
      goto LAB_1800190d2;
      *pCVar11 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>)0x0;
      *(undefined8 *)((longlong)local_68 + lVar6 + 8) = 0;
      *(undefined8 *)((longlong)local_68 + lVar6) = 0;
      *(int *)((longlong)aiStack_70 + lVar6) = iVar8 * 2;
      *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
       ((longlong)&uStack_78 + lVar6) = pCVar11;
      *(undefined8 *)(auStack_98 + lVar6 + -8) = 0x1800190ba;
      iVar8 = WideCharToMultiByte(0,0,(LPCWSTR)lpWideCharStr,-1,
                                  *(LPSTR *)((longlong)&uStack_78 + lVar6),
                                  *(int *)((longlong)aiStack_70 + lVar6),
                                  *(LPCSTR *)((longlong)local_68 + lVar6),
                                  *(LPBOOL *)((longlong)local_68 + lVar6 + 8));
      puVar10 = auStack_98 + lVar6;
      if (iVar8 == 0) {
        puVar10 = auStack_98 + lVar6;
        pCVar11 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
      }
    }
    uVar5 = 0;
    *(undefined8 *)(puVar10 + -8) = 0x1800190e0;
    Ordinal_128(param_2 + 1,pCVar11);
    *(undefined8 *)(puVar10 + -8) = 0x1800190e7;
    Ordinal_99(0);
  }
  else {
    if (VVar1 == 10) goto LAB_1800190c2;
    if (VVar1 == 0x4008) {
      lpWideCharStr = (*(_union_1719 **)((longlong)&param_3->n1 + 8))->Lo64;
      goto LAB_180019022;
    }
    if (VVar1 == 0x400c) {
      puVar2 = *(undefined4 **)((longlong)&param_3->n1 + 8);
      local_38 = *puVar2;
      uStack_34 = puVar2[1];
      uStack_30 = puVar2[2];
      uStack_2c = puVar2[3];
      local_28 = *(undefined8 *)(puVar2 + 4);
      uStack_a0 = 0x18001900e;
      uVar4 = (**(code **)(*param_1 + 0x80))(param_1,param_2,&local_38);
      uVar5 = (ulonglong)uVar4;
    }
    else {
      uStack_a0 = 0x180018fba;
      HVar3 = VariantChangeType(&local_50,param_3,0,8);
      if (-1 < HVar3) {
        uStack_a0 = 0x180018fe5;
        VariantClear(&local_50);
        lpWideCharStr = local_50.n1.decVal.u2;
        goto LAB_180019022;
      }
      uStack_a0 = 0x180018fd0;
      uVar4 = (**(code **)(*(longlong *)param_1[1] + 0x280))((longlong *)param_1[1],0x7d4);
      uVar5 = (ulonglong)uVar4;
      puVar10 = auStack_98;
    }
  }
  *(undefined8 *)(puVar10 + -8) = 0x1800190f2;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_58);
LAB_1800190f4:
  *(undefined8 *)(puVar10 + -8) = 0x180019100;
  return uVar5;
}

/* ---- FUNC 00019120 FUN_180019120 (465 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180019120(longlong *param_1,char *param_2,undefined8 *param_3,int param_4)

{
  longlong *plVar1;
  RPC_STATUS RVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  void **ppvVar6;
  undefined1 auStack_478 [32];
  char *local_458;
  longlong *local_450;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_448 [8];
  uchar *local_440;
  void *local_438;
  UUID local_430;
  undefined1 local_418 [1008];
  ulonglong local_28;
  
  local_28 = DAT_180077818 ^ (ulonglong)auStack_478;
  if (DAT_1800797f8 != 0) {
    uVar5 = (**(code **)(*param_1 + 0x280))(param_1,0x7f3);
    return uVar5;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_458);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_448);
  *param_3 = 0;
  if (param_4 == 0) {
    FUN_180002a20(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\happ.cpp",0xd6a);
    LogMessage(local_418,2,1);
  }
  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
    RVar2 = UuidCreate(&local_430);
    if (((RVar2 != 0) && (RVar2 != 0x720)) ||
       (RVar2 = UuidToStringA(&local_430,&local_440), RVar2 != 0)) {
      uVar4 = 0x80004005;
      goto LAB_1800192b4;
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              (local_448,local_440);
    RpcStringFreeA(&local_440);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_458,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               local_448);
  }
  else {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_458,param_2);
  }
  iVar3 = CMapStringToPtr::Lookup((CMapStringToPtr *)(param_1 + 0x37),local_458,&local_438);
  if (iVar3 == 0) {
    uVar4 = FUN_180027940(&local_450,param_1,
                          (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                           *)&local_458);
    if (-1 < (int)uVar4) {
      (**(code **)(*local_450 + 8))();
      plVar1 = local_450;
      ppvVar6 = CMapStringToPtr::operator[]((CMapStringToPtr *)(param_1 + 0x37),local_458);
      *ppvVar6 = plVar1;
      uVar4 = (**(code **)*local_450)(local_450,&DAT_180063430,param_3);
    }
  }
  else {
    uVar4 = (**(code **)(*param_1 + 0x280))(param_1,0x7f1);
  }
LAB_1800192b4:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_448);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_458);
  return (ulonglong)uVar4;
}

/* ---- FUNC 00019300 FUN_180019300 (116 bytes) ---- */

ulonglong FUN_180019300(longlong *param_1,wchar_t *param_2,undefined8 *param_3)

{
  ulonglong uVar1;
  char *local_res20;
  
  if (DAT_1800797f8 != 0) {
    uVar1 = (**(code **)(*param_1 + 0x280))(param_1,0x7f3);
    return uVar1;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,param_2);
  *param_3 = 0;
  uVar1 = FUN_180019120(param_1,local_res20,param_3,1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
  return uVar1 & 0xffffffff;
}

/* ---- FUNC 00019380 FUN_180019380 (148 bytes) ---- */

bool FUN_180019380(longlong param_1,uint param_2,longlong param_3,uint *param_4)

{
  longlong *plVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *(int *)(param_1 + 0x10);
  uVar3 = 0;
  if (iVar2 < *(int *)(param_1 + 0xc)) {
    do {
      if (param_2 <= uVar3) break;
      *(undefined8 *)(param_3 + (ulonglong)uVar3 * 8) =
           *(undefined8 *)(*(longlong *)(param_1 + 0x18) + (longlong)iVar2 * 8);
      plVar1 = *(longlong **)
                (*(longlong *)(param_1 + 0x18) + (longlong)*(int *)(param_1 + 0x10) * 8);
      if (plVar1 != (longlong *)0x0) {
        (**(code **)(*plVar1 + 8))();
      }
      uVar3 = uVar3 + 1;
      iVar2 = *(int *)(param_1 + 0x10) + 1;
      *(int *)(param_1 + 0x10) = iVar2;
    } while (iVar2 < *(int *)(param_1 + 0xc));
  }
  if (param_4 != (uint *)0x0) {
    *param_4 = uVar3;
  }
  return uVar3 != param_2;
}

/* ---- FUNC 00019420 FUN_180019420 (50 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180019420(undefined8 param_1,undefined8 *param_2,int param_3)

{
  int iVar1;
  undefined1 auStack_f8 [32];
  undefined4 local_d8;
  longlong *local_c8;
  longlong *local_c0;
  undefined1 local_b8 [8];
  longlong *local_b0;
  longlong *local_a8;
  longlong *local_a0;
  longlong *local_98;
  undefined8 *local_90 [2];
  int local_80 [2];
  undefined8 *local_78;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  if (param_2 != (undefined8 *)0x0) {
    local_18 = DAT_180077818 ^ (ulonglong)auStack_f8;
    local_c0 = (longlong *)0x0;
    iVar1 = (**(code **)*param_2)(param_2,&DAT_180063610,&local_c0);
    if ((-1 < iVar1) && (local_c0 != (longlong *)0x0)) {
      local_68 = 0;
      uStack_60 = 0;
      local_58 = 0;
      uStack_50 = 0;
      local_48 = 0;
      uStack_40 = 0;
      local_38 = 0;
      uStack_30 = 0;
      local_28 = 0;
      uStack_20 = 0;
      (**(code **)(*local_c0 + 0x18))(local_c0,&local_68,0x50);
      local_a0 = (longlong *)0x0;
      (**(code **)(*local_c0 + 0x28))(local_c0,&local_a0);
      local_98 = (longlong *)0x0;
      if ((local_a0 != (longlong *)0x0) &&
         ((iVar1 = (**(code **)*local_a0)(local_a0,&DAT_180066e28,&local_98), -1 < iVar1 &&
          (local_98 != (longlong *)0x0)))) {
        local_a8 = (longlong *)0x0;
        iVar1 = (**(code **)(*local_98 + 0x20))(local_98,&DAT_180063620,&local_a8);
        if ((-1 < iVar1) && (local_a8 != (longlong *)0x0)) {
          local_c8 = (longlong *)0x0;
          iVar1 = (**(code **)(*local_a8 + 0x38))(local_a8,&local_c8);
          if (-1 < iVar1) {
            (**(code **)(*local_c8 + 0x28))();
            iVar1 = (**(code **)(*local_c8 + 0x18))(local_c8,1,local_90,local_b8);
            while (iVar1 == 0) {
              if (local_90[0] != (undefined8 *)0x0) {
                local_b0 = (longlong *)0x0;
                iVar1 = (**(code **)*local_90[0])(local_90[0],&DAT_180063620,&local_b0);
                if (-1 < iVar1) {
                  if (param_3 == 0x10000012) {
                    local_78 = &local_68;
                    local_d8 = 0x10;
                    local_80[0] = param_3;
                    (**(code **)(*local_b0 + 0x18))(local_b0,0x10000012,1,local_80);
                  }
                  (**(code **)(*local_b0 + 0x10))();
                  break;
                }
              }
              iVar1 = (**(code **)(*local_c8 + 0x18))(local_c8,1,local_90,local_b8);
            }
            (**(code **)(*local_c8 + 0x10))();
          }
          (**(code **)(*local_a8 + 0x10))();
        }
        (**(code **)(*local_a0 + 0x10))();
        (**(code **)(*local_98 + 0x10))();
      }
      (**(code **)(*local_c0 + 0x10))();
    }
  }
  return;
}

/* ---- FUNC 00019452 FUN_180019452 (466 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180019452(void)

{
  longlong *plVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *in_RAX;
  int unaff_EBX;
  longlong unaff_RBP;
  undefined8 in_R9;
  
  *(undefined8 *)(unaff_RBP + -0x61) = 0;
  iVar3 = (*(code *)*in_RAX)(in_R9,&DAT_180063610,unaff_RBP + -0x61);
  if ((-1 < iVar3) && (plVar1 = *(longlong **)(unaff_RBP + -0x61), plVar1 != (longlong *)0x0)) {
    *(undefined8 *)(unaff_RBP + -9) = 0;
    *(undefined8 *)(unaff_RBP + -1) = 0;
    *(undefined8 *)(unaff_RBP + 7) = 0;
    *(undefined8 *)(unaff_RBP + 0xf) = 0;
    *(undefined8 *)(unaff_RBP + 0x17) = 0;
    *(undefined8 *)(unaff_RBP + 0x1f) = 0;
    *(undefined8 *)(unaff_RBP + 0x27) = 0;
    *(undefined8 *)(unaff_RBP + 0x2f) = 0;
    *(undefined8 *)(unaff_RBP + 0x37) = 0;
    *(undefined8 *)(unaff_RBP + 0x3f) = 0;
    (**(code **)(*plVar1 + 0x18))(plVar1,unaff_RBP + -9,0x50);
    *(undefined8 *)(unaff_RBP + -0x41) = 0;
    (**(code **)(**(longlong **)(unaff_RBP + -0x61) + 0x28))
              (*(longlong **)(unaff_RBP + -0x61),unaff_RBP + -0x41);
    puVar2 = *(undefined8 **)(unaff_RBP + -0x41);
    *(undefined8 *)(unaff_RBP + -0x39) = 0;
    if ((puVar2 != (undefined8 *)0x0) &&
       ((iVar3 = (**(code **)*puVar2)(puVar2,&DAT_180066e28,unaff_RBP + -0x39), -1 < iVar3 &&
        (plVar1 = *(longlong **)(unaff_RBP + -0x39), plVar1 != (longlong *)0x0)))) {
      *(undefined8 *)(unaff_RBP + -0x49) = 0;
      iVar3 = (**(code **)(*plVar1 + 0x20))(plVar1,&DAT_180063620,unaff_RBP + -0x49);
      if ((-1 < iVar3) && (plVar1 = *(longlong **)(unaff_RBP + -0x49), plVar1 != (longlong *)0x0)) {
        *(undefined8 *)(unaff_RBP + -0x69) = 0;
        iVar3 = (**(code **)(*plVar1 + 0x38))(plVar1,unaff_RBP + -0x69);
        if (-1 < iVar3) {
          (**(code **)(**(longlong **)(unaff_RBP + -0x69) + 0x28))();
          iVar3 = (**(code **)(**(longlong **)(unaff_RBP + -0x69) + 0x18))
                            (*(longlong **)(unaff_RBP + -0x69),1,unaff_RBP + -0x31,unaff_RBP + -0x59
                            );
          while (iVar3 == 0) {
            puVar2 = *(undefined8 **)(unaff_RBP + -0x31);
            if (puVar2 != (undefined8 *)0x0) {
              *(undefined8 *)(unaff_RBP + -0x51) = 0;
              iVar3 = (**(code **)*puVar2)(puVar2,&DAT_180063620,unaff_RBP + -0x51);
              if (-1 < iVar3) {
                if (unaff_EBX == 0x10000012) {
                  *(undefined4 *)(unaff_RBP + -0x21) = 0x10000012;
                  *(longlong *)(unaff_RBP + -0x19) = unaff_RBP + -9;
                  (**(code **)(**(longlong **)(unaff_RBP + -0x51) + 0x18))
                            (*(longlong **)(unaff_RBP + -0x51),0x10000012,1,unaff_RBP + -0x21,0x10);
                }
                (**(code **)(**(longlong **)(unaff_RBP + -0x51) + 0x10))();
                break;
              }
            }
            iVar3 = (**(code **)(**(longlong **)(unaff_RBP + -0x69) + 0x18))
                              (*(longlong **)(unaff_RBP + -0x69),1,unaff_RBP + -0x31,
                               unaff_RBP + -0x59);
          }
          (**(code **)(**(longlong **)(unaff_RBP + -0x69) + 0x10))();
        }
        (**(code **)(**(longlong **)(unaff_RBP + -0x49) + 0x10))();
      }
      (**(code **)(**(longlong **)(unaff_RBP + -0x41) + 0x10))();
      (**(code **)(**(longlong **)(unaff_RBP + -0x39) + 0x10))();
    }
    (**(code **)(**(longlong **)(unaff_RBP + -0x61) + 0x10))();
  }
  return;
}

/* ---- FUNC 00019624 FUN_180019624 (1 bytes) ---- */

void FUN_180019624(void)

{
  return;
}

/* ---- FUNC 00019630 FUN_180019630 (27 bytes) ---- */

undefined8 FUN_180019630(undefined8 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_3 == 0) {
    uVar1 = param_2;
  }
  OnSubflowsheetChange(uVar1);
  return 0;
}

/* ---- FUNC 00019650 FUN_180019650 (82 bytes) ---- */

ulonglong FUN_180019650(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018001966d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(**(longlong **)(param_1 + 8) + 0x280))(*(longlong **)(param_1 + 8),0x7f3);
    return uVar2;
  }
  Ordinal_99(1);
  uVar1 = Ordinal_40(0x1c);
  Ordinal_99(0);
  return (ulonglong)uVar1;
}

/* ---- FUNC 000196B0 FUN_1800196b0 (64 bytes) ---- */

undefined8 FUN_1800196b0(longlong param_1,int *param_2,longlong *param_3)

{
  int *piVar1;
  undefined8 uVar2;
  longlong *plVar3;
  
  if (param_1 == 0) {
    return 0x80070057;
  }
  if (param_3 == (longlong *)0x0) {
    return 0x80004003;
  }
  if ((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) && (param_2[3] == 0x46000000)
     ) {
    (**(code **)(*(longlong *)(param_1 + 0x10) + 8))(param_1 + 0x10);
    uVar2 = 0;
    *param_3 = param_1 + 0x10;
  }
  else {
    plVar3 = &DAT_180064040;
    do {
      piVar1 = (int *)plVar3[-2];
      if ((piVar1 == (int *)0x0) ||
         (((*piVar1 == *param_2 && (piVar1[1] == param_2[1])) &&
          ((piVar1[2] == param_2[2] && (piVar1[3] == param_2[3])))))) {
        if ((code *)*plVar3 == (code *)0x1) {
          plVar3 = (longlong *)(plVar3[-1] + param_1);
          (**(code **)(*plVar3 + 8))(plVar3);
          *param_3 = (longlong)plVar3;
          return 0;
        }
        uVar2 = (*(code *)*plVar3)(param_1,param_2,param_3,plVar3[-1]);
        if ((int)uVar2 == 0) {
          return 0;
        }
        if ((piVar1 != (int *)0x0) && ((int)uVar2 < 0)) goto LAB_18001978b;
      }
      plVar3 = plVar3 + 3;
    } while (*plVar3 != 0);
    uVar2 = 0x80004002;
LAB_18001978b:
    *param_3 = 0;
  }
  return uVar2;
}

/* ---- FUNC 000196F0 FUN_1800196f0 (52 bytes) ---- */

undefined8 FUN_1800196f0(longlong param_1,longlong param_2)

{
  int *piVar1;
  undefined8 uVar2;
  int *unaff_RSI;
  longlong *plVar3;
  longlong *unaff_R14;
  longlong unaff_R15;
  bool in_ZF;
  
  if ((((in_ZF) && (*(int *)(param_2 + 4) == 0)) && (*(int *)(param_2 + 8) == 0xc0)) &&
     (*(int *)(param_2 + 0xc) == 0x46000000)) {
    (**(code **)(*(longlong *)(param_1 + 0x10) + 8))(param_1 + 0x10);
    uVar2 = 0;
    *unaff_R14 = param_1 + 0x10;
  }
  else {
    plVar3 = &DAT_180064040;
    do {
      piVar1 = (int *)plVar3[-2];
      if ((piVar1 == (int *)0x0) ||
         (((*piVar1 == *unaff_RSI && (piVar1[1] == unaff_RSI[1])) &&
          ((piVar1[2] == unaff_RSI[2] && (piVar1[3] == unaff_RSI[3])))))) {
        if ((code *)*plVar3 == (code *)0x1) {
          plVar3 = (longlong *)(plVar3[-1] + unaff_R15);
          (**(code **)(*plVar3 + 8))(plVar3);
          *unaff_R14 = (longlong)plVar3;
          return 0;
        }
        uVar2 = (*(code *)*plVar3)();
        if ((int)uVar2 == 0) {
          return 0;
        }
        if ((piVar1 != (int *)0x0) && ((int)uVar2 < 0)) goto LAB_18001978b;
      }
      plVar3 = plVar3 + 3;
    } while (*plVar3 != 0);
    uVar2 = 0x80004002;
LAB_18001978b:
    *unaff_R14 = 0;
  }
  return uVar2;
}

/* ---- FUNC 00019724 FUN_180019724 (115 bytes) ---- */

undefined8 FUN_180019724(void)

{
  int *piVar1;
  undefined8 uVar2;
  int *unaff_RSI;
  longlong *plVar3;
  undefined8 *unaff_R14;
  longlong unaff_R15;
  
  plVar3 = &DAT_180064040;
  do {
    piVar1 = (int *)plVar3[-2];
    if ((piVar1 == (int *)0x0) ||
       ((((*piVar1 == *unaff_RSI && (piVar1[1] == unaff_RSI[1])) && (piVar1[2] == unaff_RSI[2])) &&
        (piVar1[3] == unaff_RSI[3])))) {
      if ((code *)*plVar3 == (code *)0x1) {
        plVar3 = (longlong *)(plVar3[-1] + unaff_R15);
        (**(code **)(*plVar3 + 8))(plVar3);
        *unaff_R14 = plVar3;
        return 0;
      }
      uVar2 = (*(code *)*plVar3)();
      if ((int)uVar2 == 0) {
        return 0;
      }
      if ((piVar1 != (int *)0x0) && ((int)uVar2 < 0)) goto LAB_18001978b;
    }
    plVar3 = plVar3 + 3;
  } while (*plVar3 != 0);
  uVar2 = 0x80004002;
LAB_18001978b:
  *unaff_R14 = 0;
  return uVar2;
}

/* ---- FUNC 00019797 FUN_180019797 (22 bytes) ---- */

void FUN_180019797(void)

{
  return;
}

/* ---- FUNC 000197AD FUN_1800197ad (23 bytes) ---- */

undefined8 FUN_1800197ad(void)

{
  longlong *plVar1;
  longlong unaff_RDI;
  undefined8 *unaff_R14;
  longlong unaff_R15;
  
  plVar1 = (longlong *)(*(longlong *)(unaff_RDI + -8) + unaff_R15);
  (**(code **)(*plVar1 + 8))(plVar1);
  *unaff_R14 = plVar1;
  return 0;
}

/* ---- FUNC 000197C4 FUN_1800197c4 (22 bytes) ---- */

undefined8 FUN_1800197c4(void)

{
  return 0x80070057;
}

/* ---- FUNC 000197DC FUN_1800197dc (9 bytes) ---- */

void FUN_1800197dc(longlong param_1,int *param_2,longlong *param_3)

{
  FUN_1800196b0(param_1 + -0x10,param_2,param_3);
  return;
}

/* ---- FUNC 000197F0 FUN_1800197f0 (64 bytes) ---- */

undefined8 FUN_1800197f0(longlong param_1,int *param_2,longlong *param_3)

{
  int *piVar1;
  undefined8 uVar2;
  longlong *plVar3;
  
  if (param_1 == 0) {
    return 0x80070057;
  }
  if (param_3 == (longlong *)0x0) {
    return 0x80004003;
  }
  if ((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) && (param_2[3] == 0x46000000)
     ) {
    (**(code **)(*(longlong *)(param_1 + 0x10) + 8))(param_1 + 0x10);
    uVar2 = 0;
    *param_3 = param_1 + 0x10;
  }
  else {
    plVar3 = &DAT_1800640b0;
    do {
      piVar1 = (int *)plVar3[-2];
      if ((piVar1 == (int *)0x0) ||
         (((*piVar1 == *param_2 && (piVar1[1] == param_2[1])) &&
          ((piVar1[2] == param_2[2] && (piVar1[3] == param_2[3])))))) {
        if ((code *)*plVar3 == (code *)0x1) {
          plVar3 = (longlong *)(plVar3[-1] + param_1);
          (**(code **)(*plVar3 + 8))(plVar3);
          *param_3 = (longlong)plVar3;
          return 0;
        }
        uVar2 = (*(code *)*plVar3)(param_1,param_2,param_3,plVar3[-1]);
        if ((int)uVar2 == 0) {
          return 0;
        }
        if ((piVar1 != (int *)0x0) && ((int)uVar2 < 0)) goto LAB_1800198cb;
      }
      plVar3 = plVar3 + 3;
    } while (*plVar3 != 0);
    uVar2 = 0x80004002;
LAB_1800198cb:
    *param_3 = 0;
  }
  return uVar2;
}

/* ---- FUNC 00019830 FUN_180019830 (52 bytes) ---- */

undefined8 FUN_180019830(longlong param_1,longlong param_2)

{
  int *piVar1;
  undefined8 uVar2;
  int *unaff_RSI;
  longlong *plVar3;
  longlong *unaff_R14;
  longlong unaff_R15;
  bool in_ZF;
  
  if ((((in_ZF) && (*(int *)(param_2 + 4) == 0)) && (*(int *)(param_2 + 8) == 0xc0)) &&
     (*(int *)(param_2 + 0xc) == 0x46000000)) {
    (**(code **)(*(longlong *)(param_1 + 0x10) + 8))(param_1 + 0x10);
    uVar2 = 0;
    *unaff_R14 = param_1 + 0x10;
  }
  else {
    plVar3 = &DAT_1800640b0;
    do {
      piVar1 = (int *)plVar3[-2];
      if ((piVar1 == (int *)0x0) ||
         (((*piVar1 == *unaff_RSI && (piVar1[1] == unaff_RSI[1])) &&
          ((piVar1[2] == unaff_RSI[2] && (piVar1[3] == unaff_RSI[3])))))) {
        if ((code *)*plVar3 == (code *)0x1) {
          plVar3 = (longlong *)(plVar3[-1] + unaff_R15);
          (**(code **)(*plVar3 + 8))(plVar3);
          *unaff_R14 = (longlong)plVar3;
          return 0;
        }
        uVar2 = (*(code *)*plVar3)();
        if ((int)uVar2 == 0) {
          return 0;
        }
        if ((piVar1 != (int *)0x0) && ((int)uVar2 < 0)) goto LAB_1800198cb;
      }
      plVar3 = plVar3 + 3;
    } while (*plVar3 != 0);
    uVar2 = 0x80004002;
LAB_1800198cb:
    *unaff_R14 = 0;
  }
  return uVar2;
}

/* ---- FUNC 00019864 FUN_180019864 (115 bytes) ---- */

undefined8 FUN_180019864(void)

{
  int *piVar1;
  undefined8 uVar2;
  int *unaff_RSI;
  longlong *plVar3;
  undefined8 *unaff_R14;
  longlong unaff_R15;
  
  plVar3 = &DAT_1800640b0;
  do {
    piVar1 = (int *)plVar3[-2];
    if ((piVar1 == (int *)0x0) ||
       ((((*piVar1 == *unaff_RSI && (piVar1[1] == unaff_RSI[1])) && (piVar1[2] == unaff_RSI[2])) &&
        (piVar1[3] == unaff_RSI[3])))) {
      if ((code *)*plVar3 == (code *)0x1) {
        plVar3 = (longlong *)(plVar3[-1] + unaff_R15);
        (**(code **)(*plVar3 + 8))(plVar3);
        *unaff_R14 = plVar3;
        return 0;
      }
      uVar2 = (*(code *)*plVar3)();
      if ((int)uVar2 == 0) {
        return 0;
      }
      if ((piVar1 != (int *)0x0) && ((int)uVar2 < 0)) goto LAB_1800198cb;
    }
    plVar3 = plVar3 + 3;
  } while (*plVar3 != 0);
  uVar2 = 0x80004002;
LAB_1800198cb:
  *unaff_R14 = 0;
  return uVar2;
}

/* ---- FUNC 000198D7 FUN_1800198d7 (22 bytes) ---- */

void FUN_1800198d7(void)

{
  return;
}

/* ---- FUNC 000198ED FUN_1800198ed (23 bytes) ---- */

undefined8 FUN_1800198ed(void)

{
  longlong *plVar1;
  longlong unaff_RDI;
  undefined8 *unaff_R14;
  longlong unaff_R15;
  
  plVar1 = (longlong *)(*(longlong *)(unaff_RDI + -8) + unaff_R15);
  (**(code **)(*plVar1 + 8))(plVar1);
  *unaff_R14 = plVar1;
  return 0;
}

/* ---- FUNC 00019904 FUN_180019904 (22 bytes) ---- */

undefined8 FUN_180019904(void)

{
  return 0x80070057;
}

/* ---- FUNC 0001991C FUN_18001991c (9 bytes) ---- */

void FUN_18001991c(longlong param_1,int *param_2,longlong *param_3)

{
  FUN_1800197f0(param_1 + -0x10,param_2,param_3);
  return;
}

/* ---- FUNC 00019930 FUN_180019930 (105 bytes) ---- */

undefined8 FUN_180019930(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  if ((((*param_2 != DAT_180063510) || (param_2[1] != DAT_180063518)) &&
      ((*param_2 != DAT_180066c78 || (param_2[1] != DAT_180066c80)))) &&
     ((*param_2 != DAT_180066c58 || (param_2[1] != DAT_180066c60)))) {
    return 0x80004002;
  }
  *param_3 = param_1;
  (**(code **)(*param_1 + 8))();
  return 0;
}

/* ---- FUNC 000199A0 FUN_1800199a0 (215 bytes) ---- */

undefined8 FUN_1800199a0(longlong *param_1,longlong *param_2,longlong *param_3)

{
  *param_3 = 0;
  if ((((*param_2 == DAT_180066c58) && (param_2[1] == DAT_180066c60)) ||
      ((*param_2 == DAT_180066c78 && (param_2[1] == DAT_180066c80)))) ||
     ((*param_2 == DAT_180063500 && (param_2[1] == DAT_180063508)))) {
    *param_3 = (longlong)param_1;
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((*param_2 == DAT_180066ca8) && (param_2[1] == DAT_180066cb0)) {
    *param_3 = param_1[1] + 0x30;
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((*param_2 == DAT_180066cd8) && (param_2[1] == DAT_180066ce0)) {
    *param_3 = param_1[1] + 0x188;
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  return 0x80004002;
}

/* ---- FUNC 00019A80 FUN_180019a80 (112 bytes) ---- */

undefined8 FUN_180019a80(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  *param_3 = 0;
  if ((((*param_2 != DAT_180066c58) || (param_2[1] != DAT_180066c60)) &&
      ((*param_2 != DAT_180066c78 || (param_2[1] != DAT_180066c80)))) &&
     ((*param_2 != DAT_1800634e0 || (param_2[1] != DAT_1800634e8)))) {
    return 0x80004002;
  }
  *param_3 = param_1;
  (**(code **)(*param_1 + 8))();
  return 0;
}

/* ---- FUNC 00019AF0 FUN_180019af0 (1795 bytes) ---- */

/* WARNING: Removing unreachable block (ram,0x00018001a1d4) */
/* WARNING: Removing unreachable block (ram,0x00018001a1dc) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

INT_PTR FUN_180019af0(longlong *param_1,longlong *param_2,longlong *param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  longlong *plVar2;
  HMODULE pHVar3;
  FARPROC pFVar4;
  INT_PTR IVar5;
  longlong *plVar6;
  
  plVar2 = (longlong *)0x0;
  *param_3 = 0;
  if ((((*param_2 == DAT_180066c58) && (param_2[1] == DAT_180066c60)) ||
      ((*param_2 == DAT_180066c78 && (param_2[1] == DAT_180066c80)))) ||
     ((*param_2 == DAT_180063460 && (param_2[1] == DAT_180063468)))) {
    *param_3 = (longlong)param_1;
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((*param_2 == DAT_180066ca8) && (param_2[1] == DAT_180066cb0)) {
    *param_3 = (longlong)(param_1 + 6);
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if (((*param_2 == DAT_180066d28) && (param_2[1] == DAT_180066d30)) ||
     ((*param_2 == DAT_180066cf8 && (param_2[1] == DAT_180066d00)))) {
    *param_3 = (longlong)(param_1 + 0x1c);
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if (((*param_2 == DAT_180066dd8) && (param_2[1] == DAT_180066de0)) ||
     (((*param_2 == DAT_180066d98 && (param_2[1] == DAT_180066da0)) ||
      ((*param_2 == DAT_180066da8 && (param_2[1] == DAT_180066db0)))))) {
    *param_3 = (longlong)(param_1 + 0x25);
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((*param_2 == DAT_180066db8) && (param_2[1] == DAT_180066dc0)) {
    *param_3 = (longlong)(param_1 + 0x2b);
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((*param_2 == DAT_180066cd8) && (param_2[1] == DAT_180066ce0)) {
    *param_3 = (longlong)(param_1 + 0x31);
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((*param_2 == DAT_180063470) && (param_2[1] == DAT_180063478)) {
    *param_3 = (longlong)(param_1 + 0x4e);
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((*param_2 == DAT_1800634a0) && (param_2[1] == DAT_1800634a8)) {
    *param_3 = (longlong)(param_1 + 0x51);
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((*param_2 == DAT_180063480) && (param_2[1] == DAT_180063488)) {
    *param_3 = (longlong)(param_1 + 0x5b);
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((*param_2 == DAT_180063490) && (param_2[1] == DAT_180063498)) {
    *param_3 = (longlong)(param_1 + 0x5f);
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((*param_2 == DAT_180066e38) && (param_2[1] == DAT_180066e40)) {
    *param_3 = (longlong)(param_1 + 0x62);
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((*param_2 == DAT_180063640) && (param_2[1] == DAT_180063648)) {
    *param_3 = (longlong)(param_1 + 0x65);
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((*param_2 == DAT_1800635c0) && (param_2[1] == DAT_1800635c8)) {
    *param_3 = (longlong)(param_1 + 0x67);
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((*param_2 == DAT_180066de8) && (param_2[1] == DAT_180066df0)) {
    *param_3 = (longlong)(param_1 + 0x6a);
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((*param_2 == DAT_180066e28) && (param_2[1] == DAT_180066e30)) {
    plVar6 = (longlong *)param_1[0x36];
    if (plVar6 == (longlong *)0x0) {
      puVar1 = operator_new(0x20);
      if (puVar1 != (undefined8 *)0x0) {
        plVar2 = FUN_180021530(puVar1,param_1);
      }
      param_1[0x36] = (longlong)plVar2;
      (**(code **)(*plVar2 + 8))(plVar2);
      plVar6 = (longlong *)param_1[0x36];
    }
    (**(code **)(*plVar6 + 8))();
    *param_3 = param_1[0x36];
    return 0;
  }
  if ((*param_2 == DAT_180063860) && (param_2[1] == DAT_180063868)) {
    FUN_18000fee0(param_1,param_2,param_3,param_4);
    pHVar3 = LoadLibraryExA("fimmtop.dll",(HANDLE)0x0,0);
    if ((pHVar3 != (HMODULE)0x0) &&
       (pFVar4 = GetProcAddress(pHVar3,"GetASVNode"), pFVar4 != (FARPROC)0x0)) {
      IVar5 = (*pFVar4)(0,param_1);
      *param_3 = IVar5;
      if (IVar5 != 0) {
        return 0;
      }
    }
  }
  else if ((*param_2 == DAT_180063870) && (param_2[1] == DAT_180063878)) {
    FUN_18000fee0(param_1,param_2,param_3,param_4);
    if (DAT_180079448 != (longlong *)0x0) {
      (**(code **)(*DAT_180079448 + 8))();
      *param_3 = (longlong)DAT_180079448;
      return 0;
    }
    pHVar3 = LoadLibraryExA("fimmtop.dll",(HANDLE)0x0,0);
    if ((((pHVar3 != (HMODULE)0x0) &&
         (pFVar4 = GetProcAddress(pHVar3,"GetTopMMEntry"), pFVar4 != (FARPROC)0x0)) &&
        (IVar5 = (*pFVar4)(), IVar5 != 0)) &&
       ((pHVar3 = LoadLibraryExA("asiadapterif.dll",(HANDLE)0x0,0), pHVar3 != (HMODULE)0x0 &&
        (pFVar4 = GetProcAddress(pHVar3,"CreateAdapterFromEntry"), pFVar4 != (FARPROC)0x0)))) {
      IVar5 = (*pFVar4)(param_3,IVar5,param_1);
      DAT_180079448 = (longlong *)*param_3;
      return IVar5;
    }
  }
  else if ((((((*param_2 != DAT_180066cb8) || (param_2[1] != DAT_180066cc0)) &&
             ((*param_2 != DAT_180066cc8 || (param_2[1] != DAT_180066cd0)))) &&
            ((((*param_2 != DAT_180066d78 || (param_2[1] != DAT_180066d80)) &&
              ((*param_2 != DAT_1800638c8 || (param_2[1] != DAT_1800638d0)))) &&
             ((*param_2 != DAT_180064158 || (param_2[1] != DAT_180064160)))))) &&
           ((*param_2 != DAT_180064168 || (param_2[1] != DAT_180064170)))) &&
          ((((*param_2 != DAT_180064178 || (param_2[1] != DAT_180064180)) &&
            ((*param_2 != DAT_180064188 || (param_2[1] != DAT_180064190)))) &&
           (((*param_2 != DAT_180064198 || (param_2[1] != DAT_1800641a0)) &&
            (((*param_2 != DAT_1800641a8 || (param_2[1] != _DAT_1800641b0)) && (param_1[4] != 0)))))
           ))) {
    IVar5 = HAQueryInterface();
    return IVar5;
  }
  return 0x80004002;
}

/* ---- FUNC 0001A200 FUN_18001a200 (91 bytes) ---- */

undefined8 FUN_18001a200(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  
  *param_3 = 0;
  if (((*param_2 != DAT_180066c58) || (param_2[1] != DAT_180066c60)) &&
     ((*param_2 != DAT_180063490 || (param_2[1] != DAT_180063498)))) {
                    /* WARNING: Could not recover jumptable at 0x00018001a258. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)**(undefined8 **)param_1[1])();
    return uVar1;
  }
  *param_3 = param_1;
  (**(code **)(*param_1 + 8))();
  return 0;
}

/* ---- FUNC 0001A260 FUN_18001a260 (91 bytes) ---- */

undefined8 FUN_18001a260(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  
  *param_3 = 0;
  if (((*param_2 != DAT_180066c58) || (param_2[1] != DAT_180066c60)) &&
     ((*param_2 != DAT_180063640 || (param_2[1] != DAT_180063648)))) {
                    /* WARNING: Could not recover jumptable at 0x00018001a2b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)**(undefined8 **)param_1[1])();
    return uVar1;
  }
  *param_3 = param_1;
  (**(code **)(*param_1 + 8))();
  return 0;
}

/* ---- FUNC 0001A2C0 FUN_18001a2c0 (91 bytes) ---- */

undefined8 FUN_18001a2c0(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  
  *param_3 = 0;
  if (((*param_2 != DAT_180066c58) || (param_2[1] != DAT_180066c60)) &&
     ((*param_2 != DAT_1800635c0 || (param_2[1] != DAT_1800635c8)))) {
                    /* WARNING: Could not recover jumptable at 0x00018001a318. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)**(undefined8 **)param_1[1])();
    return uVar1;
  }
  *param_3 = param_1;
  (**(code **)(*param_1 + 8))();
  return 0;
}

/* ---- FUNC 0001A320 FUN_18001a320 (87 bytes) ---- */

undefined8 FUN_18001a320(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  *param_3 = 0;
  if (((*param_2 != DAT_180066c58) || (param_2[1] != DAT_180066c60)) &&
     ((*param_2 != DAT_180063480 || (param_2[1] != DAT_180063488)))) {
    return 0x80004002;
  }
  *param_3 = param_1;
  (**(code **)(*param_1 + 8))();
  return 0;
}

/* ---- FUNC 0001A380 FUN_18001a380 (91 bytes) ---- */

undefined8 FUN_18001a380(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  
  *param_3 = 0;
  if (((*param_2 != DAT_180066c58) || (param_2[1] != DAT_180066c60)) &&
     ((*param_2 != DAT_180066e38 || (param_2[1] != DAT_180066e40)))) {
                    /* WARNING: Could not recover jumptable at 0x00018001a3d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)**(undefined8 **)param_1[1])();
    return uVar1;
  }
  *param_3 = param_1;
  (**(code **)(*param_1 + 8))();
  return 0;
}

/* ---- FUNC 0001A3E0 FUN_18001a3e0 (87 bytes) ---- */

undefined8 FUN_18001a3e0(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  *param_3 = 0;
  if (((*param_2 != DAT_180066c58) || (param_2[1] != DAT_180066c60)) &&
     ((*param_2 != DAT_180066de8 || (param_2[1] != DAT_180066df0)))) {
    return 0x80004002;
  }
  *param_3 = param_1;
  (**(code **)(*param_1 + 8))();
  return 0;
}

/* ---- FUNC 0001A440 FUN_18001a440 (87 bytes) ---- */

undefined8 FUN_18001a440(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  *param_3 = 0;
  if (((*param_2 != DAT_180066c58) || (param_2[1] != DAT_180066c60)) &&
     ((*param_2 != DAT_1800634d0 || (param_2[1] != DAT_1800634d8)))) {
    return 0x80004002;
  }
  *param_3 = param_1;
  (**(code **)(*param_1 + 8))();
  return 0;
}

/* ---- FUNC 0001A4A0 FUN_18001a4a0 (266 bytes) ---- */

undefined8 FUN_18001a4a0(longlong *param_1,longlong *param_2,longlong *param_3)

{
  *param_3 = 0;
  if ((((*param_2 == DAT_180066c58) && (param_2[1] == DAT_180066c60)) ||
      ((*param_2 == DAT_180066c78 && (param_2[1] == DAT_180066c80)))) ||
     ((*param_2 == DAT_180063470 && (param_2[1] == DAT_180063478)))) {
    *param_3 = (longlong)param_1;
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((*param_2 == DAT_180066ca8) && (param_2[1] == DAT_180066cb0)) {
    *param_3 = param_1[1] + 0x30;
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((*param_2 == DAT_180066cd8) && (param_2[1] == DAT_180066ce0)) {
    *param_3 = param_1[1] + 0x188;
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((*param_2 == DAT_180063500) && (param_2[1] == DAT_180063508)) {
    *param_3 = param_1[1] + 600;
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  return 0x80004002;
}

/* ---- FUNC 0001A5B0 FUN_18001a5b0 (112 bytes) ---- */

undefined8 FUN_18001a5b0(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  *param_3 = 0;
  if ((((*param_2 != DAT_180066c58) || (param_2[1] != DAT_180066c60)) &&
      ((*param_2 != DAT_180066c78 || (param_2[1] != DAT_180066c80)))) &&
     ((*param_2 != DAT_1800634a0 || (param_2[1] != DAT_1800634a8)))) {
    return 0x80004002;
  }
  *param_3 = param_1;
  (**(code **)(*param_1 + 8))();
  return 0;
}

/* ---- FUNC 0001A620 FUN_18001a620 (119 bytes) ---- */

INT_PTR FUN_18001a620(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  HMODULE hModule;
  FARPROC pFVar1;
  INT_PTR IVar2;
  
  hModule = LoadLibraryExA("fimmtop.dll",(HANDLE)0x0,0);
  if ((hModule != (HMODULE)0x0) &&
     (pFVar1 = GetProcAddress(hModule,"CXSQueryService"), pFVar1 != (FARPROC)0x0)) {
    IVar2 = (*pFVar1)(*(undefined8 *)(param_1 + 8),param_2,param_3,param_4);
    return IVar2;
  }
  return 0x80004005;
}

/* ---- FUNC 0001A6A0 FUN_18001a6a0 (321 bytes) ---- */

undefined8 FUN_18001a6a0(LPUNKNOWN param_1)

{
  int iVar1;
  
  if (*(int *)((longlong)&param_1[0x1a].lpVtbl + 4) == 0) {
    *(undefined4 *)((longlong)&param_1[0x1a].lpVtbl + 4) = 1;
    (**(code **)(*DAT_180079800 + 0x158))();
    CoFreeUnusedLibraries();
    CoDisconnectObject(param_1 + 6,0);
    CoDisconnectObject(param_1 + 0x1c,0);
    CoDisconnectObject(param_1 + 0x25,0);
    CoDisconnectObject(param_1 + 0x2b,0);
    CoDisconnectObject(param_1 + 0x31,0);
    CoDisconnectObject(param_1 + 0x4e,0);
    CoDisconnectObject(param_1 + 0x51,0);
    CoDisconnectObject(param_1 + 0x5b,0);
    CoDisconnectObject(param_1 + 0x5f,0);
    CoDisconnectObject(param_1 + 0x62,0);
    if (param_1[0x36].lpVtbl != (IUnknownVtbl *)0x0) {
      CoDisconnectObject((LPUNKNOWN)param_1[0x36].lpVtbl,0);
    }
    CoDisconnectObject(param_1 + 0x67,0);
    CoDisconnectObject(param_1 + 0x6a,0);
    CoDisconnectObject(param_1,0);
    iVar1 = *(int *)((longlong)&param_1[2].lpVtbl + 4);
    while (iVar1 != 0) {
      FUN_180018e30(param_1,0,1);
      iVar1 = *(int *)((longlong)&param_1[2].lpVtbl + 4);
    }
    if (DAT_180079800 != (longlong *)0x0) {
      (**(code **)(*DAT_180079800 + 0x10))();
    }
  }
  return 1;
}

/* ---- FUNC 0001A7F0 FUN_18001a7f0 (94 bytes) ---- */

ULONG FUN_18001a7f0(LPUNKNOWN param_1)

{
  ULONG UVar1;
  int iVar2;
  
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018001a80f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    UVar1 = (*param_1->lpVtbl[0x1a].Release)(param_1);
    return UVar1;
  }
  iVar2 = FUN_1800375b0();
  if (iVar2 != 0) {
    FUN_180037570();
  }
  FUN_18000ef30((longlong *)param_1,1);
  FUN_18001a6a0(param_1);
  FUN_1800111f0((longlong)param_1);
  return 0;
}

/* ---- FUNC 0001A850 FUN_18001a850 (116 bytes) ---- */

void FUN_18001a850(longlong *param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  
  lVar1 = *param_1;
  iVar2 = GRinqsme();
  if (iVar2 == 0) {
    iVar2 = 0x7d1;
    if (param_2 != 0) {
      iVar2 = param_2;
    }
  }
  else if (iVar2 == 1) {
    iVar2 = 0x7f6;
  }
  else if (iVar2 == 2) {
    iVar2 = 0x7f7;
  }
  else if (iVar2 == 3) {
    iVar2 = 0x7f8;
  }
  else {
    iVar2 = 0x7d1;
  }
                    /* WARNING: Could not recover jumptable at 0x00018001a8c1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(lVar1 + 0x280))(param_1,iVar2);
  return;
}

/* ---- FUNC 0001A8D0 FUN_18001a8d0 (407 bytes) ---- */

undefined8 FUN_18001a8d0(longlong param_1,uint param_2)

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
  if (*(BSTR *)(param_1 + 0x60) != (BSTR)0x0) {
    SysFreeString(*(BSTR *)(param_1 + 0x60));
  }
  if (*(BSTR *)(param_1 + 0x58) != (BSTR)0x0) {
    SysFreeString(*(BSTR *)(param_1 + 0x58));
  }
  if (*(BSTR *)(param_1 + 0x68) != (BSTR)0x0) {
    SysFreeString(*(BSTR *)(param_1 + 0x68));
  }
  *(undefined8 *)(param_1 + 0x50) = 0;
  *(undefined8 *)(param_1 + 0x58) = 0;
  *(undefined8 *)(param_1 + 0x60) = 0;
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined8 *)(param_1 + 0x78) = 0;
  *(undefined8 *)(param_1 + 0x80) = 0;
  *(undefined8 *)(param_1 + 0x88) = 0;
  *(short *)(param_1 + 0x50) = (short)param_2;
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
    *(BSTR *)(param_1 + 0x60) = pOVar3;
  }
  if (*(int *)(local_res18 + -0x10) != 0) {
    pOVar3 = FUN_1800019d0(local_res18);
    *(BSTR *)(param_1 + 0x58) = pOVar3;
  }
  *(undefined4 *)(param_1 + 0x90) = 1;
  HVar1 = CreateErrorInfo(&local_res8);
  if (-1 < HVar1) {
    (*local_res8->lpVtbl->SetGUID)(local_res8,(GUID *)&DAT_180063460);
    if (*(LPOLESTR *)(param_1 + 0x58) != (LPOLESTR)0x0) {
      (*local_res8->lpVtbl->SetSource)(local_res8,*(LPOLESTR *)(param_1 + 0x58));
    }
    if (*(LPOLESTR *)(param_1 + 0x60) != (LPOLESTR)0x0) {
      (*local_res8->lpVtbl->SetDescription)(local_res8,*(LPOLESTR *)(param_1 + 0x60));
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

/* ---- FUNC 0001AA70 FUN_18001aa70 (567 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18001aa70(longlong param_1,undefined8 *param_2)

{
  code *pcVar1;
  _func_6753 *p_Var2;
  LPOLESTR pOVar3;
  _func_6754 *p_Var4;
  _func_6755 *p_Var5;
  _func_6750 *p_Var6;
  _func_6744 *p_Var7;
  _func_6752 *p_Var8;
  short sVar9;
  int iVar10;
  HRESULT HVar11;
  BSTR pOVar12;
  longlong lVar13;
  longlong lVar14;
  WCHAR *pWVar15;
  undefined8 *puVar16;
  OLECHAR *pOVar17;
  OLECHAR *psz;
  OLECHAR *pOVar18;
  undefined1 auStackY_98 [32];
  WCHAR local_68 [24];
  ICreateErrorInfo *local_38;
  IErrorInfo *local_30;
  ulonglong local_28;
  
  pWVar15 = local_68;
  local_28 = DAT_180077818 ^ (ulonglong)&local_38;
  if (*(BSTR *)(param_1 + 0x60) != (BSTR)0x0) {
    SysFreeString(*(BSTR *)(param_1 + 0x60));
  }
  if (*(BSTR *)(param_1 + 0x58) != (BSTR)0x0) {
    SysFreeString(*(BSTR *)(param_1 + 0x58));
  }
  if (*(BSTR *)(param_1 + 0x68) != (BSTR)0x0) {
    SysFreeString(*(BSTR *)(param_1 + 0x68));
  }
  *(undefined8 *)(param_1 + 0x50) = 0;
  *(undefined8 *)(param_1 + 0x58) = 0;
  *(undefined8 *)(param_1 + 0x60) = 0;
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined8 *)(param_1 + 0x78) = 0;
  *(undefined8 *)(param_1 + 0x80) = 0;
  *(undefined8 *)(param_1 + 0x88) = 0;
  sVar9 = 0x7d1;
  if (*(short *)(param_2 + 1) != 0) {
    sVar9 = *(short *)(param_2 + 1);
  }
  pOVar18 = (OLECHAR *)0x0;
  *(short *)(param_1 + 0x50) = sVar9;
  pOVar17 = (OLECHAR *)param_2[2];
  lVar14 = -1;
  lVar13 = lVar14;
  if (pOVar17 == (OLECHAR *)0x0) {
    pWVar15 = (WCHAR *)auStackY_98;
    pOVar17 = pOVar18;
    if (&stack0x00000000 != (undefined1 *)0x68) {
      local_68[0] = L'\0';
      iVar10 = MultiByteToWideChar(0,0,"Unexpected Error",-1,local_68,0x11);
      pOVar17 = local_68;
      if (iVar10 == 0) {
        pOVar17 = pOVar18;
      }
    }
    pOVar12 = SysAllocString(pOVar17);
  }
  else {
    do {
      lVar13 = lVar13 + 1;
    } while (pOVar17[lVar13] != L'\0');
    pOVar12 = SysAllocStringLen(pOVar17,(UINT)lVar13);
  }
  *(BSTR *)(param_1 + 0x60) = pOVar12;
  pOVar17 = (OLECHAR *)param_2[3];
  if (pOVar17 == (OLECHAR *)0x0) {
    puVar16 = (undefined8 *)((longlong)pWVar15 + -0x20);
    pOVar17 = (OLECHAR *)((longlong)pWVar15 + 0x10);
    psz = pOVar18;
    if (pOVar17 != (OLECHAR *)0x0) {
      *(undefined4 *)((longlong)pWVar15 + 8) = 0xe;
      *(OLECHAR **)pWVar15 = pOVar17;
      *pOVar17 = L'\0';
      *(undefined8 *)((longlong)pWVar15 + -0x28) = 0x18001abcd;
      iVar10 = MultiByteToWideChar(0,0,"Apwn.Document",-1,*(LPWSTR *)pWVar15,
                                   *(int *)((longlong)pWVar15 + 8));
      psz = pOVar17;
      if (iVar10 == 0) {
        psz = pOVar18;
      }
    }
    *(undefined8 *)((longlong)pWVar15 + -0x28) = 0x18001abe1;
    pOVar12 = SysAllocString(psz);
  }
  else {
    do {
      lVar14 = lVar14 + 1;
    } while (pOVar17[lVar14] != L'\0');
    *(undefined8 *)((longlong)pWVar15 + -8) = 0x18001ab93;
    pOVar12 = SysAllocStringLen(pOVar17,(UINT)lVar14);
    puVar16 = (undefined8 *)pWVar15;
  }
  *(BSTR *)(param_1 + 0x58) = pOVar12;
  *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_1 + 0x90) = 1;
  pcVar1 = (code *)*param_2;
  if (pcVar1 != (code *)0x0) {
    *(undefined8 *)((longlong)puVar16 + -8) = 0x18001ac03;
    (*pcVar1)(param_2);
  }
  *(undefined8 *)((longlong)puVar16 + -8) = 0x18001ac0d;
  HVar11 = CreateErrorInfo(&local_38);
  if (-1 < HVar11) {
    p_Var2 = local_38->lpVtbl->SetGUID;
    *(undefined8 *)((longlong)puVar16 + -8) = 0x18001ac22;
    (*p_Var2)(local_38,(GUID *)&DAT_180063460);
    pOVar3 = *(LPOLESTR *)(param_1 + 0x58);
    if (pOVar3 != (LPOLESTR)0x0) {
      p_Var4 = local_38->lpVtbl->SetSource;
      *(undefined8 *)((longlong)puVar16 + -8) = 0x18001ac35;
      (*p_Var4)(local_38,pOVar3);
    }
    pOVar3 = *(LPOLESTR *)(param_1 + 0x60);
    if (pOVar3 != (LPOLESTR)0x0) {
      p_Var5 = local_38->lpVtbl->SetDescription;
      *(undefined8 *)((longlong)puVar16 + -8) = 0x18001ac48;
      (*p_Var5)(local_38,pOVar3);
    }
    p_Var6 = local_38->lpVtbl->QueryInterface;
    *(undefined8 *)((longlong)puVar16 + -8) = 0x18001ac5c;
    HVar11 = (*p_Var6)(local_38,(IID *)&DAT_180066c98,&local_30);
    if (-1 < HVar11) {
      *(undefined8 *)((longlong)puVar16 + -8) = 0x18001ac6c;
      SetErrorInfo(0,local_30);
      p_Var7 = local_30->lpVtbl->Release;
      *(undefined8 *)((longlong)puVar16 + -8) = 0x18001ac76;
      (*p_Var7)(local_30);
    }
    p_Var8 = local_38->lpVtbl->Release;
    *(undefined8 *)((longlong)puVar16 + -8) = 0x18001ac80;
    (*p_Var8)(local_38);
  }
  *(undefined8 *)((longlong)puVar16 + -8) = 0x18001ac91;
  return 0x80020009;
}

/* ---- FUNC 0001ACB0 FUN_18001acb0 (357 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

ulonglong FUN_18001acb0(longlong *param_1,LPCWSTR param_2)

{
  code *pcVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  char *pcVar6;
  int iVar7;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar8;
  undefined1 *puVar9;
  undefined8 uStack_60;
  undefined1 auStack_58 [32];
  undefined8 uStack_38;
  int aiStack_30 [2];
  undefined8 local_28 [2];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_18 [8];
  ulonglong local_10;
  longlong lVar5;
  
  puVar9 = auStack_58;
  local_10 = DAT_180077818 ^ (ulonglong)local_18;
  if (DAT_1800797f8 != 0) {
    uStack_60 = 0x18001acf6;
    uVar3 = (**(code **)(*param_1 + 0x280))(param_1,0x7f3);
    goto LAB_18001adf3;
  }
  uStack_60 = 0x18001ad0c;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_18,"");
  puVar9 = auStack_58;
  if (param_2 == (LPCWSTR)0x0) {
LAB_18001ada2:
    pCVar8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  }
  else {
    lVar4 = -1;
    do {
      lVar5 = lVar4;
      lVar4 = lVar5 + 1;
    } while (param_2[lVar4] != L'\0');
    iVar7 = (int)lVar5 + 2;
    puVar9 = auStack_58;
    if (0x3fffffff < iVar7) goto LAB_18001ada2;
    lVar4 = (longlong)(int)lVar4 * 2;
    uVar3 = lVar4 + 0x11;
    if (uVar3 <= lVar4 + 2U) {
      uVar3 = 0xffffffffffffff0;
    }
    uStack_60 = 0x18001ad5e;
    lVar4 = -(uVar3 & 0xfffffffffffffff0);
    puVar9 = auStack_58 + lVar4;
    pCVar8 = local_18 + lVar4;
    if (pCVar8 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0)
    goto LAB_18001ada2;
    *pCVar8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>)0x0;
    *(undefined8 *)((longlong)local_28 + lVar4 + 8) = 0;
    *(undefined8 *)((longlong)local_28 + lVar4) = 0;
    *(int *)((longlong)aiStack_30 + lVar4) = iVar7 * 2;
    *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
     ((longlong)&uStack_38 + lVar4) = pCVar8;
    *(undefined8 *)(auStack_58 + lVar4 + -8) = 0x18001ad97;
    iVar7 = WideCharToMultiByte(0,0,param_2,-1,*(LPSTR *)((longlong)&uStack_38 + lVar4),
                                *(int *)((longlong)aiStack_30 + lVar4),
                                *(LPCSTR *)((longlong)local_28 + lVar4),
                                *(LPBOOL *)((longlong)local_28 + lVar4 + 8));
    puVar9 = auStack_58 + lVar4;
    if (iVar7 == 0) {
      pCVar8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
      puVar9 = auStack_58 + lVar4;
    }
  }
  *(undefined8 *)(puVar9 + -8) = 0x18001adb1;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            (local_18,(char *)pCVar8);
  *(undefined8 *)(puVar9 + -8) = 0x18001adbb;
  Ordinal_102(1);
  lVar4 = *param_1;
  *(undefined8 *)(puVar9 + -8) = 0x18001adca;
  pcVar6 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)local_18,0);
  pcVar1 = *(code **)(lVar4 + 0x2c8);
  *(undefined8 *)(puVar9 + -8) = 0x18001add6;
  uVar2 = (*pcVar1)(param_1,pcVar6);
  uVar3 = (ulonglong)uVar2;
  *(undefined8 *)(puVar9 + -8) = 0x18001ade7;
  ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)local_18,-1);
  *(undefined8 *)(puVar9 + -8) = 0x18001adf1;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_18);
LAB_18001adf3:
  *(undefined8 *)(puVar9 + -8) = 0x18001adff;
  return uVar3;
}

/* ---- FUNC 0001AE20 FUN_18001ae20 (18 bytes) ---- */

undefined8 FUN_18001ae20(undefined8 param_1,undefined4 param_2)

{
  RLrcnall(param_2);
  return 0;
}

/* ---- FUNC 0001AE40 FUN_18001ae40 (375 bytes) ---- */

undefined8 FUN_18001ae40(longlong param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong *plVar4;
  longlong *plVar5;
  __POSITION *p_Var6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  CPtrList local_68 [8];
  longlong *local_60;
  
  CPtrList::CPtrList(local_68,10);
  uVar1 = *(ulonglong *)(param_1 + 0x200);
  uVar9 = 0;
  uVar8 = uVar9;
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar8 < 0) || (*(longlong *)(param_1 + 0x200) <= (longlong)uVar8)) {
LAB_18001afb2:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x1f8) + uVar8 * 8);
      uVar3 = *(ulonglong *)(lVar2 + 0x120);
      uVar7 = uVar9;
      if (uVar3 != 0) {
        do {
          if (((longlong)uVar7 < 0) || (*(longlong *)(lVar2 + 0x120) <= (longlong)uVar7))
          goto LAB_18001afb2;
          plVar5 = FUN_18003a300(*(longlong **)(*(longlong *)(lVar2 + 0x118) + uVar7 * 8));
          if (plVar5 != (longlong *)0x0) {
            p_Var6 = CPtrList::Find(local_68,plVar5,(__POSITION *)0x0);
            if (p_Var6 == (__POSITION *)0x0) {
              CPtrList::AddHead(local_68,plVar5);
            }
            else {
              (**(code **)(*plVar5 + 0x10))(plVar5);
            }
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar3);
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < uVar1);
  }
  plVar5 = local_60;
  if (local_60 != (longlong *)0x0) {
    while( true ) {
      plVar4 = (longlong *)plVar5[2];
      plVar5 = (longlong *)*plVar5;
      if ((int)uVar9 == 0) {
        uVar9 = 1;
        (**(code **)(*plVar4 + 0x170))(plVar4,1);
      }
      (**(code **)(*plVar4 + 0x168))(plVar4);
      if (plVar5 == (longlong *)0x0) break;
      (**(code **)(*plVar4 + 0x10))();
    }
    (**(code **)(*plVar4 + 0x170))(plVar4,0);
    (**(code **)(*plVar4 + 0x10))(plVar4);
  }
  CPtrList::RemoveAll(local_68);
  CPtrList::~CPtrList(local_68);
  return 0;
}

/* ---- FUNC 0001AFC0 FUN_18001afc0 (807 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

char * FUN_18001afc0(longlong *param_1,VARIANTARG *param_2,VARIANTARG *param_3)

{
  char *pcVar1;
  VARTYPE VVar2;
  undefined8 *puVar3;
  HRESULT HVar4;
  uint uVar5;
  char *pcVar6;
  longlong lVar7;
  char *pcVar9;
  ulonglong uVar10;
  int iVar11;
  LPCWSTR lpWideCharStr;
  undefined1 *puVar12;
  undefined4 uVar13;
  undefined8 uStack_d0;
  undefined1 auStack_c8 [32];
  undefined8 uStack_a8;
  int aiStack_a0 [2];
  undefined8 local_98 [2];
  longlong local_88;
  VARIANTARG local_80;
  undefined8 local_68;
  _union_1719 _Stack_60;
  undefined8 local_58;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_28;
  longlong lVar8;
  
  puVar12 = auStack_c8;
  local_28 = DAT_180077818 ^ (ulonglong)&local_88;
  if (DAT_1800797f8 != 0) {
    uStack_d0 = 0x18001b019;
    pcVar6 = (char *)(**(code **)(*(longlong *)param_1[1] + 0x280))((longlong *)param_1[1],0x7f3);
    puVar12 = auStack_c8;
    goto LAB_18001b2bc;
  }
  VVar2 = (param_2->n1).n2.vt;
  if ((VVar2 == 10) || (VVar2 == 0)) {
    uStack_d0 = 0x18001b2bc;
    pcVar6 = (char *)Ordinal_40(0xb);
    goto LAB_18001b2bc;
  }
  if (VVar2 == 0x400c) {
    local_68 = *(undefined8 *)&param_3->n1;
    _Stack_60 = (param_3->n1).decVal.u2;
    local_58 = *(undefined8 *)((longlong)&param_3->n1 + 0x10);
    puVar3 = *(undefined8 **)((longlong)&param_2->n1 + 8);
    local_48 = *puVar3;
    uStack_40 = puVar3[1];
    local_38 = puVar3[2];
    uStack_d0 = 0x18001b077;
    pcVar6 = (char *)(**(code **)(*param_1 + 0x78))(param_1,&local_48,&local_68);
    puVar12 = auStack_c8;
    goto LAB_18001b2bc;
  }
  if ((param_3->n1).n2.vt == 0x400c) {
    puVar3 = *(undefined8 **)((longlong)&param_3->n1 + 8);
    local_48 = *puVar3;
    uStack_40 = puVar3[1];
    local_38 = puVar3[2];
    local_68 = *(undefined8 *)&param_2->n1;
    _Stack_60 = (param_2->n1).decVal.u2;
    local_58 = *(undefined8 *)((longlong)&param_2->n1 + 0x10);
    uStack_d0 = 0x18001b0b9;
    pcVar6 = (char *)(**(code **)(*param_1 + 0x78))(param_1,&local_68,&local_48);
    puVar12 = auStack_c8;
    goto LAB_18001b2bc;
  }
  uStack_d0 = 0x18001b0c8;
  VariantInit(&local_80);
  VVar2 = (param_2->n1).n2.vt;
  if (VVar2 == 2) {
    uVar13 = SEXT24(*(short *)((longlong)&param_2->n1 + 8));
  }
  else if (VVar2 == 3) {
    uVar13 = *(int *)((longlong)&param_2->n1 + 8);
  }
  else if (VVar2 == 0x4002) {
    uVar13 = SEXT24(**(short **)((longlong)&param_2->n1 + 8));
  }
  else if (VVar2 == 0x4003) {
    uVar13 = **(int **)((longlong)&param_2->n1 + 8);
  }
  else {
    uStack_d0 = 0x18001b0f8;
    HVar4 = VariantChangeType(&local_80,param_2,0,3);
    uVar13 = local_80.n1._8_4_;
    if (HVar4 < 0) {
      uStack_d0 = 0x18001b10e;
      pcVar6 = (char *)(**(code **)(*(longlong *)param_1[1] + 0x280))((longlong *)param_1[1],0x7d4);
      puVar12 = auStack_c8;
      goto LAB_18001b2bc;
    }
    uStack_d0 = 0x18001b121;
    VariantClear(&local_80);
  }
  uStack_d0 = 0x18001b14b;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_88);
  VVar2 = (param_3->n1).n2.vt;
  pcVar6 = (char *)0x0;
  if (VVar2 == 1) {
LAB_18001b249:
    if (uVar13 == 4) goto LAB_18001b265;
LAB_18001b24f:
    uStack_d0 = 0x18001b261;
    uVar5 = (**(code **)(*(longlong *)param_1[1] + 0x280))((longlong *)param_1[1],0x7d4);
    pcVar6 = (char *)(ulonglong)uVar5;
    puVar12 = auStack_c8;
  }
  else {
    if (VVar2 == 8) {
      lpWideCharStr = *(LPCWSTR *)((longlong)&param_3->n1 + 8);
    }
    else {
      if (VVar2 == 10) goto LAB_18001b249;
      if (VVar2 == 0x4008) {
        lpWideCharStr = (LPCWSTR)**(undefined8 **)((longlong)&param_3->n1 + 8);
      }
      else {
        uStack_d0 = 0x18001b184;
        HVar4 = VariantChangeType(&local_80,param_3,0,8);
        if (HVar4 < 0) goto LAB_18001b24f;
        lpWideCharStr = (LPCWSTR)CONCAT44(local_80.n1._12_4_,local_80.n1._8_4_);
        uStack_d0 = 0x18001b19a;
        VariantClear(&local_80);
      }
    }
    if (lpWideCharStr == (LPCWSTR)0x0) {
LAB_18001b265:
      pcVar9 = "Dummy";
      puVar12 = auStack_c8;
    }
    else {
      lVar7 = -1;
      do {
        lVar8 = lVar7;
        lVar7 = lVar8 + 1;
      } while (lpWideCharStr[lVar7] != L'\0');
      iVar11 = (int)lVar8 + 2;
      pcVar9 = pcVar6;
      puVar12 = auStack_c8;
      if (iVar11 < 0x40000000) {
        lVar7 = (longlong)(int)lVar7 * 2;
        uVar10 = lVar7 + 0x11;
        if (uVar10 <= lVar7 + 2U) {
          uVar10 = 0xffffffffffffff0;
        }
        uStack_d0 = 0x18001b1fd;
        lVar7 = -(uVar10 & 0xfffffffffffffff0);
        pcVar1 = (char *)((longlong)&local_88 + lVar7);
        puVar12 = auStack_c8 + lVar7;
        if (pcVar1 != (char *)0x0) {
          *pcVar1 = '\0';
          *(undefined8 *)((longlong)local_98 + lVar7 + 8) = 0;
          *(undefined8 *)((longlong)local_98 + lVar7) = 0;
          *(int *)((longlong)aiStack_a0 + lVar7) = iVar11 * 2;
          *(char **)((longlong)&uStack_a8 + lVar7) = pcVar1;
          *(undefined8 *)(auStack_c8 + lVar7 + -8) = 0x18001b236;
          iVar11 = WideCharToMultiByte(0,0,lpWideCharStr,-1,*(LPSTR *)((longlong)&uStack_a8 + lVar7)
                                       ,*(int *)((longlong)aiStack_a0 + lVar7),
                                       *(LPCSTR *)((longlong)local_98 + lVar7),
                                       *(LPBOOL *)((longlong)local_98 + lVar7 + 8));
          pcVar9 = pcVar1;
          puVar12 = auStack_c8 + lVar7;
          if (iVar11 == 0) {
            pcVar9 = pcVar6;
            puVar12 = auStack_c8 + lVar7;
          }
        }
      }
    }
    *(undefined8 *)(puVar12 + -8) = 0x18001b276;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_88,pcVar9);
    iVar11 = *(int *)(local_88 + -0x10);
    *(undefined8 *)(puVar12 + -8) = 0x18001b287;
    pcVar9 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)&local_88,iVar11);
    *(undefined8 *)(puVar12 + -8) = 0x18001b294;
    Ordinal_85(uVar13,0,pcVar9);
    *(undefined8 *)(puVar12 + -8) = 0x18001b2a3;
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_88,-1);
  }
  *(undefined8 *)(puVar12 + -8) = 0x18001b2ae;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_88);
LAB_18001b2bc:
  *(undefined8 *)(puVar12 + -8) = 0x18001b2c8;
  return pcVar6;
}

/* ---- FUNC 0001B2F0 FUN_18001b2f0 (56 bytes) ---- */

undefined8 FUN_18001b2f0(longlong *param_1)

{
  undefined8 uVar1;
  
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018001b309. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x280))(param_1,0x7f3);
    return uVar1;
  }
  Ordinal_85(4,0,&DAT_180064414);
  return 0;
}

/* ---- FUNC 0001B330 FUN_18001b330 (711 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

ulonglong FUN_18001b330(longlong *param_1,VARIANTARG *param_2)

{
  VARTYPE VVar1;
  undefined4 *puVar2;
  uint uVar3;
  HRESULT HVar4;
  ulonglong uVar5;
  longlong lVar6;
  int iVar8;
  char *pcVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  LPCWSTR lpWideCharStr;
  undefined8 uStack_a0;
  undefined1 auStack_98 [32];
  undefined8 uStack_78;
  int aiStack_70 [2];
  undefined8 local_68 [2];
  undefined8 local_58;
  VARIANTARG local_50;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined8 local_28;
  ulonglong local_18;
  longlong lVar7;
  
  puVar10 = auStack_98;
  puVar11 = auStack_98;
  local_18 = DAT_180077818 ^ (ulonglong)&local_58;
  if (DAT_1800797f8 != 0) {
    uStack_a0 = 0x18001b375;
    uVar5 = (**(code **)(*(longlong *)param_1[1] + 0x280))((longlong *)param_1[1],0x7f3);
    goto LAB_18001b5dd;
  }
  uStack_a0 = 0x18001b384;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58);
  uStack_a0 = 0x18001b38f;
  VariantInit(&local_50);
  VVar1 = (param_2->n1).n2.vt;
  if (VVar1 == 0x400c) {
    puVar2 = *(undefined4 **)((longlong)&param_2->n1 + 8);
    local_38 = *puVar2;
    uStack_34 = puVar2[1];
    uStack_30 = puVar2[2];
    uStack_2c = puVar2[3];
    local_28 = *(undefined8 *)(puVar2 + 4);
    uStack_a0 = 0x18001b3c1;
    uVar3 = (**(code **)(*param_1 + 0x128))(param_1,&local_38);
    uVar5 = (ulonglong)uVar3;
    puVar10 = auStack_98;
  }
  else {
    puVar10 = auStack_98;
    if ((VVar1 != 0) && (puVar10 = auStack_98, VVar1 != 1)) {
      if (VVar1 == 8) {
        lpWideCharStr = *(LPCWSTR *)((longlong)&param_2->n1 + 8);
        if (lpWideCharStr == (LPCWSTR)0x0) {
LAB_18001b5a0:
          pcVar9 = (char *)0x0;
          puVar10 = puVar11;
        }
        else {
          lVar6 = -1;
          do {
            lVar6 = lVar6 + 1;
          } while (lpWideCharStr[lVar6] != L'\0');
LAB_18001b52b:
          iVar8 = (int)lVar6 + 1;
          puVar11 = auStack_98;
          if (0x3fffffff < iVar8) goto LAB_18001b5a0;
          lVar6 = (longlong)(int)lVar6 * 2;
          uVar5 = lVar6 + 0x11;
          if (uVar5 <= lVar6 + 2U) {
            uVar5 = 0xffffffffffffff0;
          }
          uStack_a0 = 0x18001b55f;
          lVar6 = -(uVar5 & 0xfffffffffffffff0);
          puVar11 = auStack_98 + lVar6;
          pcVar9 = (char *)((longlong)&local_58 + lVar6);
          if (pcVar9 == (char *)0x0) goto LAB_18001b5a0;
          *pcVar9 = '\0';
          *(undefined8 *)((longlong)local_68 + lVar6 + 8) = 0;
          *(undefined8 *)((longlong)local_68 + lVar6) = 0;
          *(int *)((longlong)aiStack_70 + lVar6) = iVar8 * 2;
          *(char **)((longlong)&uStack_78 + lVar6) = pcVar9;
          *(undefined8 *)(auStack_98 + lVar6 + -8) = 0x18001b595;
          iVar8 = WideCharToMultiByte(0,0,lpWideCharStr,-1,*(LPSTR *)((longlong)&uStack_78 + lVar6),
                                      *(int *)((longlong)aiStack_70 + lVar6),
                                      *(LPCSTR *)((longlong)local_68 + lVar6),
                                      *(LPBOOL *)((longlong)local_68 + lVar6 + 8));
          puVar10 = auStack_98 + lVar6;
          if (iVar8 == 0) {
            pcVar9 = (char *)0x0;
            puVar10 = auStack_98 + lVar6;
          }
        }
        *(undefined8 *)(puVar10 + -8) = 0x18001b5af;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58,pcVar9
                  );
      }
      else {
        puVar10 = auStack_98;
        if (VVar1 == 10) goto LAB_18001b5af;
        if (VVar1 == 0x4008) {
          lpWideCharStr = (LPCWSTR)**(longlong **)((longlong)&param_2->n1 + 8);
          puVar11 = auStack_98;
          if (lpWideCharStr != (LPCWSTR)0x0) {
            lVar6 = -1;
            do {
              lVar6 = lVar6 + 1;
            } while (lpWideCharStr[lVar6] != L'\0');
            goto LAB_18001b52b;
          }
          goto LAB_18001b5a0;
        }
        uStack_a0 = 0x18001b40f;
        HVar4 = VariantChangeType(&local_50,param_2,0,8);
        if (HVar4 < 0) {
          uStack_a0 = 0x18001b425;
          uVar3 = (**(code **)(*(longlong *)param_1[1] + 0x280))((longlong *)param_1[1],0x7d1);
          uVar5 = (ulonglong)uVar3;
          puVar10 = auStack_98;
          goto LAB_18001b5d1;
        }
        puVar10 = auStack_98;
        if (local_50.n1.decVal.u2.Lo64 == 0) {
LAB_18001b4c0:
          pcVar9 = (char *)0x0;
        }
        else {
          lVar6 = -1;
          do {
            lVar7 = lVar6;
            lVar6 = lVar7 + 1;
          } while (*(LPCWSTR)((longlong)local_50.n1.decVal.u2 + lVar6 * 2) != L'\0');
          iVar8 = (int)lVar7 + 2;
          puVar10 = auStack_98;
          if (0x3fffffff < iVar8) goto LAB_18001b4c0;
          lVar6 = (longlong)(int)lVar6 * 2;
          uVar5 = lVar6 + 0x11;
          if (uVar5 <= lVar6 + 2U) {
            uVar5 = 0xffffffffffffff0;
          }
          uStack_a0 = 0x18001b47f;
          lVar6 = -(uVar5 & 0xfffffffffffffff0);
          puVar10 = auStack_98 + lVar6;
          pcVar9 = (char *)((longlong)&local_58 + lVar6);
          if (pcVar9 == (char *)0x0) goto LAB_18001b4c0;
          *pcVar9 = '\0';
          *(undefined8 *)((longlong)local_68 + lVar6 + 8) = 0;
          *(undefined8 *)((longlong)local_68 + lVar6) = 0;
          *(int *)((longlong)aiStack_70 + lVar6) = iVar8 * 2;
          *(char **)((longlong)&uStack_78 + lVar6) = pcVar9;
          *(undefined8 *)(auStack_98 + lVar6 + -8) = 0x18001b4b5;
          iVar8 = WideCharToMultiByte(0,0,(LPCWSTR)local_50.n1.decVal.u2,-1,
                                      *(LPSTR *)((longlong)&uStack_78 + lVar6),
                                      *(int *)((longlong)aiStack_70 + lVar6),
                                      *(LPCSTR *)((longlong)local_68 + lVar6),
                                      *(LPBOOL *)((longlong)local_68 + lVar6 + 8));
          puVar10 = auStack_98 + lVar6;
          if (iVar8 == 0) {
            pcVar9 = (char *)0x0;
            puVar10 = auStack_98 + lVar6;
          }
        }
        *(undefined8 *)(puVar10 + -8) = 0x18001b4cf;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58,pcVar9
                  );
        *(undefined8 *)(puVar10 + -8) = 0x18001b4d9;
        VariantClear(&local_50);
      }
    }
LAB_18001b5af:
    *(undefined8 *)(puVar10 + -8) = 0x18001b5b9;
    Ordinal_99(1);
    *(undefined8 *)(puVar10 + -8) = 0x18001b5c7;
    uVar3 = Ordinal_40(0x27,local_58);
    uVar5 = (ulonglong)uVar3;
    *(undefined8 *)(puVar10 + -8) = 0x18001b5d0;
    Ordinal_99(0);
  }
LAB_18001b5d1:
  *(undefined8 *)(puVar10 + -8) = 0x18001b5db;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58);
LAB_18001b5dd:
  *(undefined8 *)(puVar10 + -8) = 0x18001b5e9;
  return uVar5;
}

/* ---- FUNC 0001B600 FUN_18001b600 (83 bytes) ---- */

undefined4 FUN_18001b600(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  
  plVar1 = param_1 + 3;
  *(int *)plVar1 = (int)*plVar1 + -1;
  lVar2 = param_1[3];
  if ((int)*plVar1 == 0) {
    (**(code **)(*DAT_180079320 + 8))();
    if (param_1 != (longlong *)0x0) {
      (**(code **)(*param_1 + 0x28))(param_1,1);
    }
    (**(code **)(*DAT_180079320 + 0x10))();
  }
  return (int)lVar2;
}

/* ---- FUNC 0001B654 FUN_18001b654 (9 bytes) ---- */

void FUN_18001b654(longlong param_1)

{
  FUN_18001b600((longlong *)(param_1 + -0x10));
  return;
}

/* ---- FUNC 0001B660 FUN_18001b660 (9 bytes) ---- */

void FUN_18001b660(longlong param_1)

{
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  return;
}

/* ---- FUNC 0001B670 FUN_18001b670 (66 bytes) ---- */

int FUN_18001b670(undefined8 *param_1)

{
  code *pcVar1;
  int iVar2;
  
  pcVar1 = (code *)param_1[5];
  iVar2 = *(int *)(param_1 + 2) + -1;
  *(int *)(param_1 + 2) = iVar2;
  if (iVar2 == 0) {
    FUN_18000b0b0(param_1);
    FUN_180025ad0(param_1);
    if (pcVar1 != (code *)0x0) {
      (*pcVar1)();
    }
    iVar2 = 0;
  }
  return iVar2;
}

/* ---- FUNC 0001B6C0 FUN_18001b6c0 (46 bytes) ---- */

int FUN_18001b6c0(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 1) + -1;
  *(int *)(param_1 + 1) = iVar1;
  if (iVar1 == 0) {
    FUN_18000b260(param_1);
    FUN_180025ad0(param_1);
    iVar1 = 0;
  }
  return iVar1;
}

/* ---- FUNC 0001B6F0 FUN_18001b6f0 (196 bytes) ---- */

undefined4 FUN_18001b6f0(longlong param_1,ulonglong param_2,undefined8 param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined4 uVar4;
  longlong *local_18 [2];
  
  uVar4 = 0;
  if ((param_2 & 1) != 0) {
    piVar1 = (int *)(param_1 + 8);
    *piVar1 = *piVar1 + -1;
    uVar4 = *(undefined4 *)(param_1 + 8);
    if (*piVar1 == 0) {
      puVar3 = (undefined8 *)GetGlobalPointer("HappNode");
      local_18[0] = (longlong *)0x0;
      if ((puVar3 != (undefined8 *)0x0) &&
         (iVar2 = (**(code **)*puVar3)(puVar3,&DAT_1800638d8,local_18), iVar2 < 0)) {
        local_18[0] = (longlong *)0x0;
      }
      if (local_18[0] != (longlong *)0x0) {
        (**(code **)(*local_18[0] + 0x20))(local_18[0],1,0,param_4 != 0);
      }
      if (local_18[0] != (longlong *)0x0) {
        (**(code **)(*local_18[0] + 0x10))();
      }
      if (param_4 != 0) {
        CoDisconnectObject((LPUNKNOWN)(param_1 + 0x10),0);
      }
    }
  }
  return uVar4;
}

/* ---- FUNC 0001B7C0 FUN_18001b7c0 (45 bytes) ---- */

undefined4 FUN_18001b7c0(undefined8 param_1,short param_2)

{
  bool bVar1;
  undefined4 uVar2;
  
  bVar1 = CApwnLibraries::RemoveLibrary(*(CApwnLibraries **)g_pApwnLibs_exref,param_2,1);
  uVar2 = 0x80004005;
  if (bVar1) {
    uVar2 = 0;
  }
  return uVar2;
}

/* ---- FUNC 0001B7F0 FUN_18001b7f0 (33 bytes) ---- */

void FUN_18001b7f0(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  int iVar4;
  ulonglong uVar5;
  longlong lVar6;
  
  lVar6 = *(longlong *)(param_1 + 0x228);
  uVar3 = 0;
  uVar5 = uVar3;
  if (0 < lVar6) {
    do {
      iVar4 = (int)uVar5;
      if (((longlong)uVar3 < 0) || (lVar6 <= (longlong)uVar3)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x220) + uVar3 * 8);
      uVar2 = FUN_180027200((longlong)plVar1,param_2);
      if ((int)uVar2 != 0) {
        FUN_18002f6d0((longlong)plVar1,0);
        (**(code **)(*plVar1 + 0x10))(plVar1);
        CPtrArray::RemoveAt((CPtrArray *)(param_1 + 0x218),(longlong)iVar4,1);
        iVar4 = iVar4 + -1;
        uVar3 = uVar3 - 1;
      }
      lVar6 = *(longlong *)(param_1 + 0x228);
      uVar3 = uVar3 + 1;
      uVar5 = (ulonglong)(iVar4 + 1U);
    } while ((int)(iVar4 + 1U) < lVar6);
  }
  return;
}

/* ---- FUNC 0001B811 FUN_18001b811 (133 bytes) ---- */

void FUN_18001b811(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  longlong *plVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  longlong unaff_RBP;
  uint unaff_EDI;
  longlong unaff_R14;
  
  uVar3 = (ulonglong)unaff_EDI;
  do {
    if (((longlong)uVar3 < 0) || (param_3 <= (longlong)uVar3)) {
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
    plVar1 = *(longlong **)(*(longlong *)(unaff_RBP + 0x220) + uVar3 * 8);
    uVar2 = FUN_180027200((longlong)plVar1,unaff_R14);
    if ((int)uVar2 != 0) {
      FUN_18002f6d0((longlong)plVar1,0);
      (**(code **)(*plVar1 + 0x10))(plVar1);
      CPtrArray::RemoveAt((CPtrArray *)(unaff_RBP + 0x218),(longlong)(int)unaff_EDI,1);
      unaff_EDI = unaff_EDI - 1;
      uVar3 = uVar3 - 1;
    }
    param_3 = *(longlong *)(unaff_RBP + 0x228);
    unaff_EDI = unaff_EDI + 1;
    uVar3 = uVar3 + 1;
  } while ((int)unaff_EDI < param_3);
  return;
}

/* ---- FUNC 0001B896 FUN_18001b896 (9 bytes) ---- */

void FUN_18001b896(void)

{
  return;
}

/* ---- FUNC 0001B89F AfxThrowInvalidArgException (5 bytes) ---- */

void __cdecl AfxThrowInvalidArgException(void)

{
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 0001B8B0 FUN_18001b8b0 (10 bytes) ---- */

undefined8 FUN_18001b8b0(longlong param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  return 0;
}

/* ---- FUNC 0001B8C0 FUN_18001b8c0 (6 bytes) ---- */

undefined8 FUN_18001b8c0(void)

{
  return 0x80004005;
}

/* ---- FUNC 0001B8D0 FUN_18001b8d0 (275 bytes) ---- */

undefined8 FUN_18001b8d0(longlong *param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong *local_res8;
  longlong *local_res20;
  longlong *local_28 [2];
  
  lVar3 = 0;
  if ((int)param_1[3] == 0) {
    uVar2 = (**(code **)(*param_1 + 0x280))(param_1,0x7d2);
    return uVar2;
  }
  (**(code **)(*param_1 + 0x90))(param_1,local_28);
  if (local_28[0] == (longlong *)0x0) {
    return 0x80004005;
  }
  local_res20 = (longlong *)0x0;
  iVar1 = (**(code **)*local_28[0])(local_28[0],&DAT_180063650,&local_res20);
  if ((-1 < iVar1) && (local_res20 != (longlong *)0x0)) {
    local_res8 = (longlong *)0x0;
    iVar1 = (**(code **)(*local_res20 + 0x28))(local_res20,param_3,&local_res8);
    if ((-1 < iVar1) && (local_res8 != (longlong *)0x0)) {
      lVar3 = HAReadArchiveByName3(param_2,param_3,local_res8,1);
      (**(code **)(*local_res8 + 0x10))();
    }
    (**(code **)(*local_res20 + 0x10))();
  }
  (**(code **)(*local_28[0] + 0x10))();
  if (lVar3 != 0) {
    uVar2 = (**(code **)(*param_1 + 0x278))(param_1,lVar3);
    return uVar2;
  }
  *(undefined4 *)(param_1 + 0x20) = 1;
  return 0;
}

/* ---- FUNC 0001B9F0 FUN_18001b9f0 (172 bytes) ---- */

undefined8 FUN_18001b9f0(longlong *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  longlong *local_res8;
  
  if ((int)param_1[3] == 0) {
    uVar1 = (**(code **)(*param_1 + 0x280))(param_1,0x7d2);
    return uVar1;
  }
  (**(code **)(*param_1 + 0x90))(param_1,&local_res8);
  if (local_res8 == (longlong *)0x0) {
    return 0x80004005;
  }
  lVar2 = HAReadArchiveByName2(param_2,param_1[4],local_res8,1);
  (**(code **)(*local_res8 + 0x10))();
  if (lVar2 != 0) {
    uVar1 = (**(code **)(*param_1 + 0x278))(param_1,lVar2);
    return uVar1;
  }
  *(undefined4 *)(param_1 + 0x20) = 1;
  return 0;
}

/* ---- FUNC 0001BAA0 FUN_18001baa0 (166 bytes) ---- */

undefined8 FUN_18001baa0(longlong *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  longlong *local_res8;
  
  if ((int)param_1[3] == 0) {
    uVar1 = (**(code **)(*param_1 + 0x280))(param_1,0x7d2);
    return uVar1;
  }
  (**(code **)(*param_1 + 0x90))(param_1,&local_res8);
  if (local_res8 == (longlong *)0x0) {
    return 0x80004005;
  }
  lVar2 = HAReadArchiveByName(param_2,param_1[4]);
  (**(code **)(*local_res8 + 0x10))();
  if (lVar2 != 0) {
    uVar1 = (**(code **)(*param_1 + 0x278))(param_1,lVar2);
    return uVar1;
  }
  *(undefined4 *)(param_1 + 0x20) = 1;
  return 0;
}

/* ---- FUNC 0001BB50 FUN_18001bb50 (46 bytes) ---- */

void FUN_18001bb50(longlong param_1,undefined4 *param_2)

{
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined8 local_18;
  
  local_28 = *param_2;
  uStack_24 = param_2[1];
  uStack_20 = param_2[2];
  uStack_1c = param_2[3];
  local_18 = *(undefined8 *)(param_2 + 4);
  (**(code **)(**(longlong **)(param_1 + 8) + 0x1a0))(*(longlong **)(param_1 + 8),&local_28);
  return;
}

/* ---- FUNC 0001BB80 FUN_18001bb80 (86 bytes) ---- */

ulonglong FUN_18001bb80(longlong *param_1,VARIANTARG *param_2)

{
  ushort uVar1;
  undefined4 *puVar2;
  uint uVar3;
  BOOL BVar4;
  int iVar5;
  HRESULT HVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  undefined4 uVar9;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res18 [16];
  VARIANTARG local_58;
  tagMSG local_38;
  
  if (DAT_1800797f8 != 0) {
    uVar7 = (**(code **)(*param_1 + 0x280))(param_1,0x7f3);
    return uVar7;
  }
  if (((int)param_1[0x1a] != 0) || (param_1[4] == 0)) {
    return 0x80004005;
  }
  uVar1 = (param_2->n1).n2.vt;
  if (uVar1 < 0xc) {
    if (uVar1 == 0xb) {
LAB_18001bcbf:
      uVar9 = SEXT24(*(short *)((longlong)&param_2->n1 + 8));
      goto LAB_18001bd52;
    }
    if (uVar1 != 0) {
      if (uVar1 == 2) goto LAB_18001bcbf;
      if (uVar1 == 3) {
        uVar9 = *(int *)((longlong)&param_2->n1 + 8);
        goto LAB_18001bd52;
      }
      if (uVar1 != 10) goto LAB_18001bcdf;
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18,"");
    FUN_1800374c0(0x7b,(longlong *)local_res18);
    puVar8 = (undefined8 *)(*param_1 + 0x270);
  }
  else {
    if (uVar1 == 0x4002) {
LAB_18001bd4b:
      uVar9 = SEXT24(**(short **)((longlong)&param_2->n1 + 8));
    }
    else if (uVar1 == 0x4003) {
      uVar9 = **(int **)((longlong)&param_2->n1 + 8);
    }
    else {
      if (uVar1 == 0x400b) goto LAB_18001bd4b;
      if (uVar1 == 0x400c) {
        puVar2 = *(undefined4 **)((longlong)&param_2->n1 + 8);
        local_38.hwnd._0_4_ = *puVar2;
        local_38.hwnd._4_4_ = puVar2[1];
        local_38.message = puVar2[2];
        local_38._12_4_ = puVar2[3];
        local_38.wParam = *(WPARAM *)(puVar2 + 4);
        uVar7 = (**(code **)(*param_1 + 0x1a0))(param_1,&local_38);
        return uVar7;
      }
LAB_18001bcdf:
      VariantInit(&local_58);
      HVar6 = VariantChangeType(&local_58,param_2,0,3);
      uVar9 = 0;
      if (HVar6 == 0) {
        VariantClear(&local_58);
        uVar9 = local_58.n1._8_4_;
      }
    }
LAB_18001bd52:
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18,"");
    FUN_1800374c0(0x7b,(longlong *)local_res18);
    puVar8 = (undefined8 *)(*param_1 + 0x270);
    if (uVar9 != 0) {
      uVar3 = (*(code *)*puVar8)(param_1,1);
      goto LAB_18001bc8e;
    }
  }
  uVar3 = (*(code *)*puVar8)(param_1);
  do {
    BVar4 = PeekMessageA(&local_38,(HWND)0x0,0,0,1);
    if (BVar4 != 0) {
      DispatchMessageA(&local_38);
    }
    iVar5 = Ordinal_151(0);
  } while ((iVar5 != 0) || (iVar5 = Ordinal_178(), iVar5 == 0));
LAB_18001bc8e:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
  return (ulonglong)uVar3;
}

/* ---- FUNC 0001BBD6 FUN_18001bbd6 (225 bytes) ---- */

ulonglong FUN_18001bbd6(uint param_1,longlong param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  BOOL BVar3;
  int iVar4;
  HRESULT HVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  VARIANTARG *unaff_RBX;
  longlong *unaff_RSI;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 in_stack_00000038;
  undefined4 in_stack_00000050;
  undefined4 uStack0000000000000054;
  UINT in_stack_00000058;
  undefined4 uStack000000000000005c;
  WPARAM in_stack_00000060;
  
  if (param_1 < 0xc) {
    if (param_1 == 0xb) {
LAB_18001bcbf:
      uVar8 = SEXT24(*(short *)(param_2 + 8));
      goto LAB_18001bd52;
    }
    if (param_1 != 0) {
      if (param_1 == 2) goto LAB_18001bcbf;
      if (param_1 == 3) {
        uVar8 = *(int *)(param_2 + 8);
        goto LAB_18001bd52;
      }
      if (param_1 != 10) goto LAB_18001bcdf;
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x000000a0,"")
    ;
    FUN_1800374c0(0x7b,(longlong *)&stack0x000000a0);
    puVar6 = (undefined8 *)(*unaff_RSI + 0x270);
  }
  else {
    if (param_1 == 0x4002) {
LAB_18001bd4b:
      uVar8 = SEXT24(**(short **)(param_2 + 8));
    }
    else if (param_1 == 0x4003) {
      uVar8 = **(int **)(param_2 + 8);
    }
    else {
      if (param_1 == 0x400b) goto LAB_18001bd4b;
      if (param_1 == 0x400c) {
        puVar1 = *(undefined4 **)(param_2 + 8);
        in_stack_00000050 = *puVar1;
        uStack0000000000000054 = puVar1[1];
        in_stack_00000058 = puVar1[2];
        uStack000000000000005c = puVar1[3];
        in_stack_00000060 = *(WPARAM *)(puVar1 + 4);
        uVar7 = (**(code **)(*unaff_RSI + 0x1a0))(in_stack_00000050,&stack0x00000050);
        return uVar7;
      }
LAB_18001bcdf:
      VariantInit((VARIANTARG *)&stack0x00000030);
      HVar5 = VariantChangeType((VARIANTARG *)&stack0x00000030,unaff_RBX,0,3);
      uVar9 = in_stack_00000038;
      uVar8 = 0;
      if (HVar5 == 0) {
        VariantClear((VARIANTARG *)&stack0x00000030);
        uVar8 = uVar9;
      }
    }
LAB_18001bd52:
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x000000a0,"")
    ;
    uVar9 = FUN_1800374c0(0x7b,(longlong *)&stack0x000000a0);
    puVar6 = (undefined8 *)(*unaff_RSI + 0x270);
    if (uVar8 != 0) {
      uVar2 = (*(code *)*puVar6)(uVar9,1);
      goto LAB_18001bc8e;
    }
  }
  uVar2 = (*(code *)*puVar6)();
  do {
    BVar3 = PeekMessageA((LPMSG)&stack0x00000050,(HWND)0x0,0,0,1);
    if (BVar3 != 0) {
      DispatchMessageA((MSG *)&stack0x00000050);
    }
    iVar4 = Ordinal_151(0);
  } while ((iVar4 != 0) || (iVar4 = Ordinal_178(), iVar4 == 0));
LAB_18001bc8e:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x000000a0);
  return (ulonglong)uVar2;
}

/* ---- FUNC 0001BCB7 FUN_18001bcb7 (230 bytes) ---- */

undefined4 FUN_18001bcb7(undefined8 param_1,longlong param_2)

{
  BOOL BVar1;
  int iVar2;
  undefined4 uVar3;
  longlong *unaff_RSI;
  
  iVar2 = *(int *)(param_2 + 8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x000000a0,"");
  FUN_1800374c0(0x7b,(longlong *)&stack0x000000a0);
  if (iVar2 == 0) {
    uVar3 = (**(code **)(*unaff_RSI + 0x270))();
    do {
      do {
        BVar1 = PeekMessageA((LPMSG)&stack0x00000050,(HWND)0x0,0,0,1);
        if (BVar1 != 0) {
          DispatchMessageA((MSG *)&stack0x00000050);
        }
        iVar2 = Ordinal_151(0);
      } while (iVar2 != 0);
      iVar2 = Ordinal_178();
    } while (iVar2 == 0);
  }
  else {
    uVar3 = (**(code **)(*unaff_RSI + 0x270))();
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x000000a0);
  return uVar3;
}

/* ---- FUNC 0001BD9D FUN_18001bd9d (22 bytes) ---- */

undefined8 FUN_18001bd9d(void)

{
  return 0x80004005;
}

/* ---- FUNC 0001BDC0 FUN_18001bdc0 (66 bytes) ---- */

void FUN_18001bdc0(longlong param_1)

{
  _union_2707 local_48;
  undefined4 local_28;
  ULONG UStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined8 local_18;
  
  VariantInit((VARIANTARG *)&local_48.n2);
  local_28 = local_48._0_4_;
  UStack_24 = local_48.decVal.Hi32;
  uStack_20 = local_48._8_4_;
  uStack_1c = local_48._12_4_;
  local_18 = local_48._16_8_;
  (**(code **)(**(longlong **)(param_1 + 8) + 0x1a0))(*(longlong **)(param_1 + 8),&local_28);
  return;
}

/* ---- FUNC 0001BE10 FUN_18001be10 (63 bytes) ---- */

void FUN_18001be10(longlong param_1,undefined4 param_2,undefined8 param_3)

{
  switch(param_2) {
  case 1:
  case 2:
  case 3:
  case 5:
  case 8:
  case 9:
  case 0xb:
  case 0x11:
  case 0x14:
    *(undefined4 *)(param_1 + 0x100) = 1;
  }
  Ordinal_40(param_2,param_3);
  return;
}

/* ---- FUNC 0001BE70 FUN_18001be70 (65 bytes) ---- */

void FUN_18001be70(longlong *param_1)

{
  _union_2707 local_48;
  undefined4 local_28;
  ULONG UStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined8 local_18;
  
  VariantInit((VARIANTARG *)&local_48.n2);
  local_28 = local_48._0_4_;
  UStack_24 = local_48.decVal.Hi32;
  uStack_20 = local_48._8_4_;
  uStack_1c = local_48._12_4_;
  local_18 = local_48._16_8_;
  (**(code **)(*param_1 + 0x1a0))(param_1,&local_28);
  return;
}

/* ---- FUNC 0001BEC0 FUN_18001bec0 (50 bytes) ---- */

undefined8 FUN_18001bec0(longlong param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return 0x80070057;
  }
  iVar1 = GRinqautorun();
  if (iVar1 == 0) {
    return 0x80004005;
  }
  AutoRunEngSim();
  return 0;
}

/* ---- FUNC 0001BF00 FUN_18001bf00 (251 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18001bf00(undefined8 param_1,LPCWSTR param_2)

{
  longlong lVar1;
  ulonglong uVar3;
  char *pcVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined8 uStack_60;
  undefined1 auStack_58 [32];
  undefined8 uStack_38;
  int aiStack_30 [2];
  undefined8 local_28 [2];
  undefined8 local_18;
  ulonglong local_10;
  longlong lVar2;
  
  local_10 = DAT_180077818 ^ (ulonglong)&local_18;
  puVar5 = auStack_58;
  if (param_2 != (LPCWSTR)0x0) {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_2[lVar1] != L'\0');
    iVar6 = (int)lVar2 + 2;
    puVar5 = auStack_58;
    if (iVar6 < 0x40000000) {
      lVar1 = (longlong)(int)lVar1 * 2;
      uVar3 = lVar1 + 0x11;
      if (uVar3 <= lVar1 + 2U) {
        uVar3 = 0xffffffffffffff0;
      }
      uStack_60 = 0x18001bf71;
      lVar1 = -(uVar3 & 0xfffffffffffffff0);
      puVar5 = auStack_58 + lVar1;
      pcVar4 = (char *)((longlong)&local_18 + lVar1);
      if (pcVar4 != (char *)0x0) {
        *pcVar4 = '\0';
        *(undefined8 *)((longlong)local_28 + lVar1 + 8) = 0;
        *(undefined8 *)((longlong)local_28 + lVar1) = 0;
        *(int *)((longlong)aiStack_30 + lVar1) = iVar6 * 2;
        *(char **)((longlong)&uStack_38 + lVar1) = pcVar4;
        *(undefined8 *)(auStack_58 + lVar1 + -8) = 0x18001bfab;
        iVar6 = WideCharToMultiByte(0,0,param_2,-1,*(LPSTR *)((longlong)&uStack_38 + lVar1),
                                    *(int *)((longlong)aiStack_30 + lVar1),
                                    *(LPCSTR *)((longlong)local_28 + lVar1),
                                    *(LPBOOL *)((longlong)local_28 + lVar1 + 8));
        puVar5 = auStack_58 + lVar1;
        if (iVar6 == 0) {
          pcVar4 = (char *)0x0;
          puVar5 = auStack_58 + lVar1;
        }
        goto LAB_18001bfb8;
      }
    }
  }
  pcVar4 = (char *)0x0;
LAB_18001bfb8:
  *(undefined8 *)(puVar5 + -8) = 0x18001bfc5;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_18,pcVar4);
  *(undefined8 *)(puVar5 + -8) = 0x18001bfd5;
  PostMainWndMessage(0x4f3,0,local_18);
  *(undefined8 *)(puVar5 + -8) = 0x18001bfdf;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_18);
  *(undefined8 *)(puVar5 + -8) = 0x18001bfed;
  return 0;
}

/* ---- FUNC 0001C000 FUN_18001c000 (38 bytes) ---- */

void FUN_18001c000(longlong param_1)

{
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018001c015. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(longlong **)(param_1 + 8) + 0x280))(*(longlong **)(param_1 + 8),0x7f3);
    return;
  }
  Ordinal_40(0x14);
  return;
}

/* ---- FUNC 0001C030 FUN_18001c030 (26 bytes) ---- */

ulonglong FUN_18001c030(longlong *param_1)

{
  uint uVar1;
  ulonglong uVar2;
  
  if ((int)param_1[0x13] == 0) {
    (**(code **)(*param_1 + 0x228))(param_1,0xffffffff);
    uVar1 = (**(code **)(*param_1 + 0x98))(param_1);
    (**(code **)(*param_1 + 0x228))(param_1,0);
    return (ulonglong)uVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x00018001c084. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(*param_1 + 0x98))();
  return uVar2;
}

/* ---- FUNC 0001C04A FUN_18001c04a (53 bytes) ---- */

undefined4 FUN_18001c04a(void)

{
  undefined4 uVar1;
  longlong in_RAX;
  longlong *unaff_RDI;
  
  (**(code **)(in_RAX + 0x228))();
  uVar1 = (**(code **)(*unaff_RDI + 0x98))();
  (**(code **)(*unaff_RDI + 0x228))();
  return uVar1;
}

/* ---- FUNC 0001C07F FUN_18001c07f (12 bytes) ---- */

void FUN_18001c07f(void)

{
  longlong in_RAX;
  
                    /* WARNING: Could not recover jumptable at 0x00018001c084. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(in_RAX + 0x98))();
  return;
}

/* ---- FUNC 0001C090 FUN_18001c090 (74 bytes) ---- */

undefined8 FUN_18001c090(longlong *param_1)

{
  uint uVar1;
  undefined8 uVar2;
  undefined4 local_res10 [6];
  
  if (DAT_1800797f8 != 0) {
    uVar2 = (**(code **)(*param_1 + 0x280))(param_1,0x7f3);
    return uVar2;
  }
  if ((int)param_1[3] == 0) {
    uVar2 = (**(code **)(*param_1 + 0x280))(param_1,0x7d2);
    return uVar2;
  }
  if (param_1[4] != 0) {
    local_res10[0] = 1;
    SetGlobalPointer("InSave",local_res10,0);
    uVar1 = FUN_180037540(0);
    SetGlobalPointer("InSave",local_res10,0);
    if (uVar1 != 0) {
      *(undefined4 *)(param_1 + 0x20) = 0;
      return 0;
    }
  }
  return 0x80004005;
}

/* ---- FUNC 0001C0DA FUN_18001c0da (97 bytes) ---- */

undefined8 FUN_18001c0da(void)

{
  uint uVar1;
  longlong unaff_RDI;
  undefined4 uStack0000000000000038;
  
  uStack0000000000000038 = 1;
  SetGlobalPointer("InSave",&stack0x00000038);
  uVar1 = FUN_180037540(0);
  SetGlobalPointer("InSave",&stack0x00000038,0);
  if (uVar1 != 0) {
    *(undefined4 *)(unaff_RDI + 0x100) = 0;
    return 0;
  }
  return 0x80004005;
}

/* ---- FUNC 0001C11E FUN_18001c11e (18 bytes) ---- */

undefined8 FUN_18001c11e(void)

{
  longlong unaff_RDI;
  
  *(undefined4 *)(unaff_RDI + 0x100) = 0;
  return 0;
}

/* ---- FUNC 0001C140 FUN_18001c140 (134 bytes) ---- */

ulonglong FUN_18001c140(longlong *param_1,undefined8 param_2,undefined4 *param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined8 local_18;
  
  lVar1 = param_1[0x13];
  if ((int)lVar1 == 0) {
    (**(code **)(*param_1 + 0x228))(param_1,0xffffffff);
  }
  local_28 = *param_3;
  uStack_24 = param_3[1];
  uStack_20 = param_3[2];
  uStack_1c = param_3[3];
  local_18 = *(undefined8 *)(param_3 + 4);
  uVar2 = (**(code **)(*param_1 + 0xa0))(param_1,param_2,&local_28);
  if ((int)lVar1 == 0) {
    (**(code **)(*param_1 + 0x228))(param_1,0);
    uVar2 = uVar2 & 0xffffffff;
  }
  return uVar2;
}

/* ---- FUNC 0001C1D0 FUN_18001c1d0 (717 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

char * FUN_18001c1d0(longlong *param_1,undefined8 *param_2,VARIANTARG *param_3)

{
  char *pcVar1;
  VARTYPE VVar2;
  LPCWSTR pWVar3;
  code *pcVar4;
  uint uVar5;
  char *pcVar6;
  longlong lVar7;
  FILE *_File;
  ulonglong uVar9;
  int iVar10;
  char *pcVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined8 uStack_90;
  undefined1 auStack_88 [32];
  undefined8 uStack_68;
  int aiStack_60 [2];
  undefined8 local_58 [2];
  char local_48 [4];
  undefined4 uStack_44;
  undefined8 local_40;
  VARIANTARG local_38;
  ulonglong local_20;
  longlong lVar8;
  
  local_20 = DAT_180077818 ^ (ulonglong)local_48;
  if (DAT_1800797f8 == 0) {
    uStack_90 = 0x18001c228;
    VariantInit(&local_38);
    if ((int)param_1[3] == 0) {
      uStack_90 = 0x18001c23f;
      pcVar6 = (char *)(**(code **)(*param_1 + 0x280))(param_1,0x7d2);
      puVar13 = auStack_88;
    }
    else {
      VVar2 = (param_3->n1).n2.vt;
      pcVar6 = (char *)0x0;
      puVar12 = auStack_88;
      if ((VVar2 != 0) && (puVar12 = auStack_88, VVar2 != 10)) {
        if (VVar2 == 0xb) {
          local_38.n1._8_2_ = *(short *)((longlong)&param_3->n1 + 8);
        }
        else if (VVar2 == 0x400b) {
          local_38.n1._8_2_ = **(short **)((longlong)&param_3->n1 + 8);
        }
        else {
          uStack_90 = 0x18001c285;
          uVar5 = VariantChangeType(&local_38,param_3,0,0xb);
          if (uVar5 != 0) {
            uStack_90 = 0x18001c295;
            VariantClear(&local_38);
            pcVar6 = (char *)(ulonglong)uVar5;
            puVar13 = auStack_88;
            goto LAB_18001c47b;
          }
        }
        puVar12 = auStack_88;
        if (local_38.n1._8_2_ == 0) {
          pWVar3 = (LPCWSTR)*param_2;
          pcVar11 = pcVar6;
          puVar12 = auStack_88;
          if (pWVar3 != (LPCWSTR)0x0) {
            lVar7 = -1;
            do {
              lVar8 = lVar7;
              lVar7 = lVar8 + 1;
            } while (pWVar3[lVar7] != L'\0');
            iVar10 = (int)lVar8 + 2;
            puVar12 = auStack_88;
            if (iVar10 < 0x40000000) {
              lVar7 = (longlong)(int)lVar7 * 2;
              uVar9 = lVar7 + 0x11;
              if (uVar9 <= lVar7 + 2U) {
                uVar9 = 0xffffffffffffff0;
              }
              uStack_90 = 0x18001c2fd;
              lVar7 = -(uVar9 & 0xfffffffffffffff0);
              pcVar1 = local_48 + lVar7;
              puVar12 = auStack_88 + lVar7;
              if (pcVar1 != (char *)0x0) {
                *(undefined8 *)((longlong)local_58 + lVar7 + 8) = 0;
                *(undefined8 *)((longlong)local_58 + lVar7) = 0;
                *(int *)((longlong)aiStack_60 + lVar7) = iVar10 * 2;
                *pcVar1 = '\0';
                *(char **)((longlong)&uStack_68 + lVar7) = pcVar1;
                *(undefined8 *)(auStack_88 + lVar7 + -8) = 0x18001c331;
                iVar10 = WideCharToMultiByte(0,0,pWVar3,-1,*(LPSTR *)((longlong)&uStack_68 + lVar7),
                                             *(int *)((longlong)aiStack_60 + lVar7),
                                             *(LPCSTR *)((longlong)local_58 + lVar7),
                                             *(LPBOOL *)((longlong)local_58 + lVar7 + 8));
                pcVar11 = pcVar1;
                puVar12 = auStack_88 + lVar7;
                if (iVar10 == 0) {
                  pcVar11 = pcVar6;
                  puVar12 = auStack_88 + lVar7;
                }
              }
            }
          }
          *(undefined8 *)(puVar12 + -8) = 0x18001c34c;
          _File = fopen(pcVar11,"r");
          if (_File != (FILE *)0x0) {
            *(undefined8 *)(puVar12 + -8) = 0x18001c35a;
            fclose(_File);
            pcVar4 = *(code **)(*param_1 + 0x280);
            *(undefined8 *)(puVar12 + -8) = 0x18001c36b;
            pcVar6 = (char *)(*pcVar4)(param_1,0x7e2);
            puVar13 = puVar12;
            goto LAB_18001c47b;
          }
        }
      }
      puVar13 = puVar12;
      if (param_1[4] == 0) {
        pcVar4 = *(code **)(*param_1 + 0x280);
        *(undefined8 *)(puVar12 + -8) = 0x18001c387;
        pcVar6 = (char *)(*pcVar4)(param_1,0x7d1);
      }
      else {
        pWVar3 = (LPCWSTR)*param_2;
        pcVar11 = pcVar6;
        if (pWVar3 != (LPCWSTR)0x0) {
          lVar7 = -1;
          do {
            lVar8 = lVar7;
            lVar7 = lVar8 + 1;
          } while (pWVar3[lVar7] != L'\0');
          iVar10 = (int)lVar8 + 2;
          if (iVar10 < 0x40000000) {
            lVar7 = (longlong)(int)lVar7 * 2;
            uVar9 = lVar7 + 0x11;
            if (uVar9 <= lVar7 + 2U) {
              uVar9 = 0xffffffffffffff0;
            }
            *(undefined8 *)(puVar12 + -8) = 0x18001c3d7;
            lVar7 = -(uVar9 & 0xfffffffffffffff0);
            pcVar1 = puVar12 + lVar7 + 0x40;
            puVar13 = puVar12 + lVar7;
            if (pcVar1 != (char *)0x0) {
              *(undefined8 *)(puVar12 + lVar7 + 0x38) = 0;
              *(undefined8 *)(puVar12 + lVar7 + 0x30) = 0;
              *(int *)(puVar12 + lVar7 + 0x28) = iVar10 * 2;
              *pcVar1 = '\0';
              *(char **)(puVar12 + lVar7 + 0x20) = pcVar1;
              *(undefined8 *)(puVar12 + lVar7 + -8) = 0x18001c40b;
              iVar10 = WideCharToMultiByte(0,0,pWVar3,-1,*(LPSTR *)(puVar12 + lVar7 + 0x20),
                                           *(int *)(puVar12 + lVar7 + 0x28),
                                           *(LPCSTR *)(puVar12 + lVar7 + 0x30),
                                           *(LPBOOL *)(puVar12 + lVar7 + 0x38));
              pcVar11 = pcVar1;
              puVar13 = puVar12 + lVar7;
              if (iVar10 == 0) {
                pcVar11 = pcVar6;
                puVar13 = puVar12 + lVar7;
              }
            }
          }
        }
        *(undefined8 *)(puVar13 + -8) = 0x18001c423;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_40,
                   pcVar11);
        local_48[0] = '\x01';
        local_48[1] = '\0';
        local_48[2] = '\0';
        local_48[3] = '\0';
        uStack_44 = 0;
        *(undefined8 *)(puVar13 + -8) = 0x18001c440;
        SetGlobalPointer("InSave",local_48,0);
        *(undefined8 *)(puVar13 + -8) = 0x18001c449;
        uVar5 = FUN_180037540(local_40);
        *(undefined8 *)(puVar13 + -8) = 0x18001c45e;
        SetGlobalPointer("InSave",&uStack_44,0);
        if (uVar5 == 0) {
          pcVar6 = (char *)0x80004005;
        }
        else {
          *(undefined4 *)(param_1 + 0x20) = 0;
        }
        *(undefined8 *)(puVar13 + -8) = 0x18001c479;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_40);
      }
    }
  }
  else {
    uStack_90 = 0x18001c219;
    pcVar6 = (char *)(**(code **)(*param_1 + 0x280))(param_1,0x7f3);
    puVar13 = auStack_88;
  }
LAB_18001c47b:
  *(undefined8 *)(puVar13 + -8) = 0x18001c487;
  return pcVar6;
}

/* ---- FUNC 0001C4A0 FUN_18001c4a0 (152 bytes) ---- */

undefined8 FUN_18001c4a0(longlong param_1,IStream *param_2,undefined8 param_3)

{
  ulonglong uVar1;
  uint uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  uVar1 = *(ulonglong *)(param_1 + 0x228);
  uVar4 = 0;
  uVar2 = 0;
  uVar5 = uVar4;
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar4 < 0) || ((longlong)uVar1 <= (longlong)uVar4)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      uVar2 = (uint)uVar5 + 1;
      if (*(int *)(*(longlong *)(*(longlong *)(param_1 + 0x220) + uVar4 * 8) + 8) == 1) {
        uVar2 = (uint)uVar5;
      }
      uVar4 = uVar4 + 1;
      uVar5 = (ulonglong)uVar2;
    } while (uVar4 < uVar1);
  }
  if ((longlong)(int)uVar2 + *(longlong *)(param_1 + 0x200) == 0) {
    return 1;
  }
  if ((int)param_3 != 0) {
    if ((int)param_3 != 1) {
      return 0x80070057;
    }
    uVar3 = FUN_18001c6e0(param_1,(longlong *)param_2,param_3,uVar4);
    return uVar3;
  }
  uVar3 = FUN_18001c540(param_1,param_2);
  return uVar3;
}

/* ---- FUNC 0001C540 FUN_18001c540 (407 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18001c540(longlong param_1,IStream *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined1 auStack_448 [32];
  uint local_428 [2];
  ulonglong local_420;
  undefined1 local_418 [1008];
  ulonglong local_28;
  
  local_28 = DAT_180077818 ^ (ulonglong)auStack_448;
  local_420 = *(ulonglong *)(param_1 + 0x200);
  (*param_2->lpVtbl->Write)(param_2,&local_420,8,(ULONG *)0x0);
  uVar3 = 0;
  uVar4 = uVar3;
  if (local_420 != 0) {
    do {
      if (((longlong)uVar4 < 0) || (*(longlong *)(param_1 + 0x200) <= (longlong)uVar4))
      goto LAB_18001c6d2;
      FUN_18002eb40(*(longlong *)(*(longlong *)(param_1 + 0x1f8) + uVar4 * 8),(longlong *)param_2);
      uVar4 = uVar4 + 1;
    } while (uVar4 < local_420);
  }
  uVar4 = *(ulonglong *)(param_1 + 0x228);
  local_428[0] = 0;
  uVar2 = uVar3;
  uVar5 = uVar3;
  if (uVar4 != 0) {
    do {
      if (((longlong)uVar2 < 0) || ((longlong)uVar4 <= (longlong)uVar2)) goto LAB_18001c6d2;
      if (*(int *)(*(longlong *)(*(longlong *)(param_1 + 0x220) + uVar2 * 8) + 8) != 1) {
        local_428[0] = (int)uVar5 + 1;
        uVar5 = (ulonglong)local_428[0];
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar4);
  }
  (*param_2->lpVtbl->Write)(param_2,local_428,4,(ULONG *)0x0);
  uVar4 = *(ulonglong *)(param_1 + 0x228);
  if (uVar4 != 0) {
    do {
      if (((longlong)uVar3 < 0) || (*(longlong *)(param_1 + 0x228) <= (longlong)uVar3)) {
LAB_18001c6d2:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x220) + uVar3 * 8);
      if (*(int *)(lVar1 + 8) != 1) {
        uVar2 = FUN_18002e990(lVar1,param_2);
        if (-1 < (int)uVar2) {
          local_428[0] = local_428[0] - 1;
        }
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar4);
  }
  if (local_428[0] != 0) {
    FUN_180002a20(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\happ.cpp",0x100b);
    LogMessage(local_418,2,1);
  }
  return 0;
}

/* ---- FUNC 0001C6E0 FUN_18001c6e0 (559 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18001c6e0(longlong param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined8 uVar9;
  undefined1 auStack_498 [32];
  char local_478 [8];
  char local_470 [4];
  char local_46c [68];
  undefined1 local_428 [1008];
  ulonglong local_38;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStack_498;
  uVar1 = *(ulonglong *)(param_1 + 0x200);
  uVar3 = 0;
  if (uVar1 != 0) {
    FUN_180002a20(local_478,"source = %I64u\n",uVar1,param_4);
    lVar4 = -1;
    do {
      lVar8 = lVar4 + 1;
      lVar2 = lVar4 + 1;
      lVar4 = lVar8;
    } while (local_478[lVar2] != '\0');
    param_4 = 0;
    (**(code **)(*param_2 + 0x20))(param_2,local_478);
    uVar5 = uVar3;
    do {
      if (((longlong)uVar5 < 0) || (*(longlong *)(param_1 + 0x200) <= (longlong)uVar5))
      goto LAB_18001c90a;
      FUN_18002f160(*(longlong *)(*(longlong *)(param_1 + 0x1f8) + uVar5 * 8),param_2,lVar8,param_4)
      ;
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
  }
  uVar1 = *(ulonglong *)(param_1 + 0x228);
  uVar5 = uVar3;
  uVar6 = uVar3;
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar5 < 0) || ((longlong)uVar1 <= (longlong)uVar5)) goto LAB_18001c90a;
      uVar7 = uVar6 + 1;
      if (*(int *)(*(longlong *)(*(longlong *)(param_1 + 0x220) + uVar5 * 8) + 8) == 1) {
        uVar7 = uVar6;
      }
      uVar5 = uVar5 + 1;
      uVar6 = uVar7;
    } while (uVar5 < uVar1);
    if (uVar7 != 0) {
      FUN_180002a20(local_478,"container = %I64u\n",uVar7,param_4);
      lVar4 = -1;
      do {
        lVar8 = lVar4 + 1;
        lVar2 = lVar4 + 1;
        lVar4 = lVar8;
      } while (local_478[lVar2] != '\0');
      uVar9 = 0;
      (**(code **)(*param_2 + 0x20))(param_2,local_478);
      uVar1 = *(ulonglong *)(param_1 + 0x228);
      if (uVar1 != 0) {
        do {
          if (((longlong)uVar3 < 0) || (*(longlong *)(param_1 + 0x228) <= (longlong)uVar3)) {
LAB_18001c90a:
                    /* WARNING: Subroutine does not return */
            AfxThrowInvalidArgException();
          }
          lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x220) + uVar3 * 8);
          if (*(int *)(lVar4 + 8) != 1) {
            uVar5 = FUN_18002ecf0(lVar4,param_2,lVar8,uVar9);
            if (-1 < (int)uVar5) {
              uVar7 = uVar7 - 1;
            }
          }
          uVar3 = uVar3 + 1;
        } while (uVar3 < uVar1);
      }
      if (uVar7 != 0) {
        FUN_180002a20(local_428,"Assert failed in file %s line %d",
                      "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\happ.cpp",0x10ad);
        LogMessage(local_428,2,1);
      }
    }
  }
  local_470[0] = s_end_ole_link_180064548[8];
  local_470[1] = s_end_ole_link_180064548[9];
  local_470[2] = s_end_ole_link_180064548[10];
  local_470[3] = s_end_ole_link_180064548[0xb];
  local_46c[0] = s_end_ole_link_180064548[0xc];
  local_46c[1] = s_end_ole_link_180064548[0xd];
  local_478[0] = s_end_ole_link_180064548[0];
  local_478[1] = s_end_ole_link_180064548[1];
  local_478[2] = s_end_ole_link_180064548[2];
  local_478[3] = s_end_ole_link_180064548[3];
  local_478[4] = s_end_ole_link_180064548[4];
  local_478[5] = s_end_ole_link_180064548[5];
  local_478[6] = s_end_ole_link_180064548[6];
  local_478[7] = s_end_ole_link_180064548[7];
  lVar4 = -1;
  do {
    lVar8 = lVar4 + 1;
    lVar2 = lVar4 + 1;
    lVar4 = lVar8;
  } while (local_478[lVar2] != '\0');
  (**(code **)(*param_2 + 0x20))(param_2,local_478,lVar8,0);
  return 0;
}

/* ---- FUNC 0001C910 FUN_18001c910 (29 bytes) ---- */

void FUN_18001c910(longlong *param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0x7f3;
  if (DAT_1800797f8 == 0) {
    uVar1 = 0x7d3;
  }
                    /* WARNING: Could not recover jumptable at 0x00018001c926. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x280))(param_1,uVar1);
  return;
}

/* ---- FUNC 0001C930 FUN_18001c930 (565 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_18001c930(longlong *param_1,longlong *param_2,undefined4 param_3,char *param_4,
             undefined4 param_5)

{
  code *pcVar1;
  undefined8 *puVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  LPWSTR pWVar6;
  undefined8 *puVar7;
  LPWSTR pWVar8;
  undefined1 local_88 [24];
  undefined8 uStackY_70;
  WCHAR local_58 [4];
  undefined8 uStack_50;
  WCHAR local_38 [8];
  undefined4 local_28;
  longlong *local_18;
  ulonglong local_10;
  
  puVar7 = (undefined8 *)&stack0xffffffffffffffb8;
  local_10 = DAT_180077818 ^ (ulonglong)&local_18;
  if ((param_4 != (char *)0x0) && ((LPCSTR)param_1[0x21] != (LPCSTR)0x0)) {
    uStack_50 = 0x18001c97f;
    iVar3 = lstrcmpiA(param_4,(LPCSTR)param_1[0x21]);
    if (iVar3 != 0) {
      uStack_50 = 0x18001c98e;
      FUN_18001cbb0((longlong)param_1,param_4);
    }
  }
  local_28 = param_5;
  uStack_50 = 0x18001c9a8;
  lVar4 = HASave(param_1[4],param_2,param_3,param_4);
  if (lVar4 == 0) {
    pWVar8 = (LPWSTR)0x0;
    local_18 = (longlong *)0x0;
    pWVar6 = pWVar8;
    if (local_38 != (LPWSTR)0x0) {
      local_38[0] = L'\0';
      uStackY_70 = 0x18001ca02;
      iVar3 = MultiByteToWideChar(0,0,"OLELINKS",-1,local_38,9);
      pWVar6 = local_38;
      if (iVar3 == 0) {
        pWVar6 = pWVar8;
      }
    }
    uStackY_70 = 0x18001ca30;
    iVar3 = (**(code **)(*param_2 + 0x20))(param_2,pWVar6,0,0x12);
    puVar2 = (undefined8 *)&stack0xffffffffffffff98;
    if (iVar3 < 0) {
      puVar7 = (undefined8 *)local_88;
      pWVar6 = pWVar8;
      if (local_58 != (LPWSTR)0x0) {
        local_58[0] = L'\0';
        iVar3 = MultiByteToWideChar(0,0,"OLELINKS",-1,local_58,9);
        pWVar6 = local_58;
        if (iVar3 == 0) {
          pWVar6 = pWVar8;
        }
      }
      iVar3 = (**(code **)(*param_2 + 0x18))(param_2,pWVar6,0x12);
      puVar2 = (undefined8 *)local_88;
      if (iVar3 < 0) {
        uVar5 = (**(code **)(*param_1 + 0x280))(param_1,0x7d1);
        goto LAB_18001cb43;
      }
    }
    puVar7 = puVar2;
    pcVar1 = *(code **)(*param_1 + 0x118);
    puVar7[-1] = 0x18001cacd;
    iVar3 = (*pcVar1)(param_1,local_18,0);
    if (iVar3 == 0) {
      pcVar1 = *(code **)(*local_18 + 0x10);
      puVar7[-1] = 0x18001cb41;
      (*pcVar1)();
    }
    else {
      pcVar1 = *(code **)(*local_18 + 0x10);
      puVar7[-1] = 0x18001cadb;
      (*pcVar1)();
      pWVar6 = (LPWSTR)(puVar7 + 2);
      if (pWVar6 == (LPWSTR)0x0) {
        pcVar1 = *(code **)(*param_2 + 0x60);
        puVar7[-5] = 0x18001cb39;
        (*pcVar1)(param_2,0);
        puVar7 = puVar7 + -4;
      }
      else {
        *(undefined4 *)(puVar7 + 1) = 9;
        *puVar7 = pWVar6;
        *pWVar6 = L'\0';
        puVar7[-5] = 0x18001cb16;
        iVar3 = MultiByteToWideChar(0,0,"OLELINKS",-1,(LPWSTR)*puVar7,*(int *)(puVar7 + 1));
        if (iVar3 == 0) {
          pWVar6 = pWVar8;
        }
        pcVar1 = *(code **)(*param_2 + 0x60);
        puVar7[-5] = 0x18001cb28;
        (*pcVar1)(param_2,pWVar6);
        puVar7 = puVar7 + -4;
      }
    }
    uVar5 = 0;
  }
  else {
    uStack_50 = 0x18001c9bd;
    uVar5 = (**(code **)(*param_1 + 0x278))(param_1,lVar4);
  }
LAB_18001cb43:
  *(undefined8 *)((longlong)puVar7 + -8) = 0x18001cb4f;
  return uVar5;
}

/* ---- FUNC 0001CB70 FUN_18001cb70 (13 bytes) ---- */

undefined8 FUN_18001cb70(void)

{
  DAT_1800797fc = 1;
  return 0;
}

/* ---- FUNC 0001CB80 FUN_18001cb80 (46 bytes) ---- */

undefined8 FUN_18001cb80(undefined8 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  *puVar1 = param_2;
  SetGlobalPointer("DontShowUpward",puVar1,0);
  return 0;
}

/* ---- FUNC 0001CBB0 FUN_18001cbb0 (135 bytes) ---- */

void FUN_18001cbb0(longlong param_1,char *param_2)

{
  char *_Dest;
  size_t _Count;
  size_t sVar1;
  
  if (*(void **)(param_1 + 0x108) != (void *)0x0) {
    operator_delete__(*(void **)(param_1 + 0x108));
  }
  if (param_2 == (char *)0x0) {
    *(undefined8 *)(param_1 + 0x108) = 0;
    return;
  }
  _Count = 0xffffffffffffffff;
  do {
    sVar1 = _Count;
    _Count = sVar1 + 1;
  } while (param_2[_Count] != '\0');
  _Dest = operator_new__(sVar1 + 2);
  *(char **)(param_1 + 0x108) = _Dest;
  strncpy(_Dest,param_2,_Count);
  *(undefined1 *)(_Count + *(longlong *)(param_1 + 0x108)) = 0;
  return;
}

/* ---- FUNC 0001CC40 FUN_18001cc40 (34 bytes) ---- */

void FUN_18001cc40(longlong *param_1)

{
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018001cc51. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x280))(param_1,0x7f3);
    return;
  }
  Ordinal_40(0xc);
  return;
}

/* ---- FUNC 0001CC70 FUN_18001cc70 (303 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_18001cc70(undefined8 param_1,LPCWSTR param_2)

{
  CApwnLibraries *this;
  longlong lVar1;
  ulonglong uVar3;
  char *pcVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined8 uStack_60;
  undefined1 auStack_58 [32];
  undefined8 uStack_38;
  int aiStack_30 [2];
  undefined8 local_28 [2];
  longlong local_18;
  ulonglong local_10;
  longlong lVar2;
  
  local_10 = DAT_180077818 ^ (ulonglong)&local_18;
  puVar5 = auStack_58;
  if (param_2 != (LPCWSTR)0x0) {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_2[lVar1] != L'\0');
    iVar6 = (int)lVar2 + 2;
    puVar5 = auStack_58;
    if (iVar6 < 0x40000000) {
      lVar1 = (longlong)(int)lVar1 * 2;
      uVar3 = lVar1 + 0x11;
      if (uVar3 <= lVar1 + 2U) {
        uVar3 = 0xffffffffffffff0;
      }
      uStack_60 = 0x18001ccdf;
      lVar1 = -(uVar3 & 0xfffffffffffffff0);
      puVar5 = auStack_58 + lVar1;
      pcVar4 = (char *)((longlong)&local_18 + lVar1);
      if (pcVar4 != (char *)0x0) {
        *pcVar4 = '\0';
        *(undefined8 *)((longlong)local_28 + lVar1 + 8) = 0;
        *(undefined8 *)((longlong)local_28 + lVar1) = 0;
        *(int *)((longlong)aiStack_30 + lVar1) = iVar6 * 2;
        *(char **)((longlong)&uStack_38 + lVar1) = pcVar4;
        *(undefined8 *)(auStack_58 + lVar1 + -8) = 0x18001cd19;
        iVar6 = WideCharToMultiByte(0,0,param_2,-1,*(LPSTR *)((longlong)&uStack_38 + lVar1),
                                    *(int *)((longlong)aiStack_30 + lVar1),
                                    *(LPCSTR *)((longlong)local_28 + lVar1),
                                    *(LPBOOL *)((longlong)local_28 + lVar1 + 8));
        puVar5 = auStack_58 + lVar1;
        if (iVar6 == 0) {
          pcVar4 = (char *)0x0;
          puVar5 = auStack_58 + lVar1;
        }
        goto LAB_18001cd26;
      }
    }
  }
  pcVar4 = (char *)0x0;
LAB_18001cd26:
  *(undefined8 *)(puVar5 + -8) = 0x18001cd33;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_18,pcVar4);
  iVar6 = *(int *)(local_18 + -0x10);
  *(undefined8 *)(puVar5 + -8) = 0x18001cd45;
  pcVar4 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)&local_18,iVar6);
  this = *(CApwnLibraries **)g_pApwnLibs_exref;
  *(undefined8 *)(puVar5 + -8) = 0x18001cd5e;
  iVar6 = CApwnLibraries::AddNewLibrary(this,pcVar4,1);
  *(undefined8 *)(puVar5 + -8) = 0x18001cd6f;
  ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_18,-1);
  *(undefined8 *)(puVar5 + -8) = 0x18001cd83;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_18);
  *(undefined8 *)(puVar5 + -8) = 0x18001cd91;
  return -(uint)(iVar6 != 0) & 0x80004005;
}

/* ---- FUNC 0001CDA0 FUN_18001cda0 (122 bytes) ---- */

undefined8 FUN_18001cda0(longlong param_1,longlong *param_2,undefined4 param_3)

{
  if (*(longlong **)(param_1 + 0x2f0) == (longlong *)0x0) {
    *(longlong **)(param_1 + 0x2f0) = param_2;
    if (param_2 != (longlong *)0x0) {
      (**(code **)(*param_2 + 8))(param_2);
    }
  }
  else {
    if (param_2 != (longlong *)0x0) {
      return 0x80004005;
    }
    (**(code **)(**(longlong **)(param_1 + 0x2f0) + 0x10))();
    *(undefined8 *)(param_1 + 0x2f0) = 0;
  }
  *(undefined4 *)(param_1 + 0x2d0) = param_3;
  return 0;
}

/* ---- FUNC 0001CE20 FUN_18001ce20 (280 bytes) ---- */

HRESULT FUN_18001ce20(longlong param_1,ushort *param_2,OLECHAR *param_3,int param_4,int param_5,
                     OLECHAR *param_6,OLECHAR *param_7,undefined8 param_8,undefined8 param_9,
                     undefined8 param_10,undefined8 param_11,OLECHAR *param_12)

{
  HRESULT HVar1;
  int iVar2;
  
  if (DAT_1800797f8 == 0) {
    HVar1 = FUN_180010c00(param_1,param_2);
    if (-1 < HVar1) {
      FUN_180010df0(param_1,param_3,param_6,param_7,param_12);
      HVar1 = 0;
      iVar2 = SetQueryForComponents_Mmg
                        (*(undefined4 *)(param_1 + 0x20),*(undefined8 *)(param_1 + 0x18),
                         *(undefined8 *)(param_1 + 0x28),param_4 != 0,param_5 == 1,
                         *(undefined8 *)(param_1 + 0x38),*(undefined8 *)(param_1 + 0x40),param_8,
                         param_9,param_10,param_11,*(undefined8 *)(param_1 + 0x30));
      if (iVar2 == -1) {
        HVar1 = -0x7fffbffb;
      }
    }
    return HVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x00018001ce5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HVar1 = (**(code **)(**(longlong **)(param_1 + 8) + 0x280))(*(longlong **)(param_1 + 8),0x7f3);
  return HVar1;
}

/* ---- FUNC 0001CF40 FUN_18001cf40 (25 bytes) ---- */

undefined8 FUN_18001cf40(longlong param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_2 + *(int *)(param_1 + 0x10);
  *(int *)(param_1 + 0x10) = iVar1;
  if (*(int *)(param_1 + 0xc) < iVar1) {
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0xc);
    return 1;
  }
  return 0;
}

/* ---- FUNC 0001CF60 FUN_18001cf60 (82 bytes) ---- */

ulonglong FUN_18001cf60(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018001cf7d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(**(longlong **)(param_1 + 8) + 0x280))(*(longlong **)(param_1 + 8),0x7f3);
    return uVar2;
  }
  Ordinal_99(1);
  uVar1 = Ordinal_40(5);
  Ordinal_99(0);
  return (ulonglong)uVar1;
}

/* ---- FUNC 0001CFC0 FUN_18001cfc0 (10 bytes) ---- */

void FUN_18001cfc0(void)

{
  Ordinal_40(10);
  return;
}

/* ---- FUNC 0001CFD0 FUN_18001cfd0 (38 bytes) ---- */

void FUN_18001cfd0(longlong param_1)

{
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018001cfe5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(longlong **)(param_1 + 8) + 0x280))(*(longlong **)(param_1 + 8),0x7f3);
    return;
  }
  Ordinal_40(8);
  return;
}

/* ---- FUNC 0001D000 FUN_18001d000 (711 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

ulonglong FUN_18001d000(longlong *param_1,VARIANTARG *param_2)

{
  VARTYPE VVar1;
  undefined4 *puVar2;
  uint uVar3;
  HRESULT HVar4;
  ulonglong uVar5;
  longlong lVar6;
  int iVar8;
  char *pcVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  LPCWSTR lpWideCharStr;
  undefined8 uStack_a0;
  undefined1 auStack_98 [32];
  undefined8 uStack_78;
  int aiStack_70 [2];
  undefined8 local_68 [2];
  undefined8 local_58;
  VARIANTARG local_50;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined8 local_28;
  ulonglong local_18;
  longlong lVar7;
  
  puVar10 = auStack_98;
  puVar11 = auStack_98;
  local_18 = DAT_180077818 ^ (ulonglong)&local_58;
  if (DAT_1800797f8 != 0) {
    uStack_a0 = 0x18001d045;
    uVar5 = (**(code **)(*(longlong *)param_1[1] + 0x280))((longlong *)param_1[1],0x7f3);
    goto LAB_18001d2ad;
  }
  uStack_a0 = 0x18001d054;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58);
  uStack_a0 = 0x18001d05f;
  VariantInit(&local_50);
  VVar1 = (param_2->n1).n2.vt;
  if (VVar1 == 0x400c) {
    puVar2 = *(undefined4 **)((longlong)&param_2->n1 + 8);
    local_38 = *puVar2;
    uStack_34 = puVar2[1];
    uStack_30 = puVar2[2];
    uStack_2c = puVar2[3];
    local_28 = *(undefined8 *)(puVar2 + 4);
    uStack_a0 = 0x18001d091;
    uVar3 = (**(code **)(*param_1 + 0x128))(param_1,&local_38);
    uVar5 = (ulonglong)uVar3;
    puVar10 = auStack_98;
  }
  else {
    puVar10 = auStack_98;
    if ((VVar1 != 0) && (puVar10 = auStack_98, VVar1 != 1)) {
      if (VVar1 == 8) {
        lpWideCharStr = *(LPCWSTR *)((longlong)&param_2->n1 + 8);
        if (lpWideCharStr == (LPCWSTR)0x0) {
LAB_18001d270:
          pcVar9 = (char *)0x0;
          puVar10 = puVar11;
        }
        else {
          lVar6 = -1;
          do {
            lVar6 = lVar6 + 1;
          } while (lpWideCharStr[lVar6] != L'\0');
LAB_18001d1fb:
          iVar8 = (int)lVar6 + 1;
          puVar11 = auStack_98;
          if (0x3fffffff < iVar8) goto LAB_18001d270;
          lVar6 = (longlong)(int)lVar6 * 2;
          uVar5 = lVar6 + 0x11;
          if (uVar5 <= lVar6 + 2U) {
            uVar5 = 0xffffffffffffff0;
          }
          uStack_a0 = 0x18001d22f;
          lVar6 = -(uVar5 & 0xfffffffffffffff0);
          puVar11 = auStack_98 + lVar6;
          pcVar9 = (char *)((longlong)&local_58 + lVar6);
          if (pcVar9 == (char *)0x0) goto LAB_18001d270;
          *pcVar9 = '\0';
          *(undefined8 *)((longlong)local_68 + lVar6 + 8) = 0;
          *(undefined8 *)((longlong)local_68 + lVar6) = 0;
          *(int *)((longlong)aiStack_70 + lVar6) = iVar8 * 2;
          *(char **)((longlong)&uStack_78 + lVar6) = pcVar9;
          *(undefined8 *)(auStack_98 + lVar6 + -8) = 0x18001d265;
          iVar8 = WideCharToMultiByte(0,0,lpWideCharStr,-1,*(LPSTR *)((longlong)&uStack_78 + lVar6),
                                      *(int *)((longlong)aiStack_70 + lVar6),
                                      *(LPCSTR *)((longlong)local_68 + lVar6),
                                      *(LPBOOL *)((longlong)local_68 + lVar6 + 8));
          puVar10 = auStack_98 + lVar6;
          if (iVar8 == 0) {
            pcVar9 = (char *)0x0;
            puVar10 = auStack_98 + lVar6;
          }
        }
        *(undefined8 *)(puVar10 + -8) = 0x18001d27f;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58,pcVar9
                  );
      }
      else {
        puVar10 = auStack_98;
        if (VVar1 == 10) goto LAB_18001d27f;
        if (VVar1 == 0x4008) {
          lpWideCharStr = (LPCWSTR)**(longlong **)((longlong)&param_2->n1 + 8);
          puVar11 = auStack_98;
          if (lpWideCharStr != (LPCWSTR)0x0) {
            lVar6 = -1;
            do {
              lVar6 = lVar6 + 1;
            } while (lpWideCharStr[lVar6] != L'\0');
            goto LAB_18001d1fb;
          }
          goto LAB_18001d270;
        }
        uStack_a0 = 0x18001d0df;
        HVar4 = VariantChangeType(&local_50,param_2,0,8);
        if (HVar4 < 0) {
          uStack_a0 = 0x18001d0f5;
          uVar3 = (**(code **)(*(longlong *)param_1[1] + 0x280))((longlong *)param_1[1],0x7d1);
          uVar5 = (ulonglong)uVar3;
          puVar10 = auStack_98;
          goto LAB_18001d2a1;
        }
        puVar10 = auStack_98;
        if (local_50.n1.decVal.u2.Lo64 == 0) {
LAB_18001d190:
          pcVar9 = (char *)0x0;
        }
        else {
          lVar6 = -1;
          do {
            lVar7 = lVar6;
            lVar6 = lVar7 + 1;
          } while (*(LPCWSTR)((longlong)local_50.n1.decVal.u2 + lVar6 * 2) != L'\0');
          iVar8 = (int)lVar7 + 2;
          puVar10 = auStack_98;
          if (0x3fffffff < iVar8) goto LAB_18001d190;
          lVar6 = (longlong)(int)lVar6 * 2;
          uVar5 = lVar6 + 0x11;
          if (uVar5 <= lVar6 + 2U) {
            uVar5 = 0xffffffffffffff0;
          }
          uStack_a0 = 0x18001d14f;
          lVar6 = -(uVar5 & 0xfffffffffffffff0);
          puVar10 = auStack_98 + lVar6;
          pcVar9 = (char *)((longlong)&local_58 + lVar6);
          if (pcVar9 == (char *)0x0) goto LAB_18001d190;
          *pcVar9 = '\0';
          *(undefined8 *)((longlong)local_68 + lVar6 + 8) = 0;
          *(undefined8 *)((longlong)local_68 + lVar6) = 0;
          *(int *)((longlong)aiStack_70 + lVar6) = iVar8 * 2;
          *(char **)((longlong)&uStack_78 + lVar6) = pcVar9;
          *(undefined8 *)(auStack_98 + lVar6 + -8) = 0x18001d185;
          iVar8 = WideCharToMultiByte(0,0,(LPCWSTR)local_50.n1.decVal.u2,-1,
                                      *(LPSTR *)((longlong)&uStack_78 + lVar6),
                                      *(int *)((longlong)aiStack_70 + lVar6),
                                      *(LPCSTR *)((longlong)local_68 + lVar6),
                                      *(LPBOOL *)((longlong)local_68 + lVar6 + 8));
          puVar10 = auStack_98 + lVar6;
          if (iVar8 == 0) {
            pcVar9 = (char *)0x0;
            puVar10 = auStack_98 + lVar6;
          }
        }
        *(undefined8 *)(puVar10 + -8) = 0x18001d19f;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58,pcVar9
                  );
        *(undefined8 *)(puVar10 + -8) = 0x18001d1a9;
        VariantClear(&local_50);
      }
    }
LAB_18001d27f:
    *(undefined8 *)(puVar10 + -8) = 0x18001d289;
    Ordinal_99(1);
    *(undefined8 *)(puVar10 + -8) = 0x18001d297;
    uVar3 = Ordinal_40(0x21,local_58);
    uVar5 = (ulonglong)uVar3;
    *(undefined8 *)(puVar10 + -8) = 0x18001d2a0;
    Ordinal_99(0);
  }
LAB_18001d2a1:
  *(undefined8 *)(puVar10 + -8) = 0x18001d2ab;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58);
LAB_18001d2ad:
  *(undefined8 *)(puVar10 + -8) = 0x18001d2b9;
  return uVar5;
}

/* ---- FUNC 0001D2D0 FUN_18001d2d0 (174 bytes) ---- */

void FUN_18001d2d0(longlong param_1,int param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  uVar1 = *(ulonglong *)(param_1 + 0x228);
  uVar2 = 0;
  uVar3 = uVar2;
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar3 < 0) || (*(longlong *)(param_1 + 0x228) <= (longlong)uVar3))
      goto LAB_18001d379;
      FUN_1800303e0(*(longlong *)(*(longlong *)(param_1 + 0x220) + uVar3 * 8),param_2);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  if ((param_2 == 0) && (uVar1 = *(ulonglong *)(param_1 + 0x200), uVar1 != 0)) {
    do {
      if (((longlong)uVar2 < 0) || (*(longlong *)(param_1 + 0x200) <= (longlong)uVar2)) {
LAB_18001d379:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      FUN_18002bb30(*(longlong *)(*(longlong *)(param_1 + 0x1f8) + uVar2 * 8));
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar1);
  }
  return;
}

/* ---- FUNC 0001D380 FUN_18001d380 (285 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_18001d380(longlong *param_1,LPCWSTR param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  longlong lVar3;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined1 *puVar7;
  char *pcVar8;
  int iVar9;
  undefined8 uStack_60;
  undefined1 auStack_58 [32];
  undefined8 uStack_38;
  int aiStack_30 [2];
  undefined8 local_28 [2];
  undefined8 local_18;
  ulonglong local_10;
  longlong lVar4;
  
  local_10 = DAT_180077818 ^ (ulonglong)&local_18;
  puVar7 = auStack_58;
  if (param_2 != (LPCWSTR)0x0) {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_2[lVar3] != L'\0');
    iVar9 = (int)lVar4 + 2;
    puVar7 = auStack_58;
    if (iVar9 < 0x40000000) {
      lVar3 = (longlong)(int)lVar3 * 2;
      uVar6 = lVar3 + 0x11;
      if (uVar6 <= lVar3 + 2U) {
        uVar6 = 0xffffffffffffff0;
      }
      uStack_60 = 0x18001d400;
      lVar3 = -(uVar6 & 0xfffffffffffffff0);
      puVar7 = auStack_58 + lVar3;
      pcVar8 = (char *)((longlong)&local_18 + lVar3);
      if (pcVar8 != (char *)0x0) {
        *pcVar8 = '\0';
        *(undefined8 *)((longlong)local_28 + lVar3 + 8) = 0;
        *(undefined8 *)((longlong)local_28 + lVar3) = 0;
        *(int *)((longlong)aiStack_30 + lVar3) = iVar9 * 2;
        *(char **)((longlong)&uStack_38 + lVar3) = pcVar8;
        *(undefined8 *)(auStack_58 + lVar3 + -8) = 0x18001d43a;
        iVar9 = WideCharToMultiByte(0,0,param_2,-1,*(LPSTR *)((longlong)&uStack_38 + lVar3),
                                    *(int *)((longlong)aiStack_30 + lVar3),
                                    *(LPCSTR *)((longlong)local_28 + lVar3),
                                    *(LPBOOL *)((longlong)local_28 + lVar3 + 8));
        puVar7 = auStack_58 + lVar3;
        if (iVar9 == 0) {
          puVar7 = auStack_58 + lVar3;
          pcVar8 = (char *)0x0;
        }
        goto LAB_18001d446;
      }
    }
  }
  pcVar8 = (char *)0x0;
LAB_18001d446:
  uVar2 = 0;
  *(undefined8 *)(puVar7 + -8) = 0x18001d453;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_18,pcVar8);
  *(undefined8 *)(puVar7 + -8) = 0x18001d45c;
  uVar5 = FUN_180037600(local_18);
  if ((int)uVar5 < 0) {
    pcVar1 = *(code **)(*param_1 + 0x280);
    *(undefined8 *)(puVar7 + -8) = 0x18001d471;
    uVar2 = (*pcVar1)(param_1,0x7f5);
  }
  *(undefined8 *)(puVar7 + -8) = 0x18001d47d;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_18);
  *(undefined8 *)(puVar7 + -8) = 0x18001d48b;
  return uVar2;
}

/* ---- FUNC 0001D4A0 FUN_18001d4a0 (314 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_18001d4a0(longlong param_1,int param_2,int param_3)

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
  if (DAT_1800797f8 == 0) {
    local_58 = (undefined8 *)0x0;
    local_40 = 0xffffffff;
    local_18 = 0;
    DAT_180079480 = 0;
    local_50 = _DAT_1800648b0;
    uStack_48 = _UNK_1800648b8;
    local_28 = 0;
    uStack_20 = 0;
    local_38 = 0;
    uStack_30 = 0;
    if ((param_2 == 0) || (param_3 == 0)) {
LAB_18001d5d1:
      return &DAT_180079480;
    }
    lVar1 = HAGetTree(*(undefined8 *)(param_1 + 0x20),&local_58);
    if ((lVar1 != 0) && (lVar1 = HAGetElement(lVar1,&local_50,&local_38,&local_58), lVar1 != 0)) {
      local_50 = CONCAT44(local_50._4_4_,param_2 + -1);
      lVar1 = HAGetElement(lVar1,&local_50,&local_38,&local_58);
      if (lVar1 != 0) {
        local_58 = (undefined8 *)HAGetLabel(lVar1,0,param_3 + -1,&DAT_180079480);
        if (local_58 != (undefined8 *)0x0) {
          if ((code *)*local_58 != (code *)0x0) {
            (*(code *)*local_58)(local_58);
          }
          DAT_180079480 = 0;
          return (undefined *)0x0;
        }
        goto LAB_18001d5d1;
      }
    }
    if ((local_58 != (undefined8 *)0x0) && ((code *)*local_58 != (code *)0x0)) {
      (*(code *)*local_58)();
    }
  }
  return (undefined *)0x0;
}

/* ---- FUNC 0001D5E0 FUN_18001d5e0 (1245 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001d5e0(IUnknown *param_1,char *param_2,undefined8 param_3,undefined8 param_4)

{
  IUnknown *ppmk;
  IUnknown *pIVar1;
  DWORD *pDVar2;
  LPCOLESTR pOVar3;
  DWORD DVar4;
  IUnknownVtbl *pIVar5;
  _func_5329 *p_Var6;
  _func_5300 *p_Var7;
  IRunningObjectTableVtbl *pIVar8;
  _func_5299 *p_Var9;
  _func_5320 *p_Var10;
  _func_5298 *p_Var11;
  _func_5301 *p_Var12;
  IUnknownVtbl *pIVar13;
  code *pcVar14;
  IRunningObjectTable *pIVar15;
  IMoniker *pIVar16;
  HRESULT HVar17;
  longlong lVar18;
  longlong lVar19;
  int iVar20;
  ulonglong uVar21;
  char *pcVar22;
  LPCOLESTR pOVar23;
  undefined1 *puVar24;
  undefined1 *puVar25;
  LPCOLESTR pOVar26;
  size_t _Count;
  ulonglong uVar27;
  undefined8 uStack_c0;
  undefined1 auStack_b8 [32];
  undefined8 uStack_98;
  int aiStack_90 [2];
  IRunningObjectTable *local_88;
  IMoniker *local_80;
  IMoniker *local_78;
  IUnknown *local_70;
  IUnknown *local_68;
  char local_60 [24];
  ulonglong local_48;
  
  local_48 = DAT_180077818 ^ (ulonglong)&local_88;
  ppmk = param_1 + 0x23;
  local_70 = param_1;
  local_68 = ppmk;
  if (param_2 == (char *)0x0) {
    uStack_c0 = 0x18001d7b5;
    FUN_18001cbb0((longlong)param_1,(char *)0x0);
    pIVar5 = ppmk->lpVtbl;
    if (pIVar5 != (IUnknownVtbl *)0x0) {
      uStack_c0 = 0x18001d7c3;
      (*((IMonikerVtbl *)pIVar5->QueryInterface)->Release)((IMoniker *)pIVar5);
      ppmk->lpVtbl = (IUnknownVtbl *)0x0;
    }
    pOVar23 = (LPCOLESTR)0x0;
    uVar27 = 2;
    uStack_c0 = 0x18001d7d7;
    iVar20 = MVGetProductCode();
    if (iVar20 == 1) {
      _Count = 0xd;
      pcVar22 = "Simulation 1";
    }
    else {
      _Count = 10;
      pcVar22 = "Problem 1";
    }
    uStack_c0 = 0x18001d800;
    strncpy(local_60,pcVar22,_Count);
    lVar18 = -1;
    do {
      lVar19 = lVar18;
      lVar18 = lVar19 + 1;
    } while (local_60[lVar19 + 1] != '\0');
    iVar20 = (int)lVar19 + 2;
    puVar25 = auStack_b8;
    pOVar26 = pOVar23;
    if (iVar20 < 0x40000000) {
      lVar18 = (longlong)(int)(lVar19 + 1) * 2;
      uVar21 = lVar18 + 0x11;
      if (uVar21 <= lVar18 + 2U) {
        uVar21 = 0xffffffffffffff0;
      }
      uStack_c0 = 0x18001d850;
      lVar18 = -(uVar21 & 0xfffffffffffffff0);
      pOVar3 = (LPCOLESTR)((longlong)&local_88 + lVar18);
      puVar25 = auStack_b8 + lVar18;
      if (pOVar3 != (LPCOLESTR)0x0) {
        *pOVar3 = L'\0';
        *(int *)((longlong)aiStack_90 + lVar18) = iVar20;
        *(LPCOLESTR *)((longlong)&uStack_98 + lVar18) = pOVar3;
        param_4 = 0xffffffff;
        *(undefined8 *)(auStack_b8 + lVar18 + -8) = 0x18001d87d;
        iVar20 = MultiByteToWideChar(0,0,local_60,-1,*(LPWSTR *)((longlong)&uStack_98 + lVar18),
                                     *(int *)((longlong)aiStack_90 + lVar18));
        puVar25 = auStack_b8 + lVar18;
        pOVar26 = pOVar3;
        if (iVar20 == 0) {
          puVar25 = auStack_b8 + lVar18;
          pOVar26 = pOVar23;
        }
      }
    }
    *(undefined8 *)(puVar25 + -8) = 0x18001d894;
    HVar17 = CreateFileMoniker(pOVar26,(LPMONIKER *)ppmk);
    puVar24 = puVar25;
    if (HVar17 < 0) goto LAB_18001da92;
    *(undefined8 *)(puVar25 + -8) = 0x18001d8a8;
    HVar17 = GetRunningObjectTable(0,&local_88);
    pIVar15 = local_88;
    if (-1 < HVar17) {
      pIVar5 = ppmk->lpVtbl;
      p_Var12 = local_88->lpVtbl->IsRunning;
      *(undefined8 *)(puVar25 + -8) = 0x18001d8bd;
      iVar20 = (*p_Var12)(pIVar15,(IMoniker *)pIVar5);
      while (iVar20 == 0) {
        pIVar5 = ppmk->lpVtbl;
        p_Var10 = ((IMonikerVtbl *)pIVar5->QueryInterface)->Release;
        *(undefined8 *)(puVar25 + -8) = 0x18001d8d9;
        (*p_Var10)((IMoniker *)pIVar5);
        *(undefined8 *)(puVar25 + -8) = 0x18001d8de;
        iVar20 = MVGetProductCode();
        pcVar22 = "Simulation %d";
        if (iVar20 != 1) {
          pcVar22 = "Problem %d";
        }
        *(undefined8 *)(puVar25 + -8) = 0x18001d8f8;
        FUN_180002a20(local_60,pcVar22,uVar27,param_4);
        lVar18 = -1;
        do {
          lVar19 = lVar18;
          lVar18 = lVar19 + 1;
        } while (local_60[lVar19 + 1] != '\0');
        iVar20 = (int)lVar19 + 2;
        puVar24 = puVar25;
        pOVar26 = pOVar23;
        if (iVar20 < 0x40000000) {
          lVar18 = (longlong)(int)(lVar19 + 1) * 2;
          uVar21 = lVar18 + 0x11;
          if (uVar21 <= lVar18 + 2U) {
            uVar21 = 0xffffffffffffff0;
          }
          *(undefined8 *)(puVar25 + -8) = 0x18001d939;
          lVar18 = -(uVar21 & 0xfffffffffffffff0);
          pOVar3 = (LPCOLESTR)(puVar25 + lVar18 + 0x30);
          puVar24 = puVar25 + lVar18;
          if (pOVar3 != (LPCOLESTR)0x0) {
            *pOVar3 = L'\0';
            *(int *)(puVar25 + lVar18 + 0x28) = iVar20;
            *(LPCOLESTR *)(puVar25 + lVar18 + 0x20) = pOVar3;
            param_4 = 0xffffffff;
            *(undefined8 *)(puVar25 + lVar18 + -8) = 0x18001d966;
            iVar20 = MultiByteToWideChar(0,0,local_60,-1,*(LPWSTR *)(puVar25 + lVar18 + 0x20),
                                         *(int *)(puVar25 + lVar18 + 0x28));
            puVar24 = puVar25 + lVar18;
            pOVar26 = pOVar3;
            if (iVar20 == 0) {
              puVar24 = puVar25 + lVar18;
              pOVar26 = pOVar23;
            }
          }
        }
        *(undefined8 *)(puVar24 + -8) = 0x18001d97d;
        HVar17 = CreateFileMoniker(pOVar26,(LPMONIKER *)ppmk);
        pIVar15 = local_88;
        if (HVar17 < 0) {
          p_Var11 = local_88->lpVtbl->Release;
          *(undefined8 *)(puVar24 + -8) = 0x18001d9e3;
          (*p_Var11)(local_88);
          goto LAB_18001da9a;
        }
        uVar27 = (ulonglong)((int)uVar27 + 1);
        pIVar5 = ppmk->lpVtbl;
        p_Var12 = local_88->lpVtbl->IsRunning;
        *(undefined8 *)(puVar24 + -8) = 0x18001d991;
        iVar20 = (*p_Var12)(pIVar15,(IMoniker *)pIVar5);
        puVar25 = puVar24;
      }
      *(undefined8 *)(puVar25 + -8) = 0x18001d9ac;
      FUN_18001cbb0((longlong)param_1,local_60);
      *(undefined8 *)(puVar25 + -8) = 0x18001d9c4;
      CreateItemMoniker(L"!",L"\\",&local_80);
      pIVar16 = local_80;
      if (local_80 != (IMoniker *)0x0) {
        pIVar5 = ppmk->lpVtbl;
        p_Var6 = ((IMonikerVtbl *)pIVar5->QueryInterface)->ComposeWith;
        *(undefined8 *)(puVar25 + -8) = 0x18001d9dd;
        (*p_Var6)((IMoniker *)pIVar5,pIVar16,0,&local_78);
      }
      pIVar15 = local_88;
      pIVar1 = param_1 + 0x22;
      DVar4 = *(DWORD *)&pIVar1->lpVtbl;
      if (DVar4 != 0) {
        p_Var7 = local_88->lpVtbl->Revoke;
        *(undefined8 *)(puVar25 + -8) = 0x18001da09;
        (*p_Var7)(pIVar15,DVar4);
        *(undefined4 *)&pIVar1->lpVtbl = 0;
      }
      pIVar15 = local_88;
      pDVar2 = (DWORD *)((longlong)&param_1[0x22].lpVtbl + 4);
      DVar4 = *pDVar2;
      if (DVar4 != 0) {
        p_Var7 = local_88->lpVtbl->Revoke;
        *(undefined8 *)(puVar25 + -8) = 0x18001da23;
        (*p_Var7)(pIVar15,DVar4);
        *pDVar2 = 0;
      }
      pIVar15 = local_88;
      pIVar8 = local_88->lpVtbl;
      *(IUnknown **)(puVar25 + 0x20) = pIVar1;
      pIVar5 = ppmk->lpVtbl;
      p_Var9 = pIVar8->Register;
      *(undefined8 *)(puVar25 + -8) = 0x18001da3d;
      (*p_Var9)(pIVar15,0,param_1,(IMoniker *)pIVar5,*(DWORD **)(puVar25 + 0x20));
      pIVar16 = local_78;
      pIVar15 = local_88;
      if (local_78 != (IMoniker *)0x0) {
        pIVar8 = local_88->lpVtbl;
        *(DWORD **)(puVar25 + 0x20) = pDVar2;
        p_Var9 = pIVar8->Register;
        *(undefined8 *)(puVar25 + -8) = 0x18001da5a;
        (*p_Var9)(pIVar15,0,param_1,pIVar16,*(DWORD **)(puVar25 + 0x20));
        p_Var10 = local_78->lpVtbl->Release;
        *(undefined8 *)(puVar25 + -8) = 0x18001da64;
        (*p_Var10)(local_78);
      }
      p_Var11 = local_88->lpVtbl->Release;
      *(undefined8 *)(puVar25 + -8) = 0x18001da6e;
      (*p_Var11)(local_88);
      if (local_80 != (IMoniker *)0x0) goto LAB_18001da77;
    }
  }
  else {
    uStack_c0 = 0x18001d630;
    FUN_18001cbb0((longlong)param_1,param_2);
    pIVar5 = ppmk->lpVtbl;
    if (pIVar5 != (IUnknownVtbl *)0x0) {
      uStack_c0 = 0x18001d63e;
      (*((IMonikerVtbl *)pIVar5->QueryInterface)->Release)((IMoniker *)pIVar5);
      ppmk->lpVtbl = (IUnknownVtbl *)0x0;
    }
    pOVar23 = (LPCOLESTR)0x0;
    lVar18 = -1;
    do {
      lVar19 = lVar18;
      lVar18 = lVar19 + 1;
    } while (param_2[lVar18] != '\0');
    iVar20 = (int)lVar19 + 2;
    puVar25 = auStack_b8;
    pOVar26 = pOVar23;
    if (iVar20 < 0x40000000) {
      lVar18 = (longlong)(int)lVar18 * 2;
      uVar27 = lVar18 + 0x11;
      if (uVar27 <= lVar18 + 2U) {
        uVar27 = 0xffffffffffffff0;
      }
      uStack_c0 = 0x18001d68e;
      lVar18 = -(uVar27 & 0xfffffffffffffff0);
      pOVar3 = (LPCOLESTR)((longlong)&local_88 + lVar18);
      puVar25 = auStack_b8 + lVar18;
      if (pOVar3 != (LPCOLESTR)0x0) {
        *pOVar3 = L'\0';
        *(int *)((longlong)aiStack_90 + lVar18) = iVar20;
        *(LPCOLESTR *)((longlong)&uStack_98 + lVar18) = pOVar3;
        *(undefined8 *)(auStack_b8 + lVar18 + -8) = 0x18001d6ba;
        iVar20 = MultiByteToWideChar(0,0,param_2,-1,*(LPWSTR *)((longlong)&uStack_98 + lVar18),
                                     *(int *)((longlong)aiStack_90 + lVar18));
        puVar25 = auStack_b8 + lVar18;
        pOVar26 = pOVar3;
        if (iVar20 == 0) {
          puVar25 = auStack_b8 + lVar18;
          pOVar26 = pOVar23;
        }
      }
    }
    *(undefined8 *)(puVar25 + -8) = 0x18001d6d1;
    HVar17 = CreateFileMoniker(pOVar26,(LPMONIKER *)ppmk);
    puVar24 = puVar25;
    if (HVar17 < 0) goto LAB_18001da92;
    *(undefined8 *)(puVar25 + -8) = 0x18001d6f1;
    CreateItemMoniker(L"!",L"\\",&local_78);
    pIVar16 = local_78;
    if (local_78 != (IMoniker *)0x0) {
      pIVar5 = ppmk->lpVtbl;
      p_Var6 = ((IMonikerVtbl *)pIVar5->QueryInterface)->ComposeWith;
      *(undefined8 *)(puVar25 + -8) = 0x18001d70a;
      (*p_Var6)((IMoniker *)pIVar5,pIVar16,0,&local_80);
    }
    *(undefined8 *)(puVar25 + -8) = 0x18001d723;
    HVar17 = GetRunningObjectTable(0,&local_88);
    pIVar15 = local_88;
    if (-1 < HVar17) {
      pIVar1 = param_1 + 0x22;
      DVar4 = *(DWORD *)&pIVar1->lpVtbl;
      if (DVar4 != 0) {
        p_Var7 = local_88->lpVtbl->Revoke;
        *(undefined8 *)(puVar25 + -8) = 0x18001d742;
        (*p_Var7)(pIVar15,DVar4);
        *(undefined4 *)&pIVar1->lpVtbl = 0;
      }
      pIVar15 = local_88;
      pDVar2 = (DWORD *)((longlong)&param_1[0x22].lpVtbl + 4);
      DVar4 = *pDVar2;
      if (DVar4 != 0) {
        p_Var7 = local_88->lpVtbl->Revoke;
        *(undefined8 *)(puVar25 + -8) = 0x18001d75c;
        (*p_Var7)(pIVar15,DVar4);
        *pDVar2 = 0;
      }
      pIVar15 = local_88;
      pIVar8 = local_88->lpVtbl;
      *(IUnknown **)(puVar25 + 0x20) = pIVar1;
      pIVar5 = ppmk->lpVtbl;
      p_Var9 = pIVar8->Register;
      *(undefined8 *)(puVar25 + -8) = 0x18001d776;
      (*p_Var9)(pIVar15,0,param_1,(IMoniker *)pIVar5,*(DWORD **)(puVar25 + 0x20));
      pIVar16 = local_80;
      pIVar15 = local_88;
      if (local_80 != (IMoniker *)0x0) {
        pIVar8 = local_88->lpVtbl;
        *(DWORD **)(puVar25 + 0x20) = pDVar2;
        p_Var9 = pIVar8->Register;
        *(undefined8 *)(puVar25 + -8) = 0x18001d793;
        (*p_Var9)(pIVar15,0,param_1,pIVar16,*(DWORD **)(puVar25 + 0x20));
        p_Var10 = local_80->lpVtbl->Release;
        *(undefined8 *)(puVar25 + -8) = 0x18001d79d;
        (*p_Var10)(local_80);
      }
      p_Var11 = local_88->lpVtbl->Release;
      *(undefined8 *)(puVar25 + -8) = 0x18001d7a7;
      (*p_Var11)(local_88);
      local_80 = local_78;
LAB_18001da77:
      p_Var10 = local_80->lpVtbl->Release;
      *(undefined8 *)(puVar25 + -8) = 0x18001da7d;
      (*p_Var10)(local_80);
    }
  }
  pIVar5 = param_1[0x30].lpVtbl;
  puVar24 = puVar25;
  if (pIVar5 != (IUnknownVtbl *)0x0) {
    pIVar13 = ppmk->lpVtbl;
    pcVar14 = *(code **)(pIVar5->QueryInterface + 0x30);
    *(undefined8 *)(puVar25 + -8) = 0x18001da92;
    (*pcVar14)(pIVar5,pIVar13);
  }
LAB_18001da92:
  *(undefined4 *)&param_1[3].lpVtbl = 1;
LAB_18001da9a:
  *(undefined8 *)(puVar24 + -8) = 0x18001daa6;
  return;
}

/* ---- FUNC 0001DAC0 FUN_18001dac0 (272 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_18001dac0(longlong param_1,undefined8 param_2)

{
  HRESULT HVar1;
  longlong lVar2;
  undefined8 *local_res18;
  IStorage *local_res20;
  
  local_res18 = (undefined8 *)0x0;
  local_res20 = (IStorage *)0x0;
  _DAT_180079478 = "mmg.exe";
  HVar1 = StgCreateDocfile((WCHAR *)0x0,0x4011012,0,&local_res20);
  if (-1 < HVar1) {
    HAInitialize(DAT_1800776d8,&DAT_180079478,&PTR_HappNotifyThread_1800776f0,
                 &PTR_Ordinal_41_1800775d0,&local_res18);
    if (local_res18 != (undefined8 *)0x0) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      return;
    }
    lVar2 = HAInitNew(local_res20,&local_res18,1);
    *(longlong *)(param_1 + 0x20) = lVar2;
    if (((lVar2 == 0) && (local_res18 != (undefined8 *)0x0)) &&
       ((code *)*local_res18 != (code *)0x0)) {
      (*(code *)*local_res18)();
      return;
    }
    HAAddRef(lVar2,&local_res18);
    SetGlobalPointer("FileNode",*(undefined8 *)(param_1 + 0x20),0);
    HAVarsum(param_2);
    (*local_res20->lpVtbl->Release)(local_res20);
  }
  return;
}

/* ---- FUNC 0001DBD0 FUN_18001dbd0 (391 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

ulonglong FUN_18001dbd0(longlong *param_1,undefined8 *param_2,undefined4 param_3)

{
  LPCWSTR lpWideCharStr;
  code *pcVar1;
  undefined8 uVar2;
  longlong *plVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  int iVar8;
  undefined1 *puVar9;
  char *pcVar10;
  undefined8 uStack_70;
  undefined1 auStack_68 [32];
  undefined8 uStack_48;
  int aiStack_40 [2];
  undefined8 local_38 [2];
  int local_28 [2];
  undefined8 local_20;
  longlong *local_18;
  ulonglong local_10;
  longlong lVar7;
  
  puVar9 = auStack_68;
  local_10 = DAT_180077818 ^ (ulonglong)local_28;
  if (DAT_1800797f8 != 0) {
    uStack_70 = 0x18001dc16;
    uVar5 = (**(code **)(*param_1 + 0x280))(param_1,0x7f3);
    goto LAB_18001dd35;
  }
  lpWideCharStr = (LPCWSTR)*param_2;
  puVar9 = auStack_68;
  if (lpWideCharStr == (LPCWSTR)0x0) {
LAB_18001dcad:
    pcVar10 = (char *)0x0;
  }
  else {
    lVar6 = -1;
    do {
      lVar7 = lVar6;
      lVar6 = lVar7 + 1;
    } while (lpWideCharStr[lVar6] != L'\0');
    iVar8 = (int)lVar7 + 2;
    puVar9 = auStack_68;
    if (0x3fffffff < iVar8) goto LAB_18001dcad;
    lVar6 = (longlong)(int)lVar6 * 2;
    uVar5 = lVar6 + 0x11;
    if (uVar5 <= lVar6 + 2U) {
      uVar5 = 0xffffffffffffff0;
    }
    uStack_70 = 0x18001dc6f;
    lVar6 = -(uVar5 & 0xfffffffffffffff0);
    puVar9 = auStack_68 + lVar6;
    pcVar10 = (char *)((longlong)local_28 + lVar6);
    if (pcVar10 == (char *)0x0) goto LAB_18001dcad;
    *pcVar10 = '\0';
    *(undefined8 *)((longlong)local_38 + lVar6 + 8) = 0;
    *(undefined8 *)((longlong)local_38 + lVar6) = 0;
    *(int *)((longlong)aiStack_40 + lVar6) = iVar8 * 2;
    *(char **)((longlong)&uStack_48 + lVar6) = pcVar10;
    *(undefined8 *)(auStack_68 + lVar6 + -8) = 0x18001dca5;
    iVar8 = WideCharToMultiByte(0,0,lpWideCharStr,-1,*(LPSTR *)((longlong)&uStack_48 + lVar6),
                                *(int *)((longlong)aiStack_40 + lVar6),
                                *(LPCSTR *)((longlong)local_38 + lVar6),
                                *(LPBOOL *)((longlong)local_38 + lVar6 + 8));
    puVar9 = auStack_68 + lVar6;
    if (iVar8 == 0) {
      puVar9 = auStack_68 + lVar6;
      pcVar10 = (char *)0x0;
    }
  }
  uVar5 = 0;
  *(undefined8 *)(puVar9 + -8) = 0x18001dcbe;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_20,pcVar10);
  uVar2 = local_20;
  local_28[0] = 0;
  *(undefined8 *)(puVar9 + -8) = 0x18001dcce;
  HappFireBeforeSave(uVar2,local_28);
  if (local_28[0] == 0) {
    pcVar1 = *(code **)(*param_1 + 0x90);
    *(undefined8 *)(puVar9 + -8) = 0x18001dce4;
    (*pcVar1)(param_1,&local_18);
    plVar3 = local_18;
    if (local_18 == (longlong *)0x0) goto LAB_18001dd22;
    lVar6 = param_1[4];
    *(undefined8 *)(puVar9 + -8) = 0x18001dcfe;
    lVar6 = HAWriteArchiveByName(local_20,lVar6,plVar3,param_3);
    pcVar1 = *(code **)(*local_18 + 0x10);
    *(undefined8 *)(puVar9 + -8) = 0x18001dd0b;
    (*pcVar1)();
    if (lVar6 != 0) {
      pcVar1 = *(code **)(*param_1 + 0x278);
      *(undefined8 *)(puVar9 + -8) = 0x18001dd20;
      uVar4 = (*pcVar1)(param_1,lVar6);
      goto LAB_18001dd27;
    }
  }
  else {
LAB_18001dd22:
    uVar4 = 0x80004005;
LAB_18001dd27:
    uVar5 = (ulonglong)uVar4;
  }
  *(undefined8 *)(puVar9 + -8) = 0x18001dd33;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_20);
LAB_18001dd35:
  *(undefined8 *)(puVar9 + -8) = 0x18001dd41;
  return uVar5;
}

/* ---- FUNC 0001DD60 FUN_18001dd60 (16 bytes) ---- */

void FUN_18001dd60(longlong *param_1,undefined8 param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00018001dd69. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x170))(param_1,param_2,1);
  return;
}

/* ---- FUNC 0001DD70 FUN_18001dd70 (95 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18001dd70(longlong *param_1,undefined4 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  ulonglong _Count;
  undefined1 auStack_188 [32];
  longlong *local_168;
  longlong *local_160;
  longlong *local_158 [2];
  char local_148 [256];
  ulonglong local_48;
  ulonglong uVar4;
  
  local_48 = DAT_180077818 ^ (ulonglong)auStack_188;
  lVar3 = 0;
  if ((int)param_1[3] == 0) {
    uVar2 = (**(code **)(*param_1 + 0x280))(param_1,0x7d2);
  }
  else if (param_3 == (char *)0x0) {
    uVar2 = (**(code **)(*param_1 + 0x280))(param_1,0x7d1);
  }
  else {
    _Count = 0xffffffffffffffff;
    do {
      uVar4 = _Count;
      _Count = uVar4 + 1;
    } while (param_3[_Count] != '\0');
    if (_Count < 0x100) {
      (**(code **)(*param_1 + 0x90))(param_1,local_158);
      if (local_158[0] == (longlong *)0x0) {
        uVar2 = 0x80004005;
      }
      else {
        strncpy(local_148,param_3,_Count);
        local_148[uVar4 + 1] = '\0';
        iVar1 = MVGetProductCode();
        if (iVar1 == 1) {
          local_160 = (longlong *)0x0;
          iVar1 = (**(code **)*local_158[0])(local_158[0],&DAT_180063650,&local_160);
          if ((-1 < iVar1) && (local_160 != (longlong *)0x0)) {
            local_168 = (longlong *)0x0;
            iVar1 = (**(code **)(*local_160 + 0x28))(local_160,param_4,&local_168);
            if ((-1 < iVar1) && (local_168 != (longlong *)0x0)) {
              lVar3 = HAWriteExportByName3(param_2,local_148,param_4);
              (**(code **)(*local_168 + 0x10))();
            }
            (**(code **)(*local_160 + 0x10))();
          }
        }
        else {
          lVar3 = HAWriteExportByName3(param_2,local_148,0,0);
        }
        (**(code **)(*local_158[0] + 0x10))();
        if (lVar3 == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = (**(code **)(*param_1 + 0x278))(param_1,lVar3);
        }
      }
    }
    else {
      uVar2 = (**(code **)(*param_1 + 0x280))(param_1,0x7d1);
    }
  }
  return uVar2;
}

/* ---- FUNC 0001DDCF FUN_18001ddcf (298 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_18001ddcf(longlong *param_1,undefined8 param_2,longlong param_3,undefined8 param_4,
             longlong *param_5,longlong *param_6)

{
  int iVar1;
  undefined8 uVar2;
  longlong *plVar3;
  ulonglong _Count;
  longlong *unaff_RBP;
  char *unaff_RSI;
  longlong *unaff_RDI;
  undefined4 unaff_R14D;
  ulonglong uVar4;
  
  _Count = 0xffffffffffffffff;
  do {
    uVar4 = _Count;
    _Count = uVar4 + 1;
  } while (*(char *)(param_3 + _Count) != (char)unaff_RBP);
  if (_Count < 0x100) {
    (**(code **)(*param_1 + 0x90))(param_1,&param_6);
    if (param_6 == unaff_RBP) {
      uVar2 = 0x80004005;
    }
    else {
      strncpy(&stack0x00000040,unaff_RSI,_Count);
      (&stack0x00000041)[uVar4] = (char)unaff_RBP;
      iVar1 = MVGetProductCode();
      if (iVar1 == 1) {
        param_5 = unaff_RBP;
        iVar1 = (**(code **)*param_6)(param_6,&DAT_180063650,&stack0x00000028);
        plVar3 = unaff_RBP;
        if ((-1 < iVar1) && (param_5 != (longlong *)0x0)) {
          iVar1 = (**(code **)(*param_5 + 0x28))();
          if ((-1 < iVar1) && (unaff_RBP != (longlong *)0x0)) {
            plVar3 = (longlong *)HAWriteExportByName3(unaff_R14D,&stack0x00000040);
            (**(code **)(*unaff_RBP + 0x10))();
          }
          (**(code **)(*param_5 + 0x10))();
        }
      }
      else {
        plVar3 = (longlong *)HAWriteExportByName3(unaff_R14D,&stack0x00000040,0,0);
      }
      (**(code **)(*param_6 + 0x10))();
      if (plVar3 == (longlong *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = (**(code **)(*unaff_RDI + 0x278))();
      }
    }
  }
  else {
    uVar2 = (**(code **)(*param_1 + 0x280))(param_1,0x7d1);
  }
  return uVar2;
}

/* ---- FUNC 0001DEF9 FUN_18001def9 (31 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001def9(void)

{
  return;
}

/* ---- FUNC 0001DF20 FUN_18001df20 (86 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18001df20(longlong *param_1,undefined4 param_2,char *param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  ulonglong _Count;
  undefined1 auStack_158 [32];
  longlong *local_138 [2];
  char local_128 [256];
  ulonglong local_28;
  ulonglong uVar3;
  
  local_28 = DAT_180077818 ^ (ulonglong)auStack_158;
  if ((int)param_1[3] == 0) {
    uVar1 = (**(code **)(*param_1 + 0x280))(param_1,0x7d2);
  }
  else if (param_3 == (char *)0x0) {
    uVar1 = (**(code **)(*param_1 + 0x280))(param_1,0x7d1);
  }
  else {
    _Count = 0xffffffffffffffff;
    do {
      uVar3 = _Count;
      _Count = uVar3 + 1;
    } while (param_3[_Count] != '\0');
    if (_Count < 0x100) {
      (**(code **)(*param_1 + 0x90))(param_1,local_138);
      if (local_138[0] == (longlong *)0x0) {
        uVar1 = 0x80004005;
      }
      else {
        strncpy(local_128,param_3,_Count);
        local_128[uVar3 + 1] = '\0';
        lVar2 = HAWriteExportByName(param_2,local_128,local_138[0]);
        (**(code **)(*local_138[0] + 0x10))();
        if (lVar2 == 0) {
          uVar1 = 0;
        }
        else {
          uVar1 = (**(code **)(*param_1 + 0x278))(param_1,lVar2);
        }
      }
    }
    else {
      uVar1 = (**(code **)(*param_1 + 0x280))(param_1,0x7d1);
    }
  }
  return uVar1;
}

/* ---- FUNC 0001DF76 FUN_18001df76 (163 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18001df76(longlong *param_1,undefined8 param_2,longlong param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  ulonglong _Count;
  undefined4 unaff_EBP;
  char *unaff_RSI;
  longlong *unaff_RDI;
  longlong *plStackX_20;
  ulonglong uVar3;
  
  _Count = 0xffffffffffffffff;
  do {
    uVar3 = _Count;
    _Count = uVar3 + 1;
  } while (*(char *)(param_3 + _Count) != '\0');
  if (_Count < 0x100) {
    (**(code **)(*param_1 + 0x90))(param_1,&plStackX_20);
    if (plStackX_20 == (longlong *)0x0) {
      uVar1 = 0x80004005;
    }
    else {
      strncpy(&stack0x00000030,unaff_RSI,_Count);
      (&stack0x00000031)[uVar3] = 0;
      lVar2 = HAWriteExportByName(unaff_EBP,&stack0x00000030,plStackX_20);
      (**(code **)(*plStackX_20 + 0x10))();
      if (lVar2 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = (**(code **)(*unaff_RDI + 0x278))();
      }
    }
  }
  else {
    uVar1 = (**(code **)(*param_1 + 0x280))(param_1,0x7d1);
  }
  return uVar1;
}

/* ---- FUNC 0001E019 FUN_18001e019 (27 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001e019(void)

{
  return;
}

/* ---- FUNC 0001E040 FUN_18001e040 (64 bytes) ---- */

void FUN_18001e040(longlong *param_1,undefined8 *param_2)

{
  int iVar1;
  
  *param_2 = 0;
  iVar1 = (**(code **)*param_1)(param_1,&DAT_180066c78,param_2);
  if (iVar1 < 0) {
                    /* WARNING: Could not recover jumptable at 0x00018001e073. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x280))(param_1,0x7d1);
    return;
  }
  return;
}

/* ---- FUNC 0001E080 FUN_18001e080 (59 bytes) ---- */

undefined8 FUN_18001e080(undefined8 param_1,short param_2,undefined2 *param_3)

{
  CPaletteCategory *pCVar1;
  
  pCVar1 = CApwnLibraries::GetCategory(*(CApwnLibraries **)g_pApwnLibs_exref,(int)param_2);
  if (pCVar1 != (CPaletteCategory *)0x0) {
    *param_3 = *(undefined2 *)(pCVar1 + 0x40);
    return 0;
  }
  return 0x80004005;
}

/* ---- FUNC 0001E0C0 FUN_18001e0c0 (69 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18001e0c0(undefined8 param_1,short param_2,undefined8 *param_3)

{
  int cchWideChar;
  int iVar1;
  CPaletteCategory *pCVar2;
  BSTR lpWideCharStr;
  undefined8 uVar3;
  undefined1 auStackY_98 [32];
  CHAR local_68 [80];
  ulonglong local_18;
  
  local_18 = DAT_180077818 ^ (ulonglong)auStackY_98;
  pCVar2 = CApwnLibraries::GetCategory(*(CApwnLibraries **)g_pApwnLibs_exref,(int)param_2);
  if (pCVar2 == (CPaletteCategory *)0x0) {
    uVar3 = 0x80004005;
  }
  else {
    (**(code **)(*(longlong *)pCVar2 + 0x18))(pCVar2,local_68,0x50);
    cchWideChar = MultiByteToWideChar(0,0,local_68,-1,(LPWSTR)0x0,0);
    lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,cchWideChar - 1);
    if (lpWideCharStr != (BSTR)0x0) {
      iVar1 = MultiByteToWideChar(0,0,local_68,-1,lpWideCharStr,cchWideChar);
      if (iVar1 != cchWideChar) {
        SysFreeString(lpWideCharStr);
        lpWideCharStr = (BSTR)0x0;
      }
    }
    uVar3 = 0;
    *param_3 = lpWideCharStr;
  }
  return uVar3;
}

/* ---- FUNC 0001E105 FUN_18001e105 (152 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18001e105(undefined8 param_1,undefined8 param_2)

{
  int cchWideChar;
  int iVar1;
  longlong in_RAX;
  BSTR lpWideCharStr;
  undefined8 *unaff_RSI;
  
  (**(code **)(in_RAX + 0x18))(param_1,param_2,0x50);
  cchWideChar = MultiByteToWideChar(0,0,&stack0x00000030,-1,(LPWSTR)0x0,0);
  lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,cchWideChar - 1);
  if (lpWideCharStr != (BSTR)0x0) {
    iVar1 = MultiByteToWideChar(0,0,&stack0x00000030,-1,lpWideCharStr,cchWideChar);
    if (iVar1 != cchWideChar) {
      SysFreeString(lpWideCharStr);
      lpWideCharStr = (BSTR)0x0;
    }
  }
  *unaff_RSI = lpWideCharStr;
  return 0;
}

/* ---- FUNC 0001E19D FUN_18001e19d (30 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18001e19d(void)

{
  return 0x80004005;
}

/* ---- FUNC 0001E1C0 FUN_18001e1c0 (324 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char * FUN_18001e1c0(undefined8 param_1,LPCWSTR param_2,undefined2 *param_3)

{
  char *pcVar1;
  CApwnLibraries *this;
  longlong lVar2;
  char *pcVar4;
  CPaletteCategory *pCVar5;
  ulonglong uVar6;
  char *pcVar7;
  undefined1 *puVar8;
  int iVar9;
  undefined8 uStack_60;
  undefined1 auStack_58 [32];
  undefined8 uStack_38;
  int aiStack_30 [2];
  undefined8 local_28 [2];
  longlong local_18;
  ulonglong local_10;
  longlong lVar3;
  
  local_10 = DAT_180077818 ^ (ulonglong)&local_18;
  pcVar7 = (char *)0x0;
  puVar8 = auStack_58;
  pcVar4 = pcVar7;
  if (param_2 != (LPCWSTR)0x0) {
    lVar2 = -1;
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_2[lVar2] != L'\0');
    iVar9 = (int)lVar3 + 2;
    puVar8 = auStack_58;
    if (iVar9 < 0x40000000) {
      lVar2 = (longlong)(int)lVar2 * 2;
      uVar6 = lVar2 + 0x11;
      if (uVar6 <= lVar2 + 2U) {
        uVar6 = 0xffffffffffffff0;
      }
      uStack_60 = 0x18001e23f;
      lVar2 = -(uVar6 & 0xfffffffffffffff0);
      pcVar1 = (char *)((longlong)&local_18 + lVar2);
      puVar8 = auStack_58 + lVar2;
      if (pcVar1 != (char *)0x0) {
        *pcVar1 = '\0';
        *(undefined8 *)((longlong)local_28 + lVar2 + 8) = 0;
        *(undefined8 *)((longlong)local_28 + lVar2) = 0;
        *(int *)((longlong)aiStack_30 + lVar2) = iVar9 * 2;
        *(char **)((longlong)&uStack_38 + lVar2) = pcVar1;
        *(undefined8 *)(auStack_58 + lVar2 + -8) = 0x18001e278;
        iVar9 = WideCharToMultiByte(0,0,param_2,-1,*(LPSTR *)((longlong)&uStack_38 + lVar2),
                                    *(int *)((longlong)aiStack_30 + lVar2),
                                    *(LPCSTR *)((longlong)local_28 + lVar2),
                                    *(LPBOOL *)((longlong)local_28 + lVar2 + 8));
        puVar8 = auStack_58 + lVar2;
        pcVar4 = pcVar1;
        if (iVar9 == 0) {
          puVar8 = auStack_58 + lVar2;
          pcVar4 = pcVar7;
        }
      }
    }
  }
  *(undefined8 *)(puVar8 + -8) = 0x18001e290;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_18,pcVar4);
  iVar9 = *(int *)(local_18 + -0x10);
  *(undefined8 *)(puVar8 + -8) = 0x18001e2a2;
  pcVar4 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)&local_18,iVar9);
  this = *(CApwnLibraries **)g_pApwnLibs_exref;
  *(undefined8 *)(puVar8 + -8) = 0x18001e2b5;
  pCVar5 = CApwnLibraries::GetCategory(this,pcVar4);
  *(undefined8 *)(puVar8 + -8) = 0x18001e2c7;
  ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_18,-1);
  if (pCVar5 == (CPaletteCategory *)0x0) {
    pcVar7 = (char *)0x80004005;
  }
  else {
    *param_3 = *(undefined2 *)(pCVar5 + 0x40);
  }
  *(undefined8 *)(puVar8 + -8) = 0x18001e2e4;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_18);
  *(undefined8 *)(puVar8 + -8) = 0x18001e2f2;
  return pcVar7;
}

/* ---- FUNC 0001E310 FUN_18001e310 (1242 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Exceeded maximum restarts with more pending */

LPCOLESTR FUN_18001e310(IUnknownVtbl *param_1,undefined2 *param_2,void **param_3)

{
  LPCOLESTR pOVar1;
  wchar_t *pwVar2;
  code *pcVar3;
  _func_5320 *p_Var4;
  _func_5157 *p_Var5;
  void *_Memory;
  _func_5156 *p_Var6;
  IMoniker *pIVar7;
  _func_5158 **pp_Var8;
  int iVar9;
  uint uVar10;
  LPCOLESTR pOVar11;
  HWND hWnd;
  longlong lVar12;
  char *pcVar13;
  longlong lVar14;
  ulonglong uVar15;
  IUnknown *pIVar16;
  char *_Str;
  undefined1 *puVar17;
  undefined1 *puVar18;
  LPCOLESTR pOVar19;
  LPCOLESTR pOVar20;
  _func_5158 *p_Var21;
  undefined8 *_Memory_00;
  undefined1 auStackY_118 [32];
  IUnknown *local_b8;
  undefined8 *local_b0;
  WPARAM local_a8;
  IMoniker *local_a0;
  _func_5158 **local_98;
  IUnknown *local_90;
  char *local_88;
  _func_5158 *local_80;
  undefined8 *local_78;
  tagMSG local_70;
  ulonglong local_40;
  
  local_40 = DAT_180077818 ^ (ulonglong)&local_b8;
  if (DAT_1800797f8 == 0) {
    pOVar19 = (LPCOLESTR)0x0;
    *param_2 = 0;
    hWnd = CreateWindowExA(0,"VarExplClass","Variable Explorer",0xcf0000,-0x80000000,0,-0x80000000,0
                           ,(HWND)0x0,(HMENU)0x0,DAT_1800797d8,(LPVOID)0x0);
    pOVar11 = (LPCOLESTR)0x0;
    puVar18 = auStackY_118;
    if (hWnd != (HWND)0x0) {
      SetWindowLongPtrA(hWnd,-0x15,(LONG_PTR)param_1);
      ShowWindow(hWnd,1);
      UpdateWindow(hWnd);
      if (param_1[1].AddRef != (_func_5157 *)0x0) {
        FUN_180021eb0(hWnd,DAT_1800797d8,param_1[1].AddRef);
        iVar9 = GetMessageA(&local_70,(HWND)0x0,0,0);
        _Memory_00 = local_b0;
        while (iVar9 != 0) {
          if (local_70.message == 0x400) {
            _Memory_00 = (undefined8 *)local_70.lParam;
            local_a8 = local_70.wParam;
          }
          TranslateMessage(&local_70);
          DispatchMessageA(&local_70);
          iVar9 = GetMessageA(&local_70,(HWND)0x0,0,0);
        }
        if (_Memory_00 != (undefined8 *)0x0) {
          if (*(int *)&param_1[1].QueryInterface == 0) {
            pOVar11 = (LPCOLESTR)(**(code **)(param_1->QueryInterface + 0x280))(param_1,0x7d2);
            puVar18 = auStackY_118;
          }
          else {
            lVar12 = HAGetBptr(*_Memory_00,&local_90);
            if (lVar12 == 0) {
              pOVar11 = pOVar19;
              if (local_90 == (IUnknown *)0x0) {
                local_98 = &param_1[1].Release;
                FUN_1800387d0((IUnknownVtbl *)*_Memory_00,(longlong *)&local_b8,param_1,param_1,1,
                              (IUnknownVtbl *)*local_98);
                local_78 = _Memory_00 + 1;
                _Str = (char *)*local_78;
                p_Var21 = param_1[0xb].Release;
                puVar17 = auStackY_118;
                while( true ) {
                  *(undefined8 *)(puVar17 + -8) = 0x18001e58f;
                  pcVar13 = strstr(_Str,"!");
                  if (pcVar13 == (char *)0x0) break;
                  *(undefined8 *)(puVar17 + -8) = 0x18001e5a7;
                  pcVar13 = strstr(_Str,"!");
                  local_88 = pcVar13;
                  *pcVar13 = '\0';
                  puVar18 = puVar17;
                  pOVar20 = pOVar19;
                  if (_Str != (char *)0x0) {
                    lVar12 = -1;
                    do {
                      lVar14 = lVar12;
                      lVar12 = lVar14 + 1;
                    } while (_Str[lVar12] != '\0');
                    iVar9 = (int)lVar14 + 2;
                    if (iVar9 < 0x40000000) {
                      lVar12 = (longlong)(int)lVar12 * 2;
                      uVar15 = lVar12 + 0x11;
                      if (uVar15 <= lVar12 + 2U) {
                        uVar15 = 0xffffffffffffff0;
                      }
                      *(undefined8 *)(puVar17 + -8) = 0x18001e5f6;
                      lVar12 = -(uVar15 & 0xfffffffffffffff0);
                      pOVar1 = (LPCOLESTR)(puVar17 + lVar12 + 0x60);
                      puVar18 = puVar17 + lVar12;
                      if (pOVar1 != (LPCOLESTR)0x0) {
                        *pOVar1 = L'\0';
                        *(int *)(puVar17 + lVar12 + 0x28) = iVar9;
                        *(LPCOLESTR *)(puVar17 + lVar12 + 0x20) = pOVar1;
                        *(undefined8 *)(puVar17 + lVar12 + -8) = 0x18001e622;
                        iVar9 = MultiByteToWideChar(0,0,_Str,-1,*(LPWSTR *)(puVar17 + lVar12 + 0x20)
                                                    ,*(int *)(puVar17 + lVar12 + 0x28));
                        puVar18 = puVar17 + lVar12;
                        pOVar20 = pOVar1;
                        if (iVar9 == 0) {
                          puVar18 = puVar17 + lVar12;
                          pOVar20 = pOVar19;
                        }
                      }
                    }
                  }
                  *(undefined8 *)(puVar18 + -8) = 0x18001e641;
                  CreateItemMoniker(L"!",pOVar20,&local_a0);
                  pIVar7 = local_a0;
                  if (local_a0 != (IMoniker *)0x0) {
                    pcVar3 = *(code **)(*(longlong *)p_Var21 + 0x58);
                    *(undefined8 *)(puVar18 + -8) = 0x18001e65b;
                    (*pcVar3)(p_Var21,pIVar7,0,&local_80);
                    pIVar7 = local_a0;
                    p_Var4 = local_a0->lpVtbl->Release;
                    *(undefined8 *)(puVar18 + -8) = 0x18001e67c;
                    (*p_Var4)(pIVar7);
                    p_Var21 = local_80;
                  }
                  _Str = pcVar13 + 1;
                  puVar17 = puVar18;
                }
                puVar18 = puVar17;
                pOVar20 = pOVar19;
                if (_Str != (char *)0x0) {
                  lVar12 = -1;
                  do {
                    lVar14 = lVar12;
                    lVar12 = lVar14 + 1;
                  } while (_Str[lVar12] != '\0');
                  iVar9 = (int)lVar14 + 2;
                  if (iVar9 < 0x40000000) {
                    lVar12 = (longlong)(int)lVar12 * 2;
                    uVar15 = lVar12 + 0x11;
                    if (uVar15 <= lVar12 + 2U) {
                      uVar15 = 0xffffffffffffff0;
                    }
                    *(undefined8 *)(puVar17 + -8) = 0x18001e6cb;
                    lVar12 = -(uVar15 & 0xfffffffffffffff0);
                    pwVar2 = (wchar_t *)(puVar17 + lVar12 + 0x60);
                    puVar18 = puVar17 + lVar12;
                    if (pwVar2 != (wchar_t *)0x0) {
                      *pwVar2 = L'\0';
                      *(int *)(puVar17 + lVar12 + 0x28) = iVar9;
                      *(wchar_t **)(puVar17 + lVar12 + 0x20) = pwVar2;
                      *(undefined8 *)(puVar17 + lVar12 + -8) = 0x18001e6f7;
                      iVar9 = MultiByteToWideChar(0,0,_Str,-1,*(LPWSTR *)(puVar17 + lVar12 + 0x20),
                                                  *(int *)(puVar17 + lVar12 + 0x28));
                      puVar18 = puVar17 + lVar12;
                      pOVar20 = pwVar2;
                      if (iVar9 == 0) {
                        puVar18 = puVar17 + lVar12;
                        pOVar20 = pOVar19;
                      }
                    }
                  }
                }
                pIVar16 = local_b8;
                *(undefined8 *)(puVar18 + -8) = 0x18001e711;
                FUN_180038480((longlong)pIVar16,(longlong *)p_Var21,pOVar20);
                if (local_a8 == 2) {
                  *param_2 = 2;
                  p_Var5 = local_b8->lpVtbl[10].AddRef;
                  *(undefined8 *)(puVar18 + -8) = 0x18001e732;
                  (*p_Var5)();
                }
                _Memory = (void *)*local_78;
                if (_Memory != (void *)0x0) {
                  *(undefined8 *)(puVar18 + -8) = 0x18001e744;
                  free(_Memory);
                }
                *(undefined8 *)(puVar18 + -8) = 0x18001e74d;
                free(_Memory_00);
                pp_Var8 = local_98;
                if (local_b8 == (IUnknown *)0x0) {
                  DAT_1800797d4 = DAT_1800797d4 + 1;
                  p_Var21 = *local_98;
                  if (p_Var21 != (_func_5158 *)0x0) {
                    *(undefined8 *)(puVar18 + -8) = 0x18001e76a;
                    (*p_Var21)((IUnknown *)0x0);
                  }
                }
                pIVar16 = local_b8;
                DAT_1800797d4 = DAT_1800797d4 + 1;
                if (local_a8 == 1) {
                  p_Var6 = local_b8->lpVtbl->QueryInterface;
                  *(undefined8 *)(puVar18 + -8) = 0x18001e78e;
                  uVar10 = (*p_Var6)(pIVar16,(IID *)&DAT_180063400,param_3);
                  pOVar11 = (LPCOLESTR)(ulonglong)uVar10;
                  *param_2 = 1;
                  if ((int)uVar10 < 0) {
                    if (local_b8 != (IUnknown *)0x0) {
                      *(undefined8 *)(puVar18 + -8) = 0x18001e7ab;
                      FUN_180037ee0(local_b8);
                      *(undefined8 *)(puVar18 + -8) = 0x18001e7b8;
                      FUN_180025ad0(local_b8);
                      pIVar16 = local_b8;
                    }
                    p_Var21 = *pp_Var8;
                    if (p_Var21 != (_func_5158 *)0x0) {
                      *(undefined8 *)(puVar18 + -8) = 0x18001e7c2;
                      (*p_Var21)(pIVar16);
                    }
                  }
                }
              }
              else {
                local_b8 = local_90;
                uVar10 = (*local_90->lpVtbl->QueryInterface)(local_90,(IID *)&DAT_180063400,param_3)
                ;
                if (local_a8 == 2) {
                  (*local_b8->lpVtbl[10].AddRef)();
                  (*local_b8->lpVtbl->Release)();
                  *param_2 = 2;
                  puVar18 = auStackY_118;
                }
                else {
                  *param_2 = 1;
                  pOVar11 = (LPCOLESTR)(ulonglong)uVar10;
                  puVar18 = auStackY_118;
                }
              }
            }
            else {
              pOVar11 = (LPCOLESTR)(**(code **)(param_1->QueryInterface + 0x278))(param_1,lVar12);
              puVar18 = auStackY_118;
            }
          }
          goto LAB_18001e7c4;
        }
      }
      pOVar11 = (LPCOLESTR)(**(code **)(param_1->QueryInterface + 0x280))(param_1,0x7d1);
      puVar18 = auStackY_118;
    }
  }
  else {
    pOVar11 = (LPCOLESTR)(**(code **)(param_1->QueryInterface + 0x280))(param_1,0x7f3);
    puVar18 = auStackY_118;
  }
LAB_18001e7c4:
  *(undefined8 *)(puVar18 + -8) = 0x18001e7d0;
  return pOVar11;
}

