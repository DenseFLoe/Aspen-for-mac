/* RVA 0x10280 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180010280(longlong param_1)

{
  code *pcVar1;
  longlong *plVar2;
  int iVar3;
  LPCSTR lpMultiByteStr;
  longlong lVar4;
  void *pvVar5;
  longlong lVar6;
  uint uVar7;
  ulonglong uVar8;
  void *pvVar9;
  LPWSTR lpWideCharStr;
  undefined2 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  void *pvVar14;
  undefined1 auStackY_f8 [32];
  WCHAR local_b8 [16];
  uint local_98;
  uint local_94;
  longlong *local_90;
  uint local_88;
  uint local_84;
  longlong *local_80;
  int local_78 [2];
  longlong *local_70;
  longlong *local_68;
  longlong *local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  puVar12 = auStackY_f8 + 0x20;
  local_38 = DAT_180052888 ^ (ulonglong)&local_98;
  if (*(longlong *)(param_1 + 8) != 0) {
    local_80 = (longlong *)0x0;
    lpWideCharStr = local_b8;
    if (lpWideCharStr == (LPWSTR)0x0) {
      lpWideCharStr = (LPWSTR)0x0;
    }
    else {
      local_b8[0] = L'\0';
      iVar3 = MultiByteToWideChar(0,0,"PFSVData",-1,lpWideCharStr,9);
      if (iVar3 == 0) {
        lpWideCharStr = (LPWSTR)0x0;
      }
    }
    (**(code **)(**(longlong **)(param_1 + 8) + 0x30))
              (*(longlong **)(param_1 + 8),lpWideCharStr,0,0x12);
    puVar12 = auStackY_f8;
    if (local_80 != (longlong *)0x0) {
      local_60 = (longlong *)0x0;
      (**(code **)(*local_80 + 0x58))(local_80,0,0,0);
      puVar12 = auStackY_f8;
      if (local_60 != (longlong *)0x0) {
        local_90 = (longlong *)0x0;
        (**(code **)(*local_80 + 0x20))(local_80,L"_Contents",0,0x12);
        puVar12 = auStackY_f8;
        if (local_90 != (longlong *)0x0) {
          local_78[0] = 0;
          uStack_50 = 0;
          local_48 = _DAT_180041f70;
          uStack_40 = _UNK_180041f78;
          local_58 = 0;
          iVar3 = (**(code **)(*local_90 + 0x18))(local_90,&local_94,4,&local_98);
          puVar13 = auStackY_f8;
          puVar12 = auStackY_f8;
          if (iVar3 == 0) {
            while (puVar12 = puVar13, local_98 == 4) {
              uVar7 = local_94 + 1;
              *(undefined8 *)(puVar13 + -8) = 0x180010406;
              lpMultiByteStr = operator_new__((ulonglong)uVar7);
              plVar2 = local_90;
              uVar7 = local_94;
              lpMultiByteStr[local_94] = '\0';
              pcVar1 = *(code **)(*local_90 + 0x18);
              *(undefined8 *)(puVar13 + -8) = 0x180010428;
              iVar3 = (*pcVar1)(plVar2,lpMultiByteStr,uVar7,&local_98);
              plVar2 = local_90;
              pvVar14 = (void *)0x0;
              if (iVar3 != 0) {
LAB_1800106ce:
                if (lpMultiByteStr != (LPCSTR)0x0) {
                  *(undefined8 *)(puVar13 + -8) = 0x1800106db;
                  operator_delete__(lpMultiByteStr);
                }
                puVar12 = puVar13;
                if (pvVar14 != (void *)0x0) {
                  *(undefined8 *)(puVar13 + -8) = 0x1800106e8;
                  operator_delete__(pvVar14);
                }
                break;
              }
              if (uVar7 != local_98) {
LAB_1800106cb:
                pvVar14 = (void *)0x0;
                goto LAB_1800106ce;
              }
              pcVar1 = *(code **)(*local_90 + 0x18);
              *(undefined8 *)(puVar13 + -8) = 0x180010454;
              iVar3 = (*pcVar1)(plVar2,&local_94,4,&local_98);
              if (iVar3 != 0) goto LAB_1800106ce;
              if (local_98 != 4) goto LAB_1800106cb;
              uVar7 = local_94 + 1;
              *(undefined8 *)(puVar13 + -8) = 0x180010470;
              pvVar14 = operator_new__((ulonglong)uVar7);
              plVar2 = local_90;
              uVar7 = local_94;
              *(undefined1 *)((ulonglong)local_94 + (longlong)pvVar14) = 0;
              pcVar1 = *(code **)(*local_90 + 0x18);
              *(undefined8 *)(puVar13 + -8) = 0x180010492;
              iVar3 = (*pcVar1)(plVar2,pvVar14,uVar7,&local_98);
              plVar2 = local_90;
              if ((iVar3 != 0) || (uVar7 != local_98)) goto LAB_1800106ce;
              pcVar1 = *(code **)(*local_90 + 0x18);
              *(undefined8 *)(puVar13 + -8) = 0x1800104bb;
              iVar3 = (*pcVar1)(plVar2,local_78,4,&local_98);
              if ((iVar3 != 0) || (local_98 != 4)) goto LAB_1800106ce;
              if (local_78[0] == 2) {
                local_68 = (longlong *)0x0;
                if (lpMultiByteStr == (LPCSTR)0x0) {
LAB_180010552:
                  puVar10 = (undefined2 *)0x0;
                  puVar13 = puVar12;
                }
                else {
                  lVar4 = -1;
                  do {
                    lVar6 = lVar4;
                    lVar4 = lVar6 + 1;
                  } while (lpMultiByteStr[lVar4] != '\0');
                  iVar3 = (int)lVar6 + 2;
                  if (0x3fffffff < iVar3) goto LAB_180010552;
                  lVar4 = (longlong)(int)lVar4 * 2;
                  uVar8 = lVar4 + 0x11;
                  if (uVar8 <= lVar4 + 2U) {
                    uVar8 = 0xffffffffffffff0;
                  }
                  *(undefined8 *)(puVar13 + -8) = 0x18001051d;
                  lVar4 = -(uVar8 & 0xfffffffffffffff0);
                  puVar12 = puVar13 + lVar4;
                  puVar11 = puVar13 + lVar4;
                  puVar10 = (undefined2 *)(puVar13 + lVar4 + 0x40);
                  if (puVar10 == (undefined2 *)0x0) goto LAB_180010552;
                  *puVar10 = 0;
                  *(int *)(puVar13 + lVar4 + 0x28) = iVar3;
                  *(undefined2 **)(puVar13 + lVar4 + 0x20) = puVar10;
                  *(undefined8 *)(puVar13 + lVar4 + -8) = 0x18001054a;
                  iVar3 = MultiByteToWideChar(0,0,lpMultiByteStr,-1,
                                              *(LPWSTR *)(puVar13 + lVar4 + 0x20),
                                              *(int *)(puVar13 + lVar4 + 0x28));
                  puVar13 = puVar13 + lVar4;
                  if (iVar3 == 0) {
                    puVar10 = (undefined2 *)0x0;
                    puVar13 = puVar11;
                  }
                }
                plVar2 = local_80;
                lVar4 = *local_80;
                *(longlong ***)(puVar13 + 0x30) = &local_68;
                *(undefined4 *)(puVar13 + 0x28) = 0;
                *(undefined8 *)(puVar13 + 0x20) = 0;
                pcVar1 = *(code **)(lVar4 + 0x30);
                *(undefined8 *)(puVar13 + -8) = 0x18001057e;
                (*pcVar1)(plVar2,puVar10,0,0x12);
                plVar2 = local_68;
                if (local_68 != (longlong *)0x0) {
                  local_70 = (longlong *)0x0;
                  lVar4 = *local_68;
                  *(longlong ***)(puVar13 + 0x28) = &local_70;
                  *(undefined4 *)(puVar13 + 0x20) = 0;
                  pcVar1 = *(code **)(lVar4 + 0x20);
                  *(undefined8 *)(puVar13 + -8) = 0x1800105b3;
                  (*pcVar1)(plVar2,L"SEVData",0,0x12);
                  plVar2 = local_70;
                  if (local_70 != (longlong *)0x0) {
                    pcVar1 = *(code **)(*local_70 + 0x18);
                    *(undefined8 *)(puVar13 + -8) = 0x1800105d4;
                    iVar3 = (*pcVar1)(plVar2,&local_88,4,&local_84);
                    if (((iVar3 != 0) || (local_84 != 4)) || (local_88 == 0)) {
                      if (local_70 != (longlong *)0x0) {
                        pcVar1 = *(code **)(*local_70 + 0x10);
                        *(undefined8 *)(puVar13 + -8) = 0x1800106b9;
                        (*pcVar1)();
                      }
                      if (local_68 != (longlong *)0x0) {
                        pcVar1 = *(code **)(*local_68 + 0x10);
                        *(undefined8 *)(puVar13 + -8) = 0x1800106c9;
                        (*pcVar1)();
                      }
                      goto LAB_1800106ce;
                    }
                    uVar7 = local_88 + 1;
                    *(undefined8 *)(puVar13 + -8) = 0x1800105f9;
                    pvVar5 = operator_new__((ulonglong)uVar7);
                    plVar2 = local_70;
                    uVar7 = local_88;
                    *(undefined1 *)((ulonglong)local_88 + (longlong)pvVar5) = 0;
                    pcVar1 = *(code **)(*local_70 + 0x18);
                    *(undefined8 *)(puVar13 + -8) = 0x18001061c;
                    iVar3 = (*pcVar1)(plVar2,pvVar5,uVar7,&local_84);
                    if ((iVar3 == 0) && (uVar7 == local_84)) {
                      lVar4 = 0;
                      do {
                        lVar6 = lVar4 + 1;
                        if (*(char *)((longlong)pvVar14 + lVar4) != (&DAT_180041bf8)[lVar4]) {
                          pvVar9 = pvVar14;
                          goto LAB_18001064b;
                        }
                        lVar4 = lVar6;
                      } while (lVar6 != 5);
                      pvVar9 = (void *)0x0;
LAB_18001064b:
                      *(undefined8 *)(puVar13 + -8) = 0x180010653;
                      HAHierSetPFSVData(pvVar9,pvVar5);
                    }
                    *(undefined8 *)(puVar13 + -8) = 0x18001065b;
                    operator_delete__(pvVar5);
                  }
                  if (local_70 != (longlong *)0x0) {
                    pcVar1 = *(code **)(*local_70 + 0x10);
                    *(undefined8 *)(puVar13 + -8) = 0x18001066a;
                    (*pcVar1)();
                  }
                }
                if (local_68 != (longlong *)0x0) {
                  pcVar1 = *(code **)(*local_68 + 0x10);
                  *(undefined8 *)(puVar13 + -8) = 0x180010679;
                  (*pcVar1)();
                }
              }
              *(undefined8 *)(puVar13 + -8) = 0x180010681;
              operator_delete__(lpMultiByteStr);
              *(undefined8 *)(puVar13 + -8) = 0x180010689;
              operator_delete__(pvVar14);
              plVar2 = local_90;
              pcVar1 = *(code **)(*local_90 + 0x18);
              *(undefined8 *)(puVar13 + -8) = 0x1800106a1;
              iVar3 = (*pcVar1)(plVar2,&local_94,4,&local_98);
              puVar12 = puVar13;
              if (iVar3 != 0) break;
            }
          }
        }
        if (local_90 != (longlong *)0x0) {
          pcVar1 = *(code **)(*local_90 + 0x10);
          *(undefined8 *)(puVar12 + -8) = 0x1800106f8;
          (*pcVar1)();
        }
      }
      if (local_60 != (longlong *)0x0) {
        pcVar1 = *(code **)(*local_60 + 0x10);
        *(undefined8 *)(puVar12 + -8) = 0x180010707;
        (*pcVar1)();
      }
    }
    if (local_80 != (longlong *)0x0) {
      pcVar1 = *(code **)(*local_80 + 0x10);
      *(undefined8 *)(puVar12 + -8) = 0x180010716;
      (*pcVar1)();
    }
  }
  *(undefined8 *)(puVar12 + -8) = 0x180010722;
  return;
}

/* RVA 0x10750 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180010750(undefined8 param_1,longlong *param_2)

{
  int iVar1;
  WCHAR *pWVar2;
  undefined1 uStack0000000000000000;
  undefined1 *in_stack_ffffffffffffffa8;
  WCHAR *pWVar3;
  WCHAR local_48 [24];
  longlong *local_18;
  ulonglong local_10;
  
  pWVar2 = local_48;
  pWVar3 = local_48;
  local_10 = DAT_180052888 ^ (ulonglong)&local_18;
  local_18 = (longlong *)0x0;
  if (&uStack0000000000000000 == (undefined1 *)0x48) {
    pWVar2 = (WCHAR *)0x0;
    pWVar3 = (WCHAR *)in_stack_ffffffffffffffa8;
  }
  else {
    local_48[0] = L'\0';
    iVar1 = MultiByteToWideChar(0,0,"SpreadsheetCalculators",-1,local_48,0x17);
    if (iVar1 == 0) {
      pWVar2 = (WCHAR *)0x0;
    }
  }
  iVar1 = (**(code **)(*param_2 + 0x20))
                    (param_2,pWVar2,0,0x12,(ulonglong)pWVar3 & 0xffffffff00000000,&local_18);
  if (-1 < iVar1) {
    ReadSpreadsheetInfoFromStream(local_18);
    (**(code **)(*local_18 + 0x10))();
  }
  return;
}

/* RVA 0x10820 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180010820(IID *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  LPOLESTR pOVar4;
  undefined4 uVar5;
  HRESULT HVar6;
  longlong lVar8;
  longlong lVar7;
  undefined8 uVar9;
  char *_Str1;
  ulonglong uVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  char *_Str2;
  int iVar13;
  undefined8 uVar14;
  undefined8 uStack_90;
  undefined1 auStack_88 [32];
  undefined8 uStack_68;
  int aiStack_60 [2];
  undefined8 local_58 [2];
  int local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  LPOLESTR local_38;
  ulonglong local_30;
  
  local_30 = DAT_180052888 ^ (ulonglong)&local_48;
  uVar14 = 0;
  uStack_90 = 0x180010861;
  uVar5 = FUN_180033bd0();
  uStack_90 = 0x180010869;
  local_40 = FUN_180001520();
  uStack_90 = 0x180010871;
  uStack_44 = FUN_180001530();
  local_38 = (LPCWSTR)0x0;
  uStack_90 = 0x180010885;
  HVar6 = StringFromCLSID(param_1,&local_38);
  pOVar4 = local_38;
  puVar11 = auStack_88;
  puVar12 = auStack_88;
  if ((HVar6 != 0) || (local_38 == (LPCWSTR)0x0)) {
    uVar14 = 0;
    goto LAB_1800109af;
  }
  lVar7 = -1;
  do {
    lVar8 = lVar7;
    lVar7 = lVar8 + 1;
  } while (local_38[lVar7] != L'\0');
  iVar13 = (int)lVar8 + 2;
  if (iVar13 < 0x40000000) {
    lVar7 = (longlong)(int)lVar7 * 2;
    uVar10 = lVar7 + 0x11;
    if (uVar10 <= lVar7 + 2U) {
      uVar10 = 0xffffffffffffff0;
    }
    uStack_90 = 0x1800108e1;
    lVar7 = -(uVar10 & 0xfffffffffffffff0);
    puVar11 = auStack_88 + lVar7;
    _Str2 = (char *)((longlong)local_58 + lVar7 + 0x10);
    if (_Str2 == (char *)0x0) goto LAB_180010927;
    *(undefined8 *)((longlong)local_58 + lVar7 + 8) = 0;
    *(undefined8 *)((longlong)local_58 + lVar7) = 0;
    *(int *)((longlong)aiStack_60 + lVar7) = iVar13 * 2;
    *(char **)(auStack_88 + lVar7 + 0x20) = _Str2;
    *_Str2 = '\0';
    *(undefined8 *)(auStack_88 + lVar7 + -8) = 0x18001091b;
    iVar13 = WideCharToMultiByte(0,0,pOVar4,-1,*(LPSTR *)(auStack_88 + lVar7 + 0x20),
                                 *(int *)((longlong)aiStack_60 + lVar7),
                                 *(LPCSTR *)((longlong)local_58 + lVar7),
                                 *(LPBOOL *)((longlong)local_58 + lVar7 + 8));
    puVar12 = auStack_88 + lVar7;
    if (iVar13 == 0) {
      _Str2 = (char *)0x0;
      puVar12 = auStack_88 + lVar7;
    }
  }
  else {
LAB_180010927:
    _Str2 = (char *)0x0;
    puVar12 = puVar11;
  }
  pOVar4 = local_38;
  *(undefined8 *)(puVar12 + -8) = 0x180010933;
  CoTaskMemFree(pOVar4);
  local_48 = 0;
  *(undefined8 *)(puVar12 + -8) = 0x180010949;
  uVar9 = FUN_1800014d0(&local_48,param_2,param_3,param_4);
  iVar13 = (int)uVar9;
  while (iVar13 != 0) {
    uVar1 = *param_4;
    uVar2 = *param_3;
    uVar3 = *param_2;
    *(undefined8 *)(puVar12 + -8) = 0x18001095e;
    FUN_180001550(uVar3,uVar2,uVar1);
    *(undefined8 *)(puVar12 + -8) = 0x180010963;
    _Str1 = (char *)FUN_180001a20();
    *(undefined8 *)(puVar12 + -8) = 0x18001096b;
    FUN_1800018c0();
    *(undefined8 *)(puVar12 + -8) = 0x180010977;
    iVar13 = _stricmp(_Str1,_Str2);
    if (iVar13 == 0) {
      uVar14 = 1;
      break;
    }
    *(undefined8 *)(puVar12 + -8) = 0x18001098d;
    uVar9 = FUN_1800014d0(&local_48,param_2,param_3,param_4);
    iVar13 = (int)uVar9;
  }
  uVar2 = local_40;
  uVar1 = uStack_44;
  *(undefined8 *)(puVar12 + -8) = 0x1800109a8;
  FUN_180001550(uVar5,uVar2,uVar1);
LAB_1800109af:
  *(undefined8 *)(puVar12 + -8) = 0x1800109bb;
  return uVar14;
}

/* RVA 0x109e0 */
undefined4 FUN_1800109e0(undefined8 param_1)

{
  longlong lVar1;
  LCID LVar2;
  int iVar3;
  longlong *plVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 local_res10 [2];
  wchar_t *local_res18;
  _union_2707 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  _union_2707 local_50;
  VARIANTARG local_38;
  
  plVar4 = (longlong *)FUN_18000cce0();
  if (plVar4 != (longlong *)0x0) {
    local_res18 = L"GetApwzFormat";
    lVar1 = *plVar4;
    LVar2 = GetUserDefaultLCID();
    iVar3 = (**(code **)(lVar1 + 0x28))(plVar4,&DAT_180042ae8,&local_res18,1,LVar2,local_res10);
    if (-1 < iVar3) {
      local_60 = 0;
      local_58 = 1;
      local_68 = &local_50;
      uVar5 = 0;
      do {
        VariantInit((VARIANTARG *)&(&local_50)[uVar5].n2);
        uVar5 = uVar5 + 1;
      } while (uVar5 < (uint)local_58);
      local_50.n2.vt = 0x400b;
      local_50.decVal.u2 = (_union_1719)param_1;
      COleVariant::COleVariant((COleVariant *)&local_38,0,3);
      lVar1 = *plVar4;
      LVar2 = GetUserDefaultLCID();
      iVar3 = (**(code **)(lVar1 + 0x30))
                        (plVar4,local_res10[0],&DAT_180042ae8,LVar2,1,&local_68,&local_38,0,0);
      uVar6 = 0;
      if (-1 < iVar3) {
        uVar6 = local_38.n1._8_4_;
      }
      (**(code **)(*plVar4 + 0x10))(plVar4);
      VariantClear(&local_38);
      return uVar6;
    }
    (**(code **)(*plVar4 + 0x10))(plVar4);
  }
  return 0;
}

/* RVA 0x10b50 */
undefined4 FUN_180010b50(undefined8 param_1)

{
  longlong lVar1;
  LCID LVar2;
  int iVar3;
  longlong *plVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 local_res10 [2];
  wchar_t *local_res18;
  _union_2707 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  _union_2707 local_50;
  VARIANTARG local_38;
  
  plVar4 = (longlong *)FUN_18000cce0();
  if (plVar4 != (longlong *)0x0) {
    local_res18 = L"GetBkpFormat";
    lVar1 = *plVar4;
    LVar2 = GetUserDefaultLCID();
    iVar3 = (**(code **)(lVar1 + 0x28))(plVar4,&DAT_180042ae8,&local_res18,1,LVar2,local_res10);
    if (-1 < iVar3) {
      local_60 = 0;
      local_58 = 1;
      local_68 = &local_50;
      uVar5 = 0;
      do {
        VariantInit((VARIANTARG *)&(&local_50)[uVar5].n2);
        uVar5 = uVar5 + 1;
      } while (uVar5 < (uint)local_58);
      local_50.n2.vt = 0x400b;
      local_50.decVal.u2 = (_union_1719)param_1;
      COleVariant::COleVariant((COleVariant *)&local_38,0,3);
      lVar1 = *plVar4;
      LVar2 = GetUserDefaultLCID();
      iVar3 = (**(code **)(lVar1 + 0x30))
                        (plVar4,local_res10[0],&DAT_180042ae8,LVar2,1,&local_68,&local_38,0,0);
      uVar6 = 0;
      if (-1 < iVar3) {
        uVar6 = local_38.n1._8_4_;
      }
      (**(code **)(*plVar4 + 0x10))(plVar4);
      VariantClear(&local_38);
      return uVar6;
    }
    (**(code **)(*plVar4 + 0x10))(plVar4);
  }
  return 0;
}

