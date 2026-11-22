/* RVA 0x2c9d0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HRESULT FUN_18002c9d0(LPVOID *param_1,LPCSTR param_2)

{
  bool bVar1;
  HRESULT HVar2;
  uint uVar3;
  int iVar4;
  DWORD DVar5;
  char *pcVar6;
  uchar *puVar7;
  CWinThread *pCVar8;
  CWnd *pCVar9;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar10;
  HANDLE hObject;
  LPCSTR lpString2;
  undefined1 auStackY_798 [32];
  char *local_758;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_750 [8];
  char local_748 [272];
  uchar local_638 [272];
  CHAR local_528 [1008];
  char local_138 [272];
  ulonglong local_28;
  
  local_28 = DAT_180052888 ^ (ulonglong)auStackY_798;
  OleInitialize((LPVOID)0x0);
  bVar1 = true;
  HVar2 = CoCreateInstance((IID *)&DAT_180042518,(LPUNKNOWN)0x0,1,(IID *)&DAT_1800424d8,param_1);
  if (HVar2 < 0) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_758);
    pcVar6 = (char *)GetSorResStringEx(0x584);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_758,pcVar6);
    MMAfxMessageBox(local_758,0,-1,0);
  }
  else {
    if (*(int *)(DAT_1800540b0 + -0x10) != 0) {
      return HVar2;
    }
    uVar3 = lstrlenA(param_2);
    if (0x103 < uVar3) {
      FUN_180001ce0(local_528,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\ApwnShellIP\\CompoundFile.cpp",0xba);
      LogMessage(local_528,2,1);
    }
    lpString2 = param_2 + 1;
    if (*param_2 != '\"') {
      lpString2 = param_2;
    }
    lstrcpynA((LPSTR)local_638,lpString2,0x104);
    puVar7 = _mbsrchr(local_638,0x22);
    if (puVar7 != (uchar *)0x0) {
      *puVar7 = '\0';
    }
    AfxFullPath(local_748,(char *)local_638);
    pCVar8 = AfxGetThread();
    pCVar9 = (CWnd *)0x0;
    if (pCVar8 != (CWinThread *)0x0) {
      pCVar9 = (CWnd *)(**(code **)(*(longlong *)pCVar8 + 0xf8))(pCVar8);
    }
    iVar4 = AfxResolveShortcut(pCVar9,local_748,local_138,0x104);
    if (iVar4 != 0) {
      lstrcpyA(local_748,local_138);
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_758,local_748
              );
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_758,'\\');
    pCVar10 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_758
                         ,(int)local_750);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_758,pCVar10);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_750);
    DVar5 = GetFileAttributesA(local_758);
    if ((DVar5 & 0x10) != 0) {
      iVar4 = _access(local_758,2);
      if (iVar4 == 0) {
        GetTempFileNameA(local_758,"_",0,local_528);
        hObject = CreateFileA(local_528,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,0x100,(HANDLE)0x0)
        ;
        if (hObject == (HANDLE)0xffffffffffffffff) {
          CloseHandle((HANDLE)0xffffffffffffffff);
          DeleteFileA(local_528);
        }
        else {
          CloseHandle(hObject);
          DeleteFileA(local_528);
          bVar1 = false;
        }
      }
      if (bVar1) {
        GetCurrentDirectoryA(0x104,local_528);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_1800540b0,
                   local_528);
        goto LAB_18002cc83;
      }
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_1800540b0,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               &local_758);
  }
LAB_18002cc83:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_758);
  return HVar2;
}

/* RVA 0x2ccc0 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18002ccc0(IUnknown *param_1,char *param_2,void **param_3)

{
  uchar (*pauVar1) [8];
  int *piVar2;
  undefined8 **ppuVar3;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar4;
  _func_5157 *p_Var5;
  _func_5158 *p_Var6;
  uchar auVar7 [8];
  IUnknownVtbl *pIVar8;
  _func_5156 *p_Var9;
  code *pcVar10;
  void *pvVar11;
  IUnknown *pIVar12;
  longlong *plVar13;
  bool bVar14;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar15;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar16;
  LPCSTR pCVar17;
  LPCSTR pCVar18;
  undefined8 uVar19;
  SAFEARRAY *psa;
  HRESULT HVar20;
  ULONG UVar21;
  int iVar22;
  int iVar23;
  longlong lVar25;
  longlong lVar24;
  undefined8 uVar26;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar27;
  undefined8 *puVar28;
  BSTR pOVar29;
  undefined8 *puVar30;
  undefined8 *puVar31;
  IModelLibraryManager *pIVar32;
  __time64_t _Var33;
  BSTR pOVar34;
  undefined8 **ppuVar35;
  ulonglong uVar36;
  int iVar37;
  IID *riid;
  uchar auVar38 [8];
  undefined1 *puVar39;
  undefined1 *puVar40;
  undefined1 *puVar41;
  char *pcVar42;
  void **ppvObject;
  uint uVar43;
  undefined1 auStack_5a8 [64];
  int local_568 [2];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_560;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCStack_558;
  longlong local_550;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_548;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCStack_540;
  longlong local_538;
  uint local_530;
  short local_52c;
  uchar local_528 [8];
  LPCSTR local_520;
  longlong *local_518;
  undefined2 local_510;
  LONG local_50c;
  LONG local_508 [2];
  undefined8 local_500;
  IUnknown *local_4f8;
  LPCSTR local_4f0;
  IUnknown *local_4e8;
  LPCSTR local_4e0;
  uchar local_4d8 [8];
  LPCSTR local_4d0;
  char *local_4c8;
  char local_4c0 [8];
  undefined8 *local_4b8;
  undefined8 *local_4b0;
  undefined8 *local_4a8;
  undefined8 local_4a0;
  LPCSTR local_498;
  BSTR local_490;
  BSTR local_488;
  undefined8 local_480;
  IUnknown *local_478;
  undefined8 **local_470;
  int local_468 [4];
  LPCSTR local_458 [2];
  longlong *local_448;
  undefined8 *local_440;
  undefined8 *local_438;
  undefined8 **local_430;
  SAFEARRAY *local_428;
  uchar local_420 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_418 [8];
  longlong *local_410;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_408 [8];
  undefined8 *local_400;
  undefined8 **local_3f8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_3f0 [8];
  undefined8 *local_3e8;
  longlong *local_3e0;
  uchar local_3d8 [8];
  undefined8 *local_3d0;
  undefined8 *local_3c8;
  undefined8 *local_3c0;
  undefined8 **local_3b8;
  undefined8 *local_3b0;
  undefined8 local_3a8 [3];
  undefined8 local_390 [3];
  undefined1 local_378 [20];
  int local_364;
  char local_348 [256];
  char local_248 [256];
  undefined1 local_148 [256];
  ulonglong local_48;
  
  local_48 = DAT_180052888 ^ (ulonglong)local_568;
  local_530 = 0;
  local_4f8 = param_1;
  local_478 = param_1;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4c8,
             "ACM_Models\\");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_480,
             "ACM_EditedModels\\");
  local_428 = (SAFEARRAY *)0x0;
  HVar20 = (*param_1->lpVtbl[10].QueryInterface)(param_1,(IID *)&local_428,param_3);
  if (HVar20 < 0) {
    _com_issue_errorex(HVar20,param_1,(_GUID *)&DAT_1800424d8);
  }
  psa = local_428;
  local_508[0] = 0;
  SafeArrayGetUBound(local_428,1,local_508);
  SafeArrayLock(psa);
  puVar41 = auStack_5a8;
  local_50c = 0;
  puVar40 = auStack_5a8;
  uVar43 = 0;
  if (-1 < local_508[0]) {
    uVar43 = local_530;
    do {
      local_4e8 = (IUnknown *)0x0;
      *(undefined8 *)(puVar41 + -8) = 0x18002cdbb;
      SafeArrayGetElement(psa,&local_50c,&local_4e8);
      pIVar12 = local_4e8;
      if (local_4e8 != (IUnknown *)0x0) {
        local_420[0] = '\0';
        local_420[1] = '\0';
        local_420[2] = '\0';
        local_420[3] = '\0';
        local_420[4] = '\0';
        local_420[5] = '\0';
        local_420[6] = '\0';
        local_420[7] = '\0';
        p_Var5 = local_4e8->lpVtbl[4].AddRef;
        *(undefined8 *)(puVar41 + -8) = 0x18002cde2;
        UVar21 = (*p_Var5)(pIVar12);
        if ((int)UVar21 < 0) {
          *(undefined8 *)(puVar41 + -8) = 0x18002cdf7;
          _com_issue_errorex(UVar21,pIVar12,(_GUID *)&DAT_1800424c8);
        }
        auVar38 = local_420;
        *(undefined8 *)(puVar41 + -8) = 0x18002ce08;
        local_528 = (uchar  [8])operator_new(0x18);
        pIVar12 = local_4e8;
        if (local_528 == (uchar  [8])0x0) {
          auVar38[0] = '\0';
          auVar38[1] = '\0';
          auVar38[2] = '\0';
          auVar38[3] = '\0';
          auVar38[4] = '\0';
          auVar38[5] = '\0';
          auVar38[6] = '\0';
          auVar38[7] = '\0';
        }
        else {
          *(uchar (*) [8])((longlong)local_528 + 8) = (uchar  [8])0x0;
          pauVar1 = (uchar (*) [8])((longlong)local_528 + 0x10);
          *(uchar *)((longlong)pauVar1 + 0) = '\x01';
          *(uchar *)((longlong)pauVar1 + 1) = '\0';
          *(uchar *)((longlong)pauVar1 + 2) = '\0';
          *(uchar *)((longlong)pauVar1 + 3) = '\0';
          *(uchar (*) [8])local_528 = auVar38;
          auVar38 = local_528;
        }
        local_3d8 = auVar38;
        if (auVar38 == (uchar  [8])0x0) {
                    /* WARNING: Subroutine does not return */
          *(undefined8 *)(puVar41 + -8) = 0x18002df65;
          FUN_180034a60(0x8007000e);
        }
        uVar43 = uVar43 | 2;
        local_52c = 0;
        p_Var6 = local_4e8->lpVtbl[4].Release;
        local_530 = uVar43;
        *(undefined8 *)(puVar41 + -8) = 0x18002ce57;
        UVar21 = (*p_Var6)(pIVar12);
        if ((int)UVar21 < 0) {
          *(undefined8 *)(puVar41 + -8) = 0x18002ce6c;
          _com_issue_errorex(UVar21,pIVar12,(_GUID *)&DAT_1800424c8);
        }
        if (local_52c != 0) {
          auVar7 = *(uchar (*) [8])auVar38;
          puVar40 = puVar41;
          if (auVar7 == (uchar  [8])0x0) {
LAB_18002cf0a:
            pcVar42 = (char *)0x0;
            puVar41 = puVar40;
          }
          else {
            lVar24 = -1;
            do {
              lVar25 = lVar24;
              lVar24 = lVar25 + 1;
            } while (*(LPCWSTR)((longlong)auVar7 + lVar24 * 2) != L'\0');
            iVar37 = (int)lVar25 + 2;
            if (0x3fffffff < iVar37) goto LAB_18002cf0a;
            lVar24 = (longlong)(int)lVar24 * 2;
            uVar36 = lVar24 + 0x11;
            if (uVar36 <= lVar24 + 2U) {
              uVar36 = 0xffffffffffffff0;
            }
            *(undefined8 *)(puVar41 + -8) = 0x18002cecf;
            lVar24 = -(uVar36 & 0xfffffffffffffff0);
            puVar40 = puVar41 + lVar24;
            puVar39 = puVar41 + lVar24;
            pcVar42 = puVar41 + lVar24 + 0x40;
            if (pcVar42 == (char *)0x0) goto LAB_18002cf0a;
            *pcVar42 = '\0';
            *(undefined8 *)(puVar41 + lVar24 + 0x38) = 0;
            *(undefined8 *)(puVar41 + lVar24 + 0x30) = 0;
            *(int *)(puVar41 + lVar24 + 0x28) = iVar37 * 2;
            *(char **)(puVar41 + lVar24 + 0x20) = pcVar42;
            *(undefined8 *)(puVar41 + lVar24 + -8) = 0x18002cf02;
            iVar37 = WideCharToMultiByte(0,0,(LPCWSTR)auVar7,-1,*(LPSTR *)(puVar41 + lVar24 + 0x20),
                                         *(int *)(puVar41 + lVar24 + 0x28),
                                         *(LPCSTR *)(puVar41 + lVar24 + 0x30),
                                         *(LPBOOL *)(puVar41 + lVar24 + 0x38));
            puVar41 = puVar41 + lVar24;
            if (iVar37 == 0) {
              pcVar42 = (char *)0x0;
              puVar41 = puVar39;
            }
          }
          *(undefined8 *)(puVar41 + -8) = 0x18002cf1d;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_418,pcVar42);
          pcVar42 = local_4c8;
          *(undefined8 *)(puVar41 + -8) = 0x18002cf35;
          iVar37 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                             (local_418,pcVar42,0);
          pIVar12 = local_4f8;
          if (-1 < iVar37) {
            LOCK();
            *(int *)*(uchar (*) [8])((longlong)auVar38 + 0x10) =
                 *(int *)*(uchar (*) [8])((longlong)auVar38 + 0x10) + 1;
            UNLOCK();
            local_528 = (uchar  [8])local_4d8;
            local_510 = 0;
            p_Var5 = local_4f8->lpVtbl[9].AddRef;
            local_4d8 = auVar38;
            *(undefined8 *)(puVar41 + -8) = 0x18002cf7b;
            UVar21 = (*p_Var5)(pIVar12);
            if ((int)UVar21 < 0) {
              *(undefined8 *)(puVar41 + -8) = 0x18002cf90;
              _com_issue_errorex(UVar21,pIVar12,(_GUID *)&DAT_1800424d8);
            }
            *(undefined8 *)(puVar41 + -8) = 0x18002cf9d;
            FUN_18001ccd0((undefined8 *)local_4d8);
          }
          *(undefined8 *)(puVar41 + -8) = 0x18002cfab;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_418);
        }
        LOCK();
        pauVar1 = (uchar (*) [8])((longlong)auVar38 + 0x10);
        iVar37 = *(int *)*pauVar1;
        *(int *)*pauVar1 = *(int *)*pauVar1 + -1;
        UNLOCK();
        if (iVar37 == 1) {
          auVar7 = *(uchar (*) [8])auVar38;
          if (auVar7 != (uchar  [8])0x0) {
            *(undefined8 *)(puVar41 + -8) = 0x18002cfc7;
            SysFreeString((BSTR)auVar7);
            *(uchar (*) [8])auVar38 = (uchar  [8])0x0;
          }
          auVar7 = *(uchar (*) [8])((longlong)auVar38 + 8);
          if (auVar7 != (uchar  [8])0x0) {
            *(undefined8 *)(puVar41 + -8) = 0x18002cfd8;
            operator_delete__((void *)auVar7);
            *(uchar (*) [8])((longlong)auVar38 + 8) = (uchar  [8])0x0;
          }
          *(undefined8 *)(puVar41 + -8) = 0x18002cfe9;
          FUN_180035134((void *)auVar38);
        }
      }
      pIVar12 = local_4e8;
      if (local_4e8 != (IUnknown *)0x0) {
        p_Var6 = local_4e8->lpVtbl->Release;
        *(undefined8 *)(puVar41 + -8) = 0x18002cffe;
        (*p_Var6)(pIVar12);
      }
      local_50c = local_50c + 1;
    } while (local_50c <= local_508[0]);
    puVar40 = puVar41;
    param_1 = local_4f8;
    uVar43 = local_530;
  }
  *(undefined8 *)(puVar40 + -8) = 0x18002d01f;
  SafeArrayUnlock(psa);
  *(undefined8 *)(puVar40 + -8) = 0x18002d028;
  SafeArrayDestroy(psa);
  *(undefined1 **)(puVar40 + 0x20) = local_148;
  *(undefined8 *)(puVar40 + -8) = 0x18002d052;
  _splitpath(param_2,local_4c0,local_248,local_348,*(char **)(puVar40 + 0x20));
  local_560 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  pCStack_558 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  local_550 = 0;
  *(undefined8 *)(puVar40 + -8) = 0x18002d067;
  FUN_180029230((longlong *)&local_560);
  local_548 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  pCStack_540 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  local_538 = 0;
  *(undefined8 *)(puVar40 + -8) = 0x18002d084;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_500,"");
  *(undefined8 *)(puVar40 + -8) = 0x18002d096;
  FUN_180028cb0((longlong *)&local_560,(longlong *)&local_548,
                (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_500);
  if (((longlong)pCStack_558 - (longlong)local_560 >> 3 == 0) &&
     ((longlong)pCStack_540 - (longlong)local_548 >> 3 == 0)) {
    *(undefined8 *)(puVar40 + -8) = 0x18002d0d6;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_500);
    pCVar15 = pCStack_540;
    pCVar27 = local_548;
    if (local_548 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
      for (; pCVar27 != pCVar15; pCVar27 = pCVar27 + 8) {
        *(undefined8 *)(puVar40 + -8) = 0x18002d0f9;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar27);
      }
      pCVar27 = local_548;
      if ((0xfff < (ulonglong)((local_538 - (longlong)local_548 >> 3) * 8)) &&
         (pCVar27 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                     (local_548 + -8),
         (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x1f <
         local_548 + (-8 - (longlong)pCVar27))) goto LAB_18002ded1;
      *(undefined8 *)(puVar40 + -8) = 0x18002d146;
      FUN_180035134(pCVar27);
      local_548 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
      pCStack_540 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
      local_538 = 0;
    }
    pCVar15 = pCStack_558;
    pCVar27 = local_560;
    if (local_560 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
      for (; pCVar27 != pCVar15; pCVar27 = pCVar27 + 8) {
        *(undefined8 *)(puVar40 + -8) = 0x18002d16d;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar27);
      }
LAB_18002d17a:
      pCVar27 = local_560;
      if (0xfff < (ulonglong)((local_550 - (longlong)local_560 >> 3) * 8)) {
        lVar24 = (longlong)local_560 -
                 (longlong)
                 *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)(local_560 + -8)
        ;
        pCVar27 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                   (local_560 + -8);
joined_r0x00018002df4e:
        if (0x1f < lVar24 - 8U) {
LAB_18002df54:
                    /* WARNING: Subroutine does not return */
          *(undefined **)(puVar40 + -8) = &UNK_18002df5a;
          _invalid_parameter_noinfo_noreturn();
        }
      }
      goto LAB_18002d1b2;
    }
  }
  else {
    if ((longlong)pCStack_540 - (longlong)local_548 >> 3 != 0) {
      *(undefined8 *)(puVar40 + -8) = 0x18002d233;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4a0,"");
      *(undefined8 *)(puVar40 + -8) = 0x18002d245;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4f0,"");
      *(undefined8 *)(puVar40 + -8) = 0x18002d25a;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_458,"");
      iVar37 = 0;
      while( true ) {
        local_568[0] = iVar37;
        if ((ulonglong)((longlong)pCStack_540 - (longlong)local_548 >> 3) <=
            (ulonglong)(longlong)iVar37) break;
        pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 (local_548 + (longlong)iVar37 * 8);
        *(undefined8 *)(puVar40 + -8) = 0x18002d28e;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4a0,
                   pCVar4);
        uVar19 = local_4a0;
        uVar26 = local_500;
        *(undefined8 *)(puVar40 + -8) = 0x18002d2aa;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4f0,
                   "%s\\%s.atmlz",uVar26,uVar19);
        uVar19 = local_480;
        uVar26 = local_4a0;
        *(undefined8 *)(puVar40 + -8) = 0x18002d2cc;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_458,
                   "%s%s.atmlz",uVar19,uVar26);
        *(undefined8 *)(puVar40 + -8) = 0x18002d2de;
        pCVar27 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                            (local_408,
                             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                              *)&local_4f0);
        uVar26 = *(undefined8 *)pCVar27;
        *(undefined8 *)(puVar40 + -8) = 0x18002d2f1;
        iVar22 = _stat64i32(uVar26,local_378);
        if (iVar22 == 0) {
          if (local_364 == 0) {
            *(undefined8 *)(puVar40 + -8) = 0x18002d314;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar27);
            bVar14 = true;
          }
          else {
            *(undefined8 *)(puVar40 + -8) = 0x18002d321;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar27);
            bVar14 = false;
          }
        }
        else {
          *(undefined8 *)(puVar40 + -8) = 0x18002d2fe;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar27);
          bVar14 = true;
        }
        pCVar17 = local_458[0];
        if (bVar14) {
          *(undefined8 *)(puVar40 + -8) = 0x18002df79;
          FUN_180025880(local_3a8,"File Size is 0");
                    /* WARNING: Subroutine does not return */
          *(undefined8 *)(puVar40 + -8) = 0x18002df8c;
          _CxxThrowException(local_3a8,(ThrowInfo *)&DAT_180049220);
        }
        *(undefined8 *)(puVar40 + -8) = 0x18002d33c;
        puVar28 = operator_new(0x18);
        local_3d0 = puVar28;
        if (puVar28 == (undefined8 *)0x0) {
          puVar28 = (undefined8 *)0x0;
        }
        else {
          puVar28[1] = 0;
          *(undefined4 *)(puVar28 + 2) = 1;
          *(undefined8 *)(puVar40 + -8) = 0x18002d35e;
          pOVar29 = FUN_180034c50(pCVar17);
          *puVar28 = pOVar29;
        }
        pCVar17 = local_4f0;
        local_3c8 = puVar28;
        if (puVar28 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
          *(undefined8 *)(puVar40 + -8) = 0x18002df96;
          FUN_180034a60(0x8007000e);
        }
        *(undefined8 *)(puVar40 + -8) = 0x18002d384;
        puVar30 = operator_new(0x18);
        local_3e8 = puVar30;
        if (puVar30 == (undefined8 *)0x0) {
          puVar30 = (undefined8 *)0x0;
        }
        else {
          puVar30[1] = 0;
          *(undefined4 *)(puVar30 + 2) = 1;
          *(undefined8 *)(puVar40 + -8) = 0x18002d3a6;
          pOVar29 = FUN_180034c50(pCVar17);
          *puVar30 = pOVar29;
        }
        local_3c0 = puVar30;
        if (puVar30 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
          *(undefined8 *)(puVar40 + -8) = 0x18002dfa1;
          FUN_180034a60(0x8007000e);
        }
        local_448 = (longlong *)0x0;
        *(undefined8 *)(puVar40 + -8) = 0x18002d3cf;
        puVar31 = operator_new(0x18);
        local_400 = puVar31;
        if (puVar31 == (undefined8 *)0x0) {
          local_4a8 = (undefined8 *)0x0;
        }
        else {
          puVar31[1] = 0;
          *(undefined4 *)(puVar31 + 2) = 1;
          *(undefined8 *)(puVar40 + -8) = 0x18002d3f5;
          pOVar29 = FUN_180034c50("");
          *puVar31 = pOVar29;
          local_4a8 = puVar31;
        }
        if (local_4a8 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
          *(undefined8 *)(puVar40 + -8) = 0x18002dfac;
          FUN_180034a60(0x8007000e);
        }
        local_528 = (uchar  [8])&local_4a8;
        LOCK();
        *(int *)(puVar30 + 2) = *(int *)(puVar30 + 2) + 1;
        UNLOCK();
        local_3f8 = &local_4b0;
        LOCK();
        *(int *)(puVar28 + 2) = *(int *)(puVar28 + 2) + 1;
        UNLOCK();
        local_470 = &local_4b8;
        local_410 = (longlong *)0x0;
        if (puVar30 == (undefined8 *)0x0) {
          ppvObject = (void **)0x0;
        }
        else {
          ppvObject = (void **)*puVar30;
        }
        if (puVar28 == (undefined8 *)0x0) {
          riid = (IID *)0x0;
        }
        else {
          riid = (IID *)*puVar28;
        }
        pIVar8 = param_1->lpVtbl;
        local_4b8 = puVar28;
        local_4b0 = puVar30;
        *(longlong ***)(puVar40 + 0x28) = &local_410;
        *(undefined2 *)(puVar40 + 0x20) = 0xffff;
        pIVar12 = local_4f8;
        p_Var9 = pIVar8[8].QueryInterface;
        *(undefined8 *)(puVar40 + -8) = 0x18002d4b9;
        HVar20 = (*p_Var9)(pIVar12,riid,ppvObject);
        if (HVar20 < 0) {
          *(undefined8 *)(puVar40 + -8) = 0x18002d4ce;
          _com_issue_errorex(HVar20,pIVar12,(_GUID *)&DAT_1800424d8);
        }
        plVar13 = local_410;
        local_530 = uVar43 | 1;
        *(undefined8 *)(puVar40 + -8) = 0x18002d4e7;
        FUN_18001ccd0(&local_4b8);
        *(undefined8 *)(puVar40 + -8) = 0x18002d4f4;
        FUN_18001ccd0(&local_4b0);
        *(undefined8 *)(puVar40 + -8) = 0x18002d501;
        FUN_18001ccd0(&local_4a8);
        if (plVar13 == (longlong *)0x0) {
          plVar13 = local_448;
        }
        else {
          pcVar10 = *(code **)(*plVar13 + 8);
          *(undefined8 *)(puVar40 + -8) = 0x18002d50f;
          (*pcVar10)(plVar13);
          local_448 = plVar13;
          pcVar10 = *(code **)(*plVar13 + 0x10);
          *(undefined8 *)(puVar40 + -8) = 0x18002d530;
          (*pcVar10)(plVar13);
        }
        if (plVar13 != (longlong *)0x0) {
          pcVar10 = *(code **)(*plVar13 + 0x10);
          *(undefined8 *)(puVar40 + -8) = 0x18002d53f;
          (*pcVar10)(plVar13);
        }
        LOCK();
        piVar2 = (int *)(puVar30 + 2);
        iVar22 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if (iVar22 == 1) {
          pOVar29 = (BSTR)*puVar30;
          if (pOVar29 != (BSTR)0x0) {
            *(undefined8 *)(puVar40 + -8) = 0x18002d55c;
            SysFreeString(pOVar29);
            *puVar30 = 0;
          }
          pvVar11 = (void *)puVar30[1];
          if (pvVar11 != (void *)0x0) {
            *(undefined8 *)(puVar40 + -8) = 0x18002d56d;
            operator_delete__(pvVar11);
            puVar30[1] = 0;
          }
          *(undefined8 *)(puVar40 + -8) = 0x18002d57e;
          FUN_180035134(puVar30);
        }
        LOCK();
        piVar2 = (int *)(puVar28 + 2);
        iVar22 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if (iVar22 == 1) {
          pOVar29 = (BSTR)*puVar28;
          if (pOVar29 != (BSTR)0x0) {
            *(undefined8 *)(puVar40 + -8) = 0x18002d59b;
            SysFreeString(pOVar29);
            *puVar28 = 0;
          }
          pvVar11 = (void *)puVar28[1];
          if (pvVar11 != (void *)0x0) {
            *(undefined8 *)(puVar40 + -8) = 0x18002d5ac;
            operator_delete__(pvVar11);
            puVar28[1] = 0;
          }
          *(undefined8 *)(puVar40 + -8) = 0x18002d5bd;
          FUN_180035134(puVar28);
        }
        iVar37 = iVar37 + 1;
        param_1 = local_4f8;
        uVar43 = local_530;
      }
      *(undefined8 *)(puVar40 + -8) = 0x18002d601;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_458);
      *(undefined8 *)(puVar40 + -8) = 0x18002d60c;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4f0);
      *(undefined8 *)(puVar40 + -8) = 0x18002d61a;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4a0);
    }
    if ((longlong)pCStack_558 - (longlong)local_560 >> 3 == 0) {
      *(undefined8 *)(puVar40 + -8) = 0x18002d63c;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_500);
      pCVar15 = pCStack_540;
      pCVar27 = local_548;
      if (local_548 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        for (; pCVar27 != pCVar15; pCVar27 = pCVar27 + 8) {
          *(undefined8 *)(puVar40 + -8) = 0x18002d659;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar27);
        }
        pCVar27 = local_548;
        if ((0xfff < (ulonglong)((local_538 - (longlong)local_548 >> 3) * 8)) &&
           (pCVar27 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                       (local_548 + -8),
           (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x1f <
           local_548 + (-8 - (longlong)pCVar27))) goto LAB_18002ded1;
        *(undefined8 *)(puVar40 + -8) = 0x18002d6a6;
        FUN_180035134(pCVar27);
        local_548 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
        pCStack_540 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
        local_538 = 0;
      }
      pCVar15 = pCStack_558;
      pCVar27 = local_560;
      if (local_560 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        for (; pCVar27 != pCVar15; pCVar27 = pCVar27 + 8) {
          *(undefined8 *)(puVar40 + -8) = 0x18002d6d9;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar27);
        }
        goto LAB_18002d17a;
      }
    }
    else {
      *(undefined8 *)(puVar40 + -8) = 0x18002d6ec;
      pIVar32 = DCGetACMModelLibraryManagerPtr();
      if (pIVar32 == (IModelLibraryManager *)0x0) {
        *(undefined8 *)(puVar40 + -8) = 0x18002d702;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_500);
        pCVar15 = pCStack_540;
        pCVar27 = local_548;
        if (local_548 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
          for (; pCVar27 != pCVar15; pCVar27 = pCVar27 + 8) {
            *(undefined8 *)(puVar40 + -8) = 0x18002d71e;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar27);
          }
          pCVar27 = local_548;
          if ((0xfff < (ulonglong)((local_538 - (longlong)local_548 >> 3) * 8)) &&
             (pCVar27 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                         (local_548 + -8),
             (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x1f <
             local_548 + (-8 - (longlong)pCVar27))) goto LAB_18002ded1;
          *(undefined8 *)(puVar40 + -8) = 0x18002d76b;
          FUN_180035134(pCVar27);
          local_548 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
          pCStack_540 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
          local_538 = 0;
        }
        pCVar15 = pCStack_558;
        pCVar27 = local_560;
        if (local_560 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
          for (; pCVar27 != pCVar15; pCVar27 = pCVar27 + 8) {
            *(undefined8 *)(puVar40 + -8) = 0x18002d799;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar27);
          }
          pCVar27 = local_560;
          if ((0xfff < (ulonglong)((local_550 - (longlong)local_560 >> 3) * 8)) &&
             (pCVar27 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                         (local_560 + -8),
             (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x1f <
             local_560 + (-8 - (longlong)pCVar27))) goto LAB_18002df54;
          *(undefined8 *)(puVar40 + -8) = 0x18002d7e6;
          FUN_180035134(pCVar27);
          local_560 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
          pCStack_558 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
          local_550 = 0;
        }
        *(undefined8 *)(puVar40 + -8) = 0x18002d7ff;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_480);
        *(undefined8 *)(puVar40 + -8) = 0x18002d80d;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4c8);
        uVar26 = 0;
        goto LAB_18002d1e6;
      }
      *(undefined8 *)(puVar40 + -8) = 0x18002d81c;
      _Var33 = _time64((__time64_t *)0x0);
      *(undefined8 *)(puVar40 + -8) = 0x18002d825;
      srand((uint)_Var33);
      *(undefined8 *)(puVar40 + -8) = 0x18002d832;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4d0);
      *(undefined8 *)(puVar40 + -8) = 0x18002d839;
      iVar37 = rand();
      *(int *)(puVar40 + 0x28) = iVar37 % 10000;
      *(char **)(puVar40 + 0x20) = local_348;
      *(undefined8 *)(puVar40 + -8) = 0x18002d88a;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4d0,
                 "%s%s%s_Temp_%d",local_4c0,local_248);
      local_568[0] = 0;
      for (iVar37 = 0;
          (ulonglong)(longlong)iVar37 <
          (ulonglong)((longlong)pCStack_558 - (longlong)local_560 >> 3); iVar37 = iVar37 + 1) {
        pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 (local_560 + (longlong)iVar37 * 8);
        *(undefined8 *)(puVar40 + -8) = 0x18002d8bc;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4e0,
                   pCVar4);
        pCVar17 = local_4e0;
        if (local_4e0 == (LPCSTR)0x0) {
          local_488 = (BSTR)0x0;
        }
        else {
          *(undefined4 *)(puVar40 + 0x28) = 0;
          *(undefined8 *)(puVar40 + 0x20) = 0;
          *(undefined8 *)(puVar40 + -8) = 0x18002d8e2;
          iVar22 = MultiByteToWideChar(0,0,pCVar17,-1,*(LPWSTR *)(puVar40 + 0x20),
                                       *(int *)(puVar40 + 0x28));
          *(undefined8 *)(puVar40 + -8) = 0x18002d8f0;
          pOVar29 = SysAllocStringLen((OLECHAR *)0x0,iVar22 - 1);
          if (pOVar29 != (BSTR)0x0) {
            *(int *)(puVar40 + 0x28) = iVar22;
            *(BSTR *)(puVar40 + 0x20) = pOVar29;
            *(undefined8 *)(puVar40 + -8) = 0x18002d912;
            iVar23 = MultiByteToWideChar(0,0,pCVar17,-1,*(LPWSTR *)(puVar40 + 0x20),
                                         *(int *)(puVar40 + 0x28));
            if (iVar23 != iVar22) {
              *(undefined8 *)(puVar40 + -8) = 0x18002d920;
              SysFreeString(pOVar29);
              goto LAB_18002dfad;
            }
          }
          local_488 = pOVar29;
          if (pOVar29 == (BSTR)0x0) {
LAB_18002dfad:
                    /* WARNING: Subroutine does not return */
            *(undefined8 *)(puVar40 + -8) = 0x18002dfb7;
            FUN_1800018d0(-0x7ff8fff2);
          }
        }
        pOVar29 = local_488;
        local_518 = (longlong *)0x0;
        pcVar10 = *(code **)(*(longlong *)pIVar32 + 0x98);
        *(undefined8 *)(puVar40 + -8) = 0x18002d959;
        iVar22 = (*pcVar10)(pIVar32,pOVar29,&local_518);
        if ((iVar22 < 0) || (local_518 == (longlong *)0x0)) {
          pcVar10 = *(code **)(*(longlong *)pIVar32 + 0xa8);
          *(undefined8 *)(puVar40 + -8) = 0x18002d97a;
          iVar22 = (*pcVar10)(pIVar32,pOVar29,&local_518);
          if ((-1 < iVar22) && (local_518 != (longlong *)0x0)) goto LAB_18002d98f;
        }
        else {
LAB_18002d98f:
          plVar13 = local_518;
          pcVar10 = *(code **)(*local_518 + 0x38);
          *(undefined8 *)(puVar40 + -8) = 0x18002d99c;
          iVar22 = (*pcVar10)(plVar13,local_468);
          if ((-1 < iVar22) && (local_468[0] - 4U < 3)) {
            *(undefined8 *)(puVar40 + -8) = 0x18002d9c0;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_520);
            pCVar18 = local_4d0;
            pCVar17 = local_4e0;
            *(undefined8 *)(puVar40 + -8) = 0x18002d9e0;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_520,
                       "%s\\%s.atmlz",pCVar18,pCVar17);
            pCVar17 = local_520;
            if (local_520 == (LPCSTR)0x0) {
              local_490 = (BSTR)0x0;
            }
            else {
              *(undefined4 *)(puVar40 + 0x28) = 0;
              *(undefined8 *)(puVar40 + 0x20) = 0;
              *(undefined8 *)(puVar40 + -8) = 0x18002da02;
              iVar22 = MultiByteToWideChar(0,0,pCVar17,-1,*(LPWSTR *)(puVar40 + 0x20),
                                           *(int *)(puVar40 + 0x28));
              *(undefined8 *)(puVar40 + -8) = 0x18002da10;
              pOVar34 = SysAllocStringLen((OLECHAR *)0x0,iVar22 - 1);
              if (pOVar34 != (BSTR)0x0) {
                *(int *)(puVar40 + 0x28) = iVar22;
                *(BSTR *)(puVar40 + 0x20) = pOVar34;
                *(undefined8 *)(puVar40 + -8) = 0x18002da35;
                iVar23 = MultiByteToWideChar(0,0,pCVar17,-1,*(LPWSTR *)(puVar40 + 0x20),
                                             *(int *)(puVar40 + 0x28));
                if (iVar23 != iVar22) {
                  *(undefined8 *)(puVar40 + -8) = 0x18002da43;
                  SysFreeString(pOVar34);
                  goto LAB_18002dfb8;
                }
              }
              local_490 = pOVar34;
              if (pOVar34 == (BSTR)0x0) {
LAB_18002dfb8:
                    /* WARNING: Subroutine does not return */
                *(undefined8 *)(puVar40 + -8) = 0x18002dfc2;
                FUN_1800018d0(-0x7ff8fff2);
              }
            }
            pOVar34 = local_490;
            plVar13 = local_518;
            pcVar10 = *(code **)(*local_518 + 0x1b0);
            *(undefined8 *)(puVar40 + -8) = 0x18002da80;
            iVar22 = (*pcVar10)(plVar13,pOVar34,0xffffffff);
            if (-1 < iVar22) {
              local_568[0] = 1;
              *(undefined8 *)(puVar40 + -8) = 0x18002da9c;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_498
                        );
              pcVar42 = local_4c8;
              pCVar17 = local_4e0;
              *(undefined8 *)(puVar40 + -8) = 0x18002dabf;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_498
                         ,"%s%s.atmlz",pcVar42,pCVar17);
              *(undefined8 *)(puVar40 + -8) = 0x18002dad1;
              pCVar27 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                  (local_3f0,
                                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                    *)&local_520);
              *(undefined8 *)(puVar40 + -8) = 0x18002dad9;
              uVar26 = FUN_1800323f0(pCVar27);
              pCVar17 = local_498;
              if ((int)uVar26 != 0) {
                *(undefined8 *)(puVar40 + -8) = 0x18002dfd6;
                FUN_180025880(local_390,"File Size is 0");
                    /* WARNING: Subroutine does not return */
                *(undefined8 *)(puVar40 + -8) = 0x18002dfe9;
                _CxxThrowException(local_390,(ThrowInfo *)&DAT_180049220);
              }
              *(undefined8 *)(puVar40 + -8) = 0x18002daf2;
              ppuVar35 = operator_new(0x18);
              local_3f8 = ppuVar35;
              if (ppuVar35 == (undefined8 **)0x0) {
                ppuVar35 = (undefined8 **)0x0;
              }
              else {
                ppuVar35[1] = (undefined8 *)0x0;
                *(undefined4 *)(ppuVar35 + 2) = 1;
                *(undefined8 *)(puVar40 + -8) = 0x18002db14;
                pOVar29 = FUN_180034c50(pCVar17);
                *ppuVar35 = (undefined8 *)pOVar29;
              }
              pCVar17 = local_520;
              local_3b8 = ppuVar35;
              if (ppuVar35 == (undefined8 **)0x0) {
                    /* WARNING: Subroutine does not return */
                *(undefined8 *)(puVar40 + -8) = 0x18002dff3;
                FUN_180034a60(0x8007000e);
              }
              *(undefined8 *)(puVar40 + -8) = 0x18002db3a;
              puVar28 = operator_new(0x18);
              local_400 = puVar28;
              if (puVar28 == (undefined8 *)0x0) {
                puVar28 = (undefined8 *)0x0;
              }
              else {
                puVar28[1] = 0;
                *(undefined4 *)(puVar28 + 2) = 1;
                *(undefined8 *)(puVar40 + -8) = 0x18002db5c;
                pOVar29 = FUN_180034c50(pCVar17);
                *puVar28 = pOVar29;
              }
              local_3b0 = puVar28;
              if (puVar28 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
                *(undefined8 *)(puVar40 + -8) = 0x18002dffe;
                FUN_180034a60(0x8007000e);
              }
              local_478 = (IUnknown *)0x0;
              *(undefined8 *)(puVar40 + -8) = 0x18002db85;
              puVar30 = operator_new(0x18);
              local_3e8 = puVar30;
              if (puVar30 == (undefined8 *)0x0) {
                puVar30 = (undefined8 *)0x0;
              }
              else {
                puVar30[1] = 0;
                *(undefined4 *)(puVar30 + 2) = 1;
                *(undefined8 *)(puVar40 + -8) = 0x18002dbab;
                pOVar29 = FUN_180034c50("");
                *puVar30 = pOVar29;
              }
              local_440 = puVar30;
              if (puVar30 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
                *(undefined **)(puVar40 + -8) = &UNK_18002e009;
                FUN_180034a60(0x8007000e);
              }
              local_438 = puVar28;
              LOCK();
              *(int *)(puVar28 + 2) = *(int *)(puVar28 + 2) + 1;
              UNLOCK();
              local_430 = ppuVar35;
              LOCK();
              *(int *)(ppuVar35 + 2) = *(int *)(ppuVar35 + 2) + 1;
              UNLOCK();
              *(undefined2 *)(puVar40 + 0x28) = 0xffff;
              *(undefined8 ***)(puVar40 + 0x20) = &local_440;
              pIVar12 = local_4f8;
              *(undefined8 *)(puVar40 + -8) = 0x18002dc0a;
              puVar30 = FUN_180026260(pIVar12,&local_3e0,(longlong *)&local_430,
                                      (longlong *)&local_438,*(undefined8 **)(puVar40 + 0x20));
              pIVar12 = (IUnknown *)*puVar30;
              if (pIVar12 != (IUnknown *)0x0) {
                p_Var5 = pIVar12->lpVtbl->AddRef;
                *(undefined8 *)(puVar40 + -8) = 0x18002dc1b;
                (*p_Var5)(pIVar12);
                local_478 = pIVar12;
              }
              pIVar12 = local_478;
              if (local_3e0 != (longlong *)0x0) {
                pcVar10 = *(code **)(*local_3e0 + 0x10);
                *(undefined8 *)(puVar40 + -8) = 0x18002dc3d;
                (*pcVar10)();
              }
              pCVar17 = local_520;
              *(undefined8 *)(puVar40 + -8) = 0x18002dc48;
              DeleteFileA(pCVar17);
              if (pIVar12 != (IUnknown *)0x0) {
                p_Var6 = pIVar12->lpVtbl->Release;
                *(undefined8 *)(puVar40 + -8) = 0x18002dc57;
                (*p_Var6)(pIVar12);
              }
              LOCK();
              piVar2 = (int *)(puVar28 + 2);
              iVar22 = *piVar2;
              *piVar2 = *piVar2 + -1;
              UNLOCK();
              if (iVar22 == 1) {
                pOVar29 = (BSTR)*puVar28;
                if (pOVar29 != (BSTR)0x0) {
                  *(undefined8 *)(puVar40 + -8) = 0x18002dc73;
                  SysFreeString(pOVar29);
                  *puVar28 = 0;
                }
                pvVar11 = (void *)puVar28[1];
                if (pvVar11 != (void *)0x0) {
                  *(undefined8 *)(puVar40 + -8) = 0x18002dc84;
                  operator_delete__(pvVar11);
                  puVar28[1] = 0;
                }
                *(undefined8 *)(puVar40 + -8) = 0x18002dc95;
                FUN_180035134(puVar28);
              }
              LOCK();
              ppuVar3 = ppuVar35 + 2;
              iVar22 = *(int *)ppuVar3;
              *(int *)ppuVar3 = *(int *)ppuVar3 + -1;
              UNLOCK();
              if (iVar22 == 1) {
                pOVar29 = (BSTR)*ppuVar35;
                if (pOVar29 != (BSTR)0x0) {
                  *(undefined8 *)(puVar40 + -8) = 0x18002dcb2;
                  SysFreeString(pOVar29);
                  *ppuVar35 = (undefined8 *)0x0;
                }
                puVar28 = ppuVar35[1];
                if (puVar28 != (undefined8 *)0x0) {
                  *(undefined8 *)(puVar40 + -8) = 0x18002dcc3;
                  operator_delete__(puVar28);
                  ppuVar35[1] = (undefined8 *)0x0;
                }
                *(undefined8 *)(puVar40 + -8) = 0x18002dcd4;
                FUN_180035134(ppuVar35);
              }
              *(undefined8 *)(puVar40 + -8) = 0x18002dce2;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_498
                        );
              pOVar29 = local_488;
              pOVar34 = local_490;
            }
            *(undefined8 *)(puVar40 + -8) = 0x18002dcf9;
            SysFreeString(pOVar34);
            *(undefined8 *)(puVar40 + -8) = 0x18002dd04;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_520);
          }
          pcVar10 = *(code **)(*(longlong *)pIVar32 + 0xe8);
          *(undefined8 *)(puVar40 + -8) = 0x18002dd14;
          (*pcVar10)(pIVar32,pOVar29);
        }
        if (local_518 != (longlong *)0x0) {
          pcVar10 = *(code **)(*local_518 + 0x10);
          *(undefined8 *)(puVar40 + -8) = 0x18002dd23;
          (*pcVar10)();
        }
        *(undefined8 *)(puVar40 + -8) = 0x18002dd2d;
        SysFreeString(pOVar29);
        *(undefined8 *)(puVar40 + -8) = 0x18002dd3b;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4e0);
      }
      if (local_568[0] != 0) {
        *(undefined8 *)(puVar40 + -8) = 0x18002de5b;
        RemoveDirectoryA(local_4d0);
      }
      *(undefined8 *)(puVar40 + -8) = 0x18002de69;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4d0);
      *(undefined8 *)(puVar40 + -8) = 0x18002de74;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_500);
      pCVar15 = pCStack_540;
      pCVar27 = local_548;
      if (local_548 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        for (; pCVar27 != pCVar15; pCVar27 = pCVar27 + 8) {
          *(undefined8 *)(puVar40 + -8) = 0x18002de90;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar27);
        }
        pCVar27 = local_548;
        if ((0xfff < (ulonglong)((local_538 - (longlong)local_548 >> 3) * 8)) &&
           (pCVar27 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                       (local_548 + -8),
           (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x1f <
           local_548 + (-8 - (longlong)pCVar27))) {
LAB_18002ded1:
                    /* WARNING: Subroutine does not return */
          *(undefined **)(puVar40 + -8) = &UNK_18002ded7;
          _invalid_parameter_noinfo_noreturn();
        }
        *(undefined8 *)(puVar40 + -8) = 0x18002dee0;
        FUN_180035134(pCVar27);
        local_548 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
        pCStack_540 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
        local_538 = 0;
      }
      pCVar16 = pCStack_558;
      pCVar15 = local_560;
      pCVar27 = local_560;
      if (local_560 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0)
      goto LAB_18002d1c6;
      for (; local_560 = pCVar27, pCVar15 != pCVar16; pCVar15 = pCVar15 + 8) {
        *(undefined8 *)(puVar40 + -8) = 0x18002df0b;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar15);
        pCVar27 = local_560;
      }
      if (0xfff < (ulonglong)((local_550 - (longlong)pCVar27 >> 3) * 8)) {
        lVar24 = (longlong)pCVar27 -
                 (longlong)
                 *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)(pCVar27 + -8);
        pCVar27 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)(pCVar27 + -8);
        goto joined_r0x00018002df4e;
      }
