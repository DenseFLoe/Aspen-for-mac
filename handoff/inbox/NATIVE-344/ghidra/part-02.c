/* RVA 0x6100 */
void FUN_180006100(undefined8 param_1,void *param_2,longlong param_3)

{
  void *pvVar1;
  
  pvVar1 = param_2;
  if ((0xfff < (ulonglong)(param_3 << 5)) &&
     (pvVar1 = *(void **)((longlong)param_2 + -8),
     0x1f < (ulonglong)((longlong)param_2 + (-8 - (longlong)pvVar1)))) {
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
  FUN_180001300(pvVar1);
  return;
}

/* RVA 0x6150 */
char * FUN_180006150(longlong param_1)

{
  char *pcVar1;
  
  pcVar1 = "Unknown exception";
  if (*(char **)(param_1 + 8) != (char *)0x0) {
    pcVar1 = *(char **)(param_1 + 8);
  }
  return pcVar1;
}

/* RVA 0x6170 */
void FUN_180006170(longlong param_1,undefined4 param_2,int param_3,undefined4 param_4,char *param_5,
                  int param_6)

{
  longlong *plVar1;
  CSimSeqObj *this;
  int iVar2;
  CSimSeqTree *pCVar3;
  CSimSeqObj *pCVar4;
  CSimSeqObj local_a8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_a0 [8];
  undefined4 local_98;
  CSimSeqObj local_88 [32];
  longlong *local_68;
  longlong local_60 [5];
  
  if (param_6 != 0) {
    pCVar4 = *(CSimSeqObj **)(param_1 + 8);
    plVar1 = (longlong *)(param_1 + 8);
    if (pCVar4 != *(CSimSeqObj **)(param_1 + 0x10)) {
      do {
        iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           (pCVar4 + 8),param_5);
        if (iVar2 == 0) {
          CSimSeqObj::CSimSeqObj(local_a8);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    (local_a0,param_5);
          local_98 = 99;
          if (param_3 == 1) {
            this = *(CSimSeqObj **)(param_1 + 0x10);
            if (this == *(CSimSeqObj **)(param_1 + 0x18)) {
              pCVar4 = FUN_180004620(plVar1,pCVar4,local_a8);
              pCVar4 = pCVar4 + 0x20;
              CSimSeqObj::~CSimSeqObj(local_a8);
            }
            else if (pCVar4 == this) {
              CSimSeqObj::CSimSeqObj(this,local_a8);
              *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x20;
              pCVar4 = pCVar4 + 0x20;
              CSimSeqObj::~CSimSeqObj(local_a8);
            }
            else {
              local_68 = plVar1;
              CSimSeqObj::CSimSeqObj((CSimSeqObj *)local_60,local_a8);
              CSimSeqObj::CSimSeqObj(this,this + -0x20);
              *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x20;
              FUN_180004d30((longlong)pCVar4,(longlong)(this + -0x20),this);
              CSimSeqObj::operator=(pCVar4,local_88);
              CSimSeqObj::~CSimSeqObj(local_88);
              (**(code **)(local_60[0] + 8))(local_60,0);
              pCVar4 = pCVar4 + 0x20;
              CSimSeqObj::~CSimSeqObj(local_a8);
            }
          }
          else {
            if (pCVar4 + 0x20 == *(CSimSeqObj **)(param_1 + 0x10)) {
              pCVar4 = *(CSimSeqObj **)(param_1 + 0x10);
              if (pCVar4 == *(CSimSeqObj **)(param_1 + 0x18)) {
                FUN_180004620(plVar1,pCVar4,local_a8);
              }
              else {
                CSimSeqObj::CSimSeqObj(pCVar4,local_a8);
                *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x20;
              }
              CSimSeqObj::~CSimSeqObj(local_a8);
              return;
            }
            CSimSeqObj::~CSimSeqObj(local_a8);
          }
        }
        else {
          pCVar3 = CSimSeqObj::GetChildren(pCVar4);
          FUN_180006170((longlong)pCVar3,param_2,param_3,param_4,param_5,param_6);
        }
        pCVar4 = pCVar4 + 0x20;
      } while (pCVar4 != *(CSimSeqObj **)(param_1 + 0x10));
    }
  }
  return;
}

/* RVA 0x63a0 */
void AllowInputPopMsg(byte param_1)

{
                    /* 0x63a0  143  AllowInputPopMsg */
  DAT_180050de0 = (uint)param_1;
  return;
}

/* RVA 0x63b0 */
HRESULT __stdcall DllCanUnloadNow(void)

{
  long lVar1;
  AFX_MODULE_STATE *pAVar2;
  AFX_MAINTAIN_STATE2 local_18 [16];
  
                    /* 0x63b0  10  DllCanUnloadNow */
  pAVar2 = AfxGetModuleState();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_18,pAVar2);
  lVar1 = AfxDllCanUnloadNow();
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_18);
  return lVar1;
}

/* RVA 0x63f0 */
undefined8 FUN_1800063f0(HINSTANCE__ *param_1,int param_2)

{
  if (param_2 == 1) {
    AfxInitExtensionModule((AFX_EXTENSION_MODULE *)&DAT_180051b68,param_1);
    SimResetDllGobal();
    StgCreateDocfile((WCHAR *)0x0,0x4000012,0,(IStorage **)&DAT_180051ba8);
    (**(code **)(*DAT_180051ba8 + 0x18))(DAT_180051ba8,L"CONTROL PANEL",0x12,0,0,&DAT_180051ba0);
    return 1;
  }
  if (param_2 == 0) {
    if (DAT_180051ba0 != (longlong *)0x0) {
      (**(code **)(*DAT_180051ba0 + 0x10))();
      DAT_180051ba0 = (longlong *)0x0;
    }
    if (DAT_180051ba8 != (longlong *)0x0) {
      (**(code **)(*DAT_180051ba8 + 0x10))();
    }
  }
  return 1;
}

/* RVA 0x64a0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1800064a0(longlong param_1)

{
  char cVar1;
  longlong *plVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  longlong *plVar6;
  longlong *plVar7;
  void *pvVar8;
  longlong lVar9;
  longlong *plVar10;
  size_t sVar11;
  undefined1 auStack_b8 [32];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_98 [8];
  void *local_90;
  void *local_88 [2];
  longlong *local_78;
  undefined8 uStack_70;
  void *local_58;
  longlong lStack_50;
  longlong local_48;
  ulonglong uStack_40;
  ulonglong local_38;
  
  plVar7 = DAT_180051bd0;
  local_38 = DAT_1800516d8 ^ (ulonglong)auStack_b8;
  cVar1 = *(char *)(DAT_180051bd0[1] + 0x19);
  plVar6 = (longlong *)DAT_180051bd0[1];
  while (cVar1 == '\0') {
    FUN_1800047a0(&DAT_180051bd0,&DAT_180051bd0,(longlong *)plVar6[2]);
    plVar2 = (longlong *)*plVar6;
    FUN_180005800(plVar6 + 4);
    FUN_180001300(plVar6);
    plVar6 = plVar2;
    cVar1 = *(char *)((longlong)plVar2 + 0x19);
  }
  plVar7[1] = (longlong)plVar7;
  *plVar7 = (longlong)plVar7;
  plVar7[2] = (longlong)plVar7;
  DAT_180051bd8 = 0;
  lVar9 = *(longlong *)(param_1 + 8);
  if (lVar9 != *(longlong *)(param_1 + 0x10)) {
    do {
      if (*(int *)(lVar9 + 0x10) == 0x10) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  (local_98,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                             *)(lVar9 + 8));
        iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                          (local_98,'.');
        if (iVar4 != -1) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                    (local_98,(int)local_88);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                    (local_98,(int)&local_90);
          local_58 = (void *)0x0;
          lStack_50 = 0;
          local_48 = 0;
          sVar11 = 0xffffffffffffffff;
          uStack_40 = 0;
          do {
            sVar11 = sVar11 + 1;
          } while (*(char *)((longlong)local_88[0] + sVar11) != '\0');
          FUN_1800044f0(&local_58,local_88[0],sVar11);
          pvVar8 = local_90;
          plVar2 = DAT_180051bd0;
          uStack_70 = uStack_70 & 0xffffffff00000000;
          local_78 = (longlong *)DAT_180051bd0[1];
          cVar1 = *(char *)((longlong)local_78 + 0x19);
          plVar6 = local_78;
          plVar7 = DAT_180051bd0;
          while (plVar10 = plVar6, cVar1 == '\0') {
            local_78 = plVar10;
            uVar5 = FUN_180004440(plVar10 + 4,&local_58);
            if ((char)uVar5 == '\0') {
              uStack_70 = CONCAT44(uStack_70._4_4_,1);
              plVar6 = (longlong *)*plVar10;
            }
            else {
              plVar6 = (longlong *)plVar10[2];
              uStack_70 = (ulonglong)uStack_70._4_4_ << 0x20;
              plVar10 = plVar7;
            }
            cVar1 = *(char *)((longlong)plVar6 + 0x19);
            plVar7 = plVar10;
          }
          if ((*(char *)((longlong)plVar7 + 0x19) != '\0') ||
             (uVar5 = FUN_180004440(&local_58,plVar7 + 4), (char)uVar5 != '\0')) {
            if (DAT_180051bd8 == 0x2aaaaaaaaaaaaaa) {
              FUN_180005ef0();
              pcVar3 = (code *)swi(3);
              (*pcVar3)();
              return;
            }
            plVar6 = operator_new(0x60);
            plVar6[6] = 0;
            plVar6[7] = 0;
            plVar6[4] = (longlong)local_58;
            plVar6[5] = lStack_50;
            plVar6[6] = local_48;
            plVar6[7] = uStack_40;
            local_48 = 0;
            uStack_40 = 0xf;
            local_58 = (void *)((ulonglong)local_58 & 0xffffffffffffff00);
            plVar6[8] = 0;
            plVar6[9] = 0;
            plVar6[10] = 0;
            plVar6[0xb] = 0xf;
            *(undefined1 *)(plVar6 + 8) = 0;
            *plVar6 = (longlong)plVar2;
            plVar6[1] = (longlong)plVar2;
            plVar6[2] = (longlong)plVar2;
            *(undefined2 *)(plVar6 + 3) = 0;
            plVar7 = FUN_180005b90((longlong *)&DAT_180051bd0,(longlong *)&local_78,plVar6);
          }
          sVar11 = 0xffffffffffffffff;
          do {
            sVar11 = sVar11 + 1;
          } while (*(char *)((longlong)pvVar8 + sVar11) != '\0');
          FUN_180005fa0(plVar7 + 8,pvVar8,sVar11);
          if (0xf < uStack_40) {
            pvVar8 = local_58;
            if ((0xfff < uStack_40 + 1) &&
               (pvVar8 = *(void **)((longlong)local_58 + -8),
               0x1f < (ulonglong)((longlong)local_58 + (-8 - (longlong)pvVar8)))) {
                    /* WARNING: Subroutine does not return */
              _invalid_parameter_noinfo_noreturn();
            }
            FUN_180001300(pvVar8);
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_90);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_88);
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_98);
      }
      lVar9 = lVar9 + 0x20;
    } while (lVar9 != *(longlong *)(param_1 + 0x10));
  }
  return;
}

/* RVA 0x6790 */
undefined4 SBaskreexc(LPCSTR param_1)

{
  int cchWideChar;
  int iVar1;
  undefined4 uVar2;
  BSTR lpWideCharStr;
  
                    /* 0x6790  149  SBaskreexc */
  lpWideCharStr = (BSTR)0x0;
  if (param_1 != (LPCSTR)0x0) {
    cchWideChar = MultiByteToWideChar(0,0,param_1,-1,(LPWSTR)0x0,0);
    lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,cchWideChar - 1);
    if (lpWideCharStr != (BSTR)0x0) {
      iVar1 = MultiByteToWideChar(0,0,param_1,-1,lpWideCharStr,cchWideChar);
      if (iVar1 != cchWideChar) {
        SysFreeString(lpWideCharStr);
        goto LAB_18000682b;
      }
    }
    if (lpWideCharStr == (BSTR)0x0) {
LAB_18000682b:
                    /* WARNING: Subroutine does not return */
      FUN_180001380(-0x7ff8fff2);
    }
  }
  uVar2 = FUN_1800098c0(lpWideCharStr);
  SysFreeString(lpWideCharStr);
  return uVar2;
}

/* RVA 0x6840 */
void FUN_180006840(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  int *piVar3;
  int local_res10 [2];
  int local_res18 [2];
  int local_res20 [2];
  
  iVar1 = FUN_1800213f0();
  if (iVar1 != 0) {
    lVar2 = FUN_1800213d0();
    piVar3 = FUN_180021540(lVar2,local_res20,local_res18,local_res10);
    while (piVar3 != (int *)0x0) {
      if (local_res10[0] != 0) {
        FUN_180006170(param_1,1,local_res20[0],local_res18[0],(char *)piVar3,local_res10[0]);
      }
      piVar3 = FUN_180021540(lVar2,local_res20,local_res18,local_res10);
    }
  }
  return;
}

/* RVA 0x68d0 */
void FUN_1800068d0(char *param_1,int param_2)

{
  char cVar1;
  HGLOBAL pvVar2;
  longlong lVar4;
  longlong lVar3;
  
  pvVar2 = (HGLOBAL)0x0;
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_1[lVar3] != '\0');
    pvVar2 = GlobalAlloc(0,lVar4 + 2);
    lVar3 = (longlong)pvVar2 - (longlong)param_1;
    do {
      cVar1 = *param_1;
      param_1[lVar3] = cVar1;
      param_1 = param_1 + 1;
    } while (cVar1 != '\0');
  }
  SimSendMainWndMessage(0x532,(longlong)param_2,pvVar2);
  return;
}

/* RVA 0x6940 */
void SimAnimateSequenceView(char *param_1,int param_2)

{
                    /* 0x6940  26  SimAnimateSequenceView */
  FUN_1800068d0(param_1,param_2);
  return;
}

/* RVA 0x6950 */
void FUN_180006950(void)

{
  void *pvVar1;
  longlong *plVar2;
  int iVar3;
  undefined8 *puVar4;
  void *pvVar5;
  longlong lVar6;
  longlong *plVar7;
  ulonglong uVar8;
  longlong *local_28;
  longlong *plStack_20;
  longlong local_18;
  
  iVar3 = CApwnEOStatus::IsEmpty((CApwnEOStatus *)g_ApwnEOStatusMap_exref);
  if (iVar3 == 0) {
    local_18 = 0;
    local_28 = (longlong *)0x0;
    plStack_20 = (longlong *)0x0;
    CApwnEOStatus::Excluded
              ((CApwnEOStatus *)g_ApwnEOStatusMap_exref,
               (vector<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>_>_>
                *)&local_28);
    uVar8 = (longlong)plStack_20 - (longlong)local_28 >> 5;
    if (uVar8 != 0) {
      iVar3 = 0;
      lVar6 = 0;
      do {
        puVar4 = (undefined8 *)(lVar6 + (longlong)local_28);
        if (0xf < *(ulonglong *)(lVar6 + 0x18 + (longlong)local_28)) {
          puVar4 = (undefined8 *)*puVar4;
        }
        SimEnablePFSBlock((LPARAM)puVar4,1);
        iVar3 = iVar3 + 1;
        lVar6 = lVar6 + 0x20;
      } while ((ulonglong)(longlong)iVar3 < uVar8);
    }
    CApwnEOStatus::RemoveAll((CApwnEOStatus *)g_ApwnEOStatusMap_exref);
    plVar2 = plStack_20;
    plVar7 = local_28;
    if (local_28 != (longlong *)0x0) {
      for (; plVar7 != plVar2; plVar7 = plVar7 + 4) {
        if (0xf < (ulonglong)plVar7[3]) {
          pvVar1 = (void *)*plVar7;
          pvVar5 = pvVar1;
          if ((0xfff < plVar7[3] + 1U) &&
             (pvVar5 = *(void **)((longlong)pvVar1 + -8),
             0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar5)))) goto LAB_180006aa0;
          FUN_180001300(pvVar5);
        }
        plVar7[2] = 0;
        plVar7[3] = 0xf;
        *(undefined1 *)plVar7 = 0;
      }
      plVar7 = local_28;
      if ((0xfff < (local_18 - (longlong)local_28 & 0xffffffffffffffe0U)) &&
         (plVar7 = (longlong *)local_28[-1],
         (undefined1 *)0x1f < (undefined1 *)((longlong)local_28 + (-8 - (longlong)plVar7)))) {
LAB_180006aa0:
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      FUN_180001300(plVar7);
    }
  }
  return;
}

/* RVA 0x6ad0 */
void FUN_180006ad0(void)

{
  longlong *plVar1;
  longlong *plVar2;
  
  plVar1 = DAT_18004f610;
  plVar2 = DAT_18004f608;
  if (DAT_18004f608 != DAT_18004f610) {
    do {
      (**(code **)(*plVar2 + 8))(plVar2,0);
      plVar2 = plVar2 + 4;
    } while (plVar2 != plVar1);
    DAT_18004f610 = DAT_18004f608;
  }
  plVar1 = DAT_18004f630;
  plVar2 = DAT_18004f628;
  if (DAT_18004f628 != DAT_18004f630) {
    do {
      (**(code **)(*plVar2 + 8))(plVar2,0);
      plVar2 = plVar2 + 4;
    } while (plVar2 != plVar1);
    DAT_18004f630 = DAT_18004f628;
  }
  return;
}

/* RVA 0x6b60 */
bool FUN_180006b60(LPCSTR param_1,LPCSTR param_2)

{
  BOOL BVar1;
  
  BVar1 = CopyFileA(param_1,param_2,0);
  return BVar1 == 1;
}

/* RVA 0x6b80 */
void SimEnablePFSBlock(LPARAM param_1,int param_2)

{
  AFX_MODULE_STATE *pAVar1;
  CWinThread *pCVar2;
  longlong lVar3;
  AFX_MAINTAIN_STATE2 local_18 [16];
  
                    /* 0x6b80  122  SimEnablePFSBlock */
  pAVar1 = AfxGetModuleState();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_18,pAVar1);
  pCVar2 = AfxGetThread();
  if (pCVar2 != (CWinThread *)0x0) {
    lVar3 = (**(code **)(*(longlong *)pCVar2 + 0xf8))(pCVar2);
    if (lVar3 != 0) {
      SendMessageA(*(HWND *)(lVar3 + 0x40),0x54e,(longlong)param_2,param_1);
    }
  }
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_18);
  return;
}

