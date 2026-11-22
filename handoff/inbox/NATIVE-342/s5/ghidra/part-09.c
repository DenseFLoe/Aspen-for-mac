/* RVA 0x29230 */
void FUN_180029230(longlong *param_1)

{
  longlong *plVar1;
  int iVar2;
  int iVar3;
  longlong *plVar4;
  char *pcVar5;
  ulonglong uVar6;
  longlong lVar7;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  int local_res10 [2];
  longlong *local_res18;
  longlong *local_res20;
  longlong *local_c8;
  char *local_c0;
  longlong *local_b8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_b0 [8];
  longlong *local_a8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_a0 [8];
  longlong *local_98;
  longlong *local_90;
  longlong *local_88;
  _union_2707 local_80;
  _union_2707 local_68;
  longlong *local_50;
  undefined4 local_48;
  ULONG UStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  
  plVar4 = (longlong *)GetGlobalPointer("HappNode");
  local_50 = plVar4;
  if (plVar4 != (longlong *)0x0) {
    (**(code **)(*plVar4 + 8))(plVar4);
    local_88 = (longlong *)0x0;
    iVar2 = (**(code **)*plVar4)(plVar4,&DAT_180042488,&local_88);
    if (-1 < iVar2) {
      local_b8 = (longlong *)0x0;
      iVar2 = (**(code **)(*local_88 + 0x30))(local_88,&local_b8);
      if (-1 < iVar2) {
        local_c8 = (longlong *)0x0;
        local_res10[0] = 0;
        (**(code **)(*local_b8 + 0x18))(local_b8,1,&local_c8,local_res10);
        while ((local_c8 != (longlong *)0x0 && (local_res10[0] != 0))) {
          local_res20 = (longlong *)0x0;
          local_90 = (longlong *)0x0;
          iVar2 = (**(code **)*local_c8)(local_c8,&DAT_180042478,&local_90);
          if (-1 < iVar2) {
            (**(code **)(*local_90 + 0x30))(local_90,&local_res20);
          }
          if (local_res20 != (longlong *)0x0) {
            local_res18 = (longlong *)0x0;
            iVar2 = (**(code **)(*local_res20 + 0x18))(local_res20,1,&local_res18);
            if (iVar2 == 0) {
              while (local_res18 != (longlong *)0x0) {
                local_98 = (longlong *)0x0;
                iVar2 = (**(code **)*local_res18)(local_res18,&DAT_180041fd0,&local_98);
                if (-1 < iVar2) {
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_a0);
                  VariantInit((VARIANTARG *)&local_68.n2);
                  VariantInit((VARIANTARG *)&local_80.n2);
                  local_48 = local_68._0_4_;
                  UStack_44 = local_68.decVal.Hi32;
                  uStack_40 = local_68._8_4_;
                  uStack_3c = local_68._12_4_;
                  local_38 = local_68._16_8_;
                  (**(code **)(*local_98 + 0x98))(local_98,0x3b,&local_48,&local_80);
                  if (local_80.n2.vt == 8) {
                    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                              (local_a0,(wchar_t *)local_80.decVal.u2);
                  }
                  VariantClear((VARIANTARG *)&local_68.n2);
                  VariantClear((VARIANTARG *)&local_80.n2);
                  iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                          CompareNoCase(local_a0,"ACMMODEL");
                  if (iVar2 == 0) {
                    local_a8 = (longlong *)0x0;
                    iVar2 = (**(code **)(*local_res18 + 0x38))(local_res18,&local_a8);
                    if (iVar2 == 0) {
                      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                 &local_c0);
                      plVar1 = local_a8;
                      lVar7 = *local_a8;
                      pcVar5 = ATL::CSimpleStringT<char,1>::GetBuffer
                                         ((CSimpleStringT<char,1> *)&local_c0,0x20);
                      (**(code **)(lVar7 + 0x18))(plVar1,pcVar5,0x20);
                      iVar2 = 0;
                      this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             param_1[1];
                      lVar7 = *param_1;
                      if ((longlong)this - lVar7 >> 3 != 0) {
                        uVar6 = 0;
                        do {
                          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                    (local_b0,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                               *)(lVar7 + uVar6 * 8));
                          iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                  ::CompareNoCase(local_b0,local_c0);
                          if (iVar3 == 0) {
                            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_b0)
                            ;
                            goto LAB_1800294d9;
                          }
                          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_b0);
                          iVar2 = iVar2 + 1;
                          this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                 param_1[1];
                          lVar7 = *param_1;
                          uVar6 = (ulonglong)iVar2;
                        } while (uVar6 < (ulonglong)((longlong)this - lVar7 >> 3));
                      }
                      if (this == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                  param_1[2]) {
                        FUN_180025400(param_1,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                               *)this,
                                      (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                       *)&local_c0);
                      }
                      else {
                        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                  (this,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                         *)&local_c0);
                        param_1[1] = param_1[1] + 8;
                      }
LAB_1800294d9:
                      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                 &local_c0);
                    }
                    if (local_a8 != (longlong *)0x0) {
                      (**(code **)(*local_a8 + 0x10))();
                    }
                  }
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_a0);
                }
                plVar1 = local_res18;
                if (local_res18 != (longlong *)0x0) {
                  local_res18 = (longlong *)0x0;
                  (**(code **)(*plVar1 + 0x10))();
                }
                (**(code **)(*local_res20 + 0x18))(local_res20,1,&local_res18);
                if (local_98 != (longlong *)0x0) {
                  (**(code **)(*local_98 + 0x10))();
                }
              }
            }
            if (local_res18 != (longlong *)0x0) {
              (**(code **)(*local_res18 + 0x10))();
            }
          }
          if (local_90 != (longlong *)0x0) {
            (**(code **)(*local_90 + 0x10))(local_90);
          }
          if (local_res20 != (longlong *)0x0) {
            (**(code **)(*local_res20 + 0x10))();
          }
          plVar1 = local_c8;
          if (local_c8 != (longlong *)0x0) {
            local_c8 = (longlong *)0x0;
            (**(code **)(*plVar1 + 0x10))();
          }
          (**(code **)(*local_b8 + 0x18))(local_b8,1,&local_c8);
        }
        if (local_c8 != (longlong *)0x0) {
          (**(code **)(*local_c8 + 0x10))();
        }
      }
      if (local_b8 != (longlong *)0x0) {
        (**(code **)(*local_b8 + 0x10))();
      }
    }
    if (local_88 != (longlong *)0x0) {
      (**(code **)(*local_88 + 0x10))();
    }
  }
  if (plVar4 != (longlong *)0x0) {
    (**(code **)(*plVar4 + 0x10))(plVar4);
  }
  return;
}

/* RVA 0x29600 */
undefined8 FUN_180029600(char *param_1)

{
  longlong *plVar1;
  undefined8 uVar2;
  longlong *local_res10;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res18 [8];
  longlong *local_res20;
  longlong *local_68;
  _union_2707 local_60;
  _union_2707 local_48;
  undefined4 local_28;
  ULONG UStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined8 local_18;
  
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
  VariantInit((VARIANTARG *)&local_48.n2);
  VariantInit((VARIANTARG *)&local_60.n2);
  local_res20 = (longlong *)HappGetTree();
  local_res10 = (longlong *)FUN_180011610((longlong *)&local_res20);
  (**(code **)(*local_res20 + 0x10))();
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            (local_res18,"Settings");
  local_68 = (longlong *)FUN_1800116a0(&local_res10,local_res18);
  (**(code **)(*local_res10 + 0x10))();
  local_res10 = (longlong *)FUN_180011610((longlong *)&local_68);
  (**(code **)(*local_68 + 0x10))();
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(local_res18,param_1)
  ;
  plVar1 = (longlong *)FUN_1800116a0(&local_res10,local_res18);
  (**(code **)(*local_res10 + 0x10))();
  local_28 = local_48._0_4_;
  UStack_24 = local_48.decVal.Hi32;
  uStack_20 = local_48._8_4_;
  uStack_1c = local_48._12_4_;
  local_18 = local_48._16_8_;
  (**(code **)(*plVar1 + 0x68))(plVar1,&local_28,&local_60);
  VariantClear((VARIANTARG *)&local_48.n2);
  (**(code **)(*plVar1 + 0x10))(plVar1);
  if ((local_60.n2.vt == 3) && (local_60._8_4_ != 0)) {
    VariantClear((VARIANTARG *)&local_60.n2);
    uVar2 = 1;
  }
  else {
    VariantClear((VARIANTARG *)&local_60.n2);
    uVar2 = 0;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
  return uVar2;
}

/* RVA 0x29740 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180029740(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,
                  longlong *param_2)

{
  char *pcVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar2;
  BOOL BVar3;
  IAtlStringMgr *pIVar4;
  longlong lVar6;
  longlong lVar5;
  HANDLE hFindFile;
  LPCSTR ***ppppCVar7;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar8;
  size_t sVar9;
  undefined1 auStackY_1c8 [32];
  undefined4 local_198 [2];
  void *local_190;
  LPCSTR ***local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  ulonglong uStack_170;
  _WIN32_FIND_DATAA local_168;
  ulonglong local_28;
  
  local_28 = DAT_180052888 ^ (ulonglong)auStackY_1c8;
  local_198[0] = 0;
  pCVar8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)*param_2;
  pCVar2 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2[1];
  if (pCVar8 != pCVar2) {
    do {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar8);
      pCVar8 = pCVar8 + 8;
    } while (pCVar8 != pCVar2);
    param_2[1] = *param_2;
  }
  pIVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager(param_1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_190,pIVar4);
  local_198[0] = 1;
  sVar9 = 0xffffffffffffffff;
  lVar6 = -1;
  do {
    lVar5 = lVar6 + 1;
    pcVar1 = "*.atmlz" + lVar6;
    lVar6 = lVar5;
  } while (*pcVar1 != '\0');
  ATL::CSimpleStringT<char,1>::Concatenate
            ((CSimpleStringT<char,1> *)&local_190,*(char **)param_1,
             *(int *)(*(char **)param_1 + -0x10),"\\*.atmlz",(int)lVar5);
  local_188 = (LPCSTR ***)0x0;
  uStack_180 = 0;
  local_178 = 0;
  uStack_170 = 0;
  do {
    sVar9 = sVar9 + 1;
  } while (*(char *)((longlong)local_190 + sVar9) != '\0');
  FUN_180006e90(&local_188,local_190,sVar9);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_190);
  ppppCVar7 = (LPCSTR ***)&local_188;
  if (0xf < uStack_170) {
    ppppCVar7 = local_188;
  }
  hFindFile = FindFirstFileA((LPCSTR)ppppCVar7,&local_168);
  if (hFindFile != (HANDLE)0xffffffffffffffff) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_198,"");
    do {
      if (((byte)local_168.dwFileAttributes & 0x10) == 0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_198,
                   local_168.cFileName);
        pCVar8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2[1];
        if (pCVar8 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_2[2]) {
          FUN_180025400(param_2,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                 *)pCVar8,
                        (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *
                        )local_198);
        }
        else {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    (pCVar8,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                             *)local_198);
          param_2[1] = param_2[1] + 8;
        }
      }
      BVar3 = FindNextFileA(hFindFile,&local_168);
    } while (BVar3 != 0);
    FindClose(hFindFile);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_198);
  }
  if (0xf < uStack_170) {
    ppppCVar7 = local_188;
    if ((0xfff < uStack_170 + 1) &&
       (ppppCVar7 = (LPCSTR ***)local_188[-1],
       (LPCSTR)0x1f < (LPCSTR)((longlong)local_188 + (-8 - (longlong)ppppCVar7)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(ppppCVar7);
  }
  return;
}

/* RVA 0x29940 */
CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_180029940(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2)

{
  longlong lVar1;
  int iVar2;
  IAtlStringMgr *pIVar3;
  longlong lVar4;
  longlong lVar5;
  char *local_res18;
  wchar_t *local_res20;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_60 [8];
  char *local_58;
  char *local_50;
  char *local_48;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_40 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_38 [16];
  
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1,"");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18,"");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18,"");
  local_res20 = malloc(0x400);
  iVar2 = SHGetKnownFolderPath(&DAT_180042ad8,0,0,&local_res20);
  if (iVar2 == 0) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_50,
               local_res20);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               &local_50);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_50);
    if (*(int *)(local_res18 + -0x10) != 0) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_38,"AspenTech");
      pIVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          &local_res18);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
                 pIVar3);
      lVar5 = -1;
      do {
        lVar4 = lVar5 + 1;
        lVar1 = lVar5 + 1;
        lVar5 = lVar4;
      } while (*(char *)((longlong)&DAT_1800409c4 + lVar1) != '\0');
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)&local_res20,local_res18,*(int *)(local_res18 + -0x10),
                 "\\",(int)lVar4);
      FUN_180001320((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_50,
                    (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
                    (undefined8 *)local_38);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
      FUN_180001430(local_40,"Aspen Plus ",param_2);
      pIVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_50
                         );
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
                 pIVar3);
      lVar5 = -1;
      do {
        lVar4 = lVar5 + 1;
        lVar1 = lVar5 + 1;
        lVar5 = lVar4;
      } while (*(char *)((longlong)&DAT_1800409c4 + lVar1) != '\0');
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)&local_res20,local_50,*(int *)(local_50 + -0x10),"\\",
                 (int)lVar4);
      FUN_180001320((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58,
                    (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
                    (undefined8 *)local_40);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48,
                 "AM Models");
      pIVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58
                         );
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
                 pIVar3);
      lVar5 = -1;
      do {
        lVar4 = lVar5 + 1;
        lVar1 = lVar5 + 1;
        lVar5 = lVar4;
      } while (*(char *)((longlong)&DAT_1800409c4 + lVar1) != '\0');
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)&local_res20,local_58,*(int *)(local_58 + -0x10),"\\",
                 (int)lVar4);
      pIVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          &local_res20);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_60,pIVar3);
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)local_60,(char *)local_res20,*(int *)(local_res20 + -8),
                 local_48,*(int *)(local_48 + -0x10));
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                (param_1,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                          *)local_60);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_60);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_40);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_50);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_38);
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_2);
  return param_1;
}

/* RVA 0x29c20 */
undefined8 * FUN_180029c20(IUnknown *param_1,undefined8 *param_2)

{
  ULONG UVar1;
  undefined8 *puVar2;
  
  UVar1 = (*param_1->lpVtbl[4].AddRef)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_1800424d8);
  }
  puVar2 = operator_new(0x18);
  if (puVar2 != (undefined8 *)0x0) {
    puVar2[1] = 0;
    *(undefined4 *)(puVar2 + 2) = 1;
    *puVar2 = 0;
  }
  *param_2 = puVar2;
  if (puVar2 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_180034a60(0x8007000e);
  }
  return param_2;
}