/* RVA 0x10cc0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_180010cc0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
             undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined4 param_8,
             undefined4 param_9)

{
  longlong lVar1;
  int iVar2;
  LCID LVar3;
  longlong *plVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined1 auStack_1e8 [32];
  LCID local_1c8;
  _union_2707 **local_1c0;
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
  
  local_38 = DAT_180052888 ^ (ulonglong)auStack_1e8;
  plVar4 = (longlong *)FUN_18000cc10();
  if (plVar4 != (longlong *)0x0) {
    local_190 = L"ShowOpenMessageBox";
    lVar1 = *plVar4;
    local_1c8 = GetUserDefaultLCID();
    local_1c0 = (_union_2707 **)&local_198;
    iVar2 = (**(code **)(lVar1 + 0x28))(plVar4,&DAT_180042ae8,&local_190,1);
    if (-1 < iVar2) {
      local_180 = 0;
      local_178 = 9;
      local_188 = &local_118;
      uVar5 = 0;
      do {
        VariantInit((VARIANTARG *)(local_158 + (ulonglong)uVar5 * 0x18 + 0x40));
        uVar5 = uVar5 + 1;
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
      local_1c0 = &local_188;
      local_1c8 = CONCAT22(local_1c8._2_2_,1);
      iVar2 = (**(code **)(lVar1 + 0x30))(plVar4,local_198,&DAT_180042ae8,LVar3);
      uVar6 = 0;
      if (-1 < iVar2) {
        uVar6 = local_170.n1._8_4_;
      }
      (**(code **)(*plVar4 + 0x10))(plVar4);
      VariantClear(&local_170);
      return uVar6;
    }
    (**(code **)(*plVar4 + 0x10))(plVar4);
  }
  return 0;
}

/* RVA 0x10ec0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined4
FUN_180010ec0(undefined8 *param_1,longlong *param_2,undefined8 *param_3,longlong *param_4)

{
  LPCSTR pCVar1;
  uint *puVar2;
  code *pcVar3;
  LPCWSTR pWVar4;
  char cVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  LCID LVar9;
  longlong *plVar10;
  BSTR pOVar11;
  BSTR pOVar12;
  longlong lVar13;
  longlong lVar14;
  ulonglong uVar15;
  uint uVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  char *pcVar19;
  undefined *puStackY_1e0;
  undefined1 auStackY_1d8 [32];
  VARIANTARG *local_1a8 [4];
  uint local_188 [2];
  longlong local_180;
  longlong local_178;
  undefined4 local_170;
  LPCWSTR local_168;
  LPCWSTR local_160;
  BSTR local_158;
  BSTR local_150;
  undefined1 local_148 [8];
  wchar_t *local_140;
  longlong *local_138;
  undefined1 *local_130;
  undefined8 local_128;
  undefined8 local_120;
  VARIANTARG local_118;
  undefined1 local_f8 [64];
  undefined1 local_b8 [24];
  undefined2 local_a0;
  BSTR local_98;
  undefined2 local_88;
  LPCWSTR *local_80;
  undefined2 local_70;
  BSTR local_68;
  ulonglong local_58;
  
  local_58 = DAT_180052888 ^ (ulonglong)local_188;
  puStackY_1e0 = (undefined *)0x180010efb;
  plVar10 = (longlong *)FUN_18000cce0();
  if (plVar10 != (longlong *)0x0) {
    local_140 = L"ShowACMModelConflictsDialog";
    lVar13 = *plVar10;
    puStackY_1e0 = (undefined *)0x180010f1c;
    local_138 = plVar10;
    GetUserDefaultLCID();
    puStackY_1e0 = (undefined *)0x180010f40;
    iVar6 = (**(code **)(lVar13 + 0x28))(plVar10,&DAT_180042ae8,&local_140,1);
    puVar18 = auStackY_1d8;
    if (-1 < iVar6) {
      local_128 = 0;
      local_120 = 4;
      local_130 = local_b8;
      uVar16 = 0;
      do {
        puStackY_1e0 = (undefined *)0x180010f87;
        VariantInit((VARIANTARG *)(local_b8 + (ulonglong)uVar16 * 0x18));
        uVar16 = uVar16 + 1;
      } while (uVar16 < (uint)local_120);
      pCVar1 = (LPCSTR)*param_1;
      if (pCVar1 == (LPCSTR)0x0) {
        local_158 = (BSTR)0x0;
      }
      else {
        puStackY_1e0 = (undefined *)0x180010fb2;
        iVar6 = MultiByteToWideChar(0,0,pCVar1,-1,(LPWSTR)0x0,0);
        puStackY_1e0 = (undefined *)0x180010fbf;
        pOVar11 = SysAllocStringLen((OLECHAR *)0x0,iVar6 - 1);
        if (pOVar11 != (BSTR)0x0) {
          puStackY_1e0 = (undefined *)0x180010fe3;
          iVar8 = MultiByteToWideChar(0,0,pCVar1,-1,pOVar11,iVar6);
          if (iVar8 != iVar6) {
            puStackY_1e0 = (undefined *)0x1800113e4;
            SysFreeString(pOVar11);
            goto LAB_1800113e4;
          }
        }
        local_158 = pOVar11;
        if (pOVar11 == (BSTR)0x0) {
LAB_1800113e4:
                    /* WARNING: Subroutine does not return */
          puStackY_1e0 = (undefined *)0x1800113ee;
          FUN_1800018d0(-0x7ff8fff2);
        }
      }
      pOVar11 = local_158;
      pCVar1 = (LPCSTR)*param_3;
      if (pCVar1 == (LPCSTR)0x0) {
        local_150 = (BSTR)0x0;
      }
      else {
        puStackY_1e0 = (undefined *)0x18001102a;
        iVar6 = MultiByteToWideChar(0,0,pCVar1,-1,(LPWSTR)0x0,0);
        puStackY_1e0 = (undefined *)0x180011038;
        pOVar12 = SysAllocStringLen((OLECHAR *)0x0,iVar6 - 1);
        if (pOVar12 != (BSTR)0x0) {
          puStackY_1e0 = (undefined *)0x18001105d;
          iVar8 = MultiByteToWideChar(0,0,pCVar1,-1,pOVar12,iVar6);
          if (iVar8 != iVar6) {
            puStackY_1e0 = (undefined *)0x1800113f8;
            SysFreeString(pOVar12);
            goto LAB_1800113f8;
          }
        }
        local_150 = pOVar12;
        if (pOVar12 == (BSTR)0x0) {
LAB_1800113f8:
                    /* WARNING: Subroutine does not return */
          puStackY_1e0 = &UNK_180011402;
          FUN_1800018d0(-0x7ff8fff2);
        }
      }
      pOVar12 = local_150;
      local_70 = 8;
      local_160 = (LPCWSTR)0x0;
      local_88 = 0x4008;
      local_80 = &local_160;
      local_a0 = 8;
      local_168 = (LPCWSTR)0x0;
      local_b8._0_2_ = 0x4008;
      local_b8._8_8_ = &local_168;
      puStackY_1e0 = (undefined *)0x1800110da;
      local_98 = local_150;
      local_68 = pOVar11;
      COleVariant::COleVariant((COleVariant *)&local_118,0,3);
      lVar13 = *plVar10;
      puStackY_1e0 = (undefined *)0x1800110e5;
      LVar9 = GetUserDefaultLCID();
      local_1a8[2] = (VARIANTARG *)local_148;
      local_1a8[1] = (VARIANTARG *)local_f8;
      local_1a8[0] = &local_118;
      puStackY_1e0 = (undefined *)0x180011126;
      iVar6 = (**(code **)(lVar13 + 0x30))(plVar10,local_170,&DAT_180042ae8,LVar9);
      pWVar4 = local_160;
      uVar7 = 0;
      if (-1 < iVar6) {
        puVar18 = auStackY_1d8;
        if (local_160 == (LPCWSTR)0x0) {
LAB_1800111d7:
          pcVar19 = (char *)0x0;
          puVar17 = puVar18;
        }
        else {
          lVar13 = -1;
          do {
            lVar14 = lVar13;
            lVar13 = lVar14 + 1;
          } while (local_160[lVar13] != L'\0');
          iVar6 = (int)lVar14 + 2;
          puVar18 = auStackY_1d8;
          if (0x3fffffff < iVar6) goto LAB_1800111d7;
          lVar13 = (longlong)(int)lVar13 * 2;
          uVar15 = lVar13 + 0x11;
          if (uVar15 <= lVar13 + 2U) {
            uVar15 = 0xffffffffffffff0;
          }
          puStackY_1e0 = (undefined *)0x180011188;
          lVar13 = -(uVar15 & 0xfffffffffffffff0);
          puVar18 = auStackY_1d8 + lVar13;
          pcVar19 = (char *)((longlong)local_188 + lVar13);
          if (pcVar19 == (char *)0x0) goto LAB_1800111d7;
          *pcVar19 = '\0';
          *(undefined8 *)((longlong)local_1a8 + lVar13 + 8) = 0;
          *(undefined8 *)((longlong)local_1a8 + lVar13) = 0;
          *(int *)((longlong)local_1a8 + lVar13 + -8) = iVar6 * 2;
          *(char **)(auStackY_1d8 + lVar13 + 0x20) = pcVar19;
          *(undefined8 *)(auStackY_1d8 + lVar13 + -8) = 0x1800111c0;
          iVar6 = WideCharToMultiByte(0,0,pWVar4,-1,*(LPSTR *)(auStackY_1d8 + lVar13 + 0x20),
                                      *(int *)((longlong)local_1a8 + lVar13 + -8),
                                      *(LPCSTR *)((longlong)local_1a8 + lVar13),
                                      *(LPBOOL *)((longlong)local_1a8 + lVar13 + 8));
          puVar17 = auStackY_1d8 + lVar13;
          if (iVar6 == 0) {
            pcVar19 = (char *)0x0;
            puVar17 = auStackY_1d8 + lVar13;
          }
        }
        *(undefined8 *)(puVar17 + -8) = 0x1800111e8;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_178,
                   pcVar19);
        iVar6 = *(int *)(local_178 + -0x10);
        if ((iVar6 != 0) && (iVar8 = 0, 0 < iVar6)) {
          do {
            *(undefined8 *)(puVar17 + -8) = 0x18001120c;
            cVar5 = ATL::CSimpleStringT<char,1>::operator[]
                              ((CSimpleStringT<char,1> *)&local_178,iVar8);
            if (cVar5 != ',') {
              *(undefined8 *)(puVar17 + -8) = 0x18001121c;
              cVar5 = ATL::CSimpleStringT<char,1>::operator[]
                                ((CSimpleStringT<char,1> *)&local_178,iVar8);
              local_188[0] = (uint)(cVar5 == '1');
              puVar2 = (uint *)param_2[1];
              if (puVar2 == (uint *)param_2[2]) {
                *(undefined8 *)(puVar17 + -8) = 0x180011245;
                FUN_1800072c0(param_2,puVar2,local_188);
              }
              else {
                *puVar2 = (uint)(cVar5 == '1');
                param_2[1] = param_2[1] + 4;
              }
            }
            iVar8 = iVar8 + 1;
          } while (iVar8 < iVar6);
        }
        pWVar4 = local_168;
        puVar18 = puVar17;
        if (local_168 == (LPCWSTR)0x0) {
LAB_1800112df:
          pcVar19 = (char *)0x0;
        }
        else {
          lVar13 = -1;
          do {
            lVar14 = lVar13;
            lVar13 = lVar14 + 1;
          } while (local_168[lVar13] != L'\0');
          iVar6 = (int)lVar14 + 2;
          if (0x3fffffff < iVar6) goto LAB_1800112df;
          lVar13 = (longlong)(int)lVar13 * 2;
          uVar15 = lVar13 + 0x11;
          if (uVar15 <= lVar13 + 2U) {
            uVar15 = 0xffffffffffffff0;
          }
          *(undefined8 *)(puVar17 + -8) = 0x18001129f;
          lVar13 = -(uVar15 & 0xfffffffffffffff0);
          puVar18 = puVar17 + lVar13;
          pcVar19 = puVar17 + lVar13 + 0x50;
          if (pcVar19 == (char *)0x0) goto LAB_1800112df;
          *pcVar19 = '\0';
          *(undefined8 *)(puVar17 + lVar13 + 0x38) = 0;
          *(undefined8 *)(puVar17 + lVar13 + 0x30) = 0;
          *(int *)(puVar17 + lVar13 + 0x28) = iVar6 * 2;
          *(char **)(puVar17 + lVar13 + 0x20) = pcVar19;
          *(undefined8 *)(puVar17 + lVar13 + -8) = 0x1800112d7;
          iVar6 = WideCharToMultiByte(0,0,pWVar4,-1,*(LPSTR *)(puVar17 + lVar13 + 0x20),
                                      *(int *)(puVar17 + lVar13 + 0x28),
                                      *(LPCSTR *)(puVar17 + lVar13 + 0x30),
                                      *(LPBOOL *)(puVar17 + lVar13 + 0x38));
          puVar18 = puVar17 + lVar13;
          if (iVar6 == 0) {
            puVar18 = puVar17 + lVar13;
            pcVar19 = (char *)0x0;
          }
        }
        iVar8 = 0;
        *(undefined8 *)(puVar18 + -8) = 0x1800112f2;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_180,
                   pcVar19);
        iVar6 = *(int *)(local_180 + -0x10);
        if ((iVar6 != 0) && (0 < iVar6)) {
          do {
            *(undefined8 *)(puVar18 + -8) = 0x18001131c;
            cVar5 = ATL::CSimpleStringT<char,1>::operator[]
                              ((CSimpleStringT<char,1> *)&local_180,iVar8);
            if (cVar5 != ',') {
              *(undefined8 *)(puVar18 + -8) = 0x18001132c;
              cVar5 = ATL::CSimpleStringT<char,1>::operator[]
                                ((CSimpleStringT<char,1> *)&local_180,iVar8);
              local_188[0] = (uint)(cVar5 == '1');
              puVar2 = (uint *)param_4[1];
              if (puVar2 == (uint *)param_4[2]) {
                *(undefined8 *)(puVar18 + -8) = 0x180011356;
                FUN_1800072c0(param_4,puVar2,local_188);
              }
              else {
                *puVar2 = local_188[0];
                param_4[1] = param_4[1] + 4;
              }
            }
            iVar8 = iVar8 + 1;
          } while (iVar8 < iVar6);
        }
        *(undefined8 *)(puVar18 + -8) = 0x180011367;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_180);
        *(undefined8 *)(puVar18 + -8) = 0x180011372;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_178);
        plVar10 = local_138;
        uVar7 = local_118.n1._8_4_;
      }
      pcVar3 = *(code **)(*plVar10 + 0x10);
      *(undefined8 *)(puVar18 + -8) = 0x180011380;
      (*pcVar3)(plVar10);
      *(undefined8 *)(puVar18 + -8) = 0x18001138b;
      VariantClear(&local_118);
      pWVar4 = local_168;
      *(undefined8 *)(puVar18 + -8) = 0x180011396;
      SysFreeString(pWVar4);
      pWVar4 = local_160;
      *(undefined8 *)(puVar18 + -8) = 0x1800113a1;
      SysFreeString(pWVar4);
      *(undefined8 *)(puVar18 + -8) = 0x1800113ab;
      SysFreeString(pOVar12);
      *(undefined8 *)(puVar18 + -8) = 0x1800113b5;
      SysFreeString(pOVar11);
      goto LAB_1800113b8;
    }
    puStackY_1e0 = (undefined *)0x180010f4e;
    (**(code **)(*plVar10 + 0x10))(plVar10);
  }
  puVar18 = auStackY_1d8;
  uVar7 = 0;
LAB_1800113b8:
  *(undefined8 *)(puVar18 + -8) = 0x1800113c7;
  return uVar7;
}

/* RVA 0x11410 */
undefined4 FUN_180011410(LPCSTR param_1)

{
  longlong lVar1;
  LCID LVar2;
  int iVar3;
  int iVar4;
  longlong *plVar5;
  BSTR pOVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 local_res10 [2];
  BSTR local_res18;
  wchar_t *local_res20;
  undefined8 in_stack_ffffffffffffff58;
  undefined2 *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined1 local_60 [24];
  VARIANTARG local_48;
  
  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffff58 >> 0x20);
  plVar5 = (longlong *)FUN_18000cce0();
  if (plVar5 != (longlong *)0x0) {
    local_res20 = L"ShowDialog";
    lVar1 = *plVar5;
    LVar2 = GetUserDefaultLCID();
    iVar3 = (**(code **)(lVar1 + 0x28))
                      (plVar5,&DAT_180042ae8,&local_res20,1,CONCAT44(uVar8,LVar2),local_res10);
    if (-1 < iVar3) {
      local_70 = 0;
      local_68 = 1;
      local_78 = (undefined2 *)local_60;
      uVar7 = 0;
      do {
        VariantInit((VARIANTARG *)(local_60 + (ulonglong)uVar7 * 0x18));
        uVar7 = uVar7 + 1;
      } while (uVar7 < (uint)local_68);
      if (param_1 == (LPCSTR)0x0) {
        local_res18 = (BSTR)0x0;
LAB_180011545:
        pOVar6 = local_res18;
        local_60._0_2_ = 8;
        local_60._8_8_ = local_res18;
        COleVariant::COleVariant((COleVariant *)&local_48,0,3);
        lVar1 = *plVar5;
        LVar2 = GetUserDefaultLCID();
        iVar3 = (**(code **)(lVar1 + 0x30))
                          (plVar5,local_res10[0],&DAT_180042ae8,LVar2,1,&local_78,&local_48,0,0);
        uVar8 = 0;
        if (-1 < iVar3) {
          uVar8 = local_48.n1._8_4_;
        }
        (**(code **)(*plVar5 + 0x10))(plVar5);
        VariantClear(&local_48);
        SysFreeString(pOVar6);
        return uVar8;
      }
      iVar3 = MultiByteToWideChar(0,0,param_1,-1,(LPWSTR)0x0,0);
      pOVar6 = SysAllocStringLen((OLECHAR *)0x0,iVar3 - 1);
      if ((pOVar6 == (BSTR)0x0) ||
         (iVar4 = MultiByteToWideChar(0,0,param_1,-1,pOVar6,iVar3), iVar4 == iVar3)) {
        local_res18 = pOVar6;
        if (pOVar6 != (BSTR)0x0) goto LAB_180011545;
      }
      else {
        SysFreeString(pOVar6);
      }
                    /* WARNING: Subroutine does not return */
      FUN_1800018d0(-0x7ff8fff2);
    }
    (**(code **)(*plVar5 + 0x10))(plVar5);
  }
  return 0;
}

/* RVA 0x11610 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180011610(longlong *param_1)

{
  undefined1 auStack_438 [32];
  undefined8 local_418 [2];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_180052888 ^ (ulonglong)auStack_438;
  if (*param_1 == 0) {
    FUN_180001ce0(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\ApwnShellIP\\ApwnLWDocument.cpp",0x9b);
    LogMessage(local_408,2,1);
  }
  local_418[0] = 0;
  (**(code **)(*(longlong *)*param_1 + 200))((longlong *)*param_1,local_418);
  return local_418[0];
}

/* RVA 0x116a0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_1800116a0(undefined8 *param_1,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2)

{
  _union_2707 *pvarg;
  longlong lVar1;
  undefined1 auStack_198 [32];
  undefined8 *local_178;
  undefined8 *local_170;
  undefined8 *local_168;
  undefined8 local_158 [2];
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined4 local_c8;
  ULONG UStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined8 local_b8;
  _union_2707 local_a8;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_28;
  
  local_28 = DAT_180052888 ^ (ulonglong)auStack_198;
  local_158[0] = 0;
  pvarg = &local_a8;
  lVar1 = 5;
  do {
    VariantInit((VARIANTARG *)&pvarg->n2);
    pvarg = pvarg + 1;
    lVar1 = lVar1 + -1;
  } while (lVar1 != 0);
  local_a8.n2.vt = 8;
  local_a8.decVal.u2 =
       (_union_1719)
       ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::AllocSysString(param_2);
  local_168 = local_158;
  local_170 = &local_148;
  local_148 = local_48;
  uStack_140 = uStack_40;
  local_178 = &local_128;
  local_138 = local_38;
  local_128 = local_60;
  uStack_120 = uStack_58;
  local_118 = local_50;
  local_108 = local_78;
  uStack_100 = uStack_70;
  local_f8 = local_68;
  local_e8 = local_90;
  uStack_e0 = uStack_88;
  local_d8 = local_80;
  local_c8 = local_a8._0_4_;
  UStack_c4 = local_a8.decVal.Hi32;
  uStack_c0 = local_a8._8_4_;
  uStack_bc = local_a8._12_4_;
  local_b8 = local_a8._16_8_;
  (**(code **)(*(longlong *)*param_1 + 0x68))((longlong *)*param_1,&local_c8,&local_e8,&local_108);
  VariantClear((VARIANTARG *)&local_a8.n2);
  return local_158[0];
}

/* RVA 0x117d0 */
void FUN_1800117d0(longlong *param_1,COleVariant *param_2)

