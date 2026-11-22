/* RVA 0x9f00 */
CWinThread * FUN_180009f00(CWinThread *param_1,uint param_2)

{
  if ((param_2 & 2) != 0) {
    _eh_vector_destructor_iterator_
              (param_1,0x88,*(__uint64 *)(param_1 + -8),CSimEventsThread::~CSimEventsThread);
    if ((param_2 & 1) != 0) {
      operator_delete__(param_1 + -8);
    }
    return param_1 + -8;
  }
  CWinThread::~CWinThread(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    FUN_180001300(param_1);
  }
  return param_1;
}

/* RVA 0x9fb0 */
/* public: virtual int __cdecl CSimEventsThread::ExitInstance(void) __ptr64 */

int __thiscall CSimEventsThread::ExitInstance(CSimEventsThread *this)

{
  int iVar1;
  
                    /* 0x9fb0  32  ?ExitInstance@CSimEventsThread@@UEAAHXZ */
  CoUninitialize();
  iVar1 = CWinThread::ExitInstance((CWinThread *)this);
  return iVar1;
}

/* RVA 0x9fd0 */
/* protected: virtual struct AFX_MSGMAP const * __ptr64 __cdecl
   CSimEventsThread::GetMessageMap(void)const __ptr64 */

AFX_MSGMAP * __thiscall CSimEventsThread::GetMessageMap(CSimEventsThread *this)

{
                    /* 0x9fd0  35  ?GetMessageMap@CSimEventsThread@@MEBAPEBUAFX_MSGMAP@@XZ */
  return (AFX_MSGMAP *)&PTR_LAB_1800403d0;
}

/* RVA 0x9fe0 */
/* public: virtual struct CRuntimeClass * __ptr64 __cdecl
   CSimEventsThread::GetRuntimeClass(void)const __ptr64 */

CRuntimeClass * __cdecl CSimEventsThread::GetRuntimeClass(void)

{
                    /* 0x9fe0  36  ?GetRuntimeClass@CSimEventsThread@@UEBAPEAUCRuntimeClass@@XZ
                       0x9fe0  38  ?GetThisClass@CSimEventsThread@@SAPEAUCRuntimeClass@@XZ */
  return (CRuntimeClass *)&classCSimEventsThread;
}

/* RVA 0x9ff0 */
/* protected: static struct AFX_MSGMAP const * __ptr64 __cdecl
   CSimEventsThread::GetThisMessageMap(void) */

AFX_MSGMAP * __cdecl CSimEventsThread::GetThisMessageMap(void)

{
                    /* 0x9ff0  43  ?GetThisMessageMap@CSimEventsThread@@KAPEBUAFX_MSGMAP@@XZ */
  return (AFX_MSGMAP *)&PTR_LAB_1800403d0;
}

/* RVA 0xa000 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: virtual int __cdecl CSimEventsThread::InitInstance(void) __ptr64 */

int __thiscall CSimEventsThread::InitInstance(CSimEventsThread *this)

{
  int iVar1;
  undefined1 auStack_438 [32];
  longlong *local_418 [2];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
                    /* 0xa000  45  ?InitInstance@CSimEventsThread@@UEAAHXZ */
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_438;
  m_hSync = (void *)GetGlobalPointer("DCOM_EVENT");
  CoInitialize((LPVOID)0x0);
  local_418[0] = (longlong *)0x0;
  iVar1 = Ordinal_78(local_418);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_180001a40();
    if (iVar1 == 0) {
      FUN_180008f80(local_408,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\Simdll\\SimEvents.cpp",0x5b);
      LogMessage(local_408,2,1);
    }
    (**(code **)(*local_418[0] + 0x10))();
    iVar1 = 1;
    m_stpEvents = (CWinThread *)this;
  }
  return iVar1;
}

/* RVA 0xa0c0 */
/* public: void __cdecl CSimEventsThread::OnSimEventHangup(unsigned __int64,__int64) __ptr64 */

void __thiscall
CSimEventsThread::OnSimEventHangup(CSimEventsThread *this,__uint64 param_1,__int64 param_2)

