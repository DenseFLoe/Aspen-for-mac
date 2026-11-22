/* ---- FUNC 0004328A FUN_18004328a (56 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_18004328a(void)

{
  undefined4 uVar1;
  longlong *unaff_R12;
  longlong *unaff_R15;
  
  (**(code **)(*unaff_R12 + 0x28))();
  uVar1 = (**(code **)(*unaff_R12 + 0x38))();
  (**(code **)(*unaff_R12 + 0x28))();
  (**(code **)(*unaff_R15 + 0x28))();
  return uVar1;
}

/* ---- FUNC 000432C2 FUN_1800432c2 (37 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1800432c2(void)

{
  return 0x80004003;
}

/* ---- FUNC 000432F0 ZStgOpenStorage (590 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong ZStgOpenStorage(longlong *param_1,wchar_t *param_2,uint param_3,longlong param_4)

{
  undefined2 *puVar1;
  code *pcVar2;
  _func_5369 *p_Var3;
  _func_5439 *p_Var4;
  LPSTREAM pIVar5;
  LPLOCKBYTES pIVar6;
  longlong *plVar7;
  uint uVar8;
  longlong lVar9;
  HGLOBAL hGlobal;
  ulonglong uVar11;
  ulonglong uVar12;
  int iVar13;
  undefined2 *puVar14;
  undefined1 *puVar15;
  undefined2 *puVar16;
  undefined8 uStack_90;
  undefined1 auStack_88 [32];
  undefined8 local_68;
  int local_60 [2];
  longlong local_58;
  LPSTREAM local_48;
  LPLOCKBYTES local_40;
  longlong *local_38;
  LPCSTR local_30;
  ulonglong local_28;
  longlong lVar10;
  
                    /* 0x432f0  546  ZStgOpenStorage */
  puVar15 = auStack_88;
  local_28 = DAT_1800791f8 ^ (ulonglong)&local_48;
  if ((param_1 == (longlong *)0x0) || (param_4 == 0)) {
    uVar12 = 0x80004003;
    puVar15 = auStack_88;
    goto LAB_180043518;
  }
  puVar16 = (undefined2 *)0x0;
  local_60[0] = 0;
  local_68 = 0;
  uStack_90 = 0x180043359;
  local_58 = param_4;
  uVar8 = (**(code **)(*param_1 + 0x30))(param_1,param_2,0,param_3);
  if (uVar8 == 0x80030001) {
    param_3 = param_3 & 0xffffff9f | 0x10;
    local_60[0] = 0;
    local_68 = 0;
    uStack_90 = 0x180043389;
    local_58 = param_4;
    uVar8 = (**(code **)(*param_1 + 0x30))(param_1,param_2,0,param_3);
  }
  uVar12 = (ulonglong)uVar8;
  if (uVar8 == 0) goto LAB_180043518;
  uStack_90 = 0x1800433a0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_30,param_2);
  uStack_90 = 0x1800433b1;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_30,".ZStg");
  local_38 = (longlong *)0x0;
  puVar14 = puVar16;
  puVar15 = auStack_88;
  if (local_30 != (LPCSTR)0x0) {
    lVar9 = -1;
    do {
      lVar10 = lVar9;
      lVar9 = lVar10 + 1;
    } while (local_30[lVar9] != '\0');
    iVar13 = (int)lVar10 + 2;
    puVar15 = auStack_88;
    if (iVar13 < 0x40000000) {
      lVar9 = (longlong)(int)lVar9 * 2;
      uVar12 = lVar9 + 0x11;
      if (uVar12 <= lVar9 + 2U) {
        uVar12 = 0xffffffffffffff0;
      }
      uStack_90 = 0x18004340d;
      lVar9 = -(uVar12 & 0xfffffffffffffff0);
      puVar1 = (undefined2 *)((longlong)&local_48 + lVar9);
      puVar15 = auStack_88 + lVar9;
      if (puVar1 != (undefined2 *)0x0) {
        *(int *)((longlong)local_60 + lVar9) = iVar13;
        *puVar1 = 0;
        *(undefined2 **)((longlong)local_60 + lVar9 + -8) = puVar1;
        *(undefined8 *)(auStack_88 + lVar9 + -8) = 0x180043435;
        iVar13 = MultiByteToWideChar(0,0,local_30,-1,*(LPWSTR *)((longlong)local_60 + lVar9 + -8),
                                     *(int *)((longlong)local_60 + lVar9));
        puVar14 = puVar1;
        puVar15 = auStack_88 + lVar9;
        if (iVar13 == 0) {
          puVar14 = puVar16;
          puVar15 = auStack_88 + lVar9;
        }
      }
    }
  }
  lVar9 = *param_1;
  *(longlong ***)(puVar15 + 0x28) = &local_38;
  *(undefined4 *)(puVar15 + 0x20) = 0;
  pcVar2 = *(code **)(lVar9 + 0x20);
  *(undefined8 *)(puVar15 + -8) = 0x180043460;
  uVar8 = (*pcVar2)(param_1,puVar14,0);
  uVar12 = (ulonglong)uVar8;
  if (uVar8 == 0) {
    local_48 = (IStream *)0x0;
    *(undefined8 *)(puVar15 + -8) = 0x180043479;
    hGlobal = GlobalAlloc(0x42,0);
    *(undefined8 *)(puVar15 + -8) = 0x18004348b;
    uVar8 = CreateStreamOnHGlobal(hGlobal,0,&local_48);
    plVar7 = local_38;
    pIVar5 = local_48;
    uVar12 = (ulonglong)uVar8;
    if (uVar8 == 0) {
      *(undefined8 *)(puVar15 + -8) = 0x18004349e;
      uVar11 = ZStgDecompressStream(plVar7,(longlong *)pIVar5);
      pIVar5 = local_48;
      uVar12 = uVar11 & 0xffffffff;
      p_Var3 = local_48->lpVtbl->Release;
      *(undefined8 *)(puVar15 + -8) = 0x1800434aa;
      (*p_Var3)(pIVar5);
      if ((int)uVar11 != 0) goto LAB_1800434f2;
      local_40 = (ILockBytes *)0x0;
      *(undefined8 *)(puVar15 + -8) = 0x1800434c2;
      uVar8 = CreateILockBytesOnHGlobal(hGlobal,1,&local_40);
      pIVar6 = local_40;
      uVar12 = (ulonglong)uVar8;
      if (uVar8 != 0) goto LAB_1800434f2;
      *(longlong *)(puVar15 + 0x28) = param_4;
      *(undefined4 *)(puVar15 + 0x20) = 0;
      *(undefined8 *)(puVar15 + -8) = 0x1800434e4;
      uVar8 = StgOpenStorageOnILockBytes
                        (pIVar6,(IStorage *)0x0,param_3 & 0xffffff9f | 0x10,(SNB)0x0,
                         *(DWORD *)(puVar15 + 0x20),*(IStorage ***)(puVar15 + 0x28));
      pIVar6 = local_40;
      uVar12 = (ulonglong)uVar8;
      p_Var4 = local_40->lpVtbl->Release;
      *(undefined8 *)(puVar15 + -8) = 0x1800434f0;
      (*p_Var4)(pIVar6);
    }
    else {
LAB_1800434f2:
      *(undefined8 *)(puVar15 + -8) = 0x1800434fb;
      GlobalFree(hGlobal);
    }
    pcVar2 = *(code **)(*local_38 + 0x10);
    *(undefined8 *)(puVar15 + -8) = 0x180043505;
    (*pcVar2)();
  }
  *(undefined8 *)(puVar15 + -8) = 0x18004350f;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_30);
LAB_180043518:
  *(undefined8 *)(puVar15 + -8) = 0x180043524;
  return uVar12;
}

/* ---- FUNC 00043540 ZStgOpenStream (565 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong ZStgOpenStream(longlong *param_1,wchar_t *param_2,undefined4 param_3,
                        LARGE_INTEGER *param_4)

{
  char *pcVar1;
  code *pcVar2;
  _func_5370 *p_Var3;
  _func_5372 *p_Var4;
  _func_5369 *p_Var5;
  LARGE_INTEGER LVar6;
  LARGE_INTEGER dlibMove;
  LARGE_INTEGER LVar7;
  uint uVar8;
  longlong lVar9;
  ulonglong uVar11;
  ulonglong uVar12;
  int iVar13;
  char *pcVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  char *pcVar17;
  undefined8 uStack_90;
  undefined1 auStack_88 [32];
  undefined4 local_68 [2];
  LARGE_INTEGER *local_60;
  char local_58 [8];
  LARGE_INTEGER local_50;
  LARGE_INTEGER local_48;
  ULONG local_40 [2];
  ULARGE_INTEGER local_38;
  LPCSTR local_30;
  ulonglong local_28;
  longlong lVar10;
  
                    /* 0x43540  547  ZStgOpenStream */
  puVar16 = auStack_88;
  puVar15 = auStack_88;
  local_28 = DAT_1800791f8 ^ (ulonglong)local_58;
  if ((param_1 == (longlong *)0x0) || (param_4 == (LARGE_INTEGER *)0x0)) {
    uVar12 = 0x80004003;
    goto LAB_18004374f;
  }
  pcVar17 = (char *)0x0;
  local_60 = &local_50;
  local_48.QuadPart = 0;
  local_38.QuadPart = 0;
  local_50.QuadPart = 0;
  local_68[0] = 0;
  uStack_90 = 0x1800435b7;
  uVar8 = (**(code **)(*param_1 + 0x20))(param_1,param_2,0,param_3);
  uVar12 = (ulonglong)uVar8;
  if (uVar8 != 0) {
    uStack_90 = 0x1800435ce;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_30,param_2);
    uStack_90 = 0x1800435df;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_30,".ZStm");
    pcVar14 = pcVar17;
    puVar15 = auStack_88;
    if (local_30 != (LPCSTR)0x0) {
      lVar9 = -1;
      do {
        lVar10 = lVar9;
        lVar9 = lVar10 + 1;
      } while (local_30[lVar9] != '\0');
      iVar13 = (int)lVar10 + 2;
      puVar15 = auStack_88;
      if (iVar13 < 0x40000000) {
        lVar9 = (longlong)(int)lVar9 * 2;
        uVar12 = lVar9 + 0x11;
        if (uVar12 <= lVar9 + 2U) {
          uVar12 = 0xffffffffffffff0;
        }
        uStack_90 = 0x18004362d;
        lVar9 = -(uVar12 & 0xfffffffffffffff0);
        pcVar1 = local_58 + lVar9;
        puVar15 = auStack_88 + lVar9;
        if (pcVar1 != (char *)0x0) {
          *(int *)((longlong)&local_60 + lVar9) = iVar13;
          pcVar1[0] = '\0';
          pcVar1[1] = '\0';
          *(char **)((longlong)local_68 + lVar9) = pcVar1;
          *(undefined8 *)(auStack_88 + lVar9 + -8) = 0x180043655;
          iVar13 = MultiByteToWideChar(0,0,local_30,-1,*(LPWSTR *)((longlong)local_68 + lVar9),
                                       *(int *)((longlong)&local_60 + lVar9));
          pcVar14 = pcVar1;
          puVar15 = auStack_88 + lVar9;
          if (iVar13 == 0) {
            pcVar14 = pcVar17;
            puVar15 = auStack_88 + lVar9;
          }
        }
      }
    }
    lVar9 = *param_1;
    *(LARGE_INTEGER **)(puVar15 + 0x28) = &local_50;
    *(undefined4 *)(puVar15 + 0x20) = 0;
    pcVar2 = *(code **)(lVar9 + 0x20);
    *(undefined8 *)(puVar15 + -8) = 0x180043680;
    uVar8 = (*pcVar2)(param_1,pcVar14,0,param_3);
    LVar6 = local_50;
    uVar12 = (ulonglong)uVar8;
    if (uVar8 == 0) {
      p_Var3 = (*(IStreamVtbl **)local_50)->Read;
      *(undefined8 *)(puVar15 + -8) = 0x1800436a0;
      uVar8 = (*p_Var3)((IStream *)LVar6,local_58,2,local_40);
      dlibMove = local_48;
      LVar6 = local_50;
      uVar12 = (ulonglong)uVar8;
      if ((((-1 < (int)uVar8) && (local_40[0] == 2)) && (local_58[0] == '\x1f')) &&
         (local_58[1] == -0x75)) {
        p_Var4 = (*(IStreamVtbl **)local_50)->Seek;
        *(undefined8 *)(puVar15 + -8) = 0x1800436d0;
        (*p_Var4)((IStream *)LVar6,dlibMove,0,&local_38);
        local_48.QuadPart = 0;
        *(undefined8 *)(puVar15 + -8) = 0x1800436e5;
        uVar8 = CreateStreamOnHGlobal((HGLOBAL)0x0,1,(LPSTREAM *)&local_48);
        LVar7 = local_48;
        LVar6 = local_50;
        uVar12 = (ulonglong)uVar8;
        if (uVar8 == 0) {
          *(undefined8 *)(puVar15 + -8) = 0x1800436f8;
          uVar11 = ZStgDecompressStream((longlong *)LVar6,(longlong *)LVar7);
          LVar6 = local_50;
          uVar12 = uVar11 & 0xffffffff;
          if ((int)uVar11 == 0) {
            p_Var5 = (*(IStreamVtbl **)local_50)->Release;
            *(undefined8 *)(puVar15 + -8) = 0x180043708;
            (*p_Var5)((IStream *)LVar6);
            local_50.s = local_48.s;
            goto LAB_180043735;
          }
        }
        LVar6 = local_48;
        if (local_48.QuadPart != 0) {
          pcVar2 = *(code **)(*(longlong *)local_48 + 0x10);
          *(undefined8 *)(puVar15 + -8) = 0x180043721;
          (*pcVar2)((IStream *)LVar6);
        }
      }
      LVar6 = local_50;
      p_Var4 = (*(IStreamVtbl **)local_50)->Seek;
      *(undefined8 *)(puVar15 + -8) = 0x180043735;
      (*p_Var4)((IStream *)LVar6,dlibMove,0,&local_38);
    }
LAB_180043735:
    *(undefined8 *)(puVar15 + -8) = 0x18004373f;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_30);
  }
  param_4->QuadPart = (LONGLONG)local_50;
  puVar16 = puVar15;
LAB_18004374f:
  *(undefined8 *)(puVar16 + -8) = 0x18004375b;
  return uVar12;
}

/* ---- FUNC 00043780 MMDriveDialog (105 bytes) ---- */

INT_PTR MMDriveDialog(undefined8 param_1)

{
  INT_PTR IVar1;
  
                    /* 0x43780  384  MMDriveDialog */
  if (DAT_18009b848 == (FARPROC)0x0) {
    if ((DAT_18009b840 == (HMODULE)0x0) &&
       (DAT_18009b840 = LoadLibraryA("mmdialog.dll"), DAT_18009b840 == (HMODULE)0x0)) {
      return 0;
    }
    DAT_18009b848 = GetProcAddress(DAT_18009b840,"gxDriveDialog");
    if (DAT_18009b848 == (FARPROC)0x0) {
      return 0;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x0001800437e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar1 = (*DAT_18009b848)(param_1);
  return IVar1;
}

/* ---- FUNC 000437F0 MMDriveDialog2 (638 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

INT_PTR MMDriveDialog2(undefined8 param_1,uint param_2,undefined8 param_3,undefined8 param_4)

{
  uint *puVar1;
  INT_PTR IVar2;
  longlong lVar3;
  uint *puVar4;
  uint uVar5;
  uint local_res10 [2];
  undefined8 local_res18 [2];
  undefined1 auStack_b8 [32];
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68 [4];
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  ulonglong local_28;
  
                    /* 0x437f0  385  MMDriveDialog2 */
  local_res18[0] = param_3;
  local_res18[1] = param_4;
  local_28 = DAT_1800791f8 ^ (ulonglong)auStack_b8;
  local_res10[0] = param_2;
  if ((DAT_18009b850 == (FARPROC)0x0) &&
     (((DAT_18009b840 == (HMODULE)0x0 &&
       (DAT_18009b840 = LoadLibraryA("mmdialog.dll"), DAT_18009b840 == (HMODULE)0x0)) ||
      (DAT_18009b850 = GetProcAddress(DAT_18009b840,"gxDriveDialog2"), DAT_18009b850 == (FARPROC)0x0
      )))) {
LAB_180043a56:
    IVar2 = 0;
  }
  else {
    uVar5 = local_res10[0];
    if (0 < (int)local_res10[0]) {
      if (8 < (int)local_res10[0]) {
        uVar5 = 8;
      }
      if (0 < (int)uVar5) {
        lVar3 = 0;
        puVar4 = local_res10;
        do {
          puVar1 = puVar4 + 2;
          puVar4 = puVar4 + 2;
          local_68[lVar3] = *(undefined8 *)puVar1;
          lVar3 = lVar3 + 1;
        } while (lVar3 < (int)uVar5);
      }
    }
    switch(uVar5) {
    case 0:
      IVar2 = (*DAT_18009b850)(param_1,(ulonglong)local_res10[0]);
      break;
    case 1:
      IVar2 = (*DAT_18009b850)(param_1,(ulonglong)local_res10[0],local_68[0]);
      break;
    case 2:
      IVar2 = (*DAT_18009b850)(param_1,(ulonglong)local_res10[0],local_68[0],local_68[1]);
      break;
    case 3:
      local_98 = local_68[2];
      IVar2 = (*DAT_18009b850)(param_1,(ulonglong)local_res10[0],local_68[0],local_68[1]);
      break;
    case 4:
      local_90 = local_68[3];
      local_98 = local_68[2];
      IVar2 = (*DAT_18009b850)(param_1,(ulonglong)local_res10[0],local_68[0],local_68[1]);
      break;
    case 5:
      local_88 = local_48;
      local_90 = local_68[3];
      local_98 = local_68[2];
      IVar2 = (*DAT_18009b850)(param_1,(ulonglong)local_res10[0],local_68[0],local_68[1]);
      break;
    case 6:
      local_80 = local_40;
      local_88 = local_48;
      local_90 = local_68[3];
      local_98 = local_68[2];
      IVar2 = (*DAT_18009b850)(param_1,(ulonglong)local_res10[0],local_68[0],local_68[1]);
      break;
    case 7:
      local_78 = local_38;
      local_80 = local_40;
      local_88 = local_48;
      local_90 = local_68[3];
      local_98 = local_68[2];
      IVar2 = (*DAT_18009b850)(param_1,(ulonglong)local_res10[0],local_68[0],local_68[1]);
      break;
    case 8:
      local_70 = local_30;
      local_78 = local_38;
      local_80 = local_40;
      local_88 = local_48;
      local_90 = local_68[3];
      local_98 = local_68[2];
      IVar2 = (*DAT_18009b850)(param_1,(ulonglong)local_res10[0],local_68[0],local_68[1]);
      break;
    default:
      goto LAB_180043a56;
    }
  }
  return IVar2;
}

/* ---- FUNC 00043AA0 MMDriveDialogRelease (43 bytes) ---- */

void MMDriveDialogRelease(void)

{
                    /* 0x43aa0  386  MMDriveDialogRelease */
  if (DAT_18009b840 != (HMODULE)0x0) {
    FreeLibrary(DAT_18009b840);
  }
  DAT_18009b850 = 0;
  DAT_18009b848 = 0;
  return;
}

/* ---- FUNC 00043AD0 CheckInTrackingKeys (246 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CheckInTrackingKeys(void)

{
  int iVar1;
  longlong lVar2;
  int *piVar3;
  int iVar4;
  undefined1 auStack_58 [32];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_38 [8];
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
                    /* 0x43ad0  71  CheckInTrackingKeys */
  local_10 = DAT_1800791f8 ^ (ulonglong)auStack_58;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_38);
  uStack_28 = 0;
  local_20 = _DAT_180053820;
  uStack_18 = _UNK_180053828;
  local_30 = 0;
  if (DAT_18009b860 != 0) {
    if (DAT_18009b8b8 != 0) {
      iVar4 = 0;
      if (0 < DAT_18009b8b8) {
        piVar3 = &DAT_18009b8c0;
        lVar2 = DAT_18009b860;
        iVar1 = DAT_18009b8b8;
        do {
          if (*piVar3 != 0) {
            FUN_180045de0(lVar2);
            *piVar3 = 0;
            lVar2 = DAT_18009b860;
            iVar1 = DAT_18009b8b8;
          }
          iVar4 = iVar4 + 1;
          piVar3 = piVar3 + 1;
        } while (iVar4 < iVar1);
      }
      DAT_18009ba68 = 0;
      DAT_18009ba6c = 0;
      DAT_18009ba70 = 0;
      DAT_18009ba74 = 0;
      DAT_18009b8b8 = 0;
      _DAT_18009baa0 = 0;
      _DAT_18009baa8 = 0;
      _DAT_18009bab0 = 0;
      _DAT_18009bab8 = 0;
      DAT_18009bac0 = 0;
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_38);
  return;
}

/* ---- FUNC 00043BD0 FUN_180043bd0 (462 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_180043bd0(void *param_1)

{
  int iVar1;
  char cVar2;
  void *pvVar3;
  char *pcVar4;
  size_t sVar5;
  undefined1 auStack_88 [32];
  int local_68 [2];
  LPCSTR local_60;
  void *local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong uStack_40;
  void *local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong uStack_20;
  ulonglong local_18;
  
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_88;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_60);
  local_68[0] = 0;
  uStack_50 = 0;
  local_48 = _DAT_180053820;
  uStack_40 = _UNK_180053828;
  local_58 = (void *)0x0;
  if (DAT_18009b860 == 0) {
    pcVar4 = "Set Tracking Key %s failed. SLM not initialized";
  }
  else {
    local_38 = (void *)0x0;
    uStack_30 = 0;
    local_28 = 0;
    uStack_20 = 0;
    sVar5 = 0xffffffffffffffff;
    do {
      sVar5 = sVar5 + 1;
    } while (*(char *)((longlong)param_1 + sVar5) != '\0');
    FUN_18000b5f0(&local_38,param_1,sVar5);
    cVar2 = FUN_180045e20(DAT_18009b860,(LPCSTR)&local_38,local_68,(longlong *)&local_58);
    if (0xf < uStack_20) {
      pvVar3 = local_38;
      if ((0xfff < uStack_20 + 1) &&
         (pvVar3 = *(void **)((longlong)local_38 + -8),
         0x1f < (ulonglong)((longlong)local_38 + (-8 - (longlong)pvVar3)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      operator_delete(pvVar3);
    }
    if (cVar2 != '\0') {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_60,
                 "Set Tracking Key %s Successful",param_1);
      OutputDebugStringA(local_60);
      (&DAT_18009b8c0)[DAT_18009b8b8] = local_68[0];
      DAT_18009b8b8 = DAT_18009b8b8 + 1;
      goto LAB_180043d22;
    }
    pcVar4 = "Set Tracking Key %s failed";
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_60,pcVar4,
             param_1);
  OutputDebugStringA(local_60);
LAB_180043d22:
  iVar1 = local_68[0];
  if (0xf < uStack_40) {
    pvVar3 = local_58;
    if ((0xfff < uStack_40 + 1) &&
       (pvVar3 = *(void **)((longlong)local_58 + -8),
       0x1f < (ulonglong)((longlong)local_58 + (-8 - (longlong)pvVar3)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar3);
  }
  local_48 = _DAT_180053820;
  uStack_40 = _UNK_180053828;
  local_58 = (void *)((ulonglong)local_58 & 0xffffffffffffff00);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_60);
  return iVar1;
}

/* ---- FUNC 00043DA0 FUN_180043da0 (101 bytes) ---- */

undefined8 FUN_180043da0(undefined8 param_1)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  
  uVar1 = MMGetSuppress();
  if (uVar1 == 0) {
    if (DAT_18009b8a0 != (code *)0x0) {
      (*DAT_18009b8a0)();
    }
    if (DAT_18009b8a8 != (code *)0x0) {
      uVar2 = FUN_1800240b0();
      if ((int)uVar2 == 1) {
                    /* WARNING: Could not recover jumptable at 0x000180043de3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar3 = (*DAT_18009b8a8)(param_1,"AEA_AspenPlus");
        return uVar3;
      }
                    /* WARNING: Could not recover jumptable at 0x000180043df6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (*DAT_18009b8a8)(param_1,"AEA_AspenProperties");
      return uVar3;
    }
  }
  return 0;
}

/* ---- FUNC 00043E10 FUN_180043e10 (789 bytes) ---- */

int FUN_180043e10(int param_1)

{
  int iVar1;
  ulonglong uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar3 = 0;
  iVar1 = param_1 % 0x20d38;
  if (0 < iVar1 + (1 - iVar1 / 10) * 10) {
    do {
      iVar3 = iVar3 + 1;
      iVar1 = (iVar1 * 0x1fb9 + 0x6efb) % 0x20d38;
    } while (iVar3 < iVar1 + (1 - iVar1 / 10) * 10);
  }
  iVar3 = (iVar1 * 0x1fb9 + 0x6efb) % 0x20d38;
  iVar6 = (iVar3 * 0x1fb9 + 0x6efb) % 0x20d38;
  iVar4 = (iVar6 * 0x1fb9 + 0x6efb) % 0x20d38;
  iVar1 = (iVar4 * 0x1fb9 + 0x6efb) % 0x20d38;
  uVar5 = ((iVar3 * 0x11d1 + 0x6efb) % 0x3b538) % 10;
  if (0 < (int)uVar5) {
    uVar2 = (ulonglong)uVar5;
    do {
      iVar1 = (iVar1 * 0x11d1 + 0x6efb) % 0x3b538;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  uVar5 = ((iVar4 * 0xe4d + 0x7859) % 0x23988) % 10;
  if (0 < (int)uVar5) {
    uVar2 = (ulonglong)uVar5;
    do {
      iVar1 = (iVar1 * 0xe4d + 0x7859) % 0x23988;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  uVar5 = ((iVar6 * 0x11d1 + 0x6efb) % 0x3b538) % 10;
  if (0 < (int)uVar5) {
    uVar2 = (ulonglong)uVar5;
    do {
      iVar4 = (iVar4 * 0xe4d + 0x7859) % 0x23988;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  if (0 < iVar1 % 10) {
    uVar2 = (ulonglong)(uint)(iVar1 % 10);
    do {
      iVar4 = (iVar4 * 0x11d1 + 0x6efb) % 0x3b538;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return iVar4 + 10;
}

/* ---- FUNC 00044130 FUN_180044130 (35 bytes) ---- */

void FUN_180044130(longlong param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = &DAT_18009ba78;
  do {
    cVar1 = *pcVar2;
    pcVar2[param_1 + -0x18009ba78] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  *(undefined1 *)(param_1 + 0x20) = 0;
  return;
}

/* ---- FUNC 00044160 FUN_180044160 (44 bytes) ---- */

void FUN_180044160(void)

{
  __time64_t _Var1;
  
  _Var1 = _time64((__time64_t *)0x0);
  srand((uint)_Var1);
  rand();
  rand();
                    /* WARNING: Could not recover jumptable at 0x000180044185. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  rand();
  return;
}

/* ---- FUNC 00044190 FUN_180044190 (97 bytes) ---- */

void FUN_180044190(void)

{
  longlong *plVar1;
  HMODULE hModule;
  FARPROC pFVar2;
  undefined8 local_30 [6];
  
  if (DAT_18009b894 != 0) {
    MMReleaseWaitStruct();
    if (DAT_18009b893 != '\0') {
      plVar1 = FUN_180038cd0(local_30,"+!RV/*");
      hModule = FUN_18000da20(plVar1);
      if (hModule != (HMODULE)0x0) {
        pFVar2 = GetProcAddress(hModule,"SimExit");
        if (pFVar2 != (FARPROC)0x0) {
          (*pFVar2)();
        }
      }
    }
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  return;
}

/* ---- FUNC 00044200 MMAddWaitItem (531 bytes) ---- */

undefined4 MMAddWaitItem(int param_1)

{
  int in_EAX;
  
                    /* 0x44200  129  MMAddWaitItem */
  if (param_1 == 0) {
    if (DAT_18009baa0 == 0) {
      in_EAX = FUN_180043bd0("SLM_TR_PML_PLS_ColAnlyz");
      DAT_18009baa0 = in_EAX;
      if (in_EAX == 0) {
        DAT_18009baa0 = 0xffffffff;
        return 1;
      }
    }
  }
  else if (param_1 == 1) {
    if (DAT_18009baa4 == 0) {
      in_EAX = FUN_180043bd0("SLM_TR_PML_PLS_PSVPLUS");
      DAT_18009baa4 = in_EAX;
      if (in_EAX == 0) {
        DAT_18009baa4 = 0xffffffff;
        return 1;
      }
    }
  }
  else if (param_1 == 2) {
    if (DAT_18009baa8 == 0) {
      in_EAX = FUN_180043bd0("SLM_TR_PML_PLS_EDR_IST");
      DAT_18009baa8 = in_EAX;
      if (in_EAX == 0) {
        DAT_18009baa8 = 0xffffffff;
        return 1;
      }
    }
  }
  else if (param_1 == 3) {
    if (DAT_18009baac == 0) {
      in_EAX = FUN_180043bd0("SLM_TR_PML_PLS_EDR_IAC");
      DAT_18009baac = in_EAX;
      if (in_EAX == 0) {
        DAT_18009baac = 0xffffffff;
        return 1;
      }
    }
  }
  else if (param_1 == 4) {
    if (DAT_18009bab0 == 0) {
      in_EAX = FUN_180043bd0("SLM_TR_PML_PLS_EDR_IPL");
      DAT_18009bab0 = in_EAX;
      if (in_EAX == 0) {
        DAT_18009bab0 = 0xffffffff;
        return 1;
      }
    }
  }
  else if (param_1 == 5) {
    if (DAT_18009bab4 == 0) {
      in_EAX = FUN_180043bd0("SLM_TR_PML_PLS_EDR_AEDR");
      DAT_18009bab4 = in_EAX;
      if (in_EAX == 0) {
        DAT_18009bab4 = 0xffffffff;
        return 1;
      }
    }
  }
  else if (param_1 == 6) {
    if (DAT_18009bab8 == 0) {
      in_EAX = FUN_180043bd0("SLM_TR_PML_ACM_APLUS");
      DAT_18009bab8 = in_EAX;
      if (in_EAX == 0) {
        DAT_18009bab8 = 0xffffffff;
        return 1;
      }
    }
  }
  else if (param_1 == 7) {
    if (DAT_18009babc == 0) {
      in_EAX = FUN_180043bd0("SLM_TR_PML_ACME_APLUS");
      DAT_18009babc = in_EAX;
      if (in_EAX == 0) {
        DAT_18009babc = 0xffffffff;
        return 1;
      }
    }
  }
  else if ((param_1 == 8) && (DAT_18009bac0 == 0)) {
    in_EAX = FUN_180043bd0("SLM_TR_PML_FERMENTATION");
    DAT_18009bac0 = in_EAX;
    if (in_EAX == 0) {
      DAT_18009bac0 = -1;
    }
  }
  return CONCAT31((int3)((uint)in_EAX >> 8),1);
}

/* ---- FUNC 00044420 MMCAInitCBFuncsA (20 bytes) ---- */

void MMCAInitCBFuncsA(longlong param_1,undefined8 param_2)

{
                    /* 0x44420  132  MMCAInitCBFuncsA */
  if (param_1 != 0) {
    DAT_18009ba50 = param_1;
    DAT_18009ba58 = param_2;
  }
  return;
}

/* ---- FUNC 00044440 MMCheckWaitStruct (24 bytes) ---- */

undefined1 MMCheckWaitStruct(void)

{
  undefined1 uVar1;
  
                    /* 0x44440  133  MMCheckWaitStruct */
  if (DAT_18009b894 != 0) {
    return 1;
  }
  uVar1 = MMWaitForDocument((undefined *)0x0,0,0);
  return uVar1;
}

/* ---- FUNC 00044460 MMHHelpInitFuncA (13 bytes) ---- */

void MMHHelpInitFuncA(longlong param_1)

{
                    /* 0x44460  140  MMHHelpInitFuncA */
  if (param_1 != 0) {
    DAT_18009ba60 = param_1;
  }
  return;
}

/* ---- FUNC 00044470 MMHasDupInfo (42 bytes) ---- */

void MMHasDupInfo(void)

{
                    /* 0x44470  141  MMHasDupInfo */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_18009b868);
  DAT_18009b891 = 1;
                    /* WARNING: Could not recover jumptable at 0x000180044493. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_18009b868);
  return;
}

/* ---- FUNC 000444A0 MMInitWaitStruct (124 bytes) ---- */

void MMInitWaitStruct(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
                    /* 0x444a0  142  MMInitWaitStruct */
  if (DAT_18009b890 == '\0') {
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_18009b868);
    DAT_18009b8bc = GetCurrentThreadId();
    puVar1 = operator_new(0x20);
    puVar2 = (undefined8 *)0x0;
    if (puVar1 != (undefined8 *)0x0) {
      puVar2 = FUN_180045a60(puVar1);
    }
    DAT_18009b860 = puVar2;
    FUN_1800460a0((longlong)puVar2);
    DAT_18009b890 = '\x01';
    DAT_18009b8b0 = SetTimer((HWND)0x0,0,30000,FUN_180045070);
  }
  return;
}

/* ---- FUNC 00044520 MMReleaseWaitStruct (195 bytes) ---- */

void MMReleaseWaitStruct(void)

{
                    /* 0x44520  143  MMReleaseWaitStruct */
  if (DAT_18009b8b0 != 0) {
    KillTimer((HWND)0x0,DAT_18009b8b0);
    DAT_18009b8b0 = 0;
  }
  if (DAT_18009b860 != (undefined8 *)0x0) {
    if (DAT_18009b894 != 0) {
      FUN_180045de0((longlong)DAT_18009b860);
      DAT_18009b894 = 0;
    }
    CheckInTrackingKeys();
    FUN_1800461d0((longlong)DAT_18009b860);
    if (DAT_18009b860 != (undefined8 *)0x0) {
      (**(code **)*DAT_18009b860)(DAT_18009b860,1);
    }
    DAT_18009b860 = (undefined8 *)0x0;
    DAT_18009b898 = 0;
    DAT_18009b8a0 = 0;
    DAT_18009b8a8 = 0;
    DAT_18009ba50 = 0;
    DAT_18009ba58 = 0;
    DAT_18009ba60 = 0;
  }
  if (DAT_18009b890 != '\0') {
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_18009b868);
  }
  DAT_18009b892 = 0;
  DAT_18009b890 = 0;
  return;
}

/* ---- FUNC 000445F0 MMWaitFailed (8 bytes) ---- */

undefined1 MMWaitFailed(void)

{
                    /* 0x445f0  145  MMWaitFailed */
  return DAT_18009b892;
}

/* ---- FUNC 00044600 MMWaitFailureKey (66 bytes) ---- */

BSTR MMWaitFailureKey(void)

{
  ulonglong uVar1;
  BSTR pOVar2;
  
                    /* 0x44600  146  MMWaitFailureKey */
  if (DAT_18009b892 == '\0') {
    return (BSTR)0x0;
  }
  uVar1 = FUN_1800240b0();
  if ((int)uVar1 == 1) {
                    /* WARNING: Could not recover jumptable at 0x000180044622. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pOVar2 = SysAllocString(L"AEA_AspenPlus");
    return pOVar2;
  }
                    /* WARNING: Could not recover jumptable at 0x000180044634. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pOVar2 = SysAllocString(L"AEA_AspenProperties");
  return pOVar2;
}

/* ---- FUNC 00044650 MMWaitFailureMessage (264 bytes) ---- */

undefined8 MMWaitFailureMessage(void)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  BSTR pOVar5;
  LPCSTR pCVar6;
  
                    /* 0x44650  147  MMWaitFailureMessage */
  if (DAT_18009b892 == '\0') {
    return 0;
  }
  if (DAT_1800791d8 == 0) {
    pCVar6 = "";
  }
  else {
    pCVar6 = (LPCSTR)&DAT_1800791c8;
    if (0xf < DAT_1800791e0) {
      pCVar6 = DAT_1800791c8;
    }
  }
  puVar4 = operator_new(0x18);
  if (puVar4 == (undefined8 *)0x0) {
    puVar4 = (undefined8 *)0x0;
  }
  else {
    puVar4[1] = 0;
    *(undefined4 *)(puVar4 + 2) = 1;
    pOVar5 = FUN_180047d90(pCVar6);
    *puVar4 = pOVar5;
  }
  if (puVar4 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_180047c60(0x8007000e);
  }
  if (*(int *)(puVar4 + 2) != 1) {
                    /* WARNING: Subroutine does not return */
    FUN_180047c60(0x80004003);
  }
  uVar3 = *puVar4;
  *puVar4 = 0;
  LOCK();
  piVar1 = (int *)(puVar4 + 2);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    if ((BSTR)*puVar4 != (BSTR)0x0) {
      SysFreeString((BSTR)*puVar4);
      *puVar4 = 0;
    }
    if ((void *)puVar4[1] != (void *)0x0) {
      operator_delete__((void *)puVar4[1]);
      puVar4[1] = 0;
    }
    operator_delete(puVar4);
  }
  return uVar3;
}

/* ---- FUNC 00044760 MMWaitForDocument (8 bytes) ---- */

void MMWaitForDocument(undefined *param_1,longlong param_2,longlong param_3)

{
                    /* 0x44760  148  MMWaitForDocument */
  MMWaitForDocumentA(param_1,param_2,param_3,'\0');
  return;
}

/* ---- FUNC 00044770 MMWaitForDocumentA (1286 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong MMWaitForDocumentA(undefined *param_1,longlong param_2,longlong param_3,char param_4)

{
  char cVar1;
  DWORD DVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  LPSTR pCVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  undefined8 uVar9;
  undefined8 **ppuVar10;
  undefined8 ******ppppppuVar11;
  longlong lVar12;
  size_t sVar13;
  bool bVar14;
  undefined1 auStack_88 [32];
  undefined8 *local_68;
  undefined *local_60;
  undefined8 *****local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong uStack_40;
  ulonglong local_38;
  
                    /* 0x44770  149  MMWaitForDocumentA */
  puVar3 = DAT_18009b860;
  local_38 = DAT_1800791f8 ^ (ulonglong)auStack_88;
  bVar14 = false;
  if (param_4 != '\0') {
    if (param_1 != (undefined *)0x0) {
      DAT_18009b898 = (code *)param_1;
    }
    if (param_2 != 0) {
      DAT_18009b8a0 = param_2;
    }
    if (param_3 != 0) {
      DAT_18009b8a8 = param_3;
    }
    return CONCAT71((int7)(local_38 >> 8),1);
  }
  local_68 = DAT_18009b860;
  local_60 = param_1;
  DVar2 = GetCurrentThreadId();
  if (DVar2 != DAT_18009b8bc) {
    local_68 = operator_new(0x20);
    if (local_68 == (undefined8 *)0x0) {
      puVar3 = (undefined8 *)0x0;
      local_68 = puVar3;
    }
    else {
      puVar3 = FUN_180045a60(local_68);
      local_68 = puVar3;
    }
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_18009b868);
  if (DAT_18009b892 == '\0') {
    if (DAT_18009b891 == '\0') {
      if (DAT_18009b894 == 0) {
        uVar4 = FUN_1800460a0((longlong)puVar3);
        if ((char)uVar4 == '\0') {
          DAT_18009b892 = '\x01';
          if (DAT_18009b860 != (undefined8 *)0x0) {
            (**(code **)*DAT_18009b860)(DAT_18009b860,1);
          }
          DAT_18009b860 = (undefined8 *)0x0;
          pCVar5 = GetCommandLineA();
          pcVar6 = _strdup(pCVar5);
          _strlwr(pcVar6);
          pcVar7 = strstr(pcVar6,"/automation");
          if ((pcVar7 == (char *)0x0) &&
             (pcVar7 = strstr(pcVar6,"-automation"), pcVar7 == (char *)0x0)) {
            MMSetSuppress(0);
          }
          operator_delete__(pcVar6);
          FUN_180043da0(0);
          if (param_1 != (undefined *)0x0) {
            (*(code *)param_1)(2);
          }
        }
        else {
          FUN_180044e20();
          uVar4 = FUN_1800240b0();
          pcVar6 = "AEA_AspenPlus";
          DAT_18009b898 = (code *)param_1;
          DAT_18009b8a0 = param_2;
          DAT_18009b8a8 = param_3;
          if ((int)uVar4 == 2) {
            pcVar6 = "AEA_AspenProperties";
          }
          do {
            local_58 = (undefined8 ******)0x0;
            uStack_50 = 0;
            local_48 = 0;
            uStack_40 = 0;
            sVar13 = 0xffffffffffffffff;
            do {
              sVar13 = sVar13 + 1;
            } while (pcVar6[sVar13] != '\0');
            FUN_18000b5f0(&local_58,pcVar6,sVar13);
            cVar1 = FUN_180045e20((longlong)puVar3,(LPCSTR)&local_58,(int *)&DAT_18009b894,
                                  (longlong *)&DAT_1800791c8);
            if (0xf < uStack_40) {
              ppppppuVar11 = (undefined8 ******)local_58;
              if ((0xfff < uStack_40 + 1) &&
                 (ppppppuVar11 = (undefined8 ******)local_58[-1],
                 0x1f < (ulonglong)((longlong)local_58 + (-8 - (longlong)ppppppuVar11)))) {
                    /* WARNING: Subroutine does not return */
                _invalid_parameter_noinfo_noreturn();
              }
              operator_delete(ppppppuVar11);
            }
            if (cVar1 != '\0') goto LAB_180044b28;
            pCVar5 = GetCommandLineA();
            pcVar7 = _strdup(pCVar5);
            _strlwr(pcVar7);
            pcVar8 = strstr(pcVar7,"/automation");
            if ((pcVar8 == (char *)0x0) &&
               (pcVar8 = strstr(pcVar7,"-automation"), pcVar8 == (char *)0x0)) {
              MMSetSuppress(0);
            }
            operator_delete__(pcVar7);
            if (DAT_1800791d8 == 0) {
              ppuVar10 = (undefined8 **)&DAT_1800533ef;
            }
            else {
              ppuVar10 = &DAT_1800791c8;
              if (0xf < DAT_1800791e0) {
                ppuVar10 = (undefined8 **)DAT_1800791c8;
              }
            }
            uVar9 = FUN_180043da0(ppuVar10);
          } while ((int)uVar9 == 4);
          if (DAT_18009b860 != (undefined8 *)0x0) {
            (**(code **)*DAT_18009b860)();
          }
          DAT_18009b860 = (undefined8 *)0x0;
          DAT_18009b892 = '\x01';
          if (DAT_18009b898 != (code *)0x0) {
            (*DAT_18009b898)();
LAB_180044b28:
            if (DAT_18009b892 == '\0') {
              uStack_50 = 0;
              local_48 = _DAT_180053820;
              uStack_40 = _UNK_180053828;
              local_58 = (undefined8 ******)0x0;
              uVar4 = FUN_1800240b0();
              FUN_180046010((longlong)DAT_18009b860,(ulonglong)DAT_18009b894,(undefined4 *)&local_68
                            ,(longlong *)&local_58);
              ppppppuVar11 = &local_58;
              if (0xf < uStack_40) {
                ppppppuVar11 = (undefined8 ******)local_58;
              }
              lVar12 = 0x14;
              if ((int)uVar4 == 2) {
                lVar12 = 0x10;
              }
              strncpy(&DAT_18009ba78,(char *)(lVar12 + (longlong)ppppppuVar11),0x20);
              DAT_18009ba98 = 0;
              bVar14 = true;
              if (0xf < uStack_40) {
                ppppppuVar11 = (undefined8 ******)local_58;
                if ((0xfff < uStack_40 + 1) &&
                   (ppppppuVar11 = (undefined8 ******)local_58[-1],
                   0x1f < (ulonglong)((longlong)local_58 + (-8 - (longlong)ppppppuVar11)))) {
                    /* WARNING: Subroutine does not return */
                  _invalid_parameter_noinfo_noreturn();
                }
                operator_delete(ppppppuVar11);
              }
              goto LAB_180044c19;
            }
          }
          bVar14 = false;
          if (DAT_18009b8b0 != 0) {
            KillTimer((HWND)0x0,DAT_18009b8b0);
            DAT_18009b8b0 = 0;
          }
        }
      }
      else {
        if (param_1 != (undefined *)0x0) {
          DAT_18009b898 = (code *)param_1;
        }
        if (param_2 != 0) {
          DAT_18009b8a0 = param_2;
        }
        if (param_3 != 0) {
          DAT_18009b8a8 = param_3;
        }
        FUN_180046220((longlong)puVar3,(ulonglong)DAT_18009b894,(undefined4 *)&local_68);
        bVar14 = (int)local_68 != 0;
        if (((int)local_68 == 0) && (DAT_18009b898 != (code *)0x0)) {
          (*DAT_18009b898)(1);
          DAT_18009b892 = '\x01';
        }
      }
    }
    else {
      bVar14 = true;
    }
  }
  else {
    bVar14 = false;
  }
LAB_180044c19:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_18009b868);
  DVar2 = GetCurrentThreadId();
  if ((DVar2 != DAT_18009b8bc) && (FUN_1800461d0((longlong)puVar3), puVar3 != (undefined8 *)0x0)) {
    (**(code **)*puVar3)(puVar3,1);
  }
  return (ulonglong)bVar14;
}

/* ---- FUNC 00044C80 ReleaseWaitItem (39 bytes) ---- */

void ReleaseWaitItem(uint param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  longlong lVar5;
  
                    /* 0x44c80  163  ReleaseWaitItem */
  if ((param_1 < 9) && (DAT_18009b860 != 0)) {
    if ((&DAT_18009baa0)[(int)param_1] != 0) {
      if ((&DAT_18009baa0)[(int)param_1] != -1) {
        bVar1 = false;
        iVar4 = 0;
        if (0 < DAT_18009b8b8) {
          piVar3 = &DAT_18009b8c0;
          lVar5 = DAT_18009b860;
          iVar2 = DAT_18009b8b8;
          do {
            if (*piVar3 == (&DAT_18009baa0)[(int)param_1]) {
              FUN_180045de0(lVar5);
              bVar1 = true;
              lVar5 = DAT_18009b860;
              iVar2 = DAT_18009b8b8;
            }
            else if (bVar1) {
              piVar3[-1] = *piVar3;
            }
            iVar4 = iVar4 + 1;
            piVar3 = piVar3 + 1;
          } while (iVar4 < iVar2);
          if (bVar1) {
            DAT_18009b8b8 = iVar2 + -1;
          }
        }
      }
      (&DAT_18009baa0)[(int)param_1] = 0;
    }
  }
  return;
}

/* ---- FUNC 00044CA7 FUN_180044ca7 (30 bytes) ---- */

void FUN_180044ca7(longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  int *piVar1;
  bool bVar2;
  longlong in_RAX;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  piVar1 = (int *)(param_1 + in_RAX * 4);
  iVar5 = *(int *)(param_1 + in_RAX * 4);
  if (iVar5 != 0) {
    if (iVar5 != -1) {
      bVar2 = false;
      iVar5 = 0;
      if (0 < DAT_18009b8b8) {
        piVar4 = &DAT_18009b8c0;
        iVar3 = DAT_18009b8b8;
        do {
          if (*piVar4 == *piVar1) {
            FUN_180045de0(param_4);
            bVar2 = true;
            param_4 = DAT_18009b860;
            iVar3 = DAT_18009b8b8;
          }
          else if (bVar2) {
            piVar4[-1] = *piVar4;
          }
          iVar5 = iVar5 + 1;
          piVar4 = piVar4 + 1;
        } while (iVar5 < iVar3);
        if (bVar2) {
          DAT_18009b8b8 = iVar3 + -1;
        }
      }
    }
    *piVar1 = 0;
  }
  return;
}

/* ---- FUNC 00044CC5 FUN_180044cc5 (11 bytes) ---- */

void FUN_180044cc5(undefined8 param_1,int param_2,char param_3,longlong param_4)

{
  int *piVar1;
  int *unaff_RSI;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_2) {
    piVar1 = &DAT_18009b8c0;
    do {
      if (*piVar1 == *unaff_RSI) {
        FUN_180045de0(param_4);
        param_3 = '\x01';
        param_4 = DAT_18009b860;
        param_2 = DAT_18009b8b8;
      }
      else if (param_3 != '\0') {
        piVar1[-1] = *piVar1;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar2 < param_2);
    if (param_3 != '\0') {
      DAT_18009b8b8 = param_2 + -1;
    }
  }
  *unaff_RSI = 0;
  return;
}

/* ---- FUNC 00044CD0 FUN_180044cd0 (78 bytes) ---- */

void FUN_180044cd0(undefined8 param_1,int param_2,char param_3,longlong param_4)

{
  int *piVar1;
  int *unaff_RSI;
  int unaff_EDI;
  
  piVar1 = &DAT_18009b8c0;
  do {
    if (*piVar1 == *unaff_RSI) {
      FUN_180045de0(param_4);
      param_3 = '\x01';
      param_4 = DAT_18009b860;
      param_2 = DAT_18009b8b8;
    }
    else if (param_3 != '\0') {
      piVar1[-1] = *piVar1;
    }
    unaff_EDI = unaff_EDI + 1;
    piVar1 = piVar1 + 1;
  } while (unaff_EDI < param_2);
  if (param_3 != '\0') {
    DAT_18009b8b8 = param_2 + -1;
  }
  *unaff_RSI = 0;
  return;
}

/* ---- FUNC 00044D1E FUN_180044d1e (13 bytes) ---- */

void FUN_180044d1e(undefined8 param_1,int param_2)

{
  undefined4 *unaff_RSI;
  
  DAT_18009b8b8 = param_2 + -1;
  *unaff_RSI = 0;
  return;
}

/* ---- FUNC 00044D2B FUN_180044d2b (11 bytes) ---- */

void FUN_180044d2b(void)

{
  undefined4 *unaff_RSI;
  
  *unaff_RSI = 0;
  return;
}

/* ---- FUNC 00044D36 FUN_180044d36 (5 bytes) ---- */

void FUN_180044d36(void)

{
  return;
}

/* ---- FUNC 00044D40 FUN_180044d40 (220 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_180044d40(int param_1)

{
  long lVar1;
  int iVar2;
  undefined1 auStack_58 [32];
  char local_38;
  char local_37;
  char local_36;
  char local_35;
  undefined1 local_34;
  char local_30;
  char local_2f;
  char local_2e;
  char local_2d;
  ulonglong local_10;
  
  local_10 = DAT_1800791f8 ^ (ulonglong)auStack_58;
  iVar2 = param_1 * 0x3da897b + (param_1 / 10) * -0x26895ec4 + -0x37c04086;
  FID_conflict_sprintf_s((wchar_t *)&local_30,0x20,L"㐥d",(ulonglong)(uint)(iVar2 % 10000));
  local_34 = 0;
  local_38 = '0';
  if (local_2d != ' ') {
    local_38 = local_2d;
  }
  local_37 = '0';
  if (local_2e != ' ') {
    local_37 = local_2e;
  }
  local_35 = '0';
  local_36 = '0';
  if (local_2f != ' ') {
    local_36 = local_2f;
  }
  if (local_30 != ' ') {
    local_35 = local_30;
  }
  lVar1 = atol(&local_38);
  return lVar1 + (iVar2 / 10000) * 10000;
}

/* ---- FUNC 00044E20 FUN_180044e20 (587 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180044e20(void)

{
  int iVar1;
  undefined8 uVar2;
  void *pvVar3;
  char *pcVar4;
  size_t sVar5;
  undefined1 auStack_68 [32];
  char *local_48;
  void *local_40;
  void *local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong uStack_20;
  ulonglong local_18;
  
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_68;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_40,"en-US");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48);
  uVar2 = FUN_180019850((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48);
  if (((int)uVar2 == 1) && (0 < *(int *)(local_48 + -0x10))) {
    iVar1 = _stricmp(local_48,"ENG");
    if (iVar1 == 0) {
      pcVar4 = "en-US";
    }
    else {
      iVar1 = _stricmp(local_48,"FRA");
      if (iVar1 == 0) {
        pcVar4 = "fr-FR";
      }
      else {
        iVar1 = _stricmp(local_48,"ITA");
        if (iVar1 == 0) {
          pcVar4 = "it-IT";
        }
        else {
          iVar1 = _stricmp(local_48,"DEU");
          if (iVar1 == 0) {
            pcVar4 = "de-DE";
          }
          else {
            iVar1 = _stricmp(local_48,"SPA");
            if (iVar1 == 0) {
              pcVar4 = "es-ES";
            }
            else {
              iVar1 = _stricmp(local_48,"JPN");
              if (iVar1 == 0) {
                pcVar4 = "ja-JP";
              }
              else {
                iVar1 = _stricmp(local_48,"CHS");
                if (iVar1 == 0) {
                  pcVar4 = "zh-HANS";
                }
                else {
                  iVar1 = _stricmp(local_48,"KOR");
                  if (iVar1 == 0) {
                    pcVar4 = "ko-KR";
                  }
                  else {
                    iVar1 = _stricmp(local_48,"RUS");
                    if (iVar1 == 0) {
                      pcVar4 = "ru-RU";
                    }
                    else {
                      iVar1 = _stricmp(local_48,"PTB");
                      if (iVar1 != 0) goto LAB_180044fb3;
                      pcVar4 = "pt-BR";
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_40,pcVar4);
  }
LAB_180044fb3:
  if (DAT_18009b860 != 0) {
    local_38 = (void *)0x0;
    uStack_30 = 0;
    local_28 = 0;
    uStack_20 = 0;
    sVar5 = 0xffffffffffffffff;
    do {
      sVar5 = sVar5 + 1;
    } while (*(char *)((longlong)local_40 + sVar5) != '\0');
    FUN_18000b5f0(&local_38,local_40,sVar5);
    FUN_180046120(DAT_18009b860,(LPCSTR)&local_38);
    if (0xf < uStack_20) {
      pvVar3 = local_38;
      if ((0xfff < uStack_20 + 1) &&
         (pvVar3 = *(void **)((longlong)local_38 + -8),
         0x1f < (ulonglong)((longlong)local_38 + (-8 - (longlong)pvVar3)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      operator_delete(pvVar3);
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_40);
  return;
}

/* ---- FUNC 00045070 FUN_180045070 (630 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180045070(void)

{
  char cVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  void *pvVar5;
  undefined8 ******ppppppuVar6;
  char *pcVar7;
  size_t sVar8;
  undefined1 auStack_78 [32];
  int local_58 [2];
  undefined8 *****local_50;
  undefined8 uStack_48;
  longlong local_40;
  ulonglong local_38;
  void *local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  ulonglong local_18;
  ulonglong local_10;
  
  local_10 = DAT_1800791f8 ^ (ulonglong)auStack_78;
  if (((DAT_18009b894 != 0) && (DAT_18009b860 != 0)) &&
     (FUN_180046220(DAT_18009b860,(ulonglong)DAT_18009b894,local_58), local_58[0] == 0)) {
    if (DAT_18009b898 == (code *)0x0) {
      DAT_18009b8b0 = SetTimer((HWND)0x0,DAT_18009b8b0,30000,FUN_180044190);
    }
    else {
      FUN_180045de0(DAT_18009b860);
      DAT_18009b894 = 0;
      iVar2 = (*DAT_18009b898)(1,0);
      if (iVar2 == 1) {
        uVar3 = FUN_1800240b0();
        pcVar7 = "AEA_AspenPlus";
        if ((int)uVar3 == 2) {
          pcVar7 = "AEA_AspenProperties";
        }
        uStack_48 = 0;
        local_40 = 0;
        local_38 = 0xf;
        local_50 = (undefined8 ******)0x0;
        do {
          local_30 = (void *)0x0;
          uStack_28 = 0;
          local_20 = 0;
          local_18 = 0;
          sVar8 = 0xffffffffffffffff;
          do {
            sVar8 = sVar8 + 1;
          } while (pcVar7[sVar8] != '\0');
          FUN_18000b5f0(&local_30,pcVar7,sVar8);
          cVar1 = FUN_180045e20(DAT_18009b860,(LPCSTR)&local_30,(int *)&DAT_18009b894,
                                (longlong *)&local_50);
          if (0xf < local_18) {
            pvVar5 = local_30;
            if ((0xfff < local_18 + 1) &&
               (pvVar5 = *(void **)((longlong)local_30 + -8),
               0x1f < (ulonglong)((longlong)local_30 + (-8 - (longlong)pvVar5)))) {
                    /* WARNING: Subroutine does not return */
              _invalid_parameter_noinfo_noreturn();
            }
            operator_delete(pvVar5);
          }
          if (cVar1 != '\0') {
            (*DAT_18009b898)(3);
            if (local_38 < 0x10) {
              return;
            }
            ppppppuVar6 = (undefined8 ******)local_50;
            if ((local_38 + 1 < 0x1000) ||
               (ppppppuVar6 = (undefined8 ******)local_50[-1],
               (undefined *)((longlong)local_50 + (-8 - (longlong)ppppppuVar6)) < (undefined *)0x20)
               ) goto LAB_180045242;
            goto LAB_180045290;
          }
          if (local_40 == 0) {
            ppppppuVar6 = (undefined8 ******)&DAT_1800533ef;
          }
          else {
            ppppppuVar6 = &local_50;
            if (0xf < local_38) {
              ppppppuVar6 = (undefined8 ******)local_50;
            }
          }
          uVar4 = FUN_180043da0(ppppppuVar6);
        } while ((int)uVar4 == 4);
        (*DAT_18009b898)(2);
        if (0xf < local_38) {
          ppppppuVar6 = (undefined8 ******)local_50;
          if ((0xfff < local_38 + 1) &&
             (ppppppuVar6 = (undefined8 ******)local_50[-1],
             (undefined *)0x1f < (undefined *)((longlong)local_50 + (-8 - (longlong)local_50[-1]))))
          {
LAB_180045290:
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
LAB_180045242:
          operator_delete(ppppppuVar6);
        }
      }
      else {
        (*DAT_18009b898)(2);
      }
    }
  }
  return;
}

/* ---- FUNC 000452F0 CheckInACMEModel (68 bytes) ---- */

void CheckInACMEModel(void)

{
  if (0 < DAT_18009ba6c) {
    DAT_18009ba6c = DAT_18009ba6c + -1;
  }
  if (DAT_18009ba6c == 0) {
    PostMainWndMessage2(0x4f9,7,0);
  }
  if (DAT_18009ba6c < 0) {
    DAT_18009ba6c = 0;
  }
  return;
}

/* ---- FUNC 00045340 CheckInACMModel (68 bytes) ---- */

void CheckInACMModel(void)

{
  if (0 < DAT_18009ba68) {
    DAT_18009ba68 = DAT_18009ba68 + -1;
  }
  if (DAT_18009ba68 == 0) {
    PostMainWndMessage2(0x4f9,6,0);
  }
  if (DAT_18009ba68 < 0) {
    DAT_18009ba68 = 0;
  }
  return;
}

/* ---- FUNC 00045390 CheckInColumnAnalyzerTK (62 bytes) ---- */

void CheckInColumnAnalyzerTK(void)

{
                    /* 0x45390  325  CheckInColumnAnalyzerTK */
  DAT_18009ba70 = DAT_18009ba70 + -1;
  if (DAT_18009ba70 < 1) {
    PostMainWndMessage2(0x4f9,0,0);
  }
  if (DAT_18009ba70 < 0) {
    DAT_18009ba70 = 0;
  }
  return;
}

/* ---- FUNC 000453D0 CheckInEDRTK (132 bytes) ---- */

void CheckInEDRTK(char *param_1)

{
  int iVar1;
  
                    /* 0x453d0  326  CheckInEDRTK */
  iVar1 = _stricmp(param_1,"ST");
  if (iVar1 == 0) {
    CheckInEDRTK_ST();
    return;
  }
  iVar1 = _stricmp(param_1,"AC");
  if (iVar1 == 0) {
    CheckInEDRTK_AC();
    return;
  }
  iVar1 = _stricmp(param_1,"PL");
  if (iVar1 == 0) {
    CheckInEDRTK_PL();
    return;
  }
  iVar1 = _stricmp(param_1,"AEDR");
  if (iVar1 == 0) {
    FUN_180045470();
    return;
  }
  return;
}

/* ---- FUNC 00045460 CheckInEDRTK_AC (10 bytes) ---- */

void CheckInEDRTK_AC(void)

{
                    /* 0x45460  327  CheckInEDRTK_AC */
  ReleaseWaitItem(3);
  return;
}

/* ---- FUNC 00045470 FUN_180045470 (10 bytes) ---- */

void FUN_180045470(void)

{
  ReleaseWaitItem(5);
  return;
}

/* ---- FUNC 00045480 CheckInEDRTK_PL (10 bytes) ---- */

void CheckInEDRTK_PL(void)

{
                    /* 0x45480  328  CheckInEDRTK_PL */
  ReleaseWaitItem(4);
  return;
}

/* ---- FUNC 00045490 CheckInEDRTK_ST (10 bytes) ---- */

void CheckInEDRTK_ST(void)

{
                    /* 0x45490  329  CheckInEDRTK_ST */
  ReleaseWaitItem(2);
  return;
}

/* ---- FUNC 000454A0 CheckInFermentationReaction (68 bytes) ---- */

void CheckInFermentationReaction(void)

{
  if (0 < DAT_18009ba74) {
    DAT_18009ba74 = DAT_18009ba74 + -1;
  }
  if (DAT_18009ba74 == 0) {
    PostMainWndMessage2(0x4f9,8,0);
  }
  if (DAT_18009ba74 < 0) {
    DAT_18009ba74 = 0;
  }
  return;
}

/* ---- FUNC 000454F0 CheckOutACMEModel (69 bytes) ---- */

void CheckOutACMEModel(void)

{
                    /* 0x454f0  331  CheckOutACMEModel */
  if (DAT_18009ba6c < 0) {
    DAT_18009ba6c = 0;
  }
  else if (DAT_18009ba6c != 0) {
    DAT_18009ba6c = DAT_18009ba6c + 1;
    return;
  }
  PostMainWndMessage2(0x4f8,7,0);
  DAT_18009ba6c = DAT_18009ba6c + 1;
  return;
}

/* ---- FUNC 00045540 CheckOutACMModel (69 bytes) ---- */

void CheckOutACMModel(void)

{
                    /* 0x45540  332  CheckOutACMModel */
  if (DAT_18009ba68 < 0) {
    DAT_18009ba68 = 0;
  }
  else if (DAT_18009ba68 != 0) {
    DAT_18009ba68 = DAT_18009ba68 + 1;
    return;
  }
  PostMainWndMessage2(0x4f8,6,0);
  DAT_18009ba68 = DAT_18009ba68 + 1;
  return;
}

/* ---- FUNC 00045590 CheckOutColumnAnalyzerTK (53 bytes) ---- */

void CheckOutColumnAnalyzerTK(void)

{
                    /* 0x45590  333  CheckOutColumnAnalyzerTK */
  if (DAT_18009ba70 == 0) {
    PostMainWndMessage2(0x4f8,0,0);
    DAT_18009ba70 = DAT_18009ba70 + 1;
    return;
  }
  DAT_18009ba70 = DAT_18009ba70 + 1;
  return;
}

/* ---- FUNC 000455D0 CheckOutEDRTK (132 bytes) ---- */

void CheckOutEDRTK(char *param_1)

{
  int iVar1;
  
                    /* 0x455d0  334  CheckOutEDRTK */
  iVar1 = _stricmp(param_1,"ST");
  if (iVar1 == 0) {
    FUN_180045690();
    return;
  }
  iVar1 = _stricmp(param_1,"AC");
  if (iVar1 == 0) {
    CheckOutEDRTK_AC();
    return;
  }
  iVar1 = _stricmp(param_1,"PL");
  if (iVar1 == 0) {
    CheckOutEDRTK_PL();
    return;
  }
  iVar1 = _stricmp(param_1,"AEDR");
  if (iVar1 == 0) {
    FUN_180045670();
    return;
  }
  return;
}

/* ---- FUNC 00045660 CheckOutEDRTK_AC (13 bytes) ---- */

void CheckOutEDRTK_AC(void)

{
                    /* 0x45660  335  CheckOutEDRTK_AC */
  MMAddWaitItem(3);
  return;
}

/* ---- FUNC 00045670 FUN_180045670 (13 bytes) ---- */

void FUN_180045670(void)

{
  MMAddWaitItem(5);
  return;
}

/* ---- FUNC 00045680 CheckOutEDRTK_PL (13 bytes) ---- */

void CheckOutEDRTK_PL(void)

{
                    /* 0x45680  336  CheckOutEDRTK_PL */
  MMAddWaitItem(4);
  return;
}

/* ---- FUNC 00045690 FUN_180045690 (13 bytes) ---- */

void FUN_180045690(void)

{
  MMAddWaitItem(2);
  return;
}

/* ---- FUNC 000456A0 CheckOutFermentationReaction (69 bytes) ---- */

void CheckOutFermentationReaction(void)

{
                    /* 0x456a0  337  CheckOutFermentationReaction */
  if (DAT_18009ba74 < 0) {
    DAT_18009ba74 = 0;
  }
  else if (DAT_18009ba74 != 0) {
    DAT_18009ba74 = DAT_18009ba74 + 1;
    return;
  }
  PostMainWndMessage2(0x4f8,8,0);
  DAT_18009ba74 = DAT_18009ba74 + 1;
  return;
}

/* ---- FUNC 000456F0 GenerateString (143 bytes) ---- */

undefined * GenerateString(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
                    /* 0x456f0  354  GenerateString */
  uVar1 = FUN_180044d40(param_1);
  iVar2 = FUN_180044160();
  FUN_180044160();
  rand();
  iVar3 = rand();
  DAT_18009bad0 = 0;
  iVar4 = FUN_180043e10(param_1);
  FID_conflict_sprintf_s
            ((wchar_t *)&DAT_18009bad0,0x100,(wchar_t *)"%d-%d-%d-%d",(ulonglong)uVar1,iVar2 + 0x169
             ,iVar4,iVar3 + 0x7a);
  return &DAT_18009bad0;
}

/* ---- FUNC 00045780 GetAcmTKLicense (7 bytes) ---- */

undefined4 GetAcmTKLicense(void)

{
                    /* 0x45780  355  GetAcmTKLicense */
  return DAT_18009ba68;
}

/* ---- FUNC 00045790 GetColumnAnalyzerTKLicense (7 bytes) ---- */

undefined4 GetColumnAnalyzerTKLicense(void)

{
                    /* 0x45790  357  GetColumnAnalyzerTKLicense */
  return DAT_18009ba70;
}

/* ---- FUNC 000457A0 GetCurrentApropTime (28 bytes) ---- */

undefined4 GetCurrentApropTime(void)

{
                    /* 0x457a0  358  GetCurrentApropTime */
  _time64((__time64_t *)&DAT_18009bac8);
  return DAT_18009bac8;
}

/* ---- FUNC 000457C0 MMCARegSection (16 bytes) ---- */

void MMCARegSection(void)

{
                    /* 0x457c0  371  MMCARegSection */
  if (DAT_18009ba50 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001800457cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_18009ba50)();
    return;
  }
  return;
}

/* ---- FUNC 000457D0 MMCAUnRegSection (16 bytes) ---- */

void MMCAUnRegSection(void)

{
                    /* 0x457d0  372  MMCAUnRegSection */
  if (DAT_18009ba58 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001800457dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_18009ba58)();
    return;
  }
  return;
}

/* ---- FUNC 000457E0 MMDisplayConnectError (64 bytes) ---- */

void MMDisplayConnectError(LPCSTR param_1)

{
  HRESULT HVar1;
  int cchWideChar;
  int iVar2;
  BSTR lpWideCharStr;
  ulonglong uVar3;
  BSTR bstrString;
  wchar_t *psz;
  longlong *local_res10;
  
                    /* 0x457e0  382  MMDisplayConnectError */
  lpWideCharStr = (BSTR)0x0;
  local_res10 = (longlong *)0x0;
  HVar1 = CoCreateInstance((IID *)&DAT_1800574f8,(LPUNKNOWN)0x0,1,(IID *)&DAT_1800577a0,&local_res10
                          );
  if (-1 < HVar1) {
    if (param_1 != (LPCSTR)0x0) {
      cchWideChar = MultiByteToWideChar(0,0,param_1,-1,(LPWSTR)0x0,0);
      lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,cchWideChar - 1);
      if ((lpWideCharStr != (BSTR)0x0) &&
         (iVar2 = MultiByteToWideChar(0,0,param_1,-1,lpWideCharStr,cchWideChar),
         iVar2 != cchWideChar)) {
        SysFreeString(lpWideCharStr);
LAB_1800458f4:
                    /* WARNING: Subroutine does not return */
        FUN_180018e40(-0x7ff8fff2);
      }
      if (lpWideCharStr == (BSTR)0x0) goto LAB_1800458f4;
      SysFreeString(lpWideCharStr);
    }
    uVar3 = FUN_1800240b0();
    psz = L"AEA_AspenPlus";
    if ((int)uVar3 != 1) {
      psz = L"AEA_AspenProperties";
    }
    bstrString = SysAllocString(psz);
    (**(code **)(*local_res10 + 0x18))(local_res10,bstrString,lpWideCharStr);
    (**(code **)(*local_res10 + 0x10))();
    SysFreeString(bstrString);
    if (lpWideCharStr != (BSTR)0x0) {
      SysFreeString(lpWideCharStr);
    }
  }
  return;
}

/* ---- FUNC 00045820 FUN_180045820 (192 bytes) ---- */

void FUN_180045820(void)

{
  int cchWideChar;
  int iVar1;
  ulonglong uVar2;
  BSTR bstrString;
  wchar_t *psz;
  BSTR unaff_RBX;
  LPCSTR unaff_RDI;
  longlong *in_stack_00000048;
  
  if (unaff_RDI != (LPCSTR)0x0) {
    cchWideChar = MultiByteToWideChar(0,0,unaff_RDI,(int)unaff_RBX + -1,unaff_RBX,(int)unaff_RBX);
    unaff_RBX = SysAllocStringLen((OLECHAR *)0x0,cchWideChar - 1);
    if (unaff_RBX != (BSTR)0x0) {
      iVar1 = MultiByteToWideChar(0,0,unaff_RDI,-1,unaff_RBX,cchWideChar);
      if (iVar1 != cchWideChar) {
        SysFreeString(unaff_RBX);
        goto LAB_1800458f4;
      }
    }
    if (unaff_RBX == (BSTR)0x0) {
LAB_1800458f4:
                    /* WARNING: Subroutine does not return */
      FUN_180018e40(-0x7ff8fff2);
    }
    SysFreeString(unaff_RBX);
  }
  uVar2 = FUN_1800240b0();
  psz = L"AEA_AspenPlus";
  if ((int)uVar2 != 1) {
    psz = L"AEA_AspenProperties";
  }
  bstrString = SysAllocString(psz);
  (**(code **)(*in_stack_00000048 + 0x18))(in_stack_00000048,bstrString,unaff_RBX);
  (**(code **)(*in_stack_00000048 + 0x10))();
  SysFreeString(bstrString);
  if (unaff_RBX != (BSTR)0x0) {
    SysFreeString(unaff_RBX);
  }
  return;
}

/* ---- FUNC 000458E0 FUN_1800458e0 (11 bytes) ---- */

void FUN_1800458e0(void)

{
  return;
}

/* ---- FUNC 000458EB FUN_1800458eb (19 bytes) ---- */

void FUN_1800458eb(void)

{
  BSTR unaff_RBX;
  
  SysFreeString(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_180018e40(-0x7ff8fff2);
}

/* ---- FUNC 00045900 MMDisplayHtmlHelp (16 bytes) ---- */

void MMDisplayHtmlHelp(void)

{
                    /* 0x45900  383  MMDisplayHtmlHelp */
  if (DAT_18009ba60 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00018004590c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_18009ba60)();
    return;
  }
  return;
}

/* ---- FUNC 00045910 START_ASPEN_PROCESS (234 bytes) ---- */

void START_ASPEN_PROCESS(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        ,undefined8 param_5,longlong param_6)

{
  char cVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  char *pcVar5;
  
                    /* 0x45910  467  START_ASPEN_PROCESS */
  if ((DAT_18009b891 == '\0') && (DAT_18009b894 != 0)) {
    uVar3 = FUN_1800240b0();
    pcVar5 = "AspenPlusGUI";
    if ((int)uVar3 == 2) {
      pcVar5 = "AspenPropertiesGUI";
    }
    lVar4 = param_6 - (longlong)pcVar5;
    do {
      cVar1 = *pcVar5;
      pcVar5[lVar4] = cVar1;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    iVar2 = GetCurrentApropTime();
    pcVar5 = GenerateString(iVar2);
    lVar4 = param_6 - (longlong)pcVar5;
    do {
      cVar1 = *pcVar5;
      pcVar5[lVar4 + 0x50] = cVar1;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_180044130(param_6 + 0xa0);
  }
  START_PROCESS(param_1,param_2,param_3,param_4,param_5,param_6);
  FUN_18000f4b0();
  return;
}

/* ---- FUNC 00045A00 FID_conflict:sprintf_s (88 bytes) ---- */

/* Library Function - Multiple Matches With Different Base Names
    sprintf_s
    swprintf_s
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

int __cdecl FID_conflict_sprintf_s(wchar_t *_Dst,size_t _SizeInWords,wchar_t *_Format,...)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 in_R9;
  undefined8 local_res20;
  
  local_res20 = in_R9;
  puVar2 = (undefined8 *)FUN_180007dc0();
  iVar1 = __stdio_common_vsprintf_s(*puVar2,_Dst,_SizeInWords,_Format,0,&local_res20);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  return iVar1;
}

/* ---- FUNC 00045A58 START_PROCESS (6 bytes) ---- */

void START_PROCESS(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180045a58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  START_PROCESS();
  return;
}

/* ---- FUNC 00045A60 FUN_180045a60 (27 bytes) ---- */

undefined8 * FUN_180045a60(undefined8 *param_1)

{
  *param_1 = SLMWrap::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  return param_1;
}

/* ---- FUNC 00045A80 FUN_180045a80 (130 bytes) ---- */

undefined8 * FUN_180045a80(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = SLMWrap::vftable;
  if ((longlong *)param_1[1] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[1] + 0x10))();
    param_1[1] = 0;
  }
  if ((longlong *)param_1[2] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[2] + 0x10))();
    param_1[2] = 0;
  }
  if (*(char *)(param_1 + 3) != '\0') {
    CoUninitialize();
  }
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

/* ---- FUNC 00045B10 FUN_180045b10 (103 bytes) ---- */

BSTR FUN_180045b10(LPCSTR param_1)

{
  longlong lVar1;
  UINT ui;
  BSTR lpWideCharStr;
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  ui = (UINT)lVar1;
  lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,ui);
  *lpWideCharStr = L'\0';
  if (lVar1 != 0) {
    if (0xf < *(ulonglong *)(param_1 + 0x18)) {
      param_1 = *(LPCSTR *)param_1;
    }
    MultiByteToWideChar(0,0,param_1,-1,lpWideCharStr,ui + 1);
  }
  return lpWideCharStr;
}

/* ---- FUNC 00045B80 FUN_180045b80 (393 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 FUN_180045b80(longlong param_1,LPCSTR param_2,longlong *param_3)

{
  longlong *plVar1;
  void *pvVar2;
  longlong lVar3;
  int iVar4;
  BSTR bstrString;
  void *pvVar5;
  undefined1 uVar6;
  UINT ui;
  byte *lpMultiByteStr;
  undefined1 auStackY_a8 [32];
  undefined1 local_74 [4];
  BSTR local_70;
  undefined8 local_68;
  byte local_60;
  undefined7 uStack_5f;
  longlong local_50;
  ulonglong local_48;
  ulonglong local_40;
  
  local_68 = 0xfffffffffffffffe;
  local_40 = DAT_1800791f8 ^ (ulonglong)auStackY_a8;
  uVar6 = 0;
  bstrString = FUN_180045b10(param_2);
  local_50 = 0;
  local_48 = 0xf;
  local_60 = 0;
  FUN_18000ad20((longlong *)&local_60,&DAT_1800579d0,0);
  lVar3 = local_50;
  ui = (UINT)local_50;
  local_70 = SysAllocStringLen((OLECHAR *)0x0,ui);
  *local_70 = L'\0';
  if (lVar3 != 0) {
    lpMultiByteStr = &local_60;
    if (0xf < local_48) {
      lpMultiByteStr = (byte *)CONCAT71(uStack_5f,local_60);
    }
    MultiByteToWideChar(0,0,(LPCSTR)lpMultiByteStr,-1,local_70,ui + 1);
  }
  if (0xf < local_48) {
    pvVar2 = (void *)CONCAT71(uStack_5f,local_60);
    pvVar5 = pvVar2;
    if (0xfff < local_48 + 1) {
      if ((local_60 & 0x1f) != 0) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      pvVar5 = *(void **)((longlong)pvVar2 - 8);
      if (pvVar2 <= pvVar5) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      if ((ulonglong)((longlong)pvVar2 - (longlong)pvVar5) < 8) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      if (0x27 < (ulonglong)((longlong)pvVar2 - (longlong)pvVar5)) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
    }
    operator_delete(pvVar5);
  }
  plVar1 = *(longlong **)(param_1 + 0x10);
  if (plVar1 == (longlong *)0x0) {
    FUN_18000ad20(param_3,"appinit.dll is either missing or unregistered.",0x2e);
  }
  else {
    iVar4 = (**(code **)(*plVar1 + 0x38))(plVar1,bstrString,local_74,&local_70);
    if (-1 < iVar4) {
      uVar6 = 1;
    }
  }
  SysFreeString(bstrString);
  SysFreeString(local_70);
  return uVar6;
}

/* ---- FUNC 00045D10 FUN_180045d10 (29 bytes) ---- */

ulonglong FUN_180045d10(longlong *param_1,longlong *param_2)

{
  int iVar1;
  LPSTR lpMultiByteStr;
  size_t sVar2;
  longlong lVar3;
  __uint64 _Var5;
  longlong lVar4;
  
  if (*param_1 != 0) {
    sVar2 = 0xffffffffffffffff;
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (*(short *)(*param_1 + lVar3 * 2) != 0);
    _Var5 = lVar4 + 2;
    lpMultiByteStr = operator_new__(_Var5);
    iVar1 = WideCharToMultiByte(0,0,(LPCWSTR)*param_1,-1,lpMultiByteStr,(int)_Var5,(LPCSTR)0x0,
                                (LPBOOL)0x0);
    lpMultiByteStr[(longlong)iVar1 + -1] = '\0';
    do {
      sVar2 = sVar2 + 1;
    } while (lpMultiByteStr[sVar2] != '\0');
    FUN_18000ad20(param_2,lpMultiByteStr,sVar2);
    operator_delete__(lpMultiByteStr);
    return _Var5 & 0xffffffff;
  }
  return 0;
}

/* ---- FUNC 00045D2D FUN_180045d2d (159 bytes) ---- */

ulonglong FUN_180045d2d(void)

{
  int iVar1;
  longlong in_RAX;
  LPSTR lpMultiByteStr;
  size_t sVar2;
  longlong *unaff_RBP;
  longlong lVar3;
  __uint64 _Var5;
  undefined8 *unaff_R14;
  longlong lVar4;
  
  sVar2 = 0xffffffffffffffff;
  lVar3 = -1;
  do {
    lVar4 = lVar3;
    lVar3 = lVar4 + 1;
  } while (*(short *)(in_RAX + lVar3 * 2) != 0);
  _Var5 = lVar4 + 2;
  lpMultiByteStr = operator_new__(_Var5);
  iVar1 = WideCharToMultiByte(0,0,(LPCWSTR)*unaff_R14,-1,lpMultiByteStr,(int)_Var5,(LPCSTR)0x0,
                              (LPBOOL)0x0);
  lpMultiByteStr[(longlong)iVar1 + -1] = '\0';
  do {
    sVar2 = sVar2 + 1;
  } while (lpMultiByteStr[sVar2] != '\0');
  FUN_18000ad20(unaff_RBP,lpMultiByteStr,sVar2);
  operator_delete__(lpMultiByteStr);
  return _Var5 & 0xffffffff;
}

/* ---- FUNC 00045DCC FUN_180045dcc (12 bytes) ---- */

void FUN_180045dcc(void)

{
  return;
}

/* ---- FUNC 00045DE0 FUN_180045de0 (54 bytes) ---- */

bool FUN_180045de0(longlong param_1)

{
  int iVar1;
  
  if (*(longlong **)(param_1 + 8) != (longlong *)0x0) {
    iVar1 = (**(code **)(**(longlong **)(param_1 + 8) + 0x30))();
    return -1 < iVar1;
  }
  return false;
}

/* ---- FUNC 00045E20 FUN_180045e20 (65 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 FUN_180045e20(longlong param_1,LPCSTR param_2,int *param_3,longlong *param_4)

{
  void *pvVar1;
  longlong lVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar5;
  BSTR bstrString;
  BSTR lpWideCharStr;
  void *pvVar6;
  undefined1 uVar7;
  UINT ui;
  byte *lpMultiByteStr;
  undefined1 auStackY_c8 [32];
  int local_88 [2];
  BSTR local_80;
  byte local_78;
  undefined7 uStack_77;
  longlong local_68;
  ulonglong local_60;
  ulonglong local_58;
  
  local_58 = DAT_1800791f8 ^ (ulonglong)auStackY_c8;
  uVar7 = 0;
  cVar3 = FUN_180045b80(param_1,param_2,param_4);
  uVar4 = 0;
  if ((cVar3 != '\0') && (uVar4 = uVar7, *(longlong *)(param_1 + 8) != 0)) {
    local_88[0] = 0;
    bstrString = FUN_180045b10(param_2);
    local_68 = 0;
    local_60 = 0xf;
    local_78 = 0;
    FUN_18000ad20((longlong *)&local_78,&DAT_1800579d0,0);
    lVar2 = local_68;
    ui = (UINT)local_68;
    lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,ui);
    *lpWideCharStr = L'\0';
    if (lVar2 != 0) {
      lpMultiByteStr = &local_78;
      if (0xf < local_60) {
        lpMultiByteStr = (byte *)CONCAT71(uStack_77,local_78);
      }
      MultiByteToWideChar(0,0,(LPCSTR)lpMultiByteStr,-1,lpWideCharStr,ui + 1);
    }
    if (0xf < local_60) {
      pvVar1 = (void *)CONCAT71(uStack_77,local_78);
      pvVar6 = pvVar1;
      if (0xfff < local_60 + 1) {
        if ((local_78 & 0x1f) != 0) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        pvVar6 = *(void **)((longlong)pvVar1 - 8);
        if (pvVar1 <= pvVar6) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        if ((ulonglong)((longlong)pvVar1 - (longlong)pvVar6) < 8) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        if (0x27 < (ulonglong)((longlong)pvVar1 - (longlong)pvVar6)) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
      }
      operator_delete(pvVar6);
    }
    local_68 = 0;
    local_60 = 0xf;
    local_78 = 0;
    iVar5 = (**(code **)(**(longlong **)(param_1 + 8) + 0x18))
                      (*(longlong **)(param_1 + 8),bstrString,lpWideCharStr,local_88);
    if ((-1 < iVar5) && (local_88[0] != 0)) {
      *param_3 = local_88[0];
      uVar4 = 1;
    }
    SysFreeString(bstrString);
    SysFreeString(lpWideCharStr);
    FUN_180045d10((longlong *)&local_80,param_4);
    SysFreeString(local_80);
  }
  return uVar4;
}

/* ---- FUNC 00045E61 FUN_180045e61 (25 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 FUN_180045e61(void)

{
  void *pvVar1;
  longlong lVar2;
  int iVar3;
  BSTR bstrString;
  BSTR lpWideCharStr;
  void *pvVar4;
  undefined1 unaff_BL;
  UINT ui;
  longlong unaff_RSI;
  LPCSTR unaff_RDI;
  LPCSTR lpMultiByteStr;
  int *unaff_R12;
  longlong *unaff_R15;
  bool in_ZF;
  int iStack0000000000000040;
  BSTR in_stack_00000048;
  byte bStack0000000000000050;
  undefined7 uStack0000000000000051;
  longlong in_stack_00000060;
  ulonglong in_stack_00000068;
  
  if (!in_ZF) {
    iStack0000000000000040 = 0;
    bstrString = FUN_180045b10(unaff_RDI);
    in_stack_00000060 = 0;
    in_stack_00000068 = 0xf;
    bStack0000000000000050 = 0;
    FUN_18000ad20((longlong *)&stack0x00000050,&DAT_1800579d0,0);
    lVar2 = in_stack_00000060;
    ui = (UINT)in_stack_00000060;
    lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,ui);
    *lpWideCharStr = L'\0';
    if (lVar2 != 0) {
      lpMultiByteStr = (LPCSTR)&stack0x00000050;
      if (0xf < in_stack_00000068) {
        lpMultiByteStr = (LPCSTR)CONCAT71(uStack0000000000000051,bStack0000000000000050);
      }
      MultiByteToWideChar(0,0,lpMultiByteStr,-1,lpWideCharStr,ui + 1);
    }
    if (0xf < in_stack_00000068) {
      pvVar1 = (void *)CONCAT71(uStack0000000000000051,bStack0000000000000050);
      pvVar4 = pvVar1;
      if (0xfff < in_stack_00000068 + 1) {
        if ((bStack0000000000000050 & 0x1f) != 0) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        pvVar4 = *(void **)((longlong)pvVar1 - 8);
        if (pvVar1 <= pvVar4) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        if ((ulonglong)((longlong)pvVar1 - (longlong)pvVar4) < 8) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        if (0x27 < (ulonglong)((longlong)pvVar1 - (longlong)pvVar4)) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
      }
      operator_delete(pvVar4);
    }
    in_stack_00000060 = 0;
    in_stack_00000068 = 0xf;
    bStack0000000000000050 = '\0';
    iVar3 = (**(code **)(**(longlong **)(unaff_RSI + 8) + 0x18))
                      (*(longlong **)(unaff_RSI + 8),bstrString,lpWideCharStr,&stack0x00000040,0);
    if ((-1 < iVar3) && (iStack0000000000000040 != 0)) {
      *unaff_R12 = iStack0000000000000040;
      unaff_BL = 1;
    }
    SysFreeString(bstrString);
    SysFreeString(lpWideCharStr);
    FUN_180045d10((longlong *)&stack0x00000048,unaff_R15);
    SysFreeString(in_stack_00000048);
  }
  return unaff_BL;
}

/* ---- FUNC 00045E7A FUN_180045e7a (152 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000180045f12) */
/* WARNING: Removing unreachable block (ram,0x000180045ee6) */
/* WARNING: Removing unreachable block (ram,0x000180045f22) */
/* WARNING: Removing unreachable block (ram,0x000180045f27) */
/* WARNING: Removing unreachable block (ram,0x000180045f2e) */
/* WARNING: Removing unreachable block (ram,0x000180045f37) */
/* WARNING: Removing unreachable block (ram,0x000180045f3e) */
/* WARNING: Removing unreachable block (ram,0x000180045f47) */
/* WARNING: Removing unreachable block (ram,0x000180045f4e) */
/* WARNING: Removing unreachable block (ram,0x000180045f54) */
/* WARNING: Removing unreachable block (ram,0x000180045f5b) */
/* WARNING: Removing unreachable block (ram,0x000180045f5e) */

undefined1 FUN_180045e7a(void)

{
  int iVar1;
  BSTR bstrString;
  BSTR lpWideCharStr;
  undefined1 unaff_BL;
  longlong unaff_RSI;
  LPCSTR unaff_RDI;
  UINT *unaff_R12;
  UINT ui;
  longlong unaff_R13;
  longlong *unaff_R15;
  UINT UStack0000000000000040;
  BSTR in_stack_00000048;
  CHAR in_stack_00000050;
  
  ui = (UINT)unaff_R13;
  UStack0000000000000040 = ui;
  bstrString = FUN_180045b10(unaff_RDI);
  in_stack_00000050 = (CHAR)unaff_R13;
  FUN_18000ad20((longlong *)&stack0x00000050,&DAT_1800579d0,0);
  lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,ui);
  *lpWideCharStr = (OLECHAR)unaff_R13;
  if (unaff_R13 != 0) {
    MultiByteToWideChar(0,0,&stack0x00000050,-1,lpWideCharStr,ui + 1);
  }
  in_stack_00000050 = (CHAR)unaff_R13;
  iVar1 = (**(code **)(**(longlong **)(unaff_RSI + 8) + 0x18))
                    (*(longlong **)(unaff_RSI + 8),bstrString,lpWideCharStr,&stack0x00000040);
  if ((-1 < iVar1) && (UStack0000000000000040 != 0)) {
    *unaff_R12 = UStack0000000000000040;
    unaff_BL = 1;
  }
  SysFreeString(bstrString);
  SysFreeString(lpWideCharStr);
  FUN_180045d10((longlong *)&stack0x00000048,unaff_R15);
  SysFreeString(in_stack_00000048);
  return unaff_BL;
}

/* ---- FUNC 00045F12 FUN_180045f12 (220 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 FUN_180045f12(void)

{
  int iVar1;
  longlong in_RAX;
  void *pvVar2;
  undefined1 unaff_BL;
  longlong unaff_RSI;
  BSTR unaff_RDI;
  int *unaff_R12;
  BSTR unaff_R14;
  longlong *unaff_R15;
  int in_stack_00000040;
  BSTR in_stack_00000048;
  undefined1 uStack0000000000000050;
  
  pvVar2 = _uStack0000000000000050;
  if (0xfff < in_RAX + 1U) {
    if (((ulonglong)_uStack0000000000000050 & 0x1f) != 0) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    pvVar2 = *(void **)((longlong)_uStack0000000000000050 + -8);
    if (_uStack0000000000000050 <= pvVar2) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    if ((ulonglong)((longlong)_uStack0000000000000050 - (longlong)pvVar2) < 8) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    if (0x27 < (ulonglong)((longlong)_uStack0000000000000050 - (longlong)pvVar2)) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
  }
  operator_delete(pvVar2);
  iVar1 = (**(code **)(**(longlong **)(unaff_RSI + 8) + 0x18))();
  if ((-1 < iVar1) && (in_stack_00000040 != 0)) {
    *unaff_R12 = in_stack_00000040;
    unaff_BL = 1;
  }
  SysFreeString(unaff_R14);
  SysFreeString(unaff_RDI);
  FUN_180045d10((longlong *)&stack0x00000048,unaff_R15);
  SysFreeString(in_stack_00000048);
  return unaff_BL;
}

/* ---- FUNC 00045FEE FUN_180045fee (28 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180045fee(void)

{
  return;
}

/* ---- FUNC 00046010 FUN_180046010 (131 bytes) ---- */

undefined8 FUN_180046010(longlong param_1,undefined8 param_2,undefined4 *param_3,longlong *param_4)

{
  longlong *plVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 local_res8 [2];
  BSTR local_18 [2];
  
  plVar1 = *(longlong **)(param_1 + 8);
  uVar3 = 0;
  if ((plVar1 != (longlong *)0x0) && ((int)param_2 != 0)) {
    local_18[0] = (BSTR)0x0;
    local_res8[0] = 0;
    iVar2 = (**(code **)(*plVar1 + 0x38))(plVar1,param_2,local_res8,local_18);
    if (-1 < iVar2) {
      if (local_18[0] == (BSTR)0x0) {
        return 0;
      }
      FUN_180045d10((longlong *)local_18,param_4);
      uVar3 = 1;
      *param_3 = local_res8[0];
    }
    if (local_18[0] != (BSTR)0x0) {
      SysFreeString(local_18[0]);
    }
  }
  return uVar3;
}

/* ---- FUNC 000460A0 FUN_1800460a0 (118 bytes) ---- */

ulonglong FUN_1800460a0(longlong param_1)

{
  HRESULT HVar1;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  LPVOID *ppv;
  LPVOID *ppv_00;
  
  ppv = (LPVOID *)(param_1 + 0x10);
  if (*(longlong *)(param_1 + 0x10) == 0) {
    HVar1 = CoCreateInstance((IID *)&DAT_180057960,(LPUNKNOWN)0x0,1,(IID *)&DAT_180057920,ppv);
    ppv = (LPVOID *)CONCAT44(extraout_var,HVar1);
  }
  ppv_00 = (LPVOID *)(param_1 + 8);
  if (*ppv_00 == (LPVOID)0x0) {
    HVar1 = CoCreateInstance((IID *)&DAT_1800577f0,(LPUNKNOWN)0x0,1,(IID *)&DAT_180057850,ppv_00);
    ppv = (LPVOID *)CONCAT44(extraout_var_00,HVar1);
    if ((HVar1 < 0) || (*ppv_00 == (LPVOID)0x0)) {
      return (ulonglong)ppv & 0xffffffffffffff00;
    }
  }
  return CONCAT71((int7)((ulonglong)ppv >> 8),1);
}

/* ---- FUNC 00046120 FUN_180046120 (66 bytes) ---- */

bool FUN_180046120(longlong param_1,LPCSTR param_2)

{
  undefined8 *puVar1;
  int iVar2;
  BSTR bstrString;
  longlong *local_res8;
  
  puVar1 = *(undefined8 **)(param_1 + 8);
  if (puVar1 != (undefined8 *)0x0) {
    local_res8 = (longlong *)0x0;
    iVar2 = (**(code **)*puVar1)(puVar1,&DAT_180057870,&local_res8);
    if ((-1 < iVar2) && (local_res8 != (longlong *)0x0)) {
      bstrString = FUN_180045b10(param_2);
      iVar2 = (**(code **)(*local_res8 + 0x30))(local_res8,bstrString);
      SysFreeString(bstrString);
      (**(code **)(*local_res8 + 0x10))();
      return -1 < iVar2;
    }
  }
  return false;
}

/* ---- FUNC 00046162 FUN_180046162 (81 bytes) ---- */

undefined1 FUN_180046162(LPCSTR param_1)

{
  int iVar1;
  BSTR bstrString;
  undefined1 unaff_SIL;
  longlong *in_stack_00000030;
  
  bstrString = FUN_180045b10(param_1);
  iVar1 = (**(code **)(*in_stack_00000030 + 0x30))(in_stack_00000030,bstrString);
  if (-1 < iVar1) {
    unaff_SIL = 1;
  }
  SysFreeString(bstrString);
  (**(code **)(*in_stack_00000030 + 0x10))();
  return unaff_SIL;
}

/* ---- FUNC 000461B3 FUN_1800461b3 (15 bytes) ---- */

undefined1 FUN_1800461b3(void)

{
  undefined1 unaff_SIL;
  
  return unaff_SIL;
}

/* ---- FUNC 000461D0 FUN_1800461d0 (75 bytes) ---- */

undefined8 FUN_1800461d0(longlong param_1)

{
  undefined8 in_RAX;
  undefined8 extraout_RAX;
  
  if (*(longlong **)(param_1 + 8) != (longlong *)0x0) {
    in_RAX = (**(code **)(**(longlong **)(param_1 + 8) + 0x10))();
    *(undefined8 *)(param_1 + 8) = 0;
  }
  if (*(longlong **)(param_1 + 0x10) != (longlong *)0x0) {
    in_RAX = (**(code **)(**(longlong **)(param_1 + 0x10) + 0x10))();
    *(undefined8 *)(param_1 + 0x10) = 0;
  }
  if (*(char *)(param_1 + 0x18) != '\0') {
    CoUninitialize();
    in_RAX = extraout_RAX;
  }
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
}

/* ---- FUNC 00046220 FUN_180046220 (75 bytes) ---- */

ulonglong FUN_180046220(longlong param_1,undefined8 param_2,undefined4 *param_3)

{
  longlong *plVar1;
  ulonglong in_RAX;
  undefined4 local_res8 [8];
  
  plVar1 = *(longlong **)(param_1 + 8);
  if (plVar1 != (longlong *)0x0) {
    local_res8[0] = 0;
    in_RAX = (**(code **)(*plVar1 + 0x28))(plVar1,param_2,1,local_res8);
    if (-1 < (int)in_RAX) {
      *param_3 = local_res8[0];
      return CONCAT71((uint7)(uint3)((uint)local_res8[0] >> 8),1);
    }
    *param_3 = 0;
  }
  return in_RAX & 0xffffffffffffff00;
}

/* ---- FUNC 0004626B operator_new (6 bytes) ---- */

void * __cdecl operator_new(__uint64 param_1)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004626b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = operator_new(param_1);
  return pvVar1;
}

/* ---- FUNC 00046271 operator_delete (6 bytes) ---- */

void __cdecl operator_delete(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180046271. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete(param_1);
  return;
}

/* ---- FUNC 00046277 operator_new[] (6 bytes) ---- */

void * __cdecl operator_new__(__uint64 param_1)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046277. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = operator_new__(param_1);
  return pvVar1;
}

/* ---- FUNC 0004627D operator_delete[] (6 bytes) ---- */

void __cdecl operator_delete__(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018004627d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete__(param_1);
  return;
}

/* ---- FUNC 00046283 AfxThrowInvalidArgException (6 bytes) ---- */

void __cdecl AfxThrowInvalidArgException(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180046283. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  AfxThrowInvalidArgException();
  return;
}

/* ---- FUNC 00046289 AfxThrowArchiveException (6 bytes) ---- */

void __cdecl AfxThrowArchiveException(int param_1,char *param_2)

{
                    /* WARNING: Could not recover jumptable at 0x000180046289. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AfxThrowArchiveException(param_1,param_2);
  return;
}

/* ---- FUNC 0004628F GetRuntimeClass (6 bytes) ---- */

CRuntimeClass * __thiscall CObject::GetRuntimeClass(CObject *this)

{
  CRuntimeClass *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004628f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetRuntimeClass(this);
  return pCVar1;
}

/* ---- FUNC 0004629B Read (6 bytes) ---- */

uint __thiscall CArchive::Read(CArchive *this,void *param_1,uint param_2)

{
  uint uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004629b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = Read(this,param_1,param_2);
  return uVar1;
}

/* ---- FUNC 000462A1 Write (6 bytes) ---- */

void __thiscall CArchive::Write(CArchive *this,void *param_1,uint param_2)

{
                    /* WARNING: Could not recover jumptable at 0x0001800462a1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Write(this,param_1,param_2);
  return;
}

/* ---- FUNC 000462A7 ReadCount (6 bytes) ---- */

__uint64 __thiscall CArchive::ReadCount(CArchive *this)

{
  __uint64 _Var1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800462a7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = ReadCount(this);
  return _Var1;
}

/* ---- FUNC 000462AD WriteCount (6 bytes) ---- */

void __thiscall CArchive::WriteCount(CArchive *this,__uint64 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0001800462ad. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WriteCount(this,param_1);
  return;
}

/* ---- FUNC 000462B3 GetRuntimeClass (6 bytes) ---- */

CRuntimeClass * __thiscall CPtrArray::GetRuntimeClass(CPtrArray *this)

{
  CRuntimeClass *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800462b3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetRuntimeClass(this);
  return pCVar1;
}

/* ---- FUNC 000462B9 CPtrArray (6 bytes) ---- */

void __thiscall CPtrArray::CPtrArray(CPtrArray *this)

{
                    /* WARNING: Could not recover jumptable at 0x0001800462b9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CPtrArray(this);
  return;
}

/* ---- FUNC 000462BF SetSize (6 bytes) ---- */

void __thiscall CPtrArray::SetSize(CPtrArray *this,__int64 param_1,__int64 param_2)

{
                    /* WARNING: Could not recover jumptable at 0x0001800462bf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetSize(this,param_1,param_2);
  return;
}

/* ---- FUNC 000462C5 SetAtGrow (6 bytes) ---- */

void __thiscall CPtrArray::SetAtGrow(CPtrArray *this,__int64 param_1,void *param_2)

{
                    /* WARNING: Could not recover jumptable at 0x0001800462c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetAtGrow(this,param_1,param_2);
  return;
}

/* ---- FUNC 000462CB Append (6 bytes) ---- */

__int64 __thiscall CPtrArray::Append(CPtrArray *this,CPtrArray *param_1)

{
  __int64 _Var1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800462cb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = Append(this,param_1);
  return _Var1;
}

/* ---- FUNC 000462D1 Copy (6 bytes) ---- */

void __thiscall CPtrArray::Copy(CPtrArray *this,CPtrArray *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0001800462d1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Copy(this,param_1);
  return;
}

/* ---- FUNC 000462D7 InsertAt (6 bytes) ---- */

void __thiscall CPtrArray::InsertAt(CPtrArray *this,__int64 param_1,void *param_2,__int64 param_3)

{
                    /* WARNING: Could not recover jumptable at 0x0001800462d7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InsertAt(this,param_1,param_2,param_3);
  return;
}

/* ---- FUNC 000462DD RemoveAt (6 bytes) ---- */

void __thiscall CPtrArray::RemoveAt(CPtrArray *this,__int64 param_1,__int64 param_2)

{
                    /* WARNING: Could not recover jumptable at 0x0001800462dd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RemoveAt(this,param_1,param_2);
  return;
}

/* ---- FUNC 000462E3 InsertAt (6 bytes) ---- */

void __thiscall CPtrArray::InsertAt(CPtrArray *this,__int64 param_1,CPtrArray *param_2)

{
                    /* WARNING: Could not recover jumptable at 0x0001800462e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InsertAt(this,param_1,param_2);
  return;
}

/* ---- FUNC 000462E9 ~CPtrArray (6 bytes) ---- */

void __thiscall CPtrArray::~CPtrArray(CPtrArray *this)

{
                    /* WARNING: Could not recover jumptable at 0x0001800462e9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CPtrArray(this);
  return;
}

/* ---- FUNC 000462EF CStringList (6 bytes) ---- */

void __thiscall CStringList::CStringList(CStringList *this,__int64 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0001800462ef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CStringList(this,param_1);
  return;
}

/* ---- FUNC 000462F5 AddTail (6 bytes) ---- */

__POSITION * __thiscall
CStringList::AddTail
          (CStringList *this,CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1)

{
  __POSITION *p_Var1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800462f5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  p_Var1 = AddTail(this,param_1);
  return p_Var1;
}

/* ---- FUNC 000462FB Find (6 bytes) ---- */

__POSITION * __thiscall CStringList::Find(CStringList *this,char *param_1,__POSITION *param_2)

{
  __POSITION *p_Var1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800462fb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  p_Var1 = Find(this,param_1,param_2);
  return p_Var1;
}

/* ---- FUNC 00046301 ~CStringList (6 bytes) ---- */

void __thiscall CStringList::~CStringList(CStringList *this)

{
                    /* WARNING: Could not recover jumptable at 0x000180046301. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CStringList(this);
  return;
}

/* ---- FUNC 00046307 Lookup (6 bytes) ---- */

int __thiscall
CMapStringToString::Lookup
          (CMapStringToString *this,char *param_1,
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046307. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = Lookup(this,param_1,param_2);
  return iVar1;
}

/* ---- FUNC 0004630D Create (6 bytes) ---- */

CPlex * __cdecl CPlex::Create(CPlex **param_1,__uint64 param_2,__uint64 param_3)

{
  CPlex *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004630d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = Create(param_1,param_2,param_3);
  return pCVar1;
}

/* ---- FUNC 00046313 FreeDataChain (6 bytes) ---- */

void __thiscall CPlex::FreeDataChain(CPlex *this)

{
                    /* WARNING: Could not recover jumptable at 0x000180046313. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FreeDataChain(this);
  return;
}

/* ---- FUNC 00046319 SerializeElements<ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>_> (6 bytes) ---- */

void __cdecl
SerializeElements<ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>_>
          (CArchive *param_1,CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2,
          __int64 param_3)

{
                    /* WARNING: Could not recover jumptable at 0x000180046319. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SerializeElements<ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>_>
            (param_1,param_2,param_3);
  return;
}

/* ---- FUNC 0004631F HashKey<char_const*___ptr64> (6 bytes) ---- */

uint __cdecl HashKey<char_const*___ptr64>(char *param_1)

{
  uint uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004631f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = HashKey<char_const*___ptr64>(param_1);
  return uVar1;
}

/* ---- FUNC 00046325 AfxVariantInit (6 bytes) ---- */

void __cdecl AfxVariantInit(tagVARIANT *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180046325. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AfxVariantInit(param_1);
  return;
}

/* ---- FUNC 0004632B CStringArray (6 bytes) ---- */

void __thiscall CStringArray::CStringArray(CStringArray *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018004632b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CStringArray(this);
  return;
}

/* ---- FUNC 00046331 SetSize (6 bytes) ---- */

void __thiscall CStringArray::SetSize(CStringArray *this,__int64 param_1,__int64 param_2)

{
                    /* WARNING: Could not recover jumptable at 0x000180046331. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetSize(this,param_1,param_2);
  return;
}

/* ---- FUNC 00046337 SetAtGrow (6 bytes) ---- */

void __thiscall CStringArray::SetAtGrow(CStringArray *this,__int64 param_1,char *param_2)

{
                    /* WARNING: Could not recover jumptable at 0x000180046337. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetAtGrow(this,param_1,param_2);
  return;
}

/* ---- FUNC 0004633D SetAtGrow (6 bytes) ---- */

void __thiscall
CStringArray::SetAtGrow
          (CStringArray *this,__int64 param_1,
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00018004633d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetAtGrow(this,param_1,param_2);
  return;
}

/* ---- FUNC 00046343 InsertAt (6 bytes) ---- */

void __thiscall
CStringArray::InsertAt
          (CStringArray *this,__int64 param_1,
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2,__int64 param_3)

{
                    /* WARNING: Could not recover jumptable at 0x000180046343. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InsertAt(this,param_1,param_2,param_3);
  return;
}

/* ---- FUNC 00046349 ~CStringArray (6 bytes) ---- */

void __thiscall CStringArray::~CStringArray(CStringArray *this)

{
                    /* WARNING: Could not recover jumptable at 0x000180046349. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CStringArray(this);
  return;
}

/* ---- FUNC 0004634F GetRuntimeClass (6 bytes) ---- */

CRuntimeClass * __thiscall CGdiObject::GetRuntimeClass(CGdiObject *this)

{
  CRuntimeClass *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004634f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetRuntimeClass(this);
  return pCVar1;
}

/* ---- FUNC 00046355 DeleteObject (6 bytes) ---- */

int __thiscall CGdiObject::DeleteObject(CGdiObject *this)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046355. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = DeleteObject(this);
  return iVar1;
}

/* ---- FUNC 0004635B GetRuntimeClass (6 bytes) ---- */

CRuntimeClass * __thiscall CBitmap::GetRuntimeClass(CBitmap *this)

{
  CRuntimeClass *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004635b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetRuntimeClass(this);
  return pCVar1;
}

/* ---- FUNC 00046361 DoModal (6 bytes) ---- */

__int64 __thiscall CDialog::DoModal(CDialog *this)

{
  __int64 _Var1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046361. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = DoModal(this);
  return _Var1;
}

/* ---- FUNC 00046367 ~CDialog (6 bytes) ---- */

void __thiscall CDialog::~CDialog(CDialog *this)

{
                    /* WARNING: Could not recover jumptable at 0x000180046367. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CDialog(this);
  return;
}

/* ---- FUNC 0004636D ~CButton (6 bytes) ---- */

void __thiscall CButton::~CButton(CButton *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018004636d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CButton(this);
  return;
}

/* ---- FUNC 00046373 ~CListBox (6 bytes) ---- */

void __thiscall CListBox::~CListBox(CListBox *this)

{
                    /* WARNING: Could not recover jumptable at 0x000180046373. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CListBox(this);
  return;
}

/* ---- FUNC 00046379 AfxMessageBox (6 bytes) ---- */

int __cdecl AfxMessageBox(char *param_1,uint param_2,uint param_3)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046379. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = AfxMessageBox(param_1,param_2,param_3);
  return iVar1;
}

/* ---- FUNC 0004637F AfxThrowMemoryException (6 bytes) ---- */

void __cdecl AfxThrowMemoryException(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018004637f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AfxThrowMemoryException();
  return;
}

/* ---- FUNC 00046385 AfxThrowOleException (6 bytes) ---- */

void __cdecl AfxThrowOleException(long param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180046385. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AfxThrowOleException(param_1);
  return;
}

/* ---- FUNC 0004638B CMapStringToString (6 bytes) ---- */

void __thiscall CMapStringToString::CMapStringToString(CMapStringToString *this,__int64 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018004638b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CMapStringToString(this,param_1);
  return;
}

/* ---- FUNC 00046391 operator[] (6 bytes) ---- */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> * __thiscall
CMapStringToString::operator[](CMapStringToString *this,char *param_1)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046391. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = operator[](this,param_1);
  return pCVar1;
}

/* ---- FUNC 00046397 ~CMapStringToString (6 bytes) ---- */

void __thiscall CMapStringToString::~CMapStringToString(CMapStringToString *this)

{
                    /* WARNING: Could not recover jumptable at 0x000180046397. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CMapStringToString(this);
  return;
}

/* ---- FUNC 0004639D COleVariant (6 bytes) ---- */

void __thiscall COleVariant::COleVariant(COleVariant *this,long param_1,ushort param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00018004639d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  COleVariant(this,param_1,param_2);
  return;
}

/* ---- FUNC 000463A3 Attach (6 bytes) ---- */

int __thiscall CGdiObject::Attach(CGdiObject *this,void *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800463a3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = Attach(this,param_1);
  return iVar1;
}

/* ---- FUNC 000463A9 DDX_Control (6 bytes) ---- */

void __cdecl DDX_Control(CDataExchange *param_1,int param_2,CWnd *param_3)

{
                    /* WARNING: Could not recover jumptable at 0x0001800463a9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DDX_Control(param_1,param_2,param_3);
  return;
}

/* ---- FUNC 000463AF OnCmdMsg (6 bytes) ---- */

int __thiscall
CCmdTarget::OnCmdMsg
          (CCmdTarget *this,uint param_1,int param_2,void *param_3,AFX_CMDHANDLERINFO *param_4)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800463af. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnCmdMsg(this,param_1,param_2,param_3,param_4);
  return iVar1;
}

/* ---- FUNC 000463B5 IsInvokeAllowed (6 bytes) ---- */

int __thiscall CCmdTarget::IsInvokeAllowed(CCmdTarget *this,long param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800463b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = IsInvokeAllowed(this,param_1);
  return iVar1;
}

/* ---- FUNC 000463BB GetDispatchIID (6 bytes) ---- */

int __thiscall CCmdTarget::GetDispatchIID(CCmdTarget *this,_GUID *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800463bb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = GetDispatchIID(this,param_1);
  return iVar1;
}

/* ---- FUNC 000463C1 GetTypeInfoCount (6 bytes) ---- */

uint __thiscall CCmdTarget::GetTypeInfoCount(CCmdTarget *this)

{
  uint uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800463c1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = GetTypeInfoCount(this);
  return uVar1;
}

/* ---- FUNC 000463C7 GetTypeLibCache (6 bytes) ---- */

CTypeLibCache * __thiscall CCmdTarget::GetTypeLibCache(CCmdTarget *this)

{
  CTypeLibCache *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800463c7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetTypeLibCache(this);
  return pCVar1;
}

/* ---- FUNC 000463CD GetTypeLib (6 bytes) ---- */

long __thiscall CCmdTarget::GetTypeLib(CCmdTarget *this,ulong param_1,ITypeLib **param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800463cd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = GetTypeLib(this,param_1,param_2);
  return lVar1;
}

/* ---- FUNC 000463D3 GetCommandMap (6 bytes) ---- */

AFX_OLECMDMAP * __thiscall CCmdTarget::GetCommandMap(CCmdTarget *this)

{
  AFX_OLECMDMAP *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800463d3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = GetCommandMap(this);
  return pAVar1;
}

/* ---- FUNC 000463D9 GetDispatchMap (6 bytes) ---- */

AFX_DISPMAP * __thiscall CCmdTarget::GetDispatchMap(CCmdTarget *this)

{
  AFX_DISPMAP *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800463d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = GetDispatchMap(this);
  return pAVar1;
}

/* ---- FUNC 000463DF GetConnectionMap (6 bytes) ---- */

AFX_CONNECTIONMAP * __thiscall CCmdTarget::GetConnectionMap(CCmdTarget *this)

{
  AFX_CONNECTIONMAP *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800463df. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = GetConnectionMap(this);
  return pAVar1;
}

/* ---- FUNC 000463E5 GetEventSinkMap (6 bytes) ---- */

AFX_EVENTSINKMAP * __thiscall CCmdTarget::GetEventSinkMap(CCmdTarget *this)

{
  AFX_EVENTSINKMAP *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800463e5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = GetEventSinkMap(this);
  return pAVar1;
}

/* ---- FUNC 000463EB OnCreateAggregates (6 bytes) ---- */

int __thiscall CCmdTarget::OnCreateAggregates(CCmdTarget *this)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800463eb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnCreateAggregates(this);
  return iVar1;
}

/* ---- FUNC 000463F1 GetInterfaceHook (6 bytes) ---- */

IUnknown * __thiscall CCmdTarget::GetInterfaceHook(CCmdTarget *this,void *param_1)

{
  IUnknown *pIVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800463f1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pIVar1 = GetInterfaceHook(this,param_1);
  return pIVar1;
}

/* ---- FUNC 000463F7 GetExtraConnectionPoints (6 bytes) ---- */

int __thiscall CCmdTarget::GetExtraConnectionPoints(CCmdTarget *this,CPtrArray *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800463f7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = GetExtraConnectionPoints(this,param_1);
  return iVar1;
}

/* ---- FUNC 000463FD GetConnectionHook (6 bytes) ---- */

IConnectionPoint * __thiscall CCmdTarget::GetConnectionHook(CCmdTarget *this,_GUID *param_1)

{
  IConnectionPoint *pIVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800463fd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pIVar1 = GetConnectionHook(this,param_1);
  return pIVar1;
}

/* ---- FUNC 00046403 CWnd (6 bytes) ---- */

void __thiscall CWnd::CWnd(CWnd *this)

{
                    /* WARNING: Could not recover jumptable at 0x000180046403. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CWnd(this);
  return;
}

/* ---- FUNC 00046409 PreSubclassWindow (6 bytes) ---- */

void __thiscall CWnd::PreSubclassWindow(CWnd *this)

{
                    /* WARNING: Could not recover jumptable at 0x000180046409. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  PreSubclassWindow(this);
  return;
}

/* ---- FUNC 0004640F SubclassDlgItem (6 bytes) ---- */

int __thiscall CWnd::SubclassDlgItem(CWnd *this,uint param_1,CWnd *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004640f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = SubclassDlgItem(this,param_1,param_2);
  return iVar1;
}

/* ---- FUNC 00046415 Create (6 bytes) ---- */

int __thiscall
CWnd::Create(CWnd *this,char *param_1,char *param_2,ulong param_3,tagRECT *param_4,CWnd *param_5,
            uint param_6,CCreateContext *param_7)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046415. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = Create(this,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return iVar1;
}

/* ---- FUNC 0004641B CreateEx (6 bytes) ---- */

int __thiscall
CWnd::CreateEx(CWnd *this,ulong param_1,char *param_2,char *param_3,ulong param_4,int param_5,
              int param_6,int param_7,int param_8,HWND__ *param_9,HMENU__ *param_10,void *param_11)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004641b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = CreateEx(this,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                   param_10,param_11);
  return iVar1;
}

/* ---- FUNC 00046421 CreateEx (6 bytes) ---- */

int __thiscall
CWnd::CreateEx(CWnd *this,ulong param_1,char *param_2,char *param_3,ulong param_4,tagRECT *param_5,
              CWnd *param_6,uint param_7,void *param_8)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046421. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = CreateEx(this,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return iVar1;
}

/* ---- FUNC 00046427 DestroyWindow (6 bytes) ---- */

int __thiscall CWnd::DestroyWindow(CWnd *this)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046427. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = DestroyWindow(this);
  return iVar1;
}

/* ---- FUNC 0004642D PreCreateWindow (6 bytes) ---- */

int __thiscall CWnd::PreCreateWindow(CWnd *this,tagCREATESTRUCTA *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004642d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = PreCreateWindow(this,param_1);
  return iVar1;
}

/* ---- FUNC 00046433 CalcWindowRect (6 bytes) ---- */

void __thiscall CWnd::CalcWindowRect(CWnd *this,tagRECT *param_1,uint param_2)

{
                    /* WARNING: Could not recover jumptable at 0x000180046433. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CalcWindowRect(this,param_1,param_2);
  return;
}

/* ---- FUNC 00046439 SetWindowTextA (6 bytes) ---- */

void __thiscall CWnd::SetWindowTextA(CWnd *this,char *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180046439. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetWindowTextA(this,param_1);
  return;
}

/* ---- FUNC 0004643F GetMenu (6 bytes) ---- */

CMenu * __thiscall CWnd::GetMenu(CWnd *this)

{
  CMenu *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004643f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetMenu(this);
  return pCVar1;
}

/* ---- FUNC 00046445 SetMenu (6 bytes) ---- */

int __thiscall CWnd::SetMenu(CWnd *this,CMenu *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046445. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = SetMenu(this,param_1);
  return iVar1;
}

/* ---- FUNC 0004644B OnToolHitTest (6 bytes) ---- */

__int64 __thiscall CWnd::OnToolHitTest(void)

{
  __int64 _Var1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004644b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = OnToolHitTest();
  return _Var1;
}

/* ---- FUNC 00046451 EnableWindow (6 bytes) ---- */

int __thiscall CWnd::EnableWindow(CWnd *this,int param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046451. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = EnableWindow(this,param_1);
  return iVar1;
}

/* ---- FUNC 00046457 GetScrollBarCtrl (6 bytes) ---- */

CScrollBar * __thiscall CWnd::GetScrollBarCtrl(CWnd *this,int param_1)

{
  CScrollBar *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046457. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetScrollBarCtrl(this,param_1);
  return pCVar1;
}

/* ---- FUNC 0004645D WinHelpA (6 bytes) ---- */

void __thiscall CWnd::WinHelpA(CWnd *this,__uint64 param_1,uint param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00018004645d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WinHelpA(this,param_1,param_2);
  return;
}

/* ---- FUNC 00046463 HtmlHelpA (6 bytes) ---- */

void __thiscall CWnd::HtmlHelpA(CWnd *this,__uint64 param_1,uint param_2)

{
                    /* WARNING: Could not recover jumptable at 0x000180046463. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HtmlHelpA(this,param_1,param_2);
  return;
}

/* ---- FUNC 00046469 WinHelpInternal (6 bytes) ---- */

void __thiscall CWnd::WinHelpInternal(CWnd *this,__uint64 param_1,uint param_2)

{
                    /* WARNING: Could not recover jumptable at 0x000180046469. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WinHelpInternal(this,param_1,param_2);
  return;
}

/* ---- FUNC 0004646F ContinueModal (6 bytes) ---- */

int __thiscall CWnd::ContinueModal(CWnd *this)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004646f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = ContinueModal(this);
  return iVar1;
}

/* ---- FUNC 00046475 EndModalLoop (6 bytes) ---- */

void __thiscall CWnd::EndModalLoop(CWnd *this,int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180046475. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EndModalLoop(this,param_1);
  return;
}

/* ---- FUNC 0004647B OnDrawIconicThumbnailOrLivePreview (6 bytes) ---- */

void __thiscall CWnd::OnDrawIconicThumbnailOrLivePreview(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018004647b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OnDrawIconicThumbnailOrLivePreview();
  return;
}

/* ---- FUNC 00046481 GetInterfaceMap (6 bytes) ---- */

AFX_INTERFACEMAP * __thiscall CWnd::GetInterfaceMap(CWnd *this)

{
  AFX_INTERFACEMAP *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046481. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = GetInterfaceMap(this);
  return pAVar1;
}

/* ---- FUNC 00046487 EnsureStdObj (6 bytes) ---- */

long __thiscall CWnd::EnsureStdObj(CWnd *this)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046487. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = EnsureStdObj(this);
  return lVar1;
}

/* ---- FUNC 0004648D get_accParent (6 bytes) ---- */

long __thiscall CWnd::get_accParent(CWnd *this,IDispatch **param_1)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004648d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accParent(this,param_1);
  return lVar1;
}

/* ---- FUNC 00046493 get_accChildCount (6 bytes) ---- */

long __thiscall CWnd::get_accChildCount(CWnd *this,long *param_1)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046493. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accChildCount(this,param_1);
  return lVar1;
}

/* ---- FUNC 00046499 get_accChild (6 bytes) ---- */

long __thiscall CWnd::get_accChild(CWnd *this,tagVARIANT *param_1,IDispatch **param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046499. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accChild(this,param_1,param_2);
  return lVar1;
}

/* ---- FUNC 0004649F get_accName (6 bytes) ---- */

long __thiscall CWnd::get_accName(CWnd *this,tagVARIANT *param_1,wchar_t **param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004649f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accName(this,param_1,param_2);
  return lVar1;
}

/* ---- FUNC 000464A5 get_accValue (6 bytes) ---- */

long __thiscall CWnd::get_accValue(CWnd *this,tagVARIANT *param_1,wchar_t **param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800464a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accValue(this,param_1,param_2);
  return lVar1;
}

/* ---- FUNC 000464AB get_accDescription (6 bytes) ---- */

long __thiscall CWnd::get_accDescription(CWnd *this,tagVARIANT *param_1,wchar_t **param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800464ab. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accDescription(this,param_1,param_2);
  return lVar1;
}

/* ---- FUNC 000464B1 get_accRole (6 bytes) ---- */

long __thiscall CWnd::get_accRole(CWnd *this,tagVARIANT *param_1,tagVARIANT *param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800464b1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accRole(this,param_1,param_2);
  return lVar1;
}

/* ---- FUNC 000464B7 get_accState (6 bytes) ---- */

long __thiscall CWnd::get_accState(CWnd *this,tagVARIANT *param_1,tagVARIANT *param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800464b7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accState(this,param_1,param_2);
  return lVar1;
}

/* ---- FUNC 000464BD get_accHelp (6 bytes) ---- */

long __thiscall CWnd::get_accHelp(CWnd *this,tagVARIANT *param_1,wchar_t **param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800464bd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accHelp(this,param_1,param_2);
  return lVar1;
}

/* ---- FUNC 000464C3 get_accHelpTopic (6 bytes) ---- */

long __thiscall
CWnd::get_accHelpTopic(CWnd *this,wchar_t **param_1,tagVARIANT *param_2,long *param_3)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800464c3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accHelpTopic(this,param_1,param_2,param_3);
  return lVar1;
}

/* ---- FUNC 000464C9 get_accKeyboardShortcut (6 bytes) ---- */

long __thiscall CWnd::get_accKeyboardShortcut(CWnd *this,tagVARIANT *param_1,wchar_t **param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800464c9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accKeyboardShortcut(this,param_1,param_2);
  return lVar1;
}

/* ---- FUNC 000464CF get_accFocus (6 bytes) ---- */

long __thiscall CWnd::get_accFocus(CWnd *this,tagVARIANT *param_1)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800464cf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accFocus(this,param_1);
  return lVar1;
}

/* ---- FUNC 000464D5 get_accSelection (6 bytes) ---- */

long __thiscall CWnd::get_accSelection(CWnd *this,tagVARIANT *param_1)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800464d5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accSelection(this,param_1);
  return lVar1;
}

/* ---- FUNC 000464DB get_accDefaultAction (6 bytes) ---- */

long __thiscall CWnd::get_accDefaultAction(CWnd *this,tagVARIANT *param_1,wchar_t **param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800464db. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accDefaultAction(this,param_1,param_2);
  return lVar1;
}

/* ---- FUNC 000464E1 accSelect (6 bytes) ---- */

long __thiscall CWnd::accSelect(CWnd *this,long param_1,tagVARIANT *param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800464e1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = accSelect(this,param_1,param_2);
  return lVar1;
}

/* ---- FUNC 000464E7 accLocation (6 bytes) ---- */

long __thiscall
CWnd::accLocation(CWnd *this,long *param_1,long *param_2,long *param_3,long *param_4,
                 tagVARIANT *param_5)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800464e7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = accLocation(this,param_1,param_2,param_3,param_4,param_5);
  return lVar1;
}

/* ---- FUNC 000464ED accNavigate (6 bytes) ---- */

long __thiscall CWnd::accNavigate(CWnd *this,long param_1,tagVARIANT *param_2,tagVARIANT *param_3)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800464ed. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = accNavigate(this,param_1,param_2,param_3);
  return lVar1;
}

/* ---- FUNC 000464F3 accHitTest (6 bytes) ---- */

long __thiscall CWnd::accHitTest(CWnd *this,long param_1,long param_2,tagVARIANT *param_3)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800464f3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = accHitTest(this,param_1,param_2,param_3);
  return lVar1;
}

/* ---- FUNC 000464F9 accDoDefaultAction (6 bytes) ---- */

long __thiscall CWnd::accDoDefaultAction(CWnd *this,tagVARIANT *param_1)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800464f9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = accDoDefaultAction(this,param_1);
  return lVar1;
}

/* ---- FUNC 000464FF put_accName (6 bytes) ---- */

long __thiscall CWnd::put_accName(CWnd *this,tagVARIANT *param_1,wchar_t *param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800464ff. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = put_accName(this,param_1,param_2);
  return lVar1;
}

/* ---- FUNC 00046505 put_accValue (6 bytes) ---- */

long __thiscall CWnd::put_accValue(CWnd *this,tagVARIANT *param_1,wchar_t *param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046505. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = put_accValue(this,param_1,param_2);
  return lVar1;
}

/* ---- FUNC 0004650B SetProxy (6 bytes) ---- */

long __thiscall CWnd::SetProxy(CWnd *this,IAccessibleProxy *param_1)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004650b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = SetProxy(this,param_1);
  return lVar1;
}

/* ---- FUNC 00046511 CreateAccessibleProxy (6 bytes) ---- */

long __thiscall
CWnd::CreateAccessibleProxy(CWnd *this,__uint64 param_1,__int64 param_2,__int64 *param_3)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046511. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = CreateAccessibleProxy(this,param_1,param_2,param_3);
  return lVar1;
}

/* ---- FUNC 00046517 OnCommand (6 bytes) ---- */

int __thiscall CWnd::OnCommand(CWnd *this,__uint64 param_1,__int64 param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046517. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnCommand(this,param_1,param_2);
  return iVar1;
}

/* ---- FUNC 0004651D OnNotify (6 bytes) ---- */

int __thiscall CWnd::OnNotify(CWnd *this,__uint64 param_1,__int64 param_2,__int64 *param_3)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004651d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnNotify(this,param_1,param_2,param_3);
  return iVar1;
}

/* ---- FUNC 00046523 GetSuperWndProcAddr (6 bytes) ---- */

_func___int64_HWND___ptr_uint___uint64___int64 ** __thiscall CWnd::GetSuperWndProcAddr(CWnd *this)

{
  _func___int64_HWND___ptr_uint___uint64___int64 **pp_Var1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046523. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pp_Var1 = GetSuperWndProcAddr(this);
  return pp_Var1;
}

/* ---- FUNC 00046529 PreTranslateMessage (6 bytes) ---- */

int __thiscall CWnd::PreTranslateMessage(CWnd *this,tagMSG *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046529. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = PreTranslateMessage(this,param_1);
  return iVar1;
}

/* ---- FUNC 0004652F OnAmbientProperty (6 bytes) ---- */

int __thiscall
CWnd::OnAmbientProperty(CWnd *this,COleControlSite *param_1,long param_2,tagVARIANT *param_3)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004652f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnAmbientProperty(this,param_1,param_2,param_3);
  return iVar1;
}

/* ---- FUNC 00046535 WindowProc (6 bytes) ---- */

__int64 __thiscall CWnd::WindowProc(CWnd *this,uint param_1,__uint64 param_2,__int64 param_3)

{
  __int64 _Var1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046535. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = WindowProc(this,param_1,param_2,param_3);
  return _Var1;
}

/* ---- FUNC 0004653B OnWndMsg (6 bytes) ---- */

int __thiscall
CWnd::OnWndMsg(CWnd *this,uint param_1,__uint64 param_2,__int64 param_3,__int64 *param_4)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004653b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnWndMsg(this,param_1,param_2,param_3,param_4);
  return iVar1;
}

/* ---- FUNC 00046541 DefWindowProcA (6 bytes) ---- */

__int64 __thiscall CWnd::DefWindowProcA(CWnd *this,uint param_1,__uint64 param_2,__int64 param_3)

{
  __int64 _Var1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046541. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = DefWindowProcA(this,param_1,param_2,param_3);
  return _Var1;
}

/* ---- FUNC 00046547 PostNcDestroy (6 bytes) ---- */

void __thiscall CWnd::PostNcDestroy(CWnd *this)

{
                    /* WARNING: Could not recover jumptable at 0x000180046547. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  PostNcDestroy(this);
  return;
}

/* ---- FUNC 0004654D OnChildNotify (6 bytes) ---- */

int __thiscall
CWnd::OnChildNotify(CWnd *this,uint param_1,__uint64 param_2,__int64 param_3,__int64 *param_4)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004654d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnChildNotify(this,param_1,param_2,param_3,param_4);
  return iVar1;
}

/* ---- FUNC 00046553 OnTouchInputs (6 bytes) ---- */

int __thiscall CWnd::OnTouchInputs(CWnd *this,uint param_1,tagTOUCHINPUT *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046553. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnTouchInputs(this,param_1,param_2);
  return iVar1;
}

/* ---- FUNC 00046559 OnTouchInput (6 bytes) ---- */

int __thiscall CWnd::OnTouchInput(void)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046559. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnTouchInput();
  return iVar1;
}

/* ---- FUNC 0004655F GetGestureStatus (6 bytes) ---- */

ulong __thiscall CWnd::GetGestureStatus(void)

{
  ulong uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004655f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = GetGestureStatus();
  return uVar1;
}

/* ---- FUNC 00046565 OnGestureZoom (6 bytes) ---- */

int __thiscall CWnd::OnGestureZoom(void)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046565. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnGestureZoom();
  return iVar1;
}

/* ---- FUNC 0004656B OnGesturePan (6 bytes) ---- */

int __thiscall CWnd::OnGesturePan(void)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004656b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnGesturePan();
  return iVar1;
}

/* ---- FUNC 00046571 OnGestureRotate (6 bytes) ---- */

int __thiscall CWnd::OnGestureRotate(void)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046571. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnGestureRotate();
  return iVar1;
}

/* ---- FUNC 00046577 OnGestureTwoFingerTap (6 bytes) ---- */

int __thiscall CWnd::OnGestureTwoFingerTap(void)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046577. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnGestureTwoFingerTap();
  return iVar1;
}

/* ---- FUNC 0004657D OnGesturePressAndTap (6 bytes) ---- */

int __thiscall CWnd::OnGesturePressAndTap(void)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004657d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnGesturePressAndTap();
  return iVar1;
}

/* ---- FUNC 00046583 ResizeDynamicLayout (6 bytes) ---- */

void __thiscall CWnd::ResizeDynamicLayout(CWnd *this)

{
                    /* WARNING: Could not recover jumptable at 0x000180046583. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ResizeDynamicLayout(this);
  return;
}

/* ---- FUNC 00046589 CheckAutoCenter (6 bytes) ---- */

int __thiscall CWnd::CheckAutoCenter(CWnd *this)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046589. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = CheckAutoCenter(this);
  return iVar1;
}

/* ---- FUNC 0004658F IsFrameWnd (6 bytes) ---- */

int __thiscall CWnd::IsFrameWnd(CWnd *this)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004658f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = IsFrameWnd(this);
  return iVar1;
}

/* ---- FUNC 00046595 OnFinalRelease (6 bytes) ---- */

void __thiscall CWnd::OnFinalRelease(CWnd *this)

{
                    /* WARNING: Could not recover jumptable at 0x000180046595. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OnFinalRelease(this);
  return;
}

/* ---- FUNC 0004659B CreateControlContainer (6 bytes) ---- */

int __thiscall CWnd::CreateControlContainer(CWnd *this,COleControlContainer **param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004659b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = CreateControlContainer(this,param_1);
  return iVar1;
}

/* ---- FUNC 000465A1 CreateControlSite (6 bytes) ---- */

int __thiscall
CWnd::CreateControlSite
          (CWnd *this,COleControlContainer *param_1,COleControlSite **param_2,uint param_3,
          _GUID *param_4)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800465a1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = CreateControlSite(this,param_1,param_2,param_3,param_4);
  return iVar1;
}

/* ---- FUNC 000465A7 SetOccDialogInfo (6 bytes) ---- */

int __thiscall CWnd::SetOccDialogInfo(CWnd *this,_AFX_OCC_DIALOG_INFO *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800465a7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = SetOccDialogInfo(this,param_1);
  return iVar1;
}

/* ---- FUNC 000465AD GetOccDialogInfo (6 bytes) ---- */

_AFX_OCC_DIALOG_INFO * __thiscall CWnd::GetOccDialogInfo(CWnd *this)

{
  _AFX_OCC_DIALOG_INFO *p_Var1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800465ad. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  p_Var1 = GetOccDialogInfo(this);
  return p_Var1;
}

/* ---- FUNC 000465B3 GetMessageMap (6 bytes) ---- */

AFX_MSGMAP * __thiscall CWnd::GetMessageMap(CWnd *this)

{
  AFX_MSGMAP *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800465b3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = GetMessageMap(this);
  return pAVar1;
}

/* ---- FUNC 000465B9 GetRuntimeClass (6 bytes) ---- */

CRuntimeClass * __thiscall CDialog::GetRuntimeClass(CDialog *this)

{
  CRuntimeClass *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800465b9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetRuntimeClass(this);
  return pCVar1;
}

/* ---- FUNC 000465BF Create (6 bytes) ---- */

int __thiscall CDialog::Create(CDialog *this,char *param_1,CWnd *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800465bf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = Create(this,param_1,param_2);
  return iVar1;
}

/* ---- FUNC 000465C5 CreateIndirect (6 bytes) ---- */

int __thiscall
CDialog::CreateIndirect(CDialog *this,DLGTEMPLATE *param_1,CWnd *param_2,void *param_3)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800465c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = CreateIndirect(this,param_1,param_2,param_3);
  return iVar1;
}

/* ---- FUNC 000465CB CreateIndirect (6 bytes) ---- */

int __thiscall CDialog::CreateIndirect(CDialog *this,void *param_1,CWnd *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800465cb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = CreateIndirect(this,param_1,param_2);
  return iVar1;
}

/* ---- FUNC 000465D1 CDialog (6 bytes) ---- */

void __thiscall CDialog::CDialog(CDialog *this,uint param_1,CWnd *param_2)

{
                    /* WARNING: Could not recover jumptable at 0x0001800465d1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CDialog(this,param_1,param_2);
  return;
}

/* ---- FUNC 000465D7 OnInitDialog (6 bytes) ---- */

int __thiscall CDialog::OnInitDialog(CDialog *this)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800465d7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnInitDialog(this);
  return iVar1;
}

/* ---- FUNC 000465DD OnSetFont (6 bytes) ---- */

void __thiscall CDialog::OnSetFont(CDialog *this,CFont *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0001800465dd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OnSetFont(this,param_1);
  return;
}

/* ---- FUNC 000465E3 OnOK (6 bytes) ---- */

void __thiscall CDialog::OnOK(CDialog *this)

{
                    /* WARNING: Could not recover jumptable at 0x0001800465e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OnOK(this);
  return;
}

/* ---- FUNC 000465E9 OnCancel (6 bytes) ---- */

void __thiscall CDialog::OnCancel(CDialog *this)

{
                    /* WARNING: Could not recover jumptable at 0x0001800465e9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OnCancel(this);
  return;
}

/* ---- FUNC 000465EF PreTranslateMessage (6 bytes) ---- */

int __thiscall CDialog::PreTranslateMessage(CDialog *this,tagMSG *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800465ef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = PreTranslateMessage(this,param_1);
  return iVar1;
}

/* ---- FUNC 000465F5 OnCmdMsg (6 bytes) ---- */

int __thiscall
CDialog::OnCmdMsg(CDialog *this,uint param_1,int param_2,void *param_3,AFX_CMDHANDLERINFO *param_4)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800465f5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnCmdMsg(this,param_1,param_2,param_3,param_4);
  return iVar1;
}

/* ---- FUNC 000465FB CheckAutoCenter (6 bytes) ---- */

int __thiscall CDialog::CheckAutoCenter(CDialog *this)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800465fb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = CheckAutoCenter(this);
  return iVar1;
}

/* ---- FUNC 00046601 SetOccDialogInfo (6 bytes) ---- */

int __thiscall CDialog::SetOccDialogInfo(CDialog *this,_AFX_OCC_DIALOG_INFO *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046601. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = SetOccDialogInfo(this,param_1);
  return iVar1;
}

/* ---- FUNC 00046607 GetOccDialogInfo (6 bytes) ---- */

_AFX_OCC_DIALOG_INFO * __thiscall CDialog::GetOccDialogInfo(CDialog *this)

{
  _AFX_OCC_DIALOG_INFO *p_Var1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046607. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  p_Var1 = GetOccDialogInfo(this);
  return p_Var1;
}

/* ---- FUNC 0004660D PreInitDialog (6 bytes) ---- */

void __thiscall CDialog::PreInitDialog(CDialog *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018004660d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  PreInitDialog(this);
  return;
}

/* ---- FUNC 00046619 Create (6 bytes) ---- */

int __thiscall
CButton::Create(CButton *this,char *param_1,ulong param_2,tagRECT *param_3,CWnd *param_4,
               uint param_5)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046619. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = Create(this,param_1,param_2,param_3,param_4,param_5);
  return iVar1;
}

/* ---- FUNC 0004661F OnChildNotify (6 bytes) ---- */

int __thiscall
CButton::OnChildNotify(CButton *this,uint param_1,__uint64 param_2,__int64 param_3,__int64 *param_4)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004661f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnChildNotify(this,param_1,param_2,param_3,param_4);
  return iVar1;
}

/* ---- FUNC 00046625 GetText (6 bytes) ---- */

void __thiscall
CListBox::GetText(CListBox *this,int param_1,
                 CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2)

{
                    /* WARNING: Could not recover jumptable at 0x000180046625. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetText(this,param_1,param_2);
  return;
}

/* ---- FUNC 0004662B CompareItem (6 bytes) ---- */

int __thiscall CListBox::CompareItem(CListBox *this,tagCOMPAREITEMSTRUCT *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004662b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = CompareItem(this,param_1);
  return iVar1;
}

/* ---- FUNC 00046631 DeleteItem (6 bytes) ---- */

void __thiscall CListBox::DeleteItem(CListBox *this,tagDELETEITEMSTRUCT *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180046631. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DeleteItem(this,param_1);
  return;
}

/* ---- FUNC 00046637 VKeyToItem (6 bytes) ---- */

int __thiscall CListBox::VKeyToItem(CListBox *this,uint param_1,uint param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046637. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = VKeyToItem(this,param_1,param_2);
  return iVar1;
}

/* ---- FUNC 0004663D CharToItem (6 bytes) ---- */

int __thiscall CListBox::CharToItem(CListBox *this,uint param_1,uint param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004663d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = CharToItem(this,param_1,param_2);
  return iVar1;
}

/* ---- FUNC 00046643 GetRuntimeClass (6 bytes) ---- */

CRuntimeClass * __thiscall CCheckListBox::GetRuntimeClass(CCheckListBox *this)

{
  CRuntimeClass *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046643. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetRuntimeClass(this);
  return pCVar1;
}

/* ---- FUNC 00046649 Create (6 bytes) ---- */

int __thiscall
CCheckListBox::Create(CCheckListBox *this,ulong param_1,tagRECT *param_2,CWnd *param_3,uint param_4)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046649. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = Create(this,param_1,param_2,param_3,param_4);
  return iVar1;
}

/* ---- FUNC 0004664F SetCheck (6 bytes) ---- */

void __thiscall CCheckListBox::SetCheck(CCheckListBox *this,int param_1,int param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00018004664f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetCheck(this,param_1,param_2);
  return;
}

/* ---- FUNC 00046655 GetCheck (6 bytes) ---- */

int __thiscall CCheckListBox::GetCheck(CCheckListBox *this,int param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046655. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = GetCheck(this,param_1);
  return iVar1;
}

/* ---- FUNC 0004665B OnGetCheckPosition (6 bytes) ---- */

void __thiscall CCheckListBox::OnGetCheckPosition(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018004665b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OnGetCheckPosition();
  return;
}

/* ---- FUNC 00046661 DrawItem (6 bytes) ---- */

void __thiscall CCheckListBox::DrawItem(CCheckListBox *this,tagDRAWITEMSTRUCT *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180046661. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DrawItem(this,param_1);
  return;
}

/* ---- FUNC 00046667 MeasureItem (6 bytes) ---- */

void __thiscall CCheckListBox::MeasureItem(CCheckListBox *this,tagMEASUREITEMSTRUCT *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180046667. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MeasureItem(this,param_1);
  return;
}

/* ---- FUNC 0004666D OnChildNotify (6 bytes) ---- */

int __thiscall
CCheckListBox::OnChildNotify
          (CCheckListBox *this,uint param_1,__uint64 param_2,__int64 param_3,__int64 *param_4)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004666d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnChildNotify(this,param_1,param_2,param_3,param_4);
  return iVar1;
}

/* ---- FUNC 00046673 get_accRole (6 bytes) ---- */

long __thiscall
CCheckListBox::get_accRole(CCheckListBox *this,tagVARIANT *param_1,tagVARIANT *param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046673. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accRole(this,param_1,param_2);
  return lVar1;
}

/* ---- FUNC 00046679 get_accState (6 bytes) ---- */

long __thiscall
CCheckListBox::get_accState(CCheckListBox *this,tagVARIANT *param_1,tagVARIANT *param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046679. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accState(this,param_1,param_2);
  return lVar1;
}

/* ---- FUNC 0004667F get_accDefaultAction (6 bytes) ---- */

long __thiscall
CCheckListBox::get_accDefaultAction(CCheckListBox *this,tagVARIANT *param_1,wchar_t **param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004667f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = get_accDefaultAction(this,param_1,param_2);
  return lVar1;
}

/* ---- FUNC 00046685 accDoDefaultAction (6 bytes) ---- */

long __thiscall CCheckListBox::accDoDefaultAction(CCheckListBox *this,tagVARIANT *param_1)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046685. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = accDoDefaultAction(this,param_1);
  return lVar1;
}

/* ---- FUNC 0004668B GetMessageMap (6 bytes) ---- */

AFX_MSGMAP * __thiscall CCheckListBox::GetMessageMap(CCheckListBox *this)

{
  AFX_MSGMAP *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004668b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = GetMessageMap(this);
  return pAVar1;
}

/* ---- FUNC 00046691 AfxFindResourceHandle (6 bytes) ---- */

HINSTANCE__ * __cdecl AfxFindResourceHandle(char *param_1,char *param_2)

{
  HINSTANCE__ *pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046691. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = AfxFindResourceHandle(param_1,param_2);
  return pHVar1;
}

/* ---- FUNC 00046697 GetRuntimeClass (6 bytes) ---- */

CRuntimeClass * __thiscall CBitmapButton::GetRuntimeClass(CBitmapButton *this)

{
  CRuntimeClass *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046697. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetRuntimeClass(this);
  return pCVar1;
}

/* ---- FUNC 0004669D DrawItem (6 bytes) ---- */

void __thiscall CBitmapButton::DrawItem(CBitmapButton *this,tagDRAWITEMSTRUCT *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018004669d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DrawItem(this,param_1);
  return;
}

/* ---- FUNC 000466A3 FromHandle (6 bytes) ---- */

CDC * __cdecl CDC::FromHandle(HDC__ *param_1)

{
  CDC *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800466a3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = FromHandle(param_1);
  return pCVar1;
}

/* ---- FUNC 000466A9 GetDlgItem (6 bytes) ---- */

CWnd * __thiscall CWnd::GetDlgItem(CWnd *this,int param_1)

{
  CWnd *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800466a9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetDlgItem(this,param_1);
  return pCVar1;
}

/* ---- FUNC 000466AF GetOFN (6 bytes) ---- */

tagOFNA * __thiscall CFileDialog::GetOFN(CFileDialog *this)

{
  tagOFNA *ptVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800466af. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ptVar1 = GetOFN(this);
  return ptVar1;
}

/* ---- FUNC 000466B5 CFileDialog (6 bytes) ---- */

void __thiscall
CFileDialog::CFileDialog
          (CFileDialog *this,int param_1,char *param_2,char *param_3,ulong param_4,char *param_5,
          CWnd *param_6,ulong param_7,int param_8)

{
                    /* WARNING: Could not recover jumptable at 0x0001800466b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CFileDialog(this,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}

/* ---- FUNC 000466BB ~CFileDialog (6 bytes) ---- */

void __thiscall CFileDialog::~CFileDialog(CFileDialog *this)

{
                    /* WARNING: Could not recover jumptable at 0x0001800466bb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CFileDialog(this);
  return;
}

/* ---- FUNC 000466C1 DoModal (6 bytes) ---- */

__int64 __thiscall CFileDialog::DoModal(CFileDialog *this)

{
  __int64 _Var1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800466c1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = DoModal(this);
  return _Var1;
}

/* ---- FUNC 000466C7 GetPathName (6 bytes) ---- */

void __thiscall CFileDialog::GetPathName(CFileDialog *this)

{
                    /* WARNING: Could not recover jumptable at 0x0001800466c7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetPathName(this);
  return;
}

/* ---- FUNC 000466CD AfxTryCleanup (6 bytes) ---- */

void __cdecl AfxTryCleanup(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800466cd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AfxTryCleanup();
  return;
}

/* ---- FUNC 000466D3 AFX_EXCEPTION_LINK (6 bytes) ---- */

void __thiscall AFX_EXCEPTION_LINK::AFX_EXCEPTION_LINK(AFX_EXCEPTION_LINK *this)

{
                    /* WARNING: Could not recover jumptable at 0x0001800466d3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AFX_EXCEPTION_LINK(this);
  return;
}

/* ---- FUNC 000466D9 AFX_MAINTAIN_STATE2 (6 bytes) ---- */

void __thiscall
AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(AFX_MAINTAIN_STATE2 *this,AFX_MODULE_STATE *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0001800466d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AFX_MAINTAIN_STATE2(this,param_1);
  return;
}

/* ---- FUNC 000466DF ~AFX_MAINTAIN_STATE2 (6 bytes) ---- */

void __thiscall AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(AFX_MAINTAIN_STATE2 *this)

{
                    /* WARNING: Could not recover jumptable at 0x0001800466df. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~AFX_MAINTAIN_STATE2(this);
  return;
}

/* ---- FUNC 000466E5 GetMessageMap (6 bytes) ---- */

AFX_MSGMAP * __thiscall CDialog::GetMessageMap(CDialog *this)

{
  AFX_MSGMAP *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800466e5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = GetMessageMap(this);
  return pAVar1;
}

/* ---- FUNC 000466EB AfxGetThread (6 bytes) ---- */

CWinThread * __cdecl AfxGetThread(void)

{
  CWinThread *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800466eb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = AfxGetThread();
  return pCVar1;
}

/* ---- FUNC 000466F1 COleDispatchDriver (6 bytes) ---- */

void __thiscall COleDispatchDriver::COleDispatchDriver(COleDispatchDriver *this)

{
                    /* WARNING: Could not recover jumptable at 0x0001800466f1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  COleDispatchDriver(this);
  return;
}

/* ---- FUNC 000466F7 AttachDispatch (6 bytes) ---- */

void __thiscall
COleDispatchDriver::AttachDispatch(COleDispatchDriver *this,IDispatch *param_1,int param_2)

{
                    /* WARNING: Could not recover jumptable at 0x0001800466f7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AttachDispatch(this,param_1,param_2);
  return;
}

/* ---- FUNC 000466FD DetachDispatch (6 bytes) ---- */

IDispatch * __thiscall COleDispatchDriver::DetachDispatch(COleDispatchDriver *this)

{
  IDispatch *pIVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800466fd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pIVar1 = DetachDispatch(this);
  return pIVar1;
}

/* ---- FUNC 00046703 ReleaseDispatch (6 bytes) ---- */

void __thiscall COleDispatchDriver::ReleaseDispatch(COleDispatchDriver *this)

{
                    /* WARNING: Could not recover jumptable at 0x000180046703. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ReleaseDispatch(this);
  return;
}

/* ---- FUNC 00046709 InvokeHelper (6 bytes) ---- */

void __thiscall
COleDispatchDriver::InvokeHelper
          (COleDispatchDriver *this,long param_1,ushort param_2,ushort param_3,void *param_4,
          uchar *param_5,...)

{
                    /* WARNING: Could not recover jumptable at 0x000180046709. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InvokeHelper(this,param_1,param_2,param_3,param_4,param_5);
  return;
}

/* ---- FUNC 0004670F CDumpContext (6 bytes) ---- */

void __thiscall CDumpContext::CDumpContext(CDumpContext *this,CFile *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018004670f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CDumpContext(this,param_1);
  return;
}

/* ---- FUNC 00046715 operator<< (6 bytes) ---- */

CDumpContext * __thiscall CDumpContext::operator<<(CDumpContext *this,char *param_1)

{
  CDumpContext *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046715. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = operator<<(this,param_1);
  return pCVar1;
}

/* ---- FUNC 0004671B AfxGetModuleState (6 bytes) ---- */

AFX_MODULE_STATE * __cdecl AfxGetModuleState(void)

{
  AFX_MODULE_STATE *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004671b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = AfxGetModuleState();
  return pAVar1;
}

/* ---- FUNC 00046721 BeginWaitCursor (6 bytes) ---- */

void __thiscall CCmdTarget::BeginWaitCursor(CCmdTarget *this)

{
                    /* WARNING: Could not recover jumptable at 0x000180046721. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BeginWaitCursor(this);
  return;
}

/* ---- FUNC 00046727 EndWaitCursor (6 bytes) ---- */

void __thiscall CCmdTarget::EndWaitCursor(CCmdTarget *this)

{
                    /* WARNING: Could not recover jumptable at 0x000180046727. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EndWaitCursor(this);
  return;
}

/* ---- FUNC 0004672D CDynLinkLibrary (6 bytes) ---- */

void __thiscall
CDynLinkLibrary::CDynLinkLibrary(CDynLinkLibrary *this,AFX_EXTENSION_MODULE *param_1,int param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00018004672d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CDynLinkLibrary(this,param_1,param_2);
  return;
}

/* ---- FUNC 00046733 AfxInitExtensionModule (6 bytes) ---- */

int __cdecl AfxInitExtensionModule(AFX_EXTENSION_MODULE *param_1,HINSTANCE__ *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046733. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = AfxInitExtensionModule(param_1,param_2);
  return iVar1;
}

/* ---- FUNC 00046739 AfxDllCanUnloadNow (6 bytes) ---- */

long __cdecl AfxDllCanUnloadNow(void)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046739. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = AfxDllCanUnloadNow();
  return lVar1;
}

/* ---- FUNC 0004673F CMapStringToPtr (6 bytes) ---- */

void __thiscall CMapStringToPtr::CMapStringToPtr(CMapStringToPtr *this,__int64 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018004673f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CMapStringToPtr(this,param_1);
  return;
}

/* ---- FUNC 00046745 Lookup (6 bytes) ---- */

int __thiscall CMapStringToPtr::Lookup(CMapStringToPtr *this,char *param_1,void **param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180046745. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = Lookup(this,param_1,param_2);
  return iVar1;
}

/* ---- FUNC 0004674B operator[] (6 bytes) ---- */

void ** __thiscall CMapStringToPtr::operator[](CMapStringToPtr *this,char *param_1)

{
  void **ppvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004674b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ppvVar1 = operator[](this,param_1);
  return ppvVar1;
}

/* ---- FUNC 00046751 GetNextAssoc (6 bytes) ---- */

void __thiscall
CMapStringToPtr::GetNextAssoc
          (CMapStringToPtr *this,__POSITION **param_1,
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2,void **param_3)

{
                    /* WARNING: Could not recover jumptable at 0x000180046751. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetNextAssoc(this,param_1,param_2,param_3);
  return;
}

/* ---- FUNC 00046757 ~CMapStringToPtr (6 bytes) ---- */

void __thiscall CMapStringToPtr::~CMapStringToPtr(CMapStringToPtr *this)

{
                    /* WARNING: Could not recover jumptable at 0x000180046757. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CMapStringToPtr(this);
  return;
}

/* ---- FUNC 00046760 `eh_vector_constructor_iterator' (112 bytes) ---- */

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
    (*(code *)PTR__guard_dispatch_icall_180053248)(param_1);
    param_1 = (void *)((longlong)param_1 + param_2);
  }
  return;
}

/* ---- FUNC 000467D0 `eh_vector_destructor_iterator' (107 bytes) ---- */

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
    (*(code *)PTR__guard_dispatch_icall_180053248)(pvVar1);
    param_3 = param_3 - 1;
  }
  return;
}

/* ---- FUNC 0004683C __ArrayUnwind (97 bytes) ---- */

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
    (*(code *)PTR__guard_dispatch_icall_180053248)(param_1);
  }
  return;
}

/* ---- FUNC 000468A0 operator_delete (5 bytes) ---- */

void __cdecl operator_delete(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180046271. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete(param_1);
  return;
}

/* ---- FUNC 000468A8 operator_delete[] (5 bytes) ---- */

void __cdecl operator_delete__(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018004627d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete__(param_1);
  return;
}

/* ---- FUNC 000468B0 __GSHandlerCheck (29 bytes) ---- */

/* Library Function - Single Match
    __GSHandlerCheck
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}

/* ---- FUNC 000468D0 __GSHandlerCheckCommon (91 bytes) ---- */

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

/* ---- FUNC 0004692C FID_conflict:__GSHandlerCheck_EH (127 bytes) ---- */

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

/* ---- FUNC 000469C0 __security_check_cookie (30 bytes) ---- */

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie == DAT_1800791f8) && ((short)(_StackCookie >> 0x30) == 0)) {
    return;
  }
  FUN_180046dc0();
  return;
}

/* ---- FUNC 000469E0 FUN_1800469e0 (43 bytes) ---- */

undefined8 * FUN_1800469e0(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = type_info::vftable;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

/* ---- FUNC 00046A0C __scrt_acquire_startup_lock (57 bytes) ---- */

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
LAB_180046a3a:
    uVar3 = uVar3 & 0xffffffffffffff00;
  }
  else {
    do {
      uVar3 = 0;
      LOCK();
      bVar2 = DAT_18009bbe0 == 0;
      uVar1 = *(ulonglong *)((longlong)Self + 8);
      if (!bVar2) {
        uVar3 = DAT_18009bbe0;
        uVar1 = DAT_18009bbe0;
      }
      DAT_18009bbe0 = uVar1;
      UNLOCK();
      if (bVar2) goto LAB_180046a3a;
    } while (*(ulonglong *)((longlong)Self + 8) != uVar3);
    uVar3 = CONCAT71((int7)(uVar3 >> 8),1);
  }
  return uVar3;
}

/* ---- FUNC 00046A48 __scrt_dllmain_after_initialize_c (52 bytes) ---- */

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
    uVar3 = FUN_180024810();
    uVar3 = _configure_narrow_argv(uVar3 & 0xffffffff);
    if ((int)uVar3 != 0) {
      return uVar3 & 0xffffffffffffff00;
    }
    uVar2 = _initialize_narrow_environment();
  }
  else {
    uVar2 = FUN_1800475e0();
  }
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}

/* ---- FUNC 00046A7C FUN_180046a7c (21 bytes) ---- */

bool FUN_180046a7c(void)

{
  undefined8 uVar1;
  
  uVar1 = FUN_180046bc4(0);
  return (char)uVar1 != '\0';
}

/* ---- FUNC 00046A94 FUN_180046a94 (40 bytes) ---- */

undefined1 FUN_180046a94(void)

{
  char cVar1;
  
  cVar1 = FUN_18004efec();
  if (cVar1 != '\0') {
    cVar1 = FUN_18004efec();
    if (cVar1 != '\0') {
      return 1;
    }
    FUN_18004efec();
  }
  return 0;
}

/* ---- FUNC 00046ABC FUN_180046abc (21 bytes) ---- */

undefined1 FUN_180046abc(void)

{
  FUN_18004efec();
  FUN_18004efec();
  return 1;
}

/* ---- FUNC 00046AD4 __scrt_dllmain_exception_filter (96 bytes) ---- */

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
    (*(code *)PTR__guard_dispatch_icall_180053248)(param_1,0,param_3);
  }
  _seh_filter_dll(param_5,param_6);
  return;
}

/* ---- FUNC 00046B34 __scrt_dllmain_uninitialize_c (48 bytes) ---- */

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
    _execute_onexit_table(&DAT_18009bbf0);
    return;
  }
  uVar2 = FUN_18004eff0();
  if ((int)uVar2 == 0) {
    _cexit();
  }
  return;
}

/* ---- FUNC 00046B64 FUN_180046b64 (20 bytes) ---- */

void FUN_180046b64(void)

{
  FUN_18004efec();
  FUN_18004efec();
  return;
}

/* ---- FUNC 00046B78 __scrt_initialize_crt (73 bytes) ---- */

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
    DAT_18009bbe8 = 1;
  }
  FUN_1800475e0();
  cVar1 = FUN_18004efec();
  uVar2 = extraout_var;
  if (cVar1 != '\0') {
    cVar1 = FUN_18004efec();
    if (cVar1 != '\0') {
      return CONCAT71(extraout_var_00,1);
    }
    FUN_18004efec();
    uVar2 = extraout_var_01;
  }
  return (ulonglong)uVar2 << 8;
}

/* ---- FUNC 00046BC4 FUN_180046bc4 (138 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_180046bc4(uint param_1)

{
  bool bVar1;
  ulonglong in_RAX;
  undefined7 extraout_var;
  
  if (DAT_18009bbe9 == '\0') {
    if (1 < param_1) {
                    /* WARNING: Subroutine does not return */
      FUN_1800477a0(5);
    }
    bVar1 = __scrt_is_ucrt_dll_in_use();
    if (((int)CONCAT71(extraout_var,bVar1) == 0) || (param_1 != 0)) {
      in_RAX = 0xffffffffffffffff;
      DAT_18009bbf0 = _DAT_180057a30;
      uRam000000018009bbf8 = _UNK_180057a38;
      _DAT_18009bc00 = 0xffffffffffffffff;
      _DAT_18009bc08 = _DAT_180057a30;
      uRam000000018009bc10 = _UNK_180057a38;
      _DAT_18009bc18 = 0xffffffffffffffff;
    }
    else {
      in_RAX = _initialize_onexit_table(&DAT_18009bbf0);
      if (((int)in_RAX != 0) ||
         (in_RAX = _initialize_onexit_table(&DAT_18009bc08), (int)in_RAX != 0)) {
        return in_RAX & 0xffffffffffffff00;
      }
    }
    DAT_18009bbe9 = '\x01';
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}

/* ---- FUNC 00046C50 FUN_180046c50 (152 bytes) ---- */

ulonglong FUN_180046c50(longlong param_1)

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
           param_1 - 0x180000000U < uVar1)) goto LAB_180046cc6;
      }
      lVar4 = 0;
LAB_180046cc6:
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

/* ---- FUNC 00046CE8 __scrt_release_startup_lock (36 bytes) ---- */

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
    DAT_18009bbe0 = 0;
    UNLOCK();
  }
  return;
}

/* ---- FUNC 00046D0C __scrt_uninitialize_crt (41 bytes) ---- */

/* Library Function - Single Match
    __scrt_uninitialize_crt
   
   Library: Visual Studio 2019 Release */

undefined1 __scrt_uninitialize_crt(undefined8 param_1,char param_2)

{
  if ((DAT_18009bbe8 == '\0') || (param_2 == '\0')) {
    FUN_18004efec();
    FUN_18004efec();
  }
  return 1;
}

/* ---- FUNC 00046D38 _onexit (58 bytes) ---- */

/* Library Function - Single Match
    _onexit
   
   Library: Visual Studio 2019 Release */

_onexit_t __cdecl _onexit(_onexit_t _Func)

{
  int iVar1;
  _onexit_t p_Var2;
  
  if (DAT_18009bbf0 == -1) {
    iVar1 = _crt_atexit();
  }
  else {
    iVar1 = _register_onexit_function(&DAT_18009bbf0);
  }
  p_Var2 = (_onexit_t)0x0;
  if (iVar1 == 0) {
    p_Var2 = _Func;
  }
  return p_Var2;
}

/* ---- FUNC 00046D74 atexit (23 bytes) ---- */

/* Library Function - Single Match
    atexit
   
   Library: Visual Studio 2019 Release */

int __cdecl atexit(_func_5014 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = _onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}

/* ---- FUNC 00046D8C __raise_securityfailure (52 bytes) ---- */

/* Library Function - Single Match
    __raise_securityfailure
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __raise_securityfailure(_EXCEPTION_POINTERS *param_1)

{
  HANDLE pvVar1;
  
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter(param_1);
  pvVar1 = GetCurrentProcess();
                    /* WARNING: Could not recover jumptable at 0x000180046db9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TerminateProcess(pvVar1,0xc0000409);
  return;
}

/* ---- FUNC 00046DC0 FUN_180046dc0 (210 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180046dc0(void)

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
  *(undefined8 *)(puVar3 + -8) = 0x180046deb;
  capture_previous_context((PCONTEXT)&DAT_18009bcc0);
  _DAT_18009bc30 = *(undefined8 *)(puVar3 + 0x38);
  _DAT_18009bd58 = puVar3 + 0x40;
  _DAT_18009bd40 = *(undefined8 *)(puVar3 + 0x40);
  _DAT_18009bc20 = 0xc0000409;
  _DAT_18009bc24 = 1;
  _DAT_18009bc38 = 1;
  DAT_18009bc40 = 2;
  *(undefined8 *)(puVar3 + 0x20) = DAT_1800791f8;
  *(undefined8 *)(puVar3 + 0x28) = DAT_1800791f0;
  *(undefined8 *)(puVar3 + -8) = 0x180046e8d;
  DAT_18009bdb8 = _DAT_18009bc30;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_180057a40);
  return;
}

/* ---- FUNC 00046E94 FUN_180046e94 (19 bytes) ---- */

void FUN_180046e94(void)

{
  FUN_180046ea8(8);
  return;
}

/* ---- FUNC 00046EA8 FUN_180046ea8 (156 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180046ea8(undefined4 param_1)

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
  *(undefined8 *)(puVar3 + -8) = 0x180046ed3;
  capture_current_context((PCONTEXT)&DAT_18009bcc0);
  _DAT_18009bc30 = *(undefined8 *)(puVar3 + 0x28);
  _DAT_18009bd58 = puVar3 + 0x30;
  _DAT_18009bc20 = 0xc0000409;
  _DAT_18009bc24 = 1;
  _DAT_18009bc38 = 1;
  DAT_18009bc40 = (ulonglong)*(uint *)(puVar3 + 0x30);
  *(undefined8 *)(puVar3 + -8) = 0x180046f3f;
  DAT_18009bdb8 = _DAT_18009bc30;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_180057a40);
  return;
}

/* ---- FUNC 00046F44 capture_current_context (109 bytes) ---- */

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

/* ---- FUNC 00046FB4 capture_previous_context (113 bytes) ---- */

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

/* ---- FUNC 00047028 _Init_thread_footer (105 bytes) ---- */

/* Library Function - Single Match
    _Init_thread_footer
   
   Library: Visual Studio 2019 Release */

void _Init_thread_footer(int *param_1)

{
  ulonglong uVar1;
  
  AcquireSRWLockExclusive((PSRWLOCK)&DAT_18009c198);
  uVar1 = (ulonglong)_tls_index;
  DAT_180079204 = DAT_180079204 + 1;
  *param_1 = DAT_180079204;
  *(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar1 * 8) + 4) = DAT_180079204;
  ReleaseSRWLockExclusive((PSRWLOCK)&DAT_18009c198);
                    /* WARNING: Could not recover jumptable at 0x00018004708a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WakeAllConditionVariable(&DAT_18009c190);
  return;
}

/* ---- FUNC 00047094 FUN_180047094 (120 bytes) ---- */

void FUN_180047094(int *param_1)

{
  AcquireSRWLockExclusive((PSRWLOCK)&DAT_18009c198);
  do {
    if (*param_1 == 0) {
      *param_1 = -1;
LAB_1800470f9:
                    /* WARNING: Could not recover jumptable at 0x000180047105. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      ReleaseSRWLockExclusive((PSRWLOCK)&DAT_18009c198);
      return;
    }
    if (*param_1 != -1) {
      *(undefined4 *)
       (*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4) =
           DAT_180079204;
      goto LAB_1800470f9;
    }
    SleepConditionVariableSRW
              ((PCONDITION_VARIABLE)&DAT_18009c190,(PSRWLOCK)&DAT_18009c198,0xffffffff,0);
  } while( true );
}

/* ---- FUNC 0004710C __GSHandlerCheck_SEH (133 bytes) ---- */

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

/* ---- FUNC 000471B0 __chkstk (78 bytes) ---- */

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

/* ---- FUNC 00047200 FUN_180047200 (80 bytes) ---- */

ulonglong FUN_180047200(undefined8 param_1,int param_2,longlong param_3)

{
  byte bVar1;
  ulonglong uVar2;
  undefined7 extraout_var;
  
  if (param_2 == 0) {
    bVar1 = FUN_180047368(CONCAT71((int7)((ulonglong)param_1 >> 8),param_3 != 0));
    return CONCAT71(extraout_var,bVar1);
  }
  if (param_2 != 1) {
    if (param_2 == 2) {
      bVar1 = FUN_180046a94();
    }
    else {
      if (param_2 != 3) {
        return 1;
      }
      bVar1 = FUN_180046abc();
    }
    return (ulonglong)bVar1;
  }
  uVar2 = FUN_180047250(param_1,param_3);
  return uVar2;
}

/* ---- FUNC 00047250 FUN_180047250 (276 bytes) ---- */

undefined8 FUN_180047250(undefined8 param_1,undefined8 param_2)

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
    if (DAT_18009bbd8 != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_1800477a0(7);
    }
    DAT_18009bbd8 = 1;
    bVar2 = FUN_180046a7c();
    if (bVar2) {
      FUN_1800479d8();
      FUN_180047998();
      FUN_1800479b4();
      iVar3 = _initterm_e(&DAT_180053370,&DAT_180053378);
      if ((iVar3 == 0) && (uVar5 = __scrt_dllmain_after_initialize_c(), (char)uVar5 != '\0')) {
        _initterm(&DAT_180053270,&DAT_180053368);
        DAT_18009bbd8 = 2;
        bVar1 = false;
      }
    }
    __scrt_release_startup_lock((char)uVar4);
    if (!bVar1) {
      plVar6 = (longlong *)FUN_1800479d0();
      if ((*plVar6 != 0) && (uVar7 = FUN_180046c50((longlong)plVar6), (char)uVar7 != '\0')) {
        (*(code *)PTR__guard_dispatch_icall_180053248)(param_1,2,param_2);
      }
      DAT_18009c1a4 = DAT_18009c1a4 + 1;
      return 1;
    }
  }
  return 0;
}

/* ---- FUNC 00047368 FUN_180047368 (129 bytes) ---- */

byte FUN_180047368(undefined8 param_1)

{
  undefined1 uVar1;
  char cVar2;
  undefined8 uVar3;
  undefined7 uVar4;
  byte bVar5;
  
  uVar1 = (undefined1)param_1;
  if (DAT_18009c1a4 < 1) {
    bVar5 = 0;
  }
  else {
    DAT_18009c1a4 = DAT_18009c1a4 + -1;
    uVar3 = __scrt_acquire_startup_lock();
    if (DAT_18009bbd8 != 2) {
                    /* WARNING: Subroutine does not return */
      FUN_1800477a0(7);
    }
    __scrt_dllmain_uninitialize_c();
    FUN_1800479a8();
    FUN_180047a14();
    DAT_18009bbd8 = 0;
    uVar4 = (undefined7)((ulonglong)param_1 >> 8);
    __scrt_release_startup_lock((char)uVar3);
    cVar2 = __scrt_uninitialize_crt(CONCAT71(uVar4,uVar1),'\0');
    bVar5 = -(cVar2 != '\0') & 1;
    FUN_180046b64();
  }
  return bVar5;
}

/* ---- FUNC 000473EC dllmain_dispatch (305 bytes) ---- */

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
  
  if ((param_2 == 0) && (DAT_18009c1a4 < 1)) {
    iVar4 = 0;
  }
  else {
    if (param_2 - 1 < 2) {
      if ((PTR_FUN_180056178 != (undefined *)0x0) &&
         (iVar4 = (*(code *)PTR__guard_dispatch_icall_180053248)(), iVar4 == 0)) {
        return 0;
      }
      uVar1 = FUN_180047200(param_1,param_2,(longlong)param_3);
      if ((int)uVar1 == 0) {
        return 0;
      }
    }
    uVar2 = FUN_18002d310(param_1,param_2);
    iVar4 = (int)uVar2;
    if ((param_2 == 1) && (iVar4 == 0)) {
      pHVar3 = param_1;
      FUN_18002d310(param_1,0);
      FUN_180047368(CONCAT71((int7)((ulonglong)pHVar3 >> 8),param_3 != (void *)0x0));
      if (PTR_FUN_180056178 != (undefined *)0x0) {
        (*(code *)PTR__guard_dispatch_icall_180053248)(param_1,0,param_3);
      }
    }
    if ((param_2 == 0) || (param_2 == 3)) {
      uVar1 = FUN_180047200(param_1,param_2,(longlong)param_3);
      iVar4 = 0;
      if ((int)uVar1 != 0) {
        if (PTR_FUN_180056178 == (undefined *)0x0) {
          iVar4 = 1;
        }
        else {
          iVar4 = (*(code *)PTR__guard_dispatch_icall_180053248)(param_1,param_2,param_3);
        }
      }
    }
  }
  return iVar4;
}

/* ---- FUNC 00047520 entry (61 bytes) ---- */

void entry(HINSTANCE__ *param_1,ulong param_2,void *param_3)

{
  if (param_2 == 1) {
    __security_init_cookie();
  }
  dllmain_dispatch(param_1,param_2,param_3);
  return;
}

/* ---- FUNC 00047560 FID_conflict:__GSHandlerCheck_EH (127 bytes) ---- */

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
                    /* WARNING: Subroutine does not return */
    __CxxFrameHandler3(param_1,param_2,param_3,param_4);
  }
  return;
}

/* ---- FUNC 000475E0 FUN_1800475e0 (428 bytes) ---- */

/* WARNING: Removing unreachable block (ram,0x0001800476aa) */
/* WARNING: Removing unreachable block (ram,0x00018004761a) */
/* WARNING: Removing unreachable block (ram,0x0001800475f3) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1800475e0(void)

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
    _DAT_180079220 = 0xffffffffffffffff;
    uVar7 = *puVar2 & 0xfff3ff0;
    _DAT_180079218 = 0x8000;
    if ((((uVar7 == 0x106c0) || (uVar7 == 0x20660)) || (uVar7 == 0x20670)) ||
       ((uVar7 - 0x30650 < 0x21 &&
        ((0x100010001U >> ((ulonglong)(uVar7 - 0x30650) & 0x3f) & 1) != 0)))) {
      DAT_18009c1a8 = DAT_18009c1a8 | 1;
    }
  }
  if (6 < *piVar1) {
    lVar3 = cpuid_Extended_Feature_Enumeration_info(7);
    uVar8 = *(uint *)(lVar3 + 4);
    if ((uVar8 >> 9 & 1) != 0) {
      DAT_18009c1a8 = DAT_18009c1a8 | 2;
    }
  }
  _DAT_180079210 = 1;
  DAT_180079214 = 2;
  if ((uVar4 >> 0x14 & 1) != 0) {
    _DAT_180079210 = 2;
    DAT_180079214 = 6;
    if (((uVar4 >> 0x1b & 1) != 0) && ((uVar4 >> 0x1c & 1) != 0)) {
      uVar5 = xinuse(0);
      bVar6 = in_XCR0 & (byte)uVar5;
      if ((bVar6 & 6) == 6) {
        DAT_180079214 = 0xe;
        _DAT_180079210 = 3;
        if ((uVar8 & 0x20) != 0) {
          _DAT_180079210 = 5;
          DAT_180079214 = 0x2e;
          if (((uVar8 & 0xd0030000) == 0xd0030000) && ((bVar6 & 0xe0) == 0xe0)) {
            DAT_180079214 = 0x6e;
            _DAT_180079210 = 6;
          }
        }
      }
    }
  }
  return 0;
}

/* ---- FUNC 0004778C __scrt_is_ucrt_dll_in_use (12 bytes) ---- */

/* Library Function - Single Match
    __scrt_is_ucrt_dll_in_use
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

bool __scrt_is_ucrt_dll_in_use(void)

{
  return DAT_180079250 != 0;
}

/* ---- FUNC 00047798 FUN_180047798 (8 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180047798(void)

{
  _DAT_18009c1ac = 0;
  return;
}

/* ---- FUNC 000477A0 FUN_1800477a0 (331 bytes) ---- */

void FUN_1800477a0(undefined4 param_1)

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
  *(undefined8 *)(puVar4 + -8) = 0x1800477d4;
  FUN_180047798();
  *(undefined8 *)(puVar4 + -8) = 0x1800477e5;
  memset(local_4d8,0,0x4d0);
  *(undefined8 *)(puVar4 + -8) = 0x1800477ef;
  RtlCaptureContext(local_4d8);
  *(undefined8 *)(puVar4 + -8) = 0x180047809;
  FunctionEntry = RtlLookupFunctionEntry(local_3e0,&local_res10,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry != (PRUNTIME_FUNCTION)0x0) {
    *(undefined8 *)(puVar4 + 0x38) = 0;
    *(undefined1 **)(puVar4 + 0x30) = local_res18;
    *(undefined1 **)(puVar4 + 0x28) = local_res20;
    *(undefined1 **)(puVar4 + 0x20) = local_4d8;
    *(undefined8 *)(puVar4 + -8) = 0x18004784a;
    RtlVirtualUnwind(0,local_res10,local_3e0,FunctionEntry,*(PCONTEXT *)(puVar4 + 0x20),
                     *(PVOID **)(puVar4 + 0x28),*(PDWORD64 *)(puVar4 + 0x30),
                     *(PKNONVOLATILE_CONTEXT_POINTERS *)(puVar4 + 0x38));
  }
  local_440 = &stack0x00000008;
  *(undefined8 *)(puVar4 + -8) = 0x18004787c;
  memset(puVar4 + 0x50,0,0x98);
  *(undefined8 *)(puVar4 + 0x60) = unaff_retaddr;
  *(undefined4 *)(puVar4 + 0x50) = 0x40000015;
  *(undefined4 *)(puVar4 + 0x54) = 1;
  *(undefined8 *)(puVar4 + -8) = 0x18004789e;
  BVar2 = IsDebuggerPresent();
  *(undefined1 **)(puVar4 + 0x40) = puVar4 + 0x50;
  *(undefined1 **)(puVar4 + 0x48) = local_4d8;
  *(undefined8 *)(puVar4 + -8) = 0x1800478bf;
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  *(undefined8 *)(puVar4 + -8) = 0x1800478ca;
  LVar3 = UnhandledExceptionFilter((_EXCEPTION_POINTERS *)(puVar4 + 0x40));
  if ((LVar3 == 0) && (BVar2 != 1)) {
    *(undefined8 *)(puVar4 + -8) = 0x1800478da;
    FUN_180047798();
  }
  return;
}

/* ---- FUNC 000478EC __security_init_cookie (172 bytes) ---- */

/* Library Function - Single Match
    __security_init_cookie
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl __security_init_cookie(void)

{
  DWORD DVar1;
  _FILETIME local_res8;
  LARGE_INTEGER local_res10;
  _FILETIME local_18 [2];
  
  if (DAT_1800791f8 == 0x2b992ddfa232) {
    local_res8.dwLowDateTime = 0;
    local_res8.dwHighDateTime = 0;
    GetSystemTimeAsFileTime(&local_res8);
    local_18[0] = local_res8;
    DVar1 = GetCurrentThreadId();
    local_18[0] = (_FILETIME)((ulonglong)local_18[0] ^ (ulonglong)DVar1);
    DVar1 = GetCurrentProcessId();
    local_18[0] = (_FILETIME)((ulonglong)local_18[0] ^ (ulonglong)DVar1);
    QueryPerformanceCounter(&local_res10);
    DAT_1800791f8 =
         ((ulonglong)local_res10.s.LowPart << 0x20 ^
          CONCAT44(local_res10.s.HighPart,local_res10.s.LowPart) ^ (ulonglong)local_18[0] ^
         (ulonglong)local_18) & 0xffffffffffff;
    if (DAT_1800791f8 == 0x2b992ddfa232) {
      DAT_1800791f8 = 0x2b992ddfa233;
    }
  }
  DAT_1800791f0 = ~DAT_1800791f8;
  return;
}

/* ---- FUNC 00047998 FUN_180047998 (14 bytes) ---- */

void FUN_180047998(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018004799f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InitializeSListHead(&DAT_18009c1b0);
  return;
}

/* ---- FUNC 000479A8 FUN_1800479a8 (12 bytes) ---- */

void FUN_1800479a8(void)

{
  __std_type_info_destroy_list(&DAT_18009c1b0);
  return;
}

/* ---- FUNC 000479B4 FUN_1800479b4 (27 bytes) ---- */

void FUN_1800479b4(void)

{
  ulonglong *puVar1;
  
  puVar1 = (ulonglong *)FUN_180007dc0();
  *puVar1 = *puVar1 | 0x24;
  puVar1 = (ulonglong *)FUN_180007dd0();
  *puVar1 = *puVar1 | 2;
  return;
}

/* ---- FUNC 000479D0 FUN_1800479d0 (8 bytes) ---- */

undefined * FUN_1800479d0(void)

{
  return &DAT_18009c238;
}

/* ---- FUNC 000479D8 FUN_1800479d8 (60 bytes) ---- */

void FUN_1800479d8(void)

{
  longlong *plVar1;
  
  for (plVar1 = &DAT_18005da88; plVar1 < &DAT_18005da88; plVar1 = plVar1 + 1) {
    if (*plVar1 != 0) {
      (*(code *)PTR__guard_dispatch_icall_180053248)();
    }
  }
  return;
}

/* ---- FUNC 00047A14 FUN_180047a14 (60 bytes) ---- */

void FUN_180047a14(void)

{
  longlong *plVar1;
  
  for (plVar1 = &DAT_18005da98; plVar1 < &DAT_18005da98; plVar1 = plVar1 + 1) {
    if (*plVar1 != 0) {
      (*(code *)PTR__guard_dispatch_icall_180053248)();
    }
  }
  return;
}

/* ---- FUNC 00047A50 CAtlBaseModule (165 bytes) ---- */

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
  *(undefined **)(this + 0x20) = &DAT_180057b18;
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
      DAT_18007a6d0 = 1;
    }
  }
  return this;
}

/* ---- FUNC 00047AF8 ~CAtlBaseModule (52 bytes) ---- */

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

/* ---- FUNC 00047B2C _Xlength_error (6 bytes) ---- */

void __cdecl std::_Xlength_error(char *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180047b2c. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  _Xlength_error(param_1);
  return;
}

/* ---- FUNC 00047B32 _Xout_of_range (6 bytes) ---- */

void __cdecl std::_Xout_of_range(char *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180047b32. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Xout_of_range(param_1);
  return;
}

/* ---- FUNC 00047B40 FUN_180047b40 (197 bytes) ---- */

undefined1 (*) [32]
FUN_180047b40(undefined1 (*param_1) [32],undefined1 (*param_2) [32],char param_3)

{
  ushort uVar1;
  undefined1 auVar2 [32];
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  ulonglong uVar6;
  undefined1 auVar7 [16];
  undefined1 auVar8 [32];
  
  uVar6 = (longlong)param_2 - (longlong)param_1;
  if (((uVar6 & 0xffffffffffffffe0) != 0) && ((DAT_180079214 >> 5 & 1) != 0)) {
    puVar5 = *param_1;
    auVar7 = vpshufb_avx(ZEXT416((uint)(int)param_3),(undefined1  [16])0x0);
    auVar8._16_16_ = auVar7;
    auVar8._0_16_ = auVar7;
    do {
      auVar2 = vpcmpeqb_avx2(auVar8,*param_1);
      uVar3 = (uint)(SUB321(auVar2 >> 7,0) & 1) | (uint)(SUB321(auVar2 >> 0xf,0) & 1) << 1 |
              (uint)(SUB321(auVar2 >> 0x17,0) & 1) << 2 | (uint)(SUB321(auVar2 >> 0x1f,0) & 1) << 3
              | (uint)(SUB321(auVar2 >> 0x27,0) & 1) << 4 |
              (uint)(SUB321(auVar2 >> 0x2f,0) & 1) << 5 | (uint)(SUB321(auVar2 >> 0x37,0) & 1) << 6
              | (uint)(SUB321(auVar2 >> 0x3f,0) & 1) << 7 |
              (uint)(SUB321(auVar2 >> 0x47,0) & 1) << 8 | (uint)(SUB321(auVar2 >> 0x4f,0) & 1) << 9
              | (uint)(SUB321(auVar2 >> 0x57,0) & 1) << 10 |
              (uint)(SUB321(auVar2 >> 0x5f,0) & 1) << 0xb |
              (uint)(SUB321(auVar2 >> 0x67,0) & 1) << 0xc |
              (uint)(SUB321(auVar2 >> 0x6f,0) & 1) << 0xd |
              (uint)(SUB321(auVar2 >> 0x77,0) & 1) << 0xe | (uint)SUB321(auVar2 >> 0x7f,0) << 0xf |
              (uint)(SUB321(auVar2 >> 0x87,0) & 1) << 0x10 |
              (uint)(SUB321(auVar2 >> 0x8f,0) & 1) << 0x11 |
              (uint)(SUB321(auVar2 >> 0x97,0) & 1) << 0x12 |
              (uint)(SUB321(auVar2 >> 0x9f,0) & 1) << 0x13 |
              (uint)(SUB321(auVar2 >> 0xa7,0) & 1) << 0x14 |
              (uint)(SUB321(auVar2 >> 0xaf,0) & 1) << 0x15 |
              (uint)(SUB321(auVar2 >> 0xb7,0) & 1) << 0x16 | (uint)SUB321(auVar2 >> 0xbf,0) << 0x17
              | (uint)(SUB321(auVar2 >> 199,0) & 1) << 0x18 |
              (uint)(SUB321(auVar2 >> 0xcf,0) & 1) << 0x19 |
              (uint)(SUB321(auVar2 >> 0xd7,0) & 1) << 0x1a |
              (uint)(SUB321(auVar2 >> 0xdf,0) & 1) << 0x1b |
              (uint)(SUB321(auVar2 >> 0xe7,0) & 1) << 0x1c |
              (uint)(SUB321(auVar2 >> 0xef,0) & 1) << 0x1d |
              (uint)(SUB321(auVar2 >> 0xf7,0) & 1) << 0x1e | (uint)(byte)(auVar2[0x1f] >> 7) << 0x1f
      ;
      if (uVar3 != 0) {
        uVar4 = 0;
        for (; (uVar3 & 1) == 0; uVar3 = uVar3 >> 1 | 0x80000000) {
          uVar4 = uVar4 + 1;
        }
        return (undefined1 (*) [32])(*param_1 + uVar4);
      }
      param_1 = param_1 + 1;
    } while (param_1 != (undefined1 (*) [32])(puVar5 + (uVar6 & 0xffffffffffffffe0)));
    uVar6 = (ulonglong)((uint)uVar6 & 0x1f);
  }
  if ((uVar6 & 0xfffffffffffffff0) != 0) {
    puVar5 = *param_1;
    do {
      auVar7[0] = -((*param_1)[0] == param_3);
      auVar7[1] = -((*param_1)[1] == param_3);
      auVar7[2] = -((*param_1)[2] == param_3);
      auVar7[3] = -((*param_1)[3] == param_3);
      auVar7[4] = -((*param_1)[4] == param_3);
      auVar7[5] = -((*param_1)[5] == param_3);
      auVar7[6] = -((*param_1)[6] == param_3);
      auVar7[7] = -((*param_1)[7] == param_3);
      auVar7[8] = -((*param_1)[8] == param_3);
      auVar7[9] = -((*param_1)[9] == param_3);
      auVar7[10] = -((*param_1)[10] == param_3);
      auVar7[0xb] = -((*param_1)[0xb] == param_3);
      auVar7[0xc] = -((*param_1)[0xc] == param_3);
      auVar7[0xd] = -((*param_1)[0xd] == param_3);
      auVar7[0xe] = -((*param_1)[0xe] == param_3);
      auVar7[0xf] = -((*param_1)[0xf] == param_3);
      uVar1 = (ushort)(SUB161(auVar7 >> 7,0) & 1) | (ushort)(SUB161(auVar7 >> 0xf,0) & 1) << 1 |
              (ushort)(SUB161(auVar7 >> 0x17,0) & 1) << 2 |
              (ushort)(SUB161(auVar7 >> 0x1f,0) & 1) << 3 |
              (ushort)(SUB161(auVar7 >> 0x27,0) & 1) << 4 |
              (ushort)(SUB161(auVar7 >> 0x2f,0) & 1) << 5 |
              (ushort)(SUB161(auVar7 >> 0x37,0) & 1) << 6 |
              (ushort)(SUB161(auVar7 >> 0x3f,0) & 1) << 7 |
              (ushort)(SUB161(auVar7 >> 0x47,0) & 1) << 8 |
              (ushort)(SUB161(auVar7 >> 0x4f,0) & 1) << 9 |
              (ushort)(SUB161(auVar7 >> 0x57,0) & 1) << 10 |
              (ushort)(SUB161(auVar7 >> 0x5f,0) & 1) << 0xb |
              (ushort)(SUB161(auVar7 >> 0x67,0) & 1) << 0xc |
              (ushort)(SUB161(auVar7 >> 0x6f,0) & 1) << 0xd |
              (ushort)(SUB161(auVar7 >> 0x77,0) & 1) << 0xe | (ushort)(auVar7[0xf] >> 7) << 0xf;
      if (uVar1 != 0) {
        uVar3 = 0;
        if (uVar1 != 0) {
          for (; (uVar1 >> uVar3 & 1) == 0; uVar3 = uVar3 + 1) {
          }
        }
        return (undefined1 (*) [32])(*param_1 + uVar3);
      }
      param_1 = (undefined1 (*) [32])(*param_1 + 0x10);
    } while (param_1 != (undefined1 (*) [32])(puVar5 + (uVar6 & 0xfffffffffffffff0)));
  }
  for (; (param_1 != param_2 && ((*param_1)[0] != param_3));
      param_1 = (undefined1 (*) [32])(*param_1 + 1)) {
  }
  return param_1;
}

/* ---- FUNC 00047C08 _Facet_Register (56 bytes) ---- */

/* Library Function - Single Match
    void __cdecl std::_Facet_Register(class std::_Facet_base * __ptr64)
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl std::_Facet_Register(_Facet_base *param_1)

{
  undefined8 *puVar1;
  
  puVar1 = operator_new(0x10);
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = DAT_18009c228;
    puVar1[1] = param_1;
  }
  DAT_18009c228 = puVar1;
  return;
}

/* ---- FUNC 00047C40 _Getgloballocale (6 bytes) ---- */

_Locimp * __cdecl std::locale::_Getgloballocale(void)

{
  _Locimp *p_Var1;
  
                    /* WARNING: Could not recover jumptable at 0x000180047c40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  p_Var1 = _Getgloballocale();
  return p_Var1;
}

/* ---- FUNC 00047C46 _Fiopen (6 bytes) ---- */

_iobuf * __cdecl std::_Fiopen(char *param_1,int param_2,int param_3)

{
  _iobuf *p_Var1;
  
                    /* WARNING: Could not recover jumptable at 0x000180047c46. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  p_Var1 = _Fiopen(param_1,param_2,param_3);
  return p_Var1;
}

/* ---- FUNC 00047C4C showmanyc (6 bytes) ---- */

__int64 __thiscall
std::basic_streambuf<char,std::char_traits<char>_>::showmanyc
          (basic_streambuf<char,std::char_traits<char>_> *this)

{
  __int64 _Var1;
  
                    /* WARNING: Could not recover jumptable at 0x000180047c4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = showmanyc(this);
  return _Var1;
}

/* ---- FUNC 00047C60 FUN_180047c60 (16 bytes) ---- */

/* WARNING: Switch with 1 destination removed at 0x000180047c69 */

void FUN_180047c60(undefined8 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018004f010. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_180079230)(param_1,0);
  return;
}

/* ---- FUNC 00047C70 FUN_180047c70 (273 bytes) ---- */

LPSTR FUN_180047c70(LPCWSTR param_1)

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
      FUN_180047c60((ulonglong)uVar2);
    }
    lpMultiByteStr = operator_new__((longlong)iVar1);
    if (lpMultiByteStr == (LPSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_180047c60(0x8007000e);
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
      FUN_180047c60((ulonglong)uVar2);
    }
  }
  return lpMultiByteStr;
}

/* ---- FUNC 00047D90 FUN_180047d90 (407 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

BSTR FUN_180047d90(LPCSTR param_1)

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
  local_28 = DAT_1800791f8 ^ (ulonglong)&local_38;
  if (param_1 != (LPCSTR)0x0) {
    lVar5 = -1;
    do {
      lVar6 = lVar5;
      lVar5 = lVar6 + 1;
    } while (param_1[lVar5] != '\0');
    uVar7 = lVar6 + 2;
    if (0x7fffffff < uVar7) {
                    /* WARNING: Subroutine does not return */
      FUN_180047c60(0x80070057);
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
      FUN_180047c60((ulonglong)uVar3);
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
      *(undefined8 *)(puVar8 + -8) = 0x180047e9f;
      iVar2 = MultiByteToWideChar(0,0,param_1,iVar2,*(LPWSTR *)(puVar8 + 0x20),
                                  *(int *)(puVar8 + 0x28));
      if (iVar2 == 0) {
        if (0xfff < iVar1) {
          *(undefined8 *)(puVar8 + -8) = 0x180047f0e;
          free(psz);
        }
        *(undefined8 *)(puVar8 + -8) = 0x180047f14;
        uVar3 = GetLastError();
        if (0 < (int)uVar3) {
          uVar3 = uVar3 & 0xffff | 0x80070000;
        }
                    /* WARNING: Subroutine does not return */
        *(undefined **)(puVar8 + -8) = &UNK_180047f27;
        FUN_180047c60((ulonglong)uVar3);
      }
      *(undefined8 *)(puVar8 + -8) = 0x180047eac;
      pOVar4 = SysAllocString(psz);
      if (0xfff < iVar1) {
        *(undefined8 *)(puVar8 + -8) = 0x180047ec0;
        free(psz);
      }
      if (pOVar4 != (BSTR)0x0) goto LAB_180047dc2;
    }
                    /* WARNING: Subroutine does not return */
    *(undefined **)(puVar8 + -8) = &UNK_180047ed7;
    FUN_180047c60(0x8007000e);
  }
  pOVar4 = (BSTR)0x0;
LAB_180047dc2:
  *(undefined8 *)(puVar8 + -8) = 0x180047dce;
  return pOVar4;
}

/* ---- FUNC 00047F30 _com_error (68 bytes) ---- */

/* Library Function - Single Match
    public: __cdecl _com_error::_com_error(class _com_error const & __ptr64) __ptr64
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

_com_error * __thiscall _com_error::_com_error(_com_error *this,_com_error *param_1)

{
  longlong lVar1;
  
  *(undefined ***)this = &PTR__scalar_deleting_destructor__180057bb8;
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  lVar1 = *(longlong *)(param_1 + 0x10);
  *(longlong *)(this + 0x10) = lVar1;
  *(undefined8 *)(this + 0x18) = 0;
  if (lVar1 != 0) {
    (*(code *)PTR__guard_dispatch_icall_180053248)();
  }
  return this;
}

/* ---- FUNC 00047F80 _com_error (69 bytes) ---- */

/* Library Function - Single Match
    public: __cdecl _com_error::_com_error(long,struct IErrorInfo * __ptr64,bool) __ptr64
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

_com_error * __thiscall
_com_error::_com_error(_com_error *this,long param_1,IErrorInfo *param_2,bool param_3)

{
  *(long *)(this + 8) = param_1;
  *(undefined ***)this = &PTR__scalar_deleting_destructor__180057bb8;
  *(IErrorInfo **)(this + 0x10) = param_2;
  *(undefined8 *)(this + 0x18) = 0;
  if ((param_2 != (IErrorInfo *)0x0) && (param_3)) {
    (*(code *)PTR__guard_dispatch_icall_180053248)(param_2);
  }
  return this;
}

/* ---- FUNC 00047FD0 ~_com_error (68 bytes) ---- */

/* Library Function - Single Match
    public: virtual __cdecl _com_error::~_com_error(void) __ptr64
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __thiscall _com_error::~_com_error(_com_error *this)

{
  *(undefined ***)this = &PTR__scalar_deleting_destructor__180057bb8;
  if (*(longlong *)(this + 0x10) != 0) {
    (*(code *)PTR__guard_dispatch_icall_180053248)();
  }
  if (*(HLOCAL *)(this + 0x18) != (HLOCAL)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000180048007. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    LocalFree(*(HLOCAL *)(this + 0x18));
    return;
  }
  return;
}

/* ---- FUNC 00048020 `scalar_deleting_destructor' (95 bytes) ---- */

/* Library Function - Single Match
    public: virtual void * __ptr64 __cdecl _com_error::`scalar deleting destructor'(unsigned int)
   __ptr64
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void * __thiscall _com_error::_scalar_deleting_destructor_(_com_error *this,uint param_1)

{
  *(undefined ***)this = &PTR__scalar_deleting_destructor__180057bb8;
  if (*(longlong *)(this + 0x10) != 0) {
    (*(code *)PTR__guard_dispatch_icall_180053248)();
  }
  if (*(HLOCAL *)(this + 0x18) != (HLOCAL)0x0) {
    LocalFree(*(HLOCAL *)(this + 0x18));
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

/* ---- FUNC 00048080 FUN_180048080 (39 bytes) ---- */

void FUN_180048080(long param_1,IErrorInfo *param_2)

{
  _com_error local_28 [40];
  
  _com_error::_com_error(local_28,param_1,param_2,false);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_28,(ThrowInfo *)&DAT_1800653e0);
}

/* ---- FUNC 000480B0 FUN_1800480b0 (16 bytes) ---- */

byte FUN_1800480b0(longlong *param_1,uint param_2)

{
  int iVar1;
  longlong *plVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  ushort uVar9;
  
  iVar1 = *(int *)(*param_1 + 8);
  uVar8 = (int)param_1[3] - 5;
  if (*(uint *)((longlong)param_1 + 0x44) < uVar8) {
    uVar8 = *(uint *)((longlong)param_1 + 0x44);
  }
  uVar9 = 0;
  while( true ) {
    uVar3 = *(int *)((longlong)param_1 + 0x1714) + 0x2a >> 3;
    uVar4 = *(uint *)(*param_1 + 0x18);
    if (uVar4 < uVar3) break;
    uVar4 = uVar4 - uVar3;
    uVar7 = *(int *)((longlong)param_1 + 0x94) - *(int *)((longlong)param_1 + 0x84);
    uVar6 = *(int *)(*param_1 + 8) + uVar7;
    uVar3 = 0xffff;
    if (uVar6 < 0xffff) {
      uVar3 = uVar6;
    }
    if (uVar4 < uVar3) {
      uVar3 = uVar4;
    }
    if ((uVar3 < uVar8) &&
       ((((uVar3 == 0 && (param_2 != 4)) || (param_2 == 0)) || (uVar3 != uVar6)))) break;
    if ((param_2 == 4) && (uVar3 == uVar6)) {
      uVar9 = 1;
    }
    else {
      uVar9 = 0;
    }
    FUN_18004c820((longlong)param_1,(void *)0x0,0,uVar9);
    *(byte *)((ulonglong)((int)param_1[5] - 4) + param_1[2]) = (byte)uVar3;
    bVar5 = (byte)(uVar3 >> 8);
    *(byte *)((ulonglong)((int)param_1[5] - 3) + param_1[2]) = bVar5;
    *(byte *)((ulonglong)((int)param_1[5] - 2) + param_1[2]) = ~(byte)uVar3;
    *(byte *)((ulonglong)((int)param_1[5] - 1) + param_1[2]) = ~bVar5;
    FUN_18004a2e0(*param_1);
    if (uVar7 != 0) {
      if (uVar3 < uVar7) {
        uVar7 = uVar3;
      }
      memcpy(*(void **)(*param_1 + 0x10),
             (void *)((longlong)*(int *)((longlong)param_1 + 0x84) + param_1[10]),(ulonglong)uVar7);
      *(longlong *)(*param_1 + 0x10) = *(longlong *)(*param_1 + 0x10) + (ulonglong)uVar7;
      *(int *)(*param_1 + 0x18) = *(int *)(*param_1 + 0x18) - uVar7;
      *(int *)(*param_1 + 0x1c) = *(int *)(*param_1 + 0x1c) + uVar7;
      *(int *)((longlong)param_1 + 0x84) = *(int *)((longlong)param_1 + 0x84) + uVar7;
      uVar3 = uVar3 - uVar7;
    }
    if (uVar3 != 0) {
      read_buf((longlong *)*param_1,(uint *)((longlong *)*param_1)[2],uVar3);
      *(longlong *)(*param_1 + 0x10) = *(longlong *)(*param_1 + 0x10) + (ulonglong)uVar3;
      *(int *)(*param_1 + 0x18) = *(int *)(*param_1 + 0x18) - uVar3;
      *(int *)(*param_1 + 0x1c) = *(int *)(*param_1 + 0x1c) + uVar3;
    }
    if (uVar9 != 0) break;
  }
  uVar8 = iVar1 - (int)((longlong *)*param_1)[1];
  if (uVar8 != 0) {
    uVar4 = *(uint *)((longlong)param_1 + 0x44);
    if (uVar8 < uVar4) {
      if ((uint)((int)param_1[0xb] - *(int *)((longlong)param_1 + 0x94)) <= uVar8) {
        uVar3 = *(int *)((longlong)param_1 + 0x94) - uVar4;
        *(uint *)((longlong)param_1 + 0x94) = uVar3;
        memcpy((void *)param_1[10],(void *)((ulonglong)uVar4 + param_1[10]),(ulonglong)uVar3);
        if (*(uint *)(param_1 + 0x2e1) < 2) {
          *(uint *)(param_1 + 0x2e1) = *(uint *)(param_1 + 0x2e1) + 1;
        }
      }
      memcpy((void *)((ulonglong)*(uint *)((longlong)param_1 + 0x94) + param_1[10]),
             (void *)(*(longlong *)*param_1 - (ulonglong)uVar8),(ulonglong)uVar8);
      *(int *)((longlong)param_1 + 0x94) = *(int *)((longlong)param_1 + 0x94) + uVar8;
    }
    else {
      *(undefined4 *)(param_1 + 0x2e1) = 2;
      memcpy((void *)param_1[10],(void *)(*(longlong *)*param_1 - (ulonglong)uVar4),(ulonglong)uVar4
            );
      *(undefined4 *)((longlong)param_1 + 0x94) = *(undefined4 *)((longlong)param_1 + 0x44);
    }
    *(undefined4 *)((longlong)param_1 + 0x84) = *(undefined4 *)((longlong)param_1 + 0x94);
    uVar4 = *(int *)((longlong)param_1 + 0x44) - *(int *)((longlong)param_1 + 0x170c);
    if (uVar4 < uVar8) {
      uVar8 = uVar4;
    }
    *(uint *)((longlong)param_1 + 0x170c) = *(int *)((longlong)param_1 + 0x170c) + uVar8;
  }
  uVar8 = *(uint *)((longlong)param_1 + 0x94);
  if (*(uint *)(param_1 + 0x2e3) < uVar8) {
    *(uint *)(param_1 + 0x2e3) = uVar8;
  }
  if (uVar9 != 0) {
    return 3;
  }
  if ((((param_2 & 0xfffffffb) != 0) && (*(int *)(*param_1 + 8) == 0)) &&
     (uVar8 == *(uint *)((longlong)param_1 + 0x84))) {
    return 1;
  }
  uVar8 = ((int)param_1[0xb] - uVar8) - 1;
  if (uVar8 < *(uint *)(*param_1 + 8)) {
    uVar4 = *(uint *)((longlong)param_1 + 0x44);
    if ((int)uVar4 <= *(int *)((longlong)param_1 + 0x84)) {
      *(int *)((longlong)param_1 + 0x94) = *(int *)((longlong)param_1 + 0x94) - uVar4;
      *(uint *)((longlong)param_1 + 0x84) = *(int *)((longlong)param_1 + 0x84) - uVar4;
      memcpy((void *)param_1[10],(void *)(param_1[10] + (ulonglong)uVar4),
             (ulonglong)*(uint *)((longlong)param_1 + 0x94));
      if (*(uint *)(param_1 + 0x2e1) < 2) {
        *(uint *)(param_1 + 0x2e1) = *(uint *)(param_1 + 0x2e1) + 1;
      }
      uVar8 = uVar8 + *(int *)((longlong)param_1 + 0x44);
    }
  }
  plVar2 = (longlong *)*param_1;
  if (*(uint *)(plVar2 + 1) < uVar8) {
    uVar8 = *(uint *)(plVar2 + 1);
  }
  if (uVar8 != 0) {
    read_buf(plVar2,(uint *)((ulonglong)*(uint *)((longlong)param_1 + 0x94) + param_1[10]),uVar8);
    *(int *)((longlong)param_1 + 0x94) = *(int *)((longlong)param_1 + 0x94) + uVar8;
  }
  if (*(uint *)(param_1 + 0x2e3) < *(uint *)((longlong)param_1 + 0x94)) {
    *(uint *)(param_1 + 0x2e3) = *(uint *)((longlong)param_1 + 0x94);
  }
  uVar8 = (int)param_1[3] - (*(int *)((longlong)param_1 + 0x1714) + 0x2a >> 3);
  if (0xffff < uVar8) {
    uVar8 = 0xffff;
  }
  uVar4 = uVar8;
  if (*(uint *)((longlong)param_1 + 0x44) < uVar8) {
    uVar4 = *(uint *)((longlong)param_1 + 0x44);
  }
  uVar3 = *(int *)((longlong)param_1 + 0x94) - *(int *)((longlong)param_1 + 0x84);
  if ((uVar4 <= uVar3) ||
     ((((uVar9 = 0, uVar3 != 0 || (param_2 == 4)) && (param_2 != 0)) &&
      ((*(int *)(*param_1 + 8) == 0 && (uVar3 <= uVar8)))))) {
    uVar4 = uVar3;
    if (uVar8 < uVar3) {
      uVar4 = uVar8;
    }
    if (((param_2 == 4) && (*(int *)(*param_1 + 8) == 0)) && (uVar4 == uVar3)) {
      uVar9 = 1;
    }
    else {
      uVar9 = 0;
    }
    FUN_18004c820((longlong)param_1,
                  (void *)((longlong)*(int *)((longlong)param_1 + 0x84) + param_1[10]),uVar4,uVar9);
    *(int *)((longlong)param_1 + 0x84) = *(int *)((longlong)param_1 + 0x84) + uVar4;
    FUN_18004a2e0(*param_1);
  }
  return -(uVar9 != 0) & 2;
}

/* ---- FUNC 000480C0 FUN_1800480c0 (8 bytes) ---- */

byte FUN_1800480c0(longlong *param_1)

{
  longlong *plVar1;
  uint uVar2;
  longlong in_RAX;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ushort uVar8;
  uint unaff_R15D;
  int iStack0000000000000050;
  
  iStack0000000000000050 = *(int *)(in_RAX + 8);
  uVar7 = (int)param_1[3] - 5;
  if (*(uint *)((longlong)param_1 + 0x44) < uVar7) {
    uVar7 = *(uint *)((longlong)param_1 + 0x44);
  }
  uVar8 = 0;
  while( true ) {
    uVar2 = *(int *)((longlong)param_1 + 0x1714) + 0x2a >> 3;
    uVar3 = *(uint *)(*param_1 + 0x18);
    if (uVar3 < uVar2) break;
    uVar3 = uVar3 - uVar2;
    uVar6 = *(int *)((longlong)param_1 + 0x94) - *(int *)((longlong)param_1 + 0x84);
    uVar5 = *(int *)(*param_1 + 8) + uVar6;
    uVar2 = 0xffff;
    if (uVar5 < 0xffff) {
      uVar2 = uVar5;
    }
    if (uVar3 < uVar2) {
      uVar2 = uVar3;
    }
    if ((uVar2 < uVar7) &&
       ((((uVar2 == 0 && (unaff_R15D != 4)) || (unaff_R15D == 0)) || (uVar2 != uVar5)))) break;
    if ((unaff_R15D == 4) && (uVar2 == uVar5)) {
      uVar8 = 1;
    }
    else {
      uVar8 = 0;
    }
    FUN_18004c820((longlong)param_1,(void *)0x0,0,uVar8);
    *(byte *)((ulonglong)((int)param_1[5] - 4) + param_1[2]) = (byte)uVar2;
    bVar4 = (byte)(uVar2 >> 8);
    *(byte *)((ulonglong)((int)param_1[5] - 3) + param_1[2]) = bVar4;
    *(byte *)((ulonglong)((int)param_1[5] - 2) + param_1[2]) = ~(byte)uVar2;
    *(byte *)((ulonglong)((int)param_1[5] - 1) + param_1[2]) = ~bVar4;
    FUN_18004a2e0(*param_1);
    if (uVar6 != 0) {
      if (uVar2 < uVar6) {
        uVar6 = uVar2;
      }
      memcpy(*(void **)(*param_1 + 0x10),
             (void *)((longlong)*(int *)((longlong)param_1 + 0x84) + param_1[10]),(ulonglong)uVar6);
      *(longlong *)(*param_1 + 0x10) = *(longlong *)(*param_1 + 0x10) + (ulonglong)uVar6;
      *(int *)(*param_1 + 0x18) = *(int *)(*param_1 + 0x18) - uVar6;
      *(int *)(*param_1 + 0x1c) = *(int *)(*param_1 + 0x1c) + uVar6;
      *(int *)((longlong)param_1 + 0x84) = *(int *)((longlong)param_1 + 0x84) + uVar6;
      uVar2 = uVar2 - uVar6;
    }
    if (uVar2 != 0) {
      read_buf((longlong *)*param_1,(uint *)((longlong *)*param_1)[2],uVar2);
      *(longlong *)(*param_1 + 0x10) = *(longlong *)(*param_1 + 0x10) + (ulonglong)uVar2;
      *(int *)(*param_1 + 0x18) = *(int *)(*param_1 + 0x18) - uVar2;
      *(int *)(*param_1 + 0x1c) = *(int *)(*param_1 + 0x1c) + uVar2;
    }
    if (uVar8 != 0) break;
  }
  uVar7 = iStack0000000000000050 - (int)((longlong *)*param_1)[1];
  if (uVar7 != 0) {
    uVar3 = *(uint *)((longlong)param_1 + 0x44);
    if (uVar7 < uVar3) {
      if ((uint)((int)param_1[0xb] - *(int *)((longlong)param_1 + 0x94)) <= uVar7) {
        uVar2 = *(int *)((longlong)param_1 + 0x94) - uVar3;
        *(uint *)((longlong)param_1 + 0x94) = uVar2;
        memcpy((void *)param_1[10],(void *)((ulonglong)uVar3 + param_1[10]),(ulonglong)uVar2);
        if (*(uint *)(param_1 + 0x2e1) < 2) {
          *(uint *)(param_1 + 0x2e1) = *(uint *)(param_1 + 0x2e1) + 1;
        }
      }
      memcpy((void *)((ulonglong)*(uint *)((longlong)param_1 + 0x94) + param_1[10]),
             (void *)(*(longlong *)*param_1 - (ulonglong)uVar7),(ulonglong)uVar7);
      *(int *)((longlong)param_1 + 0x94) = *(int *)((longlong)param_1 + 0x94) + uVar7;
    }
    else {
      *(undefined4 *)(param_1 + 0x2e1) = 2;
      memcpy((void *)param_1[10],(void *)(*(longlong *)*param_1 - (ulonglong)uVar3),(ulonglong)uVar3
            );
      *(undefined4 *)((longlong)param_1 + 0x94) = *(undefined4 *)((longlong)param_1 + 0x44);
    }
    *(undefined4 *)((longlong)param_1 + 0x84) = *(undefined4 *)((longlong)param_1 + 0x94);
    uVar3 = *(int *)((longlong)param_1 + 0x44) - *(int *)((longlong)param_1 + 0x170c);
    if (uVar3 < uVar7) {
      uVar7 = uVar3;
    }
    *(uint *)((longlong)param_1 + 0x170c) = *(int *)((longlong)param_1 + 0x170c) + uVar7;
  }
  uVar7 = *(uint *)((longlong)param_1 + 0x94);
  if (*(uint *)(param_1 + 0x2e3) < uVar7) {
    *(uint *)(param_1 + 0x2e3) = uVar7;
  }
  if (uVar8 != 0) {
    return 3;
  }
  if ((((unaff_R15D & 0xfffffffb) != 0) && (*(int *)(*param_1 + 8) == 0)) &&
     (uVar7 == *(uint *)((longlong)param_1 + 0x84))) {
    return 1;
  }
  uVar7 = ((int)param_1[0xb] - uVar7) - 1;
  if (uVar7 < *(uint *)(*param_1 + 8)) {
    uVar3 = *(uint *)((longlong)param_1 + 0x44);
    if ((int)uVar3 <= *(int *)((longlong)param_1 + 0x84)) {
      *(int *)((longlong)param_1 + 0x94) = *(int *)((longlong)param_1 + 0x94) - uVar3;
      *(uint *)((longlong)param_1 + 0x84) = *(int *)((longlong)param_1 + 0x84) - uVar3;
      memcpy((void *)param_1[10],(void *)(param_1[10] + (ulonglong)uVar3),
             (ulonglong)*(uint *)((longlong)param_1 + 0x94));
      if (*(uint *)(param_1 + 0x2e1) < 2) {
        *(uint *)(param_1 + 0x2e1) = *(uint *)(param_1 + 0x2e1) + 1;
      }
      uVar7 = uVar7 + *(int *)((longlong)param_1 + 0x44);
    }
  }
  plVar1 = (longlong *)*param_1;
  if (*(uint *)(plVar1 + 1) < uVar7) {
    uVar7 = *(uint *)(plVar1 + 1);
  }
  if (uVar7 != 0) {
    read_buf(plVar1,(uint *)((ulonglong)*(uint *)((longlong)param_1 + 0x94) + param_1[10]),uVar7);
    *(int *)((longlong)param_1 + 0x94) = *(int *)((longlong)param_1 + 0x94) + uVar7;
  }
  if (*(uint *)(param_1 + 0x2e3) < *(uint *)((longlong)param_1 + 0x94)) {
    *(uint *)(param_1 + 0x2e3) = *(uint *)((longlong)param_1 + 0x94);
  }
  uVar7 = (int)param_1[3] - (*(int *)((longlong)param_1 + 0x1714) + 0x2a >> 3);
  if (0xffff < uVar7) {
    uVar7 = 0xffff;
  }
  uVar3 = uVar7;
  if (*(uint *)((longlong)param_1 + 0x44) < uVar7) {
    uVar3 = *(uint *)((longlong)param_1 + 0x44);
  }
  uVar2 = *(int *)((longlong)param_1 + 0x94) - *(int *)((longlong)param_1 + 0x84);
  if ((uVar3 <= uVar2) ||
     ((((uVar8 = 0, uVar2 != 0 || (unaff_R15D == 4)) && (unaff_R15D != 0)) &&
      ((*(int *)(*param_1 + 8) == 0 && (uVar2 <= uVar7)))))) {
    uVar3 = uVar2;
    if (uVar7 < uVar2) {
      uVar3 = uVar7;
    }
    if (((unaff_R15D == 4) && (*(int *)(*param_1 + 8) == 0)) && (uVar3 == uVar2)) {
      uVar8 = 1;
    }
    else {
      uVar8 = 0;
    }
    FUN_18004c820((longlong)param_1,
                  (void *)((longlong)*(int *)((longlong)param_1 + 0x84) + param_1[10]),uVar3,uVar8);
    *(int *)((longlong)param_1 + 0x84) = *(int *)((longlong)param_1 + 0x84) + uVar3;
    FUN_18004a2e0(*param_1);
  }
  return -(uVar8 != 0) & 2;
}

/* ---- FUNC 000480C8 FUN_1800480c8 (410 bytes) ---- */

byte FUN_1800480c8(longlong param_1)

{
  longlong *plVar1;
  uint uVar2;
  longlong in_RAX;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  longlong *unaff_RBX;
  uint uVar6;
  uint uVar7;
  ushort uVar8;
  uint unaff_R15D;
  int iStack0000000000000050;
  
  iStack0000000000000050 = *(int *)(in_RAX + 8);
  uVar7 = *(int *)(param_1 + 0x18) - 5;
  if (*(uint *)(param_1 + 0x44) < uVar7) {
    uVar7 = *(uint *)(param_1 + 0x44);
  }
  uVar8 = 0;
  while( true ) {
    uVar2 = *(int *)((longlong)unaff_RBX + 0x1714) + 0x2a >> 3;
    uVar3 = *(uint *)(*unaff_RBX + 0x18);
    if (uVar3 < uVar2) break;
    uVar3 = uVar3 - uVar2;
    uVar6 = *(int *)((longlong)unaff_RBX + 0x94) - *(int *)((longlong)unaff_RBX + 0x84);
    uVar5 = *(int *)(*unaff_RBX + 8) + uVar6;
    uVar2 = 0xffff;
    if (uVar5 < 0xffff) {
      uVar2 = uVar5;
    }
    if (uVar3 < uVar2) {
      uVar2 = uVar3;
    }
    if ((uVar2 < uVar7) &&
       ((((uVar2 == 0 && (unaff_R15D != 4)) || (unaff_R15D == 0)) || (uVar2 != uVar5)))) break;
    if ((unaff_R15D == 4) && (uVar2 == uVar5)) {
      uVar8 = 1;
    }
    else {
      uVar8 = 0;
    }
    FUN_18004c820((longlong)unaff_RBX,(void *)0x0,0,uVar8);
    *(byte *)((ulonglong)((int)unaff_RBX[5] - 4) + unaff_RBX[2]) = (byte)uVar2;
    bVar4 = (byte)(uVar2 >> 8);
    *(byte *)((ulonglong)((int)unaff_RBX[5] - 3) + unaff_RBX[2]) = bVar4;
    *(byte *)((ulonglong)((int)unaff_RBX[5] - 2) + unaff_RBX[2]) = ~(byte)uVar2;
    *(byte *)((ulonglong)((int)unaff_RBX[5] - 1) + unaff_RBX[2]) = ~bVar4;
    FUN_18004a2e0(*unaff_RBX);
    if (uVar6 != 0) {
      if (uVar2 < uVar6) {
        uVar6 = uVar2;
      }
      memcpy(*(void **)(*unaff_RBX + 0x10),
             (void *)((longlong)*(int *)((longlong)unaff_RBX + 0x84) + unaff_RBX[10]),
             (ulonglong)uVar6);
      *(longlong *)(*unaff_RBX + 0x10) = *(longlong *)(*unaff_RBX + 0x10) + (ulonglong)uVar6;
      *(int *)(*unaff_RBX + 0x18) = *(int *)(*unaff_RBX + 0x18) - uVar6;
      *(int *)(*unaff_RBX + 0x1c) = *(int *)(*unaff_RBX + 0x1c) + uVar6;
      *(int *)((longlong)unaff_RBX + 0x84) = *(int *)((longlong)unaff_RBX + 0x84) + uVar6;
      uVar2 = uVar2 - uVar6;
    }
    if (uVar2 != 0) {
      read_buf((longlong *)*unaff_RBX,(uint *)((longlong *)*unaff_RBX)[2],uVar2);
      *(longlong *)(*unaff_RBX + 0x10) = *(longlong *)(*unaff_RBX + 0x10) + (ulonglong)uVar2;
      *(int *)(*unaff_RBX + 0x18) = *(int *)(*unaff_RBX + 0x18) - uVar2;
      *(int *)(*unaff_RBX + 0x1c) = *(int *)(*unaff_RBX + 0x1c) + uVar2;
    }
    if (uVar8 != 0) break;
  }
  uVar7 = iStack0000000000000050 - (int)((longlong *)*unaff_RBX)[1];
  if (uVar7 != 0) {
    uVar3 = *(uint *)((longlong)unaff_RBX + 0x44);
    if (uVar7 < uVar3) {
      if ((uint)((int)unaff_RBX[0xb] - *(int *)((longlong)unaff_RBX + 0x94)) <= uVar7) {
        uVar2 = *(int *)((longlong)unaff_RBX + 0x94) - uVar3;
        *(uint *)((longlong)unaff_RBX + 0x94) = uVar2;
        memcpy((void *)unaff_RBX[10],(void *)((ulonglong)uVar3 + unaff_RBX[10]),(ulonglong)uVar2);
        if (*(uint *)(unaff_RBX + 0x2e1) < 2) {
          *(uint *)(unaff_RBX + 0x2e1) = *(uint *)(unaff_RBX + 0x2e1) + 1;
        }
      }
      memcpy((void *)((ulonglong)*(uint *)((longlong)unaff_RBX + 0x94) + unaff_RBX[10]),
             (void *)(*(longlong *)*unaff_RBX - (ulonglong)uVar7),(ulonglong)uVar7);
      *(int *)((longlong)unaff_RBX + 0x94) = *(int *)((longlong)unaff_RBX + 0x94) + uVar7;
    }
    else {
      *(undefined4 *)(unaff_RBX + 0x2e1) = 2;
      memcpy((void *)unaff_RBX[10],(void *)(*(longlong *)*unaff_RBX - (ulonglong)uVar3),
             (ulonglong)uVar3);
      *(undefined4 *)((longlong)unaff_RBX + 0x94) = *(undefined4 *)((longlong)unaff_RBX + 0x44);
    }
    *(undefined4 *)((longlong)unaff_RBX + 0x84) = *(undefined4 *)((longlong)unaff_RBX + 0x94);
    uVar3 = *(int *)((longlong)unaff_RBX + 0x44) - *(int *)((longlong)unaff_RBX + 0x170c);
    if (uVar3 < uVar7) {
      uVar7 = uVar3;
    }
    *(uint *)((longlong)unaff_RBX + 0x170c) = *(int *)((longlong)unaff_RBX + 0x170c) + uVar7;
  }
  uVar7 = *(uint *)((longlong)unaff_RBX + 0x94);
  if (*(uint *)(unaff_RBX + 0x2e3) < uVar7) {
    *(uint *)(unaff_RBX + 0x2e3) = uVar7;
  }
  if (uVar8 != 0) {
    return 3;
  }
  if ((((unaff_R15D & 0xfffffffb) != 0) && (*(int *)(*unaff_RBX + 8) == 0)) &&
     (uVar7 == *(uint *)((longlong)unaff_RBX + 0x84))) {
    return 1;
  }
  uVar7 = ((int)unaff_RBX[0xb] - uVar7) - 1;
  if (uVar7 < *(uint *)(*unaff_RBX + 8)) {
    uVar3 = *(uint *)((longlong)unaff_RBX + 0x44);
    if ((int)uVar3 <= *(int *)((longlong)unaff_RBX + 0x84)) {
      *(int *)((longlong)unaff_RBX + 0x94) = *(int *)((longlong)unaff_RBX + 0x94) - uVar3;
      *(uint *)((longlong)unaff_RBX + 0x84) = *(int *)((longlong)unaff_RBX + 0x84) - uVar3;
      memcpy((void *)unaff_RBX[10],(void *)(unaff_RBX[10] + (ulonglong)uVar3),
             (ulonglong)*(uint *)((longlong)unaff_RBX + 0x94));
      if (*(uint *)(unaff_RBX + 0x2e1) < 2) {
        *(uint *)(unaff_RBX + 0x2e1) = *(uint *)(unaff_RBX + 0x2e1) + 1;
      }
      uVar7 = uVar7 + *(int *)((longlong)unaff_RBX + 0x44);
    }
  }
  plVar1 = (longlong *)*unaff_RBX;
  if (*(uint *)(plVar1 + 1) < uVar7) {
    uVar7 = *(uint *)(plVar1 + 1);
  }
  if (uVar7 != 0) {
    read_buf(plVar1,(uint *)((ulonglong)*(uint *)((longlong)unaff_RBX + 0x94) + unaff_RBX[10]),uVar7
            );
    *(int *)((longlong)unaff_RBX + 0x94) = *(int *)((longlong)unaff_RBX + 0x94) + uVar7;
  }
  if (*(uint *)(unaff_RBX + 0x2e3) < *(uint *)((longlong)unaff_RBX + 0x94)) {
    *(uint *)(unaff_RBX + 0x2e3) = *(uint *)((longlong)unaff_RBX + 0x94);
  }
  uVar7 = (int)unaff_RBX[3] - (*(int *)((longlong)unaff_RBX + 0x1714) + 0x2a >> 3);
  if (0xffff < uVar7) {
    uVar7 = 0xffff;
  }
  uVar3 = uVar7;
  if (*(uint *)((longlong)unaff_RBX + 0x44) < uVar7) {
    uVar3 = *(uint *)((longlong)unaff_RBX + 0x44);
  }
  uVar2 = *(int *)((longlong)unaff_RBX + 0x94) - *(int *)((longlong)unaff_RBX + 0x84);
  if ((uVar3 <= uVar2) ||
     ((((uVar8 = 0, uVar2 != 0 || (unaff_R15D == 4)) && (unaff_R15D != 0)) &&
      ((*(int *)(*unaff_RBX + 8) == 0 && (uVar2 <= uVar7)))))) {
    uVar3 = uVar2;
    if (uVar7 < uVar2) {
      uVar3 = uVar7;
    }
    if (((unaff_R15D == 4) && (*(int *)(*unaff_RBX + 8) == 0)) && (uVar3 == uVar2)) {
      uVar8 = 1;
    }
    else {
      uVar8 = 0;
    }
    FUN_18004c820((longlong)unaff_RBX,
                  (void *)((longlong)*(int *)((longlong)unaff_RBX + 0x84) + unaff_RBX[10]),uVar3,
                  uVar8);
    *(int *)((longlong)unaff_RBX + 0x84) = *(int *)((longlong)unaff_RBX + 0x84) + uVar3;
    FUN_18004a2e0(*unaff_RBX);
  }
  return -(uVar8 != 0) & 2;
}

/* ---- FUNC 00048262 FUN_180048262 (199 bytes) ---- */

byte FUN_180048262(void)

{
  longlong *plVar1;
  uint uVar2;
  longlong *in_RAX;
  uint uVar3;
  uint uVar4;
  longlong *unaff_RBX;
  uint unaff_R12D;
  ushort uVar5;
  int unaff_R14D;
  uint unaff_R15D;
  
  uVar2 = *(uint *)((longlong)unaff_RBX + 0x44);
  if (unaff_R12D < uVar2) {
    if ((uint)((int)unaff_RBX[0xb] - *(int *)((longlong)unaff_RBX + 0x94)) <= unaff_R12D) {
      uVar3 = *(int *)((longlong)unaff_RBX + 0x94) - uVar2;
      *(uint *)((longlong)unaff_RBX + 0x94) = uVar3;
      memcpy((void *)unaff_RBX[10],(void *)((ulonglong)uVar2 + unaff_RBX[10]),(ulonglong)uVar3);
      if (*(uint *)(unaff_RBX + 0x2e1) < 2) {
        *(uint *)(unaff_RBX + 0x2e1) = *(uint *)(unaff_RBX + 0x2e1) + 1;
      }
    }
    memcpy((void *)((ulonglong)*(uint *)((longlong)unaff_RBX + 0x94) + unaff_RBX[10]),
           (void *)(*(longlong *)*unaff_RBX - (ulonglong)unaff_R12D),(ulonglong)unaff_R12D);
    *(int *)((longlong)unaff_RBX + 0x94) = *(int *)((longlong)unaff_RBX + 0x94) + unaff_R12D;
  }
  else {
    *(undefined4 *)(unaff_RBX + 0x2e1) = 2;
    memcpy((void *)unaff_RBX[10],(void *)(*in_RAX - (ulonglong)uVar2),(ulonglong)uVar2);
    *(undefined4 *)((longlong)unaff_RBX + 0x94) = *(undefined4 *)((longlong)unaff_RBX + 0x44);
  }
  *(undefined4 *)((longlong)unaff_RBX + 0x84) = *(undefined4 *)((longlong)unaff_RBX + 0x94);
  uVar2 = *(int *)((longlong)unaff_RBX + 0x44) - *(int *)((longlong)unaff_RBX + 0x170c);
  if (uVar2 < unaff_R12D) {
    unaff_R12D = uVar2;
  }
  *(uint *)((longlong)unaff_RBX + 0x170c) = *(int *)((longlong)unaff_RBX + 0x170c) + unaff_R12D;
  uVar2 = *(uint *)((longlong)unaff_RBX + 0x94);
  if (*(uint *)(unaff_RBX + 0x2e3) < uVar2) {
    *(uint *)(unaff_RBX + 0x2e3) = uVar2;
  }
  if (unaff_R14D != 0) {
    return 3;
  }
  if ((((unaff_R15D & 0xfffffffb) != 0) && (*(int *)(*unaff_RBX + 8) == 0)) &&
     (uVar2 == *(uint *)((longlong)unaff_RBX + 0x84))) {
    return 1;
  }
  uVar2 = ((int)unaff_RBX[0xb] - uVar2) - 1;
  if (uVar2 < *(uint *)(*unaff_RBX + 8)) {
    uVar3 = *(uint *)((longlong)unaff_RBX + 0x44);
    if ((int)uVar3 <= *(int *)((longlong)unaff_RBX + 0x84)) {
      *(int *)((longlong)unaff_RBX + 0x94) = *(int *)((longlong)unaff_RBX + 0x94) - uVar3;
      *(uint *)((longlong)unaff_RBX + 0x84) = *(int *)((longlong)unaff_RBX + 0x84) - uVar3;
      memcpy((void *)unaff_RBX[10],(void *)(unaff_RBX[10] + (ulonglong)uVar3),
             (ulonglong)*(uint *)((longlong)unaff_RBX + 0x94));
      if (*(uint *)(unaff_RBX + 0x2e1) < 2) {
        *(uint *)(unaff_RBX + 0x2e1) = *(uint *)(unaff_RBX + 0x2e1) + 1;
      }
      uVar2 = uVar2 + *(int *)((longlong)unaff_RBX + 0x44);
    }
  }
  plVar1 = (longlong *)*unaff_RBX;
  if (*(uint *)(plVar1 + 1) < uVar2) {
    uVar2 = *(uint *)(plVar1 + 1);
  }
  if (uVar2 != 0) {
    read_buf(plVar1,(uint *)((ulonglong)*(uint *)((longlong)unaff_RBX + 0x94) + unaff_RBX[10]),uVar2
            );
    *(int *)((longlong)unaff_RBX + 0x94) = *(int *)((longlong)unaff_RBX + 0x94) + uVar2;
  }
  if (*(uint *)(unaff_RBX + 0x2e3) < *(uint *)((longlong)unaff_RBX + 0x94)) {
    *(uint *)(unaff_RBX + 0x2e3) = *(uint *)((longlong)unaff_RBX + 0x94);
  }
  uVar2 = (int)unaff_RBX[3] - (*(int *)((longlong)unaff_RBX + 0x1714) + 0x2a >> 3);
  if (0xffff < uVar2) {
    uVar2 = 0xffff;
  }
  uVar3 = uVar2;
  if (*(uint *)((longlong)unaff_RBX + 0x44) < uVar2) {
    uVar3 = *(uint *)((longlong)unaff_RBX + 0x44);
  }
  uVar4 = *(int *)((longlong)unaff_RBX + 0x94) - *(int *)((longlong)unaff_RBX + 0x84);
  if ((uVar3 <= uVar4) ||
     (((uVar5 = 0, uVar4 != 0 || (unaff_R15D == 4)) &&
      ((unaff_R15D != 0 && ((*(int *)(*unaff_RBX + 8) == 0 && (uVar4 <= uVar2)))))))) {
    uVar3 = uVar4;
    if (uVar2 < uVar4) {
      uVar3 = uVar2;
    }
    if (((unaff_R15D == 4) && (*(int *)(*unaff_RBX + 8) == 0)) && (uVar3 == uVar4)) {
      uVar5 = 1;
    }
    else {
      uVar5 = 0;
    }
    FUN_18004c820((longlong)unaff_RBX,
                  (void *)((longlong)*(int *)((longlong)unaff_RBX + 0x84) + unaff_RBX[10]),uVar3,
                  uVar5);
    *(int *)((longlong)unaff_RBX + 0x84) = *(int *)((longlong)unaff_RBX + 0x84) + uVar3;
    FUN_18004a2e0(*unaff_RBX);
  }
  return -(uVar5 != 0) & 2;
}

/* ---- FUNC 00048329 FUN_180048329 (405 bytes) ---- */

byte FUN_180048329(void)

{
  longlong *plVar1;
  int in_EAX;
  uint uVar2;
  uint uVar3;
  longlong *unaff_RBX;
  uint uVar4;
  ushort uVar5;
  int unaff_R14D;
  uint unaff_R15D;
  
  *(int *)(unaff_RBX + 0x2e3) = in_EAX;
  if (unaff_R14D != 0) {
    return 3;
  }
  if ((((unaff_R15D & 0xfffffffb) != 0) && (*(int *)(*unaff_RBX + 8) == 0)) &&
     (in_EAX == *(int *)((longlong)unaff_RBX + 0x84))) {
    return 1;
  }
  uVar4 = ((int)unaff_RBX[0xb] - in_EAX) - 1;
  if (uVar4 < *(uint *)(*unaff_RBX + 8)) {
    uVar2 = *(uint *)((longlong)unaff_RBX + 0x44);
    if ((int)uVar2 <= *(int *)((longlong)unaff_RBX + 0x84)) {
      *(int *)((longlong)unaff_RBX + 0x94) = *(int *)((longlong)unaff_RBX + 0x94) - uVar2;
      *(uint *)((longlong)unaff_RBX + 0x84) = *(int *)((longlong)unaff_RBX + 0x84) - uVar2;
      memcpy((void *)unaff_RBX[10],(void *)(unaff_RBX[10] + (ulonglong)uVar2),
             (ulonglong)*(uint *)((longlong)unaff_RBX + 0x94));
      if (*(uint *)(unaff_RBX + 0x2e1) < 2) {
        *(uint *)(unaff_RBX + 0x2e1) = *(uint *)(unaff_RBX + 0x2e1) + 1;
      }
      uVar4 = uVar4 + *(int *)((longlong)unaff_RBX + 0x44);
    }
  }
  plVar1 = (longlong *)*unaff_RBX;
  if (*(uint *)(plVar1 + 1) < uVar4) {
    uVar4 = *(uint *)(plVar1 + 1);
  }
  if (uVar4 != 0) {
    read_buf(plVar1,(uint *)((ulonglong)*(uint *)((longlong)unaff_RBX + 0x94) + unaff_RBX[10]),uVar4
            );
    *(int *)((longlong)unaff_RBX + 0x94) = *(int *)((longlong)unaff_RBX + 0x94) + uVar4;
  }
  if (*(uint *)(unaff_RBX + 0x2e3) < *(uint *)((longlong)unaff_RBX + 0x94)) {
    *(uint *)(unaff_RBX + 0x2e3) = *(uint *)((longlong)unaff_RBX + 0x94);
  }
  uVar4 = (int)unaff_RBX[3] - (*(int *)((longlong)unaff_RBX + 0x1714) + 0x2a >> 3);
  if (0xffff < uVar4) {
    uVar4 = 0xffff;
  }
  uVar2 = uVar4;
  if (*(uint *)((longlong)unaff_RBX + 0x44) < uVar4) {
    uVar2 = *(uint *)((longlong)unaff_RBX + 0x44);
  }
  uVar3 = *(int *)((longlong)unaff_RBX + 0x94) - *(int *)((longlong)unaff_RBX + 0x84);
  if ((uVar2 <= uVar3) ||
     (((uVar5 = 0, uVar3 != 0 || (unaff_R15D == 4)) &&
      ((unaff_R15D != 0 && ((*(int *)(*unaff_RBX + 8) == 0 && (uVar3 <= uVar4)))))))) {
    uVar2 = uVar3;
    if (uVar4 < uVar3) {
      uVar2 = uVar4;
    }
    if (((unaff_R15D == 4) && (*(int *)(*unaff_RBX + 8) == 0)) && (uVar2 == uVar3)) {
      uVar5 = 1;
    }
    else {
      uVar5 = 0;
    }
    FUN_18004c820((longlong)unaff_RBX,
                  (void *)((longlong)*(int *)((longlong)unaff_RBX + 0x84) + unaff_RBX[10]),uVar2,
                  uVar5);
    *(int *)((longlong)unaff_RBX + 0x84) = *(int *)((longlong)unaff_RBX + 0x84) + uVar2;
    FUN_18004a2e0(*unaff_RBX);
  }
  return -(uVar5 != 0) & 2;
}

/* ---- FUNC 000484C0 FUN_1800484c0 (1009 bytes) ---- */

char FUN_1800484c0(longlong *param_1,int param_2)

{
  longlong *plVar1;
  short *psVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  byte bVar6;
  void *pvVar7;
  void *pvVar8;
  short sVar9;
  ushort uVar10;
  uint uVar11;
  bool bVar12;
  
  pvVar8 = (void *)0x0;
  do {
    uVar11 = *(uint *)((longlong)param_1 + 0x9c);
    if (uVar11 < 0x106) {
      FUN_18004a0d0(param_1);
      uVar11 = *(uint *)((longlong)param_1 + 0x9c);
      if ((uVar11 < 0x106) && (param_2 == 0)) {
        return '\0';
      }
      if (uVar11 == 0) {
        uVar11 = *(uint *)((longlong)param_1 + 0x94);
        uVar4 = 2;
        if (uVar11 < 2) {
          uVar4 = uVar11;
        }
        *(uint *)((longlong)param_1 + 0x170c) = uVar4;
        if (param_2 == 4) {
          uVar4 = *(uint *)((longlong)param_1 + 0x84);
          if (-1 < (int)uVar4) {
            pvVar8 = (void *)((ulonglong)uVar4 + param_1[10]);
          }
          FUN_18004c580(param_1,pvVar8,uVar11 - uVar4,1);
          *(undefined4 *)((longlong)param_1 + 0x84) = *(undefined4 *)((longlong)param_1 + 0x94);
          FUN_18004a2e0(*param_1);
          return (*(int *)(*param_1 + 0x18) != 0) + '\x02';
        }
        if (*(int *)((longlong)param_1 + 0x16f4) != 0) {
          uVar4 = *(uint *)((longlong)param_1 + 0x84);
          if (-1 < (int)uVar4) {
            pvVar8 = (void *)((ulonglong)uVar4 + param_1[10]);
          }
          FUN_18004c580(param_1,pvVar8,uVar11 - uVar4,0);
          *(undefined4 *)((longlong)param_1 + 0x84) = *(undefined4 *)((longlong)param_1 + 0x94);
          FUN_18004a2e0(*param_1);
          if (*(int *)(*param_1 + 0x18) == 0) {
            return '\0';
          }
        }
        return '\x01';
      }
    }
    if (2 < uVar11) {
      uVar11 = ((uint)*(byte *)((ulonglong)(*(uint *)((longlong)param_1 + 0x94) + 2) + param_1[10])
               ^ (int)param_1[0xe] << ((byte)(int)param_1[0x10] & 0x1f)) &
               *(uint *)((longlong)param_1 + 0x7c);
      *(uint *)(param_1 + 0xe) = uVar11;
      *(undefined2 *)
       (param_1[0xc] +
       (ulonglong)(*(uint *)((longlong)param_1 + 0x94) & *(uint *)((longlong)param_1 + 0x4c)) * 2) =
           *(undefined2 *)(param_1[0xd] + (ulonglong)uVar11 * 2);
      uVar10 = *(ushort *)
                (param_1[0xc] +
                (ulonglong)
                (*(uint *)((longlong)param_1 + 0x94) & *(uint *)((longlong)param_1 + 0x4c)) * 2);
      *(undefined2 *)(param_1[0xd] + (ulonglong)*(uint *)(param_1 + 0xe) * 2) =
           *(undefined2 *)((longlong)param_1 + 0x94);
      if ((uVar10 != 0) &&
         (*(int *)((longlong)param_1 + 0x94) - (uint)uVar10 <=
          *(int *)((longlong)param_1 + 0x44) - 0x106U)) {
        uVar5 = FUN_18004e2d0((longlong)param_1,(uint)uVar10);
        *(int *)(param_1 + 0x11) = (int)uVar5;
      }
    }
    if (*(uint *)(param_1 + 0x11) < 3) {
      bVar6 = *(byte *)((ulonglong)*(uint *)((longlong)param_1 + 0x94) + param_1[10]);
      *(undefined2 *)(param_1[0x2df] + (ulonglong)*(uint *)((longlong)param_1 + 0x16f4) * 2) = 0;
      *(byte *)((ulonglong)*(uint *)((longlong)param_1 + 0x16f4) + param_1[0x2dd]) = bVar6;
      *(int *)((longlong)param_1 + 0x16f4) = *(int *)((longlong)param_1 + 0x16f4) + 1;
      psVar2 = (short *)((longlong)param_1 + (ulonglong)bVar6 * 4 + 0xbc);
      *psVar2 = *psVar2 + 1;
      bVar12 = *(int *)((longlong)param_1 + 0x16f4) == (int)param_1[0x2de] + -1;
      *(int *)((longlong)param_1 + 0x9c) = *(int *)((longlong)param_1 + 0x9c) + -1;
LAB_180048781:
      *(int *)((longlong)param_1 + 0x94) = *(int *)((longlong)param_1 + 0x94) + 1;
    }
    else {
      sVar9 = *(short *)((longlong)param_1 + 0x94) - (short)param_1[0x13];
      lVar3 = param_1[0x11];
      *(short *)(param_1[0x2df] + (ulonglong)*(uint *)((longlong)param_1 + 0x16f4) * 2) = sVar9;
      bVar6 = (char)lVar3 - 3;
      uVar10 = sVar9 - 1;
      *(byte *)((ulonglong)*(uint *)((longlong)param_1 + 0x16f4) + param_1[0x2dd]) = bVar6;
      *(int *)((longlong)param_1 + 0x16f4) = *(int *)((longlong)param_1 + 0x16f4) + 1;
      psVar2 = (short *)((longlong)param_1 + (ulonglong)(byte)(&DAT_18005a770)[bVar6] * 4 + 0x4c0);
      *psVar2 = *psVar2 + 1;
      if (uVar10 < 0x100) {
        uVar5 = (ulonglong)uVar10;
      }
      else {
        uVar5 = (ulonglong)((uVar10 >> 7) + 0x100);
      }
      psVar2 = (short *)((longlong)param_1 + (ulonglong)(byte)(&DAT_18005a870)[uVar5] * 4 + 0x9b0);
      *psVar2 = *psVar2 + 1;
      bVar12 = *(int *)((longlong)param_1 + 0x16f4) == (int)param_1[0x2de] + -1;
      uVar11 = *(uint *)(param_1 + 0x11);
      *(int *)((longlong)param_1 + 0x9c) = *(int *)((longlong)param_1 + 0x9c) - uVar11;
      if ((uVar11 <= *(uint *)(param_1 + 0x15)) && (2 < *(uint *)((longlong)param_1 + 0x9c))) {
        *(uint *)(param_1 + 0x11) = uVar11 - 1;
        do {
          *(int *)((longlong)param_1 + 0x94) = *(int *)((longlong)param_1 + 0x94) + 1;
          uVar11 = ((uint)*(byte *)((ulonglong)(*(uint *)((longlong)param_1 + 0x94) + 2) +
                                   param_1[10]) ^
                   (int)param_1[0xe] << ((byte)(int)param_1[0x10] & 0x1f)) &
                   *(uint *)((longlong)param_1 + 0x7c);
          *(uint *)(param_1 + 0xe) = uVar11;
          *(undefined2 *)
           (param_1[0xc] +
           (ulonglong)(*(uint *)((longlong)param_1 + 0x94) & *(uint *)((longlong)param_1 + 0x4c)) *
           2) = *(undefined2 *)(param_1[0xd] + (ulonglong)uVar11 * 2);
          *(undefined2 *)(param_1[0xd] + (ulonglong)*(uint *)(param_1 + 0xe) * 2) =
               *(undefined2 *)((longlong)param_1 + 0x94);
          plVar1 = param_1 + 0x11;
          *(int *)plVar1 = (int)*plVar1 + -1;
        } while ((int)*plVar1 != 0);
        goto LAB_180048781;
      }
      *(int *)((longlong)param_1 + 0x94) = *(int *)((longlong)param_1 + 0x94) + uVar11;
      *(undefined4 *)(param_1 + 0x11) = 0;
      uVar11 = (uint)*(byte *)((ulonglong)*(uint *)((longlong)param_1 + 0x94) + param_1[10]);
      *(uint *)(param_1 + 0xe) = uVar11;
      *(uint *)(param_1 + 0xe) =
           (uVar11 << ((byte)(int)param_1[0x10] & 0x1f) ^
           (uint)*(byte *)((ulonglong)(*(uint *)((longlong)param_1 + 0x94) + 1) + param_1[10])) &
           *(uint *)((longlong)param_1 + 0x7c);
    }
    if (bVar12) {
      uVar11 = *(uint *)((longlong)param_1 + 0x84);
      pvVar7 = pvVar8;
      if (-1 < (int)uVar11) {
        pvVar7 = (void *)((ulonglong)uVar11 + param_1[10]);
      }
      FUN_18004c580(param_1,pvVar7,*(int *)((longlong)param_1 + 0x94) - uVar11,0);
      *(undefined4 *)((longlong)param_1 + 0x84) = *(undefined4 *)((longlong)param_1 + 0x94);
      FUN_18004a2e0(*param_1);
      if (*(int *)(*param_1 + 0x18) == 0) {
        return '\0';
      }
    }
  } while( true );
}

/* ---- FUNC 000488C0 FUN_1800488c0 (1294 bytes) ---- */

char FUN_1800488c0(longlong *param_1,int param_2)

{
  longlong *plVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  longlong lVar6;
  ulonglong uVar7;
  byte bVar8;
  void *pvVar9;
  void *pvVar10;
  short sVar11;
  ushort uVar12;
  uint uVar13;
  uint uVar14;
  
  pvVar10 = (void *)0x0;
  do {
    uVar13 = *(uint *)((longlong)param_1 + 0x9c);
    uVar14 = 0;
    if (uVar13 < 0x106) {
      FUN_18004a0d0(param_1);
      uVar13 = *(uint *)((longlong)param_1 + 0x9c);
      if ((uVar13 < 0x106) && (param_2 == 0)) {
        return '\0';
      }
      if (uVar13 == 0) {
        if ((int)param_1[0x12] != 0) {
          bVar8 = *(byte *)((ulonglong)(*(int *)((longlong)param_1 + 0x94) - 1) + param_1[10]);
          *(undefined2 *)(param_1[0x2df] + (ulonglong)*(uint *)((longlong)param_1 + 0x16f4) * 2) = 0
          ;
          *(byte *)((ulonglong)*(uint *)((longlong)param_1 + 0x16f4) + param_1[0x2dd]) = bVar8;
          *(int *)((longlong)param_1 + 0x16f4) = *(int *)((longlong)param_1 + 0x16f4) + 1;
          psVar2 = (short *)((longlong)param_1 + (ulonglong)bVar8 * 4 + 0xbc);
          *psVar2 = *psVar2 + 1;
          *(undefined4 *)(param_1 + 0x12) = 0;
        }
        uVar13 = *(uint *)((longlong)param_1 + 0x94);
        uVar14 = 2;
        if (uVar13 < 2) {
          uVar14 = uVar13;
        }
        *(uint *)((longlong)param_1 + 0x170c) = uVar14;
        if (param_2 != 4) {
          if (*(int *)((longlong)param_1 + 0x16f4) != 0) {
            uVar14 = *(uint *)((longlong)param_1 + 0x84);
            if (-1 < (int)uVar14) {
              pvVar10 = (void *)((ulonglong)uVar14 + param_1[10]);
            }
            FUN_18004c580(param_1,pvVar10,uVar13 - uVar14,0);
            *(undefined4 *)((longlong)param_1 + 0x84) = *(undefined4 *)((longlong)param_1 + 0x94);
            FUN_18004a2e0(*param_1);
            if (*(int *)(*param_1 + 0x18) == 0) {
              return '\0';
            }
          }
          return '\x01';
        }
        uVar14 = *(uint *)((longlong)param_1 + 0x84);
        if (-1 < (int)uVar14) {
          pvVar10 = (void *)((ulonglong)uVar14 + param_1[10]);
        }
        FUN_18004c580(param_1,pvVar10,uVar13 - uVar14,1);
        *(undefined4 *)((longlong)param_1 + 0x84) = *(undefined4 *)((longlong)param_1 + 0x94);
        FUN_18004a2e0(*param_1);
        return (*(int *)(*param_1 + 0x18) != 0) + '\x02';
      }
    }
    if (2 < uVar13) {
      uVar13 = ((uint)*(byte *)((ulonglong)(*(uint *)((longlong)param_1 + 0x94) + 2) + param_1[10])
               ^ (int)param_1[0xe] << ((byte)(int)param_1[0x10] & 0x1f)) &
               *(uint *)((longlong)param_1 + 0x7c);
      *(uint *)(param_1 + 0xe) = uVar13;
      *(undefined2 *)
       (param_1[0xc] +
       (ulonglong)(*(uint *)((longlong)param_1 + 0x94) & *(uint *)((longlong)param_1 + 0x4c)) * 2) =
           *(undefined2 *)(param_1[0xd] + (ulonglong)uVar13 * 2);
      uVar14 = (uint)*(ushort *)
                      (param_1[0xc] +
                      (ulonglong)
                      (*(uint *)((longlong)param_1 + 0x94) & *(uint *)((longlong)param_1 + 0x4c)) *
                      2);
      *(undefined2 *)(param_1[0xd] + (ulonglong)*(uint *)(param_1 + 0xe) * 2) =
           *(undefined2 *)((longlong)param_1 + 0x94);
    }
    uVar13 = *(uint *)(param_1 + 0x11);
    *(uint *)(param_1 + 0x14) = uVar13;
    *(int *)((longlong)param_1 + 0x8c) = (int)param_1[0x13];
    *(undefined4 *)(param_1 + 0x11) = 2;
    if (((uVar14 != 0) && (uVar13 < *(uint *)(param_1 + 0x15))) &&
       (*(int *)((longlong)param_1 + 0x94) - uVar14 <= *(int *)((longlong)param_1 + 0x44) - 0x106U))
    {
      uVar7 = FUN_18004e2d0((longlong)param_1,uVar14);
      uVar13 = (uint)uVar7;
      *(uint *)(param_1 + 0x11) = uVar13;
      if ((uVar13 < 6) &&
         (((int)param_1[0x16] == 1 ||
          ((uVar13 == 3 &&
           (0x1000 < (uint)(*(int *)((longlong)param_1 + 0x94) - (int)param_1[0x13]))))))) {
        *(undefined4 *)(param_1 + 0x11) = 2;
      }
    }
    uVar13 = *(uint *)(param_1 + 0x14);
    if ((uVar13 < 3) || (uVar13 < *(uint *)(param_1 + 0x11))) {
      if ((int)param_1[0x12] == 0) {
        *(int *)((longlong)param_1 + 0x94) = *(int *)((longlong)param_1 + 0x94) + 1;
        *(int *)((longlong)param_1 + 0x9c) = *(int *)((longlong)param_1 + 0x9c) + -1;
        *(undefined4 *)(param_1 + 0x12) = 1;
      }
      else {
        bVar8 = *(byte *)((ulonglong)(*(int *)((longlong)param_1 + 0x94) - 1) + param_1[10]);
        *(undefined2 *)(param_1[0x2df] + (ulonglong)*(uint *)((longlong)param_1 + 0x16f4) * 2) = 0;
        *(byte *)((ulonglong)*(uint *)((longlong)param_1 + 0x16f4) + param_1[0x2dd]) = bVar8;
        *(int *)((longlong)param_1 + 0x16f4) = *(int *)((longlong)param_1 + 0x16f4) + 1;
        psVar2 = (short *)((longlong)param_1 + (ulonglong)bVar8 * 4 + 0xbc);
        *psVar2 = *psVar2 + 1;
        if (*(int *)((longlong)param_1 + 0x16f4) == (int)param_1[0x2de] + -1) {
          uVar13 = *(uint *)((longlong)param_1 + 0x84);
          pvVar9 = pvVar10;
          if (-1 < (int)uVar13) {
            pvVar9 = (void *)((ulonglong)uVar13 + param_1[10]);
          }
          FUN_18004c580(param_1,pvVar9,*(int *)((longlong)param_1 + 0x94) - uVar13,0);
          *(undefined4 *)((longlong)param_1 + 0x84) = *(undefined4 *)((longlong)param_1 + 0x94);
          FUN_18004a2e0(*param_1);
        }
        *(int *)((longlong)param_1 + 0x94) = *(int *)((longlong)param_1 + 0x94) + 1;
        *(int *)((longlong)param_1 + 0x9c) = *(int *)((longlong)param_1 + 0x9c) + -1;
        if (*(int *)(*param_1 + 0x18) == 0) {
          return '\0';
        }
      }
    }
    else {
      iVar3 = *(int *)((longlong)param_1 + 0x94);
      iVar4 = *(int *)((longlong)param_1 + 0x9c);
      sVar11 = *(short *)((longlong)param_1 + 0x94) - *(short *)((longlong)param_1 + 0x8c);
      bVar8 = (char)uVar13 - 3;
      *(short *)(param_1[0x2df] + (ulonglong)*(uint *)((longlong)param_1 + 0x16f4) * 2) =
           sVar11 + -1;
      uVar12 = sVar11 - 2;
      *(byte *)((ulonglong)*(uint *)((longlong)param_1 + 0x16f4) + param_1[0x2dd]) = bVar8;
      *(int *)((longlong)param_1 + 0x16f4) = *(int *)((longlong)param_1 + 0x16f4) + 1;
      psVar2 = (short *)((longlong)param_1 + (ulonglong)(byte)(&DAT_18005a770)[bVar8] * 4 + 0x4c0);
      *psVar2 = *psVar2 + 1;
      if (uVar12 < 0x100) {
        uVar7 = (ulonglong)uVar12;
      }
      else {
        uVar7 = (ulonglong)((uVar12 >> 7) + 0x100);
      }
      psVar2 = (short *)((longlong)param_1 + (ulonglong)(byte)(&DAT_18005a870)[uVar7] * 4 + 0x9b0);
      *psVar2 = *psVar2 + 1;
      lVar6 = param_1[0x2de];
      iVar5 = *(int *)((longlong)param_1 + 0x16f4);
      *(int *)((longlong)param_1 + 0x9c) =
           *(int *)((longlong)param_1 + 0x9c) + (1 - (int)param_1[0x14]);
      *(int *)(param_1 + 0x14) = (int)param_1[0x14] + -2;
      do {
        *(int *)((longlong)param_1 + 0x94) = *(int *)((longlong)param_1 + 0x94) + 1;
        uVar13 = *(uint *)((longlong)param_1 + 0x94);
        if (uVar13 <= (uint)(iVar4 + iVar3 + -3)) {
          uVar14 = ((uint)*(byte *)((ulonglong)(uVar13 + 2) + param_1[10]) ^
                   (int)param_1[0xe] << ((byte)(int)param_1[0x10] & 0x1f)) &
                   *(uint *)((longlong)param_1 + 0x7c);
          *(uint *)(param_1 + 0xe) = uVar14;
          *(undefined2 *)
           (param_1[0xc] + (ulonglong)(*(uint *)((longlong)param_1 + 0x4c) & uVar13) * 2) =
               *(undefined2 *)(param_1[0xd] + (ulonglong)uVar14 * 2);
          *(undefined2 *)(param_1[0xd] + (ulonglong)*(uint *)(param_1 + 0xe) * 2) =
               *(undefined2 *)((longlong)param_1 + 0x94);
        }
        plVar1 = param_1 + 0x14;
        *(int *)plVar1 = (int)*plVar1 + -1;
      } while ((int)*plVar1 != 0);
      *(int *)((longlong)param_1 + 0x94) = *(int *)((longlong)param_1 + 0x94) + 1;
      *(undefined4 *)(param_1 + 0x12) = 0;
      *(undefined4 *)(param_1 + 0x11) = 2;
      if (iVar5 == (int)lVar6 + -1) {
        uVar13 = *(uint *)((longlong)param_1 + 0x84);
        pvVar9 = pvVar10;
        if (-1 < (int)uVar13) {
          pvVar9 = (void *)((ulonglong)uVar13 + param_1[10]);
        }
        FUN_18004c580(param_1,pvVar9,*(int *)((longlong)param_1 + 0x94) - uVar13,0);
        *(undefined4 *)((longlong)param_1 + 0x84) = *(undefined4 *)((longlong)param_1 + 0x94);
        FUN_18004a2e0(*param_1);
        if (*(int *)(*param_1 + 0x18) == 0) {
          return '\0';
        }
      }
    }
  } while( true );
}

/* ---- FUNC 00048DD0 FUN_180048dd0 (42 bytes) ---- */

uint FUN_180048dd0(longlong *param_1,uint param_2)

{
  uint uVar1;
  longlong *plVar2;
  int *piVar3;
  longlong lVar4;
  byte bVar5;
  char cVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  undefined7 extraout_var_01;
  ulonglong uVar11;
  longlong *plVar12;
  undefined1 uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  
  uVar10 = FUN_180049b50((longlong)param_1);
  if (((int)uVar10 != 0) || (5 < param_2)) {
    return 0xfffffffe;
  }
  plVar2 = (longlong *)param_1[5];
  if (((param_1[2] == 0) || (((int)param_1[1] != 0 && (*param_1 == 0)))) ||
     (((int)plVar2[1] == 0x29a && (param_2 != 4)))) {
    param_1[4] = (longlong)PTR_s_stream_error_18005b250;
    return 0xfffffffe;
  }
  if ((int)param_1[3] == 0) {
    param_1[4] = (longlong)PTR_s_buffer_error_18005b268;
    return 0xfffffffb;
  }
  lVar4 = plVar2[8];
  iVar15 = 0;
  *(uint *)(plVar2 + 8) = param_2;
  uVar16 = 0;
  if ((int)plVar2[5] == 0) {
    if ((int)param_1[1] == 0) {
      uVar8 = uVar16;
      if (4 < (int)lVar4) {
        uVar8 = 9;
      }
      if (4 < (int)param_2) {
        iVar15 = 9;
      }
      if (((int)(param_2 * 2 - iVar15) <= (int)((int)lVar4 * 2 - uVar8)) && (param_2 != 4))
      goto LAB_180048eca;
    }
  }
  else {
    FUN_18004a2e0((longlong)param_1);
    if ((int)param_1[3] == 0) {
      *(undefined4 *)(plVar2 + 8) = 0xffffffff;
      return 0;
    }
  }
  if (((int)plVar2[1] == 0x29a) && ((int)param_1[1] != 0)) {
LAB_180048eca:
    param_1[4] = (longlong)PTR_s_buffer_error_18005b268;
    return 0xfffffffb;
  }
  if ((int)plVar2[1] == 0x2a) {
    uVar8 = uVar16;
    if (((int)plVar2[0x16] < 2) && (iVar15 = *(int *)((longlong)plVar2 + 0xac), 1 < iVar15)) {
      if (iVar15 < 6) {
        uVar8 = 1;
      }
      else {
        uVar8 = (iVar15 != 6) + 2;
      }
    }
    uVar7 = uVar8 << 6 | (int)plVar2[9] * 0x1000 - 0x7800U;
    uVar8 = uVar7 | 0x20;
    if (*(int *)((longlong)plVar2 + 0x94) == 0) {
      uVar8 = uVar7;
    }
    plVar12 = plVar2;
    FUN_18004a420((longlong)plVar2,(uVar8 / 0x1f + 1) * 0x1f);
    if (*(int *)((longlong)plVar2 + 0x94) != 0) {
      FUN_18004a420((longlong)plVar12,(uint)*(ushort *)((longlong)param_1 + 0x4e));
      FUN_18004a420((longlong)plVar12,(uint)*(ushort *)((longlong)param_1 + 0x4c));
    }
    uVar8 = FUN_18004dfc0(0,(byte *)0x0,0);
    *(uint *)((longlong)param_1 + 0x4c) = uVar8;
    *(undefined4 *)(plVar2 + 1) = 0x71;
    FUN_18004a2e0((longlong)param_1);
    if ((int)plVar2[5] != 0) goto LAB_180049090;
  }
  if ((int)plVar2[1] == 0x39) {
    uVar9 = FUN_18004c120(0,(uint *)0x0,0);
    *(undefined4 *)((longlong)param_1 + 0x4c) = uVar9;
    *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = 0x1f;
    *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
    *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = 0x8b;
    *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
    *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = 8;
    *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
    piVar3 = (int *)plVar2[6];
    uVar13 = 0;
    if (piVar3 == (int *)0x0) {
      *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = 0;
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = 0;
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = 0;
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = 0;
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = 0;
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      if (*(int *)((longlong)plVar2 + 0xac) == 9) {
        uVar13 = 2;
      }
      else if ((1 < (int)plVar2[0x16]) || (*(int *)((longlong)plVar2 + 0xac) < 2)) {
        uVar13 = 4;
      }
      *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = uVar13;
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = 10;
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      *(undefined4 *)(plVar2 + 1) = 0x71;
      FUN_18004a2e0((longlong)param_1);
      if ((int)plVar2[5] != 0) {
LAB_180049090:
        *(undefined4 *)(plVar2 + 8) = 0xffffffff;
        return 0;
      }
    }
    else {
      *(byte *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) =
           (-(*(longlong *)(piVar3 + 0xc) != 0) & 0x10U) + (-(piVar3[0xf] != 0) & 2U) +
           (-(*(longlong *)(piVar3 + 8) != 0) & 8U) + (-(*(longlong *)(piVar3 + 4) != 0) & 4U) +
           (*piVar3 != 0);
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = *(undefined1 *)(plVar2[6] + 4)
      ;
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = *(undefined1 *)(plVar2[6] + 5)
      ;
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = *(undefined1 *)(plVar2[6] + 6)
      ;
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = *(undefined1 *)(plVar2[6] + 7)
      ;
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      if (*(int *)((longlong)plVar2 + 0xac) == 9) {
        uVar13 = 2;
      }
      else if ((1 < (int)plVar2[0x16]) || (*(int *)((longlong)plVar2 + 0xac) < 2)) {
        uVar13 = 4;
      }
      *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = uVar13;
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) =
           *(undefined1 *)(plVar2[6] + 0xc);
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      uVar8 = *(uint *)(plVar2 + 5);
      if (*(longlong *)(plVar2[6] + 0x10) != 0) {
        *(undefined1 *)((ulonglong)uVar8 + plVar2[2]) = *(undefined1 *)(plVar2[6] + 0x18);
        *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
        *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) =
             *(undefined1 *)(plVar2[6] + 0x19);
        *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
        uVar8 = *(uint *)(plVar2 + 5);
      }
      if (*(int *)(plVar2[6] + 0x3c) != 0) {
        uVar9 = FUN_18004c120(*(uint *)((longlong)param_1 + 0x4c),(uint *)plVar2[2],uVar8);
        *(undefined4 *)((longlong)param_1 + 0x4c) = uVar9;
      }
      *(undefined4 *)(plVar2 + 7) = 0;
      *(undefined4 *)(plVar2 + 1) = 0x45;
    }
  }
  if ((int)plVar2[1] == 0x45) {
    if (*(longlong *)(plVar2[6] + 0x10) != 0) {
      uVar7 = (uint)*(ushort *)(plVar2[6] + 0x18) - (int)plVar2[7];
      uVar8 = *(uint *)(plVar2 + 5);
      if (*(uint *)(plVar2 + 3) < uVar8 + uVar7) {
        do {
          uVar14 = (int)plVar2[3] - *(uint *)(plVar2 + 5);
          memcpy((void *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]),
                 (void *)((ulonglong)*(uint *)(plVar2 + 7) + *(longlong *)(plVar2[6] + 0x10)),
                 (ulonglong)uVar14);
          uVar1 = *(uint *)(plVar2 + 3);
          *(uint *)(plVar2 + 5) = uVar1;
          if ((*(int *)(plVar2[6] + 0x3c) != 0) && (uVar8 < uVar1)) {
            uVar9 = FUN_18004c120(*(uint *)((longlong)param_1 + 0x4c),
                                  (uint *)((ulonglong)uVar8 + plVar2[2]),uVar1 - uVar8);
            *(undefined4 *)((longlong)param_1 + 0x4c) = uVar9;
          }
          *(uint *)(plVar2 + 7) = (int)plVar2[7] + uVar14;
          FUN_18004a2e0((longlong)param_1);
          if ((int)plVar2[5] != 0) goto LAB_1800496f2;
          uVar7 = uVar7 - uVar14;
          uVar8 = uVar16;
        } while (*(uint *)(plVar2 + 3) < (int)plVar2[5] + uVar7);
      }
      memcpy((void *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]),
             (void *)((ulonglong)*(uint *)(plVar2 + 7) + *(longlong *)(plVar2[6] + 0x10)),
             (ulonglong)uVar7);
      *(uint *)(plVar2 + 5) = (int)plVar2[5] + uVar7;
      if ((*(int *)(plVar2[6] + 0x3c) != 0) && (uVar8 < *(uint *)(plVar2 + 5))) {
        uVar9 = FUN_18004c120(*(uint *)((longlong)param_1 + 0x4c),
                              (uint *)((ulonglong)uVar8 + plVar2[2]),*(uint *)(plVar2 + 5) - uVar8);
        *(undefined4 *)((longlong)param_1 + 0x4c) = uVar9;
      }
      *(undefined4 *)(plVar2 + 7) = 0;
    }
    *(undefined4 *)(plVar2 + 1) = 0x49;
  }
  if ((int)plVar2[1] == 0x49) {
    if (*(longlong *)(plVar2[6] + 0x20) != 0) {
      uVar11 = (ulonglong)*(uint *)(plVar2 + 5);
      do {
        if ((int)plVar2[5] == (int)plVar2[3]) {
          if (*(int *)(plVar2[6] + 0x3c) != 0) {
            if ((uint)uVar11 < *(uint *)(plVar2 + 5)) {
              uVar9 = FUN_18004c120(*(uint *)((longlong)param_1 + 0x4c),(uint *)(uVar11 + plVar2[2])
                                    ,*(uint *)(plVar2 + 5) - (uint)uVar11);
              *(undefined4 *)((longlong)param_1 + 0x4c) = uVar9;
            }
          }
          FUN_18004a2e0((longlong)param_1);
          uVar11 = 0;
          if ((int)plVar2[5] != 0) goto LAB_1800496f2;
        }
        cVar6 = *(char *)(*(longlong *)(plVar2[6] + 0x20) + (ulonglong)*(uint *)(plVar2 + 7));
        *(uint *)(plVar2 + 7) = *(uint *)(plVar2 + 7) + 1;
        *(char *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = cVar6;
        *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      } while (cVar6 != '\0');
      if ((*(int *)(plVar2[6] + 0x3c) != 0) && ((uint)uVar11 < *(uint *)(plVar2 + 5))) {
        uVar9 = FUN_18004c120(*(uint *)((longlong)param_1 + 0x4c),(uint *)(uVar11 + plVar2[2]),
                              *(uint *)(plVar2 + 5) - (uint)uVar11);
        *(undefined4 *)((longlong)param_1 + 0x4c) = uVar9;
      }
      *(undefined4 *)(plVar2 + 7) = 0;
    }
    *(undefined4 *)(plVar2 + 1) = 0x5b;
  }
  if ((int)plVar2[1] == 0x5b) {
    if (*(longlong *)(plVar2[6] + 0x30) != 0) {
      uVar11 = (ulonglong)*(uint *)(plVar2 + 5);
      do {
        if ((int)plVar2[5] == (int)plVar2[3]) {
          if (*(int *)(plVar2[6] + 0x3c) != 0) {
            if ((uint)uVar11 < *(uint *)(plVar2 + 5)) {
              uVar9 = FUN_18004c120(*(uint *)((longlong)param_1 + 0x4c),(uint *)(uVar11 + plVar2[2])
                                    ,*(uint *)(plVar2 + 5) - (uint)uVar11);
              *(undefined4 *)((longlong)param_1 + 0x4c) = uVar9;
            }
          }
          FUN_18004a2e0((longlong)param_1);
          uVar11 = 0;
          if ((int)plVar2[5] != 0) goto LAB_1800496f2;
        }
        cVar6 = *(char *)(*(longlong *)(plVar2[6] + 0x30) + (ulonglong)*(uint *)(plVar2 + 7));
        *(uint *)(plVar2 + 7) = *(uint *)(plVar2 + 7) + 1;
        *(char *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = cVar6;
        *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      } while (cVar6 != '\0');
      if ((*(int *)(plVar2[6] + 0x3c) != 0) && ((uint)uVar11 < *(uint *)(plVar2 + 5))) {
        uVar9 = FUN_18004c120(*(uint *)((longlong)param_1 + 0x4c),(uint *)(uVar11 + plVar2[2]),
                              *(uint *)(plVar2 + 5) - (uint)uVar11);
        *(undefined4 *)((longlong)param_1 + 0x4c) = uVar9;
      }
    }
    *(undefined4 *)(plVar2 + 1) = 0x67;
  }
  if ((int)plVar2[1] == 0x67) {
    if (*(int *)(plVar2[6] + 0x3c) == 0) {
LAB_1800494c7:
      *(undefined4 *)(plVar2 + 1) = 0x71;
      FUN_18004a2e0((longlong)param_1);
      if ((int)plVar2[5] == 0) goto LAB_1800494df;
    }
    else if (((int)plVar2[5] + 2U <= *(uint *)(plVar2 + 3)) ||
            (FUN_18004a2e0((longlong)param_1), (int)plVar2[5] == 0)) {
      *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) =
           *(undefined1 *)((longlong)param_1 + 0x4c);
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) =
           *(undefined1 *)((longlong)param_1 + 0x4d);
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      uVar9 = FUN_18004c120(0,(uint *)0x0,0);
      *(undefined4 *)((longlong)param_1 + 0x4c) = uVar9;
      goto LAB_1800494c7;
    }
LAB_1800496f2:
    *(undefined4 *)(plVar2 + 8) = 0xffffffff;
  }
  else {
LAB_1800494df:
    if ((((int)param_1[1] != 0) || (*(int *)((longlong)plVar2 + 0x9c) != 0)) ||
       ((param_2 != 0 && ((int)plVar2[1] != 0x29a)))) {
      if (*(int *)((longlong)plVar2 + 0xac) == 0) {
        bVar5 = FUN_1800480b0(plVar2,param_2);
        uVar11 = CONCAT71(extraout_var,bVar5);
      }
      else if ((int)plVar2[0x16] == 2) {
        cVar6 = FUN_180049bb0(plVar2,param_2);
        uVar11 = CONCAT71(extraout_var_00,cVar6);
      }
      else if ((int)plVar2[0x16] == 3) {
        cVar6 = FUN_180049d80(plVar2,param_2);
        uVar11 = CONCAT71(extraout_var_01,cVar6);
      }
      else {
        uVar11 = (*(code *)(&PTR_FUN_180057c18)[(longlong)*(int *)((longlong)plVar2 + 0xac) * 2])
                           (plVar2);
      }
      if ((int)uVar11 - 2U < 2) {
        *(undefined4 *)(plVar2 + 1) = 0x29a;
      }
      if ((uVar11 & 0xfffffffd) == 0) {
        if ((int)param_1[3] != 0) {
          return 0;
        }
        goto LAB_1800496f2;
      }
      if ((int)uVar11 == 1) {
        if (param_2 == 1) {
          FUN_18004c450((longlong)plVar2);
        }
        else if ((param_2 != 5) && (FUN_18004c820((longlong)plVar2,(void *)0x0,0,0), param_2 == 3))
        {
          *(undefined2 *)(plVar2[0xd] + (ulonglong)(*(int *)((longlong)plVar2 + 0x74) - 1) * 2) = 0;
          memset((void *)plVar2[0xd],0,(ulonglong)(*(int *)((longlong)plVar2 + 0x74) - 1) * 2);
          if (*(int *)((longlong)plVar2 + 0x9c) == 0) {
            *(undefined4 *)((longlong)plVar2 + 0x94) = 0;
            *(undefined4 *)((longlong)plVar2 + 0x84) = 0;
            *(undefined4 *)((longlong)plVar2 + 0x170c) = 0;
          }
        }
        FUN_18004a2e0((longlong)param_1);
        if ((int)param_1[3] == 0) goto LAB_1800496f2;
      }
    }
    if (param_2 == 4) {
      if (0 < *(int *)((longlong)plVar2 + 0x2c)) {
        if (*(int *)((longlong)plVar2 + 0x2c) == 2) {
          *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) =
               *(undefined1 *)((longlong)param_1 + 0x4c);
          *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) =
               *(undefined1 *)((longlong)param_1 + 0x4d);
          *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) =
               *(undefined1 *)((longlong)param_1 + 0x4e);
          *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) =
               *(undefined1 *)((longlong)param_1 + 0x4f);
          *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) =
               *(undefined1 *)((longlong)param_1 + 0xc);
          *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) =
               *(undefined1 *)((longlong)param_1 + 0xd);
          *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) =
               *(undefined1 *)((longlong)param_1 + 0xe);
          *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) =
               *(undefined1 *)((longlong)param_1 + 0xf);
          *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
        }
        else {
          plVar12 = plVar2;
          FUN_18004a420((longlong)plVar2,(uint)*(ushort *)((longlong)param_1 + 0x4e));
          FUN_18004a420((longlong)plVar12,(uint)*(ushort *)((longlong)param_1 + 0x4c));
        }
        FUN_18004a2e0((longlong)param_1);
        if (0 < *(int *)((longlong)plVar2 + 0x2c)) {
          *(int *)((longlong)plVar2 + 0x2c) = -*(int *)((longlong)plVar2 + 0x2c);
        }
        return (uint)((int)plVar2[5] == 0);
      }
      return 1;
    }
  }
  return 0;
}

/* ---- FUNC 00048DFA FUN_180048dfa (84 bytes) ---- */

uint FUN_180048dfa(void)

{
  uint uVar1;
  longlong *plVar2;
  int *piVar3;
  longlong lVar4;
  byte bVar5;
  char cVar6;
  int in_EAX;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  undefined7 extraout_var_01;
  ulonglong uVar10;
  longlong *plVar11;
  undefined1 uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  longlong *unaff_RDI;
  uint unaff_R12D;
  bool in_ZF;
  
  plVar2 = (longlong *)unaff_RDI[5];
  if (((in_ZF) || (((int)unaff_RDI[1] != in_EAX && (*unaff_RDI == 0)))) ||
     (((int)plVar2[1] == 0x29a && (unaff_R12D != 4)))) {
    unaff_RDI[4] = (longlong)PTR_s_stream_error_18005b250;
    return 0xfffffffe;
  }
  if ((int)unaff_RDI[3] == 0) {
    unaff_RDI[4] = (longlong)PTR_s_buffer_error_18005b268;
    return 0xfffffffb;
  }
  lVar4 = plVar2[8];
  iVar14 = 0;
  *(uint *)(plVar2 + 8) = unaff_R12D;
  uVar15 = 0;
  if ((int)plVar2[5] == 0) {
    if ((int)unaff_RDI[1] == 0) {
      uVar8 = uVar15;
      if (4 < (int)lVar4) {
        uVar8 = 9;
      }
      if (4 < (int)unaff_R12D) {
        iVar14 = 9;
      }
      if (((int)(unaff_R12D * 2 - iVar14) <= (int)((int)lVar4 * 2 - uVar8)) && (unaff_R12D != 4))
      goto LAB_180048eca;
    }
  }
  else {
    FUN_18004a2e0((longlong)unaff_RDI);
    if ((int)unaff_RDI[3] == 0) {
      *(undefined4 *)(plVar2 + 8) = 0xffffffff;
      return 0;
    }
  }
  if (((int)plVar2[1] == 0x29a) && ((int)unaff_RDI[1] != 0)) {
LAB_180048eca:
    unaff_RDI[4] = (longlong)PTR_s_buffer_error_18005b268;
    return 0xfffffffb;
  }
  if ((int)plVar2[1] == 0x2a) {
    uVar8 = uVar15;
    if (((int)plVar2[0x16] < 2) && (iVar14 = *(int *)((longlong)plVar2 + 0xac), 1 < iVar14)) {
      if (iVar14 < 6) {
        uVar8 = 1;
      }
      else {
        uVar8 = (iVar14 != 6) + 2;
      }
    }
    uVar7 = uVar8 << 6 | (int)plVar2[9] * 0x1000 - 0x7800U;
    uVar8 = uVar7 | 0x20;
    if (*(int *)((longlong)plVar2 + 0x94) == 0) {
      uVar8 = uVar7;
    }
    plVar11 = plVar2;
    FUN_18004a420((longlong)plVar2,(uVar8 / 0x1f + 1) * 0x1f);
    if (*(int *)((longlong)plVar2 + 0x94) != 0) {
      FUN_18004a420((longlong)plVar11,(uint)*(ushort *)((longlong)unaff_RDI + 0x4e));
      FUN_18004a420((longlong)plVar11,(uint)*(ushort *)((longlong)unaff_RDI + 0x4c));
    }
    uVar8 = FUN_18004dfc0(0,(byte *)0x0,0);
    *(uint *)((longlong)unaff_RDI + 0x4c) = uVar8;
    *(undefined4 *)(plVar2 + 1) = 0x71;
    FUN_18004a2e0((longlong)unaff_RDI);
    if ((int)plVar2[5] != 0) goto LAB_180049090;
  }
  if ((int)plVar2[1] == 0x39) {
    uVar9 = FUN_18004c120(0,(uint *)0x0,0);
    *(undefined4 *)((longlong)unaff_RDI + 0x4c) = uVar9;
    *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = 0x1f;
    *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
    *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = 0x8b;
    *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
    *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = 8;
    *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
    piVar3 = (int *)plVar2[6];
    uVar12 = 0;
    if (piVar3 == (int *)0x0) {
      *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = 0;
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = 0;
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = 0;
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = 0;
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = 0;
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      if (*(int *)((longlong)plVar2 + 0xac) == 9) {
        uVar12 = 2;
      }
      else if ((1 < (int)plVar2[0x16]) || (*(int *)((longlong)plVar2 + 0xac) < 2)) {
        uVar12 = 4;
      }
      *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = uVar12;
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = 10;
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      *(undefined4 *)(plVar2 + 1) = 0x71;
      FUN_18004a2e0((longlong)unaff_RDI);
      if ((int)plVar2[5] != 0) {
LAB_180049090:
        *(undefined4 *)(plVar2 + 8) = 0xffffffff;
        return 0;
      }
    }
    else {
      *(byte *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) =
           (-(*(longlong *)(piVar3 + 0xc) != 0) & 0x10U) + (-(piVar3[0xf] != 0) & 2U) +
           (-(*(longlong *)(piVar3 + 8) != 0) & 8U) + (-(*(longlong *)(piVar3 + 4) != 0) & 4U) +
           (*piVar3 != 0);
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = *(undefined1 *)(plVar2[6] + 4)
      ;
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = *(undefined1 *)(plVar2[6] + 5)
      ;
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = *(undefined1 *)(plVar2[6] + 6)
      ;
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = *(undefined1 *)(plVar2[6] + 7)
      ;
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      if (*(int *)((longlong)plVar2 + 0xac) == 9) {
        uVar12 = 2;
      }
      else if ((1 < (int)plVar2[0x16]) || (*(int *)((longlong)plVar2 + 0xac) < 2)) {
        uVar12 = 4;
      }
      *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = uVar12;
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) =
           *(undefined1 *)(plVar2[6] + 0xc);
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      uVar8 = *(uint *)(plVar2 + 5);
      if (*(longlong *)(plVar2[6] + 0x10) != 0) {
        *(undefined1 *)((ulonglong)uVar8 + plVar2[2]) = *(undefined1 *)(plVar2[6] + 0x18);
        *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
        *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) =
             *(undefined1 *)(plVar2[6] + 0x19);
        *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
        uVar8 = *(uint *)(plVar2 + 5);
      }
      if (*(int *)(plVar2[6] + 0x3c) != 0) {
        uVar9 = FUN_18004c120(*(uint *)((longlong)unaff_RDI + 0x4c),(uint *)plVar2[2],uVar8);
        *(undefined4 *)((longlong)unaff_RDI + 0x4c) = uVar9;
      }
      *(undefined4 *)(plVar2 + 7) = 0;
      *(undefined4 *)(plVar2 + 1) = 0x45;
    }
  }
  if ((int)plVar2[1] == 0x45) {
    if (*(longlong *)(plVar2[6] + 0x10) != 0) {
      uVar7 = (uint)*(ushort *)(plVar2[6] + 0x18) - (int)plVar2[7];
      uVar8 = *(uint *)(plVar2 + 5);
      if (*(uint *)(plVar2 + 3) < uVar8 + uVar7) {
        do {
          uVar13 = (int)plVar2[3] - *(uint *)(plVar2 + 5);
          memcpy((void *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]),
                 (void *)((ulonglong)*(uint *)(plVar2 + 7) + *(longlong *)(plVar2[6] + 0x10)),
                 (ulonglong)uVar13);
          uVar1 = *(uint *)(plVar2 + 3);
          *(uint *)(plVar2 + 5) = uVar1;
          if ((*(int *)(plVar2[6] + 0x3c) != 0) && (uVar8 < uVar1)) {
            uVar9 = FUN_18004c120(*(uint *)((longlong)unaff_RDI + 0x4c),
                                  (uint *)((ulonglong)uVar8 + plVar2[2]),uVar1 - uVar8);
            *(undefined4 *)((longlong)unaff_RDI + 0x4c) = uVar9;
          }
          *(uint *)(plVar2 + 7) = (int)plVar2[7] + uVar13;
          FUN_18004a2e0((longlong)unaff_RDI);
          if ((int)plVar2[5] != 0) goto LAB_1800496f2;
          uVar7 = uVar7 - uVar13;
          uVar8 = uVar15;
        } while (*(uint *)(plVar2 + 3) < (int)plVar2[5] + uVar7);
      }
      memcpy((void *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]),
             (void *)((ulonglong)*(uint *)(plVar2 + 7) + *(longlong *)(plVar2[6] + 0x10)),
             (ulonglong)uVar7);
      *(uint *)(plVar2 + 5) = (int)plVar2[5] + uVar7;
      if ((*(int *)(plVar2[6] + 0x3c) != 0) && (uVar8 < *(uint *)(plVar2 + 5))) {
        uVar9 = FUN_18004c120(*(uint *)((longlong)unaff_RDI + 0x4c),
                              (uint *)((ulonglong)uVar8 + plVar2[2]),*(uint *)(plVar2 + 5) - uVar8);
        *(undefined4 *)((longlong)unaff_RDI + 0x4c) = uVar9;
      }
      *(undefined4 *)(plVar2 + 7) = 0;
    }
    *(undefined4 *)(plVar2 + 1) = 0x49;
  }
  if ((int)plVar2[1] == 0x49) {
    if (*(longlong *)(plVar2[6] + 0x20) != 0) {
      uVar10 = (ulonglong)*(uint *)(plVar2 + 5);
      do {
        if ((int)plVar2[5] == (int)plVar2[3]) {
          if (*(int *)(plVar2[6] + 0x3c) != 0) {
            if ((uint)uVar10 < *(uint *)(plVar2 + 5)) {
              uVar9 = FUN_18004c120(*(uint *)((longlong)unaff_RDI + 0x4c),
                                    (uint *)(uVar10 + plVar2[2]),
                                    *(uint *)(plVar2 + 5) - (uint)uVar10);
              *(undefined4 *)((longlong)unaff_RDI + 0x4c) = uVar9;
            }
          }
          FUN_18004a2e0((longlong)unaff_RDI);
          uVar10 = 0;
          if ((int)plVar2[5] != 0) goto LAB_1800496f2;
        }
        cVar6 = *(char *)(*(longlong *)(plVar2[6] + 0x20) + (ulonglong)*(uint *)(plVar2 + 7));
        *(uint *)(plVar2 + 7) = *(uint *)(plVar2 + 7) + 1;
        *(char *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = cVar6;
        *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      } while (cVar6 != '\0');
      if ((*(int *)(plVar2[6] + 0x3c) != 0) && ((uint)uVar10 < *(uint *)(plVar2 + 5))) {
        uVar9 = FUN_18004c120(*(uint *)((longlong)unaff_RDI + 0x4c),(uint *)(uVar10 + plVar2[2]),
                              *(uint *)(plVar2 + 5) - (uint)uVar10);
        *(undefined4 *)((longlong)unaff_RDI + 0x4c) = uVar9;
      }
      *(undefined4 *)(plVar2 + 7) = 0;
    }
    *(undefined4 *)(plVar2 + 1) = 0x5b;
  }
  if ((int)plVar2[1] == 0x5b) {
    if (*(longlong *)(plVar2[6] + 0x30) != 0) {
      uVar10 = (ulonglong)*(uint *)(plVar2 + 5);
      do {
        if ((int)plVar2[5] == (int)plVar2[3]) {
          if (*(int *)(plVar2[6] + 0x3c) != 0) {
            if ((uint)uVar10 < *(uint *)(plVar2 + 5)) {
              uVar9 = FUN_18004c120(*(uint *)((longlong)unaff_RDI + 0x4c),
                                    (uint *)(uVar10 + plVar2[2]),
                                    *(uint *)(plVar2 + 5) - (uint)uVar10);
              *(undefined4 *)((longlong)unaff_RDI + 0x4c) = uVar9;
            }
          }
          FUN_18004a2e0((longlong)unaff_RDI);
          uVar10 = 0;
          if ((int)plVar2[5] != 0) goto LAB_1800496f2;
        }
        cVar6 = *(char *)(*(longlong *)(plVar2[6] + 0x30) + (ulonglong)*(uint *)(plVar2 + 7));
        *(uint *)(plVar2 + 7) = *(uint *)(plVar2 + 7) + 1;
        *(char *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) = cVar6;
        *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      } while (cVar6 != '\0');
      if ((*(int *)(plVar2[6] + 0x3c) != 0) && ((uint)uVar10 < *(uint *)(plVar2 + 5))) {
        uVar9 = FUN_18004c120(*(uint *)((longlong)unaff_RDI + 0x4c),(uint *)(uVar10 + plVar2[2]),
                              *(uint *)(plVar2 + 5) - (uint)uVar10);
        *(undefined4 *)((longlong)unaff_RDI + 0x4c) = uVar9;
      }
    }
    *(undefined4 *)(plVar2 + 1) = 0x67;
  }
  if ((int)plVar2[1] == 0x67) {
    if (*(int *)(plVar2[6] + 0x3c) == 0) {
LAB_1800494c7:
      *(undefined4 *)(plVar2 + 1) = 0x71;
      FUN_18004a2e0((longlong)unaff_RDI);
      if ((int)plVar2[5] == 0) goto LAB_1800494df;
    }
    else if (((int)plVar2[5] + 2U <= *(uint *)(plVar2 + 3)) ||
            (FUN_18004a2e0((longlong)unaff_RDI), (int)plVar2[5] == 0)) {
      *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) =
           *(undefined1 *)((longlong)unaff_RDI + 0x4c);
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) =
           *(undefined1 *)((longlong)unaff_RDI + 0x4d);
      *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
      uVar9 = FUN_18004c120(0,(uint *)0x0,0);
      *(undefined4 *)((longlong)unaff_RDI + 0x4c) = uVar9;
      goto LAB_1800494c7;
    }
LAB_1800496f2:
    *(undefined4 *)(plVar2 + 8) = 0xffffffff;
  }
  else {
LAB_1800494df:
    if ((((int)unaff_RDI[1] != 0) || (*(int *)((longlong)plVar2 + 0x9c) != 0)) ||
       ((unaff_R12D != 0 && ((int)plVar2[1] != 0x29a)))) {
      if (*(int *)((longlong)plVar2 + 0xac) == 0) {
        bVar5 = FUN_1800480b0(plVar2,unaff_R12D);
        uVar10 = CONCAT71(extraout_var,bVar5);
      }
      else if ((int)plVar2[0x16] == 2) {
        cVar6 = FUN_180049bb0(plVar2,unaff_R12D);
        uVar10 = CONCAT71(extraout_var_00,cVar6);
      }
      else if ((int)plVar2[0x16] == 3) {
        cVar6 = FUN_180049d80(plVar2,unaff_R12D);
        uVar10 = CONCAT71(extraout_var_01,cVar6);
      }
      else {
        uVar10 = (*(code *)(&PTR_FUN_180057c18)[(longlong)*(int *)((longlong)plVar2 + 0xac) * 2])
                           (plVar2);
      }
      if ((int)uVar10 - 2U < 2) {
        *(undefined4 *)(plVar2 + 1) = 0x29a;
      }
      if ((uVar10 & 0xfffffffd) == 0) {
        if ((int)unaff_RDI[3] != 0) {
          return 0;
        }
        goto LAB_1800496f2;
      }
      if ((int)uVar10 == 1) {
        if (unaff_R12D == 1) {
          FUN_18004c450((longlong)plVar2);
        }
        else if ((unaff_R12D != 5) &&
                (FUN_18004c820((longlong)plVar2,(void *)0x0,0,0), unaff_R12D == 3)) {
          *(undefined2 *)(plVar2[0xd] + (ulonglong)(*(int *)((longlong)plVar2 + 0x74) - 1) * 2) = 0;
          memset((void *)plVar2[0xd],0,(ulonglong)(*(int *)((longlong)plVar2 + 0x74) - 1) * 2);
          if (*(int *)((longlong)plVar2 + 0x9c) == 0) {
            *(undefined4 *)((longlong)plVar2 + 0x94) = 0;
            *(undefined4 *)((longlong)plVar2 + 0x84) = 0;
            *(undefined4 *)((longlong)plVar2 + 0x170c) = 0;
          }
        }
        FUN_18004a2e0((longlong)unaff_RDI);
        if ((int)unaff_RDI[3] == 0) goto LAB_1800496f2;
      }
    }
    if (unaff_R12D == 4) {
      if (0 < *(int *)((longlong)plVar2 + 0x2c)) {
        if (*(int *)((longlong)plVar2 + 0x2c) == 2) {
          *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) =
               *(undefined1 *)((longlong)unaff_RDI + 0x4c);
          *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) =
               *(undefined1 *)((longlong)unaff_RDI + 0x4d);
          *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) =
               *(undefined1 *)((longlong)unaff_RDI + 0x4e);
          *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) =
               *(undefined1 *)((longlong)unaff_RDI + 0x4f);
          *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) =
               *(undefined1 *)((longlong)unaff_RDI + 0xc);
          *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) =
               *(undefined1 *)((longlong)unaff_RDI + 0xd);
          *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) =
               *(undefined1 *)((longlong)unaff_RDI + 0xe);
          *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(plVar2 + 5) + plVar2[2]) =
               *(undefined1 *)((longlong)unaff_RDI + 0xf);
          *(int *)(plVar2 + 5) = (int)plVar2[5] + 1;
        }
        else {
          plVar11 = plVar2;
          FUN_18004a420((longlong)plVar2,(uint)*(ushort *)((longlong)unaff_RDI + 0x4e));
          FUN_18004a420((longlong)plVar11,(uint)*(ushort *)((longlong)unaff_RDI + 0x4c));
        }
        FUN_18004a2e0((longlong)unaff_RDI);
        if (0 < *(int *)((longlong)plVar2 + 0x2c)) {
          *(int *)((longlong)plVar2 + 0x2c) = -*(int *)((longlong)plVar2 + 0x2c);
        }
        return (uint)((int)plVar2[5] == 0);
      }
      return 1;
    }
  }
  return 0;
}

/* ---- FUNC 00048E4E FUN_180048e4e (59 bytes) ---- */

uint FUN_180048e4e(void)

{
  uint uVar1;
  int *piVar2;
  longlong lVar3;
  byte bVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  undefined7 extraout_var_01;
  ulonglong uVar9;
  longlong *plVar10;
  undefined1 uVar11;
  longlong *unaff_RBX;
  uint uVar12;
  int iVar13;
  uint uVar14;
  longlong unaff_RDI;
  uint unaff_R12D;
  
  lVar3 = unaff_RBX[8];
  iVar13 = 0;
  *(uint *)(unaff_RBX + 8) = unaff_R12D;
  uVar14 = 0;
  if ((int)unaff_RBX[5] == 0) {
    if (*(int *)(unaff_RDI + 8) == 0) {
      uVar7 = uVar14;
      if (4 < (int)lVar3) {
        uVar7 = 9;
      }
      if (4 < (int)unaff_R12D) {
        iVar13 = 9;
      }
      if (((int)(unaff_R12D * 2 - iVar13) <= (int)((int)lVar3 * 2 - uVar7)) && (unaff_R12D != 4))
      goto LAB_180048eca;
    }
  }
  else {
    FUN_18004a2e0(unaff_RDI);
    if (*(int *)(unaff_RDI + 0x18) == 0) {
      *(undefined4 *)(unaff_RBX + 8) = 0xffffffff;
      return 0;
    }
  }
  if (((int)unaff_RBX[1] == 0x29a) && (*(int *)(unaff_RDI + 8) != 0)) {
LAB_180048eca:
    *(undefined **)(unaff_RDI + 0x20) = PTR_s_buffer_error_18005b268;
    return 0xfffffffb;
  }
  if ((int)unaff_RBX[1] == 0x2a) {
    uVar7 = uVar14;
    if (((int)unaff_RBX[0x16] < 2) && (iVar13 = *(int *)((longlong)unaff_RBX + 0xac), 1 < iVar13)) {
      if (iVar13 < 6) {
        uVar7 = 1;
      }
      else {
        uVar7 = (iVar13 != 6) + 2;
      }
    }
    uVar6 = uVar7 << 6 | (int)unaff_RBX[9] * 0x1000 - 0x7800U;
    uVar7 = uVar6 | 0x20;
    if (*(int *)((longlong)unaff_RBX + 0x94) == 0) {
      uVar7 = uVar6;
    }
    plVar10 = unaff_RBX;
    FUN_18004a420((longlong)unaff_RBX,(uVar7 / 0x1f + 1) * 0x1f);
    if (*(int *)((longlong)unaff_RBX + 0x94) != 0) {
      FUN_18004a420((longlong)plVar10,(uint)*(ushort *)(unaff_RDI + 0x4e));
      FUN_18004a420((longlong)plVar10,(uint)*(ushort *)(unaff_RDI + 0x4c));
    }
    uVar7 = FUN_18004dfc0(0,(byte *)0x0,0);
    *(uint *)(unaff_RDI + 0x4c) = uVar7;
    *(undefined4 *)(unaff_RBX + 1) = 0x71;
    FUN_18004a2e0(unaff_RDI);
    if ((int)unaff_RBX[5] != 0) goto LAB_180049090;
  }
  if ((int)unaff_RBX[1] == 0x39) {
    uVar8 = FUN_18004c120(0,(uint *)0x0,0);
    *(undefined4 *)(unaff_RDI + 0x4c) = uVar8;
    *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = 0x1f;
    *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
    *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = 0x8b;
    *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
    *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = 8;
    *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
    piVar2 = (int *)unaff_RBX[6];
    uVar11 = 0;
    if (piVar2 == (int *)0x0) {
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = 0;
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = 0;
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = 0;
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = 0;
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = 0;
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      if (*(int *)((longlong)unaff_RBX + 0xac) == 9) {
        uVar11 = 2;
      }
      else if ((1 < (int)unaff_RBX[0x16]) || (*(int *)((longlong)unaff_RBX + 0xac) < 2)) {
        uVar11 = 4;
      }
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = uVar11;
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = 10;
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined4 *)(unaff_RBX + 1) = 0x71;
      FUN_18004a2e0(unaff_RDI);
      if ((int)unaff_RBX[5] != 0) {
LAB_180049090:
        *(undefined4 *)(unaff_RBX + 8) = 0xffffffff;
        return 0;
      }
    }
    else {
      *(byte *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
           (-(*(longlong *)(piVar2 + 0xc) != 0) & 0x10U) + (-(piVar2[0xf] != 0) & 2U) +
           (-(*(longlong *)(piVar2 + 8) != 0) & 8U) + (-(*(longlong *)(piVar2 + 4) != 0) & 4U) +
           (*piVar2 != 0);
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
           *(undefined1 *)(unaff_RBX[6] + 4);
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
           *(undefined1 *)(unaff_RBX[6] + 5);
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
           *(undefined1 *)(unaff_RBX[6] + 6);
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
           *(undefined1 *)(unaff_RBX[6] + 7);
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      if (*(int *)((longlong)unaff_RBX + 0xac) == 9) {
        uVar11 = 2;
      }
      else if ((1 < (int)unaff_RBX[0x16]) || (*(int *)((longlong)unaff_RBX + 0xac) < 2)) {
        uVar11 = 4;
      }
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = uVar11;
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
           *(undefined1 *)(unaff_RBX[6] + 0xc);
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      uVar7 = *(uint *)(unaff_RBX + 5);
      if (*(longlong *)(unaff_RBX[6] + 0x10) != 0) {
        *(undefined1 *)((ulonglong)uVar7 + unaff_RBX[2]) = *(undefined1 *)(unaff_RBX[6] + 0x18);
        *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
        *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
             *(undefined1 *)(unaff_RBX[6] + 0x19);
        *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
        uVar7 = *(uint *)(unaff_RBX + 5);
      }
      if (*(int *)(unaff_RBX[6] + 0x3c) != 0) {
        uVar8 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),(uint *)unaff_RBX[2],uVar7);
        *(undefined4 *)(unaff_RDI + 0x4c) = uVar8;
      }
      *(undefined4 *)(unaff_RBX + 7) = 0;
      *(undefined4 *)(unaff_RBX + 1) = 0x45;
    }
  }
  if ((int)unaff_RBX[1] == 0x45) {
    if (*(longlong *)(unaff_RBX[6] + 0x10) != 0) {
      uVar6 = (uint)*(ushort *)(unaff_RBX[6] + 0x18) - (int)unaff_RBX[7];
      uVar7 = *(uint *)(unaff_RBX + 5);
      if (*(uint *)(unaff_RBX + 3) < uVar7 + uVar6) {
        do {
          uVar12 = (int)unaff_RBX[3] - *(uint *)(unaff_RBX + 5);
          memcpy((void *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]),
                 (void *)((ulonglong)*(uint *)(unaff_RBX + 7) + *(longlong *)(unaff_RBX[6] + 0x10)),
                 (ulonglong)uVar12);
          uVar1 = *(uint *)(unaff_RBX + 3);
          *(uint *)(unaff_RBX + 5) = uVar1;
          if ((*(int *)(unaff_RBX[6] + 0x3c) != 0) && (uVar7 < uVar1)) {
            uVar8 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),
                                  (uint *)((ulonglong)uVar7 + unaff_RBX[2]),uVar1 - uVar7);
            *(undefined4 *)(unaff_RDI + 0x4c) = uVar8;
          }
          *(uint *)(unaff_RBX + 7) = (int)unaff_RBX[7] + uVar12;
          FUN_18004a2e0(unaff_RDI);
          if ((int)unaff_RBX[5] != 0) goto LAB_1800496f2;
          uVar6 = uVar6 - uVar12;
          uVar7 = uVar14;
        } while (*(uint *)(unaff_RBX + 3) < (int)unaff_RBX[5] + uVar6);
      }
      memcpy((void *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]),
             (void *)((ulonglong)*(uint *)(unaff_RBX + 7) + *(longlong *)(unaff_RBX[6] + 0x10)),
             (ulonglong)uVar6);
      *(uint *)(unaff_RBX + 5) = (int)unaff_RBX[5] + uVar6;
      if ((*(int *)(unaff_RBX[6] + 0x3c) != 0) && (uVar7 < *(uint *)(unaff_RBX + 5))) {
        uVar8 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),(uint *)((ulonglong)uVar7 + unaff_RBX[2]),
                              *(uint *)(unaff_RBX + 5) - uVar7);
        *(undefined4 *)(unaff_RDI + 0x4c) = uVar8;
      }
      *(undefined4 *)(unaff_RBX + 7) = 0;
    }
    *(undefined4 *)(unaff_RBX + 1) = 0x49;
  }
  if ((int)unaff_RBX[1] == 0x49) {
    if (*(longlong *)(unaff_RBX[6] + 0x20) != 0) {
      uVar9 = (ulonglong)*(uint *)(unaff_RBX + 5);
      do {
        if ((int)unaff_RBX[5] == (int)unaff_RBX[3]) {
          if (*(int *)(unaff_RBX[6] + 0x3c) != 0) {
            if ((uint)uVar9 < *(uint *)(unaff_RBX + 5)) {
              uVar8 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),(uint *)(uVar9 + unaff_RBX[2]),
                                    *(uint *)(unaff_RBX + 5) - (uint)uVar9);
              *(undefined4 *)(unaff_RDI + 0x4c) = uVar8;
            }
          }
          FUN_18004a2e0(unaff_RDI);
          uVar9 = 0;
          if ((int)unaff_RBX[5] != 0) goto LAB_1800496f2;
        }
        cVar5 = *(char *)(*(longlong *)(unaff_RBX[6] + 0x20) + (ulonglong)*(uint *)(unaff_RBX + 7));
        *(uint *)(unaff_RBX + 7) = *(uint *)(unaff_RBX + 7) + 1;
        *(char *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = cVar5;
        *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      } while (cVar5 != '\0');
      if ((*(int *)(unaff_RBX[6] + 0x3c) != 0) && ((uint)uVar9 < *(uint *)(unaff_RBX + 5))) {
        uVar8 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),(uint *)(uVar9 + unaff_RBX[2]),
                              *(uint *)(unaff_RBX + 5) - (uint)uVar9);
        *(undefined4 *)(unaff_RDI + 0x4c) = uVar8;
      }
      *(undefined4 *)(unaff_RBX + 7) = 0;
    }
    *(undefined4 *)(unaff_RBX + 1) = 0x5b;
  }
  if ((int)unaff_RBX[1] == 0x5b) {
    if (*(longlong *)(unaff_RBX[6] + 0x30) != 0) {
      uVar9 = (ulonglong)*(uint *)(unaff_RBX + 5);
      do {
        if ((int)unaff_RBX[5] == (int)unaff_RBX[3]) {
          if (*(int *)(unaff_RBX[6] + 0x3c) != 0) {
            if ((uint)uVar9 < *(uint *)(unaff_RBX + 5)) {
              uVar8 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),(uint *)(uVar9 + unaff_RBX[2]),
                                    *(uint *)(unaff_RBX + 5) - (uint)uVar9);
              *(undefined4 *)(unaff_RDI + 0x4c) = uVar8;
            }
          }
          FUN_18004a2e0(unaff_RDI);
          uVar9 = 0;
          if ((int)unaff_RBX[5] != 0) goto LAB_1800496f2;
        }
        cVar5 = *(char *)(*(longlong *)(unaff_RBX[6] + 0x30) + (ulonglong)*(uint *)(unaff_RBX + 7));
        *(uint *)(unaff_RBX + 7) = *(uint *)(unaff_RBX + 7) + 1;
        *(char *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = cVar5;
        *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      } while (cVar5 != '\0');
      if ((*(int *)(unaff_RBX[6] + 0x3c) != 0) && ((uint)uVar9 < *(uint *)(unaff_RBX + 5))) {
        uVar8 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),(uint *)(uVar9 + unaff_RBX[2]),
                              *(uint *)(unaff_RBX + 5) - (uint)uVar9);
        *(undefined4 *)(unaff_RDI + 0x4c) = uVar8;
      }
    }
    *(undefined4 *)(unaff_RBX + 1) = 0x67;
  }
  if ((int)unaff_RBX[1] == 0x67) {
    if (*(int *)(unaff_RBX[6] + 0x3c) == 0) {
LAB_1800494c7:
      *(undefined4 *)(unaff_RBX + 1) = 0x71;
      FUN_18004a2e0(unaff_RDI);
      if ((int)unaff_RBX[5] == 0) goto LAB_1800494df;
    }
    else if (((int)unaff_RBX[5] + 2U <= *(uint *)(unaff_RBX + 3)) ||
            (FUN_18004a2e0(unaff_RDI), (int)unaff_RBX[5] == 0)) {
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
           *(undefined1 *)(unaff_RDI + 0x4c);
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
           *(undefined1 *)(unaff_RDI + 0x4d);
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      uVar8 = FUN_18004c120(0,(uint *)0x0,0);
      *(undefined4 *)(unaff_RDI + 0x4c) = uVar8;
      goto LAB_1800494c7;
    }
LAB_1800496f2:
    *(undefined4 *)(unaff_RBX + 8) = 0xffffffff;
  }
  else {
LAB_1800494df:
    if (((*(int *)(unaff_RDI + 8) != 0) || (*(int *)((longlong)unaff_RBX + 0x9c) != 0)) ||
       ((unaff_R12D != 0 && ((int)unaff_RBX[1] != 0x29a)))) {
      if (*(int *)((longlong)unaff_RBX + 0xac) == 0) {
        bVar4 = FUN_1800480b0(unaff_RBX,unaff_R12D);
        uVar9 = CONCAT71(extraout_var,bVar4);
      }
      else if ((int)unaff_RBX[0x16] == 2) {
        cVar5 = FUN_180049bb0(unaff_RBX,unaff_R12D);
        uVar9 = CONCAT71(extraout_var_00,cVar5);
      }
      else if ((int)unaff_RBX[0x16] == 3) {
        cVar5 = FUN_180049d80(unaff_RBX,unaff_R12D);
        uVar9 = CONCAT71(extraout_var_01,cVar5);
      }
      else {
        uVar9 = (*(code *)(&PTR_FUN_180057c18)[(longlong)*(int *)((longlong)unaff_RBX + 0xac) * 2])
                          ();
      }
      if ((int)uVar9 - 2U < 2) {
        *(undefined4 *)(unaff_RBX + 1) = 0x29a;
      }
      if ((uVar9 & 0xfffffffd) == 0) {
        if (*(int *)(unaff_RDI + 0x18) != 0) {
          return 0;
        }
        goto LAB_1800496f2;
      }
      if ((int)uVar9 == 1) {
        if (unaff_R12D == 1) {
          FUN_18004c450((longlong)unaff_RBX);
        }
        else if ((unaff_R12D != 5) &&
                (FUN_18004c820((longlong)unaff_RBX,(void *)0x0,0,0), unaff_R12D == 3)) {
          *(undefined2 *)
           (unaff_RBX[0xd] + (ulonglong)(*(int *)((longlong)unaff_RBX + 0x74) - 1) * 2) = 0;
          memset((void *)unaff_RBX[0xd],0,(ulonglong)(*(int *)((longlong)unaff_RBX + 0x74) - 1) * 2)
          ;
          if (*(int *)((longlong)unaff_RBX + 0x9c) == 0) {
            *(undefined4 *)((longlong)unaff_RBX + 0x94) = 0;
            *(undefined4 *)((longlong)unaff_RBX + 0x84) = 0;
            *(undefined4 *)((longlong)unaff_RBX + 0x170c) = 0;
          }
        }
        FUN_18004a2e0(unaff_RDI);
        if (*(int *)(unaff_RDI + 0x18) == 0) goto LAB_1800496f2;
      }
    }
    if (unaff_R12D == 4) {
      if (0 < *(int *)((longlong)unaff_RBX + 0x2c)) {
        if (*(int *)((longlong)unaff_RBX + 0x2c) == 2) {
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0x4c);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0x4d);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0x4e);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0x4f);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0xc);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0xd);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0xe);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0xf);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
        }
        else {
          plVar10 = unaff_RBX;
          FUN_18004a420((longlong)unaff_RBX,(uint)*(ushort *)(unaff_RDI + 0x4e));
          FUN_18004a420((longlong)plVar10,(uint)*(ushort *)(unaff_RDI + 0x4c));
        }
        FUN_18004a2e0(unaff_RDI);
        if (0 < *(int *)((longlong)unaff_RBX + 0x2c)) {
          *(int *)((longlong)unaff_RBX + 0x2c) = -*(int *)((longlong)unaff_RBX + 0x2c);
        }
        return (uint)((int)unaff_RBX[5] == 0);
      }
      return 1;
    }
  }
  return 0;
}

/* ---- FUNC 00048E89 FUN_180048e89 (99 bytes) ---- */

ulonglong FUN_180048e89(undefined8 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  byte bVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  undefined7 extraout_var_01;
  ulonglong uVar9;
  longlong *plVar10;
  undefined1 uVar11;
  longlong *unaff_RBX;
  uint uVar12;
  uint uVar13;
  ulonglong unaff_RSI;
  undefined7 uVar14;
  longlong unaff_RDI;
  uint unaff_R12D;
  
  uVar13 = (uint)unaff_RSI;
  if (*(uint *)(unaff_RDI + 8) == uVar13) {
    uVar7 = uVar13;
    if (4 < param_2) {
      uVar7 = 9;
    }
    uVar6 = uVar13;
    if (4 < (int)unaff_R12D) {
      uVar6 = 9;
    }
    if (((int)(unaff_R12D * 2 - uVar6) <= (int)(param_2 * 2 - uVar7)) && (unaff_R12D != 4))
    goto LAB_180048eca;
  }
  if (((int)unaff_RBX[1] == 0x29a) && (*(uint *)(unaff_RDI + 8) != uVar13)) {
LAB_180048eca:
    *(undefined **)(unaff_RDI + 0x20) = PTR_s_buffer_error_18005b268;
    return 0xfffffffb;
  }
  uVar14 = (undefined7)(unaff_RSI >> 8);
  if ((int)unaff_RBX[1] == 0x2a) {
    uVar7 = uVar13;
    if (((int)unaff_RBX[0x16] < 2) && (iVar1 = *(int *)((longlong)unaff_RBX + 0xac), 1 < iVar1)) {
      if (iVar1 < 6) {
        uVar7 = 1;
      }
      else {
        uVar7 = (int)CONCAT71(uVar14,iVar1 != 6) + 2;
      }
    }
    uVar6 = uVar7 << 6 | (int)unaff_RBX[9] * 0x1000 - 0x7800U;
    uVar7 = uVar6 | 0x20;
    if (*(uint *)((longlong)unaff_RBX + 0x94) == uVar13) {
      uVar7 = uVar6;
    }
    plVar10 = unaff_RBX;
    FUN_18004a420((longlong)unaff_RBX,(uVar7 / 0x1f + 1) * 0x1f);
    if (*(uint *)((longlong)unaff_RBX + 0x94) != uVar13) {
      FUN_18004a420((longlong)plVar10,(uint)*(ushort *)(unaff_RDI + 0x4e));
      FUN_18004a420((longlong)plVar10,(uint)*(ushort *)(unaff_RDI + 0x4c));
    }
    uVar7 = FUN_18004dfc0(0,(byte *)0x0,0);
    *(uint *)(unaff_RDI + 0x4c) = uVar7;
    *(undefined4 *)(unaff_RBX + 1) = 0x71;
    FUN_18004a2e0(unaff_RDI);
    if (*(uint *)(unaff_RBX + 5) != uVar13) goto LAB_180049090;
  }
  if ((int)unaff_RBX[1] == 0x39) {
    uVar8 = FUN_18004c120(0,(uint *)0x0,0);
    *(undefined4 *)(unaff_RDI + 0x4c) = uVar8;
    *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = 0x1f;
    *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
    *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = 0x8b;
    *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
    *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = 8;
    *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
    puVar3 = (uint *)unaff_RBX[6];
    uVar11 = (undefined1)unaff_RSI;
    if (puVar3 == (uint *)0x0) {
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = uVar11;
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = uVar11;
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = uVar11;
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = uVar11;
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = uVar11;
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      if (*(int *)((longlong)unaff_RBX + 0xac) == 9) {
        uVar11 = 2;
      }
      else if ((1 < (int)unaff_RBX[0x16]) || (*(int *)((longlong)unaff_RBX + 0xac) < 2)) {
        uVar11 = 4;
      }
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = uVar11;
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = 10;
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined4 *)(unaff_RBX + 1) = 0x71;
      FUN_18004a2e0(unaff_RDI);
      if (*(uint *)(unaff_RBX + 5) != uVar13) {
LAB_180049090:
        *(undefined4 *)(unaff_RBX + 8) = 0xffffffff;
        return 0;
      }
    }
    else {
      *(byte *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
           (-(*(longlong *)(puVar3 + 0xc) != 0) & 0x10U) + (-(puVar3[0xf] != 0) & 2U) +
           (-(*(longlong *)(puVar3 + 8) != 0) & 8U) + (-(*(longlong *)(puVar3 + 4) != 0) & 4U) +
           (*puVar3 != uVar13);
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
           *(undefined1 *)(unaff_RBX[6] + 4);
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
           *(undefined1 *)(unaff_RBX[6] + 5);
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
           *(undefined1 *)(unaff_RBX[6] + 6);
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
           *(undefined1 *)(unaff_RBX[6] + 7);
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      if (*(int *)((longlong)unaff_RBX + 0xac) == 9) {
        uVar11 = 2;
      }
      else if ((1 < (int)unaff_RBX[0x16]) || (*(int *)((longlong)unaff_RBX + 0xac) < 2)) {
        uVar11 = 4;
      }
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = uVar11;
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
           *(undefined1 *)(unaff_RBX[6] + 0xc);
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      uVar7 = *(uint *)(unaff_RBX + 5);
      if (*(ulonglong *)(unaff_RBX[6] + 0x10) != unaff_RSI) {
        *(undefined1 *)((ulonglong)uVar7 + unaff_RBX[2]) = *(undefined1 *)(unaff_RBX[6] + 0x18);
        *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
        *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
             *(undefined1 *)(unaff_RBX[6] + 0x19);
        *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
        uVar7 = *(uint *)(unaff_RBX + 5);
      }
      if (*(uint *)(unaff_RBX[6] + 0x3c) != uVar13) {
        uVar8 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),(uint *)unaff_RBX[2],uVar7);
        *(undefined4 *)(unaff_RDI + 0x4c) = uVar8;
      }
      *(uint *)(unaff_RBX + 7) = uVar13;
      *(undefined4 *)(unaff_RBX + 1) = 0x45;
    }
  }
  if ((int)unaff_RBX[1] == 0x45) {
    if (*(ulonglong *)(unaff_RBX[6] + 0x10) != unaff_RSI) {
      uVar6 = (uint)*(ushort *)(unaff_RBX[6] + 0x18) - (int)unaff_RBX[7];
      uVar7 = *(uint *)(unaff_RBX + 5);
      if (*(uint *)(unaff_RBX + 3) < uVar7 + uVar6) {
        do {
          uVar12 = (int)unaff_RBX[3] - *(uint *)(unaff_RBX + 5);
          memcpy((void *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]),
                 (void *)((ulonglong)*(uint *)(unaff_RBX + 7) + *(longlong *)(unaff_RBX[6] + 0x10)),
                 (ulonglong)uVar12);
          uVar2 = *(uint *)(unaff_RBX + 3);
          *(uint *)(unaff_RBX + 5) = uVar2;
          if ((*(uint *)(unaff_RBX[6] + 0x3c) != uVar13) && (uVar7 < uVar2)) {
            uVar8 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),
                                  (uint *)((ulonglong)uVar7 + unaff_RBX[2]),uVar2 - uVar7);
            *(undefined4 *)(unaff_RDI + 0x4c) = uVar8;
          }
          *(uint *)(unaff_RBX + 7) = (int)unaff_RBX[7] + uVar12;
          FUN_18004a2e0(unaff_RDI);
          if (*(uint *)(unaff_RBX + 5) != uVar13) goto LAB_1800496f2;
          uVar6 = uVar6 - uVar12;
          uVar7 = uVar13;
        } while (*(uint *)(unaff_RBX + 3) < (int)unaff_RBX[5] + uVar6);
      }
      memcpy((void *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]),
             (void *)((ulonglong)*(uint *)(unaff_RBX + 7) + *(longlong *)(unaff_RBX[6] + 0x10)),
             (ulonglong)uVar6);
      *(uint *)(unaff_RBX + 5) = (int)unaff_RBX[5] + uVar6;
      if ((*(uint *)(unaff_RBX[6] + 0x3c) != uVar13) && (uVar7 < *(uint *)(unaff_RBX + 5))) {
        uVar8 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),(uint *)((ulonglong)uVar7 + unaff_RBX[2]),
                              *(uint *)(unaff_RBX + 5) - uVar7);
        *(undefined4 *)(unaff_RDI + 0x4c) = uVar8;
      }
      *(uint *)(unaff_RBX + 7) = uVar13;
    }
    *(undefined4 *)(unaff_RBX + 1) = 0x49;
  }
  if ((int)unaff_RBX[1] == 0x49) {
    if (*(ulonglong *)(unaff_RBX[6] + 0x20) != unaff_RSI) {
      uVar9 = (ulonglong)*(uint *)(unaff_RBX + 5);
      do {
        if ((int)unaff_RBX[5] == (int)unaff_RBX[3]) {
          if (*(uint *)(unaff_RBX[6] + 0x3c) != uVar13) {
            if ((uint)uVar9 < *(uint *)(unaff_RBX + 5)) {
              uVar8 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),(uint *)(uVar9 + unaff_RBX[2]),
                                    *(uint *)(unaff_RBX + 5) - (uint)uVar9);
              *(undefined4 *)(unaff_RDI + 0x4c) = uVar8;
            }
          }
          FUN_18004a2e0(unaff_RDI);
          if (*(uint *)(unaff_RBX + 5) != uVar13) goto LAB_1800496f2;
          uVar9 = unaff_RSI & 0xffffffff;
        }
        cVar5 = *(char *)(*(longlong *)(unaff_RBX[6] + 0x20) + (ulonglong)*(uint *)(unaff_RBX + 7));
        *(uint *)(unaff_RBX + 7) = *(uint *)(unaff_RBX + 7) + 1;
        *(char *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = cVar5;
        *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      } while (cVar5 != '\0');
      if ((*(uint *)(unaff_RBX[6] + 0x3c) != uVar13) && ((uint)uVar9 < *(uint *)(unaff_RBX + 5))) {
        uVar8 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),(uint *)(uVar9 + unaff_RBX[2]),
                              *(uint *)(unaff_RBX + 5) - (uint)uVar9);
        *(undefined4 *)(unaff_RDI + 0x4c) = uVar8;
      }
      *(uint *)(unaff_RBX + 7) = uVar13;
    }
    *(undefined4 *)(unaff_RBX + 1) = 0x5b;
  }
  if ((int)unaff_RBX[1] == 0x5b) {
    if (*(ulonglong *)(unaff_RBX[6] + 0x30) != unaff_RSI) {
      uVar9 = (ulonglong)*(uint *)(unaff_RBX + 5);
      do {
        if ((int)unaff_RBX[5] == (int)unaff_RBX[3]) {
          if (*(uint *)(unaff_RBX[6] + 0x3c) != uVar13) {
            if ((uint)uVar9 < *(uint *)(unaff_RBX + 5)) {
              uVar8 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),(uint *)(uVar9 + unaff_RBX[2]),
                                    *(uint *)(unaff_RBX + 5) - (uint)uVar9);
              *(undefined4 *)(unaff_RDI + 0x4c) = uVar8;
            }
          }
          FUN_18004a2e0(unaff_RDI);
          if (*(uint *)(unaff_RBX + 5) != uVar13) goto LAB_1800496f2;
          uVar9 = unaff_RSI & 0xffffffff;
        }
        cVar5 = *(char *)(*(longlong *)(unaff_RBX[6] + 0x30) + (ulonglong)*(uint *)(unaff_RBX + 7));
        *(uint *)(unaff_RBX + 7) = *(uint *)(unaff_RBX + 7) + 1;
        *(char *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = cVar5;
        *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      } while (cVar5 != '\0');
      if ((*(uint *)(unaff_RBX[6] + 0x3c) != uVar13) && ((uint)uVar9 < *(uint *)(unaff_RBX + 5))) {
        uVar8 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),(uint *)(uVar9 + unaff_RBX[2]),
                              *(uint *)(unaff_RBX + 5) - (uint)uVar9);
        *(undefined4 *)(unaff_RDI + 0x4c) = uVar8;
      }
    }
    *(undefined4 *)(unaff_RBX + 1) = 0x67;
  }
  if ((int)unaff_RBX[1] == 0x67) {
    if (*(uint *)(unaff_RBX[6] + 0x3c) == uVar13) {
LAB_1800494c7:
      *(undefined4 *)(unaff_RBX + 1) = 0x71;
      FUN_18004a2e0(unaff_RDI);
      if (*(uint *)(unaff_RBX + 5) == uVar13) goto LAB_1800494df;
    }
    else if (((int)unaff_RBX[5] + 2U <= *(uint *)(unaff_RBX + 3)) ||
            (FUN_18004a2e0(unaff_RDI), *(uint *)(unaff_RBX + 5) == uVar13)) {
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
           *(undefined1 *)(unaff_RDI + 0x4c);
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
           *(undefined1 *)(unaff_RDI + 0x4d);
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      uVar8 = FUN_18004c120(0,(uint *)0x0,0);
      *(undefined4 *)(unaff_RDI + 0x4c) = uVar8;
      goto LAB_1800494c7;
    }
LAB_1800496f2:
    *(undefined4 *)(unaff_RBX + 8) = 0xffffffff;
  }
  else {
LAB_1800494df:
    if (((*(uint *)(unaff_RDI + 8) != uVar13) || (*(uint *)((longlong)unaff_RBX + 0x9c) != uVar13))
       || ((unaff_R12D != 0 && ((int)unaff_RBX[1] != 0x29a)))) {
      if (*(int *)((longlong)unaff_RBX + 0xac) == 0) {
        bVar4 = FUN_1800480b0(unaff_RBX,unaff_R12D);
        uVar9 = CONCAT71(extraout_var,bVar4);
      }
      else if ((int)unaff_RBX[0x16] == 2) {
        cVar5 = FUN_180049bb0(unaff_RBX,unaff_R12D);
        uVar9 = CONCAT71(extraout_var_00,cVar5);
      }
      else if ((int)unaff_RBX[0x16] == 3) {
        cVar5 = FUN_180049d80(unaff_RBX,unaff_R12D);
        uVar9 = CONCAT71(extraout_var_01,cVar5);
      }
      else {
        uVar9 = (*(code *)(&PTR_FUN_180057c18)[(longlong)*(int *)((longlong)unaff_RBX + 0xac) * 2])
                          ();
      }
      if ((int)uVar9 - 2U < 2) {
        *(undefined4 *)(unaff_RBX + 1) = 0x29a;
      }
      if ((uVar9 & 0xfffffffd) == 0) {
        if (*(uint *)(unaff_RDI + 0x18) != uVar13) {
          return 0;
        }
        goto LAB_1800496f2;
      }
      if ((int)uVar9 == 1) {
        if (unaff_R12D == 1) {
          FUN_18004c450((longlong)unaff_RBX);
        }
        else if ((unaff_R12D != 5) &&
                (FUN_18004c820((longlong)unaff_RBX,(void *)0x0,0,0), unaff_R12D == 3)) {
          *(short *)(unaff_RBX[0xd] + (ulonglong)(*(int *)((longlong)unaff_RBX + 0x74) - 1) * 2) =
               (short)unaff_RSI;
          memset((void *)unaff_RBX[0xd],0,(ulonglong)(*(int *)((longlong)unaff_RBX + 0x74) - 1) * 2)
          ;
          if (*(uint *)((longlong)unaff_RBX + 0x9c) == uVar13) {
            *(uint *)((longlong)unaff_RBX + 0x94) = uVar13;
            *(uint *)((longlong)unaff_RBX + 0x84) = uVar13;
            *(uint *)((longlong)unaff_RBX + 0x170c) = uVar13;
          }
        }
        FUN_18004a2e0(unaff_RDI);
        if (*(uint *)(unaff_RDI + 0x18) == uVar13) goto LAB_1800496f2;
      }
    }
    if (unaff_R12D == 4) {
      if (0 < *(int *)((longlong)unaff_RBX + 0x2c)) {
        if (*(int *)((longlong)unaff_RBX + 0x2c) == 2) {
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0x4c);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0x4d);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0x4e);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0x4f);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0xc);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0xd);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0xe);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0xf);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
        }
        else {
          plVar10 = unaff_RBX;
          FUN_18004a420((longlong)unaff_RBX,(uint)*(ushort *)(unaff_RDI + 0x4e));
          FUN_18004a420((longlong)plVar10,(uint)*(ushort *)(unaff_RDI + 0x4c));
        }
        FUN_18004a2e0(unaff_RDI);
        if (0 < *(int *)((longlong)unaff_RBX + 0x2c)) {
          *(int *)((longlong)unaff_RBX + 0x2c) = -*(int *)((longlong)unaff_RBX + 0x2c);
        }
        return CONCAT71(uVar14,*(uint *)(unaff_RBX + 5) == uVar13) & 0xffffffff;
      }
      return 1;
    }
  }
  return 0;
}

/* ---- FUNC 00048EEC FUN_180048eec (447 bytes) ---- */

ulonglong FUN_180048eec(void)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  byte bVar4;
  char cVar5;
  int in_EAX;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  undefined7 extraout_var_01;
  ulonglong uVar9;
  longlong *plVar10;
  undefined1 uVar11;
  longlong *unaff_RBX;
  uint uVar12;
  uint uVar13;
  ulonglong unaff_RSI;
  longlong unaff_RDI;
  uint unaff_R12D;
  undefined7 uVar14;
  
  uVar13 = (uint)unaff_RSI;
  uVar14 = (undefined7)(unaff_RSI >> 8);
  if (in_EAX == 0x2a) {
    uVar7 = uVar13;
    if (((int)unaff_RBX[0x16] < 2) && (iVar1 = *(int *)((longlong)unaff_RBX + 0xac), 1 < iVar1)) {
      if (iVar1 < 6) {
        uVar7 = 1;
      }
      else {
        uVar7 = (int)CONCAT71(uVar14,iVar1 != 6) + 2;
      }
    }
    uVar6 = uVar7 << 6 | (int)unaff_RBX[9] * 0x1000 - 0x7800U;
    uVar7 = uVar6 | 0x20;
    if (*(uint *)((longlong)unaff_RBX + 0x94) == uVar13) {
      uVar7 = uVar6;
    }
    plVar10 = unaff_RBX;
    FUN_18004a420((longlong)unaff_RBX,(uVar7 / 0x1f + 1) * 0x1f);
    if (*(uint *)((longlong)unaff_RBX + 0x94) != uVar13) {
      FUN_18004a420((longlong)plVar10,(uint)*(ushort *)(unaff_RDI + 0x4e));
      FUN_18004a420((longlong)plVar10,(uint)*(ushort *)(unaff_RDI + 0x4c));
    }
    uVar7 = FUN_18004dfc0(0,(byte *)0x0,0);
    *(uint *)(unaff_RDI + 0x4c) = uVar7;
    *(undefined4 *)(unaff_RBX + 1) = 0x71;
    FUN_18004a2e0(unaff_RDI);
    if (*(uint *)(unaff_RBX + 5) != uVar13) goto LAB_180049090;
  }
  if ((int)unaff_RBX[1] == 0x39) {
    uVar8 = FUN_18004c120(0,(uint *)0x0,0);
    *(undefined4 *)(unaff_RDI + 0x4c) = uVar8;
    *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = 0x1f;
    *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
    *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = 0x8b;
    *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
    *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = 8;
    *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
    puVar3 = (uint *)unaff_RBX[6];
    uVar11 = (undefined1)unaff_RSI;
    if (puVar3 == (uint *)0x0) {
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = uVar11;
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = uVar11;
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = uVar11;
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = uVar11;
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = uVar11;
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      if (*(int *)((longlong)unaff_RBX + 0xac) == 9) {
        uVar11 = 2;
      }
      else if ((1 < (int)unaff_RBX[0x16]) || (*(int *)((longlong)unaff_RBX + 0xac) < 2)) {
        uVar11 = 4;
      }
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = uVar11;
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = 10;
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined4 *)(unaff_RBX + 1) = 0x71;
      FUN_18004a2e0(unaff_RDI);
      if (*(uint *)(unaff_RBX + 5) != uVar13) {
LAB_180049090:
        *(undefined4 *)(unaff_RBX + 8) = 0xffffffff;
        return 0;
      }
    }
    else {
      *(byte *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
           (-(*(longlong *)(puVar3 + 0xc) != 0) & 0x10U) + (-(puVar3[0xf] != 0) & 2U) +
           (-(*(longlong *)(puVar3 + 8) != 0) & 8U) + (-(*(longlong *)(puVar3 + 4) != 0) & 4U) +
           (*puVar3 != uVar13);
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
           *(undefined1 *)(unaff_RBX[6] + 4);
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
           *(undefined1 *)(unaff_RBX[6] + 5);
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
           *(undefined1 *)(unaff_RBX[6] + 6);
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
           *(undefined1 *)(unaff_RBX[6] + 7);
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      if (*(int *)((longlong)unaff_RBX + 0xac) == 9) {
        uVar11 = 2;
      }
      else if ((1 < (int)unaff_RBX[0x16]) || (*(int *)((longlong)unaff_RBX + 0xac) < 2)) {
        uVar11 = 4;
      }
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = uVar11;
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
           *(undefined1 *)(unaff_RBX[6] + 0xc);
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      uVar7 = *(uint *)(unaff_RBX + 5);
      if (*(ulonglong *)(unaff_RBX[6] + 0x10) != unaff_RSI) {
        *(undefined1 *)((ulonglong)uVar7 + unaff_RBX[2]) = *(undefined1 *)(unaff_RBX[6] + 0x18);
        *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
        *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
             *(undefined1 *)(unaff_RBX[6] + 0x19);
        *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
        uVar7 = *(uint *)(unaff_RBX + 5);
      }
      if (*(uint *)(unaff_RBX[6] + 0x3c) != uVar13) {
        uVar8 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),(uint *)unaff_RBX[2],uVar7);
        *(undefined4 *)(unaff_RDI + 0x4c) = uVar8;
      }
      *(uint *)(unaff_RBX + 7) = uVar13;
      *(undefined4 *)(unaff_RBX + 1) = 0x45;
    }
  }
  if ((int)unaff_RBX[1] == 0x45) {
    if (*(ulonglong *)(unaff_RBX[6] + 0x10) != unaff_RSI) {
      uVar6 = (uint)*(ushort *)(unaff_RBX[6] + 0x18) - (int)unaff_RBX[7];
      uVar7 = *(uint *)(unaff_RBX + 5);
      if (*(uint *)(unaff_RBX + 3) < uVar7 + uVar6) {
        do {
          uVar12 = (int)unaff_RBX[3] - *(uint *)(unaff_RBX + 5);
          memcpy((void *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]),
                 (void *)((ulonglong)*(uint *)(unaff_RBX + 7) + *(longlong *)(unaff_RBX[6] + 0x10)),
                 (ulonglong)uVar12);
          uVar2 = *(uint *)(unaff_RBX + 3);
          *(uint *)(unaff_RBX + 5) = uVar2;
          if ((*(uint *)(unaff_RBX[6] + 0x3c) != uVar13) && (uVar7 < uVar2)) {
            uVar8 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),
                                  (uint *)((ulonglong)uVar7 + unaff_RBX[2]),uVar2 - uVar7);
            *(undefined4 *)(unaff_RDI + 0x4c) = uVar8;
          }
          *(uint *)(unaff_RBX + 7) = (int)unaff_RBX[7] + uVar12;
          FUN_18004a2e0(unaff_RDI);
          if (*(uint *)(unaff_RBX + 5) != uVar13) goto LAB_1800496f2;
          uVar6 = uVar6 - uVar12;
          uVar7 = uVar13;
        } while (*(uint *)(unaff_RBX + 3) < (int)unaff_RBX[5] + uVar6);
      }
      memcpy((void *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]),
             (void *)((ulonglong)*(uint *)(unaff_RBX + 7) + *(longlong *)(unaff_RBX[6] + 0x10)),
             (ulonglong)uVar6);
      *(uint *)(unaff_RBX + 5) = (int)unaff_RBX[5] + uVar6;
      if ((*(uint *)(unaff_RBX[6] + 0x3c) != uVar13) && (uVar7 < *(uint *)(unaff_RBX + 5))) {
        uVar8 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),(uint *)((ulonglong)uVar7 + unaff_RBX[2]),
                              *(uint *)(unaff_RBX + 5) - uVar7);
        *(undefined4 *)(unaff_RDI + 0x4c) = uVar8;
      }
      *(uint *)(unaff_RBX + 7) = uVar13;
    }
    *(undefined4 *)(unaff_RBX + 1) = 0x49;
  }
  if ((int)unaff_RBX[1] == 0x49) {
    if (*(ulonglong *)(unaff_RBX[6] + 0x20) != unaff_RSI) {
      uVar9 = (ulonglong)*(uint *)(unaff_RBX + 5);
      do {
        if ((int)unaff_RBX[5] == (int)unaff_RBX[3]) {
          if (*(uint *)(unaff_RBX[6] + 0x3c) != uVar13) {
            if ((uint)uVar9 < *(uint *)(unaff_RBX + 5)) {
              uVar8 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),(uint *)(uVar9 + unaff_RBX[2]),
                                    *(uint *)(unaff_RBX + 5) - (uint)uVar9);
              *(undefined4 *)(unaff_RDI + 0x4c) = uVar8;
            }
          }
          FUN_18004a2e0(unaff_RDI);
          if (*(uint *)(unaff_RBX + 5) != uVar13) goto LAB_1800496f2;
          uVar9 = unaff_RSI & 0xffffffff;
        }
        cVar5 = *(char *)(*(longlong *)(unaff_RBX[6] + 0x20) + (ulonglong)*(uint *)(unaff_RBX + 7));
        *(uint *)(unaff_RBX + 7) = *(uint *)(unaff_RBX + 7) + 1;
        *(char *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = cVar5;
        *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      } while (cVar5 != '\0');
      if ((*(uint *)(unaff_RBX[6] + 0x3c) != uVar13) && ((uint)uVar9 < *(uint *)(unaff_RBX + 5))) {
        uVar8 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),(uint *)(uVar9 + unaff_RBX[2]),
                              *(uint *)(unaff_RBX + 5) - (uint)uVar9);
        *(undefined4 *)(unaff_RDI + 0x4c) = uVar8;
      }
      *(uint *)(unaff_RBX + 7) = uVar13;
    }
    *(undefined4 *)(unaff_RBX + 1) = 0x5b;
  }
  if ((int)unaff_RBX[1] == 0x5b) {
    if (*(ulonglong *)(unaff_RBX[6] + 0x30) != unaff_RSI) {
      uVar9 = (ulonglong)*(uint *)(unaff_RBX + 5);
      do {
        if ((int)unaff_RBX[5] == (int)unaff_RBX[3]) {
          if (*(uint *)(unaff_RBX[6] + 0x3c) != uVar13) {
            if ((uint)uVar9 < *(uint *)(unaff_RBX + 5)) {
              uVar8 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),(uint *)(uVar9 + unaff_RBX[2]),
                                    *(uint *)(unaff_RBX + 5) - (uint)uVar9);
              *(undefined4 *)(unaff_RDI + 0x4c) = uVar8;
            }
          }
          FUN_18004a2e0(unaff_RDI);
          if (*(uint *)(unaff_RBX + 5) != uVar13) goto LAB_1800496f2;
          uVar9 = unaff_RSI & 0xffffffff;
        }
        cVar5 = *(char *)(*(longlong *)(unaff_RBX[6] + 0x30) + (ulonglong)*(uint *)(unaff_RBX + 7));
        *(uint *)(unaff_RBX + 7) = *(uint *)(unaff_RBX + 7) + 1;
        *(char *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = cVar5;
        *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      } while (cVar5 != '\0');
      if ((*(uint *)(unaff_RBX[6] + 0x3c) != uVar13) && ((uint)uVar9 < *(uint *)(unaff_RBX + 5))) {
        uVar8 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),(uint *)(uVar9 + unaff_RBX[2]),
                              *(uint *)(unaff_RBX + 5) - (uint)uVar9);
        *(undefined4 *)(unaff_RDI + 0x4c) = uVar8;
      }
    }
    *(undefined4 *)(unaff_RBX + 1) = 0x67;
  }
  if ((int)unaff_RBX[1] == 0x67) {
    if (*(uint *)(unaff_RBX[6] + 0x3c) == uVar13) {
LAB_1800494c7:
      *(undefined4 *)(unaff_RBX + 1) = 0x71;
      FUN_18004a2e0(unaff_RDI);
      if (*(uint *)(unaff_RBX + 5) == uVar13) goto LAB_1800494df;
    }
    else if (((int)unaff_RBX[5] + 2U <= *(uint *)(unaff_RBX + 3)) ||
            (FUN_18004a2e0(unaff_RDI), *(uint *)(unaff_RBX + 5) == uVar13)) {
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
           *(undefined1 *)(unaff_RDI + 0x4c);
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
           *(undefined1 *)(unaff_RDI + 0x4d);
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      uVar8 = FUN_18004c120(0,(uint *)0x0,0);
      *(undefined4 *)(unaff_RDI + 0x4c) = uVar8;
      goto LAB_1800494c7;
    }
LAB_1800496f2:
    *(undefined4 *)(unaff_RBX + 8) = 0xffffffff;
  }
  else {
LAB_1800494df:
    if (((*(uint *)(unaff_RDI + 8) != uVar13) || (*(uint *)((longlong)unaff_RBX + 0x9c) != uVar13))
       || ((unaff_R12D != 0 && ((int)unaff_RBX[1] != 0x29a)))) {
      if (*(int *)((longlong)unaff_RBX + 0xac) == 0) {
        bVar4 = FUN_1800480b0(unaff_RBX,unaff_R12D);
        uVar9 = CONCAT71(extraout_var,bVar4);
      }
      else if ((int)unaff_RBX[0x16] == 2) {
        cVar5 = FUN_180049bb0(unaff_RBX,unaff_R12D);
        uVar9 = CONCAT71(extraout_var_00,cVar5);
      }
      else if ((int)unaff_RBX[0x16] == 3) {
        cVar5 = FUN_180049d80(unaff_RBX,unaff_R12D);
        uVar9 = CONCAT71(extraout_var_01,cVar5);
      }
      else {
        uVar9 = (*(code *)(&PTR_FUN_180057c18)[(longlong)*(int *)((longlong)unaff_RBX + 0xac) * 2])
                          ();
      }
      if ((int)uVar9 - 2U < 2) {
        *(undefined4 *)(unaff_RBX + 1) = 0x29a;
      }
      if ((uVar9 & 0xfffffffd) == 0) {
        if (*(uint *)(unaff_RDI + 0x18) != uVar13) {
          return 0;
        }
        goto LAB_1800496f2;
      }
      if ((int)uVar9 == 1) {
        if (unaff_R12D == 1) {
          FUN_18004c450((longlong)unaff_RBX);
        }
        else if ((unaff_R12D != 5) &&
                (FUN_18004c820((longlong)unaff_RBX,(void *)0x0,0,0), unaff_R12D == 3)) {
          *(short *)(unaff_RBX[0xd] + (ulonglong)(*(int *)((longlong)unaff_RBX + 0x74) - 1) * 2) =
               (short)unaff_RSI;
          memset((void *)unaff_RBX[0xd],0,(ulonglong)(*(int *)((longlong)unaff_RBX + 0x74) - 1) * 2)
          ;
          if (*(uint *)((longlong)unaff_RBX + 0x9c) == uVar13) {
            *(uint *)((longlong)unaff_RBX + 0x94) = uVar13;
            *(uint *)((longlong)unaff_RBX + 0x84) = uVar13;
            *(uint *)((longlong)unaff_RBX + 0x170c) = uVar13;
          }
        }
        FUN_18004a2e0(unaff_RDI);
        if (*(uint *)(unaff_RDI + 0x18) == uVar13) goto LAB_1800496f2;
      }
    }
    if (unaff_R12D == 4) {
      if (0 < *(int *)((longlong)unaff_RBX + 0x2c)) {
        if (*(int *)((longlong)unaff_RBX + 0x2c) == 2) {
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0x4c);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0x4d);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0x4e);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0x4f);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0xc);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0xd);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0xe);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0xf);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
        }
        else {
          plVar10 = unaff_RBX;
          FUN_18004a420((longlong)unaff_RBX,(uint)*(ushort *)(unaff_RDI + 0x4e));
          FUN_18004a420((longlong)plVar10,(uint)*(ushort *)(unaff_RDI + 0x4c));
        }
        FUN_18004a2e0(unaff_RDI);
        if (0 < *(int *)((longlong)unaff_RBX + 0x2c)) {
          *(int *)((longlong)unaff_RBX + 0x2c) = -*(int *)((longlong)unaff_RBX + 0x2c);
        }
        return CONCAT71(uVar14,*(uint *)(unaff_RBX + 5) == uVar13) & 0xffffffff;
      }
      return 1;
    }
  }
  return 0;
}

/* ---- FUNC 000490AB FUN_1800490ab (319 bytes) ---- */

ulonglong FUN_1800490ab(undefined8 param_1,undefined8 param_2,uint *param_3,longlong param_4)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  undefined4 uVar4;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  undefined7 extraout_var_01;
  ulonglong uVar5;
  longlong *plVar6;
  undefined1 uVar7;
  longlong *unaff_RBX;
  uint uVar8;
  uint uVar9;
  ulonglong unaff_RSI;
  longlong unaff_RDI;
  uint unaff_R12D;
  uint uVar10;
  uint uVar11;
  
  uVar9 = (uint)unaff_RSI;
  *(byte *)(param_4 + unaff_RBX[2]) =
       (-(*(longlong *)(param_3 + 0xc) != 0) & 0x10U) + (-(param_3[0xf] != 0) & 2U) +
       (-(*(longlong *)(param_3 + 8) != 0) & 8U) + (-(*(longlong *)(param_3 + 4) != 0) & 4U) +
       (*param_3 != uVar9);
  *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
  *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
       *(undefined1 *)(unaff_RBX[6] + 4);
  *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
  *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
       *(undefined1 *)(unaff_RBX[6] + 5);
  *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
  *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
       *(undefined1 *)(unaff_RBX[6] + 6);
  *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
  *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
       *(undefined1 *)(unaff_RBX[6] + 7);
  *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
  if (*(int *)((longlong)unaff_RBX + 0xac) == 9) {
    uVar7 = 2;
  }
  else if ((1 < (int)unaff_RBX[0x16]) ||
          (uVar7 = (undefined1)unaff_RSI, *(int *)((longlong)unaff_RBX + 0xac) < 2)) {
    uVar7 = 4;
  }
  *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = uVar7;
  *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
  *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
       *(undefined1 *)(unaff_RBX[6] + 0xc);
  *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
  uVar10 = *(uint *)(unaff_RBX + 5);
  if (*(ulonglong *)(unaff_RBX[6] + 0x10) != unaff_RSI) {
    *(undefined1 *)((ulonglong)uVar10 + unaff_RBX[2]) = *(undefined1 *)(unaff_RBX[6] + 0x18);
    *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
    *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
         *(undefined1 *)(unaff_RBX[6] + 0x19);
    *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
    uVar10 = *(uint *)(unaff_RBX + 5);
  }
  if (*(uint *)(unaff_RBX[6] + 0x3c) != uVar9) {
    uVar4 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),(uint *)unaff_RBX[2],uVar10);
    *(undefined4 *)(unaff_RDI + 0x4c) = uVar4;
  }
  *(uint *)(unaff_RBX + 7) = uVar9;
  *(undefined4 *)(unaff_RBX + 1) = 0x45;
  if ((int)unaff_RBX[1] == 0x45) {
    if (*(ulonglong *)(unaff_RBX[6] + 0x10) != unaff_RSI) {
      uVar11 = (uint)*(ushort *)(unaff_RBX[6] + 0x18) - (int)unaff_RBX[7];
      uVar10 = *(uint *)(unaff_RBX + 5);
      if (*(uint *)(unaff_RBX + 3) < uVar10 + uVar11) {
        do {
          uVar8 = (int)unaff_RBX[3] - *(uint *)(unaff_RBX + 5);
          memcpy((void *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]),
                 (void *)((ulonglong)*(uint *)(unaff_RBX + 7) + *(longlong *)(unaff_RBX[6] + 0x10)),
                 (ulonglong)uVar8);
          uVar1 = *(uint *)(unaff_RBX + 3);
          *(uint *)(unaff_RBX + 5) = uVar1;
          if ((*(uint *)(unaff_RBX[6] + 0x3c) != uVar9) && (uVar10 < uVar1)) {
            uVar4 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),
                                  (uint *)((ulonglong)uVar10 + unaff_RBX[2]),uVar1 - uVar10);
            *(undefined4 *)(unaff_RDI + 0x4c) = uVar4;
          }
          *(uint *)(unaff_RBX + 7) = (int)unaff_RBX[7] + uVar8;
          FUN_18004a2e0(unaff_RDI);
          if (*(uint *)(unaff_RBX + 5) != uVar9) goto LAB_1800496f2;
          uVar11 = uVar11 - uVar8;
          uVar10 = uVar9;
        } while (*(uint *)(unaff_RBX + 3) < (int)unaff_RBX[5] + uVar11);
      }
      memcpy((void *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]),
             (void *)((ulonglong)*(uint *)(unaff_RBX + 7) + *(longlong *)(unaff_RBX[6] + 0x10)),
             (ulonglong)uVar11);
      *(uint *)(unaff_RBX + 5) = (int)unaff_RBX[5] + uVar11;
      if ((*(uint *)(unaff_RBX[6] + 0x3c) != uVar9) && (uVar10 < *(uint *)(unaff_RBX + 5))) {
        uVar4 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),(uint *)((ulonglong)uVar10 + unaff_RBX[2])
                              ,*(uint *)(unaff_RBX + 5) - uVar10);
        *(undefined4 *)(unaff_RDI + 0x4c) = uVar4;
      }
      *(uint *)(unaff_RBX + 7) = uVar9;
    }
    *(undefined4 *)(unaff_RBX + 1) = 0x49;
  }
  if ((int)unaff_RBX[1] == 0x49) {
    if (*(ulonglong *)(unaff_RBX[6] + 0x20) != unaff_RSI) {
      uVar5 = (ulonglong)*(uint *)(unaff_RBX + 5);
      do {
        if ((int)unaff_RBX[5] == (int)unaff_RBX[3]) {
          if (*(uint *)(unaff_RBX[6] + 0x3c) != uVar9) {
            if ((uint)uVar5 < *(uint *)(unaff_RBX + 5)) {
              uVar4 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),(uint *)(uVar5 + unaff_RBX[2]),
                                    *(uint *)(unaff_RBX + 5) - (uint)uVar5);
              *(undefined4 *)(unaff_RDI + 0x4c) = uVar4;
            }
          }
          FUN_18004a2e0(unaff_RDI);
          if (*(uint *)(unaff_RBX + 5) != uVar9) goto LAB_1800496f2;
          uVar5 = unaff_RSI & 0xffffffff;
        }
        cVar3 = *(char *)(*(longlong *)(unaff_RBX[6] + 0x20) + (ulonglong)*(uint *)(unaff_RBX + 7));
        *(uint *)(unaff_RBX + 7) = *(uint *)(unaff_RBX + 7) + 1;
        *(char *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = cVar3;
        *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      } while (cVar3 != '\0');
      if ((*(uint *)(unaff_RBX[6] + 0x3c) != uVar9) && ((uint)uVar5 < *(uint *)(unaff_RBX + 5))) {
        uVar4 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),(uint *)(uVar5 + unaff_RBX[2]),
                              *(uint *)(unaff_RBX + 5) - (uint)uVar5);
        *(undefined4 *)(unaff_RDI + 0x4c) = uVar4;
      }
      *(uint *)(unaff_RBX + 7) = uVar9;
    }
    *(undefined4 *)(unaff_RBX + 1) = 0x5b;
  }
  if ((int)unaff_RBX[1] == 0x5b) {
    if (*(ulonglong *)(unaff_RBX[6] + 0x30) != unaff_RSI) {
      uVar5 = (ulonglong)*(uint *)(unaff_RBX + 5);
      do {
        if ((int)unaff_RBX[5] == (int)unaff_RBX[3]) {
          if (*(uint *)(unaff_RBX[6] + 0x3c) != uVar9) {
            if ((uint)uVar5 < *(uint *)(unaff_RBX + 5)) {
              uVar4 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),(uint *)(uVar5 + unaff_RBX[2]),
                                    *(uint *)(unaff_RBX + 5) - (uint)uVar5);
              *(undefined4 *)(unaff_RDI + 0x4c) = uVar4;
            }
          }
          FUN_18004a2e0(unaff_RDI);
          if (*(uint *)(unaff_RBX + 5) != uVar9) goto LAB_1800496f2;
          uVar5 = unaff_RSI & 0xffffffff;
        }
        cVar3 = *(char *)(*(longlong *)(unaff_RBX[6] + 0x30) + (ulonglong)*(uint *)(unaff_RBX + 7));
        *(uint *)(unaff_RBX + 7) = *(uint *)(unaff_RBX + 7) + 1;
        *(char *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = cVar3;
        *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      } while (cVar3 != '\0');
      if ((*(uint *)(unaff_RBX[6] + 0x3c) != uVar9) && ((uint)uVar5 < *(uint *)(unaff_RBX + 5))) {
        uVar4 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),(uint *)(uVar5 + unaff_RBX[2]),
                              *(uint *)(unaff_RBX + 5) - (uint)uVar5);
        *(undefined4 *)(unaff_RDI + 0x4c) = uVar4;
      }
    }
    *(undefined4 *)(unaff_RBX + 1) = 0x67;
  }
  if ((int)unaff_RBX[1] == 0x67) {
    if (*(uint *)(unaff_RBX[6] + 0x3c) == uVar9) {
LAB_1800494c7:
      *(undefined4 *)(unaff_RBX + 1) = 0x71;
      FUN_18004a2e0(unaff_RDI);
      if (*(uint *)(unaff_RBX + 5) == uVar9) goto LAB_1800494df;
    }
    else if (((int)unaff_RBX[5] + 2U <= *(uint *)(unaff_RBX + 3)) ||
            (FUN_18004a2e0(unaff_RDI), *(uint *)(unaff_RBX + 5) == uVar9)) {
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
           *(undefined1 *)(unaff_RDI + 0x4c);
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
           *(undefined1 *)(unaff_RDI + 0x4d);
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      uVar4 = FUN_18004c120(0,(uint *)0x0,0);
      *(undefined4 *)(unaff_RDI + 0x4c) = uVar4;
      goto LAB_1800494c7;
    }
LAB_1800496f2:
    *(undefined4 *)(unaff_RBX + 8) = 0xffffffff;
  }
  else {
LAB_1800494df:
    if (((*(uint *)(unaff_RDI + 8) != uVar9) || (*(uint *)((longlong)unaff_RBX + 0x9c) != uVar9)) ||
       ((unaff_R12D != 0 && ((int)unaff_RBX[1] != 0x29a)))) {
      if (*(int *)((longlong)unaff_RBX + 0xac) == 0) {
        bVar2 = FUN_1800480b0(unaff_RBX,unaff_R12D);
        uVar5 = CONCAT71(extraout_var,bVar2);
      }
      else if ((int)unaff_RBX[0x16] == 2) {
        cVar3 = FUN_180049bb0(unaff_RBX,unaff_R12D);
        uVar5 = CONCAT71(extraout_var_00,cVar3);
      }
      else if ((int)unaff_RBX[0x16] == 3) {
        cVar3 = FUN_180049d80(unaff_RBX,unaff_R12D);
        uVar5 = CONCAT71(extraout_var_01,cVar3);
      }
      else {
        uVar5 = (*(code *)(&PTR_FUN_180057c18)[(longlong)*(int *)((longlong)unaff_RBX + 0xac) * 2])
                          ();
      }
      if ((int)uVar5 - 2U < 2) {
        *(undefined4 *)(unaff_RBX + 1) = 0x29a;
      }
      if ((uVar5 & 0xfffffffd) == 0) {
        if (*(uint *)(unaff_RDI + 0x18) != uVar9) {
          return 0;
        }
        goto LAB_1800496f2;
      }
      if ((int)uVar5 == 1) {
        if (unaff_R12D == 1) {
          FUN_18004c450((longlong)unaff_RBX);
        }
        else if ((unaff_R12D != 5) &&
                (FUN_18004c820((longlong)unaff_RBX,(void *)0x0,0,0), unaff_R12D == 3)) {
          *(short *)(unaff_RBX[0xd] + (ulonglong)(*(int *)((longlong)unaff_RBX + 0x74) - 1) * 2) =
               (short)unaff_RSI;
          memset((void *)unaff_RBX[0xd],0,(ulonglong)(*(int *)((longlong)unaff_RBX + 0x74) - 1) * 2)
          ;
          if (*(uint *)((longlong)unaff_RBX + 0x9c) == uVar9) {
            *(uint *)((longlong)unaff_RBX + 0x94) = uVar9;
            *(uint *)((longlong)unaff_RBX + 0x84) = uVar9;
            *(uint *)((longlong)unaff_RBX + 0x170c) = uVar9;
          }
        }
        FUN_18004a2e0(unaff_RDI);
        if (*(uint *)(unaff_RDI + 0x18) == uVar9) goto LAB_1800496f2;
      }
    }
    if (unaff_R12D == 4) {
      if (0 < *(int *)((longlong)unaff_RBX + 0x2c)) {
        if (*(int *)((longlong)unaff_RBX + 0x2c) == 2) {
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0x4c);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0x4d);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0x4e);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0x4f);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0xc);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0xd);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0xe);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0xf);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
        }
        else {
          plVar6 = unaff_RBX;
          FUN_18004a420((longlong)unaff_RBX,(uint)*(ushort *)(unaff_RDI + 0x4e));
          FUN_18004a420((longlong)plVar6,(uint)*(ushort *)(unaff_RDI + 0x4c));
        }
        FUN_18004a2e0(unaff_RDI);
        if (0 < *(int *)((longlong)unaff_RBX + 0x2c)) {
          *(int *)((longlong)unaff_RBX + 0x2c) = -*(int *)((longlong)unaff_RBX + 0x2c);
        }
        return CONCAT71((int7)(unaff_RSI >> 8),*(uint *)(unaff_RBX + 5) == uVar9) & 0xffffffff;
      }
      return 1;
    }
  }
  return 0;
}

/* ---- FUNC 000491EA FUN_1800491ea (1302 bytes) ---- */

ulonglong FUN_1800491ea(void)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  undefined4 uVar4;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  undefined7 extraout_var_01;
  ulonglong uVar5;
  longlong *plVar6;
  longlong *unaff_RBX;
  uint uVar7;
  uint uVar8;
  ulonglong unaff_RSI;
  longlong unaff_RDI;
  uint unaff_R12D;
  uint uVar9;
  uint uVar10;
  bool in_ZF;
  
  uVar8 = (uint)unaff_RSI;
  if (in_ZF) {
    if (*(ulonglong *)(unaff_RBX[6] + 0x10) != unaff_RSI) {
      uVar10 = (uint)*(ushort *)(unaff_RBX[6] + 0x18) - (int)unaff_RBX[7];
      uVar9 = *(uint *)(unaff_RBX + 5);
      if (*(uint *)(unaff_RBX + 3) < uVar9 + uVar10) {
        do {
          uVar7 = (int)unaff_RBX[3] - *(uint *)(unaff_RBX + 5);
          memcpy((void *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]),
                 (void *)((ulonglong)*(uint *)(unaff_RBX + 7) + *(longlong *)(unaff_RBX[6] + 0x10)),
                 (ulonglong)uVar7);
          uVar1 = *(uint *)(unaff_RBX + 3);
          *(uint *)(unaff_RBX + 5) = uVar1;
          if ((*(uint *)(unaff_RBX[6] + 0x3c) != uVar8) && (uVar9 < uVar1)) {
            uVar4 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),
                                  (uint *)((ulonglong)uVar9 + unaff_RBX[2]),uVar1 - uVar9);
            *(undefined4 *)(unaff_RDI + 0x4c) = uVar4;
          }
          *(uint *)(unaff_RBX + 7) = (int)unaff_RBX[7] + uVar7;
          FUN_18004a2e0(unaff_RDI);
          if (*(uint *)(unaff_RBX + 5) != uVar8) goto LAB_1800496f2;
          uVar10 = uVar10 - uVar7;
          uVar9 = uVar8;
        } while (*(uint *)(unaff_RBX + 3) < (int)unaff_RBX[5] + uVar10);
      }
      memcpy((void *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]),
             (void *)((ulonglong)*(uint *)(unaff_RBX + 7) + *(longlong *)(unaff_RBX[6] + 0x10)),
             (ulonglong)uVar10);
      *(uint *)(unaff_RBX + 5) = (int)unaff_RBX[5] + uVar10;
      if ((*(uint *)(unaff_RBX[6] + 0x3c) != uVar8) && (uVar9 < *(uint *)(unaff_RBX + 5))) {
        uVar4 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),(uint *)((ulonglong)uVar9 + unaff_RBX[2]),
                              *(uint *)(unaff_RBX + 5) - uVar9);
        *(undefined4 *)(unaff_RDI + 0x4c) = uVar4;
      }
      *(uint *)(unaff_RBX + 7) = uVar8;
    }
    *(undefined4 *)(unaff_RBX + 1) = 0x49;
  }
  if ((int)unaff_RBX[1] == 0x49) {
    if (*(ulonglong *)(unaff_RBX[6] + 0x20) != unaff_RSI) {
      uVar5 = (ulonglong)*(uint *)(unaff_RBX + 5);
      do {
        if ((int)unaff_RBX[5] == (int)unaff_RBX[3]) {
          if (*(uint *)(unaff_RBX[6] + 0x3c) != uVar8) {
            if ((uint)uVar5 < *(uint *)(unaff_RBX + 5)) {
              uVar4 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),(uint *)(uVar5 + unaff_RBX[2]),
                                    *(uint *)(unaff_RBX + 5) - (uint)uVar5);
              *(undefined4 *)(unaff_RDI + 0x4c) = uVar4;
            }
          }
          FUN_18004a2e0(unaff_RDI);
          if (*(uint *)(unaff_RBX + 5) != uVar8) goto LAB_1800496f2;
          uVar5 = unaff_RSI & 0xffffffff;
        }
        cVar3 = *(char *)(*(longlong *)(unaff_RBX[6] + 0x20) + (ulonglong)*(uint *)(unaff_RBX + 7));
        *(uint *)(unaff_RBX + 7) = *(uint *)(unaff_RBX + 7) + 1;
        *(char *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = cVar3;
        *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      } while (cVar3 != '\0');
      if ((*(uint *)(unaff_RBX[6] + 0x3c) != uVar8) && ((uint)uVar5 < *(uint *)(unaff_RBX + 5))) {
        uVar4 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),(uint *)(uVar5 + unaff_RBX[2]),
                              *(uint *)(unaff_RBX + 5) - (uint)uVar5);
        *(undefined4 *)(unaff_RDI + 0x4c) = uVar4;
      }
      *(uint *)(unaff_RBX + 7) = uVar8;
    }
    *(undefined4 *)(unaff_RBX + 1) = 0x5b;
  }
  if ((int)unaff_RBX[1] == 0x5b) {
    if (*(ulonglong *)(unaff_RBX[6] + 0x30) != unaff_RSI) {
      uVar5 = (ulonglong)*(uint *)(unaff_RBX + 5);
      do {
        if ((int)unaff_RBX[5] == (int)unaff_RBX[3]) {
          if (*(uint *)(unaff_RBX[6] + 0x3c) != uVar8) {
            if ((uint)uVar5 < *(uint *)(unaff_RBX + 5)) {
              uVar4 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),(uint *)(uVar5 + unaff_RBX[2]),
                                    *(uint *)(unaff_RBX + 5) - (uint)uVar5);
              *(undefined4 *)(unaff_RDI + 0x4c) = uVar4;
            }
          }
          FUN_18004a2e0(unaff_RDI);
          if (*(uint *)(unaff_RBX + 5) != uVar8) goto LAB_1800496f2;
          uVar5 = unaff_RSI & 0xffffffff;
        }
        cVar3 = *(char *)(*(longlong *)(unaff_RBX[6] + 0x30) + (ulonglong)*(uint *)(unaff_RBX + 7));
        *(uint *)(unaff_RBX + 7) = *(uint *)(unaff_RBX + 7) + 1;
        *(char *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) = cVar3;
        *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      } while (cVar3 != '\0');
      if ((*(uint *)(unaff_RBX[6] + 0x3c) != uVar8) && ((uint)uVar5 < *(uint *)(unaff_RBX + 5))) {
        uVar4 = FUN_18004c120(*(uint *)(unaff_RDI + 0x4c),(uint *)(uVar5 + unaff_RBX[2]),
                              *(uint *)(unaff_RBX + 5) - (uint)uVar5);
        *(undefined4 *)(unaff_RDI + 0x4c) = uVar4;
      }
    }
    *(undefined4 *)(unaff_RBX + 1) = 0x67;
  }
  if ((int)unaff_RBX[1] == 0x67) {
    if (*(uint *)(unaff_RBX[6] + 0x3c) == uVar8) {
LAB_1800494c7:
      *(undefined4 *)(unaff_RBX + 1) = 0x71;
      FUN_18004a2e0(unaff_RDI);
      if (*(uint *)(unaff_RBX + 5) == uVar8) goto LAB_1800494df;
    }
    else if (((int)unaff_RBX[5] + 2U <= *(uint *)(unaff_RBX + 3)) ||
            (FUN_18004a2e0(unaff_RDI), *(uint *)(unaff_RBX + 5) == uVar8)) {
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
           *(undefined1 *)(unaff_RDI + 0x4c);
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
           *(undefined1 *)(unaff_RDI + 0x4d);
      *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
      uVar4 = FUN_18004c120(0,(uint *)0x0,0);
      *(undefined4 *)(unaff_RDI + 0x4c) = uVar4;
      goto LAB_1800494c7;
    }
LAB_1800496f2:
    *(undefined4 *)(unaff_RBX + 8) = 0xffffffff;
  }
  else {
LAB_1800494df:
    if (((*(uint *)(unaff_RDI + 8) != uVar8) || (*(uint *)((longlong)unaff_RBX + 0x9c) != uVar8)) ||
       ((unaff_R12D != 0 && ((int)unaff_RBX[1] != 0x29a)))) {
      if (*(int *)((longlong)unaff_RBX + 0xac) == 0) {
        bVar2 = FUN_1800480b0(unaff_RBX,unaff_R12D);
        uVar5 = CONCAT71(extraout_var,bVar2);
      }
      else if ((int)unaff_RBX[0x16] == 2) {
        cVar3 = FUN_180049bb0(unaff_RBX,unaff_R12D);
        uVar5 = CONCAT71(extraout_var_00,cVar3);
      }
      else if ((int)unaff_RBX[0x16] == 3) {
        cVar3 = FUN_180049d80(unaff_RBX,unaff_R12D);
        uVar5 = CONCAT71(extraout_var_01,cVar3);
      }
      else {
        uVar5 = (*(code *)(&PTR_FUN_180057c18)[(longlong)*(int *)((longlong)unaff_RBX + 0xac) * 2])
                          ();
      }
      if ((int)uVar5 - 2U < 2) {
        *(undefined4 *)(unaff_RBX + 1) = 0x29a;
      }
      if ((uVar5 & 0xfffffffd) == 0) {
        if (*(uint *)(unaff_RDI + 0x18) != uVar8) {
          return 0;
        }
        goto LAB_1800496f2;
      }
      if ((int)uVar5 == 1) {
        if (unaff_R12D == 1) {
          FUN_18004c450((longlong)unaff_RBX);
        }
        else if ((unaff_R12D != 5) &&
                (FUN_18004c820((longlong)unaff_RBX,(void *)0x0,0,0), unaff_R12D == 3)) {
          *(short *)(unaff_RBX[0xd] + (ulonglong)(*(int *)((longlong)unaff_RBX + 0x74) - 1) * 2) =
               (short)unaff_RSI;
          memset((void *)unaff_RBX[0xd],0,(ulonglong)(*(int *)((longlong)unaff_RBX + 0x74) - 1) * 2)
          ;
          if (*(uint *)((longlong)unaff_RBX + 0x9c) == uVar8) {
            *(uint *)((longlong)unaff_RBX + 0x94) = uVar8;
            *(uint *)((longlong)unaff_RBX + 0x84) = uVar8;
            *(uint *)((longlong)unaff_RBX + 0x170c) = uVar8;
          }
        }
        FUN_18004a2e0(unaff_RDI);
        if (*(uint *)(unaff_RDI + 0x18) == uVar8) goto LAB_1800496f2;
      }
    }
    if (unaff_R12D == 4) {
      if (0 < *(int *)((longlong)unaff_RBX + 0x2c)) {
        if (*(int *)((longlong)unaff_RBX + 0x2c) == 2) {
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0x4c);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0x4d);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0x4e);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0x4f);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0xc);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0xd);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0xe);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
          *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 5) + unaff_RBX[2]) =
               *(undefined1 *)(unaff_RDI + 0xf);
          *(int *)(unaff_RBX + 5) = (int)unaff_RBX[5] + 1;
        }
        else {
          plVar6 = unaff_RBX;
          FUN_18004a420((longlong)unaff_RBX,(uint)*(ushort *)(unaff_RDI + 0x4e));
          FUN_18004a420((longlong)plVar6,(uint)*(ushort *)(unaff_RDI + 0x4c));
        }
        FUN_18004a2e0(unaff_RDI);
        if (0 < *(int *)((longlong)unaff_RBX + 0x2c)) {
          *(int *)((longlong)unaff_RBX + 0x2c) = -*(int *)((longlong)unaff_RBX + 0x2c);
        }
        return CONCAT71((int7)(unaff_RSI >> 8),*(uint *)(unaff_RBX + 5) == uVar8) & 0xffffffff;
      }
      return 1;
    }
  }
  return 0;
}

/* ---- FUNC 00049623 FUN_180049623 (202 bytes) ---- */

ulonglong FUN_180049623(int param_1)

{
  longlong lVar1;
  longlong unaff_RBX;
  undefined8 unaff_RSI;
  longlong unaff_RDI;
  
  if (param_1 == 2) {
    *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 0x28) + *(longlong *)(unaff_RBX + 0x10)) =
         *(undefined1 *)(unaff_RDI + 0x4c);
    *(int *)(unaff_RBX + 0x28) = *(int *)(unaff_RBX + 0x28) + 1;
    *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 0x28) + *(longlong *)(unaff_RBX + 0x10)) =
         *(undefined1 *)(unaff_RDI + 0x4d);
    *(int *)(unaff_RBX + 0x28) = *(int *)(unaff_RBX + 0x28) + 1;
    *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 0x28) + *(longlong *)(unaff_RBX + 0x10)) =
         *(undefined1 *)(unaff_RDI + 0x4e);
    *(int *)(unaff_RBX + 0x28) = *(int *)(unaff_RBX + 0x28) + 1;
    *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 0x28) + *(longlong *)(unaff_RBX + 0x10)) =
         *(undefined1 *)(unaff_RDI + 0x4f);
    *(int *)(unaff_RBX + 0x28) = *(int *)(unaff_RBX + 0x28) + 1;
    *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 0x28) + *(longlong *)(unaff_RBX + 0x10)) =
         *(undefined1 *)(unaff_RDI + 0xc);
    *(int *)(unaff_RBX + 0x28) = *(int *)(unaff_RBX + 0x28) + 1;
    *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 0x28) + *(longlong *)(unaff_RBX + 0x10)) =
         *(undefined1 *)(unaff_RDI + 0xd);
    *(int *)(unaff_RBX + 0x28) = *(int *)(unaff_RBX + 0x28) + 1;
    *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 0x28) + *(longlong *)(unaff_RBX + 0x10)) =
         *(undefined1 *)(unaff_RDI + 0xe);
    *(int *)(unaff_RBX + 0x28) = *(int *)(unaff_RBX + 0x28) + 1;
    *(undefined1 *)((ulonglong)*(uint *)(unaff_RBX + 0x28) + *(longlong *)(unaff_RBX + 0x10)) =
         *(undefined1 *)(unaff_RDI + 0xf);
    *(int *)(unaff_RBX + 0x28) = *(int *)(unaff_RBX + 0x28) + 1;
  }
  else {
    lVar1 = unaff_RBX;
    FUN_18004a420(unaff_RBX,(uint)*(ushort *)(unaff_RDI + 0x4e));
    FUN_18004a420(lVar1,(uint)*(ushort *)(unaff_RDI + 0x4c));
  }
  FUN_18004a2e0(unaff_RDI);
  if (0 < *(int *)(unaff_RBX + 0x2c)) {
    *(int *)(unaff_RBX + 0x2c) = -*(int *)(unaff_RBX + 0x2c);
  }
  return CONCAT71((int7)((ulonglong)unaff_RSI >> 8),*(int *)(unaff_RBX + 0x28) == (int)unaff_RSI) &
         0xffffffff;
}

/* ---- FUNC 00049700 FUN_180049700 (29 bytes) ---- */

undefined8 FUN_180049700(void)

{
  longlong unaff_RDI;
  
  *(undefined **)(unaff_RDI + 0x20) = PTR_s_stream_error_18005b250;
  return 0xfffffffe;
}

/* ---- FUNC 0004971D FUN_18004971d (13 bytes) ---- */

undefined8 FUN_18004971d(void)

{
  return 0xfffffffe;
}

/* ---- FUNC 00049730 FUN_180049730 (156 bytes) ---- */

undefined8 FUN_180049730(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = FUN_180049b50(param_1);
  if ((int)uVar2 != 0) {
    return 0xfffffffe;
  }
  iVar1 = *(int *)(*(longlong *)(param_1 + 0x28) + 8);
  if (*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x10) != 0) {
    (**(code **)(param_1 + 0x38))(*(undefined8 *)(param_1 + 0x40));
  }
  if (*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x68) != 0) {
    (**(code **)(param_1 + 0x38))(*(undefined8 *)(param_1 + 0x40));
  }
  if (*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x60) != 0) {
    (**(code **)(param_1 + 0x38))(*(undefined8 *)(param_1 + 0x40));
  }
  if (*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x50) != 0) {
    (**(code **)(param_1 + 0x38))(*(undefined8 *)(param_1 + 0x40));
  }
  (**(code **)(param_1 + 0x38))(*(undefined8 *)(param_1 + 0x40),*(undefined8 *)(param_1 + 0x28));
  uVar2 = 0;
  *(undefined8 *)(param_1 + 0x28) = 0;
  if (iVar1 == 0x71) {
    uVar2 = 0xfffffffd;
  }
  return uVar2;
}

/* ---- FUNC 000497D0 FUN_1800497d0 (87 bytes) ---- */

ulonglong FUN_1800497d0(longlong param_1,uint param_2,int param_3,int param_4,int param_5,
                       uint param_6,char *param_7,int param_8)

{
  uint uVar1;
  int iVar2;
  longlong *plVar3;
  longlong lVar4;
  ulonglong uVar5;
  uint uVar6;
  int iVar7;
  
  iVar2 = 1;
  if (((param_7 == (char *)0x0) || (*param_7 != '1')) || (param_8 != 0x58)) {
    return 0xfffffffa;
  }
  if (param_1 == 0) {
    return 0xfffffffe;
  }
  *(undefined8 *)(param_1 + 0x20) = 0;
  if (*(longlong *)(param_1 + 0x30) == 0) {
    *(undefined8 *)(param_1 + 0x40) = 0;
    *(code **)(param_1 + 0x30) = FUN_18004e2b0;
  }
  if (*(longlong *)(param_1 + 0x38) == 0) {
    *(code **)(param_1 + 0x38) = FUN_18004e2c0;
  }
  uVar6 = 6;
  if (param_2 != 0xffffffff) {
    uVar6 = param_2;
  }
  if (param_4 < 0) {
    param_4 = -param_4;
    iVar2 = 0;
  }
  else if (0xf < param_4) {
    iVar2 = 2;
    param_4 = param_4 + -0x10;
  }
  if (((param_5 - 1U < 9) && (param_3 == 8)) &&
     ((param_4 - 8U < 8 && ((uVar6 < 10 && (param_6 < 5)))))) {
    if (param_4 == 8) {
      if (iVar2 != 1) goto FUN_180049a4a;
      param_4 = 9;
    }
    plVar3 = (longlong *)(**(code **)(param_1 + 0x30))(*(undefined8 *)(param_1 + 0x40),1,0x1720);
    if (plVar3 != (longlong *)0x0) {
      *(longlong **)(param_1 + 0x28) = plVar3;
      *(int *)((longlong)plVar3 + 0x2c) = iVar2;
      iVar7 = 1 << ((byte)param_4 & 0x1f);
      *plVar3 = param_1;
      *(undefined4 *)(plVar3 + 1) = 0x2a;
      plVar3[6] = 0;
      *(int *)(plVar3 + 9) = param_4;
      *(int *)((longlong)plVar3 + 0x44) = iVar7;
      *(int *)((longlong)plVar3 + 0x4c) = iVar7 + -1;
      iVar2 = 1 << ((byte)(param_5 + 7) & 0x1f);
      *(int *)((longlong)plVar3 + 0x74) = iVar2;
      *(int *)((longlong)plVar3 + 0x7c) = iVar2 + -1;
      *(int *)(plVar3 + 0xf) = param_5 + 7;
      *(uint *)(plVar3 + 0x10) = (param_5 + 9U) / 3;
      lVar4 = (**(code **)(param_1 + 0x30))(*(undefined8 *)(param_1 + 0x40),iVar7,2);
      plVar3[10] = lVar4;
      lVar4 = (**(code **)(param_1 + 0x30))
                        (*(undefined8 *)(param_1 + 0x40),*(undefined4 *)((longlong)plVar3 + 0x44),2)
      ;
      plVar3[0xc] = lVar4;
      lVar4 = (**(code **)(param_1 + 0x30))
                        (*(undefined8 *)(param_1 + 0x40),*(undefined4 *)((longlong)plVar3 + 0x74),2)
      ;
      *(undefined4 *)(plVar3 + 0x2e3) = 0;
      iVar2 = 1 << ((char)param_5 + 6U & 0x1f);
      *(int *)(plVar3 + 0x2de) = iVar2;
      plVar3[0xd] = lVar4;
      lVar4 = (**(code **)(param_1 + 0x30))(*(undefined8 *)(param_1 + 0x40),iVar2,4);
      plVar3[2] = lVar4;
      uVar1 = *(uint *)(plVar3 + 0x2de);
      *(uint *)(plVar3 + 3) = uVar1 * 4;
      if ((((plVar3[10] != 0) && (plVar3[0xc] != 0)) && (plVar3[0xd] != 0)) && (lVar4 != 0)) {
        *(uint *)((longlong)plVar3 + 0xac) = uVar6;
        *(uint *)(plVar3 + 0x16) = param_6;
        *(undefined1 *)((longlong)plVar3 + 0x3c) = 8;
        plVar3[0x2df] = lVar4 + (ulonglong)(uVar1 >> 1) * 2;
        plVar3[0x2dd] = lVar4 + (ulonglong)uVar1 * 3;
        uVar5 = FUN_180049a70(param_1);
        return uVar5;
      }
      *(undefined4 *)(plVar3 + 1) = 0x29a;
      *(undefined **)(param_1 + 0x20) = PTR_s_insufficient_memory_18005b260;
      FUN_180049730(param_1);
    }
    uVar5 = 0xfffffffc;
  }
  else {
FUN_180049a4a:
    uVar5 = 0xfffffffe;
  }
  return uVar5;
}

/* ---- FUNC 00049827 FUN_180049827 (188 bytes) ---- */

ulonglong FUN_180049827(longlong param_1,uint param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  longlong *plVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong unaff_RBX;
  uint uVar6;
  int unaff_EDI;
  int iVar7;
  int unaff_R14D;
  int unaff_R15D;
  int in_stack_00000070;
  uint in_stack_00000078;
  
  *(longlong *)(unaff_RBX + 0x20) = param_1;
  if (*(longlong *)(unaff_RBX + 0x30) == param_1) {
    *(longlong *)(unaff_RBX + 0x40) = param_1;
    *(code **)(unaff_RBX + 0x30) = FUN_18004e2b0;
  }
  if (*(longlong *)(unaff_RBX + 0x38) == param_1) {
    *(code **)(unaff_RBX + 0x38) = FUN_18004e2c0;
  }
  uVar6 = 6;
  if (param_2 != 0xffffffff) {
    uVar6 = param_2;
  }
  if (unaff_EDI < 0) {
    unaff_R14D = (int)param_1;
    unaff_EDI = -unaff_EDI;
  }
  else if (0xf < unaff_EDI) {
    unaff_R14D = 2;
    unaff_EDI = unaff_EDI + -0x10;
  }
  if ((((in_stack_00000070 - 1U < 9) && (param_3 == 8)) && (unaff_EDI - 8U < 8)) &&
     ((uVar6 < 10 && (in_stack_00000078 < 5)))) {
    if (unaff_EDI == 8) {
      if (unaff_R14D != unaff_R15D) goto FUN_180049a4a;
      unaff_EDI = 9;
    }
    plVar3 = (longlong *)
             (**(code **)(unaff_RBX + 0x30))(*(undefined8 *)(unaff_RBX + 0x40),unaff_R15D,0x1720);
    if (plVar3 != (longlong *)0x0) {
      *(longlong **)(unaff_RBX + 0x28) = plVar3;
      *(int *)((longlong)plVar3 + 0x2c) = unaff_R14D;
      iVar7 = unaff_R15D << ((byte)unaff_EDI & 0x1f);
      *plVar3 = unaff_RBX;
      *(undefined4 *)(plVar3 + 1) = 0x2a;
      plVar3[6] = 0;
      *(int *)(plVar3 + 9) = unaff_EDI;
      *(int *)((longlong)plVar3 + 0x44) = iVar7;
      *(int *)((longlong)plVar3 + 0x4c) = iVar7 + -1;
      iVar2 = unaff_R15D << ((byte)(in_stack_00000070 + 7) & 0x1f);
      *(int *)((longlong)plVar3 + 0x74) = iVar2;
      *(int *)((longlong)plVar3 + 0x7c) = iVar2 + -1;
      *(int *)(plVar3 + 0xf) = in_stack_00000070 + 7;
      *(uint *)(plVar3 + 0x10) = (in_stack_00000070 + 9U) / 3;
      lVar4 = (**(code **)(unaff_RBX + 0x30))(*(undefined8 *)(unaff_RBX + 0x40),iVar7,2);
      plVar3[10] = lVar4;
      lVar4 = (**(code **)(unaff_RBX + 0x30))
                        (*(undefined8 *)(unaff_RBX + 0x40),*(undefined4 *)((longlong)plVar3 + 0x44),
                         2);
      plVar3[0xc] = lVar4;
      lVar4 = (**(code **)(unaff_RBX + 0x30))
                        (*(undefined8 *)(unaff_RBX + 0x40),*(undefined4 *)((longlong)plVar3 + 0x74),
                         2);
      *(undefined4 *)(plVar3 + 0x2e3) = 0;
      iVar2 = unaff_R15D << ((char)in_stack_00000070 + 6U & 0x1f);
      *(int *)(plVar3 + 0x2de) = iVar2;
      plVar3[0xd] = lVar4;
      lVar4 = (**(code **)(unaff_RBX + 0x30))(*(undefined8 *)(unaff_RBX + 0x40),iVar2,4);
      plVar3[2] = lVar4;
      uVar1 = *(uint *)(plVar3 + 0x2de);
      *(uint *)(plVar3 + 3) = uVar1 * 4;
      if (((plVar3[10] != 0) && (plVar3[0xc] != 0)) && ((plVar3[0xd] != 0 && (lVar4 != 0)))) {
        *(uint *)((longlong)plVar3 + 0xac) = uVar6;
        *(uint *)(plVar3 + 0x16) = in_stack_00000078;
        *(undefined1 *)((longlong)plVar3 + 0x3c) = 8;
        plVar3[0x2df] = lVar4 + (ulonglong)(uVar1 >> 1) * 2;
        plVar3[0x2dd] = lVar4 + (ulonglong)uVar1 * 3;
        uVar5 = FUN_180049a70(unaff_RBX);
        return uVar5;
      }
      *(undefined4 *)(plVar3 + 1) = 0x29a;
      *(undefined **)(unaff_RBX + 0x20) = PTR_s_insufficient_memory_18005b260;
      FUN_180049730(unaff_RBX);
    }
    uVar5 = 0xfffffffc;
  }
  else {
FUN_180049a4a:
    uVar5 = 0xfffffffe;
  }
  return uVar5;
}

/* ---- FUNC 000498E3 FUN_1800498e3 (300 bytes) ---- */

ulonglong FUN_1800498e3(void)

{
  uint uVar1;
  int iVar2;
  longlong *plVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong unaff_RBX;
  undefined4 unaff_EBP;
  undefined4 unaff_EDI;
  int iVar6;
  undefined4 unaff_R12D;
  int unaff_R13D;
  undefined4 unaff_R14D;
  int unaff_R15D;
  
  plVar3 = (longlong *)(**(code **)(unaff_RBX + 0x30))();
  if (plVar3 != (longlong *)0x0) {
    *(longlong **)(unaff_RBX + 0x28) = plVar3;
    *(undefined4 *)((longlong)plVar3 + 0x2c) = unaff_R14D;
    iVar6 = unaff_R15D << ((byte)unaff_EDI & 0x1f);
    *plVar3 = unaff_RBX;
    *(undefined4 *)(plVar3 + 1) = 0x2a;
    plVar3[6] = 0;
    *(undefined4 *)(plVar3 + 9) = unaff_EDI;
    *(int *)((longlong)plVar3 + 0x44) = iVar6;
    *(int *)((longlong)plVar3 + 0x4c) = iVar6 + -1;
    iVar2 = unaff_R15D << ((byte)(unaff_R13D + 7) & 0x1f);
    *(int *)((longlong)plVar3 + 0x74) = iVar2;
    *(int *)((longlong)plVar3 + 0x7c) = iVar2 + -1;
    *(int *)(plVar3 + 0xf) = unaff_R13D + 7;
    *(uint *)(plVar3 + 0x10) = (unaff_R13D + 9U) / 3;
    lVar4 = (**(code **)(unaff_RBX + 0x30))(*(undefined8 *)(unaff_RBX + 0x40),iVar6,2);
    plVar3[10] = lVar4;
    lVar4 = (**(code **)(unaff_RBX + 0x30))
                      (*(undefined8 *)(unaff_RBX + 0x40),*(undefined4 *)((longlong)plVar3 + 0x44),2)
    ;
    plVar3[0xc] = lVar4;
    lVar4 = (**(code **)(unaff_RBX + 0x30))
                      (*(undefined8 *)(unaff_RBX + 0x40),*(undefined4 *)((longlong)plVar3 + 0x74),2)
    ;
    *(undefined4 *)(plVar3 + 0x2e3) = 0;
    iVar2 = unaff_R15D << ((char)unaff_R13D + 6U & 0x1f);
    *(int *)(plVar3 + 0x2de) = iVar2;
    plVar3[0xd] = lVar4;
    lVar4 = (**(code **)(unaff_RBX + 0x30))(*(undefined8 *)(unaff_RBX + 0x40),iVar2,4);
    plVar3[2] = lVar4;
    uVar1 = *(uint *)(plVar3 + 0x2de);
    *(uint *)(plVar3 + 3) = uVar1 * 4;
    if ((((plVar3[10] != 0) && (plVar3[0xc] != 0)) && (plVar3[0xd] != 0)) && (lVar4 != 0)) {
      *(undefined4 *)((longlong)plVar3 + 0xac) = unaff_EBP;
      *(undefined4 *)(plVar3 + 0x16) = unaff_R12D;
      *(undefined1 *)((longlong)plVar3 + 0x3c) = 8;
      plVar3[0x2df] = lVar4 + (ulonglong)(uVar1 >> 1) * 2;
      plVar3[0x2dd] = lVar4 + (ulonglong)uVar1 * 3;
      uVar5 = FUN_180049a70(unaff_RBX);
      return uVar5;
    }
    *(undefined4 *)(plVar3 + 1) = 0x29a;
    *(undefined **)(unaff_RBX + 0x20) = PTR_s_insufficient_memory_18005b260;
    FUN_180049730(unaff_RBX);
  }
  return 0xfffffffc;
}

/* ---- FUNC 00049A0F FUN_180049a0f (26 bytes) ---- */

void FUN_180049a0f(void)

{
  return;
}

/* ---- FUNC 00049A29 FUN_180049a29 (33 bytes) ---- */

undefined8 FUN_180049a29(void)

{
  longlong unaff_RBX;
  longlong unaff_RSI;
  
  *(undefined4 *)(unaff_RSI + 8) = 0x29a;
  *(undefined **)(unaff_RBX + 0x20) = PTR_s_insufficient_memory_18005b260;
  FUN_180049730(unaff_RBX);
  return 0xfffffffc;
}

/* ---- FUNC 00049A4A FUN_180049a4a (7 bytes) ---- */

undefined8 FUN_180049a4a(void)

{
  return 0xfffffffe;
}

/* ---- FUNC 00049A51 FUN_180049a51 (16 bytes) ---- */

undefined8 FUN_180049a51(void)

{
  return 0xfffffffa;
}

/* ---- FUNC 00049A70 FUN_180049a70 (46 bytes) ---- */

ulonglong FUN_180049a70(longlong param_1)

{
  ulonglong uVar1;
  
  uVar1 = FUN_180049aa0(param_1);
  if ((int)uVar1 == 0) {
    FUN_18004a360(*(longlong *)(param_1 + 0x28));
    uVar1 = uVar1 & 0xffffffff;
  }
  return uVar1;
}

/* ---- FUNC 00049AA0 FUN_180049aa0 (174 bytes) ---- */

undefined8 FUN_180049aa0(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined8 uVar5;
  
  uVar5 = FUN_180049b50(param_1);
  if ((int)uVar5 != 0) {
    return 0xfffffffe;
  }
  *(undefined4 *)(param_1 + 0x48) = 2;
  lVar2 = *(longlong *)(param_1 + 0x28);
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(undefined8 *)(lVar2 + 0x20) = *(undefined8 *)(lVar2 + 0x10);
  *(undefined4 *)(lVar2 + 0x28) = 0;
  if (*(int *)(lVar2 + 0x2c) < 0) {
    *(int *)(lVar2 + 0x2c) = -*(int *)(lVar2 + 0x2c);
  }
  iVar1 = *(int *)(lVar2 + 0x2c);
  if (iVar1 == 2) {
    uVar3 = 0x39;
  }
  else {
    uVar3 = 0x71;
    if (iVar1 != 0) {
      uVar3 = 0x2a;
    }
  }
  *(undefined4 *)(lVar2 + 8) = uVar3;
  if (iVar1 == 2) {
    uVar4 = FUN_18004c120(0,(uint *)0x0,0);
  }
  else {
    uVar4 = FUN_18004dfc0(0,(byte *)0x0,0);
  }
  *(uint *)(param_1 + 0x4c) = uVar4;
  *(undefined4 *)(lVar2 + 0x40) = 0;
  _tr_init(lVar2);
  return 0;
}

/* ---- FUNC 00049B50 FUN_180049b50 (82 bytes) ---- */

undefined8 FUN_180049b50(longlong param_1)

{
  int iVar1;
  longlong *plVar2;
  
  if ((((param_1 != 0) && (*(longlong *)(param_1 + 0x30) != 0)) &&
      (*(longlong *)(param_1 + 0x38) != 0)) &&
     ((plVar2 = *(longlong **)(param_1 + 0x28), plVar2 != (longlong *)0x0 && (*plVar2 == param_1))))
  {
    iVar1 = (int)plVar2[1];
    if (((iVar1 - 0x2aU < 0x3e) &&
        ((0x2002000088008001U >> ((ulonglong)(iVar1 - 0x2aU) & 0x3f) & 1) != 0)) ||
       ((iVar1 == 0x71 || (iVar1 == 0x29a)))) {
      return 0;
    }
  }
  return 1;
}

/* ---- FUNC 00049BB0 FUN_180049bb0 (452 bytes) ---- */

char FUN_180049bb0(longlong *param_1,int param_2)

{
  short *psVar1;
  byte bVar2;
  uint uVar3;
  void *pvVar4;
  void *pvVar5;
  
  pvVar5 = (void *)0x0;
  while ((*(int *)((longlong)param_1 + 0x9c) != 0 ||
         (FUN_18004a0d0(param_1), *(int *)((longlong)param_1 + 0x9c) != 0))) {
    *(undefined4 *)(param_1 + 0x11) = 0;
    bVar2 = *(byte *)((ulonglong)*(uint *)((longlong)param_1 + 0x94) + param_1[10]);
    *(undefined2 *)(param_1[0x2df] + (ulonglong)*(uint *)((longlong)param_1 + 0x16f4) * 2) = 0;
    *(byte *)((ulonglong)*(uint *)((longlong)param_1 + 0x16f4) + param_1[0x2dd]) = bVar2;
    *(int *)((longlong)param_1 + 0x16f4) = *(int *)((longlong)param_1 + 0x16f4) + 1;
    psVar1 = (short *)((longlong)param_1 + (ulonglong)bVar2 * 4 + 0xbc);
    *psVar1 = *psVar1 + 1;
    *(int *)((longlong)param_1 + 0x94) = *(int *)((longlong)param_1 + 0x94) + 1;
    *(int *)((longlong)param_1 + 0x9c) = *(int *)((longlong)param_1 + 0x9c) + -1;
    if (*(int *)((longlong)param_1 + 0x16f4) == (int)param_1[0x2de] + -1) {
      uVar3 = *(uint *)((longlong)param_1 + 0x84);
      pvVar4 = pvVar5;
      if (-1 < (int)uVar3) {
        pvVar4 = (void *)((ulonglong)uVar3 + param_1[10]);
      }
      FUN_18004c580(param_1,pvVar4,*(int *)((longlong)param_1 + 0x94) - uVar3,0);
      *(undefined4 *)((longlong)param_1 + 0x84) = *(undefined4 *)((longlong)param_1 + 0x94);
      FUN_18004a2e0(*param_1);
      if (*(int *)(*param_1 + 0x18) == 0) {
        return '\0';
      }
    }
  }
  if (param_2 == 0) {
    return '\0';
  }
  *(undefined4 *)((longlong)param_1 + 0x170c) = 0;
  if (param_2 != 4) {
    if (*(int *)((longlong)param_1 + 0x16f4) != 0) {
      uVar3 = *(uint *)((longlong)param_1 + 0x84);
      if (-1 < (int)uVar3) {
        pvVar5 = (void *)((ulonglong)uVar3 + param_1[10]);
      }
      FUN_18004c580(param_1,pvVar5,*(int *)((longlong)param_1 + 0x94) - uVar3,0);
      *(undefined4 *)((longlong)param_1 + 0x84) = *(undefined4 *)((longlong)param_1 + 0x94);
      FUN_18004a2e0(*param_1);
      if (*(int *)(*param_1 + 0x18) == 0) {
        return '\0';
      }
    }
    return '\x01';
  }
  uVar3 = *(uint *)((longlong)param_1 + 0x84);
  if (-1 < (int)uVar3) {
    pvVar5 = (void *)((ulonglong)uVar3 + param_1[10]);
  }
  FUN_18004c580(param_1,pvVar5,*(int *)((longlong)param_1 + 0x94) - uVar3,1);
  *(undefined4 *)((longlong)param_1 + 0x84) = *(undefined4 *)((longlong)param_1 + 0x94);
  FUN_18004a2e0(*param_1);
  return (*(int *)(*param_1 + 0x18) != 0) + '\x02';
}

/* ---- FUNC 00049D80 FUN_180049d80 (836 bytes) ---- */

char FUN_180049d80(longlong *param_1,int param_2)

{
  short *psVar1;
  char cVar2;
  longlong lVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  byte bVar7;
  void *pvVar8;
  void *pvVar9;
  uint uVar10;
  char *pcVar11;
  bool bVar12;
  
  pvVar9 = (void *)0x0;
  do {
    uVar10 = *(uint *)((longlong)param_1 + 0x9c);
    if (uVar10 < 0x103) {
      FUN_18004a0d0(param_1);
      uVar10 = *(uint *)((longlong)param_1 + 0x9c);
      if ((uVar10 < 0x103) && (param_2 == 0)) {
        return '\0';
      }
      if (uVar10 == 0) {
        *(undefined4 *)((longlong)param_1 + 0x170c) = 0;
        if (param_2 == 4) {
          uVar10 = *(uint *)((longlong)param_1 + 0x84);
          if (-1 < (int)uVar10) {
            pvVar9 = (void *)((ulonglong)uVar10 + param_1[10]);
          }
          FUN_18004c580(param_1,pvVar9,*(int *)((longlong)param_1 + 0x94) - uVar10,1);
          *(undefined4 *)((longlong)param_1 + 0x84) = *(undefined4 *)((longlong)param_1 + 0x94);
          FUN_18004a2e0(*param_1);
          return (*(int *)(*param_1 + 0x18) != 0) + '\x02';
        }
        if (*(int *)((longlong)param_1 + 0x16f4) != 0) {
          uVar10 = *(uint *)((longlong)param_1 + 0x84);
          if (-1 < (int)uVar10) {
            pvVar9 = (void *)((ulonglong)uVar10 + param_1[10]);
          }
          FUN_18004c580(param_1,pvVar9,*(int *)((longlong)param_1 + 0x94) - uVar10,0);
          *(undefined4 *)((longlong)param_1 + 0x84) = *(undefined4 *)((longlong)param_1 + 0x94);
          FUN_18004a2e0(*param_1);
          if (*(int *)(*param_1 + 0x18) == 0) {
            return '\0';
          }
        }
        return '\x01';
      }
    }
    *(undefined4 *)(param_1 + 0x11) = 0;
    if ((2 < uVar10) && (*(uint *)((longlong)param_1 + 0x94) != 0)) {
      pcVar11 = (char *)(param_1[10] + (ulonglong)*(uint *)((longlong)param_1 + 0x94));
      cVar2 = pcVar11[-1];
      if ((cVar2 == *pcVar11) && ((cVar2 == pcVar11[1] && (cVar2 == pcVar11[2])))) {
        pcVar4 = pcVar11 + 2;
        do {
          pcVar5 = pcVar4 + 1;
          if (((((cVar2 != pcVar4[1]) || (pcVar5 = pcVar4 + 2, cVar2 != pcVar4[2])) ||
               (pcVar5 = pcVar4 + 3, cVar2 != pcVar4[3])) ||
              ((pcVar5 = pcVar4 + 4, cVar2 != pcVar4[4] || (pcVar5 = pcVar4 + 5, cVar2 != pcVar4[5])
               ))) || ((pcVar5 = pcVar4 + 6, cVar2 != pcVar4[6] ||
                       ((pcVar5 = pcVar4 + 7, cVar2 != pcVar4[7] ||
                        (pcVar5 = pcVar4 + 8, cVar2 != pcVar4[8])))))) break;
          pcVar4 = pcVar5;
        } while (pcVar5 < pcVar11 + 0x102);
        uVar6 = ((int)pcVar5 - (int)(pcVar11 + 0x102)) + 0x102;
        if (uVar10 < uVar6) {
          uVar6 = uVar10;
        }
        *(uint *)(param_1 + 0x11) = uVar6;
      }
    }
    if (*(uint *)(param_1 + 0x11) < 3) {
      bVar7 = *(byte *)((ulonglong)*(uint *)((longlong)param_1 + 0x94) + param_1[10]);
      *(undefined2 *)(param_1[0x2df] + (ulonglong)*(uint *)((longlong)param_1 + 0x16f4) * 2) = 0;
      *(byte *)((ulonglong)*(uint *)((longlong)param_1 + 0x16f4) + param_1[0x2dd]) = bVar7;
      *(int *)((longlong)param_1 + 0x16f4) = *(int *)((longlong)param_1 + 0x16f4) + 1;
      psVar1 = (short *)((longlong)param_1 + (ulonglong)bVar7 * 4 + 0xbc);
      *psVar1 = *psVar1 + 1;
      bVar12 = *(int *)((longlong)param_1 + 0x16f4) == (int)param_1[0x2de] + -1;
      *(int *)((longlong)param_1 + 0x9c) = *(int *)((longlong)param_1 + 0x9c) + -1;
      *(int *)((longlong)param_1 + 0x94) = *(int *)((longlong)param_1 + 0x94) + 1;
    }
    else {
      bVar7 = (char)param_1[0x11] - 3;
      *(undefined2 *)(param_1[0x2df] + (ulonglong)*(uint *)((longlong)param_1 + 0x16f4) * 2) = 1;
      *(byte *)((ulonglong)*(uint *)((longlong)param_1 + 0x16f4) + param_1[0x2dd]) = bVar7;
      *(int *)((longlong)param_1 + 0x16f4) = *(int *)((longlong)param_1 + 0x16f4) + 1;
      psVar1 = (short *)((longlong)param_1 + (ulonglong)(byte)(&DAT_18005a770)[bVar7] * 4 + 0x4c0);
      *psVar1 = *psVar1 + 1;
      psVar1 = (short *)((longlong)param_1 + (ulonglong)DAT_18005a870 * 4 + 0x9b0);
      *psVar1 = *psVar1 + 1;
      bVar12 = *(int *)((longlong)param_1 + 0x16f4) == (int)param_1[0x2de] + -1;
      lVar3 = param_1[0x11];
      *(undefined4 *)(param_1 + 0x11) = 0;
      *(int *)((longlong)param_1 + 0x9c) = *(int *)((longlong)param_1 + 0x9c) - (int)lVar3;
      *(int *)((longlong)param_1 + 0x94) = *(int *)((longlong)param_1 + 0x94) + (int)lVar3;
    }
    if (bVar12) {
      uVar10 = *(uint *)((longlong)param_1 + 0x84);
      pvVar8 = pvVar9;
      if (-1 < (int)uVar10) {
        pvVar8 = (void *)((ulonglong)uVar10 + param_1[10]);
      }
      FUN_18004c580(param_1,pvVar8,*(int *)((longlong)param_1 + 0x94) - uVar10,0);
      *(undefined4 *)((longlong)param_1 + 0x84) = *(undefined4 *)((longlong)param_1 + 0x94);
      FUN_18004a2e0(*param_1);
      if (*(int *)(*param_1 + 0x18) == 0) {
        return '\0';
      }
    }
  } while( true );
}

/* ---- FUNC 0004A0D0 FUN_18004a0d0 (516 bytes) ---- */

void FUN_18004a0d0(longlong *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar6;
  ulonglong uVar5;
  
  uVar1 = *(uint *)((longlong)param_1 + 0x44);
  while( true ) {
    uVar3 = ((int)param_1[0xb] - *(int *)((longlong)param_1 + 0x9c)) -
            *(uint *)((longlong)param_1 + 0x94);
    if (*(int *)((longlong)param_1 + 0x44) + -0x106 + uVar1 <= *(uint *)((longlong)param_1 + 0x94))
    {
      memcpy((void *)param_1[10],(void *)(param_1[10] + (ulonglong)uVar1),(ulonglong)(uVar1 - uVar3)
            );
      *(uint *)(param_1 + 0x13) = (int)param_1[0x13] - uVar1;
      *(int *)((longlong)param_1 + 0x94) = *(int *)((longlong)param_1 + 0x94) - uVar1;
      *(int *)((longlong)param_1 + 0x84) = *(int *)((longlong)param_1 + 0x84) - uVar1;
      FUN_18004a4f0((longlong)param_1);
      uVar3 = uVar3 + uVar1;
    }
    if ((int)((longlong *)*param_1)[1] == 0) break;
    uVar3 = read_buf((longlong *)*param_1,
                     (uint *)((ulonglong)*(uint *)((longlong)param_1 + 0x9c) +
                              (ulonglong)*(uint *)((longlong)param_1 + 0x94) + param_1[10]),uVar3);
    *(int *)((longlong)param_1 + 0x9c) = *(int *)((longlong)param_1 + 0x9c) + uVar3;
    iVar2 = *(int *)((longlong)param_1 + 0x170c);
    if (2 < (uint)(*(int *)((longlong)param_1 + 0x9c) + iVar2)) {
      uVar4 = *(int *)((longlong)param_1 + 0x94) - iVar2;
      uVar5 = (ulonglong)uVar4;
      uVar3 = (uint)*(byte *)(uVar5 + param_1[10]);
      *(uint *)(param_1 + 0xe) = uVar3;
      *(uint *)(param_1 + 0xe) =
           ((uint)*(byte *)((ulonglong)(uVar4 + 1) + param_1[10]) ^
           uVar3 << ((byte)(int)param_1[0x10] & 0x1f)) & *(uint *)((longlong)param_1 + 0x7c);
      if (iVar2 != 0) {
        uVar4 = uVar4 + 2;
        do {
          uVar6 = (ulonglong)uVar4;
          uVar4 = uVar4 + 1;
          uVar3 = ((uint)*(byte *)(uVar6 + param_1[10]) ^
                  (int)param_1[0xe] << ((byte)(int)param_1[0x10] & 0x1f)) &
                  *(uint *)((longlong)param_1 + 0x7c);
          *(uint *)(param_1 + 0xe) = uVar3;
          *(undefined2 *)(param_1[0xc] + (*(uint *)((longlong)param_1 + 0x4c) & uVar5) * 2) =
               *(undefined2 *)(param_1[0xd] + (ulonglong)uVar3 * 2);
          *(short *)(param_1[0xd] + (ulonglong)*(uint *)(param_1 + 0xe) * 2) = (short)uVar5;
          uVar5 = (ulonglong)((int)uVar5 + 1);
          *(int *)((longlong)param_1 + 0x170c) = *(int *)((longlong)param_1 + 0x170c) + -1;
          if ((uint)(*(int *)((longlong)param_1 + 0x9c) + *(int *)((longlong)param_1 + 0x170c)) < 3)
          break;
        } while (*(int *)((longlong)param_1 + 0x170c) != 0);
      }
    }
    if ((0x105 < *(uint *)((longlong)param_1 + 0x9c)) || (*(int *)(*param_1 + 8) == 0)) break;
  }
  uVar1 = *(uint *)(param_1 + 0x2e3);
  uVar3 = *(uint *)(param_1 + 0xb);
  if (uVar1 < uVar3) {
    uVar4 = *(int *)((longlong)param_1 + 0x9c) + *(int *)((longlong)param_1 + 0x94);
    if (uVar1 < uVar4) {
      uVar3 = uVar3 - uVar4;
      if (0x102 < uVar3) {
        uVar3 = 0x102;
      }
      memset((void *)((ulonglong)uVar4 + param_1[10]),0,(ulonglong)uVar3);
      *(uint *)(param_1 + 0x2e3) = uVar3 + uVar4;
      return;
    }
    if (uVar1 < uVar4 + 0x102) {
      uVar4 = (uVar4 - uVar1) + 0x102;
      if (uVar3 - uVar1 < uVar4) {
        uVar4 = uVar3 - uVar1;
      }
      memset((void *)((ulonglong)uVar1 + param_1[10]),0,(ulonglong)uVar4);
      *(uint *)(param_1 + 0x2e3) = (int)param_1[0x2e3] + uVar4;
    }
  }
  return;
}

/* ---- FUNC 0004A2E0 FUN_18004a2e0 (52 bytes) ---- */

void FUN_18004a2e0(longlong param_1)

{
  int *piVar1;
  longlong lVar2;
  uint uVar3;
  
  lVar2 = *(longlong *)(param_1 + 0x28);
  bi_flush(lVar2);
  uVar3 = *(uint *)(lVar2 + 0x28);
  if (*(uint *)(param_1 + 0x18) < *(uint *)(lVar2 + 0x28)) {
    uVar3 = *(uint *)(param_1 + 0x18);
  }
  if (uVar3 != 0) {
    memcpy(*(void **)(param_1 + 0x10),*(void **)(lVar2 + 0x20),(ulonglong)uVar3);
    *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + (ulonglong)uVar3;
    *(longlong *)(lVar2 + 0x20) = *(longlong *)(lVar2 + 0x20) + (ulonglong)uVar3;
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + uVar3;
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) - uVar3;
    piVar1 = (int *)(lVar2 + 0x28);
    *piVar1 = *piVar1 - uVar3;
    if (*piVar1 == 0) {
      *(undefined8 *)(lVar2 + 0x20) = *(undefined8 *)(lVar2 + 0x10);
    }
  }
  return;
}

/* ---- FUNC 0004A314 FUN_18004a314 (39 bytes) ---- */

void FUN_18004a314(void *param_1,void *param_2)

{
  int *piVar1;
  uint unaff_EBP;
  longlong unaff_RSI;
  longlong unaff_RDI;
  
  memcpy(param_1,param_2,(ulonglong)unaff_EBP);
  *(longlong *)(unaff_RSI + 0x10) = *(longlong *)(unaff_RSI + 0x10) + (ulonglong)unaff_EBP;
  *(longlong *)(unaff_RDI + 0x20) = *(longlong *)(unaff_RDI + 0x20) + (ulonglong)unaff_EBP;
  *(int *)(unaff_RSI + 0x1c) = *(int *)(unaff_RSI + 0x1c) + unaff_EBP;
  *(int *)(unaff_RSI + 0x18) = *(int *)(unaff_RSI + 0x18) - unaff_EBP;
  piVar1 = (int *)(unaff_RDI + 0x28);
  *piVar1 = *piVar1 - unaff_EBP;
  if (*piVar1 == 0) {
    *(undefined8 *)(unaff_RDI + 0x20) = *(undefined8 *)(unaff_RDI + 0x10);
  }
  return;
}

/* ---- FUNC 0004A33B FUN_18004a33b (24 bytes) ---- */

void FUN_18004a33b(void)

{
  longlong unaff_RDI;
  
  *(undefined8 *)(unaff_RDI + 0x20) = *(undefined8 *)(unaff_RDI + 0x10);
  return;
}

/* ---- FUNC 0004A360 FUN_18004a360 (16970 bytes) ---- */

void FUN_18004a360(longlong param_1)

{
  longlong lVar1;
  
  *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x44) * 2;
  *(undefined2 *)(*(longlong *)(param_1 + 0x68) + (ulonglong)(*(int *)(param_1 + 0x74) - 1) * 2) = 0
  ;
  memset(*(void **)(param_1 + 0x68),0,(ulonglong)(*(int *)(param_1 + 0x74) - 1) * 2);
  lVar1 = (longlong)*(int *)(param_1 + 0xac);
  *(uint *)(param_1 + 0xa8) = (uint)*(ushort *)(&DAT_180057c12 + lVar1 * 0x10);
  *(uint *)(param_1 + 0xb4) = (uint)*(ushort *)(&DAT_180057c10 + lVar1 * 0x10);
  *(uint *)(param_1 + 0xb8) = (uint)*(ushort *)(&DAT_180057c14 + lVar1 * 0x10);
  *(uint *)(param_1 + 0xa4) = (uint)*(ushort *)(&DAT_180057c16 + lVar1 * 0x10);
  *(undefined8 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x9c) = 0;
  *(undefined4 *)(param_1 + 0x170c) = 0;
  *(undefined4 *)(param_1 + 0xa0) = 2;
  *(undefined4 *)(param_1 + 0x88) = 2;
  *(undefined4 *)(param_1 + 0x70) = 0;
  return;
}

/* ---- FUNC 0004A420 FUN_18004a420 (38 bytes) ---- */

void FUN_18004a420(longlong param_1,undefined4 param_2)

{
  *(char *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
       (char)((uint)param_2 >> 8);
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
  *(char *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) = (char)param_2;
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
  return;
}

/* ---- FUNC 0004A450 read_buf (160 bytes) ---- */

/* Library Function - Single Match
    read_buf
   
   Library: Visual Studio 2019 Release */

uint read_buf(longlong *param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_1 + 1);
  uVar2 = uVar1;
  if (param_3 < uVar1) {
    uVar2 = param_3;
  }
  if (uVar2 == 0) {
    return 0;
  }
  *(uint *)(param_1 + 1) = uVar1 - uVar2;
  memcpy(param_2,(void *)*param_1,(ulonglong)uVar2);
  if (*(int *)(param_1[5] + 0x2c) == 1) {
    uVar1 = FUN_18004dfc0(*(uint *)((longlong)param_1 + 0x4c),(byte *)param_2,uVar2);
  }
  else {
    if (*(int *)(param_1[5] + 0x2c) != 2) goto LAB_18004a4d3;
    uVar1 = FUN_18004c120(*(uint *)((longlong)param_1 + 0x4c),param_2,uVar2);
  }
  *(uint *)((longlong)param_1 + 0x4c) = uVar1;
LAB_18004a4d3:
  *param_1 = *param_1 + (ulonglong)uVar2;
  *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + uVar2;
  return uVar2;
}

/* ---- FUNC 0004A4F0 FUN_18004a4f0 (94 bytes) ---- */

void FUN_18004a4f0(longlong param_1)

{
  ushort *puVar1;
  uint uVar2;
  short sVar3;
  short *psVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  uVar7 = (ulonglong)*(uint *)(param_1 + 0x74);
  uVar2 = *(uint *)(param_1 + 0x44);
  uVar5 = (ulonglong)uVar2;
  psVar4 = (short *)(*(longlong *)(param_1 + 0x68) + uVar7 * 2);
  do {
    puVar1 = (ushort *)(psVar4 + -1);
    psVar4 = psVar4 + -1;
    if (*puVar1 < uVar2) {
      sVar3 = 0;
    }
    else {
      sVar3 = *puVar1 - (short)uVar2;
    }
    *psVar4 = sVar3;
    uVar6 = (int)uVar7 - 1;
    uVar7 = (ulonglong)uVar6;
  } while (uVar6 != 0);
  psVar4 = (short *)(*(longlong *)(param_1 + 0x60) + uVar5 * 2);
  do {
    puVar1 = (ushort *)(psVar4 + -1);
    psVar4 = psVar4 + -1;
    if (*puVar1 < uVar2) {
      sVar3 = 0;
    }
    else {
      sVar3 = *puVar1 - (short)uVar2;
    }
    *psVar4 = sVar3;
    uVar6 = (int)uVar5 - 1;
    uVar5 = (ulonglong)uVar6;
  } while (uVar6 != 0);
  return;
}

/* ---- FUNC 0004A550 FUN_18004a550 (37 bytes) ---- */

void FUN_18004a550(longlong param_1)

{
  *(undefined4 *)(param_1 + 0x70) = 9;
  *(undefined **)(param_1 + 0x60) = &DAT_180057cb0;
  *(undefined **)(param_1 + 0x68) = &DAT_1800584b0;
  *(undefined4 *)(param_1 + 0x74) = 5;
  return;
}

/* ---- FUNC 0004A580 FUN_18004a580 (65 bytes) ---- */

ulonglong FUN_18004a580(longlong *param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined8 uVar11;
  char *pcVar12;
  byte bVar13;
  ushort uVar14;
  uint uVar15;
  uint uVar16;
  longlong *plVar17;
  ulonglong uVar18;
  int iVar19;
  longlong lVar20;
  uint uVar21;
  undefined2 uVar22;
  undefined1 *puVar23;
  uint uVar24;
  size_t _Size;
  ulonglong uVar25;
  uint *_Src;
  uint local_res18;
  uint local_res20;
  undefined2 local_68;
  undefined1 local_66;
  undefined1 local_65;
  uint local_64;
  uint local_60;
  uint local_5c;
  undefined1 *local_58;
  
  plVar17 = param_1;
  uVar11 = FUN_18004bfe0((longlong)param_1);
  if ((((int)uVar11 != 0) || (plVar17[2] == 0)) || ((*plVar17 == 0 && ((int)plVar17[1] != 0)))) {
    return 0xfffffffe;
  }
  lVar1 = plVar17[5];
  if (*(int *)(lVar1 + 8) == 0x3f3f) {
    *(undefined4 *)(lVar1 + 8) = 0x3f40;
  }
  local_res20 = *(uint *)(plVar17 + 3);
  uVar18 = (ulonglong)local_res20;
  puVar23 = (undefined1 *)plVar17[2];
  uVar6 = *(int *)(lVar1 + 8) - 0x3f34;
  uVar10 = *(uint *)(plVar17 + 1);
  _Src = (uint *)*plVar17;
  uVar9 = *(uint *)(lVar1 + 0x48);
  uVar21 = *(uint *)(lVar1 + 0x4c);
  local_res18 = 0;
  uVar25 = uVar18;
  local_64 = local_res20;
  local_5c = uVar10;
  local_58 = puVar23;
  if (0x1e < uVar6) {
    return 0xfffffffe;
  }
  do {
    uVar24 = (uint)uVar18;
    uVar18 = 0;
    uVar15 = 0;
    uVar16 = (uint)uVar25;
    switch((ulonglong)(&switchD_18004a65b::switchdataD_18004bca8)[(int)uVar6] + 0x180000000) {
    case 0x18004a65d:
      if (*(uint *)(lVar1 + 0x10) == 0) {
        *(undefined4 *)(lVar1 + 8) = 0x3f40;
        break;
      }
      for (; uVar21 < 0x10; uVar21 = uVar21 + 8) {
        uVar4 = 0;
        if (uVar10 == 0) goto LAB_18004bb56;
        uVar10 = uVar10 - 1;
        uVar9 = uVar9 + ((uint)(byte)*_Src << ((byte)uVar21 & 0x1f));
        _Src = (uint *)((longlong)_Src + 1);
      }
      if (((*(uint *)(lVar1 + 0x10) & 2) == 0) || (uVar9 != 0x8b1f)) {
        *(undefined4 *)(lVar1 + 0x18) = 0;
        if (*(longlong *)(lVar1 + 0x28) != 0) {
          *(undefined4 *)(*(longlong *)(lVar1 + 0x28) + 0x40) = 0xffffffff;
        }
        if (((*(byte *)(lVar1 + 0x10) & 1) == 0) ||
           (uVar6 = (uVar9 & 0xff) * 0x100 + (uVar9 >> 8), uVar6 != (uVar6 / 0x1f) * 0x1f)) {
          param_1[4] = (longlong)"incorrect header check";
          *(undefined4 *)(lVar1 + 8) = 0x3f51;
        }
        else {
          if (((byte)uVar9 & 0xf) != 8) goto LAB_18004a748;
          uVar21 = uVar21 - 4;
          uVar6 = (uVar9 >> 4 & 0xf) + 8;
          if (*(int *)(lVar1 + 0x30) == 0) {
            *(uint *)(lVar1 + 0x30) = uVar6;
          }
          if ((uVar6 < 0x10) && (uVar6 <= *(uint *)(lVar1 + 0x30))) {
            *(int *)(lVar1 + 0x1c) = 1 << (sbyte)uVar6;
            uVar6 = FUN_18004dfc0(0,(byte *)0x0,0);
            uVar21 = 0;
            *(uint *)(lVar1 + 0x20) = uVar6;
            *(uint *)((longlong)param_1 + 0x4c) = uVar6;
            *(uint *)(lVar1 + 8) = ~(uVar9 >> 0xc) & 2 | 0x3f3d;
            uVar9 = 0;
            goto LAB_18004acc8;
          }
          param_1[4] = (longlong)"invalid window size";
          *(undefined4 *)(lVar1 + 8) = 0x3f51;
          uVar9 = uVar9 >> 4;
        }
        break;
      }
      if (*(int *)(lVar1 + 0x30) == 0) {
        *(undefined4 *)(lVar1 + 0x30) = 0xf;
      }
      uVar7 = FUN_18004c120(0,(uint *)0x0,0);
      *(undefined4 *)(lVar1 + 0x20) = uVar7;
      local_68 = 0x8b1f;
      uVar7 = FUN_18004c120(*(uint *)(lVar1 + 0x20),(uint *)&local_68,2);
      *(undefined4 *)(lVar1 + 0x20) = uVar7;
      uVar9 = 0;
      uVar21 = 0;
      *(undefined4 *)(lVar1 + 8) = 0x3f35;
      goto LAB_18004acc8;
    case 0x18004a7f5:
      for (; uVar21 < 0x10; uVar21 = uVar21 + 8) {
        if (uVar10 == 0) {
          uVar25 = (ulonglong)local_res18;
          uVar10 = 0;
          goto LAB_18004bb5a;
        }
        uVar10 = uVar10 - 1;
        uVar9 = uVar9 + ((uint)(byte)*_Src << ((byte)uVar21 & 0x1f));
        _Src = (uint *)((longlong)_Src + 1);
      }
      *(uint *)(lVar1 + 0x18) = uVar9;
      if ((char)uVar9 == '\b') {
        if ((uVar9 & 0xe000) == 0) {
          if (*(uint **)(lVar1 + 0x28) != (uint *)0x0) {
            **(uint **)(lVar1 + 0x28) = uVar9 >> 8 & 1;
          }
          if (((*(uint *)(lVar1 + 0x18) & 0x200) != 0) && ((*(byte *)(lVar1 + 0x10) & 4) != 0)) {
            local_68 = (undefined2)uVar9;
            uVar7 = FUN_18004c120(*(uint *)(lVar1 + 0x20),(uint *)&local_68,2);
            *(undefined4 *)(lVar1 + 0x20) = uVar7;
          }
          *(undefined4 *)(lVar1 + 8) = 0x3f36;
          uVar9 = uVar15;
          uVar21 = uVar15;
          do {
            uVar4 = 0;
            if (uVar10 == 0) goto LAB_18004bb56;
            uVar10 = uVar10 - 1;
            uVar9 = uVar9 + ((uint)(byte)*_Src << ((byte)uVar21 & 0x1f));
            _Src = (uint *)((longlong)_Src + 1);
            uVar21 = uVar21 + 8;
joined_r0x00018004a8aa:
          } while (uVar21 < 0x20);
          if (*(longlong *)(lVar1 + 0x28) != 0) {
            *(uint *)(*(longlong *)(lVar1 + 0x28) + 4) = uVar9;
          }
          if (((*(uint *)(lVar1 + 0x18) & 0x200) != 0) && ((*(byte *)(lVar1 + 0x10) & 4) != 0)) {
            local_68 = (undefined2)uVar9;
            local_66 = (undefined1)(uVar9 >> 0x10);
            local_65 = (undefined1)(uVar9 >> 0x18);
            uVar7 = FUN_18004c120(*(uint *)(lVar1 + 0x20),(uint *)&local_68,4);
            *(undefined4 *)(lVar1 + 0x20) = uVar7;
          }
          *(undefined4 *)(lVar1 + 8) = 0x3f37;
          uVar9 = uVar15;
          uVar21 = uVar15;
          do {
            uVar4 = 0;
            if (uVar10 == 0) goto LAB_18004bb56;
            uVar10 = uVar10 - 1;
            uVar9 = uVar9 + ((uint)(byte)*_Src << ((byte)uVar21 & 0x1f));
            _Src = (uint *)((longlong)_Src + 1);
            uVar21 = uVar21 + 8;
joined_r0x00018004a936:
          } while (uVar21 < 0x10);
          if (*(longlong *)(lVar1 + 0x28) != 0) {
            *(uint *)(*(longlong *)(lVar1 + 0x28) + 8) = uVar9 & 0xff;
            *(uint *)(*(longlong *)(lVar1 + 0x28) + 0xc) = uVar9 >> 8;
          }
          if (((*(uint *)(lVar1 + 0x18) & 0x200) != 0) && ((*(byte *)(lVar1 + 0x10) & 4) != 0)) {
            local_68 = (undefined2)uVar9;
            uVar7 = FUN_18004c120(*(uint *)(lVar1 + 0x20),(uint *)&local_68,2);
            *(undefined4 *)(lVar1 + 0x20) = uVar7;
          }
          *(undefined4 *)(lVar1 + 8) = 0x3f38;
          uVar9 = uVar15;
          uVar21 = uVar15;
          goto switchD_18004a65b_caseD_8004a9b7;
        }
        param_1[4] = (longlong)"unknown header flags set";
        *(undefined4 *)(lVar1 + 8) = 0x3f51;
      }
      else {
LAB_18004a748:
        param_1[4] = (longlong)"unknown compression method";
        *(undefined4 *)(lVar1 + 8) = 0x3f51;
      }
      break;
    case 0x18004a8a7:
      goto joined_r0x00018004a8aa;
    case 0x18004a933:
      goto joined_r0x00018004a936;
    case 0x18004a9b7:
switchD_18004a65b_caseD_8004a9b7:
      if ((*(uint *)(lVar1 + 0x18) & 0x400) == 0) {
        uVar15 = uVar9;
        if (*(longlong *)(lVar1 + 0x28) != 0) {
          *(undefined8 *)(*(longlong *)(lVar1 + 0x28) + 0x10) = 0;
        }
      }
      else {
        for (; uVar21 < 0x10; uVar21 = uVar21 + 8) {
          uVar4 = 0;
          if (uVar10 == 0) goto LAB_18004bb56;
          uVar10 = uVar10 - 1;
          uVar9 = uVar9 + ((uint)(byte)*_Src << ((byte)uVar21 & 0x1f));
          _Src = (uint *)((longlong)_Src + 1);
        }
        *(uint *)(lVar1 + 0x50) = uVar9;
        if (*(longlong *)(lVar1 + 0x28) != 0) {
          *(uint *)(*(longlong *)(lVar1 + 0x28) + 0x18) = uVar9;
        }
        uVar21 = uVar15;
        if (((*(uint *)(lVar1 + 0x18) & 0x200) != 0) && ((*(byte *)(lVar1 + 0x10) & 4) != 0)) {
          local_68 = (undefined2)uVar9;
          uVar7 = FUN_18004c120(*(uint *)(lVar1 + 0x20),(uint *)&local_68,2);
          *(undefined4 *)(lVar1 + 0x20) = uVar7;
        }
      }
      uVar9 = uVar15;
      *(undefined4 *)(lVar1 + 8) = 0x3f39;
    case 0x18004aa48:
      if ((*(uint *)(lVar1 + 0x18) & 0x400) == 0) {
LAB_18004aad6:
        *(undefined4 *)(lVar1 + 0x50) = 0;
        *(undefined4 *)(lVar1 + 8) = 0x3f3a;
switchD_18004a65b_caseD_8004aae2:
        if ((*(uint *)(lVar1 + 0x18) & 0x800) == 0) {
          if (*(longlong *)(lVar1 + 0x28) != 0) {
            *(undefined8 *)(*(longlong *)(lVar1 + 0x28) + 0x20) = 0;
          }
LAB_18004ab7b:
          *(undefined4 *)(lVar1 + 0x50) = 0;
          *(undefined4 *)(lVar1 + 8) = 0x3f3b;
switchD_18004a65b_caseD_8004ab87:
          uVar25 = 0;
          if ((*(uint *)(lVar1 + 0x18) & 0x1000) == 0) {
            if (*(longlong *)(lVar1 + 0x28) != 0) {
              *(undefined8 *)(*(longlong *)(lVar1 + 0x28) + 0x30) = 0;
            }
LAB_18004ac1b:
            uVar25 = (ulonglong)local_res20;
            *(undefined4 *)(lVar1 + 8) = 0x3f3c;
            puVar23 = local_58;
switchD_18004a65b_caseD_8004ac2f:
            if ((*(uint *)(lVar1 + 0x18) & 0x200) != 0) {
              for (; uVar21 < 0x10; uVar21 = uVar21 + 8) {
                uVar4 = 0;
                if (uVar10 == 0) goto LAB_18004bb56;
                uVar10 = uVar10 - 1;
                uVar9 = uVar9 + ((uint)(byte)*_Src << ((byte)uVar21 & 0x1f));
                _Src = (uint *)((longlong)_Src + 1);
              }
              if (((*(byte *)(lVar1 + 0x10) & 4) != 0) && (uVar9 != *(ushort *)(lVar1 + 0x20))) {
                param_1[4] = (longlong)"header crc mismatch";
                *(undefined4 *)(lVar1 + 8) = 0x3f51;
                break;
              }
              uVar9 = 0;
              uVar21 = uVar9;
            }
            if (*(longlong *)(lVar1 + 0x28) != 0) {
              *(uint *)(*(longlong *)(lVar1 + 0x28) + 0x3c) = *(int *)(lVar1 + 0x18) >> 9 & 1;
              *(undefined4 *)(*(longlong *)(lVar1 + 0x28) + 0x40) = 1;
            }
            uVar7 = FUN_18004c120(0,(uint *)0x0,0);
            *(undefined4 *)(lVar1 + 0x20) = uVar7;
            *(undefined4 *)((longlong)param_1 + 0x4c) = uVar7;
LAB_18004acc0:
            *(undefined4 *)(lVar1 + 8) = 0x3f3f;
LAB_18004acc8:
            uVar25 = (ulonglong)local_res20;
            puVar23 = local_58;
            break;
          }
          uVar4 = uVar10;
          if (uVar10 != 0) {
            do {
              uVar6 = (int)uVar25 + 1;
              cVar5 = *(char *)(uVar25 + (longlong)_Src);
              lVar20 = *(longlong *)(lVar1 + 0x28);
              if (((lVar20 != 0) && (*(longlong *)(lVar20 + 0x30) != 0)) &&
                 (*(uint *)(lVar1 + 0x50) < *(uint *)(lVar20 + 0x38))) {
                *(char *)((ulonglong)*(uint *)(lVar1 + 0x50) + *(longlong *)(lVar20 + 0x30)) = cVar5
                ;
                *(int *)(lVar1 + 0x50) = *(int *)(lVar1 + 0x50) + 1;
              }
            } while ((cVar5 != '\0') && (uVar25 = (ulonglong)uVar6, uVar6 < uVar10));
            if (((*(uint *)(lVar1 + 0x18) & 0x200) != 0) && ((*(byte *)(lVar1 + 0x10) & 4) != 0)) {
              uVar7 = FUN_18004c120(*(uint *)(lVar1 + 0x20),_Src,uVar6);
              *(undefined4 *)(lVar1 + 0x20) = uVar7;
            }
            uVar10 = uVar10 - uVar6;
            _Src = (uint *)((longlong)_Src + (ulonglong)uVar6);
            uVar4 = uVar10;
            if (cVar5 == '\0') goto LAB_18004ac1b;
          }
        }
        else {
          uVar4 = uVar10;
          if (uVar10 != 0) {
            do {
              uVar6 = (int)uVar18 + 1;
              cVar5 = *(char *)(uVar18 + (longlong)_Src);
              lVar20 = *(longlong *)(lVar1 + 0x28);
              if (((lVar20 != 0) && (*(longlong *)(lVar20 + 0x20) != 0)) &&
                 (*(uint *)(lVar1 + 0x50) < *(uint *)(lVar20 + 0x28))) {
                *(char *)((ulonglong)*(uint *)(lVar1 + 0x50) + *(longlong *)(lVar20 + 0x20)) = cVar5
                ;
                *(int *)(lVar1 + 0x50) = *(int *)(lVar1 + 0x50) + 1;
              }
            } while ((cVar5 != '\0') && (uVar18 = (ulonglong)uVar6, uVar6 < uVar10));
            if (((*(uint *)(lVar1 + 0x18) & 0x200) != 0) && ((*(byte *)(lVar1 + 0x10) & 4) != 0)) {
              uVar7 = FUN_18004c120(*(uint *)(lVar1 + 0x20),_Src,uVar6);
              *(undefined4 *)(lVar1 + 0x20) = uVar7;
            }
            uVar10 = uVar10 - uVar6;
            _Src = (uint *)((longlong)_Src + (ulonglong)uVar6);
            uVar4 = uVar10;
            if (cVar5 == '\0') goto LAB_18004ab7b;
          }
        }
      }
      else {
        uVar6 = *(uint *)(lVar1 + 0x50);
        uVar15 = uVar6;
        if (uVar10 < uVar6) {
          uVar15 = uVar10;
        }
        if (uVar15 != 0) {
          lVar20 = *(longlong *)(lVar1 + 0x28);
          if ((lVar20 != 0) && (*(longlong *)(lVar20 + 0x10) != 0)) {
            uVar6 = *(int *)(lVar20 + 0x18) - uVar6;
            uVar16 = uVar15;
            if (*(uint *)(lVar20 + 0x1c) < uVar15 + uVar6) {
              uVar16 = *(uint *)(lVar20 + 0x1c) - uVar6;
            }
            memcpy((void *)((ulonglong)uVar6 + *(longlong *)(lVar20 + 0x10)),_Src,(ulonglong)uVar16)
            ;
          }
          if (((*(uint *)(lVar1 + 0x18) & 0x200) != 0) && ((*(byte *)(lVar1 + 0x10) & 4) != 0)) {
            uVar7 = FUN_18004c120(*(uint *)(lVar1 + 0x20),_Src,uVar15);
            *(undefined4 *)(lVar1 + 0x20) = uVar7;
          }
          uVar10 = uVar10 - uVar15;
          _Src = (uint *)((longlong)_Src + (ulonglong)uVar15);
          *(int *)(lVar1 + 0x50) = *(int *)(lVar1 + 0x50) - uVar15;
        }
        uVar4 = uVar10;
        if (*(int *)(lVar1 + 0x50) == 0) goto LAB_18004aad6;
      }
LAB_18004bb56:
      uVar10 = uVar4;
      uVar25 = (ulonglong)local_res18;
LAB_18004bb5a:
      uVar6 = local_64;
      param_1[2] = (longlong)local_58;
      *(uint *)(param_1 + 3) = local_res20;
      *param_1 = (longlong)_Src;
      *(uint *)(param_1 + 1) = uVar10;
      *(uint *)(lVar1 + 0x4c) = uVar21;
      *(uint *)(lVar1 + 0x48) = uVar9;
      if (((*(int *)(lVar1 + 0x34) == 0) &&
          (((local_64 == *(uint *)(param_1 + 3) || (0x3f50 < *(int *)(lVar1 + 8))) ||
           ((0x3f4d < *(int *)(lVar1 + 8) && (param_2 == 4)))))) ||
         (uVar11 = FUN_18004c020((longlong)param_1,param_1[2],local_64 - (int)param_1[3]),
         (int)uVar11 == 0)) {
        uVar6 = uVar6 - (int)param_1[3];
        local_5c = local_5c - (int)param_1[1];
        *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + local_5c;
        *(int *)((longlong)param_1 + 0x1c) = *(int *)((longlong)param_1 + 0x1c) + uVar6;
        *(int *)(lVar1 + 0x24) = *(int *)(lVar1 + 0x24) + uVar6;
        if (((*(byte *)(lVar1 + 0x10) & 4) != 0) && (uVar6 != 0)) {
          if (*(int *)(lVar1 + 0x18) == 0) {
            uVar10 = FUN_18004dfc0(*(uint *)(lVar1 + 0x20),(byte *)(param_1[2] - (ulonglong)uVar6),
                                   uVar6);
          }
          else {
            uVar10 = FUN_18004c120(*(uint *)(lVar1 + 0x20),(uint *)(param_1[2] - (ulonglong)uVar6),
                                   uVar6);
          }
          *(uint *)(lVar1 + 0x20) = uVar10;
          *(uint *)((longlong)param_1 + 0x4c) = uVar10;
        }
        iVar8 = *(int *)(lVar1 + 8);
        if ((iVar8 == 0x3f47) || (iVar8 == 0x3f42)) {
          iVar19 = 0x100;
        }
        else {
          iVar19 = 0;
        }
        iVar2 = 0;
        if (iVar8 == 0x3f3f) {
          iVar2 = 0x80;
        }
        *(uint *)(param_1 + 9) =
             iVar2 + iVar19 + (-(uint)(*(int *)(lVar1 + 0xc) != 0) & 0x40) + *(int *)(lVar1 + 0x4c);
        if (((local_5c != 0) || (uVar6 != 0)) && (param_2 != 4)) {
          return uVar25;
        }
        if ((int)uVar25 == 0) {
          return 0xfffffffb;
        }
        return uVar25;
      }
      *(undefined4 *)(lVar1 + 8) = 0x3f52;
LAB_18004bafb:
      return 0xfffffffc;
    case 0x18004aae2:
      goto switchD_18004a65b_caseD_8004aae2;
    case 0x18004ab87:
      goto switchD_18004a65b_caseD_8004ab87;
    case 0x18004ac2f:
      goto switchD_18004a65b_caseD_8004ac2f;
    case 0x18004acee:
      for (; uVar21 < 0x20; uVar21 = uVar21 + 8) {
        uVar4 = 0;
        if (uVar10 == 0) goto LAB_18004bb56;
        uVar10 = uVar10 - 1;
        uVar9 = uVar9 + ((uint)(byte)*_Src << ((byte)uVar21 & 0x1f));
        _Src = (uint *)((longlong)_Src + 1);
      }
      iVar8 = (uVar9 >> 8 & 0xff00) + ((uVar9 & 0xff00) + uVar9 * 0x10000) * 0x100 + (uVar9 >> 0x18)
      ;
      *(int *)(lVar1 + 0x20) = iVar8;
      *(int *)((longlong)param_1 + 0x4c) = iVar8;
      *(undefined4 *)(lVar1 + 8) = 0x3f3e;
      uVar9 = uVar15;
      uVar21 = uVar15;
    case 0x18004ad50:
      if (*(int *)(lVar1 + 0x14) == 0) {
        param_1[2] = (longlong)puVar23;
        *(uint *)(param_1 + 3) = uVar16;
        *param_1 = (longlong)_Src;
        *(uint *)(param_1 + 1) = uVar10;
        *(uint *)(lVar1 + 0x48) = uVar9;
        *(uint *)(lVar1 + 0x4c) = uVar21;
        return 2;
      }
      uVar6 = FUN_18004dfc0(0,(byte *)0x0,0);
      uVar25 = (ulonglong)local_res20;
      *(uint *)(lVar1 + 0x20) = uVar6;
      *(uint *)((longlong)param_1 + 0x4c) = uVar6;
      *(undefined4 *)(lVar1 + 8) = 0x3f3f;
      puVar23 = local_58;
switchD_18004a65b_caseD_8004ad7e:
      uVar4 = uVar10;
      if (1 < param_2 - 5U) {
switchD_18004a65b_caseD_8004ad8d:
        if (*(int *)(lVar1 + 0xc) == 0) {
          for (; uVar21 < 3; uVar21 = uVar21 + 8) {
            uVar4 = 0;
            if (uVar10 == 0) goto LAB_18004bb56;
            uVar10 = uVar10 - 1;
            uVar9 = uVar9 + ((uint)(byte)*_Src << ((byte)uVar21 & 0x1f));
            _Src = (uint *)((longlong)_Src + 1);
          }
          *(uint *)(lVar1 + 0xc) = uVar9 & 1;
          uVar6 = uVar9 >> 1 & 3;
          if (uVar6 == 0) {
            *(undefined4 *)(lVar1 + 8) = 0x3f41;
          }
          else {
            if (uVar6 != 1) {
              if (uVar6 == 2) {
                uVar21 = uVar21 - 3;
                *(undefined4 *)(lVar1 + 8) = 0x3f44;
                uVar9 = uVar9 >> 3;
              }
              else {
                if (uVar6 != 3) goto LAB_18004ae55;
                param_1[4] = (longlong)"invalid block type";
                uVar21 = uVar21 - 3;
                *(undefined4 *)(lVar1 + 8) = 0x3f51;
                uVar9 = uVar9 >> 3;
              }
              break;
            }
            FUN_18004a550(lVar1);
            *(undefined4 *)(lVar1 + 8) = 0x3f47;
            if (param_2 == 6) {
              uVar4 = uVar10;
              uVar9 = uVar9 >> 3;
              uVar21 = uVar21 - 3;
              goto LAB_18004bb56;
            }
          }
LAB_18004ae55:
          uVar21 = uVar21 - 3;
          uVar9 = uVar9 >> 3;
        }
        else {
          *(undefined4 *)(lVar1 + 8) = 0x3f4e;
          uVar6 = uVar21 & 7;
          uVar21 = uVar21 - uVar6;
          uVar9 = uVar9 >> (sbyte)uVar6;
        }
        break;
      }
      goto LAB_18004bb56;
    case 0x18004ad7e:
      goto switchD_18004a65b_caseD_8004ad7e;
    case 0x18004ad8d:
      goto switchD_18004a65b_caseD_8004ad8d;
    case 0x18004ae61:
      uVar9 = uVar9 >> (sbyte)(uVar21 & 7);
      for (uVar21 = uVar21 - (uVar21 & 7); uVar21 < 0x20; uVar21 = uVar21 + 8) {
        uVar4 = 0;
        if (uVar10 == 0) goto LAB_18004bb56;
        uVar10 = uVar10 - 1;
        uVar9 = uVar9 + ((uint)(byte)*_Src << ((byte)uVar21 & 0x1f));
        _Src = (uint *)((longlong)_Src + 1);
      }
      if ((uVar9 & 0xffff) == ~uVar9 >> 0x10) {
        *(uint *)(lVar1 + 0x50) = uVar9 & 0xffff;
        *(undefined4 *)(lVar1 + 8) = 0x3f42;
        uVar4 = uVar10;
        uVar9 = uVar15;
        uVar21 = uVar15;
        if (param_2 == 6) goto LAB_18004bb56;
        goto switchD_18004a65b_caseD_8004aed6;
      }
      param_1[4] = (longlong)"invalid stored block lengths";
      *(undefined4 *)(lVar1 + 8) = 0x3f51;
      break;
    case 0x18004aed6:
switchD_18004a65b_caseD_8004aed6:
      *(undefined4 *)(lVar1 + 8) = 0x3f43;
    case 0x18004aede:
      uVar6 = *(uint *)(lVar1 + 0x50);
      if (uVar6 == 0) {
        *(undefined4 *)(lVar1 + 8) = 0x3f3f;
        break;
      }
      if (uVar10 < uVar6) {
        uVar6 = uVar10;
      }
      _Size = (size_t)uVar6;
      if (uVar16 < uVar6) {
        _Size = uVar25 & 0xffffffff;
      }
      iVar8 = (int)_Size;
      uVar4 = uVar10;
      if (iVar8 != 0) {
        memcpy(puVar23,_Src,_Size);
        _Src = (uint *)((longlong)_Src + _Size);
        local_res20 = local_res20 - iVar8;
        uVar25 = (ulonglong)local_res20;
        local_58 = local_58 + _Size;
        uVar10 = uVar10 - iVar8;
        *(int *)(lVar1 + 0x50) = *(int *)(lVar1 + 0x50) - iVar8;
        puVar23 = local_58;
        break;
      }
      goto LAB_18004bb56;
    case 0x18004af45:
      for (; uVar21 < 0xe; uVar21 = uVar21 + 8) {
        uVar4 = 0;
        if (uVar10 == 0) goto LAB_18004bb56;
        uVar10 = uVar10 - 1;
        uVar9 = uVar9 + ((uint)(byte)*_Src << ((byte)uVar21 & 0x1f));
        _Src = (uint *)((longlong)_Src + 1);
      }
      uVar21 = uVar21 - 0xe;
      uVar15 = uVar9 >> 5;
      uVar6 = (uVar9 & 0x1f) + 0x101;
      uVar16 = uVar9 >> 10;
      *(uint *)(lVar1 + 0x7c) = uVar6;
      uVar9 = uVar9 >> 0xe;
      uVar15 = (uVar15 & 0x1f) + 1;
      *(uint *)(lVar1 + 0x80) = uVar15;
      *(uint *)(lVar1 + 0x78) = (uVar16 & 0xf) + 4;
      if ((uVar6 < 0x11f) && (uVar15 < 0x1f)) {
        *(undefined4 *)(lVar1 + 0x84) = 0;
        *(undefined4 *)(lVar1 + 8) = 0x3f45;
        goto switchD_18004a65b_caseD_8004afcf;
      }
      param_1[4] = (longlong)"too many length or distance symbols";
      *(undefined4 *)(lVar1 + 8) = 0x3f51;
      break;
    case 0x18004afcf:
switchD_18004a65b_caseD_8004afcf:
      if (*(uint *)(lVar1 + 0x84) < *(uint *)(lVar1 + 0x78)) {
        do {
          for (; uVar21 < 3; uVar21 = uVar21 + 8) {
            uVar4 = 0;
            if (uVar10 == 0) goto LAB_18004bb56;
            uVar10 = uVar10 - 1;
            uVar9 = uVar9 + ((uint)(byte)*_Src << ((byte)uVar21 & 0x1f));
            _Src = (uint *)((longlong)_Src + 1);
          }
          uVar14 = (ushort)uVar9;
          uVar9 = uVar9 >> 3;
          uVar21 = uVar21 - 3;
          *(ushort *)
           (lVar1 + 0x90 +
           (ulonglong)*(ushort *)(&DAT_180058530 + (ulonglong)*(uint *)(lVar1 + 0x84) * 2) * 2) =
               uVar14 & 7;
          *(int *)(lVar1 + 0x84) = *(int *)(lVar1 + 0x84) + 1;
        } while (*(uint *)(lVar1 + 0x84) < *(uint *)(lVar1 + 0x78));
      }
      uVar6 = *(uint *)(lVar1 + 0x84);
      while (uVar6 < 0x13) {
        *(undefined2 *)
         (lVar1 + 0x90 +
         (ulonglong)*(ushort *)(&DAT_180058530 + (ulonglong)*(uint *)(lVar1 + 0x84) * 2) * 2) = 0;
        *(int *)(lVar1 + 0x84) = *(int *)(lVar1 + 0x84) + 1;
        uVar6 = *(uint *)(lVar1 + 0x84);
      }
      *(uint *)(lVar1 + 0x70) = 7;
      *(longlong *)(lVar1 + 0x60) = lVar1 + 0x550;
      *(longlong *)(lVar1 + 0x88) = lVar1 + 0x550;
      uVar11 = FUN_18004e5b0(0,(ushort *)(lVar1 + 0x90),0x13,(longlong *)(lVar1 + 0x88),
                             (uint *)(lVar1 + 0x70),(undefined *)(lVar1 + 0x310));
      uVar25 = (ulonglong)local_res20;
      local_res18 = (uint)uVar11;
      if (local_res18 == 0) {
        *(undefined4 *)(lVar1 + 0x84) = 0;
        *(undefined4 *)(lVar1 + 8) = 0x3f46;
        goto switchD_18004a65b_caseD_8004b106;
      }
      param_1[4] = (longlong)"invalid code lengths set";
      *(undefined4 *)(lVar1 + 8) = 0x3f51;
      puVar23 = local_58;
      break;
    case 0x18004b106:
switchD_18004a65b_caseD_8004b106:
      puVar23 = local_58;
      if (*(uint *)(lVar1 + 0x84) < (uint)(*(int *)(lVar1 + 0x80) + *(int *)(lVar1 + 0x7c))) {
        do {
          local_60 = *(uint *)(*(longlong *)(lVar1 + 0x60) +
                              (ulonglong)
                              ((1 << ((byte)*(undefined4 *)(lVar1 + 0x70) & 0x1f)) - 1U & uVar9) * 4
                              );
          if (uVar21 < (local_60 >> 8 & 0xff)) {
            do {
              uVar4 = 0;
              if (uVar10 == 0) goto LAB_18004bb56;
              uVar10 = uVar10 - 1;
              uVar9 = uVar9 + ((uint)(byte)*_Src << ((byte)uVar21 & 0x1f));
              _Src = (uint *)((longlong)_Src + 1);
              uVar21 = uVar21 + 8;
              local_60 = *(uint *)(*(longlong *)(lVar1 + 0x60) +
                                  (ulonglong)
                                  ((1 << ((byte)*(undefined4 *)(lVar1 + 0x70) & 0x1f)) - 1U & uVar9)
                                  * 4);
            } while (uVar21 < (local_60 >> 8 & 0xff));
          }
          uVar14 = (ushort)(local_60 >> 0x10);
          bVar13 = (byte)(local_60 >> 8);
          if (0xf < uVar14) {
            if (uVar14 == 0x10) {
              for (; uVar21 < (local_60 >> 8 & 0xff) + 2; uVar21 = uVar21 + 8) {
                uVar4 = 0;
                if (uVar10 == 0) goto LAB_18004bb56;
                uVar10 = uVar10 - 1;
                uVar9 = uVar9 + ((uint)(byte)*_Src << ((byte)uVar21 & 0x1f));
                _Src = (uint *)((longlong)_Src + 1);
              }
              uVar21 = uVar21 - bVar13;
              uVar9 = uVar9 >> (bVar13 & 0x1f);
              if (*(int *)(lVar1 + 0x84) != 0) {
                uVar6 = uVar9 & 3;
                uVar9 = uVar9 >> 2;
                iVar19 = uVar6 + 3;
                uVar21 = uVar21 - 2;
                uVar22 = *(undefined2 *)(lVar1 + 0x90 + (ulonglong)(*(int *)(lVar1 + 0x84) - 1) * 2)
                ;
                goto LAB_18004b2d0;
              }
            }
            else {
              if (uVar14 == 0x11) {
                for (; uVar21 < bVar13 + 3; uVar21 = uVar21 + 8) {
                  uVar4 = 0;
                  if (uVar10 == 0) goto LAB_18004bb56;
                  uVar10 = uVar10 - 1;
                  uVar9 = uVar9 + ((uint)(byte)*_Src << ((byte)uVar21 & 0x1f));
                  _Src = (uint *)((longlong)_Src + 1);
                }
                iVar8 = -3;
                uVar9 = uVar9 >> (bVar13 & 0x1f);
                iVar19 = (uVar9 & 7) + 3;
                uVar9 = uVar9 >> 3;
              }
              else {
                for (; uVar21 < bVar13 + 7; uVar21 = uVar21 + 8) {
                  uVar4 = 0;
                  if (uVar10 == 0) goto LAB_18004bb56;
                  uVar10 = uVar10 - 1;
                  uVar9 = uVar9 + ((uint)(byte)*_Src << ((byte)uVar21 & 0x1f));
                  _Src = (uint *)((longlong)_Src + 1);
                }
                iVar8 = -7;
                uVar9 = uVar9 >> (bVar13 & 0x1f);
                iVar19 = (uVar9 & 0x7f) + 0xb;
                uVar9 = uVar9 >> 7;
              }
              uVar21 = uVar21 + (iVar8 - (uint)bVar13);
              uVar22 = 0;
LAB_18004b2d0:
              if ((uint)(*(int *)(lVar1 + 0x84) + iVar19) <=
                  (uint)(*(int *)(lVar1 + 0x80) + *(int *)(lVar1 + 0x7c))) {
                do {
                  *(undefined2 *)(lVar1 + 0x90 + (ulonglong)*(uint *)(lVar1 + 0x84) * 2) = uVar22;
                  *(int *)(lVar1 + 0x84) = *(int *)(lVar1 + 0x84) + 1;
                  uVar6 = *(uint *)(lVar1 + 0x84);
                  iVar19 = iVar19 + -1;
                } while (iVar19 != 0);
                goto LAB_18004b317;
              }
            }
            param_1[4] = (longlong)"invalid bit length repeat";
            *(undefined4 *)(lVar1 + 8) = 0x3f51;
            goto LAB_18004acd0;
          }
          uVar21 = uVar21 - (local_60 >> 8 & 0xff);
          uVar9 = uVar9 >> (bVar13 & 0x1f);
          *(ushort *)(lVar1 + 0x90 + (ulonglong)*(uint *)(lVar1 + 0x84) * 2) = uVar14;
          *(int *)(lVar1 + 0x84) = *(int *)(lVar1 + 0x84) + 1;
          uVar6 = *(uint *)(lVar1 + 0x84);
LAB_18004b317:
        } while (uVar6 < (uint)(*(int *)(lVar1 + 0x80) + *(int *)(lVar1 + 0x7c)));
      }
      if (*(int *)(lVar1 + 8) != 0x3f51) {
        if (*(short *)(lVar1 + 0x290) != 0) {
          *(uint *)(lVar1 + 0x70) = 9;
          *(longlong *)(lVar1 + 0x88) = lVar1 + 0x550;
          *(longlong *)(lVar1 + 0x60) = lVar1 + 0x550;
          uVar11 = FUN_18004e5b0(1,(ushort *)(lVar1 + 0x90),*(uint *)(lVar1 + 0x7c),
                                 (longlong *)(lVar1 + 0x88),(uint *)(lVar1 + 0x70),
                                 (undefined *)(lVar1 + 0x310));
          local_res18 = (uint)uVar11;
          if (local_res18 == 0) {
            *(undefined8 *)(lVar1 + 0x68) = *(undefined8 *)(lVar1 + 0x88);
            *(uint *)(lVar1 + 0x74) = 6;
            uVar25 = FUN_18004e5b0(2,(ushort *)
                                     ((ulonglong)*(uint *)(lVar1 + 0x7c) * 2 + 0x90 + lVar1),
                                   *(uint *)(lVar1 + 0x80),(longlong *)(lVar1 + 0x88),
                                   (uint *)(lVar1 + 0x74),(undefined *)(lVar1 + 0x310));
            local_res18 = (uint)uVar25;
            uVar25 = uVar25 & 0xffffffff;
            if (local_res18 == 0) {
              *(undefined4 *)(lVar1 + 8) = 0x3f47;
              puVar23 = local_58;
              uVar16 = local_res20;
              uVar24 = local_64;
              if (param_2 != 6) goto switchD_18004a65b_caseD_8004b460;
              goto LAB_18004bb5a;
            }
            pcVar12 = "invalid distances set";
          }
          else {
            pcVar12 = "invalid literal/lengths set";
          }
          param_1[4] = (longlong)pcVar12;
          *(undefined4 *)(lVar1 + 8) = 0x3f51;
          goto LAB_18004acc8;
        }
        param_1[4] = (longlong)"invalid code -- missing end-of-block";
        *(undefined4 *)(lVar1 + 8) = 0x3f51;
      }
      break;
    case 0x18004b460:
switchD_18004a65b_caseD_8004b460:
      *(undefined4 *)(lVar1 + 8) = 0x3f48;
    case 0x18004b468:
      if ((5 < uVar10) && (0x101 < uVar16)) {
        param_1[2] = (longlong)puVar23;
        *(uint *)(param_1 + 3) = uVar16;
        *param_1 = (longlong)_Src;
        *(uint *)(param_1 + 1) = uVar10;
        *(uint *)(lVar1 + 0x48) = uVar9;
        *(uint *)(lVar1 + 0x4c) = uVar21;
        FUN_18004ea50(param_1,uVar24);
        local_58 = (undefined1 *)param_1[2];
        local_res20 = *(uint *)(param_1 + 3);
        uVar25 = (ulonglong)local_res20;
        _Src = (uint *)*param_1;
        uVar10 = *(uint *)(param_1 + 1);
        uVar21 = *(uint *)(lVar1 + 0x4c);
        puVar23 = local_58;
        uVar9 = *(uint *)(lVar1 + 0x48);
        if (*(int *)(lVar1 + 8) == 0x3f3f) {
          *(undefined4 *)(lVar1 + 0x1be4) = 0xffffffff;
        }
        break;
      }
      *(undefined4 *)(lVar1 + 0x1be4) = 0;
      uVar6 = *(uint *)(*(longlong *)(lVar1 + 0x60) +
                       (ulonglong)((1 << ((byte)*(undefined4 *)(lVar1 + 0x70) & 0x1f)) - 1U & uVar9)
                       * 4);
      if (uVar21 < (uVar6 >> 8 & 0xff)) {
        do {
          uVar4 = 0;
          if (uVar10 == 0) goto LAB_18004bb56;
          uVar10 = uVar10 - 1;
          uVar9 = uVar9 + ((uint)(byte)*_Src << ((byte)uVar21 & 0x1f));
          _Src = (uint *)((longlong)_Src + 1);
          uVar21 = uVar21 + 8;
          uVar6 = *(uint *)(*(longlong *)(lVar1 + 0x60) +
                           (ulonglong)
                           ((1 << ((byte)*(undefined4 *)(lVar1 + 0x70) & 0x1f)) - 1U & uVar9) * 4);
        } while (uVar21 < (uVar6 >> 8 & 0xff));
      }
      cVar5 = (char)uVar6;
      uVar15 = uVar6;
      if ((cVar5 != '\0') && ((uVar6 & 0xf0) == 0)) {
        bVar13 = (byte)(uVar6 >> 8);
        uVar15 = *(uint *)(*(longlong *)(lVar1 + 0x60) +
                          (ulonglong)
                          ((((1 << (cVar5 + bVar13 & 0x1f)) - 1U & uVar9) >> (bVar13 & 0x1f)) +
                          (uVar6 >> 0x10)) * 4);
        local_60 = uVar6;
        if (uVar21 < (uVar15 >> 8 & 0xff) + (uVar6 >> 8 & 0xff)) {
          do {
            uVar4 = 0;
            if (uVar10 == 0) goto LAB_18004bb56;
            uVar9 = uVar9 + ((uint)(byte)*_Src << ((byte)uVar21 & 0x1f));
            uVar10 = uVar10 - 1;
            _Src = (uint *)((longlong)_Src + 1);
            uVar21 = uVar21 + 8;
            uVar15 = *(uint *)(*(longlong *)(lVar1 + 0x60) +
                              (ulonglong)
                              ((((1 << (cVar5 + bVar13 & 0x1f)) - 1U & uVar9) >> (bVar13 & 0x1f)) +
                              (uVar6 >> 0x10)) * 4);
          } while (uVar21 < (uVar15 >> 8 & 0xff) + (uint)bVar13);
        }
        uVar9 = uVar9 >> (bVar13 & 0x1f);
        uVar21 = uVar21 - bVar13;
        *(uint *)(lVar1 + 0x1be4) = (uint)bVar13;
      }
      uVar6 = uVar15 >> 8 & 0xff;
      *(int *)(lVar1 + 0x1be4) = *(int *)(lVar1 + 0x1be4) + uVar6;
      uVar21 = uVar21 - uVar6;
      uVar9 = uVar9 >> ((byte)(uVar15 >> 8) & 0x1f);
      *(uint *)(lVar1 + 0x50) = uVar15 >> 0x10;
      if ((char)uVar15 != '\0') {
        if ((uVar15 & 0x20) != 0) {
          *(undefined4 *)(lVar1 + 0x1be4) = 0xffffffff;
          goto LAB_18004acc0;
        }
        if ((uVar15 & 0x40) != 0) {
          param_1[4] = (longlong)"invalid literal/length code";
          *(undefined4 *)(lVar1 + 8) = 0x3f51;
          goto LAB_18004acc8;
        }
        *(undefined4 *)(lVar1 + 8) = 0x3f49;
        *(uint *)(lVar1 + 0x58) = uVar15 & 0xf;
switchD_18004a65b_caseD_8004b680:
        uVar6 = *(uint *)(lVar1 + 0x58);
        if (uVar6 != 0) {
          for (; uVar21 < uVar6; uVar21 = uVar21 + 8) {
            uVar4 = 0;
            if (uVar10 == 0) goto LAB_18004bb56;
            uVar10 = uVar10 - 1;
            uVar9 = uVar9 + ((uint)(byte)*_Src << ((byte)uVar21 & 0x1f));
            _Src = (uint *)((longlong)_Src + 1);
          }
          uVar21 = uVar21 - uVar6;
          uVar15 = (1 << ((byte)uVar6 & 0x1f)) - 1U & uVar9;
          uVar9 = uVar9 >> ((byte)uVar6 & 0x1f);
          *(int *)(lVar1 + 0x50) = *(int *)(lVar1 + 0x50) + uVar15;
          *(int *)(lVar1 + 0x1be4) = *(int *)(lVar1 + 0x1be4) + uVar6;
        }
        *(undefined4 *)(lVar1 + 0x1be8) = *(undefined4 *)(lVar1 + 0x50);
        *(undefined4 *)(lVar1 + 8) = 0x3f4a;
switchD_18004a65b_caseD_8004b6e4:
        uVar6 = *(uint *)(*(longlong *)(lVar1 + 0x68) +
                         (ulonglong)
                         ((1 << ((byte)*(undefined4 *)(lVar1 + 0x74) & 0x1f)) - 1U & uVar9) * 4);
        if (uVar21 < (uVar6 >> 8 & 0xff)) {
          do {
            uVar4 = 0;
            if (uVar10 == 0) goto LAB_18004bb56;
            uVar10 = uVar10 - 1;
            uVar9 = uVar9 + ((uint)(byte)*_Src << ((byte)uVar21 & 0x1f));
            _Src = (uint *)((longlong)_Src + 1);
            uVar21 = uVar21 + 8;
            uVar6 = *(uint *)(*(longlong *)(lVar1 + 0x68) +
                             (ulonglong)
                             ((1 << ((byte)*(undefined4 *)(lVar1 + 0x74) & 0x1f)) - 1U & uVar9) * 4)
            ;
          } while (uVar21 < (uVar6 >> 8 & 0xff));
        }
        uVar15 = uVar6;
        if ((uVar6 & 0xf0) == 0) {
          bVar13 = (byte)(uVar6 >> 8);
          uVar15 = *(uint *)(*(longlong *)(lVar1 + 0x68) +
                            (ulonglong)
                            ((((1 << ((char)uVar6 + bVar13 & 0x1f)) - 1U & uVar9) >> (bVar13 & 0x1f)
                             ) + (uVar6 >> 0x10)) * 4);
          local_60 = uVar6;
          if (uVar21 < (uVar15 >> 8 & 0xff) + (uVar6 >> 8 & 0xff)) {
            do {
              uVar4 = 0;
              if (uVar10 == 0) goto LAB_18004bb56;
              uVar9 = uVar9 + ((uint)(byte)*_Src << ((byte)uVar21 & 0x1f));
              uVar10 = uVar10 - 1;
              _Src = (uint *)((longlong)_Src + 1);
              uVar21 = uVar21 + 8;
              uVar15 = *(uint *)(*(longlong *)(lVar1 + 0x68) +
                                (ulonglong)
                                ((((1 << ((char)uVar6 + bVar13 & 0x1f)) - 1U & uVar9) >>
                                 (bVar13 & 0x1f)) + (uVar6 >> 0x10)) * 4);
            } while (uVar21 < (uVar15 >> 8 & 0xff) + (uint)bVar13);
          }
          uVar9 = uVar9 >> (bVar13 & 0x1f);
          uVar21 = uVar21 - bVar13;
          *(int *)(lVar1 + 0x1be4) = *(int *)(lVar1 + 0x1be4) + (uint)bVar13;
        }
        uVar25 = (ulonglong)local_res20;
        uVar6 = uVar15 >> 8 & 0xff;
        *(int *)(lVar1 + 0x1be4) = *(int *)(lVar1 + 0x1be4) + uVar6;
        uVar21 = uVar21 - uVar6;
        uVar9 = uVar9 >> ((byte)(uVar15 >> 8) & 0x1f);
        puVar23 = local_58;
        if ((uVar15 & 0x40) != 0) {
          param_1[4] = (longlong)"invalid distance code";
          *(undefined4 *)(lVar1 + 8) = 0x3f51;
          break;
        }
        *(uint *)(lVar1 + 0x54) = uVar15 >> 0x10;
        *(undefined4 *)(lVar1 + 8) = 0x3f4b;
        *(uint *)(lVar1 + 0x58) = uVar15 & 0xf;
        uVar24 = local_64;
switchD_18004a65b_caseD_8004b871:
        uVar6 = *(uint *)(lVar1 + 0x58);
        if (uVar6 != 0) {
          for (; uVar21 < uVar6; uVar21 = uVar21 + 8) {
            uVar4 = 0;
            if (uVar10 == 0) goto LAB_18004bb56;
            uVar10 = uVar10 - 1;
            uVar9 = uVar9 + ((uint)(byte)*_Src << ((byte)uVar21 & 0x1f));
            _Src = (uint *)((longlong)_Src + 1);
          }
          uVar21 = uVar21 - uVar6;
          uVar15 = (1 << ((byte)uVar6 & 0x1f)) - 1U & uVar9;
          uVar9 = uVar9 >> ((byte)uVar6 & 0x1f);
          *(int *)(lVar1 + 0x54) = *(int *)(lVar1 + 0x54) + uVar15;
          *(int *)(lVar1 + 0x1be4) = *(int *)(lVar1 + 0x1be4) + uVar6;
        }
        *(undefined4 *)(lVar1 + 8) = 0x3f4c;
switchD_18004a65b_caseD_8004b8c5:
        uVar6 = (uint)uVar25;
        uVar4 = uVar10;
        if (uVar6 != 0) {
          uVar15 = *(uint *)(lVar1 + 0x54);
          if (uVar24 - uVar6 < uVar15) {
            uVar15 = uVar15 - (uVar24 - uVar6);
            if ((*(uint *)(lVar1 + 0x38) < uVar15) && (*(int *)(lVar1 + 0x1be0) != 0)) {
              param_1[4] = (longlong)"invalid distance too far back";
              *(undefined4 *)(lVar1 + 8) = 0x3f51;
              break;
            }
            uVar16 = *(uint *)(lVar1 + 0x3c);
            if (uVar16 < uVar15) {
              uVar15 = uVar15 - uVar16;
              uVar16 = *(int *)(lVar1 + 0x34) - uVar15;
            }
            else {
              uVar16 = uVar16 - uVar15;
            }
            lVar20 = (ulonglong)uVar16 + *(longlong *)(lVar1 + 0x40);
            uVar16 = *(uint *)(lVar1 + 0x50);
            if (uVar16 < uVar15) goto LAB_18004b934;
          }
          else {
            lVar20 = (longlong)puVar23 - (ulonglong)uVar15;
            uVar16 = *(uint *)(lVar1 + 0x50);
LAB_18004b934:
            uVar15 = uVar16;
            uVar16 = uVar15;
          }
          uVar18 = (ulonglong)uVar15;
          if (uVar6 < uVar15) {
            uVar18 = uVar25 & 0xffffffff;
          }
          local_res20 = uVar6 - (int)uVar18;
          uVar25 = (ulonglong)local_res20;
          lVar20 = lVar20 - (longlong)puVar23;
          *(uint *)(lVar1 + 0x50) = uVar16 - (int)uVar18;
          do {
            *puVar23 = puVar23[lVar20];
            puVar23 = puVar23 + 1;
            uVar6 = (int)uVar18 - 1;
            uVar18 = (ulonglong)uVar6;
          } while (uVar6 != 0);
          local_58 = puVar23;
          if (*(int *)(lVar1 + 0x50) == 0) {
            *(undefined4 *)(lVar1 + 8) = 0x3f48;
          }
          break;
        }
        goto LAB_18004bb56;
      }
      *(undefined4 *)(lVar1 + 8) = 0x3f4d;
      goto LAB_18004acc8;
    case 0x18004b680:
      goto switchD_18004a65b_caseD_8004b680;
    case 0x18004b6e4:
      goto switchD_18004a65b_caseD_8004b6e4;
    case 0x18004b871:
      goto switchD_18004a65b_caseD_8004b871;
    case 0x18004b8c5:
      goto switchD_18004a65b_caseD_8004b8c5;
    case 0x18004b97b:
      uVar4 = uVar10;
      if (uVar16 != 0) {
        *puVar23 = *(undefined1 *)(lVar1 + 0x50);
        puVar23 = puVar23 + 1;
        local_res20 = uVar16 - 1;
        uVar25 = (ulonglong)local_res20;
        *(undefined4 *)(lVar1 + 8) = 0x3f48;
        local_58 = puVar23;
        break;
      }
      goto LAB_18004bb56;
    case 0x18004b9a7:
      uVar6 = uVar9;
      uVar3 = uVar21;
      if (*(int *)(lVar1 + 0x10) != 0) {
        for (; uVar3 < 0x20; uVar3 = uVar3 + 8) {
          uVar4 = 0;
          uVar9 = uVar6;
          uVar21 = uVar3;
          if (uVar10 == 0) goto LAB_18004bb56;
          uVar9 = *_Src;
          uVar10 = uVar10 - 1;
          _Src = (uint *)((longlong)_Src + 1);
          uVar6 = uVar6 + ((uint)(byte)uVar9 << ((byte)uVar3 & 0x1f));
        }
        uVar24 = uVar24 - uVar16;
        *(int *)((longlong)param_1 + 0x1c) = *(int *)((longlong)param_1 + 0x1c) + uVar24;
        *(int *)(lVar1 + 0x24) = *(int *)(lVar1 + 0x24) + uVar24;
        if (((*(byte *)(lVar1 + 0x10) & 4) != 0) && (uVar24 != 0)) {
          if (*(int *)(lVar1 + 0x18) == 0) {
            uVar9 = FUN_18004dfc0(*(uint *)(lVar1 + 0x20),puVar23 + -(ulonglong)uVar24,uVar24);
          }
          else {
            uVar9 = FUN_18004c120(*(uint *)(lVar1 + 0x20),(uint *)(puVar23 + -(ulonglong)uVar24),
                                  uVar24);
          }
          uVar25 = (ulonglong)local_res20;
          *(uint *)(lVar1 + 0x20) = uVar9;
          *(uint *)((longlong)param_1 + 0x4c) = uVar9;
          puVar23 = local_58;
        }
        local_64 = (uint)uVar25;
        uVar9 = uVar15;
        uVar21 = uVar15;
        if ((*(byte *)(lVar1 + 0x10) & 4) != 0) {
          uVar16 = uVar6;
          if (*(int *)(lVar1 + 0x18) == 0) {
            uVar16 = ((uVar6 & 0xff00) + uVar6 * 0x10000) * 0x100 + (uVar6 >> 8 & 0xff00) +
                     (uVar6 >> 0x18);
          }
          if (uVar16 != *(uint *)(lVar1 + 0x20)) {
            param_1[4] = (longlong)"incorrect data check";
            *(undefined4 *)(lVar1 + 8) = 0x3f51;
            uVar9 = uVar6;
            uVar21 = uVar3;
            break;
          }
        }
      }
      *(undefined4 *)(lVar1 + 8) = 0x3f4f;
    case 0x18004ba87:
      if ((*(int *)(lVar1 + 0x10) != 0) &&
         (uVar6 = uVar9, uVar16 = uVar21, *(int *)(lVar1 + 0x18) != 0)) {
        for (; uVar16 < 0x20; uVar16 = uVar16 + 8) {
          uVar4 = 0;
          uVar9 = uVar6;
          uVar21 = uVar16;
          if (uVar10 == 0) goto LAB_18004bb56;
          uVar9 = *_Src;
          uVar10 = uVar10 - 1;
          _Src = (uint *)((longlong)_Src + 1);
          uVar6 = uVar6 + ((uint)(byte)uVar9 << ((byte)uVar16 & 0x1f));
        }
        uVar9 = uVar15;
        uVar21 = uVar15;
        if (uVar6 != *(uint *)(lVar1 + 0x24)) {
          param_1[4] = (longlong)"incorrect length check";
          *(undefined4 *)(lVar1 + 8) = 0x3f51;
          uVar9 = uVar6;
          uVar21 = uVar16;
          break;
        }
      }
      *(undefined4 *)(lVar1 + 8) = 0x3f50;
switchD_18004a65b_caseD_8004bb34:
      uVar25 = 1;
      goto LAB_18004bb5a;
    case 0x18004bb34:
      goto switchD_18004a65b_caseD_8004bb34;
    case 0x18004bb3f:
      uVar25 = 0xfffffffd;
      goto LAB_18004bb5a;
    case 0x18004bbbf:
      goto LAB_18004bafb;
    }
LAB_18004acd0:
    uVar6 = *(int *)(lVar1 + 8) - 0x3f34;
    if (0x1e < uVar6) {
      return 0xfffffffe;
    }
    uVar18 = (ulonglong)local_64;
  } while( true );
}

/* ---- FUNC 0004A5C1 FUN_18004a5c1 (5846 bytes) ---- */

ulonglong FUN_18004a5c1(undefined8 *param_1)

{
  byte bVar1;
  longlong lVar2;
  undefined8 *puVar3;
  int iVar4;
  uint uVar5;
  char cVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  char *pcVar10;
  undefined8 uVar11;
  ushort uVar12;
  ulonglong uVar13;
  int iVar14;
  uint uVar15;
  longlong lVar16;
  uint uVar17;
  uint uVar18;
  byte *unaff_RBP;
  uint uVar19;
  longlong *unaff_RDI;
  undefined2 uVar20;
  int iVar21;
  undefined1 *_Dst;
  int iVar22;
  size_t _Size;
  ulonglong uVar23;
  uint *_Src;
  uint uVar24;
  
  lVar2 = param_1[5];
  if (*(int *)(lVar2 + 8) == 0x3f3f) {
    *(undefined4 *)(lVar2 + 8) = 0x3f40;
  }
  uVar18 = *(uint *)(param_1 + 3);
  uVar13 = (ulonglong)uVar18;
  _Dst = (undefined1 *)param_1[2];
  uVar7 = *(int *)(lVar2 + 8) - 0x3f34;
  uVar9 = *(uint *)(param_1 + 1);
  _Src = (uint *)*param_1;
  uVar24 = *(uint *)(lVar2 + 0x48);
  uVar17 = *(uint *)(lVar2 + 0x4c);
  *(undefined1 **)(unaff_RBP + 7) = _Dst;
  *(uint *)(unaff_RBP + 0x7f) = uVar18;
  *(uint *)(unaff_RBP + 3) = uVar9;
  *(uint *)(unaff_RBP + -5) = uVar18;
  unaff_RBP[0x77] = 0;
  unaff_RBP[0x78] = 0;
  unaff_RBP[0x79] = 0;
  unaff_RBP[0x7a] = 0;
  uVar23 = uVar13;
  if (0x1e < uVar7) {
    return 0xfffffffe;
  }
  do {
    iVar22 = (int)uVar13;
    uVar13 = 0;
    uVar15 = 0;
    uVar18 = (uint)uVar23;
    switch((ulonglong)(&switchD_18004a65b::switchdataD_18004bca8)[(int)uVar7] + 0x180000000) {
    case 0x18004a65d:
      if (*(uint *)(lVar2 + 0x10) == 0) {
        *(undefined4 *)(lVar2 + 8) = 0x3f40;
        break;
      }
      for (; uVar17 < 0x10; uVar17 = uVar17 + 8) {
        uVar19 = 0;
        if (uVar9 == 0) goto LAB_18004bb53;
        uVar9 = uVar9 - 1;
        uVar24 = uVar24 + ((uint)(byte)*_Src << ((byte)uVar17 & 0x1f));
        _Src = (uint *)((longlong)_Src + 1);
      }
      if (((*(uint *)(lVar2 + 0x10) & 2) == 0) || (uVar24 != 0x8b1f)) {
        *(undefined4 *)(lVar2 + 0x18) = 0;
        if (*(longlong *)(lVar2 + 0x28) != 0) {
          *(undefined4 *)(*(longlong *)(lVar2 + 0x28) + 0x40) = 0xffffffff;
        }
        if (((*(byte *)(lVar2 + 0x10) & 1) == 0) ||
           (uVar18 = (uVar24 & 0xff) * 0x100 + (uVar24 >> 8), uVar18 != (uVar18 / 0x1f) * 0x1f)) {
          unaff_RDI[4] = (longlong)"incorrect header check";
          *(undefined4 *)(lVar2 + 8) = 0x3f51;
        }
        else {
          if (((byte)uVar24 & 0xf) != 8) goto LAB_18004a748;
          uVar17 = uVar17 - 4;
          uVar18 = (uVar24 >> 4 & 0xf) + 8;
          if (*(int *)(lVar2 + 0x30) == 0) {
            *(uint *)(lVar2 + 0x30) = uVar18;
          }
          if ((uVar18 < 0x10) && (uVar18 <= *(uint *)(lVar2 + 0x30))) {
            *(int *)(lVar2 + 0x1c) = 1 << (sbyte)uVar18;
            uVar18 = FUN_18004dfc0(0,(byte *)0x0,0);
            uVar17 = 0;
            *(uint *)(lVar2 + 0x20) = uVar18;
            *(uint *)((longlong)unaff_RDI + 0x4c) = uVar18;
            *(uint *)(lVar2 + 8) = ~(uVar24 >> 0xc) & 2 | 0x3f3d;
            uVar24 = 0;
            goto LAB_18004acc8;
          }
          unaff_RDI[4] = (longlong)"invalid window size";
          *(undefined4 *)(lVar2 + 8) = 0x3f51;
          uVar24 = uVar24 >> 4;
        }
        break;
      }
      if (*(int *)(lVar2 + 0x30) == 0) {
        *(undefined4 *)(lVar2 + 0x30) = 0xf;
      }
      uVar8 = FUN_18004c120(0,(uint *)0x0,0);
      *(undefined4 *)(lVar2 + 0x20) = uVar8;
      unaff_RBP[-9] = 0x1f;
      unaff_RBP[-8] = 0x8b;
      uVar8 = FUN_18004c120(*(uint *)(lVar2 + 0x20),(uint *)(unaff_RBP + -9),2);
      *(undefined4 *)(lVar2 + 0x20) = uVar8;
      uVar24 = 0;
      uVar17 = 0;
      *(undefined4 *)(lVar2 + 8) = 0x3f35;
      goto LAB_18004acc8;
    case 0x18004a7f5:
      for (; uVar17 < 0x10; uVar17 = uVar17 + 8) {
        if (uVar9 == 0) {
          uVar23 = (ulonglong)*(uint *)(unaff_RBP + 0x77);
          iVar22 = *(int *)(unaff_RBP + 0x6f);
          uVar9 = 0;
          goto LAB_18004bb5a;
        }
        uVar9 = uVar9 - 1;
        uVar24 = uVar24 + ((uint)(byte)*_Src << ((byte)uVar17 & 0x1f));
        _Src = (uint *)((longlong)_Src + 1);
      }
      *(uint *)(lVar2 + 0x18) = uVar24;
      if ((char)uVar24 == '\b') {
        if ((uVar24 & 0xe000) == 0) {
          if (*(uint **)(lVar2 + 0x28) != (uint *)0x0) {
            **(uint **)(lVar2 + 0x28) = uVar24 >> 8 & 1;
          }
          if (((*(uint *)(lVar2 + 0x18) & 0x200) != 0) && ((*(byte *)(lVar2 + 0x10) & 4) != 0)) {
            unaff_RBP[-9] = 8;
            unaff_RBP[-8] = (byte)(uVar24 >> 8);
            uVar8 = FUN_18004c120(*(uint *)(lVar2 + 0x20),(uint *)(unaff_RBP + -9),2);
            *(undefined4 *)(lVar2 + 0x20) = uVar8;
          }
          *(undefined4 *)(lVar2 + 8) = 0x3f36;
          uVar24 = uVar15;
          uVar17 = uVar15;
          do {
            uVar19 = 0;
            if (uVar9 == 0) goto LAB_18004bb53;
            uVar9 = uVar9 - 1;
            uVar24 = uVar24 + ((uint)(byte)*_Src << ((byte)uVar17 & 0x1f));
            _Src = (uint *)((longlong)_Src + 1);
            uVar17 = uVar17 + 8;
joined_r0x00018004a8aa:
          } while (uVar17 < 0x20);
          if (*(longlong *)(lVar2 + 0x28) != 0) {
            *(uint *)(*(longlong *)(lVar2 + 0x28) + 4) = uVar24;
          }
          if (((*(uint *)(lVar2 + 0x18) & 0x200) != 0) && ((*(byte *)(lVar2 + 0x10) & 4) != 0)) {
            unaff_RBP[-9] = (byte)uVar24;
            unaff_RBP[-8] = (byte)(uVar24 >> 8);
            unaff_RBP[-7] = (byte)(uVar24 >> 0x10);
            unaff_RBP[-6] = (byte)(uVar24 >> 0x18);
            uVar8 = FUN_18004c120(*(uint *)(lVar2 + 0x20),(uint *)(unaff_RBP + -9),4);
            *(undefined4 *)(lVar2 + 0x20) = uVar8;
          }
          *(undefined4 *)(lVar2 + 8) = 0x3f37;
          uVar24 = uVar15;
          uVar17 = uVar15;
          do {
            uVar19 = 0;
            if (uVar9 == 0) goto LAB_18004bb53;
            uVar9 = uVar9 - 1;
            uVar24 = uVar24 + ((uint)(byte)*_Src << ((byte)uVar17 & 0x1f));
            _Src = (uint *)((longlong)_Src + 1);
            uVar17 = uVar17 + 8;
joined_r0x00018004a936:
          } while (uVar17 < 0x10);
          if (*(longlong *)(lVar2 + 0x28) != 0) {
            *(uint *)(*(longlong *)(lVar2 + 0x28) + 8) = uVar24 & 0xff;
            *(uint *)(*(longlong *)(lVar2 + 0x28) + 0xc) = uVar24 >> 8;
          }
          if (((*(uint *)(lVar2 + 0x18) & 0x200) != 0) && ((*(byte *)(lVar2 + 0x10) & 4) != 0)) {
            unaff_RBP[-9] = (byte)uVar24;
            unaff_RBP[-8] = (byte)(uVar24 >> 8);
            uVar8 = FUN_18004c120(*(uint *)(lVar2 + 0x20),(uint *)(unaff_RBP + -9),2);
            *(undefined4 *)(lVar2 + 0x20) = uVar8;
          }
          *(undefined4 *)(lVar2 + 8) = 0x3f38;
          uVar24 = uVar15;
          uVar17 = uVar15;
          goto switchD_18004a65b_caseD_8004a9b7;
        }
        unaff_RDI[4] = (longlong)"unknown header flags set";
        *(undefined4 *)(lVar2 + 8) = 0x3f51;
      }
      else {
LAB_18004a748:
        unaff_RDI[4] = (longlong)"unknown compression method";
        *(undefined4 *)(lVar2 + 8) = 0x3f51;
      }
      break;
    case 0x18004a8a7:
      goto joined_r0x00018004a8aa;
    case 0x18004a933:
      goto joined_r0x00018004a936;
    case 0x18004a9b7:
switchD_18004a65b_caseD_8004a9b7:
      if ((*(uint *)(lVar2 + 0x18) & 0x400) == 0) {
        uVar15 = uVar24;
        if (*(longlong *)(lVar2 + 0x28) != 0) {
          *(undefined8 *)(*(longlong *)(lVar2 + 0x28) + 0x10) = 0;
        }
      }
      else {
        for (; uVar17 < 0x10; uVar17 = uVar17 + 8) {
          uVar19 = 0;
          if (uVar9 == 0) goto LAB_18004bb53;
          uVar9 = uVar9 - 1;
          uVar24 = uVar24 + ((uint)(byte)*_Src << ((byte)uVar17 & 0x1f));
          _Src = (uint *)((longlong)_Src + 1);
        }
        *(uint *)(lVar2 + 0x50) = uVar24;
        if (*(longlong *)(lVar2 + 0x28) != 0) {
          *(uint *)(*(longlong *)(lVar2 + 0x28) + 0x18) = uVar24;
        }
        uVar17 = uVar15;
        if (((*(uint *)(lVar2 + 0x18) & 0x200) != 0) && ((*(byte *)(lVar2 + 0x10) & 4) != 0)) {
          unaff_RBP[-9] = (byte)uVar24;
          unaff_RBP[-8] = (byte)(uVar24 >> 8);
          uVar8 = FUN_18004c120(*(uint *)(lVar2 + 0x20),(uint *)(unaff_RBP + -9),2);
          *(undefined4 *)(lVar2 + 0x20) = uVar8;
        }
      }
      uVar24 = uVar15;
      *(undefined4 *)(lVar2 + 8) = 0x3f39;
    case 0x18004aa48:
      if ((*(uint *)(lVar2 + 0x18) & 0x400) == 0) {
LAB_18004aad6:
        *(undefined4 *)(lVar2 + 0x50) = 0;
        *(undefined4 *)(lVar2 + 8) = 0x3f3a;
switchD_18004a65b_caseD_8004aae2:
        if ((*(uint *)(lVar2 + 0x18) & 0x800) == 0) {
          if (*(longlong *)(lVar2 + 0x28) != 0) {
            *(undefined8 *)(*(longlong *)(lVar2 + 0x28) + 0x20) = 0;
          }
LAB_18004ab7b:
          *(undefined4 *)(lVar2 + 0x50) = 0;
          *(undefined4 *)(lVar2 + 8) = 0x3f3b;
switchD_18004a65b_caseD_8004ab87:
          uVar23 = 0;
          if ((*(uint *)(lVar2 + 0x18) & 0x1000) == 0) {
            if (*(longlong *)(lVar2 + 0x28) != 0) {
              *(undefined8 *)(*(longlong *)(lVar2 + 0x28) + 0x30) = 0;
            }
LAB_18004ac1b:
            unaff_RDI = *(longlong **)(unaff_RBP + 0x67);
            _Dst = *(undefined1 **)(unaff_RBP + 7);
            uVar23 = (ulonglong)*(uint *)(unaff_RBP + 0x7f);
            *(undefined4 *)(lVar2 + 8) = 0x3f3c;
switchD_18004a65b_caseD_8004ac2f:
            if ((*(uint *)(lVar2 + 0x18) & 0x200) != 0) {
              for (; uVar17 < 0x10; uVar17 = uVar17 + 8) {
                uVar19 = 0;
                if (uVar9 == 0) goto LAB_18004bb53;
                uVar9 = uVar9 - 1;
                uVar24 = uVar24 + ((uint)(byte)*_Src << ((byte)uVar17 & 0x1f));
                _Src = (uint *)((longlong)_Src + 1);
              }
              if (((*(byte *)(lVar2 + 0x10) & 4) != 0) && (uVar24 != *(ushort *)(lVar2 + 0x20))) {
                unaff_RDI[4] = (longlong)"header crc mismatch";
                *(undefined4 *)(lVar2 + 8) = 0x3f51;
                break;
              }
              uVar24 = 0;
              uVar17 = uVar24;
            }
            if (*(longlong *)(lVar2 + 0x28) != 0) {
              *(uint *)(*(longlong *)(lVar2 + 0x28) + 0x3c) = *(int *)(lVar2 + 0x18) >> 9 & 1;
              *(undefined4 *)(*(longlong *)(lVar2 + 0x28) + 0x40) = 1;
            }
            uVar8 = FUN_18004c120(0,(uint *)0x0,0);
            *(undefined4 *)(lVar2 + 0x20) = uVar8;
            *(undefined4 *)((longlong)unaff_RDI + 0x4c) = uVar8;
LAB_18004acc0:
            *(undefined4 *)(lVar2 + 8) = 0x3f3f;
LAB_18004acc8:
            uVar23 = (ulonglong)*(uint *)(unaff_RBP + 0x7f);
            goto LAB_18004accc;
          }
          uVar19 = uVar9;
          if (uVar9 != 0) {
            do {
              uVar18 = (int)uVar23 + 1;
              cVar6 = *(char *)(uVar23 + (longlong)_Src);
              lVar16 = *(longlong *)(lVar2 + 0x28);
              if (((lVar16 != 0) && (*(longlong *)(lVar16 + 0x30) != 0)) &&
                 (*(uint *)(lVar2 + 0x50) < *(uint *)(lVar16 + 0x38))) {
                *(char *)((ulonglong)*(uint *)(lVar2 + 0x50) + *(longlong *)(lVar16 + 0x30)) = cVar6
                ;
                *(int *)(lVar2 + 0x50) = *(int *)(lVar2 + 0x50) + 1;
              }
            } while ((cVar6 != '\0') && (uVar23 = (ulonglong)uVar18, uVar18 < uVar9));
            if (((*(uint *)(lVar2 + 0x18) & 0x200) != 0) && ((*(byte *)(lVar2 + 0x10) & 4) != 0)) {
              uVar8 = FUN_18004c120(*(uint *)(lVar2 + 0x20),_Src,uVar18);
              *(undefined4 *)(lVar2 + 0x20) = uVar8;
            }
            uVar9 = uVar9 - uVar18;
            _Src = (uint *)((longlong)_Src + (ulonglong)uVar18);
            uVar19 = uVar9;
            if (cVar6 == '\0') goto LAB_18004ac1b;
          }
        }
        else {
          uVar19 = uVar9;
          if (uVar9 != 0) {
            do {
              uVar18 = (int)uVar13 + 1;
              cVar6 = *(char *)(uVar13 + (longlong)_Src);
              lVar16 = *(longlong *)(lVar2 + 0x28);
              if (((lVar16 != 0) && (*(longlong *)(lVar16 + 0x20) != 0)) &&
                 (*(uint *)(lVar2 + 0x50) < *(uint *)(lVar16 + 0x28))) {
                *(char *)((ulonglong)*(uint *)(lVar2 + 0x50) + *(longlong *)(lVar16 + 0x20)) = cVar6
                ;
                *(int *)(lVar2 + 0x50) = *(int *)(lVar2 + 0x50) + 1;
              }
            } while ((cVar6 != '\0') && (uVar13 = (ulonglong)uVar18, uVar18 < uVar9));
            if (((*(uint *)(lVar2 + 0x18) & 0x200) != 0) && ((*(byte *)(lVar2 + 0x10) & 4) != 0)) {
              uVar8 = FUN_18004c120(*(uint *)(lVar2 + 0x20),_Src,uVar18);
              *(undefined4 *)(lVar2 + 0x20) = uVar8;
            }
            uVar19 = uVar9 - uVar18;
            _Src = (uint *)((longlong)_Src + (ulonglong)uVar18);
            uVar9 = uVar19;
            if (cVar6 == '\0') goto LAB_18004ab7b;
          }
        }
      }
      else {
        uVar18 = *(uint *)(lVar2 + 0x50);
        uVar7 = uVar18;
        if (uVar9 < uVar18) {
          uVar7 = uVar9;
        }
        uVar19 = uVar9;
        if (uVar7 != 0) {
          lVar16 = *(longlong *)(lVar2 + 0x28);
          if ((lVar16 != 0) && (*(longlong *)(lVar16 + 0x10) != 0)) {
            uVar18 = *(int *)(lVar16 + 0x18) - uVar18;
            uVar15 = uVar7;
            if (*(uint *)(lVar16 + 0x1c) < uVar7 + uVar18) {
              uVar15 = *(uint *)(lVar16 + 0x1c) - uVar18;
            }
            memcpy((void *)((ulonglong)uVar18 + *(longlong *)(lVar16 + 0x10)),_Src,(ulonglong)uVar15
                  );
          }
          if (((*(uint *)(lVar2 + 0x18) & 0x200) != 0) && ((*(byte *)(lVar2 + 0x10) & 4) != 0)) {
            uVar8 = FUN_18004c120(*(uint *)(lVar2 + 0x20),_Src,uVar7);
            *(undefined4 *)(lVar2 + 0x20) = uVar8;
          }
          uVar19 = uVar9 - uVar7;
          _Src = (uint *)((longlong)_Src + (ulonglong)uVar7);
          *(int *)(lVar2 + 0x50) = *(int *)(lVar2 + 0x50) - uVar7;
        }
        uVar9 = uVar19;
        if (*(int *)(lVar2 + 0x50) == 0) goto LAB_18004aad6;
      }
LAB_18004bb53:
      iVar22 = *(int *)(unaff_RBP + 0x6f);
      uVar9 = uVar19;
LAB_18004bb56:
      uVar23 = (ulonglong)*(uint *)(unaff_RBP + 0x77);
LAB_18004bb5a:
      puVar3 = *(undefined8 **)(unaff_RBP + 0x67);
      puVar3[2] = *(undefined8 *)(unaff_RBP + 7);
      *(undefined4 *)(puVar3 + 3) = *(undefined4 *)(unaff_RBP + 0x7f);
      *puVar3 = _Src;
      *(uint *)(puVar3 + 1) = uVar9;
      *(uint *)(lVar2 + 0x4c) = uVar17;
      iVar14 = *(int *)(unaff_RBP + -5);
      *(uint *)(lVar2 + 0x48) = uVar24;
      if (((*(int *)(lVar2 + 0x34) == 0) &&
          (((iVar14 == *(int *)(puVar3 + 3) || (0x3f50 < *(int *)(lVar2 + 8))) ||
           ((0x3f4d < *(int *)(lVar2 + 8) && (iVar22 == 4)))))) ||
         (uVar11 = FUN_18004c020((longlong)puVar3,puVar3[2],iVar14 - *(int *)(puVar3 + 3)),
         (int)uVar11 == 0)) {
        uVar18 = iVar14 - *(int *)(puVar3 + 3);
        iVar22 = *(int *)(unaff_RBP + 3) - *(int *)(puVar3 + 1);
        *(int *)((longlong)puVar3 + 0xc) = *(int *)((longlong)puVar3 + 0xc) + iVar22;
        *(int *)((longlong)puVar3 + 0x1c) = *(int *)((longlong)puVar3 + 0x1c) + uVar18;
        *(int *)(lVar2 + 0x24) = *(int *)(lVar2 + 0x24) + uVar18;
        bVar1 = *(byte *)(lVar2 + 0x10);
        *(int *)(unaff_RBP + 3) = iVar22;
        if (((bVar1 & 4) != 0) && (uVar18 != 0)) {
          if (*(int *)(lVar2 + 0x18) == 0) {
            uVar9 = FUN_18004dfc0(*(uint *)(lVar2 + 0x20),(byte *)(puVar3[2] - (ulonglong)uVar18),
                                  uVar18);
          }
          else {
            uVar9 = FUN_18004c120(*(uint *)(lVar2 + 0x20),(uint *)(puVar3[2] - (ulonglong)uVar18),
                                  uVar18);
          }
          iVar22 = *(int *)(unaff_RBP + 3);
          *(uint *)(lVar2 + 0x20) = uVar9;
          *(uint *)((longlong)puVar3 + 0x4c) = uVar9;
        }
        iVar14 = *(int *)(lVar2 + 8);
        if ((iVar14 == 0x3f47) || (iVar14 == 0x3f42)) {
          iVar21 = 0x100;
        }
        else {
          iVar21 = 0;
        }
        iVar4 = 0;
        if (iVar14 == 0x3f3f) {
          iVar4 = 0x80;
        }
        *(uint *)(puVar3 + 9) =
             iVar4 + iVar21 + (-(uint)(*(int *)(lVar2 + 0xc) != 0) & 0x40) + *(int *)(lVar2 + 0x4c);
        if (((iVar22 != 0) || (uVar18 != 0)) && (*(int *)(unaff_RBP + 0x6f) != 4)) {
          return uVar23;
        }
        if ((int)uVar23 == 0) {
          return 0xfffffffb;
        }
        return uVar23;
      }
      *(undefined4 *)(lVar2 + 8) = 0x3f52;
LAB_18004bafb:
      return 0xfffffffc;
    case 0x18004aae2:
      goto switchD_18004a65b_caseD_8004aae2;
    case 0x18004ab87:
      goto switchD_18004a65b_caseD_8004ab87;
    case 0x18004ac2f:
      goto switchD_18004a65b_caseD_8004ac2f;
    case 0x18004acee:
      for (; uVar17 < 0x20; uVar17 = uVar17 + 8) {
        uVar19 = 0;
        if (uVar9 == 0) goto LAB_18004bb53;
        uVar9 = uVar9 - 1;
        uVar24 = uVar24 + ((uint)(byte)*_Src << ((byte)uVar17 & 0x1f));
        _Src = (uint *)((longlong)_Src + 1);
      }
      iVar22 = (uVar24 >> 8 & 0xff00) + ((uVar24 & 0xff00) + uVar24 * 0x10000) * 0x100 +
               (uVar24 >> 0x18);
      *(int *)(lVar2 + 0x20) = iVar22;
      *(int *)((longlong)unaff_RDI + 0x4c) = iVar22;
      *(undefined4 *)(lVar2 + 8) = 0x3f3e;
      uVar24 = uVar15;
      uVar17 = uVar15;
    case 0x18004ad50:
      if (*(int *)(lVar2 + 0x14) == 0) {
        unaff_RDI[2] = (longlong)_Dst;
        *(uint *)(unaff_RDI + 3) = uVar18;
        *unaff_RDI = (longlong)_Src;
        *(uint *)(unaff_RDI + 1) = uVar9;
        *(uint *)(lVar2 + 0x48) = uVar24;
        *(uint *)(lVar2 + 0x4c) = uVar17;
        return 2;
      }
      uVar18 = FUN_18004dfc0(0,(byte *)0x0,0);
      _Dst = *(undefined1 **)(unaff_RBP + 7);
      uVar23 = (ulonglong)*(uint *)(unaff_RBP + 0x7f);
      *(uint *)(lVar2 + 0x20) = uVar18;
      *(uint *)((longlong)unaff_RDI + 0x4c) = uVar18;
      *(undefined4 *)(lVar2 + 8) = 0x3f3f;
switchD_18004a65b_caseD_8004ad7e:
      uVar19 = uVar9;
      if (*(int *)(unaff_RBP + 0x6f) - 5U < 2) goto LAB_18004bb53;
switchD_18004a65b_caseD_8004ad8d:
      if (*(int *)(lVar2 + 0xc) != 0) {
        *(undefined4 *)(lVar2 + 8) = 0x3f4e;
        uVar18 = uVar17 & 7;
        uVar17 = uVar17 - uVar18;
        uVar24 = uVar24 >> (sbyte)uVar18;
        break;
      }
      for (; uVar17 < 3; uVar17 = uVar17 + 8) {
        uVar19 = 0;
        if (uVar9 == 0) goto LAB_18004bb53;
        uVar9 = uVar9 - 1;
        uVar24 = uVar24 + ((uint)(byte)*_Src << ((byte)uVar17 & 0x1f));
        _Src = (uint *)((longlong)_Src + 1);
      }
      *(uint *)(lVar2 + 0xc) = uVar24 & 1;
      uVar18 = uVar24 >> 1 & 3;
      if (uVar18 == 0) {
        *(undefined4 *)(lVar2 + 8) = 0x3f41;
LAB_18004ae55:
        uVar17 = uVar17 - 3;
        uVar24 = uVar24 >> 3;
        break;
      }
      if (uVar18 != 1) {
        if (uVar18 == 2) {
          uVar17 = uVar17 - 3;
          *(undefined4 *)(lVar2 + 8) = 0x3f44;
          uVar24 = uVar24 >> 3;
        }
        else {
          if (uVar18 != 3) goto LAB_18004ae55;
          unaff_RDI[4] = (longlong)"invalid block type";
          uVar17 = uVar17 - 3;
          *(undefined4 *)(lVar2 + 8) = 0x3f51;
          uVar24 = uVar24 >> 3;
        }
        break;
      }
      FUN_18004a550(lVar2);
      iVar22 = *(int *)(unaff_RBP + 0x6f);
      *(undefined4 *)(lVar2 + 8) = 0x3f47;
      if (iVar22 != 6) goto LAB_18004ae55;
      uVar24 = uVar24 >> 3;
      uVar17 = uVar17 - 3;
      iVar22 = 6;
      goto LAB_18004bb56;
    case 0x18004ad7e:
      goto switchD_18004a65b_caseD_8004ad7e;
    case 0x18004ad8d:
      goto switchD_18004a65b_caseD_8004ad8d;
    case 0x18004ae61:
      uVar24 = uVar24 >> (sbyte)(uVar17 & 7);
      for (uVar17 = uVar17 - (uVar17 & 7); uVar17 < 0x20; uVar17 = uVar17 + 8) {
        uVar19 = 0;
        if (uVar9 == 0) goto LAB_18004bb53;
        uVar9 = uVar9 - 1;
        uVar24 = uVar24 + ((uint)(byte)*_Src << ((byte)uVar17 & 0x1f));
        _Src = (uint *)((longlong)_Src + 1);
      }
      if ((uVar24 & 0xffff) != ~uVar24 >> 0x10) {
        unaff_RDI[4] = (longlong)"invalid stored block lengths";
        *(undefined4 *)(lVar2 + 8) = 0x3f51;
        break;
      }
      *(uint *)(lVar2 + 0x50) = uVar24 & 0xffff;
      iVar22 = *(int *)(unaff_RBP + 0x6f);
      *(undefined4 *)(lVar2 + 8) = 0x3f42;
      uVar24 = uVar15;
      uVar17 = uVar15;
      if (iVar22 != 6) goto switchD_18004a65b_caseD_8004aed6;
      goto LAB_18004bb56;
    case 0x18004aed6:
switchD_18004a65b_caseD_8004aed6:
      *(undefined4 *)(lVar2 + 8) = 0x3f43;
    case 0x18004aede:
      uVar7 = *(uint *)(lVar2 + 0x50);
      if (uVar7 == 0) {
        *(undefined4 *)(lVar2 + 8) = 0x3f3f;
        break;
      }
      if (uVar9 < uVar7) {
        uVar7 = uVar9;
      }
      _Size = (size_t)uVar7;
      if (uVar18 < uVar7) {
        _Size = uVar23 & 0xffffffff;
      }
      iVar22 = (int)_Size;
      uVar19 = uVar9;
      if (iVar22 != 0) {
        memcpy(_Dst,_Src,_Size);
        _Src = (uint *)((longlong)_Src + _Size);
        uVar23 = (ulonglong)(uint)(*(int *)(unaff_RBP + 0x7f) - iVar22);
        _Dst = (undefined1 *)(*(longlong *)(unaff_RBP + 7) + _Size);
        *(int *)(unaff_RBP + 0x7f) = *(int *)(unaff_RBP + 0x7f) - iVar22;
        unaff_RDI = *(longlong **)(unaff_RBP + 0x67);
        uVar9 = uVar9 - iVar22;
        *(int *)(lVar2 + 0x50) = *(int *)(lVar2 + 0x50) - iVar22;
        *(undefined1 **)(unaff_RBP + 7) = _Dst;
        break;
      }
      goto LAB_18004bb53;
    case 0x18004af45:
      for (; uVar17 < 0xe; uVar17 = uVar17 + 8) {
        uVar19 = 0;
        if (uVar9 == 0) goto LAB_18004bb53;
        uVar9 = uVar9 - 1;
        uVar24 = uVar24 + ((uint)(byte)*_Src << ((byte)uVar17 & 0x1f));
        _Src = (uint *)((longlong)_Src + 1);
      }
      uVar17 = uVar17 - 0xe;
      uVar7 = uVar24 >> 5;
      uVar18 = (uVar24 & 0x1f) + 0x101;
      uVar15 = uVar24 >> 10;
      *(uint *)(lVar2 + 0x7c) = uVar18;
      uVar24 = uVar24 >> 0xe;
      uVar7 = (uVar7 & 0x1f) + 1;
      *(uint *)(lVar2 + 0x80) = uVar7;
      *(uint *)(lVar2 + 0x78) = (uVar15 & 0xf) + 4;
      if ((uVar18 < 0x11f) && (uVar7 < 0x1f)) {
        *(undefined4 *)(lVar2 + 0x84) = 0;
        *(undefined4 *)(lVar2 + 8) = 0x3f45;
        goto switchD_18004a65b_caseD_8004afcf;
      }
      unaff_RDI[4] = (longlong)"too many length or distance symbols";
      *(undefined4 *)(lVar2 + 8) = 0x3f51;
      break;
    case 0x18004afcf:
switchD_18004a65b_caseD_8004afcf:
      if (*(uint *)(lVar2 + 0x84) < *(uint *)(lVar2 + 0x78)) {
        do {
          for (; uVar17 < 3; uVar17 = uVar17 + 8) {
            uVar19 = 0;
            if (uVar9 == 0) goto LAB_18004bb53;
            uVar9 = uVar9 - 1;
            uVar24 = uVar24 + ((uint)(byte)*_Src << ((byte)uVar17 & 0x1f));
            _Src = (uint *)((longlong)_Src + 1);
          }
          uVar12 = (ushort)uVar24;
          uVar24 = uVar24 >> 3;
          uVar17 = uVar17 - 3;
          *(ushort *)
           (lVar2 + 0x90 +
           (ulonglong)*(ushort *)(&DAT_180058530 + (ulonglong)*(uint *)(lVar2 + 0x84) * 2) * 2) =
               uVar12 & 7;
          *(int *)(lVar2 + 0x84) = *(int *)(lVar2 + 0x84) + 1;
        } while (*(uint *)(lVar2 + 0x84) < *(uint *)(lVar2 + 0x78));
      }
      uVar18 = *(uint *)(lVar2 + 0x84);
      while (uVar18 < 0x13) {
        *(undefined2 *)
         (lVar2 + 0x90 +
         (ulonglong)*(ushort *)(&DAT_180058530 + (ulonglong)*(uint *)(lVar2 + 0x84) * 2) * 2) = 0;
        *(int *)(lVar2 + 0x84) = *(int *)(lVar2 + 0x84) + 1;
        uVar18 = *(uint *)(lVar2 + 0x84);
      }
      *(uint *)(lVar2 + 0x70) = 7;
      *(longlong *)(lVar2 + 0x60) = lVar2 + 0x550;
      *(longlong *)(lVar2 + 0x88) = lVar2 + 0x550;
      uVar11 = FUN_18004e5b0(0,(ushort *)(lVar2 + 0x90),0x13,(longlong *)(lVar2 + 0x88),
                             (uint *)(lVar2 + 0x70),(undefined *)(lVar2 + 0x310));
      uVar23 = (ulonglong)*(uint *)(unaff_RBP + 0x7f);
      *(int *)(unaff_RBP + 0x77) = (int)uVar11;
      if ((int)uVar11 == 0) {
        *(undefined4 *)(lVar2 + 0x84) = 0;
        *(undefined4 *)(lVar2 + 8) = 0x3f46;
        goto switchD_18004a65b_caseD_8004b106;
      }
      unaff_RDI[4] = (longlong)"invalid code lengths set";
      *(undefined4 *)(lVar2 + 8) = 0x3f51;
      goto LAB_18004accc;
    case 0x18004b106:
switchD_18004a65b_caseD_8004b106:
      if (*(uint *)(lVar2 + 0x84) < (uint)(*(int *)(lVar2 + 0x80) + *(int *)(lVar2 + 0x7c))) {
        do {
          uVar18 = *(uint *)(*(longlong *)(lVar2 + 0x60) +
                            (ulonglong)
                            ((1 << ((byte)*(undefined4 *)(lVar2 + 0x70) & 0x1f)) - 1U & uVar24) * 4)
          ;
          *(uint *)(unaff_RBP + -1) = uVar18;
          if (uVar17 < (uVar18 >> 8 & 0xff)) {
            do {
              uVar19 = 0;
              if (uVar9 == 0) goto LAB_18004bb53;
              uVar9 = uVar9 - 1;
              uVar24 = uVar24 + ((uint)(byte)*_Src << ((byte)uVar17 & 0x1f));
              _Src = (uint *)((longlong)_Src + 1);
              uVar17 = uVar17 + 8;
              uVar18 = *(uint *)(*(longlong *)(lVar2 + 0x60) +
                                (ulonglong)
                                ((1 << ((byte)*(undefined4 *)(lVar2 + 0x70) & 0x1f)) - 1U & uVar24)
                                * 4);
              *(uint *)(unaff_RBP + -1) = uVar18;
            } while (uVar17 < (uVar18 >> 8 & 0xff));
          }
          uVar12 = (ushort)(uVar18 >> 0x10);
          if (0xf < uVar12) {
            if (uVar12 == 0x10) {
              for (; uVar17 < (uVar18 >> 8 & 0xff) + 2; uVar17 = uVar17 + 8) {
                uVar19 = 0;
                if (uVar9 == 0) goto LAB_18004bb53;
                uVar9 = uVar9 - 1;
                uVar24 = uVar24 + ((uint)(byte)*_Src << ((byte)uVar17 & 0x1f));
                _Src = (uint *)((longlong)_Src + 1);
              }
              uVar17 = uVar17 - *unaff_RBP;
              uVar24 = uVar24 >> (*unaff_RBP & 0x1f);
              if (*(int *)(lVar2 + 0x84) != 0) {
                uVar18 = uVar24 & 3;
                uVar24 = uVar24 >> 2;
                iVar14 = uVar18 + 3;
                uVar17 = uVar17 - 2;
                uVar20 = *(undefined2 *)(lVar2 + 0x90 + (ulonglong)(*(int *)(lVar2 + 0x84) - 1) * 2)
                ;
                goto LAB_18004b2d0;
              }
            }
            else {
              bVar1 = *unaff_RBP;
              if (*(short *)(unaff_RBP + 1) == 0x11) {
                for (; uVar17 < bVar1 + 3; uVar17 = uVar17 + 8) {
                  uVar19 = 0;
                  if (uVar9 == 0) goto LAB_18004bb53;
                  uVar9 = uVar9 - 1;
                  uVar24 = uVar24 + ((uint)(byte)*_Src << ((byte)uVar17 & 0x1f));
                  _Src = (uint *)((longlong)_Src + 1);
                }
                iVar22 = -3;
                uVar24 = uVar24 >> (bVar1 & 0x1f);
                iVar14 = (uVar24 & 7) + 3;
                uVar24 = uVar24 >> 3;
              }
              else {
                for (; uVar17 < bVar1 + 7; uVar17 = uVar17 + 8) {
                  uVar19 = 0;
                  if (uVar9 == 0) goto LAB_18004bb53;
                  uVar9 = uVar9 - 1;
                  uVar24 = uVar24 + ((uint)(byte)*_Src << ((byte)uVar17 & 0x1f));
                  _Src = (uint *)((longlong)_Src + 1);
                }
                iVar22 = -7;
                uVar24 = uVar24 >> (bVar1 & 0x1f);
                iVar14 = (uVar24 & 0x7f) + 0xb;
                uVar24 = uVar24 >> 7;
              }
              uVar17 = uVar17 + (iVar22 - (uint)bVar1);
              uVar20 = 0;
LAB_18004b2d0:
              if ((uint)(*(int *)(lVar2 + 0x84) + iVar14) <=
                  (uint)(*(int *)(lVar2 + 0x80) + *(int *)(lVar2 + 0x7c))) {
                do {
                  *(undefined2 *)(lVar2 + 0x90 + (ulonglong)*(uint *)(lVar2 + 0x84) * 2) = uVar20;
                  *(int *)(lVar2 + 0x84) = *(int *)(lVar2 + 0x84) + 1;
                  uVar18 = *(uint *)(lVar2 + 0x84);
                  iVar14 = iVar14 + -1;
                } while (iVar14 != 0);
                goto LAB_18004b317;
              }
            }
            unaff_RDI[4] = (longlong)"invalid bit length repeat";
            *(undefined4 *)(lVar2 + 8) = 0x3f51;
            goto LAB_18004accc;
          }
          uVar17 = uVar17 - (uVar18 >> 8 & 0xff);
          uVar24 = uVar24 >> ((byte)(uVar18 >> 8) & 0x1f);
          *(ushort *)(lVar2 + 0x90 + (ulonglong)*(uint *)(lVar2 + 0x84) * 2) = uVar12;
          *(int *)(lVar2 + 0x84) = *(int *)(lVar2 + 0x84) + 1;
          uVar18 = *(uint *)(lVar2 + 0x84);
LAB_18004b317:
        } while (uVar18 < (uint)(*(int *)(lVar2 + 0x80) + *(int *)(lVar2 + 0x7c)));
      }
      if (*(int *)(lVar2 + 8) != 0x3f51) {
        if (*(short *)(lVar2 + 0x290) != 0) {
          *(uint *)(lVar2 + 0x70) = 9;
          *(longlong *)(lVar2 + 0x88) = lVar2 + 0x550;
          *(longlong *)(lVar2 + 0x60) = lVar2 + 0x550;
          uVar11 = FUN_18004e5b0(1,(ushort *)(lVar2 + 0x90),*(uint *)(lVar2 + 0x7c),
                                 (longlong *)(lVar2 + 0x88),(uint *)(lVar2 + 0x70),
                                 (undefined *)(lVar2 + 0x310));
          *(int *)(unaff_RBP + 0x77) = (int)uVar11;
          if ((int)uVar11 == 0) {
            *(undefined8 *)(lVar2 + 0x68) = *(undefined8 *)(lVar2 + 0x88);
            *(uint *)(lVar2 + 0x74) = 6;
            uVar13 = FUN_18004e5b0(2,(ushort *)
                                     ((ulonglong)*(uint *)(lVar2 + 0x7c) * 2 + 0x90 + lVar2),
                                   *(uint *)(lVar2 + 0x80),(longlong *)(lVar2 + 0x88),
                                   (uint *)(lVar2 + 0x74),(undefined *)(lVar2 + 0x310));
            *(int *)(unaff_RBP + 0x77) = (int)uVar13;
            uVar23 = uVar13 & 0xffffffff;
            if ((int)uVar13 == 0) {
              iVar22 = *(int *)(unaff_RBP + 0x6f);
              *(undefined4 *)(lVar2 + 8) = 0x3f47;
              if (iVar22 != 6) {
                unaff_RDI = *(longlong **)(unaff_RBP + 0x67);
                _Dst = *(undefined1 **)(unaff_RBP + 7);
                iVar22 = *(int *)(unaff_RBP + -5);
                uVar18 = *(uint *)(unaff_RBP + 0x7f);
                goto switchD_18004a65b_caseD_8004b460;
              }
              goto LAB_18004bb5a;
            }
            pcVar10 = "invalid distances set";
          }
          else {
            pcVar10 = "invalid literal/lengths set";
          }
          unaff_RDI = *(longlong **)(unaff_RBP + 0x67);
          unaff_RDI[4] = (longlong)pcVar10;
          *(undefined4 *)(lVar2 + 8) = 0x3f51;
          goto LAB_18004acc8;
        }
        unaff_RDI[4] = (longlong)"invalid code -- missing end-of-block";
        *(undefined4 *)(lVar2 + 8) = 0x3f51;
      }
LAB_18004accc:
      _Dst = *(undefined1 **)(unaff_RBP + 7);
      break;
    case 0x18004b460:
switchD_18004a65b_caseD_8004b460:
      *(undefined4 *)(lVar2 + 8) = 0x3f48;
    case 0x18004b468:
      if ((5 < uVar9) && (0x101 < uVar18)) {
        unaff_RDI[2] = (longlong)_Dst;
        *(uint *)(unaff_RDI + 3) = uVar18;
        *unaff_RDI = (longlong)_Src;
        *(uint *)(unaff_RDI + 1) = uVar9;
        *(uint *)(lVar2 + 0x48) = uVar24;
        *(uint *)(lVar2 + 0x4c) = uVar17;
        FUN_18004ea50(unaff_RDI,iVar22);
        iVar22 = *(int *)(lVar2 + 8);
        _Dst = (undefined1 *)unaff_RDI[2];
        uVar18 = *(uint *)(unaff_RDI + 3);
        uVar23 = (ulonglong)uVar18;
        _Src = (uint *)*unaff_RDI;
        uVar9 = *(uint *)(unaff_RDI + 1);
        uVar24 = *(uint *)(lVar2 + 0x48);
        uVar17 = *(uint *)(lVar2 + 0x4c);
        *(undefined1 **)(unaff_RBP + 7) = _Dst;
        *(uint *)(unaff_RBP + 0x7f) = uVar18;
        if (iVar22 == 0x3f3f) {
          *(undefined4 *)(lVar2 + 0x1be4) = 0xffffffff;
        }
        break;
      }
      lVar16 = *(longlong *)(lVar2 + 0x60);
      *(undefined4 *)(lVar2 + 0x1be4) = 0;
      uVar18 = *(uint *)(lVar16 + (ulonglong)
                                  ((1 << ((byte)*(undefined4 *)(lVar2 + 0x70) & 0x1f)) - 1U & uVar24
                                  ) * 4);
      if (uVar17 < (uVar18 >> 8 & 0xff)) {
        do {
          uVar19 = 0;
          if (uVar9 == 0) goto LAB_18004bb53;
          uVar9 = uVar9 - 1;
          uVar24 = uVar24 + ((uint)(byte)*_Src << ((byte)uVar17 & 0x1f));
          _Src = (uint *)((longlong)_Src + 1);
          uVar17 = uVar17 + 8;
          uVar18 = *(uint *)(*(longlong *)(lVar2 + 0x60) +
                            (ulonglong)
                            ((1 << ((byte)*(undefined4 *)(lVar2 + 0x70) & 0x1f)) - 1U & uVar24) * 4)
          ;
        } while (uVar17 < (uVar18 >> 8 & 0xff));
      }
      cVar6 = (char)uVar18;
      if ((cVar6 != '\0') && ((uVar18 & 0xf0) == 0)) {
        uVar7 = uVar18 >> 8;
        bVar1 = (byte)(uVar18 >> 8);
        *(uint *)(unaff_RBP + -1) = uVar18;
        uVar18 = *(uint *)(lVar16 + (ulonglong)
                                    ((((1 << (cVar6 + bVar1 & 0x1f)) - 1U & uVar24) >>
                                     (bVar1 & 0x1f)) + (uVar18 >> 0x10)) * 4);
        bVar1 = *unaff_RBP;
        if (uVar17 < (uVar18 >> 8 & 0xff) + (uVar7 & 0xff)) {
          do {
            uVar19 = 0;
            if (uVar9 == 0) goto LAB_18004bb53;
            uVar24 = uVar24 + ((uint)(byte)*_Src << ((byte)uVar17 & 0x1f));
            uVar9 = uVar9 - 1;
            _Src = (uint *)((longlong)_Src + 1);
            uVar17 = uVar17 + 8;
            uVar18 = *(uint *)(*(longlong *)(lVar2 + 0x60) +
                              (ulonglong)
                              ((((1 << (cVar6 + bVar1 & 0x1f)) - 1U & uVar24) >> (bVar1 & 0x1f)) +
                              (uint)*(ushort *)(unaff_RBP + 1)) * 4);
          } while (uVar17 < (uVar18 >> 8 & 0xff) + (uint)bVar1);
        }
        uVar24 = uVar24 >> (bVar1 & 0x1f);
        uVar17 = uVar17 - bVar1;
        *(uint *)(lVar2 + 0x1be4) = (uint)bVar1;
      }
      uVar7 = uVar18 >> 8 & 0xff;
      *(int *)(lVar2 + 0x1be4) = *(int *)(lVar2 + 0x1be4) + uVar7;
      uVar17 = uVar17 - uVar7;
      uVar24 = uVar24 >> ((byte)(uVar18 >> 8) & 0x1f);
      *(uint *)(lVar2 + 0x50) = uVar18 >> 0x10;
      if ((char)uVar18 != '\0') {
        if ((uVar18 & 0x20) != 0) {
          *(undefined4 *)(lVar2 + 0x1be4) = 0xffffffff;
          goto LAB_18004acc0;
        }
        if ((uVar18 & 0x40) != 0) {
          unaff_RDI[4] = (longlong)"invalid literal/length code";
          *(undefined4 *)(lVar2 + 8) = 0x3f51;
          goto LAB_18004acc8;
        }
        *(undefined4 *)(lVar2 + 8) = 0x3f49;
        *(uint *)(lVar2 + 0x58) = uVar18 & 0xf;
switchD_18004a65b_caseD_8004b680:
        uVar18 = *(uint *)(lVar2 + 0x58);
        if (uVar18 != 0) {
          for (; uVar17 < uVar18; uVar17 = uVar17 + 8) {
            uVar19 = 0;
            if (uVar9 == 0) goto LAB_18004bb53;
            uVar9 = uVar9 - 1;
            uVar24 = uVar24 + ((uint)(byte)*_Src << ((byte)uVar17 & 0x1f));
            _Src = (uint *)((longlong)_Src + 1);
          }
          uVar17 = uVar17 - uVar18;
          uVar7 = (1 << ((byte)uVar18 & 0x1f)) - 1U & uVar24;
          uVar24 = uVar24 >> ((byte)uVar18 & 0x1f);
          *(int *)(lVar2 + 0x50) = *(int *)(lVar2 + 0x50) + uVar7;
          *(int *)(lVar2 + 0x1be4) = *(int *)(lVar2 + 0x1be4) + uVar18;
        }
        *(undefined4 *)(lVar2 + 0x1be8) = *(undefined4 *)(lVar2 + 0x50);
        *(undefined4 *)(lVar2 + 8) = 0x3f4a;
switchD_18004a65b_caseD_8004b6e4:
        lVar16 = *(longlong *)(lVar2 + 0x68);
        uVar18 = *(uint *)(lVar16 + (ulonglong)
                                    ((1 << ((byte)*(undefined4 *)(lVar2 + 0x74) & 0x1f)) - 1U &
                                    uVar24) * 4);
        if (uVar17 < (uVar18 >> 8 & 0xff)) {
          do {
            uVar19 = 0;
            if (uVar9 == 0) goto LAB_18004bb53;
            uVar9 = uVar9 - 1;
            uVar24 = uVar24 + ((uint)(byte)*_Src << ((byte)uVar17 & 0x1f));
            _Src = (uint *)((longlong)_Src + 1);
            uVar17 = uVar17 + 8;
            uVar18 = *(uint *)(*(longlong *)(lVar2 + 0x68) +
                              (ulonglong)
                              ((1 << ((byte)*(undefined4 *)(lVar2 + 0x74) & 0x1f)) - 1U & uVar24) *
                              4);
          } while (uVar17 < (uVar18 >> 8 & 0xff));
        }
        if ((uVar18 & 0xf0) == 0) {
          uVar7 = uVar18 >> 8;
          cVar6 = (char)uVar18;
          bVar1 = (byte)(uVar18 >> 8);
          *(uint *)(unaff_RBP + -1) = uVar18;
          uVar18 = *(uint *)(lVar16 + (ulonglong)
                                      ((((1 << (cVar6 + bVar1 & 0x1f)) - 1U & uVar24) >>
                                       (bVar1 & 0x1f)) + (uVar18 >> 0x10)) * 4);
          bVar1 = *unaff_RBP;
          if (uVar17 < (uVar18 >> 8 & 0xff) + (uVar7 & 0xff)) {
            do {
              uVar19 = 0;
              if (uVar9 == 0) goto LAB_18004bb53;
              uVar24 = uVar24 + ((uint)(byte)*_Src << ((byte)uVar17 & 0x1f));
              uVar9 = uVar9 - 1;
              _Src = (uint *)((longlong)_Src + 1);
              uVar17 = uVar17 + 8;
              uVar18 = *(uint *)(*(longlong *)(lVar2 + 0x68) +
                                (ulonglong)
                                ((((1 << (cVar6 + bVar1 & 0x1f)) - 1U & uVar24) >> (bVar1 & 0x1f)) +
                                (uint)*(ushort *)(unaff_RBP + 1)) * 4);
            } while (uVar17 < (uVar18 >> 8 & 0xff) + (uint)bVar1);
          }
          uVar24 = uVar24 >> (bVar1 & 0x1f);
          uVar17 = uVar17 - bVar1;
          *(int *)(lVar2 + 0x1be4) = *(int *)(lVar2 + 0x1be4) + (uint)bVar1;
        }
        _Dst = *(undefined1 **)(unaff_RBP + 7);
        uVar23 = (ulonglong)*(uint *)(unaff_RBP + 0x7f);
        uVar7 = uVar18 >> 8 & 0xff;
        *(int *)(lVar2 + 0x1be4) = *(int *)(lVar2 + 0x1be4) + uVar7;
        uVar17 = uVar17 - uVar7;
        uVar24 = uVar24 >> ((byte)(uVar18 >> 8) & 0x1f);
        if ((uVar18 & 0x40) != 0) {
          unaff_RDI[4] = (longlong)"invalid distance code";
          *(undefined4 *)(lVar2 + 8) = 0x3f51;
          break;
        }
        iVar22 = *(int *)(unaff_RBP + -5);
        *(uint *)(lVar2 + 0x54) = uVar18 >> 0x10;
        *(undefined4 *)(lVar2 + 8) = 0x3f4b;
        *(uint *)(lVar2 + 0x58) = uVar18 & 0xf;
switchD_18004a65b_caseD_8004b871:
        uVar18 = *(uint *)(lVar2 + 0x58);
        if (uVar18 != 0) {
          for (; uVar17 < uVar18; uVar17 = uVar17 + 8) {
            uVar19 = 0;
            if (uVar9 == 0) goto LAB_18004bb53;
            uVar9 = uVar9 - 1;
            uVar24 = uVar24 + ((uint)(byte)*_Src << ((byte)uVar17 & 0x1f));
            _Src = (uint *)((longlong)_Src + 1);
          }
          uVar17 = uVar17 - uVar18;
          uVar7 = (1 << ((byte)uVar18 & 0x1f)) - 1U & uVar24;
          uVar24 = uVar24 >> ((byte)uVar18 & 0x1f);
          *(int *)(lVar2 + 0x54) = *(int *)(lVar2 + 0x54) + uVar7;
          *(int *)(lVar2 + 0x1be4) = *(int *)(lVar2 + 0x1be4) + uVar18;
        }
        *(undefined4 *)(lVar2 + 8) = 0x3f4c;
switchD_18004a65b_caseD_8004b8c5:
        uVar18 = (uint)uVar23;
        uVar19 = uVar9;
        if (uVar18 != 0) {
          uVar7 = *(uint *)(lVar2 + 0x54);
          if (iVar22 - uVar18 < uVar7) {
            uVar7 = uVar7 - (iVar22 - uVar18);
            if ((*(uint *)(lVar2 + 0x38) < uVar7) && (*(int *)(lVar2 + 0x1be0) != 0)) {
              unaff_RDI[4] = (longlong)"invalid distance too far back";
              *(undefined4 *)(lVar2 + 8) = 0x3f51;
              break;
            }
            uVar15 = *(uint *)(lVar2 + 0x3c);
            if (uVar15 < uVar7) {
              uVar7 = uVar7 - uVar15;
              uVar15 = *(int *)(lVar2 + 0x34) - uVar7;
            }
            else {
              uVar15 = uVar15 - uVar7;
            }
            lVar16 = (ulonglong)uVar15 + *(longlong *)(lVar2 + 0x40);
            uVar15 = *(uint *)(lVar2 + 0x50);
            if (uVar15 < uVar7) goto LAB_18004b934;
          }
          else {
            lVar16 = (longlong)_Dst - (ulonglong)uVar7;
            uVar15 = *(uint *)(lVar2 + 0x50);
LAB_18004b934:
            uVar7 = uVar15;
            uVar15 = uVar7;
          }
          uVar13 = (ulonglong)uVar7;
          if (uVar18 < uVar7) {
            uVar13 = uVar23 & 0xffffffff;
          }
          uVar18 = uVar18 - (int)uVar13;
          uVar23 = (ulonglong)uVar18;
          *(uint *)(unaff_RBP + 0x7f) = uVar18;
          lVar16 = lVar16 - (longlong)_Dst;
          *(uint *)(lVar2 + 0x50) = uVar15 - (int)uVar13;
          do {
            *_Dst = _Dst[lVar16];
            _Dst = _Dst + 1;
            uVar18 = (int)uVar13 - 1;
            uVar13 = (ulonglong)uVar18;
          } while (uVar18 != 0);
          *(undefined1 **)(unaff_RBP + 7) = _Dst;
          if (*(int *)(lVar2 + 0x50) == 0) {
            *(undefined4 *)(lVar2 + 8) = 0x3f48;
          }
          break;
        }
        goto LAB_18004bb53;
      }
      *(undefined4 *)(lVar2 + 8) = 0x3f4d;
      goto LAB_18004acc8;
    case 0x18004b680:
      goto switchD_18004a65b_caseD_8004b680;
    case 0x18004b6e4:
      goto switchD_18004a65b_caseD_8004b6e4;
    case 0x18004b871:
      goto switchD_18004a65b_caseD_8004b871;
    case 0x18004b8c5:
      goto switchD_18004a65b_caseD_8004b8c5;
    case 0x18004b97b:
      uVar19 = uVar9;
      if (uVar18 != 0) {
        *_Dst = *(undefined1 *)(lVar2 + 0x50);
        _Dst = _Dst + 1;
        uVar23 = (ulonglong)(uVar18 - 1);
        *(undefined1 **)(unaff_RBP + 7) = _Dst;
        *(uint *)(unaff_RBP + 0x7f) = uVar18 - 1;
        *(undefined4 *)(lVar2 + 8) = 0x3f48;
        break;
      }
      goto LAB_18004bb53;
    case 0x18004b9a7:
      uVar7 = uVar24;
      uVar5 = uVar17;
      if (*(int *)(lVar2 + 0x10) != 0) {
        for (; uVar5 < 0x20; uVar5 = uVar5 + 8) {
          uVar19 = 0;
          uVar24 = uVar7;
          uVar17 = uVar5;
          if (uVar9 == 0) goto LAB_18004bb53;
          uVar24 = *_Src;
          uVar9 = uVar9 - 1;
          _Src = (uint *)((longlong)_Src + 1);
          uVar7 = uVar7 + ((uint)(byte)uVar24 << ((byte)uVar5 & 0x1f));
        }
        uVar18 = iVar22 - uVar18;
        *(int *)((longlong)unaff_RDI + 0x1c) = *(int *)((longlong)unaff_RDI + 0x1c) + uVar18;
        *(int *)(lVar2 + 0x24) = *(int *)(lVar2 + 0x24) + uVar18;
        if (((*(byte *)(lVar2 + 0x10) & 4) != 0) && (uVar18 != 0)) {
          if (*(int *)(lVar2 + 0x18) == 0) {
            uVar18 = FUN_18004dfc0(*(uint *)(lVar2 + 0x20),_Dst + -(ulonglong)uVar18,uVar18);
          }
          else {
            uVar18 = FUN_18004c120(*(uint *)(lVar2 + 0x20),(uint *)(_Dst + -(ulonglong)uVar18),
                                   uVar18);
          }
          _Dst = *(undefined1 **)(unaff_RBP + 7);
          uVar23 = (ulonglong)*(uint *)(unaff_RBP + 0x7f);
          *(uint *)(lVar2 + 0x20) = uVar18;
          *(uint *)((longlong)unaff_RDI + 0x4c) = uVar18;
        }
        bVar1 = *(byte *)(lVar2 + 0x10);
        *(int *)(unaff_RBP + -5) = (int)uVar23;
        uVar24 = uVar15;
        uVar17 = uVar15;
        if ((bVar1 & 4) != 0) {
          uVar18 = uVar7;
          if (*(int *)(lVar2 + 0x18) == 0) {
            uVar18 = ((uVar7 & 0xff00) + uVar7 * 0x10000) * 0x100 + (uVar7 >> 8 & 0xff00) +
                     (uVar7 >> 0x18);
          }
          if (uVar18 != *(uint *)(lVar2 + 0x20)) {
            unaff_RDI[4] = (longlong)"incorrect data check";
            *(undefined4 *)(lVar2 + 8) = 0x3f51;
            uVar24 = uVar7;
            uVar17 = uVar5;
            break;
          }
        }
      }
      *(undefined4 *)(lVar2 + 8) = 0x3f4f;
    case 0x18004ba87:
      if ((*(int *)(lVar2 + 0x10) != 0) &&
         (uVar18 = uVar24, uVar7 = uVar17, *(int *)(lVar2 + 0x18) != 0)) {
        for (; uVar7 < 0x20; uVar7 = uVar7 + 8) {
          uVar19 = 0;
          uVar24 = uVar18;
          uVar17 = uVar7;
          if (uVar9 == 0) goto LAB_18004bb53;
          uVar24 = *_Src;
          uVar9 = uVar9 - 1;
          _Src = (uint *)((longlong)_Src + 1);
          uVar18 = uVar18 + ((uint)(byte)uVar24 << ((byte)uVar7 & 0x1f));
        }
        uVar24 = uVar15;
        uVar17 = uVar15;
        if (uVar18 != *(uint *)(lVar2 + 0x24)) {
          unaff_RDI[4] = (longlong)"incorrect length check";
          *(undefined4 *)(lVar2 + 8) = 0x3f51;
          uVar24 = uVar18;
          uVar17 = uVar7;
          break;
        }
      }
      *(undefined4 *)(lVar2 + 8) = 0x3f50;
switchD_18004a65b_caseD_8004bb34:
      iVar22 = *(int *)(unaff_RBP + 0x6f);
      uVar23 = 1;
      goto LAB_18004bb5a;
    case 0x18004bb34:
      goto switchD_18004a65b_caseD_8004bb34;
    case 0x18004bb3f:
      iVar22 = *(int *)(unaff_RBP + 0x6f);
      uVar23 = 0xfffffffd;
      goto LAB_18004bb5a;
    case 0x18004bbbf:
      goto LAB_18004bafb;
    }
    uVar7 = *(int *)(lVar2 + 8) - 0x3f34;
    if (0x1e < uVar7) {
      return 0xfffffffe;
    }
    uVar13 = (ulonglong)*(uint *)(unaff_RBP + -5);
  } while( true );
}

/* ---- FUNC 0004BB26 FUN_18004bb26 (359 bytes) ---- */

/* WARNING: Removing unreachable block (ram,0x00018004bc81) */

undefined4 FUN_18004bb26(void)

{
  byte bVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  uint uVar6;
  longlong unaff_RBP;
  undefined4 unaff_ESI;
  int iVar7;
  int iVar8;
  undefined4 unaff_R12D;
  longlong unaff_R13;
  undefined8 unaff_R14;
  
  *(undefined4 *)(unaff_R13 + 8) = 0x3f50;
  iVar8 = *(int *)(unaff_RBP + 0x6f);
  puVar2 = *(undefined8 **)(unaff_RBP + 0x67);
  puVar2[2] = *(undefined8 *)(unaff_RBP + 7);
  *(undefined4 *)(puVar2 + 3) = *(undefined4 *)(unaff_RBP + 0x7f);
  *puVar2 = unaff_R14;
  *(undefined4 *)(puVar2 + 1) = unaff_ESI;
  *(undefined4 *)(unaff_R13 + 0x4c) = unaff_R12D;
  iVar7 = *(int *)(unaff_RBP + -5);
  *(undefined4 *)(unaff_R13 + 0x48) = unaff_R12D;
  if (((*(int *)(unaff_R13 + 0x34) == 0) &&
      (((iVar7 == *(int *)(puVar2 + 3) || (0x3f50 < *(int *)(unaff_R13 + 8))) ||
       ((0x3f4d < *(int *)(unaff_R13 + 8) && (iVar8 == 4)))))) ||
     (uVar5 = FUN_18004c020((longlong)puVar2,puVar2[2],iVar7 - *(int *)(puVar2 + 3)),
     (int)uVar5 == 0)) {
    uVar6 = iVar7 - *(int *)(puVar2 + 3);
    iVar8 = *(int *)(unaff_RBP + 3) - *(int *)(puVar2 + 1);
    *(int *)((longlong)puVar2 + 0xc) = *(int *)((longlong)puVar2 + 0xc) + iVar8;
    *(int *)((longlong)puVar2 + 0x1c) = *(int *)((longlong)puVar2 + 0x1c) + uVar6;
    *(int *)(unaff_R13 + 0x24) = *(int *)(unaff_R13 + 0x24) + uVar6;
    bVar1 = *(byte *)(unaff_R13 + 0x10);
    *(int *)(unaff_RBP + 3) = iVar8;
    if (((bVar1 & 4) != 0) && (uVar6 != 0)) {
      if (*(int *)(unaff_R13 + 0x18) == 0) {
        uVar6 = FUN_18004dfc0(*(uint *)(unaff_R13 + 0x20),(byte *)(puVar2[2] - (ulonglong)uVar6),
                              uVar6);
      }
      else {
        uVar6 = FUN_18004c120(*(uint *)(unaff_R13 + 0x20),(uint *)(puVar2[2] - (ulonglong)uVar6),
                              uVar6);
      }
      *(uint *)(unaff_R13 + 0x20) = uVar6;
      *(uint *)((longlong)puVar2 + 0x4c) = uVar6;
    }
    iVar8 = *(int *)(unaff_R13 + 8);
    if ((iVar8 == 0x3f47) || (iVar8 == 0x3f42)) {
      iVar7 = 0x100;
    }
    else {
      iVar7 = 0;
    }
    iVar3 = 0;
    if (iVar8 == 0x3f3f) {
      iVar3 = 0x80;
    }
    *(uint *)(puVar2 + 9) =
         iVar3 + iVar7 + (-(uint)(*(int *)(unaff_R13 + 0xc) != 0) & 0x40) +
         *(int *)(unaff_R13 + 0x4c);
    uVar4 = 1;
  }
  else {
    *(undefined4 *)(unaff_R13 + 8) = 0x3f52;
    uVar4 = 0xfffffffc;
  }
  return uVar4;
}

/* ---- FUNC 0004BC97 FUN_18004bc97 (15 bytes) ---- */

undefined8 FUN_18004bc97(void)

{
  return 0xfffffffe;
}

/* ---- FUNC 0004BD30 FUN_18004bd30 (76 bytes) ---- */

undefined8 FUN_18004bd30(longlong param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  
  lVar2 = param_1;
  uVar1 = FUN_18004bfe0(param_1);
  if ((int)uVar1 != 0) {
    return 0xfffffffe;
  }
  if (*(longlong *)(*(longlong *)(lVar2 + 0x28) + 0x40) != 0) {
    (**(code **)(param_1 + 0x38))(*(undefined8 *)(lVar2 + 0x40));
  }
  (**(code **)(param_1 + 0x38))(*(undefined8 *)(param_1 + 0x40),*(undefined8 *)(param_1 + 0x28));
  *(undefined8 *)(param_1 + 0x28) = 0;
  return 0;
}

/* ---- FUNC 0004BD80 FUN_18004bd80 (63 bytes) ---- */

ulonglong FUN_18004bd80(longlong param_1,uint param_2,char *param_3,int param_4)

{
  longlong *plVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  if (((param_3 != (char *)0x0) && (*param_3 == '1')) && (param_4 == 0x58)) {
    if (param_1 != 0) {
      *(undefined8 *)(param_1 + 0x20) = 0;
      if (*(longlong *)(param_1 + 0x30) == 0) {
        *(undefined8 *)(param_1 + 0x40) = 0;
        *(code **)(param_1 + 0x30) = FUN_18004e2b0;
      }
      if (*(longlong *)(param_1 + 0x38) == 0) {
        *(code **)(param_1 + 0x38) = FUN_18004e2c0;
      }
      plVar1 = (longlong *)(**(code **)(param_1 + 0x30))(*(undefined8 *)(param_1 + 0x40),1,0x1bf0);
      if (plVar1 == (longlong *)0x0) {
        uVar2 = 0xfffffffc;
      }
      else {
        *(longlong **)(param_1 + 0x28) = plVar1;
        *plVar1 = param_1;
        plVar1[8] = 0;
        *(undefined4 *)(plVar1 + 1) = 0x3f34;
        uVar3 = FUN_18004bea0(param_1,param_2);
        uVar2 = uVar3 & 0xffffffff;
        if ((int)uVar3 != 0) {
          (**(code **)(param_1 + 0x38))(*(undefined8 *)(param_1 + 0x40),plVar1);
          *(undefined8 *)(param_1 + 0x28) = 0;
        }
      }
      return uVar2;
    }
    return 0xfffffffe;
  }
  return 0xfffffffa;
}

/* ---- FUNC 0004BDBF FUN_18004bdbf (104 bytes) ---- */

ulonglong FUN_18004bdbf(longlong param_1)

{
  longlong *plVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong unaff_RBX;
  uint unaff_ESI;
  
  *(undefined8 *)(param_1 + 0x20) = 0;
  if (*(longlong *)(param_1 + 0x30) == 0) {
    *(undefined8 *)(param_1 + 0x40) = 0;
    *(code **)(param_1 + 0x30) = FUN_18004e2b0;
  }
  if (*(longlong *)(param_1 + 0x38) == 0) {
    *(code **)(param_1 + 0x38) = FUN_18004e2c0;
  }
  plVar1 = (longlong *)(**(code **)(unaff_RBX + 0x30))(*(undefined8 *)(param_1 + 0x40),1,0x1bf0);
  if (plVar1 == (longlong *)0x0) {
    uVar2 = 0xfffffffc;
  }
  else {
    *(longlong **)(unaff_RBX + 0x28) = plVar1;
    *plVar1 = unaff_RBX;
    plVar1[8] = 0;
    *(undefined4 *)(plVar1 + 1) = 0x3f34;
    uVar3 = FUN_18004bea0(unaff_RBX,unaff_ESI);
    uVar2 = uVar3 & 0xffffffff;
    if ((int)uVar3 != 0) {
      (**(code **)(unaff_RBX + 0x38))(*(undefined8 *)(unaff_RBX + 0x40),plVar1);
      *(undefined8 *)(unaff_RBX + 0x28) = 0;
    }
  }
  return uVar2;
}

/* ---- FUNC 0004BE27 FUN_18004be27 (52 bytes) ---- */

ulonglong FUN_18004be27(void)

{
  longlong *in_RAX;
  ulonglong uVar1;
  longlong unaff_RBX;
  longlong unaff_RBP;
  uint unaff_ESI;
  undefined8 unaff_RDI;
  
  *(undefined8 *)(unaff_RBX + 0x28) = unaff_RDI;
  *in_RAX = unaff_RBX;
  in_RAX[8] = unaff_RBP;
  *(undefined4 *)(in_RAX + 1) = 0x3f34;
  uVar1 = FUN_18004bea0(unaff_RBX,unaff_ESI);
  if ((int)uVar1 != 0) {
    (**(code **)(unaff_RBX + 0x38))(*(undefined8 *)(unaff_RBX + 0x40));
    *(longlong *)(unaff_RBX + 0x28) = unaff_RBP;
  }
  return uVar1 & 0xffffffff;
}

/* ---- FUNC 0004BE5B FUN_18004be5b (16 bytes) ---- */

undefined8 FUN_18004be5b(void)

{
  return 0xfffffffa;
}

/* ---- FUNC 0004BE70 FUN_18004be70 (45 bytes) ---- */

undefined8 FUN_18004be70(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  uVar2 = FUN_18004bfe0(param_1);
  if ((int)uVar2 != 0) {
    return 0xfffffffe;
  }
  lVar1 = *(longlong *)(param_1 + 0x28);
  *(undefined8 *)(lVar1 + 0x34) = 0;
  *(undefined4 *)(lVar1 + 0x3c) = 0;
  uVar2 = FUN_18004bf50(param_1);
  return uVar2;
}

/* ---- FUNC 0004BEA0 FUN_18004bea0 (163 bytes) ---- */

undefined8 FUN_18004bea0(longlong param_1,uint param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  int iVar4;
  
  lVar3 = param_1;
  uVar2 = FUN_18004bfe0(param_1);
  if ((int)uVar2 != 0) {
    return 0xfffffffe;
  }
  lVar1 = *(longlong *)(lVar3 + 0x28);
  if ((int)param_2 < 0) {
    iVar4 = 0;
    param_2 = -param_2;
  }
  else {
    iVar4 = ((int)param_2 >> 4) + 5;
    if ((int)param_2 < 0x30) {
      param_2 = param_2 & 0xf;
    }
  }
  if ((param_2 == 0) || (param_2 - 8 < 8)) {
    if ((*(longlong *)(lVar1 + 0x40) != 0) && (*(uint *)(lVar1 + 0x30) != param_2)) {
      (**(code **)(param_1 + 0x38))(*(undefined8 *)(lVar3 + 0x40));
      *(undefined8 *)(lVar1 + 0x40) = 0;
    }
    *(int *)(lVar1 + 0x10) = iVar4;
    *(uint *)(lVar1 + 0x30) = param_2;
    uVar2 = FUN_18004be70(param_1);
  }
  else {
    uVar2 = 0xfffffffe;
  }
  return uVar2;
}

/* ---- FUNC 0004BF50 FUN_18004bf50 (138 bytes) ---- */

undefined8 FUN_18004bf50(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  lVar3 = param_1;
  uVar2 = FUN_18004bfe0(param_1);
  if ((int)uVar2 != 0) {
    return 0xfffffffe;
  }
  lVar1 = *(longlong *)(param_1 + 0x28);
  *(undefined4 *)(lVar1 + 0x24) = 0;
  *(undefined4 *)(lVar3 + 0x1c) = 0;
  *(undefined4 *)(lVar3 + 0xc) = 0;
  *(undefined8 *)(lVar3 + 0x20) = 0;
  if (*(uint *)(lVar1 + 0x10) != 0) {
    *(uint *)(lVar3 + 0x4c) = *(uint *)(lVar1 + 0x10) & 1;
  }
  lVar3 = lVar1 + 0x550;
  *(undefined8 *)(lVar1 + 8) = 0x3f34;
  *(longlong *)(lVar1 + 0x88) = lVar3;
  *(longlong *)(lVar1 + 0x68) = lVar3;
  *(longlong *)(lVar1 + 0x60) = lVar3;
  *(undefined4 *)(lVar1 + 0x14) = 0;
  *(undefined4 *)(lVar1 + 0x1c) = 0x8000;
  *(undefined8 *)(lVar1 + 0x28) = 0;
  *(undefined8 *)(lVar1 + 0x48) = 0;
  *(undefined4 *)(lVar1 + 0x1be0) = 1;
  *(undefined4 *)(lVar1 + 0x1be4) = 0xffffffff;
  return 0;
}

/* ---- FUNC 0004BFE0 FUN_18004bfe0 (55 bytes) ---- */

undefined8 FUN_18004bfe0(longlong param_1)

{
  longlong *plVar1;
  
  if ((((param_1 != 0) && (*(longlong *)(param_1 + 0x30) != 0)) &&
      (*(longlong *)(param_1 + 0x38) != 0)) &&
     (((plVar1 = *(longlong **)(param_1 + 0x28), plVar1 != (longlong *)0x0 && (*plVar1 == param_1))
      && ((int)plVar1[1] - 0x3f34U < 0x20)))) {
    return 0;
  }
  return 1;
}

/* ---- FUNC 0004C020 FUN_18004c020 (78 bytes) ---- */

undefined8 FUN_18004c020(longlong param_1,longlong param_2,uint param_3)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  
  lVar1 = *(longlong *)(param_1 + 0x28);
  if (*(longlong *)(lVar1 + 0x40) == 0) {
    lVar3 = (**(code **)(param_1 + 0x30))
                      (*(undefined8 *)(param_1 + 0x40),
                       1 << ((byte)*(undefined4 *)(lVar1 + 0x30) & 0x1f),1);
    *(longlong *)(lVar1 + 0x40) = lVar3;
    if (lVar3 == 0) {
      return 1;
    }
  }
  if (*(int *)(lVar1 + 0x34) == 0) {
    *(int *)(lVar1 + 0x34) = 1 << ((byte)*(undefined4 *)(lVar1 + 0x30) & 0x1f);
    *(undefined8 *)(lVar1 + 0x38) = 0;
  }
  uVar5 = *(uint *)(lVar1 + 0x34);
  if (param_3 < uVar5) {
    uVar5 = uVar5 - *(int *)(lVar1 + 0x3c);
    if (param_3 < uVar5) {
      uVar5 = param_3;
    }
    memcpy((void *)((ulonglong)*(uint *)(lVar1 + 0x3c) + *(longlong *)(lVar1 + 0x40)),
           (void *)(param_2 - (ulonglong)param_3),(ulonglong)uVar5);
    uVar4 = param_3 - uVar5;
    if (uVar4 == 0) {
      *(int *)(lVar1 + 0x3c) = *(int *)(lVar1 + 0x3c) + uVar5;
      iVar2 = *(int *)(lVar1 + 0x3c);
      if (*(int *)(lVar1 + 0x3c) == *(int *)(lVar1 + 0x34)) {
        iVar2 = 0;
      }
      *(int *)(lVar1 + 0x3c) = iVar2;
      if (*(uint *)(lVar1 + 0x34) <= *(uint *)(lVar1 + 0x38)) {
        return 0;
      }
      iVar2 = *(uint *)(lVar1 + 0x38) + uVar5;
    }
    else {
      memcpy(*(void **)(lVar1 + 0x40),(void *)(param_2 - (ulonglong)uVar4),(ulonglong)uVar4);
      iVar2 = *(int *)(lVar1 + 0x34);
      *(uint *)(lVar1 + 0x3c) = uVar4;
    }
  }
  else {
    memcpy(*(void **)(lVar1 + 0x40),(void *)(param_2 - (ulonglong)uVar5),(ulonglong)uVar5);
    iVar2 = *(int *)(lVar1 + 0x34);
    *(undefined4 *)(lVar1 + 0x3c) = 0;
  }
  *(int *)(lVar1 + 0x38) = iVar2;
  return 0;
}

/* ---- FUNC 0004C06E FUN_18004c06e (155 bytes) ---- */

undefined8 FUN_18004c06e(void)

{
  int iVar1;
  longlong unaff_RBX;
  uint uVar2;
  longlong unaff_RBP;
  longlong unaff_RSI;
  int unaff_EDI;
  uint uVar3;
  
  if (*(int *)(unaff_RBX + 0x34) == 0) {
    *(int *)(unaff_RBX + 0x34) = unaff_EDI << ((byte)*(undefined4 *)(unaff_RBX + 0x30) & 0x1f);
    *(undefined8 *)(unaff_RBX + 0x38) = 0;
  }
  uVar3 = *(uint *)(unaff_RBX + 0x34);
  uVar2 = (uint)unaff_RBP;
  if (uVar2 < uVar3) {
    uVar3 = uVar3 - *(int *)(unaff_RBX + 0x3c);
    if (uVar2 < uVar3) {
      uVar3 = uVar2;
    }
    memcpy((void *)((ulonglong)*(uint *)(unaff_RBX + 0x3c) + *(longlong *)(unaff_RBX + 0x40)),
           (void *)(unaff_RSI - unaff_RBP),(ulonglong)uVar3);
    uVar2 = uVar2 - uVar3;
    if (uVar2 == 0) {
      *(int *)(unaff_RBX + 0x3c) = *(int *)(unaff_RBX + 0x3c) + uVar3;
      iVar1 = *(int *)(unaff_RBX + 0x3c);
      if (*(int *)(unaff_RBX + 0x3c) == *(int *)(unaff_RBX + 0x34)) {
        iVar1 = 0;
      }
      *(int *)(unaff_RBX + 0x3c) = iVar1;
      if (*(uint *)(unaff_RBX + 0x34) <= *(uint *)(unaff_RBX + 0x38)) {
        return 0;
      }
      iVar1 = *(uint *)(unaff_RBX + 0x38) + uVar3;
    }
    else {
      memcpy(*(void **)(unaff_RBX + 0x40),(void *)(unaff_RSI - (ulonglong)uVar2),(ulonglong)uVar2);
      iVar1 = *(int *)(unaff_RBX + 0x34);
      *(uint *)(unaff_RBX + 0x3c) = uVar2;
    }
  }
  else {
    memcpy(*(void **)(unaff_RBX + 0x40),(void *)(unaff_RSI - (ulonglong)uVar3),(ulonglong)uVar3);
    iVar1 = *(int *)(unaff_RBX + 0x34);
    *(undefined4 *)(unaff_RBX + 0x3c) = 0;
  }
  *(int *)(unaff_RBX + 0x38) = iVar1;
  return 0;
}

/* ---- FUNC 0004C109 FUN_18004c109 (21 bytes) ---- */

void FUN_18004c109(void)

{
  return;
}

/* ---- FUNC 0004C120 FUN_18004c120 (8 bytes) ---- */

void FUN_18004c120(uint param_1,uint *param_2,uint param_3)

{
  crc32_z(param_1,param_2,(ulonglong)param_3);
  return;
}

/* ---- FUNC 0004C130 crc32_little (69 bytes) ---- */

/* Library Function - Single Match
    crc32_little
   
   Library: Visual Studio 2019 Release */

uint crc32_little(uint param_1,uint *param_2,ulonglong param_3)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar2 = ~param_1;
  for (; (param_3 != 0 && (((ulonglong)param_2 & 3) != 0));
      param_2 = (uint *)((longlong)param_2 + 1)) {
    uVar2 = *(uint *)(&DAT_180058770 + (ulonglong)(byte)((byte)*param_2 ^ (byte)uVar2) * 4) ^
            uVar2 >> 8;
    param_3 = param_3 - 1;
  }
  if (0x1f < param_3) {
    uVar3 = param_3 >> 5;
    param_3 = param_3 + uVar3 * -0x20;
    do {
      uVar2 = uVar2 ^ *param_2;
      uVar2 = *(uint *)(&DAT_180058b70 + (ulonglong)(byte)(uVar2 >> 0x10) * 4) ^
              *(uint *)(&DAT_180058f70 + (ulonglong)(byte)(uVar2 >> 8) * 4) ^
              *(uint *)(&DAT_180058770 + (ulonglong)(uVar2 >> 0x18) * 4) ^
              *(uint *)(&DAT_180059370 + (ulonglong)(uVar2 & 0xff) * 4) ^ param_2[1];
      uVar2 = *(uint *)(&DAT_180058b70 + (ulonglong)(byte)(uVar2 >> 0x10) * 4) ^
              *(uint *)(&DAT_180058f70 + (ulonglong)(byte)(uVar2 >> 8) * 4) ^
              *(uint *)(&DAT_180058770 + (ulonglong)(uVar2 >> 0x18) * 4) ^
              *(uint *)(&DAT_180059370 + (ulonglong)(uVar2 & 0xff) * 4) ^ param_2[2];
      uVar2 = *(uint *)(&DAT_180058b70 + (ulonglong)(byte)(uVar2 >> 0x10) * 4) ^
              *(uint *)(&DAT_180058f70 + (ulonglong)(byte)(uVar2 >> 8) * 4) ^
              *(uint *)(&DAT_180058770 + (ulonglong)(uVar2 >> 0x18) * 4) ^
              *(uint *)(&DAT_180059370 + (ulonglong)(uVar2 & 0xff) * 4) ^ param_2[3];
      uVar2 = *(uint *)(&DAT_180058b70 + (ulonglong)(byte)(uVar2 >> 0x10) * 4) ^
              *(uint *)(&DAT_180058f70 + (ulonglong)(byte)(uVar2 >> 8) * 4) ^
              *(uint *)(&DAT_180058770 + (ulonglong)(uVar2 >> 0x18) * 4) ^
              *(uint *)(&DAT_180059370 + (ulonglong)(uVar2 & 0xff) * 4) ^ param_2[4];
      uVar2 = *(uint *)(&DAT_180058b70 + (ulonglong)(byte)(uVar2 >> 0x10) * 4) ^
              *(uint *)(&DAT_180058f70 + (ulonglong)(byte)(uVar2 >> 8) * 4) ^
              *(uint *)(&DAT_180058770 + (ulonglong)(uVar2 >> 0x18) * 4) ^
              *(uint *)(&DAT_180059370 + (ulonglong)(uVar2 & 0xff) * 4) ^ param_2[5];
      uVar2 = *(uint *)(&DAT_180058b70 + (ulonglong)(byte)(uVar2 >> 0x10) * 4) ^
              *(uint *)(&DAT_180058f70 + (ulonglong)(byte)(uVar2 >> 8) * 4) ^
              *(uint *)(&DAT_180058770 + (ulonglong)(uVar2 >> 0x18) * 4) ^
              *(uint *)(&DAT_180059370 + (ulonglong)(uVar2 & 0xff) * 4) ^ param_2[6];
      uVar2 = *(uint *)(&DAT_180058b70 + (ulonglong)(byte)(uVar2 >> 0x10) * 4) ^
              *(uint *)(&DAT_180058f70 + (ulonglong)(byte)(uVar2 >> 8) * 4) ^
              *(uint *)(&DAT_180058770 + (ulonglong)(uVar2 >> 0x18) * 4) ^
              *(uint *)(&DAT_180059370 + (ulonglong)(uVar2 & 0xff) * 4) ^ param_2[7];
      param_2 = param_2 + 8;
      uVar2 = *(uint *)(&DAT_180058b70 + (ulonglong)(byte)(uVar2 >> 0x10) * 4) ^
              *(uint *)(&DAT_180058f70 + (ulonglong)(byte)(uVar2 >> 8) * 4) ^
              *(uint *)(&DAT_180058770 + (ulonglong)(uVar2 >> 0x18) * 4) ^
              *(uint *)(&DAT_180059370 + (ulonglong)(uVar2 & 0xff) * 4);
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  if (3 < param_3) {
    uVar3 = param_3 >> 2;
    param_3 = param_3 + uVar3 * -4;
    do {
      uVar2 = uVar2 ^ *param_2;
      param_2 = param_2 + 1;
      uVar2 = *(uint *)(&DAT_180058b70 + (ulonglong)(byte)(uVar2 >> 0x10) * 4) ^
              *(uint *)(&DAT_180058f70 + (ulonglong)(byte)(uVar2 >> 8) * 4) ^
              *(uint *)(&DAT_180058770 + (ulonglong)(uVar2 >> 0x18) * 4) ^
              *(uint *)(&DAT_180059370 + (ulonglong)(uVar2 & 0xff) * 4);
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  for (; param_3 != 0; param_3 = param_3 - 1) {
    uVar1 = *param_2;
    param_2 = (uint *)((longlong)param_2 + 1);
    uVar2 = *(uint *)(&DAT_180058770 + (ulonglong)(byte)((byte)uVar1 ^ (byte)uVar2) * 4) ^
            uVar2 >> 8;
  }
  return ~uVar2;
}

/* ---- FUNC 0004C175 FUN_18004c175 (564 bytes) ---- */

uint FUN_18004c175(uint param_1)

{
  ulonglong uVar1;
  longlong unaff_RDI;
  uint uVar2;
  uint *in_R10;
  ulonglong in_R11;
  ulonglong uVar3;
  
  uVar1 = in_R11 >> 5;
  uVar3 = in_R11 + uVar1 * -0x20;
  do {
    param_1 = param_1 ^ *in_R10;
    uVar2 = *(uint *)(unaff_RDI + 0x400 + (ulonglong)(byte)(param_1 >> 0x10) * 4) ^
            *(uint *)(unaff_RDI + 0x800 + (ulonglong)(byte)(param_1 >> 8) * 4) ^
            *(uint *)(unaff_RDI + (ulonglong)(param_1 >> 0x18) * 4) ^
            *(uint *)(unaff_RDI + 0xc00 + (ulonglong)(param_1 & 0xff) * 4) ^ in_R10[1];
    uVar2 = *(uint *)(unaff_RDI + 0x400 + (ulonglong)(byte)(uVar2 >> 0x10) * 4) ^
            *(uint *)(unaff_RDI + 0x800 + (ulonglong)(byte)(uVar2 >> 8) * 4) ^
            *(uint *)(unaff_RDI + (ulonglong)(uVar2 >> 0x18) * 4) ^
            *(uint *)(unaff_RDI + 0xc00 + (ulonglong)(uVar2 & 0xff) * 4) ^ in_R10[2];
    uVar2 = *(uint *)(unaff_RDI + 0x400 + (ulonglong)(byte)(uVar2 >> 0x10) * 4) ^
            *(uint *)(unaff_RDI + 0x800 + (ulonglong)(byte)(uVar2 >> 8) * 4) ^
            *(uint *)(unaff_RDI + (ulonglong)(uVar2 >> 0x18) * 4) ^
            *(uint *)(unaff_RDI + 0xc00 + (ulonglong)(uVar2 & 0xff) * 4) ^ in_R10[3];
    uVar2 = *(uint *)(unaff_RDI + 0x400 + (ulonglong)(byte)(uVar2 >> 0x10) * 4) ^
            *(uint *)(unaff_RDI + 0x800 + (ulonglong)(byte)(uVar2 >> 8) * 4) ^
            *(uint *)(unaff_RDI + (ulonglong)(uVar2 >> 0x18) * 4) ^
            *(uint *)(unaff_RDI + 0xc00 + (ulonglong)(uVar2 & 0xff) * 4) ^ in_R10[4];
    uVar2 = *(uint *)(unaff_RDI + 0x400 + (ulonglong)(byte)(uVar2 >> 0x10) * 4) ^
            *(uint *)(unaff_RDI + 0x800 + (ulonglong)(byte)(uVar2 >> 8) * 4) ^
            *(uint *)(unaff_RDI + (ulonglong)(uVar2 >> 0x18) * 4) ^
            *(uint *)(unaff_RDI + 0xc00 + (ulonglong)(uVar2 & 0xff) * 4) ^ in_R10[5];
    uVar2 = *(uint *)(unaff_RDI + 0x400 + (ulonglong)(byte)(uVar2 >> 0x10) * 4) ^
            *(uint *)(unaff_RDI + 0x800 + (ulonglong)(byte)(uVar2 >> 8) * 4) ^
            *(uint *)(unaff_RDI + (ulonglong)(uVar2 >> 0x18) * 4) ^
            *(uint *)(unaff_RDI + 0xc00 + (ulonglong)(uVar2 & 0xff) * 4) ^ in_R10[6];
    uVar2 = *(uint *)(unaff_RDI + 0x400 + (ulonglong)(byte)(uVar2 >> 0x10) * 4) ^
            *(uint *)(unaff_RDI + 0x800 + (ulonglong)(byte)(uVar2 >> 8) * 4) ^
            *(uint *)(unaff_RDI + (ulonglong)(uVar2 >> 0x18) * 4) ^
            *(uint *)(unaff_RDI + 0xc00 + (ulonglong)(uVar2 & 0xff) * 4) ^ in_R10[7];
    in_R10 = in_R10 + 8;
    param_1 = *(uint *)(unaff_RDI + 0x400 + (ulonglong)(byte)(uVar2 >> 0x10) * 4) ^
              *(uint *)(unaff_RDI + 0x800 + (ulonglong)(byte)(uVar2 >> 8) * 4) ^
              *(uint *)(unaff_RDI + (ulonglong)(uVar2 >> 0x18) * 4) ^
              *(uint *)(unaff_RDI + 0xc00 + (ulonglong)(uVar2 & 0xff) * 4);
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0);
  if (3 < uVar3) {
    uVar1 = uVar3 >> 2;
    uVar3 = uVar3 + uVar1 * -4;
    do {
      param_1 = param_1 ^ *in_R10;
      in_R10 = in_R10 + 1;
      param_1 = *(uint *)(unaff_RDI + 0x400 + (ulonglong)(byte)(param_1 >> 0x10) * 4) ^
                *(uint *)(unaff_RDI + 0x800 + (ulonglong)(byte)(param_1 >> 8) * 4) ^
                *(uint *)(unaff_RDI + (ulonglong)(param_1 >> 0x18) * 4) ^
                *(uint *)(unaff_RDI + 0xc00 + (ulonglong)(param_1 & 0xff) * 4);
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  for (; uVar3 != 0; uVar3 = uVar3 - 1) {
    uVar2 = *in_R10;
    in_R10 = (uint *)((longlong)in_R10 + 1);
    param_1 = *(uint *)(unaff_RDI + (ulonglong)(byte)((byte)uVar2 ^ (byte)param_1) * 4) ^
              param_1 >> 8;
  }
  return ~param_1;
}

/* ---- FUNC 0004C3A9 FUN_18004c3a9 (141 bytes) ---- */

uint FUN_18004c3a9(uint param_1)

{
  uint uVar1;
  longlong unaff_RDI;
  ulonglong uVar2;
  uint *in_R10;
  ulonglong in_R11;
  
  if (3 < in_R11) {
    uVar2 = in_R11 >> 2;
    in_R11 = in_R11 + uVar2 * -4;
    do {
      param_1 = param_1 ^ *in_R10;
      in_R10 = in_R10 + 1;
      param_1 = *(uint *)(unaff_RDI + 0x400 + (ulonglong)(byte)(param_1 >> 0x10) * 4) ^
                *(uint *)(unaff_RDI + 0x800 + (ulonglong)(byte)(param_1 >> 8) * 4) ^
                *(uint *)(unaff_RDI + (ulonglong)(param_1 >> 0x18) * 4) ^
                *(uint *)(unaff_RDI + 0xc00 + (ulonglong)(param_1 & 0xff) * 4);
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  for (; in_R11 != 0; in_R11 = in_R11 - 1) {
    uVar1 = *in_R10;
    in_R10 = (uint *)((longlong)in_R10 + 1);
    param_1 = *(uint *)(unaff_RDI + (ulonglong)(byte)((byte)uVar1 ^ (byte)param_1) * 4) ^
              param_1 >> 8;
  }
  return ~param_1;
}

/* ---- FUNC 0004C440 crc32_z (13 bytes) ---- */

/* Library Function - Single Match
    crc32_z
   
   Library: Visual Studio 2019 Release */

uint crc32_z(uint param_1,uint *param_2,ulonglong param_3)

{
  uint uVar1;
  
  if (param_2 == (uint *)0x0) {
    return 0;
  }
  uVar1 = crc32_little(param_1,param_2,param_3);
  return uVar1;
}

/* ---- FUNC 0004C450 FUN_18004c450 (284 bytes) ---- */

void FUN_18004c450(longlong param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x1714);
  if (iVar2 < 0xe) {
    *(ushort *)(param_1 + 0x1710) = *(ushort *)(param_1 + 0x1710) | 2 << ((byte)iVar2 & 0x1f);
    *(int *)(param_1 + 0x1714) = iVar2 + 3;
  }
  else {
    *(ushort *)(param_1 + 0x1710) = *(ushort *)(param_1 + 0x1710) | 2 << ((byte)iVar2 & 0x1f);
    *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
         *(undefined1 *)(param_1 + 0x1710);
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
    *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
         *(undefined1 *)(param_1 + 0x1711);
    cVar1 = *(char *)(param_1 + 0x1714);
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
    *(int *)(param_1 + 0x1714) = *(int *)(param_1 + 0x1714) + -0xd;
    *(ushort *)(param_1 + 0x1710) = 2 >> (0x10U - cVar1 & 0x1f);
  }
  iVar2 = *(int *)(param_1 + 0x1714);
  if (9 < iVar2) {
    *(ushort *)(param_1 + 0x1710) = *(ushort *)(param_1 + 0x1710) | 0 << ((byte)iVar2 & 0x1f);
    *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
         *(undefined1 *)(param_1 + 0x1710);
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
    *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
         *(undefined1 *)(param_1 + 0x1711);
    cVar1 = *(char *)(param_1 + 0x1714);
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
    *(int *)(param_1 + 0x1714) = *(int *)(param_1 + 0x1714) + -9;
    *(ushort *)(param_1 + 0x1710) = 0 >> (0x10U - cVar1 & 0x1f);
    bi_flush(param_1);
    return;
  }
  *(ushort *)(param_1 + 0x1710) = *(ushort *)(param_1 + 0x1710) | 0 << ((byte)iVar2 & 0x1f);
  *(int *)(param_1 + 0x1714) = iVar2 + 7;
  bi_flush(param_1);
  return;
}

/* ---- FUNC 0004C570 bi_flush (5 bytes) ---- */

void bi_flush(longlong param_1)

{
  if (*(int *)(param_1 + 0x1714) == 0x10) {
    *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
         *(undefined1 *)(param_1 + 0x1710);
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
    *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
         *(undefined1 *)(param_1 + 0x1711);
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
    *(undefined4 *)(param_1 + 0x1714) = 0;
    *(undefined2 *)(param_1 + 0x1710) = 0;
    return;
  }
  if (7 < *(int *)(param_1 + 0x1714)) {
    *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
         *(undefined1 *)(param_1 + 0x1710);
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
    *(int *)(param_1 + 0x1714) = *(int *)(param_1 + 0x1714) + -8;
    *(ushort *)(param_1 + 0x1710) = (ushort)*(byte *)(param_1 + 0x1711);
  }
  return;
}

/* ---- FUNC 0004C580 FUN_18004c580 (557 bytes) ---- */

void FUN_18004c580(longlong *param_1,void *param_2,uint param_3,int param_4)

{
  char cVar1;
  int iVar2;
  ushort uVar3;
  int iVar4;
  undefined8 uVar5;
  uint uVar6;
  uint uVar7;
  undefined *puVar8;
  uint uVar9;
  longlong *plVar10;
  longlong lVar11;
  
  uVar3 = (ushort)param_4;
  iVar4 = 0;
  if (*(int *)((longlong)param_1 + 0xac) < 1) {
    uVar7 = param_3 + 5;
    uVar9 = uVar7;
  }
  else {
    lVar11 = *param_1;
    if (*(int *)(lVar11 + 0x48) == 2) {
      uVar5 = FUN_18004d180((longlong)param_1);
      *(int *)(lVar11 + 0x48) = (int)uVar5;
    }
    FUN_18004caf0((longlong)param_1,param_1 + 0x168);
    FUN_18004caf0((longlong)param_1,param_1 + 0x16b);
    iVar4 = FUN_18004ca20((longlong)param_1);
    uVar6 = (int)param_1[0x2e0] + 10U >> 3;
    uVar7 = *(int *)((longlong)param_1 + 0x1704) + 10U >> 3;
    uVar9 = uVar7;
    if (uVar6 < uVar7) {
      uVar9 = uVar6;
    }
  }
  if ((uVar9 < param_3 + 4) || (param_2 == (void *)0x0)) {
    if (((int)param_1[0x16] == 4) || (uVar7 == uVar9)) {
      iVar4 = *(int *)((longlong)param_1 + 0x1714);
      if (iVar4 < 0xe) {
        *(ushort *)(param_1 + 0x2e2) =
             *(ushort *)(param_1 + 0x2e2) | uVar3 + 2 << ((byte)iVar4 & 0x1f);
        *(int *)((longlong)param_1 + 0x1714) = iVar4 + 3;
      }
      else {
        *(ushort *)(param_1 + 0x2e2) =
             *(ushort *)(param_1 + 0x2e2) | uVar3 + 2 << ((byte)iVar4 & 0x1f);
        *(char *)((ulonglong)*(uint *)(param_1 + 5) + param_1[2]) = (char)param_1[0x2e2];
        *(int *)(param_1 + 5) = (int)param_1[5] + 1;
        *(undefined1 *)((ulonglong)*(uint *)(param_1 + 5) + param_1[2]) =
             *(undefined1 *)((longlong)param_1 + 0x1711);
        cVar1 = *(char *)((longlong)param_1 + 0x1714);
        *(int *)(param_1 + 5) = (int)param_1[5] + 1;
        *(int *)((longlong)param_1 + 0x1714) = *(int *)((longlong)param_1 + 0x1714) + -0xd;
        *(ushort *)(param_1 + 0x2e2) = (ushort)(uVar3 + 2) >> (0x10U - cVar1 & 0x1f);
      }
      plVar10 = (longlong *)&DAT_18005b040;
      puVar8 = &DAT_18005abc0;
    }
    else {
      iVar2 = *(int *)((longlong)param_1 + 0x1714);
      if (iVar2 < 0xe) {
        *(ushort *)(param_1 + 0x2e2) =
             *(ushort *)(param_1 + 0x2e2) | uVar3 + 4 << ((byte)iVar2 & 0x1f);
        *(int *)((longlong)param_1 + 0x1714) = iVar2 + 3;
      }
      else {
        *(ushort *)(param_1 + 0x2e2) =
             *(ushort *)(param_1 + 0x2e2) | uVar3 + 4 << ((byte)iVar2 & 0x1f);
        *(char *)((ulonglong)*(uint *)(param_1 + 5) + param_1[2]) = (char)param_1[0x2e2];
        *(int *)(param_1 + 5) = (int)param_1[5] + 1;
        *(undefined1 *)((ulonglong)*(uint *)(param_1 + 5) + param_1[2]) =
             *(undefined1 *)((longlong)param_1 + 0x1711);
        cVar1 = *(char *)((longlong)param_1 + 0x1714);
        *(int *)(param_1 + 5) = (int)param_1[5] + 1;
        *(int *)((longlong)param_1 + 0x1714) = *(int *)((longlong)param_1 + 0x1714) + -0xd;
        *(ushort *)(param_1 + 0x2e2) = (ushort)(uVar3 + 4) >> (0x10U - cVar1 & 0x1f);
      }
      FUN_18004d770((longlong)param_1,(int)param_1[0x169] + 1,(int)param_1[0x16c] + 1,iVar4 + 1);
      plVar10 = param_1 + 0x136;
      puVar8 = (undefined *)((longlong)param_1 + 0xbc);
    }
    FUN_18004cd30((longlong)param_1,(longlong)puVar8,(longlong)plVar10);
  }
  else {
    FUN_18004c820((longlong)param_1,param_2,param_3,uVar3);
  }
  FUN_18004d4a0((longlong)param_1);
  if (param_4 != 0) {
    bi_windup((longlong)param_1);
  }
  return;
}

/* ---- FUNC 0004C7B0 _tr_init (104 bytes) ---- */

/* Library Function - Single Match
    _tr_init
   
   Library: Visual Studio 2019 Release */

void _tr_init(longlong param_1)

{
  *(longlong *)(param_1 + 0xb40) = param_1 + 0xbc;
  *(undefined ***)(param_1 + 0xb50) = &PTR_DAT_18005b0b8;
  *(longlong *)(param_1 + 0xb58) = param_1 + 0x9b0;
  *(undefined ***)(param_1 + 0xb68) = &PTR_DAT_18005b0d8;
  *(longlong *)(param_1 + 0xb70) = param_1 + 0xaa4;
  *(undefined **)(param_1 + 0xb80) = &DAT_18005b0f8;
  *(undefined2 *)(param_1 + 0x1710) = 0;
  *(undefined4 *)(param_1 + 0x1714) = 0;
  FUN_18004d4a0(param_1);
  return;
}

/* ---- FUNC 0004C820 FUN_18004c820 (253 bytes) ---- */

void FUN_18004c820(longlong param_1,void *param_2,uint param_3,ushort param_4)

{
  char cVar1;
  int iVar2;
  byte bVar3;
  
  iVar2 = *(int *)(param_1 + 0x1714);
  if (iVar2 < 0xe) {
    *(ushort *)(param_1 + 0x1710) = *(ushort *)(param_1 + 0x1710) | param_4 << ((byte)iVar2 & 0x1f);
    *(int *)(param_1 + 0x1714) = iVar2 + 3;
  }
  else {
    *(ushort *)(param_1 + 0x1710) = *(ushort *)(param_1 + 0x1710) | param_4 << ((byte)iVar2 & 0x1f);
    *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
         *(undefined1 *)(param_1 + 0x1710);
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
    *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
         *(undefined1 *)(param_1 + 0x1711);
    cVar1 = *(char *)(param_1 + 0x1714);
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
    *(int *)(param_1 + 0x1714) = *(int *)(param_1 + 0x1714) + -0xd;
    *(ushort *)(param_1 + 0x1710) = param_4 >> (0x10U - cVar1 & 0x1f);
  }
  bi_windup(param_1);
  *(byte *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) = (byte)param_3;
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
  bVar3 = (byte)(param_3 >> 8);
  *(byte *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) = bVar3;
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
  *(byte *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) = ~(byte)param_3;
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
  *(byte *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) = ~bVar3;
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
  memcpy((void *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)),param_2,
         (ulonglong)param_3);
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + param_3;
  return;
}

/* ---- FUNC 0004C920 bi_flush (128 bytes) ---- */

/* Library Function - Single Match
    bi_flush
   
   Library: Visual Studio 2019 Release */

void bi_flush(longlong param_1)

{
  if (*(int *)(param_1 + 0x1714) == 0x10) {
    *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
         *(undefined1 *)(param_1 + 0x1710);
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
    *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
         *(undefined1 *)(param_1 + 0x1711);
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
    *(undefined4 *)(param_1 + 0x1714) = 0;
    *(undefined2 *)(param_1 + 0x1710) = 0;
    return;
  }
  if (7 < *(int *)(param_1 + 0x1714)) {
    *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
         *(undefined1 *)(param_1 + 0x1710);
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
    *(int *)(param_1 + 0x1714) = *(int *)(param_1 + 0x1714) + -8;
    *(ushort *)(param_1 + 0x1710) = (ushort)*(byte *)(param_1 + 0x1711);
  }
  return;
}

/* ---- FUNC 0004C9A0 FUN_18004c9a0 (25 bytes) ---- */

uint FUN_18004c9a0(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = 0;
  do {
    uVar2 = uVar1;
    param_2 = param_2 + -1;
    uVar3 = param_1 & 1;
    param_1 = param_1 >> 1;
    uVar1 = (uVar2 | uVar3) * 2;
  } while (0 < param_2);
  return uVar2 & 0x7fffffff | uVar3;
}

/* ---- FUNC 0004C9C0 bi_windup (89 bytes) ---- */

/* Library Function - Single Match
    bi_windup
   
   Library: Visual Studio 2019 Release */

void bi_windup(longlong param_1)

{
  undefined1 uVar1;
  
  if (*(int *)(param_1 + 0x1714) < 9) {
    if (*(int *)(param_1 + 0x1714) < 1) goto LAB_18004ca07;
    uVar1 = *(undefined1 *)(param_1 + 0x1710);
  }
  else {
    *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
         *(undefined1 *)(param_1 + 0x1710);
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
    uVar1 = *(undefined1 *)(param_1 + 0x1711);
  }
  *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) = uVar1;
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
LAB_18004ca07:
  *(undefined2 *)(param_1 + 0x1710) = 0;
  *(undefined4 *)(param_1 + 0x1714) = 0;
  return;
}

/* ---- FUNC 0004CA20 FUN_18004ca20 (197 bytes) ---- */

int FUN_18004ca20(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  
  lVar1 = param_1;
  FUN_18004d630(param_1,param_1 + 0xbc,*(int *)(param_1 + 0xb48));
  FUN_18004d630(lVar1,lVar1 + 0x9b0,*(int *)(lVar1 + 0xb60));
  FUN_18004caf0(lVar1,(longlong *)(lVar1 + 0xb70));
  iVar2 = 0x12;
  lVar1 = 0x12;
  do {
    if (*(short *)(param_1 + 0xaa6 + (ulonglong)(byte)(&DAT_18005b118)[lVar1] * 4) != 0) break;
    if (*(short *)(param_1 + 0xaa6 + (ulonglong)(byte)(&UNK_18005b117)[lVar1] * 4) != 0) {
      iVar2 = iVar2 + -1;
      break;
    }
    if (*(short *)(param_1 + 0xaa6 + (ulonglong)(byte)(&UNK_18005b116)[lVar1] * 4) != 0) {
      iVar2 = iVar2 + -2;
      break;
    }
    if (*(short *)(param_1 + 0xaa6 + (ulonglong)(byte)(&UNK_18005b115)[lVar1] * 4) != 0) {
      iVar2 = iVar2 + -3;
      break;
    }
    lVar1 = lVar1 + -4;
    iVar2 = iVar2 + -4;
  } while (2 < lVar1);
  *(int *)(param_1 + 0x1700) = *(int *)(param_1 + 0x1700) + iVar2 * 3 + 0x11;
  return iVar2;
}

/* ---- FUNC 0004CAF0 FUN_18004caf0 (566 bytes) ---- */

void FUN_18004caf0(longlong param_1,longlong *param_2)

{
  short *psVar1;
  longlong lVar2;
  char cVar3;
  uint uVar4;
  longlong lVar5;
  longlong lVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  ulonglong uVar11;
  
  lVar2 = *param_2;
  iVar7 = -1;
  iVar9 = 0;
  iVar8 = *(int *)(param_2[2] + 0x14);
  uVar11 = (ulonglong)iVar8;
  lVar6 = *(longlong *)param_2[2];
  *(undefined4 *)(param_1 + 0x149c) = 0;
  *(undefined4 *)(param_1 + 0x14a0) = 0x23d;
  lVar5 = 0;
  if (0 < iVar8) {
    do {
      if (*(short *)(lVar2 + lVar5 * 4) == 0) {
        *(undefined2 *)(lVar2 + 2 + lVar5 * 4) = 0;
      }
      else {
        *(int *)(param_1 + 0x149c) = *(int *)(param_1 + 0x149c) + 1;
        *(int *)(param_1 + 0xba8 + (longlong)*(int *)(param_1 + 0x149c) * 4) = iVar9;
        *(undefined1 *)(lVar5 + 0x14a4 + param_1) = 0;
        iVar7 = iVar9;
      }
      iVar9 = iVar9 + 1;
      lVar5 = lVar5 + 1;
    } while (lVar5 < (longlong)uVar11);
  }
  iVar8 = *(int *)(param_1 + 0x149c);
  while (iVar8 < 2) {
    if (iVar7 < 2) {
      iVar8 = iVar7 + 1;
      iVar7 = iVar8;
    }
    else {
      iVar8 = 0;
    }
    *(int *)(param_1 + 0x149c) = *(int *)(param_1 + 0x149c) + 1;
    *(int *)(param_1 + 0xba8 + (longlong)*(int *)(param_1 + 0x149c) * 4) = iVar8;
    lVar5 = (longlong)iVar8;
    *(undefined2 *)(lVar2 + lVar5 * 4) = 1;
    *(undefined1 *)(lVar5 + 0x14a4 + param_1) = 0;
    *(int *)(param_1 + 0x1700) = *(int *)(param_1 + 0x1700) + -1;
    if (lVar6 != 0) {
      *(int *)(param_1 + 0x1704) =
           *(int *)(param_1 + 0x1704) - (uint)*(ushort *)(lVar6 + 2 + lVar5 * 4);
    }
    iVar8 = *(int *)(param_1 + 0x149c);
  }
  *(int *)(param_2 + 1) = iVar7;
  for (uVar4 = *(int *)(param_1 + 0x149c) / 2; 0 < (int)uVar4; uVar4 = uVar4 - 1) {
    FUN_18004d520(param_1,lVar2,(ulonglong)uVar4);
  }
  do {
    iVar8 = *(int *)(param_1 + 0xbac);
    lVar5 = (longlong)iVar8;
    *(undefined4 *)(param_1 + 0xbac) =
         *(undefined4 *)(param_1 + 0xba8 + (longlong)*(int *)(param_1 + 0x149c) * 4);
    *(int *)(param_1 + 0x149c) = *(int *)(param_1 + 0x149c) + -1;
    FUN_18004d520(param_1,lVar2,1);
    iVar9 = *(int *)(param_1 + 0xbac);
    lVar6 = (longlong)iVar9;
    *(int *)(param_1 + 0x14a0) = *(int *)(param_1 + 0x14a0) + -1;
    psVar1 = (short *)(lVar2 + lVar6 * 4);
    iVar10 = (int)uVar11;
    *(int *)(param_1 + 0xba8 + (longlong)*(int *)(param_1 + 0x14a0) * 4) = iVar8;
    *(int *)(param_1 + 0x14a0) = *(int *)(param_1 + 0x14a0) + -1;
    *(int *)(param_1 + 0xba8 + (longlong)*(int *)(param_1 + 0x14a0) * 4) = iVar9;
    *(short *)(lVar2 + (longlong)iVar10 * 4) = *psVar1 + *(short *)(lVar2 + lVar5 * 4);
    if (*(byte *)(lVar5 + 0x14a4 + param_1) < *(byte *)(lVar6 + 0x14a4 + param_1)) {
      cVar3 = *(char *)(lVar6 + 0x14a4 + param_1);
    }
    else {
      cVar3 = *(char *)(lVar5 + 0x14a4 + param_1);
    }
    *(char *)((longlong)iVar10 + 0x14a4 + param_1) = cVar3 + '\x01';
    psVar1[1] = (short)uVar11;
    *(short *)(lVar2 + 2 + lVar5 * 4) = (short)uVar11;
    *(int *)(param_1 + 0xbac) = iVar10;
    uVar11 = (ulonglong)(iVar10 + 1);
    lVar6 = param_1;
    FUN_18004d520(param_1,lVar2,1);
  } while (1 < *(int *)(param_1 + 0x149c));
  *(int *)(param_1 + 0x14a0) = *(int *)(param_1 + 0x14a0) + -1;
  *(undefined4 *)(param_1 + 0xba8 + (longlong)*(int *)(param_1 + 0x14a0) * 4) =
       *(undefined4 *)(param_1 + 0xbac);
  FUN_18004d200(lVar6,param_2);
  FUN_18004d410(lVar2,iVar7,param_1 + 0xb88);
  return;
}

/* ---- FUNC 0004CD30 FUN_18004cd30 (8 bytes) ---- */

void FUN_18004cd30(longlong param_1,longlong param_2,longlong param_3)

{
  ushort *puVar1;
  longlong lVar2;
  char cVar3;
  byte bVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  byte bVar8;
  uint uVar9;
  ulonglong uVar10;
  ushort uVar11;
  uint uVar12;
  ushort uVar13;
  
  uVar10 = 0;
  if (*(int *)(param_1 + 0x16f4) != 0) {
    do {
      uVar11 = *(ushort *)(*(longlong *)(param_1 + 0x16f8) + uVar10 * 2);
      bVar8 = *(byte *)(uVar10 + *(longlong *)(param_1 + 0x16e8));
      uVar9 = (int)uVar10 + 1;
      uVar10 = (ulonglong)uVar9;
      if (uVar11 == 0) {
        uVar11 = *(ushort *)(param_2 + 2 + (longlong)(int)(uint)bVar8 * 4);
        puVar1 = (ushort *)(param_2 + (longlong)(int)(uint)bVar8 * 4);
        iVar7 = *(int *)(param_1 + 0x1714);
        if ((int)(0x10 - (uint)uVar11) < iVar7) {
          uVar13 = *puVar1;
          *(ushort *)(param_1 + 0x1710) =
               *(ushort *)(param_1 + 0x1710) | uVar13 << ((byte)iVar7 & 0x1f);
          *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
               *(undefined1 *)(param_1 + 0x1710);
          *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
          *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
               *(undefined1 *)(param_1 + 0x1711);
          cVar3 = *(char *)(param_1 + 0x1714);
          *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
          *(int *)(param_1 + 0x1714) = *(int *)(param_1 + 0x1714) + (uVar11 - 0x10);
          *(ushort *)(param_1 + 0x1710) = uVar13 >> (0x10U - cVar3 & 0x1f);
        }
        else {
          *(ushort *)(param_1 + 0x1710) =
               *(ushort *)(param_1 + 0x1710) | *puVar1 << ((byte)iVar7 & 0x1f);
          iVar7 = iVar7 + (uint)uVar11;
LAB_18004d0a8:
          *(int *)(param_1 + 0x1714) = iVar7;
        }
      }
      else {
        bVar4 = (&DAT_18005a770)[bVar8];
        uVar13 = *(ushort *)(param_2 + 2 + (ulonglong)(bVar4 + 0x101) * 4);
        puVar1 = (ushort *)(param_2 + (ulonglong)(bVar4 + 0x101) * 4);
        iVar6 = *(int *)(param_1 + 0x1714);
        if ((int)(0x10 - (uint)uVar13) < iVar6) {
          uVar5 = *puVar1;
          *(ushort *)(param_1 + 0x1710) =
               *(ushort *)(param_1 + 0x1710) | uVar5 << ((byte)iVar6 & 0x1f);
          *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
               *(undefined1 *)(param_1 + 0x1710);
          *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
          *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
               *(undefined1 *)(param_1 + 0x1711);
          cVar3 = *(char *)(param_1 + 0x1714);
          *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
          *(int *)(param_1 + 0x1714) = *(int *)(param_1 + 0x1714) + (uVar13 - 0x10);
          *(ushort *)(param_1 + 0x1710) = uVar5 >> (0x10U - cVar3 & 0x1f);
        }
        else {
          *(ushort *)(param_1 + 0x1710) =
               *(ushort *)(param_1 + 0x1710) | *puVar1 << ((byte)iVar6 & 0x1f);
          *(uint *)(param_1 + 0x1714) = iVar6 + (uint)uVar13;
        }
        iVar6 = *(int *)(&DAT_18005aa70 + (ulonglong)bVar4 * 4);
        if (iVar6 != 0) {
          uVar13 = (ushort)bVar8 - (short)*(undefined4 *)(&DAT_18005b130 + (ulonglong)bVar4 * 4);
          iVar7 = *(int *)(param_1 + 0x1714);
          if (0x10 - iVar6 < iVar7) {
            *(ushort *)(param_1 + 0x1710) =
                 *(ushort *)(param_1 + 0x1710) | uVar13 << ((byte)iVar7 & 0x1f);
            *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
                 *(undefined1 *)(param_1 + 0x1710);
            *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
            *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
                 *(undefined1 *)(param_1 + 0x1711);
            cVar3 = *(char *)(param_1 + 0x1714);
            *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
            *(int *)(param_1 + 0x1714) = *(int *)(param_1 + 0x1714) + iVar6 + -0x10;
            *(ushort *)(param_1 + 0x1710) = uVar13 >> (0x10U - cVar3 & 0x1f);
          }
          else {
            *(ushort *)(param_1 + 0x1710) =
                 *(ushort *)(param_1 + 0x1710) | uVar13 << ((byte)iVar7 & 0x1f);
            *(int *)(param_1 + 0x1714) = iVar7 + iVar6;
          }
        }
        uVar12 = uVar11 - 1;
        if (uVar12 < 0x100) {
          bVar8 = (&DAT_18005a870)[uVar12];
        }
        else {
          bVar8 = (&DAT_18005a870)[(uVar12 >> 7) + 0x100];
        }
        lVar2 = (ulonglong)bVar8 * 4;
        iVar6 = *(int *)(param_1 + 0x1714);
        uVar11 = *(ushort *)(lVar2 + 2 + param_3);
        if ((int)(0x10 - (uint)uVar11) < iVar6) {
          uVar13 = *(ushort *)(lVar2 + param_3);
          *(ushort *)(param_1 + 0x1710) =
               *(ushort *)(param_1 + 0x1710) | uVar13 << ((byte)iVar6 & 0x1f);
          *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
               *(undefined1 *)(param_1 + 0x1710);
          *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
          *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
               *(undefined1 *)(param_1 + 0x1711);
          cVar3 = *(char *)(param_1 + 0x1714);
          *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
          *(int *)(param_1 + 0x1714) = *(int *)(param_1 + 0x1714) + (uVar11 - 0x10);
          *(ushort *)(param_1 + 0x1710) = uVar13 >> (0x10U - cVar3 & 0x1f);
        }
        else {
          *(ushort *)(param_1 + 0x1710) =
               *(ushort *)(param_1 + 0x1710) | *(short *)(lVar2 + param_3) << ((byte)iVar6 & 0x1f);
          *(uint *)(param_1 + 0x1714) = iVar6 + (uint)uVar11;
        }
        iVar6 = *(int *)(&DAT_18005aaf0 + lVar2);
        if (iVar6 != 0) {
          uVar11 = (short)uVar12 - (short)*(undefined4 *)(&DAT_18005b1b0 + lVar2);
          iVar7 = *(int *)(param_1 + 0x1714);
          if (iVar7 <= 0x10 - iVar6) {
            *(ushort *)(param_1 + 0x1710) =
                 *(ushort *)(param_1 + 0x1710) | uVar11 << ((byte)iVar7 & 0x1f);
            iVar7 = iVar7 + iVar6;
            goto LAB_18004d0a8;
          }
          *(ushort *)(param_1 + 0x1710) =
               *(ushort *)(param_1 + 0x1710) | uVar11 << ((byte)iVar7 & 0x1f);
          *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
               *(undefined1 *)(param_1 + 0x1710);
          *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
          *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
               *(undefined1 *)(param_1 + 0x1711);
          cVar3 = *(char *)(param_1 + 0x1714);
          *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
          *(int *)(param_1 + 0x1714) = *(int *)(param_1 + 0x1714) + iVar6 + -0x10;
          *(ushort *)(param_1 + 0x1710) = uVar11 >> (0x10U - cVar3 & 0x1f);
        }
      }
    } while (uVar9 < *(uint *)(param_1 + 0x16f4));
  }
  uVar11 = *(ushort *)(param_2 + 0x402);
  iVar6 = *(int *)(param_1 + 0x1714);
  if (iVar6 <= (int)(0x10 - (uint)uVar11)) {
    *(ushort *)(param_1 + 0x1710) =
         *(ushort *)(param_1 + 0x1710) | *(short *)(param_2 + 0x400) << ((byte)iVar6 & 0x1f);
    *(uint *)(param_1 + 0x1714) = iVar6 + (uint)uVar11;
    return;
  }
  uVar13 = *(ushort *)(param_2 + 0x400);
  *(ushort *)(param_1 + 0x1710) = *(ushort *)(param_1 + 0x1710) | uVar13 << ((byte)iVar6 & 0x1f);
  *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
       *(undefined1 *)(param_1 + 0x1710);
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
  *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
       *(undefined1 *)(param_1 + 0x1711);
  cVar3 = *(char *)(param_1 + 0x1714);
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
  *(int *)(param_1 + 0x1714) = *(int *)(param_1 + 0x1714) + (uVar11 - 0x10);
  *(ushort *)(param_1 + 0x1710) = uVar13 >> (0x10U - cVar3 & 0x1f);
  return;
}

/* ---- FUNC 0004CD38 FUN_18004cd38 (35 bytes) ---- */

void FUN_18004cd38(longlong param_1,longlong param_2,longlong param_3)

{
  ushort *puVar1;
  longlong lVar2;
  char cVar3;
  byte bVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  byte bVar8;
  uint uVar9;
  ulonglong uVar10;
  ushort uVar11;
  uint uVar12;
  ushort uVar13;
  
  uVar10 = 0;
  if (*(int *)(param_1 + 0x16f4) != 0) {
    do {
      uVar11 = *(ushort *)(*(longlong *)(param_1 + 0x16f8) + uVar10 * 2);
      bVar8 = *(byte *)(uVar10 + *(longlong *)(param_1 + 0x16e8));
      uVar9 = (int)uVar10 + 1;
      uVar10 = (ulonglong)uVar9;
      if (uVar11 == 0) {
        uVar11 = *(ushort *)(param_2 + 2 + (longlong)(int)(uint)bVar8 * 4);
        puVar1 = (ushort *)(param_2 + (longlong)(int)(uint)bVar8 * 4);
        iVar7 = *(int *)(param_1 + 0x1714);
        if ((int)(0x10 - (uint)uVar11) < iVar7) {
          uVar13 = *puVar1;
          *(ushort *)(param_1 + 0x1710) =
               *(ushort *)(param_1 + 0x1710) | uVar13 << ((byte)iVar7 & 0x1f);
          *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
               *(undefined1 *)(param_1 + 0x1710);
          *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
          *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
               *(undefined1 *)(param_1 + 0x1711);
          cVar3 = *(char *)(param_1 + 0x1714);
          *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
          *(int *)(param_1 + 0x1714) = *(int *)(param_1 + 0x1714) + (uVar11 - 0x10);
          *(ushort *)(param_1 + 0x1710) = uVar13 >> (0x10U - cVar3 & 0x1f);
        }
        else {
          *(ushort *)(param_1 + 0x1710) =
               *(ushort *)(param_1 + 0x1710) | *puVar1 << ((byte)iVar7 & 0x1f);
          iVar7 = iVar7 + (uint)uVar11;
LAB_18004d0a8:
          *(int *)(param_1 + 0x1714) = iVar7;
        }
      }
      else {
        bVar4 = (&DAT_18005a770)[bVar8];
        uVar13 = *(ushort *)(param_2 + 2 + (ulonglong)(bVar4 + 0x101) * 4);
        puVar1 = (ushort *)(param_2 + (ulonglong)(bVar4 + 0x101) * 4);
        iVar6 = *(int *)(param_1 + 0x1714);
        if ((int)(0x10 - (uint)uVar13) < iVar6) {
          uVar5 = *puVar1;
          *(ushort *)(param_1 + 0x1710) =
               *(ushort *)(param_1 + 0x1710) | uVar5 << ((byte)iVar6 & 0x1f);
          *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
               *(undefined1 *)(param_1 + 0x1710);
          *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
          *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
               *(undefined1 *)(param_1 + 0x1711);
          cVar3 = *(char *)(param_1 + 0x1714);
          *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
          *(int *)(param_1 + 0x1714) = *(int *)(param_1 + 0x1714) + (uVar13 - 0x10);
          *(ushort *)(param_1 + 0x1710) = uVar5 >> (0x10U - cVar3 & 0x1f);
        }
        else {
          *(ushort *)(param_1 + 0x1710) =
               *(ushort *)(param_1 + 0x1710) | *puVar1 << ((byte)iVar6 & 0x1f);
          *(uint *)(param_1 + 0x1714) = iVar6 + (uint)uVar13;
        }
        iVar6 = *(int *)(&DAT_18005aa70 + (ulonglong)bVar4 * 4);
        if (iVar6 != 0) {
          uVar13 = (ushort)bVar8 - (short)*(undefined4 *)(&DAT_18005b130 + (ulonglong)bVar4 * 4);
          iVar7 = *(int *)(param_1 + 0x1714);
          if (0x10 - iVar6 < iVar7) {
            *(ushort *)(param_1 + 0x1710) =
                 *(ushort *)(param_1 + 0x1710) | uVar13 << ((byte)iVar7 & 0x1f);
            *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
                 *(undefined1 *)(param_1 + 0x1710);
            *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
            *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
                 *(undefined1 *)(param_1 + 0x1711);
            cVar3 = *(char *)(param_1 + 0x1714);
            *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
            *(int *)(param_1 + 0x1714) = *(int *)(param_1 + 0x1714) + iVar6 + -0x10;
            *(ushort *)(param_1 + 0x1710) = uVar13 >> (0x10U - cVar3 & 0x1f);
          }
          else {
            *(ushort *)(param_1 + 0x1710) =
                 *(ushort *)(param_1 + 0x1710) | uVar13 << ((byte)iVar7 & 0x1f);
            *(int *)(param_1 + 0x1714) = iVar7 + iVar6;
          }
        }
        uVar12 = uVar11 - 1;
        if (uVar12 < 0x100) {
          bVar8 = (&DAT_18005a870)[uVar12];
        }
        else {
          bVar8 = (&DAT_18005a870)[(uVar12 >> 7) + 0x100];
        }
        lVar2 = (ulonglong)bVar8 * 4;
        iVar6 = *(int *)(param_1 + 0x1714);
        uVar11 = *(ushort *)(lVar2 + 2 + param_3);
        if ((int)(0x10 - (uint)uVar11) < iVar6) {
          uVar13 = *(ushort *)(lVar2 + param_3);
          *(ushort *)(param_1 + 0x1710) =
               *(ushort *)(param_1 + 0x1710) | uVar13 << ((byte)iVar6 & 0x1f);
          *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
               *(undefined1 *)(param_1 + 0x1710);
          *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
          *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
               *(undefined1 *)(param_1 + 0x1711);
          cVar3 = *(char *)(param_1 + 0x1714);
          *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
          *(int *)(param_1 + 0x1714) = *(int *)(param_1 + 0x1714) + (uVar11 - 0x10);
          *(ushort *)(param_1 + 0x1710) = uVar13 >> (0x10U - cVar3 & 0x1f);
        }
        else {
          *(ushort *)(param_1 + 0x1710) =
               *(ushort *)(param_1 + 0x1710) | *(short *)(lVar2 + param_3) << ((byte)iVar6 & 0x1f);
          *(uint *)(param_1 + 0x1714) = iVar6 + (uint)uVar11;
        }
        iVar6 = *(int *)(&DAT_18005aaf0 + lVar2);
        if (iVar6 != 0) {
          uVar11 = (short)uVar12 - (short)*(undefined4 *)(&DAT_18005b1b0 + lVar2);
          iVar7 = *(int *)(param_1 + 0x1714);
          if (iVar7 <= 0x10 - iVar6) {
            *(ushort *)(param_1 + 0x1710) =
                 *(ushort *)(param_1 + 0x1710) | uVar11 << ((byte)iVar7 & 0x1f);
            iVar7 = iVar7 + iVar6;
            goto LAB_18004d0a8;
          }
          *(ushort *)(param_1 + 0x1710) =
               *(ushort *)(param_1 + 0x1710) | uVar11 << ((byte)iVar7 & 0x1f);
          *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
               *(undefined1 *)(param_1 + 0x1710);
          *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
          *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
               *(undefined1 *)(param_1 + 0x1711);
          cVar3 = *(char *)(param_1 + 0x1714);
          *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
          *(int *)(param_1 + 0x1714) = *(int *)(param_1 + 0x1714) + iVar6 + -0x10;
          *(ushort *)(param_1 + 0x1710) = uVar11 >> (0x10U - cVar3 & 0x1f);
        }
      }
    } while (uVar9 < *(uint *)(param_1 + 0x16f4));
  }
  uVar11 = *(ushort *)(param_2 + 0x402);
  iVar6 = *(int *)(param_1 + 0x1714);
  if (iVar6 <= (int)(0x10 - (uint)uVar11)) {
    *(ushort *)(param_1 + 0x1710) =
         *(ushort *)(param_1 + 0x1710) | *(short *)(param_2 + 0x400) << ((byte)iVar6 & 0x1f);
    *(uint *)(param_1 + 0x1714) = iVar6 + (uint)uVar11;
    return;
  }
  uVar13 = *(ushort *)(param_2 + 0x400);
  *(ushort *)(param_1 + 0x1710) = *(ushort *)(param_1 + 0x1710) | uVar13 << ((byte)iVar6 & 0x1f);
  *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
       *(undefined1 *)(param_1 + 0x1710);
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
  *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
       *(undefined1 *)(param_1 + 0x1711);
  cVar3 = *(char *)(param_1 + 0x1714);
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
  *(int *)(param_1 + 0x1714) = *(int *)(param_1 + 0x1714) + (uVar11 - 0x10);
  *(ushort *)(param_1 + 0x1710) = uVar13 >> (0x10U - cVar3 & 0x1f);
  return;
}

/* ---- FUNC 0004CD5B FUN_18004cd5b (878 bytes) ---- */

void FUN_18004cd5b(void)

{
  ushort *puVar1;
  longlong lVar2;
  char cVar3;
  byte bVar4;
  ushort uVar5;
  int iVar6;
  longlong in_RAX;
  int iVar7;
  byte bVar8;
  char cVar9;
  int unaff_EBX;
  uint uVar10;
  ulonglong unaff_RBP;
  ushort uVar11;
  uint uVar12;
  ushort uVar13;
  longlong unaff_R14;
  longlong unaff_R15;
  
  do {
    uVar11 = *(ushort *)(*(longlong *)(in_RAX + 0x16f8) + unaff_RBP * 2);
    bVar8 = *(byte *)(unaff_RBP + *(longlong *)(in_RAX + 0x16e8));
    uVar10 = (int)unaff_RBP + 1;
    unaff_RBP = (ulonglong)uVar10;
    cVar9 = (char)unaff_EBX;
    if (uVar11 == 0) {
      uVar11 = *(ushort *)(unaff_R14 + 2 + (longlong)(int)(uint)bVar8 * 4);
      puVar1 = (ushort *)(unaff_R14 + (longlong)(int)(uint)bVar8 * 4);
      iVar7 = *(int *)(in_RAX + 0x1714);
      if ((int)(unaff_EBX - (uint)uVar11) < iVar7) {
        uVar13 = *puVar1;
        *(ushort *)(in_RAX + 0x1710) = *(ushort *)(in_RAX + 0x1710) | uVar13 << ((byte)iVar7 & 0x1f)
        ;
        *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
             *(undefined1 *)(in_RAX + 0x1710);
        *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
        *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
             *(undefined1 *)(in_RAX + 0x1711);
        cVar3 = *(char *)(in_RAX + 0x1714);
        *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
        *(int *)(in_RAX + 0x1714) = *(int *)(in_RAX + 0x1714) + (uVar11 - 0x10);
        *(ushort *)(in_RAX + 0x1710) = uVar13 >> (cVar9 - cVar3 & 0x1fU);
      }
      else {
        *(ushort *)(in_RAX + 0x1710) =
             *(ushort *)(in_RAX + 0x1710) | *puVar1 << ((byte)iVar7 & 0x1f);
        iVar7 = iVar7 + (uint)uVar11;
LAB_18004d0a8:
        *(int *)(in_RAX + 0x1714) = iVar7;
      }
    }
    else {
      bVar4 = (&DAT_18005a770)[bVar8];
      uVar13 = *(ushort *)(unaff_R14 + 2 + (ulonglong)(bVar4 + 0x101) * 4);
      puVar1 = (ushort *)(unaff_R14 + (ulonglong)(bVar4 + 0x101) * 4);
      iVar6 = *(int *)(in_RAX + 0x1714);
      if ((int)(unaff_EBX - (uint)uVar13) < iVar6) {
        uVar5 = *puVar1;
        *(ushort *)(in_RAX + 0x1710) = *(ushort *)(in_RAX + 0x1710) | uVar5 << ((byte)iVar6 & 0x1f);
        *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
             *(undefined1 *)(in_RAX + 0x1710);
        *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
        *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
             *(undefined1 *)(in_RAX + 0x1711);
        cVar3 = *(char *)(in_RAX + 0x1714);
        *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
        *(int *)(in_RAX + 0x1714) = *(int *)(in_RAX + 0x1714) + (uVar13 - 0x10);
        *(ushort *)(in_RAX + 0x1710) = uVar5 >> (cVar9 - cVar3 & 0x1fU);
      }
      else {
        *(ushort *)(in_RAX + 0x1710) =
             *(ushort *)(in_RAX + 0x1710) | *puVar1 << ((byte)iVar6 & 0x1f);
        *(uint *)(in_RAX + 0x1714) = iVar6 + (uint)uVar13;
      }
      iVar6 = *(int *)(&DAT_18005aa70 + (ulonglong)bVar4 * 4);
      if (iVar6 != 0) {
        uVar13 = (ushort)bVar8 - (short)*(undefined4 *)(&DAT_18005b130 + (ulonglong)bVar4 * 4);
        iVar7 = *(int *)(in_RAX + 0x1714);
        if (unaff_EBX - iVar6 < iVar7) {
          *(ushort *)(in_RAX + 0x1710) =
               *(ushort *)(in_RAX + 0x1710) | uVar13 << ((byte)iVar7 & 0x1f);
          *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
               *(undefined1 *)(in_RAX + 0x1710);
          *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
          *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
               *(undefined1 *)(in_RAX + 0x1711);
          cVar3 = *(char *)(in_RAX + 0x1714);
          *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
          *(int *)(in_RAX + 0x1714) = *(int *)(in_RAX + 0x1714) + iVar6 + -0x10;
          *(ushort *)(in_RAX + 0x1710) = uVar13 >> (cVar9 - cVar3 & 0x1fU);
        }
        else {
          *(ushort *)(in_RAX + 0x1710) =
               *(ushort *)(in_RAX + 0x1710) | uVar13 << ((byte)iVar7 & 0x1f);
          *(int *)(in_RAX + 0x1714) = iVar7 + iVar6;
        }
      }
      uVar12 = uVar11 - 1;
      if (uVar12 < 0x100) {
        bVar8 = (&DAT_18005a870)[uVar12];
      }
      else {
        bVar8 = (&DAT_18005a870)[(uVar12 >> 7) + 0x100];
      }
      lVar2 = (ulonglong)bVar8 * 4;
      iVar6 = *(int *)(in_RAX + 0x1714);
      uVar11 = *(ushort *)(lVar2 + 2 + unaff_R15);
      if ((int)(unaff_EBX - (uint)uVar11) < iVar6) {
        uVar13 = *(ushort *)(lVar2 + unaff_R15);
        *(ushort *)(in_RAX + 0x1710) = *(ushort *)(in_RAX + 0x1710) | uVar13 << ((byte)iVar6 & 0x1f)
        ;
        *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
             *(undefined1 *)(in_RAX + 0x1710);
        *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
        *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
             *(undefined1 *)(in_RAX + 0x1711);
        cVar3 = *(char *)(in_RAX + 0x1714);
        *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
        *(int *)(in_RAX + 0x1714) = *(int *)(in_RAX + 0x1714) + (uVar11 - 0x10);
        *(ushort *)(in_RAX + 0x1710) = uVar13 >> (cVar9 - cVar3 & 0x1fU);
      }
      else {
        *(ushort *)(in_RAX + 0x1710) =
             *(ushort *)(in_RAX + 0x1710) | *(short *)(lVar2 + unaff_R15) << ((byte)iVar6 & 0x1f);
        *(uint *)(in_RAX + 0x1714) = iVar6 + (uint)uVar11;
      }
      iVar6 = *(int *)(&DAT_18005aaf0 + lVar2);
      if (iVar6 != 0) {
        uVar11 = (short)uVar12 - (short)*(undefined4 *)(&DAT_18005b1b0 + lVar2);
        iVar7 = *(int *)(in_RAX + 0x1714);
        if (iVar7 <= unaff_EBX - iVar6) {
          *(ushort *)(in_RAX + 0x1710) =
               *(ushort *)(in_RAX + 0x1710) | uVar11 << ((byte)iVar7 & 0x1f);
          iVar7 = iVar7 + iVar6;
          goto LAB_18004d0a8;
        }
        *(ushort *)(in_RAX + 0x1710) = *(ushort *)(in_RAX + 0x1710) | uVar11 << ((byte)iVar7 & 0x1f)
        ;
        *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
             *(undefined1 *)(in_RAX + 0x1710);
        *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
        *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
             *(undefined1 *)(in_RAX + 0x1711);
        cVar3 = *(char *)(in_RAX + 0x1714);
        *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
        *(int *)(in_RAX + 0x1714) = *(int *)(in_RAX + 0x1714) + iVar6 + -0x10;
        *(ushort *)(in_RAX + 0x1710) = uVar11 >> (cVar9 - cVar3 & 0x1fU);
      }
    }
    if (*(uint *)(in_RAX + 0x16f4) <= uVar10) {
      uVar11 = *(ushort *)(unaff_R14 + 0x402);
      iVar6 = *(int *)(in_RAX + 0x1714);
      if ((int)(unaff_EBX - (uint)uVar11) < iVar6) {
        uVar13 = *(ushort *)(unaff_R14 + 0x400);
        *(ushort *)(in_RAX + 0x1710) = *(ushort *)(in_RAX + 0x1710) | uVar13 << ((byte)iVar6 & 0x1f)
        ;
        *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
             *(undefined1 *)(in_RAX + 0x1710);
        *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
        *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
             *(undefined1 *)(in_RAX + 0x1711);
        cVar3 = *(char *)(in_RAX + 0x1714);
        *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
        *(int *)(in_RAX + 0x1714) = *(int *)(in_RAX + 0x1714) + (uVar11 - 0x10);
        *(ushort *)(in_RAX + 0x1710) = uVar13 >> (cVar9 - cVar3 & 0x1fU);
        return;
      }
      *(ushort *)(in_RAX + 0x1710) =
           *(ushort *)(in_RAX + 0x1710) | *(short *)(unaff_R14 + 0x400) << ((byte)iVar6 & 0x1f);
      *(uint *)(in_RAX + 0x1714) = iVar6 + (uint)uVar11;
      return;
    }
  } while( true );
}

/* ---- FUNC 0004D0C9 FUN_18004d0c9 (172 bytes) ---- */

void FUN_18004d0c9(void)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  longlong in_RAX;
  int unaff_EBX;
  longlong unaff_R14;
  
  uVar2 = *(ushort *)(unaff_R14 + 0x402);
  iVar4 = *(int *)(in_RAX + 0x1714);
  if ((int)(unaff_EBX - (uint)uVar2) < iVar4) {
    uVar3 = *(ushort *)(unaff_R14 + 0x400);
    *(ushort *)(in_RAX + 0x1710) = *(ushort *)(in_RAX + 0x1710) | uVar3 << ((byte)iVar4 & 0x1f);
    *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
         *(undefined1 *)(in_RAX + 0x1710);
    *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
    *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
         *(undefined1 *)(in_RAX + 0x1711);
    cVar1 = *(char *)(in_RAX + 0x1714);
    *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
    *(int *)(in_RAX + 0x1714) = *(int *)(in_RAX + 0x1714) + (uVar2 - 0x10);
    *(ushort *)(in_RAX + 0x1710) = uVar3 >> ((char)unaff_EBX - cVar1 & 0x1fU);
    return;
  }
  *(ushort *)(in_RAX + 0x1710) =
       *(ushort *)(in_RAX + 0x1710) | *(short *)(unaff_R14 + 0x400) << ((byte)iVar4 & 0x1f);
  *(uint *)(in_RAX + 0x1714) = iVar4 + (uint)uVar2;
  return;
}

/* ---- FUNC 0004D0E9 FUN_18004d0e9 (105 bytes) ---- */

void FUN_18004d0e9(byte param_1)

{
  char cVar1;
  ushort uVar2;
  longlong in_RAX;
  char unaff_BL;
  int in_R11D;
  longlong unaff_R14;
  
  uVar2 = *(ushort *)(unaff_R14 + 0x400);
  *(ushort *)(in_RAX + 0x1710) = *(ushort *)(in_RAX + 0x1710) | uVar2 << (param_1 & 0x1f);
  *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
       *(undefined1 *)(in_RAX + 0x1710);
  *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
  *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
       *(undefined1 *)(in_RAX + 0x1711);
  cVar1 = *(char *)(in_RAX + 0x1714);
  *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
  *(int *)(in_RAX + 0x1714) = *(int *)(in_RAX + 0x1714) + in_R11D + -0x10;
  *(ushort *)(in_RAX + 0x1710) = uVar2 >> (unaff_BL - cVar1 & 0x1fU);
  return;
}

/* ---- FUNC 0004D180 FUN_18004d180 (119 bytes) ---- */

undefined8 FUN_18004d180(longlong param_1)

{
  short *psVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  psVar1 = (short *)(param_1 + 0xbc);
  lVar2 = 0;
  uVar3 = 0xf3ffc07f;
  while (((uVar3 & 1) == 0 || (*psVar1 == 0))) {
    lVar2 = lVar2 + 1;
    uVar3 = uVar3 >> 1;
    psVar1 = psVar1 + 2;
    if (0x1f < lVar2) {
      if (((*(short *)(param_1 + 0xe0) == 0) && (*(short *)(param_1 + 0xe4) == 0)) &&
         (*(short *)(param_1 + 0xf0) == 0)) {
        lVar2 = 0x20;
        psVar1 = (short *)(param_1 + 0x13c);
        while (*psVar1 == 0) {
          lVar2 = lVar2 + 1;
          psVar1 = psVar1 + 2;
          if (0xff < lVar2) {
            return 0;
          }
        }
      }
      return 1;
    }
  }
  return 0;
}

/* ---- FUNC 0004D200 FUN_18004d200 (118 bytes) ---- */

void FUN_18004d200(longlong param_1,longlong *param_2)

{
  ushort *puVar1;
  short *psVar2;
  ushort uVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  longlong *plVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  longlong lVar15;
  ulonglong uVar16;
  int iVar17;
  longlong lVar18;
  int iVar19;
  undefined2 *puVar20;
  uint uVar21;
  ulonglong uVar22;
  int iVar23;
  longlong lVar24;
  int *piVar25;
  longlong lVar26;
  
  plVar7 = (longlong *)param_2[2];
  lVar8 = *param_2;
  lVar9 = param_2[1];
  lVar26 = *plVar7;
  iVar23 = 0;
  lVar24 = plVar7[1];
  lVar10 = plVar7[2];
  iVar6 = (int)plVar7[3];
  uVar22 = (ulonglong)iVar6;
  puVar20 = (undefined2 *)(param_1 + 0xb88);
  for (lVar15 = 0x10; lVar15 != 0; lVar15 = lVar15 + -1) {
    *puVar20 = 0;
    puVar20 = puVar20 + 1;
  }
  *(undefined2 *)
   (lVar8 + 2 + (longlong)*(int *)(param_1 + 0xba8 + (longlong)*(int *)(param_1 + 0x14a0) * 4) * 4)
       = 0;
  iVar12 = *(int *)(param_1 + 0x14a0) + 1;
  lVar15 = (longlong)iVar12;
  if (lVar15 < 0x23d) {
    lVar18 = 0x23d - lVar15;
    iVar17 = (int)lVar18;
    piVar25 = (int *)(param_1 + 0xba8 + lVar15 * 4);
    do {
      iVar5 = *piVar25;
      lVar15 = (longlong)iVar5 * 4;
      iVar13 = *(ushort *)(lVar8 + 2 + (ulonglong)*(ushort *)(lVar15 + 2 + lVar8) * 4) + 1;
      if (iVar6 < iVar13) {
        iVar23 = iVar23 + 1;
        iVar13 = iVar6;
      }
      *(short *)(lVar15 + 2 + lVar8) = (short)iVar13;
      if (iVar5 <= (int)lVar9) {
        iVar19 = 0;
        psVar2 = (short *)(param_1 + 0xb88 + (longlong)iVar13 * 2);
        *psVar2 = *psVar2 + 1;
        if ((int)lVar10 <= iVar5) {
          iVar19 = *(int *)(lVar24 + (longlong)(iVar5 - (int)lVar10) * 4);
        }
        uVar3 = *(ushort *)(lVar15 + lVar8);
        *(int *)(param_1 + 0x1700) = *(int *)(param_1 + 0x1700) + (iVar19 + iVar13) * (uint)uVar3;
        if (lVar26 != 0) {
          *(int *)(param_1 + 0x1704) =
               *(int *)(param_1 + 0x1704) +
               ((uint)*(ushort *)(lVar15 + 2 + lVar26) + iVar19) * (uint)uVar3;
        }
      }
      piVar25 = piVar25 + 1;
      lVar18 = lVar18 + -1;
    } while (lVar18 != 0);
    if (iVar23 != 0) {
      do {
        uVar16 = (ulonglong)(int)(iVar6 - 1U);
        sVar4 = *(short *)(param_1 + 0xb88 + uVar16 * 2);
        uVar14 = iVar6 - 1U;
        while (sVar4 == 0) {
          uVar14 = (int)uVar16 - 1;
          uVar16 = (ulonglong)uVar14;
          sVar4 = *(short *)(param_1 + 0xb88 + (longlong)(int)uVar14 * 2);
        }
        iVar23 = iVar23 + -2;
        psVar2 = (short *)(param_1 + 0xb88 + (longlong)(int)uVar14 * 2);
        *psVar2 = *psVar2 + -1;
        psVar2 = (short *)(param_1 + 0xb88 + (longlong)(int)(uVar14 + 1) * 2);
        *psVar2 = *psVar2 + 2;
        psVar2 = (short *)(param_1 + uVar22 * 2 + 0xb88);
        *psVar2 = *psVar2 + -1;
      } while (0 < iVar23);
      if (iVar6 != 0) {
        lVar26 = (longlong)(iVar12 + iVar17);
        do {
          uVar21 = (uint)uVar22;
          uVar3 = *(ushort *)(param_1 + 0xb88 + (longlong)(int)uVar21 * 2);
          uVar14 = (uint)uVar3;
          if (uVar3 != 0) {
            lVar24 = param_1 + 0xba8 + lVar26 * 4;
            do {
              iVar6 = *(int *)(lVar24 + -4);
              lVar24 = lVar24 + -4;
              lVar26 = lVar26 + -1;
              if (iVar6 <= (int)lVar9) {
                puVar1 = (ushort *)(lVar8 + (longlong)iVar6 * 4);
                uVar11 = (uint)*(ushort *)(lVar8 + 2 + (longlong)iVar6 * 4);
                if (uVar11 != uVar21) {
                  *(int *)(param_1 + 0x1700) =
                       *(int *)(param_1 + 0x1700) + (uVar21 - uVar11) * (uint)*puVar1;
                  puVar1[1] = (ushort)uVar22;
                }
                uVar14 = uVar14 - 1;
              }
            } while (uVar14 != 0);
          }
          uVar22 = (ulonglong)(uVar21 - 1);
        } while (uVar21 - 1 != 0);
      }
    }
  }
  return;
}

/* ---- FUNC 0004D276 FUN_18004d276 (166 bytes) ---- */

void FUN_18004d276(int param_1,undefined8 param_2,longlong param_3,ulonglong param_4)

{
  ushort *puVar1;
  short *psVar2;
  ushort uVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  longlong in_RAX;
  int iVar7;
  uint uVar8;
  ulonglong uVar9;
  int unaff_EBX;
  int iVar10;
  longlong unaff_RBP;
  longlong unaff_RSI;
  int iVar11;
  int iVar12;
  uint uVar13;
  int in_R10D;
  longlong lVar14;
  int *piVar15;
  longlong lVar16;
  int unaff_R12D;
  longlong unaff_R13;
  longlong unaff_R15;
  
  iVar10 = (int)unaff_RBP;
  piVar15 = (int *)(param_3 + 0xba8 + in_RAX * 4);
  do {
    iVar5 = *piVar15;
    lVar16 = (longlong)iVar5 * 4;
    iVar7 = *(ushort *)(unaff_RSI + 2 + (ulonglong)*(ushort *)(lVar16 + 2 + unaff_RSI) * 4) + 1;
    iVar12 = (int)param_4;
    if (iVar12 < iVar7) {
      in_R10D = in_R10D + 1;
      iVar7 = iVar12;
    }
    *(short *)(lVar16 + 2 + unaff_RSI) = (short)iVar7;
    if (iVar5 <= unaff_EBX) {
      iVar11 = 0;
      psVar2 = (short *)(param_3 + 0xb88 + (longlong)iVar7 * 2);
      *psVar2 = *psVar2 + 1;
      if (unaff_R12D <= iVar5) {
        iVar11 = *(int *)(unaff_R13 + (longlong)(iVar5 - unaff_R12D) * 4);
      }
      uVar3 = *(ushort *)(lVar16 + unaff_RSI);
      *(int *)(param_3 + 0x1700) = *(int *)(param_3 + 0x1700) + (iVar11 + iVar7) * (uint)uVar3;
      if (unaff_R15 != 0) {
        *(int *)(param_3 + 0x1704) =
             *(int *)(param_3 + 0x1704) +
             ((uint)*(ushort *)(lVar16 + 2 + unaff_R15) + iVar11) * (uint)uVar3;
      }
    }
    piVar15 = piVar15 + 1;
    unaff_RBP = unaff_RBP + -1;
  } while (unaff_RBP != 0);
  if (in_R10D != 0) {
    do {
      uVar9 = (ulonglong)(int)(iVar12 - 1U);
      sVar4 = *(short *)(param_3 + 0xb88 + uVar9 * 2);
      uVar8 = iVar12 - 1U;
      while (sVar4 == 0) {
        uVar8 = (int)uVar9 - 1;
        uVar9 = (ulonglong)uVar8;
        sVar4 = *(short *)(param_3 + 0xb88 + (longlong)(int)uVar8 * 2);
      }
      in_R10D = in_R10D + -2;
      psVar2 = (short *)(param_3 + 0xb88 + (longlong)(int)uVar8 * 2);
      *psVar2 = *psVar2 + -1;
      psVar2 = (short *)(param_3 + 0xb88 + (longlong)(int)(uVar8 + 1) * 2);
      *psVar2 = *psVar2 + 2;
      psVar2 = (short *)(param_3 + param_4 * 2 + 0xb88);
      *psVar2 = *psVar2 + -1;
    } while (0 < in_R10D);
    if (iVar12 != 0) {
      lVar16 = (longlong)(param_1 + iVar10);
      do {
        uVar13 = (uint)param_4;
        uVar3 = *(ushort *)(param_3 + 0xb88 + (longlong)(int)uVar13 * 2);
        uVar8 = (uint)uVar3;
        if (uVar3 != 0) {
          lVar14 = param_3 + 0xba8 + lVar16 * 4;
          do {
            iVar10 = *(int *)(lVar14 + -4);
            lVar14 = lVar14 + -4;
            lVar16 = lVar16 + -1;
            if (iVar10 <= unaff_EBX) {
              puVar1 = (ushort *)(unaff_RSI + (longlong)iVar10 * 4);
              uVar6 = (uint)*(ushort *)(unaff_RSI + 2 + (longlong)iVar10 * 4);
              if (uVar6 != uVar13) {
                *(int *)(param_3 + 0x1700) =
                     *(int *)(param_3 + 0x1700) + (uVar13 - uVar6) * (uint)*puVar1;
                puVar1[1] = (ushort)param_4;
              }
              uVar8 = uVar8 - 1;
            }
          } while (uVar8 != 0);
        }
        param_4 = (ulonglong)(uVar13 - 1);
      } while (uVar13 - 1 != 0);
    }
  }
  return;
}

/* ---- FUNC 0004D31C FUN_18004d31c (231 bytes) ---- */

void FUN_18004d31c(undefined8 param_1,undefined8 param_2,longlong param_3,ulonglong param_4,
                  undefined8 param_5,int param_6)

{
  ushort *puVar1;
  short *psVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  int unaff_EBX;
  longlong unaff_RSI;
  uint uVar9;
  int in_R10D;
  longlong lVar10;
  longlong lVar11;
  
  uVar9 = (int)param_4 - 1;
  do {
    uVar8 = (ulonglong)(int)uVar9;
    sVar3 = *(short *)(param_3 + 0xb88 + uVar8 * 2);
    uVar7 = uVar9;
    while (sVar3 == 0) {
      uVar7 = (int)uVar8 - 1;
      uVar8 = (ulonglong)uVar7;
      sVar3 = *(short *)(param_3 + 0xb88 + (longlong)(int)uVar7 * 2);
    }
    in_R10D = in_R10D + -2;
    psVar2 = (short *)(param_3 + 0xb88 + (longlong)(int)uVar7 * 2);
    *psVar2 = *psVar2 + -1;
    psVar2 = (short *)(param_3 + 0xb88 + (longlong)(int)(uVar7 + 1) * 2);
    *psVar2 = *psVar2 + 2;
    psVar2 = (short *)(param_3 + param_4 * 2 + 0xb88);
    *psVar2 = *psVar2 + -1;
  } while (0 < in_R10D);
  if ((int)param_4 != 0) {
    lVar11 = (longlong)param_6;
    do {
      uVar7 = (uint)param_4;
      uVar4 = *(ushort *)(param_3 + 0xb88 + (longlong)(int)uVar7 * 2);
      uVar9 = (uint)uVar4;
      if (uVar4 != 0) {
        lVar10 = param_3 + 0xba8 + lVar11 * 4;
        do {
          iVar5 = *(int *)(lVar10 + -4);
          lVar10 = lVar10 + -4;
          lVar11 = lVar11 + -1;
          if (iVar5 <= unaff_EBX) {
            puVar1 = (ushort *)(unaff_RSI + (longlong)iVar5 * 4);
            uVar6 = (uint)*(ushort *)(unaff_RSI + 2 + (longlong)iVar5 * 4);
            if (uVar6 != uVar7) {
              *(int *)(param_3 + 0x1700) =
                   *(int *)(param_3 + 0x1700) + (uVar7 - uVar6) * (uint)*puVar1;
              puVar1[1] = (ushort)param_4;
            }
            uVar9 = uVar9 - 1;
          }
        } while (uVar9 != 0);
      }
      param_4 = (ulonglong)(uVar7 - 1);
    } while (uVar7 - 1 != 0);
  }
  return;
}

/* ---- FUNC 0004D410 FUN_18004d410 (142 bytes) ---- */

void FUN_18004d410(longlong param_1,int param_2,longlong param_3)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
  ushort local_28 [16];
  
  uVar4 = 0;
  lVar6 = 1;
  uVar5 = uVar4;
  do {
    uVar3 = ((int)uVar5 + (uint)*(ushort *)(param_3 + -2 + lVar6 * 2)) * 2;
    uVar5 = (ulonglong)uVar3;
    local_28[lVar6] = (ushort)uVar3;
    lVar6 = lVar6 + 1;
  } while (lVar6 < 0x10);
  if (-1 < param_2) {
    do {
      uVar1 = *(ushort *)(param_1 + 2 + uVar4 * 4);
      if (uVar1 != 0) {
        uVar2 = local_28[uVar1];
        local_28[uVar1] = uVar2 + 1;
        uVar3 = FUN_18004c9a0((uint)uVar2,(uint)uVar1);
        *(short *)(param_1 + uVar4 * 4) = (short)uVar3;
      }
      uVar4 = uVar4 + 1;
    } while ((longlong)uVar4 <= (longlong)param_2);
  }
  return;
}

/* ---- FUNC 0004D4A0 FUN_18004d4a0 (128 bytes) ---- */

void FUN_18004d4a0(longlong param_1)

{
  undefined2 *puVar1;
  longlong lVar2;
  
  puVar1 = (undefined2 *)(param_1 + 0xbc);
  lVar2 = 0x11e;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 2;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  puVar1 = (undefined2 *)(param_1 + 0x9b0);
  lVar2 = 0x1e;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 2;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  puVar1 = (undefined2 *)(param_1 + 0xaa4);
  lVar2 = 0x13;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 2;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  *(undefined8 *)(param_1 + 0x1700) = 0;
  *(undefined2 *)(param_1 + 0x4bc) = 1;
  *(undefined4 *)(param_1 + 0x1708) = 0;
  *(undefined4 *)(param_1 + 0x16f4) = 0;
  return;
}

/* ---- FUNC 0004D520 FUN_18004d520 (39 bytes) ---- */

void FUN_18004d520(longlong param_1,longlong param_2,longlong param_3)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  longlong lVar9;
  bool bVar10;
  
  iVar6 = (int)param_3;
  iVar8 = iVar6 * 2;
  iVar3 = *(int *)(param_1 + 0xba8 + (longlong)iVar6 * 4);
  iVar4 = *(int *)(param_1 + 0x149c);
  bVar10 = SBORROW4(iVar8,iVar4);
  iVar7 = iVar8 - iVar4;
  if (iVar4 < iVar8) {
    *(int *)(param_1 + 0xba8 + (longlong)iVar6 * 4) = iVar3;
    return;
  }
  while( true ) {
    if (bVar10 != iVar7 < 0) {
      lVar9 = (longlong)*(int *)(param_1 + 0xba8 + (longlong)(iVar8 + 1) * 4);
      lVar5 = (longlong)*(int *)(param_1 + 0xba8 + (longlong)iVar8 * 4);
      uVar1 = *(ushort *)(param_2 + lVar9 * 4);
      uVar2 = *(ushort *)(param_2 + lVar5 * 4);
      if ((uVar1 < uVar2) ||
         ((uVar1 == uVar2 &&
          (*(byte *)(lVar9 + 0x14a4 + param_1) <= *(byte *)(lVar5 + 0x14a4 + param_1))))) {
        iVar8 = iVar8 + 1;
      }
    }
    iVar4 = *(int *)(param_1 + 0xba8 + (longlong)iVar8 * 4);
    uVar1 = *(ushort *)(param_2 + (longlong)iVar3 * 4);
    uVar2 = *(ushort *)(param_2 + (longlong)iVar4 * 4);
    iVar7 = (int)param_3;
    if ((uVar1 < uVar2) ||
       ((uVar1 == uVar2 &&
        (*(byte *)(param_1 + 0x14a4 + (longlong)iVar3) <=
         *(byte *)((longlong)iVar4 + 0x14a4 + param_1))))) break;
    param_3 = (longlong)iVar8;
    iVar8 = iVar8 * 2;
    *(int *)(param_1 + 0xba8 + (longlong)iVar7 * 4) = iVar4;
    iVar4 = *(int *)(param_1 + 0x149c);
    bVar10 = SBORROW4(iVar8,iVar4);
    iVar7 = iVar8 - iVar4;
    if (iVar4 < iVar8) {
      *(int *)(param_1 + 0xba8 + param_3 * 4) = iVar3;
      return;
    }
  }
  *(int *)(param_1 + 0xba8 + (longlong)iVar7 * 4) = iVar3;
  return;
}

/* ---- FUNC 0004D547 FUN_18004d547 (182 bytes) ---- */

void FUN_18004d547(longlong param_1,undefined8 param_2,longlong param_3,int param_4)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  longlong lVar4;
  longlong unaff_RSI;
  longlong unaff_RDI;
  int iVar5;
  longlong lVar6;
  char in_SF;
  char in_OF;
  
  while( true ) {
    if (in_OF != in_SF) {
      lVar6 = (longlong)*(int *)(param_1 + 0xba8 + (longlong)(param_4 + 1) * 4);
      lVar4 = (longlong)*(int *)(param_1 + 0xba8 + (longlong)param_4 * 4);
      uVar1 = *(ushort *)(unaff_RDI + lVar6 * 4);
      uVar2 = *(ushort *)(unaff_RDI + lVar4 * 4);
      if ((uVar1 < uVar2) ||
         ((uVar1 == uVar2 &&
          (*(byte *)(lVar6 + 0x14a4 + param_1) <= *(byte *)(lVar4 + 0x14a4 + param_1))))) {
        param_4 = param_4 + 1;
      }
    }
    iVar3 = *(int *)(param_1 + 0xba8 + (longlong)param_4 * 4);
    uVar1 = *(ushort *)(unaff_RDI + unaff_RSI * 4);
    uVar2 = *(ushort *)(unaff_RDI + (longlong)iVar3 * 4);
    iVar5 = (int)param_3;
    if ((uVar1 < uVar2) ||
       ((uVar1 == uVar2 &&
        (*(byte *)(param_1 + 0x14a4 + unaff_RSI) <= *(byte *)((longlong)iVar3 + 0x14a4 + param_1))))
       ) break;
    param_3 = (longlong)param_4;
    param_4 = param_4 * 2;
    *(int *)(param_1 + 0xba8 + (longlong)iVar5 * 4) = iVar3;
    iVar3 = *(int *)(param_1 + 0x149c);
    in_OF = SBORROW4(param_4,iVar3);
    in_SF = param_4 - iVar3 < 0;
    if (iVar3 < param_4) {
      *(int *)(param_1 + 0xba8 + param_3 * 4) = (int)unaff_RSI;
      return;
    }
  }
  *(int *)(param_1 + 0xba8 + (longlong)iVar5 * 4) = (int)unaff_RSI;
  return;
}

/* ---- FUNC 0004D5FD FUN_18004d5fd (27 bytes) ---- */

void FUN_18004d5fd(longlong param_1,undefined8 param_2,int param_3)

{
  undefined4 unaff_ESI;
  
  *(undefined4 *)(param_1 + 0xba8 + (longlong)param_3 * 4) = unaff_ESI;
  return;
}

/* ---- FUNC 0004D618 FUN_18004d618 (17 bytes) ---- */

void FUN_18004d618(longlong param_1,undefined8 param_2,int param_3)

{
  undefined4 unaff_ESI;
  
  *(undefined4 *)(param_1 + 0xba8 + (longlong)param_3 * 4) = unaff_ESI;
  return;
}

/* ---- FUNC 0004D630 FUN_18004d630 (82 bytes) ---- */

void FUN_18004d630(longlong param_1,longlong param_2,int param_3)

{
  short *psVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  ushort *puVar10;
  longlong lVar11;
  
  uVar2 = *(ushort *)(param_2 + 2);
  uVar6 = 0xffffffff;
  iVar8 = 0;
  *(undefined2 *)(param_2 + 2 + (longlong)(param_3 + 1) * 4) = 0xffff;
  iVar5 = 0x8a;
  if (uVar2 != 0) {
    iVar5 = 7;
  }
  iVar4 = (uVar2 != 0) + 3;
  if (-1 < param_3) {
    puVar10 = (ushort *)(param_2 + 6);
    lVar11 = (longlong)param_3 + 1;
    do {
      iVar8 = iVar8 + 1;
      uVar3 = *puVar10;
      uVar7 = (uint)uVar2;
      uVar9 = (uint)uVar3;
      if ((iVar5 <= iVar8) || (uVar7 != uVar9)) {
        if (iVar8 < iVar4) {
          psVar1 = (short *)(param_1 + 0xaa4 + (ulonglong)uVar2 * 4);
          *psVar1 = *psVar1 + (short)iVar8;
        }
        else if (uVar7 == 0) {
          if (iVar8 < 0xb) {
            *(short *)(param_1 + 0xae8) = *(short *)(param_1 + 0xae8) + 1;
          }
          else {
            *(short *)(param_1 + 0xaec) = *(short *)(param_1 + 0xaec) + 1;
          }
        }
        else {
          if (uVar7 != uVar6) {
            psVar1 = (short *)(param_1 + 0xaa4 + (ulonglong)uVar2 * 4);
            *psVar1 = *psVar1 + 1;
          }
          *(short *)(param_1 + 0xae4) = *(short *)(param_1 + 0xae4) + 1;
        }
        iVar8 = 0;
        uVar6 = uVar7;
        if (uVar9 == 0) {
          iVar4 = 3;
          iVar8 = 0;
          iVar5 = 0x8a;
        }
        else if (uVar7 == uVar9) {
          iVar4 = 3;
          iVar8 = 0;
          iVar5 = 6;
        }
        else {
          iVar4 = 4;
          iVar5 = 7;
        }
      }
      puVar10 = puVar10 + 2;
      lVar11 = lVar11 + -1;
      uVar2 = uVar3;
    } while (lVar11 != 0);
  }
  return;
}

/* ---- FUNC 0004D682 FUN_18004d682 (227 bytes) ---- */

void FUN_18004d682(longlong param_1,int param_2,undefined8 param_3,longlong param_4)

{
  short *psVar1;
  ushort uVar2;
  int in_EAX;
  longlong unaff_RBX;
  uint unaff_EBP;
  int in_R10D;
  uint in_R11D;
  uint uVar3;
  int unaff_R13D;
  ushort *puVar4;
  
  puVar4 = (ushort *)(unaff_RBX + 6);
  param_4 = param_4 + 1;
  do {
    in_R10D = in_R10D + 1;
    uVar2 = *puVar4;
    uVar3 = (uint)uVar2;
    if ((param_2 <= in_R10D) || (in_R11D != uVar3)) {
      if (in_R10D < in_EAX) {
        psVar1 = (short *)(param_1 + 0xaa4 + (ulonglong)in_R11D * 4);
        *psVar1 = *psVar1 + (short)in_R10D;
      }
      else if (in_R11D == 0) {
        if (in_R10D < 0xb) {
          *(short *)(param_1 + 0xae8) = *(short *)(param_1 + 0xae8) + 1;
        }
        else {
          *(short *)(param_1 + 0xaec) = *(short *)(param_1 + 0xaec) + 1;
        }
      }
      else {
        if (in_R11D != unaff_EBP) {
          psVar1 = (short *)(param_1 + 0xaa4 + (ulonglong)in_R11D * 4);
          *psVar1 = *psVar1 + 1;
        }
        *(short *)(param_1 + 0xae4) = *(short *)(param_1 + 0xae4) + 1;
      }
      in_R10D = 0;
      unaff_EBP = in_R11D;
      if (uVar3 == 0) {
        in_EAX = 3;
        in_R10D = 0;
        param_2 = 0x8a;
      }
      else if (in_R11D == uVar3) {
        in_EAX = 3;
        in_R10D = 0;
        param_2 = 6;
      }
      else {
        in_EAX = 4;
        param_2 = unaff_R13D;
      }
    }
    puVar4 = puVar4 + 2;
    param_4 = param_4 + -1;
    in_R11D = (uint)uVar2;
  } while (param_4 != 0);
  return;
}

/* ---- FUNC 0004D765 FUN_18004d765 (9 bytes) ---- */

void FUN_18004d765(void)

{
  return;
}

/* ---- FUNC 0004D770 FUN_18004d770 (635 bytes) ---- */

void FUN_18004d770(longlong param_1,int param_2,int param_3,uint param_4)

{
  char cVar1;
  int iVar2;
  ushort uVar3;
  byte *pbVar4;
  ulonglong uVar5;
  
  uVar5 = (ulonglong)param_4;
  iVar2 = *(int *)(param_1 + 0x1714);
  if (iVar2 < 0xc) {
    *(ushort *)(param_1 + 0x1710) =
         *(ushort *)(param_1 + 0x1710) | (short)param_2 + -0x101 << ((byte)iVar2 & 0x1f);
    *(int *)(param_1 + 0x1714) = iVar2 + 5;
  }
  else {
    uVar3 = (short)param_2 - 0x101;
    *(ushort *)(param_1 + 0x1710) = *(ushort *)(param_1 + 0x1710) | uVar3 << ((byte)iVar2 & 0x1f);
    *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
         *(undefined1 *)(param_1 + 0x1710);
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
    *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
         *(undefined1 *)(param_1 + 0x1711);
    cVar1 = *(char *)(param_1 + 0x1714);
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
    *(int *)(param_1 + 0x1714) = *(int *)(param_1 + 0x1714) + -0xb;
    *(ushort *)(param_1 + 0x1710) = uVar3 >> (0x10U - cVar1 & 0x1f);
  }
  iVar2 = *(int *)(param_1 + 0x1714);
  if (iVar2 < 0xc) {
    *(ushort *)(param_1 + 0x1710) =
         *(ushort *)(param_1 + 0x1710) | (short)param_3 + -1 << ((byte)iVar2 & 0x1f);
    *(int *)(param_1 + 0x1714) = iVar2 + 5;
  }
  else {
    uVar3 = (short)param_3 - 1;
    *(ushort *)(param_1 + 0x1710) = *(ushort *)(param_1 + 0x1710) | uVar3 << ((byte)iVar2 & 0x1f);
    *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
         *(undefined1 *)(param_1 + 0x1710);
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
    *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
         *(undefined1 *)(param_1 + 0x1711);
    cVar1 = *(char *)(param_1 + 0x1714);
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
    *(int *)(param_1 + 0x1714) = *(int *)(param_1 + 0x1714) + -0xb;
    *(ushort *)(param_1 + 0x1710) = uVar3 >> (0x10U - cVar1 & 0x1f);
  }
  iVar2 = *(int *)(param_1 + 0x1714);
  if (iVar2 < 0xd) {
    *(ushort *)(param_1 + 0x1710) =
         *(ushort *)(param_1 + 0x1710) | (short)param_4 + -4 << ((byte)iVar2 & 0x1f);
    *(int *)(param_1 + 0x1714) = iVar2 + 4;
  }
  else {
    uVar3 = (short)param_4 - 4;
    *(ushort *)(param_1 + 0x1710) = *(ushort *)(param_1 + 0x1710) | uVar3 << ((byte)iVar2 & 0x1f);
    *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
         *(undefined1 *)(param_1 + 0x1710);
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
    *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
         *(undefined1 *)(param_1 + 0x1711);
    cVar1 = *(char *)(param_1 + 0x1714);
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
    *(int *)(param_1 + 0x1714) = *(int *)(param_1 + 0x1714) + -0xc;
    *(ushort *)(param_1 + 0x1710) = uVar3 >> (0x10U - cVar1 & 0x1f);
  }
  if (0 < (int)param_4) {
    pbVar4 = &DAT_18005b118;
    do {
      iVar2 = *(int *)(param_1 + 0x1714);
      if (iVar2 < 0xe) {
        *(ushort *)(param_1 + 0x1710) =
             *(ushort *)(param_1 + 0x1710) |
             *(short *)(param_1 + 0xaa6 + (ulonglong)*pbVar4 * 4) << ((byte)iVar2 & 0x1f);
        *(int *)(param_1 + 0x1714) = iVar2 + 3;
      }
      else {
        uVar3 = *(ushort *)(param_1 + 0xaa6 + (ulonglong)*pbVar4 * 4);
        *(ushort *)(param_1 + 0x1710) =
             *(ushort *)(param_1 + 0x1710) | uVar3 << ((byte)iVar2 & 0x1f);
        *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
             *(undefined1 *)(param_1 + 0x1710);
        *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
        *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
             *(undefined1 *)(param_1 + 0x1711);
        cVar1 = *(char *)(param_1 + 0x1714);
        *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
        *(int *)(param_1 + 0x1714) = *(int *)(param_1 + 0x1714) + -0xd;
        *(ushort *)(param_1 + 0x1710) = uVar3 >> (0x10U - cVar1 & 0x1f);
      }
      pbVar4 = pbVar4 + 1;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  FUN_18004d9f0(param_1,param_1 + 0xbc,param_2 + -1);
  FUN_18004d9f0(param_1,param_1 + 0x9b0,param_3 + -1);
  return;
}

/* ---- FUNC 0004D9F0 FUN_18004d9f0 (59 bytes) ---- */

void FUN_18004d9f0(longlong param_1,longlong param_2,int param_3)

{
  longlong lVar1;
  char cVar2;
  ushort uVar3;
  ushort uVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  ushort uVar8;
  uint uVar9;
  uint uVar10;
  ulonglong uVar11;
  uint uVar12;
  short sVar13;
  int iVar14;
  longlong lVar16;
  ushort *puVar17;
  int iVar15;
  
  uVar8 = *(ushort *)(param_2 + 2);
  uVar12 = 0xffffffff;
  iVar15 = 0;
  iVar7 = 0x8a;
  if (uVar8 != 0) {
    iVar7 = 7;
  }
  iVar6 = (uVar8 != 0) + 3;
  if (-1 < (longlong)param_3) {
    lVar16 = (longlong)param_3 + 1;
    puVar17 = (ushort *)(param_2 + 6);
    do {
      uVar11 = (ulonglong)uVar8;
      iVar14 = iVar15 + 1;
      uVar3 = *puVar17;
      uVar10 = (uint)uVar3;
      uVar9 = (uint)uVar8;
      if ((iVar7 <= iVar14) || (uVar9 != uVar10)) {
        if (iVar14 < iVar6) {
          lVar1 = param_1 + uVar11 * 4;
          do {
            uVar8 = *(ushort *)(param_1 + uVar11 * 4 + 0xaa6);
            iVar7 = *(int *)(param_1 + 0x1714);
            if ((int)(0x10 - (uint)uVar8) < iVar7) {
              uVar4 = *(ushort *)(lVar1 + 0xaa4);
              *(ushort *)(param_1 + 0x1710) =
                   *(ushort *)(param_1 + 0x1710) | uVar4 << ((byte)iVar7 & 0x1f);
              *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10))
                   = *(undefined1 *)(param_1 + 0x1710);
              *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
              *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10))
                   = *(undefined1 *)(param_1 + 0x1711);
              cVar2 = *(char *)(param_1 + 0x1714);
              *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
              *(int *)(param_1 + 0x1714) = *(int *)(param_1 + 0x1714) + (uVar8 - 0x10);
              *(ushort *)(param_1 + 0x1710) = uVar4 >> (0x10U - cVar2 & 0x1f);
            }
            else {
              *(ushort *)(param_1 + 0x1710) =
                   *(ushort *)(param_1 + 0x1710) | *(short *)(lVar1 + 0xaa4) << ((byte)iVar7 & 0x1f)
              ;
              *(uint *)(param_1 + 0x1714) = iVar7 + (uint)uVar8;
            }
            iVar14 = iVar14 + -1;
          } while (iVar14 != 0);
        }
        else if (uVar9 == 0) {
          iVar7 = *(int *)(param_1 + 0x1714);
          sVar13 = (short)iVar14;
          bVar5 = (byte)iVar7;
          if (iVar14 < 0xb) {
            uVar8 = *(ushort *)(param_1 + 0xaea);
            if ((int)(0x10 - (uint)uVar8) < iVar7) {
              uVar4 = *(ushort *)(param_1 + 0xae8);
              *(ushort *)(param_1 + 0x1710) =
                   *(ushort *)(param_1 + 0x1710) | uVar4 << (bVar5 & 0x1f);
              *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10))
                   = *(undefined1 *)(param_1 + 0x1710);
              *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
              *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10))
                   = *(undefined1 *)(param_1 + 0x1711);
              cVar2 = *(char *)(param_1 + 0x1714);
              *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
              *(int *)(param_1 + 0x1714) = *(int *)(param_1 + 0x1714) + (uVar8 - 0x10);
              *(ushort *)(param_1 + 0x1710) = uVar4 >> (0x10U - cVar2 & 0x1f);
            }
            else {
              *(ushort *)(param_1 + 0x1710) =
                   *(ushort *)(param_1 + 0x1710) | *(short *)(param_1 + 0xae8) << (bVar5 & 0x1f);
              *(uint *)(param_1 + 0x1714) = iVar7 + (uint)uVar8;
            }
            iVar7 = *(int *)(param_1 + 0x1714);
            if (iVar7 < 0xe) {
              *(ushort *)(param_1 + 0x1710) =
                   *(ushort *)(param_1 + 0x1710) | sVar13 + -3 << ((byte)iVar7 & 0x1f);
              iVar7 = iVar7 + 3;
LAB_18004df4d:
              *(int *)(param_1 + 0x1714) = iVar7;
            }
            else {
              *(ushort *)(param_1 + 0x1710) =
                   *(ushort *)(param_1 + 0x1710) | sVar13 - 3U << ((byte)iVar7 & 0x1f);
              *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10))
                   = *(undefined1 *)(param_1 + 0x1710);
              *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
              *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10))
                   = *(undefined1 *)(param_1 + 0x1711);
              cVar2 = *(char *)(param_1 + 0x1714);
              *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
              *(int *)(param_1 + 0x1714) = *(int *)(param_1 + 0x1714) + -0xd;
              *(ushort *)(param_1 + 0x1710) = (ushort)(sVar13 - 3U) >> (0x10U - cVar2 & 0x1f);
            }
          }
          else {
            uVar8 = *(ushort *)(param_1 + 0xaee);
            if ((int)(0x10 - (uint)uVar8) < iVar7) {
              uVar4 = *(ushort *)(param_1 + 0xaec);
              *(ushort *)(param_1 + 0x1710) =
                   *(ushort *)(param_1 + 0x1710) | uVar4 << (bVar5 & 0x1f);
              *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10))
                   = *(undefined1 *)(param_1 + 0x1710);
              *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
              *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10))
                   = *(undefined1 *)(param_1 + 0x1711);
              cVar2 = *(char *)(param_1 + 0x1714);
              *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
              *(int *)(param_1 + 0x1714) = *(int *)(param_1 + 0x1714) + (uVar8 - 0x10);
              *(ushort *)(param_1 + 0x1710) = uVar4 >> (0x10U - cVar2 & 0x1f);
            }
            else {
              *(ushort *)(param_1 + 0x1710) =
                   *(ushort *)(param_1 + 0x1710) | *(short *)(param_1 + 0xaec) << (bVar5 & 0x1f);
              *(uint *)(param_1 + 0x1714) = iVar7 + (uint)uVar8;
            }
            iVar7 = *(int *)(param_1 + 0x1714);
            if (iVar7 < 10) {
              *(ushort *)(param_1 + 0x1710) =
                   *(ushort *)(param_1 + 0x1710) | sVar13 + -0xb << ((byte)iVar7 & 0x1f);
              iVar7 = iVar7 + 7;
              goto LAB_18004df4d;
            }
            *(ushort *)(param_1 + 0x1710) =
                 *(ushort *)(param_1 + 0x1710) | sVar13 - 0xbU << ((byte)iVar7 & 0x1f);
            *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
                 *(undefined1 *)(param_1 + 0x1710);
            *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
            *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
                 *(undefined1 *)(param_1 + 0x1711);
            cVar2 = *(char *)(param_1 + 0x1714);
            *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
            *(int *)(param_1 + 0x1714) = *(int *)(param_1 + 0x1714) + -9;
            *(ushort *)(param_1 + 0x1710) = (ushort)(sVar13 - 0xbU) >> (0x10U - cVar2 & 0x1f);
          }
        }
        else {
          if (uVar9 != uVar12) {
            uVar8 = *(ushort *)(param_1 + 0xaa6 + uVar11 * 4);
            iVar7 = *(int *)(param_1 + 0x1714);
            iVar14 = iVar15;
            if ((int)(0x10 - (uint)uVar8) < iVar7) {
              uVar4 = *(ushort *)(param_1 + 0xaa4 + uVar11 * 4);
              *(ushort *)(param_1 + 0x1710) =
                   *(ushort *)(param_1 + 0x1710) | uVar4 << ((byte)iVar7 & 0x1f);
              *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10))
                   = *(undefined1 *)(param_1 + 0x1710);
              *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
              *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10))
                   = *(undefined1 *)(param_1 + 0x1711);
              cVar2 = *(char *)(param_1 + 0x1714);
              *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
              *(int *)(param_1 + 0x1714) = *(int *)(param_1 + 0x1714) + (uVar8 - 0x10);
              *(ushort *)(param_1 + 0x1710) = uVar4 >> (0x10U - cVar2 & 0x1f);
            }
            else {
              *(ushort *)(param_1 + 0x1710) =
                   *(ushort *)(param_1 + 0x1710) |
                   *(short *)(param_1 + 0xaa4 + uVar11 * 4) << ((byte)iVar7 & 0x1f);
              *(uint *)(param_1 + 0x1714) = iVar7 + (uint)uVar8;
            }
          }
          uVar8 = *(ushort *)(param_1 + 0xae6);
          iVar7 = *(int *)(param_1 + 0x1714);
          if ((int)(0x10 - (uint)uVar8) < iVar7) {
            uVar4 = *(ushort *)(param_1 + 0xae4);
            *(ushort *)(param_1 + 0x1710) =
                 *(ushort *)(param_1 + 0x1710) | uVar4 << ((byte)iVar7 & 0x1f);
            *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
                 *(undefined1 *)(param_1 + 0x1710);
            *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
            *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
                 *(undefined1 *)(param_1 + 0x1711);
            cVar2 = *(char *)(param_1 + 0x1714);
            *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
            *(int *)(param_1 + 0x1714) = *(int *)(param_1 + 0x1714) + (uVar8 - 0x10);
            *(ushort *)(param_1 + 0x1710) = uVar4 >> (0x10U - cVar2 & 0x1f);
          }
          else {
            *(ushort *)(param_1 + 0x1710) =
                 *(ushort *)(param_1 + 0x1710) | *(short *)(param_1 + 0xae4) << ((byte)iVar7 & 0x1f)
            ;
            *(uint *)(param_1 + 0x1714) = iVar7 + (uint)uVar8;
          }
          iVar7 = *(int *)(param_1 + 0x1714);
          if (iVar7 < 0xf) {
            *(ushort *)(param_1 + 0x1710) =
                 *(ushort *)(param_1 + 0x1710) | (short)iVar14 + -3 << ((byte)iVar7 & 0x1f);
            iVar7 = iVar7 + 2;
            goto LAB_18004df4d;
          }
          uVar8 = (short)iVar14 - 3;
          *(ushort *)(param_1 + 0x1710) =
               *(ushort *)(param_1 + 0x1710) | uVar8 << ((byte)iVar7 & 0x1f);
          *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
               *(undefined1 *)(param_1 + 0x1710);
          *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
          *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x10)) =
               *(undefined1 *)(param_1 + 0x1711);
          cVar2 = *(char *)(param_1 + 0x1714);
          *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
          *(int *)(param_1 + 0x1714) = *(int *)(param_1 + 0x1714) + -0xe;
          *(ushort *)(param_1 + 0x1710) = uVar8 >> (0x10U - cVar2 & 0x1f);
        }
        uVar12 = uVar9;
        iVar14 = 0;
        if (uVar10 == 0) {
          iVar6 = uVar3 + 3;
          iVar7 = 0x8a;
        }
        else if (uVar9 == uVar10) {
          iVar6 = 3;
          iVar7 = 6;
        }
        else {
          iVar6 = 4;
          iVar7 = 7;
          iVar14 = 0;
        }
      }
      iVar15 = iVar14;
      puVar17 = puVar17 + 2;
      lVar16 = lVar16 + -1;
      uVar8 = uVar3;
    } while (lVar16 != 0);
  }
  return;
}

/* ---- FUNC 0004DA2B FUN_18004da2b (1414 bytes) ---- */

void FUN_18004da2b(int param_1,longlong param_2,int param_3,uint param_4)

{
  longlong lVar1;
  char cVar2;
  ushort uVar3;
  ushort uVar4;
  longlong in_RAX;
  byte bVar5;
  int iVar6;
  ushort uVar7;
  uint unaff_EDI;
  uint uVar8;
  short sVar9;
  int in_R10D;
  int iVar10;
  longlong in_R11;
  longlong lVar11;
  ushort *puVar12;
  
  lVar11 = in_R11 + 1;
  puVar12 = (ushort *)(param_2 + 6);
  do {
    iVar10 = in_R10D + 1;
    uVar3 = *puVar12;
    uVar8 = (uint)uVar3;
    if ((param_3 <= iVar10) || (unaff_EDI != uVar8)) {
      if (iVar10 < param_1) {
        lVar1 = in_RAX + (ulonglong)unaff_EDI * 4;
        do {
          uVar7 = *(ushort *)(in_RAX + (ulonglong)unaff_EDI * 4 + 0xaa6);
          iVar6 = *(int *)(in_RAX + 0x1714);
          if ((int)(0x10 - (uint)uVar7) < iVar6) {
            uVar4 = *(ushort *)(lVar1 + 0xaa4);
            *(ushort *)(in_RAX + 0x1710) =
                 *(ushort *)(in_RAX + 0x1710) | uVar4 << ((byte)iVar6 & 0x1f);
            *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
                 *(undefined1 *)(in_RAX + 0x1710);
            *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
            *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
                 *(undefined1 *)(in_RAX + 0x1711);
            cVar2 = *(char *)(in_RAX + 0x1714);
            *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
            *(int *)(in_RAX + 0x1714) = *(int *)(in_RAX + 0x1714) + (uVar7 - 0x10);
            *(ushort *)(in_RAX + 0x1710) = uVar4 >> (0x10U - cVar2 & 0x1f);
          }
          else {
            *(ushort *)(in_RAX + 0x1710) =
                 *(ushort *)(in_RAX + 0x1710) | *(short *)(lVar1 + 0xaa4) << ((byte)iVar6 & 0x1f);
            *(uint *)(in_RAX + 0x1714) = iVar6 + (uint)uVar7;
          }
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
      }
      else if (unaff_EDI == 0) {
        iVar6 = *(int *)(in_RAX + 0x1714);
        sVar9 = (short)iVar10;
        bVar5 = (byte)iVar6;
        if (iVar10 < 0xb) {
          uVar7 = *(ushort *)(in_RAX + 0xaea);
          if ((int)(0x10 - (uint)uVar7) < iVar6) {
            uVar4 = *(ushort *)(in_RAX + 0xae8);
            *(ushort *)(in_RAX + 0x1710) = *(ushort *)(in_RAX + 0x1710) | uVar4 << (bVar5 & 0x1f);
            *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
                 *(undefined1 *)(in_RAX + 0x1710);
            *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
            *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
                 *(undefined1 *)(in_RAX + 0x1711);
            cVar2 = *(char *)(in_RAX + 0x1714);
            *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
            *(int *)(in_RAX + 0x1714) = *(int *)(in_RAX + 0x1714) + (uVar7 - 0x10);
            *(ushort *)(in_RAX + 0x1710) = uVar4 >> (0x10U - cVar2 & 0x1f);
          }
          else {
            *(ushort *)(in_RAX + 0x1710) =
                 *(ushort *)(in_RAX + 0x1710) | *(short *)(in_RAX + 0xae8) << (bVar5 & 0x1f);
            *(uint *)(in_RAX + 0x1714) = iVar6 + (uint)uVar7;
          }
          iVar6 = *(int *)(in_RAX + 0x1714);
          if (iVar6 < 0xe) {
            *(ushort *)(in_RAX + 0x1710) =
                 *(ushort *)(in_RAX + 0x1710) | sVar9 + -3 << ((byte)iVar6 & 0x1f);
            iVar6 = iVar6 + 3;
LAB_18004df4d:
            *(int *)(in_RAX + 0x1714) = iVar6;
          }
          else {
            *(ushort *)(in_RAX + 0x1710) =
                 *(ushort *)(in_RAX + 0x1710) | sVar9 - 3U << ((byte)iVar6 & 0x1f);
            *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
                 *(undefined1 *)(in_RAX + 0x1710);
            *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
            *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
                 *(undefined1 *)(in_RAX + 0x1711);
            cVar2 = *(char *)(in_RAX + 0x1714);
            *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
            *(int *)(in_RAX + 0x1714) = *(int *)(in_RAX + 0x1714) + -0xd;
            *(ushort *)(in_RAX + 0x1710) = (ushort)(sVar9 - 3U) >> (0x10U - cVar2 & 0x1f);
          }
        }
        else {
          uVar7 = *(ushort *)(in_RAX + 0xaee);
          if ((int)(0x10 - (uint)uVar7) < iVar6) {
            uVar4 = *(ushort *)(in_RAX + 0xaec);
            *(ushort *)(in_RAX + 0x1710) = *(ushort *)(in_RAX + 0x1710) | uVar4 << (bVar5 & 0x1f);
            *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
                 *(undefined1 *)(in_RAX + 0x1710);
            *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
            *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
                 *(undefined1 *)(in_RAX + 0x1711);
            cVar2 = *(char *)(in_RAX + 0x1714);
            *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
            *(int *)(in_RAX + 0x1714) = *(int *)(in_RAX + 0x1714) + (uVar7 - 0x10);
            *(ushort *)(in_RAX + 0x1710) = uVar4 >> (0x10U - cVar2 & 0x1f);
          }
          else {
            *(ushort *)(in_RAX + 0x1710) =
                 *(ushort *)(in_RAX + 0x1710) | *(short *)(in_RAX + 0xaec) << (bVar5 & 0x1f);
            *(uint *)(in_RAX + 0x1714) = iVar6 + (uint)uVar7;
          }
          iVar6 = *(int *)(in_RAX + 0x1714);
          if (iVar6 < 10) {
            *(ushort *)(in_RAX + 0x1710) =
                 *(ushort *)(in_RAX + 0x1710) | sVar9 + -0xb << ((byte)iVar6 & 0x1f);
            iVar6 = iVar6 + 7;
            goto LAB_18004df4d;
          }
          *(ushort *)(in_RAX + 0x1710) =
               *(ushort *)(in_RAX + 0x1710) | sVar9 - 0xbU << ((byte)iVar6 & 0x1f);
          *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
               *(undefined1 *)(in_RAX + 0x1710);
          *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
          *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
               *(undefined1 *)(in_RAX + 0x1711);
          cVar2 = *(char *)(in_RAX + 0x1714);
          *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
          *(int *)(in_RAX + 0x1714) = *(int *)(in_RAX + 0x1714) + -9;
          *(ushort *)(in_RAX + 0x1710) = (ushort)(sVar9 - 0xbU) >> (0x10U - cVar2 & 0x1f);
        }
      }
      else {
        if (unaff_EDI != param_4) {
          uVar7 = *(ushort *)(in_RAX + 0xaa6 + (ulonglong)unaff_EDI * 4);
          iVar6 = *(int *)(in_RAX + 0x1714);
          iVar10 = in_R10D;
          if ((int)(0x10 - (uint)uVar7) < iVar6) {
            uVar4 = *(ushort *)(in_RAX + 0xaa4 + (ulonglong)unaff_EDI * 4);
            *(ushort *)(in_RAX + 0x1710) =
                 *(ushort *)(in_RAX + 0x1710) | uVar4 << ((byte)iVar6 & 0x1f);
            *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
                 *(undefined1 *)(in_RAX + 0x1710);
            *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
            *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
                 *(undefined1 *)(in_RAX + 0x1711);
            cVar2 = *(char *)(in_RAX + 0x1714);
            *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
            *(int *)(in_RAX + 0x1714) = *(int *)(in_RAX + 0x1714) + (uVar7 - 0x10);
            *(ushort *)(in_RAX + 0x1710) = uVar4 >> (0x10U - cVar2 & 0x1f);
          }
          else {
            *(ushort *)(in_RAX + 0x1710) =
                 *(ushort *)(in_RAX + 0x1710) |
                 *(short *)(in_RAX + 0xaa4 + (ulonglong)unaff_EDI * 4) << ((byte)iVar6 & 0x1f);
            *(uint *)(in_RAX + 0x1714) = iVar6 + (uint)uVar7;
          }
        }
        uVar7 = *(ushort *)(in_RAX + 0xae6);
        iVar6 = *(int *)(in_RAX + 0x1714);
        if ((int)(0x10 - (uint)uVar7) < iVar6) {
          uVar4 = *(ushort *)(in_RAX + 0xae4);
          *(ushort *)(in_RAX + 0x1710) =
               *(ushort *)(in_RAX + 0x1710) | uVar4 << ((byte)iVar6 & 0x1f);
          *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
               *(undefined1 *)(in_RAX + 0x1710);
          *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
          *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
               *(undefined1 *)(in_RAX + 0x1711);
          cVar2 = *(char *)(in_RAX + 0x1714);
          *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
          *(int *)(in_RAX + 0x1714) = *(int *)(in_RAX + 0x1714) + (uVar7 - 0x10);
          *(ushort *)(in_RAX + 0x1710) = uVar4 >> (0x10U - cVar2 & 0x1f);
        }
        else {
          *(ushort *)(in_RAX + 0x1710) =
               *(ushort *)(in_RAX + 0x1710) | *(short *)(in_RAX + 0xae4) << ((byte)iVar6 & 0x1f);
          *(uint *)(in_RAX + 0x1714) = iVar6 + (uint)uVar7;
        }
        iVar6 = *(int *)(in_RAX + 0x1714);
        if (iVar6 < 0xf) {
          *(ushort *)(in_RAX + 0x1710) =
               *(ushort *)(in_RAX + 0x1710) | (short)iVar10 + -3 << ((byte)iVar6 & 0x1f);
          iVar6 = iVar6 + 2;
          goto LAB_18004df4d;
        }
        uVar7 = (short)iVar10 - 3;
        *(ushort *)(in_RAX + 0x1710) = *(ushort *)(in_RAX + 0x1710) | uVar7 << ((byte)iVar6 & 0x1f);
        *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
             *(undefined1 *)(in_RAX + 0x1710);
        *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
        *(undefined1 *)((ulonglong)*(uint *)(in_RAX + 0x28) + *(longlong *)(in_RAX + 0x10)) =
             *(undefined1 *)(in_RAX + 0x1711);
        cVar2 = *(char *)(in_RAX + 0x1714);
        *(int *)(in_RAX + 0x28) = *(int *)(in_RAX + 0x28) + 1;
        *(int *)(in_RAX + 0x1714) = *(int *)(in_RAX + 0x1714) + -0xe;
        *(ushort *)(in_RAX + 0x1710) = uVar7 >> (0x10U - cVar2 & 0x1f);
      }
      param_4 = unaff_EDI;
      iVar10 = 0;
      if (uVar8 == 0) {
        param_1 = uVar3 + 3;
        param_3 = 0x8a;
      }
      else if (unaff_EDI == uVar8) {
        param_1 = 3;
        param_3 = 6;
      }
      else {
        param_1 = 4;
        param_3 = 7;
        iVar10 = 0;
      }
    }
    in_R10D = iVar10;
    puVar12 = puVar12 + 2;
    lVar11 = lVar11 + -1;
    unaff_EDI = (uint)uVar3;
    if (lVar11 == 0) {
      return;
    }
  } while( true );
}

/* ---- FUNC 0004DFB1 FUN_18004dfb1 (6 bytes) ---- */

void FUN_18004dfb1(void)

{
  return;
}

/* ---- FUNC 0004DFC0 FUN_18004dfc0 (742 bytes) ---- */

uint FUN_18004dfc0(uint param_1,byte *param_2,uint param_3)

{
  byte *pbVar1;
  byte bVar2;
  undefined1 auVar3 [16];
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  longlong lVar22;
  ulonglong uVar23;
  uint uVar24;
  ulonglong uVar25;
  
  uVar23 = CONCAT44(0,param_3);
  uVar24 = param_1 >> 0x10;
  uVar5 = param_1 & 0xffff;
  if (uVar23 == 1) {
    uVar4 = (param_1 & 0xffff) + (uint)*param_2;
    uVar5 = uVar4 - 0xfff1;
    if (uVar4 < 0xfff1) {
      uVar5 = uVar4;
    }
    uVar24 = uVar24 + uVar5;
    uVar4 = uVar24 - 0xfff1;
    if (uVar24 < 0xfff1) {
      uVar4 = uVar24;
    }
    return uVar4 << 0x10 | uVar5;
  }
  if (param_2 == (byte *)0x0) {
    return 1;
  }
  if (uVar23 < 0x10) {
    for (; uVar23 != 0; uVar23 = uVar23 - 1) {
      bVar2 = *param_2;
      param_2 = param_2 + 1;
      uVar5 = uVar5 + bVar2;
      uVar24 = uVar24 + uVar5;
    }
    uVar4 = uVar5 - 0xfff1;
    if (uVar5 < 0xfff1) {
      uVar4 = uVar5;
    }
    return ((uVar24 / 0xfff1) * 0xf + uVar24) * 0x10000 | uVar4;
  }
  if (0x15af < uVar23) {
    auVar3._8_8_ = 0;
    auVar3._0_8_ = uVar23;
    lVar22 = SUB168(ZEXT816(0x79baa6bb6398b6f7) * auVar3,8);
    uVar25 = (uVar23 - lVar22 >> 1) + lVar22 >> 0xc;
    uVar23 = uVar23 + uVar25 * -0x15b0;
    do {
      iVar21 = 0x15b;
      do {
        iVar6 = uVar5 + *param_2;
        iVar7 = iVar6 + (uint)param_2[1];
        iVar8 = iVar7 + (uint)param_2[2];
        iVar9 = iVar8 + (uint)param_2[3];
        iVar10 = iVar9 + (uint)param_2[4];
        iVar11 = iVar10 + (uint)param_2[5];
        iVar12 = iVar11 + (uint)param_2[6];
        iVar13 = iVar12 + (uint)param_2[7];
        iVar14 = iVar13 + (uint)param_2[8];
        iVar15 = iVar14 + (uint)param_2[9];
        iVar16 = iVar15 + (uint)param_2[10];
        iVar17 = iVar16 + (uint)param_2[0xb];
        iVar18 = iVar17 + (uint)param_2[0xc];
        iVar19 = iVar18 + (uint)param_2[0xd];
        iVar20 = iVar19 + (uint)param_2[0xe];
        pbVar1 = param_2 + 0xf;
        param_2 = param_2 + 0x10;
        uVar5 = iVar20 + (uint)*pbVar1;
        uVar24 = uVar24 + iVar6 + iVar7 + iVar8 + iVar9 + iVar10 + iVar11 + iVar12 + iVar13 + iVar14
                 + iVar15 + iVar16 + iVar17 + iVar18 + iVar19 + iVar20 + uVar5;
        iVar21 = iVar21 + -1;
      } while (iVar21 != 0);
      uVar5 = uVar5 % 0xfff1;
      uVar24 = uVar24 % 0xfff1;
      uVar25 = uVar25 - 1;
    } while (uVar25 != 0);
  }
  if (uVar23 != 0) {
    if (0xf < uVar23) {
      uVar25 = uVar23 >> 4;
      uVar23 = uVar23 + uVar25 * -0x10;
      do {
        iVar21 = uVar5 + *param_2;
        iVar6 = iVar21 + (uint)param_2[1];
        iVar7 = iVar6 + (uint)param_2[2];
        iVar8 = iVar7 + (uint)param_2[3];
        iVar9 = iVar8 + (uint)param_2[4];
        iVar10 = iVar9 + (uint)param_2[5];
        iVar11 = iVar10 + (uint)param_2[6];
        iVar12 = iVar11 + (uint)param_2[7];
        iVar13 = iVar12 + (uint)param_2[8];
        iVar14 = iVar13 + (uint)param_2[9];
        iVar15 = iVar14 + (uint)param_2[10];
        iVar16 = iVar15 + (uint)param_2[0xb];
        iVar17 = iVar16 + (uint)param_2[0xc];
        iVar18 = iVar17 + (uint)param_2[0xd];
        iVar19 = iVar18 + (uint)param_2[0xe];
        pbVar1 = param_2 + 0xf;
        param_2 = param_2 + 0x10;
        uVar5 = iVar19 + (uint)*pbVar1;
        uVar24 = uVar24 + iVar21 + iVar6 + iVar7 + iVar8 + iVar9 + iVar10 + iVar11 + iVar12 + iVar13
                 + iVar14 + iVar15 + iVar16 + iVar17 + iVar18 + iVar19 + uVar5;
        uVar25 = uVar25 - 1;
      } while (uVar25 != 0);
    }
    for (; uVar23 != 0; uVar23 = uVar23 - 1) {
      bVar2 = *param_2;
      param_2 = param_2 + 1;
      uVar5 = uVar5 + bVar2;
      uVar24 = uVar24 + uVar5;
    }
    uVar5 = uVar5 % 0xfff1;
    uVar24 = uVar24 % 0xfff1;
  }
  return uVar24 << 0x10 | uVar5;
}

/* ---- FUNC 0004E2B0 FUN_18004e2b0 (13 bytes) ---- */

void FUN_18004e2b0(undefined8 param_1,int param_2,int param_3)

{
                    /* WARNING: Could not recover jumptable at 0x00018004e2b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  malloc((ulonglong)(uint)(param_2 * param_3));
  return;
}

/* ---- FUNC 0004E2C0 FUN_18004e2c0 (10 bytes) ---- */

void FUN_18004e2c0(undefined8 param_1,void *param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00018004e2c3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  free(param_2);
  return;
}

/* ---- FUNC 0004E2D0 FUN_18004e2d0 (607 bytes) ---- */

ulonglong FUN_18004e2d0(longlong param_1,uint param_2)

{
  short *psVar1;
  short sVar2;
  ushort uVar3;
  longlong lVar4;
  int iVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  uint uVar8;
  longlong lVar9;
  short sVar10;
  uint uVar11;
  uint uVar12;
  longlong lVar13;
  longlong lVar14;
  int iVar15;
  ulonglong uVar16;
  
  uVar7 = (ulonglong)param_2;
  uVar11 = *(uint *)(param_1 + 0xa4);
  if (*(int *)(param_1 + 0xb4) <= *(int *)(param_1 + 0xa0)) {
    uVar11 = uVar11 >> 2;
  }
  uVar11 = (uVar11 - 1) * 0x10000 | *(uint *)(param_1 + 0x4c);
  iVar15 = *(int *)(param_1 + 0x9c);
  if (*(int *)(param_1 + 0xb8) <= *(int *)(param_1 + 0x9c)) {
    iVar15 = *(int *)(param_1 + 0xb8);
  }
  lVar4 = *(longlong *)(param_1 + 0x50);
  uVar8 = *(uint *)(param_1 + 0x94);
  psVar1 = (short *)((ulonglong)uVar8 + lVar4);
  iVar5 = *(int *)(param_1 + 0x44) + -0x106;
  uVar12 = uVar8 - iVar5;
  uVar16 = (ulonglong)*(uint *)(param_1 + 0xa0);
  if (uVar12 == 0 || (int)uVar8 < iVar5) {
    uVar12 = 0;
  }
  lVar13 = uVar16 + lVar4;
  sVar2 = *psVar1;
  sVar10 = *(short *)((uVar16 - 1) + (longlong)psVar1);
  lVar14 = *(longlong *)(param_1 + 0x60);
  uVar8 = uVar11;
  if (sVar10 == *(short *)((uVar7 - 1) + lVar13)) goto LAB_18004e41c;
LAB_18004e382:
  uVar3 = *(ushort *)(lVar14 + (ulonglong)((uint)uVar7 & uVar11) * 2);
  uVar7 = (ulonglong)uVar3;
  if ((uVar12 < uVar3) && (uVar8 = uVar11 - 0x10000, -1 < (int)uVar8)) {
    if (sVar10 == *(short *)((uVar7 - 1) + lVar13)) goto LAB_18004e41c;
    uVar3 = *(ushort *)(lVar14 + (ulonglong)(uVar3 & uVar8) * 2);
    uVar7 = (ulonglong)uVar3;
    if ((uVar12 < uVar3) && (uVar8 = uVar11 - 0x20000, -1 < (int)uVar8)) {
      if (sVar10 == *(short *)((uVar7 - 1) + lVar13)) goto LAB_18004e41c;
      uVar3 = *(ushort *)(lVar14 + (ulonglong)(uVar3 & uVar8) * 2);
      uVar7 = (ulonglong)uVar3;
      if ((uVar12 < uVar3) && (uVar11 = uVar11 - 0x30000, -1 < (int)uVar11))
      goto code_r0x00018004e3e9;
    }
  }
LAB_18004e503:
  uVar7 = (ulonglong)*(uint *)(param_1 + 0x9c);
  if ((int)uVar16 <= (int)*(uint *)(param_1 + 0x9c)) {
    uVar7 = uVar16;
  }
  return uVar7;
code_r0x00018004e3e9:
  uVar8 = uVar11;
  if (sVar10 == *(short *)((uVar7 - 1) + lVar13)) {
LAB_18004e41c:
    do {
      uVar11 = uVar8;
      if (sVar2 != *(short *)(uVar7 + lVar4)) break;
      lVar9 = -0x108;
      lVar14 = (-(longlong)psVar1 & 3U) + 0x108 + lVar4 + uVar7;
      lVar13 = (-(longlong)psVar1 & 3U) + 0x108;
      while( true ) {
        uVar6 = *(ulonglong *)(lVar9 + lVar14) ^ *(ulonglong *)((longlong)psVar1 + lVar9 + lVar13);
        uVar8 = (uint)uVar7;
        if (uVar6 != 0) break;
        uVar6 = *(ulonglong *)(lVar9 + 8 + lVar14) ^
                *(ulonglong *)((longlong)psVar1 + lVar9 + 8 + lVar13);
        if (uVar6 != 0) {
LAB_18004e47f:
          lVar9 = lVar9 + 8;
          break;
        }
        uVar6 = *(ulonglong *)(lVar9 + 0x10 + lVar14) ^
                *(ulonglong *)((longlong)psVar1 + lVar9 + 0x10 + lVar13);
        if (uVar6 != 0) {
          lVar9 = lVar9 + 8;
          goto LAB_18004e47f;
        }
        lVar9 = lVar9 + 0x18;
        if (lVar9 == 0) goto LAB_18004e4f6;
      }
      if ((uVar6 & 0xffff) == 0) {
        if ((int)uVar6 == 0) {
          lVar9 = lVar9 + 4;
          uVar7 = uVar6 >> 0x20;
          uVar6 = uVar6 >> 0x20;
          if ((short)uVar7 != 0) goto LAB_18004e4a5;
        }
        uVar6 = uVar6 >> 0x10 & 0xffff;
        lVar9 = lVar9 + 2;
      }
LAB_18004e4a5:
      uVar7 = lVar9 + (ulonglong)((char)uVar6 == '\0') + lVar13;
      iVar5 = (int)uVar7;
      if (0x101 < iVar5) {
LAB_18004e4f6:
        uVar16 = 0x102;
        *(uint *)(param_1 + 0x98) = uVar8;
        goto LAB_18004e503;
      }
      if ((int)uVar16 < iVar5) {
        uVar16 = uVar7 & 0xffffffff;
        *(uint *)(param_1 + 0x98) = uVar8;
        if (iVar15 <= iVar5) goto LAB_18004e503;
        sVar10 = *(short *)((uVar7 - 1) + (longlong)psVar1);
        lVar14 = *(longlong *)(param_1 + 0x60);
      }
      else {
        lVar14 = *(longlong *)(param_1 + 0x60);
        uVar7 = uVar16;
      }
      lVar13 = uVar7 + lVar4;
      uVar3 = *(ushort *)(lVar14 + (ulonglong)(uVar8 & uVar11) * 2);
      uVar7 = (ulonglong)uVar3;
      if ((uVar3 <= uVar12) || (uVar11 = uVar11 - 0x10000, (int)uVar11 < 0)) goto LAB_18004e503;
      uVar8 = uVar11;
    } while (sVar10 == *(short *)((uVar7 - 1) + lVar13));
  }
  goto LAB_18004e382;
}

/* ---- FUNC 0004E5B0 FUN_18004e5b0 (378 bytes) ---- */

/* WARNING: Type propagation algorithm not settling */

undefined8
FUN_18004e5b0(int param_1,ushort *param_2,uint param_3,longlong *param_4,uint *param_5,
             undefined *param_6)

{
  longlong lVar1;
  ushort uVar2;
  byte bVar3;
  undefined2 uVar5;
  longlong lVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  ushort *puVar10;
  ulonglong uVar11;
  byte bVar12;
  uint uVar13;
  ulonglong uVar14;
  uint uVar15;
  int iVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  ulonglong uVar21;
  int iVar22;
  uint uVar23;
  bool bVar24;
  bool bVar25;
  undefined4 local_res18;
  uint local_b4;
  uint local_b0;
  undefined *local_a0;
  undefined *local_98;
  ushort local_90 [16];
  ushort auStack_70 [24];
  char cVar4;
  ulonglong uVar16;
  
  uVar7 = 0;
  puVar10 = local_90;
  for (lVar6 = 0x10; lVar6 != 0; lVar6 = lVar6 + -1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  if (param_3 != 0) {
    uVar21 = (ulonglong)param_3;
    puVar10 = param_2;
    do {
      uVar2 = *puVar10;
      puVar10 = puVar10 + 1;
      local_90[uVar2] = local_90[uVar2] + 1;
      uVar21 = uVar21 - 1;
    } while (uVar21 != 0);
  }
  uVar8 = 0xd;
  uVar21 = 0xf;
  do {
    uVar20 = (uint)uVar21;
    uVar19 = 0xffffffff;
    if (local_90[uVar21] != 0) goto LAB_18004e68e;
    if (local_90[uVar8 + 1] != 0) {
      uVar20 = uVar20 - 1;
      goto LAB_18004e68e;
    }
    if (local_90[uVar8] != 0) {
      uVar20 = uVar20 - 2;
      goto LAB_18004e68e;
    }
    if (local_90[uVar8 - 1] != 0) {
      uVar20 = uVar20 - 3;
      goto LAB_18004e68e;
    }
    if (local_90[uVar8 - 2] != 0) {
      uVar20 = uVar20 - 4;
      goto LAB_18004e68e;
    }
    uVar21 = (ulonglong)(uVar20 - 5);
    uVar8 = uVar8 - 5;
  } while (uVar20 - 5 != 0);
  uVar20 = 0;
LAB_18004e68e:
  uVar8 = *param_5;
  if (uVar20 < *param_5) {
    uVar8 = uVar20;
  }
  if (uVar20 == 0) {
    *(undefined4 *)*param_4 = 0x140;
    *param_4 = *param_4 + 4;
    *(undefined4 *)*param_4 = 0x140;
    *param_4 = *param_4 + 4;
    *param_5 = 1;
    return 0;
  }
  uVar23 = 1;
  if (1 < uVar20) {
    puVar10 = local_90;
    do {
      puVar10 = puVar10 + 1;
      if (*puVar10 != 0) break;
      uVar23 = uVar23 + 1;
    } while (uVar23 < uVar20);
  }
  iVar17 = 1;
  uVar21 = 1;
  if (uVar8 < uVar23) {
    uVar8 = uVar23;
  }
  do {
    iVar17 = iVar17 * 2 - (uint)local_90[uVar21];
    if (iVar17 < 0) {
      return 0xffffffff;
    }
    uVar9 = (int)uVar21 + 1;
    uVar21 = (ulonglong)uVar9;
  } while (uVar9 < 0x10);
  if ((0 < iVar17) && ((param_1 == 0 || (uVar20 != 1)))) {
    return 0xffffffff;
  }
  auStack_70[1] = 0;
  lVar6 = 0xe;
  uVar21 = uVar7;
  do {
    *(short *)((longlong)auStack_70 + uVar21 + 4) =
         *(short *)((longlong)local_90 + uVar21 + 2) + *(short *)((longlong)auStack_70 + uVar21 + 2)
    ;
    uVar21 = uVar21 + 2;
    lVar6 = lVar6 + -1;
  } while (lVar6 != 0);
  puVar10 = param_2;
  uVar21 = uVar7;
  if (param_3 != 0) {
    do {
      if (*puVar10 != 0) {
        *(short *)(param_6 + (ulonglong)auStack_70[*puVar10] * 2) = (short)uVar21;
        auStack_70[*puVar10] = auStack_70[*puVar10] + 1;
      }
      uVar9 = (int)uVar21 + 1;
      puVar10 = puVar10 + 1;
      uVar21 = (ulonglong)uVar9;
    } while (uVar9 < param_3);
  }
  if (param_1 == 0) {
    local_a0 = param_6;
    uVar21 = 0x14;
    local_98 = param_6;
  }
  else if (param_1 == 1) {
    uVar21 = 0x101;
    local_98 = &DAT_18005b340;
    local_a0 = &DAT_18005b380;
  }
  else {
    local_98 = &DAT_18005b3c0;
    local_a0 = &DAT_18005b400;
    uVar21 = uVar7;
  }
  lVar6 = *param_4;
  local_b4 = 0;
  uVar15 = 1 << ((byte)uVar8 & 0x1f);
  uVar16 = (ulonglong)uVar15;
  local_b0 = 0;
  uVar9 = uVar15 - 1;
  uVar14 = uVar7;
  uVar11 = uVar7;
  if (param_1 == 1) {
    bVar24 = uVar15 < 0x354;
    bVar25 = uVar15 == 0x354;
  }
  else {
    if (param_1 != 2) goto LAB_18004e850;
    bVar24 = uVar15 < 0x250;
    bVar25 = uVar15 == 0x250;
  }
  if (!bVar24 && !bVar25) {
    return 1;
  }
LAB_18004e850:
  do {
    do {
      cVar4 = (char)uVar23;
      bVar12 = (byte)uVar14;
      bVar3 = cVar4 - bVar12;
      uVar2 = *(ushort *)(param_6 + uVar7 * 2);
      uVar13 = (uint)uVar21;
      if (uVar2 + 1 < uVar13) {
        local_res18 = (uint)CONCAT21(uVar2,bVar3) << 8;
      }
      else {
        if (uVar2 < uVar13) {
          local_res18 = CONCAT31((uint3)bVar3,0x60);
          uVar5 = 0;
        }
        else {
          lVar1 = (ulonglong)(uVar2 - uVar13) * 2;
          local_res18._0_2_ = CONCAT11(bVar3,local_a0[lVar1]);
          uVar5 = *(undefined2 *)(local_98 + lVar1);
        }
        local_res18 = CONCAT22(uVar5,(ushort)local_res18);
      }
      uVar13 = (uint)uVar11;
      iVar17 = 1 << (cVar4 - bVar12 & 0x1f);
      uVar11 = (ulonglong)((uVar13 >> (bVar12 & 0x1f)) + (int)uVar16);
      uVar7 = uVar16;
      do {
        uVar11 = (ulonglong)(uint)((int)uVar11 - iVar17);
        *(uint *)(lVar6 + uVar11 * 4) = local_res18;
        uVar18 = (int)uVar7 - iVar17;
        uVar7 = (ulonglong)uVar18;
      } while (uVar18 != 0);
      for (uVar18 = 1 << (cVar4 - 1U & 0x1f); (uVar13 & uVar18) != 0; uVar18 = uVar18 >> 1) {
      }
      if (uVar18 == 0) {
        uVar11 = 0;
      }
      else {
        uVar11 = (ulonglong)((uVar13 & uVar18 - 1) + uVar18);
      }
      local_b4 = local_b4 + 1;
      puVar10 = local_90 + uVar23;
      *puVar10 = *puVar10 - 1;
      if (*puVar10 == 0) {
        if (uVar23 == uVar20) {
          if ((uint)uVar11 != 0) {
            local_res18._0_2_ = CONCAT11(cVar4 - bVar12,0x40);
            local_res18 = (uint)(ushort)local_res18;
            *(uint *)(lVar6 + uVar11 * 4) = local_res18;
          }
          *param_4 = *param_4 + (ulonglong)uVar15 * 4;
          *param_5 = uVar8;
          return 0;
        }
        uVar23 = (uint)param_2[*(ushort *)(param_6 + (ulonglong)local_b4 * 2)];
      }
      uVar7 = (ulonglong)local_b4;
    } while (uVar23 <= uVar8);
    uVar13 = uVar9 & (uint)uVar11;
    if (uVar13 != uVar19) {
      lVar6 = lVar6 + uVar16 * 4;
      if (local_b0 == 0) {
        local_b0 = uVar8;
      }
      iVar22 = uVar23 - local_b0;
      uVar19 = local_b0 + iVar22;
      for (iVar17 = 1 << ((byte)iVar22 & 0x1f);
          (uVar19 < uVar20 && (uVar7 = (ulonglong)uVar19, 0 < (int)(iVar17 - (uint)local_90[uVar7]))
          ); iVar17 = (iVar17 - (uint)local_90[uVar7]) * 2) {
        iVar22 = iVar22 + 1;
        uVar19 = uVar19 + 1;
      }
      uVar19 = 1 << ((byte)iVar22 & 0x1f);
      uVar16 = (ulonglong)uVar19;
      uVar15 = uVar15 + uVar19;
      if (param_1 == 1) {
        bVar24 = uVar15 < 0x354;
        bVar25 = uVar15 == 0x354;
LAB_18004e9b4:
        if (!bVar24 && !bVar25) {
          return 1;
        }
      }
      else if (param_1 == 2) {
        bVar24 = uVar15 < 0x250;
        bVar25 = uVar15 == 0x250;
        goto LAB_18004e9b4;
      }
      lVar1 = (ulonglong)uVar13 * 4;
      *(byte *)(lVar1 + *param_4) = (byte)iVar22;
      *(byte *)(*param_4 + 1 + lVar1) = (byte)uVar8;
      *(short *)(*param_4 + 2 + lVar1) = (short)(lVar6 - *param_4 >> 2);
      uVar19 = uVar13;
    }
    uVar7 = (ulonglong)local_b4;
    uVar14 = (ulonglong)local_b0;
  } while( true );
}

/* ---- FUNC 0004E72A FUN_18004e72a (784 bytes) ---- */

undefined8 FUN_18004e72a(undefined8 param_1,undefined8 param_2,uint param_3,byte param_4)

{
  longlong lVar1;
  short *psVar2;
  ushort uVar3;
  undefined4 uVar4;
  longlong *plVar5;
  undefined2 uVar6;
  uint uVar7;
  ulonglong uVar8;
  longlong lVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  byte bVar12;
  int unaff_EBX;
  ulonglong uVar13;
  longlong unaff_RBP;
  ushort *unaff_RSI;
  ulonglong uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  char cVar19;
  uint in_R10D;
  uint in_R11D;
  longlong lVar20;
  ulonglong unaff_R13;
  longlong *unaff_R14;
  uint unaff_R15D;
  bool bVar21;
  bool bVar22;
  
  *(short *)(unaff_RBP + -0x36) = (short)unaff_R13;
  lVar9 = 0xe;
  uVar10 = unaff_R13;
  do {
    *(short *)(unaff_RBP + -0x34 + uVar10) =
         *(short *)(unaff_RBP + -0x56 + uVar10) + *(short *)(unaff_RBP + -0x36 + uVar10);
    uVar10 = uVar10 + 2;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  uVar10 = unaff_R13 & 0xffffffff;
  if (in_R11D != 0) {
    lVar9 = *(longlong *)(unaff_RBP + 0x68);
    do {
      if (*unaff_RSI != 0) {
        *(short *)(lVar9 + (ulonglong)*(ushort *)(unaff_RBP + -0x38 + (ulonglong)*unaff_RSI * 2) * 2
                  ) = (short)uVar10;
        psVar2 = (short *)(unaff_RBP + -0x38 + (ulonglong)*unaff_RSI * 2);
        *psVar2 = *psVar2 + 1;
      }
      uVar15 = (int)uVar10 + 1;
      uVar10 = (ulonglong)uVar15;
      unaff_RSI = unaff_RSI + 1;
    } while (uVar15 < in_R11D);
    param_4 = (byte)*(undefined4 *)(unaff_RBP + -0x74);
  }
  lVar9 = *(longlong *)(unaff_RBP + 0x68);
  if (unaff_EBX == 0) {
    *(longlong *)(unaff_RBP + -0x68) = lVar9;
    uVar10 = 0x14;
    *(longlong *)(unaff_RBP + -0x60) = lVar9;
  }
  else if (unaff_EBX == 1) {
    uVar10 = 0x101;
    *(undefined **)(unaff_RBP + -0x60) = &DAT_18005b340;
    *(undefined **)(unaff_RBP + -0x68) = &DAT_18005b380;
  }
  else {
    uVar10 = unaff_R13 & 0xffffffff;
    *(undefined **)(unaff_RBP + -0x60) = &DAT_18005b3c0;
    *(undefined **)(unaff_RBP + -0x68) = &DAT_18005b400;
  }
  lVar20 = *unaff_R14;
  uVar13 = unaff_R13 & 0xffffffff;
  *(int *)(unaff_RBP + -0x7c) = (int)unaff_R13;
  uVar15 = 1 << (param_4 & 0x1f);
  uVar14 = (ulonglong)uVar15;
  uVar11 = unaff_R13 & 0xffffffff;
  *(int *)(unaff_RBP + -0x80) = (int)uVar10;
  *(int *)(unaff_RBP + -0x78) = (int)unaff_R13;
  *(uint *)(unaff_RBP + -0x70) = uVar15 - 1;
  if (*(int *)(unaff_RBP + 0x40) == 1) {
    bVar21 = uVar15 < 0x354;
    bVar22 = uVar15 == 0x354;
  }
  else {
    if (*(int *)(unaff_RBP + 0x40) != 2) goto LAB_18004e830;
    bVar21 = uVar15 < 0x250;
    bVar22 = uVar15 == 0x250;
  }
  if (!bVar21 && !bVar22) {
    return 1;
  }
LAB_18004e830:
  uVar8 = unaff_R13 & 0xffffffff;
  do {
    do {
      cVar19 = (char)in_R10D;
      bVar12 = (byte)uVar13;
      *(byte *)(unaff_RBP + 0x51) = cVar19 - bVar12;
      uVar3 = *(ushort *)(lVar9 + uVar8 * 2);
      uVar7 = (uint)uVar10;
      if (uVar3 + 1 < uVar7) {
        *(undefined1 *)(unaff_RBP + 0x50) = 0;
        *(ushort *)(unaff_RBP + 0x52) = uVar3;
      }
      else {
        if (uVar3 < uVar7) {
          *(undefined1 *)(unaff_RBP + 0x50) = 0x60;
          uVar6 = 0;
        }
        else {
          lVar9 = (ulonglong)(uVar3 - uVar7) * 2;
          *(undefined1 *)(unaff_RBP + 0x50) =
               *(undefined1 *)(lVar9 + *(longlong *)(unaff_RBP + -0x68));
          uVar6 = *(undefined2 *)(lVar9 + *(longlong *)(unaff_RBP + -0x60));
        }
        *(undefined2 *)(unaff_RBP + 0x52) = uVar6;
      }
      uVar4 = *(undefined4 *)(unaff_RBP + 0x50);
      uVar7 = (uint)uVar11;
      iVar17 = 1 << (cVar19 - bVar12 & 0x1f);
      uVar11 = (ulonglong)((uVar7 >> (bVar12 & 0x1f)) + (int)uVar14);
      uVar10 = uVar14;
      do {
        uVar11 = (ulonglong)(uint)((int)uVar11 - iVar17);
        *(undefined4 *)(lVar20 + uVar11 * 4) = uVar4;
        uVar16 = (int)uVar10 - iVar17;
        uVar10 = (ulonglong)uVar16;
      } while (uVar16 != 0);
      for (uVar16 = 1 << (cVar19 - 1U & 0x1f); (uVar7 & uVar16) != 0; uVar16 = uVar16 >> 1) {
      }
      if (uVar16 == 0) {
        uVar11 = 0;
      }
      else {
        uVar11 = (ulonglong)((uVar7 & uVar16 - 1) + uVar16);
      }
      uVar7 = *(int *)(unaff_RBP + -0x7c) + 1;
      uVar8 = (ulonglong)uVar7;
      *(uint *)(unaff_RBP + -0x7c) = uVar7;
      psVar2 = (short *)(unaff_RBP + -0x58 + (ulonglong)in_R10D * 2);
      *psVar2 = *psVar2 + -1;
      if (*psVar2 == 0) {
        if (in_R10D == param_3) {
          if ((uint)uVar11 != 0) {
            *(undefined1 *)(unaff_RBP + 0x50) = 0x40;
            *(byte *)(unaff_RBP + 0x51) = cVar19 - bVar12;
            *(undefined2 *)(unaff_RBP + 0x52) = 0;
            *(undefined4 *)(lVar20 + uVar11 * 4) = *(undefined4 *)(unaff_RBP + 0x50);
          }
          **(longlong **)(unaff_RBP + 0x58) =
               **(longlong **)(unaff_RBP + 0x58) + (ulonglong)uVar15 * 4;
          **(undefined4 **)(unaff_RBP + 0x60) = *(undefined4 *)(unaff_RBP + -0x74);
          return 0;
        }
        lVar9 = *(longlong *)(unaff_RBP + 0x68);
        in_R10D = (uint)*(ushort *)
                         (*(longlong *)(unaff_RBP + 0x48) +
                         (ulonglong)*(ushort *)(lVar9 + uVar8 * 2) * 2);
        uVar8 = (ulonglong)*(uint *)(unaff_RBP + -0x7c);
      }
      else {
        lVar9 = *(longlong *)(unaff_RBP + 0x68);
      }
      uVar10 = (ulonglong)*(uint *)(unaff_RBP + -0x80);
    } while (in_R10D <= *(uint *)(unaff_RBP + -0x74));
    uVar7 = *(uint *)(unaff_RBP + -0x70) & (uint)uVar11;
    if (uVar7 != unaff_R15D) {
      lVar20 = lVar20 + uVar14 * 4;
      uVar16 = *(uint *)(unaff_RBP + -0x78);
      if (*(uint *)(unaff_RBP + -0x78) == 0) {
        uVar16 = *(uint *)(unaff_RBP + -0x74);
      }
      iVar18 = in_R10D - uVar16;
      *(uint *)(unaff_RBP + -0x78) = uVar16;
      uVar16 = uVar16 + iVar18;
      for (iVar17 = 1 << ((byte)iVar18 & 0x1f);
          (uVar16 < param_3 &&
          (iVar17 = iVar17 - (uint)*(ushort *)(unaff_RBP + -0x58 + (ulonglong)uVar16 * 2),
          0 < iVar17)); iVar17 = iVar17 * 2) {
        iVar18 = iVar18 + 1;
        uVar16 = uVar16 + 1;
      }
      uVar16 = 1 << ((byte)iVar18 & 0x1f);
      uVar14 = (ulonglong)uVar16;
      uVar15 = uVar15 + uVar16;
      if (*(int *)(unaff_RBP + 0x40) == 1) {
        bVar21 = uVar15 < 0x354;
        bVar22 = uVar15 == 0x354;
LAB_18004e9b4:
        if (!bVar21 && !bVar22) {
          return 1;
        }
      }
      else if (*(int *)(unaff_RBP + 0x40) == 2) {
        bVar21 = uVar15 < 0x250;
        bVar22 = uVar15 == 0x250;
        goto LAB_18004e9b4;
      }
      plVar5 = *(longlong **)(unaff_RBP + 0x58);
      lVar1 = (ulonglong)uVar7 * 4;
      uVar4 = *(undefined4 *)(unaff_RBP + -0x74);
      *(byte *)(lVar1 + *plVar5) = (byte)iVar18;
      *(char *)(*plVar5 + 1 + lVar1) = (char)uVar4;
      lVar9 = *(longlong *)(unaff_RBP + 0x68);
      *(short *)(*plVar5 + 2 + lVar1) = (short)(lVar20 - *plVar5 >> 2);
      uVar10 = (ulonglong)*(uint *)(unaff_RBP + -0x80);
      uVar8 = (ulonglong)*(uint *)(unaff_RBP + -0x7c);
      unaff_R15D = uVar7;
    }
    uVar13 = (ulonglong)*(uint *)(unaff_RBP + -0x78);
  } while( true );
}

/* ---- FUNC 0004EA3A FUN_18004ea3a (18 bytes) ---- */

void FUN_18004ea3a(void)

{
  return;
}

/* ---- FUNC 0004EA50 FUN_18004ea50 (426 bytes) ---- */

void FUN_18004ea50(longlong *param_1,int param_2)

{
  longlong lVar1;
  char *pcVar2;
  int iVar3;
  longlong lVar4;
  undefined1 local_88 [16];
  byte *local_78;
  byte *local_70;
  longlong local_68;
  longlong local_60;
  longlong local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  ulonglong local_38;
  uint local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  uint local_14;
  
  lVar1 = param_1[5];
  local_78 = (byte *)*param_1;
  local_70 = local_78 + ((int)param_1[1] - 6);
  local_68 = param_1[2];
  local_60 = local_68 - (ulonglong)(uint)(param_2 - (int)param_1[3]);
  local_58 = (ulonglong)((int)param_1[3] - 0x102) + local_68;
  local_2c = *(undefined4 *)(lVar1 + 0x34);
  local_28 = *(undefined4 *)(lVar1 + 0x3c);
  local_50 = *(undefined8 *)(lVar1 + 0x40);
  local_38 = (ulonglong)*(uint *)(lVar1 + 0x48);
  local_30 = *(uint *)(lVar1 + 0x4c);
  local_48 = *(undefined8 *)(lVar1 + 0x60);
  local_40 = *(undefined8 *)(lVar1 + 0x68);
  local_24 = (1 << ((byte)*(undefined4 *)(lVar1 + 0x70) & 0x1f)) + -1;
  local_20 = (1 << ((byte)*(undefined4 *)(lVar1 + 0x74) & 0x1f)) + -1;
  for (; ((ulonglong)local_78 & 3) != 0; local_78 = local_78 + 1) {
    local_38 = local_38 + ((uint)*local_78 << ((byte)local_30 & 0x1f));
    local_30 = local_30 + 8;
  }
  inffas8664fnc((longlong)local_88);
  if (local_14 < 2) {
    if (local_14 == 1) {
      *(undefined4 *)(lVar1 + 8) = 0x3f3f;
    }
  }
  else if (local_14 == 2) {
    param_1[4] = (longlong)"invalid literal/length code";
    *(undefined4 *)(lVar1 + 8) = 0x3f51;
  }
  else {
    pcVar2 = "invalid distance code";
    if (local_14 != 3) {
      pcVar2 = "invalid distance too far back";
    }
    param_1[4] = (longlong)pcVar2;
    *(undefined4 *)(lVar1 + 8) = 0x3f51;
  }
  lVar4 = (longlong)local_78 - (ulonglong)(local_30 >> 3);
  *param_1 = lVar4;
  iVar3 = local_30 + (local_30 >> 3) * -8;
  param_1[2] = local_68;
  local_38._0_4_ = (uint)local_38 & (1 << ((byte)iVar3 & 0x1f)) - 1U;
  *(int *)(param_1 + 1) = ((int)local_70 - (int)lVar4) + 6;
  *(int *)(param_1 + 3) = ((int)local_58 - (int)local_68) + 0x102;
  *(uint *)(lVar1 + 0x48) = (uint)local_38;
  *(int *)(lVar1 + 0x4c) = iVar3;
  return;
}

/* ---- FUNC 0004EC00 inffas8664fnc (791 bytes) ---- */

/* Library Function - Single Match
    inffas8664fnc
   
   Library: Visual Studio 2019 Release */

void inffas8664fnc(longlong param_1)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  undefined2 *puVar5;
  longlong lVar6;
  longlong lVar7;
  uint uVar8;
  byte bVar9;
  uint uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  char cVar14;
  undefined4 uVar15;
  ulonglong uVar16;
  undefined7 uVar17;
  undefined8 unaff_RBP;
  uint *puVar18;
  uint *puVar19;
  undefined2 *puVar20;
  undefined1 *puVar21;
  undefined2 *puVar22;
  undefined2 *puVar23;
  uint uVar24;
  uint uVar25;
  
  *(undefined8 *)(param_1 + 8) = unaff_RBP;
  *(BADSPACEBASE **)param_1 = register0x00000020;
  puVar18 = *(uint **)(param_1 + 0x10);
  puVar23 = *(undefined2 **)(param_1 + 0x20);
  puVar4 = *(uint **)(param_1 + 0x18);
  puVar5 = *(undefined2 **)(param_1 + 0x30);
  lVar6 = *(longlong *)(param_1 + 0x40);
  lVar7 = *(longlong *)(param_1 + 0x48);
  uVar13 = *(ulonglong *)(param_1 + 0x50);
  uVar8 = *(uint *)(param_1 + 0x58);
  uVar16 = (ulonglong)uVar8;
  uVar2 = *(uint *)(param_1 + 100);
  uVar3 = *(uint *)(param_1 + 0x68);
  if ((puVar5 != puVar23) && (puVar22 = puVar23, puVar4 != puVar18)) goto LAB_18004ec96;
  bVar9 = (byte)uVar8;
  puVar19 = puVar18;
  if (bVar9 < 0x21) {
    puVar19 = puVar18 + 1;
    uVar16 = (ulonglong)CONCAT31((int3)(uVar8 >> 8),bVar9 + 0x20);
    uVar13 = uVar13 | (ulonglong)*puVar18 << (bVar9 & 0x3f);
  }
LAB_18004ecc4:
  uVar8 = *(uint *)(lVar6 + (uVar2 & uVar13) * 4);
  puVar18 = puVar19;
  do {
    bVar9 = (byte)(uVar8 >> 8);
    uVar16 = CONCAT71((int7)(uVar16 >> 8),(char)uVar16 - bVar9);
    uVar13 = uVar13 >> (bVar9 & 0x3f);
    puVar19 = puVar18;
    if ((char)uVar8 != '\0') goto LAB_18004ece0;
    puVar22 = (undefined2 *)((longlong)puVar23 + 1);
    *(char *)puVar23 = (char)(uVar8 >> 0x10);
    while( true ) {
      uVar15 = (undefined4)uVar16;
      if ((puVar5 <= puVar22) || (puVar4 <= puVar18)) {
        *(undefined4 *)(param_1 + 0x74) = 0;
        goto LAB_18004eed4;
      }
LAB_18004ec96:
      bVar9 = (byte)uVar16;
      puVar19 = puVar18;
      if (bVar9 < 0x21) {
        puVar19 = puVar18 + 1;
        uVar16 = CONCAT71((int7)(uVar16 >> 8),bVar9 + 0x20);
        uVar13 = uVar13 | (ulonglong)*puVar18 << (bVar9 & 0x3f);
      }
      uVar8 = *(uint *)(lVar6 + (uVar2 & uVar13) * 4);
      bVar9 = (byte)(uVar8 >> 8);
      uVar16 = CONCAT71((int7)(uVar16 >> 8),(char)uVar16 - bVar9);
      uVar13 = uVar13 >> (bVar9 & 0x3f);
      puVar23 = puVar22;
      if ((char)uVar8 == '\0') {
        puVar23 = (undefined2 *)((longlong)puVar22 + 1);
        *(char *)puVar22 = (char)(uVar8 >> 0x10);
        goto LAB_18004ecc4;
      }
LAB_18004ece0:
      uVar15 = (undefined4)uVar16;
      uVar24 = uVar8 >> 0x10;
      uVar10 = (uint)uVar13;
      puVar18 = puVar19;
      puVar22 = puVar23;
      if ((uVar8 & 0x10) == 0) break;
      bVar9 = (byte)uVar8 & 0xf;
      if ((uVar8 & 0xf) != 0) {
        uVar16 = CONCAT71((int7)(uVar16 >> 8),(char)uVar16 - bVar9);
        uVar13 = uVar13 >> bVar9;
        uVar24 = uVar24 + ((1 << bVar9) - 1U & uVar10);
      }
      bVar9 = (byte)uVar16;
      if (bVar9 < 0x21) {
        puVar18 = puVar19 + 1;
        uVar16 = CONCAT71((int7)(uVar16 >> 8),bVar9 + 0x20);
        uVar13 = uVar13 | (ulonglong)*puVar19 << (bVar9 & 0x3f);
      }
      uVar8 = *(uint *)(lVar7 + (uVar3 & uVar13) * 4);
      while( true ) {
        uVar25 = uVar8 >> 0x10;
        uVar12 = (ulonglong)uVar25;
        bVar9 = (byte)(uVar8 >> 8);
        uVar17 = (undefined7)(uVar16 >> 8);
        cVar14 = (char)uVar16 - bVar9;
        uVar16 = CONCAT71(uVar17,cVar14);
        uVar15 = (undefined4)uVar16;
        uVar13 = uVar13 >> (bVar9 & 0x3f);
        uVar10 = (uint)uVar13;
        if ((uVar8 & 0x10) != 0) break;
        if ((uVar8 & 0x40) != 0) {
          *(undefined4 *)(param_1 + 0x74) = 3;
          goto LAB_18004eed4;
        }
        uVar8 = *(uint *)(lVar7 + (ulonglong)(((1 << ((byte)uVar8 & 0x1f)) - 1U & uVar10) + uVar25)
                                  * 4);
      }
      bVar9 = (byte)uVar8 & 0xf;
      if ((uVar8 & 0xf) == 0) {
        if ((uVar25 != 1) || (*(undefined2 **)(param_1 + 0x28) == puVar23)) goto LAB_18004ed52;
        uVar1 = *(undefined1 *)((longlong)puVar23 + -1);
        uVar12 = (ulonglong)(uint)((int)uVar24 >> 1);
        if ((uVar24 & 1) != 0) {
          *(undefined1 *)puVar23 = uVar1;
          puVar22 = (undefined2 *)((longlong)puVar23 + 1);
        }
        for (; uVar12 != 0; uVar12 = uVar12 - 1) {
          *puVar22 = CONCAT11(uVar1,uVar1);
          puVar22 = puVar22 + 1;
        }
      }
      else {
        uVar16 = CONCAT71(uVar17,cVar14 - bVar9);
        uVar13 = uVar13 >> bVar9;
        uVar12 = (ulonglong)(uVar25 + ((1 << bVar9) - 1U & uVar10));
LAB_18004ed52:
        uVar15 = (undefined4)uVar16;
        uVar8 = (int)puVar23 - (int)*(undefined8 *)(param_1 + 0x28);
        uVar10 = (uint)uVar12;
        if (uVar8 < uVar10) {
          if (*(uint *)(param_1 + 0x5c) < uVar10) {
            *(undefined4 *)(param_1 + 0x74) = 4;
            goto LAB_18004eed4;
          }
          uVar10 = uVar10 - uVar8;
          uVar11 = (ulonglong)uVar10;
          if (*(int *)(param_1 + 0x60) == 0) {
            puVar21 = (undefined1 *)
                      (*(longlong *)(param_1 + 0x38) +
                      (ulonglong)(*(uint *)(param_1 + 0x5c) - uVar10));
            if (uVar10 < uVar24) {
              uVar24 = uVar24 - uVar10;
              for (; uVar11 != 0; uVar11 = uVar11 - 1) {
                *(undefined1 *)puVar23 = *puVar21;
                puVar21 = puVar21 + 1;
                puVar23 = (undefined2 *)((longlong)puVar23 + 1);
              }
              puVar21 = (undefined1 *)((longlong)puVar23 - uVar12);
            }
          }
          else {
            uVar8 = *(uint *)(param_1 + 0x60);
            if (uVar8 < uVar10) {
              puVar21 = (undefined1 *)
                        (((ulonglong)*(uint *)(param_1 + 0x5c) + *(longlong *)(param_1 + 0x38) +
                         (ulonglong)uVar8) - uVar11);
              uVar10 = uVar10 - uVar8;
              uVar11 = (ulonglong)uVar10;
              if (uVar10 < uVar24) {
                uVar24 = uVar24 - uVar10;
                for (; uVar11 != 0; uVar11 = uVar11 - 1) {
                  *(undefined1 *)puVar23 = *puVar21;
                  puVar21 = puVar21 + 1;
                  puVar23 = (undefined2 *)((longlong)puVar23 + 1);
                }
                puVar21 = *(undefined1 **)(param_1 + 0x38);
                uVar8 = *(uint *)(param_1 + 0x60);
                uVar11 = (ulonglong)uVar8;
                if (uVar8 < uVar24) {
                  uVar24 = uVar24 - uVar8;
                  for (; uVar11 != 0; uVar11 = uVar11 - 1) {
                    *(undefined1 *)puVar23 = *puVar21;
                    puVar21 = puVar21 + 1;
                    puVar23 = (undefined2 *)((longlong)puVar23 + 1);
                  }
                  puVar21 = (undefined1 *)((longlong)puVar23 - uVar12);
                }
              }
            }
            else {
              puVar21 = (undefined1 *)((*(longlong *)(param_1 + 0x38) + (ulonglong)uVar8) - uVar11);
              if (uVar10 < uVar24) {
                uVar24 = uVar24 - uVar10;
                for (; uVar11 != 0; uVar11 = uVar11 - 1) {
                  *(undefined1 *)puVar23 = *puVar21;
                  puVar21 = puVar21 + 1;
                  puVar23 = (undefined2 *)((longlong)puVar23 + 1);
                }
                puVar21 = (undefined1 *)((longlong)puVar23 - uVar12);
              }
            }
          }
          puVar22 = puVar23;
          for (uVar12 = (ulonglong)uVar24; uVar12 != 0; uVar12 = uVar12 - 1) {
            *(undefined1 *)puVar22 = *puVar21;
            puVar21 = puVar21 + 1;
            puVar22 = (undefined2 *)((longlong)puVar22 + 1);
          }
        }
        else {
          uVar11 = (ulonglong)(uint)((int)uVar24 >> 1);
          puVar20 = (undefined2 *)((longlong)puVar23 - uVar12);
          if ((uVar24 & 1) == 0) {
            for (; uVar11 != 0; uVar11 = uVar11 - 1) {
              *puVar22 = *puVar20;
              puVar20 = puVar20 + 1;
              puVar22 = puVar22 + 1;
            }
          }
          else {
            for (; uVar11 != 0; uVar11 = uVar11 - 1) {
              *puVar23 = *puVar20;
              puVar20 = puVar20 + 1;
              puVar23 = puVar23 + 1;
            }
            *(undefined1 *)puVar23 = *(undefined1 *)puVar20;
            puVar22 = (undefined2 *)((longlong)puVar23 + 1);
          }
        }
      }
    }
    if ((uVar8 & 0x40) != 0) {
      if ((uVar8 & 0x20) == 0) {
        *(undefined4 *)(param_1 + 0x74) = 2;
      }
      else {
        *(undefined4 *)(param_1 + 0x74) = 1;
      }
LAB_18004eed4:
      *(uint **)(param_1 + 0x10) = puVar18;
      *(undefined2 **)(param_1 + 0x20) = puVar22;
      *(undefined4 *)(param_1 + 0x58) = uVar15;
      *(ulonglong *)(param_1 + 0x50) = uVar13;
      return;
    }
    uVar8 = *(uint *)(lVar6 + (ulonglong)(((1 << ((byte)uVar8 & 0x1f)) - 1U & uVar10) + uVar24) * 4)
    ;
  } while( true );
}

/* ---- FUNC 0004EF17 __CxxFrameHandler4 (6 bytes) ---- */

void __CxxFrameHandler4(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018004ef17. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __CxxFrameHandler4();
  return;
}

/* ---- FUNC 0004EF1D memset (6 bytes) ---- */

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004ef1d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}

/* ---- FUNC 0004EF23 __std_exception_copy (6 bytes) ---- */

void __std_exception_copy(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018004ef23. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __std_exception_copy();
  return;
}

/* ---- FUNC 0004EF29 __std_exception_destroy (6 bytes) ---- */

void __std_exception_destroy(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018004ef29. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __std_exception_destroy();
  return;
}

/* ---- FUNC 0004EF2F _CxxThrowException (6 bytes) ---- */

void __stdcall _CxxThrowException(void *pExceptionObject,ThrowInfo *pThrowInfo)

{
                    /* WARNING: Could not recover jumptable at 0x00018004ef2f. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  _CxxThrowException(pExceptionObject,pThrowInfo);
  return;
}

/* ---- FUNC 0004EF35 memcmp (6 bytes) ---- */

int __cdecl memcmp(void *_Buf1,void *_Buf2,size_t _Size)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004ef35. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = memcmp(_Buf1,_Buf2,_Size);
  return iVar1;
}

/* ---- FUNC 0004EF3B memcpy (6 bytes) ---- */

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004ef3b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memcpy(_Dst,_Src,_Size);
  return pvVar1;
}

/* ---- FUNC 0004EF41 memmove (6 bytes) ---- */

void * __cdecl memmove(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004ef41. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memmove(_Dst,_Src,_Size);
  return pvVar1;
}

/* ---- FUNC 0004EF47 strrchr (6 bytes) ---- */

char * __cdecl strrchr(char *_Str,int _Ch)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004ef47. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = strrchr(_Str,_Ch);
  return pcVar1;
}

/* ---- FUNC 0004EF4D strstr (6 bytes) ---- */

char * __cdecl strstr(char *_Str,char *_SubStr)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004ef4d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = strstr(_Str,_SubStr);
  return pcVar1;
}

/* ---- FUNC 0004EF53 Unwind@18004ef53 (6 bytes) ---- */

void Unwind_18004ef53(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018004ef53. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __std_terminate();
  return;
}

/* ---- FUNC 0004EF59 strchr (6 bytes) ---- */

char * __cdecl strchr(char *_Str,int _Val)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004ef59. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = strchr(_Str,_Val);
  return pcVar1;
}

/* ---- FUNC 0004EF5F _set_purecall_handler (6 bytes) ---- */

_purecall_handler __cdecl _set_purecall_handler(_purecall_handler _Handler)

{
  _purecall_handler p_Var1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004ef5f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  p_Var1 = _set_purecall_handler(_Handler);
  return p_Var1;
}

/* ---- FUNC 0004EF65 __C_specific_handler (6 bytes) ---- */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004ef65. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}

/* ---- FUNC 0004EF6B memchr (6 bytes) ---- */

void * __cdecl memchr(void *_Buf,int _Val,size_t _MaxCount)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004ef6b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memchr(_Buf,_Val,_MaxCount);
  return pvVar1;
}

/* ---- FUNC 0004EF71 __CxxFrameHandler3 (6 bytes) ---- */

void __CxxFrameHandler3(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018004ef71. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  __CxxFrameHandler3();
  return;
}

/* ---- FUNC 0004EF77 __current_exception (6 bytes) ---- */

void __current_exception(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018004ef77. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __current_exception();
  return;
}

/* ---- FUNC 0004EF7D __current_exception_context (6 bytes) ---- */

void __current_exception_context(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018004ef7d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __current_exception_context();
  return;
}

/* ---- FUNC 0004EF83 __std_type_info_destroy_list (6 bytes) ---- */

void __std_type_info_destroy_list(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018004ef83. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __std_type_info_destroy_list();
  return;
}

/* ---- FUNC 0004EF89 strcmp (6 bytes) ---- */

int __cdecl strcmp(char *_Str1,char *_Str2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004ef89. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = strcmp(_Str1,_Str2);
  return iVar1;
}

/* ---- FUNC 0004EF8F free (6 bytes) ---- */

void __cdecl free(void *_Memory)

{
                    /* WARNING: Could not recover jumptable at 0x00018004ef8f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  free(_Memory);
  return;
}

/* ---- FUNC 0004EF95 malloc (6 bytes) ---- */

void * __cdecl malloc(size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004ef95. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = malloc(_Size);
  return pvVar1;
}

/* ---- FUNC 0004EF9B ceil (6 bytes) ---- */

double __cdecl ceil(double _X)

{
  double dVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004ef9b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  dVar1 = ceil(_X);
  return dVar1;
}

/* ---- FUNC 0004EFA1 log10 (6 bytes) ---- */

double __cdecl log10(double _X)

{
  double dVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018004efa1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  dVar1 = log10(_X);
  return dVar1;
}

/* ---- FUNC 0004EFA7 terminate (6 bytes) ---- */

void terminate(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018004efa7. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  terminate();
  return;
}

/* ---- FUNC 0004EFAD _seh_filter_dll (6 bytes) ---- */

void _seh_filter_dll(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018004efad. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _seh_filter_dll();
  return;
}

/* ---- FUNC 0004EFB3 _configure_narrow_argv (6 bytes) ---- */

void _configure_narrow_argv(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018004efb3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _configure_narrow_argv();
  return;
}

/* ---- FUNC 0004EFB9 _initialize_narrow_environment (6 bytes) ---- */

void _initialize_narrow_environment(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018004efb9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initialize_narrow_environment();
  return;
}

/* ---- FUNC 0004EFBF _initialize_onexit_table (6 bytes) ---- */

void _initialize_onexit_table(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018004efbf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initialize_onexit_table();
  return;
}

/* ---- FUNC 0004EFC5 _register_onexit_function (6 bytes) ---- */

void _register_onexit_function(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018004efc5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _register_onexit_function();
  return;
}

/* ---- FUNC 0004EFCB _execute_onexit_table (6 bytes) ---- */

void _execute_onexit_table(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018004efcb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _execute_onexit_table();
  return;
}

/* ---- FUNC 0004EFD1 _crt_atexit (6 bytes) ---- */

void _crt_atexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018004efd1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _crt_atexit();
  return;
}

/* ---- FUNC 0004EFD7 _cexit (6 bytes) ---- */

void __cdecl _cexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018004efd7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _cexit();
  return;
}

/* ---- FUNC 0004EFDD _initterm (6 bytes) ---- */

void _initterm(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018004efdd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm();
  return;
}

/* ---- FUNC 0004EFE3 _initterm_e (6 bytes) ---- */

void _initterm_e(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018004efe3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm_e();
  return;
}

/* ---- FUNC 0004EFEC FUN_18004efec (3 bytes) ---- */

undefined1 FUN_18004efec(void)

{
  return 1;
}

/* ---- FUNC 0004EFF0 FUN_18004eff0 (3 bytes) ---- */

undefined8 FUN_18004eff0(void)

{
  return 0;
}

/* ---- FUNC 0004F010 _guard_dispatch_icall (2 bytes) ---- */

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00018004f010. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

/* ---- FUNC 0004F030 _guard_dispatch_icall (6 bytes) ---- */

/* WARNING: This is an inlined function */
/* WARNING: Switch with 1 destination removed at 0x00018004f030 */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00018004f010. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

/* ---- FUNC 0004F290 FUN_18004f290 (32 bytes) ---- */

void FUN_18004f290(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x98));
  return;
}

/* ---- FUNC 0004F320 FUN_18004f320 (29 bytes) ---- */

void FUN_18004f320(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x68));
  return;
}

/* ---- FUNC 0004F350 FUN_18004f350 (29 bytes) ---- */

void FUN_18004f350(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x70));
  return;
}

/* ---- FUNC 0004F3E0 FUN_18004f3e0 (42 bytes) ---- */

void FUN_18004f3e0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x20) & 1) != 0) {
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffffffe;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0xb8));
  }
  return;
}

/* ---- FUNC 0004F410 FUN_18004f410 (42 bytes) ---- */

void FUN_18004f410(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x20) & 2) != 0) {
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffffffd;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0xb0));
  }
  return;
}

/* ---- FUNC 0004F4A0 FUN_18004f4a0 (45 bytes) ---- */

void FUN_18004f4a0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0xb8) & 1) != 0) {
    *(uint *)(param_2 + 0xb8) = *(uint *)(param_2 + 0xb8) & 0xfffffffe;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x58));
  }
  return;
}

/* ---- FUNC 0004F510 FUN_18004f510 (45 bytes) ---- */

void FUN_18004f510(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x80) & 1) != 0) {
    *(uint *)(param_2 + 0x80) = *(uint *)(param_2 + 0x80) & 0xfffffffe;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x38));
  }
  return;
}

/* ---- FUNC 0004F580 FUN_18004f580 (32 bytes) ---- */

void FUN_18004f580(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x1a0));
  return;
}

/* ---- FUNC 0004F720 FUN_18004f720 (32 bytes) ---- */

void FUN_18004f720(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x208));
  return;
}

/* ---- FUNC 0004F740 FUN_18004f740 (42 bytes) ---- */

void FUN_18004f740(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x70) & 1) != 0) {
    *(uint *)(param_2 + 0x70) = *(uint *)(param_2 + 0x70) & 0xfffffffe;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 400));
  }
  return;
}

/* ---- FUNC 0004F7D0 FUN_18004f7d0 (42 bytes) ---- */

void FUN_18004f7d0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x70) & 2) != 0) {
    *(uint *)(param_2 + 0x70) = *(uint *)(param_2 + 0x70) & 0xfffffffd;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x170));
  }
  return;
}

/* ---- FUNC 0004F800 FUN_18004f800 (42 bytes) ---- */

void FUN_18004f800(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x70) & 4) != 0) {
    *(uint *)(param_2 + 0x70) = *(uint *)(param_2 + 0x70) & 0xfffffffb;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x168));
  }
  return;
}

/* ---- FUNC 0004F870 FUN_18004f870 (42 bytes) ---- */

void FUN_18004f870(undefined8 param_1,longlong param_2)

{
  _eh_vector_destructor_iterator_((void *)(param_2 + 0x30),0x10,1,FUN_180001e00);
  return;
}

/* ---- FUNC 0004F8A0 FUN_18004f8a0 (42 bytes) ---- */

void FUN_18004f8a0(undefined8 param_1,longlong param_2)

{
  _eh_vector_destructor_iterator_
            ((void *)(param_2 + 0x58),8,1,
             ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>_exref);
  return;
}

/* ---- FUNC 0004F8E0 FUN_18004f8e0 (45 bytes) ---- */

void FUN_18004f8e0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x78) & 1) != 0) {
    *(uint *)(param_2 + 0x78) = *(uint *)(param_2 + 0x78) & 0xfffffffe;
    FUN_180009380((longlong *)(*(longlong *)(param_2 + 0x88) + 8));
  }
  return;
}

/* ---- FUNC 0004F910 FUN_18004f910 (48 bytes) ---- */

void FUN_18004f910(undefined8 param_1,longlong param_2)

{
  _Tree_val<std::_Tree_simple_types<std::pair<CAPString_const_,int>_>_> *p_Var1;
  
  p_Var1 = std::
           _Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
           ::_Get_scary(*(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
                          **)(param_2 + 0x70));
  FUN_180008800(*(undefined8 *)(param_2 + 0x70),p_Var1,*(longlong **)(param_2 + 0x78));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}

/* ---- FUNC 0004F950 FUN_18004f950 (48 bytes) ---- */

void FUN_18004f950(undefined8 param_1,longlong param_2)

{
  _Tree_val<std::_Tree_simple_types<std::pair<CAPString_const_,int>_>_> *p_Var1;
  
  p_Var1 = std::
           _Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
           ::_Get_scary(*(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
                          **)(param_2 + 0x50));
  FUN_180008800(*(undefined8 *)(param_2 + 0x50),p_Var1,*(longlong **)(param_2 + 0x58));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}

/* ---- FUNC 0004F990 FUN_18004f990 (51 bytes) ---- */

void FUN_18004f990(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x90) & 1) != 0) {
    *(uint *)(param_2 + 0x90) = *(uint *)(param_2 + 0x90) & 0xfffffffe;
    FUN_180009380((longlong *)(*(longlong *)(param_2 + 0xa0) + 8));
  }
  return;
}

/* ---- FUNC 0004F9D0 FUN_18004f9d0 (60 bytes) ---- */

void FUN_18004f9d0(undefined8 param_1,longlong param_2)

{
  FUN_1800081e0(*(longlong **)(param_2 + 0x20),*(longlong **)(param_2 + 0x28));
  FUN_18000b020(*(undefined8 *)(param_2 + 0x70),*(void **)(param_2 + 0x88),
                *(longlong *)(param_2 + 0x78));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}

/* ---- FUNC 0004FA10 FUN_18004fa10 (51 bytes) ---- */

void FUN_18004fa10(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x90) & 1) != 0) {
    *(uint *)(param_2 + 0x90) = *(uint *)(param_2 + 0x90) & 0xfffffffe;
    FUN_180009380((longlong *)(*(longlong *)(param_2 + 0xa8) + 8));
  }
  return;
}

/* ---- FUNC 0004FA70 FUN_18004fa70 (42 bytes) ---- */

void FUN_18004fa70(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x30) & 1) != 0) {
    *(uint *)(param_2 + 0x30) = *(uint *)(param_2 + 0x30) & 0xfffffffe;
    FUN_180009380((longlong *)(*(longlong *)(param_2 + 0x38) + 8));
  }
  return;
}

/* ---- FUNC 0004FAC0 FUN_18004fac0 (42 bytes) ---- */

void FUN_18004fac0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x20) & 1) != 0) {
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffffffe;
    FUN_180009380((longlong *)(param_2 + 0x40));
  }
  return;
}

/* ---- FUNC 0004FAF0 FUN_18004faf0 (42 bytes) ---- */

void FUN_18004faf0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x20) & 2) != 0) {
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffffffd;
    FUN_180009380((longlong *)(*(longlong *)(param_2 + 0x28) + 8));
  }
  return;
}

/* ---- FUNC 0004FB40 FUN_18004fb40 (42 bytes) ---- */

void FUN_18004fb40(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x20) & 1) != 0) {
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffffffe;
    FUN_180009380((longlong *)(param_2 + 0x60));
  }
  return;
}

/* ---- FUNC 0004FB70 FUN_18004fb70 (42 bytes) ---- */

void FUN_18004fb70(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x20) & 2) != 0) {
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffffffd;
    FUN_180009380((longlong *)(param_2 + 0x38));
  }
  return;
}

/* ---- FUNC 0004FBA0 FUN_18004fba0 (42 bytes) ---- */

void FUN_18004fba0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x20) & 1) != 0) {
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffffffe;
    FUN_180009380((longlong *)(param_2 + 0x30));
  }
  return;
}

/* ---- FUNC 0004FBE0 FUN_18004fbe0 (48 bytes) ---- */

void FUN_18004fbe0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x90) & 1) != 0) {
    *(uint *)(param_2 + 0x90) = *(uint *)(param_2 + 0x90) & 0xfffffffe;
    FUN_180009380((longlong *)(*(longlong *)(param_2 + 0x20) + 8));
  }
  return;
}

/* ---- FUNC 0004FC10 FUN_18004fc10 (39 bytes) ---- */

void FUN_18004fc10(undefined8 param_1,longlong param_2)

{
  deallocate(*(undefined8 *)(param_2 + 0x60),*(void **)(param_2 + 0x78),
             *(longlong *)(param_2 + 0x68));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}

/* ---- FUNC 0004FC70 FUN_18004fc70 (69 bytes) ---- */

void FUN_18004fc70(undefined8 param_1,longlong param_2)

{
  FUN_18000b730(*(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)(param_2 + 0x98),
                *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)(param_2 + 0x30))
  ;
  FUN_18000b020(*(undefined8 *)(param_2 + 0x80),*(void **)(param_2 + 0x20),
                *(longlong *)(param_2 + 0x88));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}

/* ---- FUNC 0004FD60 FUN_18004fd60 (183 bytes) ---- */

undefined8 FUN_18004fd60(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  int iVar2;
  
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x30));
  plVar1 = *(longlong **)(param_2 + 0x38);
  iVar2 = (**(code **)(*plVar1 + 0x28))(plVar1,param_2 + 0x40,0x200,0);
  if (iVar2 == 0) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x30),
               "%Ts (%Ts:%d)","Exception thrown in destructor",
               "g:\\Program Files\\Microsoft Visual Studio\\2022\\Enterprise\\VC\\Tools\\MSVC\\14.37.32822\\atlmfc\\include\\afxwin1.inl"
               ,0x4d);
  }
  else {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x30),
               "%Ts (%Ts:%d)\n%Ts","Exception thrown in destructor",
               "g:\\Program Files\\Microsoft Visual Studio\\2022\\Enterprise\\VC\\Tools\\MSVC\\14.37.32822\\atlmfc\\include\\afxwin1.inl"
               ,0x4d,param_2 + 0x40);
  }
  AfxMessageBox(*(char **)(param_2 + 0x30),0,0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x30));
  (**(code **)(*plVar1 + 8))(plVar1,1);
  return 0;
}

/* ---- FUNC 0004FE40 FUN_18004fe40 (29 bytes) ---- */

void FUN_18004fe40(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x38));
  return;
}

/* ---- FUNC 0004FE70 FUN_18004fe70 (29 bytes) ---- */

void FUN_18004fe70(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x48));
  return;
}

/* ---- FUNC 0004FF20 FUN_18004ff20 (32 bytes) ---- */

void FUN_18004ff20(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x88));
  return;
}

/* ---- FUNC 0004FF60 FUN_18004ff60 (29 bytes) ---- */

void FUN_18004ff60(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x38));
  return;
}

/* ---- FUNC 0004FF80 FUN_18004ff80 (29 bytes) ---- */

void FUN_18004ff80(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x30));
  return;
}

/* ---- FUNC 00050060 FUN_180050060 (39 bytes) ---- */

void FUN_180050060(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x30) & 1) != 0) {
    *(uint *)(param_2 + 0x30) = *(uint *)(param_2 + 0x30) & 0xfffffffe;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              (*(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)(param_2 + 0x40));
  }
  return;
}

/* ---- FUNC 00050090 FUN_180050090 (39 bytes) ---- */

void FUN_180050090(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x30) & 2) != 0) {
    *(uint *)(param_2 + 0x30) = *(uint *)(param_2 + 0x30) & 0xfffffffd;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x38));
  }
  return;
}

/* ---- FUNC 000500D0 FUN_1800500d0 (29 bytes) ---- */

void FUN_1800500d0(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x30));
  return;
}

/* ---- FUNC 000500F0 FUN_1800500f0 (32 bytes) ---- */

void FUN_1800500f0(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 200));
  return;
}

/* ---- FUNC 00050150 FUN_180050150 (29 bytes) ---- */

void FUN_180050150(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x68));
  return;
}

/* ---- FUNC 00050170 FUN_180050170 (29 bytes) ---- */

void FUN_180050170(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x68));
  return;
}

/* ---- FUNC 000501C0 FUN_1800501c0 (32 bytes) ---- */

void FUN_1800501c0(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x80));
  return;
}

/* ---- FUNC 000501E0 FUN_1800501e0 (32 bytes) ---- */

void FUN_1800501e0(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x88));
  return;
}

/* ---- FUNC 000502F0 FUN_1800502f0 (32 bytes) ---- */

void FUN_1800502f0(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x98));
  return;
}

/* ---- FUNC 00050310 FUN_180050310 (32 bytes) ---- */

void FUN_180050310(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0xa0));
  return;
}

/* ---- FUNC 000503C0 FUN_1800503c0 (39 bytes) ---- */

void FUN_1800503c0(undefined8 param_1,longlong param_2)

{
  deallocate(*(undefined8 *)(param_2 + 0x40),*(void **)(param_2 + 0x50),
             *(longlong *)(param_2 + 0x48));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}

/* ---- FUNC 000503F0 FUN_1800503f0 (39 bytes) ---- */

void FUN_1800503f0(undefined8 param_1,longlong param_2)

{
  FUN_18000b020(*(undefined8 *)(param_2 + 0x40),*(void **)(param_2 + 0x50),
                *(longlong *)(param_2 + 0x48));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}

/* ---- FUNC 00050430 FUN_180050430 (48 bytes) ---- */

void FUN_180050430(undefined8 param_1,longlong param_2)

{
  _Tree_val<std::_Tree_simple_types<std::pair<CAPString_const_,int>_>_> *p_Var1;
  
  p_Var1 = std::
           _Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
           ::_Get_scary(*(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
                          **)(param_2 + 0x50));
  FUN_180017be0(*(undefined8 *)(param_2 + 0x50),p_Var1,*(longlong **)(param_2 + 0x58));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}

/* ---- FUNC 00050470 FUN_180050470 (48 bytes) ---- */

void FUN_180050470(undefined8 param_1,longlong param_2)

{
  _Tree_val<std::_Tree_simple_types<std::pair<CAPString_const_,int>_>_> *p_Var1;
  
  p_Var1 = std::
           _Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
           ::_Get_scary(*(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
                          **)(param_2 + 0x50));
  FUN_180017c40(*(undefined8 *)(param_2 + 0x50),p_Var1,*(longlong **)(param_2 + 0x58));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}

/* ---- FUNC 000504C0 FUN_1800504c0 (48 bytes) ---- */

void FUN_1800504c0(undefined8 param_1,longlong param_2)

{
  _Tree_val<std::_Tree_simple_types<std::pair<CAPString_const_,int>_>_> *p_Var1;
  
  p_Var1 = std::
           _Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
           ::_Get_scary(*(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
                          **)(param_2 + 0x60));
  FUN_180017cc0(*(undefined8 *)(param_2 + 0x60),p_Var1,*(longlong **)(param_2 + 0x68));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}

/* ---- FUNC 00050510 FUN_180050510 (48 bytes) ---- */

void FUN_180050510(undefined8 param_1,longlong param_2)

{
  _Tree_val<std::_Tree_simple_types<std::pair<CAPString_const_,int>_>_> *p_Var1;
  
  p_Var1 = std::
           _Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
           ::_Get_scary(*(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
                          **)(param_2 + 0x60));
  FUN_180017e00(*(undefined8 *)(param_2 + 0x60),p_Var1,*(longlong **)(param_2 + 0x68));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}

/* ---- FUNC 00050550 FUN_180050550 (60 bytes) ---- */

void FUN_180050550(undefined8 param_1,longlong param_2)

{
  FUN_1800081e0(*(longlong **)(param_2 + 0x88),*(longlong **)(param_2 + 0x28));
  FUN_18000b020(*(undefined8 *)(param_2 + 0x70),*(void **)(param_2 + 0x20),
                *(longlong *)(param_2 + 0x78));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}

/* ---- FUNC 000505B0 FUN_1800505b0 (58 bytes) ---- */

undefined8 FUN_1800505b0(undefined8 param_1,longlong param_2)

{
  std::basic_ios<char,std::char_traits<char>_>::setstate
            ((basic_ios<char,std::char_traits<char>_> *)
             ((longlong)*(int *)(**(longlong **)(param_2 + 0x70) + 4) +
             (longlong)*(longlong **)(param_2 + 0x70)),4,true);
  return 0;
}

/* ---- FUNC 00050630 FUN_180050630 (39 bytes) ---- */

void FUN_180050630(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x30) & 1) != 0) {
    *(uint *)(param_2 + 0x30) = *(uint *)(param_2 + 0x30) & 0xfffffffe;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              (*(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)(param_2 + 0x50));
  }
  return;
}

/* ---- FUNC 00050660 FUN_180050660 (40 bytes) ---- */

void FUN_180050660(undefined8 param_1,longlong param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_2 + 0x50);
  if ((*puVar1 & 1) != 0) {
    *puVar1 = *puVar1 & 0xfffffffe;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              (*(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)(param_2 + 0x90));
  }
  return;
}

/* ---- FUNC 000506C0 FUN_1800506c0 (30 bytes) ---- */

void FUN_1800506c0(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x70));
  return;
}

/* ---- FUNC 00050730 FUN_180050730 (52 bytes) ---- */

void FUN_180050730(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x188) & 1) != 0) {
    *(uint *)(param_2 + 0x188) = *(uint *)(param_2 + 0x188) & 0xfffffffe;
    std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>
              ((basic_ios<char,std::char_traits<char>_> *)(param_2 + 0xd0));
  }
  return;
}

/* ---- FUNC 000507A0 FUN_1800507a0 (39 bytes) ---- */

void FUN_1800507a0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x30) & 1) != 0) {
    *(uint *)(param_2 + 0x30) = *(uint *)(param_2 + 0x30) & 0xfffffffe;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x38));
  }
  return;
}

/* ---- FUNC 00050850 FUN_180050850 (32 bytes) ---- */

void FUN_180050850(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x80));
  return;
}

/* ---- FUNC 00050870 FUN_180050870 (29 bytes) ---- */

void FUN_180050870(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x28));
  return;
}

/* ---- FUNC 00050940 FUN_180050940 (43 bytes) ---- */

undefined8 FUN_180050940(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0xa0) = *(undefined8 *)(param_2 + 0xb8);
  return 0;
}

/* ---- FUNC 00050970 FUN_180050970 (43 bytes) ---- */

undefined8 FUN_180050970(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0xa0) = *(undefined8 *)(param_2 + 0xc0);
  return 0;
}

/* ---- FUNC 000509C0 FUN_1800509c0 (48 bytes) ---- */

void FUN_1800509c0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x88) & 1) != 0) {
    *(uint *)(param_2 + 0x88) = *(uint *)(param_2 + 0x88) & 0xfffffffe;
    FUN_180009380((longlong *)(*(longlong *)(param_2 + 0x20) + 8));
  }
  return;
}

/* ---- FUNC 000509F0 FUN_1800509f0 (57 bytes) ---- */

void FUN_1800509f0(undefined8 param_1,longlong param_2)

{
  _Tree_val<std::_Tree_simple_types<std::pair<CAPString_const_,int>_>_> *p_Var1;
  
  p_Var1 = std::
           _Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
           ::_Get_scary(*(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
                          **)(param_2 + 0x80));
  FUN_1800289a0(*(undefined8 *)(param_2 + 0x80),p_Var1,*(longlong **)(param_2 + 0x88));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}

/* ---- FUNC 00050BD0 FUN_180050bd0 (60 bytes) ---- */

undefined8 FUN_180050bd0(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  
  plVar1 = *(longlong **)(param_2 + 0x48);
  if (plVar1 != (longlong *)0x0) {
    *(undefined8 *)(param_2 + 0x48) = 0;
    (**(code **)(*plVar1 + 0x10))();
  }
  *(undefined4 *)(param_2 + 0x58) = 0x80004005;
  return 0;
}

/* ---- FUNC 00050CA0 FUN_180050ca0 (46 bytes) ---- */

void FUN_180050ca0(undefined8 param_1,longlong param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_2 + 0x40);
  if ((*puVar1 & 4) != 0) {
    *puVar1 = *puVar1 & 0xfffffffb;
    FUN_180009380((longlong *)(param_2 + 0x148));
  }
  return;
}

/* ---- FUNC 00050CD0 FUN_180050cd0 (46 bytes) ---- */

void FUN_180050cd0(undefined8 param_1,longlong param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_2 + 0x40);
  if ((*puVar1 & 8) != 0) {
    *puVar1 = *puVar1 & 0xfffffff7;
    FUN_180009380((longlong *)(param_2 + 0x170));
  }
  return;
}

/* ---- FUNC 00050D00 FUN_180050d00 (46 bytes) ---- */

void FUN_180050d00(undefined8 param_1,longlong param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_2 + 0x40);
  if ((*puVar1 & 0x10) != 0) {
    *puVar1 = *puVar1 & 0xffffffef;
    FUN_180009380((longlong *)(param_2 + 0x170));
  }
  return;
}

/* ---- FUNC 00050D30 FUN_180050d30 (46 bytes) ---- */

void FUN_180050d30(undefined8 param_1,longlong param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_2 + 0x40);
  if ((*puVar1 & 0x20) != 0) {
    *puVar1 = *puVar1 & 0xffffffdf;
    FUN_180009380((longlong *)(param_2 + 0x170));
  }
  return;
}

/* ---- FUNC 00050D60 FUN_180050d60 (46 bytes) ---- */

void FUN_180050d60(undefined8 param_1,longlong param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_2 + 0x40);
  if ((*puVar1 & 0x40) != 0) {
    *puVar1 = *puVar1 & 0xffffffbf;
    FUN_180009380((longlong *)(param_2 + 0x170));
  }
  return;
}

/* ---- FUNC 00050D90 FUN_180050d90 (51 bytes) ---- */

void FUN_180050d90(undefined8 param_1,longlong param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_2 + 0x40);
  if ((*puVar1 & 0x80) != 0) {
    *puVar1 = *puVar1 & 0xffffff7f;
    FUN_180009380((longlong *)(param_2 + 0x170));
  }
  return;
}

/* ---- FUNC 00050DD0 FUN_180050dd0 (51 bytes) ---- */

void FUN_180050dd0(undefined8 param_1,longlong param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_2 + 0x40);
  if ((*puVar1 & 0x100) != 0) {
    *puVar1 = *puVar1 & 0xfffffeff;
    FUN_180009380((longlong *)(param_2 + 0x170));
  }
  return;
}

/* ---- FUNC 00050E20 FUN_180050e20 (51 bytes) ---- */

void FUN_180050e20(undefined8 param_1,longlong param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_2 + 0x40);
  if ((*puVar1 & 0x200) != 0) {
    *puVar1 = *puVar1 & 0xfffffdff;
    FUN_180009380((longlong *)(*(longlong *)(param_2 + 0x128) + 8));
  }
  return;
}

/* ---- FUNC 00050E60 FUN_180050e60 (51 bytes) ---- */

void FUN_180050e60(undefined8 param_1,longlong param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_2 + 0x40);
  if ((*puVar1 & 0x400) != 0) {
    *puVar1 = *puVar1 & 0xfffffbff;
    FUN_180009380((longlong *)(param_2 + 0x170));
  }
  return;
}

/* ---- FUNC 00050EA0 FUN_180050ea0 (51 bytes) ---- */

void FUN_180050ea0(undefined8 param_1,longlong param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_2 + 0x40);
  if ((*puVar1 & 0x800) != 0) {
    *puVar1 = *puVar1 & 0xfffff7ff;
    FUN_180009380((longlong *)(param_2 + 0x170));
  }
  return;
}

/* ---- FUNC 00050EE0 FUN_180050ee0 (51 bytes) ---- */

void FUN_180050ee0(undefined8 param_1,longlong param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_2 + 0x40);
  if ((*puVar1 & 0x1000) != 0) {
    *puVar1 = *puVar1 & 0xffffefff;
    FUN_180009380((longlong *)(param_2 + 0x170));
  }
  return;
}

/* ---- FUNC 00050F20 FUN_180050f20 (54 bytes) ---- */

undefined8 FUN_180050f20(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  
  plVar1 = *(longlong **)(param_2 + 0x58);
  if (plVar1 != (longlong *)0x0) {
    *(undefined8 *)(param_2 + 0x58) = 0;
    (**(code **)(*plVar1 + 0x10))();
  }
  return 0;
}

/* ---- FUNC 00050FF0 FUN_180050ff0 (42 bytes) ---- */

void FUN_180050ff0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x60) & 1) != 0) {
    *(uint *)(param_2 + 0x60) = *(uint *)(param_2 + 0x60) & 0xfffffffe;
    FUN_180009380((longlong *)(*(longlong *)(param_2 + 0x50) + 8));
  }
  return;
}

/* ---- FUNC 00051020 FUN_180051020 (39 bytes) ---- */

void FUN_180051020(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x38) & 1) != 0) {
    *(uint *)(param_2 + 0x38) = *(uint *)(param_2 + 0x38) & 0xfffffffe;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x40));
  }
  return;
}

/* ---- FUNC 00051050 FUN_180051050 (66 bytes) ---- */

void FUN_180051050(undefined8 param_1,longlong param_2)

{
  FUN_18003c3f0(*(longlong **)(param_2 + 0x28),*(longlong **)(param_2 + 0x30));
  deallocate(*(undefined8 *)(param_2 + 0x80),*(void **)(param_2 + 0x20),
             *(longlong *)(param_2 + 0x98));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}

/* ---- FUNC 000510A0 FUN_1800510a0 (69 bytes) ---- */

void FUN_1800510a0(undefined8 param_1,longlong param_2)

{
  FUN_18003c480(*(undefined8 **)(param_2 + 0x20),*(undefined8 **)(param_2 + 0x30));
  deallocate(*(undefined8 *)(param_2 + 0x80),*(void **)(param_2 + 0x98),
             *(longlong *)(param_2 + 0x88));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}

/* ---- FUNC 00051100 FUN_180051100 (39 bytes) ---- */

void FUN_180051100(undefined8 param_1,longlong param_2)

{
  deallocate(*(undefined8 *)(param_2 + 0x60),*(void **)(param_2 + 0x70),
             *(longlong *)(param_2 + 0x68));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}

/* ---- FUNC 00051180 FUN_180051180 (29 bytes) ---- */

void FUN_180051180(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x50));
  return;
}

/* ---- FUNC 000511C0 FUN_1800511c0 (29 bytes) ---- */

void FUN_1800511c0(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x30));
  return;
}

/* ---- FUNC 000511F0 FUN_1800511f0 (29 bytes) ---- */

void FUN_1800511f0(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x30));
  return;
}

/* ---- FUNC 00051210 FUN_180051210 (29 bytes) ---- */

void FUN_180051210(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x20));
  return;
}

/* ---- FUNC 00051230 FUN_180051230 (29 bytes) ---- */

undefined8 FUN_180051230(void)

{
  return 0;
}

/* ---- FUNC 00051260 Catch_All@180051260 (26 bytes) ---- */

undefined * Catch_All_180051260(void)

{
  return &DAT_180045ce4;
}

/* ---- FUNC 0005127B FUN_18005127b (43 bytes) ---- */

void FUN_18005127b(undefined8 param_1,longlong param_2)

{
  if (*(char *)(param_2 + 0x20) == '\0') {
    __ArrayUnwind(*(void **)(param_2 + 0x50),*(__uint64 *)(param_2 + 0x58),
                  *(__uint64 *)(param_2 + 0x28),*(_func_void_void_ptr **)(param_2 + 0x70));
  }
  return;
}

/* ---- FUNC 000512A7 FUN_1800512a7 (43 bytes) ---- */

void FUN_1800512a7(undefined8 param_1,longlong param_2)

{
  if (*(char *)(param_2 + 0x20) == '\0') {
    __ArrayUnwind(*(void **)(param_2 + 0x60),*(__uint64 *)(param_2 + 0x68),
                  *(__uint64 *)(param_2 + 0x70),*(_func_void_void_ptr **)(param_2 + 0x78));
  }
  return;
}

/* ---- FUNC 000512D3 FUN_1800512d3 (94 bytes) ---- */

undefined4 FUN_1800512d3(undefined8 param_1,longlong param_2)

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

/* ---- FUNC 00051332 FUN_180051332 (23 bytes) ---- */

bool FUN_180051332(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}

/* ---- FUNC 0005134A FUN_18005134a (22 bytes) ---- */

void FUN_18005134a(undefined8 param_1,longlong param_2)

{
  __scrt_release_startup_lock(*(char *)(param_2 + 0x40));
  return;
}

/* ---- FUNC 00051361 FUN_180051361 (24 bytes) ---- */

void FUN_180051361(undefined8 param_1,longlong param_2)

{
  __scrt_release_startup_lock(*(char *)(param_2 + 0x20));
  return;
}

/* ---- FUNC 0005137A FUN_18005137a (19 bytes) ---- */

void FUN_18005137a(void)

{
  FUN_180046b64();
  return;
}

/* ---- FUNC 0005138E FUN_18005138e (53 bytes) ---- */

void FUN_18005138e(undefined8 *param_1,longlong param_2)

{
  __scrt_dllmain_exception_filter
            (*(undefined8 *)(param_2 + 0x60),*(int *)(param_2 + 0x68),
             *(undefined8 *)(param_2 + 0x70),FUN_180047200,*(undefined4 *)*param_1,param_1);
  return;
}

/* ---- FUNC 000513D0 FUN_1800513d0 (29 bytes) ---- */

undefined8 FUN_1800513d0(void)

{
  return 0;
}

/* ---- FUNC 00051490 FUN_180051490 (249 bytes) ---- */

void FUN_180051490(void)

{
  char cVar1;
  longlong *plVar2;
  void *pvVar3;
  longlong *plVar4;
  void *pvVar5;
  
  cVar1 = *(char *)((longlong)*(longlong **)((longlong)DAT_18007a288 + 8) + 0x19);
  plVar4 = *(longlong **)((longlong)DAT_18007a288 + 8);
  do {
    if (cVar1 != '\0') {
      operator_delete(DAT_18007a288);
      return;
    }
    FUN_180017d80(&DAT_18007a288,&DAT_18007a288,(longlong *)plVar4[2]);
    plVar2 = (longlong *)*plVar4;
    FUN_180017c40(plVar4 + 8,plVar4 + 8,*(longlong **)(plVar4[8] + 8));
    operator_delete((void *)plVar4[8]);
    if (0xf < (ulonglong)plVar4[7]) {
      pvVar3 = (void *)plVar4[4];
      pvVar5 = pvVar3;
      if ((0xfff < plVar4[7] + 1U) &&
         (pvVar5 = *(void **)((longlong)pvVar3 + -8),
         0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)pvVar5)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      operator_delete(pvVar5);
    }
    plVar4[6] = 0;
    plVar4[7] = 0xf;
    *(undefined1 *)(plVar4 + 4) = 0;
    operator_delete(plVar4);
    cVar1 = *(char *)((longlong)plVar2 + 0x19);
    plVar4 = plVar2;
  } while( true );
}

/* ---- FUNC 00051590 FUN_180051590 (249 bytes) ---- */

void FUN_180051590(void)

{
  char cVar1;
  longlong *plVar2;
  void *pvVar3;
  longlong *plVar4;
  void *pvVar5;
  
  cVar1 = *(char *)((longlong)*(longlong **)((longlong)DAT_18007a278 + 8) + 0x19);
  plVar4 = *(longlong **)((longlong)DAT_18007a278 + 8);
  do {
    if (cVar1 != '\0') {
      operator_delete(DAT_18007a278);
      return;
    }
    FUN_180017e80(&DAT_18007a278,&DAT_18007a278,(longlong *)plVar4[2]);
    plVar2 = (longlong *)*plVar4;
    FUN_180017e00(plVar4 + 8,plVar4 + 8,*(longlong **)(plVar4[8] + 8));
    operator_delete((void *)plVar4[8]);
    if (0xf < (ulonglong)plVar4[7]) {
      pvVar3 = (void *)plVar4[4];
      pvVar5 = pvVar3;
      if ((0xfff < plVar4[7] + 1U) &&
         (pvVar5 = *(void **)((longlong)pvVar3 + -8),
         0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)pvVar5)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      operator_delete(pvVar5);
    }
    plVar4[6] = 0;
    plVar4[7] = 0xf;
    *(undefined1 *)(plVar4 + 4) = 0;
    operator_delete(plVar4);
    cVar1 = *(char *)((longlong)plVar2 + 0x19);
    plVar4 = plVar2;
  } while( true );
}

/* ---- FUNC 000516E0 FUN_1800516e0 (48 bytes) ---- */

void FUN_1800516e0(void)

{
  void *pvVar1;
  
  FUN_18002c5b0(0x18007b6d8);
  pvVar1 = DAT_18007b6d8;
  DAT_18007b6d8 = (void *)0x0;
  operator_delete(pvVar1);
  return;
}

/* ---- FUNC 00051730 FUN_180051730 (100 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180051730(void)

{
  void *pvVar1;
  void *pvVar2;
  
  if (0xf < DAT_180072240) {
    pvVar1 = (void *)CONCAT71(DAT_180072228._1_7_,(undefined1)DAT_180072228);
    pvVar2 = pvVar1;
    if ((0xfff < DAT_180072240 + 1) &&
       (pvVar2 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar2);
  }
  DAT_180072238 = _DAT_180053820;
  DAT_180072240 = _UNK_180053828;
  DAT_180072228._0_1_ = 0;
  return;
}

/* ---- FUNC 000517A0 FUN_1800517a0 (100 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1800517a0(void)

{
  void *pvVar1;
  void *pvVar2;
  
  if (0xf < DAT_180072220) {
    pvVar1 = (void *)CONCAT71(DAT_180072208._1_7_,(undefined1)DAT_180072208);
    pvVar2 = pvVar1;
    if ((0xfff < DAT_180072220 + 1) &&
       (pvVar2 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar2);
  }
  DAT_180072218 = _DAT_180053820;
  DAT_180072220 = _UNK_180053828;
  DAT_180072208._0_1_ = 0;
  return;
}

/* ---- FUNC 00051810 FUN_180051810 (99 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180051810(void)

{
  void *pvVar1;
  void *pvVar2;
  
  if (0xf < DAT_1800791e0) {
    pvVar1 = (void *)CONCAT71(DAT_1800791c8._1_7_,(undefined1)DAT_1800791c8);
    pvVar2 = pvVar1;
    if ((0xfff < DAT_1800791e0 + 1) &&
       (pvVar2 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar2);
  }
  DAT_1800791d8 = _DAT_180053820;
  DAT_1800791e0 = _UNK_180053828;
  DAT_1800791c8._0_1_ = 0;
  return;
}

/* ---- FUNC 00051880 ~_Fac_tidy_reg_t (91 bytes) ---- */

/* Library Function - Single Match
    public: __cdecl std::_Fac_tidy_reg_t::~_Fac_tidy_reg_t(void) __ptr64
   
   Library: Visual Studio 2019 Release */

void __thiscall std::_Fac_tidy_reg_t::~_Fac_tidy_reg_t(_Fac_tidy_reg_t *this)

{
  undefined8 *puVar1;
  longlong lVar2;
  
  while (puVar1 = DAT_18009c228, DAT_18009c228 != (undefined8 *)0x0) {
    DAT_18009c228 = (undefined8 *)*DAT_18009c228;
    lVar2 = (*(code *)PTR__guard_dispatch_icall_180053248)();
    if (lVar2 != 0) {
      (*(code *)PTR__guard_dispatch_icall_180053248)(lVar2,1);
    }
    operator_delete(puVar1);
  }
  return;
}

/* ---- FUNC 000518E0 FUN_1800518e0 (14 bytes) ---- */

void FUN_1800518e0(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800518e7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  VariantClear((VARIANTARG *)&DAT_180079238);
  return;
}