/* RVA 0x6bf0 */
undefined8 FUN_180006bf0(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  char *_Str;
  char *pcVar3;
  char *pcVar4;
  char *_Dest;
  CSimSeqObj *this;
  size_t _Count;
  longlong lVar5;
  longlong lVar6;
  undefined **ppuVar7;
  
  if (param_1 < 0) {
    return 1;
  }
  _Str = _strdup(param_2);
  _Count = 0;
  _Dest = (char *)0x0;
  pcVar3 = strchr(_Str,0x2e);
  if (pcVar3 != (char *)0x0) {
    *pcVar3 = '\0';
    _Count = (longlong)pcVar3 - (longlong)_Str;
  }
  ppuVar7 = &PTR_vftable_18004f600;
  pcVar3 = _Str;
  if (param_1 == 10) {
    ppuVar7 = &PTR_vftable_18004f620;
  }
  do {
    iVar1 = (int)(*(longlong *)((longlong)ppuVar7 + 0x10) - *(longlong *)((longlong)ppuVar7 + 8) >>
                 5);
    if (iVar1 == 0) {
      (*(code *)PTR_FUN_180044148)(_Dest,param_1 == 10);
      iVar1 = (int)(*(longlong *)((longlong)ppuVar7 + 0x10) - *(longlong *)((longlong)ppuVar7 + 8)
                   >> 5);
    }
    lVar6 = 0;
    if (0 < iVar1) {
      lVar5 = 0;
      do {
        this = (CSimSeqObj *)(*(longlong *)((longlong)ppuVar7 + 8) + lVar5);
        if (*(int *)(this + 0x10) == param_1) {
          iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             (this + 8),pcVar3);
          if (iVar2 == 0) {
            if (_Dest != (char *)0x0) {
              free(_Dest);
            }
            free(_Str);
            return 1;
          }
        }
        else if (((*(int *)(this + 0x10) == -1) && (_Count != 0)) &&
                (iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                                   ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
                                    )(this + 8),pcVar3), iVar2 == 0)) {
          if (_Dest != (char *)0x0) {
            free(_Dest);
          }
          _Dest = malloc(_Count + 1);
          strncpy(_Dest,param_2,_Count);
          _Dest[_Count] = '\0';
          ppuVar7 = (undefined **)CSimSeqObj::GetChildren(this);
          goto LAB_180006d5d;
        }
        lVar6 = lVar6 + 1;
        lVar5 = lVar5 + 0x20;
      } while (lVar6 < iVar1);
    }
    if (_Count == 0) break;
LAB_180006d5d:
    lVar6 = _Count + 1;
    _Count = 0;
    pcVar3 = _Str + lVar6;
    pcVar4 = strchr(pcVar3,0x2e);
    if (pcVar4 != (char *)0x0) {
      *pcVar4 = '\0';
      _Count = (longlong)pcVar4 - (longlong)_Str;
    }
  } while (pcVar3 != (char *)0x0);
  if (_Dest != (char *)0x0) {
    free(_Dest);
  }
  free(_Str);
  return 0;
}

/* RVA 0x6e20 */
undefined4 FUN_180006e20(char *param_1)

{
  int iVar1;
  int iVar2;
  char *_Str;
  char *pcVar3;
  char *_Dest;
  char *pcVar4;
  CSimSeqObj *this;
  size_t _Count;
  longlong lVar5;
  longlong lVar6;
  undefined **ppuVar7;
  
  _Str = _strdup(param_1);
  _Count = 0;
  _Dest = (char *)0x0;
  pcVar3 = strchr(_Str,0x2e);
  if (pcVar3 != (char *)0x0) {
    *pcVar3 = '\0';
    _Count = (longlong)pcVar3 - (longlong)_Str;
  }
  ppuVar7 = &PTR_vftable_18004f600;
  pcVar3 = _Str;
  do {
    iVar1 = (int)(*(longlong *)((longlong)ppuVar7 + 0x10) - *(longlong *)((longlong)ppuVar7 + 8) >>
                 5);
    if (iVar1 == 0) {
      (*(code *)PTR_FUN_180044148)(_Dest,0);
      iVar1 = (int)(*(longlong *)((longlong)ppuVar7 + 0x10) - *(longlong *)((longlong)ppuVar7 + 8)
                   >> 5);
    }
    lVar6 = 0;
    if (0 < iVar1) {
      lVar5 = 0;
      do {
        this = (CSimSeqObj *)(*(longlong *)((longlong)ppuVar7 + 8) + lVar5);
        if ((*(int *)(this + 0x10) == -1) && (_Count != 0)) {
          iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             (this + 8),pcVar3);
          if (iVar2 == 0) {
            if (_Dest != (char *)0x0) {
              free(_Dest);
            }
            _Dest = malloc(_Count + 1);
            strncpy(_Dest,param_1,_Count);
            _Dest[_Count] = '\0';
            ppuVar7 = (undefined **)CSimSeqObj::GetChildren(this);
            goto LAB_180006f41;
          }
        }
        else {
          iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             (this + 8),pcVar3);
          if (iVar2 == 0) {
            if (_Dest != (char *)0x0) {
              free(_Dest);
            }
            free(_Str);
            return *(undefined4 *)(this + 0x10);
          }
        }
        lVar6 = lVar6 + 1;
        lVar5 = lVar5 + 0x20;
      } while (lVar6 < iVar1);
    }
    if (_Count == 0) break;
LAB_180006f41:
    lVar6 = _Count + 1;
    _Count = 0;
    pcVar3 = _Str + lVar6;
    pcVar4 = strchr(pcVar3,0x2e);
    if (pcVar4 != (char *)0x0) {
      *pcVar4 = '\0';
      _Count = (longlong)pcVar4 - (longlong)_Str;
    }
  } while (pcVar3 != (char *)0x0);
  if (_Dest != (char *)0x0) {
    free(_Dest);
  }
  free(_Str);
  return 0;
}

/* RVA 0x6fc0 */
undefined8 FUN_180006fc0(char param_1,char *param_2,char *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_18 [16];
  
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_18,param_3);
  uVar5 = 0;
  if (DAT_180051bc0 == 0) {
    if (param_1 == 'i') {
      uVar4 = 0x40;
    }
    else if (param_1 == 'e') {
      uVar4 = 0x30;
    }
    else {
      uVar4 = 0x10;
      if (param_1 == 'q') {
        uVar4 = 0x20;
      }
    }
    iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                      (local_18,"ABORTRETRYIGNORE");
    if (iVar1 == 0) {
      uVar4 = uVar4 | 2;
    }
    else {
      iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        (local_18,"YESNOCANCEL");
      if (iVar1 == 0) {
        uVar4 = uVar4 | 3;
      }
      else {
        iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                          (local_18,"RETRYCANCEL");
        if (iVar1 == 0) {
          uVar4 = uVar4 | 5;
        }
        else {
          iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                            (local_18,"YN");
          if (iVar1 == 0) {
            uVar4 = uVar4 | 4;
          }
          else {
            iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                              (local_18,"OKCANCEL");
            if (iVar1 == 0) {
              uVar4 = uVar4 | 1;
            }
          }
        }
      }
    }
    if (param_4 == 2) {
      uVar3 = 0x200;
    }
    else {
      uVar3 = 0;
      if (param_4 == 1) {
        uVar3 = 0x100;
      }
    }
    iVar1 = MMMessageBoxDefault(uVar4 | uVar3);
    iVar2 = MMGetSuppress();
    if (iVar2 == 0) {
      iVar1 = MMAfxMessageBox(param_2,uVar4 | uVar3,0,0);
    }
    if ((iVar1 != 6) && (iVar1 != 1)) {
      uVar5 = 1;
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_18);
  return uVar5;
}

/* RVA 0x7130 */
bool SimGetConnectInfo2(char *param_1,undefined *param_2,uint *param_3)

{
  undefined8 uVar1;
  
                    /* 0x7130  131  SimGetConnectInfo2 */
  uVar1 = FUN_180026c20(param_1,param_2,param_3);
  return (int)uVar1 == -1;
}

/* RVA 0x7150 */
void SimGetCurSeqBlock(char *param_1,undefined4 *param_2)

{
  char cVar1;
  char *pcVar2;
  longlong lVar3;
  
                    /* 0x7150  181  SimGetCurSeqBlock */
  lVar3 = -1;
  pcVar2 = (char *)(*(longlong *)topfinfo_exref + 0x4c2);
  do {
    lVar3 = lVar3 + 1;
  } while (pcVar2[lVar3] != '\0');
  if (lVar3 == 0) {
    *param_1 = '\0';
    *param_2 = 0;
    return;
  }
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    *param_1 = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  *param_2 = *(undefined4 *)(*(longlong *)topfinfo_exref + 0x50c);
  return;
}

/* RVA 0x7180 */
bool FUN_180007180(LPSTR param_1,DWORD param_2)

{
  BOOL BVar1;
  DWORD local_res10 [6];
  
  if (param_1 == (LPSTR)0x0) {
    return false;
  }
  local_res10[0] = param_2;
  BVar1 = GetUserNameA(param_1,local_res10);
  return BVar1 == 1;
}

/* RVA 0x71b0 */
uint FUN_1800071b0(undefined4 param_1,LPCSTR param_2,longlong *param_3)

{
  int cchWideChar;
  int iVar1;
  undefined4 *puVar2;
  BSTR lpWideCharStr;
  longlong lVar3;
  
  puVar2 = CoTaskMemAlloc(0x18);
  *puVar2 = param_1;
  lpWideCharStr = (BSTR)0x0;
  if (param_2 != (LPCSTR)0x0) {
    cchWideChar = MultiByteToWideChar(0,0,param_2,-1,(LPWSTR)0x0,0);
    lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,cchWideChar - 1);
    if ((lpWideCharStr != (BSTR)0x0) &&
       (iVar1 = MultiByteToWideChar(0,0,param_2,-1,lpWideCharStr,cchWideChar), iVar1 != cchWideChar)
       ) {
      SysFreeString(lpWideCharStr);
      lpWideCharStr = (BSTR)0x0;
    }
  }
  *(BSTR *)(puVar2 + 2) = lpWideCharStr;
  *(longlong **)(puVar2 + 4) = param_3;
  if (param_3 != (longlong *)0x0) {
    (**(code **)(*param_3 + 8))(param_3);
  }
  lVar3 = FUN_180007640(0x555,puVar2,0);
  return -(uint)(lVar3 != 0) & 0x80004005;
}

/* RVA 0x72a0 */
void FUN_1800072a0(void)

{
  AFX_MODULE_STATE *pAVar1;
  AFX_MAINTAIN_STATE2 local_18 [24];
  
  pAVar1 = AfxGetModuleState();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_18,pAVar1);
  FUN_1800074b0(0x55d,0,0);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_18);
  return;
}