{
                    /* 0xa0c0  46  ?OnSimEventHangup@CSimEventsThread@@QEAAX_K_J@Z */
  FUN_1800019f0();
  m_stpEvents = (CWinThread *)0x0;
  SetEvent(m_hSync);
                    /* WARNING: Could not recover jumptable at 0x00018000a0e7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  PostQuitMessage(0);
  return;
}

/* RVA 0xa0f0 */
/* public: static void __cdecl CSimEventsThread::SimEventHangup(void) */

void __cdecl CSimEventsThread::SimEventHangup(void)

{
  DWORD DVar1;
  
                    /* 0xa0f0  48  ?SimEventHangup@CSimEventsThread@@SAXXZ */
  if (m_stpEvents != (CWinThread *)0x0) {
    ResetEvent(m_hSync);
    PostThreadMessageA(*(DWORD *)(m_stpEvents + 0x60),0x549,0,0);
    DVar1 = WaitForSingleObject(m_hSync,10000);
    if (DVar1 == 0x102) {
                    /* WARNING: Could not recover jumptable at 0x00018000a14a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      SetEvent(m_hSync);
      return;
    }
  }
  return;
}

/* RVA 0xa160 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */

undefined8 FUN_18000a160(int param_1,VARIANTARG *param_2,VARIANTARG *param_3)

{
  LPCWSTR lpWideCharStr;
  LPSTREAM pIVar1;
  HRESULT HVar2;
  UINT UVar3;
  int iVar4;
  longlong lVar6;
  longlong lVar5;
  HANDLE hEvent;
  ulonglong uVar7;
  void *pv;
  undefined8 pv_00;
  char *pcVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  ULONG cb;
  ULONG cb_00;
  undefined8 bstr;
  bool bVar11;
  undefined8 uStack_e0;
  undefined1 auStack_d8 [32];
  undefined8 uStack_b8;
  int aiStack_b0 [2];
  undefined8 local_a8 [2];
  void *local_98;
  ULONG local_90 [2];
  _union_2707 local_88;
  _union_2707 local_70;
  LPSTREAM local_58;
  _union_2707 local_50;
  ulonglong local_38;
  
  local_38 = DAT_1800516d8 ^ (ulonglong)&local_98;
  local_58 = (IStream *)0x0;
  cb_00 = 1;
  uStack_e0 = 0x18000a1bd;
  HVar2 = CreateStreamOnHGlobal((HGLOBAL)0x0,1,&local_58);
  if (HVar2 < 0) goto LAB_18000a650;
  local_70._0_8_ = 0;
  local_70.decVal.u2 = (_union_1719)0;
  local_70._16_8_ = (IRecordInfo *)0x0;
  uStack_e0 = 0x18000a1dc;
  VariantInit((VARIANTARG *)&local_70);
  local_88._0_8_ = 0;
  local_88.decVal.u2 = (_union_1719)(_struct_1720)0x0;
  local_88._16_8_ = (IRecordInfo *)0x0;
  uStack_e0 = 0x18000a1f4;
  VariantInit((VARIANTARG *)&local_88);
  if ((param_2 != (VARIANTARG *)0x0) && ((VARIANTARG *)&local_70 != param_2)) {
    uStack_e0 = 0x18000a20d;
    HVar2 = VariantClear((VARIANTARG *)&local_70);
    if (-1 < HVar2) {
      local_70.n2.vt = (param_2->n1).n2.vt;
      local_70.n2.wReserved1 = (param_2->n1).n2.wReserved1;
      local_70.n2.wReserved2 = (param_2->n1).n2.wReserved2;
      local_70.n2.wReserved3 = (param_2->n1).n2.wReserved3;
      local_70.decVal.u2 = (_union_1719)(param_2->n1).n2.n3.punkVal;
      local_70._16_8_ = (param_2->n1).n2.n3.brecVal.pRecInfo;
      (param_2->n1).n2.vt = 0;
    }
  }
  pIVar1 = local_58;
  if (local_58 == (IStream *)0x0) goto LAB_18000a3e7;
  uStack_e0 = 0x18000a250;
  HVar2 = (*local_58->lpVtbl->Write)(local_58,&local_70,2,(ULONG *)0x0);
  if (HVar2 < 0) goto LAB_18000a3e7;
  switch(local_70.n2.vt) {
  case 2:
  case 0xb:
  case 0x12:
    cb = 2;
    break;
  case 3:
  case 4:
  case 10:
  case 0x13:
  case 0x16:
  case 0x17:
    cb = 4;
    break;
  case 5:
  case 6:
  case 7:
  case 0x14:
  case 0x15:
    cb = 8;
    break;
  default:
    pv = (void *)0x0;
    local_50._0_8_ = 0;
    local_50.decVal.u2 = (_union_1719)0;
    local_50._16_8_ = 0;
    uStack_e0 = 0x18000a343;
    VariantInit((VARIANTARG *)&local_50.n2);
    if (local_70.n2.vt == 8) {
      local_98 = (void *)local_70._8_8_;
LAB_18000a36f:
      if (local_98 == (void *)0x0) {
        iVar4 = 4;
      }
      else {
        uStack_e0 = 0x18000a384;
        SysFreeString((BSTR)0x0);
        pv = local_98;
        uStack_e0 = 0x18000a391;
        UVar3 = SysStringByteLen(local_98);
        iVar4 = UVar3 + 6;
      }
      local_90[0] = iVar4 - 4;
      uStack_e0 = 0x18000a3b1;
      HVar2 = (*pIVar1->lpVtbl->Write)(pIVar1,local_90,4,(ULONG *)&local_98);
      if ((-1 < HVar2) && (local_90[0] != 0)) {
        uStack_e0 = 0x18000a3ce;
        (*pIVar1->lpVtbl->Write)(pIVar1,pv,local_90[0],(ULONG *)&local_98);
      }
    }
    else {
      uStack_e0 = 0x18000a361;
      HVar2 = VariantChangeType((VARIANTARG *)&local_50.n2,(VARIANTARG *)&local_70,1,8);
      if (-1 < HVar2) {
        local_98 = (void *)local_50._8_8_;
        goto LAB_18000a36f;
      }
    }
    uStack_e0 = 0x18000a3d8;
    VariantClear((VARIANTARG *)&local_50.n2);
    uStack_e0 = 0x18000a3e0;
    SysFreeString((BSTR)0x0);
    goto LAB_18000a3e7;
  case 9:
  case 0xd:
    local_98 = (void *)0x0;
    if (local_70.decVal.u2 == 0) {
LAB_18000a2e7:
      uStack_e0 = 0x18000a2f7;
      WriteClassStm(pIVar1,(IID *)&DAT_180043ef8);
    }
    else {
      uStack_e0 = 0x18000a29b;
      HVar2 = (*(*(IPersistStreamVtbl **)local_70.decVal.u2)->QueryInterface)
                        ((IPersistStream *)local_70.decVal.u2,(IID *)&DAT_180040260,&local_98);
      if (HVar2 < 0) {
        uStack_e0 = 0x18000a2b3;
        HVar2 = (*(*(IPersistStreamVtbl **)local_70.decVal.u2)->QueryInterface)
                          ((IPersistStream *)local_70.decVal.u2,(IID *)&DAT_180040270,&local_98);
        if (HVar2 < 0) goto LAB_18000a3e7;
      }
      if (local_98 == (void *)0x0) goto LAB_18000a2e7;
      uStack_e0 = 0x18000a2ce;
      OleSaveToStream(local_98,pIVar1);
    }
    if (local_98 != (void *)0x0) {
      uStack_e0 = 0x18000a2e2;
      (*(*(IPersistStreamVtbl **)local_98)->Release)(local_98);
    }
    goto LAB_18000a3e7;
  case 0x10:
  case 0x11:
    cb = 1;
  }
  uStack_e0 = 0x18000a324;
  (*pIVar1->lpVtbl->Write)(pIVar1,(void *)((longlong)&local_70.n2 + 8),cb,(ULONG *)0x0);
LAB_18000a3e7:
  if (param_2 != (VARIANTARG *)0x0) {
    uStack_e0 = 0x18000a3f5;
    HVar2 = VariantClear(param_2);
    if (-1 < HVar2) {
      (param_2->n1).n2.vt = local_70._0_2_;
      (param_2->n1).n2.wReserved1 = local_70.n2.wReserved1;
      (param_2->n1).n2.wReserved2 = local_70.n2.wReserved2;
      (param_2->n1).n2.wReserved3 = local_70.n2.wReserved3;
      (param_2->n1).n2.n3.llVal = (LONGLONG)local_70.decVal.u2;
      (param_2->n1).n2.n3.brecVal.pRecInfo = (IRecordInfo *)local_70._16_8_;
      local_70._0_8_ = local_70._0_8_ & 0xffffffffffff0000;
    }
  }
  if ((param_3 != (VARIANTARG *)0x0) && ((VARIANTARG *)&local_88 != param_3)) {
    uStack_e0 = 0x18000a428;
    HVar2 = VariantClear((VARIANTARG *)&local_88);
    if (-1 < HVar2) {
      local_88.n2.vt = (param_3->n1).n2.vt;
      local_88.n2.wReserved1 = (param_3->n1).n2.wReserved1;
      local_88.n2.wReserved2 = (param_3->n1).n2.wReserved2;
      local_88.n2.wReserved3 = (param_3->n1).n2.wReserved3;
      local_88.decVal.u2 = (_union_1719)(param_3->n1).n2.n3.punkVal;
      local_88._16_8_ = (param_3->n1).n2.n3.brecVal.pRecInfo;
      (param_3->n1).n2.vt = 0;
    }
  }
  pIVar1 = local_58;
  if (local_58 == (IStream *)0x0) goto LAB_18000a5f7;
  uStack_e0 = 0x18000a464;
  HVar2 = (*local_58->lpVtbl->Write)(local_58,&local_88,2,(ULONG *)0x0);
  if (HVar2 < 0) goto LAB_18000a5f7;
  switch(local_88.n2.vt) {
  case 2:
  case 0xb:
  case 0x12:
    cb_00 = 2;
    break;
  case 3:
  case 4:
  case 10:
  case 0x13:
  case 0x16:
  case 0x17:
    cb_00 = 4;
    break;
  case 5:
  case 6:
  case 7:
  case 0x14:
  case 0x15:
    cb_00 = 8;
    break;
  default:
    pv_00 = (_struct_1720)0x0;
    local_50._0_8_ = 0;
    local_50.decVal.u2 = (_union_1719)0;
    local_50._16_8_ = 0;
    uStack_e0 = 0x18000a55f;
    VariantInit((VARIANTARG *)&local_50.n2);
    if (local_88.n2.vt == 8) {
      bstr = local_88._8_8_;
LAB_18000a58b:
      if (bstr == 0) {
        iVar4 = 4;
      }
      else {
        uStack_e0 = 0x18000a59c;
        SysFreeString((BSTR)0x0);
        uStack_e0 = 0x18000a5a8;
        UVar3 = SysStringByteLen((BSTR)bstr);
        iVar4 = UVar3 + 6;
        pv_00 = bstr;
      }
      local_90[0] = iVar4 - 4;
      uStack_e0 = 0x18000a5c8;
      HVar2 = (*pIVar1->lpVtbl->Write)(pIVar1,local_90,4,(ULONG *)&local_98);
      if ((-1 < HVar2) && (local_90[0] != 0)) {
        uStack_e0 = 0x18000a5e5;
        (*pIVar1->lpVtbl->Write)(pIVar1,(void *)pv_00,local_90[0],(ULONG *)&local_98);
      }
    }
    else {
      uStack_e0 = 0x18000a57d;
      HVar2 = VariantChangeType((VARIANTARG *)&local_50.n2,(VARIANTARG *)&local_88,1,8);
      if (-1 < HVar2) {
        bstr = local_50._8_8_;
        goto LAB_18000a58b;
      }
    }
    uStack_e0 = 0x18000a5ef;
    VariantClear((VARIANTARG *)&local_50.n2);
    uStack_e0 = 0x18000a5f7;
    SysFreeString((BSTR)0x0);
    goto LAB_18000a5f7;
  case 9:
  case 0xd:
    local_98 = (void *)0x0;
    if (local_88.decVal.u2 == 0) {
LAB_18000a505:
      uStack_e0 = 0x18000a515;
      WriteClassStm(pIVar1,(IID *)&DAT_180043ef8);
    }
    else {
      uStack_e0 = 0x18000a4b9;
      HVar2 = (*(*(IPersistStreamVtbl **)local_88.decVal.u2)->QueryInterface)
                        ((IPersistStream *)local_88.decVal.u2,(IID *)&DAT_180040260,&local_98);
      if (HVar2 < 0) {
        uStack_e0 = 0x18000a4d1;
        HVar2 = (*(*(IPersistStreamVtbl **)local_88.decVal.u2)->QueryInterface)
                          ((IPersistStream *)local_88.decVal.u2,(IID *)&DAT_180040270,&local_98);
        if (HVar2 < 0) goto LAB_18000a5f7;
      }
      if (local_98 == (void *)0x0) goto LAB_18000a505;
      uStack_e0 = 0x18000a4ec;
      OleSaveToStream(local_98,pIVar1);
    }
    if (local_98 != (void *)0x0) {
      uStack_e0 = 0x18000a500;
      (*(*(IPersistStreamVtbl **)local_98)->Release)(local_98);
    }
    goto LAB_18000a5f7;
  case 0x10:
  case 0x11:
    break;
  }
  uStack_e0 = 0x18000a540;
  (*pIVar1->lpVtbl->Write)(pIVar1,(void *)((longlong)&local_88.n2 + 8),cb_00,(ULONG *)0x0);
LAB_18000a5f7:
  if (param_3 != (VARIANTARG *)0x0) {
    uStack_e0 = 0x18000a605;
    HVar2 = VariantClear(param_3);
    if (-1 < HVar2) {
      (param_3->n1).n2.vt = local_88._0_2_;
      (param_3->n1).n2.wReserved1 = local_88.n2.wReserved1;
      (param_3->n1).n2.wReserved2 = local_88.n2.wReserved2;
      (param_3->n1).n2.wReserved3 = local_88.n2.wReserved3;
      (param_3->n1).n2.n3.llVal = (LONGLONG)local_88.decVal.u2;
      (param_3->n1).n2.n3.brecVal.pRecInfo = (IRecordInfo *)local_88._16_8_;
      local_88._0_8_ = local_88._0_8_ & 0xffffffffffff0000;
    }
  }
  local_98 = (void *)0x0;
  uStack_e0 = 0x18000a63a;
  (*local_58->lpVtbl->Seek)(local_58,(LARGE_INTEGER)0x0,0,(ULARGE_INTEGER *)0x0);
  uStack_e0 = 0x18000a645;
  VariantClear((VARIANTARG *)&local_88);
  uStack_e0 = 0x18000a650;
  VariantClear((VARIANTARG *)&local_70);
LAB_18000a650:
  puVar10 = auStack_d8;
  if (param_1 == 9) {
    uStack_e0 = 0x18000a65d;
    GRseteorsl(0);
    puVar9 = auStack_d8;
    goto LAB_18000a7cf;
  }
  if (param_1 == 0xc) {
    pcVar8 = "########";
    puVar9 = auStack_d8;
    if (((param_3->n1).n2.vt == 8) &&
       (lpWideCharStr = (LPCWSTR)(param_3->n1).decVal.u2.Lo64, puVar9 = auStack_d8,
       lpWideCharStr != (LPCWSTR)0x0)) {
      lVar5 = -1;
      do {
        lVar6 = lVar5;
        lVar5 = lVar6 + 1;
      } while (lpWideCharStr[lVar5] != L'\0');
      iVar4 = (int)lVar6 + 2;
      if (iVar4 < 0x40000000) {
        lVar5 = (longlong)(int)lVar5 * 2;
        uVar7 = lVar5 + 0x11;
        if (uVar7 <= lVar5 + 2U) {
          uVar7 = 0xffffffffffffff0;
        }
        uStack_e0 = 0x18000a6e1;
        lVar5 = -(uVar7 & 0xfffffffffffffff0);
        puVar10 = auStack_d8 + lVar5;
        puVar9 = (undefined1 *)((longlong)local_a8 + lVar5 + 0x10);
        if (puVar9 != (undefined1 *)0x0) {
          *puVar9 = 0;
          *(undefined8 *)((longlong)local_a8 + lVar5 + 8) = 0;
          *(undefined8 *)((longlong)local_a8 + lVar5) = 0;
          *(int *)((longlong)aiStack_b0 + lVar5) = iVar4 * 2;
          *(undefined1 **)(auStack_d8 + lVar5 + 0x20) = puVar9;
          *(undefined8 *)(auStack_d8 + lVar5 + -8) = 0x18000a715;
          iVar4 = WideCharToMultiByte(0,0,lpWideCharStr,-1,*(LPSTR *)(auStack_d8 + lVar5 + 0x20),
                                      *(int *)((longlong)aiStack_b0 + lVar5),
                                      *(LPCSTR *)((longlong)local_a8 + lVar5),
                                      *(LPBOOL *)((longlong)local_a8 + lVar5 + 8));
          if (iVar4 == 0) {
            puVar9 = (undefined1 *)0x0;
          }
          *(undefined8 *)(auStack_d8 + lVar5 + -8) = 0x18000a723;
          FLeofix(puVar9);
          puVar9 = auStack_d8 + lVar5;
          goto LAB_18000a7cf;
        }
      }
      pcVar8 = (char *)0x0;
      puVar9 = puVar10;
    }
    *(undefined8 *)(puVar9 + -8) = 0x18000a733;
    FLeofix(pcVar8);
    goto LAB_18000a7cf;
  }
  if (param_1 == 3) {
    uStack_e0 = 0x18000a743;
    iVar4 = Ordinal_77();
    puVar9 = auStack_d8;
    if (iVar4 == 0) goto LAB_18000a7cf;
    uStack_e0 = 0x18000a752;
    Ordinal_79(0);
    bVar11 = false;
  }
  else {
    if (param_1 == 6) {
LAB_18000a76b:
      uStack_e0 = 0x18000a776;
      pcVar8 = (char *)GetSorResStringEx(0x1d6);
      uStack_e0 = 0x18000a77e;
      FUN_180008f30(pcVar8);
      uStack_e0 = 0x18000a783;
      FUN_1800314e0();
    }
    else if (param_1 == 2) {
      uStack_e0 = 0x18000a767;
      iVar4 = Ordinal_77();
      puVar9 = auStack_d8;
      if (iVar4 == 0) goto LAB_18000a7cf;
      goto LAB_18000a76b;
    }
    puVar9 = auStack_d8;
    if (param_1 != 7) goto LAB_18000a7cf;
    uStack_e0 = 0x18000a78e;
    iVar4 = Ordinal_77();
    puVar9 = auStack_d8;
    if (iVar4 == 0) goto LAB_18000a7cf;
    uStack_e0 = 0x18000a799;
    Ordinal_79(0);
    if ((param_3->n1).n2.vt == 3) {
      iVar4 = (param_3->n1).n2.n3.lVal;
    }
    else {
      iVar4 = -1;
    }
    bVar11 = iVar4 == 0;
  }
  uStack_e0 = 0x18000a7ba;
  Ordinal_99(bVar11);
  uStack_e0 = 0x18000a7c6;
  hEvent = (HANDLE)GetGlobalPointer("DCOM_MSHL_EVENT");
  uStack_e0 = 0x18000a7cf;
  SetEvent(hEvent);
  puVar9 = auStack_d8;
LAB_18000a7cf:
  pIVar1 = local_58;
  *(undefined8 *)(puVar9 + -8) = 0x18000a7e0;
  SimSendMainWndMessage(0x54b,pIVar1,(longlong)param_1);
  *(undefined8 *)(puVar9 + -8) = 0x18000a7ee;
  return 0;
}

/* RVA 0xa880 */
void thunk_FUN_180001300(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b368. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete(param_1);
  return;
}

/* RVA 0xa890 */
/* Library Function - Single Match
    public: class CArchive & __ptr64 __cdecl CArchive::operator<<<char,class StrTraitMFC<char,class
   ATL::ChTraitsCRT<char> > >(class ATL::CStringT<char,class StrTraitMFC<char,class
   ATL::ChTraitsCRT<char> > > const & __ptr64) __ptr64
   
   Library: Visual Studio 2015 Release */

CArchive * __thiscall
CArchive::operator<<<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>_>_>
          (CArchive *this,CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>_>_> *param_1)

{
  AfxWriteStringLength(this,(longlong)*(int *)(*(longlong *)param_1 + -0x10),0);
  CArchive::Write(this,*(void **)param_1,*(uint *)((longlong)*(void **)param_1 + -0x10));
  return this;
}

/* RVA 0xa8d0 */
longlong FUN_18000a8d0(void *param_1,longlong param_2,void *param_3)

{
  memmove(param_3,param_1,param_2 - (longlong)param_1);
  return (param_2 - (longlong)param_1) + (longlong)param_3;
}

/* RVA 0xa900 */
undefined8 * FUN_18000a900(longlong *param_1,void *param_2,undefined8 *param_3)

{
  ulonglong uVar1;
  undefined8 *puVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  void *pvVar7;
  void *pvVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  __uint64 _Var11;
  
  lVar3 = *param_1;
  lVar4 = param_1[1] - lVar3 >> 3;
  if (lVar4 == 0x1fffffffffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_180005f30();
  }
  uVar1 = lVar4 + 1;
  uVar6 = param_1[2] - lVar3 >> 3;
  if (0x1fffffffffffffff - (uVar6 >> 1) < uVar6) {
    _Var11 = 0xfffffffffffffff8;
    puVar5 = (undefined8 *)FUN_1800044b0(0xfffffffffffffff8);
  }
  else {
    uVar6 = (uVar6 >> 1) + uVar6;
    uVar9 = uVar1;
    if (uVar1 <= uVar6) {
      uVar9 = uVar6;
    }
    if (0x1fffffffffffffff < uVar9) {
                    /* WARNING: Subroutine does not return */
      FUN_180005ed0();
    }
    _Var11 = uVar9 * 8;
    if (_Var11 < 0x1000) {
      if (_Var11 == 0) {
        puVar5 = (undefined8 *)0x0;
      }
      else {
        puVar5 = operator_new(_Var11);
      }
    }
    else {
      puVar5 = (undefined8 *)FUN_1800044b0(_Var11);
    }
  }
  puVar2 = puVar5 + ((longlong)param_2 - lVar3 >> 3);
  *puVar2 = *param_3;
  pvVar8 = (void *)param_1[1];
  pvVar7 = (void *)*param_1;
  puVar10 = puVar5;
  if (param_2 != pvVar8) {
    FUN_18000a8d0((void *)*param_1,(longlong)param_2,puVar5);
    puVar10 = puVar2 + 1;
    pvVar8 = (void *)param_1[1];
    pvVar7 = param_2;
  }
  FUN_18000a8d0(pvVar7,(longlong)pvVar8,puVar10);
  pvVar8 = (void *)*param_1;
  if (pvVar8 != (void *)0x0) {
    pvVar7 = pvVar8;
    if ((0xfff < (param_1[2] - (longlong)pvVar8 & 0xfffffffffffffff8U)) &&
       (pvVar7 = *(void **)((longlong)pvVar8 + -8),
       0x1f < (ulonglong)((longlong)pvVar8 + (-8 - (longlong)pvVar7)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180001300(pvVar7);
  }
  *param_1 = (longlong)puVar5;
  param_1[1] = (longlong)(puVar5 + uVar1);
  param_1[2] = _Var11 + (longlong)puVar5;
  return puVar2;
}

/* RVA 0xaa90 */
undefined8 *
FUN_18000aa90(undefined8 *param_1,ulonglong param_2,undefined8 param_3,void *param_4,size_t param_5)

{
  __uint64 _Var1;
  ulonglong uVar2;
  size_t _Size;
  ulonglong uVar3;
  void *_Src;
  void *_Dst;
  ulonglong uVar4;
  ulonglong uVar5;
  void *pvVar6;
  
  _Size = param_1[2];
  uVar5 = 0x7fffffffffffffff;
  if (0x7fffffffffffffff - _Size < param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_180005f10();
  }
  uVar4 = _Size + param_2 | 0xf;
  uVar3 = param_1[3];
  if (uVar4 < 0x8000000000000000) {
    if (0x7fffffffffffffff - (uVar3 >> 1) < uVar3) {
      _Dst = (void *)FUN_1800044b0(0x8000000000000000);
    }
    else {
      uVar2 = (uVar3 >> 1) + uVar3;
      uVar5 = uVar4;
      if (uVar4 < uVar2) {
        uVar5 = uVar2;
      }
      _Var1 = uVar5 + 1;
      if (_Var1 < 0x1000) {
        if (_Var1 == 0) {
          _Dst = (void *)0x0;
        }
        else {
          _Dst = operator_new(_Var1);
        }
      }
      else {
        _Dst = (void *)FUN_1800044b0(_Var1);
      }
    }
  }
  else {
    _Dst = (void *)FUN_1800044b0(0x8000000000000000);
  }
  param_1[2] = _Size + param_2;
  pvVar6 = (void *)((longlong)_Dst + _Size);
  param_1[3] = uVar5;
  if (uVar3 < 0x10) {
    memcpy(_Dst,param_1,_Size);
    memcpy(pvVar6,param_4,param_5);
    *(undefined1 *)((longlong)pvVar6 + param_5) = 0;
  }
  else {
    _Src = (void *)*param_1;
    memcpy(_Dst,_Src,_Size);
    memcpy(pvVar6,param_4,param_5);
    *(undefined1 *)((longlong)pvVar6 + param_5) = 0;
    pvVar6 = _Src;
    if ((0xfff < uVar3 + 1) &&
       (pvVar6 = *(void **)((longlong)_Src + -8),
       0x1f < (ulonglong)((longlong)_Src + (-8 - (longlong)pvVar6)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180001300(pvVar6);
  }
  *param_1 = _Dst;
  return param_1;
}

/* RVA 0xac10 */
longlong * FUN_18000ac10(longlong *param_1,void *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  ulonglong _Size;
  
  _Size = 0xffffffffffffffff;
  do {
    _Size = _Size + 1;
  } while (*(char *)((longlong)param_2 + _Size) != '\0');
  lVar1 = param_1[2];
  if ((ulonglong)(param_1[3] - lVar1) < _Size) {
    plVar2 = FUN_18000aa90(param_1,_Size,0,param_2,_Size);
    return plVar2;
  }
  param_1[2] = lVar1 + _Size;
  plVar2 = param_1;
  if (0xf < (ulonglong)param_1[3]) {
    plVar2 = (longlong *)*param_1;
  }
  memmove((void *)((longlong)plVar2 + lVar1),param_2,_Size);
  *(undefined1 *)((longlong)plVar2 + lVar1 + _Size) = 0;
  return param_1;
}

/* RVA 0xaca0 */
undefined1
FUN_18000aca0(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,
             CSimSeqObj *param_2,undefined8 param_3,int param_4)

{
  char *pcVar1;
  undefined1 uVar2;
  int iVar3;
  CSimSeqTree *pCVar4;
  IAtlStringMgr *pIVar5;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar6;
  int iVar7;
  longlong lVar8;
  longlong lVar9;
  CSimSeqObj *pCVar10;
  longlong lVar11;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_50 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_48 [16];
  
  lVar8 = 0;
  pCVar4 = CSimSeqObj::GetChildren(param_2);
  iVar7 = (int)(*(longlong *)(pCVar4 + 0x10) - *(longlong *)(pCVar4 + 8) >> 5);
  if (0 < iVar7) {
    lVar9 = 0;
    lVar11 = 0;
    do {
      pCVar10 = (CSimSeqObj *)(*(longlong *)(pCVar4 + 8) + lVar11);
      if (((pCVar10 != (CSimSeqObj *)0x0) && (*(int *)(pCVar10 + 0x10) == -1)) &&
         (iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             (pCVar10 + 8),"ALL"), iVar3 != 0)) {
        pIVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                           (param_1);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_50,pIVar5);
        lVar8 = -1;
        do {
          lVar9 = lVar8 + 1;
          pcVar1 = &DAT_18003fa81 + lVar8;
          lVar8 = lVar9;
        } while (*pcVar1 != '\0');
        ATL::CSimpleStringT<char,1>::Concatenate
                  ((CSimpleStringT<char,1> *)local_50,*(char **)param_1,
                   *(int *)(*(char **)param_1 + -0x10),".",(int)lVar9);
        pCVar6 = FUN_180001aa0(local_48,local_50,(undefined8 *)(pCVar10 + 8));
        uVar2 = FUN_18000aca0(pCVar6,pCVar10,param_3,param_4);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_50);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1);
        return uVar2;
      }
      lVar9 = lVar9 + 1;
      lVar11 = lVar11 + 0x20;
    } while (lVar9 < iVar7);
    lVar9 = 0;
    do {
      if ((lVar9 + *(longlong *)(pCVar4 + 8) != 0) &&
         (*(int *)(lVar9 + *(longlong *)(pCVar4 + 8) + 0x10) == param_4)) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1);
        return 1;
      }
      lVar8 = lVar8 + 1;
      lVar9 = lVar9 + 0x20;
    } while (lVar8 < iVar7);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1);
  return 0;
}

/* RVA 0xae30 */
ulonglong FUN_18000ae30(longlong param_1,undefined8 param_2,int param_3)

{
  char cVar1;
  ulonglong in_RAX;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar2;
  undefined7 extraout_var;
  longlong lVar3;
  longlong lVar4;
  CSimSeqObj *pCVar5;
  int iVar6;
  longlong lVar7;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res8 [8];
  undefined8 local_res10;
  
  lVar3 = 0;
  iVar6 = (int)(*(longlong *)(param_1 + 0x10) - *(longlong *)(param_1 + 8) >> 5);
  if (0 < iVar6) {
    lVar4 = 0;
    lVar7 = 0;
    local_res10 = param_2;
    do {
      pCVar5 = (CSimSeqObj *)(*(longlong *)(param_1 + 8) + lVar7);
      if ((pCVar5 != (CSimSeqObj *)0x0) && (*(int *)(pCVar5 + 0x10) == -1)) {
        pCVar2 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                 ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                 CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                           (local_res8,
                            (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                             *)(pCVar5 + 8));
        cVar1 = FUN_18000aca0(pCVar2,pCVar5,local_res10,param_3);
        in_RAX = CONCAT71(extraout_var,cVar1);
        if (cVar1 != '\0') goto LAB_18000aeee;
      }
      lVar4 = lVar4 + 1;
      lVar7 = lVar7 + 0x20;
    } while (lVar4 < iVar6);
    if (0 < iVar6) {
      in_RAX = *(ulonglong *)(param_1 + 8);
      do {
        if ((in_RAX != 0) && (*(int *)(in_RAX + 0x10) == param_3)) {
LAB_18000aeee:
          return CONCAT71((int7)(in_RAX >> 8),1);
        }
        lVar3 = lVar3 + 1;
        in_RAX = in_RAX + 0x20;
      } while (lVar3 < iVar6);
    }
  }
  return in_RAX & 0xffffffffffffff00;
}

/* RVA 0xaf00 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18000af00(CSimpleStringT<char,1> *param_1,CSimSeqObj *param_2,longlong *param_3,
                  char *param_4,uint param_5)

{
  CSimpleStringT<char,1> *this;
  int iVar1;
  char *pcVar2;
  IAtlStringMgr *pIVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar4;
  longlong lVar5;
  longlong lVar6;
  longlong *plVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  char *pcVar10;
  longlong lVar11;
  CSimSeqObj *pCVar12;
  undefined1 auStackY_e8 [32];
  char *local_b8;
  void *local_b0;
  undefined4 local_a8;
  void *local_a0;
  longlong local_98;
  longlong local_90;
  CSimpleStringT<char,1> *local_88;
  CSimSeqTree *local_80;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_78 [8];
  char *local_70;
  CSimpleStringT<char,1> *local_68;
  char local_60 [16];
  ulonglong local_50;
  
  local_50 = DAT_1800516d8 ^ (ulonglong)auStackY_e8;
  local_a8 = 0;
  pcVar10 = param_4;
  local_88 = param_1;
  local_70 = param_4;
  local_68 = param_1;
  if (*(int *)(param_2 + 0x14) == 0) {
    pcVar2 = ATL::CSimpleStringT<char,1>::GetBuffer(param_1,0);
    (*(code *)PTR_FUN_180044148)(pcVar2,1);
  }
  iVar1 = CSimSeqObj::HasChildren(param_2);
  if (iVar1 != 0) {
    lVar11 = param_3[2];
    if ((ulonglong)(param_3[3] - lVar11) < 7) {
      pcVar10 = "<Items>";
      FUN_18000aa90(param_3,7,0,"<Items>",7);
    }
    else {
      param_3[2] = lVar11 + 7;
      plVar7 = param_3;
      if (0xf < (ulonglong)param_3[3]) {
        plVar7 = (longlong *)*param_3;
      }
      memmove((void *)((longlong)plVar7 + lVar11),"<Items>",7);
      *(undefined1 *)((longlong)plVar7 + lVar11 + 7) = 0;
    }
    local_80 = CSimSeqObj::GetChildren(param_2);
    iVar1 = (int)(*(longlong *)(local_80 + 0x10) - *(longlong *)(local_80 + 8) >> 5);
    local_98 = (longlong)iVar1;
    if (0 < iVar1) {
      lVar11 = 0;
      local_90 = local_98;
      do {
        pCVar12 = (CSimSeqObj *)(*(longlong *)(local_80 + 8) + lVar11);
        if ((pCVar12 != (CSimSeqObj *)0x0) && (*(int *)(pCVar12 + 0x10) == -1)) {
          lVar6 = param_3[2];
          if ((ulonglong)(param_3[3] - lVar6) < 0xc) {
            pcVar10 = "<Item><Name>";
            FUN_18000aa90(param_3,0xc,0,"<Item><Name>",0xc);
          }
          else {
            param_3[2] = lVar6 + 0xc;
            plVar7 = param_3;
            if (0xf < (ulonglong)param_3[3]) {
              plVar7 = (longlong *)*param_3;
            }
            memmove((void *)((longlong)plVar7 + lVar6),"<Item><Name>",0xc);
            *(undefined1 *)((longlong)plVar7 + lVar6 + 0xc) = 0;
          }
          FUN_18000ac10(param_3,*(void **)(pCVar12 + 8));
          lVar6 = param_3[2];
          if ((ulonglong)(param_3[3] - lVar6) < 0xe) {
            pcVar10 = "</Name><Image>";
            FUN_18000aa90(param_3,0xe,0,"</Name><Image>",0xe);
          }
          else {
            param_3[2] = lVar6 + 0xe;
            plVar7 = param_3;
            if (0xf < (ulonglong)param_3[3]) {
              plVar7 = (longlong *)*param_3;
            }
            memmove((void *)((longlong)plVar7 + lVar6),"</Name><Image>",0xe);
            *(undefined1 *)((longlong)plVar7 + lVar6 + 0xe) = 0;
          }
          lVar6 = param_3[2];
          if ((ulonglong)(param_3[3] - lVar6) < 10) {
            pcVar10 = "Folder.ico";
            FUN_18000aa90(param_3,10,0,"Folder.ico",10);
          }
          else {
            param_3[2] = lVar6 + 10;
            plVar7 = param_3;
            if (0xf < (ulonglong)param_3[3]) {
              plVar7 = (longlong *)*param_3;
            }
            memmove((void *)((longlong)plVar7 + lVar6),"Folder.ico",10);
            *(undefined1 *)((longlong)plVar7 + lVar6 + 10) = 0;
          }
          lVar6 = param_3[2];
          if ((ulonglong)(param_3[3] - lVar6) < 0xe) {
            pcVar10 = "</Image><Type>";
            FUN_18000aa90(param_3,0xe,0,"</Image><Type>",0xe);
          }
          else {
            param_3[2] = lVar6 + 0xe;
            plVar7 = param_3;
            if (0xf < (ulonglong)param_3[3]) {
              plVar7 = (longlong *)*param_3;
            }
            memmove((void *)((longlong)plVar7 + lVar6),"</Image><Type>",0xe);
            *(undefined1 *)((longlong)plVar7 + lVar6 + 0xe) = 0;
          }
          local_60[0] = '\0';
          local_60[1] = '\0';
          local_60[2] = '\0';
          local_60[3] = '\0';
          local_60[4] = '\0';
          local_60[5] = '\0';
          local_60[6] = '\0';
          local_60[7] = '\0';
          local_60[8] = '\0';
          local_60[9] = '\0';
          local_60[10] = '\0';
          local_60[0xb] = '\0';
          FUN_180008f80(local_60,&DAT_180040814,(ulonglong)*(uint *)(pCVar12 + 0x10),pcVar10);
          uVar9 = 0xffffffffffffffff;
          do {
            uVar8 = uVar9 + 1;
            lVar6 = uVar9 + 1;
            uVar9 = uVar8;
          } while (local_60[lVar6] != '\0');
          lVar6 = param_3[2];
          if ((ulonglong)(param_3[3] - lVar6) < uVar8) {
            FUN_18000aa90(param_3,uVar8,0,local_60,uVar8);
          }
          else {
            param_3[2] = lVar6 + uVar8;
            plVar7 = param_3;
            if (0xf < (ulonglong)param_3[3]) {
              plVar7 = (longlong *)*param_3;
            }
            memmove((void *)(lVar6 + (longlong)plVar7),local_60,uVar8);
            *(undefined1 *)(uVar8 + lVar6 + (longlong)plVar7) = 0;
          }
          lVar6 = param_3[2];
          if ((ulonglong)(param_3[3] - lVar6) < 0xc) {
            FUN_18000aa90(param_3,0xc,0,"</Type><Tag>",0xc);
          }
          else {
            param_3[2] = lVar6 + 0xc;
            plVar7 = param_3;
            if (0xf < (ulonglong)param_3[3]) {
              plVar7 = (longlong *)*param_3;
            }
            memmove((void *)((longlong)plVar7 + lVar6),"</Type><Tag>",0xc);
            *(undefined1 *)((longlong)plVar7 + lVar6 + 0xc) = 0;
          }
          this = local_88;
          pIVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                             ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                              local_88);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,
                     pIVar3);
          local_a8 = 0x40;
          ATL::CSimpleStringT<char,1>::Concatenate
                    ((CSimpleStringT<char,1> *)&local_b8,*(char **)this,
                     *(int *)(*(char **)this + -0x10),".",1);
          pIVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                             ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                              &local_b8);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_a0,
                     pIVar3);
          local_a8 = 0x60;
          ATL::CSimpleStringT<char,1>::Concatenate
                    ((CSimpleStringT<char,1> *)&local_a0,local_b8,*(int *)(local_b8 + -0x10),
                     *(char **)(pCVar12 + 8),*(int *)(*(char **)(pCVar12 + 8) + -0x10));
          FUN_18000ac10(param_3,local_a0);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_a0);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8);
          lVar6 = param_3[2];
          if ((ulonglong)(param_3[3] - lVar6) < 0x24) {
            FUN_18000aa90(param_3,0x24,0,"</Tag><IsExpanded>false</IsExpanded>",0x24);
          }
          else {
            param_3[2] = lVar6 + 0x24;
            plVar7 = param_3;
            if (0xf < (ulonglong)param_3[3]) {
              plVar7 = (longlong *)*param_3;
            }
            memmove((void *)((longlong)plVar7 + lVar6),"</Tag><IsExpanded>false</IsExpanded>",0x24);
            *(undefined1 *)((longlong)plVar7 + lVar6 + 0x24) = 0;
          }
          pIVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                             ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)this)
          ;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b0,
                     pIVar3);
          local_a8 = 0x10;
          ATL::CSimpleStringT<char,1>::Concatenate
                    ((CSimpleStringT<char,1> *)&local_b0,*(char **)this,
                     *(int *)(*(char **)this + -0x10),".",1);
          pCVar4 = FUN_180001aa0(local_78,(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                           *)&local_b0,(undefined8 *)(pCVar12 + 8));
          param_4 = local_70;
          pcVar10 = local_70;
          FUN_18000af00((CSimpleStringT<char,1> *)pCVar4,pCVar12,param_3,local_70,param_5);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b0);
          lVar6 = param_3[2];
          if ((ulonglong)(param_3[3] - lVar6) < 7) {
            pcVar10 = "</Item>";
            FUN_18000aa90(param_3,7,0,"</Item>",7);
          }
          else {
            param_3[2] = lVar6 + 7;
            plVar7 = param_3;
            if (0xf < (ulonglong)param_3[3]) {
              plVar7 = (longlong *)*param_3;
            }
            memmove((void *)((longlong)plVar7 + lVar6),"</Item>",7);
            *(undefined1 *)((longlong)plVar7 + lVar6 + 7) = 0;
          }
        }
        lVar11 = lVar11 + 0x20;
        local_90 = local_90 + -1;
      } while (local_90 != 0);
      local_90 = 0;
      param_1 = local_88;
    }
    lVar11 = local_98;
    if (param_4 != (char *)0x0) {
      lVar6 = param_3[2];
      if ((ulonglong)(param_3[3] - lVar6) < 0xc) {
        pcVar10 = "<Item><Name>";
        FUN_18000aa90(param_3,0xc,0,"<Item><Name>",0xc);
      }
      else {
        param_3[2] = lVar6 + 0xc;
        plVar7 = param_3;
        if (0xf < (ulonglong)param_3[3]) {
          plVar7 = (longlong *)*param_3;
        }
        memmove((void *)((longlong)plVar7 + lVar6),"<Item><Name>",0xc);
        *(undefined1 *)((longlong)plVar7 + lVar6 + 0xc) = 0;
      }
      FUN_18000ac10(param_3,param_4);
      lVar6 = param_3[2];
      if ((ulonglong)(param_3[3] - lVar6) < 0xe) {
        pcVar10 = "</Name><Image>";
        FUN_18000aa90(param_3,0xe,0,"</Name><Image>",0xe);
      }
      else {
        param_3[2] = lVar6 + 0xe;
        plVar7 = param_3;
        if (0xf < (ulonglong)param_3[3]) {
          plVar7 = (longlong *)*param_3;
        }
        memmove((void *)((longlong)plVar7 + lVar6),"</Name><Image>",0xe);
        *(undefined1 *)((longlong)plVar7 + lVar6 + 0xe) = 0;
      }
      lVar6 = param_3[2];
      if ((ulonglong)(param_3[3] - lVar6) < 0xc) {
        pcVar10 = "FormNode.png";
        FUN_18000aa90(param_3,0xc,0,"FormNode.png",0xc);
      }
      else {
        param_3[2] = lVar6 + 0xc;
        plVar7 = param_3;
        if (0xf < (ulonglong)param_3[3]) {
          plVar7 = (longlong *)*param_3;
        }
        memmove((void *)((longlong)plVar7 + lVar6),"FormNode.png",0xc);
        *(undefined1 *)((longlong)plVar7 + lVar6 + 0xc) = 0;
      }
      lVar6 = param_3[2];
      if ((ulonglong)(param_3[3] - lVar6) < 0xe) {
        pcVar10 = "</Image><Type>";
        FUN_18000aa90(param_3,0xe,0,"</Image><Type>",0xe);
      }
      else {
        param_3[2] = lVar6 + 0xe;
        plVar7 = param_3;
        if (0xf < (ulonglong)param_3[3]) {
          plVar7 = (longlong *)*param_3;
        }
        memmove((void *)((longlong)plVar7 + lVar6),"</Image><Type>",0xe);
        *(undefined1 *)((longlong)plVar7 + lVar6 + 0xe) = 0;
      }
      local_60[0] = '\0';
      local_60[1] = '\0';
      local_60[2] = '\0';
      local_60[3] = '\0';
      local_60[4] = '\0';
      local_60[5] = '\0';
      local_60[6] = '\0';
      local_60[7] = '\0';
      local_60[8] = '\0';
      local_60[9] = '\0';
      local_60[10] = '\0';
      local_60[0xb] = '\0';
      FUN_180008f80(local_60,&DAT_180040814,(ulonglong)param_5,pcVar10);
      uVar9 = 0xffffffffffffffff;
      do {
        uVar8 = uVar9 + 1;
        lVar6 = uVar9 + 1;
        uVar9 = uVar8;
      } while (local_60[lVar6] != '\0');
      lVar6 = param_3[2];
      if ((ulonglong)(param_3[3] - lVar6) < uVar8) {
        FUN_18000aa90(param_3,uVar8,0,local_60,uVar8);
      }
      else {
        param_3[2] = lVar6 + uVar8;
        plVar7 = param_3;
        if (0xf < (ulonglong)param_3[3]) {
          plVar7 = (longlong *)*param_3;
        }
        memmove((void *)((longlong)plVar7 + lVar6),local_60,uVar8);
        *(undefined1 *)(uVar8 + (longlong)plVar7 + lVar6) = 0;
      }
      lVar6 = param_3[2];
      if ((ulonglong)(param_3[3] - lVar6) < 0xc) {
        FUN_18000aa90(param_3,0xc,0,"</Type><Tag>",0xc);
      }
      else {
        param_3[2] = lVar6 + 0xc;
        plVar7 = param_3;
        if (0xf < (ulonglong)param_3[3]) {
          plVar7 = (longlong *)*param_3;
        }
        memmove((void *)((longlong)plVar7 + lVar6),"</Type><Tag>",0xc);
        *(undefined1 *)((longlong)plVar7 + lVar6 + 0xc) = 0;
      }
      pIVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_1);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,pIVar3);
      local_a8 = 8;
      lVar6 = -1;
      do {
        lVar5 = lVar6 + 1;
        pcVar10 = &DAT_18003fa81 + lVar6;
        lVar6 = lVar5;
      } while (*pcVar10 != '\0');
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)&local_b8,*(char **)param_1,
                 *(int *)(*(char **)param_1 + -0x10),".",(int)lVar5);
      pIVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8
                         );
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b0,pIVar3);
      local_a8 = 0xc;
      lVar6 = -1;
      do {
        lVar6 = lVar6 + 1;
      } while (param_4[lVar6] != '\0');
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)&local_b0,local_b8,*(int *)(local_b8 + -0x10),param_4,
                 (int)lVar6);
      FUN_18000ac10(param_3,local_b0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8);
      lVar6 = param_3[2];
      if ((ulonglong)(param_3[3] - lVar6) < 0xd) {
        FUN_18000aa90(param_3,0xd,0,"</Tag></Item>",0xd);
      }
      else {
        param_3[2] = lVar6 + 0xd;
        plVar7 = param_3;
        if (0xf < (ulonglong)param_3[3]) {
          plVar7 = (longlong *)*param_3;
        }
        memmove((void *)((longlong)plVar7 + lVar6),"</Tag></Item>",0xd);
        *(undefined1 *)((longlong)plVar7 + lVar6 + 0xd) = 0;
      }
    }
    if (0 < lVar11) {
      lVar11 = 0;
      do {
        lVar6 = *(longlong *)(local_80 + 8) + lVar11;
        if ((lVar6 != 0) && (*(uint *)(lVar6 + 0x10) == param_5)) {
          lVar5 = param_3[2];
          if ((ulonglong)(param_3[3] - lVar5) < 0xc) {
            FUN_18000aa90(param_3,0xc,0,"<Item><Name>",0xc);
          }
          else {
            param_3[2] = lVar5 + 0xc;
            plVar7 = param_3;
            if (0xf < (ulonglong)param_3[3]) {
              plVar7 = (longlong *)*param_3;
            }
            memmove((void *)((longlong)plVar7 + lVar5),"<Item><Name>",0xc);
            *(undefined1 *)((longlong)plVar7 + lVar5 + 0xc) = 0;
          }
          pcVar10 = *(char **)(lVar6 + 8);
          uVar9 = 0xffffffffffffffff;
          do {
            uVar9 = uVar9 + 1;
          } while (pcVar10[uVar9] != '\0');
          lVar5 = param_3[2];
          if ((ulonglong)(param_3[3] - lVar5) < uVar9) {
            FUN_18000aa90(param_3,uVar9,0,pcVar10,uVar9);
          }
          else {
            param_3[2] = lVar5 + uVar9;
            plVar7 = param_3;
            if (0xf < (ulonglong)param_3[3]) {
              plVar7 = (longlong *)*param_3;
            }
            memmove((void *)((longlong)plVar7 + lVar5),pcVar10,uVar9);
            *(undefined1 *)((longlong)plVar7 + lVar5 + uVar9) = 0;
          }
          lVar5 = param_3[2];
          if ((ulonglong)(param_3[3] - lVar5) < 0xe) {
            pcVar10 = "</Name><Image>";
            FUN_18000aa90(param_3,0xe,0,"</Name><Image>",0xe);
          }
          else {
            param_3[2] = lVar5 + 0xe;
            plVar7 = param_3;
            if (0xf < (ulonglong)param_3[3]) {
              plVar7 = (longlong *)*param_3;
            }
            memmove((void *)((longlong)plVar7 + lVar5),"</Name><Image>",0xe);
            *(undefined1 *)((longlong)plVar7 + lVar5 + 0xe) = 0;
          }
          lVar5 = param_3[2];
          if ((ulonglong)(param_3[3] - lVar5) < 0xc) {
            pcVar10 = "FormNode.png";
            FUN_18000aa90(param_3,0xc,0,"FormNode.png",0xc);
          }
          else {
            param_3[2] = lVar5 + 0xc;
            plVar7 = param_3;
            if (0xf < (ulonglong)param_3[3]) {
              plVar7 = (longlong *)*param_3;
            }
            memmove((void *)((longlong)plVar7 + lVar5),"FormNode.png",0xc);
            *(undefined1 *)((longlong)plVar7 + lVar5 + 0xc) = 0;
          }
          lVar5 = param_3[2];
          if ((ulonglong)(param_3[3] - lVar5) < 0xe) {
            pcVar10 = "</Image><Type>";
            FUN_18000aa90(param_3,0xe,0,"</Image><Type>",0xe);
          }
          else {
            param_3[2] = lVar5 + 0xe;
            plVar7 = param_3;
            if (0xf < (ulonglong)param_3[3]) {
              plVar7 = (longlong *)*param_3;
            }
            memmove((void *)((longlong)plVar7 + lVar5),"</Image><Type>",0xe);
            *(undefined1 *)((longlong)plVar7 + lVar5 + 0xe) = 0;
          }
          local_60[0] = '\0';
          local_60[1] = '\0';
          local_60[2] = '\0';
          local_60[3] = '\0';
          local_60[4] = '\0';
          local_60[5] = '\0';
          local_60[6] = '\0';
          local_60[7] = '\0';
          local_60[8] = '\0';
          local_60[9] = '\0';
          local_60[10] = '\0';
          local_60[0xb] = '\0';
          FUN_180008f80(local_60,&DAT_180040814,(ulonglong)param_5,pcVar10);
          uVar9 = 0xffffffffffffffff;
          do {
            uVar8 = uVar9 + 1;
            lVar5 = uVar9 + 1;
            uVar9 = uVar8;
          } while (local_60[lVar5] != '\0');
          lVar5 = param_3[2];
          if ((ulonglong)(param_3[3] - lVar5) < uVar8) {
            FUN_18000aa90(param_3,uVar8,0,local_60,uVar8);
          }
          else {
            param_3[2] = lVar5 + uVar8;
            plVar7 = param_3;
            if (0xf < (ulonglong)param_3[3]) {
              plVar7 = (longlong *)*param_3;
            }
            memmove((void *)((longlong)plVar7 + lVar5),local_60,uVar8);
            *(undefined1 *)((longlong)plVar7 + lVar5 + uVar8) = 0;
          }
          lVar5 = param_3[2];
          if ((ulonglong)(param_3[3] - lVar5) < 0xc) {
            FUN_18000aa90(param_3,0xc,0,"</Type><Tag>",0xc);
          }
          else {
            param_3[2] = lVar5 + 0xc;
            plVar7 = param_3;
            if (0xf < (ulonglong)param_3[3]) {
              plVar7 = (longlong *)*param_3;
            }
            memmove((void *)((longlong)plVar7 + lVar5),"</Type><Tag>",0xc);
            *(undefined1 *)((longlong)plVar7 + lVar5 + 0xc) = 0;
          }
          pIVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                             ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                              param_1);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,
                     pIVar3);
          local_a8 = 1;
          ATL::CSimpleStringT<char,1>::Concatenate
                    ((CSimpleStringT<char,1> *)&local_b8,*(char **)param_1,
                     *(int *)(*(char **)param_1 + -0x10),".",1);
          pIVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                             ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                              &local_b8);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b0,
                     pIVar3);
          local_a8 = 3;
          ATL::CSimpleStringT<char,1>::Concatenate
                    ((CSimpleStringT<char,1> *)&local_b0,local_b8,*(int *)(local_b8 + -0x10),
                     *(char **)(lVar6 + 8),*(int *)(*(char **)(lVar6 + 8) + -0x10));
          uVar9 = 0xffffffffffffffff;
          do {
            uVar9 = uVar9 + 1;
          } while (*(char *)((longlong)local_b0 + uVar9) != '\0');
          lVar6 = param_3[2];
          if ((ulonglong)(param_3[3] - lVar6) < uVar9) {
            FUN_18000aa90(param_3,uVar9,0,local_b0,uVar9);
          }
          else {
            param_3[2] = lVar6 + uVar9;
            plVar7 = param_3;
            if (0xf < (ulonglong)param_3[3]) {
              plVar7 = (longlong *)*param_3;
            }
            memmove((void *)((longlong)plVar7 + lVar6),local_b0,uVar9);
            *(undefined1 *)((longlong)plVar7 + lVar6 + uVar9) = 0;
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b0);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8);
          lVar6 = param_3[2];
          if ((ulonglong)(param_3[3] - lVar6) < 0xd) {
            FUN_18000aa90(param_3,0xd,0,"</Tag></Item>",0xd);
          }
          else {
            param_3[2] = lVar6 + 0xd;
            plVar7 = param_3;
            if (0xf < (ulonglong)param_3[3]) {
              plVar7 = (longlong *)*param_3;
            }
            memmove((void *)((longlong)plVar7 + lVar6),"</Tag></Item>",0xd);
            *(undefined1 *)((longlong)plVar7 + lVar6 + 0xd) = 0;
          }
        }
        lVar11 = lVar11 + 0x20;
        local_98 = local_98 + -1;
      } while (local_98 != 0);
    }
    lVar11 = param_3[2];
    if ((ulonglong)(param_3[3] - lVar11) < 8) {
      FUN_18000aa90(param_3,8,0,"</Items>",8);
    }
    else {
      param_3[2] = lVar11 + 8;
      if (0xf < (ulonglong)param_3[3]) {
        param_3 = (longlong *)*param_3;
      }
      *(undefined8 *)((longlong)param_3 + lVar11) = 0x3e736d6574492f3c;
      *(undefined1 *)((longlong)param_3 + lVar11 + 8) = 0;
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_1);
  return;
}

/* RVA 0xbdb0 */
void FUN_18000bdb0(char *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  
  pcVar4 = (char *)GetSorResStringEx(0x1d1);
  MMAfxMessageBox(pcVar4,0x30,-1,0);
  uVar3 = s_Generated_Failed_180040ac8._12_4_;
  uVar2 = s_Generated_Failed_180040ac8._8_4_;
  uVar1 = s_Generated_Failed_180040ac8._4_4_;
  pcVar4 = param_1 + -1;
  do {
    pcVar5 = pcVar4;
    pcVar4 = pcVar5 + 1;
  } while (pcVar5[1] != '\0');
  *(undefined4 *)(pcVar5 + 1) = s_Generated_Failed_180040ac8._0_4_;
  *(undefined4 *)(pcVar5 + 5) = uVar1;
  *(undefined4 *)(pcVar5 + 9) = uVar2;
  *(undefined4 *)(pcVar5 + 0xd) = uVar3;
  *(undefined2 *)(pcVar5 + 0x11) = s_Generated_Failed_180040ac8._16_2_;
  pcVar4 = _strdup(param_1);
  SimSendMainWndMessage(0x536,0,pcVar4);
  return;
}

/* RVA 0xbe20 */
void SimClearControlPanelMessage(void)

{
                    /* 0xbe20  165  SimClearControlPanelMessage */
  if (DAT_180051c20 != (BSTR)0x0) {
    SysFreeString(DAT_180051c20);
  }
  DAT_180051c20 = (BSTR)0x0;
  return;
}

/* RVA 0xbe50 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18000be50(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined7 extraout_var;
  char *pcVar3;
  undefined1 *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  LPCSTR pCVar7;
  code *pcVar8;
  undefined8 uVar9;
  undefined1 auStack_378 [32];
  char *local_358 [2];
  undefined8 local_348;
  undefined2 local_340;
  undefined1 local_33e;
  char local_238 [4];
  char local_234 [252];
  char local_138 [272];
  ulonglong local_28;
  
  local_28 = DAT_1800516d8 ^ (ulonglong)auStack_378;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_358);
  uVar9 = 0;
  pcVar8 = (code *)0x0;
  uVar5 = 0;
  if (param_1 == 1) {
    local_238[0] = (char)DAT_180040c3c;
    local_238[1] = DAT_180040c3c._1_1_;
    local_238[2] = DAT_180040c3c._2_1_;
    local_238[3] = DAT_180040c3c._3_1_;
    uVar5 = 0x7ce;
    local_234._0_2_ = DAT_180040c40;
LAB_18000bf1e:
    uVar5 = GetSorResStringEx(uVar5);
LAB_18000bf2b:
    if (DAT_180052ec4 != 0) {
      iVar2 = GRinqiap();
      if (iVar2 == 0) {
        if (DAT_180052ec4 == 0) goto LAB_18000bfd8;
        iVar2 = GRinqiap();
        if (iVar2 == 0) {
          FUN_180008f80(&local_348,"%s.%s",APtmpfil_exref,local_238);
          iVar2 = FUN_180026510((char *)0x0,(char *)&local_348);
          if (iVar2 != -1) goto LAB_18000c09c;
          uVar6 = GRinqfnm();
          FUN_180008f80(&local_348,"%s.%s",uVar6,local_238);
          _strlwr((char *)&local_348);
          pcVar8 = open_path_exref;
        }
      }
      else {
        FUN_180008f80(&local_348,"%s.%s",APtmpfil_exref,local_238);
      }
      goto LAB_18000c046;
    }
LAB_18000bfd8:
    uVar6 = GRinqfnm();
    FUN_180008f80(&local_348,"%s.%s",uVar6,local_238);
    _strlwr((char *)&local_348);
    iVar2 = FUN_180026510((char *)open_path_exref,(char *)&local_348);
    if (iVar2 == -1) {
      FUN_180008f80(&local_348,"%s.%s",APtmpfil_exref,local_238);
      goto LAB_18000c046;
    }
    pcVar8 = open_path_exref;
  }
  else {
    if (param_1 != 2) {
      if (param_1 == 3) {
        local_238[0] = s_atact_180040c54[0];
        local_238[1] = s_atact_180040c54[1];
        local_238[2] = s_atact_180040c54[2];
        local_238[3] = s_atact_180040c54[3];
        uVar5 = 2000;
        local_234._0_2_ = s_atact_180040c54._4_2_;
        goto LAB_18000bf1e;
      }
      if (param_1 == 2) goto LAB_18000c046;
      goto LAB_18000bf2b;
    }
    local_348 = DAT_180040c48;
    local_340 = DAT_180040c50;
    local_33e = DAT_180040c52;
    uVar5 = GetSorResStringEx(1999);
LAB_18000c046:
    iVar2 = FUN_180026510((char *)pcVar8,(char *)&local_348);
    if (iVar2 == -1) {
      bVar1 = FUN_1800297f0();
      uVar6 = 0x7d1;
      if ((int)CONCAT71(extraout_var,bVar1) != 0) {
        uVar6 = 0x7d2;
      }
      pcVar3 = (char *)GetSorResStringEx(uVar6);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_358,pcVar3,
                 uVar5);
      MMAfxMessageBox(local_358[0],0x30,-1,0);
      goto LAB_18000c151;
    }
  }
LAB_18000c09c:
  iVar2 = SBlocalhost();
  if (iVar2 == 0) {
    GetEditorTempFileName(local_138);
    puVar4 = (undefined1 *)FUN_18001a130();
    iVar2 = FUN_18002b2c0(local_138,&local_348,puVar4);
    if (iVar2 != 0) {
      pcVar3 = (char *)GetSorResStringEx(0x7d3);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_358,pcVar3,
                 uVar5);
      MMAfxMessageBox(local_358[0],0x30,-1,0);
      uVar9 = 0x80004005;
      goto LAB_18000c151;
    }
    iVar2 = 0;
    pCVar7 = local_138;
  }
  else {
    if (pcVar8 == (code *)0x0) {
      pCVar7 = (LPCSTR)&local_348;
    }
    else {
      FUN_180008f80(local_138,"%s\\%s",pcVar8,&local_348);
      pCVar7 = local_138;
    }
    iVar2 = 1;
  }
  FUN_180009bc0(pCVar7,iVar2,0,(LPCSTR)0x0);
LAB_18000c151:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_358);
  return uVar9;
}

/* RVA 0xc190 */
undefined8 FUN_18000c190(char *param_1)

{
  int iVar1;
  char *pcVar2;
  longlong lVar3;
  
  iVar1 = SBlocalhost();
  if (((iVar1 != 0) || (iVar1 = strncmp(param_1,"LaunchEditor",0xc), iVar1 != 0)) ||
     (pcVar2 = strrchr(param_1,0x20), pcVar2 == (char *)0x0)) {
    lVar3 = Ordinal_73(param_1,0,DAT_180051c18 != 0);
    if (lVar3 != 0) {
      return 0;
    }
    iVar1 = strncmp(param_1,"LaunchEditor",0xc);
    if (iVar1 != 0) {
      return 0;
    }
    pcVar2 = strrchr(param_1,0x20);
    if (pcVar2 == (char *)0x0) {
      return 0;
    }
  }
  PostMainWndMessage(0x545,pcVar2 + 1,0);
  return 0;
}

/* RVA 0xc230 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SimExportEOReport(char *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  undefined7 extraout_var;
  char *pcVar3;
  undefined1 *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  code *pcVar8;
  undefined1 auStack_278 [32];
  undefined8 local_258 [2];
  undefined8 local_248;
  undefined2 local_240;
  undefined1 local_23e;
  char local_138 [4];
  char local_134 [252];
  ulonglong local_38;
  
                    /* 0xc230  132  SimExportEOReport */
  local_38 = DAT_1800516d8 ^ (ulonglong)auStack_278;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_258);
  uVar7 = 0;
  pcVar8 = (code *)0x0;
  uVar5 = 0;
  if (param_2 == 1) {
    local_138[0] = (char)DAT_180040c3c;
    local_138[1] = DAT_180040c3c._1_1_;
    local_138[2] = DAT_180040c3c._2_1_;
    local_138[3] = DAT_180040c3c._3_1_;
    uVar5 = 0x7ce;
    local_134._0_2_ = DAT_180040c40;
LAB_18000c2ff:
    uVar5 = GetSorResStringEx(uVar5);
LAB_18000c30c:
    if (DAT_180052ec4 != 0) {
      iVar2 = GRinqiap();
      if (iVar2 == 0) {
        if (DAT_180052ec4 == 0) goto LAB_18000c3b9;
        iVar2 = GRinqiap();
        if (iVar2 == 0) {
          FUN_180008f80(&local_248,"%s.%s",APtmpfil_exref,local_138);
          iVar2 = FUN_180026510((char *)0x0,(char *)&local_248);
          if (iVar2 != -1) goto LAB_18000c46f;
          uVar6 = GRinqfnm();
          FUN_180008f80(&local_248,"%s.%s",uVar6,local_138);
          _strlwr((char *)&local_248);
          pcVar8 = open_path_exref;
        }
      }
      else {
        FUN_180008f80(&local_248,"%s.%s",APtmpfil_exref,local_138);
      }
      goto LAB_18000c427;
    }
LAB_18000c3b9:
    uVar6 = GRinqfnm();
    FUN_180008f80(&local_248,"%s.%s",uVar6,local_138);
    _strlwr((char *)&local_248);
    iVar2 = FUN_180026510((char *)open_path_exref,(char *)&local_248);
    if (iVar2 == -1) {
      FUN_180008f80(&local_248,"%s.%s",APtmpfil_exref,local_138);
      goto LAB_18000c427;
    }
  }
  else {
    if (param_2 != 2) {
      if (param_2 == 3) {
        local_138[0] = s_atact_180040c54[0];
        local_138[1] = s_atact_180040c54[1];
        local_138[2] = s_atact_180040c54[2];
        local_138[3] = s_atact_180040c54[3];
        uVar5 = 2000;
        local_134._0_2_ = s_atact_180040c54._4_2_;
        goto LAB_18000c2ff;
      }
      if (param_2 == 2) goto LAB_18000c427;
      goto LAB_18000c30c;
    }
    local_248 = DAT_180040c48;
    local_240 = DAT_180040c50;
    local_23e = DAT_180040c52;
    uVar5 = GetSorResStringEx(1999);
LAB_18000c427:
    iVar2 = FUN_180026510((char *)pcVar8,(char *)&local_248);
    if (iVar2 == -1) {
      bVar1 = FUN_1800297f0();
      uVar6 = 0x7d1;
      if ((int)CONCAT71(extraout_var,bVar1) != 0) {
        uVar6 = 0x7d2;
      }
      pcVar3 = (char *)GetSorResStringEx(uVar6);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_258,pcVar3,
                 uVar5);
      GenerateErrorInfo(local_258[0]);
      goto LAB_18000c4d0;
    }
  }
LAB_18000c46f:
  iVar2 = SBlocalhost();
  if (iVar2 == 0) {
    puVar4 = (undefined1 *)FUN_18001a130();
    iVar2 = FUN_18002b2c0(param_1,&local_248,puVar4);
    if (iVar2 != 0) {
      pcVar3 = (char *)GetSorResStringEx(0x7d3);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_258,pcVar3,
                 uVar5);
      GenerateErrorInfo(local_258[0]);
      uVar7 = 0x80004005;
    }
  }
  else {
    CopyFileA((LPCSTR)&local_248,param_1,0);
  }
LAB_18000c4d0:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_258);
  return uVar7;
}