/* RVA 0x29cb0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

ulonglong FUN_180029cb0(char param_1,char *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  LPCSTR pCVar3;
  BSTR pOVar4;
  char *pcVar5;
  longlong *plVar6;
  LPCWSTR pWVar7;
  LPCSTR lpExistingFileName;
  DWORD DVar8;
  BOOL BVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  char *pcVar13;
  HANDLE pvVar14;
  IModelLibraryManager *pIVar15;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar16;
  IAtlStringMgr *pIVar17;
  BSTR pOVar18;
  BSTR pOVar19;
  BSTR pOVar20;
  undefined *puVar21;
  undefined *puVar22;
  void *pvVar23;
  ulonglong uVar24;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar25;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar26;
  undefined4 *puVar27;
  uint uVar28;
  ulonglong uVar29;
  undefined1 *puVar30;
  undefined1 *puVar31;
  undefined1 *puVar32;
  undefined1 *puVar33;
  undefined1 *puVar34;
  undefined1 *puVar35;
  undefined1 *puVar36;
  undefined1 *puVar37;
  undefined1 *puVar38;
  undefined1 *puVar39;
  longlong lVar40;
  ulonglong uVar41;
  BSTR pOVar42;
  longlong lVar43;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar44;
  void *pvVar45;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar46;
  int iVar47;
  longlong lVar48;
  LPCWSTR pWVar49;
  undefined1 auStackY_868 [32];
  undefined8 local_828;
  char local_820;
  BSTR local_818;
  BSTR local_810;
  char *local_808;
  LPCWSTR local_800;
  LPCSTR local_7f8;
  BSTR local_7f0;
  LPCWSTR local_7e8;
  BSTR local_7e0;
  longlong *local_7d8;
  LPCWSTR local_7d0;
  BSTR local_7c8;
  longlong local_7c0;
  longlong local_7b8;
  LPCSTR local_7b0;
  char local_7a8 [8];
  LPCWSTR local_7a0;
  char *local_798;
  LPCSTR local_790;
  char *local_788;
  BSTR local_780;
  LPCSTR local_778;
  undefined8 local_770;
  char *local_768;
  LPCWSTR local_760;
  LPCSTR local_758;
  longlong local_750;
  LPCSTR local_748;
  BSTR local_740;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_738;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCStack_730;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_728;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_720;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCStack_718;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_710;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_708;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCStack_700;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_6f8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_6f0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCStack_6e8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_6e0;
  void *local_6d8;
  undefined4 *puStack_6d0;
  undefined4 *local_6c8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_6c0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCStack_6b8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_6b0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_6a8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_6a0 [8];
  LPCWSTR local_698;
  LPCWSTR local_690;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_688;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCStack_680;
  longlong local_678;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_670;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCStack_668;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_660;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_658;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCStack_650;
  longlong local_648;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_640 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_638 [8];
  LPCSTR local_630;
  LPCSTR local_628;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_620 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_618 [8];
  void *local_610;
  longlong lStack_608;
  longlong local_600;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_5f8 [8];
  BSTR local_5f0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_5e8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCStack_5e0;
  longlong local_5d8;
  IModelLibraryManager *local_5d0;
  longlong local_5c8;
  _WIN32_FIND_DATAA local_5b8;
  _WIN32_FIND_DATAA local_478;
  char local_338 [256];
  char local_238 [256];
  char local_138 [256];
  ulonglong local_38;
  
  local_38 = DAT_180052888 ^ (ulonglong)&local_828;
  lVar40 = 0;
  local_828 = (BSTR)((ulonglong)local_828 & 0xffffffff00000000);
  local_820 = param_1;
  _splitpath(param_2,local_7a8,local_338,local_138,local_238);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_628);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_628,
             "%s%sACM_Models\\*.atmlz",local_7a8,local_338);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_630);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_630,
             "%s%sACM_EditedModels\\*.atmlz",local_7a8,local_338);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_638);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
            (local_638,"%s%sACM_Models",local_7a8,local_338);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_768);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_768,
             "%s%sACM_EditedModels",local_7a8,local_338);
  pcVar13 = FindFirstFileA(local_628,&local_5b8);
  local_798 = pcVar13;
  pvVar14 = FindFirstFileA(local_630,&local_478);
  puVar33 = auStackY_868;
  if ((pcVar13 == (char *)0xffffffffffffffff) && (pvVar14 == (HANDLE)0xffffffffffffffff)) {
    local_828 = (BSTR)CONCAT44(local_828._4_4_,1);
    goto LAB_18002c8d1;
  }
  pIVar15 = DCGetACMModelLibraryManagerPtr();
  puVar33 = auStackY_868;
  local_5d0 = pIVar15;
  if (pIVar15 == (IModelLibraryManager *)0x0) {
    local_828 = (BSTR)CONCAT44(local_828._4_4_,0x80004005);
    goto LAB_18002c8d1;
  }
  local_720 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  pCStack_718 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  local_710 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  local_658 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  pCStack_650 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  local_648 = 0;
  local_688 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  pCStack_680 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  local_678 = 0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7b8,"");
  local_610 = (void *)0x0;
  lStack_608 = 0;
  local_600 = 0;
  local_6f0 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  pCStack_6e8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  local_6e0 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_748,"");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_758,"");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_790,"");
  puVar33 = auStackY_868;
  local_708 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  pCStack_700 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  local_6f8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  if (pvVar14 != (HANDLE)0xffffffffffffffff) {
    pCVar16 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_780
                         ,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                           *)&DAT_1800540a8);
    pCVar16 = FUN_180029940((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_740,pCVar16);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_790,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar16)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_740);
    if (((*(int *)(local_790 + -0x10) == 0) ||
        (DVar8 = GetFileAttributesA(local_790), DVar8 == 0xffffffff)) || ((DVar8 & 0x10) == 0)) {
      BVar9 = CreateDirectoryA(local_790,(LPSECURITY_ATTRIBUTES)0x0);
      puVar33 = auStackY_868;
      if (BVar9 == 0) goto LAB_18002b1fa;
    }
    FUN_180029740((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_768,
                  (longlong *)&local_688);
    FUN_180029740(local_638,(longlong *)&local_658);
    iVar47 = 0;
    if ((longlong)pCStack_680 - (longlong)local_688 >> 3 != 0) {
      uVar41 = 0;
      pCVar16 = local_658;
      pCVar25 = pCStack_680;
      pCVar44 = local_688;
      pCVar46 = pCStack_650;
      do {
        uVar24 = 0;
        if ((longlong)pCVar46 - (longlong)pCVar16 >> 3 != 0) {
          uVar29 = uVar24;
          do {
            iVar10 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                     CompareNoCase(pCVar16 + uVar24 * 8,*(char **)(pCVar44 + lVar40));
            if (iVar10 == 0) {
              if (pCStack_718 == local_710) {
                FUN_180025400((longlong *)&local_720,
                              (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                               *)pCStack_718,
                              (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                               *)(local_688 + uVar41 * 8));
              }
              else {
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          (pCStack_718,
                           (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                            *)(local_688 + uVar41 * 8));
                pCStack_718 = pCStack_718 + 8;
              }
            }
            uVar28 = (int)uVar29 + 1;
            uVar29 = (ulonglong)uVar28;
            uVar24 = (ulonglong)(int)uVar28;
            pCVar16 = local_658;
            pCVar44 = local_688;
          } while (uVar24 < (ulonglong)((longlong)pCStack_650 - (longlong)local_658 >> 3));
          pCVar25 = pCStack_680;
          pCVar46 = pCStack_650;
        }
        iVar47 = iVar47 + 1;
        lVar40 = lVar40 + 8;
        uVar41 = (ulonglong)iVar47;
      } while (uVar41 < (ulonglong)((longlong)pCVar25 - (longlong)pCVar44 >> 3));
    }
    uVar41 = 0;
    local_5e8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    pCStack_5e0 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    local_5d8 = 0;
    FUN_180029740((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_790,
                  (longlong *)&local_5e8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_6a0,"");
    puVar33 = auStackY_868;
    iVar47 = (int)((longlong)pCStack_718 - (longlong)local_720 >> 3);
    if ((int)((longlong)pCStack_5e0 - (longlong)local_5e8 >> 3) == 0) {
      if (0 < iVar47) {
        lVar40 = 0;
        do {
          pIVar17 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &local_768);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7f0,
                     pIVar17);
          local_828._0_4_ = 0x8000;
          ATL::CSimpleStringT<char,1>::Concatenate
                    ((CSimpleStringT<char,1> *)&local_7f0,local_768,*(int *)(local_768 + -0x10),"\\"
                     ,1);
          pCVar16 = local_720 + lVar40 * 8;
          pIVar17 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &local_7f0);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_808,
                     pIVar17);
          local_828._0_4_ = 0xc000;
          ATL::CSimpleStringT<char,1>::Concatenate
                    ((CSimpleStringT<char,1> *)&local_808,(char *)local_7f0,*(int *)(local_7f0 + -8)
                     ,*(char **)pCVar16,*(int *)(*(char **)pCVar16 + -0x10));
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_748,
                     (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     &local_808);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_808);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7f0);
          pIVar17 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &local_790);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7e8,
                     pIVar17);
          local_828._0_4_ = 0x2000;
          ATL::CSimpleStringT<char,1>::Concatenate
                    ((CSimpleStringT<char,1> *)&local_7e8,local_790,*(int *)(local_790 + -0x10),"\\"
                     ,1);
          pCVar16 = local_720 + lVar40 * 8;
          pIVar17 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &local_7e8);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_810,
                     pIVar17);
          local_828 = (BSTR)CONCAT44(local_828._4_4_,0x3000);
          ATL::CSimpleStringT<char,1>::Concatenate
                    ((CSimpleStringT<char,1> *)&local_810,(char *)local_7e8,*(int *)(local_7e8 + -8)
                     ,*(char **)pCVar16,*(int *)(*(char **)pCVar16 + -0x10));
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_758,
                     (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     &local_810);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_810);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7e8);
          CopyFileA(local_748,local_758,0);
          lVar40 = lVar40 + 1;
        } while (lVar40 < iVar47);
      }
    }
    else if (0 < iVar47) {
      lVar40 = 0;
      do {
        pIVar17 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_768);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7f0,
                   pIVar17);
        local_828._0_4_ = 0x800;
        ATL::CSimpleStringT<char,1>::Concatenate
                  ((CSimpleStringT<char,1> *)&local_7f0,local_768,*(int *)(local_768 + -0x10),"\\",1
                  );
        pCVar16 = local_720 + lVar40 * 8;
        pIVar17 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_7f0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_808,
                   pIVar17);
        local_828._0_4_ = 0xc00;
        ATL::CSimpleStringT<char,1>::Concatenate
                  ((CSimpleStringT<char,1> *)&local_808,(char *)local_7f0,*(int *)(local_7f0 + -8),
                   *(char **)pCVar16,*(int *)(*(char **)pCVar16 + -0x10));
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_748,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   &local_808);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_808);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7f0);
        pIVar17 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_790);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7e8,
                   pIVar17);
        local_828._0_4_ = 0x100;
        ATL::CSimpleStringT<char,1>::Concatenate
                  ((CSimpleStringT<char,1> *)&local_7e8,local_790,*(int *)(local_790 + -0x10),"\\",1
                  );
        pCVar16 = local_720 + lVar40 * 8;
        pIVar17 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_7e8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_810,
                   pIVar17);
        local_828 = (BSTR)CONCAT44(local_828._4_4_,0x300);
        ATL::CSimpleStringT<char,1>::Concatenate
                  ((CSimpleStringT<char,1> *)&local_810,(char *)local_7e8,*(int *)(local_7e8 + -8),
                   *(char **)pCVar16,*(int *)(*(char **)pCVar16 + -0x10));
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_758,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   &local_810);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_810);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7e8);
        DVar8 = GetFileAttributesA(local_758);
        if ((DVar8 == 0xffffffff) && (DVar8 = GetLastError(), DVar8 == 2)) {
          CopyFileA(local_748,local_758,0);
        }
        else if (pCStack_700 == local_6f8) {
          FUN_180025400((longlong *)&local_708,
                        (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *
                        )pCStack_700,
                        (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *
                        )(local_720 + uVar41 * 8));
        }
        else {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    (pCStack_700,
                     (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     (local_720 + uVar41 * 8));
          pCStack_700 = pCStack_700 + 8;
        }
        uVar41 = (ulonglong)((int)uVar41 + 1);
        lVar40 = lVar40 + 1;
      } while (lVar40 < iVar47);
    }
    iVar10 = 0;
    lVar40 = (longlong)pCStack_700 - (longlong)local_708;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7e0,"");
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_778,"");
    local_770 = (BSTR)((ulonglong)local_770._4_4_ << 0x20);
    iVar47 = (int)(lVar40 >> 3);
    local_5c8 = (longlong)iVar47;
    if (0 < iVar47) {
      local_750 = 0;
      puVar33 = auStackY_868;
      do {
        lVar40 = local_750;
        *(undefined8 *)(puVar33 + -8) = 0x18002a54d;
        pIVar17 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_768);
        *(undefined8 *)(puVar33 + -8) = 0x18002a55a;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7f0,
                   pIVar17);
        pcVar13 = local_768;
        local_828._0_4_ = 0x10;
        *(undefined4 *)(puVar33 + 0x20) = 1;
        iVar47 = *(int *)(pcVar13 + -0x10);
        *(undefined8 *)(puVar33 + -8) = 0x18002a583;
        ATL::CSimpleStringT<char,1>::Concatenate
                  ((CSimpleStringT<char,1> *)&local_7f0,pcVar13,iVar47,"\\",*(int *)(puVar33 + 0x20)
                  );
        pCVar16 = local_708 + lVar40 * 8;
        *(undefined8 *)(puVar33 + -8) = 0x18002a598;
        pIVar17 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_7f0);
        *(undefined8 *)(puVar33 + -8) = 0x18002a5a8;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_640,pIVar17);
        pOVar20 = local_7f0;
        local_828 = (BSTR)CONCAT44(local_828._4_4_,0x30);
        pcVar13 = *(char **)pCVar16;
        *(undefined4 *)(puVar33 + 0x20) = *(undefined4 *)(pcVar13 + -0x10);
        iVar47 = *(int *)(pOVar20 + -8);
        *(undefined8 *)(puVar33 + -8) = 0x18002a5d0;
        ATL::CSimpleStringT<char,1>::Concatenate
                  ((CSimpleStringT<char,1> *)local_640,(char *)pOVar20,iVar47,pcVar13,
                   *(int *)(puVar33 + 0x20));
        *(undefined8 *)(puVar33 + -8) = 0x18002a5e1;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7e0,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   local_640);
        *(undefined8 *)(puVar33 + -8) = 0x18002a5f2;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_640);
        *(undefined8 *)(puVar33 + -8) = 0x18002a600;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7f0);
        pOVar20 = local_7e0;
        if (local_7e0 == (BSTR)0x0) {
          local_5f0 = local_7e0;
        }
        else {
          *(undefined4 *)(puVar33 + 0x28) = 0;
          *(undefined8 *)(puVar33 + 0x20) = 0;
          *(undefined8 *)(puVar33 + -8) = 0x18002a626;
          iVar47 = MultiByteToWideChar(0,0,(LPCSTR)pOVar20,-1,*(LPWSTR *)(puVar33 + 0x20),
                                       *(int *)(puVar33 + 0x28));
          *(undefined8 *)(puVar33 + -8) = 0x18002a633;
          pOVar18 = SysAllocStringLen((OLECHAR *)0x0,iVar47 - 1);
          if (pOVar18 != (BSTR)0x0) {
            *(int *)(puVar33 + 0x28) = iVar47;
            *(BSTR *)(puVar33 + 0x20) = pOVar18;
            *(undefined8 *)(puVar33 + -8) = 0x18002a657;
            iVar11 = MultiByteToWideChar(0,0,(LPCSTR)pOVar20,-1,*(LPWSTR *)(puVar33 + 0x20),
                                         *(int *)(puVar33 + 0x28));
            if (iVar11 != iVar47) {
              *(undefined8 *)(puVar33 + -8) = 0x18002c95d;
              SysFreeString(pOVar18);
              goto LAB_18002c95d;
            }
          }
          local_5f0 = pOVar18;
          if (pOVar18 == (BSTR)0x0) {
LAB_18002c95d:
                    /* WARNING: Subroutine does not return */
            *(undefined8 *)(puVar33 + -8) = 0x18002c967;
            FUN_1800018d0(-0x7ff8fff2);
          }
        }
        pOVar20 = local_5f0;
        local_780 = (BSTR)((longlong)iVar10 * 8);
        pCVar26 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                  (local_708 + (longlong)local_780);
        *(undefined8 *)(puVar33 + -8) = 0x18002a6a3;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7f8,
                   pCVar26);
        pCVar3 = local_7f8;
        if (local_7f8 == (LPCSTR)0x0) {
          local_740 = (BSTR)0x0;
        }
        else {
          *(undefined4 *)(puVar33 + 0x28) = 0;
          *(undefined8 *)(puVar33 + 0x20) = 0;
          *(undefined8 *)(puVar33 + -8) = 0x18002a6c9;
          iVar47 = MultiByteToWideChar(0,0,pCVar3,-1,*(LPWSTR *)(puVar33 + 0x20),
                                       *(int *)(puVar33 + 0x28));
          *(undefined8 *)(puVar33 + -8) = 0x18002a6d6;
          pOVar18 = SysAllocStringLen((OLECHAR *)0x0,iVar47 - 1);
          if (pOVar18 != (BSTR)0x0) {
            *(int *)(puVar33 + 0x28) = iVar47;
            *(BSTR *)(puVar33 + 0x20) = pOVar18;
            *(undefined8 *)(puVar33 + -8) = 0x18002a6fa;
            iVar10 = MultiByteToWideChar(0,0,pCVar3,-1,*(LPWSTR *)(puVar33 + 0x20),
                                         *(int *)(puVar33 + 0x28));
            if (iVar10 != iVar47) {
              *(undefined8 *)(puVar33 + -8) = 0x18002c971;
              SysFreeString(pOVar18);
              goto LAB_18002c971;
            }
          }
          local_740 = pOVar18;
          if (pOVar18 == (BSTR)0x0) {
LAB_18002c971:
                    /* WARNING: Subroutine does not return */
            *(undefined8 *)(puVar33 + -8) = 0x18002c97b;
            FUN_1800018d0(-0x7ff8fff2);
          }
        }
        pOVar4 = local_740;
        pOVar42 = (BSTR)0x0;
        pcVar1 = *(code **)(*(longlong *)pIVar15 + 0xd8);
        local_7c8 = pOVar42;
        *(undefined8 *)(puVar33 + -8) = 0x18002a738;
        (*pcVar1)(pIVar15,pOVar20,&local_7c8);
        pOVar18 = local_7c8;
        if (local_7c8 == (BSTR)0x0) {
LAB_18002a741:
          *(undefined8 *)(puVar33 + -8) = 0x18002a74a;
          SysFreeString(pOVar4);
          *(undefined8 *)(puVar33 + -8) = 0x18002a755;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7f8);
          *(undefined8 *)(puVar33 + -8) = 0x18002a75f;
          SysFreeString(pOVar20);
        }
        else {
          pcVar1 = *(code **)(*(longlong *)local_7c8 + 0xa0);
          local_818 = pOVar42;
          *(undefined8 *)(puVar33 + -8) = 0x18002a775;
          (*pcVar1)(pOVar18,&local_818);
          pOVar18 = local_818;
          puVar31 = puVar33;
          if (local_818 == (LPCWSTR)0x0) {
LAB_18002a80b:
            pOVar19 = pOVar42;
          }
          else {
            lVar40 = -1;
            do {
              lVar43 = lVar40;
              lVar40 = lVar43 + 1;
            } while (local_818[lVar40] != L'\0');
            iVar47 = (int)lVar43 + 2;
            if (0x3fffffff < iVar47) goto LAB_18002a80b;
            lVar40 = (longlong)(int)lVar40 * 2;
            uVar41 = lVar40 + 0x11;
            if (uVar41 <= lVar40 + 2U) {
              uVar41 = 0xffffffffffffff0;
            }
            *(undefined8 *)(puVar33 + -8) = 0x18002a7cf;
            lVar40 = -(uVar41 & 0xfffffffffffffff0);
            puVar31 = puVar33 + lVar40;
            pOVar19 = (BSTR)(puVar33 + lVar40 + 0x40);
            if (pOVar19 == (BSTR)0x0) goto LAB_18002a80b;
            *(undefined1 *)pOVar19 = 0;
            *(undefined8 *)(puVar33 + lVar40 + 0x38) = 0;
            *(undefined8 *)(puVar33 + lVar40 + 0x30) = 0;
            *(int *)(puVar33 + lVar40 + 0x28) = iVar47 * 2;
            *(BSTR *)(puVar33 + lVar40 + 0x20) = pOVar19;
            *(undefined8 *)(puVar33 + lVar40 + -8) = 0x18002a803;
            iVar47 = WideCharToMultiByte(0,0,pOVar18,-1,*(LPSTR *)(puVar33 + lVar40 + 0x20),
                                         *(int *)(puVar33 + lVar40 + 0x28),
                                         *(LPCSTR *)(puVar33 + lVar40 + 0x30),
                                         *(LPBOOL *)(puVar33 + lVar40 + 0x38));
            puVar31 = puVar33 + lVar40;
            if (iVar47 == 0) {
              pOVar19 = pOVar42;
              puVar31 = puVar33 + lVar40;
            }
          }
          *(undefined8 *)(puVar31 + -8) = 0x18002a81b;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7b0,
                     (char *)pOVar19);
          *(undefined8 *)(puVar31 + -8) = 0x18002a826;
          pCVar26 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::MakeLower
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &local_7b0);
          *(undefined8 *)(puVar31 + -8) = 0x18002a833;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7b0,
                     pCVar26);
          pOVar18 = local_7c8;
          pcVar1 = *(code **)(*(longlong *)local_7c8 + 0xa8);
          local_800 = pOVar42;
          *(undefined8 *)(puVar31 + -8) = 0x18002a848;
          (*pcVar1)(pOVar18,&local_800);
          pWVar49 = local_800;
          puVar33 = puVar31;
          if (local_800 == (LPCWSTR)0x0) {
LAB_18002a8db:
            pOVar18 = pOVar42;
          }
          else {
            lVar40 = -1;
            do {
              lVar43 = lVar40;
              lVar40 = lVar43 + 1;
            } while (local_800[lVar40] != L'\0');
            iVar47 = (int)lVar43 + 2;
            if (0x3fffffff < iVar47) goto LAB_18002a8db;
            lVar40 = (longlong)(int)lVar40 * 2;
            uVar41 = lVar40 + 0x11;
            if (uVar41 <= lVar40 + 2U) {
              uVar41 = 0xffffffffffffff0;
            }
            *(undefined8 *)(puVar31 + -8) = 0x18002a89f;
            lVar40 = -(uVar41 & 0xfffffffffffffff0);
            puVar33 = puVar31 + lVar40;
            pOVar18 = (BSTR)(puVar31 + lVar40 + 0x40);
            if (pOVar18 == (BSTR)0x0) goto LAB_18002a8db;
            *(undefined1 *)pOVar18 = 0;
            *(undefined8 *)(puVar31 + lVar40 + 0x38) = 0;
            *(undefined8 *)(puVar31 + lVar40 + 0x30) = 0;
            *(int *)(puVar31 + lVar40 + 0x28) = iVar47 * 2;
            *(BSTR *)(puVar31 + lVar40 + 0x20) = pOVar18;
            *(undefined8 *)(puVar31 + lVar40 + -8) = 0x18002a8d3;
            iVar47 = WideCharToMultiByte(0,0,pWVar49,-1,*(LPSTR *)(puVar31 + lVar40 + 0x20),
                                         *(int *)(puVar31 + lVar40 + 0x28),
                                         *(LPCSTR *)(puVar31 + lVar40 + 0x30),
                                         *(LPBOOL *)(puVar31 + lVar40 + 0x38));
            puVar33 = puVar31 + lVar40;
            if (iVar47 == 0) {
              pOVar18 = pOVar42;
              puVar33 = puVar31 + lVar40;
            }
          }
          *(undefined8 *)(puVar33 + -8) = 0x18002a8eb;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7d8,
                     (char *)pOVar18);
          pOVar18 = local_7c8;
          pcVar1 = *(code **)(*(longlong *)local_7c8 + 0x68);
          local_7d0 = pOVar42;
          *(undefined8 *)(puVar33 + -8) = 0x18002a8fe;
          iVar47 = (*pcVar1)(pOVar18,&local_7d0);
          pWVar49 = local_7d0;
          if (iVar47 < 0) {
            *(undefined8 *)(puVar33 + -8) = 0x18002a90c;
            SysFreeString(pWVar49);
            *(undefined8 *)(puVar33 + -8) = 0x18002a917;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7d8);
            pWVar49 = local_800;
            *(undefined8 *)(puVar33 + -8) = 0x18002a922;
            SysFreeString(pWVar49);
            *(undefined8 *)(puVar33 + -8) = 0x18002a92d;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7b0);
            pOVar18 = local_818;
            *(undefined8 *)(puVar33 + -8) = 0x18002a938;
            SysFreeString(pOVar18);
            if (local_7c8 != (BSTR)0x0) {
              pcVar1 = *(code **)(*(longlong *)local_7c8 + 0x10);
              *(undefined8 *)(puVar33 + -8) = 0x18002a94c;
              (*pcVar1)();
            }
            goto LAB_18002a741;
          }
          puVar31 = puVar33;
          if (local_7d0 == (BSTR)0x0) {
LAB_18002a9e0:
            pOVar18 = pOVar42;
            puVar33 = puVar31;
          }
          else {
            lVar40 = -1;
            do {
              lVar43 = lVar40;
              lVar40 = lVar43 + 1;
            } while (local_7d0[lVar40] != L'\0');
            iVar47 = (int)lVar43 + 2;
            if (0x3fffffff < iVar47) goto LAB_18002a9e0;
            lVar40 = (longlong)(int)lVar40 * 2;
            uVar41 = lVar40 + 0x11;
            if (uVar41 <= lVar40 + 2U) {
              uVar41 = 0xffffffffffffff0;
            }
            *(undefined8 *)(puVar33 + -8) = 0x18002a9a4;
            lVar40 = -(uVar41 & 0xfffffffffffffff0);
            puVar31 = puVar33 + lVar40;
            puVar30 = puVar33 + lVar40;
            pOVar18 = (BSTR)(puVar33 + lVar40 + 0x40);
            if (pOVar18 == (BSTR)0x0) goto LAB_18002a9e0;
            *(undefined1 *)pOVar18 = 0;
            *(undefined8 *)(puVar33 + lVar40 + 0x38) = 0;
            *(undefined8 *)(puVar33 + lVar40 + 0x30) = 0;
            *(int *)(puVar33 + lVar40 + 0x28) = iVar47 * 2;
            *(BSTR *)(puVar33 + lVar40 + 0x20) = pOVar18;
            *(undefined8 *)(puVar33 + lVar40 + -8) = 0x18002a9d8;
            iVar47 = WideCharToMultiByte(0,0,pWVar49,-1,*(LPSTR *)(puVar33 + lVar40 + 0x20),
                                         *(int *)(puVar33 + lVar40 + 0x28),
                                         *(LPCSTR *)(puVar33 + lVar40 + 0x30),
                                         *(LPBOOL *)(puVar33 + lVar40 + 0x38));
            puVar33 = puVar33 + lVar40;
            if (iVar47 == 0) {
              pOVar18 = pOVar42;
              puVar33 = puVar30;
            }
          }
          *(undefined8 *)(puVar33 + -8) = 0x18002a9f0;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_808,
                     (char *)pOVar18);
          *(undefined8 *)(puVar33 + -8) = 0x18002a9fe;
          pIVar17 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &local_790);
          *(undefined8 *)(puVar33 + -8) = 0x18002aa0b;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7e8,
                     pIVar17);
          pCVar3 = local_790;
          local_828._0_4_ = 0x40;
          *(undefined4 *)(puVar33 + 0x20) = 1;
          iVar47 = *(int *)(pCVar3 + -0x10);
          *(undefined8 *)(puVar33 + -8) = 0x18002aa34;
          ATL::CSimpleStringT<char,1>::Concatenate
                    ((CSimpleStringT<char,1> *)&local_7e8,pCVar3,iVar47,"\\",
                     *(int *)(puVar33 + 0x20));
          pCVar16 = local_708 + local_750 * 8;
          *(undefined8 *)(puVar33 + -8) = 0x18002aa50;
          pIVar17 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &local_7e8);
          *(undefined8 *)(puVar33 + -8) = 0x18002aa60;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_618,pIVar17);
          pWVar49 = local_7e8;
          local_828 = (BSTR)CONCAT44(local_828._4_4_,0xc0);
          pcVar13 = *(char **)pCVar16;
          *(undefined4 *)(puVar33 + 0x20) = *(undefined4 *)(pcVar13 + -0x10);
          iVar47 = *(int *)(pWVar49 + -8);
          *(undefined8 *)(puVar33 + -8) = 0x18002aa89;
          ATL::CSimpleStringT<char,1>::Concatenate
                    ((CSimpleStringT<char,1> *)local_618,(char *)pWVar49,iVar47,pcVar13,
                     *(int *)(puVar33 + 0x20));
          *(undefined8 *)(puVar33 + -8) = 0x18002aa9d;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_778,
                     (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     local_618);
          *(undefined8 *)(puVar33 + -8) = 0x18002aaaf;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_618);
          *(undefined8 *)(puVar33 + -8) = 0x18002aabd;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7e8);
          pCVar3 = local_778;
          if (local_778 == (LPCSTR)0x0) {
            local_828 = pOVar42;
          }
          else {
            *(undefined4 *)(puVar33 + 0x28) = 0;
            *(undefined8 *)(puVar33 + 0x20) = 0;
            *(undefined8 *)(puVar33 + -8) = 0x18002aae5;
            iVar47 = MultiByteToWideChar(0,0,pCVar3,-1,*(LPWSTR *)(puVar33 + 0x20),
                                         *(int *)(puVar33 + 0x28));
            *(undefined8 *)(puVar33 + -8) = 0x18002aaf2;
            pOVar18 = SysAllocStringLen((OLECHAR *)0x0,iVar47 - 1);
            if (pOVar18 != (BSTR)0x0) {
              *(int *)(puVar33 + 0x28) = iVar47;
              *(BSTR *)(puVar33 + 0x20) = pOVar18;
              *(undefined8 *)(puVar33 + -8) = 0x18002ab16;
              iVar10 = MultiByteToWideChar(0,0,pCVar3,-1,*(LPWSTR *)(puVar33 + 0x20),
                                           *(int *)(puVar33 + 0x28));
              if (iVar10 != iVar47) {
                *(undefined8 *)(puVar33 + -8) = 0x18002c985;
                SysFreeString(pOVar18);
                goto LAB_18002c985;
              }
            }
            local_828 = pOVar18;
            if (pOVar18 == (BSTR)0x0) {
LAB_18002c985:
                    /* WARNING: Subroutine does not return */
              *(undefined8 *)(puVar33 + -8) = 0x18002c98f;
              FUN_1800018d0(-0x7ff8fff2);
            }
          }
          pOVar18 = local_828;
          pCVar26 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                    ((longlong)local_780 + (longlong)local_708);
          *(undefined8 *)(puVar33 + -8) = 0x18002ab49;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_810,
                     pCVar26);
          pOVar42 = local_810;
          if (local_810 == (BSTR)0x0) {
            local_780 = local_810;
          }
          else {
            *(undefined4 *)(puVar33 + 0x28) = 0;
            *(undefined8 *)(puVar33 + 0x20) = 0;
            *(undefined8 *)(puVar33 + -8) = 0x18002ab6f;
            iVar47 = MultiByteToWideChar(0,0,(LPCSTR)pOVar42,-1,*(LPWSTR *)(puVar33 + 0x20),
                                         *(int *)(puVar33 + 0x28));
            *(undefined8 *)(puVar33 + -8) = 0x18002ab7d;
            pOVar19 = SysAllocStringLen((OLECHAR *)0x0,iVar47 - 1);
            if (pOVar19 != (BSTR)0x0) {
              *(int *)(puVar33 + 0x28) = iVar47;
              *(BSTR *)(puVar33 + 0x20) = pOVar19;
              *(undefined8 *)(puVar33 + -8) = 0x18002aba2;
              iVar10 = MultiByteToWideChar(0,0,(LPCSTR)pOVar42,-1,*(LPWSTR *)(puVar33 + 0x20),
                                           *(int *)(puVar33 + 0x28));
              if (iVar10 != iVar47) {
                *(undefined8 *)(puVar33 + -8) = 0x18002c999;
                SysFreeString(pOVar19);
                goto LAB_18002c999;
              }
            }
            local_780 = pOVar19;
            if (pOVar19 == (BSTR)0x0) {
LAB_18002c999:
                    /* WARNING: Subroutine does not return */
              *(undefined8 *)(puVar33 + -8) = 0x18002c9a3;
              FUN_1800018d0(-0x7ff8fff2);
            }
            pIVar15 = local_5d0;
          }
          pOVar42 = local_780;
          pWVar49 = (LPCWSTR)0x0;
          pcVar1 = *(code **)(*(longlong *)pIVar15 + 0xd8);
          local_7a0 = pWVar49;
          *(undefined8 *)(puVar33 + -8) = 0x18002abef;
          (*pcVar1)(pIVar15,pOVar18,&local_7a0);
          pWVar7 = local_7a0;
          if (local_7a0 != (LPCWSTR)0x0) {
            pcVar1 = *(code **)(*(longlong *)local_7a0 + 0xa0);
            local_760 = pWVar49;
            *(undefined8 *)(puVar33 + -8) = 0x18002ac17;
            (*pcVar1)(pWVar7,&local_760);
            pWVar7 = local_760;
            puVar31 = puVar33;
            if (local_760 != (LPCWSTR)0x0) {
              lVar40 = -1;
              do {
                lVar43 = lVar40;
                lVar40 = lVar43 + 1;
              } while (local_760[lVar40] != L'\0');
              iVar47 = (int)lVar43 + 2;
              if (iVar47 < 0x40000000) {
                lVar40 = (longlong)(int)lVar40 * 2;
                uVar41 = lVar40 + 0x11;
                if (uVar41 <= lVar40 + 2U) {
                  uVar41 = 0xffffffffffffff0;
                }
                *(undefined8 *)(puVar33 + -8) = 0x18002ac6f;
                lVar40 = -(uVar41 & 0xfffffffffffffff0);
                pWVar49 = (LPCWSTR)(puVar33 + lVar40 + 0x40);
                if (pWVar49 == (LPCWSTR)0x0) {
                  pWVar49 = (LPCWSTR)0x0;
                  puVar31 = puVar33 + lVar40;
                }
                else {
                  *(undefined1 *)pWVar49 = 0;
                  *(undefined8 *)(puVar33 + lVar40 + 0x38) = 0;
                  *(undefined8 *)(puVar33 + lVar40 + 0x30) = 0;
                  *(int *)(puVar33 + lVar40 + 0x28) = iVar47 * 2;
                  *(LPCWSTR *)(puVar33 + lVar40 + 0x20) = pWVar49;
                  *(undefined8 *)(puVar33 + lVar40 + -8) = 0x18002aca4;
                  iVar47 = WideCharToMultiByte(0,0,pWVar7,-1,*(LPSTR *)(puVar33 + lVar40 + 0x20),
                                               *(int *)(puVar33 + lVar40 + 0x28),
                                               *(LPCSTR *)(puVar33 + lVar40 + 0x30),
                                               *(LPBOOL *)(puVar33 + lVar40 + 0x38));
                  puVar31 = puVar33 + lVar40;
                  if (iVar47 == 0) {
                    pWVar49 = (LPCWSTR)0x0;
                    puVar31 = puVar33 + lVar40;
                  }
                }
              }
            }
            *(undefined8 *)(puVar31 + -8) = 0x18002acc6;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_788,
                       (char *)pWVar49);
            *(undefined8 *)(puVar31 + -8) = 0x18002acd4;
            pCVar26 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::MakeLower
                                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                 &local_788);
            *(undefined8 *)(puVar31 + -8) = 0x18002ace4;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_788,
                       pCVar26);
            pWVar49 = local_7a0;
            pcVar13 = (char *)0x0;
            local_698 = (LPCWSTR)0x0;
            pcVar1 = *(code **)(*(longlong *)local_7a0 + 0xa8);
            *(undefined8 *)(puVar31 + -8) = 0x18002ad05;
            (*pcVar1)(pWVar49,&local_698);
            pWVar49 = local_698;
            puVar33 = puVar31;
            if (local_698 != (LPCWSTR)0x0) {
              lVar40 = -1;
              do {
                lVar43 = lVar40;
                lVar40 = lVar43 + 1;
              } while (local_698[lVar40] != L'\0');
              iVar47 = (int)lVar43 + 2;
              if (iVar47 < 0x40000000) {
                lVar40 = (longlong)(int)lVar40 * 2;
                uVar41 = lVar40 + 0x11;
                if (uVar41 <= lVar40 + 2U) {
                  uVar41 = 0xffffffffffffff0;
                }
                *(undefined8 *)(puVar31 + -8) = 0x18002ad5f;
                lVar40 = -(uVar41 & 0xfffffffffffffff0);
                pcVar13 = puVar31 + lVar40 + 0x40;
                if (pcVar13 == (char *)0x0) {
                  pcVar13 = (char *)0x0;
                  puVar33 = puVar31 + lVar40;
                }
                else {
                  *pcVar13 = '\0';
                  *(undefined8 *)(puVar31 + lVar40 + 0x38) = 0;
                  *(undefined8 *)(puVar31 + lVar40 + 0x30) = 0;
                  *(int *)(puVar31 + lVar40 + 0x28) = iVar47 * 2;
                  *(char **)(puVar31 + lVar40 + 0x20) = pcVar13;
                  *(undefined8 *)(puVar31 + lVar40 + -8) = 0x18002ad94;
                  iVar47 = WideCharToMultiByte(0,0,pWVar49,-1,*(LPSTR *)(puVar31 + lVar40 + 0x20),
                                               *(int *)(puVar31 + lVar40 + 0x28),
                                               *(LPCSTR *)(puVar31 + lVar40 + 0x30),
                                               *(LPBOOL *)(puVar31 + lVar40 + 0x38));
                  puVar33 = puVar31 + lVar40;
                  if (iVar47 == 0) {
                    pcVar13 = (char *)0x0;
                    puVar33 = puVar31 + lVar40;
                  }
                }
              }
            }
            *(undefined8 *)(puVar33 + -8) = 0x18002adb6;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_6a8,pcVar13);
            pWVar49 = local_7a0;
            pcVar13 = (char *)0x0;
            local_690 = (LPCWSTR)0x0;
            pcVar1 = *(code **)(*(longlong *)local_7a0 + 0x68);
            *(undefined8 *)(puVar33 + -8) = 0x18002add5;
            iVar47 = (*pcVar1)(pWVar49,&local_690);
            pWVar49 = local_690;
            if (-1 < iVar47) {
              if (local_690 != (LPCWSTR)0x0) {
                lVar40 = -1;
                do {
                  lVar43 = lVar40;
                  lVar40 = lVar43 + 1;
                } while (local_690[lVar40] != L'\0');
                iVar47 = (int)lVar43 + 2;
                if (iVar47 < 0x40000000) {
                  lVar40 = (longlong)(int)lVar40 * 2;
                  uVar41 = lVar40 + 0x11;
                  if (uVar41 <= lVar40 + 2U) {
                    uVar41 = 0xffffffffffffff0;
                  }
                  *(undefined8 *)(puVar33 + -8) = 0x18002ae33;
                  lVar40 = -(uVar41 & 0xfffffffffffffff0);
                  puVar32 = puVar33 + lVar40;
                  pcVar13 = puVar33 + lVar40 + 0x40;
                  if (pcVar13 == (char *)0x0) {
                    pcVar13 = (char *)0x0;
                    puVar33 = puVar33 + lVar40;
                  }
                  else {
                    *pcVar13 = '\0';
                    *(undefined8 *)(puVar33 + lVar40 + 0x38) = 0;
                    *(undefined8 *)(puVar33 + lVar40 + 0x30) = 0;
                    *(int *)(puVar33 + lVar40 + 0x28) = iVar47 * 2;
                    *(char **)(puVar33 + lVar40 + 0x20) = pcVar13;
                    *(undefined8 *)(puVar33 + lVar40 + -8) = 0x18002ae68;
                    iVar47 = WideCharToMultiByte(0,0,pWVar49,-1,*(LPSTR *)(puVar33 + lVar40 + 0x20),
                                                 *(int *)(puVar33 + lVar40 + 0x28),
                                                 *(LPCSTR *)(puVar33 + lVar40 + 0x30),
                                                 *(LPBOOL *)(puVar33 + lVar40 + 0x38));
                    puVar33 = puVar33 + lVar40;
                    if (iVar47 == 0) {
                      pcVar13 = (char *)0x0;
                      puVar33 = puVar32;
                    }
                  }
                }
              }
              *(undefined8 *)(puVar33 + -8) = 0x18002ae8a;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_5f8,pcVar13);
              pcVar13 = local_788;
              *(undefined8 *)(puVar33 + -8) = 0x18002ae9c;
              iVar47 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                                 ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                  &local_7b0,pcVar13);
              if (iVar47 == 0) {
                pcVar1 = *(code **)(*(longlong *)pIVar15 + 0xe8);
                *(undefined8 *)(puVar33 + -8) = 0x18002aeb0;
                (*pcVar1)(pIVar15,pOVar4);
                pcVar1 = *(code **)(*(longlong *)pIVar15 + 0xe8);
                *(undefined8 *)(puVar33 + -8) = 0x18002aec0;
                (*pcVar1)(pIVar15,pOVar42);
              }
              else {
                *(undefined8 *)(puVar33 + -8) = 0x18002aed6;
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          (local_620,
                           (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                            *)&local_7f8);
                *(undefined8 *)(puVar33 + -8) = 0x18002aef2;
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Replace
                          (local_620,".atmlz","");
                pCVar16 = pCStack_6e8;
                if (pCStack_6e8 == local_6e0) {
                  *(undefined8 *)(puVar33 + -8) = 0x18002af2c;
                  FUN_180025400((longlong *)&local_6f0,
                                (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                 *)pCVar16,
                                (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                 *)&local_7f8);
                }
                else {
                  *(undefined8 *)(puVar33 + -8) = 0x18002af0f;
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                            (pCVar16,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                      *)&local_7f8);
                  pCStack_6e8 = pCStack_6e8 + 8;
                }
                if (*(int *)(local_7b8 + -0x10) != 0) {
                  *(undefined8 *)(puVar33 + -8) = 0x18002af47;
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_7b8,"|");
                }
                *(undefined8 *)(puVar33 + -8) = 0x18002af58;
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_7b8,(CSimpleStringT<char,1> *)local_620);
                *(undefined8 *)(puVar33 + -8) = 0x18002af69;
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_7b8,",");
                *(undefined8 *)(puVar33 + -8) = 0x18002af7a;
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_7b8,(CSimpleStringT<char,1> *)local_5f8);
                *(undefined8 *)(puVar33 + -8) = 0x18002af8b;
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_7b8,",");
                *(undefined8 *)(puVar33 + -8) = 0x18002af9c;
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_7b8,(CSimpleStringT<char,1> *)local_6a8);
                *(undefined8 *)(puVar33 + -8) = 0x18002afad;
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_7b8,",");
                *(undefined8 *)(puVar33 + -8) = 0x18002afbb;
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_7b8,(CSimpleStringT<char,1> *)&local_808);
                *(undefined8 *)(puVar33 + -8) = 0x18002afcc;
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_7b8,",");
                *(undefined8 *)(puVar33 + -8) = 0x18002afda;
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_7b8,(CSimpleStringT<char,1> *)&local_7d8);
                *(undefined8 *)(puVar33 + -8) = 0x18002afeb;
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_7b8,",");
                plVar6 = local_7d8;
                *(undefined8 *)(puVar33 + -8) = 0x18002affc;
                iVar47 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                                   (local_6a8,(char *)plVar6);
                pcVar13 = "Yes";
                if (-1 < iVar47) {
                  pcVar13 = "No";
                }
                *(undefined8 *)(puVar33 + -8) = 0x18002b018;
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_7b8,pcVar13);
                *(undefined8 *)(puVar33 + -8) = 0x18002b026;
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_620);
              }
              *(undefined8 *)(puVar33 + -8) = 0x18002b034;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_5f8);
            }
            pWVar49 = local_690;
            *(undefined8 *)(puVar33 + -8) = 0x18002b042;
            SysFreeString(pWVar49);
            *(undefined8 *)(puVar33 + -8) = 0x18002b050;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_6a8);
            pWVar49 = local_698;
            *(undefined8 *)(puVar33 + -8) = 0x18002b05e;
            SysFreeString(pWVar49);
            *(undefined8 *)(puVar33 + -8) = 0x18002b06c;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_788);
            pWVar49 = local_760;
            *(undefined8 *)(puVar33 + -8) = 0x18002b07a;
            SysFreeString(pWVar49);
            if (local_7a0 != (LPCWSTR)0x0) {
              pcVar1 = *(code **)(*(longlong *)local_7a0 + 0x10);
              *(undefined8 *)(puVar33 + -8) = 0x18002b08d;
              (*pcVar1)();
            }
          }
          *(undefined8 *)(puVar33 + -8) = 0x18002b097;
          SysFreeString(pOVar42);
          *(undefined8 *)(puVar33 + -8) = 0x18002b0a2;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_810);
          *(undefined8 *)(puVar33 + -8) = 0x18002b0ac;
          SysFreeString(pOVar18);
          *(undefined8 *)(puVar33 + -8) = 0x18002b0b7;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_808);
          pWVar49 = local_7d0;
          *(undefined8 *)(puVar33 + -8) = 0x18002b0c2;
          SysFreeString(pWVar49);
          *(undefined8 *)(puVar33 + -8) = 0x18002b0cd;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7d8);
          pWVar49 = local_800;
          *(undefined8 *)(puVar33 + -8) = 0x18002b0d8;
          SysFreeString(pWVar49);
          *(undefined8 *)(puVar33 + -8) = 0x18002b0e3;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7b0);
          pOVar18 = local_818;
          *(undefined8 *)(puVar33 + -8) = 0x18002b0ee;
          SysFreeString(pOVar18);
          if (local_7c8 != (BSTR)0x0) {
            pcVar1 = *(code **)(*(longlong *)local_7c8 + 0x10);
            *(undefined8 *)(puVar33 + -8) = 0x18002b0fe;
            (*pcVar1)();
          }
          *(undefined8 *)(puVar33 + -8) = 0x18002b108;
          SysFreeString(pOVar4);
          *(undefined8 *)(puVar33 + -8) = 0x18002b113;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7f8);
          *(undefined8 *)(puVar33 + -8) = 0x18002b11d;
          SysFreeString(pOVar20);
        }
        iVar10 = (int)local_770 + 1;
        local_770 = (BSTR)CONCAT44(local_770._4_4_,iVar10);
        local_750 = local_750 + 1;
      } while (local_750 < local_5c8);
    }
    *(undefined8 *)(puVar33 + -8) = 0x18002b160;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_778);
    *(undefined8 *)(puVar33 + -8) = 0x18002b16b;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7e0);
    *(undefined8 *)(puVar33 + -8) = 0x18002b179;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_6a0);
    pCVar25 = pCStack_5e0;
    pCVar16 = local_5e8;
    if (local_5e8 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
      for (; pCVar16 != pCVar25; pCVar16 = pCVar16 + 8) {
        *(undefined8 *)(puVar33 + -8) = 0x18002b19b;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar16);
      }
      pCVar16 = local_5e8;
      if ((0xfff < (ulonglong)((local_5d8 - (longlong)local_5e8 >> 3) * 8)) &&
         (pCVar16 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                     (local_5e8 + -8),
         (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x1f <
         local_5e8 + (-8 - (longlong)pCVar16))) {
                    /* WARNING: Subroutine does not return */
        *(undefined **)(puVar33 + -8) = &UNK_18002b1e8;
        _invalid_parameter_noinfo_noreturn();
      }
      *(undefined8 *)(puVar33 + -8) = 0x18002b1f1;
      FUN_180035134(pCVar16);
    }
    pcVar13 = local_798;
  }