/* RVA 0x72e0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SimIsBlockInBatchHierarchy(char *param_1)

{
  char cVar1;
  undefined8 *puVar2;
  int iVar3;
  uint uVar4;
  void *pvVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  longlong lVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  size_t sVar11;
  undefined1 auStack_68 [32];
  char *local_48;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_40 [8];
  void *local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong uStack_20;
  ulonglong local_18;
  
                    /* 0x72e0  179  SimIsBlockInBatchHierarchy */
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_68;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_40,param_1);
  iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                    (local_40,'.');
  if (iVar3 == -1) {
    uVar7 = 0;
    goto LAB_180007452;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left(local_40,(int)&local_48);
  if (DAT_180051bd8 == 0) {
LAB_180007445:
    uVar7 = 0;
  }
  else {
    sVar11 = 0xffffffffffffffff;
    local_38 = (void *)0x0;
    uStack_30 = 0;
    local_28 = 0;
    uStack_20 = 0;
    do {
      sVar11 = sVar11 + 1;
    } while (local_48[sVar11] != '\0');
    FUN_1800044f0(&local_38,local_48,sVar11);
    puVar2 = DAT_180051bd0;
    cVar1 = *(char *)((longlong)DAT_180051bd0[1] + 0x19);
    puVar6 = (undefined8 *)DAT_180051bd0[1];
    puVar10 = DAT_180051bd0;
    while (puVar9 = puVar6, cVar1 == '\0') {
      uVar4 = FUN_180004440(puVar9 + 4,&local_38);
      if ((char)uVar4 == '\0') {
        puVar6 = (undefined8 *)*puVar9;
      }
      else {
        puVar6 = (undefined8 *)puVar9[2];
        puVar9 = puVar10;
      }
      cVar1 = *(char *)((longlong)puVar6 + 0x19);
      puVar10 = puVar9;
    }
    if ((*(char *)((longlong)puVar10 + 0x19) != '\0') ||
       (uVar4 = FUN_180004440(&local_38,puVar10 + 4), (char)uVar4 != '\0')) {
      puVar10 = puVar2;
    }
    if (0xf < uStack_20) {
      pvVar5 = local_38;
      if ((0xfff < uStack_20 + 1) &&
         (pvVar5 = *(void **)((longlong)local_38 + -8),
         0x1f < (ulonglong)((longlong)local_38 + (-8 - (longlong)pvVar5)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      FUN_180001300(pvVar5);
    }
    if (puVar10 == puVar2) goto LAB_180007445;
    lVar8 = (longlong)param_1 - (longlong)local_48;
    do {
      cVar1 = *local_48;
      local_48[lVar8] = cVar1;
      local_48 = local_48 + 1;
    } while (cVar1 != '\0');
    uVar7 = 1;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48);
LAB_180007452:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_40);
  return uVar7;
}

/* RVA 0x7490 */
undefined8 SimIsCurSeqBlockBatchandInInterMode(char *param_1)

{
  undefined8 uVar1;
  
                    /* 0x7490  180  SimIsCurSeqBlockBatchandInInterMode */
  uVar1 = SimIsBlockInBatchHierarchy((char *)(*(longlong *)topfinfo_exref + 0x4c2));
  return uVar1;
}

/* RVA 0x74a0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SimLoadSummary(void)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  undefined1 auStackY_158 [32];
  char acStack_128 [272];
  ulonglong uStack_18;
  
                    /* 0x74a0  185  SimLoadSummary */
  uStack_18 = DAT_1800516d8 ^ (ulonglong)auStackY_158;
  uVar1 = *(undefined4 *)partial_results_exref;
  *(undefined4 *)partial_results_exref = 0;
  pcVar3 = (char *)GetSorResStringEx(0x782);
  iVar2 = FUN_180030240(pcVar3,acStack_128,0,0x9010000,(char *)0x0);
  if (0 < iVar2) {
    FUN_18002c620((longlong)APtmpfil_exref);
    GRsetrpt(1);
  }
  *(undefined4 *)partial_results_exref = uVar1;
  iVar2 = FUN_180024de0();
  if (0 < iVar2) {
    *(undefined4 *)sum_header_exref = 1;
    FUN_18002c620((longlong)APtmpfil_exref);
    *(undefined4 *)sum_header_exref = 0;
  }
  return iVar2;
}

/* RVA 0x74b0 */
undefined8 FUN_1800074b0(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  LPSTREAM pStm;
  DWORD DVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  longlong *local_res20;
  undefined8 local_28 [2];
  
  local_28[0] = 0;
  if (DAT_180051bb0 != (longlong *)0x0) {
    DVar1 = GetCurrentThreadId();
    if ((DVar1 == DAT_18004f724) || (DAT_18004f724 == 0xffffffff)) {
      (**(code **)(*DAT_180051bb0 + 0x28))(DAT_180051bb0,param_1,param_2,param_3,local_28);
    }
    else if (DAT_180051bb8 != (LPSTREAM)0x0) {
      iVar4 = 0;
      iVar2 = TryEnterCriticalSection(*(LPCRITICAL_SECTION *)HACriticalSection_exref);
      while (iVar2 == 0) {
        iVar4 = iVar4 + 1;
        if (4 < iVar4) {
          return 0;
        }
        Sleep(5);
        iVar2 = TryEnterCriticalSection(*(LPCRITICAL_SECTION *)HACriticalSection_exref);
      }
      uVar3 = MDclrcrt(*(undefined8 *)HACriticalSection_exref);
      pStm = DAT_180051bb8;
      local_res20 = (longlong *)0x0;
      if (DAT_180051bb8 != (LPSTREAM)0x0) {
        (*DAT_180051bb8->lpVtbl->Seek)(DAT_180051bb8,(LARGE_INTEGER)0x0,0,(ULARGE_INTEGER *)0x0);
        CoUnmarshalInterface(pStm,(IID *)&DAT_1800410e8,&local_res20);
        if (local_res20 != (longlong *)0x0) {
          (**(code **)(*local_res20 + 0x28))(local_res20,param_1,param_2,param_3,local_28);
          (**(code **)(*local_res20 + 0x10))();
        }
      }
      if (*(longlong *)HACriticalSection_exref != 0) {
        MDsetcrt(*(longlong *)HACriticalSection_exref,uVar3);
        LeaveCriticalSection(*(LPCRITICAL_SECTION *)HACriticalSection_exref);
      }
    }
  }
  return local_28[0];
}

/* RVA 0x7640 */
undefined8 FUN_180007640(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  LPSTREAM pStm;
  DWORD DVar1;
  BOOL BVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 local_res20;
  longlong *local_28 [2];
  
  local_res20 = 0;
  if (DAT_180051bb0 == (longlong *)0x0) {
    return 0;
  }
  DVar1 = GetCurrentThreadId();
  if ((DVar1 == DAT_18004f724) || (DAT_18004f724 == 0xffffffff)) {
    (**(code **)(*DAT_180051bb0 + 0x28))(DAT_180051bb0,param_1,param_2,param_3,&local_res20);
  }
  else if (DAT_180051bb8 != (LPSTREAM)0x0) {
    iVar4 = 0;
    do {
      BVar2 = TryEnterCriticalSection(*(LPCRITICAL_SECTION *)HACriticalSection_exref);
      if (BVar2 != 0) {
        uVar3 = MDclrcrt(*(undefined8 *)HACriticalSection_exref);
        pStm = DAT_180051bb8;
        local_28[0] = (longlong *)0x0;
        if (DAT_180051bb8 != (LPSTREAM)0x0) {
          (*DAT_180051bb8->lpVtbl->Seek)(DAT_180051bb8,(LARGE_INTEGER)0x0,0,(ULARGE_INTEGER *)0x0);
          CoUnmarshalInterface(pStm,(IID *)&DAT_1800410e8,local_28);
          if (local_28[0] != (longlong *)0x0) {
            (**(code **)(*local_28[0] + 0x28))(local_28[0],param_1,param_2,param_3,&local_res20);
            (**(code **)(*local_28[0] + 0x10))();
          }
        }
        if (*(longlong *)HACriticalSection_exref != 0) {
          MDsetcrt(*(longlong *)HACriticalSection_exref,uVar3);
          LeaveCriticalSection(*(LPCRITICAL_SECTION *)HACriticalSection_exref);
        }
        return local_res20;
      }
      Sleep(5);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 5);
    return local_res20;
  }
  return local_res20;
}

/* RVA 0x77e0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1800077e0(longlong param_1,int param_2,int param_3)

{
  longlong *plVar1;
  CSimSeqObj *pCVar2;
  undefined **ppuVar3;
  char cVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  CSimSeqTree *pCVar8;
  int iVar9;
  int *piVar10;
  longlong *plVar11;
  ulonglong uVar12;
  CSimSeqObj *pCVar13;
  undefined **ppuVar14;
  longlong lVar15;
  int iVar16;
  undefined ***pppuVar17;
  longlong lVar18;
  int iVar19;
  undefined1 auStack_5a8 [32];
  int local_588;
  int local_584;
  undefined **local_580;
  CSimSeqObj *local_578;
  CSimSeqObj *pCStack_570;
  CSimSeqObj *local_568;
  longlong local_560;
  undefined **local_558;
  CSimSeqObj *local_550;
  CSimSeqObj *pCStack_548;
  CSimSeqObj *local_540;
  int local_538;
  int local_534;
  undefined **local_530;
  char *local_528;
  CSimSeqObj local_520 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_518 [8];
  int local_510;
  int *local_500;
  char *local_4f8;
  undefined **local_4f0;
  CSimSeqObj **local_4e8;
  longlong local_4e0 [4];
  CSimSeqObj local_4c0 [32];
  char local_4a0 [8];
  undefined1 local_498;
  char local_488 [80];
  undefined1 local_438 [1008];
  ulonglong local_48;
  
  local_48 = DAT_1800516d8 ^ (ulonglong)auStack_5a8;
  local_588 = param_3;
  local_584 = param_2;
  pcVar6 = (char *)GRinqscp();
  local_4f8 = pcVar6;
  CSimSeqObj::CSimSeqObj(local_520);
  local_568 = (CSimSeqObj *)0x0;
  local_540 = (CSimSeqObj *)0x0;
  local_580 = CSimSeqTree::vftable;
  local_558 = CSimSeqTree::vftable;
  local_578 = (CSimSeqObj *)0x0;
  pCStack_570 = (CSimSeqObj *)0x0;
  local_550 = (CSimSeqObj *)0x0;
  pCStack_548 = (CSimSeqObj *)0x0;
  piVar10 = (int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) +
                   4);
  if ((*piVar10 < DAT_180051be4) && (FUN_18003bdf0(&DAT_180051be4), DAT_180051be4 == -1)) {
    atexit((_func_5014 *)&LAB_18003d770);
    _Init_thread_footer(&DAT_180051be4);
  }
  if ((*piVar10 < DAT_180051be8) && (FUN_18003bdf0(&DAT_180051be8), DAT_180051be8 == -1)) {
    atexit((_func_5014 *)&LAB_18003d790);
    _Init_thread_footer(&DAT_180051be8);
  }
  local_534 = *(int *)(param_1 + 0xc);
  iVar16 = 0;
  iVar9 = 0;
  local_560 = 0;
  if (param_2 != 0) {
    local_500 = (int *)(param_1 + 0x10);
    do {
      local_538 = *local_500;
      piVar10 = local_500 + 1;
      iVar19 = 0;
      if (0 < local_538) {
        local_528 = (char *)0xc;
        if (param_3 != 0) {
          local_528 = (char *)0x8;
        }
        do {
          pcVar6 = local_528;
          strncpy(local_4a0,(char *)piVar10,8);
          local_498 = 0;
          if (param_3 == 0) {
            iVar5 = piVar10[2];
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      (local_518,local_4a0);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::TrimRight(local_518)
            ;
            local_510 = iVar5;
            if (iVar5 != -1) goto LAB_180007a6f;
            uVar12 = (ulonglong)iVar16;
            if ((uVar12 < (ulonglong)((longlong)pCStack_548 - (longlong)local_550 >> 5)) &&
               ((ulonglong)((longlong)local_540 - (longlong)local_550 >> 5) < uVar12)) {
              if (0x7ffffffffffffff < uVar12) goto LAB_180008031;
              FUN_180005df0((longlong *)&local_550,uVar12);
            }
            pCVar2 = pCStack_548;
            pCVar13 = local_550 + uVar12 * 0x20;
            if (pCStack_548 == local_540) {
              FUN_180004620((longlong *)&local_550,pCVar13,local_520);
              iVar16 = iVar16 + 1;
            }
            else if (pCVar13 == pCStack_548) {
              CSimSeqObj::CSimSeqObj(pCStack_548,local_520);
              pCStack_548 = pCStack_548 + 0x20;
              iVar16 = iVar16 + 1;
            }
            else {
              local_4e8 = &local_550;
              CSimSeqObj::CSimSeqObj((CSimSeqObj *)local_4e0,local_520);
              CSimSeqObj::CSimSeqObj(pCVar2,pCVar2 + -0x20);
              pCStack_548 = pCStack_548 + 0x20;
              FUN_180004d30((longlong)pCVar13,(longlong)(pCVar2 + -0x20),pCVar2);
              CSimSeqObj::operator=(pCVar13,local_4c0);
              CSimSeqObj::~CSimSeqObj(local_4c0);
              (**(code **)(local_4e0[0] + 8))(local_4e0,0);
              iVar16 = iVar16 + 1;
            }
          }
          else {
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      (local_518,local_4a0);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::TrimRight(local_518)
            ;
            local_510 = 10;
LAB_180007a6f:
            cVar4 = FUN_180005a30((longlong)&local_580,(longlong)local_520);
            if (cVar4 != '\0') {
              FUN_180008f80(local_438,"Assert failed in file %s line %d",
                            "G:\\Agent\\work\\2\\s\\src\\mm\\Simdll\\Simdll.cpp",0x28d);
              LogMessage(local_438,2,1);
            }
            uVar12 = (ulonglong)iVar9;
            if ((uVar12 < (ulonglong)((longlong)pCStack_570 - (longlong)local_578 >> 5)) &&
               ((ulonglong)((longlong)local_568 - (longlong)local_578 >> 5) < uVar12)) {
              if (0x7ffffffffffffff < uVar12) {
LAB_180008031:
                    /* WARNING: Subroutine does not return */
                FUN_180005f30();
              }
              FUN_180005df0((longlong *)&local_578,uVar12);
            }
            pCVar2 = pCStack_570;
            pCVar13 = local_578 + uVar12 * 0x20;
            if (pCStack_570 == local_568) {
              FUN_180004620((longlong *)&local_578,pCVar13,local_520);
            }
            else if (pCVar13 == pCStack_570) {
              CSimSeqObj::CSimSeqObj(pCStack_570,local_520);
              pCStack_570 = pCStack_570 + 0x20;
            }
            else {
              local_4e8 = &local_578;
              CSimSeqObj::CSimSeqObj((CSimSeqObj *)local_4e0,local_520);
              CSimSeqObj::CSimSeqObj(pCVar2,pCVar2 + -0x20);
              pCStack_570 = pCStack_570 + 0x20;
              FUN_180004d30((longlong)pCVar13,(longlong)(pCVar2 + -0x20),pCVar2);
              CSimSeqObj::operator=(pCVar13,local_4c0);
              CSimSeqObj::~CSimSeqObj(local_4c0);
              (**(code **)(local_4e0[0] + 8))(local_4e0,0);
            }
            iVar9 = iVar9 + 1;
          }
          piVar10 = (int *)((longlong)piVar10 + (longlong)pcVar6);
          iVar19 = iVar19 + 1;
          param_3 = local_588;
        } while (iVar19 < local_538);
      }
      local_500 = local_500 + 0x44;
      local_584 = local_584 + -1;
    } while (local_584 != 0);
    local_584 = 0;
    pcVar6 = local_4f8;
  }
  FUN_180004820((longlong *)&DAT_18004f6e8,DAT_18004f6f0,local_578,
                (longlong)pCStack_570 - (longlong)local_578 >> 5);
  FUN_180004820((longlong *)&DAT_18004f708,DAT_18004f710,local_550,
                (longlong)pCStack_548 - (longlong)local_550 >> 5);
  if (local_534 != 0) goto LAB_180007ec7;
  local_4f0 = &PTR_vftable_18004f600;
  local_530 = &PTR_vftable_18004f620;
  if (((pcVar6 == (char *)0x0) || (*pcVar6 == '\0')) || (1 < local_588)) {
LAB_180007f1f:
    ppuVar3 = local_4f0;
    ppuVar14 = local_530;
    lVar18 = local_560;
    iVar16 = local_588;
    if (local_588 != 0) goto LAB_180007d72;
    if (local_560 != 0) {
      *(undefined4 *)(local_560 + 0x14) = 1;
    }
    FUN_180005380(DAT_18004f708,DAT_18004f710,(longlong)DAT_18004f710 - (longlong)DAT_18004f708 >> 5
                  ,0);
    plVar11 = (longlong *)ppuVar3[1];
    plVar1 = (longlong *)ppuVar3[2];
    if (plVar11 != plVar1) {
      do {
        (**(code **)(*plVar11 + 8))(plVar11,0);
        plVar11 = plVar11 + 4;
      } while (plVar11 != plVar1);
      ppuVar3[2] = ppuVar3[1];
    }
    FUN_180004820((longlong *)(ppuVar3 + 1),(CSimSeqObj *)ppuVar3[2],DAT_18004f708,
                  (longlong)DAT_18004f710 - (longlong)DAT_18004f708 >> 5);
    FUN_180005380(DAT_18004f6e8,DAT_18004f6f0,(longlong)DAT_18004f6f0 - (longlong)DAT_18004f6e8 >> 5
                  ,0);
    FUN_180004820((longlong *)(ppuVar3 + 1),(CSimSeqObj *)ppuVar3[2],DAT_18004f6e8,
                  (longlong)DAT_18004f6f0 - (longlong)DAT_18004f6e8 >> 5);
  }
  else {
    local_528 = local_488 + -(longlong)pcVar6;
    iVar16 = local_588;
    do {
      pppuVar17 = &local_4f0;
      if (iVar16 != 0) {
        pppuVar17 = &local_530;
      }
      do {
        cVar4 = *pcVar6;
        pcVar6[(longlong)local_528] = cVar4;
        pcVar6 = pcVar6 + 1;
      } while (cVar4 != '\0');
      pCVar8 = (CSimSeqTree *)*pppuVar17;
      pcVar6 = local_488;
      do {
        pcVar7 = strchr(pcVar6,0x2e);
        if (pcVar7 != (char *)0x0) {
          *pcVar7 = '\0';
          pcVar7 = pcVar7 + 1;
        }
        iVar9 = 0;
        iVar19 = (int)(*(longlong *)(pCVar8 + 0x10) - *(longlong *)(pCVar8 + 8) >> 5);
        if (0 < iVar19) {
          do {
            iVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               ((longlong)iVar9 * 0x20 + 8 + *(longlong *)(pCVar8 + 8)),pcVar6);
            if (iVar5 == 0) break;
            iVar9 = iVar9 + 1;
          } while (iVar9 < iVar19);
        }
        if (iVar9 == iVar19) {
          *pppuVar17 = (undefined **)0x0;
          break;
        }
        if (iVar16 == local_588) {
          local_560 = *(longlong *)(pCVar8 + 8) + (longlong)iVar9 * 0x20;
        }
        pCVar8 = CSimSeqObj::GetChildren
                           ((CSimSeqObj *)((longlong)iVar9 * 0x20 + *(longlong *)(pCVar8 + 8)));
        *pppuVar17 = (undefined **)pCVar8;
        pcVar6 = pcVar7;
      } while (pcVar7 != (char *)0x0);
      iVar16 = iVar16 + 1;
      pcVar6 = local_4f8;
    } while (iVar16 < 2);
    if (local_4f0 != (undefined **)0x0) goto LAB_180007f1f;
LAB_180007d72:
    ppuVar14 = local_530;
    lVar18 = local_560;
    iVar16 = local_588;
  }
  if (ppuVar14 != (undefined **)0x0) {
    lVar15 = (longlong)DAT_18004f710 - (longlong)DAT_18004f708 >> 5;
    if ((int)lVar15 == 0) {
      if (iVar16 != 0) goto LAB_180007e03;
      plVar11 = (longlong *)ppuVar14[1];
      plVar1 = (longlong *)ppuVar14[2];
      if (plVar11 != plVar1) {
        do {
          (**(code **)(*plVar11 + 8))(plVar11,0);
          plVar11 = plVar11 + 4;
        } while (plVar11 != plVar1);
        ppuVar14[2] = ppuVar14[1];
      }
    }
    else {
      FUN_180005380(DAT_18004f708,DAT_18004f710,lVar15,0);
      plVar11 = (longlong *)ppuVar14[1];
      plVar1 = (longlong *)ppuVar14[2];
      if (plVar11 != plVar1) {
        do {
          (**(code **)(*plVar11 + 8))(plVar11,0);
          plVar11 = plVar11 + 4;
        } while (plVar11 != plVar1);
        ppuVar14[2] = ppuVar14[1];
      }
      FUN_180004820((longlong *)(ppuVar14 + 1),(CSimSeqObj *)ppuVar14[2],DAT_18004f708,
                    (longlong)DAT_18004f710 - (longlong)DAT_18004f708 >> 5);
      if (iVar16 != 0) {
LAB_180007e03:
        if (lVar18 != 0) {
          *(undefined4 *)(lVar18 + 0x14) = 1;
        }
        FUN_180005380(DAT_18004f6e8,DAT_18004f6f0,
                      (longlong)DAT_18004f6f0 - (longlong)DAT_18004f6e8 >> 5,0);
        FUN_180004820((longlong *)(ppuVar14 + 1),(CSimSeqObj *)ppuVar14[2],DAT_18004f6e8,
                      (longlong)DAT_18004f6f0 - (longlong)DAT_18004f6e8 >> 5);
      }
    }
  }
  pCVar2 = DAT_18004f6f0;
  pCVar13 = DAT_18004f6e8;
  if (DAT_18004f6e8 != DAT_18004f6f0) {
    do {
      (**(code **)(*(longlong *)pCVar13 + 8))(pCVar13,0);
      pCVar13 = pCVar13 + 0x20;
    } while (pCVar13 != pCVar2);
    DAT_18004f6f0 = DAT_18004f6e8;
  }
  pCVar2 = DAT_18004f710;
  pCVar13 = DAT_18004f708;
  if (DAT_18004f708 != DAT_18004f710) {
    do {
      (**(code **)(*(longlong *)pCVar13 + 8))(pCVar13,0);
      pCVar13 = pCVar13 + 0x20;
    } while (pCVar13 != pCVar2);
    DAT_18004f710 = DAT_18004f708;
  }
LAB_180007ec7:
  local_558 = CSimSeqTree::vftable;
  FUN_1800058b0((longlong *)&local_550);
  local_580 = CSimSeqTree::vftable;
  FUN_1800058b0((longlong *)&local_578);
  CSimSeqObj::~CSimSeqObj(local_520);
  return;
}

/* RVA 0x80b0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SimProcShwseqMessage(longlong param_1,int param_2)

{
  int iVar1;
  CSimSeqObj *pCVar2;
  uint uVar3;
  longlong lVar4;
  char *pcVar5;
  ulonglong uVar6;
  CSimSeqObj *pCVar7;
  int iVar8;
  CSimSeqObj *pCVar9;
  int iVar10;
  size_t _Count;
  int *_Source;
  int iVar11;
  undefined1 auStack_158 [32];
  undefined **local_138;
  CSimSeqObj *local_130;
  CSimSeqObj *pCStack_128;
  CSimSeqObj *local_120;
  int local_118;
  int local_114;
  int local_110;
  int *local_108;
  CSimSeqObj local_100 [8];
  longlong local_f8;
  int local_f0;
  CSimSeqObj local_e0 [32];
  CSimSeqObj **local_c0;
  longlong local_b8 [4];
  char local_98 [8];
  undefined1 local_90;
  char local_88 [80];
  ulonglong local_38;
  
                    /* 0x80b0  25  SimProcShwseqMessage */
  local_38 = DAT_1800516d8 ^ (ulonglong)auStack_158;
  iVar8 = 0;
  local_118 = param_2;
  CSimSeqObj::CSimSeqObj(local_100);
  local_130 = (CSimSeqObj *)0x0;
  pCStack_128 = (CSimSeqObj *)0x0;
  local_120 = (CSimSeqObj *)0x0;
  local_138 = CSimSeqTree::vftable;
  if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4)
       < DAT_180051be0) && (FUN_18003bdf0(&DAT_180051be0), DAT_180051be0 == -1)) {
    atexit(FUN_18003d750);
    _Init_thread_footer(&DAT_180051be0);
  }
  iVar10 = 0;
  if (param_2 != 0) {
    local_108 = (int *)(param_1 + 0x10);
    do {
      iVar1 = *local_108;
      _Source = local_108 + 1;
      iVar10 = local_108[-1];
      iVar8 = iVar8 + iVar1 * 3;
      uVar6 = (ulonglong)iVar8;
      local_114 = iVar8;
      local_110 = iVar10;
      if ((ulonglong)((longlong)local_120 - (longlong)local_130 >> 5) < uVar6) {
        if (0x7ffffffffffffff < uVar6) {
                    /* WARNING: Subroutine does not return */
          FUN_180005f30();
        }
        FUN_180005df0((longlong *)&local_130,uVar6);
      }
      iVar11 = 0;
      if (0 < iVar1) {
        do {
          strncpy(local_98,(char *)_Source,8);
          local_90 = 0;
          uVar3 = _Source[3];
          iVar8 = _Source[2];
          if (0x40 < uVar3) {
            uVar3 = 0x40;
          }
          _Count = (size_t)(int)uVar3;
          strncpy(local_88,(char *)(_Source + 4),_Count);
          if (0x40 < _Count) {
                    /* WARNING: Subroutine does not return */
            FUN_18003b6e4();
          }
          local_88[_Count] = '\0';
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_f8,
                     local_88);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::TrimRight
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_f8);
          if (*(int *)(local_f8 + -0x10) != 0) {
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_f8,
                       ".");
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_f8,
                     local_98);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::TrimRight
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_f8);
          pCVar2 = pCStack_128;
          pCVar9 = local_130 + (longlong)iVar11 * 0x20;
          local_f0 = iVar8;
          if (pCStack_128 == local_120) {
            FUN_180004620((longlong *)&local_130,pCVar9,local_100);
          }
          else if (pCVar9 == pCStack_128) {
            CSimSeqObj::CSimSeqObj(pCStack_128,local_100);
            pCStack_128 = pCStack_128 + 0x20;
          }
          else {
            local_c0 = &local_130;
            CSimSeqObj::CSimSeqObj((CSimSeqObj *)local_b8,local_100);
            pCVar7 = pCVar2 + -0x20;
            CSimSeqObj::CSimSeqObj(pCVar2,pCVar7);
            pCStack_128 = pCStack_128 + 0x20;
            for (; pCVar7 != pCVar9; pCVar7 = pCVar7 + -0x20) {
              CSimSeqObj::operator=(pCVar7,local_e0);
              CSimSeqObj::~CSimSeqObj(local_e0);
            }
            CSimSeqObj::operator=(pCVar9,local_e0);
            CSimSeqObj::~CSimSeqObj(local_e0);
            (**(code **)(local_b8[0] + 8))(local_b8,0);
          }
          _Source = (int *)((longlong)(_Source + 4) + _Count);
          iVar11 = iVar11 + 1;
        } while (iVar11 < iVar1);
        param_2 = local_118;
        iVar8 = local_114;
        iVar10 = local_110;
      }
      local_108 = local_108 + 0x44;
      param_2 = param_2 + -1;
      local_118 = param_2;
    } while (param_2 != 0);
    local_118 = 0;
  }
  FUN_180004820((longlong *)&DAT_18004f6c8,DAT_18004f6d0,local_130,
                (longlong)pCStack_128 - (longlong)local_130 >> 5);
  pCVar2 = pCStack_128;
  if (iVar10 == 0) {
    FUN_180015320(0x18004f6c0);
    FUN_180006840(0x18004f6c0);
    FUN_1800064a0(0x18004f6c0);
    pcVar5 = FUN_180015790(0x18004f6c0);
    SimSendMainWndMessage(0x55a,0,pcVar5);
    pCVar2 = DAT_18004f6d0;
    pCVar9 = DAT_18004f6c8;
    if (DAT_18004f6c8 != DAT_18004f6d0) {
      do {
        (**(code **)(*(longlong *)pCVar9 + 8))(pCVar9,0);
        pCVar9 = pCVar9 + 0x20;
      } while (pCVar9 != pCVar2);
      DAT_18004f6d0 = DAT_18004f6c8;
    }
    pCVar7 = pCStack_128;
    local_138 = CSimSeqTree::vftable;
    pCVar2 = local_130;
    pCVar9 = local_130;
    if (local_130 == (CSimSeqObj *)0x0) goto LAB_180008409;
    for (; local_130 = pCVar9, pCVar2 != pCVar7; pCVar2 = pCVar2 + 0x20) {
      (**(code **)(*(longlong *)pCVar2 + 8))(pCVar2,0);
      pCVar9 = local_130;
    }
    if (0xfff < ((longlong)local_120 - (longlong)pCVar9 & 0xffffffffffffffe0U)) {
      lVar4 = (longlong)pCVar9 - (longlong)*(CSimSeqObj **)(pCVar9 + -8);
      pCVar9 = *(CSimSeqObj **)(pCVar9 + -8);
      goto joined_r0x000180008528;
    }
  }
  else {
    local_138 = CSimSeqTree::vftable;
    pCVar7 = local_130;
    pCVar9 = local_130;
    if (local_130 == (CSimSeqObj *)0x0) goto LAB_180008409;
    for (; local_130 = pCVar9, pCVar7 != pCVar2; pCVar7 = pCVar7 + 0x20) {
      (**(code **)(*(longlong *)pCVar7 + 8))(pCVar7,0);
      pCVar9 = local_130;
    }
    if (0xfff < ((longlong)local_120 - (longlong)pCVar9 & 0xffffffffffffffe0U)) {
      lVar4 = (longlong)pCVar9 - (longlong)*(CSimSeqObj **)(pCVar9 + -8);
      pCVar9 = *(CSimSeqObj **)(pCVar9 + -8);
joined_r0x000180008528:
      if (0x1f < lVar4 - 8U) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
    }
  }
  FUN_180001300(pCVar9);
  local_120 = (CSimSeqObj *)0x0;
  local_130 = (CSimSeqObj *)0x0;
  pCStack_128 = (CSimSeqObj *)0x0;