/* RVA 0xc510 */
undefined8 SimGetControlPanelMessage(void)

{
                    /* 0xc510  167  SimGetControlPanelMessage */
  return DAT_180051c20;
}

/* RVA 0xc520 */
void SimSetControlPanelMessage(OLECHAR *param_1)

{
                    /* 0xc520  166  SimSetControlPanelMessage */
  SimClearControlPanelMessage();
  DAT_180051c20 = SysAllocString(param_1);
  return;
}

/* RVA 0xc550 */
undefined8 FUN_18000c550(undefined1 *param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  int iVar2;
  undefined8 uVar3;
  ulonglong *puVar4;
  undefined8 local_res20;
  
  if (param_2 - 1U < 0x7fffffff) {
    uVar1 = param_2 - 1;
    uVar3 = 0;
    local_res20 = param_4;
    puVar4 = (ulonglong *)FUN_180001b20();
    iVar2 = __stdio_common_vsprintf(*puVar4 | 1,param_1,uVar1,param_3,0,&local_res20);
    if (iVar2 < 0) {
      iVar2 = -1;
    }
    if ((iVar2 < 0) || (uVar1 < (ulonglong)(longlong)iVar2)) {
      param_1[uVar1] = 0;
      uVar3 = 0x8007007a;
    }
    else if ((longlong)iVar2 == uVar1) {
      param_1[uVar1] = 0;
    }
  }
  else {
    uVar3 = 0x80070057;
    if (param_2 != 0) {
      *param_1 = 0;
      return uVar3;
    }
  }
  return uVar3;
}