LAB_18002d1b2:
      *(undefined8 *)(puVar40 + -8) = 0x18002d1ba;
      FUN_180035134(pCVar27);
      local_560 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
      pCStack_558 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
      local_550 = 0;
    }
  }
LAB_18002d1c6:
  *(undefined8 *)(puVar40 + -8) = 0x18002d1d3;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_480);
  *(undefined8 *)(puVar40 + -8) = 0x18002d1e1;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4c8);
  uVar26 = 1;
LAB_18002d1e6:
  *(undefined8 *)(puVar40 + -8) = 0x18002d1f5;
  return uVar26;
}

/* RVA 0x2e010 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18002e010(IUnknown *param_1,char *param_2,char *param_3)

{
  undefined8 uVar1;
  char *pcVar2;
  undefined1 auStack_148 [32];
  undefined4 local_128;
  undefined2 local_124 [126];
  ulonglong local_28;
  
  local_28 = DAT_180052888 ^ (ulonglong)auStack_148;
  memset(local_124,0,0xfc);
  uVar1 = FUN_180029600("roottype");
  if ((int)uVar1 == 0) {
    local_128 = DAT_1800425e8;
    local_124[0] = DAT_1800425ec;
  }
  else {
    uVar1 = FUN_180029600("roottype");
    if ((int)uVar1 == 1) {
      local_128 = 0x706b62;
      FUN_180025ad0(param_1,param_2,param_3,(char *)&local_128);
    }
    local_128 = DAT_1800425f0;
    local_124[0] = DAT_1800425f4;
    FUN_180025ad0(param_1,param_2,param_3,(char *)&local_128);
    local_128 = 0x666470;
    FUN_180025ad0(param_1,param_2,param_2,(char *)&local_128);
    local_128 = 0x726f66;
  }
  FUN_180025ad0(param_1,param_2,param_3,(char *)&local_128);
  local_128 = 0x736461;
  FUN_180025ad0(param_1,param_2,param_3,(char *)&local_128);
  local_128 = 0x736264;
  FUN_180025ad0(param_1,param_2,param_3,(char *)&local_128);
  local_128 = 0x686368;
  FUN_180025ad0(param_1,param_2,param_3,(char *)&local_128);
  local_128 = 0x6c6d78;
  FUN_180025ad0(param_1,param_2,param_3,(char *)&local_128);
  pcVar2 = (char *)GetGlobalPointer("DBFileNameForCompound");
  if (pcVar2 != (char *)0x0) {
    local_128 = 0x62646d;
    FUN_180025ad0(param_1,param_2,pcVar2,(char *)&local_128);
  }
  local_128 = 0x70697a;
  FUN_180025ad0(param_1,param_2,param_2,(char *)&local_128);
  FUN_18002e1f0(param_1,param_2);
  return 1;
}

/* RVA 0x2e1f0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18002e1f0(IUnknown *param_1,char *param_2)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  longlong *plVar4;
  ULONG UVar5;
  HRESULT HVar6;
  BOOL BVar7;
  HANDLE hFindFile;
  undefined8 *puVar8;
  BSTR pOVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  char *pcVar12;
  IID *riid;
  longlong *plVar13;
  void **ppvObject;
  undefined1 auStackY_968 [32];
  undefined8 *local_928;
  uint local_920;
  char local_91c [4];
  undefined8 *local_918;
  undefined8 *local_910;
  undefined8 *local_908;
  longlong *local_900;
  char *local_8f0;
  longlong *local_8e8;
  IUnknown *local_8e0;
  HANDLE local_8d8;
  undefined8 *local_8d0;
  undefined8 *local_8c8;
  undefined8 **local_8c0;
  undefined8 **local_8b8;
  _WIN32_FIND_DATAA local_8a8;
  char local_768 [256];
  CHAR local_668 [272];
  char local_558 [256];
  char local_458 [272];
  char local_348 [272];
  char local_238 [256];
  char local_138 [256];
  ulonglong local_38;
  
  local_38 = DAT_180052888 ^ (ulonglong)auStackY_968;
  local_920 = 0;
  local_900 = (longlong *)0x0;
  local_8e0 = param_1;
  _splitpath(param_2,local_91c,local_558,local_138,local_238);
  _makepath(local_768,local_91c,local_558,(char *)0x0,(char *)0x0);
  _makepath(local_458,(char *)0x0,local_768,"*","apsst");
  hFindFile = FindFirstFileA(local_458,&local_8a8);
  plVar13 = (longlong *)0x0;
  local_8d8 = hFindFile;
  do {
    if (hFindFile == (HANDLE)0xffffffffffffffff) {
LAB_18002e635:
      FindClose(hFindFile);
      if (plVar13 != (longlong *)0x0) {
        (**(code **)(*plVar13 + 0x10))(plVar13);
      }
      return;
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_8f0,
               local_8a8.cFileName);
    pcVar12 = local_8f0;
    do {
      cVar3 = *pcVar12;
      pcVar12[(longlong)(local_668 + -(longlong)local_8f0)] = cVar3;
      pcVar12 = pcVar12 + 1;
    } while (cVar3 != '\0');
    _makepath(local_348,(char *)0x0,local_768,local_8f0,(char *)0x0);
    puVar8 = operator_new(0x18);
    local_928 = puVar8;
    if (puVar8 == (undefined8 *)0x0) {
      puVar8 = (undefined8 *)0x0;
    }
    else {
      puVar8[1] = 0;
      *(undefined4 *)(puVar8 + 2) = 1;
      pOVar9 = FUN_180034c50(local_668);
      *puVar8 = pOVar9;
    }
    local_8d0 = puVar8;
    if (puVar8 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_180034a60(0x8007000e);
    }
    puVar10 = operator_new(0x18);
    local_928 = puVar10;
    if (puVar10 == (undefined8 *)0x0) {
      puVar10 = (undefined8 *)0x0;
    }
    else {
      puVar10[1] = 0;
      *(undefined4 *)(puVar10 + 2) = 1;
      pOVar9 = FUN_180034c50(local_348);
      *puVar10 = pOVar9;
    }
    local_8c8 = puVar10;
    if (puVar10 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_180034a60(0x8007000e);
    }
    LOCK();
    *(int *)(puVar8 + 2) = *(int *)(puVar8 + 2) + 1;
    UNLOCK();
    local_928 = puVar8;
    UVar5 = (*param_1->lpVtbl[9].AddRef)(param_1);
    if ((int)UVar5 < 0) {
      _com_issue_errorex(UVar5,param_1,(_GUID *)&DAT_1800424d8);
    }
    FUN_18001ccd0(&local_928);
    puVar11 = operator_new(0x18);
    if (puVar11 == (undefined8 *)0x0) {
      puVar11 = (undefined8 *)0x0;
    }
    else {
      puVar11[1] = 0;
      *(undefined4 *)(puVar11 + 2) = 1;
      pOVar9 = FUN_180034c50("");
      *puVar11 = pOVar9;
    }
    local_908 = puVar11;
    if (puVar11 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_180034a60(0x8007000e);
    }
    LOCK();
    *(int *)(puVar10 + 2) = *(int *)(puVar10 + 2) + 1;
    UNLOCK();
    local_8c0 = &local_910;
    LOCK();
    *(int *)(puVar8 + 2) = *(int *)(puVar8 + 2) + 1;
    UNLOCK();
    local_8b8 = &local_918;
    local_8e8 = (longlong *)0x0;
    if (puVar10 == (undefined8 *)0x0) {
      ppvObject = (void **)0x0;
    }
    else {
      ppvObject = (void **)*puVar10;
    }
    if (puVar8 == (undefined8 *)0x0) {
      riid = (IID *)0x0;
    }
    else {
      riid = (IID *)*puVar8;
    }
    local_918 = puVar8;
    local_910 = puVar10;
    HVar6 = (*param_1->lpVtbl[8].QueryInterface)(param_1,riid,ppvObject);
    if (HVar6 < 0) {
      _com_issue_errorex(HVar6,param_1,(_GUID *)&DAT_1800424d8);
    }
    plVar4 = local_8e8;
    local_920 = local_920 | 1;
    FUN_18001ccd0(&local_918);
    FUN_18001ccd0(&local_910);
    FUN_18001ccd0(&local_908);
    plVar13 = local_900;
    if (local_900 != plVar4) {
      if (plVar4 != (longlong *)0x0) {
        (**(code **)(*plVar4 + 8))(plVar4);
      }
      local_900 = plVar4;
      if (plVar13 != (longlong *)0x0) {
        (**(code **)(*plVar13 + 0x10))(plVar13);
      }
    }
    if (plVar4 != (longlong *)0x0) {
      (**(code **)(*plVar4 + 0x10))(plVar4);
    }
    LOCK();
    piVar1 = (int *)(puVar10 + 2);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      if ((BSTR)*puVar10 != (BSTR)0x0) {
        SysFreeString((BSTR)*puVar10);
        *puVar10 = 0;
      }
      if ((void *)puVar10[1] != (void *)0x0) {
        operator_delete__((void *)puVar10[1]);
        puVar10[1] = 0;
      }
      FUN_180035134(puVar10);
    }
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
      FUN_180035134(puVar8);
    }
    hFindFile = local_8d8;
    BVar7 = FindNextFileA(local_8d8,&local_8a8);
    if (BVar7 == 0) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_8f0);
      plVar13 = local_900;
      goto LAB_18002e635;
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_8f0);
    plVar13 = local_900;
  } while( true );
}

/* RVA 0x2e6b0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18002e6b0(IUnknown *param_1,char *param_2,IUnknown *param_3)

{
  longlong *plVar1;
  int *piVar2;
  IUnknown **ppIVar3;
  int iVar4;
  char cVar5;
  OLECHAR *pOVar6;
  bool bVar7;
  bool bVar8;
  longlong lVar9;
  LPCWSTR bstrString;
  char *pcVar10;
  HANDLE pvVar11;
  longlong *plVar12;
  longlong *plVar13;
  undefined8 *puVar14;
  BSTR pOVar15;
  undefined8 *puVar16;
  longlong *plVar17;
  IUnknown **ppIVar18;
  IUnknown *pIVar19;
  IUnknown *pIVar20;
  IUnknownVtbl *pIVar21;
  IUnknown **ppIVar22;
  char *pcVar23;
  char *pcVar24;
  longlong lVar25;
  IUnknown *pIVar26;
  undefined1 auStackY_ff8 [32];
  byte local_fc8;
  char local_fb8 [8];
  IUnknown *local_fb0;
  IUnknown *local_fa8;
  IUnknown *local_fa0;
  IUnknown *local_f98;
  undefined8 *local_f90;
  IUnknown *local_f88;
  char local_f80 [8];
  longlong *local_f78;
  undefined8 *local_f70;
  longlong *local_f68;
  undefined8 *local_f60;
  undefined8 *local_f58;
  undefined8 *local_f50;
  undefined8 *local_f48;
  IUnknown **local_f40;
  IUnknown **local_f38;
  longlong *local_f30;
  longlong *local_f28;
  longlong *local_f20;
  undefined8 *local_f18;
  undefined8 *local_f10;
  longlong *local_f08;
  undefined8 *local_f00;
  IUnknown **local_ef8;
  IUnknown *local_ef0;
  IUnknown **local_ee8;
  char *local_ed8;
  char local_ed0 [136];
  char *local_e48;
  char local_e40 [136];
  undefined1 *local_db8;
  undefined1 local_db0 [136];
  char *local_d28;
  char local_d20 [136];
  _WIN32_FIND_DATAA local_c98;
  char local_b58 [4];
  char acStack_b54 [255];
  undefined1 local_a55;
  char local_a48 [255];
  char cStack_949;
  CHAR local_948 [4];
  char local_944 [251];
  char cStack_849;
  CHAR local_848 [4];
  char local_844 [251];
  char cStack_749;
  char local_748 [256];
  char local_648 [256];
  char local_548 [256];
  char local_448 [256];
  char local_348 [256];
  char local_248 [256];
  char local_148 [256];
  ulonglong local_48;
  
  local_48 = DAT_180052888 ^ (ulonglong)auStackY_ff8;
  bVar8 = false;
  local_f78 = (longlong *)0x0;
  local_fc8 = 1;
  bVar7 = false;
  local_fa8 = param_3;
  local_fa0 = param_1;
  local_f98 = param_1;
  local_f88 = param_3;
  lVar9 = GetpIcarusInfoHelper();
  if (lVar9 == 0) {
    local_fc8 = 0;
    bstrString = (LPCWSTR)HAGetScenario();
    if (bstrString == (LPCWSTR)0x0) {
      bstrString = SysAllocString(L"Scenario1");
    }
    local_e48 = local_e40;
    FUN_18000d880(&local_e48,bstrString,0);
    pcVar10 = local_e48;
    do {
      cVar5 = *pcVar10;
      pcVar10[(longlong)(local_a48 + -(longlong)local_e48)] = cVar5;
      pcVar10 = pcVar10 + 1;
    } while (cVar5 != '\0');
    SysFreeString(bstrString);
    pcVar10 = (char *)GetGlobalPointer("TempICFileName");
    if (pcVar10 != (char *)0x0) {
      lVar9 = 0;
      do {
        lVar25 = lVar9 + 1;
        if (pcVar10[lVar9] != "Nothing"[lVar9]) {
          strncpy(local_b58,pcVar10,0x103);
          local_a55 = 0;
          bVar7 = true;
          goto LAB_18002ea05;
        }
        lVar9 = lVar25;
      } while (lVar25 != 8);
    }
    _splitpath(param_2,local_fb8,local_548,local_648,local_348);
    _makepath(local_748,local_fb8,local_548,(char *)0x0,(char *)0x0);
    pcVar10 = &cStack_749;
    do {
      pcVar10 = pcVar10 + 1;
    } while (*pcVar10 != '\0');
    lVar9 = 0;
    do {
      cVar5 = local_648[lVar9];
      pcVar10[lVar9] = cVar5;
      lVar9 = lVar9 + 1;
    } while (cVar5 != '\0');
    pcVar10 = &cStack_749;
    do {
      pcVar23 = pcVar10;
      pcVar10 = pcVar23 + 1;
    } while (*pcVar10 != '\0');
    *(undefined4 *)pcVar10 = DAT_1800425b8;
    *(undefined2 *)(pcVar23 + 5) = DAT_1800425bc;
    pcVar10 = &cStack_749;
    do {
      pcVar10 = pcVar10 + 1;
    } while (*pcVar10 != '\0');
    lVar9 = 0;
    do {
      cVar5 = local_a48[lVar9];
      pcVar10[lVar9] = cVar5;
      lVar9 = lVar9 + 1;
    } while (cVar5 != '\0');
    _makepath(local_b58,(char *)0x0,local_748,local_a48,"szp");
    pvVar11 = FindFirstFileA(local_b58,&local_c98);
    if (pvVar11 == (HANDLE)0xffffffffffffffff) {
      _splitpath((char *)param_3,local_fb8,local_548,local_648,local_348);
      _makepath(local_748,local_fb8,local_548,(char *)0x0,(char *)0x0);
      pcVar10 = &cStack_749;
      do {
        pcVar10 = pcVar10 + 1;
      } while (*pcVar10 != '\0');
      lVar9 = 0;
      do {
        cVar5 = local_648[lVar9];
        pcVar10[lVar9] = cVar5;
        lVar9 = lVar9 + 1;
      } while (cVar5 != '\0');
      pcVar10 = &cStack_749;
      do {
        pcVar23 = pcVar10;
        pcVar10 = pcVar23 + 1;
      } while (*pcVar10 != '\0');
      *(undefined4 *)pcVar10 = DAT_1800425b8;
      *(undefined2 *)(pcVar23 + 5) = DAT_1800425bc;
      pcVar10 = &cStack_749;
      do {
        pcVar10 = pcVar10 + 1;
      } while (*pcVar10 != '\0');
      lVar9 = 0;
      do {
        cVar5 = local_a48[lVar9];
        pcVar10[lVar9] = cVar5;
        lVar9 = lVar9 + 1;
      } while (cVar5 != '\0');
      _makepath(local_b58,(char *)0x0,local_748,local_a48,"szp");
    }
LAB_18002ea05:
    if (local_e48 != local_e40) {
      free(local_e48);
    }
  }
  else {
    pOVar6 = *(OLECHAR **)(lVar9 + 8);
    plVar17 = operator_new(0x18);
    local_f68 = plVar17;
    if (plVar17 == (longlong *)0x0) {
      plVar17 = (longlong *)0x0;
    }
    else {
      plVar17[1] = 0;
      *(undefined4 *)(plVar17 + 2) = 1;
      pOVar15 = SysAllocString(pOVar6);
      *plVar17 = (longlong)pOVar15;
      if ((pOVar15 == (BSTR)0x0) && (pOVar6 != (OLECHAR *)0x0)) {
                    /* WARNING: Subroutine does not return */
        FUN_180034a60(0x8007000e);
      }
    }
    local_f08 = plVar17;
    if (plVar17 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_180034a60(0x8007000e);
    }
    pOVar6 = *(OLECHAR **)(lVar9 + 0x10);
    plVar12 = operator_new(0x18);
    local_f68 = plVar12;
    if (plVar12 == (longlong *)0x0) {
      plVar12 = (longlong *)0x0;
    }
    else {
      plVar12[1] = 0;
      *(undefined4 *)(plVar12 + 2) = 1;
      pOVar15 = SysAllocString(pOVar6);
      *plVar12 = (longlong)pOVar15;
      if ((pOVar15 == (BSTR)0x0) && (pOVar6 != (OLECHAR *)0x0)) {
                    /* WARNING: Subroutine does not return */
        FUN_180034a60(0x8007000e);
      }
    }
    local_f28 = plVar12;
    if (plVar12 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_180034a60(0x8007000e);
    }
    pOVar6 = *(OLECHAR **)(lVar9 + 0x18);
    plVar13 = operator_new(0x18);
    local_f68 = plVar13;
    if (plVar13 == (longlong *)0x0) {
      plVar13 = (longlong *)0x0;
    }
    else {
      plVar13[1] = 0;
      *(undefined4 *)(plVar13 + 2) = 1;
      pOVar15 = SysAllocString(pOVar6);
      *plVar13 = (longlong)pOVar15;
      if ((pOVar15 == (BSTR)0x0) && (pOVar6 != (OLECHAR *)0x0)) {
                    /* WARNING: Subroutine does not return */
        FUN_180034a60(0x8007000e);
      }
    }
    local_f20 = plVar13;
    if (plVar13 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_180034a60(0x8007000e);
    }
    local_ed8 = local_ed0;
    FUN_18000d880(&local_ed8,(LPCWSTR)*plVar17,0);
    local_db8 = local_db0;
    FUN_18000d880(&local_db8,(LPCWSTR)*plVar12,0);
    local_d28 = local_d20;
    FUN_18000d880(&local_d28,(LPCWSTR)*plVar13,0);
    pcVar10 = local_d28;
    do {
      cVar5 = *pcVar10;
      pcVar10[(longlong)(local_a48 + -(longlong)local_d28)] = cVar5;
      pcVar10 = pcVar10 + 1;
    } while (cVar5 != '\0');
    pcVar10 = local_ed8;
    do {
      cVar5 = *pcVar10;
      pcVar10[(longlong)(local_b58 + -(longlong)local_ed8)] = cVar5;
      pcVar10 = pcVar10 + 1;
    } while (cVar5 != '\0');
    pcVar10 = &local_c98.field_0x13f;
    do {
      pcVar10 = pcVar10 + 1;
    } while (*pcVar10 != '\0');
    *(undefined2 *)pcVar10 = DAT_1800409c4;
    pcVar10 = &local_c98.field_0x13f;
    do {
      pcVar10 = pcVar10 + 1;
    } while (*pcVar10 != '\0');
    lVar9 = 0;
    do {
      cVar5 = local_db8[lVar9];
      pcVar10[lVar9] = cVar5;
      lVar9 = lVar9 + 1;
    } while (cVar5 != '\0');
    pcVar10 = &local_c98.field_0x13f;
    do {
      pcVar10 = pcVar10 + 1;
    } while (*pcVar10 != '\0');
    *(undefined2 *)pcVar10 = DAT_1800409c4;
    pcVar10 = &local_c98.field_0x13f;
    do {
      pcVar10 = pcVar10 + 1;
    } while (*pcVar10 != '\0');
    lVar9 = 0;
    do {
      cVar5 = local_d28[lVar9];
      pcVar10[lVar9] = cVar5;
      lVar9 = lVar9 + 1;
    } while (cVar5 != '\0');
    lVar9 = 0;
    do {
      pcVar10 = local_b58 + lVar9;
      local_748[lVar9] = *pcVar10;
      lVar9 = lVar9 + 1;
    } while (*pcVar10 != '\0');
    pcVar10 = &local_c98.field_0x13f;
    do {
      pcVar10 = pcVar10 + 1;
    } while (*pcVar10 != '\0');
    *(undefined2 *)pcVar10 = DAT_1800409c4;
    pcVar10 = &local_c98.field_0x13f;
    do {
      pcVar10 = pcVar10 + 1;
    } while (*pcVar10 != '\0');
    lVar9 = 0;
    do {
      cVar5 = local_d28[lVar9];
      pcVar10[lVar9] = cVar5;
      lVar9 = lVar9 + 1;
    } while (cVar5 != '\0');
    pcVar10 = &local_c98.field_0x13f;
    do {
      pcVar23 = pcVar10;
      pcVar10 = pcVar23 + 1;
    } while (*pcVar10 != '\0');
    *(undefined4 *)pcVar10 = DAT_1800425c4;
    pcVar23[5] = DAT_1800425c8;
    if (local_d28 != local_d20) {
      free(local_d28);
    }
    if (local_db8 != local_db0) {
      free(local_db8);
    }
    if (local_ed8 != local_ed0) {
      free(local_ed8);
    }
    LOCK();
    plVar1 = plVar13 + 2;
    lVar9 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    if ((int)lVar9 == 1) {
      if ((BSTR)*plVar13 != (BSTR)0x0) {
        SysFreeString((BSTR)*plVar13);
        *plVar13 = 0;
      }
      if ((void *)plVar13[1] != (void *)0x0) {
        operator_delete__((void *)plVar13[1]);
        plVar13[1] = 0;
      }
      FUN_180035134(plVar13);
    }
    LOCK();
    plVar13 = plVar12 + 2;
    lVar9 = *plVar13;
    *(int *)plVar13 = (int)*plVar13 + -1;
    UNLOCK();
    if ((int)lVar9 == 1) {
      if ((BSTR)*plVar12 != (BSTR)0x0) {
        SysFreeString((BSTR)*plVar12);
        *plVar12 = 0;
      }
      if ((void *)plVar12[1] != (void *)0x0) {
        operator_delete__((void *)plVar12[1]);
        plVar12[1] = 0;
      }
      FUN_180035134(plVar12);
    }
    LOCK();
    plVar12 = plVar17 + 2;
    lVar9 = *plVar12;
    *(int *)plVar12 = (int)*plVar12 + -1;
    UNLOCK();
    if ((int)lVar9 == 1) {
      if ((BSTR)*plVar17 != (BSTR)0x0) {
        SysFreeString((BSTR)*plVar17);
        *plVar17 = 0;
      }
      if ((void *)plVar17[1] != (void *)0x0) {
        operator_delete__((void *)plVar17[1]);
        plVar17[1] = 0;
      }
      FUN_180035134(plVar17);
    }
    param_3 = local_fa8;
  }
  pvVar11 = FindFirstFileA(local_b58,&local_c98);
  puVar14 = operator_new(0x18);
  if (puVar14 == (undefined8 *)0x0) {
    puVar14 = (undefined8 *)0x0;
  }
  else {
    puVar14[1] = 0;
    *(undefined4 *)(puVar14 + 2) = 1;
    local_f90 = puVar14;
    pOVar15 = FUN_180034c50(local_b58);
    *puVar14 = pOVar15;
  }
  local_f90 = puVar14;
  local_f18 = puVar14;
  if (puVar14 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_180034a60(0x8007000e);
  }
  if (pvVar11 == (HANDLE)0xffffffffffffffff) {
    lVar9 = 0;
    do {
      pcVar10 = local_648 + lVar9;
      local_948[lVar9] = *pcVar10;
      lVar9 = lVar9 + 1;
    } while (*pcVar10 != '\0');
    pcVar10 = &cStack_949;
    do {
      pcVar23 = pcVar10;
      pcVar10 = pcVar23 + 1;
    } while (*pcVar10 != '\0');
    *(undefined4 *)pcVar10 = DAT_1800425b8;
    *(undefined2 *)(pcVar23 + 5) = DAT_1800425bc;
    pcVar10 = &cStack_949;
    do {
      pcVar10 = pcVar10 + 1;
    } while (*pcVar10 != '\0');
    lVar9 = 0;
    do {
      cVar5 = local_a48[lVar9];
      pcVar10[lVar9] = cVar5;
      lVar9 = lVar9 + 1;
    } while (cVar5 != '\0');
    pcVar10 = &cStack_949;
    do {
      pcVar10 = pcVar10 + 1;
    } while (*pcVar10 != '\0');
    *(undefined2 *)pcVar10 = DAT_1800409c4;
    pcVar10 = &cStack_949;
    do {
      pcVar10 = pcVar10 + 1;
    } while (*pcVar10 != '\0');
    lVar9 = 0;
    do {
      cVar5 = local_a48[lVar9];
      pcVar10[lVar9] = cVar5;
      lVar9 = lVar9 + 1;
    } while (cVar5 != '\0');
    pcVar10 = &cStack_949;
    do {
      pcVar23 = pcVar10;
      pcVar10 = pcVar23 + 1;
    } while (*pcVar10 != '\0');
    *(undefined4 *)pcVar10 = DAT_1800425c4;
    pcVar23[5] = DAT_1800425c8;
    puVar16 = operator_new(0x18);
    local_fb0 = (IUnknown *)puVar16;
    if (puVar16 == (undefined8 *)0x0) {
      puVar16 = (undefined8 *)0x0;
    }
    else {
      puVar16[1] = 0;
      *(undefined4 *)(puVar16 + 2) = 1;
      pOVar15 = FUN_180034c50(local_948);
      *puVar16 = pOVar15;
    }
    pIVar26 = local_fa0;
    local_f00 = puVar16;
    if (puVar16 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_180034a60(0x8007000e);
    }
    LOCK();
    *(int *)(puVar16 + 2) = *(int *)(puVar16 + 2) + 1;
    UNLOCK();
    local_f48 = puVar16;
    FUN_180026570(local_fa0,&local_f48);
    LOCK();
    piVar2 = (int *)(puVar16 + 2);
    iVar4 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar4 == 1) {
      if ((BSTR)*puVar16 != (BSTR)0x0) {
        SysFreeString((BSTR)*puVar16);
        *puVar16 = 0;
      }
      if ((void *)puVar16[1] != (void *)0x0) {
        operator_delete__((void *)puVar16[1]);
        puVar16[1] = 0;
      }
      FUN_180035134(puVar16);
    }
  }
  else {
    FindClose(pvVar11);
    pcVar10 = local_248;
    _splitpath((char *)param_3,local_f80,local_148,local_448,pcVar10);
    lVar9 = 0;
    do {
      pcVar23 = local_448 + lVar9;
      local_848[lVar9] = *pcVar23;
      lVar9 = lVar9 + 1;
    } while (*pcVar23 != '\0');
    pcVar23 = &cStack_849;
    do {
      pcVar24 = pcVar23;
      pcVar23 = pcVar24 + 1;
    } while (*pcVar23 != '\0');
    *(undefined4 *)pcVar23 = DAT_1800425b8;
    *(undefined2 *)(pcVar24 + 5) = DAT_1800425bc;
    pcVar23 = &cStack_849;
    do {
      pcVar23 = pcVar23 + 1;
    } while (*pcVar23 != '\0');
    lVar9 = 0;
    do {
      cVar5 = local_a48[lVar9];
      pcVar23[lVar9] = cVar5;
      lVar9 = lVar9 + 1;
    } while (cVar5 != '\0');
    pcVar23 = &cStack_849;
    do {
      pcVar23 = pcVar23 + 1;
    } while (*pcVar23 != '\0');
    *(undefined2 *)pcVar23 = DAT_1800409c4;
    pcVar23 = &cStack_849;
    do {
      pcVar23 = pcVar23 + 1;
    } while (*pcVar23 != '\0');
    lVar9 = 0;
    do {
      cVar5 = local_a48[lVar9];
      pcVar23[lVar9] = cVar5;
      lVar9 = lVar9 + 1;
    } while (cVar5 != '\0');
    pcVar23 = &cStack_849;
    do {
      pcVar24 = pcVar23;
      pcVar23 = pcVar24 + 1;
    } while (*pcVar23 != '\0');
    *(undefined4 *)pcVar23 = DAT_1800425c4;
    pcVar24[5] = DAT_1800425c8;
    puVar16 = operator_new(0x18);
    if (puVar16 == (undefined8 *)0x0) {
      puVar16 = (undefined8 *)0x0;
    }
    else {
      puVar16[1] = 0;
      *(undefined4 *)(puVar16 + 2) = 1;
      pOVar15 = FUN_180034c50(local_848);
      *puVar16 = pOVar15;
    }
    local_f10 = puVar16;
    if (puVar16 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_180034a60(0x8007000e);
    }
    LOCK();
    *(int *)(puVar16 + 2) = *(int *)(puVar16 + 2) + 1;
    UNLOCK();
    local_f60 = puVar16;
    FUN_180026570(local_fa0,&local_f60);
    LOCK();
    *(int *)(puVar16 + 2) = *(int *)(puVar16 + 2) + 1;
    UNLOCK();
    local_f70 = puVar16;
    local_f58 = operator_new(0x18);
    local_fb0 = (IUnknown *)local_f58;
    if (local_f58 == (undefined8 *)0x0) {
      local_f58 = (undefined8 *)0x0;
    }
    else {
      local_f58[1] = 0;
      *(undefined4 *)(local_f58 + 2) = 1;
      pOVar15 = FUN_180034c50("");
      *local_f58 = pOVar15;
    }
    pIVar26 = local_fa0;
    if (local_f58 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_180034a60(0x8007000e);
    }
    LOCK();
    *(int *)(puVar14 + 2) = *(int *)(puVar14 + 2) + 1;
    UNLOCK();
    local_f50 = puVar14;
    plVar17 = FUN_180026190(local_fa0,&local_f30,&local_f50,&local_f58,
                            CONCAT62((int6)((ulonglong)pcVar10 >> 0x10),(ushort)local_fc8),
                            &local_f70);
    plVar17 = (longlong *)*plVar17;
    if (plVar17 != (longlong *)0x0) {
      (**(code **)(*plVar17 + 8))(plVar17);
      local_f78 = plVar17;
    }
    if (local_f30 != (longlong *)0x0) {
      (**(code **)(*local_f30 + 0x10))();
    }
    bVar8 = true;
    LOCK();
    piVar2 = (int *)(puVar16 + 2);
    iVar4 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar4 == 1) {
      if ((BSTR)*puVar16 != (BSTR)0x0) {
        SysFreeString((BSTR)*puVar16);
        *puVar16 = 0;
      }
      if ((void *)puVar16[1] != (void *)0x0) {
        operator_delete__((void *)puVar16[1]);
        puVar16[1] = 0;
      }
      FUN_180035134(puVar16);
    }
  }
  pIVar20 = local_fa8;
  if (bVar7) {
    pcVar10 = strstr(local_b58,".szp");
    if (pcVar10 != (char *)0x0) {
      *(undefined4 *)pcVar10 = DAT_1800425cc;
      pcVar10[4] = DAT_1800425d0;
    }
  }
  else {
    _makepath(local_b58,(char *)0x0,local_748,local_a48,"izp");
  }
  ppIVar18 = operator_new(0x18);
  local_fb0 = (IUnknown *)ppIVar18;
  if (ppIVar18 == (IUnknown **)0x0) {
    ppIVar18 = (IUnknown **)0x0;
  }
  else {
    ppIVar18[1] = (IUnknown *)0x0;
    *(undefined4 *)(ppIVar18 + 2) = 1;
    pIVar19 = (IUnknown *)FUN_180034c50(local_b58);
    *ppIVar18 = pIVar19;
  }
  local_fa0 = (IUnknown *)ppIVar18;
  local_ef8 = ppIVar18;
  if (ppIVar18 == (IUnknown **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_180034a60(0x8007000e);
  }
  if (bVar8) {
    pvVar11 = FindFirstFileA(local_b58,&local_c98);
    if (pvVar11 != (HANDLE)0xffffffffffffffff) {
      FindClose(pvVar11);
      pcVar10 = local_248;
      _splitpath((char *)pIVar20,local_f80,local_148,local_448,pcVar10);
      lVar9 = 0;
      do {
        pcVar23 = local_448 + lVar9;
        local_848[lVar9] = *pcVar23;
        lVar9 = lVar9 + 1;
      } while (*pcVar23 != '\0');
      pcVar23 = &cStack_849;
      do {
        pcVar24 = pcVar23;
        pcVar23 = pcVar24 + 1;
      } while (*pcVar23 != '\0');
      *(undefined4 *)pcVar23 = DAT_1800425b8;
      *(undefined2 *)(pcVar24 + 5) = DAT_1800425bc;
      pcVar23 = &cStack_849;
      do {
        pcVar23 = pcVar23 + 1;
      } while (*pcVar23 != '\0');
      lVar9 = 0;
      do {
        cVar5 = local_a48[lVar9];
        pcVar23[lVar9] = cVar5;
        lVar9 = lVar9 + 1;
      } while (cVar5 != '\0');
      pcVar23 = &cStack_849;
      do {
        pcVar23 = pcVar23 + 1;
      } while (*pcVar23 != '\0');
      *(undefined2 *)pcVar23 = DAT_1800409c4;
      pcVar23 = &cStack_849;
      do {
        pcVar23 = pcVar23 + 1;
      } while (*pcVar23 != '\0');
      lVar9 = 0;
      do {
        cVar5 = local_a48[lVar9];
        pcVar23[lVar9] = cVar5;
        lVar9 = lVar9 + 1;
      } while (cVar5 != '\0');
      pcVar23 = &cStack_849;
      do {
        pcVar24 = pcVar23;
        pcVar23 = pcVar24 + 1;
      } while (*pcVar23 != '\0');
      *(undefined4 *)pcVar23 = DAT_1800425cc;
      pcVar24[5] = DAT_1800425d0;
      pIVar20 = operator_new(0x18);
      local_fb0 = pIVar20;
      if (pIVar20 == (IUnknown *)0x0) {
        pIVar20 = (IUnknown *)0x0;
      }
      else {
        pIVar20[1].lpVtbl = (IUnknownVtbl *)0x0;
        *(undefined4 *)&pIVar20[2].lpVtbl = 1;
        pIVar21 = (IUnknownVtbl *)FUN_180034c50(local_848);
        pIVar20->lpVtbl = pIVar21;
      }
      local_ef0 = pIVar20;
      if (pIVar20 == (IUnknown *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_180034a60(0x8007000e);
      }
      LOCK();
      *(int *)&pIVar20[2].lpVtbl = *(int *)&pIVar20[2].lpVtbl + 1;
      UNLOCK();
      local_f88 = pIVar20;
      FUN_180026570(pIVar26,&local_f88);
      local_fb0 = (IUnknown *)&local_f98;
      LOCK();
      *(int *)&pIVar20[2].lpVtbl = *(int *)&pIVar20[2].lpVtbl + 1;
      UNLOCK();
      local_f98 = pIVar20;
      pIVar19 = operator_new(0x18);
      if (pIVar19 == (IUnknown *)0x0) {
        pIVar19 = (IUnknown *)0x0;
      }
      else {
        pIVar19[1].lpVtbl = (IUnknownVtbl *)0x0;
        *(undefined4 *)&pIVar19[2].lpVtbl = 1;
        pIVar21 = (IUnknownVtbl *)FUN_180034c50("");
        pIVar19->lpVtbl = pIVar21;
      }
      local_fa8 = pIVar19;
      if (pIVar19 == (IUnknown *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_180034a60(0x8007000e);
      }
      LOCK();
      *(int *)(ppIVar18 + 2) = *(int *)(ppIVar18 + 2) + 1;
      UNLOCK();
      local_f40 = ppIVar18;
      puVar16 = FUN_180026190(pIVar26,&local_f68,&local_f40,&local_fa8,
                              CONCAT62((int6)((ulonglong)pcVar10 >> 0x10),(ushort)local_fc8),
                              &local_f98);
      plVar12 = local_f78;
      plVar17 = (longlong *)*puVar16;
      if (local_f78 != plVar17) {
        if (plVar17 != (longlong *)0x0) {
          (**(code **)(*plVar17 + 8))(plVar17);
        }
        local_f78 = plVar17;
        if (plVar12 != (longlong *)0x0) {
          (**(code **)(*plVar12 + 0x10))(plVar12);
        }
      }
      if (local_f68 != (longlong *)0x0) {
        (**(code **)(*local_f68 + 0x10))();
      }
      LOCK();
      pIVar26 = pIVar20 + 2;
      iVar4 = *(int *)&pIVar26->lpVtbl;
      *(int *)&pIVar26->lpVtbl = *(int *)&pIVar26->lpVtbl + -1;
      UNLOCK();
      if (iVar4 == 1) {
        if (pIVar20->lpVtbl != (IUnknownVtbl *)0x0) {
          SysFreeString((BSTR)pIVar20->lpVtbl);
          pIVar20->lpVtbl = (IUnknownVtbl *)0x0;
        }
        if (pIVar20[1].lpVtbl != (IUnknownVtbl *)0x0) {
          operator_delete__(pIVar20[1].lpVtbl);
          pIVar20[1].lpVtbl = (IUnknownVtbl *)0x0;
        }
        FUN_180035134(pIVar20);
      }
    }
  }
  else {
    lVar9 = 0;
    do {
      pcVar10 = local_648 + lVar9;
      local_948[lVar9] = *pcVar10;
      lVar9 = lVar9 + 1;
    } while (*pcVar10 != '\0');
    pcVar10 = &cStack_949;
    do {
      pcVar23 = pcVar10;
      pcVar10 = pcVar23 + 1;
    } while (*pcVar10 != '\0');
    *(undefined4 *)pcVar10 = DAT_1800425b8;
    *(undefined2 *)(pcVar23 + 5) = DAT_1800425bc;
    pcVar10 = &cStack_949;
    do {
      pcVar10 = pcVar10 + 1;
    } while (*pcVar10 != '\0');
    lVar9 = 0;
    do {
      cVar5 = local_a48[lVar9];
      pcVar10[lVar9] = cVar5;
      lVar9 = lVar9 + 1;
    } while (cVar5 != '\0');
    pcVar10 = &cStack_949;
    do {
      pcVar10 = pcVar10 + 1;
    } while (*pcVar10 != '\0');
    *(undefined2 *)pcVar10 = DAT_1800409c4;
    pcVar10 = &cStack_949;
    do {
      pcVar10 = pcVar10 + 1;
    } while (*pcVar10 != '\0');
    lVar9 = 0;
    do {
      cVar5 = local_a48[lVar9];
      pcVar10[lVar9] = cVar5;
      lVar9 = lVar9 + 1;
    } while (cVar5 != '\0');
    pcVar10 = &cStack_949;
    do {
      pcVar23 = pcVar10;
      pcVar10 = pcVar23 + 1;
    } while (*pcVar10 != '\0');
    *(undefined4 *)pcVar10 = DAT_1800425cc;
    pcVar23[5] = DAT_1800425d0;
    ppIVar22 = operator_new(0x18);
    local_fb0 = (IUnknown *)ppIVar22;
    if (ppIVar22 == (IUnknown **)0x0) {
      ppIVar22 = (IUnknown **)0x0;
    }
    else {
      ppIVar22[1] = (IUnknown *)0x0;
      *(undefined4 *)(ppIVar22 + 2) = 1;
      pIVar20 = (IUnknown *)FUN_180034c50(local_948);
      *ppIVar22 = pIVar20;
    }
    local_ee8 = ppIVar22;
    if (ppIVar22 == (IUnknown **)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_180034a60(0x8007000e);
    }
    LOCK();
    *(int *)(ppIVar22 + 2) = *(int *)(ppIVar22 + 2) + 1;
    UNLOCK();
    local_f38 = ppIVar22;
    FUN_180026570(pIVar26,&local_f38);
    LOCK();
    ppIVar3 = ppIVar22 + 2;
    iVar4 = *(int *)ppIVar3;
    *(int *)ppIVar3 = *(int *)ppIVar3 + -1;
    UNLOCK();
    if (iVar4 == 1) {
      if (*ppIVar22 != (IUnknown *)0x0) {
        SysFreeString((BSTR)*ppIVar22);
        *ppIVar22 = (IUnknown *)0x0;
      }
      if (ppIVar22[1] != (IUnknown *)0x0) {
        operator_delete__(ppIVar22[1]);
        ppIVar22[1] = (IUnknown *)0x0;
      }
      FUN_180035134(ppIVar22);
    }
  }
  LOCK();
  ppIVar22 = ppIVar18 + 2;
  iVar4 = *(int *)ppIVar22;
  *(int *)ppIVar22 = *(int *)ppIVar22 + -1;
  UNLOCK();
  if (iVar4 == 1) {
    if (*ppIVar18 != (IUnknown *)0x0) {
      SysFreeString((BSTR)*ppIVar18);
      *ppIVar18 = (IUnknown *)0x0;
    }
    if (ppIVar18[1] != (IUnknown *)0x0) {
      operator_delete__(ppIVar18[1]);
      ppIVar18[1] = (IUnknown *)0x0;
    }
    FUN_180035134(ppIVar18);
  }
  LOCK();
  piVar2 = (int *)(puVar14 + 2);
  iVar4 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  if (iVar4 == 1) {
    if ((BSTR)*puVar14 != (BSTR)0x0) {
      SysFreeString((BSTR)*puVar14);
      *puVar14 = 0;
    }
    if ((void *)puVar14[1] != (void *)0x0) {
      operator_delete__((void *)puVar14[1]);
      puVar14[1] = 0;
    }
    FUN_180035134(puVar14);
  }
  if (local_f78 != (longlong *)0x0) {
    (**(code **)(*local_f78 + 0x10))();
  }
  return 1;
}

/* RVA 0x2fa70 */
undefined8 FUN_18002fa70(IUnknown *param_1,char *param_2,char *param_3)

{
  int *piVar1;
  OLECHAR *psz;
  longlong *plVar2;
  int iVar3;
  ULONG UVar4;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  BSTR pOVar8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar9;
  undefined8 *puVar10;
  char *pcVar11;
  char *pcVar12;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res18 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res20 [8];
  LPCSTR local_d0;
  LPCSTR local_c8;
  undefined8 *local_c0;
  undefined8 *local_b8;
  undefined8 *local_b0;
  longlong *local_a8;
  undefined8 **local_a0;
  undefined8 *local_98;
  longlong *local_90;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_88 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_80 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_78 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_70 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_68 [8];
  undefined8 *local_60;
  undefined8 **local_58;
  undefined8 **local_50;
  undefined8 local_48 [4];
  
  local_a8 = (longlong *)0x0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_1800540b8,param_2
            );
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_1800540b8,'\\');
  pCVar5 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                     ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                      &DAT_1800540b8,(int)local_88);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_1800540b8,pCVar5)
  ;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_88);
  if (param_3 == (char *)0x0) {
    ATL::CSimpleStringT<char,1>::Empty((CSimpleStringT<char,1> *)&DAT_180054088);
  }
  else {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_180054088,
               param_3);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_180054088,'\\')
    ;
    pCVar5 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                       ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                        &DAT_180054088,(int)local_80);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_180054088,
               pCVar5);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_80);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18,param_2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_c8,param_3);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind(local_res18,'.');
  pCVar5 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                     (local_res18,(int)local_78);
  pCVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                     (local_res18,pCVar5);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(local_res20,pCVar5);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_78);
  uVar6 = FUN_180029600("roottype");
  if ((int)uVar6 == 1) {
    iVar3 = FUN_180033bd0();
    pcVar11 = ".apw";
    pcVar12 = ".aprop";
  }
  else {
    iVar3 = FUN_180033bd0();
    pcVar11 = ".bkp";
    pcVar12 = ".aprbkp";
  }
  if (iVar3 == 1) {
    pcVar12 = pcVar11;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
            (local_res18,pcVar12);
  UVar4 = (*param_1->lpVtbl[4].AddRef)(param_1);
  if ((int)UVar4 < 0) {
    _com_issue_errorex(UVar4,param_1,(_GUID *)&DAT_1800424d8);
  }
  puVar7 = operator_new(0x18);
  if (puVar7 == (undefined8 *)0x0) {
    puVar7 = (undefined8 *)0x0;
  }
  else {
    puVar7[1] = 0;
    *(undefined4 *)(puVar7 + 2) = 1;
    *puVar7 = 0;
  }
  if (puVar7 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_180034a60(0x8007000e);
  }
  psz = (OLECHAR *)*puVar7;
  LOCK();
  piVar1 = (int *)(puVar7 + 2);
  iVar3 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar3 == 1) {
    if ((BSTR)*puVar7 != (BSTR)0x0) {
      SysFreeString((BSTR)*puVar7);
      *puVar7 = 0;
    }
    if ((void *)puVar7[1] != (void *)0x0) {
      operator_delete__((void *)puVar7[1]);
      puVar7[1] = 0;
    }
    FUN_180035134(puVar7);
  }
  if (psz != (OLECHAR *)0x0) {
    local_98 = operator_new(0x18);
    if (local_98 == (undefined8 *)0x0) {
      local_98 = (undefined8 *)0x0;
    }
    else {
      local_98[1] = 0;
      *(undefined4 *)(local_98 + 2) = 1;
      pOVar8 = SysAllocString(psz);
      *local_98 = pOVar8;
      if (pOVar8 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_180034a60(0x8007000e);
      }
    }
    if (local_98 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_180034a60(0x8007000e);
    }
    FUN_180026570(param_1,&local_98);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d0,
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             local_res18);
  iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d0,'\\'
                    );
  if (0 < iVar3) {
    pCVar5 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                       ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d0,
                        (int)local_70);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d0,pCVar5);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_70);
  }
  pCVar9 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
           CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                     (local_68,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                *)&local_c8);
  uVar6 = FUN_1800323f0(pCVar9);
  if ((int)uVar6 != 0) {
    FUN_180025880(local_48,"File Size is 0");
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_48,(ThrowInfo *)&DAT_180049220);
  }
  puVar7 = operator_new(0x18);
  if (puVar7 == (undefined8 *)0x0) {
    puVar7 = (undefined8 *)0x0;
  }
  else {
    puVar7[1] = 0;
    *(undefined4 *)(puVar7 + 2) = 1;
    pOVar8 = FUN_180034c50(local_d0);
    *puVar7 = pOVar8;
  }
  if (puVar7 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_180034a60(0x8007000e);
  }
  puVar10 = operator_new(0x18);
  if (puVar10 == (undefined8 *)0x0) {
    puVar10 = (undefined8 *)0x0;
  }
  else {
    puVar10[1] = 0;
    *(undefined4 *)(puVar10 + 2) = 1;
    local_60 = puVar10;
    pOVar8 = FUN_180034c50(local_c8);
    *puVar10 = pOVar8;
  }
  local_60 = puVar10;
  if (puVar10 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_180034a60(0x8007000e);
  }
  local_b0 = operator_new(0x18);
  local_a0 = (undefined8 **)local_b0;
  if (local_b0 == (undefined8 *)0x0) {
    local_b0 = (undefined8 *)0x0;
  }
  else {
    local_b0[1] = 0;
    *(undefined4 *)(local_b0 + 2) = 1;
    pOVar8 = FUN_180034c50("");
    *local_b0 = pOVar8;
  }
  if (local_b0 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_180034a60(0x8007000e);
  }
  local_a0 = &local_b0;
  LOCK();
  *(int *)(puVar10 + 2) = *(int *)(puVar10 + 2) + 1;
  UNLOCK();
  local_58 = &local_b8;
  LOCK();
  *(int *)(puVar7 + 2) = *(int *)(puVar7 + 2) + 1;
  UNLOCK();
  local_50 = &local_c0;
  local_90 = (longlong *)0x0;
  local_c0 = puVar7;
  local_b8 = puVar10;
  UVar4 = (*param_1->lpVtbl[6].Release)(param_1);
  if ((int)UVar4 < 0) {
    _com_issue_errorex(UVar4,param_1,(_GUID *)&DAT_1800424d8);
  }
  plVar2 = local_90;
  FUN_18001ccd0(&local_c0);
  FUN_18001ccd0(&local_b8);
  FUN_18001ccd0(&local_b0);
  if (plVar2 != (longlong *)0x0) {
    (**(code **)(*plVar2 + 8))(plVar2);
    local_a8 = plVar2;
    (**(code **)(*plVar2 + 0x10))(plVar2);
  }
  LOCK();
  piVar1 = (int *)(puVar10 + 2);
  iVar3 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (local_a8 == (longlong *)0x0) {
    if (iVar3 == 1) {
      if ((BSTR)*puVar10 != (BSTR)0x0) {
        SysFreeString((BSTR)*puVar10);
        *puVar10 = 0;
      }
      if ((void *)puVar10[1] != (void *)0x0) {
        operator_delete__((void *)puVar10[1]);
        puVar10[1] = 0;
      }
      FUN_180035134(puVar10);
    }
    LOCK();
    piVar1 = (int *)(puVar7 + 2);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      if ((BSTR)*puVar7 != (BSTR)0x0) {
        SysFreeString((BSTR)*puVar7);
        *puVar7 = 0;
      }
      if ((void *)puVar7[1] != (void *)0x0) {
        operator_delete__((void *)puVar7[1]);
        puVar7[1] = 0;
      }
      FUN_180035134(puVar7);
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d0);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_c8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
    uVar6 = 0;
  }
  else {
    if (iVar3 == 1) {
      if ((BSTR)*puVar10 != (BSTR)0x0) {
        SysFreeString((BSTR)*puVar10);
        *puVar10 = 0;
      }
      if ((void *)puVar10[1] != (void *)0x0) {
        operator_delete__((void *)puVar10[1]);
        puVar10[1] = 0;
      }
      FUN_180035134(puVar10);
    }
    LOCK();
    piVar1 = (int *)(puVar7 + 2);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      if ((BSTR)*puVar7 != (BSTR)0x0) {
        SysFreeString((BSTR)*puVar7);
        *puVar7 = 0;
      }
      if ((void *)puVar7[1] != (void *)0x0) {
        operator_delete__((void *)puVar7[1]);
        puVar7[1] = 0;
      }
      FUN_180035134(puVar7);
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d0);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_c8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
    (**(code **)(*local_a8 + 0x10))();
    uVar6 = 1;
  }
  return uVar6;
}

