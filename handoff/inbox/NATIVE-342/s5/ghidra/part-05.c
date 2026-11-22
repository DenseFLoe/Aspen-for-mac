/* RVA 0x15030 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180015030(longlong param_1,char *param_2,char param_3,undefined8 param_4)

{
  longlong *plVar1;
  ULONG UVar2;
  int iVar3;
  IStorage *pIVar4;
  _GUID *p_Var5;
  void *pvVar6;
  IStorage *This;
  undefined4 extraout_var;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar7;
  undefined8 uVar8;
  longlong lVar9;
  size_t sVar10;
  undefined1 auStackY_578 [32];
  undefined4 local_548 [2];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_540 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_538 [16];
  undefined1 local_528 [256];
  char local_428 [256];
  char local_328 [256];
  char local_228 [272];
  char local_118 [256];
  IStorage *local_18;
  
  pIVar4 = (IStorage *)(DAT_180052888 ^ (ulonglong)auStackY_578);
  if (param_3 == '\0') {
    local_18 = pIVar4;
    FUN_180001ce0(local_528,"Enter CApwnLWDocument::OpenDocument fileName = %s",param_2,param_4);
    LogMessage(local_528,2,2);
    sVar10 = 0xffffffffffffffff;
    do {
      sVar10 = sVar10 + 1;
    } while (param_2[sVar10] != '\0');
    FUN_18001d350((longlong *)(param_1 + 0x60),param_2,sVar10);
    p_Var5 = (_GUID *)FUN_18000c750();
    pvVar6 = LoadApwnContextDocument(param_2,p_Var5);
    *(void **)(param_1 + 0xb0) = pvVar6;
    SetGlobalPointer("ApwnOleServerDoc");
    This = ApwnContextDocumentRootStorage(*(void **)(param_1 + 0xb0));
    pIVar4 = This;
    if (*(IStorage **)(param_1 + 8) != This) {
      if (This != (IStorage *)0x0) {
        UVar2 = (*This->lpVtbl->AddRef)(This);
        pIVar4 = (IStorage *)CONCAT44(extraout_var,UVar2);
      }
      plVar1 = *(longlong **)(param_1 + 8);
      *(IStorage **)(param_1 + 8) = This;
      if (plVar1 != (longlong *)0x0) {
        pIVar4 = (IStorage *)(**(code **)(*plVar1 + 0x10))();
      }
    }
    if (*(longlong **)(param_1 + 8) != (longlong *)0x0) {
      (**(code **)(**(longlong **)(param_1 + 8) + 0x10))();
      if (*(longlong *)(param_1 + 8) == 0) {
        LogMessage("Leave CApwnLWDocument::OpenDocument",2,2);
        pIVar4 = (IStorage *)GRsetLoadingAPW(0);
      }
      else {
        iVar3 = FUN_180033bd0();
        if (iVar3 == 1) {
          GRsetLoadingAPW(1);
          plVar1 = *(longlong **)(param_1 + 8);
          iVar3 = FUN_180033bd0();
          if (iVar3 == 1) {
            _splitpath(param_2,(char *)local_548,local_328,local_428,local_118);
            _makepath(local_228,(char *)local_548,local_328,local_428,"ads");
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_540,local_228);
            pCVar7 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                     ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                     CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                               (local_538,
                                (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                 *)local_540);
            FUN_180018420(param_1,plVar1,"ADS",pCVar7);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_540);
          }
          FUN_180018610(param_1,*(longlong **)(param_1 + 8));
        }
        iVar3 = HappInitted();
        if (iVar3 != 0) {
LAB_1800153a1:
          iVar3 = GRinqtpsaupgrade();
          if (iVar3 == 0) {
            GRsetcolumnanalyzer(0);
          }
          FUN_18000f590(param_1);
          FUN_1800169a0(param_1,(char *)0x0,0);
          MDintlib();
          FUN_18000a9c0(param_1,'\x01');
          FUN_180033bd0();
          lVar9 = GetGlobalPointer("CompoundFileName");
          if (lVar9 != 0) {
            HappUpdateMoniker(lVar9);
          }
          iVar3 = FUN_180033bd0();
          if (iVar3 == 1) {
            FUN_18000f450(param_1,*(longlong **)(param_1 + 8));
            FUN_180010280(param_1);
            FUN_18000f2b0(param_1,*(longlong **)(param_1 + 8));
            FUN_180010750(param_1,*(longlong **)(param_1 + 8));
          }
          HAPostLoadInit();
          FUN_18000f380(param_1,*(longlong **)(param_1 + 8));
          GRsetLoadingAPW(0);
          uVar8 = LogMessage("Leave CApwnLWDocument::OpenDocument",2,2);
          return CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
        }
        iVar3 = OpenHapp(*(undefined8 *)(param_1 + 8));
        if (iVar3 == -0x7555ffff) {
          GRsetLoadingAPW(0);
          iVar3 = SThasstr(*(undefined8 *)(param_1 + 8),&DAT_18004180c,local_548,local_540);
          if (iVar3 != 0) {
            STremstr(*(undefined8 *)(param_1 + 8),&DAT_18004180c,local_548[0]);
          }
          iVar3 = SThasstr(*(undefined8 *)(param_1 + 8),&DAT_180041810,local_548,local_540);
          if (iVar3 != 0) {
            STremstr(*(undefined8 *)(param_1 + 8),&DAT_180041810,local_548[0]);
          }
          pIVar4 = (IStorage *)InitializeHapp(*(undefined8 *)(param_1 + 8));
          if ((int)pIVar4 == 0) goto LAB_18001547c;
          FUN_18000f590(param_1);
          FUN_18000a9c0(param_1,'\0');
          SetGlobalPointer("ApwnDocStorage",*(undefined8 *)(param_1 + 8),0);
          SetGlobalPointer("LoadPFSFromDoc",&LAB_18000d600,0);
          SetGlobalPointer("SavePFSFToDoc",&LAB_18000d640,0);
          SetGlobalPointer("ClearPFSEmbedding",&LAB_18000d5b0,0);
          SetGlobalPointer("GetPFSEmbedding",&LAB_18000d5d0,0);
          SetGlobalPointer("RestorePFSEmbedding",&LAB_18000d620,0);
          iVar3 = OpenHappArchiveStg(*(undefined8 *)(param_1 + 8),param_2);
          if (iVar3 != 0) {
            *(undefined1 *)(param_1 + 0xac) = 1;
            FUN_18000ab20();
            uVar8 = FUN_18000f380(param_1,*(longlong **)(param_1 + 8));
            return CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
          }
        }
        else {
          if (iVar3 != -0x7ffffff9) {
            if (iVar3 == 0) goto LAB_1800153a1;
            GRsetLoadingAPW(0);
            GRsetInvalidFormat(1);
            pIVar4 = (IStorage *)SimExit();
            goto LAB_18001547c;
          }
          GRsetLoadingAPW(0);
        }
        pIVar4 = (IStorage *)SimExit();
      }
    }
  }
LAB_18001547c:
  return (ulonglong)pIVar4 & 0xffffffffffffff00;
}

/* RVA 0x154b0 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1800154b0(undefined8 param_1,char *param_2,longlong *param_3,undefined8 param_4)

{
  __uint64 _Var1;
  WCHAR *pwcsName;
  char cVar2;
  char cVar3;
  IStorageVtbl *pIVar4;
  _func_5398 *p_Var5;
  code *pcVar6;
  longlong ****pppplVar7;
  _func_5396 *p_Var8;
  uchar *puVar9;
  LPSTORAGE pIVar10;
  undefined8 *****pppppuVar11;
  BOOL BVar12;
  int iVar13;
  HRESULT HVar14;
  LSTATUS LVar15;
  int iVar16;
  HANDLE hFindFile;
  CLSID *_Dst;
  char *pcVar17;
  char *pcVar18;
  ulonglong uVar19;
  void *pvVar20;
  void *pvVar21;
  undefined *puVar22;
  undefined8 ****ppppuVar23;
  longlong lVar24;
  longlong lVar25;
  longlong *plVar26;
  ulonglong uVar27;
  longlong *****ppppplVar28;
  longlong *plVar29;
  DWORD DVar30;
  longlong *plVar31;
  longlong *****ppppplVar32;
  undefined8 *****pppppuVar33;
  longlong *plVar34;
  undefined1 *puVar35;
  undefined1 *puVar36;
  longlong *plVar37;
  longlong *plVar38;
  CLSID *pCVar39;
  ulonglong uVar40;
  HKEY pHVar41;
  undefined8 *****pppppuVar42;
  CLSID *pCVar43;
  size_t sVar44;
  size_t sVar45;
  LPDWORD lpcchClass;
  undefined8 uVar46;
  ulonglong *lpcchName;
  longlong *****_Src;
  ulonglong uVar47;
  longlong *****ppppplVar48;
  HKEY hKey;
  undefined1 local_6b8 [96];
  uint local_658;
  DWORD local_654;
  HKEY local_650;
  longlong *local_648;
  LPSTORAGE local_640;
  ulonglong local_638;
  ulonglong local_630;
  longlong *local_628;
  undefined8 local_620;
  longlong *local_618;
  longlong *local_610;
  longlong *local_608;
  longlong *local_600;
  ulonglong local_5f8;
  HKEY local_5f0;
  char *local_5e8;
  longlong *local_5e0;
  longlong *plStack_5d8;
  longlong *local_5d0;
  longlong *local_5c8;
  longlong *plStack_5c0;
  longlong *local_5b8;
  longlong *local_5b0;
  longlong local_5a8;
  CLSID local_5a0;
  undefined8 local_590;
  undefined8 uStack_588;
  undefined8 *****local_580;
  undefined8 uStack_578;
  ulonglong local_570;
  ulonglong uStack_568;
  longlong *****local_558;
  undefined8 uStack_550;
  ulonglong local_548;
  HKEY local_540;
  longlong *****local_538;
  undefined8 uStack_530;
  ulonglong local_528;
  ulonglong local_520;
  undefined8 *****local_518;
  undefined8 uStack_510;
  size_t local_508;
  ulonglong local_500;
  _WIN32_FIND_DATAA local_4f8;
  undefined8 local_3b8;
  undefined8 uStack_3b0;
  undefined8 local_3a8;
  undefined8 uStack_3a0;
  undefined8 local_398;
  undefined8 uStack_390;
  undefined8 local_388;
  undefined8 uStack_380;
  undefined8 local_378;
  undefined8 uStack_370;
  CHAR local_368;
  char acStack_367 [271];
  CHAR local_258 [271];
  char cStack_149;
  CHAR local_148 [2];
  char local_146 [270];
  ulonglong local_38;
  
  puVar36 = local_6b8;
  local_38 = DAT_180052888 ^ (ulonglong)&local_658;
  if (param_3[1] - *param_3 >> 5 == 0) goto LAB_18001693b;
  local_5e0 = (longlong *)0x0;
  plStack_5d8 = (longlong *)0x0;
  plVar37 = (longlong *)0x0;
  local_600 = (longlong *)0x0;
  local_5d0 = (longlong *)0x0;
  pCVar43 = (CLSID *)0x104;
  local_618 = param_3;
  memset(local_148,0,0x104);
  pcVar17 = param_2;
  do {
    cVar2 = *pcVar17;
    pcVar17[(longlong)(local_148 + -(longlong)param_2)] = cVar2;
    pcVar17 = pcVar17 + 1;
  } while (cVar2 != '\0');
  local_5c8 = (longlong *)0x0;
  plStack_5c0 = (longlong *)0x0;
  plVar38 = (longlong *)0x0;
  local_608 = (longlong *)0x0;
  local_5b8 = (longlong *)0x0;
  pcVar17 = &cStack_149;
  do {
    pcVar18 = pcVar17;
    pcVar17 = pcVar18 + 1;
  } while (*pcVar17 != '\0');
  *(undefined2 *)pcVar17 = DAT_180041ed0;
  pcVar18[3] = DAT_180041ed2;
  hFindFile = FindFirstFileA(local_148,&local_4f8);
  puVar36 = local_6b8;
  if (hFindFile == (HANDLE)0xffffffffffffffff) {
    plVar29 = plStack_5c0;
    plVar34 = local_5c8;
    plVar26 = plStack_5d8;
    plVar31 = local_5e0;
  }
  else {
    local_630 = 0xf;
    local_610 = plStack_5c0;
    plVar37 = plStack_5c0;
    do {
      if (((byte)local_4f8.dwFileAttributes & 0x10) == 0) {
        local_620 = (longlong *)CONCAT44(local_4f8.nFileSizeHigh,local_4f8.nFileSizeLow);
        FUN_18001f260("  %s   %I64d bytes\n",local_4f8.cFileName,local_620,param_4);
        local_5a0._0_8_ = (CLSID *)0x0;
        local_5a0.Data4[0] = '\0';
        local_5a0.Data4[1] = '\0';
        local_5a0.Data4[2] = '\0';
        local_5a0.Data4[3] = '\0';
        local_5a0.Data4[4] = '\0';
        local_5a0.Data4[5] = '\0';
        local_5a0.Data4[6] = '\0';
        local_5a0.Data4[7] = '\0';
        local_590 = (CLSID *)0x0;
        uStack_588 = 0;
        pCVar39 = (CLSID *)0xffffffffffffffff;
        do {
          pCVar39 = (CLSID *)((longlong)&pCVar39->Data1 + 1);
        } while (local_4f8.cFileName[(longlong)pCVar39] != '\0');
        if ((CLSID *)0x7fffffffffffffff < pCVar39) {
                    /* WARNING: Subroutine does not return */
          FUN_18001d1b0();
        }
        pCVar43 = pCVar39;
        if (pCVar39 < (CLSID *)0x10) {
          uStack_588 = 0xf;
          local_590 = pCVar39;
          memcpy(&local_5a0,local_4f8.cFileName,(size_t)pCVar39);
          pCVar39->Data4[(longlong)(local_5a0.Data4 + -0x10)] = '\0';
        }
        else {
          uVar47 = (ulonglong)pCVar39 | 0xf;
          if (uVar47 < 0x8000000000000000) {
            if (uVar47 < 0x16) {
              uVar47 = 0x16;
            }
          }
          else {
            uVar47 = 0x7fffffffffffffff;
          }
          _Dst = FUN_18001d210(&local_5a0,uVar47 + 1);
          local_5a0._0_8_ = _Dst;
          local_590 = pCVar39;
          uStack_588 = uVar47;
          memcpy(_Dst,local_4f8.cFileName,(size_t)pCVar39);
          _Dst->Data4[(longlong)(pCVar39->Data4 + -0x10)] = '\0';
        }
        if (plVar37 == local_608) {
          pCVar43 = &local_5a0;
          FUN_1800077a0((longlong *)&local_5c8,plVar37,(undefined8 *)pCVar43);
          local_608 = local_5b8;
          uVar47 = uStack_588;
        }
        else {
          *plVar37 = local_5a0._0_8_;
          *(uchar (*) [8])(plVar37 + 1) = local_5a0.Data4;
          *(undefined4 *)(plVar37 + 2) = (undefined4)local_590;
          *(undefined4 *)((longlong)plVar37 + 0x14) = local_590._4_4_;
          *(undefined4 *)(plVar37 + 3) = (undefined4)uStack_588;
          *(undefined4 *)((longlong)plVar37 + 0x1c) = uStack_588._4_4_;
          local_5a0._0_8_ = local_5a0._0_8_ & 0xffffffffffffff00;
          plStack_5c0 = plVar37 + 4;
          uVar47 = 0xf;
        }
        plVar37 = plStack_5c0;
        local_610 = plStack_5c0;
        if (0xf < uVar47) {
          pCVar39 = (CLSID *)local_5a0._0_8_;
          if ((0xfff < uVar47 + 1) &&
             (pCVar39 = *(CLSID **)((CLSID *)(local_5a0._0_8_ + -0x10))->Data4,
             (char *)0x1f < (char *)(local_5a0._0_8_ + (-8 - (longlong)pCVar39)))) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
          FUN_180035134(pCVar39);
        }
      }
      else {
        FUN_18001f260("  %s   <DIR>\n",local_4f8.cFileName,pCVar43,param_4);
      }
      BVar12 = FindNextFileA(hFindFile,&local_4f8);
    } while (BVar12 != 0);
    FindClose(hFindFile);
    memset(local_258,0,0x104);
    lVar24 = -(longlong)param_2;
    do {
      cVar2 = *param_2;
      param_2[(longlong)(local_258 + lVar24)] = cVar2;
      param_2 = param_2 + 1;
    } while (cVar2 != '\0');
    local_5f8 = 0;
    local_620 = local_5c8;
    uVar47 = (longlong)plVar37 - (longlong)local_5c8 >> 5;
    local_648 = plStack_5d8;
    puVar36 = local_6b8;
    plVar26 = plStack_5d8;
    local_638 = uVar47;
    if (uVar47 != 0) {
      puVar35 = local_6b8;
      plVar37 = local_618;
      while( true ) {
        uVar40 = local_5f8;
        lVar24 = 0;
        puVar36 = puVar35;
        if (plVar37[1] - *plVar37 >> 5 == 0) break;
        plVar31 = local_620 + local_5f8 * 4;
        plVar38 = plVar31;
        if (0xf < (ulonglong)plVar31[3]) {
          plVar38 = (longlong *)*plVar31;
        }
        *(undefined8 *)(puVar35 + -8) = 0x180015855;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_650,
                   (char *)plVar38);
        *(undefined8 *)(puVar35 + -8) = 0x18001586a;
        iVar13 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                           ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_650,".apmbd",0);
        if (iVar13 == -1) {
          *(undefined8 *)(puVar35 + -8) = 0x180015887;
          memset(&local_368,0,0x104);
          do {
            cVar2 = local_258[lVar24];
            acStack_367[lVar24 + -1] = cVar2;
            lVar24 = lVar24 + 1;
          } while (cVar2 != '\0');
          pcVar17 = (char *)((longlong)&uStack_370 + 7);
          do {
            pcVar17 = pcVar17 + 1;
          } while (*pcVar17 != '\0');
          *(undefined2 *)pcVar17 = DAT_1800409c4;
          if (0xf < (ulonglong)plVar31[3]) {
            plVar31 = (longlong *)*plVar31;
          }
          pcVar17 = (char *)((longlong)&uStack_370 + 7);
          do {
            pcVar17 = pcVar17 + 1;
          } while (*pcVar17 != '\0');
          lVar24 = 0;
          do {
            cVar2 = *(char *)((longlong)plVar31 + lVar24);
            pcVar17[lVar24] = cVar2;
            lVar24 = lVar24 + 1;
          } while (cVar2 != '\0');
          lVar24 = -1;
          do {
            lVar25 = lVar24;
            lVar24 = lVar25 + 1;
          } while (acStack_367[lVar25] != '\0');
          uVar19 = (lVar25 + 2) * 2;
          uVar27 = uVar19 + 0xf;
          if (uVar27 <= uVar19) {
            uVar27 = 0xffffffffffffff0;
          }
          *(undefined8 *)(puVar35 + -8) = 0x18001593f;
          lVar24 = -(uVar27 & 0xfffffffffffffff0);
          pwcsName = (WCHAR *)(puVar35 + lVar24 + 0x60);
          *(int *)(puVar35 + lVar24 + 0x28) = (int)(lVar25 + 2);
          *(WCHAR **)(puVar35 + lVar24 + 0x20) = pwcsName;
          *(undefined8 *)(puVar35 + lVar24 + -8) = 0x180015967;
          MultiByteToWideChar(0,0,&local_368,-1,*(LPWSTR *)(puVar35 + lVar24 + 0x20),
                              *(int *)(puVar35 + lVar24 + 0x28));
          *(undefined8 *)(puVar35 + lVar24 + -8) = 0x180015970;
          HVar14 = StgIsStorageFile(pwcsName);
          puVar36 = puVar35 + lVar24;
          if (HVar14 == 0) {
            local_640 = (LPSTORAGE)0x0;
            *(LPSTORAGE **)(puVar35 + lVar24 + 0x28) = &local_640;
            *(undefined4 *)(puVar35 + lVar24 + 0x20) = 0;
            *(undefined8 *)(puVar35 + lVar24 + -8) = 0x18001599d;
            HVar14 = StgOpenStorage(pwcsName,(IStorage *)0x0,0x10020,(SNB)0x0,
                                    *(DWORD *)(puVar35 + lVar24 + 0x20),
                                    *(IStorage ***)(puVar35 + lVar24 + 0x28));
            pIVar10 = local_640;
            puVar36 = puVar35 + lVar24;
            if (-1 < HVar14) {
              *(undefined8 *)(puVar35 + lVar24 + -8) = 0x1800159b6;
              ReadClassStg(pIVar10,&local_5a0);
              if ((((((((CLSID *)local_5a0._0_8_ == DAT_180041180) &&
                      (local_5a0.Data4 == DAT_180041188)) ||
                     (((CLSID *)local_5a0._0_8_ == DAT_180041190 &&
                      (local_5a0.Data4 == DAT_180041198)))) ||
                    (((CLSID *)local_5a0._0_8_ == DAT_1800411a0 &&
                     (local_5a0.Data4 == DAT_1800411a8)))) ||
                   ((((CLSID *)local_5a0._0_8_ == DAT_1800411b0 &&
                     (local_5a0.Data4 == DAT_1800411b8)) ||
                    (((((CLSID *)local_5a0._0_8_ == DAT_1800411c0 &&
                       (local_5a0.Data4 == DAT_1800411c8)) ||
                      (((CLSID *)local_5a0._0_8_ == DAT_1800411d0 &&
                       (local_5a0.Data4 == DAT_1800411d8)))) ||
                     (((CLSID *)local_5a0._0_8_ == DAT_1800411e0 &&
                      (local_5a0.Data4 == DAT_1800411e8)))))))) ||
                  ((((((CLSID *)local_5a0._0_8_ == DAT_1800411f0 &&
                      (local_5a0.Data4 == DAT_1800411f8)) ||
                     (((((CLSID *)local_5a0._0_8_ == DAT_180041200 &&
                        (local_5a0.Data4 == DAT_180041208)) ||
                       (((CLSID *)local_5a0._0_8_ == DAT_180041210 &&
                        (local_5a0.Data4 == DAT_180041218)))) ||
                      (((((CLSID *)local_5a0._0_8_ == DAT_180041220 &&
                         (local_5a0.Data4 == DAT_180041228)) ||
                        (((CLSID *)local_5a0._0_8_ == DAT_180041230 &&
                         (local_5a0.Data4 == DAT_180041238)))) ||
                       (((((CLSID *)local_5a0._0_8_ == DAT_180041240 &&
                          (local_5a0.Data4 == DAT_180041248)) ||
                         (((CLSID *)local_5a0._0_8_ == DAT_180041250 &&
                          (local_5a0.Data4 == DAT_180041258)))) ||
                        (((CLSID *)local_5a0._0_8_ == DAT_180041260 &&
                         (local_5a0.Data4 == DAT_180041268)))))))))) ||
                    (((CLSID *)local_5a0._0_8_ == DAT_180041270 &&
                     (local_5a0.Data4 == DAT_180041278)))) ||
                   (((((CLSID *)local_5a0._0_8_ == DAT_180041280 &&
                      (local_5a0.Data4 == DAT_180041288)) ||
                     (((CLSID *)local_5a0._0_8_ == DAT_180041290 &&
                      (local_5a0.Data4 == DAT_180041298)))) ||
                    ((((((CLSID *)local_5a0._0_8_ == DAT_1800412a0 &&
                        (local_5a0.Data4 == DAT_1800412a8)) ||
                       (((CLSID *)local_5a0._0_8_ == DAT_1800412b0 &&
                        (local_5a0.Data4 == DAT_1800412b8)))) ||
                      (((((CLSID *)local_5a0._0_8_ == DAT_1800412c0 &&
                         (local_5a0.Data4 == DAT_1800412c8)) ||
                        (((CLSID *)local_5a0._0_8_ == DAT_1800412d0 &&
                         (local_5a0.Data4 == DAT_1800412d8)))) ||
                       (((CLSID *)local_5a0._0_8_ == DAT_1800412e0 &&
                        (local_5a0.Data4 == DAT_1800412e8)))))) ||
                     (((CLSID *)local_5a0._0_8_ == DAT_1800412f0 &&
                      (local_5a0.Data4 == DAT_1800412f8)))))))))) ||
                 ((puVar36 = puVar35 + lVar24, (CLSID *)local_5a0._0_8_ == DAT_180041300 &&
                  (puVar36 = puVar35 + lVar24, local_5a0.Data4 == DAT_180041308)))) {
                local_628 = (longlong *)0x0;
                *(undefined4 *)(puVar35 + lVar24 + 8) = 10;
                *(undefined1 **)(puVar35 + lVar24) = puVar35 + lVar24 + 0x40;
                *(undefined8 *)(puVar35 + lVar24 + -0x28) = 0x180015c0c;
                MultiByteToWideChar(0,0,"CONTENTS",-1,*(LPWSTR *)(puVar35 + lVar24),
                                    *(int *)(puVar35 + lVar24 + 8));
                pIVar10 = local_640;
                pIVar4 = local_640->lpVtbl;
                *(longlong ***)(puVar35 + lVar24 + 8) = &local_628;
                *(undefined4 *)(puVar35 + lVar24) = 0;
                p_Var5 = pIVar4->OpenStream;
                *(undefined8 *)(puVar35 + lVar24 + -0x28) = 0x180015c2f;
                HVar14 = (*p_Var5)(pIVar10,(OLECHAR *)(puVar35 + lVar24 + 0x40),(void *)0x0,0x10,
                                   *(DWORD *)(puVar35 + lVar24),*(IStream ***)(puVar35 + lVar24 + 8)
                                  );
                plVar38 = local_628;
                puVar36 = puVar35 + lVar24 + -0x20;
                if (-1 < HVar14) {
                  local_658 = 0;
                  pcVar6 = *(code **)(*local_628 + 0x18);
                  *(undefined8 *)(puVar35 + lVar24 + -0x28) = 0x180015c52;
                  iVar13 = (*pcVar6)(plVar38,&local_654,4,&local_658);
                  if (((-1 < iVar13) && (local_658 == 4)) && (local_654 != 0)) {
                    uVar27 = (ulonglong)local_654;
                    *(undefined8 *)(puVar35 + lVar24 + -0x28) = 0x180015c77;
                    pcVar17 = malloc(uVar27);
                    plVar38 = local_628;
                    DVar30 = local_654;
                    local_5e8 = pcVar17;
                    if (pcVar17 != (char *)0x0) {
                      pcVar6 = *(code **)(*local_628 + 0x18);
                      *(undefined8 *)(puVar35 + lVar24 + -0x28) = 0x180015c9d;
                      iVar13 = (*pcVar6)(plVar38,pcVar17,DVar30,&local_658);
                      if ((-1 < iVar13) && (local_658 == local_654)) {
                        ppppplVar32 = (longlong *****)*plVar37;
                        if (ppppplVar32 != (longlong *****)plVar37[1]) {
LAB_180015cc1:
                          ppppplVar28 = ppppplVar32;
                          if ((longlong ****)0xf < ppppplVar32[3]) {
                            ppppplVar28 = (longlong *****)*ppppplVar32;
                          }
                          pcVar18 = pcVar17;
                          do {
                            cVar2 = *pcVar18;
                            cVar3 = pcVar18[(longlong)ppppplVar28 - (longlong)pcVar17];
                            if (cVar2 != cVar3) break;
                            pcVar18 = pcVar18 + 1;
                          } while (cVar3 != '\0');
                          if (cVar2 != cVar3) goto code_r0x000180015cf7;
                          uStack_550 = 0;
                          local_548 = 0;
                          local_540 = (HKEY)0xf;
                          local_558 = (longlong *****)0x0;
                          uStack_530 = 0;
                          local_528 = 0;
                          local_520 = 0xf;
                          local_538 = (longlong *****)0x0;
                          if (&local_558 != (longlong ******)ppppplVar32) {
                            ppppplVar28 = ppppplVar32;
                            if ((longlong ****)0xf < ppppplVar32[3]) {
                              ppppplVar28 = (longlong *****)*ppppplVar32;
                            }
                            pppplVar7 = ppppplVar32[2];
                            *(undefined8 *)(puVar35 + lVar24 + -0x28) = 0x180015d72;
                            FUN_18001d350((longlong *)&local_558,ppppplVar28,(size_t)pppplVar7);
                          }
                          sVar45 = 0xffffffffffffffff;
                          do {
                            sVar44 = sVar45 + 1;
                            pcVar18 = acStack_367 + sVar45;
                            sVar45 = sVar44;
                          } while (*pcVar18 != '\0');
                          *(undefined8 *)(puVar35 + lVar24 + -0x28) = 0x180015d9d;
                          FUN_18001d350((longlong *)&local_538,&local_368,sVar44);
                          uVar47 = local_548;
                          ppppplVar28 = local_558;
                          if (plVar26 == local_600) {
                            *(undefined8 *)(puVar35 + lVar24 + -0x28) = 0x180015fe6;
                            FUN_180007460((longlong *)&local_5e0,plVar26,&local_558);
                            local_600 = local_5d0;
                            pHVar41 = local_540;
                            ppppplVar28 = local_558;
                            ppppplVar48 = local_538;
                            uVar47 = local_520;
                          }
                          else {
                            local_5b0 = plVar26;
                            *plVar26 = 0;
                            plVar26[1] = 0;
                            plVar26[2] = 0;
                            plVar26[3] = 0;
                            local_5f0 = local_540;
                            ppppplVar48 = (longlong *****)&local_558;
                            if ((HKEY)0xf < local_540) {
                              ppppplVar48 = local_558;
                            }
                            if (0x7fffffffffffffff < local_548) {
                    /* WARNING: Subroutine does not return */
                              *(undefined8 *)(puVar35 + lVar24 + -0x28) = 0x180016993;
                              FUN_18001d1b0();
                            }
                            plVar26[3] = 0xf;
                            if (local_548 < 0x10) {
                              plVar26[2] = local_548;
                              pppplVar7 = ppppplVar48[1];
                              *plVar26 = (longlong)*ppppplVar48;
                              plVar26[1] = (longlong)pppplVar7;
                            }
                            else {
                              uVar40 = local_548 | 0xf;
                              if (uVar40 < 0x8000000000000000) {
                                if (uVar40 < 0x16) {
                                  uVar40 = 0x16;
                                }
                                _Var1 = uVar40 + 1;
                                if (0xfff < _Var1) {
                                  uVar27 = uVar40 + 0x28;
                                  if (uVar27 <= _Var1) {
                    /* WARNING: Subroutine does not return */
                                    *(undefined8 *)(puVar35 + lVar24 + -0x28) = 0x180016981;
                                    FUN_18001d0c0();
                                  }
                                  goto LAB_180015e63;
                                }
                                if (_Var1 == 0) {
                                  pvVar21 = (void *)0x0;
                                }
                                else {
                                  *(undefined8 *)(puVar35 + lVar24 + -0x28) = 0x180015e8f;
                                  pvVar21 = operator_new(_Var1);
                                }
                              }
                              else {
                                uVar40 = 0x7fffffffffffffff;
                                uVar27 = 0x8000000000000027;
LAB_180015e63:
                                *(undefined8 *)(puVar35 + lVar24 + -0x28) = 0x180015e6b;
                                pvVar20 = operator_new(uVar27);
                                if (pvVar20 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
                                  *(undefined **)(puVar35 + lVar24 + -0x28) = &UNK_1800160ec;
                                  _invalid_parameter_noinfo_noreturn();
                                }
                                pvVar21 = (void *)((longlong)pvVar20 + 0x27U & 0xffffffffffffffe0);
                                *(void **)((longlong)pvVar21 - 8) = pvVar20;
                              }
                              *plVar26 = (longlong)pvVar21;
                              plVar26[2] = uVar47;
                              plVar26[3] = uVar40;
                              *(undefined8 *)(puVar35 + lVar24 + -0x28) = 0x180015eb1;
                              memcpy(pvVar21,ppppplVar48,uVar47 + 1);
                            }
                            uVar47 = local_520;
                            uVar40 = local_528;
                            ppppplVar48 = local_538;
                            plVar26[4] = 0;
                            plVar26[5] = 0;
                            plVar26[6] = 0;
                            plVar26[7] = 0;
                            _Src = (longlong *****)&local_538;
                            if (0xf < local_520) {
                              _Src = local_538;
                            }
                            if (0x7fffffffffffffff < local_528) {
                    /* WARNING: Subroutine does not return */
                              *(undefined8 *)(puVar35 + lVar24 + -0x28) = 0x18001698d;
                              FUN_18001d1b0();
                            }
                            local_648[7] = 0xf;
                            if (local_528 < 0x10) {
                              local_648[6] = local_528;
                              pppplVar7 = _Src[1];
                              local_648[4] = (longlong)*_Src;
                              local_648[5] = (longlong)pppplVar7;
                            }
                            else {
                              uVar27 = local_528 | 0xf;
                              if (uVar27 < 0x8000000000000000) {
                                if (uVar27 < 0x16) {
                                  uVar27 = 0x16;
                                }
                                _Var1 = uVar27 + 1;
                                if (0xfff < _Var1) {
                                  uVar19 = uVar27 + 0x28;
                                  if (uVar19 <= _Var1) {
                    /* WARNING: Subroutine does not return */
                                    *(undefined **)(puVar35 + lVar24 + -0x28) = &UNK_180016987;
                                    FUN_18001d0c0();
                                  }
                                  goto LAB_180015f6b;
                                }
                                if (_Var1 == 0) {
                                  pvVar21 = (void *)0x0;
                                }
                                else {
                                  *(undefined8 *)(puVar35 + lVar24 + -0x28) = 0x180015f97;
                                  pvVar21 = operator_new(_Var1);
                                }
                              }
                              else {
                                uVar27 = 0x7fffffffffffffff;
                                uVar19 = 0x8000000000000027;
LAB_180015f6b:
                                *(undefined8 *)(puVar35 + lVar24 + -0x28) = 0x180015f73;
                                pvVar20 = operator_new(uVar19);
                                if (pvVar20 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
                                  *(undefined **)(puVar35 + lVar24 + -0x28) = &UNK_1800160f3;
                                  _invalid_parameter_noinfo_noreturn();
                                }
                                pvVar21 = (void *)((longlong)pvVar20 + 0x27U & 0xffffffffffffffe0);
                                *(void **)((longlong)pvVar21 - 8) = pvVar20;
                              }
                              local_648[4] = (longlong)pvVar21;
                              local_648[6] = uVar40;
                              local_648[7] = uVar27;
                              *(undefined8 *)(puVar35 + lVar24 + -0x28) = 0x180015fba;
                              memcpy(pvVar21,_Src,uVar40 + 1);
                            }
                            plStack_5d8 = local_648 + 8;
                            pcVar17 = local_5e8;
                            pHVar41 = local_5f0;
                          }
                          plVar26 = plStack_5d8;
                          plVar37 = local_618;
                          local_648 = plStack_5d8;
                          *(undefined8 *)(puVar35 + lVar24 + -0x28) = 0x18001602b;
                          FUN_18001d660((longlong)plVar37,&local_5a8,(longlong)ppppplVar32);
                          if (0xf < uVar47) {
                            ppppplVar32 = ppppplVar48;
                            if ((0xfff < uVar47 + 1) &&
                               (ppppplVar32 = (longlong *****)ppppplVar48[-1],
                               0x1f < (ulonglong)
                                      ((longlong)ppppplVar48 + (-8 - (longlong)ppppplVar32))))
                            goto LAB_1800160f4;
                            *(undefined8 *)(puVar35 + lVar24 + -0x28) = 0x180016063;
                            FUN_180035134(ppppplVar32);
                          }
                          if ((HKEY)0xf < pHVar41) {
                            ppppplVar32 = ppppplVar28;
                            if (((undefined1 *)0xfff <
                                 (undefined1 *)((longlong)&pHVar41->unused + 1U)) &&
                               (ppppplVar32 = (longlong *****)ppppplVar28[-1],
                               0x1f < (ulonglong)
                                      ((longlong)ppppplVar28 + (-8 - (longlong)ppppplVar32)))) {
LAB_1800160f4:
                    /* WARNING: Subroutine does not return */
                              *(undefined **)(puVar35 + lVar24 + -0x28) = &UNK_1800160fa;
                              _invalid_parameter_noinfo_noreturn();
                            }
                            *(undefined8 *)(puVar35 + lVar24 + -0x28) = 0x180016096;
                            FUN_180035134(ppppplVar32);
                          }
                          uVar40 = local_5f8;
                          uVar47 = local_638;
                          plVar37 = local_618;
                        }
LAB_1800160a8:
                        *(undefined8 *)(puVar35 + lVar24 + -0x28) = 0x1800160b0;
                        operator_delete__(pcVar17);
                      }
                    }
                  }
                  pcVar6 = *(code **)(*local_628 + 0x10);
                  *(undefined8 *)(puVar35 + lVar24 + -0x28) = 0x1800160ba;
                  (*pcVar6)();
                  puVar36 = puVar35 + lVar24 + -0x20;
                }
              }
              pIVar10 = local_640;
              p_Var8 = local_640->lpVtbl->Release;
              *(undefined8 *)(puVar36 + -8) = 0x1800160c4;
              (*p_Var8)(pIVar10);
            }
          }
        }
        *(undefined8 *)(puVar36 + -8) = 0x1800160cf;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_650);
        local_5f8 = uVar40 + 1;
        if (uVar47 <= local_5f8) break;
        puVar35 = puVar36;
      }
    }
    plVar31 = local_5e0;
    if ((longlong)plVar26 - (longlong)local_5e0 >> 6 != 0) {
      local_5a0.Data1 = 0;
      local_5a0.Data2 = 0;
      local_5a0.Data3 = 0;
      local_5a0.Data4[0] = '\0';
      local_5a0.Data4[1] = '\0';
      local_5a0.Data4[2] = '\0';
      local_5a0.Data4[3] = '\0';
      local_5a0.Data4[4] = '\0';
      local_5a0.Data4[5] = '\0';
      local_5a0.Data4[6] = '\0';
      local_5a0.Data4[7] = '\0';
      local_590 = (CLSID *)0x0;
      uStack_588 = 0xf;
      *(undefined8 *)(puVar36 + -8) = 0x18001613b;
      local_5a0._0_8_ = FUN_18001d210(&local_5a0,0x20);
      uVar46 = s_Software_AspenTech__1800409c8._8_8_;
      local_590 = (CLSID *)0x13;
      uStack_588 = 0x1f;
      *(undefined8 *)local_5a0._0_8_ = s_Software_AspenTech__1800409c8._0_8_;
      *(undefined8 *)((CLSID *)local_5a0._0_8_)->Data4 = uVar46;
      *(undefined2 *)&((CLSID *)(local_5a0._0_8_ + 0x10))->Data1 =
           s_Software_AspenTech__1800409c8._16_2_;
      *(char *)((longlong)&((CLSID *)(local_5a0._0_8_ + 0x10))->Data1 + 2) =
           s_Software_AspenTech__1800409c8[0x12];
      *(char *)((longlong)&((CLSID *)(local_5a0._0_8_ + 0x10))->Data1 + 3) = '\0';
      *(undefined8 *)(puVar36 + -8) = 0x180016180;
      iVar13 = FUN_180033bd0();
      *(undefined8 *)(puVar36 + -8) = 0x180016187;
      puVar22 = FUN_180033c00();
      local_518 = (undefined8 *****)0x0;
      uStack_510 = 0;
      local_508 = 0;
      local_500 = 0;
      sVar45 = 0xffffffffffffffff;
      do {
        sVar45 = sVar45 + 1;
      } while (puVar22[sVar45] != '\0');
      *(undefined8 *)(puVar36 + -8) = 0x1800161bf;
      FUN_180006e90(&local_518,puVar22,sVar45);
      if (iVar13 == 1) {
        if (uStack_588 - (longlong)local_590 < 0xb) {
          *(undefined8 *)(puVar36 + 0x20) = 0xb;
          pcVar17 = "Aspen Plus\\";
          uVar47 = 0xb;
          goto LAB_18001628c;
        }
        pCVar43 = &local_5a0;
        if (0xf < uStack_588) {
          pCVar43 = (CLSID *)local_5a0._0_8_;
        }
        puVar9 = local_590->Data4;
        local_590 = (CLSID *)(local_590->Data4 + 3);
        *(undefined8 *)(puVar36 + -8) = 0x180016215;
        memmove(pCVar43->Data4 + (longlong)(puVar9 + -0x10),"Aspen Plus\\",0xb);
        (pCVar43->Data4 + (longlong)(puVar9 + -0x10))[0xb] = 0;
      }
      else if (uStack_588 - (longlong)local_590 < 0x11) {
        *(undefined8 *)(puVar36 + 0x20) = 0x11;
        pcVar17 = "Aspen Properties\\";
        uVar47 = 0x11;
LAB_18001628c:
        *(undefined8 *)(puVar36 + -8) = 0x18001629b;
        FUN_180007e40((undefined8 *)&local_5a0,uVar47,0,pcVar17,*(size_t *)(puVar36 + 0x20));
      }
      else {
        pCVar43 = &local_5a0;
        if (0xf < uStack_588) {
          pCVar43 = (CLSID *)local_5a0._0_8_;
        }
        puVar9 = local_590->Data4;
        local_590 = (CLSID *)((longlong)&local_590[1].Data1 + 1);
        *(undefined8 *)(puVar36 + -8) = 0x180016271;
        memmove(pCVar43->Data4 + (longlong)(puVar9 + -0x10),"Aspen Properties\\",0x11);
        (pCVar43->Data4 + (longlong)(puVar9 + -0x10))[0x11] = 0;
      }
      uVar47 = local_500;
      sVar45 = local_508;
      pppppuVar11 = local_518;
      if (0x7fffffffffffffff - local_508 < 10) {
                    /* WARNING: Subroutine does not return */
        *(undefined **)(puVar36 + -8) = &UNK_180016999;
        FUN_18001d1b0();
      }
      pppppuVar42 = &local_518;
      if (0xf < local_500) {
        pppppuVar42 = local_518;
      }
      local_580 = (undefined8 *****)0x0;
      uStack_578 = 0;
      local_570 = 0;
      uStack_568 = 0;
      uVar40 = local_508 + 10;
      pppppuVar33 = &local_580;
      if (0xf < uVar40) {
        local_630 = uVar40 | 0xf;
        if (local_630 < 0x8000000000000000) {
          if (local_630 < 0x16) {
            local_630 = 0x16;
          }
          _Var1 = local_630 + 1;
          if (0xfff < _Var1) {
            uVar27 = local_630 + 0x28;
            if (uVar27 <= _Var1) {
                    /* WARNING: Subroutine does not return */
              *(undefined8 *)(puVar36 + -8) = 0x18001697b;
              FUN_18001d0c0();
            }
            goto LAB_180016321;
          }
          if (_Var1 == 0) {
            pppppuVar33 = (undefined8 *****)0x0;
          }
          else {
            *(undefined8 *)(puVar36 + -8) = 0x180016377;
            pppppuVar33 = operator_new(_Var1);
          }
        }
        else {
          local_630 = 0x7fffffffffffffff;
          uVar27 = 0x8000000000000027;
LAB_180016321:
          *(undefined8 *)(puVar36 + -8) = 0x180016329;
          ppppuVar23 = operator_new(uVar27);
          if (ppppuVar23 == (undefined8 ****)0x0) goto LAB_18001648c;
          pppppuVar33 = (undefined8 *****)((longlong)ppppuVar23 + 0x27U & 0xffffffffffffffe0);
          pppppuVar33[-1] = ppppuVar23;
        }
        local_580 = pppppuVar33;
      }
      uStack_568 = local_630;
      local_570 = uVar40;
      *(undefined8 *)(puVar36 + -8) = 0x1800163ad;
      memcpy(pppppuVar33,pppppuVar42,sVar45);
      *(undefined8 *)((longlong)pppppuVar33 + sVar45) = s__Libraries_180041e28._0_8_;
      *(undefined2 *)((longlong)pppppuVar33 + sVar45 + 8) = s__Libraries_180041e28._8_2_;
      *(undefined1 *)((longlong)pppppuVar33 + uVar40) = 0;
      uVar27 = uStack_568;
      uVar40 = local_570;
      pppppuVar42 = local_580;
      pppppuVar33 = &local_580;
      if (0xf < uStack_568) {
        pppppuVar33 = local_580;
      }
      if (uStack_588 - (longlong)local_590 < local_570) {
        *(ulonglong *)(puVar36 + 0x20) = local_570;
        *(undefined8 *)(puVar36 + -8) = 0x180016453;
        FUN_180007e40((undefined8 *)&local_5a0,uVar40,0,pppppuVar33,*(size_t *)(puVar36 + 0x20));
        pppppuVar42 = local_580;
        uVar27 = uStack_568;
      }
      else {
        pCVar43 = &local_5a0;
        if (0xf < uStack_588) {
          pCVar43 = (CLSID *)local_5a0._0_8_;
        }
        puVar9 = local_590->Data4;
        local_590 = (CLSID *)(local_590->Data4 + (local_570 - 8));
        *(undefined8 *)(puVar36 + -8) = 0x180016436;
        memmove(pCVar43->Data4 + (longlong)(puVar9 + -0x10),pppppuVar33,uVar40);
        (pCVar43->Data4 + (longlong)(puVar9 + -0x10))[uVar40] = '\0';
      }
      if (0xf < uVar27) {
        pppppuVar33 = pppppuVar42;
        if ((0xfff < uVar27 + 1) &&
           (pppppuVar33 = (undefined8 *****)pppppuVar42[-1],
           0x1f < (ulonglong)((longlong)pppppuVar42 + (-8 - (longlong)pppppuVar33)))) {
LAB_18001648c:
                    /* WARNING: Subroutine does not return */
          *(undefined **)(puVar36 + -8) = &UNK_180016492;
          _invalid_parameter_noinfo_noreturn();
        }
        *(undefined8 *)(puVar36 + -8) = 0x18001649b;
        FUN_180035134(pppppuVar33);
      }
      iVar13 = 0;
      pCVar43 = &local_5a0;
      if (0xf < uStack_588) {
        pCVar43 = (CLSID *)local_5a0._0_8_;
      }
      local_5f0 = (HKEY)0x0;
      *(HKEY **)(puVar36 + 0x20) = &local_5f0;
      *(undefined8 *)(puVar36 + -8) = 0x1800164dc;
      LVar15 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,(LPCSTR)pCVar43,0,0x2001f,
                             *(PHKEY *)(puVar36 + 0x20));
      pHVar41 = local_5f0;
      hKey = (HKEY)0x0;
      if ((LVar15 == 0) && (hKey = pHVar41, local_5f0 != (HKEY)0x0)) {
        local_258[0] = '\0';
        *(undefined8 *)(puVar36 + -8) = 0x18001650c;
        memset(local_258 + 1,0,0x103);
        local_654 = 0x104;
        local_658 = 0;
        *(char ***)(puVar36 + 0x58) = &local_5e8;
        *(ulonglong **)(puVar36 + 0x50) = &local_5f8;
        *(longlong ***)(puVar36 + 0x48) = &local_618;
        *(ulonglong **)(puVar36 + 0x40) = &local_630;
        *(longlong ***)(puVar36 + 0x38) = &local_628;
        *(HKEY **)(puVar36 + 0x30) = &local_650;
        *(LPSTORAGE **)(puVar36 + 0x28) = &local_640;
        *(uint **)(puVar36 + 0x20) = &local_658;
        uVar46 = 0;
        lpcchClass = &local_654;
        *(undefined8 *)(puVar36 + -8) = 0x180016575;
        RegQueryInfoKeyA(pHVar41,local_258,lpcchClass,(LPDWORD)0x0,*(LPDWORD *)(puVar36 + 0x20),
                         *(LPDWORD *)(puVar36 + 0x28),*(LPDWORD *)(puVar36 + 0x30),
                         *(LPDWORD *)(puVar36 + 0x38),*(LPDWORD *)(puVar36 + 0x40),
                         *(LPDWORD *)(puVar36 + 0x48),*(LPDWORD *)(puVar36 + 0x50),
                         *(PFILETIME *)(puVar36 + 0x58));
        uVar40 = (ulonglong)local_658;
        if (local_658 != 0) {
          *(undefined8 *)(puVar36 + -8) = 0x18001658c;
          FUN_18001f260("\nNumber of subkeys: %d\n",uVar40,lpcchClass,uVar46);
          DVar30 = 0;
          if (local_658 != 0) {
            do {
              local_638 = CONCAT44(local_638._4_4_,0xff);
              *(char ***)(puVar36 + 0x38) = &local_5e8;
              *(undefined8 *)(puVar36 + 0x30) = 0;
              *(undefined8 *)(puVar36 + 0x28) = 0;
              *(undefined8 *)(puVar36 + 0x20) = 0;
              lpcchName = &local_638;
              *(undefined8 *)(puVar36 + -8) = 0x1800165d5;
              LVar15 = RegEnumKeyExA(pHVar41,DVar30,&local_368,(LPDWORD)lpcchName,
                                     *(LPDWORD *)(puVar36 + 0x20),*(LPSTR *)(puVar36 + 0x28),
                                     *(LPDWORD *)(puVar36 + 0x30),*(PFILETIME *)(puVar36 + 0x38));
              if (LVar15 == 0) {
                *(undefined8 *)(puVar36 + -8) = 0x1800165ef;
                FUN_18001f260("(%d) %s\n",(ulonglong)(DVar30 + 1),&local_368,lpcchName);
                *(undefined8 *)(puVar36 + -8) = 0x1800165fc;
                iVar16 = atoi(&local_368);
                if (iVar13 < iVar16) {
                  *(undefined8 *)(puVar36 + -8) = 0x18001660d;
                  iVar13 = atoi(&local_368);
                }
              }
              DVar30 = DVar30 + 1;
            } while (DVar30 < local_658);
          }
        }
      }
      plVar37 = local_648;
      if (plVar31 != local_648) {
        plVar38 = plVar31;
        do {
          iVar13 = iVar13 + 1;
          local_3b8 = 0;
          uStack_3b0 = 0;
          local_3a8 = 0;
          uStack_3a0 = 0;
          local_398 = 0;
          uStack_390 = 0;
          local_388 = 0;
          uStack_380 = 0;
          local_378 = 0;
          uStack_370 = 0;
          *(undefined8 *)(puVar36 + -8) = 0x18001666d;
          _itoa(iVar13,(char *)&local_3b8,10);
          local_650 = (HKEY)0x0;
          *(LPSTORAGE **)(puVar36 + 0x40) = &local_640;
          *(HKEY **)(puVar36 + 0x38) = &local_650;
          *(undefined8 *)(puVar36 + 0x30) = 0;
          *(undefined4 *)(puVar36 + 0x28) = 0x2001f;
          *(undefined4 *)(puVar36 + 0x20) = 0;
          *(undefined8 *)(puVar36 + -8) = 0x1800166aa;
          LVar15 = RegCreateKeyExA(hKey,(LPCSTR)&local_3b8,0,(LPSTR)0x0,*(DWORD *)(puVar36 + 0x20),
                                   *(REGSAM *)(puVar36 + 0x28),
                                   *(LPSECURITY_ATTRIBUTES *)(puVar36 + 0x30),
                                   *(PHKEY *)(puVar36 + 0x38),*(LPDWORD *)(puVar36 + 0x40));
          pHVar41 = local_650;
          if ((LVar15 == 0) && (local_650 != (HKEY)0x0)) {
            plVar26 = plVar38;
            if (0xf < (ulonglong)plVar38[3]) {
              plVar26 = (longlong *)*plVar38;
            }
            if (plVar26 != (longlong *)0x0) {
              lVar24 = -1;
              do {
                lVar24 = lVar24 + 1;
              } while (*(char *)((longlong)plVar26 + lVar24) != '\0');
              *(int *)(puVar36 + 0x28) = (int)lVar24 + 1;
              *(longlong **)(puVar36 + 0x20) = plVar26;
              *(undefined8 *)(puVar36 + -8) = 0x18001670d;
              RegSetValueExA(pHVar41,"Display Name",0,1,*(BYTE **)(puVar36 + 0x20),
                             *(DWORD *)(puVar36 + 0x28));
            }
            plVar26 = plVar38 + 4;
            if (0xf < (ulonglong)plVar38[7]) {
              plVar26 = (longlong *)*plVar26;
            }
            if (plVar26 != (longlong *)0x0) {
              lVar24 = -1;
              do {
                lVar24 = lVar24 + 1;
              } while (*(char *)((longlong)plVar26 + lVar24) != '\0');
              *(int *)(puVar36 + 0x28) = (int)lVar24 + 1;
              *(longlong **)(puVar36 + 0x20) = plVar26;
              *(undefined8 *)(puVar36 + -8) = 0x180016754;
              RegSetValueExA(pHVar41,"Path",0,1,*(BYTE **)(puVar36 + 0x20),
                             *(DWORD *)(puVar36 + 0x28));
            }
            local_638 = local_638 & 0xffffffff00000000;
            *(undefined4 *)(puVar36 + 0x28) = 4;
            *(ulonglong **)(puVar36 + 0x20) = &local_638;
            *(undefined8 *)(puVar36 + -8) = 0x180016785;
            RegSetValueExA(pHVar41,"Active",0,4,*(BYTE **)(puVar36 + 0x20),
                           *(DWORD *)(puVar36 + 0x28));
            local_638 = local_638 & 0xffffffff00000000;
            *(undefined4 *)(puVar36 + 0x28) = 4;
            *(ulonglong **)(puVar36 + 0x20) = &local_638;
            *(undefined8 *)(puVar36 + -8) = 0x1800167b6;
            RegSetValueExA(pHVar41,"Position",0,4,*(BYTE **)(puVar36 + 0x20),
                           *(DWORD *)(puVar36 + 0x28));
            *(undefined8 *)(puVar36 + -8) = 0x1800167bf;
            RegCloseKey(pHVar41);
          }
          plVar38 = plVar38 + 8;
        } while (plVar38 != plVar37);
        uVar47 = local_500;
      }
      if (hKey != (HKEY)0x0) {
        *(undefined8 *)(puVar36 + -8) = 0x1800167e3;
        RegCloseKey(hKey);
      }
      if (0xf < uVar47) {
        pppppuVar42 = pppppuVar11;
        if ((0xfff < uVar47 + 1) &&
           (pppppuVar42 = (undefined8 *****)pppppuVar11[-1],
           0x1f < (ulonglong)((longlong)pppppuVar11 + (-8 - (longlong)pppppuVar42)))) {
                    /* WARNING: Subroutine does not return */
          *(undefined **)(puVar36 + -8) = &UNK_180016816;
          _invalid_parameter_noinfo_noreturn();
        }
        *(undefined8 *)(puVar36 + -8) = 0x18001681f;
        FUN_180035134(pppppuVar42);
      }
      if (0xf < uStack_588) {
        pCVar43 = (CLSID *)local_5a0._0_8_;
        if ((0xfff < uStack_588 + 1) &&
           (pCVar43 = *(CLSID **)((CLSID *)(local_5a0._0_8_ + -0x10))->Data4,
           (char *)0x1f < (char *)(local_5a0._0_8_ + (-8 - (longlong)pCVar43)))) {
                    /* WARNING: Subroutine does not return */
          *(undefined **)(puVar36 + -8) = &UNK_18001685e;
          _invalid_parameter_noinfo_noreturn();
        }
        *(undefined8 *)(puVar36 + -8) = 0x180016864;
        FUN_180035134(pCVar43);
      }
      plVar26 = local_648;
    }
    plVar29 = local_610;
    plVar34 = local_620;
    plVar37 = local_600;
    plVar38 = local_608;
  }
  if (plVar34 != (longlong *)0x0) {
    *(undefined8 *)(puVar36 + -8) = 0x18001688c;
    FUN_180007060(plVar34,plVar29);
    plVar29 = plVar34;
    if ((0xfff < ((longlong)plVar38 - (longlong)plVar34 & 0xffffffffffffffe0U)) &&
       (plVar29 = (longlong *)plVar34[-1],
       0x1f < (ulonglong)((longlong)plVar34 + (-8 - (longlong)plVar29)))) {
                    /* WARNING: Subroutine does not return */
      *(undefined **)(puVar36 + -8) = &UNK_1800168ba;
      _invalid_parameter_noinfo_noreturn();
    }
    *(undefined8 *)(puVar36 + -8) = 0x1800168e1;
    FUN_180035134(plVar29);
  }
  plVar38 = plVar31;
  if (plVar31 != (longlong *)0x0) {
    for (; plVar38 != plVar26; plVar38 = plVar38 + 8) {
      *(undefined8 *)(puVar36 + -8) = 0x1800168f8;
      FUN_180008b00(plVar38);
    }
    plVar38 = plVar31;
    if ((0xfff < ((longlong)plVar37 - (longlong)plVar31 & 0xffffffffffffffc0U)) &&
       (plVar38 = (longlong *)plVar31[-1],
       0x1f < (ulonglong)((longlong)plVar31 + (-8 - (longlong)plVar38)))) {
                    /* WARNING: Subroutine does not return */
      *(undefined **)(puVar36 + -8) = &UNK_18001692f;
      _invalid_parameter_noinfo_noreturn();
    }
    *(undefined8 *)(puVar36 + -8) = 0x18001693b;
    FUN_180035134(plVar38);
  }