{
  tagVARIANT *ptVar1;
  _union_2707 local_98;
  _union_2707 local_78;
  undefined8 local_58;
  _struct_1720 _Stack_50;
  IRecordInfo *local_48;
  _union_2707 local_38;
  VARIANTARG local_20;
  
  if (*param_1 != 0) {
    VariantInit((VARIANTARG *)&local_78.n2);
    COleVariant::COleVariant((COleVariant *)&local_20,param_2);
    ptVar1 = COleVariant::Detach((COleVariant *)&local_20,(tagVARIANT *)&local_98.n2);
    local_38._0_2_ = (ptVar1->n1).n2.vt;
    local_38._2_2_ = (ptVar1->n1).n2.wReserved1;
    local_38._4_2_ = (ptVar1->n1).n2.wReserved2;
    local_38._6_2_ = (ptVar1->n1).n2.wReserved3;
    local_38.decVal.u2 = (_union_1719)*(_union_1719 *)&(ptVar1->n1).decVal.u2.s2;
    local_38._16_8_ = (ptVar1->n1).n2.n3.brecVal.pRecInfo;
    local_58._0_2_ = (ptVar1->n1).n2.vt;
    local_58._2_2_ = (ptVar1->n1).n2.wReserved1;
    local_58._4_2_ = (ptVar1->n1).n2.wReserved2;
    local_58._6_2_ = (ptVar1->n1).n2.wReserved3;
    _Stack_50 = (ptVar1->n1).decVal.u2.s2;
    local_48 = (ptVar1->n1).n2.n3.brecVal.pRecInfo;
    local_98._0_4_ = local_78._0_4_;
    local_98.decVal.Hi32 = local_78.decVal.Hi32;
    local_98._8_4_ = local_78._8_4_;
    local_98._12_4_ = local_78._12_4_;
    local_98._16_8_ = local_78._16_8_;
    (**(code **)(*(longlong *)*param_1 + 0xa0))((longlong *)*param_1,0,&local_98,&local_58);
    VariantClear((VARIANTARG *)&local_38.n2);
    VariantClear(&local_20);
  }
  return;
}

/* RVA 0x118b0 */
undefined8 FUN_1800118b0(longlong param_1)

{
  longlong *plVar1;
  undefined8 uVar2;
  undefined8 extraout_RAX;
  
  FreeGlobalBlockUsage();
  uVar2 = FreeGlobalApwnLib();
  if (*(longlong *)(param_1 + 0xb0) != 0) {
    SetGlobalPointer("ApwnOleServerDoc",0,0);
    DeleteApwnContextDocument(*(void **)(param_1 + 0xb0));
    *(undefined8 *)(param_1 + 0xb0) = 0;
    uVar2 = extraout_RAX;
  }
  if (*(longlong *)(param_1 + 8) != 0) {
    SetGlobalPointer("ApwnDocStorage",0,0);
    uVar2 = STclsstg(*(undefined8 *)(param_1 + 8));
    plVar1 = *(longlong **)(param_1 + 8);
    if (plVar1 != (longlong *)0x0) {
      *(undefined8 *)(param_1 + 8) = 0;
      uVar2 = (**(code **)(*plVar1 + 0x10))();
    }
  }
  plVar1 = *(longlong **)(param_1 + 0x18);
  if (plVar1 != (longlong *)0x0) {
    *(undefined8 *)(param_1 + 0x18) = 0;
    uVar2 = (**(code **)(*plVar1 + 0x10))();
  }
  plVar1 = *(longlong **)(param_1 + 0x30);
  if (plVar1 != (longlong *)0x0) {
    *(undefined8 *)(param_1 + 0x30) = 0;
    uVar2 = (**(code **)(*plVar1 + 0x10))();
  }
  plVar1 = *(longlong **)(param_1 + 0x20);
  if (plVar1 != (longlong *)0x0) {
    *(undefined8 *)(param_1 + 0x20) = 0;
    uVar2 = (**(code **)(*plVar1 + 0x10))();
  }
  plVar1 = *(longlong **)(param_1 + 0x28);
  if (plVar1 != (longlong *)0x0) {
    *(undefined8 *)(param_1 + 0x28) = 0;
    uVar2 = (**(code **)(*plVar1 + 0x10))();
  }
  plVar1 = *(longlong **)(param_1 + 0x38);
  if (plVar1 != (longlong *)0x0) {
    *(undefined8 *)(param_1 + 0x38) = 0;
    uVar2 = (**(code **)(*plVar1 + 0x10))();
  }
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}

/* RVA 0x119a0 */
ulonglong FUN_1800119a0(longlong param_1,char *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar4;
  longlong *plVar5;
  undefined4 extraout_var;
  longlong *local_res10;
  longlong *local_res20;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_a8 [8];
  tagVARIANT local_a0;
  VARIANTARG local_88;
  _union_2707 local_70;
  undefined4 local_58;
  ULONG UStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 local_48;
  VARIANTARG local_38;
  
  if ((((param_3 != 1) && (param_3 != 0xf)) ||
      (pcVar3 = strrchr(param_2,0x2e), pcVar3 == (char *)0x0)) ||
     (iVar1 = _strnicmp(pcVar3 + 1,"apr",3), iVar1 != 0)) {
    uVar2 = FUN_18000be70(param_1,param_2,param_3);
    return CONCAT71((int7)(CONCAT44(extraout_var,uVar2) >> 8),uVar2 != 0);
  }
  local_res20 = (longlong *)HappGetTree();
  pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
           CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                     (local_a8,"Data\\Setup\\Main\\Input\\RUN_CLASS");
  plVar5 = (longlong *)FUN_180021b30((longlong *)&local_res20,pCVar4);
  local_res10 = plVar5;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_a8);
  AfxVariantInit(&local_a0);
  VariantClear(&local_a0);
  if (plVar5 != (longlong *)0x0) {
    VariantInit((VARIANTARG *)&local_70.n2);
    VariantInit(&local_88);
    local_58 = local_70._0_4_;
    UStack_54 = local_70.decVal.Hi32;
    uStack_50 = local_70._8_4_;
    uStack_4c = local_70._12_4_;
    local_48 = local_70._16_8_;
    iVar1 = (**(code **)(*plVar5 + 0x98))(plVar5,0,&local_58,&local_88);
    if (-1 < iVar1) {
      COleVariant::operator=((COleVariant *)&local_a0,&local_88);
      VariantClear(&local_88);
    }
  }
  COleVariant::COleVariant((COleVariant *)&local_38,"PROP",8);
  FUN_1800117d0((longlong *)&local_res10,(COleVariant *)&local_38);
  SetExportToApropFlag(1);
  uVar2 = FUN_18000be70(param_1,param_2,param_3);
  FUN_1800117d0((longlong *)&local_res10,(COleVariant *)&local_a0);
  if (plVar5 != (longlong *)0x0) {
    (**(code **)(*plVar5 + 0x10))(plVar5);
  }
  (**(code **)(*local_res20 + 0x10))();
  VariantClear(&local_38);
  VariantClear(&local_a0);
  return (ulonglong)(uVar2 != 0);
}

/* RVA 0x11b60 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180011b60(longlong param_1,BSTR param_2)

{
  char cVar1;
  char cVar2;
  code *pcVar3;
  longlong lVar4;
  ulonglong uVar5;
  UINT UVar6;
  uint uVar7;
  int iVar8;
  longlong *plVar9;
  void *pvVar10;
  char *pcVar11;
  char *pcVar12;
  longlong *plVar13;
  undefined8 ****ppppuVar14;
  undefined8 ****ppppuVar15;
  LPCSTR ***ppppCVar16;
  longlong *plVar17;
  longlong *plVar18;
  LPWSTR lpWideCharStr;
  undefined1 *puVar19;
  size_t sVar20;
  ulonglong uVar21;
  ulonglong uVar22;
  size_t sVar23;
  ulonglong uVar24;
  undefined1 auStackY_2c8 [24];
  undefined8 uStackY_2b0;
  WCHAR local_288 [16];
  longlong local_268;
  longlong *local_260;
  longlong *local_258 [2];
  longlong *local_248;
  longlong *local_240;
  longlong local_238;
  longlong lStack_230;
  undefined8 ****local_228;
  undefined8 uStack_220;
  ulonglong local_218;
  ulonglong local_210;
  LPCSTR ***local_208;
  undefined8 uStack_200;
  longlong local_1f8;
  ulonglong local_1f0;
  undefined1 *local_1e8;
  undefined1 local_1e0 [136];
  undefined1 *local_158;
  undefined1 local_150 [264];
  ulonglong local_48;
  
  local_48 = DAT_180052888 ^ (ulonglong)&local_268;
  uStackY_2b0 = 0x180011b9f;
  local_268 = param_1;
  FUN_1800093c0(param_1,param_2);
  uStack_220 = 0;
  local_218 = 0;
  local_210 = 0xf;
  local_228 = (undefined8 ****)0x0;
  sVar23 = 0xffffffffffffffff;
  if (param_2 == (BSTR)0x0) {
LAB_180011c33:
    local_218 = 4;
    local_228 = (undefined8 ****)CONCAT35(local_228._5_3_,0x746f6f52);
  }
  else {
    uStackY_2b0 = 0x180011bcf;
    UVar6 = SysStringLen(param_2);
    if (UVar6 == 0) goto LAB_180011c33;
    local_1e8 = local_1e0;
    uStackY_2b0 = 0x180011bf3;
    FUN_18000d880(&local_1e8,param_2,0);
    sVar20 = 0xffffffffffffffff;
    do {
      sVar20 = sVar20 + 1;
    } while (local_1e8[sVar20] != '\0');
    uStackY_2b0 = 0x180011c13;
    FUN_18001d350((longlong *)&local_228,local_1e8,sVar20);
    if (local_1e8 != local_1e0) {
      uStackY_2b0 = 0x180011c2d;
      free(local_1e8);
    }
  }
  uVar24 = local_210;
  uVar5 = local_218;
  ppppuVar14 = local_228;
  local_248 = (longlong *)(param_1 + 0xd0);
  plVar9 = (longlong *)*local_248;
  plVar17 = (longlong *)plVar9[1];
  local_258[0] = plVar9;
  if (*(char *)((longlong)plVar17 + 0x19) == '\0') {
    do {
      ppppuVar15 = &local_228;
      if (0xf < uVar24) {
        ppppuVar15 = ppppuVar14;
      }
      plVar13 = plVar17 + 4;
      if (0xf < (ulonglong)plVar17[7]) {
        plVar13 = (longlong *)plVar17[4];
      }
      uVar22 = plVar17[6];
      uVar21 = uVar22;
      if (uVar5 < uVar22) {
        uVar21 = uVar5;
      }
      uStackY_2b0 = 0x180011cae;
      uVar7 = memcmp(plVar13,ppppuVar15,uVar21);
      if (uVar7 == 0) {
        if (uVar22 < uVar5) {
          uVar7 = 0xffffffff;
        }
        else {
          uVar7 = (uint)(uVar5 < uVar22);
        }
      }
      if ((int)uVar7 < 0) {
        plVar13 = (longlong *)plVar17[2];
      }
      else {
        plVar13 = (longlong *)*plVar17;
        plVar9 = plVar17;
      }
      plVar17 = plVar13;
    } while (*(char *)((longlong)plVar13 + 0x19) == '\0');
    plVar17 = (longlong *)local_258[0][1];
  }
  uVar24 = local_210;
  plVar13 = local_258[0];
  if (*(char *)((longlong)plVar9 + 0x19) == '\0') {
    plVar18 = plVar9 + 4;
    if (0xf < (ulonglong)plVar9[7]) {
      plVar18 = (longlong *)plVar9[4];
    }
    ppppuVar14 = &local_228;
    if (0xf < local_210) {
      ppppuVar14 = local_228;
    }
    uVar22 = plVar9[6];
    uVar21 = uVar5;
    if (uVar22 < uVar5) {
      uVar21 = uVar22;
    }
    uStackY_2b0 = 0x180011d26;
    uVar7 = memcmp(ppppuVar14,plVar18,uVar21);
    uVar21 = local_210;
    ppppuVar14 = local_228;
    if (uVar7 == 0) {
      if (uVar5 < uVar22) {
        uVar7 = 0xffffffff;
      }
      else {
        uVar7 = (uint)(uVar22 < uVar5);
      }
    }
    if (((int)uVar7 < 0) || (plVar9 == plVar13)) goto LAB_180012109;
    plVar9 = plVar13;
    if (*(char *)((longlong)plVar17 + 0x19) == (char)-(char)((int)uVar7 >> 0x1f)) {
      do {
        ppppuVar15 = &local_228;
        if (0xf < uVar21) {
          ppppuVar15 = ppppuVar14;
        }
        plVar9 = plVar17 + 4;
        if (0xf < (ulonglong)plVar17[7]) {
          plVar9 = (longlong *)plVar17[4];
        }
        uVar24 = plVar17[6];
        uVar22 = uVar24;
        if (uVar5 < uVar24) {
          uVar22 = uVar5;
        }
        uStackY_2b0 = 0x180011d9e;
        uVar7 = memcmp(plVar9,ppppuVar15,uVar22);
        if (uVar7 == 0) {
          if (uVar24 < uVar5) {
            uVar7 = 0xffffffff;
          }
          else {
            uVar7 = (uint)(uVar5 < uVar24);
          }
        }
        if ((int)uVar7 < 0) {
          plVar9 = (longlong *)plVar17[2];
        }
        else {
          plVar9 = (longlong *)*plVar17;
          plVar13 = plVar17;
        }
        plVar17 = plVar9;
      } while (*(char *)((longlong)plVar9 + 0x19) == '\0');
      plVar17 = (longlong *)local_258[0][1];
      plVar9 = local_258[0];
      uVar24 = local_210;
    }
    if (*(char *)((longlong)plVar13 + 0x19) == '\0') {
      plVar18 = plVar13 + 4;
      if (0xf < (ulonglong)plVar13[7]) {
        plVar18 = (longlong *)plVar13[4];
      }
      ppppuVar14 = &local_228;
      if (0xf < uVar24) {
        ppppuVar14 = local_228;
      }
      uVar24 = plVar13[6];
      uVar22 = uVar5;
      if (uVar24 < uVar5) {
        uVar22 = uVar24;
      }
      uStackY_2b0 = 0x180011e0f;
      uVar7 = memcmp(ppppuVar14,plVar18,uVar22);
      if (uVar7 == 0) {
        if (uVar5 < uVar24) {
          uVar7 = 0xffffffff;
        }
        else {
          uVar7 = (uint)(uVar24 < uVar5);
        }
      }
      if ((int)uVar7 < 0) goto LAB_180011e2c;
    }
    else {
LAB_180011e2c:
      plVar13 = plVar9;
    }
    uVar24 = local_210;
    ppppuVar14 = local_228;
    if (plVar13[9] != 0) {
      plVar13 = plVar9;
      if (*(char *)((longlong)plVar17 + 0x19) == '\0') {
        do {
          ppppuVar15 = &local_228;
          if (0xf < uVar24) {
            ppppuVar15 = ppppuVar14;
          }
          plVar13 = plVar17 + 4;
          if (0xf < (ulonglong)plVar17[7]) {
            plVar13 = (longlong *)plVar17[4];
          }
          uVar22 = plVar17[6];
          uVar21 = uVar22;
          if (uVar5 < uVar22) {
            uVar21 = uVar5;
          }
          uStackY_2b0 = 0x180011e7e;
          uVar7 = memcmp(plVar13,ppppuVar15,uVar21);
          if (uVar7 == 0) {
            if (uVar22 < uVar5) {
              uVar7 = 0xffffffff;
            }
            else {
              uVar7 = (uint)(uVar5 < uVar22);
            }
          }
          if ((int)uVar7 < 0) {
            plVar13 = (longlong *)plVar17[2];
          }
          else {
            plVar13 = (longlong *)*plVar17;
            plVar9 = plVar17;
          }
          plVar17 = plVar13;
        } while (*(char *)((longlong)plVar13 + 0x19) == '\0');
        plVar13 = local_258[0];
      }
      if (*(char *)((longlong)plVar9 + 0x19) == '\0') {
        plVar17 = plVar9 + 4;
        if (0xf < (ulonglong)plVar9[7]) {
          plVar17 = (longlong *)plVar9[4];
        }
        ppppuVar14 = &local_228;
        if (0xf < uVar24) {
          ppppuVar14 = local_228;
        }
        uVar24 = plVar9[6];
        uVar22 = uVar5;
        if (uVar24 < uVar5) {
          uVar22 = uVar24;
        }
        uStackY_2b0 = 0x180011ee8;
        uVar7 = memcmp(ppppuVar14,plVar17,uVar22);
        if (uVar7 == 0) {
          if (uVar5 < uVar24) {
            uVar7 = 0xffffffff;
          }
          else {
            uVar7 = (uint)(uVar24 < uVar5);
          }
        }
        if ((int)uVar7 < 0) goto LAB_180011f05;
      }
      else {
LAB_180011f05:
        plVar9 = plVar13;
      }
      uStackY_2b0 = 0x180011f12;
      (**(code **)(*(longlong *)plVar9[9] + 0x10))();
    }
    uVar24 = local_210;
    ppppuVar14 = local_228;
    plVar9 = (longlong *)*local_248;
    local_258[0] = (longlong *)plVar9[1];
    cVar1 = *(char *)((longlong)local_258[0] + 0x19);
    local_260 = plVar9;
    if (cVar1 == '\0') {
      plVar17 = local_258[0];
      do {
        ppppuVar15 = &local_228;
        if (0xf < uVar24) {
          ppppuVar15 = ppppuVar14;
        }
        plVar13 = plVar17 + 4;
        if (0xf < (ulonglong)plVar17[7]) {
          plVar13 = (longlong *)plVar17[4];
        }
        uVar22 = plVar17[6];
        uVar21 = uVar22;
        if (uVar5 < uVar22) {
          uVar21 = uVar5;
        }
        uStackY_2b0 = 0x180011f6e;
        uVar7 = memcmp(plVar13,ppppuVar15,uVar21);
        if (uVar7 == 0) {
          if (uVar22 < uVar5) {
            uVar7 = 0xffffffff;
          }
          else {
            uVar7 = (uint)(uVar5 < uVar22);
          }
        }
        if ((int)uVar7 < 0) {
          plVar13 = (longlong *)plVar17[2];
        }
        else {
          plVar13 = (longlong *)*plVar17;
          plVar9 = plVar17;
        }
        plVar17 = plVar13;
      } while (*(char *)((longlong)plVar13 + 0x19) == '\0');
      cVar1 = *(char *)((longlong)local_258[0] + 0x19);
    }
    plVar13 = local_258[0];
    plVar17 = local_260;
    if (*(char *)((longlong)plVar9 + 0x19) == '\0') {
      plVar18 = plVar9 + 4;
      if (0xf < (ulonglong)plVar9[7]) {
        plVar18 = (longlong *)plVar9[4];
      }
      ppppuVar14 = &local_228;
      if (0xf < local_210) {
        ppppuVar14 = local_228;
      }
      uVar24 = plVar9[6];
      uVar22 = uVar5;
      if (uVar24 < uVar5) {
        uVar22 = uVar24;
      }
      uStackY_2b0 = 0x180011fe1;
      uVar7 = memcmp(ppppuVar14,plVar18,uVar22);
      if (uVar7 == 0) {
        if (uVar5 < uVar24) {
          uVar7 = 0xffffffff;
        }
        else {
          uVar7 = (uint)(uVar24 < uVar5);
        }
      }
      if ((int)uVar7 < 0) goto LAB_180011ffe;
    }
    else {
LAB_180011ffe:
      plVar9 = plVar17;
    }
    uVar24 = local_210;
    ppppuVar14 = local_228;
    if (plVar9[8] != 0) {
      while (cVar1 == '\0') {
        ppppuVar15 = &local_228;
        if (0xf < uVar24) {
          ppppuVar15 = ppppuVar14;
        }
        plVar9 = plVar13 + 4;
        if (0xf < (ulonglong)plVar13[7]) {
          plVar9 = (longlong *)plVar13[4];
        }
        uVar22 = plVar13[6];
        uVar21 = uVar22;
        if (uVar5 < uVar22) {
          uVar21 = uVar5;
        }
        uStackY_2b0 = 0x18001204e;
        uVar7 = memcmp(plVar9,ppppuVar15,uVar21);
        if (uVar7 == 0) {
          if (uVar22 < uVar5) {
            uVar7 = 0xffffffff;
          }
          else {
            uVar7 = (uint)(uVar5 < uVar22);
          }
        }
        if ((int)uVar7 < 0) {
          plVar9 = (longlong *)plVar13[2];
          plVar13 = plVar17;
        }
        else {
          plVar9 = (longlong *)*plVar13;
        }
        plVar17 = plVar13;
        plVar13 = plVar9;
        cVar1 = *(char *)((longlong)plVar9 + 0x19);
      }
      if (*(char *)((longlong)plVar17 + 0x19) == '\0') {
        plVar9 = plVar17 + 4;
        if (0xf < (ulonglong)plVar17[7]) {
          plVar9 = (longlong *)plVar17[4];
        }
        ppppuVar15 = &local_228;
        if (0xf < uVar24) {
          ppppuVar15 = ppppuVar14;
        }
        uVar24 = plVar17[6];
        uVar22 = uVar5;
        if (uVar24 < uVar5) {
          uVar22 = uVar24;
        }
        uStackY_2b0 = 0x1800120b2;
        uVar7 = memcmp(ppppuVar15,plVar9,uVar22);
        if (uVar7 == 0) {
          if (uVar5 < uVar24) {
            uVar7 = 0xffffffff;
          }
          else {
            uVar7 = (uint)(uVar24 < uVar5);
          }
        }
        if ((int)uVar7 < 0) goto LAB_1800120cf;
      }
      else {
LAB_1800120cf:
        plVar17 = (longlong *)*local_248;
      }
      uStackY_2b0 = 0x1800120e0;
      (**(code **)(*(longlong *)plVar17[8] + 0x10))();
    }
    uStackY_2b0 = 0x1800120f1;
    plVar9 = FUN_1800078e0(local_248,(longlong *)local_258,&local_228);
    local_238 = *plVar9;
    lStack_230 = plVar9[1];
    uStackY_2b0 = 0x180012105;
    FUN_18001c760(local_248,&local_238);
  }
  uVar24 = local_210;
LAB_180012109:
  lVar4 = local_268;
  local_238 = 0;
  local_240 = (longlong *)0x0;
  puVar19 = auStackY_2c8 + 0x20;
  if ((*(char *)(local_268 + 0xac) == '\0') &&
     (puVar19 = auStackY_2c8 + 0x20, *(longlong *)(local_268 + 8) != 0)) {
    lpWideCharStr = local_288;
    if (lpWideCharStr == (LPWSTR)0x0) {
      lpWideCharStr = (LPWSTR)0x0;
    }
    else {
      local_288[0] = L'\0';
      iVar8 = MultiByteToWideChar(0,0,"PFSVData",-1,lpWideCharStr,9);
      if (iVar8 == 0) {
        lpWideCharStr = (LPWSTR)0x0;
      }
    }
    (**(code **)(**(longlong **)(lVar4 + 8) + 0x30))(*(longlong **)(lVar4 + 8),lpWideCharStr,0,0x12)
    ;
    puVar19 = auStackY_2c8;
    if (local_240 != (longlong *)0x0) {
      local_258[0] = (longlong *)0x0;
      (**(code **)(*local_240 + 0x20))(local_240,L"_Contents",0,0x12);
      if (local_258[0] != (longlong *)0x0) {
        local_248 = (longlong *)((ulonglong)local_248 & 0xffffffff00000000);
        uStack_200 = 0;
        local_1f8 = 0;
        local_1f0 = 0xf;
        local_208 = (LPCSTR ***)0x0;
        iVar8 = (**(code **)(*local_258[0] + 0x18))(local_258[0],&local_260,4,&local_268);
        if (iVar8 == 0) {
          while( true ) {
            if ((int)local_268 != 4) goto LAB_180012389;
            pvVar10 = operator_new__((ulonglong)((int)local_260 + 1));
            iVar8 = (int)local_260;
            *(undefined1 *)(((ulonglong)local_260 & 0xffffffff) + (longlong)pvVar10) = 0;
            (**(code **)(*local_258[0] + 0x18))
                      (local_258[0],pvVar10,(ulonglong)local_260 & 0xffffffff,&local_268);
            if (iVar8 != (int)local_268) break;
            (**(code **)(*local_258[0] + 0x18))(local_258[0],&local_260,4,&local_268);
            if ((int)local_268 != 4) break;
            pcVar11 = operator_new__((ulonglong)((int)local_260 + 1));
            iVar8 = (int)local_260;
            pcVar11[(ulonglong)local_260 & 0xffffffff] = '\0';
            (**(code **)(*local_258[0] + 0x18))
                      (local_258[0],pcVar11,(ulonglong)local_260 & 0xffffffff,&local_268);
            if (iVar8 != (int)local_268) goto LAB_18001236f;
            (**(code **)(*local_258[0] + 0x18))(local_258[0],&local_248,4,&local_268);
            if ((int)local_268 != 4) goto LAB_18001236f;
            ppppuVar14 = &local_228;
            if (0xf < uVar24) {
              ppppuVar14 = local_228;
            }
            pcVar12 = pcVar11;
            do {
              cVar1 = *pcVar12;
              cVar2 = pcVar12[(longlong)ppppuVar14 - (longlong)pcVar11];
              if (cVar1 != cVar2) break;
              pcVar12 = pcVar12 + 1;
            } while (cVar2 != '\0');
            if (cVar1 == cVar2) {
              if ((int)local_248 == 1) {
                do {
                  sVar23 = sVar23 + 1;
                } while (*(char *)((longlong)pvVar10 + sVar23) != '\0');
                FUN_18001d350((longlong *)&local_208,pvVar10,sVar23);
              }
              goto LAB_18001236f;
            }
            operator_delete__(pvVar10);
            operator_delete__(pcVar11);
            iVar8 = (**(code **)(*local_258[0] + 0x18))(local_258[0],&local_260,4,&local_268);
            if (iVar8 != 0) goto LAB_180012389;
          }
          pcVar11 = (char *)0x0;
LAB_18001236f:
          if (pvVar10 != (void *)0x0) {
            operator_delete__(pvVar10);
          }
          if (pcVar11 != (char *)0x0) {
            operator_delete__(pcVar11);
          }
        }
LAB_180012389:
        plVar9 = local_240;
        if (local_1f8 != 0) {
          ppppCVar16 = (LPCSTR ***)&local_208;
          if (0xf < local_1f0) {
            ppppCVar16 = local_208;
          }
          local_158 = local_150;
          FUN_18000d660(&local_158,(LPCSTR)ppppCVar16,0);
          (**(code **)(*plVar9 + 0x60))(plVar9,local_158);
          if (local_158 != local_150) {
            free(local_158);
          }
        }
        if (0xf < local_1f0) {
          ppppCVar16 = local_208;
          if ((0xfff < local_1f0 + 1) &&
             (ppppCVar16 = (LPCSTR ***)local_208[-1],
             (LPCSTR)0x1f < (LPCSTR)((longlong)local_208 + (-8 - (longlong)ppppCVar16)))) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
          FUN_180035134(ppppCVar16);
        }
      }
      puVar19 = auStackY_2c8;
      if (local_258[0] != (longlong *)0x0) {
        (**(code **)(*local_258[0] + 0x10))();
        puVar19 = auStackY_2c8;
      }
    }
  }
  if (local_240 != (longlong *)0x0) {
    pcVar3 = *(code **)(*local_240 + 0x10);
    *(undefined8 *)(puVar19 + -8) = 0x180012447;
    (*pcVar3)();
  }
  if (0xf < uVar24) {
    ppppuVar14 = local_228;
    if ((0xfff < uVar24 + 1) &&
       (ppppuVar14 = (undefined8 ****)local_228[-1],
       0x1f < (ulonglong)((longlong)local_228 + (-8 - (longlong)ppppuVar14)))) {
                    /* WARNING: Subroutine does not return */
      *(undefined **)(puVar19 + -8) = &UNK_18001247d;
      _invalid_parameter_noinfo_noreturn();
    }
    *(undefined8 *)(puVar19 + -8) = 0x180012483;
    FUN_180035134(ppppuVar14);
  }
  *(undefined8 *)(puVar19 + -8) = 0x180012492;
  return;
}