LAB_18002b1fa:
  if (pcVar13 == (char *)0xffffffffffffffff) {
    local_828 = (BSTR)CONCAT44(local_828._4_4_,1);
  }
  else {
    *(undefined8 *)(puVar33 + -8) = 0x18002b213;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7c0);
    local_670 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    pCStack_668 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    local_660 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    local_6c0 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    pCStack_6b8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    local_6b0 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    local_738 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    pCStack_730 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    local_728 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    local_6d8 = (void *)0x0;
    puStack_6d0 = (undefined4 *)0x0;
    local_6c8 = (undefined4 *)0x0;
    do {
      *(undefined8 *)(puVar33 + -8) = 0x18002b25d;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7b0);
      *(CHAR **)(puVar33 + 0x20) = local_5b8.cFileName;
      *(undefined8 *)(puVar33 + -8) = 0x18002b289;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7b0,
                 "%s%sACM_Models\\%s",local_7a8,local_338);
      pCVar3 = local_7b0;
      if (local_7b0 == (LPCSTR)0x0) {
        local_780 = (BSTR)0x0;
      }
      else {
        *(undefined4 *)(puVar33 + 0x28) = 0;
        *(undefined8 *)(puVar33 + 0x20) = 0;
        *(undefined8 *)(puVar33 + -8) = 0x18002b2ae;
        iVar47 = MultiByteToWideChar(0,0,pCVar3,-1,*(LPWSTR *)(puVar33 + 0x20),
                                     *(int *)(puVar33 + 0x28));
        *(undefined8 *)(puVar33 + -8) = 0x18002b2bb;
        pOVar20 = SysAllocStringLen((OLECHAR *)0x0,iVar47 - 1);
        if (pOVar20 != (BSTR)0x0) {
          *(int *)(puVar33 + 0x28) = iVar47;
          *(BSTR *)(puVar33 + 0x20) = pOVar20;
          *(undefined8 *)(puVar33 + -8) = 0x18002b2df;
          iVar10 = MultiByteToWideChar(0,0,pCVar3,-1,*(LPWSTR *)(puVar33 + 0x20),
                                       *(int *)(puVar33 + 0x28));
          if (iVar10 != iVar47) {
            *(undefined8 *)(puVar33 + -8) = 0x18002c9ad;
            SysFreeString(pOVar20);
            goto LAB_18002c9ad;
          }
        }
        local_780 = pOVar20;
        if (pOVar20 == (BSTR)0x0) {
LAB_18002c9ad:
                    /* WARNING: Subroutine does not return */
          *(undefined8 *)(puVar33 + -8) = 0x18002c9b7;
          FUN_1800018d0(-0x7ff8fff2);
        }
      }
      pOVar20 = local_780;
      *(undefined8 *)(puVar33 + -8) = 0x18002b316;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_800,
                 local_5b8.cFileName);
      *(undefined8 *)(puVar33 + -8) = 0x18002b323;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_800,'.');
      *(undefined8 *)(puVar33 + -8) = 0x18002b337;
      pCVar26 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_800,(int)local_6a0);
      *(undefined8 *)(puVar33 + -8) = 0x18002b345;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_800,pCVar26
                );
      *(undefined8 *)(puVar33 + -8) = 0x18002b353;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_6a0);
      pWVar49 = local_800;
      if (local_800 == (BSTR)0x0) {
        local_740 = (BSTR)0x0;
      }
      else {
        *(undefined4 *)(puVar33 + 0x28) = 0;
        *(undefined8 *)(puVar33 + 0x20) = 0;
        *(undefined8 *)(puVar33 + -8) = 0x18002b378;
        iVar47 = MultiByteToWideChar(0,0,(LPCSTR)pWVar49,-1,*(LPWSTR *)(puVar33 + 0x20),
                                     *(int *)(puVar33 + 0x28));
        *(undefined8 *)(puVar33 + -8) = 0x18002b385;
        pOVar18 = SysAllocStringLen((OLECHAR *)0x0,iVar47 - 1);
        if (pOVar18 != (BSTR)0x0) {
          *(int *)(puVar33 + 0x28) = iVar47;
          *(BSTR *)(puVar33 + 0x20) = pOVar18;
          *(undefined8 *)(puVar33 + -8) = 0x18002b3a9;
          iVar10 = MultiByteToWideChar(0,0,(LPCSTR)pWVar49,-1,*(LPWSTR *)(puVar33 + 0x20),
                                       *(int *)(puVar33 + 0x28));
          if (iVar10 != iVar47) {
            *(undefined8 *)(puVar33 + -8) = 0x18002c9c1;
            SysFreeString(pOVar18);
            goto LAB_18002c9c1;
          }
        }
        local_740 = pOVar18;
        if (pOVar18 == (BSTR)0x0) {
LAB_18002c9c1:
                    /* WARNING: Subroutine does not return */
          *(undefined **)(puVar33 + -8) = &UNK_18002c9cb;
          FUN_1800018d0(-0x7ff8fff2);
        }
      }
      pOVar18 = local_740;
      pcVar13 = (char *)0x0;
      local_818 = (BSTR)0x0;
      pcVar1 = *(code **)(*(longlong *)pIVar15 + 0x98);
      *(undefined8 *)(puVar33 + -8) = 0x18002b3e7;
      iVar47 = (*pcVar1)(pIVar15,pOVar18,&local_818);
      if ((iVar47 < 0) || (local_818 == (BSTR)0x0)) {
        pcVar1 = *(code **)(*(longlong *)pIVar15 + 0xa8);
        *(undefined8 *)(puVar33 + -8) = 0x18002b408;
        iVar47 = (*pcVar1)(pIVar15,pOVar18,&local_818);
        if ((-1 < iVar47) && (local_818 != (BSTR)0x0)) goto LAB_18002b41d;
        local_828 = (BSTR)((ulonglong)local_828 & 0xffffffffffff0000);
        pcVar1 = *(code **)(*(longlong *)pIVar15 + 0xb0);
        *(undefined8 *)(puVar33 + -8) = 0x18002bd35;
        iVar47 = (*pcVar1)(pIVar15,pOVar20,0xffffffff,&local_828);
        pCVar16 = pCStack_730;
        if ((iVar47 < 0) || ((short)local_828 == 0)) {
          if (pCStack_730 == local_728) {
            *(undefined8 *)(puVar33 + -8) = 0x18002bd7a;
            FUN_180025400((longlong *)&local_738,
                          (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                           *)pCVar16,
                          (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                           *)&local_800);
          }
          else {
            *(undefined8 *)(puVar33 + -8) = 0x18002bd5d;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      (pCVar16,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                *)&local_800);
            pCStack_730 = pCStack_730 + 8;
          }
        }
        goto LAB_18002bd7b;
      }