LAB_18001693b:
  *(undefined8 *)(puVar36 + -8) = 0x18001694a;
  return;
code_r0x000180015cf7:
  ppppplVar32 = ppppplVar32 + 4;
  if (ppppplVar32 == (longlong *****)plVar37[1]) goto LAB_1800160a8;
  goto LAB_180015cc1;
}

/* RVA 0x169a0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Removing unreachable block (ram,0x000180017e26) */
/* WARNING: Removing unreachable block (ram,0x0001800182d6) */

void FUN_1800169a0(undefined8 param_1,char *param_2,DWORD param_3)

{
  char cVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  LSTATUS LVar5;
  FILE *pFVar6;
  char *pcVar7;
  char *****pppppcVar8;
  HKEY pHVar9;
  char *****pppppcVar10;
  longlong lVar11;
  rsize_t _MaxCount;
  undefined *puVar12;
  ulonglong uVar13;
  char ****ppppcVar14;
  HMODULE hModule;
  __uint64 _Var15;
  LPCWSTR lpWideCharStr;
  longlong lVar16;
  void *pvVar17;
  longlong *_Buf1;
  ulonglong uVar18;
  ulonglong uVar19;
  HKEY pHVar20;
  longlong *plVar21;
  HKEY pHVar22;
  undefined1 *puVar23;
  undefined1 *puVar24;
  longlong *plVar25;
  char *****pppppcVar26;
  size_t sVar27;
  ulonglong uVar28;
  size_t sVar29;
  LPDWORD lpcchClass;
  HKEY *lpcchName;
  char *pcVar30;
  int *piVar31;
  longlong *plVar32;
  char *pcVar33;
  undefined8 *****pppppuVar34;
  undefined8 *****pppppuVar35;
  ulonglong uVar36;
  undefined8 uVar37;
  DWORD dwIndex;
  char *pcVar38;
  HKEY pHVar39;
  bool bVar40;
  undefined *puStackY_c20;
  undefined1 auStackY_c18 [32];
  DWORD local_bb8;
  DWORD local_bb4;
  HKEY local_bb0;
  HKEY local_ba8;
  longlong *local_ba0;
  longlong *plStack_b98;
  longlong *local_b90;
  FILE *local_b88;
  HKEY local_b80;
  HKEY pHStack_b78;
  HKEY local_b70;
  DWORD local_b68 [2];
  char *local_b60;
  undefined4 local_b58;
  DWORD local_b54;
  HKEY local_b50;
  undefined4 local_b48;
  undefined8 local_b40;
  ulonglong local_b38;
  undefined8 local_b30;
  _FILETIME local_b28;
  DWORD local_b20;
  DWORD local_b1c;
  DWORD local_b18 [2];
  longlong local_b10;
  undefined8 local_b08;
  longlong lStack_b00;
  undefined8 local_af8;
  undefined8 uStack_af0;
  char *****local_ae8;
  longlong lStack_ae0;
  ulonglong local_ad8;
  ulonglong uStack_ad0;
  char *****local_ac8;
  undefined8 uStack_ac0;
  longlong local_ab8;
  ulonglong local_ab0;
  HKEY local_aa8;
  ulonglong uStack_aa0;
  ulonglong local_a98;
  ulonglong local_a90;
  undefined8 *****local_a88;
  undefined8 uStack_a80;
  size_t local_a78;
  undefined8 local_a70;
  char local_a68 [10];
  char acStack_a5e [262];
  char local_958 [1024];
  BYTE local_558 [272];
  BYTE local_448 [1024];
  ulonglong local_48;
  
  puVar23 = auStackY_c18;
  local_48 = DAT_180052888 ^ (ulonglong)&local_bb8;
  if (3 < param_3) goto LAB_1800183d3;
  local_ba0 = (longlong *)0x0;
  plStack_b98 = (longlong *)0x0;
  local_b90 = (longlong *)0x0;
  local_bb8 = param_3;
  local_b30 = param_1;
  if (2 < param_3 - 1) goto LAB_18001721e;
  puStackY_c20 = (undefined *)0x180016a15;
  pFVar6 = fopen(param_2,"r");
  local_b88 = pFVar6;
  if (pFVar6 != (FILE *)0x0) {
    pcVar38 = "startlibrary\n";
    bVar40 = param_3 == 3;
    if (bVar40) {
      pcVar38 = ";startlibrary\n";
    }
    pcVar33 = "endlibrary\n";
    if (bVar40) {
      pcVar33 = ";endlibrary\n";
    }
    pcVar30 = "NumLibs = ";
    if (bVar40) {
      pcVar30 = ";NumLibs = ";
    }
    puStackY_c20 = (undefined *)0x180016a7a;
    local_bb0 = (HKEY)pcVar33;
    local_b60 = pcVar30;
    memset(local_958,0,0x400);
    lStack_ae0 = 0;
    local_ad8 = 0;
    uVar36 = 0xf;
    uStack_ad0 = 0xf;
    local_ae8 = (char *****)0x0;
    puStackY_c20 = (undefined *)0x180016ab4;
    pcVar7 = fgets(local_958,0x400,pFVar6);
    if (pcVar7 != (char *)0x0) {
      do {
        uVar18 = 0xffffffffffffffff;
        sVar29 = 0xffffffffffffffff;
        do {
          sVar27 = sVar29 + 1;
          lVar11 = sVar29 + 1;
          sVar29 = sVar27;
        } while (local_958[lVar11] != '\0');
        puStackY_c20 = (undefined *)0x180016aee;
        FUN_18001d350((longlong *)&local_ae8,local_958,sVar27);
        uVar36 = uStack_ad0;
        uVar13 = local_ad8;
        pppppcVar26 = local_ae8;
        do {
          uVar18 = uVar18 + 1;
        } while (pcVar38[uVar18] != '\0');
        pppppcVar10 = (char *****)&local_ae8;
        if (0xf < uStack_ad0) {
          pppppcVar10 = local_ae8;
        }
        uVar19 = local_ad8;
        if (uVar18 < local_ad8) {
          uVar19 = uVar18;
        }
        puStackY_c20 = (undefined *)0x180016b30;
        iVar3 = memcmp(pppppcVar10,pcVar38,uVar19);
        if (((iVar3 == 0) && (uVar18 <= uVar13)) && (uVar13 <= uVar18)) {
          puStackY_c20 = (undefined *)0x180016bbe;
          pcVar38 = fgets(local_958,0x400,local_b88);
          if (pcVar38 != (char *)0x0) goto LAB_180016bd0;
          break;
        }
        puStackY_c20 = (undefined *)0x180016b51;
        pcVar7 = fgets(local_958,0x400,local_b88);
      } while (pcVar7 != (char *)0x0);
      goto LAB_180016b5a;
    }
    pppppcVar26 = local_ae8;
    goto LAB_180016b5f;
  }
  goto LAB_1800176d8;
LAB_180016bd0:
  uVar18 = 0xffffffffffffffff;
  sVar29 = 0xffffffffffffffff;
  do {
    sVar27 = sVar29 + 1;
    lVar11 = sVar29 + 1;
    sVar29 = sVar27;
  } while (local_958[lVar11] != '\0');
  puStackY_c20 = (undefined *)0x180016bfe;
  FUN_18001d350((longlong *)&local_ae8,local_958,sVar27);
  uVar36 = uStack_ad0;
  uVar13 = local_ad8;
  pppppcVar26 = local_ae8;
  uVar19 = 0xffffffffffffffff;
  do {
    uVar19 = uVar19 + 1;
  } while (*(char *)((longlong)&((HKEY)pcVar33)->unused + uVar19) != '\0');
  bVar40 = 0xf < uStack_ad0;
  pppppcVar10 = (char *****)&local_ae8;
  if (bVar40) {
    pppppcVar10 = local_ae8;
  }
  uVar28 = local_ad8;
  if (uVar19 < local_ad8) {
    uVar28 = uVar19;
  }
  puStackY_c20 = (undefined *)0x180016c46;
  iVar3 = memcmp(pppppcVar10,local_bb0,uVar28);
  if (((iVar3 == 0) && (uVar19 <= uVar13)) && (uVar13 <= uVar19)) goto LAB_180016b5a;
  do {
    uVar18 = uVar18 + 1;
  } while (pcVar30[uVar18] != '\0');
  pppppcVar10 = (char *****)&local_ae8;
  if (bVar40) {
    pppppcVar10 = pppppcVar26;
  }
  if (uVar18 <= uVar13) {
    uVar19 = uVar13 - uVar18;
    local_b38 = uVar19;
    if (uVar18 == 0) {
LAB_180016cf2:
      if (uVar18 < uVar13) {
        local_aa8 = (HKEY)0x0;
        uStack_aa0 = 0;
        local_a98 = 0;
        local_a90 = 0;
        if (uVar13 < uVar18) {
                    /* WARNING: Subroutine does not return */
          puStackY_c20 = &UNK_18001840d;
          FUN_18001d1f0();
        }
        uVar13 = 0xffffffffffffffff;
        if (local_b38 != 0xffffffffffffffff) {
          uVar13 = local_b38;
        }
        pppppcVar10 = (char *****)&local_ae8;
        if (0xf < uVar36) {
          pppppcVar10 = pppppcVar26;
        }
        if (0x7fffffffffffffff < uVar13) {
                    /* WARNING: Subroutine does not return */
          puStackY_c20 = (undefined *)0x180018413;
          FUN_18001d1b0();
        }
        local_a90 = 0xf;
        if (uVar13 < 0x10) {
          puStackY_c20 = (undefined *)0x180016da3;
          local_a98 = uVar13;
          memcpy(&local_aa8,(char *)((longlong)pppppcVar10 + uVar18),uVar13);
          local_a68[uVar13 - 0x40] = '\0';
        }
        else {
          uVar19 = uVar13 | 0xf;
          if (uVar19 < 0x8000000000000000) {
            if (uVar19 < 0x16) {
              uVar19 = 0x16;
            }
          }
          else {
            uVar19 = 0x7fffffffffffffff;
          }
          puStackY_c20 = (undefined *)0x180016ddb;
          pHVar9 = FUN_18001d210(&local_aa8,uVar19 + 1);
          puStackY_c20 = (undefined *)0x180016e01;
          local_aa8 = pHVar9;
          local_a98 = uVar13;
          local_a90 = uVar19;
          memcpy(pHVar9,(char *)((longlong)pppppcVar10 + uVar18),uVar13);
          *(char *)((longlong)&pHVar9->unused + uVar13) = '\0';
        }
        pHVar9 = (HKEY)&local_aa8;
        if (0xf < local_a90) {
          pHVar9 = local_aa8;
        }
        puStackY_c20 = (undefined *)0x180016e25;
        local_bb4 = atoi((char *)pHVar9);
        if ((int)local_bb4 < 1) goto LAB_1800171b6;
        iVar3 = 0;
        goto LAB_180016e40;
      }
    }
    else {
      puStackY_c20 = (undefined *)0x180016ca2;
      for (pppppcVar8 = memchr(pppppcVar10,(int)*local_b60,uVar19 + 1);
          pppppcVar8 != (char *****)0x0;
          pppppcVar8 = memchr((char *)((longlong)pppppcVar8 + 1),(int)*local_b60,
                              (size_t)((longlong)pppppcVar10 +
                                      ((uVar19 + 1) - ((longlong)pppppcVar8 + 1))))) {
        puStackY_c20 = (undefined *)0x180016cbf;
        iVar3 = memcmp(pppppcVar8,local_b60,uVar18);
        if (iVar3 == 0) {
          if (pppppcVar8 == pppppcVar10) goto LAB_180016cf2;
          break;
        }
        puStackY_c20 = (undefined *)0x180016cdc;
      }
    }
  }
  puStackY_c20 = (undefined *)0x180016d0d;
  pcVar38 = fgets(local_958,0x400,local_b88);
  if (pcVar38 == (char *)0x0) goto LAB_180016b5a;
  pcVar30 = local_b60;
  pcVar33 = (char *)local_bb0;
  goto LAB_180016bd0;
LAB_180016e40:
  do {
    puStackY_c20 = (undefined *)0x180016e56;
    pcVar38 = fgets(local_958,0x400,local_b88);
    if (pcVar38 != (char *)0x0) {
      sVar29 = 0xffffffffffffffff;
      do {
        sVar27 = sVar29 + 1;
        lVar11 = sVar29 + 1;
        sVar29 = sVar27;
      } while (local_958[lVar11] != '\0');
      puStackY_c20 = (undefined *)0x180016e8d;
      FUN_18001d350((longlong *)&local_ae8,local_958,sVar27);
      while( true ) {
        uVar36 = uStack_ad0;
        uVar18 = local_ad8;
        pppppcVar26 = local_ae8;
        bVar40 = 0xf < uStack_ad0;
        pppppcVar10 = (char *****)&local_ae8;
        if (bVar40) {
          pppppcVar10 = local_ae8;
        }
        if (*(char *)((longlong)pppppcVar10 + (local_ad8 - 1)) != '\n') break;
        uVar36 = local_ad8 - 1;
        if (local_ad8 < uVar36) goto LAB_180018414;
        local_ad8 = uVar36;
        pppppcVar26 = (char *****)&local_ae8;
        if (0xf < uStack_ad0) {
          pppppcVar26 = local_ae8;
        }
        *(char *)((longlong)pppppcVar26 + uVar36) = '\0';
      }
      pppppcVar10 = (char *****)&local_ae8;
      if (bVar40) {
        pppppcVar10 = local_ae8;
      }
      uVar13 = local_ad8;
      if (8 < local_ad8) {
        uVar13 = 8;
      }
      puStackY_c20 = (undefined *)0x180016f12;
      iVar4 = memcmp(pppppcVar10,"Built-In",uVar13);
      if (iVar4 == 0) {
        if (uVar18 == 8) goto LAB_1800171a9;
      }
      pppppcVar10 = (char *****)&local_ae8;
      if (bVar40) {
        pppppcVar10 = pppppcVar26;
      }
      uVar13 = uVar18;
      if (9 < uVar18) {
        uVar13 = 9;
      }
      puStackY_c20 = (undefined *)0x180016f4d;
      iVar4 = memcmp(pppppcVar10,"CAPE-OPEN",uVar13);
      if (iVar4 == 0) {
        if (uVar18 == 9) goto LAB_1800171a9;
      }
      pppppcVar10 = (char *****)&local_ae8;
      if (bVar40) {
        pppppcVar10 = pppppcVar26;
      }
      uVar19 = uVar18;
      if (10 < uVar18) {
        uVar19 = 10;
      }
      puStackY_c20 = (undefined *)0x180016f88;
      iVar4 = memcmp(pppppcVar10,"ACM Models",uVar19);
      if (iVar4 == 0) {
        if (uVar18 == 10) goto LAB_1800171a9;
      }
      pppppcVar10 = (char *****)&local_ae8;
      if (bVar40) {
        pppppcVar10 = pppppcVar26;
      }
      uVar28 = uVar18;
      if (0xc < uVar18) {
        uVar28 = 0xc;
      }
      puStackY_c20 = (undefined *)0x180016fc0;
      iVar4 = memcmp(pppppcVar10,"ACM Built-In",uVar28);
      if (iVar4 == 0) {
        if (uVar18 == 0xc) goto LAB_1800171a9;
      }
      pppppcVar10 = (char *****)&local_ae8;
      if (bVar40) {
        pppppcVar10 = pppppcVar26;
      }
      puStackY_c20 = (undefined *)0x180016feb;
      iVar4 = memcmp(pppppcVar10,";Built-In",uVar13);
      if (iVar4 == 0) {
        if (uVar18 == 9) goto LAB_1800171a9;
      }
      pppppcVar10 = (char *****)&local_ae8;
      if (bVar40) {
        pppppcVar10 = pppppcVar26;
      }
      puStackY_c20 = (undefined *)0x180017016;
      iVar4 = memcmp(pppppcVar10,";CAPE-OPEN",uVar19);
      if (iVar4 == 0) {
        if (uVar18 == 10) goto LAB_1800171a9;
      }
      pppppcVar10 = (char *****)&local_ae8;
      if (bVar40) {
        pppppcVar10 = pppppcVar26;
      }
      uVar13 = uVar18;
      if (0xb < uVar18) {
        uVar13 = 0xb;
      }
      puStackY_c20 = (undefined *)0x18001704e;
      iVar4 = memcmp(pppppcVar10,";ACM Models",uVar13);
      if (iVar4 == 0) {
        if (uVar18 == 0xb) goto LAB_1800171a9;
      }
      pppppcVar10 = (char *****)&local_ae8;
      if (bVar40) {
        pppppcVar10 = pppppcVar26;
      }
      uVar13 = uVar18;
      if (0xd < uVar18) {
        uVar13 = 0xd;
      }
      puStackY_c20 = (undefined *)0x180017086;
      iVar4 = memcmp(pppppcVar10,";ACM Built-In",uVar13);
      if (iVar4 == 0) {
        if (uVar18 == 0xd) goto LAB_1800171a9;
      }
      if (local_bb8 == 3) {
        pppppcVar10 = (char *****)&local_ae8;
        if (bVar40) {
          pppppcVar10 = pppppcVar26;
        }
        if (*(char *)pppppcVar10 == ';') {
          local_b08 = (char *****)0x0;
          lStack_b00 = 0;
          local_af8 = 0;
          uStack_af0 = 0;
          if (uVar18 == 0) {
LAB_180018414:
                    /* WARNING: Subroutine does not return */
            puStackY_c20 = (undefined *)0x180018419;
            FUN_18001d1f0();
          }
          sVar29 = 0xffffffffffffffff;
          if (uVar18 - 1 != 0xffffffffffffffff) {
            sVar29 = uVar18 - 1;
          }
          pppppcVar10 = (char *****)&local_ae8;
          if (bVar40) {
            pppppcVar10 = pppppcVar26;
          }
          puStackY_c20 = (undefined *)0x180017108;
          FUN_180006e90(&local_b08,(char *)((longlong)pppppcVar10 + 1),sVar29);
          if (0xf < uStack_ad0) {
            pppppcVar26 = local_ae8;
            if ((0xfff < uStack_ad0 + 1) &&
               (pppppcVar26 = (char *****)local_ae8[-1],
               (char *)0x1f < (char *)((longlong)local_ae8 + (-8 - (longlong)pppppcVar26)))) {
                    /* WARNING: Subroutine does not return */
              puStackY_c20 = &UNK_1800171ff;
              _invalid_parameter_noinfo_noreturn();
            }
            puStackY_c20 = (undefined *)0x180017149;
            FUN_180035134(pppppcVar26);
          }
          local_ae8 = local_b08;
          lStack_ae0 = lStack_b00;
          local_ad8 = local_af8;
          uStack_ad0 = uStack_af0;
        }
      }
      plVar32 = plStack_b98;
      if (plStack_b98 == local_b90) {
        puStackY_c20 = (undefined *)0x18001719b;
        FUN_180007680((longlong *)&local_ba0,plStack_b98,&local_ae8);
      }
      else {
        puStackY_c20 = (undefined *)0x18001717e;
        FUN_180008630(plStack_b98,&local_ae8);
        plStack_b98 = plVar32 + 4;
      }
      pppppcVar26 = local_ae8;
      uVar36 = uStack_ad0;
    }
LAB_1800171a9:
    iVar3 = iVar3 + 1;
  } while (iVar3 < (int)local_bb4);
LAB_1800171b6:
  if (0xf < local_a90) {
    pHVar9 = local_aa8;
    if ((0xfff < local_a90 + 1) &&
       (pHVar9 = *(HKEY *)(local_aa8 + -2),
       (char *)0x1f < (char *)((longlong)local_aa8 + (-8 - (longlong)pHVar9)))) {
                    /* WARNING: Subroutine does not return */
      puStackY_c20 = &UNK_1800171f8;
      _invalid_parameter_noinfo_noreturn();
    }
    puStackY_c20 = (undefined *)0x180017205;
    FUN_180035134(pHVar9);
  }
LAB_180016b5a:
  param_3 = local_bb8;
LAB_180016b5f:
  puStackY_c20 = (undefined *)0x180016b69;
  fclose(local_b88);
  if (0xf < uVar36) {
    pppppcVar10 = pppppcVar26;
    if ((0xfff < uVar36 + 1) &&
       (pppppcVar10 = (char *****)pppppcVar26[-1],
       (char *)0x1f < (char *)((longlong)pppppcVar26 + (-8 - (longlong)pppppcVar10)))) {
                    /* WARNING: Subroutine does not return */
      puStackY_c20 = &UNK_180016ba7;
      _invalid_parameter_noinfo_noreturn();
    }
    puStackY_c20 = (undefined *)0x18001721e;
    FUN_180035134(pppppcVar10);
  }
LAB_18001721e:
  puVar24 = auStackY_c18;
  if (param_3 == 0) {
    local_ba8 = (HKEY)((ulonglong)local_ba8 & 0xffffffff00000000);
    puStackY_c20 = (undefined *)0x180017233;
    lVar11 = MDgetlibptr(&local_ba8);
    if ((lVar11 != 0) && (0 < (int)local_ba8)) {
      local_bb4 = *(DWORD *)(lVar11 + 4);
      piVar31 = (int *)(lVar11 + 8);
      if (0 < (int)local_bb4) {
        local_b80 = (HKEY)0x0;
        pHStack_b78 = (HKEY)0x0;
        pHVar39 = (HKEY)0x0;
        local_bb0 = (HKEY)0x0;
        local_b70 = (HKEY)0x0;
        iVar3 = 0;
        pHVar9 = (HKEY)0x0;
        do {
          pHVar22 = local_b80;
          _MaxCount = (rsize_t)*piVar31;
          if (*piVar31 < 1) {
            if (local_b80 == (HKEY)0x0) goto LAB_1800176d8;
            pHVar20 = local_b80;
            if (local_b80 != pHVar9) goto LAB_180017650;
            goto LAB_18001769e;
          }
          puStackY_c20 = (undefined *)0x180017290;
          pcVar38 = operator_new__(_MaxCount + 1);
          puStackY_c20 = (undefined *)0x1800172a6;
          strncpy_s(pcVar38,_MaxCount + 1,(char *)(piVar31 + 1),_MaxCount);
          pcVar38[_MaxCount] = '\0';
          piVar31 = (int *)((longlong)(piVar31 + 1) + _MaxCount);
          local_b08 = (char *****)0x0;
          lStack_b00 = 0;
          local_af8 = 0;
          uStack_af0 = 0;
          sVar29 = 0xffffffffffffffff;
          do {
            sVar29 = sVar29 + 1;
          } while (pcVar38[sVar29] != '\0');
          puStackY_c20 = (undefined *)0x1800172e8;
          FUN_180006e90(&local_b08,pcVar38,sVar29);
          if (pHVar9 == pHVar39) {
            puStackY_c20 = (undefined *)0x18001732c;
            FUN_1800077a0((longlong *)&local_b80,(longlong *)pHVar9,&local_b08);
            local_bb0 = local_b70;
            uVar36 = uStack_af0;
            pHVar39 = local_b70;
          }
          else {
            *(char ******)pHVar9 = local_b08;
            *(longlong *)(pHVar9 + 2) = lStack_b00;
            pHVar9[4].unused = (int)local_af8;
            pHVar9[5].unused = local_af8._4_4_;
            pHVar9[6].unused = (int)uStack_af0;
            pHVar9[7].unused = uStack_af0._4_4_;
            local_b08 = (char *****)((ulonglong)local_b08 & 0xffffffffffffff00);
            pHStack_b78 = pHVar9 + 8;
            uVar36 = 0xf;
          }
          pHVar9 = pHStack_b78;
          if (0xf < uVar36) {
            pppppcVar26 = local_b08;
            if ((0xfff < uVar36 + 1) &&
               (pppppcVar26 = (char *****)local_b08[-1],
               (char *)0x1f < (char *)((longlong)local_b08 + (-8 - (longlong)pppppcVar26)))) {
                    /* WARNING: Subroutine does not return */
              puStackY_c20 = &UNK_18001747f;
              _invalid_parameter_noinfo_noreturn();
            }
            puStackY_c20 = (undefined *)0x180017379;
            FUN_180035134(pppppcVar26);
          }
          puStackY_c20 = (undefined *)0x180017381;
          operator_delete__(pcVar38);
          iVar3 = iVar3 + 1;
        } while (iVar3 < (int)local_bb4);
        pFVar6 = (FILE *)0x0;
        local_b88 = (FILE *)((longlong)pHVar9 - (longlong)local_b80 >> 5);
        if (local_b88 != (FILE *)0x0) {
          pHVar9 = local_b80;
          plVar32 = plStack_b98;
          do {
            uVar36 = *(ulonglong *)(pHVar9 + 6);
            pHVar39 = pHVar9;
            if (0xf < uVar36) {
              pHVar39 = *(HKEY *)pHVar9;
            }
            lVar11 = *(longlong *)(pHVar9 + 4);
            if (lVar11 == 8) {
              puStackY_c20 = (undefined *)0x1800173e8;
              iVar3 = memcmp(pHVar39,"Built-In",8);
              if (iVar3 != 0) goto LAB_1800173f0;
            }
            else {
LAB_1800173f0:
              pHVar39 = pHVar9;
              if (0xf < uVar36) {
                pHVar39 = *(HKEY *)pHVar9;
              }
              if (lVar11 == 0xc) {
                puStackY_c20 = (undefined *)0x180017411;
                iVar3 = memcmp(pHVar39,"ACM Built-In",0xc);
                if (iVar3 == 0) goto LAB_180017493;
              }
              pHVar39 = pHVar9;
              if (0xf < uVar36) {
                pHVar39 = *(HKEY *)pHVar9;
              }
              if (lVar11 == 9) {
                puStackY_c20 = (undefined *)0x180017436;
                iVar3 = memcmp(pHVar39,"CAPE-OPEN",9);
                if (iVar3 == 0) goto LAB_180017493;
              }
              pHVar39 = pHVar9;
              if (0xf < uVar36) {
                pHVar39 = *(HKEY *)pHVar9;
              }
              if (lVar11 == 10) {
                puStackY_c20 = (undefined *)0x18001745a;
                iVar3 = memcmp(pHVar39,"ACM Models",10);
                if (iVar3 == 0) goto LAB_180017493;
              }
              if (plVar32 == local_b90) {
                puStackY_c20 = (undefined *)0x18001748f;
                FUN_180007680((longlong *)&local_ba0,plVar32,(undefined8 *)pHVar9);
                plVar32 = plStack_b98;
              }
              else {
                puStackY_c20 = (undefined *)0x18001746f;
                FUN_180008630(plVar32,(undefined8 *)pHVar9);
                plStack_b98 = plVar32 + 4;
                plVar32 = plStack_b98;
              }
            }
LAB_180017493:
            pFVar6 = (FILE *)((longlong)&pFVar6->_ptr + 1);
            pHVar9 = pHVar9 + 8;
          } while (pFVar6 < local_b88);
          pHVar9 = pHStack_b78;
          pHVar39 = local_bb0;
        }
        pHVar22 = local_b80;
        if (local_b80 != (HKEY)0x0) {
          puStackY_c20 = (undefined *)0x1800174c6;
          FUN_180007060((longlong *)local_b80,(longlong *)pHVar9);
          pHVar9 = pHVar22;
          if ((0xfff < ((longlong)pHVar39 - (longlong)pHVar22 & 0xffffffffffffffe0U)) &&
             (pHVar9 = *(HKEY *)(pHVar22 + -2),
             0x1f < (ulonglong)((longlong)pHVar22 + (-8 - (longlong)pHVar9)))) {
LAB_1800176c6:
                    /* WARNING: Subroutine does not return */
            puStackY_c20 = &UNK_1800176cc;
            _invalid_parameter_noinfo_noreturn();
          }
          puStackY_c20 = (undefined *)0x1800174fd;
          FUN_180035134(pHVar9);
        }
        goto LAB_1800174fd;
      }
    }
    goto LAB_1800176d8;
  }
LAB_1800174fd:
  plVar32 = local_ba0;
  puVar23 = auStackY_c18;
  if ((longlong)plStack_b98 - (longlong)local_ba0 >> 5 != 0) {
    local_ac8 = (char *****)0x0;
    uStack_ac0 = 0;
    local_ab8 = 0;
    local_ab0 = 0xf;
    puStackY_c20 = (undefined *)0x180017545;
    local_ac8 = FUN_18001d210(&local_ac8,0x20);
    uVar37 = s_Software_AspenTech__1800409c8._8_8_;
    local_ab8 = 0x13;
    local_ab0 = 0x1f;
    *local_ac8 = (char ****)s_Software_AspenTech__1800409c8._0_8_;
    local_ac8[1] = (char ****)uVar37;
    *(undefined2 *)(local_ac8 + 2) = s_Software_AspenTech__1800409c8._16_2_;
    *(char *)((longlong)local_ac8 + 0x12) = s_Software_AspenTech__1800409c8[0x12];
    *(char *)((longlong)local_ac8 + 0x13) = '\0';
    puStackY_c20 = (undefined *)0x18001758a;
    iVar3 = FUN_180033bd0();
    puStackY_c20 = (undefined *)0x180017591;
    puVar12 = FUN_180033c00();
    local_a88 = (undefined8 *****)0x0;
    uStack_a80 = 0;
    local_a78 = 0;
    local_a70 = 0;
    sVar29 = 0xffffffffffffffff;
    do {
      sVar29 = sVar29 + 1;
    } while (puVar12[sVar29] != '\0');
    puStackY_c20 = (undefined *)0x1800175c9;
    FUN_180006e90(&local_a88,puVar12,sVar29);
    if (iVar3 == 1) {
      if (local_ab0 - local_ab8 < 0xb) {
        sVar29 = 0xb;
        pcVar38 = "Aspen Plus\\";
        uVar36 = 0xb;
        goto LAB_18001774d;
      }
      pppppcVar26 = (char *****)&local_ac8;
      if (0xf < local_ab0) {
        pppppcVar26 = local_ac8;
      }
      pcVar38 = (char *)((longlong)pppppcVar26 + local_ab8);
      puStackY_c20 = (undefined *)0x180017627;
      local_ab8 = local_ab8 + 0xb;
      memmove(pcVar38,"Aspen Plus\\",0xb);
      pcVar38[0xb] = '\0';
    }
    else if (local_ab0 - local_ab8 < 0x11) {
      sVar29 = 0x11;
      pcVar38 = "Aspen Properties\\";
      uVar36 = 0x11;
LAB_18001774d:
      puStackY_c20 = (undefined *)0x18001775c;
      FUN_180007e40(&local_ac8,uVar36,0,pcVar38,sVar29);
    }
    else {
      pppppcVar26 = (char *****)&local_ac8;
      if (0xf < local_ab0) {
        pppppcVar26 = local_ac8;
      }
      pcVar38 = (char *)((longlong)pppppcVar26 + local_ab8);
      puStackY_c20 = (undefined *)0x180017732;
      local_ab8 = local_ab8 + 0x11;
      memmove(pcVar38,"Aspen Properties\\",0x11);
      pcVar38[0x11] = '\0';
    }
    sVar29 = local_a78;
    pppppuVar34 = local_a88;
    if (0x7fffffffffffffff - local_a78 < 10) {
                    /* WARNING: Subroutine does not return */
      puStackY_c20 = &UNK_18001841f;
      FUN_18001d1b0();
    }
    pppppuVar35 = &local_a88;
    if (0xf < local_a70) {
      pppppuVar35 = local_a88;
    }
    local_b08 = (char *****)0x0;
    lStack_b00 = 0;
    local_af8 = 0;
    uStack_af0 = 0;
    uVar36 = local_a78 + 10;
    uVar18 = 0xf;
    pppppcVar26 = (char *****)&local_b08;
    if (0xf < uVar36) {
      uVar18 = uVar36 | 0xf;
      if (uVar18 < 0x8000000000000000) {
        if (uVar18 < 0x16) {
          uVar18 = 0x16;
        }
        _Var15 = uVar18 + 1;
        if (0xfff < _Var15) {
          uVar13 = uVar18 + 0x28;
          if (uVar13 <= _Var15) {
                    /* WARNING: Subroutine does not return */
            puStackY_c20 = (undefined *)0x180018407;
            FUN_18001d0c0();
          }
          goto LAB_1800177de;
        }
        if (_Var15 == 0) {
          pppppcVar26 = (char *****)0x0;
        }
        else {
          puStackY_c20 = (undefined *)0x180017830;
          pppppcVar26 = operator_new(_Var15);
        }
      }
      else {
        uVar18 = 0x7fffffffffffffff;
        uVar13 = 0x8000000000000027;
LAB_1800177de:
        puStackY_c20 = (undefined *)0x1800177e6;
        ppppcVar14 = operator_new(uVar13);
        if (ppppcVar14 == (char ****)0x0) goto LAB_18001793a;
        pppppcVar26 = (char *****)((longlong)ppppcVar14 + 0x27U & 0xffffffffffffffe0);
        pppppcVar26[-1] = ppppcVar14;
      }
      local_b08 = pppppcVar26;
    }
    puStackY_c20 = (undefined *)0x18001785a;
    local_af8 = uVar36;
    uStack_af0 = uVar18;
    memcpy(pppppcVar26,pppppuVar35,sVar29);
    *(undefined8 *)((longlong)pppppcVar26 + sVar29) = s__Libraries_180041e28._0_8_;
    *(undefined2 *)((longlong)pppppcVar26 + sVar29 + 8) = s__Libraries_180041e28._8_2_;
    *(char *)((longlong)pppppcVar26 + uVar36) = '\0';
    uVar18 = uStack_af0;
    uVar36 = local_af8;
    pppppcVar26 = local_b08;
    pppppcVar10 = (char *****)&local_b08;
    if (0xf < uStack_af0) {
      pppppcVar10 = local_b08;
    }
    if (local_ab0 - local_ab8 < local_af8) {
      puStackY_c20 = (undefined *)0x180017901;
      FUN_180007e40(&local_ac8,local_af8,0,pppppcVar10,local_af8);
      pppppcVar26 = local_b08;
      uVar18 = uStack_af0;
    }
    else {
      pppppcVar8 = (char *****)&local_ac8;
      if (0xf < local_ab0) {
        pppppcVar8 = local_ac8;
      }
      pcVar38 = (char *)((longlong)pppppcVar8 + local_ab8);
      puStackY_c20 = (undefined *)0x1800178e4;
      local_ab8 = local_af8 + local_ab8;
      memmove(pcVar38,pppppcVar10,local_af8);
      pcVar38[uVar36] = '\0';
    }
    if (0xf < uVar18) {
      pppppcVar10 = pppppcVar26;
      if ((0xfff < uVar18 + 1) &&
         (pppppcVar10 = (char *****)pppppcVar26[-1],
         (char *)0x1f < (char *)((longlong)pppppcVar26 + (-8 - (longlong)pppppcVar10)))) {
LAB_18001793a:
                    /* WARNING: Subroutine does not return */
        puStackY_c20 = &UNK_180017940;
        _invalid_parameter_noinfo_noreturn();
      }
      puStackY_c20 = (undefined *)0x180017949;
      FUN_180035134(pppppcVar10);
    }
    local_b50 = (HKEY)0x0;
    local_b40 = 0;
    pppppcVar26 = (char *****)&local_ac8;
    if (0xf < local_ab0) {
      pppppcVar26 = local_ac8;
    }
    local_bb0 = (HKEY)0x0;
    lpcchName = (HKEY *)0x2001f;
    puStackY_c20 = (undefined *)0x18001798f;
    LVar5 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,(LPCSTR)pppppcVar26,0,0x2001f,&local_bb0);
    pHVar9 = local_bb0;
    if (LVar5 == 0) {
      local_b50 = local_bb0;
      local_b48 = 0;
      if (local_bb0 != (HKEY)0x0) {
        local_958[0] = '\0';
        puStackY_c20 = (undefined *)0x1800179c5;
        memset(local_958 + 1,0,0x103);
        local_bb4 = 0x104;
        local_bb8 = 0;
        lpcchName = (HKEY *)0x0;
        lpcchClass = &local_bb4;
        puStackY_c20 = (undefined *)0x180017a3d;
        RegQueryInfoKeyA(pHVar9,local_958,lpcchClass,(LPDWORD)0x0,&local_bb8,(LPDWORD)&local_b88,
                         (LPDWORD)&local_b60,(LPDWORD)&local_b38,local_b18,&local_b1c,&local_b20,
                         &local_b28);
        local_b80 = (HKEY)0x0;
        pHStack_b78 = (HKEY)0x0;
        local_bb0 = (HKEY)0x0;
        local_b70 = (HKEY)0x0;
        if (local_bb8 == 0) {
          pHVar39 = (HKEY)0x0;
        }
        else {
          puStackY_c20 = (undefined *)0x180017a64;
          FUN_18001f260("\nNumber of subkeys: %d\n",(ulonglong)local_bb8,lpcchClass,lpcchName);
          dwIndex = 0;
          pHVar39 = pHStack_b78;
          if (local_bb8 != 0) {
            plVar25 = plStack_b98;
            do {
              if ((longlong)plVar25 - (longlong)plVar32 >> 5 == 0) break;
              local_b58 = 0xff;
              lpcchName = (HKEY *)&local_b58;
              puStackY_c20 = (undefined *)0x180017acc;
              LVar5 = RegEnumKeyExA(pHVar9,dwIndex,local_a68,(LPDWORD)lpcchName,(LPDWORD)0x0,
                                    (LPSTR)0x0,(LPDWORD)0x0,&local_b28);
              if (LVar5 == 0) {
                puStackY_c20 = (undefined *)0x180017aeb;
                FUN_18001f260("(%d) %s\n",(ulonglong)(dwIndex + 1),local_a68,lpcchName);
                uStack_aa0 = uStack_aa0 & 0xffffffff00000000;
                local_a98 = 0;
                local_ba8 = (HKEY)0x0;
                lpcchName = (HKEY *)0x2001f;
                puStackY_c20 = (undefined *)0x180017b21;
                LVar5 = RegOpenKeyExA(pHVar9,local_a68,0,0x2001f,&local_ba8);
                pHVar22 = local_ba8;
                if (LVar5 == 0) {
                  local_aa8 = local_ba8;
                  uStack_aa0 = uStack_aa0 & 0xffffffff00000000;
                  if (local_ba8 != (HKEY)0x0) {
                    puStackY_c20 = (undefined *)0x180017b5d;
                    memset(local_448,0,0x400);
                    puStackY_c20 = (undefined *)0x180017b71;
                    memset(local_558,0,0x104);
                    local_ba8._0_4_ = 0x400;
                    puStackY_c20 = (undefined *)0x180017ba4;
                    LVar5 = RegQueryValueExA(pHVar22,"Display Name",(LPDWORD)0x0,&local_b54,
                                             local_448,(LPDWORD)&local_ba8);
                    if (((LVar5 == 0) && (local_b54 - 1 < 2)) && ((int)local_ba8 == 0)) {
                      local_448[0] = '\0';
                    }
                    local_ba8 = (HKEY)CONCAT44(local_ba8._4_4_,0x104);
                    lpcchName = (HKEY *)local_b68;
                    puStackY_c20 = (undefined *)0x180017bf2;
                    LVar5 = RegQueryValueExA(pHVar22,"Path",(LPDWORD)0x0,(LPDWORD)lpcchName,
                                             local_558,(LPDWORD)&local_ba8);
                    if (((LVar5 == 0) && (local_b68[0] - 1 < 2)) && ((int)local_ba8 == 0)) {
                      local_558[0] = '\0';
                    }
                    puStackY_c20 = (undefined *)0x180017c1c;
                    iVar3 = _access((char *)local_558,0);
                    if (iVar3 == 0) {
                      if (plVar32 != plVar25) {
                        sVar29 = 0xffffffffffffffff;
                        do {
                          sVar27 = sVar29 + 1;
                          lVar11 = sVar29 + 1;
                          plVar21 = plVar32;
                          sVar29 = sVar27;
                        } while (local_448[lVar11] != '\0');
                        do {
                          _Buf1 = plVar21;
                          if (0xf < (ulonglong)plVar21[3]) {
                            _Buf1 = (longlong *)*plVar21;
                          }
                          if (plVar21[2] == sVar27) {
                            puStackY_c20 = (undefined *)0x180017de2;
                            iVar3 = memcmp(_Buf1,local_448,plVar21[2]);
                            if (iVar3 == 0) {
                              puStackY_c20 = (undefined *)0x180017e04;
                              FUN_18001d660((longlong)&local_ba0,&local_b10,(longlong)plVar21);
                              plVar32 = local_ba0;
                              break;
                            }
                          }
                          plVar21 = plVar21 + 4;
                        } while (plVar21 != plVar25);
                      }
                    }
                    else {
                      local_b08 = (char *****)0x0;
                      lStack_b00 = 0;
                      local_af8 = 0;
                      uStack_af0 = 0;
                      uVar36 = 0xffffffffffffffff;
                      do {
                        uVar18 = uVar36;
                        uVar36 = uVar18 + 1;
                      } while (local_a68[uVar18 + 1] != '\0');
                      if (0x7fffffffffffffff < uVar36) {
                    /* WARNING: Subroutine does not return */
                        puStackY_c20 = (undefined *)0x180018401;
                        FUN_18001d1b0();
                      }
                      if (uVar36 < 0x10) {
                        uStack_af0 = 0xf;
                        puStackY_c20 = (undefined *)0x180017c9a;
                        local_af8 = uVar36;
                        memcpy(&local_b08,local_a68,uVar36);
                        *(undefined1 *)((longlong)&local_b08 + uVar18 + 1) = 0;
                      }
                      else {
                        uVar18 = uVar36 | 0xf;
                        if (uVar18 < 0x8000000000000000) {
                          if (uVar18 < 0x16) {
                            uVar18 = 0x16;
                          }
                        }
                        else {
                          uVar18 = 0x7fffffffffffffff;
                        }
                        puStackY_c20 = (undefined *)0x180017cd2;
                        pppppcVar26 = FUN_18001d210(&local_b08,uVar18 + 1);
                        puStackY_c20 = (undefined *)0x180017cfc;
                        local_b08 = pppppcVar26;
                        local_af8 = uVar36;
                        uStack_af0 = uVar18;
                        memcpy(pppppcVar26,local_a68,uVar36);
                        *(char *)((longlong)pppppcVar26 + uVar36) = '\0';
                      }
                      if (pHVar39 == local_bb0) {
                        puStackY_c20 = (undefined *)0x180017d47;
                        FUN_1800077a0((longlong *)&local_b80,(longlong *)pHVar39,&local_b08);
                        local_bb0 = local_b70;
                        uVar36 = uStack_af0;
                      }
                      else {
                        *(char ******)pHVar39 = local_b08;
                        *(longlong *)(pHVar39 + 2) = lStack_b00;
                        *(ulonglong *)(pHVar39 + 4) = local_af8;
                        *(ulonglong *)(pHVar39 + 6) = uStack_af0;
                        local_b08 = (char *****)((ulonglong)local_b08 & 0xffffffffffffff00);
                        pHStack_b78 = pHVar39 + 8;
                        uVar36 = 0xf;
                      }
                      pHVar39 = pHStack_b78;
                      if (0xf < uVar36) {
                        pppppcVar26 = local_b08;
                        if ((0xfff < uVar36 + 1) &&
                           (pppppcVar26 = (char *****)local_b08[-1],
                           (char *)0x1f <
                           (char *)((longlong)local_b08 + (-8 - (longlong)pppppcVar26)))) {
                    /* WARNING: Subroutine does not return */
                          puStackY_c20 = &UNK_180017eae;
                          _invalid_parameter_noinfo_noreturn();
                        }
                        puStackY_c20 = (undefined *)0x180017d9a;
                        FUN_180035134(pppppcVar26);
                      }
                    }
                    puStackY_c20 = (undefined *)0x180017e13;
                    RegCloseKey(pHVar22);
                    pHVar9 = local_b50;
                    plVar25 = plStack_b98;
                  }
                }
              }
              dwIndex = dwIndex + 1;
            } while (dwIndex < local_bb8);
          }
          pHVar9 = local_b50;
          uVar36 = 0;
          uVar18 = (longlong)pHVar39 - (longlong)local_b80 >> 5;
          if (uVar18 != 0) {
            pHVar22 = local_b80;
            do {
              pHVar20 = pHVar22;
              if (0xf < *(ulonglong *)(pHVar22 + 6)) {
                pHVar20 = *(HKEY *)pHVar22;
              }
              if (DAT_1800534e8 == '\0') {
                puStackY_c20 = (undefined *)0x180017e83;
                hModule = GetModuleHandleA("Advapi32.dll");
                if (hModule == (HMODULE)0x0) {
                  DAT_1800534e8 = '\x01';
                }
                else {
                  puStackY_c20 = (undefined *)0x180017e98;
                  DAT_1800534e0 = GetProcAddress(hModule,"RegDeleteKeyExA");
                  DAT_1800534e8 = '\x01';
                }
              }
              if (DAT_1800534e0 == (FARPROC)0x0) {
                puStackY_c20 = (undefined *)0x180017ee1;
                RegDeleteKeyA(pHVar9,(LPCSTR)pHVar20);
              }
              else {
                lpcchName = (HKEY *)0x0;
                puStackY_c20 = (undefined *)0x180017ed9;
                (*DAT_1800534e0)();
              }
              uVar36 = uVar36 + 1;
              pHVar22 = pHVar22 + 8;
            } while (uVar36 < uVar18);
          }
        }
        pHVar22 = local_b80;
        pHVar9 = local_bb0;
        if (local_b80 != (HKEY)0x0) {
          puStackY_c20 = (undefined *)0x180017f0f;
          FUN_180007060((longlong *)local_b80,(longlong *)pHVar39);
          pHVar39 = pHVar22;
          if ((0xfff < ((longlong)pHVar9 - (longlong)pHVar22 & 0xffffffffffffffe0U)) &&
             (pHVar39 = *(HKEY *)(pHVar22 + -2),
             0x1f < (ulonglong)((longlong)pHVar22 + (-8 - (longlong)pHVar39)))) {
                    /* WARNING: Subroutine does not return */
            puStackY_c20 = &UNK_180017f3d;
            _invalid_parameter_noinfo_noreturn();
          }
          puStackY_c20 = (undefined *)0x180017f53;
          FUN_180035134(pHVar39);
        }
        puStackY_c20 = (undefined *)0x180017f5d;
        RegCloseKey(local_b50);
        local_b50 = (HKEY)0x0;
        pppppuVar34 = local_a88;
      }
    }
    local_b48 = 0;
    if ((longlong)plStack_b98 - (longlong)plVar32 >> 5 == 0) {
      uVar37 = local_b30;
    }
    else {
      puStackY_c20 = (undefined *)0x180017f9b;
      memset(local_958,0,0x104);
      puStackY_c20 = (undefined *)0x180017fad;
      GetCurrentDirectoryA(0x104,local_958);
      uVar37 = local_b30;
      puStackY_c20 = (undefined *)0x180017fc7;
      FUN_1800154b0(local_b30,local_958,(longlong *)&local_ba0,lpcchName);
      plVar32 = local_ba0;
    }
    if ((longlong)plStack_b98 - (longlong)plVar32 >> 5 != 0) {
      puStackY_c20 = (undefined *)0x180017ffe;
      pcVar38 = GetProfileStringA("mmgini","startupdir",(char *)0x0);
      puStackY_c20 = (undefined *)0x18001800d;
      FUN_1800154b0(uVar37,pcVar38,(longlong *)&local_ba0,lpcchName);
      plVar32 = local_ba0;
    }
    if ((longlong)plStack_b98 - (longlong)plVar32 >> 5 != 0) {
      puStackY_c20 = (undefined *)0x18001803c;
      memset(local_a68,0,0x104);
      local_bb8 = 0;
      puStackY_c20 = (undefined *)0x18001804b;
      GetAllUsersProfileDirectoryW(0,&local_bb8);
      _Var15 = SUB168(ZEXT816(2) * ZEXT416(local_bb8),0);
      if (SUB168(ZEXT816(2) * ZEXT416(local_bb8),8) != 0) {
        _Var15 = 0xffffffffffffffff;
      }
      puStackY_c20 = (undefined *)0x180018069;
      lpWideCharStr = operator_new__(_Var15);
      puStackY_c20 = (undefined *)0x180018079;
      GetAllUsersProfileDirectoryW(lpWideCharStr);
      if (lpWideCharStr == (LPCWSTR)0x0) {
        puVar23 = (undefined1 *)0x0;
        puVar24 = auStackY_c18;
      }
      else {
        lVar11 = -1;
        do {
          lVar16 = lVar11;
          lVar11 = lVar16 + 1;
        } while (lpWideCharStr[lVar11] != L'\0');
        iVar3 = (int)lVar16 + 2;
        if (iVar3 < 0x40000000) {
          lVar11 = (longlong)(int)lVar11 * 2;
          uVar36 = lVar11 + 0x11;
          if (uVar36 <= lVar11 + 2U) {
            uVar36 = 0xffffffffffffff0;
          }
          puStackY_c20 = (undefined *)0x1800180d2;
          lVar11 = -(uVar36 & 0xfffffffffffffff0);
          puVar23 = (undefined1 *)((longlong)local_b68 + lVar11 + -0x50);
          if (puVar23 == (undefined1 *)0x0) {
            puVar23 = (undefined1 *)0x0;
            puVar24 = auStackY_c18 + lVar11;
          }
          else {
            *puVar23 = 0;
            *(undefined8 *)(auStackY_c18 + lVar11 + 0x38) = 0;
            *(undefined8 *)(auStackY_c18 + lVar11 + 0x30) = 0;
            *(int *)(auStackY_c18 + lVar11 + 0x28) = iVar3 * 2;
            *(undefined1 **)(auStackY_c18 + lVar11 + 0x20) = puVar23;
            lpcchName = (HKEY *)0xffffffff;
            *(undefined8 *)(auStackY_c18 + lVar11 + -8) = 0x18001810b;
            iVar3 = WideCharToMultiByte(0,0,lpWideCharStr,-1,
                                        *(LPSTR *)(auStackY_c18 + lVar11 + 0x20),
                                        *(int *)(auStackY_c18 + lVar11 + 0x28),
                                        *(LPCSTR *)(auStackY_c18 + lVar11 + 0x30),
                                        *(LPBOOL *)(auStackY_c18 + lVar11 + 0x38));
            puVar24 = auStackY_c18 + lVar11;
            if (iVar3 == 0) {
              puVar23 = (undefined1 *)0x0;
              puVar24 = auStackY_c18 + lVar11;
            }
          }
        }
        else {
          puVar23 = (undefined1 *)0x0;
          puVar24 = auStackY_c18;
        }
      }
      pcVar38 = (char *)((longlong)&local_a70 + 7);
      do {
        pcVar38 = pcVar38 + 1;
      } while (*pcVar38 != '\0');
      lVar11 = 0;
      do {
        cVar1 = puVar23[lVar11];
        pcVar38[lVar11] = cVar1;
        lVar11 = lVar11 + 1;
      } while (cVar1 != '\0');
      *(undefined8 *)(puVar24 + -8) = 0x180018147;
      operator_delete__(lpWideCharStr);
      if (local_a68[0] == '\0') {
        local_bb0 = (HKEY)0x0;
        *(HKEY **)(puVar24 + 0x20) = &local_bb0;
        lpcchName = (HKEY *)0x20019;
        *(undefined8 *)(puVar24 + -8) = 0x180018180;
        LVar5 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000002,"Software\\AspenTech\\Setup",0,0x20019,
                              *(PHKEY *)(puVar24 + 0x20));
        if (LVar5 == 0) {
          local_ba8 = (HKEY)((ulonglong)local_ba8 & 0xffffffff00000000);
          local_bb4 = 0;
          *(DWORD **)(puVar24 + 0x28) = &local_bb4;
          *(undefined8 *)(puVar24 + 0x20) = 0;
          pHVar9 = local_bb0;
          lpcchName = &local_ba8;
          *(undefined8 *)(puVar24 + -8) = 0x1800181b0;
          LVar5 = RegQueryValueExA(pHVar9,"ASPENWORKINGROOT",(LPDWORD)0x0,(LPDWORD)lpcchName,
                                   *(LPBYTE *)(puVar24 + 0x20),*(LPDWORD *)(puVar24 + 0x28));
          if ((LVar5 == 0) && ((int)local_ba8 == 1)) {
            *(DWORD **)(puVar24 + 0x28) = &local_bb4;
            *(char **)(puVar24 + 0x20) = local_a68;
            pHVar9 = local_bb0;
            lpcchName = &local_ba8;
            *(undefined8 *)(puVar24 + -8) = 0x1800181e7;
            RegQueryValueExA(pHVar9,"ASPENWORKINGROOT",(LPDWORD)0x0,(LPDWORD)lpcchName,
                             *(LPBYTE *)(puVar24 + 0x20),*(LPDWORD *)(puVar24 + 0x28));
          }
        }
        if (local_a68[0] == '\0') goto LAB_1800182d1;
      }
      pcVar38 = (char *)((longlong)&local_a70 + 7);
      do {
        pcVar38 = pcVar38 + 1;
      } while (*pcVar38 != '\0');
      *(undefined2 *)pcVar38 = DAT_1800409c4;
      pcVar38 = (char *)((longlong)&local_a70 + 7);
      do {
        pcVar33 = pcVar38;
        pcVar38 = pcVar33 + 1;
      } while (*pcVar38 != '\0');
      *(undefined8 *)pcVar38 = s_AspenTech_Aspen_Plus_180041eb8._0_8_;
      *(undefined8 *)(pcVar33 + 9) = s_AspenTech_Aspen_Plus_180041eb8._8_8_;
      *(undefined4 *)(pcVar33 + 0x11) = s_AspenTech_Aspen_Plus_180041eb8._16_4_;
      *(undefined2 *)(pcVar33 + 0x15) = s_AspenTech_Aspen_Plus_180041eb8._20_2_;
      *(undefined8 *)(puVar24 + -8) = 0x18001824c;
      pcVar33 = FUN_180033bc0();
      pcVar38 = (char *)((longlong)&local_a70 + 7);
      do {
        pcVar38 = pcVar38 + 1;
      } while (*pcVar38 != '\0');
      lVar11 = 0;
      do {
        cVar1 = pcVar33[lVar11];
        pcVar38[lVar11] = cVar1;
        lVar11 = lVar11 + 1;
      } while (cVar1 != '\0');
      pcVar38 = (char *)((longlong)&local_a70 + 7);
      do {
        pcVar33 = pcVar38;
        pcVar38 = pcVar33 + 1;
      } while (*pcVar38 != '\0');
      *(undefined8 *)pcVar38 = s__Libraries_180041e28._0_8_;
      *(undefined2 *)(pcVar33 + 9) = s__Libraries_180041e28._8_2_;
      pcVar33[0xb] = s__Libraries_180041e28[10];
      *(undefined8 *)(puVar24 + -8) = 0x1800182cd;
      FUN_1800154b0(uVar37,local_a68,(longlong *)&local_ba0,lpcchName);
      plVar32 = local_ba0;
    }