LAB_180008409:
  CSimSeqObj::~CSimSeqObj(local_100);
  return;
}

/* RVA 0x8580 */
void SimPurgeMessages(void)

{
                    /* 0x8580  111  SimPurgeMessages */
  SimUpdateMessageView(1,(char *)0x0);
  return;
}

/* RVA 0x8590 */
undefined4 SimQueryStopButtonPressed(void)

{
  undefined4 uVar1;
  AFX_MODULE_STATE *pAVar2;
  AFX_MAINTAIN_STATE2 local_18 [16];
  
                    /* 0x8590  29  SimQueryStopButtonPressed */
  pAVar2 = AfxGetModuleState();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_18,pAVar2);
  if (DAT_180051c18 == 0) {
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_18);
    return 0;
  }
  uVar1 = GRinqust();
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_18);
  return uVar1;
}

/* RVA 0x85e0 */
void FUN_1800085e0(int param_1)

{
  AFX_MODULE_STATE *pAVar1;
  CWinThread *pCVar2;
  longlong lVar3;
  AFX_MAINTAIN_STATE2 local_18 [16];
  
  pAVar1 = AfxGetModuleState();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_18,pAVar1);
  pCVar2 = AfxGetThread();
  if (pCVar2 != (CWinThread *)0x0) {
    lVar3 = (**(code **)(*(longlong *)pCVar2 + 0xf8))(pCVar2);
    if (lVar3 != 0) {
      SendMessageA(*(HWND *)(lVar3 + 0x40),0x542,0,(longlong)param_1);
      goto LAB_18000863a;
    }
  }
  if (param_1 == 0) {
    Ordinal_21(0,0);
  }
LAB_18000863a:
  DAT_180052ce0 = param_1;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_18);
  return;
}

/* RVA 0x8650 */
undefined8 FUN_180008650(char *param_1)

{
  AFX_MODULE_STATE *pAVar1;
  char *pcVar2;
  AFX_MAINTAIN_STATE2 local_18 [16];
  
  pAVar1 = AfxGetModuleState();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_18,pAVar1);
  if (param_1 == (char *)0x0) {
    pcVar2 = (char *)0x0;
  }
  else {
    pcVar2 = _strdup(param_1);
  }
  FUN_1800074b0(0x548,pcVar2,0);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_18);
  return 0;
}

/* RVA 0x86a0 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SimResetDllGobal(void)

{
  longlong *plVar1;
  longlong *plVar2;
  
                    /* 0x86a0  21  SimResetDllGobal */
  plVar1 = DAT_18004f5f0;
  plVar2 = DAT_18004f5e8;
  if (DAT_18004f5e8 != DAT_18004f5f0) {
    do {
      (**(code **)(*plVar2 + 8))(plVar2,0);
      plVar2 = plVar2 + 4;
    } while (plVar2 != plVar1);
    DAT_18004f5f0 = DAT_18004f5e8;
  }
  ATL::CSimpleStringT<char,1>::Empty((CSimpleStringT<char,1> *)&DAT_180051bc8);
  _DAT_180051b98 = 0xffffffff;
  return;
}

/* RVA 0x8710 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SimResetExcludedBlockList(undefined8 param_1)

{
  short sVar1;
  undefined8 psa;
  int iVar2;
  UINT cbMultiByte;
  CHAR *pCVar3;
  undefined1 auStackY_128 [32];
  undefined8 local_e8;
  int local_e0 [2];
  short *local_d8;
  int local_d0;
  int local_cc;
  _union_2707 local_c8;
  CHAR local_a8 [128];
  ulonglong local_28;
  
                    /* 0x8710  130  SimResetExcludedBlockList */
  local_28 = DAT_1800516d8 ^ (ulonglong)auStackY_128;
  local_c8._0_8_ = 0;
  local_c8.decVal.u2 = (_union_1719)(_struct_1720)0x0;
  local_c8._16_8_ = 0;
  VariantInit((VARIANTARG *)&local_c8.n2);
  iVar2 = DCGetExcludedList(&local_c8,param_1);
  psa = local_c8._8_8_;
  if ((iVar2 == 0) && ((local_c8._0_8_ & 0x2000) != 0)) {
    local_e8 = 0;
    SafeArrayGetLBound((SAFEARRAY *)local_c8.decVal.u2,1,&local_d0);
    SafeArrayGetUBound((SAFEARRAY *)psa,1,local_e0);
    SafeArrayGetLBound((SAFEARRAY *)psa,2,(LONG *)((longlong)&local_e8 + 4));
    SafeArrayLock((SAFEARRAY *)psa);
    local_e8 = CONCAT44(local_e8._4_4_,local_d0);
    if (local_d0 <= local_e0[0]) {
      do {
        local_e8 = local_e8 & 0xffffffff;
        SafeArrayPtrOfIndex((SAFEARRAY *)psa,(LONG *)&local_e8,&local_d8);
        if (*local_d8 == 8) {
          cbMultiByte = SysStringLen(*(BSTR *)(local_d8 + 4));
          if (*(LPCWSTR *)(local_d8 + 4) == (LPCWSTR)0x0) {
            pCVar3 = (char *)0x0;
          }
          else {
            local_a8[0] = '\0';
            iVar2 = WideCharToMultiByte(0,0,*(LPCWSTR *)(local_d8 + 4),-1,local_a8,cbMultiByte,
                                        (LPCSTR)0x0,(LPBOOL)0x0);
            pCVar3 = local_a8;
            if (iVar2 == 0) {
              pCVar3 = (char *)0x0;
            }
          }
          local_e8 = CONCAT44(1,(LONG)local_e8);
          SafeArrayPtrOfIndex((SAFEARRAY *)psa,(LONG *)&local_e8,&local_d8);
          if (*local_d8 == 0xb) {
            sVar1 = local_d8[4];
            iVar2 = CApwnEOStatus::Lookup((CApwnEOStatus *)g_ApwnEOStatusMap_exref,pCVar3,&local_cc)
            ;
            if (iVar2 == 0) {
              if (sVar1 == 0) goto LAB_1800088b9;
            }
            else if (sVar1 != local_cc) {
LAB_1800088b9:
              SimEnablePFSBlock((LPARAM)pCVar3,(uint)(sVar1 != 0));
            }
          }
        }
        iVar2 = (LONG)local_e8 + 1;
        local_e8 = CONCAT44(local_e8._4_4_,iVar2);
      } while (iVar2 <= local_e0[0]);
    }
    SafeArrayUnlock((SAFEARRAY *)psa);
  }
  VariantClear((VARIANTARG *)&local_c8.n2);
  return;
}

/* RVA 0x8920 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 SimSBGetAPRunStatus(char *param_1)

{
  bool bVar1;
  int iVar2;
  FILE *_File;
  char *pcVar3;
  undefined4 uVar4;
  undefined1 auStack_d8 [32];
  char *pcStack_b8;
  undefined1 auStack_b0 [24];
  char acStack_98 [128];
  ulonglong uStack_18;
  
                    /* 0x8920  186  SimSBGetAPRunStatus */
  uStack_18 = DAT_1800516d8 ^ (ulonglong)auStack_d8;
  bVar1 = false;
  _File = fopen(param_1,"r");
  if (_File == (FILE *)0x0) {
    uVar4 = 0xffffffff;
  }
  else {
    pcStack_b8 = fgets(acStack_98,0x78,_File);
    uVar4 = pcStack_b8._0_4_;
    if (pcStack_b8 != (char *)0x0) {
      do {
        if (bVar1) {
          bVar1 = false;
        }
        else {
          pcVar3 = (char *)FUN_18002bdd0((longlong)pcStack_b8);
          if (*pcVar3 != '\n') {
            bVar1 = true;
          }
          SFgettok(&pcStack_b8,auStack_b0,0x14);
          iVar2 = SFidxstri(auStack_b0,&PTR_DAT_180050db8,4);
          if (iVar2 == 0) {
            uVar4 = 0;
          }
          else if (iVar2 == 1) {
            uVar4 = 1;
          }
          else if (iVar2 == 2) {
            uVar4 = 2;
          }
          else if (iVar2 == 3) {
            uVar4 = 4;
          }
          else {
            uVar4 = 3;
          }
        }
        pcStack_b8 = fgets(acStack_98,0x78,_File);
      } while (pcStack_b8 != (char *)0x0);
      pcStack_b8 = (char *)0x0;
    }
    fclose(_File);
  }
  return uVar4;
}