/* RVA 0x301e0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1800301e0(IUnknown *param_1)

{
  ulong uVar1;
  LPCSTR pCVar2;
  longlong *plVar3;
  int iVar4;
  ULONG UVar5;
  HRESULT HVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  HANDLE hFindFile;
  undefined8 *puVar10;
  IAtlStringMgr *pIVar11;
  undefined8 uVar12;
  FARPROC pFVar13;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar14;
  IID *pIVar15;
  BSTR pOVar16;
  IID *pIVar17;
  IID *pIVar18;
  char *pcVar19;
  IID *pIVar20;
  longlong *plVar21;
  ulonglong uVar22;
  uint uVar23;
  bool bVar24;
  undefined1 auStackY_288 [32];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_258 [8];
  LPCSTR local_250;
  uint local_248;
  IID *local_240;
  undefined2 local_238;
  LPCSTR local_230;
  undefined8 local_228;
  uint local_220;
  uint local_21c;
  int local_218;
  longlong *local_210;
  IID *local_208;
  IID *local_200;
  IID *local_1f8;
  IID *local_1f0;
  int local_1e8;
  int local_1e4;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_1e0 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_1d8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_1d0 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_1c8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_1c0 [8];
  longlong *local_1b8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_1b0 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_1a8 [8];
  ulonglong local_1a0;
  IID *local_198;
  IID *local_190;
  IID **local_188;
  IID **local_180;
  _WIN32_FIND_DATAA local_178;
  ulonglong local_38;
  
  local_38 = DAT_180052888 ^ (ulonglong)auStackY_288;
  uVar22 = 0;
  uVar23 = 0;
  local_248 = 0;
  plVar21 = (longlong *)0x0;
  local_210 = (longlong *)0x0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_250);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1c0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1c8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1d0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1d8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_228);
  uVar7 = FUN_180029600("exchangerfile");
  local_220 = (uint)uVar7;
  uVar7 = uVar7 & 0xffffffff;
  uVar8 = FUN_180029600("streamformat");
  local_21c = (uint)uVar8;
  uVar8 = uVar8 & 0xffffffff;
  uVar9 = FUN_180029600("runsettingfile");
  local_1e8 = (int)uVar9;
  uVar9 = FUN_180029600("usermodelfile");
  local_218 = (int)uVar9;
  uVar9 = FUN_180029600("fortranfile");
  local_1e4 = (int)uVar9;
  local_1a0 = DAT_180054098 - DAT_180054090 >> 5;
  do {
    while( true ) {
      if (local_1a0 <= uVar22) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_228);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1d8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1d0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1c8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1c0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_250);
        if (plVar21 != (longlong *)0x0) {
          (**(code **)(*plVar21 + 0x10))(plVar21);
        }
        return 1;
      }
      pcVar19 = (char *)(uVar22 * 0x20 + DAT_180054090);
      if (0xf < *(ulonglong *)(pcVar19 + 0x18)) {
        pcVar19 = *(char **)pcVar19;
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_250,pcVar19
                );
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_250,'.');
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_250,
                 (int)local_258);
      iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                        (local_258,"bjt");
      if ((((iVar4 == 0) ||
           (iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                    CompareNoCase(local_258,"edr"), iVar4 == 0)) ||
          (iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                             (local_258,"tai"), iVar4 == 0)) ||
         (iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                            (local_258,"ist"), iVar4 == 0)) break;
      iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                        (local_258,"apcsv");
      if ((iVar4 == 0) ||
         (iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                            (local_258,"tff"), iVar4 == 0)) {
        bVar24 = (int)uVar8 == 0;
        goto LAB_1800306f0;
      }
      iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                        (local_258,"xls");
      if (((iVar4 == 0) ||
          (iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                             (local_258,"cfg"), iVar4 == 0)) ||
         ((iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                             (local_258,"ini"), iVar4 == 0 ||
          (iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                             (local_258,"dll"), iVar4 == 0)))) {
        bVar24 = local_218 == 0;
        goto LAB_1800306f0;
      }
      iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                        (local_258,"f");
      if (((iVar4 == 0) ||
          (iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                             (local_258,"for"), iVar4 == 0)) ||
         (iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                            (local_258,"obj"), iVar4 == 0)) {
        bVar24 = local_1e4 == 0;
        goto LAB_1800306f0;
      }
      iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                        (local_258,"dlopt");
      if (((iVar4 == 0) ||
          (iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                             (local_258,"opt"), iVar4 == 0)) ||
         (((iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                    CompareNoCase(local_258,"ilb"), iVar4 == 0 ||
           ((iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                     CompareNoCase(local_258,"slb"), iVar4 == 0 ||
            (iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                     CompareNoCase(local_258,"dat"), iVar4 == 0)))) ||
          (iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                             (local_258,"def"), iVar4 == 0)))) {
        bVar24 = local_1e8 == 0;
        goto LAB_1800306f0;
      }
      iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                        (local_258,"apsst");
      if (iVar4 == 0) goto LAB_180030543;
LAB_1800306f6:
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_258);
      uVar22 = uVar22 + 1;
    }
    bVar24 = (int)uVar7 == 0;
LAB_1800306f0:
    if (bVar24) goto LAB_1800306f6;
LAB_180030543:
    hFindFile = FindFirstFileA(local_250,&local_178);
    if (hFindFile == (HANDLE)0xffffffffffffffff) {
      if (*(int *)(DAT_180054088 + -0x10) != 0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_250,'\\')
        ;
        puVar10 = (undefined8 *)
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Right
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_250,(int)local_1b0);
        pIVar11 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &DAT_180054088);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1e0,pIVar11);
        local_248 = uVar23 | 2;
        ATL::CSimpleStringT<char,1>::Concatenate
                  ((CSimpleStringT<char,1> *)local_1e0,DAT_180054088,*(int *)(DAT_180054088 + -0x10)
                   ,(char *)*puVar10,*(int *)((char *)*puVar10 + -0x10));
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1b0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_250,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   local_1e0);
        hFindFile = FindFirstFileA(local_250,&local_178);
        uVar23 = uVar23 & 0xfffffffd;
        local_248 = uVar23;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1e0);
        if (hFindFile != (HANDLE)0xffffffffffffffff) goto LAB_180030718;
      }
      pcVar19 = (char *)GetSorResStringEx(0x596);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_228,pcVar19
                 ,local_250);
      uVar9 = local_228;
      uVar12 = MVGetI18nProductName();
      if (DAT_180054080 == (HMODULE)0x0) {
        DAT_180054080 = LoadLibraryA("MMDialog.dll");
      }
      pFVar13 = GetProcAddress(DAT_180054080,"MsgBoxExImage");
      if (pFVar13 != (FARPROC)0x0) {
        (*pFVar13)(0,uVar9,uVar12,0);
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_258);
    }
    else {
LAB_180030718:
      FindClose(hFindFile);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_230,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 &local_250);
      iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_230
                         ,'\\');
      if (iVar4 != -1) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_230,'\\')
        ;
        pCVar14 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_230,(int)local_1a8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_230,
                   pCVar14);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1a8);
      }
      pCVar2 = local_230;
      pIVar15 = operator_new(0x18);
      pIVar20 = (IID *)0x0;
      local_240 = pIVar15;
      if (pIVar15 == (IID *)0x0) {
        pIVar15 = pIVar20;
      }
      else {
        pIVar15->Data4[0] = '\0';
        pIVar15->Data4[1] = '\0';
        pIVar15->Data4[2] = '\0';
        pIVar15->Data4[3] = '\0';
        pIVar15->Data4[4] = '\0';
        pIVar15->Data4[5] = '\0';
        pIVar15->Data4[6] = '\0';
        pIVar15->Data4[7] = '\0';
        pIVar15[1].Data1 = 1;
        pOVar16 = FUN_180034c50(pCVar2);
        *(BSTR *)pIVar15 = pOVar16;
      }
      pCVar2 = local_250;
      local_198 = pIVar15;
      if (pIVar15 == (IID *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_180034a60(0x8007000e);
      }
      pIVar17 = operator_new(0x18);
      local_240 = pIVar17;
      if (pIVar17 == (IID *)0x0) {
        pIVar17 = pIVar20;
      }
      else {
        pIVar17->Data4[0] = '\0';
        pIVar17->Data4[1] = '\0';
        pIVar17->Data4[2] = '\0';
        pIVar17->Data4[3] = '\0';
        pIVar17->Data4[4] = '\0';
        pIVar17->Data4[5] = '\0';
        pIVar17->Data4[6] = '\0';
        pIVar17->Data4[7] = '\0';
        pIVar17[1].Data1 = 1;
        pOVar16 = FUN_180034c50(pCVar2);
        *(BSTR *)pIVar17 = pOVar16;
      }
      local_190 = pIVar17;
      if (pIVar17 == (IID *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_180034a60(0x8007000e);
      }
      LOCK();
      pIVar15[1].Data1 = pIVar15[1].Data1 + 1;
      UNLOCK();
      local_208 = (IID *)&local_240;
      local_238 = 0;
      local_240 = pIVar15;
      UVar5 = (*param_1->lpVtbl[9].AddRef)(param_1);
      if ((int)UVar5 < 0) {
        _com_issue_errorex(UVar5,param_1,(_GUID *)&DAT_1800424d8);
      }
      FUN_18001ccd0(&local_240);
      pIVar18 = operator_new(0x18);
      local_208 = pIVar18;
      if (pIVar18 == (IID *)0x0) {
        local_1f0 = pIVar20;
      }
      else {
        pIVar18->Data4[0] = '\0';
        pIVar18->Data4[1] = '\0';
        pIVar18->Data4[2] = '\0';
        pIVar18->Data4[3] = '\0';
        pIVar18->Data4[4] = '\0';
        pIVar18->Data4[5] = '\0';
        pIVar18->Data4[6] = '\0';
        pIVar18->Data4[7] = '\0';
        pIVar18[1].Data1 = 1;
        pOVar16 = FUN_180034c50("");
        *(BSTR *)pIVar18 = pOVar16;
        local_1f0 = pIVar18;
      }
      if (local_1f0 == (IID *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_180034a60(0x8007000e);
      }
      local_208 = (IID *)&local_1f0;
      LOCK();
      pIVar17[1].Data1 = pIVar17[1].Data1 + 1;
      UNLOCK();
      local_188 = &local_1f8;
      LOCK();
      pIVar15[1].Data1 = pIVar15[1].Data1 + 1;
      UNLOCK();
      local_180 = &local_200;
      local_1b8 = (longlong *)0x0;
      if (pIVar17 == (IID *)0x0) {
        pIVar18 = pIVar20;
      }
      else {
        pIVar18 = *(IID **)pIVar17;
      }
      if (pIVar15 != (IID *)0x0) {
        pIVar20 = *(IID **)pIVar15;
      }
      local_200 = pIVar15;
      local_1f8 = pIVar17;
      HVar6 = (*param_1->lpVtbl[8].QueryInterface)(param_1,pIVar20,(void **)pIVar18);
      if (HVar6 < 0) {
        _com_issue_errorex(HVar6,param_1,(_GUID *)&DAT_1800424d8);
      }
      plVar3 = local_1b8;
      local_248 = local_248 | 1;
      FUN_18001ccd0(&local_200);
      FUN_18001ccd0(&local_1f8);
      FUN_18001ccd0(&local_1f0);
      plVar21 = local_210;
      if (local_210 != plVar3) {
        if (plVar3 != (longlong *)0x0) {
          (**(code **)(*plVar3 + 8))(plVar3);
        }
        local_210 = plVar3;
        if (plVar21 != (longlong *)0x0) {
          (**(code **)(*plVar21 + 0x10))(plVar21);
        }
      }
      if (plVar3 != (longlong *)0x0) {
        (**(code **)(*plVar3 + 0x10))(plVar3);
      }
      LOCK();
      pIVar20 = pIVar17 + 1;
      uVar1 = pIVar20->Data1;
      pIVar20->Data1 = pIVar20->Data1 - 1;
      UNLOCK();
      if (local_210 == (longlong *)0x0) {
        if (uVar1 == 1) {
          if (*(BSTR *)pIVar17 != (BSTR)0x0) {
            SysFreeString(*(BSTR *)pIVar17);
            pIVar17->Data1 = 0;
            pIVar17->Data2 = 0;
            pIVar17->Data3 = 0;
          }
          if (*(void **)pIVar17->Data4 != (void *)0x0) {
            operator_delete__(*(void **)pIVar17->Data4);
            pIVar17->Data4[0] = '\0';
            pIVar17->Data4[1] = '\0';
            pIVar17->Data4[2] = '\0';
            pIVar17->Data4[3] = '\0';
            pIVar17->Data4[4] = '\0';
            pIVar17->Data4[5] = '\0';
            pIVar17->Data4[6] = '\0';
            pIVar17->Data4[7] = '\0';
          }
          FUN_180035134(pIVar17);
        }
        LOCK();
        pIVar20 = pIVar15 + 1;
        uVar1 = pIVar20->Data1;
        pIVar20->Data1 = pIVar20->Data1 - 1;
        UNLOCK();
        if (uVar1 == 1) {
          if (*(BSTR *)pIVar15 != (BSTR)0x0) {
            SysFreeString(*(BSTR *)pIVar15);
            pIVar15->Data1 = 0;
            pIVar15->Data2 = 0;
            pIVar15->Data3 = 0;
          }
          if (*(void **)pIVar15->Data4 != (void *)0x0) {
            operator_delete__(*(void **)pIVar15->Data4);
            pIVar15->Data4[0] = '\0';
            pIVar15->Data4[1] = '\0';
            pIVar15->Data4[2] = '\0';
            pIVar15->Data4[3] = '\0';
            pIVar15->Data4[4] = '\0';
            pIVar15->Data4[5] = '\0';
            pIVar15->Data4[6] = '\0';
            pIVar15->Data4[7] = '\0';
          }
          FUN_180035134(pIVar15);
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_230);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_258);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_228);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1d8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1d0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1c8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1c0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_250);
        return 0;
      }
      if (uVar1 == 1) {
        if (*(BSTR *)pIVar17 != (BSTR)0x0) {
          SysFreeString(*(BSTR *)pIVar17);
          pIVar17->Data1 = 0;
          pIVar17->Data2 = 0;
          pIVar17->Data3 = 0;
        }
        if (*(void **)pIVar17->Data4 != (void *)0x0) {
          operator_delete__(*(void **)pIVar17->Data4);
          pIVar17->Data4[0] = '\0';
          pIVar17->Data4[1] = '\0';
          pIVar17->Data4[2] = '\0';
          pIVar17->Data4[3] = '\0';
          pIVar17->Data4[4] = '\0';
          pIVar17->Data4[5] = '\0';
          pIVar17->Data4[6] = '\0';
          pIVar17->Data4[7] = '\0';
        }
        FUN_180035134(pIVar17);
      }
      LOCK();
      pIVar20 = pIVar15 + 1;
      uVar1 = pIVar20->Data1;
      pIVar20->Data1 = pIVar20->Data1 - 1;
      UNLOCK();
      if (uVar1 == 1) {
        if (*(BSTR *)pIVar15 != (BSTR)0x0) {
          SysFreeString(*(BSTR *)pIVar15);
          pIVar15->Data1 = 0;
          pIVar15->Data2 = 0;
          pIVar15->Data3 = 0;
        }
        if (*(void **)pIVar15->Data4 != (void *)0x0) {
          operator_delete__(*(void **)pIVar15->Data4);
          pIVar15->Data4[0] = '\0';
          pIVar15->Data4[1] = '\0';
          pIVar15->Data4[2] = '\0';
          pIVar15->Data4[3] = '\0';
          pIVar15->Data4[4] = '\0';
          pIVar15->Data4[5] = '\0';
          pIVar15->Data4[6] = '\0';
          pIVar15->Data4[7] = '\0';
        }
        FUN_180035134(pIVar15);
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_230);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_258);
      plVar21 = local_210;
      uVar23 = local_248;
    }
    uVar8 = (ulonglong)local_21c;
    uVar7 = (ulonglong)local_220;
    uVar22 = uVar22 + 1;
  } while( true );
}

/* RVA 0x30cf0 */
undefined2 FUN_180030cf0(IUnknown *param_1,undefined8 *param_2)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[10].AddRef)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_1800424d8);
  }
  FUN_18001ccd0(param_2);
  return 0;
}