/* RVA 0x124b0 */
undefined8 FUN_1800124b0(longlong param_1,uchar *param_2)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar5;
  longlong *plVar6;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar7;
  undefined8 uVar8;
  DWORD DVar9;
  longlong *local_res8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res18 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_res20;
  longlong *local_c0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_b8;
  tagVARIANT local_b0;
  undefined1 local_98;
  longlong local_90;
  VARIANTARG local_88;
  _union_2707 local_70;
  undefined4 local_58;
  ULONG UStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 local_48;
  
  if (param_1 != 0) {
    local_98 = *(undefined1 *)(param_1 + 200);
  }
  uVar1 = local_98;
  local_90 = param_1;
  GRsetImportFile(1);
  GRsethideCancel(1);
  pcVar4 = strrchr((char *)param_2,0x2e);
  iVar3 = 0;
  pcVar4 = pcVar4 + 1;
  iVar2 = FUN_180033bd0();
  if (iVar2 == 1) {
    iVar2 = _stricmp(pcVar4,"bkp");
    if (iVar2 == 0) goto LAB_180012661;
    iVar2 = _stricmp(pcVar4,"apt");
    if (iVar2 == 0) goto LAB_180012655;
    iVar2 = _stricmp(pcVar4,"ikc");
    if (iVar2 == 0) goto LAB_180012649;
    iVar2 = _stricmp(pcVar4,"sum");
    if (iVar2 == 0) goto LAB_18001263d;
    iVar2 = _stricmp(pcVar4,"aprbkp");
    if (iVar2 == 0) {
      iVar3 = 5;
    }
LAB_18001259e:
    DVar9 = 0xffffffff;
    if (iVar3 != 1) {
      if (iVar3 == 2) goto LAB_18001265a;
      if (iVar3 == 3) goto LAB_18001264e;
      if (iVar3 == 4) goto LAB_180012642;
      if (iVar3 != 5) goto LAB_18001266b;
    }
LAB_180012666:
    DVar9 = 1;
  }
  else {
    iVar2 = _stricmp(pcVar4,"aprbkp");
    if (iVar2 == 0) {
LAB_180012661:
      iVar3 = 1;
      goto LAB_180012666;
    }
    iVar2 = _stricmp(pcVar4,"aprt");
    if (iVar2 == 0) {
LAB_180012655:
      iVar3 = 2;
LAB_18001265a:
      DVar9 = 2;
    }
    else {
      iVar2 = _stricmp(pcVar4,"ikc");
      if (iVar2 == 0) {
LAB_180012649:
        iVar3 = 3;
LAB_18001264e:
        DVar9 = 6;
      }
      else {
        iVar2 = _stricmp(pcVar4,"aprsum");
        if (iVar2 != 0) {
          iVar2 = _stricmp(pcVar4,"bkp");
          if (iVar2 != 0) goto LAB_18001259e;
          iVar3 = 5;
          goto LAB_180012666;
        }
LAB_18001263d:
        iVar3 = 4;
LAB_180012642:
        DVar9 = 7;
      }
    }
  }
LAB_18001266b:
  iVar2 = FUN_180033bd0();
  if (iVar2 == 1) {
    if (iVar3 == 5) {
      local_res8 = (longlong *)HappGetTree();
      pCVar5 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
               CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                         (local_res18,"Data\\Setup\\Main\\Input\\RUN_CLASS");
      plVar6 = (longlong *)FUN_180021b30((longlong *)&local_res8,pCVar5);
      local_c0 = plVar6;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
      AfxVariantInit(&local_b0);
      VariantClear(&local_b0);
      if (plVar6 != (longlong *)0x0) {
        VariantInit((VARIANTARG *)&local_70.n2);
        VariantInit(&local_88);
        local_58 = local_70._0_4_;
        UStack_54 = local_70.decVal.Hi32;
        uStack_50 = local_70._8_4_;
        uStack_4c = local_70._12_4_;
        local_48 = local_70._16_8_;
        iVar3 = (**(code **)(*plVar6 + 0x98))(plVar6,0,&local_58,&local_88);
        if (-1 < iVar3) {
          COleVariant::operator=((COleVariant *)&local_b0,&local_88);
          VariantClear(&local_88);
        }
      }
      local_b8 = local_res18;
      pCVar5 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
               CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18,"");
      pCVar7 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
               CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          &local_res20,param_2);
      local_b8 = pCVar7;
      FUN_180013b10(param_1,*(LPCSTR *)pCVar7,DVar9);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar7);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar5);
      FUN_1800117d0((longlong *)&local_c0,(COleVariant *)&local_b0);
      if (plVar6 != (longlong *)0x0) {
        (**(code **)(*plVar6 + 0x10))(plVar6);
      }
      (**(code **)(*local_res8 + 0x10))();
      VariantClear(&local_b0);
      goto LAB_18001285a;
    }
    local_res20 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8;
    pCVar5 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                       ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8
                        ,"");
    pCVar7 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18,param_2);
    local_res20 = pCVar7;
    FUN_180013b10(param_1,*(LPCSTR *)pCVar7,DVar9);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar7);
  }
  else {
    local_res20 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8;
    pCVar5 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                       ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8
                        ,"");
    pCVar7 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18,param_2);
    local_res20 = pCVar7;
    FUN_180013b10(param_1,*(LPCSTR *)pCVar7,DVar9);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar7);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar5);
LAB_18001285a:
  GRsethideCancel(0);
  GRsetImportFile(0);
  pcVar4 = _strdup("Refresh");
  uVar8 = SimSendMainWndMessage(0x536,0,pcVar4);
  if (param_1 != 0) {
    *(undefined1 *)(param_1 + 200) = uVar1;
  }
  return CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
}

/* RVA 0x128b0 */
undefined1 FUN_1800128b0(longlong param_1)

{
  IStorage **ppstgOpen;
  IStorage *pIVar1;
  undefined1 uVar2;
  int iVar3;
  undefined8 uVar4;
  _GUID *p_Var5;
  void *pvVar6;
  longlong *plVar7;
  size_t sVar8;
  longlong *plVar9;
  size_t sVar10;
  char *local_res8;
  LPCSTR local_res10;
  longlong *local_res18 [2];
  undefined1 local_38;
  
  local_res8 = (char *)0x0;
  if (param_1 != 0) {
    local_38 = *(undefined1 *)(param_1 + 200);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10);
  iVar3 = MMGetSuppress();
  uVar4 = FUN_180009bf0(param_1,iVar3,1,"",(CSimpleStringT<char,1> *)&local_res10);
  if ((int)uVar4 == -1) {
LAB_18001295e:
    uVar2 = 0;
  }
  else {
    if ((int)uVar4 == 1) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0xa0),
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 &local_res10);
      uVar2 = FUN_180013b10(param_1,local_res10,1);
      goto LAB_180012960;
    }
    iVar3 = HappInitted();
    if (iVar3 == 0) {
      ppstgOpen = (IStorage **)(param_1 + 8);
      StgCreateDocfile((WCHAR *)0x0,0x4011012,0,ppstgOpen);
      iVar3 = NewHapp(*ppstgOpen,&local_res8);
      if (iVar3 == 0) {
        SimExit();
        goto LAB_18001295e;
      }
      sVar8 = 0xffffffffffffffff;
      sVar10 = 0xffffffffffffffff;
      do {
        sVar10 = sVar10 + 1;
      } while (local_res8[sVar10] != '\0');
      FUN_18001d350((longlong *)(param_1 + 0x40),local_res8,sVar10);
      do {
        sVar8 = sVar8 + 1;
      } while (local_res8[sVar8] != '\0');
      FUN_18001d350((longlong *)(param_1 + 0x60),local_res8,sVar8);
      pIVar1 = *ppstgOpen;
      p_Var5 = (_GUID *)FUN_18000c750();
      pvVar6 = CreateApwnContextDocument(pIVar1,p_Var5);
      *(void **)(param_1 + 0xb0) = pvVar6;
      SetGlobalPointer("ApwnOleServerDoc",pvVar6,0);
      ApwnContextDocumentSetFilename(*(void **)(param_1 + 0xb0),local_res8);
    }
    else {
      pvVar6 = (void *)HappName();
      sVar8 = 0xffffffffffffffff;
      do {
        sVar8 = sVar8 + 1;
      } while (*(char *)((longlong)pvVar6 + sVar8) != '\0');
      plVar9 = (longlong *)(param_1 + 0x40);
      FUN_18001d350(plVar9,pvVar6,sVar8);
      if (0xf < *(ulonglong *)(param_1 + 0x58)) {
        plVar9 = (longlong *)*plVar9;
      }
      ApwnContextDocumentSetFilename(*(void **)(param_1 + 0xb0),(char *)plVar9);
    }
    FUN_18000f590(param_1);
    iVar3 = FUN_180033bd0();
    if (iVar3 == 1) {
      ApwnLibInitFromRegistry(0);
      plVar7 = (longlong *)HappGetTree();
      plVar9 = *(longlong **)(param_1 + 0x38);
      if (plVar9 != plVar7) {
        if ((plVar7 == (longlong *)0x0) ||
           (iVar3 = (**(code **)*plVar7)(plVar7,&DAT_1800413f0,param_1 + 0x38), iVar3 < 0)) {
          *(undefined8 *)(param_1 + 0x38) = 0;
        }
        if (plVar9 != (longlong *)0x0) {
          (**(code **)(*plVar9 + 0x10))(plVar9);
        }
      }
      InitGlobalBlockUsage(*(undefined8 *)(param_1 + 0x38));
      local_res18[0] = (longlong *)0x0;
      FUN_18000c8a0(param_1,*(undefined8 **)(param_1 + 0x38),local_res18);
      plVar9 = local_res18[0];
      if (local_res18[0] != (longlong *)0x0) {
        SEInitializeVData(local_res18[0]);
        (**(code **)(*plVar9 + 0x10))(plVar9);
      }
    }
    SetGlobalPointer("ApwnDocStorage",*(undefined8 *)(param_1 + 8),0);
    SetGlobalPointer("LoadPFSFromDoc",&LAB_18000d600,0);
    SetGlobalPointer("SavePFSFToDoc",&LAB_18000d640,0);
    SetGlobalPointer("GetPFSEmbedding",&LAB_18000d5d0,0);
    SetGlobalPointer("ClearPFSEmbedding",&LAB_18000d5b0,0);
    SetGlobalPointer("RestorePFSEmbedding",&LAB_18000d620,0);
    OpenDataShareOLE(0,local_res8,0);
    uVar2 = 1;
  }
LAB_180012960:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10);
  if (param_1 != 0) {
    *(undefined1 *)(param_1 + 200) = local_38;
  }
  return uVar2;
}