/* RVA 0x8930 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SimSBbatch(char *param_1,undefined8 param_2,longlong param_3,undefined8 param_4)

{
  char cVar1;
  char cVar2;
  longlong lVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  char *pcVar7;
  undefined8 uVar8;
  longlong lVar10;
  longlong lVar9;
  ulonglong uVar11;
  undefined4 *puVar12;
  undefined2 *puVar13;
  longlong lVar14;
  undefined1 *puVar15;
  undefined4 *puVar16;
  undefined1 auVar17 [8];
  uint *puVar18;
  ulonglong uVar19;
  char *pcVar20;
  undefined1 auStack_9e8 [32];
  longlong lStack_9c8;
  char *pcStack_9c0;
  undefined8 uStack_9b8;
  undefined8 uStack_9b0;
  uint auStack_9a8 [2];
  undefined1 auStack_9a0 [8];
  char acStack_998 [9];
  undefined1 auStack_98f [262];
  undefined4 uStack_889;
  undefined1 auStack_884 [524];
  undefined1 auStack_678 [272];
  char acStack_568 [272];
  char acStack_458 [272];
  char acStack_348 [256];
  char acStack_248 [528];
  ulonglong uStack_38;
  
                    /* 0x8930  158  SimSBbatch */
  uStack_38 = DAT_1800516d8 ^ (ulonglong)auStack_9e8;
  uVar19 = 0xffffffff;
  auStack_9a8[0] = 0xffffffff;
  if (DAT_180052cd4 == 10) {
    uVar6 = GetSorResStringEx(0xd10);
    lStack_9c8 = GetSorResStringEx(0xd0f);
    param_4 = 0x21;
    pcStack_9c0 = (char *)CONCAT44(pcStack_9c0._4_4_,10);
    uStack_9b8 = uVar6;
    FUN_180008f80(dbxbuf_exref,"%c%c%s%d%s?",0x5e,0x21);
    param_3 = 1;
    iVar4 = EXyesno(dbxbuf_exref,2);
    if (iVar4 == 1) {
      return 0xffffffff;
    }
  }
  if ((*param_1 == '\0') || (param_1 == (char *)0x0)) {
    uVar6 = GetSorResStringEx(0xd11);
    FUN_180008f80(param_1,&DAT_180040c80,uVar6,(ulonglong)DAT_180052218);
    DAT_180052218 = DAT_180052218 + 1;
    uVar6 = GetSorResStringEx(0xd13);
    lStack_9c8 = GetSorResStringEx(0xd12);
    param_4 = 0x21;
    pcStack_9c0 = param_1;
    uStack_9b8 = uVar6;
    FUN_180008f80(dbxbuf_exref,"%c%c%s%s%s",0x5e,0x21);
    param_3 = 1;
    EXyesno(dbxbuf_exref);
  }
  iVar4 = 0;
  if (0 < DAT_180052cd4) {
    pcVar20 = &DAT_180052220;
    do {
      if (*pcVar20 == '\0') break;
      pcVar7 = &DAT_180052220 + (longlong)iVar4 * 10;
      param_3 = (longlong)param_1 - (longlong)pcVar7;
      do {
        cVar1 = *pcVar7;
        cVar2 = pcVar7[param_3];
        if (cVar1 != cVar2) break;
        pcVar7 = pcVar7 + 1;
      } while (cVar2 != '\0');
      if (cVar1 == cVar2) {
        uVar6 = GetSorResStringEx(0xd16);
        uVar8 = GetSorResStringEx(0xd15);
        lStack_9c8 = GetSorResStringEx(0xd14);
        param_4 = 0x58;
        pcStack_9c0 = param_1;
        uStack_9b8 = uVar8;
        uStack_9b0 = uVar6;
        FUN_180008f80(dbxbuf_exref,"%c%c%s%s%s%s",0x5e,0x58);
        param_3 = 1;
        iVar5 = EXyesno(dbxbuf_exref);
        if (iVar5 == 1) {
          return 0xffffffff;
        }
      }
      iVar4 = iVar4 + 1;
      pcVar20 = pcVar20 + 10;
    } while (iVar4 < DAT_180052cd4);
  }
  lVar14 = *(longlong *)SBdataptr_exref;
  iVar4 = *(int *)(lVar14 + 0x1214);
  if (iVar4 == 0) {
    if (xprtdata_exref[0x200] == (code)0x0) {
LAB_1800292b0:
      pcVar20 = (char *)GetSorResStringEx(0xd1a);
      FUN_180028530(pcVar20,-1);
      return 0xffffffff;
    }
    if (*(int *)(lVar14 + 0x1218) == 2) {
      pcVar20 = param_1;
      do {
        cVar1 = *pcVar20;
        pcVar20[(longlong)(auStack_98f + (0x107 - (longlong)param_1))] = cVar1;
        pcVar20 = pcVar20 + 1;
      } while (cVar1 != '\0');
      _strlwr((char *)((longlong)&uStack_889 + 1));
      pcVar20 = (char *)((longlong)&uStack_889 + 1);
      do {
        cVar1 = *pcVar20;
        pcVar20[(longlong)param_1 - ((longlong)&uStack_889 + 1)] = cVar1;
        pcVar20 = pcVar20 + 1;
      } while (cVar1 != '\0');
    }
    else {
      pcVar20 = param_1;
      do {
        cVar1 = *pcVar20;
        pcVar20[(longlong)(auStack_98f + (0x107 - (longlong)param_1))] = cVar1;
        pcVar20 = pcVar20 + 1;
      } while (cVar1 != '\0');
    }
    puVar16 = &uStack_889;
    do {
      puVar12 = puVar16;
      puVar16 = (undefined4 *)((longlong)puVar12 + 1);
    } while (*(char *)((longlong)puVar12 + 1) != '\0');
    *(undefined4 *)((longlong)puVar12 + 1) = DAT_180040ae4;
    *(undefined1 *)((longlong)puVar12 + 5) = DAT_180040ae8;
    if ((*(int *)(*(longlong *)SBdataptr_exref + 0x1218) == 1) &&
       (*(char *)(*(longlong *)SBdataptr_exref + 0x110) != '\0')) {
      pcVar20 = _getcwd(acStack_458,0x104);
      if (pcVar20 == (char *)0x0) {
        pcVar20 = (char *)GetSorResStringEx(0xd17);
        FUN_180028530(pcVar20,-1);
        return 0xffffffff;
      }
      iVar4 = _chdir((char *)(*(longlong *)SBdataptr_exref + 0x110));
      if (iVar4 == -1) {
        pcVar20 = (char *)GetSorResStringEx(0xd18);
        FUN_180028530(pcVar20,-1);
        return 0xffffffff;
      }
      *(uint *)(Sactions_exref + 4) = *(uint *)(Sactions_exref + 4) | 0x80;
      iVar4 = dump_input((longlong)&uStack_889 + 1);
      if (iVar4 == -1) goto LAB_180029797;
      uStack_889._1_2_ = DAT_18004295c;
      puVar16 = &uStack_889;
      uStack_889._3_1_ = DAT_18004295e;
      lVar14 = *(longlong *)SBdataptr_exref;
      do {
        pcVar20 = (char *)((longlong)puVar16 + 1);
        puVar16 = (undefined4 *)((longlong)puVar16 + 1);
      } while (*pcVar20 != '\0');
      lVar10 = 0;
      do {
        cVar1 = *(char *)(lVar14 + 0x110 + lVar10);
        *(char *)((longlong)puVar16 + lVar10) = cVar1;
        lVar10 = lVar10 + 1;
      } while (cVar1 != '\0');
      CUsethvr("_HDIR",(longlong)&uStack_889 + 1,lvars_exref,0x400);
    }
    else {
      acStack_458[0] = '\0';
      *(uint *)(Sactions_exref + 4) = *(uint *)(Sactions_exref + 4) | 0x80;
      iVar4 = dump_input((longlong)&uStack_889 + 1,0);
      if (iVar4 == -1) goto LAB_180029797;
    }
    CUsethvr(&DAT_18004228c,param_1,lvars_exref,0x400);
    CUsubhvr(lvars_exref,acStack_998,xprtdata_exref + 0x200,0);
    CUusthvr(&DAT_18004228c,lvars_exref,0x400);
    if (*(int *)(*(longlong *)SBdataptr_exref + 0xc) != 0) {
      puVar13 = (undefined2 *)(auStack_9a0 + 7);
      do {
        pcVar20 = (char *)((longlong)puVar13 + 1);
        puVar13 = (undefined2 *)((longlong)puVar13 + 1);
      } while (*pcVar20 != '\0');
      *puVar13 = DAT_18003f9bc;
      pcVar20 = auStack_9a0 + 7;
      do {
        pcVar7 = pcVar20;
        pcVar20 = pcVar7 + 1;
      } while (pcVar7[1] != '\0');
      *(undefined8 *)(pcVar7 + 1) = s__getridof__mm_180042968._0_8_;
      *(undefined4 *)(pcVar7 + 9) = s__getridof__mm_180042968._8_4_;
      *(undefined2 *)(pcVar7 + 0xd) = s__getridof__mm_180042968._12_2_;
    }
    puVar13 = (undefined2 *)(auStack_9a0 + 7);
    do {
      pcVar20 = (char *)((longlong)puVar13 + 1);
      puVar13 = (undefined2 *)((longlong)puVar13 + 1);
    } while (*pcVar20 != '\0');
    *puVar13 = DAT_18003f9bc;
    lVar14 = -1;
    do {
      lVar14 = lVar14 + 1;
    } while (*(char *)(*(longlong *)SBdataptr_exref + 0xb10 + lVar14) != '\0');
    lVar10 = -1;
    do {
      lVar9 = lVar10 + 1;
      lVar3 = lVar10 + 1;
      lVar10 = lVar9;
    } while (acStack_998[lVar3] != '\0');
    uVar6 = FUN_180029800((int)lVar14 + (int)lVar9,(longlong)acStack_348,acStack_998,
                          *(longlong *)SBdataptr_exref + 0xb10);
    if ((int)uVar6 != -1) {
      if ((int)uVar6 == 1) {
        puVar15 = auStack_9a0 + 7;
        do {
          pcVar20 = puVar15 + 1;
          puVar15 = puVar15 + 1;
        } while (*pcVar20 != '\0');
        lVar14 = 0;
        do {
          cVar1 = acStack_348[lVar14];
          puVar15[lVar14] = cVar1;
          lVar14 = lVar14 + 1;
        } while (cVar1 != '\0');
      }
      puVar15 = auStack_9a0 + 7;
      lVar14 = *(longlong *)SBdataptr_exref;
      do {
        pcVar20 = puVar15 + 1;
        puVar15 = puVar15 + 1;
      } while (*pcVar20 != '\0');
      lVar10 = 0;
      do {
        cVar1 = *(char *)(lVar14 + 0xb10 + lVar10);
        puVar15[lVar10] = cVar1;
        lVar10 = lVar10 + 1;
      } while (cVar1 != '\0');
      iVar4 = FUN_1800269c0("aspen.exe",(undefined1 *)((longlong)&uStack_889 + 1));
      if (iVar4 != 0) {
LAB_180029658:
        pcVar20 = (char *)GetSorResStringEx(0xd1d);
        FUN_180028530(pcVar20,-1);
        return 0xffffffff;
      }
      FUN_180008f80(auStack_678,&DAT_18003f9b0,(longlong)&uStack_889 + 1,auStack_98f);
      uVar11 = FUN_180028100(auStack_678,*(undefined4 *)(xprtdata_exref + 0x934));
      uVar19 = uVar11 & 0xffffffff;
      if (acStack_458[0] != '\0') {
        _chdir(acStack_458);
      }
      if ((int)uVar11 != -1) goto LAB_1800296cd;
    }
  }
  else {
    if (((iVar4 != 1) && (iVar4 != 2)) && (iVar4 != 3)) {
LAB_1800296cd:
      if (DAT_180050db4 != 0) {
        DAT_180050db4 = 0;
        DAT_180052cd4 = 0;
      }
      pcVar20 = &DAT_180052220 + (longlong)DAT_180052cd4 * 10;
      do {
        cVar1 = *param_1;
        param_1 = param_1 + 1;
        *pcVar20 = cVar1;
        pcVar20 = pcVar20 + 1;
      } while (cVar1 != '\0');
      pcVar20 = (char *)(*(longlong *)SBdataptr_exref + 0x110);
      if (*pcVar20 == '\0') {
        (&DAT_180052284)[(longlong)DAT_180052cd4 * 0x104] = 0;
      }
      else {
        pcVar7 = &DAT_180052284 + (longlong)DAT_180052cd4 * 0x104;
        do {
          cVar1 = *pcVar20;
          pcVar20 = pcVar20 + 1;
          *pcVar7 = cVar1;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
      }
      (&DAT_180052cac)[DAT_180052cd4] = 2;
      DAT_180052cd4 = DAT_180052cd4 + 1;
      GRamask(8);
      msw_modify_run_menu(*(undefined4 *)GRamask1_exref);
      return uVar19;
    }
    if (xprtdata_exref[0x200] == (code)0x0) goto LAB_1800292b0;
    if (*(char *)(lVar14 + 0x110) == '\0') {
      FUN_180034540((char *)(lVar14 + 0x110));
    }
    else {
      FUN_180034540(acStack_458);
      FUN_180033fc0((char *)(*(longlong *)SBdataptr_exref + 0x110),lVar14,param_3,param_4);
    }
    pcVar20 = param_1;
    do {
      cVar1 = *pcVar20;
      pcVar20[(longlong)(auStack_98f + (0x107 - (longlong)param_1))] = cVar1;
      pcVar20 = pcVar20 + 1;
    } while (cVar1 != '\0');
    puVar16 = &uStack_889;
    do {
      puVar12 = puVar16;
      puVar16 = (undefined4 *)((longlong)puVar12 + 1);
    } while (*(char *)((longlong)puVar12 + 1) != '\0');
    *(undefined4 *)((longlong)puVar12 + 1) = DAT_180040ae4;
    *(undefined1 *)((longlong)puVar12 + 5) = DAT_180040ae8;
    *(uint *)(Sactions_exref + 4) = *(uint *)(Sactions_exref + 4) | 0x80;
    iVar4 = dump_input((longlong)&uStack_889 + 1,0);
    if (iVar4 != -1) {
      iVar4 = FUN_18002b360((char *)((longlong)&uStack_889 + 1),(char *)((longlong)&uStack_889 + 1),
                            (char *)(*(longlong *)SBdataptr_exref + 0x110));
      if (iVar4 == -1) {
        pcVar20 = (char *)GetSorResStringEx(0xd19);
        FUN_180028530(pcVar20,-1);
        return 0xffffffff;
      }
      CUsethvr(&DAT_18004228c,param_1,lvars_exref,0x400);
      CUsubhvr(lvars_exref,acStack_998,xprtdata_exref + 0x200,0);
      CUusthvr(&DAT_18004228c,lvars_exref,0x400);
      if (*(int *)(*(longlong *)SBdataptr_exref + 0xc) != 0) {
        puVar13 = (undefined2 *)(auStack_9a0 + 7);
        do {
          pcVar20 = (char *)((longlong)puVar13 + 1);
          puVar13 = (undefined2 *)((longlong)puVar13 + 1);
        } while (*pcVar20 != '\0');
        *puVar13 = DAT_18003f9bc;
        pcVar20 = auStack_9a0 + 7;
        do {
          pcVar7 = pcVar20;
          pcVar20 = pcVar7 + 1;
        } while (pcVar7[1] != '\0');
        *(undefined8 *)(pcVar7 + 1) = s__getridof__mm_180042968._0_8_;
        *(undefined4 *)(pcVar7 + 9) = s__getridof__mm_180042968._8_4_;
        *(undefined2 *)(pcVar7 + 0xd) = s__getridof__mm_180042968._12_2_;
      }
      puVar13 = (undefined2 *)(auStack_9a0 + 7);
      do {
        pcVar20 = (char *)((longlong)puVar13 + 1);
        puVar13 = (undefined2 *)((longlong)puVar13 + 1);
      } while (*pcVar20 != '\0');
      *puVar13 = DAT_18003f9bc;
      lVar14 = -1;
      do {
        lVar14 = lVar14 + 1;
      } while (*(char *)(*(longlong *)SBdataptr_exref + 0xb10 + lVar14) != '\0');
      lVar10 = -1;
      do {
        lVar9 = lVar10 + 1;
        lVar3 = lVar10 + 1;
        lVar10 = lVar9;
      } while (acStack_998[lVar3] != '\0');
      uVar6 = FUN_180029800((int)lVar14 + (int)lVar9,(longlong)acStack_348,acStack_998,
                            *(longlong *)SBdataptr_exref + 0xb10);
      if ((int)uVar6 != -1) {
        if ((int)uVar6 == 1) {
          puVar15 = auStack_9a0 + 7;
          do {
            pcVar20 = puVar15 + 1;
            puVar15 = puVar15 + 1;
          } while (*pcVar20 != '\0');
          lVar14 = 0;
          do {
            cVar1 = acStack_348[lVar14];
            puVar15[lVar14] = cVar1;
            lVar14 = lVar14 + 1;
          } while (cVar1 != '\0');
        }
        if (*(int *)(*(longlong *)SBdataptr_exref + 0x1218) == 1) {
          auStack_9a0 = (undefined1  [8])((longlong)&uStack_889 + 1);
          lVar14 = 0;
          do {
            cVar1 = acStack_998[lVar14];
            auStack_98f[lVar14 + 0x107] = cVar1;
            lVar14 = lVar14 + 1;
          } while (cVar1 != '\0');
          SFgetstr(auStack_9a0,acStack_248,0x208);
          auStack_9a8[0] = 0;
          iVar4 = FUN_1800269c0(acStack_248,acStack_568);
          if (iVar4 == 0) {
            pcVar20 = acStack_568;
            pcVar7 = "%s %s %s";
            auVar17 = auStack_9a0;
          }
          else {
            uVar6 = FUN_180026fe0(acStack_568,(int *)auStack_9a8);
            if (((int)uVar6 != 0) || (auStack_9a8[0] != 0)) goto LAB_180029658;
            FUN_180026740(acStack_568,"xeq",acStack_248,1);
            pcVar20 = acStack_248;
            pcVar7 = "%s\\%s %s";
            auVar17 = (undefined1  [8])acStack_998;
          }
          lStack_9c8 = *(longlong *)SBdataptr_exref + 0xb10;
          FUN_180008f80(auStack_678,pcVar7,pcVar20,auVar17);
          SFfmtnstr(auStack_678,0x101,acStack_998);
          if (auStack_9a8[0] != 0) goto LAB_180029658;
          pcStack_9c0 = (char *)0x0;
          lStack_9c8 = CONCAT44(lStack_9c8._4_4_,*(undefined4 *)(xprtdata_exref + 0x934));
          FUN_180008f80((longlong)&uStack_889 + 1,"%s \"%s\" %d %d","SPAWN",acStack_998);
        }
        else {
          lStack_9c8 = *(longlong *)SBdataptr_exref + 0xb10;
          uStack_9b8 = 0;
          pcStack_9c0 = (char *)CONCAT44(pcStack_9c0._4_4_,*(undefined4 *)(xprtdata_exref + 0x934));
          FUN_180008f80((longlong)&uStack_889 + 1,"%s \"%s %s\" %d %d","SPAWN",acStack_998);
        }
        lVar14 = 0;
        do {
          cVar1 = auStack_98f[lVar14 + 0x107];
          acStack_998[lVar14] = cVar1;
          lVar14 = lVar14 + 1;
        } while (cVar1 != '\0');
        puVar18 = auStack_9a8;
        pcVar20 = acStack_568;
        pcVar7 = acStack_998;
        lStack_9c8 = CONCAT44(lStack_9c8._4_4_,
                              *(undefined4 *)(*(longlong *)SBdataptr_exref + 0x1220));
        iVar4 = REMOTE_COMMAND(*(undefined4 *)(*(longlong *)SBdataptr_exref + 0x146c));
        if ((iVar4 == 0) && (auStack_9a8[0] == 0)) {
          uVar19 = FUN_180033fc0((char *)(*(longlong *)SBdataptr_exref + 0x10),pcVar7,pcVar20,
                                 puVar18);
          uVar19 = uVar19 & 0xffffffff;
          goto LAB_1800296cd;
        }
      }
    }
  }
LAB_180029797:
  pcVar20 = (char *)GetSorResStringEx(0xd1c);
  FUN_180028530(pcVar20,-1);
  return (ulonglong)auStack_9a8[0];
}

/* RVA 0x8940 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 SimSBbatchRestart(void)

{
  int iVar1;
  undefined1 auStackY_158 [32];
  char acStack_128 [8];
  undefined4 uStack_120;
  ulonglong uStack_18;
  
                    /* 0x8940  219  SimSBbatchRestart */
  uStack_18 = DAT_1800516d8 ^ (ulonglong)auStackY_158;
  GRinqcnn();
  iVar1 = FUN_180030240((char *)0x0,acStack_128,0,0x30030000,(char *)0x0);
  if (iVar1 == 0) {
    uStack_120 = 0xffffffff;
  }
  return uStack_120;
}

/* RVA 0x8950 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SimSBbatchassignta(int param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  longlong lVar2;
  int iVar3;
  ulonglong uVar4;
  char *pcVar5;
  undefined8 uVar6;
  longlong lVar8;
  longlong lVar7;
  undefined1 auStackY_348 [32];
  char *pcStack_318;
  char *pcStack_310;
  undefined8 uStack_308;
  undefined8 uStack_300;
  char acStack_2f8 [8];
  uint uStack_2f0;
  char acStack_1e8 [16];
  char acStack_1d8 [16];
  char acStack_1c8 [400];
  ulonglong uStack_38;
  
                    /* 0x8950  220  SimSBbatchassignta */
  uStack_38 = DAT_1800516d8 ^ (ulonglong)auStackY_348;
  pcStack_310 = (char *)0x0;
  acStack_1e8[0] = '\0';
  uVar6 = 1;
  iVar3 = HYparnam(param_2,&pcStack_310,&pcStack_318);
  if (iVar3 != 0) {
    lVar8 = -(longlong)pcStack_318;
    do {
      cVar1 = *pcStack_318;
      pcStack_318[(longlong)(acStack_1d8 + lVar8)] = cVar1;
      pcStack_318 = pcStack_318 + 1;
    } while (cVar1 != '\0');
    pcVar5 = pcStack_310;
    do {
      cVar1 = *pcVar5;
      pcVar5[(longlong)(acStack_1e8 + -(longlong)pcStack_310)] = cVar1;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    pcStack_318 = acStack_1d8;
    uVar4 = HYrslhie(pcStack_310,&DAT_18003fa80,&uStack_300,&uStack_308);
    if ((int)uVar4 == 0) {
      return uVar4;
    }
    uVar6 = HYGetFinfoCls(uStack_300,uStack_308);
  }
  uVar6 = HYPshFinfo(uVar6);
  pcVar5 = acStack_1e8;
  if (acStack_1e8[0] == '\0') {
    pcVar5 = "";
  }
  SBsetscp(pcVar5);
  if (param_1 == 1) {
    FUN_180008f80(acStack_1c8,"%s, %s %s RAMP %s",pcStack_318,param_3);
  }
  else if (param_1 == 2) {
    FUN_180008f80(acStack_1c8,"%s, %s %s SRAMP %s",pcStack_318,param_3);
  }
  else {
    FUN_180008f80(acStack_1c8,"%s, %s %s",pcStack_318,param_3);
  }
  lVar8 = -1;
  do {
    lVar7 = lVar8 + 1;
    lVar2 = lVar8 + 1;
    lVar8 = lVar7;
  } while (acStack_1c8[lVar2] != '\0');
  iVar3 = FUN_180030240((char *)0x0,acStack_2f8,0,lVar7 * 0x100 | 0x300500ff,acStack_1c8);
  HYPopFinfo(uVar6);
  uVar4 = (ulonglong)uStack_2f0;
  if (iVar3 == 0) {
    uVar4 = 0xffffffff;
  }
  return uVar4;
}

/* RVA 0x8960 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 SimSBbatchassignvg(int param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  int iVar2;
  longlong lVar4;
  longlong lVar3;
  undefined1 auStackY_2e8 [32];
  char acStack_2b8 [8];
  undefined4 uStack_2b0;
  char acStack_1a8 [400];
  ulonglong uStack_18;
  
                    /* 0x8960  221  SimSBbatchassignvg */
  uStack_18 = DAT_1800516d8 ^ (ulonglong)auStackY_2e8;
  if (param_1 == 1) {
    FUN_180008f80(acStack_1a8,"%s %s %s RAMP %s",param_2,param_3);
  }
  else if (param_1 == 2) {
    FUN_180008f80(acStack_1a8,"%s %s %s SRAMP %s",param_2,param_3);
  }
  else {
    FUN_180008f80(acStack_1a8,"%s %s %s",param_2,param_3);
  }
  lVar4 = -1;
  do {
    lVar3 = lVar4 + 1;
    lVar1 = lVar4 + 1;
    lVar4 = lVar3;
  } while (acStack_1a8[lVar1] != '\0');
  iVar2 = FUN_180030240((char *)0x0,acStack_2b8,0,lVar3 * 0x100 | 0x300400ff,acStack_1a8);
  if (iVar2 == 0) {
    uStack_2b0 = 0xffffffff;
  }
  return uStack_2b0;
}

/* RVA 0x8970 */
void SimSBbatchdir(char *param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  
                    /* 0x8970  155  SimSBbatchdir */
  if (param_2 == 0) {
    pcVar2 = (char *)(*(longlong *)SBdataptr_exref + 0x110);
    if (pcVar2 != (char *)0x0) {
      do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
        *param_1 = cVar1;
        param_1 = param_1 + 1;
      } while (cVar1 != '\0');
    }
  }
  else if (param_2 == 1) {
    pcVar2 = (char *)(*(longlong *)SBdataptr_exref + 0x110);
    do {
      cVar1 = *param_1;
      param_1 = param_1 + 1;
      *pcVar2 = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    return;
  }
  return;
}