LAB_18002b41d:
      pOVar4 = local_818;
      local_7d0 = (LPCWSTR)0x0;
      pcVar1 = *(code **)(*(longlong *)local_818 + 0x68);
      *(undefined8 *)(puVar33 + -8) = 0x18002b42b;
      iVar47 = (*pcVar1)(pOVar4,&local_7d0);
      pWVar49 = local_7d0;
      if (iVar47 < 0) {
LAB_18002bd0b:
        pWVar49 = local_7d0;
        *(undefined8 *)(puVar33 + -8) = 0x18002bd15;
        SysFreeString(pWVar49);
      }
      else {
        if (local_7d0 != (LPCWSTR)0x0) {
          lVar40 = -1;
          do {
            lVar43 = lVar40;
            lVar40 = lVar43 + 1;
          } while (local_7d0[lVar40] != L'\0');
          iVar47 = (int)lVar43 + 2;
          if (iVar47 < 0x40000000) {
            lVar40 = (longlong)(int)lVar40 * 2;
            uVar41 = lVar40 + 0x11;
            if (uVar41 <= lVar40 + 2U) {
              uVar41 = 0xffffffffffffff0;
            }
            *(undefined8 *)(puVar33 + -8) = 0x18002b48f;
            lVar40 = -(uVar41 & 0xfffffffffffffff0);
            puVar34 = puVar33 + lVar40;
            pcVar13 = puVar33 + lVar40 + 0x40;
            if (pcVar13 == (char *)0x0) {
              pcVar13 = (char *)0x0;
              puVar33 = puVar33 + lVar40;
            }
            else {
              *pcVar13 = '\0';
              *(undefined8 *)(puVar33 + lVar40 + 0x38) = 0;
              *(undefined8 *)(puVar33 + lVar40 + 0x30) = 0;
              *(int *)(puVar33 + lVar40 + 0x28) = iVar47 * 2;
              *(char **)(puVar33 + lVar40 + 0x20) = pcVar13;
              *(undefined8 *)(puVar33 + lVar40 + -8) = 0x18002b4c6;
              iVar47 = WideCharToMultiByte(0,0,pWVar49,-1,*(LPSTR *)(puVar33 + lVar40 + 0x20),
                                           *(int *)(puVar33 + lVar40 + 0x28),
                                           *(LPCSTR *)(puVar33 + lVar40 + 0x30),
                                           *(LPBOOL *)(puVar33 + lVar40 + 0x38));
              puVar33 = puVar33 + lVar40;
              if (iVar47 == 0) {
                pcVar13 = (char *)0x0;
                puVar33 = puVar34;
              }
            }
          }
        }
        *(undefined8 *)(puVar33 + -8) = 0x18002b4df;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7f8,
                   pcVar13);
        pcVar13 = (char *)0x0;
        local_7d8 = (longlong *)0x0;
        pcVar1 = *(code **)(*(longlong *)pIVar15 + 0xd8);
        *(undefined8 *)(puVar33 + -8) = 0x18002b4fa;
        iVar47 = (*pcVar1)(pIVar15,pOVar20,&local_7d8);
        plVar6 = local_7d8;
        if ((iVar47 < 0) || (local_7d8 == (longlong *)0x0)) {
LAB_18002bcf4:
          if (local_7d8 != (longlong *)0x0) {
            pcVar1 = *(code **)(*local_7d8 + 0x10);
            *(undefined8 *)(puVar33 + -8) = 0x18002bcff;
            (*pcVar1)();
          }
          *(undefined8 *)(puVar33 + -8) = 0x18002bd0a;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7f8);
          goto LAB_18002bd0b;
        }
        local_7c8 = (BSTR)0x0;
        pcVar1 = *(code **)(*local_7d8 + 0x68);
        *(undefined8 *)(puVar33 + -8) = 0x18002b51d;
        iVar47 = (*pcVar1)(plVar6,&local_7c8);
        pOVar4 = local_7c8;
        if (iVar47 < 0) {
          *(undefined8 *)(puVar33 + -8) = 0x18002b52b;
          SysFreeString(pOVar4);
          goto LAB_18002bcf4;
        }
        if (local_7c8 != (BSTR)0x0) {
          lVar40 = -1;
          do {
            lVar43 = lVar40;
            lVar40 = lVar43 + 1;
          } while (local_7c8[lVar40] != L'\0');
          iVar47 = (int)lVar43 + 2;
          if (iVar47 < 0x40000000) {
            lVar40 = (longlong)(int)lVar40 * 2;
            uVar41 = lVar40 + 0x11;
            if (uVar41 <= lVar40 + 2U) {
              uVar41 = 0xffffffffffffff0;
            }
            *(undefined8 *)(puVar33 + -8) = 0x18002b58f;
            lVar40 = -(uVar41 & 0xfffffffffffffff0);
            puVar35 = puVar33 + lVar40;
            pcVar13 = puVar33 + lVar40 + 0x40;
            if (pcVar13 == (char *)0x0) {
              pcVar13 = (char *)0x0;
              puVar33 = puVar33 + lVar40;
            }
            else {
              *pcVar13 = '\0';
              *(undefined8 *)(puVar33 + lVar40 + 0x38) = 0;
              *(undefined8 *)(puVar33 + lVar40 + 0x30) = 0;
              *(int *)(puVar33 + lVar40 + 0x28) = iVar47 * 2;
              *(char **)(puVar33 + lVar40 + 0x20) = pcVar13;
              *(undefined8 *)(puVar33 + lVar40 + -8) = 0x18002b5c6;
              iVar47 = WideCharToMultiByte(0,0,pOVar4,-1,*(LPSTR *)(puVar33 + lVar40 + 0x20),
                                           *(int *)(puVar33 + lVar40 + 0x28),
                                           *(LPCSTR *)(puVar33 + lVar40 + 0x30),
                                           *(LPBOOL *)(puVar33 + lVar40 + 0x38));
              puVar33 = puVar33 + lVar40;
              if (iVar47 == 0) {
                pcVar13 = (char *)0x0;
                puVar33 = puVar35;
              }
            }
          }
        }
        *(undefined8 *)(puVar33 + -8) = 0x18002b5e2;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7a0,
                   pcVar13);
        *(undefined8 *)(puVar33 + -8) = 0x18002b5f0;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_788);
        pWVar49 = local_7a0;
        *(undefined8 *)(puVar33 + -8) = 0x18002b602;
        iVar47 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                           ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_7f8,(char *)pWVar49);
        pOVar4 = local_818;
        if (iVar47 != 0) {
LAB_18002b87c:
          pOVar4 = local_818;
          pcVar13 = (char *)0x0;
          local_7f0 = (BSTR)0x0;
          pcVar1 = *(code **)(*(longlong *)local_818 + 0xa8);
          *(undefined8 *)(puVar33 + -8) = 0x18002b893;
          iVar10 = (*pcVar1)(pOVar4,&local_7f0);
          pOVar4 = local_7f0;
          if (iVar10 < 0) {
            *(undefined8 *)(puVar33 + -8) = 0x18002b8a1;
            SysFreeString(pOVar4);
            *(undefined8 *)(puVar33 + -8) = 0x18002b8af;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_788);
            *(undefined8 *)(puVar33 + -8) = 0x18002b8bd;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7a0);
            pOVar4 = local_7c8;
            *(undefined8 *)(puVar33 + -8) = 0x18002b8c8;
            SysFreeString(pOVar4);
          }
          else {
            if (local_7f0 != (BSTR)0x0) {
              lVar40 = -1;
              do {
                lVar43 = lVar40;
                lVar40 = lVar43 + 1;
              } while (local_7f0[lVar40] != L'\0');
              iVar10 = (int)lVar43 + 2;
              if (iVar10 < 0x40000000) {
                lVar40 = (longlong)(int)lVar40 * 2;
                uVar41 = lVar40 + 0x11;
                if (uVar41 <= lVar40 + 2U) {
                  uVar41 = 0xffffffffffffff0;
                }
                *(undefined8 *)(puVar33 + -8) = 0x18002b92f;
                lVar40 = -(uVar41 & 0xfffffffffffffff0);
                puVar38 = puVar33 + lVar40;
                pcVar13 = puVar33 + lVar40 + 0x40;
                if (pcVar13 == (char *)0x0) {
                  pcVar13 = (char *)0x0;
                  puVar33 = puVar33 + lVar40;
                }
                else {
                  *pcVar13 = '\0';
                  *(undefined8 *)(puVar33 + lVar40 + 0x38) = 0;
                  *(undefined8 *)(puVar33 + lVar40 + 0x30) = 0;
                  *(int *)(puVar33 + lVar40 + 0x28) = iVar10 * 2;
                  *(char **)(puVar33 + lVar40 + 0x20) = pcVar13;
                  *(undefined8 *)(puVar33 + lVar40 + -8) = 0x18002b963;
                  iVar10 = WideCharToMultiByte(0,0,pOVar4,-1,*(LPSTR *)(puVar33 + lVar40 + 0x20),
                                               *(int *)(puVar33 + lVar40 + 0x28),
                                               *(LPCSTR *)(puVar33 + lVar40 + 0x30),
                                               *(LPBOOL *)(puVar33 + lVar40 + 0x38));
                  puVar33 = puVar33 + lVar40;
                  if (iVar10 == 0) {
                    pcVar13 = (char *)0x0;
                    puVar33 = puVar38;
                  }
                }
              }
            }
            *(undefined8 *)(puVar33 + -8) = 0x18002b984;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_760,
                       pcVar13);
            plVar6 = local_7d8;
            pcVar13 = (char *)0x0;
            local_810 = (BSTR)0x0;
            pcVar1 = *(code **)(*local_7d8 + 0xa8);
            *(undefined8 *)(puVar33 + -8) = 0x18002b99c;
            iVar10 = (*pcVar1)(plVar6,&local_810);
            pOVar4 = local_810;
            if (-1 < iVar10) {
              if (local_810 != (BSTR)0x0) {
                lVar40 = -1;
                do {
                  lVar43 = lVar40;
                  lVar40 = lVar43 + 1;
                } while (local_810[lVar40] != L'\0');
                iVar10 = (int)lVar43 + 2;
                if (iVar10 < 0x40000000) {
                  lVar40 = (longlong)(int)lVar40 * 2;
                  uVar41 = lVar40 + 0x11;
                  if (uVar41 <= lVar40 + 2U) {
                    uVar41 = 0xffffffffffffff0;
                  }
                  *(undefined8 *)(puVar33 + -8) = 0x18002ba4f;
                  lVar40 = -(uVar41 & 0xfffffffffffffff0);
                  puVar39 = puVar33 + lVar40;
                  pcVar13 = puVar33 + lVar40 + 0x40;
                  if (pcVar13 == (char *)0x0) {
                    pcVar13 = (char *)0x0;
                    puVar33 = puVar33 + lVar40;
                  }
                  else {
                    *pcVar13 = '\0';
                    *(undefined8 *)(puVar33 + lVar40 + 0x38) = 0;
                    *(undefined8 *)(puVar33 + lVar40 + 0x30) = 0;
                    *(int *)(puVar33 + lVar40 + 0x28) = iVar10 * 2;
                    *(char **)(puVar33 + lVar40 + 0x20) = pcVar13;
                    *(undefined8 *)(puVar33 + lVar40 + -8) = 0x18002ba83;
                    iVar10 = WideCharToMultiByte(0,0,pOVar4,-1,*(LPSTR *)(puVar33 + lVar40 + 0x20),
                                                 *(int *)(puVar33 + lVar40 + 0x28),
                                                 *(LPCSTR *)(puVar33 + lVar40 + 0x30),
                                                 *(LPBOOL *)(puVar33 + lVar40 + 0x38));
                    puVar33 = puVar33 + lVar40;
                    if (iVar10 == 0) {
                      pcVar13 = (char *)0x0;
                      puVar33 = puVar39;
                    }
                  }
                }
              }
              *(undefined8 *)(puVar33 + -8) = 0x18002baa4;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_778
                         ,pcVar13);
              if (*(int *)(local_7c0 + -0x10) != 0) {
                *(undefined8 *)(puVar33 + -8) = 0x18002bac0;
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_7c0,"|");
              }
              *(undefined8 *)(puVar33 + -8) = 0x18002bace;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7c0
                         ,(CSimpleStringT<char,1> *)&local_800);
              *(undefined8 *)(puVar33 + -8) = 0x18002badf;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7c0
                         ,",");
              *(undefined8 *)(puVar33 + -8) = 0x18002baed;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7c0
                         ,(CSimpleStringT<char,1> *)&local_7f8);
              *(undefined8 *)(puVar33 + -8) = 0x18002bafe;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7c0
                         ,",");
              *(undefined8 *)(puVar33 + -8) = 0x18002bb0f;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7c0
                         ,(CSimpleStringT<char,1> *)&local_760);
              *(undefined8 *)(puVar33 + -8) = 0x18002bb20;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7c0
                         ,",");
              *(undefined8 *)(puVar33 + -8) = 0x18002bb31;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7c0
                         ,(CSimpleStringT<char,1> *)&local_7a0);
              *(undefined8 *)(puVar33 + -8) = 0x18002bb42;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7c0
                         ,",");
              *(undefined8 *)(puVar33 + -8) = 0x18002bb53;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7c0
                         ,(CSimpleStringT<char,1> *)&local_778);
              *(undefined8 *)(puVar33 + -8) = 0x18002bb64;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7c0
                         ,",");
              pCVar3 = local_778;
              *(undefined8 *)(puVar33 + -8) = 0x18002bb78;
              iVar10 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                                 ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                  &local_760,pCVar3);
              if ((iVar47 < 0) || ((iVar47 == 0 && (iVar10 < 0)))) {
                pcVar13 = "Yes";
              }
              else {
                pcVar13 = "No";
              }
              *(undefined8 *)(puVar33 + -8) = 0x18002bb9f;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7c0
                         ,pcVar13);
              pCVar16 = pCStack_6b8;
              if (pCStack_6b8 == local_6b0) {
                *(undefined8 *)(puVar33 + -8) = 0x18002bbd9;
                FUN_180025400((longlong *)&local_6c0,
                              (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                               *)pCVar16,
                              (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                               *)&local_7b0);
              }
              else {
                *(undefined8 *)(puVar33 + -8) = 0x18002bbbc;
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          (pCVar16,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                    *)&local_7b0);
                pCStack_6b8 = pCStack_6b8 + 8;
              }
              pCVar16 = pCStack_668;
              if (pCStack_668 == local_660) {
                *(undefined8 *)(puVar33 + -8) = 0x18002bc13;
                FUN_180025400((longlong *)&local_670,
                              (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                               *)pCVar16,
                              (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                               *)&local_800);
              }
              else {
                *(undefined8 *)(puVar33 + -8) = 0x18002bbf6;
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          (pCVar16,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                    *)&local_800);
                pCStack_668 = pCStack_668 + 8;
              }
              puVar27 = puStack_6d0;
              if (local_820 != '\0') {
                if ((iVar47 < 0) || ((iVar47 == 0 && (iVar10 < 0)))) {
                  uVar12 = 1;
                }
                else {
                  uVar12 = 0;
                }
                local_770 = (BSTR)CONCAT44(local_770._4_4_,uVar12);
                if (puStack_6d0 == local_6c8) {
                  *(undefined8 *)(puVar33 + -8) = 0x18002bc60;
                  FUN_1800072c0((longlong *)&local_6d8,puVar27,(undefined4 *)&local_770);
                }
                else {
                  *puStack_6d0 = uVar12;
                  puStack_6d0 = puStack_6d0 + 1;
                }
              }
              pcVar1 = *(code **)(*(longlong *)pIVar15 + 0xe8);
              *(undefined8 *)(puVar33 + -8) = 0x18002bc70;
              (*pcVar1)(pIVar15,pOVar18);
              *(undefined8 *)(puVar33 + -8) = 0x18002bc7e;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_778
                        );
              pOVar4 = local_810;
              *(undefined8 *)(puVar33 + -8) = 0x18002bc89;
              SysFreeString(pOVar4);
              *(undefined8 *)(puVar33 + -8) = 0x18002bc97;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_760
                        );
              pOVar4 = local_7f0;
              *(undefined8 *)(puVar33 + -8) = 0x18002bca2;
              SysFreeString(pOVar4);
              *(undefined8 *)(puVar33 + -8) = 0x18002bcb0;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_788
                        );
              *(undefined8 *)(puVar33 + -8) = 0x18002bcbe;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7a0
                        );
              pOVar4 = local_7c8;
              *(undefined8 *)(puVar33 + -8) = 0x18002bcc9;
              SysFreeString(pOVar4);
              if (local_7d8 != (longlong *)0x0) {
                pcVar1 = *(code **)(*local_7d8 + 0x10);
                *(undefined8 *)(puVar33 + -8) = 0x18002bcd9;
                (*pcVar1)();
              }
              *(undefined8 *)(puVar33 + -8) = 0x18002bce4;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7f8
                        );
              pWVar49 = local_7d0;
              *(undefined8 *)(puVar33 + -8) = 0x18002bcef;
              SysFreeString(pWVar49);
              goto LAB_18002bd7b;
            }
            *(undefined8 *)(puVar33 + -8) = 0x18002b9aa;
            SysFreeString(pOVar4);
            *(undefined8 *)(puVar33 + -8) = 0x18002b9b8;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_760);
            pOVar4 = local_7f0;
            *(undefined8 *)(puVar33 + -8) = 0x18002b9c3;
            SysFreeString(pOVar4);
            *(undefined8 *)(puVar33 + -8) = 0x18002b9d1;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_788);
            *(undefined8 *)(puVar33 + -8) = 0x18002b9df;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7a0);
            pOVar4 = local_7c8;
            *(undefined8 *)(puVar33 + -8) = 0x18002b9ea;
            SysFreeString(pOVar4);
          }
          goto LAB_18002bcf4;
        }
        pcVar13 = (char *)0x0;
        local_770 = (LPCWSTR)0x0;
        pcVar1 = *(code **)(*(longlong *)local_818 + 0xa0);
        *(undefined8 *)(puVar33 + -8) = 0x18002b62b;
        iVar10 = (*pcVar1)(pOVar4,&local_770);
        pWVar49 = local_770;
        if (-1 < iVar10) {
          if (local_770 != (LPCWSTR)0x0) {
            lVar40 = -1;
            do {
              lVar43 = lVar40;
              lVar40 = lVar43 + 1;
            } while (local_770[lVar40] != L'\0');
            iVar10 = (int)lVar43 + 2;
            if (iVar10 < 0x40000000) {
              lVar40 = (longlong)(int)lVar40 * 2;
              uVar41 = lVar40 + 0x11;
              if (uVar41 <= lVar40 + 2U) {
                uVar41 = 0xffffffffffffff0;
              }
              *(undefined8 *)(puVar33 + -8) = 0x18002b68f;
              lVar40 = -(uVar41 & 0xfffffffffffffff0);
              puVar36 = puVar33 + lVar40;
              pcVar13 = puVar33 + lVar40 + 0x40;
              if (pcVar13 == (char *)0x0) {
                pcVar13 = (char *)0x0;
                puVar33 = puVar33 + lVar40;
              }
              else {
                *pcVar13 = '\0';
                *(undefined8 *)(puVar33 + lVar40 + 0x38) = 0;
                *(undefined8 *)(puVar33 + lVar40 + 0x30) = 0;
                *(int *)(puVar33 + lVar40 + 0x28) = iVar10 * 2;
                *(char **)(puVar33 + lVar40 + 0x20) = pcVar13;
                *(undefined8 *)(puVar33 + lVar40 + -8) = 0x18002b6c3;
                iVar10 = WideCharToMultiByte(0,0,pWVar49,-1,*(LPSTR *)(puVar33 + lVar40 + 0x20),
                                             *(int *)(puVar33 + lVar40 + 0x28),
                                             *(LPCSTR *)(puVar33 + lVar40 + 0x30),
                                             *(LPBOOL *)(puVar33 + lVar40 + 0x38));
                puVar33 = puVar33 + lVar40;
                if (iVar10 == 0) {
                  pcVar13 = (char *)0x0;
                  puVar33 = puVar36;
                }
              }
            }
          }
          *(undefined8 *)(puVar33 + -8) = 0x18002b6e1;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_808,
                     pcVar13);
          plVar6 = local_7d8;
          pcVar13 = (char *)0x0;
          local_7e8 = (LPCWSTR)0x0;
          pcVar1 = *(code **)(*local_7d8 + 0xa0);
          *(undefined8 *)(puVar33 + -8) = 0x18002b6f9;
          iVar10 = (*pcVar1)(plVar6,&local_7e8);
          pWVar49 = local_7e8;
          if (-1 < iVar10) {
            if (local_7e8 != (LPCWSTR)0x0) {
              lVar40 = -1;
              do {
                lVar43 = lVar40;
                lVar40 = lVar43 + 1;
              } while (local_7e8[lVar40] != L'\0');
              iVar10 = (int)lVar43 + 2;
              if (iVar10 < 0x40000000) {
                lVar40 = (longlong)(int)lVar40 * 2;
                uVar41 = lVar40 + 0x11;
                if (uVar41 <= lVar40 + 2U) {
                  uVar41 = 0xffffffffffffff0;
                }
                *(undefined8 *)(puVar33 + -8) = 0x18002b754;
                lVar40 = -(uVar41 & 0xfffffffffffffff0);
                puVar37 = puVar33 + lVar40;
                pcVar13 = puVar33 + lVar40 + 0x40;
                if (pcVar13 == (char *)0x0) {
                  pcVar13 = (char *)0x0;
                  puVar33 = puVar33 + lVar40;
                }
                else {
                  *pcVar13 = '\0';
                  *(undefined8 *)(puVar33 + lVar40 + 0x38) = 0;
                  *(undefined8 *)(puVar33 + lVar40 + 0x30) = 0;
                  *(int *)(puVar33 + lVar40 + 0x28) = iVar10 * 2;
                  *(char **)(puVar33 + lVar40 + 0x20) = pcVar13;
                  *(undefined8 *)(puVar33 + lVar40 + -8) = 0x18002b788;
                  iVar10 = WideCharToMultiByte(0,0,pWVar49,-1,*(LPSTR *)(puVar33 + lVar40 + 0x20),
                                               *(int *)(puVar33 + lVar40 + 0x28),
                                               *(LPCSTR *)(puVar33 + lVar40 + 0x30),
                                               *(LPBOOL *)(puVar33 + lVar40 + 0x38));
                  puVar33 = puVar33 + lVar40;
                  if (iVar10 == 0) {
                    pcVar13 = (char *)0x0;
                    puVar33 = puVar37;
                  }
                }
              }
            }
            *(undefined8 *)(puVar33 + -8) = 0x18002b7a6;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7e0,
                       pcVar13);
            pOVar4 = local_7e0;
            *(undefined8 *)(puVar33 + -8) = 0x18002b7b5;
            iVar10 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                               ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                &local_808,(char *)pOVar4);
            if (iVar10 != 0) {
              *(undefined8 *)(puVar33 + -8) = 0x18002b858;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7e0
                        );
              pWVar49 = local_7e8;
              *(undefined8 *)(puVar33 + -8) = 0x18002b863;
              SysFreeString(pWVar49);
              *(undefined8 *)(puVar33 + -8) = 0x18002b86e;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_808
                        );
              pOVar4 = local_770;
              *(undefined8 *)(puVar33 + -8) = 0x18002b87c;
              SysFreeString(pOVar4);
              goto LAB_18002b87c;
            }
            pcVar1 = *(code **)(*(longlong *)pIVar15 + 0xe8);
            *(undefined8 *)(puVar33 + -8) = 0x18002b7cd;
            (*pcVar1)(pIVar15,pOVar18);
            *(undefined8 *)(puVar33 + -8) = 0x18002b7d8;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7e0);
          }
          pWVar49 = local_7e8;
          *(undefined8 *)(puVar33 + -8) = 0x18002b7e3;
          SysFreeString(pWVar49);
          *(undefined8 *)(puVar33 + -8) = 0x18002b7ee;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_808);
        }
        pOVar4 = local_770;
        *(undefined8 *)(puVar33 + -8) = 0x18002b7fc;
        SysFreeString(pOVar4);
        *(undefined8 *)(puVar33 + -8) = 0x18002b80a;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_788);
        *(undefined8 *)(puVar33 + -8) = 0x18002b818;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7a0);
        pOVar4 = local_7c8;
        *(undefined8 *)(puVar33 + -8) = 0x18002b823;
        SysFreeString(pOVar4);
        if (local_7d8 != (longlong *)0x0) {
          pcVar1 = *(code **)(*local_7d8 + 0x10);
          *(undefined8 *)(puVar33 + -8) = 0x18002b833;
          (*pcVar1)();
        }
        *(undefined8 *)(puVar33 + -8) = 0x18002b83e;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7f8);
        pWVar49 = local_7d0;
        *(undefined8 *)(puVar33 + -8) = 0x18002b849;
        SysFreeString(pWVar49);
      }