/* RVA 0xc610 */
/* Library Function - Multiple Matches With Same Base Name
    public: void __cdecl std::_Parallelism_allocator<unsigned __int64>::deallocate(unsigned __int64
   * __ptr64 const,unsigned __int64) __ptr64
    public: void __cdecl std::allocator<struct CHN * __ptr64>::deallocate(struct CHN * __ptr64 *
   __ptr64 const,unsigned __int64) __ptr64
    public: void __cdecl std::allocator<struct `void __cdecl
   phmap::container_internal::Deallocate<8,class std::allocator<struct std::pair<unsigned long const
   ,struct TPI1::PRECEX * __ptr64> > >(class std::allocator<struct std::pair<unsigned long const
   ,struct TPI1::PRECEX * __ptr64> > * __ptr64,void * __ptr64,unsigned
   __int64)'::`2'::M>::deallocate(struct `void __cdecl phmap::container_internal::Deallocate<8,class
   std::allocator<struct std::pair<unsigned long const ,struct TPI1::PRECEX * __ptr64> > >(class
   std::allocator<struct std::pair<unsigned long const ,struct TPI1::PRECEX * __ptr64> > *
   __ptr64,void * __ptr64,unsigned __int64)'::`2'::M * __ptr64 const,unsigned __int64) __ptr64
    public: void __cdecl std::allocator<struct `void __cdecl
   phmap::container_internal::Deallocate<8,class std::allocator<struct std::pair<unsigned long const
   ,struct TYPTYPE * __ptr64> > >(class std::allocator<struct std::pair<unsigned long const ,struct
   TYPTYPE * __ptr64> > * __ptr64,void * __ptr64,unsigned __int64)'::`2'::M>::deallocate(struct
   `void __cdecl phmap::container_internal::Deallocate<8,class std::allocator<struct
   std::pair<unsigned long const ,struct TYPTYPE * __ptr64> > >(class std::allocator<struct
   std::pair<unsigned long const ,struct TYPTYPE * __ptr64> > * __ptr64,void * __ptr64,unsigned
   __int64)'::`2'::M * __ptr64 const,unsigned __int64) __ptr64
     16 names - too many to list
   
   Library: Visual Studio 2019 Release */