/* RVA 0x8980 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 SimSBbatchsnapshot(undefined8 param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  int iVar2;
  char *pcVar3;
  longlong lVar5;
  longlong lVar4;
  undefined1 auStackY_2e8 [32];
  char acStack_2b8 [8];
  undefined4 uStack_2b0;
  char acStack_1a8 [400];
  ulonglong uStack_18;
  
                    /* 0x8980  222  SimSBbatchsnapshot */
  uStack_18 = DAT_1800516d8 ^ (ulonglong)auStackY_2e8;
  pcVar3 = "SAVE %s";
  if (param_2 != 1) {
    pcVar3 = "RESTORE %s";
  }
  FUN_180008f80(acStack_1a8,pcVar3,param_1,param_4);
  lVar5 = -1;
  do {
    lVar4 = lVar5 + 1;
    lVar1 = lVar5 + 1;
    lVar5 = lVar4;
  } while (acStack_1a8[lVar1] != '\0');
  iVar2 = FUN_180030240((char *)0x0,acStack_2b8,0,lVar4 * 0x100 | 0x300200ff,acStack_1a8);
  if (iVar2 == 0) {
    uStack_2b0 = 0xffffffff;
  }
  return uStack_2b0;
}

/* RVA 0x8990 */
void SimSBgetbj(longlong param_1,int *param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
                    /* 0x8990  152  SimSBgetbj */
  iVar3 = 0;
  *param_2 = DAT_180052cd4;
  if (0 < DAT_180052cd4) {
    do {
      pcVar2 = &DAT_180052220 + (longlong)iVar3 * 10;
      do {
        cVar1 = *pcVar2;
        pcVar2[param_1 + -0x180052220] = cVar1;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_180052cd4);
  }
  return;
}

/* RVA 0x89a0 */
void SimSBgetridof(undefined4 *param_1,int param_2)

{
                    /* 0x89a0  154  SimSBgetridof */
  if (param_2 == 0) {
    *param_1 = *(undefined4 *)(*(longlong *)SBdataptr_exref + 0xc);
  }
  else if (param_2 == 1) {
    *(undefined4 *)(*(longlong *)SBdataptr_exref + 0xc) = *param_1;
    return;
  }
  return;
}

/* RVA 0x89b0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SimSBjobstat(char *param_1,longlong param_2)

{
  char cVar1;
  char cVar2;
  undefined4 *puVar3;
  char *pcVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  longlong lVar8;
  undefined4 *puVar9;
  longlong lVar10;
  int iVar11;
  longlong lVar12;
  undefined1 auStack_388 [32];
  undefined8 uStack_368;
  undefined8 uStack_360;
  char acStack_358 [15];
  undefined4 uStack_349;
  undefined1 auStack_344 [267];
  undefined4 uStack_239;
  undefined1 auStack_234 [524];
  ulonglong uStack_28;
  
                    /* 0x89b0  153  SimSBjobstat */
  uStack_28 = DAT_1800516d8 ^ (ulonglong)auStack_388;
  if (*param_1 == '\0') {
    if (param_2 != 0) {
      pcVar4 = (char *)GetSorResStringEx(0xce4);
      lVar10 = param_2 - (longlong)pcVar4;
      do {
        cVar1 = *pcVar4;
        pcVar4[lVar10] = cVar1;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
    }
  }
  else {
    lVar10 = -(longlong)param_1;
    do {
      cVar1 = *param_1;
      param_1[(longlong)(acStack_358 + lVar10)] = cVar1;
      param_1 = param_1 + 1;
    } while (cVar1 != '\0');
    lVar10 = 0;
    iVar11 = 0;
    if (0 < DAT_180052cd4) {
      do {
        pcVar4 = &DAT_180052220 + (longlong)iVar11 * 10;
        lVar12 = -(longlong)pcVar4;
        do {
          cVar1 = *pcVar4;
          cVar2 = pcVar4[(longlong)(acStack_358 + lVar12)];
          if (cVar1 != cVar2) break;
          pcVar4 = pcVar4 + 1;
        } while (cVar2 != '\0');
        if (cVar1 == cVar2) {
          lVar12 = (longlong)iVar11;
          if ((&DAT_180052cac)[lVar12] != 2) goto LAB_18002a8a8;
          uStack_349._1_1_ = 0;
          pcVar4 = &DAT_180052284 + lVar12 * 0x104;
          if (*pcVar4 == '\0') {
            lVar8 = 0;
            do {
              pcVar4 = acStack_358 + lVar8;
              acStack_358[lVar8 + 0x10] = *pcVar4;
              lVar8 = lVar8 + 1;
            } while (*pcVar4 != '\0');
          }
          else {
            iVar11 = *(int *)(*(longlong *)SBdataptr_exref + 0x1218);
            if (iVar11 == 0) {
              FUN_180008f80((longlong)&uStack_349 + 1,&DAT_18003f9b0,pcVar4,acStack_358);
            }
            else if (iVar11 == 1) {
              FUN_180026740(pcVar4,acStack_358,(undefined1 *)((longlong)&uStack_349 + 1),1);
            }
            else if (iVar11 == 2) {
              FUN_180008f80((longlong)&uStack_349 + 1,"%s/%s",pcVar4,acStack_358);
            }
          }
          puVar3 = &uStack_349;
          do {
            puVar9 = puVar3;
            puVar3 = (undefined4 *)((longlong)puVar9 + 1);
          } while (*(char *)((longlong)puVar9 + 1) != '\0');
          *(undefined4 *)((longlong)puVar9 + 1) = DAT_1800420dc;
          *(undefined1 *)((longlong)puVar9 + 5) = DAT_1800420e0;
          iVar11 = FUN_180026510((char *)0x0,(char *)((longlong)&uStack_349 + 1));
          if (iVar11 != -1) {
            (&DAT_180052cac)[lVar12] = 0;
LAB_18002a8a8:
            iVar11 = *(int *)(*(longlong *)SBdataptr_exref + 0x1214);
            if (iVar11 == 0) {
              FUN_180008f80((longlong)&uStack_239 + 1,"%s.%s",acStack_358,&DAT_18004289c);
              iVar11 = *(int *)(*(longlong *)SBdataptr_exref + 0x1218);
              if (iVar11 != 0) {
                if (iVar11 == 1) {
                  if ((&DAT_180052284)[lVar12 * 0x104] != '\0') {
                    FUN_180026740(&DAT_180052284 + lVar12 * 0x104,acStack_358,
                                  (undefined1 *)((longlong)&uStack_239 + 1),1);
                    puVar3 = &uStack_239;
                    do {
                      puVar9 = puVar3;
                      puVar3 = (undefined4 *)((longlong)puVar9 + 1);
                    } while (*(char *)((longlong)puVar9 + 1) != '\0');
                    *(undefined4 *)((longlong)puVar9 + 1) = DAT_1800420dc;
                    *(undefined1 *)((longlong)puVar9 + 5) = DAT_1800420e0;
                  }
                }
                else if (iVar11 != 2) goto LAB_18002a990;
              }
              iVar11 = FUN_18002bc80((char *)((longlong)&uStack_239 + 1));
              if (iVar11 == -1) goto LAB_18002a990;
            }
            else {
              if (((iVar11 != 1) && (iVar11 != 2)) && (iVar11 != 3)) {
                return 0xffffffff;
              }
              do {
                pcVar4 = acStack_358 + lVar10;
                acStack_358[lVar10 + 0x10] = *pcVar4;
                lVar10 = lVar10 + 1;
              } while (*pcVar4 != '\0');
              FUN_180008f80((longlong)&uStack_239 + 1,"%s.%s",acStack_358,&DAT_18004289c);
              iVar11 = FUN_18002b2c0((char *)((longlong)&uStack_239 + 1),(longlong)&uStack_239 + 1,
                                     &DAT_180052284 + lVar12 * 0x104);
              if (iVar11 != 0) goto LAB_18002a990;
              iVar11 = FUN_18002bc80((char *)((longlong)&uStack_239 + 1));
              if (iVar11 == -1) {
                return 0xffffffff;
              }
              remove((char *)((longlong)&uStack_239 + 1));
            }
            if (iVar11 == 0) {
              if (param_2 != 0) {
                pcVar4 = (char *)GetSorResStringEx(0xcea);
                lVar10 = param_2 - (longlong)pcVar4;
                do {
                  cVar1 = *pcVar4;
                  pcVar4[lVar10] = cVar1;
                  pcVar4 = pcVar4 + 1;
                } while (cVar1 != '\0');
              }
              return 0;
            }
            if (iVar11 == 1) {
              if (param_2 != 0) {
                pcVar4 = (char *)GetSorResStringEx(0xce9);
                lVar10 = param_2 - (longlong)pcVar4;
                do {
                  cVar1 = *pcVar4;
                  pcVar4[lVar10] = cVar1;
                  pcVar4 = pcVar4 + 1;
                } while (cVar1 != '\0');
              }
              return 1;
            }
            if (iVar11 == 2) {
              if (param_2 != 0) {
                pcVar4 = (char *)GetSorResStringEx(0xceb);
                lVar10 = param_2 - (longlong)pcVar4;
                do {
                  cVar1 = *pcVar4;
                  pcVar4[lVar10] = cVar1;
                  pcVar4 = pcVar4 + 1;
                } while (cVar1 != '\0');
              }
              GRamask(0x10);
              msw_modify_run_menu(*(undefined4 *)GRamask1_exref);
              (&DAT_180052cac)[lVar12] = 1;
              return 2;
            }
            if (iVar11 == 3) {
              if (param_2 != 0) {
                uVar5 = GetSorResStringEx(0xce8);
                FUN_180008f80(param_2,"%s %s",uVar5,acStack_358);
              }
              return 3;
            }
            if (iVar11 == 4) {
              if (param_2 != 0) {
                pcVar4 = (char *)GetSorResStringEx(0xcec);
                lVar10 = param_2 - (longlong)pcVar4;
                do {
                  cVar1 = *pcVar4;
                  pcVar4[lVar10] = cVar1;
                  pcVar4 = pcVar4 + 1;
                } while (cVar1 != '\0');
              }
              return 4;
            }
          }
LAB_18002a990:
          if (param_2 == 0) {
            return 0xffffffff;
          }
          pcVar4 = (char *)GetSorResStringEx(0xced);
          lVar10 = param_2 - (longlong)pcVar4;
          do {
            cVar1 = *pcVar4;
            pcVar4[lVar10] = cVar1;
            pcVar4 = pcVar4 + 1;
          } while (cVar1 != '\0');
          return 0xffffffff;
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 < DAT_180052cd4);
    }
    if (param_2 != 0) {
      uVar5 = GetSorResStringEx(0xce7);
      uVar6 = GetSorResStringEx(0xce6);
      uVar7 = GetSorResStringEx(0xce5);
      uStack_368 = uVar6;
      uStack_360 = uVar5;
      FUN_180008f80(param_2,"%s%s%s%s",uVar7,acStack_358);
    }
  }
  return 0xffffffff;
}

/* RVA 0x89c0 */
void SimSBquals(char *param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  
                    /* 0x89c0  156  SimSBquals */
  if (param_2 == 0) {
    pcVar2 = (char *)(*(longlong *)SBdataptr_exref + 0xb10);
    if (pcVar2 != (char *)0x0) {
      do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
        *param_1 = cVar1;
        param_1 = param_1 + 1;
      } while (cVar1 != '\0');
    }
  }
  else if (param_2 == 1) {
    pcVar2 = (char *)(*(longlong *)SBdataptr_exref + 0xb10);
    do {
      cVar1 = *param_1;
      param_1 = param_1 + 1;
      *pcVar2 = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    return;
  }
  return;
}

/* RVA 0x89d0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SimSBreadback(char *param_1)

{
  char *pcVar1;
  char cVar2;
  char cVar3;
  undefined4 uVar4;
  code *pcVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined1 *puVar11;
  longlong lVar12;
  longlong lVar13;
  char *pcVar14;
  longlong lVar15;
  undefined4 *puVar16;
  undefined1 auStack_4b8 [32];
  undefined8 uStack_498;
  char *pcStack_490;
  undefined8 uStack_488;
  undefined8 uStack_480;
  char acStack_478 [271];
  undefined1 uStack_369;
  char acStack_368 [271];
  undefined1 uStack_259;
  char acStack_258 [272];
  char acStack_148 [272];
  ulonglong uStack_38;
  
                    /* 0x89d0  157  SimSBreadback */
  uStack_38 = DAT_1800516d8 ^ (ulonglong)auStack_4b8;
  if (*param_1 == '\0') {
    uStack_498 = GetSorResStringEx(0xce4);
    FUN_180008f80(dbxbuf_exref,"%c%c%s",0x5e,0x58);
    iVar6 = EXyesno(dbxbuf_exref,2,1);
    if (iVar6 == 1) {
      return 0xffffffff;
    }
  }
  lVar13 = -(longlong)param_1;
  do {
    cVar2 = *param_1;
    param_1[(longlong)(acStack_478 + lVar13)] = cVar2;
    param_1 = param_1 + 1;
  } while (cVar2 != '\0');
  lVar13 = 0;
  iVar6 = 0;
  if (0 < DAT_180052cd4) {
    do {
      pcVar8 = &DAT_180052220 + (longlong)iVar6 * 10;
      lVar15 = -(longlong)pcVar8;
      do {
        cVar2 = *pcVar8;
        cVar3 = pcVar8[(longlong)(acStack_478 + lVar15)];
        if (cVar2 != cVar3) break;
        pcVar8 = pcVar8 + 1;
      } while (cVar3 != '\0');
      if (cVar2 == cVar3) goto LAB_18002aced;
      iVar6 = iVar6 + 1;
    } while (iVar6 < DAT_180052cd4);
  }
  uVar9 = GetSorResStringEx(0xce7);
  uVar10 = GetSorResStringEx(0xce6);
  uStack_498 = GetSorResStringEx(0xce5);
  pcStack_490 = acStack_478;
  uStack_488 = uVar10;
  uStack_480 = uVar9;
  FUN_180008f80(dbxbuf_exref,"%c%c%s%s%s%s",0x5e,0x58);
  iVar7 = EXyesno(dbxbuf_exref,2,1);
  if (iVar7 == 1) {
    return 0xffffffff;
  }
LAB_18002aced:
  lVar15 = (longlong)iVar6;
  puVar16 = &DAT_180052cac + lVar15;
  if ((&DAT_180052cac)[lVar15] != 1) {
    uVar9 = GetSorResStringEx(0xcef);
    uVar10 = GetSorResStringEx(0xcee);
    uStack_498 = GetSorResStringEx(0xce5);
    pcStack_490 = acStack_478;
    uStack_488 = uVar10;
    uStack_480 = uVar9;
    FUN_180008f80(dbxbuf_exref,"%c%c%s%s%s%s",0x5e,0x58);
    iVar7 = EXyesno(dbxbuf_exref,2,1);
    if (iVar7 == 1) {
      return 0xffffffff;
    }
  }
  pcVar8 = acStack_478;
  lVar12 = *(longlong *)topfinfo_exref - (longlong)pcVar8;
  do {
    cVar2 = *pcVar8;
    cVar3 = pcVar8[lVar12];
    if (cVar2 != cVar3) break;
    pcVar8 = pcVar8 + 1;
  } while (cVar3 != '\0');
  if (cVar2 != cVar3) {
    uVar9 = GetSorResStringEx(0xcf2);
    uVar10 = GetSorResStringEx(0xcf1);
    uStack_498 = GetSorResStringEx(0xcf0);
    pcStack_490 = acStack_478;
    uStack_488 = uVar10;
    uStack_480 = uVar9;
    FUN_180008f80(dbxbuf_exref,"%c%c%s%s%s%s?",0x5e,0x3f);
    uVar9 = EXyesno(dbxbuf_exref,3,1);
    if ((int)uVar9 == 2) {
      return uVar9;
    }
  }
  if (((((*(int *)partial_results_exref == 0) || (iVar7 = GRinqiap(), iVar7 != 1)) ||
       (*(int *)triggered_by_canned_exref != 0)) ||
      ((*(int *)in_canned_exref != 0 || (*(int *)not_in_aspmsg_exref == 0)))) ||
     (uVar9 = FUN_18001a650(acStack_478), (int)uVar9 != 0)) {
    iVar7 = MVGetProductCode();
    pcVar8 = ".aprsum";
    pcVar14 = ".aprsum";
    if (iVar7 == 1) {
      pcVar14 = ".sum";
    }
    FUN_180008f80(acStack_368,&DAT_18003f9b0,acStack_478,pcVar14);
    lVar12 = 0;
    do {
      pcVar14 = acStack_478 + lVar12;
      acStack_148[lVar12] = *pcVar14;
      lVar12 = lVar12 + 1;
    } while (*pcVar14 != '\0');
    if (*(int *)(*(longlong *)SBdataptr_exref + 0x1214) == 0) {
      if ((*(int *)(*(longlong *)SBdataptr_exref + 0x1218) == 1) &&
         (lVar15 = lVar15 * 0x104, (&DAT_180052284)[lVar15] != '\0')) {
        FUN_180026740(&DAT_180052284 + lVar15,acStack_478,acStack_368,1);
        iVar7 = MVGetProductCode();
        pcVar14 = ".aprsum";
        if (iVar7 == 1) {
          pcVar14 = ".sum";
        }
        puVar11 = &uStack_369;
        do {
          pcVar1 = puVar11 + 1;
          puVar11 = puVar11 + 1;
        } while (*pcVar1 != '\0');
        lVar12 = 0;
        do {
          cVar2 = pcVar14[lVar12];
          puVar11[lVar12] = cVar2;
          lVar12 = lVar12 + 1;
        } while (cVar2 != '\0');
        FUN_180026740(&DAT_180052284 + lVar15,acStack_478,acStack_148,1);
      }
    }
    else {
      iVar7 = FUN_18002b2c0(acStack_368,acStack_368,&DAT_180052284 + lVar15 * 0x104);
      if (iVar7 != 0) {
        uStack_498 = GetSorResStringEx(0xcf3);
        pcStack_490 = acStack_368;
        FUN_180008f80(dbxbuf_exref,"%c%c%s%s",0x5e,0x58);
        iVar7 = EXyesno(dbxbuf_exref);
        if (iVar7 == 1) {
          return 0xffffffff;
        }
      }
    }
    iVar7 = _access(acStack_368,0);
    if (iVar7 == 0) {
      uVar4 = *(undefined4 *)partial_results_exref;
      *(undefined4 *)partial_results_exref = 0;
      OPreabck(acStack_148);
      *(int *)(*(longlong *)topfinfo_exref + 0x67c) =
           *(int *)(*(longlong *)topfinfo_exref + 0x67c) + 1;
      *(undefined4 *)partial_results_exref = uVar4;
    }
    else {
      uVar9 = GetSorResStringEx(0xcf5);
      uStack_498 = GetSorResStringEx(0xcf4);
      pcStack_490 = acStack_368;
      uStack_488 = uVar9;
      FUN_180008f80(dbxbuf_exref,"%c%c%s%s%s?",0x5e,0x58);
      iVar7 = EXyesno(dbxbuf_exref);
      if (iVar7 == 1) {
        return 0xffffffff;
      }
    }
    DAT_180052cd4 = DAT_180052cd4 + -1;
    if (iVar6 < DAT_180052cd4) {
      do {
        if (DAT_180052cd4 == 0) break;
        lVar12 = (longlong)iVar6;
        lVar15 = lVar12 + 1;
        pcVar14 = &DAT_180052220 + lVar15 * 10;
        do {
          cVar2 = *pcVar14;
          pcVar14[lVar12 * 10 + lVar15 * -10] = cVar2;
          pcVar14 = pcVar14 + 1;
        } while (cVar2 != '\0');
        pcVar14 = &DAT_180052284 + lVar15 * 0x104;
        do {
          cVar2 = *pcVar14;
          pcVar14[lVar12 * 0x104 + lVar15 * -0x104] = cVar2;
          pcVar14 = pcVar14 + 1;
        } while (cVar2 != '\0');
        iVar6 = iVar6 + 1;
        *puVar16 = puVar16[1];
        puVar16 = puVar16 + 1;
      } while (iVar6 < DAT_180052cd4);
    }
    lVar15 = (longlong)iVar6;
    (&DAT_180052220)[lVar15 * 10] = 0;
    (&DAT_180052284)[lVar15 * 0x104] = 0;
    pcVar5 = SBdataptr_exref;
    (&DAT_180052cac)[lVar15] = 0;
    if (*(int *)(*(longlong *)pcVar5 + 0x1214) != 0) {
      acStack_258[0] = '\0';
      lVar15 = 0;
      do {
        pcVar14 = acStack_148 + lVar15;
        acStack_258[lVar15] = *pcVar14;
        lVar15 = lVar15 + 1;
      } while (*pcVar14 != '\0');
      iVar6 = MVGetProductCode();
      pcVar14 = ".aprinp";
      if (iVar6 == 1) {
        pcVar14 = ".inp";
      }
      puVar11 = &uStack_259;
      do {
        pcVar1 = puVar11 + 1;
        puVar11 = puVar11 + 1;
      } while (*pcVar1 != '\0');
      lVar15 = 0;
      do {
        cVar2 = pcVar14[lVar15];
        puVar11[lVar15] = cVar2;
        lVar15 = lVar15 + 1;
      } while (cVar2 != '\0');
      remove(acStack_258);
      acStack_258[0] = '\0';
      do {
        pcVar14 = acStack_148 + lVar13;
        acStack_258[lVar13] = *pcVar14;
        lVar13 = lVar13 + 1;
      } while (*pcVar14 != '\0');
      iVar6 = MVGetProductCode();
      puVar11 = &uStack_259;
      if (iVar6 == 1) {
        pcVar8 = ".sum";
      }
      do {
        pcVar14 = puVar11 + 1;
        puVar11 = puVar11 + 1;
      } while (*pcVar14 != '\0');
      lVar13 = 0;
      do {
        cVar2 = pcVar8[lVar13];
        puVar11[lVar13] = cVar2;
        lVar13 = lVar13 + 1;
      } while (cVar2 != '\0');
      remove(acStack_258);
    }
    if (DAT_180052cd4 == 0) {
      memset(&DAT_180052220,0,0xab8);
      GRamask(8);
      GRamask(0x10);
      msw_modify_run_menu(*(undefined4 *)GRamask1_exref);
    }
  }
  return 0;
}

/* RVA 0x89e0 */
DWORD __stdcall
SearchPathA(LPCSTR lpPath,LPCSTR lpFileName,LPCSTR lpExtension,DWORD nBufferLength,LPSTR lpBuffer,
           LPSTR *lpFilePart)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800089e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DVar1 = SearchPathA(lpPath,lpFileName,lpExtension,nBufferLength,lpBuffer,lpFilePart);
  return DVar1;
}