LAB_1800182d1:
    if (0xf < local_a70) {
      pppppuVar35 = pppppuVar34;
      if ((0xfff < local_a70 + 1) &&
         (pppppuVar35 = (undefined8 *****)pppppuVar34[-1],
         0x1f < (ulonglong)((longlong)pppppuVar34 + (-8 - (longlong)pppppuVar35)))) {
                    /* WARNING: Subroutine does not return */
        *(undefined **)(puVar24 + -8) = &UNK_180018318;
        _invalid_parameter_noinfo_noreturn();
      }
      *(undefined8 *)(puVar24 + -8) = 0x180018321;
      FUN_180035134(pppppuVar35);
    }
    if (0xf < local_ab0) {
      pppppcVar26 = local_ac8;
      if ((0xfff < local_ab0 + 1) &&
         (pppppcVar26 = (char *****)local_ac8[-1],
         (char *)0x1f < (char *)((longlong)local_ac8 + (-8 - (longlong)pppppcVar26)))) {
                    /* WARNING: Subroutine does not return */
        *(undefined **)(puVar24 + -8) = &UNK_180018360;
        _invalid_parameter_noinfo_noreturn();
      }
      *(undefined8 *)(puVar24 + -8) = 0x180018366;
      FUN_180035134(pppppcVar26);
    }
    local_ab8 = 0;
    local_ab0 = 0xf;
    local_ac8 = (char *****)((ulonglong)local_ac8 & 0xffffffffffffff00);
    goto LAB_18001837f;
  }
  goto LAB_180018383;