/* RVA 0x12bc0 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_180012bc0(longlong param_1,LPCSTR param_2)

{
  short sVar1;
  char cVar2;
  DWORD DVar3;
  longlong lVar4;
  ulonglong uVar5;
  LPCWSTR ****pppppWVar6;
  longlong lVar7;
  undefined8 uVar8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar9;
  ulonglong uVar10;
  char *****pppppcVar11;
  ulonglong uVar12;
  int iVar13;
  char *****pppppcVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  LPCWSTR ****pppppWVar18;
  undefined2 *puVar19;
  short *psVar20;
  undefined1 *puVar21;
  size_t sVar22;
  ulonglong uVar23;
  size_t sVar24;
  undefined8 uStack_180;
  undefined1 auStack_178 [32];
  undefined8 uStack_158;
  int aiStack_150 [6];
  char local_138;
  undefined1 uStack_137;
  DWORD DStack_134;
  LPCSTR local_130;
  LPCSTR local_128;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_120 [8];
  undefined1 local_118;
  longlong local_110;
  LPCWSTR ****local_108;
  undefined8 uStack_100;
  ulonglong local_f8;
  ulonglong local_f0;
  char *****local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  ulonglong uStack_d0;
  LPCWSTR ****local_c8;
  undefined8 uStack_c0;
  ulonglong local_b8;
  ulonglong local_b0;
  char *****local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  ulonglong uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  ulonglong uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = DAT_180052888 ^ (ulonglong)&local_138;
  local_130 = param_2;
  local_110 = param_1;
  if (param_1 != 0) {
    local_118 = *(undefined1 *)(param_1 + 200);
  }
  uStack_137 = local_118;
  sVar24 = 0xffffffffffffffff;
  DVar3 = 0xffffffff;
  DStack_134 = 0xffffffff;
  uStack_e0 = 0;
  local_d8 = _DAT_180041f70;
  uStack_d0 = _UNK_180041f78;
  local_e8 = (char *****)0x0;
  uStack_80 = 0;
  local_78 = _DAT_180041f70;
  uStack_70 = _UNK_180041f78;
  local_88 = 0;
  puVar17 = auStack_178;
  if (param_2 == (LPCSTR)0x0) {
LAB_180012cd8:
    puVar19 = (undefined2 *)0x0;
  }
  else {
    lVar4 = -1;
    do {
      lVar7 = lVar4;
      lVar4 = lVar7 + 1;
    } while (param_2[lVar4] != '\0');
    iVar13 = (int)lVar7 + 2;
    puVar17 = auStack_178;
    if (0x3fffffff < iVar13) goto LAB_180012cd8;
    lVar4 = (longlong)(int)lVar4 * 2;
    uVar10 = lVar4 + 0x11;
    if (uVar10 <= lVar4 + 2U) {
      uVar10 = 0xffffffffffffff0;
    }
    uStack_180 = 0x180012ca6;
    lVar4 = -(uVar10 & 0xfffffffffffffff0);
    puVar17 = auStack_178 + lVar4;
    puVar19 = (undefined2 *)((longlong)aiStack_150 + lVar4 + 0x18);
    if (puVar19 == (undefined2 *)0x0) goto LAB_180012cd8;
    *puVar19 = 0;
    *(int *)((longlong)aiStack_150 + lVar4) = iVar13;
    *(undefined2 **)(auStack_178 + lVar4 + 0x20) = puVar19;
    *(undefined8 *)(auStack_178 + lVar4 + -8) = 0x180012cd0;
    iVar13 = MultiByteToWideChar(0,0,param_2,-1,*(LPWSTR *)(auStack_178 + lVar4 + 0x20),
                                 *(int *)((longlong)aiStack_150 + lVar4));
    puVar17 = auStack_178 + lVar4;
    if (iVar13 == 0) {
      puVar19 = (undefined2 *)0x0;
      puVar17 = auStack_178 + lVar4;
    }
  }
  local_108 = (LPCWSTR ****)0x0;
  uStack_100 = 0;
  local_f8 = 0;
  local_f0 = 0;
  uVar10 = 0xffffffffffffffff;
  do {
    uVar10 = uVar10 + 1;
  } while (puVar19[uVar10] != 0);
  *(undefined8 *)(puVar17 + -8) = 0x180012d07;
  FUN_180006f50(&local_108,puVar19,uVar10);
  uStack_60 = 0;
  local_58 = _DAT_180041f60;
  uStack_50 = _UNK_180041f68;
  local_68 = 0;
  pppppWVar6 = (LPCWSTR ****)&local_108;
  if (7 < local_f0) {
    pppppWVar6 = local_108;
  }
  if (local_f8 != 0) {
    uVar10 = local_f8;
    pppppWVar18 = pppppWVar6;
LAB_180012d51:
    if (*(short *)pppppWVar18 != 0x7c) goto code_r0x000180012d57;
    if (((pppppWVar18 != (LPCWSTR ****)0x0) &&
        (uVar10 = (longlong)pppppWVar18 - (longlong)pppppWVar6 >> 1, uVar10 != 0xffffffffffffffff))
       && (uVar10 == local_f8 - 2)) {
      uVar12 = uVar10 + 1;
      local_c8 = (LPCWSTR ****)0x0;
      uStack_c0 = 0;
      local_b8 = 0;
      local_b0 = 0;
      if (local_f8 < uVar12) {
                    /* WARNING: Subroutine does not return */
        *(undefined **)(puVar17 + -8) = &UNK_1800134f3;
        FUN_18001d1f0();
      }
      uVar23 = 0xffffffffffffffff;
      if (local_f8 - uVar12 != 0xffffffffffffffff) {
        uVar23 = local_f8 - uVar12;
      }
      pppppWVar6 = (LPCWSTR ****)&local_108;
      if (7 < local_f0) {
        pppppWVar6 = local_108;
      }
      psVar20 = (short *)((longlong)pppppWVar6 + uVar12 * 2);
      if (0x7ffffffffffffffe < uVar23) {
                    /* WARNING: Subroutine does not return */
        *(undefined8 *)(puVar17 + -8) = 0x1800134ed;
        FUN_18001d1b0();
      }
      local_b0 = 7;
      if (uVar23 < 8) {
        local_b8 = uVar23;
        *(undefined8 *)(puVar17 + -8) = 0x180012e08;
        memcpy(&local_c8,psVar20,uVar23 * 2);
        *(undefined2 *)((longlong)&local_c8 + uVar23 * 2) = 0;
      }
      else {
        uVar5 = uVar23 | 7;
        uVar12 = 0x7ffffffffffffffe;
        if ((uVar5 < 0x7fffffffffffffff) && (uVar12 = uVar5, uVar5 < 10)) {
          uVar12 = 10;
        }
        *(undefined8 *)(puVar17 + -8) = 0x180012e3b;
        pppppWVar6 = FUN_18001d2e0(&local_c8,uVar12 + 1);
        local_c8 = pppppWVar6;
        local_b8 = uVar23;
        local_b0 = uVar12;
        *(undefined8 *)(puVar17 + -8) = 0x180012e61;
        memcpy(pppppWVar6,psVar20,uVar23 * 2);
        *(undefined2 *)((longlong)pppppWVar6 + uVar23 * 2) = 0;
      }
      pppppWVar6 = (LPCWSTR ****)&local_c8;
      puVar16 = puVar17;
      if ((7 < local_b0) && (pppppWVar6 = local_c8, local_c8 == (LPCWSTR ****)0x0))
      goto LAB_180012f0a;
      lVar4 = -1;
      do {
        lVar7 = lVar4;
        lVar4 = lVar7 + 1;
      } while (*(short *)((longlong)pppppWVar6 + lVar4 * 2) != 0);
      iVar13 = (int)lVar7 + 2;
      if (iVar13 < 0x40000000) {
        lVar4 = (longlong)(int)lVar4 * 2;
        uVar12 = lVar4 + 0x11;
        if (uVar12 <= lVar4 + 2U) {
          uVar12 = 0xffffffffffffff0;
        }
        *(undefined8 *)(puVar17 + -8) = 0x180012ecf;
        lVar4 = -(uVar12 & 0xfffffffffffffff0);
        puVar16 = puVar17 + lVar4;
        puVar15 = puVar17 + lVar4;
        puVar21 = puVar17 + lVar4 + 0x40;
        if (puVar21 == (undefined1 *)0x0) goto LAB_180012f0a;
        *puVar21 = 0;
        *(undefined8 *)(puVar17 + lVar4 + 0x38) = 0;
        *(undefined8 *)(puVar17 + lVar4 + 0x30) = 0;
        *(int *)(puVar17 + lVar4 + 0x28) = iVar13 * 2;
        *(undefined1 **)(puVar17 + lVar4 + 0x20) = puVar21;
        *(undefined8 *)(puVar17 + lVar4 + -8) = 0x180012f02;
        iVar13 = WideCharToMultiByte(0,0,(LPCWSTR)pppppWVar6,-1,*(LPSTR *)(puVar17 + lVar4 + 0x20),
                                     *(int *)(puVar17 + lVar4 + 0x28),
                                     *(LPCSTR *)(puVar17 + lVar4 + 0x30),
                                     *(LPBOOL *)(puVar17 + lVar4 + 0x38));
        puVar17 = puVar17 + lVar4;
        if (iVar13 == 0) {
          puVar21 = (undefined1 *)0x0;
          puVar17 = puVar15;
        }
      }
      else {
LAB_180012f0a:
        puVar21 = (undefined1 *)0x0;
        puVar17 = puVar16;
      }
      local_a8 = (char *****)0x0;
      uStack_a0 = 0;
      local_98 = 0;
      uStack_90 = 0;
      sVar22 = 0xffffffffffffffff;
      do {
        sVar22 = sVar22 + 1;
      } while (puVar21[sVar22] != '\0');
      *(undefined8 *)(puVar17 + -8) = 0x180012f3e;
      FUN_180006e90(&local_a8,puVar21,sVar22);
      pppppcVar11 = (char *****)&local_a8;
      if (0xf < uStack_90) {
        pppppcVar11 = local_a8;
      }
      *(undefined8 *)(puVar17 + -8) = 0x180012f5c;
      DVar3 = atoi((char *)pppppcVar11);
      uVar12 = local_f8;
      DStack_134 = DVar3;
      if (local_f8 < uVar10) {
        uVar23 = uVar10 - local_f8;
        if (local_f0 - local_f8 < uVar23) {
          *(undefined2 *)(puVar17 + 0x20) = 0;
          *(undefined8 *)(puVar17 + -8) = 0x180012fdc;
          FUN_180007fd0(&local_108,uVar23,0,uVar23,*(undefined2 *)(puVar17 + 0x20));
        }
        else {
          local_f8 = uVar10;
          pppppWVar6 = (LPCWSTR ****)&local_108;
          if (7 < local_f0) {
            pppppWVar6 = local_108;
          }
          if (uVar23 != 0) {
            psVar20 = (short *)((longlong)pppppWVar6 + uVar12 * 2);
            for (uVar10 = uVar23; uVar10 != 0; uVar10 = uVar10 - 1) {
              *psVar20 = 0;
              psVar20 = psVar20 + 1;
            }
          }
          *(short *)((longlong)pppppWVar6 + (uVar23 + uVar12) * 2) = 0;
        }
      }
      else {
        local_f8 = uVar10;
        pppppWVar6 = (LPCWSTR ****)&local_108;
        if (7 < local_f0) {
          pppppWVar6 = local_108;
        }
        *(short *)((longlong)pppppWVar6 + uVar10 * 2) = 0;
      }
      if (0xf < uStack_90) {
        pppppcVar11 = local_a8;
        if ((0xfff < uStack_90 + 1) &&
           (pppppcVar11 = (char *****)local_a8[-1],
           (char *)0x1f < (char *)((longlong)local_a8 + (-8 - (longlong)pppppcVar11)))) {
                    /* WARNING: Subroutine does not return */
          *(undefined **)(puVar17 + -8) = &UNK_18001301b;
          _invalid_parameter_noinfo_noreturn();
        }
        *(undefined8 *)(puVar17 + -8) = 0x180013021;
        FUN_180035134(pppppcVar11);
      }
      local_98 = _DAT_180041f70;
      uStack_90 = _UNK_180041f78;
      local_a8 = (char *****)((ulonglong)local_a8 & 0xffffffffffffff00);
      param_2 = local_130;
      if (7 < local_b0) {
        pppppWVar6 = local_c8;
        if ((0xfff < local_b0 * 2 + 2) &&
           (pppppWVar6 = (LPCWSTR ****)local_c8[-1],
           0x1f < (ulonglong)((longlong)local_c8 + (-8 - (longlong)pppppWVar6)))) {
                    /* WARNING: Subroutine does not return */
          *(undefined **)(puVar17 + -8) = &UNK_180013078;
          _invalid_parameter_noinfo_noreturn();
        }
        *(undefined8 *)(puVar17 + -8) = 0x18001307e;
        FUN_180035134(pppppWVar6);
        param_2 = local_130;
      }
    }
  }
LAB_180013091:
  uVar10 = local_f8;
  cVar2 = '\x01';
  pppppWVar6 = (LPCWSTR ****)&local_108;
  if (7 < local_f0) {
    pppppWVar6 = local_108;
  }
  if (local_f8 != 0) {
    lVar4 = -1;
    if (local_f8 - 1 != -1) {
      lVar4 = local_f8 - 1;
    }
    pppppWVar18 = (LPCWSTR ****)((longlong)pppppWVar6 + lVar4 * 2);
    sVar1 = *(short *)pppppWVar18;
    while (sVar1 != 0x3e) {
      if (pppppWVar18 == pppppWVar6) goto LAB_18001315a;
      pppppWVar18 = (LPCWSTR ****)((longlong)pppppWVar18 + -2);
      sVar1 = *(short *)pppppWVar18;
    }
    uVar12 = (longlong)pppppWVar18 - (longlong)pppppWVar6 >> 1;
    if (uVar12 != 0xffffffffffffffff) {
      if (local_f8 < uVar12) {
        uVar23 = uVar12 - local_f8;
        if (local_f0 - local_f8 < uVar23) {
          *(undefined2 *)(puVar17 + 0x20) = 0;
          *(undefined8 *)(puVar17 + -8) = 0x180013152;
          FUN_180007fd0(&local_108,uVar23,0,uVar23,*(undefined2 *)(puVar17 + 0x20));
        }
        else {
          local_f8 = uVar12;
          pppppWVar6 = (LPCWSTR ****)&local_108;
          if (7 < local_f0) {
            pppppWVar6 = local_108;
          }
          if (uVar23 != 0) {
            psVar20 = (short *)((longlong)pppppWVar6 + uVar10 * 2);
            for (uVar12 = uVar23; uVar12 != 0; uVar12 = uVar12 - 1) {
              *psVar20 = 0;
              psVar20 = psVar20 + 1;
            }
          }
          *(short *)((longlong)pppppWVar6 + (uVar23 + uVar10) * 2) = 0;
        }
      }
      else {
        local_f8 = uVar12;
        pppppWVar6 = (LPCWSTR ****)&local_108;
        if (7 < local_f0) {
          pppppWVar6 = local_108;
        }
        *(short *)((longlong)pppppWVar6 + uVar12 * 2) = 0;
      }
    }
  }
LAB_18001315a:
  pppppWVar6 = (LPCWSTR ****)&local_108;
  puVar16 = puVar17;
  if ((local_f0 < 8) || (pppppWVar6 = local_108, local_108 != (LPCWSTR ****)0x0)) {
    lVar4 = -1;
    do {
      lVar7 = lVar4;
      lVar4 = lVar7 + 1;
    } while (*(short *)((longlong)pppppWVar6 + lVar4 * 2) != 0);
    iVar13 = (int)lVar7 + 2;
    if (0x3fffffff < iVar13) goto LAB_1800131ed;
    lVar4 = (longlong)(int)lVar4 * 2;
    uVar10 = lVar4 + 0x11;
    if (uVar10 <= lVar4 + 2U) {
      uVar10 = 0xffffffffffffff0;
    }
    *(undefined8 *)(puVar17 + -8) = 0x1800131b2;
    lVar4 = -(uVar10 & 0xfffffffffffffff0);
    puVar16 = puVar17 + lVar4;
    puVar21 = puVar17 + lVar4 + 0x40;
    if (puVar21 == (undefined1 *)0x0) goto LAB_1800131ed;
    *puVar21 = 0;
    *(undefined8 *)(puVar17 + lVar4 + 0x38) = 0;
    *(undefined8 *)(puVar17 + lVar4 + 0x30) = 0;
    *(int *)(puVar17 + lVar4 + 0x28) = iVar13 * 2;
    *(undefined1 **)(puVar17 + lVar4 + 0x20) = puVar21;
    *(undefined8 *)(puVar17 + lVar4 + -8) = 0x1800131e5;
    iVar13 = WideCharToMultiByte(0,0,(LPCWSTR)pppppWVar6,-1,*(LPSTR *)(puVar17 + lVar4 + 0x20),
                                 *(int *)(puVar17 + lVar4 + 0x28),
                                 *(LPCSTR *)(puVar17 + lVar4 + 0x30),
                                 *(LPBOOL *)(puVar17 + lVar4 + 0x38));
    puVar16 = puVar17 + lVar4;
    if (iVar13 == 0) {
      puVar21 = (undefined1 *)0x0;
      puVar16 = puVar17 + lVar4;
    }
  }
  else {
LAB_1800131ed:
    puVar21 = (undefined1 *)0x0;
  }
  local_a8 = (char *****)0x0;
  uStack_a0 = 0;
  local_98 = 0;
  uStack_90 = 0;
  do {
    sVar24 = sVar24 + 1;
  } while (puVar21[sVar24] != '\0');
  *(undefined8 *)(puVar16 + -8) = 0x180013221;
  FUN_180006e90(&local_a8,puVar21,sVar24);
  if (0xf < uStack_d0) {
    pppppcVar11 = local_e8;
    if ((0xfff < uStack_d0 + 1) &&
       (pppppcVar11 = (char *****)local_e8[-1],
       0x1f < (ulonglong)((longlong)local_e8 + (-8 - (longlong)pppppcVar11)))) {
                    /* WARNING: Subroutine does not return */
      *(undefined **)(puVar16 + -8) = &UNK_180013259;
      _invalid_parameter_noinfo_noreturn();
    }
    *(undefined8 *)(puVar16 + -8) = 0x18001325f;
    FUN_180035134(pppppcVar11);
  }
  local_e8 = local_a8;
  uStack_e0 = uStack_a0;
  local_d8 = local_98;
  uStack_d0 = uStack_90;
  *(undefined8 *)(puVar16 + -8) = 0x18001327a;
  iVar13 = HappInitted();
  if (iVar13 == 0) {
    *(undefined8 *)(puVar16 + -8) = 0x18001328c;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_128);
    pppppcVar11 = (char *****)&local_e8;
    if (0xf < uStack_d0) {
      pppppcVar11 = local_e8;
    }
    *(undefined8 *)(puVar16 + -8) = 0x1800132a0;
    iVar13 = MMGetSuppress();
    *(LPCSTR **)(puVar16 + 0x20) = &local_128;
    *(undefined8 *)(puVar16 + -8) = 0x1800132b9;
    uVar8 = FUN_180009bf0(param_1,iVar13,0,(char *)pppppcVar11,
                          *(CSimpleStringT<char,1> **)(puVar16 + 0x20));
    if ((int)uVar8 == -1) {
      local_138 = '\0';
    }
    else if ((int)uVar8 == 1) {
      *(undefined8 *)(puVar16 + -8) = 0x1800133e8;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0xa0),
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 &local_128);
      *(undefined8 *)(puVar16 + -8) = 0x1800133fa;
      local_138 = FUN_180013b10(param_1,local_128,1);
    }
    else {
      pppppcVar14 = (char *****)&local_e8;
      if (0xf < uStack_d0) {
        pppppcVar14 = local_e8;
      }
      *(undefined8 *)(puVar16 + -8) = 0x1800132e3;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_130,
                 (char *)pppppcVar14);
      if (DVar3 != 0xffffffff) {
LAB_180013312:
        if (DVar3 == 3) {
          *(undefined8 *)(puVar16 + -8) = 0x180013323;
          uVar8 = FUN_18000a4e0(param_1,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                         *)&local_130);
          if ((int)uVar8 == 0) {
            local_138 = (char)uVar8;
            goto LAB_18001332a;
          }
          *(undefined8 *)(puVar16 + -8) = 0x180013344;
          uVar8 = GetSorResStringEx(0x578);
          *(undefined8 *)(puVar16 + -8) = 0x18001334e;
          SimUpdateMessageView(0,uVar8);
        }
        switch(DVar3) {
        case 0:
          pppppcVar14 = (char *****)&local_e8;
          if (0xf < uStack_d0) {
            pppppcVar14 = local_e8;
          }
          *(undefined8 *)(puVar16 + -8) = 0x180013382;
          uVar8 = FUN_180015030(param_1,(char *)pppppcVar14,'\0',pppppcVar11);
          cVar2 = (char)uVar8;
          break;
        case 1:
        case 2:
        case 3:
        case 6:
        case 7:
          *(undefined8 *)(puVar16 + -8) = 0x180013392;
          cVar2 = FUN_180013b10(param_1,param_2,DVar3);
        }
        *(undefined8 *)(puVar16 + -8) = 0x18001339f;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_130);
        *(undefined8 *)(puVar16 + -8) = 0x1800133aa;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_128);
        if (cVar2 == '\0') goto LAB_180013418;
        goto LAB_1800133af;
      }
      *(undefined8 *)(puVar16 + -8) = 0x1800132f7;
      pCVar9 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
               CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                         (local_120,
                          (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                           *)&local_130);
      *(undefined8 *)(puVar16 + -8) = 0x180013306;
      uVar8 = FUN_18000caa0(param_1,(int *)&DStack_134,pCVar9);
      if ((char)uVar8 != '\0') {
        DVar3 = DStack_134;
        goto LAB_180013312;
      }
      local_138 = '\0';
LAB_18001332a:
      *(undefined8 *)(puVar16 + -8) = 0x180013334;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_130);
    }
    *(undefined8 *)(puVar16 + -8) = 0x18001340b;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_128);
    cVar2 = local_138;
  }
  else {
LAB_1800133af:
    *(undefined8 *)(puVar16 + -8) = 0x1800133b5;
    iVar13 = GRinqrcl();
    if (iVar13 == 1) {
      *(undefined8 *)(puVar16 + -8) = 0x180013417;
      HAProcessTypeIntegrityCheck();
    }
    else {
      *(undefined8 *)(puVar16 + -8) = 0x1800133c7;
      GRsetrcl(1);
      *(undefined8 *)(puVar16 + -8) = 0x1800133cd;
      HAProcessTypeIntegrityCheck();
      *(undefined8 *)(puVar16 + -8) = 0x1800133d5;
      GRsetrcl(iVar13);
    }
  }
LAB_180013418:
  if (7 < local_f0) {
    pppppWVar6 = local_108;
    if ((0xfff < local_f0 * 2 + 2) &&
       (pppppWVar6 = (LPCWSTR ****)local_108[-1],
       0x1f < (ulonglong)((longlong)local_108 + (-8 - (longlong)pppppWVar6)))) {
                    /* WARNING: Subroutine does not return */
      *(undefined **)(puVar16 + -8) = &UNK_180013455;
      _invalid_parameter_noinfo_noreturn();
    }
    *(undefined8 *)(puVar16 + -8) = 0x18001345b;
    FUN_180035134(pppppWVar6);
  }
  local_f8 = 0;
  local_f0 = 7;
  local_108 = (LPCWSTR ****)((ulonglong)local_108 & 0xffffffffffff0000);
  if (0xf < uStack_d0) {
    pppppcVar11 = local_e8;
    if ((0xfff < uStack_d0 + 1) &&
       (pppppcVar11 = (char *****)local_e8[-1],
       (char *)0x1f < (char *)((longlong)local_e8 + (-8 - (longlong)pppppcVar11)))) {
                    /* WARNING: Subroutine does not return */
      *(undefined **)(puVar16 + -8) = &UNK_1800134a4;
      _invalid_parameter_noinfo_noreturn();
    }
    *(undefined8 *)(puVar16 + -8) = 0x1800134aa;
    FUN_180035134(pppppcVar11);
  }
  if (param_1 != 0) {
    *(undefined1 *)(param_1 + 200) = uStack_137;
  }
  *(undefined8 *)(puVar16 + -8) = 0x1800134ce;
  return cVar2;