void deallocate(undefined8 param_1,void *param_2,longlong param_3)

{
  void *pvVar1;
  
  pvVar1 = param_2;
  if ((0xfff < (ulonglong)(param_3 * 8)) &&
     (pvVar1 = *(void **)((longlong)param_2 + -8),
     0x1f < (ulonglong)((longlong)param_2 + (-8 - (longlong)pvVar1)))) {
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
  FUN_180001300(pvVar1);
  return;
}

/* RVA 0xc660 */
void FUN_18000c660(void)

{
  DWORD dwMessageId;
  int iVar1;
  char *hMem;
  undefined8 uVar2;
  SIZE_T SVar3;
  LPCSTR local_res8;
  
  dwMessageId = GetLastError();
  FormatMessageA(0x1300,(LPCVOID)0x0,dwMessageId,0x400,(LPSTR)&local_res8,0,(va_list *)0x0);
  iVar1 = lstrlenA(local_res8);
  hMem = LocalAlloc(0x40,(longlong)(iVar1 + 0x32));
  uVar2 = GetSorResStringEx(0x1d2);
  SVar3 = LocalSize(hMem);
  FUN_18000c550(hMem,SVar3,uVar2,(ulonglong)dwMessageId);
  MMAfxMessageBox(hMem,0x30,-1,0);
  LocalFree(local_res8);
  LocalFree(hMem);
  return;
}

/* RVA 0xc730 */
void SetPostSolve(undefined1 param_1)

{
                    /* 0xc730  169  SetPostSolve */
  DAT_180051c1d = param_1;
  return;
}

/* RVA 0xc740 */
void SetPreSolve(undefined1 param_1)

{
                    /* 0xc740  168  SetPreSolve */
  DAT_180051c1c = param_1;
  return;
}

/* RVA 0xc750 */
undefined8 SimAddStopPoint(int param_1,char *param_2,int param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  
                    /* 0xc750  80  SimAddStopPoint */
  lVar1 = FUN_1800213d0();
  uVar2 = FUN_180020520(lVar1,1,param_3,param_1,param_2);
  if ((int)uVar2 != -1) {
    lVar1 = FUN_1800213d0();
    FUN_180020ec0(lVar1,1);
  }
  return 0;
}

/* RVA 0xc7b0 */
void FUN_18000c7b0(void)

{
  longlong *plVar1;
  int iVar2;
  CRuntimeClass *pCVar3;
  BSTR bstrString;
  longlong *local_res8;
  longlong *local_res10;
  longlong *local_res18;
  _union_2707 local_58;
  undefined4 local_38;
  ULONG UStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined8 local_28;
  
  pCVar3 = CSimEventsThread::GetRuntimeClass();
  AfxBeginThread(pCVar3,0,0,0,(_SECURITY_ATTRIBUTES *)0x0);
  if (DAT_180051dd4 == 0) {
    local_res18 = (longlong *)0x0;
    iVar2 = Ordinal_78(&local_res18);
    plVar1 = local_res18;
    if (-1 < iVar2) {
      local_res10 = (longlong *)0x0;
      bstrString = SysAllocString(L"ASCSimEventMgr");
      if (bstrString == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_180001380(-0x7ff8fff2);
      }
      iVar2 = (**(code **)(*plVar1 + 0x58))(plVar1,bstrString,&local_res10);
      SysFreeString(bstrString);
      if (-1 < iVar2) {
        local_res8 = (longlong *)0x0;
        iVar2 = (**(code **)*local_res10)(local_res10,&DAT_180040f60,&local_res8);
        if (-1 < iVar2) {
          local_58._0_8_ = 0;
          local_58.decVal.u2 = (_union_1719)(_struct_1720)0x0;
          local_58._16_8_ = 0;
          VariantInit((VARIANTARG *)&local_58.n2);
          local_38 = local_58._0_4_;
          UStack_34 = local_58.decVal.Hi32;
          uStack_30 = local_58._8_4_;
          uStack_2c = local_58._12_4_;
          local_28 = local_58._16_8_;
          Ordinal_115(local_res8,0x3c,FUN_18000a160,&local_38,&DAT_180051dd4);
          VariantClear((VARIANTARG *)&local_58.n2);
        }
        if (local_res8 != (longlong *)0x0) {
          (**(code **)(*local_res8 + 0x10))();
        }
      }
      if (local_res10 != (longlong *)0x0) {
        (**(code **)(*local_res10 + 0x10))();
      }
    }
    if (local_res18 != (longlong *)0x0) {
      (**(code **)(*local_res18 + 0x10))();
    }
  }
  return;
}

/* RVA 0xc910 */
int SimAttachNotify(int param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 *local_res20;
  
                    /* 0xc910  136  SimAttachNotify */
  if (param_1 == 0) {
    local_res20 = operator_new(0x10);
    *local_res20 = param_2;
    local_res20[1] = param_3;
    if (DAT_180051df8 == DAT_180051e00) {
      FUN_18000a900(&DAT_180051df0,DAT_180051df8,&local_res20);
      iVar1 = DAT_180051e3c;
      DAT_180051e3c = DAT_180051e3c + 1;
      return iVar1;
    }
    *DAT_180051df8 = local_res20;
    iVar1 = DAT_180051e3c;
    DAT_180051df8 = DAT_180051df8 + 1;
    DAT_180051e3c = DAT_180051e3c + 1;
    return iVar1;
  }
  if (param_1 == 1) {
    local_res20 = operator_new(0x10);
    *local_res20 = param_2;
    local_res20[1] = param_3;
    if (DAT_180051de0 == DAT_180051de8) {
      FUN_18000a900(&DAT_180051dd8,DAT_180051de0,&local_res20);
      iVar1 = DAT_180051e38;
      DAT_180051e38 = DAT_180051e38 + 1;
      return iVar1;
    }
    *DAT_180051de0 = local_res20;
    iVar1 = DAT_180051e38;
    DAT_180051de0 = DAT_180051de0 + 1;
    DAT_180051e38 = DAT_180051e38 + 1;
    return iVar1;
  }
  if (param_1 == 2) {
    local_res20 = operator_new(0x10);
    *local_res20 = param_2;
    local_res20[1] = param_3;
    if (DAT_180051e10 == DAT_180051e18) {
      FUN_18000a900(&DAT_180051e08,DAT_180051e10,&local_res20);
      iVar1 = DAT_180051e40;
      DAT_180051e40 = DAT_180051e40 + 1;
      return iVar1;
    }
    *DAT_180051e10 = local_res20;
    iVar1 = DAT_180051e40;
    DAT_180051e10 = DAT_180051e10 + 1;
    DAT_180051e40 = DAT_180051e40 + 1;
    return iVar1;
  }
  if (param_1 != 3) {
    return -1;
  }
  local_res20 = operator_new(0x10);
  *local_res20 = param_2;
  local_res20[1] = param_3;
  if (DAT_180051e28 == DAT_180051e30) {
    FUN_18000a900(&DAT_180051e20,DAT_180051e28,&local_res20);
    iVar1 = DAT_180051e44;
    DAT_180051e44 = DAT_180051e44 + 1;
    return iVar1;
  }
  *DAT_180051e28 = local_res20;
  iVar1 = DAT_180051e44;
  DAT_180051e28 = DAT_180051e28 + 1;
  DAT_180051e44 = DAT_180051e44 + 1;
  return iVar1;
}

/* RVA 0xcb20 */
bool SimCanReport(void)

{
  int iVar1;
  
                    /* 0xcb20  164  SimCanReport */
  iVar1 = FUN_180022a50(0x13,1,(char *)0x1,(uchar *)0x0);
  return iVar1 == 0;
}

/* RVA 0xcb50 */
void FUN_18000cb50(IMAGE_DOS_HEADER *param_1,undefined8 param_2,int *param_3,char *param_4)

{
  SimMain((char *)0x9,param_1,param_3,param_4);
  return;
}

/* RVA 0xcb60 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18000cb60(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined7 extraout_var;
  undefined1 *puVar5;
  LPCSTR pCVar6;
  code *pcVar7;
  char *pcVar8;
  char *pcVar9;
  undefined8 uVar10;
  undefined1 auStack_288 [32];
  char *local_268 [2];
  char local_258 [272];
  char local_148 [272];
  ulonglong local_38;
  
  local_38 = DAT_1800516d8 ^ (ulonglong)auStack_288;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_268);
  uVar10 = 0;
  pcVar7 = (code *)0x0;
  bVar1 = false;
  iVar3 = 1;
  if (DAT_180052ec4 == 0) {
LAB_18000ccb1:
    iVar2 = MVGetProductCode();
    pcVar9 = ".aprhis";
    pcVar8 = ".aprhis";
    if (iVar2 == 1) {
      pcVar8 = ".his";
    }
    uVar4 = GRinqfnm();
    FUN_180008f80(local_258,&DAT_18003f9b0,uVar4,pcVar8);
    _strlwr(local_258);
    iVar2 = FUN_180026510((char *)open_path_exref,local_258);
    if (iVar2 == -1) {
      iVar2 = MVGetProductCode();
      if (iVar2 == 1) {
        pcVar9 = ".his";
      }
      FUN_180008f80(local_258,&DAT_18003f9b0,APtmpfil_exref,pcVar9);
    }
    else {
      bVar1 = true;
      pcVar7 = open_path_exref;
    }
    if (!bVar1) goto LAB_18000cd47;
LAB_18000cdce:
    iVar2 = SBlocalhost();
    if (iVar2 == 0) {
      GetEditorTempFileName(local_148);
      puVar5 = (undefined1 *)FUN_18001a130();
      iVar3 = FUN_18002b2c0(local_148,local_258,puVar5);
      if (iVar3 != 0) {
        uVar10 = 0x7cd;
        goto LAB_18000cdff;
      }
      pCVar6 = local_148;
      iVar3 = 0;
    }
    else if (pcVar7 == (code *)0x0) {
      pCVar6 = local_258;
    }
    else {
      FUN_180008f80(local_148,"%s\\%s",pcVar7,local_258);
      pCVar6 = local_148;
    }
    FUN_180009bc0(pCVar6,iVar3,0,(LPCSTR)0x0);
    if (DAT_180052ec4 != 0) {
      iVar3 = GRinqiap();
      if (iVar3 != 0) {
        FUN_180017f80();
      }
    }
  }
  else {
    iVar2 = GRinqiap();
    if (iVar2 == 0) {
      if (DAT_180052ec4 == 0) goto LAB_18000ccb1;
      iVar2 = GRinqiap();
      if (iVar2 == 0) {
        iVar2 = MVGetProductCode();
        pcVar8 = ".aprhis";
        pcVar9 = ".aprhis";
        if (iVar2 == 1) {
          pcVar9 = ".his";
        }
        FUN_180008f80(local_258,&DAT_18003f9b0,APtmpfil_exref,pcVar9);
        iVar2 = FUN_180026510((char *)0x0,local_258);
        if (iVar2 != -1) goto LAB_18000cdce;
        iVar2 = MVGetProductCode();
        if (iVar2 == 1) {
          pcVar8 = ".his";
        }
        uVar4 = GRinqfnm();
        FUN_180008f80(local_258,&DAT_18003f9b0,uVar4,pcVar8);
        _strlwr(local_258);
        pcVar7 = open_path_exref;
      }
    }
    else {
      iVar2 = MVGetProductCode();
      pcVar8 = ".aprhis";
      if (iVar2 == 1) {
        pcVar8 = ".his";
      }
      FUN_180008f80(local_258,&DAT_18003f9b0,APtmpfil_exref,pcVar8);
      iVar2 = FUN_180017f80();
      if (iVar2 < 1) {
        uVar10 = 0x80004005;
        goto LAB_18000ce86;
      }
    }
LAB_18000cd47:
    iVar2 = FUN_180026510((char *)pcVar7,local_258);
    if (iVar2 != -1) goto LAB_18000cdce;
    bVar1 = FUN_1800297f0();
    if ((int)CONCAT71(extraout_var,bVar1) == 0) {
      iVar3 = MVGetProductCode();
      uVar10 = 0x7c7;
      if (iVar3 != 2) {
        uVar10 = 0x7c8;
      }
LAB_18000cdff:
      pcVar8 = (char *)GetSorResStringEx(uVar10);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_268,pcVar8);
    }
    else {
      iVar3 = MVGetProductCode();
      if (iVar3 == 2) {
        GetSorResStringEx(0x7ca);
        uVar10 = 0x7c9;
      }
      else {
        GetSorResStringEx(0x7cc);
        uVar10 = 0x7cb;
      }
      uVar10 = GetSorResStringEx(uVar10);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_268,"%s%s",
                 uVar10);
    }
    MMAfxMessageBox(local_268[0],0x30,-1,0);
    uVar10 = 0x80004005;
  }
LAB_18000ce86:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_268);
  return uVar10;
}

/* RVA 0xced0 */
undefined4 SimCheckImport(char *param_1)

{
  int iVar1;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar2;
  undefined8 uVar3;
  char *pcVar4;
  undefined4 uVar5;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res10 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res18 [8];
  
                    /* 0xced0  61  SimCheckImport */
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    pcVar4 = (char *)GetSorResStringEx(0x1cf);
    MMAfxMessageBox(pcVar4,0x30,-1,0);
    return 0x80004005;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10,param_1);
  iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                    (local_res10,'.');
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
  if (0 < iVar1) {
    pCVar2 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Right
                       (local_res10,(int)local_res18);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(local_res8,pCVar2)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
  }
  iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                    (local_res8,"sum");
  if (iVar1 == 0) {
    uVar3 = FUN_18001a650(param_1);
    iVar1 = (int)uVar3;
  }
  else {
    iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                      (local_res8,"bkp");
    if ((iVar1 != 0) &&
       (iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                          (local_res8,"aprbkp"), iVar1 != 0)) {
      uVar5 = 0;
      goto LAB_18000cfbf;
    }
    uVar3 = FUN_18001a520();
    iVar1 = (int)uVar3;
  }
  uVar5 = 0x80004005;
  if (iVar1 != 0) {
    uVar5 = 0;
  }
LAB_18000cfbf:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10);
  return uVar5;
}

/* RVA 0xd010 */
void SimClearAllStops(void)

{
  longlong lVar1;
  
                    /* 0xd010  77  SimClearAllStops */
  lVar1 = FUN_1800213d0();
  FUN_180020820();
  FUN_180020ec0(lVar1,1);
  return;
}

