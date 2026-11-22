/* ---- FUNC 00055380 FUN_180055380 (923 bytes) ---- */

void FUN_180055380(longlong param_1)

{
  int iVar1;
  undefined4 uVar2;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  longlong *plVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_res8;
  longlong *local_res10;
  _union_2707 local_68;
  undefined2 local_50;
  undefined6 uStack_4e;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x90),
             "AspenPlus Plot");
  CStringArray::SetSize((CStringArray *)(param_1 + 0x98),0,-1);
  CStringArray::SetAtGrow((CStringArray *)(param_1 + 0x98),*(__int64 *)(param_1 + 0xa8),"");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0xc0),"");
  this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  *(undefined4 *)(param_1 + 200) = 0;
  local_res8 = operator_new(0x40);
  if (local_res8 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
    this = FUN_180050130(local_res8);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(this,"X");
  CPtrArray::SetAtGrow((CPtrArray *)(param_1 + 0xd0),*(__int64 *)(param_1 + 0xe0),this);
  *(undefined8 *)(param_1 + 0x148) = 0;
  *(undefined8 *)(param_1 + 0x150) = 0;
  *(undefined8 *)(param_1 + 0x158) = 0;
  *(undefined4 *)(param_1 + 0x160) = 0;
  *(undefined4 *)(param_1 + 0x164) = 0x40000;
  *(undefined8 *)(param_1 + 0x16c) = 0;
  *(undefined2 *)(param_1 + 0x168) = 0;
  *(undefined4 *)(param_1 + 0x174) = 0;
  *(undefined4 *)(param_1 + 0x178) = 1;
  plVar3 = (longlong *)HappGetTree();
  iVar1 = (**(code **)(*plVar3 + 0x110))(plVar3,L"Settings",&local_res10);
  if (iVar1 < 0) goto LAB_180055702;
  local_50 = 0;
  local_68.n2.vt = 0;
  iVar1 = (**(code **)(*local_res10 + 0x110))(local_res10,L"gridstyle",&local_res8);
  if (-1 < iVar1) {
    local_38 = CONCAT62(uStack_4e,local_50);
    uStack_30 = uStack_48;
    local_28 = local_40;
    iVar1 = (**(code **)(*(longlong *)local_res8 + 0x68))(local_res8,&local_38,&local_68);
    if (-1 < iVar1) {
      if ((local_68.n2.vt == 3) || (local_68.n2.vt == 2)) {
        *(undefined2 *)(param_1 + 0x164) = local_68._8_2_;
      }
      VariantClear((VARIANTARG *)&local_68.n2);
    }
    (**(code **)(*(longlong *)local_res8 + 0x10))();
  }
  iVar1 = (**(code **)(*local_res10 + 0x110))(local_res10,L"linestyle",&local_res8);
  if (-1 < iVar1) {
    local_38 = CONCAT62(uStack_4e,local_50);
    uStack_30 = uStack_48;
    local_28 = local_40;
    iVar1 = (**(code **)(*(longlong *)local_res8 + 0x68))(local_res8,&local_38,&local_68);
    if (-1 < iVar1) {
      if ((local_68.n2.vt == 3) || (local_68.n2.vt == 2)) {
        *(undefined2 *)(param_1 + 0x168) = local_68._8_2_;
      }
      VariantClear((VARIANTARG *)&local_68.n2);
    }
    (**(code **)(*(longlong *)local_res8 + 0x10))();
  }
  iVar1 = (**(code **)(*local_res10 + 0x110))(local_res10,L"plotmarkersize",&local_res8);
  if (-1 < iVar1) {
    local_38 = CONCAT62(uStack_4e,local_50);
    uStack_30 = uStack_48;
    local_28 = local_40;
    iVar1 = (**(code **)(*(longlong *)local_res8 + 0x68))(local_res8,&local_38,&local_68);
    if (-1 < iVar1) {
      if ((local_68.n2.vt == 3) || (local_68.n2.vt == 2)) {
        *(undefined2 *)(param_1 + 0x166) = local_68._8_2_;
      }
      VariantClear((VARIANTARG *)&local_68.n2);
    }
    (**(code **)(*(longlong *)local_res8 + 0x10))();
  }
  iVar1 = (**(code **)(*local_res10 + 0x110))(local_res10,L"showlegend",&local_res8);
  if (-1 < iVar1) {
    local_38 = CONCAT62(uStack_4e,local_50);
    uStack_30 = uStack_48;
    local_28 = local_40;
    iVar1 = (**(code **)(*(longlong *)local_res8 + 0x68))(local_res8,&local_38,&local_68);
    if (-1 < iVar1) {
      uVar2 = local_68._8_4_;
      if (local_68.n2.vt == 3) {
LAB_180055661:
        *(undefined4 *)(param_1 + 0x154) = uVar2;
      }
      else if ((local_68.n2.vt == 2) || (local_68.n2.vt == 0xb)) {
        uVar2 = (int)(short)local_68._8_2_;
        goto LAB_180055661;
      }
      VariantClear((VARIANTARG *)&local_68.n2);
    }
    (**(code **)(*(longlong *)local_res8 + 0x10))();
  }
  iVar1 = (**(code **)(*local_res10 + 0x110))(local_res10,L"plottimestamp",&local_res8);
  if (-1 < iVar1) {
    local_38 = CONCAT62(uStack_4e,local_50);
    uStack_30 = uStack_48;
    local_28 = local_40;
    iVar1 = (**(code **)(*(longlong *)local_res8 + 0x68))(local_res8,&local_38,&local_68);
    if (-1 < iVar1) {
      if (local_68.n2.vt == 3) {
LAB_1800556de:
        *(undefined4 *)(param_1 + 0x150) = local_68._8_4_;
      }
      else if ((local_68.n2.vt == 2) || (local_68.n2.vt == 0xb)) {
        local_68._8_4_ = SEXT24((short)local_68._8_2_);
        goto LAB_1800556de;
      }
      VariantClear((VARIANTARG *)&local_68.n2);
    }
    (**(code **)(*(longlong *)local_res8 + 0x10))();
  }
  (**(code **)(*local_res10 + 0x10))();
LAB_180055702:
  (**(code **)(*plVar3 + 0x10))(plVar3);
  return;
}

/* ---- FUNC 00055720 FUN_180055720 (772 bytes) ---- */

int FUN_180055720(longlong *param_1,longlong *param_2,wchar_t *param_3)

{
  int iVar1;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar2;
  BSTR bstrString;
  longlong lVar3;
  int local_res10 [2];
  longlong *local_res20;
  LPCSTR local_88;
  longlong local_80;
  _union_2707 local_78;
  _union_2707 local_60;
  int local_48;
  ULONG UStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  
  local_res20 = (longlong *)0x0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_88,param_3);
  iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_88,'!',
                     0);
  if (iVar1 != -1) {
    pCVar2 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                       ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_88,
                        (int)&local_80);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_88,pCVar2);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_80);
  }
  bstrString = FUN_18005d480(local_88);
  iVar1 = (**(code **)(*param_2 + 0x110))(param_2,bstrString,&local_res20);
  SysFreeString(bstrString);
  if (iVar1 < 0) goto LAB_1800559f7;
  if (local_res20 == (longlong *)0x0) {
    iVar1 = (**(code **)(*(longlong *)param_1[0x12] + 0xb0))((longlong *)param_1[0x12],0);
    if (-1 < iVar1) {
      pCVar2 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
               CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_80
                          ,param_3);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x21),
                 pCVar2);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_80);
      iVar1 = 0;
    }
    goto LAB_1800559f7;
  }
  local_res10[0] = 0;
  iVar1 = (**(code **)(*local_res20 + 0x58))(local_res20,local_res10);
  if (iVar1 < 0) {
    (**(code **)(*local_res20 + 0x10))();
    goto LAB_1800559f7;
  }
  if (local_res10[0] == 0) {
    AfxVariantInit((tagVARIANT *)&local_78.n2);
    VariantInit((VARIANTARG *)&local_60.n2);
    local_60._0_4_ = (uint)local_60.n2.wReserved1 << 0x10;
    local_38 = local_60._16_8_;
    local_48 = local_60._0_4_;
    UStack_44 = local_60.decVal.Hi32;
    uStack_40 = local_60._8_4_;
    uStack_3c = local_60._12_4_;
    iVar1 = (**(code **)(*local_res20 + 0x68))(local_res20,&local_48);
    (**(code **)(*local_res20 + 0x10))();
    if (-1 < iVar1) {
      if (1 < (ushort)(local_78.n2.vt - 2)) {
        iVar1 = (**(code **)(*param_1 + 0x138))(param_1,0x7d1);
        VariantClear((VARIANTARG *)&local_78.n2);
        goto LAB_1800559f7;
      }
      COleVariant::ChangeType((COleVariant *)&local_78.n2,3,(tagVARIANT *)0x0);
      iVar1 = (**(code **)(*(longlong *)param_1[0x12] + 0xb0))
                        ((longlong *)param_1[0x12],local_78._8_4_);
      if (-1 < iVar1) {
        VariantClear((VARIANTARG *)&local_78.n2);
        goto LAB_180055976;
      }
    }
    VariantClear((VARIANTARG *)&local_78.n2);
  }
  else {
    if (local_res10[0] == 1) {
      local_80 = 0;
      iVar1 = HAGetLength(local_res20[9],0,&local_80);
      lVar3 = *local_res20;
      if (iVar1 != -1) {
        (**(code **)(lVar3 + 0x10))();
        iVar1 = (**(code **)(*(longlong *)param_1[0x12] + 0xb0))((longlong *)param_1[0x12],iVar1);
        if (iVar1 < 0) goto LAB_1800559f7;
LAB_180055976:
        if (*(longlong *)(param_1[0x12] + 0xe0) < 1) {
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        iVar1 = FUN_180056190(param_1,**(longlong **)(param_1[0x12] + 0xd8),param_2,param_3);
        if (-1 < iVar1) {
          pCVar2 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                   CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                             ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                              &local_80,param_3);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                     (param_1 + 0x21),pCVar2);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_80);
          iVar1 = 0;
        }
        goto LAB_1800559f7;
      }
      if (local_80 != 0) {
        (**(code **)(lVar3 + 0x10))();
        iVar1 = (**(code **)(*param_1 + 0x130))(param_1,local_80);
        goto LAB_1800559f7;
      }
    }
    else {
      lVar3 = *local_res20;
    }
    (**(code **)(lVar3 + 0x10))();
    iVar1 = (**(code **)(*param_1 + 0x138))(param_1,0x7d1);
  }
LAB_1800559f7:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_88);
  return iVar1;
}

/* ---- FUNC 00055A30 FUN_180055a30 (845 bytes) ---- */

int FUN_180055a30(longlong *param_1,longlong *param_2,wchar_t *param_3)

{
  longlong *plVar1;
  int iVar2;
  int iVar3;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar4;
  BSTR bstrString;
  longlong lVar5;
  int local_res10 [2];
  int local_res20 [2];
  longlong *local_98;
  LPCSTR local_90;
  longlong local_88;
  _union_2707 local_80;
  _union_2707 local_68;
  int local_48;
  ULONG UStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  
  local_98 = (longlong *)0x0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_90,param_3);
  iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_90,'!',
                     0);
  if (iVar2 != -1) {
    pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                       ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_90,
                        (int)local_res20);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_90,pCVar4);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res20);
  }
  bstrString = FUN_18005d480(local_90);
  iVar2 = (**(code **)(*param_2 + 0x110))(param_2,bstrString,&local_98);
  SysFreeString(bstrString);
  if (iVar2 < 0) goto LAB_180055d50;
  if (local_98 == (longlong *)0x0) {
    iVar2 = (**(code **)(*(longlong *)param_1[0x12] + 0xb0))((longlong *)param_1[0x12],0);
    if (-1 < iVar2) {
      pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
               CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          local_res20,param_3);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x21),
                 pCVar4);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res20);
      iVar2 = 0;
    }
    goto LAB_180055d50;
  }
  local_res10[0] = 0;
  iVar2 = (**(code **)(*local_98 + 0x58))(local_98,local_res10);
  if (iVar2 < 0) {
    (**(code **)(*local_98 + 0x10))();
    goto LAB_180055d50;
  }
  if (local_res10[0] == 0) {
    AfxVariantInit((tagVARIANT *)&local_80.n2);
    VariantInit((VARIANTARG *)&local_68.n2);
    local_68._0_4_ = (uint)local_68.n2.wReserved1 << 0x10;
    local_38 = local_68._16_8_;
    local_48 = local_68._0_4_;
    UStack_44 = local_68.decVal.Hi32;
    uStack_40 = local_68._8_4_;
    uStack_3c = local_68._12_4_;
    iVar2 = (**(code **)(*local_98 + 0x68))(local_98,&local_48);
    (**(code **)(*local_98 + 0x10))();
    if (-1 < iVar2) {
      if (1 < (ushort)(local_80.n2.vt - 2)) {
        iVar2 = (**(code **)(*param_1 + 0x138))(param_1,0x7d1);
        VariantClear((VARIANTARG *)&local_80.n2);
        goto LAB_180055d50;
      }
      COleVariant::ChangeType((COleVariant *)&local_80.n2,3,(tagVARIANT *)0x0);
      iVar2 = (**(code **)(*(longlong *)param_1[0x12] + 0xb0))
                        ((longlong *)param_1[0x12],local_80._8_4_);
      if (-1 < iVar2) {
        VariantClear((VARIANTARG *)&local_80.n2);
        goto LAB_180055cab;
      }
    }
    VariantClear((VARIANTARG *)&local_80.n2);
  }
  else {
    if (local_res10[0] == 1) {
      local_88 = 0;
      iVar3 = HAGetLength(local_98[9],0,&local_88);
      lVar5 = *local_98;
      if (iVar3 != -1) {
        (**(code **)(lVar5 + 0x10))();
        (**(code **)(*(longlong *)param_1[0x12] + 0xa8))((longlong *)param_1[0x12],local_res20);
        if (local_res20[0] < iVar3) {
          iVar2 = (**(code **)(*(longlong *)param_1[0x12] + 0xb0))((longlong *)param_1[0x12],iVar3);
        }
        if (iVar2 < 0) goto LAB_180055d50;
LAB_180055cab:
        plVar1 = (longlong *)param_1[0x12];
        lVar5 = plVar1[0x1c];
        (**(code **)(*plVar1 + 0xd0))(plVar1,(int)lVar5 + 1);
        if ((lVar5 < 0) || (*(longlong *)(param_1[0x12] + 0xe0) <= lVar5)) {
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        iVar2 = FUN_180056190(param_1,*(longlong *)(*(longlong *)(param_1[0x12] + 0xd8) + lVar5 * 8)
                              ,param_2,param_3);
        if (-1 < iVar2) {
          pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                   CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                             ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                              local_res20,param_3);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                     (param_1 + 0x21),pCVar4);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res20);
          iVar2 = 0;
        }
        goto LAB_180055d50;
      }
      if (local_88 != 0) {
        (**(code **)(lVar5 + 0x10))();
        iVar2 = (**(code **)(*param_1 + 0x130))(param_1,local_88);
        goto LAB_180055d50;
      }
    }
    else {
      lVar5 = *local_98;
    }
    (**(code **)(lVar5 + 0x10))();
    iVar2 = (**(code **)(*param_1 + 0x138))(param_1,0x7d1);
  }
LAB_180055d50:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_90);
  return iVar2;
}

/* ---- FUNC 00055D80 FUN_180055d80 (548 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180055d80(longlong param_1,int param_2)

{
  void *pvVar1;
  longlong lVar2;
  int iVar3;
  undefined1 auStack_428 [32];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_180077818 ^ (ulonglong)auStack_428;
  lVar2 = (longlong)param_2;
  if (param_2 < 0) {
    FUN_180002a20(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0x100);
    LogMessage(local_408,2,1);
  }
  iVar3 = *(int *)(param_1 + 0x1c);
  if (iVar3 < 0) {
    FUN_180002a20(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0x101);
    LogMessage(local_408,2,1);
    iVar3 = *(int *)(param_1 + 0x1c);
  }
  if ((iVar3 != 0) && ((*(longlong *)(param_1 + 0x28) == 0 || (*(longlong *)(param_1 + 0x20) == 0)))
     ) {
    FUN_180002a20(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\hplotval.cpp",0x102);
    LogMessage(local_408,2,1);
  }
  if (*(int *)(param_1 + 0x1c) < param_2) {
    if (*(void **)(param_1 + 0x28) == (void *)0x0) {
      pvVar1 = malloc(lVar2 * 0x18);
    }
    else {
      pvVar1 = realloc(*(void **)(param_1 + 0x28),lVar2 * 0x18);
    }
    *(void **)(param_1 + 0x28) = pvVar1;
    if (*(void **)(param_1 + 0x20) == (void *)0x0) {
      pvVar1 = malloc(lVar2 * 4);
    }
    else {
      pvVar1 = realloc(*(void **)(param_1 + 0x20),lVar2 * 4);
    }
    *(void **)(param_1 + 0x20) = pvVar1;
    memset((void *)(*(longlong *)(param_1 + 0x28) + (longlong)*(int *)(param_1 + 0x1c) * 0x18),0,
           (longlong)(param_2 - *(int *)(param_1 + 0x1c)) * 0x18);
    memset((void *)(*(longlong *)(param_1 + 0x20) + (longlong)*(int *)(param_1 + 0x1c) * 4),0,
           (longlong)(param_2 - *(int *)(param_1 + 0x1c)) << 2);
  }
  else {
    iVar3 = param_2;
    if (param_2 < *(int *)(param_1 + 0x1c)) {
      do {
        VariantClear((VARIANTARG *)(*(longlong *)(param_1 + 0x28) + (longlong)iVar3 * 0x18));
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(param_1 + 0x1c));
      if (param_2 == 0) {
        free(*(void **)(param_1 + 0x28));
        *(undefined8 *)(param_1 + 0x28) = 0;
        free(*(void **)(param_1 + 0x20));
        *(undefined8 *)(param_1 + 0x20) = 0;
      }
      else {
        pvVar1 = realloc(*(void **)(param_1 + 0x28),lVar2 * 0x18);
        *(void **)(param_1 + 0x28) = pvVar1;
        pvVar1 = realloc(*(void **)(param_1 + 0x20),lVar2 * 4);
        *(void **)(param_1 + 0x20) = pvVar1;
      }
    }
  }
  *(int *)(param_1 + 0x1c) = param_2;
  return;
}

/* ---- FUNC 00055FB0 FUN_180055fb0 (449 bytes) ---- */

void FUN_180055fb0(longlong param_1,longlong param_2,longlong param_3)

{
  __uint64 _Size;
  longlong lVar1;
  void *pvVar2;
  longlong lVar3;
  void *_Dst;
  int *piVar4;
  ulonglong _Size_00;
  longlong lVar5;
  
  if (param_2 < 0) goto LAB_18005616c;
  if (-1 < param_3) {
    *(longlong *)(param_1 + 0x20) = param_3;
  }
  pvVar2 = *(void **)(param_1 + 8);
  if (param_2 == 0) {
    if (pvVar2 != (void *)0x0) {
      operator_delete__(pvVar2);
      *(undefined8 *)(param_1 + 8) = 0;
    }
    *(undefined8 *)(param_1 + 0x18) = 0;
    *(undefined8 *)(param_1 + 0x10) = 0;
    return;
  }
  if (pvVar2 == (void *)0x0) {
    lVar5 = *(longlong *)(param_1 + 0x20);
    if (*(longlong *)(param_1 + 0x20) < param_2) {
      lVar5 = param_2;
    }
    pvVar2 = operator_new__(lVar5 * 4);
    *(void **)(param_1 + 8) = pvVar2;
    memset(pvVar2,0,lVar5 * 4);
  }
  else {
    lVar1 = *(longlong *)(param_1 + 0x18);
    if (param_2 <= lVar1) {
      lVar1 = *(longlong *)(param_1 + 0x10);
      if (lVar1 < param_2) {
        memset((void *)((longlong)pvVar2 + lVar1 * 4),0,(param_2 - lVar1) * 4);
      }
      goto LAB_180056036;
    }
    lVar3 = *(longlong *)(param_1 + 0x20);
    if (lVar3 == 0) {
      lVar3 = (longlong)
              (*(longlong *)(param_1 + 0x10) +
              (ulonglong)((uint)(*(longlong *)(param_1 + 0x10) >> 0x3f) & 7)) >> 3;
      if (lVar3 < 4) {
        lVar3 = 4;
      }
      else if (0x400 < lVar3) {
        lVar3 = 0x400;
      }
    }
    lVar3 = lVar1 + lVar3;
    lVar5 = param_2;
    if ((param_2 < lVar3) && (lVar5 = lVar3, lVar3 < lVar1)) goto LAB_18005616c;
    _Size = lVar5 * 4;
    _Dst = operator_new__(_Size);
    pvVar2 = *(void **)(param_1 + 8);
    _Size_00 = *(longlong *)(param_1 + 0x10) << 2;
    if (_Size_00 != 0) {
      if (_Dst != (void *)0x0) {
        if ((pvVar2 != (void *)0x0) && (_Size_00 <= _Size)) {
          memcpy(_Dst,pvVar2,_Size_00);
          goto LAB_180056104;
        }
        memset(_Dst,0,_Size);
        if (pvVar2 != (void *)0x0) {
          if (_Size < _Size_00) {
            piVar4 = _errno();
            *piVar4 = 0x22;
            _invalid_parameter_noinfo();
          }
          goto LAB_18005616c;
        }
      }
      piVar4 = _errno();
      *piVar4 = 0x16;
      _invalid_parameter_noinfo();
LAB_18005616c:
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
LAB_180056104:
    memset((void *)((longlong)_Dst + *(longlong *)(param_1 + 0x10) * 4),0,
           (param_2 - *(longlong *)(param_1 + 0x10)) * 4);
    operator_delete__(*(void **)(param_1 + 8));
    *(void **)(param_1 + 8) = _Dst;
  }
  *(longlong *)(param_1 + 0x18) = lVar5;
LAB_180056036:
  *(longlong *)(param_1 + 0x10) = param_2;
  return;
}

/* ---- FUNC 00056180 FUN_180056180 (4 bytes) ---- */

void FUN_180056180(longlong param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x34) = param_2;
  return;
}

/* ---- FUNC 00056190 FUN_180056190 (1265 bytes) ---- */

/* WARNING: Type propagation algorithm not settling */

int FUN_180056190(longlong *param_1,longlong param_2,longlong *param_3,wchar_t *param_4)

{
  ulonglong uVar1;
  int iVar2;
  int iVar3;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar4;
  BSTR bstrString;
  int iVar5;
  int iVar6;
  int local_res18 [2];
  longlong *local_198;
  longlong *local_190;
  LPCSTR local_188;
  int local_180 [2];
  undefined1 local_178 [24];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_160 [8];
  int local_158 [4];
  undefined8 local_148;
  _union_1719 _Stack_140;
  undefined8 local_138;
  _union_2707 local_128;
  _union_2707 local_108;
  undefined8 local_e8;
  _union_1719 _Stack_e0;
  undefined8 local_d8;
  undefined2 local_c8;
  undefined6 uStack_c6;
  undefined2 uStack_c0;
  undefined2 uStack_be;
  undefined4 uStack_bc;
  undefined2 uStack_b8;
  undefined6 uStack_b6;
  undefined2 uStack_b0;
  undefined6 uStack_ae;
  undefined2 uStack_a8;
  undefined6 local_a6;
  undefined2 uStack_a0;
  undefined6 uStack_9e;
  undefined2 uStack_98;
  undefined6 local_96;
  undefined2 uStack_90;
  undefined6 uStack_8e;
  undefined2 uStack_88;
  undefined6 uStack_86;
  undefined2 uStack_80;
  undefined6 uStack_7e;
  undefined2 uStack_78;
  undefined6 local_76;
  undefined2 uStack_70;
  undefined6 uStack_6e;
  undefined2 uStack_68;
  undefined6 local_66;
  undefined2 uStack_60;
  undefined6 uStack_5e;
  undefined2 uStack_58;
  undefined4 uStack_56;
  undefined2 uStack_52;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  iVar6 = 0;
  local_198 = (longlong *)0x0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_188,param_4);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_160);
  iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_188,'!'
                     ,0);
  if (iVar2 != -1) {
    pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Right
                       ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_188,
                        (int)&local_190);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(local_160,pCVar4);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_190);
    pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                       ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_188,
                        (int)&local_190);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_188,pCVar4);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_190);
  }
  bstrString = FUN_18005d480(local_188);
  iVar2 = (**(code **)(*param_3 + 0x110))(param_3,bstrString,&local_198);
  SysFreeString(bstrString);
  if ((iVar2 < 0) || (iVar2 = 0, local_198 == (longlong *)0x0)) goto LAB_180056647;
  local_res18[0] = 0;
  (**(code **)(*(longlong *)param_1[0x12] + 0xa8))((longlong *)param_1[0x12],local_res18);
  local_180[0] = 0;
  iVar2 = (**(code **)(*local_198 + 0x58))(local_198,local_180);
  if (iVar2 < 0) goto LAB_18005643b;
  if (local_180[0] == 0) {
    AfxVariantInit((tagVARIANT *)&((_union_2707 *)local_178)->n2);
    VariantInit((VARIANTARG *)&local_108.n2);
    uVar1 = (ulonglong)local_108._0_8_ >> 0x20;
    local_108._0_8_ = local_108._0_8_ & 0xffffffffffff0000;
    local_148 = CONCAT44((int)uVar1,(int)local_108._0_8_);
    _Stack_140 = local_108.decVal.u2;
    local_138 = local_108._16_8_;
    iVar2 = (**(code **)(*local_198 + 0x68))(local_198,&local_148);
    if (iVar2 < 0) {
      (**(code **)(*local_198 + 0x10))();
    }
    else {
      if ((ushort)(local_178._0_2_ - 2) < 2) {
        COleVariant::ChangeType((COleVariant *)&((_union_2707 *)local_178)->n2,3,(tagVARIANT *)0x0);
        local_148 = CONCAT62(local_148._2_6_,3);
        if (0 < (int)local_178._8_4_) {
          do {
            if (local_res18[0] <= iVar6) break;
            iVar5 = iVar6 + 1;
            _Stack_140.s2.Lo32 = iVar5;
            local_128._0_8_ = local_148;
            local_128.decVal.u2.s2 = _Stack_140;
            local_128._16_8_ = local_138;
            FUN_180054dc0(param_2,iVar6,0,(uint *)&local_128);
            iVar6 = iVar5;
          } while (iVar5 < (int)local_178._8_4_);
        }
        VariantClear((VARIANTARG *)&((_union_2707 *)local_178)->n2);
        (**(code **)(*local_198 + 0x10))();
        goto LAB_180056647;
      }
      (**(code **)(*local_198 + 0x10))();
      iVar2 = (**(code **)(*param_1 + 0x138))(param_1,0x7d1);
    }
    VariantClear((VARIANTARG *)&((_union_2707 *)local_178)->n2);
    goto LAB_180056647;
  }
  if (local_180[0] == 1) {
    local_190 = (longlong *)0x0;
    iVar2 = (**(code **)(*local_198 + 200))(local_198,&local_190);
    if (-1 < iVar2) {
      iVar2 = (**(code **)(*local_190 + 0x48))(local_190,local_158);
      if (-1 < iVar2) {
        uStack_c6 = 0;
        uStack_c0 = 0;
        uStack_be = 0;
        uStack_bc = 0;
        uStack_b8 = 0;
        uStack_b6 = 0;
        uStack_b0 = 0;
        uStack_ae = 0;
        uStack_a8 = 0;
        local_a6 = 0;
        uStack_a0 = 0;
        uStack_9e = 0;
        uStack_98 = 0;
        local_96 = 0;
        uStack_90 = 0;
        uStack_8e = 0;
        uStack_88 = 0;
        uStack_86 = 0;
        uStack_80 = 0;
        uStack_7e = 0;
        uStack_78 = 0;
        local_76 = 0;
        uStack_70 = 0;
        uStack_6e = 0;
        uStack_68 = 0;
        local_66 = 0;
        uStack_60 = 0;
        uStack_5e = 0;
        uStack_58 = 0;
        uStack_56 = 0;
        uStack_52 = 0;
        local_c8 = 3;
        local_178._0_2_ = 9;
        local_178._8_8_ = (_union_1719)0x0;
        iVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                          (local_160,"LABEL");
        iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                          (local_160,"LABEL2");
        if (0 < local_res18[0]) {
          do {
            if (local_158[0] <= iVar6) break;
            if (iVar3 == 0) {
              VariantInit((VARIANTARG *)&local_128.n2);
              iVar2 = (**(code **)(*local_190 + 0x90))
                                (local_190,0,iVar6,&local_128,&(((_union_2707 *)local_178)->n2).n3);
              VariantClear((VARIANTARG *)&local_128.n2);
            }
            else {
              uStack_c0 = (undefined2)iVar6;
              uStack_be = (undefined2)((uint)iVar6 >> 0x10);
              local_128._0_8_ = CONCAT62(local_66,uStack_68);
              local_128._10_6_ = uStack_5e;
              local_128._8_2_ = uStack_60;
              local_128._16_8_ = CONCAT26(uStack_52,CONCAT42(uStack_56,uStack_58));
              local_148 = CONCAT62(uStack_7e,uStack_80);
              _Stack_140.Lo64._2_6_ = local_76;
              _Stack_140.s2.Lo32._0_2_ = uStack_78;
              local_138 = CONCAT62(uStack_6e,uStack_70);
              local_108._0_8_ = CONCAT62(local_96,uStack_98);
              local_108._10_6_ = uStack_8e;
              local_108._8_2_ = uStack_90;
              local_108._16_8_ = CONCAT62(uStack_86,uStack_88);
              local_48 = CONCAT62(uStack_ae,uStack_b0);
              uStack_40 = CONCAT62(local_a6,uStack_a8);
              local_38 = CONCAT62(uStack_9e,uStack_a0);
              local_e8 = CONCAT62(uStack_c6,local_c8);
              _Stack_e0.s2.Mid32 = uStack_bc;
              _Stack_e0.s2.Lo32 = iVar6;
              local_d8 = CONCAT62(uStack_b6,uStack_b8);
              iVar2 = (**(code **)(*local_190 + 0x68))
                                (local_190,&local_e8,&local_48,&local_108,&local_148,&local_128,
                                 &(((_union_2707 *)local_178)->n2).n3);
            }
            if ((-1 < iVar2) && (local_178._8_8_ != 0)) {
              local_e8 = CONCAT62(local_178._2_6_,local_178._0_2_);
              _Stack_e0.Lo64 = local_178._8_8_;
              local_d8 = local_178._16_8_;
              FUN_180054dc0(param_2,iVar6,2 - (ushort)(iVar5 != 0),(uint *)&local_e8);
              (**(code **)(*(longlong *)local_178._8_8_ + 0x10))();
              local_178._8_8_ = (_union_1719)0x0;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < local_res18[0]);
        }
        (**(code **)(*local_190 + 0x10))();
        (**(code **)(*local_198 + 0x10))();
        if (-1 < iVar2) goto LAB_180056647;
        goto LAB_180056634;
      }
      (**(code **)(*local_190 + 0x10))();
    }
LAB_18005643b:
    (**(code **)(*local_198 + 0x10))();
  }
  else {
    (**(code **)(*local_198 + 0x10))();
LAB_180056634:
    iVar2 = (**(code **)(*param_1 + 0x138))(param_1,0x7d1);
  }
LAB_180056647:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_160);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_188);
  return iVar2;
}

/* ---- FUNC 00056690 FUN_180056690 (17 bytes) ---- */

undefined8 FUN_180056690(longlong param_1,short *param_2)

{
  *param_2 = -(ushort)(*(int *)(param_1 + 0x150) != 0);
  return 0;
}

/* ---- FUNC 000566B0 FUN_1800566b0 (39 bytes) ---- */

undefined8 FUN_1800566b0(longlong param_1,undefined8 *param_2)

{
  *param_2 = *(undefined8 *)(param_1 + 0x100);
  if (*(longlong **)(param_1 + 0x100) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0x100) + 8))();
  }
  return 0;
}

/* ---- FUNC 000566E0 FUN_1800566e0 (11 bytes) ---- */

undefined8 FUN_1800566e0(longlong param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x130);
  return 0;
}

/* ---- FUNC 000566F0 FUN_1800566f0 (150 bytes) ---- */

undefined8 FUN_1800566f0(longlong *param_1,int param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  BSTR pOVar2;
  undefined8 uVar3;
  
  if ((-1 < param_2) && ((longlong)param_2 < param_1[0x26])) {
    puVar1 = *(undefined8 **)(param_1[0x25] + (longlong)param_2 * 8);
    pOVar2 = SysAllocString((OLECHAR *)puVar1[2]);
    param_3[2] = pOVar2;
    *param_3 = *puVar1;
    param_3[1] = puVar1[1];
    *(undefined4 *)(param_3 + 3) = *(undefined4 *)(puVar1 + 3);
    *(undefined2 *)(param_3 + 5) = *(undefined2 *)(puVar1 + 5);
    pOVar2 = SysAllocString((OLECHAR *)puVar1[4]);
    param_3[4] = pOVar2;
    *(undefined2 *)((longlong)param_3 + 0x2a) = *(undefined2 *)((longlong)puVar1 + 0x2a);
    *(undefined2 *)((longlong)param_3 + 0x2c) = *(undefined2 *)((longlong)puVar1 + 0x2c);
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x00018005677f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (**(code **)(*param_1 + 0x2b8))(param_1,0x7d1);
  return uVar3;
}

/* ---- FUNC 00056790 FUN_180056790 (51 bytes) ---- */

undefined8 FUN_180056790(longlong *param_1,int param_2,undefined4 *param_3)

{
  undefined8 uVar1;
  
  if ((-1 < param_2) && ((longlong)param_2 < param_1[0x21])) {
    *param_3 = *(undefined4 *)(*(longlong *)(param_1[0x20] + (longlong)param_2 * 8) + 8);
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0001800567bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*param_1 + 0x2b8))(param_1,0x7d1);
  return uVar1;
}

/* ---- FUNC 000567D0 FUN_1800567d0 (121 bytes) ---- */

undefined8 FUN_1800567d0(longlong *param_1,int param_2,undefined4 *param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  
  if (param_2 == 0) {
    if (0 < param_1[0x1c]) {
      *param_3 = *(undefined4 *)(*(longlong *)param_1[0x1b] + 0x10);
      return 0;
    }
    *param_3 = 0;
    return 0;
  }
  if ((0 < param_2) && (lVar2 = (longlong)param_2 + -1, lVar2 < param_1[0x21])) {
    if (-1 < lVar2) {
      *param_3 = *(undefined4 *)(*(longlong *)(param_1[0x20] + lVar2 * 8) + 0x10);
      return 0;
    }
                    /* WARNING: Subroutine does not return */
    AfxThrowInvalidArgException();
  }
                    /* WARNING: Could not recover jumptable at 0x00018005683d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*param_1 + 0x2b8))(param_1,0x7d1);
  return uVar1;
}

/* ---- FUNC 00056850 FUN_180056850 (11 bytes) ---- */

undefined8 FUN_180056850(longlong param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x8c);
  return 0;
}

/* ---- FUNC 00056860 FUN_180056860 (17 bytes) ---- */

undefined8 FUN_180056860(longlong param_1,short *param_2)

{
  *param_2 = -(ushort)(*(int *)(param_1 + 0x178) != 0);
  return 0;
}

/* ---- FUNC 00056880 FUN_180056880 (33 bytes) ---- */

undefined8 FUN_180056880(longlong param_1,undefined8 *param_2)

{
  *param_2 = *(undefined8 *)(param_1 + 0x18);
  if (*(longlong **)(param_1 + 0x18) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0x18) + 8))();
  }
  return 0;
}

/* ---- FUNC 000568B0 FUN_1800568b0 (51 bytes) ---- */

undefined8 FUN_1800568b0(longlong *param_1,int param_2,undefined4 *param_3)

{
  undefined8 uVar1;
  
  if ((-1 < param_2) && ((longlong)param_2 < param_1[0x21])) {
    *param_3 = *(undefined4 *)(*(longlong *)(param_1[0x20] + (longlong)param_2 * 8) + 0xc);
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0001800568dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*param_1 + 0x2b8))(param_1,0x7d1);
  return uVar1;
}

/* ---- FUNC 000568F0 FUN_1800568f0 (117 bytes) ---- */

undefined4 FUN_1800568f0(longlong param_1,int *param_2)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  int iVar5;
  int *piVar6;
  
  lVar1 = *(longlong *)(param_1 + 0xe0);
  if (lVar1 == 0) {
    *param_2 = -1;
    return 1;
  }
  if (0 < lVar1) {
    piVar6 = *(int **)(param_1 + 0xd8);
    iVar5 = 1;
    iVar3 = *piVar6;
    if (1 < lVar1) {
      lVar4 = 1;
      do {
        piVar6 = piVar6 + 1;
        if ((lVar4 < 0) || (lVar1 <= lVar4)) goto LAB_180056960;
        iVar2 = *piVar6;
        if (iVar3 <= *piVar6) {
          iVar2 = iVar3;
        }
        iVar3 = iVar2;
        iVar5 = iVar5 + 1;
        lVar4 = lVar4 + 1;
      } while (iVar5 < lVar1);
    }
    *param_2 = iVar3;
    return 0;
  }
LAB_180056960:
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00056970 FUN_180056970 (13 bytes) ---- */

undefined8 FUN_180056970(longlong param_1,undefined2 *param_2)

{
  *param_2 = *(undefined2 *)(param_1 + 0x164);
  return 0;
}

/* ---- FUNC 00056980 FUN_180056980 (107 bytes) ---- */

undefined8 FUN_180056980(longlong param_1,longlong param_2,wchar_t *param_3,undefined2 *param_4)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined4 local_res8 [2];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res20 [8];
  
  *param_4 = 0;
  puVar1 = (undefined8 *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
           CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20,param_3);
  uVar2 = FUN_180052e30(param_1 + 0x110,local_res8,puVar1,param_2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20);
  if ((int)uVar2 != 0) {
    *param_4 = 0xffff;
  }
  return 0;
}

/* ---- FUNC 000569F0 FUN_1800569f0 (129 bytes) ---- */

undefined8 FUN_1800569f0(longlong *param_1,int param_2,undefined8 *param_3)

{
  BSTR pOVar1;
  undefined8 uVar2;
  LPCSTR local_res20;
  
  if ((-1 < param_2) && ((longlong)param_2 < param_1[0x21])) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
               *(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> **)
                (param_1[0x20] + (longlong)param_2 * 8));
    if (0 < *(int *)(local_res20 + -0x10)) {
      pOVar1 = FUN_18005d480(local_res20);
      *param_3 = pOVar1;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
      return 0;
    }
    *param_3 = 0;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
    return 0;
  }
  uVar2 = (**(code **)(*param_1 + 0x2b8))(param_1,0x7d1);
  return uVar2;
}

/* ---- FUNC 00056A80 FUN_180056a80 (57 bytes) ---- */

ulonglong FUN_180056a80(longlong *param_1,int param_2,undefined8 *param_3)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar5;
  BSTR pOVar6;
  ulonglong uVar7;
  int iVar8;
  longlong lVar9;
  int local_res10 [2];
  int local_res20 [2];
  wchar_t *local_68;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined8 local_50;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  
  if ((param_2 < 0) || (lVar9 = (longlong)param_2, param_1[0x21] <= lVar9)) {
    uVar7 = (**(code **)(*param_1 + 0x2b8))(param_1,0x7d1);
    return uVar7;
  }
  uVar3 = 0;
  local_res20[0] = 0;
  local_res10[0] = 0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_68,
             *(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> **)
              (param_1[0x20] + lVar9 * 8));
  if (*(int *)((longlong)param_1 + 0x15c) == 0) {
LAB_180056b73:
    if (param_1[0x21] <= lVar9) goto MFC140_DLL_AfxThrowInvalidArgException;
    FUN_1800515b0(*(longlong *)(param_1[0x20] + lVar9 * 8),local_res10,local_res20);
    iVar2 = local_res20[0];
    iVar8 = local_res10[0];
  }
  else {
    pcVar4 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)&local_68,0);
    iVar2 = 0;
    iVar8 = 0;
    if (*pcVar4 != '\0') {
      pcVar4 = pcVar4 + 7;
      do {
        iVar2 = _strnicmp("%param + unit%",pcVar4 + -7,0xe);
        if (iVar2 == 0) {
          if (param_1[0x21] < 1) goto MFC140_DLL_AfxThrowInvalidArgException;
          FUN_1800515b0(*(longlong *)param_1[0x20],local_res10,local_res20);
          pcVar4[-1] = '%';
          pcVar4[0] = ' ';
          pcVar4[1] = '%';
        }
        pcVar1 = pcVar4 + -6;
        pcVar4 = pcVar4 + 1;
        iVar2 = local_res20[0];
        iVar8 = local_res10[0];
      } while (*pcVar1 != '\0');
    }
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_68,-1);
    if ((iVar8 == 0) || (iVar2 == 0)) goto LAB_180056b73;
  }
  pCVar5 = FUN_180051ae0((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         local_res20,(longlong *)param_1[3],iVar8,iVar2,local_68);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_68,
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar5);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res20);
  if (*(int *)(local_68 + -8) < 1) {
    local_60 = CONCAT22(local_60._2_2_,2);
    if (param_1[0x21] <= lVar9) {
MFC140_DLL_AfxThrowInvalidArgException:
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
    local_38 = local_50;
    uStack_58 = CONCAT22(uStack_58._2_2_,
                         *(undefined2 *)(*(longlong *)(param_1[0x20] + lVar9 * 8) + 8));
    local_48 = local_60;
    uStack_44 = uStack_5c;
    uStack_40 = uStack_58;
    uStack_3c = uStack_54;
    uVar3 = (**(code **)(*param_1 + 0x80))(param_1,&local_48,param_3);
  }
  else {
    pOVar6 = FUN_18005d480((LPCSTR)local_68);
    *param_3 = pOVar6;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_68);
  return (ulonglong)uVar3;
}

/* ---- FUNC 00056AB9 FUN_180056ab9 (427 bytes) ---- */

undefined4
FUN_180056ab9(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,
             longlong param_2)

{
  char *pcVar1;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar2;
  longlong lVar3;
  int iVar4;
  undefined4 uVar5;
  longlong in_RAX;
  char *pcVar6;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar7;
  BSTR pOVar8;
  undefined8 unaff_RBX;
  longlong unaff_RBP;
  int iVar9;
  undefined8 unaff_RSI;
  longlong *unaff_RDI;
  undefined8 *unaff_R12;
  longlong unaff_R14;
  undefined8 unaff_R15;
  
  *(undefined8 *)(in_RAX + 8) = unaff_RBX;
  *(undefined8 *)(in_RAX + 0x18) = unaff_RSI;
  *(undefined8 *)(in_RAX + -0x28) = unaff_R15;
  uVar5 = 0;
  pCVar2 = *(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> **)
            (param_2 + unaff_R14 * 8);
  iVar4 = 0;
  *(undefined4 *)(unaff_RBP + 0x40) = 0;
  iVar9 = 0;
  *(undefined4 *)(unaff_RBP + 0x30) = 0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1,pCVar2);
  if (*(int *)((longlong)unaff_RDI + 0x15c) == 0) {
LAB_180056b73:
    if (unaff_RDI[0x21] <= unaff_R14) goto MFC140_DLL_AfxThrowInvalidArgException;
    FUN_1800515b0(*(longlong *)(unaff_RDI[0x20] + unaff_R14 * 8),(undefined4 *)(unaff_RBP + 0x30),
                  (undefined4 *)(unaff_RBP + 0x40));
    iVar9 = *(int *)(unaff_RBP + 0x30);
    iVar4 = *(int *)(unaff_RBP + 0x40);
  }
  else {
    pcVar6 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)(unaff_RBP + -0x48),0)
    ;
    if (*pcVar6 != '\0') {
      pcVar6 = pcVar6 + 7;
      do {
        iVar4 = _strnicmp("%param + unit%",pcVar6 + -7,0xe);
        if (iVar4 == 0) {
          if (unaff_RDI[0x21] < 1) goto MFC140_DLL_AfxThrowInvalidArgException;
          FUN_1800515b0(*(longlong *)unaff_RDI[0x20],(undefined4 *)(unaff_RBP + 0x30),
                        (undefined4 *)(unaff_RBP + 0x40));
          pcVar6[-1] = '%';
          pcVar6[0] = ' ';
          pcVar6[1] = '%';
        }
        pcVar1 = pcVar6 + -6;
        pcVar6 = pcVar6 + 1;
      } while (*pcVar1 != '\0');
      iVar9 = *(int *)(unaff_RBP + 0x30);
      iVar4 = *(int *)(unaff_RBP + 0x40);
    }
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)(unaff_RBP + -0x48),-1);
    if ((iVar9 == 0) || (iVar4 == 0)) goto LAB_180056b73;
  }
  pCVar7 = FUN_180051ae0((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         (unaff_RBP + 0x40),(longlong *)unaff_RDI[3],iVar9,iVar4,
                         *(wchar_t **)(unaff_RBP + -0x48));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + -0x48),
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar7);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + 0x40));
  if (*(int *)(*(LPCSTR *)(unaff_RBP + -0x48) + -0x10) < 1) {
    *(undefined2 *)(unaff_RBP + -0x40) = 2;
    if (unaff_RDI[0x21] <= unaff_R14) {
MFC140_DLL_AfxThrowInvalidArgException:
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
    lVar3 = unaff_RDI[0x20];
    *(undefined8 *)(unaff_RBP + -0x18) = *(undefined8 *)(unaff_RBP + -0x30);
    *(undefined2 *)(unaff_RBP + -0x38) = *(undefined2 *)(*(longlong *)(lVar3 + unaff_R14 * 8) + 8);
    lVar3 = *unaff_RDI;
    *(undefined4 *)(unaff_RBP + -0x28) = *(undefined4 *)(unaff_RBP + -0x40);
    *(undefined4 *)(unaff_RBP + -0x24) = *(undefined4 *)(unaff_RBP + -0x3c);
    *(undefined4 *)(unaff_RBP + -0x20) = *(undefined4 *)(unaff_RBP + -0x38);
    *(undefined4 *)(unaff_RBP + -0x1c) = *(undefined4 *)(unaff_RBP + -0x34);
    uVar5 = (**(code **)(lVar3 + 0x80))(*(undefined4 *)(unaff_RBP + -0x40),unaff_RBP + -0x28);
  }
  else {
    pOVar8 = FUN_18005d480(*(LPCSTR *)(unaff_RBP + -0x48));
    *unaff_R12 = pOVar8;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + -0x48));
  return uVar5;
}

/* ---- FUNC 00056C64 FUN_180056c64 (25 bytes) ---- */

void FUN_180056c64(longlong *param_1)

{
  (**(code **)(*param_1 + 0x2b8))(param_1,0x7d1);
  return;
}

/* ---- FUNC 00056C7D AfxThrowInvalidArgException (5 bytes) ---- */

void __cdecl AfxThrowInvalidArgException(void)

{
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00056C90 FUN_180056c90 (55 bytes) ---- */

undefined8 FUN_180056c90(longlong *param_1,short param_2,undefined2 *param_3)

{
  undefined8 uVar1;
  
  if ((-1 < param_2) && ((longlong)param_2 < param_1[0x21])) {
    *param_3 = *(undefined2 *)(*(longlong *)(param_1[0x20] + (longlong)param_2 * 8) + 0x14);
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180056cc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*param_1 + 0x2b8))(param_1,0x7d1);
  return uVar1;
}

/* ---- FUNC 00056CD0 FUN_180056cd0 (13 bytes) ---- */

undefined8 FUN_180056cd0(longlong param_1,undefined2 *param_2)

{
  *param_2 = *(undefined2 *)(param_1 + 0x168);
  return 0;
}

/* ---- FUNC 00056CE0 FUN_180056ce0 (55 bytes) ---- */

undefined8 FUN_180056ce0(longlong *param_1,short param_2,undefined2 *param_3)

{
  undefined8 uVar1;
  
  if ((-1 < param_2) && ((longlong)param_2 < param_1[0x21])) {
    *param_3 = *(undefined2 *)(*(longlong *)(param_1[0x20] + (longlong)param_2 * 8) + 0x16);
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180056d10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*param_1 + 0x2b8))(param_1,0x7d1);
  return uVar1;
}

/* ---- FUNC 00056D20 FUN_180056d20 (17 bytes) ---- */

undefined8 FUN_180056d20(longlong param_1,short *param_2)

{
  *param_2 = -(ushort)(*(int *)(param_1 + 0x160) != 0);
  return 0;
}

/* ---- FUNC 00056D40 FUN_180056d40 (55 bytes) ---- */

undefined8 FUN_180056d40(longlong *param_1,short param_2,undefined2 *param_3)

{
  undefined8 uVar1;
  
  if ((-1 < param_2) && ((longlong)param_2 < param_1[0x21])) {
    *param_3 = *(undefined2 *)(*(longlong *)(param_1[0x20] + (longlong)param_2 * 8) + 0x1a);
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180056d70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*param_1 + 0x2b8))(param_1,0x7d1);
  return uVar1;
}

/* ---- FUNC 00056D80 FUN_180056d80 (13 bytes) ---- */

undefined8 FUN_180056d80(longlong param_1,undefined2 *param_2)

{
  *param_2 = *(undefined2 *)(param_1 + 0x166);
  return 0;
}

/* ---- FUNC 00056D90 FUN_180056d90 (55 bytes) ---- */

undefined8 FUN_180056d90(longlong *param_1,short param_2,undefined2 *param_3)

{
  undefined8 uVar1;
  
  if ((-1 < param_2) && ((longlong)param_2 < param_1[0x21])) {
    *param_3 = *(undefined2 *)(*(longlong *)(param_1[0x20] + (longlong)param_2 * 8) + 0x18);
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180056dc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*param_1 + 0x2b8))(param_1,0x7d1);
  return uVar1;
}

/* ---- FUNC 00056DD0 FUN_180056dd0 (11 bytes) ---- */

undefined8 FUN_180056dd0(longlong param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 200);
  return 0;
}

/* ---- FUNC 00056DE0 FUN_180056de0 (11 bytes) ---- */

undefined8 FUN_180056de0(longlong param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x108);
  return 0;
}

/* ---- FUNC 00056DF0 FUN_180056df0 (11 bytes) ---- */

undefined8 FUN_180056df0(longlong param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0xe0);
  return 0;
}

/* ---- FUNC 00056E00 FUN_180056e00 (17 bytes) ---- */

undefined8 FUN_180056e00(longlong param_1,short *param_2)

{
  *param_2 = -(ushort)(*(int *)(param_1 + 0x15c) != 0);
  return 0;
}

/* ---- FUNC 00056E20 FUN_180056e20 (11 bytes) ---- */

undefined8 FUN_180056e20(longlong param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x158);
  return 0;
}

/* ---- FUNC 00056E30 FUN_180056e30 (32 bytes) ---- */

undefined8 FUN_180056e30(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  
  plVar1 = *(longlong **)(param_1 + 0x90);
  *param_2 = (longlong)plVar1;
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 8))();
  }
  return 0;
}

/* ---- FUNC 00056E50 FUN_180056e50 (53 bytes) ---- */

undefined8 FUN_180056e50(longlong param_1,undefined8 *param_2)

{
  BSTR pOVar1;
  
  if (*(int *)(*(LPCSTR *)(param_1 + 0xf8) + -0x10) == 0) {
    *param_2 = 0;
    return 0;
  }
  pOVar1 = FUN_18005d480(*(LPCSTR *)(param_1 + 0xf8));
  *param_2 = pOVar1;
  return 0;
}

/* ---- FUNC 00056E90 FUN_180056e90 (17 bytes) ---- */

undefined8 FUN_180056e90(longlong param_1,short *param_2)

{
  *param_2 = -(ushort)(*(int *)(param_1 + 0x14c) != 0);
  return 0;
}

/* ---- FUNC 00056EB0 FUN_180056eb0 (17 bytes) ---- */

undefined8 FUN_180056eb0(longlong param_1,short *param_2)

{
  *param_2 = -(ushort)(*(int *)(param_1 + 0x16c) != 0);
  return 0;
}

/* ---- FUNC 00056ED0 FUN_180056ed0 (17 bytes) ---- */

undefined8 FUN_180056ed0(longlong param_1,short *param_2)

{
  *param_2 = -(ushort)(*(int *)(param_1 + 0x154) != 0);
  return 0;
}

/* ---- FUNC 00056EF0 FUN_180056ef0 (17 bytes) ---- */

undefined8 FUN_180056ef0(longlong param_1,short *param_2)

{
  *param_2 = -(ushort)(*(int *)(param_1 + 0x170) != 0);
  return 0;
}

/* ---- FUNC 00056F10 FUN_180056f10 (17 bytes) ---- */

undefined8 FUN_180056f10(longlong param_1,short *param_2)

{
  *param_2 = -(ushort)(*(int *)(param_1 + 0x174) != 0);
  return 0;
}

/* ---- FUNC 00056F30 FUN_180056f30 (17 bytes) ---- */

undefined8 FUN_180056f30(longlong param_1,short *param_2)

{
  *param_2 = -(ushort)(*(int *)(param_1 + 0x148) != 0);
  return 0;
}

/* ---- FUNC 00056F50 FUN_180056f50 (32 bytes) ---- */

undefined8 FUN_180056f50(longlong param_1,undefined8 *param_2)

{
  BSTR pOVar1;
  
  pOVar1 = FUN_18005d480(*(LPCSTR *)(param_1 + 0x90));
  *param_2 = pOVar1;
  return 0;
}

/* ---- FUNC 00056F70 FUN_180056f70 (288 bytes) ---- */

undefined8 FUN_180056f70(longlong param_1,undefined8 *param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  BSTR pOVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  int iVar6;
  ulonglong uVar7;
  int iVar8;
  ulonglong uVar9;
  uint local_res8 [4];
  uint local_res18 [2];
  LPCSTR local_res20;
  
  uVar1 = *(ulonglong *)(param_1 + 0x108);
  uVar4 = 0;
  local_res8[0] = 0;
  local_res18[0] = 0;
  uVar5 = uVar4;
  uVar7 = uVar4;
  uVar9 = uVar4;
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar5 < 0) || ((longlong)uVar1 <= (longlong)uVar5)) goto LAB_18005708b;
      lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x100) + uVar5 * 8);
      if (lVar2 != 0) {
        FUN_1800515b0(lVar2,local_res8,local_res18);
        uVar7 = (ulonglong)local_res8[0];
        uVar9 = (ulonglong)local_res18[0];
      }
      iVar6 = (int)uVar7;
      iVar8 = (int)uVar9;
    } while (((iVar6 == 0) || (iVar8 == 0)) && (uVar5 = uVar5 + 1, uVar5 < uVar1));
    if ((iVar6 != 0) && (iVar8 != 0)) goto LAB_18005704c;
  }
  iVar8 = (int)uVar9;
  iVar6 = (int)uVar7;
  uVar1 = *(ulonglong *)(param_1 + 0xe0);
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar4 < 0) || ((longlong)uVar1 <= (longlong)uVar4)) {
LAB_18005708b:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      lVar2 = *(longlong *)(*(longlong *)(param_1 + 0xd8) + uVar4 * 8);
      if (lVar2 != 0) {
        FUN_1800515b0(lVar2,local_res8,local_res18);
        uVar7 = (ulonglong)local_res8[0];
        uVar9 = (ulonglong)local_res18[0];
      }
      iVar8 = (int)uVar9;
      iVar6 = (int)uVar7;
    } while (((iVar6 == 0) || (iVar8 == 0)) && (uVar4 = uVar4 + 1, uVar4 < uVar1));
  }
LAB_18005704c:
  FUN_180051ae0((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
                *(longlong **)(param_1 + 0x18),iVar6,iVar8,*(wchar_t **)(param_1 + 0x90));
  pOVar3 = FUN_18005d480(local_res20);
  *param_2 = pOVar3;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
  return 0;
}

/* ---- FUNC 000570A0 FUN_1800570a0 (274 bytes) ---- */

undefined8 FUN_1800570a0(longlong param_1,short *param_2,int *param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  int iVar5;
  int local_res10 [2];
  undefined4 local_res18 [4];
  
  iVar5 = -1;
  if (*param_2 == 2) {
    iVar5 = (int)param_2[4];
  }
  else if (*param_2 == 3) {
    iVar5 = *(int *)(param_2 + 4);
  }
  *param_3 = 0;
  local_res10[0] = 0;
  if (-1 < iVar5) {
    if ((longlong)iVar5 < *(longlong *)(*(longlong *)(param_1 + 0x90) + 0x108)) {
      if (-1 < iVar5) {
        lVar1 = *(longlong *)
                 (*(longlong *)(*(longlong *)(param_1 + 0x90) + 0x100) + (longlong)iVar5 * 8);
        iVar5 = 0;
        if (lVar1 != 0) {
          FUN_1800515b0(lVar1,local_res18,local_res10);
          iVar5 = local_res10[0];
        }
        *param_3 = iVar5;
        return 0;
      }
      goto LAB_1800571ad;
    }
  }
  lVar1 = *(longlong *)(param_1 + 0x90);
  uVar2 = *(ulonglong *)(lVar1 + 0x108);
  uVar4 = (ulonglong)(*(int *)(lVar1 + 0x15c) != 0);
  if (uVar2 <= uVar4) {
    return 0;
  }
  while ((-1 < (longlong)uVar4 && ((longlong)uVar4 < (longlong)uVar2))) {
    lVar3 = *(longlong *)(*(longlong *)(lVar1 + 0x100) + uVar4 * 8);
    if ((lVar3 != 0) && (FUN_1800515b0(lVar3,local_res18,local_res10), local_res10[0] != 0)) {
      *param_3 = local_res10[0];
      return 0;
    }
    uVar4 = uVar4 + 1;
    if (uVar2 <= uVar4) {
      return 0;
    }
  }
LAB_1800571ad:
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 000571C0 FUN_1800571c0 (274 bytes) ---- */

undefined8 FUN_1800571c0(longlong param_1,short *param_2,int *param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  int iVar5;
  int local_res10 [2];
  undefined4 local_res18 [4];
  
  iVar5 = -1;
  if (*param_2 == 2) {
    iVar5 = (int)param_2[4];
  }
  else if (*param_2 == 3) {
    iVar5 = *(int *)(param_2 + 4);
  }
  *param_3 = 0;
  local_res10[0] = 0;
  if (-1 < iVar5) {
    if ((longlong)iVar5 < *(longlong *)(*(longlong *)(param_1 + 0x90) + 0x108)) {
      if (-1 < iVar5) {
        lVar1 = *(longlong *)
                 (*(longlong *)(*(longlong *)(param_1 + 0x90) + 0x100) + (longlong)iVar5 * 8);
        iVar5 = 0;
        if (lVar1 != 0) {
          FUN_1800515b0(lVar1,local_res10,local_res18);
          iVar5 = local_res10[0];
        }
        *param_3 = iVar5;
        return 0;
      }
      goto LAB_1800572cd;
    }
  }
  lVar1 = *(longlong *)(param_1 + 0x90);
  uVar2 = *(ulonglong *)(lVar1 + 0x108);
  uVar4 = (ulonglong)(*(int *)(lVar1 + 0x15c) != 0);
  if (uVar2 <= uVar4) {
    return 0;
  }
  while ((-1 < (longlong)uVar4 && ((longlong)uVar4 < (longlong)uVar2))) {
    lVar3 = *(longlong *)(*(longlong *)(lVar1 + 0x100) + uVar4 * 8);
    if ((lVar3 != 0) && (FUN_1800515b0(lVar3,local_res10,local_res18), local_res10[0] != 0)) {
      *param_3 = local_res10[0];
      return 0;
    }
    uVar4 = uVar4 + 1;
    if (uVar2 <= uVar4) {
      return 0;
    }
  }
LAB_1800572cd:
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 000572E0 FUN_1800572e0 (104 bytes) ---- */

undefined8 FUN_1800572e0(longlong *param_1,ushort param_2,undefined8 *param_3)

{
  int iVar1;
  undefined8 uVar2;
  longlong *local_res8;
  
  *param_3 = 0;
  iVar1 = CMapWordToPtr::Lookup((CMapWordToPtr *)(param_1 + 0x13),param_2,&local_res8);
  if ((iVar1 != 0) && (local_res8 != (longlong *)0x0)) {
    *param_3 = local_res8;
    (**(code **)(*local_res8 + 8))();
    return 0;
  }
  uVar2 = (**(code **)(*param_1 + 0x138))(param_1,0x7d1);
  return uVar2;
}

/* ---- FUNC 00057350 FUN_180057350 (53 bytes) ---- */

undefined8 FUN_180057350(longlong param_1,undefined8 *param_2)

{
  BSTR pOVar1;
  
  if (0 < *(longlong *)(param_1 + 0xe0)) {
    pOVar1 = FUN_18005d480(*(LPCSTR *)**(undefined8 **)(param_1 + 0xd8));
    *param_2 = pOVar1;
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00057390 FUN_180057390 (36 bytes) ---- */

undefined8 FUN_180057390(longlong param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar2;
  BSTR pOVar3;
  int local_res8 [4];
  int local_res18 [2];
  LPCSTR local_res20;
  
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
  if (0 < *(longlong *)(param_1 + 0xe0)) {
    local_res18[0] = 0;
    local_res8[0] = 0;
    puVar1 = (undefined8 *)**(longlong **)(param_1 + 0xd8);
    FUN_1800515b0((longlong)puVar1,local_res18,local_res8);
    pCVar2 = FUN_180051ae0((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           local_res8,*(longlong **)(param_1 + 0x18),local_res18[0],local_res8[0],
                           (wchar_t *)*puVar1);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar2);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res8);
  }
  pOVar3 = FUN_18005d480(local_res20);
  *param_2 = pOVar3;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
  return 0;
}

/* ---- FUNC 000573B4 FUN_1800573b4 (103 bytes) ---- */

undefined8 FUN_1800573b4(void)

{
  undefined8 *puVar1;
  int in_EAX;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar2;
  BSTR pOVar3;
  undefined8 *unaff_RSI;
  longlong unaff_RDI;
  int iStack0000000000000050;
  int iStack0000000000000060;
  LPCSTR in_stack_00000068;
  
  puVar1 = (undefined8 *)**(longlong **)(unaff_RDI + 0xd8);
  iStack0000000000000050 = in_EAX;
  iStack0000000000000060 = in_EAX;
  FUN_1800515b0((longlong)puVar1,&stack0x00000060,&stack0x00000050);
  pCVar2 = FUN_180051ae0((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         &stack0x00000050,*(longlong **)(unaff_RDI + 0x18),iStack0000000000000060,
                         iStack0000000000000050,(wchar_t *)*puVar1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000068,
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000050);
  pOVar3 = FUN_18005d480(in_stack_00000068);
  *unaff_RSI = pOVar3;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000068);
  return 0;
}

/* ---- FUNC 0005741B FUN_18005741b (33 bytes) ---- */

undefined8 FUN_18005741b(void)

{
  BSTR pOVar1;
  undefined8 *unaff_RSI;
  LPCSTR in_stack_00000068;
  
  pOVar1 = FUN_18005d480(in_stack_00000068);
  *unaff_RSI = pOVar1;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000068);
  return 0;
}

/* ---- FUNC 00057440 FUN_180057440 (91 bytes) ---- */

undefined8 FUN_180057440(longlong *param_1,int param_2,undefined2 *param_3)

{
  short sVar1;
  undefined8 uVar2;
  undefined2 uVar3;
  
  if ((-1 < param_2) && ((longlong)param_2 < param_1[0x1c])) {
    sVar1 = FUN_180050f80(*(longlong *)(param_1[0x1b] + (longlong)param_2 * 8));
    uVar3 = 0xffff;
    if (1 < (ushort)(sVar1 - 2U)) {
      uVar3 = 0;
    }
    *param_3 = uVar3;
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180057494. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(*param_1 + 0x2b8))(param_1,0x7d1);
  return uVar2;
}

/* ---- FUNC 000574A0 FUN_1800574a0 (82 bytes) ---- */

undefined8 FUN_1800574a0(longlong *param_1,int param_2,int param_3,_union_1719 *param_4)

{
  undefined8 uVar1;
  
  if ((((-1 < param_2) && ((longlong)param_2 < param_1[0x1c])) && (-1 < param_3)) &&
     (param_3 < (int)param_1[0x19])) {
    FUN_180050fe0(*(longlong *)(param_1[0x1b] + (longlong)param_2 * 8),param_3,param_4);
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0001800574eb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*param_1 + 0x2b8))(param_1,0x7d1);
  return uVar1;
}

/* ---- FUNC 00057500 FUN_180057500 (145 bytes) ---- */

undefined8 FUN_180057500(longlong param_1,int *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  int local_res8 [2];
  undefined4 local_res10 [2];
  
  uVar4 = 0;
  *param_2 = 0;
  lVar1 = *(longlong *)(param_1 + 0x90);
  local_res8[0] = 0;
  uVar2 = *(ulonglong *)(lVar1 + 0xe0);
  if (uVar2 != 0) {
    do {
      if (((longlong)uVar4 < 0) || ((longlong)uVar2 <= (longlong)uVar4)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      lVar3 = *(longlong *)(*(longlong *)(lVar1 + 0xd8) + uVar4 * 8);
      if ((lVar3 != 0) && (FUN_1800515b0(lVar3,local_res10,local_res8), local_res8[0] != 0)) {
        *param_2 = local_res8[0];
        return 0;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar2);
  }
  return 0;
}

/* ---- FUNC 000575A0 FUN_1800575a0 (145 bytes) ---- */

undefined8 FUN_1800575a0(longlong param_1,int *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  int local_res8 [2];
  undefined4 local_res10 [2];
  
  uVar4 = 0;
  *param_2 = 0;
  lVar1 = *(longlong *)(param_1 + 0x90);
  local_res8[0] = 0;
  uVar2 = *(ulonglong *)(lVar1 + 0xe0);
  if (uVar2 != 0) {
    do {
      if (((longlong)uVar4 < 0) || ((longlong)uVar2 <= (longlong)uVar4)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      lVar3 = *(longlong *)(*(longlong *)(lVar1 + 0xd8) + uVar4 * 8);
      if ((lVar3 != 0) && (FUN_1800515b0(lVar3,local_res8,local_res10), local_res8[0] != 0)) {
        *param_2 = local_res8[0];
        return 0;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar2);
  }
  return 0;
}

/* ---- FUNC 00057640 FUN_180057640 (131 bytes) ---- */

undefined8 FUN_180057640(longlong param_1,short *param_2,undefined8 *param_3)

{
  BSTR pOVar1;
  longlong lVar2;
  
  if ((*param_2 == 2) || (*param_2 == 3)) {
    lVar2 = (longlong)param_2[4];
    if ((param_2[4] < 0) || (*(longlong *)(param_1 + 0xa8) <= lVar2)) {
      return 0x80070057;
    }
    if (-1 < lVar2) {
      pOVar1 = FUN_18005d480(*(LPCSTR *)(*(longlong *)(param_1 + 0xa0) + lVar2 * 8));
      *param_3 = pOVar1;
      return 0;
    }
  }
  else if (0 < *(longlong *)(param_1 + 0xa8)) {
    pOVar1 = FUN_18005d480((LPCSTR)**(undefined8 **)(param_1 + 0xa0));
    *param_3 = pOVar1;
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 000576D0 FUN_1800576d0 (413 bytes) ---- */

int FUN_1800576d0(longlong param_1,short *param_2,undefined8 *param_3)

{
  short sVar1;
  ulonglong uVar2;
  longlong lVar3;
  BSTR pOVar4;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar5;
  ulonglong uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_res10 [2];
  undefined8 *local_res18;
  int local_res20 [2];
  wchar_t *local_48;
  LPCSTR local_40;
  
  iVar8 = 0;
  iVar9 = 0;
  local_res10[0] = 0;
  local_res20[0] = 0;
  local_res18 = param_3;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48);
  sVar1 = *param_2;
  if ((sVar1 == 2) || (sVar1 == 3)) {
    lVar3 = (longlong)param_2[4];
    if ((param_2[4] < 0) || (*(longlong *)(param_1 + 0xa8) <= lVar3)) {
      iVar8 = -0x7ff8ffa9;
      goto LAB_180057842;
    }
    if (lVar3 < 0) goto LAB_180057868;
    pCVar5 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (*(longlong *)(param_1 + 0xa0) + lVar3 * 8);
  }
  else {
    if (*(longlong *)(param_1 + 0xa8) < 1) {
LAB_180057868:
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
    pCVar5 = *(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> **)
              (param_1 + 0xa0);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48,pCVar5);
  uVar2 = *(ulonglong *)(param_1 + 0x108);
  iVar7 = iVar8;
  for (uVar6 = (ulonglong)(*(int *)(param_1 + 0x15c) != 0); uVar6 < uVar2; uVar6 = uVar6 + 1) {
    if (((longlong)uVar6 < 0) || ((longlong)uVar2 <= (longlong)uVar6)) goto LAB_180057868;
    lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x100) + uVar6 * 8);
    if ((lVar3 != 0) && ((1 < (ushort)(sVar1 - 2U) || (*(int *)(lVar3 + 8) == (int)param_2[4])))) {
      FUN_1800515b0(lVar3,local_res10,local_res20);
      iVar9 = local_res10[0];
      iVar7 = local_res20[0];
    }
    if ((iVar9 != 0) && (iVar7 != 0)) break;
  }
  FUN_180051ae0((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_40,
                *(longlong **)(param_1 + 0x18),iVar9,iVar7,local_48);
  pOVar4 = FUN_18005d480(local_40);
  *local_res18 = pOVar4;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_40);
LAB_180057842:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48);
  return iVar8;
}

/* ---- FUNC 00057870 FUN_180057870 (90 bytes) ---- */

undefined8 FUN_180057870(longlong *param_1,int param_2,int param_3,_union_1719 *param_4)

{
  undefined8 uVar1;
  
  if (0 < param_1[0x21]) {
    if ((((param_2 < 0) || (param_1[0x21] <= (longlong)param_2)) || (param_3 < 0)) ||
       ((int)param_1[0x19] <= param_3)) {
                    /* WARNING: Could not recover jumptable at 0x0001800578c3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (**(code **)(*param_1 + 0x2b8))(param_1,0x7d1);
      return uVar1;
    }
    FUN_180050fe0(*(longlong *)(param_1[0x20] + (longlong)param_2 * 8),param_3,param_4);
  }
  return 0;
}

/* ---- FUNC 000578D0 FUN_1800578d0 (32 bytes) ---- */

undefined8 FUN_1800578d0(longlong param_1,undefined8 *param_2)

{
  BSTR pOVar1;
  
  pOVar1 = FUN_18005d480(*(LPCSTR *)(param_1 + 0xc0));
  *param_2 = pOVar1;
  return 0;
}

/* ---- FUNC 000578F0 FUN_1800578f0 (208 bytes) ---- */

undefined8 FUN_1800578f0(longlong param_1,undefined8 *param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  BSTR pOVar3;
  ulonglong uVar4;
  int iVar5;
  int iVar6;
  int local_res8 [2];
  int local_res18 [2];
  LPCSTR local_res20;
  
  uVar1 = *(ulonglong *)(param_1 + 0x108);
  iVar5 = 0;
  local_res8[0] = 0;
  local_res18[0] = 0;
  uVar4 = (ulonglong)(*(int *)(param_1 + 0x15c) != 0);
  iVar6 = 0;
  do {
    uVar4 = uVar4 + 1;
    if (uVar1 <= uVar4) break;
    if (((longlong)uVar4 < 0) || ((longlong)uVar1 <= (longlong)uVar4)) {
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
    lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x100) + uVar4 * 8);
    if (lVar2 != 0) {
      FUN_1800515b0(lVar2,local_res8,local_res18);
      iVar5 = local_res8[0];
      iVar6 = local_res18[0];
    }
  } while ((iVar5 == 0) || (iVar6 == 0));
  FUN_180051ae0((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
                *(longlong **)(param_1 + 0x18),iVar5,iVar6,*(wchar_t **)(param_1 + 0xc0));
  pOVar3 = FUN_18005d480(local_res20);
  *param_2 = pOVar3;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
  return 0;
}

/* ---- FUNC 000579D0 FUN_1800579d0 (12 bytes) ---- */

undefined8 FUN_1800579d0(longlong param_1,short param_2)

{
  *(int *)(param_1 + 0x150) = (int)param_2;
  return 0;
}

/* ---- FUNC 000579E0 FUN_1800579e0 (68 bytes) ---- */

undefined8 FUN_1800579e0(longlong param_1,longlong *param_2)

{
  if (*(longlong **)(param_1 + 0x100) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0x100) + 0x10))();
  }
  *(longlong **)(param_1 + 0x100) = param_2;
  if (param_2 != (longlong *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  return 0;
}

/* ---- FUNC 00057A30 FUN_180057a30 (71 bytes) ---- */

undefined8 FUN_180057a30(longlong *param_1,int param_2,int param_3)

{
  undefined8 uVar1;
  
  if ((param_3 < 0) || (param_1[0x21] <= (longlong)param_3)) {
    return 0x80070057;
  }
  if ((-1 < param_2) && ((longlong)param_2 < param_1[0x21])) {
    *(int *)(*(longlong *)(param_1[0x20] + (longlong)param_2 * 8) + 8) = param_3;
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180057a6a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*param_1 + 0x2b8))(param_1,0x7d1);
  return uVar1;
}

/* ---- FUNC 00057A80 FUN_180057a80 (156 bytes) ---- */

undefined8 FUN_180057a80(longlong *param_1,int param_2,undefined4 param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint uVar4;
  ulonglong uVar5;
  
  if (param_2 != 0) {
    if ((param_2 < 1) || (lVar2 = (longlong)param_2 + -1, param_1[0x21] <= lVar2)) {
                    /* WARNING: Could not recover jumptable at 0x000180057b10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (**(code **)(*param_1 + 0x2b8))(param_1,0x7d1);
      return uVar1;
    }
    if (-1 < lVar2) {
      *(undefined4 *)(*(longlong *)(param_1[0x20] + lVar2 * 8) + 0x10) = param_3;
      return 0;
    }
LAB_180057b17:
                    /* WARNING: Subroutine does not return */
    AfxThrowInvalidArgException();
  }
  lVar2 = param_1[0x1c];
  uVar3 = 0;
  uVar5 = uVar3;
  if (0 < lVar2) {
    do {
      if (((longlong)uVar3 < 0) || (lVar2 <= (longlong)uVar3)) goto LAB_180057b17;
      uVar4 = (int)uVar5 + 1;
      lVar2 = uVar3 * 8;
      uVar3 = uVar3 + 1;
      *(undefined4 *)(*(longlong *)(param_1[0x1b] + lVar2) + 0x10) = param_3;
      lVar2 = param_1[0x1c];
      uVar5 = (ulonglong)uVar4;
    } while ((int)uVar4 < lVar2);
  }
  return 0;
}

/* ---- FUNC 00057B20 FUN_180057b20 (9 bytes) ---- */

undefined8 FUN_180057b20(longlong param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x8c) = param_2;
  return 0;
}

/* ---- FUNC 00057B30 FUN_180057b30 (12 bytes) ---- */

undefined8 FUN_180057b30(longlong param_1,short param_2)

{
  *(int *)(param_1 + 0x178) = (int)param_2;
  return 0;
}

/* ---- FUNC 00057B40 FUN_180057b40 (25 bytes) ---- */

undefined8 FUN_180057b40(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  int iVar2;
  
  plVar1 = *(longlong **)(param_1 + 0x18);
  if (plVar1 != param_2) {
    if (plVar1 != (longlong *)0x0) {
      (**(code **)(*plVar1 + 0x10))();
    }
    if (*(longlong **)(param_1 + 0x20) != (longlong *)0x0) {
      (**(code **)(**(longlong **)(param_1 + 0x20) + 0x10))();
      *(undefined8 *)(param_1 + 0x20) = 0;
    }
    *(longlong **)(param_1 + 0x18) = param_2;
    if (param_2 != (longlong *)0x0) {
      (**(code **)(*param_2 + 8))(param_2);
      iVar2 = (**(code **)(**(longlong **)(param_1 + 0x18) + 0x110))
                        (*(longlong **)(param_1 + 0x18),L"Output",param_1 + 0x20);
      if (iVar2 < 0) {
        *(undefined8 *)(param_1 + 0x20) = 0;
      }
    }
    return 0;
  }
  return 0;
}

/* ---- FUNC 00057B59 FUN_180057b59 (111 bytes) ---- */

undefined8 FUN_180057b59(longlong *param_1)

{
  int iVar1;
  longlong *unaff_RBX;
  longlong unaff_RSI;
  
  if (param_1 != (longlong *)0x0) {
    (**(code **)(*param_1 + 0x10))();
  }
  if (*(longlong **)(unaff_RSI + 0x20) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(unaff_RSI + 0x20) + 0x10))();
    *(undefined8 *)(unaff_RSI + 0x20) = 0;
  }
  *(longlong **)(unaff_RSI + 0x18) = unaff_RBX;
  if (unaff_RBX != (longlong *)0x0) {
    (**(code **)(*unaff_RBX + 8))();
    iVar1 = (**(code **)(**(longlong **)(unaff_RSI + 0x18) + 0x110))
                      (*(longlong **)(unaff_RSI + 0x18),L"Output",unaff_RSI + 0x20);
    if (iVar1 < 0) {
      *(undefined8 *)(unaff_RSI + 0x20) = 0;
    }
  }
  return 0;
}

/* ---- FUNC 00057BC8 FUN_180057bc8 (13 bytes) ---- */

undefined8 FUN_180057bc8(void)

{
  return 0;
}

/* ---- FUNC 00057BE0 FUN_180057be0 (43 bytes) ---- */

undefined8 FUN_180057be0(longlong param_1,int param_2,undefined4 param_3)

{
  if ((-1 < param_2) && ((longlong)param_2 < *(longlong *)(param_1 + 0x108))) {
    *(undefined4 *)(*(longlong *)(*(longlong *)(param_1 + 0x100) + (longlong)param_2 * 8) + 0xc) =
         param_3;
    return 0;
  }
  return 0x80070057;
}

/* ---- FUNC 00057C10 FUN_180057c10 (205 bytes) ---- */

undefined8 FUN_180057c10(longlong param_1,int param_2,short param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  if (param_3 == 0) {
    lVar1 = *(longlong *)(param_1 + 0xe0);
    uVar2 = 0;
    uVar4 = uVar2;
    if (0 < lVar1) {
      while ((-1 < (longlong)uVar2 && ((longlong)uVar2 < lVar1))) {
        if (*(int *)(*(longlong *)(param_1 + 0xd8) + uVar2 * 4) == param_2) {
          FUN_180053ee0(param_1 + 0xd0,(longlong)(int)uVar4,1);
          return 0;
        }
        uVar3 = (int)uVar4 + 1;
        uVar2 = uVar2 + 1;
        uVar4 = (ulonglong)uVar3;
        if (lVar1 <= (int)uVar3) {
          return 0;
        }
      }
LAB_180057cd8:
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
  }
  else if (param_2 != 0) {
    lVar1 = *(longlong *)(param_1 + 0xe0);
    uVar2 = 0;
    uVar4 = uVar2;
    if (0 < lVar1) {
      do {
        if (((longlong)uVar2 < 0) || (lVar1 <= (longlong)uVar2)) goto LAB_180057cd8;
        if (*(int *)(*(longlong *)(param_1 + 0xd8) + uVar2 * 4) == param_2) {
          return 0;
        }
        uVar3 = (int)uVar4 + 1;
        uVar2 = uVar2 + 1;
        uVar4 = (ulonglong)uVar3;
      } while ((int)uVar3 < lVar1);
    }
    FUN_180054d70(param_1 + 0xd0,*(longlong *)(param_1 + 0xe0),param_2);
  }
  return 0;
}

/* ---- FUNC 00057CE0 FUN_180057ce0 (10 bytes) ---- */

undefined8 FUN_180057ce0(longlong param_1,undefined2 param_2)

{
  *(undefined2 *)(param_1 + 0x164) = param_2;
  return 0;
}

/* ---- FUNC 00057CF0 FUN_180057cf0 (32 bytes) ---- */

undefined8 FUN_180057cf0(longlong *param_1,int param_2,LPCWSTR param_3)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  LPSTR pCVar1;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar2;
  undefined8 uVar3;
  longlong lVar4;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res20 [8];
  
  if ((-1 < param_2) && (lVar4 = (longlong)param_2, lVar4 < param_1[0x21])) {
    pCVar1 = FUN_18005d360(param_3);
    if (lVar4 < param_1[0x21]) {
      this = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
              (param_1[0x20] + lVar4 * 8);
      pCVar2 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
               CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20,pCVar1);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(this,pCVar2);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20);
      operator_delete__(pCVar1);
      return 0;
    }
                    /* WARNING: Subroutine does not return */
    AfxThrowInvalidArgException();
  }
                    /* WARNING: Could not recover jumptable at 0x000180057d82. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (**(code **)(*param_1 + 0x2b8))(param_1,0x7d1);
  return uVar3;
}

/* ---- FUNC 00057D10 FUN_180057d10 (96 bytes) ---- */

undefined8 FUN_180057d10(LPCWSTR param_1)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  LPSTR pCVar1;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar2;
  longlong unaff_RBX;
  longlong unaff_RDI;
  
  pCVar1 = FUN_18005d360(param_1);
  if (unaff_RDI < *(longlong *)(unaff_RBX + 0x108)) {
    this = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
            (*(longlong *)(unaff_RBX + 0x100) + unaff_RDI * 8);
    pCVar2 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                       ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                        &stack0x00000048,pCVar1);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(this,pCVar2);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000048);
    operator_delete__(pCVar1);
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00057D70 FUN_180057d70 (25 bytes) ---- */

void FUN_180057d70(longlong *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180057d82. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x2b8))(param_1,0x7d1);
  return;
}

/* ---- FUNC 00057D89 AfxThrowInvalidArgException (5 bytes) ---- */

void __cdecl AfxThrowInvalidArgException(void)

{
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00057D90 FUN_180057d90 (52 bytes) ---- */

undefined8 FUN_180057d90(longlong *param_1,short param_2,undefined2 param_3)

{
  undefined8 uVar1;
  
  if ((-1 < param_2) && ((longlong)param_2 < param_1[0x21])) {
    *(undefined2 *)(*(longlong *)(param_1[0x20] + (longlong)param_2 * 8) + 0x14) = param_3;
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180057dbd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*param_1 + 0x2b8))(param_1,0x7d1);
  return uVar1;
}

/* ---- FUNC 00057DD0 FUN_180057dd0 (10 bytes) ---- */

undefined8 FUN_180057dd0(longlong param_1,undefined2 param_2)

{
  *(undefined2 *)(param_1 + 0x168) = param_2;
  return 0;
}

/* ---- FUNC 00057DE0 FUN_180057de0 (52 bytes) ---- */

undefined8 FUN_180057de0(longlong *param_1,short param_2,undefined2 param_3)

{
  undefined8 uVar1;
  
  if ((-1 < param_2) && ((longlong)param_2 < param_1[0x21])) {
    *(undefined2 *)(*(longlong *)(param_1[0x20] + (longlong)param_2 * 8) + 0x16) = param_3;
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180057e0d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*param_1 + 0x2b8))(param_1,0x7d1);
  return uVar1;
}

/* ---- FUNC 00057E20 FUN_180057e20 (12 bytes) ---- */

undefined8 FUN_180057e20(longlong param_1,short param_2)

{
  *(int *)(param_1 + 0x160) = (int)param_2;
  return 0;
}

/* ---- FUNC 00057E30 FUN_180057e30 (10 bytes) ---- */

undefined8 FUN_180057e30(longlong param_1,undefined2 param_2)

{
  *(undefined2 *)(param_1 + 0x166) = param_2;
  return 0;
}

/* ---- FUNC 00057E40 FUN_180057e40 (52 bytes) ---- */

undefined8 FUN_180057e40(longlong *param_1,short param_2,undefined2 param_3)

{
  undefined8 uVar1;
  
  if ((-1 < param_2) && ((longlong)param_2 < param_1[0x21])) {
    *(undefined2 *)(*(longlong *)(param_1[0x20] + (longlong)param_2 * 8) + 0x1a) = param_3;
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180057e6d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*param_1 + 0x2b8))(param_1,0x7d1);
  return uVar1;
}

/* ---- FUNC 00057E80 FUN_180057e80 (52 bytes) ---- */

undefined8 FUN_180057e80(longlong *param_1,short param_2,undefined2 param_3)

{
  undefined8 uVar1;
  
  if ((-1 < param_2) && ((longlong)param_2 < param_1[0x21])) {
    *(undefined2 *)(*(longlong *)(param_1[0x20] + (longlong)param_2 * 8) + 0x18) = param_3;
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180057ead. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*param_1 + 0x2b8))(param_1,0x7d1);
  return uVar1;
}

/* ---- FUNC 00057EC0 FUN_180057ec0 (44 bytes) ---- */

undefined8 FUN_180057ec0(longlong *param_1,int param_2)

{
  ulonglong uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  if (param_2 < 0) {
                    /* WARNING: Could not recover jumptable at 0x000180057ee5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(*param_1 + 0x2b8))(param_1,0x7d1);
    return uVar2;
  }
  uVar3 = 0;
  uVar1 = param_1[0x1c];
  uVar4 = uVar3;
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar4 < 0) || (param_1[0x1c] <= (longlong)uVar4))
      goto MFC140_DLL_AfxThrowInvalidArgException;
      FUN_180055d80(*(longlong *)(param_1[0x1b] + uVar4 * 8),param_2);
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  uVar1 = param_1[0x21];
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar3 < 0) || (param_1[0x21] <= (longlong)uVar3)) {
MFC140_DLL_AfxThrowInvalidArgException:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      FUN_180055d80(*(longlong *)(param_1[0x20] + uVar3 * 8),param_2);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  *(int *)(param_1 + 0x19) = param_2;
  return 0;
}

/* ---- FUNC 00057EEC FUN_180057eec (162 bytes) ---- */

undefined8 FUN_180057eec(longlong param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  int unaff_EBP;
  ulonglong uVar3;
  longlong unaff_RDI;
  
  uVar2 = 0;
  uVar1 = *(ulonglong *)(param_1 + 0xe0);
  uVar3 = uVar2;
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar3 < 0) || (*(longlong *)(unaff_RDI + 0xe0) <= (longlong)uVar3))
      goto MFC140_DLL_AfxThrowInvalidArgException;
      FUN_180055d80(*(longlong *)(*(longlong *)(unaff_RDI + 0xd8) + uVar3 * 8),unaff_EBP);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  uVar1 = *(ulonglong *)(unaff_RDI + 0x108);
  if (uVar1 != 0) {
    do {
      if (((longlong)uVar2 < 0) || (*(longlong *)(unaff_RDI + 0x108) <= (longlong)uVar2)) {
MFC140_DLL_AfxThrowInvalidArgException:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      FUN_180055d80(*(longlong *)(*(longlong *)(unaff_RDI + 0x100) + uVar2 * 8),unaff_EBP);
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar1);
  }
  *(int *)(unaff_RDI + 200) = unaff_EBP;
  return 0;
}

/* ---- FUNC 00057F8E AfxThrowInvalidArgException (5 bytes) ---- */

void __cdecl AfxThrowInvalidArgException(void)

{
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00057FA0 FUN_180057fa0 (33 bytes) ---- */

undefined8 FUN_180057fa0(longlong *param_1,int param_2)

{
  undefined8 uVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
  
  if (param_2 < 0) {
                    /* WARNING: Could not recover jumptable at 0x000180057fba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x2b8))(param_1,0x7d1);
    return uVar1;
  }
  uVar4 = param_1[0x21];
  uVar5 = (ulonglong)param_2;
  uVar3 = uVar4;
  if ((longlong)uVar5 < (longlong)uVar4) {
    for (; uVar5 < uVar4; uVar4 = uVar4 - 1) {
      uVar3 = uVar3 - 1;
      if (((longlong)uVar3 < 0) || (param_1[0x21] <= (longlong)uVar3)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      pCVar2 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                (param_1[0x20] + uVar3 * 8);
      if (pCVar2 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        FUN_180050580(pCVar2);
        FUN_180025ad0(pCVar2);
      }
      CPtrArray::RemoveAt((CPtrArray *)(param_1 + 0x1f),uVar3,1);
    }
  }
  else if (((longlong)uVar4 < (longlong)uVar5) && (uVar4 < uVar5)) {
    lVar6 = uVar5 - uVar4;
    do {
      pCVar2 = operator_new(0x40);
      if (pCVar2 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        pCVar2 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
      }
      else {
        pCVar2 = FUN_180050130(pCVar2);
      }
      FUN_180055d80((longlong)pCVar2,(int)param_1[0x19]);
      CPtrArray::SetAtGrow((CPtrArray *)(param_1 + 0x1f),param_1[0x21],pCVar2);
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
  }
  return 0;
}

/* ---- FUNC 00057FC1 FUN_180057fc1 (264 bytes) ---- */

undefined8 FUN_180057fc1(longlong param_1,int param_2)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  ulonglong uVar2;
  longlong unaff_RSI;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  
  uVar3 = *(ulonglong *)(param_1 + 0x108);
  uVar4 = (ulonglong)param_2;
  uVar2 = uVar3;
  if ((longlong)uVar4 < (longlong)uVar3) {
    for (; uVar4 < uVar3; uVar3 = uVar3 - 1) {
      uVar2 = uVar2 - 1;
      if (((longlong)uVar2 < 0) || (*(longlong *)(unaff_RSI + 0x108) <= (longlong)uVar2)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      pCVar1 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                (*(longlong *)(unaff_RSI + 0x100) + uVar2 * 8);
      if (pCVar1 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        FUN_180050580(pCVar1);
        FUN_180025ad0(pCVar1);
      }
      CPtrArray::RemoveAt((CPtrArray *)(unaff_RSI + 0xf8),uVar2,1);
    }
  }
  else if (((longlong)uVar3 < (longlong)uVar4) && (uVar3 < uVar4)) {
    lVar5 = uVar4 - uVar3;
    do {
      pCVar1 = operator_new(0x40);
      if (pCVar1 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        pCVar1 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
      }
      else {
        pCVar1 = FUN_180050130(pCVar1);
      }
      FUN_180055d80((longlong)pCVar1,*(int *)(unaff_RSI + 200));
      CPtrArray::SetAtGrow((CPtrArray *)(unaff_RSI + 0xf8),*(__int64 *)(unaff_RSI + 0x108),pCVar1);
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
  }
  return 0;
}

/* ---- FUNC 000580C9 AfxThrowInvalidArgException (5 bytes) ---- */

void __cdecl AfxThrowInvalidArgException(void)

{
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 000580D0 FUN_1800580d0 (33 bytes) ---- */

undefined8 FUN_1800580d0(longlong *param_1,int param_2)

{
  undefined8 uVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
  
  if (param_2 < 0) {
                    /* WARNING: Could not recover jumptable at 0x0001800580ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x2b8))(param_1,0x7d1);
    return uVar1;
  }
  uVar4 = param_1[0x1c];
  uVar5 = (ulonglong)param_2;
  uVar3 = uVar4;
  if ((longlong)uVar5 < (longlong)uVar4) {
    for (; uVar5 < uVar4; uVar4 = uVar4 - 1) {
      uVar3 = uVar3 - 1;
      if (((longlong)uVar3 < 0) || (param_1[0x1c] <= (longlong)uVar3)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      pCVar2 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                (param_1[0x1b] + uVar3 * 8);
      if (pCVar2 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        FUN_180050580(pCVar2);
        FUN_180025ad0(pCVar2);
      }
      CPtrArray::RemoveAt((CPtrArray *)(param_1 + 0x1a),uVar3,1);
    }
  }
  else if (((longlong)uVar4 < (longlong)uVar5) && (uVar4 < uVar5)) {
    lVar6 = uVar5 - uVar4;
    do {
      pCVar2 = operator_new(0x40);
      if (pCVar2 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        pCVar2 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
      }
      else {
        pCVar2 = FUN_180050130(pCVar2);
      }
      FUN_180055d80((longlong)pCVar2,(int)param_1[0x19]);
      CPtrArray::SetAtGrow((CPtrArray *)(param_1 + 0x1a),param_1[0x1c],pCVar2);
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
  }
  return 0;
}

/* ---- FUNC 000580F1 FUN_1800580f1 (264 bytes) ---- */

undefined8 FUN_1800580f1(longlong param_1,int param_2)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  ulonglong uVar2;
  longlong unaff_RSI;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  
  uVar3 = *(ulonglong *)(param_1 + 0xe0);
  uVar4 = (ulonglong)param_2;
  uVar2 = uVar3;
  if ((longlong)uVar4 < (longlong)uVar3) {
    for (; uVar4 < uVar3; uVar3 = uVar3 - 1) {
      uVar2 = uVar2 - 1;
      if (((longlong)uVar2 < 0) || (*(longlong *)(unaff_RSI + 0xe0) <= (longlong)uVar2)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      pCVar1 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                (*(longlong *)(unaff_RSI + 0xd8) + uVar2 * 8);
      if (pCVar1 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        FUN_180050580(pCVar1);
        FUN_180025ad0(pCVar1);
      }
      CPtrArray::RemoveAt((CPtrArray *)(unaff_RSI + 0xd0),uVar2,1);
    }
  }
  else if (((longlong)uVar3 < (longlong)uVar4) && (uVar3 < uVar4)) {
    lVar5 = uVar4 - uVar3;
    do {
      pCVar1 = operator_new(0x40);
      if (pCVar1 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        pCVar1 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
      }
      else {
        pCVar1 = FUN_180050130(pCVar1);
      }
      FUN_180055d80((longlong)pCVar1,*(int *)(unaff_RSI + 200));
      CPtrArray::SetAtGrow((CPtrArray *)(unaff_RSI + 0xd0),*(__int64 *)(unaff_RSI + 0xe0),pCVar1);
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
  }
  return 0;
}

/* ---- FUNC 000581F9 AfxThrowInvalidArgException (5 bytes) ---- */

void __cdecl AfxThrowInvalidArgException(void)

{
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00058200 FUN_180058200 (12 bytes) ---- */

undefined8 FUN_180058200(longlong param_1,short param_2)

{
  *(int *)(param_1 + 0x15c) = (int)param_2;
  return 0;
}

/* ---- FUNC 00058210 FUN_180058210 (9 bytes) ---- */

undefined8 FUN_180058210(longlong param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x158) = param_2;
  return 0;
}

/* ---- FUNC 00058220 FUN_180058220 (55 bytes) ---- */

undefined8 FUN_180058220(longlong param_1,wchar_t *param_2)

{
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res8 [32];
  
  pCVar1 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
           CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8,param_2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0xf8),
             pCVar1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
  return 0;
}

/* ---- FUNC 00058260 FUN_180058260 (12 bytes) ---- */

undefined8 FUN_180058260(longlong param_1,short param_2)

{
  *(int *)(param_1 + 0x14c) = (int)param_2;
  return 0;
}

/* ---- FUNC 00058270 FUN_180058270 (12 bytes) ---- */

undefined8 FUN_180058270(longlong param_1,short param_2)

{
  *(int *)(param_1 + 0x16c) = (int)param_2;
  return 0;
}

/* ---- FUNC 00058280 FUN_180058280 (12 bytes) ---- */

undefined8 FUN_180058280(longlong param_1,short param_2)

{
  *(int *)(param_1 + 0x154) = (int)param_2;
  return 0;
}

/* ---- FUNC 00058290 FUN_180058290 (12 bytes) ---- */

undefined8 FUN_180058290(longlong param_1,short param_2)

{
  *(int *)(param_1 + 0x170) = (int)param_2;
  return 0;
}

/* ---- FUNC 000582A0 FUN_1800582a0 (12 bytes) ---- */

undefined8 FUN_1800582a0(longlong param_1,short param_2)

{
  *(int *)(param_1 + 0x174) = (int)param_2;
  return 0;
}

/* ---- FUNC 000582B0 FUN_1800582b0 (12 bytes) ---- */

undefined8 FUN_1800582b0(longlong param_1,short param_2)

{
  *(int *)(param_1 + 0x148) = (int)param_2;
  return 0;
}

/* ---- FUNC 000582C0 FUN_1800582c0 (86 bytes) ---- */

undefined8 FUN_1800582c0(longlong param_1,LPCWSTR param_2)

{
  LPSTR pCVar1;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar2;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res8 [8];
  
  pCVar1 = FUN_18005d360(param_2);
  pCVar2 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
           CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8,pCVar1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x90),
             pCVar2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
  operator_delete__(pCVar1);
  return 0;
}

/* ---- FUNC 00058320 FUN_180058320 (219 bytes) ---- */

undefined8 FUN_180058320(longlong param_1,short *param_2,undefined4 param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  int iVar3;
  ulonglong uVar4;
  
  if (*param_2 == 2) {
    iVar3 = (int)param_2[4];
LAB_180058353:
    if (-1 < iVar3) {
      if ((longlong)iVar3 < *(longlong *)(*(longlong *)(param_1 + 0x90) + 0x108)) {
        if (-1 < iVar3) {
          lVar1 = *(longlong *)
                   (*(longlong *)(*(longlong *)(param_1 + 0x90) + 0x100) + (longlong)iVar3 * 8);
          if (lVar1 == 0) {
            return 0;
          }
          FUN_180056180(lVar1,param_3);
          return 0;
        }
        goto LAB_1800583f6;
      }
    }
  }
  else if (*param_2 == 3) {
    iVar3 = *(int *)(param_2 + 4);
    goto LAB_180058353;
  }
  uVar2 = *(ulonglong *)(*(longlong *)(param_1 + 0x90) + 0x108);
  uVar4 = (ulonglong)(*(int *)(*(longlong *)(param_1 + 0x90) + 0x15c) != 0);
  while( true ) {
    if (uVar2 <= uVar4) {
      return 0;
    }
    if (((longlong)uVar4 < 0) ||
       (*(longlong *)(*(longlong *)(param_1 + 0x90) + 0x108) <= (longlong)uVar4)) break;
    lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x90) + 0x100) + uVar4 * 8);
    if (lVar1 != 0) {
      FUN_180056180(lVar1,param_3);
    }
    uVar4 = uVar4 + 1;
  }
LAB_1800583f6:
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00058400 FUN_180058400 (50 bytes) ---- */

undefined8
FUN_180058400(longlong param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
             undefined2 param_5,undefined2 param_6)

{
  *(undefined2 *)(param_1 + 0x182) = param_5;
  *(undefined2 *)(param_1 + 0x184) = param_6;
  *(undefined2 *)(param_1 + 0x17c) = param_2;
  *(undefined2 *)(param_1 + 0x17e) = param_3;
  *(undefined2 *)(param_1 + 0x180) = param_4;
  return 0;
}

/* ---- FUNC 00058440 FUN_180058440 (101 bytes) ---- */

undefined8 FUN_180058440(longlong param_1,ushort param_2,longlong *param_3)

{
  int iVar1;
  void **ppvVar2;
  longlong *local_res8;
  
  iVar1 = CMapWordToPtr::Lookup((CMapWordToPtr *)(param_1 + 0x98),param_2,&local_res8);
  if ((iVar1 != 0) && (local_res8 != (longlong *)0x0)) {
    (**(code **)(*local_res8 + 0x10))();
  }
  ppvVar2 = CMapWordToPtr::operator[]((CMapWordToPtr *)(param_1 + 0x98),param_2);
  *ppvVar2 = param_3;
  (**(code **)(*param_3 + 8))(param_3);
  return 0;
}

/* ---- FUNC 000584B0 FUN_1800584b0 (102 bytes) ---- */

undefined8 FUN_1800584b0(longlong param_1,LPCWSTR param_2)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  LPSTR pCVar1;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar2;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res8 [8];
  
  pCVar1 = FUN_18005d360(param_2);
  if (0 < *(longlong *)(param_1 + 0xe0)) {
    this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
           **(undefined8 **)(param_1 + 0xd8);
    pCVar2 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8,pCVar1);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(this,pCVar2);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
  }
  operator_delete__(pCVar1);
  return 0;
}

/* ---- FUNC 00058520 FUN_180058520 (123 bytes) ---- */

undefined8
FUN_180058520(longlong *param_1,int param_2,int param_3,short param_4,undefined8 *param_5)

{
  undefined8 uVar1;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  if ((((-1 < param_2) && ((longlong)param_2 < param_1[0x1c])) && (-1 < param_3)) &&
     (param_3 < (int)param_1[0x19])) {
    local_28 = *param_5;
    uStack_20 = param_5[1];
    local_18 = param_5[2];
    FUN_180054dc0(*(longlong *)(param_1[0x1b] + (longlong)param_2 * 8),param_3,param_4,
                  (uint *)&local_28);
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180058594. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*param_1 + 0x2b8))(param_1,0x7d1);
  return uVar1;
}

/* ---- FUNC 000585A0 FUN_1800585a0 (128 bytes) ---- */

undefined8 FUN_1800585a0(longlong param_1,undefined4 param_2)

{
  ulonglong uVar1;
  longlong lVar2;
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
      lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x90) + 0xd8) + uVar3 * 8);
      if (lVar2 != 0) {
        FUN_180056180(lVar2,param_2);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return 0;
}

/* ---- FUNC 00058630 FUN_180058630 (278 bytes) ---- */

undefined8 FUN_180058630(longlong param_1,short *param_2,LPCWSTR param_3)

{
  LPSTR pCVar1;
  longlong lVar2;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar3;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar4;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res10 [8];
  
  if ((*param_2 == 2) || (*param_2 == 3)) {
    lVar2 = (longlong)param_2[4];
    if ((param_2[4] < 0) || (*(longlong *)(param_1 + 0xa8) < lVar2)) {
      return 0x80070057;
    }
    if (lVar2 == *(longlong *)(param_1 + 0xa8)) {
      pCVar1 = FUN_18005d360(param_3);
      pCVar3 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
               CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10,pCVar1);
      CStringArray::SetAtGrow((CStringArray *)(param_1 + 0x98),*(__int64 *)(param_1 + 0xa8),pCVar3);
      goto LAB_180058705;
    }
    pCVar1 = FUN_18005d360(param_3);
    if ((lVar2 < 0) || (*(longlong *)(param_1 + 0xa8) <= lVar2)) {
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
    pCVar3 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             (*(longlong *)(param_1 + 0xa0) + lVar2 * 8);
  }
  else {
    pCVar1 = FUN_18005d360(param_3);
    if (*(longlong *)(param_1 + 0xa8) < 1) {
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
    pCVar3 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)(param_1 + 0xa0);
  }
  pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
           CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10,pCVar1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(pCVar3,pCVar4);
LAB_180058705:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10);
  if (pCVar1 != (LPSTR)0x0) {
    operator_delete__(pCVar1);
  }
  return 0;
}

/* ---- FUNC 00058750 FUN_180058750 (123 bytes) ---- */

undefined8
FUN_180058750(longlong *param_1,int param_2,int param_3,short param_4,undefined8 *param_5)

{
  undefined8 uVar1;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  if ((((-1 < param_2) && ((longlong)param_2 < param_1[0x21])) && (-1 < param_3)) &&
     (param_3 < (int)param_1[0x19])) {
    local_28 = *param_5;
    uStack_20 = param_5[1];
    local_18 = param_5[2];
    FUN_180054dc0(*(longlong *)(param_1[0x20] + (longlong)param_2 * 8),param_3,param_4,
                  (uint *)&local_28);
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0001800587c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*param_1 + 0x2b8))(param_1,0x7d1);
  return uVar1;
}

/* ---- FUNC 000587D0 FUN_1800587d0 (55 bytes) ---- */

undefined8 FUN_1800587d0(longlong param_1,wchar_t *param_2)

{
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res8 [32];
  
  pCVar1 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
           CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8,param_2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0xc0),
             pCVar1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
  return 0;
}

/* ---- FUNC 00058810 FUN_180058810 (33 bytes) ---- */

undefined8 *
FUN_180058810(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 1) = 0;
  *param_1 = CImpIAdviseSink::vftable;
  param_1[2] = param_2;
  param_1[3] = param_3;
  *(undefined4 *)(param_1 + 4) = param_4;
  return param_1;
}

/* ---- FUNC 00058840 FUN_180058840 (11 bytes) ---- */

void FUN_180058840(undefined8 *param_1)

{
  *param_1 = CImpIAdviseSink::vftable;
  return;
}

/* ---- FUNC 00058850 FUN_180058850 (11 bytes) ---- */

void FUN_180058850(longlong param_1)

{
  *(undefined8 *)(param_1 + 0x10) = 0;
  *(undefined8 *)(param_1 + 0x18) = 0;
  return;
}

/* ---- FUNC 00058860 FUN_180058860 (29 bytes) ---- */

void FUN_180058860(longlong param_1)

{
  if ((*(LPUNKNOWN *)(param_1 + 0x10) != (LPUNKNOWN)0x0) && (*(int *)(param_1 + 0x20) == 0)) {
    FUN_180038690(*(LPUNKNOWN *)(param_1 + 0x10),1);
    return;
  }
  return;
}

/* ---- FUNC 00058880 FUN_180058880 (102 bytes) ---- */

void FUN_180058880(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x10) != 0) {
    if (*(int *)(param_1 + 0x20) == 0) {
      FUN_18003b500();
    }
    if (*(int *)(param_1 + 0x20) == 2) {
      FUN_18002bbd0(*(undefined8 *)(param_1 + 0x10));
    }
    if (*(int *)(param_1 + 0x20) == 3) {
      FUN_18002bb40(*(longlong *)(param_1 + 0x10));
    }
  }
  return;
}

/* ---- FUNC 000588F0 FUN_1800588f0 (65 bytes) ---- */

void FUN_1800588f0(longlong param_1,longlong *param_2)

{
  if (*(longlong *)(param_1 + 0x10) != 0) {
    if (*(int *)(param_1 + 0x20) == 0) {
      FUN_18003ca80(*(longlong *)(param_1 + 0x10),param_2);
    }
    if (*(int *)(param_1 + 0x20) == 2) {
      FUN_18002e8a0(*(longlong **)(param_1 + 0x10));
    }
  }
  return;
}

/* ---- FUNC 00058940 FUN_180058940 (99 bytes) ---- */

undefined8 FUN_180058940(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  
  if (((*param_2 != DAT_180066d48) || (param_2[1] != DAT_180066d50)) &&
     ((*param_2 != DAT_180066c58 || (param_2[1] != DAT_180066c60)))) {
    if ((undefined8 *)param_1[3] == (undefined8 *)0x0) {
      return 0x80004002;
    }
                    /* WARNING: Could not recover jumptable at 0x0001800589a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)**(undefined8 **)param_1[3])();
    return uVar1;
  }
  *param_3 = param_1;
  (**(code **)(*param_1 + 8))();
  return 0;
}

/* ---- FUNC 000589B0 FUN_1800589b0 (46 bytes) ---- */

int FUN_1800589b0(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 1) + -1;
  *(int *)(param_1 + 1) = iVar1;
  if (iVar1 == 0) {
    FUN_180058840(param_1);
    FUN_180025ad0(param_1);
    iVar1 = 0;
  }
  return iVar1;
}

/* ---- FUNC 000589E0 FUN_1800589e0 (79 bytes) ---- */

undefined8 *
FUN_1800589e0(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  UINT UVar1;
  
  *(undefined4 *)(param_1 + 1) = 0;
  *param_1 = CImpIDataObject::vftable;
  param_1[2] = param_2;
  param_1[3] = param_3;
  *(undefined4 *)(param_1 + 4) = param_4;
  UVar1 = RegisterClipboardFormatA("Link Source");
  *(UINT *)((longlong)param_1 + 0x24) = UVar1;
  UVar1 = RegisterClipboardFormatA("Link Source Descriptor");
  *(UINT *)(param_1 + 5) = UVar1;
  return param_1;
}

/* ---- FUNC 00058A30 FUN_180058a30 (11 bytes) ---- */

void FUN_180058a30(undefined8 *param_1)

{
  *param_1 = CImpIDataObject::vftable;
  return;
}

/* ---- FUNC 00058A40 FUN_180058a40 (14 bytes) ---- */

void FUN_180058a40(longlong param_1)

{
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
                    /* WARNING: Could not recover jumptable at 0x000180058a4a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(longlong **)(param_1 + 0x18) + 8))();
  return;
}

/* ---- FUNC 00058A50 FUN_180058a50 (257 bytes) ---- */

HRESULT FUN_180058a50(IDataObject *param_1,FORMATETC *param_2,DWORD param_3,IAdviseSink *param_4,
                     DWORD *param_5)

{
  bool bVar1;
  HRESULT HVar2;
  uint uVar3;
  IDataAdviseHolder *local_res8;
  
  bVar1 = false;
  if ((((param_2->cfFormat == 0) && (param_2->ptd == (DVTARGETDEVICE *)0x0)) &&
      (param_2->dwAspect == 0xffffffff)) &&
     ((bVar1 = false, param_2->lindex == -1 && (bVar1 = false, param_2->tymed == 0xffffffff)))) {
    bVar1 = true;
  }
  uVar3 = (uint)param_2->cfFormat;
  if ((uVar3 == *(uint *)((longlong)&param_1[4].lpVtbl + 4)) && (param_2->tymed == 4)) {
    bVar1 = true;
  }
  if ((uVar3 == *(uint *)&param_1[5].lpVtbl) && (param_2->tymed == 1)) {
    bVar1 = true;
  }
  if (uVar3 == 1) {
    if (param_2->tymed == 1) goto LAB_180058ace;
  }
  else if ((uVar3 == 3) && (param_2->tymed == 0x20)) goto LAB_180058ace;
  if (!bVar1) {
    return -0x7fffbffb;
  }
LAB_180058ace:
  if (*(int *)&param_1[4].lpVtbl != 0) {
    return -0x7fffbffb;
  }
  local_res8 = (IDataAdviseHolder *)param_1[2].lpVtbl[3].QueryGetData;
  if (local_res8 == (IDataAdviseHolder *)0x0) {
    HVar2 = FUN_180038b50((longlong)param_1[2].lpVtbl,&local_res8);
    if (HVar2 < 0) {
      return -0x7ff8fff2;
    }
    param_1[2].lpVtbl[3].QueryGetData = (_func_5559 *)local_res8;
  }
  HVar2 = (*local_res8->lpVtbl->Advise)(local_res8,param_1,param_2,param_3,param_4,param_5);
  return HVar2;
}

/* ---- FUNC 00058B60 FUN_180058b60 (35 bytes) ---- */

undefined8 FUN_180058b60(longlong param_1)

{
  longlong *plVar1;
  undefined8 uVar2;
  
  if ((*(int *)(param_1 + 0x20) == 0) &&
     (plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x10) + 0x148), plVar1 != (longlong *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x000180058b79. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(*plVar1 + 0x20))();
    return uVar2;
  }
  return 0x80004005;
}

/* ---- FUNC 00058B90 FUN_180058b90 (35 bytes) ---- */

undefined8 FUN_180058b90(longlong param_1)

{
  longlong *plVar1;
  undefined8 uVar2;
  
  if ((*(int *)(param_1 + 0x20) == 0) &&
     (plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x10) + 0x148), plVar1 != (longlong *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x000180058ba9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(*plVar1 + 0x28))();
    return uVar2;
  }
  return 0x80004005;
}

/* ---- FUNC 00058BC0 FUN_180058bc0 (160 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180058bc0(undefined8 param_1,DWORD param_2,LPENUMFORMATETC *param_3)

{
  int iVar1;
  undefined1 auStack_438 [32];
  IID local_418;
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_180077818 ^ (ulonglong)auStack_438;
  iVar1 = (**(code **)(*DAT_180079800 + 0x138))(DAT_180079800,&local_418);
  if (iVar1 != 0) {
    FUN_180002a20(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\IDATAOBJ.CPP",0x1ef);
    LogMessage(local_408,2,1);
  }
  OleRegEnumFormatEtc(&local_418,param_2,param_3);
  return;
}

/* ---- FUNC 00058C60 FUN_180058c60 (113 bytes) ---- */

ulonglong FUN_180058c60(longlong param_1,ushort *param_2,int *param_3)

{
  HRESULT HVar1;
  undefined4 extraout_var;
  ulonglong uVar2;
  uint uVar3;
  
  uVar3 = (uint)*param_2;
  if (uVar3 == 1) {
    if ((param_2[0xc] & 1) == 0) goto LAB_180058c71;
    if (*(int *)(param_1 + 0x20) == 0) {
      uVar2 = FUN_18003d030(*(longlong **)(param_1 + 0x10),param_3);
      return uVar2;
    }
  }
  else if (uVar3 != 3) goto LAB_180058c71;
  if (((param_2[0xc] & 0x20) != 0) && (*(int *)(param_1 + 0x20) == 0)) {
    uVar2 = FUN_18003cf70(*(longlong **)(param_1 + 0x10),param_3);
    return uVar2;
  }
LAB_180058c71:
  if (((((uint)*param_2 == *(uint *)(param_1 + 0x24)) && (*(int *)(param_2 + 0xc) == 4)) ||
      ((uVar3 == *(uint *)(param_1 + 0x28) && (*(int *)(param_2 + 0xc) == 1)))) &&
     (*(int *)(param_1 + 0x20) == 0)) {
    HVar1 = FUN_18003cb90(*(longlong **)(param_1 + 0x10),uVar3,param_3);
    return CONCAT44(extraout_var,HVar1);
  }
  return 0x80040064;
}

/* ---- FUNC 00058CE0 FUN_180058ce0 (209 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180058ce0(undefined8 param_1,ushort *param_2,undefined4 *param_3)

{
  UINT UVar1;
  int iVar2;
  undefined8 uVar3;
  undefined1 auStack_438 [32];
  IID local_418;
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_180077818 ^ (ulonglong)auStack_438;
  UVar1 = RegisterClipboardFormatA("Link Source");
  if ((UVar1 == *param_2) && ((param_2[0xc] & 8) != 0)) {
    *param_3 = 8;
    *(undefined8 *)(param_3 + 4) = 0;
    iVar2 = (**(code **)(*DAT_180079800 + 0x138))(DAT_180079800,&local_418);
    if (iVar2 != 0) {
      FUN_180002a20(local_408,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\Happ\\IDATAOBJ.CPP",0x160);
      LogMessage(local_408,2,1);
    }
    WriteClassStg(*(LPSTORAGE *)(param_3 + 2),&local_418);
    uVar3 = 0;
  }
  else {
    uVar3 = 0x80040064;
  }
  return uVar3;
}

/* ---- FUNC 00058DC0 FUN_180058dc0 (79 bytes) ---- */

ulonglong FUN_180058dc0(longlong param_1,ushort *param_2)

{
  ushort uVar1;
  uint uVar2;
  
  if ((param_2[8] & 1) != 0) {
    uVar1 = *param_2;
    uVar2 = 0;
    if (uVar1 == 1) {
      uVar2 = *(uint *)(param_2 + 0xc) & 1;
    }
    if (((uint)uVar1 == *(uint *)(param_1 + 0x24)) && (*(int *)(param_2 + 0xc) == 4)) {
      uVar2 = 1;
    }
    if (((uint)uVar1 == *(uint *)(param_1 + 0x28)) && (*(int *)(param_2 + 0xc) == 1)) {
      uVar2 = 1;
    }
    return (ulonglong)(uVar2 == 0);
  }
  return 0x80040064;
}

/* ---- FUNC 00058E10 FUN_180058e10 (14 bytes) ---- */

void FUN_180058e10(longlong param_1)

{
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
                    /* WARNING: Could not recover jumptable at 0x000180058e1a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(longlong **)(param_1 + 0x18) + 0x10))();
  return;
}

/* ---- FUNC 00058E20 FUN_180058e20 (33 bytes) ---- */

undefined8 *
FUN_180058e20(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 1) = 0;
  *param_1 = CImpIExternalConnection::vftable;
  param_1[2] = param_2;
  param_1[3] = param_3;
  *(undefined4 *)(param_1 + 4) = param_4;
  return param_1;
}

/* ---- FUNC 00058E50 FUN_180058e50 (11 bytes) ---- */

void FUN_180058e50(undefined8 *param_1)

{
  *param_1 = CImpIExternalConnection::vftable;
  return;
}

/* ---- FUNC 00058E60 FUN_180058e60 (38 bytes) ---- */

/* WARNING: Removing unreachable block (ram,0x000180018e5c) */
/* WARNING: Removing unreachable block (ram,0x000180018e60) */
/* WARNING: Removing unreachable block (ram,0x000180018e68) */
/* WARNING: Removing unreachable block (ram,0x000180018e6d) */
/* WARNING: Removing unreachable block (ram,0x000180018e8c) */
/* WARNING: Removing unreachable block (ram,0x000180018ea2) */

int FUN_180058e60(longlong param_1,ulonglong param_2)

{
  longlong *plVar1;
  int iVar2;
  
  if ((param_2 & 1) == 0) {
    return 0;
  }
  plVar1 = *(longlong **)(param_1 + 0x10);
  if (*(int *)(param_1 + 0x20) != 0) {
    iVar2 = *(int *)((longlong)plVar1 + 0x14) + 1;
    *(int *)((longlong)plVar1 + 0x14) = iVar2;
    (**(code **)(*plVar1 + 8))();
    return iVar2;
  }
  iVar2 = FUN_18003b0a0(plVar1,1);
  return iVar2;
}

/* ---- FUNC 00058E90 FUN_180058e90 (34 bytes) ---- */

/* WARNING: Removing unreachable block (ram,0x000180018e44) */

int FUN_180058e90(longlong param_1,ulonglong param_2,undefined8 param_3,int param_4)

{
  LPUNKNOWN This;
  int iVar1;
  
  if ((param_2 & 1) == 0) {
    return 0;
  }
  This = *(LPUNKNOWN *)(param_1 + 0x10);
  if (*(int *)(param_1 + 0x20) != 0) {
    iVar1 = *(int *)((longlong)&This[2].lpVtbl + 4);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = iVar1 + -1;
    *(int *)((longlong)&This[2].lpVtbl + 4) = iVar1;
    if ((iVar1 == 0) && (param_4 != 0)) {
      FUN_18000ef30((longlong *)This,1);
      FUN_18001a6a0(This);
      FUN_1800111f0((longlong)This);
    }
    (*This->lpVtbl->Release)(This);
    return iVar1;
  }
  iVar1 = FUN_18003b0a0((longlong *)This,0);
  return iVar1;
}

/* ---- FUNC 00058EC0 FUN_180058ec0 (33 bytes) ---- */

undefined8 *
FUN_180058ec0(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 1) = 0;
  *param_1 = CImpIOleItemContainer::vftable;
  param_1[2] = param_2;
  param_1[3] = param_3;
  *(undefined4 *)(param_1 + 4) = param_4;
  return param_1;
}

/* ---- FUNC 00058EF0 FUN_180058ef0 (11 bytes) ---- */

void FUN_180058ef0(undefined8 *param_1)

{
  *param_1 = CImpIOleItemContainer::vftable;
  return;
}

/* ---- FUNC 00058F00 FUN_180058f00 (2331 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Exceeded maximum restarts with more pending */

int FUN_180058f00(longlong param_1,wchar_t *param_2,int param_3,undefined8 param_4,IID *param_5,
                 void **param_6)

{
  wchar_t _C;
  code *pcVar1;
  void *pvVar2;
  _func_5156 *p_Var3;
  IUnknownVtbl *pIVar4;
  void **ppvObject;
  IID *pIVar5;
  WCHAR WVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  HRESULT HVar10;
  longlong *plVar11;
  longlong lVar12;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar13;
  undefined8 *puVar14;
  longlong lVar15;
  char *pcVar17;
  IUnknownVtbl *pIVar18;
  char *pcVar19;
  IUnknown *pIVar20;
  IUnknown *pIVar21;
  ulonglong uVar22;
  size_t _Count;
  _func_5158 *p_Var23;
  undefined1 *puVar24;
  undefined1 *puVar25;
  char *pcVar26;
  LPCWSTR _Str;
  IUnknownVtbl *pIVar27;
  char *pcVar28;
  bool bVar29;
  undefined8 uStack_120;
  undefined1 auStack_118 [32];
  undefined8 uStack_f8;
  int aiStack_f0 [2];
  undefined8 local_e8 [2];
  longlong *local_d8;
  uint local_d0 [2];
  undefined8 *local_c8;
  void **local_c0;
  IUnknown *local_b8;
  IID *local_b0;
  longlong local_a8;
  IUnknown *local_a0;
  VARIANTARG local_98;
  int local_80 [6];
  longlong local_68 [6];
  longlong lVar16;
  
  puVar24 = auStack_118;
  local_68[5] = DAT_180077818 ^ (ulonglong)&local_d8;
  local_a8 = param_1;
  local_b0 = param_5;
  local_c0 = param_6;
  pcVar26 = (char *)0x0;
  local_d8 = (longlong *)0x0;
  local_68[0] = 0;
  local_80[0] = -1;
  local_80[1] = -1;
  local_68[1] = 0;
  local_68[2] = 0;
  local_80[2] = -1;
  local_80[3] = -1;
  local_68[3] = 0;
  local_68[4] = 0;
  local_80[4] = 0xffffffff;
  local_c8 = (undefined8 *)0x0;
  *param_6 = (void *)0x0;
  iVar8 = -0x7fffbffb;
  if (param_3 == 3) {
    iVar8 = -0x7ffbfe1f;
    puVar24 = auStack_118;
    goto LAB_180059451;
  }
  if (*(int *)(param_1 + 0x20) == 1) {
    lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x20);
    puVar25 = auStack_118;
    if (lVar12 != 0) {
      uStack_120 = 0x180058fce;
      local_d8 = (longlong *)HAGetTree(lVar12,&local_c8);
      if (local_d8 != (longlong *)0x0) goto LAB_18005900a;
      puVar25 = auStack_118;
      if ((local_c8 != (undefined8 *)0x0) &&
         (puVar25 = auStack_118, (code *)*local_c8 != (code *)0x0)) {
        uStack_120 = 0x180058ff2;
        (*(code *)*local_c8)();
        iVar8 = -0x7fffbffb;
        puVar24 = auStack_118;
        goto LAB_180059451;
      }
    }
LAB_180059605:
    iVar8 = -0x7fffbffb;
    puVar24 = puVar25;
    goto LAB_180059451;
  }
  if (*(int *)(param_1 + 0x20) == 0) {
    local_d8 = *(longlong **)(*(longlong *)(param_1 + 0x10) + 0x48);
  }
LAB_18005900a:
  if (*(int *)(param_1 + 0x20) == 1) {
    uStack_120 = 0x18005902c;
    iVar7 = wcsncmp(param_2,L"OLE_LINK",8);
    if (iVar7 == 0) {
      uStack_120 = 0x180059041;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8,param_2)
      ;
      uStack_120 = 0x180059050;
      plVar11 = FUN_180011370(*(longlong *)(param_1 + 0x10),(undefined8 *)&local_d8);
      if (plVar11 == (longlong *)0x0) {
        lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0xa0);
        if (lVar12 != 0) {
          uStack_120 = 0x180059077;
          iVar8 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             (lVar12 + 0x10),(char *)local_d8);
          if (iVar8 == 0) {
            plVar11 = *(longlong **)(*(longlong *)(param_1 + 0x10) + 0xa0);
            uStack_120 = 0x180059090;
            (**(code **)(*plVar11 + 8))(plVar11);
            goto LAB_18005909f;
          }
        }
        uStack_120 = 0x18005909c;
        plVar11 = FUN_18000ed30(*(longlong **)(param_1 + 0x10));
      }
LAB_18005909f:
      uStack_120 = 0x1800590ad;
      iVar8 = (**(code **)*plVar11)(plVar11,param_5,param_6);
      uStack_120 = 0x1800590b8;
      (**(code **)(*plVar11 + 0x10))(plVar11);
      uStack_120 = 0x1800590c3;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8);
      puVar24 = auStack_118;
      goto LAB_180059451;
    }
    if (*(int *)(param_1 + 0x20) == 1) {
      uStack_120 = 0x1800590ec;
      iVar7 = wcsncmp(param_2,L"Embedding ",10);
      if (iVar7 != 0) {
        uStack_120 = 0x180059106;
        iVar7 = wcsncmp(param_2,L"PFS",3);
        if (iVar7 != 0) goto LAB_180059167;
      }
      uStack_120 = 0x180059117;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b0,param_2)
      ;
      local_d8 = (longlong *)0x0;
      uStack_120 = 0x180059134;
      iVar7 = (**(code **)(*DAT_180079800 + 0xe0))
                        (DAT_180079800,local_b0,
                         (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8)
      ;
      if (-1 < iVar7) {
        uStack_120 = 0x180059147;
        iVar8 = (**(code **)*local_d8)(local_d8,param_5,param_6);
        uStack_120 = 0x180059154;
        (**(code **)(*local_d8 + 0x10))();
      }
      uStack_120 = 0x18005915f;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b0);
      goto LAB_180059451;
    }
  }
LAB_180059167:
  if (*(int *)(param_1 + 0x20) == 0) {
    uStack_120 = 0x180059188;
    iVar7 = wcsncmp(param_2,L"@LABEL",6);
    if (iVar7 == 0) {
      puVar24 = auStack_118;
      pcVar19 = pcVar26;
      if (param_2 != (wchar_t *)0x0) {
        lVar12 = -1;
        do {
          lVar15 = lVar12;
          lVar12 = lVar15 + 1;
        } while (param_2[lVar12] != L'\0');
        iVar7 = (int)lVar15 + 2;
        puVar24 = auStack_118;
        if (iVar7 < 0x40000000) {
          lVar12 = (longlong)(int)lVar12 * 2;
          uVar22 = lVar12 + 0x11;
          if (uVar22 <= lVar12 + 2U) {
            uVar22 = 0xffffffffffffff0;
          }
          uStack_120 = 0x1800591de;
          lVar12 = -(uVar22 & 0xfffffffffffffff0);
          pcVar28 = (char *)((longlong)local_d0 + lVar12 + -8);
          puVar24 = auStack_118 + lVar12;
          if (pcVar28 != (char *)0x0) {
            *pcVar28 = '\0';
            *(undefined8 *)((longlong)local_e8 + lVar12 + 8) = 0;
            *(undefined8 *)((longlong)local_e8 + lVar12) = 0;
            *(int *)((longlong)aiStack_f0 + lVar12) = iVar7 * 2;
            *(char **)((longlong)&uStack_f8 + lVar12) = pcVar28;
            *(undefined8 *)(auStack_118 + lVar12 + -8) = 0x180059217;
            iVar7 = WideCharToMultiByte(0,0,param_2,-1,*(LPSTR *)((longlong)&uStack_f8 + lVar12),
                                        *(int *)((longlong)aiStack_f0 + lVar12),
                                        *(LPCSTR *)((longlong)local_e8 + lVar12),
                                        *(LPBOOL *)((longlong)local_e8 + lVar12 + 8));
            puVar24 = auStack_118 + lVar12;
            pcVar19 = pcVar28;
            if (iVar7 == 0) {
              puVar24 = auStack_118 + lVar12;
              pcVar19 = pcVar26;
            }
          }
        }
      }
      *(undefined8 *)(puVar24 + -8) = 0x18005922d;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_d0,pcVar19);
      *(undefined8 *)(puVar24 + -8) = 0x180059242;
      pCVar13 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_d0
                           ,(int)&local_c0);
      *(undefined8 *)(puVar24 + -8) = 0x180059250;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_d0,pCVar13);
      *(undefined8 *)(puVar24 + -8) = 0x18005925b;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_c0);
      *(undefined8 *)(puVar24 + -8) = 0x18005926a;
      iVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_d0,
                         'x',0);
      if (iVar7 != -1) {
        *(undefined8 *)(puVar24 + -8) = 0x180059286;
        puVar14 = (undefined8 *)
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             local_d0,(int)&local_c0);
        pcVar26 = (char *)*puVar14;
        *(undefined8 *)(puVar24 + -8) = 0x18005928f;
        iVar8 = atoi(pcVar26);
        *(undefined8 *)(puVar24 + -8) = 0x18005929b;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_c0);
        *(undefined8 *)(puVar24 + -8) = 0x1800592ad;
        puVar14 = (undefined8 *)
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             local_d0,(int)&local_c0);
        pcVar26 = (char *)*puVar14;
        *(undefined8 *)(puVar24 + -8) = 0x1800592b6;
        iVar7 = atoi(pcVar26);
        *(undefined8 *)(puVar24 + -8) = 0x1800592c2;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_c0);
        plVar11 = *(longlong **)(param_1 + 0x10);
        pcVar1 = *(code **)(*plVar11 + 200);
        *(undefined8 *)(puVar24 + -8) = 0x1800592d5;
        iVar9 = (*pcVar1)(plVar11,(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                  &local_d8);
        if (-1 < iVar9) {
          *(undefined8 *)(puVar24 + -8) = 0x1800592e3;
          VariantInit(&local_98);
          plVar11 = local_d8;
          lVar12 = *local_d8;
          *(void ***)(puVar24 + 0x20) = param_6;
          pcVar1 = *(code **)(lVar12 + 0x90);
          *(undefined8 *)(puVar24 + -8) = 0x1800592fe;
          iVar8 = (*pcVar1)(plVar11,iVar8,iVar7,&local_98);
          if (-1 < iVar8) {
            pcVar1 = *(code **)(*local_d8 + 0x10);
            *(undefined8 *)(puVar24 + -8) = 0x18005932a;
            (*pcVar1)();
            goto LAB_180059315;
          }
          pcVar1 = *(code **)(*local_d8 + 0x10);
          *(undefined8 *)(puVar24 + -8) = 0x18005930f;
          (*pcVar1)();
        }
        iVar8 = -0x7ffbfe1b;
      }
LAB_180059315:
      *(undefined8 *)(puVar24 + -8) = 0x18005931f;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_d0);
      goto LAB_180059451;
    }
  }
  puVar24 = auStack_118;
  if (param_2 != (wchar_t *)0x0) {
    lVar12 = -1;
    do {
      lVar12 = lVar12 + 1;
    } while (param_2[lVar12] != L'\0');
    iVar8 = (int)lVar12;
    puVar24 = auStack_118;
    if (iVar8 < 0x3fffffff) {
      uVar22 = (longlong)iVar8 * 2 + 0x11;
      if (uVar22 <= (longlong)iVar8 * 2 + 2U) {
        uVar22 = 0xffffffffffffff0;
      }
      uStack_120 = 0x180059377;
      lVar12 = -(uVar22 & 0xfffffffffffffff0);
      puVar25 = (undefined1 *)((longlong)local_d0 + lVar12 + -8);
      puVar24 = auStack_118 + lVar12;
      if (puVar25 != (undefined1 *)0x0) {
        *puVar25 = 0;
        *(undefined8 *)((longlong)local_e8 + lVar12 + 8) = 0;
        *(undefined8 *)((longlong)local_e8 + lVar12) = 0;
        *(int *)((longlong)aiStack_f0 + lVar12) = iVar8 * 2 + 2;
        *(undefined1 **)((longlong)&uStack_f8 + lVar12) = puVar25;
        *(undefined8 *)(auStack_118 + lVar12 + -8) = 0x1800593b4;
        WideCharToMultiByte(0,0,param_2,-1,*(LPSTR *)((longlong)&uStack_f8 + lVar12),
                            *(int *)((longlong)aiStack_f0 + lVar12),
                            *(LPCSTR *)((longlong)local_e8 + lVar12),
                            *(LPBOOL *)((longlong)local_e8 + lVar12 + 8));
        puVar24 = auStack_118 + lVar12;
      }
    }
  }
  if (*param_2 == L'&') {
    _C = param_2[1];
    *(undefined8 *)(puVar24 + -8) = 0x1800593c6;
    iVar8 = iswdigit(_C);
    if (iVar8 == 0) goto LAB_18005941e;
    if (*(int *)(param_1 + 0x20) == 2) {
      *(undefined8 *)(puVar24 + -8) = 0x1800593dc;
      iVar8 = _wtoi(param_2 + 1);
      if (0 < iVar8) {
        local_d8 = (longlong *)0x0;
        plVar11 = (longlong *)(*(longlong *)(param_1 + 0x10) + 0x18);
        pcVar1 = *(code **)(*plVar11 + 0x10);
        *(undefined8 *)(puVar24 + -8) = 0x1800593fa;
        iVar8 = (*pcVar1)(plVar11,iVar8,
                          (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8
                         );
        pIVar5 = local_b0;
        plVar11 = local_d8;
        if (-1 < iVar8) {
          pcVar1 = *(code **)*local_d8;
          *(undefined8 *)(puVar24 + -8) = 0x18005940e;
          iVar8 = (*pcVar1)(plVar11,pIVar5,param_6);
          pcVar1 = *(code **)(*local_d8 + 0x10);
          *(undefined8 *)(puVar24 + -8) = 0x18005941a;
          (*pcVar1)();
          goto LAB_180059451;
        }
      }
    }
  }
  else {
LAB_18005941e:
    plVar11 = local_d8;
    if (local_d8 != (longlong *)0x0) {
      *(undefined8 *)(puVar24 + -8) = 0x180059434;
      iVar8 = HAGetDimension(plVar11,&local_c8);
      if (iVar8 == -1) {
        if ((local_c8 != (undefined8 *)0x0) && (pcVar1 = (code *)*local_c8, pcVar1 != (code *)0x0))
        {
          *(undefined8 *)(puVar24 + -8) = 0x18005944c;
          (*pcVar1)();
        }
      }
      else if (iVar8 != 0) {
        local_d0[0] = 0;
        lVar12 = (longlong)iVar8;
        pcVar19 = pcVar26;
        _Str = param_2;
        pcVar28 = pcVar26;
        if (0 < iVar8) {
          do {
            WVar6 = L'#';
            if (*_Str == L'#') {
              _Str = _Str + 1;
              *(undefined8 *)(puVar24 + -8) = 0x1800595bb;
              iVar8 = _wtoi(_Str);
              puVar25 = puVar24;
              if (iVar8 < 0) goto LAB_180059605;
              local_80[(longlong)pcVar28] = iVar8;
              do {
                if (WVar6 == L'\0') break;
                WVar6 = *_Str;
                _Str = _Str + 1;
              } while (WVar6 != L'!');
            }
            else {
              *(undefined8 *)(puVar24 + -8) = 0x1800594ac;
              iVar8 = HAIsNamedDimension(plVar11,pcVar19,&local_c8);
              if (iVar8 == 0) goto LAB_18005944c;
              lVar15 = -1;
              do {
                lVar16 = lVar15;
                lVar15 = lVar16 + 1;
              } while (_Str[lVar15] != L'\0');
              iVar8 = (int)lVar16 + 2;
              puVar25 = puVar24;
              pcVar19 = pcVar26;
              if (iVar8 < 0x40000000) {
                lVar15 = (longlong)(int)lVar15 * 2;
                uVar22 = lVar15 + 0x11;
                if (uVar22 <= lVar15 + 2U) {
                  uVar22 = 0xffffffffffffff0;
                }
                *(undefined8 *)(puVar24 + -8) = 0x1800594ed;
                lVar15 = -(uVar22 & 0xfffffffffffffff0);
                pcVar17 = puVar24 + lVar15 + 0x40;
                puVar25 = puVar24 + lVar15;
                if (pcVar17 != (char *)0x0) {
                  *pcVar17 = '\0';
                  *(undefined8 *)(puVar24 + lVar15 + 0x38) = 0;
                  *(undefined8 *)(puVar24 + lVar15 + 0x30) = 0;
                  *(int *)(puVar24 + lVar15 + 0x28) = iVar8 * 2;
                  *(char **)(puVar24 + lVar15 + 0x20) = pcVar17;
                  *(undefined8 *)(puVar24 + lVar15 + -8) = 0x180059526;
                  iVar8 = WideCharToMultiByte(0,0,_Str,-1,*(LPSTR *)(puVar24 + lVar15 + 0x20),
                                              *(int *)(puVar24 + lVar15 + 0x28),
                                              *(LPCSTR *)(puVar24 + lVar15 + 0x30),
                                              *(LPBOOL *)(puVar24 + lVar15 + 0x38));
                  puVar25 = puVar24 + lVar15;
                  pcVar19 = pcVar17;
                  if (iVar8 == 0) {
                    puVar25 = puVar24 + lVar15;
                    pcVar19 = pcVar26;
                  }
                }
              }
              puVar24 = puVar25;
              *(undefined8 *)(puVar24 + -8) = 0x18005953e;
              pcVar17 = strchr(pcVar19,0x21);
              if (pcVar17 != (char *)0x0) {
                *pcVar17 = '\0';
              }
              lVar15 = -1;
              do {
                lVar16 = lVar15;
                lVar15 = lVar16 + 1;
              } while (pcVar19[lVar15] != '\0');
              *(undefined8 *)(puVar24 + -8) = 0x180059565;
              pcVar17 = malloc((longlong)((int)lVar16 + 2));
              local_68[(longlong)pcVar28] = (longlong)pcVar17;
              if (pcVar17 == (char *)0x0) {
                iVar8 = -0x7ff8fff2;
                goto LAB_180059451;
              }
              local_80[(longlong)pcVar28] = -1;
              _Count = (size_t)(int)lVar15;
              *(undefined8 *)(puVar24 + -8) = 0x18005958e;
              strncpy(pcVar17,pcVar19,_Count);
              *(undefined1 *)(_Count + local_68[(longlong)pcVar28]) = 0;
              _Str = _Str + _Count;
              plVar11 = local_d8;
              if (*_Str == L'!') {
                _Str = _Str + 1;
              }
            }
            local_d0[0] = local_d0[0] + 1;
            pcVar19 = (char *)(ulonglong)local_d0[0];
            pcVar28 = pcVar28 + 1;
            param_1 = local_a8;
          } while ((longlong)pcVar28 < lVar12);
        }
        *(undefined8 *)(puVar24 + -8) = 0x180059626;
        pIVar18 = (IUnknownVtbl *)HAGetElement(plVar11,local_80,local_68,&local_c8);
        if (pIVar18 != (IUnknownVtbl *)0x0) {
          if (0 < lVar12) {
            do {
              pvVar2 = (void *)local_68[(longlong)pcVar26];
              if (pvVar2 != (void *)0x0) {
                *(undefined8 *)(puVar24 + -8) = 0x180059685;
                free(pvVar2);
              }
              pcVar26 = pcVar26 + 1;
            } while ((longlong)pcVar26 < lVar12);
          }
          *(undefined8 *)(puVar24 + -8) = 0x18005969f;
          WaitForSingleObject(DAT_1800797e8,100);
          *(undefined8 *)(puVar24 + -8) = 0x1800596ac;
          puVar14 = (undefined8 *)HAGetBptr(pIVar18,&local_a0);
          local_c8 = puVar14;
          if (puVar14 == (undefined8 *)0x0) {
            if (local_a0 == (IUnknown *)0x0) {
              *(undefined8 *)(puVar24 + -8) = 0x18005975c;
              ReleaseSemaphore(DAT_1800797e8,1,(LPLONG)0x0);
              pIVar4 = *(IUnknownVtbl **)(param_1 + 0x10);
              bVar29 = *(int *)(param_1 + 0x20) != 1;
              if (bVar29) {
                p_Var23 = pIVar4->Release;
                pIVar27 = (IUnknownVtbl *)pIVar4[3].AddRef;
              }
              else {
                p_Var23 = pIVar4[1].Release;
                pIVar27 = pIVar4;
              }
              *(_func_5158 **)(puVar24 + 0x28) = p_Var23;
              *(uint *)(puVar24 + 0x20) = (uint)!bVar29;
              *(undefined8 *)(puVar24 + -8) = 0x180059790;
              FUN_1800387d0(pIVar18,(longlong *)&local_b8,pIVar27,pIVar4,*(int *)(puVar24 + 0x20),
                            *(IUnknownVtbl **)(puVar24 + 0x28));
              if ((local_b8 == (IUnknown *)0x0) &&
                 (DAT_1800797d4 = DAT_1800797d4 + 1, p_Var23 != (_func_5158 *)0x0)) {
                *(undefined8 *)(puVar24 + -8) = 0x1800597a6;
                (*p_Var23)((IUnknown *)0x0);
              }
              pIVar5 = local_b0;
              pIVar20 = local_b8;
              ppvObject = local_c0;
              p_Var3 = local_b8->lpVtbl->QueryInterface;
              *(undefined8 *)(puVar24 + -8) = 0x1800597b7;
              HVar10 = (*p_Var3)(pIVar20,pIVar5,ppvObject);
              pIVar21 = local_b8;
              DAT_1800797d4 = DAT_1800797d4 + 1;
              if (HVar10 < 0) {
                if (local_b8 != (IUnknown *)0x0) {
                  *(undefined8 *)(puVar24 + -8) = 0x1800597d2;
                  FUN_180037ee0(pIVar21);
                  *(undefined8 *)(puVar24 + -8) = 0x1800597df;
                  FUN_180025ad0(pIVar21);
                  pIVar20 = pIVar21;
                }
                if (p_Var23 != (_func_5158 *)0x0) {
                  *(undefined8 *)(puVar24 + -8) = 0x1800597e6;
                  (*p_Var23)(pIVar20);
                }
              }
              if (*(int *)(param_1 + 0x20) == 1) {
                plVar11 = *(longlong **)(*(longlong *)(param_1 + 0x10) + 0x118);
              }
              else {
                plVar11 = *(longlong **)(*(longlong *)(param_1 + 0x10) + 0xe8);
              }
              if (plVar11 != (longlong *)0x0) {
                *(undefined8 *)(puVar24 + -8) = 0x180059814;
                FUN_180038480((longlong)local_b8,plVar11,param_2);
              }
              iVar8 = 0;
            }
            else {
              local_b8 = local_a0;
              if (*(int *)(param_1 + 0x20) == 1) {
                plVar11 = *(longlong **)(*(longlong *)(param_1 + 0x10) + 0x118);
              }
              else {
                plVar11 = *(longlong **)(*(longlong *)(param_1 + 0x10) + 0xe8);
              }
              if (plVar11 != (longlong *)0x0) {
                *(undefined8 *)(puVar24 + -8) = 0x180059717;
                FUN_180038480((longlong)local_a0,plVar11,param_2);
              }
              pIVar5 = local_b0;
              pIVar20 = local_b8;
              p_Var3 = local_b8->lpVtbl->QueryInterface;
              *(undefined8 *)(puVar24 + -8) = 0x180059728;
              iVar8 = (*p_Var3)(pIVar20,pIVar5);
              *(undefined8 *)(puVar24 + -8) = 0x18005973e;
              ReleaseSemaphore(DAT_1800797e8,1,(LPLONG)0x0);
            }
          }
          else {
            pcVar1 = (code *)*puVar14;
            if (pcVar1 != (code *)0x0) {
              *(undefined8 *)(puVar24 + -8) = 0x1800596c2;
              (*pcVar1)(puVar14);
            }
            *(undefined8 *)(puVar24 + -8) = 0x1800596d6;
            ReleaseSemaphore(DAT_1800797e8,1,(LPLONG)0x0);
            iVar8 = -0x7fffbffb;
          }
          goto LAB_180059451;
        }
        if ((local_c8 != (undefined8 *)0x0) && (pcVar1 = (code *)*local_c8, pcVar1 != (code *)0x0))
        {
          *(undefined8 *)(puVar24 + -8) = 0x180059641;
          (*pcVar1)();
        }
        if (0 < lVar12) {
          do {
            pvVar2 = (void *)local_68[(longlong)pcVar26];
            if (pvVar2 != (void *)0x0) {
              *(undefined8 *)(puVar24 + -8) = 0x180059660;
              free(pvVar2);
            }
            pcVar26 = pcVar26 + 1;
          } while ((longlong)pcVar26 < lVar12);
        }
      }
    }
  }
LAB_18005944c:
  iVar8 = -0x7ffbfe1b;
LAB_180059451:
  *(undefined8 *)(puVar24 + -8) = 0x180059460;
  return iVar8;
}

/* ---- FUNC 00059820 FUN_180059820 (18 bytes) ---- */

undefined8 FUN_180059820(void)

{
  undefined8 *in_stack_00000028;
  
  *in_stack_00000028 = 0;
  return 0x800401ed;
}

/* ---- FUNC 00059840 FUN_180059840 (90 bytes) ---- */

undefined8 FUN_180059840(longlong param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  iVar1 = *(int *)(param_1 + 0x20);
  iVar2 = 0;
  if (iVar1 == 1) {
    iVar2 = FUN_180018e30(*(IUnknown **)(param_1 + 0x10),param_2,1);
  }
  else if (iVar1 == 0) {
    iVar2 = FUN_18003b0a0(*(longlong **)(param_1 + 0x10),param_2);
  }
  else if (iVar1 == 2) {
    iVar2 = FUN_18002bb00(*(longlong *)(param_1 + 0x10),param_2,1);
  }
  uVar3 = 0x80004005;
  if (iVar2 != 0) {
    uVar3 = 0;
  }
  return uVar3;
}

/* ---- FUNC 000598A0 FUN_1800598a0 (1020 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */

HRESULT FUN_1800598a0(longlong param_1,undefined8 param_2,short *param_3,uint *param_4,
                     LPMONIKER *param_5)

{
  char *pcVar1;
  LPCOLESTR pOVar2;
  short sVar3;
  wchar_t wVar4;
  wchar_t *pwVar5;
  LPMONIKER *ppmk;
  uint uVar6;
  int iVar7;
  HRESULT HVar8;
  longlong lVar9;
  longlong lVar10;
  ulonglong uVar11;
  wchar_t *pwVar12;
  undefined1 *puVar13;
  uint uVar14;
  uint uVar15;
  LPCOLESTR pOVar16;
  LPCOLESTR pOVar17;
  CHAR *pCVar18;
  bool bVar19;
  undefined8 uStack_1a0;
  undefined1 auStack_198 [32];
  undefined8 uStack_178;
  int aiStack_170 [2];
  uint *local_168;
  LPMONIKER *local_160;
  undefined8 *local_158 [2];
  CHAR local_148;
  char local_147 [255];
  ulonglong local_48;
  
  puVar13 = auStack_198;
  local_48 = DAT_180077818 ^ (ulonglong)&local_168;
  pOVar16 = (LPCOLESTR)0x0;
  local_168 = param_4;
  local_158[0] = (undefined8 *)0x0;
  pCVar18 = &local_148;
  local_160 = param_5;
  pwVar12 = param_3 + 1;
  uVar14 = 1;
  *param_5 = (LPMONIKER)0x0;
  uVar15 = 0;
  *param_4 = 0;
  sVar3 = *param_3;
  uVar6 = uVar14;
  if (*(int *)(param_1 + 0x20) == 1) {
    lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x20);
    if (lVar9 != 0) {
      uStack_1a0 = 0x180059926;
      lVar9 = HAGetTree(lVar9,local_158);
      bVar19 = lVar9 == 0;
LAB_180059950:
      if (!bVar19) goto LAB_180059977;
      if ((local_158[0] != (undefined8 *)0x0) && ((code *)*local_158[0] != (code *)0x0)) {
        uStack_1a0 = 0x18005996d;
        (*(code *)*local_158[0])();
        HVar8 = -0x7ffbfe1b;
        puVar13 = auStack_198;
        goto LAB_180059c73;
      }
    }
  }
  else {
    if (*(int *)(param_1 + 0x20) != 0) {
LAB_180059977:
      if (sVar3 == 0x5c) {
        if (*(int *)(param_1 + 0x20) == 1) {
          uStack_1a0 = 0x18005999f;
          iVar7 = wcsncmp(pwVar12,L"Embedding ",10);
          if (iVar7 == 0) {
            wVar4 = *pwVar12;
            pwVar5 = param_3 + 2;
            while ((wVar4 != L'\0' && (wVar4 != L'!'))) {
              uVar14 = uVar14 + 1;
              wVar4 = *pwVar5;
              pwVar5 = pwVar5 + 1;
            }
            *local_168 = uVar14;
            if (1 < uVar14) {
              pwVar5[-1] = L'\0';
              uStack_1a0 = 0x1800599ef;
              HVar8 = CreateItemMoniker(L"\\",pwVar12,local_160);
              pwVar5[-1] = wVar4;
              puVar13 = auStack_198;
              goto LAB_180059c73;
            }
          }
        }
      }
      else if (sVar3 == 0x21) {
        if (*(int *)(param_1 + 0x20) == 1) {
          uStack_1a0 = 0x180059a24;
          iVar7 = wcsncmp(pwVar12,L"PFS",3);
          if (iVar7 == 0) {
            wVar4 = *pwVar12;
            pwVar5 = param_3 + 2;
            while ((wVar4 != L'\0' && (wVar4 != L'!'))) {
              uVar14 = uVar14 + 1;
              wVar4 = *pwVar5;
              pwVar5 = pwVar5 + 1;
            }
            *local_168 = uVar14;
            if (1 < uVar14) {
              pwVar5[-1] = L'\0';
              uStack_1a0 = 0x180059a70;
              HVar8 = CreateItemMoniker(L"\\",pwVar12,local_160);
              pwVar5[-1] = wVar4;
              puVar13 = auStack_198;
              goto LAB_180059c73;
            }
            goto LAB_180059c6e;
          }
          if (*(int *)(param_1 + 0x20) == 1) {
            uStack_1a0 = 0x180059a95;
            iVar7 = wcsncmp(pwVar12,L"OLE_LINK",8);
            if (iVar7 == 0) {
              wVar4 = *pwVar12;
              pwVar5 = param_3 + 2;
              while ((wVar4 != L'\0' && (wVar4 != L'!'))) {
                uVar14 = uVar14 + 1;
                wVar4 = *pwVar5;
                pwVar5 = pwVar5 + 1;
              }
              *local_168 = uVar14;
              if (1 < uVar14) {
                pwVar5[-1] = L'\0';
                uStack_1a0 = 0x180059ae1;
                HVar8 = CreateItemMoniker(L"!",pwVar12,local_160);
                pwVar5[-1] = wVar4;
                goto LAB_180059c73;
              }
              goto LAB_180059c6e;
            }
          }
        }
        wVar4 = *pwVar12;
        pwVar12 = param_3 + 2;
        pOVar17 = pOVar16;
        if ((*(int *)(param_1 + 0x20) == 2) && (wVar4 == L'&')) {
          uStack_1a0 = 0x180059b0f;
          iVar7 = iswdigit(*pwVar12);
          if (iVar7 == 0) goto joined_r0x000180059c03;
          local_148 = '&';
          puVar13 = local_147;
          wVar4 = *pwVar12;
          uVar14 = 2;
          pwVar12 = param_3 + 3;
          uStack_1a0 = 0x180059b34;
          iVar7 = iswdigit(wVar4);
          while (iVar7 != 0) {
            *puVar13 = (char)wVar4;
            puVar13 = puVar13 + 1;
            wVar4 = *pwVar12;
            pwVar12 = pwVar12 + 1;
            uVar14 = uVar14 + 1;
            uStack_1a0 = 0x180059b59;
            iVar7 = iswdigit(wVar4);
          }
          *puVar13 = 0;
          *local_168 = uVar14;
          lVar9 = -1;
          do {
            lVar10 = lVar9 + 1;
            pcVar1 = local_147 + lVar9;
            lVar9 = lVar10;
          } while (*pcVar1 != '\0');
        }
        else {
joined_r0x000180059c03:
          while (wVar4 != L'\0') {
            uVar15 = (uint)pOVar17 + 1;
            if (wVar4 != L'!') {
              uVar15 = (uint)pOVar17;
            }
            if (uVar15 == uVar6) break;
            *pCVar18 = (CHAR)wVar4;
            uVar14 = uVar14 + 1;
            pCVar18 = pCVar18 + 1;
            wVar4 = *pwVar12;
            pwVar12 = pwVar12 + 1;
            pOVar17 = (LPCOLESTR)(ulonglong)uVar15;
          }
          *pCVar18 = '\0';
          *local_168 = uVar14;
          if ((int)uVar15 < (int)(uVar6 - 1)) goto LAB_180059c47;
          if (uVar14 < 2) goto LAB_180059c6e;
          lVar9 = -1;
          do {
            lVar10 = lVar9 + 1;
            pcVar1 = local_147 + lVar9;
            lVar9 = lVar10;
          } while (*pcVar1 != '\0');
        }
        iVar7 = (int)lVar10 + 1;
        puVar13 = auStack_198;
        pOVar17 = pOVar16;
        if (iVar7 < 0x40000000) {
          lVar9 = (longlong)(int)lVar10 * 2;
          uVar11 = lVar9 + 0x11;
          if (uVar11 <= lVar9 + 2U) {
            uVar11 = 0xffffffffffffff0;
          }
          uStack_1a0 = 0x180059baf;
          lVar9 = -(uVar11 & 0xfffffffffffffff0);
          pOVar2 = (LPCOLESTR)((longlong)&local_168 + lVar9);
          puVar13 = auStack_198 + lVar9;
          if (pOVar2 != (LPCOLESTR)0x0) {
            *(int *)((longlong)aiStack_170 + lVar9) = iVar7;
            *pOVar2 = L'\0';
            *(LPCOLESTR *)((longlong)&uStack_178 + lVar9) = pOVar2;
            *(undefined8 *)(auStack_198 + lVar9 + -8) = 0x180059bdd;
            iVar7 = MultiByteToWideChar(0,0,&local_148,-1,*(LPWSTR *)((longlong)&uStack_178 + lVar9)
                                        ,*(int *)((longlong)aiStack_170 + lVar9));
            puVar13 = auStack_198 + lVar9;
            pOVar17 = pOVar2;
            if (iVar7 == 0) {
              puVar13 = auStack_198 + lVar9;
              pOVar17 = pOVar16;
            }
          }
        }
        ppmk = local_160;
        *(undefined8 *)(puVar13 + -8) = 0x180059bfa;
        HVar8 = CreateItemMoniker(L"!",pOVar17,ppmk);
        goto LAB_180059c73;
      }
LAB_180059c6e:
      HVar8 = -0x7ffbfe1c;
      puVar13 = auStack_198;
      goto LAB_180059c73;
    }
    lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x48);
    if (lVar9 != 0) {
      uStack_1a0 = 0x18005994a;
      uVar6 = HAGetDimension(lVar9,local_158);
      bVar19 = uVar6 == 0xffffffff;
      goto LAB_180059950;
    }
  }
LAB_180059c47:
  HVar8 = -0x7ffbfe1b;
  puVar13 = auStack_198;
LAB_180059c73:
  *(undefined8 *)(puVar13 + -8) = 0x180059c82;
  return HVar8;
}

/* ---- FUNC 00059CA0 FUN_180059ca0 (33 bytes) ---- */

undefined8 *
FUN_180059ca0(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 1) = 0;
  *param_1 = CImpIOleObject::vftable;
  param_1[2] = param_2;
  param_1[3] = param_3;
  *(undefined4 *)(param_1 + 4) = param_4;
  return param_1;
}

/* ---- FUNC 00059CD0 FUN_180059cd0 (11 bytes) ---- */

void FUN_180059cd0(undefined8 *param_1)

{
  *param_1 = CImpIOleObject::vftable;
  return;
}

/* ---- FUNC 00059CE0 FUN_180059ce0 (139 bytes) ---- */

void FUN_180059ce0(longlong param_1,IAdviseSink *param_2,DWORD *param_3)

{
  HRESULT HVar1;
  IOleAdviseHolder *local_res8;
  
  if (*(int *)(param_1 + 0x20) == 0) {
    local_res8 = *(IOleAdviseHolder **)(*(longlong *)(param_1 + 0x10) + 0x1c0);
  }
  else {
    local_res8 = *(IOleAdviseHolder **)(*(longlong *)(param_1 + 0x10) + 0x180);
  }
  if (local_res8 == (IOleAdviseHolder *)0x0) {
    HVar1 = CreateOleAdviseHolder(&local_res8);
    if (HVar1 < 0) {
      return;
    }
    if (*(int *)(param_1 + 0x20) == 0) {
      *(IOleAdviseHolder **)(*(longlong *)(param_1 + 0x10) + 0x1c0) = local_res8;
    }
    else {
      *(IOleAdviseHolder **)(*(longlong *)(param_1 + 0x10) + 0x180) = local_res8;
    }
  }
  (*local_res8->lpVtbl->Advise)(local_res8,param_2,param_3);
  return;
}

/* ---- FUNC 00059D70 FUN_180059d70 (65 bytes) ---- */

undefined8 FUN_180059d70(longlong param_1,int param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  if (*(int *)(param_1 + 0x20) != 0) {
    uVar1 = FUN_18000ef30((longlong *)*(LPUNKNOWN *)(param_1 + 0x10),param_2);
    uVar2 = 0x80004005;
    if ((int)uVar1 != 0) {
      uVar2 = 0;
    }
    return uVar2;
  }
  uVar1 = FUN_180038690(*(LPUNKNOWN *)(param_1 + 0x10),param_2);
  uVar2 = 0x80004005;
  if ((int)uVar1 != 0) {
    uVar2 = 0;
  }
  return uVar2;
}

/* ---- FUNC 00059DC0 FUN_180059dc0 (63 bytes) ---- */

undefined8 FUN_180059dc0(longlong param_1,int param_2)

{
  if (param_2 == -3) {
    if (*(int *)(param_1 + 0x20) != 0) {
      FUN_180037570();
    }
  }
  else {
    if (1 < param_2 + 1U) {
      return 0x40180;
    }
    if (*(int *)(param_1 + 0x20) != 0) {
      FUN_180037380();
      return 0;
    }
  }
  return 0;
}

/* ---- FUNC 00059E00 FUN_180059e00 (44 bytes) ---- */

undefined8 FUN_180059e00(longlong param_1)

{
  undefined8 uVar1;
  longlong *plVar2;
  
  if (*(int *)(param_1 + 0x20) == 0) {
    plVar2 = *(longlong **)(*(longlong *)(param_1 + 0x10) + 0x1c0);
  }
  else {
    plVar2 = *(longlong **)(*(longlong *)(param_1 + 0x10) + 0x180);
  }
  if (plVar2 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000180059e22. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*plVar2 + 0x28))();
    return uVar1;
  }
  return 0x80004005;
}

/* ---- FUNC 00059E30 FUN_180059e30 (82 bytes) ---- */

undefined8 FUN_180059e30(longlong param_1,undefined8 *param_2)

{
  if (*(int *)(param_1 + 0x20) != 0) {
    *param_2 = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x150);
    (**(code **)(**(longlong **)(*(longlong *)(param_1 + 0x10) + 0x150) + 8))();
    return 0;
  }
  *param_2 = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x1b8);
  (**(code **)(**(longlong **)(*(longlong *)(param_1 + 0x10) + 0x1b8) + 8))();
  return 0;
}

/* ---- FUNC 00059E90 FUN_180059e90 (36 bytes) ---- */

undefined8 FUN_180059e90(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  
  if (*(int *)(param_1 + 0x20) != 0) {
    return 0x80004001;
  }
  lVar1 = *(longlong *)(param_1 + 0x10) + 0x118;
  *param_3 = lVar1;
  uVar2 = 0x80004005;
  if (lVar1 != 0) {
    uVar2 = 0;
  }
  return uVar2;
}

/* ---- FUNC 00059EC0 FUN_180059ec0 (135 bytes) ---- */

undefined8 FUN_180059ec0(longlong param_1,undefined8 param_2,int param_3,undefined8 *param_4)

{
  longlong *plVar1;
  
  if (param_3 == 1) {
    if (*(int *)(param_1 + 0x20) == 0) {
      plVar1 = *(longlong **)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x50) + 0x118);
    }
    else {
      plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x10) + 0x118);
    }
  }
  else {
    if ((param_3 != 2) && (param_3 != 3)) {
      return 0x80004005;
    }
    if (*(int *)(param_1 + 0x20) == 0) {
      plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x10) + 0xe8);
    }
    else {
      plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x10) + 0x118);
    }
  }
  if (plVar1 == (longlong *)0x0) {
    return 0x80004005;
  }
  (**(code **)(*plVar1 + 8))(plVar1);
  *param_4 = plVar1;
  return 0;
}

/* ---- FUNC 00059F50 FUN_180059f50 (144 bytes) ---- */

undefined8 FUN_180059f50(longlong param_1,undefined8 param_2)

{
  longlong *plVar1;
  
  if (*(int *)(param_1 + 0x20) != 0) {
    plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x10) + 0x150);
    if (plVar1 != (longlong *)0x0) {
      (**(code **)(*plVar1 + 0x10))();
    }
    *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x150) = param_2;
    (**(code **)(**(longlong **)(*(longlong *)(param_1 + 0x10) + 0x150) + 8))();
    return 0;
  }
  plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x10) + 0x1b8);
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x10))();
  }
  *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x1b8) = param_2;
  (**(code **)(**(longlong **)(*(longlong *)(param_1 + 0x10) + 0x1b8) + 8))();
  return 0;
}

/* ---- FUNC 00059FE0 FUN_180059fe0 (44 bytes) ---- */

undefined8 FUN_180059fe0(longlong param_1)

{
  undefined8 uVar1;
  longlong *plVar2;
  
  if (*(int *)(param_1 + 0x20) == 0) {
    plVar2 = *(longlong **)(*(longlong *)(param_1 + 0x10) + 0x1c0);
  }
  else {
    plVar2 = *(longlong **)(*(longlong *)(param_1 + 0x10) + 0x180);
  }
  if (plVar2 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00018005a002. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*plVar2 + 0x20))();
    return uVar1;
  }
  return 0x80004005;
}

/* ---- FUNC 0005A010 FUN_18005a010 (29 bytes) ---- */

undefined8 * FUN_18005a010(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  *(undefined4 *)(param_1 + 1) = 0;
  *param_1 = CImpIPersistFile::vftable;
  param_1[2] = param_2;
  param_1[3] = param_3;
  return param_1;
}

/* ---- FUNC 0005A030 FUN_18005a030 (11 bytes) ---- */

void FUN_18005a030(undefined8 *param_1)

{
  *param_1 = CImpIPersistFile::vftable;
  return;
}

/* ---- FUNC 0005A040 FUN_18005a040 (69 bytes) ---- */

undefined8 FUN_18005a040(longlong param_1,undefined8 *param_2)

{
  LPCSTR lpMultiByteStr;
  HRESULT HVar1;
  LPWSTR lpWideCharStr;
  IMalloc *local_res10;
  
  *param_2 = 0;
  HVar1 = CoGetMalloc(1,&local_res10);
  if (HVar1 < 0) {
    return 0x80004005;
  }
  lpWideCharStr = (*local_res10->lpVtbl->Alloc)(local_res10,0x208);
  (*local_res10->lpVtbl->Release)(local_res10);
  lpMultiByteStr = *(LPCSTR *)(*(longlong *)(param_1 + 0x10) + 0x108);
  if (lpMultiByteStr == (LPCSTR)0x0) {
    MultiByteToWideChar(0,0,"*.apa",-1,lpWideCharStr,0x104);
    return 1;
  }
  MultiByteToWideChar(0,0,lpMultiByteStr,-1,lpWideCharStr,0x104);
  *param_2 = lpWideCharStr;
  return 0;
}

/* ---- FUNC 0005A085 FUN_18005a085 (98 bytes) ---- */

undefined8 FUN_18005a085(longlong *param_1)

{
  LPCSTR lpMultiByteStr;
  LPWSTR lpWideCharStr;
  longlong unaff_RSI;
  undefined8 *unaff_RDI;
  longlong *in_stack_00000048;
  
  lpWideCharStr = (LPWSTR)(**(code **)(*param_1 + 0x18))();
  (**(code **)(*in_stack_00000048 + 0x10))();
  lpMultiByteStr = *(LPCSTR *)(*(longlong *)(unaff_RSI + 0x10) + 0x108);
  if (lpMultiByteStr == (LPCSTR)0x0) {
    MultiByteToWideChar(0,0,"*.apa",-1,lpWideCharStr,0x104);
    return 1;
  }
  MultiByteToWideChar(0,0,lpMultiByteStr,-1,lpWideCharStr,0x104);
  *unaff_RDI = lpWideCharStr;
  return 0;
}

/* ---- FUNC 0005A0E7 FUN_18005a0e7 (27 bytes) ---- */

undefined8 FUN_18005a0e7(UINT param_1,DWORD param_2,LPCSTR param_3,int param_4,int param_5)

{
  undefined8 unaff_RBX;
  undefined8 *unaff_RDI;
  LPWSTR in_stack_00000020;
  
  MultiByteToWideChar(param_1,param_2,param_3,param_4,in_stack_00000020,param_5);
  *unaff_RDI = unaff_RBX;
  return 0;
}

/* ---- FUNC 0005A110 FUN_18005a110 (27 bytes) ---- */

bool FUN_18005a110(longlong param_1)

{
  undefined1 uVar1;
  undefined7 extraout_var;
  
  uVar1 = FUN_180018640(*(longlong *)(param_1 + 0x10));
  return (int)CONCAT71(extraout_var,uVar1) == 0;
}

/* ---- FUNC 0005A130 FUN_18005a130 (595 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_18005a130(longlong param_1,OLECHAR *param_2)

{
  char cVar1;
  char cVar2;
  longlong *plVar3;
  code *pcVar4;
  IUnknown *pIVar5;
  longlong lVar6;
  BSTR pOVar8;
  ulonglong uVar9;
  char *pcVar10;
  int iVar11;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar12;
  undefined1 *puVar13;
  undefined8 uStack_c0;
  undefined1 auStack_b8 [32];
  undefined8 uStack_98;
  int aiStack_90 [2];
  undefined8 local_88 [2];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_78 [8];
  BSTR local_70;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_68 [8];
  _union_2707 local_60;
  undefined4 local_48;
  ULONG UStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  VARIANTARG local_28;
  ulonglong local_10;
  longlong lVar7;
  
  local_10 = DAT_180077818 ^ (ulonglong)local_78;
  uStack_c0 = 0x18005a178;
  VariantInit(&local_28);
  puVar13 = auStack_b8;
  if (param_2 == (OLECHAR *)0x0) {
LAB_18005a212:
    pCVar12 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  }
  else {
    lVar6 = -1;
    do {
      lVar7 = lVar6;
      lVar6 = lVar7 + 1;
    } while (param_2[lVar6] != L'\0');
    iVar11 = (int)lVar7 + 2;
    puVar13 = auStack_b8;
    if (0x3fffffff < iVar11) goto LAB_18005a212;
    lVar6 = (longlong)(int)lVar6 * 2;
    uVar9 = lVar6 + 0x11;
    if (uVar9 <= lVar6 + 2U) {
      uVar9 = 0xffffffffffffff0;
    }
    uStack_c0 = 0x18005a1ce;
    lVar6 = -(uVar9 & 0xfffffffffffffff0);
    puVar13 = auStack_b8 + lVar6;
    pCVar12 = local_78 + lVar6;
    if (pCVar12 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0)
    goto LAB_18005a212;
    *pCVar12 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>)0x0;
    *(undefined8 *)((longlong)local_88 + lVar6 + 8) = 0;
    *(undefined8 *)((longlong)local_88 + lVar6) = 0;
    *(int *)((longlong)aiStack_90 + lVar6) = iVar11 * 2;
    *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
     ((longlong)&uStack_98 + lVar6) = pCVar12;
    *(undefined8 *)(auStack_b8 + lVar6 + -8) = 0x18005a207;
    iVar11 = WideCharToMultiByte(0,0,param_2,-1,*(LPSTR *)((longlong)&uStack_98 + lVar6),
                                 *(int *)((longlong)aiStack_90 + lVar6),
                                 *(LPCSTR *)((longlong)local_88 + lVar6),
                                 *(LPBOOL *)((longlong)local_88 + lVar6 + 8));
    puVar13 = auStack_b8 + lVar6;
    if (iVar11 == 0) {
      pCVar12 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
      puVar13 = auStack_b8 + lVar6;
    }
  }
  *(undefined8 *)(puVar13 + -8) = 0x18005a21d;
  pOVar8 = SysAllocString(param_2);
  local_70 = pOVar8;
  if (*(int *)(*(longlong *)(param_1 + 0x10) + 0x18) != 0) {
    pcVar10 = *(char **)(*(longlong *)(param_1 + 0x10) + 0x108);
    lVar6 = (longlong)pCVar12 - (longlong)pcVar10;
    do {
      cVar1 = *pcVar10;
      cVar2 = pcVar10[lVar6];
      if (cVar1 != cVar2) break;
      pcVar10 = pcVar10 + 1;
    } while (cVar2 != '\0');
    if (cVar1 == cVar2) {
      *(undefined8 *)(puVar13 + -8) = 0x18005a260;
      SysFreeString(pOVar8);
      iVar11 = 0;
      goto LAB_18005a355;
    }
  }
  *(undefined8 *)(puVar13 + -8) = 0x18005a271;
  VariantInit((VARIANTARG *)&local_60.n2);
  local_60.n2.vt = 10;
  *(undefined8 *)(puVar13 + -8) = 0x18005a287;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_78,(char *)pCVar12);
  *(undefined8 *)(puVar13 + -8) = 0x18005a294;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind(local_78,'.');
  *(undefined8 *)(puVar13 + -8) = 0x18005a2a5;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid(local_78,(int)local_68);
  *(undefined8 *)(puVar13 + -8) = 0x18005a2ab;
  iVar11 = MVGetProductCode();
  pcVar10 = ".aprbkp";
  if (iVar11 == 1) {
    pcVar10 = ".bkp";
  }
  *(undefined8 *)(puVar13 + -8) = 0x18005a2ca;
  iVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                     (local_68,pcVar10);
  plVar3 = *(longlong **)(param_1 + 0x10);
  lVar6 = *plVar3;
  if (iVar11 == 0) {
    pcVar4 = *(code **)(lVar6 + 0x88);
    *(undefined8 *)(puVar13 + -8) = 0x18005a2df;
    iVar11 = (*pcVar4)();
  }
  else {
    local_48 = local_60._0_4_;
    UStack_44 = local_60.decVal.Hi32;
    uStack_40 = local_60._8_4_;
    uStack_3c = local_60._12_4_;
    local_38 = local_60._16_8_;
    pcVar4 = *(code **)(lVar6 + 0x80);
    *(undefined8 *)(puVar13 + -8) = 0x18005a2fd;
    iVar11 = (*pcVar4)(plVar3,&local_70,&local_48);
  }
  *(undefined8 *)(puVar13 + -8) = 0x18005a309;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_68);
  *(undefined8 *)(puVar13 + -8) = 0x18005a314;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_78);
  pOVar8 = local_70;
  *(undefined8 *)(puVar13 + -8) = 0x18005a31e;
  SysFreeString(pOVar8);
  *(undefined8 *)(puVar13 + -8) = 0x18005a328;
  VariantClear((VARIANTARG *)&local_60.n2);
  if (iVar11 < 0) {
    pIVar5 = *(IUnknown **)(param_1 + 0x10);
    *(undefined8 *)(puVar13 + -8) = 0x18005a33d;
    FUN_180018e30(pIVar5,1,1);
    pIVar5 = *(IUnknown **)(param_1 + 0x10);
    *(undefined8 *)(puVar13 + -8) = 0x18005a34c;
    FUN_180018e30(pIVar5,0,1);
    iVar11 = -0x7fffbffb;
  }
LAB_18005a355:
  *(undefined8 *)(puVar13 + -8) = 0x18005a361;
  return iVar11;
}

/* ---- FUNC 0005A390 FUN_18005a390 (600 bytes) ---- */

undefined8 FUN_18005a390(IUnknown *param_1,LPCOLESTR param_2,int param_3)

{
  DWORD dwRegister;
  IUnknownVtbl *pIVar1;
  _func_5157 *p_Var2;
  _func_5158 *p_Var3;
  undefined1 uVar4;
  HRESULT HVar5;
  _func_5156 *p_Var6;
  longlong lVar7;
  undefined7 extraout_var;
  _func_5156 *p_Var8;
  IRunningObjectTable *local_res10;
  
  p_Var6 = (_func_5156 *)0x0;
  p_Var8 = p_Var6;
  if ((param_2 != (LPCOLESTR)0x0) &&
     (p_Var8 = param_1[2].lpVtbl[0xb].QueryInterface, p_Var8 == (_func_5156 *)0x0)) {
    return 0x80030103;
  }
  pIVar1 = param_1[2].lpVtbl;
  p_Var2 = pIVar1[1].AddRef;
  if (p_Var2 != (_func_5157 *)0x0) {
    if (param_3 == 0) {
      uVar4 = FUN_180018640((longlong)pIVar1);
      local_res10 = operator_new(800);
      if (local_res10 != (LPRUNNINGOBJECTTABLE)0x0) {
        p_Var6 = (_func_5156 *)FUN_180024da0((char *)local_res10,(char *)p_Var8);
      }
      if (p_Var6 == (_func_5156 *)0x0) {
        return 0x8003001d;
      }
      FUN_180025150((longlong)p_Var6);
      lVar7 = HASaveFileByName(p_Var6 + 0x311,p_Var2);
      if (lVar7 == 0) {
        FUN_180025110((longlong)p_Var6);
        _guard_check_icall();
        FUN_180025ad0(p_Var6);
        if ((int)CONCAT71(extraout_var,uVar4) != 0) {
          *(undefined4 *)&param_1[2].lpVtbl[10].Release = 1;
        }
        return 0;
      }
      FUN_180025110((longlong)p_Var6);
      _guard_check_icall();
    }
    else {
      if (param_2 != (LPCOLESTR)0x0) {
        FUN_18001cbb0((longlong)pIVar1,(char *)p_Var8);
        p_Var3 = param_1[2].lpVtbl[0xb].Release;
        if (p_Var3 != (_func_5158 *)0x0) {
          (**(code **)(*(longlong *)p_Var3 + 0x10))();
          param_1[2].lpVtbl[0xb].Release = (_func_5158 *)0x0;
        }
        HVar5 = CreateFileMoniker(param_2,(LPMONIKER *)&param_1[2].lpVtbl[0xb].Release);
        if ((-1 < HVar5) && (HVar5 = GetRunningObjectTable(0,&local_res10), -1 < HVar5)) {
          dwRegister = *(DWORD *)&param_1[2].lpVtbl[0xb].AddRef;
          if (dwRegister != 0) {
            (*local_res10->lpVtbl->Revoke)(local_res10,dwRegister);
            *(undefined4 *)&param_1[2].lpVtbl[0xb].AddRef = 0;
          }
          (*local_res10->lpVtbl->Register)
                    (local_res10,0,param_1,(IMoniker *)param_1[2].lpVtbl[0xb].Release,
                     (DWORD *)&param_1[2].lpVtbl[0xb].AddRef);
          (*local_res10->lpVtbl->Release)(local_res10);
        }
      }
      local_res10 = operator_new(800);
      if (local_res10 != (LPRUNNINGOBJECTTABLE)0x0) {
        p_Var6 = (_func_5156 *)FUN_180024da0((char *)local_res10,(char *)p_Var8);
      }
      if (p_Var6 == (_func_5156 *)0x0) {
        return 0x8003001d;
      }
      FUN_180025150((longlong)p_Var6);
      lVar7 = HASaveFileByName(p_Var6 + 0x311,p_Var2);
      if (lVar7 == 0) {
        FUN_180025110((longlong)p_Var6);
        _guard_check_icall();
        FUN_180025ad0(p_Var6);
        *(undefined4 *)&param_1[2].lpVtbl[10].Release = 0;
        return 0;
      }
      FUN_180025110((longlong)p_Var6);
      _guard_check_icall();
    }
    FUN_180025ad0(p_Var6);
  }
  return 0x8003001d;
}

/* ---- FUNC 0005A5F0 FUN_18005a5f0 (33 bytes) ---- */

undefined8 * FUN_18005a5f0(undefined8 *param_1,undefined8 param_2)

{
  param_1[2] = param_2;
  *param_1 = CIOleUILinkContainer::vftable;
  *(undefined4 *)(param_1 + 1) = 0;
  *(undefined4 *)(param_1 + 3) = 0;
  param_1[4] = 0;
  *(undefined4 *)(param_1 + 5) = 0;
  return param_1;
}

/* ---- FUNC 0005A620 FUN_18005a620 (21 bytes) ---- */

undefined8 * FUN_18005a620(undefined8 *param_1)

{
  *(undefined4 *)(param_1 + 1) = 0;
  *param_1 = CLinks::vftable;
  return param_1;
}

/* ---- FUNC 0005A640 FUN_18005a640 (48 bytes) ---- */

void FUN_18005a640(undefined8 *param_1)

{
  *param_1 = CIOleUILinkContainer::vftable;
  if ((longlong *)param_1[4] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[4] + 0x10))();
    param_1[4] = 0;
  }
  return;
}

/* ---- FUNC 0005A670 FUN_18005a670 (11 bytes) ---- */

void FUN_18005a670(undefined8 *param_1)

{
  *param_1 = CLinks::vftable;
  return;
}

/* ---- FUNC 0005A680 FUN_18005a680 (38 bytes) ---- */

undefined8 FUN_18005a680(longlong param_1,uint param_2)

{
  *(undefined4 *)((ulonglong)param_2 + 8) = 1;
  FUN_180027550((ulonglong)param_2);
  *(undefined4 *)(param_1 + 0x28) = 1;
  return 0;
}

/* ---- FUNC 0005A6B0 FUN_18005a6b0 (25 bytes) ---- */

undefined8 FUN_18005a6b0(undefined8 param_1,uint param_2)

{
  undefined8 uVar1;
  
  if (param_2 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018005a6c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*(longlong *)(ulonglong)param_2 + 0x28))
                      ((longlong *)(ulonglong)param_2,0,&DAT_180066d68);
    return uVar1;
  }
  return 0;
}

/* ---- FUNC 0005A6D0 FUN_18005a6d0 (305 bytes) ---- */

ulonglong FUN_18005a6d0(undefined8 param_1,longlong *param_2)

{
  int iVar1;
  HRESULT HVar2;
  ulonglong uVar3;
  int local_res10 [2];
  longlong *local_res18;
  LPBC local_res20;
  longlong *local_18;
  LPVOID local_10;
  
  uVar3 = 0;
  local_res18 = (longlong *)0x0;
  local_10 = (LPVOID)0x0;
  local_res20 = (IBindCtx *)0x0;
  if (param_2 != (longlong *)0x0) {
    iVar1 = (**(code **)(*param_2 + 0xb0))(param_2,local_res10);
    if ((iVar1 < 0) || (local_res10[0] != 1)) {
      local_res18 = param_2;
      (**(code **)(*param_2 + 8))(param_2);
    }
    else {
      iVar1 = (**(code **)(*param_2 + 0x60))(param_2,1,&local_18);
      if (iVar1 < 0) {
        return 0;
      }
      (**(code **)(*local_18 + 0x18))(local_18,1,&local_res18,0);
      (**(code **)(*local_18 + 0x10))();
    }
    if (local_res18 != (longlong *)0x0) {
      iVar1 = (**(code **)(*local_res18 + 0xb0))(local_res18,local_res10);
      if (((-1 < iVar1) && (local_res10[0] == 2)) &&
         (HVar2 = CreateBindCtx(0,&local_res20), -1 < HVar2)) {
        iVar1 = (**(code **)(*local_res18 + 0xa0))(local_res18,local_res20,0,&local_10);
        if (-1 < iVar1) {
          uVar3 = 0xffffffffffffffff;
          do {
            uVar3 = uVar3 + 1;
          } while (*(short *)((longlong)local_10 + uVar3 * 2) != 0);
          uVar3 = uVar3 & 0xffffffff;
          CoTaskMemFree(local_10);
        }
        (*local_res20->lpVtbl->Release)(local_res20);
      }
      (**(code **)(*local_res18 + 0x10))();
      return uVar3;
    }
  }
  return 0;
}

/* ---- FUNC 0005A810 FUN_18005a810 (499 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18005a810(undefined8 param_1,LPCSTR param_2,uint param_3,LPMONIKER *param_4)

{
  longlong lVar1;
  LPCOLESTR pOVar2;
  _func_5320 *p_Var3;
  LPMONIKER pIVar4;
  LPMONIKER pmkRest;
  longlong lVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  int iVar8;
  LPCOLESTR pOVar9;
  LPCOLESTR pOVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined8 uStack_1a0;
  undefined1 auStack_198 [32];
  undefined8 uStack_178;
  int aiStack_170 [2];
  LPMONIKER local_168;
  LPMONIKER local_160;
  CHAR local_158;
  char acStack_157 [271];
  ulonglong local_48;
  
  local_48 = DAT_180077818 ^ (ulonglong)&local_168;
  pOVar9 = (LPCOLESTR)0x0;
  local_168 = (LPMONIKER)0x0;
  local_160 = (LPMONIKER)0x0;
  *param_4 = (LPMONIKER)0x0;
  uStack_1a0 = 0x18005a85c;
  lstrcpynA(&local_158,param_2,param_3 + 1);
  lVar1 = -1;
  do {
    lVar5 = lVar1;
    lVar1 = lVar5 + 1;
  } while (acStack_157[lVar5] != '\0');
  iVar8 = (int)lVar5 + 2;
  puVar12 = auStack_198;
  pOVar10 = pOVar9;
  if (iVar8 < 0x40000000) {
    lVar1 = (longlong)(int)(lVar5 + 1) * 2;
    uVar7 = lVar1 + 0x11;
    if (uVar7 <= lVar1 + 2U) {
      uVar7 = 0xffffffffffffff0;
    }
    uStack_1a0 = 0x18005a8a6;
    lVar1 = -(uVar7 & 0xfffffffffffffff0);
    pOVar2 = (LPCOLESTR)((longlong)&local_168 + lVar1);
    puVar12 = auStack_198 + lVar1;
    if (pOVar2 != (LPCOLESTR)0x0) {
      *(int *)((longlong)aiStack_170 + lVar1) = iVar8;
      *pOVar2 = L'\0';
      *(LPCOLESTR *)((longlong)&uStack_178 + lVar1) = pOVar2;
      *(undefined8 *)(auStack_198 + lVar1 + -8) = 0x18005a8d3;
      iVar8 = MultiByteToWideChar(0,0,&local_158,-1,*(LPWSTR *)((longlong)&uStack_178 + lVar1),
                                  *(int *)((longlong)aiStack_170 + lVar1));
      puVar12 = auStack_198 + lVar1;
      pOVar10 = pOVar2;
      if (iVar8 == 0) {
        puVar12 = auStack_198 + lVar1;
        pOVar10 = pOVar9;
      }
    }
  }
  *(undefined8 *)(puVar12 + -8) = 0x18005a8eb;
  CreateFileMoniker(pOVar10,&local_168);
  puVar11 = puVar12;
  if (local_168 == (LPMONIKER)0x0) {
LAB_18005a9d2:
    uVar6 = 0;
    puVar12 = puVar11;
  }
  else {
    *(undefined8 *)(puVar12 + -8) = 0x18005a8fe;
    iVar8 = lstrlenA(param_2);
    if ((int)param_3 < iVar8) {
      *(undefined8 *)(puVar12 + -8) = 0x18005a918;
      lstrcpyA(&local_158,param_2 + (ulonglong)param_3 + 1);
      lVar1 = -1;
      do {
        lVar5 = lVar1;
        lVar1 = lVar5 + 1;
      } while (acStack_157[lVar5] != '\0');
      iVar8 = (int)lVar5 + 2;
      pOVar10 = pOVar9;
      if (iVar8 < 0x40000000) {
        lVar1 = (longlong)(int)(lVar5 + 1) * 2;
        uVar7 = lVar1 + 0x11;
        if (uVar7 <= lVar1 + 2U) {
          uVar7 = 0xffffffffffffff0;
        }
        *(undefined8 *)(puVar12 + -8) = 0x18005a958;
        lVar1 = -(uVar7 & 0xfffffffffffffff0);
        pOVar2 = (LPCOLESTR)(puVar12 + lVar1 + 0x30);
        puVar11 = puVar12 + lVar1;
        if (pOVar2 != (LPCOLESTR)0x0) {
          *(int *)(puVar12 + lVar1 + 0x28) = iVar8;
          *pOVar2 = L'\0';
          *(LPCOLESTR *)(puVar12 + lVar1 + 0x20) = pOVar2;
          *(undefined8 *)(puVar12 + lVar1 + -8) = 0x18005a985;
          iVar8 = MultiByteToWideChar(0,0,&local_158,-1,*(LPWSTR *)(puVar12 + lVar1 + 0x20),
                                      *(int *)(puVar12 + lVar1 + 0x28));
          pOVar10 = pOVar2;
          puVar11 = puVar12 + lVar1;
          if (iVar8 == 0) {
            pOVar10 = pOVar9;
            puVar11 = puVar12 + lVar1;
          }
        }
      }
      *(undefined8 *)(puVar11 + -8) = 0x18005a9a2;
      CreateItemMoniker(L"!",pOVar10,&local_160);
      pmkRest = local_160;
      pIVar4 = local_168;
      if (local_160 != (LPMONIKER)0x0) {
        *(undefined8 *)(puVar11 + -8) = 0x18005a9b8;
        CreateGenericComposite(pIVar4,pmkRest,param_4);
        pIVar4 = local_160;
        p_Var3 = local_160->lpVtbl->Release;
        *(undefined8 *)(puVar11 + -8) = 0x18005a9c2;
        (*p_Var3)(pIVar4);
      }
      pIVar4 = local_168;
      p_Var3 = local_168->lpVtbl->Release;
      *(undefined8 *)(puVar11 + -8) = 0x18005a9cc;
      (*p_Var3)(pIVar4);
      puVar12 = puVar11;
      if (*param_4 == (LPMONIKER)0x0) goto LAB_18005a9d2;
    }
    else {
      *param_4 = local_168;
    }
    uVar6 = 1;
  }
  *(undefined8 *)(puVar12 + -8) = 0x18005a9e3;
  return uVar6;
}

/* ---- FUNC 0005AA10 FUN_18005aa10 (402 bytes) ---- */

ulonglong FUN_18005aa10(longlong param_1,ulonglong param_2,undefined8 *param_3,int *param_4,
                       undefined8 param_5,undefined8 param_6,uint *param_7,undefined4 *param_8)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  char *pcVar7;
  undefined4 extraout_var;
  char *pcVar8;
  char *local_28;
  longlong *local_20;
  
  uVar5 = param_2 & 0xffffffff;
  local_20 = (longlong *)0x0;
  if ((int)param_2 == 0) {
    uVar5 = 0x80004005;
  }
  else {
    if (param_7 != (uint *)0x0) {
      *param_7 = (uint)((*(int *)(uVar5 + 8) - 4U & 0xfffffffb) == 0);
    }
    if (param_8 != (undefined4 *)0x0) {
      *param_8 = 0;
      if (*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x10) < 1) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      if (uVar5 == **(ulonglong **)(*(longlong *)(param_1 + 0x10) + 8)) {
        *param_8 = 1;
      }
    }
    if (*(int *)(uVar5 + 8) == 0x10) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_28);
      uVar6 = FUN_180029930(uVar5,(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                  &local_28);
      uVar5 = uVar6 & 0xffffffff;
      if (-1 < (int)uVar6) {
        iVar3 = *(int *)(local_28 + -0x10);
        iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_28,'!',0);
        *param_4 = iVar2;
        if (iVar2 == -1) {
          *param_4 = iVar3;
        }
        pcVar7 = CoTaskMemAlloc((longlong)(iVar3 + 1));
        pcVar8 = pcVar7;
        do {
          cVar1 = *local_28;
          *pcVar8 = cVar1;
          local_28 = local_28 + 1;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        *param_3 = pcVar7;
        uVar5 = 0;
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_28);
    }
    else {
      iVar3 = FUN_18005aee0(param_1,param_2,&DAT_180066dc8,&local_20);
      uVar5 = CONCAT44(extraout_var,iVar3);
      if (-1 < iVar3) {
        uVar4 = (**(code **)(**(longlong **)(param_1 + 0x20) + 0x38))
                          (*(longlong **)(param_1 + 0x20),(ulonglong)local_20 & 0xffffffff,param_3,
                           param_4,param_5,param_6,param_7,param_8);
        uVar5 = (ulonglong)uVar4;
        (**(code **)(*local_20 + 0x10))();
      }
    }
  }
  return uVar5;
}

/* ---- FUNC 0005ABB0 FUN_18005abb0 (67 bytes) ---- */

undefined4
FUN_18005abb0(undefined8 param_1,uint param_2,undefined8 *param_3,undefined4 *param_4,
             undefined8 *param_5,undefined8 *param_6)

{
  int iVar1;
  undefined4 uVar2;
  LPSTR pCVar3;
  ulonglong uVar4;
  longlong *plVar5;
  longlong lVar6;
  LPCWSTR local_48;
  longlong *local_40;
  longlong *local_38 [2];
  
  plVar5 = (longlong *)(ulonglong)param_2;
  local_40 = (longlong *)0x0;
  local_38[0] = (longlong *)0x0;
  if (param_2 == 0) {
    return 0x80004005;
  }
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = 0;
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  if (param_5 != (undefined8 *)0x0) {
    *param_5 = 0;
  }
  if (param_6 != (undefined8 *)0x0) {
    *param_6 = 0;
  }
  iVar1 = (**(code **)(*plVar5 + 0x30))(plVar5,local_38);
  if (-1 < iVar1) {
    iVar1 = (**(code **)*plVar5)(plVar5,&DAT_180066db8,&local_40);
    if (-1 < iVar1) {
      pCVar3 = CoTaskMemAlloc(0x50);
      (**(code **)(*local_40 + 0x80))(local_40,1,&local_48);
      WideCharToMultiByte(0,0,local_48,-1,pCVar3,0x50,(LPCSTR)0x0,(LPBOOL)0x0);
      CoTaskMemFree(local_48);
      if (param_5 != (undefined8 *)0x0) {
        *param_5 = pCVar3;
      }
      pCVar3 = CoTaskMemAlloc(0x50);
      (**(code **)(*local_40 + 0x80))(local_40,2,&local_48);
      WideCharToMultiByte(0,0,local_48,-1,pCVar3,0x50,(LPCSTR)0x0,(LPBOOL)0x0);
      CoTaskMemFree(local_48);
      if (param_6 != (undefined8 *)0x0) {
        *param_6 = pCVar3;
      }
      (**(code **)(*local_40 + 0x10))();
    }
    if (param_4 != (undefined4 *)0x0) {
      uVar4 = FUN_18005a6d0(param_1,local_38[0]);
      *param_4 = (int)uVar4;
    }
    (**(code **)(*local_38[0] + 0x10))();
  }
  uVar2 = (**(code **)(*plVar5 + 0x40))(plVar5,&local_48);
  lVar6 = -1;
  do {
    lVar6 = lVar6 + 1;
  } while (local_48[lVar6] != L'\0');
  iVar1 = (int)lVar6 + 1;
  pCVar3 = CoTaskMemAlloc((longlong)iVar1);
  WideCharToMultiByte(0,0,local_48,-1,pCVar3,iVar1,(LPCSTR)0x0,(LPBOOL)0x0);
  CoTaskMemFree(local_48);
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = pCVar3;
  }
  return uVar2;
}

/* ---- FUNC 0005ABF3 FUN_18005abf3 (111 bytes) ---- */

undefined4
FUN_18005abf3(undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  LPSTR pCVar3;
  ulonglong uVar4;
  longlong *unaff_RBX;
  longlong lVar5;
  undefined4 *unaff_RDI;
  undefined8 unaff_R12;
  LPCSTR unaff_R13;
  undefined8 *unaff_R15;
  LPCWSTR in_stack_00000040;
  longlong *in_stack_00000048;
  longlong *in_stack_00000050;
  undefined8 *in_stack_000000b0;
  undefined8 *in_stack_000000b8;
  
  if (unaff_R15 != (undefined8 *)0x0) {
    *param_3 = unaff_R13;
  }
  if (unaff_RDI != (undefined4 *)0x0) {
    *param_4 = (int)unaff_R13;
  }
  if (in_stack_000000b0 != (undefined8 *)0x0) {
    *in_stack_000000b0 = unaff_R13;
  }
  if (in_stack_000000b8 != (undefined8 *)0x0) {
    *in_stack_000000b8 = unaff_R13;
  }
  iVar1 = (**(code **)(*unaff_RBX + 0x30))();
  if (-1 < iVar1) {
    iVar1 = (**(code **)*unaff_RBX)();
    if (-1 < iVar1) {
      pCVar3 = CoTaskMemAlloc(0x50);
      (**(code **)(*in_stack_00000048 + 0x80))(in_stack_00000048,1,&stack0x00000040);
      WideCharToMultiByte(0,0,in_stack_00000040,-1,pCVar3,0x50,unaff_R13,(LPBOOL)unaff_R13);
      CoTaskMemFree(in_stack_00000040);
      if (in_stack_000000b0 != (undefined8 *)0x0) {
        *in_stack_000000b0 = pCVar3;
      }
      pCVar3 = CoTaskMemAlloc(0x50);
      (**(code **)(*in_stack_00000048 + 0x80))(in_stack_00000048,2,&stack0x00000040);
      WideCharToMultiByte(0,0,in_stack_00000040,-1,pCVar3,0x50,unaff_R13,(LPBOOL)unaff_R13);
      CoTaskMemFree(in_stack_00000040);
      if (in_stack_000000b8 != (undefined8 *)0x0) {
        *in_stack_000000b8 = pCVar3;
      }
      (**(code **)(*in_stack_00000048 + 0x10))();
    }
    if (unaff_RDI != (undefined4 *)0x0) {
      uVar4 = FUN_18005a6d0(unaff_R12,in_stack_00000050);
      *unaff_RDI = (int)uVar4;
    }
    (**(code **)(*in_stack_00000050 + 0x10))();
  }
  uVar2 = (**(code **)(*unaff_RBX + 0x40))();
  lVar5 = -1;
  do {
    lVar5 = lVar5 + 1;
  } while (in_stack_00000040[lVar5] != (WCHAR)unaff_R13);
  iVar1 = (int)lVar5 + 1;
  pCVar3 = CoTaskMemAlloc((longlong)iVar1);
  WideCharToMultiByte(0,0,in_stack_00000040,-1,pCVar3,iVar1,unaff_R13,(LPBOOL)unaff_R13);
  CoTaskMemFree(in_stack_00000040);
  if (unaff_R15 != (undefined8 *)0x0) {
    *unaff_R15 = pCVar3;
  }
  return uVar2;
}

/* ---- FUNC 0005AC62 FUN_18005ac62 (212 bytes) ---- */

undefined4 FUN_18005ac62(SIZE_T param_1)

{
  undefined4 uVar1;
  LPSTR pCVar2;
  ulonglong uVar3;
  int cbMultiByte;
  longlong *unaff_RBX;
  longlong lVar4;
  undefined8 *unaff_RSI;
  undefined4 *unaff_RDI;
  undefined8 unaff_R12;
  LPCSTR unaff_R13;
  undefined8 *unaff_R14;
  undefined8 *unaff_R15;
  LPCWSTR in_stack_00000040;
  longlong *in_stack_00000048;
  longlong *in_stack_00000050;
  
  pCVar2 = CoTaskMemAlloc(param_1);
  (**(code **)(*in_stack_00000048 + 0x80))(in_stack_00000048,1,&stack0x00000040);
  WideCharToMultiByte(0,0,in_stack_00000040,-1,pCVar2,0x50,unaff_R13,(LPBOOL)unaff_R13);
  CoTaskMemFree(in_stack_00000040);
  if (unaff_RSI != (undefined8 *)0x0) {
    *unaff_RSI = pCVar2;
  }
  pCVar2 = CoTaskMemAlloc(0x50);
  (**(code **)(*in_stack_00000048 + 0x80))(in_stack_00000048,2,&stack0x00000040);
  WideCharToMultiByte(0,0,in_stack_00000040,-1,pCVar2,0x50,unaff_R13,(LPBOOL)unaff_R13);
  CoTaskMemFree(in_stack_00000040);
  if (unaff_R14 != (undefined8 *)0x0) {
    *unaff_R14 = pCVar2;
  }
  (**(code **)(*in_stack_00000048 + 0x10))();
  if (unaff_RDI != (undefined4 *)0x0) {
    uVar3 = FUN_18005a6d0(unaff_R12,in_stack_00000050);
    *unaff_RDI = (int)uVar3;
  }
  (**(code **)(*in_stack_00000050 + 0x10))();
  uVar1 = (**(code **)(*unaff_RBX + 0x40))();
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (in_stack_00000040[lVar4] != (WCHAR)unaff_R13);
  cbMultiByte = (int)lVar4 + 1;
  pCVar2 = CoTaskMemAlloc((longlong)cbMultiByte);
  WideCharToMultiByte(0,0,in_stack_00000040,-1,pCVar2,cbMultiByte,unaff_R13,(LPBOOL)unaff_R13);
  CoTaskMemFree(in_stack_00000040);
  if (unaff_R15 != (undefined8 *)0x0) {
    *unaff_R15 = pCVar2;
  }
  return uVar1;
}

/* ---- FUNC 0005AD36 FUN_18005ad36 (90 bytes) ---- */

undefined4 FUN_18005ad36(void)

{
  undefined4 uVar1;
  ulonglong uVar2;
  LPSTR lpMultiByteStr;
  int cbMultiByte;
  longlong *unaff_RBX;
  longlong lVar3;
  undefined8 unaff_RSI;
  undefined4 *unaff_RDI;
  undefined8 unaff_R12;
  LPCSTR unaff_R13;
  undefined8 *unaff_R14;
  undefined8 *unaff_R15;
  LPCWSTR in_stack_00000040;
  longlong *in_stack_00000048;
  longlong *in_stack_00000050;
  
  *unaff_R14 = unaff_RSI;
  (**(code **)(*in_stack_00000048 + 0x10))();
  if (unaff_RDI != (undefined4 *)0x0) {
    uVar2 = FUN_18005a6d0(unaff_R12,in_stack_00000050);
    *unaff_RDI = (int)uVar2;
  }
  (**(code **)(*in_stack_00000050 + 0x10))();
  uVar1 = (**(code **)(*unaff_RBX + 0x40))();
  lVar3 = -1;
  do {
    lVar3 = lVar3 + 1;
  } while (in_stack_00000040[lVar3] != (WCHAR)unaff_R13);
  cbMultiByte = (int)lVar3 + 1;
  lpMultiByteStr = CoTaskMemAlloc((longlong)cbMultiByte);
  WideCharToMultiByte(0,0,in_stack_00000040,-1,lpMultiByteStr,cbMultiByte,unaff_R13,
                      (LPBOOL)unaff_R13);
  CoTaskMemFree(in_stack_00000040);
  if (unaff_R15 != (undefined8 *)0x0) {
    *unaff_R15 = lpMultiByteStr;
  }
  return uVar1;
}

/* ---- FUNC 0005AD90 FUN_18005ad90 (106 bytes) ---- */

undefined4 FUN_18005ad90(longlong param_1)

{
  LPSTR lpMultiByteStr;
  int cbMultiByte;
  longlong unaff_RBX;
  undefined4 unaff_ESI;
  LPCSTR unaff_R13;
  undefined8 *unaff_R15;
  LPCWSTR in_stack_00000040;
  
  do {
    unaff_RBX = unaff_RBX + 1;
  } while (*(short *)(param_1 + unaff_RBX * 2) != (short)unaff_R13);
  cbMultiByte = (int)unaff_RBX + 1;
  lpMultiByteStr = CoTaskMemAlloc((longlong)cbMultiByte);
  WideCharToMultiByte(0,0,in_stack_00000040,-1,lpMultiByteStr,cbMultiByte,unaff_R13,
                      (LPBOOL)unaff_R13);
  CoTaskMemFree(in_stack_00000040);
  if (unaff_R15 != (undefined8 *)0x0) {
    *unaff_R15 = lpMultiByteStr;
  }
  return unaff_ESI;
}

/* ---- FUNC 0005AE00 FUN_18005ae00 (103 bytes) ---- */

int FUN_18005ae00(undefined8 param_1,ulonglong param_2,undefined4 *param_3)

{
  int iVar1;
  longlong *local_res20;
  
  if ((int)param_2 == 0) {
    return -0x7fffbffb;
  }
  if (*(int *)((param_2 & 0xffffffff) + 8) == 0x10) {
    *param_3 = 1;
    return 0;
  }
  iVar1 = FUN_18005aee0(param_1,param_2,&DAT_180066dc8,&local_res20);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_res20 + 0x20))(local_res20,param_3);
    (**(code **)(*local_res20 + 0x10))();
  }
  return iVar1;
}

/* ---- FUNC 0005AE70 FUN_18005ae70 (22 bytes) ---- */

undefined8 FUN_18005ae70(undefined8 param_1,uint param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  if (param_2 == 0) {
    return 0x80004005;
  }
                    /* WARNING: Could not recover jumptable at 0x00018005ae82. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*(longlong *)(ulonglong)param_2 + 0x20))
                    ((longlong *)(ulonglong)param_2,param_3);
  return uVar1;
}

/* ---- FUNC 0005AE90 FUN_18005ae90 (76 bytes) ---- */

longlong FUN_18005ae90(longlong param_1,int param_2)

{
  uint *puVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  
  puVar1 = (uint *)(param_1 + 0x18);
  if (param_2 == 0) {
    *puVar1 = 0;
  }
  lVar2 = *(longlong *)(param_1 + 0x10);
  uVar4 = *puVar1;
  if (uVar4 < *(uint *)(lVar2 + 0x10)) {
    do {
      uVar5 = (ulonglong)uVar4;
      if (*(longlong *)(lVar2 + 0x10) <= (longlong)uVar5) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      uVar4 = uVar4 + 1;
      lVar3 = *(longlong *)(*(longlong *)(lVar2 + 8) + uVar5 * 8);
      *puVar1 = uVar4;
      if (lVar3 != 0) {
        return lVar3;
      }
    } while (uVar4 < *(uint *)(lVar2 + 0x10));
  }
  return 0;
}

/* ---- FUNC 0005AEE0 FUN_18005aee0 (91 bytes) ---- */

undefined4 FUN_18005aee0(undefined8 param_1,ulonglong param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 uVar1;
  longlong *local_18 [2];
  
  FUN_18002bb10(param_2 & 0xffffffff,(longlong *)local_18);
  if (local_18[0] != (longlong *)0x0) {
    uVar1 = (**(code **)*local_18[0])(local_18[0],param_3,param_4);
    (**(code **)(*local_18[0] + 0x10))();
    return uVar1;
  }
  return 0x80004005;
}

/* ---- FUNC 0005AF40 FUN_18005af40 (65 bytes) ---- */

undefined8 FUN_18005af40(longlong param_1)

{
  undefined8 *puVar1;
  longlong *plVar2;
  
  puVar1 = operator_new(0x10);
  if (puVar1 == (undefined8 *)0x0) {
    plVar2 = (longlong *)0x0;
  }
  else {
    plVar2 = FUN_18005a620(puVar1);
  }
  *(longlong **)(param_1 + 0x20) = plVar2;
  (**(code **)(*plVar2 + 8))();
  return 1;
}

/* ---- FUNC 0005AF90 FUN_18005af90 (23 bytes) ---- */

undefined8 FUN_18005af90(undefined8 param_1,ulonglong param_2)

{
  FUN_180025d10(param_2 & 0xffffffff);
  return 0;
}

/* ---- FUNC 0005AFB0 FUN_18005afb0 (6 bytes) ---- */

undefined8 FUN_18005afb0(void)

{
  return 0x80004002;
}

/* ---- FUNC 0005AFC0 FUN_18005afc0 (46 bytes) ---- */

int FUN_18005afc0(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 1) + -1;
  *(int *)(param_1 + 1) = iVar1;
  if (iVar1 == 0) {
    FUN_18005a640(param_1);
    FUN_180025ad0(param_1);
    iVar1 = 0;
  }
  return iVar1;
}

/* ---- FUNC 0005AFF0 FUN_18005aff0 (46 bytes) ---- */

int FUN_18005aff0(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 1) + -1;
  *(int *)(param_1 + 1) = iVar1;
  if (iVar1 == 0) {
    FUN_18005a670(param_1);
    FUN_180025ad0(param_1);
    iVar1 = 0;
  }
  return iVar1;
}

/* ---- FUNC 0005B020 FUN_18005b020 (256 bytes) ---- */

int FUN_18005b020(longlong param_1,ulonglong param_2,char *param_3,undefined4 param_4,
                 undefined4 *param_5,int param_6)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined4 local_18;
  undefined4 uStack_14;
  
  uVar3 = param_2 & 0xffffffff;
  if (((int)param_2 == 0) || (*(int *)(uVar3 + 8) == 1)) {
    return -0x7fffbffb;
  }
  if (*(int *)(uVar3 + 8) == 0x10) {
    FUN_18002f340(uVar3,param_3);
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_3[lVar2] != '\0');
    *param_5 = (int)lVar2;
    if (param_6 != 0) {
      FUN_180028420(uVar3);
      *(undefined4 *)(param_1 + 0x28) = 1;
      return 0;
    }
  }
  else {
    *(undefined4 *)(uVar3 + 8) = 2;
    iVar1 = FUN_18005aee0(param_1,param_2,&DAT_180066dc8,&local_18);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = (**(code **)(**(longlong **)(param_1 + 0x20) + 0x30))
                      (*(longlong **)(param_1 + 0x20),local_18,param_3,param_4,param_5,param_6);
    (**(code **)(*(longlong *)CONCAT44(uStack_14,local_18) + 0x10))();
    if (iVar1 < 0) {
      return iVar1;
    }
    if (iVar1 == 0) {
      *(undefined4 *)(uVar3 + 8) = 4;
    }
  }
  *(undefined4 *)(param_1 + 0x28) = 1;
  return 0;
}

/* ---- FUNC 0005B120 FUN_18005b120 (316 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_18005b120(undefined8 param_1,uint param_2,LPCSTR param_3,uint param_4,ULONG *param_5,
                  int param_6)

{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  uint uVar4;
  longlong *plVar5;
  undefined1 auStackY_478 [32];
  LPMONIKER local_448;
  longlong local_440;
  longlong lStack_438;
  WCHAR local_428 [512];
  ulonglong local_28;
  
  local_28 = DAT_180077818 ^ (ulonglong)auStackY_478;
  plVar5 = (longlong *)(ulonglong)param_2;
  local_448 = (IMoniker *)0x0;
  local_440 = DAT_180066d68;
  lStack_438 = DAT_180066d70;
  if (param_6 == 0) {
    uVar4 = 1;
    uVar2 = FUN_18005a810(param_1,param_3,param_4,&local_448);
    if ((int)uVar2 == 0) {
      return 0x80004005;
    }
  }
  else {
    uVar2 = FUN_18005b4f0(param_1,param_3,param_5,&local_448,&local_440);
    if ((int)uVar2 == 0) {
      return 0x80004005;
    }
    lVar3 = DAT_180066d68 - local_440;
    if (lVar3 == 0) {
      lVar3 = DAT_180066d70 - lStack_438;
    }
    uVar4 = (uint)(lVar3 == 0);
  }
  if (plVar5 == (longlong *)0x0) {
    (*local_448->lpVtbl->Release)(local_448);
    return 0x80004005;
  }
  if (local_448 == (IMoniker *)0x0) {
    MultiByteToWideChar(0,0,param_3,-1,local_428,0x200);
    uVar1 = (**(code **)(*plVar5 + 0x38))(plVar5,local_428);
  }
  else {
    uVar1 = (**(code **)(*plVar5 + 0x28))(plVar5,local_448,&local_440);
    (*local_448->lpVtbl->Release)(local_448);
  }
  if ((int)uVar1 < 0) {
    return uVar1;
  }
  return uVar4;
}

/* ---- FUNC 0005B260 FUN_18005b260 (106 bytes) ---- */

uint FUN_18005b260(longlong param_1,ulonglong param_2,undefined4 param_3)

{
  uint uVar1;
  longlong *local_res20;
  
  if ((int)param_2 == 0) {
    return 0x80004005;
  }
  uVar1 = FUN_18005aee0(param_1,param_2,&DAT_180066dc8,&local_res20);
  if (-1 < (int)uVar1) {
    uVar1 = (**(code **)(*local_res20 + 0x18))(local_res20,param_3);
    (**(code **)(*local_res20 + 0x10))();
    *(uint *)(param_1 + 0x28) = ~uVar1 >> 0x1f;
  }
  return uVar1;
}

/* ---- FUNC 0005B2D0 FUN_18005b2d0 (22 bytes) ---- */

undefined8 FUN_18005b2d0(undefined8 param_1,uint param_2,undefined4 param_3)

{
  undefined8 uVar1;
  
  if (param_2 == 0) {
    return 0x80004005;
  }
                    /* WARNING: Could not recover jumptable at 0x00018005b2e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*(longlong *)(ulonglong)param_2 + 0x18))
                    ((longlong *)(ulonglong)param_2,param_3);
  return uVar1;
}

/* ---- FUNC 0005B2F0 FUN_18005b2f0 (362 bytes) ---- */

ulonglong FUN_18005b2f0(longlong param_1,uint param_2,int param_3)

{
  ulonglong uVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar2;
  char *pcVar3;
  undefined8 *puVar4;
  IAtlStringMgr *pIVar5;
  ulonglong uVar6;
  char *local_28;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_20 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_18 [16];
  
  uVar6 = (ulonglong)param_2;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_28);
  uVar1 = FUN_180030460(uVar6);
  if ((int)uVar1 < 0) {
    if (param_3 != 0) {
      pCVar2 = FUN_180020fe0(local_20,0xf);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_28,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar2
                );
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_20);
      pcVar3 = (char *)MVGetVersionString();
      puVar4 = (undefined8 *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
               CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_18,pcVar3);
      pIVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_28
                         );
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_20,pIVar5);
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)local_20,local_28,*(int *)(local_28 + -0x10),
                 (char *)*puVar4,*(int *)((char *)*puVar4 + -0x10));
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_28,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 local_20);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_20);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_18);
      pCVar2 = FUN_180020fe0(local_18,0xe);
      MMAfxMessageBox(*(char **)pCVar2,0,-1,0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_18);
    }
    if ((*(int *)(uVar6 + 8) - 4U & 0xfffffffb) == 0) {
      *(undefined4 *)(uVar6 + 8) = 2;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x28) = 1;
    if (*(int *)(uVar6 + 8) == 2) {
      *(undefined4 *)(uVar6 + 8) = 4;
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_28);
  return uVar1 & 0xffffffff;
}

/* ---- FUNC 0005B460 FUN_18005b460 (46 bytes) ---- */

ulonglong FUN_18005b460(undefined8 param_1,uint param_2)

{
  uint uVar1;
  ULONG UVar2;
  ulonglong uVar3;
  LPUNKNOWN local_18 [2];
  
  if (param_2 == 0) {
    return 0x80004005;
  }
  uVar3 = (*(code *)**(undefined8 **)(ulonglong)param_2)
                    ((undefined8 *)(ulonglong)param_2,&DAT_180066db8,local_18);
  if (-1 < (int)uVar3) {
    uVar1 = OleRun(local_18[0]);
    if ((int)uVar1 < 0) {
      (*local_18[0]->lpVtbl->Release)(local_18[0]);
      return (ulonglong)uVar1;
    }
    UVar2 = (*local_18[0]->lpVtbl[4].Release)(local_18[0]);
    uVar1 = 0;
    if (UVar2 != 0) {
      uVar1 = (*local_18[0]->lpVtbl[4].AddRef)(local_18[0]);
    }
    (*local_18[0]->lpVtbl->Release)(local_18[0]);
    uVar3 = (ulonglong)uVar1;
  }
  return uVar3;
}

/* ---- FUNC 0005B48E FUN_18005b48e (40 bytes) ---- */

HRESULT FUN_18005b48e(LPUNKNOWN param_1)

{
  HRESULT HVar1;
  int iVar2;
  undefined8 uStackX_20;
  
  HVar1 = OleRun(param_1);
  if (HVar1 < 0) {
    (**(code **)(*uStackX_20 + 0x10))();
    return HVar1;
  }
  iVar2 = (**(code **)(*uStackX_20 + 0x70))();
  HVar1 = 0;
  if (iVar2 != 0) {
    HVar1 = (**(code **)(*uStackX_20 + 0x68))();
  }
  (**(code **)(*uStackX_20 + 0x10))();
  return HVar1;
}

/* ---- FUNC 0005B4B6 FUN_18005b4b6 (43 bytes) ---- */

undefined4 FUN_18005b4b6(longlong *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uStackX_20;
  
  iVar1 = (**(code **)(*param_1 + 0x70))();
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = (**(code **)(*uStackX_20 + 0x68))();
  }
  (**(code **)(*uStackX_20 + 0x10))();
  return uVar2;
}

/* ---- FUNC 0005B4E1 FUN_18005b4e1 (5 bytes) ---- */

void FUN_18005b4e1(void)

{
  return;
}

/* ---- FUNC 0005B4F0 FUN_18005b4f0 (364 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_18005b4f0(undefined8 param_1,LPCSTR param_2,ULONG *param_3,LPMONIKER *param_4,
             undefined8 *param_5)

{
  LPCOLESTR pOVar1;
  IMoniker *This;
  _func_5326 *p_Var2;
  code *pcVar3;
  _func_5262 *p_Var4;
  LPBC pIVar5;
  longlong *plVar6;
  HRESULT HVar7;
  longlong lVar8;
  undefined8 uVar10;
  ulonglong uVar11;
  int iVar12;
  LPCOLESTR pOVar13;
  LPCOLESTR szUserName;
  undefined1 *puVar14;
  undefined8 uStack_70;
  undefined1 auStack_68 [32];
  undefined8 uStack_48;
  int aiStack_40 [2];
  LPBC local_38;
  longlong *local_30;
  ulonglong local_28;
  longlong lVar9;
  
  puVar14 = auStack_68;
  local_28 = DAT_180077818 ^ (ulonglong)&local_38;
  pOVar13 = (LPCOLESTR)0x0;
  *param_4 = (LPMONIKER)0x0;
  uVar10 = DAT_180066d70;
  local_38 = (LPBC)0x0;
  *param_5 = DAT_180066d68;
  param_5[1] = uVar10;
  uStack_70 = 0x18005b54a;
  HVar7 = CreateBindCtx(0,&local_38);
  if (-1 < HVar7) {
    szUserName = pOVar13;
    puVar14 = auStack_68;
    if (param_2 != (LPCSTR)0x0) {
      lVar8 = -1;
      do {
        lVar9 = lVar8;
        lVar8 = lVar9 + 1;
      } while (param_2[lVar8] != '\0');
      iVar12 = (int)lVar9 + 2;
      puVar14 = auStack_68;
      if (iVar12 < 0x40000000) {
        lVar8 = (longlong)(int)lVar8 * 2;
        uVar11 = lVar8 + 0x11;
        if (uVar11 <= lVar8 + 2U) {
          uVar11 = 0xffffffffffffff0;
        }
        uStack_70 = 0x18005b59c;
        lVar8 = -(uVar11 & 0xfffffffffffffff0);
        pOVar1 = (LPCOLESTR)((longlong)&local_38 + lVar8);
        puVar14 = auStack_68 + lVar8;
        if (pOVar1 != (LPCOLESTR)0x0) {
          *(int *)((longlong)aiStack_40 + lVar8) = iVar12;
          *pOVar1 = L'\0';
          *(LPCOLESTR *)((longlong)&uStack_48 + lVar8) = pOVar1;
          *(undefined8 *)(auStack_68 + lVar8 + -8) = 0x18005b5c8;
          iVar12 = MultiByteToWideChar(0,0,param_2,-1,*(LPWSTR *)((longlong)&uStack_48 + lVar8),
                                       *(int *)((longlong)aiStack_40 + lVar8));
          szUserName = pOVar1;
          puVar14 = auStack_68 + lVar8;
          if (iVar12 == 0) {
            szUserName = pOVar13;
            puVar14 = auStack_68 + lVar8;
          }
        }
      }
    }
    pIVar5 = local_38;
    *(undefined8 *)(puVar14 + -8) = 0x18005b5e4;
    HVar7 = MkParseDisplayName(pIVar5,szUserName,param_3,param_4);
    pIVar5 = local_38;
    if (-1 < HVar7) {
      This = *param_4;
      *(longlong ***)(puVar14 + 0x20) = &local_30;
      pIVar5 = local_38;
      p_Var2 = This->lpVtbl->BindToObject;
      *(undefined8 *)(puVar14 + -8) = 0x18005b608;
      HVar7 = (*p_Var2)(This,pIVar5,(IMoniker *)0x0,(IID *)&DAT_180066db8,
                        *(void ***)(puVar14 + 0x20));
      plVar6 = local_30;
      if (-1 < HVar7) {
        pcVar3 = *(code **)(*local_30 + 0x78);
        *(undefined8 *)(puVar14 + -8) = 0x18005b619;
        (*pcVar3)(plVar6,param_5);
        pcVar3 = *(code **)(*local_30 + 0x10);
        *(undefined8 *)(puVar14 + -8) = 0x18005b623;
        (*pcVar3)();
      }
      uVar10 = 1;
      goto LAB_18005b636;
    }
    p_Var4 = local_38->lpVtbl->Release;
    *(undefined8 *)(puVar14 + -8) = 0x18005b634;
    (*p_Var4)(pIVar5);
  }
  uVar10 = 0;
LAB_18005b636:
  *(undefined8 *)(puVar14 + -8) = 0x18005b642;
  return uVar10;
}

/* ---- FUNC 0005B660 FUN_18005b660 (680 bytes) ---- */

ulonglong FUN_18005b660(longlong *param_1,longlong *param_2,longlong *param_3,undefined8 *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  int iVar6;
  int local_58;
  int local_54;
  uint local_50;
  longlong *local_48;
  longlong *local_40;
  longlong *local_38;
  longlong *local_30;
  
  iVar6 = 0;
  *param_4 = 0;
  if ((((param_1 == (longlong *)0x0) || (param_2 == (longlong *)0x0)) ||
      (param_3 == (longlong *)0x0)) ||
     ((iVar1 = (**(code **)(*param_3 + 0xb0))(param_3,&local_58), iVar1 < 0 || (local_58 != 1)))) {
    uVar5 = 0x80004005;
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0xb0))(param_1,&local_58);
    if ((iVar1 < 0) || (local_58 != 1)) {
      iVar1 = 1;
    }
    else {
      uVar5 = (**(code **)(*param_1 + 0x60))(param_1,1,&local_48);
      if ((int)uVar5 < 0) {
        return uVar5;
      }
      iVar2 = (**(code **)(*local_48 + 0x18))(local_48,1,&local_40,0);
      iVar1 = iVar6;
      while (iVar2 == 0) {
        iVar1 = iVar1 + 1;
        (**(code **)(*local_40 + 0x10))();
        iVar2 = (**(code **)(*local_48 + 0x18))(local_48,1,&local_40);
      }
      (**(code **)(*local_48 + 0x10))();
    }
    local_54 = 0;
    uVar5 = (**(code **)(*param_3 + 0x60))(param_3,0,&local_48);
    if (-1 < (int)uVar5) {
      iVar2 = (**(code **)(*local_48 + 0x18))(local_48,1,&local_40);
      while (iVar2 == 0) {
        iVar6 = iVar6 + 1;
        local_54 = iVar6;
        (**(code **)(*local_40 + 0x10))();
        iVar2 = (**(code **)(*local_48 + 0x18))(local_48,1,&local_40);
      }
      (**(code **)(*local_48 + 0x28))();
      uVar3 = (**(code **)(*local_48 + 0x18))(local_48,1,&local_38);
      if ((int)uVar3 < 0) {
        (**(code **)(*local_48 + 0x10))();
        return (ulonglong)uVar3;
      }
      uVar3 = 1;
      while( true ) {
        local_50 = uVar3;
        if ((uint)(iVar6 - iVar1) <= uVar3) {
          (**(code **)(*local_48 + 0x10))();
          (**(code **)(*param_2 + 0x58))(param_2,local_38,0,&local_30);
          (**(code **)(*local_38 + 0x10))();
          *param_4 = local_30;
          return 0;
        }
        uVar4 = (**(code **)(*local_48 + 0x18))(local_48,1);
        if ((int)uVar4 < 0) break;
        (**(code **)(*local_40 + 0x58))(local_40,local_38);
        (**(code **)(*local_40 + 0x10))();
        (**(code **)(*local_38 + 0x10))();
        local_38 = local_30;
        uVar3 = uVar3 + 1;
      }
      (**(code **)(*local_48 + 0x10))();
      return (ulonglong)uVar4;
    }
  }
  return uVar5;
}

/* ---- FUNC 0005B910 FUN_18005b910 (493 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HRESULT FUN_18005b910(LPCSTR param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  code *pcVar1;
  DWORD dwClsContext;
  longlong *plVar2;
  HRESULT HVar3;
  longlong lVar4;
  ulonglong uVar6;
  int iVar7;
  undefined1 *puVar8;
  LPCOLESTR lpszProgID;
  undefined8 uStack_f0;
  undefined1 auStack_e8 [32];
  undefined8 uStack_c8;
  int aiStack_c0 [10];
  longlong *local_98;
  undefined4 local_90 [2];
  undefined4 local_88;
  undefined4 local_84;
  wchar_t *local_80;
  undefined2 *local_78;
  undefined4 *local_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined2 local_60 [4];
  undefined8 local_58;
  undefined2 local_48;
  undefined8 local_40;
  CLSID local_30;
  ulonglong local_20;
  longlong lVar5;
  
  local_20 = DAT_180077818 ^ (ulonglong)&local_98;
  puVar8 = auStack_e8;
  if (param_1 != (LPCSTR)0x0) {
    lVar4 = -1;
    do {
      lVar5 = lVar4;
      lVar4 = lVar5 + 1;
    } while (param_1[lVar4] != '\0');
    iVar7 = (int)lVar5 + 2;
    puVar8 = auStack_e8;
    if (iVar7 < 0x40000000) {
      lVar4 = (longlong)(int)lVar4 * 2;
      uVar6 = lVar4 + 0x11;
      if (uVar6 <= lVar4 + 2U) {
        uVar6 = 0xffffffffffffff0;
      }
      uStack_f0 = 0x18005b99d;
      lVar4 = -(uVar6 & 0xfffffffffffffff0);
      puVar8 = auStack_e8 + lVar4;
      lpszProgID = (LPCOLESTR)((longlong)local_90 + lVar4 + -8);
      if (lpszProgID != (LPCOLESTR)0x0) {
        *(int *)((longlong)aiStack_c0 + lVar4) = iVar7;
        *lpszProgID = L'\0';
        *(LPCOLESTR *)((longlong)&uStack_c8 + lVar4) = lpszProgID;
        *(undefined8 *)(auStack_e8 + lVar4 + -8) = 0x18005b9c6;
        iVar7 = MultiByteToWideChar(0,0,param_1,-1,*(LPWSTR *)((longlong)&uStack_c8 + lVar4),
                                    *(int *)((longlong)aiStack_c0 + lVar4));
        puVar8 = auStack_e8 + lVar4;
        if (iVar7 == 0) {
          puVar8 = auStack_e8 + lVar4;
          lpszProgID = (LPCOLESTR)0x0;
        }
        goto LAB_18005b9d2;
      }
    }
  }
  lpszProgID = (LPCOLESTR)0x0;
LAB_18005b9d2:
  *(undefined8 *)(puVar8 + -8) = 0x18005b9df;
  HVar3 = CLSIDFromProgID(lpszProgID,&local_30);
  if (HVar3 == 0) {
    *(longlong ***)(puVar8 + 0x20) = &local_98;
    dwClsContext = 4;
    if (param_4 == 0) {
      dwClsContext = 1;
    }
    *(undefined8 *)(puVar8 + -8) = 0x18005ba11;
    HVar3 = CoCreateInstance(&local_30,(LPUNKNOWN)0x0,dwClsContext,(IID *)&DAT_180066c78,
                             *(LPVOID **)(puVar8 + 0x20));
    plVar2 = local_98;
    if (HVar3 == 0) {
      local_80 = L"Display";
      *(undefined4 **)(puVar8 + 0x28) = local_90;
      *(undefined4 *)(puVar8 + 0x20) = 0x800;
      pcVar1 = *(code **)(*plVar2 + 0x28);
      *(undefined8 *)(puVar8 + -8) = 0x18005ba4d;
      HVar3 = (*pcVar1)(plVar2,&DAT_180066d68,&local_80,1);
      plVar2 = local_98;
      if (HVar3 == 0) {
        *(undefined8 *)(puVar8 + 0x40) = 0;
        local_78 = local_60;
        *(undefined8 *)(puVar8 + 0x38) = 0;
        local_60[0] = 9;
        local_48 = 9;
        local_88 = 0;
        local_84 = 1;
        local_68 = 2;
        local_64 = 2;
        lVar4 = *plVar2;
        local_70 = &local_88;
        local_58 = param_2;
        local_40 = param_3;
        *(undefined8 *)(puVar8 + 0x30) = 0;
        *(undefined2 ***)(puVar8 + 0x28) = &local_78;
        *(undefined2 *)(puVar8 + 0x20) = 1;
        pcVar1 = *(code **)(lVar4 + 0x30);
        *(undefined8 *)(puVar8 + -8) = 0x18005bac1;
        HVar3 = (*pcVar1)(plVar2,local_90[0],&DAT_180066d68,0x800);
        pcVar1 = *(code **)(*local_98 + 0x10);
        *(undefined8 *)(puVar8 + -8) = 0x18005bacd;
        (*pcVar1)();
      }
    }
  }
  *(undefined8 *)(puVar8 + -8) = 0x18005badb;
  return HVar3;
}

/* ---- FUNC 0005BAFD GetDefaultCopyContent (6 bytes) ---- */

void GetDefaultCopyContent(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bafd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x5bafd  25  GetDefaultCopyContent */
  GetDefaultCopyContent();
  return;
}

/* ---- FUNC 0005BB03 MMAfxMessageBox (6 bytes) ---- */

int __cdecl MMAfxMessageBox(char *param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005bb03. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = MMAfxMessageBox(param_1,param_2,param_3,param_4);
  return iVar1;
}

/* ---- FUNC 0005BB09 MMSetSuppress (6 bytes) ---- */

void MMSetSuppress(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bb09. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MMSetSuppress();
  return;
}

/* ---- FUNC 0005BB0F MMGetSuppress (6 bytes) ---- */

void MMGetSuppress(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bb0f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MMGetSuppress();
  return;
}

/* ---- FUNC 0005BB15 GetGlobalPointer (6 bytes) ---- */

void GetGlobalPointer(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bb15. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetGlobalPointer();
  return;
}

/* ---- FUNC 0005BB1B APModLibGetValues (6 bytes) ---- */

void APModLibGetValues(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bb1b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  APModLibGetValues();
  return;
}

/* ---- FUNC 0005BB21 SESetSettingValue (6 bytes) ---- */

void SESetSettingValue(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bb21. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SESetSettingValue();
  return;
}

/* ---- FUNC 0005BB27 SetGlobalPointer (6 bytes) ---- */

void SetGlobalPointer(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bb27. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetGlobalPointer();
  return;
}

/* ---- FUNC 0005BB2D PostMainWndMessage (6 bytes) ---- */

void PostMainWndMessage(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bb2d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  PostMainWndMessage();
  return;
}

/* ---- FUNC 0005BB33 MMWaitFailed (6 bytes) ---- */

void MMWaitFailed(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bb33. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MMWaitFailed();
  return;
}

/* ---- FUNC 0005BB39 MMWaitFailureKey (6 bytes) ---- */

void MMWaitFailureKey(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bb39. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MMWaitFailureKey();
  return;
}

/* ---- FUNC 0005BB3F MMWaitFailureMessage (6 bytes) ---- */

void MMWaitFailureMessage(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bb3f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MMWaitFailureMessage();
  return;
}

/* ---- FUNC 0005BB45 MMGetLocalizedPrompt (6 bytes) ---- */

void MMGetLocalizedPrompt(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bb45. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MMGetLocalizedPrompt();
  return;
}

/* ---- FUNC 0005BB51 MDfree (6 bytes) ---- */

void MDfree(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bb51. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDfree();
  return;
}

/* ---- FUNC 0005BB57 MDmalloc (6 bytes) ---- */

void MDmalloc(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bb57. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDmalloc();
  return;
}

/* ---- FUNC 0005BB5D GRchkitm (6 bytes) ---- */

void GRchkitm(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bb5d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRchkitm();
  return;
}

/* ---- FUNC 0005BB63 export_MM_file_MAX (6 bytes) ---- */

void export_MM_file_MAX(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bb63. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  export_MM_file_MAX();
  return;
}

/* ---- FUNC 0005BB69 GRsetgfl (6 bytes) ---- */

void GRsetgfl(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bb69. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetgfl();
  return;
}

/* ---- FUNC 0005BB6F OnSubflowsheetChange (6 bytes) ---- */

void OnSubflowsheetChange(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bb6f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OnSubflowsheetChange();
  return;
}

/* ---- FUNC 0005BB75 RLrcnall (6 bytes) ---- */

void RLrcnall(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bb75. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RLrcnall();
  return;
}

/* ---- FUNC 0005BB7B GetNextAvailableDatabank (6 bytes) ---- */

void GetNextAvailableDatabank(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bb7b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetNextAvailableDatabank();
  return;
}

/* ---- FUNC 0005BB81 GetNextDefaultDatabank (6 bytes) ---- */

void GetNextDefaultDatabank(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bb81. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetNextDefaultDatabank();
  return;
}

/* ---- FUNC 0005BB87 SetQueryForComponents_Mmg (6 bytes) ---- */

void SetQueryForComponents_Mmg(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bb87. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetQueryForComponents_Mmg();
  return;
}

/* ---- FUNC 0005BB8D FetchNextComponent_Mmg (6 bytes) ---- */

void FetchNextComponent_Mmg(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bb8d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FetchNextComponent_Mmg();
  return;
}

/* ---- FUNC 0005BB93 GRinqsme (6 bytes) ---- */

void GRinqsme(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bb93. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqsme();
  return;
}

/* ---- FUNC 0005BB99 GRinqautorun (6 bytes) ---- */

void GRinqautorun(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bb99. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqautorun();
  return;
}

/* ---- FUNC 0005BB9F AutoRunEngSim (6 bytes) ---- */

void AutoRunEngSim(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bb9f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AutoRunEngSim();
  return;
}

/* ---- FUNC 0005BBA5 GRinqinmt (6 bytes) ---- */

void GRinqinmt(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bba5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqinmt();
  return;
}

/* ---- FUNC 0005BBAB gxDriveDialog (6 bytes) ---- */

void gxDriveDialog(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bbab. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  gxDriveDialog();
  return;
}

/* ---- FUNC 0005BBB1 HAOnUpdateMessage (6 bytes) ---- */

void HAOnUpdateMessage(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bbb1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HAOnUpdateMessage();
  return;
}

/* ---- FUNC 0005BBB7 HAGetAttrNum (6 bytes) ---- */

void HAGetAttrNum(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bbb7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HAGetAttrNum();
  return;
}

/* ---- FUNC 0005BBBD Ordinal_41 (6 bytes) ---- */

void Ordinal_41(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bbbd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_41();
  return;
}

/* ---- FUNC 0005BBC3 Ordinal_42 (6 bytes) ---- */

void Ordinal_42(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bbc3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_42();
  return;
}

/* ---- FUNC 0005BBFF Ordinal_83 (6 bytes) ---- */

void Ordinal_83(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bbff. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_83();
  return;
}

/* ---- FUNC 0005BC29 Ordinal_40 (6 bytes) ---- */

void Ordinal_40(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bc29. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_40();
  return;
}

/* ---- FUNC 0005BC2F Ordinal_82 (6 bytes) ---- */

void Ordinal_82(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bc2f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_82();
  return;
}

/* ---- FUNC 0005BC35 Ordinal_84 (6 bytes) ---- */

void Ordinal_84(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bc35. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_84();
  return;
}

/* ---- FUNC 0005BC3B Ordinal_73 (6 bytes) ---- */

void Ordinal_73(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bc3b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_73();
  return;
}

/* ---- FUNC 0005BC41 Ordinal_74 (6 bytes) ---- */

void Ordinal_74(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bc41. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_74();
  return;
}

/* ---- FUNC 0005BC47 Ordinal_75 (6 bytes) ---- */

void Ordinal_75(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bc47. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_75();
  return;
}

/* ---- FUNC 0005BC4D Ordinal_76 (6 bytes) ---- */

void Ordinal_76(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bc4d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_76();
  return;
}

/* ---- FUNC 0005BC53 Ordinal_78 (6 bytes) ---- */

void Ordinal_78(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bc53. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_78();
  return;
}

/* ---- FUNC 0005BC59 Ordinal_77 (6 bytes) ---- */

void Ordinal_77(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bc59. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_77();
  return;
}

/* ---- FUNC 0005BC5F Ordinal_79 (6 bytes) ---- */

void Ordinal_79(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bc5f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_79();
  return;
}

/* ---- FUNC 0005BC65 Ordinal_80 (6 bytes) ---- */

void Ordinal_80(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bc65. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_80();
  return;
}

/* ---- FUNC 0005BC6B Ordinal_81 (6 bytes) ---- */

void Ordinal_81(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bc6b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_81();
  return;
}

/* ---- FUNC 0005BC71 Ordinal_85 (6 bytes) ---- */

void Ordinal_85(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bc71. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_85();
  return;
}

/* ---- FUNC 0005BC77 Ordinal_99 (6 bytes) ---- */

void Ordinal_99(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bc77. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_99();
  return;
}

/* ---- FUNC 0005BC7D Ordinal_102 (6 bytes) ---- */

void Ordinal_102(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bc7d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_102();
  return;
}

/* ---- FUNC 0005BC83 Ordinal_104 (6 bytes) ---- */

void Ordinal_104(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bc83. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_104();
  return;
}

/* ---- FUNC 0005BC89 Ordinal_129 (6 bytes) ---- */

void Ordinal_129(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bc89. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_129();
  return;
}

/* ---- FUNC 0005BC8F Ordinal_119 (6 bytes) ---- */

void Ordinal_119(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bc8f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_119();
  return;
}

/* ---- FUNC 0005BC95 Ordinal_123 (6 bytes) ---- */

void Ordinal_123(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bc95. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_123();
  return;
}

/* ---- FUNC 0005BC9B Ordinal_151 (6 bytes) ---- */

void Ordinal_151(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bc9b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_151();
  return;
}

/* ---- FUNC 0005BCA1 Ordinal_178 (6 bytes) ---- */

void Ordinal_178(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bca1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_178();
  return;
}

/* ---- FUNC 0005BCA7 Ordinal_106 (6 bytes) ---- */

void Ordinal_106(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bca7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_106();
  return;
}

/* ---- FUNC 0005BCAD Ordinal_128 (6 bytes) ---- */

void Ordinal_128(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bcad. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_128();
  return;
}

/* ---- FUNC 0005BCB3 Ordinal_112 (6 bytes) ---- */

void Ordinal_112(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bcb3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_112();
  return;
}

/* ---- FUNC 0005BCB9 Ordinal_131 (6 bytes) ---- */

void Ordinal_131(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bcb9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_131();
  return;
}

/* ---- FUNC 0005BCBF MVGetProductCode (6 bytes) ---- */

void MVGetProductCode(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bcbf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MVGetProductCode();
  return;
}

/* ---- FUNC 0005BCC5 MVGetVersionString (6 bytes) ---- */

void MVGetVersionString(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bcc5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MVGetVersionString();
  return;
}

/* ---- FUNC 0005BCCB MVGetProductName (6 bytes) ---- */

void MVGetProductName(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bccb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MVGetProductName();
  return;
}

/* ---- FUNC 0005BCD1 operator_new (6 bytes) ---- */

void * __cdecl operator_new(__uint64 param_1)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005bcd1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = operator_new(param_1);
  return pvVar1;
}

/* ---- FUNC 0005BCD7 AfxThrowMemoryException (6 bytes) ---- */

void __cdecl AfxThrowMemoryException(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bcd7. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  AfxThrowMemoryException();
  return;
}

/* ---- FUNC 0005BCDD AfxThrowInvalidArgException (6 bytes) ---- */

void __cdecl AfxThrowInvalidArgException(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bcdd. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  AfxThrowInvalidArgException();
  return;
}

/* ---- FUNC 0005BCE3 AfxThrowOleException (6 bytes) ---- */

void __cdecl AfxThrowOleException(long param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bce3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AfxThrowOleException(param_1);
  return;
}

/* ---- FUNC 0005BCEF CStringArray (6 bytes) ---- */

void __thiscall CStringArray::CStringArray(CStringArray *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bcef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CStringArray(this);
  return;
}

/* ---- FUNC 0005BCF5 SetAtGrow (6 bytes) ---- */

void __thiscall
CStringArray::SetAtGrow
          (CStringArray *this,__int64 param_1,
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bcf5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetAtGrow(this,param_1,param_2);
  return;
}

/* ---- FUNC 0005BCFB ~CStringArray (6 bytes) ---- */

void __thiscall CStringArray::~CStringArray(CStringArray *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bcfb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CStringArray(this);
  return;
}

/* ---- FUNC 0005BD01 operator_delete (6 bytes) ---- */

void __cdecl operator_delete(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bd01. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete(param_1);
  return;
}

/* ---- FUNC 0005BD07 CDWordArray (6 bytes) ---- */

void __thiscall CDWordArray::CDWordArray(CDWordArray *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bd07. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CDWordArray(this);
  return;
}

/* ---- FUNC 0005BD0D SetAtGrow (6 bytes) ---- */

void __thiscall CDWordArray::SetAtGrow(CDWordArray *this,__int64 param_1,ulong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bd0d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetAtGrow(this,param_1,param_2);
  return;
}

/* ---- FUNC 0005BD13 ~CDWordArray (6 bytes) ---- */

void __thiscall CDWordArray::~CDWordArray(CDWordArray *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bd13. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CDWordArray(this);
  return;
}

/* ---- FUNC 0005BD19 GetRuntimeClass (6 bytes) ---- */

CRuntimeClass * __thiscall CPtrArray::GetRuntimeClass(CPtrArray *this)

{
  CRuntimeClass *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005bd19. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetRuntimeClass(this);
  return pCVar1;
}

/* ---- FUNC 0005BD1F CPtrArray (6 bytes) ---- */

void __thiscall CPtrArray::CPtrArray(CPtrArray *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bd1f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CPtrArray(this);
  return;
}

/* ---- FUNC 0005BD25 SetSize (6 bytes) ---- */

void __thiscall CPtrArray::SetSize(CPtrArray *this,__int64 param_1,__int64 param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bd25. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetSize(this,param_1,param_2);
  return;
}

/* ---- FUNC 0005BD2B SetAtGrow (6 bytes) ---- */

void __thiscall CPtrArray::SetAtGrow(CPtrArray *this,__int64 param_1,void *param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bd2b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetAtGrow(this,param_1,param_2);
  return;
}

/* ---- FUNC 0005BD31 InsertAt (6 bytes) ---- */

void __thiscall CPtrArray::InsertAt(CPtrArray *this,__int64 param_1,void *param_2,__int64 param_3)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bd31. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InsertAt(this,param_1,param_2,param_3);
  return;
}

/* ---- FUNC 0005BD37 RemoveAt (6 bytes) ---- */

void __thiscall CPtrArray::RemoveAt(CPtrArray *this,__int64 param_1,__int64 param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bd37. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RemoveAt(this,param_1,param_2);
  return;
}

/* ---- FUNC 0005BD3D ~CPtrArray (6 bytes) ---- */

void __thiscall CPtrArray::~CPtrArray(CPtrArray *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bd3d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CPtrArray(this);
  return;
}

/* ---- FUNC 0005BD43 AfxVariantInit (6 bytes) ---- */

void __cdecl AfxVariantInit(tagVARIANT *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bd43. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AfxVariantInit(param_1);
  return;
}

/* ---- FUNC 0005BD49 operator_new[] (6 bytes) ---- */

void * __cdecl operator_new__(__uint64 param_1)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005bd49. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = operator_new__(param_1);
  return pvVar1;
}

/* ---- FUNC 0005BD4F operator_delete[] (6 bytes) ---- */

void __cdecl operator_delete__(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bd4f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete__(param_1);
  return;
}

/* ---- FUNC 0005BD55 Delete (6 bytes) ---- */

void __thiscall CException::Delete(CException *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bd55. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Delete(this);
  return;
}

/* ---- FUNC 0005BD5B AfxTryCleanup (6 bytes) ---- */

void __cdecl AfxTryCleanup(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bd5b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AfxTryCleanup();
  return;
}

/* ---- FUNC 0005BD61 AFX_EXCEPTION_LINK (6 bytes) ---- */

void __thiscall AFX_EXCEPTION_LINK::AFX_EXCEPTION_LINK(AFX_EXCEPTION_LINK *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bd61. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AFX_EXCEPTION_LINK(this);
  return;
}

/* ---- FUNC 0005BD67 SetSize (6 bytes) ---- */

void __thiscall CStringArray::SetSize(CStringArray *this,__int64 param_1,__int64 param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bd67. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetSize(this,param_1,param_2);
  return;
}

/* ---- FUNC 0005BD6D SetAtGrow (6 bytes) ---- */

void __thiscall CStringArray::SetAtGrow(CStringArray *this,__int64 param_1,char *param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bd6d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetAtGrow(this,param_1,param_2);
  return;
}

/* ---- FUNC 0005BD73 CPtrList (6 bytes) ---- */

void __thiscall CPtrList::CPtrList(CPtrList *this,__int64 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bd73. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CPtrList(this,param_1);
  return;
}

/* ---- FUNC 0005BD79 AddHead (6 bytes) ---- */

__POSITION * __thiscall CPtrList::AddHead(CPtrList *this,void *param_1)

{
  __POSITION *p_Var1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005bd79. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  p_Var1 = AddHead(this,param_1);
  return p_Var1;
}

/* ---- FUNC 0005BD7F RemoveAll (6 bytes) ---- */

void __thiscall CPtrList::RemoveAll(CPtrList *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bd7f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RemoveAll(this);
  return;
}

/* ---- FUNC 0005BD85 Find (6 bytes) ---- */

__POSITION * __thiscall CPtrList::Find(CPtrList *this,void *param_1,__POSITION *param_2)

{
  __POSITION *p_Var1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005bd85. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  p_Var1 = Find(this,param_1,param_2);
  return p_Var1;
}

/* ---- FUNC 0005BD8B ~CPtrList (6 bytes) ---- */

void __thiscall CPtrList::~CPtrList(CPtrList *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bd8b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CPtrList(this);
  return;
}

/* ---- FUNC 0005BD91 CStringList (6 bytes) ---- */

void __thiscall CStringList::CStringList(CStringList *this,__int64 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bd91. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CStringList(this,param_1);
  return;
}

/* ---- FUNC 0005BD97 AddTail (6 bytes) ---- */

__POSITION * __thiscall CStringList::AddTail(CStringList *this,char *param_1)

{
  __POSITION *p_Var1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005bd97. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  p_Var1 = AddTail(this,param_1);
  return p_Var1;
}

/* ---- FUNC 0005BD9D ~CStringList (6 bytes) ---- */

void __thiscall CStringList::~CStringList(CStringList *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bd9d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CStringList(this);
  return;
}

/* ---- FUNC 0005BDA3 CMapStringToPtr (6 bytes) ---- */

void __thiscall CMapStringToPtr::CMapStringToPtr(CMapStringToPtr *this,__int64 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bda3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CMapStringToPtr(this,param_1);
  return;
}

/* ---- FUNC 0005BDA9 Lookup (6 bytes) ---- */

int __thiscall CMapStringToPtr::Lookup(CMapStringToPtr *this,char *param_1,void **param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005bda9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = Lookup(this,param_1,param_2);
  return iVar1;
}

/* ---- FUNC 0005BDAF operator[] (6 bytes) ---- */

void ** __thiscall CMapStringToPtr::operator[](CMapStringToPtr *this,char *param_1)

{
  void **ppvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005bdaf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ppvVar1 = operator[](this,param_1);
  return ppvVar1;
}

/* ---- FUNC 0005BDB5 RemoveKey (6 bytes) ---- */

int __thiscall CMapStringToPtr::RemoveKey(CMapStringToPtr *this,char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005bdb5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = RemoveKey(this,param_1);
  return iVar1;
}

/* ---- FUNC 0005BDBB RemoveAll (6 bytes) ---- */

void __thiscall CMapStringToPtr::RemoveAll(CMapStringToPtr *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bdbb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RemoveAll(this);
  return;
}

/* ---- FUNC 0005BDC1 GetNextAssoc (6 bytes) ---- */

void __thiscall
CMapStringToPtr::GetNextAssoc
          (CMapStringToPtr *this,__POSITION **param_1,
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2,void **param_3)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bdc1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetNextAssoc(this,param_1,param_2,param_3);
  return;
}

/* ---- FUNC 0005BDC7 ~CMapStringToPtr (6 bytes) ---- */

void __thiscall CMapStringToPtr::~CMapStringToPtr(CMapStringToPtr *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bdc7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CMapStringToPtr(this);
  return;
}

/* ---- FUNC 0005BDCD COleDispatchDriver (6 bytes) ---- */

void __thiscall COleDispatchDriver::COleDispatchDriver(COleDispatchDriver *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bdcd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  COleDispatchDriver(this);
  return;
}

/* ---- FUNC 0005BDD3 AttachDispatch (6 bytes) ---- */

void __thiscall
COleDispatchDriver::AttachDispatch(COleDispatchDriver *this,IDispatch *param_1,int param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bdd3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AttachDispatch(this,param_1,param_2);
  return;
}

/* ---- FUNC 0005BDD9 ReleaseDispatch (6 bytes) ---- */

void __thiscall COleDispatchDriver::ReleaseDispatch(COleDispatchDriver *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bdd9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ReleaseDispatch(this);
  return;
}

/* ---- FUNC 0005BDDF InvokeHelper (6 bytes) ---- */

void __thiscall
COleDispatchDriver::InvokeHelper
          (COleDispatchDriver *this,long param_1,ushort param_2,ushort param_3,void *param_4,
          uchar *param_5,...)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bddf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InvokeHelper(this,param_1,param_2,param_3,param_4,param_5);
  return;
}

/* ---- FUNC 0005BDE5 SetSize (6 bytes) ---- */

void __thiscall CDWordArray::SetSize(CDWordArray *this,__int64 param_1,__int64 param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bde5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetSize(this,param_1,param_2);
  return;
}

/* ---- FUNC 0005BDEB Copy (6 bytes) ---- */

void __thiscall CPtrArray::Copy(CPtrArray *this,CPtrArray *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bdeb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Copy(this,param_1);
  return;
}

/* ---- FUNC 0005BDF1 GetRuntimeClass (6 bytes) ---- */

CRuntimeClass * __thiscall CCmdTarget::GetRuntimeClass(CCmdTarget *this)

{
  CRuntimeClass *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005bdf1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetRuntimeClass(this);
  return pCVar1;
}

/* ---- FUNC 0005BDF7 OnCmdMsg (6 bytes) ---- */

int __thiscall
CCmdTarget::OnCmdMsg
          (CCmdTarget *this,uint param_1,int param_2,void *param_3,AFX_CMDHANDLERINFO *param_4)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005bdf7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnCmdMsg(this,param_1,param_2,param_3,param_4);
  return iVar1;
}

/* ---- FUNC 0005BDFD OnFinalRelease (6 bytes) ---- */

void __thiscall CCmdTarget::OnFinalRelease(CCmdTarget *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bdfd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OnFinalRelease(this);
  return;
}

/* ---- FUNC 0005BE03 IsInvokeAllowed (6 bytes) ---- */

int __thiscall CCmdTarget::IsInvokeAllowed(CCmdTarget *this,long param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005be03. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = IsInvokeAllowed(this,param_1);
  return iVar1;
}

/* ---- FUNC 0005BE09 GetDispatchIID (6 bytes) ---- */

int __thiscall CCmdTarget::GetDispatchIID(CCmdTarget *this,_GUID *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005be09. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = GetDispatchIID(this,param_1);
  return iVar1;
}

/* ---- FUNC 0005BE0F GetTypeInfoCount (6 bytes) ---- */

uint __thiscall CCmdTarget::GetTypeInfoCount(CCmdTarget *this)

{
  uint uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005be0f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = GetTypeInfoCount(this);
  return uVar1;
}

/* ---- FUNC 0005BE15 GetTypeLibCache (6 bytes) ---- */

CTypeLibCache * __thiscall CCmdTarget::GetTypeLibCache(CCmdTarget *this)

{
  CTypeLibCache *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005be15. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetTypeLibCache(this);
  return pCVar1;
}

/* ---- FUNC 0005BE1B GetTypeLib (6 bytes) ---- */

long __thiscall CCmdTarget::GetTypeLib(CCmdTarget *this,ulong param_1,ITypeLib **param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005be1b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = GetTypeLib(this,param_1,param_2);
  return lVar1;
}

/* ---- FUNC 0005BE21 GetMessageMap (6 bytes) ---- */

AFX_MSGMAP * __thiscall CCmdTarget::GetMessageMap(CCmdTarget *this)

{
  AFX_MSGMAP *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005be21. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = GetMessageMap(this);
  return pAVar1;
}

/* ---- FUNC 0005BE27 GetCommandMap (6 bytes) ---- */

AFX_OLECMDMAP * __thiscall CCmdTarget::GetCommandMap(CCmdTarget *this)

{
  AFX_OLECMDMAP *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005be27. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = GetCommandMap(this);
  return pAVar1;
}

/* ---- FUNC 0005BE2D GetDispatchMap (6 bytes) ---- */

AFX_DISPMAP * __thiscall CCmdTarget::GetDispatchMap(CCmdTarget *this)

{
  AFX_DISPMAP *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005be2d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = GetDispatchMap(this);
  return pAVar1;
}

/* ---- FUNC 0005BE33 GetConnectionMap (6 bytes) ---- */

AFX_CONNECTIONMAP * __thiscall CCmdTarget::GetConnectionMap(CCmdTarget *this)

{
  AFX_CONNECTIONMAP *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005be33. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = GetConnectionMap(this);
  return pAVar1;
}

/* ---- FUNC 0005BE3F GetEventSinkMap (6 bytes) ---- */

AFX_EVENTSINKMAP * __thiscall CCmdTarget::GetEventSinkMap(CCmdTarget *this)

{
  AFX_EVENTSINKMAP *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005be3f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = GetEventSinkMap(this);
  return pAVar1;
}

/* ---- FUNC 0005BE45 OnCreateAggregates (6 bytes) ---- */

int __thiscall CCmdTarget::OnCreateAggregates(CCmdTarget *this)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005be45. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnCreateAggregates(this);
  return iVar1;
}

/* ---- FUNC 0005BE4B GetInterfaceHook (6 bytes) ---- */

IUnknown * __thiscall CCmdTarget::GetInterfaceHook(CCmdTarget *this,void *param_1)

{
  IUnknown *pIVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005be4b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pIVar1 = GetInterfaceHook(this,param_1);
  return pIVar1;
}

/* ---- FUNC 0005BE51 GetExtraConnectionPoints (6 bytes) ---- */

int __thiscall CCmdTarget::GetExtraConnectionPoints(CCmdTarget *this,CPtrArray *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005be51. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = GetExtraConnectionPoints(this,param_1);
  return iVar1;
}

/* ---- FUNC 0005BE57 GetConnectionHook (6 bytes) ---- */

IConnectionPoint * __thiscall CCmdTarget::GetConnectionHook(CCmdTarget *this,_GUID *param_1)

{
  IConnectionPoint *pIVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005be57. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pIVar1 = GetConnectionHook(this,param_1);
  return pIVar1;
}

/* ---- FUNC 0005BE5D CEnumArray (6 bytes) ---- */

void __thiscall
CEnumArray::CEnumArray(CEnumArray *this,__uint64 param_1,void *param_2,uint param_3,int param_4)

{
                    /* WARNING: Could not recover jumptable at 0x00018005be5d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CEnumArray(this,param_1,param_2,param_3,param_4);
  return;
}

/* ---- FUNC 0005BE63 ~CEnumArray (6 bytes) ---- */

void __thiscall CEnumArray::~CEnumArray(CEnumArray *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018005be63. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CEnumArray(this);
  return;
}

/* ---- FUNC 0005BE69 OnNext (6 bytes) ---- */

int __thiscall CEnumArray::OnNext(CEnumArray *this,void *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005be69. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnNext(this,param_1);
  return iVar1;
}

/* ---- FUNC 0005BE6F OnSkip (6 bytes) ---- */

int __thiscall CEnumArray::OnSkip(CEnumArray *this)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005be6f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnSkip(this);
  return iVar1;
}

/* ---- FUNC 0005BE75 OnReset (6 bytes) ---- */

void __thiscall CEnumArray::OnReset(CEnumArray *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018005be75. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OnReset(this);
  return;
}

/* ---- FUNC 0005BE7B OnClone (6 bytes) ---- */

CEnumArray * __thiscall CEnumArray::OnClone(CEnumArray *this)

{
  CEnumArray *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005be7b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = OnClone(this);
  return pCVar1;
}

/* ---- FUNC 0005BE81 AfxThrowArchiveException (6 bytes) ---- */

void __cdecl AfxThrowArchiveException(int param_1,char *param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00018005be81. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AfxThrowArchiveException(param_1,param_2);
  return;
}

/* ---- FUNC 0005BE87 GetRuntimeClass (6 bytes) ---- */

CRuntimeClass * __thiscall CObject::GetRuntimeClass(CObject *this)

{
  CRuntimeClass *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005be87. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetRuntimeClass(this);
  return pCVar1;
}

/* ---- FUNC 0005BE8D CArchive (6 bytes) ---- */

void __thiscall
CArchive::CArchive(CArchive *this,CFile *param_1,uint param_2,int param_3,void *param_4)

{
                    /* WARNING: Could not recover jumptable at 0x00018005be8d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CArchive(this,param_1,param_2,param_3,param_4);
  return;
}

/* ---- FUNC 0005BE93 ~CArchive (6 bytes) ---- */

void __thiscall CArchive::~CArchive(CArchive *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018005be93. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CArchive(this);
  return;
}

/* ---- FUNC 0005BE99 Read (6 bytes) ---- */

uint __thiscall CArchive::Read(CArchive *this,void *param_1,uint param_2)

{
  uint uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005be99. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = Read(this,param_1,param_2);
  return uVar1;
}

/* ---- FUNC 0005BE9F Write (6 bytes) ---- */

void __thiscall CArchive::Write(CArchive *this,void *param_1,uint param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00018005be9f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Write(this,param_1,param_2);
  return;
}

/* ---- FUNC 0005BEA5 Close (6 bytes) ---- */

void __thiscall CArchive::Close(CArchive *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bea5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Close(this);
  return;
}

/* ---- FUNC 0005BEAB ReadCount (6 bytes) ---- */

__uint64 __thiscall CArchive::ReadCount(CArchive *this)

{
  __uint64 _Var1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005beab. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = ReadCount(this);
  return _Var1;
}

/* ---- FUNC 0005BEB1 WriteCount (6 bytes) ---- */

void __thiscall CArchive::WriteCount(CArchive *this,__uint64 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018005beb1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WriteCount(this,param_1);
  return;
}

/* ---- FUNC 0005BEB7 RemoveAt (6 bytes) ---- */

void __thiscall CDWordArray::RemoveAt(CDWordArray *this,__int64 param_1,__int64 param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00018005beb7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RemoveAt(this,param_1,param_2);
  return;
}

/* ---- FUNC 0005BEBD RemoveAt (6 bytes) ---- */

void __thiscall CStringArray::RemoveAt(CStringArray *this,__int64 param_1,__int64 param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bebd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RemoveAt(this,param_1,param_2);
  return;
}

/* ---- FUNC 0005BEC3 CMapWordToPtr (6 bytes) ---- */

void __thiscall CMapWordToPtr::CMapWordToPtr(CMapWordToPtr *this,__int64 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bec3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CMapWordToPtr(this,param_1);
  return;
}

/* ---- FUNC 0005BEC9 Lookup (6 bytes) ---- */

int __thiscall CMapWordToPtr::Lookup(CMapWordToPtr *this,ushort param_1,void **param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005bec9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = Lookup(this,param_1,param_2);
  return iVar1;
}

/* ---- FUNC 0005BECF operator[] (6 bytes) ---- */

void ** __thiscall CMapWordToPtr::operator[](CMapWordToPtr *this,ushort param_1)

{
  void **ppvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005becf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ppvVar1 = operator[](this,param_1);
  return ppvVar1;
}

/* ---- FUNC 0005BED5 RemoveAll (6 bytes) ---- */

void __thiscall CMapWordToPtr::RemoveAll(CMapWordToPtr *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bed5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RemoveAll(this);
  return;
}

/* ---- FUNC 0005BEDB GetNextAssoc (6 bytes) ---- */

void __thiscall
CMapWordToPtr::GetNextAssoc(CMapWordToPtr *this,__POSITION **param_1,ushort *param_2,void **param_3)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bedb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetNextAssoc(this,param_1,param_2,param_3);
  return;
}

/* ---- FUNC 0005BEE1 ~CMapWordToPtr (6 bytes) ---- */

void __thiscall CMapWordToPtr::~CMapWordToPtr(CMapWordToPtr *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bee1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CMapWordToPtr(this);
  return;
}

/* ---- FUNC 0005BEE7 ChangeType (6 bytes) ---- */

void __thiscall COleVariant::ChangeType(COleVariant *this,ushort param_1,tagVARIANT *param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bee7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ChangeType(this,param_1,param_2);
  return;
}

/* ---- FUNC 0005BEED COleStreamFile (6 bytes) ---- */

void __thiscall COleStreamFile::COleStreamFile(COleStreamFile *this,IStream *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018005beed. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  COleStreamFile(this,param_1);
  return;
}

/* ---- FUNC 0005BEF3 Attach (6 bytes) ---- */

void __thiscall COleStreamFile::Attach(COleStreamFile *this,IStream *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bef3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Attach(this,param_1);
  return;
}

/* ---- FUNC 0005BEF9 Detach (6 bytes) ---- */

IStream * __thiscall COleStreamFile::Detach(COleStreamFile *this)

{
  IStream *pIVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005bef9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pIVar1 = Detach(this);
  return pIVar1;
}

/* ---- FUNC 0005BEFF ~COleStreamFile (6 bytes) ---- */

void __thiscall COleStreamFile::~COleStreamFile(COleStreamFile *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018005beff. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~COleStreamFile(this);
  return;
}

/* ---- FUNC 0005BF08 __GSHandlerCheck (29 bytes) ---- */

/* Library Function - Single Match
    __GSHandlerCheck
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}

/* ---- FUNC 0005BF28 __GSHandlerCheckCommon (91 bytes) ---- */

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

/* ---- FUNC 0005BF84 FID_conflict:__GSHandlerCheck_EH (127 bytes) ---- */

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

/* ---- FUNC 0005C004 __GSHandlerCheck_SEH (133 bytes) ---- */

/* Library Function - Single Match
    __GSHandlerCheck_SEH
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __GSHandlerCheck_SEH
               (_EXCEPTION_RECORD *param_1,void *param_2,_CONTEXT *param_3,
               _DISPATCHER_CONTEXT *param_4)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = *(uint **)(param_4 + 0x38);
  uVar1 = *puVar2;
  __GSHandlerCheckCommon(param_2,(longlong)param_4);
  if ((puVar2[(ulonglong)uVar1 * 4 + 1] & ((param_1->ExceptionFlags & 0x66) != 0) + 1) != 0) {
    __C_specific_handler(param_1,param_2,param_3,param_4);
  }
  return;
}

/* ---- FUNC 0005C0A0 __chkstk (78 bytes) ---- */

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

/* ---- FUNC 0005C100 __security_check_cookie (30 bytes) ---- */

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie == DAT_180077818) && ((short)(_StackCookie >> 0x30) == 0)) {
    return;
  }
  FUN_18005c180();
  return;
}

/* ---- FUNC 0005C120 FUN_18005c120 (43 bytes) ---- */

undefined8 * FUN_18005c120(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = type_info::vftable;
  if ((param_2 & 1) != 0) {
    FUN_180025ad0(param_1);
  }
  return param_1;
}

/* ---- FUNC 0005C14C __raise_securityfailure (52 bytes) ---- */

/* Library Function - Single Match
    __raise_securityfailure
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __raise_securityfailure(_EXCEPTION_POINTERS *param_1)

{
  HANDLE pvVar1;
  
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter(param_1);
  pvVar1 = GetCurrentProcess();
                    /* WARNING: Could not recover jumptable at 0x00018005c179. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TerminateProcess(pvVar1,0xc0000409);
  return;
}

/* ---- FUNC 0005C180 FUN_18005c180 (210 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_18005c180(void)

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
  *(undefined8 *)(puVar3 + -8) = 0x18005c1ab;
  capture_previous_context((PCONTEXT)&DAT_18007a0c0);
  _DAT_18007a030 = *(undefined8 *)(puVar3 + 0x38);
  _DAT_18007a158 = puVar3 + 0x40;
  _DAT_18007a140 = *(undefined8 *)(puVar3 + 0x40);
  _DAT_18007a020 = 0xc0000409;
  _DAT_18007a024 = 1;
  _DAT_18007a038 = 1;
  DAT_18007a040 = 2;
  *(undefined8 *)(puVar3 + 0x20) = DAT_180077818;
  *(undefined8 *)(puVar3 + 0x28) = DAT_180077810;
  *(undefined8 *)(puVar3 + -8) = 0x18005c24d;
  DAT_18007a1b8 = _DAT_18007a030;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_180066c40);
  return;
}

/* ---- FUNC 0005C254 FUN_18005c254 (19 bytes) ---- */

void FUN_18005c254(void)

{
  FUN_18005c268(8);
  return;
}

/* ---- FUNC 0005C268 FUN_18005c268 (156 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_18005c268(undefined4 param_1)

{
  code *pcVar1;
  BOOL BVar2;
  undefined1 *puVar3;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [32];
  
  puVar3 = auStack_28;
  BVar2 = IsProcessorFeaturePresent(0x17);
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(param_1);
    puVar3 = auStack_20;
  }
  *(undefined8 *)(puVar3 + -8) = 0x18005c293;
  capture_current_context((PCONTEXT)&DAT_18007a0c0);
  _DAT_18007a030 = *(undefined8 *)(puVar3 + 0x28);
  _DAT_18007a158 = puVar3 + 0x30;
  _DAT_18007a020 = 0xc0000409;
  _DAT_18007a024 = 1;
  _DAT_18007a038 = 1;
  DAT_18007a040 = (ulonglong)*(uint *)(puVar3 + 0x30);
  *(undefined8 *)(puVar3 + -8) = 0x18005c2ff;
  DAT_18007a1b8 = _DAT_18007a030;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_180066c40);
  return;
}

/* ---- FUNC 0005C304 capture_current_context (109 bytes) ---- */

/* Library Function - Single Match
    capture_current_context
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void capture_current_context(PCONTEXT param_1)

{
  DWORD64 ControlPc;
  PRUNTIME_FUNCTION FunctionEntry;
  DWORD64 local_res8;
  ulonglong local_res10;
  PVOID local_res18;
  
  RtlCaptureContext();
  ControlPc = param_1->Rip;
  FunctionEntry = RtlLookupFunctionEntry(ControlPc,&local_res8,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry != (PRUNTIME_FUNCTION)0x0) {
    RtlVirtualUnwind(0,local_res8,ControlPc,FunctionEntry,param_1,&local_res18,&local_res10,
                     (PKNONVOLATILE_CONTEXT_POINTERS)0x0);
  }
  return;
}

/* ---- FUNC 0005C374 capture_previous_context (113 bytes) ---- */

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

/* ---- FUNC 0005C3E8 FUN_18005c3e8 (14 bytes) ---- */

void FUN_18005c3e8(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005c3ef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InitializeSListHead(&DAT_18007a590);
  return;
}

/* ---- FUNC 0005C3F8 FUN_18005c3f8 (12 bytes) ---- */

void FUN_18005c3f8(void)

{
  __std_type_info_destroy_list(&DAT_18007a590);
  return;
}

/* ---- FUNC 0005C404 `eh_vector_constructor_iterator' (112 bytes) ---- */

/* Library Function - Single Match
    void __cdecl `eh vector constructor iterator'(void * __ptr64,unsigned __int64,unsigned
   __int64,void (__cdecl*)(void * __ptr64),void (__cdecl*)(void * __ptr64))
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl
_eh_vector_constructor_iterator_
          (void *param_1,__uint64 param_2,__uint64 param_3,_func_void_void_ptr *param_4,
          _func_void_void_ptr *param_5)

{
  __uint64 _Var1;
  
  for (_Var1 = 0; _Var1 != param_3; _Var1 = _Var1 + 1) {
    (*(code *)PTR__guard_dispatch_icall_1800623e0)(param_1);
    param_1 = (void *)((longlong)param_1 + param_2);
  }
  return;
}

/* ---- FUNC 0005C474 `eh_vector_destructor_iterator' (107 bytes) ---- */

/* Library Function - Single Match
    void __cdecl `eh vector destructor iterator'(void * __ptr64,unsigned __int64,unsigned
   __int64,void (__cdecl*)(void * __ptr64))
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl
_eh_vector_destructor_iterator_
          (void *param_1,__uint64 param_2,__uint64 param_3,_func_void_void_ptr *param_4)

{
  void *pvVar1;
  
  pvVar1 = (void *)(param_2 * param_3 + (longlong)param_1);
  while( true ) {
    if (param_3 == 0) break;
    pvVar1 = (void *)((longlong)pvVar1 - param_2);
    (*(code *)PTR__guard_dispatch_icall_1800623e0)(pvVar1);
    param_3 = param_3 - 1;
  }
  return;
}

/* ---- FUNC 0005C4E0 __ArrayUnwind (97 bytes) ---- */

/* Library Function - Single Match
    void __cdecl __ArrayUnwind(void * __ptr64,unsigned __int64,unsigned __int64,void (__cdecl*)(void
   * __ptr64))
   
   Library: Visual Studio 2019 Release */

void __cdecl
__ArrayUnwind(void *param_1,__uint64 param_2,__uint64 param_3,_func_void_void_ptr *param_4)

{
  __uint64 _Var1;
  
  for (_Var1 = 0; _Var1 != param_3; _Var1 = _Var1 + 1) {
    param_1 = (void *)((longlong)param_1 - param_2);
    (*(code *)PTR__guard_dispatch_icall_1800623e0)(param_1);
  }
  return;
}

/* ---- FUNC 0005C544 operator_delete[] (5 bytes) ---- */

void __cdecl operator_delete__(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018005bd4f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete__(param_1);
  return;
}

/* ---- FUNC 0005C54C __scrt_acquire_startup_lock (57 bytes) ---- */

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
LAB_18005c57a:
    uVar3 = uVar3 & 0xffffffffffffff00;
  }
  else {
    do {
      uVar3 = 0;
      LOCK();
      bVar2 = DAT_18007a5a8 == 0;
      uVar1 = *(ulonglong *)((longlong)Self + 8);
      if (!bVar2) {
        uVar3 = DAT_18007a5a8;
        uVar1 = DAT_18007a5a8;
      }
      DAT_18007a5a8 = uVar1;
      UNLOCK();
      if (bVar2) goto LAB_18005c57a;
    } while (*(ulonglong *)((longlong)Self + 8) != uVar3);
    uVar3 = CONCAT71((int7)(uVar3 >> 8),1);
  }
  return uVar3;
}

/* ---- FUNC 0005C588 __scrt_dllmain_after_initialize_c (52 bytes) ---- */

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
    uVar3 = FUN_180026fd0();
    uVar3 = _configure_narrow_argv(uVar3 & 0xffffffff);
    if ((int)uVar3 != 0) {
      return uVar3 & 0xffffffffffffff00;
    }
    uVar2 = _initialize_narrow_environment();
  }
  else {
    uVar2 = FUN_18005cd4c();
  }
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}

/* ---- FUNC 0005C5BC FUN_18005c5bc (21 bytes) ---- */

bool FUN_18005c5bc(void)

{
  undefined8 uVar1;
  
  uVar1 = FUN_18005c704(0);
  return (char)uVar1 != '\0';
}

/* ---- FUNC 0005C5D4 FUN_18005c5d4 (40 bytes) ---- */

undefined1 FUN_18005c5d4(void)

{
  char cVar1;
  
  cVar1 = FUN_18005d994();
  if (cVar1 != '\0') {
    cVar1 = FUN_18005d994();
    if (cVar1 != '\0') {
      return 1;
    }
    FUN_18005d994();
  }
  return 0;
}

/* ---- FUNC 0005C5FC FUN_18005c5fc (21 bytes) ---- */

undefined1 FUN_18005c5fc(void)

{
  FUN_18005d994();
  FUN_18005d994();
  return 1;
}

/* ---- FUNC 0005C614 __scrt_dllmain_exception_filter (96 bytes) ---- */

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
    (*(code *)PTR__guard_dispatch_icall_1800623e0)(param_1,0,param_3);
  }
  _seh_filter_dll(param_5,param_6);
  return;
}

/* ---- FUNC 0005C674 __scrt_dllmain_uninitialize_c (48 bytes) ---- */

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
    _execute_onexit_table(&DAT_18007a5b8);
    return;
  }
  uVar2 = FUN_18002e4b0();
  if ((int)uVar2 == 0) {
    _cexit();
  }
  return;
}

/* ---- FUNC 0005C6A4 FUN_18005c6a4 (20 bytes) ---- */

void FUN_18005c6a4(void)

{
  FUN_18005d994();
  FUN_18005d994();
  return;
}

/* ---- FUNC 0005C6B8 __scrt_initialize_crt (73 bytes) ---- */

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
    DAT_18007a5b0 = 1;
  }
  FUN_18005cd4c();
  cVar1 = FUN_18005d994();
  uVar2 = extraout_var;
  if (cVar1 != '\0') {
    cVar1 = FUN_18005d994();
    if (cVar1 != '\0') {
      return CONCAT71(extraout_var_00,1);
    }
    FUN_18005d994();
    uVar2 = extraout_var_01;
  }
  return (ulonglong)uVar2 << 8;
}

/* ---- FUNC 0005C704 FUN_18005c704 (138 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_18005c704(uint param_1)

{
  bool bVar1;
  ulonglong in_RAX;
  undefined7 extraout_var;
  
  if (DAT_18007a5b1 == '\0') {
    if (1 < param_1) {
                    /* WARNING: Subroutine does not return */
      FUN_18005cf0c(5);
    }
    bVar1 = __scrt_is_ucrt_dll_in_use();
    if (((int)CONCAT71(extraout_var,bVar1) == 0) || (param_1 != 0)) {
      in_RAX = 0xffffffffffffffff;
      DAT_18007a5b8 = _DAT_180065b90;
      uRam000000018007a5c0 = _UNK_180065b98;
      _DAT_18007a5c8 = 0xffffffffffffffff;
      _DAT_18007a5d0 = _DAT_180065b90;
      uRam000000018007a5d8 = _UNK_180065b98;
      _DAT_18007a5e0 = 0xffffffffffffffff;
    }
    else {
      in_RAX = _initialize_onexit_table(&DAT_18007a5b8);
      if (((int)in_RAX != 0) ||
         (in_RAX = _initialize_onexit_table(&DAT_18007a5d0), (int)in_RAX != 0)) {
        return in_RAX & 0xffffffffffffff00;
      }
    }
    DAT_18007a5b1 = '\x01';
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}

/* ---- FUNC 0005C790 FUN_18005c790 (152 bytes) ---- */

ulonglong FUN_18005c790(longlong param_1)

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
           param_1 - 0x180000000U < uVar1)) goto LAB_18005c806;
      }
      lVar4 = 0;
LAB_18005c806:
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

/* ---- FUNC 0005C828 __scrt_release_startup_lock (36 bytes) ---- */

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
    DAT_18007a5a8 = 0;
    UNLOCK();
  }
  return;
}

/* ---- FUNC 0005C84C __scrt_uninitialize_crt (41 bytes) ---- */

/* Library Function - Single Match
    __scrt_uninitialize_crt
   
   Library: Visual Studio 2019 Release */

undefined1 __scrt_uninitialize_crt(undefined8 param_1,char param_2)

{
  if ((DAT_18007a5b0 == '\0') || (param_2 == '\0')) {
    FUN_18005d994();
    FUN_18005d994();
  }
  return 1;
}

/* ---- FUNC 0005C878 _onexit (58 bytes) ---- */

/* Library Function - Single Match
    _onexit
   
   Library: Visual Studio 2019 Release */

_onexit_t __cdecl _onexit(_onexit_t _Func)

{
  int iVar1;
  _onexit_t p_Var2;
  
  if (DAT_18007a5b8 == -1) {
    iVar1 = _crt_atexit();
  }
  else {
    iVar1 = _register_onexit_function(&DAT_18007a5b8);
  }
  p_Var2 = (_onexit_t)0x0;
  if (iVar1 == 0) {
    p_Var2 = _Func;
  }
  return p_Var2;
}

/* ---- FUNC 0005C8B4 atexit (23 bytes) ---- */

/* Library Function - Single Match
    atexit
   
   Library: Visual Studio 2019 Release */

int __cdecl atexit(_func_5014 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = _onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}

/* ---- FUNC 0005C8CC FUN_18005c8cc (57 bytes) ---- */

void FUN_18005c8cc(undefined4 *param_1)

{
  AcquireSRWLockExclusive((PSRWLOCK)&DAT_18007a5f0);
  *param_1 = 0;
  ReleaseSRWLockExclusive((PSRWLOCK)&DAT_18007a5f0);
                    /* WARNING: Could not recover jumptable at 0x00018005c8fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WakeAllConditionVariable(&DAT_18007a5e8);
  return;
}

/* ---- FUNC 0005C908 _Init_thread_footer (105 bytes) ---- */

/* Library Function - Single Match
    _Init_thread_footer
   
   Library: Visual Studio 2019 Release */

void _Init_thread_footer(int *param_1)

{
  ulonglong uVar1;
  
  AcquireSRWLockExclusive((PSRWLOCK)&DAT_18007a5f0);
  uVar1 = (ulonglong)_tls_index;
  DAT_180077828 = DAT_180077828 + 1;
  *param_1 = DAT_180077828;
  *(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar1 * 8) + 4) = DAT_180077828;
  ReleaseSRWLockExclusive((PSRWLOCK)&DAT_18007a5f0);
                    /* WARNING: Could not recover jumptable at 0x00018005c96a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WakeAllConditionVariable(&DAT_18007a5e8);
  return;
}

/* ---- FUNC 0005C974 FUN_18005c974 (120 bytes) ---- */

void FUN_18005c974(int *param_1)

{
  AcquireSRWLockExclusive((PSRWLOCK)&DAT_18007a5f0);
  do {
    if (*param_1 == 0) {
      *param_1 = -1;
LAB_18005c9d9:
                    /* WARNING: Could not recover jumptable at 0x00018005c9e5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      ReleaseSRWLockExclusive((PSRWLOCK)&DAT_18007a5f0);
      return;
    }
    if (*param_1 != -1) {
      *(undefined4 *)
       (*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4) =
           DAT_180077828;
      goto LAB_18005c9d9;
    }
    SleepConditionVariableSRW
              ((PCONDITION_VARIABLE)&DAT_18007a5e8,(PSRWLOCK)&DAT_18007a5f0,0xffffffff,0);
  } while( true );
}

/* ---- FUNC 0005C9EC FUN_18005c9ec (80 bytes) ---- */

ulonglong FUN_18005c9ec(undefined8 param_1,int param_2,longlong param_3)

{
  byte bVar1;
  ulonglong uVar2;
  undefined7 extraout_var;
  
  if (param_2 == 0) {
    bVar1 = FUN_18005cb54(CONCAT71((int7)((ulonglong)param_1 >> 8),param_3 != 0));
    return CONCAT71(extraout_var,bVar1);
  }
  if (param_2 != 1) {
    if (param_2 == 2) {
      bVar1 = FUN_18005c5d4();
    }
    else {
      if (param_2 != 3) {
        return 1;
      }
      bVar1 = FUN_18005c5fc();
    }
    return (ulonglong)bVar1;
  }
  uVar2 = FUN_18005ca3c(param_1,param_3);
  return uVar2;
}

/* ---- FUNC 0005CA3C FUN_18005ca3c (276 bytes) ---- */

undefined8 FUN_18005ca3c(undefined8 param_1,undefined8 param_2)

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
    if (DAT_18007a5a0 != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18005cf0c(7);
    }
    DAT_18007a5a0 = 1;
    bVar2 = FUN_18005c5bc();
    if (bVar2) {
      FUN_18005d128();
      FUN_18005c3e8();
      FUN_18005d104();
      iVar3 = _initterm_e(&DAT_180062440,&DAT_180062448);
      if ((iVar3 == 0) && (uVar5 = __scrt_dllmain_after_initialize_c(), (char)uVar5 != '\0')) {
        _initterm(&DAT_180062408,&DAT_180062438);
        DAT_18007a5a0 = 2;
        bVar1 = false;
      }
    }
    __scrt_release_startup_lock((char)uVar4);
    if (!bVar1) {
      plVar6 = (longlong *)FUN_18005d120();
      if ((*plVar6 != 0) && (uVar7 = FUN_18005c790((longlong)plVar6), (char)uVar7 != '\0')) {
        (*(code *)PTR__guard_dispatch_icall_1800623e0)(param_1,2,param_2);
      }
      DAT_18007a5fc = DAT_18007a5fc + 1;
      return 1;
    }
  }
  return 0;
}

/* ---- FUNC 0005CB54 FUN_18005cb54 (129 bytes) ---- */

byte FUN_18005cb54(undefined8 param_1)

{
  undefined1 uVar1;
  char cVar2;
  undefined8 uVar3;
  undefined7 uVar4;
  byte bVar5;
  
  uVar1 = (undefined1)param_1;
  if (DAT_18007a5fc < 1) {
    bVar5 = 0;
  }
  else {
    DAT_18007a5fc = DAT_18007a5fc + -1;
    uVar3 = __scrt_acquire_startup_lock();
    if (DAT_18007a5a0 != 2) {
                    /* WARNING: Subroutine does not return */
      FUN_18005cf0c(7);
    }
    __scrt_dllmain_uninitialize_c();
    FUN_18005c3f8();
    FUN_18005d164();
    DAT_18007a5a0 = 0;
    uVar4 = (undefined7)((ulonglong)param_1 >> 8);
    __scrt_release_startup_lock((char)uVar3);
    cVar2 = __scrt_uninitialize_crt(CONCAT71(uVar4,uVar1),'\0');
    bVar5 = -(cVar2 != '\0') & 1;
    FUN_18005c6a4();
  }
  return bVar5;
}

/* ---- FUNC 0005CBD8 dllmain_dispatch (305 bytes) ---- */

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
  
  if ((param_2 == 0) && (DAT_18007a5fc < 1)) {
    iVar4 = 0;
  }
  else {
    if (param_2 - 1 < 2) {
      if ((PTR_FUN_180066f00 != (undefined *)0x0) &&
         (iVar4 = (*(code *)PTR__guard_dispatch_icall_1800623e0)(), iVar4 == 0)) {
        return 0;
      }
      uVar1 = FUN_18005c9ec(param_1,param_2,(longlong)param_3);
      if ((int)uVar1 == 0) {
        return 0;
      }
    }
    uVar2 = FUN_1800376e0(param_1,param_2);
    iVar4 = (int)uVar2;
    if ((param_2 == 1) && (iVar4 == 0)) {
      pHVar3 = param_1;
      FUN_1800376e0(param_1,0);
      FUN_18005cb54(CONCAT71((int7)((ulonglong)pHVar3 >> 8),param_3 != (void *)0x0));
      if (PTR_FUN_180066f00 != (undefined *)0x0) {
        (*(code *)PTR__guard_dispatch_icall_1800623e0)(param_1,0,param_3);
      }
    }
    if ((param_2 == 0) || (param_2 == 3)) {
      uVar1 = FUN_18005c9ec(param_1,param_2,(longlong)param_3);
      iVar4 = 0;
      if ((int)uVar1 != 0) {
        if (PTR_FUN_180066f00 == (undefined *)0x0) {
          iVar4 = 1;
        }
        else {
          iVar4 = (*(code *)PTR__guard_dispatch_icall_1800623e0)(param_1,param_2,param_3);
        }
      }
    }
  }
  return iVar4;
}

/* ---- FUNC 0005CD0C entry (61 bytes) ---- */

void entry(HINSTANCE__ *param_1,ulong param_2,void *param_3)

{
  if (param_2 == 1) {
    __security_init_cookie();
  }
  dllmain_dispatch(param_1,param_2,param_3);
  return;
}

/* ---- FUNC 0005CD4C FUN_18005cd4c (428 bytes) ---- */

/* WARNING: Removing unreachable block (ram,0x00018005ce16) */
/* WARNING: Removing unreachable block (ram,0x00018005cd86) */
/* WARNING: Removing unreachable block (ram,0x00018005cd5f) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_18005cd4c(void)

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
    _DAT_180077840 = 0xffffffffffffffff;
    uVar7 = *puVar2 & 0xfff3ff0;
    _DAT_180077838 = 0x8000;
    if ((((uVar7 == 0x106c0) || (uVar7 == 0x20660)) || (uVar7 == 0x20670)) ||
       ((uVar7 - 0x30650 < 0x21 &&
        ((0x100010001U >> ((ulonglong)(uVar7 - 0x30650) & 0x3f) & 1) != 0)))) {
      DAT_18007a600 = DAT_18007a600 | 1;
    }
  }
  if (6 < *piVar1) {
    lVar3 = cpuid_Extended_Feature_Enumeration_info(7);
    uVar8 = *(uint *)(lVar3 + 4);
    if ((uVar8 >> 9 & 1) != 0) {
      DAT_18007a600 = DAT_18007a600 | 2;
    }
  }
  _DAT_180077830 = 1;
  DAT_180077834 = 2;
  if ((uVar4 >> 0x14 & 1) != 0) {
    _DAT_180077830 = 2;
    DAT_180077834 = 6;
    if (((uVar4 >> 0x1b & 1) != 0) && ((uVar4 >> 0x1c & 1) != 0)) {
      uVar5 = xinuse(0);
      bVar6 = in_XCR0 & (byte)uVar5;
      if ((bVar6 & 6) == 6) {
        DAT_180077834 = 0xe;
        _DAT_180077830 = 3;
        if ((uVar8 & 0x20) != 0) {
          _DAT_180077830 = 5;
          DAT_180077834 = 0x2e;
          if (((uVar8 & 0xd0030000) == 0xd0030000) && ((bVar6 & 0xe0) == 0xe0)) {
            DAT_180077834 = 0x6e;
            _DAT_180077830 = 6;
          }
        }
      }
    }
  }
  return 0;
}

/* ---- FUNC 0005CEF8 __scrt_is_ucrt_dll_in_use (12 bytes) ---- */

/* Library Function - Single Match
    __scrt_is_ucrt_dll_in_use
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

bool __scrt_is_ucrt_dll_in_use(void)

{
  return DAT_180077870 != 0;
}

/* ---- FUNC 0005CF04 FUN_18005cf04 (8 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_18005cf04(void)

{
  _DAT_18007a604 = 0;
  return;
}

/* ---- FUNC 0005CF0C FUN_18005cf0c (331 bytes) ---- */

void FUN_18005cf0c(undefined4 param_1)

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
  *(undefined8 *)(puVar4 + -8) = 0x18005cf40;
  FUN_18005cf04();
  *(undefined8 *)(puVar4 + -8) = 0x18005cf51;
  memset(local_4d8,0,0x4d0);
  *(undefined8 *)(puVar4 + -8) = 0x18005cf5b;
  RtlCaptureContext(local_4d8);
  *(undefined8 *)(puVar4 + -8) = 0x18005cf75;
  FunctionEntry = RtlLookupFunctionEntry(local_3e0,&local_res10,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry != (PRUNTIME_FUNCTION)0x0) {
    *(undefined8 *)(puVar4 + 0x38) = 0;
    *(undefined1 **)(puVar4 + 0x30) = local_res18;
    *(undefined1 **)(puVar4 + 0x28) = local_res20;
    *(undefined1 **)(puVar4 + 0x20) = local_4d8;
    *(undefined8 *)(puVar4 + -8) = 0x18005cfb6;
    RtlVirtualUnwind(0,local_res10,local_3e0,FunctionEntry,*(PCONTEXT *)(puVar4 + 0x20),
                     *(PVOID **)(puVar4 + 0x28),*(PDWORD64 *)(puVar4 + 0x30),
                     *(PKNONVOLATILE_CONTEXT_POINTERS *)(puVar4 + 0x38));
  }
  local_440 = &stack0x00000008;
  *(undefined8 *)(puVar4 + -8) = 0x18005cfe8;
  memset(puVar4 + 0x50,0,0x98);
  *(undefined8 *)(puVar4 + 0x60) = unaff_retaddr;
  *(undefined4 *)(puVar4 + 0x50) = 0x40000015;
  *(undefined4 *)(puVar4 + 0x54) = 1;
  *(undefined8 *)(puVar4 + -8) = 0x18005d00a;
  BVar2 = IsDebuggerPresent();
  *(undefined1 **)(puVar4 + 0x40) = puVar4 + 0x50;
  *(undefined1 **)(puVar4 + 0x48) = local_4d8;
  *(undefined8 *)(puVar4 + -8) = 0x18005d02b;
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  *(undefined8 *)(puVar4 + -8) = 0x18005d036;
  LVar3 = UnhandledExceptionFilter((_EXCEPTION_POINTERS *)(puVar4 + 0x40));
  if ((LVar3 == 0) && (BVar2 != 1)) {
    *(undefined8 *)(puVar4 + -8) = 0x18005d046;
    FUN_18005cf04();
  }
  return;
}

/* ---- FUNC 0005D058 __security_init_cookie (172 bytes) ---- */

/* Library Function - Single Match
    __security_init_cookie
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl __security_init_cookie(void)

{
  DWORD DVar1;
  _FILETIME local_res8;
  LARGE_INTEGER local_res10;
  _FILETIME local_18 [2];
  
  if (DAT_180077818 == 0x2b992ddfa232) {
    local_res8.dwLowDateTime = 0;
    local_res8.dwHighDateTime = 0;
    GetSystemTimeAsFileTime(&local_res8);
    local_18[0] = local_res8;
    DVar1 = GetCurrentThreadId();
    local_18[0] = (_FILETIME)((ulonglong)local_18[0] ^ (ulonglong)DVar1);
    DVar1 = GetCurrentProcessId();
    local_18[0] = (_FILETIME)((ulonglong)local_18[0] ^ (ulonglong)DVar1);
    QueryPerformanceCounter(&local_res10);
    DAT_180077818 =
         ((ulonglong)local_res10.s.LowPart << 0x20 ^
          CONCAT44(local_res10.s.HighPart,local_res10.s.LowPart) ^ (ulonglong)local_18[0] ^
         (ulonglong)local_18) & 0xffffffffffff;
    if (DAT_180077818 == 0x2b992ddfa232) {
      DAT_180077818 = 0x2b992ddfa233;
    }
  }
  DAT_180077810 = ~DAT_180077818;
  return;
}

/* ---- FUNC 0005D104 FUN_18005d104 (27 bytes) ---- */

void FUN_18005d104(void)

{
  ulonglong *puVar1;
  
  puVar1 = (ulonglong *)FUN_180002a10();
  *puVar1 = *puVar1 | 0x24;
  puVar1 = (ulonglong *)FUN_180005970();
  *puVar1 = *puVar1 | 2;
  return;
}

/* ---- FUNC 0005D120 FUN_18005d120 (8 bytes) ---- */

undefined * FUN_18005d120(void)

{
  return &DAT_18007a680;
}

/* ---- FUNC 0005D128 FUN_18005d128 (60 bytes) ---- */

void FUN_18005d128(void)

{
  longlong *plVar1;
  
  for (plVar1 = &DAT_18006b758; plVar1 < &DAT_18006b758; plVar1 = plVar1 + 1) {
    if (*plVar1 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800623e0)();
    }
  }
  return;
}

/* ---- FUNC 0005D164 FUN_18005d164 (60 bytes) ---- */

void FUN_18005d164(void)

{
  longlong *plVar1;
  
  for (plVar1 = &DAT_18006b768; plVar1 < &DAT_18006b768; plVar1 = plVar1 + 1) {
    if (*plVar1 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800623e0)();
    }
  }
  return;
}

/* ---- FUNC 0005D1A0 CAtlBaseModule (165 bytes) ---- */

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
  *(undefined **)(this + 0x20) = &DAT_180066e48;
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
      DAT_180079879 = 1;
    }
  }
  return this;
}

/* ---- FUNC 0005D248 ~CAtlBaseModule (52 bytes) ---- */

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

/* ---- FUNC 0005D27C OleUIPromptUserA (6 bytes) ---- */

void OleUIPromptUserA(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005d27c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OleUIPromptUserA();
  return;
}

/* ---- FUNC 0005D282 OleUIUpdateLinksA (6 bytes) ---- */

void OleUIUpdateLinksA(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005d282. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OleUIUpdateLinksA();
  return;
}

/* ---- FUNC 0005D288 OleUIPasteSpecialA (6 bytes) ---- */

void OleUIPasteSpecialA(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005d288. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OleUIPasteSpecialA();
  return;
}

/* ---- FUNC 0005D290 FUN_18005d290 (16 bytes) ---- */

/* WARNING: Switch with 1 destination removed at 0x00018005d299 */

void FUN_18005d290(undefined8 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018005d9b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_180077850)(param_1,0);
  return;
}

/* ---- FUNC 0005D2A0 _com_issue_errorex (184 bytes) ---- */

/* Library Function - Single Match
    void __cdecl _com_issue_errorex(long,struct IUnknown * __ptr64,struct _GUID const & __ptr64)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl _com_issue_errorex(long param_1,IUnknown *param_2,_GUID *param_3)

{
  int iVar1;
  HRESULT HVar2;
  IErrorInfo *local_res10;
  undefined8 local_res20;
  
  local_res10 = (IErrorInfo *)0x0;
  if ((param_2 != (IUnknown *)0x0) &&
     (iVar1 = (*(code *)PTR__guard_dispatch_icall_1800623e0)(param_2,&DAT_180066ee8,&local_res20),
     -1 < iVar1)) {
    iVar1 = (*(code *)PTR__guard_dispatch_icall_1800623e0)(local_res20,param_3);
    (*(code *)PTR__guard_dispatch_icall_1800623e0)();
    if ((iVar1 == 0) && (HVar2 = GetErrorInfo(0,&local_res10), HVar2 != 0)) {
      local_res10 = (IErrorInfo *)0x0;
    }
  }
  (*(code *)PTR__guard_dispatch_icall_1800623e0)(param_1,local_res10);
  return;
}

/* ---- FUNC 0005D360 FUN_18005d360 (273 bytes) ---- */

LPSTR FUN_18005d360(LPCWSTR param_1)

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
      FUN_18005d290((ulonglong)uVar2);
    }
    lpMultiByteStr = operator_new__((longlong)iVar1);
    if (lpMultiByteStr == (LPSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_18005d290(0x8007000e);
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
      FUN_18005d290((ulonglong)uVar2);
    }
  }
  return lpMultiByteStr;
}

/* ---- FUNC 0005D480 FUN_18005d480 (407 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

BSTR FUN_18005d480(LPCSTR param_1)

{
  size_t _Size;
  int iVar1;
  int iVar2;
  uint uVar3;
  OLECHAR *psz;
  BSTR pOVar4;
  longlong lVar5;
  ulonglong uVar7;
  undefined1 *puVar8;
  undefined1 auStackY_68 [32];
  int local_38;
  int iStack_34;
  OLECHAR *local_30;
  ulonglong local_28;
  longlong lVar6;
  
  puVar8 = auStackY_68;
  local_28 = DAT_180077818 ^ (ulonglong)&local_38;
  if (param_1 != (LPCSTR)0x0) {
    lVar5 = -1;
    do {
      lVar6 = lVar5;
      lVar5 = lVar6 + 1;
    } while (param_1[lVar5] != '\0');
    uVar7 = lVar6 + 2;
    if (0x7fffffff < uVar7) {
                    /* WARNING: Subroutine does not return */
      FUN_18005d290(0x80070057);
    }
    iVar2 = (int)uVar7;
    iStack_34 = iVar2;
    iVar1 = MultiByteToWideChar(0,0,param_1,iVar2,(LPWSTR)0x0,0);
    local_38 = iVar1;
    if (iVar1 == 0) {
      uVar3 = GetLastError();
      if (0 < (int)uVar3) {
        uVar3 = uVar3 & 0xffff | 0x80070000;
      }
                    /* WARNING: Subroutine does not return */
      FUN_18005d290((ulonglong)uVar3);
    }
    _Size = (longlong)iVar1 * 2;
    if (iVar1 < 0x1000) {
      uVar7 = _Size + 0xf;
      if (uVar7 <= _Size) {
        uVar7 = 0xffffffffffffff0;
      }
      psz = (OLECHAR *)((longlong)&local_38 + -(uVar7 & 0xfffffffffffffff0));
      puVar8 = auStackY_68 + -(uVar7 & 0xfffffffffffffff0);
    }
    else {
      psz = malloc(_Size);
      puVar8 = auStackY_68;
    }
    local_30 = psz;
    if (psz != (OLECHAR *)0x0) {
      *(int *)(puVar8 + 0x28) = iVar1;
      *(OLECHAR **)(puVar8 + 0x20) = psz;
      *(undefined8 *)(puVar8 + -8) = 0x18005d58f;
      iVar2 = MultiByteToWideChar(0,0,param_1,iVar2,*(LPWSTR *)(puVar8 + 0x20),
                                  *(int *)(puVar8 + 0x28));
      if (iVar2 == 0) {
        if (0xfff < iVar1) {
          *(undefined8 *)(puVar8 + -8) = 0x18005d5fe;
          free(psz);
        }
        *(undefined8 *)(puVar8 + -8) = 0x18005d604;
        uVar3 = GetLastError();
        if (0 < (int)uVar3) {
          uVar3 = uVar3 & 0xffff | 0x80070000;
        }
                    /* WARNING: Subroutine does not return */
        *(undefined **)(puVar8 + -8) = &UNK_18005d617;
        FUN_18005d290((ulonglong)uVar3);
      }
      *(undefined8 *)(puVar8 + -8) = 0x18005d59c;
      pOVar4 = SysAllocString(psz);
      if (0xfff < iVar1) {
        *(undefined8 *)(puVar8 + -8) = 0x18005d5b0;
        free(psz);
      }
      if (pOVar4 != (BSTR)0x0) goto LAB_18005d4b2;
    }
                    /* WARNING: Subroutine does not return */
    *(undefined **)(puVar8 + -8) = &UNK_18005d5c7;
    FUN_18005d290(0x8007000e);
  }
  pOVar4 = (BSTR)0x0;
LAB_18005d4b2:
  *(undefined8 *)(puVar8 + -8) = 0x18005d4be;
  return pOVar4;
}

/* ---- FUNC 0005D620 _com_error (68 bytes) ---- */

/* Library Function - Single Match
    public: __cdecl _com_error::_com_error(class _com_error const & __ptr64) __ptr64
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

_com_error * __thiscall _com_error::_com_error(_com_error *this,_com_error *param_1)

{
  longlong lVar1;
  
  *(undefined ***)this = &PTR__scalar_deleting_destructor__180066ef8;
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  lVar1 = *(longlong *)(param_1 + 0x10);
  *(longlong *)(this + 0x10) = lVar1;
  *(undefined8 *)(this + 0x18) = 0;
  if (lVar1 != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800623e0)();
  }
  return this;
}

/* ---- FUNC 0005D670 _com_error (69 bytes) ---- */

/* Library Function - Single Match
    public: __cdecl _com_error::_com_error(long,struct IErrorInfo * __ptr64,bool) __ptr64
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

_com_error * __thiscall
_com_error::_com_error(_com_error *this,long param_1,IErrorInfo *param_2,bool param_3)

{
  *(long *)(this + 8) = param_1;
  *(undefined ***)this = &PTR__scalar_deleting_destructor__180066ef8;
  *(IErrorInfo **)(this + 0x10) = param_2;
  *(undefined8 *)(this + 0x18) = 0;
  if ((param_2 != (IErrorInfo *)0x0) && (param_3)) {
    (*(code *)PTR__guard_dispatch_icall_1800623e0)(param_2);
  }
  return this;
}

/* ---- FUNC 0005D6C0 ~_com_error (68 bytes) ---- */

/* Library Function - Single Match
    public: virtual __cdecl _com_error::~_com_error(void) __ptr64
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __thiscall _com_error::~_com_error(_com_error *this)

{
  *(undefined ***)this = &PTR__scalar_deleting_destructor__180066ef8;
  if (*(longlong *)(this + 0x10) != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800623e0)();
  }
  if (*(HLOCAL *)(this + 0x18) != (HLOCAL)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00018005d6f7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    LocalFree(*(HLOCAL *)(this + 0x18));
    return;
  }
  return;
}

/* ---- FUNC 0005D710 `scalar_deleting_destructor' (95 bytes) ---- */

/* Library Function - Single Match
    public: virtual void * __ptr64 __cdecl _com_error::`scalar deleting destructor'(unsigned int)
   __ptr64
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void * __thiscall _com_error::_scalar_deleting_destructor_(_com_error *this,uint param_1)

{
  *(undefined ***)this = &PTR__scalar_deleting_destructor__180066ef8;
  if (*(longlong *)(this + 0x10) != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800623e0)();
  }
  if (*(HLOCAL *)(this + 0x18) != (HLOCAL)0x0) {
    LocalFree(*(HLOCAL *)(this + 0x18));
  }
  if ((param_1 & 1) != 0) {
    FUN_180025ad0(this);
  }
  return this;
}

/* ---- FUNC 0005D770 FUN_18005d770 (39 bytes) ---- */

void FUN_18005d770(long param_1,IErrorInfo *param_2)

{
  _com_error local_28 [40];
  
  _com_error::_com_error(local_28,param_1,param_2,false);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_28,(ThrowInfo *)&DAT_180072b60);
}

/* ---- FUNC 0005D798 _Xlength_error (6 bytes) ---- */

void __cdecl std::_Xlength_error(char *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018005d798. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  _Xlength_error(param_1);
  return;
}

/* ---- FUNC 0005D79E _Xout_of_range (6 bytes) ---- */

void __cdecl std::_Xout_of_range(char *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018005d79e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Xout_of_range(param_1);
  return;
}

/* ---- FUNC 0005D7A4 __std_exception_copy (6 bytes) ---- */

void __std_exception_copy(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005d7a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __std_exception_copy();
  return;
}

/* ---- FUNC 0005D7AA __std_exception_destroy (6 bytes) ---- */

void __std_exception_destroy(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005d7aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __std_exception_destroy();
  return;
}

/* ---- FUNC 0005D7B0 _CxxThrowException (6 bytes) ---- */

void __stdcall _CxxThrowException(void *pExceptionObject,ThrowInfo *pThrowInfo)

{
                    /* WARNING: Could not recover jumptable at 0x00018005d7b0. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  _CxxThrowException(pExceptionObject,pThrowInfo);
  return;
}

/* ---- FUNC 0005D7B6 __CxxFrameHandler4 (6 bytes) ---- */

void __CxxFrameHandler4(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005d7b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __CxxFrameHandler4();
  return;
}

/* ---- FUNC 0005D7BC memcpy (6 bytes) ---- */

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005d7bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memcpy(_Dst,_Src,_Size);
  return pvVar1;
}

/* ---- FUNC 0005D7C2 memmove (6 bytes) ---- */

void * __cdecl memmove(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005d7c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memmove(_Dst,_Src,_Size);
  return pvVar1;
}

/* ---- FUNC 0005D7C8 memset (6 bytes) ---- */

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005d7c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}

/* ---- FUNC 0005D7D4 strchr (6 bytes) ---- */

char * __cdecl strchr(char *_Str,int _Val)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005d7d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = strchr(_Str,_Val);
  return pcVar1;
}

/* ---- FUNC 0005D7DA strrchr (6 bytes) ---- */

char * __cdecl strrchr(char *_Str,int _Ch)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005d7da. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = strrchr(_Str,_Ch);
  return pcVar1;
}

/* ---- FUNC 0005D7E0 strstr (6 bytes) ---- */

char * __cdecl strstr(char *_Str,char *_SubStr)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005d7e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = strstr(_Str,_SubStr);
  return pcVar1;
}

/* ---- FUNC 0005D7E6 _purecall (6 bytes) ---- */

void _purecall(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005d7e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _purecall();
  return;
}

/* ---- FUNC 0005D7EC wcsrchr (6 bytes) ---- */

wchar_t * __cdecl wcsrchr(wchar_t *_Str,wchar_t _Ch)

{
  wchar_t *pwVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005d7ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pwVar1 = wcsrchr(_Str,_Ch);
  return pwVar1;
}

/* ---- FUNC 0005D7F2 memcmp (6 bytes) ---- */

int __cdecl memcmp(void *_Buf1,void *_Buf2,size_t _Size)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005d7f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = memcmp(_Buf1,_Buf2,_Size);
  return iVar1;
}

/* ---- FUNC 0005D7F8 memchr (6 bytes) ---- */

void * __cdecl memchr(void *_Buf,int _Val,size_t _MaxCount)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005d7f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memchr(_Buf,_Val,_MaxCount);
  return pvVar1;
}

/* ---- FUNC 0005D7FE wcschr (6 bytes) ---- */

wchar_t * __cdecl wcschr(wchar_t *_Str,wchar_t _Ch)

{
  wchar_t *pwVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005d7fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pwVar1 = wcschr(_Str,_Ch);
  return pwVar1;
}

/* ---- FUNC 0005D804 __C_specific_handler (6 bytes) ---- */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005d804. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}

/* ---- FUNC 0005D80A __std_type_info_destroy_list (6 bytes) ---- */

void __std_type_info_destroy_list(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005d80a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __std_type_info_destroy_list();
  return;
}

/* ---- FUNC 0005D810 __current_exception (6 bytes) ---- */

void __current_exception(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005d810. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __current_exception();
  return;
}

/* ---- FUNC 0005D816 __current_exception_context (6 bytes) ---- */

void __current_exception_context(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005d816. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __current_exception_context();
  return;
}

/* ---- FUNC 0005D81C free (6 bytes) ---- */

void __cdecl free(void *_Memory)

{
                    /* WARNING: Could not recover jumptable at 0x00018005d81c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  free(_Memory);
  return;
}

/* ---- FUNC 0005D822 malloc (6 bytes) ---- */

void * __cdecl malloc(size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005d822. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = malloc(_Size);
  return pvVar1;
}

/* ---- FUNC 0005D828 ceil (6 bytes) ---- */

double __cdecl ceil(double _X)

{
  double dVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005d828. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  dVar1 = ceil(_X);
  return dVar1;
}

/* ---- FUNC 0005D82E strcmp (6 bytes) ---- */

int __cdecl strcmp(char *_Str1,char *_Str2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005d82e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = strcmp(_Str1,_Str2);
  return iVar1;
}

/* ---- FUNC 0005D834 log10 (6 bytes) ---- */

double __cdecl log10(double _X)

{
  double dVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018005d834. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  dVar1 = log10(_X);
  return dVar1;
}

/* ---- FUNC 0005D83A terminate (6 bytes) ---- */

void terminate(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005d83a. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  terminate();
  return;
}

/* ---- FUNC 0005D840 _seh_filter_dll (6 bytes) ---- */

void _seh_filter_dll(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005d840. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _seh_filter_dll();
  return;
}

/* ---- FUNC 0005D846 _configure_narrow_argv (6 bytes) ---- */

void _configure_narrow_argv(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005d846. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _configure_narrow_argv();
  return;
}

/* ---- FUNC 0005D84C _initialize_narrow_environment (6 bytes) ---- */

void _initialize_narrow_environment(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005d84c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initialize_narrow_environment();
  return;
}

/* ---- FUNC 0005D852 _initialize_onexit_table (6 bytes) ---- */

void _initialize_onexit_table(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005d852. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initialize_onexit_table();
  return;
}

/* ---- FUNC 0005D858 _register_onexit_function (6 bytes) ---- */

void _register_onexit_function(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005d858. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _register_onexit_function();
  return;
}

/* ---- FUNC 0005D85E _execute_onexit_table (6 bytes) ---- */

void _execute_onexit_table(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005d85e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _execute_onexit_table();
  return;
}

/* ---- FUNC 0005D864 _crt_atexit (6 bytes) ---- */

void _crt_atexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005d864. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _crt_atexit();
  return;
}

/* ---- FUNC 0005D86A _cexit (6 bytes) ---- */

void __cdecl _cexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005d86a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _cexit();
  return;
}

/* ---- FUNC 0005D870 _initterm (6 bytes) ---- */

void _initterm(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005d870. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm();
  return;
}

/* ---- FUNC 0005D876 _initterm_e (6 bytes) ---- */

void _initterm_e(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005d876. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm_e();
  return;
}

/* ---- FUNC 0005D87C FUN_18005d87c (93 bytes) ---- */

undefined4 FUN_18005d87c(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (DAT_18007a678 == 0) {
    uVar2 = 1;
  }
  else {
    uVar1 = FUN_18005d8dc(0x18007a678);
    uVar2 = 0;
    if (uVar1 != 0) {
      uVar2 = (*(code *)PTR__guard_dispatch_icall_1800623e0)(param_1,param_2,param_3);
    }
  }
  return uVar2;
}

/* ---- FUNC 0005D8DC FUN_18005d8dc (176 bytes) ---- */

uint FUN_18005d8dc(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  bool bVar4;
  
  if (IMAGE_DOS_HEADER_180000000.e_magic == (char  [2])0x5a4d) {
    bVar4 = false;
    if (*(int *)((longlong)(int)IMAGE_DOS_HEADER_180000000.e_lfanew + 0x180000000) == 0x4550) {
      bVar4 = *(short *)((longlong)IMAGE_DOS_HEADER_180000000.e_res_4_ +
                        (longlong)(int)IMAGE_DOS_HEADER_180000000.e_lfanew + -4) == 0x20b;
    }
  }
  else {
    bVar4 = false;
  }
  uVar2 = 0;
  if (bVar4) {
    lVar3 = (longlong)(int)IMAGE_DOS_HEADER_180000000.e_lfanew;
    uVar2 = 0;
    lVar1 = lVar3 + 0x180000018 +
            (ulonglong)*(ushort *)((longlong)IMAGE_DOS_HEADER_180000000.e_res_4_ + lVar3 + -8);
    while( true ) {
      if (*(ushort *)(IMAGE_DOS_HEADER_180000000.e_magic + lVar3 + 6) <= uVar2) break;
      if (((ulonglong)*(uint *)(lVar1 + 0xc) <= param_1 - 0x180000000U) &&
         (param_1 - 0x180000000U < (ulonglong)(*(int *)(lVar1 + 8) + *(uint *)(lVar1 + 0xc))))
      goto LAB_18005d96f;
      uVar2 = uVar2 + 1;
      lVar1 = lVar1 + 0x28;
    }
    lVar1 = 0;
LAB_18005d96f:
    if (lVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = ~(*(uint *)(lVar1 + 0x24) >> 0x1f) & 1;
    }
  }
  return uVar2;
}

/* ---- FUNC 0005D98C SetDefaultCopyContent (6 bytes) ---- */

void SetDefaultCopyContent(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018005d98c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x5d98c  26  SetDefaultCopyContent */
  SetDefaultCopyContent();
  return;
}

/* ---- FUNC 0005D994 FUN_18005d994 (3 bytes) ---- */

undefined1 FUN_18005d994(void)

{
  return 1;
}

/* ---- FUNC 0005D9B0 _guard_dispatch_icall (2 bytes) ---- */

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00018005d9b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

/* ---- FUNC 0005D9D0 _guard_dispatch_icall (6 bytes) ---- */

/* WARNING: This is an inlined function */
/* WARNING: Switch with 1 destination removed at 0x00018005d9d0 */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00018005d9b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

/* ---- FUNC 0005DA70 FUN_18005da70 (29 bytes) ---- */

void FUN_18005da70(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x38));
  return;
}

/* ---- FUNC 0005DAA0 FUN_18005daa0 (29 bytes) ---- */

void FUN_18005daa0(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x50));
  return;
}

/* ---- FUNC 0005DAC0 FUN_18005dac0 (29 bytes) ---- */

void FUN_18005dac0(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x70));
  return;
}

/* ---- FUNC 0005DAF0 FUN_18005daf0 (29 bytes) ---- */

void FUN_18005daf0(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x40));
  return;
}

/* ---- FUNC 0005DB10 FUN_18005db10 (29 bytes) ---- */

void FUN_18005db10(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x60));
  return;
}

/* ---- FUNC 0005DB30 FUN_18005db30 (32 bytes) ---- */

bool FUN_18005db30(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3fffff03;
}

/* ---- FUNC 0005DB60 FUN_18005db60 (39 bytes) ---- */

void FUN_18005db60(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x30) & 1) != 0) {
    *(uint *)(param_2 + 0x30) = *(uint *)(param_2 + 0x30) & 0xfffffffe;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              (*(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)(param_2 + 0x50));
  }
  return;
}

/* ---- FUNC 0005DB90 FUN_18005db90 (39 bytes) ---- */

void FUN_18005db90(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x20) & 1) != 0) {
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffffffe;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              (*(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)(param_2 + 0x40));
  }
  return;
}

/* ---- FUNC 0005DBC0 FUN_18005dbc0 (28 bytes) ---- */

undefined8 FUN_18005dbc0(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 8) = 1;
  return 0;
}

/* ---- FUNC 0005DBE0 FUN_18005dbe0 (29 bytes) ---- */

undefined8 FUN_18005dbe0(void)

{
  return 0;
}

/* ---- FUNC 0005DC90 FUN_18005dc90 (29 bytes) ---- */

void FUN_18005dc90(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x30));
  return;
}

/* ---- FUNC 0005DCB0 FUN_18005dcb0 (45 bytes) ---- */

void FUN_18005dcb0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x80) & 1) != 0) {
    *(uint *)(param_2 + 0x80) = *(uint *)(param_2 + 0x80) & 0xfffffffe;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x30));
  }
  return;
}

/* ---- FUNC 0005DCE0 FUN_18005dce0 (32 bytes) ---- */

void FUN_18005dce0(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x80));
  return;
}

/* ---- FUNC 0005DD50 FUN_18005dd50 (39 bytes) ---- */

void FUN_18005dd50(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x40) & 2) != 0) {
    *(uint *)(param_2 + 0x40) = *(uint *)(param_2 + 0x40) & 0xfffffffd;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x50));
  }
  return;
}

/* ---- FUNC 0005DD80 FUN_18005dd80 (39 bytes) ---- */

void FUN_18005dd80(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x40) & 4) != 0) {
    *(uint *)(param_2 + 0x40) = *(uint *)(param_2 + 0x40) & 0xfffffffb;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x60));
  }
  return;
}

/* ---- FUNC 0005DE10 FUN_18005de10 (29 bytes) ---- */

void FUN_18005de10(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x28));
  return;
}

/* ---- FUNC 0005DEE0 FUN_18005dee0 (40 bytes) ---- */

void FUN_18005dee0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x60) & 2) != 0) {
    *(uint *)(param_2 + 0x60) = *(uint *)(param_2 + 0x60) & 0xfffffffd;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0xb0));
  }
  return;
}

/* ---- FUNC 0005DF10 FUN_18005df10 (40 bytes) ---- */

void FUN_18005df10(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x60) & 4) != 0) {
    *(uint *)(param_2 + 0x60) = *(uint *)(param_2 + 0x60) & 0xfffffffb;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0xa0));
  }
  return;
}

/* ---- FUNC 0005DFD0 FUN_18005dfd0 (45 bytes) ---- */

void FUN_18005dfd0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x1d0) & 1) != 0) {
    *(uint *)(param_2 + 0x1d0) = *(uint *)(param_2 + 0x1d0) & 0xfffffffe;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x30));
  }
  return;
}

/* ---- FUNC 0005E000 FUN_18005e000 (45 bytes) ---- */

void FUN_18005e000(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x1d0) & 2) != 0) {
    *(uint *)(param_2 + 0x1d0) = *(uint *)(param_2 + 0x1d0) & 0xfffffffd;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x38));
  }
  return;
}

/* ---- FUNC 0005E030 FUN_18005e030 (45 bytes) ---- */

void FUN_18005e030(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x1d0) & 4) != 0) {
    *(uint *)(param_2 + 0x1d0) = *(uint *)(param_2 + 0x1d0) & 0xfffffffb;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x38));
  }
  return;
}

/* ---- FUNC 0005E060 FUN_18005e060 (45 bytes) ---- */

void FUN_18005e060(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x1d0) & 8) != 0) {
    *(uint *)(param_2 + 0x1d0) = *(uint *)(param_2 + 0x1d0) & 0xfffffff7;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x50));
  }
  return;
}

/* ---- FUNC 0005E090 FUN_18005e090 (45 bytes) ---- */

void FUN_18005e090(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x1d0) & 0x10) != 0) {
    *(uint *)(param_2 + 0x1d0) = *(uint *)(param_2 + 0x1d0) & 0xffffffef;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x48));
  }
  return;
}

/* ---- FUNC 0005E0C0 FUN_18005e0c0 (45 bytes) ---- */

void FUN_18005e0c0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x1d0) & 0x20) != 0) {
    *(uint *)(param_2 + 0x1d0) = *(uint *)(param_2 + 0x1d0) & 0xffffffdf;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x38));
  }
  return;
}

/* ---- FUNC 0005E0F0 FUN_18005e0f0 (45 bytes) ---- */

void FUN_18005e0f0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x1d0) & 0x40) != 0) {
    *(uint *)(param_2 + 0x1d0) = *(uint *)(param_2 + 0x1d0) & 0xffffffbf;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x30));
  }
  return;
}

/* ---- FUNC 0005E120 FUN_18005e120 (50 bytes) ---- */

void FUN_18005e120(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x1d0) & 0x80) != 0) {
    *(uint *)(param_2 + 0x1d0) = *(uint *)(param_2 + 0x1d0) & 0xffffff7f;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x38));
  }
  return;
}

/* ---- FUNC 0005E4D0 FUN_18005e4d0 (29 bytes) ---- */

undefined8 FUN_18005e4d0(void)

{
  return 0;
}

/* ---- FUNC 0005E4F0 FUN_18005e4f0 (56 bytes) ---- */

undefined8 FUN_18005e4f0(undefined8 param_1,longlong param_2)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(**(longlong **)(param_2 + 0x240) + 0x280))
                    (*(longlong **)(param_2 + 0x240),0x7d1);
  *(undefined4 *)(param_2 + 0xa8) = uVar1;
  return 0;
}

/* ---- FUNC 0005E540 FUN_18005e540 (29 bytes) ---- */

void FUN_18005e540(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x30));
  return;
}

/* ---- FUNC 0005E560 FUN_18005e560 (29 bytes) ---- */

void FUN_18005e560(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x30));
  return;
}

/* ---- FUNC 0005E580 FUN_18005e580 (29 bytes) ---- */

void FUN_18005e580(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x40));
  return;
}

/* ---- FUNC 0005E5B0 FUN_18005e5b0 (29 bytes) ---- */

void FUN_18005e5b0(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x78));
  return;
}

/* ---- FUNC 0005E5E0 FUN_18005e5e0 (39 bytes) ---- */

undefined8 FUN_18005e5e0(undefined8 param_1,longlong param_2)

{
  CException::Delete(*(CException **)(param_2 + 0x20));
  return 0;
}

/* ---- FUNC 0005E610 FUN_18005e610 (29 bytes) ---- */

void FUN_18005e610(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x68));
  return;
}

/* ---- FUNC 0005E630 FUN_18005e630 (32 bytes) ---- */

void FUN_18005e630(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x108));
  return;
}

/* ---- FUNC 0005E680 FUN_18005e680 (29 bytes) ---- */

void FUN_18005e680(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x38));
  return;
}

/* ---- FUNC 0005E6B0 FUN_18005e6b0 (29 bytes) ---- */

void FUN_18005e6b0(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x28));
  return;
}

/* ---- FUNC 0005E6D0 FUN_18005e6d0 (29 bytes) ---- */

void FUN_18005e6d0(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x28));
  return;
}

/* ---- FUNC 0005E740 FUN_18005e740 (29 bytes) ---- */

void FUN_18005e740(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x20));
  return;
}

/* ---- FUNC 0005E780 FUN_18005e780 (46 bytes) ---- */

undefined8 FUN_18005e780(undefined8 param_1,longlong param_2)

{
  *(CException **)(param_2 + 0x80) = *(CException **)(param_2 + 0x50);
  CException::Delete(*(CException **)(param_2 + 0x50));
  return 0;
}

/* ---- FUNC 0005E7B0 FUN_18005e7b0 (40 bytes) ---- */

undefined8 FUN_18005e7b0(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0x80) = *(undefined8 *)(param_2 + 0x58);
  return 0;
}

/* ---- FUNC 0005E7E0 FUN_18005e7e0 (40 bytes) ---- */

undefined8 FUN_18005e7e0(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0x80) = *(undefined8 *)(param_2 + 0x60);
  return 0;
}

/* ---- FUNC 0005E8C0 FUN_18005e8c0 (32 bytes) ---- */

void FUN_18005e8c0(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x1a0));
  return;
}

/* ---- FUNC 0005EA00 FUN_18005ea00 (32 bytes) ---- */

void FUN_18005ea00(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x180));
  return;
}

/* ---- FUNC 0005EA20 FUN_18005ea20 (32 bytes) ---- */

void FUN_18005ea20(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x198));
  return;
}

/* ---- FUNC 0005EA50 FUN_18005ea50 (32 bytes) ---- */

void FUN_18005ea50(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x398));
  return;
}

/* ---- FUNC 0005EA70 FUN_18005ea70 (56 bytes) ---- */

undefined8 FUN_18005ea70(undefined8 param_1,longlong param_2)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(**(longlong **)(param_2 + 0x380) + 0x280))
                    (*(longlong **)(param_2 + 0x380),0x7fa);
  *(undefined4 *)(param_2 + 0x390) = uVar1;
  return 0;
}

/* ---- FUNC 0005EAB0 FUN_18005eab0 (29 bytes) ---- */

void FUN_18005eab0(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x30));
  return;
}

/* ---- FUNC 0005EAD0 FUN_18005ead0 (29 bytes) ---- */

void FUN_18005ead0(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x20));
  return;
}

/* ---- FUNC 0005EAF0 FUN_18005eaf0 (65 bytes) ---- */

void FUN_18005eaf0(undefined8 param_1,longlong param_2)

{
  operator_delete__(*(void **)(param_2 + 0x80));
  return;
}

/* ---- FUNC 0005EB70 FUN_18005eb70 (30 bytes) ---- */

undefined8 FUN_18005eb70(void)

{
  return 0;
}

/* ---- FUNC 0005EB90 FUN_18005eb90 (54 bytes) ---- */

undefined8 FUN_18005eb90(undefined8 param_1,longlong param_2)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(**(longlong **)(param_2 + 0x120) + 0x280))
                    (*(longlong **)(param_2 + 0x120),0x7ef);
  *(undefined4 *)(param_2 + 0x60) = uVar1;
  return 0;
}

/* ---- FUNC 0005EBD0 FUN_18005ebd0 (30 bytes) ---- */

undefined8 FUN_18005ebd0(void)

{
  return 0;
}

/* ---- FUNC 0005EBF0 FUN_18005ebf0 (40 bytes) ---- */

void FUN_18005ebf0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x60) & 1) != 0) {
    *(uint *)(param_2 + 0x60) = *(uint *)(param_2 + 0x60) & 0xfffffffe;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              (*(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)(param_2 + 0x88));
  }
  return;
}

/* ---- FUNC 0005EC30 FUN_18005ec30 (29 bytes) ---- */

void FUN_18005ec30(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x40));
  return;
}

/* ---- FUNC 0005EC50 FUN_18005ec50 (29 bytes) ---- */

void FUN_18005ec50(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x30));
  return;
}

/* ---- FUNC 0005EC90 FUN_18005ec90 (43 bytes) ---- */

undefined8 FUN_18005ec90(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0x80) = *(undefined8 *)(param_2 + 0x98);
  return 0;
}

/* ---- FUNC 0005ECC0 FUN_18005ecc0 (43 bytes) ---- */

undefined8 FUN_18005ecc0(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0x80) = *(undefined8 *)(param_2 + 0xa0);
  return 0;
}

/* ---- FUNC 0005ECF0 FUN_18005ecf0 (43 bytes) ---- */

undefined8 FUN_18005ecf0(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0x80) = *(undefined8 *)(param_2 + 0xa8);
  return 0;
}

/* ---- FUNC 0005ED30 FUN_18005ed30 (40 bytes) ---- */

undefined8 FUN_18005ed30(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0x78) = *(undefined8 *)(param_2 + 0x90);
  return 0;
}

/* ---- FUNC 0005ED60 FUN_18005ed60 (40 bytes) ---- */

undefined8 FUN_18005ed60(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0x78) = *(undefined8 *)(param_2 + 0x98);
  return 0;
}

/* ---- FUNC 0005ED90 FUN_18005ed90 (40 bytes) ---- */

undefined8 FUN_18005ed90(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0x78) = *(undefined8 *)(param_2 + 0xa0);
  return 0;
}

/* ---- FUNC 0005EDE0 FUN_18005ede0 (37 bytes) ---- */

undefined8 FUN_18005ede0(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0x68) = *(undefined8 *)(param_2 + 0x38);
  return 0;
}

/* ---- FUNC 0005EE10 FUN_18005ee10 (37 bytes) ---- */

undefined8 FUN_18005ee10(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0x68) = *(undefined8 *)(param_2 + 0x40);
  return 0;
}

/* ---- FUNC 0005EE40 FUN_18005ee40 (37 bytes) ---- */

undefined8 FUN_18005ee40(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0x68) = *(undefined8 *)(param_2 + 0x48);
  return 0;
}

/* ---- FUNC 0005EE90 FUN_18005ee90 (43 bytes) ---- */

undefined8 FUN_18005ee90(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0xa8) = *(undefined8 *)(param_2 + 0xc0);
  return 0;
}

/* ---- FUNC 0005EEC0 FUN_18005eec0 (43 bytes) ---- */

undefined8 FUN_18005eec0(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0xa8) = *(undefined8 *)(param_2 + 200);
  return 0;
}

/* ---- FUNC 0005EF10 FUN_18005ef10 (29 bytes) ---- */

void FUN_18005ef10(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x30));
  return;
}

/* ---- FUNC 0005F140 FUN_18005f140 (29 bytes) ---- */

void FUN_18005f140(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x58));
  return;
}

/* ---- FUNC 0005F160 FUN_18005f160 (29 bytes) ---- */

void FUN_18005f160(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x38));
  return;
}

/* ---- FUNC 0005F1B0 FUN_18005f1b0 (29 bytes) ---- */

void FUN_18005f1b0(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x70));
  return;
}

/* ---- FUNC 0005F220 FUN_18005f220 (32 bytes) ---- */

void FUN_18005f220(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x178));
  return;
}

/* ---- FUNC 0005F240 FUN_18005f240 (32 bytes) ---- */

void FUN_18005f240(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x138));
  return;
}

/* ---- FUNC 0005F280 FUN_18005f280 (32 bytes) ---- */

void FUN_18005f280(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x140));
  return;
}

/* ---- FUNC 0005F2C0 FUN_18005f2c0 (32 bytes) ---- */

void FUN_18005f2c0(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x148));
  return;
}

/* ---- FUNC 0005F2E0 FUN_18005f2e0 (32 bytes) ---- */

void FUN_18005f2e0(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x150));
  return;
}

/* ---- FUNC 0005F310 FUN_18005f310 (32 bytes) ---- */

void FUN_18005f310(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x158));
  return;
}

/* ---- FUNC 0005F360 FUN_18005f360 (32 bytes) ---- */

void FUN_18005f360(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x160));
  return;
}

/* ---- FUNC 0005F390 FUN_18005f390 (40 bytes) ---- */

void FUN_18005f390(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x58) & 1) != 0) {
    *(uint *)(param_2 + 0x58) = *(uint *)(param_2 + 0x58) & 0xfffffffe;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x60));
  }
  return;
}

/* ---- FUNC 0005F410 FUN_18005f410 (39 bytes) ---- */

void FUN_18005f410(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x40) & 1) != 0) {
    *(uint *)(param_2 + 0x40) = *(uint *)(param_2 + 0x40) & 0xfffffffe;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x58));
  }
  return;
}

/* ---- FUNC 0005F450 FUN_18005f450 (29 bytes) ---- */

void FUN_18005f450(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x40));
  return;
}

/* ---- FUNC 0005F470 FUN_18005f470 (48 bytes) ---- */

void FUN_18005f470(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 200) & 1) != 0) {
    *(uint *)(param_2 + 200) = *(uint *)(param_2 + 200) & 0xfffffffe;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0xb0));
  }
  return;
}

/* ---- FUNC 0005F4B0 FUN_18005f4b0 (29 bytes) ---- */

void FUN_18005f4b0(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x70));
  return;
}

/* ---- FUNC 0005F4D0 FUN_18005f4d0 (39 bytes) ---- */

void FUN_18005f4d0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x38) & 1) != 0) {
    *(uint *)(param_2 + 0x38) = *(uint *)(param_2 + 0x38) & 0xfffffffe;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x50));
  }
  return;
}

/* ---- FUNC 0005F5B0 FUN_18005f5b0 (39 bytes) ---- */

void FUN_18005f5b0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x48) & 1) != 0) {
    *(uint *)(param_2 + 0x48) = *(uint *)(param_2 + 0x48) & 0xfffffffe;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x50));
  }
  return;
}

/* ---- FUNC 0005F5E0 FUN_18005f5e0 (39 bytes) ---- */

void FUN_18005f5e0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x48) & 2) != 0) {
    *(uint *)(param_2 + 0x48) = *(uint *)(param_2 + 0x48) & 0xfffffffd;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x50));
  }
  return;
}

/* ---- FUNC 0005F610 FUN_18005f610 (39 bytes) ---- */

void FUN_18005f610(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x48) & 4) != 0) {
    *(uint *)(param_2 + 0x48) = *(uint *)(param_2 + 0x48) & 0xfffffffb;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x50));
  }
  return;
}

/* ---- FUNC 0005F640 FUN_18005f640 (42 bytes) ---- */

void FUN_18005f640(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x48) & 8) != 0) {
    *(uint *)(param_2 + 0x48) = *(uint *)(param_2 + 0x48) & 0xfffffff7;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x88));
  }
  return;
}

/* ---- FUNC 0005F670 FUN_18005f670 (42 bytes) ---- */

void FUN_18005f670(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x48) & 0x10) != 0) {
    *(uint *)(param_2 + 0x48) = *(uint *)(param_2 + 0x48) & 0xffffffef;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x90));
  }
  return;
}

/* ---- FUNC 0005F6A0 FUN_18005f6a0 (42 bytes) ---- */

void FUN_18005f6a0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x48) & 0x20) != 0) {
    *(uint *)(param_2 + 0x48) = *(uint *)(param_2 + 0x48) & 0xffffffdf;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x98));
  }
  return;
}

/* ---- FUNC 0005F6D0 FUN_18005f6d0 (39 bytes) ---- */

void FUN_18005f6d0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x38) & 1) != 0) {
    *(uint *)(param_2 + 0x38) = *(uint *)(param_2 + 0x38) & 0xfffffffe;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x48));
  }
  return;
}

/* ---- FUNC 0005F760 FUN_18005f760 (40 bytes) ---- */

undefined8 FUN_18005f760(undefined8 param_1,longlong param_2)

{
  CException::Delete(*(CException **)(param_2 + 0x70));
  return 0;
}

/* ---- FUNC 0005F790 FUN_18005f790 (40 bytes) ---- */

undefined8 FUN_18005f790(undefined8 param_1,longlong param_2)

{
  CException::Delete(*(CException **)(param_2 + 0x78));
  return 0;
}

/* ---- FUNC 0005F7C0 FUN_18005f7c0 (29 bytes) ---- */

void FUN_18005f7c0(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x28));
  return;
}

/* ---- FUNC 0005F7F0 FUN_18005f7f0 (39 bytes) ---- */

undefined8 FUN_18005f7f0(undefined8 param_1,longlong param_2)

{
  CException::Delete(*(CException **)(param_2 + 0x30));
  return 0;
}

/* ---- FUNC 0005F820 FUN_18005f820 (29 bytes) ---- */

void FUN_18005f820(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x28));
  return;
}

/* ---- FUNC 0005F850 FUN_18005f850 (39 bytes) ---- */

undefined8 FUN_18005f850(undefined8 param_1,longlong param_2)

{
  CException::Delete(*(CException **)(param_2 + 0x28));
  return 0;
}

/* ---- FUNC 0005F890 FUN_18005f890 (54 bytes) ---- */

undefined8 FUN_18005f890(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0x30) = *(undefined8 *)(param_2 + 0x20);
  if (*(int *)(param_2 + 0x78) != 0) {
    (**(code **)(**(longlong **)(param_2 + 0x60) + 0x10))();
  }
  return 0;
}

/* ---- FUNC 0005F8D0 FUN_18005f8d0 (42 bytes) ---- */

void FUN_18005f8d0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x70) & 1) != 0) {
    *(uint *)(param_2 + 0x70) = *(uint *)(param_2 + 0x70) & 0xfffffffe;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x80));
  }
  return;
}

/* ---- FUNC 0005F900 FUN_18005f900 (39 bytes) ---- */

void FUN_18005f900(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x70) & 2) != 0) {
    *(uint *)(param_2 + 0x70) = *(uint *)(param_2 + 0x70) & 0xfffffffd;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x30));
  }
  return;
}

/* ---- FUNC 0005F950 FUN_18005f950 (40 bytes) ---- */

undefined8 FUN_18005f950(undefined8 param_1,longlong param_2)

{
  CException::Delete(*(CException **)(param_2 + 0x70));
  return 0;
}

/* ---- FUNC 0005F9D0 FUN_18005f9d0 (48 bytes) ---- */

void FUN_18005f9d0(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_18003ef80(*(undefined8 *)(param_2 + 0x50));
  FUN_180037a20(*(undefined8 *)(param_2 + 0x50),uVar1,*(longlong **)(param_2 + 0x58));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}

/* ---- FUNC 0005FB00 FUN_18005fb00 (29 bytes) ---- */

void FUN_18005fb00(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x48));
  return;
}

/* ---- FUNC 0005FB20 FUN_18005fb20 (29 bytes) ---- */

void FUN_18005fb20(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x28));
  return;
}

/* ---- FUNC 0005FB40 FUN_18005fb40 (50 bytes) ---- */

undefined8 FUN_18005fb40(void)

{
  ReleaseSemaphore(DAT_1800797e8,1,(LPLONG)0x0);
  return 0;
}

/* ---- FUNC 0005FB90 FUN_18005fb90 (60 bytes) ---- */

undefined8 FUN_18005fb90(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  
  plVar1 = *(longlong **)(param_2 + 0x58);
  *(longlong **)(param_2 + 0x28) = plVar1;
  (**(code **)(*plVar1 + 0x28))(plVar1,param_2 + 0x80,0x400,0);
  return 0;
}

/* ---- FUNC 0005FBD0 FUN_18005fbd0 (30 bytes) ---- */

undefined8 FUN_18005fbd0(void)

{
  return 0;
}

/* ---- FUNC 0005FC10 FUN_18005fc10 (38 bytes) ---- */

void FUN_18005fc10(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x30) & 1) != 0) {
    *(uint *)(param_2 + 0x30) = *(uint *)(param_2 + 0x30) & 0xfffffffe;
    FUN_180001440(*(longlong **)(param_2 + 0x60));
  }
  return;
}

/* ---- FUNC 0005FC40 FUN_18005fc40 (39 bytes) ---- */

undefined8 FUN_18005fc40(undefined8 param_1,longlong param_2)

{
  **(undefined4 **)(param_2 + 0x38) = 0;
  return 0;
}

/* ---- FUNC 0005FC70 FUN_18005fc70 (48 bytes) ---- */

void FUN_18005fc70(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x80) & 1) != 0) {
    *(uint *)(param_2 + 0x80) = *(uint *)(param_2 + 0x80) & 0xfffffffe;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x88));
  }
  return;
}

/* ---- FUNC 0005FCA0 FUN_18005fca0 (45 bytes) ---- */

void FUN_18005fca0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x80) & 2) != 0) {
    *(uint *)(param_2 + 0x80) = *(uint *)(param_2 + 0x80) & 0xfffffffd;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x30));
  }
  return;
}

/* ---- FUNC 0005FCF0 FUN_18005fcf0 (39 bytes) ---- */

void FUN_18005fcf0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x38) & 1) != 0) {
    *(uint *)(param_2 + 0x38) = *(uint *)(param_2 + 0x38) & 0xfffffffe;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x40));
  }
  return;
}

/* ---- FUNC 0005FD20 FUN_18005fd20 (39 bytes) ---- */

void FUN_18005fd20(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x38) & 2) != 0) {
    *(uint *)(param_2 + 0x38) = *(uint *)(param_2 + 0x38) & 0xfffffffd;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x58));
  }
  return;
}

/* ---- FUNC 0005FD50 FUN_18005fd50 (39 bytes) ---- */

void FUN_18005fd50(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x38) & 4) != 0) {
    *(uint *)(param_2 + 0x38) = *(uint *)(param_2 + 0x38) & 0xfffffffb;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x40));
  }
  return;
}

/* ---- FUNC 0005FD80 FUN_18005fd80 (39 bytes) ---- */

void FUN_18005fd80(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x38) & 8) != 0) {
    *(uint *)(param_2 + 0x38) = *(uint *)(param_2 + 0x38) & 0xfffffff7;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x58));
  }
  return;
}

/* ---- FUNC 0005FE70 FUN_18005fe70 (29 bytes) ---- */

void FUN_18005fe70(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x20));
  return;
}

/* ---- FUNC 0005FE90 FUN_18005fe90 (36 bytes) ---- */

undefined8 FUN_18005fe90(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x20) = 0;
  return 0;
}

/* ---- FUNC 0005FEC0 FUN_18005fec0 (39 bytes) ---- */

undefined8 FUN_18005fec0(undefined8 param_1,longlong param_2)

{
  **(undefined4 **)(param_2 + 0x40) = 0;
  return 0;
}

/* ---- FUNC 0005FEF0 FUN_18005fef0 (44 bytes) ---- */

undefined8 FUN_18005fef0(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(*(longlong *)(param_2 + 0x50) + (longlong)*(int *)(param_2 + 0x40) * 4) = 0;
  return 0;
}

/* ---- FUNC 0005FF20 FUN_18005ff20 (39 bytes) ---- */

void FUN_18005ff20(undefined8 param_1,longlong param_2)

{
  deallocate(*(undefined8 *)(param_2 + 0x60),*(void **)(param_2 + 0x78),
             *(longlong *)(param_2 + 0x68));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}

/* ---- FUNC 0005FFA0 FUN_18005ffa0 (45 bytes) ---- */

void FUN_18005ffa0(undefined8 param_1,longlong param_2)

{
  _eh_vector_destructor_iterator_
            ((void *)(param_2 + 0x140),0x18,5,(_func_void_void_ptr *)&DAT_1800015e0);
  return;
}

/* ---- FUNC 0005FFE0 FUN_18005ffe0 (44 bytes) ---- */

undefined8 FUN_18005ffe0(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x120 + (longlong)*(int *)(param_2 + 0x50) * 4) = 0;
  return 0;
}

/* ---- FUNC 00060190 FUN_180060190 (29 bytes) ---- */

void FUN_180060190(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x38));
  return;
}

/* ---- FUNC 000601B0 FUN_1800601b0 (29 bytes) ---- */

void FUN_1800601b0(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x30));
  return;
}

/* ---- FUNC 000601E0 FUN_1800601e0 (29 bytes) ---- */

void FUN_1800601e0(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x28));
  return;
}

/* ---- FUNC 00060230 FUN_180060230 (32 bytes) ---- */

void FUN_180060230(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x90));
  return;
}

/* ---- FUNC 00060250 FUN_180060250 (29 bytes) ---- */

void FUN_180060250(undefined8 param_1,longlong param_2)

{
  FUN_180025ad0(*(void **)(param_2 + 0x58));
  return;
}

/* ---- FUNC 00060270 FUN_180060270 (39 bytes) ---- */

void FUN_180060270(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x68) & 1) != 0) {
    *(uint *)(param_2 + 0x68) = *(uint *)(param_2 + 0x68) & 0xfffffffe;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x38));
  }
  return;
}

/* ---- FUNC 00060297 FUN_180060297 (43 bytes) ---- */

void FUN_180060297(undefined8 param_1,longlong param_2)

{
  if (*(char *)(param_2 + 0x20) == '\0') {
    __ArrayUnwind(*(void **)(param_2 + 0x50),*(__uint64 *)(param_2 + 0x58),
                  *(__uint64 *)(param_2 + 0x28),*(_func_void_void_ptr **)(param_2 + 0x70));
  }
  return;
}

/* ---- FUNC 000602C3 FUN_1800602c3 (43 bytes) ---- */

void FUN_1800602c3(undefined8 param_1,longlong param_2)

{
  if (*(char *)(param_2 + 0x20) == '\0') {
    __ArrayUnwind(*(void **)(param_2 + 0x60),*(__uint64 *)(param_2 + 0x68),
                  *(__uint64 *)(param_2 + 0x70),*(_func_void_void_ptr **)(param_2 + 0x78));
  }
  return;
}

/* ---- FUNC 000602EF FUN_1800602ef (94 bytes) ---- */

undefined4 FUN_1800602ef(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  *(undefined8 *)(param_2 + 0x40) = param_1;
  *(undefined8 *)(param_2 + 0x30) = param_1;
  *(undefined8 *)(param_2 + 0x28) = **(undefined8 **)(param_2 + 0x30);
  if (**(int **)(param_2 + 0x28) != -0x1f928c9d) {
    *(undefined4 *)(param_2 + 0x20) = 0;
    return *(undefined4 *)(param_2 + 0x20);
  }
  puVar2 = (undefined8 *)__current_exception();
  *puVar2 = *(undefined8 *)(param_2 + 0x28);
  uVar1 = *(undefined8 *)(*(longlong *)(param_2 + 0x30) + 8);
  puVar2 = (undefined8 *)__current_exception_context();
  *puVar2 = uVar1;
                    /* WARNING: Subroutine does not return */
  terminate();
}

/* ---- FUNC 0006034E FUN_18006034e (23 bytes) ---- */

bool FUN_18006034e(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}

/* ---- FUNC 00060366 FUN_180060366 (22 bytes) ---- */

void FUN_180060366(undefined8 param_1,longlong param_2)

{
  __scrt_release_startup_lock(*(char *)(param_2 + 0x40));
  return;
}

/* ---- FUNC 0006037D FUN_18006037d (24 bytes) ---- */

void FUN_18006037d(undefined8 param_1,longlong param_2)

{
  __scrt_release_startup_lock(*(char *)(param_2 + 0x20));
  return;
}

/* ---- FUNC 00060396 FUN_180060396 (19 bytes) ---- */

void FUN_180060396(void)

{
  FUN_18005c6a4();
  return;
}

/* ---- FUNC 000603AA FUN_1800603aa (53 bytes) ---- */

void FUN_1800603aa(undefined8 *param_1,longlong param_2)

{
  __scrt_dllmain_exception_filter
            (*(undefined8 *)(param_2 + 0x60),*(int *)(param_2 + 0x68),
             *(undefined8 *)(param_2 + 0x70),FUN_18005c9ec,*(undefined4 *)*param_1,param_1);
  return;
}

/* ---- FUNC 000603E0 FUN_1800603e0 (29 bytes) ---- */

undefined8 FUN_1800603e0(void)

{
  return 0;
}

/* ---- FUNC 00060410 FUN_180060410 (137 bytes) ---- */

void FUN_180060410(void)

{
  undefined8 *puVar1;
  PVOID Ptr;
  longlong *plVar2;
  longlong *plVar3;
  
  if (DAT_1800777c0 != 0) {
    plVar2 = (longlong *)PTR_DAT_1800777d8;
    plVar3 = (longlong *)PTR_DAT_1800777d0;
    if (PTR_DAT_1800777d0 < PTR_DAT_1800777d8) {
      do {
        if (*plVar3 != 0) {
          puVar1 = *(undefined8 **)(*plVar3 + 0x20);
          Ptr = (PVOID)*puVar1;
          if (Ptr != (PVOID)0x0) {
            plVar2 = DecodePointer(Ptr);
            (**(code **)(*plVar2 + 0x10))(plVar2);
            *puVar1 = 0;
            plVar2 = (longlong *)PTR_DAT_1800777d8;
          }
        }
        plVar3 = plVar3 + 1;
      } while (plVar3 < plVar2);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_1800777e0);
    DAT_1800777c0 = 0;
  }
  return;
}

/* ---- FUNC 000604C0 FUN_1800604c0 (99 bytes) ---- */

void FUN_1800604c0(void)

{
  char cVar1;
  longlong *plVar2;
  longlong *plVar3;
  
  cVar1 = *(char *)((longlong)*(longlong **)((longlong)DAT_180079c30 + 8) + 0x19);
  plVar3 = *(longlong **)((longlong)DAT_180079c30 + 8);
  while (cVar1 == '\0') {
    FUN_180041b90(&DAT_180079c30,&DAT_180079c30,(longlong *)plVar3[2]);
    plVar2 = (longlong *)*plVar3;
    FUN_180025ad0(plVar3);
    plVar3 = plVar2;
    cVar1 = *(char *)((longlong)plVar2 + 0x19);
  }
  FUN_180025ad0(DAT_180079c30);
  return;
}

/* ---- FUNC 00060530 FUN_180060530 (14 bytes) ---- */

void FUN_180060530(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180060537. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  VariantClear((VARIANTARG *)&DAT_180077858);
  return;
}