code_r0x000180012d57:
  pppppWVar18 = (LPCWSTR ****)((longlong)pppppWVar18 + 2);
  uVar10 = uVar10 - 1;
  if (uVar10 == 0) goto LAB_180013091;
  goto LAB_180012d51;
}

/* RVA 0x13520 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180013520(longlong param_1,longlong *param_2)

{
  char cVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  int iVar7;
  longlong *plVar8;
  longlong *plVar9;
  ulonglong uVar10;
  undefined8 ******ppppppuVar11;
  void *pvVar12;
  undefined8 *******pppppppuVar13;
  void **ppvVar14;
  size_t sVar15;
  ulonglong uVar16;
  longlong *plVar17;
  undefined1 auStack_1f8 [32];
  undefined8 local_1d8;
  undefined4 uStack_1d0;
  undefined4 uStack_1cc;
  undefined8 local_1c8;
  _union_2707 local_1b8;
  longlong local_1a0;
  longlong local_198;
  longlong lStack_190;
  _union_2707 local_188;
  longlong *local_170;
  undefined8 ******local_168;
  undefined8 ******ppppppuStack_160;
  ulonglong local_158;
  ulonglong uStack_150;
  longlong *local_148;
  longlong local_140;
  undefined8 *******local_138;
  undefined8 uStack_130;
  ulonglong local_128;
  ulonglong local_120;
  void *local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  ulonglong uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  ulonglong uStack_e0;
  undefined1 *local_d8;
  undefined1 local_d0 [136];
  ulonglong local_48;
  
  local_48 = DAT_180052888 ^ (ulonglong)auStack_1f8;
  local_1a0 = param_1;
  VariantInit((VARIANTARG *)&local_188.n2);
  VariantInit((VARIANTARG *)&local_1b8.n2);
  uStack_f0 = 0;
  local_e8 = _DAT_180041f70;
  uStack_e0 = _UNK_180041f78;
  local_f8 = 0;
  local_1d8._0_4_ = local_188._0_4_;
  local_1d8._4_4_ = local_188.decVal.Hi32;
  uStack_1d0 = local_188._8_4_;
  uStack_1cc = local_188._12_4_;
  local_1c8 = local_188._16_8_;
  iVar7 = (**(code **)(*param_2 + 0x98))(param_2,0x3f,&local_1d8,&local_1b8);
  if (((-1 < iVar7) && (local_1b8.n2.vt == 3)) && (local_1b8._8_4_ != 0)) {
    VariantClear((VARIANTARG *)&local_1b8.n2);
    local_1d8._0_4_ = local_188._0_4_;
    local_1d8._4_4_ = local_188.decVal.Hi32;
    uStack_1d0 = local_188._8_4_;
    uStack_1cc = local_188._12_4_;
    local_1c8 = local_188._16_8_;
    iVar7 = (**(code **)(*param_2 + 0x98))(param_2,0x41,&local_1d8,&local_1b8);
    if (-1 < iVar7) {
      local_d8 = local_d0;
      FUN_18000d880(&local_d8,(LPCWSTR)CONCAT44(local_1b8._12_4_,local_1b8._8_4_),0);
      local_138 = (undefined8 *******)0x0;
      uStack_130 = 0;
      local_128 = 0;
      local_120 = 0;
      sVar15 = 0xffffffffffffffff;
      do {
        sVar15 = sVar15 + 1;
      } while (local_d8[sVar15] != '\0');
      FUN_180006e90(&local_138,local_d8,sVar15);
      if (local_d8 != local_d0) {
        free(local_d8);
      }
      pppppppuVar13 = &local_138;
      if (0xf < local_120) {
        pppppppuVar13 = local_138;
      }
      plVar8 = (longlong *)HYGetModelByName(pppppppuVar13);
      local_170 = plVar8;
      if (plVar8 != (longlong *)0x0) {
        (**(code **)(*plVar8 + 8))(plVar8);
      }
      uStack_110 = 0;
      local_108 = _DAT_180041f70;
      uStack_100 = _UNK_180041f78;
      local_118 = (void *)0x0;
      plVar17 = (longlong *)(param_1 + 0xd0);
      puVar2 = *(undefined8 **)*plVar17;
      while (puVar2 != (undefined8 *)*plVar17) {
        if ((longlong *)puVar2[8] == plVar8) {
          ppvVar14 = (void **)(puVar2 + 4);
          if (&local_118 != ppvVar14) {
            if (0xf < (ulonglong)puVar2[7]) {
              ppvVar14 = *ppvVar14;
            }
            FUN_18001d350((longlong *)&local_118,ppvVar14,puVar2[6]);
          }
          lVar4 = puVar2[9];
          if (lVar4 != 0) {
            plVar9 = FUN_1800078e0(plVar17,&local_1d8,&local_118);
            local_198 = *plVar9;
            lStack_190 = plVar9[1];
            FUN_18001c760(plVar17,&local_198);
            uVar5 = local_128;
            local_168 = (undefined8 ******)0x0;
            ppppppuStack_160 = (undefined8 ******)0x0;
            local_158 = 0;
            uStack_150 = 0;
            pppppppuVar13 = &local_138;
            if (0xf < local_120) {
              pppppppuVar13 = local_138;
            }
            if (0x7fffffffffffffff < local_128) goto LAB_180013afd;
            if (local_128 < 0x10) {
              local_158 = local_128;
              uStack_150 = 0xf;
              local_168 = *pppppppuVar13;
              ppppppuStack_160 = pppppppuVar13[1];
            }
            else {
              uVar16 = local_128 | 0xf;
              if (uVar16 < 0x8000000000000000) {
                if (uVar16 < 0x16) {
                  uVar16 = 0x16;
                }
              }
              else {
                uVar16 = 0x7fffffffffffffff;
              }
              local_168 = FUN_18001d210(&local_168,uVar16 + 1);
              local_158 = uVar5;
              uStack_150 = uVar16;
              memcpy(local_168,pppppppuVar13,uVar5 + 1);
            }
            local_148 = plVar8;
            local_140 = lVar4;
            FUN_180008240(plVar17,&local_1d8,&local_168);
            if (0xf < uStack_150) {
              ppppppuVar11 = local_168;
              if ((0xfff < uStack_150 + 1) &&
                 (ppppppuVar11 = (undefined8 ******)local_168[-1],
                 0x1f < (ulonglong)((longlong)local_168 + (-8 - (longlong)ppppppuVar11))))
              goto LAB_180013a39;
              FUN_180035134(ppppppuVar11);
            }
          }
          break;
        }
        puVar3 = (undefined8 *)puVar2[2];
        if (*(char *)((longlong)puVar3 + 0x19) == '\0') {
          cVar1 = *(char *)((longlong)*puVar3 + 0x19);
          puVar2 = puVar3;
          puVar3 = (undefined8 *)*puVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((longlong)*puVar3 + 0x19);
            puVar2 = puVar3;
            puVar3 = (undefined8 *)*puVar3;
          }
        }
        else {
          cVar1 = *(char *)((longlong)puVar2[1] + 0x19);
          puVar6 = (undefined8 *)puVar2[1];
          puVar3 = puVar2;
          while ((puVar2 = puVar6, cVar1 == '\0' && (puVar3 == (undefined8 *)puVar2[2]))) {
            cVar1 = *(char *)((longlong)puVar2[1] + 0x19);
            puVar6 = (undefined8 *)puVar2[1];
            puVar3 = puVar2;
          }
        }
      }
      plVar17 = (longlong *)(local_1a0 + 0xe0);
      puVar2 = *(undefined8 **)*plVar17;
      while (puVar2 != (undefined8 *)*plVar17) {
        if ((longlong *)puVar2[8] == plVar8) {
          ppvVar14 = (void **)(puVar2 + 4);
          if (&local_118 != ppvVar14) {
            if (0xf < (ulonglong)puVar2[7]) {
              ppvVar14 = *ppvVar14;
            }
            FUN_18001d350((longlong *)&local_118,ppvVar14,puVar2[6]);
          }
          lVar4 = puVar2[9];
          if (lVar4 != 0) {
            plVar9 = FUN_1800078e0(plVar17,&local_1d8,&local_118);
            local_198 = *plVar9;
            lStack_190 = plVar9[1];
            FUN_18001c760(plVar17,&local_198);
            uVar5 = local_128;
            local_168 = (undefined8 ******)0x0;
            ppppppuStack_160 = (undefined8 ******)0x0;
            local_158 = 0;
            uStack_150 = 0;
            pppppppuVar13 = &local_138;
            if (0xf < local_120) {
              pppppppuVar13 = local_138;
            }
            if (0x7fffffffffffffff < local_128) {
LAB_180013afd:
              uStack_150 = 0;
              local_158 = 0;
              ppppppuStack_160 = (undefined8 ******)0x0;
              local_168 = (undefined8 ******)0x0;
                    /* WARNING: Subroutine does not return */
              FUN_18001d1b0();
            }
            if (local_128 < 0x10) {
              local_158 = local_128;
              uStack_150 = 0xf;
              local_168 = *pppppppuVar13;
              ppppppuStack_160 = pppppppuVar13[1];
            }
            else {
              uVar10 = local_128 | 0xf;
              uVar16 = 0x7fffffffffffffff;
              if ((uVar10 < 0x8000000000000000) && (uVar16 = uVar10, uVar10 < 0x16)) {
                uVar16 = 0x16;
              }
              local_168 = FUN_18001d210(&local_168,uVar16 + 1);
              local_158 = uVar5;
              uStack_150 = uVar16;
              memcpy(local_168,pppppppuVar13,uVar5 + 1);
            }
            local_148 = plVar8;
            local_140 = lVar4;
            FUN_180008240(plVar17,&local_1d8,&local_168);
            if (0xf < uStack_150) {
              ppppppuVar11 = local_168;
              if ((0xfff < uStack_150 + 1) &&
                 (ppppppuVar11 = (undefined8 ******)local_168[-1],
                 0x1f < (ulonglong)((longlong)local_168 + (-8 - (longlong)ppppppuVar11)))) {
LAB_180013a39:
                    /* WARNING: Subroutine does not return */
                _invalid_parameter_noinfo_noreturn();
              }
              FUN_180035134(ppppppuVar11);
            }
          }
          break;
        }
        puVar3 = (undefined8 *)puVar2[2];
        if (*(char *)((longlong)puVar3 + 0x19) == '\0') {
          cVar1 = *(char *)((longlong)*puVar3 + 0x19);
          puVar2 = puVar3;
          puVar3 = (undefined8 *)*puVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((longlong)*puVar3 + 0x19);
            puVar2 = puVar3;
            puVar3 = (undefined8 *)*puVar3;
          }
        }
        else {
          cVar1 = *(char *)((longlong)puVar2[1] + 0x19);
          puVar6 = (undefined8 *)puVar2[1];
          puVar3 = puVar2;
          while ((puVar2 = puVar6, cVar1 == '\0' && (puVar3 == (undefined8 *)puVar2[2]))) {
            cVar1 = *(char *)((longlong)puVar2[1] + 0x19);
            puVar6 = (undefined8 *)puVar2[1];
            puVar3 = puVar2;
          }
        }
      }
      if (0xf < uStack_100) {
        pvVar12 = local_118;
        if ((0xfff < uStack_100 + 1) &&
           (pvVar12 = *(void **)((longlong)local_118 + -8),
           0x1f < (ulonglong)((longlong)local_118 + (-8 - (longlong)pvVar12)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        FUN_180035134(pvVar12);
      }
      if (plVar8 != (longlong *)0x0) {
        (**(code **)(*plVar8 + 0x10))(plVar8);
      }
      if (0xf < local_120) {
        pppppppuVar13 = local_138;
        if ((0xfff < local_120 + 1) &&
           (pppppppuVar13 = (undefined8 *******)local_138[-1],
           0x1f < (ulonglong)((longlong)local_138 + (-8 - (longlong)pppppppuVar13)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        FUN_180035134(pppppppuVar13);
      }
    }
  }
  return;
}

/* RVA 0x13b10 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_180013b10(longlong param_1,LPCSTR param_2,DWORD param_3)

{
  char cVar1;
  IStorage *pIVar2;
  code *pcVar3;
  longlong *plVar4;
  undefined1 uVar5;
  HRESULT HVar6;
  int iVar7;
  longlong lVar8;
  ulonglong uVar9;
  LPCWSTR ***ppppWVar10;
  FILE *_File;
  LPCSTR pCVar11;
  longlong lVar12;
  undefined8 uVar13;
  _GUID *p_Var14;
  void *pvVar15;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar16;
  IAtlStringMgr *pIVar17;
  char *pcVar18;
  BSTR bstrString;
  undefined8 *puVar19;
  ulonglong uVar20;
  LPCWSTR ***ppppWVar21;
  int iVar22;
  ulonglong uVar23;
  byte bVar24;
  undefined1 *puVar25;
  undefined1 *puVar26;
  undefined1 *puVar27;
  undefined1 *puVar28;
  undefined1 *puVar29;
  undefined2 *puVar30;
  WCHAR *pwcsName;
  ulonglong uVar31;
  short *psVar32;
  undefined1 *puVar33;
  char *pcVar34;
  size_t sVar35;
  size_t sVar36;
  undefined8 uStack_1e0;
  undefined1 auStack_1d8 [32];
  undefined8 uStack_1b8;
  int aiStack_1b0 [6];
  undefined2 local_198 [4];
  LPCSTR local_190;
  LPCSTR local_188;
  DWORD local_180 [2];
  longlong *local_178;
  void *local_170;
  undefined8 local_168;
  undefined8 local_160;
  _union_2707 local_158;
  _union_2707 local_140;
  undefined1 local_128;
  longlong local_120;
  undefined8 local_118;
  _union_1719 _Stack_110;
  undefined8 local_108;
  LPCWSTR ***local_f8;
  undefined8 uStack_f0;
  ulonglong local_e8;
  ulonglong local_e0;
  LPCWSTR ***local_d8;
  _struct_1720 _Stack_d0;
  ulonglong local_c8;
  ulonglong uStack_c0;
  LPCWSTR ***local_b8;
  _struct_1720 _Stack_b0;
  ulonglong local_a8;
  ulonglong uStack_a0;
  LPCWSTR ***local_98;
  _struct_1720 _Stack_90;
  ulonglong local_88;
  ulonglong uStack_80;
  LPCWSTR ***local_78;
  _union_1719 _Stack_70;
  ulonglong local_68;
  ulonglong uStack_60;
  char local_58;
  char local_57 [15];
  undefined1 local_48;
  ulonglong local_40;
  
  local_40 = DAT_180052888 ^ (ulonglong)local_198;
  local_180[0] = param_3;
  local_190 = param_2;
  local_178 = (longlong *)((ulonglong)local_178 & 0xffffffff00000000);
  local_168 = (longlong *)((ulonglong)local_168 & 0xffffffff00000000);
  local_160 = 0;
  local_120 = param_1;
  if (param_1 != 0) {
    local_128 = *(undefined1 *)(param_1 + 200);
  }
  local_198[0]._0_1_ = local_128;
  *(undefined1 *)(param_1 + 0xab) = 0;
  _Stack_d0.Lo32 = 0;
  _Stack_d0.Mid32 = 0;
  local_c8 = 0;
  uStack_c0 = 0xf;
  local_d8 = (LPCWSTR ***)0x0;
  _Stack_90.Lo32 = 0;
  _Stack_90.Mid32 = 0;
  local_88 = _DAT_180041f70;
  uStack_80 = _UNK_180041f78;
  local_98 = (LPCWSTR ***)0x0;
  sVar36 = 0xffffffffffffffff;
  puVar27 = auStack_1d8;
  if (param_2 == (LPCSTR)0x0) {
LAB_180013c47:
    puVar30 = (undefined2 *)0x0;
  }
  else {
    lVar8 = -1;
    do {
      lVar12 = lVar8;
      lVar8 = lVar12 + 1;
    } while (param_2[lVar8] != '\0');
    iVar22 = (int)lVar12 + 2;
    puVar27 = auStack_1d8;
    if (0x3fffffff < iVar22) goto LAB_180013c47;
    lVar8 = (longlong)(int)lVar8 * 2;
    uVar20 = lVar8 + 0x11;
    if (uVar20 <= lVar8 + 2U) {
      uVar20 = 0xffffffffffffff0;
    }
    uStack_1e0 = 0x180013c16;
    lVar8 = -(uVar20 & 0xfffffffffffffff0);
    puVar27 = auStack_1d8 + lVar8;
    puVar30 = (undefined2 *)((longlong)local_198 + lVar8);
    if (puVar30 == (undefined2 *)0x0) goto LAB_180013c47;
    *puVar30 = 0;
    *(int *)((longlong)aiStack_1b0 + lVar8) = iVar22;
    *(undefined2 **)(auStack_1d8 + lVar8 + 0x20) = puVar30;
    *(undefined8 *)(auStack_1d8 + lVar8 + -8) = 0x180013c3f;
    iVar22 = MultiByteToWideChar(0,0,param_2,-1,*(LPWSTR *)(auStack_1d8 + lVar8 + 0x20),
                                 *(int *)((longlong)aiStack_1b0 + lVar8));
    puVar27 = auStack_1d8 + lVar8;
    if (iVar22 == 0) {
      puVar30 = (undefined2 *)0x0;
      puVar27 = auStack_1d8 + lVar8;
    }
  }
  local_f8 = (LPCWSTR ***)0x0;
  uStack_f0 = 0;
  local_e8 = 0;
  local_e0 = 0;
  uVar20 = 0xffffffffffffffff;
  do {
    uVar20 = uVar20 + 1;
  } while (puVar30[uVar20] != 0);
  *(undefined8 *)(puVar27 + -8) = 0x180013c7f;
  FUN_180006f50(&local_f8,puVar30,uVar20);
  uVar20 = local_e8;
  _Stack_b0.Lo32 = 0;
  _Stack_b0.Mid32 = 0;
  local_a8 = _DAT_180041f60;
  uStack_a0 = _UNK_180041f68;
  local_b8 = (LPCWSTR ***)0x0;
  ppppWVar10 = (LPCWSTR ***)&local_f8;
  if (7 < local_e0) {
    ppppWVar10 = local_f8;
  }
  if (local_e8 != 0) {
    uVar9 = local_e8;
    ppppWVar21 = ppppWVar10;
    do {
      if (*(short *)ppppWVar21 == 0x7c) {
        if ((ppppWVar21 != (LPCWSTR ***)0x0) &&
           (uVar9 = (longlong)ppppWVar21 - (longlong)ppppWVar10 >> 1, uVar9 != 0xffffffffffffffff))
        goto LAB_180013dc6;
        break;
      }
      ppppWVar21 = (LPCWSTR ***)((longlong)ppppWVar21 + 2);
      uVar9 = uVar9 - 1;
    } while (uVar9 != 0);
  }
  ppppWVar10 = (LPCWSTR ***)&local_f8;
  if (7 < local_e0) {
    ppppWVar10 = local_f8;
  }
  if (local_e8 != 0) {
    uVar9 = local_e8;
    ppppWVar21 = ppppWVar10;
    do {
      if (*(short *)ppppWVar21 == 0x3e) {
        if ((ppppWVar21 != (LPCWSTR ***)0x0) &&
           (uVar9 = (longlong)ppppWVar21 - (longlong)ppppWVar10 >> 1, uVar9 != 0xffffffffffffffff))
        goto LAB_180013dc6;
        break;
      }
      ppppWVar21 = (LPCWSTR ***)((longlong)ppppWVar21 + 2);
      uVar9 = uVar9 - 1;
    } while (uVar9 != 0);
  }
  puVar29 = puVar27;
  if (param_2 == (LPCSTR)0x0) {
LAB_180013fe3:
    pwcsName = (WCHAR *)0x0;
    puVar27 = puVar29;
  }
  else {
    lVar8 = -1;
    do {
      lVar12 = lVar8;
      lVar8 = lVar12 + 1;
    } while (param_2[lVar8] != '\0');
    iVar22 = (int)lVar12 + 2;
    if (0x3fffffff < iVar22) goto LAB_180013fe3;
    lVar8 = (longlong)(int)lVar8 * 2;
    uVar20 = lVar8 + 0x11;
    if (uVar20 <= lVar8 + 2U) {
      uVar20 = 0xffffffffffffff0;
    }
    *(undefined8 *)(puVar27 + -8) = 0x180013d73;
    lVar8 = -(uVar20 & 0xfffffffffffffff0);
    puVar29 = puVar27 + lVar8;
    puVar25 = puVar27 + lVar8;
    pwcsName = (WCHAR *)(puVar27 + lVar8 + 0x40);
    if (pwcsName == (WCHAR *)0x0) goto LAB_180013fe3;
    *pwcsName = L'\0';
    *(int *)(puVar27 + lVar8 + 0x28) = iVar22;
    *(WCHAR **)(puVar27 + lVar8 + 0x20) = pwcsName;
    *(undefined8 *)(puVar27 + lVar8 + -8) = 0x180013da2;
    iVar22 = MultiByteToWideChar(0,0,param_2,-1,*(LPWSTR *)(puVar27 + lVar8 + 0x20),
                                 *(int *)(puVar27 + lVar8 + 0x28));
    puVar27 = puVar27 + lVar8;
    if (iVar22 == 0) {
      pwcsName = (WCHAR *)0x0;
      puVar27 = puVar25;
    }
  }
  *(undefined8 *)(puVar27 + -8) = 0x180013ff0;
  HVar6 = StgIsStorageFile(pwcsName);
  if (HVar6 == 0) {
    *(undefined1 *)(param_1 + 0xab) = 1;
    goto LAB_1800140f0;
  }
  *(undefined8 *)(puVar27 + -8) = 0x18001400e;
  pcVar18 = strrchr(param_2,0x2e);
  if (pcVar18 == (char *)0x0) goto LAB_1800140f0;
  *(undefined8 *)(puVar27 + -8) = 0x180014028;
  iVar22 = _stricmp(pcVar18 + 1,"bkp");
  if (iVar22 != 0) goto LAB_1800140f0;
  *(undefined8 *)(puVar27 + -8) = 0x180014040;
  _File = fopen(param_2,"rb");
  if (_File != (FILE *)0x0) {
    local_48 = 0;
    *(undefined8 *)(puVar27 + -8) = 0x18001406c;
    sVar35 = fread(&local_58,1,0x10,_File);
    if ((sVar35 < 5) || (pcVar18 = &local_58, local_58 == '\0')) {
LAB_180014199:
      *(undefined8 *)(puVar27 + -8) = 0x1800141a2;
      fclose(_File);
      if (sVar35 == 0) goto LAB_1800140f0;
    }
    else {
      do {
        if (local_58 != ' ') {
          *(undefined8 *)(puVar27 + -8) = 0x1800140c3;
          iVar22 = strncmp(pcVar18,"MM",2);
          if (iVar22 != 0) {
            *(undefined8 *)(puVar27 + -8) = 0x1800140dd;
            iVar22 = strncmp(pcVar18,"ASPEN",5);
            if (iVar22 != 0) goto LAB_180014199;
          }
          *(undefined8 *)(puVar27 + -8) = 0x1800140ee;
          fclose(_File);
          goto LAB_1800140f0;
        }
        pcVar18 = pcVar18 + 1;
        local_58 = *pcVar18;
      } while (local_58 != '\0');
      *(undefined8 *)(puVar27 + -8) = 0x1800140a8;
      fclose(_File);
    }
  }
  *(undefined8 *)(puVar27 + -8) = 0x1800141b6;
  GRsetInvalidFormat(1);
  *(undefined8 *)(puVar27 + -8) = 0x1800141c1;
  pCVar11 = (LPCSTR)GetSorResStringEx(0x577);
  *(undefined8 *)(puVar27 + -8) = 0x1800141c9;
  FUN_180011410(pCVar11);
  goto LAB_1800141ca;
LAB_180013dc6:
  *(undefined1 *)(param_1 + 0xaa) = 1;
  uVar23 = uVar9 + 1;
  local_78 = (LPCWSTR ***)0x0;
  _Stack_70.Lo64 = 0;
  if (local_e8 < uVar23) {
                    /* WARNING: Subroutine does not return */
    *(undefined **)(puVar27 + -8) = &UNK_18001501f;
    FUN_18001d1f0();
  }
  uVar31 = 0xffffffffffffffff;
  if (local_e8 - uVar23 != 0xffffffffffffffff) {
    uVar31 = local_e8 - uVar23;
  }
  ppppWVar10 = (LPCWSTR ***)&local_f8;
  if (7 < local_e0) {
    ppppWVar10 = local_f8;
  }
  psVar32 = (short *)((longlong)ppppWVar10 + uVar23 * 2);
  if (0x7ffffffffffffffe < uVar31) {
                    /* WARNING: Subroutine does not return */
    *(undefined **)(puVar27 + -8) = &UNK_180015025;
    FUN_18001d1b0();
  }
  local_68 = uVar31;
  if (uVar31 < 8) {
    uStack_60 = 7;
    *(undefined8 *)(puVar27 + -8) = 0x180013e48;
    memcpy(&local_78,psVar32,uVar31 * 2);
    (local_57 + (uVar31 * 2 - 0x21))[0] = '\0';
    (local_57 + (uVar31 * 2 - 0x21))[1] = '\0';
  }
  else {
    uVar23 = uVar31 | 7;
    uVar20 = 0x7ffffffffffffffe;
    if ((uVar23 < 0x7fffffffffffffff) && (uVar20 = uVar23, uVar23 < 10)) {
      uVar20 = 10;
    }
    *(undefined8 *)(puVar27 + -8) = 0x180013e81;
    ppppWVar10 = FUN_18001d2e0(&local_78,uVar20 + 1);
    local_78 = ppppWVar10;
    uStack_60 = uVar20;
    *(undefined8 *)(puVar27 + -8) = 0x180013eaa;
    memcpy(ppppWVar10,psVar32,uVar31 * 2);
    pcVar18 = (char *)((longlong)ppppWVar10 + uVar31 * 2);
    pcVar18[0] = '\0';
    pcVar18[1] = '\0';
    uVar20 = local_e8;
  }
  local_178 = (longlong *)CONCAT44(local_178._4_4_,1);
  if (7 < uStack_a0) {
    ppppWVar10 = local_b8;
    if ((0xfff < uStack_a0 * 2 + 2) &&
       (ppppWVar10 = (LPCWSTR ***)local_b8[-1],
       (char *)0x1f < (char *)((longlong)local_b8 + (-8 - (longlong)ppppWVar10))))
    goto LAB_1800144f6;
    *(undefined8 *)(puVar27 + -8) = 0x180013f07;
    FUN_180035134(ppppWVar10);
    uVar20 = local_e8;
  }
  local_b8 = local_78;
  _Stack_b0 = _Stack_70.s2;
  local_a8 = local_68;
  uStack_a0 = uStack_60;
  param_2 = local_190;
  param_3 = local_180[0];
  if (uVar20 < uVar9) {
    uVar23 = uVar9 - uVar20;
    if (local_e0 - uVar20 < uVar23) {
      *(undefined2 *)(puVar27 + 0x20) = 0;
      *(undefined8 *)(puVar27 + -8) = 0x180013fd6;
      FUN_180007fd0(&local_f8,uVar23,0,uVar23,*(undefined2 *)(puVar27 + 0x20));
      param_2 = local_190;
      param_3 = local_180[0];
    }
    else {
      local_e8 = uVar9;
      ppppWVar10 = (LPCWSTR ***)&local_f8;
      if (7 < local_e0) {
        ppppWVar10 = local_f8;
      }
      if (uVar23 != 0) {
        psVar32 = (short *)((longlong)ppppWVar10 + uVar20 * 2);
        for (uVar9 = uVar23; uVar9 != 0; uVar9 = uVar9 - 1) {
          *psVar32 = 0;
          psVar32 = psVar32 + 1;
        }
      }
      *(short *)((longlong)ppppWVar10 + (uVar23 + uVar20) * 2) = 0;
    }
  }
  else {
    local_e8 = uVar9;
    ppppWVar10 = (LPCWSTR ***)&local_f8;
    if (7 < local_e0) {
      ppppWVar10 = local_f8;
    }
    *(short *)((longlong)ppppWVar10 + uVar9 * 2) = 0;
  }
LAB_1800140f0:
  ppppWVar10 = (LPCWSTR ***)&local_f8;
  puVar29 = puVar27;
  if ((local_e0 < 8) || (ppppWVar10 = local_f8, local_f8 != (LPCWSTR ***)0x0)) {
    lVar8 = -1;
    do {
      lVar12 = lVar8;
      lVar8 = lVar12 + 1;
    } while (*(short *)((longlong)ppppWVar10 + lVar8 * 2) != 0);
    iVar22 = (int)lVar12 + 2;
    if (0x3fffffff < iVar22) goto LAB_180014358;
    lVar8 = (longlong)(int)lVar8 * 2;
    uVar20 = lVar8 + 0x11;
    if (uVar20 <= lVar8 + 2U) {
      uVar20 = 0xffffffffffffff0;
    }
    *(undefined8 *)(puVar27 + -8) = 0x180014157;
    lVar8 = -(uVar20 & 0xfffffffffffffff0);
    puVar29 = puVar27 + lVar8;
    puVar26 = puVar27 + lVar8;
    puVar33 = puVar27 + lVar8 + 0x40;
    if (puVar33 == (undefined1 *)0x0) goto LAB_180014358;
    *puVar33 = 0;
    *(undefined8 *)(puVar27 + lVar8 + 0x38) = 0;
    *(undefined8 *)(puVar27 + lVar8 + 0x30) = 0;
    *(int *)(puVar27 + lVar8 + 0x28) = iVar22 * 2;
    *(undefined1 **)(puVar27 + lVar8 + 0x20) = puVar33;
    *(undefined8 *)(puVar27 + lVar8 + -8) = 0x18001418e;
    iVar22 = WideCharToMultiByte(0,0,(LPCWSTR)ppppWVar10,-1,*(LPSTR *)(puVar27 + lVar8 + 0x20),
                                 *(int *)(puVar27 + lVar8 + 0x28),
                                 *(LPCSTR *)(puVar27 + lVar8 + 0x30),
                                 *(LPBOOL *)(puVar27 + lVar8 + 0x38));
    puVar27 = puVar27 + lVar8;
    if (iVar22 == 0) {
      puVar33 = (undefined1 *)0x0;
      puVar27 = puVar26;
    }
  }
  else {
LAB_180014358:
    puVar33 = (undefined1 *)0x0;
    puVar27 = puVar29;
  }
  local_78 = (LPCWSTR ***)0x0;
  _Stack_70.Lo64 = 0;
  local_68 = 0;
  uStack_60 = 0;
  sVar35 = 0xffffffffffffffff;
  do {
    sVar35 = sVar35 + 1;
  } while (puVar33[sVar35] != '\0');
  *(undefined8 *)(puVar27 + -8) = 0x18001438c;
  FUN_180006e90(&local_78,puVar33,sVar35);
  if (0xf < uStack_c0) {
    ppppWVar10 = local_d8;
    if ((0xfff < uStack_c0 + 1) &&
       (ppppWVar10 = (LPCWSTR ***)local_d8[-1],
       (char *)0x1f < (char *)((longlong)local_d8 + (-8 - (longlong)ppppWVar10))))
    goto LAB_1800144f6;
    *(undefined8 *)(puVar27 + -8) = 0x1800143cd;
    FUN_180035134(ppppWVar10);
  }
  local_d8 = local_78;
  _Stack_d0 = _Stack_70.s2;
  local_c8 = local_68;
  uStack_c0 = uStack_60;
  ppppWVar10 = (LPCWSTR ***)&local_b8;
  puVar29 = puVar27;
  if ((uStack_a0 < 8) || (ppppWVar10 = local_b8, local_b8 != (LPCWSTR ***)0x0)) {
    lVar8 = -1;
    do {
      lVar12 = lVar8;
      lVar8 = lVar12 + 1;
    } while (*(short *)((longlong)ppppWVar10 + lVar8 * 2) != 0);
    iVar22 = (int)lVar12 + 2;
    if (0x3fffffff < iVar22) goto LAB_18001448a;
    lVar8 = (longlong)(int)lVar8 * 2;
    uVar20 = lVar8 + 0x11;
    if (uVar20 <= lVar8 + 2U) {
      uVar20 = 0xffffffffffffff0;
    }
    *(undefined8 *)(puVar27 + -8) = 0x18001444f;
    lVar8 = -(uVar20 & 0xfffffffffffffff0);
    puVar29 = puVar27 + lVar8;
    puVar28 = puVar27 + lVar8;
    puVar33 = puVar27 + lVar8 + 0x40;
    if (puVar33 == (undefined1 *)0x0) goto LAB_18001448a;
    *puVar33 = 0;
    *(undefined8 *)(puVar27 + lVar8 + 0x38) = 0;
    *(undefined8 *)(puVar27 + lVar8 + 0x30) = 0;
    *(int *)(puVar27 + lVar8 + 0x28) = iVar22 * 2;
    *(undefined1 **)(puVar27 + lVar8 + 0x20) = puVar33;
    *(undefined8 *)(puVar27 + lVar8 + -8) = 0x180014482;
    iVar22 = WideCharToMultiByte(0,0,(LPCWSTR)ppppWVar10,-1,*(LPSTR *)(puVar27 + lVar8 + 0x20),
                                 *(int *)(puVar27 + lVar8 + 0x28),
                                 *(LPCSTR *)(puVar27 + lVar8 + 0x30),
                                 *(LPBOOL *)(puVar27 + lVar8 + 0x38));
    puVar27 = puVar27 + lVar8;
    if (iVar22 == 0) {
      puVar33 = (undefined1 *)0x0;
      puVar27 = puVar28;
    }
  }
  else {
LAB_18001448a:
    puVar33 = (undefined1 *)0x0;
    puVar27 = puVar29;
  }
  local_78 = (LPCWSTR ***)0x0;
  _Stack_70.Lo64 = 0;
  local_68 = 0;
  uStack_60 = 0;
  sVar35 = 0xffffffffffffffff;
  do {
    sVar35 = sVar35 + 1;
  } while (puVar33[sVar35] != '\0');
  *(undefined8 *)(puVar27 + -8) = 0x1800144be;
  FUN_180006e90(&local_78,puVar33,sVar35);
  if (0xf < uStack_80) {
    ppppWVar10 = local_98;
    if ((0xfff < uStack_80 + 1) &&
       (ppppWVar10 = (LPCWSTR ***)local_98[-1],
       (char *)0x1f < (char *)((longlong)local_98 + (-8 - (longlong)ppppWVar10)))) {
LAB_1800144f6:
                    /* WARNING: Subroutine does not return */
      *(undefined **)(puVar27 + -8) = &UNK_1800144fc;
      _invalid_parameter_noinfo_noreturn();
    }
    *(undefined8 *)(puVar27 + -8) = 0x180014502;
    FUN_180035134(ppppWVar10);
  }
  local_98 = local_78;
  _Stack_90 = _Stack_70.s2;
  local_88 = local_68;
  uStack_80 = uStack_60;
  *(undefined8 *)(puVar27 + -8) = 0x180014528;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_188);
  ppppWVar10 = (LPCWSTR ***)&local_d8;
  if (0xf < uStack_c0) {
    ppppWVar10 = local_d8;
  }
  *(undefined8 *)(puVar27 + -8) = 0x180014545;
  iVar22 = MMGetSuppress();
  *(LPCSTR **)(puVar27 + 0x20) = &local_188;
  *(undefined8 *)(puVar27 + -8) = 0x18001455e;
  uVar13 = FUN_180009bf0(param_1,iVar22,0,(char *)ppppWVar10,
                         *(CSimpleStringT<char,1> **)(puVar27 + 0x20));
  if ((int)uVar13 == -1) {
    *(undefined8 *)(puVar27 + -8) = 0x180014eab;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_188);
    if (7 < uStack_a0) {
      ppppWVar10 = local_b8;
      if ((0xfff < uStack_a0 * 2 + 2) &&
         (ppppWVar10 = (LPCWSTR ***)local_b8[-1],
         (char *)0x1f < (char *)((longlong)local_b8 + (-8 - (longlong)ppppWVar10))))
      goto LAB_180014ee9;
      *(undefined8 *)(puVar27 + -8) = 0x180014ef5;
      FUN_180035134(ppppWVar10);
    }
    local_a8 = _DAT_180041f60;
    uStack_a0 = _UNK_180041f68;
    local_b8 = (LPCWSTR ***)((ulonglong)local_b8 & 0xffffffffffff0000);
    if (7 < local_e0) {
      ppppWVar10 = local_f8;
      if ((0xfff < local_e0 * 2 + 2) &&
         (ppppWVar10 = (LPCWSTR ***)local_f8[-1],
         0x1f < (ulonglong)((longlong)local_f8 + (-8 - (longlong)ppppWVar10)))) goto LAB_180014f49;
      *(undefined8 *)(puVar27 + -8) = 0x180014f55;
      FUN_180035134(ppppWVar10);
    }
    local_e8 = 0;
    local_e0 = 7;
    local_f8 = (LPCWSTR ***)((ulonglong)local_f8 & 0xffffffffffff0000);
    if (0xf < uStack_80) {
      ppppWVar10 = local_98;
      if ((0xfff < uStack_80 + 1) &&
         (ppppWVar10 = (LPCWSTR ***)local_98[-1],
         (char *)0x1f < (char *)((longlong)local_98 + (-8 - (longlong)ppppWVar10))))
      goto LAB_180014fa6;
      *(undefined8 *)(puVar27 + -8) = 0x180014fb2;
      FUN_180035134(ppppWVar10);
    }
    local_88 = _DAT_180041f70;
    uStack_80 = _UNK_180041f78;
    local_98 = (LPCWSTR ***)((ulonglong)local_98 & 0xffffffffffffff00);
    if (0xf < uStack_c0) {
      ppppWVar10 = local_d8;
      if (0xfff < uStack_c0 + 1) {
        ppppWVar10 = (LPCWSTR ***)local_d8[-1];
        lVar8 = (longlong)local_d8 - (longlong)ppppWVar10;
joined_r0x000180015007:
        if (0x1f < lVar8 - 8U) goto LAB_18001500d;
      }
LAB_18001431c:
      _UNK_180041f78 = uStack_80;
      _DAT_180041f70 = local_88;
      *(undefined8 *)(puVar27 + -8) = 0x180014321;
      FUN_180035134(ppppWVar10);
    }
  }
  else {
    if ((int)uVar13 == 1) {
      *(undefined8 *)(puVar27 + -8) = 0x180014d17;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0xa0),
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 &local_188);
      *(undefined8 *)(puVar27 + -8) = 0x180014d29;
      uVar5 = FUN_180013b10(param_1,local_188,1);
      *(undefined8 *)(puVar27 + -8) = 0x180014d36;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_188);
      if (7 < uStack_a0) {
        ppppWVar10 = local_b8;
        if ((0xfff < uStack_a0 * 2 + 2) &&
           (ppppWVar10 = (LPCWSTR ***)local_b8[-1],
           (char *)0x1f < (char *)((longlong)local_b8 + (-8 - (longlong)ppppWVar10))))
        goto LAB_180014ee9;
        *(undefined8 *)(puVar27 + -8) = 0x180014d7d;
        FUN_180035134(ppppWVar10);
      }
      local_a8 = _DAT_180041f60;
      uStack_a0 = _UNK_180041f68;
      local_b8 = (LPCWSTR ***)((ulonglong)local_b8 & 0xffffffffffff0000);
      if (7 < local_e0) {
        ppppWVar10 = local_f8;
        if ((0xfff < local_e0 * 2 + 2) &&
           (ppppWVar10 = (LPCWSTR ***)local_f8[-1],
           0x1f < (ulonglong)((longlong)local_f8 + (-8 - (longlong)ppppWVar10))))
        goto LAB_180014f49;
        *(undefined8 *)(puVar27 + -8) = 0x180014dda;
        FUN_180035134(ppppWVar10);
      }
      local_e8 = 0;
      local_e0 = 7;
      local_f8 = (LPCWSTR ***)((ulonglong)local_f8 & 0xffffffffffff0000);
      if (0xf < uStack_80) {
        ppppWVar10 = local_98;
        if ((0xfff < uStack_80 + 1) &&
           (ppppWVar10 = (LPCWSTR ***)local_98[-1],
           (char *)0x1f < (char *)((longlong)local_98 + (-8 - (longlong)ppppWVar10))))
        goto LAB_180014fa6;
        *(undefined8 *)(puVar27 + -8) = 0x180014e34;
        FUN_180035134(ppppWVar10);
      }
      local_88 = _DAT_180041f70;
      uStack_80 = _UNK_180041f78;
      local_98 = (LPCWSTR ***)((ulonglong)local_98 & 0xffffffffffffff00);
      if (0xf < uStack_c0) {
        ppppWVar10 = local_d8;
        if ((0xfff < uStack_c0 + 1) &&
           (ppppWVar10 = (LPCWSTR ***)local_d8[-1],
           (char *)0x1f < (char *)((longlong)local_d8 + (-8 - (longlong)ppppWVar10))))
        goto LAB_18001500d;
        *(undefined8 *)(puVar27 + -8) = 0x180014e8c;
        FUN_180035134(ppppWVar10);
      }
      *(undefined1 *)(param_1 + 200) = (undefined1)local_198[0];
      goto LAB_18001432f;
    }
    bVar24 = 1;
    *(undefined8 *)(puVar27 + -8) = 0x180014577;
    iVar22 = HappInitted();
    if (iVar22 == 0) {
      bVar24 = 0;
      *(undefined8 *)(puVar27 + -8) = 0x180014593;
      StgCreateDocfile((WCHAR *)0x0,0x4011012,0,(IStorage **)(param_1 + 8));
      uVar13 = *(undefined8 *)(param_1 + 8);
      *(undefined8 *)(puVar27 + -8) = 0x1800145a0;
      iVar7 = NewHapp(uVar13,&local_160);
      if (iVar7 == 0) {
        *(undefined8 *)(puVar27 + -8) = 0x1800145ae;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_188);
        goto LAB_1800141ca;
      }
      pIVar2 = *(IStorage **)(param_1 + 8);
      *(undefined8 *)(puVar27 + -8) = 0x1800145bf;
      p_Var14 = (_GUID *)FUN_18000c750();
      *(undefined8 *)(puVar27 + -8) = 0x1800145cb;
      pvVar15 = CreateApwnContextDocument(pIVar2,p_Var14);
      *(void **)(param_1 + 0xb0) = pvVar15;
      *(undefined8 *)(puVar27 + -8) = 0x1800145e4;
      SetGlobalPointer("ApwnOleServerDoc",pvVar15,0);
    }
    ppppWVar10 = (LPCWSTR ***)&local_d8;
    if (0xf < uStack_c0) {
      ppppWVar10 = local_d8;
    }
    local_180[0] = param_3;
    *(undefined8 *)(puVar27 + -8) = 0x180014609;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_170,
               (char *)ppppWVar10);
    if (param_3 == 0xffffffff) {
      *(undefined8 *)(puVar27 + -8) = 0x18001461e;
      pCVar16 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_190,
                           (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                            *)&local_170);
      *(undefined8 *)(puVar27 + -8) = 0x18001462d;
      FUN_18000caa0(param_1,(int *)local_180,pCVar16);
      param_3 = local_180[0];
    }
    ppppWVar10 = (LPCWSTR ***)&local_d8;
    if (0xf < uStack_c0) {
      ppppWVar10 = local_d8;
    }
    *(undefined8 *)(puVar27 + -8) = 0x180014653;
    FUN_1800169a0(param_1,(char *)ppppWVar10,param_3);
    if (param_3 != 3) {
LAB_1800146c7:
      *(byte *)(param_1 + 0xa9) = bVar24 ^ 1;
      ppppWVar10 = (LPCWSTR ***)&local_d8;
      if (0xf < uStack_c0) {
        ppppWVar10 = local_d8;
      }
      if (bVar24 == 0) {
        if (iVar22 == 0) {
          *(undefined8 *)(puVar27 + -8) = 0x180014733;
          FUN_18000f590(param_1);
          *(undefined8 *)(puVar27 + -8) = 0x18001473d;
          FUN_18000a9c0(param_1,'\0');
          if (*(char *)(param_1 + 0xab) == '\0') {
            *(undefined8 *)(puVar27 + -8) = 0x18001476d;
            iVar22 = OpenHappArchive(ppppWVar10);
            if (iVar22 != 0) goto LAB_180014781;
            *(undefined8 *)(puVar27 + -8) = 0x180014776;
            SimExit();
            *(undefined8 *)(param_1 + 0x38) = 0;
            uVar5 = false;
          }
          else {
            *(undefined8 *)(puVar27 + -8) = 0x180014751;
            iVar22 = OpenHappArchiveStg(0,ppppWVar10);
            if (iVar22 == 0) {
              *(undefined8 *)(puVar27 + -8) = 0x18001475a;
              SimExit();
              *(undefined8 *)(param_1 + 0x38) = 0;
              uVar5 = false;
            }
            else {
LAB_180014781:
              *(undefined8 *)(puVar27 + -8) = 0x180014786;
              FUN_180033bd0();
              *(undefined8 *)(puVar27 + -8) = 0x180014792;
              lVar8 = GetGlobalPointer("CompoundFileName");
              if (lVar8 != 0) {
                *(undefined8 *)(puVar27 + -8) = 0x18001479f;
                HappUpdateMoniker(lVar8);
              }
              *(undefined8 *)(puVar27 + -8) = 0x1800147ab;
              lVar8 = GetGlobalPointer("CompoundFileName");
              if (lVar8 != 0) {
                *(undefined8 *)(puVar27 + -8) = 0x1800147b5;
                FUN_1800265e0();
              }
              uVar5 = true;
            }
          }
        }
        else {
          uVar5 = false;
        }
        uVar20 = local_c8;
        if ((LPCWSTR ****)(param_1 + 0x60) != &local_d8) {
          ppppWVar10 = (LPCWSTR ***)&local_d8;
          if (0xf < uStack_c0) {
            ppppWVar10 = local_d8;
          }
          *(undefined8 *)(puVar27 + -8) = 0x1800147f0;
          FUN_18001d350((longlong *)(param_1 + 0x60),ppppWVar10,uVar20);
        }
      }
      else {
        *(undefined8 *)(puVar27 + -8) = 0x1800146f9;
        GRsetImportForPSV(1);
        *(undefined8 *)(puVar27 + -8) = 0x180014701;
        iVar22 = RestoreHappArchive(ppppWVar10);
        uVar5 = iVar22 != 0;
        *(undefined8 *)(puVar27 + -8) = 0x180014716;
        GRsetimportarchivestatus(iVar22 != 0);
      }
      pcVar34 = (char *)(param_1 + 0x60);
      pcVar18 = pcVar34;
      if (0xf < *(ulonglong *)(param_1 + 0x78)) {
        pcVar18 = *(char **)pcVar34;
      }
      pvVar15 = *(void **)(param_1 + 0xb0);
      *(undefined8 *)(puVar27 + -8) = 0x18001480a;
      ApwnContextDocumentSetFilename(pvVar15,pcVar18);
      if (*(char *)(param_1 + 0xa8) != '\0') {
        *(undefined1 *)(param_1 + 0xa8) = 0;
        *(undefined8 *)(puVar27 + -8) = 0x180014831;
        pCVar16 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             local_180,"EmergBackupFile");
        if (0xf < *(ulonglong *)(param_1 + 0x78)) {
          pcVar34 = *(char **)pcVar34;
        }
        *(undefined8 *)(puVar27 + -8) = 0x180014847;
        pIVar17 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                            (pCVar16);
        *(undefined8 *)(puVar27 + -8) = 0x180014854;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_190,
                   pIVar17);
        local_168 = (longlong *)(CONCAT44(local_168._4_4_,local_178._0_4_) | 2);
        if (pcVar34 == (char *)0x0) {
          lVar8 = 0;
        }
        else {
          lVar8 = -1;
          do {
            lVar8 = lVar8 + 1;
          } while (pcVar34[lVar8] != '\0');
        }
        pcVar18 = *(char **)pCVar16;
        *(int *)(puVar27 + 0x20) = (int)lVar8;
        iVar22 = *(int *)(pcVar18 + -0x10);
        *(undefined8 *)(puVar27 + -8) = 0x180014891;
        ATL::CSimpleStringT<char,1>::Concatenate
                  ((CSimpleStringT<char,1> *)&local_190,pcVar18,iVar22,pcVar34,
                   *(int *)(puVar27 + 0x20));
        *(undefined8 *)(puVar27 + -8) = 0x18001489c;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_180);
        pCVar11 = local_190;
        *(undefined8 *)(puVar27 + -8) = 0x1800148a6;
        pcVar18 = _strdup(pCVar11);
        *(undefined8 *)(puVar27 + -8) = 0x1800148b5;
        SimSendMainWndMessage(0x536,0,pcVar18);
        *(undefined8 *)(puVar27 + -8) = 0x1800148c0;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_190);
      }
      if (*(char *)(param_1 + 0xaa) == '\0') {
        ppppWVar10 = (LPCWSTR ***)&local_d8;
        if (0xf < uStack_c0) {
          ppppWVar10 = local_d8;
        }
        if (local_c8 == 0) {
LAB_180014a87:
          lVar8 = -1;
        }
        else {
          lVar8 = -1;
          if (local_c8 - 1 != -1) {
            lVar8 = local_c8 - 1;
          }
          ppppWVar21 = (LPCWSTR ***)(lVar8 + (longlong)ppppWVar10);
          cVar1 = *(char *)ppppWVar21;
          while (cVar1 != '\\') {
            if (ppppWVar21 == ppppWVar10) goto LAB_180014a87;
            ppppWVar21 = (LPCWSTR ***)((longlong)ppppWVar21 + -1);
            cVar1 = *(char *)ppppWVar21;
          }
          lVar8 = (longlong)ppppWVar21 - (longlong)ppppWVar10;
        }
        if (lVar8 == -1) {
          *(undefined8 *)(puVar27 + -8) = 0x180014b81;
          FUN_18001c5a0(param_1,param_2);
        }
        else {
          uVar20 = lVar8 + 1;
          local_78 = (LPCWSTR ***)0x0;
          _Stack_70.Lo64._0_4_ = 0;
          _Stack_70.Lo64._4_4_ = 0;
          local_68 = 0;
          uStack_60 = 0;
          if (local_c8 < uVar20) {
                    /* WARNING: Subroutine does not return */
            *(undefined8 *)(puVar27 + -8) = 0x180015019;
            FUN_18001d1f0();
          }
          if (local_c8 - uVar20 != 0xffffffffffffffff) {
            sVar36 = local_c8 - uVar20;
          }
          ppppWVar10 = (LPCWSTR ***)&local_d8;
          if (0xf < uStack_c0) {
            ppppWVar10 = local_d8;
          }
          *(undefined8 *)(puVar27 + -8) = 0x180014ae1;
          FUN_180006e90(&local_78,(char *)((longlong)ppppWVar10 + uVar20),sVar36);
          if (0xf < uStack_c0) {
            ppppWVar10 = local_d8;
            if ((0xfff < uStack_c0 + 1) &&
               (ppppWVar10 = (LPCWSTR ***)local_d8[-1],
               (char *)0x1f < (char *)((longlong)local_d8 + (-8 - (longlong)ppppWVar10)))) {
                    /* WARNING: Subroutine does not return */
              *(undefined **)(puVar27 + -8) = &UNK_180014b1f;
              _invalid_parameter_noinfo_noreturn();
            }
            *(undefined8 *)(puVar27 + -8) = 0x180014b25;
            FUN_180035134(ppppWVar10);
          }
          uVar20 = local_68;
          local_d8 = local_78;
          _Stack_d0 = _Stack_70.s2;
          local_c8 = local_68;
          uStack_c0 = uStack_60;
          if ((LPCWSTR ****)(param_1 + 0x40) != &local_d8) {
            ppppWVar10 = (LPCWSTR ***)&local_d8;
            if (0xf < uStack_60) {
              ppppWVar10 = local_78;
            }
            *(undefined8 *)(puVar27 + -8) = 0x180014b74;
            FUN_18001d350((longlong *)(param_1 + 0x40),ppppWVar10,uVar20);
          }
        }
      }
      else {
        ppppWVar10 = (LPCWSTR ***)&local_98;
        if (0xf < uStack_80) {
          ppppWVar10 = local_98;
        }
        *(undefined8 *)(puVar27 + -8) = 0x1800148f2;
        bstrString = SysAllocString(L"Data\\Setup\\Main\\Input\\RUN_CLASS");
        *(undefined8 *)(puVar27 + -8) = 0x1800148fa;
        puVar19 = (undefined8 *)HappGetTree();
        local_178 = (longlong *)0x0;
        if (puVar19 != (undefined8 *)0x0) {
          pcVar3 = *(code **)*puVar19;
          *(undefined8 *)(puVar27 + -8) = 0x18001491c;
          iVar22 = (*pcVar3)(puVar19,&DAT_180041858,&local_178);
          if (iVar22 < 0) {
            local_178 = (longlong *)0x0;
          }
        }
        plVar4 = local_178;
        if (local_178 != (longlong *)0x0) {
          local_168 = (longlong *)0x0;
          pcVar3 = *(code **)(*local_178 + 0x110);
          *(undefined8 *)(puVar27 + -8) = 0x18001494a;
          (*pcVar3)(plVar4,bstrString,&local_168);
          if (local_168 != (longlong *)0x0) {
            local_158._0_8_ = (LPCWSTR ***)0x0;
            local_158.decVal.u2 = (_union_1719)(_struct_1720)0x0;
            local_158._16_8_ = 0;
            *(undefined8 *)(puVar27 + -8) = 0x18001496e;
            VariantInit((VARIANTARG *)&local_158.n2);
            local_140.n2.vt = 0;
            *(undefined8 *)(puVar27 + -8) = 0x180014980;
            FUN_180008fd0((VARIANTARG *)&local_140.n2,(LPCSTR)ppppWVar10);
            plVar4 = local_168;
            local_118 = CONCAT62(local_140._2_6_,local_140.n2.vt);
            _Stack_110.s2 = (_struct_1720)local_140.decVal.u2;
            local_108 = local_140._16_8_;
            local_78 = (LPCWSTR ***)local_158._0_8_;
            _Stack_70.s2 = (_struct_1720)local_158.decVal.u2;
            local_68 = local_158._16_8_;
            pcVar3 = *(code **)(*local_168 + 0x70);
            *(undefined8 *)(puVar27 + -8) = 0x1800149c9;
            (*pcVar3)(plVar4,&local_78,&local_118);
            *(undefined8 *)(puVar27 + -8) = 0x1800149d4;
            VariantClear((VARIANTARG *)&local_140.n2);
            *(undefined8 *)(puVar27 + -8) = 0x1800149df;
            VariantClear((VARIANTARG *)&local_158.n2);
          }
          if (local_168 != (longlong *)0x0) {
            pcVar3 = *(code **)(*local_168 + 0x10);
            *(undefined8 *)(puVar27 + -8) = 0x1800149ee;
            (*pcVar3)();
          }
        }
        *(undefined8 *)(puVar27 + -8) = 0x1800149f7;
        SysFreeString(bstrString);
        if (local_178 != (longlong *)0x0) {
          pcVar3 = *(code **)(*local_178 + 0x10);
          *(undefined8 *)(puVar27 + -8) = 0x180014a07;
          (*pcVar3)();
        }
        *(undefined8 *)(puVar27 + -8) = 0x180014a0c;
        pvVar15 = (void *)HappName();
        do {
          sVar36 = sVar36 + 1;
        } while (*(char *)((longlong)pvVar15 + sVar36) != '\0');
        *(undefined8 *)(puVar27 + -8) = 0x180014a29;
        FUN_18001d350((longlong *)(param_1 + 0x40),pvVar15,sVar36);
        *(undefined1 *)(param_1 + 0xaa) = 0;
      }
      *(undefined8 *)(puVar27 + -8) = 0x180014b8e;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_170);
      *(undefined8 *)(puVar27 + -8) = 0x180014b99;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_188);
      if (7 < uStack_a0) {
        ppppWVar10 = local_b8;
        if ((0xfff < uStack_a0 * 2 + 2) &&
           (ppppWVar10 = (LPCWSTR ***)local_b8[-1],
           (char *)0x1f < (char *)((longlong)local_b8 + (-8 - (longlong)ppppWVar10)))) {
LAB_180014ee9:
                    /* WARNING: Subroutine does not return */
          *(undefined **)(puVar27 + -8) = &UNK_180014eef;
          _invalid_parameter_noinfo_noreturn();
        }
        *(undefined8 *)(puVar27 + -8) = 0x180014be0;
        FUN_180035134(ppppWVar10);
      }
      local_a8 = _DAT_180041f60;
      uStack_a0 = _UNK_180041f68;
      local_b8 = (LPCWSTR ***)((ulonglong)local_b8 & 0xffffffffffff0000);
      if (7 < local_e0) {
        ppppWVar10 = local_f8;
        if ((0xfff < local_e0 * 2 + 2) &&
           (ppppWVar10 = (LPCWSTR ***)local_f8[-1],
           0x1f < (ulonglong)((longlong)local_f8 + (-8 - (longlong)ppppWVar10)))) {
LAB_180014f49:
          _UNK_180041f68 = uStack_a0;
          _DAT_180041f60 = local_a8;
                    /* WARNING: Subroutine does not return */
          *(undefined **)(puVar27 + -8) = &UNK_180014f4f;
          _invalid_parameter_noinfo_noreturn();
        }
        *(undefined8 *)(puVar27 + -8) = 0x180014c3e;
        FUN_180035134(ppppWVar10);
      }
      local_e8 = 0;
      local_e0 = 7;
      local_f8 = (LPCWSTR ***)((ulonglong)local_f8 & 0xffffffffffff0000);
      if (0xf < uStack_80) {
        ppppWVar10 = local_98;
        if ((0xfff < uStack_80 + 1) &&
           (ppppWVar10 = (LPCWSTR ***)local_98[-1],
           (char *)0x1f < (char *)((longlong)local_98 + (-8 - (longlong)ppppWVar10)))) {
LAB_180014fa6:
          local_e0 = 7;
          local_e8 = 0;
                    /* WARNING: Subroutine does not return */
          *(undefined **)(puVar27 + -8) = &UNK_180014fac;
          _invalid_parameter_noinfo_noreturn();
        }
        *(undefined8 *)(puVar27 + -8) = 0x180014c99;
        FUN_180035134(ppppWVar10);
      }
      local_88 = _DAT_180041f70;
      uStack_80 = _UNK_180041f78;
      local_98 = (LPCWSTR ***)((ulonglong)local_98 & 0xffffffffffffff00);
      if (0xf < uStack_c0) {
        ppppWVar10 = local_d8;
        if ((0xfff < uStack_c0 + 1) &&
           (ppppWVar10 = (LPCWSTR ***)local_d8[-1],
           (char *)0x1f < (char *)((longlong)local_d8 + (-8 - (longlong)ppppWVar10)))) {
LAB_18001500d:
          _UNK_180041f78 = uStack_80;
          _DAT_180041f70 = local_88;
                    /* WARNING: Subroutine does not return */
          *(undefined **)(puVar27 + -8) = &UNK_180015013;
          _invalid_parameter_noinfo_noreturn();
        }
        *(undefined8 *)(puVar27 + -8) = 0x180014cf1;
        FUN_180035134(ppppWVar10);
      }
      *(undefined1 *)(param_1 + 200) = (undefined1)local_198[0];
      goto LAB_18001432f;
    }
    *(undefined8 *)(puVar27 + -8) = 0x180014665;
    uVar13 = FUN_18000a4e0(param_1,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                    *)&local_170);
    pvVar15 = local_170;
    if ((int)uVar13 == 0) {
      *(undefined8 *)(puVar27 + -8) = 0x180014673;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_170);
      *(undefined8 *)(puVar27 + -8) = 0x18001467e;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_188);
    }
    else {
      *(undefined8 *)(puVar27 + -8) = 0x18001468c;
      iVar7 = OpenHappInput(pvVar15);
      if (iVar7 != 0) {
        sVar35 = 0xffffffffffffffff;
        do {
          sVar35 = sVar35 + 1;
        } while (*(char *)((longlong)local_170 + sVar35) != '\0');
        *(undefined8 *)(puVar27 + -8) = 0x1800146c7;
        FUN_18001d350((longlong *)&local_d8,local_170,sVar35);
        goto LAB_1800146c7;
      }
      *(undefined8 *)(puVar27 + -8) = 0x18001469a;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_170);
      *(undefined8 *)(puVar27 + -8) = 0x1800146a5;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_188);
    }