/* RVA 0x89f0 */
undefined8 SimSendMainWndMessage(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 local_res20;
  
                    /* 0x89f0  148  SimSendMainWndMessage */
  local_res20 = 0;
  if (DAT_180051bb0 == (longlong *)0x0) {
    return 0;
  }
  (**(code **)(*DAT_180051bb0 + 0x28))(DAT_180051bb0,param_1,param_2,param_3,&local_res20);
  return local_res20;
}

/* RVA 0x8a40 */
void SimSetEOSolveStatus(char *param_1,uint param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  AFX_MODULE_STATE *pAVar2;
  char *pcVar3;
  longlong lVar5;
  longlong lVar4;
  AFX_MAINTAIN_STATE2 local_18 [16];
  
  pAVar2 = AfxGetModuleState();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_18,pAVar2);
  iVar1 = GRinqeop();
  if (iVar1 != 0) {
    GRseteorsl((param_2 != 0) + '\x01');
    if ((param_1 != (char *)0x0) && (param_2 < 8)) {
      lVar4 = -1;
      do {
        lVar5 = lVar4;
        lVar4 = lVar5 + 1;
      } while (param_1[lVar4] != '\0');
      pcVar3 = operator_new__(lVar5 + 0x65);
      iVar1 = _stricmp(param_1,"unknown");
      if (iVar1 == 0) {
        FUN_180008f80(pcVar3,(&PTR_s_EO_Solution_converged_18004f680)[(int)param_2],param_3,param_4)
        ;
      }
      else {
        FUN_180008f80(pcVar3,(&PTR_s_EO_Solution_for_scope__s_converg_18004f640)[(int)param_2],
                      param_1,param_4);
      }
      thunk_FUN_180008f30(pcVar3);
      operator_delete__(pcVar3);
      FUN_180008f30("");
      GRsetust(0);
    }
  }
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_18);
  return;
}

/* RVA 0x8b40 */
undefined4 SimSetNoMessage(undefined4 param_1)

{
  undefined4 uVar1;
  
                    /* 0x8b40  107  SimSetNoMessage */
  uVar1 = DAT_180051bc0;
  DAT_180051bc0 = param_1;
  return uVar1;
}

/* RVA 0x8b50 */
bool FUN_180008b50(LPSTR param_1)

{
  BOOL BVar1;
  bool bVar2;
  DWORD local_res10 [6];
  _PROCESS_INFORMATION local_98;
  _STARTUPINFOA local_78;
  
  local_78._4_8_ = 0;
  local_78._12_8_ = 0;
  local_78.hStdError._4_4_ = 0;
  local_78._20_8_ = 0;
  local_78._28_8_ = 0;
  local_78.dwY = 0;
  local_78.dwXSize = 0;
  local_78.dwYSize = 0;
  local_78.dwXCountChars = 0;
  local_78.dwYCountChars = 0;
  local_78.dwFillAttribute = 0;
  local_78.dwFlags = 0;
  local_78.wShowWindow = 0;
  local_78.cbReserved2 = 0;
  local_78._68_8_ = 0;
  local_78._76_8_ = 0;
  local_78._84_8_ = 0;
  local_78._92_8_ = 0;
  local_78.cb = 0x68;
  BVar1 = CreateProcessA((LPCSTR)0x0,param_1,(LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0,0
                         ,0x8000000,(LPVOID)0x0,(LPCSTR)0x0,&local_78,&local_98);
  bVar2 = false;
  if (BVar1 != 0) {
    local_res10[0] = 0;
    WaitForSingleObject(local_98.hProcess,0xffffffff);
    GetExitCodeProcess(local_98.hProcess,local_res10);
    bVar2 = local_res10[0] == 0;
  }
  return bVar2;
}

/* RVA 0x8c10 */
void SimUpdateMessageView(int param_1,char *param_2)

{
  char cVar1;
  HGLOBAL pvVar2;
  longlong lVar4;
  longlong lVar3;
  
                    /* 0x8c10  27  SimUpdateMessageView */
  SimReflect(1,0,param_2);
  pvVar2 = (HGLOBAL)0x0;
  if (((param_1 == 0) && (param_2 != (char *)0x0)) && (*param_2 != '\0')) {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_2[lVar3] != '\0');
    pvVar2 = GlobalAlloc(0,lVar4 + 2);
    lVar3 = (longlong)pvVar2 - (longlong)param_2;
    do {
      cVar1 = *param_2;
      param_2[lVar3] = cVar1;
      param_2 = param_2 + 1;
    } while (cVar1 != '\0');
  }
  SimSendMainWndMessage(0x543,(ulonglong)(param_1 != 0),pvVar2);
  return;
}

/* RVA 0x8cb0 */
void SimdllInitExtDLL(void)

{
  CDynLinkLibrary *this;
  
                    /* 0x8cb0  103  SimdllInitExtDLL */
  this = operator_new(0x80);
  if (this == (CDynLinkLibrary *)0x0) {
    return;
  }
  CDynLinkLibrary::CDynLinkLibrary(this,(AFX_EXTENSION_MODULE *)&DAT_180051b68,0);
  return;
}

/* RVA 0x8ce0 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 WPFSimAskReexecuteFortran(LPCSTR param_1,LPCSTR param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  BSTR pOVar5;
  longlong lVar7;
  longlong lVar6;
  ulonglong uVar8;
  char *pcVar9;
  undefined1 *puVar10;
  char *pcVar11;
  undefined *puStackY_70;
  undefined1 auStackY_68 [32];
  int local_38 [2];
  undefined8 local_30;
  BSTR local_28;
  ulonglong local_20;
  
                    /* 0x8ce0  150  WPFSimAskReexecuteFortran */
  local_20 = DAT_1800516d8 ^ (ulonglong)&local_28;
  pcVar11 = (char *)0x0;
  if (param_2 == (LPCSTR)0x0) {
    pOVar5 = (BSTR)0x0;
  }
  else {
    puStackY_70 = (undefined *)0x180008d30;
    iVar2 = MultiByteToWideChar(0,0,param_2,-1,(LPWSTR)0x0,0);
    puStackY_70 = (undefined *)0x180008d3e;
    pOVar5 = SysAllocStringLen((OLECHAR *)0x0,iVar2 - 1);
    if (pOVar5 != (BSTR)0x0) {
      puStackY_70 = (undefined *)0x180008d61;
      iVar3 = MultiByteToWideChar(0,0,param_2,-1,pOVar5,iVar2);
      if (iVar3 != iVar2) {
        puStackY_70 = (undefined *)0x180008eec;
        SysFreeString(pOVar5);
        goto LAB_180008eec;
      }
    }
    if (pOVar5 == (BSTR)0x0) goto LAB_180008eec;
  }
  puStackY_70 = (undefined *)0x180008d85;
  local_28 = pOVar5;
  SysFreeString(pOVar5);
  if (param_1 == (LPCSTR)0x0) {
    pOVar5 = (BSTR)0x0;
  }
  else {
    puStackY_70 = (undefined *)0x180008da6;
    iVar2 = MultiByteToWideChar(0,0,param_1,-1,(LPWSTR)0x0,0);
    puStackY_70 = (undefined *)0x180008db4;
    pOVar5 = SysAllocStringLen((OLECHAR *)0x0,iVar2 - 1);
    if (pOVar5 != (BSTR)0x0) {
      puStackY_70 = (undefined *)0x180008dd9;
      iVar3 = MultiByteToWideChar(0,0,param_1,-1,pOVar5,iVar2);
      if (iVar3 != iVar2) {
        puStackY_70 = (undefined *)0x180008de7;
        SysFreeString(pOVar5);
        goto LAB_180008eec;
      }
    }
    if (pOVar5 == (BSTR)0x0) {
LAB_180008eec:
                    /* WARNING: Subroutine does not return */
      puStackY_70 = &UNK_180008ef6;
      FUN_180001380(-0x7ff8fff2);
    }
  }
  puStackY_70 = (undefined *)0x180008e06;
  uVar4 = FUN_180009a30(pOVar5,&local_28);
  puStackY_70 = (undefined *)0x180008e12;
  SysFreeString(pOVar5);
  pOVar5 = local_28;
  puVar10 = auStackY_68;
  if (local_28 != (LPCWSTR)0x0) {
    lVar6 = -1;
    do {
      lVar7 = lVar6;
      lVar6 = lVar7 + 1;
    } while (local_28[lVar6] != L'\0');
    iVar2 = (int)lVar7 + 2;
    puVar10 = auStackY_68;
    if (iVar2 < 0x40000000) {
      lVar6 = (longlong)(int)lVar6 * 2;
      uVar8 = lVar6 + 0x11;
      if (uVar8 <= lVar6 + 2U) {
        uVar8 = 0xffffffffffffff0;
      }
      puStackY_70 = (undefined *)0x180008e6f;
      lVar6 = -(uVar8 & 0xfffffffffffffff0);
      puVar10 = auStackY_68 + lVar6;
      pcVar9 = (char *)((longlong)&local_28 + lVar6);
      if (pcVar9 != (char *)0x0) {
        *(undefined8 *)((longlong)local_38 + lVar6 + 8) = 0;
        *(undefined8 *)((longlong)local_38 + lVar6) = 0;
        *(int *)((longlong)local_38 + lVar6 + -8) = iVar2 * 2;
        *pcVar9 = '\0';
        *(char **)(auStackY_68 + lVar6 + 0x20) = pcVar9;
        *(undefined8 *)(auStackY_68 + lVar6 + -8) = 0x180008ea3;
        iVar2 = WideCharToMultiByte(0,0,pOVar5,-1,*(LPSTR *)(auStackY_68 + lVar6 + 0x20),
                                    *(int *)((longlong)local_38 + lVar6 + -8),
                                    *(LPCSTR *)((longlong)local_38 + lVar6),
                                    *(LPBOOL *)((longlong)local_38 + lVar6 + 8));
        puVar10 = auStackY_68 + lVar6;
        if (iVar2 == 0) {
          pcVar9 = (char *)0x0;
        }
        pcVar11 = pcVar9;
      }
    }
  }
  lVar6 = (longlong)param_2 - (longlong)pcVar11;
  do {
    cVar1 = *pcVar11;
    pcVar11[lVar6] = cVar1;
    pcVar11 = pcVar11 + 1;
  } while (cVar1 != '\0');
  *(undefined8 *)(puVar10 + -8) = 0x180008ecd;
  return uVar4;
}

/* RVA 0x8f00 */
void FUN_180008f00(void)

{
  SimSendMainWndMessage(0x53e,0,0);
  return;
}

/* RVA 0x8f10 */
void FUN_180008f10(void)

{
  SimSendMainWndMessage(0x53c,0,0);
  return;
}

/* RVA 0x8f20 */
void FUN_180008f20(undefined8 param_1,int param_2)

{
  SimSendMainWndMessage(0x53b,(longlong)param_2,param_1);
  return;
}

/* RVA 0x8f30 */
void FUN_180008f30(char *param_1)

{
  char *pcVar1;
  
  if (param_1 == (char *)0x0) {
    pcVar1 = (char *)0x0;
  }
  else {
    pcVar1 = _strdup(param_1);
  }
  SimSendMainWndMessage(0x536,0,pcVar1);
  return;
}

/* RVA 0x8f60 */
void FUN_180008f60(undefined8 param_1,int param_2)

{
  SimSendMainWndMessage(0x53a,(longlong)param_2,param_1);
  return;
}

/* RVA 0x8f70 */
void thunk_FUN_180008f30(char *param_1)

{
  char *pcVar1;
  
  if (param_1 == (char *)0x0) {
    pcVar1 = (char *)0x0;
  }
  else {
    pcVar1 = _strdup(param_1);
  }
  SimSendMainWndMessage(0x536,0,pcVar1);
  return;
}

/* RVA 0x8f80 */
int FUN_180008f80(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong *puVar2;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  puVar2 = (ulonglong *)FUN_180001b20();
  iVar1 = __stdio_common_vsprintf(*puVar2 | 1,param_1,0xffffffffffffffff,param_2,0,&local_res18);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  return iVar1;
}