LAB_180017650:
  do {
    if (0xf < *(ulonglong *)(pHVar20 + 6)) {
      pvVar2 = *(void **)pHVar20;
      pvVar17 = pvVar2;
      if ((0xfff < *(ulonglong *)(pHVar20 + 6) + 1) &&
         (pvVar17 = *(void **)((longlong)pvVar2 + -8),
         0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar17)))) goto LAB_1800176c6;
      puStackY_c20 = (undefined *)0x180017686;
      FUN_180035134(pvVar17);
    }
    *(longlong *)(pHVar20 + 4) = 0;
    *(longlong *)(pHVar20 + 6) = 0xf;
    *(undefined1 *)&pHVar20->unused = 0;
    pHVar20 = pHVar20 + 8;
  } while (pHVar20 != pHVar9);
LAB_18001769e:
  pHVar9 = pHVar22;
  if ((0xfff < ((longlong)pHVar39 - (longlong)pHVar22 & 0xffffffffffffffe0U)) &&
     (pHVar9 = *(HKEY *)(pHVar22 + -2),
     0x1f < (ulonglong)((longlong)pHVar22 + (-8 - (longlong)pHVar9)))) goto LAB_1800176c6;
  puStackY_c20 = (undefined *)0x1800176d8;
  FUN_180035134(pHVar9);