/* RVA 0xd040 */
ulonglong SimCommand(char *param_1,IMAGE_DOS_HEADER *param_2,int *param_3,char *param_4)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined4 extraout_var_08;
  longlong lVar16;
  undefined8 *puVar17;
  BSTR pOVar18;
  char *_Str1;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  undefined7 extraout_var_01;
  undefined7 extraout_var_02;
  undefined7 extraout_var_03;
  undefined7 extraout_var_04;
  undefined7 extraout_var_05;
  undefined7 extraout_var_06;
  undefined7 extraout_var_07;
  IMAGE_DOS_HEADER *pIVar19;
  char *pcVar20;
  int *piVar21;
  ulonglong uVar22;
  int aiStackX_8 [2];
  char *pcStackX_18;
  char *pcStackX_20;
  undefined8 in_stack_ffffffffffffffb0;
  
                    /* 0xd040  127  SimCommand */
  uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffffb0 >> 0x20);
  iVar5 = 0;
  uVar7 = (uint)param_1;
  uVar22 = (ulonglong)(int)uVar7;
  pIVar19 = param_2;
  if ((uVar7 - 1 & 0xfffffffb) == 0) {
    aiStackX_8[0] = 0;
    param_3 = aiStackX_8;
    param_1 = (char *)0x552;
    pIVar19 = (IMAGE_DOS_HEADER *)(ulonglong)(uVar7 == 5);
    SimSendMainWndMessage(0x552,pIVar19,param_3);
    if (aiStackX_8[0] != 0) {
      return 0x80004005;
    }
    if (uVar7 != 1) goto LAB_18000fdd2;
LAB_18000fde2:
    uVar9 = SimInEOMode();
    if ((int)uVar9 != 0) {
      if (uVar7 == 1) {
        iVar4 = GRinqsms();
        if (((iVar4 == 0) || (iVar4 = GRinqsmf(), iVar4 != 0)) && (iVar4 = GRinqmtf(), iVar4 == 0))
        {
          iVar5 = GRinqautorun();
          if (((iVar5 == 1) && (iVar5 = GRinqpgc(), iVar5 == 0)) &&
             (iVar5 = GRinqeorsl(), iVar5 != 0)) {
            return 0x80004005;
          }
LAB_18000ffa7:
          uVar6 = SimEORun(param_2->e_magic);
          return CONCAT44(extraout_var_08,uVar6);
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&pcStackX_20);
        iVar4 = GRinqsmstrat();
        if (iVar4 == 1) {
          uVar10 = GetSorResStringEx(0x1bc);
          uVar11 = GetSorResStringEx(0x1bb);
          uVar12 = GetSorResStringEx(0x1ba);
          uVar13 = GetSorResStringEx(0x1b9);
          uVar14 = GetSorResStringEx(0x1b8);
          uVar15 = GetSorResStringEx(0x1b7);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&pcStackX_20,
                     "%s\n%s\n%s\n\n%s\n%s\n%s",uVar15,uVar14,uVar13,uVar12,uVar11,uVar10);
          uVar6 = (undefined4)((ulonglong)uVar10 >> 0x20);
        }
        else {
          uVar10 = GetSorResStringEx(0x1bc);
          uVar11 = GetSorResStringEx(0x1bb);
          uVar12 = GetSorResStringEx(0x1ba);
          uVar13 = GetSorResStringEx(0x1bd);
          uVar14 = GetSorResStringEx(0x1be);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&pcStackX_20,
                     "%s\n%s\n\n%s\n%s\n%s",uVar14,uVar13,uVar12,uVar11,uVar10);
        }
        param_4 = (char *)0x0;
        param_3 = (int *)0xffffffff;
        pIVar19 = (IMAGE_DOS_HEADER *)0x33;
        iVar4 = MMAfxMessageBox(pcStackX_20,0x33,-1,0);
        param_1 = (char *)&pcStackX_20;
        if (iVar4 == 2) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_1);
          return 0x80004005;
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_1);
        if (iVar4 == 7) goto LAB_18000ffa7;
      }
      else {
        if (uVar7 == 5) {
          uVar22 = FUN_18000e0d0();
          return uVar22;
        }
        if (uVar7 == 0x33) {
          uVar22 = FUN_18000d8f0();
          return uVar22;
        }
      }
    }
  }
  else {
LAB_18000fdd2:
    if ((uVar7 == 5) || (uVar7 == 0x33)) goto LAB_18000fde2;
  }
  bVar3 = false;
  bVar2 = false;
  bVar1 = false;
  if (DAT_180051c18 == 0) {
    pcVar20 = pIVar19->e_magic;
    if (uVar7 != 9) goto LAB_18000ffd5;
  }
  else {
    if (uVar7 != 10) {
      return 0x80004005;
    }
LAB_18000ffd5:
    param_1 = "AnalysisForm";
    lVar16 = GetGlobalPointer();
    if (lVar16 != 0) {
      if (0xc < uVar7 - 10) {
switchD_180010002_caseD_d:
        uVar10 = 0x1c0;
LAB_180010009:
        uVar10 = GetSorResStringEx(uVar10);
        uVar11 = MVGetI18nProductName();
        open_message_box(uVar11,uVar10,&DAT_1800408b0,0,0,0,0,CONCAT44(uVar6,1),0);
        return 0;
      }
      pIVar19 = &IMAGE_DOS_HEADER_180000000;
      param_1 = (char *)((ulonglong)(&switchD_180010002::switchdataD_18001082c)[(int)(uVar7 - 10)] +
                        0x180000000);
      switch(uVar7) {
      default:
        break;
      case 0xb:
        uVar10 = 0x1bf;
        goto LAB_180010009;
      case 0xd:
      case 0xe:
      case 0xf:
      case 0x10:
      case 0x11:
        goto switchD_180010002_caseD_d;
      }
    }
    if (uVar7 == 0xc) {
      uVar10 = FUN_18000d050(0,(longlong *)0x0);
      if ((int)uVar10 == 0) {
        FUN_180019330(0);
        return 0;
      }
      return 0;
    }
    if (uVar7 == 10) {
      GRsetust(1);
      return 0;
    }
    pcVar20 = pIVar19->e_magic;
    if (uVar7 == 0xb) {
      uVar22 = SimInEOMode();
      if ((int)uVar22 != 0) {
        PostMainWndMessage(0x545,"EOReinit",0);
        return 0;
      }
      FUN_180019330(1);
      uVar7 = 0;
      if (DAT_180052ce4 == 1) {
        uVar7 = 0x80004005;
      }
      return (ulonglong)uVar7;
    }
  }
  if (uVar7 - 0xf < 3) {
    PostMainWndMessage(0x545,"Batch Submit",0);
    return 0;
  }
  if (uVar7 == 0x12) {
    SimInputSummary();
    return 0;
  }
  if (uVar7 == 0x13) {
    FUN_18000cb60();
    return 0;
  }
  if (uVar7 == 0x14) {
    PostMainWndMessage(0x545,"Run Settings",0);
    return 0;
  }
  if (uVar7 == 0x15) {
    FUN_1800143f0(param_1,pcVar20,param_3,param_4);
    return 0;
  }
  if (uVar7 == 0x16) {
    SimDisplayReport(0,(char *)0x0,0);
    return 0;
  }
  if (uVar7 == 0x17) {
    puVar17 = operator_new(0x18);
    if (puVar17 != (undefined8 *)0x0) {
      puVar17[1] = 0;
      *(undefined4 *)(puVar17 + 2) = 1;
      pOVar18 = SysAllocString(L"PDBActivateDlg");
      *puVar17 = pOVar18;
      if (pOVar18 != (BSTR)0x0) {
        uVar7 = FUN_1800090b0(pOVar18);
        LOCK();
        piVar21 = (int *)(puVar17 + 2);
        iVar5 = *piVar21;
        *piVar21 = *piVar21 + -1;
        UNLOCK();
        if (iVar5 == 1) {
          if ((BSTR)*puVar17 != (BSTR)0x0) {
            SysFreeString((BSTR)*puVar17);
            *puVar17 = 0;
          }
          if ((void *)puVar17[1] != (void *)0x0) {
            operator_delete__((void *)puVar17[1]);
            puVar17[1] = 0;
          }
          FUN_180001300(puVar17);
        }
        return (ulonglong)uVar7;
      }
    }
                    /* WARNING: Subroutine does not return */
    FUN_18003c7f0(0x8007000e);
  }
  if (uVar7 == 0x18) {
    PostMainWndMessage(0x545,"PDBGet",0);
    return 0;
  }
  if (uVar7 == 0x19) {
    PostMainWndMessage(0x545,"PDBPut",0);
    return 0;
  }
  if (uVar7 == 0x1a) {
    uVar22 = FUN_18000ebd0(param_2->e_magic,pcVar20,param_3,param_4);
    return uVar22;
  }
  if (uVar7 == 0x28) {
    uVar22 = FUN_18000eec0(param_2->e_magic);
    return uVar22;
  }
  if (uVar7 == 0x1b) {
    uVar11 = 0;
    uVar10 = 0x101b;
    SimReflect(2,0x101b,0);
    uVar7 = FUN_18000e8e0(param_2->e_magic,uVar10,uVar11,param_4);
    SimSendMainWndMessage(0x540,0x101b,0);
    return (ulonglong)uVar7;
  }
  if (uVar7 == 0x1c) {
    iVar4 = GRinqlcp();
    if (iVar4 == 0) {
      return 0;
    }
    iVar4 = GRinqcnn();
    if (iVar4 == 0) {
      return 0;
    }
    GRsetpri();
    GRsetigb();
  }
  else if (uVar7 == 0x1d) {
    GRsetpri();
    _Str1 = (char *)GRinqigb();
    if (_Str1 == (char *)0x0) {
LAB_180010308:
      iVar4 = GRinqgcp();
      if (iVar4 != 0) goto LAB_18001060b;
    }
    else {
      pcVar20 = "########";
      iVar4 = strcmp(_Str1,"########");
      if (iVar4 != 0) goto LAB_180010308;
    }
    GRsetedt();
  }
  else {
    GRsetpri();
    GRsetigb();
    if ((uVar7 < 0x28) && ((0x8680000000U >> (uVar22 & 0x3f) & 1) != 0)) {
      DAT_180051c10 = 0;
      if ((param_2 != (IMAGE_DOS_HEADER *)0x0) && (param_2->e_magic[0] != '\0')) {
        pcVar20 = param_2->e_magic;
        iVar4 = _stricmp("solve",param_2->e_magic);
        if (iVar4 != 0) {
          param_3 = (int *)0x6;
          pcVar20 = param_2->e_magic;
          iVar4 = _strnicmp("solve ",param_2->e_magic,6);
          if (iVar4 != 0) {
            pcVar20 = param_2->e_magic;
            iVar4 = _stricmp("parse solve",param_2->e_magic);
            if (iVar4 != 0) {
              param_3 = (int *)0xc;
              pcVar20 = param_2->e_magic;
              iVar4 = _strnicmp("parse solve ",param_2->e_magic,0xc);
              if (iVar4 != 0) goto LAB_1800103bb;
            }
          }
        }
        DAT_180051c10 = 1;
      }
LAB_1800103bb:
      DAT_180051c04 = 0;
      DAT_180051c08 = 1;
      if (((*(int *)bestinput_exref == 0) && (*(int *)runanyway_exref == 0)) &&
         (iVar4 = GRinqcmp(), iVar4 == 0)) {
        DAT_180051c04 = 1;
        DAT_180051c08 = 0;
      }
      else {
        if (uVar7 == 0x1f) {
          DAT_180051c08 = 0;
          goto LAB_18001060b;
        }
        iVar4 = GRinqpgc();
        if (iVar4 != 0) {
          iVar4 = GRinqnec();
          if (iVar4 != 0) {
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&pcStackX_18
                      );
            iVar4 = GRinqautorun();
            if (iVar4 != 1) {
              lVar16 = GetGlobalPointer("RunFromPlantData");
              if (lVar16 != 0) {
                param_4 = "False";
                piVar21 = (int *)0x0;
                do {
                  pcVar20 = (char *)(ulonglong)*(byte *)(lVar16 + (longlong)piVar21);
                  param_3 = (int *)((longlong)piVar21 + 1);
                  if (*(byte *)(lVar16 + (longlong)piVar21) != *(byte *)(piVar21 + 0x60010257))
                  goto LAB_180010538;
                  piVar21 = param_3;
                } while (param_3 != (int *)0x6);
              }
              uVar10 = GetSorResStringEx(0x1bc);
              uVar11 = GetSorResStringEx(0x1c6);
              uVar12 = GetSorResStringEx(0x1c5);
              uVar13 = GetSorResStringEx(0x1c4);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         &pcStackX_18,"%s\n%s\n\n%s\n%s ",uVar13,uVar12,uVar11,uVar10);
              param_4 = (char *)0x0;
              param_3 = (int *)0xffffffff;
              pcVar20 = (char *)0x31;
              iVar4 = MMAfxMessageBox(pcStackX_18,0x31,-1,0);
              if (iVar4 == 2) {
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &pcStackX_18);
                return 0;
              }
              if (iVar4 == 7) {
                DAT_180051c04 = 1;
                bVar3 = true;
                DAT_180051c08 = 0;
              }
            }
LAB_180010538:
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&pcStackX_18
                      );
            bVar2 = bVar3;
          }
        }
      }
    }
    bVar1 = bVar2;
    if (uVar7 == 0x23) {
      FUN_18000be50(1);
      return 0;
    }
    if (uVar7 == 0x24) {
      FUN_18000be50(2);
      return 0;
    }
    if (uVar7 == 0x25) {
      FUN_18000be50(3);
      return 0;
    }
    if (uVar7 == 0x29) {
      uVar22 = FUN_180014460(param_2->e_magic,'\x01');
      return uVar22;
    }
    if (uVar7 == 0x2a) {
      uVar22 = FUN_180013de0(param_2->e_magic);
      return uVar22;
    }
    if (uVar7 == 0x2b) {
      uVar22 = FUN_180014460(param_2->e_magic,'\0');
      return uVar22;
    }
    if (((uVar7 == 1) && (iVar4 = GRinqdrs(), iVar4 != 0)) && (iVar4 = MMGetSuppress(), iVar4 == 0))
    {
      if ((param_2 != (IMAGE_DOS_HEADER *)0x0) && (param_2->e_magic[0] != '\0')) {
        pcVar20 = "NoShowDialog";
        iVar4 = _stricmp(param_2->e_magic,"NoShowDialog");
        if (iVar4 == 0) goto LAB_18001060b;
      }
      iVar4 = FUN_1800094a0();
      if (iVar4 < 1) {
        return 0;
      }
    }
  }
LAB_18001060b:
  bVar3 = FUN_18002f5f0(0);
  iVar4 = aiStackX_8[0];
  if ((int)CONCAT71(extraout_var,bVar3) == 0) {
    if (*(int *)debug_flag_exref == 0) {
      if (bVar1) {
        iVar4 = *(int *)simulate_flag_exref;
        *(undefined4 *)simulate_flag_exref = 0;
      }
    }
    else {
      bVar1 = false;
    }
    DAT_180051c00 = uVar7;
    uVar10 = FUN_180031540((undefined *)0x0,pcVar20,param_3,param_4);
    if ((int)uVar10 == 0) {
      return 0x80004005;
    }
    if ((uVar7 - 1 & 0xfffffffb) != 0) {
      bVar3 = FUN_180031510(0);
      if (((int)CONCAT71(extraout_var_00,bVar3) != 0) ||
         (bVar3 = FUN_180031510(0xe), (int)CONCAT71(extraout_var_01,bVar3) != 0)) {
        aiStackX_8[0] = 0;
        SimSendMainWndMessage(0x552,0,aiStackX_8);
        if (aiStackX_8[0] != 0) {
          return 0x80004005;
        }
      }
      if (uVar7 == 0x20) goto LAB_1800107fd;
    }
    GRbkpinp();
    if ((uVar7 < 0x28) && ((0x8010000222U >> (uVar22 & 0x3f) & 1) != 0)) {
LAB_180010744:
      FUN_18000eeb0();
    }
    else if ((uVar7 == 0x1f) || (uVar7 == 0x22)) {
      if (((param_2 != (IMAGE_DOS_HEADER *)0x0) && (param_2->e_magic[0] != '\0')) &&
         ((iVar8 = _stricmp(param_2->e_magic,"parse solve"), iVar8 == 0 ||
          (iVar8 = _strnicmp(param_2->e_magic,"parse solve ",0xc), iVar8 == 0))))
      goto LAB_180010744;
    }
    else if ((uVar7 == 0x21) &&
            ((bVar3 = FUN_180031510(0), (int)CONCAT71(extraout_var_02,bVar3) != 0 ||
             (bVar3 = FUN_180031510(0xe), (int)CONCAT71(extraout_var_03,bVar3) != 0))))
    goto LAB_180010744;
    uVar10 = EXmsgbox();
    if ((int)uVar10 == 1) {
      iVar5 = -1;
    }
    else {
      if (uVar7 == 7) goto LAB_1800107fd;
      bVar3 = FUN_180031510(0);
      if (((((int)CONCAT71(extraout_var_04,bVar3) != 0) ||
           (bVar3 = FUN_180031510(0x19), (int)CONCAT71(extraout_var_05,bVar3) != 0)) ||
          (bVar3 = FUN_180031510(1), (int)CONCAT71(extraout_var_06,bVar3) != 0)) ||
         (bVar3 = FUN_180031510(0x2b), (int)CONCAT71(extraout_var_07,bVar3) != 0)) {
        iVar8 = FUN_180022a50(1,1,(char *)0x0,(uchar *)param_2);
        if (iVar8 == 0) {
          if ((uVar7 < 0x23) && ((0x6a0000000U >> (uVar22 & 0x3f) & 1) != 0)) goto LAB_1800107fd;
          GRsetgfl();
        }
        else {
          iVar5 = -1;
        }
      }
    }
  }
  else {
    iVar5 = -1;
  }
  if (uVar7 == 1) {
    GRinqdrs(0);
  }
  if ((iVar5 == -1) && ((0x27 < uVar7 || ((0x8680000000U >> (uVar22 & 0x3f) & 1) == 0)))) {
    if (bVar1) {
      *(int *)simulate_flag_exref = iVar4;
    }
    return 0x80004005;
  }
LAB_1800107fd:
  uVar22 = FUN_180015a10(uVar7,(uchar *)param_2);
  if (!bVar1) {
    return uVar22;
  }
  *(int *)simulate_flag_exref = iVar4;
  return uVar22;
}