/* RVA 0x8fe0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180008fe0(void)

{
  int iVar1;
  HRESULT HVar2;
  LPWSTR lpWideCharStr;
  WCHAR local_88 [48];
  LPVOID local_28;
  CLSID local_20;
  ulonglong local_10;
  
  local_10 = DAT_1800516d8 ^ (ulonglong)&local_28;
  lpWideCharStr = local_88;
  if (lpWideCharStr == (LPWSTR)0x0) {
    lpWideCharStr = (LPCOLESTR)0x0;
  }
  else {
    local_88[0] = L'\0';
    iVar1 = MultiByteToWideChar(0,0,"AspenTech.AspenPlus.WpfSimdll.DialogDriver.410",-1,
                                lpWideCharStr,0x2f);
    if (iVar1 == 0) {
      lpWideCharStr = (LPCOLESTR)0x0;
    }
  }
  HVar2 = CLSIDFromProgID(lpWideCharStr,&local_20);
  if (-1 < HVar2) {
    local_28 = (LPVOID)0x0;
    HVar2 = CoCreateInstance(&local_20,(LPUNKNOWN)0x0,1,(IID *)&DAT_180043ee8,&local_28);
    if (-1 < HVar2) {
      return local_28;
    }
  }
  return 0;
}

/* RVA 0x90b0 */
undefined4 FUN_1800090b0(undefined8 param_1)

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
  
  plVar4 = (longlong *)FUN_180008fe0();
  if (plVar4 != (longlong *)0x0) {
    local_res18 = L"Show";
    lVar1 = *plVar4;
    LVar2 = GetUserDefaultLCID();
    iVar3 = (**(code **)(lVar1 + 0x28))(plVar4,&DAT_180043ef8,&local_res18,1,LVar2,local_res10);
    if (-1 < iVar3) {
      local_60 = 0;
      local_58 = 1;
      local_68 = &local_50;
      uVar5 = 0;
      do {
        VariantInit((VARIANTARG *)&(&local_50)[uVar5].n2);
        uVar5 = uVar5 + 1;
      } while (uVar5 < (uint)local_58);
      local_50.n2.vt = 8;
      local_50.decVal.u2 = (_union_1719)param_1;
      COleVariant::COleVariant((COleVariant *)&local_38,0,3);
      lVar1 = *plVar4;
      LVar2 = GetUserDefaultLCID();
      iVar3 = (**(code **)(lVar1 + 0x30))
                        (plVar4,local_res10[0],&DAT_180043ef8,LVar2,1,&local_68,&local_38,0,0);
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

/* RVA 0x9220 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_180009220(int param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
             undefined4 param_5,undefined4 param_6)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  LCID LVar4;
  longlong *plVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined1 auStackY_1a8 [32];
  undefined4 local_150;
  BSTR local_148;
  longlong local_140;
  _union_2707 *local_138;
  undefined8 local_130;
  undefined8 local_128;
  VARIANTARG local_120;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  _union_2707 local_c8;
  undefined2 local_b0;
  undefined4 local_a8;
  undefined2 local_98;
  undefined4 local_90;
  undefined2 local_80;
  undefined8 local_78;
  undefined2 local_68;
  undefined8 local_60;
  undefined2 local_50;
  longlong *local_48;
  ulonglong local_38;
  
  local_38 = DAT_1800516d8 ^ (ulonglong)auStackY_1a8;
  plVar5 = (longlong *)FUN_180008fe0();
  uVar7 = 0;
  if (plVar5 != (longlong *)0x0) {
    uVar7 = 0;
    iVar2 = MultiByteToWideChar(0,0,"ShowEOExportWzd",-1,(LPWSTR)0x0,0);
    local_148 = SysAllocStringLen((OLECHAR *)0x0,iVar2 - 1);
    if (local_148 != (BSTR)0x0) {
      iVar3 = MultiByteToWideChar(0,0,"ShowEOExportWzd",-1,local_148,iVar2);
      if (iVar3 != iVar2) {
        SysFreeString(local_148);
        local_148 = (BSTR)0x0;
        goto LAB_180009486;
      }
    }
    if (local_148 == (BSTR)0x0) {
LAB_180009486:
                    /* WARNING: Subroutine does not return */
      FUN_180001380(-0x7ff8fff2);
    }
    lVar1 = *plVar5;
    GetUserDefaultLCID();
    iVar2 = (**(code **)(lVar1 + 0x28))(plVar5,&DAT_180043ef8,&local_148,1);
    if (iVar2 < 0) {
      (**(code **)(*plVar5 + 0x10))(plVar5);
    }
    else {
      local_130 = 0;
      local_128 = 6;
      local_138 = &local_c8;
      uVar6 = 0;
      do {
        VariantInit((VARIANTARG *)&(&local_c8)[uVar6].n2);
        uVar6 = uVar6 + 1;
      } while (uVar6 < (uint)local_128);
      local_140 = (longlong)param_1;
      local_50 = 0x400d;
      local_48 = &local_140;
      local_68 = 8;
      local_80 = 8;
      local_98 = 3;
      local_b0 = 3;
      local_a8 = param_5;
      local_c8.n2.vt = 3;
      local_c8._8_4_ = param_6;
      local_108 = 0;
      uStack_100 = 0;
      local_f8 = 0;
      uStack_f0 = 0;
      local_e8 = 0;
      uStack_e0 = 0;
      local_d8 = 0;
      uStack_d0 = 0;
      local_90 = param_4;
      local_78 = param_3;
      local_60 = param_2;
      COleVariant::COleVariant((COleVariant *)&local_120,0,3);
      lVar1 = *plVar5;
      LVar4 = GetUserDefaultLCID();
      iVar2 = (**(code **)(lVar1 + 0x30))(plVar5,local_150,&DAT_180043ef8,LVar4);
      uVar7 = 0;
      if (-1 < iVar2) {
        uVar7 = local_120.n1._8_4_;
      }
      (**(code **)(*plVar5 + 0x10))(plVar5);
      VariantClear(&local_120);
    }
    SysFreeString(local_148);
  }
  return uVar7;
}

/* RVA 0x94a0 */
int FUN_1800094a0(void)

{
  longlong lVar1;
  LCID LVar2;
  int iVar3;
  undefined4 uVar4;
  longlong *plVar5;
  undefined4 local_res8 [2];
  wchar_t *local_res10;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  VARIANTARG local_30;
  
  plVar5 = (longlong *)FUN_180008fe0();
  if (plVar5 != (longlong *)0x0) {
    local_res10 = L"ShowRegression";
    lVar1 = *plVar5;
    LVar2 = GetUserDefaultLCID();
    iVar3 = (**(code **)(lVar1 + 0x28))(plVar5,&DAT_180043ef8,&local_res10,1,LVar2,local_res8);
    if (-1 < iVar3) {
      local_48 = 0;
      uStack_40 = 0;
      local_38 = 0;
      COleVariant::COleVariant((COleVariant *)&local_30,0,3);
      lVar1 = *plVar5;
      LVar2 = GetUserDefaultLCID();
      uVar4 = (**(code **)(lVar1 + 0x30))
                        (plVar5,local_res8[0],&DAT_180043ef8,LVar2,1,&local_48,&local_30,0,0);
      if ((int)uVar4 < 0) {
        (**(code **)(*plVar5 + 0x10))(plVar5);
      }
      else {
        (**(code **)(*plVar5 + 0x10))();
        uVar4 = local_30.n1._8_4_;
      }
      VariantClear(&local_30);
      return uVar4;
    }
    (**(code **)(*plVar5 + 0x10))(plVar5);
  }
  return 0;
}

/* RVA 0x95c0 */
undefined4 FUN_1800095c0(undefined8 *param_1,undefined4 param_2)

{
  longlong lVar1;
  LCID LVar2;
  int iVar3;
  longlong *plVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 local_res18 [2];
  BSTR local_res20;
  wchar_t *local_98;
  _union_2707 *local_90;
  undefined8 local_88;
  undefined8 local_80;
  VARIANTARG local_78;
  _union_2707 local_60;
  undefined2 local_48;
  BSTR *local_40;
  
  plVar4 = (longlong *)FUN_180008fe0();
  if (plVar4 != (longlong *)0x0) {
    local_98 = L"ShowUserFortran";
    lVar1 = *plVar4;
    LVar2 = GetUserDefaultLCID();
    iVar3 = (**(code **)(lVar1 + 0x28))(plVar4,&DAT_180043ef8,&local_98,1,LVar2,local_res18);
    if (-1 < iVar3) {
      local_88 = 0;
      local_80 = 2;
      local_90 = &local_60;
      uVar5 = 0;
      do {
        VariantInit((VARIANTARG *)&(&local_60)[uVar5].n2);
        uVar5 = uVar5 + 1;
      } while (uVar5 < (uint)local_80);
      local_res20 = SysAllocString(L"");
      local_48 = 0x4008;
      local_40 = &local_res20;
      local_60.n2.vt = 3;
      local_60._8_4_ = param_2;
      COleVariant::COleVariant((COleVariant *)&local_78,0,3);
      lVar1 = *plVar4;
      LVar2 = GetUserDefaultLCID();
      iVar3 = (**(code **)(lVar1 + 0x30))
                        (plVar4,local_res18[0],&DAT_180043ef8,LVar2,1,&local_90,&local_78,0,0);
      uVar6 = 0;
      if (-1 < iVar3) {
        *param_1 = local_res20;
        uVar6 = local_78.n1._8_4_;
      }
      (**(code **)(*plVar4 + 0x10))(plVar4);
      SysFreeString(local_res20);
      VariantClear(&local_78);
      return uVar6;
    }
    (**(code **)(*plVar4 + 0x10))(plVar4);
  }
  return 0;
}

/* RVA 0x9740 */
undefined4 FUN_180009740(undefined4 param_1,undefined8 param_2)

{
  longlong lVar1;
  LCID LVar2;
  int iVar3;
  longlong *plVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 local_res18 [2];
  wchar_t *local_res20;
  _union_2707 *local_88;
  undefined8 local_80;
  undefined8 local_78;
  VARIANTARG local_70;
  _union_2707 local_58;
  undefined2 local_40;
  undefined4 local_38;
  
  plVar4 = (longlong *)FUN_180008fe0();
  if (plVar4 != (longlong *)0x0) {
    local_res20 = L"ShowWaitingForEditorDlg";
    lVar1 = *plVar4;
    LVar2 = GetUserDefaultLCID();
    iVar3 = (**(code **)(lVar1 + 0x28))(plVar4,&DAT_180043ef8,&local_res20,1,LVar2,local_res18);
    if (-1 < iVar3) {
      local_80 = 0;
      local_78 = 2;
      local_88 = &local_58;
      uVar5 = 0;
      do {
        VariantInit((VARIANTARG *)&(&local_58)[uVar5].n2);
        uVar5 = uVar5 + 1;
      } while (uVar5 < (uint)local_78);
      local_40 = 3;
      local_58.n2.vt = 8;
      local_58.decVal.u2 = (_union_1719)param_2;
      local_38 = param_1;
      COleVariant::COleVariant((COleVariant *)&local_70,0,3);
      lVar1 = *plVar4;
      LVar2 = GetUserDefaultLCID();
      iVar3 = (**(code **)(lVar1 + 0x30))
                        (plVar4,local_res18[0],&DAT_180043ef8,LVar2,1,&local_88,&local_70,0,0);
      uVar6 = 0;
      if (-1 < iVar3) {
        uVar6 = local_70.n1._8_4_;
      }
      (**(code **)(*plVar4 + 0x10))(plVar4);
      VariantClear(&local_70);
      return uVar6;
    }
    (**(code **)(*plVar4 + 0x10))(plVar4);
  }
  return 0;
}

/* RVA 0x98c0 */
undefined4 FUN_1800098c0(undefined8 param_1)

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
  
  plVar4 = (longlong *)FUN_180008fe0();
  if (plVar4 != (longlong *)0x0) {
    local_res18 = L"SimAskReexecute";
    lVar1 = *plVar4;
    LVar2 = GetUserDefaultLCID();
    iVar3 = (**(code **)(lVar1 + 0x28))(plVar4,&DAT_180043ef8,&local_res18,1,LVar2,local_res10);
    if (-1 < iVar3) {
      local_60 = 0;
      local_58 = 1;
      local_68 = &local_50;
      uVar5 = 0;
      do {
        VariantInit((VARIANTARG *)&(&local_50)[uVar5].n2);
        uVar5 = uVar5 + 1;
      } while (uVar5 < (uint)local_58);
      local_50.n2.vt = 8;
      local_50.decVal.u2 = (_union_1719)param_1;
      COleVariant::COleVariant((COleVariant *)&local_38,0,3);
      lVar1 = *plVar4;
      LVar2 = GetUserDefaultLCID();
      iVar3 = (**(code **)(lVar1 + 0x30))
                        (plVar4,local_res10[0],&DAT_180043ef8,LVar2,1,&local_68,&local_38,0,0);
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

/* RVA 0x9a30 */
undefined4 FUN_180009a30(undefined8 param_1,undefined8 *param_2)

{
  longlong lVar1;
  LCID LVar2;
  int iVar3;
  longlong *plVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 local_res18 [2];
  BSTR local_res20;
  wchar_t *local_98;
  undefined2 *local_90;
  undefined8 local_88;
  undefined8 local_80;
  VARIANTARG local_78;
  undefined1 local_60 [24];
  undefined2 local_48;
  undefined8 local_40;
  
  plVar4 = (longlong *)FUN_180008fe0();
  if (plVar4 != (longlong *)0x0) {
    local_98 = L"SimAskReexecuteFortran";
    lVar1 = *plVar4;
    LVar2 = GetUserDefaultLCID();
    iVar3 = (**(code **)(lVar1 + 0x28))(plVar4,&DAT_180043ef8,&local_98,1,LVar2,local_res18);
    if (-1 < iVar3) {
      local_88 = 0;
      local_80 = 2;
      local_90 = (undefined2 *)local_60;
      uVar5 = 0;
      do {
        VariantInit((VARIANTARG *)(local_60 + (ulonglong)uVar5 * 0x18));
        uVar5 = uVar5 + 1;
      } while (uVar5 < (uint)local_80);
      local_res20 = SysAllocString(L"");
      local_48 = 8;
      local_60._0_2_ = 0x4008;
      local_60._8_8_ = &local_res20;
      local_40 = param_1;
      COleVariant::COleVariant((COleVariant *)&local_78,0,3);
      lVar1 = *plVar4;
      LVar2 = GetUserDefaultLCID();
      iVar3 = (**(code **)(lVar1 + 0x30))
                        (plVar4,local_res18[0],&DAT_180043ef8,LVar2,1,&local_90,&local_78,0,0);
      uVar6 = 0;
      if (-1 < iVar3) {
        *param_2 = local_res20;
        uVar6 = local_78.n1._8_4_;
      }
      (**(code **)(*plVar4 + 0x10))(plVar4);
      SysFreeString(local_res20);
      VariantClear(&local_78);
      return uVar6;
    }
    (**(code **)(*plVar4 + 0x10))(plVar4);
  }
  return 0;
}

/* RVA 0x9bc0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

BOOL FUN_180009bc0(LPCSTR param_1,int param_2,int param_3,LPCSTR param_4)

{
  longlong lVar1;
  int iVar2;
  BOOL BVar3;
  int iVar4;
  AFX_MODULE_STATE *pAVar5;
  char *pcVar6;
  IAtlStringMgr *pIVar7;
  BSTR lpWideCharStr;
  longlong lVar9;
  longlong lVar8;
  undefined1 auStackY_248 [32];
  char *local_1f8;
  char *local_1f0;
  AFX_MAINTAIN_STATE2 local_1e8 [16];
  _STARTUPINFOA local_1d8;
  _PROCESS_INFORMATION local_168;
  CHAR local_148 [272];
  ulonglong local_38;
  
  local_38 = DAT_1800516d8 ^ (ulonglong)auStackY_248;
  pAVar5 = AfxGetModuleState();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_1e8,pAVar5);
  iVar2 = MMGetSuppress();
  if (iVar2 != 0) {
    MMAfxMessageBox("Unable to display interactive editor when dialogs are suppressed. Continuing.",
                    0,-1,0);
    BVar3 = 0;
    goto LAB_180009c87;
  }
  pcVar6 = (char *)SEGetSettingValue("editor");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1f8,pcVar6);
  lpWideCharStr = (BSTR)0x0;
  if (*(int *)(local_1f8 + -0x10) == 0) {
LAB_180009c78:
    BVar3 = 0;
  }
  else {
    if ((param_2 == 0) || (iVar2 = GetEditorTempTxtFileName(local_148), iVar2 == 0)) {
      strncpy(local_148,param_1,0x103);
    }
    else {
      BVar3 = CopyFileA(param_1,local_148,0);
      if (BVar3 == 0) goto LAB_180009c78;
    }
    local_1d8.cb = 0x68;
    local_1d8.hStdError._4_4_ = 0;
    local_1d8._4_8_ = 0;
    local_1d8._12_8_ = 0;
    local_1d8._20_8_ = 0;
    local_1d8._28_8_ = 0;
    local_1d8.dwY = 0;
    local_1d8.dwXSize = 0;
    local_1d8.dwYSize = 0;
    local_1d8.dwXCountChars = 0;
    local_1d8.dwYCountChars = 0;
    local_1d8.dwFillAttribute = 0;
    local_1d8.dwFlags = 0;
    local_1d8.wShowWindow = 0;
    local_1d8.cbReserved2 = 0;
    local_1d8._68_8_ = 0;
    local_1d8._76_8_ = 0;
    local_1d8._84_8_ = 0;
    local_1d8._92_8_ = 0;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1f8," ");
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1f8,local_148
              );
    pcVar6 = ATL::CSimpleStringT<char,1>::GetBuffer
                       ((CSimpleStringT<char,1> *)&local_1f8,*(int *)(local_1f8 + -0x10));
    BVar3 = CreateProcessA((LPCSTR)0x0,pcVar6,(LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0,
                           0,0,(LPVOID)0x0,(LPCSTR)0x0,&local_1d8,&local_168);
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_1f8,-1);
    if (BVar3 == 0) {
      pIVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          &local_1f8);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1f0,pIVar7)
      ;
      lVar9 = -1;
      do {
        lVar8 = lVar9 + 1;
        lVar1 = lVar9 + 1;
        lVar9 = lVar8;
      } while ("Could not create process:  "[lVar1] != '\0');
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)&local_1f0,"Could not create process:  ",(int)lVar8,
                 local_1f8,*(int *)(local_1f8 + -0x10));
      MMAfxMessageBox(local_1f0,0x30,-1,0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1f0);
      goto LAB_180009c78;
    }
    if (param_3 != 0) {
      if (param_4 != (LPCSTR)0x0) {
        iVar2 = MultiByteToWideChar(0,0,param_4,-1,(LPWSTR)0x0,0);
        lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,iVar2 - 1);
        if ((lpWideCharStr != (BSTR)0x0) &&
           (iVar4 = MultiByteToWideChar(0,0,param_4,-1,lpWideCharStr,iVar2), iVar4 != iVar2)) {
          SysFreeString(lpWideCharStr);
LAB_180009e6d:
                    /* WARNING: Subroutine does not return */
          FUN_180001380(-0x7ff8fff2);
        }
        if (lpWideCharStr == (BSTR)0x0) goto LAB_180009e6d;
      }
      FUN_180009740(local_168.hProcess._0_4_,lpWideCharStr);
      SysFreeString(lpWideCharStr);
      BVar3 = 1;
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1f8);
LAB_180009c87:
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_1e8);
  return BVar3;
}

/* RVA 0x9e80 */
/* protected: static struct CRuntimeClass * __ptr64 __cdecl CSimEventsThread::_GetBaseClass(void) */

CRuntimeClass * __cdecl CSimEventsThread::_GetBaseClass(void)

{
  CRuntimeClass *pCVar1;
  
                    /* 0x9e80  50  ?_GetBaseClass@CSimEventsThread@@KAPEAUCRuntimeClass@@XZ */
                    /* WARNING: Could not recover jumptable at 0x00018003b488. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = CWinThread::GetThisClass();
  return pCVar1;
}

/* RVA 0x9e90 */
/* public: static class CObject * __ptr64 __cdecl CSimEventsThread::CreateObject(void) */

CObject * __cdecl CSimEventsThread::CreateObject(void)

{
  CSimEventsThread *this;
  CObject *pCVar1;
  
                    /* 0x9e90  22  ?CreateObject@CSimEventsThread@@SAPEAVCObject@@XZ */
  this = operator_new(0x88);
  if (this == (CSimEventsThread *)0x0) {
    return (CObject *)0x0;
  }
  pCVar1 = (CObject *)CSimEventsThread(this);
  return pCVar1;
}

/* RVA 0x9ec0 */
/* public: __cdecl CSimEventsThread::CSimEventsThread(void) __ptr64 */

CSimEventsThread * __thiscall CSimEventsThread::CSimEventsThread(CSimEventsThread *this)

{
                    /* 0x9ec0  11  ??0CSimEventsThread@@QEAA@XZ */
  CWinThread::CWinThread((CWinThread *)this);
  *(undefined ***)this = _vftable_;
  m_hSync = (void *)0x0;
  return this;
}

/* RVA 0x9ef0 */
/* public: virtual __cdecl CSimEventsThread::~CSimEventsThread(void) __ptr64 */

void __thiscall CSimEventsThread::~CSimEventsThread(CSimEventsThread *this)

{
                    /* 0x9ef0  14  ??1CSimEventsThread@@UEAA@XZ */
  CWinThread::~CWinThread((CWinThread *)this);
  return;
}