LAB_18002bd7b:
      if (local_818 != (BSTR)0x0) {
        pcVar1 = *(code **)(*(longlong *)local_818 + 0x10);
        *(undefined8 *)(puVar33 + -8) = 0x18002bd8a;
        (*pcVar1)();
      }
      *(undefined8 *)(puVar33 + -8) = 0x18002bd94;
      SysFreeString(pOVar18);
      *(undefined8 *)(puVar33 + -8) = 0x18002bd9f;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_800);
      *(undefined8 *)(puVar33 + -8) = 0x18002bda9;
      SysFreeString(pOVar20);
      *(undefined8 *)(puVar33 + -8) = 0x18002bdb4;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7b0);
      pcVar13 = local_798;
      *(undefined8 *)(puVar33 + -8) = 0x18002bdcb;
      BVar9 = FindNextFileA(pcVar13,&local_5b8);
    } while (BVar9 != 0);
    *(undefined8 *)(puVar33 + -8) = 0x18002bddf;
    FindClose(pcVar13);
    if ((longlong)pCStack_730 - (longlong)local_738 >> 3 != 0) {
      *(undefined8 *)(puVar33 + -8) = 0x18002be07;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_750);
      iVar47 = 0;
      if ((longlong)pCStack_730 - (longlong)local_738 >> 3 != 0) {
        uVar41 = 0;
        do {
          *(undefined8 *)(puVar33 + -8) = 0x18002be3d;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_798);
          uVar2 = *(undefined8 *)(local_738 + uVar41 * 8);
          *(undefined8 *)(puVar33 + -8) = 0x18002be5d;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_798,
                     "    %s\n",uVar2);
          *(undefined8 *)(puVar33 + -8) = 0x18002be71;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_750,
                     (CSimpleStringT<char,1> *)&local_798);
          *(undefined8 *)(puVar33 + -8) = 0x18002be7f;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_798);
          iVar47 = iVar47 + 1;
          uVar41 = (ulonglong)iVar47;
        } while (uVar41 < (ulonglong)((longlong)pCStack_730 - (longlong)local_738 >> 3));
      }
      *(undefined8 *)(puVar33 + -8) = 0x18002bea8;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_778);
      *(undefined8 *)(puVar33 + -8) = 0x18002beae;
      puVar21 = FUN_180033c00();
      *(undefined8 *)(puVar33 + -8) = 0x18002beb6;
      puVar22 = FUN_180033bb0();
      *(undefined8 *)(puVar33 + -8) = 0x18002bed0;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_778,
                 "%s(%s)",puVar22,puVar21);
      *(undefined8 *)(puVar33 + -8) = 0x18002beda;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7e0);
      *(undefined8 *)(puVar33 + -8) = 0x18002bee6;
      pcVar13 = (char *)GetSorResStringEx(0x831);
      lVar40 = local_750;
      *(undefined8 *)(puVar33 + -8) = 0x18002bf01;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7e0,pcVar13
                 ,lVar40);
      *(undefined8 *)(puVar33 + -8) = 0x18002bf13;
      MMAfxMessageBox((char *)local_7e0,0,-1,0);
      *(undefined8 *)(puVar33 + -8) = 0x18002bf1e;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7e0);
      *(undefined8 *)(puVar33 + -8) = 0x18002bf2c;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_778);
      *(undefined8 *)(puVar33 + -8) = 0x18002bf3a;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_750);
    }
    iVar47 = 0;
    if (((longlong)pCStack_6b8 - (longlong)local_6c0 >> 3 == 0) &&
       ((longlong)pCStack_6e8 - (longlong)local_6f0 >> 3 == 0)) {
      local_828 = (BSTR)((ulonglong)local_828 & 0xffffffff00000000);
      pvVar23 = local_6d8;
    }
    else {
      if (local_820 == '\0') {
        *(undefined8 *)(puVar33 + -8) = 0x18002bf9c;
        iVar10 = FUN_180010ec0(&local_7c0,(longlong *)&local_6d8,&local_7b8,(longlong *)&local_610);
        if (iVar10 == 0) {
          local_828 = (BSTR)CONCAT44(local_828._4_4_,0x80004005);
          pvVar23 = local_6d8;
          goto LAB_18002c36c;
        }
      }
      if (lStack_608 - (longlong)local_610 >> 2 != 0) {
        lVar48 = 0;
        lVar43 = 0;
        pvVar23 = local_610;
        lVar40 = lStack_608;
        do {
          if (*(int *)((longlong)pvVar23 + lVar43) != 0) {
            *(undefined8 *)(puVar33 + -8) = 0x18002bff7;
            pIVar17 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                 &local_768);
            *(undefined8 *)(puVar33 + -8) = 0x18002c004;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_808,
                       pIVar17);
            pcVar13 = local_768;
            local_828._0_4_ = 8;
            *(undefined4 *)(puVar33 + 0x20) = 1;
            iVar10 = *(int *)(pcVar13 + -0x10);
            *(undefined8 *)(puVar33 + -8) = 0x18002c02d;
            ATL::CSimpleStringT<char,1>::Concatenate
                      ((CSimpleStringT<char,1> *)&local_808,pcVar13,iVar10,"\\",
                       *(int *)(puVar33 + 0x20));
            pCVar16 = local_6f0;
            *(undefined8 *)(puVar33 + -8) = 0x18002c03e;
            pIVar17 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                 &local_808);
            *(undefined8 *)(puVar33 + -8) = 0x18002c04e;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_798,
                       pIVar17);
            pcVar5 = local_808;
            local_828._0_4_ = 0xc;
            pcVar13 = *(char **)(pCVar16 + lVar48);
            *(undefined4 *)(puVar33 + 0x20) = *(undefined4 *)(pcVar13 + -0x10);
            iVar10 = *(int *)(pcVar5 + -0x10);
            *(undefined8 *)(puVar33 + -8) = 0x18002c077;
            ATL::CSimpleStringT<char,1>::Concatenate
                      ((CSimpleStringT<char,1> *)&local_798,pcVar5,iVar10,pcVar13,
                       *(int *)(puVar33 + 0x20));
            *(undefined8 *)(puVar33 + -8) = 0x18002c08b;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_748,
                       (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                       &local_798);
            *(undefined8 *)(puVar33 + -8) = 0x18002c09c;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_798);
            *(undefined8 *)(puVar33 + -8) = 0x18002c0aa;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_808);
            *(undefined8 *)(puVar33 + -8) = 0x18002c0b8;
            pIVar17 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                 &local_790);
            *(undefined8 *)(puVar33 + -8) = 0x18002c0c5;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_810,
                       pIVar17);
            pCVar3 = local_790;
            local_828._0_4_ = 2;
            *(undefined4 *)(puVar33 + 0x20) = 1;
            iVar10 = *(int *)(pCVar3 + -0x10);
            *(undefined8 *)(puVar33 + -8) = 0x18002c0ee;
            ATL::CSimpleStringT<char,1>::Concatenate
                      ((CSimpleStringT<char,1> *)&local_810,pCVar3,iVar10,"\\",
                       *(int *)(puVar33 + 0x20));
            pCVar16 = local_6f0;
            *(undefined8 *)(puVar33 + -8) = 0x18002c0ff;
            pIVar17 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                 &local_810);
            *(undefined8 *)(puVar33 + -8) = 0x18002c10c;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7e0,
                       pIVar17);
            pOVar20 = local_810;
            local_828 = (BSTR)CONCAT44(local_828._4_4_,3);
            pcVar13 = *(char **)(pCVar16 + lVar48);
            *(undefined4 *)(puVar33 + 0x20) = *(undefined4 *)(pcVar13 + -0x10);
            iVar10 = *(int *)(pOVar20 + -8);
            *(undefined8 *)(puVar33 + -8) = 0x18002c132;
            ATL::CSimpleStringT<char,1>::Concatenate
                      ((CSimpleStringT<char,1> *)&local_7e0,(char *)pOVar20,iVar10,pcVar13,
                       *(int *)(puVar33 + 0x20));
            *(undefined8 *)(puVar33 + -8) = 0x18002c143;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_758,
                       (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                       &local_7e0);
            *(undefined8 *)(puVar33 + -8) = 0x18002c151;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7e0);
            *(undefined8 *)(puVar33 + -8) = 0x18002c15f;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_810);
            lpExistingFileName = local_748;
            pCVar3 = local_758;
            *(undefined8 *)(puVar33 + -8) = 0x18002c176;
            CopyFileA(lpExistingFileName,pCVar3,0);
            pvVar23 = local_610;
            lVar40 = lStack_608;
          }
          iVar47 = iVar47 + 1;
          lVar43 = lVar43 + 4;
          lVar48 = lVar48 + 8;
        } while ((ulonglong)(longlong)iVar47 < (ulonglong)(lVar40 - (longlong)pvVar23 >> 2));
      }
      iVar47 = 0;
      pvVar23 = local_6d8;
      if ((longlong)puStack_6d0 - (longlong)local_6d8 >> 2 != 0) {
        lVar40 = 0;
        lVar43 = 0;
        puVar27 = puStack_6d0;
        do {
          if (*(int *)((longlong)pvVar23 + lVar43) != 0) {
            local_828 = (BSTR)((ulonglong)local_828 & 0xffffffffffff0000);
            pCVar3 = *(LPCSTR *)(local_6c0 + lVar40);
            if (pCVar3 == (LPCSTR)0x0) {
              local_780 = (BSTR)0x0;
            }
            else {
              *(undefined4 *)(puVar33 + 0x28) = 0;
              *(undefined8 *)(puVar33 + 0x20) = 0;
              *(undefined8 *)(puVar33 + -8) = 0x18002c20b;
              iVar10 = MultiByteToWideChar(0,0,pCVar3,-1,*(LPWSTR *)(puVar33 + 0x20),
                                           *(int *)(puVar33 + 0x28));
              *(undefined8 *)(puVar33 + -8) = 0x18002c218;
              pOVar20 = SysAllocStringLen((OLECHAR *)0x0,iVar10 - 1);
              if (pOVar20 != (BSTR)0x0) {
                *(int *)(puVar33 + 0x28) = iVar10;
                *(BSTR *)(puVar33 + 0x20) = pOVar20;
                *(undefined8 *)(puVar33 + -8) = 0x18002c23c;
                iVar11 = MultiByteToWideChar(0,0,pCVar3,-1,*(LPWSTR *)(puVar33 + 0x20),
                                             *(int *)(puVar33 + 0x28));
                if (iVar11 != iVar10) {
                  *(undefined8 *)(puVar33 + -8) = 0x18002c949;
                  SysFreeString(pOVar20);
                  goto LAB_18002c949;
                }
              }
              local_780 = pOVar20;
              if (pOVar20 == (BSTR)0x0) {
LAB_18002c949:
                    /* WARNING: Subroutine does not return */
                *(undefined8 *)(puVar33 + -8) = 0x18002c953;
                FUN_1800018d0(-0x7ff8fff2);
              }
            }
            pOVar20 = local_780;
            pcVar1 = *(code **)(*(longlong *)pIVar15 + 0xb0);
            *(undefined8 *)(puVar33 + -8) = 0x18002c27c;
            iVar10 = (*pcVar1)(pIVar15,pOVar20,1,&local_828);
            if (((iVar10 < 0) || ((short)local_828 != -1)) && (local_820 == '\0')) {
              *(undefined8 *)(puVar33 + -8) = 0x18002c29f;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7e0
                        );
              *(undefined8 *)(puVar33 + -8) = 0x18002c2a5;
              puVar21 = FUN_180033c00();
              *(undefined8 *)(puVar33 + -8) = 0x18002c2ad;
              puVar22 = FUN_180033bb0();
              *(undefined8 *)(puVar33 + -8) = 0x18002c2c4;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7e0
                         ,"%s(%s)",puVar22,puVar21);
              *(undefined8 *)(puVar33 + -8) = 0x18002c2d1;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_798
                        );
              pCVar16 = local_670 + (longlong)iVar47 * 8;
              *(undefined8 *)(puVar33 + -8) = 0x18002c2eb;
              pcVar13 = (char *)GetSorResStringEx(0x832);
              uVar2 = *(undefined8 *)pCVar16;
              *(undefined8 *)(puVar33 + -8) = 0x18002c302;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_798
                         ,pcVar13,uVar2);
              pcVar13 = local_798;
              *(undefined8 *)(puVar33 + -8) = 0x18002c317;
              MMAfxMessageBox(pcVar13,0,-1,0);
              *(undefined8 *)(puVar33 + -8) = 0x18002c325;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_798
                        );
              *(undefined8 *)(puVar33 + -8) = 0x18002c330;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7e0
                        );
            }
            *(undefined8 *)(puVar33 + -8) = 0x18002c33a;
            SysFreeString(pOVar20);
            puVar27 = puStack_6d0;
            pvVar23 = local_6d8;
          }
          iVar47 = iVar47 + 1;
          lVar43 = lVar43 + 4;
          lVar40 = lVar40 + 8;
        } while ((ulonglong)(longlong)iVar47 <
                 (ulonglong)((longlong)puVar27 - (longlong)pvVar23 >> 2));
      }
      local_828 = (BSTR)((ulonglong)local_828 & 0xffffffff00000000);
    }