LAB_1800176d8:
  puVar24 = auStackY_c18;
  plVar32 = local_ba0;
LAB_18001837f:
  puVar23 = puVar24;
LAB_180018383:
  plVar25 = plStack_b98;
  if (plVar32 != (longlong *)0x0) {
    *(undefined8 *)(puVar23 + -8) = 0x180018397;
    FUN_180007060(plVar32,plVar25);
    plVar25 = plVar32;
    if ((0xfff < ((longlong)local_b90 - (longlong)plVar32 & 0xffffffffffffffe0U)) &&
       (plVar25 = (longlong *)plVar32[-1],
       0x1f < (ulonglong)((longlong)plVar32 + (-8 - (longlong)plVar25)))) {
                    /* WARNING: Subroutine does not return */
      *(undefined **)(puVar23 + -8) = &UNK_1800183ca;
      _invalid_parameter_noinfo_noreturn();
    }
    *(undefined8 *)(puVar23 + -8) = 0x1800183d3;
    FUN_180035134(plVar25);
  }
LAB_1800183d3:
  *(undefined8 *)(puVar23 + -8) = 0x1800183e2;
  return;
}

/* RVA 0x18420 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180018420(undefined8 param_1,longlong *param_2,LPCSTR param_3,
                  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_4)

{
  code *pcVar1;
  char *_Filename;
  uint uVar2;
  longlong *plVar3;
  longlong lVar5;
  longlong lVar4;
  FILE *_File;
  void *_Str;
  ulonglong uVar6;
  int iVar7;
  undefined2 *puVar8;
  undefined1 *puVar9;
  undefined8 uStack_480;
  undefined1 auStack_478 [32];
  undefined8 uStack_458;
  int aiStack_450 [2];
  uint local_448;
  uint uStack_444;
  longlong *local_440;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_438;
  undefined1 local_428 [1008];
  ulonglong local_38;
  
  local_38 = DAT_180052888 ^ (ulonglong)&local_448;
  local_438 = param_4;
  local_440 = (longlong *)0x0;
  puVar9 = auStack_478;
  if (param_3 == (LPCSTR)0x0) {
LAB_1800184ce:
    puVar8 = (undefined2 *)0x0;
  }
  else {
    lVar4 = -1;
    do {
      lVar5 = lVar4;
      lVar4 = lVar5 + 1;
    } while (param_3[lVar4] != '\0');
    iVar7 = (int)lVar5 + 2;
    puVar9 = auStack_478;
    if (0x3fffffff < iVar7) goto LAB_1800184ce;
    lVar4 = (longlong)(int)lVar4 * 2;
    uVar6 = lVar4 + 0x11;
    if (uVar6 <= lVar4 + 2U) {
      uVar6 = 0xffffffffffffff0;
    }
    uStack_480 = 0x18001849e;
    lVar4 = -(uVar6 & 0xfffffffffffffff0);
    puVar9 = auStack_478 + lVar4;
    puVar8 = (undefined2 *)((longlong)aiStack_450 + lVar4 + 8);
    if (puVar8 == (undefined2 *)0x0) goto LAB_1800184ce;
    *puVar8 = 0;
    *(int *)((longlong)aiStack_450 + lVar4) = iVar7;
    *(undefined2 **)(auStack_478 + lVar4 + 0x20) = puVar8;
    *(undefined8 *)(auStack_478 + lVar4 + -8) = 0x1800184c6;
    iVar7 = MultiByteToWideChar(0,0,param_3,-1,*(LPWSTR *)(auStack_478 + lVar4 + 0x20),
                                *(int *)((longlong)aiStack_450 + lVar4));
    puVar9 = auStack_478 + lVar4;
    if (iVar7 == 0) {
      puVar8 = (undefined2 *)0x0;
      puVar9 = auStack_478 + lVar4;
    }
  }
  lVar4 = *param_2;
  *(longlong ***)(puVar9 + 0x28) = &local_440;
  *(undefined4 *)(puVar9 + 0x20) = 0;
  pcVar1 = *(code **)(lVar4 + 0x20);
  *(undefined8 *)(puVar9 + -8) = 0x1800184f4;
  iVar7 = (*pcVar1)(param_2,puVar8,0,0x12);
  plVar3 = local_440;
  if (-1 < iVar7) {
    local_448 = 0;
    pcVar1 = *(code **)(*local_440 + 0x18);
    *(undefined8 *)(puVar9 + -8) = 0x180018515;
    (*pcVar1)(plVar3,&local_448,4);
    if (0 < (int)local_448) {
      _Filename = *(char **)param_4;
      *(undefined8 *)(puVar9 + -8) = 0x18001852f;
      _File = fopen(_Filename,"wb");
      if (_File == (FILE *)0x0) goto LAB_1800185e1;
      iVar7 = local_448 + 1;
      *(undefined8 *)(puVar9 + -8) = 0x180018548;
      _Str = operator_new__((longlong)iVar7);
      plVar3 = local_440;
      uVar2 = local_448;
      *(undefined1 *)((longlong)(int)local_448 + (longlong)_Str) = 0;
      uStack_444 = 0;
      pcVar1 = *(code **)(*local_440 + 0x18);
      *(undefined8 *)(puVar9 + -8) = 0x18001856d;
      (*pcVar1)(plVar3,_Str,uVar2,&uStack_444);
      if (uStack_444 != local_448) {
        *(undefined8 *)(puVar9 + -8) = 0x180018592;
        FUN_180001ce0(local_428,"Assert failed in file %s line %d",
                      "G:\\Agent\\work\\2\\s\\src\\mm\\ApwnShellIP\\ApwnLWDocument.cpp",0xd75);
        *(undefined8 *)(puVar9 + -8) = 0x1800185a5;
        LogMessage(local_428,2,1);
      }
      uVar6 = (ulonglong)uStack_444;
      *(undefined8 *)(puVar9 + -8) = 0x1800185bc;
      fwrite(_Str,1,uVar6,_File);
      *(undefined8 *)(puVar9 + -8) = 0x1800185c5;
      fflush(_File);
      *(undefined8 *)(puVar9 + -8) = 0x1800185ce;
      fclose(_File);
      *(undefined8 *)(puVar9 + -8) = 0x1800185d6;
      operator_delete__(_Str);
    }
    pcVar1 = *(code **)(*local_440 + 0x10);
    *(undefined8 *)(puVar9 + -8) = 0x1800185e0;
    (*pcVar1)();
  }
LAB_1800185e1:
  *(undefined8 *)(puVar9 + -8) = 0x1800185ea;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_4);
  *(undefined8 *)(puVar9 + -8) = 0x1800185f9;
  return;
}

/* RVA 0x18610 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180018610(undefined8 param_1,longlong *param_2)

{
  int iVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar2;
  FILE *_File;
  char *pcVar3;
  undefined1 auStackY_7c8 [32];
  char local_798 [8];
  char *local_790;
  FILE *local_788;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_780 [24];
  CHAR local_768 [272];
  char local_658 [272];
  char local_548 [272];
  char local_438 [256];
  char local_338 [256];
  char local_238 [256];
  char local_138 [272];
  ulonglong local_28;
  
  local_28 = DAT_180052888 ^ (ulonglong)auStackY_7c8;
  local_798[0] = '\0';
  local_798[1] = '\0';
  local_798[2] = '\0';
  local_798[3] = '\0';
  iVar1 = FUN_180033bd0();
  if (iVar1 == 1) {
    iVar1 = _access(PTR_s_FNN_TXT_1800527e8,0);
    if (iVar1 == 0) {
      remove(PTR_s_FNN_TXT_1800527e8);
    }
    pCVar2 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                       ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_790,
                        PTR_s_FNN_TXT_1800527e8);
    FUN_180018420(param_1,param_2,PTR_s_FNN_TXT_1800527e8,pCVar2);
    iVar1 = _access(PTR_s_FNN_TXT_1800527e8,0);
    if (iVar1 == 0) {
      _File = fopen(PTR_s_FNN_TXT_1800527e8,"rt");
      local_788 = _File;
      while( true ) {
        pcVar3 = fgets(local_548,0x104,_File);
        if (pcVar3 == (char *)0x0) break;
        pcVar3 = fgets(local_658,0x104,_File);
        if (pcVar3 == (char *)0x0) break;
        pcVar3 = strchr(local_548,10);
        if (pcVar3 != (char *)0x0) {
          *pcVar3 = '\0';
        }
        pcVar3 = strchr(local_658,10);
        if (pcVar3 != (char *)0x0) {
          *pcVar3 = '\0';
        }
        iVar1 = SHGetFolderPathA(0,0x1c);
        if (-1 < iVar1) {
          PathAppendA(local_768,"\\AspenTech\\AIModeling\\MergeNNFiles\\");
          SHCreateDirectoryExA((HWND)0x0,local_768,(SECURITY_ATTRIBUTES *)0x0);
          _splitpath(local_768,local_798,local_238,(char *)0x0,(char *)0x0);
          _splitpath(local_658,(char *)0x0,(char *)0x0,local_338,local_438);
          _makepath(local_138,local_798,local_238,local_338,local_438);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_790,
                     local_138);
          iVar1 = _access(local_790,0);
          if (iVar1 == -1) {
            pCVar2 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                     ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                     CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                               (local_780,
                                (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                 *)&local_790);
            FUN_180018420(param_1,param_2,local_548,pCVar2);
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_790);
        }
      }
      if (_File != (FILE *)0x0) {
        fclose(_File);
      }
      remove(PTR_s_FNN_TXT_1800527e8);
    }
  }
  return;
}

/* RVA 0x188c0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1800188c0(longlong param_1,BSTR param_2)

{
  __uint64 _Var1;
  int *piVar2;
  int iVar3;
  _func_5437 **pp_Var4;
  ulonglong uVar5;
  ILockBytesVtbl *pIVar6;
  UINT UVar7;
  ulonglong uVar8;
  LPCSTR ***ppppCVar9;
  longlong *plVar10;
  ILockBytesVtbl *pIVar11;
  undefined8 *puVar12;
  BSTR pOVar13;
  LPCSTR ****pppppCVar14;
  longlong lVar15;
  longlong lVar16;
  LPCSTR ****pppppCVar17;
  longlong *plVar18;
  ulonglong uVar19;
  size_t sVar20;
  undefined1 auStack_158 [32];
  undefined8 local_138;
  undefined4 local_130;
  ILockBytesVtbl **local_128;
  ILockBytesVtbl *local_118;
  longlong *local_110;
  ILockBytesVtbl *local_108;
  undefined8 *local_100;
  LPCSTR ****local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  ulonglong local_e0;
  undefined1 *local_d8;
  undefined1 local_d0 [136];
  ulonglong local_48;
  
  local_48 = DAT_180052888 ^ (ulonglong)auStack_158;
  uStack_f0 = 0;
  local_e8 = 0;
  local_e0 = 0xf;
  local_f8 = (LPCSTR ****)0x0;
  if ((param_2 != (BSTR)0x0) && (UVar7 = SysStringLen(param_2), UVar7 != 0)) {
    local_d8 = local_d0;
    FUN_18000d880(&local_d8,param_2,0);
    sVar20 = 0xffffffffffffffff;
    do {
      sVar20 = sVar20 + 1;
    } while (local_d8[sVar20] != '\0');
    FUN_18001d350((longlong *)&local_f8,local_d8,sVar20);
    if (local_d8 != local_d0) {
      free(local_d8);
    }
    goto LAB_180018a87;
  }
  uVar5 = local_e0;
  if (3 < local_e0) {
    pppppCVar17 = (LPCSTR ****)&local_f8;
    if (0xf < local_e0) {
      pppppCVar17 = local_f8;
    }
    local_e8 = 4;
    *(undefined4 *)pppppCVar17 = 0x746f6f52;
    *(undefined1 *)((longlong)pppppCVar17 + 4) = 0;
    goto LAB_180018a87;
  }
  uVar19 = 0x7fffffffffffffff;
  if (0x7fffffffffffffff - (local_e0 >> 1) < local_e0) {
    uVar8 = 0x8000000000000027;
LAB_1800189d1:
    ppppCVar9 = operator_new(uVar8);
    if (ppppCVar9 == (LPCSTR ***)0x0) goto LAB_180018a76;
    pppppCVar17 = (LPCSTR ****)((longlong)ppppCVar9 + 0x27U & 0xffffffffffffffe0);
    pppppCVar17[-1] = ppppCVar9;
  }
  else {
    uVar8 = (local_e0 >> 1) + local_e0;
    uVar19 = 0xf;
    if (0xf < uVar8) {
      uVar19 = uVar8;
    }
    _Var1 = uVar19 + 1;
    if (0xfff < _Var1) {
      uVar8 = uVar19 + 0x28;
      if (uVar8 <= _Var1) {
                    /* WARNING: Subroutine does not return */
        FUN_18001d0c0();
      }
      goto LAB_1800189d1;
    }
    if (_Var1 == 0) {
      pppppCVar17 = (LPCSTR ****)0x0;
    }
    else {
      pppppCVar17 = operator_new(_Var1);
    }
  }
  local_e8 = 4;
  local_e0 = uVar19;
  *(undefined4 *)pppppCVar17 = 0x746f6f52;
  *(undefined1 *)((longlong)pppppCVar17 + 4) = 0;
  if (0xf < uVar5) {
    pppppCVar14 = local_f8;
    if ((0xfff < uVar5 + 1) &&
       (pppppCVar14 = (LPCSTR ****)local_f8[-1],
       0x1f < (ulonglong)((longlong)local_f8 + (-8 - (longlong)pppppCVar14)))) {
LAB_180018a76:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(pppppCVar14);
  }
  local_f8 = pppppCVar17;
LAB_180018a87:
  plVar18 = (longlong *)0x0;
  local_110 = (longlong *)0x0;
  pppppCVar17 = (LPCSTR ****)&local_f8;
  if (0xf < local_e0) {
    pppppCVar17 = local_f8;
  }
  lVar15 = 0;
  do {
    lVar16 = lVar15 + 1;
    if (*(char *)((longlong)pppppCVar17 + lVar15) != (&DAT_180041bf8)[lVar15]) {
      pppppCVar17 = (LPCSTR ****)&local_f8;
      if (0xf < local_e0) {
        pppppCVar17 = local_f8;
      }
      plVar10 = (longlong *)HYGetModelByName(pppppCVar17);
      if (plVar10 == (longlong *)0x0) goto LAB_180018ca8;
      (**(code **)(*plVar10 + 8))(plVar10);
      plVar18 = plVar10;
      goto LAB_180018b0e;
    }
    lVar15 = lVar16;
  } while (lVar16 != 5);
  plVar10 = (longlong *)HYGetModelByName(0);
  if (plVar10 != (longlong *)0x0) {
    (**(code **)(*plVar10 + 8))(plVar10);
    plVar18 = plVar10;
LAB_180018b0e:
    local_118 = (ILockBytesVtbl *)0x0;
    local_110 = plVar18;
    pIVar11 = FUN_18000cdb0(param_1,param_2,'\0');
    pIVar6 = local_118;
    if (local_118 != pIVar11) {
      if (pIVar11 != (ILockBytesVtbl *)0x0) {
        (**(code **)(pIVar11->QueryInterface + 8))(pIVar11);
      }
      pIVar6 = pIVar11;
      if (local_118 != (ILockBytesVtbl *)0x0) {
        pp_Var4 = &local_118->QueryInterface;
        pIVar6 = local_118;
        local_118 = pIVar11;
        (**(code **)(*pp_Var4 + 0x10))(pIVar6);
        pIVar6 = local_118;
      }
    }
    local_118 = pIVar6;
    if (local_118 == (ILockBytesVtbl *)0x0) {
      local_108 = (ILockBytesVtbl *)0x0;
      local_128 = &local_108;
      local_130 = 0;
      local_138 = 0;
      (**(code **)(**(longlong **)(param_1 + 8) + 0x30))
                (*(longlong **)(param_1 + 8),L"PFSEmbedding",0,0x12);
      pIVar6 = local_108;
      if (local_108 != (ILockBytesVtbl *)0x0) {
        pppppCVar17 = (LPCSTR ****)&local_f8;
        if (0xf < local_e0) {
          pppppCVar17 = local_f8;
        }
        puVar12 = operator_new(0x18);
        if (puVar12 == (undefined8 *)0x0) {
          puVar12 = (undefined8 *)0x0;
        }
        else {
          puVar12[1] = 0;
          *(undefined4 *)(puVar12 + 2) = 1;
          local_100 = puVar12;
          pOVar13 = FUN_180034c50((LPCSTR)pppppCVar17);
          *puVar12 = pOVar13;
        }
        local_100 = puVar12;
        if (puVar12 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_180034a60(0x8007000e);
        }
        local_128 = &local_118;
        local_130 = 0;
        local_138 = 0;
        (**(code **)(pIVar6->QueryInterface + 0x30))(pIVar6,*puVar12,0,0x12);
        LOCK();
        piVar2 = (int *)(puVar12 + 2);
        iVar3 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if (iVar3 == 1) {
          if ((BSTR)*puVar12 != (BSTR)0x0) {
            SysFreeString((BSTR)*puVar12);
            *puVar12 = 0;
          }
          if ((void *)puVar12[1] != (void *)0x0) {
            operator_delete__((void *)puVar12[1]);
            puVar12[1] = 0;
          }
          FUN_180035134(puVar12);
        }
        plVar18 = local_110;
        if (local_118 != (ILockBytesVtbl *)0x0) {
          RestoreEmbeddedObjects(local_118,local_110);
        }
      }
      if (local_108 != (ILockBytesVtbl *)0x0) {
        (**(code **)(local_108->QueryInterface + 0x10))(local_108);
      }
    }
    if (local_118 != (ILockBytesVtbl *)0x0) {
      (**(code **)(local_118->QueryInterface + 0x10))();
    }
  }
LAB_180018ca8:
  if (plVar18 != (longlong *)0x0) {
    (**(code **)(*plVar18 + 0x10))(plVar18);
  }
  if (0xf < local_e0) {
    pppppCVar17 = local_f8;
    if ((0xfff < local_e0 + 1) &&
       (pppppCVar17 = (LPCSTR ****)local_f8[-1],
       0x1f < (ulonglong)((longlong)local_f8 + (-8 - (longlong)pppppCVar17)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180035134(pppppCVar17);
  }
  return;
}

/* RVA 0x18d40 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180018d40(IStorageVtbl *param_1,IStorage param_2)

{
  _func_5396 **pp_Var1;
  _func_5395 *p_Var2;
  _func_5395 *p_Var3;
  bool bVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  HRESULT HVar8;
  ulonglong uVar9;
  char *pcVar10;
  longlong *plVar11;
  int *piVar12;
  undefined8 uVar13;
  LPCSTR pCVar14;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar15;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar16;
  basic_streambuf<char,std::char_traits<char>_> *pbVar17;
  ulonglong uVar18;
  IStorageVtbl *pIVar19;
  ulonglong extraout_RAX;
  undefined8 *puVar20;
  undefined4 extraout_var;
  char *pcVar21;
  _func_5406 **pp_Var22;
  longlong lVar23;
  _func_5406 **pp_Var24;
  IStorage IVar25;
  IStorage IVar26;
  void *_Dst;
  size_t sVar27;
  wchar_t *pwVar28;
  size_t sVar29;
  char *pcVar30;
  ulonglong uVar31;
  undefined1 auStackY_728 [32];
  short local_6f8 [4];
  IStorage local_6f0;
  LPCSTR local_6e8;
  int local_6e0;
  undefined4 uStack_6dc;
  IStorageVtbl *local_6d8;
  int local_6d0 [2];
  _func_5406 **local_6c8;
  IStorage local_6c0;
  IStorage local_6b8;
  undefined8 uStack_6b0;
  ulonglong local_6a8;
  ulonglong uStack_6a0;
  IStorageVtbl *local_698;
  undefined8 uStack_690;
  ulonglong local_688;
  ulonglong uStack_680;
  IStorage local_678 [2];
  size_t local_668;
  undefined8 local_660;
  longlong local_658 [2];
  basic_streambuf<char,std::char_traits<char>_> local_648 [8];
  basic_istream<char,std::char_traits<char>_> local_640 [152];
  basic_ios<char,std::char_traits<char>_> local_5a8 [92];
  basic_ios<char,std::char_traits<char>_> abStack_54c [4];
  longlong local_548 [2];
  basic_streambuf<char,std::char_traits<char>_> local_538 [8];
  basic_istream<char,std::char_traits<char>_> local_530 [152];
  basic_ios<char,std::char_traits<char>_> local_498 [96];
  char local_438 [256];
  char local_338 [256];
  char local_238 [256];
  char local_138 [256];
  ulonglong local_38;
  
  local_38 = DAT_180052888 ^ (ulonglong)auStackY_728;
  local_6e0 = 0;
  local_6f8[0] = CONCAT11(local_6f8[0]._1_1_,1);
  local_6d8 = param_1;
  local_6c0.lpVtbl = param_2.lpVtbl;
  if (param_2.lpVtbl == (IStorageVtbl *)0x0) {
    if (param_1->SetElementTimes != (_func_5408 *)0x0) {
      pp_Var24 = &param_1->DestroyElement;
      pp_Var22 = pp_Var24;
      if ((_func_5409 *)0xf < param_1->SetClass) {
        pp_Var22 = (_func_5406 **)*pp_Var24;
      }
      _splitpath((char *)pp_Var22,(char *)&local_6c8,(char *)local_548,local_138,local_438);
      pp_Var22 = pp_Var24;
      if ((_func_5409 *)0xf < param_1->SetClass) {
        pp_Var22 = (_func_5406 **)*pp_Var24;
      }
      uVar9 = GRchkmmdir(pp_Var22,2);
      if ((int)uVar9 != 0) goto LAB_180019d66;
      pcVar10 = (char *)GetGlobalPointer("CompoundFileName");
      if (pcVar10 == (char *)0x0) {
        iVar5 = FUN_180033bd0();
        pcVar21 = ".aprbkp";
        pcVar10 = ".aprbkp";
        if (iVar5 == 1) {
          pcVar10 = ".bkp";
        }
        iVar5 = _stricmp(pcVar10,local_438);
        if (iVar5 == 0) {
          pp_Var22 = pp_Var24;
          if ((_func_5409 *)0xf < param_1->SetClass) {
            pp_Var22 = (_func_5406 **)*pp_Var24;
          }
          uVar9 = WriteHappArchive(pp_Var22,0);
          uVar31 = (ulonglong)((int)uVar9 != 0);
          if ((int)uVar9 == 0) goto LAB_180019d66;
          pp_Var22 = pp_Var24;
          if ((_func_5409 *)0xf < param_1->SetClass) {
            pp_Var22 = (_func_5406 **)*pp_Var24;
          }
          GRAuxFileOnSave(pp_Var22);
          pCVar14 = (LPCSTR)GRemrbkp();
          DeleteFileA(pCVar14);
          DeleteFileA("$backup.bkp");
          pp_Var22 = pp_Var24;
          if ((_func_5409 *)0xf < param_1->SetClass) {
            pp_Var22 = (_func_5406 **)*pp_Var24;
          }
          uVar13 = GRemrbkpfull();
          GRDeleteEmergencyFiles(pp_Var22,uVar13);
          SimUpdateMessageView(0,"\n<< Run Saved >>\n");
          HappIsDirty();
          piVar12 = (int *)SEGetSettingValue("saveasapw",0);
          local_6d0[0] = *piVar12;
          local_6f8[0] = 0;
          if (local_6d0[0] == 0) {
            iVar5 = MMGetSuppress();
            if (iVar5 != 0) {
              local_6d0[0] = 7;
              HappSetDirty(0);
              GRsetmod(0);
              goto LAB_180018fbe;
            }
            uVar6 = FUN_180010b50(local_6f8);
            local_6d0[0] = ((short)uVar6 != -1) + 6;
            if (local_6f8[0] == -1) {
              SESetSettingValue("saveasapw",local_6d0,1);
            }
          }
          if (local_6d0[0] == 6) {
            if ((_func_5409 *)0xf < param_1->SetClass) {
              pp_Var24 = (_func_5406 **)*pp_Var24;
            }
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e8,
                       (char *)pp_Var24);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e8,
                       '.');
            pCVar15 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                 &local_6e8,(int)&local_6f0);
            iVar5 = FUN_180033bd0();
            pcVar10 = ".aprop";
            if (iVar5 == 1) {
              pcVar10 = ".apw";
            }
            FUN_1800013a0((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          &local_6d8,pCVar15,pcVar10);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6f0);
            pCVar15 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                 &local_6e0,
                                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                  *)&local_6d8);
            FUN_18000b3f0(&param_1->QueryInterface,pCVar15,0);
            local_6d0[0] = 7;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6d8);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e8);
          }
          HappSetDirty(0);
          GRsetmod(0);
          goto LAB_180018fbe;
        }
        iVar5 = FUN_180033bd0();
        pcVar10 = ".aprop";
        if (iVar5 == 1) {
          pcVar10 = ".apw";
        }
        iVar5 = _stricmp(pcVar10,local_438);
        if (iVar5 == 0) {
          iVar5 = MMGetProfileInt("mmgini","alwayssavebkp",0);
          if (iVar5 != 0) {
            pp_Var22 = pp_Var24;
            if ((_func_5409 *)0xf < param_1->SetClass) {
              pp_Var22 = (_func_5406 **)*pp_Var24;
            }
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6f0,
                       (char *)pp_Var22);
            iVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &local_6f0,'.');
            if ((iVar5 != -1) &&
               (iVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                        ReverseFind((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
                                    )&local_6f0,'\\'), iVar7 < iVar5)) {
              pCVar16 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *
                        )ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                                   ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
                                    )&local_6f0,(int)&local_6e0);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6f0
                         ,pCVar16);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e0
                        );
            }
            iVar5 = FUN_180033bd0();
            if (iVar5 == 1) {
              pcVar21 = ".bkp";
            }
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6f0,
                       pcVar21);
            pcVar10 = (char *)GRemrbkpfull();
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e8,
                       pcVar10);
            iVar5 = WriteHappArchive(local_6f0.lpVtbl,0);
            if (iVar5 != 0) {
              DeleteFileA(local_6e8);
              DeleteFileA("$backup.bkp");
              pp_Var22 = pp_Var24;
              if ((_func_5409 *)0xf < param_1->SetClass) {
                pp_Var22 = (_func_5406 **)*pp_Var24;
              }
              GRDeleteEmergencyFiles(pp_Var22,local_6e8);
            }
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e8);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6f0);
          }
          pp_Var22 = pp_Var24;
          if ((_func_5409 *)0xf < param_1->SetClass) {
            pp_Var22 = (_func_5406 **)*pp_Var24;
          }
          iVar5 = (**(code **)param_1->QueryInterface)(param_1,pp_Var22,1);
          if (iVar5 != 0) {
            pp_Var22 = pp_Var24;
            if ((_func_5409 *)0xf < param_1->SetClass) {
              pp_Var22 = (_func_5406 **)*pp_Var24;
            }
            GRAuxFileOnSave(pp_Var22);
            pCVar14 = (LPCSTR)GRemrbkp();
            DeleteFileA(pCVar14);
            DeleteFileA("$backup.bkp");
            pp_Var22 = pp_Var24;
            if ((_func_5409 *)0xf < param_1->SetClass) {
              pp_Var22 = (_func_5406 **)*pp_Var24;
            }
            uVar13 = GRemrbkpfull();
            GRDeleteEmergencyFiles(pp_Var22,uVar13);
            if ((_func_5409 *)0xf < param_1->SetClass) {
              pp_Var24 = (_func_5406 **)*pp_Var24;
            }
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6f0,
                       (char *)pp_Var24);
            iVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &local_6f0,'.');
            if ((iVar5 != -1) &&
               (iVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                        ReverseFind((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
                                    )&local_6f0,'\\'), iVar7 < iVar5)) {
              pCVar16 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *
                        )ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                                   ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
                                    )&local_6f0,(int)&local_6e8);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6f0
                         ,pCVar16);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e8
                        );
            }
            iVar5 = FUN_180033bd0();
            pcVar10 = ".aprpdf";
            if (iVar5 == 1) {
              pcVar10 = ".appdf";
            }
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6f0,
                       pcVar10);
            FUN_180008430((basic_istream<char,std::char_traits<char>_> *)local_658,
                          (char *)local_6f0.lpVtbl,1,0x40,1);
            bVar4 = std::ios_base::operator!
                              ((ios_base *)
                               ((longlong)local_658 + (longlong)*(int *)(local_658[0] + 4)));
            if (bVar4) {
              SimUpdateMessageView(0,"\n<< Run Saved >>\n");
            }
            else {
              pbVar17 = FUN_18001d4c0(local_648);
              if (pbVar17 == (basic_streambuf<char,std::char_traits<char>_> *)0x0) {
                std::basic_ios<char,std::char_traits<char>_>::setstate
                          ((basic_ios<char,std::char_traits<char>_> *)
                           ((longlong)local_658 + (longlong)*(int *)(local_658[0] + 4)),2,false);
              }
            }
            *(undefined ***)((longlong)local_658 + (longlong)*(int *)(local_658[0] + 4)) =
                 std::basic_ifstream<char,std::char_traits<char>_>::vftable;
            *(int *)((longlong)local_658 + (longlong)*(int *)(local_658[0] + 4) + -4) =
                 *(int *)(local_658[0] + 4) + -0xb0;
            FUN_180008a20(local_648);
            std::basic_istream<char,std::char_traits<char>_>::
            ~basic_istream<char,std::char_traits<char>_>(local_640);
            std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>
                      (local_5a8);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6f0);
          }
          uVar31 = 1;
          *(undefined1 *)((longlong)&param_1[1].CreateStream + 1) = 0;
          *(undefined1 *)((longlong)&param_1[1].CreateStream + 4) = 0;
          HappSetDirty(0);
          GRsetmod(0);
          goto LAB_180018fbe;
        }
        iVar5 = FUN_180033bd0();
        pcVar10 = ".aprt";
        if (iVar5 == 1) {
          pcVar10 = ".apt";
        }
        iVar5 = _stricmp(pcVar10,local_438);
        if (iVar5 == 0) {
          pp_Var22 = pp_Var24;
          if ((_func_5409 *)0xf < param_1->SetClass) {
            pp_Var22 = (_func_5406 **)*pp_Var24;
          }
          uVar9 = WriteHappArchive(pp_Var22,0);
          uVar31 = (ulonglong)((int)uVar9 != 0);
          if ((int)uVar9 == 0) goto LAB_180019d66;
          uVar13 = GetSorResStringEx(0x57e);
          SimUpdateMessageView(0,uVar13);
          if ((_func_5409 *)0xf < param_1->SetClass) {
            pp_Var24 = (_func_5406 **)*pp_Var24;
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6d8,
                     (char *)pp_Var24);
          pwVar28 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                    AllocSysString((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                   &local_6d8);
          FUN_18001ac00(param_1,'\x01',pwVar28);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6d8);
          HappSetDirty(0);
          GRsetmod(0);
          goto LAB_180018fbe;
        }
      }
      else {
        uVar9 = GRchkmmdir(pcVar10,2);
        if ((int)uVar9 != 0) goto LAB_180019d66;
        if ((_func_5409 *)0xf < param_1->SetClass) {
          pp_Var24 = (_func_5406 **)*pp_Var24;
        }
        plVar11 = FUN_1800087d0(&local_6d8,(LPCSTR)pp_Var24);
        if ((undefined8 *)*plVar11 == (undefined8 *)0x0) {
          pwVar28 = (wchar_t *)0x0;
        }
        else {
          pwVar28 = *(wchar_t **)*plVar11;
        }
        FUN_18001ac00(param_1,'\x01',pwVar28);
        pIVar19 = local_6d8;
        if (local_6d8 != (IStorageVtbl *)0x0) {
          LOCK();
          pp_Var1 = &local_6d8->Release;
          iVar5 = *(int *)pp_Var1;
          *(int *)pp_Var1 = *(int *)pp_Var1 + -1;
          UNLOCK();
          if ((iVar5 == 1) && (local_6d8 != (IStorageVtbl *)0x0)) {
            if (local_6d8->QueryInterface != (_func_5394 *)0x0) {
              SysFreeString((BSTR)local_6d8->QueryInterface);
              pIVar19->QueryInterface = (_func_5394 *)0x0;
            }
            if (pIVar19->AddRef != (_func_5395 *)0x0) {
              operator_delete__(pIVar19->AddRef);
              pIVar19->AddRef = (_func_5395 *)0x0;
            }
            FUN_180035134(pIVar19);
          }
        }
        _splitpath(pcVar10,(char *)local_6d0,(char *)local_658,local_238,local_338);
        iVar5 = FUN_180033bd0();
        pcVar21 = ".apropz";
        if (iVar5 == 1) {
          pcVar21 = ".apwz";
        }
        iVar5 = _stricmp(pcVar21,local_338);
        if (iVar5 == 0) {
          piVar12 = (int *)SEGetSettingValue("saveasapw",0);
          iVar5 = *piVar12;
          uVar13 = FUN_18000ab50();
          if ((((int)uVar13 != 0) && (iVar5 == 0)) && (iVar5 = MMGetSuppress(), iVar5 == 0)) {
            local_6f8[0] = 0;
            uVar6 = FUN_1800109e0(local_6f8);
            local_6e0 = ((short)uVar6 != -1) + 6;
            if (local_6f8[0] == -1) {
              SESetSettingValue("saveasapw",&local_6e0,1,0);
            }
            if (local_6e0 == 6) {
              local_6f0.lpVtbl._0_4_ = 1;
              SESetSettingValue("roottype",&local_6f0,1,0);
            }
          }
        }
        FUN_18000b2c0(&param_1->QueryInterface,pcVar10);
LAB_180018fad:
        HappSetDirty(0);
        GRsetmod(0);
      }
    }
LAB_180018fbb:
    uVar31 = 1;
    goto LAB_180018fbe;
  }
  _splitpath((char *)param_2.lpVtbl,(char *)local_6d0,local_238,(char *)local_658,local_438);
  iVar5 = FUN_180033bd0();
  pcVar21 = ".apropz";
  pcVar10 = ".apropz";
  if (iVar5 == 1) {
    pcVar10 = ".apwz";
  }
  iVar5 = _stricmp(local_438,pcVar10);
  IVar25.lpVtbl = param_2.lpVtbl;
  if (iVar5 != 0) {
    IVar25.lpVtbl = (IStorageVtbl *)0x0;
  }
  SetGlobalCharPointer("CompoundFileName",IVar25.lpVtbl);
  iVar5 = FUN_180033bd0();
  pcVar30 = ".aprop";
  pcVar10 = ".aprop";
  if (iVar5 == 1) {
    pcVar10 = ".apw";
  }
  iVar5 = _stricmp(local_438,pcVar10);
  if (iVar5 == 0) {
    iVar5 = MMGetProfileInt("mmgini","alwayssavebkp",0);
    sVar27 = 0xffffffffffffffff;
    if (iVar5 != 0) {
      local_6b8.lpVtbl = (IStorageVtbl *)0x0;
      uStack_6b0 = 0;
      local_6a8 = 0;
      uStack_6a0 = 0;
      sVar29 = 0xffffffffffffffff;
      do {
        sVar29 = sVar29 + 1;
      } while (*(char *)((longlong)&(param_2.lpVtbl)->QueryInterface + sVar29) != '\0');
      FUN_180006e90(&local_6b8,param_2.lpVtbl,sVar29);
      iVar5 = FUN_180033bd0();
      uVar31 = uStack_6a0;
      IVar25.lpVtbl = local_6b8.lpVtbl;
      if (iVar5 == 1) {
        pcVar30 = ".apw";
      }
      lVar23 = -1;
      do {
        lVar23 = lVar23 + 1;
      } while (pcVar30[lVar23] != '\0');
      local_698 = (IStorageVtbl *)0x0;
      uStack_690 = 0;
      uVar9 = local_6a8 - lVar23;
      if (local_6a8 < local_6a8 - lVar23) {
        uVar9 = local_6a8;
      }
      local_6f0.lpVtbl = (IStorageVtbl *)&local_6b8;
      if (0xf < uStack_6a0) {
        local_6f0.lpVtbl = local_6b8.lpVtbl;
      }
      if (0x7fffffffffffffff < uVar9) {
                    /* WARNING: Subroutine does not return */
        FUN_18001d1b0();
      }
      local_688 = uVar9;
      if (uVar9 < 0x10) {
        uStack_680 = 0xf;
        memcpy(&local_698,local_6f0.lpVtbl,uVar9);
        *(undefined1 *)((longlong)&local_678[-4].lpVtbl + uVar9) = 0;
      }
      else {
        uVar18 = uVar9 | 0xf;
        uVar31 = 0x7fffffffffffffff;
        if ((uVar18 < 0x8000000000000000) && (uVar31 = uVar18, uVar18 < 0x16)) {
          uVar31 = 0x16;
        }
        pIVar19 = FUN_18001d210(&local_698,uVar31 + 1);
        local_698 = pIVar19;
        uStack_680 = uVar31;
        memcpy(pIVar19,local_6f0.lpVtbl,uVar9);
        *(undefined1 *)((longlong)&pIVar19->QueryInterface + uVar9) = 0;
        IVar25.lpVtbl = local_6b8.lpVtbl;
        uVar31 = uStack_6a0;
      }
      if (0xf < uVar31) {
        IVar26.lpVtbl = IVar25.lpVtbl;
        if ((0xfff < uVar31 + 1) &&
           (IVar26.lpVtbl = (IStorageVtbl *)IVar25.lpVtbl[-1].Stat,
           0x1f < (ulonglong)((longlong)IVar25.lpVtbl + (-8 - (longlong)IVar26.lpVtbl)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        FUN_180035134(IVar26.lpVtbl);
      }
      local_6b8.lpVtbl = local_698;
      uStack_6b0 = uStack_690;
      local_6a8 = local_688;
      uStack_6a0 = uStack_680;
      iVar5 = FUN_180033bd0();
      pcVar10 = ".aprbkp";
      if (iVar5 == 1) {
        pcVar10 = ".bkp";
      }
      uVar31 = 0xffffffffffffffff;
      do {
        uVar31 = uVar31 + 1;
      } while (pcVar10[uVar31] != '\0');
      if (uStack_6a0 - local_6a8 < uVar31) {
        FUN_180007e40(&local_6b8,uVar31,0,pcVar10,uVar31);
      }
      else {
        IVar25.lpVtbl = (IStorageVtbl *)&local_6b8;
        if (0xf < uStack_6a0) {
          IVar25.lpVtbl = local_6b8.lpVtbl;
        }
        _Dst = (void *)((longlong)&(IVar25.lpVtbl)->QueryInterface + local_6a8);
        local_6a8 = local_6a8 + uVar31;
        memmove(_Dst,pcVar10,uVar31);
        *(undefined1 *)((longlong)_Dst + uVar31) = 0;
      }
      IVar25.lpVtbl = (IStorageVtbl *)&local_6b8;
      if (0xf < uStack_6a0) {
        IVar25.lpVtbl = local_6b8.lpVtbl;
      }
      WriteHappArchive(IVar25.lpVtbl,0);
      if (0xf < uStack_6a0) {
        IVar25.lpVtbl = local_6b8.lpVtbl;
        if ((0xfff < uStack_6a0 + 1) &&
           (IVar25.lpVtbl = (IStorageVtbl *)local_6b8.lpVtbl[-1].Stat,
           0x1f < (ulonglong)((longlong)local_6b8.lpVtbl + (-8 - (longlong)IVar25.lpVtbl)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        FUN_180035134(IVar25.lpVtbl);
      }
    }
    pcVar10 = (char *)GRemrbkpfull();
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e8,pcVar10);
    pp_Var24 = &param_1->DestroyElement;
    local_6c8 = pp_Var24;
    iVar5 = (**(code **)param_1->QueryInterface)(param_1,param_2.lpVtbl,1);
    if (iVar5 != 0) {
      pp_Var22 = pp_Var24;
      if ((_func_5409 *)0xf < param_1->SetClass) {
        pp_Var22 = (_func_5406 **)*pp_Var24;
      }
      GRAuxFileOnSaveAs(pp_Var22,param_2.lpVtbl);
      DeleteFileA(local_6e8);
      DeleteFileA("$backup.bkp");
      pp_Var22 = pp_Var24;
      if ((_func_5409 *)0xf < param_1->SetClass) {
        pp_Var22 = (_func_5406 **)*pp_Var24;
      }
      GRDeleteEmergencyFiles(pp_Var22,local_6e8);
      pp_Var22 = pp_Var24;
      if ((_func_5409 *)0xf < param_1->SetClass) {
        pp_Var22 = (_func_5406 **)*pp_Var24;
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6f0,
                 (char *)pp_Var22);
      iVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6f0
                         ,'.');
      if ((iVar5 != -1) &&
         (iVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_6f0,'\\'), iVar7 < iVar5)) {
        pCVar16 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_6f0,(int)&local_6e0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6f0,
                   pCVar16);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e0);
      }
      iVar5 = FUN_180033bd0();
      pcVar10 = ".aprpdf";
      if (iVar5 == 1) {
        pcVar10 = ".appdf";
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6f0,pcVar10
                );
      FUN_180008430((basic_istream<char,std::char_traits<char>_> *)local_548,
                    (char *)local_6f0.lpVtbl,1,0x40,1);
      bVar4 = std::ios_base::operator!
                        ((ios_base *)((longlong)local_548 + (longlong)*(int *)(local_548[0] + 4)));
      if (bVar4) {
        SimUpdateMessageView(0,"\n<< Run Saved >>\n");
      }
      else {
        pbVar17 = FUN_18001d4c0(local_538);
        if (pbVar17 == (basic_streambuf<char,std::char_traits<char>_> *)0x0) {
          std::basic_ios<char,std::char_traits<char>_>::setstate
                    ((basic_ios<char,std::char_traits<char>_> *)
                     ((longlong)local_548 + (longlong)*(int *)(local_548[0] + 4)),2,false);
        }
      }
      *(undefined ***)((longlong)local_548 + (longlong)*(int *)(local_548[0] + 4)) =
           std::basic_ifstream<char,std::char_traits<char>_>::vftable;
      *(int *)(local_5a8 + (longlong)*(int *)(local_548[0] + 4) + 0x5c) =
           *(int *)(local_548[0] + 4) + -0xb0;
      FUN_180008a20(local_538);
      std::basic_istream<char,std::char_traits<char>_>::~basic_istream<char,std::char_traits<char>_>
                (local_530);
      std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>
                (local_498);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6f0);
    }
    do {
      uVar31 = 1;
      sVar27 = sVar27 + 1;
    } while (*(char *)((longlong)&(param_2.lpVtbl)->QueryInterface + sVar27) != '\0');
    FUN_18001d350((longlong *)pp_Var24,param_2.lpVtbl,sVar27);
    HappSetDirty(0);
    GRsetmod(0);
    *(undefined1 *)((longlong)&param_1[1].CreateStream + 4) = 0;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e8);
    goto LAB_180018fbe;
  }
  iVar5 = FUN_180033bd0();
  pcVar10 = ".aprbkp";
  if (iVar5 == 1) {
    pcVar10 = ".bkp";
  }
  iVar5 = _stricmp(local_438,pcVar10);
  if (iVar5 != 0) {
    iVar5 = FUN_180033bd0();
    pcVar10 = ".aprt";
    if (iVar5 == 1) {
      pcVar10 = ".apt";
    }
    iVar5 = _stricmp(local_438,pcVar10);
    if (iVar5 == 0) {
      WriteHappArchive(param_2.lpVtbl,0);
      HVar8 = StgCreateDocfile((WCHAR *)0x0,0x4011012,0,(IStorage **)&local_6f0);
      if (-1 < HVar8) {
        (**(code **)(*(longlong *)param_1->AddRef + 0x38))(param_1->AddRef,0,0,0);
        SetGlobalPointer("ApwnDocStorage",local_6f0.lpVtbl,0);
        ApwnContextDocumentSetRootStorage(param_1[1].OpenStream,(IStorage *)local_6f0.lpVtbl);
        STclsstg(param_1->AddRef);
        p_Var2 = param_1->AddRef;
        if (p_Var2 != (_func_5395 *)0x0) {
          param_1->AddRef = (_func_5395 *)0x0;
          (**(code **)(*(longlong *)p_Var2 + 0x10))();
        }
        IVar25.lpVtbl = local_6f0.lpVtbl;
        if ((IStorageVtbl *)param_1->AddRef != local_6f0.lpVtbl) {
          if (local_6f0.lpVtbl != (IStorageVtbl *)0x0) {
            (*((IStorageVtbl *)(local_6f0.lpVtbl)->QueryInterface)->AddRef)
                      ((IStorage *)local_6f0.lpVtbl);
          }
          p_Var2 = param_1->AddRef;
          param_1->AddRef = (_func_5395 *)IVar25.lpVtbl;
          if (p_Var2 != (_func_5395 *)0x0) {
            (**(code **)(*(longlong *)p_Var2 + 0x10))();
          }
        }
        sVar27 = 0xffffffffffffffff;
        do {
          sVar27 = sVar27 + 1;
        } while (*(char *)((longlong)&(param_2.lpVtbl)->QueryInterface + sVar27) != '\0');
        FUN_18001d350((longlong *)&param_1->DestroyElement,param_2.lpVtbl,sVar27);
        goto LAB_180018fad;
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e8);
      iVar5 = FUN_180033bd0();
      uVar13 = 0x57f;
      if (iVar5 != 1) {
        uVar13 = 0x580;
      }
      pcVar10 = (char *)GetSorResStringEx(uVar13);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e8,pcVar10
                );
      MMAfxMessageBox(local_6e8,0x30,-1,0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e8);
      goto LAB_180018fbb;
    }
    iVar5 = FUN_180033bd0();
    if (iVar5 == 1) {
      pcVar21 = ".apwz";
    }
    iVar5 = _stricmp(local_438,pcVar21);
    uVar9 = CONCAT44(extraout_var,iVar5);
    if (iVar5 != 0) goto LAB_180019d66;
    piVar12 = (int *)SEGetSettingValue("saveasapw",0);
    iVar5 = *piVar12;
    uVar13 = FUN_18000ab50();
    if ((((int)uVar13 != 0) && (iVar5 == 0)) && (iVar5 = MMGetSuppress(), iVar5 == 0)) {
      local_6f8[0] = 0;
      uVar6 = FUN_1800109e0(local_6f8);
      local_6e0 = ((short)uVar6 != -1) + 6;
      if (local_6f8[0] == -1) {
        SESetSettingValue("saveasapw",&local_6e0,1,0);
      }
      if (local_6e0 == 6) {
        local_6f0.lpVtbl._0_4_ = 1;
        SESetSettingValue("roottype",&local_6f0,1,0);
      }
    }
    pp_Var24 = &param_1->DestroyElement;
    FUN_180008630(local_678,pp_Var24);
    uVar9 = FUN_18000b2c0(&param_1->QueryInterface,(char *)param_2.lpVtbl);
    uVar31 = (ulonglong)((int)uVar9 != 0);
    if ((int)uVar9 == 0) {
      if ((IStorage *)pp_Var24 != local_678) {
        param_2.lpVtbl = (IStorageVtbl *)local_678;
        if (0xf < local_660) {
          param_2.lpVtbl = local_678[0].lpVtbl;
        }
        goto LAB_18001a391;
      }
    }
    else {
      local_668 = 0xffffffffffffffff;
      do {
        local_668 = local_668 + 1;
      } while (*(char *)((longlong)&(param_2.lpVtbl)->QueryInterface + local_668) != '\0');
LAB_18001a391:
      FUN_18001d350((longlong *)pp_Var24,param_2.lpVtbl,local_668);
    }
    HappSetDirty(0);
    GRsetmod(0);
    if (0xf < local_660) {
      IVar25.lpVtbl = local_678[0].lpVtbl;
      if ((0xfff < local_660 + 1) &&
         (IVar25.lpVtbl = (IStorageVtbl *)local_678[0].lpVtbl[-1].Stat,
         0x1f < (ulonglong)((longlong)local_678[0].lpVtbl + (-8 - (longlong)IVar25.lpVtbl)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      FUN_180035134(IVar25.lpVtbl);
    }
    goto LAB_180018fbe;
  }
  piVar12 = (int *)SEGetSettingValue("saveasapw",0);
  iVar5 = *piVar12;
  local_6c8 = (_func_5406 **)CONCAT44(local_6c8._4_4_,iVar5);
  local_6f8[0] = 0;
  if (iVar5 == 0) {
    iVar5 = MMGetSuppress();
    if (iVar5 == 0) {
      uVar6 = FUN_180010b50(local_6f8);
      iVar5 = ((short)uVar6 != -1) + 6;
      local_6c8 = (_func_5406 **)CONCAT44(local_6c8._4_4_,iVar5);
      if (local_6f8[0] == -1) {
        SESetSettingValue("saveasapw",&local_6c8);
        iVar5 = (int)local_6c8;
      }
      goto LAB_180019c75;
    }
    local_6c8 = (_func_5406 **)CONCAT44(local_6c8._4_4_,7);
  }
  else {
LAB_180019c75:
    if (iVar5 == 6) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6d8,
                 (char *)param_2.lpVtbl);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e8,
                 "{ } [ ] , . / * : ; \" , ?");
      iVar5 = SBDOShost();
      if ((iVar5 == 0) &&
         (iVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::FindOneOf
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_6d8,local_6e8), iVar5 != -1)) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e0);
        pcVar10 = (char *)GetSorResStringEx(0x57b);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e0,
                   pcVar10);
        pcVar10 = (char *)GetSorResStringEx(0x57c);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e0,
                   pcVar10);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e0,
                   (CSimpleStringT<char,1> *)&local_6e8);
        pcVar10 = (char *)GetSorResStringEx(0x57d);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e0,
                   pcVar10);
        MMAfxMessageBox((char *)CONCAT44(uStack_6dc,local_6e0),0x40,-1,0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6d8);
        uVar9 = extraout_RAX;