/* RVA 0xd050 */
undefined8 FUN_18000d050(int param_1,longlong *param_2)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  AFX_MODULE_STATE *pAVar4;
  undefined7 extraout_var;
  ulonglong uVar5;
  undefined7 extraout_var_00;
  undefined8 uVar6;
  undefined1 local_res18 [16];
  AFX_MAINTAIN_STATE2 local_18 [16];
  
  pAVar4 = AfxGetModuleState();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_18,pAVar4);
  cVar1 = MMCheckWaitStruct();
  if (cVar1 == '\0') {
    SimReflect(1,0,"Unable to check out or validate license.");
    uVar6 = 0x80004005;
    goto LAB_18000d0f9;
  }
  uVar6 = 0;
  if (param_1 == 0) {
    FUN_1800040c0();
    goto LAB_18000d0f9;
  }
  if (DAT_180051c2c == 0) {
    if (param_2 == (longlong *)0x0) {
      uVar5 = FUN_180003920(local_res18);
      iVar3 = (int)uVar5;
      if (iVar3 != 0) goto LAB_18000d0e3;
    }
    bVar2 = FUN_180003a70(local_res18,param_2);
    iVar3 = (int)CONCAT71(extraout_var_00,bVar2);
  }
  else {
    DAT_180051c2c = 0;
    bVar2 = FUN_180003d80(local_res18,(char *)0x0);
    iVar3 = (int)CONCAT71(extraout_var,bVar2);
    if (iVar3 == 0) {
      uVar6 = 0x80004005;
      goto LAB_18000d0f9;
    }
  }
LAB_18000d0e3:
  if (iVar3 != 1) {
    uVar6 = 0x80004005;
  }
LAB_18000d0f9:
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_18);
  return uVar6;
}

/* RVA 0xd120 */
void SimDelStopPoint(int param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
                    /* 0xd120  81  SimDelStopPoint */
  lVar1 = FUN_1800213d0();
  uVar2 = FUN_1800209a0(lVar1,param_1);
  if ((int)uVar2 == -1) {
    return;
  }
  lVar1 = FUN_1800213d0();
  FUN_180020ec0(lVar1,1);
  return;
}

/* RVA 0xd160 */
void SimDetachNotify(int param_1,int param_2)

{
  longlong lVar1;
  longlong lVar2;
  
                    /* 0xd160  137  SimDetachNotify */
  if (param_1 == 0) {
    if (param_2 < 0) {
      return;
    }
    if (DAT_180051e3c <= param_2) {
      return;
    }
    lVar2 = (longlong)param_2 * 8;
    lVar1 = DAT_180051df0;
    if (*(void **)(lVar2 + DAT_180051df0) != (void *)0x0) {
      FUN_180001300(*(void **)(lVar2 + DAT_180051df0));
      *(undefined8 *)(lVar2 + DAT_180051df0) = 0;
      return;
    }
  }
  else if (param_1 == 1) {
    if (param_2 < 0) {
      return;
    }
    if (DAT_180051e38 <= param_2) {
      return;
    }
    lVar2 = (longlong)param_2 * 8;
    lVar1 = DAT_180051dd8;
    if (*(void **)(lVar2 + DAT_180051dd8) != (void *)0x0) {
      FUN_180001300(*(void **)(lVar2 + DAT_180051dd8));
      *(undefined8 *)(lVar2 + DAT_180051dd8) = 0;
      return;
    }
  }
  else if (param_1 == 2) {
    if (param_2 < 0) {
      return;
    }
    if (DAT_180051e40 <= param_2) {
      return;
    }
    lVar2 = (longlong)param_2 * 8;
    lVar1 = DAT_180051e08;
    if (*(void **)(lVar2 + DAT_180051e08) != (void *)0x0) {
      FUN_180001300(*(void **)(lVar2 + DAT_180051e08));
      *(undefined8 *)(lVar2 + DAT_180051e08) = 0;
      return;
    }
  }
  else {
    if (param_1 != 3) {
      return;
    }
    if (param_2 < 0) {
      return;
    }
    if (DAT_180051e44 <= param_2) {
      return;
    }
    lVar2 = (longlong)param_2 * 8;
    lVar1 = DAT_180051e20;
    if (*(void **)(lVar2 + DAT_180051e20) != (void *)0x0) {
      FUN_180001300(*(void **)(lVar2 + DAT_180051e20));
      lVar1 = DAT_180051e20;
    }
  }
  *(undefined8 *)(lVar2 + lVar1) = 0;
  return;
}

/* RVA 0xd2c0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SimDisplayReport(int param_1,char *param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  errno_t eVar4;
  int iVar5;
  undefined7 extraout_var;
  ulonglong uVar6;
  undefined1 *puVar7;
  char *pcVar8;
  uchar *puVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined1 auStackY_6d8 [32];
  char *local_6a8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_6a0 [8];
  int local_698;
  int local_694;
  FILE *local_690;
  FILE *local_688;
  uint local_680;
  undefined4 local_67c;
  undefined8 local_678;
  undefined8 local_670;
  undefined4 local_668;
  undefined8 local_664;
  undefined8 uStack_65c;
  undefined4 local_654;
  uchar local_648 [272];
  uchar local_538 [272];
  undefined1 local_428 [1024];
  ulonglong local_28;
  
                    /* 0xd2c0  145  SimDisplayReport */
  local_28 = DAT_1800516d8 ^ (ulonglong)auStackY_6d8;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6a8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_6a0);
  bVar1 = FUN_18002bdf0();
  if ((int)CONCAT71(extraout_var,bVar1) == 0) {
    GetEditorTempFileName(local_648);
    iVar2 = FUN_180022a50(0x13,1,(char *)0x2,local_648);
    if (iVar2 != 0) goto LAB_18000d5b7;
    iVar2 = 0;
    puVar9 = local_648;
  }
  else {
    pcVar8 = (char *)0x0;
    uVar10 = 1;
    uVar11 = 1;
    iVar2 = FUN_180022a50(0x13,1,(char *)0x1,(uchar *)0x0);
    if (iVar2 != 0) {
LAB_18000d5b7:
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_6a0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6a8);
      return 0x80004005;
    }
    if ((DAT_180052ec4 == 0) || (iVar2 = GRinqcnn(), iVar2 != 2)) {
      DAT_180051c00 = 4;
      FUN_180031540((undefined *)0x0,uVar10,uVar11,pcVar8);
      pcVar8 = (char *)0x0;
      iVar2 = FUN_180022a50(1,1,(char *)0x0,(uchar *)0x0);
      if (iVar2 != 0) goto LAB_18000d5b7;
      local_678 = 1;
      local_664 = 0;
      uStack_65c = 0;
      local_654 = 0;
      local_680 = 4;
      local_670 = 0;
      local_67c = 1;
      local_668 = 0;
      FUN_180015c10(&local_680);
    }
    iVar2 = 0;
    FUN_180008f80(local_538,"%s.ia1",APtmpfil_exref,pcVar8);
    local_698 = param_1;
    iVar3 = FUN_180017fe0(&local_698,param_2,(FILE *)(ulonglong)param_3,pcVar8);
    local_694 = iVar3;
    if (iVar3 == 0) goto LAB_18000d61c;
    if (local_698 == 0xd) {
      FUN_180008f80(local_538,"%s.rp1",APtmpfil_exref,pcVar8);
      FUN_180008f80(local_648,"%s.rp2",APtmpfil_exref,pcVar8);
      eVar4 = fopen_s(&local_688,(char *)local_538,"a");
      if (eVar4 == 0) {
        eVar4 = fopen_s(&local_690,(char *)local_648,"r");
        if (eVar4 == 0) {
          uVar6 = fread_s(local_428,0x400,1,1,local_690);
          iVar5 = (int)uVar6;
          while (0 < iVar5) {
            fwrite(local_428,1,uVar6 & 0xffffffff,local_688);
            uVar6 = fread_s(local_428,0x400,1,1,local_690);
            iVar5 = (int)uVar6;
          }
          fclose(local_688);
        }
        else {
          local_690 = local_688;
        }
        fclose(local_690);
      }
    }
    else if (local_698 == 0xe) {
      FUN_180008f80(local_538,"%s.rp1",APtmpfil_exref,pcVar8);
    }
    if ((iVar3 < 1) || (iVar3 = FUN_180026510((char *)0x0,(char *)local_538), iVar3 == -1))
    goto LAB_18000d61c;
    iVar3 = SBlocalhost();
    if (iVar3 == 0) {
      GetEditorTempFileName(local_648);
      puVar7 = (undefined1 *)FUN_18001a130();
      iVar3 = FUN_18002b2c0((char *)local_648,local_538,puVar7);
      if (iVar3 != 0) {
        pcVar8 = (char *)GetSorResStringEx(0x1cc);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6a8,
                   pcVar8);
        MMAfxMessageBox(local_6a8,0x30,-1,0);
        goto LAB_18000d5b7;
      }
      puVar9 = local_648;
    }
    else {
      puVar9 = local_538;
      iVar2 = 1;
    }
  }
  FUN_180009bc0((LPCSTR)puVar9,iVar2,0,(LPCSTR)0x0);
LAB_18000d61c:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_6a0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6a8);
  return 0;
}

/* RVA 0xd680 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 SimEOCommand(char *param_1)

{
  char cVar1;
  int iVar2;
  DWORD DVar3;
  BOOL BVar4;
  AFX_MODULE_STATE *pAVar5;
  CWinThread *pCVar6;
  longlong lVar7;
  char *lParam;
  HGLOBAL pvVar8;
  undefined8 uVar9;
  longlong lVar10;
  HWND hWnd;
  undefined4 uVar11;
  undefined1 auStackY_98 [32];
  HANDLE local_68;
  AFX_MAINTAIN_STATE2 local_60 [16];
  tagMSG local_50;
  char local_20 [4];
  char local_1c [2];
  char local_1a;
  ulonglong local_18;
  
                    /* 0xd680  142  SimEOCommand */
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_98;
  pAVar5 = AfxGetModuleState();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_60,pAVar5);
  local_20[0] = s_OPENDB_180040bec[0];
  local_20[1] = s_OPENDB_180040bec[1];
  local_20[2] = s_OPENDB_180040bec[2];
  local_20[3] = s_OPENDB_180040bec[3];
  uVar11 = 0;
  local_1c[0] = s_OPENDB_180040bec[4];
  local_1c[1] = s_OPENDB_180040bec[5];
  local_1a = s_OPENDB_180040bec[6];
  iVar2 = _strnicmp(param_1,local_20,6);
  if (iVar2 == 0) {
    pCVar6 = AfxGetThread();
    if ((pCVar6 != (CWinThread *)0x0) &&
       (lVar7 = (**(code **)(*(longlong *)pCVar6 + 0xf8))(pCVar6), lVar7 != 0)) {
      lParam = _strdup(param_1 + 7);
      PostMessageA(*(HWND *)(lVar7 + 0x40),0x545,0,(LPARAM)lParam);
    }
  }
  else {
    iVar2 = GRinqautorun();
    if (iVar2 != 1) {
      SimSendMainWndMessage(0x539,0,0);
    }
    DVar3 = GetCurrentThreadId();
    if (DVar3 == DAT_18004f724) {
      lVar7 = -1;
      do {
        lVar10 = lVar7;
        lVar7 = lVar10 + 1;
      } while (param_1[lVar7] != '\0');
      pvVar8 = GlobalAlloc(0,lVar10 + 2);
      lVar7 = (longlong)pvVar8 - (longlong)param_1;
      do {
        cVar1 = *param_1;
        param_1[lVar7] = cVar1;
        param_1 = param_1 + 1;
      } while (cVar1 != '\0');
      uVar9 = FUN_180015fb0();
      if ((int)uVar9 == 0) {
        pCVar6 = AfxGetThread();
        if ((pCVar6 == (CWinThread *)0x0) ||
           (lVar7 = (**(code **)(*(longlong *)pCVar6 + 0xf8))(pCVar6), lVar7 == 0)) {
          hWnd = (HWND)0x0;
        }
        else {
          hWnd = *(HWND *)(lVar7 + 0x40);
        }
        local_68 = (HANDLE)GetGlobalPointer("DCOM_MSHL_EVENT");
        WaitForSingleObject(local_68,0xffffffff);
        ResetEvent(local_68);
        SimSendMainWndMessage(0x544,pvVar8,1);
        DVar3 = MsgWaitForMultipleObjectsEx(1,&local_68,1000,0x40,0);
        while (DVar3 != 0) {
          BVar4 = GetMessageA(&local_50,hWnd,0,0);
          if (BVar4 == -1) goto LAB_18000d8bb;
          TranslateMessage(&local_50);
          DispatchMessageA(&local_50);
          DVar3 = MsgWaitForMultipleObjectsEx(1,&local_68,1000,0x40,0);
        }
        uVar11 = 1;
      }
      else {
        FUN_1800074b0(0x544,pvVar8,1);
      }
    }
    else {
      Ordinal_73(param_1,0,DAT_180051c18 != 0);
      iVar2 = Ordinal_98();
      uVar11 = 0;
      if (iVar2 != 0) {
        uVar11 = 1;
      }
    }
  }
LAB_18000d8bb:
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_60);
  return uVar11;
}

/* RVA 0xd8f0 */
void FUN_18000d8f0(void)

{
  int *in_R8;
  char *in_R9;
  
  SimMain((char *)0x1f,(IMAGE_DOS_HEADER *)"PARSE pause",in_R8,in_R9);
  return;
}