LAB_18002c36c:
    if (pvVar23 != (void *)0x0) {
      pvVar45 = pvVar23;
      if ((0xfff < (ulonglong)(((longlong)local_6c8 - (longlong)pvVar23 >> 2) * 4)) &&
         (pvVar45 = *(void **)((longlong)pvVar23 + -8),
         0x1f < (ulonglong)((longlong)pvVar23 + (-8 - (longlong)pvVar45)))) {
                    /* WARNING: Subroutine does not return */
        *(undefined **)(puVar33 + -8) = &UNK_18002c3ae;
        _invalid_parameter_noinfo_noreturn();
      }
      *(undefined8 *)(puVar33 + -8) = 0x18002c3b7;
      FUN_180035134(pvVar45);
      local_6d8 = (void *)0x0;
      puStack_6d0 = (undefined4 *)0x0;
      local_6c8 = (undefined4 *)0x0;
    }
    pCVar25 = pCStack_730;
    pCVar16 = local_738;
    if (local_738 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
      for (; pCVar16 != pCVar25; pCVar16 = pCVar16 + 8) {
        *(undefined8 *)(puVar33 + -8) = 0x18002c3ee;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar16);
      }
      pCVar16 = local_738;
      if ((0xfff < (ulonglong)(((longlong)local_728 - (longlong)local_738 >> 3) * 8)) &&
         (pCVar16 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                     (local_738 + -8),
         (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x1f <
         local_738 + (-8 - (longlong)pCVar16))) {
                    /* WARNING: Subroutine does not return */
        *(undefined **)(puVar33 + -8) = &UNK_18002c43b;
        _invalid_parameter_noinfo_noreturn();
      }
      *(undefined8 *)(puVar33 + -8) = 0x18002c444;
      FUN_180035134(pCVar16);
      local_738 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
      pCStack_730 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
      local_728 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    }
    pCVar25 = pCStack_6b8;
    pCVar16 = local_6c0;
    if (local_6c0 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
      for (; pCVar16 != pCVar25; pCVar16 = pCVar16 + 8) {
        *(undefined8 *)(puVar33 + -8) = 0x18002c47b;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar16);
      }
      pCVar16 = local_6c0;
      if ((0xfff < (ulonglong)(((longlong)local_6b0 - (longlong)local_6c0 >> 3) * 8)) &&
         (pCVar16 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                     (local_6c0 + -8),
         (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x1f <
         local_6c0 + (-8 - (longlong)pCVar16))) {
                    /* WARNING: Subroutine does not return */
        *(undefined **)(puVar33 + -8) = &UNK_18002c4c8;
        _invalid_parameter_noinfo_noreturn();
      }
      *(undefined8 *)(puVar33 + -8) = 0x18002c4d1;
      FUN_180035134(pCVar16);
      local_6c0 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
      pCStack_6b8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
      local_6b0 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    }
    pCVar25 = pCStack_668;
    pCVar16 = local_670;
    if (local_670 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
      for (; pCVar16 != pCVar25; pCVar16 = pCVar16 + 8) {
        *(undefined8 *)(puVar33 + -8) = 0x18002c509;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar16);
      }
      pCVar16 = local_670;
      if ((0xfff < (ulonglong)(((longlong)local_660 - (longlong)local_670 >> 3) * 8)) &&
         (pCVar16 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                     (local_670 + -8),
         (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x1f <
         local_670 + (-8 - (longlong)pCVar16))) {
                    /* WARNING: Subroutine does not return */
        *(undefined **)(puVar33 + -8) = &UNK_18002c556;
        _invalid_parameter_noinfo_noreturn();
      }
      *(undefined8 *)(puVar33 + -8) = 0x18002c55f;
      FUN_180035134(pCVar16);
      local_670 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
      pCStack_668 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
      local_660 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    }
    *(undefined8 *)(puVar33 + -8) = 0x18002c57b;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7c0);
  }
  pCVar25 = pCStack_700;
  pCVar16 = local_708;
  if (local_708 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
    for (; pCVar16 != pCVar25; pCVar16 = pCVar16 + 8) {
      *(undefined8 *)(puVar33 + -8) = 0x18002c59d;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar16);
    }
    pCVar16 = local_708;
    if ((0xfff < (ulonglong)(((longlong)local_6f8 - (longlong)local_708 >> 3) * 8)) &&
       (pCVar16 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                   (local_708 + -8),
       (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x1f <
       local_708 + (-8 - (longlong)pCVar16))) {
                    /* WARNING: Subroutine does not return */
      *(undefined **)(puVar33 + -8) = &UNK_18002c5ea;
      _invalid_parameter_noinfo_noreturn();
    }
    *(undefined8 *)(puVar33 + -8) = 0x18002c5f3;
    FUN_180035134(pCVar16);
    local_708 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    pCStack_700 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    local_6f8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  }
  *(undefined8 *)(puVar33 + -8) = 0x18002c612;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_790);
  *(undefined8 *)(puVar33 + -8) = 0x18002c620;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_758);
  *(undefined8 *)(puVar33 + -8) = 0x18002c62e;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_748);
  pCVar25 = pCStack_6e8;
  pCVar16 = local_6f0;
  if (local_6f0 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
    for (; pCVar16 != pCVar25; pCVar16 = pCVar16 + 8) {
      *(undefined8 *)(puVar33 + -8) = 0x18002c650;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar16);
    }
    pCVar16 = local_6f0;
    if ((0xfff < (ulonglong)(((longlong)local_6e0 - (longlong)local_6f0 >> 3) * 8)) &&
       (pCVar16 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                   (local_6f0 + -8),
       (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x1f <
       local_6f0 + (-8 - (longlong)pCVar16))) {
                    /* WARNING: Subroutine does not return */
      *(undefined **)(puVar33 + -8) = &UNK_18002c69d;
      _invalid_parameter_noinfo_noreturn();
    }
    *(undefined8 *)(puVar33 + -8) = 0x18002c6a6;
    FUN_180035134(pCVar16);
    local_6f0 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    pCStack_6e8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    local_6e0 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  }
  if (local_610 != (void *)0x0) {
    pvVar23 = local_610;
    if ((0xfff < (ulonglong)((local_600 - (longlong)local_610 >> 2) * 4)) &&
       (pvVar23 = *(void **)((longlong)local_610 + -8),
       0x1f < (ulonglong)((longlong)local_610 + (-8 - (longlong)pvVar23)))) {
                    /* WARNING: Subroutine does not return */
      *(undefined **)(puVar33 + -8) = &UNK_18002c701;
      _invalid_parameter_noinfo_noreturn();
    }
    *(undefined8 *)(puVar33 + -8) = 0x18002c707;
    FUN_180035134(pvVar23);
    local_610 = (void *)0x0;
    lStack_608 = 0;
    local_600 = 0;
  }
  *(undefined8 *)(puVar33 + -8) = 0x18002c723;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7b8);
  pCVar25 = pCStack_680;
  pCVar16 = local_688;
  if (local_688 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
    for (; pCVar16 != pCVar25; pCVar16 = pCVar16 + 8) {
      *(undefined8 *)(puVar33 + -8) = 0x18002c749;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar16);
    }
    pCVar16 = local_688;
    if ((0xfff < (ulonglong)((local_678 - (longlong)local_688 >> 3) * 8)) &&
       (pCVar16 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                   (local_688 + -8),
       (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x1f <
       local_688 + (-8 - (longlong)pCVar16))) {
                    /* WARNING: Subroutine does not return */
      *(undefined **)(puVar33 + -8) = &UNK_18002c796;
      _invalid_parameter_noinfo_noreturn();
    }
    *(undefined8 *)(puVar33 + -8) = 0x18002c79f;
    FUN_180035134(pCVar16);
    local_688 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    pCStack_680 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    local_678 = 0;
  }
  pCVar25 = pCStack_650;
  pCVar16 = local_658;
  if (local_658 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
    for (; pCVar16 != pCVar25; pCVar16 = pCVar16 + 8) {
      *(undefined8 *)(puVar33 + -8) = 0x18002c7d9;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar16);
    }
    pCVar16 = local_658;
    if ((0xfff < (ulonglong)((local_648 - (longlong)local_658 >> 3) * 8)) &&
       (pCVar16 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                   (local_658 + -8),
       (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x1f <
       local_658 + (-8 - (longlong)pCVar16))) {
                    /* WARNING: Subroutine does not return */
      *(undefined **)(puVar33 + -8) = &UNK_18002c826;
      _invalid_parameter_noinfo_noreturn();
    }
    *(undefined8 *)(puVar33 + -8) = 0x18002c82f;
    FUN_180035134(pCVar16);
    local_658 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    pCStack_650 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    local_648 = 0;
  }
  pCVar25 = pCStack_718;
  pCVar16 = local_720;
  if (local_720 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
    for (; pCVar16 != pCVar25; pCVar16 = pCVar16 + 8) {
      *(undefined8 *)(puVar33 + -8) = 0x18002c869;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar16);
    }
    pCVar16 = local_720;
    if ((0xfff < (ulonglong)(((longlong)local_710 - (longlong)local_720 >> 3) * 8)) &&
       (pCVar16 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                   (local_720 + -8),
       (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x1f <
       local_720 + (-8 - (longlong)pCVar16))) {
                    /* WARNING: Subroutine does not return */
      *(undefined **)(puVar33 + -8) = &UNK_18002c8b6;
      _invalid_parameter_noinfo_noreturn();
    }
    *(undefined8 *)(puVar33 + -8) = 0x18002c8bf;
    FUN_180035134(pCVar16);
    local_720 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    pCStack_718 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    local_710 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  }
LAB_18002c8d1:
  *(undefined8 *)(puVar33 + -8) = 0x18002c8de;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_768);
  *(undefined8 *)(puVar33 + -8) = 0x18002c8ec;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_638);
  *(undefined8 *)(puVar33 + -8) = 0x18002c8fa;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_630);
  *(undefined8 *)(puVar33 + -8) = 0x18002c908;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_628);
  *(undefined8 *)(puVar33 + -8) = 0x18002c91a;
  return (ulonglong)local_828 & 0xffffffff;
}