/* RVA 0x30d60 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined8 FUN_180030d60(byte param_1,LPCSTR param_2,longlong param_3,longlong param_4)

{
  int *piVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar2;
  char cVar3;
  _func_5158 *p_Var4;
  byte bVar5;
  short sVar6;
  IUnknown *pIVar7;
  HRESULT HVar8;
  int iVar9;
  BOOL BVar10;
  DWORD DVar11;
  ULONG UVar12;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar13;
  IAtlStringMgr *pIVar14;
  char *pcVar15;
  undefined8 *puVar16;
  BSTR pOVar17;
  undefined8 *puVar18;
  longlong *plVar19;
  longlong lVar21;
  longlong lVar20;
  undefined8 uVar22;
  ulonglong uVar23;
  IID *pIVar24;
  longlong lVar25;
  undefined1 *puVar26;
  uint uVar27;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar28;
  LPCWSTR lpWideCharStr;
  undefined *puStackY_120;
  undefined1 auStackY_118 [32];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_e0 [8];
  char *local_d8;
  byte local_d0;
  uint uStack_cc;
  char *local_c8;
  short local_c0;
  short local_bc;
  IUnknown *local_b8;
  char *local_b0;
  uchar local_a8 [8];
  undefined8 *local_a0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_98 [8];
  undefined8 *local_90;
  char *local_88;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_80 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_78 [8];
  char *local_70;
  undefined8 *local_68;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_60 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_58 [8];
  undefined8 local_50;
  undefined8 *local_48;
  undefined8 *local_40;
  ulonglong local_38;
  
  local_38 = DAT_180052888 ^ (ulonglong)&local_d8;
  pCVar28 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  uStack_cc = 0;
  local_b8 = (IUnknown *)0x0;
  local_50 = 0;
  puStackY_120 = (undefined *)0x180030dc6;
  local_d0 = param_1;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_c8);
  puStackY_120 = (undefined *)0x180030dd3;
  HVar8 = FUN_18002c9d0(&local_b8,param_2);
  if (HVar8 < 0) {
LAB_1800315d8:
    puStackY_120 = (undefined *)0x1800315e2;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_c8);
    if (local_b8 != (IUnknown *)0x0) {
      puStackY_120 = (undefined *)0x1800315f2;
      (*local_b8->lpVtbl->Release)(local_b8);
    }
    uVar22 = 1;
    puVar26 = auStackY_118;
  }
  else {
    puStackY_120 = (undefined *)0x180030de8;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8,param_2);
    puStackY_120 = (undefined *)0x180030df5;
    iVar9 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8,
                       '.');
    if (0 < iVar9) {
      puStackY_120 = (undefined *)0x180030e0d;
      pCVar13 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_d8,(int)local_58);
      puStackY_120 = (undefined *)0x180030e1b;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8,pCVar13)
      ;
      puStackY_120 = (undefined *)0x180030e29;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_58);
    }
    puStackY_120 = (undefined *)0x180030e35;
    iVar9 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8,
                       '\\');
    if (0 < iVar9) {
      puStackY_120 = (undefined *)0x180030e4a;
      pCVar13 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_d8,(int)local_60);
      puStackY_120 = (undefined *)0x180030e58;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8,pCVar13)
      ;
      puStackY_120 = (undefined *)0x180030e63;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_60);
    }
    puStackY_120 = (undefined *)0x180030e71;
    pIVar14 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         &DAT_1800540b0);
    puStackY_120 = (undefined *)0x180030e7e;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_80,pIVar14);
    uStack_cc = 2;
    puStackY_120 = (undefined *)0x180030ea6;
    ATL::CSimpleStringT<char,1>::Concatenate
              ((CSimpleStringT<char,1> *)local_80,DAT_1800540b0,*(int *)(DAT_1800540b0 + -0x10),
               local_d8,*(int *)(local_d8 + -0x10));
    puStackY_120 = (undefined *)0x180030eb4;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)local_80
              );
    uStack_cc = 0;
    puStackY_120 = (undefined *)0x180030ec3;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_80);
    puStackY_120 = (undefined *)0x180030ecf;
    BVar10 = CreateDirectoryA(local_d8,(LPSECURITY_ATTRIBUTES)0x0);
    if ((short)BVar10 == 0) {
      puStackY_120 = (undefined *)0x180030ede;
      DVar11 = GetLastError();
      if (DVar11 == 0xb7) {
        uVar27 = 1;
        puStackY_120 = (undefined *)0x180030f67;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b0);
        puStackY_120 = (undefined *)0x180030f7c;
        FUN_1800013a0((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_70,
                      (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8,"_"
                     );
        do {
          uVar23 = (ulonglong)uVar27;
          uVar27 = uVar27 + 1;
          puStackY_120 = (undefined *)0x180030f96;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b0,"%d"
                     ,uVar23);
          puStackY_120 = (undefined *)0x180030fa1;
          pIVar14 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &local_70);
          puStackY_120 = (undefined *)0x180030fae;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_78,pIVar14);
          uStack_cc = 1;
          puStackY_120 = (undefined *)0x180030fd2;
          ATL::CSimpleStringT<char,1>::Concatenate
                    ((CSimpleStringT<char,1> *)local_78,local_70,*(int *)(local_70 + -0x10),local_b0
                     ,*(int *)(local_b0 + -0x10));
          puStackY_120 = (undefined *)0x180030fe0;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8,
                     (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     local_78);
          uStack_cc = 0;
          puStackY_120 = (undefined *)0x180030ff0;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_78);
          puStackY_120 = (undefined *)0x180030ffc;
          BVar10 = CreateDirectoryA(local_d8,(LPSECURITY_ATTRIBUTES)0x0);
        } while ((short)BVar10 == 0);
        puStackY_120 = (undefined *)0x18003100f;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_70);
        puStackY_120 = (undefined *)0x18003101a;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b0);
      }
      else {
        puStackY_120 = (undefined *)0x180030ef2;
        pcVar15 = (char *)GetSorResStringEx(0x58f);
        puStackY_120 = (undefined *)0x180030f03;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_c8,
                   pcVar15,local_d8);
        puStackY_120 = (undefined *)0x180030f2b;
        DVar11 = FormatMessageA(0x1100,(LPCVOID)0x0,DVar11,0x409,(LPSTR)&local_b0,0,(va_list *)0x0);
        if (DVar11 != 0) {
          puStackY_120 = (undefined *)0x180030f41;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_c8,
                     local_b0);
          puStackY_120 = (undefined *)0x180030f53;
          MMAfxMessageBox(local_c8,0,-1,0);
          puStackY_120 = (undefined *)0x1800315d7;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8);
          goto LAB_1800315d8;
        }
      }
    }
    puVar26 = auStackY_118;
    puStackY_120 = (undefined *)0x180031025;
    puVar16 = operator_new(0x18);
    local_68 = puVar16;
    if (puVar16 == (undefined8 *)0x0) {
      puVar16 = (undefined8 *)0x0;
    }
    else {
      puVar16[1] = 0;
      *(undefined4 *)(puVar16 + 2) = 1;
      puStackY_120 = (undefined *)0x180031044;
      pOVar17 = FUN_180034c50(param_2);
      *puVar16 = pOVar17;
    }
    pIVar7 = local_b8;
    local_48 = puVar16;
    if (puVar16 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
      puStackY_120 = (undefined *)0x180031636;
      FUN_180034a60(0x8007000e);
    }
    LOCK();
    *(int *)(puVar16 + 2) = *(int *)(puVar16 + 2) + 1;
    UNLOCK();
    local_a8 = (uchar  [8])&local_90;
    local_c0 = 0;
    puStackY_120 = (undefined *)0x18003109b;
    local_90 = puVar16;
    UVar12 = (*local_b8->lpVtbl[10].AddRef)(local_b8);
    if ((int)UVar12 < 0) {
      puStackY_120 = (undefined *)0x1800310b0;
      _com_issue_errorex(UVar12,pIVar7,(_GUID *)&DAT_1800424d8);
    }
    sVar6 = local_c0;
    puStackY_120 = (undefined *)0x1800310bd;
    FUN_18001ccd0(&local_90);
    pcVar15 = local_d8;
    if (sVar6 == 0) {
      puStackY_120 = (undefined *)0x1800310d1;
      pcVar15 = (char *)GetSorResStringEx(0x590);
      puStackY_120 = (undefined *)0x1800310e1;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_c8,pcVar15,
                 param_2);
      puStackY_120 = (undefined *)0x1800310f9;
      MMAfxMessageBox(local_c8,0,-1,0);
      LOCK();
      piVar1 = (int *)(puVar16 + 2);
      iVar9 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar9 == 1) {
        if ((BSTR)*puVar16 != (BSTR)0x0) {
          puStackY_120 = (undefined *)0x180031112;
          SysFreeString((BSTR)*puVar16);
          *puVar16 = 0;
        }
        if ((void *)puVar16[1] != (void *)0x0) {
          puStackY_120 = (undefined *)0x180031123;
          operator_delete__((void *)puVar16[1]);
          puVar16[1] = 0;
        }
        puStackY_120 = (undefined *)0x180031134;
        FUN_180035134(puVar16);
      }
      puStackY_120 = (undefined *)0x18003113f;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8);
      puStackY_120 = (undefined *)0x18003114a;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_c8);
      if (local_b8 != (IUnknown *)0x0) {
        puStackY_120 = (undefined *)0x18003115a;
        (*local_b8->lpVtbl->Release)(local_b8);
      }
      uVar22 = 1;
      puVar26 = auStackY_118;
    }
    else {
      puStackY_120 = (undefined *)0x180031172;
      puVar18 = operator_new(0x18);
      local_a0 = puVar18;
      if (puVar18 == (undefined8 *)0x0) {
        puVar18 = (undefined8 *)0x0;
      }
      else {
        puVar18[1] = 0;
        *(undefined4 *)(puVar18 + 2) = 1;
        puStackY_120 = (undefined *)0x180031191;
        pOVar17 = FUN_180034c50(pcVar15);
        *puVar18 = pOVar17;
      }
      pIVar7 = local_b8;
      local_40 = puVar18;
      if (puVar18 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
        puStackY_120 = &UNK_180031641;
        FUN_180034a60(0x8007000e);
      }
      LOCK();
      *(int *)(puVar18 + 2) = *(int *)(puVar18 + 2) + 1;
      UNLOCK();
      local_a8 = (uchar  [8])&local_a0;
      local_bc = 0;
      puStackY_120 = (undefined *)0x1800311e3;
      local_a0 = puVar18;
      UVar12 = (*local_b8->lpVtbl[0xb].AddRef)(local_b8);
      if ((int)UVar12 < 0) {
        puStackY_120 = (undefined *)0x1800311f8;
        _com_issue_errorex(UVar12,pIVar7,(_GUID *)&DAT_1800424d8);
      }
      sVar6 = local_bc;
      puStackY_120 = (undefined *)0x180031205;
      FUN_18001ccd0(&local_a0);
      if (sVar6 == 0) {
        puStackY_120 = (undefined *)0x180031219;
        pcVar15 = (char *)GetSorResStringEx(0x591);
        puStackY_120 = (undefined *)0x180031229;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_c8,
                   pcVar15,param_2);
        puStackY_120 = (undefined *)0x180031241;
        MMAfxMessageBox(local_c8,0,-1,0);
        LOCK();
        piVar1 = (int *)(puVar18 + 2);
        iVar9 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar9 == 1) {
          if ((BSTR)*puVar18 != (BSTR)0x0) {
            puStackY_120 = (undefined *)0x18003125d;
            SysFreeString((BSTR)*puVar18);
            *puVar18 = 0;
          }
          if ((void *)puVar18[1] != (void *)0x0) {
            puStackY_120 = (undefined *)0x18003126e;
            operator_delete__((void *)puVar18[1]);
            puVar18[1] = 0;
          }
          puStackY_120 = (undefined *)0x18003127f;
          FUN_180035134(puVar18);
        }
        LOCK();
        piVar1 = (int *)(puVar16 + 2);
        iVar9 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar9 == 1) {
          if ((BSTR)*puVar16 != (BSTR)0x0) {
            puStackY_120 = (undefined *)0x180031298;
            SysFreeString((BSTR)*puVar16);
            *puVar16 = 0;
          }
          if ((void *)puVar16[1] != (void *)0x0) {
            puStackY_120 = (undefined *)0x1800312a9;
            operator_delete__((void *)puVar16[1]);
            puVar16[1] = 0;
          }
          puStackY_120 = (undefined *)0x1800312ba;
          FUN_180035134(puVar16);
        }
        puStackY_120 = (undefined *)0x1800312c5;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8);
        puStackY_120 = (undefined *)0x1800312d0;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_c8);
        if (local_b8 != (IUnknown *)0x0) {
          puStackY_120 = (undefined *)0x1800312e0;
          (*local_b8->lpVtbl->Release)(local_b8);
        }
        uVar22 = 1;
      }
      else {
        LOCK();
        piVar1 = (int *)(puVar18 + 2);
        iVar9 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar9 == 1) {
          if ((BSTR)*puVar18 != (BSTR)0x0) {
            puStackY_120 = (undefined *)0x18003130c;
            SysFreeString((BSTR)*puVar18);
            *puVar18 = 0;
          }
          if ((void *)puVar18[1] != (void *)0x0) {
            puStackY_120 = (undefined *)0x18003131d;
            operator_delete__((void *)puVar18[1]);
            puVar18[1] = 0;
          }
          puStackY_120 = (undefined *)0x18003132e;
          FUN_180035134(puVar18);
        }
        LOCK();
        piVar1 = (int *)(puVar16 + 2);
        iVar9 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar9 == 1) {
          if ((BSTR)*puVar16 != (BSTR)0x0) {
            puStackY_120 = (undefined *)0x180031349;
            SysFreeString((BSTR)*puVar16);
            *puVar16 = 0;
          }
          if ((void *)puVar16[1] != (void *)0x0) {
            puStackY_120 = (undefined *)0x18003135a;
            operator_delete__((void *)puVar16[1]);
            puVar16[1] = 0;
          }
          puStackY_120 = (undefined *)0x18003136b;
          FUN_180035134(puVar16);
        }
        puStackY_120 = (undefined *)0x180031379;
        plVar19 = FUN_180029c20(local_b8,&local_68);
        puVar16 = local_68;
        if ((undefined8 *)*plVar19 == (undefined8 *)0x0) {
          lpWideCharStr = (LPCWSTR)0x0;
        }
        else {
          lpWideCharStr = *(LPCWSTR *)*plVar19;
        }
        if (local_68 != (undefined8 *)0x0) {
          LOCK();
          piVar1 = (int *)(local_68 + 2);
          iVar9 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if ((iVar9 == 1) && (local_68 != (undefined8 *)0x0)) {
            if ((BSTR)*local_68 != (BSTR)0x0) {
              puStackY_120 = (undefined *)0x1800313b1;
              SysFreeString((BSTR)*local_68);
              *puVar16 = 0;
            }
            if ((void *)puVar16[1] != (void *)0x0) {
              puStackY_120 = (undefined *)0x1800313c2;
              operator_delete__((void *)puVar16[1]);
              puVar16[1] = 0;
            }
            puStackY_120 = (undefined *)0x1800313d3;
            FUN_180035134(puVar16);
          }
          local_68 = (undefined8 *)0x0;
        }
        puVar26 = auStackY_118;
        if (lpWideCharStr != (LPCWSTR)0x0) {
          lVar20 = -1;
          do {
            lVar21 = lVar20;
            lVar20 = lVar21 + 1;
          } while (lpWideCharStr[lVar20] != L'\0');
          iVar9 = (int)lVar21 + 2;
          puVar26 = auStackY_118;
          if (iVar9 < 0x40000000) {
            lVar20 = (longlong)(int)lVar20 * 2;
            uVar23 = lVar20 + 0x11;
            if (uVar23 <= lVar20 + 2U) {
              uVar23 = 0xffffffffffffff0;
            }
            puStackY_120 = (undefined *)0x180031422;
            lVar20 = -(uVar23 & 0xfffffffffffffff0);
            pCVar2 = local_98 + lVar20 + -0x40;
            puVar26 = auStackY_118 + lVar20;
            if (pCVar2 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
              *pCVar2 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>)0x0;
              *(undefined8 *)(local_98 + lVar20 + -0x48) = 0;
              *(undefined8 *)(auStackY_118 + lVar20 + 0x30) = 0;
              *(int *)(auStackY_118 + lVar20 + 0x28) = iVar9 * 2;
              *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
               (auStackY_118 + lVar20 + 0x20) = pCVar2;
              *(undefined8 *)(auStackY_118 + lVar20 + -8) = 0x180031458;
              iVar9 = WideCharToMultiByte(0,0,lpWideCharStr,-1,
                                          *(LPSTR *)(auStackY_118 + lVar20 + 0x20),
                                          *(int *)(auStackY_118 + lVar20 + 0x28),
                                          *(LPCSTR *)(auStackY_118 + lVar20 + 0x30),
                                          *(LPBOOL *)(local_98 + lVar20 + -0x48));
              pCVar28 = pCVar2;
              if (iVar9 == 0) {
                pCVar28 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
              }
              puVar26 = auStackY_118 + lVar20;
            }
          }
        }
        *(undefined8 *)(puVar26 + -8) = 0x18003146e;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_98,(char *)pCVar28);
        *(undefined8 *)(puVar26 + -8) = 0x18003147b;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                  (local_98,'\\');
        *(undefined8 *)(puVar26 + -8) = 0x18003148d;
        pCVar13 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                            (local_98,(int)local_60);
        *(undefined8 *)(puVar26 + -8) = 0x18003149b;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  (local_98,pCVar13);
        *(undefined8 *)(puVar26 + -8) = 0x1800314a6;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_60);
        *(undefined8 *)(puVar26 + -8) = 0x1800314b1;
        pIVar14 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_d8);
        *(undefined8 *)(puVar26 + -8) = 0x1800314be;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b0,
                   pIVar14);
        pcVar15 = local_d8;
        uStack_cc = uStack_cc | 8;
        lVar20 = -1;
        do {
          lVar25 = lVar20 + 1;
          lVar21 = lVar20 + 1;
          lVar20 = lVar25;
        } while (*(char *)((longlong)&DAT_1800409c4 + lVar21) != '\0');
        *(int *)(puVar26 + 0x20) = (int)lVar25;
        iVar9 = *(int *)(pcVar15 + -0x10);
        *(undefined8 *)(puVar26 + -8) = 0x1800314f0;
        ATL::CSimpleStringT<char,1>::Concatenate
                  ((CSimpleStringT<char,1> *)&local_b0,pcVar15,iVar9,"\\",*(int *)(puVar26 + 0x20));
        pCVar28 = local_98;
        pIVar24 = (IID *)&local_b0;
        *(undefined8 *)(puVar26 + -8) = 0x180031501;
        FUN_180001320((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_88,
                      (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)pIVar24,
                      (undefined8 *)pCVar28);
        *(undefined8 *)(puVar26 + -8) = 0x18003150c;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b0);
        pIVar7 = local_b8;
        pcVar15 = local_88;
        do {
          cVar3 = *pcVar15;
          pcVar15[param_3 - (longlong)local_88] = cVar3;
          pcVar15 = pcVar15 + 1;
        } while (cVar3 != '\0');
        pcVar15 = local_d8;
        do {
          cVar3 = *pcVar15;
          pcVar15[param_4 - (longlong)local_d8] = cVar3;
          pcVar15 = pcVar15 + 1;
        } while (cVar3 != '\0');
        *(undefined8 *)(puVar26 + -8) = 0x180031558;
        FUN_180026150(pIVar7,pIVar24,(void **)pCVar28);
        *(undefined8 *)(puVar26 + -8) = 0x180031562;
        SetCurrentDirectoryA(local_d8);
        *(undefined8 *)(puVar26 + -8) = 0x180031573;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_1800540c0,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   &local_d8);
        pcVar15 = local_88;
        bVar5 = local_d0;
        *(undefined8 *)(puVar26 + -8) = 0x180031580;
        FUN_180029cb0(bVar5,pcVar15);
        uVar23 = (ulonglong)local_d0;
        *(undefined8 *)(puVar26 + -8) = 0x18003158d;
        FUN_180032500(uVar23,local_88);
        *(undefined8 *)(puVar26 + -8) = 0x180031598;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_88);
        *(undefined8 *)(puVar26 + -8) = 0x1800315a3;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_98);
        *(undefined8 *)(puVar26 + -8) = 0x1800315ae;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8);
        *(undefined8 *)(puVar26 + -8) = 0x1800315b9;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_c8);
        pIVar7 = local_b8;
        if (local_b8 != (IUnknown *)0x0) {
          p_Var4 = local_b8->lpVtbl->Release;
          *(undefined8 *)(puVar26 + -8) = 0x1800315c9;
          (*p_Var4)(pIVar7);
        }
        uVar22 = 0;
      }
    }
  }
  *(undefined8 *)(puVar26 + -8) = 0x180031606;
  return uVar22;
}