/* RVA 0xd910 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 SimEORun(char *param_1)

{
  char *pcVar1;
  code cVar2;
  char cVar3;
  bool bVar4;
  longlong *plVar5;
  int iVar6;
  int iVar7;
  longlong *plVar8;
  BSTR pOVar9;
  IAtlStringMgr *pIVar10;
  ulonglong uVar11;
  char *pcVar12;
  undefined1 *puVar13;
  longlong lVar14;
  undefined4 uVar15;
  int *piVar16;
  _union_2707 *p_Var17;
  undefined4 uVar18;
  longlong lVar19;
  undefined1 auStackY_248 [32];
  IMAGE_DOS_HEADER *local_218;
  char *local_210;
  longlong *local_208;
  longlong *local_200;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_1f8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_1f0 [8];
  longlong *local_1e8;
  longlong *local_1e0;
  _union_2707 local_1d8;
  _union_2707 local_1b8;
  char *local_198;
  int local_188;
  ULONG UStack_184;
  undefined4 uStack_180;
  undefined4 uStack_17c;
  undefined8 local_178;
  _union_2707 local_168;
  _union_2707 local_150;
  char local_138 [8];
  char local_130 [4];
  char acStack_12c [244];
  ulonglong local_38;
  
                    /* 0xd910  172  SimEORun */
  local_38 = DAT_1800516d8 ^ (ulonglong)auStackY_248;
  uVar15 = 0;
  bVar4 = false;
  local_1e0 = (longlong *)0x0;
  local_208 = (longlong *)0x0;
  local_198 = param_1;
  plVar8 = (longlong *)GetGlobalPointer("HappNode");
  if (plVar8 == (longlong *)0x0) goto LAB_18000e055;
  (**(code **)(*plVar8 + 8))(plVar8);
  (**(code **)(*plVar8 + 0x90))();
  plVar5 = local_1e0;
  uVar15 = 0;
  if (local_1e0 != (longlong *)0x0) {
    iVar6 = MultiByteToWideChar(0,0,"Data",-1,(LPWSTR)0x0,0);
    pOVar9 = SysAllocStringLen((OLECHAR *)0x0,iVar6 - 1);
    if ((pOVar9 != (BSTR)0x0) &&
       (iVar7 = MultiByteToWideChar(0,0,"Data",-1,pOVar9,iVar6), iVar7 != iVar6)) {
LAB_18000e0be:
      SysFreeString(pOVar9);
LAB_18000e0c4:
                    /* WARNING: Subroutine does not return */
      FUN_180001380(-0x7ff8fff2);
    }
    if (pOVar9 == (BSTR)0x0) goto LAB_18000e0c4;
    (**(code **)(*plVar5 + 0x110))(plVar5,pOVar9,&local_208);
    SysFreeString(pOVar9);
    if (local_208 == (longlong *)0x0) goto LAB_18000e04c;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_218);
    local_138[0] = '\0';
    local_138[1] = '\0';
    memset(local_138 + 2,0,0xfe);
    FUN_180008f80(local_138,&DAT_180040c80,"solve /mode #",(ulonglong)simrunMode);
    if (*simrunScope_exref != (code)0x0) {
      pcVar1 = (char *)((longlong)&local_150.n2.n3.brecVal.pRecInfo + 7);
      do {
        pcVar12 = pcVar1;
        pcVar1 = pcVar12 + 1;
      } while (pcVar12[1] != '\0');
      *(undefined8 *)(pcVar12 + 1) = s__plant_180040c88._0_8_;
      pcVar12[9] = s__plant_180040c88[8];
      puVar13 = (undefined1 *)((longlong)&local_150.n2.n3.brecVal.pRecInfo + 7);
      do {
        pcVar1 = puVar13 + 1;
        puVar13 = puVar13 + 1;
      } while (*pcVar1 != '\0');
      lVar14 = 0;
      do {
        cVar2 = simrunScope_exref[lVar14];
        puVar13[lVar14] = cVar2;
        lVar14 = lVar14 + 1;
      } while (cVar2 != (code)0x0);
    }
    if (simrunObject != '\0') {
      pcVar1 = (char *)((longlong)&local_150.n2.n3.brecVal.pRecInfo + 7);
      do {
        pcVar12 = pcVar1;
        pcVar1 = pcVar12 + 1;
      } while (pcVar12[1] != '\0');
      *(undefined8 *)(pcVar12 + 1) = s__objective_180040c98._0_8_;
      *(undefined4 *)(pcVar12 + 9) = s__objective_180040c98._8_4_;
      pcVar12[0xd] = s__objective_180040c98[0xc];
      puVar13 = (undefined1 *)((longlong)&local_150.n2.n3.brecVal.pRecInfo + 7);
      do {
        pcVar1 = puVar13 + 1;
        puVar13 = puVar13 + 1;
      } while (*pcVar1 != '\0');
      lVar14 = 0;
      do {
        cVar3 = (&simrunObject)[lVar14];
        puVar13[lVar14] = cVar3;
        lVar14 = lVar14 + 1;
      } while (cVar3 != '\0');
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_218,"%s",
               local_138);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_210);
    plVar5 = local_208;
    local_1e8 = (longlong *)0x0;
    iVar6 = MultiByteToWideChar(0,0,"Convergence\\EO-Conv-Options\\Input\\SOLVER",-1,(LPWSTR)0x0,0);
    pOVar9 = SysAllocStringLen((OLECHAR *)0x0,iVar6 - 1);
    if ((pOVar9 != (BSTR)0x0) &&
       (iVar7 = MultiByteToWideChar(0,0,"Convergence\\EO-Conv-Options\\Input\\SOLVER",-1,pOVar9,
                                    iVar6), iVar7 != iVar6)) goto LAB_18000e0be;
    if (pOVar9 == (BSTR)0x0) goto LAB_18000e0c4;
    (**(code **)(*plVar5 + 0x110))(plVar5,pOVar9,&local_1e8);
    SysFreeString(pOVar9);
    VariantInit((VARIANTARG *)&local_168.n2);
    VariantInit((VARIANTARG *)&local_1d8.n2);
    if (local_1e8 != (longlong *)0x0) {
      local_1b8._0_4_ = local_168._0_4_;
      local_1b8.decVal.Hi32 = local_168.decVal.Hi32;
      local_1b8._8_4_ = local_168._8_4_;
      local_1b8._12_4_ = local_168._12_4_;
      local_1b8._16_8_ = local_168._16_8_;
      iVar6 = (**(code **)(*local_1e8 + 0x98))(local_1e8,0,&local_1b8,&local_1d8);
      if (-1 < iVar6) {
        if (local_1d8.n2.vt == 8) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_210,
                     (wchar_t *)CONCAT44(local_1d8._12_4_,local_1d8._8_4_));
        }
        VariantClear((VARIANTARG *)&local_1d8.n2);
      }
    }
    if ((((int)simrunMode < 2) &&
        (iVar6 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                           ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_210,"NSOLVE"), iVar6 != 0)) &&
       (iVar6 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_210,"XSLP"), iVar6 != 0)) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1f0);
      plVar5 = local_208;
      local_200 = (longlong *)0x0;
      iVar6 = MultiByteToWideChar(0,0,"Convergence\\EO-Conv-Options\\Input\\HOMOTOPY",-1,(LPWSTR)0x0
                                  ,0);
      pOVar9 = SysAllocStringLen((OLECHAR *)0x0,iVar6 - 1);
      if ((pOVar9 != (BSTR)0x0) &&
         (iVar7 = MultiByteToWideChar(0,0,"Convergence\\EO-Conv-Options\\Input\\HOMOTOPY",-1,pOVar9,
                                      iVar6), iVar7 != iVar6)) {
LAB_18000e0a7:
        SysFreeString(pOVar9);
LAB_18000e0b0:
                    /* WARNING: Subroutine does not return */
        FUN_180001380(-0x7ff8fff2);
      }
      if (pOVar9 == (BSTR)0x0) goto LAB_18000e0b0;
      (**(code **)(*plVar5 + 0x110))(plVar5,pOVar9,&local_200);
      SysFreeString(pOVar9);
      plVar5 = local_208;
      if (local_200 == (longlong *)0x0) {
        iVar6 = MultiByteToWideChar(0,0,"Data\\Convergence\\EO-Conv-Options\\Input\\HOMOTOPY",-1,
                                    (LPWSTR)0x0,0);
        pOVar9 = SysAllocStringLen((OLECHAR *)0x0,iVar6 - 1);
        if ((pOVar9 != (BSTR)0x0) &&
           (iVar7 = MultiByteToWideChar(0,0,"Data\\Convergence\\EO-Conv-Options\\Input\\HOMOTOPY",-1
                                        ,pOVar9,iVar6), iVar7 != iVar6)) goto LAB_18000e0a7;
        if (pOVar9 == (BSTR)0x0) goto LAB_18000e0b0;
        (**(code **)(*plVar5 + 0x110))(plVar5,pOVar9,&local_200);
        SysFreeString(pOVar9);
      }
      VariantInit((VARIANTARG *)&local_150.n2);
      VariantInit((VARIANTARG *)&local_1b8.n2);
      if (local_200 != (longlong *)0x0) {
        local_188 = local_150._0_4_;
        UStack_184 = local_150.decVal.Hi32;
        uStack_180 = local_150._8_4_;
        uStack_17c = local_150._12_4_;
        local_178 = local_150._16_8_;
        iVar6 = (**(code **)(*local_200 + 0x98))(local_200,0,&local_188,&local_1b8);
        if (-1 < iVar6) {
          if (local_1b8.n2.vt == 8) {
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      (local_1f0,(wchar_t *)CONCAT44(local_1b8._12_4_,local_1b8._8_4_));
            iVar6 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                              (local_1f0,"YES");
            if (iVar6 == 0) {
              pIVar10 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                        GetManager((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                   &local_210);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1f8,pIVar10);
              lVar14 = -1;
              do {
                lVar19 = lVar14 + 1;
                pcVar1 = &DAT_180040d4d + lVar14;
                lVar14 = lVar19;
              } while (*pcVar1 != '\0');
              ATL::CSimpleStringT<char,1>::Concatenate
                        ((CSimpleStringT<char,1> *)local_1f8,"HOMO_",(int)lVar19,local_210,
                         *(int *)(local_210 + -0x10));
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_210
                         ,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                           *)local_1f8);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1f8);
            }
          }
          VariantClear((VARIANTARG *)&local_1b8.n2);
        }
        (**(code **)(*local_200 + 0x10))();
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1f0);
    }
    if (*(int *)(local_210 + -0x10) != 0) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_218,
                 " /solver ");
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_218,
                 (CSimpleStringT<char,1> *)&local_210);
    }
    pcVar1 = local_198;
    if (local_198 != (char *)0x0) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_218," ");
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_218,pcVar1)
      ;
    }
    if (DAT_180051c1c != '\0') {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_218,
                 " /presolve ");
    }
    if (DAT_180051c1d != '\0') {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_218,
                 " /postsolve ");
    }
    p_Var17 = &local_1d8;
    piVar16 = &local_188;
    local_188 = local_168._0_4_;
    UStack_184 = local_168.decVal.Hi32;
    uStack_180 = local_168._8_4_;
    uStack_17c = local_168._12_4_;
    local_178 = local_168._16_8_;
    (**(code **)(*local_208 + 0x98))(local_208,0xc);
    uVar18 = 0;
    if (local_1d8.n2.vt == 3) {
      uVar18 = local_1d8._8_4_;
    }
    VariantClear((VARIANTARG *)&local_1d8.n2);
    uVar15 = 1;
    if ((((uint)uVar18 >> 0x14 & 1) != 0) || ((uVar18 & 0xfc000) == 0)) {
      bVar4 = true;
    }
    iVar6 = GRinqrsl();
    if ((iVar6 == 0) ||
       (((iVar6 = GRinqpgc(), iVar6 != 0 && (iVar6 = GRinqnec(), iVar6 != 0)) ||
        (iVar6 = GRinqgpd(), iVar6 == 0)))) {
      iVar6 = GRinqcmp();
      if (((iVar6 != 0) || (*(int *)runanyway_exref != 0)) || (*(int *)bestinput_exref != 0))
      goto LAB_18000e013;
    }
    else {
      iVar6 = GRinqpgc();
      if ((iVar6 != 0) || (bVar4)) {
LAB_18000e013:
        uVar11 = SimMain((char *)0x22,local_218,piVar16,(char *)p_Var17);
        uVar15 = (undefined4)uVar11;
      }
      else {
        uVar11 = SimMain((char *)0x1f,local_218,piVar16,(char *)p_Var17);
        uVar15 = (undefined4)uVar11;
      }
    }
    if (local_1e8 != (longlong *)0x0) {
      (**(code **)(*local_1e8 + 0x10))();
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_210);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_218);
  }
LAB_18000e04c:
  (**(code **)(*plVar8 + 0x10))(plVar8);
LAB_18000e055:
  if (local_208 != (longlong *)0x0) {
    (**(code **)(*local_208 + 0x10))();
  }
  if (local_1e0 != (longlong *)0x0) {
    (**(code **)(*local_1e0 + 0x10))();
  }
  return uVar15;
}

/* RVA 0xe0d0 */
void FUN_18000e0d0(void)

{
  int *in_R8;
  char *in_R9;
  
  SimMain((char *)0x1f,(IMAGE_DOS_HEADER *)"PARSE step",in_R8,in_R9);
  return;
}

/* RVA 0xe0f0 */
void SimEoImportAfterInit(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  LPCSTR pCVar4;
  BSTR lpWideCharStr;
  BSTR lpWideCharStr_00;
  
                    /* 0xe0f0  171  SimEoImportAfterInit */
  uVar1 = SBlocalhost();
  pCVar4 = (LPCSTR)GetSorResStringEx(0xfa1);
  lpWideCharStr_00 = (BSTR)0x0;
  if (pCVar4 == (LPCSTR)0x0) {
    lpWideCharStr = (BSTR)0x0;
  }
  else {
    iVar2 = MultiByteToWideChar(0,0,pCVar4,-1,(LPWSTR)0x0,0);
    lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,iVar2 - 1);
    if ((lpWideCharStr != (BSTR)0x0) &&
       (iVar3 = MultiByteToWideChar(0,0,pCVar4,-1,lpWideCharStr,iVar2), iVar3 != iVar2)) {
      SysFreeString(lpWideCharStr);
      goto LAB_18000e250;
    }
    if (lpWideCharStr == (BSTR)0x0) goto LAB_18000e250;
  }
  pCVar4 = (LPCSTR)GetSorResStringEx();
  if (pCVar4 == (LPCSTR)0x0) {
LAB_18000e1fa:
    FUN_180009220(0,lpWideCharStr_00,lpWideCharStr,uVar1,1,1);
    SysFreeString(lpWideCharStr_00);
                    /* WARNING: Could not recover jumptable at 0x00018000e240. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    SysFreeString(lpWideCharStr);
    return;
  }
  iVar2 = MultiByteToWideChar(0,0,pCVar4,-1,(LPWSTR)0x0,0);
  lpWideCharStr_00 = SysAllocStringLen((OLECHAR *)0x0,iVar2 - 1);
  if ((lpWideCharStr_00 == (BSTR)0x0) ||
     (iVar3 = MultiByteToWideChar(0,0,pCVar4,-1,lpWideCharStr_00,iVar2), iVar3 == iVar2)) {
    if (lpWideCharStr_00 != (BSTR)0x0) goto LAB_18000e1fa;
  }
  else {
    SysFreeString(lpWideCharStr_00);
  }
LAB_18000e250:
                    /* WARNING: Subroutine does not return */
  FUN_180001380(-0x7ff8fff2);
}

/* RVA 0xe260 */
undefined8 SimExit(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4)

{
  LPSTREAM pStm;
  int iVar1;
  char *pcVar2;
  undefined8 uVar3;
  
                    /* 0xe260  42  SimExit */
  SimClearControlPanelMessage();
  Ordinal_157();
  FUN_18000f830();
  iVar1 = GRinqcnn();
  if (iVar1 != 0) {
    FUN_18002a3a0(param_1,param_2,param_3,param_4);
  }
  FUN_18002f8b0();
  FUN_1800261d0((char *)APtmpfil_exref);
  iVar1 = GRinqsme();
  if (iVar1 == 0) {
    pcVar2 = (char *)GRemrbkp();
    remove(pcVar2);
    pcVar2 = (char *)GRemrbka();
    remove(pcVar2);
    pcVar2 = (char *)GRemrprp();
    remove(pcVar2);
    remove("$backup.bkp");
    remove("$backup.aprbkp");
    remove("$backup.apmbd");
    uVar3 = GRemrbkpfull();
    GRDeleteEmergencyFiles(0,uVar3);
    remove((char *)APtmpfil_exref);
  }
  remove("apcape.mmf");
  pStm = DAT_180051bb8;
  if (DAT_180051bb0 != (longlong *)0x0) {
    if (DAT_180051bb8 != (LPSTREAM)0x0) {
      (*DAT_180051bb8->lpVtbl->Seek)(DAT_180051bb8,(LARGE_INTEGER)0x0,0,(ULARGE_INTEGER *)0x0);
      CoReleaseMarshalData(pStm);
      (*pStm->lpVtbl->Release)(pStm);
      DAT_180051bb8 = (LPSTREAM)0x0;
    }
    (**(code **)(*DAT_180051bb0 + 0x10))();
    DAT_180051bb0 = (longlong *)0x0;
  }
  return 0;
}

/* RVA 0xe390 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 SimExportAPPDF(char *param_1,undefined8 param_2,undefined8 param_3,undefined *param_4)

{
  char cVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  longlong lVar6;
  undefined1 *puVar7;
  undefined4 *puVar8;
  char *pcVar9;
  char *pcVar10;
  longlong lVar11;
  longlong lVar12;
  undefined1 auStack_388 [32];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_368 [16];
  char local_358 [271];
  undefined4 uStack_249;
  undefined1 local_244 [268];
  char local_138 [272];
  ulonglong local_28;
  
                    /* 0xe390  96  SimExportAPPDF */
  local_28 = DAT_1800516d8 ^ (ulonglong)auStack_388;
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    return 1;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_368);
  if ((((DAT_180052ec4 == 0) || (iVar4 = GRinqcnn(), iVar4 == 0)) ||
      (iVar4 = GRinqcnn(), iVar4 == 1)) || (iVar4 = GRinqcannedpdf(), iVar4 != 0)) {
    uVar5 = 2;
  }
  else {
    iVar4 = MVGetProductCode();
    pcVar9 = "%sdyn.aprpdf";
    if (iVar4 != 2) {
      pcVar9 = "%sdyn.appdf";
    }
    FUN_180008f80(local_358,pcVar9,param_1,param_4);
    pcVar9 = strrchr(local_358,0x5c);
    uVar5 = 0;
    if (pcVar9 == (char *)0x0) {
      lVar11 = 0;
      do {
        pcVar9 = local_358 + lVar11;
        local_138[lVar11] = *pcVar9;
        lVar11 = lVar11 + 1;
      } while (*pcVar9 != '\0');
      pcVar9 = (char *)0x0;
    }
    else {
      pcVar10 = pcVar9 + 1;
      lVar11 = -(longlong)pcVar10;
      do {
        cVar1 = *pcVar10;
        pcVar10[(longlong)(local_138 + lVar11)] = cVar1;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      *pcVar9 = '\0';
      pcVar9 = local_358;
    }
    iVar4 = FUN_180026510(pcVar9,local_138);
    if (iVar4 != -1) {
      FUN_180025fb0(pcVar9,local_138);
    }
    lVar11 = -1;
    lVar12 = 0;
    bVar2 = false;
    if (open_path_exref != (code *)0x0) {
      lVar12 = -1;
      do {
        lVar6 = lVar12;
        lVar12 = lVar6 + 1;
      } while (open_path_exref[lVar6 + 1] != (code)0x0);
      lVar12 = lVar6 + 2;
      bVar2 = false;
      if (open_path_exref[lVar6] != (code)0x5c) {
        bVar2 = true;
      }
    }
    lVar6 = GRinqfnm();
    do {
      lVar11 = lVar11 + 1;
    } while (*(char *)(lVar6 + lVar11) != '\0');
    puVar7 = operator_new__(lVar12 + 1 + lVar11);
    *puVar7 = 0;
    if (open_path_exref == (code *)0x0) {
      pcVar9 = (char *)GRinqfnm();
      lVar11 = (longlong)puVar7 - (longlong)pcVar9;
      do {
        cVar1 = *pcVar9;
        pcVar9[lVar11] = cVar1;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
    }
    else {
      param_4 = (undefined *)GRinqfnm();
      if (bVar2) {
        FUN_180008f80(puVar7,"%s\\%s",open_path_exref,param_4);
      }
      else {
        FUN_180008f80(puVar7,&DAT_18003f9b0,open_path_exref,param_4);
      }
    }
    pcVar10 = "%sdyn";
    pcVar9 = param_1;
    FUN_180008f80(local_358,"%sdyn",param_1,param_4);
    GRsetfnm(local_358);
    iVar4 = SimGetReportSummary();
    if (iVar4 == 0) {
      FUN_180027cb0(local_358);
      FUN_1800325b0(local_358,pcVar10,pcVar9,param_4);
      iVar4 = SBlocalhost();
      if (iVar4 == 0) {
        lVar11 = 0x110 - (longlong)param_1;
        do {
          cVar1 = *param_1;
          param_1[(longlong)(local_358 + lVar11)] = cVar1;
          param_1 = param_1 + 1;
        } while (cVar1 != '\0');
        puVar3 = &uStack_249;
        do {
          puVar8 = puVar3;
          puVar3 = (undefined4 *)((longlong)puVar8 + 1);
        } while (*(char *)((longlong)puVar8 + 1) != '\0');
        *(undefined4 *)((longlong)puVar8 + 1) = DAT_180040a80;
        *(undefined1 *)((longlong)puVar8 + 5) = DAT_180040a84;
        pcVar9 = strrchr((char *)((longlong)&uStack_249 + 1),0x5c);
        if (pcVar9 == (char *)0x0) {
          pcVar9 = (char *)((longlong)&uStack_249 + 1);
        }
        else {
          pcVar9 = pcVar9 + 1;
        }
        FUN_180025fb0((char *)0x0,pcVar9);
        pcVar10 = (char *)FUN_18001a130();
        FUN_18002b360((char *)((longlong)&uStack_249 + 1),pcVar9,pcVar10);
      }
      SimGetSummaryHeader();
      GRsetfnm(puVar7);
      FUN_180001300(puVar7);
    }
    else {
      uVar5 = 3;
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_368);
  return uVar5;
}