LAB_1800141ca:
    if (7 < uStack_a0) {
      ppppWVar10 = local_b8;
      if ((0xfff < uStack_a0 * 2 + 2) &&
         (ppppWVar10 = (LPCWSTR ***)local_b8[-1],
         (char *)0x1f < (char *)((longlong)local_b8 + (-8 - (longlong)ppppWVar10))))
      goto LAB_180014ee9;
      *(undefined8 *)(puVar27 + -8) = 0x180014210;
      FUN_180035134(ppppWVar10);
    }
    local_a8 = _DAT_180041f60;
    uStack_a0 = _UNK_180041f68;
    local_b8 = (LPCWSTR ***)((ulonglong)local_b8 & 0xffffffffffff0000);
    if (7 < local_e0) {
      ppppWVar10 = local_f8;
      if ((0xfff < local_e0 * 2 + 2) &&
         (ppppWVar10 = (LPCWSTR ***)local_f8[-1],
         0x1f < (ulonglong)((longlong)local_f8 + (-8 - (longlong)ppppWVar10)))) goto LAB_180014f49;
      *(undefined8 *)(puVar27 + -8) = 0x18001426f;
      FUN_180035134(ppppWVar10);
    }
    local_f8 = (LPCWSTR ***)((ulonglong)local_f8 & 0xffffffffffff0000);
    local_e0 = 7;
    local_e8 = 0;
    if (0xf < uStack_80) {
      ppppWVar10 = local_98;
      if ((0xfff < uStack_80 + 1) &&
         (ppppWVar10 = (LPCWSTR ***)local_98[-1],
         (char *)0x1f < (char *)((longlong)local_98 + (-8 - (longlong)ppppWVar10))))
      goto LAB_180014fa6;
      *(undefined8 *)(puVar27 + -8) = 0x1800142c9;
      FUN_180035134(ppppWVar10);
    }
    local_88 = _DAT_180041f70;
    uStack_80 = _UNK_180041f78;
    local_98 = (LPCWSTR ***)((ulonglong)local_98 & 0xffffffffffffff00);
    if (0xf < uStack_c0) {
      ppppWVar10 = local_d8;
      if (0xfff < uStack_c0 + 1) {
        ppppWVar10 = (LPCWSTR ***)local_d8[-1];
        lVar8 = (longlong)local_d8 - (longlong)ppppWVar10;
        goto joined_r0x000180015007;
      }
      goto LAB_18001431c;
    }
  }
  *(undefined1 *)(param_1 + 200) = (undefined1)local_198[0];
  uVar5 = 0;
LAB_18001432f:
  *(undefined8 *)(puVar27 + -8) = 0x18001433e;
  return uVar5;
}

