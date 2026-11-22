/* ---- FUNC 0001E7F0 FUN_18001e7f0 (11 bytes) ---- */

undefined8 FUN_18001e7f0(undefined8 param_1,undefined2 *param_2)

{
  *param_2 = 0;
  return 0x80004001;
}

/* ---- FUNC 0001E800 FUN_18001e800 (36 bytes) ---- */

undefined8 FUN_18001e800(undefined8 param_1,undefined2 *param_2)

{
  int iVar1;
  
  iVar1 = CApwnLibraries::CountLibraries(*(CApwnLibraries **)g_pApwnLibs_exref);
  *param_2 = (short)iVar1;
  return 0;
}

/* ---- FUNC 0001E830 FUN_18001e830 (27 bytes) ---- */

undefined8 FUN_18001e830(longlong *param_1,longlong *param_2)

{
  *param_2 = (longlong)(param_1 + 0x4b);
  (**(code **)(*param_1 + 8))();
  return 0;
}

/* ---- FUNC 0001E850 FUN_18001e850 (55 bytes) ---- */

undefined8 FUN_18001e850(longlong param_1,undefined4 param_2,undefined8 *param_3)

{
  LPCSTR lpMultiByteStr;
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  BSTR lpWideCharStr;
  LPCSTR local_res20;
  
  if (DAT_1800797f8 == 0) {
    local_res20 = (LPCSTR)0x0;
    iVar1 = Ordinal_73(param_2,&local_res20);
    lpMultiByteStr = local_res20;
    if (iVar1 != 0) {
      lpWideCharStr = (BSTR)0x0;
      if (local_res20 != (LPCSTR)0x0) {
        iVar1 = MultiByteToWideChar(0,0,local_res20,-1,(LPWSTR)0x0,0);
        lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,iVar1 - 1);
        if ((lpWideCharStr != (BSTR)0x0) &&
           (iVar2 = MultiByteToWideChar(0,0,lpMultiByteStr,-1,lpWideCharStr,iVar1), iVar2 != iVar1))
        {
          SysFreeString(lpWideCharStr);
          lpWideCharStr = (BSTR)0x0;
        }
      }
      *param_3 = lpWideCharStr;
    }
    if (local_res20 != (LPCSTR)0x0) {
      free(local_res20);
    }
    return 0;
  }
  uVar3 = (**(code **)(**(longlong **)(param_1 + 8) + 0x280))(*(longlong **)(param_1 + 8),0x7f3);
  return uVar3;
}

/* ---- FUNC 0001E887 FUN_18001e887 (28 bytes) ---- */

undefined8 FUN_18001e887(void)

{
  LPCSTR lpMultiByteStr;
  undefined4 in_EAX;
  int iVar1;
  int iVar2;
  BSTR lpWideCharStr;
  undefined8 *unaff_R14;
  LPCSTR pCStack0000000000000068;
  
  pCStack0000000000000068 = (LPCSTR)0x0;
  iVar1 = Ordinal_73(in_EAX);
  lpMultiByteStr = pCStack0000000000000068;
  if (iVar1 != 0) {
    lpWideCharStr = (BSTR)0x0;
    if (pCStack0000000000000068 != (LPCSTR)0x0) {
      iVar1 = MultiByteToWideChar(0,0,pCStack0000000000000068,-1,(LPWSTR)0x0,0);
      lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,iVar1 - 1);
      if ((lpWideCharStr != (BSTR)0x0) &&
         (iVar2 = MultiByteToWideChar(0,0,lpMultiByteStr,-1,lpWideCharStr,iVar1), iVar2 != iVar1)) {
        SysFreeString(lpWideCharStr);
        lpWideCharStr = (BSTR)0x0;
      }
    }
    *unaff_R14 = lpWideCharStr;
  }
  if (pCStack0000000000000068 != (LPCSTR)0x0) {
    free(pCStack0000000000000068);
  }
  return 0;
}

/* ---- FUNC 0001E8A3 FUN_18001e8a3 (124 bytes) ---- */

undefined8 FUN_18001e8a3(void)

{
  int cchWideChar;
  int iVar1;
  LPWSTR lpWideCharStr;
  LPCSTR unaff_RBX;
  void *_Memory;
  LPWSTR unaff_RDI;
  undefined8 *unaff_R14;
  void *in_stack_00000068;
  
  _Memory = (void *)0x0;
  lpWideCharStr = unaff_RDI;
  if (unaff_RBX != (LPCSTR)0x0) {
    iVar1 = (int)unaff_RDI;
    cchWideChar = MultiByteToWideChar(0,0,unaff_RBX,iVar1 + -1,unaff_RDI,iVar1);
    lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,cchWideChar - 1);
    _Memory = in_stack_00000068;
    if ((lpWideCharStr != (BSTR)0x0) &&
       (iVar1 = MultiByteToWideChar(0,0,unaff_RBX,iVar1 + -1,lpWideCharStr,cchWideChar),
       iVar1 != cchWideChar)) {
      SysFreeString(lpWideCharStr);
      lpWideCharStr = unaff_RDI;
    }
  }
  *unaff_R14 = lpWideCharStr;
  if (_Memory != (void *)0x0) {
    free(_Memory);
  }
  return 0;
}

/* ---- FUNC 0001E91F FUN_18001e91f (10 bytes) ---- */

undefined8 FUN_18001e91f(void)

{
  void *unaff_RBX;
  
  if (unaff_RBX != (void *)0x0) {
    free(unaff_RBX);
  }
  return 0;
}

/* ---- FUNC 0001E929 FUN_18001e929 (23 bytes) ---- */

undefined8 FUN_18001e929(void)

{
  void *unaff_RBX;
  
  free(unaff_RBX);
  return 0;
}

/* ---- FUNC 0001E940 FUN_18001e940 (8 bytes) ---- */

void FUN_18001e940(undefined8 param_1,undefined8 param_2)

{
  Ordinal_123(param_2);
  return;
}

/* ---- FUNC 0001E950 FUN_18001e950 (8 bytes) ---- */

void FUN_18001e950(undefined8 param_1,undefined8 param_2)

{
  Ordinal_119(param_2);
  return;
}

/* ---- FUNC 0001E960 FUN_18001e960 (41 bytes) ---- */

undefined8 FUN_18001e960(undefined8 param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  if (param_2 == (undefined8 *)0x0) {
    return 0x80070057;
  }
  uVar1 = MMWaitFailureMessage();
  *param_2 = uVar1;
  return 0;
}

/* ---- FUNC 0001E990 FUN_18001e990 (41 bytes) ---- */

undefined8 FUN_18001e990(undefined8 param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  if (param_2 == (undefined8 *)0x0) {
    return 0x80070057;
  }
  uVar1 = MMWaitFailureKey();
  *param_2 = uVar1;
  return 0;
}

/* ---- FUNC 0001E9C0 FUN_18001e9c0 (211 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18001e9c0(undefined8 param_1,undefined8 *param_2)

{
  int cchWideChar;
  int iVar1;
  BSTR lpWideCharStr;
  undefined1 auStackY_158 [32];
  CHAR local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_180077818 ^ (ulonglong)auStackY_158;
  GetModuleFileNameA((HMODULE)0x0,local_128,0x104);
  cchWideChar = MultiByteToWideChar(0,0,local_128,-1,(LPWSTR)0x0,0);
  lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,cchWideChar - 1);
  if ((lpWideCharStr != (BSTR)0x0) &&
     (iVar1 = MultiByteToWideChar(0,0,local_128,-1,lpWideCharStr,cchWideChar), iVar1 != cchWideChar)
     ) {
    SysFreeString(lpWideCharStr);
    *param_2 = 0;
    return 0;
  }
  *param_2 = lpWideCharStr;
  return 0;
}

/* ---- FUNC 0001EAA0 FUN_18001eaa0 (57 bytes) ---- */

undefined8 FUN_18001eaa0(longlong param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018001eac3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(**(longlong **)(param_1 + 8) + 0x280))(*(longlong **)(param_1 + 8),0x7f3);
    return uVar2;
  }
  uVar1 = Ordinal_82();
  *param_2 = uVar1;
  return 0;
}

/* ---- FUNC 0001EAE0 FUN_18001eae0 (33 bytes) ---- */

undefined8 FUN_18001eae0(undefined8 param_1,ushort *param_2)

{
  int iVar1;
  
  iVar1 = GRinqinmt();
  *param_2 = (ushort)(iVar1 == 1);
  return 0;
}

/* ---- FUNC 0001EB10 FUN_18001eb10 (27 bytes) ---- */

undefined8 FUN_18001eb10(longlong *param_1,longlong *param_2)

{
  *param_2 = (longlong)(param_1 + 0x48);
  (**(code **)(*param_1 + 8))();
  return 0;
}

/* ---- FUNC 0001EB30 FUN_18001eb30 (77 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_18001eb30(undefined8 param_1,short param_2,undefined8 *param_3)

{
  int iVar1;
  int cchWideChar;
  int iVar2;
  IAUserModelLibrary *pIVar3;
  BSTR lpWideCharStr;
  undefined1 auStackY_b8 [32];
  CHAR local_88 [80];
  ulonglong local_38;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStackY_b8;
  pIVar3 = CApwnLibraries::GetLibrary(*(CApwnLibraries **)g_pApwnLibs_exref,(int)param_2);
  if (pIVar3 == (IAUserModelLibrary *)0x0) {
    iVar1 = -0x7fffbffb;
  }
  else {
    iVar1 = (**(code **)(*(longlong *)pIVar3 + 0x38))(pIVar3,local_88,0x50);
    if (iVar1 == 0) {
      cchWideChar = MultiByteToWideChar(0,0,local_88,-1,(LPWSTR)0x0,0);
      lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,cchWideChar - 1);
      if ((lpWideCharStr != (BSTR)0x0) &&
         (iVar2 = MultiByteToWideChar(0,0,local_88,-1,lpWideCharStr,cchWideChar),
         iVar2 != cchWideChar)) {
        SysFreeString(lpWideCharStr);
        lpWideCharStr = (BSTR)0x0;
      }
      *param_3 = lpWideCharStr;
    }
    (**(code **)(*(longlong *)pIVar3 + 0x10))(pIVar3);
  }
  return iVar1;
}

/* ---- FUNC 0001EB7D FUN_18001eb7d (25 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_18001eb7d(void)

{
  int iVar1;
  int cchWideChar;
  int iVar2;
  BSTR lpWideCharStr;
  longlong *unaff_RBX;
  longlong in_R9;
  undefined8 *unaff_R15;
  
  iVar1 = (**(code **)(in_R9 + 0x38))();
  if (iVar1 == 0) {
    cchWideChar = MultiByteToWideChar(0,0,&stack0x00000030,-1,(LPWSTR)0x0,0);
    lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,cchWideChar - 1);
    if ((lpWideCharStr != (BSTR)0x0) &&
       (iVar2 = MultiByteToWideChar(0,0,&stack0x00000030,-1,lpWideCharStr,cchWideChar),
       iVar2 != cchWideChar)) {
      SysFreeString(lpWideCharStr);
      lpWideCharStr = (BSTR)0x0;
    }
    *unaff_R15 = lpWideCharStr;
  }
  (**(code **)(*unaff_RBX + 0x10))();
  return iVar1;
}

/* ---- FUNC 0001EB96 FUN_18001eb96 (151 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_18001eb96(void)

{
  int in_EAX;
  int cchWideChar;
  int iVar1;
  BSTR lpWideCharStr;
  longlong *unaff_RBX;
  int unaff_EBP;
  undefined8 *unaff_R15;
  
  cchWideChar = MultiByteToWideChar(0,0,&stack0x00000030,in_EAX + -1,(LPWSTR)0x0,0);
  lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,cchWideChar - 1);
  if ((lpWideCharStr != (BSTR)0x0) &&
     (iVar1 = MultiByteToWideChar(0,0,&stack0x00000030,unaff_EBP + -1,lpWideCharStr,cchWideChar),
     iVar1 != cchWideChar)) {
    SysFreeString(lpWideCharStr);
    lpWideCharStr = (BSTR)0x0;
  }
  *unaff_R15 = lpWideCharStr;
  (**(code **)(*unaff_RBX + 0x10))();
  return unaff_EBP;
}

/* ---- FUNC 0001EC2D FUN_18001ec2d (21 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_18001ec2d(void)

{
  longlong *unaff_RBX;
  undefined4 unaff_EBP;
  
  (**(code **)(*unaff_RBX + 0x10))();
  return unaff_EBP;
}

/* ---- FUNC 0001EC42 FUN_18001ec42 (32 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18001ec42(void)

{
  return 0x80004005;
}

/* ---- FUNC 0001EC70 FUN_18001ec70 (283 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_18001ec70(undefined8 param_1,short param_2,undefined8 *param_3)

{
  int iVar1;
  IAUserModelLibrary *pIVar2;
  BSTR pOVar3;
  undefined4 uVar4;
  undefined1 auStack_f8 [32];
  undefined4 *local_d8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_c8 [8];
  undefined4 local_c0;
  undefined4 local_bc;
  char local_b8 [80];
  CHAR local_68 [80];
  ulonglong local_18;
  
  local_18 = DAT_180077818 ^ (ulonglong)auStack_f8;
  uVar4 = 0;
  pIVar2 = CApwnLibraries::GetLibrary(*(CApwnLibraries **)g_pApwnLibs_exref,(int)param_2);
  if (pIVar2 == (IAUserModelLibrary *)0x0) {
    uVar4 = 0x80004005;
  }
  else {
    (**(code **)(*(longlong *)pIVar2 + 0x38))(pIVar2,local_b8,0x50);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_c8,local_b8);
    iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                      (local_c8,"Built-In");
    if ((iVar1 == 0) ||
       (iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                          (local_c8,"CAPE-OPEN"), iVar1 == 0)) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_c8);
      uVar4 = 0;
    }
    else {
      local_bc = 0;
      local_c0 = 0;
      local_d8 = &local_c0;
      iVar1 = APModLibGetValues(local_b8,local_68,0x50,&local_bc);
      if (iVar1 == 0) {
        uVar4 = 0x80004005;
      }
      else {
        pOVar3 = FUN_1800019d0(local_68);
        *param_3 = pOVar3;
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_c8);
    }
  }
  return uVar4;
}

/* ---- FUNC 0001ED90 FUN_18001ed90 (28 bytes) ---- */

undefined8 FUN_18001ed90(void)

{
  undefined8 uVar1;
  
  if (DAT_180079800 == (longlong *)0x0) {
    return 0x80004005;
  }
                    /* WARNING: Could not recover jumptable at 0x00018001eda5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*DAT_180079800 + 0x128))();
  return uVar1;
}

/* ---- FUNC 0001EDB0 FUN_18001edb0 (92 bytes) ---- */

undefined8 FUN_18001edb0(undefined8 param_1,undefined8 *param_2)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  BSTR pOVar2;
  LPCSTR local_res10;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res18 [16];
  
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10);
  pCVar1 = FUN_180020fe0(local_res18,1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10,
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
  pOVar2 = FUN_1800019d0(local_res10);
  *param_2 = pOVar2;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10);
  return 0;
}

/* ---- FUNC 0001EE10 FUN_18001ee10 (2863 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

_union_1719 * FUN_18001ee10(longlong *param_1,VARIANTARG *param_2,int param_3,undefined8 *param_4)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  _union_1719 *p_Var1;
  VARTYPE VVar2;
  code *pcVar3;
  longlong *plVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined1 *puVar10;
  HRESULT HVar11;
  uint uVar12;
  int iVar13;
  longlong lVar14;
  undefined8 *puVar15;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar16;
  LPCOLESTR pOVar17;
  undefined4 *puVar18;
  ulonglong uVar19;
  int iVar20;
  undefined4 uVar21;
  char *pcVar22;
  _union_1719 *p_Var23;
  undefined1 *puVar24;
  _union_1719 *p_Var25;
  _union_1719 _Var26;
  char *pcVar27;
  _union_1719 *p_Var28;
  undefined8 uStack_7e0;
  undefined1 auStack_7d8 [32];
  undefined8 uStack_7b8;
  int aiStack_7b0 [2];
  undefined8 local_7a8 [4];
  _union_1719 local_788;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_780 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_778 [8];
  int local_770;
  int local_76c;
  int local_768;
  undefined4 local_764;
  longlong *local_760;
  _union_2707 local_758;
  _union_2707 local_740;
  _union_2707 local_728;
  _union_2707 local_710;
  undefined8 local_6f8;
  _union_1719 _Stack_6f0;
  undefined8 local_6e8;
  undefined8 local_6d8;
  _union_1719 _Stack_6d0;
  undefined8 local_6c8;
  undefined8 local_6b8;
  _union_1719 _Stack_6b0;
  undefined8 local_6a8;
  undefined8 local_698;
  _union_1719 _Stack_690;
  undefined8 local_688;
  undefined8 local_678;
  _union_1719 _Stack_670;
  undefined8 local_668;
  _union_2707 local_658;
  _union_2707 local_640;
  _union_2707 local_628;
  undefined8 local_608;
  undefined8 uStack_600;
  undefined8 local_5f8;
  undefined8 local_5e8;
  undefined8 uStack_5e0;
  undefined8 local_5d8;
  undefined1 local_5c8 [24];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_5b0 [8];
  undefined4 local_5a8;
  ULONG UStack_5a4;
  undefined4 uStack_5a0;
  undefined4 uStack_59c;
  undefined8 local_598;
  IID local_588;
  char local_578 [80];
  char local_528 [80];
  char local_4d8 [80];
  char local_488 [80];
  undefined1 local_438 [1008];
  ulonglong local_48;
  
  puVar24 = auStack_7d8;
  this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(local_7a8 + 4);
  local_48 = DAT_180077818 ^ (ulonglong)this;
  p_Var25 = (_union_1719 *)0x0;
  *param_4 = 0;
  uStack_7e0 = 0x18001ee66;
  local_76c = param_3;
  local_760 = param_1;
  VariantInit((VARIANTARG *)local_5c8);
  uStack_7e0 = 0x18001ee73;
  VariantInit((VARIANTARG *)&local_628.n2);
  local_628.n2.vt = 0;
  uStack_7e0 = 0x18001ee8b;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this,"");
  uStack_7e0 = 0x18001ee95;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_778);
  VVar2 = (param_2->n1).n2.vt;
  pcVar27 = ".aprt";
  puVar10 = auStack_7d8;
  p_Var28 = p_Var25;
  if (VVar2 != 0) {
    p_Var23 = p_Var25;
    if (VVar2 == 8) {
      _Var26 = (_union_1719)((_union_1719 *)((longlong)&param_2->n1 + 8))->Lo64;
      p_Var28 = (_union_1719 *)((longlong)&param_2->n1 + 8);
      puVar24 = auStack_7d8;
      if ((LPCWSTR)_Var26.Lo64 != (LPCWSTR)0x0) {
        lVar14 = -1;
        do {
          lVar14 = lVar14 + 1;
        } while (*(LPCWSTR)(_Var26.Lo64 + lVar14 * 2) != L'\0');
        goto LAB_18001ef7a;
      }
    }
    else {
      puVar10 = auStack_7d8;
      p_Var28 = (_union_1719 *)0x0;
      if (VVar2 == 10) goto LAB_18001f147;
      if (VVar2 == 0x4008) {
        p_Var28 = *(_union_1719 **)((longlong)&param_2->n1 + 8);
        _Var26 = (_union_1719)p_Var28->Lo64;
        puVar24 = auStack_7d8;
        if ((LPCWSTR)_Var26.Lo64 != (LPCWSTR)0x0) {
          lVar14 = -1;
          do {
            lVar14 = lVar14 + 1;
          } while (*(LPCWSTR)(_Var26.Lo64 + lVar14 * 2) != L'\0');
LAB_18001ef7a:
          iVar20 = (int)lVar14 + 1;
          puVar24 = auStack_7d8;
          if (iVar20 < 0x40000000) {
            lVar14 = (longlong)(int)lVar14 * 2;
            uVar19 = lVar14 + 0x11;
            if (uVar19 <= lVar14 + 2U) {
              uVar19 = 0xffffffffffffff0;
            }
            uStack_7e0 = 0x18001efae;
            lVar14 = -(uVar19 & 0xfffffffffffffff0);
            p_Var1 = (_union_1719 *)(local_780 + lVar14 + -8);
            puVar24 = auStack_7d8 + lVar14;
            if (p_Var1 != (_union_1719 *)0x0) {
              *(undefined8 *)((longlong)local_7a8 + lVar14 + 8) = 0;
              *(undefined8 *)((longlong)local_7a8 + lVar14) = 0;
              *(int *)((longlong)aiStack_7b0 + lVar14) = iVar20 * 2;
              *(undefined1 *)p_Var1 = 0;
              *(_union_1719 **)((longlong)&uStack_7b8 + lVar14) = p_Var1;
              *(undefined8 *)(auStack_7d8 + lVar14 + -8) = 0x18001efe2;
              iVar20 = WideCharToMultiByte(0,0,(LPCWSTR)_Var26,-1,
                                           *(LPSTR *)((longlong)&uStack_7b8 + lVar14),
                                           *(int *)((longlong)aiStack_7b0 + lVar14),
                                           *(LPCSTR *)((longlong)local_7a8 + lVar14),
                                           *(LPBOOL *)((longlong)local_7a8 + lVar14 + 8));
              p_Var23 = p_Var1;
              puVar24 = auStack_7d8 + lVar14;
              if (iVar20 == 0) {
                p_Var23 = p_Var25;
                puVar24 = auStack_7d8 + lVar14;
              }
            }
          }
        }
      }
      else {
        uStack_7e0 = 0x18001eedf;
        HVar11 = VariantChangeType((VARIANTARG *)local_5c8,param_2,0,8);
        if (HVar11 < 0) {
          uStack_7e0 = 0x18001eef4;
          uVar12 = (**(code **)(*param_1 + 0x280))(param_1,0x7d4);
          p_Var25 = (_union_1719 *)(ulonglong)uVar12;
          goto LAB_18001f900;
        }
        p_Var28 = (_union_1719 *)(local_5c8 + 8);
        puVar24 = auStack_7d8;
        if (local_5c8._8_8_ != 0) {
          lVar14 = -1;
          do {
            lVar14 = lVar14 + 1;
            _Var26 = (_union_1719)local_5c8._8_8_;
          } while (*(LPCWSTR)(local_5c8._8_8_ + lVar14 * 2) != L'\0');
          goto LAB_18001ef7a;
        }
      }
    }
    *(undefined8 *)(puVar24 + -8) = 0x18001effa;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              (this,(char *)&p_Var23->Lo64);
    iVar20 = *(int *)(local_788.Lo64 + -0x10);
    *(undefined8 *)(puVar24 + -8) = 0x18001f00d;
    iVar13 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                       (this,'|');
    if (iVar13 == iVar20 + -2) {
      *(undefined8 *)(puVar24 + -8) = 0x18001f02a;
      puVar15 = (undefined8 *)
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Right
                          (this,(int)local_780);
      pcVar22 = (char *)*puVar15;
      *(undefined8 *)(puVar24 + -8) = 0x18001f033;
      atoi(pcVar22);
      *(undefined8 *)(puVar24 + -8) = 0x18001f03d;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_780);
      *(undefined8 *)(puVar24 + -8) = 0x18001f04e;
      pCVar16 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                          (this,(int)local_780);
      *(undefined8 *)(puVar24 + -8) = 0x18001f05b;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(this,pCVar16);
      *(undefined8 *)(puVar24 + -8) = 0x18001f065;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_780);
    }
    *(undefined8 *)(puVar24 + -8) = 0x18001f071;
    iVar20 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                       (this,'>');
    if (0 < iVar20) {
      *(undefined8 *)(puVar24 + -8) = 0x18001f086;
      pCVar16 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                          (this,(int)local_780);
      *(undefined8 *)(puVar24 + -8) = 0x18001f093;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(this,pCVar16);
      *(undefined8 *)(puVar24 + -8) = 0x18001f09d;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_780);
    }
    *(undefined8 *)(puVar24 + -8) = 0x18001f0a9;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind(this,'.');
    *(undefined8 *)(puVar24 + -8) = 0x18001f0ba;
    pCVar16 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                        (this,(int)local_780);
    *(undefined8 *)(puVar24 + -8) = 0x18001f0c7;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(local_778,pCVar16)
    ;
    *(undefined8 *)(puVar24 + -8) = 0x18001f0d1;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_780);
    pcVar3 = *(code **)(*DAT_180079800 + 0x78);
    *(undefined8 *)(puVar24 + -8) = 0x18001f0e2;
    (*pcVar3)(DAT_180079800,&local_770);
    puVar10 = puVar24;
    param_1 = local_760;
    if (*(int *)(local_788.Lo64 + -0x10) != 0) {
      *(undefined8 *)(puVar24 + -8) = 0x18001f0f0;
      iVar20 = MVGetProductCode();
      pcVar22 = ".aprt";
      if (iVar20 == 1) {
        pcVar22 = ".apt";
      }
      *(undefined8 *)(puVar24 + -8) = 0x18001f10b;
      iVar20 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                         (local_778,pcVar22);
      _Var26 = local_788;
      if ((iVar20 != 0) || (param_1 = local_760, local_770 == 0)) {
        *(undefined8 *)(puVar24 + -8) = 0x18001f120;
        pOVar17 = HappActivateRunningObject((LPCSTR)_Var26,param_4);
        param_1 = local_760;
        if ((int)pOVar17 != 0) {
          *(undefined8 *)(puVar24 + -8) = 0x18001f131;
          VariantClear((VARIANTARG *)local_5c8);
          *(undefined8 *)(puVar24 + -8) = 0x18001f13e;
          VariantClear((VARIANTARG *)&local_628.n2);
          goto LAB_18001f900;
        }
      }
    }
  }
LAB_18001f147:
  puVar24 = puVar10;
  pcVar3 = *(code **)(*DAT_180079800 + 0x138);
  *(undefined8 *)(puVar24 + -8) = 0x18001f15e;
  iVar20 = (*pcVar3)();
  if (iVar20 != 0) {
    *(undefined8 *)(puVar24 + -8) = 0x18001f182;
    FUN_180002a20(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\happ.cpp",0x499);
    *(undefined8 *)(puVar24 + -8) = 0x18001f198;
    LogMessage(local_438,2,1);
  }
  *(undefined8 **)(puVar24 + 0x20) = param_4;
  *(undefined8 *)(puVar24 + -8) = 0x18001f1b7;
  uVar12 = CoCreateInstance(&local_588,(LPUNKNOWN)0x0,4,(IID *)&DAT_180063460,
                            *(LPVOID **)(puVar24 + 0x20));
  if ((int)uVar12 < 0) {
    *(undefined8 *)(puVar24 + -8) = 0x18001f1ca;
    VariantClear((VARIANTARG *)local_5c8);
    *(undefined8 *)(puVar24 + -8) = 0x18001f1d7;
    VariantClear((VARIANTARG *)&local_628.n2);
    p_Var25 = (_union_1719 *)(ulonglong)uVar12;
    goto LAB_18001f900;
  }
  if (local_76c == 0) {
    pcVar3 = *(code **)(*(longlong *)*param_4 + 0x108);
    *(undefined8 *)(puVar24 + -8) = 0x18001f1ef;
    (*pcVar3)();
    *(undefined8 *)(puVar24 + -8) = 0x18001f1fb;
    puVar18 = (undefined4 *)GetGlobalPointer("DontShowUpward");
    plVar4 = (longlong *)*param_4;
    if (puVar18 == (undefined4 *)0x0) {
      uVar21 = 0;
    }
    else {
      uVar21 = *puVar18;
    }
    pcVar3 = *(code **)(*plVar4 + 0x138);
    *(undefined8 *)(puVar24 + -8) = 0x18001f213;
    (*pcVar3)(plVar4,uVar21);
    plVar4 = (longlong *)*param_4;
    pcVar3 = *(code **)(*plVar4 + 0x1c0);
    *(undefined8 *)(puVar24 + -8) = 0x18001f221;
    (*pcVar3)(plVar4,0);
  }
  *(undefined8 *)(puVar24 + -8) = 0x18001f22e;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_5b0);
  *(undefined8 *)(puVar24 + -8) = 0x18001f23b;
  VariantInit((VARIANTARG *)&local_640.n2);
  *(undefined8 *)(puVar24 + -8) = 0x18001f245;
  VariantInit((VARIANTARG *)&local_758.n2);
  *(undefined8 *)(puVar24 + -8) = 0x18001f24f;
  VariantInit((VARIANTARG *)&local_740.n2);
  *(undefined8 *)(puVar24 + -8) = 0x18001f259;
  VariantInit((VARIANTARG *)&local_728.n2);
  *(undefined8 *)(puVar24 + -8) = 0x18001f263;
  VariantInit((VARIANTARG *)&local_710.n2);
  *(undefined8 *)(puVar24 + -8) = 0x18001f270;
  VariantInit((VARIANTARG *)&local_658.n2);
  *(undefined4 *)(puVar24 + 0x30) = 0x50;
  *(undefined4 **)(puVar24 + 0x28) = &local_764;
  *(char **)(puVar24 + 0x20) = local_488;
  *(undefined8 *)(puVar24 + -8) = 0x18001f2ab;
  Ordinal_106(&local_768,local_578,local_528,local_4d8);
  if (local_768 != -1) {
    local_640._8_4_ = local_768;
    local_640.n2.vt = 3;
    local_658.n2.vt = 3;
    local_658._8_4_ = local_764;
    if (local_578[0] != '\0') {
      local_758.n2.vt = 8;
      *(undefined8 *)(puVar24 + -8) = 0x18001f2f5;
      local_758.decVal.u2 = (_union_1719)FUN_1800019d0(local_578);
    }
    if (local_528[0] != '\0') {
      local_740.n2.vt = 8;
      *(undefined8 *)(puVar24 + -8) = 0x18001f312;
      local_740.decVal.u2 = (_union_1719)FUN_1800019d0(local_528);
    }
    if (local_4d8[0] != '\0') {
      local_728.n2.vt = 8;
      *(undefined8 *)(puVar24 + -8) = 0x18001f32f;
      local_728.decVal.u2 = (_union_1719)FUN_1800019d0(local_4d8);
    }
    if (local_488[0] != '\0') {
      local_710.n2.vt = 8;
      *(undefined8 *)(puVar24 + -8) = 0x18001f34c;
      local_710.decVal.u2 = (_union_1719)FUN_1800019d0(local_488);
    }
  }
  if ((p_Var28 == (_union_1719 *)0x0) || (*(int *)(local_788.Lo64 + -0x10) == 0)) {
    uVar5 = CONCAT62(local_658._2_6_,local_658.n2.vt);
    uVar7 = CONCAT44(local_658._12_4_,local_658._8_4_);
    plVar4 = (longlong *)*param_4;
    *(undefined8 **)(puVar24 + 0x40) = &local_5e8;
    uVar8 = local_710.decVal.u2;
    uVar6 = CONCAT62(local_710._2_6_,local_710.n2.vt);
    lVar14 = *plVar4;
    local_5d8 = local_658._16_8_;
    local_5e8 = uVar5;
    uStack_5e0 = uVar7;
    *(undefined8 **)(puVar24 + 0x38) = &local_678;
    uVar7 = local_728.decVal.u2;
    _Stack_670 = (_union_1719)uVar8;
    uVar5 = CONCAT62(local_728._2_6_,local_728.n2.vt);
    local_678 = uVar6;
    *(undefined8 **)(puVar24 + 0x30) = &local_698;
    uVar8 = local_740.decVal.u2;
    local_668 = local_710._16_8_;
    _Stack_690 = (_union_1719)uVar7;
    uVar6 = CONCAT62(local_740._2_6_,local_740.n2.vt);
    local_698 = uVar5;
    *(undefined8 **)(puVar24 + 0x28) = &local_6b8;
    uVar7 = local_758.decVal.u2;
    local_688 = local_728._16_8_;
    _Stack_6b0 = (_union_1719)uVar8;
    uVar5 = CONCAT62(local_758._2_6_,local_758.n2.vt);
    local_6b8 = uVar6;
    *(undefined8 **)(puVar24 + 0x20) = &local_6d8;
    local_6a8 = local_740._16_8_;
    _Stack_6d0 = (_union_1719)uVar7;
    local_6f8 = CONCAT44(local_640.decVal.Hi32,CONCAT22(local_640.n2.wReserved1,local_640.n2.vt));
    _Stack_6f0.s2.Mid32 = local_640._12_4_;
    _Stack_6f0.s2.Lo32 = local_640._8_4_;
    local_6c8 = local_758._16_8_;
    local_608 = CONCAT44(local_628.decVal.Hi32,CONCAT22(local_628.n2.wReserved1,local_628.n2.vt));
    uStack_600 = CONCAT44(local_628._12_4_,local_628._8_4_);
    local_6e8 = local_640._16_8_;
    local_5a8 = *(undefined4 *)&param_2->n1;
    UStack_5a4 = (param_2->n1).decVal.Hi32;
    uStack_5a0 = *(undefined4 *)((longlong)&param_2->n1 + 8);
    uStack_59c = *(undefined4 *)((longlong)&param_2->n1 + 0xc);
    local_5f8 = local_628._16_8_;
    local_598 = *(undefined8 *)((longlong)&param_2->n1 + 0x10);
    pcVar3 = *(code **)(lVar14 + 0x188);
    local_6d8 = uVar5;
    *(undefined8 *)(puVar24 + -8) = 0x18001f88a;
    iVar20 = (*pcVar3)(plVar4,&local_5a8,&local_608,&local_6f8);
  }
  else {
    *(undefined8 *)(puVar24 + -8) = 0x18001f36e;
    iVar20 = MVGetProductCode();
    pcVar22 = ".aprt";
    if (iVar20 == 1) {
      pcVar22 = ".apt";
    }
    *(undefined8 *)(puVar24 + -8) = 0x18001f389;
    iVar20 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                       (local_778,pcVar22);
    if ((iVar20 == 0) && (local_770 == 1)) {
      uVar6 = CONCAT62(local_658._2_6_,local_658.n2.vt);
      uVar7 = CONCAT44(local_658._12_4_,local_658._8_4_);
      plVar4 = (longlong *)*param_4;
      *(undefined8 **)(puVar24 + 0x38) = &local_608;
      uVar9 = local_710.decVal.u2;
      uVar5 = CONCAT62(local_710._2_6_,local_710.n2.vt);
      lVar14 = *plVar4;
      local_5f8 = local_658._16_8_;
      local_608 = uVar6;
      uStack_600 = uVar7;
      *(undefined8 **)(puVar24 + 0x30) = &local_6f8;
      uVar8 = local_728.decVal.u2;
      _Stack_6f0 = (_union_1719)uVar9;
      uVar6 = CONCAT62(local_728._2_6_,local_728.n2.vt);
      local_6f8 = uVar5;
      *(undefined8 **)(puVar24 + 0x28) = &local_6d8;
      uVar7 = local_740.decVal.u2;
      local_6e8 = local_710._16_8_;
      _Stack_6d0 = (_union_1719)uVar8;
      uVar5 = CONCAT62(local_740._2_6_,local_740.n2.vt);
      local_6d8 = uVar6;
      *(undefined8 **)(puVar24 + 0x20) = &local_6b8;
      local_6c8 = local_728._16_8_;
      _Stack_6b0 = (_union_1719)uVar7;
      local_698 = CONCAT62(local_758._2_6_,local_758.n2.vt);
      local_6a8 = local_740._16_8_;
      _Stack_690 = local_758.decVal.u2;
      local_688 = local_758._16_8_;
      local_678 = CONCAT44(local_640.decVal.Hi32,CONCAT22(local_640.n2.wReserved1,local_640.n2.vt));
      _Stack_670.s2.Mid32 = local_640._12_4_;
      _Stack_670.s2.Lo32 = local_640._8_4_;
      local_668 = local_640._16_8_;
      pcVar3 = *(code **)(lVar14 + 0x1a8);
      local_6b8 = uVar5;
      *(undefined8 *)(puVar24 + -8) = 0x18001f487;
      iVar20 = (*pcVar3)(plVar4,p_Var28,&local_678,&local_698);
    }
    else {
      *(undefined8 *)(puVar24 + -8) = 0x18001f491;
      iVar20 = MVGetProductCode();
      pcVar22 = ".aprbkp";
      if (iVar20 == 1) {
        pcVar22 = ".bkp";
      }
      *(undefined8 *)(puVar24 + -8) = 0x18001f4b0;
      iVar20 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                         (local_778,pcVar22);
      if (iVar20 != 0) {
        *(undefined8 *)(puVar24 + -8) = 0x18001f4bd;
        iVar20 = MVGetProductCode();
        if (iVar20 == 1) {
          pcVar27 = ".apt";
        }
        *(undefined8 *)(puVar24 + -8) = 0x18001f4d1;
        iVar20 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                           (local_778,pcVar27);
        if (iVar20 != 0) {
          *(undefined8 *)(puVar24 + -8) = 0x18001f4de;
          iVar20 = MVGetProductCode();
          pcVar27 = ".aprinp";
          if (iVar20 == 1) {
            pcVar27 = ".inp";
          }
          *(undefined8 *)(puVar24 + -8) = 0x18001f4fd;
          iVar20 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                             (local_778,pcVar27);
          if (iVar20 != 0) {
            *(undefined8 *)(puVar24 + -8) = 0x18001f50a;
            iVar20 = MVGetProductCode();
            pcVar27 = ".apropz";
            if (iVar20 == 1) {
              pcVar27 = ".apwz";
            }
            *(undefined8 *)(puVar24 + -8) = 0x18001f529;
            iVar20 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                     CompareNoCase(local_778,pcVar27);
            if (iVar20 != 0) {
              *(undefined8 *)(puVar24 + -8) = 0x18001f542;
              iVar20 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                       CompareNoCase(local_778,".pro");
              if (iVar20 != 0) {
                uVar5 = CONCAT62(local_658._2_6_,local_658.n2.vt);
                _Var26.s2.Mid32 = local_658._12_4_;
                _Var26.s2.Lo32 = local_658._8_4_;
                plVar4 = (longlong *)*param_4;
                *(undefined8 **)(puVar24 + 0x40) = &local_678;
                uVar8 = local_710.decVal.u2;
                uVar6 = CONCAT62(local_710._2_6_,local_710.n2.vt);
                lVar14 = *plVar4;
                local_678 = uVar5;
                _Stack_670 = _Var26;
                *(undefined8 **)(puVar24 + 0x38) = &local_698;
                uVar7 = local_728.decVal.u2;
                local_668 = local_658._16_8_;
                _Stack_690 = (_union_1719)uVar8;
                uVar5 = CONCAT62(local_728._2_6_,local_728.n2.vt);
                local_698 = uVar6;
                *(undefined8 **)(puVar24 + 0x30) = &local_6b8;
                uVar8 = local_740.decVal.u2;
                local_688 = local_710._16_8_;
                _Stack_6b0 = (_union_1719)uVar7;
                uVar6 = CONCAT62(local_740._2_6_,local_740.n2.vt);
                local_6b8 = uVar5;
                *(undefined8 **)(puVar24 + 0x28) = &local_6d8;
                uVar7 = local_758.decVal.u2;
                local_6a8 = local_728._16_8_;
                _Stack_6d0 = (_union_1719)uVar8;
                uVar5 = CONCAT62(local_758._2_6_,local_758.n2.vt);
                local_6d8 = uVar6;
                *(undefined8 **)(puVar24 + 0x20) = &local_6f8;
                local_6c8 = local_740._16_8_;
                _Stack_6f0 = (_union_1719)uVar7;
                local_608 = CONCAT44(local_640.decVal.Hi32,
                                     CONCAT22(local_640.n2.wReserved1,local_640.n2.vt));
                uStack_600 = CONCAT44(local_640._12_4_,local_640._8_4_);
                local_6e8 = local_758._16_8_;
                local_5f8 = local_640._16_8_;
                local_5e8 = CONCAT44(local_628.decVal.Hi32,
                                     CONCAT22(local_628.n2.wReserved1,local_628.n2.vt));
                uStack_5e0 = CONCAT44(local_628._12_4_,local_628._8_4_);
                local_5d8 = local_628._16_8_;
                pcVar3 = *(code **)(lVar14 + 400);
                local_6f8 = uVar5;
                *(undefined8 *)(puVar24 + -8) = 0x18001f660;
                iVar20 = (*pcVar3)(plVar4,p_Var28,&local_5e8,&local_608);
                goto LAB_18001f88a;
              }
            }
          }
        }
      }
      uVar6 = CONCAT62(local_658._2_6_,local_658.n2.vt);
      uVar7 = CONCAT44(local_658._12_4_,local_658._8_4_);
      plVar4 = (longlong *)*param_4;
      *(undefined8 **)(puVar24 + 0x38) = &local_5e8;
      uVar9 = local_710.decVal.u2;
      uVar5 = CONCAT62(local_710._2_6_,local_710.n2.vt);
      lVar14 = *plVar4;
      local_5d8 = local_658._16_8_;
      local_5e8 = uVar6;
      uStack_5e0 = uVar7;
      *(undefined8 **)(puVar24 + 0x30) = &local_678;
      uVar8 = local_728.decVal.u2;
      _Stack_670 = (_union_1719)uVar9;
      uVar6 = CONCAT62(local_728._2_6_,local_728.n2.vt);
      local_678 = uVar5;
      *(undefined8 **)(puVar24 + 0x28) = &local_698;
      uVar7 = local_740.decVal.u2;
      local_668 = local_710._16_8_;
      _Stack_690 = (_union_1719)uVar8;
      uVar5 = CONCAT62(local_740._2_6_,local_740.n2.vt);
      local_698 = uVar6;
      *(undefined8 **)(puVar24 + 0x20) = &local_6b8;
      local_688 = local_728._16_8_;
      _Stack_6b0 = (_union_1719)uVar7;
      local_6d8 = CONCAT62(local_758._2_6_,local_758.n2.vt);
      local_6a8 = local_740._16_8_;
      _Stack_6d0 = local_758.decVal.u2;
      local_6c8 = local_758._16_8_;
      local_6f8 = CONCAT44(local_640.decVal.Hi32,CONCAT22(local_640.n2.wReserved1,local_640.n2.vt));
      _Stack_6f0.s2.Mid32 = local_640._12_4_;
      _Stack_6f0.s2.Lo32 = local_640._8_4_;
      local_6e8 = local_640._16_8_;
      pcVar3 = *(code **)(lVar14 + 0x198);
      local_6b8 = uVar5;
      *(undefined8 *)(puVar24 + -8) = 0x18001f751;
      iVar20 = (*pcVar3)(plVar4,p_Var28,&local_6f8,&local_6d8);
    }
  }
LAB_18001f88a:
  *(undefined8 *)(puVar24 + -8) = 0x18001f899;
  VariantClear((VARIANTARG *)local_5c8);
  *(undefined8 *)(puVar24 + -8) = 0x18001f8a6;
  VariantClear((VARIANTARG *)&local_628.n2);
  *(undefined8 *)(puVar24 + -8) = 0x18001f8b0;
  VariantClear((VARIANTARG *)&local_758.n2);
  *(undefined8 *)(puVar24 + -8) = 0x18001f8ba;
  VariantClear((VARIANTARG *)&local_740.n2);
  *(undefined8 *)(puVar24 + -8) = 0x18001f8c4;
  VariantClear((VARIANTARG *)&local_728.n2);
  *(undefined8 *)(puVar24 + -8) = 0x18001f8ce;
  VariantClear((VARIANTARG *)&local_710.n2);
  uVar12 = 0;
  if (iVar20 != 0) {
    pcVar3 = *(code **)(*param_1 + 0x280);
    *(undefined8 *)(puVar24 + -8) = 0x18001f8e3;
    uVar12 = (*pcVar3)(param_1,0x7e4);
    pcVar3 = *(code **)(*(longlong *)*param_4 + 0x10);
    *(undefined8 *)(puVar24 + -8) = 0x18001f8ee;
    (*pcVar3)();
    *param_4 = 0;
  }
  p_Var25 = (_union_1719 *)(ulonglong)uVar12;
  *(undefined8 *)(puVar24 + -8) = 0x18001f900;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_5b0);
LAB_18001f900:
  *(undefined8 *)(puVar24 + -8) = 0x18001f90a;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_778);
  *(undefined8 *)(puVar24 + -8) = 0x18001f914;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this);
  *(undefined8 *)(puVar24 + -8) = 0x18001f925;
  return p_Var25;
}

/* ---- FUNC 0001F940 FUN_18001f940 (2650 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

_union_1719 *
FUN_18001f940(longlong *param_1,VARIANTARG *param_2,undefined8 *param_3,undefined8 *param_4,
             undefined8 *param_5,undefined8 *param_6,undefined8 *param_7,undefined8 *param_8,
             undefined8 *param_9)

{
  _union_1719 *p_Var1;
  VARTYPE VVar2;
  code *pcVar3;
  longlong *plVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  HRESULT HVar8;
  uint uVar9;
  int iVar10;
  _union_1719 *p_Var11;
  longlong lVar12;
  undefined8 *puVar13;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar14;
  LPCOLESTR pOVar15;
  ulonglong uVar16;
  int iVar17;
  char *pcVar18;
  _union_1719 *p_Var19;
  undefined1 *puVar20;
  undefined1 *puVar21;
  _union_1719 *p_Var22;
  _union_1719 _Var23;
  char *pcVar24;
  undefined8 uStackY_650;
  undefined1 auStackY_648 [32];
  _union_1719 local_5f8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_5f0 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_5e8 [8];
  int local_5e0 [2];
  undefined8 *local_5d8;
  undefined8 *local_5d0;
  undefined8 *local_5c8;
  undefined8 *local_5c0;
  undefined8 *local_5b8;
  undefined8 *local_5b0;
  _union_2707 local_5a8;
  _union_2707 local_588;
  _union_2707 local_568;
  _union_2707 local_548;
  _union_2707 local_528;
  longlong *local_508;
  _union_2707 local_4f8;
  _union_2707 local_4d8;
  undefined8 local_4b8;
  undefined8 uStack_4b0;
  undefined8 local_4a8;
  undefined1 local_498 [24];
  uint local_480 [2];
  undefined4 local_478;
  ULONG UStack_474;
  undefined4 uStack_470;
  undefined4 uStack_46c;
  undefined8 local_468;
  IID local_458;
  undefined1 local_448 [1008];
  ulonglong local_58;
  
  puVar20 = auStackY_648;
  local_58 = DAT_180077818 ^ (ulonglong)&local_5f8;
  p_Var22 = (_union_1719 *)0x0;
  local_4f8._0_8_ = *param_8;
  local_4f8.decVal.u2 = *(_union_1719 *)(param_8 + 1);
  local_4f8._16_8_ = param_8[2];
  local_5a8._0_8_ = *param_7;
  local_5a8.decVal.u2 = *(_union_1719 *)(param_7 + 1);
  local_5a8._16_8_ = param_7[2];
  local_588._0_8_ = *param_6;
  local_588.decVal.u2 = *(_union_1719 *)(param_6 + 1);
  local_588._16_8_ = param_6[2];
  local_568._0_8_ = *param_5;
  local_568.decVal.u2 = *(_union_1719 *)(param_5 + 1);
  local_5c0 = param_5;
  local_568._16_8_ = param_5[2];
  local_548._0_8_ = *param_4;
  local_548.decVal.u2 = *(_union_1719 *)(param_4 + 1);
  local_5c8 = param_6;
  local_548._16_8_ = param_4[2];
  local_528._0_8_ = *param_3;
  local_528.decVal.u2 = *(_union_1719 *)(param_3 + 1);
  local_5d0 = param_7;
  local_528._16_8_ = param_3[2];
  local_5d8 = param_8;
  *param_9 = 0;
  uStackY_650 = 0x18001fa89;
  local_5b8 = param_4;
  local_5b0 = param_3;
  local_508 = param_1;
  p_Var11 = (_union_1719 *)
            FUN_1800129c0(param_1,(VARIANTARG *)&local_528.n2,(VARIANTARG *)&local_548.n2,
                          (VARIANTARG *)&local_568.n2,(VARIANTARG *)&local_588.n2,
                          (VARIANTARG *)&local_5a8.n2,(VARIANTARG *)&local_4f8.n2,local_480);
  puVar21 = auStackY_648;
  if ((int)p_Var11 < 0) goto LAB_180020377;
  uStackY_650 = 0x18001faa1;
  VariantInit((VARIANTARG *)local_498);
  uStackY_650 = 0x18001faae;
  VariantInit((VARIANTARG *)&local_4d8.n2);
  local_4d8.n2.vt = 0;
  uStackY_650 = 0x18001fac6;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5f8.s2,"");
  uStackY_650 = 0x18001fad0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_5e8);
  VVar2 = (param_2->n1).n2.vt;
  pcVar24 = ".aprt";
  puVar21 = auStackY_648;
  p_Var11 = p_Var22;
  if (VVar2 == 0) goto LAB_18001fd7e;
  p_Var19 = p_Var22;
  if (VVar2 == 8) {
    _Var23 = (_union_1719)((_union_1719 *)((longlong)&param_2->n1 + 8))->Lo64;
    p_Var11 = (_union_1719 *)((longlong)&param_2->n1 + 8);
    puVar20 = auStackY_648;
    if ((LPCWSTR)_Var23.Lo64 != (LPCWSTR)0x0) {
      lVar12 = -1;
      do {
        lVar12 = lVar12 + 1;
      } while (*(LPCWSTR)(_Var23.Lo64 + lVar12 * 2) != L'\0');
      goto LAB_18001fbae;
    }
    goto LAB_18001fc21;
  }
  puVar21 = auStackY_648;
  p_Var11 = (_union_1719 *)0x0;
  if (VVar2 == 10) goto LAB_18001fd7e;
  if (VVar2 == 0x4008) {
    p_Var11 = *(_union_1719 **)((longlong)&param_2->n1 + 8);
    _Var23 = (_union_1719)p_Var11->Lo64;
    puVar20 = auStackY_648;
    if ((LPCWSTR)_Var23.Lo64 != (LPCWSTR)0x0) {
      lVar12 = -1;
      do {
        lVar12 = lVar12 + 1;
      } while (*(LPCWSTR)(_Var23.Lo64 + lVar12 * 2) != L'\0');
LAB_18001fbae:
      iVar17 = (int)lVar12 + 1;
      puVar20 = auStackY_648;
      if (iVar17 < 0x40000000) {
        lVar12 = (longlong)(int)lVar12 * 2;
        uVar16 = lVar12 + 0x11;
        if (uVar16 <= lVar12 + 2U) {
          uVar16 = 0xffffffffffffff0;
        }
        uStackY_650 = 0x18001fbe2;
        lVar12 = -(uVar16 & 0xfffffffffffffff0);
        p_Var1 = (_union_1719 *)(local_5f0 + lVar12 + -8);
        puVar20 = auStackY_648 + lVar12;
        if (p_Var1 != (_union_1719 *)0x0) {
          *(undefined8 *)(local_5f0 + lVar12 + -0x20) = 0;
          *(undefined8 *)(&stack0xfffffffffffff9e8 + lVar12) = 0;
          *(int *)(&stack0xfffffffffffff9e0 + lVar12) = iVar17 * 2;
          *(undefined1 *)p_Var1 = 0;
          *(_union_1719 **)(&stack0xfffffffffffff9d8 + lVar12) = p_Var1;
          *(undefined8 *)(auStackY_648 + lVar12 + -8) = 0x18001fc16;
          iVar17 = WideCharToMultiByte(0,0,(LPCWSTR)_Var23,-1,
                                       *(LPSTR *)(&stack0xfffffffffffff9d8 + lVar12),
                                       *(int *)(&stack0xfffffffffffff9e0 + lVar12),
                                       *(LPCSTR *)(&stack0xfffffffffffff9e8 + lVar12),
                                       *(LPBOOL *)(local_5f0 + lVar12 + -0x20));
          p_Var19 = p_Var1;
          puVar20 = auStackY_648 + lVar12;
          if (iVar17 == 0) {
            p_Var19 = p_Var22;
            puVar20 = auStackY_648 + lVar12;
          }
        }
      }
    }
LAB_18001fc21:
    *(undefined8 *)(puVar20 + -8) = 0x18001fc2e;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5f8.s2,
               (char *)&p_Var19->Lo64);
    iVar17 = *(int *)(local_5f8.Lo64 - 0x10);
    *(undefined8 *)(puVar20 + -8) = 0x18001fc41;
    iVar10 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                       ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                        &local_5f8.s2,'|');
    if (iVar10 == iVar17 + -2) {
      *(undefined8 *)(puVar20 + -8) = 0x18001fc5e;
      puVar13 = (undefined8 *)
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Right
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_5f8.s2,(int)local_5f0);
      pcVar18 = (char *)*puVar13;
      *(undefined8 *)(puVar20 + -8) = 0x18001fc67;
      atoi(pcVar18);
      *(undefined8 *)(puVar20 + -8) = 0x18001fc71;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_5f0);
      *(undefined8 *)(puVar20 + -8) = 0x18001fc82;
      pCVar14 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_5f8.s2,(int)local_5f0);
      *(undefined8 *)(puVar20 + -8) = 0x18001fc8f;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5f8.s2,
                 pCVar14);
      *(undefined8 *)(puVar20 + -8) = 0x18001fc99;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_5f0);
    }
    *(undefined8 *)(puVar20 + -8) = 0x18001fca5;
    iVar17 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                       ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                        &local_5f8.s2,'>');
    if (0 < iVar17) {
      *(undefined8 *)(puVar20 + -8) = 0x18001fcba;
      pCVar14 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_5f8.s2,(int)local_5f0);
      *(undefined8 *)(puVar20 + -8) = 0x18001fcc7;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5f8.s2,
                 pCVar14);
      *(undefined8 *)(puVar20 + -8) = 0x18001fcd1;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_5f0);
    }
    *(undefined8 *)(puVar20 + -8) = 0x18001fcdd;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5f8.s2,'.');
    *(undefined8 *)(puVar20 + -8) = 0x18001fcee;
    pCVar14 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         &local_5f8.s2,(int)local_5f0);
    *(undefined8 *)(puVar20 + -8) = 0x18001fcfb;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(local_5e8,pCVar14)
    ;
    *(undefined8 *)(puVar20 + -8) = 0x18001fd05;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_5f0);
    pcVar3 = *(code **)(*DAT_180079800 + 0x78);
    *(undefined8 *)(puVar20 + -8) = 0x18001fd16;
    (*pcVar3)(DAT_180079800,local_5e0);
    puVar21 = puVar20;
    param_1 = local_508;
    if (*(int *)(local_5f8.Lo64 - 0x10) != 0) {
      *(undefined8 *)(puVar20 + -8) = 0x18001fd24;
      iVar17 = MVGetProductCode();
      pcVar18 = ".aprt";
      if (iVar17 == 1) {
        pcVar18 = ".apt";
      }
      *(undefined8 *)(puVar20 + -8) = 0x18001fd3f;
      iVar17 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                         (local_5e8,pcVar18);
      _Var23 = local_5f8;
      if ((iVar17 != 0) || (param_1 = local_508, local_5e0[0] == 0)) {
        *(undefined8 *)(puVar20 + -8) = 0x18001fd54;
        pOVar15 = FUN_180023c20((LPCSTR)_Var23,param_9);
        param_1 = local_508;
        if ((int)pOVar15 != 0) {
          *(undefined8 *)(puVar20 + -8) = 0x18001fd65;
          VariantClear((VARIANTARG *)local_498);
          *(undefined8 *)(puVar20 + -8) = 0x18001fd72;
          VariantClear((VARIANTARG *)&local_4d8.n2);
          p_Var11 = p_Var22;
          goto LAB_180020361;
        }
      }
    }
LAB_18001fd7e:
    puVar20 = puVar21;
    pcVar3 = *(code **)(*DAT_180079800 + 0x138);
    *(undefined8 *)(puVar20 + -8) = 0x18001fd95;
    iVar17 = (*pcVar3)();
    if (iVar17 != 0) {
      *(undefined8 *)(puVar20 + -8) = 0x18001fdb9;
      FUN_180002a20(local_448,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\happ.cpp",0x401);
      *(undefined8 *)(puVar20 + -8) = 0x18001fdcf;
      LogMessage(local_448,2,1);
    }
    *(undefined8 **)(puVar20 + 0x20) = param_9;
    *(undefined8 *)(puVar20 + -8) = 0x18001fdee;
    uVar9 = CoCreateInstance(&local_458,(LPUNKNOWN)0x0,4,(IID *)&DAT_180063460,
                             *(LPVOID **)(puVar20 + 0x20));
    puVar13 = local_5d8;
    if ((int)uVar9 < 0) {
      *(undefined8 *)(puVar20 + -8) = 0x18001fe01;
      VariantClear((VARIANTARG *)local_498);
      *(undefined8 *)(puVar20 + -8) = 0x18001fe0e;
      VariantClear((VARIANTARG *)&local_4d8.n2);
    }
    else {
      if ((p_Var11 == (_union_1719 *)0x0) || (*(int *)(local_5f8.Lo64 - 0x10) == 0)) {
        plVar4 = (longlong *)*param_9;
        *(undefined8 **)(puVar20 + 0x40) = &local_4b8;
        uVar5 = *puVar13;
        uVar6 = puVar13[1];
        *(_union_2707 **)(puVar20 + 0x38) = &local_528;
        puVar7 = local_5d0;
        local_4a8 = puVar13[2];
        local_4b8 = uVar5;
        uStack_4b0 = uVar6;
        *(_union_2707 **)(puVar20 + 0x30) = &local_548;
        uVar5 = *puVar7;
        _Var23 = *(_union_1719 *)(puVar7 + 1);
        *(_union_2707 **)(puVar20 + 0x28) = &local_568;
        puVar13 = local_5c8;
        local_528._16_8_ = puVar7[2];
        local_528._0_8_ = uVar5;
        local_528.decVal.u2 = _Var23;
        *(_union_2707 **)(puVar20 + 0x20) = &local_588;
        local_548._0_8_ = *puVar13;
        local_548.decVal.u2 = *(_union_1719 *)(puVar13 + 1);
        local_548._16_8_ = puVar13[2];
        local_568._0_8_ = *local_5c0;
        local_568.decVal.u2 = *(_union_1719 *)(local_5c0 + 1);
        local_568._16_8_ = local_5c0[2];
        local_588._0_8_ = *local_5b8;
        local_588.decVal.u2 = *(_union_1719 *)(local_5b8 + 1);
        local_588._16_8_ = local_5b8[2];
        local_5a8._0_8_ = *local_5b0;
        local_5a8.decVal.u2 = *(_union_1719 *)(local_5b0 + 1);
        local_5a8._16_8_ = local_5b0[2];
        local_4f8._0_8_ =
             CONCAT44(local_4d8.decVal.Hi32,CONCAT22(local_4d8.n2.wReserved1,local_4d8.n2.vt));
        local_4f8._12_4_ = local_4d8._12_4_;
        local_4f8._8_4_ = local_4d8._8_4_;
        local_478 = *(undefined4 *)&param_2->n1;
        UStack_474 = (param_2->n1).decVal.Hi32;
        uStack_470 = *(undefined4 *)((longlong)&param_2->n1 + 8);
        uStack_46c = *(undefined4 *)((longlong)&param_2->n1 + 0xc);
        local_4f8._16_8_ = local_4d8._16_8_;
        local_468 = *(undefined8 *)((longlong)&param_2->n1 + 0x10);
        pcVar3 = *(code **)(*plVar4 + 0x188);
        *(undefined8 *)(puVar20 + -8) = 0x18002031e;
        iVar17 = (*pcVar3)(plVar4,&local_478,&local_4f8,&local_5a8);
      }
      else {
        *(undefined8 *)(puVar20 + -8) = 0x18001fe2e;
        iVar17 = MVGetProductCode();
        pcVar18 = ".aprt";
        if (iVar17 == 1) {
          pcVar18 = ".apt";
        }
        *(undefined8 *)(puVar20 + -8) = 0x18001fe49;
        iVar17 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                           (local_5e8,pcVar18);
        puVar13 = local_5d8;
        if ((iVar17 == 0) && (local_5e0[0] == 1)) {
          plVar4 = (longlong *)*param_9;
          *(_union_2707 **)(puVar20 + 0x38) = &local_528;
          uVar5 = *puVar13;
          _Var23 = *(_union_1719 *)(puVar13 + 1);
          *(_union_2707 **)(puVar20 + 0x30) = &local_548;
          puVar7 = local_5d0;
          local_528._16_8_ = puVar13[2];
          local_528._0_8_ = uVar5;
          local_528.decVal.u2 = _Var23;
          *(_union_2707 **)(puVar20 + 0x28) = &local_568;
          uVar5 = *puVar7;
          _Var23 = *(_union_1719 *)(puVar7 + 1);
          *(_union_2707 **)(puVar20 + 0x20) = &local_588;
          local_548._16_8_ = puVar7[2];
          local_568._0_8_ = *local_5c8;
          local_568.decVal.u2 = *(_union_1719 *)(local_5c8 + 1);
          local_568._16_8_ = local_5c8[2];
          local_588._0_8_ = *local_5c0;
          local_588.decVal.u2 = *(_union_1719 *)(local_5c0 + 1);
          local_588._16_8_ = local_5c0[2];
          local_5a8._0_8_ = *local_5b8;
          local_5a8.decVal.u2 = *(_union_1719 *)(local_5b8 + 1);
          local_5a8._16_8_ = local_5b8[2];
          local_4f8._0_8_ = *local_5b0;
          local_4f8.decVal.u2 = *(_union_1719 *)(local_5b0 + 1);
          local_4f8._16_8_ = local_5b0[2];
          pcVar3 = *(code **)(*plVar4 + 0x1a8);
          local_548._0_8_ = uVar5;
          local_548.decVal.u2 = _Var23;
          *(undefined8 *)(puVar20 + -8) = 0x18001ff3c;
          iVar17 = (*pcVar3)(plVar4,p_Var11,&local_4f8,&local_5a8);
        }
        else {
          *(undefined8 *)(puVar20 + -8) = 0x18001ff46;
          iVar17 = MVGetProductCode();
          pcVar18 = ".aprbkp";
          if (iVar17 == 1) {
            pcVar18 = ".bkp";
          }
          *(undefined8 *)(puVar20 + -8) = 0x18001ff65;
          iVar17 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                             (local_5e8,pcVar18);
          if (iVar17 != 0) {
            *(undefined8 *)(puVar20 + -8) = 0x18001ff72;
            iVar17 = MVGetProductCode();
            if (iVar17 == 1) {
              pcVar24 = ".apt";
            }
            *(undefined8 *)(puVar20 + -8) = 0x18001ff86;
            iVar17 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                     CompareNoCase(local_5e8,pcVar24);
            if (iVar17 != 0) {
              *(undefined8 *)(puVar20 + -8) = 0x18001ff93;
              iVar17 = MVGetProductCode();
              pcVar24 = ".aprinp";
              if (iVar17 == 1) {
                pcVar24 = ".inp";
              }
              *(undefined8 *)(puVar20 + -8) = 0x18001ffb2;
              iVar17 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                       CompareNoCase(local_5e8,pcVar24);
              if (iVar17 != 0) {
                *(undefined8 *)(puVar20 + -8) = 0x18001ffbf;
                iVar17 = MVGetProductCode();
                pcVar24 = ".apropz";
                if (iVar17 == 1) {
                  pcVar24 = ".apwz";
                }
                *(undefined8 *)(puVar20 + -8) = 0x18001ffde;
                iVar17 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                         CompareNoCase(local_5e8,pcVar24);
                if (iVar17 != 0) {
                  *(undefined8 *)(puVar20 + -8) = 0x18001fff7;
                  iVar17 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                           CompareNoCase(local_5e8,".pro");
                  puVar13 = local_5d8;
                  if (iVar17 != 0) {
                    plVar4 = (longlong *)*param_9;
                    *(_union_2707 **)(puVar20 + 0x40) = &local_528;
                    uVar5 = *puVar13;
                    _Var23 = *(_union_1719 *)(puVar13 + 1);
                    *(_union_2707 **)(puVar20 + 0x38) = &local_548;
                    puVar7 = local_5d0;
                    local_528._16_8_ = puVar13[2];
                    local_528._0_8_ = uVar5;
                    local_528.decVal.u2 = _Var23;
                    *(_union_2707 **)(puVar20 + 0x30) = &local_568;
                    uVar5 = *puVar7;
                    _Var23 = *(_union_1719 *)(puVar7 + 1);
                    *(_union_2707 **)(puVar20 + 0x28) = &local_588;
                    puVar13 = local_5c8;
                    local_548._16_8_ = puVar7[2];
                    local_548._0_8_ = uVar5;
                    local_548.decVal.u2 = _Var23;
                    *(_union_2707 **)(puVar20 + 0x20) = &local_5a8;
                    local_568._0_8_ = *puVar13;
                    local_568.decVal.u2 = *(_union_1719 *)(puVar13 + 1);
                    local_568._16_8_ = puVar13[2];
                    local_588._0_8_ = *local_5c0;
                    local_588.decVal.u2 = *(_union_1719 *)(local_5c0 + 1);
                    local_588._16_8_ = local_5c0[2];
                    local_5a8._0_8_ = *local_5b8;
                    local_5a8.decVal.u2 = *(_union_1719 *)(local_5b8 + 1);
                    local_5a8._16_8_ = local_5b8[2];
                    local_4f8._0_8_ = *local_5b0;
                    local_4f8.decVal.u2 = *(_union_1719 *)(local_5b0 + 1);
                    local_4f8._16_8_ = local_5b0[2];
                    local_4b8 = CONCAT44(local_4d8.decVal.Hi32,
                                         CONCAT22(local_4d8.n2.wReserved1,local_4d8.n2.vt));
                    uStack_4b0 = CONCAT44(local_4d8._12_4_,local_4d8._8_4_);
                    local_4a8 = local_4d8._16_8_;
                    pcVar3 = *(code **)(*plVar4 + 400);
                    *(undefined8 *)(puVar20 + -8) = 0x18002010a;
                    iVar17 = (*pcVar3)(plVar4,p_Var11,&local_4b8,&local_4f8);
                    goto LAB_18002031e;
                  }
                }
              }
            }
          }
          puVar13 = local_5d8;
          plVar4 = (longlong *)*param_9;
          *(undefined8 **)(puVar20 + 0x38) = &local_4b8;
          uVar5 = *puVar13;
          uVar6 = puVar13[1];
          *(_union_2707 **)(puVar20 + 0x30) = &local_528;
          puVar7 = local_5d0;
          local_4a8 = puVar13[2];
          local_4b8 = uVar5;
          uStack_4b0 = uVar6;
          *(_union_2707 **)(puVar20 + 0x28) = &local_548;
          uVar5 = *puVar7;
          _Var23 = *(_union_1719 *)(puVar7 + 1);
          *(_union_2707 **)(puVar20 + 0x20) = &local_568;
          local_528._16_8_ = puVar7[2];
          local_548._0_8_ = *local_5c8;
          local_548.decVal.u2 = *(_union_1719 *)(local_5c8 + 1);
          local_548._16_8_ = local_5c8[2];
          local_568._0_8_ = *local_5c0;
          local_568.decVal.u2 = *(_union_1719 *)(local_5c0 + 1);
          local_568._16_8_ = local_5c0[2];
          local_588._0_8_ = *local_5b8;
          local_588.decVal.u2 = *(_union_1719 *)(local_5b8 + 1);
          local_588._16_8_ = local_5b8[2];
          local_5a8._0_8_ = *local_5b0;
          local_5a8.decVal.u2 = *(_union_1719 *)(local_5b0 + 1);
          local_5a8._16_8_ = local_5b0[2];
          pcVar3 = *(code **)(*plVar4 + 0x198);
          local_528._0_8_ = uVar5;
          local_528.decVal.u2 = _Var23;
          *(undefined8 *)(puVar20 + -8) = 0x1800201f0;
          iVar17 = (*pcVar3)(plVar4,p_Var11,&local_5a8,&local_588);
        }
      }
LAB_18002031e:
      *(undefined8 *)(puVar20 + -8) = 0x18002032d;
      VariantClear((VARIANTARG *)local_498);
      *(undefined8 *)(puVar20 + -8) = 0x18002033a;
      VariantClear((VARIANTARG *)&local_4d8.n2);
      uVar9 = 0;
      if (iVar17 != 0) {
        pcVar3 = *(code **)(*param_1 + 0x280);
        *(undefined8 *)(puVar20 + -8) = 0x18002034f;
        uVar9 = (*pcVar3)(param_1,0x7e4);
        pcVar3 = *(code **)(*(longlong *)*param_9 + 0x10);
        *(undefined8 *)(puVar20 + -8) = 0x18002035b;
        (*pcVar3)();
        *param_9 = 0;
      }
    }
    p_Var11 = (_union_1719 *)(ulonglong)uVar9;
  }
  else {
    uStackY_650 = 0x18001fb1a;
    HVar8 = VariantChangeType((VARIANTARG *)local_498,param_2,0,8);
    if (-1 < HVar8) {
      p_Var11 = (_union_1719 *)(local_498 + 8);
      puVar20 = auStackY_648;
      if (local_498._8_8_ != 0) {
        lVar12 = -1;
        do {
          lVar12 = lVar12 + 1;
          _Var23 = (_union_1719)local_498._8_8_;
        } while (*(LPCWSTR)(local_498._8_8_ + lVar12 * 2) != L'\0');
        goto LAB_18001fbae;
      }
      goto LAB_18001fc21;
    }
    uStackY_650 = 0x18001fb2f;
    uVar9 = (**(code **)(*param_1 + 0x280))(param_1,0x7d4);
    p_Var11 = (_union_1719 *)(ulonglong)uVar9;
  }
LAB_180020361:
  *(undefined8 *)(puVar20 + -8) = 0x18002036b;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_5e8);
  *(undefined8 *)(puVar20 + -8) = 0x180020375;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_5f8.s2);
  puVar21 = puVar20;
LAB_180020377:
  *(undefined8 *)(puVar21 + -8) = 0x180020386;
  return p_Var11;
}

/* ---- FUNC 000203A0 FUN_1800203a0 (222 bytes) ---- */

void FUN_1800203a0(longlong *param_1,undefined4 *param_2,undefined8 param_3)

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
  local_28 = *param_2;
  uStack_24 = param_2[1];
  uStack_20 = param_2[2];
  uStack_1c = param_2[3];
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
  local_18 = *(undefined8 *)(param_2 + 4);
  (**(code **)(*param_1 + 0x178))
            (param_1,&local_28,&local_48,&local_68,&local_88,&local_a8,&local_c8,&local_e8,param_3);
  return;
}

/* ---- FUNC 00020480 FUN_180020480 (48 bytes) ---- */

void FUN_180020480(longlong *param_1,undefined4 *param_2,undefined8 param_3)

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
  (**(code **)(*param_1 + 0x150))(local_28,&local_28,0,param_3);
  return;
}

/* ---- FUNC 000204B0 FUN_1800204b0 (60 bytes) ---- */

undefined8 FUN_1800204b0(longlong param_1,undefined4 param_2,undefined2 *param_3)

{
  undefined2 uVar1;
  undefined8 uVar2;
  
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0001800204d3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(**(longlong **)(param_1 + 8) + 0x280))(*(longlong **)(param_1 + 8),0x7f3);
    return uVar2;
  }
  uVar1 = Ordinal_75(param_2);
  *param_3 = uVar1;
  return 0;
}

/* ---- FUNC 000204F0 FUN_1800204f0 (28 bytes) ---- */

undefined8 FUN_1800204f0(void)

{
  undefined8 uVar1;
  
  if (DAT_180079800 == (longlong *)0x0) {
    return 0x80004005;
  }
                    /* WARNING: Could not recover jumptable at 0x000180020505. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*DAT_180079800 + 0x130))();
  return uVar1;
}

/* ---- FUNC 00020510 FUN_180020510 (25 bytes) ---- */

undefined8 FUN_180020510(undefined8 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = _getpid();
  *param_2 = iVar1;
  return 0;
}

/* ---- FUNC 00020530 FUN_180020530 (54 bytes) ---- */

undefined8 FUN_180020530(undefined8 param_1,ushort *param_2)

{
  ushort uVar1;
  
  if (DAT_1800797f8 != 0) {
    *param_2 = 0;
    return 0;
  }
  uVar1 = GRchkitm(0x20);
  *param_2 = uVar1 & 0x20;
  return 0;
}

/* ---- FUNC 00020570 FUN_180020570 (28 bytes) ---- */

undefined8 FUN_180020570(longlong param_1,short *param_2)

{
  if (param_2 == (short *)0x0) {
    return 0x80070057;
  }
  *param_2 = -(ushort)(*(int *)(param_1 + 0x98) != 0);
  return 0;
}

/* ---- FUNC 00020590 FUN_180020590 (261 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180020590(longlong *param_1,LPCWSTR param_2,VARIANTARG *param_3)

{
  undefined1 *puVar1;
  code *pcVar2;
  longlong lVar3;
  ulonglong uVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined8 uStack_60;
  undefined1 auStack_58 [32];
  undefined8 uStack_38;
  int aiStack_30 [2];
  undefined8 local_28 [2];
  ulonglong local_18 [2];
  longlong lVar4;
  
  local_18[0] = DAT_180077818 ^ (ulonglong)local_18;
  uStack_60 = 0x1800205cb;
  VariantClear(param_3);
  puVar8 = (undefined1 *)0x0;
  (param_3->n1).n2.vt = 3;
  *(undefined4 *)((longlong)&param_3->n1 + 8) = 0;
  puVar7 = auStack_58;
  puVar9 = puVar8;
  if (param_2 != (LPCWSTR)0x0) {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_2[lVar3] != L'\0');
    iVar6 = (int)lVar4 + 2;
    puVar7 = auStack_58;
    if (iVar6 < 0x40000000) {
      lVar3 = (longlong)(int)lVar3 * 2;
      uVar5 = lVar3 + 0x11;
      if (uVar5 <= lVar3 + 2U) {
        uVar5 = 0xffffffffffffff0;
      }
      uStack_60 = 0x180020622;
      lVar3 = -(uVar5 & 0xfffffffffffffff0);
      puVar1 = (undefined1 *)((longlong)local_18 + lVar3);
      puVar7 = auStack_58 + lVar3;
      if (puVar1 != (undefined1 *)0x0) {
        *(undefined8 *)((longlong)local_28 + lVar3 + 8) = 0;
        *(undefined8 *)((longlong)local_28 + lVar3) = 0;
        *(int *)((longlong)aiStack_30 + lVar3) = iVar6 * 2;
        *(undefined1 **)((longlong)&uStack_38 + lVar3) = puVar1;
        *puVar1 = 0;
        *(undefined8 *)(auStack_58 + lVar3 + -8) = 0x18002065b;
        iVar6 = WideCharToMultiByte(0,0,param_2,-1,*(LPSTR *)((longlong)&uStack_38 + lVar3),
                                    *(int *)((longlong)aiStack_30 + lVar3),
                                    *(LPCSTR *)((longlong)local_28 + lVar3),
                                    *(LPBOOL *)((longlong)local_28 + lVar3 + 8));
        puVar7 = auStack_58 + lVar3;
        puVar9 = puVar1;
        if (iVar6 == 0) {
          puVar7 = auStack_58 + lVar3;
          puVar9 = puVar8;
        }
      }
    }
  }
  pcVar2 = *(code **)(*param_1 + 0x2c8);
  *(undefined8 *)(puVar7 + -8) = 0x180020673;
  (*pcVar2)(param_1,puVar9);
  *(undefined8 *)(puVar7 + -8) = 0x18002067f;
  return;
}

/* ---- FUNC 000206A0 FUN_1800206a0 (433 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

ulonglong FUN_1800206a0(longlong *param_1,BSTR param_2,undefined8 param_3)

{
  undefined1 *puVar1;
  code *pcVar2;
  longlong *plVar3;
  UINT UVar4;
  int iVar5;
  uint uVar6;
  longlong lVar7;
  ulonglong uVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  ulonglong uVar13;
  undefined8 uStack_80;
  undefined1 auStack_78 [32];
  undefined8 uStack_58;
  int aiStack_50 [2];
  undefined8 local_48 [2];
  longlong *local_38;
  longlong *local_30;
  undefined8 *local_28;
  ulonglong local_20;
  longlong lVar8;
  
  local_20 = DAT_180077818 ^ (ulonglong)&local_38;
  uVar13 = 0x80004002;
  uVar9 = uVar13;
  puVar12 = auStack_78;
  if (param_1[4] != 0) {
    if (param_2 != (BSTR)0x0) {
      uStack_80 = 0x1800206f5;
      UVar4 = SysStringLen(param_2);
      if (UVar4 != 0) {
        uStack_80 = 0x18002070d;
        (**(code **)(*param_1 + 0x90))(param_1,&local_30);
        if (local_30 == (longlong *)0x0) {
          uVar9 = 0x80004005;
          puVar12 = auStack_78;
        }
        else {
          puVar10 = (undefined1 *)0x0;
          local_38 = (longlong *)0x0;
          uStack_80 = 0x180020735;
          iVar5 = (**(code **)*local_30)(local_30,&DAT_180063650,&local_38);
          puVar12 = auStack_78;
          if ((-1 < iVar5) && (puVar12 = auStack_78, local_38 != (longlong *)0x0)) {
            lVar7 = -1;
            do {
              lVar8 = lVar7;
              lVar7 = lVar8 + 1;
            } while (param_2[lVar7] != L'\0');
            iVar5 = (int)lVar8 + 2;
            puVar11 = puVar10;
            puVar12 = auStack_78;
            if (iVar5 < 0x40000000) {
              lVar7 = (longlong)(int)lVar7 * 2;
              uVar9 = lVar7 + 0x11;
              if (uVar9 <= lVar7 + 2U) {
                uVar9 = 0xffffffffffffff0;
              }
              uStack_80 = 0x18002078e;
              lVar7 = -(uVar9 & 0xfffffffffffffff0);
              puVar1 = (undefined1 *)((longlong)&local_38 + lVar7);
              puVar12 = auStack_78 + lVar7;
              if (puVar1 != (undefined1 *)0x0) {
                *(undefined8 *)((longlong)local_48 + lVar7 + 8) = 0;
                *(undefined8 *)((longlong)local_48 + lVar7) = 0;
                *(int *)((longlong)aiStack_50 + lVar7) = iVar5 * 2;
                *(undefined1 **)((longlong)&uStack_58 + lVar7) = puVar1;
                *puVar1 = 0;
                *(undefined8 *)(auStack_78 + lVar7 + -8) = 0x1800207c6;
                iVar5 = WideCharToMultiByte(0,0,param_2,-1,*(LPSTR *)((longlong)&uStack_58 + lVar7),
                                            *(int *)((longlong)aiStack_50 + lVar7),
                                            *(LPCSTR *)((longlong)local_48 + lVar7),
                                            *(LPBOOL *)((longlong)local_48 + lVar7 + 8));
                puVar11 = puVar1;
                puVar12 = auStack_78 + lVar7;
                if (iVar5 == 0) {
                  puVar11 = puVar10;
                  puVar12 = auStack_78 + lVar7;
                }
              }
            }
            plVar3 = local_38;
            pcVar2 = *(code **)(*local_38 + 0x28);
            *(undefined8 *)(puVar12 + -8) = 0x1800207e2;
            uVar6 = (*pcVar2)(plVar3,puVar11,param_3);
            uVar13 = (ulonglong)uVar6;
            pcVar2 = *(code **)(*local_38 + 0x10);
            *(undefined8 *)(puVar12 + -8) = 0x1800207ef;
            (*pcVar2)();
          }
          pcVar2 = *(code **)(*local_30 + 0x10);
          *(undefined8 *)(puVar12 + -8) = 0x1800207f9;
          (*pcVar2)();
          uVar9 = uVar13;
        }
        goto LAB_18002082f;
      }
    }
    local_28 = (undefined8 *)0x0;
    uStack_80 = 0x180020819;
    uVar9 = HAQueryInterface(param_1[4],&DAT_180063610,param_3,&local_28);
    puVar12 = auStack_78;
    if ((local_28 != (undefined8 *)0x0) &&
       (uVar9 = uVar13, puVar12 = auStack_78, (code *)*local_28 != (code *)0x0)) {
      uStack_80 = 0x18002082c;
      (*(code *)*local_28)();
      puVar12 = auStack_78;
    }
  }
LAB_18002082f:
  *(undefined8 *)(puVar12 + -8) = 0x18002083b;
  return uVar9;
}

/* ---- FUNC 00020860 FUN_180020860 (11 bytes) ---- */

undefined8 FUN_180020860(undefined8 param_1,undefined2 *param_2)

{
  *param_2 = 0xffff;
  return 0x80004001;
}

/* ---- FUNC 00020870 FUN_180020870 (147 bytes) ---- */

ulonglong FUN_180020870(longlong *param_1,wchar_t *param_2,undefined8 *param_3)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  char *local_res20;
  undefined8 *local_18 [2];
  
  if (DAT_1800797f8 != 0) {
    uVar3 = (**(code **)(*param_1 + 0x280))(param_1,0x7f3);
    return uVar3;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,param_2);
  *param_3 = 0;
  iVar1 = CMapStringToPtr::Lookup((CMapStringToPtr *)(param_1 + 0x37),local_res20,local_18);
  if (iVar1 == 0) {
    uVar3 = 0x80004005;
  }
  else {
    uVar2 = (**(code **)*local_18[0])(local_18[0],&DAT_180063430,param_3);
    uVar3 = (ulonglong)uVar2;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
  return uVar3;
}

/* ---- FUNC 00020910 FUN_180020910 (57 bytes) ---- */

undefined8 FUN_180020910(longlong param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x000180020933. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(**(longlong **)(param_1 + 8) + 0x280))(*(longlong **)(param_1 + 8),0x7f3);
    return uVar2;
  }
  uVar1 = Ordinal_78();
  *param_2 = uVar1;
  return 0;
}

/* ---- FUNC 00020950 FUN_180020950 (8 bytes) ---- */

undefined8 FUN_180020950(longlong param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x14);
  return 0;
}

/* ---- FUNC 00020960 FUN_180020960 (31 bytes) ---- */

undefined8 FUN_180020960(undefined8 param_1,uint *param_2)

{
  int iVar1;
  
  iVar1 = MMGetSuppress();
  *param_2 = (uint)(iVar1 != 0);
  return 0;
}

/* ---- FUNC 00020980 FUN_180020980 (121 bytes) ---- */

ulonglong FUN_180020980(IUnknownVtbl *param_1,longlong *param_2,undefined8 param_3,
                       undefined8 param_4)

{
  longlong *plVar1;
  uint uVar2;
  ulonglong uVar3;
  IUnknownVtbl *pIVar4;
  longlong local_res18;
  longlong local_res20;
  
  if (DAT_1800797f8 != 0) {
    uVar3 = (**(code **)(param_1->QueryInterface + 0x280))(param_1,0x7f3);
    return uVar3;
  }
  local_res18 = 0;
  if (*(int *)&param_1[1].QueryInterface == 0) {
    uVar3 = (**(code **)(param_1->QueryInterface + 0x280))(param_1,0x7d2);
    return uVar3;
  }
  if (param_1[1].AddRef == (_func_5157 *)0x0) {
    uVar3 = (**(code **)(param_1->QueryInterface + 0x280))(param_1,0x7d1);
    return uVar3;
  }
  pIVar4 = (IUnknownVtbl *)HAGetTree(param_1[1].AddRef,&local_res18);
  if (pIVar4 == (IUnknownVtbl *)0x0) {
    if (local_res18 != 0) {
      uVar3 = (**(code **)(param_1->QueryInterface + 0x278))();
      return uVar3;
    }
    uVar3 = (**(code **)(param_1->QueryInterface + 0x280))(param_1,0x7d1);
    return uVar3;
  }
  if (param_1[0xb].Release == (_func_5158 *)0x0) {
    FUN_18001d5e0((IUnknown *)param_1,(char *)param_1[0xb].QueryInterface,param_3,param_4);
  }
  uVar2 = FUN_1800389d0(pIVar4,param_1,param_1,1,(IUnknownVtbl *)param_1[1].Release,&local_res20);
  if (-1 < (int)uVar2) {
    *param_2 = local_res20;
    if (param_1[0xb].Release != (_func_5158 *)0x0) {
      plVar1 = *(longlong **)(local_res20 + 0xe8);
      (**(code **)(*(longlong *)param_1[0xb].Release + 8))();
      if (plVar1 != (longlong *)0x0) {
        (**(code **)(*plVar1 + 0x10))(plVar1);
      }
      *(_func_5158 **)(local_res20 + 0xe8) = param_1[0xb].Release;
    }
  }
  return (ulonglong)uVar2;
}

/* ---- FUNC 000209F9 FUN_1800209f9 (54 bytes) ---- */

ulonglong FUN_1800209f9(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *plVar1;
  uint uVar2;
  IUnknownVtbl *pIVar3;
  ulonglong uVar4;
  IUnknownVtbl *unaff_RBX;
  longlong *unaff_R14;
  longlong in_stack_00000060;
  longlong in_stack_00000068;
  
  pIVar3 = (IUnknownVtbl *)HAGetTree();
  if (pIVar3 != (IUnknownVtbl *)0x0) {
    if (unaff_RBX[0xb].Release == (_func_5158 *)0x0) {
      FUN_18001d5e0((IUnknown *)unaff_RBX,(char *)unaff_RBX[0xb].QueryInterface,param_3,param_4);
    }
    uVar2 = FUN_1800389d0(pIVar3,unaff_RBX,unaff_RBX,1,(IUnknownVtbl *)unaff_RBX[1].Release,
                          &stack0x00000068);
    if (-1 < (int)uVar2) {
      *unaff_R14 = in_stack_00000068;
      if (unaff_RBX[0xb].Release != (_func_5158 *)0x0) {
        plVar1 = *(longlong **)(in_stack_00000068 + 0xe8);
        (**(code **)(*(longlong *)unaff_RBX[0xb].Release + 8))();
        if (plVar1 != (longlong *)0x0) {
          (**(code **)(*plVar1 + 0x10))(plVar1);
        }
        *(_func_5158 **)(in_stack_00000068 + 0xe8) = unaff_RBX[0xb].Release;
      }
    }
    return (ulonglong)uVar2;
  }
  if (in_stack_00000060 != 0) {
    uVar4 = (**(code **)(unaff_RBX->QueryInterface + 0x278))();
    return uVar4;
  }
  uVar4 = (**(code **)(unaff_RBX->QueryInterface + 0x280))();
  return uVar4;
}

/* ---- FUNC 00020A2F FUN_180020a2f (24 bytes) ---- */

void FUN_180020a2f(undefined8 param_1)

{
  longlong in_RAX;
  
  (**(code **)(in_RAX + 0x280))(param_1,0x7d1);
  return;
}

/* ---- FUNC 00020A47 FUN_180020a47 (161 bytes) ---- */

int FUN_180020a47(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *plVar1;
  int iVar2;
  IUnknownVtbl *unaff_RBX;
  IUnknownVtbl *unaff_RDI;
  longlong *unaff_R14;
  longlong in_stack_00000068;
  
  if (unaff_RBX[0xb].Release == (_func_5158 *)0x0) {
    FUN_18001d5e0((IUnknown *)unaff_RBX,(char *)unaff_RBX[0xb].QueryInterface,param_3,param_4);
  }
  iVar2 = FUN_1800389d0(unaff_RDI,unaff_RBX,unaff_RBX,1,(IUnknownVtbl *)unaff_RBX[1].Release,
                        &stack0x00000068);
  if (-1 < iVar2) {
    *unaff_R14 = in_stack_00000068;
    if (unaff_RBX[0xb].Release != (_func_5158 *)0x0) {
      plVar1 = *(longlong **)(in_stack_00000068 + 0xe8);
      (**(code **)(*(longlong *)unaff_RBX[0xb].Release + 8))();
      if (plVar1 != (longlong *)0x0) {
        (**(code **)(*plVar1 + 0x10))(plVar1);
      }
      *(_func_5158 **)(in_stack_00000068 + 0xe8) = unaff_RBX[0xb].Release;
    }
  }
  return iVar2;
}

/* ---- FUNC 00020AF0 FUN_180020af0 (25 bytes) ---- */

undefined8 FUN_180020af0(undefined8 param_1,undefined2 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_1800375b0();
  *param_2 = (short)uVar1;
  return 0;
}

/* ---- FUNC 00020B10 FUN_180020b10 (56 bytes) ---- */

undefined8 FUN_180020b10(undefined8 param_1,short param_2,short param_3)

{
  CPaletteCategory *pCVar1;
  
  pCVar1 = CApwnLibraries::GetCategory(*(CApwnLibraries **)g_pApwnLibs_exref,(int)param_2);
  if (pCVar1 != (CPaletteCategory *)0x0) {
    *(int *)(pCVar1 + 0x40) = (int)param_3;
    return 0;
  }
  return 0x80004005;
}

/* ---- FUNC 00020B50 FUN_180020b50 (320 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char * FUN_180020b50(undefined8 param_1,LPCWSTR param_2,short param_3)

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
      uStack_60 = 0x180020bcf;
      lVar2 = -(uVar6 & 0xfffffffffffffff0);
      pcVar1 = (char *)((longlong)&local_18 + lVar2);
      puVar8 = auStack_58 + lVar2;
      if (pcVar1 != (char *)0x0) {
        *pcVar1 = '\0';
        *(undefined8 *)((longlong)local_28 + lVar2 + 8) = 0;
        *(undefined8 *)((longlong)local_28 + lVar2) = 0;
        *(int *)((longlong)aiStack_30 + lVar2) = iVar9 * 2;
        *(char **)((longlong)&uStack_38 + lVar2) = pcVar1;
        *(undefined8 *)(auStack_58 + lVar2 + -8) = 0x180020c08;
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
  *(undefined8 *)(puVar8 + -8) = 0x180020c20;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_18,pcVar4);
  iVar9 = *(int *)(local_18 + -0x10);
  *(undefined8 *)(puVar8 + -8) = 0x180020c32;
  pcVar4 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)&local_18,iVar9);
  this = *(CApwnLibraries **)g_pApwnLibs_exref;
  *(undefined8 *)(puVar8 + -8) = 0x180020c45;
  pCVar5 = CApwnLibraries::GetCategory(this,pcVar4);
  *(undefined8 *)(puVar8 + -8) = 0x180020c57;
  ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_18,-1);
  if (pCVar5 == (CPaletteCategory *)0x0) {
    pcVar7 = (char *)0x80004005;
  }
  else {
    *(int *)(pCVar5 + 0x40) = (int)param_3;
  }
  *(undefined8 *)(puVar8 + -8) = 0x180020c70;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_18);
  *(undefined8 *)(puVar8 + -8) = 0x180020c7e;
  return pcVar7;
}

/* ---- FUNC 00020C90 FUN_180020c90 (44 bytes) ---- */

undefined8 FUN_180020c90(undefined8 param_1,short param_2)

{
  int iVar1;
  
  iVar1 = FUN_1800375b0();
  if (iVar1 != 0) {
    (**(code **)(*DAT_180079800 + 0x90))(DAT_180079800,(int)param_2);
  }
  return 0;
}

/* ---- FUNC 00020CC0 FUN_180020cc0 (296 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

ulonglong FUN_180020cc0(longlong param_1,undefined4 param_2,LPCWSTR param_3)

{
  longlong *plVar1;
  code *pcVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  int iVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined8 uStack_60;
  undefined1 auStack_58 [32];
  undefined8 uStack_38;
  int aiStack_30 [2];
  undefined8 local_28 [2];
  ulonglong local_18 [2];
  longlong lVar6;
  
  puVar8 = auStack_58;
  local_18[0] = DAT_180077818 ^ (ulonglong)local_18;
  if (DAT_1800797f8 != 0) {
    uStack_60 = 0x180020d0a;
    uVar4 = (**(code **)(**(longlong **)(param_1 + 8) + 0x280))(*(longlong **)(param_1 + 8),0x7f3);
    goto LAB_180020dc6;
  }
  puVar8 = auStack_58;
  if (param_3 == (LPCWSTR)0x0) {
LAB_180020d9d:
    puVar9 = (undefined1 *)0x0;
  }
  else {
    lVar5 = -1;
    do {
      lVar6 = lVar5;
      lVar5 = lVar6 + 1;
    } while (param_3[lVar5] != L'\0');
    iVar7 = (int)lVar6 + 2;
    puVar8 = auStack_58;
    if (0x3fffffff < iVar7) goto LAB_180020d9d;
    lVar5 = (longlong)(int)lVar5 * 2;
    uVar4 = lVar5 + 0x11;
    if (uVar4 <= lVar5 + 2U) {
      uVar4 = 0xffffffffffffff0;
    }
    uStack_60 = 0x180020d5f;
    lVar5 = -(uVar4 & 0xfffffffffffffff0);
    puVar8 = auStack_58 + lVar5;
    puVar9 = (undefined1 *)((longlong)local_18 + lVar5);
    if (puVar9 == (undefined1 *)0x0) goto LAB_180020d9d;
    *puVar9 = 0;
    *(undefined8 *)((longlong)local_28 + lVar5 + 8) = 0;
    *(undefined8 *)((longlong)local_28 + lVar5) = 0;
    *(int *)((longlong)aiStack_30 + lVar5) = iVar7 * 2;
    *(undefined1 **)((longlong)&uStack_38 + lVar5) = puVar9;
    *(undefined8 *)(auStack_58 + lVar5 + -8) = 0x180020d95;
    iVar7 = WideCharToMultiByte(0,0,param_3,-1,*(LPSTR *)((longlong)&uStack_38 + lVar5),
                                *(int *)((longlong)aiStack_30 + lVar5),
                                *(LPCSTR *)((longlong)local_28 + lVar5),
                                *(LPBOOL *)((longlong)local_28 + lVar5 + 8));
    puVar8 = auStack_58 + lVar5;
    if (iVar7 == 0) {
      puVar8 = auStack_58 + lVar5;
      puVar9 = (undefined1 *)0x0;
    }
  }
  uVar4 = 0;
  *(undefined8 *)(puVar8 + -8) = 0x180020dac;
  iVar7 = Ordinal_74(param_2,puVar9);
  if (iVar7 == 0) {
    plVar1 = *(longlong **)(param_1 + 8);
    pcVar2 = *(code **)(*plVar1 + 0x280);
    *(undefined8 *)(puVar8 + -8) = 0x180020dc2;
    uVar3 = (*pcVar2)(plVar1,0x7d1);
    uVar4 = (ulonglong)uVar3;
  }
LAB_180020dc6:
  *(undefined8 *)(puVar8 + -8) = 0x180020dd2;
  return uVar4;
}

/* ---- FUNC 00020DF0 FUN_180020df0 (56 bytes) ---- */

undefined8 FUN_180020df0(longlong param_1,undefined4 param_2,short param_3)

{
  undefined8 uVar1;
  
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x000180020e0f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(**(longlong **)(param_1 + 8) + 0x280))(*(longlong **)(param_1 + 8),0x7f3);
    return uVar1;
  }
  Ordinal_76(param_2,(int)param_3);
  return 0;
}

/* ---- FUNC 00020E30 FUN_180020e30 (63 bytes) ---- */

undefined8 FUN_180020e30(longlong param_1,short param_2)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res8 [32];
  
  *(int *)(param_1 + 0x98) = (int)param_2;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
  FUN_1800374c0(0x79 - (uint)(param_2 != 0),(longlong *)local_res8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
  return 0;
}

/* ---- FUNC 00020E70 FUN_180020e70 (30 bytes) ---- */

undefined8 FUN_180020e70(undefined8 param_1,short param_2)

{
  (**(code **)(*DAT_180079800 + 0xa0))(DAT_180079800,(int)param_2);
  return 0;
}

/* ---- FUNC 00020E90 FUN_180020e90 (23 bytes) ---- */

undefined8 FUN_180020e90(undefined8 param_1,int param_2)

{
  MMSetSuppress(param_2 != 0);
  return 0;
}

/* ---- FUNC 00020EB0 FUN_180020eb0 (77 bytes) ---- */

undefined8 FUN_180020eb0(longlong *param_1,short param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if ((int)param_1[3] == 0) {
                    /* WARNING: Could not recover jumptable at 0x000180020ec6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(*param_1 + 0x280))(param_1,0x7d2);
    return uVar2;
  }
  if (param_2 == 0) {
    iVar1 = FUN_1800375b0();
    if (iVar1 != 0) {
      uVar2 = FUN_180037570();
      return uVar2;
    }
  }
  else {
    iVar1 = FUN_1800375b0();
    if (iVar1 == 0) {
      uVar2 = FUN_1800375e0();
      return uVar2;
    }
  }
  return 0;
}

/* ---- FUNC 00020F00 FUN_180020f00 (116 bytes) ---- */

void FUN_180020f00(longlong *param_1,char *param_2)

{
  int iVar1;
  char local_res8 [8];
  int local_res10 [2];
  
  iVar1 = (**(code **)(*param_1 + 0x18))(param_1,local_res8,1,local_res10);
  if (-1 < iVar1) {
    while ((local_res10[0] == 1 && (local_res8[0] != '\0'))) {
      *param_2 = local_res8[0];
      param_2 = param_2 + 1;
      if ((local_res8[0] == '\n') ||
         (iVar1 = (**(code **)(*param_1 + 0x18))(param_1,local_res8,1,local_res10), iVar1 < 0))
      break;
    }
  }
  *param_2 = '\0';
  return;
}

/* ---- FUNC 00020F80 sscanf (82 bytes) ---- */

/* Library Function - Single Match
    sscanf
   
   Library: Visual Studio 2019 Release */

int __cdecl sscanf(char *_Src,char *_Format,...)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 in_R8;
  undefined8 in_R9;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = in_R8;
  local_res20 = in_R9;
  puVar2 = (undefined8 *)FUN_180005970();
  iVar1 = __stdio_common_vsscanf(*puVar2,_Src,0xffffffffffffffff,_Format,0,&local_res18);
  return iVar1;
}

/* ---- FUNC 00020FE0 FUN_180020fe0 (781 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_180020fe0(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,uint param_2)

{
  longlong lVar1;
  code *pcVar2;
  int iVar3;
  HRESULT HVar4;
  int iVar5;
  LCID LVar6;
  BSTR pOVar7;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar8;
  uint uVar9;
  LPCOLESTR lpszProgID;
  undefined1 *puVar11;
  undefined1 auStackY_188 [32];
  WCHAR local_138 [20];
  undefined8 uStack_110;
  undefined1 local_108 [80];
  LPCSTR local_b8;
  BSTR local_b0;
  undefined4 local_a8;
  BSTR local_a0;
  undefined2 *local_98;
  undefined8 local_90;
  undefined8 local_88;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_80;
  undefined1 local_78 [24];
  undefined2 local_60;
  BSTR local_58;
  CLSID local_48;
  ulonglong local_38;
  LPCOLESTR pOVar10;
  
  local_38 = DAT_180077818 ^ (ulonglong)&local_b8;
  local_a8 = 1;
  uStack_110 = 0x18002102d;
  local_80 = param_1;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1);
  local_a8 = 1;
  uStack_110 = 0x18002103c;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8);
  uStack_110 = 0x180021051;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,"_%u",
             (ulonglong)param_2);
  pOVar10 = (LPCOLESTR)0x0;
  puVar11 = local_108;
  if (DAT_180079580 == (longlong *)0x0) {
    lpszProgID = pOVar10;
    if (local_138 != (LPWSTR)0x0) {
      local_138[0] = L'\0';
      iVar3 = MultiByteToWideChar(0,0,"AspenTech.AspenPlus.Localization.UnmanagedResourceServer.410"
                                  ,-1,local_138,0x3d);
      lpszProgID = local_138;
      if (iVar3 == 0) {
        lpszProgID = pOVar10;
      }
    }
    HVar4 = CLSIDFromProgID(lpszProgID,&local_48);
    puVar11 = auStackY_188;
    if ((HVar4 < 0) ||
       (HVar4 = CoCreateInstance(&local_48,(LPUNKNOWN)0x0,1,(IID *)&DAT_180066c78,&DAT_180079580),
       puVar11 = auStackY_188, HVar4 < 0)) goto LAB_18002129f;
    local_b0 = L"GetHappResourceString";
    lVar1 = *DAT_180079580;
    GetUserDefaultLCID();
    iVar3 = (**(code **)(lVar1 + 0x28))(DAT_180079580,&DAT_180066d68,&local_b0,1);
    puVar11 = auStackY_188;
    if (iVar3 < 0) {
      (**(code **)(*DAT_180079580 + 0x10))();
      DAT_180079580 = (longlong *)0x0;
      puVar11 = auStackY_188;
      goto LAB_18002129f;
    }
  }
  local_90 = 0;
  local_88 = 2;
  local_98 = (undefined2 *)local_78;
  do {
    *(undefined8 *)(puVar11 + -8) = 0x180021174;
    VariantInit((VARIANTARG *)(local_78 + (longlong)pOVar10 * 0x18));
    uVar9 = (int)pOVar10 + 1;
    pOVar10 = (LPCOLESTR)(ulonglong)uVar9;
  } while (uVar9 < (uint)local_88);
  *(undefined8 *)(puVar11 + -8) = 0x180021188;
  local_a0 = SysAllocString(L"");
  if (local_b8 == (LPCSTR)0x0) {
    local_b0 = (BSTR)0x0;
  }
  else {
    *(undefined4 *)(puVar11 + 0x28) = 0;
    *(undefined8 *)(puVar11 + 0x20) = 0;
    *(undefined8 *)(puVar11 + -8) = 0x1800211b2;
    iVar3 = MultiByteToWideChar(0,0,local_b8,-1,*(LPWSTR *)(puVar11 + 0x20),*(int *)(puVar11 + 0x28)
                               );
    *(undefined8 *)(puVar11 + -8) = 0x1800211c0;
    pOVar7 = SysAllocStringLen((OLECHAR *)0x0,iVar3 - 1);
    if (pOVar7 != (BSTR)0x0) {
      *(int *)(puVar11 + 0x28) = iVar3;
      *(BSTR *)(puVar11 + 0x20) = pOVar7;
      *(undefined8 *)(puVar11 + -8) = 0x1800211e5;
      iVar5 = MultiByteToWideChar(0,0,local_b8,-1,*(LPWSTR *)(puVar11 + 0x20),
                                  *(int *)(puVar11 + 0x28));
      if (iVar5 != iVar3) {
        *(undefined8 *)(puVar11 + -8) = 0x1800212e3;
        SysFreeString(pOVar7);
        goto LAB_1800212e3;
      }
    }
    local_b0 = pOVar7;
    if (pOVar7 == (BSTR)0x0) {
LAB_1800212e3:
                    /* WARNING: Subroutine does not return */
      *(undefined **)(puVar11 + -8) = &UNK_1800212ed;
      FUN_180001a90(-0x7ff8fff2);
    }
  }
  pOVar7 = local_b0;
  local_60 = 8;
  local_78._0_2_ = 0x4008;
  local_78._8_8_ = &local_a0;
  lVar1 = *DAT_180079580;
  *(undefined8 *)(puVar11 + -8) = 0x180021232;
  local_58 = local_b0;
  LVar6 = GetUserDefaultLCID();
  *(undefined8 *)(puVar11 + 0x40) = 0;
  *(undefined8 *)(puVar11 + 0x38) = 0;
  *(undefined8 *)(puVar11 + 0x30) = 0;
  *(undefined2 ***)(puVar11 + 0x28) = &local_98;
  *(undefined2 *)(puVar11 + 0x20) = 1;
  pcVar2 = *(code **)(lVar1 + 0x30);
  *(undefined8 *)(puVar11 + -8) = 0x18002126a;
  iVar3 = (*pcVar2)(DAT_180079580,DAT_1800776e0,&DAT_180066d68,LVar6);
  if (-1 < iVar3) {
    *(undefined8 *)(puVar11 + -8) = 0x18002127c;
    pCVar8 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                       ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48,
                        local_a0);
    *(undefined8 *)(puVar11 + -8) = 0x180021289;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_1,pCVar8);
    *(undefined8 *)(puVar11 + -8) = 0x180021294;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48);
  }
  *(undefined8 *)(puVar11 + -8) = 0x18002129e;
  SysFreeString(pOVar7);
LAB_18002129f:
  *(undefined8 *)(puVar11 + -8) = 0x1800212a9;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8);
  *(undefined8 *)(puVar11 + -8) = 0x1800212bc;
  return param_1;
}

/* ---- FUNC 000212F0 FUN_1800212f0 (26 bytes) ---- */

undefined8 * FUN_1800212f0(undefined8 *param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  
  param_1[1] = param_2;
  *param_1 = CSupportErrorInfo::vftable;
  uVar1 = param_3[1];
  param_1[2] = *param_3;
  param_1[3] = uVar1;
  return param_1;
}

/* ---- FUNC 00021310 FUN_180021310 (26 bytes) ---- */

bool FUN_180021310(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  
  lVar1 = *param_2 - *(longlong *)(param_1 + 0x10);
  if (lVar1 == 0) {
    lVar1 = param_2[1] - *(longlong *)(param_1 + 0x18);
  }
  return lVar1 != 0;
}

/* ---- FUNC 00021330 FUN_180021330 (24 bytes) ---- */

undefined8 * FUN_180021330(undefined8 *param_1,undefined1 param_2)

{
  *(undefined4 *)(param_1 + 1) = 0;
  *param_1 = CHappCF::vftable;
  *(undefined1 *)((longlong)param_1 + 0xc) = param_2;
  return param_1;
}

/* ---- FUNC 00021350 FUN_180021350 (86 bytes) ---- */

undefined8 FUN_180021350(longlong param_1,longlong param_2,undefined8 param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  
  *param_4 = 0;
  if (DAT_1800797d4 == 0) {
    return 0x80004005;
  }
  if (param_2 != 0) {
    return 0x80040110;
  }
  if (*(char *)(param_1 + 0xc) != '\0') {
    if (DAT_180079588 != 0) {
      return 0x80004021;
    }
    DAT_180079588 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x0001800213a3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)*DAT_1800797f0)(DAT_1800797f0,param_3,param_4);
  return uVar1;
}

/* ---- FUNC 000213B0 FUN_1800213b0 (76 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1800213b0(undefined8 param_1,int param_2)

{
  if (param_2 != 0) {
    if (DAT_1800797f0 != (LPUNKNOWN)0x0) {
      CoLockObjectExternal(DAT_1800797f0,1,0);
    }
    _DAT_1800797d0 = _DAT_1800797d0 + 1;
    return 0;
  }
  _DAT_1800797d0 = _DAT_1800797d0 + -1;
  if (DAT_1800797f0 != (LPUNKNOWN)0x0) {
    CoLockObjectExternal(DAT_1800797f0,0,1);
  }
  return 0;
}

/* ---- FUNC 00021400 FUN_180021400 (123 bytes) ---- */

undefined8 FUN_180021400(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  *param_3 = 0;
  if (DAT_18007958c != 0) {
    FUN_18000ef30(DAT_1800797f0,1);
    return 0x80004005;
  }
  if (((*param_2 != DAT_180066c58) || (param_2[1] != DAT_180066c60)) &&
     ((*param_2 != DAT_180066c68 || (param_2[1] != DAT_180066c70)))) {
    return 0x80004002;
  }
  *param_3 = param_1;
  (**(code **)(*param_1 + 8))();
  return 0;
}

/* ---- FUNC 00021480 FUN_180021480 (32 bytes) ---- */

int FUN_180021480(void *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((longlong)param_1 + 8) + -1;
  *(int *)((longlong)param_1 + 8) = iVar1;
  if (iVar1 == 0) {
    FUN_180025ad0(param_1);
    iVar1 = 0;
  }
  return iVar1;
}

/* ---- FUNC 000214A0 FUN_1800214a0 (47 bytes) ---- */

undefined8 * FUN_1800214a0(undefined8 *param_1,longlong *param_2)

{
  param_1[2] = param_2;
  *param_1 = CImpIEnumHappCP::vftable;
  param_1[1] = 0;
  (**(code **)(*param_2 + 8))(param_2);
  return param_1;
}

/* ---- FUNC 000214D0 FUN_1800214d0 (47 bytes) ---- */

undefined8 * FUN_1800214d0(undefined8 *param_1,longlong *param_2)

{
  param_1[2] = param_2;
  *param_1 = CImpIEnumHappConns::vftable;
  param_1[1] = 0;
  (**(code **)(*param_2 + 8))(param_2);
  return param_1;
}

/* ---- FUNC 00021500 FUN_180021500 (41 bytes) ---- */

undefined8 * FUN_180021500(undefined8 *param_1,undefined8 *param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  param_1[6] = param_3;
  *param_1 = CImpIHappCP::vftable;
  param_1[4] = 0;
  *(undefined4 *)(param_1 + 1) = 0;
  *(undefined8 *)((longlong)param_1 + 0xc) = uVar1;
  *(undefined8 *)((longlong)param_1 + 0x14) = uVar2;
  *(undefined4 *)(param_1 + 5) = 100;
  return param_1;
}

/* ---- FUNC 00021530 FUN_180021530 (27 bytes) ---- */

undefined8 * FUN_180021530(undefined8 *param_1,undefined8 param_2)

{
  param_1[2] = param_2;
  *param_1 = CImpIHappCPContainer::vftable;
  *(undefined4 *)(param_1 + 1) = 0;
  param_1[3] = 0;
  return param_1;
}

/* ---- FUNC 00021550 FUN_180021550 (35 bytes) ---- */

void FUN_180021550(undefined8 *param_1)

{
  *param_1 = CImpIEnumHappCP::vftable;
  if ((longlong *)param_1[2] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[2] + 0x10))();
  }
  return;
}

/* ---- FUNC 00021580 FUN_180021580 (35 bytes) ---- */

void FUN_180021580(undefined8 *param_1)

{
  *param_1 = CImpIEnumHappConns::vftable;
  if ((longlong *)param_1[2] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[2] + 0x10))();
  }
  return;
}

/* ---- FUNC 000215B0 FUN_1800215b0 (82 bytes) ---- */

void FUN_1800215b0(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  *param_1 = CImpIHappCP::vftable;
  puVar2 = (undefined8 *)param_1[4];
  if ((undefined8 *)param_1[4] != (undefined8 *)0x0) {
    do {
      param_1[4] = puVar2;
      puVar1 = (undefined8 *)puVar2[1];
      (**(code **)(*(longlong *)*puVar2 + 0x10))();
      free((void *)param_1[4]);
      puVar2 = puVar1;
    } while (puVar1 != (undefined8 *)0x0);
    param_1[4] = 0;
  }
  return;
}

/* ---- FUNC 00021610 FUN_180021610 (35 bytes) ---- */

void FUN_180021610(undefined8 *param_1)

{
  *param_1 = CImpIHappCPContainer::vftable;
  if ((longlong *)param_1[3] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[3] + 0x10))();
  }
  return;
}

/* ---- FUNC 00021640 FUN_180021640 (178 bytes) ---- */

undefined8 FUN_180021640(longlong *param_1,longlong *param_2,undefined4 *param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 *local_res8;
  
  uVar3 = (**(code **)(*param_1 + 0x40))(param_1,param_2,&local_res8);
  if (-1 < (int)uVar3) {
    *local_res8 = param_2;
    (**(code **)(*param_2 + 8))(param_2);
    *param_3 = (int)param_1[5];
    *(int *)(param_1 + 5) = (int)param_1[5] + 1;
    *(undefined4 *)(local_res8 + 2) = *param_3;
    local_res8[1] = 0;
    lVar1 = param_1[4];
    if (lVar1 != 0) {
      for (lVar2 = *(longlong *)(lVar1 + 8); lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 8)) {
        lVar1 = lVar2;
      }
      *(undefined8 **)(lVar1 + 8) = local_res8;
      return 0;
    }
    param_1[4] = (longlong)local_res8;
    uVar3 = 0;
  }
  return uVar3;
}

/* ---- FUNC 00021700 FUN_180021700 (44 bytes) ---- */

undefined8 FUN_180021700(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  void *pvVar1;
  undefined8 uVar2;
  
  pvVar1 = malloc(0x18);
  uVar2 = 0;
  *param_3 = pvVar1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0x8007000e;
  }
  return uVar2;
}

/* ---- FUNC 00021730 FUN_180021730 (81 bytes) ---- */

void FUN_180021730(longlong param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  
  puVar1 = operator_new(0x18);
  if (puVar1 == (undefined8 *)0x0) {
    puVar1 = (undefined8 *)0x0;
  }
  else {
    puVar1 = FUN_1800214a0(puVar1,*(longlong **)(param_1 + 0x10));
  }
                    /* WARNING: Could not recover jumptable at 0x00018002177e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)*puVar1)(puVar1,&DAT_180066e18,param_2);
  return;
}

/* ---- FUNC 00021790 FUN_180021790 (110 bytes) ---- */

void FUN_180021790(longlong param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  longlong *plVar2;
  
  puVar1 = operator_new(0x18);
  if (puVar1 == (undefined8 *)0x0) {
    plVar2 = (longlong *)0x0;
  }
  else {
    plVar2 = FUN_1800214d0(puVar1,*(longlong **)(param_1 + 0x10));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    (**(code **)(*plVar2 + 0x20))(plVar2);
  }
                    /* WARNING: Could not recover jumptable at 0x0001800217fb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)*plVar2)(plVar2,&DAT_180066df8,param_2);
  return;
}

/* ---- FUNC 00021800 FUN_180021800 (101 bytes) ---- */

undefined8 FUN_180021800(longlong *param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  puVar1 = operator_new(0x18);
  if (puVar1 == (undefined8 *)0x0) {
    puVar1 = (undefined8 *)0x0;
  }
  else {
    puVar1 = FUN_1800214a0(puVar1,param_1);
  }
  if (puVar1 != (undefined8 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000180021852. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)*puVar1)(puVar1,&DAT_180066e18,param_2);
    return uVar2;
  }
  return 0x8007000e;
}

/* ---- FUNC 00021870 FUN_180021870 (80 bytes) ---- */

void FUN_180021870(longlong *param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  
  puVar1 = operator_new(0x18);
  if (puVar1 == (undefined8 *)0x0) {
    puVar1 = (undefined8 *)0x0;
  }
  else {
    puVar1 = FUN_1800214d0(puVar1,param_1);
  }
                    /* WARNING: Could not recover jumptable at 0x0001800218bd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)*puVar1)(puVar1,&DAT_180066df8,param_2);
  return;
}

/* ---- FUNC 000218C0 FUN_1800218c0 (95 bytes) ---- */

undefined8 FUN_1800218c0(longlong param_1,uint param_2,longlong *param_3)

{
  longlong *plVar1;
  uint uVar2;
  longlong *plVar3;
  
  plVar3 = *(longlong **)(param_1 + 0x20);
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      if (plVar3 == (longlong *)0x0) {
        return 0x80004005;
      }
      plVar3 = (longlong *)plVar3[1];
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_2);
  }
  if (plVar3 == (longlong *)0x0) {
    return 0x80004005;
  }
  plVar1 = (longlong *)*plVar3;
  *param_3 = (longlong)plVar1;
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 8))();
  }
  *(int *)(param_3 + 1) = (int)plVar3[2];
  return 0;
}

/* ---- FUNC 00021920 FUN_180021920 (62 bytes) ---- */

ulonglong FUN_180021920(longlong param_1,longlong *param_2,undefined8 *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  longlong local_18;
  longlong lStack_10;
  
  if ((*param_2 == DAT_180063510) && (param_2[1] == DAT_180063518)) {
    puVar3 = *(undefined8 **)(param_1 + 0x18);
    if (puVar3 == (undefined8 *)0x0) {
      puVar3 = operator_new(0x38);
      if (puVar3 == (undefined8 *)0x0) {
        puVar3 = (undefined8 *)0x0;
      }
      else {
        local_18 = *param_2;
        lStack_10 = param_2[1];
        puVar3 = FUN_180021500(puVar3,&local_18,param_1);
      }
      uVar1 = (**(code **)*puVar3)(puVar3,&DAT_180066e08,param_1 + 0x18);
      uVar2 = (ulonglong)uVar1;
      *param_3 = *(undefined8 *)(param_1 + 0x18);
      (**(code **)(**(longlong **)(param_1 + 0x18) + 8))();
    }
    else {
      uVar2 = (**(code **)*puVar3)(puVar3,&DAT_180066e08);
    }
    return uVar2;
  }
  return 0x80004002;
}

/* ---- FUNC 0002195E FUN_18002195e (44 bytes) ---- */

ulonglong FUN_18002195e(undefined8 *param_1)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  undefined8 *unaff_RBX;
  longlong unaff_RSI;
  undefined8 *unaff_R14;
  undefined8 uStackX_20;
  
  if (param_1 == (undefined8 *)0x0) {
    puVar3 = operator_new(0x38);
    if (puVar3 == (undefined8 *)0x0) {
      puVar3 = (undefined8 *)0x0;
    }
    else {
      uStackX_20 = *unaff_RBX;
      puVar3 = FUN_180021500(puVar3,&uStackX_20,unaff_RSI);
    }
    uVar1 = (**(code **)*puVar3)(puVar3,&DAT_180066e08,unaff_RSI + 0x18);
    uVar2 = (ulonglong)uVar1;
    *unaff_R14 = *(undefined8 *)(unaff_RSI + 0x18);
    (**(code **)(**(longlong **)(unaff_RSI + 0x18) + 8))();
  }
  else {
    uVar2 = (**(code **)*param_1)(param_1,&DAT_180066e08);
  }
  return uVar2;
}

/* ---- FUNC 0002198A FUN_18002198a (90 bytes) ---- */

undefined4 FUN_18002198a(void)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  undefined8 *unaff_RBX;
  longlong unaff_RSI;
  undefined8 *unaff_R14;
  undefined8 uStackX_20;
  
  puVar2 = operator_new(0x38);
  if (puVar2 == (undefined8 *)0x0) {
    puVar2 = (undefined8 *)0x0;
  }
  else {
    uStackX_20 = *unaff_RBX;
    puVar2 = FUN_180021500(puVar2,&uStackX_20,unaff_RSI);
  }
  uVar1 = (**(code **)*puVar2)(puVar2,&DAT_180066e08,unaff_RSI + 0x18);
  *unaff_R14 = *(undefined8 *)(unaff_RSI + 0x18);
  (**(code **)(**(longlong **)(unaff_RSI + 0x18) + 8))();
  return uVar1;
}

/* ---- FUNC 000219E4 FUN_1800219e4 (22 bytes) ---- */

undefined8 FUN_1800219e4(void)

{
  return 0x80004002;
}

/* ---- FUNC 00021A00 FUN_180021a00 (23 bytes) ---- */

undefined8 FUN_180021a00(longlong param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  if (*(longlong *)(param_1 + 0x30) != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x14);
    *param_2 = *(undefined8 *)(param_1 + 0xc);
    param_2[1] = uVar1;
    return 0;
  }
  return 0x80004005;
}

/* ---- FUNC 00021A20 FUN_180021a20 (43 bytes) ---- */

undefined8 FUN_180021a20(longlong param_1,longlong *param_2)

{
  if (*(longlong *)(param_1 + 0x30) != 0) {
    *param_2 = *(longlong *)(param_1 + 0x30);
    (**(code **)(**(longlong **)(param_1 + 0x30) + 8))();
    return 0;
  }
  return 0x80004005;
}

/* ---- FUNC 00021A50 FUN_180021a50 (47 bytes) ---- */

undefined8 FUN_180021a50(longlong param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  
  *param_4 = 0;
  if (*(int *)(param_1 + 0xc) == 1) {
    return 1;
  }
  *param_4 = 1;
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
                    /* WARNING: Could not recover jumptable at 0x000180021a7b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(**(longlong **)(param_1 + 0x10) + 0x20))
                    (*(longlong **)(param_1 + 0x10),&DAT_180063510);
  return uVar1;
}

/* ---- FUNC 00021A80 FUN_180021a80 (47 bytes) ---- */

void FUN_180021a80(longlong param_1,undefined8 param_2,longlong *param_3,uint *param_4)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = *(uint *)(param_1 + 0xc);
  *(uint *)(param_1 + 0xc) = uVar1 + 1;
  uVar2 = FUN_1800218c0(*(longlong *)(param_1 + 0x10),uVar1,param_3);
  if (param_4 != (uint *)0x0) {
    *param_4 = (uint)((int)uVar2 == 0);
  }
  return;
}

/* ---- FUNC 00021AB0 FUN_180021ab0 (104 bytes) ---- */

undefined8 FUN_180021ab0(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  if (((*param_2 != DAT_180066c58) || (param_2[1] != DAT_180066c60)) &&
     ((*param_2 != DAT_180066e18 || (param_2[1] != DAT_180066e20)))) {
    return 0x80004002;
  }
  (**(code **)(*param_1 + 8))();
  *param_3 = param_1;
  return 0;
}

/* ---- FUNC 00021B20 FUN_180021b20 (104 bytes) ---- */

undefined8 FUN_180021b20(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  if (((*param_2 != DAT_180066c58) || (param_2[1] != DAT_180066c60)) &&
     ((*param_2 != DAT_180066df8 || (param_2[1] != DAT_180066e00)))) {
    return 0x80004002;
  }
  (**(code **)(*param_1 + 8))();
  *param_3 = param_1;
  return 0;
}

/* ---- FUNC 00021B90 FUN_180021b90 (104 bytes) ---- */

undefined8 FUN_180021b90(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  if (((*param_2 != DAT_180066c58) || (param_2[1] != DAT_180066c60)) &&
     ((*param_2 != DAT_180066e08 || (param_2[1] != DAT_180066e10)))) {
    return 0x80004002;
  }
  (**(code **)(*param_1 + 8))();
  *param_3 = param_1;
  return 0;
}

/* ---- FUNC 00021C00 FUN_180021c00 (104 bytes) ---- */

undefined8 FUN_180021c00(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  
  if ((*param_2 == DAT_180066e28) && (param_2[1] == DAT_180066e30)) {
    (**(code **)(*param_1 + 8))();
    *param_3 = param_1;
    return 0;
  }
  if ((undefined8 *)param_1[2] == (undefined8 *)0x0) {
    return 0x80004002;
  }
                    /* WARNING: Could not recover jumptable at 0x000180021c65. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)**(undefined8 **)param_1[2])();
  return uVar1;
}

/* ---- FUNC 00021C70 FUN_180021c70 (46 bytes) ---- */

int FUN_180021c70(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 1) + -1;
  *(int *)(param_1 + 1) = iVar1;
  if (iVar1 == 0) {
    FUN_180021550(param_1);
    FUN_180025ad0(param_1);
    iVar1 = 0;
  }
  return iVar1;
}

/* ---- FUNC 00021CA0 FUN_180021ca0 (46 bytes) ---- */

int FUN_180021ca0(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 1) + -1;
  *(int *)(param_1 + 1) = iVar1;
  if (iVar1 == 0) {
    FUN_180021580(param_1);
    FUN_180025ad0(param_1);
    iVar1 = 0;
  }
  return iVar1;
}

/* ---- FUNC 00021CD0 FUN_180021cd0 (46 bytes) ---- */

int FUN_180021cd0(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 1) + -1;
  *(int *)(param_1 + 1) = iVar1;
  if (iVar1 == 0) {
    FUN_1800215b0(param_1);
    FUN_180025ad0(param_1);
    iVar1 = 0;
  }
  return iVar1;
}

/* ---- FUNC 00021D00 FUN_180021d00 (46 bytes) ---- */

int FUN_180021d00(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 1) + -1;
  *(int *)(param_1 + 1) = iVar1;
  if (iVar1 == 0) {
    FUN_180021610(param_1);
    FUN_180025ad0(param_1);
    iVar1 = 0;
  }
  return iVar1;
}

/* ---- FUNC 00021D30 FUN_180021d30 (10 bytes) ---- */

undefined8 FUN_180021d30(longlong param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 0;
  return 0;
}

/* ---- FUNC 00021D40 FUN_180021d40 (8 bytes) ---- */

bool FUN_180021d40(undefined8 param_1,int param_2)

{
  return param_2 != 0;
}

/* ---- FUNC 00021D50 FUN_180021d50 (6 bytes) ---- */

undefined8 FUN_180021d50(longlong param_1,int param_2)

{
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_2;
  return 0;
}

/* ---- FUNC 00021D60 FUN_180021d60 (94 bytes) ---- */

undefined8 FUN_180021d60(longlong param_1,int param_2)

{
  undefined8 *_Memory;
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar2 = *(undefined8 **)(param_1 + 0x20);
  puVar1 = (undefined8 *)0x0;
  while( true ) {
    _Memory = puVar2;
    if (_Memory == (undefined8 *)0x0) {
      return 0x80004005;
    }
    if (*(int *)(_Memory + 2) == param_2) break;
    puVar2 = (undefined8 *)_Memory[1];
    puVar1 = _Memory;
  }
  if (puVar1 == (undefined8 *)0x0) {
    *(undefined8 *)(param_1 + 0x20) = _Memory[1];
  }
  else {
    puVar1[1] = _Memory[1];
  }
  (**(code **)(*(longlong *)*_Memory + 0x10))();
  free(_Memory);
  return 0;
}

/* ---- FUNC 00021DC0 FUN_180021dc0 (20 bytes) ---- */

undefined8 FUN_180021dc0(undefined8 param_1,void *param_2)

{
  free(param_2);
  return 0;
}

/* ---- FUNC 00021DE0 FUN_180021de0 (195 bytes) ---- */

void FUN_180021de0(HWND param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                  LPCSTR param_5,int param_6)

{
  undefined4 uStack_a4;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  LPCSTR pCStack_40;
  int local_38;
  uint uStack_2c;
  undefined8 local_28;
  
  local_38 = lstrlenA(param_5);
  local_58 = CONCAT44(uStack_a4,0x45);
  uStack_2c = (uint)(param_6 != 0);
  pCStack_40 = param_5;
  local_68 = param_4;
  local_60 = param_3;
  local_28 = param_2;
  SendMessageA(param_1,0x1100,0,(LPARAM)&local_68);
  return;
}

/* ---- FUNC 00021EB0 FUN_180021eb0 (247 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180021eb0(HWND param_1,HINSTANCE param_2,undefined8 param_3)

{
  HWND pHVar1;
  longlong lVar2;
  undefined1 auStackY_98 [32];
  undefined8 *local_38;
  tagRECT local_30;
  ulonglong local_20;
  
  local_20 = DAT_180077818 ^ (ulonglong)auStackY_98;
  local_38 = (undefined8 *)0x0;
  InitCommonControls();
  GetClientRect(param_1,&local_30);
  pHVar1 = CreateWindowExA(0,"SysTreeView32","Variable Browser",0x50000027,0,0,local_30.right,
                           local_30.bottom,param_1,(HMENU)0x0,param_2,(LPVOID)0x0);
  if (pHVar1 != (HWND)0x0) {
    lVar2 = HAGetTree(param_3,&local_38);
    if (lVar2 != 0) {
      FUN_180021fb0(pHVar1,lVar2,0,0xffffffffffff0000);
      return 1;
    }
    if ((local_38 != (undefined8 *)0x0) && ((code *)*local_38 != (code *)0x0)) {
      (*(code *)*local_38)();
    }
  }
  return 0;
}

/* ---- FUNC 00021FB0 FUN_180021fb0 (103 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180021fb0(HWND param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  uint uVar5;
  undefined8 **ppuVar6;
  undefined1 auStackY_a8 [32];
  undefined8 *local_78;
  uint local_70 [2];
  char *local_68;
  char local_60 [24];
  ulonglong local_48;
  
  local_48 = DAT_180077818 ^ (ulonglong)auStackY_a8;
  local_78 = (undefined8 *)0x0;
  iVar1 = HAGetLength(param_2,0,&local_78);
  if (iVar1 == -1) {
    if ((local_78 != (undefined8 *)0x0) && ((code *)*local_78 != (code *)0x0)) {
      (*(code *)*local_78)();
    }
  }
  else {
    local_68 = local_60;
    uVar5 = 0;
    uVar4 = 0;
    if (0 < iVar1) {
      do {
        ppuVar6 = &local_78;
        local_70[0] = uVar5;
        lVar3 = HAGetElement(param_2,local_70,&local_68);
        if (lVar3 == 0) {
LAB_1800220c7:
          if (local_78 == (undefined8 *)0x0) {
            return;
          }
          if ((code *)*local_78 == (code *)0x0) {
            return;
          }
          (*(code *)*local_78)();
          return;
        }
        if (local_60[0] == '\0') {
          FUN_180002a20(local_60,&DAT_180064abc,(ulonglong)uVar5,ppuVar6);
        }
        iVar2 = HAIsList(lVar3,&local_78);
        if (iVar2 == -1) goto LAB_1800220c7;
        uVar4 = FUN_180021de0(param_1,lVar3,uVar4,param_4,local_60,(uint)(iVar2 != 0));
        uVar5 = uVar5 + 1;
      } while ((int)uVar5 < iVar1);
    }
  }
  return;
}

/* ---- FUNC 00022017 FUN_180022017 (36 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180022017(void)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  uint uVar4;
  int unaff_ESI;
  undefined8 *puVar5;
  HWND unaff_R12;
  undefined8 unaff_R15;
  undefined8 *in_stack_00000030;
  uint uStack0000000000000038;
  undefined1 *puStack0000000000000040;
  char in_stack_00000048;
  
  puStack0000000000000040 = &stack0x00000048;
  uVar4 = 0;
  uVar3 = 0;
  if (0 < unaff_ESI) {
    do {
      puVar5 = &stack0x00000030;
      uStack0000000000000038 = uVar4;
      lVar2 = HAGetElement();
      if (lVar2 == 0) {
LAB_1800220c7:
        if (in_stack_00000030 == (undefined8 *)0x0) {
          return;
        }
        if ((code *)*in_stack_00000030 == (code *)0x0) {
          return;
        }
        (*(code *)*in_stack_00000030)();
        return;
      }
      if (in_stack_00000048 == '\0') {
        FUN_180002a20(&stack0x00000048,&DAT_180064abc,(ulonglong)uVar4,puVar5);
      }
      iVar1 = HAIsList(lVar2,&stack0x00000030);
      if (iVar1 == -1) goto LAB_1800220c7;
      uVar3 = FUN_180021de0(unaff_R12,lVar2,uVar3,unaff_R15,&stack0x00000048,(uint)(iVar1 != 0));
      uVar4 = uVar4 + 1;
    } while ((int)uVar4 < unaff_ESI);
  }
  return;
}

/* ---- FUNC 0002203B FUN_18002203b (165 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18002203b(void)

{
  int iVar1;
  longlong lVar2;
  uint unaff_EBX;
  int unaff_ESI;
  undefined8 *puVar3;
  HWND unaff_R12;
  undefined8 unaff_R14;
  undefined8 unaff_R15;
  undefined8 *in_stack_00000030;
  uint uStack0000000000000038;
  char in_stack_00000048;
  
  while( true ) {
    puVar3 = &stack0x00000030;
    uStack0000000000000038 = unaff_EBX;
    lVar2 = HAGetElement();
    if (lVar2 == 0) break;
    if (in_stack_00000048 == '\0') {
      FUN_180002a20(&stack0x00000048,&DAT_180064abc,(ulonglong)unaff_EBX,puVar3);
    }
    iVar1 = HAIsList(lVar2,&stack0x00000030);
    if (iVar1 == -1) break;
    unaff_R14 = FUN_180021de0(unaff_R12,lVar2,unaff_R14,unaff_R15,&stack0x00000048,
                              (uint)(iVar1 != 0));
    unaff_EBX = unaff_EBX + 1;
    if (unaff_ESI <= (int)unaff_EBX) {
      return;
    }
  }
  if (in_stack_00000030 == (undefined8 *)0x0) {
    return;
  }
  if ((code *)*in_stack_00000030 == (code *)0x0) {
    return;
  }
  (*(code *)*in_stack_00000030)();
  return;
}

/* ---- FUNC 000220E0 FUN_1800220e0 (13 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1800220e0(void)

{
  return;
}

/* ---- FUNC 000220ED FUN_1800220ed (27 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1800220ed(void)

{
  return;
}

/* ---- FUNC 00022110 HappActivateRunningObject (564 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

LPCOLESTR HappActivateRunningObject(LPCSTR param_1,undefined8 *param_2)

{
  LPCOLESTR pOVar1;
  _func_5302 *p_Var2;
  _func_5320 *p_Var3;
  _func_5298 *p_Var4;
  _func_5156 *p_Var5;
  code *pcVar6;
  _func_5158 *p_Var7;
  LPRUNNINGOBJECTTABLE pIVar8;
  LPMONIKER pIVar9;
  IUnknown *pIVar10;
  longlong *plVar11;
  HRESULT HVar12;
  longlong lVar13;
  IRunningObjectTableVtbl *pIVar15;
  ulonglong uVar16;
  int iVar17;
  LPCOLESTR pOVar18;
  undefined1 *puVar19;
  LPCOLESTR lpszPathName;
  undefined8 uStack_90;
  undefined1 auStack_88 [32];
  undefined8 uStack_68;
  int aiStack_60 [2];
  LPRUNNINGOBJECTTABLE local_58;
  LPMONIKER local_50;
  IUnknown *local_48;
  longlong *local_40;
  longlong *local_38;
  longlong local_30;
  longlong lStack_28;
  ulonglong local_20;
  longlong lVar14;
  
                    /* 0x22110  40  HappActivateRunningObject */
  puVar19 = auStack_88;
  local_20 = DAT_180077818 ^ (ulonglong)&local_58;
  pOVar18 = (LPCOLESTR)0x0;
  local_40 = (longlong *)0x0;
  local_48 = (IUnknown *)0x0;
  local_50 = (IMoniker *)0x0;
  local_58 = (IRunningObjectTable *)0x0;
  uStack_90 = 0x180022158;
  HVar12 = GetRunningObjectTable(0,&local_58);
  if (-1 < HVar12) {
    puVar19 = auStack_88;
    lpszPathName = pOVar18;
    if (param_1 != (LPCSTR)0x0) {
      lVar13 = -1;
      do {
        lVar14 = lVar13;
        lVar13 = lVar14 + 1;
      } while (param_1[lVar13] != '\0');
      iVar17 = (int)lVar14 + 2;
      puVar19 = auStack_88;
      if (iVar17 < 0x40000000) {
        lVar13 = (longlong)(int)lVar13 * 2;
        uVar16 = lVar13 + 0x11;
        if (uVar16 <= lVar13 + 2U) {
          uVar16 = 0xffffffffffffff0;
        }
        uStack_90 = 0x1800221ac;
        lVar13 = -(uVar16 & 0xfffffffffffffff0);
        pOVar1 = (LPCOLESTR)((longlong)&local_58 + lVar13);
        puVar19 = auStack_88 + lVar13;
        if (pOVar1 != (LPCOLESTR)0x0) {
          *pOVar1 = L'\0';
          *(int *)((longlong)aiStack_60 + lVar13) = iVar17;
          *(LPCOLESTR *)((longlong)&uStack_68 + lVar13) = pOVar1;
          *(undefined8 *)(auStack_88 + lVar13 + -8) = 0x1800221d8;
          iVar17 = MultiByteToWideChar(0,0,param_1,-1,*(LPWSTR *)((longlong)&uStack_68 + lVar13),
                                       *(int *)((longlong)aiStack_60 + lVar13));
          puVar19 = auStack_88 + lVar13;
          lpszPathName = pOVar1;
          if (iVar17 == 0) {
            puVar19 = auStack_88 + lVar13;
            lpszPathName = pOVar18;
          }
        }
      }
    }
    *(undefined8 *)(puVar19 + -8) = 0x1800221f0;
    HVar12 = CreateFileMoniker(lpszPathName,&local_50);
    pIVar9 = local_50;
    pIVar8 = local_58;
    pIVar15 = local_58->lpVtbl;
    if (-1 < HVar12) {
      p_Var2 = pIVar15->GetObjectA;
      *(undefined8 *)(puVar19 + -8) = 0x180022206;
      HVar12 = (*p_Var2)(pIVar8,pIVar9,&local_48);
      pIVar10 = local_48;
      pIVar9 = local_50;
      if (-1 < HVar12) {
        local_30 = DAT_180066d68;
        lStack_28 = DAT_180066d70;
        local_38 = (longlong *)0x0;
        if (local_48 != (IUnknown *)0x0) {
          p_Var5 = local_48->lpVtbl->QueryInterface;
          *(undefined8 *)(puVar19 + -8) = 0x180022253;
          HVar12 = (*p_Var5)(pIVar10,(IID *)&DAT_180064ac8,&local_38);
          if (HVar12 < 0) {
            local_38 = (longlong *)0x0;
          }
        }
        plVar11 = local_38;
        if (local_38 != (longlong *)0x0) {
          pcVar6 = *(code **)(*local_38 + 0x18);
          *(undefined8 *)(puVar19 + -8) = 0x180022273;
          (*pcVar6)(plVar11,&local_30);
        }
        pIVar9 = local_50;
        if ((local_30 == DAT_180063520) && (lStack_28 == DAT_180063528)) {
          p_Var3 = local_50->lpVtbl->Release;
          *(undefined8 *)(puVar19 + -8) = 0x180022297;
          (*p_Var3)(pIVar9);
          pIVar8 = local_58;
          p_Var4 = local_58->lpVtbl->Release;
          *(undefined8 *)(puVar19 + -8) = 0x1800222a1;
          (*p_Var4)(pIVar8);
          pIVar10 = local_48;
          p_Var5 = local_48->lpVtbl->QueryInterface;
          *(undefined8 *)(puVar19 + -8) = 0x1800222b5;
          HVar12 = (*p_Var5)(pIVar10,(IID *)&DAT_180063460,&local_40);
          if (-1 < HVar12) {
            pcVar6 = *(code **)(*local_40 + 0x130);
            *(undefined8 *)(puVar19 + -8) = 0x1800222c6;
            iVar17 = (*pcVar6)();
            if (-1 < iVar17) {
              if (param_2 != (undefined8 *)0x0) {
                *param_2 = local_40;
                pcVar6 = *(code **)(*local_40 + 8);
                *(undefined8 *)(puVar19 + -8) = 0x1800222dc;
                (*pcVar6)();
              }
              pOVar18 = (LPCOLESTR)0x1;
            }
            pcVar6 = *(code **)(*local_40 + 0x10);
            *(undefined8 *)(puVar19 + -8) = 0x1800222eb;
            (*pcVar6)();
          }
          pIVar10 = local_48;
          p_Var7 = local_48->lpVtbl->Release;
          *(undefined8 *)(puVar19 + -8) = 0x1800222f5;
          (*p_Var7)(pIVar10);
        }
        else {
          p_Var3 = local_50->lpVtbl->Release;
          *(undefined8 *)(puVar19 + -8) = 0x180022301;
          (*p_Var3)(pIVar9);
          pIVar8 = local_58;
          p_Var4 = local_58->lpVtbl->Release;
          *(undefined8 *)(puVar19 + -8) = 0x18002230b;
          (*p_Var4)(pIVar8);
          pIVar10 = local_48;
          p_Var7 = local_48->lpVtbl->Release;
          *(undefined8 *)(puVar19 + -8) = 0x180022315;
          (*p_Var7)(pIVar10);
        }
        if (local_38 != (longlong *)0x0) {
          pcVar6 = *(code **)(*local_38 + 0x10);
          *(undefined8 *)(puVar19 + -8) = 0x180022325;
          (*pcVar6)();
        }
        goto LAB_180022327;
      }
      p_Var3 = local_50->lpVtbl->Release;
      *(undefined8 *)(puVar19 + -8) = 0x180022214;
      (*p_Var3)(pIVar9);
      pIVar15 = local_58->lpVtbl;
    }
    pIVar8 = local_58;
    p_Var4 = pIVar15->Release;
    *(undefined8 *)(puVar19 + -8) = 0x18002221e;
    (*p_Var4)(pIVar8);
  }
  pOVar18 = (LPCOLESTR)0x0;
LAB_180022327:
  *(undefined8 *)(puVar19 + -8) = 0x180022333;
  return pOVar18;
}

/* ---- FUNC 00022350 HappCanExecuteEOSyncErrorsCommand (238 bytes) ---- */

uint HappCanExecuteEOSyncErrorsCommand(void)

{
  int iVar1;
  longlong *plVar2;
  uint uVar3;
  undefined4 uVar4;
  longlong *local_res8;
  _union_2707 local_58;
  _union_2707 local_40;
  undefined4 local_28;
  ULONG UStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined8 local_18;
  
                    /* 0x22350  71  HappCanExecuteEOSyncErrorsCommand */
  plVar2 = (longlong *)HappGetTree();
  if (plVar2 == (longlong *)0x0) {
    return 0;
  }
  uVar3 = 0;
  VariantInit((VARIANTARG *)&local_40.n2);
  VariantInit((VARIANTARG *)&local_58.n2);
  iVar1 = (**(code **)(*plVar2 + 0x110))(plVar2,L"Data",&local_res8);
  if ((-1 < iVar1) && (local_res8 != (longlong *)0x0)) {
    local_28 = local_40._0_4_;
    UStack_24 = local_40.decVal.Hi32;
    uStack_20 = local_40._8_4_;
    uStack_1c = local_40._12_4_;
    local_18 = local_40._16_8_;
    iVar1 = (**(code **)(*local_res8 + 0x98))(local_res8,0xc,&local_28,&local_58);
    uVar4 = 0;
    if (-1 < iVar1) {
      uVar4 = 0;
      if (local_58.n2.vt == 3) {
        uVar4 = local_58._8_4_;
      }
    }
    uVar3 = (uint)((uVar4 & 0xd8000) != 0);
    VariantClear((VARIANTARG *)&local_58.n2);
    (**(code **)(*local_res8 + 0x10))();
  }
  (**(code **)(*plVar2 + 0x10))(plVar2);
  return uVar3;
}

/* ---- FUNC 00022440 HappCanExportDynamics (7 bytes) ---- */

void HappCanExportDynamics(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180022440. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x22440  53  HappCanExportDynamics */
  HACanExportDynamics();
  return;
}

/* ---- FUNC 00022450 HappCanRunPressureChecker (7 bytes) ---- */

void HappCanRunPressureChecker(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180022450. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x22450  44  HappCanRunPressureChecker */
  HACanRunPressureChecker();
  return;
}

/* ---- FUNC 00022460 HappCopyFormatSelect (128 bytes) ---- */

void HappCopyFormatSelect(void)

{
  int iVar1;
  wchar_t *bstrString;
  longlong *local_res8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res10 [24];
  
                    /* 0x22460  28  HappCopyFormatSelect */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10,"VBSelect");
  bstrString = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::AllocSysString
                         (local_res10);
  iVar1 = (**(code **)(*DAT_1800797f0 + 0xd0))(DAT_1800797f0,bstrString,&local_res8);
  if (iVar1 < 0) {
    SysFreeString(bstrString);
  }
  else {
    SysFreeString(bstrString);
    (**(code **)(*local_res8 + 0xa0))();
    (**(code **)(*local_res8 + 0x10))();
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10);
  return;
}

/* ---- FUNC 000224E0 HappCopySelect (128 bytes) ---- */

void HappCopySelect(void)

{
  int iVar1;
  wchar_t *bstrString;
  longlong *local_res8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res10 [24];
  
                    /* 0x224e0  27  HappCopySelect */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10,"VBSelect");
  bstrString = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::AllocSysString
                         (local_res10);
  iVar1 = (**(code **)(*DAT_1800797f0 + 0xd0))(DAT_1800797f0,bstrString,&local_res8);
  if (iVar1 < 0) {
    SysFreeString(bstrString);
  }
  else {
    SysFreeString(bstrString);
    (**(code **)(*local_res8 + 0x98))();
    (**(code **)(*local_res8 + 0x10))();
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10);
  return;
}

/* ---- FUNC 00022560 HappDOA (11 bytes) ---- */

void HappDOA(void)

{
                    /* 0x22560  49  HappDOA */
  DAT_18007958c = 1;
  return;
}

/* ---- FUNC 00022570 HappDialog (5 bytes) ---- */

void HappDialog(void)

{
                    /* 0x22570  39  HappDialog */
                    /* WARNING: Could not recover jumptable at 0x00018005bbab. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  gxDriveDialog();
  return;
}

/* ---- FUNC 00022580 HappEditLinks (12 bytes) ---- */

void HappEditLinks(void)

{
                    /* 0x22580  36  HappEditLinks */
  FUN_18000fc60(DAT_1800797f0);
  return;
}

/* ---- FUNC 00022590 HappEditsAllowed (568 bytes) ---- */

uint HappEditsAllowed(void)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  undefined7 extraout_var;
  wchar_t *bstrString;
  undefined7 extraout_var_00;
  uint uVar4;
  uint uVar5;
  short local_res8 [4];
  uint local_res10 [2];
  int local_res18 [2];
  longlong *local_res20;
  longlong *local_c8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_c0 [8];
  _union_2707 local_b8;
  _union_2707 local_a0;
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
  _union_2707 local_48;
  VARIANTARG local_30;
  
                    /* 0x22590  29  HappEditsAllowed */
  bVar1 = FUN_18000ed90((longlong)DAT_1800797f0);
  uVar4 = -(uint)((int)CONCAT71(extraout_var,bVar1) != 0) & 0x10;
  VariantInit((VARIANTARG *)&local_b8.n2);
  VariantInit((VARIANTARG *)&local_a0.n2);
  VariantInit((VARIANTARG *)&local_48.n2);
  VariantInit(&local_30);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_c0,"VBSelect");
  bstrString = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::AllocSysString
                         (local_c0);
  iVar3 = (**(code **)(*DAT_1800797f0 + 0xd0))(DAT_1800797f0,bstrString,&local_res20);
  if (iVar3 < 0) {
    SysFreeString(bstrString);
  }
  else {
    SysFreeString(bstrString);
    (**(code **)(*local_res20 + 0x48))(local_res20,local_res18);
    if (0 < local_res18[0]) {
      uVar5 = uVar4 | 3;
      if (local_res18[0] == 1) {
        local_b8.n2.vt = 3;
        local_b8._8_4_ = 0;
        local_88 = local_b8._0_4_;
        UStack_84 = local_b8.decVal.Hi32;
        uStack_80 = 0;
        uStack_7c = local_b8._12_4_;
        local_78 = local_b8._16_8_;
        (**(code **)(*local_res20 + 0x58))(local_res20,&local_88,local_res8);
        if (local_res8[0] == 0) {
          local_a0.n2.vt = 9;
          local_88 = local_b8._0_4_;
          UStack_84 = local_b8.decVal.Hi32;
          uStack_80 = local_b8._8_4_;
          uStack_7c = local_b8._12_4_;
          local_78 = local_b8._16_8_;
          (**(code **)(*local_res20 + 0x50))(local_res20,&local_88,&local_a0);
          local_68 = local_48._0_4_;
          UStack_64 = local_48.decVal.Hi32;
          uStack_60 = local_48._8_4_;
          uStack_5c = local_48._12_4_;
          local_58 = local_48._16_8_;
          (**(code **)(*(longlong *)local_a0.decVal.u2 + 0x98))
                    (local_a0.decVal.u2.Lo64,0x12,&local_68,&local_30);
          VariantClear((VARIANTARG *)&local_a0.n2);
          if ((local_30.n1._8_4_ == 0) &&
             (bVar2 = FUN_1800246f0(), (int)CONCAT71(extraout_var_00,bVar2) != 0)) {
            uVar5 = uVar4 | 0xf;
          }
        }
        else if (local_res8[0] == 100) {
          local_a0.n2.vt = 0xd;
          local_68 = local_b8._0_4_;
          UStack_64 = local_b8.decVal.Hi32;
          uStack_60 = local_b8._8_4_;
          uStack_5c = local_b8._12_4_;
          local_58 = local_b8._16_8_;
          (**(code **)(*local_res20 + 0x50))(local_res20,&local_68,&local_a0);
          local_c8 = (longlong *)0x0;
          if ((local_a0.decVal.u2.Lo64 != 0) &&
             (iVar3 = (*(code *)**(undefined8 **)local_a0.decVal.u2)
                                (local_a0.decVal.u2.Lo64,&DAT_180063818,&local_c8), iVar3 < 0)) {
            local_c8 = (longlong *)0x0;
          }
          uVar5 = 0;
          if (local_c8 != (longlong *)0x0) {
            local_res10[0] = 0;
            iVar3 = (**(code **)(*local_c8 + 0x28))(local_c8,local_res10);
            uVar5 = 0;
            if (iVar3 == 0) {
              uVar5 = local_res10[0];
            }
          }
          if (local_c8 != (longlong *)0x0) {
            (**(code **)(*local_c8 + 0x10))();
          }
        }
      }
      uVar4 = uVar5;
      if (1 < local_res18[0]) {
        uVar4 = uVar4 | 0x20;
      }
    }
    (**(code **)(*local_res20 + 0x10))();
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_c0);
  return uVar4;
}

/* ---- FUNC 000227D0 HappEstablishLink (26 bytes) ---- */

undefined8 HappEstablishLink(void)

{
                    /* 0x227d0  55  HappEstablishLink */
  FUN_180010090(DAT_1800797f0);
  return 1;
}

/* ---- FUNC 000227F0 HappFireBeforeCalculate (479 bytes) ---- */

void HappFireBeforeCalculate(undefined4 param_1,int *param_2)

{
  int iVar1;
  int local_res18 [2];
  undefined4 local_res20;
  longlong *local_88;
  longlong *local_80;
  longlong *local_78;
  IDispatch *local_70;
  COleDispatchDriver local_68 [16];
  undefined1 local_58 [8];
  AFX_EXCEPTION_LINK local_50 [16];
  longlong *local_40 [5];
  
                    /* 0x227f0  57  HappFireBeforeCalculate */
  if (DAT_1800797f0 != (undefined8 *)0x0) {
    local_res18[0] = 0;
    local_78 = (longlong *)0x0;
    local_80 = (longlong *)0x0;
    local_res20 = param_1;
    iVar1 = (**(code **)*DAT_1800797f0)(DAT_1800797f0,&DAT_180066e28,&local_78);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_78 + 0x20))(local_78,&DAT_180063510,&local_80);
      if (-1 < iVar1) {
        COleDispatchDriver::COleDispatchDriver(local_68);
        iVar1 = (**(code **)(*local_80 + 0x38))(local_80,&local_88);
        if (-1 < iVar1) {
          (**(code **)(*local_88 + 0x28))();
          while (local_res18[0] == 0) {
            iVar1 = (**(code **)(*local_88 + 0x18))(local_88,1,local_40,local_58);
            if (iVar1 != 0) break;
            if (local_40[0] != (longlong *)0x0) {
              local_70 = (IDispatch *)0x0;
              iVar1 = (**(code **)*local_40[0])(local_40[0],&DAT_180066c78,&local_70);
              if (-1 < iVar1) {
                COleDispatchDriver::AttachDispatch(local_68,local_70,1);
                AFX_EXCEPTION_LINK::AFX_EXCEPTION_LINK(local_50);
                COleDispatchDriver::InvokeHelper
                          (local_68,0x6b,1,0,(void *)0x0,&DAT_1800776e4,local_res20,local_res18);
                AfxTryCleanup();
                COleDispatchDriver::ReleaseDispatch(local_68);
              }
              (**(code **)(*local_40[0] + 0x10))();
            }
          }
          (**(code **)(*local_88 + 0x10))();
        }
        (**(code **)(*local_80 + 0x10))();
        COleDispatchDriver::ReleaseDispatch(local_68);
      }
      (**(code **)(*local_78 + 0x10))();
    }
    if (param_2 != (int *)0x0) {
      *param_2 = local_res18[0];
    }
  }
  return;
}

/* ---- FUNC 000229D0 HappFireBeforeSave (470 bytes) ---- */

void HappFireBeforeSave(undefined8 param_1,int *param_2)

{
  int iVar1;
  int local_res18 [2];
  undefined1 local_res20 [8];
  longlong *local_88;
  longlong *local_80;
  longlong *local_78;
  IDispatch *local_70;
  COleDispatchDriver local_68 [16];
  AFX_EXCEPTION_LINK local_58 [16];
  longlong *local_48 [6];
  
                    /* 0x229d0  58  HappFireBeforeSave */
  if (DAT_1800797f0 != (undefined8 *)0x0) {
    local_res18[0] = 0;
    local_78 = (longlong *)0x0;
    local_80 = (longlong *)0x0;
    iVar1 = (**(code **)*DAT_1800797f0)(DAT_1800797f0,&DAT_180066e28,&local_78);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_78 + 0x20))(local_78,&DAT_180063510,&local_80);
      if (-1 < iVar1) {
        COleDispatchDriver::COleDispatchDriver(local_68);
        iVar1 = (**(code **)(*local_80 + 0x38))(local_80,&local_88);
        if (-1 < iVar1) {
          (**(code **)(*local_88 + 0x28))();
          while (local_res18[0] == 0) {
            iVar1 = (**(code **)(*local_88 + 0x18))(local_88,1,local_48,local_res20);
            if (iVar1 != 0) break;
            if (local_48[0] != (longlong *)0x0) {
              local_70 = (IDispatch *)0x0;
              iVar1 = (**(code **)*local_48[0])(local_48[0],&DAT_180066c78,&local_70);
              if (-1 < iVar1) {
                COleDispatchDriver::AttachDispatch(local_68,local_70,1);
                AFX_EXCEPTION_LINK::AFX_EXCEPTION_LINK(local_58);
                COleDispatchDriver::InvokeHelper
                          (local_68,0x6c,1,0,(void *)0x0,&DAT_1800776e8,param_1,local_res18);
                AfxTryCleanup();
                COleDispatchDriver::ReleaseDispatch(local_68);
              }
              (**(code **)(*local_48[0] + 0x10))();
            }
          }
          (**(code **)(*local_88 + 0x10))();
        }
        (**(code **)(*local_80 + 0x10))();
        COleDispatchDriver::ReleaseDispatch(local_68);
      }
      (**(code **)(*local_78 + 0x10))();
    }
    if (param_2 != (int *)0x0) {
      *param_2 = local_res18[0];
    }
  }
  return;
}

/* ---- FUNC 00022BB0 HappFireCalculationCompleted (401 bytes) ---- */

void HappFireCalculationCompleted(void)

{
  int iVar1;
  undefined1 local_res8 [8];
  longlong *local_res10;
  longlong *local_res18;
  longlong *local_res20;
  IDispatch *local_68 [4];
  COleDispatchDriver local_48 [16];
  AFX_EXCEPTION_LINK local_38 [16];
  longlong *local_28 [3];
  
                    /* 0x22bb0  59  HappFireCalculationCompleted */
  if (DAT_1800797f0 != (undefined8 *)0x0) {
    local_res20 = (longlong *)0x0;
    local_res18 = (longlong *)0x0;
    iVar1 = (**(code **)*DAT_1800797f0)(DAT_1800797f0,&DAT_180066e28,&local_res20);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_res20 + 0x20))(local_res20,&DAT_180063510,&local_res18);
      if (-1 < iVar1) {
        COleDispatchDriver::COleDispatchDriver(local_48);
        iVar1 = (**(code **)(*local_res18 + 0x38))(local_res18,&local_res10);
        if (-1 < iVar1) {
          (**(code **)(*local_res10 + 0x28))();
          while( true ) {
            iVar1 = (**(code **)(*local_res10 + 0x18))(local_res10,1,local_28,local_res8);
            if (iVar1 != 0) break;
            if (local_28[0] != (longlong *)0x0) {
              local_68[0] = (IDispatch *)0x0;
              iVar1 = (**(code **)*local_28[0])(local_28[0],&DAT_180066c78,local_68);
              if (-1 < iVar1) {
                COleDispatchDriver::AttachDispatch(local_48,local_68[0],1);
                AFX_EXCEPTION_LINK::AFX_EXCEPTION_LINK(local_38);
                COleDispatchDriver::InvokeHelper(local_48,0x6d,1,0,(void *)0x0,(uchar *)0x0);
                AfxTryCleanup();
                COleDispatchDriver::ReleaseDispatch(local_48);
              }
              (**(code **)(*local_28[0] + 0x10))();
            }
          }
          (**(code **)(*local_res10 + 0x10))();
        }
        (**(code **)(*local_res18 + 0x10))();
        COleDispatchDriver::ReleaseDispatch(local_48);
      }
      (**(code **)(*local_res20 + 0x10))();
    }
  }
  return;
}

/* ---- FUNC 00022D50 HappFireCalculationStopped (401 bytes) ---- */

void HappFireCalculationStopped(void)

{
  int iVar1;
  undefined1 local_res8 [8];
  longlong *local_res10;
  longlong *local_res18;
  longlong *local_res20;
  IDispatch *local_68 [4];
  COleDispatchDriver local_48 [16];
  AFX_EXCEPTION_LINK local_38 [16];
  longlong *local_28 [3];
  
                    /* 0x22d50  63  HappFireCalculationStopped */
  if (DAT_1800797f0 != (undefined8 *)0x0) {
    local_res20 = (longlong *)0x0;
    local_res18 = (longlong *)0x0;
    iVar1 = (**(code **)*DAT_1800797f0)(DAT_1800797f0,&DAT_180066e28,&local_res20);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_res20 + 0x20))(local_res20,&DAT_180063510,&local_res18);
      if (-1 < iVar1) {
        COleDispatchDriver::COleDispatchDriver(local_48);
        iVar1 = (**(code **)(*local_res18 + 0x38))(local_res18,&local_res10);
        if (-1 < iVar1) {
          (**(code **)(*local_res10 + 0x28))();
          while( true ) {
            iVar1 = (**(code **)(*local_res10 + 0x18))(local_res10,1,local_28,local_res8);
            if (iVar1 != 0) break;
            if (local_28[0] != (longlong *)0x0) {
              local_68[0] = (IDispatch *)0x0;
              iVar1 = (**(code **)*local_28[0])(local_28[0],&DAT_180066c78,local_68);
              if (-1 < iVar1) {
                COleDispatchDriver::AttachDispatch(local_48,local_68[0],1);
                AFX_EXCEPTION_LINK::AFX_EXCEPTION_LINK(local_38);
                COleDispatchDriver::InvokeHelper(local_48,0x6e,1,0,(void *)0x0,(uchar *)0x0);
                AfxTryCleanup();
                COleDispatchDriver::ReleaseDispatch(local_48);
              }
              (**(code **)(*local_28[0] + 0x10))();
            }
          }
          (**(code **)(*local_res10 + 0x10))();
        }
        (**(code **)(*local_res18 + 0x10))();
        COleDispatchDriver::ReleaseDispatch(local_48);
      }
      (**(code **)(*local_res20 + 0x10))();
    }
  }
  return;
}

/* ---- FUNC 00022EF0 HappFireControlPanelMessage (446 bytes) ---- */

void HappFireControlPanelMessage(undefined4 param_1,undefined8 param_2)

{
  int iVar1;
  undefined2 local_res18;
  undefined1 local_res1a;
  undefined1 local_res20 [8];
  longlong *local_88;
  longlong *local_80;
  longlong *local_78;
  IDispatch *local_70;
  COleDispatchDriver local_68 [16];
  AFX_EXCEPTION_LINK local_58 [16];
  longlong *local_48 [7];
  
                    /* 0x22ef0  70  HappFireControlPanelMessage */
  if (DAT_1800797f0 != (undefined8 *)0x0) {
    local_78 = (longlong *)0x0;
    local_80 = (longlong *)0x0;
    local_res18 = DAT_180064b64;
    local_res1a = DAT_180064b66;
    iVar1 = (**(code **)*DAT_1800797f0)(DAT_1800797f0,&DAT_180066e28,&local_78);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_78 + 0x20))(local_78,&DAT_180063510,&local_80);
      if (-1 < iVar1) {
        COleDispatchDriver::COleDispatchDriver(local_68);
        iVar1 = (**(code **)(*local_80 + 0x38))(local_80,&local_88);
        if (-1 < iVar1) {
          (**(code **)(*local_88 + 0x28))();
          while( true ) {
            iVar1 = (**(code **)(*local_88 + 0x18))(local_88,1,local_48,local_res20);
            if (iVar1 != 0) break;
            if (local_48[0] != (longlong *)0x0) {
              local_70 = (IDispatch *)0x0;
              iVar1 = (**(code **)*local_48[0])(local_48[0],&DAT_180066c78,&local_70);
              if (-1 < iVar1) {
                COleDispatchDriver::AttachDispatch(local_68,local_70,1);
                AFX_EXCEPTION_LINK::AFX_EXCEPTION_LINK(local_58);
                COleDispatchDriver::InvokeHelper
                          (local_68,0x65,1,0,(void *)0x0,(uchar *)&local_res18,param_1,param_2);
                AfxTryCleanup();
                COleDispatchDriver::ReleaseDispatch(local_68);
              }
              (**(code **)(*local_48[0] + 0x10))();
            }
          }
          (**(code **)(*local_88 + 0x10))();
        }
        (**(code **)(*local_80 + 0x10))();
        COleDispatchDriver::ReleaseDispatch(local_68);
      }
      (**(code **)(*local_78 + 0x10))();
    }
  }
  return;
}

/* ---- FUNC 000230B0 FUN_1800230b0 (401 bytes) ---- */

void FUN_1800230b0(void)

{
  int iVar1;
  undefined1 local_res8 [8];
  longlong *local_res10;
  longlong *local_res18;
  longlong *local_res20;
  IDispatch *local_68 [4];
  COleDispatchDriver local_48 [16];
  AFX_EXCEPTION_LINK local_38 [16];
  longlong *local_28 [3];
  
  if (DAT_1800797f0 != (undefined8 *)0x0) {
    local_res20 = (longlong *)0x0;
    local_res18 = (longlong *)0x0;
    iVar1 = (**(code **)*DAT_1800797f0)(DAT_1800797f0,&DAT_180066e28,&local_res20);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_res20 + 0x20))(local_res20,&DAT_180063510,&local_res18);
      if (-1 < iVar1) {
        COleDispatchDriver::COleDispatchDriver(local_48);
        iVar1 = (**(code **)(*local_res18 + 0x38))(local_res18,&local_res10);
        if (-1 < iVar1) {
          (**(code **)(*local_res10 + 0x28))();
          while( true ) {
            iVar1 = (**(code **)(*local_res10 + 0x18))(local_res10,1,local_28,local_res8);
            if (iVar1 != 0) break;
            if (local_28[0] != (longlong *)0x0) {
              local_68[0] = (IDispatch *)0x0;
              iVar1 = (**(code **)*local_28[0])(local_28[0],&DAT_180066c78,local_68);
              if (-1 < iVar1) {
                COleDispatchDriver::AttachDispatch(local_48,local_68[0],1);
                AFX_EXCEPTION_LINK::AFX_EXCEPTION_LINK(local_38);
                COleDispatchDriver::InvokeHelper(local_48,0x70,1,0,(void *)0x0,(uchar *)0x0);
                AfxTryCleanup();
                COleDispatchDriver::ReleaseDispatch(local_48);
              }
              (**(code **)(*local_28[0] + 0x10))();
            }
          }
          (**(code **)(*local_res10 + 0x10))();
        }
        (**(code **)(*local_res18 + 0x10))();
        COleDispatchDriver::ReleaseDispatch(local_48);
      }
      (**(code **)(*local_res20 + 0x10))();
    }
  }
  return;
}

/* ---- FUNC 00023250 HappFireEngineCommandCompleted (401 bytes) ---- */

void HappFireEngineCommandCompleted(void)

{
  int iVar1;
  undefined1 local_res8 [8];
  longlong *local_res10;
  longlong *local_res18;
  longlong *local_res20;
  IDispatch *local_68 [4];
  COleDispatchDriver local_48 [16];
  AFX_EXCEPTION_LINK local_38 [16];
  longlong *local_28 [3];
  
                    /* 0x23250  67  HappFireEngineCommandCompleted */
  if (DAT_1800797f0 != (undefined8 *)0x0) {
    local_res20 = (longlong *)0x0;
    local_res18 = (longlong *)0x0;
    iVar1 = (**(code **)*DAT_1800797f0)(DAT_1800797f0,&DAT_180066e28,&local_res20);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_res20 + 0x20))(local_res20,&DAT_180063510,&local_res18);
      if (-1 < iVar1) {
        COleDispatchDriver::COleDispatchDriver(local_48);
        iVar1 = (**(code **)(*local_res18 + 0x38))(local_res18,&local_res10);
        if (-1 < iVar1) {
          (**(code **)(*local_res10 + 0x28))();
          while( true ) {
            iVar1 = (**(code **)(*local_res10 + 0x18))(local_res10,1,local_28,local_res8);
            if (iVar1 != 0) break;
            if (local_28[0] != (longlong *)0x0) {
              local_68[0] = (IDispatch *)0x0;
              iVar1 = (**(code **)*local_28[0])(local_28[0],&DAT_180066c78,local_68);
              if (-1 < iVar1) {
                COleDispatchDriver::AttachDispatch(local_48,local_68[0],1);
                AFX_EXCEPTION_LINK::AFX_EXCEPTION_LINK(local_38);
                COleDispatchDriver::InvokeHelper(local_48,0x6a,1,0,(void *)0x0,(uchar *)0x0);
                AfxTryCleanup();
                COleDispatchDriver::ReleaseDispatch(local_48);
              }
              (**(code **)(*local_28[0] + 0x10))();
            }
          }
          (**(code **)(*local_res10 + 0x10))();
        }
        (**(code **)(*local_res18 + 0x10))();
        COleDispatchDriver::ReleaseDispatch(local_48);
      }
      (**(code **)(*local_res20 + 0x10))();
    }
  }
  return;
}

/* ---- FUNC 000233F0 HappFireGuiClosed (401 bytes) ---- */

void HappFireGuiClosed(void)

{
  int iVar1;
  undefined1 local_res8 [8];
  longlong *local_res10;
  longlong *local_res18;
  longlong *local_res20;
  IDispatch *local_68 [4];
  COleDispatchDriver local_48 [16];
  AFX_EXCEPTION_LINK local_38 [16];
  longlong *local_28 [3];
  
                    /* 0x233f0  69  HappFireGuiClosed */
  if (DAT_1800797f0 != (undefined8 *)0x0) {
    local_res20 = (longlong *)0x0;
    local_res18 = (longlong *)0x0;
    iVar1 = (**(code **)*DAT_1800797f0)(DAT_1800797f0,&DAT_180066e28,&local_res20);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_res20 + 0x20))(local_res20,&DAT_180063510,&local_res18);
      if (-1 < iVar1) {
        COleDispatchDriver::COleDispatchDriver(local_48);
        iVar1 = (**(code **)(*local_res18 + 0x38))(local_res18,&local_res10);
        if (-1 < iVar1) {
          (**(code **)(*local_res10 + 0x28))();
          while( true ) {
            iVar1 = (**(code **)(*local_res10 + 0x18))(local_res10,1,local_28,local_res8);
            if (iVar1 != 0) break;
            if (local_28[0] != (longlong *)0x0) {
              local_68[0] = (IDispatch *)0x0;
              iVar1 = (**(code **)*local_28[0])(local_28[0],&DAT_180066c78,local_68);
              if (-1 < iVar1) {
                COleDispatchDriver::AttachDispatch(local_48,local_68[0],1);
                AFX_EXCEPTION_LINK::AFX_EXCEPTION_LINK(local_38);
                COleDispatchDriver::InvokeHelper(local_48,0x6f,1,0,(void *)0x0,(uchar *)0x0);
                AfxTryCleanup();
                COleDispatchDriver::ReleaseDispatch(local_48);
              }
              (**(code **)(*local_28[0] + 0x10))();
            }
          }
          (**(code **)(*local_res10 + 0x10))();
        }
        (**(code **)(*local_res18 + 0x10))();
        COleDispatchDriver::ReleaseDispatch(local_48);
      }
      (**(code **)(*local_res20 + 0x10))();
    }
  }
  return;
}

/* ---- FUNC 00023590 HappFireGuiClosing (401 bytes) ---- */

void HappFireGuiClosing(void)

{
  int iVar1;
  undefined1 local_res8 [8];
  longlong *local_res10;
  longlong *local_res18;
  longlong *local_res20;
  IDispatch *local_68 [4];
  COleDispatchDriver local_48 [16];
  AFX_EXCEPTION_LINK local_38 [16];
  longlong *local_28 [3];
  
                    /* 0x23590  66  HappFireGuiClosing */
  if (DAT_1800797f0 != (undefined8 *)0x0) {
    local_res20 = (longlong *)0x0;
    local_res18 = (longlong *)0x0;
    iVar1 = (**(code **)*DAT_1800797f0)(DAT_1800797f0,&DAT_180066e28,&local_res20);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_res20 + 0x20))(local_res20,&DAT_180063510,&local_res18);
      if (-1 < iVar1) {
        COleDispatchDriver::COleDispatchDriver(local_48);
        iVar1 = (**(code **)(*local_res18 + 0x38))(local_res18,&local_res10);
        if (-1 < iVar1) {
          (**(code **)(*local_res10 + 0x28))();
          while( true ) {
            iVar1 = (**(code **)(*local_res10 + 0x18))(local_res10,1,local_28,local_res8);
            if (iVar1 != 0) break;
            if (local_28[0] != (longlong *)0x0) {
              local_68[0] = (IDispatch *)0x0;
              iVar1 = (**(code **)*local_28[0])(local_28[0],&DAT_180066c78,local_68);
              if (-1 < iVar1) {
                COleDispatchDriver::AttachDispatch(local_48,local_68[0],1);
                AFX_EXCEPTION_LINK::AFX_EXCEPTION_LINK(local_38);
                COleDispatchDriver::InvokeHelper(local_48,0x66,1,0,(void *)0x0,(uchar *)0x0);
                AfxTryCleanup();
                COleDispatchDriver::ReleaseDispatch(local_48);
              }
              (**(code **)(*local_28[0] + 0x10))();
            }
          }
          (**(code **)(*local_res10 + 0x10))();
        }
        (**(code **)(*local_res18 + 0x10))();
        COleDispatchDriver::ReleaseDispatch(local_48);
      }
      (**(code **)(*local_res20 + 0x10))();
    }
  }
  return;
}

/* ---- FUNC 00023730 HappFireInClosing (446 bytes) ---- */

void HappFireInClosing(undefined4 param_1,undefined8 param_2)

{
  int iVar1;
  undefined2 local_res18;
  undefined1 local_res1a;
  undefined1 local_res20 [8];
  longlong *local_88;
  longlong *local_80;
  longlong *local_78;
  IDispatch *local_70;
  COleDispatchDriver local_68 [16];
  AFX_EXCEPTION_LINK local_58 [16];
  longlong *local_48 [7];
  
                    /* 0x23730  65  HappFireInClosing */
  if (DAT_1800797f0 != (undefined8 *)0x0) {
    local_78 = (longlong *)0x0;
    local_80 = (longlong *)0x0;
    local_res18 = DAT_180064b64;
    local_res1a = DAT_180064b66;
    iVar1 = (**(code **)*DAT_1800797f0)(DAT_1800797f0,&DAT_180066e28,&local_78);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_78 + 0x20))(local_78,&DAT_180063510,&local_80);
      if (-1 < iVar1) {
        COleDispatchDriver::COleDispatchDriver(local_68);
        iVar1 = (**(code **)(*local_80 + 0x38))(local_80,&local_88);
        if (-1 < iVar1) {
          (**(code **)(*local_88 + 0x28))();
          while( true ) {
            iVar1 = (**(code **)(*local_88 + 0x18))(local_88,1,local_48,local_res20);
            if (iVar1 != 0) break;
            if (local_48[0] != (longlong *)0x0) {
              local_70 = (IDispatch *)0x0;
              iVar1 = (**(code **)*local_48[0])(local_48[0],&DAT_180066c78,&local_70);
              if (-1 < iVar1) {
                COleDispatchDriver::AttachDispatch(local_68,local_70,1);
                AFX_EXCEPTION_LINK::AFX_EXCEPTION_LINK(local_58);
                COleDispatchDriver::InvokeHelper
                          (local_68,0x67,1,0,(void *)0x0,(uchar *)&local_res18,param_1,param_2);
                AfxTryCleanup();
                COleDispatchDriver::ReleaseDispatch(local_68);
              }
              (**(code **)(*local_48[0] + 0x10))();
            }
          }
          (**(code **)(*local_88 + 0x10))();
        }
        (**(code **)(*local_80 + 0x10))();
        COleDispatchDriver::ReleaseDispatch(local_68);
      }
      (**(code **)(*local_78 + 0x10))();
    }
  }
  return;
}

/* ---- FUNC 000238F0 HappFireUpdateMessage (612 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void HappFireUpdateMessage(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  int iVar1;
  undefined1 auStackY_e8 [32];
  longlong *local_90;
  longlong *local_88;
  longlong *local_80;
  longlong *local_78;
  IDispatch *local_70;
  COleDispatchDriver local_68 [16];
  undefined1 local_58 [8];
  undefined8 local_50;
  AFX_EXCEPTION_LINK local_48 [16];
  longlong *local_38 [4];
  undefined4 local_18;
  undefined1 local_14;
  ulonglong local_10;
  
                    /* 0x238f0  64  HappFireUpdateMessage */
  local_10 = DAT_180077818 ^ (ulonglong)auStackY_e8;
  if (DAT_1800797f0 != (undefined8 *)0x0) {
    local_50 = param_2;
    HAOnUpdateMessage(param_1,param_2,DAT_1800797f0[4]);
    local_78 = (longlong *)0x0;
    if (param_3 != (undefined8 *)0x0) {
      (**(code **)*param_3)(param_3,&DAT_180066c78,&local_78);
    }
    local_80 = (longlong *)0x0;
    local_88 = (longlong *)0x0;
    local_18 = DAT_180064b68;
    local_14 = DAT_180064b6c;
    iVar1 = (**(code **)*DAT_1800797f0)(DAT_1800797f0,&DAT_180066e28,&local_80);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_80 + 0x20))(local_80,&DAT_180063510,&local_88);
      if (-1 < iVar1) {
        COleDispatchDriver::COleDispatchDriver(local_68);
        iVar1 = (**(code **)(*local_88 + 0x38))(local_88,&local_90);
        if (-1 < iVar1) {
          (**(code **)(*local_90 + 0x28))();
          while( true ) {
            iVar1 = (**(code **)(*local_90 + 0x18))(local_90,1,local_38,local_58);
            if (iVar1 != 0) break;
            if (local_38[0] != (longlong *)0x0) {
              local_70 = (IDispatch *)0x0;
              iVar1 = (**(code **)*local_38[0])(local_38[0],&DAT_180066c78,&local_70);
              if (-1 < iVar1) {
                COleDispatchDriver::AttachDispatch(local_68,local_70,1);
                AFX_EXCEPTION_LINK::AFX_EXCEPTION_LINK(local_48);
                COleDispatchDriver::InvokeHelper(local_68,0x69,1,0,(void *)0x0,(uchar *)&local_18);
                AfxTryCleanup();
                COleDispatchDriver::ReleaseDispatch(local_68);
              }
              (**(code **)(*local_38[0] + 0x10))();
            }
          }
          (**(code **)(*local_90 + 0x10))();
        }
        (**(code **)(*local_88 + 0x10))();
        COleDispatchDriver::ReleaseDispatch(local_68);
      }
      (**(code **)(*local_80 + 0x10))();
    }
    if (local_78 != (longlong *)0x0) {
      (**(code **)(*local_78 + 0x10))();
    }
  }
  return;
}

/* ---- FUNC 00023B60 HappGetClassObject (5 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

HRESULT __stdcall HappGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  undefined8 *puVar9;
  longlong *plVar10;
  
                    /* 0x23b60  50  HappGetClassObject */
  *ppv = (LPVOID)0x0;
  lVar1._0_4_ = riid->Data1;
  lVar1._4_2_ = riid->Data2;
  lVar1._6_2_ = riid->Data3;
  if (((lVar1 != DAT_180066c68) || (*(longlong *)riid->Data4 != DAT_180066c70)) &&
     ((lVar2._0_4_ = riid->Data1, lVar2._4_2_ = riid->Data2, lVar2._6_2_ = riid->Data3,
      lVar2 != DAT_180066c58 || (*(longlong *)riid->Data4 != DAT_180066c60)))) {
    return -0x7fffbffe;
  }
  lVar3._0_4_ = rclsid->Data1;
  lVar3._4_2_ = rclsid->Data2;
  lVar3._6_2_ = rclsid->Data3;
  if (((lVar3 == DAT_180063560) && (*(longlong *)rclsid->Data4 == DAT_180063568)) ||
     ((lVar4._0_4_ = rclsid->Data1, lVar4._4_2_ = rclsid->Data2, lVar4._6_2_ = rclsid->Data3,
      lVar4 == _DAT_1800635b0 && (*(longlong *)rclsid->Data4 == _UNK_1800635b8)))) {
    puVar9 = operator_new(0x10);
    if (puVar9 == (undefined8 *)0x0) {
      return -0x7ff8fff2;
    }
    plVar10 = FUN_180050110(puVar9);
  }
  else {
    lVar5._0_4_ = rclsid->Data1;
    lVar5._4_2_ = rclsid->Data2;
    lVar5._6_2_ = rclsid->Data3;
    if (((lVar5 == DAT_180063580) && (*(longlong *)rclsid->Data4 == DAT_180063588)) ||
       ((lVar6._0_4_ = rclsid->Data1, lVar6._4_2_ = rclsid->Data2, lVar6._6_2_ = rclsid->Data3,
        lVar6 == _DAT_1800635a0 && (*(longlong *)rclsid->Data4 == _UNK_1800635a8)))) {
      puVar9 = operator_new(0x10);
      if (puVar9 == (undefined8 *)0x0) {
        return -0x7ff8fff2;
      }
      plVar10 = FUN_180005a60(puVar9);
    }
    else {
      lVar7._0_4_ = rclsid->Data1;
      lVar7._4_2_ = rclsid->Data2;
      lVar7._6_2_ = rclsid->Data3;
      if (((lVar7 != DAT_180063530) || (*(longlong *)rclsid->Data4 != DAT_180063538)) &&
         ((lVar8._0_4_ = rclsid->Data1, lVar8._4_2_ = rclsid->Data2, lVar8._6_2_ = rclsid->Data3,
          lVar8 != _DAT_180063590 || (*(longlong *)rclsid->Data4 != _UNK_180063598)))) {
        return -0x7ffbfeef;
      }
      puVar9 = operator_new(0x10);
      if (puVar9 == (undefined8 *)0x0) {
        return -0x7ff8fff2;
      }
      plVar10 = FUN_180021330(puVar9,1);
    }
  }
  if (plVar10 == (longlong *)0x0) {
    return -0x7ff8fff2;
  }
  (**(code **)(*plVar10 + 8))(plVar10);
  *ppv = plVar10;
  return 0;
}

/* ---- FUNC 00023B70 HappGetHapp (41 bytes) ---- */

longlong * HappGetHapp(void)

{
                    /* 0x23b70  21  HappGetHapp */
  if (DAT_1800797f0 == (longlong *)0x0) {
    return (longlong *)0x0;
  }
  (**(code **)(*DAT_1800797f0 + 8))();
  return DAT_1800797f0;
}

/* ---- FUNC 00023BA0 HappGetTree (60 bytes) ---- */

undefined8 HappGetTree(void)

{
  int iVar1;
  undefined8 local_res8 [4];
  
                    /* 0x23ba0  22  HappGetTree */
  if (DAT_1800797f0 != (longlong *)0x0) {
    local_res8[0] = 0;
    iVar1 = (**(code **)(*DAT_1800797f0 + 0x90))(DAT_1800797f0,local_res8);
    if (-1 < iVar1) {
      return local_res8[0];
    }
  }
  return 0;
}

/* ---- FUNC 00023BE0 HappInitted (11 bytes) ---- */

undefined4 HappInitted(void)

{
                    /* 0x23be0  10  HappInitted */
  return *(undefined4 *)(DAT_1800797f0 + 0x18);
}

/* ---- FUNC 00023BF0 HappIsDirty (12 bytes) ---- */

void HappIsDirty(void)

{
                    /* 0x23bf0  32  HappIsDirty */
  FUN_180018640(DAT_1800797f0);
  return;
}

/* ---- FUNC 00023C00 HappLinkContainerDataChange (5 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void HappLinkContainerDataChange(void *param_1)

{
  ulonglong uVar1;
  UINT UVar2;
  int iVar3;
  ulonglong uVar4;
  undefined1 auStack_468 [32];
  undefined2 auStack_448 [4];
  undefined8 uStack_440;
  undefined4 uStack_438;
  undefined4 uStack_434;
  undefined4 uStack_430;
  STGMEDIUM SStack_428;
  undefined1 auStack_408 [1008];
  ulonglong uStack_18;
  
                    /* 0x23c00  48  HappLinkContainerDataChange */
  uStack_18 = DAT_180077818 ^ (ulonglong)auStack_468;
  if (*(int *)((longlong)param_1 + 8) != 4) {
    FUN_180002a20(auStack_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\HappSel.cpp",0x1128);
    LogMessage(auStack_408,2,1);
  }
  if (*(longlong *)((longlong)param_1 + 0x68) == 0) {
    FUN_180002a20(auStack_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\HappSel.cpp",0x1129);
    LogMessage(auStack_408,2,1);
  }
  if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4)
       < DAT_1800795c8) && (FUN_18005c974(&DAT_1800795c8), DAT_1800795c8 == -1)) {
    CPtrArray::CPtrArray((CPtrArray *)&DAT_1800795a0);
    atexit((_func_5014 *)&LAB_180060400);
    _Init_thread_footer(&DAT_1800795c8);
  }
  if (DAT_18007959c == 0) {
    DAT_18007959c = 1;
    UVar2 = RegisterClipboardFormatA("Grid Text");
    uStack_438 = 1;
    uStack_440 = 0;
    uStack_430 = 1;
    uStack_434 = 0xffffffff;
    auStack_448[0] = (short)UVar2;
    if (*(int *)((longlong)param_1 + 0x80) == 0) {
      auStack_448[0] = 1;
    }
    iVar3 = (**(code **)(**(longlong **)((longlong)param_1 + 0x68) + 0x18))
                      (*(longlong **)((longlong)param_1 + 0x68),auStack_448,&SStack_428);
    if (-1 < iVar3) {
      FUN_18003e370(-1);
      if (SStack_428.u.hBitmap != (HBITMAP)0x0) {
        DAT_180079898 = 1;
        FUN_18002c9d0((longlong)param_1,SStack_428.u.hGlobal,1);
        DAT_180079898 = 0;
      }
      ReleaseStgMedium(&SStack_428);
      FUN_18003e370(0);
    }
    uVar1 = DAT_1800795b0;
    uVar4 = 0;
    if (DAT_1800795b0 != 0) {
      do {
        if (((longlong)uVar4 < 0) || ((longlong)DAT_1800795b0 <= (longlong)uVar4)) {
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        (**(code **)(*DAT_180079800 + 0xf0))();
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar1);
    }
    CPtrArray::SetSize((CPtrArray *)&DAT_1800795a0,0,-1);
    DAT_18007959c = 0;
  }
  else {
    CPtrArray::SetAtGrow((CPtrArray *)&DAT_1800795a0,DAT_1800795b0,param_1);
  }
  return;
}

/* ---- FUNC 00023C10 HappLinkSourceDataChange (5 bytes) ---- */

void HappLinkSourceDataChange(longlong param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  wchar_t *bstrString;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong *plStackX_8;
  undefined8 auStack_28 [2];
  
                    /* 0x23c10  43  HappLinkSourceDataChange */
  FUN_1800255a0(auStack_28);
  uVar4 = 0;
  uVar1 = *(ulonglong *)(param_1 + 0x60);
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar4 < 0) || (*(longlong *)(param_1 + 0x60) <= (longlong)uVar4)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x58) + uVar4 * 8);
      if ((*(int *)(lVar2 + 0x30) == 0) && (*(int *)(lVar2 + 8) != 0)) {
        FUN_18002f560(lVar2,(longlong *)0x0,4,(char *)0x0);
      }
      if (*(int *)(lVar2 + 0x30) == 4) {
        bstrString = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                     AllocSysString((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
                                    )(lVar2 + 0x10));
        uVar3 = FUN_180026ff0(DAT_180079590,bstrString,&plStackX_8);
        if (-1 < (int)uVar3) {
          FUN_18002f560(lVar2,plStackX_8,0,(char *)0x0);
        }
        SysFreeString(bstrString);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  (*(code *)**(undefined8 **)(param_1 + 0x18))((undefined8 *)(param_1 + 0x18),0,1);
  (**(code **)(*DAT_180079800 + 0xe8))(DAT_180079800,0,param_1);
  FUN_180025a20(auStack_28);
  return;
}

/* ---- FUNC 00023C20 FUN_180023c20 (547 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

LPCOLESTR FUN_180023c20(LPCSTR param_1,undefined8 *param_2)

{
  LPCOLESTR pOVar1;
  _func_5302 *p_Var2;
  _func_5320 *p_Var3;
  _func_5298 *p_Var4;
  _func_5156 *p_Var5;
  code *pcVar6;
  _func_5158 *p_Var7;
  LPRUNNINGOBJECTTABLE pIVar8;
  LPMONIKER pIVar9;
  IUnknown *pIVar10;
  longlong *plVar11;
  HRESULT HVar12;
  longlong lVar13;
  IRunningObjectTableVtbl *pIVar15;
  ulonglong uVar16;
  int iVar17;
  LPCOLESTR pOVar18;
  undefined1 *puVar19;
  LPCOLESTR lpszPathName;
  undefined8 uStack_90;
  undefined1 auStack_88 [32];
  undefined8 uStack_68;
  int aiStack_60 [2];
  LPRUNNINGOBJECTTABLE local_58;
  LPMONIKER local_50;
  IUnknown *local_48;
  longlong *local_40;
  longlong *local_38;
  longlong local_30;
  longlong lStack_28;
  ulonglong local_20;
  longlong lVar14;
  
  puVar19 = auStack_88;
  local_20 = DAT_180077818 ^ (ulonglong)&local_58;
  pOVar18 = (LPCOLESTR)0x0;
  local_38 = (longlong *)0x0;
  local_48 = (IUnknown *)0x0;
  local_50 = (IMoniker *)0x0;
  local_58 = (IRunningObjectTable *)0x0;
  uStack_90 = 0x180023c68;
  HVar12 = GetRunningObjectTable(0,&local_58);
  if (-1 < HVar12) {
    puVar19 = auStack_88;
    lpszPathName = pOVar18;
    if (param_1 != (LPCSTR)0x0) {
      lVar13 = -1;
      do {
        lVar14 = lVar13;
        lVar13 = lVar14 + 1;
      } while (param_1[lVar13] != '\0');
      iVar17 = (int)lVar14 + 2;
      puVar19 = auStack_88;
      if (iVar17 < 0x40000000) {
        lVar13 = (longlong)(int)lVar13 * 2;
        uVar16 = lVar13 + 0x11;
        if (uVar16 <= lVar13 + 2U) {
          uVar16 = 0xffffffffffffff0;
        }
        uStack_90 = 0x180023cbc;
        lVar13 = -(uVar16 & 0xfffffffffffffff0);
        pOVar1 = (LPCOLESTR)((longlong)&local_58 + lVar13);
        puVar19 = auStack_88 + lVar13;
        if (pOVar1 != (LPCOLESTR)0x0) {
          *pOVar1 = L'\0';
          *(int *)((longlong)aiStack_60 + lVar13) = iVar17;
          *(LPCOLESTR *)((longlong)&uStack_68 + lVar13) = pOVar1;
          *(undefined8 *)(auStack_88 + lVar13 + -8) = 0x180023ce8;
          iVar17 = MultiByteToWideChar(0,0,param_1,-1,*(LPWSTR *)((longlong)&uStack_68 + lVar13),
                                       *(int *)((longlong)aiStack_60 + lVar13));
          puVar19 = auStack_88 + lVar13;
          lpszPathName = pOVar1;
          if (iVar17 == 0) {
            puVar19 = auStack_88 + lVar13;
            lpszPathName = pOVar18;
          }
        }
      }
    }
    *(undefined8 *)(puVar19 + -8) = 0x180023d00;
    HVar12 = CreateFileMoniker(lpszPathName,&local_50);
    pIVar9 = local_50;
    pIVar8 = local_58;
    pIVar15 = local_58->lpVtbl;
    if (-1 < HVar12) {
      p_Var2 = pIVar15->GetObjectA;
      *(undefined8 *)(puVar19 + -8) = 0x180023d16;
      HVar12 = (*p_Var2)(pIVar8,pIVar9,&local_48);
      pIVar10 = local_48;
      pIVar9 = local_50;
      if (-1 < HVar12) {
        local_30 = DAT_180066d68;
        lStack_28 = DAT_180066d70;
        local_40 = (longlong *)0x0;
        if (local_48 != (IUnknown *)0x0) {
          p_Var5 = local_48->lpVtbl->QueryInterface;
          *(undefined8 *)(puVar19 + -8) = 0x180023d63;
          HVar12 = (*p_Var5)(pIVar10,(IID *)&DAT_180064ac8,&local_40);
          if (HVar12 < 0) {
            local_40 = (longlong *)0x0;
          }
        }
        plVar11 = local_40;
        if (local_40 != (longlong *)0x0) {
          pcVar6 = *(code **)(*local_40 + 0x18);
          *(undefined8 *)(puVar19 + -8) = 0x180023d83;
          (*pcVar6)(plVar11,&local_30);
        }
        pIVar9 = local_50;
        if ((local_30 == DAT_180063520) && (lStack_28 == DAT_180063528)) {
          p_Var3 = local_50->lpVtbl->Release;
          *(undefined8 *)(puVar19 + -8) = 0x180023da7;
          (*p_Var3)(pIVar9);
          pIVar8 = local_58;
          p_Var4 = local_58->lpVtbl->Release;
          *(undefined8 *)(puVar19 + -8) = 0x180023db1;
          (*p_Var4)(pIVar8);
          pIVar10 = local_48;
          p_Var5 = local_48->lpVtbl->QueryInterface;
          *(undefined8 *)(puVar19 + -8) = 0x180023dc5;
          HVar12 = (*p_Var5)(pIVar10,(IID *)&DAT_180063460,&local_38);
          if (-1 < HVar12) {
            if (param_2 != (undefined8 *)0x0) {
              *param_2 = local_38;
              pcVar6 = *(code **)(*local_38 + 8);
              *(undefined8 *)(puVar19 + -8) = 0x180023ddb;
              (*pcVar6)();
            }
            pOVar18 = (LPCOLESTR)0x1;
            pcVar6 = *(code **)(*local_38 + 0x10);
            *(undefined8 *)(puVar19 + -8) = 0x180023dea;
            (*pcVar6)();
          }
          pIVar10 = local_48;
          p_Var7 = local_48->lpVtbl->Release;
          *(undefined8 *)(puVar19 + -8) = 0x180023df4;
          (*p_Var7)(pIVar10);
        }
        else {
          p_Var3 = local_50->lpVtbl->Release;
          *(undefined8 *)(puVar19 + -8) = 0x180023e00;
          (*p_Var3)(pIVar9);
          pIVar8 = local_58;
          p_Var4 = local_58->lpVtbl->Release;
          *(undefined8 *)(puVar19 + -8) = 0x180023e0a;
          (*p_Var4)(pIVar8);
          pIVar10 = local_48;
          p_Var7 = local_48->lpVtbl->Release;
          *(undefined8 *)(puVar19 + -8) = 0x180023e14;
          (*p_Var7)(pIVar10);
        }
        if (local_40 != (longlong *)0x0) {
          pcVar6 = *(code **)(*local_40 + 0x10);
          *(undefined8 *)(puVar19 + -8) = 0x180023e24;
          (*pcVar6)();
        }
        goto LAB_180023e26;
      }
      p_Var3 = local_50->lpVtbl->Release;
      *(undefined8 *)(puVar19 + -8) = 0x180023d24;
      (*p_Var3)(pIVar9);
      pIVar15 = local_58->lpVtbl;
    }
    pIVar8 = local_58;
    p_Var4 = pIVar15->Release;
    *(undefined8 *)(puVar19 + -8) = 0x180023d2e;
    (*p_Var4)(pIVar8);
  }
  pOVar18 = (LPCOLESTR)0x0;
LAB_180023e26:
  *(undefined8 *)(puVar19 + -8) = 0x180023e32;
  return pOVar18;
}

/* ---- FUNC 00023E50 HappName (21 bytes) ---- */

undefined8 HappName(void)

{
                    /* 0x23e50  12  HappName */
  if (DAT_1800797f0 != 0) {
    return *(undefined8 *)(DAT_1800797f0 + 0x108);
  }
  return 0;
}

/* ---- FUNC 00023E70 HappPaste (156 bytes) ---- */

void HappPaste(void)

{
  int iVar1;
  wchar_t *bstrString;
  undefined1 local_res8 [8];
  int local_res10 [2];
  longlong *local_res18;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res20 [8];
  
                    /* 0x23e70  30  HappPaste */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20,"VBSelect");
  bstrString = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::AllocSysString
                         (local_res20);
  iVar1 = (**(code **)(*DAT_1800797f0 + 0xd0))(DAT_1800797f0,bstrString,&local_res18);
  if (iVar1 < 0) {
    SysFreeString(bstrString);
  }
  else {
    SysFreeString(bstrString);
    (**(code **)(*local_res18 + 0x48))(local_res18,local_res10);
    if (local_res10[0] == 1) {
      (**(code **)(*local_res18 + 0xa8))(local_res18,local_res8);
    }
    (**(code **)(*local_res18 + 0x10))();
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20);
  return;
}

/* ---- FUNC 00023F10 HappPasteSpecial (245 bytes) ---- */

void HappPasteSpecial(void)

{
  int iVar1;
  wchar_t *bstrString;
  undefined1 local_res8 [8];
  int local_res10 [2];
  longlong *local_res18;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res20 [8];
  uint local_68;
  uint local_48 [8];
  uint local_28 [8];
  
                    /* 0x23f10  31  HappPasteSpecial */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20,"VBSelect");
  bstrString = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::AllocSysString
                         (local_res20);
  iVar1 = (**(code **)(*DAT_1800797f0 + 0xd0))(DAT_1800797f0,bstrString,&local_res18);
  if (iVar1 < 0) {
    SysFreeString(bstrString);
  }
  else {
    SysFreeString(bstrString);
    (**(code **)(*local_res18 + 0x48))(local_res18,local_res10);
    if (local_res10[0] == 1) {
      local_68 = local_68 & 0xffff0000;
      local_48[0] = local_68;
      local_28[0] = local_68;
      (**(code **)(*local_res18 + 0xb0))(local_res18,local_28,local_48,local_res8);
    }
    (**(code **)(*local_res18 + 0x10))();
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20);
  return;
}

/* ---- FUNC 00024010 HappRun (22 bytes) ---- */

void HappRun(undefined4 param_1)

{
                    /* 0x24010  18  HappRun */
                    /* WARNING: Could not recover jumptable at 0x00018002401f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_1800797f0 + 0x270))(DAT_1800797f0,param_1,0);
  return;
}

/* ---- FUNC 00024030 HappRunCommand (26 bytes) ---- */

void HappRunCommand(undefined4 param_1,undefined8 param_2)

{
                    /* 0x24030  56  HappRunCommand */
                    /* WARNING: Could not recover jumptable at 0x000180024043. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_1800797f0 + 0x270))(DAT_1800797f0,param_1,param_2);
  return;
}

/* ---- FUNC 00024050 HappRunPressureChecker (7 bytes) ---- */

void HappRunPressureChecker(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180024050. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x24050  45  HappRunPressureChecker */
  HARunPressureChecker();
  return;
}

/* ---- FUNC 00024060 HappSetDirty (21 bytes) ---- */

void HappSetDirty(int param_1)

{
                    /* 0x24060  47  HappSetDirty */
  *(uint *)(DAT_1800797f0 + 0x100) = (uint)(param_1 != 0);
  return;
}

/* ---- FUNC 00024080 HappSetHost (17 bytes) ---- */

void HappSetHost(void)

{
                    /* 0x24080  33  HappSetHost */
                    /* WARNING: Could not recover jumptable at 0x00018002408a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_1800797f0 + 0x2e8))();
  return;
}

/* ---- FUNC 000240A0 HappTemporaryOpenCloseLinks (19 bytes) ---- */

void HappTemporaryOpenCloseLinks(int param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
                    /* 0x240a0  42  HappTemporaryOpenCloseLinks */
  lVar2 = DAT_1800797f0;
  if (DAT_1800797f0 == 0) {
    return;
  }
  uVar1 = *(ulonglong *)(DAT_1800797f0 + 0x228);
  uVar3 = 0;
  uVar4 = uVar3;
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar4 < 0) || (*(longlong *)(lVar2 + 0x228) <= (longlong)uVar4))
      goto LAB_18001d379;
      FUN_1800303e0(*(longlong *)(*(longlong *)(lVar2 + 0x220) + uVar4 * 8),param_1);
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  if ((param_1 == 0) && (uVar1 = *(ulonglong *)(lVar2 + 0x200), uVar1 != 0)) {
    do {
      if (((longlong)uVar3 < 0) || (*(longlong *)(lVar2 + 0x200) <= (longlong)uVar3)) {
LAB_18001d379:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      FUN_18002bb30(*(longlong *)(*(longlong *)(lVar2 + 0x1f8) + uVar3 * 8));
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return;
}

/* ---- FUNC 000240C0 HappUpdateMoniker (15 bytes) ---- */

void HappUpdateMoniker(char *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
                    /* 0x240c0  54  HappUpdateMoniker */
  FUN_18001d5e0(DAT_1800797f0,param_1,param_3,param_4);
  return;
}

/* ---- FUNC 000240D0 HappVarsum (15 bytes) ---- */

void HappVarsum(undefined8 param_1)

{
                    /* 0x240d0  24  HappVarsum */
  FUN_18001dac0(DAT_1800797f0,param_1);
  return;
}

/* ---- FUNC 000240E0 HappWriteExport (39 bytes) ---- */

uint HappWriteExport(undefined4 param_1,undefined8 param_2)

{
  uint uVar1;
  
                    /* 0x240e0  23  HappWriteExport */
  uVar1 = (**(code **)(*DAT_1800797f0 + 0x2d8))(DAT_1800797f0,param_1,param_2);
  return ~uVar1 >> 0x1f;
}

/* ---- FUNC 00024110 HappWriteExportHier (42 bytes) ---- */

uint HappWriteExportHier(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  
                    /* 0x24110  61  HappWriteExportHier */
  uVar1 = (**(code **)(*DAT_1800797f0 + 0x2e0))(DAT_1800797f0,param_1,param_2,param_3);
  return ~uVar1 >> 0x1f;
}

/* ---- FUNC 00024140 InitializeHapp (37 bytes) ---- */

bool InitializeHapp(undefined8 param_1)

{
  int iVar1;
  
                    /* 0x24140  34  InitializeHapp */
  iVar1 = (**(code **)(*DAT_1800797f0 + 0x288))(DAT_1800797f0,param_1);
  return -1 < iVar1;
}

/* ---- FUNC 00024170 IsHappLocked (27 bytes) ---- */

bool IsHappLocked(void)

{
                    /* 0x24170  37  IsHappLocked */
  if (DAT_1800797f0 != 0) {
    return *(int *)(DAT_1800797f0 + 0x14) != 0;
  }
  return true;
}

/* ---- FUNC 00024190 LockGlobalObject (25 bytes) ---- */

void LockGlobalObject(int param_1,int param_2)

{
                    /* 0x24190  16  LockGlobalObject */
  if (DAT_1800797f0 != (IUnknown *)0x0) {
    FUN_180018e30(DAT_1800797f0,param_1,param_2);
    return;
  }
  return;
}

/* ---- FUNC 000241B0 NewAppNewHapp (171 bytes) ---- */

undefined8 NewAppNewHapp(void)

{
  int iVar1;
  longlong *local_res8 [4];
  _union_2707 local_68;
  undefined4 local_48;
  ULONG UStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  VARIANTARG local_28;
  
                    /* 0x241b0  8  NewAppNewHapp */
  VariantInit((VARIANTARG *)&local_68.n2);
  VariantInit(&local_28);
  local_68._8_4_ = 0x80020004;
  local_68.n2.vt = 10;
  local_38 = local_68._16_8_;
  local_48 = local_68._0_4_;
  UStack_44 = local_68.decVal.Hi32;
  uStack_40 = 0x80020004;
  uStack_3c = local_68._12_4_;
  iVar1 = (**(code **)(*DAT_1800797f0 + 0x100))(DAT_1800797f0,&local_48,local_res8);
  if ((-1 < iVar1) && (local_res8[0] != (longlong *)0x0)) {
    VariantClear((VARIANTARG *)&local_68.n2);
    iVar1 = (**(code **)(*local_res8[0] + 0x60))(local_res8[0],1);
    if (-1 < iVar1) {
      (**(code **)(*local_res8[0] + 0x10))();
    }
  }
  return 0;
}

/* ---- FUNC 00024260 NewAppOpenHapp (207 bytes) ---- */

undefined4 NewAppOpenHapp(LPCSTR param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  LPCSTR pCVar4;
  undefined4 uVar5;
  longlong *local_res10 [3];
  _union_2707 local_48;
  undefined4 local_28;
  ULONG UStack_24;
  undefined4 uStack_20;
  ULONG UStack_1c;
  undefined8 local_18;
  
                    /* 0x24260  3  NewAppOpenHapp */
  local_48._0_8_ = 0;
  local_48.decVal.u2 = (_union_1719)0x0;
  local_48._16_8_ = 0;
  VariantInit((VARIANTARG *)&local_48.n2);
  if ((int)DAT_1800797f0[3] != 0) {
    pCVar4 = param_1;
    do {
      cVar1 = *pCVar4;
      cVar2 = pCVar4[DAT_1800797f0[0x21] - (longlong)param_1];
      if (cVar1 != cVar2) break;
      pCVar4 = pCVar4 + 1;
    } while (cVar2 != '\0');
    if (cVar1 == cVar2) {
      uVar5 = 1;
      goto LAB_18002431c;
    }
    local_48.n2.vt = 8;
    local_48.decVal.u2 = (_union_1719)FUN_1800019d0(param_1);
    local_28 = local_48._0_4_;
    UStack_24 = local_48.decVal.Hi32;
    uStack_20 = local_48._8_4_;
    UStack_1c = local_48._12_4_;
    local_18 = local_48._16_8_;
    iVar3 = (**(code **)(*DAT_1800797f0 + 0x100))(DAT_1800797f0,&local_28,local_res10);
    if ((-1 < iVar3) && (local_res10[0] != (longlong *)0x0)) {
      (**(code **)(*local_res10[0] + 0x10))();
    }
  }
  uVar5 = 0;
LAB_18002431c:
  VariantClear((VARIANTARG *)&local_48.n2);
  return uVar5;
}

/* ---- FUNC 00024330 NewHapp (152 bytes) ---- */

undefined8 NewHapp(IID *param_1,undefined8 *param_2,void **param_3,undefined8 param_4)

{
  HRESULT HVar1;
  _union_2707 local_38;
  _union_2707 local_20;
  
                    /* 0x24330  9  NewHapp */
  VariantInit((VARIANTARG *)&local_38.n2);
  VariantInit((VARIANTARG *)&local_20.n2);
  local_38.n2.vt = 10;
  local_38._8_4_ = 0x80020004;
  local_20.n2.vt = 10;
  local_20._8_4_ = 0x80020004;
  HVar1 = (*DAT_1800797f0->lpVtbl[0x1b].QueryInterface)(DAT_1800797f0,param_1,param_3);
  if (HVar1 < 0) {
    return 0;
  }
  FUN_18001d5e0(DAT_1800797f0,(char *)0x0,param_3,param_4);
  *param_2 = DAT_1800797f0[0x21].lpVtbl;
  return 1;
}

/* ---- FUNC 000243D0 OpenHapp (164 bytes) ---- */

ULONG OpenHapp(longlong *param_1,char *param_2,undefined8 param_3,undefined8 param_4)

{
  ULONG UVar1;
  int iVar2;
  char *pcVar3;
  IID *local_res18 [2];
  VARIANTARG local_28;
  
                    /* 0x243d0  5  OpenHapp */
  VariantInit(&local_28);
  pcVar3 = param_2;
  UVar1 = (*DAT_1800797f0->lpVtbl[0x1b].AddRef)(DAT_1800797f0);
  if (UVar1 == 0) {
    FUN_18001d5e0(DAT_1800797f0,param_2,pcVar3,param_4);
    local_res18[0] = (IID *)0x0;
    iVar2 = (**(code **)(*param_1 + 0x20))(param_1,L"OLELINKS",0,0x12,0,local_res18);
    if (-1 < iVar2) {
      (*DAT_1800797f0->lpVtbl[0xc].QueryInterface)(DAT_1800797f0,local_res18[0],(void **)0x0);
      (**(code **)(*(longlong *)local_res18[0] + 0x10))();
    }
    UVar1 = 0;
  }
  return UVar1;
}

/* ---- FUNC 00024480 OpenHappArchive (252 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool OpenHappArchive(char *param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  undefined2 *puVar1;
  _func_5158 *p_Var2;
  ULONG UVar3;
  longlong lVar4;
  ulonglong uVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined8 uStack_50;
  undefined1 auStack_48 [32];
  undefined8 uStack_28;
  int aiStack_20 [2];
  undefined2 *local_18;
  ulonglong local_10;
  longlong lVar5;
  
                    /* 0x24480  6  OpenHappArchive */
  local_10 = DAT_180077818 ^ (ulonglong)&local_18;
  puVar8 = auStack_48;
  if (param_1 != (char *)0x0) {
    lVar4 = -1;
    do {
      lVar5 = lVar4;
      lVar4 = lVar5 + 1;
    } while (param_1[lVar4] != '\0');
    iVar7 = (int)lVar5 + 2;
    puVar8 = auStack_48;
    if (iVar7 < 0x40000000) {
      lVar4 = (longlong)(int)lVar4 * 2;
      uVar6 = lVar4 + 0x11;
      if (uVar6 <= lVar4 + 2U) {
        uVar6 = 0xffffffffffffff0;
      }
      uStack_50 = 0x1800244f1;
      lVar4 = -(uVar6 & 0xfffffffffffffff0);
      puVar8 = auStack_48 + lVar4;
      puVar1 = (undefined2 *)((longlong)&local_18 + lVar4);
      if (puVar1 != (undefined2 *)0x0) {
        *(int *)((longlong)aiStack_20 + lVar4) = iVar7;
        *puVar1 = 0;
        *(undefined2 **)((longlong)&uStack_28 + lVar4) = puVar1;
        param_4 = 0xffffffff;
        *(undefined8 *)(auStack_48 + lVar4 + -8) = 0x18002451d;
        param_3 = param_1;
        iVar7 = MultiByteToWideChar(0,0,param_1,-1,*(LPWSTR *)((longlong)&uStack_28 + lVar4),
                                    *(int *)((longlong)aiStack_20 + lVar4));
        local_18 = puVar1;
        puVar8 = auStack_48 + lVar4;
        if (iVar7 == 0) {
          local_18 = (undefined2 *)0x0;
          puVar8 = auStack_48 + lVar4;
        }
        goto LAB_18002452a;
      }
    }
  }
  local_18 = (undefined2 *)0x0;
LAB_18002452a:
  p_Var2 = DAT_1800797f0->lpVtbl[0x1b].Release;
  *(undefined8 *)(puVar8 + -8) = 0x180024542;
  UVar3 = (*p_Var2)(DAT_1800797f0);
  if (-1 < (int)UVar3) {
    *(undefined8 *)(puVar8 + -8) = 0x180024559;
    FUN_18001d5e0(DAT_1800797f0,param_1,param_3,param_4);
  }
  *(undefined8 *)(puVar8 + -8) = 0x18002456a;
  return -1 < (int)UVar3;
}

/* ---- FUNC 00024580 OpenHappArchiveStg (69 bytes) ---- */

undefined8
OpenHappArchiveStg(undefined8 param_1,char *param_2,undefined8 param_3,undefined8 param_4)

{
  ULONG UVar1;
  char *pcVar2;
  
                    /* 0x24580  68  OpenHappArchiveStg */
  pcVar2 = param_2;
  UVar1 = (*DAT_1800797f0->lpVtbl[0x1c].Release)(DAT_1800797f0);
  if ((int)UVar1 < 0) {
    return 0;
  }
  FUN_18001d5e0(DAT_1800797f0,param_2,pcVar2,param_4);
  return 1;
}

/* ---- FUNC 000245D0 OpenHappInput (220 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool OpenHappInput(LPCSTR param_1)

{
  undefined2 *puVar1;
  code *pcVar2;
  longlong lVar3;
  ulonglong uVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined8 uStack_50;
  undefined1 auStack_48 [32];
  undefined8 uStack_28;
  int aiStack_20 [2];
  undefined2 *local_18;
  ulonglong local_10;
  longlong lVar4;
  
                    /* 0x245d0  46  OpenHappInput */
  local_10 = DAT_180077818 ^ (ulonglong)&local_18;
  puVar7 = auStack_48;
  if (param_1 != (LPCSTR)0x0) {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_1[lVar3] != '\0');
    iVar6 = (int)lVar4 + 2;
    puVar7 = auStack_48;
    if (iVar6 < 0x40000000) {
      lVar3 = (longlong)(int)lVar3 * 2;
      uVar5 = lVar3 + 0x11;
      if (uVar5 <= lVar3 + 2U) {
        uVar5 = 0xffffffffffffff0;
      }
      uStack_50 = 0x18002463d;
      lVar3 = -(uVar5 & 0xfffffffffffffff0);
      puVar7 = auStack_48 + lVar3;
      puVar1 = (undefined2 *)((longlong)&local_18 + lVar3);
      if (puVar1 != (undefined2 *)0x0) {
        *(int *)((longlong)aiStack_20 + lVar3) = iVar6;
        *puVar1 = 0;
        *(undefined2 **)((longlong)&uStack_28 + lVar3) = puVar1;
        *(undefined8 *)(auStack_48 + lVar3 + -8) = 0x180024666;
        iVar6 = MultiByteToWideChar(0,0,param_1,-1,*(LPWSTR *)((longlong)&uStack_28 + lVar3),
                                    *(int *)((longlong)aiStack_20 + lVar3));
        puVar7 = auStack_48 + lVar3;
        local_18 = puVar1;
        if (iVar6 == 0) {
          puVar7 = auStack_48 + lVar3;
          local_18 = (undefined2 *)0x0;
        }
        goto LAB_180024672;
      }
    }
  }
  local_18 = (undefined2 *)0x0;
LAB_180024672:
  pcVar2 = *(code **)(*DAT_1800797f0 + 0x2a0);
  *(undefined8 *)(puVar7 + -8) = 0x18002468b;
  iVar6 = (*pcVar2)(DAT_1800797f0,&local_18);
  *(undefined8 *)(puVar7 + -8) = 0x18002469e;
  return -1 < iVar6;
}

/* ---- FUNC 000246B0 OpenHappPro2Input (64 bytes) ---- */

void OpenHappPro2Input(LPCSTR param_1,LPCSTR param_2)

{
  BSTR local_res18;
  BSTR local_res20;
  
                    /* 0x246b0  62  OpenHappPro2Input */
  local_res20 = FUN_1800019d0(param_1);
  local_res18 = FUN_1800019d0(param_2);
  (**(code **)(*DAT_1800797f0 + 0x2a8))(DAT_1800797f0,&local_res20,&local_res18);
  return;
}

/* ---- FUNC 000246F0 FUN_1800246f0 (20 bytes) ---- */

byte FUN_1800246f0(void)

{
  byte bVar1;
  BOOL BVar2;
  UINT format;
  UINT format_00;
  BOOL BVar3;
  byte bVar4;
  
  BVar2 = OpenClipboard((HWND)0x0);
  if (BVar2 != 0) {
    format = RegisterClipboardFormatA("Link Source");
    format_00 = RegisterClipboardFormatA("Happ Node");
    BVar2 = IsClipboardFormatAvailable(1);
    BVar3 = IsClipboardFormatAvailable(format);
    bVar4 = BVar2 != 0 | 2;
    if (BVar3 == 0) {
      bVar4 = BVar2 != 0;
    }
    BVar2 = IsClipboardFormatAvailable(format_00);
    CloseClipboard();
    bVar1 = bVar4 | 4;
    if (BVar2 == 0) {
      bVar1 = bVar4;
    }
    return bVar1;
  }
  return 0;
}

/* ---- FUNC 00024704 FUN_180024704 (125 bytes) ---- */

ulonglong FUN_180024704(void)

{
  UINT format;
  UINT format_00;
  BOOL BVar1;
  ulonglong uVar2;
  undefined8 unaff_RBP;
  ulonglong uVar3;
  
  format = RegisterClipboardFormatA("Link Source");
  format_00 = RegisterClipboardFormatA("Happ Node");
  BVar1 = IsClipboardFormatAvailable((int)unaff_RBP + 1);
  uVar2 = CONCAT71((int7)((ulonglong)unaff_RBP >> 8),BVar1 != 0);
  BVar1 = IsClipboardFormatAvailable(format);
  uVar3 = (ulonglong)((uint)uVar2 | 2);
  if (BVar1 == 0) {
    uVar3 = uVar2 & 0xffffffff;
  }
  BVar1 = IsClipboardFormatAvailable(format_00);
  CloseClipboard();
  uVar2 = (ulonglong)((uint)uVar3 | 4);
  if (BVar1 == 0) {
    uVar2 = uVar3;
  }
  return uVar2;
}

/* ---- FUNC 00024781 FUN_180024781 (8 bytes) ---- */

undefined4 FUN_180024781(void)

{
  undefined4 unaff_EBP;
  
  return unaff_EBP;
}

/* ---- FUNC 00024790 RegisterClassFactory (253 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 RegisterClassFactory(void)

{
  int iVar1;
  HRESULT HVar2;
  undefined8 *puVar3;
  IUnknown *This;
  undefined1 auStackY_458 [32];
  IID local_420;
  undefined1 local_408 [1008];
  ulonglong local_18;
  
                    /* 0x24790  15  RegisterClassFactory */
  local_18 = DAT_180077818 ^ (ulonglong)auStackY_458;
  puVar3 = operator_new(0x10);
  if (puVar3 == (undefined8 *)0x0) {
    This = (IUnknown *)0x0;
  }
  else {
    This = (IUnknown *)FUN_180021330(puVar3,0);
  }
  if (This != (IUnknown *)0x0) {
    (*This->lpVtbl->AddRef)(This);
    iVar1 = (**(code **)(*DAT_180079800 + 0x138))(DAT_180079800,&local_420);
    if (iVar1 != 0) {
      FUN_180002a20(local_408,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\happmfc.cpp",0x19d);
      LogMessage(local_408,2,1);
    }
    HVar2 = CoRegisterClassObject(&local_420,This,4,0,(LPDWORD)(DAT_1800797f0 + 0x120));
    if (HVar2 == 0) {
      (*This->lpVtbl->Release)(This);
      return 1;
    }
    FUN_180025ad0(This);
  }
  return 0;
}

/* ---- FUNC 00024890 ReleaseHapp (14 bytes) ---- */

void ReleaseHapp(void)

{
                    /* 0x24890  2  ReleaseHapp */
                    /* WARNING: Could not recover jumptable at 0x00018002489a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_1800797f0 + 0x10))();
  return;
}

/* ---- FUNC 000248A0 RestoreHappArchive (37 bytes) ---- */

bool RestoreHappArchive(undefined8 param_1)

{
  int iVar1;
  
                    /* 0x248a0  4  RestoreHappArchive */
  iVar1 = (**(code **)(*DAT_1800797f0 + 0x2c0))(DAT_1800797f0,param_1);
  return -1 < iVar1;
}

/* ---- FUNC 000248D0 RestoreHappHierArchive (43 bytes) ---- */

bool RestoreHappHierArchive(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
                    /* 0x248d0  60  RestoreHappHierArchive */
  iVar1 = (**(code **)(*DAT_1800797f0 + 0x2d0))(DAT_1800797f0,param_1,param_2);
  return -1 < iVar1;
}

/* ---- FUNC 00024900 SaveHapp (154 bytes) ---- */

undefined8 SaveHapp(IID *param_1,uint param_2,char *param_3)

{
  int iVar1;
  HRESULT HVar2;
  void **ppvObject;
  char *pcVar3;
  
                    /* 0x24900  7  SaveHapp */
  iVar1 = _stricmp((char *)DAT_1800797f0[0x21].lpVtbl,param_3);
  if (*(int *)&DAT_1800797f0[3].lpVtbl != 0) {
    ppvObject = (void **)(ulonglong)param_2;
    pcVar3 = param_3;
    HVar2 = (*DAT_1800797f0->lpVtbl[0x1d].QueryInterface)(DAT_1800797f0,param_1,ppvObject);
    if ((-1 < HVar2) && ((param_2 == 0 || (iVar1 != 0)))) {
      FUN_18001d5e0(DAT_1800797f0,param_3,ppvObject,pcVar3);
    }
  }
  return 0;
}

/* ---- FUNC 000249A0 ViewBrowser (153 bytes) ---- */

uint ViewBrowser(int param_1)

{
  longlong *plVar1;
  uint uVar2;
  longlong *local_res10 [3];
  
                    /* 0x249a0  14  ViewBrowser */
  local_res10[0] = (longlong *)0x0;
  (**(code **)(*DAT_1800797f0 + 0x90))(DAT_1800797f0,local_res10);
  plVar1 = local_res10[0];
  if (local_res10[0] == (longlong *)0x0) {
    return 0;
  }
  FUN_18003b0a0(local_res10[0],1);
  (**(code **)(*local_res10[0] + 0x10))();
  uVar2 = FUN_18005b910("mmgBrowser.MDIBrowser",local_res10[0],DAT_1800797f0,param_1);
  FUN_18003b0a0(plVar1,0);
  return ~uVar2 >> 0x1f;
}

/* ---- FUNC 00024A40 ViewExplorer (153 bytes) ---- */

void ViewExplorer(void)

{
  HWND hWnd;
  
                    /* 0x24a40  13  ViewExplorer */
  hWnd = CreateWindowExA(0,"VarExplClass","Variable Explorer",0xcf0000,-0x80000000,0,-0x80000000,0,
                         (HWND)0x0,(HMENU)0x0,DAT_1800797d8,(LPVOID)0x0);
  if (hWnd != (HWND)0x0) {
    ShowWindow(hWnd,1);
    UpdateWindow(hWnd);
    FUN_180021eb0(hWnd,DAT_1800797d8,*(undefined8 *)(DAT_1800797f0 + 0x20));
    return;
  }
  return;
}

/* ---- FUNC 00024AE0 WriteHappArchive (273 bytes) ---- */

undefined8 WriteHappArchive(char *param_1,uint param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  int cchWideChar;
  int iVar2;
  ULONG UVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  BSTR local_res8;
  
                    /* 0x24ae0  17  WriteHappArchive */
  iVar1 = _stricmp((char *)DAT_1800797f0[0x21].lpVtbl,param_1);
  uVar4 = 0;
  if (param_1 == (char *)0x0) {
    local_res8 = (BSTR)0x0;
  }
  else {
    param_4 = 0xffffffff;
    cchWideChar = MultiByteToWideChar(0,0,param_1,-1,(LPWSTR)0x0,0);
    local_res8 = SysAllocStringLen((OLECHAR *)0x0,cchWideChar - 1);
    if (local_res8 != (BSTR)0x0) {
      param_4 = 0xffffffff;
      iVar2 = MultiByteToWideChar(0,0,param_1,-1,local_res8,cchWideChar);
      if (iVar2 != cchWideChar) {
        SysFreeString(local_res8);
        goto LAB_180024be7;
      }
    }
    if (local_res8 == (BSTR)0x0) {
LAB_180024be7:
                    /* WARNING: Subroutine does not return */
      FUN_180001a90(-0x7ff8fff2);
    }
  }
  uVar5 = (ulonglong)param_2;
  UVar3 = (*DAT_1800797f0->lpVtbl[0xf].AddRef)(DAT_1800797f0);
  if (UVar3 == 0) {
    if (iVar1 != 0) {
      FUN_18001d5e0(DAT_1800797f0,param_1,uVar5,param_4);
    }
    uVar4 = 1;
  }
  SysFreeString(local_res8);
  return uVar4;
}

/* ---- FUNC 00024C00 DllGetClassObject (91 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

HRESULT __stdcall DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  undefined8 *puVar9;
  longlong *plVar10;
  
                    /* 0x24c00  38  DllGetClassObject */
  *ppv = (LPVOID)0x0;
  lVar1._0_4_ = riid->Data1;
  lVar1._4_2_ = riid->Data2;
  lVar1._6_2_ = riid->Data3;
  if (((lVar1 != DAT_180066c68) || (*(longlong *)riid->Data4 != DAT_180066c70)) &&
     ((lVar2._0_4_ = riid->Data1, lVar2._4_2_ = riid->Data2, lVar2._6_2_ = riid->Data3,
      lVar2 != DAT_180066c58 || (*(longlong *)riid->Data4 != DAT_180066c60)))) {
    return -0x7fffbffe;
  }
  lVar3._0_4_ = rclsid->Data1;
  lVar3._4_2_ = rclsid->Data2;
  lVar3._6_2_ = rclsid->Data3;
  if (((lVar3 == DAT_180063560) && (*(longlong *)rclsid->Data4 == DAT_180063568)) ||
     ((lVar4._0_4_ = rclsid->Data1, lVar4._4_2_ = rclsid->Data2, lVar4._6_2_ = rclsid->Data3,
      lVar4 == _DAT_1800635b0 && (*(longlong *)rclsid->Data4 == _UNK_1800635b8)))) {
    puVar9 = operator_new(0x10);
    if (puVar9 == (undefined8 *)0x0) {
      return -0x7ff8fff2;
    }
    plVar10 = FUN_180050110(puVar9);
  }
  else {
    lVar5._0_4_ = rclsid->Data1;
    lVar5._4_2_ = rclsid->Data2;
    lVar5._6_2_ = rclsid->Data3;
    if (((lVar5 == DAT_180063580) && (*(longlong *)rclsid->Data4 == DAT_180063588)) ||
       ((lVar6._0_4_ = rclsid->Data1, lVar6._4_2_ = rclsid->Data2, lVar6._6_2_ = rclsid->Data3,
        lVar6 == _DAT_1800635a0 && (*(longlong *)rclsid->Data4 == _UNK_1800635a8)))) {
      puVar9 = operator_new(0x10);
      if (puVar9 == (undefined8 *)0x0) {
        return -0x7ff8fff2;
      }
      plVar10 = FUN_180005a60(puVar9);
    }
    else {
      lVar7._0_4_ = rclsid->Data1;
      lVar7._4_2_ = rclsid->Data2;
      lVar7._6_2_ = rclsid->Data3;
      if (((lVar7 != DAT_180063530) || (*(longlong *)rclsid->Data4 != DAT_180063538)) &&
         ((lVar8._0_4_ = rclsid->Data1, lVar8._4_2_ = rclsid->Data2, lVar8._6_2_ = rclsid->Data3,
          lVar8 != _DAT_180063590 || (*(longlong *)rclsid->Data4 != _UNK_180063598)))) {
        return -0x7ffbfeef;
      }
      puVar9 = operator_new(0x10);
      if (puVar9 == (undefined8 *)0x0) {
        return -0x7ff8fff2;
      }
      plVar10 = FUN_180021330(puVar9,1);
    }
  }
  if (plVar10 == (longlong *)0x0) {
    return -0x7ff8fff2;
  }
  (**(code **)(*plVar10 + 8))(plVar10);
  *ppv = plVar10;
  return 0;
}

/* ---- FUNC 00024C5B FUN_180024c5b (277 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_180024c5b(longlong *param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong *plVar2;
  undefined8 *unaff_RDI;
  bool in_ZF;
  longlong in_XMM1_Qb;
  
  if (((in_ZF) && (param_1[1] == DAT_180063568)) ||
     ((*param_1 == param_2 && (param_1[1] == in_XMM1_Qb)))) {
    puVar1 = operator_new(0x10);
    if (puVar1 == (undefined8 *)0x0) {
      return 0x8007000e;
    }
    plVar2 = FUN_180050110(puVar1);
  }
  else if (((*param_1 == DAT_180063580) && (param_1[1] == DAT_180063588)) ||
          ((*param_1 == _DAT_1800635a0 && (param_1[1] == _UNK_1800635a8)))) {
    puVar1 = operator_new(0x10);
    if (puVar1 == (undefined8 *)0x0) {
      return 0x8007000e;
    }
    plVar2 = FUN_180005a60(puVar1);
  }
  else {
    if (((*param_1 != DAT_180063530) || (param_1[1] != DAT_180063538)) &&
       ((*param_1 != _DAT_180063590 || (param_1[1] != _UNK_180063598)))) {
      return 0x80040111;
    }
    puVar1 = operator_new(0x10);
    if (puVar1 == (undefined8 *)0x0) {
      return 0x8007000e;
    }
    plVar2 = FUN_180021330(puVar1,1);
  }
  if (plVar2 == (longlong *)0x0) {
    return 0x8007000e;
  }
  (**(code **)(*plVar2 + 8))(plVar2);
  *unaff_RDI = plVar2;
  return 0;
}

/* ---- FUNC 00024D70 FUN_180024d70 (16 bytes) ---- */

undefined8 FUN_180024d70(void)

{
  return 0x8007000e;
}

/* ---- FUNC 00024D80 FUN_180024d80 (16 bytes) ---- */

undefined8 FUN_180024d80(void)

{
  return 0x80040111;
}

/* ---- FUNC 00024D90 FUN_180024d90 (11 bytes) ---- */

undefined8 FUN_180024d90(void)

{
  return 0x80004002;
}

/* ---- FUNC 00024DA0 FUN_180024da0 (158 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char * FUN_180024da0(char *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  DWORD DVar4;
  char *pcVar5;
  char *pcVar6;
  FILE *_File;
  longlong lVar7;
  char *pcVar9;
  char *_Dest;
  char *pcVar10;
  char cVar11;
  undefined1 auStack_148 [32];
  CHAR local_128 [256];
  ulonglong local_28;
  longlong lVar8;
  
  local_28 = DAT_180077818 ^ (ulonglong)auStack_148;
  strncpy(param_1,param_2,0xff);
  iVar2 = _getdrive();
  pcVar10 = param_1 + 0x208;
  *(int *)(param_1 + 0x104) = iVar2;
  pcVar5 = _getcwd(pcVar10,0x100);
  if (pcVar5 == (char *)0x0) {
    *pcVar10 = '\0';
  }
  lVar7 = -1;
  do {
    lVar8 = lVar7;
    lVar7 = lVar8 + 1;
  } while (param_2[lVar7] != '\0');
  pcVar5 = malloc(lVar8 + 2);
  if (pcVar5 != (char *)0x0) {
    pcVar9 = param_2;
    do {
      cVar11 = *pcVar9;
      pcVar9[(longlong)pcVar5 - (longlong)param_2] = cVar11;
      pcVar9 = pcVar9 + 1;
    } while (cVar11 != '\0');
    if ((pcVar5[1] == ':') && (iVar2 = isalpha((int)*pcVar5), iVar2 != 0)) {
      iVar3 = islower((int)*pcVar5);
      iVar2 = (int)*pcVar5;
      if (iVar3 != 0) {
        iVar2 = toupper(iVar2);
      }
      iVar2 = iVar2 + -0x40;
      pcVar9 = pcVar5 + 2;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x104);
      pcVar9 = pcVar5;
    }
    *(int *)(param_1 + 0x100) = iVar2;
    pcVar6 = strrchr(pcVar9,0x5c);
    _Dest = param_1 + 0x108;
    if (pcVar6 == (char *)0x0) {
      do {
        cVar11 = *pcVar10;
        pcVar10 = pcVar10 + 1;
        *_Dest = cVar11;
        _Dest = _Dest + 1;
      } while (cVar11 != '\0');
    }
    else {
      *pcVar6 = '\0';
      strncpy(_Dest,pcVar9,0xff);
    }
    free(pcVar5);
    DVar4 = GetShortPathNameA(param_2,local_128,0x100);
    if ((DVar4 == 0) && (DVar4 = GetLastError(), DVar4 == 2)) {
      _File = fopen(param_2,"a");
      fclose(_File);
      GetShortPathNameA(param_2,local_128,0x100);
      remove(param_2);
    }
    pcVar10 = local_128;
    pcVar5 = strrchr(local_128,0x5c);
    if (pcVar5 != (char *)0x0) {
      pcVar10 = pcVar5 + 1;
    }
    pcVar5 = strrchr(pcVar10,0x2e);
    if (pcVar5 == (char *)0x0) {
      param_1[0x31a] = '\0';
    }
    else {
      strncpy(param_1 + 0x31a,pcVar5 + 1,3);
      param_1[0x31d] = '\0';
      *pcVar5 = '\0';
    }
    strncpy(param_1 + 0x311,pcVar10,8);
    lVar7 = 0;
    param_1[0x319] = '\0';
    iVar2 = 2;
    cVar11 = 'a';
    do {
      if (0x80 < (byte)param_1[lVar7 + 0x311]) {
        cVar1 = '_';
        if (lVar7 == 0) {
          cVar1 = cVar11;
        }
        param_1[lVar7 + 0x311] = cVar1;
      }
      if (0x80 < (byte)param_1[lVar7 + 0x312]) {
        cVar1 = '_';
        if (iVar2 == 1) {
          cVar1 = cVar11;
        }
        param_1[lVar7 + 0x312] = cVar1;
      }
      if (0x80 < (byte)param_1[lVar7 + 0x313]) {
        cVar1 = '_';
        if (iVar2 == 0) {
          cVar1 = cVar11;
        }
        param_1[lVar7 + 0x313] = cVar1;
      }
      if (0x80 < (byte)param_1[lVar7 + 0x314]) {
        cVar1 = '_';
        if (iVar2 == -1) {
          cVar1 = cVar11;
        }
        param_1[lVar7 + 0x314] = cVar1;
      }
      if (0x80 < (byte)param_1[lVar7 + 0x315]) {
        cVar1 = '_';
        if (iVar2 == -2) {
          cVar1 = cVar11;
        }
        param_1[lVar7 + 0x315] = cVar1;
      }
      if (0x80 < (byte)param_1[lVar7 + 0x316]) {
        cVar1 = '_';
        if (iVar2 == -3) {
          cVar1 = cVar11;
        }
        param_1[lVar7 + 0x316] = cVar1;
      }
      if (0x80 < (byte)param_1[lVar7 + 0x317]) {
        cVar1 = '_';
        if (iVar2 == -4) {
          cVar1 = cVar11;
        }
        param_1[lVar7 + 0x317] = cVar1;
      }
      if (0x80 < (byte)param_1[lVar7 + 0x318]) {
        cVar1 = '_';
        if (iVar2 == -5) {
          cVar1 = cVar11;
        }
        param_1[lVar7 + 0x318] = cVar1;
      }
      iVar2 = iVar2 + 8;
      lVar7 = lVar7 + 8;
    } while (lVar7 < 8);
    return param_1;
  }
  *(undefined4 *)(param_1 + 0x100) = *(undefined4 *)(param_1 + 0x104);
  *pcVar10 = '\0';
  param_1[0x108] = '\0';
  param_1[0x311] = '\0';
  return param_1;
}

/* ---- FUNC 00024E3E FUN_180024e3e (204 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180024e3e(undefined8 param_1,longlong param_2)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  DWORD DVar5;
  char *pcVar6;
  FILE *_File;
  char *pcVar7;
  char *pcVar8;
  char *unaff_RBX;
  LPCSTR unaff_RBP;
  char *unaff_RSI;
  longlong unaff_RDI;
  longlong lVar9;
  undefined1 uVar10;
  CHAR aCStackX_20 [8];
  
  pcVar8 = unaff_RBP;
  do {
    cVar1 = *pcVar8;
    pcVar8[param_2 - (longlong)unaff_RBP] = cVar1;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  if (unaff_RSI[1] == ':') {
    iVar3 = isalpha((int)*unaff_RSI);
    if (iVar3 != 0) {
      iVar4 = islower((int)*unaff_RSI);
      iVar3 = (int)*unaff_RSI;
      if (iVar4 != 0) {
        iVar3 = toupper(iVar3);
      }
      iVar3 = iVar3 + -0x40;
      pcVar8 = unaff_RSI + 2;
      goto LAB_180024e9b;
    }
  }
  iVar3 = *(int *)(unaff_RDI + 0x104);
  pcVar8 = unaff_RSI;
LAB_180024e9b:
  *(int *)(unaff_RDI + 0x100) = iVar3;
  pcVar6 = strrchr(pcVar8,0x5c);
  pcVar7 = (char *)(unaff_RDI + 0x108);
  if (pcVar6 == (char *)0x0) {
    do {
      cVar1 = *unaff_RBX;
      unaff_RBX = unaff_RBX + 1;
      *pcVar7 = cVar1;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
  }
  else {
    *pcVar6 = '\0';
    strncpy(pcVar7,pcVar8,0xff);
  }
  free(unaff_RSI);
  DVar5 = GetShortPathNameA(unaff_RBP,aCStackX_20,0x100);
  if (DVar5 == 0) {
    DVar5 = GetLastError();
    if (DVar5 == 2) {
      _File = fopen(unaff_RBP,"a");
      fclose(_File);
      GetShortPathNameA(unaff_RBP,aCStackX_20,0x100);
      remove(unaff_RBP);
    }
  }
  pcVar8 = aCStackX_20;
  pcVar7 = strrchr(aCStackX_20,0x5c);
  if (pcVar7 != (char *)0x0) {
    pcVar8 = pcVar7 + 1;
  }
  pcVar7 = strrchr(pcVar8,0x2e);
  if (pcVar7 == (char *)0x0) {
    *(undefined1 *)(unaff_RDI + 0x31a) = 0;
  }
  else {
    strncpy((char *)(unaff_RDI + 0x31a),pcVar7 + 1,3);
    *(undefined1 *)(unaff_RDI + 0x31d) = 0;
    *pcVar7 = '\0';
  }
  strncpy((char *)(unaff_RDI + 0x311),pcVar8,8);
  lVar9 = 0;
  *(undefined1 *)(unaff_RDI + 0x319) = 0;
  iVar3 = 2;
  uVar10 = 0x61;
  do {
    if (0x80 < *(byte *)(lVar9 + 0x311 + unaff_RDI)) {
      uVar2 = 0x5f;
      if (lVar9 == 0) {
        uVar2 = uVar10;
      }
      *(undefined1 *)(lVar9 + 0x311 + unaff_RDI) = uVar2;
    }
    if (0x80 < *(byte *)(lVar9 + 0x312 + unaff_RDI)) {
      uVar2 = 0x5f;
      if (iVar3 == 1) {
        uVar2 = uVar10;
      }
      *(undefined1 *)(lVar9 + 0x312 + unaff_RDI) = uVar2;
    }
    if (0x80 < *(byte *)(lVar9 + 0x313 + unaff_RDI)) {
      uVar2 = 0x5f;
      if (iVar3 == 0) {
        uVar2 = uVar10;
      }
      *(undefined1 *)(lVar9 + 0x313 + unaff_RDI) = uVar2;
    }
    if (0x80 < *(byte *)(lVar9 + 0x314 + unaff_RDI)) {
      uVar2 = 0x5f;
      if (iVar3 == -1) {
        uVar2 = uVar10;
      }
      *(undefined1 *)(lVar9 + 0x314 + unaff_RDI) = uVar2;
    }
    if (0x80 < *(byte *)(lVar9 + 0x315 + unaff_RDI)) {
      uVar2 = 0x5f;
      if (iVar3 == -2) {
        uVar2 = uVar10;
      }
      *(undefined1 *)(lVar9 + 0x315 + unaff_RDI) = uVar2;
    }
    if (0x80 < *(byte *)(lVar9 + 0x316 + unaff_RDI)) {
      uVar2 = 0x5f;
      if (iVar3 == -3) {
        uVar2 = uVar10;
      }
      *(undefined1 *)(lVar9 + 0x316 + unaff_RDI) = uVar2;
    }
    if (0x80 < *(byte *)(lVar9 + 0x317 + unaff_RDI)) {
      uVar2 = 0x5f;
      if (iVar3 == -4) {
        uVar2 = uVar10;
      }
      *(undefined1 *)(lVar9 + 0x317 + unaff_RDI) = uVar2;
    }
    if (0x80 < *(byte *)(lVar9 + 0x318 + unaff_RDI)) {
      uVar2 = 0x5f;
      if (iVar3 == -5) {
        uVar2 = uVar10;
      }
      *(undefined1 *)(lVar9 + 0x318 + unaff_RDI) = uVar2;
    }
    iVar3 = iVar3 + 8;
    lVar9 = lVar9 + 8;
  } while (lVar9 < 8);
  return;
}

/* ---- FUNC 00024F0A FUN_180024f0a (512 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180024f0a(void)

{
  undefined1 uVar1;
  DWORD DVar2;
  FILE *_File;
  char *pcVar3;
  int iVar4;
  char *unaff_RBP;
  char *_Str;
  longlong unaff_RDI;
  longlong lVar5;
  undefined1 uVar6;
  CHAR aCStackX_20 [8];
  
  DVar2 = GetLastError();
  if (DVar2 == 2) {
    _File = fopen(unaff_RBP,"a");
    fclose(_File);
    GetShortPathNameA(unaff_RBP,aCStackX_20,0x100);
    remove(unaff_RBP);
  }
  _Str = aCStackX_20;
  pcVar3 = strrchr(aCStackX_20,0x5c);
  if (pcVar3 != (char *)0x0) {
    _Str = pcVar3 + 1;
  }
  pcVar3 = strrchr(_Str,0x2e);
  if (pcVar3 == (char *)0x0) {
    *(undefined1 *)(unaff_RDI + 0x31a) = 0;
  }
  else {
    strncpy((char *)(unaff_RDI + 0x31a),pcVar3 + 1,3);
    *(undefined1 *)(unaff_RDI + 0x31d) = 0;
    *pcVar3 = '\0';
  }
  strncpy((char *)(unaff_RDI + 0x311),_Str,8);
  lVar5 = 0;
  *(undefined1 *)(unaff_RDI + 0x319) = 0;
  iVar4 = 2;
  uVar6 = 0x61;
  do {
    if (0x80 < *(byte *)(lVar5 + 0x311 + unaff_RDI)) {
      uVar1 = 0x5f;
      if (lVar5 == 0) {
        uVar1 = uVar6;
      }
      *(undefined1 *)(lVar5 + 0x311 + unaff_RDI) = uVar1;
    }
    if (0x80 < *(byte *)(lVar5 + 0x312 + unaff_RDI)) {
      uVar1 = 0x5f;
      if (iVar4 == 1) {
        uVar1 = uVar6;
      }
      *(undefined1 *)(lVar5 + 0x312 + unaff_RDI) = uVar1;
    }
    if (0x80 < *(byte *)(lVar5 + 0x313 + unaff_RDI)) {
      uVar1 = 0x5f;
      if (iVar4 == 0) {
        uVar1 = uVar6;
      }
      *(undefined1 *)(lVar5 + 0x313 + unaff_RDI) = uVar1;
    }
    if (0x80 < *(byte *)(lVar5 + 0x314 + unaff_RDI)) {
      uVar1 = 0x5f;
      if (iVar4 == -1) {
        uVar1 = uVar6;
      }
      *(undefined1 *)(lVar5 + 0x314 + unaff_RDI) = uVar1;
    }
    if (0x80 < *(byte *)(lVar5 + 0x315 + unaff_RDI)) {
      uVar1 = 0x5f;
      if (iVar4 == -2) {
        uVar1 = uVar6;
      }
      *(undefined1 *)(lVar5 + 0x315 + unaff_RDI) = uVar1;
    }
    if (0x80 < *(byte *)(lVar5 + 0x316 + unaff_RDI)) {
      uVar1 = 0x5f;
      if (iVar4 == -3) {
        uVar1 = uVar6;
      }
      *(undefined1 *)(lVar5 + 0x316 + unaff_RDI) = uVar1;
    }
    if (0x80 < *(byte *)(lVar5 + 0x317 + unaff_RDI)) {
      uVar1 = 0x5f;
      if (iVar4 == -4) {
        uVar1 = uVar6;
      }
      *(undefined1 *)(lVar5 + 0x317 + unaff_RDI) = uVar1;
    }
    if (0x80 < *(byte *)(lVar5 + 0x318 + unaff_RDI)) {
      uVar1 = 0x5f;
      if (iVar4 == -5) {
        uVar1 = uVar6;
      }
      *(undefined1 *)(lVar5 + 0x318 + unaff_RDI) = uVar1;
    }
    iVar4 = iVar4 + 8;
    lVar5 = lVar5 + 8;
  } while (lVar5 < 8);
  return;
}

/* ---- FUNC 00025110 FUN_180025110 (54 bytes) ---- */

undefined8 FUN_180025110(longlong param_1)

{
  if (*(int *)(param_1 + 0x104) != 0) {
    _chdrive(*(int *)(param_1 + 0x104));
  }
  if ((char *)(param_1 + 0x208) != (char *)0x0) {
    _chdir((char *)(param_1 + 0x208));
  }
  return 1;
}

/* ---- FUNC 00025150 FUN_180025150 (54 bytes) ---- */

undefined8 FUN_180025150(longlong param_1)

{
  if (*(int *)(param_1 + 0x100) != 0) {
    _chdrive(*(int *)(param_1 + 0x100));
  }
  if (*(char *)(param_1 + 0x108) != '\0') {
    _chdir((char *)(param_1 + 0x108));
  }
  return 1;
}

/* ---- FUNC 00025190 FUN_180025190 (44 bytes) ---- */

HRESULT FUN_180025190(VARIANTARG *param_1,LCID param_2,LCID param_3)

{
  VARTYPE vt;
  BSTR pOVar1;
  HRESULT HVar2;
  UINT UVar3;
  INT IVar4;
  BSTR local_res8;
  
  vt = (param_1->n1).n2.vt;
  if (((byte)vt & 5) == 5) {
    return 0;
  }
  HVar2 = VariantChangeTypeEx(param_1,param_1,param_2,0,5);
  if (HVar2 != 0) {
    if ((param_1->n1).n2.vt == 8) {
      pOVar1 = *(BSTR *)((longlong)&param_1->n1 + 8);
      UVar3 = SysStringLen(pOVar1);
      if (pOVar1[UVar3 - 1] == L'%') {
        UVar3 = SysStringLen(pOVar1);
        pOVar1[UVar3 - 1] = L'\0';
        HVar2 = VariantChangeTypeEx(param_1,param_1,param_2,0,5);
        if (HVar2 < 0) {
          return HVar2;
        }
        HVar2 = VariantChangeTypeEx(param_1,param_1,param_3,0,vt);
        if (HVar2 < 0) {
          return HVar2;
        }
        pOVar1 = *(BSTR *)((longlong)&param_1->n1 + 8);
        UVar3 = SysStringLen(pOVar1);
        local_res8 = (BSTR)0x0;
        IVar4 = SysReAllocStringLen(&local_res8,pOVar1,UVar3 + 1);
        if (local_res8 == (BSTR)0x0) {
          return IVar4;
        }
        local_res8[(longlong)(int)(UVar3 + 1) + -1] = L'%';
        (param_1->n1).decVal.u2.Lo64 = (ULONGLONG)local_res8;
        SysFreeString(pOVar1);
        return IVar4;
      }
    }
    if (HVar2 < 0) {
      return HVar2;
    }
  }
  HVar2 = VariantChangeTypeEx(param_1,param_1,param_3,0,vt);
  return HVar2;
}

/* ---- FUNC 000251BC FUN_1800251bc (92 bytes) ---- */

HRESULT FUN_1800251bc(VARIANTARG *param_1)

{
  BSTR pOVar1;
  HRESULT HVar2;
  UINT UVar3;
  INT IVar4;
  VARIANTARG *unaff_RBX;
  LCID unaff_EBP;
  VARTYPE unaff_SI;
  LCID unaff_R15D;
  BSTR in_stack_00000060;
  
  HVar2 = VariantChangeTypeEx(param_1,unaff_RBX,unaff_R15D,0,5);
  if (HVar2 != 0) {
    if ((unaff_RBX->n1).n2.vt == 8) {
      pOVar1 = *(BSTR *)((longlong)&unaff_RBX->n1 + 8);
      UVar3 = SysStringLen(pOVar1);
      if (pOVar1[UVar3 - 1] == L'%') {
        UVar3 = SysStringLen(pOVar1);
        pOVar1[UVar3 - 1] = L'\0';
        HVar2 = VariantChangeTypeEx(unaff_RBX,unaff_RBX,unaff_R15D,0,5);
        if (HVar2 < 0) {
          return HVar2;
        }
        HVar2 = VariantChangeTypeEx(unaff_RBX,unaff_RBX,unaff_EBP,0,unaff_SI);
        if (HVar2 < 0) {
          return HVar2;
        }
        pOVar1 = *(BSTR *)((longlong)&unaff_RBX->n1 + 8);
        UVar3 = SysStringLen(pOVar1);
        in_stack_00000060 = (BSTR)0x0;
        IVar4 = SysReAllocStringLen(&stack0x00000060,pOVar1,UVar3 + 1);
        if (in_stack_00000060 == (BSTR)0x0) {
          return IVar4;
        }
        in_stack_00000060[(longlong)(int)(UVar3 + 1) + -1] = L'%';
        (unaff_RBX->n1).decVal.u2.Lo64 = (ULONGLONG)in_stack_00000060;
        SysFreeString(pOVar1);
        return IVar4;
      }
    }
    if (HVar2 < 0) {
      return HVar2;
    }
  }
  HVar2 = VariantChangeTypeEx(unaff_RBX,unaff_RBX,unaff_EBP,0,unaff_SI);
  return HVar2;
}

/* ---- FUNC 00025218 FUN_180025218 (161 bytes) ---- */

HRESULT FUN_180025218(BSTR param_1)

{
  BSTR psz;
  UINT UVar1;
  HRESULT HVar2;
  VARIANTARG *unaff_RBX;
  LCID unaff_EBP;
  VARTYPE unaff_SI;
  VARTYPE unaff_R12W;
  longlong unaff_R14;
  LCID unaff_R15D;
  BSTR in_stack_00000060;
  
  UVar1 = SysStringLen(param_1);
  *(undefined2 *)(unaff_R14 + (ulonglong)(UVar1 - 1) * 2) = 0;
  HVar2 = VariantChangeTypeEx(unaff_RBX,unaff_RBX,unaff_R15D,0,unaff_R12W);
  if ((-1 < HVar2) &&
     (HVar2 = VariantChangeTypeEx(unaff_RBX,unaff_RBX,unaff_EBP,0,unaff_SI), -1 < HVar2)) {
    psz = *(BSTR *)((longlong)&unaff_RBX->n1 + 8);
    UVar1 = SysStringLen(psz);
    in_stack_00000060 = (BSTR)0x0;
    HVar2 = SysReAllocStringLen(&stack0x00000060,psz,UVar1 + 1);
    if (in_stack_00000060 != (BSTR)0x0) {
      in_stack_00000060[(longlong)(int)(UVar1 + 1) + -1] = L'%';
      (unaff_RBX->n1).decVal.u2.Lo64 = (ULONGLONG)in_stack_00000060;
      SysFreeString(psz);
    }
  }
  return HVar2;
}

/* ---- FUNC 000252B9 FUN_1800252b9 (25 bytes) ---- */

void FUN_1800252b9(void)

{
  return;
}

/* ---- FUNC 000252D2 FUN_1800252d2 (33 bytes) ---- */

HRESULT FUN_1800252d2(void)

{
  VARIANTARG *unaff_RBX;
  LCID unaff_EBP;
  VARTYPE unaff_SI;
  HRESULT unaff_EDI;
  
  if (-1 < unaff_EDI) {
    unaff_EDI = VariantChangeTypeEx(unaff_RBX,unaff_RBX,unaff_EBP,0,unaff_SI);
  }
  return unaff_EDI;
}

/* ---- FUNC 00025300 FUN_180025300 (139 bytes) ---- */

undefined8 * FUN_180025300(undefined8 *param_1)

{
  *param_1 = CHSelection::vftable;
  param_1[1] = CHSelection::XSelectionDragDrop::vftable;
  FUN_1800212f0(param_1 + 5,param_1,&DAT_180063430);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x13));
  CPtrArray::CPtrArray((CPtrArray *)(param_1 + 0x14));
  CPtrArray::CPtrArray((CPtrArray *)(param_1 + 0x19));
  *(undefined4 *)(param_1 + 4) = 0;
  param_1[3] = 0;
  param_1[0x12] = 0;
  *(undefined4 *)(param_1 + 2) = 0;
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

/* ---- FUNC 00025390 FUN_180025390 (231 bytes) ---- */

undefined8 * FUN_180025390(undefined8 *param_1)

{
  undefined8 *puVar1;
  longlong *plVar2;
  
  *param_1 = CHSelectionLinkContainer::vftable;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 3));
  CPtrArray::CPtrArray((CPtrArray *)(param_1 + 6));
  CStringArray::CStringArray((CStringArray *)(param_1 + 0x11));
  CDWordArray::CDWordArray((CDWordArray *)(param_1 + 0x16));
  CDWordArray::CDWordArray((CDWordArray *)(param_1 + 0x1b));
  plVar2 = (longlong *)0x0;
  *(undefined4 *)(param_1 + 4) = 0;
  param_1[2] = 0;
  param_1[5] = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  *(undefined4 *)(param_1 + 1) = 1;
  puVar1 = operator_new(0x28);
  if (puVar1 != (undefined8 *)0x0) {
    plVar2 = FUN_180058810(puVar1,param_1,param_1,3);
  }
  param_1[0xb] = plVar2;
  if (plVar2 != (longlong *)0x0) {
    (**(code **)(*plVar2 + 8))(plVar2);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 3),"");
  *(undefined4 *)(param_1 + 0x10) = 1;
  return param_1;
}

/* ---- FUNC 00025480 FUN_180025480 (283 bytes) ---- */

undefined8 * FUN_180025480(undefined8 *param_1)

{
  undefined8 *puVar1;
  longlong *plVar2;
  
  *param_1 = CHSelectionLinkSource::vftable;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 2));
  FUN_180041f10(param_1 + 3,param_1,param_1,1);
  CPtrArray::CPtrArray((CPtrArray *)(param_1 + 10));
  CPtrArray::CPtrArray((CPtrArray *)(param_1 + 0xf));
  FUN_180058ec0(param_1 + 0x16,param_1,param_1,2);
  CStringArray::CStringArray((CStringArray *)(param_1 + 0x1c));
  CPtrArray::CPtrArray((CPtrArray *)(param_1 + 0x22));
  CDWordArray::CDWordArray((CDWordArray *)(param_1 + 0x27));
  plVar2 = (longlong *)0x0;
  *(undefined4 *)(param_1 + 9) = 0;
  param_1[0x15] = 0;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 2),"");
  puVar1 = operator_new(0x28);
  if (puVar1 != (undefined8 *)0x0) {
    plVar2 = FUN_180058810(puVar1,param_1,param_1,2);
  }
  param_1[0x1b] = plVar2;
  if (plVar2 != (longlong *)0x0) {
    (**(code **)(*plVar2 + 8))();
  }
  *(undefined4 *)(param_1 + 0x21) = 0;
  *(undefined1 *)(param_1 + 0x2c) = 0;
  return param_1;
}

/* ---- FUNC 000255A0 FUN_1800255a0 (29 bytes) ---- */

undefined8 * FUN_1800255a0(undefined8 *param_1)

{
  *param_1 = DAT_180079590;
  DAT_180079590 = param_1;
  param_1[1] = 0;
  return param_1;
}

/* ---- FUNC 000255C0 FUN_1800255c0 (216 bytes) ---- */

undefined8 *
FUN_1800255c0(undefined8 *param_1,
             CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *param_2,
             longlong *param_3,uint param_4,undefined8 *param_5)

{
  *param_1 = CSelectEntry::vftable;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 2));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 3));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 4));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 10));
  if (param_5 == (undefined8 *)0x0) {
    param_1[8] = 0;
  }
  else {
    (**(code **)*param_5)(param_5,&DAT_180066c58,param_1 + 8);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 4),param_2)
  ;
  param_1[7] = 0;
  param_1[9] = 0;
  param_1[0xb] = 0;
  *(undefined4 *)(param_1 + 1) = 0;
  param_1[5] = 0;
  *(undefined4 *)(param_1 + 6) = 0xffffffff;
  FUN_18002f560((longlong)param_1,param_3,param_4,(char *)0x0);
  return param_1;
}

/* ---- FUNC 000256A0 FUN_1800256a0 (100 bytes) ---- */

undefined8 * FUN_1800256a0(undefined8 *param_1)

{
  *param_1 = CSelectEntry::vftable;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 2));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 3));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 4));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 10));
  *(undefined4 *)(param_1 + 6) = 0xffffffff;
  param_1[5] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[0xb] = 0;
  *(undefined4 *)(param_1 + 1) = 0;
  return param_1;
}

/* ---- FUNC 00025710 FUN_180025710 (21 bytes) ---- */

undefined8 * FUN_180025710(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined2 *)(param_1 + 2) = 0;
  *(undefined8 *)((longlong)param_1 + 0x14) = 0;
  return param_1;
}

/* ---- FUNC 00025730 FUN_180025730 (145 bytes) ---- */

void FUN_180025730(undefined8 *param_1)

{
  *param_1 = CHSelection::vftable;
  FUN_1800272b0((longlong)param_1);
  if ((longlong *)param_1[3] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[3] + 0x10))();
  }
  if ((longlong *)param_1[0x12] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x12] + 0x10))();
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
  CPtrArray::~CPtrArray((CPtrArray *)(param_1 + 0x19));
  CPtrArray::~CPtrArray((CPtrArray *)(param_1 + 0x14));
                    /* WARNING: Could not recover jumptable at 0x0001800257ba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x13));
  return;
}

/* ---- FUNC 000257D0 FUN_1800257d0 (375 bytes) ---- */

void FUN_1800257d0(undefined8 *param_1)

{
  ulonglong uVar1;
  CPtrArray *this;
  ulonglong uVar2;
  longlong *plVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  *param_1 = CHSelectionLinkContainer::vftable;
  FUN_180027550((longlong)param_1);
  if (param_1[0xb] != 0) {
    FUN_180058850(param_1[0xb]);
    (**(code **)(*(longlong *)param_1[0xb] + 0x10))();
  }
  if ((undefined8 *)param_1[5] != (undefined8 *)0x0) {
    (*(code *)**(undefined8 **)param_1[5])();
  }
  uVar5 = 0;
  uVar1 = param_1[8];
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar5 < 0) || ((longlong)param_1[8] <= (longlong)uVar5)) {
LAB_180025942:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      this = *(CPtrArray **)(param_1[7] + uVar5 * 8);
      if (this != (CPtrArray *)0x0) {
        uVar4 = 0;
        uVar2 = *(ulonglong *)(this + 0x10);
        if (uVar2 != 0) {
          do {
            if (((longlong)uVar4 < 0) || (*(longlong *)(this + 0x10) <= (longlong)uVar4))
            goto LAB_180025942;
            plVar3 = *(longlong **)(*(longlong *)(this + 8) + uVar4 * 8);
            if (plVar3 != (longlong *)0x0) {
              (**(code **)(*plVar3 + 0x10))();
            }
            uVar4 = uVar4 + 1;
          } while (uVar4 < uVar2);
        }
        CPtrArray::SetSize(this,0,-1);
        (**(code **)(*(longlong *)this + 8))(this);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
  }
  CPtrArray::SetSize((CPtrArray *)(param_1 + 6),0,-1);
  if ((longlong *)param_1[0xe] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0xe] + 0x10))();
  }
  if ((longlong *)param_1[0xf] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0xf] + 0x10))();
  }
  if ((longlong *)param_1[2] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[2] + 0x10))();
  }
  CDWordArray::~CDWordArray((CDWordArray *)(param_1 + 0x1b));
  CDWordArray::~CDWordArray((CDWordArray *)(param_1 + 0x16));
  CStringArray::~CStringArray((CStringArray *)(param_1 + 0x11));
  CPtrArray::~CPtrArray((CPtrArray *)(param_1 + 6));
                    /* WARNING: Could not recover jumptable at 0x00018002593b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 3));
  return;
}

/* ---- FUNC 00025950 FUN_180025950 (205 bytes) ---- */

void FUN_180025950(undefined8 *param_1)

{
  *param_1 = CHSelectionLinkSource::vftable;
  FUN_1800275b0((longlong)param_1);
  if (param_1[0x1b] != 0) {
    FUN_180058850(param_1[0x1b]);
    (**(code **)(*(longlong *)param_1[0x1b] + 0x10))();
  }
  if ((longlong *)param_1[0x15] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x15] + 0x10))();
  }
  if ((longlong *)param_1[1] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[1] + 0x10))();
  }
  CStringArray::SetSize((CStringArray *)(param_1 + 0x1c),0,-1);
  CDWordArray::~CDWordArray((CDWordArray *)(param_1 + 0x27));
  CPtrArray::~CPtrArray((CPtrArray *)(param_1 + 0x22));
  CStringArray::~CStringArray((CStringArray *)(param_1 + 0x1c));
  FUN_180058ef0(param_1 + 0x16);
  CPtrArray::~CPtrArray((CPtrArray *)(param_1 + 0xf));
  CPtrArray::~CPtrArray((CPtrArray *)(param_1 + 10));
  FUN_1800420c0(param_1 + 3);
                    /* WARNING: Could not recover jumptable at 0x000180025a16. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 2));
  return;
}

/* ---- FUNC 00025A20 FUN_180025a20 (35 bytes) ---- */

void FUN_180025a20(undefined8 *param_1)

{
  DAT_180079590 = *param_1;
  if ((longlong *)param_1[1] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[1] + 0x10))();
  }
  return;
}

/* ---- FUNC 00025A50 FUN_180025a50 (122 bytes) ---- */

void FUN_180025a50(undefined8 *param_1)

{
  *param_1 = CSelectEntry::vftable;
  if ((longlong *)param_1[0xb] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0xb] + 0x10))();
  }
  if ((longlong *)param_1[8] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[8] + 0x10))();
  }
  FUN_1800273b0((longlong)param_1);
  if ((void *)param_1[7] != (void *)0x0) {
    FUN_180025ad0((void *)param_1[7]);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 10));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 4));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 3));
                    /* WARNING: Could not recover jumptable at 0x000180025ac3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 2));
  return;
}

/* ---- FUNC 00025AD0 FUN_180025ad0 (5 bytes) ---- */

void FUN_180025ad0(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bd01. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete(param_1);
  return;
}

/* ---- FUNC 00025AE0 FUN_180025ae0 (126 bytes) ---- */

longlong FUN_180025ae0(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  
  if (param_1 != param_2) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x20),
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               (param_2 + 0x20));
    FUN_18002f560(param_1,*(longlong **)(param_2 + 0x28),*(uint *)(param_2 + 0x30),
                  *(char **)(param_2 + 0x18));
    if (*(undefined8 **)(param_2 + 0x38) != (undefined8 *)0x0) {
      puVar1 = FUN_1800274e0(*(undefined8 **)(param_2 + 0x38));
      *(undefined8 **)(param_1 + 0x38) = puVar1;
    }
    *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_2 + 0x48);
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_2 + 0x4c);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x50),
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               (param_2 + 0x50));
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x10),
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               (param_1 + 0x10));
  }
  return param_1;
}

/* ---- FUNC 00025CD0 FUN_180025cd0 (52 bytes) ---- */

undefined8 * FUN_180025cd0(undefined8 *param_1,uint param_2)

{
  FUN_180025a50(param_1);
  if ((param_2 & 1) != 0) {
    FUN_180025ad0(param_1);
  }
  return param_1;
}

/* ---- FUNC 00025D10 FUN_180025d10 (94 bytes) ---- */

undefined8 FUN_180025d10(longlong param_1)

{
  HRESULT HVar1;
  ULONG UVar2;
  ulonglong uVar3;
  HCURSOR pHVar4;
  LPUNKNOWN local_res8;
  
  if (*(int *)(param_1 + 8) == 1) {
FUN_180025e10:
    MessageBeep(0);
    return 0;
  }
  if (*(int *)(param_1 + 8) == 0x10) {
    uVar3 = FUN_180028420(param_1);
    if ((int)uVar3 < 0) goto FUN_180025e10;
  }
  local_res8 = (LPUNKNOWN)0x0;
  (**(code **)**(undefined8 **)(param_1 + 0x68))
            (*(undefined8 **)(param_1 + 0x68),&DAT_180066db8,&local_res8);
  if (local_res8 == (LPUNKNOWN)0x0) goto FUN_180025e10;
  pHVar4 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
  pHVar4 = SetCursor(pHVar4);
  HVar1 = OleRun(local_res8);
  if (-1 < HVar1) {
    UVar2 = (*local_res8->lpVtbl[3].Release)(local_res8);
    if (-1 < (int)UVar2) {
      if (*(int *)(param_1 + 8) == 2) {
        *(undefined4 *)(param_1 + 8) = 4;
        SetCursor(pHVar4);
        return 0;
      }
      goto LAB_180025df0;
    }
  }
  *(undefined4 *)(param_1 + 8) = 2;
LAB_180025df0:
  SetCursor(pHVar4);
  return 0;
}

/* ---- FUNC 00025D6E FUN_180025d6e (123 bytes) ---- */

undefined8 FUN_180025d6e(undefined8 param_1,LPCSTR param_2)

{
  HRESULT HVar1;
  ULONG UVar2;
  HCURSOR pHVar3;
  longlong unaff_RBX;
  LPUNKNOWN in_stack_00000050;
  
  pHVar3 = LoadCursorA((HINSTANCE)0x0,param_2);
  pHVar3 = SetCursor(pHVar3);
  HVar1 = OleRun(in_stack_00000050);
  if (-1 < HVar1) {
    UVar2 = (*in_stack_00000050->lpVtbl[3].Release)(in_stack_00000050);
    if (-1 < (int)UVar2) {
      if (*(int *)(unaff_RBX + 8) == 2) {
        *(undefined4 *)(unaff_RBX + 8) = 4;
        SetCursor(pHVar3);
        return 0;
      }
      goto LAB_180025df0;
    }
  }
  *(undefined4 *)(unaff_RBX + 8) = 2;
LAB_180025df0:
  SetCursor(pHVar3);
  return 0;
}

/* ---- FUNC 00025DE9 FUN_180025de9 (39 bytes) ---- */

undefined8 FUN_180025de9(void)

{
  longlong unaff_RBX;
  HCURSOR unaff_RDI;
  
  *(undefined4 *)(unaff_RBX + 8) = 2;
  SetCursor(unaff_RDI);
  return 0;
}

/* ---- FUNC 00025E10 FUN_180025e10 (26 bytes) ---- */

undefined8 FUN_180025e10(void)

{
  MessageBeep(0);
  return 0;
}

/* ---- FUNC 00025E30 FUN_180025e30 (4374 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined8 *
FUN_180025e30(longlong *param_1,VARIANTARG *param_2,short param_3,ushort *param_4,undefined8 param_5
             ,undefined8 *param_6,ushort *param_7,ushort *param_8,ushort *param_9,
             undefined8 *param_10,undefined8 *param_11)

{
  undefined8 uVar1;
  char cVar2;
  ushort uVar3;
  code *pcVar4;
  __int64 _Var5;
  _union_1719 _Var6;
  undefined8 uVar7;
  _union_1719 _Var8;
  undefined8 uVar9;
  HRESULT HVar10;
  uint uVar11;
  longlong lVar12;
  ushort *puVar13;
  longlong lVar14;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  char *pcVar15;
  undefined8 *puVar16;
  undefined8 *puVar17;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar18;
  undefined8 uVar19;
  ulonglong uVar20;
  int iVar21;
  longlong *plVar22;
  undefined8 *puVar23;
  longlong *plVar24;
  undefined1 *puVar25;
  undefined1 *puVar26;
  undefined1 *puVar27;
  LPCWSTR pWVar28;
  longlong *plVar29;
  undefined8 uStack_2c0;
  undefined1 auStack_2b8 [32];
  undefined8 local_298;
  _union_2707 *local_290;
  _union_2707 *local_288 [6];
  longlong local_258;
  longlong *local_250;
  int local_248;
  short local_240;
  undefined2 uStack_23e;
  undefined4 uStack_23c;
  longlong *local_238;
  ULONG local_230;
  _union_2707 local_228;
  _union_2707 local_208;
  _union_2707 local_1e8;
  _union_2707 local_1c8;
  _union_2707 local_1a8;
  LPCWSTR local_188 [2];
  _union_2707 local_178;
  _union_2707 local_158;
  char *local_138;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_130 [8];
  _union_2707 local_128;
  _union_2707 local_108;
  _union_2707 local_e8;
  _union_2707 local_c8;
  VARIANTARG local_a8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_90 [8];
  VARIANTARG local_88;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_70 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_68 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_60 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_58 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_50 [8];
  VARIANTARG local_48;
  ulonglong local_30;
  longlong *plVar30;
  
  puVar26 = auStack_2b8;
  puVar27 = auStack_2b8;
  puVar25 = auStack_2b8;
  local_30 = DAT_180077818 ^ (ulonglong)&local_258;
  uStack_23e = 0;
  uStack_2c0 = 0x180025e89;
  local_240 = param_3;
  FUN_180003f10(local_50,(ushort *)param_2);
  uStack_2c0 = 0x180025e98;
  FUN_180003f10(local_58,param_4);
  uStack_2c0 = 0x180025eae;
  FUN_180003f10(local_60,param_7);
  uStack_2c0 = 0x180025ec4;
  FUN_180003f10(local_68,param_8);
  uStack_2c0 = 0x180025eda;
  FUN_180003f10(local_70,param_9);
  if ((int)param_1[2] != 0) {
    puVar23 = (undefined8 *)0x1;
    puVar27 = auStack_2b8;
    goto LAB_180026ec9;
  }
  uVar3 = (param_2->n1).n2.vt;
  if (uVar3 < 0xb) {
    puVar25 = auStack_2b8;
    if ((uVar3 == 10) || (puVar25 = auStack_2b8, uVar3 == 0)) {
LAB_180026221:
      pcVar4 = *(code **)(*param_1 + 0xd8);
      *(undefined8 *)(puVar25 + -8) = 0x180026232;
      uVar11 = (*pcVar4)(param_1,0x7db);
      puVar23 = (undefined8 *)(ulonglong)uVar11;
      puVar27 = puVar25;
      goto LAB_180026ec9;
    }
    if (uVar3 == 2) {
      local_248 = (int)*(short *)((longlong)&param_2->n1 + 8);
    }
    else {
      if (uVar3 != 3) {
        if (uVar3 != 8) goto LAB_180025f8e;
        pWVar28 = *(LPCWSTR *)((longlong)&param_2->n1 + 8);
        puVar25 = auStack_2b8;
        if (pWVar28 != (LPCWSTR)0x0) {
          lVar12 = -1;
          do {
            lVar12 = lVar12 + 1;
          } while (pWVar28[lVar12] != L'\0');
          goto LAB_1800261bb;
        }
        goto LAB_180026221;
      }
      local_248 = *(int *)((longlong)&param_2->n1 + 8);
    }
  }
  else if (uVar3 == 0x4002) {
    local_248 = (int)**(short **)((longlong)&param_2->n1 + 8);
  }
  else {
    if (uVar3 != 0x4003) {
      if (uVar3 == 0x4008) {
        pWVar28 = (LPCWSTR)**(longlong **)((longlong)&param_2->n1 + 8);
        if (pWVar28 != (LPCWSTR)0x0) {
          lVar12 = -1;
          do {
            lVar12 = lVar12 + 1;
          } while (pWVar28[lVar12] != L'\0');
LAB_1800261bb:
          iVar21 = (int)lVar12 + 1;
          puVar25 = auStack_2b8;
          if (iVar21 < 0x40000000) {
            lVar12 = (longlong)(int)lVar12 * 2;
            uVar20 = lVar12 + 0x11;
            if (uVar20 <= lVar12 + 2U) {
              uVar20 = 0xffffffffffffff0;
            }
            uStack_2c0 = 0x1800261ef;
            lVar12 = -(uVar20 & 0xfffffffffffffff0);
            puVar26 = (undefined1 *)((longlong)&local_258 + lVar12);
            puVar25 = auStack_2b8 + lVar12;
            if (puVar26 != (undefined1 *)0x0) {
              *(undefined8 *)((longlong)local_288 + lVar12 + 8) = 0;
              *(undefined8 *)((longlong)local_288 + lVar12) = 0;
              *(int *)((longlong)&local_290 + lVar12) = iVar21 * 2;
              *(undefined1 **)((longlong)&local_298 + lVar12) = puVar26;
              *puVar26 = 0;
              *(undefined8 *)(auStack_2b8 + lVar12 + -8) = 0x180026221;
              WideCharToMultiByte(0,0,pWVar28,-1,*(LPSTR *)((longlong)&local_298 + lVar12),
                                  *(int *)((longlong)&local_290 + lVar12),
                                  *(LPCSTR *)((longlong)local_288 + lVar12),
                                  *(LPBOOL *)((longlong)local_288 + lVar12 + 8));
              puVar25 = auStack_2b8 + lVar12;
            }
          }
        }
      }
      else {
        if (uVar3 == 0x400c) {
          puVar23 = *(undefined8 **)((longlong)&param_2->n1 + 8);
          lVar12 = *param_1;
          _Var6 = *(_union_1719 *)(puVar23 + 1);
          *(undefined8 *)&param_2->n1 = *puVar23;
          (param_2->n1).decVal.u2 = _Var6;
          *(undefined8 *)((longlong)&param_2->n1 + 0x10) = puVar23[2];
          local_1a8._0_8_ = *param_11;
          local_1a8.decVal.u2 = *(_union_1719 *)(param_11 + 1);
          local_1a8._16_8_ = param_11[2];
          local_178._0_8_ = *param_10;
          local_178.decVal.u2 = *(_union_1719 *)(param_10 + 1);
          local_178._16_8_ = param_10[2];
          local_108._0_8_ = *(undefined8 *)param_9;
          local_108.decVal.u2 = *(_union_1719 *)(param_9 + 4);
          local_108._16_8_ = *(undefined8 *)(param_9 + 8);
          local_128._0_8_ = *(undefined8 *)param_8;
          local_128.decVal.u2 = *(_union_1719 *)(param_8 + 4);
          local_128._16_8_ = *(undefined8 *)(param_8 + 8);
          local_158._0_8_ = *(undefined8 *)param_7;
          local_158.decVal.u2 = *(_union_1719 *)(param_7 + 4);
          local_158._16_8_ = *(undefined8 *)(param_7 + 8);
          local_1e8._0_8_ = *param_6;
          local_1e8.decVal.u2 = *(_union_1719 *)(param_6 + 1);
          local_1e8._16_8_ = param_6[2];
          local_288[4] = &local_1a8;
          local_288[3] = &local_178;
          local_288[2] = &local_108;
          local_288[1] = &local_128;
          local_288[0] = &local_158;
          local_290 = &local_1e8;
          local_1c8._0_8_ = *(undefined8 *)param_4;
          local_1c8.decVal.u2 = *(_union_1719 *)(param_4 + 4);
          local_1c8._16_8_ = *(undefined8 *)(param_4 + 8);
          local_208._0_8_ = *(undefined8 *)&param_2->n1;
          local_208.decVal.u2 = (param_2->n1).decVal.u2;
          local_298 = param_5;
          local_208._16_8_ = *(undefined8 *)((longlong)&param_2->n1 + 0x10);
          uStack_2c0 = 0x18002618a;
          uVar11 = (**(code **)(lVar12 + 0x78))(param_1,&local_208,param_3,&local_1c8);
          puVar23 = (undefined8 *)(ulonglong)uVar11;
          goto LAB_180026ec9;
        }
LAB_180025f8e:
        uStack_2c0 = 0x180025f9b;
        VariantInit(&local_88);
        uStack_2c0 = 0x180025fb4;
        HVar10 = VariantChangeType(&local_88,param_2,0,3);
        if (HVar10 == 0) {
          local_248 = local_88.n1._8_4_;
          uStack_2c0 = 0x180025fce;
          VariantClear(&local_88);
          goto LAB_180026255;
        }
        uStack_2c0 = 0x180025fe0;
        VariantClear(&local_88);
        uStack_2c0 = 0x180025ff9;
        HVar10 = VariantChangeType(&local_88,param_2,0,8);
        if (HVar10 == 0) {
          pWVar28 = (LPCWSTR)CONCAT44(local_88.n1._12_4_,local_88.n1._8_4_);
          puVar25 = auStack_2b8;
          if (pWVar28 != (LPCWSTR)0x0) {
            lVar12 = -1;
            do {
              lVar12 = lVar12 + 1;
            } while (pWVar28[lVar12] != L'\0');
            goto LAB_1800261bb;
          }
        }
        else {
          uStack_2c0 = 0x18002600a;
          VariantClear(&local_88);
          puVar25 = auStack_2b8;
        }
      }
      goto LAB_180026221;
    }
    local_248 = **(int **)((longlong)&param_2->n1 + 8);
  }
LAB_180026255:
  plVar30 = (longlong *)0x0;
  plVar29 = (longlong *)0x0;
  plVar24 = (longlong *)0x0;
  local_250 = (longlong *)0x0;
  uStack_2c0 = 0x18002626c;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_130);
  uStack_2c0 = 0x180026279;
  VariantInit(&local_a8);
  uStack_2c0 = 0x180026286;
  VariantInit(&local_48);
  local_230 = 0;
  local_258._0_4_ = 0;
  uStack_2c0 = 0x1800262a2;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_138,"");
  puVar27 = auStack_2b8;
  plVar22 = plVar30;
  switch(param_3) {
  case 0:
  case 0x60:
  case 0x61:
  case 0x62:
  case 99:
    uVar3 = *param_4;
    if ((uVar3 == 9) || (uVar3 == 0xd)) {
      puVar13 = param_4 + 4;
LAB_18002645e:
      plVar24 = *(longlong **)puVar13;
      puVar27 = auStack_2b8;
      plVar22 = plVar29;
      param_3 = local_240;
      if (plVar24 != (longlong *)0x0) {
        uStack_2c0 = 0x180026481;
        iVar21 = (**(code **)*plVar24)(plVar24,&DAT_180063400,&local_250);
        puVar27 = auStack_2b8;
        param_3 = local_240;
        if (-1 < iVar21) {
          local_188[0] = (LPCWSTR)0x0;
          local_208._16_8_ = local_a8.n1._16_8_;
          uStack_2c0 = 0x1800264bf;
          (**(code **)(*local_250 + 0x48))(local_250,&local_208,local_188);
          pWVar28 = local_188[0];
          lVar12 = -1;
          plVar22 = (longlong *)0x0;
          puVar26 = auStack_2b8;
          if (local_188[0] != (LPCWSTR)0x0) {
            do {
              lVar14 = lVar12;
              lVar12 = lVar14 + 1;
            } while (local_188[0][lVar12] != L'\0');
            iVar21 = (int)lVar14 + 2;
            puVar26 = auStack_2b8;
            if (iVar21 < 0x40000000) {
              lVar12 = (longlong)(int)lVar12 * 2;
              uVar20 = lVar12 + 0x11;
              if (uVar20 <= lVar12 + 2U) {
                uVar20 = 0xffffffffffffff0;
              }
              uStack_2c0 = 0x180026514;
              lVar12 = -(uVar20 & 0xfffffffffffffff0);
              plVar22 = (longlong *)((longlong)&local_258 + lVar12);
              if (plVar22 == (longlong *)0x0) {
                plVar22 = (longlong *)0x0;
                puVar26 = auStack_2b8 + lVar12;
              }
              else {
                *(undefined1 *)plVar22 = 0;
                *(undefined8 *)((longlong)local_288 + lVar12 + 8) = 0;
                *(undefined8 *)((longlong)local_288 + lVar12) = 0;
                *(int *)((longlong)&local_290 + lVar12) = iVar21 * 2;
                *(longlong **)((longlong)&local_298 + lVar12) = plVar22;
                *(undefined8 *)(auStack_2b8 + lVar12 + -8) = 0x180026547;
                iVar21 = WideCharToMultiByte(0,0,pWVar28,-1,
                                             *(LPSTR *)((longlong)&local_298 + lVar12),
                                             *(int *)((longlong)&local_290 + lVar12),
                                             *(LPCSTR *)((longlong)local_288 + lVar12),
                                             *(LPBOOL *)((longlong)local_288 + lVar12 + 8));
                puVar26 = auStack_2b8 + lVar12;
                if (iVar21 == 0) {
                  plVar22 = plVar30;
                  puVar26 = auStack_2b8 + lVar12;
                }
              }
            }
          }
          *(undefined8 *)(puVar26 + -8) = 0x180026563;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    (local_130,(char *)plVar22);
          *(undefined8 *)(puVar26 + -8) = 0x18002657a;
          this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                 ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                           (local_130,(int)&local_238);
          *(undefined8 *)(puVar26 + -8) = 0x18002658a;
          iVar21 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                             (this,"@Label");
          *(undefined8 *)(puVar26 + -8) = 0x180026596;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_238);
          if (iVar21 == 0) {
            pcVar4 = *(code **)(*local_250 + 0x10);
            *(undefined8 *)(puVar26 + -8) = 0x1800265a8;
            (*pcVar4)();
            lVar12 = *param_1;
            local_208._0_8_ = *param_11;
            local_208.decVal.u2 = *(_union_1719 *)(param_11 + 1);
            local_208._16_8_ = param_11[2];
            local_1c8._0_8_ = *param_10;
            local_1c8.decVal.u2 = *(_union_1719 *)(param_10 + 1);
            local_1c8._16_8_ = param_10[2];
            local_1e8._0_8_ = *(undefined8 *)param_9;
            local_1e8.decVal.u2 = *(_union_1719 *)(param_9 + 4);
            local_1e8._16_8_ = *(undefined8 *)(param_9 + 8);
            local_158._0_8_ = *(undefined8 *)param_8;
            local_158.decVal.u2 = *(_union_1719 *)(param_8 + 4);
            local_158._16_8_ = *(undefined8 *)(param_8 + 8);
            local_178._0_8_ = *(undefined8 *)param_7;
            local_178.decVal.u2 = *(_union_1719 *)(param_7 + 4);
            local_178._16_8_ = *(undefined8 *)(param_7 + 8);
            uVar1 = *param_6;
            _Var6 = *(_union_1719 *)(param_6 + 1);
            uVar19 = param_6[2];
            *(_union_2707 **)(puVar26 + 0x50) = &local_208;
            *(_union_2707 **)(puVar26 + 0x48) = &local_1c8;
            *(_union_2707 **)(puVar26 + 0x40) = &local_1e8;
            *(_union_2707 **)(puVar26 + 0x38) = &local_158;
            *(_union_2707 **)(puVar26 + 0x30) = &local_178;
            uVar7 = *(undefined8 *)param_4;
            _Var8 = *(_union_1719 *)(param_4 + 4);
            local_e8._0_8_ = uVar1;
            local_e8.decVal.u2 = _Var6;
            *(_union_2707 **)(puVar26 + 0x28) = &local_e8;
            uVar1 = *(undefined8 *)(param_4 + 8);
            uVar9 = *(undefined8 *)&param_2->n1;
            _Var6 = (param_2->n1).decVal.u2;
            local_e8._16_8_ = uVar19;
            local_c8._0_8_ = uVar7;
            local_c8.decVal.u2 = _Var8;
            *(undefined8 *)(puVar26 + 0x20) = param_5;
            local_228._16_8_ = *(undefined8 *)((longlong)&param_2->n1 + 0x10);
            pcVar4 = *(code **)(lVar12 + 0x78);
            local_228._0_8_ = uVar9;
            local_228.decVal.u2 = _Var6;
            local_c8._16_8_ = uVar1;
            *(undefined8 *)(puVar26 + -8) = 0x1800266e4;
            uVar11 = (*pcVar4)(param_1,&local_228,3,&local_c8);
            pWVar28 = local_188[0];
            puVar23 = (undefined8 *)(ulonglong)uVar11;
            *(undefined8 *)(puVar26 + -8) = 0x1800266f3;
            SysFreeString(pWVar28);
            goto LAB_180026eaf;
          }
          *(undefined8 *)(puVar26 + -8) = 0x180026705;
          VariantInit((VARIANTARG *)&local_128.n2);
          *(undefined8 *)(puVar26 + -8) = 0x180026712;
          VariantInit((VARIANTARG *)&local_108.n2);
          *(undefined8 *)(puVar26 + -8) = 0x18002671f;
          VariantInit((VARIANTARG *)&local_1a8.n2);
          plVar22 = local_250;
          local_228._16_8_ = local_a8.n1._16_8_;
          pcVar4 = *(code **)(*local_250 + 0x98);
          *(undefined8 *)(puVar26 + -8) = 0x180026756;
          iVar21 = (*pcVar4)(plVar22,2,&local_228,&local_128);
          if (-1 < iVar21) {
            if (local_128.n2.vt == 2) {
              local_230 = (ULONG)(short)local_128._8_2_;
            }
            else if (local_128.n2.vt == 3) {
              local_230 = local_128._8_4_;
            }
            *(undefined8 *)(puVar26 + -8) = 0x18002678c;
            VariantClear((VARIANTARG *)&local_128.n2);
          }
          plVar22 = local_250;
          local_228._16_8_ = local_a8.n1._16_8_;
          pcVar4 = *(code **)(*local_250 + 0x98);
          *(undefined8 *)(puVar26 + -8) = 0x1800267c1;
          iVar21 = (*pcVar4)(plVar22,3,&local_228,&local_108);
          if (-1 < iVar21) {
            if (local_108.n2.vt == 2) {
              local_258._0_4_ = (int)(short)local_108._8_2_;
            }
            else if (local_108.n2.vt == 3) {
              local_258._0_4_ = local_108._8_4_;
            }
            *(undefined8 *)(puVar26 + -8) = 0x1800267f7;
            VariantClear((VARIANTARG *)&local_108.n2);
          }
          plVar22 = local_250;
          local_228._16_8_ = local_a8.n1._16_8_;
          pcVar4 = *(code **)(*local_250 + 0x98);
          *(undefined8 *)(puVar26 + -8) = 0x18002682c;
          iVar21 = (*pcVar4)(plVar22,0xd,&local_228,&local_1a8);
          uVar19 = local_1a8.decVal.u2;
          if (-1 < iVar21) {
            if (local_1a8.n2.vt == 8) {
              *(undefined8 *)(puVar26 + -8) = 0x18002684b;
              pCVar18 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *
                        )ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                         CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                   ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
                                    )&local_238,(wchar_t *)uVar19);
              *(undefined8 *)(puVar26 + -8) = 0x18002685b;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_138
                         ,pCVar18);
              *(undefined8 *)(puVar26 + -8) = 0x180026865;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_238
                        );
            }
            *(undefined8 *)(puVar26 + -8) = 0x180026872;
            VariantClear((VARIANTARG *)&local_1a8.n2);
          }
          plVar22 = local_250;
          if (local_240 == 99) {
            pcVar4 = *(code **)(*local_250 + 8);
            *(undefined8 *)(puVar26 + -8) = 0x18002688b;
            (*pcVar4)(plVar22);
            plVar24 = (longlong *)&DAT_1800633a4;
            *(undefined8 *)(puVar26 + -8) = 0x1800268a2;
            VariantInit((VARIANTARG *)&local_178.n2);
            plVar30 = local_250;
            local_228._16_8_ = local_a8.n1._16_8_;
            pcVar4 = *(code **)(*local_250 + 0x98);
            *(undefined8 *)(puVar26 + -8) = 0x1800268d4;
            iVar21 = (*pcVar4)(plVar30,0,&local_228);
            plVar30 = plVar22;
            param_3 = 2;
            if (-1 < iVar21) {
              *(undefined2 *)(puVar26 + 0x20) = 8;
              *(undefined8 *)(puVar26 + -8) = 0x180026900;
              HVar10 = VariantChangeTypeEx((VARIANTARG *)&local_178.n2,(VARIANTARG *)&local_178.n2,
                                           0x400,0,*(VARTYPE *)(puVar26 + 0x20));
              uVar19 = local_178.decVal.u2;
              if (((-1 < HVar10) && (local_178.decVal.u2.Lo64 != 0)) &&
                 (*(wchar_t *)local_178.decVal.u2 != L'\0')) {
                *(undefined8 *)(puVar26 + -8) = 0x180026920;
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_240,(wchar_t *)uVar19);
                lVar12 = -1;
                do {
                  lVar14 = lVar12;
                  lVar12 = lVar14 + 1;
                } while (*(char *)(CONCAT44(uStack_23c,CONCAT22(uStack_23e,local_240)) + 1 + lVar14)
                         != '\0');
                *(undefined8 *)(puVar26 + -8) = 0x180026939;
                plVar24 = malloc(lVar14 + 2);
                pcVar15 = (char *)CONCAT44(uStack_23c,CONCAT22(uStack_23e,local_240));
                plVar22 = plVar24;
                do {
                  cVar2 = *pcVar15;
                  pcVar15 = pcVar15 + 1;
                  *(char *)plVar22 = cVar2;
                  plVar22 = (longlong *)((longlong)plVar22 + 1);
                } while (cVar2 != '\0');
                *(undefined8 *)(puVar26 + -8) = 0x18002696b;
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_240);
              }
              *(undefined8 *)(puVar26 + -8) = 0x180026978;
              VariantClear((VARIANTARG *)&local_178.n2);
              param_3 = 2;
            }
          }
          else {
            local_238 = local_250;
            pcVar4 = *(code **)(*local_250 + 8);
            *(undefined8 *)(puVar26 + -8) = 0x180026988;
            (*pcVar4)();
            *(undefined8 *)(puVar26 + -8) = 0x180026994;
            iVar21 = FUN_18002a490(&local_238);
            plVar29 = local_238;
            plVar22 = local_250;
            if (iVar21 == 1) {
              pcVar4 = *(code **)(*local_238 + 8);
              *(undefined8 *)(puVar26 + -8) = 0x1800269c9;
              (*pcVar4)(plVar29);
              plVar30 = local_250;
              pcVar4 = *(code **)(*local_250 + 8);
              *(undefined8 *)(puVar26 + -8) = 0x1800269d7;
              (*pcVar4)(plVar30);
              plVar24 = plVar29;
              param_3 = local_240;
            }
            else {
              param_3 = local_240;
              if (iVar21 == 2) {
                param_3 = 2;
                pcVar4 = *(code **)(*local_250 + 8);
                *(undefined8 *)(puVar26 + -8) = 0x1800269bb;
                (*pcVar4)(plVar22);
                plVar24 = (longlong *)&DAT_1800633a4;
                plVar30 = plVar22;
              }
            }
            pcVar4 = *(code **)(*plVar29 + 0x10);
            *(undefined8 *)(puVar26 + -8) = 0x1800269e4;
            (*pcVar4)(plVar29);
          }
          pcVar4 = *(code **)(*local_250 + 0x10);
          *(undefined8 *)(puVar26 + -8) = 0x1800269ee;
          (*pcVar4)();
          pWVar28 = local_188[0];
          *(undefined8 *)(puVar26 + -8) = 0x1800269fb;
          SysFreeString(pWVar28);
          puVar27 = puVar26;
          plVar22 = plVar30;
        }
      }
      break;
    }
    if (uVar3 == 0x4009) {
LAB_1800262f8:
      puVar13 = *(ushort **)(param_4 + 4);
      goto LAB_18002645e;
    }
    if (uVar3 != 0x400c) {
      puVar27 = auStack_2b8;
      plVar22 = plVar29;
      if (uVar3 != 0x400d) break;
      goto LAB_1800262f8;
    }
    puVar23 = *(undefined8 **)(param_4 + 4);
    lVar12 = *param_1;
    uVar19 = puVar23[1];
    *(undefined8 *)param_4 = *puVar23;
    *(undefined8 *)(param_4 + 4) = uVar19;
    *(undefined8 *)(param_4 + 8) = puVar23[2];
    local_208._0_8_ = *param_11;
    local_208.decVal.u2 = *(_union_1719 *)(param_11 + 1);
    local_208._16_8_ = param_11[2];
    local_1c8._0_8_ = *param_10;
    local_1c8.decVal.u2 = *(_union_1719 *)(param_10 + 1);
    local_1c8._16_8_ = param_10[2];
    local_1e8._0_8_ = *(undefined8 *)param_9;
    local_1e8.decVal.u2 = *(_union_1719 *)(param_9 + 4);
    local_1e8._16_8_ = *(undefined8 *)(param_9 + 8);
    local_158._0_8_ = *(undefined8 *)param_8;
    local_158.decVal.u2 = *(_union_1719 *)(param_8 + 4);
    local_158._16_8_ = *(undefined8 *)(param_8 + 8);
    local_1a8._0_8_ = *(undefined8 *)param_7;
    local_1a8.decVal.u2 = *(_union_1719 *)(param_7 + 4);
    local_1a8._16_8_ = *(undefined8 *)(param_7 + 8);
    local_178._0_8_ = *param_6;
    local_178.decVal.u2 = *(_union_1719 *)(param_6 + 1);
    local_178._16_8_ = param_6[2];
    local_288[4] = &local_208;
    local_288[3] = &local_1c8;
    local_288[2] = &local_1e8;
    local_288[1] = &local_158;
    local_288[0] = &local_1a8;
    local_290 = &local_178;
    local_108._0_8_ = *(undefined8 *)param_4;
    local_108.decVal.u2 = *(_union_1719 *)(param_4 + 4);
    local_108._16_8_ = *(undefined8 *)(param_4 + 8);
    local_128._0_8_ = *(undefined8 *)&param_2->n1;
    local_128.decVal.u2 = (param_2->n1).decVal.u2;
    local_298 = param_5;
    local_128._16_8_ = *(undefined8 *)((longlong)&param_2->n1 + 0x10);
    uStack_2c0 = 0x180026453;
    uVar11 = (**(code **)(lVar12 + 0x78))(param_1,&local_128,param_3,&local_108);
    puVar23 = (undefined8 *)(ulonglong)uVar11;
    goto LAB_180026eaf;
  case 1:
  case 3:
  case 100:
    uVar3 = *param_4;
    if ((uVar3 == 9) || (uVar3 == 0xd)) {
      plVar24 = *(longlong **)(param_4 + 4);
      puVar27 = auStack_2b8;
      plVar22 = plVar29;
    }
    else {
      if (uVar3 != 0x4009) {
        if (uVar3 == 0x400c) {
LAB_180026a59:
          puVar23 = *(undefined8 **)(param_4 + 4);
          lVar12 = *param_1;
          uVar19 = puVar23[1];
          *(undefined8 *)param_4 = *puVar23;
          *(undefined8 *)(param_4 + 4) = uVar19;
          *(undefined8 *)(param_4 + 8) = puVar23[2];
          local_228._0_8_ = *param_11;
          local_228.decVal.u2 = *(_union_1719 *)(param_11 + 1);
          local_228._16_8_ = param_11[2];
          local_c8._0_8_ = *param_10;
          local_c8.decVal.u2 = *(_union_1719 *)(param_10 + 1);
          local_c8._16_8_ = param_10[2];
          local_e8._0_8_ = *(undefined8 *)param_9;
          local_e8.decVal.u2 = *(_union_1719 *)(param_9 + 4);
          local_e8._16_8_ = *(undefined8 *)(param_9 + 8);
          local_208._0_8_ = *(undefined8 *)param_8;
          local_208.decVal.u2 = *(_union_1719 *)(param_8 + 4);
          local_208._16_8_ = *(undefined8 *)(param_8 + 8);
          local_1c8._0_8_ = *(undefined8 *)param_7;
          local_1c8.decVal.u2 = *(_union_1719 *)(param_7 + 4);
          local_1c8._16_8_ = *(undefined8 *)(param_7 + 8);
          local_1e8._0_8_ = *param_6;
          local_1e8.decVal.u2 = *(_union_1719 *)(param_6 + 1);
          local_1e8._16_8_ = param_6[2];
          local_288[4] = &local_228;
          local_288[3] = &local_c8;
          local_288[2] = &local_e8;
          local_288[1] = &local_208;
          local_288[0] = &local_1c8;
          local_290 = &local_1e8;
          local_158._0_8_ = *(undefined8 *)param_4;
          local_158.decVal.u2 = *(_union_1719 *)(param_4 + 4);
          local_158._16_8_ = *(undefined8 *)(param_4 + 8);
          local_1a8._0_8_ = *(undefined8 *)&param_2->n1;
          local_1a8.decVal.u2 = (param_2->n1).decVal.u2;
          local_298 = param_5;
          local_1a8._16_8_ = *(undefined8 *)((longlong)&param_2->n1 + 0x10);
          uStack_2c0 = 0x180026ba2;
          uVar11 = (**(code **)(lVar12 + 0x78))(param_1,&local_1a8,param_3,&local_158);
          puVar23 = (undefined8 *)(ulonglong)uVar11;
          puVar26 = auStack_2b8;
          goto LAB_180026eaf;
        }
        puVar27 = auStack_2b8;
        if (uVar3 != 0x400d) break;
      }
      plVar24 = (longlong *)**(undefined8 **)(param_4 + 4);
      puVar27 = auStack_2b8;
      plVar22 = plVar29;
    }
    break;
  case 2:
  case 0x5a:
    uVar3 = *param_4;
    if (uVar3 == 8) {
      pWVar28 = *(LPCWSTR *)(param_4 + 4);
      puVar27 = auStack_2b8;
      plVar22 = plVar29;
      if (pWVar28 != (LPCWSTR)0x0) {
        lVar12 = -1;
        do {
          lVar12 = lVar12 + 1;
        } while (pWVar28[lVar12] != L'\0');
LAB_180026bcd:
        iVar21 = (int)lVar12 + 1;
        puVar27 = auStack_2b8;
        plVar22 = plVar29;
        if (iVar21 < 0x40000000) {
          lVar12 = (longlong)(int)lVar12 * 2;
          uVar20 = lVar12 + 0x11;
          if (uVar20 <= lVar12 + 2U) {
            uVar20 = 0xffffffffffffff0;
          }
          uStack_2c0 = 0x180026c05;
          lVar12 = -(uVar20 & 0xfffffffffffffff0);
          plVar24 = (longlong *)((longlong)&local_258 + lVar12);
          if (plVar24 == (longlong *)0x0) {
            plVar24 = (longlong *)0x0;
            puVar27 = auStack_2b8 + lVar12;
          }
          else {
            *(undefined8 *)((longlong)local_288 + lVar12 + 8) = 0;
            *(undefined8 *)((longlong)local_288 + lVar12) = 0;
            *(undefined1 *)plVar24 = 0;
            *(int *)((longlong)&local_290 + lVar12) = iVar21 * 2;
            *(longlong **)((longlong)&local_298 + lVar12) = plVar24;
            *(undefined8 *)(auStack_2b8 + lVar12 + -8) = 0x180026c38;
            iVar21 = WideCharToMultiByte(0,0,pWVar28,-1,*(LPSTR *)((longlong)&local_298 + lVar12),
                                         *(int *)((longlong)&local_290 + lVar12),
                                         *(LPCSTR *)((longlong)local_288 + lVar12),
                                         *(LPBOOL *)((longlong)local_288 + lVar12 + 8));
            puVar27 = auStack_2b8 + lVar12;
            if (iVar21 == 0) {
              plVar24 = plVar30;
              puVar27 = auStack_2b8 + lVar12;
            }
          }
        }
      }
    }
    else if (uVar3 == 0x4008) {
      pWVar28 = (LPCWSTR)**(longlong **)(param_4 + 4);
      puVar27 = auStack_2b8;
      plVar22 = plVar29;
      if (pWVar28 != (LPCWSTR)0x0) {
        lVar12 = -1;
        do {
          lVar12 = lVar12 + 1;
        } while (pWVar28[lVar12] != L'\0');
        goto LAB_180026bcd;
      }
    }
    else {
      puVar27 = auStack_2b8;
      plVar22 = plVar29;
      if (uVar3 == 0x400c) goto LAB_180026a59;
    }
  }
  puVar23 = (undefined8 *)0x0;
  *(undefined8 *)(puVar27 + -8) = 0x180026c84;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_90,(char *)0x0);
  *(undefined8 *)(puVar27 + -8) = 0x180026c8c;
  puVar16 = operator_new(0x60);
  puVar17 = puVar23;
  if (puVar16 != (undefined8 *)0x0) {
    *(undefined8 *)(puVar27 + 0x20) = param_5;
    *(undefined8 *)(puVar27 + -8) = 0x180026cb3;
    puVar17 = FUN_1800255c0(puVar16,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                     *)local_90,plVar24,(int)param_3,
                            *(undefined8 **)(puVar27 + 0x20));
  }
  local_228._0_8_ = *param_11;
  local_228.decVal.u2 = *(_union_1719 *)(param_11 + 1);
  local_228._16_8_ = param_11[2];
  local_c8._0_8_ = *param_10;
  local_c8.decVal.u2 = *(_union_1719 *)(param_10 + 1);
  local_c8._16_8_ = param_10[2];
  local_e8._0_8_ = *(undefined8 *)param_9;
  local_e8.decVal.u2 = *(_union_1719 *)(param_9 + 4);
  local_e8._16_8_ = *(undefined8 *)(param_9 + 8);
  local_208._0_8_ = *(undefined8 *)param_8;
  local_208.decVal.u2 = *(_union_1719 *)(param_8 + 4);
  local_208._16_8_ = *(undefined8 *)(param_8 + 8);
  local_1c8._0_8_ = *(undefined8 *)param_7;
  local_1c8.decVal.u2 = *(_union_1719 *)(param_7 + 4);
  local_1c8._16_8_ = *(undefined8 *)(param_7 + 8);
  uVar1 = *param_6;
  _Var6 = *(_union_1719 *)(param_6 + 1);
  uVar19 = param_6[2];
  *(_union_2707 **)(puVar27 + 0x30) = &local_228;
  *(_union_2707 **)(puVar27 + 0x28) = &local_c8;
  *(_union_2707 **)(puVar27 + 0x20) = &local_e8;
  local_1e8._0_8_ = uVar1;
  local_1e8.decVal.u2 = _Var6;
  local_1e8._16_8_ = uVar19;
  *(undefined8 *)(puVar27 + -8) = 0x180026d98;
  FUN_18002f850((longlong)puVar17,(short *)&local_1e8,(VARIANTARG *)&local_1c8.n2,
                (VARIANTARG *)&local_208.n2,*(VARIANTARG **)(puVar27 + 0x20),
                *(VARIANTARG **)(puVar27 + 0x28),*(VARIANTARG **)(puVar27 + 0x30));
  *(ULONG *)(puVar17 + 9) = local_230;
  *(int *)((longlong)puVar17 + 0x4c) = (int)local_258;
  *(undefined8 *)(puVar27 + -8) = 0x180026db5;
  pCVar18 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_238,
                       local_138);
  *(undefined8 *)(puVar27 + -8) = 0x180026dc2;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(puVar17 + 10),pCVar18
            );
  *(undefined8 *)(puVar27 + -8) = 0x180026dcc;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_238);
  if (plVar22 != (longlong *)0x0) {
    *(undefined8 *)(puVar27 + -8) = 0x180026ddc;
    FUN_18002f770((longlong)puVar17,plVar22);
    pcVar4 = *(code **)(*plVar22 + 0x10);
    *(undefined8 *)(puVar27 + -8) = 0x180026de6;
    (*pcVar4)(plVar22);
    if ((param_3 == 0) && (plVar24 != (longlong *)0x0)) {
      pcVar4 = *(code **)(*plVar24 + 0x10);
      *(undefined8 *)(puVar27 + -8) = 0x180026dfa;
      (*pcVar4)(plVar24);
    }
  }
  *(undefined8 *)(puVar27 + -8) = 0x180026e05;
  uVar19 = FUN_1800283a0((longlong)param_1,(longlong)puVar17);
  if ((int)uVar19 == 0) {
    lVar12 = (longlong)local_248;
    if (local_248 < 0) {
      _Var5 = param_1[0x16];
      *(undefined8 *)(puVar27 + -8) = 0x180026e3b;
      CPtrArray::SetAtGrow((CPtrArray *)(param_1 + 0x14),_Var5,puVar17);
    }
    else if (param_1[0x16] + -1 < lVar12) {
      *(undefined8 *)(puVar27 + -8) = 0x180026e67;
      CPtrArray::InsertAt((CPtrArray *)(param_1 + 0x14),lVar12,puVar17,1);
    }
    else {
      if ((lVar12 < 0) || (param_1[0x16] <= lVar12)) {
                    /* WARNING: Subroutine does not return */
        *(undefined **)(puVar27 + -8) = &UNK_180026f46;
        AfxThrowInvalidArgException();
      }
      puVar16 = *(undefined8 **)(param_1[0x15] + lVar12 * 8);
      *(undefined8 **)(param_1[0x15] + lVar12 * 8) = puVar17;
      if (puVar16 != (undefined8 *)0x0) {
        pcVar4 = *(code **)*puVar16;
        *(undefined8 *)(puVar27 + -8) = 0x180026ea0;
        (*pcVar4)(puVar16,1);
      }
    }
  }
  else {
    puVar23 = (undefined8 *)0x1;
    pcVar4 = *(code **)*puVar17;
    *(undefined8 *)(puVar27 + -8) = 0x180026e18;
    (*pcVar4)(puVar17,1);
  }
  *(undefined8 *)(puVar27 + -8) = 0x180026eaf;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_90);
  puVar26 = puVar27;
LAB_180026eaf:
  *(undefined8 *)(puVar26 + -8) = 0x180026ebc;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_138);
  *(undefined8 *)(puVar26 + -8) = 0x180026ec9;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_130);
  puVar27 = puVar26;
LAB_180026ec9:
  *(undefined8 *)(puVar27 + -8) = 0x180026ed6;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_70);
  *(undefined8 *)(puVar27 + -8) = 0x180026ee3;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_68);
  *(undefined8 *)(puVar27 + -8) = 0x180026ef0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_60);
  *(undefined8 *)(puVar27 + -8) = 0x180026efd;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_58);
  *(undefined8 *)(puVar27 + -8) = 0x180026f0a;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_50);
  *(undefined8 *)(puVar27 + -8) = 0x180026f1b;
  return puVar23;
}

/* ---- FUNC 00026FC0 FUN_180026fc0 (9 bytes) ---- */

void FUN_180026fc0(longlong param_1)

{
  *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 1;
  return;
}

/* ---- FUNC 00026FD0 FUN_180026fd0 (6 bytes) ---- */

undefined8 FUN_180026fd0(void)

{
  return 1;
}

/* ---- FUNC 00026FE0 FUN_180026fe0 (16 bytes) ---- */

void FUN_180026fe0(longlong param_1)

{
  *(undefined1 *)(param_1 + 0x160) = 1;
  FUN_180042530(param_1 + 0x18);
  return;
}

/* ---- FUNC 00026FF0 FUN_180026ff0 (295 bytes) ---- */

ulonglong FUN_180026ff0(longlong param_1,wchar_t *param_2,void **param_3)

{
  LPBC *ppbc;
  uint uVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar4;
  wchar_t *szUserName;
  ULONG local_res8 [2];
  wchar_t *local_res20;
  IMoniker *local_38;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_30 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_28 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_20 [8];
  
  ppbc = (LPBC *)(param_1 + 8);
  if (*ppbc == (LPBC)0x0) {
    CreateBindCtx(0,ppbc);
  }
  uVar2 = (**(code **)(**(longlong **)(DAT_1800797f0 + 0x118) + 0xa0))
                    (*(longlong **)(DAT_1800797f0 + 0x118),*ppbc,0,&local_res20);
  if (-1 < (int)uVar2) {
    puVar3 = (undefined8 *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_20,param_2);
    pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_28,local_res20);
    FUN_180003af0(local_30,pCVar4,puVar3);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_28);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_20);
    CoTaskMemFree(local_res20);
    szUserName = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::AllocSysString
                           (local_30);
    uVar1 = MkParseDisplayName(*ppbc,szUserName,local_res8,&local_38);
    SysFreeString(szUserName);
    if (-1 < (int)uVar1) {
      uVar1 = (*local_38->lpVtbl->BindToObject)
                        (local_38,*ppbc,(IMoniker *)0x0,(IID *)&DAT_180063400,param_3);
      (*local_38->lpVtbl->Release)(local_38);
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_30);
    uVar2 = (ulonglong)uVar1;
  }
  return uVar2;
}

/* ---- FUNC 00027120 FUN_180027120 (50 bytes) ---- */

undefined8 FUN_180027120(longlong *param_1,undefined2 *param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  longlong *plVar4;
  int local_res10 [2];
  
  if (param_2 == (undefined2 *)0x0) {
    return 0x80070057;
  }
  *param_2 = 0xffff;
  local_res10[0] = 0;
  (**(code **)(*param_1 + 0x48))(param_1,local_res10);
  if (local_res10[0] < 2) {
FUN_1800271db:
    *param_2 = 0;
    return 0;
  }
  if (0 < param_1[0x16]) {
    plVar4 = (longlong *)param_1[0x15];
    lVar1 = *plVar4;
    if (*(longlong **)(lVar1 + 0x38) == (longlong *)0x0) goto FUN_1800271db;
    iVar3 = 1;
    if (local_res10[0] < 2) {
      return 0;
    }
    lVar2 = 1;
    while ((plVar4 = plVar4 + 1, -1 < lVar2 && (lVar2 < param_1[0x16]))) {
      if ((*(longlong **)(*plVar4 + 0x38) == (longlong *)0x0) ||
         (**(longlong **)(lVar1 + 0x38) != **(longlong **)(*plVar4 + 0x38))) goto FUN_1800271db;
      iVar3 = iVar3 + 1;
      lVar2 = lVar2 + 1;
      if (local_res10[0] <= iVar3) {
        return 0;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00027152 FUN_180027152 (137 bytes) ---- */

undefined8 FUN_180027152(void)

{
  longlong lVar1;
  longlong in_RAX;
  longlong lVar2;
  int iVar3;
  longlong unaff_RBX;
  undefined2 *unaff_RDI;
  longlong *plVar4;
  int iStack0000000000000038;
  
  iStack0000000000000038 = 0;
  (**(code **)(in_RAX + 0x48))();
  if (iStack0000000000000038 < 2) {
FUN_1800271db:
    *unaff_RDI = 0;
    return 0;
  }
  if (0 < *(longlong *)(unaff_RBX + 0xb0)) {
    plVar4 = *(longlong **)(unaff_RBX + 0xa8);
    lVar1 = *plVar4;
    if (*(longlong **)(lVar1 + 0x38) == (longlong *)0x0) goto FUN_1800271db;
    iVar3 = 1;
    if (iStack0000000000000038 < 2) {
      return 0;
    }
    lVar2 = 1;
    while ((plVar4 = plVar4 + 1, -1 < lVar2 && (lVar2 < *(longlong *)(unaff_RBX + 0xb0)))) {
      if ((*(longlong **)(*plVar4 + 0x38) == (longlong *)0x0) ||
         (**(longlong **)(lVar1 + 0x38) != **(longlong **)(*plVar4 + 0x38))) goto FUN_1800271db;
      iVar3 = iVar3 + 1;
      lVar2 = lVar2 + 1;
      if (iStack0000000000000038 <= iVar3) {
        return 0;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 000271DB FUN_1800271db (21 bytes) ---- */

undefined8 FUN_1800271db(void)

{
  undefined2 unaff_SI;
  undefined2 *unaff_RDI;
  
  *unaff_RDI = unaff_SI;
  return 0;
}

/* ---- FUNC 000271F0 AfxThrowInvalidArgException (5 bytes) ---- */

void __cdecl AfxThrowInvalidArgException(void)

{
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00027200 FUN_180027200 (172 bytes) ---- */

undefined8 FUN_180027200(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  int iVar6;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (lVar1 == 0) {
    if (*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x28) == param_2) {
      return 1;
    }
  }
  else {
    iVar6 = 0;
    if (0 < lVar1) {
      lVar5 = 0;
      while ((-1 < lVar5 && (lVar5 < lVar1))) {
        lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + lVar5 * 8);
        uVar4 = 0;
        uVar3 = *(ulonglong *)(lVar2 + 0x10);
        if (uVar3 != 0) {
          do {
            if (((longlong)uVar4 < 0) || ((longlong)uVar3 <= (longlong)uVar4)) goto LAB_1800272a7;
            if (*(longlong *)(*(longlong *)(lVar2 + 8) + uVar4 * 8) == param_2) {
              return 1;
            }
            uVar4 = uVar4 + 1;
          } while (uVar4 < uVar3);
        }
        iVar6 = iVar6 + 1;
        lVar5 = lVar5 + 1;
        if (lVar1 <= iVar6) {
          return 0;
        }
      }
LAB_1800272a7:
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
  }
  return 0;
}

/* ---- FUNC 000272B0 FUN_1800272b0 (33 bytes) ---- */

undefined8 FUN_1800272b0(longlong param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  
  if (*(int *)(param_1 + 0x10) != 0) {
    return 1;
  }
  lVar2 = *(longlong *)(param_1 + 0xb0);
  uVar4 = 0;
  uVar3 = uVar4;
  uVar6 = uVar4;
  if (0 < lVar2) {
    do {
      if (((longlong)uVar3 < 0) || (lVar2 <= (longlong)uVar3))
      goto MFC140_DLL_AfxThrowInvalidArgException;
      puVar1 = *(undefined8 **)(*(longlong *)(param_1 + 0xa8) + uVar3 * 8);
      if (puVar1 != (undefined8 *)0x0) {
        (**(code **)*puVar1)();
      }
      lVar2 = *(longlong *)(param_1 + 0xb0);
      uVar5 = (int)uVar6 + 1;
      uVar3 = uVar3 + 1;
      uVar6 = (ulonglong)uVar5;
    } while ((int)uVar5 < lVar2);
  }
  CPtrArray::SetSize((CPtrArray *)(param_1 + 0xa0),0,-1);
  lVar2 = *(longlong *)(param_1 + 0xd8);
  uVar3 = uVar4;
  if (0 < lVar2) {
    do {
      if (((longlong)uVar4 < 0) || (lVar2 <= (longlong)uVar4)) {
MFC140_DLL_AfxThrowInvalidArgException:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      (**(code **)(**(longlong **)(*(longlong *)(param_1 + 0xd0) + uVar4 * 8) + 0x10))();
      lVar2 = *(longlong *)(param_1 + 0xd8);
      uVar5 = (int)uVar3 + 1;
      uVar4 = uVar4 + 1;
      uVar3 = (ulonglong)uVar5;
    } while ((int)uVar5 < lVar2);
  }
  CPtrArray::SetSize((CPtrArray *)(param_1 + 200),0,-1);
  return 0;
}

/* ---- FUNC 000272D1 FUN_1800272d1 (216 bytes) ---- */

undefined8 FUN_1800272d1(longlong param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong unaff_RDI;
  
  uVar4 = 0;
  uVar3 = uVar4;
  uVar6 = uVar4;
  if (0 < param_1) {
    do {
      if (((longlong)uVar3 < 0) || (param_1 <= (longlong)uVar3))
      goto MFC140_DLL_AfxThrowInvalidArgException;
      puVar1 = *(undefined8 **)(*(longlong *)(unaff_RDI + 0xa8) + uVar3 * 8);
      if (puVar1 != (undefined8 *)0x0) {
        (**(code **)*puVar1)();
      }
      param_1 = *(longlong *)(unaff_RDI + 0xb0);
      uVar5 = (int)uVar6 + 1;
      uVar3 = uVar3 + 1;
      uVar6 = (ulonglong)uVar5;
    } while ((int)uVar5 < param_1);
  }
  CPtrArray::SetSize((CPtrArray *)(unaff_RDI + 0xa0),0,-1);
  lVar2 = *(longlong *)(unaff_RDI + 0xd8);
  uVar3 = uVar4;
  if (0 < lVar2) {
    do {
      if (((longlong)uVar4 < 0) || (lVar2 <= (longlong)uVar4)) {
MFC140_DLL_AfxThrowInvalidArgException:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      (**(code **)(**(longlong **)(*(longlong *)(unaff_RDI + 0xd0) + uVar4 * 8) + 0x10))();
      lVar2 = *(longlong *)(unaff_RDI + 0xd8);
      uVar5 = (int)uVar3 + 1;
      uVar4 = uVar4 + 1;
      uVar3 = (ulonglong)uVar5;
    } while ((int)uVar5 < lVar2);
  }
  CPtrArray::SetSize((CPtrArray *)(unaff_RDI + 200),0,-1);
  return 0;
}

/* ---- FUNC 000273A9 AfxThrowInvalidArgException (5 bytes) ---- */

void __cdecl AfxThrowInvalidArgException(void)

{
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 000273B0 FUN_1800273b0 (94 bytes) ---- */

void FUN_1800273b0(longlong param_1)

{
  uint uVar1;
  longlong *_Memory;
  
  _Memory = *(longlong **)(param_1 + 0x28);
  if (_Memory == (longlong *)0x0) goto LAB_1800273e7;
  uVar1 = *(uint *)(param_1 + 0x30);
  if ((1 < uVar1) && (2 < uVar1 - 0x60)) {
    if ((uVar1 == 2) || (uVar1 == 0x5a)) {
      free(_Memory);
      goto LAB_1800273e7;
    }
    if (uVar1 != 3) goto LAB_1800273e7;
  }
  (**(code **)(*_Memory + 0x10))();
LAB_1800273e7:
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0xffffffff;
                    /* WARNING: Could not recover jumptable at 0x0001800273ff. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CSimpleStringT<char,1>::Empty((CSimpleStringT<char,1> *)(param_1 + 0x18));
  return;
}

/* ---- FUNC 00027410 FUN_180027410 (205 bytes) ---- */

undefined8 FUN_180027410(longlong param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  longlong *plVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong *local_res8;
  
  uVar3 = 0;
  local_res8 = (longlong *)0x0;
  if (param_2 != (undefined8 *)0x0) {
    (**(code **)*param_2)(param_2,&DAT_180066c58,&local_res8);
  }
  uVar4 = *(ulonglong *)(param_1 + 0xb0);
  plVar2 = local_res8;
  if (uVar4 != 0) {
    do {
      if (((longlong)uVar3 < 0) || (*(longlong *)(param_1 + 0xb0) <= (longlong)uVar3)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      puVar1 = *(undefined8 **)(*(longlong *)(param_1 + 0xa8) + uVar3 * 8);
      if ((puVar1 != (undefined8 *)0x0) && ((longlong *)puVar1[8] == plVar2)) {
        CPtrArray::RemoveAt((CPtrArray *)(param_1 + 0xa0),uVar3,1);
        (**(code **)*puVar1)(puVar1,1);
        uVar4 = uVar4 - 1;
        uVar3 = uVar3 - 1;
        plVar2 = local_res8;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar4);
  }
  if (plVar2 != (longlong *)0x0) {
    (**(code **)(*plVar2 + 0x10))();
  }
  return 0;
}

/* ---- FUNC 000274E0 FUN_1800274e0 (91 bytes) ---- */

undefined8 * FUN_1800274e0(undefined8 *param_1)

{
  undefined8 *puVar1;
  
  puVar1 = operator_new(0x20);
  if (puVar1 == (undefined8 *)0x0) {
    puVar1 = (undefined8 *)0x0;
  }
  else {
    puVar1 = FUN_180025710(puVar1);
  }
  *puVar1 = *param_1;
  *(undefined4 *)(puVar1 + 1) = *(undefined4 *)(param_1 + 1);
  *(undefined4 *)((longlong)puVar1 + 0xc) = *(undefined4 *)((longlong)param_1 + 0xc);
  *(undefined2 *)(puVar1 + 2) = *(undefined2 *)(param_1 + 2);
  *(undefined4 *)((longlong)puVar1 + 0x14) = *(undefined4 *)((longlong)param_1 + 0x14);
  *(undefined4 *)(puVar1 + 3) = *(undefined4 *)(param_1 + 3);
  return puVar1;
}

/* ---- FUNC 00027540 FUN_180027540 (10 bytes) ---- */

void FUN_180027540(longlong *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180027543. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x80))();
  return;
}

/* ---- FUNC 00027550 FUN_180027550 (84 bytes) ---- */

void FUN_180027550(longlong param_1)

{
  if ((*(int *)(param_1 + 0x60) != 0) && (*(longlong **)(param_1 + 0x68) != (longlong *)0x0)) {
    (**(code **)(**(longlong **)(param_1 + 0x68) + 0x50))();
    *(undefined4 *)(param_1 + 0x60) = 0;
  }
  if (*(longlong **)(param_1 + 0x68) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0x68) + 0x10))();
    *(undefined8 *)(param_1 + 0x68) = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x00018002759d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x18),"");
  return;
}

/* ---- FUNC 000275B0 FUN_1800275b0 (537 bytes) ---- */

void FUN_1800275b0(longlong param_1)

{
  ulonglong uVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  int iVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong *local_res8;
  
  uVar6 = 0;
  if (*(longlong *)(*(longlong *)(param_1 + 8) + 0xa0) == param_1) {
    *(undefined8 *)(*(longlong *)(param_1 + 8) + 0xa0) = 0;
  }
  FUN_180042810(param_1 + 0x18);
  uVar1 = *(ulonglong *)(param_1 + 0x120);
  uVar5 = uVar6;
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar5 < 0) || (*(longlong *)(param_1 + 0x120) <= (longlong)uVar5)) {
LAB_1800277c4:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar2 = *(longlong **)(*(longlong *)(param_1 + 0x118) + uVar5 * 8);
      local_res8 = (longlong *)0x0;
      if (*(longlong *)(param_1 + 0x148) <= (longlong)uVar5) goto LAB_1800277c4;
      if ((*(int *)(*(longlong *)(param_1 + 0x140) + uVar5 * 4) != 0) &&
         (iVar4 = (**(code **)*plVar2)(plVar2,&DAT_180066d58,&local_res8), -1 < iVar4)) {
        if (*(longlong *)(param_1 + 0x148) <= (longlong)uVar5) goto LAB_1800277c4;
        (**(code **)(*local_res8 + 0x50))();
        (**(code **)(*local_res8 + 0x10))();
      }
      (**(code **)(*plVar2 + 0x10))(plVar2);
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
  }
  CPtrArray::SetSize((CPtrArray *)(param_1 + 0x110),0,-1);
  CDWordArray::SetSize((CDWordArray *)(param_1 + 0x138),0,-1);
  uVar1 = *(ulonglong *)(param_1 + 0x60);
  uVar5 = uVar6;
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar5 < 0) || (*(longlong *)(param_1 + 0x60) <= (longlong)uVar5))
      goto LAB_1800277be;
      puVar3 = *(undefined8 **)(*(longlong *)(param_1 + 0x58) + uVar5 * 8);
      if (puVar3 != (undefined8 *)0x0) {
        (**(code **)*puVar3)();
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
  }
  CPtrArray::SetSize((CPtrArray *)(param_1 + 0x50),0,-1);
  uVar1 = *(ulonglong *)(param_1 + 0x88);
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar6 < 0) || (*(longlong *)(param_1 + 0x88) <= (longlong)uVar6)) {
LAB_1800277be:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      (**(code **)(**(longlong **)(*(longlong *)(param_1 + 0x80) + uVar6 * 8) + 0x10))();
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar1);
  }
  CPtrArray::SetSize((CPtrArray *)(param_1 + 0x78),0,-1);
  if (((*(int *)(param_1 + 0xa0) != 0) &&
      (puVar3 = *(undefined8 **)(param_1 + 8), puVar3 != (undefined8 *)0x0)) &&
     (iVar4 = (**(code **)*puVar3)(puVar3,&DAT_180066db8,&local_res8), -1 < iVar4)) {
    (**(code **)(*local_res8 + 0xa0))(local_res8,*(undefined4 *)(param_1 + 0xa0));
    (**(code **)(*local_res8 + 0x10))();
    *(undefined4 *)(param_1 + 0xa0) = 0;
  }
  return;
}

/* ---- FUNC 000277D0 FUN_1800277d0 (108 bytes) ---- */

ulonglong FUN_1800277d0(longlong param_1)

{
  int iVar1;
  longlong *plVar2;
  ulonglong uVar3;
  
  if (*(longlong *)(param_1 + 0xb0) == 0) {
    return 1;
  }
  uVar3 = 0x80004005;
  iVar1 = GetDefaultCopyContent();
  if (iVar1 != 0) {
    plVar2 = FUN_180027ae0(param_1);
    DAT_180079208 = GetDefaultCopyContent();
    if (plVar2 != (longlong *)0x0) {
      uVar3 = FUN_180027840((longlong)plVar2);
      uVar3 = uVar3 & 0xffffffff;
      (**(code **)(*plVar2 + 0x10))(plVar2);
    }
  }
  return uVar3;
}

/* ---- FUNC 00027840 FUN_180027840 (85 bytes) ---- */

undefined8 FUN_180027840(longlong param_1)

{
  int iVar1;
  LPDATAOBJECT local_res8 [4];
  
  local_res8[0] = (LPDATAOBJECT)0x0;
  iVar1 = (**(code **)(*(longlong *)(param_1 + 0x18) + 0x10))
                    (param_1 + 0x18,DAT_180079208,local_res8);
  if (-1 < iVar1) {
    OleSetClipboard(local_res8[0]);
    (*local_res8[0]->lpVtbl->Release)(local_res8[0]);
    *(longlong *)(*(longlong *)(param_1 + 8) + 0xa0) = param_1;
  }
  return 0;
}

/* ---- FUNC 000278A0 FUN_1800278a0 (156 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_1800278a0(longlong param_1)

{
  HWND hWndParent;
  INT_PTR IVar1;
  longlong *plVar2;
  ulonglong uVar3;
  
  if (*(longlong *)(param_1 + 0xb0) == 0) {
    return 1;
  }
  uVar3 = 0x80004005;
  _DAT_180079204 = 0xffff;
  hWndParent = GetActiveWindow();
  IVar1 = DialogBoxParamA(DAT_1800797d8,(LPCSTR)0x65,hWndParent,FUN_1800038d0,0);
  if ((IVar1 == 1) && (DAT_180079208 != 0)) {
    plVar2 = FUN_180027ae0(param_1);
    if (plVar2 != (longlong *)0x0) {
      uVar3 = FUN_180027840((longlong)plVar2);
      uVar3 = uVar3 & 0xffffffff;
      (**(code **)(*plVar2 + 0x10))(plVar2);
    }
  }
  return uVar3;
}

/* ---- FUNC 00027940 FUN_180027940 (177 bytes) ---- */

HRESULT FUN_180027940(undefined8 *param_1,longlong *param_2,
                     CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                     *param_3)

{
  HRESULT HVar1;
  undefined8 *puVar2;
  
  puVar2 = operator_new(0xf0);
  if (puVar2 == (undefined8 *)0x0) {
    puVar2 = (undefined8 *)0x0;
  }
  else {
    puVar2 = FUN_180025300(puVar2);
  }
  HVar1 = FUN_180033ad0(puVar2 + 3,(GUID *)&DAT_180063430);
  if (HVar1 < 0) {
    if (puVar2 != (undefined8 *)0x0) {
      FUN_180025730(puVar2);
      FUN_180025ad0(puVar2);
    }
    *param_1 = 0;
  }
  else {
    puVar2[0x12] = param_2;
    (**(code **)(*param_2 + 8))(param_2);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(puVar2 + 0x13),
               param_3);
    *param_1 = puVar2;
    HVar1 = 0;
  }
  return HVar1;
}

/* ---- FUNC 00027A00 FUN_180027a00 (212 bytes) ---- */

longlong * FUN_180027a00(longlong param_1)

{
  longlong *plVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  
  puVar2 = operator_new(0x100);
  plVar5 = (longlong *)0x0;
  plVar3 = plVar5;
  if (puVar2 != (undefined8 *)0x0) {
    plVar3 = FUN_180025390(puVar2);
  }
  if (plVar3 != (longlong *)0x0) {
    (**(code **)(*plVar3 + 8))(plVar3);
    if (param_1 != 0) {
      plVar1 = *(longlong **)(param_1 + 0x90);
      plVar3[2] = (longlong)plVar1;
      (**(code **)(*plVar1 + 8))();
      if (*(longlong *)(param_1 + 0xb0) < 1) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      puVar2 = (undefined8 *)**(undefined8 **)(param_1 + 0xa8);
    }
    if (puVar2 != (undefined8 *)0x0) {
      puVar4 = operator_new(0x60);
      if (puVar4 != (undefined8 *)0x0) {
        plVar5 = FUN_1800256a0(puVar4);
      }
      plVar3[5] = (longlong)plVar5;
      FUN_180025ae0((longlong)plVar5,(longlong)puVar2);
    }
    return plVar3;
  }
  return (longlong *)0x0;
}

/* ---- FUNC 00027AE0 FUN_180027ae0 (1365 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong * FUN_180027ae0(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  longlong *plVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  undefined1 auStack_548 [32];
  BSTR *local_528;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_518 [8];
  longlong *local_510;
  _union_2707 local_508;
  wchar_t *local_4f0;
  BSTR local_4e8;
  wchar_t *local_4e0;
  undefined8 *local_4d8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_4d0 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_4c8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_4c0 [8];
  longlong *local_4b8;
  _union_2707 local_4b0;
  _union_2707 local_498;
  _union_2707 local_480;
  longlong *local_468;
  undefined8 local_460 [3];
  undefined4 local_448;
  ULONG UStack_444;
  undefined4 uStack_440;
  ULONG UStack_43c;
  code *local_438;
  undefined1 local_428 [1008];
  ulonglong local_38;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStack_548;
  plVar12 = (longlong *)0x0;
  local_480._0_8_ = 0;
  local_480.decVal.u2 = (_union_1719)0x0;
  local_480._16_8_ = 0;
  VariantInit((VARIANTARG *)&local_480.n2);
  local_498._0_8_ = 0;
  local_498.decVal.u2 = (_union_1719)0x0;
  local_498._16_8_ = 0;
  VariantInit((VARIANTARG *)&local_498.n2);
  local_4b0._0_8_ = 0;
  local_4b0.decVal.u2 = (_union_1719)0x0;
  local_4b0._16_8_ = 0;
  VariantInit((VARIANTARG *)&local_4b0.n2);
  local_4d8 = operator_new(0x168);
  plVar4 = plVar12;
  if (local_4d8 != (undefined8 *)0x0) {
    plVar4 = FUN_180025480(local_4d8);
  }
  if (plVar4 != (longlong *)0x0) {
    (**(code **)(*plVar4 + 8))(plVar4);
    plVar10 = *(longlong **)(param_1 + 0x90);
    plVar4[1] = (longlong)plVar10;
    (**(code **)(*plVar10 + 8))();
    FUN_1800255a0(local_460);
    plVar10 = *(longlong **)(param_1 + 0xb0);
    plVar11 = plVar12;
    local_4b8 = plVar10;
    if (plVar10 != (longlong *)0x0) {
      do {
        plVar5 = operator_new(0x60);
        plVar9 = plVar12;
        local_468 = plVar5;
        if (plVar5 != (longlong *)0x0) {
          *plVar5 = (longlong)CSelectEntry::vftable;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(plVar5 + 2));
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(plVar5 + 3));
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(plVar5 + 4));
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(plVar5 + 10))
          ;
          plVar5[5] = 0;
          *(undefined4 *)(plVar5 + 6) = 0xffffffff;
          plVar5[7] = 0;
          plVar5[8] = 0;
          plVar5[9] = 0;
          plVar5[0xb] = 0;
          *(undefined4 *)(plVar5 + 1) = 0;
          plVar9 = plVar5;
        }
        if (((longlong)plVar11 < 0) || (*(longlong *)(param_1 + 0xb0) <= (longlong)plVar11))
        goto LAB_180028030;
        FUN_180025ae0((longlong)plVar9,
                      *(longlong *)(*(longlong *)(param_1 + 0xa8) + (longlong)plVar11 * 8));
        iVar2 = (int)plVar9[6];
        if ((iVar2 != 0) && (((1 < iVar2 - 2U && (2 < iVar2 - 0x60U)) && (iVar2 != 0x5a)))) {
          FUN_180002a20(local_428,"Assert failed in file %s line %d",
                        "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\HappSel.cpp",0x736);
          LogMessage(local_428);
        }
        iVar2 = (int)plVar9[6];
        if (iVar2 == 3) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    (local_518,
                     (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     (plVar9 + 3));
          local_510 = (longlong *)0x0;
          iVar2 = (**(code **)(*(longlong *)plVar9[5] + 200))((longlong *)plVar9[5],&local_510);
          if ((-1 < iVar2) &&
             (iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                                (local_518,'x',0), iVar2 != -1)) {
            puVar6 = (undefined8 *)
                     ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                               (local_518,(int)local_4d0);
            iVar2 = atoi((char *)*puVar6);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_4d0);
            puVar6 = (undefined8 *)
                     ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                               (local_518,(int)local_4c8);
            iVar3 = atoi((char *)*puVar6);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_4c8);
            local_508._0_8_ = 0;
            local_508.decVal.u2.Lo64 = (_union_1719)0x0;
            local_508._16_8_ = (code *)0x0;
            VariantInit((VARIANTARG *)&local_508.n2);
            local_4e8 = (BSTR)0x0;
            local_448 = local_508._0_4_;
            UStack_444 = local_508.decVal.Hi32;
            uStack_440 = local_508._8_4_;
            UStack_43c = local_508._12_4_;
            local_438 = (code *)local_508._16_8_;
            local_528 = &local_4e8;
            iVar2 = (**(code **)(*local_510 + 0x80))(local_510,iVar2,iVar3,&local_448);
            if ((-1 < iVar2) &&
               (uVar7 = FUN_180029ab0(DAT_180079590,plVar9[5],&local_4f0), -1 < (int)uVar7)) {
              pCVar8 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                       ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                       CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                 (local_4c0,local_4f0);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         (plVar9 + 2),pCVar8);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_4c0);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         (plVar9 + 2),"!@LABEL");
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         (plVar9 + 2),(CSimpleStringT<char,1> *)local_518);
              CoTaskMemFree(local_4f0);
            }
            SysFreeString(local_4e8);
            VariantClear((VARIANTARG *)&local_508.n2);
            plVar10 = local_4b8;
          }
          if (local_510 != (longlong *)0x0) {
            (**(code **)(*local_510 + 0x10))();
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_518);
LAB_180027f13:
          CPtrArray::SetAtGrow((CPtrArray *)(plVar4 + 10),plVar4[0xc],plVar9);
        }
        else {
          if ((iVar2 != 0) && (2 < iVar2 - 0x60U)) goto LAB_180027f13;
          local_508._0_8_ = 0;
          local_508.decVal.u2.Lo64 = (_union_1719)0x0;
          local_508._16_8_ = (code *)0x0;
          lVar1 = plVar9[5];
          puVar6 = (undefined8 *)HAGetAttr(*(undefined8 *)(lVar1 + 0x48),0x1b,0,&local_508);
          if (puVar6 == (undefined8 *)0x0) {
            if ((local_508.decVal.u2.Lo64 != 0) && (*(int *)local_508.decVal.u2 != 0)) {
              *(undefined4 *)(plVar9 + 1) = 1;
            }
            if ((code *)local_508._16_8_ != (code *)0x0) {
              (*(code *)local_508._16_8_)();
            }
          }
          else if ((code *)*puVar6 != (code *)0x0) {
            (*(code *)*puVar6)(puVar6);
          }
          uVar7 = FUN_180029ab0(DAT_180079590,lVar1,&local_4e0);
          if (-1 < (int)uVar7) {
            pCVar8 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                     CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                               ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                &local_4d8,local_4e0);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(plVar9 + 2)
                       ,pCVar8);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4d8);
            CoTaskMemFree(local_4e0);
            goto LAB_180027f13;
          }
          (**(code **)*plVar9)(plVar9,1);
        }
        plVar11 = (longlong *)((longlong)plVar11 + 1);
      } while (plVar11 < plVar10);
    }
    if (plVar4[0xc] == 0) {
      (**(code **)(*plVar4 + 0x10))(plVar4);
      plVar4 = plVar12;
    }
    else {
      plVar10 = *(longlong **)(param_1 + 0xd8);
      CPtrArray::SetSize((CPtrArray *)(plVar4 + 0xf),(__int64)plVar10,-1);
      if (plVar10 != (longlong *)0x0) {
        do {
          if (((longlong)plVar12 < 0) || (*(longlong *)(param_1 + 0xd8) <= (longlong)plVar12)) {
LAB_180028030:
                    /* WARNING: Subroutine does not return */
            AfxThrowInvalidArgException();
          }
          plVar11 = *(longlong **)(*(longlong *)(param_1 + 0xd0) + (longlong)plVar12 * 8);
          (**(code **)(*plVar11 + 8))(plVar11);
          if (plVar4[0x11] <= (longlong)plVar12) goto LAB_180028030;
          *(longlong **)(plVar4[0x10] + (longlong)plVar12 * 8) = plVar11;
          plVar12 = (longlong *)((longlong)plVar12 + 1);
        } while (plVar12 < plVar10);
      }
      FUN_18002fca0((longlong)plVar4);
      FUN_18002f9f0((longlong)plVar4);
    }
    FUN_180025a20(local_460);
    plVar12 = plVar4;
  }
  VariantClear((VARIANTARG *)&local_4b0.n2);
  VariantClear((VARIANTARG *)&local_498.n2);
  VariantClear((VARIANTARG *)&local_480.n2);
  return plVar12;
}

/* ---- FUNC 00028040 FUN_180028040 (580 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180028040(void *param_1)

{
  ulonglong uVar1;
  UINT UVar2;
  int iVar3;
  ulonglong uVar4;
  undefined1 auStack_468 [32];
  undefined2 local_448 [4];
  undefined8 local_440;
  undefined4 local_438;
  undefined4 local_434;
  undefined4 local_430;
  STGMEDIUM local_428;
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_180077818 ^ (ulonglong)auStack_468;
  if (*(int *)((longlong)param_1 + 8) != 4) {
    FUN_180002a20(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\HappSel.cpp",0x1128);
    LogMessage(local_408,2,1);
  }
  if (*(longlong *)((longlong)param_1 + 0x68) == 0) {
    FUN_180002a20(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\HappSel.cpp",0x1129);
    LogMessage(local_408,2,1);
  }
  if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4)
       < DAT_1800795c8) && (FUN_18005c974(&DAT_1800795c8), DAT_1800795c8 == -1)) {
    CPtrArray::CPtrArray((CPtrArray *)&DAT_1800795a0);
    atexit((_func_5014 *)&LAB_180060400);
    _Init_thread_footer(&DAT_1800795c8);
  }
  if (DAT_18007959c == 0) {
    DAT_18007959c = 1;
    UVar2 = RegisterClipboardFormatA("Grid Text");
    local_438 = 1;
    local_440 = 0;
    local_430 = 1;
    local_434 = 0xffffffff;
    local_448[0] = (short)UVar2;
    if (*(int *)((longlong)param_1 + 0x80) == 0) {
      local_448[0] = 1;
    }
    iVar3 = (**(code **)(**(longlong **)((longlong)param_1 + 0x68) + 0x18))
                      (*(longlong **)((longlong)param_1 + 0x68),local_448,&local_428);
    if (-1 < iVar3) {
      FUN_18003e370(-1);
      if (local_428.u.hBitmap != (HBITMAP)0x0) {
        DAT_180079898 = 1;
        FUN_18002c9d0((longlong)param_1,local_428.u.hGlobal,1);
        DAT_180079898 = 0;
      }
      ReleaseStgMedium(&local_428);
      FUN_18003e370(0);
    }
    uVar1 = DAT_1800795b0;
    uVar4 = 0;
    if (DAT_1800795b0 != 0) {
      do {
        if (((longlong)uVar4 < 0) || ((longlong)DAT_1800795b0 <= (longlong)uVar4)) {
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        (**(code **)(*DAT_180079800 + 0xf0))();
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar1);
    }
    CPtrArray::SetSize((CPtrArray *)&DAT_1800795a0,0,-1);
    DAT_18007959c = 0;
  }
  else {
    CPtrArray::SetAtGrow((CPtrArray *)&DAT_1800795a0,DAT_1800795b0,param_1);
  }
  return;
}

/* ---- FUNC 00028290 FUN_180028290 (258 bytes) ---- */

void FUN_180028290(longlong param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  wchar_t *bstrString;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong *local_res8;
  undefined8 local_28 [2];
  
  FUN_1800255a0(local_28);
  uVar4 = 0;
  uVar1 = *(ulonglong *)(param_1 + 0x60);
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar4 < 0) || (*(longlong *)(param_1 + 0x60) <= (longlong)uVar4)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x58) + uVar4 * 8);
      if ((*(int *)(lVar2 + 0x30) == 0) && (*(int *)(lVar2 + 8) != 0)) {
        FUN_18002f560(lVar2,(longlong *)0x0,4,(char *)0x0);
      }
      if (*(int *)(lVar2 + 0x30) == 4) {
        bstrString = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                     AllocSysString((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
                                    )(lVar2 + 0x10));
        uVar3 = FUN_180026ff0(DAT_180079590,bstrString,&local_res8);
        if (-1 < (int)uVar3) {
          FUN_18002f560(lVar2,local_res8,0,(char *)0x0);
        }
        SysFreeString(bstrString);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  (*(code *)**(undefined8 **)(param_1 + 0x18))((undefined8 *)(param_1 + 0x18),0,1);
  (**(code **)(*DAT_180079800 + 0xe8))(DAT_180079800,0,param_1);
  FUN_180025a20(local_28);
  return;
}

/* ---- FUNC 000283A0 FUN_1800283a0 (120 bytes) ---- */

undefined8 FUN_1800283a0(longlong param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  lVar1 = *(longlong *)(param_1 + 0xb0);
  lVar3 = 0;
  if (0 < lVar1) {
    do {
      if ((lVar3 < 0) || (*(longlong *)(param_1 + 0xb0) <= lVar3)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      uVar2 = FUN_180025b90(*(longlong *)(*(longlong *)(param_1 + 0xa8) + lVar3 * 8),param_2);
      if ((char)uVar2 != '\0') {
        return 1;
      }
      lVar3 = lVar3 + 1;
    } while (lVar3 < lVar1);
  }
  return 0;
}

/* ---- FUNC 00028420 FUN_180028420 (874 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180028420(longlong param_1)

{
  LPVOID *ppvObj;
  uint uVar1;
  UINT UVar2;
  ulonglong uVar3;
  BSTR pOVar4;
  undefined1 auStackY_4a8 [32];
  LPMONIKER local_468;
  IBindCtx *local_460;
  LPCSTR local_458;
  ULONG local_450 [2];
  tagFORMATETC local_448;
  undefined1 local_428 [1008];
  ulonglong local_38;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStackY_4a8;
  if (*(int *)(param_1 + 8) != 0x10) {
    FUN_180002a20(local_428,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\HappSel.cpp",0x1409);
    LogMessage(local_428,2,1);
  }
  if (*(int *)(*(longlong *)(param_1 + 0x18) + -0x10) == 0) {
    FUN_180002a20(local_428,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\HappSel.cpp",0x140a);
    LogMessage(local_428,2,1);
  }
  CreateBindCtx(0,&local_460);
  local_468 = (IMoniker *)0x0;
  if (**(LPCSTR *)(param_1 + 0x18) == '~') {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_458);
    uVar3 = FUN_180029930(param_1,(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                  &local_458);
    if ((int)uVar3 < 0) {
      (*local_460->lpVtbl->Release)(local_460);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_458);
      return uVar3 & 0xffffffff;
    }
    pOVar4 = FUN_1800019d0(local_458);
    uVar1 = MkParseDisplayName(local_460,pOVar4,local_450,&local_468);
    SysFreeString(pOVar4);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_458);
  }
  else {
    pOVar4 = FUN_1800019d0(*(LPCSTR *)(param_1 + 0x18));
    uVar1 = MkParseDisplayName(local_460,pOVar4,local_450,&local_468);
    SysFreeString(pOVar4);
  }
  if ((int)uVar1 < 0) {
    (*local_460->lpVtbl->Release)(local_460);
    if (local_468 != (IMoniker *)0x0) {
      (*local_468->lpVtbl->Release)(local_468);
    }
    uVar3 = (ulonglong)uVar1;
  }
  else {
    uVar1 = CreateILockBytesOnHGlobal((HGLOBAL)0x0,1,(LPLOCKBYTES *)(param_1 + 0x78));
    if ((int)uVar1 < 0) {
      (*local_468->lpVtbl->Release)(local_468);
      (*local_460->lpVtbl->Release)(local_460);
      uVar3 = (ulonglong)uVar1;
    }
    else {
      uVar1 = StgCreateDocfileOnILockBytes
                        (*(ILockBytes **)(param_1 + 0x78),0x1012,0,(IStorage **)(param_1 + 0x70));
      if ((int)uVar1 < 0) {
        (**(code **)(**(longlong **)(param_1 + 0x78) + 0x10))();
        *(undefined8 *)(param_1 + 0x78) = 0;
        (*local_468->lpVtbl->Release)(local_468);
        (*local_460->lpVtbl->Release)(local_460);
        uVar3 = (ulonglong)uVar1;
      }
      else {
        UVar2 = RegisterClipboardFormatA("Grid Text");
        local_448.dwAspect = 1;
        local_448.ptd = (DVTARGETDEVICE *)0x0;
        local_448.tymed = 1;
        local_448.lindex = -1;
        local_448.cfFormat = (CLIPFORMAT)UVar2;
        if (*(int *)(param_1 + 0x80) == 0) {
          local_448.cfFormat = 1;
        }
        ppvObj = (LPVOID *)(param_1 + 0x68);
        uVar1 = OleCreateLink(local_468,(IID *)&DAT_180066d58,0,&local_448,(LPOLECLIENTSITE)0x0,
                              *(LPSTORAGE *)(param_1 + 0x70),ppvObj);
        if ((int)uVar1 < 0) {
          (**(code **)(**(longlong **)(param_1 + 0x70) + 0x10))();
          *(undefined8 *)(param_1 + 0x70) = 0;
          (**(code **)(**(longlong **)(param_1 + 0x78) + 0x10))();
        }
        else {
          uVar1 = (**(code **)(*(longlong *)*ppvObj + 0x48))
                            (*ppvObj,&local_448,2,*(undefined8 *)(param_1 + 0x58));
          if (-1 < (int)uVar1) {
            (*local_468->lpVtbl->Release)(local_468);
            (*local_460->lpVtbl->Release)(local_460);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       (param_1 + 0x18),"");
            *(undefined4 *)(param_1 + 8) = 4;
            return 0;
          }
          (**(code **)(*(longlong *)*ppvObj + 0x10))();
          *ppvObj = (LPVOID)0x0;
          (**(code **)(**(longlong **)(param_1 + 0x70) + 0x10))();
          *(undefined8 *)(param_1 + 0x70) = 0;
          (**(code **)(**(longlong **)(param_1 + 0x78) + 0x10))();
        }
        *(undefined8 *)(param_1 + 0x78) = 0;
        (*local_468->lpVtbl->Release)(local_468);
        (*local_460->lpVtbl->Release)(local_460);
        uVar3 = (ulonglong)uVar1;
      }
    }
  }
  return uVar3;
}

/* ---- FUNC 00028790 FUN_180028790 (271 bytes) ---- */

undefined8 FUN_180028790(longlong *param_1,VARIANTARG *param_2,undefined2 *param_3)

{
  ushort uVar1;
  _union_1719 _Var2;
  HRESULT HVar3;
  int iVar4;
  undefined8 uVar5;
  longlong lVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  uint uVar9;
  ulonglong uVar10;
  undefined8 *puVar11;
  longlong *local_res10;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res18 [8];
  VARIANTARG local_68;
  undefined4 local_48;
  ULONG UStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  
  uVar1 = (param_2->n1).n2.vt;
  uVar7 = 0;
  *param_3 = 0;
  if (uVar1 < 0xe) {
    if (uVar1 != 0xd) {
      if (uVar1 == 0) {
LAB_1800287c8:
        uVar5 = (**(code **)(*param_1 + 0xd8))(param_1,0x7d4);
        return uVar5;
      }
      if (uVar1 != 9) {
        if (uVar1 == 10) goto LAB_1800287c8;
        goto LAB_180028808;
      }
    }
    puVar11 = *(undefined8 **)((longlong)&param_2->n1 + 8);
  }
  else {
    if (uVar1 != 0x4009) {
      if (uVar1 == 0x400c) {
        puVar11 = *(undefined8 **)((longlong)&param_2->n1 + 8);
        _Var2 = *(_union_1719 *)(puVar11 + 1);
        *(undefined8 *)&param_2->n1 = *puVar11;
        (param_2->n1).decVal.u2 = _Var2;
        local_38 = puVar11[2];
        lVar6 = *param_1;
        *(undefined8 *)((longlong)&param_2->n1 + 0x10) = local_38;
        local_48 = *(undefined4 *)&param_2->n1;
        UStack_44 = (param_2->n1).decVal.Hi32;
        uStack_40 = *(undefined4 *)((longlong)&param_2->n1 + 8);
        uStack_3c = *(undefined4 *)((longlong)&param_2->n1 + 0xc);
        uVar5 = (**(code **)(lVar6 + 0x90))(local_48,&local_48);
        return uVar5;
      }
      if (uVar1 != 0x400d) {
LAB_180028808:
        VariantInit(&local_68);
        HVar3 = VariantChangeType(&local_68,param_2,0,0xd);
        if (HVar3 != 0) {
          uVar5 = (**(code **)(*param_1 + 0xd8))(param_1,0x7d4);
          return uVar5;
        }
        puVar11 = *(undefined8 **)((longlong)&param_2->n1 + 8);
        VariantClear(&local_68);
        goto FUN_18002889f;
      }
    }
    puVar11 = (undefined8 *)**(undefined8 **)((longlong)&param_2->n1 + 8);
  }
FUN_18002889f:
  uVar8 = uVar7;
  if ((puVar11 != (undefined8 *)0x0) &&
     (iVar4 = (**(code **)*puVar11)(puVar11,&DAT_180063400,&local_res10), -1 < iVar4)) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(local_res10 + 0x3b)
               ,(int)local_res18);
    iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                      (local_res18,"@LABEL");
    (**(code **)(*local_res10 + 0x10))();
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
    uVar8 = (ulonglong)(iVar4 == 0);
  }
  lVar6 = param_1[0x16];
  uVar10 = uVar7;
  if (0 < lVar6) {
    do {
      if (((longlong)uVar7 < 0) || (lVar6 <= (longlong)uVar7)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      lVar6 = *(longlong *)(param_1[0x15] + uVar7 * 8);
      if (lVar6 != 0) {
        if ((puVar11 != (undefined8 *)0x0) && (*(undefined8 **)(lVar6 + 0x58) == puVar11)) {
LAB_180028996:
          *param_3 = 0xffff;
          return 0;
        }
        switch(*(undefined4 *)(lVar6 + 0x30)) {
        case 0:
        case 1:
        case 0x60:
        case 0x61:
        case 0x62:
        case 100:
          if (*(undefined8 **)(lVar6 + 0x28) == puVar11) goto LAB_180028996;
          break;
        case 3:
          if ((uVar8 != 0) && (iVar4 = FUN_18002ac00(lVar6,puVar11), iVar4 != 0))
          goto LAB_180028996;
        }
      }
      lVar6 = param_1[0x16];
      uVar9 = (int)uVar10 + 1;
      uVar7 = uVar7 + 1;
      uVar10 = (ulonglong)uVar9;
    } while ((int)uVar9 < lVar6);
  }
  return 0;
}

/* ---- FUNC 0002889F FUN_18002889f (283 bytes) ---- */

undefined8 FUN_18002889f(void)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint uVar4;
  ulonglong unaff_RSI;
  ulonglong uVar5;
  undefined8 *unaff_RDI;
  longlong unaff_R14;
  undefined2 *unaff_R15;
  longlong *in_stack_00000098;
  
  uVar3 = unaff_RSI;
  if ((unaff_RDI != (undefined8 *)0x0) && (iVar1 = (**(code **)*unaff_RDI)(), -1 < iVar1)) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
               (in_stack_00000098 + 0x3b),(int)&stack0x000000a0);
    iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       &stack0x000000a0,"@LABEL");
    (**(code **)(*in_stack_00000098 + 0x10))();
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x000000a0);
    uVar3 = CONCAT71((int7)(unaff_RSI >> 8),iVar1 == 0);
  }
  lVar2 = *(longlong *)(unaff_R14 + 0xb0);
  uVar5 = unaff_RSI;
  if (0 < lVar2) {
    do {
      if (((longlong)unaff_RSI < 0) || (lVar2 <= (longlong)unaff_RSI)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      lVar2 = *(longlong *)(*(longlong *)(unaff_R14 + 0xa8) + unaff_RSI * 8);
      if (lVar2 != 0) {
        if ((unaff_RDI != (undefined8 *)0x0) && (*(undefined8 **)(lVar2 + 0x58) == unaff_RDI)) {
LAB_180028996:
          *unaff_R15 = 0xffff;
          return 0;
        }
        switch(*(undefined4 *)(lVar2 + 0x30)) {
        case 0:
        case 1:
        case 0x60:
        case 0x61:
        case 0x62:
        case 100:
          if (*(undefined8 **)(lVar2 + 0x28) == unaff_RDI) goto LAB_180028996;
          break;
        case 3:
          if ((uVar3 != 0) && (iVar1 = FUN_18002ac00(lVar2,unaff_RDI), iVar1 != 0))
          goto LAB_180028996;
        }
      }
      lVar2 = *(longlong *)(unaff_R14 + 0xb0);
      uVar4 = (int)uVar5 + 1;
      unaff_RSI = unaff_RSI + 1;
      uVar5 = (ulonglong)uVar4;
    } while ((int)uVar4 < lVar2);
  }
  return 0;
}

/* ---- FUNC 000289BA caseD_3 (51 bytes) ---- */

undefined8 switchD_18002898e::caseD_3(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  code *UNRECOVERED_JUMPTABLE;
  longlong unaff_RBX;
  longlong unaff_RBP;
  int unaff_ESI;
  undefined8 *unaff_RDI;
  longlong unaff_R12;
  longlong unaff_R14;
  undefined2 *unaff_R15;
  
  if ((unaff_RBP == 0) || (iVar2 = FUN_18002ac00(param_3,unaff_RDI), iVar2 == 0)) {
    while( true ) {
      unaff_ESI = unaff_ESI + 1;
      unaff_RBX = unaff_RBX + 1;
      if (*(longlong *)(unaff_R14 + 0xb0) <= (longlong)unaff_ESI) break;
      if ((unaff_RBX < 0) || (*(longlong *)(unaff_R14 + 0xb0) <= unaff_RBX)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      lVar1 = *(longlong *)(*(longlong *)(unaff_R14 + 0xa8) + unaff_RBX * 8);
      if (lVar1 != 0) {
        if ((unaff_RDI != (undefined8 *)0x0) && (*(undefined8 **)(lVar1 + 0x58) == unaff_RDI))
        goto LAB_180028996;
        if (*(uint *)(lVar1 + 0x30) < 0x65) {
          UNRECOVERED_JUMPTABLE =
               (code *)((ulonglong)
                        *(uint *)(unaff_R12 + 0x289f0 +
                                 (ulonglong)
                                 *(byte *)(unaff_R12 + 0x289fc +
                                          (longlong)(int)*(uint *)(lVar1 + 0x30)) * 4) + unaff_R12);
                    /* WARNING: Could not recover jumptable at 0x00018002898e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(UNRECOVERED_JUMPTABLE);
          return uVar3;
        }
      }
    }
  }
  else {
LAB_180028996:
    *unaff_R15 = 0xffff;
  }
  return 0;
}

/* ---- FUNC 00028A70 FUN_180028a70 (3760 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180028a70(longlong param_1)

{
  ulonglong uVar1;
  int iVar2;
  uint uVar3;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar4;
  wchar_t *pwVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  ulonglong uVar11;
  undefined1 auStackY_5c8 [32];
  char *local_588;
  undefined4 local_580;
  undefined4 local_57c;
  undefined4 local_578;
  uint local_574;
  uint local_570 [2];
  longlong *local_568;
  char *local_560;
  undefined4 local_558;
  ulong local_554;
  undefined4 local_550;
  undefined4 local_54c;
  undefined4 local_548;
  ulonglong local_540;
  int *piStack_538;
  code *local_530;
  undefined4 local_528;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_520 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_518 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_510 [8];
  longlong *local_508;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_500 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_4f8 [8];
  undefined8 *local_4f0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_4e8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_4e0 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_4d8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_4d0 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_4c8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_4c0 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_4b8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_4b0 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_4a8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_4a0 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_498 [8];
  undefined8 *local_490;
  undefined8 *local_488;
  undefined8 *local_480;
  undefined8 *local_478;
  undefined8 *local_470;
  undefined8 *local_468;
  undefined8 local_460 [2];
  undefined8 *local_450;
  char local_448;
  char local_447;
  undefined1 local_428 [1008];
  ulonglong local_38;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStackY_5c8;
  if ((*(int *)(param_1 + 0x108) != 0) && (*(longlong *)(param_1 + 0xf0) != 0)) {
    FUN_1800255a0(local_460);
    uVar11 = 0;
    local_568 = (longlong *)0x0;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_588);
    uVar1 = *(ulonglong *)(param_1 + 0xf0);
    puVar10 = local_4f0;
    if (uVar1 != 0) {
      do {
        puVar9 = (undefined8 *)0x0;
        if (((longlong)uVar11 < 0) || (*(longlong *)(param_1 + 0xf0) <= (longlong)uVar11)) {
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_588,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   (*(longlong *)(param_1 + 0xe8) + uVar11 * 8));
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_560,"");
        iVar2 = strncmp(local_588,"0+",2);
        if (iVar2 == 0) {
          iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_588,'~',0);
          if (1 < iVar2) {
            pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Right
                               ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                &local_588,(int)local_4a0);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_560,
                       pCVar4);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_4a0);
            pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                               ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                &local_588,(int)local_498);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_588,
                       pCVar4);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_498);
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_520,local_588 + 2);
          pwVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                   AllocSysString(local_520);
          uVar6 = FUN_180026ff0(DAT_180079590,pwVar5,&local_568);
          SysFreeString(pwVar5);
          puVar7 = operator_new(0x60);
          puVar8 = puVar9;
          if ((int)uVar6 < 0) {
            local_490 = puVar7;
            if (puVar7 != (undefined8 *)0x0) {
              puVar8 = FUN_1800255c0(puVar7,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                             *)(param_1 + 0x10),(longlong *)0x0,4,(undefined8 *)0x0)
              ;
            }
            *(undefined4 *)(puVar8 + 1) = 1;
          }
          else {
            local_450 = puVar7;
            if (puVar7 != (undefined8 *)0x0) {
              puVar8 = FUN_1800255c0(puVar7,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                             *)(param_1 + 0x10),local_568,0,(undefined8 *)0x0);
            }
            local_540 = 0;
            piStack_538 = (int *)0x0;
            local_530 = (code *)0x0;
            puVar7 = (undefined8 *)HAGetAttr(local_568[9],0x1b,0,&local_540);
            if (puVar7 == (undefined8 *)0x0) {
              if ((piStack_538 != (int *)0x0) && (*piStack_538 != 0)) {
                *(undefined4 *)(puVar8 + 1) = 1;
              }
              if (local_530 != (code *)0x0) {
                (*local_530)(piStack_538);
              }
            }
            else if ((code *)*puVar7 != (code *)0x0) {
              (*(code *)*puVar7)(puVar7);
              (**(code **)(*local_568 + 0x10))();
              goto LAB_180028cfe;
            }
            (**(code **)(*local_568 + 0x10))();
          }
LAB_180028cfe:
          if (*(int *)(local_560 + -0x10) != 0) {
            local_574 = 0;
            local_578 = 0;
            local_57c = 0;
            local_580 = 0;
            local_570[0] = 0;
            sscanf(local_560,"%lu~%ld~%ld~%ld~%ld",&local_574,&local_578);
            FUN_18002f7b0((longlong)puVar8,local_574,local_578,local_57c,local_580,local_570[0]);
          }
          local_558 = 0;
          local_548 = 0;
          local_448 = '\0';
          uVar11 = uVar11 + 1;
          if (((longlong)uVar11 < 0) || (*(longlong *)(param_1 + 0xf0) <= (longlong)uVar11)) {
                    /* WARNING: Subroutine does not return */
            AfxThrowInvalidArgException();
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_588,
                     (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     (*(longlong *)(param_1 + 0xe8) + uVar11 * 8));
          sscanf(local_588,"basis = %s unitrow = %d unitcol = %d",&local_448);
          *(undefined4 *)(puVar8 + 9) = local_558;
          *(undefined4 *)((longlong)puVar8 + 0x4c) = local_548;
          if ((local_448 != '\0') && ((local_448 != '-' || (local_447 != '\0')))) {
            pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                     CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                               (local_4e8,&local_448);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       (puVar8 + 10),pCVar4);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_4e8);
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(puVar8 + 2),
                     (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     local_520);
          CPtrArray::SetAtGrow((CPtrArray *)(param_1 + 0x50),*(__int64 *)(param_1 + 0x60),puVar8);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_520);
        }
        else {
          iVar2 = strncmp(local_588,"2+",2);
          if (iVar2 == 0) {
            iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &local_588,'~',0);
            if (1 < iVar2) {
              pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                       ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Right
                                 ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                  &local_588,(int)local_4e0);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_560
                         ,pCVar4);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_4e0);
              pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                       ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                                 ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                  &local_588,(int)local_4d8);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_588
                         ,pCVar4);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_4d8);
            }
            local_488 = operator_new(0x60);
            puVar8 = puVar9;
            if (local_488 != (undefined8 *)0x0) {
              puVar8 = FUN_1800255c0(local_488,
                                     (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                      *)(param_1 + 0x10),(longlong *)(local_588 + 2),2,
                                     (undefined8 *)0x0);
            }
            if (*(int *)(local_560 + -0x10) != 0) {
              local_570[0] = 0;
              local_580 = 0;
              local_57c = 0;
              local_578 = 0;
              local_574 = 0;
              sscanf(local_560,"%lu~%ld~%ld~%ld~%ld",local_570,&local_580);
              FUN_18002f7b0((longlong)puVar8,local_570[0],local_580,local_57c,local_578,local_574);
            }
            CPtrArray::SetAtGrow((CPtrArray *)(param_1 + 0x50),*(__int64 *)(param_1 + 0x60),puVar8);
          }
        }
        iVar2 = strncmp(local_588,"3+",2);
        if (iVar2 == 0) {
          iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_588,'~',0);
          if (1 < iVar2) {
            pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Right
                               ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                &local_588,(int)local_4d0);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_560,
                       pCVar4);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_4d0);
            pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                               ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                &local_588,(int)local_4c8);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_588,
                       pCVar4);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_4c8);
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_518,local_588 + 2);
          pwVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                   AllocSysString(local_518);
          uVar6 = FUN_180026ff0(DAT_180079590,pwVar5,&local_568);
          SysFreeString(pwVar5);
          puVar8 = operator_new(0x60);
          if ((int)uVar6 < 0) {
            local_478 = puVar8;
            if (puVar8 != (undefined8 *)0x0) {
              puVar9 = FUN_1800255c0(puVar8,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                             *)(param_1 + 0x10),(longlong *)0x0,4,(undefined8 *)0x0)
              ;
            }
            *(undefined4 *)(puVar9 + 1) = 1;
          }
          else {
            local_480 = puVar8;
            if (puVar8 != (undefined8 *)0x0) {
              puVar9 = FUN_1800255c0(puVar8,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                             *)(param_1 + 0x10),local_568,3,(undefined8 *)0x0);
            }
            local_540 = 0;
            piStack_538 = (int *)0x0;
            local_530 = (code *)0x0;
            puVar8 = (undefined8 *)HAGetAttr(local_568[9],0x1b,0);
            if (puVar8 == (undefined8 *)0x0) {
              if ((piStack_538 != (int *)0x0) && (*piStack_538 != 0)) {
                *(undefined4 *)(puVar9 + 1) = 1;
              }
              if (local_530 != (code *)0x0) {
                (*local_530)(piStack_538);
              }
            }
            else if ((code *)*puVar8 != (code *)0x0) {
              (*(code *)*puVar8)(puVar8);
              (**(code **)(*local_568 + 0x10))();
              goto LAB_180029182;
            }
            (**(code **)(*local_568 + 0x10))();
          }
LAB_180029182:
          if (*(int *)(local_560 + -0x10) != 0) {
            local_570[0] = 0;
            local_580 = 0;
            local_57c = 0;
            local_578 = 0;
            local_574 = 0;
            sscanf(local_560,"%lu~%ld~%ld~%ld~%ld",local_570,&local_580);
            FUN_18002f7b0((longlong)puVar9,local_570[0],local_580,local_57c,local_578,local_574);
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(puVar9 + 2),
                     (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     local_518);
          CPtrArray::SetAtGrow((CPtrArray *)(param_1 + 0x50),*(__int64 *)(param_1 + 0x60),puVar9);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_518);
        }
        else {
          iVar2 = strncmp(local_588,"4+",2);
          if (iVar2 == 0) {
            FUN_180002a20(local_428,"Assert failed in file %s line %d",
                          "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\HappSel.cpp",0x9f9);
            LogMessage(local_428,2,1);
            uVar11 = uVar11 + 1;
            if (((longlong)uVar11 < 0) || (*(longlong *)(param_1 + 0xf0) <= (longlong)uVar11)) {
                    /* WARNING: Subroutine does not return */
              AfxThrowInvalidArgException();
            }
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_588,
                       (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                       (*(longlong *)(param_1 + 0xe8) + uVar11 * 8));
          }
          else {
            iVar2 = strncmp(local_588,"90+",3);
            if (iVar2 == 0) {
              iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                 &local_588,'~',0);
              if (1 < iVar2) {
                pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                          *)ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                            Right((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                  &local_588,(int)local_4c0);
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_560,pCVar4);
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_4c0);
                pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                          *)ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                        *)&local_588,(int)local_4b8);
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_588,pCVar4);
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_4b8);
              }
              local_470 = operator_new(0x60);
              if (local_470 != (undefined8 *)0x0) {
                puVar9 = FUN_1800255c0(local_470,
                                       (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                        *)(param_1 + 0x10),(longlong *)(local_588 + 3),0x5a,
                                       (undefined8 *)0x0);
              }
              if (*(int *)(local_560 + -0x10) != 0) {
                local_570[0] = 0;
                local_580 = 0;
                local_57c = 0;
                local_578 = 0;
                local_574 = 0;
                sscanf(local_560,"%lu~%ld~%ld~%ld~%ld",local_570,&local_580);
                FUN_18002f7b0((longlong)puVar9,local_570[0],local_580,local_57c,local_578,local_574)
                ;
              }
              CPtrArray::SetAtGrow
                        ((CPtrArray *)(param_1 + 0x50),*(__int64 *)(param_1 + 0x60),puVar9);
            }
          }
        }
        iVar2 = strncmp(local_588,"96+",3);
        if (((iVar2 == 0) || (iVar2 = strncmp(local_588,"97+",3), iVar2 == 0)) ||
           (iVar2 = strncmp(local_588,"99+",3), iVar2 == 0)) {
          uVar3 = atoi(local_588);
          iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_588,'~',0);
          if (1 < iVar2) {
            pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Right
                               ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                &local_588,(int)local_4b0);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_560,
                       pCVar4);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_4b0);
            pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                               ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                &local_588,(int)local_4a8);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_588,
                       pCVar4);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_4a8);
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_4f8,local_588 + 3);
          pwVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                   AllocSysString(local_4f8);
          uVar6 = FUN_180026ff0(DAT_180079590,pwVar5,&local_568);
          SysFreeString(pwVar5);
          if (-1 < (int)uVar6) {
            local_468 = operator_new(0x60);
            if (local_468 == (undefined8 *)0x0) {
              puVar10 = (undefined8 *)0x0;
            }
            else {
              puVar10 = FUN_1800255c0(local_468,
                                      (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                       *)(param_1 + 0x10),local_568,uVar3,(undefined8 *)0x0);
            }
            local_540 = 0;
            piStack_538 = (int *)0x0;
            local_530 = (code *)0x0;
            puVar9 = (undefined8 *)HAGetAttr(local_568[9],0x1b,0,&local_540);
            if (puVar9 == (undefined8 *)0x0) {
              if ((piStack_538 != (int *)0x0) && (*piStack_538 != 0)) {
                *(undefined4 *)(puVar10 + 1) = 1;
              }
              if (local_530 != (code *)0x0) {
                (*local_530)(piStack_538);
              }
            }
            else if ((code *)*puVar9 != (code *)0x0) {
              (*(code *)*puVar9)(puVar9);
            }
            (**(code **)(*local_568 + 0x10))();
          }
          if (*(int *)(local_560 + -0x10) != 0) {
            local_570[0] = 0;
            local_580 = 0;
            local_57c = 0;
            local_578 = 0;
            local_574 = 0;
            sscanf(local_560,"%lu~%ld~%ld~%ld~%ld",local_570,&local_580);
            FUN_18002f7b0((longlong)puVar10,local_570[0],local_580,local_57c,local_578,local_574);
          }
          local_54c = 0;
          local_550 = 0;
          local_448 = '\0';
          uVar11 = uVar11 + 1;
          if (((longlong)uVar11 < 0) || (*(longlong *)(param_1 + 0xf0) <= (longlong)uVar11)) {
                    /* WARNING: Subroutine does not return */
            AfxThrowInvalidArgException();
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_588,
                     (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     (*(longlong *)(param_1 + 0xe8) + uVar11 * 8));
          sscanf(local_588,"basis = %s unitrow = %d unitcol = %d",&local_448);
          *(undefined4 *)(puVar10 + 9) = local_54c;
          *(undefined4 *)((longlong)puVar10 + 0x4c) = local_550;
          if ((local_448 != '\0') && ((local_448 != '-' || (local_447 != '\0')))) {
            pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                     CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                               ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                &local_4f0,&local_448);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       (puVar10 + 10),pCVar4);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4f0);
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(puVar10 + 2),
                     (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     local_4f8);
          CPtrArray::SetAtGrow((CPtrArray *)(param_1 + 0x50),*(__int64 *)(param_1 + 0x60),puVar10);
          this = local_4f8;
LAB_18002989f:
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this);
        }
        else {
          if (*local_588 == '-') {
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_510,local_588 + 1);
            pwVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                     AllocSysString(local_510);
            uVar6 = FUN_180026ff0(DAT_180079590,pwVar5,&local_568);
            SysFreeString(pwVar5);
            if ((int)uVar6 < 0) {
              this = local_510;
            }
            else {
              CPtrArray::SetAtGrow
                        ((CPtrArray *)(param_1 + 0x78),*(__int64 *)(param_1 + 0x88),local_568);
              this = local_510;
            }
            goto LAB_18002989f;
          }
          if (*local_588 == '*') {
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_500,local_588 + 1);
            pwVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                     AllocSysString(local_500);
            uVar6 = FUN_180026ff0(DAT_180079590,pwVar5,&local_568);
            SysFreeString(pwVar5);
            if ((int)uVar6 < 0) {
              this = local_500;
            }
            else {
              local_554 = 0;
              local_508 = (longlong *)0x0;
              iVar2 = (**(code **)*local_568)(local_568,&DAT_180066d58,&local_508);
              if (-1 < iVar2) {
                local_540 = local_540 & 0xffffffffffff0000;
                piStack_538 = (int *)0x0;
                local_530 = (code *)0xffffffffffffffff;
                local_528 = 0xffffffff;
                (**(code **)(*local_508 + 0x48))(local_508,&local_540,1);
                (**(code **)(*local_508 + 0x10))();
              }
              CPtrArray::SetAtGrow
                        ((CPtrArray *)(param_1 + 0x110),*(__int64 *)(param_1 + 0x120),local_568);
              CDWordArray::SetAtGrow
                        ((CDWordArray *)(param_1 + 0x138),*(__int64 *)(param_1 + 0x148),local_554);
              this = local_500;
            }
            goto LAB_18002989f;
          }
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_560);
        uVar11 = uVar11 + 1;
      } while (uVar11 < uVar1);
    }
    *(undefined4 *)(param_1 + 0x108) = 0;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_588);
    FUN_180025a20(local_460);
  }
  return;
}

/* ---- FUNC 00029930 FUN_180029930 (372 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_180029930(longlong param_1,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2)

{
  longlong *plVar1;
  int iVar2;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar3;
  undefined1 auStack_448 [32];
  IBindCtx *local_428;
  wchar_t *local_420;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_418 [16];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_180077818 ^ (ulonglong)auStack_448;
  if (*(int *)(param_1 + 8) != 0x10) {
    FUN_180002a20(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\HappSel.cpp",0x13ce);
    LogMessage(local_408,2,1);
  }
  if (*(int *)(*(longlong *)(param_1 + 0x18) + -0x10) == 0) {
    FUN_180002a20(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\HappSel.cpp",0x13cf);
    LogMessage(local_408,2,1);
  }
  if (**(char **)(param_1 + 0x18) == '~') {
    CreateBindCtx(0,&local_428);
    plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x10) + 0x118);
    iVar2 = (**(code **)(*plVar1 + 0xa0))(plVar1,local_428,0,&local_420);
    if (iVar2 < 0) {
      (*local_428->lpVtbl->Release)(local_428);
      return 0x80004005;
    }
    pCVar3 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_418,local_420);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_2,pCVar3);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_418);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              (param_2,(char *)(*(longlong *)(param_1 + 0x18) + 1));
    CoTaskMemFree(local_420);
    (*local_428->lpVtbl->Release)(local_428);
  }
  else {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              (param_2,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                       (param_1 + 0x18));
  }
  return 0;
}

/* ---- FUNC 00029AB0 FUN_180029ab0 (156 bytes) ---- */

ulonglong FUN_180029ab0(longlong param_1,longlong param_2,undefined8 *param_3)

{
  LPBC *ppbc;
  uint uVar1;
  ulonglong uVar2;
  longlong *local_res8;
  
  uVar2 = 0;
  ppbc = (LPBC *)(param_1 + 8);
  if (*ppbc == (LPBC)0x0) {
    CreateBindCtx(0,ppbc);
  }
  *param_3 = 0;
  if ((param_2 != 0) &&
     (uVar2 = (**(code **)(**(longlong **)(DAT_1800797f0 + 0x118) + 0x98))
                        (*(longlong **)(DAT_1800797f0 + 0x118),*(undefined8 *)(param_2 + 0xe8),
                         &local_res8), -1 < (int)uVar2)) {
    uVar1 = (**(code **)(*local_res8 + 0xa0))(local_res8,*ppbc,0,param_3);
    uVar2 = (ulonglong)uVar1;
    (**(code **)(*local_res8 + 0x10))();
  }
  return uVar2;
}

/* ---- FUNC 00029B50 FUN_180029b50 (986 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

ulonglong FUN_180029b50(longlong param_1,
                       CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2)

{
  LPCWSTR lpWideCharStr;
  char *pcVar1;
  longlong *plVar2;
  code *pcVar3;
  wchar_t *lpWideCharStr_00;
  HRESULT HVar4;
  uint uVar5;
  int iVar6;
  ulonglong uVar7;
  longlong lVar8;
  longlong lVar9;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  IAtlStringMgr *pIVar10;
  IID *This;
  longlong lVar11;
  undefined1 *puVar12;
  char *pcVar13;
  undefined4 uVar14;
  char *pcVar15;
  IID **ppvObject;
  size_t _MaxCount;
  undefined8 uStack_4c0;
  undefined1 auStack_4b8 [32];
  undefined8 uStack_498;
  int aiStack_490 [2];
  undefined8 local_488 [2];
  IID *local_478;
  IID *local_470;
  longlong *local_468;
  DWORD local_460;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_458 [8];
  wchar_t *local_450;
  wchar_t *local_448;
  IEnumString *local_440;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_438 [16];
  undefined1 local_428 [1008];
  ulonglong local_38;
  
  puVar12 = auStack_4b8;
  ppvObject = &local_478;
  local_38 = DAT_180077818 ^ (ulonglong)ppvObject;
  pcVar15 = (char *)0x0;
  uVar14 = 0;
  local_460 = 0;
  if (*(int *)(param_1 + 8) == 1) {
    uStack_4c0 = 0x180029baa;
    FUN_180002a20(local_428,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\HappSel.cpp",0x1381);
    uStack_4c0 = 0x180029bbb;
    LogMessage(local_428,2,1);
  }
  if (*(int *)(param_1 + 8) == 0x10) {
    uStack_4c0 = 0x180029bce;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              (param_2,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                       (param_1 + 0x18));
LAB_180029f03:
    uVar7 = 0;
  }
  else {
    local_478 = (IID *)0x0;
    uStack_4c0 = 0x180029beb;
    uVar7 = (**(code **)**(undefined8 **)(param_1 + 0x68))
                      (*(undefined8 **)(param_1 + 0x68),&DAT_180066dc8);
    puVar12 = auStack_4b8;
    if ((int)uVar7 < 0) goto LAB_180029f05;
    uStack_4c0 = 0x180029bff;
    CreateBindCtx(0,(LPBC *)&local_470);
    local_440 = (IEnumString *)0x0;
    uStack_4c0 = 0x180029c11;
    HVar4 = (*(*(IBindCtxVtbl **)local_478)->EnumObjectParam)((IBindCtx *)local_478,&local_440);
    if (-1 < HVar4) {
      uStack_4c0 = 0x180029c1f;
      (*local_440->lpVtbl->Release)(local_440);
      uStack_4c0 = 0x180029c2d;
      (*(*(IBindCtxVtbl **)local_478)[1].QueryInterface)((IBindCtx *)local_478,local_470,ppvObject);
    }
    uStack_4c0 = 0x180029c3b;
    uVar5 = (*(*(IBindCtxVtbl **)local_478)->SetBindOptions)
                      ((IBindCtx *)local_478,(BIND_OPTS *)&local_468);
    This = local_478;
    if (-1 < (int)uVar5) {
      uStack_4c0 = 0x180029c4b;
      (*(*(IBindCtxVtbl **)local_478)->Release)((IBindCtx *)local_478);
      uStack_4c0 = 0x180029c63;
      uVar5 = (**(code **)(*local_468 + 0xa0))(local_468,local_470,0,&local_448);
      if (-1 < (int)uVar5) {
        plVar2 = *(longlong **)(*(longlong *)(param_1 + 0x10) + 0x118);
        uStack_4c0 = 0x180029ca3;
        uVar5 = (**(code **)(*plVar2 + 0xa0))(plVar2,local_470,0,&local_450);
        lpWideCharStr_00 = local_448;
        uVar7 = (ulonglong)uVar5;
        if ((int)uVar5 < 0) {
          uStack_4c0 = 0x180029cb3;
          CoTaskMemFree(local_448);
          uStack_4c0 = 0x180029cbd;
          (**(code **)(*local_468 + 0x10))();
          uStack_4c0 = 0x180029cc7;
          (**(code **)(*(longlong *)local_470 + 0x10))((IBindCtx *)local_470);
          puVar12 = auStack_4b8;
          goto LAB_180029f05;
        }
        lVar11 = -1;
        _MaxCount = 0xffffffffffffffff;
        do {
          _MaxCount = _MaxCount + 1;
        } while (local_450[_MaxCount] != L'\0');
        uStack_4c0 = 0x180029cf3;
        iVar6 = wcsncmp(local_448,local_450,_MaxCount);
        if (iVar6 == 0) {
          lVar8 = -1;
          do {
            lVar8 = lVar8 + 1;
          } while (local_450[lVar8] != L'\0');
          if (lpWideCharStr_00[lVar8] != L'!') {
            lVar8 = -1;
            do {
              lVar8 = lVar8 + 1;
            } while (local_450[lVar8] != L'\0');
            if (lpWideCharStr_00[lVar8] != L'\\') goto LAB_180029e4b;
          }
          lVar8 = -1;
          do {
            lVar8 = lVar8 + 1;
          } while (local_450[lVar8] != L'\0');
          lpWideCharStr = lpWideCharStr_00 + lVar8;
          puVar12 = auStack_4b8;
          pcVar13 = pcVar15;
          if (lpWideCharStr != (LPCWSTR)0x0) {
            lVar8 = -1;
            do {
              lVar9 = lVar8;
              lVar8 = lVar9 + 1;
            } while (lpWideCharStr[lVar8] != L'\0');
            iVar6 = (int)lVar9 + 2;
            puVar12 = auStack_4b8;
            if (iVar6 < 0x40000000) {
              lVar8 = (longlong)(int)lVar8 * 2;
              uVar7 = lVar8 + 0x11;
              if (uVar7 <= lVar8 + 2U) {
                uVar7 = 0xffffffffffffff0;
              }
              uStack_4c0 = 0x180029d84;
              lVar8 = -(uVar7 & 0xfffffffffffffff0);
              pcVar1 = (char *)((longlong)&local_478 + lVar8);
              puVar12 = auStack_4b8 + lVar8;
              if (pcVar1 != (char *)0x0) {
                *pcVar1 = '\0';
                *(undefined8 *)((longlong)local_488 + lVar8 + 8) = 0;
                *(undefined8 *)((longlong)local_488 + lVar8) = 0;
                *(int *)((longlong)aiStack_490 + lVar8) = iVar6 * 2;
                *(char **)((longlong)&uStack_498 + lVar8) = pcVar1;
                *(undefined8 *)(auStack_4b8 + lVar8 + -8) = 0x180029db7;
                iVar6 = WideCharToMultiByte(0,0,lpWideCharStr,-1,
                                            *(LPSTR *)((longlong)&uStack_498 + lVar8),
                                            *(int *)((longlong)aiStack_490 + lVar8),
                                            *(LPCSTR *)((longlong)local_488 + lVar8),
                                            *(LPBOOL *)((longlong)local_488 + lVar8 + 8));
                puVar12 = auStack_4b8 + lVar8;
                pcVar13 = pcVar1;
                if (iVar6 == 0) {
                  puVar12 = auStack_4b8 + lVar8;
                  pcVar13 = pcVar15;
                }
              }
            }
          }
          *(undefined8 *)(puVar12 + -8) = 0x180029dd3;
          this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                 ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                 CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_438,"~");
          *(undefined8 *)(puVar12 + -8) = 0x180029ddf;
          pIVar10 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                              (this);
          *(undefined8 *)(puVar12 + -8) = 0x180029dec;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_458,pIVar10);
          local_460 = 1;
          if (pcVar13 != (char *)0x0) {
            do {
              lVar11 = lVar11 + 1;
            } while (pcVar13[lVar11] != '\0');
            uVar14 = (undefined4)lVar11;
          }
          pcVar15 = *(char **)this;
          *(undefined4 *)(puVar12 + 0x20) = uVar14;
          iVar6 = *(int *)(pcVar15 + -0x10);
          *(undefined8 *)(puVar12 + -8) = 0x180029e23;
          ATL::CSimpleStringT<char,1>::Concatenate
                    ((CSimpleStringT<char,1> *)local_458,pcVar15,iVar6,pcVar13,
                     *(int *)(puVar12 + 0x20));
          *(undefined8 *)(puVar12 + -8) = 0x180029e30;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    (param_2,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                              *)local_458);
          *(undefined8 *)(puVar12 + -8) = 0x180029e3b;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_458);
          *(undefined8 *)(puVar12 + -8) = 0x180029e46;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_438);
        }
        else {
LAB_180029e4b:
          puVar12 = auStack_4b8;
          pcVar13 = pcVar15;
          if (lpWideCharStr_00 != (wchar_t *)0x0) {
            lVar11 = -1;
            do {
              lVar8 = lVar11;
              lVar11 = lVar8 + 1;
            } while (lpWideCharStr_00[lVar11] != L'\0');
            iVar6 = (int)lVar8 + 2;
            puVar12 = auStack_4b8;
            if (iVar6 < 0x40000000) {
              lVar11 = (longlong)(int)lVar11 * 2;
              uVar7 = lVar11 + 0x11;
              if (uVar7 <= lVar11 + 2U) {
                uVar7 = 0xffffffffffffff0;
              }
              uStack_4c0 = 0x180029e90;
              lVar11 = -(uVar7 & 0xfffffffffffffff0);
              pcVar1 = (char *)((longlong)&local_478 + lVar11);
              puVar12 = auStack_4b8 + lVar11;
              if (pcVar1 != (char *)0x0) {
                *pcVar1 = '\0';
                *(undefined8 *)((longlong)local_488 + lVar11 + 8) = 0;
                *(undefined8 *)((longlong)local_488 + lVar11) = 0;
                *(int *)((longlong)aiStack_490 + lVar11) = iVar6 * 2;
                *(char **)((longlong)&uStack_498 + lVar11) = pcVar1;
                *(undefined8 *)(auStack_4b8 + lVar11 + -8) = 0x180029ec6;
                iVar6 = WideCharToMultiByte(0,0,lpWideCharStr_00,-1,
                                            *(LPSTR *)((longlong)&uStack_498 + lVar11),
                                            *(int *)((longlong)aiStack_490 + lVar11),
                                            *(LPCSTR *)((longlong)local_488 + lVar11),
                                            *(LPBOOL *)((longlong)local_488 + lVar11 + 8));
                puVar12 = auStack_4b8 + lVar11;
                pcVar13 = pcVar1;
                if (iVar6 == 0) {
                  puVar12 = auStack_4b8 + lVar11;
                  pcVar13 = pcVar15;
                }
              }
            }
          }
          *(undefined8 *)(puVar12 + -8) = 0x180029edb;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    (param_2,pcVar13);
        }
        *(undefined8 *)(puVar12 + -8) = 0x180029ee5;
        CoTaskMemFree(local_450);
        *(undefined8 *)(puVar12 + -8) = 0x180029eef;
        CoTaskMemFree(local_448);
        pcVar3 = *(code **)(*local_468 + 0x10);
        *(undefined8 *)(puVar12 + -8) = 0x180029ef9;
        (*pcVar3)();
        pcVar3 = *(code **)(*(longlong *)local_470 + 0x10);
        *(undefined8 *)(puVar12 + -8) = 0x180029f03;
        (*pcVar3)((IBindCtx *)local_470);
        goto LAB_180029f03;
      }
      uStack_4c0 = 0x180029c73;
      (**(code **)(*local_468 + 0x10))();
      This = local_470;
    }
    uStack_4c0 = 0x180029c7d;
    (*(*(IBindCtxVtbl **)This)->Release)((IBindCtx *)This);
    uVar7 = (ulonglong)uVar5;
    puVar12 = auStack_4b8;
  }
LAB_180029f05:
  *(undefined8 *)(puVar12 + -8) = 0x180029f14;
  return uVar7;
}

/* ---- FUNC 00029F30 FUN_180029f30 (489 bytes) ---- */

undefined8 FUN_180029f30(longlong param_1,CStringArray *param_2)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar5;
  ulonglong uVar6;
  LPBC local_res8;
  wchar_t *local_res18;
  undefined8 local_res20;
  LPBC local_18;
  wchar_t *local_10;
  
  if (*(longlong *)(param_1 + 0x40) == 0) {
    lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x28);
    iVar1 = *(int *)(lVar2 + 0x68);
    while( true ) {
      if (iVar1 == 0) {
        if (lVar2 != 0) {
          CreateBindCtx(0,&local_res8);
          (**(code **)(**(longlong **)(lVar2 + 0xe8) + 0xa0))
                    (*(longlong **)(lVar2 + 0xe8),local_res8,0,&local_res18);
          pCVar5 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                   ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                   CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                             ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                              &local_res20,local_res18);
          CStringArray::SetAtGrow(param_2,*(__int64 *)(param_2 + 0x10),pCVar5);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
        }
        return 0;
      }
      if (lVar2 == 0) break;
      lVar2 = *(longlong *)(lVar2 + 0x60);
      if (lVar2 != 0) {
        iVar1 = *(int *)(lVar2 + 0x68);
      }
    }
    return 0;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18,"");
  if (*(longlong *)(param_1 + 0x40) < 1) {
LAB_18002a114:
                    /* WARNING: Subroutine does not return */
    AfxThrowInvalidArgException();
  }
  lVar2 = **(longlong **)(param_1 + 0x38);
  if (lVar2 != 0) {
    uVar6 = 0;
    uVar3 = *(ulonglong *)(lVar2 + 0x10);
    if (uVar3 != 0) {
      do {
        if (((longlong)uVar6 < 0) || ((longlong)uVar3 <= (longlong)uVar6)) goto LAB_18002a114;
        lVar4 = *(longlong *)(*(longlong *)(lVar2 + 8) + uVar6 * 8);
        iVar1 = *(int *)(lVar4 + 0x68);
        while (iVar1 != 0) {
          if (lVar4 == 0) goto LAB_180029fcb;
          lVar4 = *(longlong *)(lVar4 + 0x60);
          if (lVar4 != 0) {
            iVar1 = *(int *)(lVar4 + 0x68);
          }
        }
        if (lVar4 != 0) {
          CreateBindCtx(0,&local_18);
          (**(code **)(**(longlong **)(lVar4 + 0xe8) + 0xa0))
                    (*(longlong **)(lVar4 + 0xe8),local_18,0,&local_10);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
                     local_10);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8,
                     " %s[...]",local_res20);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18,
                     (CSimpleStringT<char,1> *)&local_res8);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
          break;
        }
LAB_180029fcb:
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar3);
    }
  }
  CStringArray::SetAtGrow
            (param_2,*(__int64 *)(param_2 + 0x10),
             (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18);
  return 0;
}

/* ---- FUNC 0002A120 FUN_18002a120 (874 bytes) ---- */

longlong FUN_18002a120(longlong *param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  ulonglong uVar3;
  char cVar4;
  HRESULT HVar5;
  int iVar6;
  longlong lVar7;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar8;
  longlong *plVar9;
  wchar_t *lpszItem;
  char *pcVar10;
  char *pcVar11;
  uint uVar12;
  ulonglong uVar13;
  bool bVar14;
  longlong *local_res8;
  undefined4 local_res10 [2];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res18 [8];
  longlong local_res20;
  undefined8 local_68;
  IMoniker *local_60;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_58 [8];
  longlong *local_50;
  longlong *local_48;
  
  plVar2 = param_1 + 0x15;
  lVar7 = *plVar2;
  if (lVar7 == 0) {
    local_res10[0] = 0x21;
    plVar1 = param_1 + 1;
    if ((*plVar1 != 0) && (*(longlong *)(*plVar1 + 0x118) != 0)) {
      local_res8 = param_1;
      local_50 = plVar2;
      local_48 = plVar1;
      if ((char)param_1[0x2c] == '\0') {
        if ((0 < param_1[0x1e]) && ((int)param_1[0x21] != 0)) {
          FUN_180028a70((longlong)param_1);
        }
        if (*(int *)(param_1[2] + -0x10) == 0) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
                     "");
          uVar13 = 0;
          uVar3 = param_1[0xc];
          if (uVar3 != 0) {
            do {
              if (*(int *)(local_res20 + -0x10) != 0) break;
              if (((longlong)uVar13 < 0) || (param_1[0xc] <= (longlong)uVar13)) {
                    /* WARNING: Subroutine does not return */
                AfxThrowInvalidArgException();
              }
              lVar7 = *(longlong *)(param_1[0xb] + uVar13 * 8);
              iVar6 = *(int *)(lVar7 + 0x30);
              if ((iVar6 == 0) || (iVar6 - 3U < 2)) {
                pcVar10 = *(char **)(lVar7 + 0x10);
                cVar4 = *pcVar10;
                if (cVar4 != '!') goto LAB_18002a244;
                pcVar10 = pcVar10 + 1;
                cVar4 = *pcVar10;
                while (cVar4 != '!') {
LAB_18002a244:
                  bVar14 = cVar4 == '\0';
                  cVar4 = '\0';
                  if (bVar14) break;
                  pcVar10 = pcVar10 + 1;
                  cVar4 = *pcVar10;
                }
                pcVar11 = pcVar10 + 1;
                if (cVar4 != '!') {
                  pcVar11 = pcVar10;
                }
                pCVar8 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                          *)ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                      (local_58,pcVar11);
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_res20,pCVar8);
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_58);
              }
              uVar13 = uVar13 + 1;
            } while (uVar13 < uVar3);
          }
          pcVar10 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)&local_res20,0)
          ;
          cVar4 = *pcVar10;
          while (cVar4 != '\0') {
            if (cVar4 == '!') {
              *pcVar10 = '.';
            }
            pcVar10 = pcVar10 + 1;
            cVar4 = *pcVar10;
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_68);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_68,
                     "OLE_LINK.%s",local_res20);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    (local_res18,
                     (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     &local_68);
          uVar12 = 2;
          plVar9 = FUN_180011370(*plVar1,(undefined8 *)local_res18);
          while (plVar9 != (longlong *)0x0) {
            (**(code **)(*plVar9 + 0x10))();
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                      (local_res18,"%s(%d)",local_68,(ulonglong)uVar12);
            uVar12 = uVar12 + 1;
            plVar9 = FUN_180011370(*plVar1,(undefined8 *)local_res18);
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 2),
                     (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     local_res18);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_68);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
        }
        lpszItem = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                   AllocSysString((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                  (param_1 + 2));
        HVar5 = CreateItemMoniker((LPCOLESTR)local_res10,lpszItem,&local_60);
        if (HVar5 < 0) {
          SysFreeString(lpszItem);
          return 0;
        }
        SysFreeString(lpszItem);
LAB_18002a3e7:
        (**(code **)(**(longlong **)(*plVar1 + 0x118) + 0x58))
                  (*(longlong **)(*plVar1 + 0x118),local_60,0,plVar2);
        (*local_60->lpVtbl->Release)(local_60);
        if (((int)param_1[0x14] == 0) &&
           (iVar6 = (*(code *)**(undefined8 **)*plVar1)
                              ((undefined8 *)*plVar1,&DAT_180066db8,&local_res8), -1 < iVar6)) {
          (**(code **)(*local_res8 + 0x98))(local_res8,param_1[0x1b],param_1 + 0x14);
          (**(code **)(*local_res8 + 0x10))();
        }
        return *plVar2;
      }
      HVar5 = CreateItemMoniker((LPCOLESTR)local_res10,L"OLE_LINK.BAD_LINK",&local_60);
      if (-1 < HVar5) goto LAB_18002a3e7;
    }
    lVar7 = 0;
  }
  return lVar7;
}

/* ---- FUNC 0002A490 FUN_18002a490 (387 bytes) ---- */

undefined4 FUN_18002a490(undefined8 *param_1)

{
  longlong *plVar1;
  int iVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  undefined4 uVar5;
  byte *local_res8;
  undefined8 local_38;
  char *pcStack_30;
  code *local_28;
  
  plVar1 = (longlong *)*param_1;
  local_38 = 0;
  pcStack_30 = (char *)0x0;
  local_28 = (code *)0x0;
  if (plVar1[9] != 0) {
    puVar3 = (undefined8 *)HAGetAttr(plVar1[9],0x2d,0,&local_38);
    if (puVar3 == (undefined8 *)0x0) {
      if ((((int)local_38 == -3) && (pcStack_30 != (char *)0x0)) && (*pcStack_30 != '\0')) {
        if ((*pcStack_30 == ' ') && (pcStack_30[1] == '\0')) {
          if (local_28 != (code *)0x0) {
            (*local_28)();
          }
          return 2;
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
        iVar2 = strncmp(pcStack_30,"\\\\Data",6);
        if (iVar2 == 0) {
          ATL::CSimpleStringT<char,1>::Empty((CSimpleStringT<char,1> *)&local_res8);
        }
        else {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8,
                     "\\\\Data");
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8,
                   pcStack_30);
        uVar5 = *(undefined4 *)partial_results_exref;
        *(undefined4 *)partial_results_exref = 0;
        plVar4 = FUN_180038fc0(plVar1,local_res8);
        *(undefined4 *)partial_results_exref = uVar5;
        if (local_28 != (code *)0x0) {
          (*local_28)(pcStack_30);
        }
        uVar5 = 0;
        if (plVar4 != (longlong *)0x0) {
          if (plVar4 == plVar1) {
            (**(code **)(*plVar4 + 0x10))(plVar4);
            uVar5 = 0;
          }
          else {
            (**(code **)(*plVar1 + 0x10))(plVar1);
            *param_1 = plVar4;
            uVar5 = 1;
          }
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
        return uVar5;
      }
      if (local_28 != (code *)0x0) {
        (*local_28)();
      }
    }
    else if ((code *)*puVar3 != (code *)0x0) {
      (*(code *)*puVar3)(puVar3);
    }
  }
  return 0;
}

/* ---- FUNC 0002A620 FUN_18002a620 (1324 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

CPtrArray * FUN_18002a620(longlong param_1,HGLOBAL param_2)

{
  int iVar1;
  longlong *plVar2;
  int iVar3;
  CPtrArray *pCVar4;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar5;
  CPtrArray *pCVar6;
  CPtrArray *pCVar7;
  int iVar8;
  CPtrArray *pCVar9;
  uint uVar10;
  longlong lVar11;
  longlong lVar12;
  CPtrArray *pCVar13;
  undefined1 auStackY_528 [32];
  short local_4f8 [2];
  short local_4f4;
  int local_4f0;
  undefined4 uStack_4ec;
  int local_4e8;
  int local_4e4;
  char *local_4e0;
  longlong local_4d8;
  longlong local_4d0;
  undefined8 local_4c8;
  CPtrArray *local_4c0;
  CDWordArray local_4b8 [8];
  uint *local_4b0;
  longlong local_4a8;
  CDWordArray local_490 [8];
  longlong local_488;
  CPtrArray *local_480;
  CStringArray local_468 [16];
  longlong local_458;
  undefined1 local_438 [1008];
  ulonglong local_48;
  
  local_48 = DAT_180077818 ^ (ulonglong)auStackY_528;
  plVar2 = *(longlong **)(*(longlong *)(param_1 + 0x28) + 0x38);
  if ((plVar2 == (longlong *)0x0) || (*plVar2 == 0)) {
    return (CPtrArray *)0x0;
  }
  local_4d8 = param_1;
  CStringArray::CStringArray(local_468);
  CDWordArray::CDWordArray(local_490);
  CDWordArray::CDWordArray(local_4b8);
  lVar12 = local_4d8;
  FUN_18002bbf0(local_4d8,param_2,local_468,local_490,local_4b8);
  if (local_458 == 0) {
    pCVar13 = (CPtrArray *)0x80004005;
    goto LAB_18002a965;
  }
  pCVar13 = (CPtrArray *)0x0;
  iVar3 = 0;
  local_4e8 = 0;
  local_4e4 = 0;
  local_4f8[0] = 0;
  local_4f4 = 0;
  iVar8 = 0;
  if (local_480 != (CPtrArray *)0x0) {
    local_488 = local_488 - (longlong)local_4b0;
    pCVar4 = pCVar13;
    pCVar6 = pCVar13;
    pCVar7 = pCVar13;
    do {
      if (((longlong)pCVar4 < 0) || ((longlong)local_480 <= (longlong)pCVar4)) {
LAB_18002ab47:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      uVar10 = *(uint *)((longlong)local_4b0 + local_488);
      pCVar9 = (CPtrArray *)(ulonglong)uVar10;
      if ((int)uVar10 <= (int)pCVar7) {
        pCVar9 = pCVar7;
      }
      iVar3 = (int)pCVar9;
      if (local_4a8 <= (longlong)pCVar4) goto LAB_18002ab47;
      pCVar7 = (CPtrArray *)(ulonglong)*local_4b0;
      if ((int)*local_4b0 <= (int)pCVar6) {
        pCVar7 = pCVar6;
      }
      iVar8 = (int)pCVar7;
      pCVar4 = pCVar4 + 1;
      local_4b0 = local_4b0 + 1;
      pCVar6 = pCVar7;
      pCVar7 = pCVar9;
    } while (pCVar4 < local_480);
  }
  uVar10 = iVar3 + 1;
  iVar8 = iVar8 + 1;
  iVar3 = (**(code **)(*(longlong *)*plVar2 + 0x40))
                    ((longlong *)*plVar2,&local_4e8,local_4f8,&local_4e4);
  if (iVar3 < 0) {
    FUN_180002a20(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\HappSel.cpp",0xe0f);
    LogMessage(local_438,2,1);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4e0);
  iVar3 = (int)plVar2[1] + iVar8;
  if (((local_4e8 < iVar3) && (-1 < local_4f8[0])) && (local_4f8[0] + local_4e8 < iVar3)) {
LAB_18002a7f5:
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4f0);
    pCVar5 = FUN_180020fe0((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_4d8,10);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4f0,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar5);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4d8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4e0,
               (char *)CONCAT44(uStack_4ec,local_4f0),(ulonglong)uVar10);
    MMAfxMessageBox(local_4e0,0x40,-1,0);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4f0);
LAB_18002a953:
    pCVar13 = (CPtrArray *)0x80004005;
  }
  else {
    iVar1 = *(int *)((longlong)plVar2 + 0xc) + uVar10;
    if (((local_4e4 < iVar1) && (-1 < local_4f4)) && (local_4f4 + local_4e4 < iVar1))
    goto LAB_18002a7f5;
    if (((local_4e8 != (int)plVar2[1]) || (iVar8 != 1)) &&
       (((local_4e4 != *(int *)((longlong)plVar2 + 0xc) || (uVar10 != 1)) &&
        ((local_4e8 < iVar3 || (local_4e4 < iVar1)))))) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4f0);
      pCVar5 = FUN_180020fe0((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_4d0,0xc);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4f0,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar5
                );
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4d0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4e0,
                 (char *)CONCAT44(uStack_4ec,local_4f0),(ulonglong)uVar10);
      iVar3 = MMAfxMessageBox(local_4e0,0x24,-1,0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4f0);
      lVar12 = local_4d8;
      if (iVar3 != 7) goto LAB_18002a990;
      goto LAB_18002a953;
    }
LAB_18002a990:
    if (*(longlong *)(lVar12 + 0x40) != 0) {
      FUN_180002a20(local_438,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\HappSel.cpp",0xe3d);
      LogMessage(local_438,2,1);
    }
    local_4c8 = 0;
    lVar11 = (longlong)(int)uVar10;
    local_4d0 = lVar11;
    CPtrArray::SetSize((CPtrArray *)(lVar12 + 0x30),lVar11,-1);
    local_4f0 = 0;
    lVar12 = (longlong)iVar8;
    pCVar4 = pCVar13;
    if (0 < lVar11) {
      do {
        local_4c0 = operator_new(0x28);
        pCVar6 = pCVar13;
        if (local_4c0 != (CPtrArray *)0x0) {
          pCVar6 = (CPtrArray *)CPtrArray::CPtrArray(local_4c0);
        }
        CPtrArray::SetSize(pCVar6,lVar12,-1);
        pCVar7 = pCVar13;
        pCVar9 = pCVar13;
        if (0 < lVar12) {
          do {
            (**(code **)(*(longlong *)*plVar2 + 0x38))
                      ((longlong *)*plVar2,(int)plVar2[1] + (int)pCVar9,
                       local_4f0 + *(int *)((longlong)plVar2 + 0xc),(short)plVar2[2]);
            if (((longlong)pCVar7 < 0) || (*(longlong *)(pCVar6 + 0x10) <= (longlong)pCVar7))
            goto LAB_18002ab41;
            *(undefined8 *)(*(longlong *)(pCVar6 + 8) + (longlong)pCVar7 * 8) = local_4c8;
            pCVar9 = (CPtrArray *)(ulonglong)((int)pCVar9 + 1);
            pCVar7 = pCVar7 + 1;
          } while ((longlong)pCVar7 < lVar12);
        }
        lVar11 = *(longlong *)(pCVar6 + 0x10);
        pCVar7 = pCVar13;
        pCVar9 = pCVar13;
        if (0 < lVar11) {
          do {
            iVar8 = (int)pCVar9;
            if (((longlong)pCVar7 < 0) || (lVar11 <= (longlong)pCVar7)) goto LAB_18002ab41;
            if (*(longlong *)(*(longlong *)(pCVar6 + 8) + (longlong)pCVar7 * 8) == 0) {
              CPtrArray::RemoveAt(pCVar6,(longlong)iVar8,1);
              iVar8 = iVar8 + -1;
              pCVar7 = pCVar7 + -1;
            }
            pCVar9 = (CPtrArray *)(ulonglong)(iVar8 + 1U);
            pCVar7 = pCVar7 + 1;
            lVar11 = *(longlong *)(pCVar6 + 0x10);
          } while ((int)(iVar8 + 1U) < lVar11);
        }
        if (((longlong)pCVar4 < 0) || (*(longlong *)(local_4d8 + 0x40) <= (longlong)pCVar4)) {
LAB_18002ab41:
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        *(CPtrArray **)(*(longlong *)(local_4d8 + 0x38) + (longlong)pCVar4 * 8) = pCVar6;
        local_4f0 = local_4f0 + 1;
        pCVar4 = pCVar4 + 1;
      } while ((longlong)pCVar4 < local_4d0);
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4e0);
LAB_18002a965:
  CDWordArray::~CDWordArray(local_4b8);
  CDWordArray::~CDWordArray(local_490);
  CStringArray::~CStringArray(local_468);
  return pCVar13;
}

/* ---- FUNC 0002AB50 FUN_18002ab50 (171 bytes) ---- */

HRESULT FUN_18002ab50(void *param_1,DISPID param_2,undefined8 param_3,undefined8 param_4,
                     WORD param_5,DISPPARAMS *param_6,VARIANT *param_7,EXCEPINFO *param_8,
                     UINT *param_9)

{
  undefined8 uVar1;
  BSTR pOVar2;
  PVOID pvVar3;
  HRESULT HVar4;
  
  *(undefined4 *)((longlong)param_1 + 0x88) = 0;
  HVar4 = DispInvoke(param_1,*(ITypeInfo **)((longlong)param_1 + 0x18),param_2,param_5,param_6,
                     param_7,param_8,param_9);
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

/* ---- FUNC 0002AC00 FUN_18002ac00 (173 bytes) ---- */

undefined4 FUN_18002ac00(longlong param_1,undefined8 *param_2)

{
  int iVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  undefined4 uVar2;
  bool bVar3;
  longlong *local_res18;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res20 [8];
  
  uVar2 = 0;
  bVar3 = false;
  if (*(int *)(param_1 + 0x30) != 3) {
    return 0;
  }
  iVar1 = (**(code **)*param_2)(param_2,&DAT_180063400,&local_res18);
  if (-1 < iVar1) {
    if (local_res18[0xc] == *(longlong *)(param_1 + 0x28)) {
      this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                       ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                        (local_res18 + 0x3b),(int)local_res20);
      bVar3 = true;
      iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        (this,*(char **)(param_1 + 0x18));
      uVar2 = 0;
      if (iVar1 == 0) {
        uVar2 = 1;
      }
    }
    if (bVar3) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20);
    }
    (**(code **)(*local_res18 + 0x10))();
  }
  return uVar2;
}

/* ---- FUNC 0002ACB0 FUN_18002acb0 (166 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18002acb0(longlong *param_1)

{
  longlong *plVar1;
  undefined1 auStack_428 [32];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_180077818 ^ (ulonglong)auStack_428;
  plVar1 = FUN_180011370(param_1[1],param_1 + 2);
  if (plVar1 == (longlong *)0x0) {
    FUN_18000e960(param_1[1],param_1);
  }
  else {
    if (plVar1 != param_1) {
      FUN_180002a20(local_408,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\HappSel.cpp",0x838);
      LogMessage(local_408,2,1);
    }
    (**(code **)(*plVar1 + 0x10))(plVar1);
  }
  return;
}

/* ---- FUNC 0002AD60 FUN_18002ad60 (743 bytes) ---- */

CPtrArray * FUN_18002ad60(longlong param_1,IStream *param_2)

{
  IStreamVtbl *pIVar1;
  HRESULT HVar2;
  uint uVar3;
  char *pv;
  CPtrArray *pCVar4;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar5;
  CPtrArray *pCVar6;
  CPtrArray *pCVar7;
  CPtrArray *pCVar8;
  CPtrArray *pCVar9;
  CPtrArray *pCVar10;
  longlong local_res8;
  ULONG local_res10 [2];
  ULONG local_res18 [2];
  int local_res20 [2];
  longlong *local_78;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_70 [8];
  CPtrArray *local_68;
  undefined8 local_60 [4];
  
  pCVar6 = (CPtrArray *)0x0;
  local_res20[0] = 0;
  local_res18[0] = 0;
  local_res10[0] = 0;
  local_res8 = param_1;
  HVar2 = (*param_2->lpVtbl->Read)(param_2,(void *)(param_1 + 0x80),4,local_res10);
  if ((((HVar2 < 0) || (local_res10[0] != 4)) ||
      (HVar2 = (*param_2->lpVtbl->Read)(param_2,local_res18,4,local_res10), HVar2 < 0)) ||
     (local_res10[0] != 4)) {
    return (CPtrArray *)0x80004005;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_70);
  pIVar1 = param_2->lpVtbl;
  pv = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)local_70,local_res18[0]);
  HVar2 = (*pIVar1->Read)(param_2,pv,local_res18[0],local_res10);
  ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)local_70,-1);
  if ((HVar2 < 0) || (local_res10[0] != local_res18[0])) {
    pCVar7 = (CPtrArray *)0x80004005;
    goto LAB_18002b01d;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x18),
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)local_70);
  *(undefined4 *)(param_1 + 8) = 0x10;
  FUN_1800255a0(local_60);
  HVar2 = (*param_2->lpVtbl->Read)(param_2,local_res18,4,local_res10);
  if ((HVar2 < 0) || (local_res10[0] != 4)) {
LAB_18002b004:
    uVar3 = 0x80004005;
LAB_18002b009:
    pCVar7 = (CPtrArray *)(ulonglong)uVar3;
  }
  else {
    pCVar7 = pCVar6;
    if (local_res18[0] == 0) {
      uVar3 = FUN_18002b260((longlong)local_60,param_2,&local_78,0);
      if ((int)uVar3 < 0) goto LAB_18002b009;
      pCVar4 = operator_new(0x60);
      local_68 = pCVar4;
      if (pCVar4 != (CPtrArray *)0x0) {
        pCVar5 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                 CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                           ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_res8,"VBSelect");
        local_res20[0] = 1;
        pCVar6 = (CPtrArray *)
                 FUN_1800255c0((undefined8 *)pCVar4,pCVar5,local_78,0,(undefined8 *)0x0);
      }
      *(CPtrArray **)(param_1 + 0x28) = pCVar6;
      if (pCVar4 != (CPtrArray *)0x0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
      }
      (**(code **)(*local_78 + 0x10))();
    }
    else {
      CPtrArray::SetSize((CPtrArray *)(param_1 + 0x30),(ulonglong)local_res18[0],-1);
      pCVar4 = pCVar6;
      pCVar10 = pCVar6;
      if (0 < (int)local_res18[0]) {
        do {
          local_res20[0] = 0;
          (*param_2->lpVtbl->Read)(param_2,local_res20,4,local_res10);
          if (local_res10[0] != 4) goto LAB_18002b004;
          local_68 = operator_new(0x28);
          pCVar7 = pCVar6;
          if (local_68 != (CPtrArray *)0x0) {
            pCVar7 = (CPtrArray *)CPtrArray::CPtrArray(local_68);
          }
          CPtrArray::SetSize(pCVar7,(longlong)local_res20[0],-1);
          pCVar8 = pCVar6;
          pCVar9 = pCVar6;
          if (0 < local_res20[0]) {
            while (uVar3 = FUN_18002b260((longlong)local_60,param_2,&local_78,0), -1 < (int)uVar3) {
              if (((longlong)pCVar8 < 0) || (*(longlong *)(pCVar7 + 0x10) <= (longlong)pCVar8))
              goto LAB_18002b042;
              *(longlong **)(*(longlong *)(pCVar7 + 8) + (longlong)pCVar8 * 8) = local_78;
              uVar3 = (int)pCVar9 + 1;
              pCVar9 = (CPtrArray *)(ulonglong)uVar3;
              pCVar8 = pCVar8 + 1;
              if (local_res20[0] <= (int)uVar3) goto LAB_18002afdc;
            }
            goto LAB_18002b009;
          }
LAB_18002afdc:
          if (((longlong)pCVar10 < 0) || (*(longlong *)(local_res8 + 0x40) <= (longlong)pCVar10)) {
LAB_18002b042:
                    /* WARNING: Subroutine does not return */
            AfxThrowInvalidArgException();
          }
          *(CPtrArray **)(*(longlong *)(local_res8 + 0x38) + (longlong)pCVar10 * 8) = pCVar7;
          uVar3 = (int)pCVar4 + 1;
          pCVar4 = (CPtrArray *)(ulonglong)uVar3;
          pCVar10 = pCVar10 + 1;
          pCVar7 = (CPtrArray *)0x0;
        } while ((int)uVar3 < (int)local_res18[0]);
      }
    }
  }
  FUN_180025a20(local_60);
LAB_18002b01d:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_70);
  return pCVar7;
}

/* ---- FUNC 0002B050 FUN_18002b050 (522 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_18002b050(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined1 auStack_468 [32];
  int local_448;
  int local_444;
  int local_440 [2];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_438 [16];
  undefined1 local_428 [1008];
  ulonglong local_38;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStack_468;
  if (*(longlong *)(param_1 + 0xf0) != 0) {
    FUN_180002a20(local_428,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\HappSel.cpp",0x85a);
    LogMessage(local_428,2,1);
  }
  iVar2 = (**(code **)(*param_2 + 0x18))(param_2,&local_444,4,&local_448);
  if ((-1 < iVar2) && (local_448 == 4)) {
    lVar1 = *param_2;
    pcVar4 = ATL::CSimpleStringT<char,1>::GetBufferSetLength
                       ((CSimpleStringT<char,1> *)(param_1 + 0x10),local_444);
    iVar2 = (**(code **)(lVar1 + 0x18))(param_2,pcVar4,local_444,&local_448);
    if ((-1 < iVar2) && (local_448 == local_444)) {
      ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)(param_1 + 0x10),-1);
      iVar2 = (**(code **)(*param_2 + 0x18))(param_2,local_440,4,&local_448);
      if ((-1 < iVar2) && (local_448 == 4)) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_438);
        uVar5 = 0;
        iVar2 = 0;
        if (0 < local_440[0]) {
          do {
            iVar3 = (**(code **)(*param_2 + 0x18))(param_2,&local_444,4,&local_448);
            if ((iVar3 < 0) || (local_448 != 4)) {
LAB_18002b227:
              uVar5 = 0x80004005;
              goto LAB_18002b217;
            }
            lVar1 = *param_2;
            pcVar4 = ATL::CSimpleStringT<char,1>::GetBufferSetLength
                               ((CSimpleStringT<char,1> *)local_438,local_444);
            iVar3 = (**(code **)(lVar1 + 0x18))(param_2,pcVar4,local_444,&local_448);
            if ((iVar3 < 0) || (local_448 != local_444)) goto LAB_18002b227;
            ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)local_438,-1);
            CStringArray::SetAtGrow
                      ((CStringArray *)(param_1 + 0xe0),*(__int64 *)(param_1 + 0xf0),local_438);
            iVar2 = iVar2 + 1;
          } while (iVar2 < local_440[0]);
        }
        *(undefined4 *)(param_1 + 0x108) = 1;
LAB_18002b217:
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_438);
        return uVar5;
      }
    }
  }
  return 0x80004005;
}

/* ---- FUNC 0002B260 FUN_18002b260 (273 bytes) ---- */

HRESULT FUN_18002b260(longlong param_1,LPSTREAM param_2,undefined8 param_3,longlong param_4)

{
  LPBC *ppbc;
  HRESULT HVar1;
  int local_res8 [2];
  longlong *local_res10;
  longlong *local_28 [2];
  
  HVar1 = 0;
  ppbc = (LPBC *)(param_1 + 8);
  if (*ppbc == (LPBC)0x0) {
    CreateBindCtx(0,ppbc);
  }
  (*param_2->lpVtbl->Read)(param_2,local_res8,4,(ULONG *)0x0);
  if ((local_res8[0] != 0) &&
     (HVar1 = OleLoadFromStream(param_2,(IID *)&DAT_180066d18,&local_res10), -1 < HVar1)) {
    HVar1 = (**(code **)(**(longlong **)(DAT_1800797f0 + 0x118) + 0x58))
                      (*(longlong **)(DAT_1800797f0 + 0x118),local_res10,0,local_28);
    if (-1 < HVar1) {
      HVar1 = (**(code **)(*local_28[0] + 0x40))(local_28[0],*ppbc,0,&DAT_180063400,param_3);
      if (((HVar1 < 0) && (param_4 != 0)) &&
         (HVar1 = (**(code **)(*local_res10 + 0xa0))(local_res10,*ppbc,0,param_4), -1 < HVar1)) {
        HVar1 = 1;
      }
      (**(code **)(*local_res10 + 0x10))();
      local_res10 = local_28[0];
    }
    (**(code **)(*local_res10 + 0x10))();
  }
  return HVar1;
}

/* ---- FUNC 0002B380 FUN_18002b380 (1379 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18002b380(undefined8 *param_1,longlong param_2,int *param_3)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  HRESULT HVar4;
  char *pcVar5;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar6;
  longlong lVar7;
  longlong lVar8;
  LPCSTR pCVar9;
  undefined8 *puVar10;
  CPtrArray *pCVar11;
  CPtrArray *this;
  short *psVar12;
  CPtrArray *pCVar13;
  CPtrArray *pCVar14;
  LPWSTR lpWideCharStr;
  undefined1 auStackY_2d8 [32];
  IBindCtx *local_2a8;
  int local_2a0;
  IMoniker *local_298;
  longlong *local_290;
  int *local_288;
  ULONG local_280 [2];
  uint local_278 [2];
  longlong local_270;
  undefined8 *local_268;
  short *local_260;
  CPtrArray *local_258;
  OLECHAR local_248;
  WCHAR local_246 [255];
  ulonglong local_48;
  
  local_48 = DAT_180077818 ^ (ulonglong)auStackY_2d8;
  pCVar11 = (CPtrArray *)0x0;
  local_2a0 = 0;
  local_288 = param_3;
  local_270 = param_2;
  local_268 = param_1;
  pcVar5 = FUN_180030d80(param_2,param_3);
  if (pcVar5 != (char *)0x0) {
    lVar7 = -1;
    do {
      lVar8 = lVar7;
      lVar7 = lVar8 + 1;
    } while (pcVar5[lVar7] != '\0');
    pcVar5[lVar8] = '\0';
    iVar2 = strncmp(pcVar5,"usegridtext = ",0xe);
    if (iVar2 == 0) {
      iVar2 = atoi(pcVar5 + 0xe);
      *(int *)(param_1 + 0x10) = iVar2;
      pcVar5 = FUN_180030d80(param_2,param_3);
      if (pcVar5 != (char *)0x0) {
        lVar7 = -1;
        do {
          lVar8 = lVar7;
          lVar7 = lVar8 + 1;
        } while (pcVar5[lVar7] != '\0');
        pcVar5[lVar8] = '\0';
        pCVar6 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                 CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                           ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            local_278,pcVar5);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 3),
                   pCVar6);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_278);
        *(undefined4 *)(param_1 + 1) = 0x10;
        CreateBindCtx(0,&local_2a8);
        iVar2 = (**(code **)(**(longlong **)(param_1[2] + 0x118) + 0xa0))
                          (*(longlong **)(param_1[2] + 0x118),local_2a8,0,&local_260);
        if (-1 < iVar2) {
          psVar12 = local_260;
          do {
            sVar1 = *psVar12;
            *(short *)(((longlong)&local_248 - (longlong)local_260) + (longlong)psVar12) = sVar1;
            psVar12 = psVar12 + 1;
          } while (sVar1 != 0);
          CoTaskMemFree(local_260);
          lVar7 = -1;
          do {
            lVar8 = lVar7;
            lVar7 = lVar8 + 1;
          } while ((&local_248)[lVar7] != L'\0');
          (&local_248)[lVar7] = L'!';
          lVar8 = lVar8 + 2;
          if (0x1ff < (ulonglong)(lVar8 * 2)) {
                    /* WARNING: Subroutine does not return */
            FUN_18005c254();
          }
          lpWideCharStr = &local_248 + lVar8;
          *lpWideCharStr = L'\0';
          pcVar5 = FUN_180030d80(param_2,param_3);
          if ((pcVar5 != (char *)0x0) && (iVar2 = strncmp(pcVar5,"linkto = ",9), iVar2 == 0)) {
            uVar3 = atoi(pcVar5 + 9);
            local_278[0] = uVar3;
            if (uVar3 != 0) {
              CPtrArray::SetSize((CPtrArray *)(param_1 + 6),(ulonglong)uVar3,-1);
              local_2a0 = 0;
              pCVar14 = pCVar11;
              if (0 < (int)uVar3) {
                do {
                  pcVar5 = FUN_180030d80(param_2,param_3);
                  if ((pcVar5 == (char *)0x0) || (iVar2 = strncmp(pcVar5,"size = ",7), iVar2 != 0))
                  goto LAB_18002b4c1;
                  iVar2 = atoi(pcVar5 + 7);
                  local_258 = operator_new(0x28);
                  this = pCVar11;
                  if (local_258 != (CPtrArray *)0x0) {
                    this = (CPtrArray *)CPtrArray::CPtrArray(local_258);
                  }
                  CPtrArray::SetSize(this,(longlong)iVar2,-1);
                  pCVar13 = pCVar11;
                  if (0 < iVar2) {
                    while (pCVar9 = FUN_180030d80(local_270,local_288), pCVar9 != (LPCSTR)0x0) {
                      lVar7 = -1;
                      do {
                        lVar8 = lVar7;
                        lVar7 = lVar8 + 1;
                      } while (pCVar9[lVar7] != '\0');
                      pCVar9[lVar8] = '\0';
                      lVar7 = -1;
                      do {
                        lVar7 = lVar7 + 1;
                      } while (pCVar9[lVar7] != '\0');
                      if (lpWideCharStr != (LPWSTR)0x0) {
                        *lpWideCharStr = L'\0';
                        MultiByteToWideChar(0,0,pCVar9,-1,lpWideCharStr,(int)lVar7 + 1);
                      }
                      HVar4 = MkParseDisplayName(local_2a8,&local_248,local_280,&local_298);
                      if (HVar4 < 0) break;
                      HVar4 = (*local_298->lpVtbl->BindToObject)
                                        (local_298,local_2a8,(IMoniker *)0x0,(IID *)&DAT_180063400,
                                         &local_290);
                      (*local_298->lpVtbl->Release)(local_298);
                      if (HVar4 < 0) break;
                      if (((longlong)pCVar13 < 0) ||
                         (*(longlong *)(this + 0x10) <= (longlong)pCVar13)) goto LAB_18002b8d8;
                      *(longlong **)(*(longlong *)(this + 8) + (longlong)pCVar13 * 8) = local_290;
                      pCVar13 = pCVar13 + 1;
                      if ((longlong)iVar2 <= (longlong)pCVar13) goto LAB_18002b89a;
                    }
                    goto LAB_18002b4c1;
                  }
LAB_18002b89a:
                  if (((longlong)pCVar14 < 0) || ((longlong)local_268[8] <= (longlong)pCVar14)) {
LAB_18002b8d8:
                    /* WARNING: Subroutine does not return */
                    AfxThrowInvalidArgException();
                  }
                  *(CPtrArray **)(local_268[7] + (longlong)pCVar14 * 8) = this;
                  local_2a0 = local_2a0 + 1;
                  pCVar14 = pCVar14 + 1;
                  param_2 = local_270;
                  param_3 = local_288;
                } while (local_2a0 < (int)local_278[0]);
              }
LAB_18002b6e4:
              (*local_2a8->lpVtbl->Release)(local_2a8);
              return 0;
            }
            pCVar9 = FUN_180030d80(param_2,param_3);
            if (pCVar9 != (LPCSTR)0x0) {
              lVar7 = -1;
              do {
                lVar8 = lVar7;
                lVar7 = lVar8 + 1;
              } while (pCVar9[lVar7] != '\0');
              pCVar9[lVar8] = '\0';
              lVar7 = -1;
              do {
                lVar7 = lVar7 + 1;
              } while (pCVar9[lVar7] != '\0');
              if (lpWideCharStr != (LPWSTR)0x0) {
                *lpWideCharStr = L'\0';
                MultiByteToWideChar(0,0,pCVar9,-1,lpWideCharStr,(int)lVar7 + 1);
              }
              HVar4 = MkParseDisplayName(local_2a8,&local_248,local_280,&local_298);
              if (-1 < HVar4) {
                HVar4 = (*local_298->lpVtbl->BindToObject)
                                  (local_298,local_2a8,(IMoniker *)0x0,(IID *)&DAT_180063400,
                                   &local_290);
                (*local_298->lpVtbl->Release)(local_298);
                if (-1 < HVar4) {
                  puVar10 = operator_new(0x60);
                  local_268 = puVar10;
                  if (puVar10 != (undefined8 *)0x0) {
                    pCVar6 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                              *)ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                                CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                            *)&local_288,"VBSelect");
                    local_2a0 = 1;
                    pCVar11 = (CPtrArray *)
                              FUN_1800255c0(puVar10,pCVar6,local_290,0,(undefined8 *)0x0);
                  }
                  param_1[5] = pCVar11;
                  if (puVar10 != (undefined8 *)0x0) {
                    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &local_288);
                  }
                  (**(code **)(*local_290 + 0x10))();
                  goto LAB_18002b6e4;
                }
              }
            }
          }
        }
LAB_18002b4c1:
        (*local_2a8->lpVtbl->Release)(local_2a8);
      }
    }
  }
  return 0x80004005;
}

/* ---- FUNC 0002B8F0 FUN_18002b8f0 (225 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18002b8f0(longlong param_1,longlong *param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined1 auStack_628 [31];
  char acStack_609 [9];
  char local_600 [504];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_180077818 ^ (ulonglong)auStack_628;
  if (*(longlong *)(param_1 + 0xf0) != 0) {
    FUN_180002a20(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\HappSel.cpp",0x89f);
    LogMessage(local_408,2,1);
  }
  FUN_180020f00(param_2,acStack_609 + 1);
  lVar2 = -1;
  do {
    lVar5 = lVar2;
    lVar2 = lVar5 + 1;
  } while (acStack_609[lVar5 + 2] != '\0');
  acStack_609[lVar5 + 1] = '\0';
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x10),
             acStack_609 + 1);
  FUN_180020f00(param_2,acStack_609 + 1);
  iVar3 = strncmp(acStack_609 + 1,"count = ",8);
  if (iVar3 == 0) {
    uVar4 = atoi(local_600);
    if (0 < (int)uVar4) {
      uVar8 = (ulonglong)uVar4;
      do {
        FUN_180020f00(param_2,acStack_609 + 1);
        uVar1 = 0xffffffffffffffff;
        do {
          uVar7 = uVar1;
          uVar1 = uVar7 + 1;
        } while (acStack_609[uVar7 + 2] != '\0');
        if (1 < uVar7 + 1) {
          acStack_609[uVar7 + 1] = '\0';
          CStringArray::SetAtGrow
                    ((CStringArray *)(param_1 + 0xe0),*(__int64 *)(param_1 + 0xf0),acStack_609 + 1);
        }
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
    }
    *(undefined4 *)(param_1 + 0x108) = 1;
    uVar6 = 0;
  }
  else {
    uVar6 = 0x80004005;
  }
  return uVar6;
}

/* ---- FUNC 0002B9D1 FUN_18002b9d1 (102 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18002b9d1(void)

{
  ulonglong uVar1;
  uint in_EAX;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong *unaff_RSI;
  longlong unaff_RDI;
  char acStackX_1f [9];
  
  uVar3 = (ulonglong)in_EAX;
  do {
    FUN_180020f00(unaff_RSI,acStackX_1f + 1);
    uVar1 = 0xffffffffffffffff;
    do {
      uVar2 = uVar1;
      uVar1 = uVar2 + 1;
    } while (acStackX_1f[uVar2 + 2] != '\0');
    if (1 < uVar2 + 1) {
      acStackX_1f[uVar2 + 1] = '\0';
      CStringArray::SetAtGrow
                ((CStringArray *)(unaff_RDI + 0xe0),*(__int64 *)(unaff_RDI + 0xf0),acStackX_1f + 1);
    }
    uVar3 = uVar3 - 1;
  } while (uVar3 != 0);
  *(undefined4 *)(unaff_RDI + 0x108) = 1;
  return 0;
}

/* ---- FUNC 0002BA37 FUN_18002ba37 (45 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18002ba37(void)

{
  longlong unaff_RDI;
  
  *(undefined4 *)(unaff_RDI + 0x108) = 1;
  return 0;
}

/* ---- FUNC 0002BA70 FUN_18002ba70 (135 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18002ba70(longlong param_1,short param_2)

{
  int iVar1;
  undefined1 auStack_428 [32];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_180077818 ^ (ulonglong)auStack_428;
  iVar1 = (int)param_2;
  if (*(int *)(param_1 + 0x10) == iVar1) {
    FUN_180002a20(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\HappSel.cpp",0x58e);
    LogMessage(local_408,2,1);
    *(int *)(param_1 + 0x10) = iVar1;
  }
  else {
    *(int *)(param_1 + 0x10) = iVar1;
  }
  return 0;
}

/* ---- FUNC 0002BB00 FUN_18002bb00 (9 bytes) ---- */

void FUN_18002bb00(longlong param_1,int param_2,int param_3)

{
  FUN_180018e30(*(IUnknown **)(param_1 + 8),param_2,param_3);
  return;
}

/* ---- FUNC 0002BB10 FUN_18002bb10 (20 bytes) ---- */

void FUN_18002bb10(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  
  plVar1 = *(longlong **)(param_1 + 0x68);
  *param_2 = (longlong)plVar1;
  if (plVar1 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00018002bb1f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar1 + 8))();
    return;
  }
  return;
}

/* ---- FUNC 0002BB30 FUN_18002bb30 (9 bytes) ---- */

void FUN_18002bb30(longlong param_1)

{
  FUN_180042810(param_1 + 0x18);
  return;
}

/* ---- FUNC 0002BB40 FUN_18002bb40 (137 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18002bb40(longlong param_1)

{
  undefined1 auStack_428 [32];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_180077818 ^ (ulonglong)auStack_428;
  if (*(int *)(param_1 + 8) == 4) {
    if (*(longlong *)(param_1 + 0x68) == 0) {
      FUN_180002a20(local_408,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\HappSel.cpp",0x1117);
      LogMessage(local_408,2,1);
    }
    (**(code **)(*DAT_180079800 + 0xf0))(DAT_180079800,param_1);
  }
  return;
}

/* ---- FUNC 0002BBD0 FUN_18002bbd0 (28 bytes) ---- */

void FUN_18002bbd0(undefined8 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018002bbe5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_180079800 + 0xe8))(DAT_180079800,1,param_1);
  return;
}

/* ---- FUNC 0002BBF0 FUN_18002bbf0 (88 bytes) ---- */

void FUN_18002bbf0(undefined8 param_1,HGLOBAL param_2,CStringArray *param_3,CDWordArray *param_4,
                  CDWordArray *param_5)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  longlong lVar9;
  char *pcVar10;
  ulong uVar11;
  ulong uVar12;
  char cVar13;
  
  uVar11 = 0;
  uVar12 = 0;
  pcVar5 = GlobalLock(param_2);
  pcVar5 = _strdup(pcVar5);
  lVar9 = -1;
  do {
    lVar9 = lVar9 + 1;
  } while (pcVar5[lVar9] != '\0');
  pcVar10 = pcVar5 + lVar9;
  pcVar8 = pcVar5;
  if (pcVar5 < pcVar10) {
    do {
      cVar13 = '\0';
      bVar3 = false;
      bVar2 = true;
      pcVar6 = pcVar8;
      do {
        cVar1 = *pcVar6;
        if (cVar1 != '\r') {
          if (cVar1 == '\n') goto LAB_18002bc96;
          if (cVar1 != '\t') goto LAB_18002bc8c;
LAB_18002bca0:
          *pcVar6 = '\0';
          cVar13 = cVar1;
          break;
        }
        if (pcVar6[1] != '\n') {
LAB_18002bc96:
          if (bVar2) {
            bVar3 = true;
          }
          goto LAB_18002bca0;
        }
        bVar2 = false;
        *pcVar6 = ' ';
LAB_18002bc8c:
        pcVar6 = pcVar6 + 1;
      } while (pcVar6 < pcVar10);
      pcVar7 = pcVar6 + -1;
      iVar4 = _ismbcspace((int)pcVar6[-1]);
      while ((iVar4 != 0 && (pcVar8 <= pcVar7))) {
        *pcVar7 = '\0';
        pcVar7 = pcVar7 + -1;
        iVar4 = _ismbcspace((int)*pcVar7);
      }
      CStringArray::SetAtGrow(param_3,*(__int64 *)(param_3 + 0x10),pcVar8);
      CDWordArray::SetAtGrow(param_4,*(__int64 *)(param_4 + 0x10),uVar11);
      CDWordArray::SetAtGrow(param_5,*(__int64 *)(param_5 + 0x10),uVar12);
      if ((cVar13 == '\n') || (cVar13 == '\r')) {
        uVar11 = 0;
        uVar12 = uVar12 + 1;
      }
      else if (cVar13 == '\t') {
        uVar11 = uVar11 + 1;
      }
      pcVar8 = pcVar6 + 1;
    } while (pcVar6 + 1 < pcVar10);
    if (bVar3) {
      CStringArray::SetAtGrow(param_3,*(__int64 *)(param_3 + 0x10),"");
      CDWordArray::SetAtGrow(param_4,*(__int64 *)(param_4 + 0x10),uVar11);
      CDWordArray::SetAtGrow(param_5,*(__int64 *)(param_5 + 0x10),uVar12);
    }
  }
  free(pcVar5);
                    /* WARNING: Could not recover jumptable at 0x00018002bdb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GlobalUnlock(param_2);
  return;
}

/* ---- FUNC 0002BC48 FUN_18002bc48 (16 bytes) ---- */

void FUN_18002bc48(void)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *unaff_RSI;
  char *unaff_RDI;
  ulong unaff_R12D;
  ulong unaff_R13D;
  char cVar7;
  void *pvStackX_20;
  HGLOBAL in_stack_00000078;
  CStringArray *in_stack_00000080;
  CDWordArray *in_stack_00000088;
  CDWordArray *in_stack_00000090;
  
  do {
    cVar7 = '\0';
    bVar3 = false;
    bVar2 = true;
    pcVar5 = unaff_RSI;
    do {
      cVar1 = *pcVar5;
      if (cVar1 != '\r') {
        if (cVar1 == '\n') goto LAB_18002bc96;
        if (cVar1 != '\t') goto LAB_18002bc8c;
LAB_18002bca0:
        *pcVar5 = '\0';
        cVar7 = cVar1;
        break;
      }
      if (pcVar5[1] != '\n') {
LAB_18002bc96:
        if (bVar2) {
          bVar3 = true;
        }
        goto LAB_18002bca0;
      }
      bVar2 = false;
      *pcVar5 = ' ';
LAB_18002bc8c:
      pcVar5 = pcVar5 + 1;
    } while (pcVar5 < unaff_RDI);
    pcVar6 = pcVar5 + -1;
    iVar4 = _ismbcspace((int)pcVar5[-1]);
    while ((iVar4 != 0 && (unaff_RSI <= pcVar6))) {
      *pcVar6 = '\0';
      pcVar6 = pcVar6 + -1;
      iVar4 = _ismbcspace((int)*pcVar6);
    }
    CStringArray::SetAtGrow(in_stack_00000080,*(__int64 *)(in_stack_00000080 + 0x10),unaff_RSI);
    CDWordArray::SetAtGrow(in_stack_00000088,*(__int64 *)(in_stack_00000088 + 0x10),unaff_R12D);
    CDWordArray::SetAtGrow(in_stack_00000090,*(__int64 *)(in_stack_00000090 + 0x10),unaff_R13D);
    if ((cVar7 == '\n') || (cVar7 == '\r')) {
      unaff_R12D = 0;
      unaff_R13D = unaff_R13D + 1;
    }
    else if (cVar7 == '\t') {
      unaff_R12D = unaff_R12D + 1;
    }
    unaff_RSI = pcVar5 + 1;
    if (unaff_RDI <= pcVar5 + 1) {
      if (bVar3) {
        CStringArray::SetAtGrow(in_stack_00000080,*(__int64 *)(in_stack_00000080 + 0x10),"");
        CDWordArray::SetAtGrow(in_stack_00000088,*(__int64 *)(in_stack_00000088 + 0x10),unaff_R12D);
        CDWordArray::SetAtGrow(in_stack_00000090,*(__int64 *)(in_stack_00000090 + 0x10),unaff_R13D);
      }
      free(pvStackX_20);
                    /* WARNING: Could not recover jumptable at 0x00018002bdb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      GlobalUnlock(in_stack_00000078);
      return;
    }
  } while( true );
}

/* ---- FUNC 0002BC58 FUN_18002bc58 (256 bytes) ---- */

void FUN_18002bc58(undefined8 param_1,undefined8 param_2,char param_3)

{
  char cVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *unaff_RSI;
  char *unaff_RDI;
  ulong unaff_R12D;
  ulong unaff_R13D;
  char cVar7;
  char cVar8;
  void *pvStackX_20;
  HGLOBAL in_stack_00000078;
  CStringArray *in_stack_00000080;
  CDWordArray *in_stack_00000088;
  CDWordArray *in_stack_00000090;
  
  do {
    cVar7 = '\0';
    cVar8 = '\0';
    bVar2 = true;
    pcVar5 = unaff_RSI;
    do {
      cVar1 = *pcVar5;
      cVar3 = '\0';
      if (cVar1 != '\r') {
        if (cVar1 == '\n') goto LAB_18002bc96;
        if (cVar1 != '\t') goto LAB_18002bc8c;
LAB_18002bca0:
        cVar8 = cVar3;
        *pcVar5 = '\0';
        cVar7 = cVar1;
        break;
      }
      if (pcVar5[1] != '\n') {
LAB_18002bc96:
        if (bVar2) {
          cVar3 = param_3;
        }
        goto LAB_18002bca0;
      }
      bVar2 = false;
      *pcVar5 = ' ';
LAB_18002bc8c:
      pcVar5 = pcVar5 + 1;
    } while (pcVar5 < unaff_RDI);
    pcVar6 = pcVar5 + -1;
    iVar4 = _ismbcspace((int)pcVar5[-1]);
    while ((iVar4 != 0 && (unaff_RSI <= pcVar6))) {
      *pcVar6 = '\0';
      pcVar6 = pcVar6 + -1;
      iVar4 = _ismbcspace((int)*pcVar6);
    }
    CStringArray::SetAtGrow(in_stack_00000080,*(__int64 *)(in_stack_00000080 + 0x10),unaff_RSI);
    CDWordArray::SetAtGrow(in_stack_00000088,*(__int64 *)(in_stack_00000088 + 0x10),unaff_R12D);
    CDWordArray::SetAtGrow(in_stack_00000090,*(__int64 *)(in_stack_00000090 + 0x10),unaff_R13D);
    if ((cVar7 == '\n') || (cVar7 == '\r')) {
      unaff_R12D = 0;
      unaff_R13D = unaff_R13D + 1;
    }
    else if (cVar7 == '\t') {
      unaff_R12D = unaff_R12D + 1;
    }
    param_3 = '\x01';
    unaff_RSI = pcVar5 + 1;
    if (unaff_RDI <= pcVar5 + 1) {
      if (cVar8 != '\0') {
        CStringArray::SetAtGrow(in_stack_00000080,*(__int64 *)(in_stack_00000080 + 0x10),"");
        CDWordArray::SetAtGrow(in_stack_00000088,*(__int64 *)(in_stack_00000088 + 0x10),unaff_R12D);
        CDWordArray::SetAtGrow(in_stack_00000090,*(__int64 *)(in_stack_00000090 + 0x10),unaff_R13D);
      }
      free(pvStackX_20);
                    /* WARNING: Could not recover jumptable at 0x00018002bdb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      GlobalUnlock(in_stack_00000078);
      return;
    }
  } while( true );
}

/* ---- FUNC 0002BD58 FUN_18002bd58 (72 bytes) ---- */

void FUN_18002bd58(void)

{
  CDWordArray *unaff_RBX;
  CDWordArray *unaff_RBP;
  ulong unaff_R12D;
  ulong unaff_R13D;
  void *pvStackX_20;
  HGLOBAL in_stack_00000078;
  CStringArray *in_stack_00000080;
  
  CStringArray::SetAtGrow(in_stack_00000080,*(__int64 *)(in_stack_00000080 + 0x10),"");
  CDWordArray::SetAtGrow(unaff_RBP,*(__int64 *)(unaff_RBP + 0x10),unaff_R12D);
  CDWordArray::SetAtGrow(unaff_RBX,*(__int64 *)(unaff_RBX + 0x10),unaff_R13D);
  free(pvStackX_20);
                    /* WARNING: Could not recover jumptable at 0x00018002bdb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GlobalUnlock(in_stack_00000078);
  return;
}

/* ---- FUNC 0002BDA0 FUN_18002bda0 (31 bytes) ---- */

void FUN_18002bda0(void)

{
  undefined4 in_EAX;
  undefined4 in_register_00000004;
  HGLOBAL in_stack_00000078;
  
  free((void *)CONCAT44(in_register_00000004,in_EAX));
                    /* WARNING: Could not recover jumptable at 0x00018002bdb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GlobalUnlock(in_stack_00000078);
  return;
}

/* ---- FUNC 0002BDC0 FUN_18002bdc0 (137 bytes) ---- */

undefined8 FUN_18002bdc0(longlong param_1,undefined2 *param_2)

{
  uint uVar1;
  longlong *plVar2;
  undefined8 uVar3;
  
  *param_2 = 0;
  if (*(longlong *)(param_1 + 0xb0) != 0) {
    if (*(longlong *)(param_1 + 0xb0) < 1) {
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
    if (((**(longlong **)(param_1 + 0xa8) != 0) &&
        (uVar1 = *(uint *)(**(longlong **)(param_1 + 0xa8) + 0x30), (uVar1 & 0xfffffffc) == 0)) &&
       (uVar1 != 1)) {
      plVar2 = FUN_180027a00(param_1);
      if (plVar2 != (longlong *)0x0) {
        uVar3 = FUN_18002be50((longlong)plVar2);
        if (-1 < (int)uVar3) {
          *param_2 = 0xffff;
        }
        (**(code **)(*plVar2 + 0x10))(plVar2);
      }
      return 0;
    }
  }
  return 1;
}

/* ---- FUNC 0002BE00 FUN_18002be00 (57 bytes) ---- */

undefined8 FUN_18002be00(longlong param_1)

{
  longlong *plVar1;
  undefined8 uVar2;
  undefined2 *unaff_RDI;
  
  plVar1 = FUN_180027a00(param_1);
  if (plVar1 != (longlong *)0x0) {
    uVar2 = FUN_18002be50((longlong)plVar1);
    if (-1 < (int)uVar2) {
      *unaff_RDI = 0xffff;
    }
    (**(code **)(*plVar1 + 0x10))(plVar1);
  }
  return 0;
}

/* ---- FUNC 0002BE39 FUN_18002be39 (11 bytes) ---- */

undefined8 FUN_18002be39(void)

{
  return 1;
}

/* ---- FUNC 0002BE50 FUN_18002be50 (589 bytes) ---- */

undefined8 FUN_18002be50(longlong param_1)

{
  longlong *plVar1;
  HRESULT HVar2;
  UINT UVar3;
  CPtrArray *pCVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  int iVar7;
  IDataObject *local_res10;
  BSTR local_res18;
  char *local_res20;
  IErrorInfo *local_68;
  STGMEDIUM local_60;
  FORMATETC local_48;
  
  iVar7 = 0;
  HVar2 = OleGetClipboard(&local_res10);
  if (HVar2 < 0) {
    return 0x80004005;
  }
  plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x28) + 0x38);
  if (((plVar1 == (longlong *)0x0) || (*plVar1 == 0)) ||
     ((-1 < (int)plVar1[1] && (-1 < *(int *)((longlong)plVar1 + 0xc))))) {
    UVar3 = RegisterClipboardFormatA("Grid Text");
    local_48.cfFormat = (CLIPFORMAT)UVar3;
    local_48.dwAspect = 1;
    local_48.ptd = (DVTARGETDEVICE *)0x0;
    local_48.tymed = 1;
    local_48.lindex = -1;
    HVar2 = (*local_res10->lpVtbl->GetData)(local_res10,&local_48,&local_60);
    if (HVar2 < 0) {
      UVar3 = RegisterClipboardFormatA("AP_Text");
      local_48.cfFormat = (CLIPFORMAT)UVar3;
      local_48.dwAspect = 1;
      local_48.ptd = (DVTARGETDEVICE *)0x0;
      local_48.tymed = 1;
      local_48.lindex = -1;
      HVar2 = (*local_res10->lpVtbl->GetData)(local_res10,&local_48,&local_60);
      if (HVar2 < 0) goto LAB_18002bf59;
      *(undefined4 *)(param_1 + 0x80) = 0;
    }
  }
  else {
    UVar3 = RegisterClipboardFormatA("AP_Text");
    local_48.cfFormat = (CLIPFORMAT)UVar3;
    local_48.dwAspect = 1;
    local_48.ptd = (DVTARGETDEVICE *)0x0;
    local_48.tymed = 1;
    local_48.lindex = -1;
    HVar2 = (*local_res10->lpVtbl->GetData)(local_res10,&local_48,&local_60);
    if (HVar2 < 0) {
LAB_18002bf59:
      local_48.cfFormat = 1;
      local_48.dwAspect = 1;
      local_48.ptd = (DVTARGETDEVICE *)0x0;
      local_48.tymed = 1;
      local_48.lindex = -1;
      HVar2 = (*local_res10->lpVtbl->GetData)(local_res10,&local_48,&local_60);
      *(undefined4 *)(param_1 + 0x80) = 0;
      if (HVar2 < 0) goto LAB_18002c07d;
    }
  }
  FUN_18003e370(-1);
  uVar6 = 0;
  if ((local_60.u.hBitmap != (HBITMAP)0x0) &&
     (pCVar4 = FUN_18002a620(param_1,local_60.u.hGlobal), uVar6 = 0, -1 < (int)pCVar4)) {
    uVar5 = FUN_18002c9d0(param_1,local_60.u.hGlobal,0);
    if ((int)uVar5 < 0) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
                 "Unable to paste supplied text.");
      local_68 = (IErrorInfo *)0x0;
      HVar2 = GetErrorInfo(0,&local_68);
      if ((-1 < HVar2) && (local_68 != (IErrorInfo *)0x0)) {
        local_res18 = (wchar_t *)0x0;
        HVar2 = (*local_68->lpVtbl->GetDescription)(local_68,&local_res18);
        if ((-1 < HVar2) && (local_res18 != (wchar_t *)0x0)) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
                     "\r\n\r\nReported error:\r\n  ");
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
                     local_res18);
          SysFreeString(local_res18);
        }
      }
      MMAfxMessageBox(local_res20,0x40,-1,0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
    }
    else {
      uVar6 = 1;
    }
  }
  iVar7 = (int)uVar6;
  ReleaseStgMedium(&local_60);
  FUN_18003e370(0);
LAB_18002c07d:
  (*local_res10->lpVtbl->Release)(local_res10);
  uVar6 = 0x80004005;
  if (iVar7 != 0) {
    uVar6 = 0;
  }
  return uVar6;
}

/* ---- FUNC 0002C0A0 FUN_18002c0a0 (489 bytes) ---- */

undefined8 FUN_18002c0a0(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  UINT UVar2;
  int iVar3;
  CPtrArray *pCVar4;
  ulonglong uVar5;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar6;
  undefined8 uVar7;
  int iVar8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res10 [8];
  STGMEDIUM local_58;
  undefined2 local_40 [4];
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  iVar8 = 0;
  if (param_2 == (longlong *)0x0) {
    return 0x80070057;
  }
  plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x28) + 0x38);
  if (((plVar1 == (longlong *)0x0) || (*plVar1 == 0)) ||
     ((-1 < (int)plVar1[1] && (-1 < *(int *)((longlong)plVar1 + 0xc))))) {
    UVar2 = RegisterClipboardFormatA("Grid Text");
    local_40[0] = (undefined2)UVar2;
    local_30 = 1;
    local_38 = 0;
    local_28 = 1;
    local_2c = 0xffffffff;
    iVar3 = (**(code **)(*param_2 + 0x18))(param_2,local_40);
    if (iVar3 < 0) {
      UVar2 = RegisterClipboardFormatA("AP_Text");
      local_40[0] = (undefined2)UVar2;
      local_30 = 1;
      local_38 = 0;
      local_28 = 1;
      local_2c = 0xffffffff;
      iVar3 = (**(code **)(*param_2 + 0x18))(param_2,local_40);
      if (iVar3 < 0) goto LAB_18002c1a9;
      *(undefined4 *)(param_1 + 0x80) = 0;
    }
  }
  else {
    UVar2 = RegisterClipboardFormatA("AP_Text");
    local_40[0] = (undefined2)UVar2;
    local_30 = 1;
    local_38 = 0;
    local_28 = 1;
    local_2c = 0xffffffff;
    iVar3 = (**(code **)(*param_2 + 0x18))(param_2,local_40);
    if (iVar3 < 0) {
LAB_18002c1a9:
      local_40[0] = 1;
      local_30 = 1;
      local_38 = 0;
      local_28 = 1;
      local_2c = 0xffffffff;
      iVar3 = (**(code **)(*param_2 + 0x18))(param_2,local_40);
      *(undefined4 *)(param_1 + 0x80) = 0;
      if (iVar3 < 0) goto LAB_18002c25a;
    }
  }
  FUN_18003e370(-1);
  uVar7 = 0;
  if ((local_58.u.hBitmap != (HBITMAP)0x0) &&
     (pCVar4 = FUN_18002a620(param_1,local_58.u.hGlobal), uVar7 = 0, -1 < (int)pCVar4)) {
    uVar5 = FUN_18002c9d0(param_1,local_58.u.hGlobal,0);
    if ((int)uVar5 < 0) {
      pCVar6 = FUN_180020fe0(local_res10,0xd);
      MMAfxMessageBox(*(char **)pCVar6,0x40,-1,0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10);
    }
    else {
      uVar7 = 1;
    }
  }
  iVar8 = (int)uVar7;
  ReleaseStgMedium(&local_58);
  FUN_18003e370(0);
LAB_18002c25a:
  (**(code **)(*param_2 + 0x10))(param_2);
  uVar7 = 0x80004005;
  if (iVar8 != 0) {
    uVar7 = 0;
  }
  return uVar7;
}

/* ---- FUNC 0002C290 FUN_18002c290 (32 bytes) ---- */

undefined4 FUN_18002c290(longlong param_1,longlong *param_2,undefined2 *param_3)

{
  undefined8 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_18002c2b0(param_1 + -8,param_2,param_3);
  uVar2 = 0x80004005;
  if ((int)uVar1 != 0) {
    uVar2 = 0;
  }
  return uVar2;
}

/* ---- FUNC 0002C2B0 FUN_18002c2b0 (136 bytes) ---- */

undefined8 FUN_18002c2b0(longlong param_1,longlong *param_2,undefined2 *param_3)

{
  int iVar1;
  longlong *plVar2;
  undefined8 uVar3;
  
  *param_3 = 0;
  if (*(longlong *)(param_1 + 0xb0) != 0) {
    if (*(longlong *)(param_1 + 0xb0) < 1) {
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
    if ((**(longlong **)(param_1 + 0xa8) != 0) &&
       (((iVar1 = *(int *)(**(longlong **)(param_1 + 0xa8) + 0x30), iVar1 == 0 || (iVar1 == 3)) &&
        (plVar2 = FUN_180027a00(param_1), plVar2 != (longlong *)0x0)))) {
      uVar3 = FUN_18002c0a0((longlong)plVar2,param_2);
      if (-1 < (int)uVar3) {
        *param_3 = 0xffff;
      }
      (**(code **)(*plVar2 + 0x10))(plVar2);
    }
  }
  return 1;
}

/* ---- FUNC 0002C2EF FUN_18002c2ef (52 bytes) ---- */

undefined8 FUN_18002c2ef(longlong param_1)

{
  longlong *plVar1;
  undefined8 uVar2;
  longlong *unaff_RSI;
  undefined2 *unaff_RDI;
  
  plVar1 = FUN_180027a00(param_1);
  if (plVar1 != (longlong *)0x0) {
    uVar2 = FUN_18002c0a0((longlong)plVar1,unaff_RSI);
    if (-1 < (int)uVar2) {
      *unaff_RDI = 0xffff;
    }
    (**(code **)(*plVar1 + 0x10))(plVar1);
  }
  return 1;
}

/* ---- FUNC 0002C323 FUN_18002c323 (16 bytes) ---- */

undefined8 FUN_18002c323(void)

{
  return 1;
}

/* ---- FUNC 0002C340 FUN_18002c340 (231 bytes) ---- */

undefined8
FUN_18002c340(longlong param_1,undefined8 *param_2,undefined8 *param_3,undefined2 *param_4)

{
  int iVar1;
  longlong *plVar2;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  *param_4 = 0;
  if (*(longlong *)(param_1 + 0xb0) != 0) {
    if (*(longlong *)(param_1 + 0xb0) < 1) {
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
    if ((**(longlong **)(param_1 + 0xa8) != 0) &&
       ((iVar1 = *(int *)(**(longlong **)(param_1 + 0xa8) + 0x30), iVar1 == 0 || (iVar1 == 3)))) {
      plVar2 = FUN_180027a00(param_1);
      if (plVar2 != (longlong *)0x0) {
        local_48 = *param_3;
        uStack_40 = param_3[1];
        local_38 = param_3[2];
        local_28 = *param_2;
        uStack_20 = param_2[1];
        local_18 = param_2[2];
        iVar1 = FUN_18002c430(plVar2,(short *)&local_28,(short *)&local_48);
        if (-1 < iVar1) {
          *param_4 = 0xffff;
        }
        (**(code **)(*plVar2 + 0x10))(plVar2);
      }
      return 0;
    }
  }
  return 1;
}

/* ---- FUNC 0002C393 FUN_18002c393 (119 bytes) ---- */

undefined8 FUN_18002c393(longlong param_1)

{
  int iVar1;
  longlong *plVar2;
  undefined8 *unaff_RBP;
  undefined8 *unaff_RSI;
  undefined2 *unaff_RDI;
  undefined8 uStackX_20;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  
  plVar2 = FUN_180027a00(param_1);
  if (plVar2 != (longlong *)0x0) {
    uStackX_20 = *unaff_RSI;
    in_stack_00000040 = *unaff_RBP;
    in_stack_00000048 = unaff_RBP[1];
    in_stack_00000050 = unaff_RBP[2];
    iVar1 = FUN_18002c430(plVar2,(short *)&stack0x00000040,(short *)&uStackX_20);
    if (-1 < iVar1) {
      *unaff_RDI = 0xffff;
    }
    (**(code **)(*plVar2 + 0x10))(plVar2);
  }
  return 0;
}

/* ---- FUNC 0002C40A FUN_18002c40a (24 bytes) ---- */

undefined8 FUN_18002c40a(void)

{
  return 1;
}

/* ---- FUNC 0002C430 FUN_18002c430 (1436 bytes) ---- */

int FUN_18002c430(longlong *param_1,short *param_2,short *param_3)

{
  LPLOCKBYTES *pplkbyt;
  IStorage **ppstgOpen;
  LPVOID *ppvObj;
  short sVar1;
  bool bVar2;
  bool bVar3;
  UINT UVar4;
  UINT UVar5;
  HRESULT HVar6;
  int iVar7;
  CPtrArray *pCVar8;
  ulonglong uVar9;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar10;
  uint uVar11;
  CLIPFORMAT CVar12;
  UINT local_res20 [2];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_168 [8];
  FORMATETC local_160;
  STGMEDIUM local_140;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  LPDATAOBJECT local_e8;
  undefined2 *puStack_e0;
  undefined8 local_d8;
  UINT *pUStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  int local_b8;
  int iStack_b4;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined2 local_98 [4];
  undefined8 local_90;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  char *local_78;
  char *local_70;
  undefined4 local_68;
  CLIPFORMAT local_60;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  char *local_40;
  char *local_38;
  undefined4 local_30;
  
  bVar3 = false;
  uVar11 = 0;
  UVar4 = RegisterClipboardFormatA("Grid Text");
  UVar5 = RegisterClipboardFormatA("Link Source");
  local_128 = 0;
  uStack_120 = 0;
  local_118 = 0;
  uStack_110 = 0;
  local_108 = 0;
  uStack_100 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  local_e8 = (IDataObject *)0x0;
  puStack_e0 = (undefined2 *)0x0;
  local_d8 = 0;
  pUStack_d0 = (UINT *)0x0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_b8 = 0;
  iStack_b4 = 0;
  uStack_b0 = 0;
  local_a8 = 0;
  HVar6 = OleGetClipboard(&local_e8);
  if (HVar6 < 0) {
    return -0x7fffbffb;
  }
  CVar12 = (CLIPFORMAT)UVar4;
  local_160.dwAspect = 1;
  local_160.ptd = (DVTARGETDEVICE *)0x0;
  local_160.tymed = 1;
  local_160.lindex = -1;
  local_160.cfFormat = CVar12;
  HVar6 = (*local_e8->lpVtbl->GetData)(local_e8,&local_160,&local_140);
  if (-1 < HVar6) {
    uVar11 = (uint)(local_140.u.hBitmap != (HBITMAP)0x0);
    ReleaseStgMedium(&local_140);
  }
  uStack_120 = DAT_1800797e0;
  local_128._4_4_ = 0x10;
  local_128 = 0x1000000088;
  puStack_e0 = local_98;
  local_d8 = CONCAT44(local_d8._4_4_,uVar11 + 1);
  pUStack_d0 = local_res20;
  local_c8 = CONCAT44(local_c8._4_4_,1);
  local_98[0] = 1;
  local_88 = 1;
  local_80 = 1;
  local_84 = 0xffffffff;
  local_68 = 0x201;
  local_90 = 0;
  if (uVar11 == 0) {
    local_78 = "Text";
    local_70 = "Text";
  }
  else {
    local_78 = "Text with labels";
    local_70 = "Text with labels";
    local_50 = 1;
    local_58 = 0;
    local_48 = 1;
    local_4c = 0xffffffff;
    local_40 = "Text without labels";
    local_38 = "Text without labels";
    local_30 = 0x201;
    local_60 = CVar12;
  }
  bVar2 = false;
  sVar1 = *param_2;
  local_res20[0] = UVar5;
  if (sVar1 == 2) {
    UVar5 = (UINT)param_2[4];
    if (UVar5 == 1) {
      local_b8 = 0;
    }
    else {
LAB_18002c673:
      if ((uVar11 == 0) || (UVar5 != UVar4)) goto LAB_18002c683;
      local_b8 = 1;
    }
LAB_18002c680:
    bVar2 = true;
  }
  else {
    if (sVar1 == 3) {
      UVar5 = *(UINT *)(param_2 + 4);
      if (UVar5 != 1) goto LAB_18002c673;
      local_b8 = 0;
      goto LAB_18002c680;
    }
    bVar2 = false;
    if (sVar1 == 8) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                (local_168,*(wchar_t **)(param_2 + 4));
      iVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                        (local_168,"Text");
      if (iVar7 == 0) {
        local_b8 = 0;
        bVar2 = true;
      }
      else {
        bVar2 = false;
        if ((uVar11 != 0) &&
           (iVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                    CompareNoCase(local_168,"Grid Text"), bVar2 = false, iVar7 == 0)) {
          local_b8 = 1;
          bVar2 = true;
        }
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_168);
    }
  }
LAB_18002c683:
  iVar7 = 0;
  sVar1 = *param_3;
  if (sVar1 == 2) {
LAB_18002c696:
    if (param_3[4] == 0) {
      uVar11 = local_128._4_4_ | 2;
    }
    else {
LAB_18002c6b5:
      uVar11 = local_128._4_4_ | 4;
      iVar7 = 1;
    }
LAB_18002c6bb:
    local_128 = CONCAT44(uVar11,(undefined4)local_128);
    iStack_b4 = iVar7;
    if (!bVar2) goto LAB_18002c6c5;
  }
  else {
    if (sVar1 == 3) {
      if (*(int *)(param_3 + 4) != 0) goto LAB_18002c6b5;
      uVar11 = local_128._4_4_ | 2;
      iVar7 = 0;
      goto LAB_18002c6bb;
    }
    if (sVar1 == 0xb) goto LAB_18002c696;
LAB_18002c6c5:
    iVar7 = OleUIPasteSpecialA();
    if (iVar7 != 1) goto LAB_18002c99c;
  }
  if (local_b8 == 0) {
    local_160.cfFormat = 1;
    *(undefined4 *)(param_1 + 0x10) = 0;
    CVar12 = local_160.cfFormat;
  }
  else if (local_b8 != 1) {
LAB_18002c99c:
    (*local_e8->lpVtbl->Release)(local_e8);
    return -0x7fffbffb;
  }
  local_160.cfFormat = CVar12;
  local_160.lindex = -1;
  local_160.tymed = 1;
  local_160.ptd = (DVTARGETDEVICE *)0x0;
  local_160.dwAspect = 1;
  if (iStack_b4 == 0) {
    HVar6 = (*local_e8->lpVtbl->GetData)(local_e8,&local_160,&local_140);
    if (-1 < HVar6) {
      FUN_18003e370(-1);
      bVar2 = bVar3;
      if (((local_140.u.hBitmap != (HBITMAP)0x0) &&
          (pCVar8 = FUN_18002a620((longlong)param_1,local_140.u.hGlobal), -1 < (int)pCVar8)) &&
         (uVar9 = FUN_18002c9d0((longlong)param_1,local_140.u.hGlobal,0), bVar2 = true,
         (int)uVar9 < 0)) {
        pCVar10 = FUN_180020fe0(local_168,0xd);
        MMAfxMessageBox(*(char **)pCVar10,0x40,-1,0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_168);
        bVar2 = bVar3;
      }
      bVar3 = bVar2;
      FUN_18003e370(0);
      ReleaseStgMedium(&local_140);
    }
  }
  else {
    pplkbyt = (LPLOCKBYTES *)(param_1 + 0xf);
    HVar6 = CreateILockBytesOnHGlobal((HGLOBAL)0x0,1,pplkbyt);
    if (HVar6 < 0) {
      (*local_e8->lpVtbl->Release)(local_e8);
      return HVar6;
    }
    ppstgOpen = (IStorage **)(param_1 + 0xe);
    HVar6 = StgCreateDocfileOnILockBytes(*pplkbyt,0x1012,0,ppstgOpen);
    if (HVar6 < 0) {
      (*(*pplkbyt)->lpVtbl->Release)(*pplkbyt);
      *pplkbyt = (LPLOCKBYTES)0x0;
      (*local_e8->lpVtbl->Release)(local_e8);
      return HVar6;
    }
    ppvObj = (LPVOID *)(param_1 + 0xd);
    HVar6 = OleCreateLinkFromData
                      (local_e8,(IID *)&DAT_180066d58,0,&local_160,(LPOLECLIENTSITE)0x0,*ppstgOpen,
                       ppvObj);
    if (HVar6 < 0) {
      (*(*ppstgOpen)->lpVtbl->Release)(*ppstgOpen);
      *ppstgOpen = (IStorage *)0x0;
      (*(*pplkbyt)->lpVtbl->Release)(*pplkbyt);
      *pplkbyt = (LPLOCKBYTES)0x0;
      return HVar6;
    }
    iVar7 = (**(code **)(*(longlong *)*ppvObj + 0x48))
                      (*ppvObj,&local_160,2,param_1[0xb],param_1 + 0xc);
    if (iVar7 < 0) {
      (*(*ppstgOpen)->lpVtbl->Release)(*ppstgOpen);
      *ppstgOpen = (IStorage *)0x0;
      (*(*pplkbyt)->lpVtbl->Release)(*pplkbyt);
      *pplkbyt = (LPLOCKBYTES)0x0;
      (**(code **)(*(longlong *)*ppvObj + 0x10))();
      *ppvObj = (LPVOID)0x0;
      return iVar7;
    }
    iVar7 = (**(code **)(*(longlong *)*ppvObj + 0x18))(*ppvObj,&local_160);
    if (-1 < iVar7) {
      FUN_18003e370(-1);
      bVar2 = bVar3;
      if (((local_140.u.hBitmap != (HBITMAP)0x0) &&
          (pCVar8 = FUN_18002a620((longlong)param_1,local_140.u.hGlobal), -1 < (int)pCVar8)) &&
         (uVar9 = FUN_18002c9d0((longlong)param_1,local_140.u.hGlobal,0), bVar2 = true,
         (int)uVar9 < 0)) {
        pCVar10 = FUN_180020fe0(local_168,0x12);
        MMAfxMessageBox(*(char **)pCVar10,0x40,-1,0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_168);
        bVar2 = bVar3;
      }
      ReleaseStgMedium(&local_140);
      FUN_18003e370(0);
      bVar3 = bVar2;
    }
    FUN_18000e910(param_1[2],param_1);
    *(undefined4 *)(param_1 + 1) = 4;
  }
  (*local_e8->lpVtbl->Release)(local_e8);
  if (bVar3) {
    return 0;
  }
  return -0x7fffbffb;
}

/* ---- FUNC 0002C9D0 FUN_18002c9d0 (3002 bytes) ---- */

ulonglong FUN_18002c9d0(longlong param_1,HGLOBAL param_2,int param_3)

{
  longlong *plVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  undefined8 *puVar8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  longlong lVar9;
  longlong lVar10;
  ulonglong uVar11;
  longlong *plVar12;
  longlong lVar13;
  longlong *local_res8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res20 [8];
  _union_2707 local_188;
  _union_2707 local_170;
  ulonglong local_158;
  _union_1719 _Stack_150;
  undefined8 local_148;
  _union_2707 local_138;
  longlong *local_120;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_118 [16];
  ulonglong local_108;
  _union_1719 _Stack_100;
  undefined8 local_f8;
  _union_2707 local_e8;
  CStringArray local_d0 [8];
  longlong local_c8;
  longlong *local_c0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_a8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_a0 [8];
  longlong *local_98;
  CDWordArray local_90 [8];
  longlong local_88;
  longlong local_80;
  CDWordArray local_68 [8];
  longlong local_60;
  longlong local_58;
  
  plVar12 = (longlong *)0x0;
  local_170._0_8_ = 0;
  local_170.decVal.u2 = (_union_1719)0x0;
  local_170._16_8_ = 0;
  VariantInit((VARIANTARG *)&local_170.n2);
  local_188._0_8_ = 0;
  local_188._8_4_ = 0;
  local_188._12_4_ = 0;
  local_188._16_8_ = 0;
  VariantInit((VARIANTARG *)&local_188.n2);
  local_e8._0_8_ = 0;
  local_e8.decVal.u2 = (_union_1719)0x0;
  local_e8._16_8_ = 0;
  VariantInit((VARIANTARG *)&local_e8.n2);
  local_138._0_8_ = 0;
  local_138.decVal.u2 = (_union_1719)0x0;
  local_138._16_8_ = 0;
  VariantInit((VARIANTARG *)&local_138.n2);
  if (*(longlong *)(param_1 + 0x40) == 0) {
    iVar3 = *(int *)(*(longlong *)(param_1 + 0x28) + 0x30);
    if ((iVar3 == 0) || (iVar3 == 3)) {
      plVar12 = *(longlong **)(*(longlong *)(param_1 + 0x28) + 0x28);
      uVar11 = (ulonglong)local_188._0_8_ >> 0x20;
      local_188._0_8_ = local_188._0_8_ & 0xffffffffffff0000;
      local_e8._0_8_ = local_e8._0_8_ & 0xffffffffffff0000;
      local_108 = CONCAT44((int)uVar11,(int)local_188._0_8_);
      _Stack_100.s2.Mid32 = local_188._12_4_;
      _Stack_100.s2.Lo32 = local_188._8_4_;
      local_f8 = local_188._16_8_;
      uVar6 = (**(code **)(*plVar12 + 0x98))(plVar12,0x12,&local_108,&local_e8);
      uVar11 = (ulonglong)uVar6;
      if (((int)uVar6 < 0) || (local_e8._8_4_ != 0)) goto LAB_18002cfc8;
    }
    else {
      uVar11 = (ulonglong)local_res8 & 0xffffffff;
    }
    pcVar7 = GlobalLock(param_2);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8,pcVar7);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::TrimRight
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
    if ((*(longlong *)(param_1 + 0x98) == 1) &&
       (iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                          (*(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                            (param_1 + 0x90),(char *)local_res8), iVar3 == 0)) {
      GlobalUnlock(param_2);
      uVar11 = 0;
LAB_18002cdba:
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
      goto LAB_18002cfc8;
    }
    CStringArray::SetSize((CStringArray *)(param_1 + 0x88),0,-1);
    local_188.n2.vt = 3;
    local_188._8_4_ = 1;
    local_170.n2.vt = 8;
    local_170.decVal.u2 =
         (_union_1719)
         ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::AllocSysString
                   ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
    iVar3 = *(int *)(*(longlong *)(param_1 + 0x28) + 0x30);
    if (iVar3 == 3) {
      uVar11 = 0x80004005;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                (local_res20,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 (*(longlong *)(param_1 + 0x28) + 0x18));
      plVar12 = *(longlong **)(*(longlong *)(param_1 + 0x28) + 0x28);
      iVar3 = (**(code **)(*plVar12 + 200))(plVar12,&local_120);
      if (-1 < iVar3) {
        iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                          (local_res20,'x',0);
        if (iVar3 != -1) {
          puVar8 = (undefined8 *)
                   ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                             (local_res20,(int)local_118);
          iVar3 = atoi((char *)*puVar8);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_118);
          puVar8 = (undefined8 *)
                   ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                             (local_res20,(int)local_118);
          iVar4 = atoi((char *)*puVar8);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_118);
          cVar2 = FUN_18002f2c0();
          if (cVar2 != '.') {
            local_108 = local_188._0_8_;
            _Stack_100.s2.Mid32 = local_188._12_4_;
            _Stack_100.s2.Lo32 = local_188._8_4_;
            local_f8 = local_188._16_8_;
            iVar5 = (**(code **)(*local_120 + 0xa0))
                              (local_120,iVar3,0xffffffff,0x34,&local_108,&local_138);
            if (((-1 < iVar5) && (local_138.n2.vt == 3)) && (local_138._8_4_ != 0)) {
              FUN_180025190((VARIANTARG *)&local_170.n2,0x400,0x7f);
              VariantClear((VARIANTARG *)&local_138.n2);
            }
          }
          local_108 = local_188._0_8_;
          _Stack_100.s2.Mid32 = local_188._12_4_;
          _Stack_100.s2.Lo32 = local_188._8_4_;
          local_f8 = local_188._16_8_;
          uVar6 = (**(code **)(*local_120 + 0x88))
                            (local_120,iVar3,iVar4,&local_108,local_170.decVal.u2.Lo64);
          uVar11 = (ulonglong)uVar6;
        }
        (**(code **)(*local_120 + 0x10))();
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20);
    }
    else if (iVar3 == 0) {
      cVar2 = FUN_18002f2c0();
      if (cVar2 != '.') {
        local_108 = local_188._0_8_;
        _Stack_100.s2.Mid32 = local_188._12_4_;
        _Stack_100.s2.Lo32 = local_188._8_4_;
        local_f8 = local_188._16_8_;
        iVar3 = (**(code **)(*plVar12 + 0x98))(plVar12,0x34,&local_108,&local_138);
        if (((-1 < iVar3) && (local_138.n2.vt == 3)) && (local_138._8_4_ != 0)) {
          FUN_180025190((VARIANTARG *)&local_170.n2,0x400,0x7f);
        }
        VariantClear((VARIANTARG *)&local_138.n2);
      }
      local_108 = local_170._0_8_;
      _Stack_100 = local_170.decVal.u2;
      local_f8 = local_170._16_8_;
      local_158 = local_188._0_8_;
      _Stack_150.s2.Mid32 = local_188._12_4_;
      _Stack_150.s2.Lo32 = local_188._8_4_;
      local_148 = local_188._16_8_;
      uVar6 = (**(code **)(*plVar12 + 0x70))(plVar12,&local_158,&local_108);
      uVar11 = (ulonglong)uVar6;
    }
    GlobalUnlock(param_2);
    VariantClear((VARIANTARG *)&local_170.n2);
    if (param_3 == 0) {
      if ((int)uVar11 < 0) goto LAB_18002cdba;
LAB_18002cdd0:
      CStringArray::SetAtGrow
                ((CStringArray *)(param_1 + 0x88),*(__int64 *)(param_1 + 0x98),
                 (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
    }
    else if (-1 < (int)uVar11) goto LAB_18002cdd0;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
  }
  else {
    CStringArray::CStringArray(local_d0);
    CDWordArray::CDWordArray(local_68);
    CDWordArray::CDWordArray(local_90);
    FUN_18002bbf0(param_1,param_2,local_d0,local_68,local_90);
    if (local_c0 == (longlong *)0x0) {
      uVar11 = 1;
LAB_18002d55d:
      CDWordArray::~CDWordArray(local_90);
      CDWordArray::~CDWordArray(local_68);
      CStringArray::~CStringArray(local_d0);
      goto LAB_18002cfc8;
    }
    local_98 = local_c0;
    if (local_c0 != (longlong *)0x0) {
      uVar6 = (uint)local_res8;
      do {
        if ((((longlong)plVar12 < 0) || (local_58 <= (longlong)plVar12)) ||
           (lVar9 = (longlong)*(int *)(local_60 + (longlong)plVar12 * 4),
           local_80 <= (longlong)plVar12)) goto LAB_18002d585;
        lVar10 = (longlong)*(int *)(local_88 + (longlong)plVar12 * 4);
        if (lVar9 < *(longlong *)(param_1 + 0x40)) {
          if (lVar9 < 0) goto LAB_18002d585;
          lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + lVar9 * 8);
          if (*(longlong *)(lVar9 + 0x10) <= lVar10) goto LAB_18002cf6a;
          if (plVar12 < *(longlong **)(param_1 + 0x98)) {
            if (*(longlong *)(param_1 + 0x98) <= (longlong)plVar12) goto LAB_18002d585;
            if ((longlong)local_c0 <= (longlong)plVar12) goto LAB_18002d585;
            iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               (*(longlong *)(param_1 + 0x90) + (longlong)plVar12 * 8),
                               *(char **)(local_c8 + (longlong)plVar12 * 8));
            if (iVar3 == 0) {
              if ((*(longlong *)(param_1 + 0xc0) <= (longlong)plVar12) ||
                 (local_58 <= (longlong)plVar12)) goto LAB_18002d585;
              if (*(int *)(*(longlong *)(param_1 + 0xb8) + (longlong)plVar12 * 4) ==
                  *(int *)(local_60 + (longlong)plVar12 * 4)) {
                if ((*(longlong *)(param_1 + 0xe8) <= (longlong)plVar12) ||
                   (local_80 <= (longlong)plVar12)) goto LAB_18002d585;
                if (*(int *)(*(longlong *)(param_1 + 0xe0) + (longlong)plVar12 * 4) ==
                    *(int *)(local_88 + (longlong)plVar12 * 4)) goto LAB_18002cf6a;
              }
            }
          }
          else {
            CStringArray::SetSize((CStringArray *)(param_1 + 0x88),(longlong)plVar12 + 1,-1);
            CDWordArray::SetSize((CDWordArray *)(param_1 + 0xb0),(longlong)plVar12 + 1,-1);
            CDWordArray::SetSize((CDWordArray *)(param_1 + 0xd8),(longlong)plVar12 + 1,-1);
          }
          lVar13 = (longlong)plVar12 * 8;
          if ((((((*(longlong *)(param_1 + 0x98) <= (longlong)plVar12) ||
                 ((longlong)local_c0 <= (longlong)plVar12)) ||
                (ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                           ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            (*(longlong *)(param_1 + 0x90) + lVar13),
                            (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                             *)(local_c8 + lVar13)),
                *(longlong *)(param_1 + 0xc0) <= (longlong)plVar12)) ||
               ((local_58 <= (longlong)plVar12 ||
                (*(undefined4 *)(*(longlong *)(param_1 + 0xb8) + (longlong)plVar12 * 4) =
                      *(undefined4 *)(local_60 + (longlong)plVar12 * 4),
                *(longlong *)(param_1 + 0xe8) <= (longlong)plVar12)))) ||
              (local_80 <= (longlong)plVar12)) ||
             ((*(undefined4 *)(*(longlong *)(param_1 + 0xe0) + (longlong)plVar12 * 4) =
                    *(undefined4 *)(local_88 + (longlong)plVar12 * 4), lVar10 < 0 ||
              (*(longlong *)(lVar9 + 0x10) <= lVar10)))) goto LAB_18002d585;
          plVar1 = *(longlong **)(*(longlong *)(lVar9 + 8) + lVar10 * 8);
          if (plVar1 == (longlong *)0x0) goto LAB_18002cf6a;
          this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                 ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                           ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            (plVar1 + 0x3b),(int)local_118);
          iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                            (this,"@LABEL");
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_118);
          if (iVar3 == 0) {
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       (plVar1 + 0x3b),(int)local_res20);
            plVar1 = (longlong *)plVar1[0xc];
            if (plVar1 == (longlong *)0x0) {
LAB_18002d355:
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20);
              goto LAB_18002d4d9;
            }
            local_res8 = (longlong *)0x0;
            uVar6 = (**(code **)(*plVar1 + 200))(plVar1,&local_res8);
            if (-1 < (int)uVar6) {
              uVar11 = (ulonglong)local_188._0_8_ >> 0x20;
              local_188._0_8_ = local_188._0_8_ & 0xffffffffffff0000;
              local_e8._0_8_ = local_e8._0_8_ & 0xffffffffffff0000;
              local_158 = CONCAT44((int)uVar11,(int)local_188._0_8_);
              _Stack_150.s2.Mid32 = local_188._12_4_;
              _Stack_150.s2.Lo32 = local_188._8_4_;
              local_148 = local_188._16_8_;
              uVar6 = (**(code **)(*plVar1 + 0x98))(plVar1,0x12,&local_158,&local_e8);
              if ((-1 < (int)uVar6) && (local_e8._8_4_ == 0)) {
                iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                                  (local_res20,'x',0);
                if (iVar3 != -1) {
                  puVar8 = (undefined8 *)
                           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                                     (local_res20,(int)&local_120);
                  iVar3 = atoi((char *)*puVar8);
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_120);
                  puVar8 = (undefined8 *)
                           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                                     (local_res20,(int)local_a0);
                  iVar4 = atoi((char *)*puVar8);
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_a0);
                  local_188.n2.vt = 3;
                  local_188._8_4_ = 1;
                  local_170.n2.vt = 8;
                  if ((longlong)local_c0 <= (longlong)plVar12) goto LAB_18002d57f;
                  local_170.decVal.u2 =
                       (_union_1719)
                       ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                       AllocSysString((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                       *)(local_c8 + lVar13));
                  cVar2 = FUN_18002f2c0();
                  if (cVar2 != '.') {
                    local_158 = local_188._0_8_;
                    _Stack_150.s2.Mid32 = local_188._12_4_;
                    _Stack_150.s2.Lo32 = local_188._8_4_;
                    local_148 = local_188._16_8_;
                    iVar5 = (**(code **)(*local_res8 + 0xa0))
                                      (local_res8,iVar3,0xffffffff,0x34,&local_158,&local_138);
                    if (((-1 < iVar5) && (local_138.n2.vt == 3)) && (local_138._8_4_ != 0)) {
                      FUN_180025190((VARIANTARG *)&local_170.n2,0x400,0x7f);
                      VariantClear((VARIANTARG *)&local_138.n2);
                    }
                  }
                  local_158 = local_188._0_8_;
                  _Stack_150.s2.Mid32 = local_188._12_4_;
                  _Stack_150.s2.Lo32 = local_188._8_4_;
                  local_148 = local_188._16_8_;
                  uVar6 = (**(code **)(*local_res8 + 0x88))
                                    (local_res8,iVar3,iVar4,&local_158,local_170.decVal.u2.Lo64);
                  VariantClear((VARIANTARG *)&local_170.n2);
                }
                (**(code **)(*local_res8 + 0x10))();
                goto LAB_18002d355;
              }
              (**(code **)(*local_res8 + 0x10))();
            }
            if (*(longlong *)(param_1 + 0xc0) <= (longlong)plVar12) {
LAB_18002d57f:
                    /* WARNING: Subroutine does not return */
              AfxThrowInvalidArgException();
            }
            *(undefined4 *)(*(longlong *)(param_1 + 0xb8) + (longlong)plVar12 * 4) = 0xffffffff;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20);
          }
          else {
            uVar11 = (ulonglong)local_188._0_8_ >> 0x20;
            local_188._0_8_ = local_188._0_8_ & 0xffffffffffff0000;
            local_e8._0_8_ = local_e8._0_8_ & 0xffffffffffff0000;
            local_158 = CONCAT44((int)uVar11,(int)local_188._0_8_);
            _Stack_150.s2.Mid32 = local_188._12_4_;
            _Stack_150.s2.Lo32 = local_188._8_4_;
            local_148 = local_188._16_8_;
            iVar3 = (**(code **)(*plVar1 + 0x98))(plVar1,0x12,&local_158,&local_e8);
            if ((iVar3 < 0) && (local_e8._8_4_ == 0)) {
              local_158 = local_188._0_8_;
              _Stack_150.s2.Mid32 = local_188._12_4_;
              _Stack_150.s2.Lo32 = local_188._8_4_;
              local_148 = local_188._16_8_;
              uVar6 = (**(code **)(*plVar1 + 0x98))(plVar1,0x47,&local_158,&local_e8);
              if (((int)uVar6 < 0) && (local_e8._8_4_ == 0)) {
                if (*(longlong *)(param_1 + 0xc0) <= (longlong)plVar12) goto LAB_18002d585;
                *(undefined4 *)(*(longlong *)(param_1 + 0xb8) + (longlong)plVar12 * 4) = 0xffffffff;
                goto LAB_18002d55a;
              }
            }
            local_188.n2.vt = 3;
            local_170.n2.vt = 8;
            local_188._8_4_ = 1;
            if ((longlong)local_c0 <= (longlong)plVar12) goto LAB_18002d585;
            local_170.decVal.u2 =
                 (_union_1719)
                 ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::AllocSysString
                           ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            (local_c8 + lVar13));
            cVar2 = FUN_18002f2c0();
            if (cVar2 != '.') {
              local_158 = local_188._0_8_;
              _Stack_150.s2.Mid32 = local_188._12_4_;
              _Stack_150.s2.Lo32 = local_188._8_4_;
              local_148 = local_188._16_8_;
              iVar3 = (**(code **)(*plVar1 + 0x98))(plVar1,0x34,&local_158,&local_138);
              if (((-1 < iVar3) && (local_138.n2.vt == 3)) && (local_138._8_4_ != 0)) {
                FUN_180025190((VARIANTARG *)&local_170.n2,0x400,0x7f);
                VariantClear((VARIANTARG *)&local_138.n2);
              }
            }
            local_158 = local_170._0_8_;
            _Stack_150 = local_170.decVal.u2;
            local_148 = local_170._16_8_;
            local_108 = local_188._0_8_;
            _Stack_100.s2.Mid32 = local_188._12_4_;
            _Stack_100.s2.Lo32 = local_188._8_4_;
            local_f8 = local_188._16_8_;
            uVar6 = (**(code **)(*plVar1 + 0x70))(plVar1,&local_108,&local_158);
            VariantClear((VARIANTARG *)&local_170.n2);
LAB_18002d4d9:
            if ((int)uVar6 < 0) {
              if (*(longlong *)(param_1 + 0xc0) <= (longlong)plVar12) {
LAB_18002d585:
                    /* WARNING: Subroutine does not return */
                AfxThrowInvalidArgException();
              }
              *(undefined4 *)(*(longlong *)(param_1 + 0xb8) + (longlong)plVar12 * 4) = 0xffffffff;
            }
            if ((param_3 != 0) || (-1 < (int)uVar6)) goto LAB_18002cf6a;
          }
LAB_18002d55a:
          uVar11 = (ulonglong)uVar6;
          goto LAB_18002d55d;
        }
LAB_18002cf6a:
        plVar12 = (longlong *)((longlong)plVar12 + 1);
      } while (plVar12 < local_98);
    }
    CDWordArray::~CDWordArray(local_90);
    CDWordArray::~CDWordArray(local_68);
    CStringArray::~CStringArray(local_d0);
  }
  uVar11 = 0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_a8,"");
  FUN_1800374c0(0x65,(longlong *)local_a8);
  local_res8 = (longlong *)0x0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_a8);
LAB_18002cfc8:
  VariantClear((VARIANTARG *)&local_138.n2);
  VariantClear((VARIANTARG *)&local_e8.n2);
  VariantClear((VARIANTARG *)&local_188.n2);
  VariantClear((VARIANTARG *)&local_170.n2);
  return uVar11;
}

/* ---- FUNC 0002D590 FUN_18002d590 (31 bytes) ---- */

ulonglong FUN_18002d590(longlong param_1,undefined2 *param_2)

{
  longlong *plVar1;
  ulonglong uVar2;
  undefined8 local_res18 [2];
  
  plVar1 = FUN_180027ae0(param_1);
  if (plVar1 != (longlong *)0x0) {
    uVar2 = FUN_18002e900((longlong)plVar1,local_res18);
    *(undefined8 *)(param_2 + 4) = local_res18[0];
    *param_2 = 0x14;
    (**(code **)(*plVar1 + 0x10))(plVar1);
    return uVar2 & 0xffffffff;
  }
  return 0x80004005;
}

/* ---- FUNC 0002D5AF FUN_18002d5af (56 bytes) ---- */

ulonglong FUN_18002d5af(undefined8 param_1,undefined8 *param_2)

{
  longlong in_RAX;
  ulonglong uVar1;
  undefined2 *unaff_RSI;
  longlong *unaff_RDI;
  undefined8 in_stack_00000040;
  
  uVar1 = FUN_18002e900(in_RAX,param_2);
  *(undefined8 *)(unaff_RSI + 4) = in_stack_00000040;
  *unaff_RSI = 0x14;
  (**(code **)(*unaff_RDI + 0x10))();
  return uVar1 & 0xffffffff;
}

/* ---- FUNC 0002D5E7 FUN_18002d5e7 (16 bytes) ---- */

undefined8 FUN_18002d5e7(void)

{
  return 0x80004005;
}

/* ---- FUNC 0002D600 FUN_18002d600 (2269 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18002d600(longlong param_1)

{
  CStringArray *this;
  uint uVar1;
  longlong lVar2;
  char *pcVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar4;
  IAtlStringMgr *pIVar5;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  longlong lVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  undefined1 auStackY_158 [32];
  longlong local_118;
  undefined4 local_110;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_108 [8];
  longlong local_100;
  wchar_t *local_f8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_f0 [8];
  ulonglong local_e8;
  longlong local_e0;
  longlong local_d8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_d0 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_c8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_c0 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_b8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_b0 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_a8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_a0 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_98 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_90 [8];
  undefined8 local_88 [2];
  char local_78 [64];
  ulonglong local_38;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStackY_158;
  uVar11 = 0;
  local_110 = 0;
  this = (CStringArray *)(param_1 + 0xe0);
  local_100 = param_1;
  CStringArray::SetSize(this,0,-1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_118);
  FUN_1800255a0(local_88);
  local_e8 = *(ulonglong *)(param_1 + 0x60);
  lVar9 = param_1;
  uVar12 = uVar11;
  if (local_e8 != 0) {
    do {
      if (((longlong)uVar12 < 0) || (*(longlong *)(lVar9 + 0x60) <= (longlong)uVar12))
      goto LAB_18002ded8;
      lVar2 = *(longlong *)(*(longlong *)(lVar9 + 0x58) + uVar12 * 8);
      uVar1 = *(uint *)(lVar2 + 0x30);
      if ((uVar1 & 0xfffffffb) == 0) {
        pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                 ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                 CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_f0,"0+");
        pIVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                           (pCVar4);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_108,pIVar5);
        local_110 = 4;
        ATL::CSimpleStringT<char,1>::Concatenate
                  ((CSimpleStringT<char,1> *)local_108,*(char **)pCVar4,
                   *(int *)(*(char **)pCVar4 + -0x10),*(char **)(lVar2 + 0x10),
                   *(int *)(*(char **)(lVar2 + 0x10) + -0x10));
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_118,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   local_108);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_108);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_f0);
        lVar9 = local_100;
        if (*(int *)(local_118 + -0x10) != 0) {
          puVar8 = *(undefined8 **)(lVar2 + 0x38);
          if (puVar8 != (undefined8 *)0x0) {
            FUN_180002a20(local_78,"~%p~%ld~%ld~%ld~%ld",*puVar8,
                          (ulonglong)*(uint *)((longlong)puVar8 + 0x14));
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_118,
                       local_78);
          }
          CStringArray::SetAtGrow
                    (this,*(__int64 *)(param_1 + 0xf0),
                     (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_118);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8,
                     *(char **)(lVar2 + 0x50));
          if (*(int *)(local_d8 + -0x10) == 0) {
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8,
                       "-");
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_118,
                     "basis = %s unitrow = %d unitcol = %d",local_d8,
                     (ulonglong)*(uint *)(lVar2 + 0x48));
          CStringArray::SetAtGrow
                    (this,*(__int64 *)(param_1 + 0xf0),
                     (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_118);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8);
          lVar9 = local_100;
        }
      }
      else if (uVar1 == 2) {
        pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                 ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                 CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_b8,"2+");
        pcVar3 = *(char **)(lVar2 + 0x28);
        pIVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                           (pCVar4);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_d0,pIVar5);
        local_110 = 8;
        uVar10 = uVar11;
        if (pcVar3 != (char *)0x0) {
          uVar10 = 0xffffffffffffffff;
          do {
            uVar10 = uVar10 + 1;
          } while (pcVar3[uVar10] != '\0');
        }
        ATL::CSimpleStringT<char,1>::Concatenate
                  ((CSimpleStringT<char,1> *)local_d0,*(char **)pCVar4,
                   *(int *)(*(char **)pCVar4 + -0x10),pcVar3,(int)uVar10);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_118,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   local_d0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_d0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_b8);
        puVar8 = *(undefined8 **)(lVar2 + 0x38);
        if (puVar8 != (undefined8 *)0x0) {
          FUN_180002a20(local_78,"~%p~%ld~%ld~%ld~%ld",*puVar8,
                        (ulonglong)*(uint *)((longlong)puVar8 + 0x14));
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_118,
                     local_78);
        }
        CStringArray::SetAtGrow
                  (this,*(__int64 *)(param_1 + 0xf0),
                   (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_118);
        lVar9 = local_100;
      }
      else if (uVar1 == 0x5a) {
        pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                 ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                 CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_b0,"90+");
        pcVar3 = *(char **)(lVar2 + 0x28);
        pIVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                           (pCVar4);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_c8,pIVar5);
        local_110 = 0x10;
        uVar10 = uVar11;
        if (pcVar3 != (char *)0x0) {
          uVar10 = 0xffffffffffffffff;
          do {
            uVar10 = uVar10 + 1;
          } while (pcVar3[uVar10] != '\0');
        }
        ATL::CSimpleStringT<char,1>::Concatenate
                  ((CSimpleStringT<char,1> *)local_c8,*(char **)pCVar4,
                   *(int *)(*(char **)pCVar4 + -0x10),pcVar3,(int)uVar10);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_118,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   local_c8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_c8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_b0);
        puVar8 = *(undefined8 **)(lVar2 + 0x38);
        if (puVar8 != (undefined8 *)0x0) {
          FUN_180002a20(local_78,"~%p~%ld~%ld~%ld~%ld",*puVar8,
                        (ulonglong)*(uint *)((longlong)puVar8 + 0x14));
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_118,
                     local_78);
        }
        CStringArray::SetAtGrow
                  (this,*(__int64 *)(param_1 + 0xf0),
                   (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_118);
        lVar9 = local_100;
      }
      else {
        if (uVar1 == 0x60) {
          pCVar6 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                   CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_90,"96+");
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_118,
                     pCVar6);
          pCVar4 = local_90;
        }
        else if (uVar1 == 0x61) {
          pCVar6 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                   CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_98,"97+");
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_118,
                     pCVar6);
          pCVar4 = local_98;
        }
        else {
          if (uVar1 != 0x62) {
            if (uVar1 == 3) {
              pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                       CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_a8,"3+");
              pIVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                       GetManager(pCVar4);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_c0,pIVar5);
              local_110 = 0x20;
              ATL::CSimpleStringT<char,1>::Concatenate
                        ((CSimpleStringT<char,1> *)local_c0,*(char **)pCVar4,
                         *(int *)(*(char **)pCVar4 + -0x10),*(char **)(lVar2 + 0x10),
                         *(int *)(*(char **)(lVar2 + 0x10) + -0x10));
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_118
                         ,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                           *)local_c0);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_c0);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_a8);
              lVar9 = local_100;
              if (*(int *)(local_118 + -0x10) != 0) {
                puVar8 = *(undefined8 **)(lVar2 + 0x38);
                if (puVar8 != (undefined8 *)0x0) {
                  FUN_180002a20(local_78,"~%p~%ld~%ld~%ld~%ld",*puVar8,
                                (ulonglong)*(uint *)((longlong)puVar8 + 0x14));
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_118,local_78);
                }
                CStringArray::SetAtGrow
                          (this,*(__int64 *)(param_1 + 0xf0),
                           (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_118);
                lVar9 = local_100;
              }
            }
            goto LAB_18002dc58;
          }
          pCVar6 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                   CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_a0,"98+");
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_118,
                     pCVar6);
          pCVar4 = local_a0;
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar4);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_118,
                   (CSimpleStringT<char,1> *)(lVar2 + 0x10));
        if (*(int *)(local_118 + -0x10) != 0) {
          puVar8 = *(undefined8 **)(lVar2 + 0x38);
          if (puVar8 != (undefined8 *)0x0) {
            FUN_180002a20(local_78,"~%p~%ld~%ld~%ld~%ld",*puVar8,
                          (ulonglong)*(uint *)((longlong)puVar8 + 0x14));
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_118,
                       local_78);
          }
          CStringArray::SetAtGrow
                    (this,*(__int64 *)(param_1 + 0xf0),
                     (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_118);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_e0,
                     *(char **)(lVar2 + 0x50));
          if (*(int *)(local_e0 + -0x10) == 0) {
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_e0,
                       "-");
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_118,
                     "basis = %s unitrow = %d unitcol = %d",local_e0,
                     (ulonglong)*(uint *)(lVar2 + 0x48));
          CStringArray::SetAtGrow
                    (this,*(__int64 *)(param_1 + 0xf0),
                     (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_118);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_e0);
        }
      }
LAB_18002dc58:
      uVar12 = uVar12 + 1;
    } while (uVar12 < local_e8);
  }
  uVar12 = *(ulonglong *)(lVar9 + 0x88);
  uVar10 = uVar11;
  if (uVar12 != 0) {
    do {
      if (((longlong)uVar10 < 0) || (*(longlong *)(lVar9 + 0x88) <= (longlong)uVar10))
      goto LAB_18002ded8;
      uVar7 = FUN_180029ab0(DAT_180079590,*(longlong *)(*(longlong *)(lVar9 + 0x80) + uVar10 * 8),
                            &local_f8);
      if (-1 < (int)uVar7) {
        puVar8 = (undefined8 *)
                 ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                 CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_f0,local_f8);
        pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                 ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                 CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                           ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_e8,"-");
        pIVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                           (pCVar4);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_108,pIVar5);
        local_110 = 2;
        ATL::CSimpleStringT<char,1>::Concatenate
                  ((CSimpleStringT<char,1> *)local_108,*(char **)pCVar4,
                   *(int *)(*(char **)pCVar4 + -0x10),(char *)*puVar8,
                   *(int *)((char *)*puVar8 + -0x10));
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_118,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   local_108);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_108);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_e8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_f0);
        CStringArray::SetAtGrow
                  (this,*(__int64 *)(param_1 + 0xf0),
                   (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_118);
        CoTaskMemFree(local_f8);
        lVar9 = local_100;
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < uVar12);
  }
  uVar12 = *(ulonglong *)(lVar9 + 0x120);
  if (uVar12 != 0) {
    do {
      if (((longlong)uVar11 < 0) || (*(longlong *)(lVar9 + 0x120) <= (longlong)uVar11)) {
LAB_18002ded8:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      uVar10 = FUN_180029ab0(DAT_180079590,*(longlong *)(*(longlong *)(lVar9 + 0x118) + uVar11 * 8),
                             &local_f8);
      if (-1 < (int)uVar10) {
        puVar8 = (undefined8 *)
                 ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                 CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_f0,local_f8);
        pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                 ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                 CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                           ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_e8,"*");
        pIVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                           (pCVar4);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_108,pIVar5);
        local_110 = 1;
        ATL::CSimpleStringT<char,1>::Concatenate
                  ((CSimpleStringT<char,1> *)local_108,*(char **)pCVar4,
                   *(int *)(*(char **)pCVar4 + -0x10),(char *)*puVar8,
                   *(int *)((char *)*puVar8 + -0x10));
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_118,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   local_108);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_108);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_e8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_f0);
        CStringArray::SetAtGrow
                  (this,*(__int64 *)(param_1 + 0xf0),
                   (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_118);
        CoTaskMemFree(local_f8);
        lVar9 = local_100;
      }
      uVar11 = uVar11 + 1;
    } while (uVar11 < uVar12);
  }
  FUN_180025a20(local_88);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_118);
  return;
}

/* ---- FUNC 0002DEE0 FUN_18002dee0 (205 bytes) ---- */

undefined8 FUN_18002dee0(longlong *param_1,longlong *param_2,longlong *param_3)

{
  *param_3 = 0;
  if ((((*param_2 == DAT_180066c58) && (param_2[1] == DAT_180066c60)) ||
      ((*param_2 == DAT_180066c78 && (param_2[1] == DAT_180066c80)))) ||
     ((*param_2 == DAT_180063430 && (param_2[1] == DAT_180063438)))) {
    *param_3 = (longlong)param_1;
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((*param_2 == DAT_180066ca8) && (param_2[1] == DAT_180066cb0)) {
    *param_3 = (longlong)(param_1 + 5);
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((*param_2 == DAT_180063630) && (param_2[1] == DAT_180063638)) {
    *param_3 = (longlong)(param_1 + 1);
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  return 0x80004002;
}

/* ---- FUNC 0002DFB0 FUN_18002dfb0 (116 bytes) ---- */

undefined8 FUN_18002dfb0(longlong *param_1,longlong *param_2,longlong *param_3)

{
  *param_3 = 0;
  if ((*param_2 == DAT_180066c58) && (param_2[1] == DAT_180066c60)) {
    *param_3 = (longlong)param_1;
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((*param_2 == DAT_180066d48) && ((param_2[1] == DAT_180066d50 && (param_1[0xb] != 0)))) {
    *param_3 = param_1[0xb];
    (**(code **)(*(longlong *)param_1[0xb] + 8))();
    return 0;
  }
  return 0x80004002;
}

/* ---- FUNC 0002E030 FUN_18002e030 (223 bytes) ---- */

undefined8 FUN_18002e030(longlong *param_1,longlong *param_2,longlong *param_3)

{
  *param_3 = 0;
  if ((*param_2 == DAT_180066c58) && (param_2[1] == DAT_180066c60)) {
    *param_3 = (longlong)param_1;
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  if ((((*param_2 != DAT_180066dd8) || (param_2[1] != DAT_180066de0)) &&
      ((*param_2 != DAT_180066d98 || (param_2[1] != DAT_180066da0)))) &&
     ((*param_2 != DAT_180066da8 || (param_2[1] != DAT_180066db0)))) {
    if (((*param_2 == DAT_180066d48) && (param_2[1] == DAT_180066d50)) && (param_1[0x1b] != 0)) {
      *param_3 = param_1[0x1b];
      (**(code **)(*(longlong *)param_1[0x1b] + 8))();
      return 0;
    }
    return 0x80004002;
  }
  *param_3 = (longlong)(param_1 + 0x16);
  (**(code **)(*param_1 + 8))();
  return 0;
}

/* ---- FUNC 0002E110 FUN_18002e110 (60 bytes) ---- */

undefined8 FUN_18002e110(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  
  if ((*param_2 == DAT_180063630) && (param_2[1] == DAT_180063638)) {
    *param_3 = param_1;
    (**(code **)(*param_1 + 8))();
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x00018002e149. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)param_1[-1])(param_1 + -1);
  return uVar1;
}

/* ---- FUNC 0002E150 FUN_18002e150 (404 bytes) ---- */

undefined8 FUN_18002e150(longlong param_1,uint param_2)

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
    (*local_res8->lpVtbl->SetGUID)(local_res8,(GUID *)&DAT_180063410);
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

/* ---- FUNC 0002E2F0 FUN_18002e2f0 (50 bytes) ---- */

undefined8 FUN_18002e2f0(longlong param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 *puVar4;
  longlong *local_res8;
  undefined8 local_res10;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res18 [8];
  VARIANTARG local_38;
  
  VariantInit(&local_38);
  local_res10 = 0;
  if ((*(int *)(param_1 + 0x30) == 3) && (*(longlong *)(param_1 + 0x28) != 0)) {
    iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       (param_1 + 0x18),'x',0);
    if (iVar1 != -1) {
      puVar4 = (undefined8 *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          (param_1 + 0x18),(int)local_res18);
      iVar1 = atoi((char *)*puVar4);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
      puVar4 = (undefined8 *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          (param_1 + 0x18),(int)local_res18);
      iVar2 = atoi((char *)*puVar4);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
      iVar3 = (**(code **)(**(longlong **)(param_1 + 0x28) + 200))
                        (*(longlong **)(param_1 + 0x28),&local_res8);
      if (-1 < iVar3) {
        (**(code **)(*local_res8 + 0x90))(local_res8,iVar1,iVar2,&local_38,&local_res10);
        (**(code **)(*local_res8 + 0x10))();
      }
    }
    return local_res10;
  }
  return 0;
}

/* ---- FUNC 0002E322 FUN_18002e322 (39 bytes) ---- */

undefined8 FUN_18002e322(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 *puVar4;
  longlong unaff_RBX;
  longlong *in_stack_00000070;
  undefined8 in_stack_00000078;
  
  iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                     (unaff_RBX + 0x18),'x',0);
  if (iVar1 != -1) {
    puVar4 = (undefined8 *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                       ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                        (unaff_RBX + 0x18),(int)&stack0x00000080);
    iVar1 = atoi((char *)*puVar4);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000080);
    puVar4 = (undefined8 *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                       ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                        (unaff_RBX + 0x18),(int)&stack0x00000080);
    iVar2 = atoi((char *)*puVar4);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000080);
    iVar3 = (**(code **)(**(longlong **)(unaff_RBX + 0x28) + 200))
                      (*(longlong **)(unaff_RBX + 0x28),&stack0x00000070);
    if (-1 < iVar3) {
      (**(code **)(*in_stack_00000070 + 0x90))
                (in_stack_00000070,iVar1,iVar2,&stack0x00000030,&stack0x00000078);
      (**(code **)(*in_stack_00000070 + 0x10))();
    }
  }
  return in_stack_00000078;
}

/* ---- FUNC 0002E349 FUN_18002e349 (175 bytes) ---- */

undefined8 FUN_18002e349(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 *puVar4;
  longlong unaff_RBX;
  longlong *in_stack_00000070;
  undefined8 in_stack_00000078;
  
  puVar4 = (undefined8 *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                     ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                      (unaff_RBX + 0x18),(int)&stack0x00000080);
  iVar1 = atoi((char *)*puVar4);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000080);
  puVar4 = (undefined8 *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                     ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                      (unaff_RBX + 0x18),(int)&stack0x00000080);
  iVar2 = atoi((char *)*puVar4);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000080);
  iVar3 = (**(code **)(**(longlong **)(unaff_RBX + 0x28) + 200))
                    (*(longlong **)(unaff_RBX + 0x28),&stack0x00000070);
  if (-1 < iVar3) {
    (**(code **)(*in_stack_00000070 + 0x90))
              (in_stack_00000070,iVar1,iVar2,&stack0x00000030,&stack0x00000078);
    (**(code **)(*in_stack_00000070 + 0x10))();
  }
  return in_stack_00000078;
}

/* ---- FUNC 0002E3F8 FUN_18002e3f8 (21 bytes) ---- */

undefined8 FUN_18002e3f8(void)

{
  undefined8 in_stack_00000078;
  
  return in_stack_00000078;
}

/* ---- FUNC 0002E40D FUN_18002e40d (8 bytes) ---- */

undefined8 FUN_18002e40d(void)

{
  return 0;
}

/* ---- FUNC 0002E420 FUN_18002e420 (46 bytes) ---- */

int FUN_18002e420(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4) + -1;
  *(int *)(param_1 + 4) = iVar1;
  if (iVar1 == 0) {
    FUN_180025730(param_1);
    FUN_180025ad0(param_1);
    iVar1 = 0;
  }
  return iVar1;
}

/* ---- FUNC 0002E450 FUN_18002e450 (46 bytes) ---- */

int FUN_18002e450(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4) + -1;
  *(int *)(param_1 + 4) = iVar1;
  if (iVar1 == 0) {
    FUN_1800257d0(param_1);
    FUN_180025ad0(param_1);
    iVar1 = 0;
  }
  return iVar1;
}

/* ---- FUNC 0002E480 FUN_18002e480 (46 bytes) ---- */

int FUN_18002e480(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 9) + -1;
  *(int *)(param_1 + 9) = iVar1;
  if (iVar1 == 0) {
    FUN_180025950(param_1);
    FUN_180025ad0(param_1);
    iVar1 = 0;
  }
  return iVar1;
}

/* ---- FUNC 0002E4B0 FUN_18002e4b0 (3 bytes) ---- */

undefined8 FUN_18002e4b0(void)

{
  return 0;
}

/* ---- FUNC 0002E4C0 FUN_18002e4c0 (931 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined8 FUN_18002e4c0(longlong *param_1,VARIANTARG *param_2)

{
  undefined1 *puVar1;
  ushort uVar2;
  int iVar3;
  _union_1719 _Var4;
  HRESULT HVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  int iVar8;
  longlong lVar9;
  undefined8 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  LPCWSTR lpWideCharStr;
  longlong lVar13;
  undefined8 *puVar14;
  undefined *puStack_a0;
  undefined1 auStack_98 [32];
  undefined8 uStack_78;
  int aiStack_70 [2];
  undefined8 local_68 [2];
  VARIANTARG local_58;
  void *local_40;
  undefined4 local_38;
  ULONG UStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined8 local_28;
  ulonglong local_18;
  
  puVar12 = auStack_98;
  puVar11 = auStack_98;
  local_18 = DAT_180077818 ^ (ulonglong)&local_58;
  if ((int)param_1[2] != 0) {
    uVar6 = 1;
    puVar11 = auStack_98;
    goto LAB_18002e786;
  }
  uVar2 = (param_2->n1).n2.vt;
  if (0x4002 < uVar2) {
    if (uVar2 == 0x4003) {
      local_58.n1._8_4_ = **(int **)((longlong)&param_2->n1 + 8);
      goto LAB_18002e7f6;
    }
    if (uVar2 == 0x4008) {
      lpWideCharStr = (LPCWSTR)**(longlong **)((longlong)&param_2->n1 + 8);
      puVar12 = auStack_98;
      if (lpWideCharStr != (LPCWSTR)0x0) {
        lVar9 = -1;
        do {
          lVar9 = lVar9 + 1;
        } while (lpWideCharStr[lVar9] != L'\0');
        goto LAB_18002e63b;
      }
      goto LAB_18002e84e;
    }
    if (uVar2 != 0x4009) {
      if (uVar2 == 0x400c) {
        puVar14 = *(undefined8 **)((longlong)&param_2->n1 + 8);
        _Var4 = *(_union_1719 *)(puVar14 + 1);
        *(undefined8 *)&param_2->n1 = *puVar14;
        (param_2->n1).decVal.u2 = _Var4;
        local_28 = puVar14[2];
        lVar9 = *param_1;
        *(undefined8 *)((longlong)&param_2->n1 + 0x10) = local_28;
        local_38 = *(undefined4 *)&param_2->n1;
        UStack_34 = (param_2->n1).decVal.Hi32;
        uStack_30 = *(undefined4 *)((longlong)&param_2->n1 + 8);
        uStack_2c = *(undefined4 *)((longlong)&param_2->n1 + 0xc);
        puStack_a0 = (undefined *)0x18002e6e7;
        uVar6 = (**(code **)(lVar9 + 0x88))(param_1,&local_38);
        goto LAB_18002e786;
      }
      if (uVar2 != 0x400d) goto switchD_18002e525_caseD_1;
    }
    puVar14 = (undefined8 *)**(undefined8 **)((longlong)&param_2->n1 + 8);
LAB_18002e6f3:
    lVar9 = param_1[0x16];
    iVar8 = 0;
    if (0 < lVar9) {
      lVar13 = 0;
      do {
        if ((lVar13 < 0) || (lVar9 <= lVar13)) {
                    /* WARNING: Subroutine does not return */
          puStack_a0 = &UNK_18002e863;
          AfxThrowInvalidArgException();
        }
        puVar10 = *(undefined8 **)(param_1[0x15] + lVar13 * 8);
        if ((puVar10 != (undefined8 *)0x0) &&
           (((puVar14 != (undefined8 *)0x0 && ((undefined8 *)puVar10[0xb] == puVar14)) ||
            (((iVar3 = *(int *)(puVar10 + 6), iVar3 == 0 || ((iVar3 == 1 || (iVar3 == 100)))) &&
             ((undefined8 *)puVar10[5] == puVar14)))))) {
          puStack_a0 = (undefined *)0x18002e7b5;
          CPtrArray::RemoveAt((CPtrArray *)(param_1 + 0x14),(longlong)iVar8,1);
          goto LAB_18002e7b5;
        }
        iVar8 = iVar8 + 1;
        lVar13 = lVar13 + 1;
      } while (iVar8 < lVar9);
    }
    puStack_a0 = (undefined *)0x18002e768;
    iVar8 = (**(code **)*puVar14)(puVar14,&DAT_180063400,&local_40);
    puVar12 = auStack_98;
    if (iVar8 < 0) goto LAB_18002e84e;
    puStack_a0 = (undefined *)0x18002e784;
    CPtrArray::SetAtGrow((CPtrArray *)(param_1 + 0x19),param_1[0x1b],local_40);
    goto LAB_18002e784;
  }
  if (uVar2 == 0x4002) {
    local_58.n1._8_4_ = SEXT24(**(short **)((longlong)&param_2->n1 + 8));
    goto LAB_18002e7f6;
  }
  switch(uVar2) {
  default:
switchD_18002e525_caseD_1:
    puStack_a0 = (undefined *)0x18002e5c1;
    VariantInit(&local_58);
    puStack_a0 = (undefined *)0x18002e5d7;
    HVar5 = VariantChangeType(&local_58,param_2,0,3);
    if (HVar5 == 0) {
      puStack_a0 = (undefined *)0x18002e5e8;
      VariantClear(&local_58);
      goto LAB_18002e7f6;
    }
    puStack_a0 = (undefined *)0x18002e5f3;
    VariantClear(&local_58);
    puStack_a0 = (undefined *)0x18002e609;
    HVar5 = VariantChangeType(&local_58,param_2,0,8);
    if (HVar5 == 0) {
      lpWideCharStr = (LPCWSTR)CONCAT44(local_58.n1._12_4_,local_58.n1._8_4_);
      puVar12 = auStack_98;
      if (lpWideCharStr != (LPCWSTR)0x0) {
        lVar9 = -1;
        do {
          lVar9 = lVar9 + 1;
        } while (lpWideCharStr[lVar9] != L'\0');
        goto LAB_18002e63b;
      }
      goto LAB_18002e84e;
    }
    puStack_a0 = (undefined *)0x18002e617;
    VariantClear(&local_58);
  case 0:
  case 10:
    puStack_a0 = (undefined *)0x18002e538;
    uVar6 = (**(code **)(*param_1 + 0xd8))(param_1,0x7db);
    puVar11 = auStack_98;
    break;
  case 2:
    local_58.n1._8_4_ = SEXT24(*(short *)((longlong)&param_2->n1 + 8));
    goto LAB_18002e7f6;
  case 3:
    local_58.n1._8_4_ = *(int *)((longlong)&param_2->n1 + 8);
LAB_18002e7f6:
    lVar9 = (longlong)(int)local_58.n1._8_4_;
    if (param_1[0x16] + -1 < lVar9) {
      puStack_a0 = (undefined *)0x18002e81a;
      uVar6 = (**(code **)(*param_1 + 0xd8))(param_1,0x7de);
      puVar11 = auStack_98;
    }
    else {
      if (((int)local_58.n1._8_4_ < 0) || (param_1[0x16] <= lVar9)) {
                    /* WARNING: Subroutine does not return */
        puStack_a0 = &UNK_18002e85d;
        AfxThrowInvalidArgException();
      }
      puVar10 = *(undefined8 **)(param_1[0x15] + lVar9 * 8);
      puStack_a0 = (undefined *)0x18002e845;
      CPtrArray::RemoveAt((CPtrArray *)(param_1 + 0x14),lVar9,1);
      puVar12 = auStack_98;
      if (puVar10 == (undefined8 *)0x0) {
LAB_18002e84e:
        uVar6 = 0x80004005;
        puVar11 = puVar12;
      }
      else {
LAB_18002e7b5:
        puStack_a0 = (undefined *)0x18002e7c2;
        (**(code **)*puVar10)(puVar10,1);
LAB_18002e784:
        uVar6 = 0;
        puVar11 = auStack_98;
      }
    }
    break;
  case 8:
    lpWideCharStr = *(LPCWSTR *)((longlong)&param_2->n1 + 8);
    if (lpWideCharStr != (LPCWSTR)0x0) {
      lVar9 = -1;
      do {
        lVar9 = lVar9 + 1;
      } while (lpWideCharStr[lVar9] != L'\0');
LAB_18002e63b:
      iVar8 = (int)lVar9;
      puVar12 = auStack_98;
      if (iVar8 < 0x3fffffff) {
        uVar7 = (longlong)iVar8 * 2 + 0x11;
        if (uVar7 <= (longlong)iVar8 * 2 + 2U) {
          uVar7 = 0xffffffffffffff0;
        }
        puStack_a0 = (undefined *)0x18002e671;
        lVar9 = -(uVar7 & 0xfffffffffffffff0);
        puVar11 = auStack_98 + lVar9;
        puVar1 = (undefined1 *)((longlong)&local_58 + lVar9);
        puVar12 = auStack_98 + lVar9;
        if (puVar1 != (undefined1 *)0x0) {
          *puVar1 = 0;
          *(undefined8 *)((longlong)local_68 + lVar9 + 8) = 0;
          *(undefined8 *)((longlong)local_68 + lVar9) = 0;
          *(int *)((longlong)aiStack_70 + lVar9) = iVar8 * 2 + 2;
          *(undefined1 **)((longlong)&uStack_78 + lVar9) = puVar1;
          *(undefined8 *)(auStack_98 + lVar9 + -8) = 0x18002e6ad;
          WideCharToMultiByte(0,0,lpWideCharStr,-1,*(LPSTR *)((longlong)&uStack_78 + lVar9),
                              *(int *)((longlong)aiStack_70 + lVar9),
                              *(LPCSTR *)((longlong)local_68 + lVar9),
                              *(LPBOOL *)((longlong)local_68 + lVar9 + 8));
          uVar6 = 0x80004005;
          break;
        }
      }
    }
    goto LAB_18002e84e;
  case 9:
  case 0xd:
    puVar14 = *(undefined8 **)((longlong)&param_2->n1 + 8);
    goto LAB_18002e6f3;
  }
LAB_18002e786:
  *(undefined8 *)(puVar11 + -8) = 0x18002e792;
  return uVar6;
}

/* ---- FUNC 0002E8A0 FUN_18002e8a0 (81 bytes) ---- */

void FUN_18002e8a0(longlong *param_1)

{
  longlong lVar1;
  
  if ((longlong *)param_1[0x15] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x15] + 0x10))();
    param_1[0x15] = 0;
  }
  lVar1 = FUN_18002a120(param_1);
  if (lVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018002e8e7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(param_1[3] + 8))(param_1 + 3,param_1[0x15]);
    return;
  }
  return;
}

/* ---- FUNC 0002E900 FUN_18002e900 (143 bytes) ---- */

undefined8 FUN_18002e900(longlong param_1,undefined8 *param_2)

{
  int iVar1;
  UINT UVar2;
  longlong *local_res8 [4];
  undefined1 local_48 [8];
  undefined8 local_40;
  undefined2 local_30 [4];
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_res8[0] = (longlong *)0x0;
  iVar1 = (**(code **)(*(longlong *)(param_1 + 0x18) + 0x10))
                    (param_1 + 0x18,DAT_180079208,local_res8);
  if (-1 < iVar1) {
    UVar2 = RegisterClipboardFormatA("Print Text");
    local_20 = 1;
    local_28 = 0;
    local_18 = 1;
    local_1c = 0xffffffff;
    local_30[0] = (short)UVar2;
    (**(code **)(*local_res8[0] + 0x18))(local_res8[0],local_30,local_48);
    *param_2 = local_40;
    (**(code **)(*local_res8[0] + 0x10))();
  }
  return 0;
}

/* ---- FUNC 0002E990 FUN_18002e990 (430 bytes) ---- */

ulonglong FUN_18002e990(longlong param_1,IStream *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  int iVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong local_res8;
  void *local_res10;
  ulonglong local_res18 [2];
  undefined8 local_48 [2];
  
  (*param_2->lpVtbl->Write)(param_2,(void *)(param_1 + 0x80),4,(ULONG *)0x0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10);
  uVar2 = FUN_180029b50(param_1,(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                &local_res10);
  uVar6 = uVar2 & 0xffffffff;
  if ((int)uVar2 < 0) goto LAB_18002ea76;
  local_res8 = (longlong)(*(int *)((longlong)local_res10 + -0x10) + 1);
  (*param_2->lpVtbl->Write)(param_2,&local_res8,4,(ULONG *)0x0);
  (*param_2->lpVtbl->Write)(param_2,local_res10,(ULONG)local_res8,(ULONG *)0x0);
  FUN_1800255a0(local_48);
  local_res8 = *(longlong *)(param_1 + 0x40);
  (*param_2->lpVtbl->Write)(param_2,&local_res8,4,(ULONG *)0x0);
  if (local_res8 == 0) {
    uVar2 = FUN_18002ec50(local_48,param_2,*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x28));
    if (-1 < (int)uVar2) goto LAB_18002ea68;
  }
  else {
    iVar4 = 0;
    if (0 < (int)local_res8) {
      lVar5 = 0;
      do {
        if ((lVar5 < 0) || (*(longlong *)(param_1 + 0x40) <= lVar5)) {
LAB_18002eb39:
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x38) + lVar5 * 8);
        uVar2 = 0;
        local_res18[0] = *(ulonglong *)(lVar1 + 0x10);
        (*param_2->lpVtbl->Write)(param_2,local_res18,4,(ULONG *)0x0);
        if (local_res18[0] != 0) {
          do {
            if (((longlong)uVar2 < 0) || (*(longlong *)(lVar1 + 0x10) <= (longlong)uVar2))
            goto LAB_18002eb39;
            uVar3 = FUN_18002ec50(local_48,param_2,
                                  *(longlong *)(*(longlong *)(lVar1 + 8) + uVar2 * 8));
            if ((int)uVar3 < 0) goto LAB_18002ea6b;
            uVar2 = uVar2 + 1;
          } while (uVar2 < local_res18[0]);
        }
        iVar4 = iVar4 + 1;
        lVar5 = lVar5 + 1;
      } while (iVar4 < (int)(ULONG)local_res8);
    }
LAB_18002ea68:
    uVar6 = 0;
  }
LAB_18002ea6b:
  FUN_180025a20(local_48);
LAB_18002ea76:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10);
  return uVar6;
}

/* ---- FUNC 0002EB40 FUN_18002eb40 (260 bytes) ---- */

undefined8 FUN_18002eb40(longlong param_1,longlong *param_2)

{
  ulonglong uVar1;
  int local_res8 [2];
  longlong local_res10;
  ulonglong local_res18 [2];
  
  if (*(longlong *)(param_1 + 0xf0) == 0) {
    FUN_18002d600(param_1);
  }
  local_res8[0] = *(int *)(*(longlong *)(param_1 + 0x10) + -0x10) + 1;
  (**(code **)(*param_2 + 0x20))(param_2,local_res8,4);
  (**(code **)(*param_2 + 0x20))(param_2,*(undefined8 *)(param_1 + 0x10),local_res8[0],0);
  local_res18[0] = *(ulonglong *)(param_1 + 0xf0);
  (**(code **)(*param_2 + 0x20))(param_2,local_res18,4);
  uVar1 = 0;
  if (local_res18[0] != 0) {
    do {
      if (((longlong)uVar1 < 0) || (*(longlong *)(param_1 + 0xf0) <= (longlong)uVar1)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 (*(longlong *)(param_1 + 0xe8) + uVar1 * 8));
      local_res8[0] = *(int *)(local_res10 + -0x10) + 1;
      (**(code **)(*param_2 + 0x20))(param_2,local_res8,4);
      (**(code **)(*param_2 + 0x20))(param_2,local_res10,local_res8[0]);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10);
      uVar1 = uVar1 + 1;
    } while (uVar1 < local_res18[0]);
  }
  return 0;
}

/* ---- FUNC 0002EC50 FUN_18002ec50 (146 bytes) ---- */

ulonglong FUN_18002ec50(undefined8 param_1,IStream *param_2,longlong param_3)

{
  uint uVar1;
  ulonglong uVar2;
  uint local_res10 [2];
  LPPERSISTSTREAM local_res18;
  
  uVar2 = 0;
  local_res10[0] = (uint)(param_3 != 0);
  (*param_2->lpVtbl->Write)(param_2,local_res10,4,(ULONG *)0x0);
  if ((local_res10[0] != 0) &&
     (uVar2 = (**(code **)(**(longlong **)(DAT_1800797f0 + 0x118) + 0x98))
                        (*(longlong **)(DAT_1800797f0 + 0x118),*(undefined8 *)(param_3 + 0xe8),
                         &local_res18), -1 < (int)uVar2)) {
    uVar1 = OleSaveToStream(local_res18,param_2);
    uVar2 = (ulonglong)uVar1;
    (*local_res18->lpVtbl->Release)(local_res18);
  }
  return uVar2;
}

/* ---- FUNC 0002ECF0 FUN_18002ecf0 (1133 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_18002ecf0(longlong param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 *puVar1;
  longlong *plVar2;
  code *pcVar3;
  _func_5262 *p_Var4;
  IBindCtx *pIVar5;
  WCHAR WVar6;
  ulonglong uVar7;
  longlong lVar8;
  longlong lVar9;
  int iVar10;
  LPCWSTR pWVar11;
  WCHAR *pWVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  ulonglong uVar17;
  undefined1 *puVar18;
  LPCWSTR lpWideCharStr;
  WCHAR *lpWideCharStr_00;
  undefined8 uVar19;
  WCHAR **ppWVar20;
  longlong lVar21;
  bool bVar22;
  undefined8 uStack_2d0;
  undefined1 auStack_2c8 [32];
  undefined8 uStack_2a8;
  int aiStack_2a0 [2];
  undefined8 local_298 [2];
  int local_288 [2];
  WCHAR *local_280;
  IBindCtx *local_278;
  undefined8 local_270;
  longlong local_268;
  undefined1 *local_260;
  longlong local_258;
  longlong local_250;
  char local_248 [512];
  ulonglong local_48;
  
  puVar13 = auStack_2c8;
  puVar15 = auStack_2c8;
  local_48 = DAT_180077818 ^ (ulonglong)local_288;
  uStack_2d0 = 0x18002ed41;
  local_250 = param_1;
  FUN_180002a20(local_248,"usegridtext = %d\n",(ulonglong)*(uint *)(param_1 + 0x80),param_4);
  lVar8 = -1;
  do {
    lVar9 = lVar8 + 1;
    lVar8 = lVar8 + 1;
  } while (local_248[lVar9] != '\0');
  uVar19 = 0;
  uStack_2d0 = 0x18002ed69;
  (**(code **)(*param_2 + 0x20))(param_2,local_248);
  uStack_2d0 = 0x18002ed73;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_270);
  uStack_2d0 = 0x18002ed80;
  uVar7 = FUN_180029b50(param_1,(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                &local_270);
  uVar17 = uVar7 & 0xffffffff;
  if ((int)uVar7 < 0) goto LAB_18002ef4f;
  uStack_2d0 = 0x18002ed9e;
  FUN_180002a20(local_248,&DAT_180064d28,local_270,uVar19);
  lVar8 = -1;
  do {
    lVar9 = lVar8 + 1;
    lVar8 = lVar8 + 1;
  } while (local_248[lVar9] != '\0');
  uVar19 = 0;
  uStack_2d0 = 0x18002edc7;
  (**(code **)(*param_2 + 0x20))(param_2,local_248);
  uStack_2d0 = 0x18002edd3;
  CreateBindCtx(0,&local_278);
  lVar8 = *(longlong *)(param_1 + 0x40);
  uStack_2d0 = 0x18002edee;
  local_258 = lVar8;
  FUN_180002a20(local_248,"linkto = %llu\n",lVar8,uVar19);
  lVar9 = -1;
  do {
    lVar21 = lVar9 + 1;
    lVar9 = lVar9 + 1;
  } while (local_248[lVar21] != '\0');
  uVar19 = 0;
  uStack_2d0 = 0x18002ee17;
  (**(code **)(*param_2 + 0x20))(param_2,local_248);
  if (lVar8 == 0) {
    plVar2 = *(longlong **)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x28) + 0xe8);
    ppWVar20 = &local_280;
    uStack_2d0 = 0x18002ee43;
    (**(code **)(*plVar2 + 0xa0))(plVar2,local_278,0);
    WVar6 = *local_280;
    pWVar11 = local_280;
    while ((WVar6 != L'!' && (bVar22 = WVar6 != L'\0', WVar6 = L'\0', bVar22))) {
      pWVar11 = pWVar11 + 1;
      WVar6 = *pWVar11;
    }
    lpWideCharStr = pWVar11 + 1;
    if (WVar6 != L'!') {
      lpWideCharStr = pWVar11;
    }
    puVar15 = auStack_2c8;
    if (lpWideCharStr == (LPCWSTR)0x0) {
LAB_18002eeff:
      puVar13 = (undefined1 *)0x0;
    }
    else {
      lVar8 = -1;
      do {
        lVar9 = lVar8;
        lVar8 = lVar9 + 1;
      } while (lpWideCharStr[lVar8] != L'\0');
      iVar10 = (int)lVar9 + 2;
      puVar15 = auStack_2c8;
      if (0x3fffffff < iVar10) goto LAB_18002eeff;
      lVar8 = (longlong)(int)lVar8 * 2;
      uVar7 = lVar8 + 0x11;
      if (uVar7 <= lVar8 + 2U) {
        uVar7 = 0xffffffffffffff0;
      }
      uStack_2d0 = 0x18002eec2;
      lVar8 = -(uVar7 & 0xfffffffffffffff0);
      puVar15 = auStack_2c8 + lVar8;
      puVar13 = (undefined1 *)((longlong)local_288 + lVar8);
      if (puVar13 == (undefined1 *)0x0) goto LAB_18002eeff;
      *puVar13 = 0;
      *(undefined8 *)((longlong)local_298 + lVar8 + 8) = 0;
      *(undefined8 *)((longlong)local_298 + lVar8) = 0;
      *(int *)((longlong)aiStack_2a0 + lVar8) = iVar10 * 2;
      *(undefined1 **)((longlong)&uStack_2a8 + lVar8) = puVar13;
      ppWVar20 = (WCHAR **)0xffffffff;
      *(undefined8 *)(auStack_2c8 + lVar8 + -8) = 0x18002eef7;
      iVar10 = WideCharToMultiByte(0,0,lpWideCharStr,-1,*(LPSTR *)((longlong)&uStack_2a8 + lVar8),
                                   *(int *)((longlong)aiStack_2a0 + lVar8),
                                   *(LPCSTR *)((longlong)local_298 + lVar8),
                                   *(LPBOOL *)((longlong)local_298 + lVar8 + 8));
      puVar15 = auStack_2c8 + lVar8;
      if (iVar10 == 0) {
        puVar13 = (undefined1 *)0x0;
        puVar15 = auStack_2c8 + lVar8;
      }
    }
    *(undefined8 *)(puVar15 + -8) = 0x18002ef16;
    FUN_180002a20(local_248,&DAT_180064d28,puVar13,ppWVar20);
    lVar8 = -1;
    do {
      lVar21 = lVar8 + 1;
      lVar9 = lVar8 + 1;
      lVar8 = lVar21;
    } while (local_248[lVar9] != '\0');
    pcVar3 = *(code **)(*param_2 + 0x20);
    *(undefined8 *)(puVar15 + -8) = 0x18002ef3a;
    (*pcVar3)(param_2,local_248,lVar21,0);
    *(undefined8 *)(puVar15 + -8) = 0x18002ef44;
    CoTaskMemFree(local_280);
    puVar13 = puVar15;
  }
  else {
    puVar18 = (undefined1 *)0x0;
    local_288[0] = 0;
    puVar13 = auStack_2c8;
    if (0 < (int)lVar8) {
      local_268 = 0;
      do {
        puVar13 = puVar15;
        if ((local_268 < 0) || (*(longlong *)(param_1 + 0x40) <= local_268)) {
LAB_18002f158:
                    /* WARNING: Subroutine does not return */
          *(undefined **)(puVar13 + -8) = &UNK_18002f15d;
          AfxThrowInvalidArgException();
        }
        lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x38) + local_268 * 8);
        puVar14 = *(undefined1 **)(lVar8 + 0x10);
        local_260 = puVar14;
        *(undefined8 *)(puVar15 + -8) = 0x18002efd9;
        FUN_180002a20(local_248,"size = %llu\n",puVar14,uVar19);
        lVar9 = -1;
        do {
          lVar21 = lVar9 + 1;
          lVar9 = lVar9 + 1;
        } while (local_248[lVar21] != '\0');
        uVar19 = 0;
        pcVar3 = *(code **)(*param_2 + 0x20);
        *(undefined8 *)(puVar15 + -8) = 0x18002eff9;
        (*pcVar3)(param_2,local_248);
        puVar16 = puVar18;
        if (puVar14 != (undefined1 *)0x0) {
          do {
            pIVar5 = local_278;
            if (((longlong)puVar16 < 0) || (*(longlong *)(lVar8 + 0x10) <= (longlong)puVar16))
            goto LAB_18002f158;
            plVar2 = *(longlong **)
                      (*(longlong *)(*(longlong *)(lVar8 + 8) + (longlong)puVar16 * 8) + 0xe8);
            ppWVar20 = &local_280;
            pcVar3 = *(code **)(*plVar2 + 0xa0);
            *(undefined8 *)(puVar13 + -8) = 0x18002f038;
            (*pcVar3)(plVar2,pIVar5,0);
            WVar6 = *local_280;
            pWVar12 = local_280;
            while ((WVar6 != L'!' && (bVar22 = WVar6 != L'\0', WVar6 = L'\0', bVar22))) {
              pWVar12 = pWVar12 + 1;
              WVar6 = *pWVar12;
            }
            lpWideCharStr_00 = pWVar12 + 1;
            if (WVar6 != L'!') {
              lpWideCharStr_00 = pWVar12;
            }
            puVar14 = puVar18;
            puVar15 = puVar13;
            if (lpWideCharStr_00 != (LPCWSTR)0x0) {
              lVar9 = -1;
              do {
                lVar21 = lVar9;
                lVar9 = lVar21 + 1;
              } while (lpWideCharStr_00[lVar9] != L'\0');
              iVar10 = (int)lVar21 + 2;
              if (iVar10 < 0x40000000) {
                lVar9 = (longlong)(int)lVar9 * 2;
                uVar7 = lVar9 + 0x11;
                if (uVar7 <= lVar9 + 2U) {
                  uVar7 = 0xffffffffffffff0;
                }
                *(undefined8 *)(puVar13 + -8) = 0x18002f0ab;
                lVar9 = -(uVar7 & 0xfffffffffffffff0);
                puVar1 = puVar13 + lVar9 + 0x40;
                puVar15 = puVar13 + lVar9;
                if (puVar1 != (undefined1 *)0x0) {
                  *puVar1 = 0;
                  *(undefined8 *)(puVar13 + lVar9 + 0x38) = 0;
                  *(undefined8 *)(puVar13 + lVar9 + 0x30) = 0;
                  *(int *)(puVar13 + lVar9 + 0x28) = iVar10 * 2;
                  *(undefined1 **)(puVar13 + lVar9 + 0x20) = puVar1;
                  ppWVar20 = (WCHAR **)0xffffffff;
                  *(undefined8 *)(puVar13 + lVar9 + -8) = 0x18002f0de;
                  iVar10 = WideCharToMultiByte(0,0,lpWideCharStr_00,-1,
                                               *(LPSTR *)(puVar13 + lVar9 + 0x20),
                                               *(int *)(puVar13 + lVar9 + 0x28),
                                               *(LPCSTR *)(puVar13 + lVar9 + 0x30),
                                               *(LPBOOL *)(puVar13 + lVar9 + 0x38));
                  puVar14 = puVar1;
                  puVar15 = puVar13 + lVar9;
                  if (iVar10 == 0) {
                    puVar14 = puVar18;
                    puVar15 = puVar13 + lVar9;
                  }
                }
              }
            }
            *(undefined8 *)(puVar15 + -8) = 0x18002f0fc;
            FUN_180002a20(local_248,&DAT_180064d28,puVar14,ppWVar20);
            lVar9 = -1;
            do {
              lVar21 = lVar9 + 1;
              lVar9 = lVar9 + 1;
            } while (local_248[lVar21] != '\0');
            uVar19 = 0;
            pcVar3 = *(code **)(*param_2 + 0x20);
            *(undefined8 *)(puVar15 + -8) = 0x18002f11c;
            (*pcVar3)(param_2,local_248);
            pWVar12 = local_280;
            *(undefined8 *)(puVar15 + -8) = 0x18002f126;
            CoTaskMemFree(pWVar12);
            puVar16 = puVar16 + 1;
            puVar13 = puVar15;
          } while (puVar16 < local_260);
        }
        local_288[0] = local_288[0] + 1;
        local_268 = local_268 + 1;
        param_1 = local_250;
        puVar13 = puVar15;
      } while (local_288[0] < (int)local_258);
    }
  }
  uVar17 = 0;
  p_Var4 = local_278->lpVtbl->Release;
  *(undefined8 *)(puVar13 + -8) = 0x18002ef4e;
  (*p_Var4)(local_278);
LAB_18002ef4f:
  *(undefined8 *)(puVar13 + -8) = 0x18002ef59;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_270);
  *(undefined8 *)(puVar13 + -8) = 0x18002ef6a;
  return uVar17;
}

/* ---- FUNC 0002F160 FUN_18002f160 (340 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18002f160(longlong param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined1 auStack_258 [32];
  longlong local_238 [2];
  char local_228 [512];
  ulonglong local_28;
  longlong lVar4;
  
  local_28 = DAT_180077818 ^ (ulonglong)auStack_258;
  if (*(longlong *)(param_1 + 0xf0) == 0) {
    FUN_18002d600(param_1);
  }
  FUN_180002a20(local_228,&DAT_180064d28,*(undefined8 *)(param_1 + 0x10),param_4);
  lVar4 = -1;
  do {
    lVar2 = lVar4 + 1;
    lVar4 = lVar4 + 1;
  } while (local_228[lVar2] != '\0');
  uVar6 = 0;
  (**(code **)(*param_2 + 0x20))(param_2,local_228);
  uVar1 = *(ulonglong *)(param_1 + 0xf0);
  FUN_180002a20(local_228,"count = %llu\n",uVar1,uVar6);
  lVar4 = -1;
  do {
    lVar3 = lVar4 + 1;
    lVar2 = lVar4 + 1;
    lVar4 = lVar3;
  } while (local_228[lVar2] != '\0');
  (**(code **)(*param_2 + 0x20))(param_2,local_228,lVar3,0);
  uVar5 = 0;
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar5 < 0) || (*(longlong *)(param_1 + 0xf0) <= (longlong)uVar5)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_238,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 (*(longlong *)(param_1 + 0xe8) + uVar5 * 8));
      (**(code **)(*param_2 + 0x20))(param_2,local_238[0],*(undefined4 *)(local_238[0] + -0x10),0);
      (**(code **)(*param_2 + 0x20))(param_2,&DAT_180064d40,1);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_238);
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
  }
  return 0;
}

/* ---- FUNC 0002F2C0 FUN_18002f2c0 (124 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char FUN_18002f2c0(void)

{
  LCID Locale;
  int iVar1;
  undefined1 auStack_38 [32];
  char local_18 [8];
  ulonglong local_10;
  
  local_10 = DAT_180077818 ^ (ulonglong)auStack_38;
  if (DAT_180079598 == '\0') {
    DAT_180079598 = '.';
    Locale = GetUserDefaultLCID();
    iVar1 = GetLocaleInfoA(Locale,0xe,local_18,5);
    if (iVar1 != 0) {
      DAT_180079598 = local_18[0];
      return local_18[0];
    }
  }
  return DAT_180079598;
}

/* ---- FUNC 0002F340 FUN_18002f340 (530 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_18002f340(longlong param_1,char *param_2)

{
  longlong *plVar1;
  int iVar2;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  IAtlStringMgr *pIVar3;
  longlong lVar4;
  char *pcVar5;
  longlong lVar6;
  size_t _MaxCount;
  int iVar7;
  undefined1 auStackY_488 [32];
  char *local_458;
  undefined4 local_450;
  IBindCtx *local_448;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_440 [8];
  wchar_t *local_438;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_430 [8];
  undefined1 local_428 [1008];
  ulonglong local_38;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStackY_488;
  iVar7 = 0;
  local_450 = 0;
  if (*(int *)(param_1 + 8) != 0x10) {
    FUN_180002a20(local_428,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\HappSel.cpp",0x13e9);
    LogMessage(local_428,2,1);
  }
  CreateBindCtx(0,&local_448);
  plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x10) + 0x118);
  iVar2 = (**(code **)(*plVar1 + 0xa0))(plVar1,local_448,0,&local_438);
  if (iVar2 < 0) {
    (*local_448->lpVtbl->Release)(local_448);
    return iVar2;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_458,local_438);
  CoTaskMemFree(local_438);
  (*local_448->lpVtbl->Release)(local_448);
  lVar6 = -1;
  _MaxCount = 0xffffffffffffffff;
  do {
    _MaxCount = _MaxCount + 1;
  } while (local_458[_MaxCount] != '\0');
  iVar2 = strncmp(local_458,param_2,_MaxCount);
  if (iVar2 == 0) {
    lVar4 = -1;
    do {
      lVar4 = lVar4 + 1;
    } while (local_458[lVar4] != '\0');
    if (param_2[lVar4] != '!') {
      lVar4 = -1;
      do {
        lVar4 = lVar4 + 1;
      } while (local_458[lVar4] != '\0');
      if (param_2[lVar4] != '\\') goto LAB_18002f510;
    }
    this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
           CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_430,"~");
    lVar4 = -1;
    do {
      lVar4 = lVar4 + 1;
    } while (local_458[lVar4] != '\0');
    pIVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager(this);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_440,pIVar3);
    local_450 = 1;
    pcVar5 = param_2 + lVar4;
    if (pcVar5 != (char *)0x0) {
      do {
        lVar6 = lVar6 + 1;
      } while (pcVar5[lVar6] != '\0');
      iVar7 = (int)lVar6;
    }
    ATL::CSimpleStringT<char,1>::Concatenate
              ((CSimpleStringT<char,1> *)local_440,*(char **)this,*(int *)(*(char **)this + -0x10),
               pcVar5,iVar7);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x18),
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               local_440);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_440);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_430);
  }
  else {
LAB_18002f510:
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x18),
               param_2);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_458);
  return 0;
}

/* ---- FUNC 0002F560 FUN_18002f560 (361 bytes) ---- */

void FUN_18002f560(longlong param_1,longlong *param_2,uint param_3,char *param_4)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar4;
  void *pvVar5;
  longlong lVar6;
  longlong lVar7;
  longlong *local_res8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res10 [8];
  
  FUN_1800273b0(param_1);
  *(longlong **)(param_1 + 0x28) = param_2;
  *(uint *)(param_1 + 0x30) = param_3;
  if (param_2 != (longlong *)0x0) {
    if (((param_3 < 2) || (param_3 - 0x60 < 3)) || (param_3 == 100)) {
      (**(code **)(*param_2 + 8))(param_2);
    }
    else {
      if ((param_3 == 2) || (param_3 == 0x5a)) {
        lVar7 = -1;
        do {
          lVar6 = lVar7;
          lVar7 = lVar6 + 1;
        } while (*(char *)((longlong)param_2 + lVar7) != '\0');
        pvVar5 = malloc(lVar6 + 2);
        if (lVar7 != 0) {
          lVar6 = (longlong)pvVar5 - (longlong)param_2;
          do {
            lVar2 = *param_2;
            *(char *)(lVar6 + (longlong)param_2) = (char)lVar2;
            param_2 = (longlong *)((longlong)param_2 + 1);
          } while ((char)lVar2 != '\0');
        }
        *(undefined1 *)((longlong)pvVar5 + lVar7) = 0;
        *(void **)(param_1 + 0x28) = pvVar5;
        return;
      }
      if (param_3 == 3) {
        if (param_4 != (char *)0x0) {
          (*(code *)((undefined8 *)*param_2)[1])(param_2);
                    /* WARNING: Could not recover jumptable at 0x00018002f660. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                     (param_1 + 0x18),param_4);
          return;
        }
        iVar3 = (**(code **)*param_2)(param_2,&DAT_180063400,&local_res8);
        if (-1 < iVar3) {
          plVar1 = (longlong *)local_res8[0xc];
          (**(code **)(*plVar1 + 8))(plVar1);
          *(longlong **)(param_1 + 0x28) = plVar1;
          pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                             ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                              (local_res8 + 0x3b),(int)local_res10);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                     (param_1 + 0x18),pCVar4);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10);
          (**(code **)(*local_res8 + 0x10))();
          return;
        }
      }
    }
  }
  return;
}

/* ---- FUNC 0002F6D0 FUN_18002f6d0 (41 bytes) ---- */

void FUN_18002f6d0(longlong param_1,undefined4 param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  
  lVar5 = *(longlong *)(param_1 + 0x40);
  if (lVar5 == 0) {
    *(undefined4 *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x28) + 0x164) = param_2;
    return;
  }
  iVar4 = 0;
  if (0 < lVar5) {
    lVar6 = 0;
    do {
      if ((lVar6 < 0) || (lVar5 <= lVar6)) {
MFC140_DLL_AfxThrowInvalidArgException:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x38) + lVar6 * 8);
      uVar3 = 0;
      uVar2 = *(ulonglong *)(lVar5 + 0x10);
      if (uVar2 != 0) {
        do {
          if (((longlong)uVar3 < 0) || (*(longlong *)(lVar5 + 0x10) <= (longlong)uVar3))
          goto MFC140_DLL_AfxThrowInvalidArgException;
          lVar1 = uVar3 * 8;
          uVar3 = uVar3 + 1;
          *(undefined4 *)(*(longlong *)(*(longlong *)(lVar5 + 8) + lVar1) + 0x164) = param_2;
        } while (uVar3 < uVar2);
      }
      lVar5 = *(longlong *)(param_1 + 0x40);
      iVar4 = iVar4 + 1;
      lVar6 = lVar6 + 1;
    } while (iVar4 < lVar5);
  }
  return;
}

/* ---- FUNC 0002F6F9 FUN_18002f6f9 (106 bytes) ---- */

void FUN_18002f6f9(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  int iVar5;
  longlong unaff_RDI;
  longlong lVar6;
  undefined4 in_R11D;
  
  iVar5 = 0;
  if (0 < param_3) {
    lVar6 = 0;
    do {
      if ((lVar6 < 0) || (param_3 <= lVar6)) {
MFC140_DLL_AfxThrowInvalidArgException:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      lVar2 = *(longlong *)(*(longlong *)(unaff_RDI + 0x38) + lVar6 * 8);
      uVar4 = 0;
      uVar3 = *(ulonglong *)(lVar2 + 0x10);
      if (uVar3 != 0) {
        do {
          if (((longlong)uVar4 < 0) || (*(longlong *)(lVar2 + 0x10) <= (longlong)uVar4))
          goto MFC140_DLL_AfxThrowInvalidArgException;
          lVar1 = uVar4 * 8;
          uVar4 = uVar4 + 1;
          *(undefined4 *)(*(longlong *)(*(longlong *)(lVar2 + 8) + lVar1) + 0x164) = in_R11D;
        } while (uVar4 < uVar3);
      }
      param_3 = *(longlong *)(unaff_RDI + 0x40);
      iVar5 = iVar5 + 1;
      lVar6 = lVar6 + 1;
    } while (iVar5 < param_3);
  }
  return;
}

/* ---- FUNC 0002F763 AfxThrowInvalidArgException (5 bytes) ---- */

void __cdecl AfxThrowInvalidArgException(void)

{
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 0002F770 FUN_18002f770 (60 bytes) ---- */

void FUN_18002f770(longlong param_1,longlong *param_2)

{
  if (*(longlong **)(param_1 + 0x58) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0x58) + 0x10))();
  }
  *(longlong **)(param_1 + 0x58) = param_2;
  if (param_2 != (longlong *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  return;
}

/* ---- FUNC 0002F7B0 FUN_18002f7b0 (146 bytes) ---- */

void FUN_18002f7b0(longlong param_1,uint param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5,undefined4 param_6)

{
  undefined8 *puVar1;
  ulonglong *puVar2;
  
  puVar2 = (ulonglong *)0x0;
  if (*(void **)(param_1 + 0x38) != (void *)0x0) {
    FUN_180025ad0(*(void **)(param_1 + 0x38));
    *(undefined8 *)(param_1 + 0x38) = 0;
  }
  puVar1 = operator_new(0x20);
  if (puVar1 != (undefined8 *)0x0) {
    puVar2 = FUN_180025710(puVar1);
  }
  *(ulonglong **)(param_1 + 0x38) = puVar2;
  *puVar2 = (ulonglong)param_2;
  *(undefined4 *)(*(longlong *)(param_1 + 0x38) + 0x14) = param_3;
  *(undefined4 *)(*(longlong *)(param_1 + 0x38) + 0x18) = param_4;
  *(undefined4 *)(*(longlong *)(param_1 + 0x38) + 8) = param_5;
  *(undefined4 *)(*(longlong *)(param_1 + 0x38) + 0xc) = param_6;
  return;
}

/* ---- FUNC 0002F850 FUN_18002f850 (403 bytes) ---- */

void FUN_18002f850(longlong param_1,short *param_2,VARIANTARG *param_3,VARIANTARG *param_4,
                  VARIANTARG *param_5,VARIANTARG *param_6,VARIANTARG *param_7)

{
  short sVar1;
  int iVar2;
  HRESULT HVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  longlong *local_res8;
  undefined8 *local_res10;
  
  puVar4 = (undefined8 *)0x0;
  if (*(void **)(param_1 + 0x38) != (void *)0x0) {
    FUN_180025ad0(*(void **)(param_1 + 0x38));
    *(undefined8 *)(param_1 + 0x38) = 0;
  }
  sVar1 = *param_2;
  local_res8 = (longlong *)0x0;
  if ((sVar1 == 9) || (sVar1 == 0xd)) {
    puVar5 = *(undefined8 **)(param_2 + 4);
  }
  else {
    if ((sVar1 != 0x4009) && (sVar1 != 0x400d)) {
      return;
    }
    puVar5 = (undefined8 *)**(undefined8 **)(param_2 + 4);
  }
  iVar2 = (**(code **)*puVar5)(puVar5,&DAT_180063420,&local_res8);
  if ((-1 < iVar2) && (local_res8 != (longlong *)0x0)) {
    local_res10 = operator_new(0x20);
    if (local_res10 != (undefined8 *)0x0) {
      puVar4 = FUN_180025710(local_res10);
    }
    *(undefined8 **)(param_1 + 0x38) = puVar4;
    *puVar4 = local_res8;
    (**(code **)(*local_res8 + 0x10))();
    HVar3 = VariantChangeType(param_3,param_3,0,3);
    if (-1 < HVar3) {
      *(undefined4 *)(*(longlong *)(param_1 + 0x38) + 8) =
           *(undefined4 *)((longlong)&param_3->n1 + 8);
    }
    HVar3 = VariantChangeType(param_4,param_4,0,3);
    if (-1 < HVar3) {
      *(undefined4 *)(*(longlong *)(param_1 + 0x38) + 0xc) =
           *(undefined4 *)((longlong)&param_4->n1 + 8);
    }
    HVar3 = VariantChangeType(param_5,param_5,0,2);
    if (-1 < HVar3) {
      *(undefined2 *)(*(longlong *)(param_1 + 0x38) + 0x10) =
           *(undefined2 *)((longlong)&param_5->n1 + 8);
    }
    HVar3 = VariantChangeType(param_6,param_6,0,3);
    if (-1 < HVar3) {
      *(undefined4 *)(*(longlong *)(param_1 + 0x38) + 0x14) =
           *(undefined4 *)((longlong)&param_6->n1 + 8);
    }
    HVar3 = VariantChangeType(param_7,param_7,0,3);
    if (-1 < HVar3) {
      *(undefined4 *)(*(longlong *)(param_1 + 0x38) + 0x18) =
           *(undefined4 *)((longlong)&param_7->n1 + 8);
    }
  }
  return;
}

/* ---- FUNC 0002F9F0 FUN_18002f9f0 (216 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18002f9f0(longlong param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  int iVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  longlong *plVar7;
  ulonglong uVar8;
  undefined1 auStack_498 [32];
  ulong *local_478;
  ulong local_468 [2];
  longlong *local_460;
  undefined8 local_458;
  int *piStack_450;
  code *local_448;
  undefined2 local_440 [4];
  undefined8 local_438;
  undefined8 local_430;
  undefined4 local_428;
  undefined1 local_418 [1008];
  ulonglong local_28;
  
  local_28 = DAT_180077818 ^ (ulonglong)auStack_498;
  if (*(longlong *)(param_1 + 0x120) != 0) {
    FUN_180002a20(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\HappSel.cpp",0xc71);
    LogMessage(local_418,2,1);
  }
  if (*(longlong *)(param_1 + 0x148) != 0) {
    FUN_180002a20(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\HappSel.cpp",0xc72);
    LogMessage(local_418,2,1);
  }
  uVar1 = *(ulonglong *)(param_1 + 0x60);
  local_440[0] = 0;
  local_438 = 0;
  local_430 = 0xffffffffffffffff;
  local_428 = 0xffffffff;
  uVar8 = 0;
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar8 < 0) || (*(longlong *)(param_1 + 0x60) <= (longlong)uVar8)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x58) + uVar8 * 8);
      iVar4 = *(int *)(lVar2 + 0x30);
      if ((iVar4 == 0) || (iVar4 == 3)) {
        plVar7 = *(longlong **)(lVar2 + 0x28);
        local_458 = 0;
        piStack_450 = (int *)0x0;
        local_448 = (code *)0x0;
        puVar5 = (undefined8 *)HAGetAttr(plVar7[9],0x12,0,&local_458);
        if (puVar5 == (undefined8 *)0x0) {
          if (*piStack_450 != 0) {
            do {
              iVar4 = HAWillNotify(plVar7[9]);
              if (iVar4 != 0) break;
              if ((int)plVar7[0xd] != 0) {
                plVar7 = (longlong *)0x0;
                break;
              }
              plVar7 = (longlong *)plVar7[0xc];
            } while (plVar7 != (longlong *)0x0);
          }
          if (local_448 != (code *)0x0) {
            (*local_448)(piStack_450);
          }
          if (plVar7 != (longlong *)0x0) {
            uVar3 = *(ulonglong *)(param_1 + 0x120);
            uVar6 = 0;
            if (uVar3 != 0) {
              do {
                if (((longlong)uVar6 < 0) || ((longlong)uVar3 <= (longlong)uVar6)) {
                    /* WARNING: Subroutine does not return */
                  AfxThrowInvalidArgException();
                }
                if (*(longlong **)(*(longlong *)(param_1 + 0x118) + uVar6 * 8) == plVar7)
                goto LAB_18002fc50;
                uVar6 = uVar6 + 1;
              } while (uVar6 < uVar3);
            }
            local_468[0] = 0;
            local_460 = (longlong *)0x0;
            iVar4 = (**(code **)*plVar7)(plVar7,&DAT_180066d58,&local_460);
            if (-1 < iVar4) {
              local_478 = local_468;
              (**(code **)(*local_460 + 0x48))
                        (local_460,local_440,1,*(undefined8 *)(param_1 + 0xd8));
              (**(code **)(*local_460 + 0x10))();
            }
            (**(code **)(*plVar7 + 8))(plVar7);
            CPtrArray::SetAtGrow
                      ((CPtrArray *)(param_1 + 0x110),*(__int64 *)(param_1 + 0x120),plVar7);
            CDWordArray::SetAtGrow
                      ((CDWordArray *)(param_1 + 0x138),*(__int64 *)(param_1 + 0x148),local_468[0]);
          }
        }
        else if ((code *)*puVar5 != (code *)0x0) {
          (*(code *)*puVar5)(puVar5);
        }
      }
LAB_18002fc50:
      uVar8 = uVar8 + 1;
    } while (uVar8 < uVar1);
  }
  return;
}

/* ---- FUNC 0002FAC8 FUN_18002fac8 (459 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18002fac8(void)

{
  longlong lVar1;
  int iVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong *plVar6;
  ulonglong unaff_RBP;
  ulonglong unaff_RSI;
  longlong unaff_RDI;
  ulong uVar7;
  longlong *unaff_R14;
  ulong in_stack_00000030;
  longlong *in_stack_00000038;
  undefined8 in_stack_00000040;
  ulong *in_stack_00000048;
  code *in_stack_00000050;
  
  do {
    if (((longlong)unaff_RSI < 0) || (*(longlong *)(unaff_RDI + 0x60) <= (longlong)unaff_RSI)) {
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
    lVar1 = *(longlong *)(*(longlong *)(unaff_RDI + 0x58) + unaff_RSI * 8);
    iVar2 = *(int *)(lVar1 + 0x30);
    if ((iVar2 == 0) || (iVar2 == 3)) {
      plVar5 = *(longlong **)(lVar1 + 0x28);
      in_stack_00000040 = 0;
      in_stack_00000048 = (ulong *)0x0;
      in_stack_00000050 = (code *)0x0;
      puVar3 = (undefined8 *)HAGetAttr(plVar5[9],0x12,0,&stack0x00000040);
      if (puVar3 == (undefined8 *)0x0) {
        uVar7 = (ulong)unaff_R14;
        plVar6 = plVar5;
        if (*in_stack_00000048 != uVar7) {
          do {
            iVar2 = HAWillNotify(plVar5[9]);
            plVar6 = plVar5;
            if ((iVar2 != 0) || (plVar6 = unaff_R14, *(ulong *)(plVar5 + 0xd) != uVar7)) break;
            plVar6 = (longlong *)plVar5[0xc];
            plVar5 = plVar6;
          } while (plVar6 != (longlong *)0x0);
        }
        if (in_stack_00000050 != (code *)0x0) {
          (*in_stack_00000050)(in_stack_00000048);
        }
        if (plVar6 != (longlong *)0x0) {
          plVar5 = *(longlong **)(unaff_RDI + 0x120);
          plVar4 = unaff_R14;
          if (plVar5 != (longlong *)0x0) {
            do {
              if (((longlong)plVar4 < 0) || ((longlong)plVar5 <= (longlong)plVar4)) {
                    /* WARNING: Subroutine does not return */
                AfxThrowInvalidArgException();
              }
              if (*(longlong **)(*(longlong *)(unaff_RDI + 0x118) + (longlong)plVar4 * 8) == plVar6)
              goto LAB_18002fc50;
              plVar4 = (longlong *)((longlong)plVar4 + 1);
            } while (plVar4 < plVar5);
          }
          in_stack_00000030 = uVar7;
          in_stack_00000038 = unaff_R14;
          iVar2 = (**(code **)*plVar6)(plVar6,&DAT_180066d58,&stack0x00000038);
          if (-1 < iVar2) {
            (**(code **)(*in_stack_00000038 + 0x48))
                      (in_stack_00000038,&stack0x00000058,1,*(undefined8 *)(unaff_RDI + 0xd8),
                       &stack0x00000030);
            (**(code **)(*in_stack_00000038 + 0x10))();
          }
          (**(code **)(*plVar6 + 8))(plVar6);
          CPtrArray::SetAtGrow
                    ((CPtrArray *)(unaff_RDI + 0x110),*(__int64 *)(unaff_RDI + 0x120),plVar6);
          CDWordArray::SetAtGrow
                    ((CDWordArray *)(unaff_RDI + 0x138),*(__int64 *)(unaff_RDI + 0x148),
                     in_stack_00000030);
        }
      }
      else if ((code *)*puVar3 != (code *)0x0) {
        (*(code *)*puVar3)(puVar3);
      }
    }
LAB_18002fc50:
    unaff_RSI = unaff_RSI + 1;
    if (unaff_RBP <= unaff_RSI) {
      return;
    }
  } while( true );
}

/* ---- FUNC 0002FC64 FUN_18002fc64 (36 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18002fc64(void)

{
  return;
}

/* ---- FUNC 0002FC88 AfxThrowInvalidArgException (5 bytes) ---- */

void __cdecl AfxThrowInvalidArgException(void)

{
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 0002FCA0 FUN_18002fca0 (1840 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18002fca0(longlong param_1)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  void *pvVar5;
  longlong *plVar6;
  int iVar7;
  longlong lVar8;
  char cVar9;
  int iVar10;
  ulonglong uVar11;
  longlong lVar12;
  longlong lVar13;
  longlong lVar14;
  longlong lVar15;
  ulonglong uVar16;
  int iVar17;
  longlong *plVar18;
  CPtrArray *this;
  void *pvVar19;
  int iVar20;
  undefined1 auStack_468 [32];
  char local_448;
  int local_444;
  ulonglong local_440;
  longlong *local_438;
  undefined1 local_428 [1008];
  ulonglong local_38;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStack_468;
  uVar16 = *(ulonglong *)(param_1 + 0x60);
  iVar20 = 0;
  local_440 = uVar16;
  if (uVar16 == 0) {
    local_438 = (longlong *)(param_1 + 0x58);
  }
  else {
    lVar15 = 0;
    do {
      if ((lVar15 < 0) || (*(longlong *)(param_1 + 0x60) <= lVar15)) goto LAB_1800303cb;
      local_438 = (longlong *)(param_1 + 0x58);
      lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x58) + lVar15 * 8);
      if ((lVar13 != 0) && (plVar18 = *(longlong **)(lVar13 + 0x38), plVar18 != (longlong *)0x0)) {
        iVar17 = iVar20 + 1;
        uVar11 = (ulonglong)iVar17;
        iVar10 = iVar17;
        lVar13 = lVar15;
        if (uVar11 < uVar16) {
          do {
            lVar13 = lVar13 + 1;
            if ((lVar13 < 0) || (*(longlong *)(param_1 + 0x60) <= lVar13)) goto LAB_1800303cb;
            pvVar19 = *(void **)(*(longlong *)(param_1 + 0x58) + lVar13 * 8);
            if ((pvVar19 != (void *)0x0) &&
               ((*(longlong **)((longlong)pvVar19 + 0x38) != (longlong *)0x0 &&
                (**(longlong **)((longlong)pvVar19 + 0x38) == *plVar18)))) {
              CPtrArray::RemoveAt((CPtrArray *)(param_1 + 0x50),uVar11,1);
              CPtrArray::InsertAt((CPtrArray *)(param_1 + 0x50),(longlong)iVar17,pvVar19,1);
              iVar20 = iVar20 + 1;
              iVar17 = iVar17 + 1;
              lVar15 = lVar15 + 1;
            }
            uVar11 = (ulonglong)(iVar10 + 1);
            uVar16 = local_440;
            iVar10 = iVar10 + 1;
          } while (uVar11 < local_440);
        }
      }
      iVar20 = iVar20 + 1;
      lVar15 = lVar15 + 1;
    } while ((ulonglong)(longlong)iVar20 < uVar16);
    lVar15 = 0;
    iVar20 = 0;
    lVar12 = 0;
    lVar13 = 0;
    do {
      if ((lVar12 < 0) || (*(longlong *)(param_1 + 0x60) <= lVar12)) goto LAB_1800303cb;
      lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x58) + lVar12 * 8);
      lVar8 = lVar13;
      if ((lVar14 != 0) && (plVar18 = *(longlong **)(lVar14 + 0x38), plVar18 != (longlong *)0x0)) {
        lVar8 = *plVar18;
        lVar14 = lVar15 + 1;
        if (lVar13 == *plVar18) {
          lVar8 = lVar13;
          lVar14 = lVar15;
        }
        lVar15 = lVar14;
        *plVar18 = lVar15;
      }
      iVar20 = iVar20 + 1;
      lVar12 = lVar12 + 1;
      lVar13 = lVar8;
    } while ((ulonglong)(longlong)iVar20 < uVar16);
    lVar15 = 0;
    local_440 = local_440 & 0xffffffff00000000;
    iVar20 = 0;
    do {
      iVar20 = iVar20 + 1;
      if ((lVar15 < 0) || (lVar13 = *(longlong *)(param_1 + 0x60), lVar13 <= lVar15))
      goto LAB_1800303cb;
      lVar14 = *(longlong *)(param_1 + 0x58);
      lVar12 = *(longlong *)(lVar14 + lVar15 * 8);
      if ((lVar12 != 0) &&
         (plVar18 = *(longlong **)(lVar12 + 0x38), lVar8 = lVar15, iVar10 = iVar20,
         plVar18 != (longlong *)0x0)) {
        for (; (ulonglong)(longlong)iVar10 < uVar16; iVar10 = iVar10 + 1) {
          lVar8 = lVar8 + 1;
          if ((lVar8 < 0) || (lVar13 <= lVar8)) goto LAB_1800303cb;
          lVar3 = *(longlong *)(lVar14 + lVar8 * 8);
          if (lVar3 != 0) {
            plVar4 = *(longlong **)(lVar3 + 0x38);
            if ((plVar4 == (longlong *)0x0) || (*plVar4 != *plVar18)) break;
            if (*(int *)((longlong)plVar4 + 0x14) < *(int *)((longlong)plVar18 + 0x14)) {
              if ((lVar13 <= lVar15) ||
                 (*(longlong *)(lVar14 + lVar15 * 8) = lVar3, *(longlong *)(param_1 + 0x60) <= lVar8
                 )) goto LAB_1800303cb;
              *(longlong *)(*(longlong *)(param_1 + 0x58) + lVar8 * 8) = lVar12;
              lVar13 = *(longlong *)(param_1 + 0x60);
              lVar14 = *(longlong *)(param_1 + 0x58);
              plVar18 = plVar4;
              lVar12 = lVar3;
            }
          }
        }
      }
      iVar10 = (int)local_440 + 1;
      lVar15 = lVar15 + 1;
      local_440 = CONCAT44(local_440._4_4_,iVar10);
    } while ((ulonglong)(longlong)iVar10 < uVar16);
    iVar20 = 0;
    lVar15 = 0;
    do {
      if ((lVar15 < 0) || (*(longlong *)(param_1 + 0x60) <= lVar15)) goto LAB_1800303cb;
      lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x58) + lVar15 * 8);
      if ((lVar13 != 0) && (plVar18 = *(longlong **)(lVar13 + 0x38), plVar18 != (longlong *)0x0)) {
        iVar10 = 0;
        while( true ) {
          iVar1 = iVar20;
          lVar12 = lVar15;
          iVar7 = iVar10;
          iVar17 = iVar1 + 1;
          lVar13 = lVar12 + 1;
          lVar15 = lVar13;
          iVar20 = iVar17;
          if (uVar16 <= (ulonglong)(longlong)iVar17) break;
          if ((lVar13 < 0) || (*(longlong *)(param_1 + 0x60) <= lVar13)) goto LAB_1800303cb;
          lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x58) + lVar13 * 8);
          iVar10 = iVar7;
          if (lVar14 != 0) {
            plVar4 = *(longlong **)(lVar14 + 0x38);
            lVar15 = lVar12;
            iVar20 = iVar1;
            if ((plVar4 == (longlong *)0x0) || (*plVar4 != *plVar18)) break;
            if (*(int *)((longlong)plVar4 + 0x14) < *(int *)((longlong)plVar18 + 0x14)) {
              FUN_180002a20(local_428,"Assert failed in file %s line %d",
                            "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\HappSel.cpp",0xb62);
              LogMessage(local_428,2,1);
            }
            iVar1 = *(int *)((longlong)plVar18 + 0x14);
            iVar2 = *(int *)((longlong)plVar4 + 0x14);
            *(int *)((longlong)plVar18 + 0x14) = iVar7;
            plVar18 = plVar4;
            iVar10 = iVar7 + 1;
            lVar15 = lVar13;
            iVar20 = iVar17;
            if (iVar2 <= iVar1 + 0x14) {
              iVar10 = iVar7;
            }
          }
        }
        *(int *)((longlong)plVar18 + 0x14) = iVar7;
      }
      iVar20 = iVar20 + 1;
      lVar15 = lVar15 + 1;
    } while ((ulonglong)(longlong)iVar20 < uVar16);
    iVar20 = 0;
    local_440 = local_440 & 0xffffffff00000000;
    lVar15 = 0;
    local_444 = 1;
    do {
      if ((lVar15 < 0) || (*(longlong *)(param_1 + 0x60) <= lVar15)) goto LAB_1800303cb;
      pvVar19 = *(void **)(*(longlong *)(param_1 + 0x58) + lVar15 * 8);
      if ((pvVar19 != (void *)0x0) &&
         ((plVar18 = *(longlong **)((longlong)pvVar19 + 0x38), plVar18 != (longlong *)0x0 &&
          (uVar11 = (ulonglong)local_444, iVar10 = local_444, lVar13 = lVar15, uVar11 < uVar16)))) {
        do {
          lVar13 = lVar13 + 1;
          if ((lVar13 < 0) || (*(longlong *)(param_1 + 0x60) <= lVar13)) goto LAB_1800303cb;
          pvVar5 = *(void **)(*(longlong *)(param_1 + 0x58) + lVar13 * 8);
          if (pvVar5 != (void *)0x0) {
            plVar4 = *(longlong **)((longlong)pvVar5 + 0x38);
            if ((plVar4 == (longlong *)0x0) || (*plVar4 != *plVar18)) break;
            if ((int)plVar4[3] < (int)plVar18[3]) {
              if (*(longlong *)(param_1 + 0x60) <= lVar15) goto LAB_1800303cb;
              *(void **)(*(longlong *)(param_1 + 0x58) + lVar15 * 8) = pvVar5;
              CPtrArray::RemoveAt((CPtrArray *)(param_1 + 0x50),uVar11,1);
              CPtrArray::InsertAt((CPtrArray *)(param_1 + 0x50),(longlong)local_444,pvVar19,1);
              plVar18 = plVar4;
              pvVar19 = pvVar5;
            }
          }
          uVar11 = (ulonglong)(iVar10 + 1);
          iVar10 = iVar10 + 1;
        } while (uVar11 < uVar16);
        iVar20 = (int)local_440;
      }
      iVar20 = iVar20 + 1;
      local_444 = local_444 + 1;
      lVar15 = lVar15 + 1;
      local_440 = CONCAT44(local_440._4_4_,iVar20);
    } while ((ulonglong)(longlong)iVar20 < uVar16);
  }
  plVar18 = (longlong *)(param_1 + 0x58);
  uVar16 = *(ulonglong *)(param_1 + 0x60);
  iVar20 = 0;
  if (0 < (longlong)uVar16) {
    lVar15 = 0;
    do {
      if ((lVar15 < 0) || ((longlong)uVar16 <= lVar15)) goto LAB_1800303cb;
      lVar13 = *(longlong *)(*plVar18 + lVar15 * 8);
      if ((lVar13 == 0) || (*(int *)(lVar13 + 0x30) != 0x5a)) {
        lVar13 = lVar15 + 1;
        iVar10 = iVar20 + 1;
      }
      else {
        plVar4 = *(longlong **)(lVar13 + 0x38);
        cVar9 = '\0';
        local_448 = '\0';
        if ((plVar4 != (longlong *)0x0) && ((int)plVar4[1] == -1)) {
          iVar10 = 0;
          lVar12 = 0;
          if (0 < (longlong)uVar16) {
            do {
              this = (CPtrArray *)(param_1 + 0x50);
              if ((lVar12 < 0) || ((longlong)uVar16 <= lVar12)) goto LAB_1800303cb;
              lVar14 = *(longlong *)(*plVar18 + lVar12 * 8);
              if ((lVar14 == 0) ||
                 ((((lVar14 == lVar13 ||
                    (plVar6 = *(longlong **)(lVar14 + 0x38), plVar6 == (longlong *)0x0)) ||
                   ((int)plVar6[1] != -1)) ||
                  ((*plVar4 != *plVar6 ||
                   (*(int *)((longlong)plVar4 + 0xc) != *(int *)((longlong)plVar6 + 0xc))))))) {
                iVar10 = iVar10 + 1;
                lVar12 = lVar12 + 1;
              }
              else {
                if (*(int *)(lVar14 + 0x30) != 0x5a) {
                  CPtrArray::RemoveAt(this,(longlong)iVar20,1);
                  cVar9 = '\x01';
                  break;
                }
                if ((int)plVar4[3] < (int)plVar6[3]) {
                  CPtrArray::RemoveAt(this,(longlong)iVar20,1);
                  cVar9 = '\x01';
                  break;
                }
                CPtrArray::RemoveAt(this,(longlong)iVar10,1);
                plVar18 = local_438;
              }
              uVar16 = *(ulonglong *)(param_1 + 0x60);
              cVar9 = local_448;
            } while ((longlong)iVar10 < (longlong)uVar16);
          }
        }
        plVar18 = local_438;
        lVar13 = lVar15 + 1;
        iVar10 = iVar20 + 1;
        if (cVar9 != '\0') {
          lVar13 = lVar15;
          iVar10 = iVar20;
        }
      }
      iVar20 = iVar10;
      uVar16 = *(ulonglong *)(param_1 + 0x60);
      lVar15 = lVar13;
    } while ((longlong)iVar20 < (longlong)uVar16);
  }
  iVar20 = 0;
  if (uVar16 != 0) {
    lVar15 = 0;
    do {
      if ((lVar15 < 0) || (*(longlong *)(param_1 + 0x60) <= lVar15)) {
LAB_1800303cb:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      lVar13 = *(longlong *)(*plVar18 + lVar15 * 8);
      if ((lVar13 != 0) && (plVar4 = *(longlong **)(lVar13 + 0x38), plVar4 != (longlong *)0x0)) {
        iVar10 = 0;
        while( true ) {
          iVar1 = iVar20;
          lVar12 = lVar15;
          iVar7 = iVar10;
          iVar17 = iVar1 + 1;
          lVar13 = lVar12 + 1;
          lVar15 = lVar13;
          iVar20 = iVar17;
          if (uVar16 <= (ulonglong)(longlong)iVar17) break;
          if ((lVar13 < 0) || (*(longlong *)(param_1 + 0x60) <= lVar13)) goto LAB_1800303cb;
          lVar14 = *(longlong *)(*plVar18 + lVar13 * 8);
          iVar10 = iVar7;
          if (lVar14 != 0) {
            plVar6 = *(longlong **)(lVar14 + 0x38);
            lVar15 = lVar12;
            iVar20 = iVar1;
            if ((plVar6 == (longlong *)0x0) || (*plVar6 != *plVar4)) break;
            if ((int)plVar6[3] < (int)plVar4[3]) {
              FUN_180002a20(local_428,"Assert failed in file %s line %d",
                            "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\HappSel.cpp",0xbec);
              LogMessage(local_428,2,1);
              plVar18 = local_438;
            }
            lVar12 = plVar6[3];
            lVar14 = plVar4[3];
            *(int *)(plVar4 + 3) = iVar7;
            plVar4 = plVar6;
            iVar10 = iVar7 + 1;
            lVar15 = lVar13;
            iVar20 = iVar17;
            if ((int)lVar12 <= (int)lVar14) {
              iVar10 = iVar7;
            }
          }
        }
        *(int *)(plVar4 + 3) = iVar7;
      }
      iVar20 = iVar20 + 1;
      lVar15 = lVar15 + 1;
    } while ((ulonglong)(longlong)iVar20 < uVar16);
  }
  return;
}

/* ---- FUNC 000303E0 FUN_1800303e0 (124 bytes) ---- */

void FUN_1800303e0(longlong param_1,int param_2)

{
  int iVar1;
  LPUNKNOWN *ppvObject;
  LPUNKNOWN local_res8;
  
  if ((*(int *)(param_1 + 8) - 4U & 0xfffffffb) == 0) {
    ppvObject = &local_res8;
    iVar1 = (**(code **)**(undefined8 **)(param_1 + 0x68))
                      (*(undefined8 **)(param_1 + 0x68),&DAT_180066db8);
    if (-1 < iVar1) {
      if (param_2 == 0) {
        (*local_res8->lpVtbl[2].QueryInterface)(local_res8,(IID *)0x1,ppvObject);
      }
      else if (*(int *)(param_1 + 8) == 4) {
        FUN_180030460(param_1);
      }
      else {
        OleRun(local_res8);
      }
      (*local_res8->lpVtbl->Release)(local_res8);
    }
  }
  return;
}

/* ---- FUNC 00030460 FUN_180030460 (69 bytes) ---- */

ulonglong FUN_180030460(longlong param_1)

{
  ULONG UVar1;
  ULONG UVar2;
  UINT UVar3;
  uint uVar4;
  ulonglong uVar5;
  LPUNKNOWN local_res8;
  STGMEDIUM local_48;
  undefined2 local_30 [4];
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  if (*(int *)(param_1 + 8) == 1) {
    return 0x80004005;
  }
  if ((*(int *)(param_1 + 8) == 0x10) && (uVar5 = FUN_180028420(param_1), (int)uVar5 < 0)) {
    return 0x80004005;
  }
  uVar5 = (**(code **)**(undefined8 **)(param_1 + 0x68))
                    (*(undefined8 **)(param_1 + 0x68),&DAT_180066db8,&local_res8);
  if (-1 < (int)uVar5) {
    UVar1 = OleRun(local_res8);
    if ((int)UVar1 < 0) {
      (*local_res8->lpVtbl->Release)(local_res8);
    }
    else {
      UVar2 = (*local_res8->lpVtbl[4].Release)(local_res8);
      UVar1 = 0;
      if (UVar2 != 0) {
        UVar1 = (*local_res8->lpVtbl[4].AddRef)(local_res8);
      }
      (*local_res8->lpVtbl->Release)(local_res8);
      if (-1 < (int)UVar1) {
        UVar3 = RegisterClipboardFormatA("Grid Text");
        local_20 = 1;
        local_18 = 1;
        local_30[0] = (undefined2)UVar3;
        local_28 = 0;
        local_1c = 0xffffffff;
        if (*(int *)(param_1 + 0x80) == 0) {
          local_30[0] = 1;
        }
        uVar4 = (**(code **)(**(longlong **)(param_1 + 0x68) + 0x18))
                          (*(longlong **)(param_1 + 0x68),local_30,&local_48);
        uVar5 = (ulonglong)uVar4;
        if (-1 < (int)uVar4) {
          FUN_18003e370(-1);
          if (local_48.u.hBitmap != (HBITMAP)0x0) {
            DAT_180079898 = 1;
            uVar5 = FUN_18002c9d0(param_1,local_48.u.hGlobal,1);
            uVar5 = uVar5 & 0xffffffff;
            DAT_180079898 = 0;
          }
          ReleaseStgMedium(&local_48);
          FUN_18003e370(0);
        }
        return uVar5;
      }
    }
    uVar5 = (ulonglong)UVar1;
  }
  return uVar5;
}

/* ---- FUNC 000304A5 FUN_1800304a5 (35 bytes) ---- */

ulonglong FUN_1800304a5(LPUNKNOWN param_1)

{
  uint uVar1;
  int iVar2;
  UINT UVar3;
  ulonglong uVar4;
  longlong unaff_RDI;
  undefined1 auStackX_20 [8];
  _union_2284 in_stack_00000028;
  undefined2 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined4 in_stack_00000048;
  undefined4 uStack000000000000004c;
  undefined4 in_stack_00000050;
  longlong *in_stack_00000070;
  
  uVar1 = OleRun(param_1);
  if ((int)uVar1 < 0) {
    (**(code **)(*in_stack_00000070 + 0x10))();
  }
  else {
    iVar2 = (**(code **)(*in_stack_00000070 + 0x70))();
    uVar1 = 0;
    if (iVar2 != 0) {
      uVar1 = (**(code **)(*in_stack_00000070 + 0x68))();
    }
    (**(code **)(*in_stack_00000070 + 0x10))();
    if (-1 < (int)uVar1) {
      UVar3 = RegisterClipboardFormatA("Grid Text");
      in_stack_00000048 = 1;
      in_stack_00000050 = 1;
      in_stack_00000040 = 0;
      uStack000000000000004c = 0xffffffff;
      in_stack_00000038 = (short)UVar3;
      if (*(int *)(unaff_RDI + 0x80) == 0) {
        in_stack_00000038 = 1;
      }
      uVar1 = (**(code **)(**(longlong **)(unaff_RDI + 0x68) + 0x18))
                        (*(longlong **)(unaff_RDI + 0x68),&stack0x00000038,auStackX_20);
      uVar4 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) {
        FUN_18003e370(-1);
        if (in_stack_00000028.hBitmap != (HBITMAP)0x0) {
          DAT_180079898 = 1;
          uVar4 = FUN_18002c9d0(unaff_RDI,in_stack_00000028.hGlobal,1);
          uVar4 = uVar4 & 0xffffffff;
          DAT_180079898 = 0;
        }
        ReleaseStgMedium((LPSTGMEDIUM)auStackX_20);
        FUN_18003e370(0);
      }
      return uVar4;
    }
  }
  return (ulonglong)uVar1;
}

/* ---- FUNC 000304C8 FUN_1800304c8 (6 bytes) ---- */

void FUN_1800304c8(void)

{
  return;
}

/* ---- FUNC 000304CE FUN_1800304ce (224 bytes) ---- */

ulonglong FUN_1800304ce(longlong *param_1)

{
  int iVar1;
  uint uVar2;
  UINT UVar3;
  ulonglong uVar4;
  longlong unaff_RDI;
  undefined1 auStackX_20 [8];
  _union_2284 in_stack_00000028;
  undefined2 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined4 in_stack_00000048;
  undefined4 uStack000000000000004c;
  undefined4 in_stack_00000050;
  longlong *in_stack_00000070;
  
  iVar1 = (**(code **)(*param_1 + 0x70))();
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = (**(code **)(*in_stack_00000070 + 0x68))();
  }
  (**(code **)(*in_stack_00000070 + 0x10))();
  if (-1 < (int)uVar2) {
    UVar3 = RegisterClipboardFormatA("Grid Text");
    in_stack_00000048 = 1;
    in_stack_00000050 = 1;
    in_stack_00000040 = 0;
    uStack000000000000004c = 0xffffffff;
    in_stack_00000038 = (short)UVar3;
    if (*(int *)(unaff_RDI + 0x80) == 0) {
      in_stack_00000038 = 1;
    }
    uVar2 = (**(code **)(**(longlong **)(unaff_RDI + 0x68) + 0x18))
                      (*(longlong **)(unaff_RDI + 0x68),&stack0x00000038,auStackX_20);
    uVar4 = (ulonglong)uVar2;
    if (-1 < (int)uVar2) {
      FUN_18003e370(-1);
      if (in_stack_00000028.hBitmap != (HBITMAP)0x0) {
        DAT_180079898 = 1;
        uVar4 = FUN_18002c9d0(unaff_RDI,in_stack_00000028.hGlobal,1);
        uVar4 = uVar4 & 0xffffffff;
        DAT_180079898 = 0;
      }
      ReleaseStgMedium((LPSTGMEDIUM)auStackX_20);
      FUN_18003e370(0);
    }
    return uVar4;
  }
  return (ulonglong)uVar2;
}

/* ---- FUNC 000305AE FUN_1800305ae (11 bytes) ---- */

undefined8 FUN_1800305ae(void)

{
  return 0x80004005;
}

/* ---- FUNC 000305C0 FUN_1800305c0 (14 bytes) ---- */

void FUN_1800305c0(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0001800305ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(longlong **)(param_1 + 0x90) + 0x38))();
  return;
}

/* ---- FUNC 000305D0 FUN_1800305d0 (11 bytes) ---- */

undefined8 FUN_1800305d0(longlong param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0xb0);
  return 0;
}

/* ---- FUNC 000305E0 FUN_1800305e0 (953 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_1800305e0(longlong *param_1,VARIANTARG *param_2,VARIANTARG *param_3)

{
  ushort uVar1;
  code *pcVar2;
  LPCSTR pCVar3;
  undefined8 *puVar4;
  HRESULT HVar5;
  undefined4 uVar6;
  int iVar7;
  longlong *plVar8;
  _union_1719 _Var9;
  ulonglong uVar10;
  longlong lVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  LPCWSTR lpWideCharStr;
  undefined *puStack_b0;
  undefined1 auStack_a8 [32];
  undefined8 uStack_88;
  int aiStack_80 [2];
  undefined8 local_78 [2];
  _union_1719 local_68;
  VARIANTARG local_60;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_48 [16];
  undefined4 local_38;
  ULONG UStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined8 local_28;
  ulonglong local_18;
  
  puVar12 = auStack_a8;
  puVar13 = auStack_a8;
  local_18 = DAT_180077818 ^ (ulonglong)&local_68;
  puStack_b0 = (undefined *)0x180030625;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_48);
  uVar1 = (param_2->n1).n2.vt;
  if (uVar1 < 0xb) {
    if ((uVar1 == 10) || (uVar1 == 0)) {
      puStack_b0 = (undefined *)0x180030692;
      (**(code **)(*param_1 + 0xd8))(param_1,0x7db);
      local_60.n1._8_4_ = local_68.s2.Lo32;
    }
    else if (uVar1 == 2) {
      local_60.n1._8_4_ = SEXT24(*(short *)((longlong)&param_2->n1 + 8));
    }
    else {
      if (uVar1 != 3) {
        if (uVar1 != 8) goto LAB_1800306c5;
        lpWideCharStr = *(LPCWSTR *)((longlong)&param_2->n1 + 8);
        puVar12 = auStack_a8;
        if (lpWideCharStr != (LPCWSTR)0x0) {
          lVar11 = -1;
          do {
            lVar11 = lVar11 + 1;
          } while (lpWideCharStr[lVar11] != L'\0');
          goto LAB_1800307bb;
        }
        goto LAB_180030827;
      }
      local_60.n1._8_4_ = *(ULONG *)((longlong)&param_2->n1 + 8);
    }
LAB_18003084e:
    lVar11 = (longlong)(int)local_60.n1._8_4_;
    puVar12 = auStack_a8;
    if (lVar11 <= param_1[0x16] + -1) {
      puStack_b0 = (undefined *)0x180030869;
      VariantInit(param_3);
      if ((lVar11 < 0) || (param_1[0x16] <= lVar11)) {
                    /* WARNING: Subroutine does not return */
        puStack_b0 = &UNK_180030999;
        AfxThrowInvalidArgException();
      }
      uVar6 = 0;
      lVar11 = *(longlong *)(param_1[0x15] + lVar11 * 8);
      if (lVar11 != 0) {
        iVar7 = *(int *)(lVar11 + 0x30);
        if ((iVar7 == 0) || (iVar7 == 1)) {
          local_68.Lo64 = 0;
          puVar4 = *(undefined8 **)(lVar11 + 0x28);
          if (puVar4 != (undefined8 *)0x0) {
            puStack_b0 = (undefined *)0x18003094a;
            iVar7 = (**(code **)*puVar4)(puVar4,&DAT_180066c78,&local_68);
LAB_18003094c:
            if (-1 < iVar7) {
              (param_3->n1).decVal.u2 = local_68;
              (param_3->n1).n2.vt = 9;
              puVar13 = auStack_a8;
              goto LAB_180030960;
            }
          }
        }
        else if (iVar7 == 2) {
          pCVar3 = *(LPCSTR *)(lVar11 + 0x28);
          if (pCVar3 != (LPCSTR)0x0) {
            (param_3->n1).n2.vt = 8;
            puStack_b0 = (undefined *)0x180030927;
            _Var9 = (_union_1719)FUN_1800019d0(pCVar3);
            (param_3->n1).decVal.u2 = _Var9;
            puVar13 = auStack_a8;
            goto LAB_180030960;
          }
        }
        else if (iVar7 == 3) {
          local_68.Lo64 = 0;
          puStack_b0 = (undefined *)0x1800308e9;
          plVar8 = (longlong *)FUN_18002e2f0(lVar11);
          if (plVar8 != (longlong *)0x0) {
            puStack_b0 = (undefined *)0x180030905;
            iVar7 = (**(code **)*plVar8)(plVar8,&DAT_180066c78,&local_68);
            puStack_b0 = (undefined *)0x180030910;
            (**(code **)(*plVar8 + 0x10))(plVar8);
            goto LAB_18003094c;
          }
        }
        else if ((iVar7 == 100) &&
                (plVar8 = *(longlong **)(lVar11 + 0x28), plVar8 != (longlong *)0x0)) {
          (param_3->n1).n2.vt = 0xd;
          (param_3->n1).decVal.u2.Lo64 = (ULONGLONG)plVar8;
          puStack_b0 = (undefined *)0x1800308d8;
          (**(code **)(*plVar8 + 8))();
          puVar13 = auStack_a8;
          uVar6 = 0;
          goto LAB_180030960;
        }
      }
      (param_3->n1).n2.vt = 0;
      puVar13 = auStack_a8;
      uVar6 = 0;
      goto LAB_180030960;
    }
  }
  else {
    if (uVar1 == 0x4002) {
      local_60.n1._8_4_ = SEXT24(**(short **)((longlong)&param_2->n1 + 8));
      goto LAB_18003084e;
    }
    if (uVar1 == 0x4003) {
      local_60.n1._8_4_ = **(ULONG **)((longlong)&param_2->n1 + 8);
      goto LAB_18003084e;
    }
    if (uVar1 == 0x4008) {
      lpWideCharStr = (LPCWSTR)**(longlong **)((longlong)&param_2->n1 + 8);
      if (lpWideCharStr == (LPCWSTR)0x0) goto LAB_180030827;
      lVar11 = -1;
      do {
        lVar11 = lVar11 + 1;
      } while (lpWideCharStr[lVar11] != L'\0');
    }
    else {
      if (uVar1 == 0x400c) {
        puVar4 = *(undefined8 **)((longlong)&param_2->n1 + 8);
        _Var9 = *(_union_1719 *)(puVar4 + 1);
        *(undefined8 *)&param_2->n1 = *puVar4;
        (param_2->n1).decVal.u2 = _Var9;
        local_28 = puVar4[2];
        lVar11 = *param_1;
        *(undefined8 *)((longlong)&param_2->n1 + 0x10) = local_28;
        local_38 = *(undefined4 *)&param_2->n1;
        UStack_34 = (param_2->n1).decVal.Hi32;
        uStack_30 = *(undefined4 *)((longlong)&param_2->n1 + 8);
        uStack_2c = *(undefined4 *)((longlong)&param_2->n1 + 0xc);
        puStack_b0 = (undefined *)0x18003078e;
        uVar6 = (**(code **)(lVar11 + 0x50))(param_1,&local_38,param_3);
        goto LAB_180030960;
      }
LAB_1800306c5:
      puStack_b0 = (undefined *)0x1800306cf;
      VariantInit(&local_60);
      puStack_b0 = (undefined *)0x1800306e5;
      HVar5 = VariantChangeType(&local_60,param_2,0,3);
      if (HVar5 == 0) {
        puStack_b0 = (undefined *)0x1800306f6;
        VariantClear(&local_60);
        goto LAB_18003084e;
      }
      puStack_b0 = (undefined *)0x180030701;
      VariantClear(&local_60);
      puStack_b0 = (undefined *)0x180030717;
      HVar5 = VariantChangeType(&local_60,param_2,0,8);
      if (HVar5 != 0) {
        puStack_b0 = (undefined *)0x180030725;
        VariantClear(&local_60);
        puStack_b0 = (undefined *)0x180030736;
        uVar6 = (**(code **)(*param_1 + 0xd8))(param_1,0x7db);
        puVar13 = auStack_a8;
        goto LAB_180030960;
      }
      lpWideCharStr = (LPCWSTR)CONCAT44(local_60.n1._12_4_,local_60.n1._8_4_);
      puVar12 = auStack_a8;
      if (lpWideCharStr == (LPCWSTR)0x0) goto LAB_180030827;
      lVar11 = -1;
      do {
        lVar11 = lVar11 + 1;
      } while (lpWideCharStr[lVar11] != L'\0');
    }
LAB_1800307bb:
    iVar7 = (int)lVar11;
    puVar12 = auStack_a8;
    if (iVar7 < 0x3fffffff) {
      uVar10 = (longlong)iVar7 * 2 + 0x11;
      if (uVar10 <= (longlong)iVar7 * 2 + 2U) {
        uVar10 = 0xffffffffffffff0;
      }
      puStack_b0 = (undefined *)0x1800307ed;
      lVar11 = -(uVar10 & 0xfffffffffffffff0);
      puVar13 = (undefined1 *)((longlong)&local_68 + lVar11);
      puVar12 = auStack_a8 + lVar11;
      if (puVar13 != (undefined1 *)0x0) {
        *(undefined8 *)((longlong)local_78 + lVar11 + 8) = 0;
        *(undefined8 *)((longlong)local_78 + lVar11) = 0;
        *(int *)((longlong)aiStack_80 + lVar11) = iVar7 * 2 + 2;
        *(undefined1 **)((longlong)&uStack_88 + lVar11) = puVar13;
        *puVar13 = 0;
        *(undefined8 *)(auStack_a8 + lVar11 + -8) = 0x180030827;
        WideCharToMultiByte(0,0,lpWideCharStr,-1,*(LPSTR *)((longlong)&uStack_88 + lVar11),
                            *(int *)((longlong)aiStack_80 + lVar11),
                            *(LPCSTR *)((longlong)local_78 + lVar11),
                            *(LPBOOL *)((longlong)local_78 + lVar11 + 8));
        puVar12 = auStack_a8 + lVar11;
      }
    }
  }
LAB_180030827:
  pcVar2 = *(code **)(*param_1 + 0xd8);
  *(undefined8 *)(puVar12 + -8) = 0x180030838;
  uVar6 = (*pcVar2)(param_1,0x7de);
  puVar13 = puVar12;
LAB_180030960:
  *(undefined8 *)(puVar13 + -8) = 0x18003096a;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_48);
  *(undefined8 *)(puVar13 + -8) = 0x180030978;
  return uVar6;
}

/* ---- FUNC 000309A0 FUN_1800309a0 (687 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1800309a0(longlong *param_1,VARIANTARG *param_2,undefined2 *param_3)

{
  ushort uVar1;
  code *pcVar2;
  undefined8 *puVar3;
  _union_1719 _Var4;
  HRESULT HVar5;
  ulonglong uVar6;
  int iVar7;
  longlong lVar8;
  undefined8 uVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  LPCWSTR lpWideCharStr;
  undefined *puStack_a0;
  undefined1 auStack_98 [32];
  undefined8 uStack_78;
  int aiStack_70 [2];
  undefined8 local_68 [2];
  VARIANTARG local_58;
  int local_40;
  undefined4 local_38;
  ULONG UStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined8 local_28;
  ulonglong local_18;
  
  puVar10 = auStack_98;
  puVar12 = auStack_98;
  puVar11 = auStack_98;
  local_18 = DAT_180077818 ^ (ulonglong)&local_58;
  uVar1 = (param_2->n1).n2.vt;
  if (uVar1 < 0xb) {
    if ((uVar1 == 10) || (uVar1 == 0)) {
      puStack_a0 = (undefined *)0x180030a3f;
      (**(code **)(*param_1 + 0xd8))(param_1,0x7db);
      local_58.n1._8_4_ = local_40;
LAB_180030bfd:
      lVar8 = (longlong)(int)local_58.n1._8_4_;
      puVar12 = auStack_98;
      if (lVar8 <= param_1[0x16] + -1) {
        if (((int)local_58.n1._8_4_ < 0) || (param_1[0x16] <= lVar8)) {
                    /* WARNING: Subroutine does not return */
          puStack_a0 = &UNK_180030c4f;
          AfxThrowInvalidArgException();
        }
        lVar8 = *(longlong *)(param_1[0x15] + lVar8 * 8);
        if (lVar8 == 0) {
          uVar9 = 0;
          *param_3 = 0xffff;
          puVar11 = auStack_98;
        }
        else {
          uVar9 = 0;
          *param_3 = (short)*(undefined4 *)(lVar8 + 0x30);
          puVar11 = auStack_98;
        }
        goto LAB_180030ae3;
      }
    }
    else {
      if (uVar1 == 2) {
        local_58.n1._8_4_ = SEXT24(*(short *)((longlong)&param_2->n1 + 8));
        goto LAB_180030bfd;
      }
      if (uVar1 == 3) {
        local_58.n1._8_4_ = *(int *)((longlong)&param_2->n1 + 8);
        goto LAB_180030bfd;
      }
      if (uVar1 != 8) goto LAB_180030a72;
      lpWideCharStr = *(LPCWSTR *)((longlong)&param_2->n1 + 8);
      puVar12 = auStack_98;
      if (lpWideCharStr != (LPCWSTR)0x0) {
        lVar8 = -1;
        do {
          lVar8 = lVar8 + 1;
        } while (lpWideCharStr[lVar8] != L'\0');
        goto LAB_180030b7b;
      }
    }
LAB_180030be1:
    lVar8 = *param_1;
    uVar9 = 0x7de;
    puVar10 = puVar12;
  }
  else {
    if (uVar1 == 0x4002) {
      local_58.n1._8_4_ = SEXT24(**(short **)((longlong)&param_2->n1 + 8));
      goto LAB_180030bfd;
    }
    if (uVar1 == 0x4003) {
      local_58.n1._8_4_ = **(int **)((longlong)&param_2->n1 + 8);
      goto LAB_180030bfd;
    }
    if (uVar1 == 0x4008) {
      lpWideCharStr = (LPCWSTR)**(longlong **)((longlong)&param_2->n1 + 8);
      if (lpWideCharStr == (LPCWSTR)0x0) goto LAB_180030be1;
      lVar8 = -1;
      do {
        lVar8 = lVar8 + 1;
      } while (lpWideCharStr[lVar8] != L'\0');
LAB_180030b7b:
      iVar7 = (int)lVar8;
      puVar12 = auStack_98;
      if (iVar7 < 0x3fffffff) {
        uVar6 = (longlong)iVar7 * 2 + 0x11;
        if (uVar6 <= (longlong)iVar7 * 2 + 2U) {
          uVar6 = 0xffffffffffffff0;
        }
        puStack_a0 = (undefined *)0x180030bad;
        lVar8 = -(uVar6 & 0xfffffffffffffff0);
        puVar11 = (undefined1 *)((longlong)&local_58 + lVar8);
        puVar12 = auStack_98 + lVar8;
        if (puVar11 != (undefined1 *)0x0) {
          *(undefined8 *)((longlong)local_68 + lVar8 + 8) = 0;
          *(undefined8 *)((longlong)local_68 + lVar8) = 0;
          *(int *)((longlong)aiStack_70 + lVar8) = iVar7 * 2 + 2;
          *(undefined1 **)((longlong)&uStack_78 + lVar8) = puVar11;
          *puVar11 = 0;
          *(undefined8 *)(auStack_98 + lVar8 + -8) = 0x180030be1;
          WideCharToMultiByte(0,0,lpWideCharStr,-1,*(LPSTR *)((longlong)&uStack_78 + lVar8),
                              *(int *)((longlong)aiStack_70 + lVar8),
                              *(LPCSTR *)((longlong)local_68 + lVar8),
                              *(LPBOOL *)((longlong)local_68 + lVar8 + 8));
          puVar12 = auStack_98 + lVar8;
        }
      }
      goto LAB_180030be1;
    }
    if (uVar1 == 0x400c) {
      puVar3 = *(undefined8 **)((longlong)&param_2->n1 + 8);
      _Var4 = *(_union_1719 *)(puVar3 + 1);
      *(undefined8 *)&param_2->n1 = *puVar3;
      (param_2->n1).decVal.u2 = _Var4;
      local_28 = puVar3[2];
      lVar8 = *param_1;
      *(undefined8 *)((longlong)&param_2->n1 + 0x10) = local_28;
      local_38 = *(undefined4 *)&param_2->n1;
      UStack_34 = (param_2->n1).decVal.Hi32;
      uStack_30 = *(undefined4 *)((longlong)&param_2->n1 + 8);
      uStack_2c = *(undefined4 *)((longlong)&param_2->n1 + 0xc);
      puStack_a0 = (undefined *)0x180030b57;
      uVar9 = (**(code **)(lVar8 + 0x58))(local_38,&local_38);
      goto LAB_180030ae3;
    }
LAB_180030a72:
    puStack_a0 = (undefined *)0x180030a7c;
    VariantInit(&local_58);
    puStack_a0 = (undefined *)0x180030a92;
    HVar5 = VariantChangeType(&local_58,param_2,0,3);
    if (HVar5 == 0) {
      puStack_a0 = (undefined *)0x180030aa3;
      VariantClear(&local_58);
      goto LAB_180030bfd;
    }
    puStack_a0 = (undefined *)0x180030aae;
    VariantClear(&local_58);
    puStack_a0 = (undefined *)0x180030ac4;
    HVar5 = VariantChangeType(&local_58,param_2,0,8);
    if (HVar5 == 0) {
      lpWideCharStr = (LPCWSTR)CONCAT44(local_58.n1._12_4_,local_58.n1._8_4_);
      puVar12 = auStack_98;
      if (lpWideCharStr == (LPCWSTR)0x0) goto LAB_180030be1;
      lVar8 = -1;
      do {
        lVar8 = lVar8 + 1;
      } while (lpWideCharStr[lVar8] != L'\0');
      goto LAB_180030b7b;
    }
    puStack_a0 = (undefined *)0x180030ad2;
    VariantClear(&local_58);
    lVar8 = *param_1;
    uVar9 = 0x7db;
  }
  pcVar2 = *(code **)(lVar8 + 0xd8);
  *(undefined8 *)(puVar10 + -8) = 0x180030ae3;
  uVar9 = (*pcVar2)(param_1,uVar9);
  puVar11 = puVar10;
LAB_180030ae3:
  *(undefined8 *)(puVar11 + -8) = 0x180030aef;
  return uVar9;
}

/* ---- FUNC 00030C50 FUN_180030c50 (33 bytes) ---- */

undefined8 FUN_180030c50(longlong param_1,undefined8 *param_2)

{
  wchar_t *pwVar1;
  
  pwVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::AllocSysString
                     ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                      (param_1 + 0x98));
  *param_2 = pwVar1;
  return 0;
}

/* ---- FUNC 00030C80 FUN_180030c80 (134 bytes) ---- */

undefined8 FUN_180030c80(longlong param_1,int param_2,undefined8 *param_3)

{
  longlong lVar1;
  wchar_t *pwVar2;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res8 [8];
  
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8,"");
  if ((longlong)param_2 < *(longlong *)(param_1 + 0xb0)) {
    if (param_2 < 0) {
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
    lVar1 = *(longlong *)(*(longlong *)(param_1 + 0xa8) + (longlong)param_2 * 8);
    if (lVar1 != 0) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                (local_res8,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 (lVar1 + 0x20));
    }
  }
  pwVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::AllocSysString
                     (local_res8);
  *param_3 = pwVar2;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
  return 0;
}

/* ---- FUNC 00030D10 FUN_180030d10 (98 bytes) ---- */

undefined8 FUN_180030d10(longlong param_1,int param_2,wchar_t *param_3)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res8 [8];
  
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8,param_3);
  if ((longlong)param_2 < *(longlong *)(param_1 + 0xb0)) {
    if (param_2 < 0) {
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
               (*(longlong *)(*(longlong *)(param_1 + 0xa8) + (longlong)param_2 * 8) + 0x20),
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               local_res8);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
  return 0;
}

/* ---- FUNC 00030D80 FUN_180030d80 (86 bytes) ---- */

undefined1 * FUN_180030d80(longlong param_1,int *param_2)

{
  char cVar1;
  longlong lVar2;
  char *pcVar3;
  char *pcVar4;
  
  lVar2 = (longlong)*param_2;
  if (*(longlong *)(param_1 + 0x10) <= lVar2) {
    return (undefined1 *)0x0;
  }
  if (-1 < lVar2) {
    pcVar4 = &DAT_1800795d0;
    pcVar3 = *(char **)(*(longlong *)(param_1 + 8) + lVar2 * 8);
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
      *pcVar4 = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    *param_2 = *param_2 + 1;
    return &DAT_1800795d0;
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00030DE0 FUN_180030de0 (5 bytes) ---- */

void FUN_180030de0(longlong param_1,undefined8 param_2)

{
  *(undefined8 *)(param_1 + 0x20) = param_2;
  return;
}

/* ---- FUNC 00030DF0 FUN_180030df0 (192 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined8 FUN_180030df0(undefined8 param_1,undefined8 *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  BSTR pOVar3;
  ulonglong uVar4;
  undefined1 *puVar5;
  undefined8 uStack_40;
  undefined1 auStack_38 [32];
  int local_18 [2];
  ulonglong local_10;
  
  puVar5 = auStack_38;
  local_10 = DAT_180077818 ^ (ulonglong)local_18;
  if (param_2 == (undefined8 *)0x0) {
    uVar2 = 0x80070057;
    puVar5 = auStack_38;
  }
  else {
    *param_2 = 0;
    local_18[0] = 0;
    uStack_40 = 0x180030e3a;
    Ordinal_131("localdir",0,local_18);
    if (local_18[0] == 0) {
      uVar2 = 1;
    }
    else {
      local_18[0] = local_18[0] + 1;
      uVar4 = (longlong)local_18[0] + 0xf;
      if (uVar4 <= (ulonglong)(longlong)local_18[0]) {
        uVar4 = 0xffffffffffffff0;
      }
      uStack_40 = 0x180030e6e;
      lVar1 = -(uVar4 & 0xfffffffffffffff0);
      puVar5 = auStack_38 + lVar1;
      *(undefined8 *)(auStack_38 + lVar1 + -8) = 0x180030e89;
      Ordinal_131("localdir",(LPCSTR)((longlong)local_18 + lVar1),local_18);
      *(undefined8 *)(auStack_38 + lVar1 + -8) = 0x180030e91;
      pOVar3 = FUN_1800019d0((LPCSTR)((longlong)local_18 + lVar1));
      *param_2 = pOVar3;
      uVar2 = 0;
    }
  }
  *(undefined8 *)(puVar5 + -8) = 0x180030ea2;
  return uVar2;
}

/* ---- FUNC 00030EB0 FUN_180030eb0 (76 bytes) ---- */

undefined8 FUN_180030eb0(longlong param_1,undefined8 *param_2)

{
  BSTR pOVar1;
  LPCSTR pCVar2;
  
  if (param_2 == (undefined8 *)0x0) {
    return 0x80070057;
  }
  *param_2 = 0;
  if ((*(longlong *)(param_1 + 0x10) == 0) ||
     (pCVar2 = *(LPCSTR *)(*(longlong *)(param_1 + 0x10) + 0x108), pCVar2 == (LPCSTR)0x0)) {
    pCVar2 = "";
  }
  pOVar1 = FUN_1800019d0(pCVar2);
  *param_2 = pOVar1;
  return 0;
}

/* ---- FUNC 00030F00 FUN_180030f00 (84 bytes) ---- */

undefined8 FUN_180030f00(undefined8 param_1,short *param_2)

{
  int local_res10 [2];
  undefined4 local_res18 [4];
  
  if (param_2 == (short *)0x0) {
    return 0x80070057;
  }
  local_res18[0] = 4;
  *param_2 = 0;
  local_res10[0] = 0;
  Ordinal_131("remote",local_res10,local_res18);
  *param_2 = -(ushort)(local_res10[0] != 0);
  return 0;
}

/* ---- FUNC 00030F60 FUN_180030f60 (192 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined8 FUN_180030f60(undefined8 param_1,undefined8 *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  BSTR pOVar3;
  ulonglong uVar4;
  undefined1 *puVar5;
  undefined8 uStack_40;
  undefined1 auStack_38 [32];
  int local_18 [2];
  ulonglong local_10;
  
  puVar5 = auStack_38;
  local_10 = DAT_180077818 ^ (ulonglong)local_18;
  if (param_2 == (undefined8 *)0x0) {
    uVar2 = 0x80070057;
    puVar5 = auStack_38;
  }
  else {
    *param_2 = 0;
    local_18[0] = 0;
    uStack_40 = 0x180030faa;
    Ordinal_131("runid",0,local_18);
    if (local_18[0] == 0) {
      uVar2 = 1;
    }
    else {
      local_18[0] = local_18[0] + 1;
      uVar4 = (longlong)local_18[0] + 0xf;
      if (uVar4 <= (ulonglong)(longlong)local_18[0]) {
        uVar4 = 0xffffffffffffff0;
      }
      uStack_40 = 0x180030fde;
      lVar1 = -(uVar4 & 0xfffffffffffffff0);
      puVar5 = auStack_38 + lVar1;
      *(undefined8 *)(auStack_38 + lVar1 + -8) = 0x180030ff9;
      Ordinal_131("runid",(LPCSTR)((longlong)local_18 + lVar1),local_18);
      *(undefined8 *)(auStack_38 + lVar1 + -8) = 0x180031001;
      pOVar3 = FUN_1800019d0((LPCSTR)((longlong)local_18 + lVar1));
      *param_2 = pOVar3;
      uVar2 = 0;
    }
  }
  *(undefined8 *)(puVar5 + -8) = 0x180031012;
  return uVar2;
}

/* ---- FUNC 00031020 FUN_180031020 (192 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined8 FUN_180031020(undefined8 param_1,undefined8 *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  BSTR pOVar3;
  ulonglong uVar4;
  undefined1 *puVar5;
  undefined8 uStack_40;
  undefined1 auStack_38 [32];
  int local_18 [2];
  ulonglong local_10;
  
  puVar5 = auStack_38;
  local_10 = DAT_180077818 ^ (ulonglong)local_18;
  if (param_2 == (undefined8 *)0x0) {
    uVar2 = 0x80070057;
    puVar5 = auStack_38;
  }
  else {
    *param_2 = 0;
    local_18[0] = 0;
    uStack_40 = 0x18003106a;
    Ordinal_131("hostname",0,local_18);
    if (local_18[0] == 0) {
      uVar2 = 1;
    }
    else {
      local_18[0] = local_18[0] + 1;
      uVar4 = (longlong)local_18[0] + 0xf;
      if (uVar4 <= (ulonglong)(longlong)local_18[0]) {
        uVar4 = 0xffffffffffffff0;
      }
      uStack_40 = 0x18003109e;
      lVar1 = -(uVar4 & 0xfffffffffffffff0);
      puVar5 = auStack_38 + lVar1;
      *(undefined8 *)(auStack_38 + lVar1 + -8) = 0x1800310b9;
      Ordinal_131("hostname",(LPCSTR)((longlong)local_18 + lVar1),local_18);
      *(undefined8 *)(auStack_38 + lVar1 + -8) = 0x1800310c1;
      pOVar3 = FUN_1800019d0((LPCSTR)((longlong)local_18 + lVar1));
      *param_2 = pOVar3;
      uVar2 = 0;
    }
  }
  *(undefined8 *)(puVar5 + -8) = 0x1800310d2;
  return uVar2;
}

/* ---- FUNC 000310E0 FUN_1800310e0 (192 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined8 FUN_1800310e0(undefined8 param_1,undefined8 *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  BSTR pOVar3;
  ulonglong uVar4;
  undefined1 *puVar5;
  undefined8 uStack_40;
  undefined1 auStack_38 [32];
  int local_18 [2];
  ulonglong local_10;
  
  puVar5 = auStack_38;
  local_10 = DAT_180077818 ^ (ulonglong)local_18;
  if (param_2 == (undefined8 *)0x0) {
    uVar2 = 0x80070057;
    puVar5 = auStack_38;
  }
  else {
    *param_2 = 0;
    local_18[0] = 0;
    uStack_40 = 0x18003112a;
    Ordinal_131("remotedir",0,local_18);
    if (local_18[0] == 0) {
      uVar2 = 1;
    }
    else {
      local_18[0] = local_18[0] + 1;
      uVar4 = (longlong)local_18[0] + 0xf;
      if (uVar4 <= (ulonglong)(longlong)local_18[0]) {
        uVar4 = 0xffffffffffffff0;
      }
      uStack_40 = 0x18003115e;
      lVar1 = -(uVar4 & 0xfffffffffffffff0);
      puVar5 = auStack_38 + lVar1;
      *(undefined8 *)(auStack_38 + lVar1 + -8) = 0x180031179;
      Ordinal_131("remotedir",(LPCSTR)((longlong)local_18 + lVar1),local_18);
      *(undefined8 *)(auStack_38 + lVar1 + -8) = 0x180031181;
      pOVar3 = FUN_1800019d0((LPCSTR)((longlong)local_18 + lVar1));
      *param_2 = pOVar3;
      uVar2 = 0;
    }
  }
  *(undefined8 *)(puVar5 + -8) = 0x180031192;
  return uVar2;
}

/* ---- FUNC 000311A0 FUN_1800311a0 (192 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined8 FUN_1800311a0(undefined8 param_1,undefined8 *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  BSTR pOVar3;
  ulonglong uVar4;
  undefined1 *puVar5;
  undefined8 uStack_40;
  undefined1 auStack_38 [32];
  int local_18 [2];
  ulonglong local_10;
  
  puVar5 = auStack_38;
  local_10 = DAT_180077818 ^ (ulonglong)local_18;
  if (param_2 == (undefined8 *)0x0) {
    uVar2 = 0x80070057;
    puVar5 = auStack_38;
  }
  else {
    *param_2 = 0;
    local_18[0] = 0;
    uStack_40 = 0x1800311ea;
    Ordinal_131("username",0,local_18);
    if (local_18[0] == 0) {
      uVar2 = 1;
    }
    else {
      local_18[0] = local_18[0] + 1;
      uVar4 = (longlong)local_18[0] + 0xf;
      if (uVar4 <= (ulonglong)(longlong)local_18[0]) {
        uVar4 = 0xffffffffffffff0;
      }
      uStack_40 = 0x18003121e;
      lVar1 = -(uVar4 & 0xfffffffffffffff0);
      puVar5 = auStack_38 + lVar1;
      *(undefined8 *)(auStack_38 + lVar1 + -8) = 0x180031239;
      Ordinal_131("username",(LPCSTR)((longlong)local_18 + lVar1),local_18);
      *(undefined8 *)(auStack_38 + lVar1 + -8) = 0x180031241;
      pOVar3 = FUN_1800019d0((LPCSTR)((longlong)local_18 + lVar1));
      *param_2 = pOVar3;
      uVar2 = 0;
    }
  }
  *(undefined8 *)(puVar5 + -8) = 0x180031252;
  return uVar2;
}

/* ---- FUNC 00031260 FUN_180031260 (49 bytes) ---- */

undefined8 FUN_180031260(undefined8 param_1,undefined8 *param_2)

{
  LPCSTR pCVar1;
  BSTR pOVar2;
  
  if (param_2 == (undefined8 *)0x0) {
    return 0x80070057;
  }
  pCVar1 = (LPCSTR)MVGetVersionString();
  pOVar2 = FUN_1800019d0(pCVar1);
  *param_2 = pOVar2;
  return 0;
}

/* ---- FUNC 000312A0 FUN_1800312a0 (590 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

HRESULT FUN_1800312a0(IBindCtx *param_1,longlong *param_2,longlong param_3,ULONG *param_4,
                     LPMONIKER *param_5)

{
  LPCOLESTR szUserName;
  OLECHAR OVar1;
  short sVar2;
  _func_5262 *p_Var3;
  IBindCtxVtbl **ppIVar4;
  LPBC This;
  LPBC pIVar5;
  int iVar6;
  longlong lVar7;
  OLECHAR *pOVar8;
  short *psVar9;
  ulonglong uVar10;
  LPCOLESTR pOVar11;
  longlong lVar12;
  undefined1 *puVar13;
  longlong lVar14;
  undefined8 uStack_480;
  undefined1 auStack_478 [30];
  short sStack_45a;
  LPBC local_458;
  ULONG local_450 [2];
  OLECHAR *local_448 [2];
  undefined1 local_438 [1008];
  ulonglong local_48;
  
  puVar13 = auStack_478;
  local_48 = DAT_180077818 ^ (ulonglong)&local_458;
  local_458 = (IBindCtx *)0x0;
  local_450[0] = 0;
  if (((param_2 == (longlong *)0x0) || (param_3 == 0)) || (param_5 == (LPMONIKER *)0x0)) {
    uStack_480 = 0x180031312;
    FUN_180002a20(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\helper.cpp",0xda);
    uStack_480 = 0x180031325;
    LogMessage(local_438,2,1);
    if (((param_2 == (longlong *)0x0) || (param_3 == 0)) || (param_5 == (LPMONIKER *)0x0)) {
      iVar6 = -0x7ff8ffa9;
      goto LAB_1800314bc;
    }
  }
  *param_5 = (LPMONIKER)0x0;
  if (param_1 == (IBindCtx *)0x0) {
    uStack_480 = 0x180031378;
    iVar6 = CreateBindCtx(0,&local_458);
    puVar13 = auStack_478;
    pIVar5 = local_458;
    if (iVar6 < 0) goto LAB_1800314bc;
  }
  else {
    pIVar5 = local_458;
    if (local_458 != param_1) {
      uStack_480 = 0x180031357;
      (*param_1->lpVtbl->AddRef)(param_1);
      This = local_458;
      pIVar5 = param_1;
      if (local_458 != (IBindCtx *)0x0) {
        ppIVar4 = &local_458->lpVtbl;
        uStack_480 = 0x18003136a;
        local_458 = param_1;
        (*(*ppIVar4)->Release)(This);
        pIVar5 = local_458;
      }
    }
  }
  local_458 = pIVar5;
  if (local_458 == (IBindCtx *)0x0) {
    iVar6 = -0x7fffbffb;
    puVar13 = auStack_478;
  }
  else {
    local_448[0] = (OLECHAR *)0x0;
    uStack_480 = 0x1800313ae;
    iVar6 = (**(code **)(*param_2 + 0xa0))(param_2,local_458,0,local_448);
    puVar13 = auStack_478;
    if (-1 < iVar6) {
      lVar7 = -1;
      lVar14 = -1;
      do {
        lVar14 = lVar14 + 1;
      } while (local_448[0][lVar14] != L'\0');
      do {
        lVar7 = lVar7 + 1;
      } while (*(short *)(param_3 + lVar7 * 2) != 0);
      lVar7 = (lVar7 + lVar14) * 2;
      uVar10 = lVar7 + 0x11;
      if (uVar10 <= lVar7 + 2U) {
        uVar10 = 0xffffffffffffff0;
      }
      uStack_480 = 0x180031404;
      lVar7 = -(uVar10 & 0xfffffffffffffff0);
      szUserName = (LPCOLESTR)((longlong)local_450 + lVar7 + -8);
      pOVar8 = local_448[0];
      pOVar11 = szUserName;
      do {
        OVar1 = *pOVar8;
        *pOVar11 = OVar1;
        pOVar8 = pOVar8 + 1;
        pOVar11 = pOVar11 + 1;
      } while (OVar1 != L'\0');
      psVar9 = (short *)((longlong)&sStack_45a + lVar7);
      do {
        psVar9 = psVar9 + 1;
      } while (*psVar9 != 0);
      lVar12 = 0;
      do {
        sVar2 = *(short *)(param_3 + lVar12 * 2);
        psVar9[lVar12] = sVar2;
        pOVar8 = local_448[0];
        lVar12 = lVar12 + 1;
      } while (sVar2 != 0);
      *(undefined8 *)(auStack_478 + lVar7 + -8) = 0x18003145b;
      CoTaskMemFree(pOVar8);
      pIVar5 = local_458;
      *(undefined8 *)(auStack_478 + lVar7 + -8) = 0x18003146f;
      iVar6 = MkParseDisplayName(pIVar5,szUserName,local_450,param_5);
      if (iVar6 < 0) {
        *(undefined8 *)(auStack_478 + lVar7 + -8) = 0x180031492;
        FUN_180002a20(local_438,"Assert failed in file %s line %d",
                      "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\helper.cpp",0xf4);
        *(undefined8 *)(auStack_478 + lVar7 + -8) = 0x1800314a5;
        LogMessage(local_438,2,1);
      }
      local_450[0] = local_450[0] - (int)lVar14;
      puVar13 = auStack_478 + lVar7;
      if (param_4 != (ULONG *)0x0) {
        *param_4 = local_450[0];
        puVar13 = auStack_478 + lVar7;
      }
    }
  }
LAB_1800314bc:
  pIVar5 = local_458;
  if (local_458 != (IBindCtx *)0x0) {
    p_Var3 = local_458->lpVtbl->Release;
    *(undefined8 *)(puVar13 + -8) = 0x1800314cb;
    (*p_Var3)(pIVar5);
  }
  *(undefined8 *)(puVar13 + -8) = 0x1800314dc;
  return iVar6;
}

/* ---- FUNC 000314F0 FUN_1800314f0 (344 bytes) ---- */

HGLOBAL FUN_1800314f0(uint *param_1,uint param_2,undefined8 param_3,undefined8 param_4,uint param_5,
                     LPCSTR param_6,LPCSTR param_7)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  HGLOBAL hMem;
  uint *puVar7;
  LPCSTR lpMultiByteStr;
  
  iVar4 = lstrlenA(param_6);
  iVar4 = iVar4 + 1;
  lpMultiByteStr = param_6;
  iVar5 = iVar4;
  if (param_7 != (LPCSTR)0x0) {
    iVar5 = lstrlenA(param_7);
    lpMultiByteStr = param_7;
    iVar5 = iVar5 + 1;
  }
  uVar6 = (iVar5 + iVar4) * 2 + 0x34;
  hMem = GlobalAlloc(0x42,(ulonglong)uVar6);
  if (hMem != (HGLOBAL)0x0) {
    puVar7 = GlobalLock(hMem);
    *puVar7 = uVar6;
    *(undefined8 *)(puVar7 + 8) = param_4;
    *(undefined8 *)(puVar7 + 6) = param_3;
    puVar7[10] = param_5;
    uVar6 = *param_1;
    uVar1 = param_1[1];
    uVar2 = param_1[2];
    uVar3 = param_1[3];
    puVar7[5] = param_2;
    puVar7[1] = uVar6;
    puVar7[2] = uVar1;
    puVar7[3] = uVar2;
    puVar7[4] = uVar3;
    if (param_6 == (LPCSTR)0x0) {
      puVar7[0xb] = 0;
    }
    else {
      puVar7[0xb] = 0x34;
      MultiByteToWideChar(0,0,param_6,-1,(LPWSTR)(puVar7 + 0xd),iVar4);
    }
    if (lpMultiByteStr == (LPCSTR)0x0) {
      puVar7[0xc] = 0;
    }
    else {
      uVar6 = iVar4 * 2 + 0x34;
      puVar7[0xc] = uVar6;
      MultiByteToWideChar(0,0,lpMultiByteStr,-1,(LPWSTR)((ulonglong)uVar6 + (longlong)puVar7),iVar5)
      ;
    }
    GlobalUnlock(hMem);
    return hMem;
  }
  return (HGLOBAL)0x0;
}

/* ---- FUNC 00031650 FUN_180031650 (183 bytes) ---- */

HRESULT FUN_180031650(LPPERSISTSTREAM param_1,IID *param_2,longlong param_3,int *param_4)

{
  HRESULT HVar1;
  LPSTREAM pStm;
  LPSTREAM local_res20;
  
  local_res20 = (LPSTREAM)0x0;
  param_4[4] = 0;
  param_4[5] = 0;
  if (*param_4 == 0) {
    if ((*(byte *)(param_3 + 0x18) & 4) == 0) {
      return -0x7ffbff9c;
    }
    HVar1 = CreateStreamOnHGlobal((HGLOBAL)0x0,1,&local_res20);
    if (HVar1 < 0) {
      return -0x7ff8fff2;
    }
    *(LPSTREAM *)(param_4 + 2) = local_res20;
    pStm = local_res20;
  }
  else {
    if (*param_4 != 4) {
      return -0x7ffbff9c;
    }
    pStm = *(LPSTREAM *)(param_4 + 2);
    *(LPSTREAM *)(param_4 + 2) = pStm;
  }
  *param_4 = 4;
  HVar1 = OleSaveToStream(param_1,pStm);
  if (-1 < HVar1) {
    HVar1 = WriteClassStm(*(LPSTREAM *)(param_4 + 2),param_2);
    return HVar1;
  }
  return HVar1;
}

/* ---- FUNC 00031710 FUN_180031710 (13 bytes) ---- */

int FUN_180031710(longlong param_1)

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

/* ---- FUNC 00031720 FUN_180031720 (13 bytes) ---- */

int FUN_180031720(longlong param_1)

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

/* ---- FUNC 00031730 FUN_180031730 (4 bytes) ---- */

undefined4 FUN_180031730(longlong param_1)

{
  return *(undefined4 *)(param_1 + 0xc);
}

/* ---- FUNC 00031740 FUN_180031740 (116 bytes) ---- */

HRESULT FUN_180031740(longlong param_1,undefined8 *param_2)

{
  LPVOID *ppv;
  HRESULT HVar1;
  
  if (param_2 == (undefined8 *)0x0) {
    return -0x7fffbffd;
  }
  ppv = (LPVOID *)(param_1 + 0x40);
  HVar1 = 0;
  if ((*ppv == (LPVOID)0x0) &&
     (HVar1 = CoCreateInstance((IID *)&DAT_180066d88,(LPUNKNOWN)0x0,1,(IID *)&DAT_180065030,ppv),
     HVar1 < 0)) {
    return HVar1;
  }
  *param_2 = *ppv;
  (**(code **)(*(longlong *)*ppv + 8))();
  return HVar1;
}

/* ---- FUNC 000317C0 FUN_1800317c0 (24 bytes) ---- */

void FUN_1800317c0(undefined8 param_1,longlong *param_2)

{
                    /* WARNING: Could not recover jumptable at 0x0001800317d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_2 + 0x18))(param_2,L"APPID",&DAT_1800648c0);
  return;
}

/* ---- FUNC 000317E0 thunk_FUN_180036af0 (5 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */

DWORD thunk_FUN_180036af0(longlong *param_1,LPCSTR param_2,int param_3,undefined8 *param_4)

{
  char *pcVar1;
  WCHAR WVar2;
  HMODULE pHVar3;
  char cVar4;
  BOOL BVar5;
  DWORD DVar6;
  int iVar7;
  uint uVar8;
  longlong lVar9;
  ulonglong uVar10;
  LPCWSTR pWVar11;
  LPCWSTR pWVar12;
  HMODULE pHVar13;
  int *piVar14;
  longlong lVar15;
  LPCWSTR pWVar16;
  WCHAR *pWVar17;
  WCHAR *pWVar18;
  LPCWSTR pWVar19;
  LPCWSTR pWVar20;
  undefined1 *puVar21;
  undefined1 *puVar22;
  LPCWSTR pWVar23;
  ulonglong uVar24;
  undefined1 auStack_a18 [48];
  undefined **ppuStack_9e8;
  void *pvStack_9e0;
  void *pvStack_9d8;
  int iStack_9d0;
  _RTL_CRITICAL_SECTION _Stack_9c8;
  char cStack_9a0;
  LPCWSTR pWStack_998;
  CHAR CStack_988;
  char acStack_987 [271];
  WCHAR aWStack_878 [528];
  WCHAR aWStack_458 [520];
  ulonglong uStack_48;
  
  puVar21 = auStack_a18;
  uStack_48 = DAT_180077818 ^ (ulonglong)&ppuStack_9e8;
  ppuStack_9e8 = ATL::CRegObject::vftable;
  pWVar19 = (LPCWSTR)0x0;
  pvStack_9e0 = (void *)0x0;
  pvStack_9d8 = (void *)0x0;
  iStack_9d0 = 0;
  _Stack_9c8.DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
  _Stack_9c8.LockCount = 0;
  _Stack_9c8.RecursionCount = 0;
  _Stack_9c8.OwningThread = (HANDLE)0x0;
  _Stack_9c8.LockSemaphore = (HANDLE)0x0;
  _Stack_9c8.SpinCount = 0;
  cStack_9a0 = '\0';
  BVar5 = InitializeCriticalSectionEx(&_Stack_9c8,0,0);
  if (BVar5 == 0) {
    DVar6 = GetLastError();
    if (0 < (int)DVar6) {
      DVar6 = DVar6 & 0xffff | 0x80070000;
    }
    if ((int)DVar6 < 0) {
      ppuStack_9e8 = ATL::CRegObject::vftable;
      EnterCriticalSection(&_Stack_9c8);
      pWVar20 = pWVar19;
      pWVar23 = pWVar19;
      if (0 < iStack_9d0) {
        do {
          if ((((longlong)pWVar20 < 0) || (iVar7 = (int)pWVar23, iStack_9d0 <= iVar7)) ||
             (operator_delete__(*(void **)((longlong)pWVar20 + (longlong)pvStack_9e0)),
             iStack_9d0 <= iVar7)) {
                    /* WARNING: Subroutine does not return */
            FUN_180001a90(-0x7ffffff5);
          }
          operator_delete__(*(void **)((longlong)pWVar20 + (longlong)pvStack_9d8));
          pWVar20 = pWVar20 + 4;
          pWVar23 = (LPCWSTR)(ulonglong)(iVar7 + 1U);
        } while ((int)(iVar7 + 1U) < iStack_9d0);
      }
      if (pvStack_9e0 != (void *)0x0) {
        free(pvStack_9e0);
        pvStack_9e0 = (void *)0x0;
      }
      if (pvStack_9d8 != (void *)0x0) {
        free(pvStack_9d8);
        pvStack_9d8 = (void *)0x0;
      }
      iStack_9d0 = 0;
      LeaveCriticalSection(&_Stack_9c8);
      if (cStack_9a0 != '\0') {
        cStack_9a0 = '\0';
        DeleteCriticalSection(&_Stack_9c8);
      }
      pWVar20 = pWVar19;
      if (0 < iStack_9d0) {
        do {
          if ((((longlong)pWVar20 < 0) || (iVar7 = (int)pWVar19, iStack_9d0 <= iVar7)) ||
             (operator_delete__(*(void **)((longlong)pWVar20 + (longlong)pvStack_9e0)),
             iStack_9d0 <= iVar7)) {
                    /* WARNING: Subroutine does not return */
            FUN_180001a90(-0x7ffffff5);
          }
          operator_delete__(*(void **)((longlong)pWVar20 + (longlong)pvStack_9d8));
          pWVar19 = (LPCWSTR)(ulonglong)(iVar7 + 1U);
          pWVar20 = pWVar20 + 4;
        } while ((int)(iVar7 + 1U) < iStack_9d0);
      }
      if (pvStack_9e0 != (void *)0x0) {
        free(pvStack_9e0);
        pvStack_9e0 = (void *)0x0;
      }
      if (pvStack_9d8 != (void *)0x0) {
        free(pvStack_9d8);
        pvStack_9d8 = (void *)0x0;
      }
      iStack_9d0 = 0;
      if (pvStack_9e0 != (void *)0x0) {
        free(pvStack_9e0);
        pvStack_9e0 = (void *)0x0;
      }
      puVar21 = auStack_a18;
      if (pvStack_9d8 != (void *)0x0) {
        free(pvStack_9d8);
        puVar21 = auStack_a18;
      }
      goto LAB_180036ce3;
    }
  }
  cStack_9a0 = '\x01';
  if (param_4 != (undefined8 *)0x0) {
    pWVar20 = (LPCWSTR)*param_4;
    while (pWVar20 != (LPCWSTR)0x0) {
      FUN_180031840((longlong)&ppuStack_9e8,pWVar20,(void *)param_4[1]);
      param_4 = param_4 + 2;
      pWVar20 = (LPCWSTR)*param_4;
    }
  }
  DVar6 = (**(code **)(*param_1 + 0x28))(param_1,&ppuStack_9e8);
  pHVar3 = DAT_18007a618;
  if ((int)DVar6 < 0) {
    ppuStack_9e8 = ATL::CRegObject::vftable;
    EnterCriticalSection(&_Stack_9c8);
    pWVar20 = pWVar19;
    pWVar23 = pWVar19;
    if (0 < iStack_9d0) {
      do {
        if ((((longlong)pWVar20 < 0) || (iVar7 = (int)pWVar23, iStack_9d0 <= iVar7)) ||
           (operator_delete__(*(void **)((longlong)pWVar20 + (longlong)pvStack_9e0)),
           iStack_9d0 <= iVar7)) {
                    /* WARNING: Subroutine does not return */
          FUN_180001a90(-0x7ffffff5);
        }
        operator_delete__(*(void **)((longlong)pWVar20 + (longlong)pvStack_9d8));
        pWVar20 = pWVar20 + 4;
        pWVar23 = (LPCWSTR)(ulonglong)(iVar7 + 1U);
      } while ((int)(iVar7 + 1U) < iStack_9d0);
    }
    if (pvStack_9e0 != (void *)0x0) {
      free(pvStack_9e0);
      pvStack_9e0 = (void *)0x0;
    }
    if (pvStack_9d8 != (void *)0x0) {
      free(pvStack_9d8);
      pvStack_9d8 = (void *)0x0;
    }
    iStack_9d0 = 0;
    LeaveCriticalSection(&_Stack_9c8);
    if (cStack_9a0 != '\0') {
      cStack_9a0 = '\0';
      DeleteCriticalSection(&_Stack_9c8);
    }
    pWVar20 = pWVar19;
    if (0 < iStack_9d0) {
      do {
        if ((((longlong)pWVar20 < 0) || (iVar7 = (int)pWVar19, iStack_9d0 <= iVar7)) ||
           (operator_delete__(*(void **)((longlong)pWVar20 + (longlong)pvStack_9e0)),
           iStack_9d0 <= iVar7)) {
                    /* WARNING: Subroutine does not return */
          FUN_180001a90(-0x7ffffff5);
        }
        operator_delete__(*(void **)((longlong)pWVar20 + (longlong)pvStack_9d8));
        pWVar19 = (LPCWSTR)(ulonglong)(iVar7 + 1U);
        pWVar20 = pWVar20 + 4;
      } while ((int)(iVar7 + 1U) < iStack_9d0);
    }
    if (pvStack_9e0 != (void *)0x0) {
      free(pvStack_9e0);
      pvStack_9e0 = (void *)0x0;
    }
    if (pvStack_9d8 != (void *)0x0) {
      free(pvStack_9d8);
      pvStack_9d8 = (void *)0x0;
    }
    iStack_9d0 = 0;
    if (pvStack_9e0 != (void *)0x0) {
      free(pvStack_9e0);
      pvStack_9e0 = (void *)0x0;
    }
    puVar21 = auStack_a18;
    if (pvStack_9d8 != (void *)0x0) {
      free(pvStack_9d8);
      puVar21 = auStack_a18;
    }
    goto LAB_180036ce3;
  }
  pWStack_998 = (LPCWSTR)0x0;
  DVar6 = GetModuleFileNameA(DAT_18007a618,&CStack_988,0x104);
  if (DVar6 == 0) {
    DVar6 = FUN_1800333f0();
    FUN_180032790(&ppuStack_9e8);
    puVar21 = auStack_a18;
    goto LAB_180036ce3;
  }
  if (DVar6 == 0x104) {
    FUN_180032790(&ppuStack_9e8);
    DVar6 = 0x8007007a;
    puVar21 = auStack_a18;
    goto LAB_180036ce3;
  }
  lVar15 = -1;
  do {
    lVar9 = lVar15 + 1;
    pcVar1 = acStack_987 + lVar15;
    lVar15 = lVar9;
  } while (*pcVar1 != '\0');
  lVar15 = (longlong)((int)lVar9 + 1) * 2;
  pWVar20 = pWVar19;
  puVar22 = auStack_a18;
  pWVar23 = pWVar19;
  if (lVar15 + 0x80000000U < 0x100000000) {
    iVar7 = (int)lVar15;
    uVar24 = (ulonglong)iVar7;
    if ((iVar7 < 0x401) && (cVar4 = FUN_1800026d0(uVar24), cVar4 != '\0')) {
      uVar10 = uVar24 + 0xf;
      if (uVar10 <= uVar24) {
        uVar10 = 0xffffffffffffff0;
      }
      puVar21 = auStack_a18 + -(uVar10 & 0xfffffffffffffff0);
      pWVar12 = (LPCWSTR)((longlong)&ppuStack_9e8 + -(uVar10 & 0xfffffffffffffff0));
    }
    else {
      if (~uVar24 < 0x10) {
                    /* WARNING: Subroutine does not return */
        FUN_180001a90(-0x7ff8fdea);
      }
      pWVar11 = malloc(uVar24 + 0x10);
      pWVar12 = pWVar19;
      if (pWVar11 != (LPCWSTR)0x0) {
        pWVar11[0] = L'\0';
        pWVar11[1] = L'\0';
        pWVar11[2] = L'\0';
        pWVar11[3] = L'\0';
        pWStack_998 = pWVar11;
        pWVar20 = pWVar11;
        puVar21 = auStack_a18;
        pWVar12 = pWVar11 + 8;
      }
    }
    puVar22 = puVar21;
    if (pWVar12 != (LPCWSTR)0x0) {
      *pWVar12 = L'\0';
      *(int *)(puVar21 + 0x28) = (int)(uVar24 >> 1);
      *(LPCWSTR *)(puVar21 + 0x20) = pWVar12;
      *(undefined8 *)(puVar21 + -8) = 0x180036fc9;
      iVar7 = MultiByteToWideChar(0,0,&CStack_988,-1,*(LPWSTR *)(puVar21 + 0x20),
                                  *(int *)(puVar21 + 0x28));
      pWVar23 = pWVar12;
      if (iVar7 == 0) {
        pWVar23 = pWVar19;
      }
    }
  }
  puVar21 = puVar22;
  if (pWVar23 == (LPCWSTR)0x0) {
    while (pWVar20 != (LPCWSTR)0x0) {
      pWVar19 = *(LPCWSTR *)pWVar20;
      *(undefined8 *)(puVar22 + -8) = 0x180036fec;
      free(pWVar20);
      pWVar20 = pWVar19;
    }
    *(undefined8 *)(puVar22 + -8) = 0x180036ffa;
    FUN_180032790(&ppuStack_9e8);
    DVar6 = 0x8007000e;
    goto LAB_180036ce3;
  }
  pWVar12 = pWVar19;
  pWVar17 = aWStack_458;
  pWVar11 = pWVar23;
  do {
    uVar8 = (uint)pWVar12;
    WVar2 = *pWVar11;
    pWVar18 = pWVar17;
    if (WVar2 == L'\0') break;
    *pWVar17 = WVar2;
    pWVar18 = pWVar17 + 1;
    if ((WVar2 == L'\'') && (uVar8 = uVar8 + 1, uVar8 < 0x207)) {
      *pWVar18 = L'\'';
      pWVar18 = pWVar17 + 2;
    }
    pWVar11 = pWVar11 + 1;
    pWVar12 = (LPCWSTR)(ulonglong)(uVar8 + 1);
    pWVar17 = pWVar18;
  } while (uVar8 + 1 < 0x207);
  *pWVar18 = L'\0';
  if (pHVar3 == (HMODULE)0x0) {
LAB_180037066:
    aWStack_878[0] = L'\"';
    lVar15 = -1;
    do {
      lVar15 = lVar15 + 1;
    } while (aWStack_458[lVar15] != L'\0');
    uVar24 = (longlong)((int)lVar15 + 1) * 2;
    if (uVar24 != 0) {
      if (0x416 < uVar24) {
        *(undefined8 *)(puVar22 + -8) = 0x18003714e;
        memset(aWStack_878 + 1,0,0x416);
        *(undefined8 *)(puVar22 + -8) = 0x180037154;
        piVar14 = _errno();
        *piVar14 = 0x22;
        *(undefined8 *)(puVar22 + -8) = 0x18003715c;
        _invalid_parameter_noinfo();
        while (pWVar20 != (LPCWSTR)0x0) {
          pWVar19 = *(LPCWSTR *)pWVar20;
          *(undefined8 *)(puVar22 + -8) = 0x18003716e;
          free(pWVar20);
          pWVar20 = pWVar19;
        }
        *(undefined8 *)(puVar22 + -8) = 0x18003717c;
        FUN_180032790(&ppuStack_9e8);
        DVar6 = 0x80004005;
        goto LAB_180036ce3;
      }
      *(undefined8 *)(puVar22 + -8) = 0x1800370b4;
      memcpy(aWStack_878 + 1,aWStack_458,uVar24);
    }
    lVar15 = -1;
    do {
      lVar15 = lVar15 + 1;
    } while (aWStack_878[lVar15] != L'\0');
    lVar15 = (longlong)(int)lVar15;
    aWStack_878[lVar15] = L'\"';
    if (0x417 < lVar15 * 2 + 2U) {
                    /* WARNING: Subroutine does not return */
      *(undefined8 *)(puVar22 + -8) = 0x180037344;
      FUN_18005c254();
    }
    aWStack_878[lVar15 + 1] = 0;
    pWVar17 = aWStack_878;
  }
  else {
    *(undefined8 *)(puVar22 + -8) = 0x180037055;
    pHVar13 = GetModuleHandleA((LPCSTR)0x0);
    if (pHVar3 == pHVar13) goto LAB_180037066;
    pWVar17 = aWStack_458;
  }
  *(undefined8 *)(puVar22 + -8) = 0x18003710a;
  DVar6 = FUN_180031840((longlong)&ppuStack_9e8,L"Module",pWVar17);
  if ((int)DVar6 < 0) {
    while (pWVar20 != (LPCWSTR)0x0) {
      pWVar19 = *(LPCWSTR *)pWVar20;
      *(undefined8 *)(puVar22 + -8) = 0x18003712c;
      free(pWVar20);
      pWVar20 = pWVar19;
    }
    *(undefined8 *)(puVar22 + -8) = 0x18003713a;
    FUN_180032790(&ppuStack_9e8);
    goto LAB_180036ce3;
  }
  *(undefined8 *)(puVar22 + -8) = 0x18003719d;
  DVar6 = FUN_180031840((longlong)&ppuStack_9e8,L"Module_Raw",aWStack_458);
  if ((int)DVar6 < 0) {
    while (pWVar20 != (LPCWSTR)0x0) {
      pWVar19 = *(LPCWSTR *)pWVar20;
      *(undefined8 *)(puVar22 + -8) = 0x1800371bc;
      free(pWVar20);
      pWVar20 = pWVar19;
    }
    *(undefined8 *)(puVar22 + -8) = 0x1800371ca;
    FUN_180032790(&ppuStack_9e8);
    goto LAB_180036ce3;
  }
  if (param_2 != (LPCSTR)0x0) {
    lVar15 = -1;
    do {
      lVar15 = lVar15 + 1;
    } while (param_2[lVar15] != '\0');
    lVar15 = (longlong)((int)lVar15 + 1) * 2;
    pWVar12 = pWVar19;
    if (lVar15 + 0x80000000U < 0x100000000) {
      iVar7 = (int)lVar15;
      uVar24 = (ulonglong)iVar7;
      if (iVar7 < 0x401) {
        *(undefined8 *)(puVar22 + -8) = 0x18003721c;
        cVar4 = FUN_1800026d0(uVar24);
        if (cVar4 == '\0') goto LAB_180037246;
        uVar10 = uVar24 + 0xf;
        if (uVar10 <= uVar24) {
          uVar10 = 0xffffffffffffff0;
        }
        *(undefined8 *)(puVar22 + -8) = 0x18003723c;
        pWVar11 = (LPCWSTR)(puVar22 + -(uVar10 & 0xfffffffffffffff0) + 0x30);
        puVar22 = puVar22 + -(uVar10 & 0xfffffffffffffff0);
      }
      else {
LAB_180037246:
        if (~uVar24 < 0x10) {
                    /* WARNING: Subroutine does not return */
          *(undefined **)(puVar22 + -8) = &UNK_18003733e;
          FUN_180001a90(-0x7ff8fdea);
        }
        *(undefined8 *)(puVar22 + -8) = 0x180037260;
        pWVar16 = malloc(uVar24 + 0x10);
        pWVar11 = pWVar19;
        if (pWVar16 != (LPCWSTR)0x0) {
          *(LPCWSTR *)pWVar16 = pWVar20;
          pWStack_998 = pWVar16;
          pWVar20 = pWVar16;
          pWVar11 = pWVar16 + 8;
        }
      }
      if (pWVar11 != (LPCWSTR)0x0) {
        *pWVar11 = L'\0';
        *(int *)(puVar22 + 0x28) = (int)(uVar24 >> 1);
        *(LPCWSTR *)(puVar22 + 0x20) = pWVar11;
        *(undefined8 *)(puVar22 + -8) = 0x1800372a0;
        iVar7 = MultiByteToWideChar(0,0,param_2,-1,*(LPWSTR *)(puVar22 + 0x20),
                                    *(int *)(puVar22 + 0x28));
        pWVar12 = pWVar11;
        if (iVar7 == 0) {
          pWVar12 = pWVar19;
        }
      }
    }
    if (pWVar12 != (LPCWSTR)0x0) {
      if (param_3 == 0) {
        *(undefined8 *)(puVar22 + -8) = 0x1800372d2;
        DVar6 = FUN_180035dd0(&ppuStack_9e8,pWVar23,pWVar12,L"REGISTRY");
      }
      else {
        *(undefined8 *)(puVar22 + -8) = 0x1800372cb;
        DVar6 = FUN_180035b10(&ppuStack_9e8,pWVar23,pWVar12,L"REGISTRY");
      }
      while (pWVar20 != (LPCWSTR)0x0) {
        pWVar19 = *(LPCWSTR *)pWVar20;
        *(undefined8 *)(puVar22 + -8) = 0x1800372ec;
        free(pWVar20);
        pWVar20 = pWVar19;
      }
      *(undefined8 *)(puVar22 + -8) = 0x1800372fa;
      FUN_180032790(&ppuStack_9e8);
      puVar21 = puVar22;
      goto LAB_180036ce3;
    }
  }
  while (pWVar20 != (LPCWSTR)0x0) {
    pWVar19 = *(LPCWSTR *)pWVar20;
    *(undefined8 *)((longlong)puVar22 + -8) = 0x18003731c;
    free(pWVar20);
    pWVar20 = pWVar19;
  }
  *(undefined8 *)((longlong)puVar22 + -8) = 0x18003732a;
  FUN_180032790(&ppuStack_9e8);
  DVar6 = 0x8007000e;
  puVar21 = puVar22;
LAB_180036ce3:
  *(undefined8 *)(puVar21 + -8) = 0x180036cf2;
  return DVar6;
}

/* ---- FUNC 000317F0 thunk_FUN_180036200 (5 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */

DWORD thunk_FUN_180036200(longlong *param_1,undefined4 param_2,int param_3,undefined8 *param_4)

{
  char *pcVar1;
  WCHAR WVar2;
  HMODULE pHVar3;
  char cVar4;
  BOOL BVar5;
  DWORD DVar6;
  int iVar7;
  uint uVar8;
  longlong lVar9;
  ulonglong uVar10;
  undefined8 *puVar11;
  HMODULE pHVar12;
  longlong lVar13;
  int *piVar14;
  undefined8 *puVar15;
  WCHAR *pWVar16;
  WCHAR *pWVar17;
  undefined1 *puVar18;
  undefined1 *puVar19;
  ulonglong uVar20;
  LPCSTR pCVar21;
  undefined8 *puVar22;
  LPCWSTR pWVar23;
  LPCWSTR pWVar24;
  LPCSTR pCVar25;
  undefined1 auStack_a28 [64];
  undefined **ppuStack_9e8;
  void *pvStack_9e0;
  void *pvStack_9d8;
  int iStack_9d0;
  _RTL_CRITICAL_SECTION _Stack_9c8;
  char cStack_9a0;
  undefined4 uStack_998;
  CHAR CStack_988;
  char acStack_987 [271];
  WCHAR aWStack_878 [528];
  WCHAR aWStack_458 [520];
  ulonglong uStack_48;
  
  puVar18 = auStack_a28;
  uStack_48 = DAT_180077818 ^ (ulonglong)&ppuStack_9e8;
  ppuStack_9e8 = ATL::CRegObject::vftable;
  puVar15 = (undefined8 *)0x0;
  pvStack_9e0 = (void *)0x0;
  pvStack_9d8 = (void *)0x0;
  iStack_9d0 = 0;
  _Stack_9c8.DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
  _Stack_9c8.LockCount = 0;
  _Stack_9c8.RecursionCount = 0;
  _Stack_9c8.OwningThread = (HANDLE)0x0;
  _Stack_9c8.LockSemaphore = (HANDLE)0x0;
  _Stack_9c8.SpinCount = 0;
  cStack_9a0 = '\0';
  uStack_998 = param_2;
  BVar5 = InitializeCriticalSectionEx(&_Stack_9c8,0,0);
  if (BVar5 == 0) {
    DVar6 = GetLastError();
    if (0 < (int)DVar6) {
      DVar6 = DVar6 & 0xffff | 0x80070000;
    }
    if ((int)DVar6 < 0) {
      ppuStack_9e8 = ATL::CRegObject::vftable;
      EnterCriticalSection(&_Stack_9c8);
      puVar11 = puVar15;
      puVar22 = puVar15;
      if (0 < iStack_9d0) {
        do {
          if ((((longlong)puVar11 < 0) || (iVar7 = (int)puVar22, iStack_9d0 <= iVar7)) ||
             (operator_delete__(*(void **)((longlong)puVar11 + (longlong)pvStack_9e0)),
             iStack_9d0 <= iVar7)) {
                    /* WARNING: Subroutine does not return */
            FUN_180001a90(-0x7ffffff5);
          }
          operator_delete__(*(void **)((longlong)puVar11 + (longlong)pvStack_9d8));
          puVar11 = puVar11 + 1;
          puVar22 = (undefined8 *)(ulonglong)(iVar7 + 1U);
        } while ((int)(iVar7 + 1U) < iStack_9d0);
      }
      if (pvStack_9e0 != (void *)0x0) {
        free(pvStack_9e0);
        pvStack_9e0 = (void *)0x0;
      }
      if (pvStack_9d8 != (void *)0x0) {
        free(pvStack_9d8);
        pvStack_9d8 = (void *)0x0;
      }
      iStack_9d0 = 0;
      LeaveCriticalSection(&_Stack_9c8);
      if (cStack_9a0 != '\0') {
        cStack_9a0 = '\0';
        DeleteCriticalSection(&_Stack_9c8);
      }
      puVar11 = puVar15;
      if (0 < iStack_9d0) {
        do {
          if ((((longlong)puVar11 < 0) || (iVar7 = (int)puVar15, iStack_9d0 <= iVar7)) ||
             (operator_delete__(*(void **)((longlong)puVar11 + (longlong)pvStack_9e0)),
             iStack_9d0 <= iVar7)) {
                    /* WARNING: Subroutine does not return */
            FUN_180001a90(-0x7ffffff5);
          }
          operator_delete__(*(void **)((longlong)puVar11 + (longlong)pvStack_9d8));
          puVar15 = (undefined8 *)(ulonglong)(iVar7 + 1U);
          puVar11 = puVar11 + 1;
        } while ((int)(iVar7 + 1U) < iStack_9d0);
      }
      if (pvStack_9e0 != (void *)0x0) {
        free(pvStack_9e0);
        pvStack_9e0 = (void *)0x0;
      }
      if (pvStack_9d8 != (void *)0x0) {
        free(pvStack_9d8);
        pvStack_9d8 = (void *)0x0;
      }
      iStack_9d0 = 0;
      if (pvStack_9e0 != (void *)0x0) {
        free(pvStack_9e0);
        pvStack_9e0 = (void *)0x0;
      }
      puVar18 = auStack_a28;
      if (pvStack_9d8 != (void *)0x0) {
        free(pvStack_9d8);
        puVar18 = auStack_a28;
      }
      goto LAB_180036a82;
    }
  }
  cStack_9a0 = '\x01';
  if (param_4 != (undefined8 *)0x0) {
    pWVar23 = (LPCWSTR)*param_4;
    while (pWVar23 != (LPCWSTR)0x0) {
      FUN_180031840((longlong)&ppuStack_9e8,pWVar23,(void *)param_4[1]);
      param_4 = param_4 + 2;
      pWVar23 = (LPCWSTR)*param_4;
    }
  }
  DVar6 = (**(code **)(*param_1 + 0x28))(param_1,&ppuStack_9e8);
  pHVar3 = DAT_18007a618;
  if ((int)DVar6 < 0) {
    ppuStack_9e8 = ATL::CRegObject::vftable;
    EnterCriticalSection(&_Stack_9c8);
    puVar11 = puVar15;
    puVar22 = puVar15;
    if (0 < iStack_9d0) {
      do {
        if ((((longlong)puVar11 < 0) || (iVar7 = (int)puVar22, iStack_9d0 <= iVar7)) ||
           (operator_delete__(*(void **)((longlong)puVar11 + (longlong)pvStack_9e0)),
           iStack_9d0 <= iVar7)) {
                    /* WARNING: Subroutine does not return */
          FUN_180001a90(-0x7ffffff5);
        }
        operator_delete__(*(void **)((longlong)puVar11 + (longlong)pvStack_9d8));
        puVar11 = puVar11 + 1;
        puVar22 = (undefined8 *)(ulonglong)(iVar7 + 1U);
      } while ((int)(iVar7 + 1U) < iStack_9d0);
    }
    if (pvStack_9e0 != (void *)0x0) {
      free(pvStack_9e0);
      pvStack_9e0 = (void *)0x0;
    }
    if (pvStack_9d8 != (void *)0x0) {
      free(pvStack_9d8);
      pvStack_9d8 = (void *)0x0;
    }
    iStack_9d0 = 0;
    LeaveCriticalSection(&_Stack_9c8);
    if (cStack_9a0 != '\0') {
      cStack_9a0 = '\0';
      DeleteCriticalSection(&_Stack_9c8);
    }
    puVar11 = puVar15;
    if (0 < iStack_9d0) {
      do {
        if ((((longlong)puVar11 < 0) || (iVar7 = (int)puVar15, iStack_9d0 <= iVar7)) ||
           (operator_delete__(*(void **)((longlong)puVar11 + (longlong)pvStack_9e0)),
           iStack_9d0 <= iVar7)) {
                    /* WARNING: Subroutine does not return */
          FUN_180001a90(-0x7ffffff5);
        }
        operator_delete__(*(void **)((longlong)puVar11 + (longlong)pvStack_9d8));
        puVar15 = (undefined8 *)(ulonglong)(iVar7 + 1U);
        puVar11 = puVar11 + 1;
      } while ((int)(iVar7 + 1U) < iStack_9d0);
    }
    if (pvStack_9e0 != (void *)0x0) {
      free(pvStack_9e0);
      pvStack_9e0 = (void *)0x0;
    }
    if (pvStack_9d8 != (void *)0x0) {
      free(pvStack_9d8);
      pvStack_9d8 = (void *)0x0;
    }
    iStack_9d0 = 0;
    if (pvStack_9e0 != (void *)0x0) {
      free(pvStack_9e0);
      pvStack_9e0 = (void *)0x0;
    }
    puVar18 = auStack_a28;
    if (pvStack_9d8 != (void *)0x0) {
      free(pvStack_9d8);
      puVar18 = auStack_a28;
    }
    goto LAB_180036a82;
  }
  DVar6 = GetModuleFileNameA(DAT_18007a618,&CStack_988,0x104);
  if (DVar6 == 0) {
    DVar6 = FUN_1800333f0();
    FUN_180032790(&ppuStack_9e8);
    puVar18 = auStack_a28;
    goto LAB_180036a82;
  }
  if (DVar6 == 0x104) {
    FUN_180032790(&ppuStack_9e8);
    DVar6 = 0x8007007a;
    puVar18 = auStack_a28;
    goto LAB_180036a82;
  }
  lVar13 = -1;
  do {
    lVar9 = lVar13 + 1;
    pcVar1 = acStack_987 + lVar13;
    lVar13 = lVar9;
  } while (*pcVar1 != '\0');
  lVar13 = (longlong)((int)lVar9 + 1) * 2;
  puVar19 = auStack_a28;
  if (lVar13 + 0x80000000U < 0x100000000) {
    iVar7 = (int)lVar13;
    uVar20 = (ulonglong)iVar7;
    if ((iVar7 < 0x401) && (cVar4 = FUN_1800026d0(uVar20), cVar4 != '\0')) {
      uVar10 = uVar20 + 0xf;
      if (uVar10 <= uVar20) {
        uVar10 = 0xffffffffffffff0;
      }
      puVar18 = auStack_a28 + -(uVar10 & 0xfffffffffffffff0);
      pWVar23 = (LPCWSTR)((longlong)&ppuStack_9e8 + -(uVar10 & 0xfffffffffffffff0));
      puVar11 = puVar15;
    }
    else {
      if (~uVar20 < 0x10) {
                    /* WARNING: Subroutine does not return */
        FUN_180001a90(-0x7ff8fdea);
      }
      puVar11 = malloc(uVar20 + 0x10);
      puVar19 = auStack_a28;
      if (puVar11 == (undefined8 *)0x0) goto LAB_180036a74;
      *puVar11 = 0;
      pWVar23 = (LPCWSTR)(puVar11 + 2);
    }
    if (pWVar23 != (LPCWSTR)0x0) {
      *pWVar23 = L'\0';
      *(int *)(puVar18 + 0x28) = (int)(uVar20 >> 1);
      *(LPCWSTR *)(puVar18 + 0x20) = pWVar23;
      *(undefined8 *)(puVar18 + -8) = 0x1800366b2;
      iVar7 = MultiByteToWideChar(0,0,&CStack_988,-1,*(LPWSTR *)(puVar18 + 0x20),
                                  *(int *)(puVar18 + 0x28));
      if (iVar7 != 0) {
        pWVar16 = aWStack_458;
        pWVar24 = pWVar23;
        do {
          uVar8 = (uint)puVar15;
          WVar2 = *pWVar24;
          pWVar17 = pWVar16;
          if (WVar2 == L'\0') break;
          *pWVar16 = WVar2;
          pWVar17 = pWVar16 + 1;
          if ((WVar2 == L'\'') && (uVar8 = uVar8 + 1, uVar8 < 0x207)) {
            *pWVar17 = L'\'';
            pWVar17 = pWVar16 + 2;
          }
          pWVar24 = pWVar24 + 1;
          puVar15 = (undefined8 *)(ulonglong)(uVar8 + 1);
          pWVar16 = pWVar17;
        } while (uVar8 + 1 < 0x207);
        *pWVar17 = L'\0';
        if (pHVar3 == (HMODULE)0x0) {
LAB_180036720:
          aWStack_878[0] = L'\"';
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (aWStack_458[lVar13] != L'\0');
          uVar20 = (longlong)((int)lVar13 + 1) * 2;
          if (uVar20 != 0) {
            if (0x416 < uVar20) {
              *(undefined8 *)(puVar18 + -8) = 0x180036801;
              memset(aWStack_878 + 1,0,0x416);
              *(undefined8 *)(puVar18 + -8) = 0x180036807;
              piVar14 = _errno();
              *piVar14 = 0x22;
              *(undefined8 *)(puVar18 + -8) = 0x18003680f;
              _invalid_parameter_noinfo();
              while (puVar11 != (undefined8 *)0x0) {
                puVar15 = (undefined8 *)*puVar11;
                *(undefined8 *)(puVar18 + -8) = 0x180036820;
                free(puVar11);
                puVar11 = puVar15;
              }
              *(undefined8 *)(puVar18 + -8) = 0x18003682e;
              FUN_180032790(&ppuStack_9e8);
              DVar6 = 0x80004005;
              goto LAB_180036a82;
            }
            *(undefined8 *)(puVar18 + -8) = 0x180036769;
            memcpy(aWStack_878 + 1,aWStack_458,uVar20);
          }
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (aWStack_878[lVar13] != L'\0');
          lVar13 = (longlong)(int)lVar13;
          aWStack_878[lVar13] = L'\"';
          if (0x417 < lVar13 * 2 + 2U) {
                    /* WARNING: Subroutine does not return */
            *(undefined8 *)(puVar18 + -8) = 0x180036ab0;
            FUN_18005c254();
          }
          aWStack_878[lVar13 + 1] = 0;
          pWVar16 = aWStack_878;
        }
        else {
          *(undefined8 *)(puVar18 + -8) = 0x18003670f;
          pHVar12 = GetModuleHandleA((LPCSTR)0x0);
          if (pHVar3 == pHVar12) goto LAB_180036720;
          pWVar16 = aWStack_458;
        }
        *(undefined8 *)(puVar18 + -8) = 0x1800367c8;
        DVar6 = FUN_180031840((longlong)&ppuStack_9e8,L"Module",pWVar16);
        if ((int)DVar6 < 0) {
          while (puVar11 != (undefined8 *)0x0) {
            puVar15 = (undefined8 *)*puVar11;
            *(undefined8 *)(puVar18 + -8) = 0x1800367df;
            free(puVar11);
            puVar11 = puVar15;
          }
          *(undefined8 *)(puVar18 + -8) = 0x1800367ed;
          FUN_180032790(&ppuStack_9e8);
          goto LAB_180036a82;
        }
        *(undefined8 *)(puVar18 + -8) = 0x18003684f;
        DVar6 = FUN_180031840((longlong)&ppuStack_9e8,L"Module_Raw",aWStack_458);
        if ((int)DVar6 < 0) {
          while (puVar11 != (undefined8 *)0x0) {
            puVar15 = (undefined8 *)*puVar11;
            *(undefined8 *)(puVar18 + -8) = 0x18003686c;
            free(puVar11);
            puVar11 = puVar15;
          }
          *(undefined8 *)(puVar18 + -8) = 0x18003687a;
          FUN_180032790(&ppuStack_9e8);
          goto LAB_180036a82;
        }
        if (param_3 == 0) {
          puVar15 = (undefined8 *)0x0;
          *(undefined8 *)(puVar18 + -8) = 0x180036971;
          cVar4 = FUN_1800026d0(0x12);
          if (cVar4 == '\0') {
            *(undefined8 *)(puVar18 + -8) = 0x18003698e;
            puVar15 = malloc(0x22);
            if (puVar15 == (undefined8 *)0x0) goto LAB_180036a31;
            *puVar15 = 0;
            pCVar21 = (LPCSTR)(puVar15 + 2);
          }
          else {
            pCVar21 = puVar18 + 0x20;
            puVar18 = puVar18 + -0x20;
          }
          if (pCVar21 == (LPCSTR)0x0) {
joined_r0x000180036a16:
            while (puVar15 != (undefined8 *)0x0) {
              puVar22 = (undefined8 *)*puVar15;
              *(undefined8 *)(puVar18 + -8) = 0x180036a2c;
              free(puVar15);
              puVar15 = puVar22;
            }
            goto LAB_180036a31;
          }
          *pCVar21 = '\0';
          *(undefined8 *)(puVar18 + 0x38) = 0;
          *(undefined8 *)(puVar18 + 0x30) = 0;
          *(undefined4 *)(puVar18 + 0x28) = 0x12;
          *(LPCSTR *)(puVar18 + 0x20) = pCVar21;
          *(undefined8 *)(puVar18 + -8) = 0x1800369d7;
          iVar7 = WideCharToMultiByte(0,0,L"REGISTRY",-1,*(LPSTR *)(puVar18 + 0x20),
                                      *(int *)(puVar18 + 0x28),*(LPCSTR *)(puVar18 + 0x30),
                                      *(LPBOOL *)(puVar18 + 0x38));
          if (iVar7 == 0) goto joined_r0x000180036a16;
          pCVar25 = (LPCSTR)(ulonglong)(ushort)uStack_998;
          *(undefined4 *)(puVar18 + 0x20) = 0;
          *(undefined8 *)(puVar18 + -8) = 0x1800369f4;
          DVar6 = FUN_180034920(&ppuStack_9e8,pWVar23,pCVar25,pCVar21,*(int *)(puVar18 + 0x20));
          while (puVar15 != (undefined8 *)0x0) {
            puVar22 = (undefined8 *)*puVar15;
            *(undefined8 *)(puVar18 + -8) = 0x180036a0c;
            free(puVar15);
            puVar15 = puVar22;
          }
        }
        else {
          puVar15 = (undefined8 *)0x0;
          *(undefined8 *)(puVar18 + -8) = 0x18003689a;
          cVar4 = FUN_1800026d0(0x12);
          if (cVar4 == '\0') {
            *(undefined8 *)(puVar18 + -8) = 0x1800368b7;
            puVar15 = malloc(0x22);
            if (puVar15 == (undefined8 *)0x0) goto LAB_180036a31;
            *puVar15 = 0;
            pCVar21 = (LPCSTR)(puVar15 + 2);
          }
          else {
            pCVar21 = puVar18 + 0x20;
            puVar18 = puVar18 + -0x20;
          }
          if (pCVar21 != (LPCSTR)0x0) {
            *pCVar21 = '\0';
            *(undefined8 *)(puVar18 + 0x38) = 0;
            *(undefined8 *)(puVar18 + 0x30) = 0;
            *(undefined4 *)(puVar18 + 0x28) = 0x12;
            *(LPCSTR *)(puVar18 + 0x20) = pCVar21;
            *(undefined8 *)(puVar18 + -8) = 0x180036900;
            iVar7 = WideCharToMultiByte(0,0,L"REGISTRY",-1,*(LPSTR *)(puVar18 + 0x20),
                                        *(int *)(puVar18 + 0x28),*(LPCSTR *)(puVar18 + 0x30),
                                        *(LPBOOL *)(puVar18 + 0x38));
            if (iVar7 != 0) {
              pCVar25 = (LPCSTR)(ulonglong)(ushort)uStack_998;
              *(undefined4 *)(puVar18 + 0x20) = 1;
              *(undefined8 *)(puVar18 + -8) = 0x180036920;
              DVar6 = FUN_180034920(&ppuStack_9e8,pWVar23,pCVar25,pCVar21,*(int *)(puVar18 + 0x20));
              while (puVar15 != (undefined8 *)0x0) {
                puVar22 = (undefined8 *)*puVar15;
                *(undefined8 *)(puVar18 + -8) = 0x18003693c;
                free(puVar15);
                puVar15 = puVar22;
              }
              goto joined_r0x000180036a39;
            }
          }
          while (puVar15 != (undefined8 *)0x0) {
            puVar22 = (undefined8 *)*puVar15;
            *(undefined8 *)(puVar18 + -8) = 0x18003695c;
            free(puVar15);
            puVar15 = puVar22;
          }
LAB_180036a31:
          DVar6 = 0x8007000e;
        }
joined_r0x000180036a39:
        while (puVar11 != (undefined8 *)0x0) {
          puVar15 = (undefined8 *)*puVar11;
          *(undefined8 *)((longlong)puVar18 + -8) = 0x180036a4c;
          free(puVar11);
          puVar11 = puVar15;
        }
        *(undefined8 *)((longlong)puVar18 + -8) = 0x180036a5a;
        FUN_180032790(&ppuStack_9e8);
        goto LAB_180036a82;
      }
    }
    while (puVar19 = puVar18, puVar11 != (undefined8 *)0x0) {
      puVar15 = (undefined8 *)*puVar11;
      *(undefined8 *)(puVar18 + -8) = 0x180036a6f;
      free(puVar11);
      puVar11 = puVar15;
    }
  }
LAB_180036a74:
  *(undefined8 *)(puVar19 + -8) = 0x180036a7d;
  FUN_180032790(&ppuStack_9e8);
  DVar6 = 0x8007000e;
  puVar18 = puVar19;
LAB_180036a82:
  *(undefined8 *)(puVar18 + -8) = 0x180036a91;
  return DVar6;
}

/* ---- FUNC 00031800 FUN_180031800 (62 bytes) ---- */

undefined8 * FUN_180031800(undefined8 *param_1,uint param_2)

{
  *param_1 = ATL::CComModule::vftable;
  FUN_180036140((longlong)param_1);
  if ((param_2 & 1) != 0) {
    FUN_180025ad0(param_1);
  }
  return param_1;
}

/* ---- FUNC 00031840 FUN_180031840 (746 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_180031840(longlong param_1,LPCWSTR param_2,void *param_3)

{
  undefined1 auVar1 [16];
  char cVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  __uint64 _Var7;
  undefined8 *puVar8;
  void *pvVar9;
  undefined8 *puVar10;
  undefined8 *_Memory;
  undefined1 *puVar11;
  undefined1 *puVar12;
  ulonglong uVar13;
  uint uVar14;
  longlong lVar15;
  __uint64 _Size;
  int iVar16;
  undefined8 *puVar17;
  undefined1 auStack_98 [64];
  void *local_58 [2];
  ulonglong local_48;
  undefined8 *local_40;
  ulonglong local_30;
  
  puVar12 = auStack_98;
  puVar11 = auStack_98;
  local_30 = DAT_180077818 ^ (ulonglong)local_58;
  if ((param_2 == (LPCWSTR)0x0) || (param_3 == (void *)0x0)) {
    uVar14 = 0x80070057;
    goto LAB_180031afa;
  }
  local_58[0] = param_3;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  puVar17 = (undefined8 *)0x0;
  iVar16 = 0;
  local_58[1] = (undefined8 *)0x0;
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (param_2[lVar4] != L'\0');
  lVar4 = (longlong)((int)lVar4 + 1) * 2;
  _Memory = puVar17;
  puVar12 = auStack_98;
  puVar10 = puVar17;
  if (lVar4 + 0x80000000U < 0x100000000) {
    iVar3 = (int)lVar4;
    uVar13 = (ulonglong)iVar3;
    if ((iVar3 < 0x401) && (cVar2 = FUN_1800026d0(uVar13), cVar2 != '\0')) {
      uVar5 = uVar13 + 0xf;
      if (uVar5 <= uVar13) {
        uVar5 = 0xffffffffffffff0;
      }
      puVar11 = auStack_98 + -(uVar5 & 0xfffffffffffffff0);
      puVar8 = (undefined8 *)((longlong)local_58 + -(uVar5 & 0xfffffffffffffff0));
      puVar6 = puVar17;
    }
    else {
      if (~uVar13 < 0x10) {
                    /* WARNING: Subroutine does not return */
        FUN_180001a90(-0x7ff8fdea);
      }
      puVar6 = malloc(uVar13 + 0x10);
      puVar12 = auStack_98;
      if (puVar6 == (undefined8 *)0x0) goto LAB_18003198e;
      *puVar6 = 0;
      local_58[1] = puVar6;
      puVar8 = puVar6 + 2;
    }
    _Memory = puVar6;
    puVar12 = puVar11;
    if (puVar8 != (undefined8 *)0x0) {
      *(undefined1 *)puVar8 = 0;
      *(undefined8 *)(puVar11 + 0x38) = 0;
      *(undefined8 *)(puVar11 + 0x30) = 0;
      *(int *)(puVar11 + 0x28) = iVar3;
      *(undefined8 **)(puVar11 + 0x20) = puVar8;
      *(undefined8 *)(puVar11 + -8) = 0x180031975;
      iVar3 = WideCharToMultiByte(0,0,param_2,-1,*(LPSTR *)(puVar11 + 0x20),*(int *)(puVar11 + 0x28)
                                  ,*(LPCSTR *)(puVar11 + 0x30),*(LPBOOL *)(puVar11 + 0x38));
      puVar10 = puVar8;
      if (iVar3 == 0) {
        puVar10 = puVar17;
      }
    }
  }
LAB_18003198e:
  if (puVar10 == (undefined8 *)0x0) {
    uVar14 = 0x8007000e;
  }
  else {
    lVar4 = -1;
    do {
      lVar15 = lVar4;
      lVar4 = lVar15 + 1;
    } while (*(char *)((longlong)puVar10 + lVar4) != '\0');
    _Size = lVar15 + 2;
    *(undefined8 *)(puVar12 + -8) = 0x1800319b5;
    puVar6 = operator_new__(_Size);
    lVar4 = -1;
    do {
      lVar4 = lVar4 + 1;
    } while (*(short *)((longlong)local_58[0] + lVar4 * 2) != 0);
    local_48 = (longlong)((int)lVar4 + 1) * 2;
    auVar1._8_8_ = 0;
    auVar1._0_8_ = local_48;
    _Var7 = SUB168(ZEXT816(2) * auVar1,0);
    if (SUB168(ZEXT816(2) * auVar1,8) != 0) {
      _Var7 = 0xffffffffffffffff;
    }
    local_40 = puVar6;
    *(undefined8 *)(puVar12 + -8) = 0x1800319fa;
    puVar8 = operator_new__(_Var7);
    if ((puVar6 == (undefined8 *)0x0) || (puVar8 == (undefined8 *)0x0)) {
LAB_180031aab:
      iVar16 = -0x7ff8fff2;
    }
    else {
      if (_Size != 0) {
        *(undefined8 *)(puVar12 + -8) = 0x180031a22;
        memcpy(puVar6,puVar10,_Size);
      }
      uVar13 = local_48;
      pvVar9 = local_58[0];
      if (local_48 != 0) {
        *(undefined8 *)(puVar12 + -8) = 0x180031a37;
        memcpy(puVar8,pvVar9,uVar13);
      }
      iVar3 = *(int *)(param_1 + 0x18);
      pvVar9 = *(void **)(param_1 + 8);
      *(undefined8 *)(puVar12 + -8) = 0x180031a50;
      pvVar9 = _recalloc(pvVar9,(longlong)(iVar3 + 1),8);
      if (pvVar9 == (void *)0x0) goto LAB_180031aab;
      *(void **)(param_1 + 8) = pvVar9;
      iVar3 = *(int *)(param_1 + 0x18);
      pvVar9 = *(void **)(param_1 + 0x10);
      *(undefined8 *)(puVar12 + -8) = 0x180031a72;
      pvVar9 = _recalloc(pvVar9,(longlong)(iVar3 + 1),8);
      if (pvVar9 == (void *)0x0) goto LAB_180031aab;
      *(void **)(param_1 + 0x10) = pvVar9;
      lVar4 = (longlong)*(int *)(param_1 + 0x18) * 8;
      puVar10 = (undefined8 *)(*(longlong *)(param_1 + 8) + lVar4);
      if (puVar10 != (undefined8 *)0x0) {
        *puVar10 = puVar6;
      }
      puVar10 = (undefined8 *)(*(longlong *)(param_1 + 0x10) + lVar4);
      if (puVar10 != (undefined8 *)0x0) {
        *puVar10 = puVar8;
      }
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
      puVar6 = puVar17;
      puVar8 = puVar17;
    }
    *(undefined8 *)(puVar12 + -8) = 0x180031ab9;
    operator_delete__(puVar8);
    *(undefined8 *)(puVar12 + -8) = 0x180031ac2;
    operator_delete__(puVar6);
    *(undefined8 *)(puVar12 + -8) = 0x180031acc;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
    uVar14 = iVar16 >> 0x1f & 0x8007000e;
  }
  while (_Memory != (undefined8 *)0x0) {
    puVar17 = (undefined8 *)*_Memory;
    *(undefined8 *)(puVar12 + -8) = 0x180031aec;
    free(_Memory);
    _Memory = puVar17;
  }
LAB_180031afa:
  *(undefined8 *)(puVar12 + -8) = 0x180031b06;
  return uVar14;
}

/* ---- FUNC 00031B30 FUN_180031b30 (59 bytes) ---- */

ulonglong FUN_180031b30(longlong param_1)

{
  ulonglong uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  uVar1 = FUN_180033560((longlong *)(param_1 + 8));
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return uVar1 & 0xffffffff;
}

/* ---- FUNC 00031B70 FUN_180031b70 (52 bytes) ---- */

undefined8 * FUN_180031b70(undefined8 *param_1,uint param_2)

{
  FUN_180032790(param_1);
  if ((param_2 & 1) != 0) {
    FUN_180025ad0(param_1);
  }
  return param_1;
}

/* ---- FUNC 00031BB0 HappNotifyThread (935 bytes) ---- */

void HappNotifyThread(undefined2 param_1,LPUNKNOWN param_2)

{
  char *pcVar1;
  IUnknownVtbl *pIVar2;
  int iVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar4;
  undefined8 uVar5;
  IAtlStringMgr *pIVar6;
  longlong lVar7;
  longlong *plVar9;
  undefined4 uVar10;
  _func_5158 **pp_Var11;
  char *local_res10;
  char *local_res18;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res20 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_38 [8];
  void *local_30 [2];
  longlong lVar8;
  
                    /* 0x31bb0  52  HappNotifyThread */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20,"");
  local_30[0] = (void *)0x0;
  switch(param_1) {
  case 0:
  case 6:
  case 7:
    if (param_2 != (LPUNKNOWN)0x0) {
      pIVar2 = param_2[0xc].lpVtbl;
      if ((pIVar2 == (IUnknownVtbl *)0x0) || (*(int *)&param_2[0xd].lpVtbl != 0)) {
        (*param_2->lpVtbl->AddRef)(param_2);
        FUN_18003b570(param_2);
        (*param_2->lpVtbl->Release)(param_2);
      }
      else {
        (*param_2->lpVtbl->AddRef)(param_2);
        FUN_18003b570(param_2);
        pp_Var11 = &pIVar2[0x13].Release;
        iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)pp_Var11
                           ,"Blocks");
        if (iVar3 != 0) {
          pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                   ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                   CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                             ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                              &local_res10,
                              (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                               *)pp_Var11);
          uVar5 = FUN_180033a50(pCVar4);
          if ((int)uVar5 != 1) {
            iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                    CompareNoCase((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                  pp_Var11,"Streams");
            if (iVar3 == 0) {
              FUN_1800374c0(0x69,(longlong *)(param_2 + 0x3b));
              (*param_2->lpVtbl->Release)(param_2);
            }
            else {
              FUN_1800374c0(0x7a,(longlong *)(param_2 + 0x3b));
              (*param_2->lpVtbl->Release)(param_2);
            }
            break;
          }
        }
        FUN_1800374c0(0x68,(longlong *)(param_2 + 0x3b));
        (*param_2->lpVtbl->Release)(param_2);
      }
    }
    break;
  case 1:
    if (param_2 != (LPUNKNOWN)0x0) {
      if (DAT_18007988c != 0) break;
      (*param_2->lpVtbl->AddRef)(param_2);
    }
  case 0xf:
  case 0x22:
switchD_180031bff_caseD_f:
    if (DAT_180079800 != (longlong *)0x0) {
      (**(code **)(*DAT_180079800 + 0xd8))(DAT_180079800,param_1,param_2);
    }
    break;
  case 2:
    if (DAT_18007988c != 0) {
      DAT_180079894 = 1;
      break;
    }
    uVar10 = 0x66;
    goto LAB_180031f3a;
  case 3:
  case 8:
  case 0x10:
  case 0x11:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x20:
    if (param_2 != (LPUNKNOWN)0x0) {
      (*param_2->lpVtbl->AddRef)(param_2);
    }
    goto switchD_180031bff_caseD_f;
  case 9:
    if ((param_2[0xc].lpVtbl == (IUnknownVtbl *)0x0) || (*(int *)&param_2[0xd].lpVtbl != 0)) break;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               (param_2 + 0x3b));
    FUN_18003b5b0((longlong)param_2);
    pp_Var11 = &param_2[0xc].lpVtbl[0x13].Release;
    iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)pp_Var11,
                       "Blocks");
    if (iVar3 == 0) {
LAB_180031d37:
      pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
               CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          &local_res18,
                          (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                           *)pp_Var11);
      uVar5 = FUN_180033a50(pCVar4);
      if ((int)uVar5 == 1) {
        pIVar6 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                           ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            pp_Var11);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18,
                   pIVar6);
        lVar8 = -1;
        do {
          lVar7 = lVar8 + 1;
          pcVar1 = &DAT_180064d6d + lVar8;
          lVar8 = lVar7;
        } while (*pcVar1 != '\0');
        ATL::CSimpleStringT<char,1>::Concatenate
                  ((CSimpleStringT<char,1> *)&local_res18,(char *)*pp_Var11,
                   *(int *)(*pp_Var11 + -0x10),"-",(int)lVar7);
        pIVar6 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                           ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_res18);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_38,pIVar6);
        ATL::CSimpleStringT<char,1>::Concatenate
                  ((CSimpleStringT<char,1> *)local_38,local_res18,*(int *)(local_res18 + -0x10),
                   local_res10,*(int *)(local_res10 + -0x10));
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   local_38);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_38);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18);
      }
      uVar10 = 0x6a;
LAB_180031e05:
      FUN_1800374c0(uVar10,(longlong *)&local_res10);
    }
    else {
      pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
               CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          &local_res18,
                          (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                           *)pp_Var11);
      uVar5 = FUN_180033a50(pCVar4);
      if ((int)uVar5 == 1) goto LAB_180031d37;
      iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)pp_Var11,
                         "Streams");
      if (iVar3 == 0) {
        uVar10 = 0x6b;
        goto LAB_180031e05;
      }
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10);
    break;
  case 0xc:
    plVar9 = (longlong *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                       ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                        &local_res10,"");
    FUN_1800374c0(0x70,plVar9);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10);
    break;
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x1c:
  case 0x1e:
  case 0x1f:
  case 0x21:
    (*param_2->lpVtbl->QueryInterface)(param_2,(IID *)&DAT_180063610,local_30);
    if (DAT_180079800 != (longlong *)0x0) {
      (**(code **)(*DAT_180079800 + 0xd8))(DAT_180079800,param_1,local_30[0]);
    }
    break;
  case 0x1d:
    uVar10 = 0x75;
    goto LAB_180031f3a;
  case 0x23:
    uVar10 = 0x7a;
LAB_180031f3a:
    FUN_1800374c0(uVar10,(longlong *)local_res20);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20);
  return;
}

/* ---- FUNC 00031FB0 FUN_180031fb0 (351 bytes) ---- */

DWORD FUN_180031fb0(longlong param_1,int *param_2,undefined8 *param_3)

{
  code *pcVar1;
  BOOL BVar2;
  DWORD DVar3;
  longlong *plVar4;
  undefined8 uVar5;
  DWORD DVar6;
  longlong *plVar7;
  
  if (param_3 == (undefined8 *)0x0) {
    return 0x80004003;
  }
  *param_3 = 0;
  DVar6 = 0x8007000e;
  plVar4 = operator_new(0x48);
  if (plVar4 != (longlong *)0x0) {
    *(undefined4 *)(plVar4 + 1) = 0;
    plVar4[2] = 0;
    plVar4[3] = 0;
    plVar4[4] = 0;
    plVar4[5] = 0;
    plVar4[6] = 0;
    *(undefined1 *)(plVar4 + 7) = 0;
    *plVar4 = (longlong)ATL::CComObjectCached<ATL::CComClassFactory>::vftable;
    plVar4[8] = param_1;
    DVar6 = 0;
    plVar7 = plVar4;
    BVar2 = InitializeCriticalSectionEx((LPCRITICAL_SECTION)(plVar4 + 2),0,0);
    if ((BVar2 == 0) && (DVar6 = GetLastError(), 0 < (int)DVar6)) {
      DVar6 = DVar6 & 0xffff | 0x80070000;
    }
    if (-1 < (int)DVar6) {
      *(undefined1 *)(plVar4 + 7) = 1;
    }
    DVar3 = 0;
    if ((int)DVar6 < 0) {
      DVar3 = DVar6;
    }
    DVar6 = 0;
    if ((int)DVar3 < 0) {
      DVar6 = DVar3;
    }
    if (DVar6 == 0) {
      pcVar1 = *(code **)*plVar4;
      if (pcVar1 == FUN_180032310) {
        uVar5 = FUN_180033420((longlong)plVar4,0x1800655e8,param_2,param_3);
        DVar6 = (DWORD)uVar5;
      }
      else {
        DVar6 = (*pcVar1)(plVar4,param_2,param_3,pcVar1,plVar7);
      }
      if (DVar6 == 0) {
        return 0;
      }
    }
    (**(code **)(*plVar4 + 0x28))(plVar4,1);
  }
  return DVar6;
}

/* ---- FUNC 00032120 FUN_180032120 (228 bytes) ---- */

ulonglong FUN_180032120(longlong *param_1,undefined8 param_2,byte *param_3,undefined8 *param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong *plVar5;
  longlong *local_res8;
  AFX_EXCEPTION_LINK local_30 [24];
  
  bVar1 = false;
  *param_4 = 0;
  local_res8 = param_1;
  if (param_1 == (longlong *)0x0) {
    bVar1 = true;
    iVar2 = (**(code **)(*DAT_1800797f0 + 0x90))(DAT_1800797f0,&local_res8);
    if (iVar2 < 0) {
      return 0x80004005;
    }
  }
  plVar5 = local_res8;
  if (param_3 == (byte *)0x0) {
    uVar4 = (**(code **)*local_res8)(local_res8,param_2,param_4);
  }
  else {
    AFX_EXCEPTION_LINK::AFX_EXCEPTION_LINK(local_30);
    plVar5 = FUN_180038fc0(plVar5,param_3);
    AfxTryCleanup();
    if (bVar1) {
      (**(code **)(*local_res8 + 0x10))();
    }
    if (plVar5 == (longlong *)0x0) {
      uVar4 = 0x80004002;
    }
    else {
      uVar3 = (**(code **)*plVar5)(plVar5,param_2,param_4);
      uVar4 = (ulonglong)uVar3;
      (**(code **)(*plVar5 + 0x10))(plVar5);
    }
  }
  return uVar4;
}

/* ---- FUNC 00032290 FUN_180032290 (44 bytes) ---- */

int FUN_180032290(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 8);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if (iVar2 + 1 == 2) {
    (**(code **)(*DAT_180079320 + 8))();
  }
  return iVar2 + 1;
}

/* ---- FUNC 000322C0 FUN_1800322c0 (70 bytes) ---- */

int FUN_1800322c0(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  
  LOCK();
  plVar1 = param_1 + 1;
  lVar2 = *plVar1;
  *(int *)plVar1 = (int)*plVar1 + -1;
  UNLOCK();
  iVar3 = (int)lVar2 + -1;
  if (iVar3 == 0) {
    if (param_1 != (longlong *)0x0) {
      (**(code **)(*param_1 + 0x28))(param_1,(int)lVar2);
      return 0;
    }
  }
  else if (iVar3 == 1) {
    (**(code **)(*DAT_180079320 + 0x10))();
  }
  return iVar3;
}

/* ---- FUNC 00032310 FUN_180032310 (118 bytes) ---- */

undefined8 FUN_180032310(longlong *param_1,int *param_2,undefined8 *param_3)

{
  int *piVar1;
  undefined8 uVar2;
  longlong *plVar3;
  
  if (param_1 == (longlong *)0x0) {
    return 0x80070057;
  }
  if (param_3 == (undefined8 *)0x0) {
    return 0x80004003;
  }
  if ((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) && (param_2[3] == 0x46000000)
     ) {
    (**(code **)(*param_1 + 8))();
    *param_3 = param_1;
    return 0;
  }
  plVar3 = &DAT_1800655f8;
  do {
    piVar1 = (int *)plVar3[-2];
    if ((piVar1 == (int *)0x0) ||
       (((*piVar1 == *param_2 && (piVar1[1] == param_2[1])) &&
        ((piVar1[2] == param_2[2] && (piVar1[3] == param_2[3])))))) {
      if ((code *)*plVar3 == (code *)0x1) {
        plVar3 = (longlong *)(plVar3[-1] + (longlong)param_1);
        (**(code **)(*plVar3 + 8))(plVar3);
        *param_3 = plVar3;
        return 0;
      }
      uVar2 = (*(code *)*plVar3)(param_1,param_2,param_3,plVar3[-1]);
      if ((int)uVar2 == 0) {
        return 0;
      }
      if ((piVar1 != (int *)0x0) && ((int)uVar2 < 0)) goto LAB_1800323f2;
    }
    plVar3 = plVar3 + 3;
  } while (*plVar3 != 0);
  uVar2 = 0x80004002;
LAB_1800323f2:
  *param_3 = 0;
  return uVar2;
}

/* ---- FUNC 00032386 FUN_180032386 (142 bytes) ---- */

undefined8 FUN_180032386(void)

{
  int *piVar1;
  undefined8 uVar2;
  int *unaff_RSI;
  longlong *plVar3;
  longlong unaff_R14;
  undefined8 *unaff_R15;
  
  plVar3 = &DAT_1800655f8;
  do {
    piVar1 = (int *)plVar3[-2];
    if ((piVar1 == (int *)0x0) ||
       ((((*piVar1 == *unaff_RSI && (piVar1[1] == unaff_RSI[1])) && (piVar1[2] == unaff_RSI[2])) &&
        (piVar1[3] == unaff_RSI[3])))) {
      if ((code *)*plVar3 == (code *)0x1) {
        plVar3 = (longlong *)(plVar3[-1] + unaff_R14);
        (**(code **)(*plVar3 + 8))(plVar3);
        *unaff_R15 = plVar3;
        return 0;
      }
      uVar2 = (*(code *)*plVar3)();
      if ((int)uVar2 == 0) {
        return 0;
      }
      if ((piVar1 != (int *)0x0) && ((int)uVar2 < 0)) goto LAB_1800323f2;
    }
    plVar3 = plVar3 + 3;
  } while (*plVar3 != 0);
  uVar2 = 0x80004002;
LAB_1800323f2:
  *unaff_R15 = 0;
  return uVar2;
}

/* ---- FUNC 00032414 FUN_180032414 (23 bytes) ---- */

undefined8 FUN_180032414(void)

{
  longlong *plVar1;
  longlong unaff_RDI;
  longlong unaff_R14;
  undefined8 *unaff_R15;
  
  plVar1 = (longlong *)(*(longlong *)(unaff_RDI + -8) + unaff_R14);
  (**(code **)(*plVar1 + 8))(plVar1);
  *unaff_R15 = plVar1;
  return 0;
}

/* ---- FUNC 0003242B FUN_18003242b (22 bytes) ---- */

undefined8 FUN_18003242b(void)

{
  return 0x80070057;
}

/* ---- FUNC 00032450 FUN_180032450 (85 bytes) ---- */

undefined8 * FUN_180032450(undefined8 *param_1,ulonglong param_2)

{
  *(undefined4 *)(param_1 + 1) = 0xc0000001;
  *param_1 = ATL::CComClassFactory::vftable;
  if (*(char *)(param_1 + 7) != '\0') {
    *(undefined1 *)(param_1 + 7) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  }
  if ((param_2 & 1) != 0) {
    FUN_180025ad0(param_1);
  }
  return param_1;
}

/* ---- FUNC 000324B0 FUN_1800324b0 (83 bytes) ---- */

undefined4 FUN_1800324b0(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  
  plVar1 = param_1 + 1;
  *(int *)plVar1 = (int)*plVar1 + -1;
  lVar2 = param_1[1];
  if ((int)*plVar1 == 0) {
    (**(code **)(*DAT_180079320 + 8))();
    if (param_1 != (longlong *)0x0) {
      (**(code **)(*param_1 + 0x18))(param_1,1);
    }
    (**(code **)(*DAT_180079320 + 0x10))();
  }
  return (int)lVar2;
}

/* ---- FUNC 00032510 FUN_180032510 (19 bytes) ---- */

undefined8 FUN_180032510(longlong *param_1,int *param_2,longlong *param_3)

{
  undefined8 uVar1;
  
  if (param_3 == (longlong *)0x0) {
    return 0x80004003;
  }
  *param_3 = 0;
  if ((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) && (param_2[3] == 0x46000000)
     ) {
    *param_3 = (longlong)param_1;
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  uVar1 = FUN_1800196b0((longlong)(param_1 + 2),param_2,param_3);
  return uVar1;
}

/* ---- FUNC 00032523 FUN_180032523 (58 bytes) ---- */

undefined8 FUN_180032523(longlong *param_1,int *param_2,longlong *param_3)

{
  undefined8 uVar1;
  
  *param_3 = 0;
  if ((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) && (param_2[3] == 0x46000000)
     ) {
    *param_3 = (longlong)param_1;
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  uVar1 = FUN_1800196b0((longlong)(param_1 + 2),param_2,param_3);
  return uVar1;
}

/* ---- FUNC 0003255D FUN_18003255d (18 bytes) ---- */

void FUN_18003255d(longlong param_1,int *param_2,longlong *param_3)

{
  FUN_1800196b0(param_1 + 0x10,param_2,param_3);
  return;
}

/* ---- FUNC 00032570 FUN_180032570 (11 bytes) ---- */

void FUN_180032570(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180032577. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(longlong **)(param_1 + 0x18) + 8))();
  return;
}

/* ---- FUNC 00032580 FUN_180032580 (11 bytes) ---- */

void FUN_180032580(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180032587. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(longlong **)(param_1 + 0x18) + 0x10))();
  return;
}

/* ---- FUNC 00032590 FUN_180032590 (10 bytes) ---- */

void FUN_180032590(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180032597. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)**(undefined8 **)(param_1 + 0x18))();
  return;
}

/* ---- FUNC 000325A0 FUN_1800325a0 (103 bytes) ---- */

undefined8 * FUN_1800325a0(undefined8 *param_1,uint param_2)

{
  *param_1 = ATL::CComAggObject<CHNodeSelection>::vftable;
  *(undefined4 *)(param_1 + 1) = 0xc0000001;
  FUN_18002e4b0();
  (**(code **)(*DAT_180079320 + 0x10))();
  if ((longlong *)param_1[6] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[6] + 0x10))();
  }
  if ((param_2 & 1) != 0) {
    FUN_180025ad0(param_1);
  }
  return param_1;
}

/* ---- FUNC 00032610 FUN_180032610 (84 bytes) ---- */

undefined8 FUN_180032610(longlong param_1,longlong param_2,int *param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  
  if (param_4 == (undefined8 *)0x0) {
    return 0x80004003;
  }
  *param_4 = 0;
  if ((param_2 != 0) &&
     ((((*param_3 != 0 || (param_3[1] != 0)) || (param_3[2] != 0xc0)) || (param_3[3] != 0x46000000))
     )) {
    return 0x80040110;
  }
                    /* WARNING: Could not recover jumptable at 0x00018003265a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(param_1 + 0x40))(param_2,param_3,param_4);
  return uVar1;
}

/* ---- FUNC 00032670 FUN_180032670 (38 bytes) ---- */

undefined8 FUN_180032670(undefined8 param_1,int param_2)

{
  if (param_2 != 0) {
    (**(code **)(*DAT_180079320 + 8))();
    return 0;
  }
  (**(code **)(*DAT_180079320 + 0x10))();
  return 0;
}

/* ---- FUNC 000326A0 FUN_1800326a0 (78 bytes) ---- */

undefined8 * FUN_1800326a0(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = ATL::CComClassFactory::vftable;
  if (*(char *)(param_1 + 7) != '\0') {
    *(undefined1 *)(param_1 + 7) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  }
  if ((param_2 & 1) != 0) {
    FUN_180025ad0(param_1);
  }
  return param_1;
}

/* ---- FUNC 000326F0 FUN_1800326f0 (9 bytes) ---- */

void FUN_1800326f0(longlong param_1)

{
  FUN_180032590(param_1 + -0x10);
  return;
}

/* ---- FUNC 000326FC FUN_1800326fc (9 bytes) ---- */

void FUN_1800326fc(longlong param_1)

{
  FUN_180032570(param_1 + -0x10);
  return;
}

/* ---- FUNC 00032708 FUN_180032708 (9 bytes) ---- */

void FUN_180032708(longlong param_1)

{
  FUN_180032580(param_1 + -0x10);
  return;
}

/* ---- FUNC 00032720 FUN_180032720 (30 bytes) ---- */

void FUN_180032720(undefined8 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}

/* ---- FUNC 00032760 FUN_180032760 (48 bytes) ---- */

void FUN_180032760(undefined8 *param_1)

{
  if ((HKEY)*param_1 != (HKEY)0x0) {
    RegCloseKey((HKEY)*param_1);
    *param_1 = 0;
    *(undefined4 *)(param_1 + 1) = 0;
    return;
  }
  *(undefined4 *)(param_1 + 1) = 0;
  return;
}

/* ---- FUNC 00032790 FUN_180032790 (136 bytes) ---- */

void FUN_180032790(undefined8 *param_1)

{
  *param_1 = ATL::CRegObject::vftable;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  FUN_180033560(param_1 + 1);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  if (*(char *)(param_1 + 9) != '\0') {
    *(undefined1 *)(param_1 + 9) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  }
  FUN_180033560(param_1 + 1);
  if ((void *)param_1[1] != (void *)0x0) {
    free((void *)param_1[1]);
    param_1[1] = 0;
  }
  if ((void *)param_1[2] != (void *)0x0) {
    free((void *)param_1[2]);
    param_1[2] = 0;
  }
  *(undefined4 *)(param_1 + 3) = 0;
  return;
}

/* ---- FUNC 00032820 APExitInstance (49 bytes) ---- */

void APExitInstance(void)

{
                    /* 0x32820  35  APExitInstance */
  DAT_180079800 = 0;
  if (DAT_1800797e8 != (HANDLE)0x0) {
    CloseHandle(DAT_1800797e8);
    DAT_1800797e8 = (HANDLE)0x0;
  }
  return;
}

/* ---- FUNC 00032860 APInitApplication (244 bytes) ---- */

undefined8 APInitApplication(HINSTANCE param_1)

{
  ATOM AVar1;
  HWND pHVar2;
  WNDCLASSA local_a8;
  undefined1 local_58 [80];
  
                    /* 0x32860  19  APInitApplication */
  local_a8.style = 3;
  local_a8.cbClsExtra = 0;
  local_a8.cbWndExtra = 0;
  local_a8.hIcon = (HICON)0x0;
  local_a8.hInstance = param_1;
  local_a8.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_a8.hbrBackground = (HBRUSH)0x6;
  local_a8.lpszClassName = "VarExplClass";
  local_a8.lpszMenuName = "WIN95";
  AVar1 = RegisterClassA(&local_a8);
  if ((AVar1 != 0) &&
     (pHVar2 = CreateWindowExA(0,"VarExplClass","main window",0xcf0000,-0x80000000,0,-0x80000000,0,
                               (HWND)0x0,(HMENU)0x0,param_1,local_58), pHVar2 != (HWND)0x0)) {
    DAT_1800797e0 = pHVar2;
    return 1;
  }
  return 0;
}

/* ---- FUNC 00032960 APInitInstance (124 bytes) ---- */

undefined8 APInitInstance(longlong *param_1)

{
                    /* 0x32960  20  APInitInstance */
  DAT_180079800 = param_1;
  (**(code **)(*param_1 + 8))();
  FUN_18000f4c0(&DAT_1800797f0,_guard_check_icall);
  if (DAT_1800797f0 == (IUnknown *)0x0) {
    DAT_1800797d4 = DAT_1800797d4 + 1;
    _guard_check_icall();
  }
  DAT_1800797d4 = DAT_1800797d4 + 1;
  FUN_180018e30(DAT_1800797f0,1,0);
  DAT_1800797e8 = CreateSemaphoreA((LPSECURITY_ATTRIBUTES)0x0,1,1,"SemaphoreBackPtr");
  return 1;
}

/* ---- FUNC 000329E0 FUN_1800329e0 (389 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined8 * FUN_1800329e0(int *param_1,LPCWSTR param_2)

{
  char cVar1;
  int iVar2;
  undefined8 *puVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  undefined8 *_Memory;
  undefined1 *puVar7;
  undefined1 *puVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  longlong lVar12;
  undefined1 auStack_78 [64];
  undefined8 *local_38;
  ulonglong local_30;
  
  puVar8 = auStack_78;
  puVar7 = auStack_78;
  local_30 = DAT_180077818 ^ (ulonglong)&local_38;
  if (param_2 == (LPCWSTR)0x0) {
    puVar3 = (undefined8 *)0x0;
    goto LAB_180032b35;
  }
  puVar3 = (undefined8 *)0x0;
  local_38 = (undefined8 *)0x0;
  lVar12 = -1;
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (param_2[lVar4] != L'\0');
  lVar4 = (longlong)((int)lVar4 + 1) * 2;
  _Memory = puVar3;
  puVar8 = auStack_78;
  puVar11 = puVar3;
  if (lVar4 + 0x80000000U < 0x100000000) {
    iVar2 = (int)lVar4;
    uVar9 = (ulonglong)iVar2;
    if ((iVar2 < 0x401) && (cVar1 = FUN_1800026d0(uVar9), cVar1 != '\0')) {
      uVar5 = uVar9 + 0xf;
      if (uVar5 <= uVar9) {
        uVar5 = 0xffffffffffffff0;
      }
      puVar7 = auStack_78 + -(uVar5 & 0xfffffffffffffff0);
      puVar10 = (undefined8 *)((longlong)&local_38 + -(uVar5 & 0xfffffffffffffff0));
      puVar6 = puVar3;
    }
    else {
      if (~uVar9 < 0x10) {
                    /* WARNING: Subroutine does not return */
        FUN_180001a90(-0x7ff8fdea);
      }
      puVar6 = malloc(uVar9 + 0x10);
      _Memory = (undefined8 *)0x0;
      puVar8 = auStack_78;
      if (puVar6 == (undefined8 *)0x0) goto LAB_180032afd;
      *puVar6 = 0;
      local_38 = puVar6;
      puVar10 = puVar6 + 2;
    }
    _Memory = puVar6;
    puVar8 = puVar7;
    if (puVar10 != (undefined8 *)0x0) {
      *(undefined1 *)puVar10 = 0;
      *(undefined8 *)(puVar7 + 0x38) = 0;
      *(undefined8 *)(puVar7 + 0x30) = 0;
      *(int *)(puVar7 + 0x28) = iVar2;
      *(undefined8 **)(puVar7 + 0x20) = puVar10;
      *(undefined8 *)(puVar7 + -8) = 0x180032af2;
      iVar2 = WideCharToMultiByte(0,0,param_2,-1,*(LPSTR *)(puVar7 + 0x20),*(int *)(puVar7 + 0x28),
                                  *(LPCSTR *)(puVar7 + 0x30),*(LPBOOL *)(puVar7 + 0x38));
      puVar11 = puVar10;
      if (iVar2 == 0) {
        puVar11 = puVar3;
      }
    }
  }
LAB_180032afd:
  if (puVar11 != (undefined8 *)0x0) {
    do {
      lVar12 = lVar12 + 1;
    } while (*(char *)((longlong)puVar11 + lVar12) != '\0');
    *(undefined8 *)(puVar8 + -8) = 0x180032b19;
    uVar9 = FUN_1800332b0(param_1,puVar11,(int)lVar12);
    puVar3 = (undefined8 *)(uVar9 & 0xffffffff);
  }
  while (_Memory != (undefined8 *)0x0) {
    puVar11 = (undefined8 *)*_Memory;
    *(undefined8 *)(puVar8 + -8) = 0x180032b2d;
    free(_Memory);
    _Memory = puVar11;
  }
LAB_180032b35:
  *(undefined8 *)(puVar8 + -8) = 0x180032b41;
  return puVar3;
}

/* ---- FUNC 00032B70 FUN_180032b70 (1728 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180032b70(undefined8 *param_1,undefined8 *param_2,LPCSTR param_3,undefined1 *param_4)

{
  BYTE BVar1;
  HKEY hKey;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  longlong lVar4;
  LPCSTR lpValueName;
  char cVar5;
  int iVar6;
  BOOL BVar7;
  DWORD cbData;
  ulonglong uVar8;
  longlong lVar9;
  LPSTR pCVar10;
  BYTE *pBVar11;
  ulonglong uVar12;
  LPCOLESTR pOVar13;
  undefined4 extraout_var;
  longlong lVar14;
  BYTE *pBVar15;
  LPCOLESTR pOVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  undefined1 *puVar19;
  uint uVar20;
  LPCOLESTR pOVar21;
  DWORD DVar22;
  LPCOLESTR pOVar23;
  LPCOLESTR strIn;
  undefined1 auStackY_12f8 [32];
  DWORD local_12c8 [2];
  DWORD local_12c0 [2];
  LPCSTR local_12b8;
  undefined8 *local_12b0;
  undefined8 *local_12a8;
  LPCSTR local_12a0;
  ulonglong local_1298;
  undefined1 *local_1290;
  BYTE *local_1278;
  BYTE local_1270 [264];
  BYTE *local_1168;
  BYTE local_1160 [264];
  BYTE local_1058 [4096];
  ulonglong local_58;
  undefined8 uStack_48;
  
  uStack_48 = 0x180032b87;
  puVar17 = auStackY_12f8;
  puVar18 = auStackY_12f8;
  local_58 = DAT_180077818 ^ (ulonglong)local_12c8;
  local_12b8 = param_3;
  local_12b0 = param_1;
  local_12a8 = param_2;
  local_12a0 = param_3;
  local_1290 = param_4;
  uVar8 = FUN_180033b80(param_1,local_1058);
  puVar19 = auStackY_12f8;
  if ((int)uVar8 < 0) goto LAB_1800331ed;
  iVar6 = lstrcmpiA((LPCSTR)local_1058,"S");
  if (iVar6 == 0) {
    iVar6 = 8;
  }
  else {
    iVar6 = lstrcmpiA((LPCSTR)local_1058,"M");
    if (iVar6 == 0) {
      iVar6 = 0x4008;
    }
    else {
      iVar6 = lstrcmpiA((LPCSTR)local_1058,"D");
      if (iVar6 == 0) {
        iVar6 = 0x13;
      }
      else {
        iVar6 = lstrcmpiA((LPCSTR)local_1058,"B");
        if (iVar6 != 0) {
          uVar8 = 0x80020009;
          puVar19 = auStackY_12f8;
          goto LAB_1800331ed;
        }
        iVar6 = 0x11;
      }
    }
  }
  while( true ) {
    cVar5 = *(LPCSTR)*param_1;
    if ((((cVar5 != '\t') && (cVar5 != '\n')) && (cVar5 != '\r')) && (cVar5 != ' ')) break;
    pCVar10 = CharNextA((LPCSTR)*param_1);
    *param_1 = pCVar10;
  }
  uVar8 = FUN_180033b80(param_1,local_1058);
  puVar19 = auStackY_12f8;
  if ((int)uVar8 < 0) goto LAB_1800331ed;
  if (iVar6 == 8) {
    lVar14 = -1;
    do {
      lVar9 = lVar14 + 1;
      lVar4 = lVar14 + 1;
      lVar14 = lVar9;
    } while (local_1058[lVar4] != '\0');
    uVar20 = RegSetValueExA((HKEY)*param_2,param_3,0,1,local_1058,(int)lVar9 + 1);
LAB_1800331c5:
    puVar19 = puVar18;
    if (uVar20 != 0) {
      *(undefined8 *)(puVar18 + -8) = 0x1800331d4;
      uVar20 = FUN_180033410(uVar20);
      uVar8 = CONCAT44(extraout_var,uVar20);
      goto LAB_1800331ed;
    }
  }
  else {
    if (iVar6 == 0x11) {
      uVar8 = 0xffffffffffffffff;
      do {
        uVar12 = uVar8 + 1;
        lVar14 = uVar8 + 1;
        uVar8 = uVar12;
      } while (local_1058[lVar14] != '\0');
      DVar22 = (DWORD)uVar12;
      if ((uVar12 & 1) == 0) {
        cbData = (int)DVar22 / 2;
        uVar12 = (ulonglong)(int)cbData;
        uVar8 = 0;
        local_1278 = (BYTE *)0x0;
        local_12c8[0] = cbData;
        local_12c0[0] = DVar22;
        local_1298 = uVar12;
        if (cbData == 0) {
LAB_180033078:
          local_1278 = local_1270;
        }
        else {
          auVar3._8_8_ = 0;
          auVar3._0_8_ = uVar12;
          if (SUB168((ZEXT416(0) << 0x40 | ZEXT816(0xffffffffffffffff)) / auVar3,0) == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_180001a90(-0x7ff8fdea);
          }
          if (uVar12 < 0x101) goto LAB_180033078;
          FUN_180033280(&local_1278,uVar12);
        }
        lpValueName = local_12b8;
        if (local_1278 != (BYTE *)0x0) {
          memset(local_1278,0,uVar12);
          uVar12 = uVar8;
          if (0 < (int)DVar22) {
            do {
              uVar20 = (uint)uVar12;
              BVar1 = local_1058[uVar8];
              switch(BVar1) {
              case '0':
              case '1':
              case '2':
              case '3':
              case '4':
              case '5':
              case '6':
              case '7':
              case '8':
              case '9':
                cVar5 = BVar1 + 0xd0;
                break;
              default:
                cVar5 = '\0';
                break;
              case 'A':
              case 'B':
              case 'C':
              case 'D':
              case 'E':
              case 'F':
                cVar5 = BVar1 + 0xc9;
                break;
              case 'a':
              case 'b':
              case 'c':
              case 'd':
              case 'e':
              case 'f':
                cVar5 = BVar1 + 0xa9;
              }
              local_1278[(int)uVar20 / 2] =
                   local_1278[(int)uVar20 / 2] | cVar5 << (4U - (char)((uVar20 & 1) << 2) & 0x1f);
              uVar8 = uVar8 + 1;
              uVar12 = (ulonglong)(uVar20 + 1);
            } while ((longlong)uVar8 < (longlong)(int)DVar22);
          }
          uVar20 = RegSetValueExA((HKEY)*param_2,lpValueName,0,3,local_1278,cbData);
          puVar18 = auStackY_12f8;
          if (local_1278 != local_1270) {
            FUN_1800339a0(&local_1278);
            puVar18 = auStackY_12f8;
          }
          goto LAB_1800331c5;
        }
        FUN_1800339a0(&local_1278);
      }
      uVar8 = 0x80004005;
      puVar19 = auStackY_12f8;
      goto LAB_1800331ed;
    }
    if (iVar6 == 0x13) {
      pOVar21 = (LPCOLESTR)0x0;
      pOVar16 = (LPCOLESTR)0x0;
      local_1298 = 0;
      lVar14 = -1;
      do {
        lVar9 = lVar14 + 1;
        lVar4 = lVar14 + 1;
        lVar14 = lVar9;
      } while (local_1058[lVar4] != '\0');
      lVar14 = (longlong)((int)lVar9 + 1) * 2;
      pOVar13 = pOVar21;
      puVar19 = auStackY_12f8;
      strIn = pOVar21;
      if (lVar14 + 0x80000000U < 0x100000000) {
        iVar6 = (int)lVar14;
        uVar8 = (ulonglong)iVar6;
        if ((iVar6 < 0x401) && (cVar5 = FUN_1800026d0(uVar8), cVar5 != '\0')) {
          uVar12 = uVar8 + 0xf;
          if (uVar12 <= uVar8) {
            uVar12 = 0xffffffffffffff0;
          }
          pOVar16 = pOVar21;
          puVar17 = auStackY_12f8 + -(uVar12 & 0xfffffffffffffff0);
          pOVar23 = (LPCOLESTR)((longlong)local_12c8 + -(uVar12 & 0xfffffffffffffff0));
        }
        else {
          if (~uVar8 < 0x10) {
                    /* WARNING: Subroutine does not return */
            FUN_180001a90(-0x7ff8fdea);
          }
          pOVar13 = malloc(uVar8 + 0x10);
          pOVar23 = pOVar21;
          if (pOVar13 != (LPCOLESTR)0x0) {
            pOVar13[0] = L'\0';
            pOVar13[1] = L'\0';
            pOVar13[2] = L'\0';
            pOVar13[3] = L'\0';
            pOVar16 = pOVar13;
            puVar17 = auStackY_12f8;
            pOVar23 = pOVar13 + 8;
          }
        }
        pOVar13 = pOVar16;
        puVar19 = puVar17;
        param_3 = local_12b8;
        if (pOVar23 != (LPCOLESTR)0x0) {
          *pOVar23 = L'\0';
          *(int *)(puVar17 + 0x28) = (int)(uVar8 >> 1);
          *(LPCOLESTR *)(puVar17 + 0x20) = pOVar23;
          *(undefined8 *)(puVar17 + -8) = 0x180032f3c;
          iVar6 = MultiByteToWideChar(0,0,(LPCSTR)local_1058,-1,*(LPWSTR *)(puVar17 + 0x20),
                                      *(int *)(puVar17 + 0x28));
          strIn = pOVar23;
          param_3 = local_12b8;
          if (iVar6 == 0) {
            strIn = pOVar21;
          }
        }
      }
      if (strIn == (LPCOLESTR)0x0) {
        while (pOVar13 != (LPCOLESTR)0x0) {
          pOVar16 = *(LPCOLESTR *)pOVar13;
          *(undefined8 *)(puVar19 + -8) = 0x180032f6c;
          free(pOVar13);
          pOVar13 = pOVar16;
        }
        uVar8 = 0x8007000e;
        goto LAB_1800331ed;
      }
      *(undefined8 *)(puVar19 + -8) = 0x180032f8d;
      uVar20 = VarUI4FromStr(strIn,0,0,local_12c8);
      uVar8 = (ulonglong)uVar20;
      if ((int)uVar20 < 0) {
        while (pOVar13 != (LPCOLESTR)0x0) {
          pOVar16 = *(LPCOLESTR *)pOVar13;
          *(undefined8 *)(puVar19 + -8) = 0x180032fac;
          free(pOVar13);
          pOVar13 = pOVar16;
        }
        goto LAB_1800331ed;
      }
      local_12c0[0] = local_12c8[0];
      *(undefined4 *)(puVar19 + 0x28) = 4;
      *(DWORD **)(puVar19 + 0x20) = local_12c0;
      hKey = (HKEY)*param_2;
      *(undefined8 *)(puVar19 + -8) = 0x180032fe5;
      uVar20 = RegSetValueExA(hKey,param_3,0,4,*(BYTE **)(puVar19 + 0x20),*(DWORD *)(puVar19 + 0x28)
                             );
      while (puVar18 = puVar19, pOVar13 != (LPCOLESTR)0x0) {
        pOVar16 = *(LPCOLESTR *)pOVar13;
        *(undefined8 *)(puVar19 + -8) = 0x180032ffc;
        free(pOVar13);
        pOVar13 = pOVar16;
      }
      goto LAB_1800331c5;
    }
    puVar19 = auStackY_12f8;
    if (iVar6 == 0x4008) {
      lVar14 = -1;
      do {
        lVar9 = lVar14 + 1;
        lVar4 = lVar14 + 1;
        lVar14 = lVar9;
      } while (local_1058[lVar4] != '\0');
      iVar6 = (int)lVar9 + 2;
      DVar22 = 0;
      local_1168 = (BYTE *)0x0;
      uVar8 = (ulonglong)iVar6;
      if (iVar6 == 0) {
LAB_180032d1f:
        local_1168 = local_1160;
      }
      else {
        auVar2._8_8_ = 0;
        auVar2._0_8_ = uVar8;
        if (SUB168((ZEXT816(0) << 0x40 | ZEXT816(0xffffffffffffffff)) / auVar2,0) == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_180001a90(-0x7ff8fdea);
        }
        if (uVar8 < 0x101) goto LAB_180032d1f;
        FUN_180033280(&local_1168,uVar8);
      }
      if (local_1168 == (BYTE *)0x0) {
        uVar20 = 0xe;
      }
      else {
        pBVar11 = local_1058;
        pBVar15 = local_1168;
        while (local_1058[0] != '\0') {
          pCVar10 = CharNextA((LPCSTR)pBVar11);
          if ((*pBVar11 == '\\') && (*pCVar10 == '0')) {
            *pBVar15 = '\0';
            pBVar11 = (BYTE *)CharNextA(pCVar10);
          }
          else {
            *pBVar15 = *pBVar11;
            BVar7 = IsDBCSLeadByte(*pBVar11);
            if (BVar7 != 0) {
              pBVar15 = pBVar15 + 1;
              pBVar11 = pBVar11 + 1;
              if (*pBVar11 == '\0') break;
              *pBVar15 = *pBVar11;
            }
            pBVar11 = pBVar11 + 1;
          }
          pBVar15 = pBVar15 + 1;
          local_1058[0] = *pBVar11;
        }
        pBVar15[0] = '\0';
        pBVar15[1] = '\0';
        pBVar11 = local_1168;
        if (local_1168 == (BYTE *)0x0) {
          uVar20 = 0xd;
        }
        else {
          do {
            lVar14 = -1;
            do {
              lVar14 = lVar14 + 1;
            } while (pBVar11[lVar14] != '\0');
            uVar20 = (int)lVar14 + 1;
            DVar22 = DVar22 + uVar20;
            pBVar11 = pBVar11 + uVar20;
          } while (uVar20 != 1);
          uVar20 = RegSetValueExA((HKEY)*param_2,param_3,0,(int)lVar14 + 7,local_1168,DVar22);
        }
      }
      puVar18 = auStackY_12f8;
      if (local_1168 != local_1160) {
        FUN_1800339a0(&local_1168);
        puVar18 = auStackY_12f8;
      }
      goto LAB_1800331c5;
    }
  }
  puVar18 = local_1290;
  uVar8 = 0;
  *(undefined8 *)(puVar19 + -8) = 0x180032e59;
  uVar12 = FUN_180033b80(param_1,puVar18);
  if ((int)uVar12 < 0) {
    uVar8 = uVar12 & 0xffffffff;
  }
LAB_1800331ed:
  *(undefined8 *)(puVar19 + -8) = 0x1800331fc;
  return uVar8;
}

/* ---- FUNC 00033280 FUN_180033280 (42 bytes) ---- */

void FUN_180033280(undefined8 *param_1,size_t param_2)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_2);
  if (pvVar1 != (void *)0x0) {
    *param_1 = pvVar1;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_180001a90(-0x7ff8fff2);
}

/* ---- FUNC 000332B0 FUN_1800332b0 (120 bytes) ---- */

undefined8 FUN_1800332b0(int *param_1,void *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  LPVOID pvVar3;
  int *piVar4;
  int iVar5;
  void *_Dst;
  ulonglong _Size;
  ulonglong _Size_00;
  
  _Size = (ulonglong)param_3;
  iVar5 = param_3 + 1 + *param_1;
  if ((iVar5 <= *param_1) || (iVar5 <= param_3)) {
    return 0;
  }
  uVar1 = param_1[1];
  if ((int)uVar1 <= iVar5) {
    do {
      if (0x3fffffff < (int)uVar1) {
        return 0;
      }
      uVar1 = uVar1 * 2;
      param_1[1] = uVar1;
    } while ((int)uVar1 <= iVar5);
    pvVar3 = CoTaskMemRealloc(*(LPVOID *)(param_1 + 2),(ulonglong)uVar1);
    if (pvVar3 == (LPVOID)0x0) {
      return 0;
    }
    *(LPVOID *)(param_1 + 2) = pvVar3;
  }
  iVar5 = *param_1;
  if (iVar5 < 0) {
    return 0;
  }
  iVar2 = param_1[1];
  if (iVar2 <= iVar5) {
    return 0;
  }
  if (iVar2 < iVar2 - iVar5) {
    return 0;
  }
  _Size_00 = (ulonglong)(iVar2 - iVar5);
  _Dst = (void *)((longlong)iVar5 + *(longlong *)(param_1 + 2));
  if (param_3 == 0) {
LAB_18003336b:
    *param_1 = *param_1 + param_3;
    *(undefined1 *)((longlong)*param_1 + *(longlong *)(param_1 + 2)) = 0;
    return 1;
  }
  if (_Dst == (void *)0x0) {
    piVar4 = _errno();
    *piVar4 = 0x16;
  }
  else {
    if ((param_2 != (void *)0x0) && (_Size <= _Size_00)) {
      memcpy(_Dst,param_2,_Size);
      goto LAB_18003336b;
    }
    memset(_Dst,0,_Size_00);
    if (param_2 == (void *)0x0) {
      piVar4 = _errno();
      *piVar4 = 0x16;
    }
    else {
      if (_Size <= _Size_00) goto LAB_1800333df;
      piVar4 = _errno();
      *piVar4 = 0x22;
    }
  }
  _invalid_parameter_noinfo();
LAB_1800333df:
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00033328 FUN_180033328 (112 bytes) ---- */

undefined8 FUN_180033328(int param_1)

{
  longlong in_RAX;
  int *piVar1;
  void *_Dst;
  int *unaff_RBX;
  ulonglong unaff_RBP;
  ulonglong _Size;
  void *unaff_R14;
  
  _Size = (ulonglong)param_1;
  _Dst = (void *)(in_RAX + *(longlong *)(unaff_RBX + 2));
  if ((int)unaff_RBP == 0) {
LAB_18003336b:
    *unaff_RBX = *unaff_RBX + (int)unaff_RBP;
    *(undefined1 *)((longlong)*unaff_RBX + *(longlong *)(unaff_RBX + 2)) = 0;
    return 1;
  }
  if (_Dst == (void *)0x0) {
    piVar1 = _errno();
    *piVar1 = 0x16;
  }
  else {
    if ((unaff_R14 != (void *)0x0) && (unaff_RBP <= _Size)) {
      memcpy(_Dst,unaff_R14,unaff_RBP);
      goto LAB_18003336b;
    }
    memset(_Dst,0,_Size);
    if (unaff_R14 == (void *)0x0) {
      piVar1 = _errno();
      *piVar1 = 0x16;
    }
    else {
      if (unaff_RBP <= _Size) goto LAB_1800333df;
      piVar1 = _errno();
      *piVar1 = 0x22;
    }
  }
  _invalid_parameter_noinfo();
LAB_1800333df:
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00033398 FUN_180033398 (19 bytes) ---- */

undefined8 FUN_180033398(void)

{
  return 0;
}

/* ---- FUNC 000333AB FUN_1800333ab (57 bytes) ---- */

void FUN_1800333ab(void *param_1)

{
  int *piVar1;
  ulonglong unaff_RBP;
  ulonglong unaff_RSI;
  longlong unaff_R14;
  
  memset(param_1,0,unaff_RSI);
  if (unaff_R14 == 0) {
    piVar1 = _errno();
    *piVar1 = 0x16;
  }
  else {
    if (unaff_RBP <= unaff_RSI) goto LAB_1800333df;
    piVar1 = _errno();
    *piVar1 = 0x22;
  }
  _invalid_parameter_noinfo();
LAB_1800333df:
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 000333F0 FUN_1800333f0 (27 bytes) ---- */

DWORD FUN_1800333f0(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  return DVar1;
}

/* ---- FUNC 00033410 FUN_180033410 (16 bytes) ---- */

uint FUN_180033410(uint param_1)

{
  if ((int)param_1 < 1) {
    return param_1;
  }
  return param_1 & 0xffff | 0x80070000;
}

/* ---- FUNC 00033420 FUN_180033420 (74 bytes) ---- */

undefined8 FUN_180033420(longlong param_1,longlong param_2,int *param_3,undefined8 *param_4)

{
  longlong lVar1;
  int *piVar2;
  undefined8 uVar3;
  longlong *plVar4;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    return 0x80070057;
  }
  if (param_4 == (undefined8 *)0x0) {
    return 0x80004003;
  }
  if ((((*param_3 == 0) && (param_3[1] == 0)) && (param_3[2] == 0xc0)) && (param_3[3] == 0x46000000)
     ) {
    plVar4 = (longlong *)(*(longlong *)(param_2 + 8) + param_1);
    (**(code **)(*plVar4 + 8))(plVar4);
    uVar3 = 0;
    *param_4 = plVar4;
  }
  else {
    plVar4 = (longlong *)(param_2 + 0x10);
    lVar1 = *(longlong *)(param_2 + 0x10);
    while (lVar1 != 0) {
      piVar2 = (int *)plVar4[-2];
      if ((piVar2 == (int *)0x0) ||
         (((*piVar2 == *param_3 && (piVar2[1] == param_3[1])) &&
          ((piVar2[2] == param_3[2] && (piVar2[3] == param_3[3])))))) {
        if ((code *)*plVar4 == (code *)0x1) {
          plVar4 = (longlong *)(plVar4[-1] + param_1);
          (**(code **)(*plVar4 + 8))(plVar4);
          *param_4 = plVar4;
          return 0;
        }
        uVar3 = (*(code *)*plVar4)(param_1,param_3,param_4,plVar4[-1]);
        if ((int)uVar3 == 0) {
          return 0;
        }
        if ((piVar2 != (int *)0x0) && ((int)uVar3 < 0)) goto LAB_18003350e;
      }
      plVar4 = plVar4 + 3;
      lVar1 = *plVar4;
    }
    uVar3 = 0x80004002;
LAB_18003350e:
    *param_4 = 0;
  }
  return uVar3;
}

/* ---- FUNC 0003346A FUN_18003346a (62 bytes) ---- */

undefined8 FUN_18003346a(undefined8 param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  int *piVar2;
  undefined8 uVar3;
  longlong *plVar4;
  int *unaff_RSI;
  undefined8 *unaff_R14;
  longlong unaff_R15;
  bool in_ZF;
  
  if ((((in_ZF) && (*(int *)(param_3 + 4) == 0)) && (*(int *)(param_3 + 8) == 0xc0)) &&
     (*(int *)(param_3 + 0xc) == 0x46000000)) {
    plVar4 = (longlong *)(*(longlong *)(param_2 + 8) + unaff_R15);
    (**(code **)(*plVar4 + 8))(plVar4);
    uVar3 = 0;
    *unaff_R14 = plVar4;
  }
  else {
    plVar4 = (longlong *)(param_2 + 0x10);
    lVar1 = *(longlong *)(param_2 + 0x10);
    while (lVar1 != 0) {
      piVar2 = (int *)plVar4[-2];
      if ((piVar2 == (int *)0x0) ||
         (((*piVar2 == *unaff_RSI && (piVar2[1] == unaff_RSI[1])) &&
          ((piVar2[2] == unaff_RSI[2] && (piVar2[3] == unaff_RSI[3])))))) {
        if ((code *)*plVar4 == (code *)0x1) {
          plVar4 = (longlong *)(plVar4[-1] + unaff_R15);
          (**(code **)(*plVar4 + 8))(plVar4);
          *unaff_R14 = plVar4;
          return 0;
        }
        uVar3 = (*(code *)*plVar4)();
        if ((int)uVar3 == 0) {
          return 0;
        }
        if ((piVar2 != (int *)0x0) && ((int)uVar3 < 0)) goto LAB_18003350e;
      }
      plVar4 = plVar4 + 3;
      lVar1 = *plVar4;
    }
    uVar3 = 0x80004002;
LAB_18003350e:
    *unaff_R14 = 0;
  }
  return uVar3;
}

/* ---- FUNC 000334A8 FUN_1800334a8 (114 bytes) ---- */

undefined8 FUN_1800334a8(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  undefined8 uVar2;
  longlong *plVar3;
  int *unaff_RSI;
  undefined8 *unaff_R14;
  longlong unaff_R15;
  bool in_ZF;
  
  plVar3 = (longlong *)(param_2 + 0x10);
  if (!in_ZF) {
    do {
      piVar1 = (int *)plVar3[-2];
      if ((piVar1 == (int *)0x0) ||
         ((((*piVar1 == *unaff_RSI && (piVar1[1] == unaff_RSI[1])) && (piVar1[2] == unaff_RSI[2]))
          && (piVar1[3] == unaff_RSI[3])))) {
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
        if ((piVar1 != (int *)0x0) && ((int)uVar2 < 0)) goto LAB_18003350e;
      }
      plVar3 = plVar3 + 3;
    } while (*plVar3 != 0);
  }
  uVar2 = 0x80004002;
LAB_18003350e:
  *unaff_R14 = 0;
  return uVar2;
}

/* ---- FUNC 0003351A FUN_18003351a (22 bytes) ---- */

void FUN_18003351a(void)

{
  return;
}

/* ---- FUNC 00033530 FUN_180033530 (23 bytes) ---- */

undefined8 FUN_180033530(void)

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

/* ---- FUNC 00033547 FUN_180033547 (22 bytes) ---- */

undefined8 FUN_180033547(void)

{
  return 0x80070057;
}

/* ---- FUNC 00033560 FUN_180033560 (163 bytes) ---- */

undefined8 FUN_180033560(longlong *param_1)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  
  iVar1 = (int)param_1[2];
  iVar2 = 0;
  if (0 < iVar1) {
    lVar3 = 0;
    do {
      if ((lVar3 < 0) || (iVar1 <= iVar2)) {
LAB_1800335f9:
                    /* WARNING: Subroutine does not return */
        FUN_180001a90(-0x7ffffff5);
      }
      operator_delete__(*(void **)(lVar3 + *param_1));
      if ((int)param_1[2] <= iVar2) goto LAB_1800335f9;
      operator_delete__(*(void **)(lVar3 + param_1[1]));
      iVar1 = (int)param_1[2];
      iVar2 = iVar2 + 1;
      lVar3 = lVar3 + 8;
    } while (iVar2 < iVar1);
  }
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  if ((void *)param_1[1] != (void *)0x0) {
    free((void *)param_1[1]);
    param_1[1] = 0;
  }
  *(undefined4 *)(param_1 + 2) = 0;
  return 0;
}

/* ---- FUNC 00033610 FUN_180033610 (308 bytes) ---- */

longlong * FUN_180033610(longlong param_1,int *param_2,longlong *param_3)

{
  uint uVar1;
  longlong *plVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong *plVar5;
  longlong *plVar6;
  
  if (param_3 == (longlong *)0x0) {
    return (longlong *)0x80004003;
  }
  *param_3 = 0;
  plVar6 = (longlong *)0x8007000e;
  plVar2 = operator_new(0x38);
  plVar5 = (longlong *)0x0;
  if (plVar2 != (longlong *)0x0) {
    *(undefined4 *)(plVar2 + 1) = 0;
    *plVar2 = (longlong)ATL::CComAggObject<CHNodeSelection>::vftable;
    *(undefined4 *)(plVar2 + 3) = 0;
    plVar2[6] = 0;
    plVar2[2] = (longlong)ATL::CComContainedObject<CHNodeSelection>::vftable;
    plVar2[4] = (longlong)ATL::CComContainedObject<CHNodeSelection>::vftable;
    plVar2[5] = param_1;
    (**(code **)(*DAT_180079320 + 8))();
    plVar5 = plVar2;
  }
  if (plVar5 != (longlong *)0x0) {
    uVar3 = FUN_18002e4b0();
    plVar6 = (longlong *)0x0;
    if ((int)uVar3 < 0) {
      plVar6 = (longlong *)(uVar3 & 0xffffffff);
    }
    if ((int)plVar6 == 0) {
      if (*(code **)*plVar5 == FUN_180032510) {
        uVar4 = FUN_180032510(plVar5,param_2,param_3);
        uVar1 = (uint)uVar4;
      }
      else {
        uVar1 = (**(code **)*plVar5)();
      }
      plVar6 = (longlong *)(ulonglong)uVar1;
      if (uVar1 == 0) {
        return (longlong *)0x0;
      }
    }
    (**(code **)(*plVar5 + 0x18))(plVar5,1);
  }
  return plVar6;
}

/* ---- FUNC 00033750 FUN_180033750 (284 bytes) ---- */

longlong * FUN_180033750(undefined8 param_1,int *param_2,undefined8 *param_3)

{
  code *pcVar1;
  uint uVar2;
  longlong *plVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong *plVar8;
  
  if (param_3 == (undefined8 *)0x0) {
    return (longlong *)0x80004003;
  }
  *param_3 = 0;
  plVar7 = (longlong *)0x8007000e;
  plVar3 = operator_new(0x28);
  plVar6 = (longlong *)0x0;
  if (plVar3 != (longlong *)0x0) {
    *(undefined4 *)(plVar3 + 3) = 0;
    *(undefined4 *)(plVar3 + 1) = 0;
    plVar3[4] = 0;
    *plVar3 = (longlong)ATL::CComObject<CHNodeSelection>::vftable;
    plVar3[2] = (longlong)ATL::CComObject<CHNodeSelection>::vftable;
    plVar8 = plVar3;
    (**(code **)(*DAT_180079320 + 8))();
    plVar6 = plVar3;
    plVar3 = plVar8;
  }
  if (plVar6 != (longlong *)0x0) {
    plVar8 = plVar6;
    uVar4 = FUN_18002e4b0();
    plVar7 = (longlong *)0x0;
    if ((int)uVar4 < 0) {
      plVar7 = (longlong *)(uVar4 & 0xffffffff);
    }
    if ((int)plVar7 == 0) {
      pcVar1 = *(code **)*plVar6;
      if (pcVar1 == FUN_1800196b0) {
        uVar5 = FUN_180033420((longlong)plVar6,0x180064030,param_2,param_3);
        uVar2 = (uint)uVar5;
      }
      else {
        uVar2 = (*pcVar1)(plVar6,param_2,param_3,pcVar1,plVar8,plVar3);
      }
      plVar7 = (longlong *)(ulonglong)uVar2;
      if (uVar2 == 0) {
        return (longlong *)0x0;
      }
    }
    (**(code **)(*plVar6 + 0x28))(plVar6,1);
  }
  return plVar7;
}

/* ---- FUNC 00033870 FUN_180033870 (303 bytes) ---- */

ulonglong FUN_180033870(undefined8 *param_1,LPCSTR param_2)

{
  longlong *plVar1;
  LSTATUS LVar2;
  HMODULE pHVar3;
  FARPROC pFVar4;
  ulonglong uVar5;
  undefined4 extraout_var;
  HKEY hKey;
  
  plVar1 = (longlong *)param_1[2];
  if (plVar1 != (longlong *)0x0) {
    hKey = (HKEY)*param_1;
    if (*plVar1 == 0) {
      if ((int)plVar1[1] != 0) goto LAB_1800338fa;
    }
    else {
      pHVar3 = GetModuleHandleA("Advapi32.dll");
      if ((pHVar3 != (HMODULE)0x0) &&
         (pFVar4 = GetProcAddress(pHVar3,"RegDeleteKeyTransactedA"), pFVar4 != (FARPROC)0x0)) {
        uVar5 = (*pFVar4)(hKey,param_2,0,0,*plVar1,0);
        return uVar5;
      }
    }
    return 1;
  }
  if (DAT_180079878 == '\0') {
    pHVar3 = GetModuleHandleA("Advapi32.dll");
    if (pHVar3 == (HMODULE)0x0) {
      DAT_180079878 = '\x01';
    }
    else {
      DAT_180079870 = GetProcAddress(pHVar3,"RegDeleteKeyExA");
      DAT_180079878 = '\x01';
    }
  }
  hKey = (HKEY)*param_1;
  if (DAT_180079870 != (FARPROC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00018003399c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar5 = (*DAT_180079870)(hKey,param_2,(ulonglong)*(uint *)(param_1 + 1),0);
    return uVar5;
  }
LAB_1800338fa:
                    /* WARNING: Could not recover jumptable at 0x000180033909. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LVar2 = RegDeleteKeyA(hKey,param_2);
  return CONCAT44(extraout_var,LVar2);
}

/* ---- FUNC 000339A0 FUN_1800339a0 (10 bytes) ---- */

void FUN_1800339a0(undefined8 *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0001800339a3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  free((void *)*param_1);
  return;
}

/* ---- FUNC 000339B0 HappLockMT (13 bytes) ---- */

undefined4 HappLockMT(undefined4 param_1)

{
  undefined4 uVar1;
  
                    /* 0x339b0  51  HappLockMT */
  uVar1 = DAT_1800797f8;
  DAT_1800797f8 = param_1;
  return uVar1;
}

/* ---- FUNC 000339C0 HappNotify (141 bytes) ---- */

void HappNotify(short param_1,longlong *param_2)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res10 [24];
  
                    /* 0x339c0  41  HappNotify */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10,"");
  if ((param_1 == 1) || (param_1 == 3)) {
    FUN_18003d280((longlong)param_2,4);
    if (DAT_18007988c == 0) {
      FUN_1800374c0(0x65,(longlong *)local_res10);
    }
  }
  else if ((param_1 == 8) || (param_1 == 0xe)) {
    FUN_18003d280((longlong)param_2,4);
  }
  (**(code **)(*param_2 + 0x10))(param_2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10);
  return;
}

/* ---- FUNC 00033A50 FUN_180033a50 (127 bytes) ---- */

undefined8 FUN_180033a50(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1)

{
  int iVar1;
  
  iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                    (param_1,PTR_s_Measurement_180077708);
  if (iVar1 != 0) {
    iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                      (param_1,PTR_s_Design_Spec_180077710);
    if (iVar1 != 0) {
      iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                        (param_1,PTR_s_Calculator_180077718);
      if (iVar1 != 0) {
        iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                          (param_1,PTR_s_Transfer_180077720);
        if (iVar1 != 0) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1);
          return 0;
        }
      }
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1);
  return 1;
}

/* ---- FUNC 00033AD0 FUN_180033ad0 (168 bytes) ---- */

HRESULT FUN_180033ad0(undefined8 *param_1,GUID *param_2)

{
  HRESULT HVar1;
  ITypeLib *local_res8;
  ITypeInfo *local_res18 [2];
  
  *param_1 = 0;
  local_res8 = (ITypeLib *)0x0;
  local_res18[0] = (ITypeInfo *)0x0;
  HVar1 = LoadRegTypeLib((GUID *)&DAT_1800633f0,0x16,0,0x409,&local_res8);
  if ((HVar1 < 0) && (HVar1 = LoadTypeLib(L"happ.tlb",&local_res8), HVar1 < 0)) {
    return HVar1;
  }
  HVar1 = (*local_res8->lpVtbl->GetTypeInfoOfGuid)(local_res8,param_2,local_res18);
  if (-1 < HVar1) {
    (*local_res8->lpVtbl->Release)(local_res8);
    *param_1 = local_res18[0];
    return 0;
  }
  (*local_res8->lpVtbl->Release)(local_res8);
  return HVar1;
}

/* ---- FUNC 00033B80 FUN_180033b80 (403 bytes) ---- */

undefined8 FUN_180033b80(undefined8 *param_1,undefined1 *param_2)

{
  byte bVar1;
  LPSTR pCVar2;
  char *lpsz;
  LPCSTR lpsz_00;
  ulonglong uVar3;
  char cVar4;
  uint uVar5;
  undefined1 *puVar6;
  longlong lVar7;
  byte *lpsz_01;
  
  while( true ) {
    lpsz_01 = (byte *)*param_1;
    bVar1 = *lpsz_01;
    uVar5 = (uint)(char)bVar1;
    if ((((uVar5 != 9) && (uVar5 != 10)) && (uVar5 != 0xd)) && (uVar5 != 0x20)) break;
    pCVar2 = CharNextA((LPCSTR)lpsz_01);
    *param_1 = pCVar2;
  }
  if (bVar1 != 0) {
    puVar6 = param_2;
    if (bVar1 != 0x27) {
      do {
        cVar4 = (char)uVar5;
        if (((cVar4 == '\t') || (cVar4 == '\n')) || ((cVar4 == '\r' || (cVar4 == ' ')))) break;
        pCVar2 = CharNextA((LPCSTR)lpsz_01);
        *param_1 = pCVar2;
        uVar3 = (longlong)pCVar2 - (longlong)lpsz_01;
        if (param_2 + 0x1000 <= puVar6 + uVar3 + 1) {
          return 0x80020009;
        }
        if (0 < (int)uVar3) {
          lVar7 = (longlong)lpsz_01 - (longlong)puVar6;
          uVar3 = uVar3 & 0xffffffff;
          do {
            *puVar6 = puVar6[lVar7];
            puVar6 = puVar6 + 1;
            uVar3 = uVar3 - 1;
          } while (uVar3 != 0);
        }
        lpsz_01 = (byte *)*param_1;
        uVar5 = (uint)*lpsz_01;
      } while (*lpsz_01 != 0);
      *puVar6 = 0;
      return 0;
    }
    lpsz = CharNextA((LPCSTR)lpsz_01);
    *param_1 = lpsz;
    if (*lpsz == '\0') {
LAB_180033c82:
      if (*(char *)*param_1 != '\0') {
        *puVar6 = 0;
        pCVar2 = CharNextA((LPCSTR)*param_1);
        *param_1 = pCVar2;
        return 0;
      }
    }
    else {
      do {
        if ((*lpsz == '\'') && (pCVar2 = CharNextA(lpsz), *pCVar2 != '\'')) goto LAB_180033c82;
        lpsz_00 = (LPCSTR)*param_1;
        if (*lpsz_00 == '\'') {
          lpsz_00 = CharNextA(lpsz_00);
          *param_1 = lpsz_00;
        }
        pCVar2 = CharNextA(lpsz_00);
        *param_1 = pCVar2;
        uVar3 = (longlong)pCVar2 - (longlong)lpsz_00;
        if (param_2 + 0x1000 <= puVar6 + uVar3 + 1) {
          return 0x80020009;
        }
        if (0 < (int)uVar3) {
          lVar7 = (longlong)lpsz_00 - (longlong)puVar6;
          uVar3 = uVar3 & 0xffffffff;
          do {
            *puVar6 = puVar6[lVar7];
            puVar6 = puVar6 + 1;
            uVar3 = uVar3 - 1;
          } while (uVar3 != 0);
        }
        lpsz = (char *)*param_1;
      } while (*lpsz != '\0');
    }
  }
  return 0x80020009;
}

/* ---- FUNC 00033D20 FUN_180033d20 (1549 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 * FUN_180033d20(undefined8 *param_1,uchar *param_2,undefined8 *param_3)

{
  uchar uVar1;
  char cVar2;
  LPCWSTR pWVar3;
  errno_t eVar4;
  int iVar5;
  longlong lVar6;
  uchar *puVar7;
  LPSTR pCVar8;
  undefined8 *puVar9;
  LPSTR pCVar10;
  LPCSTR pCVar11;
  undefined8 uVar12;
  int *piVar13;
  undefined1 *puVar14;
  int iVar15;
  uint uVar16;
  ulonglong uVar17;
  undefined1 *pv;
  int iVar18;
  int iVar19;
  ulonglong uVar20;
  LPCSTR pCVar21;
  undefined1 *puVar22;
  ulonglong uVar23;
  bool bVar24;
  undefined1 auStack_b8 [32];
  char local_98;
  char local_97;
  char local_96;
  int local_90;
  uint local_8c;
  undefined1 *local_88;
  int local_80;
  undefined8 *local_78;
  undefined8 *local_70;
  uchar local_68 [32];
  ulonglong local_48;
  
  local_48 = DAT_180077818 ^ (ulonglong)auStack_b8;
  if ((param_2 == (uchar *)0x0) || (param_3 == (undefined8 *)0x0)) {
    puVar22 = (undefined1 *)0x80004003;
  }
  else {
    iVar5 = 0;
    *param_3 = 0;
    lVar6 = -1;
    do {
      lVar6 = lVar6 + 1;
    } while (param_2[lVar6] != '\0');
    local_8c = (int)lVar6 * 2;
    local_90 = 0;
    if ((int)local_8c < 100) {
      local_8c = 1000;
    }
    uVar17 = (ulonglong)local_8c;
    local_78 = param_1;
    local_70 = param_3;
    local_88 = CoTaskMemAlloc((ulonglong)local_8c);
    pv = local_88;
    if (local_88 == (undefined1 *)0x0) {
LAB_180033dbd:
      puVar22 = (undefined1 *)0x8007000e;
    }
    else {
      *local_88 = 0;
      *param_1 = param_2;
      local_80 = 0;
      local_97 = '\0';
      local_98 = '\0';
      uVar1 = *param_2;
      iVar15 = local_80;
      local_96 = DAT_180079860;
      while (local_80 = iVar15, uVar1 != '\0') {
        if (local_96 == '\x01') {
          if (((iVar15 == 0) && (puVar7 = _mbsstr(param_2,"HKCR"), puVar7 != (uchar *)0x0)) &&
             (puVar7 == (uchar *)*param_1)) {
            pCVar8 = CharNextA((LPCSTR)*param_1);
            *param_1 = pCVar8;
            pCVar8 = CharNextA(pCVar8);
            *param_1 = pCVar8;
            pCVar8 = CharNextA(pCVar8);
            *param_1 = pCVar8;
            pCVar8 = CharNextA(pCVar8);
            *param_1 = pCVar8;
            puVar9 = FUN_1800329e0(&local_90,L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses");
            pv = local_88;
            if ((int)puVar9 == 0) goto LAB_180033dbd;
            local_97 = '\x01';
            uVar17 = (ulonglong)local_8c;
            iVar5 = local_90;
          }
          cVar2 = local_97;
          if (*(LPCSTR)*param_1 == '\'') {
            if (local_98 == '\0') {
              local_98 = '\x01';
              goto LAB_180033ff1;
            }
            pCVar8 = CharNextA((LPCSTR)*param_1);
            if (*pCVar8 != '\'') {
              local_98 = '\0';
              goto LAB_180033f9f;
            }
            pCVar8 = CharNextA((LPCSTR)*param_1);
            *param_1 = pCVar8;
            pCVar10 = CharNextA(pCVar8);
            iVar18 = (int)pCVar10 - (int)pCVar8;
            iVar19 = iVar5 + iVar18;
            iVar15 = iVar19 + 1;
            if ((iVar5 < iVar15) && (iVar18 < iVar15)) {
              puVar22 = pv;
              puVar14 = local_88;
              if ((int)uVar17 <= iVar15) {
                do {
                  if (0x3fffffff < (int)uVar17) goto LAB_180033dbd;
                  local_8c = (int)uVar17 * 2;
                  uVar17 = (ulonglong)local_8c;
                } while ((int)local_8c <= iVar15);
                puVar22 = CoTaskMemRealloc(pv,uVar17);
                puVar14 = puVar22;
                if (puVar22 == (undefined1 *)0x0) goto LAB_180033dbd;
              }
              local_88 = puVar14;
              pv = puVar22;
              if (((-1 < iVar5) && (iVar15 = (int)uVar17, iVar5 < iVar15)) &&
                 (iVar15 - iVar5 <= iVar15)) {
                uVar20 = (ulonglong)iVar18;
                uVar23 = (ulonglong)(iVar15 - iVar5);
                puVar14 = puVar22 + iVar5;
                if (uVar20 == 0) {
LAB_180033f83:
                  puVar22[iVar19] = 0;
                  param_1 = local_78;
                  iVar5 = iVar19;
                  local_90 = iVar19;
                  goto LAB_180033ff1;
                }
                if (puVar14 == (undefined1 *)0x0) goto LAB_18003430a;
                if ((pCVar8 != (LPSTR)0x0) && (uVar20 <= uVar23)) {
                  memcpy(puVar14,pCVar8,uVar20);
                  goto LAB_180033f83;
                }
                memset(puVar14,0,uVar23);
                if (pCVar8 == (LPSTR)0x0) goto LAB_18003430a;
                bVar24 = uVar23 < uVar20;
LAB_180034279:
                if (!bVar24) goto LAB_18003431c;
                piVar13 = _errno();
                *piVar13 = 0x22;
LAB_180034316:
                _invalid_parameter_noinfo();
LAB_18003431c:
                    /* WARNING: Subroutine does not return */
                AfxThrowInvalidArgException();
              }
            }
            goto LAB_180033dbd;
          }
          if (local_98 != '\0') goto LAB_180033ff1;
LAB_180033f9f:
          if (*(char *)*param_1 == '{') {
            local_80 = local_80 + 1;
          }
          else {
            local_80 = iVar15;
            if (((*(char *)*param_1 == '}') && (local_80 = iVar15 + -1, local_80 == 0)) &&
               (cVar2 == '\x01')) {
              puVar9 = FUN_1800329e0(&local_90,L"\r\n\t}\r\n}\r\n");
              pv = local_88;
              if ((int)puVar9 == 0) goto LAB_180033dbd;
              local_97 = '\0';
              uVar17 = (ulonglong)local_8c;
              iVar5 = local_90;
            }
          }
        }
LAB_180033ff1:
        pCVar11 = (LPCSTR)*param_1;
        if (*pCVar11 == '%') {
          pCVar11 = CharNextA(pCVar11);
          *param_1 = pCVar11;
          cVar2 = *pCVar11;
          if (cVar2 != '%') {
            if (pCVar11 != (LPSTR)0x0) {
              while ((pCVar21 = (LPCSTR)0x0, cVar2 != '\0' && (pCVar21 = pCVar11, cVar2 != '%'))) {
                pCVar11 = CharNextA(pCVar11);
                cVar2 = *pCVar11;
              }
              if (pCVar21 != (LPCSTR)0x0) {
                puVar7 = (uchar *)*param_1;
                if (0x1f < (longlong)pCVar21 - (longlong)puVar7) {
                  puVar22 = (undefined1 *)0x80004005;
                  goto LAB_1800342c5;
                }
                eVar4 = _mbsnbcpy_s(local_68,0x20,puVar7,(longlong)((int)pCVar21 - (int)puVar7));
                if (eVar4 != 0) {
                  if (eVar4 == 0xc) {
                    /* WARNING: Subroutine does not return */
                    AfxThrowMemoryException();
                  }
                  if (eVar4 != 0x50) {
                    /* WARNING: Subroutine does not return */
                    AfxThrowInvalidArgException();
                  }
                }
                lVar6 = param_1[1];
                EnterCriticalSection((LPCRITICAL_SECTION)(lVar6 + 0x20));
                uVar20 = 0;
                uVar17 = uVar20;
                if (0 < *(int *)(lVar6 + 0x18)) {
                  while( true ) {
                    iVar5 = lstrcmpiA(*(LPCSTR *)(*(longlong *)(lVar6 + 8) + uVar17 * 8),
                                      (LPCSTR)local_68);
                    if (iVar5 == 0) break;
                    uVar16 = (int)uVar20 + 1;
                    uVar20 = (ulonglong)uVar16;
                    uVar17 = uVar17 + 1;
                    if (*(int *)(lVar6 + 0x18) <= (int)uVar16) goto LAB_1800341a0;
                  }
                  if (uVar17 != 0xffffffffffffffff) {
                    if (((longlong)uVar17 < 0) || (*(int *)(lVar6 + 0x18) <= (int)uVar20)) {
                    /* WARNING: Subroutine does not return */
                      FUN_180001a90(-0x7ffffff5);
                    }
                    pWVar3 = *(LPCWSTR *)(*(longlong *)(lVar6 + 0x10) + uVar17 * 8);
                    LeaveCriticalSection((LPCRITICAL_SECTION)(lVar6 + 0x20));
                    if (pWVar3 != (LPCWSTR)0x0) {
                      puVar9 = FUN_1800329e0(&local_90,pWVar3);
                      if ((int)puVar9 == 0) goto LAB_1800342a4;
                      pCVar11 = (LPCSTR)*param_1;
                      while (pCVar11 != pCVar21) {
                        pCVar11 = CharNextA(pCVar11);
                        *param_1 = pCVar11;
                      }
                      goto LAB_180034230;
                    }
                    goto LAB_1800341aa;
                  }
                }
LAB_1800341a0:
                LeaveCriticalSection((LPCRITICAL_SECTION)(lVar6 + 0x20));
              }
            }
LAB_1800341aa:
            puVar22 = (undefined1 *)0x80020009;
            goto LAB_1800342c5;
          }
          pCVar8 = CharNextA(pCVar11);
          iVar19 = (int)pCVar8 - (int)pCVar11;
          iVar18 = iVar5 + iVar19;
          iVar15 = iVar18 + 1;
          if ((iVar15 <= iVar5) || (iVar15 <= iVar19)) goto LAB_180033dbd;
          puVar22 = pv;
          puVar14 = local_88;
          if ((int)uVar17 <= iVar15) {
            do {
              if (0x3fffffff < (int)uVar17) goto LAB_180033dbd;
              local_8c = (int)uVar17 * 2;
              uVar17 = (ulonglong)local_8c;
            } while ((int)local_8c <= iVar15);
            puVar22 = CoTaskMemRealloc(pv,uVar17);
            puVar14 = puVar22;
            if (puVar22 == (undefined1 *)0x0) goto LAB_180033dbd;
          }
          local_88 = puVar14;
          pv = puVar22;
          if (((iVar5 < 0) || (iVar15 = (int)uVar17, iVar15 <= iVar5)) || (iVar15 < iVar15 - iVar5))
          goto LAB_180033dbd;
          uVar20 = (ulonglong)iVar19;
          uVar23 = (ulonglong)(iVar15 - iVar5);
          puVar14 = puVar22 + iVar5;
          if (uVar20 != 0) {
            if (puVar14 != (undefined1 *)0x0) {
              if ((pCVar11 != (LPSTR)0x0) && (uVar20 <= uVar23)) {
                memcpy(puVar14,pCVar11,uVar20);
                goto LAB_1800340d3;
              }
              memset(puVar14,0,uVar23);
              if (pCVar11 != (LPSTR)0x0) {
                bVar24 = uVar23 < uVar20;
                goto LAB_180034279;
              }
            }
LAB_18003430a:
            piVar13 = _errno();
            *piVar13 = 0x16;
            goto LAB_180034316;
          }
LAB_1800340d3:
          puVar22[iVar18] = 0;
          param_1 = local_78;
          local_90 = iVar18;
        }
        else {
          pCVar8 = CharNextA(pCVar11);
          uVar12 = FUN_1800332b0(&local_90,pCVar11,(int)pCVar8 - (int)pCVar11);
          if ((int)uVar12 == 0) {
LAB_1800342a4:
            puVar22 = (undefined1 *)0x8007000e;
            pv = local_88;
            goto LAB_1800342c5;
          }
LAB_180034230:
          uVar17 = (ulonglong)local_8c;
          pv = local_88;
        }
        iVar5 = local_90;
        param_2 = (uchar *)CharNextA((LPCSTR)*param_1);
        *param_1 = param_2;
        iVar15 = local_80;
        uVar1 = *param_2;
      }
      puVar22 = (undefined1 *)0x0;
      *local_70 = pv;
      pv = puVar22;
    }
LAB_1800342c5:
    CoTaskMemFree(pv);
  }
  return puVar22;
}

/* ---- FUNC 00034330 FUN_180034330 (397 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180034330(undefined8 *param_1,LPCSTR param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined1 auStackY_1a8 [32];
  DWORD local_168 [2];
  HKEY local_160;
  uint local_158;
  undefined8 local_150;
  HKEY local_148;
  _FILETIME local_140;
  CHAR local_138 [256];
  ulonglong local_38;
  
  local_38 = DAT_180077818 ^ (ulonglong)auStackY_1a8;
  uVar1 = *(uint *)(param_1 + 1);
  uVar4 = 0;
  local_160 = (HKEY)0x0;
  local_158 = 0;
  local_150 = 0;
  local_148 = (HKEY)0x0;
  uVar2 = RegOpenKeyExA((HKEY)*param_1,param_2,0,uVar1 | 0x2001f,&local_148);
  uVar5 = (ulonglong)uVar2;
  if (uVar2 == 0) {
    if (local_160 != (HKEY)0x0) {
      uVar2 = RegCloseKey(local_160);
      uVar4 = (ulonglong)uVar2;
    }
    local_158 = uVar1 & 0x300;
    local_160 = local_148;
    uVar5 = uVar4;
  }
  if ((int)uVar5 == 0) {
    local_168[0] = 0x100;
    iVar3 = RegEnumKeyExA(local_160,0,local_138,local_168,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,
                          &local_140);
    while (iVar3 == 0) {
      uVar4 = FUN_180034330(&local_160,local_138);
      uVar5 = uVar4 & 0xffffffff;
      if ((int)uVar4 != 0) goto LAB_18003448d;
      local_168[0] = 0x100;
      iVar3 = RegEnumKeyExA(local_160,0,local_138,local_168,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,
                            &local_140);
    }
    if (local_160 != (HKEY)0x0) {
      RegCloseKey(local_160);
      local_160 = (HKEY)0x0;
    }
    local_158 = 0;
    uVar5 = FUN_180033870(param_1,param_2);
    uVar5 = uVar5 & 0xffffffff;
  }
LAB_18003448d:
  if (local_160 != (HKEY)0x0) {
    RegCloseKey(local_160);
  }
  return uVar5;
}

/* ---- FUNC 000344C0 FUN_1800344c0 (72 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 * FUN_1800344c0(undefined8 *param_1,uchar *param_2,int param_3)

{
  byte bVar1;
  HKEY pHVar2;
  undefined8 uVar3;
  byte *pv;
  int iVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  LPSTR pCVar7;
  LPCSTR pCVar8;
  byte *pbVar9;
  char cVar10;
  uint uVar11;
  ulonglong uVar12;
  uchar *puVar13;
  ulonglong uVar14;
  longlong lVar15;
  undefined **ppuVar16;
  undefined1 auStackY_1088 [32];
  byte *local_1058 [2];
  uchar local_1048 [4096];
  ulonglong local_48 [2];
  
  local_48[0] = DAT_180077818 ^ (ulonglong)auStackY_1088;
  local_1058[0] = (byte *)0x0;
  puVar5 = FUN_180033d20(param_1,param_2,local_1058);
  pv = local_1058[0];
  if (-1 < (int)puVar5) {
    *param_1 = local_1058[0];
    bVar1 = *local_1058[0];
    puVar5 = (undefined1 *)((ulonglong)puVar5 & 0xffffffff);
    pbVar6 = local_1058[0];
    while (bVar1 != 0) {
      puVar13 = local_1048;
      while( true ) {
        bVar1 = *pbVar6;
        uVar11 = (uint)(char)bVar1;
        if ((((uVar11 != 9) && (uVar11 != 10)) && (uVar11 != 0xd)) && (uVar11 != 0x20)) break;
        pbVar6 = (byte *)CharNextA((LPCSTR)pbVar6);
        *param_1 = pbVar6;
      }
      if (bVar1 == 0) {
LAB_1800346d0:
        puVar5 = (undefined1 *)0x80020009;
        break;
      }
      if (bVar1 == 0x27) {
        pCVar7 = CharNextA((LPCSTR)pbVar6);
        *param_1 = pCVar7;
        cVar10 = *pCVar7;
        while ((cVar10 != '\0' &&
               ((*(LPCSTR)*param_1 != '\'' ||
                (pCVar7 = CharNextA((LPCSTR)*param_1), *pCVar7 == '\''))))) {
          pCVar8 = (LPCSTR)*param_1;
          if (*pCVar8 == '\'') {
            pCVar8 = CharNextA(pCVar8);
            *param_1 = pCVar8;
          }
          pCVar7 = CharNextA(pCVar8);
          *param_1 = pCVar7;
          uVar12 = (longlong)pCVar7 - (longlong)pCVar8;
          if (local_48 <= puVar13 + uVar12 + 1) goto LAB_1800346d0;
          if (0 < (int)uVar12) {
            lVar15 = (longlong)pCVar8 - (longlong)puVar13;
            uVar12 = uVar12 & 0xffffffff;
            do {
              *puVar13 = puVar13[lVar15];
              puVar13 = puVar13 + 1;
              uVar12 = uVar12 - 1;
            } while (uVar12 != 0);
          }
          cVar10 = *pCVar7;
        }
        pCVar8 = (LPCSTR)*param_1;
        if (*pCVar8 == '\0') goto LAB_1800346d0;
        *puVar13 = '\0';
        pCVar7 = CharNextA(pCVar8);
        *param_1 = pCVar7;
      }
      else {
        do {
          cVar10 = (char)uVar11;
          if (((cVar10 == '\t') || (cVar10 == '\n')) || ((cVar10 == '\r' || (cVar10 == ' '))))
          break;
          pbVar9 = (byte *)CharNextA((LPCSTR)pbVar6);
          *param_1 = pbVar9;
          uVar12 = (longlong)pbVar9 - (longlong)pbVar6;
          if (local_48 <= puVar13 + uVar12 + 1) goto LAB_1800346d0;
          if (0 < (int)uVar12) {
            lVar15 = (longlong)pbVar6 - (longlong)puVar13;
            uVar12 = uVar12 & 0xffffffff;
            do {
              *puVar13 = puVar13[lVar15];
              puVar13 = puVar13 + 1;
              uVar12 = uVar12 - 1;
            } while (uVar12 != 0);
          }
          uVar11 = (uint)*pbVar9;
          pbVar6 = pbVar9;
        } while (*pbVar9 != 0);
        *puVar13 = '\0';
      }
      ppuVar16 = &PTR_DAT_180065210;
      uVar12 = 0;
      uVar14 = 0;
      while (iVar4 = lstrcmpiA((LPCSTR)local_1048,*ppuVar16), iVar4 != 0) {
        uVar11 = (int)uVar12 + 1;
        uVar12 = (ulonglong)uVar11;
        uVar14 = uVar14 + 1;
        ppuVar16 = ppuVar16 + 2;
        if (0xd < uVar11) goto LAB_1800346d0;
      }
      pHVar2 = (HKEY)(&DAT_180065218)[uVar14 * 2];
      if (pHVar2 == (HKEY)0x0) goto LAB_1800346d0;
      puVar13 = local_1048;
      while( true ) {
        pbVar6 = (byte *)*param_1;
        bVar1 = *pbVar6;
        uVar11 = (uint)(char)bVar1;
        if ((((uVar11 != 9) && (uVar11 != 10)) && (uVar11 != 0xd)) && (uVar11 != 0x20)) break;
        pCVar7 = CharNextA((LPCSTR)pbVar6);
        *param_1 = pCVar7;
      }
      if (bVar1 == 0) goto LAB_1800346d0;
      if (bVar1 == 0x27) {
        pCVar7 = CharNextA((LPCSTR)pbVar6);
        *param_1 = pCVar7;
        cVar10 = *pCVar7;
        while ((cVar10 != '\0' &&
               ((*(LPCSTR)*param_1 != '\'' ||
                (pCVar7 = CharNextA((LPCSTR)*param_1), *pCVar7 == '\''))))) {
          pCVar8 = (LPCSTR)*param_1;
          if (*pCVar8 == '\'') {
            pCVar8 = CharNextA(pCVar8);
            *param_1 = pCVar8;
          }
          pCVar7 = CharNextA(pCVar8);
          *param_1 = pCVar7;
          uVar12 = (longlong)pCVar7 - (longlong)pCVar8;
          if (local_48 <= puVar13 + uVar12 + 1) goto LAB_1800346d0;
          if (0 < (int)uVar12) {
            lVar15 = (longlong)pCVar8 - (longlong)puVar13;
            uVar12 = uVar12 & 0xffffffff;
            do {
              *puVar13 = puVar13[lVar15];
              puVar13 = puVar13 + 1;
              uVar12 = uVar12 - 1;
            } while (uVar12 != 0);
          }
          cVar10 = *pCVar7;
        }
        pCVar8 = (LPCSTR)*param_1;
        if (*pCVar8 == '\0') goto LAB_1800346d0;
        *puVar13 = '\0';
        pCVar7 = CharNextA(pCVar8);
        *param_1 = pCVar7;
      }
      else {
        do {
          cVar10 = (char)uVar11;
          if (((cVar10 == '\t') || (cVar10 == '\n')) || ((cVar10 == '\r' || (cVar10 == ' '))))
          break;
          pbVar9 = (byte *)CharNextA((LPCSTR)pbVar6);
          *param_1 = pbVar9;
          uVar12 = (longlong)pbVar9 - (longlong)pbVar6;
          if (local_48 <= puVar13 + uVar12 + 1) goto LAB_1800346d0;
          if (0 < (int)uVar12) {
            lVar15 = (longlong)pbVar6 - (longlong)puVar13;
            uVar12 = uVar12 & 0xffffffff;
            do {
              *puVar13 = puVar13[lVar15];
              puVar13 = puVar13 + 1;
              uVar12 = uVar12 - 1;
            } while (uVar12 != 0);
          }
          uVar11 = (uint)*pbVar9;
          pbVar6 = pbVar9;
        } while (*pbVar9 != 0);
        *puVar13 = '\0';
      }
      if (local_1048[0] != '{') goto LAB_1800346d0;
      if (param_3 == 0) {
        uVar12 = FUN_180034c40(param_1,local_1048,pHVar2,0,0);
        puVar5 = (undefined1 *)(uVar12 & 0xffffffff);
        if ((int)uVar12 < 0) break;
      }
      else {
        uVar3 = *param_1;
        uVar12 = FUN_180034c40(param_1,local_1048,pHVar2,param_3,0);
        puVar5 = (undefined1 *)(uVar12 & 0xffffffff);
        if ((int)uVar12 < 0) {
          *param_1 = uVar3;
          FUN_180034c40(param_1,local_1048,pHVar2,0,0);
          break;
        }
      }
      while( true ) {
        pbVar6 = (byte *)*param_1;
        bVar1 = *pbVar6;
        if ((((bVar1 != 9) && (bVar1 != 10)) && (bVar1 != 0xd)) && (bVar1 != 0x20)) break;
        pCVar7 = CharNextA((LPCSTR)pbVar6);
        *param_1 = pCVar7;
      }
    }
    CoTaskMemFree(pv);
  }
  return puVar5;
}

/* ---- FUNC 00034508 FUN_180034508 (25 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180034508(void)

{
  byte bVar1;
  HKEY pHVar2;
  undefined8 uVar3;
  int iVar4;
  byte *pbVar5;
  LPSTR pCVar6;
  LPCSTR pCVar7;
  byte *pbVar8;
  char cVar9;
  uint uVar10;
  ulonglong uVar11;
  ulonglong unaff_RBX;
  byte *pbVar12;
  ulonglong uVar13;
  undefined8 *unaff_RSI;
  longlong lVar14;
  undefined **ppuVar15;
  byte bVar16;
  int iVar17;
  ulonglong unaff_R12;
  int unaff_R14D;
  byte *in_stack_00000030;
  byte in_stack_00000040;
  
  *unaff_RSI = in_stack_00000030;
  bVar16 = (byte)unaff_R12;
  pbVar5 = in_stack_00000030;
  if (*in_stack_00000030 != bVar16) {
    do {
      pbVar12 = &stack0x00000040;
      while( true ) {
        bVar1 = *pbVar5;
        uVar10 = (uint)(char)bVar1;
        if ((((uVar10 != 9) && (uVar10 != 10)) && (uVar10 != 0xd)) && (uVar10 != 0x20)) break;
        pbVar5 = (byte *)CharNextA((LPCSTR)pbVar5);
        *unaff_RSI = pbVar5;
      }
      if (bVar1 == 0) {
LAB_1800346d0:
        unaff_RBX = 0x80020009;
        break;
      }
      if (bVar1 == 0x27) {
        pbVar5 = (byte *)CharNextA((LPCSTR)pbVar5);
        *unaff_RSI = pbVar5;
        bVar1 = *pbVar5;
        while ((bVar1 != bVar16 &&
               ((*(LPCSTR)*unaff_RSI != '\'' ||
                (pCVar6 = CharNextA((LPCSTR)*unaff_RSI), *pCVar6 == '\''))))) {
          pCVar7 = (LPCSTR)*unaff_RSI;
          if (*pCVar7 == '\'') {
            pCVar7 = CharNextA(pCVar7);
            *unaff_RSI = pCVar7;
          }
          pbVar5 = (byte *)CharNextA(pCVar7);
          *unaff_RSI = pbVar5;
          uVar11 = (longlong)pbVar5 - (longlong)pCVar7;
          if (&stack0x00001040 <= pbVar12 + uVar11 + 1) goto LAB_1800346d0;
          if (0 < (int)uVar11) {
            lVar14 = (longlong)pCVar7 - (longlong)pbVar12;
            uVar11 = uVar11 & 0xffffffff;
            do {
              *pbVar12 = pbVar12[lVar14];
              pbVar12 = pbVar12 + 1;
              uVar11 = uVar11 - 1;
            } while (uVar11 != 0);
          }
          bVar1 = *pbVar5;
        }
        pbVar5 = (byte *)*unaff_RSI;
        if (*pbVar5 == bVar16) goto LAB_1800346d0;
        *pbVar12 = bVar16;
        pCVar6 = CharNextA((LPCSTR)pbVar5);
        *unaff_RSI = pCVar6;
      }
      else {
        do {
          cVar9 = (char)uVar10;
          if (((cVar9 == '\t') || (cVar9 == '\n')) || ((cVar9 == '\r' || (cVar9 == ' ')))) break;
          pbVar8 = (byte *)CharNextA((LPCSTR)pbVar5);
          *unaff_RSI = pbVar8;
          uVar11 = (longlong)pbVar8 - (longlong)pbVar5;
          if (&stack0x00001040 <= pbVar12 + uVar11 + 1) goto LAB_1800346d0;
          if (0 < (int)uVar11) {
            lVar14 = (longlong)pbVar5 - (longlong)pbVar12;
            uVar11 = uVar11 & 0xffffffff;
            do {
              *pbVar12 = pbVar12[lVar14];
              pbVar12 = pbVar12 + 1;
              uVar11 = uVar11 - 1;
            } while (uVar11 != 0);
          }
          uVar10 = (uint)*pbVar8;
          pbVar5 = pbVar8;
        } while (*pbVar8 != 0);
        *pbVar12 = bVar16;
      }
      iVar17 = (int)unaff_R12;
      uVar13 = unaff_R12 & 0xffffffff;
      ppuVar15 = &PTR_DAT_180065210;
      uVar11 = unaff_R12;
      while (iVar4 = lstrcmpiA((LPCSTR)&stack0x00000040,*ppuVar15), iVar4 != 0) {
        uVar10 = (int)uVar13 + 1;
        uVar13 = (ulonglong)uVar10;
        uVar11 = uVar11 + 1;
        ppuVar15 = ppuVar15 + 2;
        if (0xd < uVar10) goto LAB_1800346d0;
      }
      pHVar2 = (HKEY)(&DAT_180065218)[uVar11 * 2];
      if (pHVar2 == (HKEY)0x0) goto LAB_1800346d0;
      pbVar5 = &stack0x00000040;
      while( true ) {
        pbVar12 = (byte *)*unaff_RSI;
        bVar1 = *pbVar12;
        uVar10 = (uint)(char)bVar1;
        if ((((uVar10 != 9) && (uVar10 != 10)) && (uVar10 != 0xd)) && (uVar10 != 0x20)) break;
        pCVar6 = CharNextA((LPCSTR)pbVar12);
        *unaff_RSI = pCVar6;
      }
      if (bVar1 == 0) goto LAB_1800346d0;
      if (bVar1 == 0x27) {
        pbVar12 = (byte *)CharNextA((LPCSTR)pbVar12);
        *unaff_RSI = pbVar12;
        bVar1 = *pbVar12;
        while ((bVar1 != bVar16 &&
               ((*(LPCSTR)*unaff_RSI != '\'' ||
                (pCVar6 = CharNextA((LPCSTR)*unaff_RSI), *pCVar6 == '\''))))) {
          pCVar7 = (LPCSTR)*unaff_RSI;
          if (*pCVar7 == '\'') {
            pCVar7 = CharNextA(pCVar7);
            *unaff_RSI = pCVar7;
          }
          pbVar12 = (byte *)CharNextA(pCVar7);
          *unaff_RSI = pbVar12;
          uVar11 = (longlong)pbVar12 - (longlong)pCVar7;
          if (&stack0x00001040 <= pbVar5 + uVar11 + 1) goto LAB_1800346d0;
          if (0 < (int)uVar11) {
            lVar14 = (longlong)pCVar7 - (longlong)pbVar5;
            uVar11 = uVar11 & 0xffffffff;
            do {
              *pbVar5 = pbVar5[lVar14];
              pbVar5 = pbVar5 + 1;
              uVar11 = uVar11 - 1;
            } while (uVar11 != 0);
          }
          bVar1 = *pbVar12;
        }
        pbVar12 = (byte *)*unaff_RSI;
        if (*pbVar12 == bVar16) goto LAB_1800346d0;
        *pbVar5 = bVar16;
        pCVar6 = CharNextA((LPCSTR)pbVar12);
        *unaff_RSI = pCVar6;
      }
      else {
        do {
          cVar9 = (char)uVar10;
          if (((cVar9 == '\t') || (cVar9 == '\n')) || ((cVar9 == '\r' || (cVar9 == ' ')))) break;
          pbVar8 = (byte *)CharNextA((LPCSTR)pbVar12);
          *unaff_RSI = pbVar8;
          uVar11 = (longlong)pbVar8 - (longlong)pbVar12;
          if (&stack0x00001040 <= pbVar5 + uVar11 + 1) goto LAB_1800346d0;
          if (0 < (int)uVar11) {
            lVar14 = (longlong)pbVar12 - (longlong)pbVar5;
            uVar11 = uVar11 & 0xffffffff;
            do {
              *pbVar5 = pbVar5[lVar14];
              pbVar5 = pbVar5 + 1;
              uVar11 = uVar11 - 1;
            } while (uVar11 != 0);
          }
          uVar10 = (uint)*pbVar8;
          pbVar12 = pbVar8;
        } while (*pbVar8 != 0);
        *pbVar5 = bVar16;
      }
      if (in_stack_00000040 != 0x7b) goto LAB_1800346d0;
      if (unaff_R14D == 0) {
        uVar11 = FUN_180034c40(unaff_RSI,&stack0x00000040,pHVar2,0,iVar17);
        unaff_RBX = uVar11 & 0xffffffff;
        if ((int)uVar11 < 0) break;
      }
      else {
        uVar3 = *unaff_RSI;
        uVar11 = FUN_180034c40(unaff_RSI,&stack0x00000040,pHVar2,unaff_R14D,iVar17);
        unaff_RBX = uVar11 & 0xffffffff;
        if ((int)uVar11 < 0) {
          *unaff_RSI = uVar3;
          FUN_180034c40(unaff_RSI,&stack0x00000040,pHVar2,0,iVar17);
          break;
        }
      }
      while( true ) {
        pbVar5 = (byte *)*unaff_RSI;
        bVar1 = *pbVar5;
        if ((((bVar1 != 9) && (bVar1 != 10)) && (bVar1 != 0xd)) && (bVar1 != 0x20)) break;
        pCVar6 = CharNextA((LPCSTR)pbVar5);
        *unaff_RSI = pCVar6;
      }
    } while (bVar1 != 0);
  }
  CoTaskMemFree(in_stack_00000030);
  return unaff_RBX & 0xffffffff;
}

/* ---- FUNC 00034521 FUN_180034521 (460 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180034521(void)

{
  byte bVar1;
  HKEY pHVar2;
  undefined8 uVar3;
  int iVar4;
  byte *pbVar5;
  LPSTR pCVar6;
  LPCSTR pCVar7;
  byte *pbVar8;
  ulonglong uVar9;
  char cVar10;
  uint uVar11;
  ulonglong uVar12;
  char *pcVar13;
  undefined8 *unaff_RSI;
  longlong lVar14;
  undefined **ppuVar15;
  char cVar16;
  int iVar17;
  ulonglong unaff_R12;
  int unaff_R14D;
  byte *unaff_R15;
  uchar in_stack_00000040;
  
  pbVar5 = unaff_R15;
  do {
    pcVar13 = (char *)&stack0x00000040;
    while( true ) {
      bVar1 = *pbVar5;
      uVar11 = (uint)(char)bVar1;
      if ((((uVar11 != 9) && (uVar11 != 10)) && (uVar11 != 0xd)) && (uVar11 != 0x20)) break;
      pbVar5 = (byte *)CharNextA((LPCSTR)pbVar5);
      *unaff_RSI = pbVar5;
    }
    if (bVar1 == 0) {
LAB_1800346d0:
      uVar12 = 0x80020009;
      break;
    }
    cVar16 = (char)unaff_R12;
    if (bVar1 == 0x27) {
      pCVar6 = CharNextA((LPCSTR)pbVar5);
      *unaff_RSI = pCVar6;
      cVar10 = *pCVar6;
      while ((cVar10 != cVar16 &&
             ((*(LPCSTR)*unaff_RSI != '\'' ||
              (pCVar6 = CharNextA((LPCSTR)*unaff_RSI), *pCVar6 == '\''))))) {
        pCVar7 = (LPCSTR)*unaff_RSI;
        if (*pCVar7 == '\'') {
          pCVar7 = CharNextA(pCVar7);
          *unaff_RSI = pCVar7;
        }
        pCVar6 = CharNextA(pCVar7);
        *unaff_RSI = pCVar6;
        uVar12 = (longlong)pCVar6 - (longlong)pCVar7;
        if (&stack0x00001040 <= pcVar13 + uVar12 + 1) goto LAB_1800346d0;
        if (0 < (int)uVar12) {
          lVar14 = (longlong)pCVar7 - (longlong)pcVar13;
          uVar12 = uVar12 & 0xffffffff;
          do {
            *pcVar13 = pcVar13[lVar14];
            pcVar13 = pcVar13 + 1;
            uVar12 = uVar12 - 1;
          } while (uVar12 != 0);
        }
        cVar10 = *pCVar6;
      }
      pCVar7 = (LPCSTR)*unaff_RSI;
      if (*pCVar7 == cVar16) goto LAB_1800346d0;
      *pcVar13 = cVar16;
      pCVar6 = CharNextA(pCVar7);
      *unaff_RSI = pCVar6;
    }
    else {
      do {
        cVar10 = (char)uVar11;
        if (((cVar10 == '\t') || (cVar10 == '\n')) || ((cVar10 == '\r' || (cVar10 == ' ')))) break;
        pbVar8 = (byte *)CharNextA((LPCSTR)pbVar5);
        *unaff_RSI = pbVar8;
        uVar12 = (longlong)pbVar8 - (longlong)pbVar5;
        if (&stack0x00001040 <= pcVar13 + uVar12 + 1) goto LAB_1800346d0;
        if (0 < (int)uVar12) {
          lVar14 = (longlong)pbVar5 - (longlong)pcVar13;
          uVar12 = uVar12 & 0xffffffff;
          do {
            *pcVar13 = pcVar13[lVar14];
            pcVar13 = pcVar13 + 1;
            uVar12 = uVar12 - 1;
          } while (uVar12 != 0);
        }
        uVar11 = (uint)*pbVar8;
        pbVar5 = pbVar8;
      } while (*pbVar8 != 0);
      *pcVar13 = cVar16;
    }
    iVar17 = (int)unaff_R12;
    uVar9 = unaff_R12 & 0xffffffff;
    ppuVar15 = &PTR_DAT_180065210;
    uVar12 = unaff_R12;
    while (iVar4 = lstrcmpiA((LPCSTR)&stack0x00000040,*ppuVar15), iVar4 != 0) {
      uVar11 = (int)uVar9 + 1;
      uVar9 = (ulonglong)uVar11;
      uVar12 = uVar12 + 1;
      ppuVar15 = ppuVar15 + 2;
      if (0xd < uVar11) goto LAB_1800346d0;
    }
    pHVar2 = (HKEY)(&DAT_180065218)[uVar12 * 2];
    if (pHVar2 == (HKEY)0x0) goto LAB_1800346d0;
    pcVar13 = (char *)&stack0x00000040;
    while( true ) {
      pbVar5 = (byte *)*unaff_RSI;
      bVar1 = *pbVar5;
      uVar11 = (uint)(char)bVar1;
      if ((((uVar11 != 9) && (uVar11 != 10)) && (uVar11 != 0xd)) && (uVar11 != 0x20)) break;
      pCVar6 = CharNextA((LPCSTR)pbVar5);
      *unaff_RSI = pCVar6;
    }
    if (bVar1 == 0) goto LAB_1800346d0;
    if (bVar1 == 0x27) {
      pCVar6 = CharNextA((LPCSTR)pbVar5);
      *unaff_RSI = pCVar6;
      cVar10 = *pCVar6;
      while ((cVar10 != cVar16 &&
             ((*(LPCSTR)*unaff_RSI != '\'' ||
              (pCVar6 = CharNextA((LPCSTR)*unaff_RSI), *pCVar6 == '\''))))) {
        pCVar7 = (LPCSTR)*unaff_RSI;
        if (*pCVar7 == '\'') {
          pCVar7 = CharNextA(pCVar7);
          *unaff_RSI = pCVar7;
        }
        pCVar6 = CharNextA(pCVar7);
        *unaff_RSI = pCVar6;
        uVar12 = (longlong)pCVar6 - (longlong)pCVar7;
        if (&stack0x00001040 <= pcVar13 + uVar12 + 1) goto LAB_1800346d0;
        if (0 < (int)uVar12) {
          lVar14 = (longlong)pCVar7 - (longlong)pcVar13;
          uVar12 = uVar12 & 0xffffffff;
          do {
            *pcVar13 = pcVar13[lVar14];
            pcVar13 = pcVar13 + 1;
            uVar12 = uVar12 - 1;
          } while (uVar12 != 0);
        }
        cVar10 = *pCVar6;
      }
      pCVar7 = (LPCSTR)*unaff_RSI;
      if (*pCVar7 == cVar16) goto LAB_1800346d0;
      *pcVar13 = cVar16;
      pCVar6 = CharNextA(pCVar7);
      *unaff_RSI = pCVar6;
    }
    else {
      do {
        cVar10 = (char)uVar11;
        if (((cVar10 == '\t') || (cVar10 == '\n')) || ((cVar10 == '\r' || (cVar10 == ' ')))) break;
        pbVar8 = (byte *)CharNextA((LPCSTR)pbVar5);
        *unaff_RSI = pbVar8;
        uVar12 = (longlong)pbVar8 - (longlong)pbVar5;
        if (&stack0x00001040 <= pcVar13 + uVar12 + 1) goto LAB_1800346d0;
        if (0 < (int)uVar12) {
          lVar14 = (longlong)pbVar5 - (longlong)pcVar13;
          uVar12 = uVar12 & 0xffffffff;
          do {
            *pcVar13 = pcVar13[lVar14];
            pcVar13 = pcVar13 + 1;
            uVar12 = uVar12 - 1;
          } while (uVar12 != 0);
        }
        uVar11 = (uint)*pbVar8;
        pbVar5 = pbVar8;
      } while (*pbVar8 != 0);
      *pcVar13 = cVar16;
    }
    if (in_stack_00000040 != '{') goto LAB_1800346d0;
    if (unaff_R14D == 0) {
      uVar9 = FUN_180034c40(unaff_RSI,&stack0x00000040,pHVar2,0,iVar17);
      uVar12 = uVar9 & 0xffffffff;
      if ((int)uVar9 < 0) break;
    }
    else {
      uVar3 = *unaff_RSI;
      uVar9 = FUN_180034c40(unaff_RSI,&stack0x00000040,pHVar2,unaff_R14D,iVar17);
      uVar12 = uVar9 & 0xffffffff;
      if ((int)uVar9 < 0) {
        *unaff_RSI = uVar3;
        FUN_180034c40(unaff_RSI,&stack0x00000040,pHVar2,0,iVar17);
        break;
      }
    }
    while( true ) {
      pbVar5 = (byte *)*unaff_RSI;
      bVar1 = *pbVar5;
      if ((((bVar1 != 9) && (bVar1 != 10)) && (bVar1 != 0xd)) && (bVar1 != 0x20)) break;
      pCVar6 = CharNextA((LPCSTR)pbVar5);
      *unaff_RSI = pCVar6;
    }
  } while (bVar1 != 0);
  CoTaskMemFree(unaff_R15);
  return uVar12;
}

/* ---- FUNC 000346ED FUN_1800346ed (19 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_1800346ed(void)

{
  undefined4 unaff_EBX;
  LPVOID unaff_R15;
  
  CoTaskMemFree(unaff_R15);
  return unaff_EBX;
}

/* ---- FUNC 00034700 FUN_180034700 (30 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180034700(void)

{
  return;
}

/* ---- FUNC 0003471E FUN_18003471e (505 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_18003471e(void)

{
  byte bVar1;
  HKEY pHVar2;
  undefined8 uVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  LPSTR pCVar7;
  LPCSTR pCVar8;
  char cVar9;
  uint uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  char *pcVar13;
  ulonglong unaff_RBP;
  undefined8 *unaff_RSI;
  undefined8 *puVar14;
  longlong lVar15;
  char cVar16;
  ulonglong unaff_R12;
  undefined8 *unaff_R13;
  int unaff_R14D;
  LPVOID unaff_R15;
  uchar in_stack_00000040;
  
  while (pHVar2 = (HKEY)unaff_R13[unaff_RBP * 2 + 1], pHVar2 != (HKEY)0x0) {
    pcVar13 = (char *)&stack0x00000040;
    while( true ) {
      pbVar5 = (byte *)*unaff_RSI;
      bVar1 = *pbVar5;
      uVar10 = (uint)(char)bVar1;
      if ((((uVar10 != 9) && (uVar10 != 10)) && (uVar10 != 0xd)) && (uVar10 != 0x20)) break;
      pCVar7 = CharNextA((LPCSTR)pbVar5);
      *unaff_RSI = pCVar7;
    }
    if (bVar1 == 0) break;
    cVar16 = (char)unaff_R12;
    if (bVar1 == 0x27) {
      pCVar7 = CharNextA((LPCSTR)pbVar5);
      *unaff_RSI = pCVar7;
      cVar9 = *pCVar7;
      while ((cVar9 != cVar16 &&
             ((*(LPCSTR)*unaff_RSI != '\'' ||
              (pCVar7 = CharNextA((LPCSTR)*unaff_RSI), *pCVar7 == '\''))))) {
        pCVar8 = (LPCSTR)*unaff_RSI;
        if (*pCVar8 == '\'') {
          pCVar8 = CharNextA(pCVar8);
          *unaff_RSI = pCVar8;
        }
        pCVar7 = CharNextA(pCVar8);
        *unaff_RSI = pCVar7;
        uVar11 = (longlong)pCVar7 - (longlong)pCVar8;
        if (&stack0x00001040 <= pcVar13 + uVar11 + 1) goto LAB_1800346d0;
        if (0 < (int)uVar11) {
          lVar15 = (longlong)pCVar8 - (longlong)pcVar13;
          uVar11 = uVar11 & 0xffffffff;
          do {
            *pcVar13 = pcVar13[lVar15];
            pcVar13 = pcVar13 + 1;
            uVar11 = uVar11 - 1;
          } while (uVar11 != 0);
        }
        cVar9 = *pCVar7;
      }
      pCVar8 = (LPCSTR)*unaff_RSI;
      if (*pCVar8 == cVar16) break;
      *pcVar13 = cVar16;
      pCVar7 = CharNextA(pCVar8);
      *unaff_RSI = pCVar7;
    }
    else {
      do {
        cVar9 = (char)uVar10;
        if (((cVar9 == '\t') || (cVar9 == '\n')) || ((cVar9 == '\r' || (cVar9 == ' ')))) break;
        pbVar6 = (byte *)CharNextA((LPCSTR)pbVar5);
        *unaff_RSI = pbVar6;
        uVar11 = (longlong)pbVar6 - (longlong)pbVar5;
        if (&stack0x00001040 <= pcVar13 + uVar11 + 1) goto LAB_1800346d0;
        if (0 < (int)uVar11) {
          lVar15 = (longlong)pbVar5 - (longlong)pcVar13;
          uVar11 = uVar11 & 0xffffffff;
          do {
            *pcVar13 = pcVar13[lVar15];
            pcVar13 = pcVar13 + 1;
            uVar11 = uVar11 - 1;
          } while (uVar11 != 0);
        }
        uVar10 = (uint)*pbVar6;
        pbVar5 = pbVar6;
      } while (*pbVar6 != 0);
      *pcVar13 = cVar16;
    }
    if (in_stack_00000040 != '{') break;
    iVar4 = (int)unaff_R12;
    if (unaff_R14D == 0) {
      uVar11 = FUN_180034c40(unaff_RSI,&stack0x00000040,pHVar2,0,iVar4);
      uVar12 = uVar11 & 0xffffffff;
      if ((int)uVar11 < 0) goto LAB_1800346d5;
    }
    else {
      uVar3 = *unaff_RSI;
      uVar11 = FUN_180034c40(unaff_RSI,&stack0x00000040,pHVar2,unaff_R14D,iVar4);
      uVar12 = uVar11 & 0xffffffff;
      if ((int)uVar11 < 0) {
        *unaff_RSI = uVar3;
        FUN_180034c40(unaff_RSI,&stack0x00000040,pHVar2,0,iVar4);
        goto LAB_1800346d5;
      }
    }
    while( true ) {
      pbVar5 = (byte *)*unaff_RSI;
      bVar1 = *pbVar5;
      if ((((bVar1 != 9) && (bVar1 != 10)) && (bVar1 != 0xd)) && (bVar1 != 0x20)) break;
      pCVar7 = CharNextA((LPCSTR)pbVar5);
      *unaff_RSI = pCVar7;
    }
    if (bVar1 == 0) goto LAB_1800346d5;
    pcVar13 = (char *)&stack0x00000040;
    while( true ) {
      bVar1 = *pbVar5;
      uVar10 = (uint)(char)bVar1;
      if (((uVar10 != 9) && (uVar10 != 10)) && ((uVar10 != 0xd && (uVar10 != 0x20)))) break;
      pbVar5 = (byte *)CharNextA((LPCSTR)pbVar5);
      *unaff_RSI = pbVar5;
    }
    if (bVar1 == 0) break;
    if (bVar1 == 0x27) {
      pCVar7 = CharNextA((LPCSTR)pbVar5);
      *unaff_RSI = pCVar7;
      cVar9 = *pCVar7;
      while ((cVar9 != cVar16 &&
             ((*(LPCSTR)*unaff_RSI != '\'' ||
              (pCVar7 = CharNextA((LPCSTR)*unaff_RSI), *pCVar7 == '\''))))) {
        pCVar8 = (LPCSTR)*unaff_RSI;
        if (*pCVar8 == '\'') {
          pCVar8 = CharNextA(pCVar8);
          *unaff_RSI = pCVar8;
        }
        pCVar7 = CharNextA(pCVar8);
        *unaff_RSI = pCVar7;
        uVar11 = (longlong)pCVar7 - (longlong)pCVar8;
        if (&stack0x00001040 <= pcVar13 + uVar11 + 1) goto LAB_1800346d0;
        if (0 < (int)uVar11) {
          lVar15 = (longlong)pCVar8 - (longlong)pcVar13;
          uVar11 = uVar11 & 0xffffffff;
          do {
            *pcVar13 = pcVar13[lVar15];
            pcVar13 = pcVar13 + 1;
            uVar11 = uVar11 - 1;
          } while (uVar11 != 0);
        }
        cVar9 = *pCVar7;
      }
      pCVar8 = (LPCSTR)*unaff_RSI;
      if (*pCVar8 == cVar16) break;
      *pcVar13 = cVar16;
      pCVar7 = CharNextA(pCVar8);
      *unaff_RSI = pCVar7;
    }
    else {
      do {
        cVar9 = (char)uVar10;
        if (((cVar9 == '\t') || (cVar9 == '\n')) || ((cVar9 == '\r' || (cVar9 == ' ')))) break;
        pbVar6 = (byte *)CharNextA((LPCSTR)pbVar5);
        *unaff_RSI = pbVar6;
        uVar11 = (longlong)pbVar6 - (longlong)pbVar5;
        if (&stack0x00001040 <= pcVar13 + uVar11 + 1) goto LAB_1800346d0;
        if (0 < (int)uVar11) {
          lVar15 = (longlong)pbVar5 - (longlong)pcVar13;
          uVar11 = uVar11 & 0xffffffff;
          do {
            *pcVar13 = pcVar13[lVar15];
            pcVar13 = pcVar13 + 1;
            uVar11 = uVar11 - 1;
          } while (uVar11 != 0);
        }
        uVar10 = (uint)*pbVar6;
        pbVar5 = pbVar6;
      } while (*pbVar6 != 0);
      *pcVar13 = cVar16;
    }
    uVar11 = unaff_R12 & 0xffffffff;
    unaff_RBP = unaff_R12;
    puVar14 = unaff_R13;
    while (iVar4 = lstrcmpiA((LPCSTR)&stack0x00000040,(LPCSTR)*puVar14), iVar4 != 0) {
      uVar10 = (int)uVar11 + 1;
      uVar11 = (ulonglong)uVar10;
      unaff_RBP = unaff_RBP + 1;
      puVar14 = puVar14 + 2;
      if (0xd < uVar10) goto LAB_1800346d0;
    }
  }
LAB_1800346d0:
  uVar12 = 0x80020009;
LAB_1800346d5:
  CoTaskMemFree(unaff_R15);
  return uVar12;
}

/* ---- FUNC 00034920 FUN_180034920 (788 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

DWORD FUN_180034920(undefined8 param_1,LPCWSTR param_2,LPCSTR param_3,LPCSTR param_4,int param_5)

{
  undefined1 auVar1 [16];
  uchar *puVar2;
  char cVar3;
  int iVar4;
  DWORD DVar5;
  uint uVar6;
  longlong lVar7;
  ulonglong uVar8;
  LPCSTR pCVar9;
  HMODULE hModule;
  HRSRC hResInfo;
  HGLOBAL _Src;
  undefined1 *puVar10;
  LPCSTR _Memory;
  undefined1 *puVar11;
  undefined1 *puVar12;
  ulonglong uVar13;
  LPCSTR pCVar14;
  LPCSTR lpLibFileName;
  LPCSTR pCVar15;
  undefined1 auStack_4d8 [64];
  DWORD local_498 [2];
  LPCSTR local_490;
  HMODULE local_488;
  HGLOBAL local_480;
  undefined8 local_478;
  undefined8 local_470;
  uchar *local_458;
  uchar local_450 [1032];
  ulonglong local_48;
  
  puVar12 = auStack_4d8;
  puVar11 = auStack_4d8;
  local_48 = DAT_180077818 ^ (ulonglong)local_498;
  pCVar15 = (LPCSTR)0x0;
  local_490 = (LPCSTR)0x0;
  local_478 = 0;
  local_458 = (uchar *)0x0;
  _Memory = pCVar15;
  local_470 = param_1;
  if (param_2 != (LPCWSTR)0x0) {
    lVar7 = -1;
    do {
      lVar7 = lVar7 + 1;
    } while (param_2[lVar7] != L'\0');
    lVar7 = (longlong)((int)lVar7 + 1) * 2;
    puVar12 = auStack_4d8;
    lpLibFileName = pCVar15;
    if (lVar7 + 0x80000000U < 0x100000000) {
      iVar4 = (int)lVar7;
      uVar13 = (ulonglong)iVar4;
      if ((iVar4 < 0x401) && (cVar3 = FUN_1800026d0(uVar13), cVar3 != '\0')) {
        uVar8 = uVar13 + 0xf;
        if (uVar8 <= uVar13) {
          uVar8 = 0xffffffffffffff0;
        }
        puVar11 = auStack_4d8 + -(uVar8 & 0xfffffffffffffff0);
        pCVar14 = (LPCSTR)((longlong)local_498 + -(uVar8 & 0xfffffffffffffff0));
        pCVar9 = pCVar15;
      }
      else {
        if (~uVar13 < 0x10) {
                    /* WARNING: Subroutine does not return */
          FUN_180001a90(-0x7ff8fdea);
        }
        pCVar9 = malloc(uVar13 + 0x10);
        _Memory = (LPCSTR)0x0;
        puVar12 = auStack_4d8;
        if (pCVar9 == (LPCSTR)0x0) goto LAB_180034a4d;
        pCVar9[0] = '\0';
        pCVar9[1] = '\0';
        pCVar9[2] = '\0';
        pCVar9[3] = '\0';
        pCVar9[4] = '\0';
        pCVar9[5] = '\0';
        pCVar9[6] = '\0';
        pCVar9[7] = '\0';
        local_490 = pCVar9;
        pCVar14 = pCVar9 + 0x10;
      }
      _Memory = pCVar9;
      puVar12 = puVar11;
      if (pCVar14 != (LPCSTR)0x0) {
        *pCVar14 = '\0';
        *(undefined8 *)(puVar11 + 0x38) = 0;
        *(undefined8 *)(puVar11 + 0x30) = 0;
        *(int *)(puVar11 + 0x28) = iVar4;
        *(LPCSTR *)(puVar11 + 0x20) = pCVar14;
        *(undefined8 *)(puVar11 + -8) = 0x180034a42;
        iVar4 = WideCharToMultiByte(0,0,param_2,-1,*(LPSTR *)(puVar11 + 0x20),
                                    *(int *)(puVar11 + 0x28),*(LPCSTR *)(puVar11 + 0x30),
                                    *(LPBOOL *)(puVar11 + 0x38));
        lpLibFileName = pCVar14;
        if (iVar4 == 0) {
          lpLibFileName = pCVar15;
        }
      }
    }
LAB_180034a4d:
    if (lpLibFileName != (LPCSTR)0x0) {
      *(undefined8 *)(puVar12 + -8) = 0x180034a65;
      hModule = LoadLibraryExA(lpLibFileName,(HANDLE)0x0,0x60);
      if (hModule == (HMODULE)0x0) {
        local_488 = hModule;
        *(undefined8 *)(puVar12 + -8) = 0x180034a80;
        hModule = LoadLibraryExA(lpLibFileName,(HANDLE)0x0,2);
        if (hModule != (HMODULE)0x0) goto LAB_180034a98;
        local_488 = hModule;
        *(undefined8 *)(puVar12 + -8) = 0x180034a91;
        DVar5 = FUN_1800333f0();
      }
      else {
LAB_180034a98:
        local_488 = hModule;
        *(undefined8 *)(puVar12 + -8) = 0x180034aa7;
        hResInfo = FindResourceA(hModule,param_3,param_4);
        if (hResInfo == (HRSRC)0x0) {
          *(undefined8 *)(puVar12 + -8) = 0x180034ab4;
          DVar5 = FUN_1800333f0();
        }
        else {
          *(undefined8 *)(puVar12 + -8) = 0x180034ac5;
          _Src = LoadResource(hModule,hResInfo);
          local_480 = _Src;
          if (_Src == (HGLOBAL)0x0) {
            *(undefined8 *)(puVar12 + -8) = 0x180034ad6;
            DVar5 = FUN_1800333f0();
          }
          else {
            *(undefined8 *)(puVar12 + -8) = 0x180034ae7;
            local_498[0] = SizeofResource(hModule,hResInfo);
            uVar13 = (ulonglong)local_498[0];
            uVar6 = local_498[0] + 1;
            if (uVar6 < local_498[0]) {
              DVar5 = 0x8007000e;
            }
            else {
              if (uVar6 == 0) {
LAB_180034b2f:
                local_458 = local_450;
              }
              else {
                auVar1._8_8_ = 0;
                auVar1._0_8_ = CONCAT44(0,uVar6);
                if (SUB168((ZEXT816(0) << 0x40 | ZEXT816(0xffffffffffffffff)) / auVar1,0) == 0) {
                    /* WARNING: Subroutine does not return */
                  *(undefined **)(puVar12 + -8) = &UNK_180034c34;
                  FUN_180001a90(-0x7ff8fdea);
                }
                if (CONCAT44(0,uVar6) < 0x401) goto LAB_180034b2f;
                *(undefined8 *)(puVar12 + -8) = 0x180034b2d;
                FUN_180033280(&local_458,(ulonglong)uVar6);
              }
              puVar2 = local_458;
              if (local_458 == (uchar *)0x0) {
                DVar5 = 0x8007000e;
              }
              else {
                if (uVar13 != 0) {
                  *(undefined8 *)(puVar12 + -8) = 0x180034b6a;
                  memcpy(puVar2,_Src,uVar13);
                }
                puVar2 = local_458;
                local_458[uVar13] = '\0';
                *(undefined8 *)(puVar12 + -8) = 0x180034b86;
                puVar10 = FUN_1800344c0(&local_478,puVar2,param_5);
                DVar5 = (DWORD)puVar10;
              }
            }
          }
        }
        if (hModule != (HMODULE)0x0) {
          *(undefined8 *)(puVar12 + -8) = 0x180034b96;
          FreeLibrary(hModule);
        }
      }
      if (local_458 != local_450) {
        *(undefined8 *)(puVar12 + -8) = 0x180034baa;
        FUN_1800339a0(&local_458);
      }
      while (_Memory != (LPCSTR)0x0) {
        pCVar15 = *(LPCSTR *)_Memory;
        *(undefined8 *)(puVar12 + -8) = 0x180034bbc;
        free(_Memory);
        _Memory = pCVar15;
      }
      goto LAB_180034bf6;
    }
  }
  if (local_458 != local_450) {
    *(undefined8 *)(puVar12 + -8) = 0x180034bd8;
    FUN_1800339a0(&local_458);
  }
  while (_Memory != (LPCSTR)0x0) {
    pCVar15 = *(LPCSTR *)_Memory;
    *(undefined8 *)(puVar12 + -8) = 0x180034bec;
    free(_Memory);
    _Memory = pCVar15;
  }
  DVar5 = 0x8007000e;
LAB_180034bf6:
  *(undefined8 *)(puVar12 + -8) = 0x180034c05;
  return DVar5;
}

/* ---- FUNC 00034C40 FUN_180034c40 (3791 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180034c40(undefined8 *param_1,uchar *param_2,HKEY param_3,int param_4,int param_5)

{
  byte bVar1;
  uchar uVar2;
  bool bVar3;
  longlong *plVar4;
  HKEY hKey;
  int iVar5;
  int iVar6;
  int iVar7;
  errno_t eVar8;
  LSTATUS LVar9;
  HKEY hKey_00;
  ulonglong uVar10;
  LPSTR pCVar11;
  char *pcVar12;
  LPCSTR pCVar13;
  ulonglong uVar14;
  byte *pbVar15;
  HMODULE pHVar16;
  FARPROC pFVar17;
  INT_PTR IVar18;
  char cVar19;
  uint uVar20;
  uint uVar21;
  uchar *puVar22;
  undefined **ppuVar23;
  CHAR *pCVar24;
  longlong lVar25;
  byte *pbVar26;
  undefined1 auStackY_1218 [32];
  HKEY local_11b8;
  HKEY local_11b0;
  int local_11a8;
  HKEY local_11a0;
  undefined4 local_1198;
  longlong *local_1190;
  DWORD local_1188 [2];
  HKEY local_1180;
  undefined4 local_1178;
  undefined8 local_1170;
  uchar local_1168 [272];
  CHAR local_1058 [4096];
  ulonglong local_58 [2];
  undefined8 uStack_48;
  
  uStack_48 = 0x180034c5f;
  local_58[0] = DAT_180077818 ^ (ulonglong)auStackY_1218;
  hKey_00 = (HKEY)0x0;
  local_11a0 = (HKEY)0x0;
  local_1198 = 0;
  local_1190 = (longlong *)0x0;
  local_11b0 = param_3;
  local_11a8 = param_4;
LAB_180034c94:
  uVar10 = FUN_180033b80(param_1,param_2);
  do {
    uVar14 = uVar10 & 0xffffffff;
    if ((int)uVar10 < 0) {
LAB_180035ad1:
      if (hKey_00 != (HKEY)0x0) {
        RegCloseKey(hKey_00);
      }
      return uVar14;
    }
LAB_180034ca3:
    if (*param_2 == '}') goto LAB_180035ad1;
    iVar5 = lstrcmpiA((LPCSTR)param_2,"Delete");
    iVar6 = lstrcmpiA((LPCSTR)param_2,"ForceRemove");
    if ((iVar6 != 0) && (iVar5 != 0)) goto LAB_180034f03;
    while( true ) {
      pbVar26 = (byte *)*param_1;
      bVar1 = *pbVar26;
      uVar20 = (uint)(char)bVar1;
      if ((uVar20 != 9) && (((uVar20 != 10 && (uVar20 != 0xd)) && (uVar20 != 0x20)))) break;
      pCVar11 = CharNextA((LPCSTR)pbVar26);
      *param_1 = pCVar11;
    }
    if (bVar1 == 0) goto LAB_180035acc;
    puVar22 = param_2;
    if (bVar1 == 0x27) {
      pcVar12 = CharNextA((LPCSTR)pbVar26);
      *param_1 = pcVar12;
      cVar19 = *pcVar12;
      while ((cVar19 != '\0' &&
             ((*pcVar12 != '\'' || (pCVar11 = CharNextA(pcVar12), *pCVar11 == '\''))))) {
        pCVar13 = (LPCSTR)*param_1;
        if (*pCVar13 == '\'') {
          pCVar13 = CharNextA(pCVar13);
          *param_1 = pCVar13;
        }
        pCVar11 = CharNextA(pCVar13);
        *param_1 = pCVar11;
        uVar10 = (longlong)pCVar11 - (longlong)pCVar13;
        if (param_2 + 0x1000 <= puVar22 + uVar10 + 1) goto LAB_180035acc;
        if (0 < (int)uVar10) {
          lVar25 = (longlong)pCVar13 - (longlong)puVar22;
          uVar10 = uVar10 & 0xffffffff;
          do {
            *puVar22 = puVar22[lVar25];
            puVar22 = puVar22 + 1;
            uVar10 = uVar10 - 1;
          } while (uVar10 != 0);
        }
        pcVar12 = (char *)*param_1;
        cVar19 = *pcVar12;
      }
      if (*(char *)*param_1 == '\0') goto LAB_180035acc;
      *puVar22 = '\0';
      pCVar11 = CharNextA((LPCSTR)*param_1);
      *param_1 = pCVar11;
    }
    else {
      do {
        cVar19 = (char)uVar20;
        if (((cVar19 == '\t') || (cVar19 == '\n')) || ((cVar19 == '\r' || (cVar19 == ' ')))) break;
        pCVar11 = CharNextA((LPCSTR)pbVar26);
        *param_1 = pCVar11;
        uVar10 = (longlong)pCVar11 - (longlong)pbVar26;
        if (param_2 + 0x1000 <= puVar22 + uVar10 + 1) goto LAB_180035acc;
        if (0 < (int)uVar10) {
          lVar25 = (longlong)pbVar26 - (longlong)puVar22;
          uVar10 = uVar10 & 0xffffffff;
          do {
            *puVar22 = puVar22[lVar25];
            puVar22 = puVar22 + 1;
            uVar10 = uVar10 - 1;
          } while (uVar10 != 0);
        }
        pbVar26 = (byte *)*param_1;
        uVar20 = (uint)*pbVar26;
      } while (*pbVar26 != 0);
      *puVar22 = '\0';
    }
    iVar6 = local_11a8;
    if (local_11a8 != 0) {
      local_1180 = (HKEY)0x0;
      local_1178 = 0;
      local_1170 = 0;
      uVar2 = *param_2;
      puVar22 = param_2;
      while (uVar2 != '\0') {
        if (uVar2 == '\\') {
          if (puVar22 != (uchar *)0x0) goto LAB_180035acc;
          break;
        }
        puVar22 = (uchar *)CharNextA((LPCSTR)puVar22);
        uVar2 = *puVar22;
      }
      ppuVar23 = &PTR_s_AppID_1800650f0;
      do {
        iVar7 = lstrcmpiA((LPCSTR)param_2,*ppuVar23);
        if (iVar7 == 0) goto LAB_180034ece;
        ppuVar23 = ppuVar23 + 1;
      } while ((longlong)ppuVar23 < 0x180065150);
      local_1180 = local_11b0;
      local_1178 = 0;
      local_1170 = 0;
      FUN_180034330(&local_1180,(LPCSTR)param_2);
LAB_180034ece:
      if (iVar5 != 0) goto LAB_180034f03;
      uVar10 = FUN_180033b80(param_1,param_2);
      uVar14 = uVar10 & 0xffffffff;
      if ((int)uVar10 < 0) goto LAB_180035ad1;
      uVar14 = FUN_180036080(param_1,(char *)param_2);
      iVar5 = (int)uVar14;
joined_r0x000180034ef6:
      uVar14 = uVar14 & 0xffffffff;
      if (iVar5 < 0) goto LAB_180035ad1;
LAB_1800356d8:
      if (*param_2 == '{') {
        lVar25 = -1;
        do {
          lVar25 = lVar25 + 1;
        } while (param_2[lVar25] != '\0');
        if (lVar25 == 1) {
          uVar10 = FUN_180034c40(param_1,param_2,hKey_00,iVar6,0);
          uVar14 = uVar10 & 0xffffffff;
          if ((int)uVar10 < 0) goto LAB_180035ad1;
          goto LAB_180034c94;
        }
      }
      goto LAB_180034ca3;
    }
LAB_180034f03:
    iVar5 = lstrcmpiA((LPCSTR)param_2,"NoRemove");
    uVar20 = 0;
    bVar3 = true;
    if (iVar5 == 0) {
      while( true ) {
        pbVar26 = (byte *)*param_1;
        bVar1 = *pbVar26;
        uVar21 = (uint)(char)bVar1;
        if ((((uVar21 != 9) && (uVar21 != 10)) && (uVar21 != 0xd)) && (uVar21 != 0x20)) break;
        pCVar11 = CharNextA((LPCSTR)pbVar26);
        *param_1 = pCVar11;
      }
      if (bVar1 != 0) {
        puVar22 = param_2;
        bVar3 = false;
        if (bVar1 == 0x27) {
          pcVar12 = CharNextA((LPCSTR)pbVar26);
          *param_1 = pcVar12;
          cVar19 = *pcVar12;
          while ((cVar19 != '\0' &&
                 ((*pcVar12 != '\'' || (pCVar11 = CharNextA(pcVar12), *pCVar11 == '\''))))) {
            pCVar13 = (LPCSTR)*param_1;
            if (*pCVar13 == '\'') {
              pCVar13 = CharNextA(pCVar13);
              *param_1 = pCVar13;
            }
            pCVar11 = CharNextA(pCVar13);
            *param_1 = pCVar11;
            uVar10 = (longlong)pCVar11 - (longlong)pCVar13;
            if (param_2 + 0x1000 <= puVar22 + uVar10 + 1) goto LAB_180035acc;
            if (0 < (int)uVar10) {
              lVar25 = (longlong)pCVar13 - (longlong)puVar22;
              uVar10 = uVar10 & 0xffffffff;
              do {
                *puVar22 = puVar22[lVar25];
                puVar22 = puVar22 + 1;
                uVar10 = uVar10 - 1;
              } while (uVar10 != 0);
            }
            pcVar12 = (char *)*param_1;
            cVar19 = *pcVar12;
          }
          if (*(char *)*param_1 == '\0') goto LAB_180035acc;
          *puVar22 = '\0';
          pCVar11 = CharNextA((LPCSTR)*param_1);
          *param_1 = pCVar11;
        }
        else {
          do {
            cVar19 = (char)uVar21;
            if (((cVar19 == '\t') || (cVar19 == '\n')) || ((cVar19 == '\r' || (cVar19 == ' '))))
            break;
            pCVar11 = CharNextA((LPCSTR)pbVar26);
            *param_1 = pCVar11;
            uVar10 = (longlong)pCVar11 - (longlong)pbVar26;
            if (param_2 + 0x1000 <= puVar22 + uVar10 + 1) goto LAB_180035acc;
            if (0 < (int)uVar10) {
              lVar25 = (longlong)pbVar26 - (longlong)puVar22;
              uVar10 = uVar10 & 0xffffffff;
              do {
                *puVar22 = puVar22[lVar25];
                puVar22 = puVar22 + 1;
                uVar10 = uVar10 - 1;
              } while (uVar10 != 0);
            }
            pbVar26 = (byte *)*param_1;
            uVar21 = (uint)*pbVar26;
          } while (*pbVar26 != 0);
          *puVar22 = '\0';
        }
        goto LAB_18003506c;
      }
LAB_180035acc:
      uVar14 = 0x80020009;
      goto LAB_180035ad1;
    }
LAB_18003506c:
    iVar5 = lstrcmpiA((LPCSTR)param_2,"Val");
    if (iVar5 != 0) {
      uVar2 = *param_2;
      puVar22 = param_2;
      iVar6 = local_11a8;
      plVar4 = local_1190;
      while (local_11a8 = iVar6, local_1190 = plVar4, uVar2 != '\0') {
        if (uVar2 == '\\') {
          if (puVar22 != (uchar *)0x0) goto LAB_180035acc;
          break;
        }
        puVar22 = (uchar *)CharNextA((LPCSTR)puVar22);
        iVar6 = local_11a8;
        plVar4 = local_1190;
        uVar2 = *puVar22;
      }
      if (iVar6 != 0) {
        local_11b8 = (HKEY)0x0;
        if (plVar4 == (longlong *)0x0) {
LAB_180035497:
          iVar5 = RegOpenKeyExA(local_11b0,(LPCSTR)param_2,0,0x2001f,&local_11b8);
LAB_1800354b8:
          if (iVar5 != 0) goto LAB_1800354e1;
          uVar21 = uVar20;
          if (hKey_00 != (HKEY)0x0) {
            uVar21 = RegCloseKey(hKey_00);
          }
          local_11a0 = local_11b8;
          local_1198 = 0;
          hKey_00 = local_11b8;
          if (uVar21 != 0) goto LAB_1800354e1;
        }
        else {
          if (*plVar4 == 0) {
            if ((int)plVar4[1] != 0) goto LAB_180035497;
LAB_180035490:
            iVar5 = 1;
            goto LAB_1800354b8;
          }
          pHVar16 = GetModuleHandleA("Advapi32.dll");
          if (pHVar16 != (HMODULE)0x0) {
            pFVar17 = GetProcAddress(pHVar16,"RegOpenKeyTransactedA");
            if (pFVar17 == (FARPROC)0x0) goto LAB_180035490;
            IVar18 = (*pFVar17)(local_11b0,param_2);
            iVar5 = (int)IVar18;
            goto LAB_1800354b8;
          }
LAB_1800354e1:
          local_11b8 = (HKEY)0x0;
          if (plVar4 == (longlong *)0x0) {
LAB_180035559:
            iVar5 = RegOpenKeyExA(local_11b0,(LPCSTR)param_2,0,0x20019,&local_11b8);
LAB_18003557a:
            if (iVar5 == 0) {
              uVar21 = uVar20;
              if (hKey_00 != (HKEY)0x0) {
                uVar21 = RegCloseKey(hKey_00);
              }
              local_11a0 = local_11b8;
              local_1198 = 0;
              hKey_00 = local_11b8;
              if (uVar21 == 0) goto LAB_18003569b;
            }
          }
          else {
            if (*plVar4 == 0) {
              if ((int)plVar4[1] != 0) goto LAB_180035559;
LAB_180035552:
              iVar5 = 1;
              goto LAB_18003557a;
            }
            pHVar16 = GetModuleHandleA("Advapi32.dll");
            if (pHVar16 != (HMODULE)0x0) {
              pFVar17 = GetProcAddress(pHVar16,"RegOpenKeyTransactedA");
              if (pFVar17 == (FARPROC)0x0) goto LAB_180035552;
              IVar18 = (*pFVar17)(local_11b0,param_2);
              iVar5 = (int)IVar18;
              goto LAB_18003557a;
            }
          }
          local_11b8 = (HKEY)0x0;
          if (plVar4 == (longlong *)0x0) {
LAB_180035636:
            uVar21 = RegCreateKeyExA(local_11b0,(LPCSTR)param_2,0,(LPSTR)0x0,0,0x2001f,
                                     (LPSECURITY_ATTRIBUTES)0x0,&local_11b8,local_1188);
          }
          else if (*plVar4 == 0) {
            if ((int)plVar4[1] != 0) goto LAB_180035636;
LAB_18003562f:
            uVar21 = 1;
          }
          else {
            pHVar16 = GetModuleHandleA("Advapi32.dll");
            if (pHVar16 == (HMODULE)0x0) {
              uVar21 = 1;
              goto LAB_180035ac1;
            }
            pFVar17 = GetProcAddress(pHVar16,"RegCreateKeyTransactedA");
            if (pFVar17 == (FARPROC)0x0) goto LAB_18003562f;
            IVar18 = (*pFVar17)(local_11b0,param_2);
            uVar21 = (uint)IVar18;
          }
          if (uVar21 != 0) goto LAB_180035ac1;
          uVar21 = uVar20;
          if (hKey_00 != (HKEY)0x0) {
            uVar21 = RegCloseKey(hKey_00);
          }
          local_11a0 = local_11b8;
          local_1198 = 0;
          hKey_00 = local_11b8;
          if (uVar21 != 0) goto LAB_180035ac1;
        }
LAB_18003569b:
        hKey_00 = local_11a0;
        local_1198 = 0;
        local_11b8 = local_11a0;
        uVar10 = FUN_180033b80(param_1,param_2);
        uVar14 = uVar10 & 0xffffffff;
        if (-1 < (int)uVar10) {
          if (*param_2 == '=') {
            uVar14 = FUN_180032b70(param_1,&local_11a0,(LPCSTR)0x0,param_2);
            iVar5 = (int)uVar14;
            hKey_00 = local_11a0;
            goto joined_r0x000180034ef6;
          }
          goto LAB_1800356d8;
        }
        goto LAB_180035ad1;
      }
      if (param_5 == 0) {
        local_11b8 = (HKEY)0x0;
        if (plVar4 == (longlong *)0x0) {
LAB_1800357c2:
          uVar21 = RegOpenKeyExA(local_11b0,(LPCSTR)param_2,0,0x20019,&local_11b8);
        }
        else if (*plVar4 == 0) {
          if ((int)plVar4[1] != 0) goto LAB_1800357c2;
LAB_1800357bb:
          uVar21 = 1;
        }
        else {
          pHVar16 = GetModuleHandleA("Advapi32.dll");
          if (pHVar16 == (HMODULE)0x0) {
            uVar21 = 1;
            goto LAB_180035815;
          }
          pFVar17 = GetProcAddress(pHVar16,"RegOpenKeyTransactedA");
          if (pFVar17 == (FARPROC)0x0) goto LAB_1800357bb;
          IVar18 = (*pFVar17)(local_11b0,param_2,0,0x20019);
          uVar21 = (uint)IVar18;
        }
        if (uVar21 == 0) {
          uVar21 = uVar20;
          if (hKey_00 != (HKEY)0x0) {
            uVar21 = RegCloseKey(hKey_00);
          }
          local_11a0 = local_11b8;
          local_1198 = 0;
          hKey_00 = local_11b8;
        }
      }
      else {
        uVar21 = 2;
      }
LAB_180035815:
      iVar5 = 1;
      if (uVar21 == 0) {
        iVar5 = param_5;
      }
      eVar8 = _mbsnbcpy_s(local_1168,0x104,param_2,0xffffffffffffffff);
      if (eVar8 != 0) {
        if (eVar8 == 0xc) {
                    /* WARNING: Subroutine does not return */
          AfxThrowMemoryException();
        }
        if (eVar8 != 0x50) {
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
      }
      uVar10 = FUN_180033b80(param_1,param_2);
      uVar14 = uVar10 & 0xffffffff;
      if ((int)uVar10 < 0) goto LAB_180035ad1;
      uVar10 = FUN_180036080(param_1,(char *)param_2);
      uVar14 = uVar10 & 0xffffffff;
      if ((int)uVar10 < 0) goto LAB_180035ad1;
      if (*param_2 == '{') {
        lVar25 = -1;
        do {
          lVar25 = lVar25 + 1;
        } while (param_2[lVar25] != '\0');
        if (lVar25 == 1) {
          uVar10 = FUN_180034c40(param_1,param_2,hKey_00,0,iVar5);
          uVar14 = uVar10 & 0xffffffff;
          if (((int)uVar10 < 0) && (iVar5 == 0)) goto LAB_180035ad1;
          uVar10 = FUN_180033b80(param_1,param_2);
          uVar14 = uVar10 & 0xffffffff;
          if ((int)uVar10 < 0) goto LAB_180035ad1;
        }
      }
      if (uVar21 != 2) {
        if (uVar21 == 0) {
          uVar21 = 0;
          if (param_5 != 0) {
            local_11b8 = (HKEY)((ulonglong)local_11b8 & 0xffffffff00000000);
            LVar9 = RegQueryInfoKeyW(hKey_00,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                     (LPDWORD)&local_11b8,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                     (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(PFILETIME)0x0);
            if ((LVar9 == 0) && ((int)local_11b8 != 0)) {
              ppuVar23 = &PTR_s_AppID_1800650f0;
              do {
                iVar5 = lstrcmpiA((LPCSTR)local_1168,*ppuVar23);
                if (iVar5 == 0) goto LAB_180034ca3;
                ppuVar23 = ppuVar23 + 1;
              } while ((longlong)ppuVar23 < 0x180065150);
              if (bVar3) {
                FUN_180034330(&local_11a0,(LPCSTR)local_1168);
                hKey_00 = local_11a0;
              }
              goto LAB_180034ca3;
            }
          }
          local_11b8 = (HKEY)((ulonglong)local_11b8 & 0xffffffff00000000);
          LVar9 = RegQueryInfoKeyW(hKey_00,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                   (LPDWORD)&local_11b8,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                   (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(PFILETIME)0x0);
          uVar20 = uVar21;
          if (LVar9 == 0) {
            uVar20 = (uint)((int)local_11b8 != 0);
          }
          if (hKey_00 != (HKEY)0x0) {
            uVar21 = RegCloseKey(hKey_00);
            local_11a0 = (HKEY)0x0;
            hKey_00 = (HKEY)0x0;
          }
          local_1198 = 0;
          if (uVar21 != 0) goto LAB_180035ac1;
          if ((bVar3) && (uVar20 == 0)) {
            if (DAT_180079878 == '\0') {
              pHVar16 = GetModuleHandleA("Advapi32.dll");
              if (pHVar16 == (HMODULE)0x0) {
                DAT_180079878 = '\x01';
              }
              else {
                DAT_180079870 = GetProcAddress(pHVar16,"RegDeleteKeyExA");
                DAT_180079878 = '\x01';
              }
            }
            if (DAT_180079870 == (FARPROC)0x0) {
              uVar21 = RegDeleteKeyA(local_11b0,(LPCSTR)local_1168);
            }
            else {
              IVar18 = (*DAT_180079870)();
              uVar21 = (uint)IVar18;
            }
            if (uVar21 != 0) goto LAB_180035ac1;
          }
          goto LAB_180034ca3;
        }
        if (param_5 == 0) {
          uVar20 = FUN_180033410(uVar21);
          uVar14 = (ulonglong)uVar20;
          goto LAB_180035ad1;
        }
      }
      goto LAB_180034ca3;
    }
    pCVar24 = local_1058;
    while( true ) {
      pbVar26 = (byte *)*param_1;
      bVar1 = *pbVar26;
      uVar20 = (uint)(char)bVar1;
      if ((((uVar20 != 9) && (uVar20 != 10)) && (uVar20 != 0xd)) && (uVar20 != 0x20)) break;
      pCVar11 = CharNextA((LPCSTR)pbVar26);
      *param_1 = pCVar11;
    }
    if (bVar1 == 0) goto LAB_180035acc;
    if (bVar1 == 0x27) {
      pCVar11 = CharNextA((LPCSTR)pbVar26);
      *param_1 = pCVar11;
      cVar19 = *pCVar11;
      while ((cVar19 != '\0' &&
             ((*(LPCSTR)*param_1 != '\'' ||
              (pCVar11 = CharNextA((LPCSTR)*param_1), *pCVar11 == '\''))))) {
        pCVar13 = (LPCSTR)*param_1;
        if (*pCVar13 == '\'') {
          pCVar13 = CharNextA(pCVar13);
          *param_1 = pCVar13;
        }
        pCVar11 = CharNextA(pCVar13);
        *param_1 = pCVar11;
        uVar10 = (longlong)pCVar11 - (longlong)pCVar13;
        if (local_58 <= pCVar24 + uVar10 + 1) goto LAB_180035acc;
        if (0 < (int)uVar10) {
          lVar25 = (longlong)pCVar13 - (longlong)pCVar24;
          uVar10 = uVar10 & 0xffffffff;
          do {
            *pCVar24 = pCVar24[lVar25];
            pCVar24 = pCVar24 + 1;
            uVar10 = uVar10 - 1;
          } while (uVar10 != 0);
        }
        cVar19 = *pCVar11;
      }
      pCVar13 = (LPCSTR)*param_1;
      if (*pCVar13 == '\0') goto LAB_180035acc;
      *pCVar24 = '\0';
      pCVar11 = CharNextA(pCVar13);
      *param_1 = pCVar11;
    }
    else {
      do {
        cVar19 = (char)uVar20;
        if (((cVar19 == '\t') || (cVar19 == '\n')) || ((cVar19 == '\r' || (cVar19 == ' ')))) break;
        pbVar15 = (byte *)CharNextA((LPCSTR)pbVar26);
        *param_1 = pbVar15;
        uVar10 = (longlong)pbVar15 - (longlong)pbVar26;
        if (local_58 <= pCVar24 + uVar10 + 1) goto LAB_180035acc;
        if (0 < (int)uVar10) {
          lVar25 = (longlong)pbVar26 - (longlong)pCVar24;
          uVar10 = uVar10 & 0xffffffff;
          do {
            *pCVar24 = pCVar24[lVar25];
            pCVar24 = pCVar24 + 1;
            uVar10 = uVar10 - 1;
          } while (uVar10 != 0);
        }
        uVar20 = (uint)*pbVar15;
        pbVar26 = pbVar15;
      } while (*pbVar15 != 0);
      *pCVar24 = '\0';
    }
    while( true ) {
      pbVar26 = (byte *)*param_1;
      bVar1 = *pbVar26;
      uVar20 = (uint)(char)bVar1;
      if ((((uVar20 != 9) && (uVar20 != 10)) && (uVar20 != 0xd)) && (uVar20 != 0x20)) break;
      pCVar11 = CharNextA((LPCSTR)pbVar26);
      *param_1 = pCVar11;
    }
    if (bVar1 == 0) goto LAB_180035acc;
    puVar22 = param_2;
    if (bVar1 == 0x27) {
      pcVar12 = CharNextA((LPCSTR)pbVar26);
      *param_1 = pcVar12;
      cVar19 = *pcVar12;
      while ((cVar19 != '\0' &&
             ((*pcVar12 != '\'' || (pCVar11 = CharNextA(pcVar12), *pCVar11 == '\''))))) {
        pCVar13 = (LPCSTR)*param_1;
        if (*pCVar13 == '\'') {
          pCVar13 = CharNextA(pCVar13);
          *param_1 = pCVar13;
        }
        pCVar11 = CharNextA(pCVar13);
        *param_1 = pCVar11;
        uVar10 = (longlong)pCVar11 - (longlong)pCVar13;
        if (param_2 + 0x1000 <= puVar22 + uVar10 + 1) goto LAB_180035acc;
        if (0 < (int)uVar10) {
          lVar25 = (longlong)pCVar13 - (longlong)puVar22;
          uVar10 = uVar10 & 0xffffffff;
          do {
            *puVar22 = puVar22[lVar25];
            puVar22 = puVar22 + 1;
            uVar10 = uVar10 - 1;
          } while (uVar10 != 0);
        }
        pcVar12 = (char *)*param_1;
        cVar19 = *pcVar12;
      }
      if (*(char *)*param_1 == '\0') goto LAB_180035acc;
      *puVar22 = '\0';
      pCVar11 = CharNextA((LPCSTR)*param_1);
      *param_1 = pCVar11;
    }
    else {
      do {
        cVar19 = (char)uVar20;
        if (((cVar19 == '\t') || (cVar19 == '\n')) || ((cVar19 == '\r' || (cVar19 == ' ')))) break;
        pCVar11 = CharNextA((LPCSTR)pbVar26);
        *param_1 = pCVar11;
        uVar10 = (longlong)pCVar11 - (longlong)pbVar26;
        if (param_2 + 0x1000 <= puVar22 + uVar10 + 1) goto LAB_180035acc;
        if (0 < (int)uVar10) {
          lVar25 = (longlong)pbVar26 - (longlong)puVar22;
          uVar10 = uVar10 & 0xffffffff;
          do {
            *puVar22 = puVar22[lVar25];
            puVar22 = puVar22 + 1;
            uVar10 = uVar10 - 1;
          } while (uVar10 != 0);
        }
        pbVar26 = (byte *)*param_1;
        uVar20 = (uint)*pbVar26;
      } while (*pbVar26 != 0);
      *puVar22 = '\0';
    }
    iVar6 = local_11a8;
    if (*param_2 != '=') goto LAB_180035acc;
    if (local_11a8 != 0) {
      local_1180 = local_11b0;
      local_1178 = 0;
      local_1170 = 0;
      uVar14 = FUN_180032b70(param_1,&local_1180,local_1058,param_2);
      iVar5 = (int)uVar14;
      goto joined_r0x000180034ef6;
    }
    if ((param_5 == 0) && (bVar3)) {
      local_11b8 = (HKEY)0x0;
      uVar21 = RegOpenKeyExA(local_11b0,(LPCSTR)0x0,0,0x20006,&local_11b8);
      hKey = local_11b8;
      if (uVar21 != 0) {
LAB_180035ac1:
        uVar20 = FUN_180033410(uVar21);
        uVar14 = (ulonglong)uVar20;
        goto LAB_180035ad1;
      }
      uVar20 = RegDeleteValueA(local_11b8,local_1058);
      if ((uVar20 & 0xfffffffd) != 0) {
        uVar20 = FUN_180033410(uVar20);
        uVar14 = (ulonglong)uVar20;
        if (hKey != (HKEY)0x0) {
          RegCloseKey(hKey);
        }
        goto LAB_180035ad1;
      }
      if (hKey != (HKEY)0x0) {
        RegCloseKey(hKey);
      }
    }
    uVar10 = FUN_180036080(param_1,(char *)param_2);
  } while( true );
}

/* ---- FUNC 00035B10 FUN_180035b10 (702 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

DWORD FUN_180035b10(undefined8 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

{
  char cVar1;
  int iVar2;
  DWORD DVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  undefined8 *_Memory;
  undefined1 *puVar7;
  undefined1 *puVar8;
  ulonglong uVar9;
  LPCSTR pCVar10;
  LPCSTR pCVar11;
  undefined1 auStack_78 [64];
  undefined8 *local_38;
  ulonglong local_30;
  
  puVar7 = auStack_78;
  puVar8 = auStack_78;
  local_30 = DAT_180077818 ^ (ulonglong)&local_38;
  _Memory = (undefined8 *)0x0;
  local_38 = (undefined8 *)0x0;
  if ((param_3 == (LPCWSTR)0x0) || (param_4 == (LPCWSTR)0x0)) {
    DVar3 = 0x80070057;
    goto joined_r0x000180035d76;
  }
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (param_3[lVar4] != L'\0');
  lVar4 = (longlong)((int)lVar4 + 1) * 2;
  puVar7 = auStack_78;
  if (lVar4 + 0x80000000U < 0x100000000) {
    iVar2 = (int)lVar4;
    uVar9 = (ulonglong)iVar2;
    if ((iVar2 < 0x401) && (cVar1 = FUN_1800026d0(uVar9), cVar1 != '\0')) {
      uVar5 = uVar9 + 0xf;
      if (uVar5 <= uVar9) {
        uVar5 = 0xffffffffffffff0;
      }
      puVar8 = auStack_78 + -(uVar5 & 0xfffffffffffffff0);
      pCVar10 = (LPCSTR)((longlong)&local_38 + -(uVar5 & 0xfffffffffffffff0));
      puVar6 = _Memory;
    }
    else {
      if (~uVar9 < 0x10) {
                    /* WARNING: Subroutine does not return */
        FUN_180001a90(-0x7ff8fdea);
      }
      puVar6 = malloc(uVar9 + 0x10);
      puVar7 = auStack_78;
      if (puVar6 == (undefined8 *)0x0) goto LAB_180035c61;
      *puVar6 = 0;
      local_38 = puVar6;
      pCVar10 = (LPCSTR)(puVar6 + 2);
    }
    _Memory = puVar6;
    puVar7 = puVar8;
    if (pCVar10 == (LPCSTR)0x0) goto LAB_180035c61;
    *pCVar10 = '\0';
    *(undefined8 *)(puVar8 + 0x38) = 0;
    *(undefined8 *)(puVar8 + 0x30) = 0;
    *(int *)(puVar8 + 0x28) = iVar2;
    *(LPCSTR *)(puVar8 + 0x20) = pCVar10;
    *(undefined8 *)(puVar8 + -8) = 0x180035c3a;
    iVar2 = WideCharToMultiByte(0,0,param_3,-1,*(LPSTR *)(puVar8 + 0x20),*(int *)(puVar8 + 0x28),
                                *(LPCSTR *)(puVar8 + 0x30),*(LPBOOL *)(puVar8 + 0x38));
    if (iVar2 == 0) {
      pCVar10 = (LPCSTR)0x0;
    }
  }
  else {
LAB_180035c61:
    puVar8 = puVar7;
    puVar6 = _Memory;
    pCVar10 = (LPCSTR)0x0;
  }
  pCVar11 = (LPCSTR)0x0;
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (param_4[lVar4] != L'\0');
  lVar4 = (longlong)((int)lVar4 + 1) * 2;
  _Memory = puVar6;
  if (lVar4 + 0x80000000U < 0x100000000) {
    iVar2 = (int)lVar4;
    uVar9 = (ulonglong)iVar2;
    if (iVar2 < 0x401) {
      *(undefined8 *)(puVar8 + -8) = 0x180035ca4;
      cVar1 = FUN_1800026d0(uVar9);
      if (cVar1 == '\0') goto LAB_180035cce;
      uVar5 = uVar9 + 0xf;
      if (uVar5 <= uVar9) {
        uVar5 = 0xffffffffffffff0;
      }
      *(undefined8 *)(puVar8 + -8) = 0x180035cc4;
      pCVar11 = puVar8 + -(uVar5 & 0xfffffffffffffff0) + 0x40;
      puVar8 = puVar8 + -(uVar5 & 0xfffffffffffffff0);
LAB_180035cfb:
      puVar6 = _Memory;
      if (pCVar11 != (LPCSTR)0x0) {
        *pCVar11 = '\0';
        *(undefined8 *)(puVar8 + 0x38) = 0;
        *(undefined8 *)(puVar8 + 0x30) = 0;
        *(int *)(puVar8 + 0x28) = iVar2;
        *(LPCSTR *)(puVar8 + 0x20) = pCVar11;
        *(undefined8 *)(puVar8 + -8) = 0x180035d2a;
        iVar2 = WideCharToMultiByte(0,0,param_4,-1,*(LPSTR *)(puVar8 + 0x20),*(int *)(puVar8 + 0x28)
                                    ,*(LPCSTR *)(puVar8 + 0x30),*(LPBOOL *)(puVar8 + 0x38));
        if (iVar2 == 0) {
          pCVar11 = (LPCSTR)0x0;
        }
        goto LAB_180035d40;
      }
    }
    else {
LAB_180035cce:
      if (~uVar9 < 0x10) {
                    /* WARNING: Subroutine does not return */
        *(undefined **)(puVar8 + -8) = &UNK_180035dc3;
        FUN_180001a90(-0x7ff8fdea);
      }
      *(undefined8 *)(puVar8 + -8) = 0x180035ce8;
      _Memory = malloc(uVar9 + 0x10);
      if (_Memory != (undefined8 *)0x0) {
        *_Memory = puVar6;
        local_38 = _Memory;
        pCVar11 = (LPCSTR)(_Memory + 2);
        goto LAB_180035cfb;
      }
    }
    pCVar11 = (LPCSTR)0x0;
    _Memory = puVar6;
  }
LAB_180035d40:
  puVar7 = puVar8;
  if ((pCVar10 == (LPCSTR)0x0) || (pCVar11 == (LPCSTR)0x0)) {
    DVar3 = 0x8007000e;
  }
  else {
    *(undefined4 *)(puVar8 + 0x20) = 1;
    *(undefined8 *)(puVar8 + -8) = 0x180035d63;
    DVar3 = FUN_180034920(param_1,param_2,pCVar10,pCVar11,*(int *)(puVar8 + 0x20));
  }
joined_r0x000180035d76:
  while (_Memory != (undefined8 *)0x0) {
    puVar6 = (undefined8 *)*_Memory;
    *(undefined8 *)(puVar7 + -8) = 0x180035d8c;
    free(_Memory);
    _Memory = puVar6;
  }
  *(undefined8 *)(puVar7 + -8) = 0x180035d9f;
  return DVar3;
}

/* ---- FUNC 00035DD0 FUN_180035dd0 (686 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

DWORD FUN_180035dd0(undefined8 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

{
  char cVar1;
  int iVar2;
  DWORD DVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  undefined8 *_Memory;
  undefined1 *puVar7;
  undefined1 *puVar8;
  ulonglong uVar9;
  LPCSTR pCVar10;
  LPCSTR pCVar11;
  undefined1 auStack_78 [64];
  undefined8 *local_38;
  ulonglong local_30;
  
  puVar8 = auStack_78;
  puVar7 = auStack_78;
  local_30 = DAT_180077818 ^ (ulonglong)&local_38;
  _Memory = (undefined8 *)0x0;
  local_38 = (undefined8 *)0x0;
  if ((param_3 == (LPCWSTR)0x0) || (param_4 == (LPCWSTR)0x0)) {
    DVar3 = 0x80070057;
    goto joined_r0x00018003602c;
  }
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (param_3[lVar4] != L'\0');
  lVar4 = (longlong)((int)lVar4 + 1) * 2;
  puVar8 = auStack_78;
  if (lVar4 + 0x80000000U < 0x100000000) {
    iVar2 = (int)lVar4;
    uVar9 = (ulonglong)iVar2;
    if ((iVar2 < 0x401) && (cVar1 = FUN_1800026d0(uVar9), cVar1 != '\0')) {
      uVar5 = uVar9 + 0xf;
      if (uVar5 <= uVar9) {
        uVar5 = 0xffffffffffffff0;
      }
      puVar7 = auStack_78 + -(uVar5 & 0xfffffffffffffff0);
      pCVar10 = (LPCSTR)((longlong)&local_38 + -(uVar5 & 0xfffffffffffffff0));
      puVar6 = _Memory;
    }
    else {
      if (~uVar9 < 0x10) {
                    /* WARNING: Subroutine does not return */
        FUN_180001a90(-0x7ff8fdea);
      }
      puVar6 = malloc(uVar9 + 0x10);
      puVar8 = auStack_78;
      if (puVar6 == (undefined8 *)0x0) goto LAB_180035f21;
      *puVar6 = 0;
      local_38 = puVar6;
      pCVar10 = (LPCSTR)(puVar6 + 2);
    }
    _Memory = puVar6;
    puVar8 = puVar7;
    if (pCVar10 == (LPCSTR)0x0) goto LAB_180035f21;
    *pCVar10 = '\0';
    *(undefined8 *)(puVar7 + 0x38) = 0;
    *(undefined8 *)(puVar7 + 0x30) = 0;
    *(int *)(puVar7 + 0x28) = iVar2;
    *(LPCSTR *)(puVar7 + 0x20) = pCVar10;
    *(undefined8 *)(puVar7 + -8) = 0x180035efa;
    iVar2 = WideCharToMultiByte(0,0,param_3,-1,*(LPSTR *)(puVar7 + 0x20),*(int *)(puVar7 + 0x28),
                                *(LPCSTR *)(puVar7 + 0x30),*(LPBOOL *)(puVar7 + 0x38));
    if (iVar2 == 0) {
      pCVar10 = (LPCSTR)0x0;
    }
  }
  else {
LAB_180035f21:
    puVar7 = puVar8;
    puVar6 = _Memory;
    pCVar10 = (LPCSTR)0x0;
  }
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (param_4[lVar4] != L'\0');
  lVar4 = (longlong)((int)lVar4 + 1) * 2;
  if (lVar4 + 0x80000000U < 0x100000000) {
    iVar2 = (int)lVar4;
    uVar9 = (ulonglong)iVar2;
    if (iVar2 < 0x401) {
      *(undefined8 *)(puVar7 + -8) = 0x180035f64;
      cVar1 = FUN_1800026d0(uVar9);
      if (cVar1 == '\0') goto LAB_180035f8e;
      uVar5 = uVar9 + 0xf;
      if (uVar5 <= uVar9) {
        uVar5 = 0xffffffffffffff0;
      }
      *(undefined8 *)(puVar7 + -8) = 0x180035f84;
      pCVar11 = puVar7 + -(uVar5 & 0xfffffffffffffff0) + 0x40;
      _Memory = puVar6;
      puVar7 = puVar7 + -(uVar5 & 0xfffffffffffffff0);
    }
    else {
LAB_180035f8e:
      if (~uVar9 < 0x10) {
                    /* WARNING: Subroutine does not return */
        *(undefined **)(puVar7 + -8) = &UNK_180036073;
        FUN_180001a90(-0x7ff8fdea);
      }
      *(undefined8 *)(puVar7 + -8) = 0x180035fa8;
      _Memory = malloc(uVar9 + 0x10);
      if (_Memory == (undefined8 *)0x0) goto LAB_180035ff7;
      *_Memory = puVar6;
      local_38 = _Memory;
      pCVar11 = (LPCSTR)(_Memory + 2);
    }
    puVar6 = _Memory;
    if (pCVar11 == (LPCSTR)0x0) goto LAB_180035ff7;
    *pCVar11 = '\0';
    *(undefined8 *)(puVar7 + 0x38) = 0;
    *(undefined8 *)(puVar7 + 0x30) = 0;
    *(int *)(puVar7 + 0x28) = iVar2;
    *(LPCSTR *)(puVar7 + 0x20) = pCVar11;
    *(undefined8 *)(puVar7 + -8) = 0x180035fe8;
    iVar2 = WideCharToMultiByte(0,0,param_4,-1,*(LPSTR *)(puVar7 + 0x20),*(int *)(puVar7 + 0x28),
                                *(LPCSTR *)(puVar7 + 0x30),*(LPBOOL *)(puVar7 + 0x38));
    if (iVar2 == 0) {
      pCVar11 = (LPCSTR)0x0;
    }
  }
  else {
LAB_180035ff7:
    _Memory = puVar6;
    pCVar11 = (LPCSTR)0x0;
  }
  puVar8 = puVar7;
  if ((pCVar10 == (LPCSTR)0x0) || (pCVar11 == (LPCSTR)0x0)) {
    DVar3 = 0x8007000e;
  }
  else {
    *(undefined4 *)(puVar7 + 0x20) = 0;
    *(undefined8 *)(puVar7 + -8) = 0x180036019;
    DVar3 = FUN_180034920(param_1,param_2,pCVar10,pCVar11,*(int *)(puVar7 + 0x20));
  }
joined_r0x00018003602c:
  while (_Memory != (undefined8 *)0x0) {
    puVar6 = (undefined8 *)*_Memory;
    *(undefined8 *)(puVar8 + -8) = 0x18003603c;
    free(_Memory);
    _Memory = puVar6;
  }
  *(undefined8 *)(puVar8 + -8) = 0x18003604f;
  return DVar3;
}

/* ---- FUNC 00036080 FUN_180036080 (178 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180036080(undefined8 *param_1,char *param_2)

{
  char cVar1;
  ulonglong uVar2;
  LPSTR pCVar3;
  ulonglong uVar4;
  undefined1 auStack_1038 [32];
  undefined1 local_1018 [4096];
  ulonglong local_18;
  undefined8 uStack_10;
  
  uStack_10 = 0x180036090;
  local_18 = DAT_180077818 ^ (ulonglong)auStack_1038;
  if (*param_2 == '=') {
    uVar2 = FUN_180033b80(param_1,param_2);
    if (-1 < (int)uVar2) {
      while( true ) {
        cVar1 = *(LPCSTR)*param_1;
        if ((((cVar1 != '\t') && (cVar1 != '\n')) && (cVar1 != '\r')) && (cVar1 != ' ')) break;
        pCVar3 = CharNextA((LPCSTR)*param_1);
        *param_1 = pCVar3;
      }
      uVar2 = FUN_180033b80(param_1,local_1018);
      if (-1 < (int)uVar2) {
        uVar4 = FUN_180033b80(param_1,param_2);
        uVar2 = 0;
        if ((int)uVar4 < 0) {
          uVar2 = uVar4 & 0xffffffff;
        }
      }
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* ---- FUNC 00036140 FUN_180036140 (21 bytes) ---- */

void FUN_180036140(longlong param_1)

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
        FUN_180037630(0xc0000005,1);
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      puVar3 = *(undefined8 **)(lVar4 + 8);
      while (puVar3 != (undefined8 *)0x0) {
        (*(code *)*puVar3)(puVar3[1]);
        puVar1 = (undefined8 *)puVar3[2];
        FUN_180025ad0(puVar3);
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

/* ---- FUNC 00036155 FUN_180036155 (35 bytes) ---- */

void FUN_180036155(longlong param_1)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong unaff_RSI;
  
  if (*(longlong *)(param_1 + 0x10) != 0) {
    lVar4 = param_1 + 8;
    if (param_1 == 0) {
      lVar4 = 0;
    }
    if (lVar4 == 0) {
      FUN_180037630(0xc0000005,1);
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    puVar3 = *(undefined8 **)(lVar4 + 8);
    while (puVar3 != (undefined8 *)0x0) {
      (*(code *)*puVar3)(puVar3[1]);
      puVar1 = (undefined8 *)puVar3[2];
      FUN_180025ad0(puVar3);
      puVar3 = puVar1;
    }
    *(undefined8 *)(lVar4 + 8) = 0;
    *(undefined8 *)(unaff_RSI + 0x10) = 0;
  }
  if (*(longlong **)(unaff_RSI + 0x40) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(unaff_RSI + 0x40) + 0x10))();
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(unaff_RSI + 0x18));
  *(undefined4 *)(unaff_RSI + 8) = 0;
  return;
}

/* ---- FUNC 00036178 FUN_180036178 (14 bytes) ---- */

void FUN_180036178(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  longlong unaff_RBP;
  longlong unaff_RSI;
  undefined8 unaff_R15;
  
  puVar2 = *(undefined8 **)(unaff_RBP + 8);
  while (puVar2 != (undefined8 *)0x0) {
    (*(code *)*puVar2)(puVar2[1]);
    puVar1 = (undefined8 *)puVar2[2];
    FUN_180025ad0(puVar2);
    puVar2 = puVar1;
  }
  *(undefined8 *)(unaff_RBP + 8) = unaff_R15;
  *(undefined8 *)(unaff_RSI + 0x10) = unaff_R15;
  if (*(longlong **)(unaff_RSI + 0x40) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(unaff_RSI + 0x40) + 0x10))();
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(unaff_RSI + 0x18));
  *(int *)(unaff_RSI + 8) = (int)unaff_R15;
  return;
}

/* ---- FUNC 00036186 FUN_180036186 (46 bytes) ---- */

void FUN_180036186(void)

{
  undefined8 *puVar1;
  longlong unaff_RBP;
  longlong unaff_RSI;
  undefined8 *unaff_RDI;
  undefined8 unaff_R15;
  
  do {
    (*(code *)*unaff_RDI)(unaff_RDI[1]);
    puVar1 = (undefined8 *)unaff_RDI[2];
    FUN_180025ad0(unaff_RDI);
    unaff_RDI = puVar1;
  } while (puVar1 != (undefined8 *)0x0);
  *(undefined8 *)(unaff_RBP + 8) = unaff_R15;
  *(undefined8 *)(unaff_RSI + 0x10) = unaff_R15;
  if (*(longlong **)(unaff_RSI + 0x40) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(unaff_RSI + 0x40) + 0x10))();
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(unaff_RSI + 0x18));
  *(int *)(unaff_RSI + 8) = (int)unaff_R15;
  return;
}

/* ---- FUNC 000361B4 FUN_1800361b4 (13 bytes) ---- */

void FUN_1800361b4(void)

{
  longlong unaff_RBP;
  longlong unaff_RSI;
  undefined8 unaff_R15;
  
  *(undefined8 *)(unaff_RBP + 8) = unaff_R15;
  *(undefined8 *)(unaff_RSI + 0x10) = unaff_R15;
  if (*(longlong **)(unaff_RSI + 0x40) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(unaff_RSI + 0x40) + 0x10))();
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(unaff_RSI + 0x18));
  *(int *)(unaff_RSI + 8) = (int)unaff_R15;
  return;
}

/* ---- FUNC 000361C1 FUN_1800361c1 (39 bytes) ---- */

void FUN_1800361c1(void)

{
  longlong unaff_RSI;
  undefined4 unaff_R15D;
  
  if (*(longlong **)(unaff_RSI + 0x40) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(unaff_RSI + 0x40) + 0x10))();
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(unaff_RSI + 0x18));
  *(undefined4 *)(unaff_RSI + 8) = unaff_R15D;
  return;
}

/* ---- FUNC 000361E8 FUN_1800361e8 (8 bytes) ---- */

void FUN_1800361e8(void)

{
  return;
}

/* ---- FUNC 000361F0 FUN_1800361f0 (16 bytes) ---- */

void FUN_1800361f0(void)

{
  code *pcVar1;
  
  FUN_180037630(0xc0000005,1);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

/* ---- FUNC 00036200 FUN_180036200 (2279 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */

DWORD FUN_180036200(longlong *param_1,undefined4 param_2,int param_3,undefined8 *param_4)

{
  char *pcVar1;
  WCHAR WVar2;
  HMODULE pHVar3;
  char cVar4;
  BOOL BVar5;
  DWORD DVar6;
  int iVar7;
  uint uVar8;
  longlong lVar9;
  ulonglong uVar10;
  undefined8 *puVar11;
  HMODULE pHVar12;
  longlong lVar13;
  int *piVar14;
  undefined8 *puVar15;
  WCHAR *pWVar16;
  WCHAR *pWVar17;
  undefined1 *puVar18;
  undefined1 *puVar19;
  ulonglong uVar20;
  LPCSTR pCVar21;
  undefined8 *puVar22;
  LPCWSTR pWVar23;
  LPCWSTR pWVar24;
  LPCSTR pCVar25;
  undefined1 auStack_a28 [64];
  undefined **local_9e8;
  void *local_9e0;
  void *local_9d8;
  int local_9d0;
  _RTL_CRITICAL_SECTION local_9c8;
  char local_9a0;
  undefined4 local_998;
  CHAR local_988;
  char acStack_987 [271];
  WCHAR local_878 [528];
  WCHAR local_458 [520];
  ulonglong local_48;
  
  puVar18 = auStack_a28;
  local_48 = DAT_180077818 ^ (ulonglong)&local_9e8;
  local_9e8 = ATL::CRegObject::vftable;
  puVar15 = (undefined8 *)0x0;
  local_9e0 = (void *)0x0;
  local_9d8 = (void *)0x0;
  local_9d0 = 0;
  local_9c8.DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
  local_9c8.LockCount = 0;
  local_9c8.RecursionCount = 0;
  local_9c8.OwningThread = (HANDLE)0x0;
  local_9c8.LockSemaphore = (HANDLE)0x0;
  local_9c8.SpinCount = 0;
  local_9a0 = '\0';
  local_998 = param_2;
  BVar5 = InitializeCriticalSectionEx(&local_9c8,0,0);
  if (BVar5 == 0) {
    DVar6 = GetLastError();
    if (0 < (int)DVar6) {
      DVar6 = DVar6 & 0xffff | 0x80070000;
    }
    if ((int)DVar6 < 0) {
      local_9e8 = ATL::CRegObject::vftable;
      EnterCriticalSection(&local_9c8);
      puVar11 = puVar15;
      puVar22 = puVar15;
      if (0 < local_9d0) {
        do {
          if ((((longlong)puVar11 < 0) || (iVar7 = (int)puVar22, local_9d0 <= iVar7)) ||
             (operator_delete__(*(void **)((longlong)puVar11 + (longlong)local_9e0)),
             local_9d0 <= iVar7)) {
                    /* WARNING: Subroutine does not return */
            FUN_180001a90(-0x7ffffff5);
          }
          operator_delete__(*(void **)((longlong)puVar11 + (longlong)local_9d8));
          puVar11 = puVar11 + 1;
          puVar22 = (undefined8 *)(ulonglong)(iVar7 + 1U);
        } while ((int)(iVar7 + 1U) < local_9d0);
      }
      if (local_9e0 != (void *)0x0) {
        free(local_9e0);
        local_9e0 = (void *)0x0;
      }
      if (local_9d8 != (void *)0x0) {
        free(local_9d8);
        local_9d8 = (void *)0x0;
      }
      local_9d0 = 0;
      LeaveCriticalSection(&local_9c8);
      if (local_9a0 != '\0') {
        local_9a0 = '\0';
        DeleteCriticalSection(&local_9c8);
      }
      puVar11 = puVar15;
      if (0 < local_9d0) {
        do {
          if ((((longlong)puVar11 < 0) || (iVar7 = (int)puVar15, local_9d0 <= iVar7)) ||
             (operator_delete__(*(void **)((longlong)puVar11 + (longlong)local_9e0)),
             local_9d0 <= iVar7)) {
                    /* WARNING: Subroutine does not return */
            FUN_180001a90(-0x7ffffff5);
          }
          operator_delete__(*(void **)((longlong)puVar11 + (longlong)local_9d8));
          puVar15 = (undefined8 *)(ulonglong)(iVar7 + 1U);
          puVar11 = puVar11 + 1;
        } while ((int)(iVar7 + 1U) < local_9d0);
      }
      if (local_9e0 != (void *)0x0) {
        free(local_9e0);
        local_9e0 = (void *)0x0;
      }
      if (local_9d8 != (void *)0x0) {
        free(local_9d8);
        local_9d8 = (void *)0x0;
      }
      local_9d0 = 0;
      if (local_9e0 != (void *)0x0) {
        free(local_9e0);
        local_9e0 = (void *)0x0;
      }
      puVar18 = auStack_a28;
      if (local_9d8 != (void *)0x0) {
        free(local_9d8);
        puVar18 = auStack_a28;
      }
      goto LAB_180036a82;
    }
  }
  local_9a0 = '\x01';
  if (param_4 != (undefined8 *)0x0) {
    pWVar23 = (LPCWSTR)*param_4;
    while (pWVar23 != (LPCWSTR)0x0) {
      FUN_180031840((longlong)&local_9e8,pWVar23,(void *)param_4[1]);
      param_4 = param_4 + 2;
      pWVar23 = (LPCWSTR)*param_4;
    }
  }
  DVar6 = (**(code **)(*param_1 + 0x28))(param_1,&local_9e8);
  pHVar3 = DAT_18007a618;
  if ((int)DVar6 < 0) {
    local_9e8 = ATL::CRegObject::vftable;
    EnterCriticalSection(&local_9c8);
    puVar11 = puVar15;
    puVar22 = puVar15;
    if (0 < local_9d0) {
      do {
        if ((((longlong)puVar11 < 0) || (iVar7 = (int)puVar22, local_9d0 <= iVar7)) ||
           (operator_delete__(*(void **)((longlong)puVar11 + (longlong)local_9e0)),
           local_9d0 <= iVar7)) {
                    /* WARNING: Subroutine does not return */
          FUN_180001a90(-0x7ffffff5);
        }
        operator_delete__(*(void **)((longlong)puVar11 + (longlong)local_9d8));
        puVar11 = puVar11 + 1;
        puVar22 = (undefined8 *)(ulonglong)(iVar7 + 1U);
      } while ((int)(iVar7 + 1U) < local_9d0);
    }
    if (local_9e0 != (void *)0x0) {
      free(local_9e0);
      local_9e0 = (void *)0x0;
    }
    if (local_9d8 != (void *)0x0) {
      free(local_9d8);
      local_9d8 = (void *)0x0;
    }
    local_9d0 = 0;
    LeaveCriticalSection(&local_9c8);
    if (local_9a0 != '\0') {
      local_9a0 = '\0';
      DeleteCriticalSection(&local_9c8);
    }
    puVar11 = puVar15;
    if (0 < local_9d0) {
      do {
        if ((((longlong)puVar11 < 0) || (iVar7 = (int)puVar15, local_9d0 <= iVar7)) ||
           (operator_delete__(*(void **)((longlong)puVar11 + (longlong)local_9e0)),
           local_9d0 <= iVar7)) {
                    /* WARNING: Subroutine does not return */
          FUN_180001a90(-0x7ffffff5);
        }
        operator_delete__(*(void **)((longlong)puVar11 + (longlong)local_9d8));
        puVar15 = (undefined8 *)(ulonglong)(iVar7 + 1U);
        puVar11 = puVar11 + 1;
      } while ((int)(iVar7 + 1U) < local_9d0);
    }
    if (local_9e0 != (void *)0x0) {
      free(local_9e0);
      local_9e0 = (void *)0x0;
    }
    if (local_9d8 != (void *)0x0) {
      free(local_9d8);
      local_9d8 = (void *)0x0;
    }
    local_9d0 = 0;
    if (local_9e0 != (void *)0x0) {
      free(local_9e0);
      local_9e0 = (void *)0x0;
    }
    puVar18 = auStack_a28;
    if (local_9d8 != (void *)0x0) {
      free(local_9d8);
      puVar18 = auStack_a28;
    }
    goto LAB_180036a82;
  }
  DVar6 = GetModuleFileNameA(DAT_18007a618,&local_988,0x104);
  if (DVar6 == 0) {
    DVar6 = FUN_1800333f0();
    FUN_180032790(&local_9e8);
    puVar18 = auStack_a28;
    goto LAB_180036a82;
  }
  if (DVar6 == 0x104) {
    FUN_180032790(&local_9e8);
    DVar6 = 0x8007007a;
    puVar18 = auStack_a28;
    goto LAB_180036a82;
  }
  lVar13 = -1;
  do {
    lVar9 = lVar13 + 1;
    pcVar1 = acStack_987 + lVar13;
    lVar13 = lVar9;
  } while (*pcVar1 != '\0');
  lVar13 = (longlong)((int)lVar9 + 1) * 2;
  puVar19 = auStack_a28;
  if (lVar13 + 0x80000000U < 0x100000000) {
    iVar7 = (int)lVar13;
    uVar20 = (ulonglong)iVar7;
    if ((iVar7 < 0x401) && (cVar4 = FUN_1800026d0(uVar20), cVar4 != '\0')) {
      uVar10 = uVar20 + 0xf;
      if (uVar10 <= uVar20) {
        uVar10 = 0xffffffffffffff0;
      }
      puVar18 = auStack_a28 + -(uVar10 & 0xfffffffffffffff0);
      pWVar23 = (LPCWSTR)((longlong)&local_9e8 + -(uVar10 & 0xfffffffffffffff0));
      puVar11 = puVar15;
    }
    else {
      if (~uVar20 < 0x10) {
                    /* WARNING: Subroutine does not return */
        FUN_180001a90(-0x7ff8fdea);
      }
      puVar11 = malloc(uVar20 + 0x10);
      puVar19 = auStack_a28;
      if (puVar11 == (undefined8 *)0x0) goto LAB_180036a74;
      *puVar11 = 0;
      pWVar23 = (LPCWSTR)(puVar11 + 2);
    }
    if (pWVar23 != (LPCWSTR)0x0) {
      *pWVar23 = L'\0';
      *(int *)(puVar18 + 0x28) = (int)(uVar20 >> 1);
      *(LPCWSTR *)(puVar18 + 0x20) = pWVar23;
      *(undefined8 *)(puVar18 + -8) = 0x1800366b2;
      iVar7 = MultiByteToWideChar(0,0,&local_988,-1,*(LPWSTR *)(puVar18 + 0x20),
                                  *(int *)(puVar18 + 0x28));
      if (iVar7 != 0) {
        pWVar16 = local_458;
        pWVar24 = pWVar23;
        do {
          uVar8 = (uint)puVar15;
          WVar2 = *pWVar24;
          pWVar17 = pWVar16;
          if (WVar2 == L'\0') break;
          *pWVar16 = WVar2;
          pWVar17 = pWVar16 + 1;
          if ((WVar2 == L'\'') && (uVar8 = uVar8 + 1, uVar8 < 0x207)) {
            *pWVar17 = L'\'';
            pWVar17 = pWVar16 + 2;
          }
          pWVar24 = pWVar24 + 1;
          puVar15 = (undefined8 *)(ulonglong)(uVar8 + 1);
          pWVar16 = pWVar17;
        } while (uVar8 + 1 < 0x207);
        *pWVar17 = L'\0';
        if (pHVar3 == (HMODULE)0x0) {
LAB_180036720:
          local_878[0] = L'\"';
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (local_458[lVar13] != L'\0');
          uVar20 = (longlong)((int)lVar13 + 1) * 2;
          if (uVar20 != 0) {
            if (0x416 < uVar20) {
              *(undefined8 *)(puVar18 + -8) = 0x180036801;
              memset(local_878 + 1,0,0x416);
              *(undefined8 *)(puVar18 + -8) = 0x180036807;
              piVar14 = _errno();
              *piVar14 = 0x22;
              *(undefined8 *)(puVar18 + -8) = 0x18003680f;
              _invalid_parameter_noinfo();
              while (puVar11 != (undefined8 *)0x0) {
                puVar15 = (undefined8 *)*puVar11;
                *(undefined8 *)(puVar18 + -8) = 0x180036820;
                free(puVar11);
                puVar11 = puVar15;
              }
              *(undefined8 *)(puVar18 + -8) = 0x18003682e;
              FUN_180032790(&local_9e8);
              DVar6 = 0x80004005;
              goto LAB_180036a82;
            }
            *(undefined8 *)(puVar18 + -8) = 0x180036769;
            memcpy(local_878 + 1,local_458,uVar20);
          }
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (local_878[lVar13] != L'\0');
          lVar13 = (longlong)(int)lVar13;
          local_878[lVar13] = L'\"';
          if (0x417 < lVar13 * 2 + 2U) {
                    /* WARNING: Subroutine does not return */
            *(undefined8 *)(puVar18 + -8) = 0x180036ab0;
            FUN_18005c254();
          }
          local_878[lVar13 + 1] = 0;
          pWVar16 = local_878;
        }
        else {
          *(undefined8 *)(puVar18 + -8) = 0x18003670f;
          pHVar12 = GetModuleHandleA((LPCSTR)0x0);
          if (pHVar3 == pHVar12) goto LAB_180036720;
          pWVar16 = local_458;
        }
        *(undefined8 *)(puVar18 + -8) = 0x1800367c8;
        DVar6 = FUN_180031840((longlong)&local_9e8,L"Module",pWVar16);
        if ((int)DVar6 < 0) {
          while (puVar11 != (undefined8 *)0x0) {
            puVar15 = (undefined8 *)*puVar11;
            *(undefined8 *)(puVar18 + -8) = 0x1800367df;
            free(puVar11);
            puVar11 = puVar15;
          }
          *(undefined8 *)(puVar18 + -8) = 0x1800367ed;
          FUN_180032790(&local_9e8);
          goto LAB_180036a82;
        }
        *(undefined8 *)(puVar18 + -8) = 0x18003684f;
        DVar6 = FUN_180031840((longlong)&local_9e8,L"Module_Raw",local_458);
        if ((int)DVar6 < 0) {
          while (puVar11 != (undefined8 *)0x0) {
            puVar15 = (undefined8 *)*puVar11;
            *(undefined8 *)(puVar18 + -8) = 0x18003686c;
            free(puVar11);
            puVar11 = puVar15;
          }
          *(undefined8 *)(puVar18 + -8) = 0x18003687a;
          FUN_180032790(&local_9e8);
          goto LAB_180036a82;
        }
        if (param_3 == 0) {
          puVar15 = (undefined8 *)0x0;
          *(undefined8 *)(puVar18 + -8) = 0x180036971;
          cVar4 = FUN_1800026d0(0x12);
          if (cVar4 == '\0') {
            *(undefined8 *)(puVar18 + -8) = 0x18003698e;
            puVar15 = malloc(0x22);
            if (puVar15 == (undefined8 *)0x0) goto LAB_180036a31;
            *puVar15 = 0;
            pCVar21 = (LPCSTR)(puVar15 + 2);
          }
          else {
            pCVar21 = puVar18 + 0x20;
            puVar18 = puVar18 + -0x20;
          }
          if (pCVar21 == (LPCSTR)0x0) {
joined_r0x000180036a16:
            while (puVar15 != (undefined8 *)0x0) {
              puVar22 = (undefined8 *)*puVar15;
              *(undefined8 *)(puVar18 + -8) = 0x180036a2c;
              free(puVar15);
              puVar15 = puVar22;
            }
            goto LAB_180036a31;
          }
          *pCVar21 = '\0';
          *(undefined8 *)(puVar18 + 0x38) = 0;
          *(undefined8 *)(puVar18 + 0x30) = 0;
          *(undefined4 *)(puVar18 + 0x28) = 0x12;
          *(LPCSTR *)(puVar18 + 0x20) = pCVar21;
          *(undefined8 *)(puVar18 + -8) = 0x1800369d7;
          iVar7 = WideCharToMultiByte(0,0,L"REGISTRY",-1,*(LPSTR *)(puVar18 + 0x20),
                                      *(int *)(puVar18 + 0x28),*(LPCSTR *)(puVar18 + 0x30),
                                      *(LPBOOL *)(puVar18 + 0x38));
          if (iVar7 == 0) goto joined_r0x000180036a16;
          pCVar25 = (LPCSTR)(ulonglong)(ushort)local_998;
          *(undefined4 *)(puVar18 + 0x20) = 0;
          *(undefined8 *)(puVar18 + -8) = 0x1800369f4;
          DVar6 = FUN_180034920(&local_9e8,pWVar23,pCVar25,pCVar21,*(int *)(puVar18 + 0x20));
          while (puVar15 != (undefined8 *)0x0) {
            puVar22 = (undefined8 *)*puVar15;
            *(undefined8 *)(puVar18 + -8) = 0x180036a0c;
            free(puVar15);
            puVar15 = puVar22;
          }
        }
        else {
          puVar15 = (undefined8 *)0x0;
          *(undefined8 *)(puVar18 + -8) = 0x18003689a;
          cVar4 = FUN_1800026d0(0x12);
          if (cVar4 == '\0') {
            *(undefined8 *)(puVar18 + -8) = 0x1800368b7;
            puVar15 = malloc(0x22);
            if (puVar15 == (undefined8 *)0x0) goto LAB_180036a31;
            *puVar15 = 0;
            pCVar21 = (LPCSTR)(puVar15 + 2);
          }
          else {
            pCVar21 = puVar18 + 0x20;
            puVar18 = puVar18 + -0x20;
          }
          if (pCVar21 != (LPCSTR)0x0) {
            *pCVar21 = '\0';
            *(undefined8 *)(puVar18 + 0x38) = 0;
            *(undefined8 *)(puVar18 + 0x30) = 0;
            *(undefined4 *)(puVar18 + 0x28) = 0x12;
            *(LPCSTR *)(puVar18 + 0x20) = pCVar21;
            *(undefined8 *)(puVar18 + -8) = 0x180036900;
            iVar7 = WideCharToMultiByte(0,0,L"REGISTRY",-1,*(LPSTR *)(puVar18 + 0x20),
                                        *(int *)(puVar18 + 0x28),*(LPCSTR *)(puVar18 + 0x30),
                                        *(LPBOOL *)(puVar18 + 0x38));
            if (iVar7 != 0) {
              pCVar25 = (LPCSTR)(ulonglong)(ushort)local_998;
              *(undefined4 *)(puVar18 + 0x20) = 1;
              *(undefined8 *)(puVar18 + -8) = 0x180036920;
              DVar6 = FUN_180034920(&local_9e8,pWVar23,pCVar25,pCVar21,*(int *)(puVar18 + 0x20));
              while (puVar15 != (undefined8 *)0x0) {
                puVar22 = (undefined8 *)*puVar15;
                *(undefined8 *)(puVar18 + -8) = 0x18003693c;
                free(puVar15);
                puVar15 = puVar22;
              }
              goto joined_r0x000180036a39;
            }
          }
          while (puVar15 != (undefined8 *)0x0) {
            puVar22 = (undefined8 *)*puVar15;
            *(undefined8 *)(puVar18 + -8) = 0x18003695c;
            free(puVar15);
            puVar15 = puVar22;
          }
LAB_180036a31:
          DVar6 = 0x8007000e;
        }
joined_r0x000180036a39:
        while (puVar11 != (undefined8 *)0x0) {
          puVar15 = (undefined8 *)*puVar11;
          *(undefined8 *)((longlong)puVar18 + -8) = 0x180036a4c;
          free(puVar11);
          puVar11 = puVar15;
        }
        *(undefined8 *)((longlong)puVar18 + -8) = 0x180036a5a;
        FUN_180032790(&local_9e8);
        goto LAB_180036a82;
      }
    }
    while (puVar19 = puVar18, puVar11 != (undefined8 *)0x0) {
      puVar15 = (undefined8 *)*puVar11;
      *(undefined8 *)(puVar18 + -8) = 0x180036a6f;
      free(puVar11);
      puVar11 = puVar15;
    }
  }
LAB_180036a74:
  *(undefined8 *)(puVar19 + -8) = 0x180036a7d;
  FUN_180032790(&local_9e8);
  DVar6 = 0x8007000e;
  puVar18 = puVar19;
LAB_180036a82:
  *(undefined8 *)(puVar18 + -8) = 0x180036a91;
  return DVar6;
}

/* ---- FUNC 00036AF0 FUN_180036af0 (2187 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */

DWORD FUN_180036af0(longlong *param_1,LPCSTR param_2,int param_3,undefined8 *param_4)

{
  char *pcVar1;
  WCHAR WVar2;
  HMODULE pHVar3;
  char cVar4;
  BOOL BVar5;
  DWORD DVar6;
  int iVar7;
  uint uVar8;
  longlong lVar9;
  ulonglong uVar10;
  LPCWSTR pWVar11;
  LPCWSTR pWVar12;
  HMODULE pHVar13;
  int *piVar14;
  longlong lVar15;
  LPCWSTR pWVar16;
  WCHAR *pWVar17;
  WCHAR *pWVar18;
  LPCWSTR pWVar19;
  LPCWSTR pWVar20;
  undefined1 *puVar21;
  undefined1 *puVar22;
  LPCWSTR pWVar23;
  ulonglong uVar24;
  undefined1 auStack_a18 [48];
  undefined **local_9e8;
  void *local_9e0;
  void *local_9d8;
  int local_9d0;
  _RTL_CRITICAL_SECTION local_9c8;
  char local_9a0;
  LPCWSTR local_998;
  CHAR local_988;
  char acStack_987 [271];
  WCHAR local_878 [528];
  WCHAR local_458 [520];
  ulonglong local_48;
  
  puVar21 = auStack_a18;
  local_48 = DAT_180077818 ^ (ulonglong)&local_9e8;
  local_9e8 = ATL::CRegObject::vftable;
  pWVar19 = (LPCWSTR)0x0;
  local_9e0 = (void *)0x0;
  local_9d8 = (void *)0x0;
  local_9d0 = 0;
  local_9c8.DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
  local_9c8.LockCount = 0;
  local_9c8.RecursionCount = 0;
  local_9c8.OwningThread = (HANDLE)0x0;
  local_9c8.LockSemaphore = (HANDLE)0x0;
  local_9c8.SpinCount = 0;
  local_9a0 = '\0';
  BVar5 = InitializeCriticalSectionEx(&local_9c8,0,0);
  if (BVar5 == 0) {
    DVar6 = GetLastError();
    if (0 < (int)DVar6) {
      DVar6 = DVar6 & 0xffff | 0x80070000;
    }
    if ((int)DVar6 < 0) {
      local_9e8 = ATL::CRegObject::vftable;
      EnterCriticalSection(&local_9c8);
      pWVar20 = pWVar19;
      pWVar23 = pWVar19;
      if (0 < local_9d0) {
        do {
          if ((((longlong)pWVar20 < 0) || (iVar7 = (int)pWVar23, local_9d0 <= iVar7)) ||
             (operator_delete__(*(void **)((longlong)pWVar20 + (longlong)local_9e0)),
             local_9d0 <= iVar7)) {
                    /* WARNING: Subroutine does not return */
            FUN_180001a90(-0x7ffffff5);
          }
          operator_delete__(*(void **)((longlong)pWVar20 + (longlong)local_9d8));
          pWVar20 = pWVar20 + 4;
          pWVar23 = (LPCWSTR)(ulonglong)(iVar7 + 1U);
        } while ((int)(iVar7 + 1U) < local_9d0);
      }
      if (local_9e0 != (void *)0x0) {
        free(local_9e0);
        local_9e0 = (void *)0x0;
      }
      if (local_9d8 != (void *)0x0) {
        free(local_9d8);
        local_9d8 = (void *)0x0;
      }
      local_9d0 = 0;
      LeaveCriticalSection(&local_9c8);
      if (local_9a0 != '\0') {
        local_9a0 = '\0';
        DeleteCriticalSection(&local_9c8);
      }
      pWVar20 = pWVar19;
      if (0 < local_9d0) {
        do {
          if ((((longlong)pWVar20 < 0) || (iVar7 = (int)pWVar19, local_9d0 <= iVar7)) ||
             (operator_delete__(*(void **)((longlong)pWVar20 + (longlong)local_9e0)),
             local_9d0 <= iVar7)) {
                    /* WARNING: Subroutine does not return */
            FUN_180001a90(-0x7ffffff5);
          }
          operator_delete__(*(void **)((longlong)pWVar20 + (longlong)local_9d8));
          pWVar19 = (LPCWSTR)(ulonglong)(iVar7 + 1U);
          pWVar20 = pWVar20 + 4;
        } while ((int)(iVar7 + 1U) < local_9d0);
      }
      if (local_9e0 != (void *)0x0) {
        free(local_9e0);
        local_9e0 = (void *)0x0;
      }
      if (local_9d8 != (void *)0x0) {
        free(local_9d8);
        local_9d8 = (void *)0x0;
      }
      local_9d0 = 0;
      if (local_9e0 != (void *)0x0) {
        free(local_9e0);
        local_9e0 = (void *)0x0;
      }
      puVar21 = auStack_a18;
      if (local_9d8 != (void *)0x0) {
        free(local_9d8);
        puVar21 = auStack_a18;
      }
      goto LAB_180036ce3;
    }
  }
  local_9a0 = '\x01';
  if (param_4 != (undefined8 *)0x0) {
    pWVar20 = (LPCWSTR)*param_4;
    while (pWVar20 != (LPCWSTR)0x0) {
      FUN_180031840((longlong)&local_9e8,pWVar20,(void *)param_4[1]);
      param_4 = param_4 + 2;
      pWVar20 = (LPCWSTR)*param_4;
    }
  }
  DVar6 = (**(code **)(*param_1 + 0x28))(param_1,&local_9e8);
  pHVar3 = DAT_18007a618;
  if ((int)DVar6 < 0) {
    local_9e8 = ATL::CRegObject::vftable;
    EnterCriticalSection(&local_9c8);
    pWVar20 = pWVar19;
    pWVar23 = pWVar19;
    if (0 < local_9d0) {
      do {
        if ((((longlong)pWVar20 < 0) || (iVar7 = (int)pWVar23, local_9d0 <= iVar7)) ||
           (operator_delete__(*(void **)((longlong)pWVar20 + (longlong)local_9e0)),
           local_9d0 <= iVar7)) {
                    /* WARNING: Subroutine does not return */
          FUN_180001a90(-0x7ffffff5);
        }
        operator_delete__(*(void **)((longlong)pWVar20 + (longlong)local_9d8));
        pWVar20 = pWVar20 + 4;
        pWVar23 = (LPCWSTR)(ulonglong)(iVar7 + 1U);
      } while ((int)(iVar7 + 1U) < local_9d0);
    }
    if (local_9e0 != (void *)0x0) {
      free(local_9e0);
      local_9e0 = (void *)0x0;
    }
    if (local_9d8 != (void *)0x0) {
      free(local_9d8);
      local_9d8 = (void *)0x0;
    }
    local_9d0 = 0;
    LeaveCriticalSection(&local_9c8);
    if (local_9a0 != '\0') {
      local_9a0 = '\0';
      DeleteCriticalSection(&local_9c8);
    }
    pWVar20 = pWVar19;
    if (0 < local_9d0) {
      do {
        if ((((longlong)pWVar20 < 0) || (iVar7 = (int)pWVar19, local_9d0 <= iVar7)) ||
           (operator_delete__(*(void **)((longlong)pWVar20 + (longlong)local_9e0)),
           local_9d0 <= iVar7)) {
                    /* WARNING: Subroutine does not return */
          FUN_180001a90(-0x7ffffff5);
        }
        operator_delete__(*(void **)((longlong)pWVar20 + (longlong)local_9d8));
        pWVar19 = (LPCWSTR)(ulonglong)(iVar7 + 1U);
        pWVar20 = pWVar20 + 4;
      } while ((int)(iVar7 + 1U) < local_9d0);
    }
    if (local_9e0 != (void *)0x0) {
      free(local_9e0);
      local_9e0 = (void *)0x0;
    }
    if (local_9d8 != (void *)0x0) {
      free(local_9d8);
      local_9d8 = (void *)0x0;
    }
    local_9d0 = 0;
    if (local_9e0 != (void *)0x0) {
      free(local_9e0);
      local_9e0 = (void *)0x0;
    }
    puVar21 = auStack_a18;
    if (local_9d8 != (void *)0x0) {
      free(local_9d8);
      puVar21 = auStack_a18;
    }
    goto LAB_180036ce3;
  }
  local_998 = (LPCWSTR)0x0;
  DVar6 = GetModuleFileNameA(DAT_18007a618,&local_988,0x104);
  if (DVar6 == 0) {
    DVar6 = FUN_1800333f0();
    FUN_180032790(&local_9e8);
    puVar21 = auStack_a18;
    goto LAB_180036ce3;
  }
  if (DVar6 == 0x104) {
    FUN_180032790(&local_9e8);
    DVar6 = 0x8007007a;
    puVar21 = auStack_a18;
    goto LAB_180036ce3;
  }
  lVar15 = -1;
  do {
    lVar9 = lVar15 + 1;
    pcVar1 = acStack_987 + lVar15;
    lVar15 = lVar9;
  } while (*pcVar1 != '\0');
  lVar15 = (longlong)((int)lVar9 + 1) * 2;
  pWVar20 = pWVar19;
  puVar22 = auStack_a18;
  pWVar23 = pWVar19;
  if (lVar15 + 0x80000000U < 0x100000000) {
    iVar7 = (int)lVar15;
    uVar24 = (ulonglong)iVar7;
    if ((iVar7 < 0x401) && (cVar4 = FUN_1800026d0(uVar24), cVar4 != '\0')) {
      uVar10 = uVar24 + 0xf;
      if (uVar10 <= uVar24) {
        uVar10 = 0xffffffffffffff0;
      }
      puVar21 = auStack_a18 + -(uVar10 & 0xfffffffffffffff0);
      pWVar12 = (LPCWSTR)((longlong)&local_9e8 + -(uVar10 & 0xfffffffffffffff0));
    }
    else {
      if (~uVar24 < 0x10) {
                    /* WARNING: Subroutine does not return */
        FUN_180001a90(-0x7ff8fdea);
      }
      pWVar11 = malloc(uVar24 + 0x10);
      pWVar12 = pWVar19;
      if (pWVar11 != (LPCWSTR)0x0) {
        pWVar11[0] = L'\0';
        pWVar11[1] = L'\0';
        pWVar11[2] = L'\0';
        pWVar11[3] = L'\0';
        local_998 = pWVar11;
        pWVar20 = pWVar11;
        puVar21 = auStack_a18;
        pWVar12 = pWVar11 + 8;
      }
    }
    puVar22 = puVar21;
    if (pWVar12 != (LPCWSTR)0x0) {
      *pWVar12 = L'\0';
      *(int *)(puVar21 + 0x28) = (int)(uVar24 >> 1);
      *(LPCWSTR *)(puVar21 + 0x20) = pWVar12;
      *(undefined8 *)(puVar21 + -8) = 0x180036fc9;
      iVar7 = MultiByteToWideChar(0,0,&local_988,-1,*(LPWSTR *)(puVar21 + 0x20),
                                  *(int *)(puVar21 + 0x28));
      pWVar23 = pWVar12;
      if (iVar7 == 0) {
        pWVar23 = pWVar19;
      }
    }
  }
  puVar21 = puVar22;
  if (pWVar23 == (LPCWSTR)0x0) {
    while (pWVar20 != (LPCWSTR)0x0) {
      pWVar19 = *(LPCWSTR *)pWVar20;
      *(undefined8 *)(puVar22 + -8) = 0x180036fec;
      free(pWVar20);
      pWVar20 = pWVar19;
    }
    *(undefined8 *)(puVar22 + -8) = 0x180036ffa;
    FUN_180032790(&local_9e8);
    DVar6 = 0x8007000e;
    goto LAB_180036ce3;
  }
  pWVar12 = pWVar19;
  pWVar17 = local_458;
  pWVar11 = pWVar23;
  do {
    uVar8 = (uint)pWVar12;
    WVar2 = *pWVar11;
    pWVar18 = pWVar17;
    if (WVar2 == L'\0') break;
    *pWVar17 = WVar2;
    pWVar18 = pWVar17 + 1;
    if ((WVar2 == L'\'') && (uVar8 = uVar8 + 1, uVar8 < 0x207)) {
      *pWVar18 = L'\'';
      pWVar18 = pWVar17 + 2;
    }
    pWVar11 = pWVar11 + 1;
    pWVar12 = (LPCWSTR)(ulonglong)(uVar8 + 1);
    pWVar17 = pWVar18;
  } while (uVar8 + 1 < 0x207);
  *pWVar18 = L'\0';
  if (pHVar3 == (HMODULE)0x0) {
LAB_180037066:
    local_878[0] = L'\"';
    lVar15 = -1;
    do {
      lVar15 = lVar15 + 1;
    } while (local_458[lVar15] != L'\0');
    uVar24 = (longlong)((int)lVar15 + 1) * 2;
    if (uVar24 != 0) {
      if (0x416 < uVar24) {
        *(undefined8 *)(puVar22 + -8) = 0x18003714e;
        memset(local_878 + 1,0,0x416);
        *(undefined8 *)(puVar22 + -8) = 0x180037154;
        piVar14 = _errno();
        *piVar14 = 0x22;
        *(undefined8 *)(puVar22 + -8) = 0x18003715c;
        _invalid_parameter_noinfo();
        while (pWVar20 != (LPCWSTR)0x0) {
          pWVar19 = *(LPCWSTR *)pWVar20;
          *(undefined8 *)(puVar22 + -8) = 0x18003716e;
          free(pWVar20);
          pWVar20 = pWVar19;
        }
        *(undefined8 *)(puVar22 + -8) = 0x18003717c;
        FUN_180032790(&local_9e8);
        DVar6 = 0x80004005;
        goto LAB_180036ce3;
      }
      *(undefined8 *)(puVar22 + -8) = 0x1800370b4;
      memcpy(local_878 + 1,local_458,uVar24);
    }
    lVar15 = -1;
    do {
      lVar15 = lVar15 + 1;
    } while (local_878[lVar15] != L'\0');
    lVar15 = (longlong)(int)lVar15;
    local_878[lVar15] = L'\"';
    if (0x417 < lVar15 * 2 + 2U) {
                    /* WARNING: Subroutine does not return */
      *(undefined8 *)(puVar22 + -8) = 0x180037344;
      FUN_18005c254();
    }
    local_878[lVar15 + 1] = 0;
    pWVar17 = local_878;
  }
  else {
    *(undefined8 *)(puVar22 + -8) = 0x180037055;
    pHVar13 = GetModuleHandleA((LPCSTR)0x0);
    if (pHVar3 == pHVar13) goto LAB_180037066;
    pWVar17 = local_458;
  }
  *(undefined8 *)(puVar22 + -8) = 0x18003710a;
  DVar6 = FUN_180031840((longlong)&local_9e8,L"Module",pWVar17);
  if ((int)DVar6 < 0) {
    while (pWVar20 != (LPCWSTR)0x0) {
      pWVar19 = *(LPCWSTR *)pWVar20;
      *(undefined8 *)(puVar22 + -8) = 0x18003712c;
      free(pWVar20);
      pWVar20 = pWVar19;
    }
    *(undefined8 *)(puVar22 + -8) = 0x18003713a;
    FUN_180032790(&local_9e8);
    goto LAB_180036ce3;
  }
  *(undefined8 *)(puVar22 + -8) = 0x18003719d;
  DVar6 = FUN_180031840((longlong)&local_9e8,L"Module_Raw",local_458);
  if ((int)DVar6 < 0) {
    while (pWVar20 != (LPCWSTR)0x0) {
      pWVar19 = *(LPCWSTR *)pWVar20;
      *(undefined8 *)(puVar22 + -8) = 0x1800371bc;
      free(pWVar20);
      pWVar20 = pWVar19;
    }
    *(undefined8 *)(puVar22 + -8) = 0x1800371ca;
    FUN_180032790(&local_9e8);
    goto LAB_180036ce3;
  }
  if (param_2 != (LPCSTR)0x0) {
    lVar15 = -1;
    do {
      lVar15 = lVar15 + 1;
    } while (param_2[lVar15] != '\0');
    lVar15 = (longlong)((int)lVar15 + 1) * 2;
    pWVar12 = pWVar19;
    if (lVar15 + 0x80000000U < 0x100000000) {
      iVar7 = (int)lVar15;
      uVar24 = (ulonglong)iVar7;
      if (iVar7 < 0x401) {
        *(undefined8 *)(puVar22 + -8) = 0x18003721c;
        cVar4 = FUN_1800026d0(uVar24);
        if (cVar4 == '\0') goto LAB_180037246;
        uVar10 = uVar24 + 0xf;
        if (uVar10 <= uVar24) {
          uVar10 = 0xffffffffffffff0;
        }
        *(undefined8 *)(puVar22 + -8) = 0x18003723c;
        pWVar11 = (LPCWSTR)(puVar22 + -(uVar10 & 0xfffffffffffffff0) + 0x30);
        puVar22 = puVar22 + -(uVar10 & 0xfffffffffffffff0);
      }
      else {
LAB_180037246:
        if (~uVar24 < 0x10) {
                    /* WARNING: Subroutine does not return */
          *(undefined **)(puVar22 + -8) = &UNK_18003733e;
          FUN_180001a90(-0x7ff8fdea);
        }
        *(undefined8 *)(puVar22 + -8) = 0x180037260;
        pWVar16 = malloc(uVar24 + 0x10);
        pWVar11 = pWVar19;
        if (pWVar16 != (LPCWSTR)0x0) {
          *(LPCWSTR *)pWVar16 = pWVar20;
          local_998 = pWVar16;
          pWVar20 = pWVar16;
          pWVar11 = pWVar16 + 8;
        }
      }
      if (pWVar11 != (LPCWSTR)0x0) {
        *pWVar11 = L'\0';
        *(int *)(puVar22 + 0x28) = (int)(uVar24 >> 1);
        *(LPCWSTR *)(puVar22 + 0x20) = pWVar11;
        *(undefined8 *)(puVar22 + -8) = 0x1800372a0;
        iVar7 = MultiByteToWideChar(0,0,param_2,-1,*(LPWSTR *)(puVar22 + 0x20),
                                    *(int *)(puVar22 + 0x28));
        pWVar12 = pWVar11;
        if (iVar7 == 0) {
          pWVar12 = pWVar19;
        }
      }
    }
    if (pWVar12 != (LPCWSTR)0x0) {
      if (param_3 == 0) {
        *(undefined8 *)(puVar22 + -8) = 0x1800372d2;
        DVar6 = FUN_180035dd0(&local_9e8,pWVar23,pWVar12,L"REGISTRY");
      }
      else {
        *(undefined8 *)(puVar22 + -8) = 0x1800372cb;
        DVar6 = FUN_180035b10(&local_9e8,pWVar23,pWVar12,L"REGISTRY");
      }
      while (pWVar20 != (LPCWSTR)0x0) {
        pWVar19 = *(LPCWSTR *)pWVar20;
        *(undefined8 *)(puVar22 + -8) = 0x1800372ec;
        free(pWVar20);
        pWVar20 = pWVar19;
      }
      *(undefined8 *)(puVar22 + -8) = 0x1800372fa;
      FUN_180032790(&local_9e8);
      puVar21 = puVar22;
      goto LAB_180036ce3;
    }
  }
  while (pWVar20 != (LPCWSTR)0x0) {
    pWVar19 = *(LPCWSTR *)pWVar20;
    *(undefined8 *)((longlong)puVar22 + -8) = 0x18003731c;
    free(pWVar20);
    pWVar20 = pWVar19;
  }
  *(undefined8 *)((longlong)puVar22 + -8) = 0x18003732a;
  FUN_180032790(&local_9e8);
  DVar6 = 0x8007000e;
  puVar21 = puVar22;
LAB_180036ce3:
  *(undefined8 *)(puVar21 + -8) = 0x180036cf2;
  return DVar6;
}

/* ---- FUNC 00037380 FUN_180037380 (28 bytes) ---- */

undefined8 FUN_180037380(void)

{
  undefined8 uVar1;
  
  if (DAT_180079800 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00018003738f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*DAT_180079800 + 0xd0))();
    return uVar1;
  }
  return 0x80004005;
}

/* ---- FUNC 000373A0 FUN_1800373a0 (28 bytes) ---- */

undefined8 FUN_1800373a0(void)

{
  undefined8 uVar1;
  
  if (DAT_180079800 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001800373af. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*DAT_180079800 + 0x140))();
    return uVar1;
  }
  return 0x80004005;
}

/* ---- FUNC 000373C0 FUN_1800373c0 (31 bytes) ---- */

undefined8 FUN_1800373c0(undefined8 param_1)

{
  undefined8 uVar1;
  
  if (DAT_180079800 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001800373d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*DAT_180079800 + 0x150))(DAT_180079800,param_1);
    return uVar1;
  }
  return 0x80004005;
}

/* ---- FUNC 000373E0 FUN_1800373e0 (37 bytes) ---- */

undefined8 FUN_1800373e0(undefined8 param_1,undefined4 param_2)

{
  undefined8 uVar1;
  
  if (DAT_180079800 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001800373f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*DAT_180079800 + 0x110))(DAT_180079800,param_1,param_2);
    return uVar1;
  }
  return 0x80004005;
}

/* ---- FUNC 00037410 FUN_180037410 (37 bytes) ---- */

undefined8 FUN_180037410(undefined4 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if (DAT_180079800 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000180037428. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*DAT_180079800 + 0x108))(DAT_180079800,param_1,param_2);
    return uVar1;
  }
  return 0x80004005;
}

/* ---- FUNC 00037440 FUN_180037440 (58 bytes) ---- */

uint FUN_180037440(void)

{
  uint uVar1;
  
  uVar1 = 0x80004005;
  if (DAT_180079800 != (longlong *)0x0) {
    uVar1 = (**(code **)(*DAT_180079800 + 0x30))(DAT_180079800,DAT_1800797fc == 0);
  }
  DAT_1800797fc = 0;
  return ~uVar1 >> 0x1f;
}

/* ---- FUNC 00037480 FUN_180037480 (64 bytes) ---- */

uint FUN_180037480(undefined8 param_1)

{
  uint uVar1;
  
  uVar1 = 0x80004005;
  if (DAT_180079800 != (longlong *)0x0) {
    uVar1 = (**(code **)(*DAT_180079800 + 0x38))(DAT_180079800,param_1,DAT_1800797fc == 0);
  }
  DAT_1800797fc = 0;
  return ~uVar1 >> 0x1f;
}

/* ---- FUNC 000374C0 FUN_1800374c0 (40 bytes) ---- */

void FUN_1800374c0(undefined4 param_1,longlong *param_2)

{
  longlong lVar1;
  
  if (DAT_180079800 != (longlong *)0x0) {
    lVar1 = 0;
    if (*(int *)(*param_2 + -0x10) != 0) {
      lVar1 = *param_2;
    }
                    /* WARNING: Could not recover jumptable at 0x0001800374e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_180079800 + 0x68))(DAT_180079800,param_1,lVar1);
    return;
  }
  return;
}

/* ---- FUNC 000374F0 FUN_1800374f0 (70 bytes) ---- */

uint FUN_1800374f0(undefined8 param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = 0x80004005;
  if (DAT_180079800 != (longlong *)0x0) {
    uVar1 = (**(code **)(*DAT_180079800 + 0x40))(DAT_180079800,param_1,DAT_1800797fc == 0,param_2);
  }
  DAT_1800797fc = 0;
  return ~uVar1 >> 0x1f;
}

/* ---- FUNC 00037540 FUN_180037540 (40 bytes) ---- */

uint FUN_180037540(undefined8 param_1)

{
  uint uVar1;
  
  uVar1 = 0x80004005;
  if (DAT_180079800 != (longlong *)0x0) {
    uVar1 = (**(code **)(*DAT_180079800 + 0x48))(DAT_180079800,param_1);
  }
  return ~uVar1 >> 0x1f;
}

/* ---- FUNC 00037570 FUN_180037570 (27 bytes) ---- */

undefined8 FUN_180037570(void)

{
  undefined8 uVar1;
  
  if (DAT_180079800 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000180037581. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*DAT_180079800 + 0x20))(DAT_180079800,0);
    return uVar1;
  }
  return 0x80004005;
}

/* ---- FUNC 00037590 FUN_180037590 (31 bytes) ---- */

undefined8 FUN_180037590(undefined8 param_1)

{
  undefined8 uVar1;
  
  if (DAT_180079800 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001800375a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*DAT_180079800 + 0x118))(DAT_180079800,param_1);
    return uVar1;
  }
  return 0x80004005;
}

/* ---- FUNC 000375B0 FUN_1800375b0 (47 bytes) ---- */

undefined4 FUN_1800375b0(void)

{
  int iVar1;
  undefined4 local_res8 [8];
  
  if (DAT_180079800 != (longlong *)0x0) {
    iVar1 = (**(code **)(*DAT_180079800 + 0x18))(DAT_180079800,local_res8);
    if (-1 < iVar1) {
      return local_res8[0];
    }
  }
  return 0;
}

/* ---- FUNC 000375E0 FUN_1800375e0 (30 bytes) ---- */

undefined8 FUN_1800375e0(void)

{
  undefined8 uVar1;
  
  if (DAT_180079800 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001800375f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*DAT_180079800 + 0x20))(DAT_180079800,1);
    return uVar1;
  }
  return 0x80004005;
}

/* ---- FUNC 00037600 FUN_180037600 (31 bytes) ---- */

undefined8 FUN_180037600(undefined8 param_1)

{
  undefined8 uVar1;
  
  if (DAT_180079800 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000180037612. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*DAT_180079800 + 0x120))(DAT_180079800,param_1);
    return uVar1;
  }
  return 0x80004005;
}

/* ---- FUNC 00037620 InitializeCriticalSectionEx (7 bytes) ---- */

BOOL __stdcall
InitializeCriticalSectionEx(LPCRITICAL_SECTION lpCriticalSection,DWORD dwSpinCount,DWORD Flags)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180037620. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = InitializeCriticalSectionEx(lpCriticalSection,dwSpinCount,Flags);
  return BVar1;
}

/* ---- FUNC 00037630 FUN_180037630 (13 bytes) ---- */

void FUN_180037630(undefined8 param_1,undefined8 param_2)

{
                    /* WARNING: Could not recover jumptable at 0x000180037636. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RaiseException(param_1,param_2,0,0);
  return;
}

/* ---- FUNC 00037640 DllCanUnloadNow (152 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HRESULT __stdcall DllCanUnloadNow(void)

{
  char *lpOutputString;
  bool bVar1;
  undefined1 auStack_428 [32];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
                    /* 0x37640  11  DllCanUnloadNow */
  local_18 = DAT_180077818 ^ (ulonglong)auStack_428;
  bVar1 = DAT_1800797f0 != 0;
  if (DAT_1800797f0 == 0) {
    if (DAT_18007981c != 0) {
      FUN_180002a20(local_408,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hmainmfc.cpp",0x57);
      LogMessage(local_408,2,1);
    }
    lpOutputString = "Happ.dll DllCanUnloadNow returning OK to unload\n";
  }
  else {
    lpOutputString = "Happ.dll DllCanUnloadNow not OK to unload\n";
  }
  OutputDebugStringA(lpOutputString);
  return (HRESULT)bVar1;
}

/* ---- FUNC 000376E0 FUN_1800376e0 (153 bytes) ---- */

undefined8 FUN_1800376e0(undefined8 param_1,int param_2)

{
  undefined **ppuVar1;
  undefined *puVar2;
  longlong *plVar3;
  undefined **ppuVar4;
  longlong *plVar5;
  
  if (param_2 == 1) {
    ppuVar4 = &PTR_DAT_180077730;
    DAT_180079858 = &PTR_DAT_180077730;
    DAT_1800797d8 = param_1;
    plVar3 = (longlong *)PTR_DAT_1800777d8;
    plVar5 = (longlong *)PTR_DAT_1800777d0;
    puVar2 = PTR_DAT_180077730;
    while (PTR_DAT_1800777d0 = (undefined *)plVar5, PTR_DAT_1800777d8 = (undefined *)plVar3,
          puVar2 != (undefined *)0x0) {
      (*(code *)ppuVar4[8])(1);
      ppuVar1 = ppuVar4 + 9;
      ppuVar4 = ppuVar4 + 9;
      plVar3 = (longlong *)PTR_DAT_1800777d8;
      plVar5 = (longlong *)PTR_DAT_1800777d0;
      puVar2 = *ppuVar1;
    }
    if (plVar5 < plVar3) {
      do {
        if (*plVar5 != 0) {
          (**(code **)(*plVar5 + 0x38))(1);
          plVar3 = (longlong *)PTR_DAT_1800777d8;
        }
        plVar5 = plVar5 + 1;
      } while (plVar5 < plVar3);
      return 1;
    }
  }
  else if (param_2 == 0) {
    if (DAT_180079858 != (undefined **)0x0) {
      puVar2 = *DAT_180079858;
      ppuVar4 = DAT_180079858;
      while (puVar2 != (undefined *)0x0) {
        if ((longlong *)ppuVar4[4] != (longlong *)0x0) {
          (**(code **)(*(longlong *)ppuVar4[4] + 0x10))();
        }
        ppuVar4[4] = (undefined *)0x0;
        (*(code *)ppuVar4[8])(0);
        ppuVar4 = ppuVar4 + 9;
        puVar2 = *ppuVar4;
      }
    }
    plVar3 = (longlong *)PTR_DAT_1800777d8;
    plVar5 = (longlong *)PTR_DAT_1800777d0;
    if (PTR_DAT_1800777d0 < PTR_DAT_1800777d8) {
      do {
        if (*plVar5 != 0) {
          (**(code **)(*plVar5 + 0x38))(0);
          plVar3 = (longlong *)PTR_DAT_1800777d8;
        }
        plVar5 = plVar5 + 1;
      } while (plVar5 < plVar3);
    }
    FUN_180036140(0x180079810);
  }
  return 1;
}

/* ---- FUNC 00037779 FUN_180037779 (45 bytes) ---- */

undefined8 FUN_180037779(void)

{
  longlong *plVar1;
  longlong *unaff_RBX;
  longlong *plVar2;
  
  do {
    if ((longlong *)unaff_RBX[4] != (longlong *)0x0) {
      (**(code **)(*(longlong *)unaff_RBX[4] + 0x10))();
    }
    unaff_RBX[4] = 0;
    (*(code *)unaff_RBX[8])(0);
    unaff_RBX = unaff_RBX + 9;
  } while (*unaff_RBX != 0);
  plVar1 = (longlong *)PTR_DAT_1800777d8;
  plVar2 = (longlong *)PTR_DAT_1800777d0;
  if (PTR_DAT_1800777d0 < PTR_DAT_1800777d8) {
    do {
      if (*plVar2 != 0) {
        (**(code **)(*plVar2 + 0x38))(0);
        plVar1 = (longlong *)PTR_DAT_1800777d8;
      }
      plVar2 = plVar2 + 1;
    } while (plVar2 < plVar1);
  }
  FUN_180036140(0x180079810);
  return 1;
}

/* ---- FUNC 000377A6 FUN_1800377a6 (78 bytes) ---- */

undefined8 FUN_1800377a6(void)

{
  longlong *plVar1;
  longlong *plVar2;
  
  plVar1 = (longlong *)PTR_DAT_1800777d8;
  plVar2 = (longlong *)PTR_DAT_1800777d0;
  if (PTR_DAT_1800777d0 < PTR_DAT_1800777d8) {
    do {
      if (*plVar2 != 0) {
        (**(code **)(*plVar2 + 0x38))(0);
        plVar1 = (longlong *)PTR_DAT_1800777d8;
      }
      plVar2 = plVar2 + 1;
    } while (plVar2 < plVar1);
  }
  FUN_180036140(0x180079810);
  return 1;
}

/* ---- FUNC 00037800 FUN_180037800 (234 bytes) ---- */

void FUN_180037800(undefined8 *param_1,void *param_2,size_t param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  void *_Dst;
  
  if (param_3 < 0x8000000000000000) {
    param_1[3] = 0xf;
    if (param_3 < 0x10) {
      param_1[2] = param_3;
      memcpy(param_1,param_2,param_3);
      *(undefined1 *)(param_3 + (longlong)param_1) = 0;
    }
    else {
      uVar2 = param_3 | 0xf;
      if (uVar2 < 0x8000000000000000) {
        if (uVar2 < 0x16) {
          uVar2 = 0x16;
        }
        uVar1 = uVar2 + 1;
        if (uVar1 < 0x1000) {
          if (uVar1 == 0) {
            _Dst = (void *)0x0;
          }
          else {
            _Dst = operator_new(uVar1);
          }
        }
        else {
          _Dst = (void *)FUN_180001160(uVar1);
        }
      }
      else {
        _Dst = (void *)FUN_180001160(0x8000000000000000);
        uVar2 = 0x7fffffffffffffff;
      }
      *param_1 = _Dst;
      param_1[2] = param_3;
      param_1[3] = uVar2;
      memcpy(_Dst,param_2,param_3);
      *(undefined1 *)((longlong)_Dst + param_3) = 0;
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_180002780();
}

/* ---- FUNC 00037853 FUN_180037853 (125 bytes) ---- */

void FUN_180037853(void)

{
  ulonglong uVar1;
  ulonglong in_RAX;
  ulonglong uVar2;
  void *_Dst;
  size_t unaff_RBX;
  void *unaff_RBP;
  undefined8 *unaff_RSI;
  ulonglong unaff_RDI;
  
  uVar2 = in_RAX | 0xf;
  if (unaff_RDI < uVar2) {
    _Dst = (void *)FUN_180001160(0x8000000000000000);
    uVar2 = unaff_RDI;
  }
  else {
    if (uVar2 < 0x16) {
      uVar2 = 0x16;
    }
    uVar1 = uVar2 + 1;
    if (uVar1 < 0x1000) {
      if (uVar1 == 0) {
        _Dst = (void *)0x0;
      }
      else {
        _Dst = operator_new(uVar1);
      }
    }
    else {
      _Dst = (void *)FUN_180001160(uVar1);
    }
  }
  *unaff_RSI = _Dst;
  unaff_RSI[2] = unaff_RBX;
  unaff_RSI[3] = uVar2;
  memcpy(_Dst,unaff_RBP,unaff_RBX);
  *(undefined1 *)((longlong)_Dst + unaff_RBX) = 0;
  return;
}

/* ---- FUNC 000378D0 FUN_1800378d0 (21 bytes) ---- */

void FUN_1800378d0(void)

{
  return;
}

/* ---- FUNC 000378F0 FUN_1800378f0 (174 bytes) ---- */

longlong *
FUN_1800378f0(undefined8 *param_1,undefined8 *param_2,longlong param_3,undefined8 param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  
  plVar3 = (longlong *)*param_1;
  if (*(char *)((longlong)param_2 + 0x19) == '\0') {
    plVar1 = operator_new(0x28);
    plVar1[4] = param_2[4];
    *plVar1 = (longlong)plVar3;
    plVar1[2] = (longlong)plVar3;
    *(undefined2 *)(plVar1 + 3) = 0;
    plVar1[1] = param_3;
    *(undefined1 *)(plVar1 + 3) = *(undefined1 *)(param_2 + 3);
    if (*(char *)((longlong)plVar3 + 0x19) != '\0') {
      plVar3 = plVar1;
    }
    plVar2 = FUN_1800378f0(param_1,(undefined8 *)*param_2,(longlong)plVar1,param_4);
    *plVar1 = (longlong)plVar2;
    plVar2 = FUN_1800378f0(param_1,(undefined8 *)param_2[2],(longlong)plVar1,param_4);
    plVar1[2] = (longlong)plVar2;
  }
  return plVar3;
}

/* ---- FUNC 000379A0 FUN_1800379a0 (113 bytes) ---- */

void FUN_1800379a0(longlong *param_1,undefined8 param_2)

{
  char cVar1;
  longlong *plVar2;
  longlong *plVar3;
  
  cVar1 = *(char *)((longlong)*(longlong **)(*param_1 + 8) + 0x19);
  plVar3 = *(longlong **)(*param_1 + 8);
  while (cVar1 == '\0') {
    FUN_180037a20(param_1,param_2,(longlong *)plVar3[2]);
    plVar2 = (longlong *)*plVar3;
    FUN_180025ad0(plVar3);
    plVar3 = plVar2;
    cVar1 = *(char *)((longlong)plVar2 + 0x19);
  }
  FUN_180025ad0((void *)*param_1);
  return;
}

/* ---- FUNC 00037A20 FUN_180037a20 (85 bytes) ---- */

void FUN_180037a20(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  char cVar1;
  longlong *plVar2;
  
  cVar1 = *(char *)((longlong)param_3 + 0x19);
  while (cVar1 == '\0') {
    FUN_180037a20(param_1,param_2,(longlong *)param_3[2]);
    plVar2 = (longlong *)*param_3;
    FUN_180025ad0(param_3);
    param_3 = plVar2;
    cVar1 = *(char *)((longlong)plVar2 + 0x19);
  }
  return;
}

/* ---- FUNC 00037A80 FUN_180037a80 (46 bytes) ---- */

undefined8 *
FUN_180037a80(undefined8 *param_1,ulonglong param_2,undefined8 param_3,size_t param_4,
             longlong param_5,void *param_6,size_t param_7)

{
  size_t _Size;
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  void *_Src;
  void *_Dst;
  ulonglong uVar4;
  ulonglong uVar5;
  void *pvVar6;
  
  lVar2 = param_1[2];
  uVar5 = 0x7fffffffffffffff;
  if (0x7fffffffffffffffU - lVar2 < param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_180002780();
  }
  uVar3 = param_1[3];
  uVar4 = lVar2 + param_2 | 0xf;
  if (uVar4 < 0x8000000000000000) {
    if (0x7fffffffffffffff - (uVar3 >> 1) < uVar3) {
      _Dst = (void *)FUN_180001160(0x8000000000000000);
    }
    else {
      uVar1 = (uVar3 >> 1) + uVar3;
      uVar5 = uVar4;
      if (uVar4 < uVar1) {
        uVar5 = uVar1;
      }
      uVar4 = uVar5 + 1;
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
  param_1[3] = uVar5;
  param_1[2] = lVar2 + param_2;
  pvVar6 = (void *)((longlong)_Dst + param_4);
  _Size = ((lVar2 - param_4) - param_5) + 1;
  if (uVar3 < 0x10) {
    memcpy(_Dst,param_1,param_4);
    memcpy(pvVar6,param_6,param_7);
    memcpy((void *)((longlong)pvVar6 + param_7),(void *)(param_4 + param_5 + (longlong)param_1),
           _Size);
  }
  else {
    _Src = (void *)*param_1;
    memcpy(_Dst,_Src,param_4);
    memcpy(pvVar6,param_6,param_7);
    memcpy((void *)((longlong)pvVar6 + param_7),(void *)((longlong)_Src + param_5 + param_4),_Size);
    pvVar6 = _Src;
    if ((0xfff < uVar3 + 1) &&
       (pvVar6 = *(void **)((longlong)_Src + -8),
       0x1f < (ulonglong)((longlong)_Src + (-8 - (longlong)pvVar6)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180025ad0(pvVar6);
  }
  *param_1 = _Dst;
  return param_1;
}

/* ---- FUNC 00037AAE FUN_180037aae (385 bytes) ---- */

void FUN_180037aae(longlong param_1,longlong param_2)

{
  size_t _Size;
  ulonglong uVar1;
  ulonglong uVar2;
  void *_Src;
  void *_Dst;
  ulonglong uVar3;
  ulonglong unaff_RBX;
  void *pvVar4;
  undefined8 *unaff_RDI;
  longlong unaff_R14;
  size_t unaff_R15;
  longlong in_stack_00000070;
  void *in_stack_00000078;
  size_t in_stack_00000080;
  
  uVar2 = *(ulonglong *)(param_1 + 0x18);
  uVar3 = unaff_R14 + param_2 | 0xf;
  if (unaff_RBX < uVar3) {
    _Dst = (void *)FUN_180001160(0x8000000000000000);
  }
  else if (unaff_RBX - (uVar2 >> 1) < uVar2) {
    _Dst = (void *)FUN_180001160(0x8000000000000000);
  }
  else {
    uVar1 = (uVar2 >> 1) + uVar2;
    unaff_RBX = uVar3;
    if (uVar3 < uVar1) {
      unaff_RBX = uVar1;
    }
    uVar3 = unaff_RBX + 1;
    if (uVar3 < 0x1000) {
      if (uVar3 == 0) {
        _Dst = (void *)0x0;
      }
      else {
        _Dst = operator_new(uVar3);
      }
    }
    else {
      _Dst = (void *)FUN_180001160(uVar3);
    }
  }
  unaff_RDI[3] = unaff_RBX;
  unaff_RDI[2] = unaff_R14 + param_2;
  pvVar4 = (void *)((longlong)_Dst + unaff_R15);
  _Size = ((unaff_R14 - unaff_R15) - in_stack_00000070) + 1;
  if (uVar2 < 0x10) {
    memcpy(_Dst,unaff_RDI,unaff_R15);
    memcpy(pvVar4,in_stack_00000078,in_stack_00000080);
    memcpy((void *)((longlong)pvVar4 + in_stack_00000080),
           (void *)(unaff_R15 + in_stack_00000070 + (longlong)unaff_RDI),_Size);
  }
  else {
    _Src = (void *)*unaff_RDI;
    memcpy(_Dst,_Src,unaff_R15);
    memcpy(pvVar4,in_stack_00000078,in_stack_00000080);
    memcpy((void *)((longlong)pvVar4 + in_stack_00000080),
           (void *)((longlong)_Src + in_stack_00000070 + unaff_R15),_Size);
    pvVar4 = _Src;
    if ((0xfff < uVar2 + 1) &&
       (pvVar4 = *(void **)((longlong)_Src + -8),
       0x1f < (ulonglong)((longlong)_Src + (-8 - (longlong)pvVar4)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180025ad0(pvVar4);
  }
  *unaff_RDI = _Dst;
  return;
}

/* ---- FUNC 00037C2F thunk_FUN_180002780 (5 bytes) ---- */

void thunk_FUN_180002780(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_180002780();
}

/* ---- FUNC 00037C40 FUN_180037c40 (500 bytes) ---- */

undefined8 * FUN_180037c40(undefined8 *param_1)

{
  void *pvVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  
  *param_1 = CHNode::vftable;
  FUN_180058e20(param_1 + 3,param_1,param_1,0);
  plVar3 = (longlong *)0x0;
  param_1[0xb] = 0;
  FUN_1800212f0(param_1 + 0x10,param_1,&DAT_180063400);
  FUN_180058ec0(param_1 + 0x1e,param_1,param_1,0);
  FUN_1800589e0(param_1 + 0x23,param_1,param_1,0);
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = 0xf;
  *(undefined1 *)(param_1 + 0x2d) = 0;
  FUN_180059ca0(param_1 + 0x32,param_1,param_1,0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x3b));
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  pvVar1 = operator_new(0x28);
  *(void **)pvVar1 = pvVar1;
  *(void **)((longlong)pvVar1 + 8) = pvVar1;
  *(void **)((longlong)pvVar1 + 0x10) = pvVar1;
  *(undefined2 *)((longlong)pvVar1 + 0x18) = 0x101;
  param_1[0x3c] = pvVar1;
  FUN_180037e40(param_1 + 0x3e,param_1);
  param_1[1] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xc] = 0;
  *(undefined4 *)(param_1 + 0xd) = 0;
  param_1[0xe] = 0;
  param_1[2] = 0;
  param_1[0x1d] = 0;
  param_1[0x29] = 0;
  param_1[0x38] = 0;
  param_1[0x2a] = 0;
  param_1[0x37] = 0;
  *(undefined4 *)(param_1 + 0x2b) = 4000;
  *(undefined4 *)((longlong)param_1 + 0x15c) = 400;
  *(undefined4 *)(param_1 + 0x3a) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x3b),"");
  param_1[0xf] = 0;
  *(undefined4 *)(param_1 + 0x31) = 0;
  puVar2 = operator_new(0x28);
  if (puVar2 != (undefined8 *)0x0) {
    plVar3 = FUN_180058810(puVar2,param_1,param_1,0);
  }
  param_1[0x39] = plVar3;
  if (plVar3 != (longlong *)0x0) {
    (**(code **)(*plVar3 + 8))();
  }
  *(undefined4 *)((longlong)param_1 + 0x164) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  return param_1;
}

/* ---- FUNC 00037E40 FUN_180037e40 (69 bytes) ---- */

undefined8 * FUN_180037e40(undefined8 *param_1,undefined8 param_2)

{
  HRESULT HVar1;
  
  param_1[1] = param_2;
  *param_1 = CHNode::CImpIHappServiceProvider::vftable;
  HVar1 = FUN_180033ad0(param_1 + 2,(GUID *)&DAT_1800635c0);
  if (HVar1 < 0) {
    param_1[2] = 0;
  }
  return param_1;
}

/* ---- FUNC 00037EE0 FUN_180037ee0 (658 bytes) ---- */

void FUN_180037ee0(undefined8 *param_1)

{
  void *pvVar1;
  int iVar2;
  undefined8 *puVar3;
  void *pvVar4;
  longlong *local_res8;
  
  *param_1 = CHNode::vftable;
  puVar3 = (undefined8 *)param_1[0xf];
  if (puVar3 != (undefined8 *)0x0) {
    FUN_1800473f0(puVar3);
    FUN_180025ad0(puVar3);
  }
  if ((DAT_180079880 != (longlong *)0x0) && (DAT_180079888 != 0)) {
    (**(code **)(*DAT_180079880 + 0x10))();
    DAT_180079888 = DAT_180079888 + -1;
    if (DAT_180079888 == 0) {
      DAT_180079880 = (longlong *)0x0;
    }
  }
  if ((longlong *)param_1[0x1d] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x1d] + 0x10))();
  }
  if ((longlong *)param_1[0xe] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0xe] + 0x10))();
  }
  puVar3 = (undefined8 *)param_1[0xc];
  if (puVar3 != (undefined8 *)0x0) {
    iVar2 = (**(code **)*puVar3)(puVar3,&DAT_180066db8);
    if (-1 < iVar2) {
      (**(code **)(*local_res8 + 0xa0))(local_res8,*(undefined4 *)(param_1 + 0x3a));
      (**(code **)(*local_res8 + 0x10))();
      *(undefined4 *)(param_1 + 0x3a) = 0;
    }
    (**(code **)(*(longlong *)param_1[0xc] + 0x10))();
  }
  if ((param_1[9] != 0) && (*(longlong *)(param_1[10] + 0x20) != 0)) {
    WaitForSingleObject(DAT_1800797e8,100);
    puVar3 = (undefined8 *)HASetBptr(0,param_1[9]);
    if ((puVar3 != (undefined8 *)0x0) && ((code *)*puVar3 != (code *)0x0)) {
      (*(code *)*puVar3)(puVar3);
    }
    param_1[9] = 0;
    ReleaseSemaphore(DAT_1800797e8,1,(LPLONG)0x0);
  }
  if ((void *)param_1[0x2a] != (void *)0x0) {
    FUN_180025ad0((void *)param_1[0x2a]);
  }
  if ((longlong *)param_1[0x37] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x37] + 0x10))();
  }
  if ((longlong *)param_1[10] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[10] + 0x10))();
  }
  if ((longlong *)param_1[0x29] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x29] + 0x10))();
  }
  if ((longlong *)param_1[0x38] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x38] + 0x10))();
  }
  if (param_1[0x39] != 0) {
    FUN_180058850(param_1[0x39]);
    (**(code **)(*(longlong *)param_1[0x39] + 0x10))();
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
  FUN_180038180(param_1 + 0x3e);
  FUN_1800379a0(param_1 + 0x3c,param_1 + 0x3c);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x3b));
  FUN_180059cd0(param_1 + 0x32);
  if (0xf < (ulonglong)param_1[0x30]) {
    pvVar1 = (void *)param_1[0x2d];
    pvVar4 = pvVar1;
    if ((0xfff < param_1[0x30] + 1) &&
       (pvVar4 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar4)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180025ad0(pvVar4);
  }
  param_1[0x2f] = 0;
  param_1[0x30] = 0xf;
  *(undefined1 *)(param_1 + 0x2d) = 0;
  FUN_180058a30(param_1 + 0x23);
  FUN_180058ef0(param_1 + 0x1e);
  FUN_180058e50(param_1 + 3);
  return;
}

/* ---- FUNC 00038180 FUN_180038180 (35 bytes) ---- */

void FUN_180038180(undefined8 *param_1)

{
  *param_1 = CHNode::CImpIHappServiceProvider::vftable;
  if ((longlong *)param_1[2] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[2] + 0x10))();
  }
  return;
}

/* ---- FUNC 000381B0 FUN_1800381b0 (53 bytes) ---- */

AcpTopRecord * FUN_1800381b0(AcpTopRecord *param_1,uint param_2)

{
  AcpTopRecord::~AcpTopRecord(param_1);
  if ((param_2 & 1) != 0) {
    FUN_180025ad0(param_1);
  }
  return param_1;
}

/* ---- FUNC 000381F0 FUN_1800381f0 (15 bytes) ---- */

void FUN_1800381f0(longlong *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0001800381f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x210))(param_1,0x7d3);
  return;
}

/* ---- FUNC 00038200 FUN_180038200 (437 bytes) ---- */

void FUN_180038200(longlong *param_1,undefined8 param_2,VARIANTARG *param_3)

{
  ushort uVar1;
  undefined4 *puVar2;
  HRESULT HVar3;
  longlong lVar4;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  VARIANTARG local_28;
  
  if (DAT_1800797f8 != 0) {
    (**(code **)(*param_1 + 0x210))(param_1,0x7f3);
    return;
  }
  if (param_1[9] == 0) {
    (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
    return;
  }
  VariantInit(&local_28);
  uVar1 = (param_3->n1).n2.vt;
  if (uVar1 == 0x400c) {
    puVar2 = *(undefined4 **)((longlong)&param_3->n1 + 8);
    local_48 = *puVar2;
    uStack_44 = puVar2[1];
    uStack_40 = puVar2[2];
    uStack_3c = puVar2[3];
    local_38 = *(undefined8 *)(puVar2 + 4);
    (**(code **)(*param_1 + 0x1e0))(param_1,param_2,&local_48);
    return;
  }
  if (uVar1 < 0xc) {
    if (uVar1 == 0xb) {
      local_28.n1._8_4_ = ZEXT14(*(short *)((longlong)&param_3->n1 + 8) != 0);
      goto LAB_180038373;
    }
    if (uVar1 != 0) {
      if (uVar1 == 2) {
        local_28.n1._8_4_ = SEXT24(*(short *)((longlong)&param_3->n1 + 8));
        goto LAB_180038373;
      }
      if (uVar1 == 3) {
        local_28.n1._8_4_ = *(uint *)((longlong)&param_3->n1 + 8);
        goto LAB_180038373;
      }
      if (uVar1 != 10) goto LAB_18003830e;
    }
    local_28.n1._8_4_ = 0;
  }
  else {
    if (uVar1 == 0x4002) {
      local_28.n1._8_4_ = SEXT24(**(short **)((longlong)&param_3->n1 + 8));
      goto LAB_180038373;
    }
    if (uVar1 == 0x4003) {
      local_28.n1._8_4_ = **(uint **)((longlong)&param_3->n1 + 8);
      goto LAB_180038373;
    }
    if (uVar1 == 0x400b) {
      local_28.n1._8_4_ = ZEXT14(**(short **)((longlong)&param_3->n1 + 8) != 0);
      goto LAB_180038373;
    }
LAB_18003830e:
    HVar3 = VariantChangeType(&local_28,param_3,0,3);
    if (HVar3 != 0) {
      (**(code **)(*param_1 + 0x210))(param_1,0x7d4);
      return;
    }
  }
LAB_180038373:
  lVar4 = HATemplAppend(param_1[9],param_2,local_28.n1._8_4_);
  if (lVar4 == 0) {
    return;
  }
  (**(code **)(*param_1 + 0x208))(param_1,lVar4);
  return;
}

/* ---- FUNC 000383C0 FUN_1800383c0 (192 bytes) ---- */

undefined8 FUN_1800383c0(longlong *param_1,short param_2,short param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  longlong lVar2;
  BSTR pOVar3;
  undefined1 local_28 [8];
  LPCSTR local_20;
  code *local_18;
  
  if (DAT_1800797f8 != 0) {
    uVar1 = (**(code **)(*param_1 + 0x210))(param_1,0x7f3);
    return uVar1;
  }
  *param_4 = 0;
  if (param_1[9] == 0) {
    uVar1 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
    return uVar1;
  }
  lVar2 = HABrowse(param_1[9],(int)param_2,(int)param_3,local_28);
  if (lVar2 != 0) {
    uVar1 = (**(code **)(*param_1 + 0x208))(param_1,lVar2);
    return uVar1;
  }
  if (local_20 != (LPCSTR)0x0) {
    pOVar3 = FUN_1800019d0(local_20);
    *param_4 = pOVar3;
    if (local_18 != (code *)0x0) {
      (*local_18)(local_20);
    }
  }
  return 0;
}

/* ---- FUNC 00038480 FUN_180038480 (323 bytes) ---- */

undefined8 FUN_180038480(longlong param_1,longlong *param_2,wchar_t *param_3)

{
  bool bVar1;
  int iVar2;
  HRESULT HVar3;
  IAtlStringMgr *pIVar4;
  OLECHAR local_48 [4];
  char *local_40;
  IMoniker *local_38 [2];
  
  local_48[0] = L'!';
  local_48[1] = L'\0';
  bVar1 = false;
  if (*(int *)(*(longlong *)(param_1 + 0x1d8) + -0x10) != 0) {
    pIVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                       ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                        (param_1 + 0x1d8));
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_40,param_3,
               pIVar4);
    iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       (param_1 + 0x1d8),local_40);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_40);
    if ((iVar2 != 0) && (*(longlong **)(param_1 + 0xe8) != (longlong *)0x0)) {
      (**(code **)(**(longlong **)(param_1 + 0xe8) + 0x10))();
      *(undefined8 *)(param_1 + 0xe8) = 0;
      bVar1 = true;
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x1d8),
             param_3);
  if (*(longlong *)(param_1 + 0xe8) == 0) {
    HVar3 = CreateItemMoniker(local_48,param_3,local_38);
    if (-1 < HVar3) {
      (**(code **)(*param_2 + 0x58))(param_2,local_38[0],0,param_1 + 0xe8);
      (*local_38[0]->lpVtbl->Release)(local_38[0]);
      if (bVar1) {
        FUN_18003d280(param_1,2);
      }
      return 0;
    }
  }
  return 1;
}

/* ---- FUNC 000385D0 FUN_1800385d0 (176 bytes) ---- */

undefined8 FUN_1800385d0(longlong *param_1,int param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0001800385ef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x210))(param_1,0x7f3);
    return uVar1;
  }
  if (param_1[9] == 0) {
                    /* WARNING: Could not recover jumptable at 0x00018003860f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
    return uVar1;
  }
  if (param_2 == -1) {
    lVar2 = HAClear();
  }
  else {
    lVar2 = HAClear2();
  }
  if (lVar2 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018003863c. Too many branches */
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
  return 0;
}

/* ---- FUNC 00038680 FUN_180038680 (15 bytes) ---- */

void FUN_180038680(longlong *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180038688. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x200))(param_1,0xffffffff);
  return;
}

/* ---- FUNC 00038690 FUN_180038690 (319 bytes) ---- */

undefined8 FUN_180038690(LPUNKNOWN param_1,int param_2)

{
  IUnknownVtbl *pIVar1;
  int iVar2;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar3;
  undefined8 *puVar4;
  longlong *local_res8;
  
  if (*(int *)&param_1[8].lpVtbl == 0) {
    if (param_2 == 2) {
      pCVar3 = FUN_180020fe0((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_res8,0x10);
      iVar2 = MMAfxMessageBox(*(char **)pCVar3,3,-1,0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
      if (iVar2 == 2) {
        return 0x8004000c;
      }
    }
    *(undefined4 *)&param_1[8].lpVtbl = 1;
    (*param_1->lpVtbl->AddRef)(param_1);
    pIVar1 = param_1[0xc].lpVtbl;
    if ((pIVar1 != (IUnknownVtbl *)0x0) &&
       (iVar2 = (**(code **)pIVar1->QueryInterface)(pIVar1,&DAT_180066db8,&local_res8), -1 < iVar2))
    {
      (**(code **)(*local_res8 + 0xa0))(local_res8,*(undefined4 *)&param_1[0x3a].lpVtbl);
      (**(code **)(*local_res8 + 0x10))();
      *(undefined4 *)&param_1[0x3a].lpVtbl = 0;
    }
    FUN_18003d280((longlong)param_1,1);
    CoDisconnectObject(param_1 + 0x3e,0);
    CoDisconnectObject(param_1,0);
    if (param_1[9].lpVtbl != (IUnknownVtbl *)0x0) {
      puVar4 = (undefined8 *)HASetBptr(0);
      if ((puVar4 != (undefined8 *)0x0) && ((code *)*puVar4 != (code *)0x0)) {
        (*(code *)*puVar4)(puVar4);
      }
      param_1[9].lpVtbl = (IUnknownVtbl *)0x0;
    }
    iVar2 = *(int *)((longlong)&param_1[1].lpVtbl + 4);
    while (iVar2 != 0) {
      FUN_18003b0a0((longlong *)param_1,0);
      iVar2 = *(int *)((longlong)&param_1[1].lpVtbl + 4);
    }
    *(undefined4 *)&param_1[8].lpVtbl = 0;
    (*param_1->lpVtbl->Release)(param_1);
  }
  return 1;
}

/* ---- FUNC 000387D0 FUN_1800387d0 (501 bytes) ---- */

HRESULT FUN_1800387d0(IUnknownVtbl *param_1,longlong *param_2,IUnknownVtbl *param_3,
                     IUnknownVtbl *param_4,int param_5,IUnknownVtbl *param_6)

{
  HRESULT HVar1;
  int iVar2;
  IUnknownVtbl *pIVar3;
  LPUNKNOWN local_res10;
  undefined8 *local_28;
  longlong *local_20;
  
  *param_2 = 0;
  local_28 = (undefined8 *)HAGetBptr(param_1,&local_res10);
  if (local_28 == (undefined8 *)0x0) {
    if (local_res10 != (LPUNKNOWN)0x0) {
      *param_2 = (longlong)local_res10;
      return 1;
    }
    if (DAT_180079888 == 0) {
      HVar1 = FUN_180033ad0(&DAT_180079880,(GUID *)&DAT_180063400);
      if (HVar1 < 0) {
        return HVar1;
      }
    }
    else {
      (**(code **)(*DAT_180079880 + 8))();
    }
    DAT_180079888 = DAT_180079888 + 1;
    local_20 = operator_new(0x208);
    local_res10 = (LPUNKNOWN)0x0;
    if (local_20 != (longlong *)0x0) {
      local_res10 = (LPUNKNOWN)FUN_180037c40(local_20);
    }
    local_res10[9].lpVtbl = param_1;
    local_res10[10].lpVtbl = param_3;
    (**(code **)(param_3->QueryInterface + 8))(param_3);
    local_res10[0xc].lpVtbl = param_4;
    iVar2 = HAGetDimension(param_1,&local_28);
    *(int *)&local_res10[0x2c].lpVtbl = iVar2;
    if (iVar2 != -1) {
      local_28 = (undefined8 *)0x0;
      *(int *)&local_res10[0xd].lpVtbl = param_5;
      if (param_4 != (IUnknownVtbl *)0x0) {
        (**(code **)(param_4->QueryInterface + 8))(param_4);
        iVar2 = (**(code **)param_4->QueryInterface)(param_4,&DAT_180066db8,&local_20);
        if (-1 < iVar2) {
          (**(code **)(*local_20 + 0x98))(local_20,local_res10[0x39].lpVtbl,local_res10 + 0x3a);
          (**(code **)(*local_20 + 0x10))();
        }
        if (param_5 == 0) {
          pIVar3 = (IUnknownVtbl *)local_res10[0xc].lpVtbl[9].Release;
        }
        else {
          pIVar3 = (IUnknownVtbl *)local_res10[0xc].lpVtbl[0xb].Release;
        }
        local_res10[0xe].lpVtbl = pIVar3;
        if (local_res10[0xe].lpVtbl != (IUnknownVtbl *)0x0) {
          (**(code **)((local_res10[0xe].lpVtbl)->QueryInterface + 8))();
        }
      }
      local_res10[2].lpVtbl = param_6;
      local_28 = (undefined8 *)HASetBptr(local_res10,param_1);
      if (local_28 == (undefined8 *)0x0) {
        *param_2 = (longlong)local_res10;
        return 0;
      }
      FUN_180038690(local_res10,1);
      if ((code *)*local_28 != (code *)0x0) {
        (*(code *)*local_28)();
      }
    }
  }
  else if ((code *)*local_28 != (code *)0x0) {
    (*(code *)*local_28)(local_28);
  }
  return -0x7fffbffb;
}

/* ---- FUNC 000389D0 FUN_1800389d0 (368 bytes) ---- */

int FUN_1800389d0(IUnknownVtbl *param_1,IUnknownVtbl *param_2,IUnknownVtbl *param_3,int param_4,
                 IUnknownVtbl *param_5,undefined8 *param_6)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *local_28;
  undefined8 *local_20;
  
  local_28 = (undefined8 *)0x0;
  local_20 = (undefined8 *)0x0;
  *param_6 = 0;
  WaitForSingleObject(DAT_1800797e8,100);
  puVar2 = (undefined8 *)HAGetBptr(param_1,&local_28);
  if (puVar2 == (undefined8 *)0x0) {
    if (local_28 == (undefined8 *)0x0) {
      ReleaseSemaphore(DAT_1800797e8,1,(LPLONG)0x0);
      FUN_1800387d0(param_1,(longlong *)&local_20,param_2,param_3,param_4,param_5);
      puVar2 = local_20;
      if ((local_20 == (undefined8 *)0x0) &&
         (DAT_1800797d4 = DAT_1800797d4 + 1, param_5 != (IUnknownVtbl *)0x0)) {
        (*(code *)param_5)();
      }
      iVar1 = (**(code **)*puVar2)(puVar2,&DAT_180063400,param_6);
      DAT_1800797d4 = DAT_1800797d4 + 1;
      if (iVar1 < 0) {
        FUN_180037ee0(puVar2);
        FUN_180025ad0(puVar2);
        if (param_5 != (IUnknownVtbl *)0x0) {
          (*(code *)param_5)();
        }
      }
    }
    else {
      iVar1 = (**(code **)*local_28)(local_28,&DAT_180063400,param_6);
      ReleaseSemaphore(DAT_1800797e8,1,(LPLONG)0x0);
    }
  }
  else {
    if ((code *)*puVar2 != (code *)0x0) {
      (*(code *)*puVar2)(puVar2);
    }
    ReleaseSemaphore(DAT_1800797e8,1,(LPLONG)0x0);
    iVar1 = -0x7fffbffb;
  }
  return iVar1;
}

/* ---- FUNC 00038B50 FUN_180038b50 (367 bytes) ---- */

HRESULT FUN_180038b50(longlong param_1,LPDATAADVISEHOLDER *param_2)

{
  longlong lVar1;
  LPDATAADVISEHOLDER pIVar2;
  IDataAdviseHolder *This;
  HRESULT HVar3;
  int iVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined1 local_28 [8];
  int *local_20;
  code *local_18;
  
  *param_2 = (LPDATAADVISEHOLDER)0x0;
  puVar5 = (undefined8 *)HAGetAttr(*(undefined8 *)(param_1 + 0x48),0x12,0,local_28);
  if (puVar5 == (undefined8 *)0x0) {
    iVar4 = *local_20;
    if (local_18 != (code *)0x0) {
      (*local_18)();
    }
    if (iVar4 == 0) {
      HVar3 = CreateDataAdviseHolder(param_2);
      if (-1 < HVar3) {
        *(LPDATAADVISEHOLDER *)(param_1 + 0x148) = *param_2;
        return HVar3;
      }
      return HVar3;
    }
    iVar4 = *(int *)(param_1 + 0x68);
    lVar1 = param_1;
    while ((iVar4 == 0 && (lVar1 = *(longlong *)(lVar1 + 0x60), lVar1 != 0))) {
      iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         (lVar1 + 0x1d8),"Output");
      lVar6 = lVar1;
      if (iVar4 == 0) {
LAB_180038c61:
        if (*(longlong **)(lVar6 + 0x148) != (longlong *)0x0) {
          (**(code **)(**(longlong **)(lVar6 + 0x148) + 8))();
          pIVar2 = *(LPDATAADVISEHOLDER *)(lVar6 + 0x148);
          *(LPDATAADVISEHOLDER *)(param_1 + 0x148) = pIVar2;
          *param_2 = pIVar2;
          return 0;
        }
        HVar3 = CreateDataAdviseHolder((LPDATAADVISEHOLDER *)(lVar6 + 0x148));
        if (-1 < HVar3) {
          This = *(IDataAdviseHolder **)(lVar6 + 0x148);
          *param_2 = This;
          (*This->lpVtbl->AddRef)(This);
          *(LPDATAADVISEHOLDER *)(param_1 + 0x148) = *param_2;
          return HVar3;
        }
        return HVar3;
      }
      iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         (lVar1 + 0x1d8),"Table");
      if (iVar4 == 0) {
        if (*(int *)(lVar1 + 0x68) != 0) {
          return -0x7fffbffb;
        }
        lVar6 = *(longlong *)(lVar1 + 0x60);
        if ((lVar6 != 0) &&
           (iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               (lVar6 + 0x1d8),"Stream-Sum"), iVar4 == 0)) goto LAB_180038c61;
      }
      iVar4 = *(int *)(lVar1 + 0x68);
    }
  }
  else if ((code *)*puVar5 != (code *)0x0) {
    (*(code *)*puVar5)(puVar5);
  }
  return -0x7fffbffb;
}

/* ---- FUNC 00038CC0 FUN_180038cc0 (73 bytes) ---- */

undefined8 FUN_180038cc0(longlong *param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  
  lVar2 = *param_1;
  if (DAT_1800797f8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x000180038cdf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(lVar2 + 0x210))(param_1,0x7f3);
    return uVar1;
  }
  if (param_1[0xc] != 0) {
                    /* WARNING: Could not recover jumptable at 0x000180038cf7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(lVar2 + 0x210))(param_1,0x7e9);
    return uVar1;
  }
  if (param_1[9] == 0) {
                    /* WARNING: Could not recover jumptable at 0x000180038da0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(lVar2 + 0x210))(param_1,0x7d9);
    return uVar1;
  }
  (**(code **)(lVar2 + 8))();
  lVar2 = HADeleteObject(param_1[9]);
  param_1[9] = 0;
  *(undefined4 *)(param_1[10] + 0x100) = 1;
  if (lVar2 != 0) {
    (**(code **)(*param_1 + 0x10))();
                    /* WARNING: Could not recover jumptable at 0x000180038d55. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x208))(param_1,lVar2);
    return uVar1;
  }
  FUN_18003e7a0((longlong)param_1,(IUnknown *)0x0,0);
  if (DAT_180079800 != (longlong *)0x0) {
    (**(code **)(*DAT_180079800 + 0x68))(DAT_180079800,0x73,param_1);
  }
  (**(code **)(*param_1 + 0x10))(param_1);
  return 0;
}

/* ---- FUNC 00038D09 FUN_180038d09 (83 bytes) ---- */

undefined8 FUN_180038d09(void)

{
  longlong in_RAX;
  longlong lVar1;
  undefined8 uVar2;
  longlong *unaff_RBX;
  
  (**(code **)(in_RAX + 8))();
  lVar1 = HADeleteObject(unaff_RBX[9]);
  unaff_RBX[9] = 0;
  *(undefined4 *)(unaff_RBX[10] + 0x100) = 1;
  if (lVar1 != 0) {
    (**(code **)(*unaff_RBX + 0x10))();
                    /* WARNING: Could not recover jumptable at 0x000180038d55. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(*unaff_RBX + 0x208))();
    return uVar2;
  }
  FUN_18003e7a0((longlong)unaff_RBX,(IUnknown *)0x0,0);
  if (DAT_180079800 != (longlong *)0x0) {
    (**(code **)(*DAT_180079800 + 0x68))(DAT_180079800,0x73);
  }
  (**(code **)(*unaff_RBX + 0x10))();
  return 0;
}

/* ---- FUNC 00038D5C FUN_180038d5c (58 bytes) ---- */

undefined8 FUN_180038d5c(longlong param_1)

{
  longlong *unaff_RBX;
  
  FUN_18003e7a0(param_1,(IUnknown *)0x0,0);
  if (DAT_180079800 != (longlong *)0x0) {
    (**(code **)(*DAT_180079800 + 0x68))(DAT_180079800,0x73);
  }
  (**(code **)(*unaff_RBX + 0x10))();
  return 0;
}

/* ---- FUNC 00038D96 FUN_180038d96 (17 bytes) ---- */

void FUN_180038d96(undefined8 param_1)

{
  longlong in_RAX;
  
                    /* WARNING: Could not recover jumptable at 0x000180038da0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(in_RAX + 0x210))(param_1,0x7d9);
  return;
}

/* ---- FUNC 00038DB0 FUN_180038db0 (201 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180038db0(longlong *param_1,undefined4 param_2,ushort *param_3)

{
  ulonglong uVar1;
  undefined1 auStack_4a8 [32];
  undefined4 local_488;
  ULONG UStack_484;
  undefined4 uStack_480;
  undefined4 uStack_47c;
  undefined8 local_478;
  _union_2707 local_468;
  _union_2707 local_448 [44];
  ulonglong local_28;
  
  local_28 = DAT_180077818 ^ (ulonglong)auStack_4a8;
  *param_3 = 0;
  VariantInit((VARIANTARG *)&local_448[0].n2);
  VariantInit((VARIANTARG *)&local_468.n2);
  local_488 = local_448[0]._0_4_;
  UStack_484 = local_448[0].decVal.Hi32;
  uStack_480 = local_448[0]._8_4_;
  uStack_47c = local_448[0]._12_4_;
  local_478 = local_448[0]._16_8_;
  (**(code **)(*param_1 + 0x98))(param_1,0x3e,&local_488,&local_468);
  if (local_468.n2.vt == 0xd) {
    AFX_EXCEPTION_LINK::AFX_EXCEPTION_LINK((AFX_EXCEPTION_LINK *)&local_488);
    uVar1 = FUN_180037410(param_2,local_468.decVal.u2);
    *param_3 = (ushort)(uVar1 >> 0x1f) & 1 ^ 1;
    AfxTryCleanup();
  }
  VariantClear((VARIANTARG *)&local_468.n2);
  return 0;
}

/* ---- FUNC 00038E80 FUN_180038e80 (310 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void FUN_180038e80(longlong *param_1,LPCWSTR param_2)

{
  undefined1 *puVar1;
  code *pcVar2;
  longlong lVar3;
  ulonglong uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  int iVar9;
  undefined8 uStack_60;
  undefined1 auStack_58 [32];
  undefined8 uStack_38;
  int aiStack_30 [2];
  undefined8 local_28 [2];
  ulonglong local_18 [2];
  longlong lVar4;
  
  puVar6 = auStack_58;
  local_18[0] = DAT_180077818 ^ (ulonglong)local_18;
  puVar7 = (undefined1 *)0x0;
  if (DAT_1800797f8 == 0) {
    lVar3 = param_1[9];
    if (lVar3 == 0) {
      uStack_60 = 0x180038edf;
      (**(code **)(*param_1 + 0x210))(param_1,0x7d9);
      puVar6 = auStack_58;
    }
    else {
      puVar8 = puVar7;
      if (param_2 != (LPCWSTR)0x0) {
        lVar3 = -1;
        do {
          lVar4 = lVar3;
          lVar3 = lVar4 + 1;
        } while (param_2[lVar3] != L'\0');
        iVar9 = (int)lVar4 + 2;
        puVar6 = auStack_58;
        if (iVar9 < 0x40000000) {
          lVar3 = (longlong)(int)lVar3 * 2;
          uVar5 = lVar3 + 0x11;
          if (uVar5 <= lVar3 + 2U) {
            uVar5 = 0xffffffffffffff0;
          }
          uStack_60 = 0x180038f33;
          lVar3 = -(uVar5 & 0xfffffffffffffff0);
          puVar1 = (undefined1 *)((longlong)local_18 + lVar3);
          puVar6 = auStack_58 + lVar3;
          if (puVar1 != (undefined1 *)0x0) {
            *(undefined8 *)((longlong)local_28 + lVar3 + 8) = 0;
            *(undefined8 *)((longlong)local_28 + lVar3) = 0;
            *(int *)((longlong)aiStack_30 + lVar3) = iVar9 * 2;
            *(undefined1 **)((longlong)&uStack_38 + lVar3) = puVar1;
            *puVar1 = 0;
            *(undefined8 *)(auStack_58 + lVar3 + -8) = 0x180038f6d;
            iVar9 = WideCharToMultiByte(0,0,param_2,-1,*(LPSTR *)((longlong)&uStack_38 + lVar3),
                                        *(int *)((longlong)aiStack_30 + lVar3),
                                        *(LPCSTR *)((longlong)local_28 + lVar3),
                                        *(LPBOOL *)((longlong)local_28 + lVar3 + 8));
            puVar6 = auStack_58 + lVar3;
            puVar8 = puVar1;
            if (iVar9 == 0) {
              puVar6 = auStack_58 + lVar3;
              puVar8 = puVar7;
            }
          }
        }
        lVar3 = param_1[9];
      }
      *(undefined8 *)(puVar6 + -8) = 0x180038f83;
      lVar3 = HAExport(lVar3,puVar8);
      if (lVar3 != 0) {
        pcVar2 = *(code **)(*param_1 + 0x208);
        *(undefined8 *)(puVar6 + -8) = 0x180038f98;
        (*pcVar2)(param_1,lVar3);
      }
    }
  }
  else {
    uStack_60 = 0x180038ec0;
    (**(code **)(*param_1 + 0x210))(param_1,0x7f3);
    puVar6 = auStack_58;
  }
  *(undefined8 *)(puVar6 + -8) = 0x180038fa4;
  return;
}

/* ---- FUNC 00038FC0 FUN_180038fc0 (3450 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */

longlong * FUN_180038fc0(longlong *param_1,byte *param_2)

{
  byte bVar1;
  char cVar2;
  code *pcVar3;
  char *******pppppppcVar4;
  longlong *plVar5;
  void *pvVar6;
  undefined1 auVar7 [8];
  int iVar8;
  longlong lVar9;
  _union_1719 _Var10;
  char *******pppppppcVar11;
  longlong lVar12;
  byte *pbVar13;
  undefined1 auVar14 [8];
  ulonglong uVar15;
  char *******pppppppcVar16;
  byte *pbVar17;
  OLECHAR *pOVar18;
  _union_2707 *p_Var19;
  undefined1 *puVar20;
  undefined1 *puVar21;
  undefined1 *puVar22;
  undefined1 *puVar23;
  undefined1 *puVar24;
  byte *pbVar25;
  _union_1719 *p_Var26;
  uint uVar27;
  ulonglong _Size;
  ulonglong uVar28;
  size_t sVar29;
  uint uVar30;
  byte bVar31;
  uint uVar32;
  uint uVar33;
  longlong lVar34;
  uint uVar35;
  bool bVar36;
  undefined1 auStack_248 [64];
  byte local_208 [4];
  uint local_204;
  byte *local_200;
  byte *local_1f8;
  byte *local_1f0;
  longlong *local_1e8;
  byte *local_1e0;
  longlong *local_1d8;
  longlong local_1d0;
  void *local_1c8;
  byte *local_1c0;
  byte *local_1b8;
  longlong *local_1b0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  char *******local_128;
  undefined8 uStack_120;
  longlong local_118;
  ulonglong local_110;
  char *******local_108;
  undefined8 uStack_100;
  longlong local_f8;
  ulonglong local_f0;
  undefined1 local_e8 [8];
  _union_1719 _Stack_e0;
  ulonglong local_d8;
  ulonglong local_d0;
  undefined1 local_c8 [24];
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  ulonglong local_48;
  
  puVar24 = auStack_248;
  puVar23 = auStack_248;
  local_48 = DAT_180077818 ^ (ulonglong)local_208;
  uVar33 = 0;
  local_1c0 = (byte *)0x0;
  local_1e8 = (longlong *)0x0;
  puVar21 = auStack_248;
  if (param_2 == (byte *)0x0) goto LAB_180039643;
  bVar31 = *param_2;
  uVar32 = (uint)(char)bVar31;
  local_208[0] = bVar31;
  local_1f8 = param_2;
  local_1b0 = param_1;
  if (bVar31 == 0) {
    (**(code **)(*param_1 + 8))(param_1);
    goto LAB_180039645;
  }
  if (uVar32 == 0x2e) {
    pbVar25 = param_2 + 1;
    if ((param_2[1] == 0x2e) && (pbVar25 = param_2 + 2, (int)param_1[0xd] == 0)) {
      param_1 = FUN_180038fc0((longlong *)param_1[0xc],pbVar25);
      puVar23 = auStack_248;
      goto LAB_180039645;
    }
LAB_180039cc1:
    param_1 = FUN_180038fc0(param_1,pbVar25);
    puVar23 = auStack_248;
  }
  else {
    if ((uVar32 == 0x2f) || (uVar32 == 0x5c)) {
      if ((param_2[1] != 0x5c) && (param_2[1] != 0x2f)) {
        pbVar25 = param_2 + 1;
        goto LAB_180039cc1;
      }
      iVar8 = (**(code **)(*(longlong *)param_1[10] + 0x90))((longlong *)param_1[10],&local_1e8);
      puVar21 = auStack_248;
      if (-1 < iVar8) {
        param_1 = FUN_180038fc0(local_1e8,param_2 + 2);
        (**(code **)(*local_1e8 + 0x10))();
        puVar23 = auStack_248;
        goto LAB_180039645;
      }
    }
    else {
      uVar30 = 0xffffffff;
      local_1e0 = (byte *)((ulonglong)local_1e0 & 0xffffffff00000000);
      local_204 = 0xffffffff;
      lVar12 = -1;
      do {
        lVar34 = lVar12;
        lVar12 = lVar34 + 1;
      } while (param_2[lVar12] != 0);
      local_200 = operator_new__(lVar34 + 2);
      lVar12 = -1;
      do {
        lVar34 = lVar12;
        lVar12 = lVar34 + 1;
      } while (param_2[lVar12] != 0);
      local_1c8 = operator_new__(lVar34 + 2);
      local_1f0 = local_200;
      pbVar25 = local_200;
      if (bVar31 == 0) {
        pbVar13 = param_2;
        bVar31 = 0;
      }
      else {
        lVar12 = (longlong)local_1c8 - (longlong)local_200;
        pbVar13 = param_2;
        pbVar17 = local_200;
        uVar27 = uVar33;
        uVar35 = uVar33;
        local_1d0 = lVar12;
        while( true ) {
          bVar31 = (byte)uVar32;
          if (bVar31 == 0x5c) break;
          if (bVar31 == 0x2f) {
            local_d8 = 0;
            local_d0 = 0;
            local_e8 = (undefined1  [8])0x0;
            _Stack_e0.Lo64 = 0;
            FUN_180037800((undefined8 *)local_e8,pbVar17,(longlong)(int)uVar33);
            uVar28 = local_d0;
            uVar15 = local_d8;
            auVar7 = local_e8;
            auVar14 = (undefined1  [8])local_e8;
            if (0xf < local_d0) {
              auVar14 = local_e8;
            }
            _Size = local_d8;
            if (5 < local_d8) {
              _Size = 5;
            }
            iVar8 = memcmp((void *)auVar14,"Assay",_Size);
            pbVar25 = local_1f0;
            uVar30 = local_204;
            if (((iVar8 == 0) && (uVar15 == 5)) && ((int)local_1e0 == 0)) {
              local_1e0 = (byte *)CONCAT44(local_1e0._4_4_,uVar33 + 1);
              local_1b8 = local_1f8;
            }
            else {
              if ((uVar27 == 0) || (uVar35 != 0)) {
                if (0xf < uVar28) {
                  auVar14 = auVar7;
                  if ((0xfff < uVar28 + 1) &&
                     (auVar14 = *(undefined1 (*) [8])((longlong)auVar7 + -8),
                     (undefined1 *)0x1f <
                     (undefined1 *)((longlong)auVar7 + (-8 - (longlong)auVar14))))
                  goto LAB_180039320;
                  FUN_180025ad0((void *)auVar14);
                  pbVar25 = local_1f0;
                  uVar30 = local_204;
                }
                break;
              }
              uVar35 = uVar33 + 1;
              local_1c0 = local_1f8;
            }
            lVar12 = local_1d0;
            pbVar17 = local_200;
            if (0xf < uVar28) {
              auVar14 = auVar7;
              if ((0xfff < uVar28 + 1) &&
                 (auVar14 = *(undefined1 (*) [8])((longlong)auVar7 + -8),
                 (undefined1 *)0x1f < (undefined1 *)((longlong)auVar7 + (-8 - (longlong)auVar14))))
              goto LAB_180039320;
              FUN_180025ad0((void *)auVar14);
              lVar12 = local_1d0;
              pbVar17 = local_200;
              pbVar25 = local_1f0;
              uVar30 = local_204;
            }
LAB_1800391c0:
            pbVar25[lVar12] = local_208[0];
            *pbVar25 = local_208[0];
            pbVar25 = pbVar25 + 1;
            uVar33 = uVar33 + 1;
            pbVar13 = local_1f8;
            local_1f0 = pbVar25;
          }
          else {
            local_208[0] = bVar31;
            if (bVar31 != 0x27) goto LAB_1800391c0;
            uVar27 = uVar27 ^ 1;
            uVar30 = uVar33;
            local_204 = uVar33;
            if (uVar35 != 0) {
              local_204 = 0xffffffff;
              uVar30 = 0xffffffff;
              uVar35 = 0;
            }
          }
          local_208[0] = pbVar13[1];
          uVar32 = (uint)local_208[0];
          pbVar13 = pbVar13 + 1;
          local_1f8 = pbVar13;
          if (local_208[0] == 0) break;
        }
        if ((int)local_1e0 != 0) {
          iVar8 = uVar33 - (int)local_1e0;
          local_d8 = 0;
          local_d0 = 0;
          local_1e0 = local_200 + (int)local_1e0;
          local_e8 = (undefined1  [8])0x0;
          _Stack_e0.Lo64 = 0;
          FUN_180037800((undefined8 *)local_e8,local_1e0,(longlong)iVar8);
          uVar15 = local_d0;
          auVar7 = local_e8;
          auVar14 = (undefined1  [8])local_e8;
          if (0xf < local_d0) {
            auVar14 = local_e8;
          }
          uVar28 = local_d8;
          if (5 < local_d8) {
            uVar28 = 5;
          }
          iVar8 = memcmp((void *)auVar14,"Blend",uVar28);
          if ((iVar8 != 0) || (local_d8 != 5)) {
            local_1e0[-1] = 0;
            local_1f8 = local_1b8;
          }
          if (0xf < uVar15) {
            auVar14 = auVar7;
            if ((0xfff < uVar15 + 1) &&
               (auVar14 = *(undefined1 (*) [8])((longlong)auVar7 + -8),
               (undefined1 *)0x1f < (undefined1 *)((longlong)auVar7 + (-8 - (longlong)auVar14)))) {
LAB_180039320:
                    /* WARNING: Subroutine does not return */
              _invalid_parameter_noinfo_noreturn();
            }
            FUN_180025ad0((void *)auVar14);
          }
        }
        pbVar13 = local_1f8;
        bVar31 = local_208[0];
        if ((uVar35 != 0) && (uVar27 != 0)) {
          lVar12 = (longlong)(int)(uVar30 + 1);
          if (lVar12 <= (int)(uVar35 - 1)) {
            pbVar13 = local_200 + lVar12;
            lVar12 = ((int)(uVar35 - 1) - lVar12) + 1;
            do {
              *pbVar13 = pbVar13[local_1d0 + -1];
              pbVar13 = pbVar13 + 1;
              lVar12 = lVar12 + -1;
              pbVar25 = local_1f0;
            } while (lVar12 != 0);
          }
          local_200[(int)uVar30] = 0x27;
          local_200[(int)uVar35] = 0;
          pbVar13 = local_1c0;
        }
      }
      *pbVar25 = 0;
      lVar12 = 5;
      p_Var19 = (_union_2707 *)local_c8;
      do {
        VariantInit((VARIANTARG *)&p_Var19->n2);
        plVar5 = local_1b0;
        p_Var19 = p_Var19 + 1;
        lVar12 = lVar12 + -1;
      } while (lVar12 != 0);
      local_1d8 = (longlong *)0x0;
      iVar8 = (**(code **)(*local_1b0 + 200))(local_1b0,&local_1d8);
      puVar23 = auStack_248;
      if (-1 < iVar8) {
        if (*local_200 == 0x28) {
          pbVar25 = local_200 + 1;
          puVar24 = auStack_248;
          if (*pbVar25 != 0) {
            lVar12 = 0;
            p_Var26 = &(((_union_2707 *)local_c8)->decVal).u2;
            puVar24 = auStack_248;
            pbVar17 = pbVar25;
            do {
              pOVar18 = (OLECHAR *)0x0;
              if (4 < lVar12) break;
              bVar31 = *pbVar25;
              if ((bVar31 == 0x2c) || (bVar31 == 0x29)) {
                *pbVar25 = 0;
                if (*pbVar17 == 0x23) {
                  *(undefined2 *)(p_Var26 + -1) = 3;
                  *(undefined8 *)(puVar24 + -8) = 0x180039466;
                  iVar8 = atoi((char *)(pbVar17 + 1));
                  (p_Var26->s2).Lo32 = iVar8;
                }
                else {
                  *(undefined2 *)(p_Var26 + -1) = 8;
                  lVar34 = -1;
                  do {
                    lVar9 = lVar34;
                    lVar34 = lVar9 + 1;
                  } while (pbVar17[lVar34] != 0);
                  iVar8 = (int)lVar9 + 2;
                  if (iVar8 < 0x40000000) {
                    lVar34 = (longlong)(int)lVar34 * 2;
                    uVar15 = lVar34 + 0x11;
                    if (uVar15 <= lVar34 + 2U) {
                      uVar15 = 0xffffffffffffff0;
                    }
                    *(undefined8 *)(puVar24 + -8) = 0x1800394bc;
                    lVar34 = -(uVar15 & 0xfffffffffffffff0);
                    puVar20 = puVar24 + lVar34;
                    pOVar18 = (OLECHAR *)(puVar24 + lVar34 + 0x40);
                    if (pOVar18 == (OLECHAR *)0x0) {
                      pOVar18 = (OLECHAR *)0x0;
                      puVar24 = puVar24 + lVar34;
                    }
                    else {
                      *(int *)(puVar24 + lVar34 + 0x28) = iVar8;
                      *pOVar18 = L'\0';
                      *(OLECHAR **)(puVar24 + lVar34 + 0x20) = pOVar18;
                      *(undefined8 *)(puVar24 + lVar34 + -8) = 0x1800394e7;
                      iVar8 = MultiByteToWideChar(0,0,(LPCSTR)pbVar17,-1,
                                                  *(LPWSTR *)(puVar24 + lVar34 + 0x20),
                                                  *(int *)(puVar24 + lVar34 + 0x28));
                      puVar24 = puVar24 + lVar34;
                      if (iVar8 == 0) {
                        pOVar18 = (OLECHAR *)0x0;
                        puVar24 = puVar20;
                      }
                    }
                  }
                  *(undefined8 *)(puVar24 + -8) = 0x180039501;
                  _Var10 = (_union_1719)SysAllocString(pOVar18);
                  *p_Var26 = _Var10;
                }
                lVar12 = lVar12 + 1;
                p_Var26 = p_Var26 + 3;
                pbVar17 = pbVar25 + 1;
                if (bVar31 == 0x29) break;
              }
              pbVar25 = pbVar25 + 1;
            } while (*pbVar25 != 0);
          }
        }
        else if ((int)plVar5[0x2c] < 2) {
          if (*local_200 == 0x23) {
            local_c8._0_2_ = 3;
            iVar8 = atoi((char *)(local_200 + 1));
            local_c8._8_4_ = iVar8;
            puVar24 = auStack_248;
          }
          else {
            local_f8 = 0;
            local_108 = (char *******)0x0;
            uStack_100 = 0;
            local_f0 = 0;
            sVar29 = 0xffffffffffffffff;
            do {
              sVar29 = sVar29 + 1;
            } while (local_200[sVar29] != 0);
            FUN_180037800(&local_108,local_200,sVar29);
            pppppppcVar11 = (char *******)&local_108;
            if (0xf < local_f0) {
              pppppppcVar11 = local_108;
            }
            if (local_f8 == 0) {
LAB_180039aa2:
              iVar8 = -1;
            }
            else {
              lVar12 = -1;
              if (local_f8 + -1 != -1) {
                lVar12 = local_f8 + -1;
              }
              pppppppcVar16 = (char *******)((longlong)pppppppcVar11 + lVar12);
              cVar2 = *(char *)pppppppcVar16;
              while (cVar2 != '\'') {
                if (pppppppcVar16 == pppppppcVar11) goto LAB_180039aa2;
                pppppppcVar16 = (char *******)((longlong)pppppppcVar16 + -1);
                cVar2 = *(char *)pppppppcVar16;
              }
              iVar8 = (int)pppppppcVar16 - (int)pppppppcVar11;
            }
            while (-1 < iVar8) {
              pppppppcVar11 = (char *******)&local_108;
              if (0xf < local_f0) {
                pppppppcVar11 = local_108;
              }
              pppppppcVar11 = (char *******)((longlong)pppppppcVar11 + local_f8);
              pppppppcVar16 = (char *******)&local_108;
              if (0xf < local_f0) {
                pppppppcVar16 = local_108;
              }
              if (pppppppcVar16 != pppppppcVar11) {
                do {
                  if (*(char *)pppppppcVar16 == '\'') break;
                  pppppppcVar16 = (char *******)((longlong)pppppppcVar16 + 1);
                } while (pppppppcVar16 != pppppppcVar11);
                pppppppcVar4 = pppppppcVar16;
                if (pppppppcVar16 != pppppppcVar11) {
                  while (pppppppcVar4 = (char *******)((longlong)pppppppcVar4 + 1),
                        pppppppcVar4 != pppppppcVar11) {
                    if (*(char *)pppppppcVar4 != '\'') {
                      *(char *)pppppppcVar16 = *(char *)pppppppcVar4;
                      pppppppcVar16 = (char *******)((longlong)pppppppcVar16 + 1);
                    }
                  }
                }
              }
              pppppppcVar11 = (char *******)&local_108;
              if (0xf < local_f0) {
                pppppppcVar11 = local_108;
              }
              lVar12 = (longlong)pppppppcVar16 - (longlong)pppppppcVar11;
              pppppppcVar11 = (char *******)&local_108;
              if (0xf < local_f0) {
                pppppppcVar11 = local_108;
              }
              lVar34 = local_f8 - (ulonglong)(local_f8 != lVar12);
              memmove((char *)((longlong)pppppppcVar11 + lVar12),
                      (char *)((longlong)pppppppcVar11 + lVar12) + (local_f8 != lVar12),
                      (lVar34 - lVar12) + 1);
              local_f8 = lVar34;
              pppppppcVar11 = (char *******)&local_108;
              if (0xf < local_f0) {
                pppppppcVar11 = local_108;
              }
              if (lVar34 == 0) {
LAB_180039bc2:
                iVar8 = -1;
              }
              else {
                lVar12 = -1;
                if (lVar34 + -1 != -1) {
                  lVar12 = lVar34 + -1;
                }
                pppppppcVar16 = (char *******)((longlong)pppppppcVar11 + lVar12);
                cVar2 = *(char *)pppppppcVar16;
                while (cVar2 != '\'') {
                  if (pppppppcVar16 == pppppppcVar11) goto LAB_180039bc2;
                  pppppppcVar16 = (char *******)((longlong)pppppppcVar16 + -1);
                  cVar2 = *(char *)pppppppcVar16;
                }
                iVar8 = (int)pppppppcVar16 - (int)pppppppcVar11;
              }
            }
            pppppppcVar11 = (char *******)&local_108;
            if (0xf < local_f0) {
              pppppppcVar11 = local_108;
            }
            local_c8._0_2_ = 8;
            local_c8._8_8_ = FUN_1800019d0((LPCSTR)pppppppcVar11);
            puVar24 = auStack_248;
            if (0xf < local_f0) {
              pppppppcVar11 = local_108;
              if ((0xfff < local_f0 + 1) &&
                 (pppppppcVar11 = (char *******)local_108[-1],
                 (char *)0x1f < (char *)((longlong)local_108 + (-8 - (longlong)pppppppcVar11)))) {
                    /* WARNING: Subroutine does not return */
                _invalid_parameter_noinfo_noreturn();
              }
              FUN_180025ad0(pppppppcVar11);
              puVar24 = auStack_248;
            }
          }
        }
        else {
          uVar33 = 0;
          lVar12 = (longlong)local_200 - (longlong)param_2;
          do {
            bVar1 = *param_2;
            param_2[lVar12] = bVar1;
            param_2 = param_2 + 1;
          } while (bVar1 != 0);
          pbVar13 = local_200;
          if (0 < (int)plVar5[0x2c]) {
            p_Var26 = &(((_union_2707 *)local_c8)->decVal).u2;
            pbVar25 = local_200;
            puVar24 = auStack_248;
            pbVar17 = local_200;
            uVar32 = uVar33;
            do {
              bVar31 = *pbVar17;
              uVar30 = uVar32 ^ 1;
              if (bVar31 != 0x27) {
                uVar30 = uVar32;
              }
              if (((uVar30 == 0) && ((bVar31 == 0x5c || (bVar31 == 0x2f)))) || (bVar31 == 0)) {
                *pbVar17 = 0;
                if (*pbVar25 == 0x23) {
                  *(undefined2 *)(p_Var26 + -1) = 3;
                  *(undefined8 *)(puVar24 + -8) = 0x180039707;
                  iVar8 = atoi((char *)(pbVar25 + 1));
                  (p_Var26->s2).Lo32 = iVar8;
                }
                else {
                  local_118 = 0;
                  local_110 = 0;
                  sVar29 = 0xffffffffffffffff;
                  local_128 = (char *******)0x0;
                  uStack_120 = 0;
                  do {
                    sVar29 = sVar29 + 1;
                  } while (pbVar25[sVar29] != 0);
                  *(undefined8 *)(puVar24 + -8) = 0x180039746;
                  FUN_180037800(&local_128,pbVar25,sVar29);
                  pppppppcVar11 = (char *******)&local_128;
                  if (0xf < local_110) {
                    pppppppcVar11 = local_128;
                  }
                  if (local_118 == 0) {
LAB_1800397a2:
                    iVar8 = -1;
                  }
                  else {
                    lVar12 = -1;
                    if (local_118 + -1 != -1) {
                      lVar12 = local_118 + -1;
                    }
                    pppppppcVar16 = (char *******)((longlong)pppppppcVar11 + lVar12);
                    cVar2 = *(char *)pppppppcVar16;
                    while (cVar2 != '\'') {
                      if (pppppppcVar16 == pppppppcVar11) goto LAB_1800397a2;
                      pppppppcVar16 = (char *******)((longlong)pppppppcVar16 + -1);
                      cVar2 = *(char *)pppppppcVar16;
                    }
                    iVar8 = (int)pppppppcVar16 - (int)pppppppcVar11;
                  }
                  while (-1 < iVar8) {
                    pppppppcVar11 = (char *******)&local_128;
                    if (0xf < local_110) {
                      pppppppcVar11 = local_128;
                    }
                    pppppppcVar16 = (char *******)((longlong)pppppppcVar11 + local_118);
                    if (pppppppcVar11 != pppppppcVar16) {
                      do {
                        if (*(char *)pppppppcVar11 == '\'') break;
                        pppppppcVar11 = (char *******)((longlong)pppppppcVar11 + 1);
                      } while (pppppppcVar11 != pppppppcVar16);
                      pppppppcVar4 = pppppppcVar11;
                      if (pppppppcVar11 != pppppppcVar16) {
                        while (pppppppcVar4 = (char *******)((longlong)pppppppcVar4 + 1),
                              pppppppcVar4 != pppppppcVar16) {
                          if (*(char *)pppppppcVar4 != '\'') {
                            *(char *)pppppppcVar11 = *(char *)pppppppcVar4;
                            pppppppcVar11 = (char *******)((longlong)pppppppcVar11 + 1);
                          }
                        }
                      }
                    }
                    pppppppcVar16 = (char *******)&local_128;
                    if (0xf < local_110) {
                      pppppppcVar16 = local_128;
                    }
                    lVar12 = (longlong)pppppppcVar11 - (longlong)pppppppcVar16;
                    bVar36 = local_118 != lVar12;
                    pppppppcVar11 = (char *******)&local_128;
                    if (0xf < local_110) {
                      pppppppcVar11 = local_128;
                    }
                    lVar34 = local_118 - (ulonglong)bVar36;
                    *(undefined8 *)(puVar24 + -8) = 0x180039864;
                    memmove((char *)((longlong)pppppppcVar11 + lVar12),
                            (char *)((longlong)pppppppcVar11 + lVar12) + bVar36,
                            (lVar34 - lVar12) + 1);
                    local_118 = lVar34;
                    pppppppcVar11 = (char *******)&local_128;
                    if (0xf < local_110) {
                      pppppppcVar11 = local_128;
                    }
                    if (lVar34 == 0) {
LAB_1800398b9:
                      iVar8 = -1;
                    }
                    else {
                      lVar12 = -1;
                      if (lVar34 + -1 != -1) {
                        lVar12 = lVar34 + -1;
                      }
                      pppppppcVar16 = (char *******)((longlong)pppppppcVar11 + lVar12);
                      cVar2 = *(char *)pppppppcVar16;
                      while (cVar2 != '\'') {
                        if (pppppppcVar16 == pppppppcVar11) goto LAB_1800398b9;
                        pppppppcVar16 = (char *******)((longlong)pppppppcVar16 + -1);
                        cVar2 = *(char *)pppppppcVar16;
                      }
                      iVar8 = (int)pppppppcVar16 - (int)pppppppcVar11;
                    }
                  }
                  *(undefined2 *)(p_Var26 + -1) = 8;
                  pppppppcVar11 = (char *******)&local_128;
                  puVar23 = puVar24;
                  if ((local_110 < 0x10) ||
                     (pppppppcVar11 = local_128, local_128 != (char *******)0x0)) {
                    lVar12 = -1;
                    do {
                      lVar34 = lVar12;
                      lVar12 = lVar34 + 1;
                    } while (*(char *)((longlong)pppppppcVar11 + lVar12) != '\0');
                    iVar8 = (int)lVar34 + 2;
                    if (0x3fffffff < iVar8) goto LAB_180039964;
                    lVar12 = (longlong)(int)lVar12 * 2;
                    uVar15 = lVar12 + 0x11;
                    if (uVar15 <= lVar12 + 2U) {
                      uVar15 = 0xffffffffffffff0;
                    }
                    *(undefined8 *)(puVar24 + -8) = 0x18003992e;
                    lVar12 = -(uVar15 & 0xfffffffffffffff0);
                    puVar23 = puVar24 + lVar12;
                    puVar22 = puVar24 + lVar12;
                    pOVar18 = (OLECHAR *)(puVar24 + lVar12 + 0x40);
                    if (pOVar18 == (OLECHAR *)0x0) goto LAB_180039964;
                    *(int *)(puVar24 + lVar12 + 0x28) = iVar8;
                    *pOVar18 = L'\0';
                    *(OLECHAR **)(puVar24 + lVar12 + 0x20) = pOVar18;
                    *(undefined8 *)(puVar24 + lVar12 + -8) = 0x180039957;
                    iVar8 = MultiByteToWideChar(0,0,(LPCSTR)pppppppcVar11,-1,
                                                *(LPWSTR *)(puVar24 + lVar12 + 0x20),
                                                *(int *)(puVar24 + lVar12 + 0x28));
                    puVar24 = puVar24 + lVar12;
                    if (iVar8 == 0) {
                      pOVar18 = (OLECHAR *)0x0;
                      puVar24 = puVar22;
                    }
                  }
                  else {
LAB_180039964:
                    pOVar18 = (OLECHAR *)0x0;
                    puVar24 = puVar23;
                  }
                  *(undefined8 *)(puVar24 + -8) = 0x180039971;
                  _Var10 = (_union_1719)SysAllocString(pOVar18);
                  *p_Var26 = _Var10;
                  if (0xf < local_110) {
                    pppppppcVar11 = local_128;
                    if ((0xfff < local_110 + 1) &&
                       (pppppppcVar11 = (char *******)local_128[-1],
                       (char *)0x1f < (char *)((longlong)local_128 + (-8 - (longlong)pppppppcVar11))
                       )) {
                    /* WARNING: Subroutine does not return */
                      *(undefined **)(puVar24 + -8) = &UNK_1800399e9;
                      _invalid_parameter_noinfo_noreturn();
                    }
                    *(undefined8 *)(puVar24 + -8) = 0x1800399b1;
                    FUN_180025ad0(pppppppcVar11);
                  }
                }
                uVar33 = uVar33 + 1;
                p_Var26 = p_Var26 + 3;
                pbVar25 = pbVar17 + 1;
                pbVar13 = pbVar17 + 1;
                if (bVar31 == 0) break;
              }
              pbVar17 = pbVar17 + 1;
              pbVar13 = pbVar17;
              uVar32 = uVar30;
            } while ((int)uVar33 < (int)plVar5[0x2c]);
          }
        }
        plVar5 = local_1d8;
        lVar34 = 5;
        *(longlong ***)(puVar24 + 0x30) = &local_1e8;
        local_1a8 = local_68;
        uStack_1a0 = uStack_60;
        lVar12 = *plVar5;
        local_198 = local_58;
        local_188 = local_80;
        uStack_180 = uStack_78;
        local_178 = local_70;
        *(undefined8 **)(puVar24 + 0x28) = &local_1a8;
        local_168 = local_98;
        uStack_160 = uStack_90;
        *(undefined8 **)(puVar24 + 0x20) = &local_188;
        local_158 = local_88;
        local_148 = local_b0;
        uStack_140 = uStack_a8;
        local_138 = local_a0;
        local_e8._4_4_ = local_c8._4_4_;
        local_e8._0_4_ = local_c8._0_4_;
        _Stack_e0 = (_union_1719)local_c8._8_8_;
        local_d8 = local_c8._16_8_;
        pcVar3 = *(code **)(lVar12 + 0x68);
        *(undefined8 *)(puVar24 + -8) = 0x180039605;
        iVar8 = (*pcVar3)(plVar5,local_e8,&local_148,&local_168);
        p_Var19 = (_union_2707 *)local_c8;
        if (-1 < iVar8) {
          do {
            *(undefined8 *)(puVar24 + -8) = 0x180039c4e;
            VariantClear((VARIANTARG *)&p_Var19->n2);
            pbVar25 = local_200;
            p_Var19 = p_Var19 + 1;
            lVar34 = lVar34 + -1;
          } while (lVar34 != 0);
          *(undefined8 *)(puVar24 + -8) = 0x180039c61;
          operator_delete__(pbVar25);
          pvVar6 = local_1c8;
          *(undefined8 *)(puVar24 + -8) = 0x180039c6a;
          operator_delete__(pvVar6);
          plVar5 = local_1e8;
          if (local_1e8 != (longlong *)0x0) {
            param_1 = local_1e8;
            if (bVar31 != 0) {
              *(undefined8 *)(puVar24 + -8) = 0x180039c92;
              param_1 = FUN_180038fc0(plVar5,pbVar13);
              pcVar3 = *(code **)(*local_1e8 + 0x10);
              *(undefined8 *)(puVar24 + -8) = 0x180039c9f;
              (*pcVar3)();
            }
            pcVar3 = *(code **)(*local_1d8 + 0x10);
            *(undefined8 *)(puVar24 + -8) = 0x180039ca9;
            (*pcVar3)();
            puVar23 = puVar24;
            goto LAB_180039645;
          }
          pcVar3 = *(code **)(*local_1d8 + 0x10);
          *(undefined8 *)(puVar24 + -8) = 0x180039c7d;
          (*pcVar3)();
          puVar21 = puVar24;
          goto LAB_180039643;
        }
        do {
          *(undefined8 *)(puVar24 + -8) = 0x18003961d;
          VariantClear((VARIANTARG *)&p_Var19->n2);
          p_Var19 = p_Var19 + 1;
          lVar34 = lVar34 + -1;
        } while (lVar34 != 0);
        pcVar3 = *(code **)(*local_1d8 + 0x10);
        *(undefined8 *)(puVar24 + -8) = 0x180039631;
        (*pcVar3)();
        puVar23 = puVar24;
      }
      pbVar25 = local_200;
      *(undefined8 *)(puVar23 + -8) = 0x18003963a;
      operator_delete__(pbVar25);
      pvVar6 = local_1c8;
      *(undefined8 *)(puVar23 + -8) = 0x180039643;
      operator_delete__(pvVar6);
      puVar21 = puVar23;
    }
LAB_180039643:
    param_1 = (longlong *)0x0;
    puVar23 = puVar21;
  }
LAB_180039645:
  *(undefined8 *)(puVar23 + -8) = 0x180039654;
  return param_1;
}