LAB_180019d66:
        return uVar9 & 0xffffffffffffff00;
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e8);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6d8);
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6f0,
             (char *)param_2.lpVtbl);
  if (*(char *)((longlong)&param_1[1].CreateStream + 1) == '\0') {
    pp_Var24 = &param_1->DestroyElement;
    if ((_func_5409 *)0xf < param_1->SetClass) {
      pp_Var24 = (_func_5406 **)*pp_Var24;
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e8,
               (char *)pp_Var24);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6f0,'.');
    puVar20 = (undefined8 *)
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6f0
                         ,(int)&local_6d8);
    local_6e0 = 1;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e8,'.');
    pCVar15 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e8
                         ,(int)&local_6c0);
    local_6e0 = 3;
    iVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                      (pCVar15,(char *)*puVar20);
    if ((iVar5 == 0) && ((int)local_6c8 == 6)) {
      bVar4 = true;
    }
    else {
      bVar4 = false;
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6c0);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6d8);
    if (bVar4) {
      (**(code **)param_1->QueryInterface)(param_1,local_6e8);
      local_6c8 = (_func_5406 **)CONCAT44(local_6c8._4_4_,7);
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e8);
    ApwnContextDocumentSetFilename(param_1[1].OpenStream,(char *)local_6f0.lpVtbl);
    HVar8 = StgCreateDocfile((WCHAR *)0x0,0x4011012,0,(IStorage **)&local_6d8);
    if (HVar8 < 0) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e8);
      iVar5 = FUN_180033bd0();
      uVar13 = 0x57f;
      if (iVar5 != 1) {
        uVar13 = 0x580;
      }
      pcVar10 = (char *)GetSorResStringEx(uVar13);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e8,pcVar10
                );
      MMAfxMessageBox(local_6e8,0x30,-1,0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6e8);
    }
    else {
      p_Var2 = param_1->AddRef;
      ApwnContextDocumentSetRootStorage(param_1[1].OpenStream,(IStorage *)local_6d8);
      ApwnContextDocumentSaveContents(param_1[1].OpenStream);
      SaveHapp(local_6d8,0,local_6f0.lpVtbl,0);
      pIVar19 = local_6d8;
      if ((IStorageVtbl *)param_1->AddRef != local_6d8) {
        if (local_6d8 != (IStorageVtbl *)0x0) {
          (**(code **)(local_6d8->QueryInterface + 8))(local_6d8);
        }
        p_Var3 = param_1->AddRef;
        param_1->AddRef = (_func_5395 *)pIVar19;
        if (p_Var3 != (_func_5395 *)0x0) {
          (**(code **)(*(longlong *)p_Var3 + 0x10))();
        }
      }
      iVar5 = FUN_180033bd0();
      if (iVar5 == 1) {
        FUN_18001bf90((longlong)param_1,(longlong *)param_1->AddRef);
      }
      iVar5 = FUN_180033bd0();
      if (iVar5 == 1) {
        FUN_18001a7a0(param_1,(longlong *)param_1->AddRef);
        pp_Var24 = &param_1->DestroyElement;
        if ((_func_5409 *)0xf < param_1->SetClass) {
          pp_Var24 = (_func_5406 **)*pp_Var24;
        }
        FUN_18001a540(param_1,(longlong *)param_1->AddRef,(char *)pp_Var24);
        FUN_18001ad40(param_1,(longlong *)param_1->AddRef);
      }
      ApwnContextDocumentCommitItems(param_1[1].OpenStream,1);
      (**(code **)(*(longlong *)param_1->AddRef + 0x48))(param_1->AddRef,0);
      SetGlobalPointer("ApwnDocStorage",param_1->AddRef);
      STclsstg(p_Var2);
    }
  }
  else {
    ApwnContextDocumentSetFilename(param_1[1].OpenStream,(char *)local_6f0.lpVtbl);
    HappUpdateMoniker(local_6f0.lpVtbl);
  }
  sVar27 = 0xffffffffffffffff;
  HappUpdateMoniker(param_2.lpVtbl);
  iVar5 = WriteHappArchive(param_2.lpVtbl,0);
  uVar31 = (ulonglong)(iVar5 != 0);
  if (iVar5 != 0) {
    pp_Var24 = &param_1->DestroyElement;
    if ((_func_5409 *)0xf < param_1->SetClass) {
      pp_Var24 = (_func_5406 **)param_1->DestroyElement;
    }
    GRAuxFileOnSaveAs(pp_Var24,param_2.lpVtbl);
    do {
      sVar27 = sVar27 + 1;
    } while (*(char *)((longlong)&(param_2.lpVtbl)->QueryInterface + sVar27) != '\0');
    FUN_18001d350((longlong *)&param_1->DestroyElement,param_2.lpVtbl,sVar27);
    uVar13 = GetSorResStringEx(0x57e);
    SimUpdateMessageView(0,uVar13);
  }
  *(undefined1 *)((longlong)&param_1[1].CreateStream + 1) = 1;
  if ((int)local_6c8 == 6) {
    pCVar15 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6c0
                         ,(char *)param_2.lpVtbl);
    FUN_18000b3f0(&param_1->QueryInterface,pCVar15,0);
  }
  HappSetDirty(0);
  GRsetmod(0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_6f0);
LAB_180018fbe:
  pcVar10 = _strdup("Refresh");
  SimSendMainWndMessage(0x536,0,pcVar10);
  return uVar31;
}

